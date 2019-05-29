# Makefile for OPS exercise 5
# Use tabs for indentation, not spaces!

all: printversion getsignal sendsignal

# Link object files and create a binary executable:
getsignal: getsignal_sendpid.o 
	gcc -Wall -o getsignal_sendpid getsignal_sendpid.o

sendsignal: sendsignal_getpid.o
	gcc -Wall -o sendsignal_getpid sendsignal_getpid.o

# Compile C-files and create object files (.o).
# The option -c ensures no linking takes place:
getsignal.o: getsignal_sendpid.c
	gcc -c -Wall getsignal_sendpid.c

sendsignal.o: sendsignal_getpid.c
	gcc -c -Wall sendsignal_getpid.c

clean:
	rm -f *.o

cleanall: clean
	rm -f getsignal_sendpid sendsignal_getpid

printversion:
	gcc --version | grep gcc
