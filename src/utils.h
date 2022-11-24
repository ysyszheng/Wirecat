#ifndef UTILS_H
#define UTILS_H

#include <iostream>
#include <pcap.h>

#define FALSE 0
#define TRUE 1
#define PRINT_DEV_INFO FALSE
#define LOG(msg)                                                               \
  std::cout << "(" << __FILE__ << ":" << __LINE__ << ")" << msg << std::endl;

char errbuf[PCAP_ERRBUF_SIZE];

#endif // UTILS_H