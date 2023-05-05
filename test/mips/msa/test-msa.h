#if !defined(SIMDE_TEST_MIPS_TEST_MSA_H)
#define SIMDE_TEST_MIPS_TEST_MSA_H

#include "../../../simde/mips/msa.h"
#include "../../test.h"

#if !defined(SIMDE_TEST_BARE)
  #define SIMDE_TEST_DECLARE_SUITE(name) SIMDE_TEST_SUITE_DECLARE_GETTERS(HEDLEY_CONCAT(simde_test_mips_msa_simd_get_suite_,name))
  #include <test/mips/msa/declare-suites.h>
  #undef SIMDE_TEST_DECLARE_SUITE
#endif

HEDLEY_DIAGNOSTIC_PUSH
HEDLEY_DIAGNOSTIC_DISABLE_UNUSED_FUNCTION

#define SIMDE_TEST_MIPS_MSA_GENERATE_INT_FUNCS_(Element_Width, Element_Count, Variant_Name) \
  static int \
  simde_test_msa_v##Element_Count##i##Element_Width##_assert_equal_( \
      simde_v##Element_Count##i##Element_Width a, simde_v##Element_Count##i##Element_Width b, \
      const char* filename, int line, const char* astr, const char* bstr) { \
    int##Element_Width##_t a_[sizeof(a) / sizeof(int##Element_Width##_t)]; \
    int##Element_Width##_t b_[sizeof(a) / sizeof(int##Element_Width##_t)]; \
    simde_memcpy(a_, &a, sizeof(a)); \
    simde_memcpy(b_, &b, sizeof(b)); \
    return simde_assert_equal_vi##Element_Width##_(sizeof(a_) / sizeof(a_[0]), a_, b_, filename, line, astr, bstr); \
  } \
  \
  static int \
  simde_test_msa_v##Element_Count##u##Element_Width##_assert_equal_( \
      simde_v##Element_Count##u##Element_Width a, simde_v##Element_Count##u##Element_Width b, \
      const char* filename, int line, const char* astr, const char* bstr) { \
    uint##Element_Width##_t a_[sizeof(a) / sizeof(uint##Element_Width##_t)]; \
    uint##Element_Width##_t b_[sizeof(a) / sizeof(uint##Element_Width##_t)]; \
    simde_memcpy(a_, &a, sizeof(a)); \
    simde_memcpy(b_, &b, sizeof(b)); \
    return simde_assert_equal_vu##Element_Width##_(sizeof(a_) / sizeof(a_[0]), a_, b_, filename, line, astr, bstr); \
  } \
  \
  static void \
  simde_test_msa_v##Element_Count##i##Element_Width##_write(int indent, simde_v##Element_Count##i##Element_Width v, SimdeTestVecPos pos) { \
    int##Element_Width##_t v_[sizeof(v) / sizeof(int##Element_Width##_t)]; \
    simde_memcpy(v_, &v, sizeof(v)); \
    simde_test_codegen_write_vi##Element_Width(indent, sizeof(v_) / sizeof(v_[0]), v_, pos); \
  } \
  \
  static void \
  simde_test_msa_v##Element_Count##u##Element_Width##_write(int indent, simde_v##Element_Count##u##Element_Width v, SimdeTestVecPos pos) { \
    uint##Element_Width##_t v_[sizeof(v) / sizeof(int##Element_Width##_t)]; \
    simde_memcpy(v_, &v, sizeof(v)); \
    simde_test_codegen_write_vu##Element_Width(indent, sizeof(v_) / sizeof(v_[0]), v_, pos); \
  } \
  \
  static simde_v##Element_Count##i##Element_Width \
  simde_test_msa_v##Element_Count##i##Element_Width##_random(void) { \
    simde_v##Element_Count##i##Element_Width r; \
    simde_test_codegen_random_memory(sizeof(r), HEDLEY_REINTERPRET_CAST(uint8_t*, &r)); \
    return r; \
  } \
  \
  static simde_v##Element_Count##u##Element_Width \
  simde_test_msa_v##Element_Count##u##Element_Width##_random(void) { \
    simde_v##Element_Count##u##Element_Width r; \
    simde_test_codegen_random_memory(sizeof(r), HEDLEY_REINTERPRET_CAST(uint8_t*, &r)); \
    return r; \
  }

#define SIMDE_TEST_MIPS_MSA_GENERATE_FLOAT_FUNCS_(Element_Width, Element_Count, Variant_Name) \
  static int \
  simde_test_msa_v##Element_Count##f##Element_Width##_assert_equal_( \
      simde_v##Element_Count##f##Element_Width a, simde_v##Element_Count##f##Element_Width b, simde_float##Element_Width slop, \
      const char* filename, int line, const char* astr, const char* bstr) { \
    simde_float##Element_Width a_[sizeof(a) / sizeof(simde_float##Element_Width)]; \
    simde_float##Element_Width b_[sizeof(a) / sizeof(simde_float##Element_Width)]; \
    simde_memcpy(a_, &a, sizeof(a)); \
    simde_memcpy(b_, &b, sizeof(b)); \
    return simde_assert_equal_vf##Element_Width##_(sizeof(a_) / sizeof(a_[0]), a_, b_, slop, filename, line, astr, bstr); \
  } \
  \
  static void \
  simde_test_msa_v##Element_Count##f##Element_Width##_write(int indent, simde_v##Element_Count##f##Element_Width v, SimdeTestVecPos pos) { \
    simde_float##Element_Width v_[sizeof(v) / sizeof(simde_float##Element_Width)]; \
    simde_memcpy(v_, &v, sizeof(v)); \
    simde_test_codegen_write_vf##Element_Width(indent, sizeof(v_) / sizeof(v_[0]), v_, pos); \
  } \
  \
  static simde_v##Element_Count##f##Element_Width \
  simde_test_msa_v##Element_Count##f##Element_Width##_random(simde_float##Element_Width min, simde_float##Element_Width max) { \
    simde_float##Element_Width r_[sizeof(simde_v##Element_Count##f##Element_Width) / sizeof(simde_float##Element_Width)]; \
    simde_v##Element_Count##f##Element_Width r; \
    simde_test_codegen_random_vf##Element_Width(sizeof(simde_v##Element_Count##f##Element_Width) / sizeof(simde_float##Element_Width), r_, min, max); \
    simde_memcpy(&r, r_, sizeof(r)); \
    return r; \
  } \
  \
  static void \
  simde_test_msa_v##Element_Count##f##Element_Width##_random_full( \
      size_t test_sets, size_t vectors_per_set, \
      simde_float##Element_Width v[HEDLEY_ARRAY_PARAM(test_sets * vectors_per_set * (sizeof(simde_v##Element_Count##f##Element_Width) / sizeof(simde_float##Element_Width)))], \
      simde_float##Element_Width min, simde_float##Element_Width max, \
      SimdeTestVecFloatType vec_type) { \
    simde_test_codegen_random_vf##Element_Width##_full(test_sets, vectors_per_set, (sizeof(simde_v##Element_Count##f##Element_Width) / sizeof(simde_float##Element_Width)), v, min, max, vec_type); \
  } \
  \
  static simde_v##Element_Count##f##Element_Width \
  simde_test_msa_f##Element_Width##x##Element_Count##_random_full_extract( \
      size_t vectors_per_set, \
      simde_float##Element_Width v[], \
      size_t set_n, size_t vec_n) { \
    simde_v##Element_Count##f##Element_Width r; \
    simde_memcpy(&r, &(v[((vectors_per_set * set_n) + vec_n) * (sizeof(simde_v##Element_Count##f##Element_Width) / sizeof(simde_float##Element_Width))]), sizeof(r)); \
    return r; \
  }

SIMDE_TEST_MIPS_MSA_GENERATE_INT_FUNCS_( 8, 16, b)
SIMDE_TEST_MIPS_MSA_GENERATE_INT_FUNCS_(16,  8, h)
SIMDE_TEST_MIPS_MSA_GENERATE_INT_FUNCS_(32,  4, w)
SIMDE_TEST_MIPS_MSA_GENERATE_INT_FUNCS_(64,  2, d)
SIMDE_TEST_MIPS_MSA_GENERATE_FLOAT_FUNCS_(32,  4, w)
SIMDE_TEST_MIPS_MSA_GENERATE_FLOAT_FUNCS_(64,  2, d)

#define simde_test_msa_v16i8_assert_equal(a, b) do { if (simde_test_msa_v16i8_assert_equal_(a, b, __FILE__, __LINE__, #a, #b)) return 1; } while (0)
#define simde_test_msa_v8i16_assert_equal(a, b) do { if (simde_test_msa_v8i16_assert_equal_(a, b, __FILE__, __LINE__, #a, #b)) return 1; } while (0)
#define simde_test_msa_v4i32_assert_equal(a, b) do { if (simde_test_msa_v4i32_assert_equal_(a, b, __FILE__, __LINE__, #a, #b)) return 1; } while (0)
#define simde_test_msa_v2i64_assert_equal(a, b) do { if (simde_test_msa_v2i64_assert_equal_(a, b, __FILE__, __LINE__, #a, #b)) return 1; } while (0)
#define simde_test_msa_v16u8_assert_equal(a, b) do { if (simde_test_msa_v16u8_assert_equal_(a, b, __FILE__, __LINE__, #a, #b)) return 1; } while (0)
#define simde_test_msa_v8u16_assert_equal(a, b) do { if (simde_test_msa_v8u16_assert_equal_(a, b, __FILE__, __LINE__, #a, #b)) return 1; } while (0)
#define simde_test_msa_v4u32_assert_equal(a, b) do { if (simde_test_msa_v4u32_assert_equal_(a, b, __FILE__, __LINE__, #a, #b)) return 1; } while (0)
#define simde_test_msa_v2u64_assert_equal(a, b) do { if (simde_test_msa_v2u64_assert_equal_(a, b, __FILE__, __LINE__, #a, #b)) return 1; } while (0)
#define simde_test_msa_v4f32_assert_equal(a, b, precision) do { if (simde_test_msa_v4f32_assert_equal_(a, b, simde_test_f32_precision_to_slop(precision), __FILE__, __LINE__, #a, #b)) return 1; } while (0)
#define simde_test_msa_v2f64_assert_equal(a, b, precision) do { if (simde_test_msa_v2f64_assert_equal_(a, b, simde_test_f64_precision_to_slop(precision), __FILE__, __LINE__, #a, #b)) return 1; } while (0)

/* HEDLEY_DIAGNOSTIC_DISABLE_UNUSED_FUNCTION */
HEDLEY_DIAGNOSTIC_POP

#endif /* !defined(SIMDE_TEST_MIPS_TEST_MSA_H) */
