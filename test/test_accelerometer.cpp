#include <stdio.h>
#include <sys/ioctl.h>
#include <fcntl.h>
#include "../drivers/accelerometer.hpp"
int main() {
    char *gsensor_device = "/dev/accel";
    int device = open(gsensor_device , O_RDWR);
    printf("Got device %d\n", device);
    while (1) {
        struct sensor_axis* data = get_data(device);

        printf("X: %d\n", data->x);
        printf("Y: %d\n", data->y);
        printf("Z: %d\n", data->z);
        printf("\n");
    }
}
