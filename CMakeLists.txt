cmake_minimum_required(VERSION 3.9)
project(BoundaryTracing)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

add_executable(
        BoundaryTracing main.cpp
        boundary_tracing.cpp
)

# linking
target_link_libraries(BoundaryTracing ${OpenCV_LIBS})