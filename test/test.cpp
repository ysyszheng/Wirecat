#include "../src/sniffer.h"
#include "../src/utils/utils.h"

int main(int argc, char **argv) {
  char *devName = NULL;
  Sniffer sniffer;
  sniffer.findAllDevs();

  std::cout << "Input Devices: " << std::endl;
  scanf("%s", devName);

  sniffer.getDevName(devName);
  sniffer.getDevInfo();
  sniffer.sniff();

  return 0;
}
