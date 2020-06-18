#if !defined(SIMDE_TEST_X86_TEST_AVX512_H)
#define SIMDE_TEST_X86_TEST_AVX512_H

#include "test-x86.h"
#include "test-avx.h"
#include "../../simde/x86/avx512f.h"

SIMDE_TEST_X86_GENERATE_FLOAT_TYPE_FUNCS_(__m512, 32, 16, simde_mm512_storeu_ps)
SIMDE_TEST_X86_GENERATE_FLOAT_TYPE_FUNCS_(__m512d, 64, 8, simde_mm512_storeu_pd)
SIMDE_TEST_X86_GENERATE_INT_TYPE_FUNCS_(__m512i, 8, 64, simde_mm512_storeu_si512)
SIMDE_TEST_X86_GENERATE_INT_TYPE_FUNCS_(__m512i, 16, 32, simde_mm512_storeu_si512)
SIMDE_TEST_X86_GENERATE_INT_TYPE_FUNCS_(__m512i, 32, 16, simde_mm512_storeu_si512)
SIMDE_TEST_X86_GENERATE_INT_TYPE_FUNCS_(__m512i, 64, 8, simde_mm512_storeu_si512)
SIMDE_TEST_X86_GENERATE_UINT_TYPE_FUNCS_(__m512i, 8, 64, simde_mm512_storeu_si512)
SIMDE_TEST_X86_GENERATE_UINT_TYPE_FUNCS_(__m512i, 16, 32, simde_mm512_storeu_si512)
SIMDE_TEST_X86_GENERATE_UINT_TYPE_FUNCS_(__m512i, 32, 16, simde_mm512_storeu_si512)
SIMDE_TEST_X86_GENERATE_UINT_TYPE_FUNCS_(__m512i, 64, 8, simde_mm512_storeu_si512)

#define SIMDE_TEST_X86_GENERATE_MASK_FUNCS_(EL) \
  static simde__mmask##EL \
  simde_test_x86_random_mmask##EL(void) { \
    return HEDLEY_STATIC_CAST(simde__mmask##EL, simde_test_codegen_random_u##EL()); \
  } \
 \
  static void \
  simde_test_x86_write_mmask##EL(int indent, simde__mmask16 value, SimdeTestVecPos pos) { \
    simde_test_codegen_write_u##EL(indent, HEDLEY_STATIC_CAST(uint##EL##_t, value), pos); \
  }

SIMDE_TEST_X86_GENERATE_MASK_FUNCS_(8)
SIMDE_TEST_X86_GENERATE_MASK_FUNCS_(16)
SIMDE_TEST_X86_GENERATE_MASK_FUNCS_(32)
SIMDE_TEST_X86_GENERATE_MASK_FUNCS_(64)

#define simde_test_x86_assert_equal_f32x16(a, b, precision) do { if (simde_test_x86_assert_equal_f32x16_(a, b, 1e-##precision##f, __FILE__, __LINE__, #a, #b)) { return 1; } } while (0)
#define simde_test_x86_assert_equal_f64x8(a, b, precision) do { if (simde_test_x86_assert_equal_f64x8_(a, b, 1e-##precision, __FILE__, __LINE__, #a, #b)) { return 1; } } while (0)
#define simde_test_x86_assert_equal_i8x64(a, b) do { if (simde_test_x86_assert_equal_i8x64_(a, b, __FILE__, __LINE__, #a, #b)) { return 1; } } while (0)
#define simde_test_x86_assert_equal_i16x32(a, b) do { if (simde_test_x86_assert_equal_i16x32_(a, b, __FILE__, __LINE__, #a, #b)) { return 1; } } while (0)
#define simde_test_x86_assert_equal_i32x16(a, b) do { if (simde_test_x86_assert_equal_i32x16_(a, b, __FILE__, __LINE__, #a, #b)) { return 1; } } while (0)
#define simde_test_x86_assert_equal_i64x8(a, b) do { if (simde_test_x86_assert_equal_i64x8_(a, b, __FILE__, __LINE__, #a, #b)) { return 1; } } while (0)
#define simde_test_x86_assert_equal_u8x64(a, b) do { if (simde_test_x86_assert_equal_u8x64_(a, b, __FILE__, __LINE__, #a, #b)) { return 1; } } while (0)
#define simde_test_x86_assert_equal_u16x32(a, b) do { if (simde_test_x86_assert_equal_u16x32_(a, b, __FILE__, __LINE__, #a, #b)) { return 1; } } while (0)
#define simde_test_x86_assert_equal_u32x16(a, b) do { if (simde_test_x86_assert_equal_u32x16_(a, b, __FILE__, __LINE__, #a, #b)) { return 1; } } while (0)
#define simde_test_x86_assert_equal_u64x8(a, b) do { if (simde_test_x86_assert_equal_u64x8_(a, b, __FILE__, __LINE__, #a, #b)) { return 1; } } while (0)

#endif /* !defined(SIMDE_TEST_X86_TEST_AVX512_H) */
