class Camera {
    static void* update_frame(void *p);
    private:
        pthread_t update_thread_id;
        pthread_mutex_t camera_data_mutex;
        VideoCapture capture;
        Mat cur_frame;
        const char* device_str = "/dev/video0";
        int frame_rate = 40;
    public:
        Camera();
        Mat get_frame();
        void register_frame_handler(void (*handler)());
        void set_frame_rate(int rate);
        void begin_update_camera(void* p);
};