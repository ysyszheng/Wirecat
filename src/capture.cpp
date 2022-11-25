#include "capture.h"

void get_packet(u_char *args, const struct pcap_pkthdr *header,
                const u_char *packet) {

  static size_t cnt = 1; /* packet counter */
  printf("\nPacket number %zu:\n", cnt);
  cnt++;

  /* declare pointers to packet headers */
  const ethernet_header *ethernet;
  const ipv4_header *ipv4;
  const tcp_header *tcp;
  const char *payload;

  ethernet = (ethernet_header *)(packet);

  switch (ethernet->ether_type) {
  case ETHER_TYPE_IPV4:
    /***** IPv4 *****/
    ipv4 = (ipv4_header *)(packet + SIZE_ETHERNET);
    break;
  case ETHER_TYPE_ARP:
    /***** ARP *****/
    break;
  case ETHER_TYPE_IPV6:
    /***** IPv6 *****/
    break;
  }

  return;
}
