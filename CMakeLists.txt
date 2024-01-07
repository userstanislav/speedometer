cmake_minimum_required(VERSION 3.5)
project(speedometer_project)

# Include each subproject directory
add_subdirectory(speedometer_display)
add_subdirectory(speedometer_ipc)
add_subdirectory(speedometer_sensor)