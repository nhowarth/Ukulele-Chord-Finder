CC=gcc
CXX=g++
CXXFLAGS=-g -Wall $(shell root-config --cflags)
LDFLAGS=-g $(shell root-config --ldflags)
LDLIBS=$(shell root-config --libs)

SRCS=main.cpp ukulele.cpp chord.cpp note.cpp
OBJS=$(subst .cpp, .o, $(SRCS))

all: main

main: $(OBJS)
	$(CXX) $(CXXFLAGS) -o main $(OBJS) $(LDLIBS)

main.o: main.cpp ukulele.h

ukulele.o: ukulele.cpp ukulele.h chord.h note.h

chord.o: chord.cpp chord.h note.h

note.o: note.cpp note.h

clean:
	rm -f $(OBJS) main
