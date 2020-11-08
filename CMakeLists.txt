cmake_minimum_required(VERSION 3.16)
project(AVS2)

set(CMAKE_CXX_STANDARD 17)

find_package (Threads)


add_executable(AVS2 main.cpp part2.cpp part2.h)
target_link_libraries (AVS2 ${CMAKE_THREAD_LIBS_INIT})