#ifndef UTILS_H
#define UTILS_H

#include "../header.h"
#include <arpa/inet.h>
#include <cstdio>
#include <ctype.h>
#include <errno.h>
#include <iostream>
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
#define ERROR_INFO(msg)                                                        \
  std::cout << "(" << __FILE__ << ":" << __LINE__ << ") " << __FUNCTION__      \
            << "(): " << msg << std::endl;
#define LOG(msg)                                                               \
  std::cout << "(" << __FILE__ << ":" << __LINE__ << ")" << msg << std::endl;

void print_payload(const u_char *payload, size_t payload_len);

#endif // UTILS_H