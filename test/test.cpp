#include "../src/sniffer.h"
#include "../src/utils.h"
#include <iostream>
#include <pcap.h>

int main(int argc, char **argv) {
  Sniffer sniffer;
  sniffer.findAllDevs();
  return 0;
}