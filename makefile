CC = g++
CFLAGS = -std=c++11 -Wall -pedantic -pthread

default: main

main: main.o accelerometer.o
	$(CC) $(CFLAGS) -o main main.o accelerometer.o

test_accelerometer: test_accelerometer.o accelerometer.o
	$(CC) $(CFLAGS) -o test_accelerometer test_accelerometer.o accelerometer.o
main.o: main.cpp drivers/Accelerometer.hpp
	$(CC) $(CFLAGS) -c main.cpp

accelerometer.o: drivers/Accelerometer.cpp drivers/Accelerometer.hpp
	$(CC) $(CFLAGS) -c drivers/accelerometer.cpp

test_accelerometer.o: test/test_accelerometer.cpp drivers/Accelerometer.hpp
	$(CC) $(CFLAGS) -c test/test_accelerometer.cpp