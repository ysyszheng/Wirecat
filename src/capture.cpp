#include "capture.h"

void get_packet(u_char *args, const struct pcap_pkthdr *header,
                const u_char *packet) {

  static size_t cnt = 1; /* packet counter */
  printf("\nPacket number %zu:\n", cnt);
  cnt++;

  /* declare pointers to packet headers */
  const ethernet_header *ethernet;
  const ipv4_header *ipv4;
  const ipv6_header *ipv6;
  const tcp_header *tcp;
  const arp_header *arp;
  const char *payload;

  ethernet = (ethernet_header *)(packet);

  if (PRINT_ETHER_ADDR) {
    printf("  Src Host Ethernet Address: %s\n",
           ether_ntoa((const struct ether_addr *)&ethernet->ether_shost));
    printf("  Dst Host Ethernet Address: %s\n",
           ether_ntoa((const struct ether_addr *)&ethernet->ether_dhost));
  }

  switch (ntohs(ethernet->ether_type)) {
  case ETHERTYPE_IP:
    /***** IPv4 *****/
    ipv4 = (ipv4_header *)(packet + SIZE_ETHERNET);
    printf("  Ethernet Type: IPv4\n");
    break;
  case ETHERTYPE_ARP:
    /***** ARP *****/
    arp = (arp_header *)(packet + SIZE_ETHERNET);
    printf("  Ethernet Type: ARP\n");
    break;
  case ETHERTYPE_IPV6:
    /***** IPv6 *****/
    ipv6 = (ipv6_header *)(packet + SIZE_ETHERNET);
    printf("  Ethernet Type: IPv6\n");
    break;
  default:
    printf("  Unknown Ethernet Type: %x\n", ntohs(ethernet->ether_type));
    break;
  }

  return;
}
