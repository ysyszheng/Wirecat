#ifndef SNIFFER_H
#define SNIFFER_H

#include "catch.h"
#include "utils/utils.h"

class Sniffer : public QObject {
  Q_OBJECT

  friend class MainWindow;
  friend class DevWindow;
  friend class CThread;

protected:
  pcap_if_t *allDev_ptr;
  std::vector<pcap_if_t *> allDev_vec;
  const char *dev; // device name
  pcap_t *handle;
  bpf_u_int32 mask; // net mask
  bpf_u_int32 net;  // IP address
  flag_t status;    // status {start, stop, restart}

public:
  Sniffer();
  ~Sniffer();
  bool findAllDevs();
  void getDevName(const char *devName);
  bool getDevInfo();

public slots:
  void sniff(); // sniff after setDev
};

#endif // SNIFFER_H