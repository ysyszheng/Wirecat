#include "sniffer.h"

Sniffer::Sniffer() {
  dev = NULL;
  allDev_ptr = NULL;
}

Sniffer::~Sniffer() {
  if (allDev_ptr)
    pcap_freealldevs(allDev_ptr);
}

bool Sniffer::findAllDevs() {
  char errbuf[PCAP_ERRBUF_SIZE];
  pcap_findalldevs(&allDev_ptr, errbuf);

  if (allDev_ptr == NULL) {
    ERROR_INFO(errbuf);
    exit(1);
  }

  if (PRINT_DEV_NAME) {
    printf("Available devices: \n");
  }

  for (pcap_if_t *pdev = allDev_ptr; pdev; pdev = pdev->next) {
    if (PRINT_DEV_NAME) {
      std::cout << "  @: " << pdev->name << std::endl;
    }
    allDev_vec.push_back(pdev);
  }
  return TRUE;
}

void Sniffer::getDevName(const char *devName) { dev = devName; }

bool Sniffer::getDevInfo() {
  char errbuf[PCAP_ERRBUF_SIZE];

  if (pcap_lookupnet(dev, &net, &mask, errbuf) == -1) {
    ERROR_INFO(errbuf);
    net = 0;
    mask = 0;
    return FALSE;
  }

  if (PRINT_DEV_INFO) {
    std::cout << "NET: " << net << " mask: " << mask << std::endl;
  }
  return TRUE;
}

bool Sniffer::sniff() {
  char errbuf[PCAP_ERRBUF_SIZE];
  pcap_t *handle;
  // struct pcap_pkthdr header; /* The header that pcap gives us */
  // const u_char *packet;      /* The actual packet */
  size_t num_packets = 10;

  handle = pcap_open_live(dev, BUFSIZ, 1, 1000, errbuf);
  if (handle == NULL) {
    ERROR_INFO(errbuf);
    return FALSE;
  }

  pcap_loop(handle, num_packets, get_packet, NULL);

  pcap_close(handle);

  return TRUE;
}