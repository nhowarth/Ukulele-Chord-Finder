#CC=gcc
CXX=g++
#CXXFLAGS=-g -Wall $(shell root-config --cflags)
CXXFLAGS=-g -Wall
#LDFLAGS=-g $(shell root-config --ldflags)
LDFLAGS=-Wall
#LDLIBS=$(shell root-config --libs)

SRCS=main.cpp ukulele.cpp chord.cpp note.cpp
OBJS=$(subst .cpp,.o,$(SRCS))

all: main

main: $(OBJS)
	$(CXX) $(LDFLAGS) -o main $(OBJS)

main.o: main.cpp ukulele.h
	$(CXX) $(CXXFLAGS) -c main.cpp

ukulele.o: ukulele.cpp ukulele.h chord.h note.h
	$(CXX) $(CXXFLAGS) -c ukulele.cpp

chord.o: chord.cpp chord.h note.h
	$(CXX) $(CXXFLAGS) -c chord.cpp

note.o: note.cpp note.h
	$(CXX) $(CXXFLAGS) -c note.cpp

clean:
	rm -f $(OBJS) main

