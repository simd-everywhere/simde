#if defined(SIMDE_TESTS_WASM_RUN_TESTS_H)
  #error File already included.
#endif
#define SIMDE_TESTS_WASM_RUN_TESTS_H

#include "../test.h"
#include "simd128/run-tests.h"
#include "relaxed-simd/run-tests.h"

MunitSuite* simde_tests_wasm_get_suite(void);
