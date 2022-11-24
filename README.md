Sniffer X
======

A Not Simple Network Sniffer.

Environment
-----
* Ubuntu 20.04
* Qt 5.9.0
* libpcap 1.10.1

Dependencies
-----
```bash
$ sudo apt-get install qtbase5-dev qtchooser qt5-qmake qtbase5-dev-tools
$ sudo apt-get install libpcap-dev
```

Structure
-----
* `src/` - Source code
  * `src/main.cpp` - Main function
  * `src/mainwindow.cpp` - Main window
  * `src/mainwindow.h` - Main window header
  * `src/sniffer.cpp` - Sniffer
  * `src/sniffer.h` - Sniffer header
* `ui/` - UI files
  * `ui/mainwindow.ui` - Main window UI
* `build/` - Build directory
  * `build/bin/` - Executable directory
    * `build/bin/sniffer` - Executable file

Build & Run
-----
```bash
# build
$ cd ./build
$ qmake -o Makefil ../sniffer.pro
$ make
# run
$ cd ./bin
$ chmod +x ./sniffer 
$ ./sniffer
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
* [Getting Started with qmake](https://doc.qt.io/qt-6.2/qmake-tutorial.html)
* [pcap tutorial](https://www.tcpdump.org/pcap.html)
* [The Sniffer's Guide to Raw Traffic](http://yuba.stanford.edu/~casado/pcap/)