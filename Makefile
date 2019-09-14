CC=g++
CFLAGS=-c -Wall -std=c++17

all: matrix

matrix: main.o matrix.o
				$(CC) matrix.o main.o -o matrix

main.o: main.cpp
				$(CC) $(CFLAGS) main.cpp

matrix.o: matrix.h matrix.cpp
				$(CC) $(CFLAGS) matrix.h matrix.cpp

clean:
				rm -rf *.o *.gch