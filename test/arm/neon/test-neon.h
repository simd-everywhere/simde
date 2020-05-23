#if !defined(SIMDE_TEST_ARM_NEON_TEST_NEON_H)
#define SIMDE_TEST_ARM_NEON_TEST_NEON_H

#include "../../test.h"
#include "../../../simde/arm/neon/ld1.h"
#include "../../../simde/arm/neon/st1.h"

#define SIMDE_TEST_ARM_NEON_GENERATE_INT_TYPE_FUNCS_(NT, ET, element_count, modifier, symbol_identifier, neon_identifier) \
  static simde_##NT \
  simde_test_arm_neon_random_##symbol_identifier##x##element_count(void) { \
    simde_##NT v; \
    simde_codegen_random_memory(sizeof(v), HEDLEY_REINTERPRET_CAST(uint8_t*, &v)); \
    return v; \
  } \
 \
  static void \
  simde_test_arm_neon_write_##symbol_identifier##x##element_count(int indent, simde_##NT value, SimdeTestVecPos pos) { \
    ET value_[sizeof(value) / sizeof(ET)]; \
 \
    simde_vst1##modifier##_##neon_identifier(value_, value); \
 \
    simde_test_codegen_write_v##symbol_identifier(indent, sizeof(value) / sizeof(ET), value_, pos); \
 \
  } \
 \
  static int \
  simde_test_arm_neon_assert_equal_##symbol_identifier##x##element_count##_(simde_##NT a, simde_##NT b, \
      const char* filename, int line, const char* astr, const char* bstr) { \
    ET a_[sizeof(a) / sizeof(ET)], b_[sizeof(b) / sizeof(ET)]; \
 \
    simde_vst1##modifier##_##neon_identifier(a_, a); \
    simde_vst1##modifier##_##neon_identifier(b_, b); \
 \
    return simde_assert_equal_v##symbol_identifier##_(sizeof(a_) / sizeof(a_[0]), a_, b_, filename, line, astr, bstr); \
  }

#define SIMDE_TEST_ARM_NEON_GENERATE_FLOAT_TYPE_FUNCS_(NT, ET, SET, element_count, modifier, symbol_identifier) \
  static simde_##NT \
  simde_test_arm_neon_random_##symbol_identifier##x##element_count(ET min, ET max) { \
    SET v[sizeof(simde_##NT) / sizeof(ET)]; \
    simde_codegen_random_v##symbol_identifier(sizeof(v) / sizeof(v[0]), v, HEDLEY_STATIC_CAST(SET, min), HEDLEY_STATIC_CAST(SET, max)); \
    return simde_vld1##modifier##_##symbol_identifier(HEDLEY_REINTERPRET_CAST(ET*, v)); \
  } \
 \
  static void \
  simde_test_arm_neon_write_##symbol_identifier##x##element_count(int indent, simde_##NT value, SimdeTestVecPos pos) { \
    ET value_[sizeof(value) / sizeof(ET)]; \
    simde_vst1##modifier##_##symbol_identifier(value_, value); \
    simde_test_codegen_write_v##symbol_identifier(indent, sizeof(value_) / sizeof(value_[0]), value_, pos); \
  } \
 \
  static int \
  simde_test_arm_neon_assert_equal_##symbol_identifier##x##element_count##_(simde_##NT a, simde_##NT b, ET slop, \
      const char* filename, int line, const char* astr, const char* bstr) { \
    SET a_[sizeof(a) / sizeof(ET)], b_[sizeof(b) / sizeof(ET)]; \
 \
    simde_vst1##modifier##_##symbol_identifier(a_, a); \
    simde_vst1##modifier##_##symbol_identifier(b_, b); \
 \
    return simde_assert_equal_v##symbol_identifier##_(sizeof(a_) / sizeof(ET), HEDLEY_REINTERPRET_CAST(SET*, a_), HEDLEY_REINTERPRET_CAST(SET*, b_), slop, filename, line, astr, bstr); \
  }

HEDLEY_DIAGNOSTIC_PUSH
SIMDE_DIAGNOSTIC_DISABLE_CPP98_COMPAT_PEDANTIC_
SIMDE_TEST_ARM_NEON_GENERATE_INT_TYPE_FUNCS_(     int8x8_t,   int8_t,  8,  ,  i8,  s8)
SIMDE_TEST_ARM_NEON_GENERATE_INT_TYPE_FUNCS_(    int16x4_t,  int16_t,  4,  , i16, s16)
SIMDE_TEST_ARM_NEON_GENERATE_INT_TYPE_FUNCS_(    int32x2_t,  int32_t,  2,  , i32, s32)
SIMDE_TEST_ARM_NEON_GENERATE_INT_TYPE_FUNCS_(    int64x1_t,  int64_t,  1,  , i64, s64)
SIMDE_TEST_ARM_NEON_GENERATE_INT_TYPE_FUNCS_(    uint8x8_t,  uint8_t,  8,  ,  u8,  u8)
SIMDE_TEST_ARM_NEON_GENERATE_INT_TYPE_FUNCS_(   uint16x4_t, uint16_t,  4,  , u16, u16)
SIMDE_TEST_ARM_NEON_GENERATE_INT_TYPE_FUNCS_(   uint32x2_t, uint32_t,  2,  , u32, u32)
SIMDE_TEST_ARM_NEON_GENERATE_INT_TYPE_FUNCS_(   uint64x1_t, uint64_t,  1,  , u64, u64)
SIMDE_TEST_ARM_NEON_GENERATE_FLOAT_TYPE_FUNCS_(float32x2_t, simde_float32_t, simde_float32, 2,  , f32)
SIMDE_TEST_ARM_NEON_GENERATE_FLOAT_TYPE_FUNCS_(float64x1_t, simde_float64_t, simde_float64, 1,  , f64)

SIMDE_TEST_ARM_NEON_GENERATE_INT_TYPE_FUNCS_(    int8x16_t,   int8_t, 16, q,  i8,  s8)
SIMDE_TEST_ARM_NEON_GENERATE_INT_TYPE_FUNCS_(    int16x8_t,  int16_t,  8, q, i16, s16)
SIMDE_TEST_ARM_NEON_GENERATE_INT_TYPE_FUNCS_(    int32x4_t,  int32_t,  4, q, i32, s32)
SIMDE_TEST_ARM_NEON_GENERATE_INT_TYPE_FUNCS_(    int64x2_t,  int64_t,  2, q, i64, s64)
SIMDE_TEST_ARM_NEON_GENERATE_INT_TYPE_FUNCS_(   uint8x16_t,  uint8_t, 16, q,  u8,  u8)
SIMDE_TEST_ARM_NEON_GENERATE_INT_TYPE_FUNCS_(   uint16x8_t,  uint16_t,  8, q, u16, u16)
SIMDE_TEST_ARM_NEON_GENERATE_INT_TYPE_FUNCS_(   uint32x4_t,  uint32_t,  4, q, u32, u32)
SIMDE_TEST_ARM_NEON_GENERATE_INT_TYPE_FUNCS_(   uint64x2_t,  uint64_t,  2, q, u64, u64)
SIMDE_TEST_ARM_NEON_GENERATE_FLOAT_TYPE_FUNCS_(float32x4_t, simde_float32_t, simde_float32, 4, q, f32)
SIMDE_TEST_ARM_NEON_GENERATE_FLOAT_TYPE_FUNCS_(float64x2_t, simde_float64_t, simde_float64, 2, q, f64)
HEDLEY_DIAGNOSTIC_POP

#define simde_test_arm_neon_assert_equal_i8x8(a, b)   simde_test_arm_neon_assert_equal_i8x8_(a, b, __FILE__, __LINE__, #a, #b)
#define simde_test_arm_neon_assert_equal_i16x4(a, b) simde_test_arm_neon_assert_equal_i16x4_(a, b, __FILE__, __LINE__, #a, #b)
#define simde_test_arm_neon_assert_equal_i32x2(a, b) simde_test_arm_neon_assert_equal_i32x2_(a, b, __FILE__, __LINE__, #a, #b)
#define simde_test_arm_neon_assert_equal_i64x1(a, b) simde_test_arm_neon_assert_equal_i64x1_(a, b, __FILE__, __LINE__, #a, #b)
#define simde_test_arm_neon_assert_equal_u8x8(a, b)   simde_test_arm_neon_assert_equal_u8x8_(a, b, __FILE__, __LINE__, #a, #b)
#define simde_test_arm_neon_assert_equal_u16x4(a, b) simde_test_arm_neon_assert_equal_u16x4_(a, b, __FILE__, __LINE__, #a, #b)
#define simde_test_arm_neon_assert_equal_u32x2(a, b) simde_test_arm_neon_assert_equal_u32x2_(a, b, __FILE__, __LINE__, #a, #b)
#define simde_test_arm_neon_assert_equal_u64x1(a, b) simde_test_arm_neon_assert_equal_u64x1_(a, b, __FILE__, __LINE__, #a, #b)
#define simde_test_arm_neon_assert_equal_f32x2(a, b, precision) simde_test_arm_neon_assert_equal_f32x2_(a, b, 1e-##precision##f, __FILE__, __LINE__, #a, #b)
#define simde_test_arm_neon_assert_equal_f64x1(a, b, precision) simde_test_arm_neon_assert_equal_f64x1_(a, b, 1e-##precision,    __FILE__, __LINE__, #a, #b)

#define simde_test_arm_neon_assert_equal_i8x16(a, b) simde_test_arm_neon_assert_equal_i8x16_(a, b, __FILE__, __LINE__, #a, #b)
#define simde_test_arm_neon_assert_equal_i16x8(a, b) simde_test_arm_neon_assert_equal_i16x8_(a, b, __FILE__, __LINE__, #a, #b)
#define simde_test_arm_neon_assert_equal_i32x4(a, b) simde_test_arm_neon_assert_equal_i32x4_(a, b, __FILE__, __LINE__, #a, #b)
#define simde_test_arm_neon_assert_equal_i64x2(a, b) simde_test_arm_neon_assert_equal_i64x2_(a, b, __FILE__, __LINE__, #a, #b)
#define simde_test_arm_neon_assert_equal_u8x16(a, b) simde_test_arm_neon_assert_equal_u8x16_(a, b, __FILE__, __LINE__, #a, #b)
#define simde_test_arm_neon_assert_equal_u16x8(a, b) simde_test_arm_neon_assert_equal_u16x8_(a, b, __FILE__, __LINE__, #a, #b)
#define simde_test_arm_neon_assert_equal_u32x4(a, b) simde_test_arm_neon_assert_equal_u32x4_(a, b, __FILE__, __LINE__, #a, #b)
#define simde_test_arm_neon_assert_equal_u64x2(a, b) simde_test_arm_neon_assert_equal_u64x2_(a, b, __FILE__, __LINE__, #a, #b)
#define simde_test_arm_neon_assert_equal_f32x4(a, b, precision) simde_test_arm_neon_assert_equal_f32x4_(a, b, 1e-##precision##f, __FILE__, __LINE__, #a, #b)
#define simde_test_arm_neon_assert_equal_f64x2(a, b, precision) simde_test_arm_neon_assert_equal_f64x2_(a, b, 1e-##precision,    __FILE__, __LINE__, #a, #b)

#if !defined(SIMDE_TEST_BARE)
  #define SIMDE_TEST_DECLARE_SUITE(name) SIMDE_TEST_SUITE_DECLARE_GETTERS(HEDLEY_CONCAT(simde_test_arm_neon_get_suite_,name))
  #include "declare-suites.h"
  #undef SIMDE_TEST_DECLARE_SUITE
#endif

#endif /* !defined(SIMDE_TEST_ARM_NEON_TEST_NEON_H) */
