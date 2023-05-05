#if !defined(SIMDE_TEST_X86_TEST_SSE_H)
#define SIMDE_TEST_X86_TEST_SSE_H

#include "test-x86.h"
#include "test-mmx.h"
#include "../../simde/x86/sse.h"

HEDLEY_DIAGNOSTIC_PUSH
SIMDE_DISABLE_UNWANTED_DIAGNOSTICS

SIMDE_TEST_X86_GENERATE_FLOAT_TYPE_FUNCS_(__m128, 32, 4, simde_mm_storeu_ps)

#define simde_test_x86_assert_equal_f32x4(a, b, precision) do { if (simde_test_x86_assert_equal_f32x4_(a, b, simde_test_f32_precision_to_slop(precision), __FILE__, __LINE__, #a, #b)) { return 1; } } while (0)

HEDLEY_DIAGNOSTIC_POP

#endif /* !defined(SIMDE_TEST_X86_TEST_SSE_H) */
