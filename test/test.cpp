#include "../src/sniffer.h"
#include "../src/utils/utils.h"

int main(int argc, char **argv) {
  // Sniffer sniffer;
  // sniffer.findAllDevs();

  // const char *devName = "eth0";
  // sniffer.getDevName(devName);
  // sniffer.getDevInfo();
  // sniffer.sniff();

  const u_char c[] = "www.baidu.com\0\0\0\0\0[[[[[]]]]]\0s\0[>\0ab45";
  print_payload(c, 38);

  return 0;
}