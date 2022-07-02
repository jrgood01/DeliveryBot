#ifndef __MUTEX_H
#define __MUTEX_H

#include <pthread.h>
#include "drivers/accelerometer.hpp"

extern pthread_mutex_t sensor_data_mutex;

#endif