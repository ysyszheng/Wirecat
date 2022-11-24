#include "../src/sniffer.h"
#include "../src/utils.h"

int main(int argc, char **argv) {
  Sniffer sniffer;
  sniffer.findAllDevs();

  const char *devName = "eth0";
  sniffer.getDevName(devName);
  sniffer.getDevInfo();
  sniffer.sniff();

  return 0;
}