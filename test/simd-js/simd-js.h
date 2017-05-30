#if !defined(SIMDE__JS_INTERNAL_H)
#define SIMDE__JS_INTERNAL_H

#include "../test.h"

#if defined(SIMDE_NO_NATIVE)
#  define SIMD_JS_TEST_FUNC(type, name) \
  { (char*) "/" #name "/emul", test_simde_em_##type##_##name, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL }
#else
#  define SIMD_JS_TEST_FUNC(type, name) \
  { (char*) "/" #name, test_simde_em_##type##_##name, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL }
#endif
#define SIMD_JS_TEST_FUNC_CMP(type, name) \
  { (char*) "/" #name "/cmp", test_simde_em_##type##_##name, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL }

#define SIMDE_JS_DEFINE_TEST_EM_BINARY(T, op)				\
  static MunitResult                                                    \
  test_simde_em_##T##_##op(const MunitParameter params[], void* data) { \
    (void) params;                                                      \
    (void) data;                                                        \
                                                                        \
    T na, nb, nr;                                                       \
    simde_em_##T ea, eb, er;                                            \
                                                                        \
    munit_rand_memory(sizeof(na), (uint8_t*) &na);                      \
    munit_rand_memory(sizeof(nb), (uint8_t*) &nb);                      \
    memcpy(&ea, &na, sizeof(na));                                       \
    memcpy(&eb, &nb, sizeof(nb));                                       \
                                                                        \
    nr = emscripten_##T##_##op(na, nb);                                 \
    er = simde_em_##T##_##op(ea, eb);                                   \
                                                                        \
    simde_assert_##T(nr, ==, er);                                       \
                                                                        \
    return MUNIT_OK;                                                    \
  }

#define SIMDE_JS_DEFINE_TEST_EM_UNARY(T, op)				\
  static MunitResult                                                    \
  test_simde_em_##T##_##op(const MunitParameter params[], void* data) { \
    (void) params;                                                      \
    (void) data;                                                        \
                                                                        \
    T na, nr;                                                           \
    simde_em_##T ea, er;                                                \
                                                                        \
    munit_rand_memory(sizeof(na), (uint8_t*) &na);                      \
    memcpy(&ea, &na, sizeof(na));                                       \
                                                                        \
    nr = emscripten_##T##_##op(na);                                     \
    er = simde_em_##T##_##op(ea);                                       \
                                                                        \
    simde_assert_##T(nr, ==, er);                                       \
                                                                        \
    return MUNIT_OK;                                                    \
  }

#define SIMDE_JS_DEFINE_TEST_EM_COMPARE(T, BT, op)			\
  static MunitResult                                                    \
  test_simde_em_##T##_##op(const MunitParameter params[], void* data) { \
    (void) params;                                                      \
    (void) data;                                                        \
                                                                        \
    T na, nb;                                                           \
    simde_em_##T ea, eb;                                                \
    BT nr;                                                              \
    simde_em_##BT er;                                                   \
                                                                        \
    munit_rand_memory(sizeof(na), (uint8_t*) &na);                      \
    munit_rand_memory(sizeof(nb), (uint8_t*) &nb);                      \
    for (size_t i = 0 ; i < (sizeof(na) / sizeof(na[0])) ; i++)         \
      if (munit_rand_int_range(0, 1))                                   \
        nb[i] = na[i];                                                  \
                                                                        \
    memcpy(&ea, &na, sizeof(na));                                       \
    memcpy(&eb, &nb, sizeof(nb));                                       \
                                                                        \
    nr = emscripten_##T##_##op(na, nb);                                 \
    er = simde_em_##T##_##op(ea, eb);                                   \
                                                                        \
    simde_assert_##T(nr, ==, er);                                       \
                                                                        \
    return MUNIT_OK;                                                    \
  }

MunitSuite simde_simd_js_int32x4_test_suite;
MunitSuite simde_simd_js_int32x4_emul_test_suite;
MunitSuite simde_simd_js_int32x4_cmp_test_suite;

MunitSuite simde_simd_js_float32x4_test_suite;

#define simde_assert_int32x4(a, op, b) \
  simde_assert_int32v(4, (int32_t*) &(a), op, (int32_t*) &(b))

#define simde_assert_bool32x4(a, op, b) \
  simde_assert_uint32vx(4, (uint32_t*) &(a), op, (uint32_t*) &(b))

#endif
