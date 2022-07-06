cmake_minimum_required(VERSION 3.16)
project(DeliveryBot LANGUAGES CXX)

add_executable(main src/main.cpp src/drivers/Accelerometer.cpp)
target_include_directories(main
        PRIVATE
        src/
        src/drivers
        src/api)