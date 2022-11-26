#ifndef CAPTURE_H
#define CAPTURE_H

#include "utils/utils.h"

void get_packet(u_char *args, const struct pcap_pkthdr *header,
                const u_char *packet);

void handle_ipv4(const u_char *packet);
void handle_arp(const u_char *packet);
void handle_ipv6(const u_char *packet);

// hdr_len is len of ipv4_header/arp_header/ipv6_header
void handle_tcp(const u_char *packet, size_t hdr_len, size_t total_len);
void handle_udp(const u_char *packet, size_t hdr_len, size_t total_len);
void handle_icmp(const u_char *packet, size_t hdr_len, size_t total_len);
void handle_igmp(const u_char *packet, size_t hdr_len, size_t total_len);

#endif // CAPTURE_H