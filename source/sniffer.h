#ifndef SNIFFER_H
#define SNIFFER_H

#include <pcap.h>
#include <vector>
#include "utils.h"

class Sniffer {
private:
  pcap_if_t *allDev_ptr;
  std::vector<pcap_if_t *> allDev_vec;
public:
  Sniffer();
  ~Sniffer();
  bool findAllDevs();
};

#endif // SNIFFER_H