#define SIMDE_TEST_MIPS_MSA_INSN st

#include "test-msa.h"
#include "../../../simde/mips/msa/st.h"

static int
test_simde_st_b (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int8_t  a[16];
    int8_t ru[32];
    int8_t r0[32];
    int8_t r4[32];
    int8_t r16[32];
  } test_vec[] = {
    { { -INT8_C(  57), -INT8_C( 125),  INT8_C(   1), -INT8_C(  20),  INT8_C(  70),  INT8_C( 112), -INT8_C(  80),  INT8_C(  85),
         INT8_C(  42), -INT8_C(   9),  INT8_C( 107),  INT8_C(  90),  INT8_C(  91),  INT8_C(  25),  INT8_C(   1),  INT8_C(   7) },
      {  INT8_C(  70), -INT8_C( 102),  INT8_C(  84),  INT8_C(  74), -INT8_C(  47), -INT8_C(  60), -INT8_C(   4), -INT8_C(   9),
        -INT8_C(  39),  INT8_C(  91), -INT8_C(  63), -INT8_C( 127),  INT8_C(  56), -INT8_C(  32),  INT8_C(  34), -INT8_C(   1),
         INT8_C(  99),  INT8_C(  35), -INT8_C(  21), -INT8_C(  86), -INT8_C( 109), -INT8_C( 101), -INT8_C(   1), -INT8_C(  67),
        -INT8_C( 110),  INT8_C( 106),  INT8_C(  24), -INT8_C(  18), -INT8_C( 125),  INT8_C(  25), -INT8_C(  11), -INT8_C(  54) },
      { -INT8_C(  57), -INT8_C( 125),  INT8_C(   1), -INT8_C(  20),  INT8_C(  70),  INT8_C( 112), -INT8_C(  80),  INT8_C(  85),
         INT8_C(  42), -INT8_C(   9),  INT8_C( 107),  INT8_C(  90),  INT8_C(  91),  INT8_C(  25),  INT8_C(   1),  INT8_C(   7),
         INT8_C(  99),  INT8_C(  35), -INT8_C(  21), -INT8_C(  86), -INT8_C( 109), -INT8_C( 101), -INT8_C(   1), -INT8_C(  67),
        -INT8_C( 110),  INT8_C( 106),  INT8_C(  24), -INT8_C(  18), -INT8_C( 125),  INT8_C(  25), -INT8_C(  11), -INT8_C(  54) },
      {  INT8_C(  70), -INT8_C( 102),  INT8_C(  84),  INT8_C(  74), -INT8_C(  57), -INT8_C( 125),  INT8_C(   1), -INT8_C(  20),
         INT8_C(  70),  INT8_C( 112), -INT8_C(  80),  INT8_C(  85),  INT8_C(  42), -INT8_C(   9),  INT8_C( 107),  INT8_C(  90),
         INT8_C(  91),  INT8_C(  25),  INT8_C(   1),  INT8_C(   7), -INT8_C( 109), -INT8_C( 101), -INT8_C(   1), -INT8_C(  67),
        -INT8_C( 110),  INT8_C( 106),  INT8_C(  24), -INT8_C(  18), -INT8_C( 125),  INT8_C(  25), -INT8_C(  11), -INT8_C(  54) },
      {  INT8_C(  70), -INT8_C( 102),  INT8_C(  84),  INT8_C(  74), -INT8_C(  47), -INT8_C(  60), -INT8_C(   4), -INT8_C(   9),
        -INT8_C(  39),  INT8_C(  91), -INT8_C(  63), -INT8_C( 127),  INT8_C(  56), -INT8_C(  32),  INT8_C(  34), -INT8_C(   1),
        -INT8_C(  57), -INT8_C( 125),  INT8_C(   1), -INT8_C(  20),  INT8_C(  70),  INT8_C( 112), -INT8_C(  80),  INT8_C(  85),
         INT8_C(  42), -INT8_C(   9),  INT8_C( 107),  INT8_C(  90),  INT8_C(  91),  INT8_C(  25),  INT8_C(   1),  INT8_C(   7) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    int8_t r[sizeof(test_vec[i].ru)];
    simde_v16i8 a = simde_msa_ld_b(test_vec[i].a, 0);

    simde_memcpy(r, test_vec[i].ru, sizeof(r));
    simde_msa_st_b(a, r, 0);
    simde_assert_equal_vi8(sizeof(r), test_vec[i].r0, r);

    simde_memcpy(r, test_vec[i].ru, sizeof(r));
    simde_msa_st_b(a, r, 4);
    simde_assert_equal_vi8(sizeof(r), test_vec[i].r4, r);

    simde_memcpy(r, test_vec[i].ru, sizeof(r));
    simde_msa_st_b(a, r, 16);
    simde_assert_equal_vi8(sizeof(r), test_vec[i].r16, r);
  }

  return 0;
#else
  fputc('\n', stdout);
  simde_v16i8 a = simde_test_msa_v16i8_random();
  int8_t r0[32], r4[32], r16[32], ru[32];

  simde_test_codegen_random_memory(sizeof(ru), HEDLEY_REINTERPRET_CAST(uint8_t*, ru));
  simde_memcpy(r0, ru, sizeof(ru));
  simde_memcpy(r4, ru, sizeof(ru));
  simde_memcpy(r16, ru, sizeof(ru));

  simde_msa_st_b(a, r0, 0);
  simde_msa_st_b(a, r4, 4);
  simde_msa_st_b(a, r16, 16);

  simde_test_msa_v16i8_write(2, a, SIMDE_TEST_VEC_POS_FIRST);
  simde_test_codegen_write_vi8(2, sizeof(ru) / sizeof(ru[0]), ru, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_codegen_write_vi8(2, sizeof(r0) / sizeof(r0[0]), r0, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_codegen_write_vi8(2, sizeof(r4) / sizeof(r4[0]), r4, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_codegen_write_vi8(2, sizeof(r16) / sizeof(r16[0]), r16, SIMDE_TEST_VEC_POS_LAST);

  return 1;
#endif
}

static int
test_simde_st_h (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int16_t  a[8];
    int16_t ru[16];
    int16_t r0[16];
    int16_t r4[16];
    int16_t r16[16];
  } test_vec[] = {
    { { -INT16_C( 20637), -INT16_C( 14769), -INT16_C( 10501), -INT16_C( 28394),  INT16_C( 11194), -INT16_C( 21974), -INT16_C( 29026), -INT16_C( 11367) },
      {  INT16_C(  7296),  INT16_C(  1056),  INT16_C( 26076),  INT16_C( 10905), -INT16_C( 13490),  INT16_C(  5517),  INT16_C( 29922),  INT16_C( 17948),
         INT16_C( 27427),  INT16_C(  7692),  INT16_C(  9025), -INT16_C(  1105), -INT16_C(  9906), -INT16_C(  4955),  INT16_C( 15975), -INT16_C(  5953) },
      { -INT16_C( 20637), -INT16_C( 14769), -INT16_C( 10501), -INT16_C( 28394),  INT16_C( 11194), -INT16_C( 21974), -INT16_C( 29026), -INT16_C( 11367),
         INT16_C( 27427),  INT16_C(  7692),  INT16_C(  9025), -INT16_C(  1105), -INT16_C(  9906), -INT16_C(  4955),  INT16_C( 15975), -INT16_C(  5953) },
      {  INT16_C(  7296),  INT16_C(  1056), -INT16_C( 20637), -INT16_C( 14769), -INT16_C( 10501), -INT16_C( 28394),  INT16_C( 11194), -INT16_C( 21974),
        -INT16_C( 29026), -INT16_C( 11367),  INT16_C(  9025), -INT16_C(  1105), -INT16_C(  9906), -INT16_C(  4955),  INT16_C( 15975), -INT16_C(  5953) },
      {  INT16_C(  7296),  INT16_C(  1056),  INT16_C( 26076),  INT16_C( 10905), -INT16_C( 13490),  INT16_C(  5517),  INT16_C( 29922),  INT16_C( 17948),
        -INT16_C( 20637), -INT16_C( 14769), -INT16_C( 10501), -INT16_C( 28394),  INT16_C( 11194), -INT16_C( 21974), -INT16_C( 29026), -INT16_C( 11367) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    int16_t r[sizeof(test_vec[i].ru) / sizeof(test_vec[i].ru[0])];
    simde_v8i16 a = simde_msa_ld_h(test_vec[i].a, 0);

    simde_memcpy(r, test_vec[i].ru, sizeof(r));
    simde_msa_st_h(a, r, 0);
    simde_assert_equal_vi16(sizeof(r) / sizeof(r[0]), test_vec[i].r0, r);

    simde_memcpy(r, test_vec[i].ru, sizeof(r));
    simde_msa_st_h(a, r, 4);
    simde_assert_equal_vi16(sizeof(r) / sizeof(r[0]), test_vec[i].r4, r);

    simde_memcpy(r, test_vec[i].ru, sizeof(r));
    simde_msa_st_h(a, r, 16);
    simde_assert_equal_vi16(sizeof(r) / sizeof(r[0]), test_vec[i].r16, r);
  }

  return 0;
#else
  fputc('\n', stdout);
  simde_v8i16 a = simde_test_msa_v8i16_random();
  int16_t r0[16], r4[16], r16[16], ru[16];

  simde_test_codegen_random_memory(sizeof(ru), HEDLEY_REINTERPRET_CAST(uint8_t*, ru));
  simde_memcpy(r0, ru, sizeof(ru));
  simde_memcpy(r4, ru, sizeof(ru));
  simde_memcpy(r16, ru, sizeof(ru));

  simde_msa_st_h(a, r0, 0);
  simde_msa_st_h(a, r4, 4);
  simde_msa_st_h(a, r16, 16);

  simde_test_msa_v8i16_write(2, a, SIMDE_TEST_VEC_POS_FIRST);
  simde_test_codegen_write_vi16(2, sizeof(ru) / sizeof(ru[0]), ru, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_codegen_write_vi16(2, sizeof(r0) / sizeof(r0[0]), r0, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_codegen_write_vi16(2, sizeof(r4) / sizeof(r4[0]), r4, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_codegen_write_vi16(2, sizeof(r16) / sizeof(r16[0]), r16, SIMDE_TEST_VEC_POS_LAST);

  return 1;
#endif
}

static int
test_simde_st_w (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int32_t  a[4];
    int32_t ru[8];
    int32_t r0[8];
    int32_t r4[8];
    int32_t r16[8];
  } test_vec[] = {
    { {  INT32_C(   921493338), -INT32_C(  1822390971),  INT32_C(   866709072), -INT32_C(  2055617438) },
      {  INT32_C(  1889764655), -INT32_C(   160738648), -INT32_C(  1813901269), -INT32_C(  1451515569), -INT32_C(   958371967),  INT32_C(  1029259501), -INT32_C(  1871707858), -INT32_C(   199890491) },
      {  INT32_C(   921493338), -INT32_C(  1822390971),  INT32_C(   866709072), -INT32_C(  2055617438), -INT32_C(   958371967),  INT32_C(  1029259501), -INT32_C(  1871707858), -INT32_C(   199890491) },
      {  INT32_C(  1889764655),  INT32_C(   921493338), -INT32_C(  1822390971),  INT32_C(   866709072), -INT32_C(  2055617438),  INT32_C(  1029259501), -INT32_C(  1871707858), -INT32_C(   199890491) },
      {  INT32_C(  1889764655), -INT32_C(   160738648), -INT32_C(  1813901269), -INT32_C(  1451515569),  INT32_C(   921493338), -INT32_C(  1822390971),  INT32_C(   866709072), -INT32_C(  2055617438) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    int32_t r[sizeof(test_vec[i].ru) / sizeof(test_vec[i].ru[0])];
    simde_v4i32 a = simde_msa_ld_w(test_vec[i].a, 0);

    simde_memcpy(r, test_vec[i].ru, sizeof(r));
    simde_msa_st_w(a, r, 0);
    simde_assert_equal_vi32(sizeof(r) / sizeof(r[0]), test_vec[i].r0, r);

    simde_memcpy(r, test_vec[i].ru, sizeof(r));
    simde_msa_st_w(a, r, 4);
    simde_assert_equal_vi32(sizeof(r) / sizeof(r[0]), test_vec[i].r4, r);

    simde_memcpy(r, test_vec[i].ru, sizeof(r));
    simde_msa_st_w(a, r, 16);
    simde_assert_equal_vi32(sizeof(r) / sizeof(r[0]), test_vec[i].r16, r);
  }

  return 0;
#else
  fputc('\n', stdout);
  simde_v4i32 a = simde_test_msa_v4i32_random();
  int32_t r0[8], r4[8], r16[8], ru[8];

  simde_test_codegen_random_memory(sizeof(ru), HEDLEY_REINTERPRET_CAST(uint8_t*, ru));
  simde_memcpy(r0, ru, sizeof(ru));
  simde_memcpy(r4, ru, sizeof(ru));
  simde_memcpy(r16, ru, sizeof(ru));

  simde_msa_st_w(a, r0, 0);
  simde_msa_st_w(a, r4, 4);
  simde_msa_st_w(a, r16, 16);

  simde_test_msa_v4i32_write(2, a, SIMDE_TEST_VEC_POS_FIRST);
  simde_test_codegen_write_vi32(2, sizeof(ru) / sizeof(ru[0]), ru, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_codegen_write_vi32(2, sizeof(r0) / sizeof(r0[0]), r0, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_codegen_write_vi32(2, sizeof(r4) / sizeof(r4[0]), r4, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_codegen_write_vi32(2, sizeof(r16) / sizeof(r16[0]), r16, SIMDE_TEST_VEC_POS_LAST);

  return 1;
#endif
}

static int
test_simde_st_d (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int64_t  a[2];
    int64_t ru[4];
    int64_t r0[4];
    int64_t r8[4];
    int64_t r16[4];
  } test_vec[] = {
    { { -INT64_C( 1211907635136411288),  INT64_C( 6532010588549242016) },
      {  INT64_C( 1263295964925401521),  INT64_C(  594567094622189119),  INT64_C( 7924218561106238620), -INT64_C( 7478857305109526058) },
      { -INT64_C( 1211907635136411288),  INT64_C( 6532010588549242016),  INT64_C( 7924218561106238620), -INT64_C( 7478857305109526058) },
      {  INT64_C( 1263295964925401521), -INT64_C( 1211907635136411288),  INT64_C( 6532010588549242016), -INT64_C( 7478857305109526058) },
      {  INT64_C( 1263295964925401521),  INT64_C(  594567094622189119), -INT64_C( 1211907635136411288),  INT64_C( 6532010588549242016) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    int64_t r[sizeof(test_vec[i].ru) / sizeof(test_vec[i].ru[0])];
    simde_v2i64 a = simde_msa_ld_d(test_vec[i].a, 0);

    simde_memcpy(r, test_vec[i].ru, sizeof(r));
    simde_msa_st_d(a, r, 0);
    simde_assert_equal_vi64(sizeof(r) / sizeof(r[0]), test_vec[i].r0, r);

    simde_memcpy(r, test_vec[i].ru, sizeof(r));
    simde_msa_st_d(a, r, 8);
    simde_assert_equal_vi64(sizeof(r) / sizeof(r[0]), test_vec[i].r8, r);

    simde_memcpy(r, test_vec[i].ru, sizeof(r));
    simde_msa_st_d(a, r, 16);
    simde_assert_equal_vi64(sizeof(r) / sizeof(r[0]), test_vec[i].r16, r);
  }

  return 0;
#else
  fputc('\n', stdout);
  simde_v2i64 a = simde_test_msa_v2i64_random();
  int64_t r0[4], r8[4], r16[4], ru[4];

  simde_test_codegen_random_memory(sizeof(ru), HEDLEY_REINTERPRET_CAST(uint8_t*, ru));
  simde_memcpy(r0, ru, sizeof(ru));
  simde_memcpy(r8, ru, sizeof(ru));
  simde_memcpy(r16, ru, sizeof(ru));

  simde_msa_st_d(a, r0, 0);
  simde_msa_st_d(a, r8, 8);
  simde_msa_st_d(a, r16, 16);

  simde_test_msa_v2i64_write(2, a, SIMDE_TEST_VEC_POS_FIRST);
  simde_test_codegen_write_vi64(2, sizeof(ru) / sizeof(ru[0]), ru, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_codegen_write_vi64(2, sizeof(r0) / sizeof(r0[0]), r0, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_codegen_write_vi64(2, sizeof(r8) / sizeof(r8[0]), r8, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_codegen_write_vi64(2, sizeof(r16) / sizeof(r16[0]), r16, SIMDE_TEST_VEC_POS_LAST);

  return 1;
#endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(st_b)
SIMDE_TEST_FUNC_LIST_ENTRY(st_h)
SIMDE_TEST_FUNC_LIST_ENTRY(st_w)
SIMDE_TEST_FUNC_LIST_ENTRY(st_d)
SIMDE_TEST_FUNC_LIST_END

#include "test-msa-footer.h"
