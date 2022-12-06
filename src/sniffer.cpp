#include "sniffer.h"

Sniffer::Sniffer() {
  dev = NULL;
  allDev_ptr = NULL;
  findAllDevs();
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
    printf("Device Info:\n");
    printf("NET: %d.%d.%d.%d\tmask: %d.%d.%d.%d\n", (net >> 24) & 0xff,
           (net >> 16) & 0xff, (net >> 8) & 0xff, (net)&0xff,
           (mask >> 24) & 0xff, (mask >> 16) & 0xff, (mask >> 8) & 0xff,
           mask & 0xff);
  }
  return TRUE;
}

bool Sniffer::sniff() {
  char errbuf[PCAP_ERRBUF_SIZE];
  pcap_t *handle;
  int num_packets = -1;

  handle = pcap_open_live(dev, BUFSIZ, -1, 1000, errbuf);
  if (handle == NULL) {
    ERROR_INFO(errbuf);
    return FALSE;
  }

  pcap_loop(handle, num_packets, get_packet, NULL);

  pcap_close(handle);

  return TRUE;
}