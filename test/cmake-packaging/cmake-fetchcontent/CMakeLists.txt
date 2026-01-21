cmake_minimum_required(VERSION 3.22)
project(simde-fetchcontent-consumer LANGUAGES C CXX)

include(FetchContent)
FetchContent_Declare(simde SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../../../)
FetchContent_MakeAvailable(simde)

add_executable(consumer-fc-c main.c)
target_link_libraries(consumer-fc-c PRIVATE simde::simde)

add_executable(consumer-fc-cpp main.cpp)
target_link_libraries(consumer-fc-cpp PRIVATE simde::simde)

enable_testing()
add_test(NAME consumer-fc-c COMMAND consumer-fc-c)
add_test(NAME consumer-fc-cpp COMMAND consumer-fc-cpp)
