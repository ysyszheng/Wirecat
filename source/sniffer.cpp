#include "sniffer.h"
#include "utils.h"
#include <iostream>
#include <pcap.h>
#include <sys/socket.h>

Sniffer::Sniffer() { allDev_ptr = NULL; }

Sniffer::~Sniffer() {
  if (allDev_ptr)
    pcap_freealldevs(allDev_ptr);
}

bool Sniffer::findAllDevs() {
  pcap_findalldevs(&allDev_ptr, errbuf);

  if (allDev_ptr == NULL) {
    printf("pcap_findalldevs(): %s", errbuf);
    return FALSE;
  }

  for (pcap_if_t *pdev = allDev_ptr; pdev; pdev = pdev->next) {
    if (PRINT_DEV_INFO) {
      std::cout << "@: " << pdev->name << std::endl;
    }
    allDev_vec.push_back(pdev);
  }
  return TRUE;
}