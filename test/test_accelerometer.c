#include <stdio.h>
#include <sys/ioctl.h>
#include <fcntl.h>
#include "../drivers/accelerometer.h"
int main() {
    int device = open("/dev/accelerometer", O_RDWR);
    while (true) {
        struct sensor_axis* data = get_data(0);
        printf("X: %d\n", data->x);
        printf("Y: %d\n", data->y);
        printf("Z: %d\n", data->z);
        printf("\n");
    }
}