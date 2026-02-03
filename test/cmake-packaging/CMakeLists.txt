add_test(
    NAME simde-cmake-install
    COMMAND ${CMAKE_CTEST_COMMAND}
        --build-and-test "${PROJECT_SOURCE_DIR}"
                         "${CMAKE_CURRENT_BINARY_DIR}/build"
        --build-generator ${CMAKE_GENERATOR}
        --build-target install
        --build-options "-DCMAKE_INSTALL_PREFIX=${CMAKE_CURRENT_BINARY_DIR}/install"
)

add_test(
    NAME simde-cmake-find-package
    COMMAND ${CMAKE_CTEST_COMMAND}
    --build-and-test "${CMAKE_CURRENT_SOURCE_DIR}/cmake-find-package"
                     "${CMAKE_CURRENT_BINARY_DIR}/cmake-find-package/build"
    --build-generator "${CMAKE_GENERATOR}"
    --build-options "-DCMAKE_PREFIX_PATH=${CMAKE_CURRENT_BINARY_DIR}/install"
)
set_tests_properties(simde-cmake-find-package PROPERTIES DEPENDS simde-cmake-install)

add_test(
    NAME simde-cmake-fetchcontent
    COMMAND ${CMAKE_CTEST_COMMAND}
    --build-and-test "${CMAKE_CURRENT_SOURCE_DIR}/cmake-fetchcontent"
                     "${CMAKE_CURRENT_BINARY_DIR}/cmake-fetchcontent/build"
    --build-generator "${CMAKE_GENERATOR}"
)

# Generate the zip file for testing
find_package(Python REQUIRED COMPONENTS Interpreter)
set(SIMDE_ZIP_PATH ${CMAKE_CURRENT_BINARY_DIR}/simde-v0.0.1-dev.zip)

add_test(
    NAME simde-generate-zip
    COMMAND $<TARGET_FILE:Python::Interpreter> ${CMAKE_CURRENT_SOURCE_DIR}/../../package_simde.py --output ${SIMDE_ZIP_PATH} --source ${CMAKE_CURRENT_SOURCE_DIR}/../../simde --overwrite
)

# This test requires SIMDE_ZIP_PATH to be set in the build environment
add_test(
    NAME simde-cmake-fetchcontent-zip
    COMMAND ${CMAKE_CTEST_COMMAND}
    --build-and-test "${CMAKE_CURRENT_SOURCE_DIR}/cmake-fetchcontent-zip"
                     "${CMAKE_CURRENT_BINARY_DIR}/cmake-fetchcontent-zip/build"
    --build-generator "${CMAKE_GENERATOR}"
    --build-options "-DSIMDE_ZIP_PATH=${SIMDE_ZIP_PATH}"
)
set_tests_properties(simde-cmake-fetchcontent-zip PROPERTIES DEPENDS simde-generate-zip)
