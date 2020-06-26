#if !defined(SIMDE_TEST_ARM_NEON_TEST_NEON_H)
#define SIMDE_TEST_ARM_NEON_TEST_NEON_H

#include "../../test.h"
#include "../../../simde/arm/neon/ld1.h"
#include "../../../simde/arm/neon/st1.h"

#define SIMDE_TEST_ARM_NEON_GENERATE_INT_TYPE_FUNCS_(NT, ET, element_count, modifier, symbol_identifier, neon_identifier) \
  static simde_##NT \
  simde_test_arm_neon_random_##symbol_identifier##x##element_count(void) { \
    simde_##NT v; \
    simde_test_codegen_random_memory(sizeof(v), HEDLEY_REINTERPRET_CAST(uint8_t*, &v)); \
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
    simde_test_codegen_random_v##symbol_identifier(sizeof(v) / sizeof(v[0]), v, HEDLEY_STATIC_CAST(SET, min), HEDLEY_STATIC_CAST(SET, max)); \
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

#define SIMDE_TEST_ARM_NEON_GENERATE_X2_VECTOR_INT_TYPE_FUNCS_(NT, ET, element_count, modifier, symbol_identifier, neon_identifier) \
  static simde_##NT \
  simde_test_arm_neon_random_##symbol_identifier##x##element_count##x2(void) { \
    simde_##NT v; \
    simde_test_codegen_random_memory(sizeof(v), HEDLEY_REINTERPRET_CAST(uint8_t*, &v)); \
    return v; \
  } \
 \
  static void \
  simde_test_arm_neon_write_##symbol_identifier##x##element_count##x2(int indent, simde_##NT value, SimdeTestVecPos pos) { \
    simde_test_codegen_write_indent(indent); \
    fputs("  {\n", stdout); \
    ET value0_[sizeof(value) / sizeof(ET) / 2]; \
    ET value1_[sizeof(value) / sizeof(ET) / 2]; \
 \
    simde_vst1##modifier##_##neon_identifier(value0_, value.val[0]); \
    simde_vst1##modifier##_##neon_identifier(value1_, value.val[1]); \
 \
    simde_test_codegen_write_v##symbol_identifier(indent+2, sizeof(value0_) / sizeof(ET), value0_, SIMDE_TEST_VEC_POS_MIDDLE); \
    simde_test_codegen_write_v##symbol_identifier(indent+2, sizeof(value1_) / sizeof(ET), value1_, SIMDE_TEST_VEC_POS_MIDDLE); \
    if (pos == SIMDE_TEST_VEC_POS_LAST) { \
      simde_test_codegen_write_indent(indent); \
      fputs("  },\n", stdout); \
      simde_test_codegen_write_indent(indent); \
      fputs("},\n", stdout); \
    } else { \
      fputs("  },\n", stdout); \
    } \
 \
  } \
 \
  static int \
  simde_test_arm_neon_assert_equal_##symbol_identifier##x##element_count##x2_(simde_##NT a, simde_##NT b, \
      const char* filename, int line, const char* astr, const char* bstr) { \
    ET a0_[sizeof(a.val[0]) / sizeof(ET)], b0_[sizeof(b.val[0]) / sizeof(ET)]; \
    ET a1_[sizeof(a.val[1]) / sizeof(ET)], b1_[sizeof(b.val[1]) / sizeof(ET)]; \
 \
    simde_vst1##modifier##_##neon_identifier(a0_, a.val[0]); \
    simde_vst1##modifier##_##neon_identifier(b0_, b.val[0]); \
    simde_vst1##modifier##_##neon_identifier(a1_, a.val[1]); \
    simde_vst1##modifier##_##neon_identifier(b1_, b.val[1]); \
 \
    return simde_assert_equal_v##symbol_identifier##_(sizeof(a0_) / sizeof(a0_[0]), a0_, b0_, filename, line, astr, bstr) \
      && simde_assert_equal_v##symbol_identifier##_(sizeof(a1_) / sizeof(a1_[0]), a1_, b1_, filename, line, astr, bstr); \
  }

#define SIMDE_TEST_ARM_NEON_GENERATE_X2_VECTOR_FLOAT_TYPE_FUNCS_(NT, ET, SET, element_count, modifier, symbol_identifier) \
  static simde_##NT \
  simde_test_arm_neon_random_##symbol_identifier##x##element_count##x2(ET min, ET max) { \
    SET v0[sizeof(simde_##NT) / sizeof(ET) / 2]; \
    SET v1[sizeof(simde_##NT) / sizeof(ET) / 2]; \
    simde_test_codegen_random_v##symbol_identifier(sizeof(v0) / sizeof(v0[0]), v0, HEDLEY_STATIC_CAST(SET, min), HEDLEY_STATIC_CAST(SET, max)); \
    simde_test_codegen_random_v##symbol_identifier(sizeof(v1) / sizeof(v1[0]), v1, HEDLEY_STATIC_CAST(SET, min), HEDLEY_STATIC_CAST(SET, max)); \
    simde_##NT r; \
    r.val[0] = simde_vld1##modifier##_##symbol_identifier(HEDLEY_REINTERPRET_CAST(ET*, v0)); \
    r.val[1] = simde_vld1##modifier##_##symbol_identifier(HEDLEY_REINTERPRET_CAST(ET*, v1)); \
    return r; \
  } \
 \
  static void \
  simde_test_arm_neon_write_##symbol_identifier##x##element_count##x2(int indent, simde_##NT value, SimdeTestVecPos pos) { \
    simde_test_codegen_write_indent(indent); \
    fputs("  {\n", stdout); \
 \
    ET value0_[sizeof(value) / sizeof(ET) / 2]; \
    ET value1_[sizeof(value) / sizeof(ET) / 2]; \
    simde_vst1##modifier##_##symbol_identifier(value0_, value.val[0]); \
    simde_vst1##modifier##_##symbol_identifier(value1_, value.val[1]); \
    simde_test_codegen_write_v##symbol_identifier(indent + 2, sizeof(value0_) / sizeof(value0_[0]), value0_, SIMDE_TEST_VEC_POS_MIDDLE); \
    simde_test_codegen_write_v##symbol_identifier(indent + 2, sizeof(value1_) / sizeof(value1_[0]), value1_, SIMDE_TEST_VEC_POS_MIDDLE); \
    if (pos == SIMDE_TEST_VEC_POS_LAST) { \
      simde_test_codegen_write_indent(indent); \
      fputs("  },\n", stdout); \
      simde_test_codegen_write_indent(indent); \
      fputs("},\n", stdout); \
    } else { \
      fputs("  },\n", stdout); \
    } \
  } \
 \
  static int \
  simde_test_arm_neon_assert_equal_##symbol_identifier##x##element_count##x2_(simde_##NT a, simde_##NT b, ET slop, \
     const char* filename, int line, const char* astr, const char* bstr) { \
    SET a0_[sizeof(a) / sizeof(ET)], b0_[sizeof(b) / sizeof(ET)]; \
    SET a1_[sizeof(a) / sizeof(ET)], b1_[sizeof(b) / sizeof(ET)]; \
 \
    simde_vst1##modifier##_##symbol_identifier(a0_, a.val[0]); \
    simde_vst1##modifier##_##symbol_identifier(b0_, b.val[0]);       \
    simde_vst1##modifier##_##symbol_identifier(a1_, a.val[1]); \
    simde_vst1##modifier##_##symbol_identifier(b1_, b.val[1]); \
 \
    return simde_assert_equal_v##symbol_identifier##_(sizeof(a0_) / sizeof(ET), HEDLEY_REINTERPRET_CAST(SET*, a0_), HEDLEY_REINTERPRET_CAST(SET*, b0_), slop, filename, line, astr, bstr) && \
      simde_assert_equal_v##symbol_identifier##_(sizeof(a1_) / sizeof(ET), HEDLEY_REINTERPRET_CAST(SET*, a1_), HEDLEY_REINTERPRET_CAST(SET*, b1_), slop, filename, line, astr, bstr); \
  }

#if !defined(SIMDE_BUG_INTEL_857088)
SIMDE_TEST_ARM_NEON_GENERATE_X2_VECTOR_INT_TYPE_FUNCS_(     int8x8x2_t,   int8_t,  8,  ,  i8,  s8)
SIMDE_TEST_ARM_NEON_GENERATE_X2_VECTOR_INT_TYPE_FUNCS_(    int16x4x2_t,  int16_t,  4,  , i16, s16)
SIMDE_TEST_ARM_NEON_GENERATE_X2_VECTOR_INT_TYPE_FUNCS_(    int32x2x2_t,  int32_t,  2,  , i32, s32)
SIMDE_TEST_ARM_NEON_GENERATE_X2_VECTOR_INT_TYPE_FUNCS_(    int64x1x2_t,  int64_t,  1,  , i64, s64)
SIMDE_TEST_ARM_NEON_GENERATE_X2_VECTOR_INT_TYPE_FUNCS_(    uint8x8x2_t,  uint8_t,  8,  ,  u8,  u8)
SIMDE_TEST_ARM_NEON_GENERATE_X2_VECTOR_INT_TYPE_FUNCS_(   uint16x4x2_t, uint16_t,  4,  , u16, u16)
SIMDE_TEST_ARM_NEON_GENERATE_X2_VECTOR_INT_TYPE_FUNCS_(   uint32x2x2_t, uint32_t,  2,  , u32, u32)
SIMDE_TEST_ARM_NEON_GENERATE_X2_VECTOR_INT_TYPE_FUNCS_(   uint64x1x2_t, uint64_t,  1,  , u64, u64)
SIMDE_TEST_ARM_NEON_GENERATE_X2_VECTOR_FLOAT_TYPE_FUNCS_(float32x2x2_t, simde_float32_t, simde_float32, 2, , f32)
SIMDE_TEST_ARM_NEON_GENERATE_X2_VECTOR_FLOAT_TYPE_FUNCS_(float64x1x2_t, simde_float64_t, simde_float64, 1, , f64)

SIMDE_TEST_ARM_NEON_GENERATE_X2_VECTOR_INT_TYPE_FUNCS_(    int8x16x2_t,   int8_t, 16, q,  i8,  s8)
SIMDE_TEST_ARM_NEON_GENERATE_X2_VECTOR_INT_TYPE_FUNCS_(    int16x8x2_t,  int16_t,  8, q, i16, s16)
SIMDE_TEST_ARM_NEON_GENERATE_X2_VECTOR_INT_TYPE_FUNCS_(    int32x4x2_t,  int32_t,  4, q, i32, s32)
SIMDE_TEST_ARM_NEON_GENERATE_X2_VECTOR_INT_TYPE_FUNCS_(    int64x2x2_t,  int64_t,  2, q, i64, s64)
SIMDE_TEST_ARM_NEON_GENERATE_X2_VECTOR_INT_TYPE_FUNCS_(   uint8x16x2_t,  uint8_t, 16, q,  u8,  u8)
SIMDE_TEST_ARM_NEON_GENERATE_X2_VECTOR_INT_TYPE_FUNCS_(   uint16x8x2_t,  uint16_t,  8, q, u16, u16)
SIMDE_TEST_ARM_NEON_GENERATE_X2_VECTOR_INT_TYPE_FUNCS_(   uint32x4x2_t,  uint32_t,  4, q, u32, u32)
SIMDE_TEST_ARM_NEON_GENERATE_X2_VECTOR_INT_TYPE_FUNCS_(   uint64x2x2_t,  uint64_t,  2, q, u64, u64)
SIMDE_TEST_ARM_NEON_GENERATE_X2_VECTOR_FLOAT_TYPE_FUNCS_(float32x4x2_t, simde_float32_t, simde_float32, 4, q, f32)
SIMDE_TEST_ARM_NEON_GENERATE_X2_VECTOR_FLOAT_TYPE_FUNCS_(float64x2x2_t, simde_float64_t, simde_float64, 2, q, f64)
#endif

#define simde_test_arm_neon_assert_equal_i8x8(a, b)   do { if (simde_test_arm_neon_assert_equal_i8x8_(a, b, __FILE__, __LINE__, #a, #b)) { return 1; } } while (0)
#define simde_test_arm_neon_assert_equal_i16x4(a, b) do { if (simde_test_arm_neon_assert_equal_i16x4_(a, b, __FILE__, __LINE__, #a, #b)) { return 1; } } while (0)
#define simde_test_arm_neon_assert_equal_i32x2(a, b) do { if (simde_test_arm_neon_assert_equal_i32x2_(a, b, __FILE__, __LINE__, #a, #b)) { return 1; } } while (0)
#define simde_test_arm_neon_assert_equal_i64x1(a, b) do { if (simde_test_arm_neon_assert_equal_i64x1_(a, b, __FILE__, __LINE__, #a, #b)) { return 1; } } while (0)
#define simde_test_arm_neon_assert_equal_u8x8(a, b)   do { if (simde_test_arm_neon_assert_equal_u8x8_(a, b, __FILE__, __LINE__, #a, #b)) { return 1; } } while (0)
#define simde_test_arm_neon_assert_equal_u16x4(a, b) do { if (simde_test_arm_neon_assert_equal_u16x4_(a, b, __FILE__, __LINE__, #a, #b)) { return 1; } } while (0)
#define simde_test_arm_neon_assert_equal_u32x2(a, b) do { if (simde_test_arm_neon_assert_equal_u32x2_(a, b, __FILE__, __LINE__, #a, #b)) { return 1; } } while (0)
#define simde_test_arm_neon_assert_equal_u64x1(a, b) do { if (simde_test_arm_neon_assert_equal_u64x1_(a, b, __FILE__, __LINE__, #a, #b)) { return 1; } } while (0)
#define simde_test_arm_neon_assert_equal_f32x2(a, b, precision) do { if (simde_test_arm_neon_assert_equal_f32x2_(a, b, 1e-##precision##f, __FILE__, __LINE__, #a, #b)) { return 1; } } while (0)
#define simde_test_arm_neon_assert_equal_f64x1(a, b, precision) do { if (simde_test_arm_neon_assert_equal_f64x1_(a, b, 1e-##precision,    __FILE__, __LINE__, #a, #b)) { return 1; } } while (0)

#define simde_test_arm_neon_assert_equal_i8x16(a, b) do { if (simde_test_arm_neon_assert_equal_i8x16_(a, b, __FILE__, __LINE__, #a, #b)) { return 1; } } while (0)
#define simde_test_arm_neon_assert_equal_i16x8(a, b) do { if (simde_test_arm_neon_assert_equal_i16x8_(a, b, __FILE__, __LINE__, #a, #b)) { return 1; } } while (0)
#define simde_test_arm_neon_assert_equal_i32x4(a, b) do { if (simde_test_arm_neon_assert_equal_i32x4_(a, b, __FILE__, __LINE__, #a, #b)) { return 1; } } while (0)
#define simde_test_arm_neon_assert_equal_i64x2(a, b) do { if (simde_test_arm_neon_assert_equal_i64x2_(a, b, __FILE__, __LINE__, #a, #b)) { return 1; } } while (0)
#define simde_test_arm_neon_assert_equal_u8x16(a, b) do { if (simde_test_arm_neon_assert_equal_u8x16_(a, b, __FILE__, __LINE__, #a, #b)) { return 1; } } while (0)
#define simde_test_arm_neon_assert_equal_u16x8(a, b) do { if (simde_test_arm_neon_assert_equal_u16x8_(a, b, __FILE__, __LINE__, #a, #b)) { return 1; } } while (0)
#define simde_test_arm_neon_assert_equal_u32x4(a, b) do { if (simde_test_arm_neon_assert_equal_u32x4_(a, b, __FILE__, __LINE__, #a, #b)) { return 1; } } while (0)
#define simde_test_arm_neon_assert_equal_u64x2(a, b) do { if (simde_test_arm_neon_assert_equal_u64x2_(a, b, __FILE__, __LINE__, #a, #b)) { return 1; } } while (0)
#define simde_test_arm_neon_assert_equal_f32x4(a, b, precision) do { if (simde_test_arm_neon_assert_equal_f32x4_(a, b, 1e-##precision##f, __FILE__, __LINE__, #a, #b)) { return 1; } } while (0)
#define simde_test_arm_neon_assert_equal_f64x2(a, b, precision) do { if (simde_test_arm_neon_assert_equal_f64x2_(a, b, 1e-##precision,    __FILE__, __LINE__, #a, #b)) { return 1; } } while (0)

#if !defined(SIMDE_TEST_BARE)
  #define SIMDE_TEST_DECLARE_SUITE(name) SIMDE_TEST_SUITE_DECLARE_GETTERS(HEDLEY_CONCAT(simde_test_arm_neon_get_suite_,name))
  #include "declare-suites.h"
  #undef SIMDE_TEST_DECLARE_SUITE
#endif

#endif /* !defined(SIMDE_TEST_ARM_NEON_TEST_NEON_H) */
