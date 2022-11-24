#include "utils.h"

void get_packet(u_char *args, const struct pcap_pkthdr *header,
                const u_char *packet) {

  static int count = 1; /* packet counter */

  /* declare pointers to packet headers */
  const ethernet_header *ethernet; /* The ethernet header [1] */
  const ipv4_header *ip;           /* The IP header */
  const tcp_header *tcp;           /* The TCP header */
  const char *payload;             /* Packet payload */

  int size_ip;
  int size_tcp;
  int size_payload;

  printf("\nPacket number %d:\n", count);
  count++;

  /* define ethernet header */
  ethernet = (ethernet_header *)(packet);

  /* define/compute ip header offset */
  ip = (ipv4_header *)(packet + SIZE_ETHERNET);
  size_ip = IP_HL(ip) * 4;
  if (size_ip < 20) {
    printf("   * Invalid IP header length: %u bytes\n", size_ip);
    return;
  }

  /* print source and destination IP addresses */
  printf("       From: %s\n", inet_ntoa(ip->ip_src));
  printf("         To: %s\n", inet_ntoa(ip->ip_dst));

  /* determine protocol */
  switch (ip->ip_p) {
  case IPPROTO_TCP:
    printf("   Protocol: TCP\n");
    break;
  case IPPROTO_UDP:
    printf("   Protocol: UDP\n");
    return;
  case IPPROTO_ICMP:
    printf("   Protocol: ICMP\n");
    return;
  case IPPROTO_IP:
    printf("   Protocol: IP\n");
    return;
  default:
    printf("   Protocol: unknown\n");
    return;
  }

  /*
   *  OK, this packet is TCP.
   */

  /* define/compute tcp header offset */
  tcp = (struct sniff_tcp *)(packet + SIZE_ETHERNET + size_ip);
  size_tcp = TH_OFF(tcp) * 4;
  if (size_tcp < 20) {
    printf("   * Invalid TCP header length: %u bytes\n", size_tcp);
    return;
  }

  printf("   Src port: %d\n", ntohs(tcp->th_sport));
  printf("   Dst port: %d\n", ntohs(tcp->th_dport));

  /* define/compute tcp payload (segment) offset */
  payload = (u_char *)(packet + SIZE_ETHERNET + size_ip + size_tcp);

  /* compute tcp payload (segment) size */
  size_payload = ntohs(ip->ip_len) - (size_ip + size_tcp);

  /*
   * Print payload data; it might be binary, so don't just
   * treat it as a string.
   */
  if (size_payload > 0) {
    printf("   Payload (%d bytes):\n", size_payload);
    print_payload(payload, size_payload);
  }

  return;
}
