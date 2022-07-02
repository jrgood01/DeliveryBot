//Got this header from: https://docs.khadas.com/linux/vim3/GsensorUsage.html
#define GBUFF_SIZE                12
#define GSENSOR_IOCTL_MAGIC       'a'

#define GSENSOR_IOCTL_INIT              _IO(GSENSOR_IOCTL_MAGIC, 0x01)
#define GSENSOR_IOCTL_RESET             _IO(GSENSOR_IOCTL_MAGIC, 0x04)
#define GSENSOR_IOCTL_CLOSE             _IO(GSENSOR_IOCTL_MAGIC, 0x02)
#define GSENSOR_IOCTL_START             _IO(GSENSOR_IOCTL_MAGIC, 0x03)
#define GSENSOR_IOCTL_GETDATA           _IOR(GSENSOR_IOCTL_MAGIC, 0x08, char[GBUFF_SIZE+1])
#define GSENSOR_IOCTL_APP_SET_RATE      _IOW(GSENSOR_IOCTL_MAGIC, 0x10, short)
#define GSENSOR_IOCTL_GET_CALIBRATION   _IOR(GSENSOR_IOCTL_MAGIC, 0x11, int[3])

struct sensor_axis {
    int x;
    int y;
    int z;
};

byte* get_data(int device);