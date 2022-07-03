#include <stdio.h>
#include "../drivers/accelerometer.hpp"
int main() {
    Accelerometer* accelerometer = new Accelerometer();
    accelerometer->begin_update_on_interval(1000);
    while(1) {
        int* ret_data = accelerometer.read_accelerometer_data();
        printf("x: %d y: %d z: %d", ret_data[0], ret_data[1], ret_data[2]);
        usleep(100000)
    }
}
