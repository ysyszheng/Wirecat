#ifndef UTILS_H
#define UTILS_H

#include <iostream>
#include <pcap.h>

#define FALSE 0
#define TRUE 1
#define PRINT_DEV_INFO TRUE
#define LOG(msg)                                                               \
  std::cout << "(" << __FILE__ << ":" << __LINE__ << ")" << msg << std::endl;


#endif // UTILS_H