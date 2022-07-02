#include <sys/ioctl.h>
#include <fcntl.h>
#include "accelerometer.h"
struct sensor_axis get_data(int device) {
    struct sensor_axis data = (int*) malloc(sizeof(int) * 3);
    ioctl(device, GSENSOR_IOCTL_GETDATA, &data);
    return data;
}

