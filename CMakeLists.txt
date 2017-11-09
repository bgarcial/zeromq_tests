cmake_minimum_required(VERSION 3.9)
project(zeroMQ_C___Client_Python_Server)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp client.cpp client_get-time-of-day.cpp)
add_executable(zeroMQ_C___Client_Python_Server ${SOURCE_FILES})