#include "sniffer.h"
#include "utils/hdr.h"
#include "utils/utils.h"
#include <sys/types.h>

std::vector<packet_struct *> Sniffer::pkt; // packet
View *Sniffer::view;                       // view

Sniffer::Sniffer() {
  dev = NULL;
  allDev_ptr = NULL;
  dumper = NULL;
  status = Init;
  findAllDevs();
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
  // status = Start;
  while (TRUE) {
    if (status == Start) {
      // LOG("Start");
      // dumper = pcap_dump_open(handle, "./packet.pcap");
      // pcap_dispatch(handle, -1, get_packet, (u_char *)dumper);
      pcap_dispatch(handle, -1, get_packet, NULL);
      // pcap_dump_flush(dumper);
      // pcap_dump_close(dumper);
      // get_packet();
    } else if (status == Stop) {
      LOG("Stop");
    } else {
      LOG("Initiating...");
    }
  }
}

void Sniffer::get_packet(u_char *args, const struct pcap_pkthdr *header,
                         const u_char *packet) {

  static size_t cnt = 0;
  // pcap_dumper_t *dumper = (pcap_dumper_t *)args;
  // pcap_dump(args, header, packet);
  // pcap_dump_flush(dumper);

  packet_struct *pkt_p = new packet_struct;
  pkt_p->len = SIZE_ETHERNET;
  pkt_p->time = currentDataTime();
  pkt_p->eth_hdr = (ethernet_header *)(packet);

  switch (ntohs(pkt_p->eth_hdr->ether_type)) {
  case ETHERTYPE_IP: {
    pkt_p->net_type = IPv4;
    handle_ipv4(packet, pkt_p);
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

  void *packet_cpy = malloc(pkt_p->len);
  memcpy(packet_cpy, packet, pkt_p->len);

  pkt_p->len = SIZE_ETHERNET;
  pkt_p->eth_hdr = (ethernet_header *)(packet_cpy);

  switch (ntohs(pkt_p->eth_hdr->ether_type)) {
  case ETHERTYPE_IP: {
    pkt_p->net_type = IPv4;
    handle_ipv4((const u_char *)packet_cpy, pkt_p);
    break;
  }
  case ETHERTYPE_ARP:
    pkt_p->net_type = ARP;
    handle_arp((const u_char *)packet_cpy, pkt_p);
    break;
  case ETHERTYPE_IPV6:
    pkt_p->net_type = IPv6;
    handle_ipv6((const u_char *)packet_cpy, pkt_p);
    break;
  default:
    pkt_p->net_type = Unet;
    break;
  }

  if (pkt_p->net_type != Unet) { // Known types
    cnt++;
    pkt_p->no = cnt;

    Sniffer::pkt.push_back(pkt_p);
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

/* IP reassmble function */
packet_struct *Sniffer::ipv4Reassmble(const packet_struct *packet) {
  uint16_t identification = ntohs(packet->net_hdr.ipv4_hdr->ip_id);
  int size = pkt.size();
  u_char *datagram = new u_char[8000]; // space to store payload

  packet_struct *newpacket = new packet_struct;
  newpacket->time = currentDataTime();
  newpacket->net_type = IPv4;

  uint32_t final_hdr_length = 0; // header length of reassmbled data
  uint32_t total_data_len = 0;   // length of payload

  bool oversize_flag = false;

  for (int i = 0; i < size; i++) {
    if (ntohs(pkt[i]->net_hdr.ipv4_hdr->ip_id) ==
        identification) { // is a fragment of a same packet
      ushort tmpOffset = ntohs(pkt[i]->net_hdr.ipv4_hdr->ip_off) & 0x1fff;
      uint32_t hdr_length = 0;

      hdr_length += SIZE_ETHERNET + 20; // 20-length of ipv4_header
      switch (pkt[i]->trs_type) {
      case UDP:
        hdr_length += 8;
        break; // 8-length of UDP header
      case TCP:
        hdr_length += 20;
        break; // 20-length of TCP header
      case ICMP:
        hdr_length += 8;
        break; // 8-length of ICMP header
      case IGMP:
        hdr_length += 8;
        break; // 8-length of IGMP header
      case Utrs:
        break;
      }

      total_data_len += pkt[i]->len - hdr_length;
      if (total_data_len > 8000) { // too big, discard
        oversize_flag = true;
        break;
      }

      if (tmpOffset == 0) { // the first fragment
        final_hdr_length = hdr_length;
        memcpy(newpacket->eth_hdr, pkt[i]->eth_hdr,
               final_hdr_length); // copy header of the first fragment
        memcpy(datagram, pkt[i]->eth_hdr + hdr_length,
               pkt[i]->len - hdr_length); // copy data of the first fragment
      } else {
        memcpy(datagram + tmpOffset * 8, pkt[i]->eth_hdr + hdr_length,
               pkt[i]->len - hdr_length); // copy data of this fragment
      }
    }
  }

  if (oversize_flag) { // oversize, reassmble failed
    return NULL;
  }

  memcpy(newpacket->eth_hdr + final_hdr_length, datagram,
         total_data_len); // newpacket is the packet after reassmbled
  newpacket->len = final_hdr_length + total_data_len;

  delete[] datagram;

  return newpacket;
}