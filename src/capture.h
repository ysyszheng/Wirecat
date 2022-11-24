#ifndef CAPTURE_H
#define CAPTURE_H

#include "utils/utils.h"

void get_packet(u_char *args, const struct pcap_pkthdr *header,
                const u_char *packet);

#endif // CAPTURE_H