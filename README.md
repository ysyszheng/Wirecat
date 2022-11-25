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
  * `build/build.sh` - Build script
  * `build/sniffer.pro` - Project file
  * `build/bin/` - Executable directory
    * `build/bin/sniffer` - Executable file

Build & Run
-----

Use `build.sh` script: 


```bash
# build
$ cd build
$ bash build.sh
# run
$ ./bin/sniffer
```

Manually: 

```bash
# build
$ cd ./build
$ qmake -o Makefile ./sniffer.pro
$ make
# run
$ cd ./bin
$ chmod +x ./sniffer 
$ ./sniffer
```

Test
-----

Test sniffer in terminal: 

```bash
$ cd test
# make clean if necessary
$ make
$ sudo ./test
```

The output should be like this: 

```bash
Available devices: 
  @: eth0
  @: any
  @: lo
  @: dummy0
  @: tunl0
  @: sit0
  @: bluetooth-monitor
  @: nflog
  @: nfqueue
  @: dbus-system
  @: dbus-session
  @: bond0
Input Devices: 
eth0 # your inputs
NET: 0.224.30.172

Packet number 1:
  Src Host Ethernet Address: 0:15:5d:bc:b1:16
  Dst Host Ethernet Address: 0:15:5d:e1:b:30
  Ethernet Type: IPv4
    Src Host IPv4 Address: 172.30.231.192
    Dst Host IPv4 Address: 172.30.224.1
    Protocol: UDP
      Src port: 40845
      Dst port: 53
Payload (33 bytes):
00000  fb 6f 01 00 00 01 00 00  00 00 00 00 03 61 70 69  .o......  .....api
00010  07 74 61 62 6e 69 6e 65  03 63 6f 6d 00 00 01 00  .tabnine  .com....
00020  01                                                .                 
```

TODO
-----
* [x] GUI framework
* [x] Find all network devices
* [x] Catch packets
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
* [sniffex.c](https://www.tcpdump.org/other/sniffex.c)
* [libpcap packet capture tutorial](http://yuba.stanford.edu/~casado/pcap/)