cmake_minimum_required(VERSION 3.16)
set(CMAKE_CXX_FLAGS -pthread)

project(DeliveryBot LANGUAGES CXX)

find_package(oatpp 1.3.0 REQUIRED)
target_link_libraries(${project_name}
        PUBLIC oatpp::oatpp
        PUBLIC oatpp::oatpp-test
        )

target_include_directories(${project_name}-lib PUBLIC src)

add_executable(main src/main.cpp src/drivers/Accelerometer.cpp)
target_include_directories(main
        PRIVATE
        src/
        src/drivers
        src/api)

add_executable(test_accelerometer test/test_accelerometer.cpp src/drivers/Accelerometer.cpp)
target_include_directories(test_accelerometer
        PRIVATE
        src/
        src/drivers
        src/api)