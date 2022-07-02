#include <sys/ioctl.h>
#include <fcntl.h>
#include <pthread.h>
#include <stdlib.h>
#include "accelerometer.h"
#include "../mutex.h"

//Get the data from the accelerometer
sensor_axis_t* get_data(int device) {
    sensor_axis_t* data = malloc(sizeof(int) * 3);
    ioctl(device, GSENSOR_IOCTL_GETDATA, data);
    return data;
}

//Write acceletometer data into mutex protected memory
void upload_accelerometer_data(int device) {
    sensor_axis_t* data = get_data(device);
    pthread_mutex_lock(&sensor_data_mutex);
    sensor_data->x = data.x;
    sensor_data->y = data.y;
    sensor_data->z = data.z;
    pthread_mutex_unlock(&sensor_data_mutex);
}

//Read acceletometer data from mutex protected memory
sensor_axis_t read_accelerometer_data(int device) {
    sensor_axis_t data;
    pthread_mutex_lock(&sensor_data_mutex);
    data.x = sensor_data->x;
    data.y = sensor_data->y;
    data.z = sensor_data->z;
    pthread_mutex_unlock(&sensor_data_mutex);
    return data;
}