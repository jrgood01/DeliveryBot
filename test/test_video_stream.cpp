#include <stdio.h>
#include <unistd.h>
#include "drivers/Camera.h"
int main() {
    Camera* cam = new Camera();
    cam->begin_update_camera();
    usleep(1000000);
    Mat frame = cam->get_frame();
    cv::FileStorage fs("cap.jpg", cv::FileStorage::WRITE);
    fs << "CamData" << frame;
    fs.release();
}
