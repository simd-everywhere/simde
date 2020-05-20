#include "../../simde/x86/avx512f.h"

#include "test-avx.h"

#if !defined(SIMDE_TEST_X86_AVX512)
#define SIMDE_TEST_X86_AVX512

SIMDE_TEST_DEFINE_ASSERT_VEC_CLOSE(m512, f32)
SIMDE_TEST_DEFINE_ASSERT_VEC_CLOSE(m512d, f64)

#define simde_assert_m512_close(a, b, precision) \
  simde_assert_m512_f32_close_ex(__LINE__, __FILE__, a, b, precision)
#define simde_assert_m512d_close(a, b, precision) \
  simde_assert_m512d_f64_close_ex(__LINE__, __FILE__, a, b, precision)

#define simde_assert_mmask8(a, op, b) \
  munit_assert_uint8(HEDLEY_STATIC_CAST(uint8_t, a), op, HEDLEY_STATIC_CAST(uint8_t, b))
#define simde_assert_mmask16(a, op, b) \
  munit_assert_uint16(HEDLEY_STATIC_CAST(uint16_t, a), op, HEDLEY_STATIC_CAST(uint16_t, b))
#define simde_assert_mmask32(a, op, b) \
  munit_assert_uint32(HEDLEY_STATIC_CAST(uint32_t, a), op, HEDLEY_STATIC_CAST(uint32_t, b))
#define simde_assert_mmask64(a, op, b) \
  munit_assert_uint64(HEDLEY_STATIC_CAST(uint64_t, a), op, HEDLEY_STATIC_CAST(uint64_t, b))

#endif /* !defined(SIMDE_TEST_X86_AVX512) */
