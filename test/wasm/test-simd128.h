#if !defined(SIMDE_TEST_WASM_TEST_SIMD128_H)
#define SIMDE_TEST_WASM_TEST_SIMD128_H

#include "../../simde/wasm/simd128.h"
#include "../test.h"

HEDLEY_DIAGNOSTIC_PUSH
HEDLEY_DIAGNOSTIC_DISABLE_UNUSED_FUNCTION

#define SIMDE_TEST_WASM_SIMD128_GENERATE_INT_FUNCS_(Element_Width, Element_Count) \
  static int \
  simde_test_wasm_i##Element_Width##x##Element_Count##_assert_equal_( \
      simde_v128_t a, simde_v128_t b, \
      const char* filename, int line, const char* astr, const char* bstr) { \
    int##Element_Width##_t a_[sizeof(a) / sizeof(int##Element_Width##_t)]; \
    int##Element_Width##_t b_[sizeof(a) / sizeof(int##Element_Width##_t)]; \
    simde_wasm_v128_store(a_, a); \
    simde_wasm_v128_store(b_, b); \
    return simde_assert_equal_vi##Element_Width##_(sizeof(a_) / sizeof(a_[0]), a_, b_, filename, line, astr, bstr); \
  } \
  \
  static int \
  simde_test_wasm_u##Element_Width##x##Element_Count##_assert_equal_( \
      simde_v128_t a, simde_v128_t b, \
      const char* filename, int line, const char* astr, const char* bstr) { \
    uint##Element_Width##_t a_[sizeof(a) / sizeof(uint##Element_Width##_t)]; \
    uint##Element_Width##_t b_[sizeof(a) / sizeof(uint##Element_Width##_t)]; \
    simde_wasm_v128_store(a_, a); \
    simde_wasm_v128_store(b_, b); \
    return simde_assert_equal_vu##Element_Width##_(sizeof(a_) / sizeof(a_[0]), a_, b_, filename, line, astr, bstr); \
  } \
  \
  static void \
  simde_test_wasm_i##Element_Width##x##Element_Count##_write(int indent, simde_v128_t v, SimdeTestVecPos pos) { \
    int##Element_Width##_t v_[sizeof(v) / sizeof(int##Element_Width##_t)]; \
    simde_wasm_v128_store(v_, v); \
    simde_test_codegen_write_vi##Element_Width(indent, sizeof(v_) / sizeof(v_[0]), v_, pos); \
  } \
  \
  static void \
  simde_test_wasm_u##Element_Width##x##Element_Count##_write(int indent, simde_v128_t v, SimdeTestVecPos pos) { \
    uint##Element_Width##_t v_[sizeof(v) / sizeof(int##Element_Width##_t)]; \
    simde_wasm_v128_store(v_, v); \
    simde_test_codegen_write_vu##Element_Width(indent, sizeof(v_) / sizeof(v_[0]), v_, pos); \
  } \
  \
  static simde_v128_t \
  simde_test_wasm_i##Element_Width##x##Element_Count##_random(void) { \
    simde_v128_t r; \
    simde_test_codegen_random_memory(sizeof(r), HEDLEY_REINTERPRET_CAST(uint8_t*, &r)); \
    return r; \
  } \
  \
  static simde_v128_t \
  simde_test_wasm_u##Element_Width##x##Element_Count##_random(void) { \
    simde_v128_t r; \
    simde_test_codegen_random_memory(sizeof(r), HEDLEY_REINTERPRET_CAST(uint8_t*, &r)); \
    return r; \
  }

#define SIMDE_TEST_WASM_SIMD128_GENERATE_FLOAT_FUNCS_(Element_Width, Element_Count) \
  static int \
  simde_test_wasm_f##Element_Width##x##Element_Count##_assert_equal_( \
      simde_v128_t a, simde_v128_t b, simde_float##Element_Width slop, \
      const char* filename, int line, const char* astr, const char* bstr) { \
    simde_float##Element_Width a_[sizeof(a) / sizeof(simde_float##Element_Width)]; \
    simde_float##Element_Width b_[sizeof(a) / sizeof(simde_float##Element_Width)]; \
    simde_wasm_v128_store(a_, a); \
    simde_wasm_v128_store(b_, b); \
    return simde_assert_equal_vf##Element_Width##_(sizeof(a_) / sizeof(a_[0]), a_, b_, slop, filename, line, astr, bstr); \
  } \
  \
  static void \
  simde_test_wasm_f##Element_Width##x##Element_Count##_write(int indent, simde_v128_t v, SimdeTestVecPos pos) { \
    simde_float##Element_Width v_[sizeof(v) / sizeof(simde_float##Element_Width)]; \
    simde_wasm_v128_store(v_, v); \
    simde_test_codegen_write_vf##Element_Width(indent, sizeof(v_) / sizeof(v_[0]), v_, pos); \
  } \
  \
  static simde_v128_t \
  simde_test_wasm_f##Element_Width##x##Element_Count##_random(simde_float##Element_Width min, simde_float##Element_Width max) { \
    simde_float##Element_Width r_[sizeof(simde_v128_t) / sizeof(simde_float##Element_Width)]; \
    simde_test_codegen_random_vf##Element_Width(sizeof(simde_v128_t) / sizeof(simde_float##Element_Width), r_, min, max); \
    return simde_wasm_v128_load(r_); \
  } \
  \
  static void \
  simde_test_wasm_f##Element_Width##x##Element_Count##_random_full( \
      size_t test_sets, size_t vectors_per_set, \
      simde_float##Element_Width v[HEDLEY_ARRAY_PARAM(test_sets * vectors_per_set * (sizeof(simde_v128_t) / sizeof(simde_float##Element_Width)))], \
      simde_float##Element_Width min, simde_float##Element_Width max, \
      SimdeTestVecFloatType vec_type) { \
    simde_test_codegen_random_vf##Element_Width##_full(test_sets, vectors_per_set, (sizeof(simde_v128_t) / sizeof(simde_float##Element_Width)), v, min, max, vec_type); \
  } \
  \
  static simde_v128_t \
  simde_test_wasm_f##Element_Width##x##Element_Count##_random_full_extract( \
      size_t vectors_per_set, \
      simde_float##Element_Width v[], \
      size_t set_n, size_t vec_n) { \
    return simde_wasm_v128_load(&(v[((vectors_per_set * set_n) + vec_n) * (sizeof(simde_v128_t) / sizeof(simde_float##Element_Width))])); \
  }

SIMDE_TEST_WASM_SIMD128_GENERATE_INT_FUNCS_( 8, 16)
SIMDE_TEST_WASM_SIMD128_GENERATE_INT_FUNCS_(16,  8)
SIMDE_TEST_WASM_SIMD128_GENERATE_INT_FUNCS_(32,  4)
SIMDE_TEST_WASM_SIMD128_GENERATE_INT_FUNCS_(64,  2)
SIMDE_TEST_WASM_SIMD128_GENERATE_FLOAT_FUNCS_(32,  4)
SIMDE_TEST_WASM_SIMD128_GENERATE_FLOAT_FUNCS_(64,  2)

#define simde_test_wasm_i8x16_assert_equal(a, b) do { if (simde_test_wasm_i8x16_assert_equal_(a, b, __FILE__, __LINE__, #a, #b)) return 1; } while (0)
#define simde_test_wasm_i16x8_assert_equal(a, b) do { if (simde_test_wasm_i16x8_assert_equal_(a, b, __FILE__, __LINE__, #a, #b)) return 1; } while (0)
#define simde_test_wasm_i32x4_assert_equal(a, b) do { if (simde_test_wasm_i32x4_assert_equal_(a, b, __FILE__, __LINE__, #a, #b)) return 1; } while (0)
#define simde_test_wasm_i64x2_assert_equal(a, b) do { if (simde_test_wasm_i64x2_assert_equal_(a, b, __FILE__, __LINE__, #a, #b)) return 1; } while (0)
#define simde_test_wasm_u8x16_assert_equal(a, b) do { if (simde_test_wasm_u8x16_assert_equal_(a, b, __FILE__, __LINE__, #a, #b)) return 1; } while (0)
#define simde_test_wasm_u16x8_assert_equal(a, b) do { if (simde_test_wasm_u16x8_assert_equal_(a, b, __FILE__, __LINE__, #a, #b)) return 1; } while (0)
#define simde_test_wasm_u32x4_assert_equal(a, b) do { if (simde_test_wasm_u32x4_assert_equal_(a, b, __FILE__, __LINE__, #a, #b)) return 1; } while (0)
#define simde_test_wasm_u64x2_assert_equal(a, b) do { if (simde_test_wasm_u64x2_assert_equal_(a, b, __FILE__, __LINE__, #a, #b)) return 1; } while (0)
#define simde_test_wasm_f32x4_assert_equal(a, b, precision) do { if (simde_test_wasm_f32x4_assert_equal_(a, b, simde_test_f32_precision_to_slop(precision), __FILE__, __LINE__, #a, #b)) return 1; } while (0)
#define simde_test_wasm_f64x2_assert_equal(a, b, precision) do { if (simde_test_wasm_f64x2_assert_equal_(a, b, simde_test_f64_precision_to_slop(precision), __FILE__, __LINE__, #a, #b)) return 1; } while (0)

/* HEDLEY_DIAGNOSTIC_DISABLE_UNUSED_FUNCTION */
HEDLEY_DIAGNOSTIC_POP

#endif /* !defined(SIMDE_TEST_WASM_TEST_SIMD128_H) */
