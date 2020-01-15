cmake_minimum_required(VERSION 3.0)

project(simde-tests)

set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake)
include (ExtraWarningFlags)

enable_testing()

if(NOT EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/munit/munit.c")
  find_program(GIT git)
  if(GIT)
    execute_process(COMMAND ${GIT} submodule update --init --recursive)
  else()
    message (FATAL_ERROR "It looks like you don't have submodules checked out.  Please run `git submodule update --init --recursive'")
  endif()
endif()

if(CMAKE_BUILD_TYPE STREQUAL "")
  set(CMAKE_BUILD_TYPE "Debug")
elseif(CMAKE_BUILD_TYPE STREQUAL "Coverage")
  set(orig_req_libs "${CMAKE_REQUIRED_LIBRARIES}")
  set(CMAKE_REQUIRED_LIBRARIES "${CMAKE_REQUIRED_LIBRARIES};--coverage")
  check_c_compiler_flag("--coverage" CFLAG___coverage)
  set(CMAKE_REQUIRED_LIBRARIES "${orig_req_libs}")

  if(CFLAG___coverage)
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} --coverage")
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_C_FLAGS} --coverage")
    add_definitions("-DSIMDE_NO_INLINE")
  else()
    set(CMAKE_BUILD_TYPE "Debug")
  endif()
endif()

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

check_function_exists(fegetround FEGETROUND_EXISTS)
if(NOT FEGETROUND_EXISTS)
  unset(FEGETROUND_EXISTS CACHE)
  list(APPEND CMAKE_REQUIRED_LIBRARIES m)
  check_function_exists(fegetround FEGETROUND_EXISTS)
  if(FEGETROUND_EXISTS)
    set(NEED_LIBM True)
  else()
    message(FATAL_ERROR "Unable to find fegetround")
  endif()
endif(NOT FEGETROUND_EXISTS)

set_property(TARGET munit PROPERTY C_STANDARD "99")
if("${CLOCK_GETTIME_EXISTS}")
  target_compile_definitions(munit PRIVATE "MUNIT_ALLOW_CLOCK_GETTIME")
  target_link_libraries(munit "${CLOCK_GETTIME_LIBRARY}")
endif()

include_directories("${CMAKE_SOURCE_DIR}/..")

set(TEST_SOURCES)

if(NOT DISABLE_X86)
  set(TEST_SOURCES
    x86/mmx.c
    x86/sse.c
    x86/sse2.c
    x86/sse3.c
    x86/ssse3.c
    x86/sse4.1.c
    x86/sse4.2.c
    x86/avx.c
    x86/avx2.c
    x86/fma.c)
else()
  add_definitions(-DDISABLE_X86)
endif()

list(APPEND TEST_SOURCES
  simd-js/int32x4.c
  simd-js/int32x4-compare.c
  simd-js/float32x4.c)

list(APPEND TEST_SOURCES
  arm/neon/vadd.c
  arm/neon/vdup_n.c
  arm/neon/vmul.c
  arm/neon/vsub.c)

add_library(simde-test-no-native STATIC ${TEST_SOURCES})
target_compile_definitions(simde-test-no-native PRIVATE SIMDE_NO_NATIVE)
set_property(TARGET simde-test-no-native PROPERTY C_STANDARD "99")

add_library(simde-test-native STATIC ${TEST_SOURCES})
set_property(TARGET simde-test-native PROPERTY C_STANDARD "99")

set_compiler_specific_flags(
  VARIABLE extra_cflags
  INTEL -wd3179)

check_c_compiler_flag("-fopenmp-simd" CFLAG__fopenmp_simd)
check_c_compiler_flag("-qopenmp-simd" CFLAG__qopenmp_simd)
if(CFLAG__fopenmp_simd)
  set(extra_cflags "${extra_cflags} -fopenmp-simd -DSIMDE_ENABLE_OPENMP")
elseif(CFLAG__qopenmp_simd)
  set(extra_cflags "${extra_cflags} -qopenmp-simd -DSIMDE_ENABLE_OPENMP")
endif()

check_c_compiler_flag("-mfpu=neon -Werror" CFLAG__mfpu_neon)
if(CFLAG__mfpu_neon)
  set(extra_cflags "${extra_cflags} -mfpu=neon")
endif()

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${extra_cflags}")

add_executable(run-tests test.c test-common.c)
target_link_libraries(run-tests munit simde-test-no-native simde-test-native)

if(NEED_LIBM)
  target_link_libraries(run-tests m)
endif()
if (NOT DISABLE_X86)
  foreach(tst "/x86/mmx" "/x86/sse" "/x86/sse2" "/x86/sse3" "/x86/ssse3" "/x86/sse4.1" "/x86/sse4.2" "/x86/avx" "/x86/avx2")
    add_test(NAME "${tst}/${variant}" COMMAND ${CMAKE_CROSSCOMPILING_EMULATOR} $<TARGET_FILE:run-tests> "${tst}")
  endforeach()
endif()
add_test(NAME "/simd-js" COMMAND ${CMAKE_CROSSCOMPILING_EMULATOR} $<TARGET_FILE:run-tests> "/simd-js")
target_add_extra_warning_flags(run-tests)
set_property (TARGET run-tests PROPERTY C_STANDARD "99")
if("${CMAKE_C_COMPILER}" MATCHES "arm-linux-gnueabihf-gcc")
  target_link_libraries(run-tests -static)
elseif("${CMAKE_C_COMPILER}" MATCHES "aarch64-linux-gnu-gcc")
  target_link_libraries(run-tests -static)
endif()
