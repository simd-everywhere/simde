#if defined(SIMDE_TESTS_WASM_SIMD128_RUN_TESTS_H)
  #error File already included.
#endif
#define SIMDE_TESTS_WASM_SIMD128_RUN_TESTS_H

#include "../../munit/munit.h"

MunitSuite* simde_tests_wasm_simd128_get_suite(void);
