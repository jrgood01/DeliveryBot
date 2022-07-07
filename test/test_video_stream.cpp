#include <stdio.h>
#include <unistd.h>
#include "drivers/Camera.h"
int main() {
    Camera* cam = new Camera();
    while(1) {
        cam->begin_update_camera();
        usleep(10000)
        Mat frame = cam->get_frame();
        cv::FileStorage fs("cap.jpg", cv::FileStorage::WRITE);
        fs << "CamData" << frame;
        fs.release();
    }
}
