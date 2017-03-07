CC=g++
CFLAGS=-g -Wall

main: note.o chord.o ukulele.o

EXEC= note chord ukulele main

all: $(EXEC)

clean:
	rm -f *.o main
