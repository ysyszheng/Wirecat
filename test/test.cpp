#include "../src/sniffer.h"
#include "../src/utils/utils.h"

int main(int argc, char **argv) {
  const char *devName;
  std::string devNameStr;
  Sniffer sniffer;
  sniffer.findAllDevs();

  std::cout << "Input Devices: ";
  std::cin >> devNameStr;
  devName = devNameStr.c_str();

  sniffer.getDevName(devName);
  sniffer.getDevInfo();
  sniffer.sniff();

  return 0;
}
