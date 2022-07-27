cmake_minimum_required(VERSION 3.1)

set(project_name DeliveryBot)

project(${project_name})

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_BUILD_TYPE RelWithDebInfo)
set(CXXFLAGS " -lCppLinuxSerial")

add_compile_options(-lCppLinuxSerial)

add_library(${project_name}-lib
        src/drivers/Accelerometer.cpp
        src/drivers/Accelerometer.h
        src/api/controller/CamAPIController.hpp
        src/api/controller/CamAPIController.cpp
        src/api/controller/MotorController.hpp
        src/api/dto/DTOs.hpp
        src/api/video_stream_backend/ImageWSListener.cpp
        src/api/video_stream_backend/ImageWSListener.hpp
        src/api/video_stream_backend/Utils.cpp
        src/api/video_stream_backend/Utils.hpp
        src/api/video_stream_backend/V4LGrabber.cpp
        src/api/video_stream_backend/V4LGrabber.hpp
        )

## link libs
find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})
find_package(oatpp 1.3.0 REQUIRED)
find_package(oatpp-websocket 1.3.0 REQUIRED)
find_library(LinuxSerial libCppLinuxSerial /usr/local/lib)

target_link_libraries(${project_name}-lib
        PUBLIC oatpp::oatpp-websocket
        PUBLIC oatpp::oatpp
        PUBLIC oatpp::oatpp-test
        ${LinuxSerial}
        ${OpenCV_LIBS}
        )

target_include_directories(${project_name}-lib PUBLIC src)

## add executables

add_executable(${project_name}-exe
        src/main.cpp
        )
target_link_libraries(${project_name}-exe ${project_name}-lib)
add_dependencies(${project_name}-exe ${project_name}-lib)

add_executable(${project_name}-accelerometer-test
        test/test_accelerometer.cpp
        )
target_link_libraries(${project_name}-accelerometer-test ${project_name}-lib)
add_dependencies(${project_name}-accelerometer-test ${project_name}-lib)

set_target_properties(${project_name}-lib ${project_name}-exe PROPERTIES
        CXX_STANDARD 11
        CXX_EXTENSIONS OFF
        CXX_STANDARD_REQUIRED ON
        )

enable_testing()
add_test(project-tests ${project_name}-test)