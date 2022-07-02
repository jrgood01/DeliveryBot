#include <stdio.h>
#include <pthread.h>
#include "drivers/accelerometer.h"
#include "mutex.h"
int main() {
   sensor_data = malloc(sizeof(int) * 3);
   pthread_mutex_init(&sensor_data_mutex, NULL);
}