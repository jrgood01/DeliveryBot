CC = gcc
CFLAGS = -g -Wall

default: main

main: main.o accelerometer.o
	$(CC) $(CFLAGS) -o main main.o accelerometer.o

main.o: main.c drivers/accelerometer.h mutex.h
	$(CC) $(CFLAGS) -c main.c

accelerometer.o: drivers/accelerometer.c drivers/accelerometer.h mutex.h
	$(CC) $(CFLAGS) -c drivers/accelerometer.c