add_test(
    NAME simde-cmake-install
    COMMAND ${CMAKE_CTEST_COMMAND}
        --build-and-test "${PROJECT_SOURCE_DIR}"
                         "${PROJECT_BINARY_DIR}/build"
        --build-generator ${CMAKE_GENERATOR}
        --build-target install
        --build-options "-DCMAKE_INSTALL_PREFIX=${PROJECT_BINARY_DIR}/install"
)

add_test(
    NAME simde-cmake-find-package
    COMMAND ${CMAKE_CTEST_COMMAND}
    --build-and-test "${CMAKE_CURRENT_SOURCE_DIR}/cmake-find-package"
                     "${PROJECT_BINARY_DIR}/cmake-find-package/build"
    --build-generator "${CMAKE_GENERATOR}"
    --build-options "-DCMAKE_PREFIX_PATH=${PROJECT_BINARY_DIR}/install"
)
set_tests_properties(simde-cmake-find-package PROPERTIES DEPENDS simde-cmake-install)

add_test(
    NAME simde-cmake-fetchcontent
    COMMAND ${CMAKE_CTEST_COMMAND}
    --build-and-test "${CMAKE_CURRENT_SOURCE_DIR}/cmake-fetchcontent"
                     "${PROJECT_BINARY_DIR}/cmake-fetchcontent/build"
    --build-generator "${CMAKE_GENERATOR}"
)
