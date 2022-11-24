#ifndef SNIFFER_H
#define SNIFFER_H

#include "utils.h"
#include <pcap.h>
#include <vector>


class Sniffer {
private:
  pcap_if_t *allDev_ptr;
  std::vector<pcap_if_t *> allDev_vec;
  pcap_if_t *cur_dev;

public:
  Sniffer();
  ~Sniffer();
  bool findAllDevs();
};

#endif // SNIFFER_H