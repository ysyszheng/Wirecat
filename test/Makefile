CXX = g++
CXXFLAG = -Wall -O3
PCAP = -lpcap
SOURCES = test.cpp ../src/sniffer.cpp

test: $(SOURCE)
	$(CXX) $(CXXFLAG) -o test $(SOURCES) $(PCAP)

clean:
	rm test