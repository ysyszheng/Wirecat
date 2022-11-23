Sniffer X
======

A Not Simple Network Sniffer.

Env
-----
* Ubuntu 20.04 LTS
* Qt 5.9.0 LTS
* libpcap 1.10.1

Dependencies
-----
```bash
$ sudo apt-get install qtbase5-dev qtchooser qt5-qmake qtbase5-dev-tools
$ sudo apt-get install libpcap-dev
```

Build
-----
```bash
$ cd ./source
$ qmake -o Makefil Sniffer.pro
$ make
```

Run
-----
```bash
$ cd ./bin
$ chmod +x ./Sniffer 
$ ./Sniffer
```

TODO
-----
* [x] GUI framework
* [x] Find all network devices
* [ ] Capture packets
* [ ] Parse packets (Parse IP, TCP, UDP, ICMP, ARP, etc.)
* [ ] IP fragmentation reassembly
* [ ] Filter packets (Filter IP addresses (src & dst), ports (src & dst), protocols, etc.)
* [ ] Search packets (Search by content, etc.)
* [ ] Save packets (Save packets to readable file)
* [ ] File reassembly (Reassemble files from TCP packets)
* [ ] Interact in GUI (Show packets info in GUI)

Reference
-----
* [pcap tutorial](https://www.tcpdump.org/pcap.html)
* [The Sniffer's Guide to Raw Traffic](http://yuba.stanford.edu/~casado/pcap/)