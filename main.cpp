#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <fcntl.h>

#include "drivers/accelerometer.hpp"
#include "mutex.hpp"
#include "devices.hpp"

void init() {
    sensor_data = (sensor_axis_t*) malloc(sizeof(int) * 3);
    pthread_mutex_init(&sensor_data_mutex, NULL);
    accelerometer_id = open(ACCELEROMETER_DEVICE_STRINGm O_RDWR);
}

int main() {
    init();
}