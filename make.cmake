cmake_minimum_required(VERSION 3.16)
project(DeliveryBot LANGUAGES CXX)

add_executable(main 
    main.cpp,
    drivers/Accelerometer.cpp,
    global_state.h,
    drivers/Accelerometer.h
)