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

SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(svdup_n_s8)
SIMDE_TEST_FUNC_LIST_ENTRY(svdup_n_s8_z)
SIMDE_TEST_FUNC_LIST_ENTRY(svdup_n_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(svdup_n_s16_z)
SIMDE_TEST_FUNC_LIST_ENTRY(svdup_n_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(svdup_n_s32_z)
SIMDE_TEST_FUNC_LIST_ENTRY(svdup_n_s64)
SIMDE_TEST_FUNC_LIST_ENTRY(svdup_n_s64_z)
SIMDE_TEST_FUNC_LIST_ENTRY(svdup_n_u8)
SIMDE_TEST_FUNC_LIST_ENTRY(svdup_n_u8_z)
SIMDE_TEST_FUNC_LIST_ENTRY(svdup_n_u16)
SIMDE_TEST_FUNC_LIST_ENTRY(svdup_n_u16_z)
SIMDE_TEST_FUNC_LIST_ENTRY(svdup_n_u32)
SIMDE_TEST_FUNC_LIST_ENTRY(svdup_n_u32_z)
SIMDE_TEST_FUNC_LIST_ENTRY(svdup_n_u64)
SIMDE_TEST_FUNC_LIST_ENTRY(svdup_n_u64_z)
SIMDE_TEST_FUNC_LIST_ENTRY(svdup_n_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(svdup_n_f32_z)
SIMDE_TEST_FUNC_LIST_ENTRY(svdup_n_f64)
SIMDE_TEST_FUNC_LIST_ENTRY(svdup_n_f64_z)
SIMDE_TEST_FUNC_LIST_END

#include "test-sve-footer.h"
