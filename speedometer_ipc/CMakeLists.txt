cmake_minimum_required(VERSION 3.14)

project(speedometer_ipc LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(speedometer_ipc STATIC
  ipc_writer.cpp
  ipc_writer.h
  ipc_reader.cpp
  ipc_reader.h
  ipc_settings.h
)

target_compile_definitions(speedometer_ipc PRIVATE SPEEDOMETER_IPC_LIBRARY)
