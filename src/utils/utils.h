#ifndef UTILS_H
#define UTILS_H

#include <iostream>
#include <cstdio>
#include <vector>
#include <pcap.h>
#include <pcap/pcap.h>
#include <sys/socket.h>

#define FALSE 0
#define TRUE 1
#define PRINT_DEV_NAME TRUE
#define PRINT_DEV_INFO TRUE
#define ERROR_INFO(msg)                                                        \
  std::cout << "(" << __FILE__ << ":" << __LINE__ << ") " << __FUNCTION__      \
            << "(): " << msg << std::endl;
#define LOG(msg)                                                               \
  std::cout << "(" << __FILE__ << ":" << __LINE__ << ")" << msg << std::endl;

#endif // UTILS_H