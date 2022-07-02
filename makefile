main: main.c
	gcc -o main drivers/accelerometer.c main.c
test: test/accelerometer.c
	gcc -o test/accelerometer drivers/accelerometer.c test/accelerometer.c
