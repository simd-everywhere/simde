cmake_minimum_required(VERSION 3.0)

project(simde-tests)

set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake)
include (ExtraWarningFlags)

enable_testing()

option(BUILD_CPP_TESTS "Build C++ tests" ON)
option(ALWAYS_BUILD_NATIVE_TESTS "Build 'native' tests even if the native instructions aren't available" OFF)

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

if("${OPENMP_SIMD_FLAGS}" STREQUAL "")
  foreach(omp_simd_flag "-fopenmp-simd" "-qopenmp-simd")
    string (REGEX REPLACE "[^a-zA-Z0-9]+" "_" omp_simd_flag_name "CFLAG_${omp_simd_flag}")
    check_c_compiler_flag("${omp_simd_flag}" "${omp_simd_flag_name}")

    if(${omp_simd_flag_name})
      set(OPENMP_SIMD_FLAGS "-DSIMDE_ENABLE_OPENMP ${omp_simd_flag}")
      break()
    endif()
  endforeach()
endif()

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${OPENMP_SIMD_FLAGS}")

set(TEST_SOURCES_C
  x86/mmx.c
  x86/sse.c
  x86/sse2.c
  x86/sse3.c
  x86/ssse3.c
  x86/sse4.1.c
  x86/sse4.2.c
  x86/avx.c
  x86/avx2.c
  x86/avx512f.c
  x86/avx512bw.c
  x86/avx512vl.c
  x86/fma.c
  x86/svml.c

  arm/neon/vadd.c
  arm/neon/vdup_n.c
  arm/neon/vmul.c
  arm/neon/vsub.c)

set(TEST_RUNNER_SOURCES
  run-tests.c
  x86/test-x86.c
  arm/neon/test-neon.c
  arm/test-arm.c)
add_executable(run-tests ${TEST_RUNNER_SOURCES})
set_property(TARGET run-tests PROPERTY C_STANDARD "99")
target_link_libraries(run-tests munit)
target_add_compiler_flags (munit "-w")
if(NEED_LIBM)
  target_link_libraries(run-tests m)
endif(NEED_LIBM)

set(TEST_SOURCES_CPP)
if(BUILD_CPP_TESTS)
  foreach(csource ${TEST_SOURCES_C})
    configure_file("${csource}" "${CMAKE_CURRENT_BINARY_DIR}/${csource}pp")
    list(APPEND TEST_SOURCES_CPP "${CMAKE_CURRENT_BINARY_DIR}/${csource}pp")
  endforeach()

  add_definitions(-DSIMDE_BUILD_CPP_TESTS)
endif(BUILD_CPP_TESTS)

foreach(native native emul)
  add_library(simde-test-${native} STATIC ${TEST_SOURCES_C} ${TEST_SOURCES_CPP})

  target_include_directories(simde-test-${native} PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/..")
  set_property(TARGET simde-test-${native} PROPERTY C_STANDARD "99")

  if(ALWAYS_BUILD_NATIVE_TESTS)
    target_compile_definitions(simde-test-${native} PRIVATE SIMDE_ALWAYS_BUILD_NATIVE_TESTS)
  endif(ALWAYS_BUILD_NATIVE_TESTS)

  target_link_libraries(run-tests simde-test-${native})
endforeach(native native emul)
target_compile_definitions(simde-test-emul PRIVATE SIMDE_NO_NATIVE)

foreach(tst
      "/x86/mmx"
      "/x86/sse"
      "/x86/sse2"
      "/x86/sse3"
      "/x86/ssse3"
      "/x86/sse4.1"
      "/x86/sse4.2"
      "/x86/avx"
      "/x86/fma"
      "/x86/avx2"
      "/x86/avx512f"
      "/x86/avx512bw"
      "/x86/avx512vl"
      "/x86/svml"
    )
  add_test(NAME "${tst}/${variant}" COMMAND ${CMAKE_CROSSCOMPILING_EMULATOR} $<TARGET_FILE:run-tests> "${tst}")
endforeach()
