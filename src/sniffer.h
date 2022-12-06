#ifndef SNIFFER_H
#define SNIFFER_H

#include "catch.h"
#include "utils/utils.h"

class Sniffer {
  friend class DevWindow;
  
protected:
  pcap_if_t *allDev_ptr;
  std::vector<pcap_if_t *> allDev_vec;
  const char *dev;  // device name
  bpf_u_int32 mask; // net mask
  bpf_u_int32 net;  // IP address

public:
  Sniffer();
  ~Sniffer();
  bool findAllDevs();
  void getDevName(const char *devName);
  bool getDevInfo();
  bool sniff(); // sniff after setDev
};


#endif // SNIFFER_H