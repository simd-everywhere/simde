#if !defined(SIMDE_TEST_H)
#define SIMDE_TEST_H

#if defined(TEST_NATIVE)
#  define SIMDE__MMX_NATIVE
#  define SIMDE__SSE_NATIVE
#  define SIMDE__SSE2_NATIVE

#  if defined(__GNUC__) && !defined(__clang__) && !defined(__INTEL_COMPILER)
#    pragma GCC target("sse4.1")
#  endif
#endif

#include <stdio.h>
#include <limits.h>

#include "munit/munit.h"

const MunitSuite simde_mmx_test_suite;
const MunitSuite simde_sse_test_suite;
const MunitSuite simde_sse2_test_suite;

#endif /* !defined(SIMDE_TEST_H) */
