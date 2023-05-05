#if !defined(SIMDE_TEST_X86_TEST_X86_H)
#define SIMDE_TEST_X86_TEST_X86_H

#include "../test.h"

HEDLEY_DIAGNOSTIC_PUSH
HEDLEY_DIAGNOSTIC_DISABLE_UNUSED_FUNCTION

#define SIMDE_TEST_X86_GENERATE_FLOAT_TYPE_FUNCS_(NT, EL, EC, SF) \
  static simde##NT \
  simde_test_x86_random_f##EL##x##EC(simde_float##EL min, simde_float##EL max) { \
    simde_float##EL values[sizeof(simde##NT) / sizeof(simde_float##EL)]; \
    simde_test_codegen_random_vf##EL(sizeof(values) / sizeof(values[0]), values, min, max); \
    simde##NT r; \
    simde_memcpy(&r, values, sizeof(r)); \
    return r; \
  } \
 \
  static void \
  simde_test_x86_write_f##EL##x##EC(int indent, simde##NT value, SimdeTestVecPos pos) { \
    simde_float##EL values[sizeof(value) / sizeof(simde_float##EL)]; \
    SF(values, value); \
    simde_test_codegen_write_vf##EL(indent, sizeof(values) / sizeof(values[0]), values, pos); \
  } \
 \
  static int \
  simde_test_x86_assert_equal_f##EL##x##EC##_(simde##NT a, simde##NT b, simde_float##EL slop, \
      const char* filename, int line, const char* astr, const char* bstr) { \
    simde_float##EL \
      a_[sizeof(a) / sizeof(simde_float##EL)], \
      b_[sizeof(a) / sizeof(simde_float##EL)]; \
 \
    SF(a_, a); \
    SF(b_, b); \
 \
    return simde_assert_equal_vf##EL##_(sizeof(a_) / sizeof(a_[0]), a_, b_, slop, filename, line, astr, bstr); \
  } \
\
  static void \
  simde_test_x86_random_f##EL##x##EC##_full( \
      size_t test_sets, size_t vectors_per_set, \
      simde_float##EL values[HEDLEY_ARRAY_PARAM(test_sets * vectors_per_set * (sizeof(simde##NT) / sizeof(simde_float##EL)))], \
      simde_float##EL min, simde_float##EL max, SimdeTestVecFloatType type) { \
    simde_test_codegen_random_vf##EL##_full(test_sets, vectors_per_set, sizeof(simde##NT) / sizeof(simde_float##EL), values, min, max, type); \
  } \
  \
  static simde##NT \
  simde_test_x86_random_extract_f##EL##x##EC(size_t set_num, size_t vectors_per_set, size_t vector_num, simde_float##EL* values) { \
    const size_t elem_cnt = sizeof(simde##NT) / sizeof(simde_float##EL); \
    const size_t set_cnt = elem_cnt * vectors_per_set; \
    simde##NT r; \
    simde_memcpy(&r, &(values[(set_num * set_cnt) + (vector_num * elem_cnt)]), sizeof(r)); \
    return r; \
  }

#define SIMDE_TEST_X86_GENERATE_INT_TYPE_FUNCS_(NT, EL, EC, SF) \
  static simde##NT \
  simde_test_x86_random_i##EL##x##EC(void) { \
    simde##NT v; \
    simde_test_codegen_random_memory(sizeof(v), HEDLEY_REINTERPRET_CAST(uint8_t*, &v)); \
    return v; \
  } \
 \
  static void \
  simde_test_x86_write_i##EL##x##EC(int indent, simde##NT value, SimdeTestVecPos pos) { \
    int##EL##_t value_[sizeof(value) / sizeof(int##EL##_t)]; \
    SF(SIMDE_ALIGN_CAST(simde##NT*, value_), value); \
    simde_test_codegen_write_vi##EL(indent, sizeof(value_) / sizeof(value_[0]), value_, pos); \
  } \
 \
  static int \
  simde_test_x86_assert_equal_i##EL##x##EC##_(simde##NT a, simde##NT b, \
      const char* filename, int line, const char* astr, const char* bstr) { \
    int##EL##_t a_[sizeof(a) / sizeof(int##EL##_t)], b_[sizeof(a) / sizeof(int##EL##_t)]; \
    SF(SIMDE_ALIGN_CAST(simde##NT*, a_), a); \
    SF(SIMDE_ALIGN_CAST(simde##NT*, b_), b); \
    return simde_assert_equal_vi##EL##_(sizeof(a_) / sizeof(a_[0]), a_, b_, filename, line, astr, bstr); \
  } \
 \
  static int \
  simde_test_x86_assert_close_i##EL##x##EC##_(simde##NT a, simde##NT b, int##EL##_t slop, \
      const char* filename, int line, const char* astr, const char* bstr) { \
    int##EL##_t a_[sizeof(a) / sizeof(int##EL##_t)], b_[sizeof(a) / sizeof(int##EL##_t)]; \
    SF(SIMDE_ALIGN_CAST(simde##NT*, a_), a); \
    SF(SIMDE_ALIGN_CAST(simde##NT*, b_), b); \
    return simde_assert_close_vi##EL##_(sizeof(a_) / sizeof(a_[0]), a_, b_, slop, filename, line, astr, bstr); \
  }

#define SIMDE_TEST_X86_GENERATE_UINT_TYPE_FUNCS_(NT, EL, EC, SF) \
  static simde##NT \
  simde_test_x86_random_u##EL##x##EC(void) { \
    simde##NT v; \
    simde_test_codegen_random_memory(sizeof(v), HEDLEY_REINTERPRET_CAST(uint8_t*, &v)); \
    return v; \
  } \
 \
  static void \
  simde_test_x86_write_u##EL##x##EC(int indent, simde##NT value, SimdeTestVecPos pos) { \
    uint##EL##_t value_[sizeof(value) / sizeof(int##EL##_t)]; \
    SF(SIMDE_ALIGN_CAST(simde##NT*, value_), value); \
    simde_test_codegen_write_vu##EL(indent, sizeof(value_) / sizeof(value_[0]), value_, pos); \
  } \
 \
  static int \
  simde_test_x86_assert_equal_u##EL##x##EC##_(simde##NT a, simde##NT b, \
      const char* filename, int line, const char* astr, const char* bstr) { \
    uint##EL##_t a_[sizeof(a) / sizeof(int##EL##_t)], b_[sizeof(a) / sizeof(int##EL##_t)]; \
    SF(SIMDE_ALIGN_CAST(simde##NT*, a_), a); \
    SF(SIMDE_ALIGN_CAST(simde##NT*, b_), b); \
    return simde_assert_equal_vu##EL##_(sizeof(a_) / sizeof(a_[0]), a_, b_, filename, line, astr, bstr); \
  } \
 \
  static int \
  simde_test_x86_assert_close_u##EL##x##EC##_(simde##NT a, simde##NT b, uint##EL##_t slop, \
      const char* filename, int line, const char* astr, const char* bstr) { \
    uint##EL##_t a_[sizeof(a) / sizeof(int##EL##_t)], b_[sizeof(a) / sizeof(int##EL##_t)]; \
    SF(SIMDE_ALIGN_CAST(simde##NT*, a_), a); \
    SF(SIMDE_ALIGN_CAST(simde##NT*, b_), b); \
    return simde_assert_close_vu##EL##_(sizeof(a_) / sizeof(a_[0]), a_, b_, slop, filename, line, astr, bstr); \
  }

/* For compatibility only.  Note that the operator is assumed to be == */
#define simde_assert_m64_i8(a, op, b) simde_test_x86_assert_equal_i8x8(a, b)
#define simde_assert_m64_i16(a, op, b) simde_test_x86_assert_equal_i16x4(a, b)
#define simde_assert_m64_i32(a, op, b) simde_test_x86_assert_equal_i32x2(a, b)
#define simde_assert_m64_i64(a, op, b) simde_test_x86_assert_equal_i64x1(a, b)
#define simde_assert_m64_u8(a, op, b) simde_test_x86_assert_equal_u8x8(a, b)
#define simde_assert_m64_u16(a, op, b) simde_test_x86_assert_equal_u16x4(a, b)
#define simde_assert_m64_u32(a, op, b) simde_test_x86_assert_equal_u32x2(a, b)
#define simde_assert_m64_u64(a, op, b) simde_test_x86_assert_equal_u64x1(a, b)

#define simde_assert_m128i_i8(a, op, b) simde_test_x86_assert_equal_i8x16(a, b)
#define simde_assert_m128i_i16(a, op, b) simde_test_x86_assert_equal_i16x8(a, b)
#define simde_assert_m128i_i32(a, op, b) simde_test_x86_assert_equal_i32x4(a, b)
#define simde_assert_m128i_i64(a, op, b) simde_test_x86_assert_equal_i64x2(a, b)
#define simde_assert_m128i_u8(a, op, b) simde_test_x86_assert_equal_u8x16(a, b)
#define simde_assert_m128i_u16(a, op, b) simde_test_x86_assert_equal_u16x8(a, b)
#define simde_assert_m128i_u32(a, op, b) simde_test_x86_assert_equal_u32x4(a, b)
#define simde_assert_m128i_u64(a, op, b) simde_test_x86_assert_equal_u64x2(a, b)
#define simde_assert_m128_close(a, b, precision) simde_test_x86_assert_equal_f32x4(a, b, precision)
#define simde_assert_m128d_close(a, b, precision) simde_test_x86_assert_equal_f64x2(a, b, precision)
#define simde_assert_m128_equal(a, b) simde_test_x86_assert_equal_i32x4(simde_mm_castps_si128(a), simde_mm_castps_si128(b))
#define simde_assert_m128d_equal(a, b) simde_test_x86_assert_equal_i32x4(simde_mm_castpd_si128(a), simde_mm_castpd_si128(b))
#define simde_assert_m128i_equal(a, b) simde_test_x86_assert_equal_i32x4(a, b)

#define simde_assert_m256i_i8(a, op, b) simde_test_x86_assert_equal_i8x32(a, b)
#define simde_assert_m256i_i16(a, op, b) simde_test_x86_assert_equal_i16x16(a, b)
#define simde_assert_m256i_i32(a, op, b) simde_test_x86_assert_equal_i32x8(a, b)
#define simde_assert_m256i_i64(a, op, b) simde_test_x86_assert_equal_i64x4(a, b)
#define simde_assert_m256i_u8(a, op, b) simde_test_x86_assert_equal_u8x32(a, b)
#define simde_assert_m256i_u16(a, op, b) simde_test_x86_assert_equal_u16x16(a, b)
#define simde_assert_m256i_u32(a, op, b) simde_test_x86_assert_equal_u32x8(a, b)
#define simde_assert_m256i_u64(a, op, b) simde_test_x86_assert_equal_u64x4(a, b)
#define simde_assert_m256_close(a, b, precision) simde_test_x86_assert_equal_f32x8(a, b, precision)
#define simde_assert_m256d_close(a, b, precision) simde_test_x86_assert_equal_f64x4(a, b, precision)
#define simde_assert_m256_equal(a, b) simde_test_x86_assert_equal_i32x8(simde_mm_castps_si128(a), simde_mm_castps_si128(b))
#define simde_assert_m256d_equal(a, b) simde_test_x86_assert_equal_i32x8(simde_mm_castpd_si256(a), simde_mm_castpd_si256(b))
#define simde_assert_m256i_equal(a, b) simde_test_x86_assert_equal_i32x8(a, b)

#define simde_assert_m512i_i8(a, op, b) simde_test_x86_assert_equal_i8x64(a, b)
#define simde_assert_m512i_i16(a, op, b) simde_test_x86_assert_equal_i16x32(a, b)
#define simde_assert_m512i_i32(a, op, b) simde_test_x86_assert_equal_i32x16(a, b)
#define simde_assert_m512i_i64(a, op, b) simde_test_x86_assert_equal_i64x8(a, b)
#define simde_assert_m512i_u8(a, op, b) simde_test_x86_assert_equal_u8x64(a, b)
#define simde_assert_m512i_u16(a, op, b) simde_test_x86_assert_equal_u16x32(a, b)
#define simde_assert_m512i_u32(a, op, b) simde_test_x86_assert_equal_u32x16(a, b)
#define simde_assert_m512i_u64(a, op, b) simde_test_x86_assert_equal_u64x8(a, b)
#define simde_assert_m512_close(a, b, precision) simde_test_x86_assert_equal_f32x16(a, b, precision)
#define simde_assert_m512d_close(a, b, precision) simde_test_x86_assert_equal_f64x8(a, b, precision)
#define simde_assert_m512_equal(a, b) simde_test_x86_assert_equal_i32x16(simde_mm_castps_si128(a), simde_mm_castps_si128(b))
#define simde_assert_m512d_equal(a, b) simde_test_x86_assert_equal_i32x16(simde_mm_castpd_si512(a), simde_mm_castpd_si512(b))
#define simde_assert_m512i_equal(a, b) simde_test_x86_assert_equal_i32x16(a, b)

#define simde_assert_equal_mmask8(a, b) simde_assert_equal_u8(a, b)
#define simde_assert_equal_mmask16(a, b) simde_assert_equal_u16(a, b)
#define simde_assert_equal_mmask32(a, b) simde_assert_equal_u32(a, b)
#define simde_assert_equal_mmask64(a, b) simde_assert_equal_u64(a, b)

/* HEDLEY_DIAGNOSTIC_DISABLE_UNUSED_FUNCTION */
HEDLEY_DIAGNOSTIC_POP

#if !defined(SIMDE_TEST_BARE)
  #define SIMDE_TEST_DECLARE_SUITE(name) SIMDE_TEST_SUITE_DECLARE_GETTERS(HEDLEY_CONCAT(simde_test_x86_get_suite_,name))
  #include <test/x86/declare-suites.h>
  #undef SIMDE_TEST_DECLARE_SUITE
#endif

#endif /* !defined(SIMDE_TEST_X86_TEST_X86_H) */
