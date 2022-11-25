#include "../src/sniffer.h"
#include "../src/utils/utils.h"

int main(int argc, char **argv) {
  Sniffer sniffer;
  sniffer.findAllDevs();

  const char *devName = "eth0";
  sniffer.getDevName(devName);
  sniffer.getDevInfo();
  sniffer.sniff();

  // const u_char c[] = "\0\0<]\0D\0\0**#\0\0\0E\0\0)\0\0@";
  // print_payload(c, 21);

  return 0;
}