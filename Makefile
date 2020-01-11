# -*- Makefile -*-
all: dinlib.so frequency

frequency: main.o dinlib.so
	gcc -Wall -o frequency main.o ./dinlib.so
dinLib: dinlib.so

dinlib.so: freq.o
	gcc -shared -o dinlib.so freq.o

main.o: main.c freq.h
	gcc -Wall -fPIC -g -c main.c
.PHONY: clean all dinLib

freq.o: freq.c freq.h
	gcc -Wall -fPIC -g -c freq.c

clean: 
	rm -f *.o *.so frequency
