main: main.c
	gcc -o main drivers/accelerometer.c main.c
test: test/test_accelerometer
	gcc -o test/accelerometer drivers/accelerometer.c test/accelerometer.c
