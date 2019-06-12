cmake_minimum_required(VERSION 3.8 FATAL_ERROR)

project(xyzrgbToPCD VERSION 0.0 LANGUAGES C CXX)

find_package(PCL 1.8 REQUIRED)

add_executable(xyzrgbToPCD main.cpp)

target_include_directories(xyzrgbToPCD PUBLIC include)

target_include_directories(xyzrgbToPCD PUBLIC ${PCL_INCLUDE_DIRS})
target_link_libraries(xyzrgbToPCD  LINK_PUBLIC ${PCL_LIBRARIES})
