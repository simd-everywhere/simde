#if !defined(SIMDE__JS_INTERNAL_H)
#define SIMDE__JS_INTERNAL_H

#include "../test.h"

MunitSuite simde_simd_js_test_suite;
MunitSuite simde_simd_js_emul_test_suite;
MunitSuite simde_simd_js_cmp_test_suite;

#define simde_assert_int32x4(a, op, b) \
  simde_assert_int32v(4, (int32_t*) &(a), op, (int32_t*) &(b))

#endif
