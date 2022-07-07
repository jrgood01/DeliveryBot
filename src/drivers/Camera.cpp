#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/core.hpp>
#include <unistd.h>
#include <pthread.h>
#include <iostream>
#include <stdio.h>
#include "Camera.h"

using namespace cv;

Camera::Camera() {
    int deviceID = 0;
    int apiID = cv::CAP_ANY;
    this->capture.open(deviceID, apiID);
    if (!this->capture.isOpened()) {
        std::cerr << "ERROR! Unable to open camera\n";
    }
};

void Camera::set_frame_rate(int rate) {
    this->frame_rate = frame_rate;
}

void* Camera::update_frame(void* p) {
    Camera *cam = (Camera*) p;
    while(1) {
        pthread_mutex_lock(&cam->camera_data_mutex);
        cam->capture.read(cam->capture->cur_frame);
        if (cam->cur_frame.empty()) {
            std::cerr << "Error! no data from camera capture\n";
        }
        pthread_mutex_unlock(&cam->camera_data_mutex);
        usleep(1000000 / cam->frame_rate);
    }
}

Mat Camera::get_frame() {
    pthread_mutex_lock(&this->camera_data_mutex);
    Mat frame = this->cur_frame;
    pthread_mutex_unlock(&this->camera_data_mutex);
    return frame;
}

void Camera::begin_update_camera() {
    if (update_thread_id) {
        pthread_cancel(update_thread_id);
    }

    if (pthread_create(&this->update_thread_id, NULL, Camera::update_frame, this)) {
        perror("could not create thread for camera update");
    }
}