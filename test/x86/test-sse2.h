#if !defined(SIMDE_TEST_X86_TEST_SSE2_H)
#define SIMDE_TEST_X86_TEST_SSE2_H

#include "test-x86.h"
#include "test-sse.h"
#include "../../simde/x86/sse2.h"

HEDLEY_DIAGNOSTIC_PUSH
SIMDE_DISABLE_UNWANTED_DIAGNOSTICS

SIMDE_TEST_X86_GENERATE_FLOAT_TYPE_FUNCS_(__m128d, 64, 2, simde_mm_storeu_pd)
SIMDE_TEST_X86_GENERATE_INT_TYPE_FUNCS_(__m128i, 8, 16, simde_mm_storeu_si128)
SIMDE_TEST_X86_GENERATE_INT_TYPE_FUNCS_(__m128i, 16, 8, simde_mm_storeu_si128)
SIMDE_TEST_X86_GENERATE_INT_TYPE_FUNCS_(__m128i, 32, 4, simde_mm_storeu_si128)
SIMDE_TEST_X86_GENERATE_INT_TYPE_FUNCS_(__m128i, 64, 2, simde_mm_storeu_si128)
SIMDE_TEST_X86_GENERATE_UINT_TYPE_FUNCS_(__m128i, 8, 16, simde_mm_storeu_si128)
SIMDE_TEST_X86_GENERATE_UINT_TYPE_FUNCS_(__m128i, 16, 8, simde_mm_storeu_si128)
SIMDE_TEST_X86_GENERATE_UINT_TYPE_FUNCS_(__m128i, 32, 4, simde_mm_storeu_si128)
SIMDE_TEST_X86_GENERATE_UINT_TYPE_FUNCS_(__m128i, 64, 2, simde_mm_storeu_si128)

#define simde_test_x86_assert_equal_f64x2(a, b, precision) do { if (simde_test_x86_assert_equal_f64x2_(a, b, simde_test_f64_precision_to_slop(precision), __FILE__, __LINE__, #a, #b)) { return 1; } } while (0)
#define simde_test_x86_assert_equal_i8x16(a, b) do { if (simde_test_x86_assert_equal_i8x16_(a, b, __FILE__, __LINE__, #a, #b)) { return 1; } } while (0)
#define simde_test_x86_assert_equal_i16x8(a, b) do { if (simde_test_x86_assert_equal_i16x8_(a, b, __FILE__, __LINE__, #a, #b)) { return 1; } } while (0)
#define simde_test_x86_assert_equal_i32x4(a, b) do { if (simde_test_x86_assert_equal_i32x4_(a, b, __FILE__, __LINE__, #a, #b)) { return 1; } } while (0)
#define simde_test_x86_assert_equal_i64x2(a, b) do { if (simde_test_x86_assert_equal_i64x2_(a, b, __FILE__, __LINE__, #a, #b)) { return 1; } } while (0)
#define simde_test_x86_assert_equal_u8x16(a, b) do { if (simde_test_x86_assert_equal_u8x16_(a, b, __FILE__, __LINE__, #a, #b)) { return 1; } } while (0)
#define simde_test_x86_assert_equal_u16x8(a, b) do { if (simde_test_x86_assert_equal_u16x8_(a, b, __FILE__, __LINE__, #a, #b)) { return 1; } } while (0)
#define simde_test_x86_assert_equal_u32x4(a, b) do { if (simde_test_x86_assert_equal_u32x4_(a, b, __FILE__, __LINE__, #a, #b)) { return 1; } } while (0)
#define simde_test_x86_assert_equal_u64x2(a, b) do { if (simde_test_x86_assert_equal_u64x2_(a, b, __FILE__, __LINE__, #a, #b)) { return 1; } } while (0)

HEDLEY_DIAGNOSTIC_POP

#endif /* !defined(SIMDE_TEST_X86_TEST_SSE2_H) */
