#define SIMDE_TEST_MIPS_MSA_INSN ld

#include "test-msa.h"
#include "../../../simde/mips/msa/ld.h"

static int
test_simde_ld_b (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int8_t  a[32];
    int8_t r0[16];
    int8_t r4[16];
    int8_t r6[16];
  } test_vec[] = {
    { { -INT8_C(   4), -INT8_C(   4),  INT8_C(  50),  INT8_C(  32),  INT8_C(  26), -INT8_C(  60), -INT8_C( 125), -INT8_C(  46),
        -INT8_C(  36),  INT8_C(   1),  INT8_C(  53),  INT8_C(  76), -INT8_C(  77), -INT8_C(  51), -INT8_C( 115),  INT8_C( 116),
         INT8_C( 109), -INT8_C(  96),  INT8_C( 102),  INT8_C(  29),  INT8_C( 124), -INT8_C(   9), -INT8_C(  19),  INT8_C(  90),
         INT8_C(  31), -INT8_C(  94),  INT8_C(  12),  INT8_C(  48),  INT8_C(  56), -INT8_C(  23), -INT8_C(  66),  INT8_C(  52) },
      { -INT8_C(   4), -INT8_C(   4),  INT8_C(  50),  INT8_C(  32),  INT8_C(  26), -INT8_C(  60), -INT8_C( 125), -INT8_C(  46),
        -INT8_C(  36),  INT8_C(   1),  INT8_C(  53),  INT8_C(  76), -INT8_C(  77), -INT8_C(  51), -INT8_C( 115),  INT8_C( 116) },
      {  INT8_C(  26), -INT8_C(  60), -INT8_C( 125), -INT8_C(  46), -INT8_C(  36),  INT8_C(   1),  INT8_C(  53),  INT8_C(  76),
        -INT8_C(  77), -INT8_C(  51), -INT8_C( 115),  INT8_C( 116),  INT8_C( 109), -INT8_C(  96),  INT8_C( 102),  INT8_C(  29) },
      { -INT8_C( 125), -INT8_C(  46), -INT8_C(  36),  INT8_C(   1),  INT8_C(  53),  INT8_C(  76), -INT8_C(  77), -INT8_C(  51),
        -INT8_C( 115),  INT8_C( 116),  INT8_C( 109), -INT8_C(  96),  INT8_C( 102),  INT8_C(  29),  INT8_C( 124), -INT8_C(   9) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_v16i8 r0 = simde_msa_ld_b(test_vec[0].a, 0);
    simde_v16i8 r4 = simde_msa_ld_b(test_vec[0].a, 4);
    simde_v16i8 r6 = simde_msa_ld_b(test_vec[0].a, 6);

    simde_test_msa_v16i8_assert_equal(r0, simde_msa_ld_b(test_vec[i].r0, 0));
    simde_test_msa_v16i8_assert_equal(r4, simde_msa_ld_b(test_vec[i].r4, 0));
    simde_test_msa_v16i8_assert_equal(r6, simde_msa_ld_b(test_vec[i].r6, 0));
  }

  return 0;
#else
  fputc('\n', stdout);
  int8_t a[32];
  simde_test_codegen_random_memory(sizeof(a), HEDLEY_REINTERPRET_CAST(uint8_t*, a));

  simde_v16i8 r0 = simde_msa_ld_b(a, 0);
  simde_v16i8 r4 = simde_msa_ld_b(a, 4);
  simde_v16i8 r6 = simde_msa_ld_b(a, 6);

  simde_test_codegen_write_vi8(2, sizeof(a) / sizeof(a[0]), a, SIMDE_TEST_VEC_POS_FIRST);
  simde_test_msa_v16i8_write(2, r0, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_msa_v16i8_write(2, r4, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_msa_v16i8_write(2, r6, SIMDE_TEST_VEC_POS_LAST);
  return 1;
#endif
}

static int
test_simde_ld_h (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int16_t  a[32];
    int16_t r0[8];
    int16_t r4[8];
    int16_t r6[8];
  } test_vec[] = {
    { {  INT16_C( 16557), -INT16_C( 23369),  INT16_C( 10278), -INT16_C( 11242), -INT16_C( 20137), -INT16_C( 29297),  INT16_C( 16850),  INT16_C(  1170),
        -INT16_C( 17850),  INT16_C( 24888),  INT16_C( 31634), -INT16_C( 25943),  INT16_C( 22377),  INT16_C( 30863),  INT16_C(  4378), -INT16_C( 14367),
        -INT16_C( 26543),  INT16_C( 30571), -INT16_C( 32320),  INT16_C(  6219), -INT16_C(  9678),  INT16_C(  1189),  INT16_C( 14108),  INT16_C( 25097),
         INT16_C( 16881), -INT16_C( 31548),  INT16_C( 28093),  INT16_C(  9758), -INT16_C( 21052), -INT16_C(  8546),  INT16_C( 32703),  INT16_C(  4261) },
      {  INT16_C( 16557), -INT16_C( 23369),  INT16_C( 10278), -INT16_C( 11242), -INT16_C( 20137), -INT16_C( 29297),  INT16_C( 16850),  INT16_C(  1170) },
      {  INT16_C( 10278), -INT16_C( 11242), -INT16_C( 20137), -INT16_C( 29297),  INT16_C( 16850),  INT16_C(  1170), -INT16_C( 17850),  INT16_C( 24888) },
      { -INT16_C( 11242), -INT16_C( 20137), -INT16_C( 29297),  INT16_C( 16850),  INT16_C(  1170), -INT16_C( 17850),  INT16_C( 24888),  INT16_C( 31634) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_v8i16 r0 = simde_msa_ld_h(test_vec[0].a, 0);
    simde_v8i16 r4 = simde_msa_ld_h(test_vec[0].a, 4);
    simde_v8i16 r6 = simde_msa_ld_h(test_vec[0].a, 6);

    simde_test_msa_v8i16_assert_equal(r0, simde_msa_ld_h(test_vec[i].r0, 0));
    simde_test_msa_v8i16_assert_equal(r4, simde_msa_ld_h(test_vec[i].r4, 0));
    simde_test_msa_v8i16_assert_equal(r6, simde_msa_ld_h(test_vec[i].r6, 0));
  }

  return 0;
#else
  fputc('\n', stdout);
  int16_t a[32];
  simde_test_codegen_random_memory(sizeof(a), HEDLEY_REINTERPRET_CAST(uint8_t*, a));

  simde_v8i16 r0 = simde_msa_ld_h(a, 0);
  simde_v8i16 r4 = simde_msa_ld_h(a, 4);
  simde_v8i16 r6 = simde_msa_ld_h(a, 6);

  simde_test_codegen_write_vi16(2, sizeof(a) / sizeof(a[0]), a, SIMDE_TEST_VEC_POS_FIRST);
  simde_test_msa_v8i16_write(2, r0, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_msa_v8i16_write(2, r4, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_msa_v8i16_write(2, r6, SIMDE_TEST_VEC_POS_LAST);
  return 1;
#endif
}

static int
test_simde_ld_w (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int32_t  a[32];
    int32_t r0[4];
    int32_t r4[4];
    int32_t r12[4];
  } test_vec[] = {
    { { -INT32_C(  1249417923), -INT32_C(  1869806461), -INT32_C(   873572522), -INT32_C(   766434583),  INT32_C(   153610813),  INT32_C(   167269473), -INT32_C(  1035482236),  INT32_C(  1077113603),
         INT32_C(  1542896344),  INT32_C(   367821759), -INT32_C(  1008674086),  INT32_C(   982856188),  INT32_C(  2084813851), -INT32_C(  1786430704),  INT32_C(   173526022),  INT32_C(   407538495),
         INT32_C(    74661957), -INT32_C(  1659215933),  INT32_C(   912390713),  INT32_C(  1198585388), -INT32_C(  1010519117), -INT32_C(   195540498),  INT32_C(  1442754582), -INT32_C(  2140321477),
         INT32_C(  1300619657),  INT32_C(  2062196544), -INT32_C(   978302055), -INT32_C(   183689150), -INT32_C(  1044852269),  INT32_C(   817172762), -INT32_C(    58280767), -INT32_C(  2038631427) },
      { -INT32_C(  1249417923), -INT32_C(  1869806461), -INT32_C(   873572522), -INT32_C(   766434583) },
      { -INT32_C(  1869806461), -INT32_C(   873572522), -INT32_C(   766434583),  INT32_C(   153610813) },
      { -INT32_C(   766434583),  INT32_C(   153610813),  INT32_C(   167269473), -INT32_C(  1035482236) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_v4i32 r0 = simde_msa_ld_w(test_vec[0].a, 0);
    simde_v4i32 r4 = simde_msa_ld_w(test_vec[0].a, 4);
    simde_v4i32 r6 = simde_msa_ld_w(test_vec[0].a, 12);

    simde_test_msa_v4i32_assert_equal(r0, simde_msa_ld_w(test_vec[i].r0, 0));
    simde_test_msa_v4i32_assert_equal(r4, simde_msa_ld_w(test_vec[i].r4, 0));
    simde_test_msa_v4i32_assert_equal(r6, simde_msa_ld_w(test_vec[i].r12, 0));
  }

  return 0;
#else
  fputc('\n', stdout);
  int32_t a[32];
  simde_test_codegen_random_memory(sizeof(a), HEDLEY_REINTERPRET_CAST(uint8_t*, a));

  simde_v4i32 r0 = simde_msa_ld_w(a, 0);
  simde_v4i32 r4 = simde_msa_ld_w(a, 4);
  simde_v4i32 r12 = simde_msa_ld_w(a, 12);

  simde_test_codegen_write_vi32(2, sizeof(a) / sizeof(a[0]), a, SIMDE_TEST_VEC_POS_FIRST);
  simde_test_msa_v4i32_write(2, r0, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_msa_v4i32_write(2, r4, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_msa_v4i32_write(2, r12, SIMDE_TEST_VEC_POS_LAST);
  return 1;
#endif
}

static int
test_simde_ld_d (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int64_t  a[32];
    int64_t r0[2];
    int64_t r8[2];
    int64_t r16[2];
  } test_vec[] = {
    { {  INT64_C( 4219800970639638996),  INT64_C( 3620907703842324233), -INT64_C( 3807608719861876259),  INT64_C( 8565920855828704860),
         INT64_C( 8871838867427930949),  INT64_C(  714391375256624985), -INT64_C( 2101727995428217600),  INT64_C( 2661659125930040536),
        -INT64_C( 1099958483672204081), -INT64_C( 8539507099847589304),  INT64_C( 9212509583368748656),  INT64_C(    2509299829511428),
        -INT64_C( 8868435127827361178), -INT64_C( 7452484143541611136), -INT64_C( 7846844434740205837),  INT64_C( 7254877881077535869),
         INT64_C( 7877725856966176914), -INT64_C( 5430766376434840606),  INT64_C( 1608746700473577776), -INT64_C( 2458838632786244994),
         INT64_C( 8052153066682269795),  INT64_C( 8052185715862746442), -INT64_C(  577161717152280755), -INT64_C( 7461247193006751156),
         INT64_C( 7534704824938930067),  INT64_C( 8325522000381676251), -INT64_C( 8669050794158671551),  INT64_C(  857815295163507738),
         INT64_C( 5852634934252720050),  INT64_C( 2261078445954739142),  INT64_C( 3202493723402943151), -INT64_C( 3156352490002476881) },
      {  INT64_C( 4219800970639638996),  INT64_C( 3620907703842324233) },
      {  INT64_C( 3620907703842324233), -INT64_C( 3807608719861876259) },
      { -INT64_C( 3807608719861876259),  INT64_C( 8565920855828704860) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_v2i64 r0 = simde_msa_ld_d(test_vec[0].a, 0);
    simde_v2i64 r4 = simde_msa_ld_d(test_vec[0].a, 8);
    simde_v2i64 r6 = simde_msa_ld_d(test_vec[0].a, 16);

    simde_test_msa_v2i64_assert_equal(r0, simde_msa_ld_d(test_vec[i].r0, 0));
    simde_test_msa_v2i64_assert_equal(r4, simde_msa_ld_d(test_vec[i].r8, 0));
    simde_test_msa_v2i64_assert_equal(r6, simde_msa_ld_d(test_vec[i].r16, 0));
  }

  return 0;
#else
  fputc('\n', stdout);
  int64_t a[32];
  simde_test_codegen_random_memory(sizeof(a), HEDLEY_REINTERPRET_CAST(uint8_t*, a));

  simde_v2i64 r0 = simde_msa_ld_d(a, 0);
  simde_v2i64 r8 = simde_msa_ld_d(a, 8);
  simde_v2i64 r16 = simde_msa_ld_d(a, 16);

  simde_test_codegen_write_vi64(2, sizeof(a) / sizeof(a[0]), a, SIMDE_TEST_VEC_POS_FIRST);
  simde_test_msa_v2i64_write(2, r0, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_msa_v2i64_write(2, r8, SIMDE_TEST_VEC_POS_MIDDLE);
  simde_test_msa_v2i64_write(2, r16, SIMDE_TEST_VEC_POS_LAST);
  return 1;
#endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(ld_b)
SIMDE_TEST_FUNC_LIST_ENTRY(ld_h)
SIMDE_TEST_FUNC_LIST_ENTRY(ld_w)
SIMDE_TEST_FUNC_LIST_ENTRY(ld_d)
SIMDE_TEST_FUNC_LIST_END

#include "test-msa-footer.h"
