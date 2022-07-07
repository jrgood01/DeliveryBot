#include <stdio.h>
#include <unistd.h>
#include "drivers/Camera.h"
int main() {
    Camera* cam = new Camera();
    while(1) {
        cam->begin_update_camera();
        Mat frame = cam->get_frame();
        cv::FileStorage fs("cap.jpg", cv::FileStorage::WRITE); // create FileStorage object
        fs << frame; // command to save the data
        fs.release(); // releasing the file.
    }
}
