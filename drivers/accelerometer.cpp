#include <sys/ioctl.h>
#include <fcntl.h>
#include <pthread.h>
#include <stdlib.h>
#include <stdexcept>
#include <system_error>
#include <unistd.h>
#include "accelerometer.hpp"

Accelerometer::Accelerometer() {
    pthread_mutex_init(&this->sensor_data_mutex, NULL);
    this->device_id = open(this->ACCELEROMETER_DEVICE_STRING, O_RDWR);
    if(this->device_id < 0) {
        //throw std::system_error("Failed to open accelerometer device")
    }
};

/*
 * Gets data directly from the accelerometer
 * @return an array containing 3 ints: x, y, z
 */
int* Accelerometer::get_data() {
    int* data = (int*) malloc(sizeof(int) * 3);
    ioctl(this->device_id, GSENSOR_IOCTL_GETDATA, data);
    return data;
}

/*
 * Writes the current accelerometer data into the buffer
 */
void Accelerometer::update_accelerometer_data() {
    int* data = this->get_data();
    pthread_mutex_lock(&this->sensor_data_mutex);
    this->x = data[0];
    this->y = data[1];
    this->z = data[2];
    pthread_mutex_unlock(&this->sensor_data_mutex);
}

/*
 * Read Accelerometer data from the buffer
*/
int* Accelerometer::read_accelerometer_data() {
    int* data = (int*) malloc(sizeof(int) * 3);
    pthread_mutex_lock(&this->sensor_data_mutex);
    data[0] = this->x;
    data[1] = this->y;
    data[2] = this->z;
    pthread_mutex_unlock(&this->sensor_data_mutex);
    return data;
}

/*
 * helper method to update accelerometer buffer on interval
 */
void *Accelerometer::update_on_interval(void* p) {
    Accelerometer *acc = (Accelerometer*) p;
    while(1) {
        acc->update_accelerometer_data();
        usleep(acc->update_interval);
    }
};

/*
 * Updates the Accelerometer async on a specified interval
 * @param interval the interval in microseconds
 */
void Accelerometer::begin_update_on_interval(useconds_t interval) {
    this->update_interval = interval;
    if (update_thread_id) {
        pthread_cancel(this->update_thread_id);
    }
    if (pthread_create(&this->update_thread_id, NULL, Accelerometer::update_on_interval, this)) {
        perror("could not create thread for accelerometer update");
    }
};