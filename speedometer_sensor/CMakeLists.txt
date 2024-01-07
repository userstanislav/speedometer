cmake_minimum_required(VERSION 3.5)

project(speedometer_sensor LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(speedometer_sensor
    main.cpp
    speedometer_sensor.cpp
    speedometer_sensor.h
)

# Link with speedometer_ipc library
target_link_libraries(speedometer_sensor PRIVATE speedometer_ipc)

# Include directories
target_include_directories(speedometer_sensor PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
target_include_directories(speedometer_sensor PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../speedometer_ipc)
