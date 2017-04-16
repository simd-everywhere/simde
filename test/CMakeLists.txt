cmake_minimum_required(VERSION 3.0)

project(portable-snippet-tests)

set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake)
include (ExtraWarningFlags)

enable_testing()

if(CMAKE_BUILD_TYPE STREQUAL "")
  set(CMAKE_BUILD_TYPE "Debug")
endif()

if (NOT EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/munit/munit.c")
  message (FATAL_ERROR "It looks like you don't have submodules checked out.  Please run `git submodule update --init --recursive'")
endif ()

add_library(munit STATIC munit/munit.c)

include(CheckFunctionExists)
check_function_exists(clock_gettime CLOCK_GETTIME_RES)
if(CLOCK_GETTIME_RES)
  set(CLOCK_GETTIME_EXISTS yes)
else()
  set(orig_req_libs "${CMAKE_REQUIRED_LIBRARIES}")
  set(CMAKE_REQUIRED_LIBRARIES "${CMAKE_REQUIRED_LIBRARIES};rt")

  check_function_exists(clock_gettime CLOCK_GETTIME_LIBRT_RES)
  if(CLOCK_GETTIME_LIBRT_RES)
    set(CLOCK_GETTIME_EXISTS yes)
    set(CLOCK_GETTIME_LIBRARY "rt")
  endif()

  set(CMAKE_REQUIRED_LIBRARIES "${orig_req_libs}")
  unset(orig_req_libs)
endif()

set_property(TARGET munit PROPERTY C_STANDARD "99")
if("${CLOCK_GETTIME_EXISTS}")
  target_compile_definitions(munit PRIVATE "MUNIT_ALLOW_CLOCK_GETTIME")
  target_link_libraries(munit "${CLOCK_GETTIME_LIBRARY}")
endif()

set(TEST_SOURCES
  test.c
  test-mmx.c
  test-sse.c
  test-sse2.c)

set_compiler_specific_flags(
  VARIABLE extra_cflags
  INTEL -wd3179
  GCCISH -march=native)

foreach(variant native emul)
  add_executable(test-${variant} ${TEST_SOURCES})
  target_link_libraries(test-${variant} munit m)
  foreach(tst "/mmx" "/sse")
    add_test(NAME "/${variant}${tst}" COMMAND $<TARGET_FILE:test-${variant}> "/${variant}${tst}")
  endforeach()
  target_add_extra_warning_flags(test-${variant})
  set_property (TARGET test-${variant} PROPERTY C_STANDARD "99")
  target_add_compiler_flags(test-${variant} ${extra_cflags})
endforeach()

target_compile_definitions(test-native PRIVATE -DTEST_NATIVE)
