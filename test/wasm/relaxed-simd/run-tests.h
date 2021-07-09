#if defined(SIMDE_TESTS_WASM_RELAXED_SIMD_RUN_TESTS_H)
  #error File already included.
#endif
#define SIMDE_TESTS_WASM_RELAXED_SIMD_RUN_TESTS_H

#include "../../munit/munit.h"

MunitSuite* simde_tests_wasm_relaxed_simd_get_suite(void);
