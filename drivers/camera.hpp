class Camera {
    private:
        pthread_t update_thread_id;
        pthread_mutex_t camera_data_mutex;
    public:
        void register_frame_handler(void (*handler)());
        void set_frame_rate(int rate);
        void set_resolution(int width, int height);

};