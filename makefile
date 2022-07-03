CC = g++
CFLAGS = -std=c++11 -Wall -pedantic

default: main

main: main.o accelerometer.o
	$(CC) $(CFLAGS) -o main main.o accelerometer.o

main.o: main.cpp drivers/accelerometer.hpp
	$(CC) $(CFLAGS) -c main.cpp

accelerometer.o: drivers/accelerometer.cpp drivers/accelerometer.hpp
	$(CC) $(CFLAGS) -c drivers/accelerometer.cpp