#if !defined(SIMDE_TEST_WASM_SIMD128_TEST_SIMD128_H)
#define SIMDE_TEST_WASM_SIMD128_TEST_SIMD128_H

#include "../test-simd128.h"

#if !defined(SIMDE_TEST_BARE)
  #define SIMDE_TEST_DECLARE_SUITE(name) SIMDE_TEST_SUITE_DECLARE_GETTERS(HEDLEY_CONCAT(simde_test_wasm_relaxed_simd_get_suite_,name))
  #include <test/wasm/relaxed-simd/declare-suites.h>
  #undef SIMDE_TEST_DECLARE_SUITE
#endif

#endif /* !defined(SIMDE_TEST_WASM_SIMD128_TEST_SIMD128_H) */
