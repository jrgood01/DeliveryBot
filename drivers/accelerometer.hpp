#include <pthread.h>

#ifndef __ACCELEROMETER_H_
#define __ACCELEROMETER_H_

//Header definitions from: https://docs.khadas.com/linux/vim3/GsensorUsage.html
#define GBUFF_SIZE                12
#define GSENSOR_IOCTL_MAGIC       'a'

#define GSENSOR_IOCTL_INIT              _IO(GSENSOR_IOCTL_MAGIC, 0x01)
#define GSENSOR_IOCTL_RESET             _IO(GSENSOR_IOCTL_MAGIC, 0x04)
#define GSENSOR_IOCTL_CLOSE             _IO(GSENSOR_IOCTL_MAGIC, 0x02)
#define GSENSOR_IOCTL_START             _IO(GSENSOR_IOCTL_MAGIC, 0x03)
#define GSENSOR_IOCTL_GETDATA           _IOR(GSENSOR_IOCTL_MAGIC, 0x08, char[GBUFF_SIZE+1])
#define GSENSOR_IOCTL_APP_SET_RATE      _IOW(GSENSOR_IOCTL_MAGIC, 0x10, short)
#define GSENSOR_IOCTL_GET_CALIBRATION   _IOR(GSENSOR_IOCTL_MAGIC, 0x11, int[3])
//-----------------------------------------------------------------------------

class Accelerometer {
private:
    void update_accelerometer_data();
    void update_on_interval(useconds_t interval);
    int* get_data();
    pthread_t update_thread_id;
    pthread_mutex_t sensor_data_mutex;
    const char* ACCELEROMETER_DEVICE_STRING = "/dev/accel";
    int device_id;
public:
    int x;
    int y;
    int z;
    Accelerometer();
    int* read_accelerometer_data();
    void begin_update_on_interval(useconds_t interval);
};

#endif