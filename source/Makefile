CC = g++
CFLAGS = -Wall -O3
oS = main.o minwindow.o

sniffer: $(oS)
	$(CC) $(CFLAGS) -o ../bin/sniffer $(oS)

main.o: ./main.cpp ./mainwindow.h
	$(CC) $(CFLAGS) -c ./main.cpp

minwindows.o: ./mainwindow.cpp ./mainwindow.h
	$(CC) $(CFLAGS) -c ./mainwindow.cpp

clean:
	rm ./*.o

rmsniffer:
	rm ../bin/sniffer
