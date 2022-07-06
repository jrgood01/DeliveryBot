cmake_minimum_required(VERSION 3.16)
project(DeliveryBot LANGUAGES CXX)

add_executable(main 
    DeliveryBot/main.cpp,
    DeliveryBot/drivers/Accelerometer.cpp,
    DeliveryBot/global_state.h,
    DeliveryBot/drivers/Accelerometer.h
)