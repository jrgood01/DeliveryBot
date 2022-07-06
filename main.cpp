#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <fcntl.h>

#include "drivers/Accelerometer.hpp"
#include "global_state.hpp"

int main() {
    robot_accelerometer = accelerometer();
}