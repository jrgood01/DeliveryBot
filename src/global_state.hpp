#ifndef __GLOBAL_STATE_H_
#define __GLOBAL_STATE_H_
#include <pthread.h>
#include <CppLinuxSerial/SerialPort.hpp>
using namespace mn::CppLinuxSerial;

SerialPort serialPort;
pthread_mutex_t port_lock;

#endif