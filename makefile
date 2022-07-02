CC = g++
CFLAGS = -g -Wall

default: main

main: main.o accelerometer.o
	$(CC) $(CFLAGS) -o main main.o accelerometer.o

main.o: main.cpp drivers/accelerometer.hpp mutex.hpp devices.hpp
	$(CC) $(CFLAGS) -c main.c

accelerometer.o: drivers/accelerometer.cpp drivers/accelerometer.hpp mutex.hpp
	$(CC) $(CFLAGS) -c drivers/accelerometer.c