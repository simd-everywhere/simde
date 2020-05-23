#if !defined(SIMDE_TEST_X86_TEST_AVX_H)
#define SIMDE_TEST_X86_TEST_AVX_H

#include "test-x86.h"
#include "test-sse2.h"
#include "../../simde/x86/avx.h"

SIMDE_TEST_X86_GENERATE_FLOAT_TYPE_FUNCS_(__m256, 32, 8)
SIMDE_TEST_X86_GENERATE_FLOAT_TYPE_FUNCS_(__m256d, 64, 4)
SIMDE_TEST_X86_GENERATE_INT_TYPE_FUNCS_(__m256i, 8, 32)
SIMDE_TEST_X86_GENERATE_INT_TYPE_FUNCS_(__m256i, 16, 16)
SIMDE_TEST_X86_GENERATE_INT_TYPE_FUNCS_(__m256i, 32, 8)
SIMDE_TEST_X86_GENERATE_INT_TYPE_FUNCS_(__m256i, 64, 4)
SIMDE_TEST_X86_GENERATE_UINT_TYPE_FUNCS_(__m256i, 8, 32)
SIMDE_TEST_X86_GENERATE_UINT_TYPE_FUNCS_(__m256i, 16, 16)
SIMDE_TEST_X86_GENERATE_UINT_TYPE_FUNCS_(__m256i, 32, 8)
SIMDE_TEST_X86_GENERATE_UINT_TYPE_FUNCS_(__m256i, 64, 4)

#define simde_test_x86_assert_equal_f32x8(a, b, precision) simde_test_x86_assert_equal_f32x8_(a, b, 1e-##precision##f, __FILE__, __LINE__, #a, #b)
#define simde_test_x86_assert_equal_f64x4(a, b, precision) simde_test_x86_assert_equal_f64x4_(a, b, 1e-##precision, __FILE__, __LINE__, #a, #b)
#define simde_test_x86_assert_equal_i8x32(a, b) simde_test_x86_assert_equal_i8x32_(a, b, __FILE__, __LINE__, #a, #b)
#define simde_test_x86_assert_equal_i16x16(a, b) simde_test_x86_assert_equal_i16x16_(a, b, __FILE__, __LINE__, #a, #b)
#define simde_test_x86_assert_equal_i32x8(a, b) simde_test_x86_assert_equal_i32x8_(a, b, __FILE__, __LINE__, #a, #b)
#define simde_test_x86_assert_equal_i64x4(a, b) simde_test_x86_assert_equal_i64x4_(a, b, __FILE__, __LINE__, #a, #b)
#define simde_test_x86_assert_equal_u8x32(a, b) simde_test_x86_assert_equal_u8x32_(a, b, __FILE__, __LINE__, #a, #b)
#define simde_test_x86_assert_equal_u16x16(a, b) simde_test_x86_assert_equal_u16x16_(a, b, __FILE__, __LINE__, #a, #b)
#define simde_test_x86_assert_equal_u32x8(a, b) simde_test_x86_assert_equal_u32x8_(a, b, __FILE__, __LINE__, #a, #b)
#define simde_test_x86_assert_equal_u64x4(a, b) simde_test_x86_assert_equal_u64x4_(a, b, __FILE__, __LINE__, #a, #b)

#endif /* !defined(SIMDE_TEST_X86_TEST_AVX_H) */
