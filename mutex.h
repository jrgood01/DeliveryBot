#ifndef __MUTEX_H
#define __MUTEX_H

#include "drivers/accelerometer.h"

sensor_data_t sensor_data;
pthread_mutex_t sensor_data_mutex;

#endif