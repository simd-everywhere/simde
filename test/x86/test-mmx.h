#if !defined(SIMDE_TEST_X86_TEST_MMX_H)
#define SIMDE_TEST_X86_TEST_MMX_H

#include "test-x86.h"
#include "../../simde/x86/mmx.h"

HEDLEY_DIAGNOSTIC_PUSH
SIMDE_DISABLE_UNWANTED_DIAGNOSTICS

SIMDE_TEST_X86_GENERATE_FLOAT_TYPE_FUNCS_(__m64, 32, 2, simde_x_mm_storeu_si64)
SIMDE_TEST_X86_GENERATE_FLOAT_TYPE_FUNCS_(__m64, 64, 1, simde_x_mm_storeu_si64)
SIMDE_TEST_X86_GENERATE_INT_TYPE_FUNCS_(__m64, 8, 8, simde_x_mm_storeu_si64)
SIMDE_TEST_X86_GENERATE_INT_TYPE_FUNCS_(__m64, 16, 4, simde_x_mm_storeu_si64)
SIMDE_TEST_X86_GENERATE_INT_TYPE_FUNCS_(__m64, 32, 2, simde_x_mm_storeu_si64)
SIMDE_TEST_X86_GENERATE_INT_TYPE_FUNCS_(__m64, 64, 1, simde_x_mm_storeu_si64)
SIMDE_TEST_X86_GENERATE_UINT_TYPE_FUNCS_(__m64, 8, 8, simde_x_mm_storeu_si64)
SIMDE_TEST_X86_GENERATE_UINT_TYPE_FUNCS_(__m64, 16, 4, simde_x_mm_storeu_si64)
SIMDE_TEST_X86_GENERATE_UINT_TYPE_FUNCS_(__m64, 32, 2, simde_x_mm_storeu_si64)
SIMDE_TEST_X86_GENERATE_UINT_TYPE_FUNCS_(__m64, 64, 1, simde_x_mm_storeu_si64)

#define simde_test_x86_assert_equal_f32x2(a, b, precision) do { if (simde_test_x86_assert_equal_f32x2_(a, b, simde_test_f32_precision_to_slop(precision), __FILE__, __LINE__, #a, #b)) { return 1; } } while (0)
#define simde_test_x86_assert_equal_f64x1(a, b, precision) do { if (simde_test_x86_assert_equal_f64x1_(a, b, simde_test_f64_precision_to_slop(precision), __FILE__, __LINE__, #a, #b)) { return 1; } } while (0)
#define simde_test_x86_assert_equal_i8x8(a, b) do { if (simde_test_x86_assert_equal_i8x8_(a, b, __FILE__, __LINE__, #a, #b)) { return 1; } } while (0)
#define simde_test_x86_assert_equal_i16x4(a, b) do { if (simde_test_x86_assert_equal_i16x4_(a, b, __FILE__, __LINE__, #a, #b)) { return 1; } } while (0)
#define simde_test_x86_assert_equal_i32x2(a, b) do { if (simde_test_x86_assert_equal_i32x2_(a, b, __FILE__, __LINE__, #a, #b)) { return 1; } } while (0)
#define simde_test_x86_assert_equal_i64x1(a, b) do { if (simde_test_x86_assert_equal_i64x1_(a, b, __FILE__, __LINE__, #a, #b)) { return 1; } } while (0)
#define simde_test_x86_assert_equal_u8x8(a, b) do { if (simde_test_x86_assert_equal_u8x8_(a, b, __FILE__, __LINE__, #a, #b)) { return 1; } } while (0)
#define simde_test_x86_assert_equal_u16x4(a, b) do { if (simde_test_x86_assert_equal_u16x4_(a, b, __FILE__, __LINE__, #a, #b)) { return 1; } } while (0)
#define simde_test_x86_assert_equal_u32x2(a, b) do { if (simde_test_x86_assert_equal_u32x2_(a, b, __FILE__, __LINE__, #a, #b)) { return 1; } } while (0)
#define simde_test_x86_assert_equal_u64x1(a, b) do { if (simde_test_x86_assert_equal_u64x1_(a, b, __FILE__, __LINE__, #a, #b)) { return 1; } } while (0)

/* SIMDE_DISABLE_UNWANTED_DIAGNOSTICS */
HEDLEY_DIAGNOSTIC_POP

#endif /* !defined(SIMDE_TEST_X86_TEST_MMX_H) */
