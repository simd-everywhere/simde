cmake_minimum_required(VERSION 3.22)

project(
    simde
    DESCRIPTION
        "Implementations of SIMD instruction sets for systems which don't natively support them."
    HOMEPAGE_URL "https://github.com/simd-everywhere/simde"
    LANGUAGES C CXX
    VERSION 0.8.4
)

# Options
option(SIMDE_TEST_CMAKE_PACKAGING "Test cmake packaging" ${PROJECT_IS_TOP_LEVEL})

# The main simde library
add_library(simde INTERFACE)
add_library(simde::simde ALIAS simde)

target_compile_features(simde INTERFACE c_std_99)

target_include_directories(
    simde
    INTERFACE
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
        $<INSTALL_INTERFACE:include>
)

if(SIMDE_TEST_CMAKE_PACKAGING)
    include(CTest)
    enable_testing()
    add_subdirectory(test/cmake-packaging)
endif()

include(GNUInstallDirs)

# Install headers
install(DIRECTORY simde DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

# Export targets
install(TARGETS simde EXPORT simde-targets)

# Package Configuration
include(CMakePackageConfigHelpers)

write_basic_package_version_file(
    ${CMAKE_CURRENT_BINARY_DIR}/simde-config-version.cmake
    VERSION ${PROJECT_VERSION}
    COMPATIBILITY SameMajorVersion
)

file(
    WRITE
    ${CMAKE_CURRENT_BINARY_DIR}/simde-config.cmake.in
    "@PACKAGE_INIT@\n"
    "include(\"\${CMAKE_CURRENT_LIST_DIR}/simde-config-targets.cmake\")\n"
)

configure_package_config_file(
    ${CMAKE_CURRENT_BINARY_DIR}/simde-config.cmake.in
    ${CMAKE_CURRENT_BINARY_DIR}/simde-config.cmake
    INSTALL_DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/simde
    NO_SET_AND_CHECK_MACRO
    NO_CHECK_REQUIRED_COMPONENTS_MACRO
)

install(
    FILES
        ${CMAKE_CURRENT_BINARY_DIR}/simde-config.cmake
        ${CMAKE_CURRENT_BINARY_DIR}/simde-config-version.cmake
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/simde
)

install(
    EXPORT simde-targets
    FILE simde-config-targets.cmake
    NAMESPACE simde::
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/simde
)
