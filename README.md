:smile_cat:Wirecat
======

A Not Simple Network Sniffer.

![demo](doc/img/demo.png)

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
  * `src/utils/` - Utility functions
  * `src/utils/utils.h` - Utility functions header
  * `src/utils/utils.cpp` - Utility functions implementation
  * `src/utils/hdr.h` - Package header information
  * `src/main.cpp` - Main function
  * `src/mainwindow.cpp` - Main window
  * `src/mainwindow.h` - Main window header
  * `src/sniffer.cpp` - Sniffer
  * `src/sniffer.h` - Sniffer header
  * `src/catch.h` - Catch package
  * `src/catch.cpp` - Catch package implementation
* `ui/` - UI files
  * `ui/mainwindow.ui` - Main window UI
* `build/` - Build directory
  * `build/build.sh` - Build script
  * `build/sniffer.pro` - Project file
  * `build/bin/` - Executable directory
    * `build/bin/sniffer` - Executable file
* `test/` - Test directory
  * `Makefile` - Makefile
  * `test/test.cpp` - Test file

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
Input Devices: eth0 # your inputs
Device Info:
NET: 0.224.30.172       mask: 0.240.255.255

Packet number 1:
  Src Host MAC Address: 0:15:5d:e1:b:30
  Dst Host MAC Address: 1:0:5e:7f:ff:fa
  Ethernet Type: IPv4
    Src Host IPv4 Address: 172.30.224.1
    Dst Host IPv4 Address: 239.255.255.250
    Protocol: UDP
      Src port: 60090
      Dst port: 1900
Payload (175 bytes):
00000  4d 2d 53 45 41 52 43 48  20 2a 20 48 54 54 50 2f  M-SEARCH   * HTTP/
00010  31 2e 31 0d 0a 48 4f 53  54 3a 20 32 33 39 2e 32  1.1..HOS  T: 239.2
00020  35 35 2e 32 35 35 2e 32  35 30 3a 31 39 30 30 0d  55.255.2  50:1900.
00030  0a 4d 41 4e 3a 20 22 73  73 64 70 3a 64 69 73 63  .MAN: "s  sdp:disc
00040  6f 76 65 72 22 0d 0a 4d  58 3a 20 31 0d 0a 53 54  over"..M  X: 1..ST
00050  3a 20 75 72 6e 3a 64 69  61 6c 2d 6d 75 6c 74 69  : urn:di  al-multi
00060  73 63 72 65 65 6e 2d 6f  72 67 3a 73 65 72 76 69  screen-o  rg:servi
00070  63 65 3a 64 69 61 6c 3a  31 0d 0a 55 53 45 52 2d  ce:dial:  1..USER-
00080  41 47 45 4e 54 3a 20 47  6f 6f 67 6c 65 20 43 68  AGENT: G  oogle Ch
00090  72 6f 6d 65 2f 31 30 37  2e 30 2e 35 33 30 34 2e  rome/107  .0.5304.
000a0  31 30 37 20 57 69 6e 64  6f 77 73 0d 0a 0d 0a     107 Wind  ows....
```

Save to log file: 

```bash
$ cd test
$ mkdir log
# make clean if necessary
$ make
$ echo "eth0" > test.in # change "eth0" to your device
$ sudo ./test < test.in > ./log/"$(date +"%Y-%m-%d_%H-%M-%S").log"
```

TODO
-----
* [x] GUI framework
* [x] Find all network devices
* [x] Catch packets
* [x] Parse packets (Parse IP, TCP, UDP, ICMP, ARP, etc.)
* [ ] IP fragmentation reassembly
* [ ] Filter packets (Filter IP addresses (src & dst), ports (src & dst), protocols, etc.)
* [ ] Search packets (Search by content, etc.)
* [ ] Save packets (Save packets to readable file)
* [ ] File reassembly (Reassemble files from TCP packets)
* [ ] Interact in GUI (Show packets info in GUI)
* [ ] Beautify UI (QStyle class may be helpful)

Reference
-----
Resources
* [Getting Started with qmake](https://doc.qt.io/qt-6.2/qmake-tutorial.html)
* [pcap tutorial](https://www.tcpdump.org/pcap.html)
* [sniffex.c](https://www.tcpdump.org/other/sniffex.c)
* [libpcap packet capture tutorial](http://yuba.stanford.edu/~casado/pcap/)
* [Qt groupbox example](https://doc.qt.io/qt-5/qtwidgets-widgets-groupbox-example.html)

Q&A
* [QGroupBox find selected Radio Button](https://stackoverflow.com/questions/43106746/qgroupbox-find-selected-radio-button)
* [Qt forward declaration problem](https://stackoverflow.com/questions/21113581/qt-invalid-use-of-incomplete-type-and-forward-declaration)
* [Include Qt path in vscode-clangd](https://stackoverflow.com/questions/61206703/is-there-includepath-option-in-clangd#answer-69269142)