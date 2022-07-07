#include "drivers/Accelerometer.h"
#include "drivers/Camera.h"

#ifndef __GLOBAL_STATE_H_
#define __GLOBAL_STATE_H_

extern bool manual_control_enabled;

extern Accelerometer* robot_accelerometer;
extern Camera* robot_camera;

#endif