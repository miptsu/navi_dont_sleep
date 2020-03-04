cmake_minimum_required(VERSION 3.15)
project(navi_dont_sleep)

set(CMAKE_CXX_STANDARD 20)

find_package(OpenCV REQUIRED)
include_directories( ${OpenCV_INCLUDE_DIRS} )

add_executable(navi_dont_sleep main.cpp)

target_link_libraries(navi_dont_sleep ${OpenCV_LIBS})

