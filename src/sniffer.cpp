#include "sniffer.h"
#include "utils/hdr.h"
#include "utils/utils.h"
#include <sys/types.h>

std::vector<packet_struct *> Sniffer::pkt; // packet
View *Sniffer::view;                       // view

Sniffer::Sniffer() {
  dev = NULL;
  allDev_ptr = NULL;
  status = Init;
  findAllDevs();
  is_IPreassmble_ticked = false;
}

Sniffer::~Sniffer() {
  if (allDev_ptr)
    pcap_freealldevs(allDev_ptr);
  if (handle)
    pcap_close(handle);
}

bool Sniffer::findAllDevs() {
  char errbuf[PCAP_ERRBUF_SIZE];
  pcap_findalldevs(&allDev_ptr, errbuf);

  if (allDev_ptr == NULL) {
    ERROR_INFO(errbuf);
    exit(1);
  }

  if (PRINT_DEV_NAME) {
    printf("Available devices: \n");
  }

  for (pcap_if_t *pdev = allDev_ptr; pdev; pdev = pdev->next) {
    if (PRINT_DEV_NAME) {
      std::cout << "  @: " << pdev->name << std::endl;
    }
    allDev_vec.push_back(pdev);
  }
  return TRUE;
}

void Sniffer::getDevName(const char *devName) { dev = devName; }

bool Sniffer::getDevInfo() {
  char errbuf[PCAP_ERRBUF_SIZE];

  if (pcap_lookupnet(dev, &net, &mask, errbuf) == -1) {
    ERROR_INFO(errbuf);
    net = 0;
    mask = 0;
    return FALSE;
  }

  if (PRINT_DEV_INFO) {
    printf("Device Info:\n");
    printf("NET: %d.%d.%d.%d\tmask: %d.%d.%d.%d\n", (net >> 24) & 0xff,
           (net >> 16) & 0xff, (net >> 8) & 0xff, (net)&0xff,
           (mask >> 24) & 0xff, (mask >> 16) & 0xff, (mask >> 8) & 0xff,
           mask & 0xff);
  }
  return TRUE;
}

void Sniffer::getView(View *viewObj) { view = viewObj; }

void Sniffer::sniff() {
  LOG("Start Sniffing...")
  // status = Start;

  while (TRUE) {
    if (status == Start) {
      LOG("Start");
      pcap_dispatch(handle, -1, get_packet, NULL);
    } else if (status == Stop) {
      LOG("Stop");
    } else {
      LOG("Initiating...");
    }
  }

  return;
}

bool isSegment(packet_struct* packet){
  if ((((packet->net_hdr.ipv4_hdr->ip_off >> 13) & 0x1) == 0) & ((packet->net_hdr.ipv4_hdr->ip_off & 0x1fff) == 0)) //MF=0,pffset=0
    return false;
  else return true;
}

void Sniffer::get_packet(u_char *args, const struct pcap_pkthdr *header,
                         const u_char *packet) {

  static size_t cnt = 0;

  packet_struct *pkt_p = new packet_struct;
  pkt_p->len = SIZE_ETHERNET;
  pkt_p->time = currentDataTime();
  pkt_p->eth_hdr = (ethernet_header *)(packet);
  cnt++;
  pkt_p->no = cnt;

  switch (ntohs(pkt_p->eth_hdr->ether_type)) {
  case ETHERTYPE_IP:{
    pkt_p->net_type = IPv4;
    handle_ipv4(packet, pkt_p);
    if(is_IPreassmble_ticked) {
      /* IP Fragmentation Reassembly */
      if(isSegment(pkt_p)) {
        ip_regroup(pkt_p);
        if(pkt_p->no == 0) {
          cnt--;
          return;
        }
      }
    }
    break;
  }
  case ETHERTYPE_ARP:
    pkt_p->net_type = ARP;
    handle_arp(packet, pkt_p);
    break;
  case ETHERTYPE_IPV6:
    pkt_p->net_type = IPv6;
    handle_ipv6(packet, pkt_p);
    break;
  default:
    pkt_p->net_type = Unet;
    break;
  }

  if(pkt_p->net_type == Unet) {
    cnt--;
  }

  if (pkt_p->net_type != Unet) { // Known types
    Sniffer::pkt.push_back(pkt_p);
    // LOG("\n" << store_payload((u_char *)pkt_p->eth_hdr, pkt_p->len));
    view->add_pkt(pkt_p);
  }
  

  return;
}

void Sniffer::handle_ipv4(const u_char *packet, packet_struct *pkt_p) {
  pkt_p->net_hdr.ipv4_hdr = (ipv4_header *)(packet + SIZE_ETHERNET);
  long size_ip = IPv4_HL(pkt_p->net_hdr.ipv4_hdr) * 4;
  pkt_p->len += size_ip;

  switch (pkt_p->net_hdr.ipv4_hdr->ip_p) {
  case IPPROTO_TCP:
    pkt_p->trs_type = TCP;
    pkt_p->trs_hdr.tcp_hdr = (tcp_header *)(packet + pkt_p->len);
    break;
  case IPPROTO_UDP:
    pkt_p->trs_type = UDP;
    pkt_p->trs_hdr.udp_hdr = (udp_header *)(packet + pkt_p->len);
    break;
  case IPPROTO_ICMP:
    pkt_p->trs_type = ICMP;
    pkt_p->trs_hdr.icmp_hdr = (icmp_header *)(packet + pkt_p->len);
    break;
  case IPPROTO_IGMP:
    pkt_p->trs_type = IGMP;
    pkt_p->trs_hdr.igmp_hdr = (igmp_header *)(packet + pkt_p->len);
    break;
  default:
    pkt_p->trs_type = Utrs;
    break;
  }

  pkt_p->len -= size_ip; // sub size_ip, because ip_len include it
  pkt_p->len += ntohs(pkt_p->net_hdr.ipv4_hdr->ip_len); // TODO

  return;
}

void Sniffer::handle_ipv6(const u_char *packet, packet_struct *pkt_p) {
  pkt_p->net_hdr.ipv6_hdr = (ipv6_header *)(packet + SIZE_ETHERNET);
  pkt_p->len += SIZE_IPv6;

  switch (pkt_p->net_hdr.ipv6_hdr->next_header) { // TODO
  case IPPROTO_TCP:
    pkt_p->trs_type = TCP;
    pkt_p->trs_hdr.tcp_hdr = (tcp_header *)(packet + pkt_p->len);
    break;
  case IPPROTO_UDP:
    pkt_p->trs_type = UDP;
    pkt_p->trs_hdr.udp_hdr = (udp_header *)(packet + pkt_p->len);
    break;
  case IPPROTO_ICMP:
    pkt_p->trs_type = ICMP;
    pkt_p->trs_hdr.icmp_hdr = (icmp_header *)(packet + pkt_p->len);
    break;
  case IPPROTO_IGMP:
    pkt_p->trs_type = IGMP;
    pkt_p->trs_hdr.igmp_hdr = (igmp_header *)(packet + pkt_p->len);
    break;
  default:
    pkt_p->trs_type = Utrs;
    break;
  }

  pkt_p->len += ntohs(pkt_p->net_hdr.ipv6_hdr->payload_len); // TODO

  return;
}

void Sniffer::handle_arp(const u_char *packet, packet_struct *pkt_p) {
  pkt_p->net_hdr.arp_hdr = (arp_header *)(packet + SIZE_ETHERNET);
  pkt_p->len += SIZE_ARP;
  return;
}


/* function for ip reassembly */
void bit_set(void* buf, int offset)
{
    (static_cast<char*>(buf))[offset >> 3] |= 1 << (offset & 7);
}

int bit_isset(void* buf, int offset)
{
    if ((static_cast<char*>(buf))[offset >> 3] & 1 << (offset & 7))
        return 1;
    else
        return 0;
}

void Sniffer::ip_regroup(packet_struct* newpacket) {
  size_t i=0;

  ipv4_header* ip = (ipv4_header*)(newpacket->net_hdr.ipv4_hdr);
  ushort identification = ip->ip_id;
  if(idenList.size() != 0) {
    for(i=0;i<idenList.size();++i) {
      if(idenList[i] == identification) break;
    }
  }

  if(i == idenList.size()){
    /* The first fragment received, open new space */
    idenList.push_back(identification);
    buf* buffer = new buf;
    buffer->TDL = 0;
    buffer->data = new unsigned char[8000];
    buffer->seg_PT = new unsigned char[8000];
    *(buffer->seg_PT) = 0;
    segpack.push_back(buffer);
  }

  /* copy data to corresponding data buffer */
  memcpy((segpack[i]->data) + (ip->ip_off & 0x1fff)*8, newpacket->eth_hdr + 14 + (ip->ip_vhl & 0xf)*4, (ip->ip_len-(ip->ip_vhl & 0xf)*4));

  for(int j = (ip->ip_off & 0x1fff); j<((ip->ip_off & 0x1fff) + ((ip->ip_len - (ip->ip_vhl & 0xf) * 4) + 7) / 8); j++){
    bit_set(segpack[i]->seg_PT, j);
  }

  if((((ip->ip_off >> 13) & 0x1) == 0) & ((ip->ip_off & 0x1fff) != 0)) {   
    /* MF=0, offset!=0, the last fragmentation */
    segpack[i]->TDL = ip->ip_len - ((ip->ip_vhl & 0xf) * 4) + (ip->ip_off & 0x1fff) * 8;
  }

  if((((ip->ip_off >> 13) & 0x1) == 1)&& ((ip->ip_off & 0x1fff) == 0)) {       
    /* MF=1, offset=0, the first fragmentation, copy header  */
    ethernet_header* th= (ethernet_header*)newpacket->eth_hdr;
    segpack[i]->ip = ip;
    segpack[i]->th = th;
  }

  if(segpack[i]->TDL != 0)  /* check whether reassmbly is completed */
  {
    int seg_PT_SET = 1;
    for (int j = 0; j <= ((segpack[i]->TDL + 7) / 8); j++)    /* if reassmbly is completed, seg_PT_SET = 1 */
    {
      seg_PT_SET = seg_PT_SET * (bit_isset(segpack[i]->seg_PT, j));
    }
    if (seg_PT_SET)
    {
      segpack[i]->ip->ip_len =(segpack[i]->TDL) + ((segpack[i]->ip->ip_vhl & 0x1f) * 4); 
      segpack[i]->ip->ip_off= segpack[i]->ip->ip_off;
      segpack[i]->ip->ip_off = segpack[i]->ip->ip_off & 0xcfff;
      segpack[i]->ip->ip_off = segpack[i]->ip->ip_off | 0x4000;            /*set DF=1, MF=0*/

      unsigned char* newdata = new unsigned char[14 + segpack[i]->ip->ip_len+1];        /* Splicing IP reassembled data packets */
      memcpy(newdata, segpack[i]->th, 14);                                              /* add ethernet header */
      memcpy(newdata + 14, segpack[i]->ip, (segpack[i]->ip->ip_vhl & 0xf) * 4);        /* add IP header */
      /* add data after reassmbly */
      memcpy(newdata + 14 + (segpack[i]->ip->ip_vhl & 0xf) * 4, segpack[i]->data, segpack[i]->ip->ip_len - (segpack[i]->ip->ip_vhl & 0xf) * 4);

      /* save as a new packet */
      newpacket->eth_hdr = (ethernet_header*)newdata;
      newpacket->len = static_cast<bpf_u_int32>(14 + segpack[i]->ip->ip_len);
      delete segpack[i]->data;
      delete segpack[i]->seg_PT;
      //delete segpack[i];
      segpack.erase(segpack.begin() + i);
      idenList.erase(idenList.begin() + i);
    }
    else
    {
      newpacket->no = 0;        /* the packet is not fully reassembled */
    }
  }
  else
  {
    newpacket->no = 0;          /* the packet is not fully reassembled */
  }
}

