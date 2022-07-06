cmake_minimum_required(VERSION 3.16)
project(DeliveryBot LANGUAGES CXX)

target_sources(${PROJECT_NAME}
        PRIVATE
        drivers/Accelerometer.cpp

        PUBLIC
        main.cpp
)

add_executable(main 
    ${PROJECT_SOURCE_DIR}/DeliveryBot/main.cpp,
    ${PROJECT_SOURCE_DIR}/DeliveryBot/drivers/Accelerometer.cpp,
    ${PROJECT_SOURCE_DIR}/DeliveryBot/global_state.h,
    ${PROJECT_SOURCE_DIR}/DeliveryBot/drivers/Accelerometer.h
)