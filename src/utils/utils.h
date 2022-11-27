#ifndef UTILS_H
#define UTILS_H

#include "hdr.h"
#include <arpa/inet.h>
#include <cstdio>
#include <ctype.h>
#include <errno.h>
#include <iostream>
#include <net/ethernet.h>
#include <netinet/ether.h>
#include <netinet/if_ether.h>
#include <netinet/in.h>
#include <pcap.h>
#include <pcap/pcap.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <vector>

#define FALSE 0
#define TRUE 1

#define PRINT_DEV_NAME TRUE
#define PRINT_DEV_INFO TRUE
#define PRINT_PACKAGE_NUM TRUE
#define PRINT_ETHER_ADDR TRUE
#define PRINT_UNKNOW_ETHER_TYPE TRUE
#define PRINT_UNKNOW_IP_PROTO TRUE
#define PRINT_UNKNOW_ARP_PROTO TRUE

#define ERROR_INFO(msg)                                                        \
  std::cout << "(" << __FILE__ << ":" << __LINE__ << ") " << __FUNCTION__      \
            << "(): " << msg << std::endl;
#define LOG(msg)                                                               \
  std::cout << "(" << __FILE__ << ":" << __LINE__ << ")" << msg << std::endl;

void print_payload(const u_char *payload, size_t payload_len);

#endif // UTILS_H