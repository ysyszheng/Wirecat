CXX = g++
CXXFLAG = -Wall -O3
PCAP = -lpcap
SOURCES = test.cpp \
	../src/sniffer.cpp ../src/utils/utils.cpp \
	../src/capture.cpp

test: $(SOURCE)
	$(CXX) $(CXXFLAG) -o test $(SOURCES) $(PCAP)

clean:
	rm test