cmake_minimum_required(VERSION 3.16)
project(DeliveryBot LANGUAGES CXX)

add_executable(main 
    ${PROJECT_SOURCE_DIR}/DeliveryBot/main.cpp,
    ${PROJECT_SOURCE_DIR}/DeliveryBot/drivers/Accelerometer.cpp,
)

target_sources(${PROJECT_NAME}
        PRIVATE
        ${PROJECT_SOURCE_DIR}/drivers/Accelerometer.cpp
        ${PROJECT_SOURCE_DIR}/DeliveryBot/global_state.h,
        ${PROJECT_SOURCE_DIR}/DeliveryBot/drivers/Accelerometer.h

        PUBLIC
        ${PROJECT_SOURCE_DIR}/main.cpp
)