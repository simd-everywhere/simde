#define SIMDE_TEST_ARM_SVE_INSN dup

#include "test-sve.h"
#include "../../../simde/arm/sve/dup.h"
#include "../../../simde/arm/sve/cmplt.h"

static int
test_simde_svdup_n_s8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const int8_t a = -INT8_C( 114);
  static const int8_t e[] =
    { -INT8_C( 114), -INT8_C( 114), -INT8_C( 114), -INT8_C( 114), -INT8_C( 114), -INT8_C( 114), -INT8_C( 114), -INT8_C( 114),
      -INT8_C( 114), -INT8_C( 114), -INT8_C( 114), -INT8_C( 114), -INT8_C( 114), -INT8_C( 114), -INT8_C( 114), -INT8_C( 114),
      -INT8_C( 114), -INT8_C( 114), -INT8_C( 114), -INT8_C( 114), -INT8_C( 114), -INT8_C( 114), -INT8_C( 114), -INT8_C( 114),
      -INT8_C( 114), -INT8_C( 114), -INT8_C( 114), -INT8_C( 114), -INT8_C( 114), -INT8_C( 114), -INT8_C( 114), -INT8_C( 114),
      -INT8_C( 114), -INT8_C( 114), -INT8_C( 114), -INT8_C( 114), -INT8_C( 114), -INT8_C( 114), -INT8_C( 114), -INT8_C( 114),
      -INT8_C( 114), -INT8_C( 114), -INT8_C( 114), -INT8_C( 114), -INT8_C( 114), -INT8_C( 114), -INT8_C( 114), -INT8_C( 114),
      -INT8_C( 114), -INT8_C( 114), -INT8_C( 114), -INT8_C( 114), -INT8_C( 114), -INT8_C( 114), -INT8_C( 114), -INT8_C( 114),
      -INT8_C( 114), -INT8_C( 114), -INT8_C( 114), -INT8_C( 114), -INT8_C( 114), -INT8_C( 114), -INT8_C( 114), -INT8_C( 114),
      -INT8_C( 114), -INT8_C( 114), -INT8_C( 114), -INT8_C( 114), -INT8_C( 114), -INT8_C( 114), -INT8_C( 114), -INT8_C( 114),
      -INT8_C( 114), -INT8_C( 114), -INT8_C( 114), -INT8_C( 114), -INT8_C( 114), -INT8_C( 114), -INT8_C( 114), -INT8_C( 114),
      -INT8_C( 114), -INT8_C( 114), -INT8_C( 114), -INT8_C( 114), -INT8_C( 114), -INT8_C( 114), -INT8_C( 114), -INT8_C( 114),
      -INT8_C( 114), -INT8_C( 114), -INT8_C( 114), -INT8_C( 114), -INT8_C( 114), -INT8_C( 114), -INT8_C( 114), -INT8_C( 114),
      -INT8_C( 114), -INT8_C( 114), -INT8_C( 114), -INT8_C( 114), -INT8_C( 114), -INT8_C( 114), -INT8_C( 114), -INT8_C( 114),
      -INT8_C( 114), -INT8_C( 114), -INT8_C( 114), -INT8_C( 114), -INT8_C( 114), -INT8_C( 114), -INT8_C( 114), -INT8_C( 114),
      -INT8_C( 114), -INT8_C( 114), -INT8_C( 114), -INT8_C( 114), -INT8_C( 114), -INT8_C( 114), -INT8_C( 114), -INT8_C( 114),
      -INT8_C( 114), -INT8_C( 114), -INT8_C( 114), -INT8_C( 114), -INT8_C( 114), -INT8_C( 114), -INT8_C( 114), -INT8_C( 114),
      -INT8_C( 114), -INT8_C( 114), -INT8_C( 114), -INT8_C( 114), -INT8_C( 114), -INT8_C( 114), -INT8_C( 114), -INT8_C( 114),
      -INT8_C( 114), -INT8_C( 114), -INT8_C( 114), -INT8_C( 114), -INT8_C( 114), -INT8_C( 114), -INT8_C( 114), -INT8_C( 114),
      -INT8_C( 114), -INT8_C( 114), -INT8_C( 114), -INT8_C( 114), -INT8_C( 114), -INT8_C( 114), -INT8_C( 114), -INT8_C( 114),
      -INT8_C( 114), -INT8_C( 114), -INT8_C( 114), -INT8_C( 114), -INT8_C( 114), -INT8_C( 114), -INT8_C( 114), -INT8_C( 114),
      -INT8_C( 114), -INT8_C( 114), -INT8_C( 114), -INT8_C( 114), -INT8_C( 114), -INT8_C( 114), -INT8_C( 114), -INT8_C( 114),
      -INT8_C( 114), -INT8_C( 114), -INT8_C( 114), -INT8_C( 114), -INT8_C( 114), -INT8_C( 114), -INT8_C( 114), -INT8_C( 114),
      -INT8_C( 114), -INT8_C( 114), -INT8_C( 114), -INT8_C( 114), -INT8_C( 114), -INT8_C( 114), -INT8_C( 114), -INT8_C( 114),
      -INT8_C( 114), -INT8_C( 114), -INT8_C( 114), -INT8_C( 114), -INT8_C( 114), -INT8_C( 114), -INT8_C( 114), -INT8_C( 114),
      -INT8_C( 114), -INT8_C( 114), -INT8_C( 114), -INT8_C( 114), -INT8_C( 114), -INT8_C( 114), -INT8_C( 114), -INT8_C( 114),
      -INT8_C( 114), -INT8_C( 114), -INT8_C( 114), -INT8_C( 114), -INT8_C( 114), -INT8_C( 114), -INT8_C( 114) };

  static int8_t r[sizeof(e) / sizeof(e[0])];
  static const int32_t len = HEDLEY_STATIC_CAST(int32_t, sizeof(e) / sizeof(e[0]));
  int32_t i = 0;
  simde_svbool_t pg = simde_svwhilelt_b8_s32(i, len);
  while (simde_svptest_first(simde_svptrue_b8(), pg)) {
    simde_svint8_t rv;

    rv = simde_svdup_n_s8(a);

    simde_svst1_s8(pg, &(r[i]), rv);

    i += simde_svcntb();
    pg = simde_svwhilelt_b8_s32(i, len);
  }

  simde_assert_equal_vi8(len, e, r);

  return 0;
#else
  int8_t a, e[1024];
  int32_t len;

  fputc('\n', stdout);

  len = simde_test_codegen_random_i16() & ((sizeof(e) / sizeof(e[0])) - 1);
  a = simde_test_codegen_random_i8();

  int32_t i = 0;
  simde_svbool_t pg = simde_svwhilelt_b8_s32(i, len);
  while (simde_svptest_first(simde_svptrue_b8(), pg)) {
    simde_svint8_t ev;

    ev = simde_svdup_n_s8(a);

    simde_svst1_s8(pg, &(e[i]), ev);

    i += simde_svcntb();
    pg = simde_svwhilelt_b8_s32(i, len);
  }

  simde_test_codegen_write_1i8(1, a);
  simde_test_codegen_write_1vi8(1, HEDLEY_STATIC_CAST(size_t, len), e);

  return 1;
#endif
}

static int
test_simde_svdup_n_s8_z (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const int8_t p[] =
    { -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
       INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
       INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
       INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
       INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
       INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
       INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
       INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
       INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
       INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
       INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1) };
  static const int8_t a = -INT8_C(  17);
  static const int8_t e[] =
    { -INT8_C(  17),  INT8_C(   0), -INT8_C(  17), -INT8_C(  17), -INT8_C(  17),  INT8_C(   0), -INT8_C(  17), -INT8_C(  17),
       INT8_C(   0), -INT8_C(  17), -INT8_C(  17), -INT8_C(  17), -INT8_C(  17), -INT8_C(  17), -INT8_C(  17), -INT8_C(  17),
      -INT8_C(  17), -INT8_C(  17), -INT8_C(  17), -INT8_C(  17),  INT8_C(   0), -INT8_C(  17), -INT8_C(  17),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0), -INT8_C(  17), -INT8_C(  17), -INT8_C(  17), -INT8_C(  17), -INT8_C(  17), -INT8_C(  17),
       INT8_C(   0), -INT8_C(  17), -INT8_C(  17), -INT8_C(  17), -INT8_C(  17), -INT8_C(  17),  INT8_C(   0), -INT8_C(  17),
      -INT8_C(  17), -INT8_C(  17),  INT8_C(   0),  INT8_C(   0), -INT8_C(  17), -INT8_C(  17), -INT8_C(  17), -INT8_C(  17),
      -INT8_C(  17), -INT8_C(  17), -INT8_C(  17),  INT8_C(   0), -INT8_C(  17), -INT8_C(  17), -INT8_C(  17), -INT8_C(  17),
      -INT8_C(  17),  INT8_C(   0), -INT8_C(  17), -INT8_C(  17),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(  17),
      -INT8_C(  17), -INT8_C(  17), -INT8_C(  17), -INT8_C(  17), -INT8_C(  17), -INT8_C(  17),  INT8_C(   0), -INT8_C(  17),
      -INT8_C(  17), -INT8_C(  17),  INT8_C(   0), -INT8_C(  17), -INT8_C(  17), -INT8_C(  17), -INT8_C(  17), -INT8_C(  17),
      -INT8_C(  17), -INT8_C(  17), -INT8_C(  17), -INT8_C(  17), -INT8_C(  17), -INT8_C(  17),  INT8_C(   0), -INT8_C(  17),
      -INT8_C(  17), -INT8_C(  17), -INT8_C(  17), -INT8_C(  17),  INT8_C(   0), -INT8_C(  17),  INT8_C(   0), -INT8_C(  17),
      -INT8_C(  17), -INT8_C(  17), -INT8_C(  17), -INT8_C(  17), -INT8_C(  17),  INT8_C(   0),  INT8_C(   0), -INT8_C(  17),
      -INT8_C(  17), -INT8_C(  17), -INT8_C(  17), -INT8_C(  17),  INT8_C(   0),  INT8_C(   0), -INT8_C(  17), -INT8_C(  17),
      -INT8_C(  17), -INT8_C(  17), -INT8_C(  17), -INT8_C(  17),  INT8_C(   0),  INT8_C(   0), -INT8_C(  17),  INT8_C(   0),
       INT8_C(   0), -INT8_C(  17), -INT8_C(  17), -INT8_C(  17), -INT8_C(  17),  INT8_C(   0),  INT8_C(   0), -INT8_C(  17),
       INT8_C(   0),  INT8_C(   0), -INT8_C(  17), -INT8_C(  17), -INT8_C(  17), -INT8_C(  17), -INT8_C(  17), -INT8_C(  17),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(  17), -INT8_C(  17), -INT8_C(  17), -INT8_C(  17), -INT8_C(  17),
      -INT8_C(  17), -INT8_C(  17),  INT8_C(   0), -INT8_C(  17), -INT8_C(  17), -INT8_C(  17), -INT8_C(  17), -INT8_C(  17),
      -INT8_C(  17), -INT8_C(  17), -INT8_C(  17), -INT8_C(  17), -INT8_C(  17),  INT8_C(   0), -INT8_C(  17), -INT8_C(  17),
      -INT8_C(  17), -INT8_C(  17), -INT8_C(  17),  INT8_C(   0), -INT8_C(  17),  INT8_C(   0), -INT8_C(  17), -INT8_C(  17),
      -INT8_C(  17),  INT8_C(   0), -INT8_C(  17),  INT8_C(   0),  INT8_C(   0), -INT8_C(  17), -INT8_C(  17), -INT8_C(  17),
      -INT8_C(  17),  INT8_C(   0),  INT8_C(   0), -INT8_C(  17), -INT8_C(  17), -INT8_C(  17), -INT8_C(  17), -INT8_C(  17),
      -INT8_C(  17), -INT8_C(  17),  INT8_C(   0), -INT8_C(  17),  INT8_C(   0), -INT8_C(  17),  INT8_C(   0), -INT8_C(  17),
      -INT8_C(  17), -INT8_C(  17), -INT8_C(  17), -INT8_C(  17),  INT8_C(   0), -INT8_C(  17), -INT8_C(  17),  INT8_C(   0),
      -INT8_C(  17),  INT8_C(   0), -INT8_C(  17), -INT8_C(  17), -INT8_C(  17), -INT8_C(  17), -INT8_C(  17),  INT8_C(   0),
      -INT8_C(  17), -INT8_C(  17), -INT8_C(  17), -INT8_C(  17), -INT8_C(  17), -INT8_C(  17), -INT8_C(  17), -INT8_C(  17),
      -INT8_C(  17), -INT8_C(  17),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(  17),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(  17), -INT8_C(  17),  INT8_C(   0), -INT8_C(  17), -INT8_C(  17), -INT8_C(  17), -INT8_C(  17), -INT8_C(  17),
       INT8_C(   0), -INT8_C(  17), -INT8_C(  17), -INT8_C(  17), -INT8_C(  17), -INT8_C(  17), -INT8_C(  17), -INT8_C(  17),
      -INT8_C(  17), -INT8_C(  17),  INT8_C(   0), -INT8_C(  17), -INT8_C(  17), -INT8_C(  17), -INT8_C(  17), -INT8_C(  17),
      -INT8_C(  17), -INT8_C(  17),  INT8_C(   0),  INT8_C(   0), -INT8_C(  17), -INT8_C(  17), -INT8_C(  17), -INT8_C(  17),
      -INT8_C(  17), -INT8_C(  17), -INT8_C(  17),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(  17), -INT8_C(  17),
       INT8_C(   0), -INT8_C(  17),  INT8_C(   0),  INT8_C(   0), -INT8_C(  17),  INT8_C(   0),  INT8_C(   0), -INT8_C(  17),
      -INT8_C(  17), -INT8_C(  17), -INT8_C(  17), -INT8_C(  17), -INT8_C(  17),  INT8_C(   0), -INT8_C(  17), -INT8_C(  17),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(  17), -INT8_C(  17),  INT8_C(   0), -INT8_C(  17), -INT8_C(  17),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(  17), -INT8_C(  17),  INT8_C(   0),  INT8_C(   0), -INT8_C(  17),
       INT8_C(   0), -INT8_C(  17),  INT8_C(   0),  INT8_C(   0), -INT8_C(  17), -INT8_C(  17),  INT8_C(   0), -INT8_C(  17),
      -INT8_C(  17), -INT8_C(  17), -INT8_C(  17),  INT8_C(   0),  INT8_C(   0), -INT8_C(  17),  INT8_C(   0), -INT8_C(  17),
       INT8_C(   0), -INT8_C(  17), -INT8_C(  17), -INT8_C(  17), -INT8_C(  17), -INT8_C(  17), -INT8_C(  17),  INT8_C(   0),
      -INT8_C(  17), -INT8_C(  17), -INT8_C(  17), -INT8_C(  17), -INT8_C(  17),  INT8_C(   0), -INT8_C(  17), -INT8_C(  17),
      -INT8_C(  17),  INT8_C(   0), -INT8_C(  17), -INT8_C(  17), -INT8_C(  17),  INT8_C(   0), -INT8_C(  17), -INT8_C(  17),
       INT8_C(   0), -INT8_C(  17), -INT8_C(  17), -INT8_C(  17), -INT8_C(  17),  INT8_C(   0),  INT8_C(   0), -INT8_C(  17),
      -INT8_C(  17),  INT8_C(   0),  INT8_C(   0), -INT8_C(  17), -INT8_C(  17), -INT8_C(  17),  INT8_C(   0), -INT8_C(  17),
      -INT8_C(  17), -INT8_C(  17), -INT8_C(  17), -INT8_C(  17), -INT8_C(  17), -INT8_C(  17), -INT8_C(  17), -INT8_C(  17),
      -INT8_C(  17), -INT8_C(  17), -INT8_C(  17), -INT8_C(  17), -INT8_C(  17), -INT8_C(  17), -INT8_C(  17), -INT8_C(  17),
      -INT8_C(  17), -INT8_C(  17), -INT8_C(  17),  INT8_C(   0),  INT8_C(   0), -INT8_C(  17),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(  17), -INT8_C(  17),  INT8_C(   0), -INT8_C(  17), -INT8_C(  17), -INT8_C(  17), -INT8_C(  17),  INT8_C(   0),
       INT8_C(   0), -INT8_C(  17),  INT8_C(   0),  INT8_C(   0), -INT8_C(  17), -INT8_C(  17), -INT8_C(  17), -INT8_C(  17),
      -INT8_C(  17),  INT8_C(   0), -INT8_C(  17),  INT8_C(   0),  INT8_C(   0), -INT8_C(  17),  INT8_C(   0), -INT8_C(  17),
      -INT8_C(  17), -INT8_C(  17),  INT8_C(   0), -INT8_C(  17),  INT8_C(   0), -INT8_C(  17), -INT8_C(  17), -INT8_C(  17),
      -INT8_C(  17), -INT8_C(  17), -INT8_C(  17), -INT8_C(  17), -INT8_C(  17),  INT8_C(   0), -INT8_C(  17), -INT8_C(  17),
      -INT8_C(  17), -INT8_C(  17),  INT8_C(   0), -INT8_C(  17), -INT8_C(  17), -INT8_C(  17), -INT8_C(  17), -INT8_C(  17),
      -INT8_C(  17), -INT8_C(  17), -INT8_C(  17),  INT8_C(   0), -INT8_C(  17),  INT8_C(   0),  INT8_C(   0), -INT8_C(  17),
      -INT8_C(  17), -INT8_C(  17), -INT8_C(  17), -INT8_C(  17), -INT8_C(  17),  INT8_C(   0), -INT8_C(  17), -INT8_C(  17),
       INT8_C(   0), -INT8_C(  17),  INT8_C(   0), -INT8_C(  17), -INT8_C(  17), -INT8_C(  17),  INT8_C(   0), -INT8_C(  17),
      -INT8_C(  17), -INT8_C(  17), -INT8_C(  17), -INT8_C(  17), -INT8_C(  17),  INT8_C(   0), -INT8_C(  17),  INT8_C(   0),
      -INT8_C(  17), -INT8_C(  17), -INT8_C(  17), -INT8_C(  17), -INT8_C(  17), -INT8_C(  17),  INT8_C(   0), -INT8_C(  17),
      -INT8_C(  17),  INT8_C(   0), -INT8_C(  17), -INT8_C(  17), -INT8_C(  17),  INT8_C(   0), -INT8_C(  17), -INT8_C(  17),
      -INT8_C(  17), -INT8_C(  17), -INT8_C(  17),  INT8_C(   0), -INT8_C(  17), -INT8_C(  17),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0), -INT8_C(  17), -INT8_C(  17), -INT8_C(  17), -INT8_C(  17),  INT8_C(   0),  INT8_C(   0), -INT8_C(  17),
      -INT8_C(  17), -INT8_C(  17), -INT8_C(  17), -INT8_C(  17), -INT8_C(  17), -INT8_C(  17), -INT8_C(  17), -INT8_C(  17),
      -INT8_C(  17),  INT8_C(   0), -INT8_C(  17),  INT8_C(   0), -INT8_C(  17), -INT8_C(  17),  INT8_C(   0), -INT8_C(  17),
       INT8_C(   0), -INT8_C(  17),  INT8_C(   0),  INT8_C(   0), -INT8_C(  17), -INT8_C(  17), -INT8_C(  17), -INT8_C(  17),
      -INT8_C(  17), -INT8_C(  17), -INT8_C(  17), -INT8_C(  17),  INT8_C(   0), -INT8_C(  17), -INT8_C(  17), -INT8_C(  17),
      -INT8_C(  17), -INT8_C(  17), -INT8_C(  17),  INT8_C(   0),  INT8_C(   0), -INT8_C(  17),  INT8_C(   0), -INT8_C(  17),
      -INT8_C(  17), -INT8_C(  17), -INT8_C(  17), -INT8_C(  17), -INT8_C(  17), -INT8_C(  17), -INT8_C(  17), -INT8_C(  17),
      -INT8_C(  17), -INT8_C(  17), -INT8_C(  17), -INT8_C(  17), -INT8_C(  17),  INT8_C(   0), -INT8_C(  17), -INT8_C(  17),
      -INT8_C(  17), -INT8_C(  17), -INT8_C(  17), -INT8_C(  17), -INT8_C(  17), -INT8_C(  17), -INT8_C(  17),  INT8_C(   0),
      -INT8_C(  17),  INT8_C(   0), -INT8_C(  17), -INT8_C(  17), -INT8_C(  17), -INT8_C(  17), -INT8_C(  17), -INT8_C(  17),
      -INT8_C(  17), -INT8_C(  17), -INT8_C(  17), -INT8_C(  17), -INT8_C(  17), -INT8_C(  17), -INT8_C(  17),  INT8_C(   0),
       INT8_C(   0), -INT8_C(  17),  INT8_C(   0), -INT8_C(  17), -INT8_C(  17), -INT8_C(  17), -INT8_C(  17), -INT8_C(  17),
      -INT8_C(  17),  INT8_C(   0), -INT8_C(  17), -INT8_C(  17), -INT8_C(  17),  INT8_C(   0),  INT8_C(   0), -INT8_C(  17),
      -INT8_C(  17), -INT8_C(  17), -INT8_C(  17), -INT8_C(  17), -INT8_C(  17), -INT8_C(  17), -INT8_C(  17), -INT8_C(  17),
      -INT8_C(  17),  INT8_C(   0), -INT8_C(  17),  INT8_C(   0),  INT8_C(   0), -INT8_C(  17), -INT8_C(  17), -INT8_C(  17),
       INT8_C(   0), -INT8_C(  17), -INT8_C(  17),  INT8_C(   0), -INT8_C(  17), -INT8_C(  17), -INT8_C(  17), -INT8_C(  17),
       INT8_C(   0), -INT8_C(  17), -INT8_C(  17), -INT8_C(  17), -INT8_C(  17), -INT8_C(  17),  INT8_C(   0), -INT8_C(  17),
       INT8_C(   0),  INT8_C(   0), -INT8_C(  17),  INT8_C(   0),  INT8_C(   0), -INT8_C(  17),  INT8_C(   0), -INT8_C(  17),
      -INT8_C(  17),  INT8_C(   0),  INT8_C(   0), -INT8_C(  17), -INT8_C(  17),  INT8_C(   0), -INT8_C(  17),  INT8_C(   0),
       INT8_C(   0), -INT8_C(  17), -INT8_C(  17), -INT8_C(  17), -INT8_C(  17), -INT8_C(  17), -INT8_C(  17), -INT8_C(  17),
      -INT8_C(  17), -INT8_C(  17),  INT8_C(   0), -INT8_C(  17), -INT8_C(  17), -INT8_C(  17), -INT8_C(  17), -INT8_C(  17),
      -INT8_C(  17), -INT8_C(  17), -INT8_C(  17),  INT8_C(   0), -INT8_C(  17),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(  17), -INT8_C(  17), -INT8_C(  17), -INT8_C(  17), -INT8_C(  17), -INT8_C(  17),  INT8_C(   0), -INT8_C(  17),
      -INT8_C(  17), -INT8_C(  17), -INT8_C(  17), -INT8_C(  17), -INT8_C(  17), -INT8_C(  17), -INT8_C(  17), -INT8_C(  17),
       INT8_C(   0), -INT8_C(  17),  INT8_C(   0), -INT8_C(  17),  INT8_C(   0), -INT8_C(  17),  INT8_C(   0), -INT8_C(  17),
      -INT8_C(  17),  INT8_C(   0), -INT8_C(  17),  INT8_C(   0), -INT8_C(  17),  INT8_C(   0), -INT8_C(  17), -INT8_C(  17),
      -INT8_C(  17), -INT8_C(  17), -INT8_C(  17),  INT8_C(   0), -INT8_C(  17), -INT8_C(  17), -INT8_C(  17),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0), -INT8_C(  17),  INT8_C(   0), -INT8_C(  17), -INT8_C(  17), -INT8_C(  17),  INT8_C(   0),
      -INT8_C(  17), -INT8_C(  17), -INT8_C(  17),  INT8_C(   0), -INT8_C(  17),  INT8_C(   0), -INT8_C(  17),  INT8_C(   0),
      -INT8_C(  17), -INT8_C(  17), -INT8_C(  17), -INT8_C(  17),  INT8_C(   0), -INT8_C(  17),  INT8_C(   0), -INT8_C(  17),
      -INT8_C(  17), -INT8_C(  17), -INT8_C(  17),  INT8_C(   0),  INT8_C(   0), -INT8_C(  17), -INT8_C(  17), -INT8_C(  17),
       INT8_C(   0),  INT8_C(   0), -INT8_C(  17),  INT8_C(   0), -INT8_C(  17), -INT8_C(  17), -INT8_C(  17), -INT8_C(  17),
      -INT8_C(  17), -INT8_C(  17),  INT8_C(   0),  INT8_C(   0), -INT8_C(  17),  INT8_C(   0), -INT8_C(  17), -INT8_C(  17),
       INT8_C(   0),  INT8_C(   0), -INT8_C(  17), -INT8_C(  17), -INT8_C(  17), -INT8_C(  17), -INT8_C(  17),  INT8_C(   0),
      -INT8_C(  17), -INT8_C(  17), -INT8_C(  17),  INT8_C(   0), -INT8_C(  17), -INT8_C(  17), -INT8_C(  17),  INT8_C(   0),
       INT8_C(   0), -INT8_C(  17), -INT8_C(  17), -INT8_C(  17),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(  17),
      -INT8_C(  17), -INT8_C(  17), -INT8_C(  17), -INT8_C(  17), -INT8_C(  17), -INT8_C(  17), -INT8_C(  17),  INT8_C(   0),
      -INT8_C(  17),  INT8_C(   0), -INT8_C(  17), -INT8_C(  17),  INT8_C(   0),  INT8_C(   0), -INT8_C(  17),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0), -INT8_C(  17), -INT8_C(  17),  INT8_C(   0), -INT8_C(  17), -INT8_C(  17), -INT8_C(  17),
      -INT8_C(  17), -INT8_C(  17), -INT8_C(  17),  INT8_C(   0), -INT8_C(  17), -INT8_C(  17),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(  17), -INT8_C(  17),  INT8_C(   0), -INT8_C(  17),  INT8_C(   0), -INT8_C(  17),  INT8_C(   0), -INT8_C(  17),
       INT8_C(   0),  INT8_C(   0), -INT8_C(  17), -INT8_C(  17), -INT8_C(  17), -INT8_C(  17), -INT8_C(  17), -INT8_C(  17),
      -INT8_C(  17), -INT8_C(  17), -INT8_C(  17), -INT8_C(  17), -INT8_C(  17), -INT8_C(  17), -INT8_C(  17), -INT8_C(  17),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(  17), -INT8_C(  17), -INT8_C(  17),
       INT8_C(   0), -INT8_C(  17), -INT8_C(  17), -INT8_C(  17),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(  17),
      -INT8_C(  17), -INT8_C(  17),  INT8_C(   0),  INT8_C(   0), -INT8_C(  17), -INT8_C(  17),  INT8_C(   0), -INT8_C(  17),
       INT8_C(   0), -INT8_C(  17), -INT8_C(  17), -INT8_C(  17), -INT8_C(  17),  INT8_C(   0), -INT8_C(  17), -INT8_C(  17),
      -INT8_C(  17),  INT8_C(   0),  INT8_C(   0), -INT8_C(  17), -INT8_C(  17), -INT8_C(  17), -INT8_C(  17), -INT8_C(  17),
      -INT8_C(  17), -INT8_C(  17), -INT8_C(  17),  INT8_C(   0),  INT8_C(   0), -INT8_C(  17), -INT8_C(  17), -INT8_C(  17),
      -INT8_C(  17), -INT8_C(  17), -INT8_C(  17),  INT8_C(   0), -INT8_C(  17), -INT8_C(  17), -INT8_C(  17), -INT8_C(  17),
      -INT8_C(  17), -INT8_C(  17), -INT8_C(  17), -INT8_C(  17), -INT8_C(  17), -INT8_C(  17), -INT8_C(  17), -INT8_C(  17),
      -INT8_C(  17), -INT8_C(  17), -INT8_C(  17), -INT8_C(  17), -INT8_C(  17), -INT8_C(  17),  INT8_C(   0), -INT8_C(  17),
      -INT8_C(  17),  INT8_C(   0), -INT8_C(  17),  INT8_C(   0), -INT8_C(  17), -INT8_C(  17), -INT8_C(  17), -INT8_C(  17),
       INT8_C(   0),  INT8_C(   0), -INT8_C(  17), -INT8_C(  17),  INT8_C(   0), -INT8_C(  17), -INT8_C(  17), -INT8_C(  17),
      -INT8_C(  17), -INT8_C(  17),  INT8_C(   0),  INT8_C(   0), -INT8_C(  17), -INT8_C(  17), -INT8_C(  17) };

  static int8_t r[sizeof(e) / sizeof(e[0])];
  static const int32_t len = HEDLEY_STATIC_CAST(int32_t, sizeof(e) / sizeof(e[0]));
  int32_t i = 0;
  simde_svbool_t pg = simde_svwhilelt_b8_s32(i, len);
  while (simde_svptest_first(simde_svptrue_b8(), pg)) {
    simde_svint8_t rv;
    simde_svbool_t pv;

    pv = simde_svcmplt_s8(pg, simde_svld1_s8(pg, &(p[i])), simde_svdup_n_s8(INT8_C(0)));
    rv = simde_svdup_n_s8_z(pv, a);

    simde_svst1_s8(pg, &(r[i]), rv);

    i += simde_svcntb();
    pg = simde_svwhilelt_b8_s32(i, len);
  }

  simde_assert_equal_vi8(len, e, r);

  return 0;
#else
  int8_t a, p[1024], e[1024];
  int32_t len;

  fputc('\n', stdout);

  len = simde_test_codegen_random_i16() & ((sizeof(e) / sizeof(e[0])) - 1);
  simde_test_codegen_random_memory(sizeof(p), HEDLEY_REINTERPRET_CAST(uint8_t*, p));
  a = simde_test_codegen_random_i8();

  int32_t i = 0;
  simde_svbool_t pg = simde_svwhilelt_b8_s32(i, len);
  while (simde_svptest_first(simde_svptrue_b8(), pg)) {
    simde_svint8_t ev;
    simde_svbool_t pv;

    pv = simde_svcmplt_s8(pg, simde_svld1_s8(pg, &(p[i])), simde_svdup_n_s8(0));
    ev = simde_svdup_n_s8_z(pv, a);

    simde_svst1_s8(pg, &(e[i]), ev);
    simde_svst1_s8(pg, &(p[i]), simde_svdup_n_s8_z(pv, ~INT8_C(0)));

    i += simde_svcntb();
    pg = simde_svwhilelt_b8_s32(i, len);
  }

  simde_test_codegen_write_1vi8(1, HEDLEY_STATIC_CAST(size_t, len), p);
  simde_test_codegen_write_1i8(1, a);
  simde_test_codegen_write_1vi8(1, HEDLEY_STATIC_CAST(size_t, len), e);

  return 1;
#endif
}

static int
test_simde_svdup_n_s8_m (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const int8_t p[] =
    { -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
       INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
       INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
       INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
       INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
       INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
       INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
       INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
       INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
       INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0) };
  static const int8_t a[] =
    { -INT8_C(  66), -INT8_C(   8),  INT8_C(  79),  INT8_C( 102), -INT8_C(   2),  INT8_C(  94), -INT8_C(  19), -INT8_C(  87),
       INT8_C(  20),  INT8_C( 115), -INT8_C(  97), -INT8_C(  10),  INT8_C(  49),  INT8_C(  77),  INT8_C(  23), -INT8_C(  37),
       INT8_C( 126), -INT8_C(  89),  INT8_C(  54), -INT8_C(  14),  INT8_C(  55), -INT8_C( 102), -INT8_C(  49), -INT8_C(  70),
      -INT8_C(   2),  INT8_C( 100),  INT8_C(  32),  INT8_C(  81),  INT8_C(  37), -INT8_C(  30),  INT8_C(  78), -INT8_C(  29),
      -INT8_C(  38), -INT8_C(  99),  INT8_C(  73), -INT8_C(  40), -INT8_C(   4),  INT8_C(  54), -INT8_C( 127),  INT8_C(  16),
      -INT8_C(  87),  INT8_C(  33),  INT8_C(   7), -INT8_C(  38),  INT8_C( 110),  INT8_C(  30), -INT8_C(  74), -INT8_C(  20),
      -INT8_C(  59), -INT8_C(  20), -INT8_C(  34), -INT8_C(   3), -INT8_C( 122), -INT8_C(  82), -INT8_C(  73), -INT8_C( 123),
       INT8_C(  18), -INT8_C(  41), -INT8_C(  42),  INT8_C(  55), -INT8_C(  71),  INT8_C(  36),  INT8_C(  26), -INT8_C( 109),
      -INT8_C(  62),  INT8_C(  99),  INT8_C( 108), -INT8_C(  66), -INT8_C( 103), -INT8_C(  19), -INT8_C(  50),  INT8_C(  66),
       INT8_C(  14), -INT8_C(  43),  INT8_C(  29),  INT8_C( 125), -INT8_C(  12), -INT8_C(  45),  INT8_C( 105), -INT8_C(  71),
      -INT8_C(  65),  INT8_C(  72), -INT8_C(  74),  INT8_C(  70), -INT8_C(  10),  INT8_C( 109), -INT8_C(  53),  INT8_C(   8),
       INT8_C(  69), -INT8_C(  95),  INT8_C(  64), -INT8_C(   2), -INT8_C(  58),  INT8_C(  90), -INT8_C( 110), -INT8_C( 120),
      -INT8_C(  66), -INT8_C(   2),  INT8_C(  70),  INT8_C(  87), -INT8_C(  21),  INT8_C(  20), -INT8_C( 102), -INT8_C(   6),
      -INT8_C(  22), -INT8_C(  73),  INT8_C( 119), -INT8_C(  34), -INT8_C( 118), -INT8_C(  32), -INT8_C( 105),  INT8_C(  73),
       INT8_C(  40),  INT8_C(  78), -INT8_C( 113),  INT8_C(  30), -INT8_C(  69),  INT8_C(  90),  INT8_C(  39),  INT8_C(   0),
      -INT8_C(   4),  INT8_C( 103), -INT8_C(   1), -INT8_C(  62), -INT8_C(  63), -INT8_C( 111),  INT8_C(  74),      INT8_MAX,
      -INT8_C( 113), -INT8_C( 112), -INT8_C(  41),  INT8_C( 122), -INT8_C(  92),  INT8_C( 113),  INT8_C( 116), -INT8_C( 114),
       INT8_C(  40), -INT8_C(  21),  INT8_C( 108), -INT8_C(  78), -INT8_C(  52),  INT8_C(   4), -INT8_C(   5), -INT8_C(  12),
       INT8_C(  82), -INT8_C( 117),  INT8_C(  19),  INT8_C(  13), -INT8_C(  27),  INT8_C(  58),  INT8_C(  14), -INT8_C(  31),
      -INT8_C(  95),  INT8_C(  13), -INT8_C(  93),  INT8_C(  98), -INT8_C(  98), -INT8_C(  19), -INT8_C(  30),  INT8_C(  45),
       INT8_C( 125), -INT8_C(  71), -INT8_C(  89),  INT8_C(  34),  INT8_C(  42),  INT8_C(  28), -INT8_C(  80),  INT8_C(  82),
       INT8_C(   7),  INT8_C(  29),  INT8_C(   4), -INT8_C(  45),  INT8_C(  33), -INT8_C(   1), -INT8_C(  56),  INT8_C( 115),
      -INT8_C( 118), -INT8_C(  37),      INT8_MIN,  INT8_C( 112),  INT8_C(  21), -INT8_C( 114),  INT8_C(  81), -INT8_C(  74),
      -INT8_C( 101), -INT8_C(  11),  INT8_C(  24),  INT8_C(  57), -INT8_C(  30), -INT8_C(   6),  INT8_C( 102),  INT8_C(  96),
      -INT8_C(  77),  INT8_C(  14), -INT8_C( 126), -INT8_C(  35),  INT8_C(  42),  INT8_C(  50),  INT8_C(  47),  INT8_C(  49),
       INT8_C(  79),  INT8_C(  51),  INT8_C(   5),  INT8_C( 112),  INT8_C(  51), -INT8_C(  51), -INT8_C(  29), -INT8_C(  67),
      -INT8_C(  88),  INT8_C( 100),  INT8_C(  45), -INT8_C(  67), -INT8_C(  14),      INT8_MAX,  INT8_C( 115), -INT8_C( 114),
       INT8_C( 116), -INT8_C( 117), -INT8_C(  57),  INT8_C(  86), -INT8_C( 122),  INT8_C(  46), -INT8_C(  74),  INT8_C(  57),
       INT8_C(  60),  INT8_C(  56),  INT8_C(  23),  INT8_C( 102),  INT8_C( 107),  INT8_C(  70), -INT8_C( 105), -INT8_C(  70),
       INT8_C( 122), -INT8_C( 100),  INT8_C(  43), -INT8_C(  83),  INT8_C( 105),  INT8_C(  14),  INT8_C( 106),  INT8_C(  17),
       INT8_C( 114), -INT8_C( 104), -INT8_C(  50),  INT8_C( 101),  INT8_C(  23),  INT8_C(  65), -INT8_C(  13), -INT8_C( 117),
      -INT8_C(  51), -INT8_C(  70), -INT8_C(  31),  INT8_C(  83), -INT8_C(  24), -INT8_C( 104), -INT8_C( 116),  INT8_C(  36),
      -INT8_C(  48), -INT8_C(  93), -INT8_C( 118),  INT8_C(  59), -INT8_C(  22),  INT8_C(  34), -INT8_C(  10),  INT8_C( 100),
      -INT8_C(  66),  INT8_C(  33),  INT8_C(  17),  INT8_C(  40),  INT8_C(  47),  INT8_C( 123),  INT8_C(  57), -INT8_C(  94),
       INT8_C(  19),  INT8_C(   8),  INT8_C(   7),  INT8_C(  42),  INT8_C(  73), -INT8_C(   6), -INT8_C(  75),  INT8_C(  22),
      -INT8_C(  76), -INT8_C( 105),  INT8_C( 105), -INT8_C(  99),  INT8_C(  47), -INT8_C(  10), -INT8_C(  63), -INT8_C(   1),
      -INT8_C( 103),  INT8_C(  76),  INT8_C(  59), -INT8_C( 125),  INT8_C( 110),  INT8_C(  49), -INT8_C(  25),  INT8_C(  44),
       INT8_C(  82), -INT8_C(   8),  INT8_C(  84), -INT8_C( 127),  INT8_C( 116), -INT8_C( 114),  INT8_C(  35), -INT8_C( 121),
      -INT8_C( 106),  INT8_C(  42), -INT8_C(  78), -INT8_C(  33),  INT8_C(  36),  INT8_C( 103), -INT8_C(  10), -INT8_C(  39),
      -INT8_C(   2),  INT8_C(  95),  INT8_C( 118),  INT8_C(  45),  INT8_C(  85),  INT8_C(  55),  INT8_C(  45), -INT8_C(  17),
      -INT8_C( 125),  INT8_C( 104),  INT8_C( 114), -INT8_C(  15), -INT8_C( 103),  INT8_C(  90),  INT8_C(  30), -INT8_C(  21),
       INT8_C(  82),  INT8_C( 114),  INT8_C( 108), -INT8_C(  58),  INT8_C(   0), -INT8_C( 112),  INT8_C(  78), -INT8_C( 106),
      -INT8_C(  70),  INT8_C(   0),  INT8_C( 118), -INT8_C(  33),  INT8_C( 103),  INT8_C( 108), -INT8_C(  72),  INT8_C( 102),
      -INT8_C(  53),  INT8_C(  46), -INT8_C( 109),  INT8_C(  33),  INT8_C( 101), -INT8_C(  64),  INT8_C(  16), -INT8_C(  23),
       INT8_C(  40), -INT8_C( 126), -INT8_C(  38), -INT8_C(  63), -INT8_C(  36), -INT8_C(   8), -INT8_C(  84),  INT8_C(  47),
       INT8_C( 107),  INT8_C(  25), -INT8_C(  11),  INT8_C( 107), -INT8_C(  87),  INT8_C(  67),  INT8_C(   2),  INT8_C(  99),
       INT8_C(  67),  INT8_C( 120),  INT8_C(  66), -INT8_C(  85), -INT8_C(  28), -INT8_C(   6),  INT8_C(  17), -INT8_C(  81),
       INT8_C(  40), -INT8_C(  92), -INT8_C(  48), -INT8_C( 114),  INT8_C( 101), -INT8_C(  32),  INT8_C( 119), -INT8_C( 115),
       INT8_C(  99),  INT8_C(  81),  INT8_C(  79),  INT8_C(  63),  INT8_C(  74), -INT8_C(   5),  INT8_C( 110), -INT8_C(  75),
       INT8_C(  20),  INT8_C( 100),  INT8_C(  32), -INT8_C(  67), -INT8_C(  89),  INT8_C(  34),  INT8_C(  33), -INT8_C(  21),
      -INT8_C( 102),  INT8_C(  99), -INT8_C( 106),  INT8_C( 126),  INT8_C(  94), -INT8_C(  89),  INT8_C(  46), -INT8_C( 122),
       INT8_C(  75), -INT8_C(   2),  INT8_C(  20), -INT8_C(  80), -INT8_C(  33), -INT8_C( 117),  INT8_C(  62),  INT8_C(  66),
      -INT8_C(  35), -INT8_C( 115), -INT8_C( 127),  INT8_C(  39), -INT8_C( 120), -INT8_C(  16), -INT8_C(  36), -INT8_C(  99),
       INT8_C(  84), -INT8_C(   4),  INT8_C(  90), -INT8_C(   5),  INT8_C(  31),  INT8_C( 123), -INT8_C(  26), -INT8_C(  71),
      -INT8_C(  33),  INT8_C( 124),  INT8_C(  56),  INT8_C(  61),  INT8_C(  35),  INT8_C( 102), -INT8_C(  61),  INT8_C( 111),
       INT8_C( 100), -INT8_C(  40),  INT8_C(  31),  INT8_C(  67),  INT8_C(  99),  INT8_C(  93), -INT8_C( 123),  INT8_C(  64),
      -INT8_C(  22),  INT8_C(   7),  INT8_C( 103),  INT8_C( 115), -INT8_C(   9),  INT8_C(  67),  INT8_C(  16),  INT8_C(  75),
       INT8_C(  64),  INT8_C( 106),  INT8_C(  70),  INT8_C(  95), -INT8_C(  26),  INT8_C(  45),  INT8_C(  24), -INT8_C(  59),
      -INT8_C(  87),  INT8_C(  80),  INT8_C(   2), -INT8_C(  51), -INT8_C(  74), -INT8_C(  59),  INT8_C(  60),  INT8_C(  27),
      -INT8_C(  99),  INT8_C(  91),  INT8_C(  94),  INT8_C(   1), -INT8_C(  71), -INT8_C(  28),  INT8_C(  65), -INT8_C(  93),
      -INT8_C(  21), -INT8_C(  87),  INT8_C(  22), -INT8_C(  30), -INT8_C(  20),  INT8_C(  38),  INT8_C(  45),  INT8_C(  44),
      -INT8_C( 111),  INT8_C( 115), -INT8_C( 117),  INT8_C( 119), -INT8_C(  96), -INT8_C(  92),  INT8_C(  60),  INT8_C(  74),
      -INT8_C(  12),  INT8_C(  62),  INT8_C(  23), -INT8_C(  85),  INT8_C(   3),  INT8_C(  83), -INT8_C(  58), -INT8_C(  95),
      -INT8_C(  82),  INT8_C(  36), -INT8_C(  94),  INT8_C( 103),  INT8_C(   8), -INT8_C(  29),  INT8_C(  11), -INT8_C(  13),
      -INT8_C( 116),  INT8_C(  33), -INT8_C(  43),  INT8_C( 121),  INT8_C(  72),  INT8_C(   2), -INT8_C(  91), -INT8_C(  39),
       INT8_C( 118),  INT8_C(  49),  INT8_C(  80),  INT8_C(  22), -INT8_C(  43), -INT8_C( 116),  INT8_C(  96), -INT8_C(  55),
      -INT8_C(  54),  INT8_C( 119),  INT8_C( 116), -INT8_C(  51), -INT8_C(  54),  INT8_C(  58),  INT8_C( 110),  INT8_C( 121),
       INT8_C(  95),  INT8_C(  16), -INT8_C(  32),  INT8_C( 103), -INT8_C(  12), -INT8_C(  21),  INT8_C(  91),      INT8_MIN,
       INT8_C(  13),  INT8_C(  48), -INT8_C(   7),  INT8_C(  85),  INT8_C(  51), -INT8_C(  97),  INT8_C(  46), -INT8_C(  87),
      -INT8_C(  48),  INT8_C( 126), -INT8_C(  65), -INT8_C(  91),  INT8_C(  10),  INT8_C(  32),  INT8_C( 110), -INT8_C(  44),
      -INT8_C( 105), -INT8_C(  29), -INT8_C(  95),  INT8_C(  98),  INT8_C(  29),  INT8_C(  16), -INT8_C(  37),  INT8_C( 124),
       INT8_C(  32), -INT8_C(  69), -INT8_C(  28),  INT8_C(  20), -INT8_C(  89),  INT8_C(  63), -INT8_C( 107), -INT8_C(  76),
       INT8_C( 111), -INT8_C( 114),  INT8_C(   9), -INT8_C(  94),  INT8_C(  45),  INT8_C(  55),  INT8_C(  75), -INT8_C(   3),
      -INT8_C(  75),  INT8_C(  11), -INT8_C(  94), -INT8_C(  65),  INT8_C(  43),  INT8_C(  17), -INT8_C( 109), -INT8_C(  62),
      -INT8_C(  12),  INT8_C(  52),  INT8_C(  36),  INT8_C(  17),  INT8_C(  68), -INT8_C(   1), -INT8_C( 114),  INT8_C( 101),
      -INT8_C(  69),  INT8_C( 114),  INT8_C( 121),  INT8_C(  98), -INT8_C(  79),  INT8_C(  14),  INT8_C(  22),  INT8_C(  32),
      -INT8_C(  99),  INT8_C(  31), -INT8_C(  61), -INT8_C(  54),  INT8_C(  86),  INT8_C(  14), -INT8_C(  56),  INT8_C(  11),
       INT8_C(  25),  INT8_C( 106), -INT8_C(  54),  INT8_C(  68),  INT8_C( 123),  INT8_C(  93),  INT8_C(   7),  INT8_C( 111),
      -INT8_C( 111),  INT8_C(  43), -INT8_C( 127), -INT8_C(  42),  INT8_C(  43),  INT8_C(  15),  INT8_C(  59), -INT8_C(  26),
      -INT8_C( 127), -INT8_C(  76),  INT8_C(  72),  INT8_C(  50), -INT8_C(  61),  INT8_C(  94),  INT8_C(  82),  INT8_C(  96),
       INT8_C( 125),  INT8_C(  21),  INT8_C(  42), -INT8_C(  45),  INT8_C(  36), -INT8_C(  14), -INT8_C(  34),  INT8_C(  61),
       INT8_C(  93), -INT8_C(  88), -INT8_C( 126), -INT8_C(  40),  INT8_C(   5), -INT8_C( 119),  INT8_C(  72), -INT8_C( 106),
      -INT8_C(  76), -INT8_C(  55),  INT8_C( 108), -INT8_C(  33), -INT8_C(  40), -INT8_C(  89), -INT8_C(  59),  INT8_C(  89),
       INT8_C(  92),  INT8_C(  13), -INT8_C( 117),  INT8_C(  31),  INT8_C( 107), -INT8_C(  35),      INT8_MAX, -INT8_C(  24),
      -INT8_C(  13), -INT8_C(  87), -INT8_C(  69),  INT8_C(  23), -INT8_C( 100), -INT8_C( 103),  INT8_C(  84), -INT8_C(   7),
       INT8_C(  65), -INT8_C(  42), -INT8_C(  47),  INT8_C(  70),  INT8_C(  95),  INT8_C(  25), -INT8_C(  35),  INT8_C(  20),
      -INT8_C(  30),  INT8_C(  73), -INT8_C(  13), -INT8_C(  70), -INT8_C(  15), -INT8_C(  71),  INT8_C(  19),  INT8_C(  77),
      -INT8_C(  58), -INT8_C(  98),  INT8_C( 108),  INT8_C(  50),  INT8_C( 124), -INT8_C(  21),  INT8_C(  26),  INT8_C( 111),
      -INT8_C( 108), -INT8_C(  42), -INT8_C( 122),  INT8_C(  48),  INT8_C( 111), -INT8_C(  38),  INT8_C(  41), -INT8_C(  79),
      -INT8_C(  79), -INT8_C(   5), -INT8_C(   9),  INT8_C(  16),  INT8_C(  20), -INT8_C(  44),  INT8_C(  36), -INT8_C(   9),
       INT8_C(  30),  INT8_C(  24), -INT8_C(  79),  INT8_C(  15), -INT8_C(  47), -INT8_C(  59),  INT8_C(  92), -INT8_C( 105),
       INT8_C(  99), -INT8_C(  56), -INT8_C(  55), -INT8_C(  33), -INT8_C(  77), -INT8_C(  28),  INT8_C(  78),  INT8_C(  71),
      -INT8_C(  70), -INT8_C(  44),  INT8_C( 120),  INT8_C(  41), -INT8_C(  81), -INT8_C(  95), -INT8_C(  38),  INT8_C(  96),
      -INT8_C( 100), -INT8_C(  46),  INT8_C( 112), -INT8_C(  79), -INT8_C(  90), -INT8_C( 107), -INT8_C(  88), -INT8_C(  60),
      -INT8_C(  83),  INT8_C(  89), -INT8_C(  45),  INT8_C( 126),  INT8_C(  30),  INT8_C(  47),  INT8_C(  21), -INT8_C( 126),
      -INT8_C(   9), -INT8_C(  33),  INT8_C(  97), -INT8_C(  86), -INT8_C(  61), -INT8_C(  80), -INT8_C(  14),  INT8_C( 125),
      -INT8_C( 124),  INT8_C( 106), -INT8_C(  90),  INT8_C(  51),  INT8_C(  11), -INT8_C( 127), -INT8_C( 109), -INT8_C(  88),
       INT8_C(  83),  INT8_C(   4),  INT8_C(  89), -INT8_C(   7), -INT8_C( 103),  INT8_C(   1), -INT8_C(  66),  INT8_C(  70),
       INT8_C(  90), -INT8_C( 111), -INT8_C(  60),  INT8_C( 121), -INT8_C(  63), -INT8_C(  39), -INT8_C(   5), -INT8_C(  72),
      -INT8_C(  72),  INT8_C(  92),  INT8_C(  99),  INT8_C( 123),  INT8_C(  12),  INT8_C(  85), -INT8_C(   8), -INT8_C( 111),
      -INT8_C(  65), -INT8_C(  97), -INT8_C(  60), -INT8_C(  54),  INT8_C(  32),  INT8_C(  88),  INT8_C( 114),  INT8_C( 115),
       INT8_C(  92), -INT8_C(  53),  INT8_C( 108), -INT8_C(  11), -INT8_C(  52),  INT8_C(  42),  INT8_C(  59) };
  static const int8_t b = -INT8_C(  21);
  static const int8_t e[] =
    { -INT8_C(  21), -INT8_C(  21), -INT8_C(  21),  INT8_C( 102), -INT8_C(   2),  INT8_C(  94), -INT8_C(  19), -INT8_C(  21),
      -INT8_C(  21),  INT8_C( 115), -INT8_C(  97), -INT8_C(  10),  INT8_C(  49),  INT8_C(  77), -INT8_C(  21), -INT8_C(  37),
       INT8_C( 126), -INT8_C(  21),  INT8_C(  54), -INT8_C(  14), -INT8_C(  21), -INT8_C(  21), -INT8_C(  21), -INT8_C(  70),
      -INT8_C(  21), -INT8_C(  21),  INT8_C(  32), -INT8_C(  21), -INT8_C(  21), -INT8_C(  21), -INT8_C(  21), -INT8_C(  21),
      -INT8_C(  21), -INT8_C(  99), -INT8_C(  21), -INT8_C(  21), -INT8_C(  21),  INT8_C(  54), -INT8_C(  21),  INT8_C(  16),
      -INT8_C(  87),  INT8_C(  33), -INT8_C(  21), -INT8_C(  21),  INT8_C( 110),  INT8_C(  30), -INT8_C(  21), -INT8_C(  20),
      -INT8_C(  59), -INT8_C(  20), -INT8_C(  21), -INT8_C(   3), -INT8_C( 122), -INT8_C(  21), -INT8_C(  21), -INT8_C(  21),
       INT8_C(  18), -INT8_C(  41), -INT8_C(  42),  INT8_C(  55), -INT8_C(  21), -INT8_C(  21), -INT8_C(  21), -INT8_C(  21),
      -INT8_C(  62), -INT8_C(  21), -INT8_C(  21), -INT8_C(  66), -INT8_C(  21), -INT8_C(  19), -INT8_C(  21),  INT8_C(  66),
       INT8_C(  14), -INT8_C(  43), -INT8_C(  21), -INT8_C(  21), -INT8_C(  21), -INT8_C(  21),  INT8_C( 105), -INT8_C(  71),
      -INT8_C(  21), -INT8_C(  21), -INT8_C(  21), -INT8_C(  21), -INT8_C(  10),  INT8_C( 109), -INT8_C(  21), -INT8_C(  21),
       INT8_C(  69), -INT8_C(  21), -INT8_C(  21), -INT8_C(   2), -INT8_C(  21), -INT8_C(  21), -INT8_C(  21), -INT8_C( 120),
      -INT8_C(  66), -INT8_C(   2), -INT8_C(  21), -INT8_C(  21), -INT8_C(  21),  INT8_C(  20), -INT8_C( 102), -INT8_C(  21),
      -INT8_C(  21), -INT8_C(  73), -INT8_C(  21), -INT8_C(  21), -INT8_C(  21), -INT8_C(  21), -INT8_C( 105), -INT8_C(  21),
       INT8_C(  40), -INT8_C(  21), -INT8_C( 113), -INT8_C(  21), -INT8_C(  21), -INT8_C(  21),  INT8_C(  39),  INT8_C(   0),
      -INT8_C(  21),  INT8_C( 103), -INT8_C(   1), -INT8_C(  21), -INT8_C(  63), -INT8_C(  21),  INT8_C(  74),      INT8_MAX,
      -INT8_C( 113), -INT8_C(  21), -INT8_C(  41), -INT8_C(  21), -INT8_C(  92),  INT8_C( 113), -INT8_C(  21), -INT8_C(  21),
       INT8_C(  40), -INT8_C(  21), -INT8_C(  21), -INT8_C(  78), -INT8_C(  21), -INT8_C(  21), -INT8_C(  21), -INT8_C(  12),
       INT8_C(  82), -INT8_C( 117), -INT8_C(  21),  INT8_C(  13), -INT8_C(  27),  INT8_C(  58),  INT8_C(  14), -INT8_C(  31),
      -INT8_C(  21),  INT8_C(  13), -INT8_C(  21), -INT8_C(  21), -INT8_C(  98), -INT8_C(  21), -INT8_C(  21),  INT8_C(  45),
      -INT8_C(  21), -INT8_C(  71), -INT8_C(  89), -INT8_C(  21),  INT8_C(  42), -INT8_C(  21), -INT8_C(  21), -INT8_C(  21),
      -INT8_C(  21),  INT8_C(  29), -INT8_C(  21), -INT8_C(  21),  INT8_C(  33), -INT8_C(  21), -INT8_C(  21),  INT8_C( 115),
      -INT8_C(  21), -INT8_C(  37), -INT8_C(  21), -INT8_C(  21), -INT8_C(  21), -INT8_C(  21), -INT8_C(  21), -INT8_C(  74),
      -INT8_C( 101), -INT8_C(  21), -INT8_C(  21),  INT8_C(  57), -INT8_C(  30), -INT8_C(  21), -INT8_C(  21), -INT8_C(  21),
      -INT8_C(  21),  INT8_C(  14), -INT8_C(  21), -INT8_C(  35), -INT8_C(  21),  INT8_C(  50),  INT8_C(  47),  INT8_C(  49),
       INT8_C(  79),  INT8_C(  51), -INT8_C(  21),  INT8_C( 112), -INT8_C(  21), -INT8_C(  21), -INT8_C(  21), -INT8_C(  67),
      -INT8_C(  21),  INT8_C( 100), -INT8_C(  21), -INT8_C(  21), -INT8_C(  14), -INT8_C(  21), -INT8_C(  21), -INT8_C( 114),
       INT8_C( 116), -INT8_C(  21), -INT8_C(  21), -INT8_C(  21), -INT8_C( 122), -INT8_C(  21), -INT8_C(  21),  INT8_C(  57),
      -INT8_C(  21),  INT8_C(  56), -INT8_C(  21), -INT8_C(  21),  INT8_C( 107),  INT8_C(  70), -INT8_C(  21), -INT8_C(  21),
       INT8_C( 122), -INT8_C(  21), -INT8_C(  21), -INT8_C(  21), -INT8_C(  21), -INT8_C(  21), -INT8_C(  21), -INT8_C(  21),
       INT8_C( 114), -INT8_C(  21), -INT8_C(  50),  INT8_C( 101), -INT8_C(  21), -INT8_C(  21), -INT8_C(  21), -INT8_C( 117),
      -INT8_C(  51), -INT8_C(  70), -INT8_C(  21), -INT8_C(  21), -INT8_C(  24), -INT8_C(  21), -INT8_C( 116), -INT8_C(  21),
      -INT8_C(  21), -INT8_C(  93), -INT8_C( 118),  INT8_C(  59), -INT8_C(  22),  INT8_C(  34), -INT8_C(  21),  INT8_C( 100),
      -INT8_C(  66), -INT8_C(  21),  INT8_C(  17),  INT8_C(  40),  INT8_C(  47), -INT8_C(  21), -INT8_C(  21), -INT8_C(  94),
      -INT8_C(  21), -INT8_C(  21), -INT8_C(  21),  INT8_C(  42),  INT8_C(  73), -INT8_C(   6), -INT8_C(  75), -INT8_C(  21),
      -INT8_C(  21), -INT8_C( 105), -INT8_C(  21), -INT8_C(  21), -INT8_C(  21), -INT8_C(  10), -INT8_C(  21), -INT8_C(  21),
      -INT8_C(  21),  INT8_C(  76),  INT8_C(  59), -INT8_C( 125), -INT8_C(  21),  INT8_C(  49), -INT8_C(  21),  INT8_C(  44),
      -INT8_C(  21), -INT8_C(  21),  INT8_C(  84), -INT8_C( 127),  INT8_C( 116), -INT8_C(  21),  INT8_C(  35), -INT8_C( 121),
      -INT8_C( 106),  INT8_C(  42), -INT8_C(  78), -INT8_C(  21),  INT8_C(  36), -INT8_C(  21), -INT8_C(  21), -INT8_C(  21),
      -INT8_C(  21), -INT8_C(  21), -INT8_C(  21), -INT8_C(  21),  INT8_C(  85),  INT8_C(  55), -INT8_C(  21), -INT8_C(  21),
      -INT8_C(  21), -INT8_C(  21), -INT8_C(  21), -INT8_C(  15), -INT8_C( 103),  INT8_C(  90),  INT8_C(  30), -INT8_C(  21),
      -INT8_C(  21), -INT8_C(  21), -INT8_C(  21), -INT8_C(  58),  INT8_C(   0), -INT8_C( 112),  INT8_C(  78), -INT8_C(  21),
      -INT8_C(  70), -INT8_C(  21), -INT8_C(  21), -INT8_C(  21), -INT8_C(  21),  INT8_C( 108), -INT8_C(  72), -INT8_C(  21),
      -INT8_C(  21), -INT8_C(  21), -INT8_C( 109),  INT8_C(  33),  INT8_C( 101), -INT8_C(  64), -INT8_C(  21), -INT8_C(  21),
       INT8_C(  40), -INT8_C(  21), -INT8_C(  38), -INT8_C(  63), -INT8_C(  21), -INT8_C(   8), -INT8_C(  84), -INT8_C(  21),
       INT8_C( 107), -INT8_C(  21), -INT8_C(  11),  INT8_C( 107), -INT8_C(  87),  INT8_C(  67),  INT8_C(   2), -INT8_C(  21),
       INT8_C(  67), -INT8_C(  21),  INT8_C(  66), -INT8_C(  21), -INT8_C(  21), -INT8_C(  21),  INT8_C(  17), -INT8_C(  21),
      -INT8_C(  21), -INT8_C(  21), -INT8_C(  21), -INT8_C( 114),  INT8_C( 101), -INT8_C(  21), -INT8_C(  21), -INT8_C(  21),
       INT8_C(  99), -INT8_C(  21), -INT8_C(  21), -INT8_C(  21),  INT8_C(  74), -INT8_C(  21), -INT8_C(  21), -INT8_C(  21),
      -INT8_C(  21), -INT8_C(  21), -INT8_C(  21), -INT8_C(  67), -INT8_C(  89), -INT8_C(  21), -INT8_C(  21), -INT8_C(  21),
      -INT8_C(  21),  INT8_C(  99), -INT8_C( 106), -INT8_C(  21),  INT8_C(  94), -INT8_C(  21),  INT8_C(  46), -INT8_C(  21),
      -INT8_C(  21), -INT8_C(   2), -INT8_C(  21), -INT8_C(  21), -INT8_C(  21), -INT8_C(  21),  INT8_C(  62),  INT8_C(  66),
      -INT8_C(  21), -INT8_C( 115), -INT8_C( 127),  INT8_C(  39), -INT8_C( 120), -INT8_C(  21), -INT8_C(  21), -INT8_C(  21),
       INT8_C(  84), -INT8_C(  21),  INT8_C(  90), -INT8_C(  21), -INT8_C(  21),  INT8_C( 123), -INT8_C(  26), -INT8_C(  71),
      -INT8_C(  33),  INT8_C( 124), -INT8_C(  21),  INT8_C(  61),  INT8_C(  35),  INT8_C( 102), -INT8_C(  61), -INT8_C(  21),
      -INT8_C(  21), -INT8_C(  40), -INT8_C(  21),  INT8_C(  67),  INT8_C(  99),  INT8_C(  93), -INT8_C(  21), -INT8_C(  21),
      -INT8_C(  22), -INT8_C(  21),  INT8_C( 103), -INT8_C(  21), -INT8_C(   9),  INT8_C(  67), -INT8_C(  21), -INT8_C(  21),
      -INT8_C(  21), -INT8_C(  21),  INT8_C(  70), -INT8_C(  21), -INT8_C(  21),  INT8_C(  45), -INT8_C(  21), -INT8_C(  59),
      -INT8_C(  21), -INT8_C(  21), -INT8_C(  21), -INT8_C(  21), -INT8_C(  21), -INT8_C(  21), -INT8_C(  21),  INT8_C(  27),
      -INT8_C(  99),  INT8_C(  91), -INT8_C(  21),  INT8_C(   1), -INT8_C(  71), -INT8_C(  21), -INT8_C(  21), -INT8_C(  21),
      -INT8_C(  21), -INT8_C(  87),  INT8_C(  22), -INT8_C(  30), -INT8_C(  20),  INT8_C(  38),  INT8_C(  45),  INT8_C(  44),
      -INT8_C(  21), -INT8_C(  21), -INT8_C(  21), -INT8_C(  21), -INT8_C(  21), -INT8_C(  92), -INT8_C(  21), -INT8_C(  21),
      -INT8_C(  12),  INT8_C(  62),  INT8_C(  23), -INT8_C(  21),  INT8_C(   3), -INT8_C(  21), -INT8_C(  58), -INT8_C(  95),
      -INT8_C(  82),  INT8_C(  36), -INT8_C(  94), -INT8_C(  21), -INT8_C(  21), -INT8_C(  29),  INT8_C(  11), -INT8_C(  13),
      -INT8_C( 116), -INT8_C(  21), -INT8_C(  21), -INT8_C(  21), -INT8_C(  21), -INT8_C(  21), -INT8_C(  21), -INT8_C(  21),
       INT8_C( 118),  INT8_C(  49),  INT8_C(  80),  INT8_C(  22), -INT8_C(  43), -INT8_C( 116), -INT8_C(  21), -INT8_C(  21),
      -INT8_C(  54),  INT8_C( 119),  INT8_C( 116), -INT8_C(  51), -INT8_C(  54), -INT8_C(  21), -INT8_C(  21),  INT8_C( 121),
       INT8_C(  95), -INT8_C(  21), -INT8_C(  21),  INT8_C( 103), -INT8_C(  21), -INT8_C(  21),  INT8_C(  91),      INT8_MIN,
       INT8_C(  13), -INT8_C(  21), -INT8_C(  21),  INT8_C(  85),  INT8_C(  51), -INT8_C(  97), -INT8_C(  21), -INT8_C(  21),
      -INT8_C(  21),  INT8_C( 126), -INT8_C(  21), -INT8_C(  91),  INT8_C(  10), -INT8_C(  21), -INT8_C(  21), -INT8_C(  21),
      -INT8_C(  21), -INT8_C(  29), -INT8_C(  21), -INT8_C(  21), -INT8_C(  21), -INT8_C(  21), -INT8_C(  37),  INT8_C( 124),
       INT8_C(  32), -INT8_C(  69), -INT8_C(  28),  INT8_C(  20), -INT8_C(  89), -INT8_C(  21), -INT8_C(  21), -INT8_C(  21),
       INT8_C( 111), -INT8_C( 114), -INT8_C(  21), -INT8_C(  21), -INT8_C(  21), -INT8_C(  21), -INT8_C(  21), -INT8_C(   3),
      -INT8_C(  21), -INT8_C(  21), -INT8_C(  21), -INT8_C(  65),  INT8_C(  43),  INT8_C(  17), -INT8_C(  21), -INT8_C(  62),
      -INT8_C(  12), -INT8_C(  21),  INT8_C(  36),  INT8_C(  17),  INT8_C(  68), -INT8_C(   1), -INT8_C( 114), -INT8_C(  21),
      -INT8_C(  21), -INT8_C(  21), -INT8_C(  21), -INT8_C(  21), -INT8_C(  79),  INT8_C(  14),  INT8_C(  22), -INT8_C(  21),
      -INT8_C(  21),  INT8_C(  31), -INT8_C(  61), -INT8_C(  21),  INT8_C(  86),  INT8_C(  14), -INT8_C(  56), -INT8_C(  21),
      -INT8_C(  21), -INT8_C(  21), -INT8_C(  54),  INT8_C(  68), -INT8_C(  21), -INT8_C(  21),  INT8_C(   7),  INT8_C( 111),
      -INT8_C(  21), -INT8_C(  21), -INT8_C( 127), -INT8_C(  21),  INT8_C(  43), -INT8_C(  21),  INT8_C(  59), -INT8_C(  21),
      -INT8_C( 127), -INT8_C(  76),  INT8_C(  72), -INT8_C(  21), -INT8_C(  61), -INT8_C(  21),  INT8_C(  82),  INT8_C(  96),
       INT8_C( 125), -INT8_C(  21), -INT8_C(  21), -INT8_C(  45), -INT8_C(  21), -INT8_C(  21), -INT8_C(  34), -INT8_C(  21),
       INT8_C(  93), -INT8_C(  88), -INT8_C(  21), -INT8_C(  40),  INT8_C(   5), -INT8_C(  21),  INT8_C(  72), -INT8_C(  21),
      -INT8_C(  21), -INT8_C(  21), -INT8_C(  21), -INT8_C(  21), -INT8_C(  40), -INT8_C(  89), -INT8_C(  59), -INT8_C(  21),
       INT8_C(  92), -INT8_C(  21), -INT8_C( 117), -INT8_C(  21),  INT8_C( 107), -INT8_C(  21), -INT8_C(  21), -INT8_C(  21),
      -INT8_C(  21), -INT8_C(  21), -INT8_C(  21), -INT8_C(  21), -INT8_C( 100), -INT8_C(  21),  INT8_C(  84), -INT8_C(  21),
       INT8_C(  65), -INT8_C(  42), -INT8_C(  47),  INT8_C(  70),  INT8_C(  95),  INT8_C(  25), -INT8_C(  35), -INT8_C(  21),
      -INT8_C(  21), -INT8_C(  21), -INT8_C(  13), -INT8_C(  70), -INT8_C(  21), -INT8_C(  71), -INT8_C(  21),  INT8_C(  77),
      -INT8_C(  21), -INT8_C(  98), -INT8_C(  21),  INT8_C(  50),  INT8_C( 124), -INT8_C(  21), -INT8_C(  21), -INT8_C(  21),
      -INT8_C( 108), -INT8_C(  42), -INT8_C(  21), -INT8_C(  21),  INT8_C( 111), -INT8_C(  38), -INT8_C(  21), -INT8_C(  21),
      -INT8_C(  79), -INT8_C(  21), -INT8_C(   9),  INT8_C(  16),  INT8_C(  20), -INT8_C(  44),  INT8_C(  36), -INT8_C(  21),
       INT8_C(  30),  INT8_C(  24), -INT8_C(  79),  INT8_C(  15), -INT8_C(  47), -INT8_C(  21),  INT8_C(  92), -INT8_C( 105),
       INT8_C(  99), -INT8_C(  56), -INT8_C(  55), -INT8_C(  33), -INT8_C(  77), -INT8_C(  28), -INT8_C(  21),  INT8_C(  71),
      -INT8_C(  21), -INT8_C(  21),  INT8_C( 120),  INT8_C(  41), -INT8_C(  21), -INT8_C(  21), -INT8_C(  21),  INT8_C(  96),
      -INT8_C( 100), -INT8_C(  21), -INT8_C(  21), -INT8_C(  79), -INT8_C(  90), -INT8_C(  21), -INT8_C(  88), -INT8_C(  21),
      -INT8_C(  21), -INT8_C(  21), -INT8_C(  21),  INT8_C( 126),  INT8_C(  30),  INT8_C(  47), -INT8_C(  21), -INT8_C( 126),
      -INT8_C(  21), -INT8_C(  33),  INT8_C(  97), -INT8_C(  21), -INT8_C(  61), -INT8_C(  80), -INT8_C(  14), -INT8_C(  21),
      -INT8_C( 124),  INT8_C( 106), -INT8_C(  90),  INT8_C(  51),  INT8_C(  11), -INT8_C(  21), -INT8_C( 109), -INT8_C(  88),
      -INT8_C(  21), -INT8_C(  21), -INT8_C(  21), -INT8_C(  21), -INT8_C(  21),  INT8_C(   1), -INT8_C(  21),  INT8_C(  70),
       INT8_C(  90), -INT8_C( 111), -INT8_C(  21),  INT8_C( 121), -INT8_C(  21), -INT8_C(  39), -INT8_C(  21), -INT8_C(  21),
      -INT8_C(  72),  INT8_C(  92),  INT8_C(  99), -INT8_C(  21), -INT8_C(  21), -INT8_C(  21), -INT8_C(  21), -INT8_C(  21),
      -INT8_C(  21), -INT8_C(  21), -INT8_C(  21), -INT8_C(  54),  INT8_C(  32),  INT8_C(  88), -INT8_C(  21),  INT8_C( 115),
       INT8_C(  92), -INT8_C(  21),  INT8_C( 108), -INT8_C(  21), -INT8_C(  21), -INT8_C(  21),  INT8_C(  59) };

  static int8_t r[sizeof(e) / sizeof(e[0])];
  static const int32_t len = HEDLEY_STATIC_CAST(int32_t, sizeof(e) / sizeof(e[0]));
  int32_t i = 0;
  simde_svbool_t pg = simde_svwhilelt_b8_s32(i, len);
  while (simde_svptest_first(simde_svptrue_b8(), pg)) {
    simde_svint8_t
      rv,
      av = simde_svld1_s8(pg, &(a[i]));
    simde_svbool_t pv;

    pv = simde_svcmplt_s8(pg, simde_svld1_s8(pg, &(p[i])), simde_svdup_n_s8(INT8_C(0)));
    rv = simde_svdup_n_s8_m(av, pv, b);

    simde_svst1_s8(pg, &(r[i]), rv);

    i += simde_svcntb();
    pg = simde_svwhilelt_b8_s32(i, len);
  }

  simde_assert_equal_vi8(len, e, r);

  return 0;
#else
  int8_t p[1024], a[1024], b, e[1024];
  int32_t len = simde_test_arm_sve_random_length(sizeof(e), sizeof(e[0]));

  fputc('\n', stdout);

  simde_test_codegen_random_memory(sizeof(p), HEDLEY_REINTERPRET_CAST(uint8_t*, p));
  simde_test_codegen_random_memory(sizeof(a), HEDLEY_REINTERPRET_CAST(uint8_t*, a));
  b = simde_test_codegen_random_i8();

  int32_t i = 0;
  simde_svbool_t pg = simde_svwhilelt_b8_s32(i, len);
  while (simde_svptest_first(simde_svptrue_b8(), pg)) {
    simde_svint8_t av, ev;
    simde_svbool_t pv;

    pv = simde_svcmplt_s8(pg, simde_svld1_s8(pg, &(p[i])), simde_svdup_n_s8(0));
    av = simde_svld1_s8(pg, &(a[i]));

    ev = simde_svdup_n_s8_m(av, pv, b);

    simde_svst1_s8(pg, &(e[i]), ev);
    simde_svst1_s8(pg, &(p[i]), simde_svdup_n_s8_z(pv, ~INT8_C(0)));

    i += simde_svcntb();
    pg = simde_svwhilelt_b8_s32(i, len);
  }

  simde_test_codegen_write_1vi8(1, HEDLEY_STATIC_CAST(size_t, len), p);
  simde_test_codegen_write_1vi8(1, HEDLEY_STATIC_CAST(size_t, len), a);
  simde_test_codegen_write_1i8(1, b);
  simde_test_codegen_write_1vi8(1, HEDLEY_STATIC_CAST(size_t, len), e);

  return 1;
#endif
}

static int
test_simde_svdup_n_s16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const int16_t a = -INT16_C(  61);
  static const int16_t e[] =
    { -INT16_C(    61), -INT16_C(    61), -INT16_C(    61), -INT16_C(    61), -INT16_C(    61), -INT16_C(    61), -INT16_C(    61), -INT16_C(    61),
      -INT16_C(    61), -INT16_C(    61), -INT16_C(    61), -INT16_C(    61), -INT16_C(    61), -INT16_C(    61), -INT16_C(    61), -INT16_C(    61),
      -INT16_C(    61), -INT16_C(    61), -INT16_C(    61), -INT16_C(    61), -INT16_C(    61), -INT16_C(    61), -INT16_C(    61), -INT16_C(    61),
      -INT16_C(    61), -INT16_C(    61), -INT16_C(    61), -INT16_C(    61), -INT16_C(    61), -INT16_C(    61), -INT16_C(    61), -INT16_C(    61),
      -INT16_C(    61), -INT16_C(    61), -INT16_C(    61), -INT16_C(    61), -INT16_C(    61), -INT16_C(    61), -INT16_C(    61), -INT16_C(    61),
      -INT16_C(    61), -INT16_C(    61), -INT16_C(    61), -INT16_C(    61), -INT16_C(    61), -INT16_C(    61), -INT16_C(    61), -INT16_C(    61),
      -INT16_C(    61), -INT16_C(    61), -INT16_C(    61), -INT16_C(    61), -INT16_C(    61), -INT16_C(    61), -INT16_C(    61), -INT16_C(    61),
      -INT16_C(    61), -INT16_C(    61), -INT16_C(    61), -INT16_C(    61), -INT16_C(    61), -INT16_C(    61), -INT16_C(    61), -INT16_C(    61),
      -INT16_C(    61), -INT16_C(    61), -INT16_C(    61), -INT16_C(    61), -INT16_C(    61), -INT16_C(    61), -INT16_C(    61), -INT16_C(    61),
      -INT16_C(    61), -INT16_C(    61), -INT16_C(    61), -INT16_C(    61), -INT16_C(    61), -INT16_C(    61), -INT16_C(    61), -INT16_C(    61),
      -INT16_C(    61), -INT16_C(    61), -INT16_C(    61), -INT16_C(    61), -INT16_C(    61), -INT16_C(    61), -INT16_C(    61), -INT16_C(    61),
      -INT16_C(    61), -INT16_C(    61), -INT16_C(    61), -INT16_C(    61), -INT16_C(    61), -INT16_C(    61), -INT16_C(    61), -INT16_C(    61),
      -INT16_C(    61), -INT16_C(    61), -INT16_C(    61), -INT16_C(    61), -INT16_C(    61), -INT16_C(    61), -INT16_C(    61), -INT16_C(    61),
      -INT16_C(    61), -INT16_C(    61), -INT16_C(    61), -INT16_C(    61), -INT16_C(    61), -INT16_C(    61), -INT16_C(    61), -INT16_C(    61),
      -INT16_C(    61), -INT16_C(    61), -INT16_C(    61), -INT16_C(    61), -INT16_C(    61), -INT16_C(    61), -INT16_C(    61), -INT16_C(    61),
      -INT16_C(    61), -INT16_C(    61), -INT16_C(    61), -INT16_C(    61), -INT16_C(    61), -INT16_C(    61), -INT16_C(    61), -INT16_C(    61),
      -INT16_C(    61), -INT16_C(    61), -INT16_C(    61), -INT16_C(    61), -INT16_C(    61), -INT16_C(    61), -INT16_C(    61), -INT16_C(    61),
      -INT16_C(    61), -INT16_C(    61), -INT16_C(    61), -INT16_C(    61), -INT16_C(    61), -INT16_C(    61), -INT16_C(    61), -INT16_C(    61),
      -INT16_C(    61), -INT16_C(    61), -INT16_C(    61), -INT16_C(    61), -INT16_C(    61), -INT16_C(    61), -INT16_C(    61), -INT16_C(    61),
      -INT16_C(    61), -INT16_C(    61), -INT16_C(    61), -INT16_C(    61), -INT16_C(    61), -INT16_C(    61), -INT16_C(    61), -INT16_C(    61),
      -INT16_C(    61), -INT16_C(    61), -INT16_C(    61), -INT16_C(    61), -INT16_C(    61), -INT16_C(    61), -INT16_C(    61), -INT16_C(    61),
      -INT16_C(    61), -INT16_C(    61), -INT16_C(    61), -INT16_C(    61), -INT16_C(    61), -INT16_C(    61), -INT16_C(    61), -INT16_C(    61),
      -INT16_C(    61), -INT16_C(    61), -INT16_C(    61), -INT16_C(    61), -INT16_C(    61), -INT16_C(    61), -INT16_C(    61), -INT16_C(    61),
      -INT16_C(    61), -INT16_C(    61), -INT16_C(    61), -INT16_C(    61), -INT16_C(    61), -INT16_C(    61), -INT16_C(    61), -INT16_C(    61),
      -INT16_C(    61), -INT16_C(    61), -INT16_C(    61), -INT16_C(    61), -INT16_C(    61), -INT16_C(    61), -INT16_C(    61), -INT16_C(    61),
      -INT16_C(    61), -INT16_C(    61), -INT16_C(    61), -INT16_C(    61), -INT16_C(    61), -INT16_C(    61), -INT16_C(    61), -INT16_C(    61),
      -INT16_C(    61), -INT16_C(    61), -INT16_C(    61), -INT16_C(    61), -INT16_C(    61), -INT16_C(    61), -INT16_C(    61), -INT16_C(    61),
      -INT16_C(    61), -INT16_C(    61), -INT16_C(    61), -INT16_C(    61), -INT16_C(    61), -INT16_C(    61), -INT16_C(    61), -INT16_C(    61),
      -INT16_C(    61), -INT16_C(    61), -INT16_C(    61), -INT16_C(    61), -INT16_C(    61), -INT16_C(    61), -INT16_C(    61), -INT16_C(    61),
      -INT16_C(    61), -INT16_C(    61), -INT16_C(    61), -INT16_C(    61), -INT16_C(    61), -INT16_C(    61), -INT16_C(    61), -INT16_C(    61),
      -INT16_C(    61), -INT16_C(    61), -INT16_C(    61), -INT16_C(    61), -INT16_C(    61), -INT16_C(    61), -INT16_C(    61), -INT16_C(    61),
      -INT16_C(    61), -INT16_C(    61), -INT16_C(    61), -INT16_C(    61), -INT16_C(    61), -INT16_C(    61), -INT16_C(    61), -INT16_C(    61),
      -INT16_C(    61), -INT16_C(    61), -INT16_C(    61), -INT16_C(    61), -INT16_C(    61), -INT16_C(    61), -INT16_C(    61), -INT16_C(    61),
      -INT16_C(    61), -INT16_C(    61), -INT16_C(    61) };

  static int16_t r[sizeof(e) / sizeof(e[0])];
  static const int32_t len = HEDLEY_STATIC_CAST(int32_t, sizeof(e) / sizeof(e[0]));
  int32_t i = 0;
  simde_svbool_t pg = simde_svwhilelt_b16_s32(i, len);
  while (simde_svptest_first(simde_svptrue_b16(), pg)) {
    simde_svint16_t rv;

    rv = simde_svdup_n_s16(a);

    simde_svst1_s16(pg, &(r[i]), rv);

    i += simde_svcnth();
    pg = simde_svwhilelt_b16_s32(i, len);
  }

  simde_assert_equal_vi16(len, e, r);

  return 0;
#else
  int16_t a, e[1024 / sizeof(int16_t)];
  int32_t len;

  fputc('\n', stdout);

  len = simde_test_codegen_random_i16() & ((sizeof(e) / sizeof(e[0])) - 1);
  a = simde_test_codegen_random_i16();

  int32_t i = 0;
  simde_svbool_t pg = simde_svwhilelt_b16_s32(i, len);
  while (simde_svptest_first(simde_svptrue_b16(), pg)) {
    simde_svint16_t ev;

    ev = simde_svdup_n_s16(a);

    simde_svst1_s16(pg, &(e[i]), ev);

    i += simde_svcnth();
    pg = simde_svwhilelt_b16_s32(i, len);
  }

  simde_test_codegen_write_1i8(1, a);
  simde_test_codegen_write_1vi16(1, HEDLEY_STATIC_CAST(size_t, len), e);

  return 1;
#endif
}

static int
test_simde_svdup_n_s16_z (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const int16_t p[] =
    { -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),
      -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),
      -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),
       INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),
      -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),
       INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
       INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),
       INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),
      -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),
       INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),
       INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),
      -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),
      -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),
      -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),
       INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
      -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),
      -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),
      -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),
      -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),
       INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),
       INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),
      -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),
       INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),
      -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),
       INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),
      -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),
      -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),
       INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),
      -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),
      -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),
      -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),
       INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),
      -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),
      -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),
      -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),
      -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),
      -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),
      -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),
      -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),
      -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),
      -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),
      -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),
      -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),
      -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),
      -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1) };
  static const int16_t a = -INT16_C(    99);
  static const int16_t e[] =
    { -INT16_C(    99), -INT16_C(    99),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(    99),  INT16_C(     0), -INT16_C(    99),
      -INT16_C(    99),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(    99), -INT16_C(    99),  INT16_C(     0), -INT16_C(    99),
      -INT16_C(    99),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(    99), -INT16_C(    99), -INT16_C(    99),  INT16_C(     0),
       INT16_C(     0), -INT16_C(    99), -INT16_C(    99), -INT16_C(    99), -INT16_C(    99), -INT16_C(    99), -INT16_C(    99), -INT16_C(    99),
      -INT16_C(    99),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(    99),  INT16_C(     0),  INT16_C(     0), -INT16_C(    99),
       INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
       INT16_C(     0), -INT16_C(    99),  INT16_C(     0),  INT16_C(     0), -INT16_C(    99),  INT16_C(     0), -INT16_C(    99), -INT16_C(    99),
       INT16_C(     0), -INT16_C(    99), -INT16_C(    99), -INT16_C(    99),  INT16_C(     0), -INT16_C(    99), -INT16_C(    99), -INT16_C(    99),
      -INT16_C(    99), -INT16_C(    99),  INT16_C(     0),  INT16_C(     0), -INT16_C(    99), -INT16_C(    99),  INT16_C(     0), -INT16_C(    99),
       INT16_C(     0), -INT16_C(    99), -INT16_C(    99), -INT16_C(    99),  INT16_C(     0), -INT16_C(    99), -INT16_C(    99),  INT16_C(     0),
       INT16_C(     0),  INT16_C(     0), -INT16_C(    99),  INT16_C(     0),  INT16_C(     0), -INT16_C(    99), -INT16_C(    99), -INT16_C(    99),
      -INT16_C(    99),  INT16_C(     0), -INT16_C(    99), -INT16_C(    99), -INT16_C(    99), -INT16_C(    99),  INT16_C(     0),  INT16_C(     0),
      -INT16_C(    99), -INT16_C(    99), -INT16_C(    99),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(    99),
      -INT16_C(    99),  INT16_C(     0), -INT16_C(    99),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(    99),  INT16_C(     0),
       INT16_C(     0), -INT16_C(    99),  INT16_C(     0), -INT16_C(    99),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
      -INT16_C(    99), -INT16_C(    99),  INT16_C(     0),  INT16_C(     0), -INT16_C(    99), -INT16_C(    99),  INT16_C(     0),  INT16_C(     0),
      -INT16_C(    99),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(    99),  INT16_C(     0), -INT16_C(    99),
      -INT16_C(    99), -INT16_C(    99),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(    99),  INT16_C(     0), -INT16_C(    99),
      -INT16_C(    99),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(    99),  INT16_C(     0), -INT16_C(    99),
       INT16_C(     0),  INT16_C(     0), -INT16_C(    99),  INT16_C(     0), -INT16_C(    99),  INT16_C(     0), -INT16_C(    99),  INT16_C(     0),
       INT16_C(     0), -INT16_C(    99),  INT16_C(     0), -INT16_C(    99),  INT16_C(     0), -INT16_C(    99),  INT16_C(     0), -INT16_C(    99),
      -INT16_C(    99),  INT16_C(     0), -INT16_C(    99), -INT16_C(    99),  INT16_C(     0), -INT16_C(    99),  INT16_C(     0), -INT16_C(    99),
       INT16_C(     0), -INT16_C(    99), -INT16_C(    99), -INT16_C(    99), -INT16_C(    99),  INT16_C(     0),  INT16_C(     0), -INT16_C(    99),
      -INT16_C(    99), -INT16_C(    99), -INT16_C(    99), -INT16_C(    99), -INT16_C(    99),  INT16_C(     0),  INT16_C(     0), -INT16_C(    99),
       INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(    99), -INT16_C(    99), -INT16_C(    99), -INT16_C(    99), -INT16_C(    99),
      -INT16_C(    99), -INT16_C(    99), -INT16_C(    99), -INT16_C(    99), -INT16_C(    99),  INT16_C(     0),  INT16_C(     0), -INT16_C(    99),
      -INT16_C(    99),  INT16_C(     0),  INT16_C(     0), -INT16_C(    99), -INT16_C(    99),  INT16_C(     0),  INT16_C(     0), -INT16_C(    99),
       INT16_C(     0), -INT16_C(    99),  INT16_C(     0), -INT16_C(    99), -INT16_C(    99), -INT16_C(    99), -INT16_C(    99), -INT16_C(    99),
      -INT16_C(    99), -INT16_C(    99), -INT16_C(    99), -INT16_C(    99), -INT16_C(    99), -INT16_C(    99), -INT16_C(    99), -INT16_C(    99),
      -INT16_C(    99), -INT16_C(    99), -INT16_C(    99), -INT16_C(    99), -INT16_C(    99), -INT16_C(    99), -INT16_C(    99), -INT16_C(    99),
      -INT16_C(    99), -INT16_C(    99), -INT16_C(    99), -INT16_C(    99), -INT16_C(    99),  INT16_C(     0),  INT16_C(     0), -INT16_C(    99),
       INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(    99), -INT16_C(    99),  INT16_C(     0),  INT16_C(     0), -INT16_C(    99),
      -INT16_C(    99), -INT16_C(    99), -INT16_C(    99), -INT16_C(    99), -INT16_C(    99),  INT16_C(     0),  INT16_C(     0), -INT16_C(    99),
      -INT16_C(    99), -INT16_C(    99), -INT16_C(    99), -INT16_C(    99), -INT16_C(    99),  INT16_C(     0),  INT16_C(     0), -INT16_C(    99),
      -INT16_C(    99),  INT16_C(     0),  INT16_C(     0), -INT16_C(    99), -INT16_C(    99),  INT16_C(     0),  INT16_C(     0), -INT16_C(    99),
      -INT16_C(    99),  INT16_C(     0),  INT16_C(     0), -INT16_C(    99), -INT16_C(    99),  INT16_C(     0),  INT16_C(     0), -INT16_C(    99),
      -INT16_C(    99),  INT16_C(     0),  INT16_C(     0), -INT16_C(    99), -INT16_C(    99), -INT16_C(    99), -INT16_C(    99), -INT16_C(    99),
      -INT16_C(    99), -INT16_C(    99), -INT16_C(    99), -INT16_C(    99), -INT16_C(    99),  INT16_C(     0),  INT16_C(     0), -INT16_C(    99),
      -INT16_C(    99),  INT16_C(     0),  INT16_C(     0), -INT16_C(    99), -INT16_C(    99),  INT16_C(     0),  INT16_C(     0), -INT16_C(    99),
      -INT16_C(    99), -INT16_C(    99), -INT16_C(    99), -INT16_C(    99),  INT16_C(     0), -INT16_C(    99),  INT16_C(     0), -INT16_C(    99),
      -INT16_C(    99), -INT16_C(    99), -INT16_C(    99), -INT16_C(    99), -INT16_C(    99),  INT16_C(     0),  INT16_C(     0), -INT16_C(    99),
      -INT16_C(    99),  INT16_C(     0),  INT16_C(     0), -INT16_C(    99), -INT16_C(    99), -INT16_C(    99), -INT16_C(    99), -INT16_C(    99),
      -INT16_C(    99), -INT16_C(    99), -INT16_C(    99), -INT16_C(    99), -INT16_C(    99), -INT16_C(    99), -INT16_C(    99), -INT16_C(    99),
      -INT16_C(    99), -INT16_C(    99), -INT16_C(    99), -INT16_C(    99), -INT16_C(    99), -INT16_C(    99), -INT16_C(    99), -INT16_C(    99),
      -INT16_C(    99), -INT16_C(    99), -INT16_C(    99), -INT16_C(    99), -INT16_C(    99), -INT16_C(    99), -INT16_C(    99) };

  static int16_t r[sizeof(e) / sizeof(e[0])];
  static const int32_t len = HEDLEY_STATIC_CAST(int32_t, sizeof(e) / sizeof(e[0]));
  int32_t i = 0;
  simde_svbool_t pg = simde_svwhilelt_b16_s32(i, len);
  while (simde_svptest_first(simde_svptrue_b16(), pg)) {
    simde_svint16_t rv;
    simde_svbool_t pv;

    pv = simde_svcmplt_s16(pg, simde_svld1_s16(pg, &(p[i])), simde_svdup_n_s16(INT16_C(0)));
    rv = simde_svdup_n_s16_z(pv, a);

    simde_svst1_s16(pg, &(r[i]), rv);

    i += simde_svcnth();
    pg = simde_svwhilelt_b16_s32(i, len);
  }

  simde_assert_equal_vi16(len, e, r);

  return 0;
#else
  int16_t a, p[1024 / sizeof(int16_t)], e[1024 / sizeof(int16_t)];
  int32_t len;

  fputc('\n', stdout);

  len = simde_test_codegen_random_i16() & ((sizeof(e) / sizeof(e[0])) - 1);
  simde_test_codegen_random_memory(sizeof(p), HEDLEY_REINTERPRET_CAST(uint8_t*, p));
  a = simde_test_codegen_random_i8();

  int32_t i = 0;
  simde_svbool_t pg = simde_svwhilelt_b16_s32(i, len);
  while (simde_svptest_first(simde_svptrue_b16(), pg)) {
    simde_svint16_t ev;
    simde_svbool_t pv;

    pv = simde_svcmplt_s16(pg, simde_svld1_s16(pg, &(p[i])), simde_svdup_n_s16(0));
    ev = simde_svdup_n_s16_z(pv, a);

    simde_svst1_s16(pg, &(e[i]), ev);
    simde_svst1_s16(pg, &(p[i]), simde_svdup_n_s16_z(pv, ~INT16_C(0)));

    i += simde_svcnth();
    pg = simde_svwhilelt_b16_s32(i, len);
  }

  simde_test_codegen_write_1vi16(1, HEDLEY_STATIC_CAST(size_t, len), p);
  simde_test_codegen_write_1i16(1, a);
  simde_test_codegen_write_1vi16(1, HEDLEY_STATIC_CAST(size_t, len), e);

  return 1;
#endif
}

static int
test_simde_svdup_n_s16_m (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const int16_t p[] =
    { -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),
       INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),
      -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),
      -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),
      -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
       INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
      -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
       INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),
      -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),
       INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),
       INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),
      -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),
       INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),
      -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),
      -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),
      -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),
      -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),
       INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
      -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),
      -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),
       INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),
      -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),
       INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),
      -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
       INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),
      -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),
       INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),
      -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
       INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),
       INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
       INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),
       INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),
      -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),
       INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),
       INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),
       INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),
       INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),
       INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),
       INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),
       INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
       INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),
      -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),
      -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),
      -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),
      -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),
      -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),
      -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),
       INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),
      -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),
      -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),
      -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),
       INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),
      -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),
      -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),
      -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
      -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1) };
  static const int16_t a[] =
    { -INT16_C( 24438), -INT16_C(  2343),  INT16_C( 12405),  INT16_C( 13955),  INT16_C( 12377), -INT16_C(  3789),  INT16_C( 20252),  INT16_C(   999),
      -INT16_C( 27701), -INT16_C( 14930),  INT16_C( 28860),  INT16_C( 19743),  INT16_C( 23075), -INT16_C(  7230), -INT16_C( 22549),  INT16_C( 30174),
      -INT16_C( 18617), -INT16_C( 17301), -INT16_C(  4377),  INT16_C( 16626),  INT16_C(  9758),  INT16_C( 15154),  INT16_C(  6517),  INT16_C( 16446),
      -INT16_C(  4948),  INT16_C( 26630),  INT16_C(  9564), -INT16_C( 32587),  INT16_C( 30591),  INT16_C( 27235),  INT16_C( 16670),  INT16_C( 26335),
       INT16_C( 19193), -INT16_C(  8158),  INT16_C(  5433),  INT16_C( 22305),  INT16_C( 21307), -INT16_C( 20334), -INT16_C( 11924),  INT16_C(  6385),
      -INT16_C(  2115),  INT16_C(  6784),  INT16_C( 13596), -INT16_C( 25702), -INT16_C(   596), -INT16_C( 13818), -INT16_C(  6849),  INT16_C( 14384),
       INT16_C( 21296),  INT16_C( 26904),  INT16_C( 14696), -INT16_C( 23616),  INT16_C( 21388), -INT16_C(  1965),  INT16_C( 17444), -INT16_C(  7920),
      -INT16_C( 28613),  INT16_C( 22523), -INT16_C( 27195),  INT16_C( 29171), -INT16_C(  1645), -INT16_C( 11716),  INT16_C( 27870),  INT16_C(  3594),
       INT16_C(  8895),  INT16_C( 10103),  INT16_C( 14428), -INT16_C(  5942),  INT16_C(  7819), -INT16_C( 20511), -INT16_C(  3742), -INT16_C( 24944),
      -INT16_C( 29566),  INT16_C( 18421), -INT16_C(  6111), -INT16_C( 19271), -INT16_C(  2591), -INT16_C( 16250), -INT16_C( 28575),  INT16_C(  8654),
       INT16_C( 18099),  INT16_C(  3912),  INT16_C(  4990),  INT16_C(  2551), -INT16_C( 10191), -INT16_C( 27720),  INT16_C( 18634),  INT16_C( 19505),
       INT16_C( 10196), -INT16_C(  2413),  INT16_C( 19471), -INT16_C(  3670),  INT16_C( 12609), -INT16_C( 23631),  INT16_C( 32705),  INT16_C( 29892),
       INT16_C(  3269),  INT16_C( 17283),  INT16_C( 31519),  INT16_C( 20556),  INT16_C(  1107),  INT16_C(  7652),  INT16_C(  5453),  INT16_C(  8553),
      -INT16_C(   708),  INT16_C( 19479), -INT16_C( 15799), -INT16_C( 29891), -INT16_C(  4365), -INT16_C( 19410), -INT16_C(  3475),  INT16_C( 13097),
      -INT16_C( 21250),  INT16_C(  7798), -INT16_C( 15577),  INT16_C( 31598),  INT16_C( 21191),  INT16_C(  5272),  INT16_C(   616), -INT16_C( 23498),
       INT16_C( 19967),  INT16_C( 18672),  INT16_C( 11535),  INT16_C(   723),  INT16_C(   283), -INT16_C( 30281), -INT16_C(  7949), -INT16_C(  3396),
       INT16_C( 12940), -INT16_C( 19440),  INT16_C( 32501), -INT16_C( 17105), -INT16_C( 14383),  INT16_C( 14801),  INT16_C(  1993), -INT16_C( 14115),
      -INT16_C( 12715),  INT16_C( 25617), -INT16_C(  6917),  INT16_C(  5991),  INT16_C(  7910), -INT16_C(  9824),  INT16_C( 23806), -INT16_C( 30005),
      -INT16_C(  9330), -INT16_C( 31682),  INT16_C( 27994),  INT16_C( 11073),  INT16_C(  4661), -INT16_C(   412),  INT16_C( 16666),  INT16_C( 28615),
      -INT16_C( 10225),  INT16_C(  3027),  INT16_C( 15036), -INT16_C( 24030), -INT16_C( 15784),  INT16_C( 22140),  INT16_C( 18206), -INT16_C( 21279),
       INT16_C(  7971),  INT16_C( 32048),  INT16_C( 29069), -INT16_C( 15704),  INT16_C(  3204), -INT16_C( 24896), -INT16_C( 30899),  INT16_C( 23821),
      -INT16_C(  8097),  INT16_C(  7272), -INT16_C( 30181),  INT16_C( 29630),  INT16_C( 14924),  INT16_C( 27338), -INT16_C( 21630), -INT16_C( 23274),
       INT16_C( 18378),  INT16_C( 22306), -INT16_C( 13640),  INT16_C( 15385), -INT16_C(  9514),  INT16_C(  9178), -INT16_C(  6303), -INT16_C( 16000),
      -INT16_C(  5944), -INT16_C(  7203), -INT16_C( 25742), -INT16_C( 16810),  INT16_C(  8406),  INT16_C( 22568),  INT16_C( 16331), -INT16_C( 26883),
       INT16_C(  8070),  INT16_C( 16109),  INT16_C(  2025), -INT16_C( 16517),  INT16_C( 21985),  INT16_C( 17122),  INT16_C( 25405),  INT16_C(  1283),
      -INT16_C(  8117), -INT16_C( 16664),  INT16_C( 15996),  INT16_C( 21116), -INT16_C( 23201),  INT16_C( 10922), -INT16_C( 22556),  INT16_C( 27328),
      -INT16_C( 20794), -INT16_C( 20568),  INT16_C(  9141), -INT16_C( 27026),  INT16_C( 20601), -INT16_C( 18728), -INT16_C(  9037), -INT16_C(    69),
      -INT16_C( 23620),  INT16_C( 14525),  INT16_C( 14817),  INT16_C( 16522),  INT16_C( 13534), -INT16_C( 15765),  INT16_C( 11227), -INT16_C( 24276),
      -INT16_C( 10791), -INT16_C( 29104), -INT16_C( 16648),  INT16_C( 28964), -INT16_C(   753), -INT16_C( 15833), -INT16_C(  7463), -INT16_C( 27199),
       INT16_C( 32389),  INT16_C( 26574),  INT16_C( 22712), -INT16_C( 26969),  INT16_C(  4749),  INT16_C( 26713), -INT16_C( 31426),  INT16_C(  5898),
       INT16_C( 23130),  INT16_C( 21414), -INT16_C( 13799),  INT16_C( 10436), -INT16_C(  4921), -INT16_C( 24342), -INT16_C( 21298),  INT16_C( 21558),
       INT16_C(  1066), -INT16_C(  7493),  INT16_C( 25180), -INT16_C(  5767), -INT16_C( 11659), -INT16_C( 19630),  INT16_C( 23639), -INT16_C( 19766),
       INT16_C( 28854), -INT16_C( 12539), -INT16_C( 14021),  INT16_C(   759), -INT16_C(  7499), -INT16_C( 31581), -INT16_C(  9842), -INT16_C( 18216),
      -INT16_C( 27683),  INT16_C( 14747),  INT16_C(  5365),  INT16_C( 27171),  INT16_C( 30182),  INT16_C( 15645), -INT16_C(  5935), -INT16_C( 30737),
      -INT16_C(  2984), -INT16_C( 27817),  INT16_C( 20158),  INT16_C( 29590),  INT16_C( 14640), -INT16_C( 16649), -INT16_C( 12526), -INT16_C(  4233),
       INT16_C(  4706),  INT16_C( 22568),  INT16_C( 19238),  INT16_C(  3266), -INT16_C(  8000), -INT16_C( 28343),  INT16_C( 14792),  INT16_C(  8217),
       INT16_C( 28717), -INT16_C(  5196),  INT16_C( 19134), -INT16_C(  4257),  INT16_C( 22147), -INT16_C( 27219),  INT16_C(  9254), -INT16_C( 30588),
      -INT16_C( 21450),  INT16_C( 23776), -INT16_C( 23560), -INT16_C( 18328), -INT16_C( 19837),  INT16_C( 19274),  INT16_C( 25579),  INT16_C(  6251),
       INT16_C(  8147), -INT16_C( 28412),  INT16_C( 25449), -INT16_C(  4992),  INT16_C( 11961), -INT16_C(  8319),  INT16_C(  1362), -INT16_C( 30360),
       INT16_C( 18610), -INT16_C( 21787),  INT16_C( 20203),  INT16_C( 28258), -INT16_C( 21504), -INT16_C(  5191),  INT16_C(  9487), -INT16_C(  7677),
       INT16_C(  1860), -INT16_C( 20876), -INT16_C(  2966),  INT16_C(  9370),  INT16_C(  7202),  INT16_C( 29955),  INT16_C( 27425), -INT16_C( 11266),
      -INT16_C(  7244), -INT16_C( 24707), -INT16_C(  8143),  INT16_C( 12558), -INT16_C( 14452), -INT16_C( 25572),  INT16_C(  8428),  INT16_C( 12670),
      -INT16_C(  3545), -INT16_C( 27937),  INT16_C( 31207),  INT16_C(  2486), -INT16_C( 18027), -INT16_C( 18562),  INT16_C( 31781), -INT16_C(  9846),
       INT16_C(  2144), -INT16_C( 28296), -INT16_C( 31000),  INT16_C( 29891), -INT16_C(  8370),  INT16_C( 14864), -INT16_C( 28673),  INT16_C( 10091),
       INT16_C( 19073),  INT16_C( 26809),  INT16_C( 28612),  INT16_C( 22898), -INT16_C(  4056),  INT16_C( 19728), -INT16_C( 25747), -INT16_C( 13018),
      -INT16_C( 24669), -INT16_C( 29858),  INT16_C(  8485),  INT16_C( 29695),  INT16_C(  4097),  INT16_C(   174),  INT16_C(  6559),  INT16_C(  8231),
      -INT16_C(  8092),  INT16_C( 10377), -INT16_C(  1201),  INT16_C( 30849), -INT16_C( 27925),  INT16_C( 22725), -INT16_C(  5075), -INT16_C( 12251),
      -INT16_C( 31605), -INT16_C( 20389),  INT16_C( 23205), -INT16_C( 23004), -INT16_C( 11670),  INT16_C(  2471), -INT16_C( 12565),  INT16_C( 20266),
      -INT16_C( 19537), -INT16_C(   393), -INT16_C(  1618), -INT16_C( 26250),  INT16_C( 15499), -INT16_C( 18190),  INT16_C(  5928), -INT16_C( 19576),
      -INT16_C(  7269),  INT16_C( 16739), -INT16_C( 30915), -INT16_C( 22297), -INT16_C( 29095),  INT16_C( 17841), -INT16_C(  9379),  INT16_C(  3220),
       INT16_C(  3214),  INT16_C( 15370), -INT16_C( 32507), -INT16_C( 28458), -INT16_C( 14147), -INT16_C(  6840), -INT16_C( 12065),  INT16_C( 31640),
      -INT16_C(  1101), -INT16_C(  3908), -INT16_C( 23677), -INT16_C(  9064),  INT16_C( 18994), -INT16_C( 28895), -INT16_C( 18907), -INT16_C( 19301),
      -INT16_C( 23102), -INT16_C( 14352), -INT16_C( 14810), -INT16_C(  7337), -INT16_C( 24690),  INT16_C( 28360),  INT16_C( 24687),  INT16_C(  8937),
      -INT16_C( 23204), -INT16_C(  8430), -INT16_C( 21688),  INT16_C( 31419), -INT16_C(  8715),  INT16_C(  6665), -INT16_C( 23405),  INT16_C( 21966),
      -INT16_C( 16566),  INT16_C( 28700),  INT16_C( 29573),  INT16_C(  5204),  INT16_C(  7186), -INT16_C( 32382),  INT16_C( 27517), -INT16_C(  9821),
      -INT16_C( 19184),  INT16_C( 22712),  INT16_C( 29536),  INT16_C( 21971), -INT16_C(  9136), -INT16_C(  7312) };
  static const int16_t b = -INT16_C( 15735);
  static const int16_t e[] =
    { -INT16_C( 15735), -INT16_C( 15735),  INT16_C( 12405), -INT16_C( 15735),  INT16_C( 12377), -INT16_C(  3789), -INT16_C( 15735),  INT16_C(   999),
      -INT16_C( 27701), -INT16_C( 15735), -INT16_C( 15735),  INT16_C( 19743),  INT16_C( 23075), -INT16_C(  7230), -INT16_C( 15735), -INT16_C( 15735),
      -INT16_C( 15735), -INT16_C( 15735), -INT16_C(  4377), -INT16_C( 15735), -INT16_C( 15735),  INT16_C( 15154), -INT16_C( 15735),  INT16_C( 16446),
      -INT16_C( 15735), -INT16_C( 15735), -INT16_C( 15735), -INT16_C( 15735), -INT16_C( 15735),  INT16_C( 27235), -INT16_C( 15735), -INT16_C( 15735),
      -INT16_C( 15735), -INT16_C( 15735),  INT16_C(  5433),  INT16_C( 22305), -INT16_C( 15735), -INT16_C( 20334), -INT16_C( 11924),  INT16_C(  6385),
      -INT16_C(  2115),  INT16_C(  6784),  INT16_C( 13596), -INT16_C( 15735), -INT16_C( 15735), -INT16_C( 13818), -INT16_C(  6849),  INT16_C( 14384),
      -INT16_C( 15735),  INT16_C( 26904),  INT16_C( 14696), -INT16_C( 15735),  INT16_C( 21388), -INT16_C(  1965),  INT16_C( 17444), -INT16_C(  7920),
      -INT16_C( 28613),  INT16_C( 22523), -INT16_C( 27195), -INT16_C( 15735), -INT16_C(  1645), -INT16_C( 15735),  INT16_C( 27870), -INT16_C( 15735),
      -INT16_C( 15735), -INT16_C( 15735), -INT16_C( 15735), -INT16_C( 15735),  INT16_C(  7819), -INT16_C( 15735), -INT16_C(  3742), -INT16_C( 15735),
      -INT16_C( 29566),  INT16_C( 18421), -INT16_C(  6111), -INT16_C( 15735), -INT16_C(  2591), -INT16_C( 15735), -INT16_C( 28575), -INT16_C( 15735),
       INT16_C( 18099), -INT16_C( 15735),  INT16_C(  4990), -INT16_C( 15735), -INT16_C( 10191), -INT16_C( 15735), -INT16_C( 15735), -INT16_C( 15735),
      -INT16_C( 15735), -INT16_C(  2413),  INT16_C( 19471), -INT16_C(  3670),  INT16_C( 12609), -INT16_C( 15735),  INT16_C( 32705),  INT16_C( 29892),
       INT16_C(  3269), -INT16_C( 15735), -INT16_C( 15735), -INT16_C( 15735),  INT16_C(  1107), -INT16_C( 15735), -INT16_C( 15735), -INT16_C( 15735),
      -INT16_C( 15735),  INT16_C( 19479), -INT16_C( 15799), -INT16_C( 15735), -INT16_C(  4365), -INT16_C( 15735), -INT16_C( 15735),  INT16_C( 13097),
      -INT16_C( 15735),  INT16_C(  7798), -INT16_C( 15735), -INT16_C( 15735),  INT16_C( 21191),  INT16_C(  5272), -INT16_C( 15735), -INT16_C( 15735),
      -INT16_C( 15735),  INT16_C( 18672),  INT16_C( 11535), -INT16_C( 15735),  INT16_C(   283), -INT16_C( 30281), -INT16_C( 15735), -INT16_C(  3396),
      -INT16_C( 15735), -INT16_C( 15735),  INT16_C( 32501), -INT16_C( 17105), -INT16_C( 15735), -INT16_C( 15735), -INT16_C( 15735), -INT16_C( 14115),
      -INT16_C( 12715), -INT16_C( 15735), -INT16_C(  6917),  INT16_C(  5991), -INT16_C( 15735), -INT16_C(  9824),  INT16_C( 23806), -INT16_C( 30005),
      -INT16_C( 15735), -INT16_C( 15735), -INT16_C( 15735),  INT16_C( 11073),  INT16_C(  4661), -INT16_C(   412), -INT16_C( 15735), -INT16_C( 15735),
      -INT16_C( 15735), -INT16_C( 15735), -INT16_C( 15735), -INT16_C( 24030), -INT16_C( 15735),  INT16_C( 22140), -INT16_C( 15735), -INT16_C( 21279),
       INT16_C(  7971),  INT16_C( 32048), -INT16_C( 15735), -INT16_C( 15735),  INT16_C(  3204), -INT16_C( 24896), -INT16_C( 15735), -INT16_C( 15735),
      -INT16_C( 15735),  INT16_C(  7272), -INT16_C( 15735), -INT16_C( 15735), -INT16_C( 15735), -INT16_C( 15735), -INT16_C( 15735), -INT16_C( 15735),
       INT16_C( 18378), -INT16_C( 15735), -INT16_C( 13640),  INT16_C( 15385), -INT16_C( 15735), -INT16_C( 15735), -INT16_C( 15735), -INT16_C( 16000),
      -INT16_C( 15735), -INT16_C( 15735), -INT16_C( 25742), -INT16_C( 15735),  INT16_C(  8406),  INT16_C( 22568),  INT16_C( 16331), -INT16_C( 26883),
       INT16_C(  8070), -INT16_C( 15735), -INT16_C( 15735), -INT16_C( 15735), -INT16_C( 15735),  INT16_C( 17122),  INT16_C( 25405), -INT16_C( 15735),
      -INT16_C( 15735), -INT16_C( 16664), -INT16_C( 15735), -INT16_C( 15735), -INT16_C( 15735),  INT16_C( 10922), -INT16_C( 15735),  INT16_C( 27328),
      -INT16_C( 20794), -INT16_C( 15735), -INT16_C( 15735), -INT16_C( 27026), -INT16_C( 15735), -INT16_C( 15735), -INT16_C( 15735), -INT16_C(    69),
      -INT16_C( 15735), -INT16_C( 15735),  INT16_C( 14817), -INT16_C( 15735),  INT16_C( 13534), -INT16_C( 15765),  INT16_C( 11227), -INT16_C( 24276),
      -INT16_C( 10791), -INT16_C( 15735), -INT16_C( 15735), -INT16_C( 15735), -INT16_C( 15735), -INT16_C( 15735), -INT16_C(  7463), -INT16_C( 27199),
       INT16_C( 32389),  INT16_C( 26574),  INT16_C( 22712), -INT16_C( 15735),  INT16_C(  4749),  INT16_C( 26713), -INT16_C( 31426),  INT16_C(  5898),
       INT16_C( 23130), -INT16_C( 15735), -INT16_C( 15735), -INT16_C( 15735), -INT16_C(  4921), -INT16_C( 24342), -INT16_C( 15735), -INT16_C( 15735),
       INT16_C(  1066), -INT16_C( 15735),  INT16_C( 25180), -INT16_C( 15735), -INT16_C( 15735), -INT16_C( 19630),  INT16_C( 23639), -INT16_C( 15735),
      -INT16_C( 15735), -INT16_C( 15735), -INT16_C( 15735),  INT16_C(   759), -INT16_C(  7499), -INT16_C( 15735), -INT16_C(  9842), -INT16_C( 18216),
      -INT16_C( 27683),  INT16_C( 14747), -INT16_C( 15735),  INT16_C( 27171),  INT16_C( 30182),  INT16_C( 15645), -INT16_C(  5935), -INT16_C( 15735),
      -INT16_C(  2984), -INT16_C( 27817),  INT16_C( 20158),  INT16_C( 29590), -INT16_C( 15735), -INT16_C( 16649), -INT16_C( 15735), -INT16_C( 15735),
       INT16_C(  4706),  INT16_C( 22568), -INT16_C( 15735),  INT16_C(  3266), -INT16_C( 15735), -INT16_C( 28343), -INT16_C( 15735),  INT16_C(  8217),
       INT16_C( 28717), -INT16_C(  5196), -INT16_C( 15735), -INT16_C( 15735), -INT16_C( 15735), -INT16_C( 15735), -INT16_C( 15735), -INT16_C( 15735),
      -INT16_C( 21450),  INT16_C( 23776), -INT16_C( 15735), -INT16_C( 18328), -INT16_C( 19837),  INT16_C( 19274), -INT16_C( 15735),  INT16_C(  6251),
       INT16_C(  8147), -INT16_C( 28412),  INT16_C( 25449), -INT16_C( 15735), -INT16_C( 15735), -INT16_C( 15735),  INT16_C(  1362), -INT16_C( 15735),
       INT16_C( 18610), -INT16_C( 15735), -INT16_C( 15735), -INT16_C( 15735), -INT16_C( 21504), -INT16_C(  5191),  INT16_C(  9487), -INT16_C(  7677),
       INT16_C(  1860), -INT16_C( 15735), -INT16_C( 15735), -INT16_C( 15735), -INT16_C( 15735), -INT16_C( 15735), -INT16_C( 15735), -INT16_C( 15735),
      -INT16_C( 15735), -INT16_C( 24707), -INT16_C(  8143), -INT16_C( 15735), -INT16_C( 14452), -INT16_C( 15735),  INT16_C(  8428), -INT16_C( 15735),
      -INT16_C( 15735), -INT16_C( 27937),  INT16_C( 31207),  INT16_C(  2486), -INT16_C( 15735), -INT16_C( 18562),  INT16_C( 31781), -INT16_C( 15735),
      -INT16_C( 15735), -INT16_C( 28296), -INT16_C( 15735),  INT16_C( 29891), -INT16_C( 15735),  INT16_C( 14864), -INT16_C( 28673), -INT16_C( 15735),
      -INT16_C( 15735), -INT16_C( 15735), -INT16_C( 15735),  INT16_C( 22898), -INT16_C(  4056),  INT16_C( 19728), -INT16_C( 15735), -INT16_C( 15735),
      -INT16_C( 15735), -INT16_C( 29858), -INT16_C( 15735), -INT16_C( 15735), -INT16_C( 15735), -INT16_C( 15735), -INT16_C( 15735),  INT16_C(  8231),
      -INT16_C( 15735),  INT16_C( 10377), -INT16_C( 15735), -INT16_C( 15735), -INT16_C( 27925), -INT16_C( 15735), -INT16_C(  5075), -INT16_C( 15735),
      -INT16_C( 31605), -INT16_C( 15735),  INT16_C( 23205), -INT16_C( 15735), -INT16_C( 11670),  INT16_C(  2471), -INT16_C( 12565), -INT16_C( 15735),
      -INT16_C( 15735), -INT16_C(   393), -INT16_C( 15735), -INT16_C( 26250),  INT16_C( 15499), -INT16_C( 15735), -INT16_C( 15735), -INT16_C( 19576),
      -INT16_C( 15735), -INT16_C( 15735), -INT16_C( 15735), -INT16_C( 15735), -INT16_C( 15735), -INT16_C( 15735), -INT16_C( 15735), -INT16_C( 15735),
      -INT16_C( 15735), -INT16_C( 15735), -INT16_C( 32507), -INT16_C( 28458), -INT16_C( 14147), -INT16_C(  6840), -INT16_C( 15735), -INT16_C( 15735),
      -INT16_C(  1101), -INT16_C(  3908), -INT16_C( 15735), -INT16_C(  9064),  INT16_C( 18994), -INT16_C( 15735), -INT16_C( 15735), -INT16_C( 19301),
      -INT16_C( 15735), -INT16_C( 14352), -INT16_C( 14810), -INT16_C(  7337), -INT16_C( 24690),  INT16_C( 28360), -INT16_C( 15735),  INT16_C(  8937),
      -INT16_C( 15735), -INT16_C( 15735), -INT16_C( 15735),  INT16_C( 31419), -INT16_C( 15735),  INT16_C(  6665), -INT16_C( 15735),  INT16_C( 21966),
      -INT16_C( 15735),  INT16_C( 28700), -INT16_C( 15735), -INT16_C( 15735),  INT16_C(  7186), -INT16_C( 32382),  INT16_C( 27517), -INT16_C(  9821),
      -INT16_C( 15735),  INT16_C( 22712), -INT16_C( 15735),  INT16_C( 21971), -INT16_C(  9136), -INT16_C( 15735) };

  static int16_t r[sizeof(e) / sizeof(e[0])];
  static const int32_t len = HEDLEY_STATIC_CAST(int32_t, sizeof(e) / sizeof(e[0]));
  int32_t i = 0;
  simde_svbool_t pg = simde_svwhilelt_b16_s32(i, len);
  while (simde_svptest_first(simde_svptrue_b16(), pg)) {
    simde_svint16_t
      rv,
      av = simde_svld1_s16(pg, &(a[i]));
    simde_svbool_t pv;

    pv = simde_svcmplt_s16(pg, simde_svld1_s16(pg, &(p[i])), simde_svdup_n_s16(INT16_C(0)));
    rv = simde_svdup_n_s16_m(av, pv, b);

    simde_svst1_s16(pg, &(r[i]), rv);

    i += simde_svcnth();
    pg = simde_svwhilelt_b16_s32(i, len);
  }

  simde_assert_equal_vi16(len, e, r);

  return 0;
#else
  int16_t p[1024 / sizeof(int16_t)], a[1024 / sizeof(int16_t)], b, e[1024 / sizeof(int16_t)];
  int32_t len = simde_test_arm_sve_random_length(sizeof(e), sizeof(e[0]));

  fputc('\n', stdout);

  simde_test_codegen_random_memory(sizeof(p), HEDLEY_REINTERPRET_CAST(uint8_t*, p));
  simde_test_codegen_random_memory(sizeof(a), HEDLEY_REINTERPRET_CAST(uint8_t*, a));
  b = simde_test_codegen_random_i16();

  int32_t i = 0;
  simde_svbool_t pg = simde_svwhilelt_b16_s32(i, len);
  while (simde_svptest_first(simde_svptrue_b16(), pg)) {
    simde_svint16_t av, ev;
    simde_svbool_t pv;

    pv = simde_svcmplt_s16(pg, simde_svld1_s16(pg, &(p[i])), simde_svdup_n_s16(0));
    av = simde_svld1_s16(pg, &(a[i]));

    ev = simde_svdup_n_s16_m(av, pv, b);

    simde_svst1_s16(pg, &(e[i]), ev);
    simde_svst1_s16(pg, &(p[i]), simde_svdup_n_s16_z(pv, ~INT16_C(0)));

    i += simde_svcnth();
    pg = simde_svwhilelt_b16_s32(i, len);
  }

  simde_test_codegen_write_1vi16(1, HEDLEY_STATIC_CAST(size_t, len), p);
  simde_test_codegen_write_1vi16(1, HEDLEY_STATIC_CAST(size_t, len), a);
  simde_test_codegen_write_1i16(1, b);
  simde_test_codegen_write_1vi16(1, HEDLEY_STATIC_CAST(size_t, len), e);

  return 1;
#endif
}

static int
test_simde_svdup_n_s32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const int8_t a = -INT8_C(  44);
  static const int32_t e[] =
    { -INT32_C(          44), -INT32_C(          44), -INT32_C(          44), -INT32_C(          44), -INT32_C(          44), -INT32_C(          44), -INT32_C(          44), -INT32_C(          44),
      -INT32_C(          44), -INT32_C(          44), -INT32_C(          44), -INT32_C(          44), -INT32_C(          44), -INT32_C(          44), -INT32_C(          44), -INT32_C(          44),
      -INT32_C(          44), -INT32_C(          44), -INT32_C(          44), -INT32_C(          44), -INT32_C(          44), -INT32_C(          44), -INT32_C(          44), -INT32_C(          44),
      -INT32_C(          44), -INT32_C(          44), -INT32_C(          44), -INT32_C(          44), -INT32_C(          44), -INT32_C(          44), -INT32_C(          44), -INT32_C(          44),
      -INT32_C(          44), -INT32_C(          44), -INT32_C(          44), -INT32_C(          44), -INT32_C(          44), -INT32_C(          44), -INT32_C(          44), -INT32_C(          44),
      -INT32_C(          44), -INT32_C(          44), -INT32_C(          44), -INT32_C(          44), -INT32_C(          44), -INT32_C(          44), -INT32_C(          44), -INT32_C(          44),
      -INT32_C(          44), -INT32_C(          44), -INT32_C(          44), -INT32_C(          44), -INT32_C(          44), -INT32_C(          44), -INT32_C(          44), -INT32_C(          44),
      -INT32_C(          44), -INT32_C(          44), -INT32_C(          44), -INT32_C(          44), -INT32_C(          44), -INT32_C(          44), -INT32_C(          44), -INT32_C(          44),
      -INT32_C(          44), -INT32_C(          44), -INT32_C(          44), -INT32_C(          44), -INT32_C(          44), -INT32_C(          44), -INT32_C(          44), -INT32_C(          44),
      -INT32_C(          44), -INT32_C(          44), -INT32_C(          44), -INT32_C(          44), -INT32_C(          44), -INT32_C(          44), -INT32_C(          44), -INT32_C(          44),
      -INT32_C(          44), -INT32_C(          44), -INT32_C(          44), -INT32_C(          44), -INT32_C(          44), -INT32_C(          44), -INT32_C(          44), -INT32_C(          44),
      -INT32_C(          44), -INT32_C(          44), -INT32_C(          44), -INT32_C(          44), -INT32_C(          44), -INT32_C(          44), -INT32_C(          44), -INT32_C(          44),
      -INT32_C(          44), -INT32_C(          44), -INT32_C(          44), -INT32_C(          44), -INT32_C(          44), -INT32_C(          44), -INT32_C(          44), -INT32_C(          44),
      -INT32_C(          44), -INT32_C(          44), -INT32_C(          44), -INT32_C(          44), -INT32_C(          44), -INT32_C(          44), -INT32_C(          44), -INT32_C(          44),
      -INT32_C(          44), -INT32_C(          44), -INT32_C(          44), -INT32_C(          44), -INT32_C(          44), -INT32_C(          44), -INT32_C(          44), -INT32_C(          44),
      -INT32_C(          44), -INT32_C(          44), -INT32_C(          44), -INT32_C(          44), -INT32_C(          44), -INT32_C(          44), -INT32_C(          44), -INT32_C(          44),
      -INT32_C(          44), -INT32_C(          44), -INT32_C(          44), -INT32_C(          44), -INT32_C(          44), -INT32_C(          44), -INT32_C(          44), -INT32_C(          44),
      -INT32_C(          44), -INT32_C(          44), -INT32_C(          44), -INT32_C(          44), -INT32_C(          44), -INT32_C(          44), -INT32_C(          44), -INT32_C(          44),
      -INT32_C(          44), -INT32_C(          44), -INT32_C(          44), -INT32_C(          44), -INT32_C(          44), -INT32_C(          44), -INT32_C(          44), -INT32_C(          44),
      -INT32_C(          44), -INT32_C(          44), -INT32_C(          44), -INT32_C(          44), -INT32_C(          44), -INT32_C(          44), -INT32_C(          44), -INT32_C(          44),
      -INT32_C(          44), -INT32_C(          44), -INT32_C(          44), -INT32_C(          44), -INT32_C(          44), -INT32_C(          44), -INT32_C(          44), -INT32_C(          44),
      -INT32_C(          44), -INT32_C(          44), -INT32_C(          44), -INT32_C(          44), -INT32_C(          44), -INT32_C(          44), -INT32_C(          44), -INT32_C(          44),
      -INT32_C(          44), -INT32_C(          44) };

  static int32_t r[sizeof(e) / sizeof(e[0])];
  static const int32_t len = HEDLEY_STATIC_CAST(int32_t, sizeof(e) / sizeof(e[0]));
  int32_t i = 0;
  simde_svbool_t pg = simde_svwhilelt_b32_s32(i, len);
  while (simde_svptest_first(simde_svptrue_b32(), pg)) {
    simde_svint32_t rv;

    rv = simde_svdup_n_s32(a);

    simde_svst1_s32(pg, &(r[i]), rv);

    i += simde_svcntw();
    pg = simde_svwhilelt_b32_s32(i, len);
  }

  simde_assert_equal_vi32(len, e, r);

  return 0;
#else
  int32_t a, e[1024 / sizeof(int32_t)];
  int32_t len;

  fputc('\n', stdout);

  len = simde_test_codegen_random_i32() & ((sizeof(e) / sizeof(e[0])) - 1);
  a = simde_test_codegen_random_i32();

  int32_t i = 0;
  simde_svbool_t pg = simde_svwhilelt_b32_s32(i, len);
  while (simde_svptest_first(simde_svptrue_b32(), pg)) {
    simde_svint32_t ev;

    ev = simde_svdup_n_s32(a);

    simde_svst1_s32(pg, &(e[i]), ev);

    i += simde_svcntw();
    pg = simde_svwhilelt_b32_s32(i, len);
  }

  simde_test_codegen_write_1i8(1, a);
  simde_test_codegen_write_1vi32(1, HEDLEY_STATIC_CAST(size_t, len), e);

  return 1;
#endif
}

static int
test_simde_svdup_n_s32_z (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const int32_t p[] =
    {  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),
      -INT32_C(           1), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),
      -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),
      -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),
      -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),
      -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),
      -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),
      -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),
      -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),
      -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),
       INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),
       INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),
      -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),
      -INT32_C(           1), -INT32_C(           1) };
  static const int32_t a = -INT32_C(          27);
  static const int32_t e[] =
    {  INT32_C(           0), -INT32_C(          27), -INT32_C(          27),  INT32_C(           0), -INT32_C(          27),  INT32_C(           0), -INT32_C(          27), -INT32_C(          27),
      -INT32_C(          27), -INT32_C(          27),  INT32_C(           0), -INT32_C(          27), -INT32_C(          27),  INT32_C(           0), -INT32_C(          27), -INT32_C(          27),
      -INT32_C(          27), -INT32_C(          27), -INT32_C(          27),  INT32_C(           0), -INT32_C(          27), -INT32_C(          27),  INT32_C(           0), -INT32_C(          27),
      -INT32_C(          27), -INT32_C(          27), -INT32_C(          27), -INT32_C(          27), -INT32_C(          27), -INT32_C(          27), -INT32_C(          27), -INT32_C(          27),
      -INT32_C(          27), -INT32_C(          27), -INT32_C(          27), -INT32_C(          27),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),
      -INT32_C(          27), -INT32_C(          27),  INT32_C(           0),  INT32_C(           0), -INT32_C(          27), -INT32_C(          27),  INT32_C(           0),  INT32_C(           0),
      -INT32_C(          27), -INT32_C(          27), -INT32_C(          27), -INT32_C(          27), -INT32_C(          27), -INT32_C(          27),  INT32_C(           0), -INT32_C(          27),
      -INT32_C(          27), -INT32_C(          27),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(          27),
      -INT32_C(          27), -INT32_C(          27),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),
      -INT32_C(          27), -INT32_C(          27),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),
       INT32_C(           0), -INT32_C(          27),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),
       INT32_C(           0),  INT32_C(           0), -INT32_C(          27), -INT32_C(          27),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),
      -INT32_C(          27), -INT32_C(          27), -INT32_C(          27), -INT32_C(          27), -INT32_C(          27), -INT32_C(          27), -INT32_C(          27), -INT32_C(          27),
      -INT32_C(          27), -INT32_C(          27) };

  static int32_t r[sizeof(e) / sizeof(e[0])];
  static const int32_t len = HEDLEY_STATIC_CAST(int32_t, sizeof(e) / sizeof(e[0]));
  int32_t i = 0;
  simde_svbool_t pg = simde_svwhilelt_b32_s32(i, len);
  while (simde_svptest_first(simde_svptrue_b32(), pg)) {
    simde_svint32_t rv;
    simde_svbool_t pv;

    pv = simde_svcmplt_s32(pg, simde_svld1_s32(pg, &(p[i])), simde_svdup_n_s32(INT32_C(0)));
    rv = simde_svdup_n_s32_z(pv, a);

    simde_svst1_s32(pg, &(r[i]), rv);

    i += simde_svcntw();
    pg = simde_svwhilelt_b32_s32(i, len);
  }

  simde_assert_equal_vi32(len, e, r);

  return 0;
#else
  int32_t a, p[1024 / sizeof(int32_t)], e[1024 / sizeof(int32_t)];
  int32_t len;

  fputc('\n', stdout);

  len = simde_test_codegen_random_i32() & ((sizeof(e) / sizeof(e[0])) - 1);
  simde_test_codegen_random_memory(sizeof(p), HEDLEY_REINTERPRET_CAST(uint8_t*, p));
  a = simde_test_codegen_random_i8();

  int32_t i = 0;
  simde_svbool_t pg = simde_svwhilelt_b32_s32(i, len);
  while (simde_svptest_first(simde_svptrue_b32(), pg)) {
    simde_svint32_t ev;
    simde_svbool_t pv;

    pv = simde_svcmplt_s32(pg, simde_svld1_s32(pg, &(p[i])), simde_svdup_n_s32(0));
    ev = simde_svdup_n_s32_z(pv, a);

    simde_svst1_s32(pg, &(e[i]), ev);
    simde_svst1_s32(pg, &(p[i]), simde_svdup_n_s32_z(pv, ~INT32_C(0)));

    i += simde_svcntw();
    pg = simde_svwhilelt_b32_s32(i, len);
  }

  simde_test_codegen_write_1vi32(1, HEDLEY_STATIC_CAST(size_t, len), p);
  simde_test_codegen_write_1i32(1, a);
  simde_test_codegen_write_1vi32(1, HEDLEY_STATIC_CAST(size_t, len), e);

  return 1;
#endif
}

static int
test_simde_svdup_n_s32_m (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const int32_t p[] =
    {  INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),
       INT32_C(           0), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),
       INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),
       INT32_C(           0), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),
      -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),
       INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),
      -INT32_C(           1),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),
      -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),
       INT32_C(           0),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),
      -INT32_C(           1),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),
       INT32_C(           0),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),
      -INT32_C(           1),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),
      -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),
       INT32_C(           0), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),
      -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),
      -INT32_C(           1),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),
      -INT32_C(           1), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),
      -INT32_C(           1),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),
       INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),
       INT32_C(           0), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),
      -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),
       INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),
       INT32_C(           0), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),
       INT32_C(           0), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),
       INT32_C(           0),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),
      -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),
      -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),
      -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),
      -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),
      -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0) };
  static const int32_t a[] =
    { -INT32_C(    48756944),  INT32_C(  1528977161),  INT32_C(   755471489), -INT32_C(  1733643678),  INT32_C(  1028932969),  INT32_C(  1474508581),  INT32_C(   236618853), -INT32_C(  1420425861),
       INT32_C(   363359756),  INT32_C(  1198574277), -INT32_C(  1049331873), -INT32_C(  1822810582), -INT32_C(  1982812572),  INT32_C(  1256305637), -INT32_C(  1285948616),  INT32_C(   207531776),
      -INT32_C(   484375010),  INT32_C(   791319248),  INT32_C(   871472649),  INT32_C(   566643645), -INT32_C(   559245575), -INT32_C(  2111272118), -INT32_C(  2026536569),  INT32_C(  1335137073),
       INT32_C(  1764930969),  INT32_C(  1369005383), -INT32_C(  1199273221), -INT32_C(   824620075),  INT32_C(   732726497), -INT32_C(  1766992881), -INT32_C(  2028019114),  INT32_C(   248951413),
      -INT32_C(  1351088025),  INT32_C(  1627394405),  INT32_C(  1880720539), -INT32_C(  1321274417), -INT32_C(  2032342409),  INT32_C(   337480382), -INT32_C(   493143188),  INT32_C(  1425043949),
      -INT32_C(   553424774),  INT32_C(   339739513),  INT32_C(  1468291720), -INT32_C(  1006058931),  INT32_C(  1800070572), -INT32_C(   612407441), -INT32_C(  1883432030),  INT32_C(   115650188),
      -INT32_C(  1863915754),  INT32_C(  1940137707), -INT32_C(   842389120), -INT32_C(  1735273493),  INT32_C(   654564536), -INT32_C(   436043197),  INT32_C(   712360093), -INT32_C(  2077206162),
       INT32_C(   739513921), -INT32_C(  1113605827), -INT32_C(   846501406), -INT32_C(   194700228),  INT32_C(  1008429304), -INT32_C(  2011029781),  INT32_C(  1286772702),  INT32_C(   852550641),
       INT32_C(   912188921), -INT32_C(  2131427938), -INT32_C(  1555202202), -INT32_C(  1801997413),  INT32_C(   114340635), -INT32_C(  1349520687),  INT32_C(  2063286665),  INT32_C(   514640676),
       INT32_C(  1314130608),  INT32_C(  1859012615),  INT32_C(  1662065863), -INT32_C(   352868145),  INT32_C(   754042715),  INT32_C(  1121681593), -INT32_C(   423766335),  INT32_C(  1376020898),
       INT32_C(  2074171508),  INT32_C(  1760128929),  INT32_C(  1523317387), -INT32_C(    28982621),  INT32_C(  1110128265),  INT32_C(  2005206710),  INT32_C(  2136818397),  INT32_C(   533815723),
       INT32_C(  1536914106),  INT32_C(  1841530082),  INT32_C(   583569279), -INT32_C(   618656431), -INT32_C(   115520701),  INT32_C(   795910738), -INT32_C(  1867591964), -INT32_C(   374374609),
      -INT32_C(   733721870),  INT32_C(  1312884943), -INT32_C(   395310697),  INT32_C(  1505988630),  INT32_C(   777183708),  INT32_C(  1750975363), -INT32_C(  1057485935),  INT32_C(  2091558794),
      -INT32_C(  1051660558), -INT32_C(  1928359178), -INT32_C(  1300856933), -INT32_C(   351586033), -INT32_C(  1642504678), -INT32_C(  1308199391),  INT32_C(   208862849), -INT32_C(  1752687451),
       INT32_C(    22599947),  INT32_C(   110061419), -INT32_C(   155712026),  INT32_C(  1507968062),  INT32_C(  1140325154), -INT32_C(   201982607), -INT32_C(  1593874437), -INT32_C(  1892120700),
      -INT32_C(   879718304), -INT32_C(   556654600),  INT32_C(  1674873380),  INT32_C(  1891415630),  INT32_C(   582202289), -INT32_C(  1424643920), -INT32_C(  1807018992), -INT32_C(    64781412),
       INT32_C(   214479636), -INT32_C(   135619885),  INT32_C(  1935327012),  INT32_C(   652416629),  INT32_C(  2034800585),  INT32_C(  1327783487),  INT32_C(   249786482),  INT32_C(   118163187),
      -INT32_C(  1928080454), -INT32_C(  1853555091),  INT32_C(   839180221), -INT32_C(  1084692235), -INT32_C(  1103585153),  INT32_C(  1896766974), -INT32_C(  1065356851), -INT32_C(  1295480072),
      -INT32_C(   901784739), -INT32_C(  1772305447), -INT32_C(  1731698526), -INT32_C(   950591416), -INT32_C(  1081700415), -INT32_C(  1187998484),  INT32_C(  2105192581), -INT32_C(  1741733318),
      -INT32_C(   144544227), -INT32_C(   728908238),  INT32_C(  1735153183),  INT32_C(   925877110),  INT32_C(  1073198419), -INT32_C(   822532279),  INT32_C(   307000279), -INT32_C(   760579147),
       INT32_C(   482938090), -INT32_C(   353347637),  INT32_C(   592534957),  INT32_C(  1935376416),  INT32_C(  2125681205),  INT32_C(  1364044921), -INT32_C(   731670241), -INT32_C(    22672108),
      -INT32_C(   468029415),  INT32_C(  1959660487), -INT32_C(  2003361688), -INT32_C(   688065888), -INT32_C(  1101746364),  INT32_C(  2047844699),  INT32_C(  1330541114), -INT32_C(  1739721601),
       INT32_C(   729639012), -INT32_C(   610317453),  INT32_C(   207828843),  INT32_C(  1860329257),  INT32_C(  1764505102),  INT32_C(   316881880),  INT32_C(   744567213), -INT32_C(  1966821594),
      -INT32_C(  1967767273), -INT32_C(   127576691), -INT32_C(  1241200500),  INT32_C(   908387880), -INT32_C(   174043107),  INT32_C(   940016523), -INT32_C(   614176331),  INT32_C(   795158552),
      -INT32_C(   138863766), -INT32_C(    34660751),  INT32_C(   246674662), -INT32_C(   146417702), -INT32_C(  1293097689),  INT32_C(   501937256),  INT32_C(  1979207261), -INT32_C(   509321609),
      -INT32_C(   354919047),  INT32_C(  1642645371), -INT32_C(  1771004997), -INT32_C(  1701989005),  INT32_C(    38632090), -INT32_C(   887081106), -INT32_C(    46131066), -INT32_C(   253827978),
      -INT32_C(  1126517183),  INT32_C(   958251645), -INT32_C(   774927010), -INT32_C(   596943806),  INT32_C(  1155512534),  INT32_C(  1980760048), -INT32_C(  1905045737),  INT32_C(  1954435379),
      -INT32_C(  2077206521),  INT32_C(  2042449435),  INT32_C(   508202203), -INT32_C(  1074088471),  INT32_C(  1577376110), -INT32_C(   254536744), -INT32_C(  1770109085), -INT32_C(  1626604392),
       INT32_C(  1864579924),  INT32_C(  1709760905),  INT32_C(  1451438701),  INT32_C(  1444314600),  INT32_C(   800332375), -INT32_C(  1876981715),  INT32_C(  1730649551), -INT32_C(   301583719),
      -INT32_C(   144889491),  INT32_C(  2019313162),  INT32_C(  1624170360), -INT32_C(  1279859620),  INT32_C(   753101566), -INT32_C(  1044643086) };
  static const int32_t b = -INT32_C(  1245423756);
  static const int32_t e[] =
    { -INT32_C(    48756944),  INT32_C(  1528977161), -INT32_C(  1245423756), -INT32_C(  1245423756), -INT32_C(  1245423756),  INT32_C(  1474508581),  INT32_C(   236618853), -INT32_C(  1245423756),
       INT32_C(   363359756), -INT32_C(  1245423756), -INT32_C(  1049331873), -INT32_C(  1245423756), -INT32_C(  1982812572),  INT32_C(  1256305637), -INT32_C(  1245423756), -INT32_C(  1245423756),
      -INT32_C(   484375010),  INT32_C(   791319248),  INT32_C(   871472649), -INT32_C(  1245423756), -INT32_C(  1245423756), -INT32_C(  1245423756), -INT32_C(  1245423756), -INT32_C(  1245423756),
       INT32_C(  1764930969), -INT32_C(  1245423756), -INT32_C(  1199273221), -INT32_C(  1245423756), -INT32_C(  1245423756), -INT32_C(  1245423756), -INT32_C(  1245423756),  INT32_C(   248951413),
      -INT32_C(  1245423756), -INT32_C(  1245423756),  INT32_C(  1880720539), -INT32_C(  1321274417), -INT32_C(  1245423756), -INT32_C(  1245423756), -INT32_C(   493143188),  INT32_C(  1425043949),
      -INT32_C(   553424774),  INT32_C(   339739513), -INT32_C(  1245423756), -INT32_C(  1245423756),  INT32_C(  1800070572), -INT32_C(   612407441), -INT32_C(  1245423756), -INT32_C(  1245423756),
      -INT32_C(  1245423756),  INT32_C(  1940137707), -INT32_C(  1245423756), -INT32_C(  1245423756),  INT32_C(   654564536), -INT32_C(  1245423756), -INT32_C(  1245423756), -INT32_C(  1245423756),
      -INT32_C(  1245423756), -INT32_C(  1245423756), -INT32_C(  1245423756), -INT32_C(  1245423756),  INT32_C(  1008429304), -INT32_C(  1245423756), -INT32_C(  1245423756),  INT32_C(   852550641),
       INT32_C(   912188921), -INT32_C(  2131427938), -INT32_C(  1245423756), -INT32_C(  1801997413),  INT32_C(   114340635), -INT32_C(  1245423756), -INT32_C(  1245423756),  INT32_C(   514640676),
      -INT32_C(  1245423756),  INT32_C(  1859012615),  INT32_C(  1662065863), -INT32_C(  1245423756), -INT32_C(  1245423756), -INT32_C(  1245423756), -INT32_C(   423766335), -INT32_C(  1245423756),
       INT32_C(  2074171508),  INT32_C(  1760128929), -INT32_C(  1245423756), -INT32_C(    28982621), -INT32_C(  1245423756),  INT32_C(  2005206710), -INT32_C(  1245423756), -INT32_C(  1245423756),
      -INT32_C(  1245423756),  INT32_C(  1841530082),  INT32_C(   583569279), -INT32_C(  1245423756), -INT32_C(   115520701),  INT32_C(   795910738), -INT32_C(  1245423756), -INT32_C(  1245423756),
      -INT32_C(  1245423756), -INT32_C(  1245423756), -INT32_C(  1245423756), -INT32_C(  1245423756), -INT32_C(  1245423756), -INT32_C(  1245423756), -INT32_C(  1245423756), -INT32_C(  1245423756),
      -INT32_C(  1051660558), -INT32_C(  1245423756), -INT32_C(  1300856933), -INT32_C(  1245423756), -INT32_C(  1642504678), -INT32_C(  1245423756), -INT32_C(  1245423756), -INT32_C(  1752687451),
      -INT32_C(  1245423756),  INT32_C(   110061419), -INT32_C(  1245423756),  INT32_C(  1507968062), -INT32_C(  1245423756), -INT32_C(  1245423756), -INT32_C(  1593874437), -INT32_C(  1245423756),
      -INT32_C(  1245423756), -INT32_C(   556654600), -INT32_C(  1245423756), -INT32_C(  1245423756),  INT32_C(   582202289), -INT32_C(  1424643920), -INT32_C(  1245423756), -INT32_C(  1245423756),
      -INT32_C(  1245423756), -INT32_C(  1245423756),  INT32_C(  1935327012), -INT32_C(  1245423756),  INT32_C(  2034800585),  INT32_C(  1327783487), -INT32_C(  1245423756), -INT32_C(  1245423756),
      -INT32_C(  1245423756), -INT32_C(  1853555091),  INT32_C(   839180221), -INT32_C(  1245423756), -INT32_C(  1245423756), -INT32_C(  1245423756), -INT32_C(  1245423756), -INT32_C(  1245423756),
      -INT32_C(   901784739), -INT32_C(  1772305447), -INT32_C(  1731698526), -INT32_C(  1245423756), -INT32_C(  1081700415), -INT32_C(  1187998484), -INT32_C(  1245423756), -INT32_C(  1741733318),
      -INT32_C(   144544227), -INT32_C(  1245423756),  INT32_C(  1735153183), -INT32_C(  1245423756), -INT32_C(  1245423756), -INT32_C(   822532279), -INT32_C(  1245423756), -INT32_C(   760579147),
      -INT32_C(  1245423756), -INT32_C(   353347637), -INT32_C(  1245423756),  INT32_C(  1935376416), -INT32_C(  1245423756), -INT32_C(  1245423756), -INT32_C(   731670241), -INT32_C(    22672108),
      -INT32_C(   468029415),  INT32_C(  1959660487), -INT32_C(  2003361688), -INT32_C(  1245423756), -INT32_C(  1245423756),  INT32_C(  2047844699),  INT32_C(  1330541114), -INT32_C(  1739721601),
       INT32_C(   729639012), -INT32_C(  1245423756),  INT32_C(   207828843), -INT32_C(  1245423756),  INT32_C(  1764505102), -INT32_C(  1245423756),  INT32_C(   744567213), -INT32_C(  1966821594),
      -INT32_C(  1967767273), -INT32_C(  1245423756), -INT32_C(  1241200500), -INT32_C(  1245423756), -INT32_C(   174043107),  INT32_C(   940016523), -INT32_C(  1245423756), -INT32_C(  1245423756),
      -INT32_C(   138863766), -INT32_C(    34660751), -INT32_C(  1245423756), -INT32_C(   146417702), -INT32_C(  1245423756),  INT32_C(   501937256),  INT32_C(  1979207261), -INT32_C(   509321609),
      -INT32_C(  1245423756), -INT32_C(  1245423756), -INT32_C(  1245423756), -INT32_C(  1701989005), -INT32_C(  1245423756), -INT32_C(  1245423756), -INT32_C(    46131066), -INT32_C(   253827978),
      -INT32_C(  1245423756),  INT32_C(   958251645), -INT32_C(  1245423756), -INT32_C(   596943806), -INT32_C(  1245423756), -INT32_C(  1245423756), -INT32_C(  1905045737),  INT32_C(  1954435379),
      -INT32_C(  1245423756),  INT32_C(  2042449435), -INT32_C(  1245423756), -INT32_C(  1074088471), -INT32_C(  1245423756), -INT32_C(   254536744), -INT32_C(  1245423756), -INT32_C(  1626604392),
      -INT32_C(  1245423756),  INT32_C(  1709760905),  INT32_C(  1451438701),  INT32_C(  1444314600), -INT32_C(  1245423756), -INT32_C(  1876981715), -INT32_C(  1245423756), -INT32_C(   301583719),
      -INT32_C(  1245423756), -INT32_C(  1245423756),  INT32_C(  1624170360), -INT32_C(  1279859620),  INT32_C(   753101566), -INT32_C(  1044643086) };

  static int32_t r[sizeof(e) / sizeof(e[0])];
  static const int32_t len = HEDLEY_STATIC_CAST(int32_t, sizeof(e) / sizeof(e[0]));
  int32_t i = 0;
  simde_svbool_t pg = simde_svwhilelt_b32_s32(i, len);
  while (simde_svptest_first(simde_svptrue_b32(), pg)) {
    simde_svint32_t
      rv,
      av = simde_svld1_s32(pg, &(a[i]));
    simde_svbool_t pv;

    pv = simde_svcmplt_s32(pg, simde_svld1_s32(pg, &(p[i])), simde_svdup_n_s32(INT32_C(0)));
    rv = simde_svdup_n_s32_m(av, pv, b);

    simde_svst1_s32(pg, &(r[i]), rv);

    i += simde_svcntw();
    pg = simde_svwhilelt_b32_s32(i, len);
  }

  simde_assert_equal_vi32(len, e, r);

  return 0;
#else
  int32_t p[1024 / sizeof(int32_t)], a[1024 / sizeof(int32_t)], b, e[1024 / sizeof(int32_t)];
  int32_t len = simde_test_arm_sve_random_length(sizeof(e), sizeof(e[0]));

  fputc('\n', stdout);

  simde_test_codegen_random_memory(sizeof(p), HEDLEY_REINTERPRET_CAST(uint8_t*, p));
  simde_test_codegen_random_memory(sizeof(a), HEDLEY_REINTERPRET_CAST(uint8_t*, a));
  b = simde_test_codegen_random_i32();

  int32_t i = 0;
  simde_svbool_t pg = simde_svwhilelt_b32_s32(i, len);
  while (simde_svptest_first(simde_svptrue_b32(), pg)) {
    simde_svint32_t av, ev;
    simde_svbool_t pv;

    pv = simde_svcmplt_s32(pg, simde_svld1_s32(pg, &(p[i])), simde_svdup_n_s32(0));
    av = simde_svld1_s32(pg, &(a[i]));

    ev = simde_svdup_n_s32_m(av, pv, b);

    simde_svst1_s32(pg, &(e[i]), ev);
    simde_svst1_s32(pg, &(p[i]), simde_svdup_n_s32_z(pv, ~INT32_C(0)));

    i += simde_svcntw();
    pg = simde_svwhilelt_b32_s32(i, len);
  }

  simde_test_codegen_write_1vi32(1, HEDLEY_STATIC_CAST(size_t, len), p);
  simde_test_codegen_write_1vi32(1, HEDLEY_STATIC_CAST(size_t, len), a);
  simde_test_codegen_write_1i32(1, b);
  simde_test_codegen_write_1vi32(1, HEDLEY_STATIC_CAST(size_t, len), e);

  return 1;
#endif
}

static int
test_simde_svdup_n_s64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const int8_t a =  INT8_C( 119);
  static const int64_t e[] =
    {  INT64_C(                 119),  INT64_C(                 119),  INT64_C(                 119),  INT64_C(                 119),
       INT64_C(                 119),  INT64_C(                 119),  INT64_C(                 119),  INT64_C(                 119),
       INT64_C(                 119),  INT64_C(                 119),  INT64_C(                 119),  INT64_C(                 119),
       INT64_C(                 119),  INT64_C(                 119),  INT64_C(                 119),  INT64_C(                 119),
       INT64_C(                 119),  INT64_C(                 119),  INT64_C(                 119),  INT64_C(                 119),
       INT64_C(                 119),  INT64_C(                 119),  INT64_C(                 119),  INT64_C(                 119),
       INT64_C(                 119),  INT64_C(                 119),  INT64_C(                 119),  INT64_C(                 119),
       INT64_C(                 119),  INT64_C(                 119),  INT64_C(                 119),  INT64_C(                 119),
       INT64_C(                 119),  INT64_C(                 119),  INT64_C(                 119),  INT64_C(                 119),
       INT64_C(                 119),  INT64_C(                 119),  INT64_C(                 119),  INT64_C(                 119),
       INT64_C(                 119),  INT64_C(                 119),  INT64_C(                 119),  INT64_C(                 119),
       INT64_C(                 119),  INT64_C(                 119),  INT64_C(                 119),  INT64_C(                 119),
       INT64_C(                 119),  INT64_C(                 119),  INT64_C(                 119),  INT64_C(                 119),
       INT64_C(                 119),  INT64_C(                 119),  INT64_C(                 119),  INT64_C(                 119),
       INT64_C(                 119),  INT64_C(                 119),  INT64_C(                 119),  INT64_C(                 119),
       INT64_C(                 119),  INT64_C(                 119),  INT64_C(                 119),  INT64_C(                 119),
       INT64_C(                 119),  INT64_C(                 119),  INT64_C(                 119),  INT64_C(                 119),
       INT64_C(                 119),  INT64_C(                 119),  INT64_C(                 119),  INT64_C(                 119),
       INT64_C(                 119),  INT64_C(                 119),  INT64_C(                 119),  INT64_C(                 119),
       INT64_C(                 119),  INT64_C(                 119),  INT64_C(                 119),  INT64_C(                 119),
       INT64_C(                 119),  INT64_C(                 119),  INT64_C(                 119),  INT64_C(                 119),
       INT64_C(                 119),  INT64_C(                 119),  INT64_C(                 119),  INT64_C(                 119),
       INT64_C(                 119),  INT64_C(                 119),  INT64_C(                 119),  INT64_C(                 119),
       INT64_C(                 119),  INT64_C(                 119),  INT64_C(                 119),  INT64_C(                 119),
       INT64_C(                 119),  INT64_C(                 119),  INT64_C(                 119),  INT64_C(                 119),
       INT64_C(                 119),  INT64_C(                 119),  INT64_C(                 119),  INT64_C(                 119),
       INT64_C(                 119),  INT64_C(                 119),  INT64_C(                 119),  INT64_C(                 119),
       INT64_C(                 119),  INT64_C(                 119),  INT64_C(                 119),  INT64_C(                 119),
       INT64_C(                 119),  INT64_C(                 119),  INT64_C(                 119),  INT64_C(                 119),
       INT64_C(                 119),  INT64_C(                 119),  INT64_C(                 119),  INT64_C(                 119),
       INT64_C(                 119),  INT64_C(                 119) };

  static int64_t r[sizeof(e) / sizeof(e[0])];
  static const int64_t len = HEDLEY_STATIC_CAST(int64_t, sizeof(e) / sizeof(e[0]));
  int32_t i = 0;
  simde_svbool_t pg = simde_svwhilelt_b64_s32(i, len);
  while (simde_svptest_first(simde_svptrue_b64(), pg)) {
    simde_svint64_t rv;

    rv = simde_svdup_n_s64(a);

    simde_svst1_s64(pg, &(r[i]), rv);

    i += simde_svcntd();
    pg = simde_svwhilelt_b64_s32(i, len);
  }

  simde_assert_equal_vi64(len, e, r);

  return 0;
#else
  int64_t a, e[1024 / sizeof(int64_t)];
  int64_t len;

  fputc('\n', stdout);

  len = simde_test_codegen_random_i64() & ((sizeof(e) / sizeof(e[0])) - 1);
  a = simde_test_codegen_random_i64();

  int64_t i = 0;
  simde_svbool_t pg = simde_svwhilelt_b64_s32(i, len);
  while (simde_svptest_first(simde_svptrue_b64(), pg)) {
    simde_svint64_t ev;

    ev = simde_svdup_n_s64(a);

    simde_svst1_s64(pg, &(e[i]), ev);

    i += simde_svcntd();
    pg = simde_svwhilelt_b64_s32(i, len);
  }

  simde_test_codegen_write_1i8(1, a);
  simde_test_codegen_write_1vi64(1, HEDLEY_STATIC_CAST(size_t, len), e);

  return 1;
#endif
}

static int
test_simde_svdup_n_s64_z (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const int64_t p[] =
    { -INT64_C(                   1), -INT64_C(                   1),  INT64_C(                   0), -INT64_C(                   1),
      -INT64_C(                   1), -INT64_C(                   1),  INT64_C(                   0),  INT64_C(                   0),
      -INT64_C(                   1),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),
      -INT64_C(                   1), -INT64_C(                   1), -INT64_C(                   1), -INT64_C(                   1),
      -INT64_C(                   1),  INT64_C(                   0),  INT64_C(                   0), -INT64_C(                   1),
       INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),
      -INT64_C(                   1),  INT64_C(                   0), -INT64_C(                   1), -INT64_C(                   1),
       INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),
       INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),
       INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),
       INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0), -INT64_C(                   1),
       INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0), -INT64_C(                   1),
       INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),
       INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),
       INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0) };
  static const int64_t a =  INT64_C(                 106);
  static const int64_t e[] =
    {  INT64_C(                 106),  INT64_C(                 106),  INT64_C(                   0),  INT64_C(                 106),
       INT64_C(                 106),  INT64_C(                 106),  INT64_C(                   0),  INT64_C(                   0),
       INT64_C(                 106),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),
       INT64_C(                 106),  INT64_C(                 106),  INT64_C(                 106),  INT64_C(                 106),
       INT64_C(                 106),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                 106),
       INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),
       INT64_C(                 106),  INT64_C(                   0),  INT64_C(                 106),  INT64_C(                 106),
       INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),
       INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),
       INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),
       INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                 106),
       INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                 106),
       INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),
       INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),
       INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0) };

  static int64_t r[sizeof(e) / sizeof(e[0])];
  static const int64_t len = HEDLEY_STATIC_CAST(int64_t, sizeof(e) / sizeof(e[0]));
  int32_t i = 0;
  simde_svbool_t pg = simde_svwhilelt_b64_s32(i, len);
  while (simde_svptest_first(simde_svptrue_b64(), pg)) {
    simde_svint64_t rv;
    simde_svbool_t pv;

    pv = simde_svcmplt_s64(pg, simde_svld1_s64(pg, &(p[i])), simde_svdup_n_s64(INT64_C(0)));
    rv = simde_svdup_n_s64_z(pv, a);

    simde_svst1_s64(pg, &(r[i]), rv);

    i += simde_svcntd();
    pg = simde_svwhilelt_b64_s32(i, len);
  }

  simde_assert_equal_vi64(len, e, r);

  return 0;
#else
  int64_t a, p[1024 / sizeof(int64_t)], e[1024 / sizeof(int64_t)];
  int64_t len;

  fputc('\n', stdout);

  len = simde_test_codegen_random_i64() & ((sizeof(e) / sizeof(e[0])) - 1);
  simde_test_codegen_random_memory(sizeof(p), HEDLEY_REINTERPRET_CAST(uint8_t*, p));
  a = simde_test_codegen_random_i8();

  int64_t i = 0;
  simde_svbool_t pg = simde_svwhilelt_b64_s32(i, len);
  while (simde_svptest_first(simde_svptrue_b64(), pg)) {
    simde_svint64_t ev;
    simde_svbool_t pv;

    pv = simde_svcmplt_s64(pg, simde_svld1_s64(pg, &(p[i])), simde_svdup_n_s64(0));
    ev = simde_svdup_n_s64_z(pv, a);

    simde_svst1_s64(pg, &(e[i]), ev);
    simde_svst1_s64(pg, &(p[i]), simde_svdup_n_s64_z(pv, ~INT64_C(0)));

    i += simde_svcntd();
    pg = simde_svwhilelt_b64_s32(i, len);
  }

  simde_test_codegen_write_1vi64(1, HEDLEY_STATIC_CAST(size_t, len), p);
  simde_test_codegen_write_1i64(1, a);
  simde_test_codegen_write_1vi64(1, HEDLEY_STATIC_CAST(size_t, len), e);

  return 1;
#endif
}

static int
test_simde_svdup_n_s64_m (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const int64_t p[] =
    {  INT64_C(                   0),  INT64_C(                   0), -INT64_C(                   1),  INT64_C(                   0),
      -INT64_C(                   1),  INT64_C(                   0), -INT64_C(                   1),  INT64_C(                   0),
       INT64_C(                   0),  INT64_C(                   0), -INT64_C(                   1), -INT64_C(                   1),
       INT64_C(                   0), -INT64_C(                   1), -INT64_C(                   1),  INT64_C(                   0),
       INT64_C(                   0),  INT64_C(                   0), -INT64_C(                   1),  INT64_C(                   0),
      -INT64_C(                   1),  INT64_C(                   0),  INT64_C(                   0), -INT64_C(                   1),
      -INT64_C(                   1),  INT64_C(                   0), -INT64_C(                   1),  INT64_C(                   0),
      -INT64_C(                   1),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),
      -INT64_C(                   1), -INT64_C(                   1), -INT64_C(                   1), -INT64_C(                   1),
      -INT64_C(                   1), -INT64_C(                   1),  INT64_C(                   0),  INT64_C(                   0),
       INT64_C(                   0), -INT64_C(                   1), -INT64_C(                   1), -INT64_C(                   1),
       INT64_C(                   0),  INT64_C(                   0), -INT64_C(                   1),  INT64_C(                   0),
      -INT64_C(                   1), -INT64_C(                   1),  INT64_C(                   0), -INT64_C(                   1),
       INT64_C(                   0), -INT64_C(                   1), -INT64_C(                   1),  INT64_C(                   0),
       INT64_C(                   0), -INT64_C(                   1), -INT64_C(                   1), -INT64_C(                   1),
       INT64_C(                   0),  INT64_C(                   0), -INT64_C(                   1), -INT64_C(                   1),
       INT64_C(                   0),  INT64_C(                   0), -INT64_C(                   1),  INT64_C(                   0),
       INT64_C(                   0), -INT64_C(                   1), -INT64_C(                   1),  INT64_C(                   0),
      -INT64_C(                   1),  INT64_C(                   0), -INT64_C(                   1), -INT64_C(                   1),
       INT64_C(                   0), -INT64_C(                   1),  INT64_C(                   0), -INT64_C(                   1),
      -INT64_C(                   1),  INT64_C(                   0), -INT64_C(                   1), -INT64_C(                   1),
       INT64_C(                   0), -INT64_C(                   1),  INT64_C(                   0),  INT64_C(                   0),
      -INT64_C(                   1),  INT64_C(                   0),  INT64_C(                   0), -INT64_C(                   1),
      -INT64_C(                   1),  INT64_C(                   0), -INT64_C(                   1), -INT64_C(                   1),
      -INT64_C(                   1),  INT64_C(                   0), -INT64_C(                   1), -INT64_C(                   1),
      -INT64_C(                   1),  INT64_C(                   0),  INT64_C(                   0), -INT64_C(                   1),
       INT64_C(                   0),  INT64_C(                   0), -INT64_C(                   1), -INT64_C(                   1),
       INT64_C(                   0), -INT64_C(                   1), -INT64_C(                   1), -INT64_C(                   1),
       INT64_C(                   0), -INT64_C(                   1) };
  static const int64_t a[] =
    {  INT64_C( 3628583581354659803),  INT64_C( 4346881908059426226),  INT64_C( 5270818856939271240),  INT64_C( 7941309126659515255),
      -INT64_C( 5873090853689709887),  INT64_C( 8444402330806842083), -INT64_C( 6315271322762970305),  INT64_C( 7731071604713813833),
      -INT64_C(   99865226925079309), -INT64_C( 6860914760184834777),  INT64_C( 4140794809829968542), -INT64_C( 4136169422147188091),
      -INT64_C( 5909757875559509789), -INT64_C( 5897521915173409241),  INT64_C( 7871999575563557397), -INT64_C( 7703348122610871425),
       INT64_C( 5095980341870710149), -INT64_C( 7404773737623537283),  INT64_C( 3325025072164289231),  INT64_C( 8824691276185190447),
       INT64_C( 1715094766989150823),  INT64_C( 6923689112329624567), -INT64_C( 4649618549850524772), -INT64_C(  330143119693448452),
       INT64_C( 2725889637104087330), -INT64_C(  586956297402746391),  INT64_C( 3006641131887980905), -INT64_C( 7762650557275546954),
      -INT64_C(   14877398867523721), -INT64_C( 8362811623354045282), -INT64_C( 6441485639588957116), -INT64_C( 5503902063090616680),
      -INT64_C( 5543329622208745475),  INT64_C( 2467302850169768847), -INT64_C( 7464382127567224110), -INT64_C( 8154540562483881242),
      -INT64_C( 2236121528341025488),  INT64_C( 1530888810501678142), -INT64_C( 1645712705239592047),  INT64_C( 4303717257500674971),
       INT64_C( 5422183375681116685),  INT64_C( 3563656412882522396),  INT64_C( 2910991727080918137),  INT64_C( 6772584055127175350),
       INT64_C( 1207523202477882728),  INT64_C( 5160532323270076620),  INT64_C(   64783546136616752), -INT64_C( 5744695054312588648),
      -INT64_C( 3944899298467708357), -INT64_C( 4312809531329105905), -INT64_C( 6234273735356782543),  INT64_C( 3934977275938880675),
      -INT64_C( 5287041623217749542), -INT64_C( 2832841509729675945),  INT64_C( 4493693696315962017), -INT64_C( 6900423074757546486),
      -INT64_C( 6853327129871408506), -INT64_C( 3212408825083889428), -INT64_C( 7618153728095961491), -INT64_C( 4884760491863543601),
      -INT64_C( 5808289179671810950), -INT64_C( 7472407279484866489), -INT64_C( 9039033741457960597),  INT64_C( 8955774007355386455),
       INT64_C( 5363124166746715386), -INT64_C( 4010438572833001579),  INT64_C( 3825331651383195873),  INT64_C( 8572052669521342072),
       INT64_C( 8182372965882738496),  INT64_C( 4716827233056018768), -INT64_C(  318088149667072639), -INT64_C( 6697859370824935654),
       INT64_C( 3526447015798390947),  INT64_C( 3127560456476893637),  INT64_C( 4829863382247685256), -INT64_C( 8322961169260642953),
      -INT64_C( 7117943780802862042), -INT64_C( 1085039410014907364),  INT64_C( 1356150404462443366), -INT64_C( 5191125822694708352),
       INT64_C( 1677016897465221327), -INT64_C( 7466459991149574135), -INT64_C( 2163986901371495094),  INT64_C( 2156731976219550629),
      -INT64_C( 6173580076080911296),  INT64_C( 5322266295429443857), -INT64_C( 6765772245660990503), -INT64_C( 1840627934241987319),
       INT64_C( 6034389477372344434),  INT64_C( 3454106255215810982),  INT64_C( 5482433546627391094),  INT64_C( 2843204804025773802),
      -INT64_C( 5483704234082134192),  INT64_C( 7374444206365441234),  INT64_C( 3456494321528324455),  INT64_C(  195964525344692957),
      -INT64_C( 4788318249926986804), -INT64_C( 7616927068837255434), -INT64_C( 1048433728080042498),  INT64_C( 3640662660271452882),
      -INT64_C( 8514168812972860882), -INT64_C(  629453941382333314), -INT64_C( 8222254897408801825), -INT64_C( 3424539318422509600),
      -INT64_C( 7291679519018482511), -INT64_C( 2923246312670937731),  INT64_C( 3987567311665670414), -INT64_C( 5798112946362161386),
      -INT64_C( 5822378945194790533),  INT64_C( 1354900712427190782),  INT64_C( 6686210775983036220), -INT64_C( 5096495610680031080),
      -INT64_C(  509043122025449458), -INT64_C( 2012339753236687620) };
  static const int64_t b = -INT64_C( 5186611020917853902);
  static const int64_t e[] =
    {  INT64_C( 3628583581354659803),  INT64_C( 4346881908059426226), -INT64_C( 5186611020917853902),  INT64_C( 7941309126659515255),
      -INT64_C( 5186611020917853902),  INT64_C( 8444402330806842083), -INT64_C( 5186611020917853902),  INT64_C( 7731071604713813833),
      -INT64_C(   99865226925079309), -INT64_C( 6860914760184834777), -INT64_C( 5186611020917853902), -INT64_C( 5186611020917853902),
      -INT64_C( 5909757875559509789), -INT64_C( 5186611020917853902), -INT64_C( 5186611020917853902), -INT64_C( 7703348122610871425),
       INT64_C( 5095980341870710149), -INT64_C( 7404773737623537283), -INT64_C( 5186611020917853902),  INT64_C( 8824691276185190447),
      -INT64_C( 5186611020917853902),  INT64_C( 6923689112329624567), -INT64_C( 4649618549850524772), -INT64_C( 5186611020917853902),
      -INT64_C( 5186611020917853902), -INT64_C(  586956297402746391), -INT64_C( 5186611020917853902), -INT64_C( 7762650557275546954),
      -INT64_C( 5186611020917853902), -INT64_C( 8362811623354045282), -INT64_C( 6441485639588957116), -INT64_C( 5503902063090616680),
      -INT64_C( 5186611020917853902), -INT64_C( 5186611020917853902), -INT64_C( 5186611020917853902), -INT64_C( 5186611020917853902),
      -INT64_C( 5186611020917853902), -INT64_C( 5186611020917853902), -INT64_C( 1645712705239592047),  INT64_C( 4303717257500674971),
       INT64_C( 5422183375681116685), -INT64_C( 5186611020917853902), -INT64_C( 5186611020917853902), -INT64_C( 5186611020917853902),
       INT64_C( 1207523202477882728),  INT64_C( 5160532323270076620), -INT64_C( 5186611020917853902), -INT64_C( 5744695054312588648),
      -INT64_C( 5186611020917853902), -INT64_C( 5186611020917853902), -INT64_C( 6234273735356782543), -INT64_C( 5186611020917853902),
      -INT64_C( 5287041623217749542), -INT64_C( 5186611020917853902), -INT64_C( 5186611020917853902), -INT64_C( 6900423074757546486),
      -INT64_C( 6853327129871408506), -INT64_C( 5186611020917853902), -INT64_C( 5186611020917853902), -INT64_C( 5186611020917853902),
      -INT64_C( 5808289179671810950), -INT64_C( 7472407279484866489), -INT64_C( 5186611020917853902), -INT64_C( 5186611020917853902),
       INT64_C( 5363124166746715386), -INT64_C( 4010438572833001579), -INT64_C( 5186611020917853902),  INT64_C( 8572052669521342072),
       INT64_C( 8182372965882738496), -INT64_C( 5186611020917853902), -INT64_C( 5186611020917853902), -INT64_C( 6697859370824935654),
      -INT64_C( 5186611020917853902),  INT64_C( 3127560456476893637), -INT64_C( 5186611020917853902), -INT64_C( 5186611020917853902),
      -INT64_C( 7117943780802862042), -INT64_C( 5186611020917853902),  INT64_C( 1356150404462443366), -INT64_C( 5186611020917853902),
      -INT64_C( 5186611020917853902), -INT64_C( 7466459991149574135), -INT64_C( 5186611020917853902), -INT64_C( 5186611020917853902),
      -INT64_C( 6173580076080911296), -INT64_C( 5186611020917853902), -INT64_C( 6765772245660990503), -INT64_C( 1840627934241987319),
      -INT64_C( 5186611020917853902),  INT64_C( 3454106255215810982),  INT64_C( 5482433546627391094), -INT64_C( 5186611020917853902),
      -INT64_C( 5186611020917853902),  INT64_C( 7374444206365441234), -INT64_C( 5186611020917853902), -INT64_C( 5186611020917853902),
      -INT64_C( 5186611020917853902), -INT64_C( 7616927068837255434), -INT64_C( 5186611020917853902), -INT64_C( 5186611020917853902),
      -INT64_C( 5186611020917853902), -INT64_C(  629453941382333314), -INT64_C( 8222254897408801825), -INT64_C( 5186611020917853902),
      -INT64_C( 7291679519018482511), -INT64_C( 2923246312670937731), -INT64_C( 5186611020917853902), -INT64_C( 5186611020917853902),
      -INT64_C( 5822378945194790533), -INT64_C( 5186611020917853902), -INT64_C( 5186611020917853902), -INT64_C( 5186611020917853902),
      -INT64_C(  509043122025449458), -INT64_C( 5186611020917853902) };

  static int64_t r[sizeof(e) / sizeof(e[0])];
  static const int32_t len = HEDLEY_STATIC_CAST(int32_t, sizeof(e) / sizeof(e[0]));
  int32_t i = 0;
  simde_svbool_t pg = simde_svwhilelt_b64_s32(i, len);
  while (simde_svptest_first(simde_svptrue_b64(), pg)) {
    simde_svint64_t
      rv,
      av = simde_svld1_s64(pg, &(a[i]));
    simde_svbool_t pv;

    pv = simde_svcmplt_s64(pg, simde_svld1_s64(pg, &(p[i])), simde_svdup_n_s64(INT64_C(0)));
    rv = simde_svdup_n_s64_m(av, pv, b);

    simde_svst1_s64(pg, &(r[i]), rv);

    i += simde_svcntd();
    pg = simde_svwhilelt_b64_s32(i, len);
  }

  simde_assert_equal_vi64(len, e, r);

  return 0;
#else
  int64_t p[1024 / sizeof(int64_t)], a[1024 / sizeof(int64_t)], b, e[1024 / sizeof(int64_t)];
  int32_t len = simde_test_arm_sve_random_length(sizeof(e), sizeof(e[0]));

  fputc('\n', stdout);

  simde_test_codegen_random_memory(sizeof(p), HEDLEY_REINTERPRET_CAST(uint8_t*, p));
  simde_test_codegen_random_memory(sizeof(a), HEDLEY_REINTERPRET_CAST(uint8_t*, a));
  b = simde_test_codegen_random_i64();

  int32_t i = 0;
  simde_svbool_t pg = simde_svwhilelt_b64_s32(i, len);
  while (simde_svptest_first(simde_svptrue_b64(), pg)) {
    simde_svint64_t av, ev;
    simde_svbool_t pv;

    pv = simde_svcmplt_s64(pg, simde_svld1_s64(pg, &(p[i])), simde_svdup_n_s64(0));
    av = simde_svld1_s64(pg, &(a[i]));

    ev = simde_svdup_n_s64_m(av, pv, b);

    simde_svst1_s64(pg, &(e[i]), ev);
    simde_svst1_s64(pg, &(p[i]), simde_svdup_n_s64_z(pv, ~INT64_C(0)));

    i += simde_svcntd();
    pg = simde_svwhilelt_b64_s32(i, len);
  }

  simde_test_codegen_write_1vi64(1, HEDLEY_STATIC_CAST(size_t, len), p);
  simde_test_codegen_write_1vi64(1, HEDLEY_STATIC_CAST(size_t, len), a);
  simde_test_codegen_write_1i64(1, b);
  simde_test_codegen_write_1vi64(1, HEDLEY_STATIC_CAST(size_t, len), e);

  return 1;
#endif
}

static int
test_simde_svdup_n_u8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const uint8_t a = UINT8_C(150);
  static const uint8_t e[] =
    { UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150),
      UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150),
      UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150),
      UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150),
      UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150),
      UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150),
      UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150),
      UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150),
      UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150),
      UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150),
      UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150),
      UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150),
      UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150),
      UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150),
      UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150),
      UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150),
      UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150),
      UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150),
      UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150),
      UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150),
      UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150),
      UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150),
      UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150),
      UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150),
      UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150),
      UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150),
      UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150),
      UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150),
      UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150),
      UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150),
      UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150),
      UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150),
      UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150),
      UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150),
      UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150),
      UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150),
      UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150),
      UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150),
      UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150),
      UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150),
      UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150),
      UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150),
      UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150),
      UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150),
      UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150),
      UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150),
      UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150),
      UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150),
      UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150),
      UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150),
      UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150),
      UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150),
      UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150),
      UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150),
      UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150),
      UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150),
      UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150),
      UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150),
      UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150),
      UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150),
      UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150),
      UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150),
      UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150),
      UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150),
      UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150),
      UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150),
      UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150),
      UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150),
      UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150),
      UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150),
      UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150),
      UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150),
      UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150),
      UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150),
      UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150),
      UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150),
      UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150), UINT8_C(150) };

  static uint8_t r[sizeof(e) / sizeof(e[0])];
  static const int32_t len = HEDLEY_STATIC_CAST(int32_t, sizeof(e) / sizeof(e[0]));
  int32_t i = 0;
  simde_svbool_t pg = simde_svwhilelt_b8_s32(i, len);
  while (simde_svptest_first(simde_svptrue_b8(), pg)) {
    simde_svuint8_t rv;

    rv = simde_svdup_n_u8(a);

    simde_svst1_u8(pg, &(r[i]), rv);

    i += simde_svcntb();
    pg = simde_svwhilelt_b8_s32(i, len);
  }

  simde_assert_equal_vu8(len, e, r);

  return 0;
#else
  uint8_t a, e[1024];
  int32_t len;

  fputc('\n', stdout);

  len = simde_test_codegen_random_u16() & ((sizeof(e) / sizeof(e[0])) - 1);
  a = simde_test_codegen_random_u8();

  int32_t i = 0;
  simde_svbool_t pg = simde_svwhilelt_b8_s32(i, len);
  while (simde_svptest_first(simde_svptrue_b8(), pg)) {
    simde_svuint8_t ev;

    ev = simde_svdup_n_u8(a);

    simde_svst1_u8(pg, &(e[i]), ev);

    i += simde_svcntb();
    pg = simde_svwhilelt_b8_s32(i, len);
  }

  simde_test_codegen_write_1u8(1, a);
  simde_test_codegen_write_1vu8(1, HEDLEY_STATIC_CAST(size_t, len), e);

  return 1;
#endif
}

static int
test_simde_svdup_n_u8_z (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const int8_t p[] =
    { -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
       INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
       INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
       INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
       INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
       INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0) };
  static const uint8_t a = UINT8_C(131);
  static const uint8_t e[] =
    { UINT8_C(131), UINT8_C(131), UINT8_C(  0), UINT8_C(131), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(131),
      UINT8_C(  0), UINT8_C(131), UINT8_C(  0), UINT8_C(  0), UINT8_C(131), UINT8_C(131), UINT8_C(  0), UINT8_C(131),
      UINT8_C(131), UINT8_C(131), UINT8_C(131), UINT8_C(131), UINT8_C(  0), UINT8_C(131), UINT8_C(131), UINT8_C(  0),
      UINT8_C(  0), UINT8_C(  0), UINT8_C(131), UINT8_C(131), UINT8_C(  0), UINT8_C(  0), UINT8_C(131), UINT8_C(  0),
      UINT8_C(  0), UINT8_C(131), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),
      UINT8_C(  0), UINT8_C(  0), UINT8_C(131), UINT8_C(  0), UINT8_C(131), UINT8_C(131), UINT8_C(  0), UINT8_C(131),
      UINT8_C(131), UINT8_C(131), UINT8_C(  0), UINT8_C(131), UINT8_C(  0), UINT8_C(131), UINT8_C(131), UINT8_C(131),
      UINT8_C(131), UINT8_C(131), UINT8_C(  0), UINT8_C(  0), UINT8_C(131), UINT8_C(131), UINT8_C(131), UINT8_C(  0),
      UINT8_C(131), UINT8_C(131), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(131),
      UINT8_C(  0), UINT8_C(  0), UINT8_C(131), UINT8_C(  0), UINT8_C(  0), UINT8_C(131), UINT8_C(131), UINT8_C(131),
      UINT8_C(131), UINT8_C(  0), UINT8_C(131), UINT8_C(131), UINT8_C(131), UINT8_C(131), UINT8_C(131), UINT8_C(131),
      UINT8_C(  0), UINT8_C(131), UINT8_C(  0), UINT8_C(131), UINT8_C(131), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),
      UINT8_C(131), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(131), UINT8_C(131), UINT8_C(131), UINT8_C(  0),
      UINT8_C(131), UINT8_C(131), UINT8_C(131), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(131), UINT8_C(131),
      UINT8_C(  0), UINT8_C(131), UINT8_C(131), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),
      UINT8_C(  0), UINT8_C(131), UINT8_C(  0), UINT8_C(131), UINT8_C(131), UINT8_C(  0), UINT8_C(131), UINT8_C(  0),
      UINT8_C(131), UINT8_C(  0), UINT8_C(131), UINT8_C(  0), UINT8_C(131), UINT8_C(  0), UINT8_C(131), UINT8_C(131),
      UINT8_C(  0), UINT8_C(  0), UINT8_C(131), UINT8_C(131), UINT8_C(131), UINT8_C(131), UINT8_C(131), UINT8_C(  0),
      UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(131), UINT8_C(131), UINT8_C(131), UINT8_C(  0),
      UINT8_C(  0), UINT8_C(131), UINT8_C(131), UINT8_C(131), UINT8_C(131), UINT8_C(131), UINT8_C(  0), UINT8_C(  0),
      UINT8_C(131), UINT8_C(  0), UINT8_C(131), UINT8_C(131), UINT8_C(131), UINT8_C(  0), UINT8_C(131), UINT8_C(131),
      UINT8_C(131), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(131), UINT8_C(  0), UINT8_C(131),
      UINT8_C(  0), UINT8_C(131), UINT8_C(  0), UINT8_C(131), UINT8_C(131), UINT8_C(131), UINT8_C(131), UINT8_C(131),
      UINT8_C(  0), UINT8_C(131), UINT8_C(131), UINT8_C(131), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),
      UINT8_C(  0), UINT8_C(131), UINT8_C(131), UINT8_C(131), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(131),
      UINT8_C(131), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(131), UINT8_C(  0),
      UINT8_C(  0), UINT8_C(131), UINT8_C(131), UINT8_C(131), UINT8_C(  0), UINT8_C(131), UINT8_C(131), UINT8_C(  0),
      UINT8_C(131), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(131), UINT8_C(131), UINT8_C(  0), UINT8_C(131),
      UINT8_C(131), UINT8_C(  0), UINT8_C(131), UINT8_C(131), UINT8_C(  0), UINT8_C(  0), UINT8_C(131), UINT8_C(  0),
      UINT8_C(131), UINT8_C(131), UINT8_C(  0), UINT8_C(131), UINT8_C(  0), UINT8_C(  0), UINT8_C(131), UINT8_C(  0),
      UINT8_C(131), UINT8_C(131), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(131), UINT8_C(131), UINT8_C(  0),
      UINT8_C(  0), UINT8_C(131), UINT8_C(  0), UINT8_C(131), UINT8_C(131), UINT8_C(  0), UINT8_C(131), UINT8_C(  0),
      UINT8_C(  0), UINT8_C(  0), UINT8_C(131), UINT8_C(131), UINT8_C(131), UINT8_C(131), UINT8_C(  0), UINT8_C(  0),
      UINT8_C(  0), UINT8_C(131), UINT8_C(131), UINT8_C(  0), UINT8_C(131), UINT8_C(131), UINT8_C(131), UINT8_C(131),
      UINT8_C(  0), UINT8_C(131), UINT8_C(131), UINT8_C(131), UINT8_C(  0), UINT8_C(131), UINT8_C(131), UINT8_C(  0),
      UINT8_C(131), UINT8_C(131), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(131), UINT8_C(  0), UINT8_C(131),
      UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(131), UINT8_C(131), UINT8_C(131), UINT8_C(  0), UINT8_C(131),
      UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(131), UINT8_C(  0), UINT8_C(131), UINT8_C(131),
      UINT8_C(131), UINT8_C(131), UINT8_C(131), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),
      UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(131), UINT8_C(  0),
      UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),
      UINT8_C(131), UINT8_C(131), UINT8_C(131), UINT8_C(  0), UINT8_C(131), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),
      UINT8_C(  0), UINT8_C(131), UINT8_C(  0), UINT8_C(131), UINT8_C(  0), UINT8_C(131), UINT8_C(131), UINT8_C(  0),
      UINT8_C(  0), UINT8_C(131), UINT8_C(131), UINT8_C(  0), UINT8_C(  0), UINT8_C(131), UINT8_C(131), UINT8_C(131),
      UINT8_C(  0), UINT8_C(131), UINT8_C(131), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(131), UINT8_C(  0),
      UINT8_C(131), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(131), UINT8_C(131), UINT8_C(131), UINT8_C(131),
      UINT8_C(131), UINT8_C(131), UINT8_C(131), UINT8_C(131), UINT8_C(131), UINT8_C(  0), UINT8_C(  0), UINT8_C(131),
      UINT8_C(  0), UINT8_C(131), UINT8_C(  0), UINT8_C(131), UINT8_C(131), UINT8_C(131), UINT8_C(  0), UINT8_C(131),
      UINT8_C(131), UINT8_C(  0), UINT8_C(  0), UINT8_C(131), UINT8_C(  0), UINT8_C(131), UINT8_C(131), UINT8_C(131),
      UINT8_C(  0), UINT8_C(  0), UINT8_C(131), UINT8_C(131), UINT8_C(  0), UINT8_C(  0), UINT8_C(131), UINT8_C(131),
      UINT8_C(  0), UINT8_C(  0), UINT8_C(131), UINT8_C(131), UINT8_C(131), UINT8_C(131), UINT8_C(131), UINT8_C(  0),
      UINT8_C(131), UINT8_C(131), UINT8_C(131), UINT8_C(131), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),
      UINT8_C(  0), UINT8_C(131), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(131), UINT8_C(  0), UINT8_C(  0),
      UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(131), UINT8_C(131), UINT8_C(131), UINT8_C(131), UINT8_C(131),
      UINT8_C(  0), UINT8_C(  0), UINT8_C(131), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0) };

  static uint8_t r[sizeof(e) / sizeof(e[0])];
  static const int32_t len = HEDLEY_STATIC_CAST(int32_t, sizeof(e) / sizeof(e[0]));
  int32_t i = 0;
  simde_svbool_t pg = simde_svwhilelt_b8_s32(i, len);
  while (simde_svptest_first(simde_svptrue_b8(), pg)) {
    simde_svuint8_t rv;
    simde_svbool_t pv;

    pv = simde_svcmplt_s8(pg, simde_svld1_s8(pg, &(p[i])), simde_svdup_n_s8(0));
    rv = simde_svdup_n_u8_z(pv, a);

    simde_svst1_u8(pg, &(r[i]), rv);

    i += simde_svcntb();
    pg = simde_svwhilelt_b8_s32(i, len);
  }

  simde_assert_equal_vu8(len, e, r);

  return 0;
#else
  int8_t p[1024];
  uint8_t a, e[1024];
  int32_t len;

  fputc('\n', stdout);

  len = simde_test_codegen_random_u16() & ((sizeof(e) / sizeof(e[0])) - 1);
  simde_test_codegen_random_memory(sizeof(p), HEDLEY_REINTERPRET_CAST(uint8_t*, p));
  a = simde_test_codegen_random_u8();

  int32_t i = 0;
  simde_svbool_t pg = simde_svwhilelt_b8_s32(i, len);
  while (simde_svptest_first(simde_svptrue_b8(), pg)) {
    simde_svuint8_t ev;
    simde_svbool_t pv;

    pv = simde_svcmplt_s8(pg, simde_svld1_s8(pg, &(p[i])), simde_svdup_n_s8(0));
    ev = simde_svdup_n_u8_z(pv, a);

    simde_svst1_u8(pg, &(e[i]), ev);
    simde_svst1_s8(pg, &(p[i]), simde_svdup_n_s8_z(pv, ~INT8_C(0)));

    i += simde_svcntb();
    pg = simde_svwhilelt_b8_s32(i, len);
  }

  simde_test_codegen_write_1vi8(1, HEDLEY_STATIC_CAST(size_t, len), p);
  simde_test_codegen_write_1u8(1, a);
  simde_test_codegen_write_1vu8(1, HEDLEY_STATIC_CAST(size_t, len), e);

  return 1;
#endif
}

static int
test_simde_svdup_n_u8_m (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const int8_t p[] =
    { -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
       INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
       INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
       INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
       INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
       INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
       INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
       INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
       INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),
      -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),
       INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),
      -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
      -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1) };
  static const uint8_t a[] =
    { UINT8_C( 72), UINT8_C( 10), UINT8_C( 20), UINT8_C(158), UINT8_C(222), UINT8_C( 10), UINT8_C(182), UINT8_C( 63),
      UINT8_C( 86), UINT8_C( 21), UINT8_C(229), UINT8_C(253), UINT8_C( 28), UINT8_C( 69), UINT8_C( 77), UINT8_C( 55),
      UINT8_C(148), UINT8_C(105), UINT8_C(167), UINT8_C(180), UINT8_C( 41), UINT8_C(185), UINT8_C( 95), UINT8_C( 27),
      UINT8_C(238), UINT8_C(158), UINT8_C(232), UINT8_C(194), UINT8_C(250), UINT8_C(101), UINT8_C(103), UINT8_C( 67),
      UINT8_C(111), UINT8_C(123), UINT8_C(225), UINT8_C( 77), UINT8_C(133), UINT8_C(152), UINT8_C(141), UINT8_C(220),
      UINT8_C(173), UINT8_C(114), UINT8_C(217), UINT8_C(201), UINT8_C(183), UINT8_C( 38), UINT8_C(  0), UINT8_C( 75),
      UINT8_C(143), UINT8_C(167),    UINT8_MAX, UINT8_C(184), UINT8_C( 97), UINT8_C( 95), UINT8_C(212), UINT8_C( 79),
      UINT8_C(253), UINT8_C(188), UINT8_C( 17), UINT8_C(248), UINT8_C( 33), UINT8_C(121), UINT8_C( 59), UINT8_C(145),
      UINT8_C(244), UINT8_C( 28), UINT8_C(222), UINT8_C(122), UINT8_C(180), UINT8_C(107), UINT8_C( 86), UINT8_C( 97),
      UINT8_C(221), UINT8_C( 47), UINT8_C( 42), UINT8_C(148), UINT8_C( 85), UINT8_C( 42), UINT8_C(224), UINT8_C(228),
      UINT8_C(210), UINT8_C(223), UINT8_C(156), UINT8_C( 51), UINT8_C( 62), UINT8_C(112), UINT8_C(130), UINT8_C( 60),
      UINT8_C( 44), UINT8_C(147), UINT8_C( 52), UINT8_C( 78), UINT8_C( 12), UINT8_C(111), UINT8_C(223), UINT8_C(  1),
      UINT8_C(139), UINT8_C(189), UINT8_C(123), UINT8_C( 64), UINT8_C( 41), UINT8_C(209), UINT8_C(161), UINT8_C(  6),
      UINT8_C(  0), UINT8_C(204), UINT8_C(155), UINT8_C( 85), UINT8_C(246), UINT8_C(123), UINT8_C( 57), UINT8_C(200),
      UINT8_C( 90), UINT8_C(213), UINT8_C(251), UINT8_C(153), UINT8_C( 70), UINT8_C(125), UINT8_C(213), UINT8_C(114),
      UINT8_C( 17), UINT8_C(  9), UINT8_C(192), UINT8_C( 29), UINT8_C(120), UINT8_C(159), UINT8_C( 30), UINT8_C(  3),
      UINT8_C( 93), UINT8_C(153), UINT8_C( 67), UINT8_C(134), UINT8_C(106), UINT8_C(229), UINT8_C(140), UINT8_C(106),
      UINT8_C(177), UINT8_C( 39), UINT8_C(191), UINT8_C(167), UINT8_C(162), UINT8_C(248), UINT8_C(112), UINT8_C(253),
      UINT8_C(206), UINT8_C(107), UINT8_C(150), UINT8_C( 20), UINT8_C(233), UINT8_C(107), UINT8_C(134), UINT8_C(250),
      UINT8_C(116), UINT8_C( 71), UINT8_C( 23), UINT8_C(236), UINT8_C(230), UINT8_C( 54), UINT8_C(239), UINT8_C( 67),
      UINT8_C(207), UINT8_C( 51), UINT8_C(201), UINT8_C( 58), UINT8_C( 24), UINT8_C( 86), UINT8_C(164), UINT8_C(201),
      UINT8_C(125), UINT8_C(100), UINT8_C(112), UINT8_C( 32), UINT8_C( 92), UINT8_C(224), UINT8_C( 29), UINT8_C( 42),
      UINT8_C( 76), UINT8_C(179), UINT8_C( 62), UINT8_C( 53), UINT8_C( 30), UINT8_C(197), UINT8_C( 47), UINT8_C(146),
      UINT8_C( 12), UINT8_C( 70), UINT8_C(126), UINT8_C(242), UINT8_C(124), UINT8_C(109), UINT8_C( 54), UINT8_C( 76),
      UINT8_C(160),    UINT8_MAX, UINT8_C(134), UINT8_C(184), UINT8_C( 85), UINT8_C( 42), UINT8_C(129), UINT8_C(211),
      UINT8_C(142), UINT8_C(242), UINT8_C(243), UINT8_C(235), UINT8_C(210), UINT8_C( 16), UINT8_C( 21), UINT8_C( 30),
      UINT8_C(195), UINT8_C( 84), UINT8_C( 83), UINT8_C(225), UINT8_C( 25), UINT8_C(130), UINT8_C(115), UINT8_C( 37),
      UINT8_C(201), UINT8_C(241), UINT8_C( 23), UINT8_C( 69), UINT8_C( 94), UINT8_C( 77), UINT8_C(145),    UINT8_MAX,
      UINT8_C( 77), UINT8_C( 23), UINT8_C(183), UINT8_C(162), UINT8_C( 66), UINT8_C( 57), UINT8_C(117), UINT8_C(208),
      UINT8_C( 43), UINT8_C(104), UINT8_C(187), UINT8_C(253), UINT8_C(120), UINT8_C(209), UINT8_C( 28), UINT8_C( 59),
      UINT8_C( 37), UINT8_C(111), UINT8_C( 28), UINT8_C( 62), UINT8_C(242), UINT8_C(143), UINT8_C( 99), UINT8_C(187),
      UINT8_C(128), UINT8_C(122), UINT8_C(  0), UINT8_C(223), UINT8_C(200), UINT8_C(146), UINT8_C(222), UINT8_C( 21),
      UINT8_C(169), UINT8_C(149), UINT8_C(183), UINT8_C(235), UINT8_C(206), UINT8_C( 45), UINT8_C(188), UINT8_C(249),
      UINT8_C(149), UINT8_C(119), UINT8_C(247), UINT8_C( 14), UINT8_C( 72), UINT8_C( 19), UINT8_C( 73), UINT8_C(109),
      UINT8_C(130), UINT8_C(102), UINT8_C(171), UINT8_C(116), UINT8_C(245), UINT8_C( 14), UINT8_C( 47), UINT8_C(118),
      UINT8_C(137), UINT8_C( 48), UINT8_C( 85), UINT8_C( 81), UINT8_C(194), UINT8_C( 51), UINT8_C(102), UINT8_C(107),
      UINT8_C(200), UINT8_C( 29), UINT8_C( 87), UINT8_C(151), UINT8_C( 74), UINT8_C( 19), UINT8_C(144), UINT8_C(224),
      UINT8_C(138), UINT8_C(135), UINT8_C(238), UINT8_C(211), UINT8_C(154), UINT8_C( 55), UINT8_C( 64), UINT8_C( 29),
      UINT8_C(157), UINT8_C(236), UINT8_C(145), UINT8_C(147), UINT8_C(250), UINT8_C(193), UINT8_C(  9), UINT8_C(131),
      UINT8_C(241), UINT8_C( 94), UINT8_C(212), UINT8_C(179), UINT8_C(145), UINT8_C( 58), UINT8_C( 30), UINT8_C( 89),
      UINT8_C( 88), UINT8_C(117), UINT8_C(240), UINT8_C(162), UINT8_C(136), UINT8_C(129), UINT8_C(130), UINT8_C( 19),
      UINT8_C(  8), UINT8_C(112), UINT8_C(230), UINT8_C(163), UINT8_C(168), UINT8_C( 38), UINT8_C(192), UINT8_C( 69),
      UINT8_C( 18), UINT8_C( 81), UINT8_C(216), UINT8_C( 13), UINT8_C( 18), UINT8_C(225), UINT8_C(144), UINT8_C(  3),
      UINT8_C( 63), UINT8_C(101), UINT8_C(182), UINT8_C(208), UINT8_C(159), UINT8_C(213), UINT8_C( 42), UINT8_C(247),
      UINT8_C( 74), UINT8_C( 26), UINT8_C(154), UINT8_C(211), UINT8_C(155), UINT8_C( 28), UINT8_C(230), UINT8_C(164),
      UINT8_C(141), UINT8_C(204), UINT8_C( 71), UINT8_C( 53), UINT8_C(242), UINT8_C(  7), UINT8_C(122), UINT8_C(  5),
      UINT8_C( 88), UINT8_C( 83), UINT8_C( 18), UINT8_C(107), UINT8_C( 52), UINT8_C(162), UINT8_C(110), UINT8_C(116),
      UINT8_C(  7), UINT8_C( 37), UINT8_C( 68), UINT8_C(167), UINT8_C(250), UINT8_C(110), UINT8_C(158), UINT8_C( 68),
      UINT8_C(137), UINT8_C( 56), UINT8_C( 23), UINT8_C( 36), UINT8_C( 85), UINT8_C(253), UINT8_C(200), UINT8_C(226),
      UINT8_C(201), UINT8_C( 15), UINT8_C( 23), UINT8_C(188), UINT8_C( 22), UINT8_C(145), UINT8_C(193), UINT8_C(111),
      UINT8_C(228), UINT8_C(211), UINT8_C(218), UINT8_C( 25), UINT8_C(117), UINT8_C( 72), UINT8_C(141), UINT8_C(125),
      UINT8_C(109), UINT8_C(209), UINT8_C( 36), UINT8_C(103), UINT8_C( 64), UINT8_C(194), UINT8_C(172), UINT8_C(201),
      UINT8_C(251), UINT8_C(195), UINT8_C(237), UINT8_C( 80), UINT8_C(193), UINT8_C(182), UINT8_C( 50), UINT8_C(138),
      UINT8_C(197), UINT8_C( 73), UINT8_C( 70), UINT8_C(220), UINT8_C(218), UINT8_C(  7), UINT8_C( 75), UINT8_C(191),
      UINT8_C(218), UINT8_C( 37), UINT8_C(216), UINT8_C( 80), UINT8_C(109), UINT8_C(101), UINT8_C(205), UINT8_C(219),
      UINT8_C( 54), UINT8_C(241), UINT8_C( 66), UINT8_C(118), UINT8_C(179), UINT8_C(238), UINT8_C( 63), UINT8_C(174),
      UINT8_C(178), UINT8_C( 45), UINT8_C(254), UINT8_C(115), UINT8_C(227), UINT8_C( 48), UINT8_C(253), UINT8_C(168),
      UINT8_C(121), UINT8_C( 68), UINT8_C(132), UINT8_C( 84), UINT8_C( 75), UINT8_C(207), UINT8_C( 19), UINT8_C( 38),
      UINT8_C(244), UINT8_C(235), UINT8_C(118), UINT8_C( 98), UINT8_C( 80), UINT8_C( 67), UINT8_C( 61), UINT8_C(134),
      UINT8_C( 52), UINT8_C(127), UINT8_C(253), UINT8_C(231), UINT8_C(110), UINT8_C( 60), UINT8_C(150), UINT8_C( 32),
      UINT8_C(105), UINT8_C(148), UINT8_C(147), UINT8_C( 76), UINT8_C(197), UINT8_C(144), UINT8_C(245), UINT8_C( 62),
      UINT8_C(212), UINT8_C(121), UINT8_C(146), UINT8_C( 32), UINT8_C( 73), UINT8_C(165), UINT8_C( 70), UINT8_C( 61),
      UINT8_C(144), UINT8_C(188), UINT8_C(159), UINT8_C(224),    UINT8_MAX, UINT8_C(220), UINT8_C(103), UINT8_C( 51),
      UINT8_C( 92), UINT8_C(100), UINT8_C( 26), UINT8_C(202), UINT8_C(160), UINT8_C(176), UINT8_C(234), UINT8_C( 10),
      UINT8_C( 69), UINT8_C(125), UINT8_C( 86), UINT8_C( 10), UINT8_C( 13), UINT8_C( 75), UINT8_C( 72), UINT8_C(226),
      UINT8_C(197), UINT8_C(219), UINT8_C(  2), UINT8_C( 14), UINT8_C(128), UINT8_C( 72), UINT8_C( 75), UINT8_C( 17),
      UINT8_C(  4), UINT8_C(235), UINT8_C(241), UINT8_C(  3), UINT8_C(199), UINT8_C( 88), UINT8_C( 54), UINT8_C( 35),
      UINT8_C(188), UINT8_C( 80), UINT8_C(237), UINT8_C( 93), UINT8_C(  1), UINT8_C(215), UINT8_C(103), UINT8_C( 70),
      UINT8_C( 84), UINT8_C(189), UINT8_C( 80), UINT8_C( 98), UINT8_C(  9), UINT8_C(152), UINT8_C( 68), UINT8_C(206),
      UINT8_C(115), UINT8_C( 70), UINT8_C(220), UINT8_C(244), UINT8_C(142), UINT8_C( 39), UINT8_C(  5), UINT8_C(146),
      UINT8_C( 18), UINT8_C(246), UINT8_C(149), UINT8_C(218), UINT8_C( 79), UINT8_C(203), UINT8_C(253), UINT8_C( 11),
      UINT8_C( 27), UINT8_C(235), UINT8_C(104), UINT8_C( 28), UINT8_C(194), UINT8_C(207), UINT8_C( 98), UINT8_C( 23),
      UINT8_C(141), UINT8_C(178), UINT8_C(121), UINT8_C(150), UINT8_C( 75), UINT8_C(189), UINT8_C(100), UINT8_C(190),
      UINT8_C(  3), UINT8_C( 64), UINT8_C(178), UINT8_C(145), UINT8_C(103), UINT8_C(183), UINT8_C( 35), UINT8_C(122),
      UINT8_C(174), UINT8_C(184), UINT8_C( 84), UINT8_C(253), UINT8_C(131), UINT8_C( 81), UINT8_C(  8), UINT8_C(158),
      UINT8_C( 60), UINT8_C(113), UINT8_C(187),    UINT8_MAX, UINT8_C( 64), UINT8_C( 29), UINT8_C( 22), UINT8_C(205),
      UINT8_C(208), UINT8_C(143), UINT8_C( 99), UINT8_C( 27), UINT8_C( 76), UINT8_C(199), UINT8_C(217), UINT8_C( 79),
      UINT8_C(  7), UINT8_C(140), UINT8_C(224), UINT8_C(111), UINT8_C( 67), UINT8_C(  3), UINT8_C(233), UINT8_C(241),
      UINT8_C(187), UINT8_C( 61), UINT8_C(238), UINT8_C( 62), UINT8_C(142), UINT8_C(247), UINT8_C(220), UINT8_C(203),
      UINT8_C(104), UINT8_C(151), UINT8_C(202), UINT8_C(168), UINT8_C(181), UINT8_C(224), UINT8_C(118), UINT8_C(133),
      UINT8_C(111), UINT8_C(217), UINT8_C(160), UINT8_C(187), UINT8_C(161), UINT8_C(121), UINT8_C( 10), UINT8_C(168),
      UINT8_C(  5), UINT8_C(234), UINT8_C( 23), UINT8_C( 73), UINT8_C(237), UINT8_C(  0), UINT8_C( 58), UINT8_C(168),
      UINT8_C( 61), UINT8_C( 41), UINT8_C(230), UINT8_C(204), UINT8_C( 32), UINT8_C(194), UINT8_C(151), UINT8_C(136),
      UINT8_C( 90), UINT8_C( 97), UINT8_C( 48), UINT8_C( 15), UINT8_C( 65), UINT8_C(166), UINT8_C(148), UINT8_C(176),
      UINT8_C(128), UINT8_C( 52), UINT8_C(107), UINT8_C( 33), UINT8_C(173), UINT8_C(117), UINT8_C(201), UINT8_C(179),
      UINT8_C( 95), UINT8_C(225), UINT8_C(252), UINT8_C( 76), UINT8_C(225), UINT8_C( 54), UINT8_C(244), UINT8_C( 31),
      UINT8_C( 95), UINT8_C(218), UINT8_C(235), UINT8_C(127), UINT8_C(156), UINT8_C(130), UINT8_C(  7), UINT8_C(246),
      UINT8_C(227), UINT8_C( 56), UINT8_C(  5), UINT8_C( 36), UINT8_C(222), UINT8_C(153), UINT8_C(212), UINT8_C( 94),
      UINT8_C(205), UINT8_C( 63), UINT8_C(127), UINT8_C(123), UINT8_C(180), UINT8_C( 73), UINT8_C( 46), UINT8_C( 19),
      UINT8_C( 42), UINT8_C( 42), UINT8_C( 95), UINT8_C( 11), UINT8_C( 96), UINT8_C( 83), UINT8_C( 42), UINT8_C(192),
      UINT8_C( 45), UINT8_C( 21), UINT8_C( 63), UINT8_C(201), UINT8_C(151), UINT8_C( 71), UINT8_C(192), UINT8_C(122),
      UINT8_C(127), UINT8_C(197), UINT8_C(158), UINT8_C( 93), UINT8_C( 95), UINT8_C(114), UINT8_C(188), UINT8_C( 44),
      UINT8_C(177), UINT8_C( 59), UINT8_C(167), UINT8_C(101), UINT8_C(132), UINT8_C(213), UINT8_C(120), UINT8_C(174),
         UINT8_MAX, UINT8_C(215), UINT8_C(186), UINT8_C( 96), UINT8_C( 42), UINT8_C(228), UINT8_C( 32), UINT8_C( 87),
      UINT8_C(250), UINT8_C( 95), UINT8_C( 33), UINT8_C(145), UINT8_C(166), UINT8_C(225), UINT8_C( 12), UINT8_C( 37),
      UINT8_C(166), UINT8_C(170), UINT8_C(131), UINT8_C(  5), UINT8_C( 29), UINT8_C( 63), UINT8_C( 50), UINT8_C(206),
      UINT8_C(122), UINT8_C(217), UINT8_C( 52),    UINT8_MAX, UINT8_C(175), UINT8_C(172), UINT8_C(173), UINT8_C(174),
      UINT8_C(132), UINT8_C(103), UINT8_C( 14), UINT8_C(174), UINT8_C( 76), UINT8_C( 46), UINT8_C(  6), UINT8_C( 70),
      UINT8_C(142), UINT8_C( 39), UINT8_C(215), UINT8_C( 52), UINT8_C(  8), UINT8_C(227), UINT8_C( 90), UINT8_C(174),
      UINT8_C(142), UINT8_C(221), UINT8_C(180), UINT8_C(171), UINT8_C( 28), UINT8_C(230), UINT8_C(121), UINT8_C(150),
      UINT8_C(191), UINT8_C(173), UINT8_C(149), UINT8_C(110), UINT8_C( 90), UINT8_C( 67), UINT8_C( 29), UINT8_C(222),
      UINT8_C(170), UINT8_C( 43), UINT8_C(140), UINT8_C(246), UINT8_C( 90), UINT8_C(146), UINT8_C( 60), UINT8_C(232),
      UINT8_C(185), UINT8_C( 20), UINT8_C( 28), UINT8_C(193), UINT8_C(247), UINT8_C(118), UINT8_C(112), UINT8_C(133),
      UINT8_C( 83), UINT8_C( 36), UINT8_C( 48), UINT8_C(111), UINT8_C( 10), UINT8_C(170), UINT8_C(  6), UINT8_C(201),
      UINT8_C( 87), UINT8_C(155), UINT8_C( 56), UINT8_C(177), UINT8_C(222), UINT8_C( 85), UINT8_C(143), UINT8_C(137),
      UINT8_C(128), UINT8_C( 28), UINT8_C(127), UINT8_C(218), UINT8_C(174), UINT8_C(188), UINT8_C(194), UINT8_C(104),
      UINT8_C(208), UINT8_C(223), UINT8_C( 41), UINT8_C(199), UINT8_C( 85), UINT8_C(153), UINT8_C( 77), UINT8_C(169),
      UINT8_C(189), UINT8_C(125), UINT8_C( 24), UINT8_C(199), UINT8_C( 39), UINT8_C( 30), UINT8_C(145), UINT8_C(127),
      UINT8_C(186), UINT8_C(201), UINT8_C( 48), UINT8_C(152), UINT8_C( 30), UINT8_C(192), UINT8_C( 33), UINT8_C(158),
      UINT8_C(220), UINT8_C(161), UINT8_C(121), UINT8_C(138), UINT8_C( 93), UINT8_C( 59), UINT8_C(242), UINT8_C( 45),
      UINT8_C( 26), UINT8_C( 28), UINT8_C(244), UINT8_C(112), UINT8_C(181), UINT8_C( 65), UINT8_C( 25), UINT8_C(115),
      UINT8_C(191), UINT8_C( 49), UINT8_C( 58), UINT8_C(230), UINT8_C( 80), UINT8_C(203), UINT8_C(101), UINT8_C( 10),
      UINT8_C(148), UINT8_C(150), UINT8_C(162), UINT8_C(178) };
  static const uint8_t b = UINT8_C(106);
  static const uint8_t e[] =
    { UINT8_C(106), UINT8_C( 10), UINT8_C(106), UINT8_C(158), UINT8_C(106), UINT8_C( 10), UINT8_C(182), UINT8_C(106),
      UINT8_C( 86), UINT8_C( 21), UINT8_C(229), UINT8_C(253), UINT8_C( 28), UINT8_C(106), UINT8_C( 77), UINT8_C( 55),
      UINT8_C(148), UINT8_C(106), UINT8_C(106), UINT8_C(180), UINT8_C( 41), UINT8_C(106), UINT8_C(106), UINT8_C( 27),
      UINT8_C(106), UINT8_C(106), UINT8_C(106), UINT8_C(194), UINT8_C(106), UINT8_C(101), UINT8_C(106), UINT8_C(106),
      UINT8_C(106), UINT8_C(123), UINT8_C(225), UINT8_C( 77), UINT8_C(106), UINT8_C(152), UINT8_C(141), UINT8_C(106),
      UINT8_C(173), UINT8_C(114), UINT8_C(217), UINT8_C(106), UINT8_C(106), UINT8_C( 38), UINT8_C(106), UINT8_C( 75),
      UINT8_C(143), UINT8_C(167),    UINT8_MAX, UINT8_C(184), UINT8_C(106), UINT8_C( 95), UINT8_C(212), UINT8_C(106),
      UINT8_C(106), UINT8_C(188), UINT8_C(106), UINT8_C(106), UINT8_C(106), UINT8_C(121), UINT8_C( 59), UINT8_C(145),
      UINT8_C(106), UINT8_C(106), UINT8_C(222), UINT8_C(122), UINT8_C(106), UINT8_C(106), UINT8_C( 86), UINT8_C( 97),
      UINT8_C(106), UINT8_C(106), UINT8_C(106), UINT8_C(148), UINT8_C( 85), UINT8_C( 42), UINT8_C(106), UINT8_C(228),
      UINT8_C(106), UINT8_C(106), UINT8_C(156), UINT8_C(106), UINT8_C(106), UINT8_C(106), UINT8_C(130), UINT8_C(106),
      UINT8_C(106), UINT8_C(106), UINT8_C(106), UINT8_C(106), UINT8_C( 12), UINT8_C(111), UINT8_C(106), UINT8_C(  1),
      UINT8_C(106), UINT8_C(189), UINT8_C(106), UINT8_C(106), UINT8_C(106), UINT8_C(106), UINT8_C(106), UINT8_C(  6),
      UINT8_C(106), UINT8_C(106), UINT8_C(106), UINT8_C(106), UINT8_C(246), UINT8_C(123), UINT8_C(106), UINT8_C(106),
      UINT8_C( 90), UINT8_C(106), UINT8_C(251), UINT8_C(153), UINT8_C(106), UINT8_C(106), UINT8_C(213), UINT8_C(106),
      UINT8_C(106), UINT8_C(106), UINT8_C(192), UINT8_C(106), UINT8_C(120), UINT8_C(106), UINT8_C( 30), UINT8_C(106),
      UINT8_C(106), UINT8_C(106), UINT8_C( 67), UINT8_C(134), UINT8_C(106), UINT8_C(229), UINT8_C(106), UINT8_C(106),
      UINT8_C(106), UINT8_C( 39), UINT8_C(106), UINT8_C(106), UINT8_C(162), UINT8_C(106), UINT8_C(106), UINT8_C(106),
      UINT8_C(106), UINT8_C(107), UINT8_C(106), UINT8_C( 20), UINT8_C(106), UINT8_C(106), UINT8_C(106), UINT8_C(106),
      UINT8_C(116), UINT8_C(106), UINT8_C( 23), UINT8_C(236), UINT8_C(230), UINT8_C(106), UINT8_C(239), UINT8_C( 67),
      UINT8_C(207), UINT8_C(106), UINT8_C(201), UINT8_C( 58), UINT8_C(106), UINT8_C( 86), UINT8_C(164), UINT8_C(106),
      UINT8_C(125), UINT8_C(100), UINT8_C(106), UINT8_C(106), UINT8_C(106), UINT8_C(224), UINT8_C( 29), UINT8_C( 42),
      UINT8_C(106), UINT8_C(106), UINT8_C(106), UINT8_C(106), UINT8_C(106), UINT8_C(197), UINT8_C( 47), UINT8_C(106),
      UINT8_C(106), UINT8_C( 70), UINT8_C(126), UINT8_C(242), UINT8_C(124), UINT8_C(106), UINT8_C( 54), UINT8_C( 76),
      UINT8_C(160), UINT8_C(106), UINT8_C(134), UINT8_C(184), UINT8_C(106), UINT8_C(106), UINT8_C(129), UINT8_C(106),
      UINT8_C(142), UINT8_C(106), UINT8_C(106), UINT8_C(235), UINT8_C(210), UINT8_C(106), UINT8_C( 21), UINT8_C(106),
      UINT8_C(106), UINT8_C(106), UINT8_C( 83), UINT8_C(225), UINT8_C( 25), UINT8_C(130), UINT8_C(115), UINT8_C( 37),
      UINT8_C(106), UINT8_C(106), UINT8_C( 23), UINT8_C(106), UINT8_C( 94), UINT8_C(106), UINT8_C(145), UINT8_C(106),
      UINT8_C( 77), UINT8_C(106), UINT8_C(183), UINT8_C(162), UINT8_C(106), UINT8_C( 57), UINT8_C(117), UINT8_C(106),
      UINT8_C( 43), UINT8_C(106), UINT8_C(106), UINT8_C(253), UINT8_C(106), UINT8_C(209), UINT8_C( 28), UINT8_C( 59),
      UINT8_C( 37), UINT8_C(111), UINT8_C(106), UINT8_C( 62), UINT8_C(106), UINT8_C(106), UINT8_C( 99), UINT8_C(187),
      UINT8_C(128), UINT8_C(106), UINT8_C(  0), UINT8_C(106), UINT8_C(200), UINT8_C(106), UINT8_C(106), UINT8_C(106),
      UINT8_C(169), UINT8_C(149), UINT8_C(106), UINT8_C(106), UINT8_C(106), UINT8_C( 45), UINT8_C(106), UINT8_C(106),
      UINT8_C(106), UINT8_C(119), UINT8_C(247), UINT8_C( 14), UINT8_C( 72), UINT8_C( 19), UINT8_C(106), UINT8_C(109),
      UINT8_C(106), UINT8_C(106), UINT8_C(106), UINT8_C(116), UINT8_C(245), UINT8_C(106), UINT8_C(106), UINT8_C(106),
      UINT8_C(106), UINT8_C( 48), UINT8_C(106), UINT8_C(106), UINT8_C(106), UINT8_C(106), UINT8_C(106), UINT8_C(107),
      UINT8_C(106), UINT8_C(106), UINT8_C(106), UINT8_C(151), UINT8_C(106), UINT8_C( 19), UINT8_C(144), UINT8_C(224),
      UINT8_C(106), UINT8_C(135), UINT8_C(106), UINT8_C(106), UINT8_C(106), UINT8_C(106), UINT8_C( 64), UINT8_C(106),
      UINT8_C(157), UINT8_C(236), UINT8_C(145), UINT8_C(106), UINT8_C(250), UINT8_C(106), UINT8_C(106), UINT8_C(106),
      UINT8_C(241), UINT8_C( 94), UINT8_C(106), UINT8_C(106), UINT8_C(106), UINT8_C( 58), UINT8_C(106), UINT8_C(106),
      UINT8_C(106), UINT8_C(106), UINT8_C(106), UINT8_C(162), UINT8_C(136), UINT8_C(106), UINT8_C(106), UINT8_C(106),
      UINT8_C(  8), UINT8_C(106), UINT8_C(106), UINT8_C(163), UINT8_C(106), UINT8_C( 38), UINT8_C(106), UINT8_C(106),
      UINT8_C( 18), UINT8_C(106), UINT8_C(106), UINT8_C( 13), UINT8_C( 18), UINT8_C(225), UINT8_C(106), UINT8_C(106),
      UINT8_C(106), UINT8_C(101), UINT8_C(182), UINT8_C(208), UINT8_C(106), UINT8_C(213), UINT8_C( 42), UINT8_C(106),
      UINT8_C( 74), UINT8_C(106), UINT8_C(154), UINT8_C(211), UINT8_C(106), UINT8_C(106), UINT8_C(230), UINT8_C(164),
      UINT8_C(106), UINT8_C(106), UINT8_C( 71), UINT8_C( 53), UINT8_C(106), UINT8_C(106), UINT8_C(122), UINT8_C(  5),
      UINT8_C( 88), UINT8_C(106), UINT8_C( 18), UINT8_C(106), UINT8_C(106), UINT8_C(162), UINT8_C(110), UINT8_C(116),
      UINT8_C(106), UINT8_C(106), UINT8_C(106), UINT8_C(167), UINT8_C(250), UINT8_C(106), UINT8_C(106), UINT8_C( 68),
      UINT8_C(106), UINT8_C(106), UINT8_C( 23), UINT8_C(106), UINT8_C(106), UINT8_C(106), UINT8_C(106), UINT8_C(106),
      UINT8_C(201), UINT8_C( 15), UINT8_C(106), UINT8_C(188), UINT8_C(106), UINT8_C(106), UINT8_C(193), UINT8_C(106),
      UINT8_C(228), UINT8_C(106), UINT8_C(106), UINT8_C( 25), UINT8_C(106), UINT8_C(106), UINT8_C(141), UINT8_C(106),
      UINT8_C(106), UINT8_C(209), UINT8_C(106), UINT8_C(106), UINT8_C( 64), UINT8_C(106), UINT8_C(106), UINT8_C(201),
      UINT8_C(106), UINT8_C(195), UINT8_C(106), UINT8_C(106), UINT8_C(106), UINT8_C(106), UINT8_C( 50), UINT8_C(106),
      UINT8_C(106), UINT8_C(106), UINT8_C( 70), UINT8_C(220), UINT8_C(106), UINT8_C(106), UINT8_C( 75), UINT8_C(106),
      UINT8_C(218), UINT8_C(106), UINT8_C(106), UINT8_C( 80), UINT8_C(106), UINT8_C(101), UINT8_C(106), UINT8_C(219),
      UINT8_C(106), UINT8_C(106), UINT8_C(106), UINT8_C(106), UINT8_C(106), UINT8_C(106), UINT8_C(106), UINT8_C(174),
      UINT8_C(106), UINT8_C(106), UINT8_C(106), UINT8_C(115), UINT8_C(227), UINT8_C( 48), UINT8_C(253), UINT8_C(168),
      UINT8_C(106), UINT8_C(106), UINT8_C(106), UINT8_C( 84), UINT8_C( 75), UINT8_C(106), UINT8_C( 19), UINT8_C(106),
      UINT8_C(106), UINT8_C(235), UINT8_C(118), UINT8_C(106), UINT8_C(106), UINT8_C( 67), UINT8_C(106), UINT8_C(134),
      UINT8_C(106), UINT8_C(106), UINT8_C(253), UINT8_C(231), UINT8_C(110), UINT8_C( 60), UINT8_C(106), UINT8_C( 32),
      UINT8_C(106), UINT8_C(106), UINT8_C(106), UINT8_C( 76), UINT8_C(106), UINT8_C(144), UINT8_C(245), UINT8_C(106),
      UINT8_C(106), UINT8_C(106), UINT8_C(146), UINT8_C( 32), UINT8_C(106), UINT8_C(165), UINT8_C(106), UINT8_C( 61),
      UINT8_C(144), UINT8_C(188), UINT8_C(159), UINT8_C(224),    UINT8_MAX, UINT8_C(106), UINT8_C(103), UINT8_C(106),
      UINT8_C(106), UINT8_C(106), UINT8_C( 26), UINT8_C(202), UINT8_C(106), UINT8_C(176), UINT8_C(234), UINT8_C( 10),
      UINT8_C(106), UINT8_C(106), UINT8_C( 86), UINT8_C(106), UINT8_C(106), UINT8_C(106), UINT8_C( 72), UINT8_C(106),
      UINT8_C(197), UINT8_C(219), UINT8_C(106), UINT8_C(106), UINT8_C(106), UINT8_C(106), UINT8_C( 75), UINT8_C(106),
      UINT8_C(106), UINT8_C(235), UINT8_C(241), UINT8_C(106), UINT8_C(199), UINT8_C( 88), UINT8_C(106), UINT8_C( 35),
      UINT8_C(106), UINT8_C( 80), UINT8_C(237), UINT8_C(106), UINT8_C(  1), UINT8_C(106), UINT8_C(106), UINT8_C( 70),
      UINT8_C(106), UINT8_C(189), UINT8_C(106), UINT8_C(106), UINT8_C(  9), UINT8_C(152), UINT8_C( 68), UINT8_C(206),
      UINT8_C(115), UINT8_C( 70), UINT8_C(220), UINT8_C(106), UINT8_C(106), UINT8_C(106), UINT8_C(106), UINT8_C(146),
      UINT8_C( 18), UINT8_C(106), UINT8_C(149), UINT8_C(106), UINT8_C( 79), UINT8_C(106), UINT8_C(253), UINT8_C( 11),
      UINT8_C(106), UINT8_C(235), UINT8_C(106), UINT8_C( 28), UINT8_C(194), UINT8_C(106), UINT8_C( 98), UINT8_C( 23),
      UINT8_C(141), UINT8_C(178), UINT8_C(106), UINT8_C(150), UINT8_C( 75), UINT8_C(189), UINT8_C(106), UINT8_C(190),
      UINT8_C(106), UINT8_C( 64), UINT8_C(178), UINT8_C(145), UINT8_C(103), UINT8_C(183), UINT8_C(106), UINT8_C(106),
      UINT8_C(174), UINT8_C(106), UINT8_C( 84), UINT8_C(253), UINT8_C(106), UINT8_C( 81), UINT8_C(106), UINT8_C(106),
      UINT8_C(106), UINT8_C(106), UINT8_C(106),    UINT8_MAX, UINT8_C( 64), UINT8_C( 29), UINT8_C( 22), UINT8_C(106),
      UINT8_C(208), UINT8_C(143), UINT8_C(106), UINT8_C(106), UINT8_C(106), UINT8_C(106), UINT8_C(217), UINT8_C( 79),
      UINT8_C(106), UINT8_C(140), UINT8_C(106), UINT8_C(111), UINT8_C( 67), UINT8_C(106), UINT8_C(106), UINT8_C(106),
      UINT8_C(187), UINT8_C( 61), UINT8_C(106), UINT8_C( 62), UINT8_C(106), UINT8_C(106), UINT8_C(106), UINT8_C(203),
      UINT8_C(104), UINT8_C(106), UINT8_C(106), UINT8_C(106), UINT8_C(106), UINT8_C(224), UINT8_C(118), UINT8_C(133),
      UINT8_C(106), UINT8_C(106), UINT8_C(106), UINT8_C(187), UINT8_C(161), UINT8_C(106), UINT8_C(106), UINT8_C(168),
      UINT8_C(106), UINT8_C(106), UINT8_C( 23), UINT8_C( 73), UINT8_C(237), UINT8_C(  0), UINT8_C(106), UINT8_C(106),
      UINT8_C( 61), UINT8_C(106), UINT8_C(230), UINT8_C(106), UINT8_C( 32), UINT8_C(106), UINT8_C(151), UINT8_C(106),
      UINT8_C( 90), UINT8_C(106), UINT8_C( 48), UINT8_C(106), UINT8_C( 65), UINT8_C(166), UINT8_C(148), UINT8_C(106),
      UINT8_C(106), UINT8_C(106), UINT8_C(107), UINT8_C( 33), UINT8_C(173), UINT8_C(106), UINT8_C(106), UINT8_C(106),
      UINT8_C(106), UINT8_C(225), UINT8_C(252), UINT8_C( 76), UINT8_C(225), UINT8_C( 54), UINT8_C(106), UINT8_C(106),
      UINT8_C(106), UINT8_C(106), UINT8_C(235), UINT8_C(127), UINT8_C(106), UINT8_C(130), UINT8_C(106), UINT8_C(246),
      UINT8_C(227), UINT8_C(106), UINT8_C(  5), UINT8_C( 36), UINT8_C(222), UINT8_C(153), UINT8_C(212), UINT8_C( 94),
      UINT8_C(106), UINT8_C( 63), UINT8_C(127), UINT8_C(106), UINT8_C(106), UINT8_C( 73), UINT8_C(106), UINT8_C(106),
      UINT8_C( 42), UINT8_C( 42), UINT8_C(106), UINT8_C(106), UINT8_C( 96), UINT8_C( 83), UINT8_C( 42), UINT8_C(192),
      UINT8_C( 45), UINT8_C(106), UINT8_C(106), UINT8_C(201), UINT8_C(151), UINT8_C(106), UINT8_C(192), UINT8_C(122),
      UINT8_C(106), UINT8_C(197), UINT8_C(106), UINT8_C(106), UINT8_C( 95), UINT8_C(106), UINT8_C(106), UINT8_C(106),
      UINT8_C(106), UINT8_C(106), UINT8_C(167), UINT8_C(106), UINT8_C(132), UINT8_C(213), UINT8_C(120), UINT8_C(106),
         UINT8_MAX, UINT8_C(106), UINT8_C(106), UINT8_C(106), UINT8_C( 42), UINT8_C(106), UINT8_C(106), UINT8_C(106),
      UINT8_C(106), UINT8_C( 95), UINT8_C(106), UINT8_C(106), UINT8_C(106), UINT8_C(106), UINT8_C( 12), UINT8_C( 37),
      UINT8_C(106), UINT8_C(170), UINT8_C(131), UINT8_C(106), UINT8_C(106), UINT8_C(106), UINT8_C(106), UINT8_C(106),
      UINT8_C(106), UINT8_C(217), UINT8_C(106), UINT8_C(106), UINT8_C(175), UINT8_C(106), UINT8_C(173), UINT8_C(106),
      UINT8_C(106), UINT8_C(106), UINT8_C( 14), UINT8_C(106), UINT8_C(106), UINT8_C(106), UINT8_C(106), UINT8_C( 70),
      UINT8_C(142), UINT8_C( 39), UINT8_C(215), UINT8_C( 52), UINT8_C(  8), UINT8_C(227), UINT8_C(106), UINT8_C(106),
      UINT8_C(142), UINT8_C(106), UINT8_C(106), UINT8_C(171), UINT8_C( 28), UINT8_C(106), UINT8_C(121), UINT8_C(106),
      UINT8_C(106), UINT8_C(106), UINT8_C(106), UINT8_C(110), UINT8_C(106), UINT8_C(106), UINT8_C(106), UINT8_C(222),
      UINT8_C(106), UINT8_C(106), UINT8_C(140), UINT8_C(106), UINT8_C(106), UINT8_C(106), UINT8_C( 60), UINT8_C(106),
      UINT8_C(185), UINT8_C( 20), UINT8_C( 28), UINT8_C(193), UINT8_C(106), UINT8_C(106), UINT8_C(112), UINT8_C(106),
      UINT8_C(106), UINT8_C( 36), UINT8_C( 48), UINT8_C(106), UINT8_C(106), UINT8_C(170), UINT8_C(106), UINT8_C(106),
      UINT8_C(106), UINT8_C(155), UINT8_C(106), UINT8_C(106), UINT8_C(222), UINT8_C( 85), UINT8_C(106), UINT8_C(137),
      UINT8_C(128), UINT8_C( 28), UINT8_C(106), UINT8_C(106), UINT8_C(106), UINT8_C(106), UINT8_C(106), UINT8_C(104),
      UINT8_C(208), UINT8_C(106), UINT8_C( 41), UINT8_C(106), UINT8_C(106), UINT8_C(153), UINT8_C(106), UINT8_C(169),
      UINT8_C(106), UINT8_C(106), UINT8_C( 24), UINT8_C(199), UINT8_C( 39), UINT8_C( 30), UINT8_C(106), UINT8_C(127),
      UINT8_C(186), UINT8_C(106), UINT8_C(106), UINT8_C(106), UINT8_C(106), UINT8_C(106), UINT8_C(106), UINT8_C(158),
      UINT8_C(106), UINT8_C(106), UINT8_C(106), UINT8_C(138), UINT8_C( 93), UINT8_C( 59), UINT8_C(242), UINT8_C(106),
      UINT8_C( 26), UINT8_C(106), UINT8_C(244), UINT8_C(112), UINT8_C(181), UINT8_C(106), UINT8_C(106), UINT8_C(106),
      UINT8_C(106), UINT8_C(106), UINT8_C( 58), UINT8_C(230), UINT8_C(106), UINT8_C(203), UINT8_C(101), UINT8_C( 10),
      UINT8_C(106), UINT8_C(150), UINT8_C(162), UINT8_C(106) };

  static uint8_t r[sizeof(e) / sizeof(e[0])];
  static const int32_t len = HEDLEY_STATIC_CAST(int32_t, sizeof(e) / sizeof(e[0]));
  int32_t i = 0;
  simde_svbool_t pg = simde_svwhilelt_b8_s32(i, len);
  while (simde_svptest_first(simde_svptrue_b8(), pg)) {
    simde_svuint8_t
      rv,
      av = simde_svld1_u8(pg, &(a[i]));
    simde_svbool_t pv;

    pv = simde_svcmplt_s8(pg, simde_svld1_s8(pg, &(p[i])), simde_svdup_n_s8(INT8_C(0)));
    rv = simde_svdup_n_u8_m(av, pv, b);

    simde_svst1_u8(pg, &(r[i]), rv);

    i += simde_svcntb();
    pg = simde_svwhilelt_b8_s32(i, len);
  }

  simde_assert_equal_vu8(len, e, r);

  return 0;
#else
  int8_t p[1024 / sizeof(uint8_t)];
  uint8_t a[1024 / sizeof(uint8_t)], b, e[1024 / sizeof(uint8_t)];
  int32_t len = simde_test_arm_sve_random_length(sizeof(e), sizeof(e[0]));

  fputc('\n', stdout);

  simde_test_codegen_random_memory(sizeof(p), HEDLEY_REINTERPRET_CAST(uint8_t*, p));
  simde_test_codegen_random_memory(sizeof(a), HEDLEY_REINTERPRET_CAST(uint8_t*, a));
  b = simde_test_codegen_random_u8();

  int32_t i = 0;
  simde_svbool_t pg = simde_svwhilelt_b8_s32(i, len);
  while (simde_svptest_first(simde_svptrue_b8(), pg)) {
    simde_svuint8_t av, ev;
    simde_svbool_t pv;

    pv = simde_svcmplt_s8(pg, simde_svld1_s8(pg, &(p[i])), simde_svdup_n_s8(0));
    av = simde_svld1_u8(pg, &(a[i]));

    ev = simde_svdup_n_u8_m(av, pv, b);

    simde_svst1_u8(pg, &(e[i]), ev);
    simde_svst1_s8(pg, &(p[i]), simde_svdup_n_s8_z(pv, ~INT8_C(0)));

    i += simde_svcntb();
    pg = simde_svwhilelt_b8_s32(i, len);
  }

  simde_test_codegen_write_1vi8(1, HEDLEY_STATIC_CAST(size_t, len), p);
  simde_test_codegen_write_1vu8(1, HEDLEY_STATIC_CAST(size_t, len), a);
  simde_test_codegen_write_1u8(1, b);
  simde_test_codegen_write_1vu8(1, HEDLEY_STATIC_CAST(size_t, len), e);

  return 1;
#endif
}

static int
test_simde_svdup_n_u16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const uint16_t a = UINT16_C(63416);
  static const uint16_t e[] =
    { UINT16_C(63416), UINT16_C(63416), UINT16_C(63416), UINT16_C(63416), UINT16_C(63416), UINT16_C(63416), UINT16_C(63416), UINT16_C(63416),
      UINT16_C(63416), UINT16_C(63416), UINT16_C(63416), UINT16_C(63416), UINT16_C(63416), UINT16_C(63416), UINT16_C(63416), UINT16_C(63416),
      UINT16_C(63416), UINT16_C(63416), UINT16_C(63416), UINT16_C(63416), UINT16_C(63416), UINT16_C(63416), UINT16_C(63416), UINT16_C(63416),
      UINT16_C(63416), UINT16_C(63416), UINT16_C(63416), UINT16_C(63416), UINT16_C(63416), UINT16_C(63416), UINT16_C(63416), UINT16_C(63416),
      UINT16_C(63416), UINT16_C(63416), UINT16_C(63416), UINT16_C(63416), UINT16_C(63416), UINT16_C(63416), UINT16_C(63416), UINT16_C(63416),
      UINT16_C(63416), UINT16_C(63416), UINT16_C(63416), UINT16_C(63416), UINT16_C(63416), UINT16_C(63416), UINT16_C(63416), UINT16_C(63416),
      UINT16_C(63416), UINT16_C(63416), UINT16_C(63416), UINT16_C(63416), UINT16_C(63416), UINT16_C(63416), UINT16_C(63416), UINT16_C(63416),
      UINT16_C(63416), UINT16_C(63416), UINT16_C(63416), UINT16_C(63416), UINT16_C(63416), UINT16_C(63416), UINT16_C(63416), UINT16_C(63416),
      UINT16_C(63416), UINT16_C(63416), UINT16_C(63416), UINT16_C(63416), UINT16_C(63416), UINT16_C(63416), UINT16_C(63416), UINT16_C(63416),
      UINT16_C(63416), UINT16_C(63416), UINT16_C(63416), UINT16_C(63416), UINT16_C(63416), UINT16_C(63416), UINT16_C(63416), UINT16_C(63416),
      UINT16_C(63416), UINT16_C(63416), UINT16_C(63416), UINT16_C(63416), UINT16_C(63416), UINT16_C(63416), UINT16_C(63416), UINT16_C(63416),
      UINT16_C(63416), UINT16_C(63416), UINT16_C(63416), UINT16_C(63416), UINT16_C(63416), UINT16_C(63416), UINT16_C(63416), UINT16_C(63416),
      UINT16_C(63416), UINT16_C(63416), UINT16_C(63416), UINT16_C(63416), UINT16_C(63416), UINT16_C(63416), UINT16_C(63416), UINT16_C(63416),
      UINT16_C(63416), UINT16_C(63416), UINT16_C(63416), UINT16_C(63416), UINT16_C(63416), UINT16_C(63416), UINT16_C(63416), UINT16_C(63416),
      UINT16_C(63416), UINT16_C(63416), UINT16_C(63416), UINT16_C(63416), UINT16_C(63416), UINT16_C(63416), UINT16_C(63416), UINT16_C(63416),
      UINT16_C(63416), UINT16_C(63416), UINT16_C(63416), UINT16_C(63416), UINT16_C(63416), UINT16_C(63416), UINT16_C(63416), UINT16_C(63416),
      UINT16_C(63416), UINT16_C(63416), UINT16_C(63416), UINT16_C(63416), UINT16_C(63416), UINT16_C(63416), UINT16_C(63416), UINT16_C(63416),
      UINT16_C(63416), UINT16_C(63416), UINT16_C(63416), UINT16_C(63416), UINT16_C(63416), UINT16_C(63416), UINT16_C(63416), UINT16_C(63416),
      UINT16_C(63416), UINT16_C(63416), UINT16_C(63416), UINT16_C(63416), UINT16_C(63416), UINT16_C(63416), UINT16_C(63416), UINT16_C(63416),
      UINT16_C(63416), UINT16_C(63416), UINT16_C(63416), UINT16_C(63416), UINT16_C(63416), UINT16_C(63416), UINT16_C(63416), UINT16_C(63416),
      UINT16_C(63416), UINT16_C(63416), UINT16_C(63416), UINT16_C(63416), UINT16_C(63416), UINT16_C(63416), UINT16_C(63416), UINT16_C(63416),
      UINT16_C(63416), UINT16_C(63416), UINT16_C(63416), UINT16_C(63416), UINT16_C(63416), UINT16_C(63416), UINT16_C(63416), UINT16_C(63416),
      UINT16_C(63416), UINT16_C(63416), UINT16_C(63416), UINT16_C(63416), UINT16_C(63416), UINT16_C(63416), UINT16_C(63416), UINT16_C(63416),
      UINT16_C(63416), UINT16_C(63416), UINT16_C(63416), UINT16_C(63416), UINT16_C(63416), UINT16_C(63416), UINT16_C(63416), UINT16_C(63416),
      UINT16_C(63416), UINT16_C(63416), UINT16_C(63416), UINT16_C(63416), UINT16_C(63416), UINT16_C(63416), UINT16_C(63416), UINT16_C(63416),
      UINT16_C(63416), UINT16_C(63416), UINT16_C(63416), UINT16_C(63416), UINT16_C(63416), UINT16_C(63416), UINT16_C(63416), UINT16_C(63416),
      UINT16_C(63416), UINT16_C(63416), UINT16_C(63416), UINT16_C(63416), UINT16_C(63416), UINT16_C(63416), UINT16_C(63416), UINT16_C(63416),
      UINT16_C(63416), UINT16_C(63416), UINT16_C(63416), UINT16_C(63416), UINT16_C(63416), UINT16_C(63416), UINT16_C(63416), UINT16_C(63416),
      UINT16_C(63416), UINT16_C(63416), UINT16_C(63416), UINT16_C(63416), UINT16_C(63416), UINT16_C(63416), UINT16_C(63416), UINT16_C(63416),
      UINT16_C(63416), UINT16_C(63416), UINT16_C(63416), UINT16_C(63416), UINT16_C(63416), UINT16_C(63416), UINT16_C(63416), UINT16_C(63416),
      UINT16_C(63416), UINT16_C(63416), UINT16_C(63416), UINT16_C(63416), UINT16_C(63416), UINT16_C(63416), UINT16_C(63416), UINT16_C(63416),
      UINT16_C(63416), UINT16_C(63416), UINT16_C(63416), UINT16_C(63416), UINT16_C(63416), UINT16_C(63416), UINT16_C(63416), UINT16_C(63416),
      UINT16_C(63416), UINT16_C(63416), UINT16_C(63416), UINT16_C(63416), UINT16_C(63416), UINT16_C(63416), UINT16_C(63416), UINT16_C(63416),
      UINT16_C(63416), UINT16_C(63416), UINT16_C(63416), UINT16_C(63416), UINT16_C(63416), UINT16_C(63416), UINT16_C(63416), UINT16_C(63416),
      UINT16_C(63416), UINT16_C(63416), UINT16_C(63416), UINT16_C(63416), UINT16_C(63416), UINT16_C(63416), UINT16_C(63416), UINT16_C(63416),
      UINT16_C(63416), UINT16_C(63416), UINT16_C(63416), UINT16_C(63416), UINT16_C(63416), UINT16_C(63416), UINT16_C(63416), UINT16_C(63416),
      UINT16_C(63416), UINT16_C(63416), UINT16_C(63416), UINT16_C(63416), UINT16_C(63416), UINT16_C(63416), UINT16_C(63416), UINT16_C(63416),
      UINT16_C(63416), UINT16_C(63416), UINT16_C(63416), UINT16_C(63416), UINT16_C(63416), UINT16_C(63416), UINT16_C(63416), UINT16_C(63416),
      UINT16_C(63416), UINT16_C(63416), UINT16_C(63416), UINT16_C(63416), UINT16_C(63416), UINT16_C(63416) };

  static uint16_t r[sizeof(e) / sizeof(e[0])];
  static const int32_t len = HEDLEY_STATIC_CAST(int32_t, sizeof(e) / sizeof(e[0]));
  int32_t i = 0;
  simde_svbool_t pg = simde_svwhilelt_b16_s32(i, len);
  while (simde_svptest_first(simde_svptrue_b16(), pg)) {
    simde_svuint16_t rv;

    rv = simde_svdup_n_u16(a);

    simde_svst1_u16(pg, &(r[i]), rv);

    i += simde_svcnth();
    pg = simde_svwhilelt_b16_s32(i, len);
  }

  simde_assert_equal_vu16(len, e, r);

  return 0;
#else
  uint16_t a, e[1024 / sizeof(uint16_t)];
  int32_t len;

  fputc('\n', stdout);

  len = simde_test_codegen_random_u16() & ((sizeof(e) / sizeof(e[0])) - 1);
  a = simde_test_codegen_random_u16();

  int32_t i = 0;
  simde_svbool_t pg = simde_svwhilelt_b16_s32(i, len);
  while (simde_svptest_first(simde_svptrue_b16(), pg)) {
    simde_svuint16_t ev;

    ev = simde_svdup_n_u16(a);

    simde_svst1_u16(pg, &(e[i]), ev);

    i += simde_svcnth();
    pg = simde_svwhilelt_b16_s32(i, len);
  }

  simde_test_codegen_write_1u16(1, a);
  simde_test_codegen_write_1vu16(1, HEDLEY_STATIC_CAST(size_t, len), e);

  return 1;
#endif
}

static int
test_simde_svdup_n_u16_z (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const int16_t p[] =
    {  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),
      -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),
       INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),
       INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),
       INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),
       INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),
      -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
      -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),
      -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),
      -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),
      -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),
      -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),
      -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),
       INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),
      -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),
      -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),
       INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),
       INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),
      -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1) };
  static const uint16_t a = UINT16_C(   12);
  static const uint16_t e[] =
    { UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(   12), UINT16_C(   12), UINT16_C(    0),
      UINT16_C(   12), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(   12), UINT16_C(   12),
      UINT16_C(    0), UINT16_C(   12), UINT16_C(    0), UINT16_C(    0), UINT16_C(   12), UINT16_C(    0), UINT16_C(   12), UINT16_C(    0),
      UINT16_C(    0), UINT16_C(   12), UINT16_C(   12), UINT16_C(   12), UINT16_C(    0), UINT16_C(    0), UINT16_C(   12), UINT16_C(    0),
      UINT16_C(    0), UINT16_C(   12), UINT16_C(    0), UINT16_C(   12), UINT16_C(    0), UINT16_C(   12), UINT16_C(    0), UINT16_C(   12),
      UINT16_C(    0), UINT16_C(   12), UINT16_C(   12), UINT16_C(   12), UINT16_C(   12), UINT16_C(   12), UINT16_C(    0), UINT16_C(   12),
      UINT16_C(   12), UINT16_C(    0), UINT16_C(   12), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0),
      UINT16_C(   12), UINT16_C(    0), UINT16_C(   12), UINT16_C(    0), UINT16_C(   12), UINT16_C(   12), UINT16_C(   12), UINT16_C(    0),
      UINT16_C(   12), UINT16_C(   12), UINT16_C(   12), UINT16_C(    0), UINT16_C(   12), UINT16_C(   12), UINT16_C(    0), UINT16_C(   12),
      UINT16_C(   12), UINT16_C(   12), UINT16_C(    0), UINT16_C(   12), UINT16_C(    0), UINT16_C(   12), UINT16_C(    0), UINT16_C(   12),
      UINT16_C(   12), UINT16_C(   12), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(   12), UINT16_C(    0), UINT16_C(   12),
      UINT16_C(   12), UINT16_C(   12), UINT16_C(    0), UINT16_C(    0), UINT16_C(   12), UINT16_C(   12), UINT16_C(   12), UINT16_C(    0),
      UINT16_C(   12), UINT16_C(   12), UINT16_C(   12), UINT16_C(    0), UINT16_C(   12), UINT16_C(   12), UINT16_C(   12), UINT16_C(    0),
      UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(   12), UINT16_C(   12), UINT16_C(   12),
      UINT16_C(   12), UINT16_C(    0), UINT16_C(   12), UINT16_C(   12), UINT16_C(   12), UINT16_C(    0), UINT16_C(   12), UINT16_C(   12),
      UINT16_C(   12), UINT16_C(    0), UINT16_C(    0), UINT16_C(   12), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(   12),
      UINT16_C(    0), UINT16_C(   12), UINT16_C(    0), UINT16_C(   12), UINT16_C(    0), UINT16_C(    0), UINT16_C(   12), UINT16_C(   12),
      UINT16_C(    0), UINT16_C(    0), UINT16_C(   12), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(   12),
      UINT16_C(   12), UINT16_C(    0), UINT16_C(   12), UINT16_C(   12), UINT16_C(   12) };

  static uint16_t r[sizeof(e) / sizeof(e[0])];
  static const int32_t len = HEDLEY_STATIC_CAST(int32_t, sizeof(e) / sizeof(e[0]));
  int32_t i = 0;
  simde_svbool_t pg = simde_svwhilelt_b16_s32(i, len);
  while (simde_svptest_first(simde_svptrue_b16(), pg)) {
    simde_svuint16_t rv;
    simde_svbool_t pv;

    pv = simde_svcmplt_s16(pg, simde_svld1_s16(pg, &(p[i])), simde_svdup_n_s16(INT16_C(0)));
    rv = simde_svdup_n_u16_z(pv, a);

    simde_svst1_u16(pg, &(r[i]), rv);

    i += simde_svcnth();
    pg = simde_svwhilelt_b16_s32(i, len);
  }

  simde_assert_equal_vu16(len, e, r);

  return 0;
#else
  uint16_t a, e[1024 / sizeof(uint16_t)];
  int16_t p[1024 / sizeof(uint16_t)];
  int32_t len;

  fputc('\n', stdout);

  len = simde_test_codegen_random_i16() & ((sizeof(e) / sizeof(e[0])) - 1);
  simde_test_codegen_random_memory(sizeof(p), HEDLEY_REINTERPRET_CAST(uint8_t*, p));
  a = simde_test_codegen_random_u8();

  int32_t i = 0;
  simde_svbool_t pg = simde_svwhilelt_b16_s32(i, len);
  while (simde_svptest_first(simde_svptrue_b16(), pg)) {
    simde_svuint16_t ev;
    simde_svbool_t pv;

    pv = simde_svcmplt_s16(pg, simde_svld1_s16(pg, &(p[i])), simde_svdup_n_s16(0));
    ev = simde_svdup_n_u16_z(pv, a);

    simde_svst1_u16(pg, &(e[i]), ev);
    simde_svst1_s16(pg, &(p[i]), simde_svdup_n_s16_z(pv, ~INT16_C(0)));

    i += simde_svcnth();
    pg = simde_svwhilelt_b16_s32(i, len);
  }

  simde_test_codegen_write_1vi16(1, HEDLEY_STATIC_CAST(size_t, len), p);
  simde_test_codegen_write_1u16(1, a);
  simde_test_codegen_write_1vu16(1, HEDLEY_STATIC_CAST(size_t, len), e);

  return 1;
#endif
}

static int
test_simde_svdup_n_u16_m (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const int16_t p[] =
    { -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),
      -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
       INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),
      -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),
       INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),
      -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),
       INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),
      -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),
       INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),
      -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),
       INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),
      -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),
       INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),
      -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),
       INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),
       INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),
      -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),
      -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),
      -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),
       INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),
      -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),
      -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),
      -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),
       INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),
      -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),
       INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
       INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),
       INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
      -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),
       INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),
       INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),
      -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),
      -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),
       INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),
      -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),
       INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),
       INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),
      -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),
      -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),
      -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),
       INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),
      -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),
       INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),
      -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),
      -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),
       INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),
       INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),
       INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),
       INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),
       INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),
      -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),
      -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),
      -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),
      -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),
      -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),
      -INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),
      -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0),
      -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),  INT16_C(     0), -INT16_C(     1) };
  static const uint16_t a[] =
    { UINT16_C(46122), UINT16_C(54535), UINT16_C(10815), UINT16_C( 9719), UINT16_C(40346), UINT16_C(62728), UINT16_C(25175), UINT16_C(48025),
      UINT16_C(28626), UINT16_C(16610), UINT16_C(42107), UINT16_C(17080), UINT16_C(26816), UINT16_C(34960), UINT16_C(12600), UINT16_C(25223),
      UINT16_C(36582), UINT16_C( 9527), UINT16_C(12216), UINT16_C(21066), UINT16_C(21196), UINT16_C( 9031), UINT16_C(57781), UINT16_C(34783),
      UINT16_C(49488), UINT16_C(52168), UINT16_C(32869), UINT16_C( 9486), UINT16_C(40680), UINT16_C( 8366), UINT16_C(13776), UINT16_C(46722),
      UINT16_C(47555), UINT16_C(31707), UINT16_C( 9960), UINT16_C(46541), UINT16_C( 5496), UINT16_C(11736), UINT16_C(47094), UINT16_C(18101),
      UINT16_C(32120), UINT16_C(56594), UINT16_C( 8445), UINT16_C(58627), UINT16_C(45502), UINT16_C(36357), UINT16_C(34790), UINT16_C(43332),
      UINT16_C( 8256), UINT16_C(10532), UINT16_C(61766), UINT16_C(48862), UINT16_C(46598), UINT16_C(64748), UINT16_C(41326), UINT16_C(58947),
      UINT16_C(21790), UINT16_C( 7108), UINT16_C(51061), UINT16_C(13056), UINT16_C( 1400), UINT16_C(24258), UINT16_C( 1676), UINT16_C(52231),
      UINT16_C(11046), UINT16_C(27893), UINT16_C(54044), UINT16_C( 9003), UINT16_C( 6026), UINT16_C(63519), UINT16_C(25272), UINT16_C(55006),
      UINT16_C(41655), UINT16_C(11505), UINT16_C(61801), UINT16_C(57696), UINT16_C( 8950), UINT16_C(33343), UINT16_C(17960), UINT16_C(20302),
      UINT16_C(17521), UINT16_C(36539), UINT16_C(58903), UINT16_C(41393), UINT16_C(53501), UINT16_C(46489), UINT16_C(30771), UINT16_C(60043),
      UINT16_C(31770), UINT16_C(33815), UINT16_C(30573), UINT16_C(25445), UINT16_C(42393), UINT16_C(49637), UINT16_C(13547), UINT16_C(23824),
      UINT16_C(52344), UINT16_C(36843), UINT16_C(40114), UINT16_C(45105), UINT16_C(51820), UINT16_C(40805), UINT16_C(61762), UINT16_C(23946),
      UINT16_C(41325), UINT16_C(56289), UINT16_C(17944), UINT16_C(45374), UINT16_C( 9451), UINT16_C(55154), UINT16_C(33624), UINT16_C(53300),
      UINT16_C( 8015), UINT16_C(  351), UINT16_C(37051), UINT16_C(10161), UINT16_C( 5979), UINT16_C(40391), UINT16_C(20744), UINT16_C(30202),
      UINT16_C(56306), UINT16_C( 2640), UINT16_C(36642), UINT16_C( 3515), UINT16_C(11699), UINT16_C( 3044), UINT16_C( 6320), UINT16_C(65499),
      UINT16_C(14903), UINT16_C(61953), UINT16_C(45771), UINT16_C( 9754), UINT16_C(57801), UINT16_C(53699), UINT16_C(48690), UINT16_C( 9287),
      UINT16_C(38809), UINT16_C(47918), UINT16_C(59686), UINT16_C(55753), UINT16_C(44310), UINT16_C(51172), UINT16_C(49094), UINT16_C(64966),
      UINT16_C(51194), UINT16_C(50672), UINT16_C( 2682), UINT16_C(17387), UINT16_C(44779), UINT16_C( 7445), UINT16_C(23660), UINT16_C( 1601),
      UINT16_C(28659), UINT16_C( 6849), UINT16_C(35416), UINT16_C(28403), UINT16_C(55352), UINT16_C(65077), UINT16_C(64663), UINT16_C(37371),
      UINT16_C(60355), UINT16_C(15702), UINT16_C(16885), UINT16_C(57473), UINT16_C(38640), UINT16_C(23805), UINT16_C(16114), UINT16_C(58722),
      UINT16_C( 9389), UINT16_C( 1535), UINT16_C(62382), UINT16_C(58996), UINT16_C(43467), UINT16_C(25316), UINT16_C(57509), UINT16_C(27124),
      UINT16_C(19147), UINT16_C(49574), UINT16_C(10124), UINT16_C(31905), UINT16_C(40893), UINT16_C(45016), UINT16_C(15325), UINT16_C(35733),
      UINT16_C(37983), UINT16_C( 3472), UINT16_C( 1159), UINT16_C(21236), UINT16_C(55470), UINT16_C(21429), UINT16_C(43448), UINT16_C(33980),
      UINT16_C(25587), UINT16_C(32581), UINT16_C(59018), UINT16_C(18683), UINT16_C(54405), UINT16_C(25591), UINT16_C(35855), UINT16_C(28398),
      UINT16_C(32289), UINT16_C(43131), UINT16_C(28547), UINT16_C(12795), UINT16_C(45128), UINT16_C(  132), UINT16_C(16729), UINT16_C(19588),
      UINT16_C(51620), UINT16_C(11980), UINT16_C(51120), UINT16_C(13686), UINT16_C(28315), UINT16_C(43672), UINT16_C(34554), UINT16_C( 6936),
      UINT16_C(37893), UINT16_C(35012), UINT16_C(48899), UINT16_C(19385), UINT16_C(15727), UINT16_C(51276), UINT16_C(53374), UINT16_C( 8724),
      UINT16_C(57498), UINT16_C(19025), UINT16_C(51112), UINT16_C(17279), UINT16_C( 6197), UINT16_C(12526), UINT16_C( 1694), UINT16_C(41803),
      UINT16_C( 3994), UINT16_C(40491), UINT16_C(58574), UINT16_C(15849), UINT16_C(13602), UINT16_C(40965), UINT16_C( 6662), UINT16_C(41155),
      UINT16_C( 5370), UINT16_C(41706), UINT16_C(27099), UINT16_C( 4582), UINT16_C(54401), UINT16_C( 8257), UINT16_C(36058), UINT16_C(30147),
      UINT16_C(61340), UINT16_C(27155), UINT16_C(64723), UINT16_C(62888), UINT16_C(44338), UINT16_C(14486), UINT16_C(22983), UINT16_C(49880),
      UINT16_C(49773), UINT16_C(18532), UINT16_C(18987), UINT16_C(44377), UINT16_C(39454), UINT16_C(63949), UINT16_C(36903), UINT16_C(50030),
      UINT16_C(33151), UINT16_C(21293), UINT16_C(54653), UINT16_C(44872), UINT16_C(56963), UINT16_C(19175), UINT16_C(48951), UINT16_C(41996),
      UINT16_C(29057), UINT16_C(44525), UINT16_C(18107), UINT16_C(55898), UINT16_C(10209), UINT16_C( 2259), UINT16_C(16823), UINT16_C(14283),
      UINT16_C(63682), UINT16_C(16266), UINT16_C(53966), UINT16_C(20975), UINT16_C(54961), UINT16_C(59547), UINT16_C(43158), UINT16_C( 6029),
      UINT16_C(31257), UINT16_C(54468), UINT16_C( 7872), UINT16_C(41390), UINT16_C(33093), UINT16_C(64937), UINT16_C(29890), UINT16_C(33844),
      UINT16_C(48749), UINT16_C(15300), UINT16_C(45968), UINT16_C(16780), UINT16_C(10121), UINT16_C( 7978), UINT16_C(47055), UINT16_C(59447),
      UINT16_C(64305), UINT16_C(61885), UINT16_C(27418), UINT16_C(24467), UINT16_C(15597), UINT16_C(44892), UINT16_C(37041), UINT16_C( 7732),
      UINT16_C(63566), UINT16_C(57177), UINT16_C(58795), UINT16_C(13344), UINT16_C(18956), UINT16_C(56404), UINT16_C(35585), UINT16_C(12996),
      UINT16_C(33158), UINT16_C(40996), UINT16_C(47085), UINT16_C(55808), UINT16_C(23795), UINT16_C(42121), UINT16_C(48621), UINT16_C(15298),
      UINT16_C( 7093), UINT16_C(24602), UINT16_C(15104), UINT16_C( 3477), UINT16_C(59781), UINT16_C(34793), UINT16_C(44404), UINT16_C(64185),
      UINT16_C(56623), UINT16_C( 7323), UINT16_C(39828), UINT16_C(35062), UINT16_C(32759), UINT16_C(58412), UINT16_C(61245), UINT16_C(61984),
      UINT16_C(14858), UINT16_C( 2899), UINT16_C(59509), UINT16_C(64280), UINT16_C(  465), UINT16_C(17794), UINT16_C(15278), UINT16_C(56639),
      UINT16_C(55833), UINT16_C(44537), UINT16_C(61301), UINT16_C(27957), UINT16_C(25199), UINT16_C(44113), UINT16_C(29009), UINT16_C(23454),
      UINT16_C(61868), UINT16_C( 8550), UINT16_C(32473), UINT16_C(43548), UINT16_C(40575), UINT16_C(12015), UINT16_C(12250), UINT16_C(62219),
      UINT16_C( 1289), UINT16_C(32672), UINT16_C(55028), UINT16_C(25580), UINT16_C(15672), UINT16_C(35087), UINT16_C(44719), UINT16_C(23524),
      UINT16_C(19359), UINT16_C(31100), UINT16_C(39369), UINT16_C(18723), UINT16_C( 4919), UINT16_C( 4471), UINT16_C(33346), UINT16_C(19204),
      UINT16_C(42375), UINT16_C(31946), UINT16_C(46715), UINT16_C(46047), UINT16_C(61428), UINT16_C(41788), UINT16_C( 8349), UINT16_C(15614),
      UINT16_C(31339), UINT16_C(13749), UINT16_C(55571), UINT16_C(19326), UINT16_C(62956), UINT16_C(11868), UINT16_C(24951), UINT16_C(65401),
      UINT16_C(17414), UINT16_C(33147), UINT16_C(23290), UINT16_C(60980), UINT16_C(28745), UINT16_C(59025), UINT16_C(36752), UINT16_C(64547),
      UINT16_C(55306), UINT16_C( 7473), UINT16_C(44977), UINT16_C(40296), UINT16_C(50596), UINT16_C( 7115), UINT16_C(17702), UINT16_C(11290),
      UINT16_C(38281), UINT16_C(33709), UINT16_C(57840), UINT16_C(14706), UINT16_C(  849), UINT16_C(57632), UINT16_C(17299), UINT16_C(40413),
      UINT16_C( 3611), UINT16_C(52666), UINT16_C( 9149), UINT16_C(24938), UINT16_C(14056), UINT16_C( 3709), UINT16_C(38779), UINT16_C( 1082),
      UINT16_C(59181), UINT16_C( 7559), UINT16_C(63944), UINT16_C( 6486), UINT16_C(30461), UINT16_C(37114), UINT16_C(55481), UINT16_C(54573),
      UINT16_C(59366), UINT16_C(42146), UINT16_C( 3082), UINT16_C(61957), UINT16_C(33346), UINT16_C(48384), UINT16_C(14874), UINT16_C(18369),
      UINT16_C(18721), UINT16_C(59748), UINT16_C(47682), UINT16_C(16130), UINT16_C(64817), UINT16_C(60111), UINT16_C(64725), UINT16_C(48063),
      UINT16_C(25060), UINT16_C(61023), UINT16_C(25966), UINT16_C(45281), UINT16_C(57831) };
  static const uint16_t b = UINT16_C( 2791);
  static const uint16_t e[] =
    { UINT16_C( 2791), UINT16_C(54535), UINT16_C(10815), UINT16_C( 9719), UINT16_C(40346), UINT16_C( 2791), UINT16_C(25175), UINT16_C(48025),
      UINT16_C( 2791), UINT16_C( 2791), UINT16_C(42107), UINT16_C(17080), UINT16_C( 2791), UINT16_C(34960), UINT16_C(12600), UINT16_C(25223),
      UINT16_C(36582), UINT16_C( 2791), UINT16_C( 2791), UINT16_C(21066), UINT16_C( 2791), UINT16_C( 9031), UINT16_C( 2791), UINT16_C( 2791),
      UINT16_C( 2791), UINT16_C( 2791), UINT16_C(32869), UINT16_C( 9486), UINT16_C( 2791), UINT16_C( 8366), UINT16_C( 2791), UINT16_C( 2791),
      UINT16_C(47555), UINT16_C(31707), UINT16_C( 2791), UINT16_C(46541), UINT16_C( 5496), UINT16_C(11736), UINT16_C( 2791), UINT16_C(18101),
      UINT16_C( 2791), UINT16_C( 2791), UINT16_C( 2791), UINT16_C(58627), UINT16_C( 2791), UINT16_C( 2791), UINT16_C( 2791), UINT16_C(43332),
      UINT16_C( 8256), UINT16_C( 2791), UINT16_C( 2791), UINT16_C(48862), UINT16_C(46598), UINT16_C( 2791), UINT16_C(41326), UINT16_C( 2791),
      UINT16_C( 2791), UINT16_C( 7108), UINT16_C( 2791), UINT16_C(13056), UINT16_C( 2791), UINT16_C(24258), UINT16_C( 1676), UINT16_C( 2791),
      UINT16_C(11046), UINT16_C( 2791), UINT16_C(54044), UINT16_C( 2791), UINT16_C( 6026), UINT16_C( 2791), UINT16_C(25272), UINT16_C( 2791),
      UINT16_C( 2791), UINT16_C(11505), UINT16_C( 2791), UINT16_C( 2791), UINT16_C( 2791), UINT16_C(33343), UINT16_C( 2791), UINT16_C( 2791),
      UINT16_C(17521), UINT16_C( 2791), UINT16_C( 2791), UINT16_C(41393), UINT16_C(53501), UINT16_C( 2791), UINT16_C(30771), UINT16_C( 2791),
      UINT16_C( 2791), UINT16_C( 2791), UINT16_C( 2791), UINT16_C( 2791), UINT16_C( 2791), UINT16_C( 2791), UINT16_C(13547), UINT16_C( 2791),
      UINT16_C(52344), UINT16_C(36843), UINT16_C( 2791), UINT16_C(45105), UINT16_C( 2791), UINT16_C( 2791), UINT16_C( 2791), UINT16_C(23946),
      UINT16_C( 2791), UINT16_C( 2791), UINT16_C( 2791), UINT16_C(45374), UINT16_C( 9451), UINT16_C( 2791), UINT16_C( 2791), UINT16_C( 2791),
      UINT16_C( 8015), UINT16_C(  351), UINT16_C( 2791), UINT16_C( 2791), UINT16_C( 5979), UINT16_C( 2791), UINT16_C(20744), UINT16_C(30202),
      UINT16_C(56306), UINT16_C( 2640), UINT16_C( 2791), UINT16_C( 2791), UINT16_C( 2791), UINT16_C( 3044), UINT16_C( 2791), UINT16_C( 2791),
      UINT16_C( 2791), UINT16_C( 2791), UINT16_C(45771), UINT16_C( 2791), UINT16_C(57801), UINT16_C( 2791), UINT16_C( 2791), UINT16_C( 9287),
      UINT16_C( 2791), UINT16_C( 2791), UINT16_C( 2791), UINT16_C( 2791), UINT16_C( 2791), UINT16_C( 2791), UINT16_C(49094), UINT16_C(64966),
      UINT16_C( 2791), UINT16_C(50672), UINT16_C( 2682), UINT16_C(17387), UINT16_C(44779), UINT16_C( 2791), UINT16_C( 2791), UINT16_C( 2791),
      UINT16_C(28659), UINT16_C( 6849), UINT16_C( 2791), UINT16_C( 2791), UINT16_C(55352), UINT16_C( 2791), UINT16_C( 2791), UINT16_C( 2791),
      UINT16_C( 2791), UINT16_C(15702), UINT16_C( 2791), UINT16_C(57473), UINT16_C( 2791), UINT16_C( 2791), UINT16_C( 2791), UINT16_C(58722),
      UINT16_C( 2791), UINT16_C( 2791), UINT16_C( 2791), UINT16_C(58996), UINT16_C(43467), UINT16_C(25316), UINT16_C( 2791), UINT16_C(27124),
      UINT16_C( 2791), UINT16_C(49574), UINT16_C( 2791), UINT16_C( 2791), UINT16_C(40893), UINT16_C(45016), UINT16_C( 2791), UINT16_C(35733),
      UINT16_C(37983), UINT16_C( 3472), UINT16_C( 1159), UINT16_C(21236), UINT16_C(55470), UINT16_C( 2791), UINT16_C( 2791), UINT16_C(33980),
      UINT16_C( 2791), UINT16_C(32581), UINT16_C(59018), UINT16_C( 2791), UINT16_C(54405), UINT16_C( 2791), UINT16_C( 2791), UINT16_C( 2791),
      UINT16_C(32289), UINT16_C(43131), UINT16_C(28547), UINT16_C(12795), UINT16_C(45128), UINT16_C(  132), UINT16_C(16729), UINT16_C(19588),
      UINT16_C(51620), UINT16_C( 2791), UINT16_C(51120), UINT16_C( 2791), UINT16_C( 2791), UINT16_C(43672), UINT16_C( 2791), UINT16_C( 6936),
      UINT16_C(37893), UINT16_C(35012), UINT16_C( 2791), UINT16_C( 2791), UINT16_C(15727), UINT16_C(51276), UINT16_C(53374), UINT16_C( 8724),
      UINT16_C( 2791), UINT16_C(19025), UINT16_C(51112), UINT16_C(17279), UINT16_C( 6197), UINT16_C(12526), UINT16_C( 2791), UINT16_C( 2791),
      UINT16_C( 3994), UINT16_C(40491), UINT16_C( 2791), UINT16_C(15849), UINT16_C(13602), UINT16_C( 2791), UINT16_C( 6662), UINT16_C( 2791),
      UINT16_C( 5370), UINT16_C(41706), UINT16_C(27099), UINT16_C( 4582), UINT16_C(54401), UINT16_C( 2791), UINT16_C(36058), UINT16_C( 2791),
      UINT16_C( 2791), UINT16_C(27155), UINT16_C( 2791), UINT16_C( 2791), UINT16_C( 2791), UINT16_C(14486), UINT16_C( 2791), UINT16_C(49880),
      UINT16_C( 2791), UINT16_C( 2791), UINT16_C(18987), UINT16_C(44377), UINT16_C(39454), UINT16_C( 2791), UINT16_C(36903), UINT16_C( 2791),
      UINT16_C(33151), UINT16_C(21293), UINT16_C( 2791), UINT16_C(44872), UINT16_C( 2791), UINT16_C(19175), UINT16_C(48951), UINT16_C( 2791),
      UINT16_C( 2791), UINT16_C( 2791), UINT16_C( 2791), UINT16_C( 2791), UINT16_C(10209), UINT16_C( 2791), UINT16_C( 2791), UINT16_C(14283),
      UINT16_C(63682), UINT16_C( 2791), UINT16_C( 2791), UINT16_C( 2791), UINT16_C(54961), UINT16_C( 2791), UINT16_C(43158), UINT16_C( 2791),
      UINT16_C(31257), UINT16_C( 2791), UINT16_C( 2791), UINT16_C( 2791), UINT16_C( 2791), UINT16_C( 2791), UINT16_C(29890), UINT16_C(33844),
      UINT16_C( 2791), UINT16_C( 2791), UINT16_C(45968), UINT16_C(16780), UINT16_C(10121), UINT16_C( 2791), UINT16_C(47055), UINT16_C( 2791),
      UINT16_C( 2791), UINT16_C(61885), UINT16_C(27418), UINT16_C( 2791), UINT16_C(15597), UINT16_C( 2791), UINT16_C(37041), UINT16_C( 2791),
      UINT16_C( 2791), UINT16_C( 2791), UINT16_C( 2791), UINT16_C( 2791), UINT16_C( 2791), UINT16_C( 2791), UINT16_C(35585), UINT16_C( 2791),
      UINT16_C(33158), UINT16_C( 2791), UINT16_C(47085), UINT16_C(55808), UINT16_C( 2791), UINT16_C(42121), UINT16_C( 2791), UINT16_C(15298),
      UINT16_C( 2791), UINT16_C(24602), UINT16_C( 2791), UINT16_C( 2791), UINT16_C(59781), UINT16_C( 2791), UINT16_C(44404), UINT16_C(64185),
      UINT16_C(56623), UINT16_C( 2791), UINT16_C( 2791), UINT16_C(35062), UINT16_C(32759), UINT16_C( 2791), UINT16_C(61245), UINT16_C(61984),
      UINT16_C( 2791), UINT16_C( 2899), UINT16_C( 2791), UINT16_C(64280), UINT16_C(  465), UINT16_C(17794), UINT16_C(15278), UINT16_C( 2791),
      UINT16_C( 2791), UINT16_C(44537), UINT16_C( 2791), UINT16_C( 2791), UINT16_C( 2791), UINT16_C(44113), UINT16_C( 2791), UINT16_C(23454),
      UINT16_C(61868), UINT16_C( 2791), UINT16_C( 2791), UINT16_C(43548), UINT16_C(40575), UINT16_C(12015), UINT16_C( 2791), UINT16_C(62219),
      UINT16_C( 1289), UINT16_C(32672), UINT16_C( 2791), UINT16_C( 2791), UINT16_C( 2791), UINT16_C( 2791), UINT16_C(44719), UINT16_C( 2791),
      UINT16_C(19359), UINT16_C(31100), UINT16_C(39369), UINT16_C(18723), UINT16_C( 2791), UINT16_C( 2791), UINT16_C( 2791), UINT16_C(19204),
      UINT16_C(42375), UINT16_C( 2791), UINT16_C(46715), UINT16_C(46047), UINT16_C( 2791), UINT16_C( 2791), UINT16_C( 8349), UINT16_C( 2791),
      UINT16_C(31339), UINT16_C(13749), UINT16_C( 2791), UINT16_C(19326), UINT16_C(62956), UINT16_C( 2791), UINT16_C( 2791), UINT16_C( 2791),
      UINT16_C( 2791), UINT16_C( 2791), UINT16_C(23290), UINT16_C(60980), UINT16_C( 2791), UINT16_C(59025), UINT16_C( 2791), UINT16_C(64547),
      UINT16_C( 2791), UINT16_C( 7473), UINT16_C(44977), UINT16_C( 2791), UINT16_C(50596), UINT16_C( 7115), UINT16_C( 2791), UINT16_C(11290),
      UINT16_C( 2791), UINT16_C(33709), UINT16_C(57840), UINT16_C(14706), UINT16_C(  849), UINT16_C( 2791), UINT16_C( 2791), UINT16_C( 2791),
      UINT16_C( 2791), UINT16_C( 2791), UINT16_C( 2791), UINT16_C(24938), UINT16_C( 2791), UINT16_C( 2791), UINT16_C( 2791), UINT16_C( 1082),
      UINT16_C( 2791), UINT16_C( 2791), UINT16_C(63944), UINT16_C( 6486), UINT16_C( 2791), UINT16_C(37114), UINT16_C( 2791), UINT16_C( 2791),
      UINT16_C( 2791), UINT16_C(42146), UINT16_C( 3082), UINT16_C(61957), UINT16_C( 2791), UINT16_C( 2791), UINT16_C(14874), UINT16_C( 2791),
      UINT16_C( 2791), UINT16_C( 2791), UINT16_C( 2791), UINT16_C( 2791), UINT16_C(64817), UINT16_C(60111), UINT16_C( 2791), UINT16_C(48063),
      UINT16_C( 2791), UINT16_C(61023), UINT16_C( 2791), UINT16_C(45281), UINT16_C( 2791) };

  static uint16_t r[sizeof(e) / sizeof(e[0])];
  static const int32_t len = HEDLEY_STATIC_CAST(int32_t, sizeof(e) / sizeof(e[0]));
  int32_t i = 0;
  simde_svbool_t pg = simde_svwhilelt_b16_s32(i, len);
  while (simde_svptest_first(simde_svptrue_b16(), pg)) {
    simde_svuint16_t
      rv,
      av = simde_svld1_u16(pg, &(a[i]));
    simde_svbool_t pv;

    pv = simde_svcmplt_s16(pg, simde_svld1_s16(pg, &(p[i])), simde_svdup_n_s16(INT16_C(0)));
    rv = simde_svdup_n_u16_m(av, pv, b);

    simde_svst1_u16(pg, &(r[i]), rv);

    i += simde_svcnth();
    pg = simde_svwhilelt_b16_s32(i, len);
  }

  simde_assert_equal_vu16(len, e, r);

  return 0;
#else
  int16_t p[1024 / sizeof(uint16_t)];
  uint16_t a[1024 / sizeof(uint16_t)], b, e[1024 / sizeof(uint16_t)];
  int32_t len = simde_test_arm_sve_random_length(sizeof(e), sizeof(e[0]));

  fputc('\n', stdout);

  simde_test_codegen_random_memory(sizeof(p), HEDLEY_REINTERPRET_CAST(uint8_t*, p));
  simde_test_codegen_random_memory(sizeof(a), HEDLEY_REINTERPRET_CAST(uint8_t*, a));
  b = simde_test_codegen_random_u16();

  int32_t i = 0;
  simde_svbool_t pg = simde_svwhilelt_b16_s32(i, len);
  while (simde_svptest_first(simde_svptrue_b16(), pg)) {
    simde_svuint16_t av, ev;
    simde_svbool_t pv;

    pv = simde_svcmplt_s16(pg, simde_svld1_s16(pg, &(p[i])), simde_svdup_n_s16(0));
    av = simde_svld1_u16(pg, &(a[i]));

    ev = simde_svdup_n_u16_m(av, pv, b);

    simde_svst1_u16(pg, &(e[i]), ev);
    simde_svst1_s16(pg, &(p[i]), simde_svdup_n_s16_z(pv, ~INT16_C(0)));

    i += simde_svcnth();
    pg = simde_svwhilelt_b16_s32(i, len);
  }

  simde_test_codegen_write_1vi16(1, HEDLEY_STATIC_CAST(size_t, len), p);
  simde_test_codegen_write_1vu16(1, HEDLEY_STATIC_CAST(size_t, len), a);
  simde_test_codegen_write_1u16(1, b);
  simde_test_codegen_write_1vu16(1, HEDLEY_STATIC_CAST(size_t, len), e);

  return 1;
#endif
}

static int
test_simde_svdup_n_u32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const uint32_t a = UINT32_C(2164833827);
  static const uint32_t e[] =
    { UINT32_C(2164833827), UINT32_C(2164833827), UINT32_C(2164833827), UINT32_C(2164833827), UINT32_C(2164833827), UINT32_C(2164833827), UINT32_C(2164833827), UINT32_C(2164833827),
      UINT32_C(2164833827), UINT32_C(2164833827), UINT32_C(2164833827), UINT32_C(2164833827), UINT32_C(2164833827), UINT32_C(2164833827), UINT32_C(2164833827), UINT32_C(2164833827),
      UINT32_C(2164833827), UINT32_C(2164833827), UINT32_C(2164833827), UINT32_C(2164833827), UINT32_C(2164833827), UINT32_C(2164833827), UINT32_C(2164833827), UINT32_C(2164833827),
      UINT32_C(2164833827), UINT32_C(2164833827), UINT32_C(2164833827), UINT32_C(2164833827), UINT32_C(2164833827), UINT32_C(2164833827), UINT32_C(2164833827), UINT32_C(2164833827),
      UINT32_C(2164833827), UINT32_C(2164833827), UINT32_C(2164833827), UINT32_C(2164833827), UINT32_C(2164833827), UINT32_C(2164833827), UINT32_C(2164833827), UINT32_C(2164833827),
      UINT32_C(2164833827), UINT32_C(2164833827), UINT32_C(2164833827), UINT32_C(2164833827), UINT32_C(2164833827), UINT32_C(2164833827), UINT32_C(2164833827), UINT32_C(2164833827),
      UINT32_C(2164833827), UINT32_C(2164833827), UINT32_C(2164833827), UINT32_C(2164833827), UINT32_C(2164833827), UINT32_C(2164833827), UINT32_C(2164833827), UINT32_C(2164833827),
      UINT32_C(2164833827), UINT32_C(2164833827), UINT32_C(2164833827), UINT32_C(2164833827), UINT32_C(2164833827), UINT32_C(2164833827), UINT32_C(2164833827), UINT32_C(2164833827),
      UINT32_C(2164833827), UINT32_C(2164833827), UINT32_C(2164833827), UINT32_C(2164833827), UINT32_C(2164833827), UINT32_C(2164833827), UINT32_C(2164833827), UINT32_C(2164833827),
      UINT32_C(2164833827), UINT32_C(2164833827), UINT32_C(2164833827), UINT32_C(2164833827), UINT32_C(2164833827), UINT32_C(2164833827), UINT32_C(2164833827), UINT32_C(2164833827),
      UINT32_C(2164833827), UINT32_C(2164833827), UINT32_C(2164833827), UINT32_C(2164833827), UINT32_C(2164833827), UINT32_C(2164833827), UINT32_C(2164833827), UINT32_C(2164833827),
      UINT32_C(2164833827), UINT32_C(2164833827), UINT32_C(2164833827), UINT32_C(2164833827), UINT32_C(2164833827), UINT32_C(2164833827), UINT32_C(2164833827), UINT32_C(2164833827),
      UINT32_C(2164833827), UINT32_C(2164833827), UINT32_C(2164833827), UINT32_C(2164833827), UINT32_C(2164833827), UINT32_C(2164833827), UINT32_C(2164833827), UINT32_C(2164833827),
      UINT32_C(2164833827), UINT32_C(2164833827), UINT32_C(2164833827), UINT32_C(2164833827), UINT32_C(2164833827), UINT32_C(2164833827), UINT32_C(2164833827), UINT32_C(2164833827),
      UINT32_C(2164833827), UINT32_C(2164833827), UINT32_C(2164833827), UINT32_C(2164833827), UINT32_C(2164833827), UINT32_C(2164833827), UINT32_C(2164833827), UINT32_C(2164833827),
      UINT32_C(2164833827), UINT32_C(2164833827), UINT32_C(2164833827), UINT32_C(2164833827), UINT32_C(2164833827), UINT32_C(2164833827), UINT32_C(2164833827), UINT32_C(2164833827),
      UINT32_C(2164833827), UINT32_C(2164833827), UINT32_C(2164833827), UINT32_C(2164833827), UINT32_C(2164833827), UINT32_C(2164833827), UINT32_C(2164833827), UINT32_C(2164833827),
      UINT32_C(2164833827), UINT32_C(2164833827), UINT32_C(2164833827), UINT32_C(2164833827), UINT32_C(2164833827), UINT32_C(2164833827), UINT32_C(2164833827), UINT32_C(2164833827),
      UINT32_C(2164833827), UINT32_C(2164833827), UINT32_C(2164833827), UINT32_C(2164833827), UINT32_C(2164833827), UINT32_C(2164833827), UINT32_C(2164833827), UINT32_C(2164833827),
      UINT32_C(2164833827), UINT32_C(2164833827), UINT32_C(2164833827), UINT32_C(2164833827), UINT32_C(2164833827), UINT32_C(2164833827), UINT32_C(2164833827), UINT32_C(2164833827),
      UINT32_C(2164833827), UINT32_C(2164833827), UINT32_C(2164833827), UINT32_C(2164833827), UINT32_C(2164833827), UINT32_C(2164833827), UINT32_C(2164833827), UINT32_C(2164833827),
      UINT32_C(2164833827), UINT32_C(2164833827), UINT32_C(2164833827), UINT32_C(2164833827), UINT32_C(2164833827), UINT32_C(2164833827), UINT32_C(2164833827), UINT32_C(2164833827),
      UINT32_C(2164833827), UINT32_C(2164833827), UINT32_C(2164833827), UINT32_C(2164833827), UINT32_C(2164833827), UINT32_C(2164833827), UINT32_C(2164833827), UINT32_C(2164833827),
      UINT32_C(2164833827), UINT32_C(2164833827), UINT32_C(2164833827), UINT32_C(2164833827), UINT32_C(2164833827), UINT32_C(2164833827), UINT32_C(2164833827), UINT32_C(2164833827),
      UINT32_C(2164833827), UINT32_C(2164833827), UINT32_C(2164833827), UINT32_C(2164833827), UINT32_C(2164833827), UINT32_C(2164833827), UINT32_C(2164833827), UINT32_C(2164833827),
      UINT32_C(2164833827), UINT32_C(2164833827), UINT32_C(2164833827), UINT32_C(2164833827), UINT32_C(2164833827), UINT32_C(2164833827), UINT32_C(2164833827), UINT32_C(2164833827),
      UINT32_C(2164833827), UINT32_C(2164833827), UINT32_C(2164833827), UINT32_C(2164833827), UINT32_C(2164833827), UINT32_C(2164833827), UINT32_C(2164833827), UINT32_C(2164833827),
      UINT32_C(2164833827), UINT32_C(2164833827), UINT32_C(2164833827), UINT32_C(2164833827), UINT32_C(2164833827), UINT32_C(2164833827), UINT32_C(2164833827), UINT32_C(2164833827),
      UINT32_C(2164833827), UINT32_C(2164833827), UINT32_C(2164833827), UINT32_C(2164833827), UINT32_C(2164833827), UINT32_C(2164833827), UINT32_C(2164833827), UINT32_C(2164833827),
      UINT32_C(2164833827), UINT32_C(2164833827), UINT32_C(2164833827), UINT32_C(2164833827), UINT32_C(2164833827), UINT32_C(2164833827), UINT32_C(2164833827), UINT32_C(2164833827),
      UINT32_C(2164833827), UINT32_C(2164833827), UINT32_C(2164833827), UINT32_C(2164833827), UINT32_C(2164833827), UINT32_C(2164833827), UINT32_C(2164833827) };

  static uint32_t r[sizeof(e) / sizeof(e[0])];
  static const int32_t len = HEDLEY_STATIC_CAST(int32_t, sizeof(e) / sizeof(e[0]));
  int32_t i = 0;
  simde_svbool_t pg = simde_svwhilelt_b32_s32(i, len);
  while (simde_svptest_first(simde_svptrue_b32(), pg)) {
    simde_svuint32_t rv;

    rv = simde_svdup_n_u32(a);

    simde_svst1_u32(pg, &(r[i]), rv);

    i += simde_svcntw();
    pg = simde_svwhilelt_b32_s32(i, len);
  }

  simde_assert_equal_vu32(len, e, r);

  return 0;
#else
  uint32_t a, e[1024 / sizeof(uint32_t)];
  int32_t len;

  fputc('\n', stdout);

  len = simde_test_codegen_random_u32() & ((sizeof(e) / sizeof(e[0])) - 1);
  a = simde_test_codegen_random_u32();

  int32_t i = 0;
  simde_svbool_t pg = simde_svwhilelt_b32_s32(i, len);
  while (simde_svptest_first(simde_svptrue_b32(), pg)) {
    simde_svuint32_t ev;

    ev = simde_svdup_n_u32(a);

    simde_svst1_u32(pg, &(e[i]), ev);

    i += simde_svcntw();
    pg = simde_svwhilelt_b32_s32(i, len);
  }

  simde_test_codegen_write_1u32(1, a);
  simde_test_codegen_write_1vu32(1, HEDLEY_STATIC_CAST(size_t, len), e);

  return 1;
#endif
}

static int
test_simde_svdup_n_u32_z (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const int32_t p[] =
    {  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),
       INT32_C(           0), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),
      -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),
      -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),
       INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),
       INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),
       INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),
       INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),
       INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),
       INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),
       INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),
       INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),
       INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0) };
  static const uint32_t a = UINT32_C(        99);
  static const uint32_t e[] =
    { UINT32_C(         0), UINT32_C(         0), UINT32_C(        99), UINT32_C(         0), UINT32_C(        99), UINT32_C(        99), UINT32_C(        99), UINT32_C(        99),
      UINT32_C(         0), UINT32_C(        99), UINT32_C(         0), UINT32_C(        99), UINT32_C(        99), UINT32_C(         0), UINT32_C(         0), UINT32_C(        99),
      UINT32_C(        99), UINT32_C(        99), UINT32_C(         0), UINT32_C(         0), UINT32_C(        99), UINT32_C(         0), UINT32_C(         0), UINT32_C(        99),
      UINT32_C(        99), UINT32_C(         0), UINT32_C(         0), UINT32_C(         0), UINT32_C(         0), UINT32_C(         0), UINT32_C(         0), UINT32_C(         0),
      UINT32_C(         0), UINT32_C(         0), UINT32_C(         0), UINT32_C(         0), UINT32_C(         0), UINT32_C(         0), UINT32_C(         0), UINT32_C(         0),
      UINT32_C(         0), UINT32_C(         0), UINT32_C(         0), UINT32_C(         0), UINT32_C(         0), UINT32_C(         0), UINT32_C(         0), UINT32_C(         0),
      UINT32_C(         0), UINT32_C(         0), UINT32_C(         0), UINT32_C(         0), UINT32_C(         0), UINT32_C(         0), UINT32_C(         0), UINT32_C(         0),
      UINT32_C(         0), UINT32_C(         0), UINT32_C(         0), UINT32_C(         0), UINT32_C(        99), UINT32_C(        99), UINT32_C(         0), UINT32_C(         0),
      UINT32_C(         0), UINT32_C(         0), UINT32_C(         0), UINT32_C(         0), UINT32_C(         0), UINT32_C(         0), UINT32_C(         0), UINT32_C(         0),
      UINT32_C(         0), UINT32_C(         0), UINT32_C(         0), UINT32_C(         0), UINT32_C(         0), UINT32_C(         0), UINT32_C(         0), UINT32_C(         0),
      UINT32_C(         0), UINT32_C(         0), UINT32_C(         0), UINT32_C(         0), UINT32_C(         0), UINT32_C(         0), UINT32_C(         0), UINT32_C(         0),
      UINT32_C(         0), UINT32_C(         0), UINT32_C(         0), UINT32_C(         0), UINT32_C(         0), UINT32_C(         0), UINT32_C(         0), UINT32_C(         0),
      UINT32_C(         0), UINT32_C(         0), UINT32_C(         0), UINT32_C(         0), UINT32_C(         0), UINT32_C(         0) };

  static uint32_t r[sizeof(e) / sizeof(e[0])];
  static const int32_t len = HEDLEY_STATIC_CAST(int32_t, sizeof(e) / sizeof(e[0]));
  int32_t i = 0;
  simde_svbool_t pg = simde_svwhilelt_b32_s32(i, len);
  while (simde_svptest_first(simde_svptrue_b32(), pg)) {
    simde_svuint32_t rv;
    simde_svbool_t pv;

    pv = simde_svcmplt_s32(pg, simde_svld1_s32(pg, &(p[i])), simde_svdup_n_s32(INT32_C(0)));
    rv = simde_svdup_n_u32_z(pv, a);

    simde_svst1_u32(pg, &(r[i]), rv);

    i += simde_svcntw();
    pg = simde_svwhilelt_b32_s32(i, len);
  }

  simde_assert_equal_vu32(len, e, r);

  return 0;
#else
  uint32_t a, e[1024 / sizeof(uint32_t)];
  int32_t p[1024 / sizeof(uint32_t)];
  int32_t len;

  fputc('\n', stdout);

  len = simde_test_codegen_random_u32() & ((sizeof(e) / sizeof(e[0])) - 1);
  simde_test_codegen_random_memory(sizeof(p), HEDLEY_REINTERPRET_CAST(uint8_t*, p));
  a = simde_test_codegen_random_u8();

  int32_t i = 0;
  simde_svbool_t pg = simde_svwhilelt_b32_s32(i, len);
  while (simde_svptest_first(simde_svptrue_b32(), pg)) {
    simde_svuint32_t ev;
    simde_svbool_t pv;

    pv = simde_svcmplt_s32(pg, simde_svld1_s32(pg, &(p[i])), simde_svdup_n_s32(0));
    ev = simde_svdup_n_u32_z(pv, a);

    simde_svst1_u32(pg, &(e[i]), ev);
    simde_svst1_s32(pg, &(p[i]), simde_svdup_n_s32_z(pv, ~INT32_C(0)));

    i += simde_svcntw();
    pg = simde_svwhilelt_b32_s32(i, len);
  }

  simde_test_codegen_write_1vi32(1, HEDLEY_STATIC_CAST(size_t, len), p);
  simde_test_codegen_write_1u32(1, a);
  simde_test_codegen_write_1vu32(1, HEDLEY_STATIC_CAST(size_t, len), e);

  return 1;
#endif
}

static int
test_simde_svdup_n_u32_m (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const int32_t p[] =
    { -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),
      -INT32_C(           1),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),
      -INT32_C(           1),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),
       INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),
       INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),
       INT32_C(           0), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),
      -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),
       INT32_C(           0), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),
      -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),
       INT32_C(           0),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),
      -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),
       INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),
      -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),
      -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),
       INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),
      -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),
      -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),
      -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),
      -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),
       INT32_C(           0), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),
      -INT32_C(           1),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),
       INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),
      -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),
      -INT32_C(           1), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1) };
  static const uint32_t a[] =
    { UINT32_C( 741867412), UINT32_C(3019275459), UINT32_C( 952162994), UINT32_C(2703319329), UINT32_C(2323731850), UINT32_C(1334294032), UINT32_C( 228726251), UINT32_C(1978035169),
      UINT32_C( 782310762), UINT32_C(1289852826), UINT32_C(2474943090), UINT32_C(2369037571), UINT32_C( 186103547), UINT32_C(1465556588), UINT32_C(2506423476), UINT32_C(3523955303),
      UINT32_C(  33598568), UINT32_C(3058622788), UINT32_C(2269762179), UINT32_C(1913945463), UINT32_C(2692557875), UINT32_C(2130171850), UINT32_C( 991190228), UINT32_C( 235741094),
      UINT32_C( 252710347), UINT32_C(1925537519), UINT32_C(2834894384), UINT32_C(3206155916), UINT32_C(  73373754), UINT32_C(1132681071), UINT32_C(1501534131), UINT32_C(2171112630),
      UINT32_C(2308012186), UINT32_C( 133912279), UINT32_C(4054840677), UINT32_C(1034996227), UINT32_C(3510702178), UINT32_C( 437634151), UINT32_C( 292787291), UINT32_C(3130252064),
      UINT32_C( 725820500), UINT32_C(3744612218), UINT32_C( 936436276), UINT32_C( 242516396), UINT32_C(4175410577), UINT32_C(3574789242), UINT32_C(2850522504), UINT32_C(3043195489),
      UINT32_C( 417376158), UINT32_C( 452465382), UINT32_C(2689714420), UINT32_C(3668886857), UINT32_C(4107439738), UINT32_C( 197846146), UINT32_C(3417616746), UINT32_C(3380614955),
      UINT32_C(2766233790), UINT32_C(1740560754), UINT32_C(3943108514), UINT32_C(1338422996), UINT32_C(3326318660), UINT32_C(3889237373), UINT32_C(3920790974), UINT32_C(1538405021),
      UINT32_C(  67146898), UINT32_C( 258719341), UINT32_C(2734388174), UINT32_C(1844560169), UINT32_C(3593680217), UINT32_C(  29164866), UINT32_C( 669675402), UINT32_C( 864263585),
      UINT32_C(2654503729), UINT32_C( 263103297), UINT32_C(1068673302), UINT32_C(3282871146), UINT32_C( 463134936), UINT32_C(1864128485), UINT32_C(1754728135), UINT32_C(3567000227),
      UINT32_C(3732133021), UINT32_C(2397970807), UINT32_C( 885891274), UINT32_C( 485980739), UINT32_C(1060606298), UINT32_C(2964214761), UINT32_C(4246226265), UINT32_C(4241601631),
      UINT32_C(  14369928), UINT32_C( 797886821), UINT32_C(2892192617), UINT32_C( 801659861), UINT32_C(3580821484), UINT32_C(2894404946), UINT32_C(3265896034), UINT32_C(3686693458),
      UINT32_C( 618371519), UINT32_C(3411306850), UINT32_C(2591602628), UINT32_C(4291379218), UINT32_C(2463381568), UINT32_C(3074316885), UINT32_C(1249503224), UINT32_C( 556087394),
      UINT32_C( 876937425), UINT32_C( 788502889), UINT32_C(1674082129), UINT32_C(4167209400), UINT32_C( 512374729), UINT32_C(2312554897), UINT32_C( 315838384), UINT32_C(1496578439),
      UINT32_C(1670216185), UINT32_C(1670482962), UINT32_C(3167181060), UINT32_C(3031706090), UINT32_C(4057087584), UINT32_C(3095046151), UINT32_C(2143964920), UINT32_C(1087962695),
      UINT32_C(2309186935), UINT32_C(4142740722), UINT32_C(2024977549), UINT32_C(1043097309), UINT32_C(2888826532), UINT32_C(2674174631), UINT32_C(1058942712), UINT32_C(2743072556),
      UINT32_C(1311581020), UINT32_C(3846445655), UINT32_C(2875061966), UINT32_C(  32082268), UINT32_C( 783096199), UINT32_C(3150778819), UINT32_C(1828383807), UINT32_C(1057978851),
      UINT32_C(4102962332), UINT32_C( 618254934), UINT32_C( 634402505), UINT32_C(1176943039), UINT32_C(2507527122), UINT32_C( 609239780), UINT32_C( 294668846), UINT32_C(1615962052),
      UINT32_C( 844423132), UINT32_C(2052533681), UINT32_C( 580921187), UINT32_C(3010053856), UINT32_C(2118704794), UINT32_C(1336056096), UINT32_C(2808099555), UINT32_C(2919805394),
      UINT32_C(1122000016), UINT32_C(3988535178), UINT32_C(1058036830), UINT32_C(3186784547), UINT32_C(2000370263), UINT32_C(3083263699), UINT32_C(3797821200), UINT32_C(1771071192),
      UINT32_C(1303081411), UINT32_C( 121268136), UINT32_C(3880143556), UINT32_C( 446970051), UINT32_C(1184030578), UINT32_C(3472709821), UINT32_C(1487952767), UINT32_C(2244035010),
      UINT32_C(1523739826), UINT32_C(2539719891), UINT32_C( 444507991), UINT32_C(1379214047), UINT32_C(3214460674), UINT32_C(2676856095), UINT32_C(3002547952), UINT32_C( 825735295),
      UINT32_C(4153084196), UINT32_C(1838148886), UINT32_C(1955007892), UINT32_C( 851885104), UINT32_C(2750504579), UINT32_C(3812786163), UINT32_C(1016478141), UINT32_C( 359517681),
      UINT32_C(3977050327), UINT32_C(2052758501), UINT32_C(3656311209), UINT32_C( 554415262) };
  static const uint32_t b = UINT32_C(3974678527);
  static const uint32_t e[] =
    { UINT32_C(3974678527), UINT32_C(3974678527), UINT32_C(3974678527), UINT32_C(3974678527), UINT32_C(3974678527), UINT32_C(3974678527), UINT32_C( 228726251), UINT32_C(1978035169),
      UINT32_C(3974678527), UINT32_C(1289852826), UINT32_C(3974678527), UINT32_C(3974678527), UINT32_C( 186103547), UINT32_C(3974678527), UINT32_C(2506423476), UINT32_C(3974678527),
      UINT32_C(3974678527), UINT32_C(3058622788), UINT32_C(2269762179), UINT32_C(3974678527), UINT32_C(3974678527), UINT32_C(2130171850), UINT32_C( 991190228), UINT32_C( 235741094),
      UINT32_C( 252710347), UINT32_C(3974678527), UINT32_C(2834894384), UINT32_C(3206155916), UINT32_C(3974678527), UINT32_C(1132681071), UINT32_C(1501534131), UINT32_C(3974678527),
      UINT32_C(2308012186), UINT32_C( 133912279), UINT32_C(4054840677), UINT32_C(1034996227), UINT32_C(3974678527), UINT32_C( 437634151), UINT32_C(3974678527), UINT32_C(3130252064),
      UINT32_C( 725820500), UINT32_C(3974678527), UINT32_C(3974678527), UINT32_C( 242516396), UINT32_C(4175410577), UINT32_C(3974678527), UINT32_C(2850522504), UINT32_C(3974678527),
      UINT32_C(3974678527), UINT32_C( 452465382), UINT32_C(3974678527), UINT32_C(3668886857), UINT32_C(4107439738), UINT32_C(3974678527), UINT32_C(3974678527), UINT32_C(3380614955),
      UINT32_C(2766233790), UINT32_C(3974678527), UINT32_C(3943108514), UINT32_C(3974678527), UINT32_C(3974678527), UINT32_C(3974678527), UINT32_C(3974678527), UINT32_C(1538405021),
      UINT32_C(3974678527), UINT32_C( 258719341), UINT32_C(2734388174), UINT32_C(1844560169), UINT32_C(3593680217), UINT32_C(  29164866), UINT32_C(3974678527), UINT32_C( 864263585),
      UINT32_C(2654503729), UINT32_C( 263103297), UINT32_C(3974678527), UINT32_C(3282871146), UINT32_C(3974678527), UINT32_C(3974678527), UINT32_C(1754728135), UINT32_C(3567000227),
      UINT32_C(3974678527), UINT32_C(3974678527), UINT32_C( 885891274), UINT32_C( 485980739), UINT32_C(1060606298), UINT32_C(3974678527), UINT32_C(3974678527), UINT32_C(3974678527),
      UINT32_C(  14369928), UINT32_C( 797886821), UINT32_C(2892192617), UINT32_C( 801659861), UINT32_C(3580821484), UINT32_C(3974678527), UINT32_C(3974678527), UINT32_C(3974678527),
      UINT32_C(3974678527), UINT32_C(3974678527), UINT32_C(3974678527), UINT32_C(4291379218), UINT32_C(2463381568), UINT32_C(3974678527), UINT32_C(3974678527), UINT32_C(3974678527),
      UINT32_C(3974678527), UINT32_C( 788502889), UINT32_C(3974678527), UINT32_C(4167209400), UINT32_C(3974678527), UINT32_C(3974678527), UINT32_C(3974678527), UINT32_C(3974678527),
      UINT32_C(1670216185), UINT32_C(3974678527), UINT32_C(3167181060), UINT32_C(3031706090), UINT32_C(3974678527), UINT32_C(3095046151), UINT32_C(2143964920), UINT32_C(1087962695),
      UINT32_C(3974678527), UINT32_C(4142740722), UINT32_C(3974678527), UINT32_C(1043097309), UINT32_C(3974678527), UINT32_C(2674174631), UINT32_C(1058942712), UINT32_C(2743072556),
      UINT32_C(3974678527), UINT32_C(3974678527), UINT32_C(2875061966), UINT32_C(  32082268), UINT32_C(3974678527), UINT32_C(3974678527), UINT32_C(1828383807), UINT32_C(1057978851),
      UINT32_C(3974678527), UINT32_C( 618254934), UINT32_C( 634402505), UINT32_C(1176943039), UINT32_C(2507527122), UINT32_C(3974678527), UINT32_C(3974678527), UINT32_C(1615962052),
      UINT32_C(3974678527), UINT32_C(3974678527), UINT32_C(3974678527), UINT32_C(3010053856), UINT32_C(2118704794), UINT32_C(1336056096), UINT32_C(3974678527), UINT32_C(3974678527),
      UINT32_C(1122000016), UINT32_C(3974678527), UINT32_C(1058036830), UINT32_C(3974678527), UINT32_C(2000370263), UINT32_C(3974678527), UINT32_C(3797821200), UINT32_C(1771071192),
      UINT32_C(3974678527), UINT32_C( 121268136), UINT32_C(3974678527), UINT32_C(3974678527), UINT32_C(1184030578), UINT32_C(3472709821), UINT32_C(3974678527), UINT32_C(3974678527),
      UINT32_C(1523739826), UINT32_C(2539719891), UINT32_C(3974678527), UINT32_C(3974678527), UINT32_C(3214460674), UINT32_C(2676856095), UINT32_C(3974678527), UINT32_C(3974678527),
      UINT32_C(3974678527), UINT32_C(1838148886), UINT32_C(3974678527), UINT32_C( 851885104), UINT32_C(2750504579), UINT32_C(3974678527), UINT32_C(1016478141), UINT32_C(3974678527),
      UINT32_C(3974678527), UINT32_C(3974678527), UINT32_C(3656311209), UINT32_C(3974678527) };

  static uint32_t r[sizeof(e) / sizeof(e[0])];
  static const int32_t len = HEDLEY_STATIC_CAST(int32_t, sizeof(e) / sizeof(e[0]));
  int32_t i = 0;
  simde_svbool_t pg = simde_svwhilelt_b32_s32(i, len);
  while (simde_svptest_first(simde_svptrue_b32(), pg)) {
    simde_svuint32_t
      rv,
      av = simde_svld1_u32(pg, &(a[i]));
    simde_svbool_t pv;

    pv = simde_svcmplt_s32(pg, simde_svld1_s32(pg, &(p[i])), simde_svdup_n_s32(INT32_C(0)));
    rv = simde_svdup_n_u32_m(av, pv, b);

    simde_svst1_u32(pg, &(r[i]), rv);

    i += simde_svcntw();
    pg = simde_svwhilelt_b32_s32(i, len);
  }

  simde_assert_equal_vu32(len, e, r);

  return 0;
#else
  int32_t p[1024 / sizeof(uint32_t)];
  uint32_t a[1024 / sizeof(uint32_t)], b, e[1024 / sizeof(uint32_t)];
  int32_t len = simde_test_arm_sve_random_length(sizeof(e), sizeof(e[0]));

  fputc('\n', stdout);

  simde_test_codegen_random_memory(sizeof(p), HEDLEY_REINTERPRET_CAST(uint8_t*, p));
  simde_test_codegen_random_memory(sizeof(a), HEDLEY_REINTERPRET_CAST(uint8_t*, a));
  b = simde_test_codegen_random_u32();

  int32_t i = 0;
  simde_svbool_t pg = simde_svwhilelt_b32_s32(i, len);
  while (simde_svptest_first(simde_svptrue_b32(), pg)) {
    simde_svuint32_t av, ev;
    simde_svbool_t pv;

    pv = simde_svcmplt_s32(pg, simde_svld1_s32(pg, &(p[i])), simde_svdup_n_s32(0));
    av = simde_svld1_u32(pg, &(a[i]));

    ev = simde_svdup_n_u32_m(av, pv, b);

    simde_svst1_u32(pg, &(e[i]), ev);
    simde_svst1_s32(pg, &(p[i]), simde_svdup_n_s32_z(pv, ~INT64_C(0)));

    i += simde_svcntw();
    pg = simde_svwhilelt_b32_s32(i, len);
  }

  simde_test_codegen_write_1vi32(1, HEDLEY_STATIC_CAST(size_t, len), p);
  simde_test_codegen_write_1vu32(1, HEDLEY_STATIC_CAST(size_t, len), a);
  simde_test_codegen_write_1u32(1, b);
  simde_test_codegen_write_1vu32(1, HEDLEY_STATIC_CAST(size_t, len), e);

  return 1;
#endif
}

static int
test_simde_svdup_n_u64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const uint64_t a = UINT64_C(11134186708511297224);
  static const uint64_t e[] =
    { UINT64_C(11134186708511297224), UINT64_C(11134186708511297224), UINT64_C(11134186708511297224), UINT64_C(11134186708511297224),
      UINT64_C(11134186708511297224), UINT64_C(11134186708511297224), UINT64_C(11134186708511297224), UINT64_C(11134186708511297224),
      UINT64_C(11134186708511297224), UINT64_C(11134186708511297224), UINT64_C(11134186708511297224), UINT64_C(11134186708511297224),
      UINT64_C(11134186708511297224), UINT64_C(11134186708511297224), UINT64_C(11134186708511297224), UINT64_C(11134186708511297224),
      UINT64_C(11134186708511297224), UINT64_C(11134186708511297224), UINT64_C(11134186708511297224), UINT64_C(11134186708511297224),
      UINT64_C(11134186708511297224) };

  static uint64_t r[sizeof(e) / sizeof(e[0])];
  static const int64_t len = HEDLEY_STATIC_CAST(int64_t, sizeof(e) / sizeof(e[0]));
  int32_t i = 0;
  simde_svbool_t pg = simde_svwhilelt_b64_s32(i, len);
  while (simde_svptest_first(simde_svptrue_b64(), pg)) {
    simde_svuint64_t rv;

    rv = simde_svdup_n_u64(a);

    simde_svst1_u64(pg, &(r[i]), rv);

    i += simde_svcntd();
    pg = simde_svwhilelt_b64_s32(i, len);
  }

  simde_assert_equal_vu64(len, e, r);

  return 0;
#else
  uint64_t a, e[1024 / sizeof(uint64_t)];
  int64_t len;

  fputc('\n', stdout);

  len = simde_test_codegen_random_u64() & ((sizeof(e) / sizeof(e[0])) - 1);
  a = simde_test_codegen_random_u64();

  int64_t i = 0;
  simde_svbool_t pg = simde_svwhilelt_b64_s32(i, len);
  while (simde_svptest_first(simde_svptrue_b64(), pg)) {
    simde_svuint64_t ev;

    ev = simde_svdup_n_u64(a);

    simde_svst1_u64(pg, &(e[i]), ev);

    i += simde_svcntd();
    pg = simde_svwhilelt_b64_s32(i, len);
  }

  simde_test_codegen_write_1u64(1, a);
  simde_test_codegen_write_1vu64(1, HEDLEY_STATIC_CAST(size_t, len), e);

  return 1;
#endif
}

static int
test_simde_svdup_n_u64_z (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const int64_t p[] =
    {  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),
       INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0), -INT64_C(                   1),
      -INT64_C(                   1),  INT64_C(                   0), -INT64_C(                   1),  INT64_C(                   0),
      -INT64_C(                   1),  INT64_C(                   0), -INT64_C(                   1), -INT64_C(                   1),
       INT64_C(                   0), -INT64_C(                   1),  INT64_C(                   0),  INT64_C(                   0),
      -INT64_C(                   1), -INT64_C(                   1),  INT64_C(                   0), -INT64_C(                   1),
      -INT64_C(                   1),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),
      -INT64_C(                   1), -INT64_C(                   1),  INT64_C(                   0), -INT64_C(                   1),
      -INT64_C(                   1), -INT64_C(                   1), -INT64_C(                   1),  INT64_C(                   0),
      -INT64_C(                   1),  INT64_C(                   0),  INT64_C(                   0), -INT64_C(                   1),
       INT64_C(                   0),  INT64_C(                   0), -INT64_C(                   1), -INT64_C(                   1),
      -INT64_C(                   1),  INT64_C(                   0), -INT64_C(                   1), -INT64_C(                   1),
      -INT64_C(                   1),  INT64_C(                   0),  INT64_C(                   0), -INT64_C(                   1),
      -INT64_C(                   1),  INT64_C(                   0), -INT64_C(                   1),  INT64_C(                   0),
      -INT64_C(                   1),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),
      -INT64_C(                   1),  INT64_C(                   0), -INT64_C(                   1), -INT64_C(                   1),
       INT64_C(                   0), -INT64_C(                   1),  INT64_C(                   0),  INT64_C(                   0),
       INT64_C(                   0) };
  static const uint64_t a = UINT64_C(14169136510567434236);
  static const uint64_t e[] =
    { UINT64_C(                   0), UINT64_C(                   0), UINT64_C(                   0), UINT64_C(                   0),
      UINT64_C(                   0), UINT64_C(                   0), UINT64_C(                   0), UINT64_C(14169136510567434236),
      UINT64_C(14169136510567434236), UINT64_C(                   0), UINT64_C(14169136510567434236), UINT64_C(                   0),
      UINT64_C(14169136510567434236), UINT64_C(                   0), UINT64_C(14169136510567434236), UINT64_C(14169136510567434236),
      UINT64_C(                   0), UINT64_C(14169136510567434236), UINT64_C(                   0), UINT64_C(                   0),
      UINT64_C(14169136510567434236), UINT64_C(14169136510567434236), UINT64_C(                   0), UINT64_C(14169136510567434236),
      UINT64_C(14169136510567434236), UINT64_C(                   0), UINT64_C(                   0), UINT64_C(                   0),
      UINT64_C(14169136510567434236), UINT64_C(14169136510567434236), UINT64_C(                   0), UINT64_C(14169136510567434236),
      UINT64_C(14169136510567434236), UINT64_C(14169136510567434236), UINT64_C(14169136510567434236), UINT64_C(                   0),
      UINT64_C(14169136510567434236), UINT64_C(                   0), UINT64_C(                   0), UINT64_C(14169136510567434236),
      UINT64_C(                   0), UINT64_C(                   0), UINT64_C(14169136510567434236), UINT64_C(14169136510567434236),
      UINT64_C(14169136510567434236), UINT64_C(                   0), UINT64_C(14169136510567434236), UINT64_C(14169136510567434236),
      UINT64_C(14169136510567434236), UINT64_C(                   0), UINT64_C(                   0), UINT64_C(14169136510567434236),
      UINT64_C(14169136510567434236), UINT64_C(                   0), UINT64_C(14169136510567434236), UINT64_C(                   0),
      UINT64_C(14169136510567434236), UINT64_C(                   0), UINT64_C(                   0), UINT64_C(                   0),
      UINT64_C(14169136510567434236), UINT64_C(                   0), UINT64_C(14169136510567434236), UINT64_C(14169136510567434236),
      UINT64_C(                   0), UINT64_C(14169136510567434236), UINT64_C(                   0), UINT64_C(                   0),
      UINT64_C(                   0) };

  static uint64_t r[sizeof(e) / sizeof(e[0])];
  static const int64_t len = HEDLEY_STATIC_CAST(int64_t, sizeof(e) / sizeof(e[0]));
  int32_t i = 0;
  simde_svbool_t pg = simde_svwhilelt_b64_s32(i, len);
  while (simde_svptest_first(simde_svptrue_b64(), pg)) {
    simde_svuint64_t rv;
    simde_svbool_t pv;

    pv = simde_svcmplt_s64(pg, simde_svld1_s64(pg, &(p[i])), simde_svdup_n_s64(INT64_C(0)));
    rv = simde_svdup_n_u64_z(pv, a);

    simde_svst1_u64(pg, &(r[i]), rv);

    i += simde_svcntd();
    pg = simde_svwhilelt_b64_s32(i, len);
  }

  simde_assert_equal_vu64(len, e, r);

  return 0;
#else
  int64_t p[1024 / sizeof(int64_t)];
  uint64_t a, e[1024 / sizeof(uint64_t)];
  int32_t len;

  fputc('\n', stdout);

  len = simde_test_codegen_random_i32() & ((sizeof(e) / sizeof(e[0])) - 1);
  simde_test_codegen_random_memory(sizeof(p), HEDLEY_REINTERPRET_CAST(uint8_t*, p));
  a = simde_test_codegen_random_i64();

  int64_t i = 0;
  simde_svbool_t pg = simde_svwhilelt_b64_s32(i, len);
  while (simde_svptest_first(simde_svptrue_b64(), pg)) {
    simde_svuint64_t ev;
    simde_svbool_t pv;

    pv = simde_svcmplt_s64(pg, simde_svld1_s64(pg, &(p[i])), simde_svdup_n_s64(0));
    ev = simde_svdup_n_u64_z(pv, a);

    simde_svst1_u64(pg, &(e[i]), ev);
    simde_svst1_s64(pg, &(p[i]), simde_svdup_n_s64_z(pv, ~INT64_C(0)));

    i += simde_svcntd();
    pg = simde_svwhilelt_b64_s32(i, len);
  }

  simde_test_codegen_write_1vi64(1, HEDLEY_STATIC_CAST(size_t, len), p);
  simde_test_codegen_write_1u64(1, a);
  simde_test_codegen_write_1vu64(1, HEDLEY_STATIC_CAST(size_t, len), e);

  return 1;
#endif
}

static int
test_simde_svdup_n_u64_m (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const int64_t p[] =
    {  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),
       INT64_C(                   0), -INT64_C(                   1), -INT64_C(                   1), -INT64_C(                   1),
      -INT64_C(                   1), -INT64_C(                   1),  INT64_C(                   0),  INT64_C(                   0),
       INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0), -INT64_C(                   1),
      -INT64_C(                   1), -INT64_C(                   1), -INT64_C(                   1), -INT64_C(                   1),
      -INT64_C(                   1),  INT64_C(                   0),  INT64_C(                   0), -INT64_C(                   1),
      -INT64_C(                   1), -INT64_C(                   1), -INT64_C(                   1), -INT64_C(                   1),
      -INT64_C(                   1), -INT64_C(                   1), -INT64_C(                   1), -INT64_C(                   1),
      -INT64_C(                   1),  INT64_C(                   0), -INT64_C(                   1),  INT64_C(                   0),
      -INT64_C(                   1),  INT64_C(                   0),  INT64_C(                   0), -INT64_C(                   1),
      -INT64_C(                   1), -INT64_C(                   1), -INT64_C(                   1), -INT64_C(                   1),
       INT64_C(                   0),  INT64_C(                   0), -INT64_C(                   1),  INT64_C(                   0),
      -INT64_C(                   1), -INT64_C(                   1),  INT64_C(                   0),  INT64_C(                   0),
       INT64_C(                   0), -INT64_C(                   1),  INT64_C(                   0), -INT64_C(                   1),
       INT64_C(                   0), -INT64_C(                   1), -INT64_C(                   1), -INT64_C(                   1),
      -INT64_C(                   1),  INT64_C(                   0),  INT64_C(                   0), -INT64_C(                   1),
      -INT64_C(                   1), -INT64_C(                   1), -INT64_C(                   1), -INT64_C(                   1),
       INT64_C(                   0), -INT64_C(                   1), -INT64_C(                   1), -INT64_C(                   1),
      -INT64_C(                   1),  INT64_C(                   0), -INT64_C(                   1),  INT64_C(                   0),
       INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0), -INT64_C(                   1),
      -INT64_C(                   1), -INT64_C(                   1),  INT64_C(                   0), -INT64_C(                   1),
      -INT64_C(                   1), -INT64_C(                   1),  INT64_C(                   0),  INT64_C(                   0),
      -INT64_C(                   1), -INT64_C(                   1), -INT64_C(                   1), -INT64_C(                   1),
      -INT64_C(                   1),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),
       INT64_C(                   0), -INT64_C(                   1), -INT64_C(                   1),  INT64_C(                   0),
      -INT64_C(                   1),  INT64_C(                   0),  INT64_C(                   0), -INT64_C(                   1),
       INT64_C(                   0),  INT64_C(                   0), -INT64_C(                   1), -INT64_C(                   1),
      -INT64_C(                   1), -INT64_C(                   1),  INT64_C(                   0), -INT64_C(                   1),
      -INT64_C(                   1), -INT64_C(                   1),  INT64_C(                   0), -INT64_C(                   1),
       INT64_C(                   0),  INT64_C(                   0), -INT64_C(                   1),  INT64_C(                   0),
       INT64_C(                   0), -INT64_C(                   1) };
  static const uint64_t a[] =
    { UINT64_C( 5939440719379939651), UINT64_C( 3838579179947245875), UINT64_C( 1963403387956120717), UINT64_C( 5016343690547539088),
      UINT64_C( 1410565529963904867), UINT64_C( 8518988505504909975), UINT64_C( 2227108694385436115), UINT64_C( 5276810177035650035),
      UINT64_C( 1130435910346351293), UINT64_C( 5406656532883698088), UINT64_C( 5268648983438823282), UINT64_C( 4211561080503041860),
      UINT64_C(13988891938638003355), UINT64_C(17670818180854134136), UINT64_C(10955872872772752235), UINT64_C( 6722243401913289107),
      UINT64_C( 2309381960435245360), UINT64_C( 2756005864259281095), UINT64_C(15820287085717763232), UINT64_C(12851924794075729212),
      UINT64_C( 2674867002995952470), UINT64_C( 2038915104525725801), UINT64_C( 7063504753322374114), UINT64_C( 9087626500594856682),
      UINT64_C(10091048493553293960), UINT64_C(  748999584192166347), UINT64_C(18138030969871234350), UINT64_C( 6688835919076071469),
      UINT64_C(13136240263552978846), UINT64_C( 2951938005855567558), UINT64_C(10801095807004847320), UINT64_C( 8033504536925195339),
      UINT64_C(15109152389748276749), UINT64_C(16761753569954016636), UINT64_C(11088062725670116066), UINT64_C(10755217721898158594),
      UINT64_C( 7840832857517683444), UINT64_C( 2873436496472477416), UINT64_C( 7746280870078689945), UINT64_C( 7077829502079744284),
      UINT64_C(16883767412214843122), UINT64_C( 5344580547863785920), UINT64_C(  741037778173795701), UINT64_C(17995230750549378794),
      UINT64_C( 1051919604925603245), UINT64_C(12923147566984690525), UINT64_C( 2798100119328754395), UINT64_C( 1756186608358359904),
      UINT64_C(14174059925537766231), UINT64_C(16270707234467661787), UINT64_C(10959087725296967348), UINT64_C( 2847786584378348803),
      UINT64_C( 9855144460341300377), UINT64_C( 8444372177375106633), UINT64_C( 6890080115097984206), UINT64_C(10666585479917116432),
      UINT64_C(11444589300953699486), UINT64_C(12836981755435906543), UINT64_C( 1708366223176666106), UINT64_C( 8251156178503434739),
      UINT64_C( 6829304692053186258), UINT64_C(14743718460073686021), UINT64_C(11448105910579385536), UINT64_C(12078106459880805976),
      UINT64_C(17361542502037805859), UINT64_C(17719541600572014410), UINT64_C( 4112802277364599498), UINT64_C(14910859450442423922),
      UINT64_C(11401233354115300958), UINT64_C( 5943241365511607120), UINT64_C( 4955889037824439980), UINT64_C(10300710016109980793),
      UINT64_C(17665670411755934519), UINT64_C( 3602867081881248548), UINT64_C( 1891658774272198186), UINT64_C( 8966158084325952433),
      UINT64_C( 8871582566386779781), UINT64_C(13244002989513349141), UINT64_C(13882614199025371885), UINT64_C(11349369131781711551),
      UINT64_C(14927152079868168533), UINT64_C( 7116028762535907197), UINT64_C( 2923003734112892096), UINT64_C(10823466301698879871),
      UINT64_C( 6755516951113759286), UINT64_C( 2418758868451928761), UINT64_C(11037620210523800220), UINT64_C( 4434466768424032691),
      UINT64_C(17409771809371245919), UINT64_C(14383285730445099545), UINT64_C(13900634085430955060), UINT64_C(15895243217435891794),
      UINT64_C(14859264905908503820), UINT64_C( 4371556015628900024), UINT64_C(13924412545567520367), UINT64_C( 4459885450367857035),
      UINT64_C( 7924848483075489655), UINT64_C(10688161377875411470), UINT64_C(15898073173624675952), UINT64_C(16549824206840642623),
      UINT64_C(17576155051017187016), UINT64_C(11963351948579191629), UINT64_C(11774704538567972667), UINT64_C(16084253226065677795),
      UINT64_C(11657084210360699117), UINT64_C( 7521040161389662339), UINT64_C(17309968955707024945), UINT64_C(17987789279065099434),
      UINT64_C(14534402727109000895), UINT64_C( 1367374519815358307), UINT64_C(17710090296226278857), UINT64_C( 4481459303839303469),
      UINT64_C(17538430442503535957), UINT64_C(10718704327389866188), UINT64_C( 8550418460657215594), UINT64_C( 1005394221465559095),
      UINT64_C( 1612584750615643358), UINT64_C(14651481043123889397), UINT64_C( 2714872253467573997), UINT64_C( 1895397776374324361),
      UINT64_C(17974685263435724307), UINT64_C(12176060739671897806) };
  static const uint64_t b = UINT64_C(14316700374494852992);
  static const uint64_t e[] =
    { UINT64_C( 5939440719379939651), UINT64_C( 3838579179947245875), UINT64_C( 1963403387956120717), UINT64_C( 5016343690547539088),
      UINT64_C( 1410565529963904867), UINT64_C(14316700374494852992), UINT64_C(14316700374494852992), UINT64_C(14316700374494852992),
      UINT64_C(14316700374494852992), UINT64_C(14316700374494852992), UINT64_C( 5268648983438823282), UINT64_C( 4211561080503041860),
      UINT64_C(13988891938638003355), UINT64_C(17670818180854134136), UINT64_C(10955872872772752235), UINT64_C(14316700374494852992),
      UINT64_C(14316700374494852992), UINT64_C(14316700374494852992), UINT64_C(14316700374494852992), UINT64_C(14316700374494852992),
      UINT64_C(14316700374494852992), UINT64_C( 2038915104525725801), UINT64_C( 7063504753322374114), UINT64_C(14316700374494852992),
      UINT64_C(14316700374494852992), UINT64_C(14316700374494852992), UINT64_C(14316700374494852992), UINT64_C(14316700374494852992),
      UINT64_C(14316700374494852992), UINT64_C(14316700374494852992), UINT64_C(14316700374494852992), UINT64_C(14316700374494852992),
      UINT64_C(14316700374494852992), UINT64_C(16761753569954016636), UINT64_C(14316700374494852992), UINT64_C(10755217721898158594),
      UINT64_C(14316700374494852992), UINT64_C( 2873436496472477416), UINT64_C( 7746280870078689945), UINT64_C(14316700374494852992),
      UINT64_C(14316700374494852992), UINT64_C(14316700374494852992), UINT64_C(14316700374494852992), UINT64_C(14316700374494852992),
      UINT64_C( 1051919604925603245), UINT64_C(12923147566984690525), UINT64_C(14316700374494852992), UINT64_C( 1756186608358359904),
      UINT64_C(14316700374494852992), UINT64_C(14316700374494852992), UINT64_C(10959087725296967348), UINT64_C( 2847786584378348803),
      UINT64_C( 9855144460341300377), UINT64_C(14316700374494852992), UINT64_C( 6890080115097984206), UINT64_C(14316700374494852992),
      UINT64_C(11444589300953699486), UINT64_C(14316700374494852992), UINT64_C(14316700374494852992), UINT64_C(14316700374494852992),
      UINT64_C(14316700374494852992), UINT64_C(14743718460073686021), UINT64_C(11448105910579385536), UINT64_C(14316700374494852992),
      UINT64_C(14316700374494852992), UINT64_C(14316700374494852992), UINT64_C(14316700374494852992), UINT64_C(14316700374494852992),
      UINT64_C(11401233354115300958), UINT64_C(14316700374494852992), UINT64_C(14316700374494852992), UINT64_C(14316700374494852992),
      UINT64_C(14316700374494852992), UINT64_C( 3602867081881248548), UINT64_C(14316700374494852992), UINT64_C( 8966158084325952433),
      UINT64_C( 8871582566386779781), UINT64_C(13244002989513349141), UINT64_C(13882614199025371885), UINT64_C(14316700374494852992),
      UINT64_C(14316700374494852992), UINT64_C(14316700374494852992), UINT64_C( 2923003734112892096), UINT64_C(14316700374494852992),
      UINT64_C(14316700374494852992), UINT64_C(14316700374494852992), UINT64_C(11037620210523800220), UINT64_C( 4434466768424032691),
      UINT64_C(14316700374494852992), UINT64_C(14316700374494852992), UINT64_C(14316700374494852992), UINT64_C(14316700374494852992),
      UINT64_C(14316700374494852992), UINT64_C( 4371556015628900024), UINT64_C(13924412545567520367), UINT64_C( 4459885450367857035),
      UINT64_C( 7924848483075489655), UINT64_C(14316700374494852992), UINT64_C(14316700374494852992), UINT64_C(16549824206840642623),
      UINT64_C(14316700374494852992), UINT64_C(11963351948579191629), UINT64_C(11774704538567972667), UINT64_C(14316700374494852992),
      UINT64_C(11657084210360699117), UINT64_C( 7521040161389662339), UINT64_C(14316700374494852992), UINT64_C(14316700374494852992),
      UINT64_C(14316700374494852992), UINT64_C(14316700374494852992), UINT64_C(17710090296226278857), UINT64_C(14316700374494852992),
      UINT64_C(14316700374494852992), UINT64_C(14316700374494852992), UINT64_C( 8550418460657215594), UINT64_C(14316700374494852992),
      UINT64_C( 1612584750615643358), UINT64_C(14651481043123889397), UINT64_C(14316700374494852992), UINT64_C( 1895397776374324361),
      UINT64_C(17974685263435724307), UINT64_C(14316700374494852992) };

  static uint64_t r[sizeof(e) / sizeof(e[0])];
  static const int32_t len = HEDLEY_STATIC_CAST(int32_t, sizeof(e) / sizeof(e[0]));
  int32_t i = 0;
  simde_svbool_t pg = simde_svwhilelt_b64_s32(i, len);
  while (simde_svptest_first(simde_svptrue_b64(), pg)) {
    simde_svuint64_t
      rv,
      av = simde_svld1_u64(pg, &(a[i]));
    simde_svbool_t pv;

    pv = simde_svcmplt_s64(pg, simde_svld1_s64(pg, &(p[i])), simde_svdup_n_s64(INT64_C(0)));
    rv = simde_svdup_n_u64_m(av, pv, b);

    simde_svst1_u64(pg, &(r[i]), rv);

    i += simde_svcntd();
    pg = simde_svwhilelt_b64_s32(i, len);
  }

  simde_assert_equal_vu64(len, e, r);

  return 0;
#else
  int64_t p[1024 / sizeof(uint64_t)];
  uint64_t a[1024 / sizeof(uint64_t)], b, e[1024 / sizeof(uint64_t)];
  int32_t len = simde_test_arm_sve_random_length(sizeof(e), sizeof(e[0]));

  fputc('\n', stdout);

  simde_test_codegen_random_memory(sizeof(p), HEDLEY_REINTERPRET_CAST(uint8_t*, p));
  simde_test_codegen_random_memory(sizeof(a), HEDLEY_REINTERPRET_CAST(uint8_t*, a));
  b = simde_test_codegen_random_u64();

  int32_t i = 0;
  simde_svbool_t pg = simde_svwhilelt_b64_s32(i, len);
  while (simde_svptest_first(simde_svptrue_b64(), pg)) {
    simde_svuint64_t av, ev;
    simde_svbool_t pv;

    pv = simde_svcmplt_s64(pg, simde_svld1_s64(pg, &(p[i])), simde_svdup_n_s64(0));
    av = simde_svld1_u64(pg, &(a[i]));

    ev = simde_svdup_n_u64_m(av, pv, b);

    simde_svst1_u64(pg, &(e[i]), ev);
    simde_svst1_s64(pg, &(p[i]), simde_svdup_n_s64_z(pv, ~INT64_C(0)));

    i += simde_svcntd();
    pg = simde_svwhilelt_b64_s32(i, len);
  }

  simde_test_codegen_write_1vi64(1, HEDLEY_STATIC_CAST(size_t, len), p);
  simde_test_codegen_write_1vu64(1, HEDLEY_STATIC_CAST(size_t, len), a);
  simde_test_codegen_write_1u64(1, b);
  simde_test_codegen_write_1vu64(1, HEDLEY_STATIC_CAST(size_t, len), e);

  return 1;
#endif
}

static int
test_simde_svdup_n_f32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const simde_float32 a = SIMDE_FLOAT32_C(  -509.41);
  static const simde_float32 e[] =
    { SIMDE_FLOAT32_C(  -509.41), SIMDE_FLOAT32_C(  -509.41), SIMDE_FLOAT32_C(  -509.41), SIMDE_FLOAT32_C(  -509.41),
      SIMDE_FLOAT32_C(  -509.41), SIMDE_FLOAT32_C(  -509.41), SIMDE_FLOAT32_C(  -509.41), SIMDE_FLOAT32_C(  -509.41),
      SIMDE_FLOAT32_C(  -509.41), SIMDE_FLOAT32_C(  -509.41), SIMDE_FLOAT32_C(  -509.41), SIMDE_FLOAT32_C(  -509.41),
      SIMDE_FLOAT32_C(  -509.41), SIMDE_FLOAT32_C(  -509.41), SIMDE_FLOAT32_C(  -509.41), SIMDE_FLOAT32_C(  -509.41),
      SIMDE_FLOAT32_C(  -509.41), SIMDE_FLOAT32_C(  -509.41), SIMDE_FLOAT32_C(  -509.41), SIMDE_FLOAT32_C(  -509.41),
      SIMDE_FLOAT32_C(  -509.41), SIMDE_FLOAT32_C(  -509.41), SIMDE_FLOAT32_C(  -509.41), SIMDE_FLOAT32_C(  -509.41),
      SIMDE_FLOAT32_C(  -509.41), SIMDE_FLOAT32_C(  -509.41), SIMDE_FLOAT32_C(  -509.41), SIMDE_FLOAT32_C(  -509.41),
      SIMDE_FLOAT32_C(  -509.41), SIMDE_FLOAT32_C(  -509.41), SIMDE_FLOAT32_C(  -509.41), SIMDE_FLOAT32_C(  -509.41),
      SIMDE_FLOAT32_C(  -509.41), SIMDE_FLOAT32_C(  -509.41), SIMDE_FLOAT32_C(  -509.41), SIMDE_FLOAT32_C(  -509.41),
      SIMDE_FLOAT32_C(  -509.41), SIMDE_FLOAT32_C(  -509.41), SIMDE_FLOAT32_C(  -509.41), SIMDE_FLOAT32_C(  -509.41),
      SIMDE_FLOAT32_C(  -509.41), SIMDE_FLOAT32_C(  -509.41), SIMDE_FLOAT32_C(  -509.41), SIMDE_FLOAT32_C(  -509.41),
      SIMDE_FLOAT32_C(  -509.41), SIMDE_FLOAT32_C(  -509.41), SIMDE_FLOAT32_C(  -509.41), SIMDE_FLOAT32_C(  -509.41),
      SIMDE_FLOAT32_C(  -509.41), SIMDE_FLOAT32_C(  -509.41), SIMDE_FLOAT32_C(  -509.41), SIMDE_FLOAT32_C(  -509.41),
      SIMDE_FLOAT32_C(  -509.41), SIMDE_FLOAT32_C(  -509.41), SIMDE_FLOAT32_C(  -509.41), SIMDE_FLOAT32_C(  -509.41),
      SIMDE_FLOAT32_C(  -509.41), SIMDE_FLOAT32_C(  -509.41), SIMDE_FLOAT32_C(  -509.41), SIMDE_FLOAT32_C(  -509.41),
      SIMDE_FLOAT32_C(  -509.41), SIMDE_FLOAT32_C(  -509.41), SIMDE_FLOAT32_C(  -509.41), SIMDE_FLOAT32_C(  -509.41),
      SIMDE_FLOAT32_C(  -509.41), SIMDE_FLOAT32_C(  -509.41), SIMDE_FLOAT32_C(  -509.41), SIMDE_FLOAT32_C(  -509.41),
      SIMDE_FLOAT32_C(  -509.41), SIMDE_FLOAT32_C(  -509.41), SIMDE_FLOAT32_C(  -509.41), SIMDE_FLOAT32_C(  -509.41),
      SIMDE_FLOAT32_C(  -509.41), SIMDE_FLOAT32_C(  -509.41), SIMDE_FLOAT32_C(  -509.41), SIMDE_FLOAT32_C(  -509.41),
      SIMDE_FLOAT32_C(  -509.41), SIMDE_FLOAT32_C(  -509.41) };

  static simde_float32 r[sizeof(e) / sizeof(e[0])];
  static const int32_t len = HEDLEY_STATIC_CAST(int32_t, sizeof(e) / sizeof(e[0]));
  int32_t i = 0;
  simde_svbool_t pg = simde_svwhilelt_b32_s32(i, len);
  while (simde_svptest_first(simde_svptrue_b32(), pg)) {
    simde_svfloat32_t rv;

    rv = simde_svdup_n_f32(a);

    simde_svst1_f32(pg, &(r[i]), rv);

    i += simde_svcntw();
    pg = simde_svwhilelt_b32_s32(i, len);
  }

  simde_assert_equal_vf32(len, e, r, 1);

  return 0;
#else
  simde_float32 a, e[1024 / sizeof(int32_t)];
  int32_t len;

  fputc('\n', stdout);

  len = simde_test_codegen_random_i32() & ((sizeof(e) / sizeof(e[0])) - 1);
  a = simde_test_codegen_random_f32(SIMDE_FLOAT32_C(-1000.0), SIMDE_FLOAT32_C(1000.0));

  int32_t i = 0;
  simde_svbool_t pg = simde_svwhilelt_b32_s32(i, len);
  while (simde_svptest_first(simde_svptrue_b32(), pg)) {
    simde_svfloat32_t ev;

    ev = simde_svdup_n_f32(a);

    simde_svst1_f32(pg, &(e[i]), ev);

    i += simde_svcntw();
    pg = simde_svwhilelt_b32_s32(i, len);
  }

  simde_test_codegen_write_1f32(1, a);
  simde_test_codegen_write_1vf32(1, HEDLEY_STATIC_CAST(size_t, len), e);

  return 1;
#endif
}

static int
test_simde_svdup_n_f32_z (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const int32_t p[] =
    { -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),
      -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),
       INT32_C(           0), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),
      -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),
      -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),
      -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),
      -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),
      -INT32_C(           1),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),
      -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),
      -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),
       INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),
      -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),
      -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),
      -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),
      -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),
      -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),
      -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),
      -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),
      -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),
      -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),
      -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),
      -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),
      -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),
      -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),
      -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),
      -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),
      -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),
      -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),
      -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),
      -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),
      -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),
      -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1) };
  static const simde_float32 a = SIMDE_FLOAT32_C(  -105.00);
  static const simde_float32 e[] =
    { SIMDE_FLOAT32_C(  -105.00), SIMDE_FLOAT32_C(  -105.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
      SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -105.00), SIMDE_FLOAT32_C(  -105.00), SIMDE_FLOAT32_C(     0.00),
      SIMDE_FLOAT32_C(  -105.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
      SIMDE_FLOAT32_C(  -105.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -105.00), SIMDE_FLOAT32_C(  -105.00),
      SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -105.00), SIMDE_FLOAT32_C(  -105.00), SIMDE_FLOAT32_C(     0.00),
      SIMDE_FLOAT32_C(  -105.00), SIMDE_FLOAT32_C(  -105.00), SIMDE_FLOAT32_C(  -105.00), SIMDE_FLOAT32_C(     0.00),
      SIMDE_FLOAT32_C(  -105.00), SIMDE_FLOAT32_C(  -105.00), SIMDE_FLOAT32_C(  -105.00), SIMDE_FLOAT32_C(  -105.00),
      SIMDE_FLOAT32_C(  -105.00), SIMDE_FLOAT32_C(  -105.00), SIMDE_FLOAT32_C(  -105.00), SIMDE_FLOAT32_C(  -105.00),
      SIMDE_FLOAT32_C(  -105.00), SIMDE_FLOAT32_C(  -105.00), SIMDE_FLOAT32_C(  -105.00), SIMDE_FLOAT32_C(  -105.00),
      SIMDE_FLOAT32_C(  -105.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -105.00), SIMDE_FLOAT32_C(  -105.00),
      SIMDE_FLOAT32_C(  -105.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
      SIMDE_FLOAT32_C(  -105.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -105.00), SIMDE_FLOAT32_C(     0.00),
      SIMDE_FLOAT32_C(  -105.00), SIMDE_FLOAT32_C(  -105.00), SIMDE_FLOAT32_C(  -105.00), SIMDE_FLOAT32_C(  -105.00),
      SIMDE_FLOAT32_C(  -105.00), SIMDE_FLOAT32_C(  -105.00), SIMDE_FLOAT32_C(  -105.00), SIMDE_FLOAT32_C(     0.00),
      SIMDE_FLOAT32_C(  -105.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -105.00),
      SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -105.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -105.00),
      SIMDE_FLOAT32_C(  -105.00), SIMDE_FLOAT32_C(  -105.00), SIMDE_FLOAT32_C(  -105.00), SIMDE_FLOAT32_C(  -105.00),
      SIMDE_FLOAT32_C(  -105.00), SIMDE_FLOAT32_C(  -105.00), SIMDE_FLOAT32_C(  -105.00), SIMDE_FLOAT32_C(  -105.00),
      SIMDE_FLOAT32_C(  -105.00), SIMDE_FLOAT32_C(  -105.00), SIMDE_FLOAT32_C(  -105.00), SIMDE_FLOAT32_C(  -105.00),
      SIMDE_FLOAT32_C(  -105.00), SIMDE_FLOAT32_C(  -105.00), SIMDE_FLOAT32_C(  -105.00), SIMDE_FLOAT32_C(  -105.00),
      SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -105.00), SIMDE_FLOAT32_C(  -105.00),
      SIMDE_FLOAT32_C(  -105.00), SIMDE_FLOAT32_C(  -105.00), SIMDE_FLOAT32_C(  -105.00), SIMDE_FLOAT32_C(  -105.00),
      SIMDE_FLOAT32_C(  -105.00), SIMDE_FLOAT32_C(  -105.00), SIMDE_FLOAT32_C(  -105.00), SIMDE_FLOAT32_C(  -105.00),
      SIMDE_FLOAT32_C(  -105.00), SIMDE_FLOAT32_C(  -105.00), SIMDE_FLOAT32_C(  -105.00), SIMDE_FLOAT32_C(  -105.00),
      SIMDE_FLOAT32_C(  -105.00), SIMDE_FLOAT32_C(  -105.00), SIMDE_FLOAT32_C(  -105.00), SIMDE_FLOAT32_C(  -105.00),
      SIMDE_FLOAT32_C(  -105.00), SIMDE_FLOAT32_C(  -105.00), SIMDE_FLOAT32_C(  -105.00), SIMDE_FLOAT32_C(  -105.00),
      SIMDE_FLOAT32_C(  -105.00), SIMDE_FLOAT32_C(  -105.00), SIMDE_FLOAT32_C(  -105.00), SIMDE_FLOAT32_C(  -105.00),
      SIMDE_FLOAT32_C(  -105.00), SIMDE_FLOAT32_C(  -105.00), SIMDE_FLOAT32_C(  -105.00), SIMDE_FLOAT32_C(  -105.00),
      SIMDE_FLOAT32_C(  -105.00), SIMDE_FLOAT32_C(  -105.00), SIMDE_FLOAT32_C(  -105.00), SIMDE_FLOAT32_C(  -105.00),
      SIMDE_FLOAT32_C(  -105.00), SIMDE_FLOAT32_C(  -105.00), SIMDE_FLOAT32_C(  -105.00), SIMDE_FLOAT32_C(  -105.00),
      SIMDE_FLOAT32_C(  -105.00), SIMDE_FLOAT32_C(  -105.00), SIMDE_FLOAT32_C(  -105.00), SIMDE_FLOAT32_C(  -105.00),
      SIMDE_FLOAT32_C(  -105.00), SIMDE_FLOAT32_C(  -105.00), SIMDE_FLOAT32_C(  -105.00), SIMDE_FLOAT32_C(  -105.00),
      SIMDE_FLOAT32_C(  -105.00), SIMDE_FLOAT32_C(  -105.00), SIMDE_FLOAT32_C(  -105.00), SIMDE_FLOAT32_C(  -105.00),
      SIMDE_FLOAT32_C(  -105.00), SIMDE_FLOAT32_C(  -105.00), SIMDE_FLOAT32_C(  -105.00), SIMDE_FLOAT32_C(  -105.00),
      SIMDE_FLOAT32_C(  -105.00), SIMDE_FLOAT32_C(  -105.00), SIMDE_FLOAT32_C(  -105.00), SIMDE_FLOAT32_C(  -105.00),
      SIMDE_FLOAT32_C(  -105.00), SIMDE_FLOAT32_C(  -105.00), SIMDE_FLOAT32_C(  -105.00), SIMDE_FLOAT32_C(  -105.00),
      SIMDE_FLOAT32_C(  -105.00), SIMDE_FLOAT32_C(  -105.00), SIMDE_FLOAT32_C(  -105.00), SIMDE_FLOAT32_C(  -105.00),
      SIMDE_FLOAT32_C(  -105.00), SIMDE_FLOAT32_C(  -105.00), SIMDE_FLOAT32_C(  -105.00), SIMDE_FLOAT32_C(  -105.00),
      SIMDE_FLOAT32_C(  -105.00), SIMDE_FLOAT32_C(  -105.00), SIMDE_FLOAT32_C(  -105.00), SIMDE_FLOAT32_C(  -105.00),
      SIMDE_FLOAT32_C(  -105.00), SIMDE_FLOAT32_C(  -105.00), SIMDE_FLOAT32_C(  -105.00), SIMDE_FLOAT32_C(  -105.00),
      SIMDE_FLOAT32_C(  -105.00), SIMDE_FLOAT32_C(  -105.00), SIMDE_FLOAT32_C(  -105.00), SIMDE_FLOAT32_C(  -105.00),
      SIMDE_FLOAT32_C(  -105.00), SIMDE_FLOAT32_C(  -105.00), SIMDE_FLOAT32_C(  -105.00), SIMDE_FLOAT32_C(  -105.00),
      SIMDE_FLOAT32_C(  -105.00), SIMDE_FLOAT32_C(  -105.00), SIMDE_FLOAT32_C(  -105.00), SIMDE_FLOAT32_C(  -105.00),
      SIMDE_FLOAT32_C(  -105.00), SIMDE_FLOAT32_C(  -105.00), SIMDE_FLOAT32_C(  -105.00), SIMDE_FLOAT32_C(  -105.00),
      SIMDE_FLOAT32_C(  -105.00), SIMDE_FLOAT32_C(  -105.00), SIMDE_FLOAT32_C(  -105.00), SIMDE_FLOAT32_C(  -105.00),
      SIMDE_FLOAT32_C(  -105.00), SIMDE_FLOAT32_C(  -105.00), SIMDE_FLOAT32_C(  -105.00), SIMDE_FLOAT32_C(  -105.00),
      SIMDE_FLOAT32_C(  -105.00), SIMDE_FLOAT32_C(  -105.00), SIMDE_FLOAT32_C(  -105.00), SIMDE_FLOAT32_C(  -105.00),
      SIMDE_FLOAT32_C(  -105.00), SIMDE_FLOAT32_C(  -105.00), SIMDE_FLOAT32_C(  -105.00), SIMDE_FLOAT32_C(  -105.00),
      SIMDE_FLOAT32_C(  -105.00), SIMDE_FLOAT32_C(  -105.00), SIMDE_FLOAT32_C(  -105.00), SIMDE_FLOAT32_C(  -105.00),
      SIMDE_FLOAT32_C(  -105.00), SIMDE_FLOAT32_C(  -105.00), SIMDE_FLOAT32_C(  -105.00), SIMDE_FLOAT32_C(  -105.00),
      SIMDE_FLOAT32_C(  -105.00), SIMDE_FLOAT32_C(  -105.00), SIMDE_FLOAT32_C(  -105.00), SIMDE_FLOAT32_C(  -105.00),
      SIMDE_FLOAT32_C(  -105.00), SIMDE_FLOAT32_C(  -105.00), SIMDE_FLOAT32_C(  -105.00), SIMDE_FLOAT32_C(  -105.00),
      SIMDE_FLOAT32_C(  -105.00), SIMDE_FLOAT32_C(  -105.00), SIMDE_FLOAT32_C(  -105.00), SIMDE_FLOAT32_C(  -105.00),
      SIMDE_FLOAT32_C(  -105.00), SIMDE_FLOAT32_C(  -105.00), SIMDE_FLOAT32_C(  -105.00), SIMDE_FLOAT32_C(  -105.00),
      SIMDE_FLOAT32_C(  -105.00), SIMDE_FLOAT32_C(  -105.00), SIMDE_FLOAT32_C(  -105.00), SIMDE_FLOAT32_C(  -105.00),
      SIMDE_FLOAT32_C(  -105.00), SIMDE_FLOAT32_C(  -105.00), SIMDE_FLOAT32_C(  -105.00), SIMDE_FLOAT32_C(  -105.00),
      SIMDE_FLOAT32_C(  -105.00), SIMDE_FLOAT32_C(  -105.00), SIMDE_FLOAT32_C(  -105.00), SIMDE_FLOAT32_C(  -105.00),
      SIMDE_FLOAT32_C(  -105.00), SIMDE_FLOAT32_C(  -105.00), SIMDE_FLOAT32_C(  -105.00), SIMDE_FLOAT32_C(  -105.00),
      SIMDE_FLOAT32_C(  -105.00), SIMDE_FLOAT32_C(  -105.00), SIMDE_FLOAT32_C(  -105.00), SIMDE_FLOAT32_C(  -105.00),
      SIMDE_FLOAT32_C(  -105.00), SIMDE_FLOAT32_C(  -105.00), SIMDE_FLOAT32_C(  -105.00), SIMDE_FLOAT32_C(  -105.00),
      SIMDE_FLOAT32_C(  -105.00), SIMDE_FLOAT32_C(  -105.00), SIMDE_FLOAT32_C(  -105.00), SIMDE_FLOAT32_C(  -105.00),
      SIMDE_FLOAT32_C(  -105.00), SIMDE_FLOAT32_C(  -105.00), SIMDE_FLOAT32_C(  -105.00), SIMDE_FLOAT32_C(  -105.00),
      SIMDE_FLOAT32_C(  -105.00), SIMDE_FLOAT32_C(  -105.00), SIMDE_FLOAT32_C(  -105.00), SIMDE_FLOAT32_C(  -105.00) };

  static simde_float32 r[sizeof(e) / sizeof(e[0])];
  static const int32_t len = HEDLEY_STATIC_CAST(int32_t, sizeof(e) / sizeof(e[0]));
  int32_t i = 0;
  simde_svbool_t pg = simde_svwhilelt_b32_s32(i, len);
  while (simde_svptest_first(simde_svptrue_b32(), pg)) {
    simde_svfloat32_t rv;
    simde_svbool_t pv;

    pv = simde_svcmplt_s32(pg, simde_svld1_s32(pg, &(p[i])), simde_svdup_n_s32(INT32_C(0)));
    rv = simde_svdup_n_f32_z(pv, a);

    simde_svst1_f32(pg, &(r[i]), rv);

    i += simde_svcntw();
    pg = simde_svwhilelt_b32_s32(i, len);
  }

  simde_assert_equal_vf32(len, e, r, 1);

  return 0;
#else
  simde_float32 a, e[1024 / sizeof(int32_t)];
  int32_t p[1024 / sizeof(int32_t)];
  int32_t len;

  fputc('\n', stdout);

  len = simde_test_codegen_random_i32() & ((sizeof(e) / sizeof(e[0])) - 1);
  simde_test_codegen_random_memory(sizeof(p), HEDLEY_REINTERPRET_CAST(uint8_t*, p));
  a = simde_test_codegen_random_i8();

  int32_t i = 0;
  simde_svbool_t pg = simde_svwhilelt_b32_s32(i, len);
  while (simde_svptest_first(simde_svptrue_b32(), pg)) {
    simde_svfloat32_t ev;
    simde_svbool_t pv;

    pv = simde_svcmplt_f32(pg, simde_svreinterpret_f32_s32(simde_svld1_s32(pg, &(p[i]))), simde_svdup_n_f32(0));
    ev = simde_svdup_n_f32_z(pv, a);

    simde_svst1_f32(pg, &(e[i]), ev);
    simde_svst1_s32(pg, &(p[i]), simde_svdup_n_s32_z(pv, ~INT32_C(0)));

    i += simde_svcntw();
    pg = simde_svwhilelt_b32_s32(i, len);
  }

  simde_test_codegen_write_1vi32(1, HEDLEY_STATIC_CAST(size_t, len), p);
  simde_test_codegen_write_1f32(1, a);
  simde_test_codegen_write_1vf32(1, HEDLEY_STATIC_CAST(size_t, len), e);

  return 1;
#endif
}

static int
test_simde_svdup_n_f32_m (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const int32_t p[] =
    {  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),
      -INT32_C(           1), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),
       INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),
      -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),
       INT32_C(           0), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),
      -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),
      -INT32_C(           1),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),
      -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1),
      -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),
      -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),
      -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),
      -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),
       INT32_C(           0), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0), -INT32_C(           1),
       INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),
      -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),
      -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),  INT32_C(           0),  INT32_C(           0), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1),
      -INT32_C(           1),  INT32_C(           0) };
  static const simde_float32 a[] =
    { SIMDE_FLOAT32_C(  -565.61), SIMDE_FLOAT32_C(  -379.72), SIMDE_FLOAT32_C(   460.37), SIMDE_FLOAT32_C(   144.14),
      SIMDE_FLOAT32_C(   325.75), SIMDE_FLOAT32_C(   626.27), SIMDE_FLOAT32_C(  -567.97), SIMDE_FLOAT32_C(  -564.20),
      SIMDE_FLOAT32_C(     7.88), SIMDE_FLOAT32_C(   640.52), SIMDE_FLOAT32_C(    20.60), SIMDE_FLOAT32_C(  -373.75),
      SIMDE_FLOAT32_C(   632.23), SIMDE_FLOAT32_C(   427.56), SIMDE_FLOAT32_C(   300.92), SIMDE_FLOAT32_C(  -589.57),
      SIMDE_FLOAT32_C(   164.48), SIMDE_FLOAT32_C(  -871.42), SIMDE_FLOAT32_C(   866.10), SIMDE_FLOAT32_C(   783.63),
      SIMDE_FLOAT32_C(   408.25), SIMDE_FLOAT32_C(   985.83), SIMDE_FLOAT32_C(    31.46), SIMDE_FLOAT32_C(  -434.91),
      SIMDE_FLOAT32_C(   177.94), SIMDE_FLOAT32_C(  -307.00), SIMDE_FLOAT32_C(  -552.56), SIMDE_FLOAT32_C(   476.04),
      SIMDE_FLOAT32_C(   298.30), SIMDE_FLOAT32_C(  -458.60), SIMDE_FLOAT32_C(   851.10), SIMDE_FLOAT32_C(   732.69),
      SIMDE_FLOAT32_C(   161.68), SIMDE_FLOAT32_C(   311.46), SIMDE_FLOAT32_C(  -123.17), SIMDE_FLOAT32_C(  -512.57),
      SIMDE_FLOAT32_C(   -62.26), SIMDE_FLOAT32_C(   308.86), SIMDE_FLOAT32_C(   -76.77), SIMDE_FLOAT32_C(   945.62),
      SIMDE_FLOAT32_C(   -50.62), SIMDE_FLOAT32_C(   943.82), SIMDE_FLOAT32_C(  -428.13), SIMDE_FLOAT32_C(  -418.39),
      SIMDE_FLOAT32_C(   371.38), SIMDE_FLOAT32_C(   872.79), SIMDE_FLOAT32_C(    -7.96), SIMDE_FLOAT32_C(  -464.13),
      SIMDE_FLOAT32_C(  -998.63), SIMDE_FLOAT32_C(  -141.86), SIMDE_FLOAT32_C(  -680.50), SIMDE_FLOAT32_C(   409.61),
      SIMDE_FLOAT32_C(  -156.04), SIMDE_FLOAT32_C(   350.96), SIMDE_FLOAT32_C(   974.70), SIMDE_FLOAT32_C(  -978.09),
      SIMDE_FLOAT32_C(  -956.04), SIMDE_FLOAT32_C(  -577.86), SIMDE_FLOAT32_C(   497.95), SIMDE_FLOAT32_C(   342.26),
      SIMDE_FLOAT32_C(   -36.46), SIMDE_FLOAT32_C(   349.04), SIMDE_FLOAT32_C(    74.95), SIMDE_FLOAT32_C(  -874.78),
      SIMDE_FLOAT32_C(  -339.49), SIMDE_FLOAT32_C(   951.79), SIMDE_FLOAT32_C(  -387.35), SIMDE_FLOAT32_C(   598.24),
      SIMDE_FLOAT32_C(   260.64), SIMDE_FLOAT32_C(   535.88), SIMDE_FLOAT32_C(   543.86), SIMDE_FLOAT32_C(  -789.98),
      SIMDE_FLOAT32_C(   479.70), SIMDE_FLOAT32_C(  -884.27), SIMDE_FLOAT32_C(  -208.37), SIMDE_FLOAT32_C(  -148.91),
      SIMDE_FLOAT32_C(   988.52), SIMDE_FLOAT32_C(   783.67), SIMDE_FLOAT32_C(   386.96), SIMDE_FLOAT32_C(   989.89),
      SIMDE_FLOAT32_C(  -358.19), SIMDE_FLOAT32_C(   706.46), SIMDE_FLOAT32_C(   399.51), SIMDE_FLOAT32_C(   485.77),
      SIMDE_FLOAT32_C(    57.42), SIMDE_FLOAT32_C(   374.21), SIMDE_FLOAT32_C(   507.68), SIMDE_FLOAT32_C(   101.38),
      SIMDE_FLOAT32_C(   796.35), SIMDE_FLOAT32_C(     5.62), SIMDE_FLOAT32_C(  -556.36), SIMDE_FLOAT32_C(  -240.11),
      SIMDE_FLOAT32_C(  -645.34), SIMDE_FLOAT32_C(   518.60), SIMDE_FLOAT32_C(  -114.89), SIMDE_FLOAT32_C(    15.17),
      SIMDE_FLOAT32_C(   470.38), SIMDE_FLOAT32_C(   497.76), SIMDE_FLOAT32_C(  -386.59), SIMDE_FLOAT32_C(  -268.97),
      SIMDE_FLOAT32_C(    33.64), SIMDE_FLOAT32_C(  -842.73), SIMDE_FLOAT32_C(   -58.95), SIMDE_FLOAT32_C(  -486.65),
      SIMDE_FLOAT32_C(  -726.99), SIMDE_FLOAT32_C(   732.68), SIMDE_FLOAT32_C(   364.44), SIMDE_FLOAT32_C(  -738.47),
      SIMDE_FLOAT32_C(   516.35), SIMDE_FLOAT32_C(  -248.61), SIMDE_FLOAT32_C(  -748.58), SIMDE_FLOAT32_C(  -841.84),
      SIMDE_FLOAT32_C(  -542.15), SIMDE_FLOAT32_C(   650.93), SIMDE_FLOAT32_C(   643.93), SIMDE_FLOAT32_C(   515.27),
      SIMDE_FLOAT32_C(    25.14), SIMDE_FLOAT32_C(   151.61), SIMDE_FLOAT32_C(  -383.35), SIMDE_FLOAT32_C(  -178.51),
      SIMDE_FLOAT32_C(  -842.77), SIMDE_FLOAT32_C(    60.29), SIMDE_FLOAT32_C(   581.38), SIMDE_FLOAT32_C(  -488.10),
      SIMDE_FLOAT32_C(  -421.11), SIMDE_FLOAT32_C(  -533.51), SIMDE_FLOAT32_C(   527.06), SIMDE_FLOAT32_C(  -950.73),
      SIMDE_FLOAT32_C(   964.25), SIMDE_FLOAT32_C(  -859.52) };
  static const simde_float32 b = SIMDE_FLOAT32_C(  -219.70);
  static const simde_float32 e[] =
    { SIMDE_FLOAT32_C(  -565.61), SIMDE_FLOAT32_C(  -219.70), SIMDE_FLOAT32_C(   460.37), SIMDE_FLOAT32_C(   144.14),
      SIMDE_FLOAT32_C(   325.75), SIMDE_FLOAT32_C(   626.27), SIMDE_FLOAT32_C(  -567.97), SIMDE_FLOAT32_C(  -219.70),
      SIMDE_FLOAT32_C(  -219.70), SIMDE_FLOAT32_C(  -219.70), SIMDE_FLOAT32_C(    20.60), SIMDE_FLOAT32_C(  -219.70),
      SIMDE_FLOAT32_C(   632.23), SIMDE_FLOAT32_C(  -219.70), SIMDE_FLOAT32_C(  -219.70), SIMDE_FLOAT32_C(  -589.57),
      SIMDE_FLOAT32_C(   164.48), SIMDE_FLOAT32_C(  -871.42), SIMDE_FLOAT32_C(   866.10), SIMDE_FLOAT32_C(  -219.70),
      SIMDE_FLOAT32_C(  -219.70), SIMDE_FLOAT32_C(  -219.70), SIMDE_FLOAT32_C(  -219.70), SIMDE_FLOAT32_C(  -434.91),
      SIMDE_FLOAT32_C(  -219.70), SIMDE_FLOAT32_C(  -219.70), SIMDE_FLOAT32_C(  -552.56), SIMDE_FLOAT32_C(   476.04),
      SIMDE_FLOAT32_C(   298.30), SIMDE_FLOAT32_C(  -458.60), SIMDE_FLOAT32_C(   851.10), SIMDE_FLOAT32_C(  -219.70),
      SIMDE_FLOAT32_C(   161.68), SIMDE_FLOAT32_C(  -219.70), SIMDE_FLOAT32_C(  -123.17), SIMDE_FLOAT32_C(  -219.70),
      SIMDE_FLOAT32_C(  -219.70), SIMDE_FLOAT32_C(  -219.70), SIMDE_FLOAT32_C(  -219.70), SIMDE_FLOAT32_C(   945.62),
      SIMDE_FLOAT32_C(  -219.70), SIMDE_FLOAT32_C(   943.82), SIMDE_FLOAT32_C(  -428.13), SIMDE_FLOAT32_C(  -418.39),
      SIMDE_FLOAT32_C(   371.38), SIMDE_FLOAT32_C(   872.79), SIMDE_FLOAT32_C(  -219.70), SIMDE_FLOAT32_C(  -219.70),
      SIMDE_FLOAT32_C(  -219.70), SIMDE_FLOAT32_C(  -141.86), SIMDE_FLOAT32_C(  -680.50), SIMDE_FLOAT32_C(  -219.70),
      SIMDE_FLOAT32_C(  -219.70), SIMDE_FLOAT32_C(   350.96), SIMDE_FLOAT32_C(   974.70), SIMDE_FLOAT32_C(  -219.70),
      SIMDE_FLOAT32_C(  -219.70), SIMDE_FLOAT32_C(  -219.70), SIMDE_FLOAT32_C(   497.95), SIMDE_FLOAT32_C(   342.26),
      SIMDE_FLOAT32_C(  -219.70), SIMDE_FLOAT32_C(   349.04), SIMDE_FLOAT32_C(  -219.70), SIMDE_FLOAT32_C(  -219.70),
      SIMDE_FLOAT32_C(  -219.70), SIMDE_FLOAT32_C(  -219.70), SIMDE_FLOAT32_C(  -387.35), SIMDE_FLOAT32_C(   598.24),
      SIMDE_FLOAT32_C(   260.64), SIMDE_FLOAT32_C(   535.88), SIMDE_FLOAT32_C(   543.86), SIMDE_FLOAT32_C(  -789.98),
      SIMDE_FLOAT32_C(  -219.70), SIMDE_FLOAT32_C(  -884.27), SIMDE_FLOAT32_C(  -219.70), SIMDE_FLOAT32_C(  -148.91),
      SIMDE_FLOAT32_C(  -219.70), SIMDE_FLOAT32_C(  -219.70), SIMDE_FLOAT32_C(  -219.70), SIMDE_FLOAT32_C(   989.89),
      SIMDE_FLOAT32_C(  -219.70), SIMDE_FLOAT32_C(  -219.70), SIMDE_FLOAT32_C(  -219.70), SIMDE_FLOAT32_C(  -219.70),
      SIMDE_FLOAT32_C(    57.42), SIMDE_FLOAT32_C(   374.21), SIMDE_FLOAT32_C(   507.68), SIMDE_FLOAT32_C(   101.38),
      SIMDE_FLOAT32_C(  -219.70), SIMDE_FLOAT32_C(     5.62), SIMDE_FLOAT32_C(  -556.36), SIMDE_FLOAT32_C(  -240.11),
      SIMDE_FLOAT32_C(  -645.34), SIMDE_FLOAT32_C(  -219.70), SIMDE_FLOAT32_C(  -114.89), SIMDE_FLOAT32_C(  -219.70),
      SIMDE_FLOAT32_C(   470.38), SIMDE_FLOAT32_C(  -219.70), SIMDE_FLOAT32_C(  -219.70), SIMDE_FLOAT32_C(  -268.97),
      SIMDE_FLOAT32_C(    33.64), SIMDE_FLOAT32_C(  -219.70), SIMDE_FLOAT32_C(   -58.95), SIMDE_FLOAT32_C(  -219.70),
      SIMDE_FLOAT32_C(  -726.99), SIMDE_FLOAT32_C(  -219.70), SIMDE_FLOAT32_C(   364.44), SIMDE_FLOAT32_C(  -738.47),
      SIMDE_FLOAT32_C(  -219.70), SIMDE_FLOAT32_C(  -248.61), SIMDE_FLOAT32_C(  -748.58), SIMDE_FLOAT32_C(  -841.84),
      SIMDE_FLOAT32_C(  -219.70), SIMDE_FLOAT32_C(  -219.70), SIMDE_FLOAT32_C(  -219.70), SIMDE_FLOAT32_C(  -219.70),
      SIMDE_FLOAT32_C(    25.14), SIMDE_FLOAT32_C(   151.61), SIMDE_FLOAT32_C(  -383.35), SIMDE_FLOAT32_C(  -219.70),
      SIMDE_FLOAT32_C(  -219.70), SIMDE_FLOAT32_C(  -219.70), SIMDE_FLOAT32_C(  -219.70), SIMDE_FLOAT32_C(  -488.10),
      SIMDE_FLOAT32_C(  -421.11), SIMDE_FLOAT32_C(  -219.70), SIMDE_FLOAT32_C(  -219.70), SIMDE_FLOAT32_C(  -219.70),
      SIMDE_FLOAT32_C(  -219.70), SIMDE_FLOAT32_C(  -859.52) };

  static simde_float32 r[sizeof(e) / sizeof(e[0])];
  static const int32_t len = HEDLEY_STATIC_CAST(int32_t, sizeof(e) / sizeof(e[0]));
  int32_t i = 0;
  simde_svbool_t pg = simde_svwhilelt_b32_s32(i, len);
  while (simde_svptest_first(simde_svptrue_b32(), pg)) {
    simde_svfloat32_t
      rv,
      av = simde_svld1_f32(pg, &(a[i]));
    simde_svbool_t pv;

    pv = simde_svcmplt_s32(pg, simde_svld1_s32(pg, &(p[i])), simde_svdup_n_s32(INT32_C(0)));
    rv = simde_svdup_n_f32_m(av, pv, b);

    simde_svst1_f32(pg, &(r[i]), rv);

    i += simde_svcntw();
    pg = simde_svwhilelt_b32_s32(i, len);
  }

  simde_assert_equal_vf32(len, e, r, 1);

  return 0;
#else
  int32_t p[1024 / sizeof(int32_t)];
  simde_float32 a[1024 / sizeof(int32_t)], b, e[1024 / sizeof(int32_t)];
  int32_t len = simde_test_arm_sve_random_length(sizeof(e), sizeof(e[0]));

  fputc('\n', stdout);

  simde_test_codegen_random_memory(sizeof(p), HEDLEY_REINTERPRET_CAST(uint8_t*, p));
  simde_test_codegen_random_vf32(HEDLEY_STATIC_CAST(size_t, len), a, SIMDE_FLOAT32_C(-1000.0), SIMDE_FLOAT32_C(1000.0));
  b = simde_test_codegen_random_f32(SIMDE_FLOAT32_C(-1000.0), SIMDE_FLOAT32_C(1000.0));

  int32_t i = 0;
  simde_svbool_t pg = simde_svwhilelt_b32_s32(i, len);
  while (simde_svptest_first(simde_svptrue_b32(), pg)) {
    simde_svfloat32_t av, ev;
    simde_svbool_t pv;

    pv = simde_svcmplt_s32(pg, simde_svld1_s32(pg, &(p[i])), simde_svdup_n_s32(0));
    av = simde_svld1_f32(pg, &(a[i]));

    ev = simde_svdup_n_f32_m(av, pv, b);

    simde_svst1_f32(pg, &(e[i]), ev);
    simde_svst1_s32(pg, &(p[i]), simde_svdup_n_s32_z(pv, ~INT32_C(0)));

    i += simde_svcntw();
    pg = simde_svwhilelt_b32_s32(i, len);
  }

  simde_test_codegen_write_1vi32(1, HEDLEY_STATIC_CAST(size_t, len), p);
  simde_test_codegen_write_1vf32(1, HEDLEY_STATIC_CAST(size_t, len), a);
  simde_test_codegen_write_1f32(1, b);
  simde_test_codegen_write_1vf32(1, HEDLEY_STATIC_CAST(size_t, len), e);

  return 1;
#endif
}

static int
test_simde_svdup_n_f64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const simde_float64 a = SIMDE_FLOAT64_C(   562.36);
  static const simde_float64 e[] =
    { SIMDE_FLOAT64_C(   562.36), SIMDE_FLOAT64_C(   562.36), SIMDE_FLOAT64_C(   562.36), SIMDE_FLOAT64_C(   562.36),
      SIMDE_FLOAT64_C(   562.36), SIMDE_FLOAT64_C(   562.36), SIMDE_FLOAT64_C(   562.36), SIMDE_FLOAT64_C(   562.36),
      SIMDE_FLOAT64_C(   562.36), SIMDE_FLOAT64_C(   562.36), SIMDE_FLOAT64_C(   562.36), SIMDE_FLOAT64_C(   562.36),
      SIMDE_FLOAT64_C(   562.36), SIMDE_FLOAT64_C(   562.36), SIMDE_FLOAT64_C(   562.36), SIMDE_FLOAT64_C(   562.36),
      SIMDE_FLOAT64_C(   562.36), SIMDE_FLOAT64_C(   562.36), SIMDE_FLOAT64_C(   562.36), SIMDE_FLOAT64_C(   562.36),
      SIMDE_FLOAT64_C(   562.36), SIMDE_FLOAT64_C(   562.36), SIMDE_FLOAT64_C(   562.36), SIMDE_FLOAT64_C(   562.36),
      SIMDE_FLOAT64_C(   562.36), SIMDE_FLOAT64_C(   562.36), SIMDE_FLOAT64_C(   562.36), SIMDE_FLOAT64_C(   562.36),
      SIMDE_FLOAT64_C(   562.36), SIMDE_FLOAT64_C(   562.36), SIMDE_FLOAT64_C(   562.36), SIMDE_FLOAT64_C(   562.36),
      SIMDE_FLOAT64_C(   562.36), SIMDE_FLOAT64_C(   562.36), SIMDE_FLOAT64_C(   562.36), SIMDE_FLOAT64_C(   562.36),
      SIMDE_FLOAT64_C(   562.36), SIMDE_FLOAT64_C(   562.36), SIMDE_FLOAT64_C(   562.36), SIMDE_FLOAT64_C(   562.36),
      SIMDE_FLOAT64_C(   562.36), SIMDE_FLOAT64_C(   562.36), SIMDE_FLOAT64_C(   562.36), SIMDE_FLOAT64_C(   562.36),
      SIMDE_FLOAT64_C(   562.36), SIMDE_FLOAT64_C(   562.36), SIMDE_FLOAT64_C(   562.36), SIMDE_FLOAT64_C(   562.36),
      SIMDE_FLOAT64_C(   562.36), SIMDE_FLOAT64_C(   562.36), SIMDE_FLOAT64_C(   562.36), SIMDE_FLOAT64_C(   562.36),
      SIMDE_FLOAT64_C(   562.36), SIMDE_FLOAT64_C(   562.36), SIMDE_FLOAT64_C(   562.36), SIMDE_FLOAT64_C(   562.36),
      SIMDE_FLOAT64_C(   562.36), SIMDE_FLOAT64_C(   562.36), SIMDE_FLOAT64_C(   562.36), SIMDE_FLOAT64_C(   562.36),
      SIMDE_FLOAT64_C(   562.36), SIMDE_FLOAT64_C(   562.36), SIMDE_FLOAT64_C(   562.36), SIMDE_FLOAT64_C(   562.36),
      SIMDE_FLOAT64_C(   562.36), SIMDE_FLOAT64_C(   562.36), SIMDE_FLOAT64_C(   562.36), SIMDE_FLOAT64_C(   562.36),
      SIMDE_FLOAT64_C(   562.36), SIMDE_FLOAT64_C(   562.36), SIMDE_FLOAT64_C(   562.36), SIMDE_FLOAT64_C(   562.36),
      SIMDE_FLOAT64_C(   562.36), SIMDE_FLOAT64_C(   562.36), SIMDE_FLOAT64_C(   562.36), SIMDE_FLOAT64_C(   562.36),
      SIMDE_FLOAT64_C(   562.36), SIMDE_FLOAT64_C(   562.36), SIMDE_FLOAT64_C(   562.36), SIMDE_FLOAT64_C(   562.36),
      SIMDE_FLOAT64_C(   562.36), SIMDE_FLOAT64_C(   562.36), SIMDE_FLOAT64_C(   562.36), SIMDE_FLOAT64_C(   562.36),
      SIMDE_FLOAT64_C(   562.36), SIMDE_FLOAT64_C(   562.36), SIMDE_FLOAT64_C(   562.36), SIMDE_FLOAT64_C(   562.36),
      SIMDE_FLOAT64_C(   562.36), SIMDE_FLOAT64_C(   562.36), SIMDE_FLOAT64_C(   562.36), SIMDE_FLOAT64_C(   562.36),
      SIMDE_FLOAT64_C(   562.36), SIMDE_FLOAT64_C(   562.36), SIMDE_FLOAT64_C(   562.36), SIMDE_FLOAT64_C(   562.36),
      SIMDE_FLOAT64_C(   562.36), SIMDE_FLOAT64_C(   562.36), SIMDE_FLOAT64_C(   562.36), SIMDE_FLOAT64_C(   562.36),
      SIMDE_FLOAT64_C(   562.36), SIMDE_FLOAT64_C(   562.36), SIMDE_FLOAT64_C(   562.36), SIMDE_FLOAT64_C(   562.36),
      SIMDE_FLOAT64_C(   562.36), SIMDE_FLOAT64_C(   562.36), SIMDE_FLOAT64_C(   562.36), SIMDE_FLOAT64_C(   562.36),
      SIMDE_FLOAT64_C(   562.36), SIMDE_FLOAT64_C(   562.36), SIMDE_FLOAT64_C(   562.36), SIMDE_FLOAT64_C(   562.36),
      SIMDE_FLOAT64_C(   562.36), SIMDE_FLOAT64_C(   562.36), SIMDE_FLOAT64_C(   562.36), SIMDE_FLOAT64_C(   562.36),
      SIMDE_FLOAT64_C(   562.36), SIMDE_FLOAT64_C(   562.36), SIMDE_FLOAT64_C(   562.36), SIMDE_FLOAT64_C(   562.36),
      SIMDE_FLOAT64_C(   562.36), SIMDE_FLOAT64_C(   562.36), SIMDE_FLOAT64_C(   562.36), SIMDE_FLOAT64_C(   562.36),
      SIMDE_FLOAT64_C(   562.36) };

  static simde_float64 r[sizeof(e) / sizeof(e[0])];
  static const int64_t len = HEDLEY_STATIC_CAST(int64_t, sizeof(e) / sizeof(e[0]));
  int32_t i = 0;
  simde_svbool_t pg = simde_svwhilelt_b64_s32(i, len);
  while (simde_svptest_first(simde_svptrue_b64(), pg)) {
    simde_svfloat64_t rv;

    rv = simde_svdup_n_f64(a);

    simde_svst1_f64(pg, &(r[i]), rv);

    i += simde_svcntd();
    pg = simde_svwhilelt_b64_s32(i, len);
  }

  simde_assert_equal_vf64(len, e, r, 1);

  return 0;
#else
  simde_float64 a, e[1024 / sizeof(int64_t)];
  int64_t len;

  fputc('\n', stdout);

  len = simde_test_codegen_random_i64() & ((sizeof(e) / sizeof(e[0])) - 1);
  a = simde_test_codegen_random_f64(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));

  int64_t i = 0;
  simde_svbool_t pg = simde_svwhilelt_b64_s32(i, len);
  while (simde_svptest_first(simde_svptrue_b64(), pg)) {
    simde_svfloat64_t ev;

    ev = simde_svdup_n_f64(a);

    simde_svst1_f64(pg, &(e[i]), ev);

    i += simde_svcntd();
    pg = simde_svwhilelt_b64_s32(i, len);
  }

  simde_test_codegen_write_1f32(1, a);
  simde_test_codegen_write_1vf64(1, HEDLEY_STATIC_CAST(size_t, len), e);

  return 1;
#endif
}

static int
test_simde_svdup_n_f64_z (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const int64_t p[] =
    {  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0), -INT64_C(                   1),
       INT64_C(                   0),  INT64_C(                   0), -INT64_C(                   1), -INT64_C(                   1),
       INT64_C(                   0), -INT64_C(                   1),  INT64_C(                   0),  INT64_C(                   0),
       INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),
       INT64_C(                   0),  INT64_C(                   0), -INT64_C(                   1),  INT64_C(                   0),
       INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),
       INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),
       INT64_C(                   0), -INT64_C(                   1), -INT64_C(                   1),  INT64_C(                   0),
       INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0), -INT64_C(                   1),
       INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),
       INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),
       INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),
       INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),
       INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),
      -INT64_C(                   1),  INT64_C(                   0), -INT64_C(                   1),  INT64_C(                   0),
       INT64_C(                   0),  INT64_C(                   0), -INT64_C(                   1),  INT64_C(                   0),
      -INT64_C(                   1), -INT64_C(                   1),  INT64_C(                   0), -INT64_C(                   1),
       INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),
       INT64_C(                   0),  INT64_C(                   0), -INT64_C(                   1),  INT64_C(                   0),
       INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),
       INT64_C(                   0), -INT64_C(                   1), -INT64_C(                   1),  INT64_C(                   0),
      -INT64_C(                   1),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0) };
  static const simde_float64 a = SIMDE_FLOAT64_C(  -983.43);
  static const simde_float64 e[] =
    { SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(  -983.43),
      SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(  -983.43), SIMDE_FLOAT64_C(  -983.43),
      SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(  -983.43), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00),
      SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00),
      SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(  -983.43), SIMDE_FLOAT64_C(     0.00),
      SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00),
      SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00),
      SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(  -983.43), SIMDE_FLOAT64_C(  -983.43), SIMDE_FLOAT64_C(     0.00),
      SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(  -983.43),
      SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00),
      SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00),
      SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00),
      SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00),
      SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00),
      SIMDE_FLOAT64_C(  -983.43), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(  -983.43), SIMDE_FLOAT64_C(     0.00),
      SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(  -983.43), SIMDE_FLOAT64_C(     0.00),
      SIMDE_FLOAT64_C(  -983.43), SIMDE_FLOAT64_C(  -983.43), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(  -983.43),
      SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00),
      SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(  -983.43), SIMDE_FLOAT64_C(     0.00),
      SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00),
      SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(  -983.43), SIMDE_FLOAT64_C(  -983.43), SIMDE_FLOAT64_C(     0.00),
      SIMDE_FLOAT64_C(  -983.43), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00) };

  static simde_float64 r[sizeof(e) / sizeof(e[0])];
  static const int32_t len = HEDLEY_STATIC_CAST(int32_t, sizeof(e) / sizeof(e[0]));
  int32_t i = 0;
  simde_svbool_t pg = simde_svwhilelt_b64_s32(i, len);
  while (simde_svptest_first(simde_svptrue_b64(), pg)) {
    simde_svfloat64_t rv;
    simde_svbool_t pv;

    pv = simde_svcmplt_s64(pg, simde_svld1_s64(pg, &(p[i])), simde_svdup_n_s64(INT64_C(0)));
    rv = simde_svdup_n_f64_z(pv, a);

    simde_svst1_f64(pg, &(r[i]), rv);

    i += simde_svcntd();
    pg = simde_svwhilelt_b64_s32(i, len);
  }

  simde_assert_equal_vf64(len, e, r, 1);

  return 0;
#else
  simde_float64 a, e[1024 / sizeof(int64_t)];
  int64_t p[1024 / sizeof(int64_t)];
  int64_t len;

  fputc('\n', stdout);

  len = simde_test_codegen_random_i64() & ((sizeof(e) / sizeof(e[0])) - 1);
  simde_test_codegen_random_memory(sizeof(p), HEDLEY_REINTERPRET_CAST(uint8_t*, p));
  a = simde_test_codegen_random_f64(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));

  int64_t i = 0;
  simde_svbool_t pg = simde_svwhilelt_b64_s32(i, len);
  while (simde_svptest_first(simde_svptrue_b64(), pg)) {
    simde_svfloat64_t ev;
    simde_svbool_t pv;

    pv = simde_svcmplt_s64(pg, simde_svld1_s64(pg, &(p[i])), simde_svdup_n_s64(0));
    ev = simde_svdup_n_f64_z(pv, a);

    simde_svst1_f64(pg, &(e[i]), ev);
    simde_svst1_s64(pg, &(p[i]), simde_svdup_n_s64_z(pv, ~INT64_C(0)));

    i += simde_svcntd();
    pg = simde_svwhilelt_b64_s32(i, len);
  }

  simde_test_codegen_write_1vi64(1, HEDLEY_STATIC_CAST(size_t, len), p);
  simde_test_codegen_write_1f64(1, a);
  simde_test_codegen_write_1vf64(1, HEDLEY_STATIC_CAST(size_t, len), e);

  return 1;
#endif
}

static int
test_simde_svdup_n_f64_m (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const int64_t p[] =
    {  INT64_C(                   0),  INT64_C(                   0), -INT64_C(                   1),  INT64_C(                   0),
      -INT64_C(                   1),  INT64_C(                   0), -INT64_C(                   1),  INT64_C(                   0),
      -INT64_C(                   1),  INT64_C(                   0), -INT64_C(                   1), -INT64_C(                   1),
      -INT64_C(                   1), -INT64_C(                   1), -INT64_C(                   1), -INT64_C(                   1),
      -INT64_C(                   1), -INT64_C(                   1), -INT64_C(                   1), -INT64_C(                   1),
       INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),
      -INT64_C(                   1),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),
      -INT64_C(                   1), -INT64_C(                   1), -INT64_C(                   1), -INT64_C(                   1),
       INT64_C(                   0), -INT64_C(                   1), -INT64_C(                   1), -INT64_C(                   1),
       INT64_C(                   0), -INT64_C(                   1), -INT64_C(                   1), -INT64_C(                   1),
      -INT64_C(                   1),  INT64_C(                   0), -INT64_C(                   1), -INT64_C(                   1),
      -INT64_C(                   1),  INT64_C(                   0),  INT64_C(                   0), -INT64_C(                   1),
       INT64_C(                   0), -INT64_C(                   1),  INT64_C(                   0),  INT64_C(                   0),
       INT64_C(                   0), -INT64_C(                   1),  INT64_C(                   0), -INT64_C(                   1),
      -INT64_C(                   1),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),
       INT64_C(                   0),  INT64_C(                   0), -INT64_C(                   1), -INT64_C(                   1),
       INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0), -INT64_C(                   1),
       INT64_C(                   0), -INT64_C(                   1),  INT64_C(                   0),  INT64_C(                   0),
       INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),
      -INT64_C(                   1),  INT64_C(                   0), -INT64_C(                   1),  INT64_C(                   0) };
  static const simde_float64 a[] =
    { SIMDE_FLOAT64_C(   625.95), SIMDE_FLOAT64_C(  -336.50), SIMDE_FLOAT64_C(   -44.53), SIMDE_FLOAT64_C(   996.85),
      SIMDE_FLOAT64_C(  -212.87), SIMDE_FLOAT64_C(  -442.74), SIMDE_FLOAT64_C(   267.77), SIMDE_FLOAT64_C(  -642.53),
      SIMDE_FLOAT64_C(  -411.25), SIMDE_FLOAT64_C(   508.19), SIMDE_FLOAT64_C(  -111.61), SIMDE_FLOAT64_C(   922.74),
      SIMDE_FLOAT64_C(  -645.51), SIMDE_FLOAT64_C(   460.13), SIMDE_FLOAT64_C(   534.95), SIMDE_FLOAT64_C(  -598.06),
      SIMDE_FLOAT64_C(  -800.94), SIMDE_FLOAT64_C(  -761.70), SIMDE_FLOAT64_C(   145.08), SIMDE_FLOAT64_C(   656.88),
      SIMDE_FLOAT64_C(   285.41), SIMDE_FLOAT64_C(   929.96), SIMDE_FLOAT64_C(  -981.70), SIMDE_FLOAT64_C(   406.94),
      SIMDE_FLOAT64_C(  -647.74), SIMDE_FLOAT64_C(    61.80), SIMDE_FLOAT64_C(  -219.64), SIMDE_FLOAT64_C(  -659.69),
      SIMDE_FLOAT64_C(  -750.85), SIMDE_FLOAT64_C(    22.10), SIMDE_FLOAT64_C(    47.70), SIMDE_FLOAT64_C(   875.10),
      SIMDE_FLOAT64_C(   685.60), SIMDE_FLOAT64_C(  -996.82), SIMDE_FLOAT64_C(   871.95), SIMDE_FLOAT64_C(  -527.27),
      SIMDE_FLOAT64_C(  -439.56), SIMDE_FLOAT64_C(   139.72), SIMDE_FLOAT64_C(  -169.81), SIMDE_FLOAT64_C(   149.18),
      SIMDE_FLOAT64_C(  -352.10), SIMDE_FLOAT64_C(   718.58), SIMDE_FLOAT64_C(    71.93), SIMDE_FLOAT64_C(     2.40),
      SIMDE_FLOAT64_C(   178.71), SIMDE_FLOAT64_C(  -393.12), SIMDE_FLOAT64_C(   404.33), SIMDE_FLOAT64_C(   377.77),
      SIMDE_FLOAT64_C(  -154.83), SIMDE_FLOAT64_C(  -450.59), SIMDE_FLOAT64_C(    34.65), SIMDE_FLOAT64_C(  -869.42),
      SIMDE_FLOAT64_C(  -520.63), SIMDE_FLOAT64_C(    52.96), SIMDE_FLOAT64_C(   537.53), SIMDE_FLOAT64_C(  -168.36),
      SIMDE_FLOAT64_C(  -885.25), SIMDE_FLOAT64_C(  -682.11), SIMDE_FLOAT64_C(   171.95), SIMDE_FLOAT64_C(  -636.09),
      SIMDE_FLOAT64_C(   339.98), SIMDE_FLOAT64_C(  -780.35), SIMDE_FLOAT64_C(  -760.99), SIMDE_FLOAT64_C(    25.58),
      SIMDE_FLOAT64_C(  -777.17), SIMDE_FLOAT64_C(  -889.04), SIMDE_FLOAT64_C(   498.31), SIMDE_FLOAT64_C(  -216.73),
      SIMDE_FLOAT64_C(   250.68), SIMDE_FLOAT64_C(  -671.50), SIMDE_FLOAT64_C(   932.45), SIMDE_FLOAT64_C(   898.58),
      SIMDE_FLOAT64_C(  -952.92), SIMDE_FLOAT64_C(     4.38), SIMDE_FLOAT64_C(   -99.02), SIMDE_FLOAT64_C(   225.79),
      SIMDE_FLOAT64_C(   611.25), SIMDE_FLOAT64_C(  -694.69), SIMDE_FLOAT64_C(  -396.44), SIMDE_FLOAT64_C(  -543.58) };
  static const simde_float64 b = SIMDE_FLOAT64_C(  -145.28);
  static const simde_float64 e[] =
    { SIMDE_FLOAT64_C(   625.95), SIMDE_FLOAT64_C(  -336.50), SIMDE_FLOAT64_C(  -145.28), SIMDE_FLOAT64_C(   996.85),
      SIMDE_FLOAT64_C(  -145.28), SIMDE_FLOAT64_C(  -442.74), SIMDE_FLOAT64_C(  -145.28), SIMDE_FLOAT64_C(  -642.53),
      SIMDE_FLOAT64_C(  -145.28), SIMDE_FLOAT64_C(   508.19), SIMDE_FLOAT64_C(  -145.28), SIMDE_FLOAT64_C(  -145.28),
      SIMDE_FLOAT64_C(  -145.28), SIMDE_FLOAT64_C(  -145.28), SIMDE_FLOAT64_C(  -145.28), SIMDE_FLOAT64_C(  -145.28),
      SIMDE_FLOAT64_C(  -145.28), SIMDE_FLOAT64_C(  -145.28), SIMDE_FLOAT64_C(  -145.28), SIMDE_FLOAT64_C(  -145.28),
      SIMDE_FLOAT64_C(   285.41), SIMDE_FLOAT64_C(   929.96), SIMDE_FLOAT64_C(  -981.70), SIMDE_FLOAT64_C(   406.94),
      SIMDE_FLOAT64_C(  -145.28), SIMDE_FLOAT64_C(    61.80), SIMDE_FLOAT64_C(  -219.64), SIMDE_FLOAT64_C(  -659.69),
      SIMDE_FLOAT64_C(  -145.28), SIMDE_FLOAT64_C(  -145.28), SIMDE_FLOAT64_C(  -145.28), SIMDE_FLOAT64_C(  -145.28),
      SIMDE_FLOAT64_C(   685.60), SIMDE_FLOAT64_C(  -145.28), SIMDE_FLOAT64_C(  -145.28), SIMDE_FLOAT64_C(  -145.28),
      SIMDE_FLOAT64_C(  -439.56), SIMDE_FLOAT64_C(  -145.28), SIMDE_FLOAT64_C(  -145.28), SIMDE_FLOAT64_C(  -145.28),
      SIMDE_FLOAT64_C(  -145.28), SIMDE_FLOAT64_C(   718.58), SIMDE_FLOAT64_C(  -145.28), SIMDE_FLOAT64_C(  -145.28),
      SIMDE_FLOAT64_C(  -145.28), SIMDE_FLOAT64_C(  -393.12), SIMDE_FLOAT64_C(   404.33), SIMDE_FLOAT64_C(  -145.28),
      SIMDE_FLOAT64_C(  -154.83), SIMDE_FLOAT64_C(  -145.28), SIMDE_FLOAT64_C(    34.65), SIMDE_FLOAT64_C(  -869.42),
      SIMDE_FLOAT64_C(  -520.63), SIMDE_FLOAT64_C(  -145.28), SIMDE_FLOAT64_C(   537.53), SIMDE_FLOAT64_C(  -145.28),
      SIMDE_FLOAT64_C(  -145.28), SIMDE_FLOAT64_C(  -682.11), SIMDE_FLOAT64_C(   171.95), SIMDE_FLOAT64_C(  -636.09),
      SIMDE_FLOAT64_C(   339.98), SIMDE_FLOAT64_C(  -780.35), SIMDE_FLOAT64_C(  -145.28), SIMDE_FLOAT64_C(  -145.28),
      SIMDE_FLOAT64_C(  -777.17), SIMDE_FLOAT64_C(  -889.04), SIMDE_FLOAT64_C(   498.31), SIMDE_FLOAT64_C(  -145.28),
      SIMDE_FLOAT64_C(   250.68), SIMDE_FLOAT64_C(  -145.28), SIMDE_FLOAT64_C(   932.45), SIMDE_FLOAT64_C(   898.58),
      SIMDE_FLOAT64_C(  -952.92), SIMDE_FLOAT64_C(     4.38), SIMDE_FLOAT64_C(   -99.02), SIMDE_FLOAT64_C(   225.79),
      SIMDE_FLOAT64_C(  -145.28), SIMDE_FLOAT64_C(  -694.69), SIMDE_FLOAT64_C(  -145.28), SIMDE_FLOAT64_C(  -543.58) };

  static simde_float64 r[sizeof(e) / sizeof(e[0])];
  static const int32_t len = HEDLEY_STATIC_CAST(int32_t, sizeof(e) / sizeof(e[0]));
  int32_t i = 0;
  simde_svbool_t pg = simde_svwhilelt_b64_s32(i, len);
  while (simde_svptest_first(simde_svptrue_b64(), pg)) {
    simde_svfloat64_t
      rv,
      av = simde_svld1_f64(pg, &(a[i]));
    simde_svbool_t pv;

    pv = simde_svcmplt_s64(pg, simde_svld1_s64(pg, &(p[i])), simde_svdup_n_s64(INT64_C(0)));
    rv = simde_svdup_n_f64_m(av, pv, b);

    simde_svst1_f64(pg, &(r[i]), rv);

    i += simde_svcntd();
    pg = simde_svwhilelt_b64_s32(i, len);
  }

  simde_assert_equal_vf64(len, e, r, 1);

  return 0;
#else
  int64_t p[1024 / sizeof(int64_t)];
  simde_float64 a[1024 / sizeof(int64_t)], b, e[1024 / sizeof(int64_t)];
  int32_t len = simde_test_arm_sve_random_length(sizeof(e), sizeof(e[0]));

  fputc('\n', stdout);

  simde_test_codegen_random_memory(sizeof(p), HEDLEY_REINTERPRET_CAST(uint8_t*, p));
  simde_test_codegen_random_vf64(HEDLEY_STATIC_CAST(size_t, len), a, SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
  b = simde_test_codegen_random_f64(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));

  int32_t i = 0;
  simde_svbool_t pg = simde_svwhilelt_b64_s32(i, len);
  while (simde_svptest_first(simde_svptrue_b64(), pg)) {
    simde_svfloat64_t av, ev;
    simde_svbool_t pv;

    pv = simde_svcmplt_s64(pg, simde_svld1_s64(pg, &(p[i])), simde_svdup_n_s64(0));
    av = simde_svld1_f64(pg, &(a[i]));

    ev = simde_svdup_n_f64_m(av, pv, b);

    simde_svst1_f64(pg, &(e[i]), ev);
    simde_svst1_s64(pg, &(p[i]), simde_svdup_n_s64_z(pv, ~INT64_C(0)));

    i += simde_svcntd();
    pg = simde_svwhilelt_b64_s32(i, len);
  }

  simde_test_codegen_write_1vi64(1, HEDLEY_STATIC_CAST(size_t, len), p);
  simde_test_codegen_write_1vf64(1, HEDLEY_STATIC_CAST(size_t, len), a);
  simde_test_codegen_write_1f64(1, b);
  simde_test_codegen_write_1vf64(1, HEDLEY_STATIC_CAST(size_t, len), e);

  return 1;
#endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(svdup_n_s8)
SIMDE_TEST_FUNC_LIST_ENTRY(svdup_n_s8_z)
SIMDE_TEST_FUNC_LIST_ENTRY(svdup_n_s8_m)
SIMDE_TEST_FUNC_LIST_ENTRY(svdup_n_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(svdup_n_s16_z)
SIMDE_TEST_FUNC_LIST_ENTRY(svdup_n_s16_m)
SIMDE_TEST_FUNC_LIST_ENTRY(svdup_n_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(svdup_n_s32_z)
SIMDE_TEST_FUNC_LIST_ENTRY(svdup_n_s32_m)
SIMDE_TEST_FUNC_LIST_ENTRY(svdup_n_s64)
SIMDE_TEST_FUNC_LIST_ENTRY(svdup_n_s64_z)
SIMDE_TEST_FUNC_LIST_ENTRY(svdup_n_s64_m)
SIMDE_TEST_FUNC_LIST_ENTRY(svdup_n_u8)
SIMDE_TEST_FUNC_LIST_ENTRY(svdup_n_u8_z)
SIMDE_TEST_FUNC_LIST_ENTRY(svdup_n_u8_m)
SIMDE_TEST_FUNC_LIST_ENTRY(svdup_n_u16)
SIMDE_TEST_FUNC_LIST_ENTRY(svdup_n_u16_z)
SIMDE_TEST_FUNC_LIST_ENTRY(svdup_n_u16_m)
SIMDE_TEST_FUNC_LIST_ENTRY(svdup_n_u32)
SIMDE_TEST_FUNC_LIST_ENTRY(svdup_n_u32_z)
SIMDE_TEST_FUNC_LIST_ENTRY(svdup_n_u32_m)
SIMDE_TEST_FUNC_LIST_ENTRY(svdup_n_u64)
SIMDE_TEST_FUNC_LIST_ENTRY(svdup_n_u64_z)
SIMDE_TEST_FUNC_LIST_ENTRY(svdup_n_u64_m)
SIMDE_TEST_FUNC_LIST_ENTRY(svdup_n_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(svdup_n_f32_z)
SIMDE_TEST_FUNC_LIST_ENTRY(svdup_n_f32_m)
SIMDE_TEST_FUNC_LIST_ENTRY(svdup_n_f64)
SIMDE_TEST_FUNC_LIST_ENTRY(svdup_n_f64_z)
SIMDE_TEST_FUNC_LIST_ENTRY(svdup_n_f64_m)
SIMDE_TEST_FUNC_LIST_END

#include "test-sve-footer.h"
