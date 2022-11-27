CXX = g++
CXXFLAG = -Wall -O3
PCAPFLAG = -lpcap
SOURCES = test.cpp \
	../src/sniffer.cpp ../src/utils/utils.cpp \
	../src/catch.cpp
HEADERS = ../src/sniffer.h ../src/utils/utils.h \
	../src/catch.h ../src/utils/hdr.h

test: $(SOURCE) $(HEADERS)
	$(CXX) $(CXXFLAG) -o test $(SOURCES) $(PCAPFLAG)

clean:
	rm test