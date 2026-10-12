cmake_minimum_required(VERSION 3.22)

# SIMDE_ZIP_PATH must be passed to CMake
if(NOT DEFINED SIMDE_ZIP_PATH)
    message(FATAL_ERROR "SIMDE_ZIP_PATH must be defined")
endif()

project(simde-fetchcontent-zip-consumer LANGUAGES C CXX)

include(FetchContent)
FetchContent_Declare(simde URL ${SIMDE_ZIP_PATH})
FetchContent_MakeAvailable(simde)

add_executable(consumer-zip-c ../sources/main.c)
target_link_libraries(consumer-zip-c PRIVATE simde::simde)

add_executable(consumer-zip-cpp ../sources/main.cpp)
target_link_libraries(consumer-zip-cpp PRIVATE simde::simde)

enable_testing()
add_test(NAME consumer-zip-c COMMAND consumer-zip-c)
add_test(NAME consumer-zip-cpp COMMAND consumer-zip-cpp)
