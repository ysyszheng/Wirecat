#ifndef HEADER_H
#define HEADER_H

#include "utils/utils.h"

/* ethernet headers are always exactly 14 bytes */
#define SIZE_ETHERNET 14

/* Ethernet addresses are 6 bytes */
#define ETHER_ADDR_LEN 6

typedef struct {
  u_char ether_dhost[ETHER_ADDR_LEN]; /* destination host address */
  u_char ether_shost[ETHER_ADDR_LEN]; /* source host address */
  u_short ether_type;                 /* IP? ARP? RARP? etc */
} ethernet_header;

#endif // HEADER_H