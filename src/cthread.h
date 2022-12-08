#ifndef CTHREAD_H
#define CTHREAD_H

#include "sniffer.h"
#include "utils/utils.h"
#include "view.h"

class CThread : public QThread {
  friend class MainWindow;

  Q_OBJECT
public:
  CThread();
  CThread(Sniffer *snifferObj);
  ~CThread();
  void run();
  // void stop();
  // void wait();

private:
  Sniffer *sniffer;
  View *view;

  flag_t flag;
  // void get_packet(u_char *args, const struct pcap_pkthdr *header,
  //                 const u_char *packet);
  // void handle_ipv4(const u_char *packet);
  // void handle_arp(const u_char *packet);
  // void handle_ipv6(const u_char *packet);
  // void handle_tcp(const u_char *packet, size_t hdr_len, size_t total_len);
  // void handle_udp(const u_char *packet, size_t hdr_len, size_t total_len);
  // void handle_icmp(const u_char *packet, size_t hdr_len, size_t total_len);
  // void handle_igmp(const u_char *packet, size_t hdr_len, size_t total_len);
};

#endif // CTHREAD_H