cmake_minimum_required(VERSION 3.5)
project(JPS)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")
include_directories(include)

find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})
message(STATUS "OpenCV include dirs: ${OpenCV_INCLUDE_DIRS}")

add_executable(jps src/main.cc 
                    src/jps.cc
                    src/map.cc)
target_link_libraries(jps ${OpenCV_LIBS})
message(STATUS "OpenCV include LIB: ${OpenCV_LIBS}")