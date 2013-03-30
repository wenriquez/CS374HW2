CC=gcc
CFLAGS= -g -Wall -I.
LINKFLAGS= -g -Wall
INC=-pthread

all: client1 client2 server tests

client1: client1.o fifodefs.o
	$(CC) $(LINKFLAGS) $(INC) -o client1 client1.o fifodefs.o

client2: client2.o fifodefs.o
	$(CC) $(LINKFLAGS) $(INC) -o client2 client2.o fifodefs.o

server: server.o fifodefs.o
	$(CC) $(LINKFLAGS) $(INC) -o server server.o fifodefs.o

tests: tests.o fifodefs.o
	$(CC) $(LINKFLAGS) $(INC) -o tests tests.o fifodefs.o

client1.o: client1.c
	$(CC) $(LINKFLAGS) $(INC) -c client1.c -o client1.o

client2.o: client2.c
	$(CC) $(LINKFLAGS) $(INC) -c client2.c -o client2.o

fifodefs.o: fifodefs.c fifodefs.h
	$(CC) $(LINKFLAGS) $(INC) -c fifodefs.c -o fifodefs.o

server.o: server.c
	$(CC) $(LINKFLAGS) $(INC) -c server.c -o server.o

tests.o: tests.c
	$(CC) $(LINKFLAGS) $(INC) -c tests.c -o tests.o

clean:
	rm -f *.o client1 client2 server tests FIFO1 FIFO2

