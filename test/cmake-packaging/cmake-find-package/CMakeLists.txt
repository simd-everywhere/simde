cmake_minimum_required(VERSION 3.22)
project(simde-consumer LANGUAGES C CXX)

find_package(simde CONFIG REQUIRED)
message(STATUS "simde version: ${simde_VERSION}")

add_executable(consumer-c main.c)
target_link_libraries(consumer-c PRIVATE simde::simde)

add_executable(consumer-cpp main.cpp)
target_link_libraries(consumer-cpp PRIVATE simde::simde)

enable_testing()
add_test(NAME consumer-c COMMAND consumer-c)
add_test(NAME consumer-cpp COMMAND consumer-cpp)
