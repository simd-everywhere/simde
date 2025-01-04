#define SIMDE_TEST_ARM_NEON_INSN qshlu_n

#include "test-neon.h"
#include "../../../simde/arm/neon/qshlu_n.h"

HEDLEY_DIAGNOSTIC_PUSH
SIMDE_DIAGNOSTIC_DISABLE_UNREACHABLE_

static int
test_simde_vqshluh_n_s16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
      int16_t a;
      uint16_t r0;
      uint16_t r2;
      uint16_t r5;
      uint16_t r9;
      uint16_t r10;
      uint16_t r13;
      uint16_t r15;
    } test_vec[] = {
    { -INT16_C(  1108),
      UINT16_C(    0),
      UINT16_C(    0),
      UINT16_C(    0),
      UINT16_C(    0),
      UINT16_C(    0),
      UINT16_C(    0),
      UINT16_C(    0) },
    {  INT16_C(   115),
      UINT16_C(  115),
      UINT16_C(  460),
      UINT16_C( 3680),
      UINT16_C(58880),
           UINT16_MAX,
           UINT16_MAX,
           UINT16_MAX },
    {  INT16_C(  3529),
      UINT16_C( 3529),
      UINT16_C(14116),
           UINT16_MAX,
           UINT16_MAX,
           UINT16_MAX,
           UINT16_MAX,
           UINT16_MAX },
    {  INT16_C(   144),
      UINT16_C(  144),
      UINT16_C(  576),
      UINT16_C( 4608),
           UINT16_MAX,
           UINT16_MAX,
           UINT16_MAX,
           UINT16_MAX },
    { -INT16_C( 28545),
      UINT16_C(    0),
      UINT16_C(    0),
      UINT16_C(    0),
      UINT16_C(    0),
      UINT16_C(    0),
      UINT16_C(    0),
      UINT16_C(    0) },
    {  INT16_C( 26435),
      UINT16_C(26435),
           UINT16_MAX,
           UINT16_MAX,
           UINT16_MAX,
           UINT16_MAX,
           UINT16_MAX,
           UINT16_MAX },
    { -INT16_C( 22897),
      UINT16_C(    0),
      UINT16_C(    0),
      UINT16_C(    0),
      UINT16_C(    0),
      UINT16_C(    0),
      UINT16_C(    0),
      UINT16_C(    0) },
    {  INT16_C(    29),
      UINT16_C(   29),
      UINT16_C(  116),
      UINT16_C(  928),
      UINT16_C(14848),
      UINT16_C(29696),
           UINT16_MAX,
           UINT16_MAX },
    {  INT16_C(  6552),
      UINT16_C( 6552),
      UINT16_C(26208),
           UINT16_MAX,
           UINT16_MAX,
           UINT16_MAX,
           UINT16_MAX,
           UINT16_MAX },
    {  INT16_C( 27151),
      UINT16_C(27151),
           UINT16_MAX,
           UINT16_MAX,
           UINT16_MAX,
           UINT16_MAX,
           UINT16_MAX,
           UINT16_MAX },
    { -INT16_C( 13307),
      UINT16_C(    0),
      UINT16_C(    0),
      UINT16_C(    0),
      UINT16_C(    0),
      UINT16_C(    0),
      UINT16_C(    0),
      UINT16_C(    0) },
    {  INT16_C(   253),
      UINT16_C(  253),
      UINT16_C( 1012),
      UINT16_C( 8096),
           UINT16_MAX,
           UINT16_MAX,
           UINT16_MAX,
           UINT16_MAX },
    {  INT16_C(  8965),
      UINT16_C( 8965),
      UINT16_C(35860),
           UINT16_MAX,
           UINT16_MAX,
           UINT16_MAX,
           UINT16_MAX,
           UINT16_MAX },
    {  INT16_C( 27187),
      UINT16_C(27187),
           UINT16_MAX,
           UINT16_MAX,
           UINT16_MAX,
           UINT16_MAX,
           UINT16_MAX,
           UINT16_MAX },
    {  INT16_C( 12609),
      UINT16_C(12609),
      UINT16_C(50436),
           UINT16_MAX,
           UINT16_MAX,
           UINT16_MAX,
           UINT16_MAX,
           UINT16_MAX },
    {  INT16_C(    89),
      UINT16_C(   89),
      UINT16_C(  356),
      UINT16_C( 2848),
      UINT16_C(45568),
           UINT16_MAX,
           UINT16_MAX,
           UINT16_MAX },
    {  INT16_C( 13356),
      UINT16_C(13356),
      UINT16_C(53424),
           UINT16_MAX,
           UINT16_MAX,
           UINT16_MAX,
           UINT16_MAX,
           UINT16_MAX },
    {  INT16_C(   115),
      UINT16_C(  115),
      UINT16_C(  460),
      UINT16_C( 3680),
      UINT16_C(58880),
           UINT16_MAX,
           UINT16_MAX,
           UINT16_MAX },
    { -INT16_C(   447),
      UINT16_C(    0),
      UINT16_C(    0),
      UINT16_C(    0),
      UINT16_C(    0),
      UINT16_C(    0),
      UINT16_C(    0),
      UINT16_C(    0) },
    {  INT16_C(   119),
      UINT16_C(  119),
      UINT16_C(  476),
      UINT16_C( 3808),
      UINT16_C(60928),
           UINT16_MAX,
           UINT16_MAX,
           UINT16_MAX },
    { -INT16_C( 13170),
      UINT16_C(    0),
      UINT16_C(    0),
      UINT16_C(    0),
      UINT16_C(    0),
      UINT16_C(    0),
      UINT16_C(    0),
      UINT16_C(    0) },
    {  INT16_C(  7463),
      UINT16_C( 7463),
      UINT16_C(29852),
           UINT16_MAX,
           UINT16_MAX,
           UINT16_MAX,
           UINT16_MAX,
           UINT16_MAX },
    {  INT16_C(  2930),
      UINT16_C( 2930),
      UINT16_C(11720),
           UINT16_MAX,
           UINT16_MAX,
           UINT16_MAX,
           UINT16_MAX,
           UINT16_MAX },
    {  INT16_C(  3011),
      UINT16_C( 3011),
      UINT16_C(12044),
           UINT16_MAX,
           UINT16_MAX,
           UINT16_MAX,
           UINT16_MAX,
           UINT16_MAX },
    { -INT16_C( 11740),
      UINT16_C(    0),
      UINT16_C(    0),
      UINT16_C(    0),
      UINT16_C(    0),
      UINT16_C(    0),
      UINT16_C(    0),
      UINT16_C(    0) },
    {  INT16_C( 10613),
      UINT16_C(10613),
      UINT16_C(42452),
           UINT16_MAX,
           UINT16_MAX,
           UINT16_MAX,
           UINT16_MAX,
           UINT16_MAX },
    {  INT16_C( 30878),
      UINT16_C(30878),
           UINT16_MAX,
           UINT16_MAX,
           UINT16_MAX,
           UINT16_MAX,
           UINT16_MAX,
           UINT16_MAX },
    {  INT16_C(    69),
      UINT16_C(   69),
      UINT16_C(  276),
      UINT16_C( 2208),
      UINT16_C(35328),
           UINT16_MAX,
           UINT16_MAX,
           UINT16_MAX },
    { -INT16_C(  4453),
      UINT16_C(    0),
      UINT16_C(    0),
      UINT16_C(    0),
      UINT16_C(    0),
      UINT16_C(    0),
      UINT16_C(    0),
      UINT16_C(    0) },
    {  INT16_C(   242),
      UINT16_C(  242),
      UINT16_C(  968),
      UINT16_C( 7744),
           UINT16_MAX,
           UINT16_MAX,
           UINT16_MAX,
           UINT16_MAX },
    { -INT16_C( 18913),
      UINT16_C(    0),
      UINT16_C(    0),
      UINT16_C(    0),
      UINT16_C(    0),
      UINT16_C(    0),
      UINT16_C(    0),
      UINT16_C(    0) },
    {  INT16_C( 19402),
      UINT16_C(19402),
           UINT16_MAX,
           UINT16_MAX,
           UINT16_MAX,
           UINT16_MAX,
           UINT16_MAX,
           UINT16_MAX },
    };

    for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
      int16_t a = test_vec[i].a;
      uint16_t r0 = simde_vqshluh_n_s16(a, 0);
      uint16_t r2 = simde_vqshluh_n_s16(a, 2);
      uint16_t r5 = simde_vqshluh_n_s16(a, 5);
      uint16_t r9 = simde_vqshluh_n_s16(a, 9);
      uint16_t r10 = simde_vqshluh_n_s16(a, 10);
      uint16_t r13 = simde_vqshluh_n_s16(a, 13);
      uint16_t r15 = simde_vqshluh_n_s16(a, 15);

      simde_assert_equal_u16(r0, test_vec[i].r0);
      simde_assert_equal_u16(r2, test_vec[i].r2);
      simde_assert_equal_u16(r5, test_vec[i].r5);
      simde_assert_equal_u16(r9, test_vec[i].r9);
      simde_assert_equal_u16(r10, test_vec[i].r10);
      simde_assert_equal_u16(r13, test_vec[i].r13);
      simde_assert_equal_u16(r15, test_vec[i].r15);
    }

    return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 32 ; i++) {
    int16_t a = simde_test_codegen_random_i16();
    // Ensure some reasonable number of valid test vectors.
    if ((i % 2) && (a < 0))
    {
      a = -a;
      a %= 256;
    }
    uint16_t r0 = simde_vqshluh_n_s16(a, 0);
    uint16_t r2 = simde_vqshluh_n_s16(a, 2);
    uint16_t r5 = simde_vqshluh_n_s16(a, 5);
    uint16_t r9 = simde_vqshluh_n_s16(a, 9);
    uint16_t r10 = simde_vqshluh_n_s16(a, 10);
    uint16_t r13 = simde_vqshluh_n_s16(a, 13);
    uint16_t r15 = simde_vqshluh_n_s16(a, 15);

    simde_test_codegen_write_i16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_u16(2, r0, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_u16(2, r2, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_u16(2, r5, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_u16(2, r9, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_u16(2, r10, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_u16(2, r13, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_u16(2, r15, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vqshlus_n_s32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
      int32_t a;
      uint32_t r0;
      uint32_t r2;
      uint32_t r5;
      uint32_t r9;
      uint32_t r16;
      uint32_t r24;
      uint32_t r31;
    } test_vec[] = {
    { -INT32_C(   860251280),
      UINT32_C(         0),
      UINT32_C(         0),
      UINT32_C(         0),
      UINT32_C(         0),
      UINT32_C(         0),
      UINT32_C(         0),
      UINT32_C(         0) },
    {  INT32_C(  1938561109),
      UINT32_C(1938561109),
                UINT32_MAX,
                UINT32_MAX,
                UINT32_MAX,
                UINT32_MAX,
                UINT32_MAX,
                UINT32_MAX },
    {  INT32_C(   570684325),
      UINT32_C( 570684325),
      UINT32_C(2282737300),
                UINT32_MAX,
                UINT32_MAX,
                UINT32_MAX,
                UINT32_MAX,
                UINT32_MAX },
    {  INT32_C(  1438355717),
      UINT32_C(1438355717),
                UINT32_MAX,
                UINT32_MAX,
                UINT32_MAX,
                UINT32_MAX,
                UINT32_MAX,
                UINT32_MAX },
    { -INT32_C(  2110861755),
      UINT32_C(         0),
      UINT32_C(         0),
      UINT32_C(         0),
      UINT32_C(         0),
      UINT32_C(         0),
      UINT32_C(         0),
      UINT32_C(         0) },
    {  INT32_C(   220741274),
      UINT32_C( 220741274),
      UINT32_C( 882965096),
                UINT32_MAX,
                UINT32_MAX,
                UINT32_MAX,
                UINT32_MAX,
                UINT32_MAX },
    { -INT32_C(  1436645693),
      UINT32_C(         0),
      UINT32_C(         0),
      UINT32_C(         0),
      UINT32_C(         0),
      UINT32_C(         0),
      UINT32_C(         0),
      UINT32_C(         0) },
    {  INT32_C(         166),
      UINT32_C(       166),
      UINT32_C(       664),
      UINT32_C(      5312),
      UINT32_C(     84992),
      UINT32_C(  10878976),
      UINT32_C(2785017856),
                UINT32_MAX },
    {  INT32_C(   949453539),
      UINT32_C( 949453539),
      UINT32_C(3797814156),
                UINT32_MAX,
                UINT32_MAX,
                UINT32_MAX,
                UINT32_MAX,
                UINT32_MAX },
    {  INT32_C(  1084957595),
      UINT32_C(1084957595),
                UINT32_MAX,
                UINT32_MAX,
                UINT32_MAX,
                UINT32_MAX,
                UINT32_MAX,
                UINT32_MAX },
    {  INT32_C(   459452182),
      UINT32_C( 459452182),
      UINT32_C(1837808728),
                UINT32_MAX,
                UINT32_MAX,
                UINT32_MAX,
                UINT32_MAX,
                UINT32_MAX },
    {  INT32_C(         192),
      UINT32_C(       192),
      UINT32_C(       768),
      UINT32_C(      6144),
      UINT32_C(     98304),
      UINT32_C(  12582912),
      UINT32_C(3221225472),
                UINT32_MAX },
    { -INT32_C(  2029478164),
      UINT32_C(         0),
      UINT32_C(         0),
      UINT32_C(         0),
      UINT32_C(         0),
      UINT32_C(         0),
      UINT32_C(         0),
      UINT32_C(         0) },
    {  INT32_C(          35),
      UINT32_C(        35),
      UINT32_C(       140),
      UINT32_C(      1120),
      UINT32_C(     17920),
      UINT32_C(   2293760),
      UINT32_C( 587202560),
                UINT32_MAX },
    {  INT32_C(   273347254),
      UINT32_C( 273347254),
      UINT32_C(1093389016),
                UINT32_MAX,
                UINT32_MAX,
                UINT32_MAX,
                UINT32_MAX,
                UINT32_MAX },
    {  INT32_C(   500896570),
      UINT32_C( 500896570),
      UINT32_C(2003586280),
                UINT32_MAX,
                UINT32_MAX,
                UINT32_MAX,
                UINT32_MAX,
                UINT32_MAX },
    {  INT32_C(   810906261),
      UINT32_C( 810906261),
      UINT32_C(3243625044),
                UINT32_MAX,
                UINT32_MAX,
                UINT32_MAX,
                UINT32_MAX,
                UINT32_MAX },
    {  INT32_C(         107),
      UINT32_C(       107),
      UINT32_C(       428),
      UINT32_C(      3424),
      UINT32_C(     54784),
      UINT32_C(   7012352),
      UINT32_C(1795162112),
                UINT32_MAX },
    { -INT32_C(   255339600),
      UINT32_C(         0),
      UINT32_C(         0),
      UINT32_C(         0),
      UINT32_C(         0),
      UINT32_C(         0),
      UINT32_C(         0),
      UINT32_C(         0) },
    {  INT32_C(          15),
      UINT32_C(        15),
      UINT32_C(        60),
      UINT32_C(       480),
      UINT32_C(      7680),
      UINT32_C(    983040),
      UINT32_C( 251658240),
                UINT32_MAX },
    { -INT32_C(  1285194026),
      UINT32_C(         0),
      UINT32_C(         0),
      UINT32_C(         0),
      UINT32_C(         0),
      UINT32_C(         0),
      UINT32_C(         0),
      UINT32_C(         0) },
    {  INT32_C(  1683225006),
      UINT32_C(1683225006),
                UINT32_MAX,
                UINT32_MAX,
                UINT32_MAX,
                UINT32_MAX,
                UINT32_MAX,
                UINT32_MAX },
    {  INT32_C(   645242347),
      UINT32_C( 645242347),
      UINT32_C(2580969388),
                UINT32_MAX,
                UINT32_MAX,
                UINT32_MAX,
                UINT32_MAX,
                UINT32_MAX },
    {  INT32_C(  1162039472),
      UINT32_C(1162039472),
                UINT32_MAX,
                UINT32_MAX,
                UINT32_MAX,
                UINT32_MAX,
                UINT32_MAX,
                UINT32_MAX },
    {  INT32_C(  1484167619),
      UINT32_C(1484167619),
                UINT32_MAX,
                UINT32_MAX,
                UINT32_MAX,
                UINT32_MAX,
                UINT32_MAX,
                UINT32_MAX },
    {  INT32_C(  1241835418),
      UINT32_C(1241835418),
                UINT32_MAX,
                UINT32_MAX,
                UINT32_MAX,
                UINT32_MAX,
                UINT32_MAX,
                UINT32_MAX },
    { -INT32_C(  1405432902),
      UINT32_C(         0),
      UINT32_C(         0),
      UINT32_C(         0),
      UINT32_C(         0),
      UINT32_C(         0),
      UINT32_C(         0),
      UINT32_C(         0) },
    {  INT32_C(         254),
      UINT32_C(       254),
      UINT32_C(      1016),
      UINT32_C(      8128),
      UINT32_C(    130048),
      UINT32_C(  16646144),
      UINT32_C(4261412864),
                UINT32_MAX },
    { -INT32_C(   561254609),
      UINT32_C(         0),
      UINT32_C(         0),
      UINT32_C(         0),
      UINT32_C(         0),
      UINT32_C(         0),
      UINT32_C(         0),
      UINT32_C(         0) },
    {  INT32_C(          24),
      UINT32_C(        24),
      UINT32_C(        96),
      UINT32_C(       768),
      UINT32_C(     12288),
      UINT32_C(   1572864),
      UINT32_C( 402653184),
                UINT32_MAX },
    {  INT32_C(   737785723),
      UINT32_C( 737785723),
      UINT32_C(2951142892),
                UINT32_MAX,
                UINT32_MAX,
                UINT32_MAX,
                UINT32_MAX,
                UINT32_MAX },
    {  INT32_C(         248),
      UINT32_C(       248),
      UINT32_C(       992),
      UINT32_C(      7936),
      UINT32_C(    126976),
      UINT32_C(  16252928),
      UINT32_C(4160749568),
                UINT32_MAX },
    };

    for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
      int32_t a = test_vec[i].a;
      uint32_t r0 = simde_vqshlus_n_s32(a, 0);
      uint32_t r2 = simde_vqshlus_n_s32(a, 2);
      uint32_t r5 = simde_vqshlus_n_s32(a, 5);
      uint32_t r9 = simde_vqshlus_n_s32(a, 9);
      uint32_t r16 = simde_vqshlus_n_s32(a, 16);
      uint32_t r24 = simde_vqshlus_n_s32(a, 24);
      uint32_t r31 = simde_vqshlus_n_s32(a, 31);

      simde_assert_equal_u32(r0, test_vec[i].r0);
      simde_assert_equal_u32(r2, test_vec[i].r2);
      simde_assert_equal_u32(r5, test_vec[i].r5);
      simde_assert_equal_u32(r9, test_vec[i].r9);
      simde_assert_equal_u32(r16, test_vec[i].r16);
      simde_assert_equal_u32(r24, test_vec[i].r24);
      simde_assert_equal_u32(r31, test_vec[i].r31);
    }

    return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 32 ; i++) {
    int32_t a = simde_test_codegen_random_i32();
    // Ensure some reasonable number of valid test vectors.
    if ((i % 2) && (a < 0))
    {
      a = -a;
      a %= 256;
    }
    uint32_t r0 = simde_vqshlus_n_s32(a, 0);
    uint32_t r2 = simde_vqshlus_n_s32(a, 2);
    uint32_t r5 = simde_vqshlus_n_s32(a, 5);
    uint32_t r9 = simde_vqshlus_n_s32(a, 9);
    uint32_t r16 = simde_vqshlus_n_s32(a, 16);
    uint32_t r24 = simde_vqshlus_n_s32(a, 24);
    uint32_t r31 = simde_vqshlus_n_s32(a, 31);

    simde_test_codegen_write_i32(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_u32(2, r0, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_u32(2, r2, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_u32(2, r5, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_u32(2, r9, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_u32(2, r16, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_u32(2, r24, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_u32(2, r31, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vqshlud_n_s64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
      int64_t a;
      uint64_t r0;
      uint64_t r2;
      uint64_t r5;
      uint64_t r9;
      uint64_t r32;
      uint64_t r48;
      uint64_t r63;
    } test_vec[] = {
    {  INT64_C( 2886399765623690139),
      UINT64_C( 2886399765623690139),
      UINT64_C(11545599062494760556),
                          UINT64_MAX,
                          UINT64_MAX,
                          UINT64_MAX,
                          UINT64_MAX,
                          UINT64_MAX },
    {  INT64_C(                  28),
      UINT64_C(                  28),
      UINT64_C(                 112),
      UINT64_C(                 896),
      UINT64_C(               14336),
      UINT64_C(        120259084288),
      UINT64_C(    7881299347898368),
                          UINT64_MAX },
    {  INT64_C( 2703632360428737343),
      UINT64_C( 2703632360428737343),
      UINT64_C(10814529441714949372),
                          UINT64_MAX,
                          UINT64_MAX,
                          UINT64_MAX,
                          UINT64_MAX,
                          UINT64_MAX },
    {  INT64_C(                  98),
      UINT64_C(                  98),
      UINT64_C(                 392),
      UINT64_C(                3136),
      UINT64_C(               50176),
      UINT64_C(        420906795008),
      UINT64_C(   27584547717644288),
                          UINT64_MAX },
    {  INT64_C( 3086723063588304994),
      UINT64_C( 3086723063588304994),
      UINT64_C(12346892254353219976),
                          UINT64_MAX,
                          UINT64_MAX,
                          UINT64_MAX,
                          UINT64_MAX,
                          UINT64_MAX },
    {  INT64_C( 2248181184994964008),
      UINT64_C( 2248181184994964008),
      UINT64_C( 8992724739979856032),
                          UINT64_MAX,
                          UINT64_MAX,
                          UINT64_MAX,
                          UINT64_MAX,
                          UINT64_MAX },
    { -INT64_C( 6364903447505023433),
      UINT64_C(                   0),
      UINT64_C(                   0),
      UINT64_C(                   0),
      UINT64_C(                   0),
      UINT64_C(                   0),
      UINT64_C(                   0),
      UINT64_C(                   0) },
    {  INT64_C( 1857972031008909455),
      UINT64_C( 1857972031008909455),
      UINT64_C( 7431888124035637820),
                          UINT64_MAX,
                          UINT64_MAX,
                          UINT64_MAX,
                          UINT64_MAX,
                          UINT64_MAX },
    {  INT64_C( 6773304119622301583),
      UINT64_C( 6773304119622301583),
                          UINT64_MAX,
                          UINT64_MAX,
                          UINT64_MAX,
                          UINT64_MAX,
                          UINT64_MAX,
                          UINT64_MAX },
    {  INT64_C(                 242),
      UINT64_C(                 242),
      UINT64_C(                 968),
      UINT64_C(                7744),
      UINT64_C(              123904),
      UINT64_C(       1039382085632),
      UINT64_C(   68116944363978752),
                          UINT64_MAX },
    { -INT64_C( 4798055237531738951),
      UINT64_C(                   0),
      UINT64_C(                   0),
      UINT64_C(                   0),
      UINT64_C(                   0),
      UINT64_C(                   0),
      UINT64_C(                   0),
      UINT64_C(                   0) },
    {  INT64_C(                 118),
      UINT64_C(                 118),
      UINT64_C(                 472),
      UINT64_C(                3776),
      UINT64_C(               60416),
      UINT64_C(        506806140928),
      UINT64_C(   33214047251857408),
                          UINT64_MAX },
    { -INT64_C( 3751909992286248869),
      UINT64_C(                   0),
      UINT64_C(                   0),
      UINT64_C(                   0),
      UINT64_C(                   0),
      UINT64_C(                   0),
      UINT64_C(                   0),
      UINT64_C(                   0) },
    {  INT64_C( 5335298334686619359),
      UINT64_C( 5335298334686619359),
                          UINT64_MAX,
                          UINT64_MAX,
                          UINT64_MAX,
                          UINT64_MAX,
                          UINT64_MAX,
                          UINT64_MAX },
    { -INT64_C( 5939837636799872603),
      UINT64_C(                   0),
      UINT64_C(                   0),
      UINT64_C(                   0),
      UINT64_C(                   0),
      UINT64_C(                   0),
      UINT64_C(                   0),
      UINT64_C(                   0) },
    {  INT64_C(                  61),
      UINT64_C(                  61),
      UINT64_C(                 244),
      UINT64_C(                1952),
      UINT64_C(               31232),
      UINT64_C(        261993005056),
      UINT64_C(   17169973579350016),
                          UINT64_MAX },
    { -INT64_C( 8074556451617822871),
      UINT64_C(                   0),
      UINT64_C(                   0),
      UINT64_C(                   0),
      UINT64_C(                   0),
      UINT64_C(                   0),
      UINT64_C(                   0),
      UINT64_C(                   0) },
    {  INT64_C( 1939630276072745999),
      UINT64_C( 1939630276072745999),
      UINT64_C( 7758521104290983996),
                          UINT64_MAX,
                          UINT64_MAX,
                          UINT64_MAX,
                          UINT64_MAX,
                          UINT64_MAX },
    {  INT64_C( 3316195700146828852),
      UINT64_C( 3316195700146828852),
      UINT64_C(13264782800587315408),
                          UINT64_MAX,
                          UINT64_MAX,
                          UINT64_MAX,
                          UINT64_MAX,
                          UINT64_MAX },
    {  INT64_C(                  85),
      UINT64_C(                  85),
      UINT64_C(                 340),
      UINT64_C(                2720),
      UINT64_C(               43520),
      UINT64_C(        365072220160),
      UINT64_C(   23925373020405760),
                          UINT64_MAX },
    {  INT64_C( 1881586601638470108),
      UINT64_C( 1881586601638470108),
      UINT64_C( 7526346406553880432),
                          UINT64_MAX,
                          UINT64_MAX,
                          UINT64_MAX,
                          UINT64_MAX,
                          UINT64_MAX },
    {  INT64_C( 3240522415905375337),
      UINT64_C( 3240522415905375337),
      UINT64_C(12962089663621501348),
                          UINT64_MAX,
                          UINT64_MAX,
                          UINT64_MAX,
                          UINT64_MAX,
                          UINT64_MAX },
    {  INT64_C( 1096214622027179420),
      UINT64_C( 1096214622027179420),
      UINT64_C( 4384858488108717680),
                          UINT64_MAX,
                          UINT64_MAX,
                          UINT64_MAX,
                          UINT64_MAX,
                          UINT64_MAX },
    {  INT64_C(                 131),
      UINT64_C(                 131),
      UINT64_C(                 524),
      UINT64_C(                4192),
      UINT64_C(               67072),
      UINT64_C(        562640715776),
      UINT64_C(   36873221949095936),
                          UINT64_MAX },
    {  INT64_C( 5852294572258503441),
      UINT64_C( 5852294572258503441),
                          UINT64_MAX,
                          UINT64_MAX,
                          UINT64_MAX,
                          UINT64_MAX,
                          UINT64_MAX,
                          UINT64_MAX },
    {  INT64_C( 3723957473559704202),
      UINT64_C( 3723957473559704202),
      UINT64_C(14895829894238816808),
                          UINT64_MAX,
                          UINT64_MAX,
                          UINT64_MAX,
                          UINT64_MAX,
                          UINT64_MAX },
    {  INT64_C( 4143155232059896332),
      UINT64_C( 4143155232059896332),
      UINT64_C(16572620928239585328),
                          UINT64_MAX,
                          UINT64_MAX,
                          UINT64_MAX,
                          UINT64_MAX,
                          UINT64_MAX },
    {  INT64_C( 5448601532175206846),
      UINT64_C( 5448601532175206846),
                          UINT64_MAX,
                          UINT64_MAX,
                          UINT64_MAX,
                          UINT64_MAX,
                          UINT64_MAX,
                          UINT64_MAX },
    {  INT64_C( 1708727438762510205),
      UINT64_C( 1708727438762510205),
      UINT64_C( 6834909755050040820),
                          UINT64_MAX,
                          UINT64_MAX,
                          UINT64_MAX,
                          UINT64_MAX,
                          UINT64_MAX },
    {  INT64_C( 1827132191375222160),
      UINT64_C( 1827132191375222160),
      UINT64_C( 7308528765500888640),
                          UINT64_MAX,
                          UINT64_MAX,
                          UINT64_MAX,
                          UINT64_MAX,
                          UINT64_MAX },
    { -INT64_C( 4220425874231945607),
      UINT64_C(                   0),
      UINT64_C(                   0),
      UINT64_C(                   0),
      UINT64_C(                   0),
      UINT64_C(                   0),
      UINT64_C(                   0),
      UINT64_C(                   0) },
    {  INT64_C( 3555348583236854226),
      UINT64_C( 3555348583236854226),
      UINT64_C(14221394332947416904),
                          UINT64_MAX,
                          UINT64_MAX,
                          UINT64_MAX,
                          UINT64_MAX,
                          UINT64_MAX },
    { -INT64_C( 1311306851604316631),
      UINT64_C(                   0),
      UINT64_C(                   0),
      UINT64_C(                   0),
      UINT64_C(                   0),
      UINT64_C(                   0),
      UINT64_C(                   0),
      UINT64_C(                   0) },
    {  INT64_C( 2907198552664270642),
      UINT64_C( 2907198552664270642),
      UINT64_C(11628794210657082568),
                          UINT64_MAX,
                          UINT64_MAX,
                          UINT64_MAX,
                          UINT64_MAX,
                          UINT64_MAX },
    { -INT64_C( 4767961899337916153),
      UINT64_C(                   0),
      UINT64_C(                   0),
      UINT64_C(                   0),
      UINT64_C(                   0),
      UINT64_C(                   0),
      UINT64_C(                   0),
      UINT64_C(                   0) },
    {  INT64_C(                 212),
      UINT64_C(                 212),
      UINT64_C(                 848),
      UINT64_C(                6784),
      UINT64_C(              108544),
      UINT64_C(        910533066752),
      UINT64_C(   59672695062659072),
                          UINT64_MAX },
    {  INT64_C( 2749774076919326686),
      UINT64_C( 2749774076919326686),
      UINT64_C(10999096307677306744),
                          UINT64_MAX,
                          UINT64_MAX,
                          UINT64_MAX,
                          UINT64_MAX,
                          UINT64_MAX },
    {  INT64_C(                 113),
      UINT64_C(                 113),
      UINT64_C(                 452),
      UINT64_C(                3616),
      UINT64_C(               57856),
      UINT64_C(        485331304448),
      UINT64_C(   31806672368304128),
                          UINT64_MAX },
    { -INT64_C( 5096215995630566753),
      UINT64_C(                   0),
      UINT64_C(                   0),
      UINT64_C(                   0),
      UINT64_C(                   0),
      UINT64_C(                   0),
      UINT64_C(                   0),
      UINT64_C(                   0) },
    {  INT64_C( 1014621837266063348),
      UINT64_C( 1014621837266063348),
      UINT64_C( 4058487349064253392),
                          UINT64_MAX,
                          UINT64_MAX,
                          UINT64_MAX,
                          UINT64_MAX,
                          UINT64_MAX },
    {  INT64_C( 2696374791627697744),
      UINT64_C( 2696374791627697744),
      UINT64_C(10785499166510790976),
                          UINT64_MAX,
                          UINT64_MAX,
                          UINT64_MAX,
                          UINT64_MAX,
                          UINT64_MAX },
    {  INT64_C( 3249286169999167665),
      UINT64_C( 3249286169999167665),
      UINT64_C(12997144679996670660),
                          UINT64_MAX,
                          UINT64_MAX,
                          UINT64_MAX,
                          UINT64_MAX,
                          UINT64_MAX },
    {  INT64_C( 7841608593457995147),
      UINT64_C( 7841608593457995147),
                          UINT64_MAX,
                          UINT64_MAX,
                          UINT64_MAX,
                          UINT64_MAX,
                          UINT64_MAX,
                          UINT64_MAX },
    {  INT64_C( 7298909016306707212),
      UINT64_C( 7298909016306707212),
                          UINT64_MAX,
                          UINT64_MAX,
                          UINT64_MAX,
                          UINT64_MAX,
                          UINT64_MAX,
                          UINT64_MAX },
    { -INT64_C( 5252863995267148962),
      UINT64_C(                   0),
      UINT64_C(                   0),
      UINT64_C(                   0),
      UINT64_C(                   0),
      UINT64_C(                   0),
      UINT64_C(                   0),
      UINT64_C(                   0) },
    {  INT64_C(                  27),
      UINT64_C(                  27),
      UINT64_C(                 108),
      UINT64_C(                 864),
      UINT64_C(               13824),
      UINT64_C(        115964116992),
      UINT64_C(    7599824371187712),
                          UINT64_MAX },
    {  INT64_C( 6985288989438203404),
      UINT64_C( 6985288989438203404),
                          UINT64_MAX,
                          UINT64_MAX,
                          UINT64_MAX,
                          UINT64_MAX,
                          UINT64_MAX,
                          UINT64_MAX },
    {  INT64_C( 1846448064061819942),
      UINT64_C( 1846448064061819942),
      UINT64_C( 7385792256247279768),
                          UINT64_MAX,
                          UINT64_MAX,
                          UINT64_MAX,
                          UINT64_MAX,
                          UINT64_MAX },
    {  INT64_C( 4771045237274331513),
      UINT64_C( 4771045237274331513),
                          UINT64_MAX,
                          UINT64_MAX,
                          UINT64_MAX,
                          UINT64_MAX,
                          UINT64_MAX,
                          UINT64_MAX },
    {  INT64_C(                  91),
      UINT64_C(                  91),
      UINT64_C(                 364),
      UINT64_C(                2912),
      UINT64_C(               46592),
      UINT64_C(        390842023936),
      UINT64_C(   25614222880669696),
                          UINT64_MAX },
    { -INT64_C( 8836064255623125844),
      UINT64_C(                   0),
      UINT64_C(                   0),
      UINT64_C(                   0),
      UINT64_C(                   0),
      UINT64_C(                   0),
      UINT64_C(                   0),
      UINT64_C(                   0) },
    {  INT64_C( 6602101000981445578),
      UINT64_C( 6602101000981445578),
                          UINT64_MAX,
                          UINT64_MAX,
                          UINT64_MAX,
                          UINT64_MAX,
                          UINT64_MAX,
                          UINT64_MAX },
    {  INT64_C( 8811312277574299048),
      UINT64_C( 8811312277574299048),
                          UINT64_MAX,
                          UINT64_MAX,
                          UINT64_MAX,
                          UINT64_MAX,
                          UINT64_MAX,
                          UINT64_MAX },
    {  INT64_C(                 161),
      UINT64_C(                 161),
      UINT64_C(                 644),
      UINT64_C(                5152),
      UINT64_C(               82432),
      UINT64_C(        691489734656),
      UINT64_C(   45317471250415616),
                          UINT64_MAX },
    {  INT64_C( 4370847282686227396),
      UINT64_C( 4370847282686227396),
      UINT64_C(17483389130744909584),
                          UINT64_MAX,
                          UINT64_MAX,
                          UINT64_MAX,
                          UINT64_MAX,
                          UINT64_MAX },
    {  INT64_C( 7968665194224314201),
      UINT64_C( 7968665194224314201),
                          UINT64_MAX,
                          UINT64_MAX,
                          UINT64_MAX,
                          UINT64_MAX,
                          UINT64_MAX,
                          UINT64_MAX },
    { -INT64_C( 2278895620339765233),
      UINT64_C(                   0),
      UINT64_C(                   0),
      UINT64_C(                   0),
      UINT64_C(                   0),
      UINT64_C(                   0),
      UINT64_C(                   0),
      UINT64_C(                   0) },
    {  INT64_C(                  71),
      UINT64_C(                  71),
      UINT64_C(                 284),
      UINT64_C(                2272),
      UINT64_C(               36352),
      UINT64_C(        304942678016),
      UINT64_C(   19984723346456576),
                          UINT64_MAX },
    { -INT64_C( 4520361235328595307),
      UINT64_C(                   0),
      UINT64_C(                   0),
      UINT64_C(                   0),
      UINT64_C(                   0),
      UINT64_C(                   0),
      UINT64_C(                   0),
      UINT64_C(                   0) },
    {  INT64_C( 8651575862270625499),
      UINT64_C( 8651575862270625499),
                          UINT64_MAX,
                          UINT64_MAX,
                          UINT64_MAX,
                          UINT64_MAX,
                          UINT64_MAX,
                          UINT64_MAX },
    { -INT64_C(  475767200333069309),
      UINT64_C(                   0),
      UINT64_C(                   0),
      UINT64_C(                   0),
      UINT64_C(                   0),
      UINT64_C(                   0),
      UINT64_C(                   0),
      UINT64_C(                   0) },
    {  INT64_C(                 127),
      UINT64_C(                 127),
      UINT64_C(                 508),
      UINT64_C(                4064),
      UINT64_C(               65024),
      UINT64_C(        545460846592),
      UINT64_C(   35747322042253312),
                          UINT64_MAX },
    {  INT64_C( 2901765450253785371),
      UINT64_C( 2901765450253785371),
      UINT64_C(11607061801015141484),
                          UINT64_MAX,
                          UINT64_MAX,
                          UINT64_MAX,
                          UINT64_MAX,
                          UINT64_MAX },
    {  INT64_C(                 213),
      UINT64_C(                 213),
      UINT64_C(                 852),
      UINT64_C(                6816),
      UINT64_C(              109056),
      UINT64_C(        914828034048),
      UINT64_C(   59954170039369728),
                          UINT64_MAX },
    };

    for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
      int64_t a = test_vec[i].a;
      uint64_t r0 = simde_vqshlud_n_s64(a, 0);
      uint64_t r2 = simde_vqshlud_n_s64(a, 2);
      uint64_t r5 = simde_vqshlud_n_s64(a, 5);
      uint64_t r9 = simde_vqshlud_n_s64(a, 9);
      uint64_t r32 = simde_vqshlud_n_s64(a, 32);
      uint64_t r48 = simde_vqshlud_n_s64(a, 48);
      uint64_t r63 = simde_vqshlud_n_s64(a, 63);

      simde_assert_equal_u64(r0, test_vec[i].r0);
      simde_assert_equal_u64(r2, test_vec[i].r2);
      simde_assert_equal_u64(r5, test_vec[i].r5);
      simde_assert_equal_u64(r9, test_vec[i].r9);
      simde_assert_equal_u64(r32, test_vec[i].r32);
      simde_assert_equal_u64(r48, test_vec[i].r48);
      simde_assert_equal_u64(r63, test_vec[i].r63);
    }

    return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 64 ; i++) {
    int64_t a = simde_test_codegen_random_i64();
    // Ensure some reasonable number of valid test vectors.
    if ((i % 2) && (a < 0))
    {
      a = -a;
      a %= 256;
    }
    uint64_t r0 = simde_vqshlud_n_s64(a, 0);
    uint64_t r2 = simde_vqshlud_n_s64(a, 2);
    uint64_t r5 = simde_vqshlud_n_s64(a, 5);
    uint64_t r9 = simde_vqshlud_n_s64(a, 9);
    uint64_t r32 = simde_vqshlud_n_s64(a, 32);
    uint64_t r48 = simde_vqshlud_n_s64(a, 48);
    uint64_t r63 = simde_vqshlud_n_s64(a, 63);

    simde_test_codegen_write_i64(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_u64(2, r0, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_u64(2, r2, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_u64(2, r5, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_u64(2, r9, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_u64(2, r32, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_u64(2, r48, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_u64(2, r63, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vqshlu_n_s8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int8_t a[8];
    const int n;
    uint8_t r[8];
  } test_vec[] = {
    { { -INT8_C(  66),  INT8_C(  72), -INT8_C(  92), -INT8_C(  15), -INT8_C(  78), -INT8_C(  96), -INT8_C( 107), -INT8_C(  40) },
      INT32_C(           0),
     { UINT8_C(  0), UINT8_C( 72), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0) } },
   { {  INT8_C(  46),  INT8_C( 106), -INT8_C(  64), -INT8_C( 112), -INT8_C(  41),  INT8_C(  94), -INT8_C(  38),      INT8_MIN },
      INT32_C(           1),
     { UINT8_C( 92), UINT8_C(212), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(188), UINT8_C(  0), UINT8_C(  0) } },
   { { -INT8_C(   4),  INT8_C(  61), -INT8_C(   4), -INT8_C(  78),  INT8_C(  55),  INT8_C( 107),  INT8_C(  37),  INT8_C(  59) },
      INT32_C(           2),
     { UINT8_C(  0), UINT8_C(244), UINT8_C(  0), UINT8_C(  0), UINT8_C(220),    UINT8_MAX, UINT8_C(148), UINT8_C(236) } },
   { {  INT8_C(  33),  INT8_C(  38),  INT8_C(  47), -INT8_C(  32), -INT8_C(  11),  INT8_C( 103), -INT8_C( 103), -INT8_C(  77) },
      INT32_C(           3),
     {    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0), UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  0) } },
   { { -INT8_C(  80),  INT8_C(  61), -INT8_C(  92),  INT8_C(  98), -INT8_C(  35),  INT8_C(  58),  INT8_C(  59),  INT8_C(  11) },
      INT32_C(           4),
     { UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX, UINT8_C(176) } },
   { { -INT8_C(  92), -INT8_C(   5), -INT8_C( 101),  INT8_C( 124),  INT8_C(  89),  INT8_C( 118), -INT8_C(   4),  INT8_C(  85) },
      INT32_C(           5),
     { UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX } },
   { { -INT8_C(  77), -INT8_C(   8),  INT8_C(   8), -INT8_C(  22),  INT8_C(  99),  INT8_C(  45),  INT8_C(  37), -INT8_C( 123) },
      INT32_C(           6),
     { UINT8_C(  0), UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0) } },
   { {  INT8_C(  83),  INT8_C(  84),  INT8_C( 101),  INT8_C(  72), -INT8_C(  68), -INT8_C(   2), -INT8_C(   5),  INT8_C( 108) },
      INT32_C(           7),
     {    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),    UINT8_MAX } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int8x8_t a = simde_vld1_s8(test_vec[i].a);
    simde_uint8x8_t r;
    SIMDE_CONSTIFY_8_(simde_vqshlu_n_s8, r, (HEDLEY_UNREACHABLE(), r), test_vec[i].n, a);

    simde_test_arm_neon_assert_equal_u8x8(r, simde_vld1_u8(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  const int n[] = { 0, 1, 2, 3, 4, 5, 6, 7 };
  for (int i = 0 ; i < 8 ; i++) {
    simde_int8x8_t a = simde_test_arm_neon_random_i8x8();
    simde_uint8x8_t r;
    SIMDE_CONSTIFY_8_(simde_vqshlu_n_s8, r, (HEDLEY_UNREACHABLE(), r), n[i], a);

    simde_test_arm_neon_write_i8x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_i32(2, n[i], SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u8x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vqshlu_n_s16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int16_t a[4];
    uint16_t r0[4];
    uint16_t r2[4];
    uint16_t r5[4];
    uint16_t r9[4];
    uint16_t r10[4];
    uint16_t r13[4];
    uint16_t r15[4];
  } test_vec[] = {
    { {  INT16_C( 10390), -INT16_C( 23036), -INT16_C( 23085), -INT16_C( 26112) },
      { UINT16_C(10390), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0) },
      { UINT16_C(41560), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0) },
      {      UINT16_MAX, UINT16_C(    0), UINT16_C(    0), UINT16_C(    0) },
      {      UINT16_MAX, UINT16_C(    0), UINT16_C(    0), UINT16_C(    0) },
      {      UINT16_MAX, UINT16_C(    0), UINT16_C(    0), UINT16_C(    0) },
      {      UINT16_MAX, UINT16_C(    0), UINT16_C(    0), UINT16_C(    0) },
      {      UINT16_MAX, UINT16_C(    0), UINT16_C(    0), UINT16_C(    0) } },
    { {  INT16_C( 23503), -INT16_C(    67),  INT16_C( 13233), -INT16_C(  9905) },
      { UINT16_C(23503), UINT16_C(    0), UINT16_C(13233), UINT16_C(    0) },
      {      UINT16_MAX, UINT16_C(    0), UINT16_C(52932), UINT16_C(    0) },
      {      UINT16_MAX, UINT16_C(    0),      UINT16_MAX, UINT16_C(    0) },
      {      UINT16_MAX, UINT16_C(    0),      UINT16_MAX, UINT16_C(    0) },
      {      UINT16_MAX, UINT16_C(    0),      UINT16_MAX, UINT16_C(    0) },
      {      UINT16_MAX, UINT16_C(    0),      UINT16_MAX, UINT16_C(    0) },
      {      UINT16_MAX, UINT16_C(    0),      UINT16_MAX, UINT16_C(    0) } },
    { {  INT16_C( 15091),  INT16_C(   772), -INT16_C( 16389), -INT16_C(  1073) },
      { UINT16_C(15091), UINT16_C(  772), UINT16_C(    0), UINT16_C(    0) },
      { UINT16_C(60364), UINT16_C( 3088), UINT16_C(    0), UINT16_C(    0) },
      {      UINT16_MAX, UINT16_C(24704), UINT16_C(    0), UINT16_C(    0) },
      {      UINT16_MAX,      UINT16_MAX, UINT16_C(    0), UINT16_C(    0) },
      {      UINT16_MAX,      UINT16_MAX, UINT16_C(    0), UINT16_C(    0) },
      {      UINT16_MAX,      UINT16_MAX, UINT16_C(    0), UINT16_C(    0) },
      {      UINT16_MAX,      UINT16_MAX, UINT16_C(    0), UINT16_C(    0) } },
    { { -INT16_C( 28563), -INT16_C(  9751),  INT16_C( 32169),  INT16_C( 16282) },
      { UINT16_C(    0), UINT16_C(    0), UINT16_C(32169), UINT16_C(16282) },
      { UINT16_C(    0), UINT16_C(    0),      UINT16_MAX, UINT16_C(65128) },
      { UINT16_C(    0), UINT16_C(    0),      UINT16_MAX,      UINT16_MAX },
      { UINT16_C(    0), UINT16_C(    0),      UINT16_MAX,      UINT16_MAX },
      { UINT16_C(    0), UINT16_C(    0),      UINT16_MAX,      UINT16_MAX },
      { UINT16_C(    0), UINT16_C(    0),      UINT16_MAX,      UINT16_MAX },
      { UINT16_C(    0), UINT16_C(    0),      UINT16_MAX,      UINT16_MAX } },
    { { -INT16_C( 24923),  INT16_C( 31206), -INT16_C(  6589),  INT16_C(  4627) },
      { UINT16_C(    0), UINT16_C(31206), UINT16_C(    0), UINT16_C( 4627) },
      { UINT16_C(    0),      UINT16_MAX, UINT16_C(    0), UINT16_C(18508) },
      { UINT16_C(    0),      UINT16_MAX, UINT16_C(    0),      UINT16_MAX },
      { UINT16_C(    0),      UINT16_MAX, UINT16_C(    0),      UINT16_MAX },
      { UINT16_C(    0),      UINT16_MAX, UINT16_C(    0),      UINT16_MAX },
      { UINT16_C(    0),      UINT16_MAX, UINT16_C(    0),      UINT16_MAX },
      { UINT16_C(    0),      UINT16_MAX, UINT16_C(    0),      UINT16_MAX } },
    { { -INT16_C( 12223), -INT16_C(  3566),  INT16_C( 24835), -INT16_C(  2357) },
      { UINT16_C(    0), UINT16_C(    0), UINT16_C(24835), UINT16_C(    0) },
      { UINT16_C(    0), UINT16_C(    0),      UINT16_MAX, UINT16_C(    0) },
      { UINT16_C(    0), UINT16_C(    0),      UINT16_MAX, UINT16_C(    0) },
      { UINT16_C(    0), UINT16_C(    0),      UINT16_MAX, UINT16_C(    0) },
      { UINT16_C(    0), UINT16_C(    0),      UINT16_MAX, UINT16_C(    0) },
      { UINT16_C(    0), UINT16_C(    0),      UINT16_MAX, UINT16_C(    0) },
      { UINT16_C(    0), UINT16_C(    0),      UINT16_MAX, UINT16_C(    0) } },
    { { -INT16_C( 12133), -INT16_C( 26630), -INT16_C( 13937), -INT16_C(   878) },
      { UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0) },
      { UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0) },
      { UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0) },
      { UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0) },
      { UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0) },
      { UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0) },
      { UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0) } },
    { {  INT16_C( 31833),  INT16_C(   981),  INT16_C( 28665), -INT16_C( 24766) },
      { UINT16_C(31833), UINT16_C(  981), UINT16_C(28665), UINT16_C(    0) },
      {      UINT16_MAX, UINT16_C( 3924),      UINT16_MAX, UINT16_C(    0) },
      {      UINT16_MAX, UINT16_C(31392),      UINT16_MAX, UINT16_C(    0) },
      {      UINT16_MAX,      UINT16_MAX,      UINT16_MAX, UINT16_C(    0) },
      {      UINT16_MAX,      UINT16_MAX,      UINT16_MAX, UINT16_C(    0) },
      {      UINT16_MAX,      UINT16_MAX,      UINT16_MAX, UINT16_C(    0) },
      {      UINT16_MAX,      UINT16_MAX,      UINT16_MAX, UINT16_C(    0) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x4_t a = simde_vld1_s16(test_vec[i].a);
    simde_uint16x4_t r0 = simde_vqshlu_n_s16(a, 0);
    simde_uint16x4_t r2 = simde_vqshlu_n_s16(a, 2);
    simde_uint16x4_t r5 = simde_vqshlu_n_s16(a, 5);
    simde_uint16x4_t r9 = simde_vqshlu_n_s16(a, 9);
    simde_uint16x4_t r10 = simde_vqshlu_n_s16(a, 10);
    simde_uint16x4_t r13 = simde_vqshlu_n_s16(a, 13);
    simde_uint16x4_t r15 = simde_vqshlu_n_s16(a, 15);

    simde_test_arm_neon_assert_equal_u16x4(r0, simde_vld1_u16(test_vec[i].r0));
    simde_test_arm_neon_assert_equal_u16x4(r2, simde_vld1_u16(test_vec[i].r2));
    simde_test_arm_neon_assert_equal_u16x4(r5, simde_vld1_u16(test_vec[i].r5));
    simde_test_arm_neon_assert_equal_u16x4(r9, simde_vld1_u16(test_vec[i].r9));
    simde_test_arm_neon_assert_equal_u16x4(r10, simde_vld1_u16(test_vec[i].r10));
    simde_test_arm_neon_assert_equal_u16x4(r13, simde_vld1_u16(test_vec[i].r13));
    simde_test_arm_neon_assert_equal_u16x4(r15, simde_vld1_u16(test_vec[i].r15));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int16x4_t a = simde_test_arm_neon_random_i16x4();
    simde_uint16x4_t r0 = simde_vqshlu_n_s16(a, 0);
    simde_uint16x4_t r2 = simde_vqshlu_n_s16(a, 2);
    simde_uint16x4_t r5 = simde_vqshlu_n_s16(a, 5);
    simde_uint16x4_t r9 = simde_vqshlu_n_s16(a, 9);
    simde_uint16x4_t r10 = simde_vqshlu_n_s16(a, 10);
    simde_uint16x4_t r13 = simde_vqshlu_n_s16(a, 13);
    simde_uint16x4_t r15 = simde_vqshlu_n_s16(a, 15);

    simde_test_arm_neon_write_i16x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u16x4(2, r0, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u16x4(2, r2, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u16x4(2, r5, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u16x4(2, r9, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u16x4(2, r10, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u16x4(2, r13, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u16x4(2, r15, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vqshlu_n_s32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int32_t a[2];
    uint32_t r0[2];
    uint32_t r4[2];
    uint32_t r10[2];
    uint32_t r15[2];
    uint32_t r23[2];
    uint32_t r28[2];
    uint32_t r31[2];
  } test_vec[] = {
    { {  INT32_C(   598227896), -INT32_C(  1134992453) },
      { UINT32_C( 598227896), UINT32_C(         0) },
      {           UINT32_MAX, UINT32_C(         0) },
      {           UINT32_MAX, UINT32_C(         0) },
      {           UINT32_MAX, UINT32_C(         0) },
      {           UINT32_MAX, UINT32_C(         0) },
      {           UINT32_MAX, UINT32_C(         0) },
      {           UINT32_MAX, UINT32_C(         0) } },
    { {  INT32_C(   461190294),  INT32_C(  1207825082) },
      { UINT32_C( 461190294), UINT32_C(1207825082) },
      {           UINT32_MAX,           UINT32_MAX },
      {           UINT32_MAX,           UINT32_MAX },
      {           UINT32_MAX,           UINT32_MAX },
      {           UINT32_MAX,           UINT32_MAX },
      {           UINT32_MAX,           UINT32_MAX },
      {           UINT32_MAX,           UINT32_MAX } },
    { {  INT32_C(   268503244),  INT32_C(  1953130073) },
      { UINT32_C( 268503244), UINT32_C(1953130073) },
      {           UINT32_MAX,           UINT32_MAX },
      {           UINT32_MAX,           UINT32_MAX },
      {           UINT32_MAX,           UINT32_MAX },
      {           UINT32_MAX,           UINT32_MAX },
      {           UINT32_MAX,           UINT32_MAX },
      {           UINT32_MAX,           UINT32_MAX } },
    { {  INT32_C(  1616334634), -INT32_C(  1096563195) },
      { UINT32_C(1616334634), UINT32_C(         0) },
      {           UINT32_MAX, UINT32_C(         0) },
      {           UINT32_MAX, UINT32_C(         0) },
      {           UINT32_MAX, UINT32_C(         0) },
      {           UINT32_MAX, UINT32_C(         0) },
      {           UINT32_MAX, UINT32_C(         0) },
      {           UINT32_MAX, UINT32_C(         0) } },
    { { -INT32_C(  1126085887),  INT32_C(  1148795822) },
      { UINT32_C(         0), UINT32_C(1148795822) },
      { UINT32_C(         0),           UINT32_MAX },
      { UINT32_C(         0),           UINT32_MAX },
      { UINT32_C(         0),           UINT32_MAX },
      { UINT32_C(         0),           UINT32_MAX },
      { UINT32_C(         0),           UINT32_MAX },
      { UINT32_C(         0),           UINT32_MAX } },
    { {  INT32_C(   694154863), -INT32_C(  1267704600) },
      { UINT32_C( 694154863), UINT32_C(         0) },
      {           UINT32_MAX, UINT32_C(         0) },
      {           UINT32_MAX, UINT32_C(         0) },
      {           UINT32_MAX, UINT32_C(         0) },
      {           UINT32_MAX, UINT32_C(         0) },
      {           UINT32_MAX, UINT32_C(         0) },
      {           UINT32_MAX, UINT32_C(         0) } },
    { { -INT32_C(  1094421915),  INT32_C(    36843480) },
      { UINT32_C(         0), UINT32_C(  36843480) },
      { UINT32_C(         0), UINT32_C( 589495680) },
      { UINT32_C(         0),           UINT32_MAX },
      { UINT32_C(         0),           UINT32_MAX },
      { UINT32_C(         0),           UINT32_MAX },
      { UINT32_C(         0),           UINT32_MAX },
      { UINT32_C(         0),           UINT32_MAX } },
    { { -INT32_C(  2073917058),  INT32_C(  1363281487) },
      { UINT32_C(         0), UINT32_C(1363281487) },
      { UINT32_C(         0),           UINT32_MAX },
      { UINT32_C(         0),           UINT32_MAX },
      { UINT32_C(         0),           UINT32_MAX },
      { UINT32_C(         0),           UINT32_MAX },
      { UINT32_C(         0),           UINT32_MAX },
      { UINT32_C(         0),           UINT32_MAX } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x2_t a = simde_vld1_s32(test_vec[i].a);
    simde_uint32x2_t r0 = simde_vqshlu_n_s32(a, 0);
    simde_uint32x2_t r4 = simde_vqshlu_n_s32(a, 4);
    simde_uint32x2_t r10 = simde_vqshlu_n_s32(a, 10);
    simde_uint32x2_t r15 = simde_vqshlu_n_s32(a, 15);
    simde_uint32x2_t r23 = simde_vqshlu_n_s32(a, 23);
    simde_uint32x2_t r28 = simde_vqshlu_n_s32(a, 28);
    simde_uint32x2_t r31 = simde_vqshlu_n_s32(a, 31);

    simde_test_arm_neon_assert_equal_u32x2(r0, simde_vld1_u32(test_vec[i].r0));
    simde_test_arm_neon_assert_equal_u32x2(r4, simde_vld1_u32(test_vec[i].r4));
    simde_test_arm_neon_assert_equal_u32x2(r10, simde_vld1_u32(test_vec[i].r10));
    simde_test_arm_neon_assert_equal_u32x2(r15, simde_vld1_u32(test_vec[i].r15));
    simde_test_arm_neon_assert_equal_u32x2(r23, simde_vld1_u32(test_vec[i].r23));
    simde_test_arm_neon_assert_equal_u32x2(r28, simde_vld1_u32(test_vec[i].r28));
    simde_test_arm_neon_assert_equal_u32x2(r31, simde_vld1_u32(test_vec[i].r31));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int32x2_t a = simde_test_arm_neon_random_i32x2();
    simde_uint32x2_t r0 = simde_vqshlu_n_s32(a, 0);
    simde_uint32x2_t r4 = simde_vqshlu_n_s32(a, 4);
    simde_uint32x2_t r10 = simde_vqshlu_n_s32(a, 10);
    simde_uint32x2_t r15 = simde_vqshlu_n_s32(a, 15);
    simde_uint32x2_t r23 = simde_vqshlu_n_s32(a, 23);
    simde_uint32x2_t r28 = simde_vqshlu_n_s32(a, 28);
    simde_uint32x2_t r31 = simde_vqshlu_n_s32(a, 31);

    simde_test_arm_neon_write_i32x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u32x2(2, r0, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x2(2, r4, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x2(2, r10, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x2(2, r15, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x2(2, r23, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x2(2, r28, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x2(2, r31, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vqshlu_n_s64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int64_t a[1];
    uint64_t r0[1];
    uint64_t r3[1];
    uint64_t r12[1];
    uint64_t r27[1];
    uint64_t r35[1];
    uint64_t r48[1];
    uint64_t r63[1];
  } test_vec[] = {
    { {  INT64_C( 5072672013399964110) },
      { UINT64_C( 5072672013399964110) },
      {                     UINT64_MAX },
      {                     UINT64_MAX },
      {                     UINT64_MAX },
      {                     UINT64_MAX },
      {                     UINT64_MAX },
      {                     UINT64_MAX } },
    { {  INT64_C( 6677610278852285409) },
      { UINT64_C( 6677610278852285409) },
      {                     UINT64_MAX },
      {                     UINT64_MAX },
      {                     UINT64_MAX },
      {                     UINT64_MAX },
      {                     UINT64_MAX },
      {                     UINT64_MAX } },
    { { -INT64_C( 8033029934178609758) },
      { UINT64_C(                   0) },
      { UINT64_C(                   0) },
      { UINT64_C(                   0) },
      { UINT64_C(                   0) },
      { UINT64_C(                   0) },
      { UINT64_C(                   0) },
      { UINT64_C(                   0) } },
    { {  INT64_C( 3529324990751820018) },
      { UINT64_C( 3529324990751820018) },
      {                     UINT64_MAX },
      {                     UINT64_MAX },
      {                     UINT64_MAX },
      {                     UINT64_MAX },
      {                     UINT64_MAX },
      {                     UINT64_MAX } },
    { {  INT64_C( 7025476331418468327) },
      { UINT64_C( 7025476331418468327) },
      {                     UINT64_MAX },
      {                     UINT64_MAX },
      {                     UINT64_MAX },
      {                     UINT64_MAX },
      {                     UINT64_MAX },
      {                     UINT64_MAX } },
    { {  INT64_C( 4745482970623441748) },
      { UINT64_C( 4745482970623441748) },
      {                     UINT64_MAX },
      {                     UINT64_MAX },
      {                     UINT64_MAX },
      {                     UINT64_MAX },
      {                     UINT64_MAX },
      {                     UINT64_MAX } },
    { { -INT64_C( 1003541852673011796) },
      { UINT64_C(                   0) },
      { UINT64_C(                   0) },
      { UINT64_C(                   0) },
      { UINT64_C(                   0) },
      { UINT64_C(                   0) },
      { UINT64_C(                   0) },
      { UINT64_C(                   0) } },
    { {  INT64_C( 5984773099453005181) },
      { UINT64_C( 5984773099453005181) },
      {                     UINT64_MAX },
      {                     UINT64_MAX },
      {                     UINT64_MAX },
      {                     UINT64_MAX },
      {                     UINT64_MAX },
      {                     UINT64_MAX } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int64x1_t a = simde_vld1_s64(test_vec[i].a);
    simde_uint64x1_t r0 = simde_vqshlu_n_s64(a, 0);
    simde_uint64x1_t r3 = simde_vqshlu_n_s64(a, 3);
    simde_uint64x1_t r12 = simde_vqshlu_n_s64(a, 12);
    simde_uint64x1_t r27 = simde_vqshlu_n_s64(a, 27);
    simde_uint64x1_t r35 = simde_vqshlu_n_s64(a, 35);
    simde_uint64x1_t r48 = simde_vqshlu_n_s64(a, 48);
    simde_uint64x1_t r63 = simde_vqshlu_n_s64(a, 63);

    simde_test_arm_neon_assert_equal_u64x1(r0, simde_vld1_u64(test_vec[i].r0));
    simde_test_arm_neon_assert_equal_u64x1(r3, simde_vld1_u64(test_vec[i].r3));
    simde_test_arm_neon_assert_equal_u64x1(r12, simde_vld1_u64(test_vec[i].r12));
    simde_test_arm_neon_assert_equal_u64x1(r27, simde_vld1_u64(test_vec[i].r27));
    simde_test_arm_neon_assert_equal_u64x1(r35, simde_vld1_u64(test_vec[i].r35));
    simde_test_arm_neon_assert_equal_u64x1(r48, simde_vld1_u64(test_vec[i].r48));
    simde_test_arm_neon_assert_equal_u64x1(r63, simde_vld1_u64(test_vec[i].r63));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int64x1_t a = simde_test_arm_neon_random_i64x1();
    simde_uint64x1_t r0 = simde_vqshlu_n_s64(a, 0);
    simde_uint64x1_t r3 = simde_vqshlu_n_s64(a, 3);
    simde_uint64x1_t r12 = simde_vqshlu_n_s64(a, 12);
    simde_uint64x1_t r27 = simde_vqshlu_n_s64(a, 27);
    simde_uint64x1_t r35 = simde_vqshlu_n_s64(a, 35);
    simde_uint64x1_t r48 = simde_vqshlu_n_s64(a, 48);
    simde_uint64x1_t r63 = simde_vqshlu_n_s64(a, 63);

    simde_test_arm_neon_write_i64x1(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u64x1(2, r0, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u64x1(2, r3, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u64x1(2, r12, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u64x1(2, r27, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u64x1(2, r35, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u64x1(2, r48, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u64x1(2, r63, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vqshluq_n_s8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int8_t a[16];
    const int n;
    uint8_t r[16];
  } test_vec[] = {
    { { -INT8_C(  13), -INT8_C(  72), -INT8_C(  26), -INT8_C(  14), -INT8_C(   8),  INT8_C(  33),  INT8_C(  14),  INT8_C( 109),
         INT8_C(  34), -INT8_C(  11), -INT8_C(  47), -INT8_C(  30),  INT8_C(   2), -INT8_C(  53),  INT8_C( 104), -INT8_C( 114) },
       INT32_C(           0),
      { UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C( 33), UINT8_C( 14), UINT8_C(109),
        UINT8_C( 34), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  2), UINT8_C(  0), UINT8_C(104), UINT8_C(  0) } },
    { { -INT8_C(  53),  INT8_C(  80), -INT8_C(  57), -INT8_C( 121), -INT8_C(   3), -INT8_C(  82),  INT8_C(   7), -INT8_C( 104),
         INT8_C(  56), -INT8_C(  93),      INT8_MAX, -INT8_C( 124), -INT8_C(  69), -INT8_C(  61),  INT8_C( 124), -INT8_C(  82) },
       INT32_C(           1),
      { UINT8_C(  0), UINT8_C(160), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C( 14), UINT8_C(  0),
        UINT8_C(112), UINT8_C(  0), UINT8_C(254), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(248), UINT8_C(  0) } },
    { {  INT8_C( 123),  INT8_C(  98), -INT8_C(  96),  INT8_C( 116), -INT8_C( 125), -INT8_C(  81), -INT8_C(  31), -INT8_C(  91),
        -INT8_C(  92), -INT8_C(  78), -INT8_C( 120), -INT8_C(  89),  INT8_C( 125), -INT8_C(  16),  INT8_C(  53),  INT8_C(  73) },
       INT32_C(           2),
      {    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),
        UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(212),    UINT8_MAX } },
    { {  INT8_C(  64), -INT8_C(   4), -INT8_C(  48),  INT8_C(  61), -INT8_C(  86), -INT8_C(  41), -INT8_C(  43), -INT8_C(  30),
         INT8_C( 123),  INT8_C(  84),  INT8_C( 102),  INT8_C(  54),  INT8_C(  24), -INT8_C(  30), -INT8_C(  27), -INT8_C( 109) },
       INT32_C(           3),
      {    UINT8_MAX, UINT8_C(  0), UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),
           UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(192), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0) } },
    { {  INT8_C(  68), -INT8_C( 123),  INT8_C(   7), -INT8_C(  57),  INT8_C(  52), -INT8_C(  23),  INT8_C( 109), -INT8_C(  39),
        -INT8_C( 101), -INT8_C(  11),      INT8_MIN,  INT8_C(  25), -INT8_C(  27), -INT8_C(  75),  INT8_C(  98),  INT8_C(  37) },
       INT32_C(           4),
      {    UINT8_MAX, UINT8_C(  0), UINT8_C(112), UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),
        UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,    UINT8_MAX } },
    { { -INT8_C(  79),  INT8_C(  50),  INT8_C(  98),  INT8_C(  91),  INT8_C(  10),  INT8_C(  56),  INT8_C(  62), -INT8_C( 123),
        -INT8_C( 116), -INT8_C(  92), -INT8_C(  69), -INT8_C(  92), -INT8_C( 121), -INT8_C(  96),  INT8_C(  56), -INT8_C(  53) },
       INT32_C(           5),
      { UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),
        UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),    UINT8_MAX, UINT8_C(  0) } },
    { {  INT8_C(  38),  INT8_C(  63), -INT8_C( 109),  INT8_C(  90),  INT8_C(  40),  INT8_C(   0),  INT8_C(  51), -INT8_C(  60),
        -INT8_C(  11), -INT8_C(  77), -INT8_C(  35), -INT8_C(  38),  INT8_C( 104),  INT8_C(  63), -INT8_C(   1),  INT8_C(  25) },
       INT32_C(           6),
      {    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),
        UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX } },
    { {  INT8_C( 113),  INT8_C(  97),  INT8_C( 117),  INT8_C( 123), -INT8_C( 103), -INT8_C(  77),  INT8_C(   0),  INT8_C(  38),
         INT8_C(  87), -INT8_C(  68), -INT8_C(  54), -INT8_C(  34),  INT8_C(  92),  INT8_C(   2), -INT8_C(  86), -INT8_C( 126) },
       INT32_C(           7),
      {    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,
           UINT8_MAX, UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,    UINT8_MAX, UINT8_C(  0), UINT8_C(  0) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int8x16_t a = simde_vld1q_s8(test_vec[i].a);
    simde_uint8x16_t r;
    SIMDE_CONSTIFY_8_(simde_vqshluq_n_s8, r, (HEDLEY_UNREACHABLE(), r), test_vec[i].n, a);

    simde_test_arm_neon_assert_equal_u8x16(r, simde_vld1q_u8(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  const int n[] = { 0, 1, 2, 3, 4, 5, 6, 7 };
  for (int i = 0 ; i < 8 ; i++) {
    simde_int8x16_t a = simde_test_arm_neon_random_i8x16();
    simde_uint8x16_t r;
    SIMDE_CONSTIFY_8_(simde_vqshluq_n_s8, r, (HEDLEY_UNREACHABLE(), r), n[i], a);

    simde_test_arm_neon_write_i8x16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_i32(2, n[i], SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u8x16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vqshluq_n_s16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int16_t a[8];
    uint16_t r0[8];
    uint16_t r2[8];
    uint16_t r5[8];
    uint16_t r9[8];
    uint16_t r10[8];
    uint16_t r13[8];
    uint16_t r15[8];
  } test_vec[] = {
    { {  INT16_C(  7690), -INT16_C(  5215),  INT16_C(  8941), -INT16_C(  2856), -INT16_C( 19412), -INT16_C( 31048),  INT16_C(  2621), -INT16_C( 11962) },
      { UINT16_C( 7690), UINT16_C(    0), UINT16_C( 8941), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C( 2621), UINT16_C(    0) },
      { UINT16_C(30760), UINT16_C(    0), UINT16_C(35764), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(10484), UINT16_C(    0) },
      {      UINT16_MAX, UINT16_C(    0),      UINT16_MAX, UINT16_C(    0), UINT16_C(    0), UINT16_C(    0),      UINT16_MAX, UINT16_C(    0) },
      {      UINT16_MAX, UINT16_C(    0),      UINT16_MAX, UINT16_C(    0), UINT16_C(    0), UINT16_C(    0),      UINT16_MAX, UINT16_C(    0) },
      {      UINT16_MAX, UINT16_C(    0),      UINT16_MAX, UINT16_C(    0), UINT16_C(    0), UINT16_C(    0),      UINT16_MAX, UINT16_C(    0) },
      {      UINT16_MAX, UINT16_C(    0),      UINT16_MAX, UINT16_C(    0), UINT16_C(    0), UINT16_C(    0),      UINT16_MAX, UINT16_C(    0) },
      {      UINT16_MAX, UINT16_C(    0),      UINT16_MAX, UINT16_C(    0), UINT16_C(    0), UINT16_C(    0),      UINT16_MAX, UINT16_C(    0) } },
    { {  INT16_C(   485),  INT16_C( 17765),  INT16_C( 24754), -INT16_C( 19795), -INT16_C( 22943), -INT16_C(  9095),  INT16_C( 22537),  INT16_C(  5055) },
      { UINT16_C(  485), UINT16_C(17765), UINT16_C(24754), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(22537), UINT16_C( 5055) },
      { UINT16_C( 1940),      UINT16_MAX,      UINT16_MAX, UINT16_C(    0), UINT16_C(    0), UINT16_C(    0),      UINT16_MAX, UINT16_C(20220) },
      { UINT16_C(15520),      UINT16_MAX,      UINT16_MAX, UINT16_C(    0), UINT16_C(    0), UINT16_C(    0),      UINT16_MAX,      UINT16_MAX },
      {      UINT16_MAX,      UINT16_MAX,      UINT16_MAX, UINT16_C(    0), UINT16_C(    0), UINT16_C(    0),      UINT16_MAX,      UINT16_MAX },
      {      UINT16_MAX,      UINT16_MAX,      UINT16_MAX, UINT16_C(    0), UINT16_C(    0), UINT16_C(    0),      UINT16_MAX,      UINT16_MAX },
      {      UINT16_MAX,      UINT16_MAX,      UINT16_MAX, UINT16_C(    0), UINT16_C(    0), UINT16_C(    0),      UINT16_MAX,      UINT16_MAX },
      {      UINT16_MAX,      UINT16_MAX,      UINT16_MAX, UINT16_C(    0), UINT16_C(    0), UINT16_C(    0),      UINT16_MAX,      UINT16_MAX } },
    { {  INT16_C( 24694),  INT16_C( 25854), -INT16_C( 10622), -INT16_C( 20648),  INT16_C(  4490), -INT16_C( 14539),  INT16_C( 31771),  INT16_C(   409) },
      { UINT16_C(24694), UINT16_C(25854), UINT16_C(    0), UINT16_C(    0), UINT16_C( 4490), UINT16_C(    0), UINT16_C(31771), UINT16_C(  409) },
      {      UINT16_MAX,      UINT16_MAX, UINT16_C(    0), UINT16_C(    0), UINT16_C(17960), UINT16_C(    0),      UINT16_MAX, UINT16_C( 1636) },
      {      UINT16_MAX,      UINT16_MAX, UINT16_C(    0), UINT16_C(    0),      UINT16_MAX, UINT16_C(    0),      UINT16_MAX, UINT16_C(13088) },
      {      UINT16_MAX,      UINT16_MAX, UINT16_C(    0), UINT16_C(    0),      UINT16_MAX, UINT16_C(    0),      UINT16_MAX,      UINT16_MAX },
      {      UINT16_MAX,      UINT16_MAX, UINT16_C(    0), UINT16_C(    0),      UINT16_MAX, UINT16_C(    0),      UINT16_MAX,      UINT16_MAX },
      {      UINT16_MAX,      UINT16_MAX, UINT16_C(    0), UINT16_C(    0),      UINT16_MAX, UINT16_C(    0),      UINT16_MAX,      UINT16_MAX },
      {      UINT16_MAX,      UINT16_MAX, UINT16_C(    0), UINT16_C(    0),      UINT16_MAX, UINT16_C(    0),      UINT16_MAX,      UINT16_MAX } },
    { { -INT16_C(   387),  INT16_C( 12358), -INT16_C(  2978), -INT16_C( 16414),  INT16_C( 23450), -INT16_C( 23397),  INT16_C( 23219),  INT16_C( 10935) },
      { UINT16_C(    0), UINT16_C(12358), UINT16_C(    0), UINT16_C(    0), UINT16_C(23450), UINT16_C(    0), UINT16_C(23219), UINT16_C(10935) },
      { UINT16_C(    0), UINT16_C(49432), UINT16_C(    0), UINT16_C(    0),      UINT16_MAX, UINT16_C(    0),      UINT16_MAX, UINT16_C(43740) },
      { UINT16_C(    0),      UINT16_MAX, UINT16_C(    0), UINT16_C(    0),      UINT16_MAX, UINT16_C(    0),      UINT16_MAX,      UINT16_MAX },
      { UINT16_C(    0),      UINT16_MAX, UINT16_C(    0), UINT16_C(    0),      UINT16_MAX, UINT16_C(    0),      UINT16_MAX,      UINT16_MAX },
      { UINT16_C(    0),      UINT16_MAX, UINT16_C(    0), UINT16_C(    0),      UINT16_MAX, UINT16_C(    0),      UINT16_MAX,      UINT16_MAX },
      { UINT16_C(    0),      UINT16_MAX, UINT16_C(    0), UINT16_C(    0),      UINT16_MAX, UINT16_C(    0),      UINT16_MAX,      UINT16_MAX },
      { UINT16_C(    0),      UINT16_MAX, UINT16_C(    0), UINT16_C(    0),      UINT16_MAX, UINT16_C(    0),      UINT16_MAX,      UINT16_MAX } },
    { { -INT16_C( 18757),  INT16_C( 15758), -INT16_C(  6516),  INT16_C(  6124),  INT16_C(  8951),  INT16_C(  5086),  INT16_C( 30622),  INT16_C(  6932) },
      { UINT16_C(    0), UINT16_C(15758), UINT16_C(    0), UINT16_C( 6124), UINT16_C( 8951), UINT16_C( 5086), UINT16_C(30622), UINT16_C( 6932) },
      { UINT16_C(    0), UINT16_C(63032), UINT16_C(    0), UINT16_C(24496), UINT16_C(35804), UINT16_C(20344),      UINT16_MAX, UINT16_C(27728) },
      { UINT16_C(    0),      UINT16_MAX, UINT16_C(    0),      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX },
      { UINT16_C(    0),      UINT16_MAX, UINT16_C(    0),      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX },
      { UINT16_C(    0),      UINT16_MAX, UINT16_C(    0),      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX },
      { UINT16_C(    0),      UINT16_MAX, UINT16_C(    0),      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX },
      { UINT16_C(    0),      UINT16_MAX, UINT16_C(    0),      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX } },
    { {  INT16_C( 23157), -INT16_C( 11445),  INT16_C( 11598), -INT16_C(  5741),  INT16_C( 11913),  INT16_C( 15501),  INT16_C( 17545),  INT16_C( 17510) },
      { UINT16_C(23157), UINT16_C(    0), UINT16_C(11598), UINT16_C(    0), UINT16_C(11913), UINT16_C(15501), UINT16_C(17545), UINT16_C(17510) },
      {      UINT16_MAX, UINT16_C(    0), UINT16_C(46392), UINT16_C(    0), UINT16_C(47652), UINT16_C(62004),      UINT16_MAX,      UINT16_MAX },
      {      UINT16_MAX, UINT16_C(    0),      UINT16_MAX, UINT16_C(    0),      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX },
      {      UINT16_MAX, UINT16_C(    0),      UINT16_MAX, UINT16_C(    0),      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX },
      {      UINT16_MAX, UINT16_C(    0),      UINT16_MAX, UINT16_C(    0),      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX },
      {      UINT16_MAX, UINT16_C(    0),      UINT16_MAX, UINT16_C(    0),      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX },
      {      UINT16_MAX, UINT16_C(    0),      UINT16_MAX, UINT16_C(    0),      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX } },
    { { -INT16_C(  2822), -INT16_C( 30847),  INT16_C( 28379), -INT16_C( 11618),  INT16_C( 31888),  INT16_C( 12005), -INT16_C(  1548),  INT16_C( 26953) },
      { UINT16_C(    0), UINT16_C(    0), UINT16_C(28379), UINT16_C(    0), UINT16_C(31888), UINT16_C(12005), UINT16_C(    0), UINT16_C(26953) },
      { UINT16_C(    0), UINT16_C(    0),      UINT16_MAX, UINT16_C(    0),      UINT16_MAX, UINT16_C(48020), UINT16_C(    0),      UINT16_MAX },
      { UINT16_C(    0), UINT16_C(    0),      UINT16_MAX, UINT16_C(    0),      UINT16_MAX,      UINT16_MAX, UINT16_C(    0),      UINT16_MAX },
      { UINT16_C(    0), UINT16_C(    0),      UINT16_MAX, UINT16_C(    0),      UINT16_MAX,      UINT16_MAX, UINT16_C(    0),      UINT16_MAX },
      { UINT16_C(    0), UINT16_C(    0),      UINT16_MAX, UINT16_C(    0),      UINT16_MAX,      UINT16_MAX, UINT16_C(    0),      UINT16_MAX },
      { UINT16_C(    0), UINT16_C(    0),      UINT16_MAX, UINT16_C(    0),      UINT16_MAX,      UINT16_MAX, UINT16_C(    0),      UINT16_MAX },
      { UINT16_C(    0), UINT16_C(    0),      UINT16_MAX, UINT16_C(    0),      UINT16_MAX,      UINT16_MAX, UINT16_C(    0),      UINT16_MAX } },
    { { -INT16_C( 27308), -INT16_C( 24003), -INT16_C( 12094),  INT16_C( 19339),  INT16_C(  6398), -INT16_C( 30840), -INT16_C(  4515),  INT16_C( 22475) },
      { UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(19339), UINT16_C( 6398), UINT16_C(    0), UINT16_C(    0), UINT16_C(22475) },
      { UINT16_C(    0), UINT16_C(    0), UINT16_C(    0),      UINT16_MAX, UINT16_C(25592), UINT16_C(    0), UINT16_C(    0),      UINT16_MAX },
      { UINT16_C(    0), UINT16_C(    0), UINT16_C(    0),      UINT16_MAX,      UINT16_MAX, UINT16_C(    0), UINT16_C(    0),      UINT16_MAX },
      { UINT16_C(    0), UINT16_C(    0), UINT16_C(    0),      UINT16_MAX,      UINT16_MAX, UINT16_C(    0), UINT16_C(    0),      UINT16_MAX },
      { UINT16_C(    0), UINT16_C(    0), UINT16_C(    0),      UINT16_MAX,      UINT16_MAX, UINT16_C(    0), UINT16_C(    0),      UINT16_MAX },
      { UINT16_C(    0), UINT16_C(    0), UINT16_C(    0),      UINT16_MAX,      UINT16_MAX, UINT16_C(    0), UINT16_C(    0),      UINT16_MAX },
      { UINT16_C(    0), UINT16_C(    0), UINT16_C(    0),      UINT16_MAX,      UINT16_MAX, UINT16_C(    0), UINT16_C(    0),      UINT16_MAX } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x8_t a = simde_vld1q_s16(test_vec[i].a);
    simde_uint16x8_t r0 = simde_vqshluq_n_s16(a, 0);
    simde_uint16x8_t r2 = simde_vqshluq_n_s16(a, 2);
    simde_uint16x8_t r5 = simde_vqshluq_n_s16(a, 5);
    simde_uint16x8_t r9 = simde_vqshluq_n_s16(a, 9);
    simde_uint16x8_t r10 = simde_vqshluq_n_s16(a, 10);
    simde_uint16x8_t r13 = simde_vqshluq_n_s16(a, 13);
    simde_uint16x8_t r15 = simde_vqshluq_n_s16(a, 15);

    simde_test_arm_neon_assert_equal_u16x8(r0, simde_vld1q_u16(test_vec[i].r0));
    simde_test_arm_neon_assert_equal_u16x8(r2, simde_vld1q_u16(test_vec[i].r2));
    simde_test_arm_neon_assert_equal_u16x8(r5, simde_vld1q_u16(test_vec[i].r5));
    simde_test_arm_neon_assert_equal_u16x8(r9, simde_vld1q_u16(test_vec[i].r9));
    simde_test_arm_neon_assert_equal_u16x8(r10, simde_vld1q_u16(test_vec[i].r10));
    simde_test_arm_neon_assert_equal_u16x8(r13, simde_vld1q_u16(test_vec[i].r13));
    simde_test_arm_neon_assert_equal_u16x8(r15, simde_vld1q_u16(test_vec[i].r15));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int16x8_t a = simde_test_arm_neon_random_i16x8();
    simde_uint16x8_t r0 = simde_vqshluq_n_s16(a, 0);
    simde_uint16x8_t r2 = simde_vqshluq_n_s16(a, 2);
    simde_uint16x8_t r5 = simde_vqshluq_n_s16(a, 5);
    simde_uint16x8_t r9 = simde_vqshluq_n_s16(a, 9);
    simde_uint16x8_t r10 = simde_vqshluq_n_s16(a, 10);
    simde_uint16x8_t r13 = simde_vqshluq_n_s16(a, 13);
    simde_uint16x8_t r15 = simde_vqshluq_n_s16(a, 15);

    simde_test_arm_neon_write_i16x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u16x8(2, r0, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u16x8(2, r2, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u16x8(2, r5, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u16x8(2, r9, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u16x8(2, r10, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u16x8(2, r13, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u16x8(2, r15, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vqshluq_n_s32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int32_t a[4];
    uint32_t r0[4];
    uint32_t r4[4];
    uint32_t r10[4];
    uint32_t r15[4];
    uint32_t r23[4];
    uint32_t r28[4];
    uint32_t r31[4];
  } test_vec[] = {
    { {  INT32_C(   347520906),  INT32_C(  1268454275), -INT32_C(    44010171),  INT32_C(  2018331281) },
      { UINT32_C( 347520906), UINT32_C(1268454275), UINT32_C(         0), UINT32_C(2018331281) },
      {           UINT32_MAX,           UINT32_MAX, UINT32_C(         0),           UINT32_MAX },
      {           UINT32_MAX,           UINT32_MAX, UINT32_C(         0),           UINT32_MAX },
      {           UINT32_MAX,           UINT32_MAX, UINT32_C(         0),           UINT32_MAX },
      {           UINT32_MAX,           UINT32_MAX, UINT32_C(         0),           UINT32_MAX },
      {           UINT32_MAX,           UINT32_MAX, UINT32_C(         0),           UINT32_MAX },
      {           UINT32_MAX,           UINT32_MAX, UINT32_C(         0),           UINT32_MAX } },
    { {  INT32_C(   803026077), -INT32_C(  1721349556),  INT32_C(  1100880288), -INT32_C(   705448886) },
      { UINT32_C( 803026077), UINT32_C(         0), UINT32_C(1100880288), UINT32_C(         0) },
      {           UINT32_MAX, UINT32_C(         0),           UINT32_MAX, UINT32_C(         0) },
      {           UINT32_MAX, UINT32_C(         0),           UINT32_MAX, UINT32_C(         0) },
      {           UINT32_MAX, UINT32_C(         0),           UINT32_MAX, UINT32_C(         0) },
      {           UINT32_MAX, UINT32_C(         0),           UINT32_MAX, UINT32_C(         0) },
      {           UINT32_MAX, UINT32_C(         0),           UINT32_MAX, UINT32_C(         0) },
      {           UINT32_MAX, UINT32_C(         0),           UINT32_MAX, UINT32_C(         0) } },
    { { -INT32_C(   152458893),  INT32_C(    37848253), -INT32_C(  1946180870), -INT32_C(  1996272404) },
      { UINT32_C(         0), UINT32_C(  37848253), UINT32_C(         0), UINT32_C(         0) },
      { UINT32_C(         0), UINT32_C( 605572048), UINT32_C(         0), UINT32_C(         0) },
      { UINT32_C(         0),           UINT32_MAX, UINT32_C(         0), UINT32_C(         0) },
      { UINT32_C(         0),           UINT32_MAX, UINT32_C(         0), UINT32_C(         0) },
      { UINT32_C(         0),           UINT32_MAX, UINT32_C(         0), UINT32_C(         0) },
      { UINT32_C(         0),           UINT32_MAX, UINT32_C(         0), UINT32_C(         0) },
      { UINT32_C(         0),           UINT32_MAX, UINT32_C(         0), UINT32_C(         0) } },
    { { -INT32_C(   860233600), -INT32_C(   882499797), -INT32_C(  2096364488),  INT32_C(   744030136) },
      { UINT32_C(         0), UINT32_C(         0), UINT32_C(         0), UINT32_C( 744030136) },
      { UINT32_C(         0), UINT32_C(         0), UINT32_C(         0),           UINT32_MAX },
      { UINT32_C(         0), UINT32_C(         0), UINT32_C(         0),           UINT32_MAX },
      { UINT32_C(         0), UINT32_C(         0), UINT32_C(         0),           UINT32_MAX },
      { UINT32_C(         0), UINT32_C(         0), UINT32_C(         0),           UINT32_MAX },
      { UINT32_C(         0), UINT32_C(         0), UINT32_C(         0),           UINT32_MAX },
      { UINT32_C(         0), UINT32_C(         0), UINT32_C(         0),           UINT32_MAX } },
    { {  INT32_C(  1713521065), -INT32_C(  1066900282), -INT32_C(   229939450),  INT32_C(   863784627) },
      { UINT32_C(1713521065), UINT32_C(         0), UINT32_C(         0), UINT32_C( 863784627) },
      {           UINT32_MAX, UINT32_C(         0), UINT32_C(         0),           UINT32_MAX },
      {           UINT32_MAX, UINT32_C(         0), UINT32_C(         0),           UINT32_MAX },
      {           UINT32_MAX, UINT32_C(         0), UINT32_C(         0),           UINT32_MAX },
      {           UINT32_MAX, UINT32_C(         0), UINT32_C(         0),           UINT32_MAX },
      {           UINT32_MAX, UINT32_C(         0), UINT32_C(         0),           UINT32_MAX },
      {           UINT32_MAX, UINT32_C(         0), UINT32_C(         0),           UINT32_MAX } },
    { {  INT32_C(  1493185838), -INT32_C(  1943706028),  INT32_C(   571421034), -INT32_C(   632395983) },
      { UINT32_C(1493185838), UINT32_C(         0), UINT32_C( 571421034), UINT32_C(         0) },
      {           UINT32_MAX, UINT32_C(         0),           UINT32_MAX, UINT32_C(         0) },
      {           UINT32_MAX, UINT32_C(         0),           UINT32_MAX, UINT32_C(         0) },
      {           UINT32_MAX, UINT32_C(         0),           UINT32_MAX, UINT32_C(         0) },
      {           UINT32_MAX, UINT32_C(         0),           UINT32_MAX, UINT32_C(         0) },
      {           UINT32_MAX, UINT32_C(         0),           UINT32_MAX, UINT32_C(         0) },
      {           UINT32_MAX, UINT32_C(         0),           UINT32_MAX, UINT32_C(         0) } },
    { {  INT32_C(  1866494377), -INT32_C(   617633579), -INT32_C(  1026721265), -INT32_C(   151696952) },
      { UINT32_C(1866494377), UINT32_C(         0), UINT32_C(         0), UINT32_C(         0) },
      {           UINT32_MAX, UINT32_C(         0), UINT32_C(         0), UINT32_C(         0) },
      {           UINT32_MAX, UINT32_C(         0), UINT32_C(         0), UINT32_C(         0) },
      {           UINT32_MAX, UINT32_C(         0), UINT32_C(         0), UINT32_C(         0) },
      {           UINT32_MAX, UINT32_C(         0), UINT32_C(         0), UINT32_C(         0) },
      {           UINT32_MAX, UINT32_C(         0), UINT32_C(         0), UINT32_C(         0) },
      {           UINT32_MAX, UINT32_C(         0), UINT32_C(         0), UINT32_C(         0) } },
    { { -INT32_C(   766446210), -INT32_C(   983599781), -INT32_C(   672633178),  INT32_C(  2142320342) },
      { UINT32_C(         0), UINT32_C(         0), UINT32_C(         0), UINT32_C(2142320342) },
      { UINT32_C(         0), UINT32_C(         0), UINT32_C(         0),           UINT32_MAX },
      { UINT32_C(         0), UINT32_C(         0), UINT32_C(         0),           UINT32_MAX },
      { UINT32_C(         0), UINT32_C(         0), UINT32_C(         0),           UINT32_MAX },
      { UINT32_C(         0), UINT32_C(         0), UINT32_C(         0),           UINT32_MAX },
      { UINT32_C(         0), UINT32_C(         0), UINT32_C(         0),           UINT32_MAX },
      { UINT32_C(         0), UINT32_C(         0), UINT32_C(         0),           UINT32_MAX } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x4_t a = simde_vld1q_s32(test_vec[i].a);
    simde_uint32x4_t r0 = simde_vqshluq_n_s32(a, 0);
    simde_uint32x4_t r4 = simde_vqshluq_n_s32(a, 4);
    simde_uint32x4_t r10 = simde_vqshluq_n_s32(a, 10);
    simde_uint32x4_t r15 = simde_vqshluq_n_s32(a, 15);
    simde_uint32x4_t r23 = simde_vqshluq_n_s32(a, 23);
    simde_uint32x4_t r28 = simde_vqshluq_n_s32(a, 28);
    simde_uint32x4_t r31 = simde_vqshluq_n_s32(a, 31);

    simde_test_arm_neon_assert_equal_u32x4(r0, simde_vld1q_u32(test_vec[i].r0));
    simde_test_arm_neon_assert_equal_u32x4(r4, simde_vld1q_u32(test_vec[i].r4));
    simde_test_arm_neon_assert_equal_u32x4(r10, simde_vld1q_u32(test_vec[i].r10));
    simde_test_arm_neon_assert_equal_u32x4(r15, simde_vld1q_u32(test_vec[i].r15));
    simde_test_arm_neon_assert_equal_u32x4(r23, simde_vld1q_u32(test_vec[i].r23));
    simde_test_arm_neon_assert_equal_u32x4(r28, simde_vld1q_u32(test_vec[i].r28));
    simde_test_arm_neon_assert_equal_u32x4(r31, simde_vld1q_u32(test_vec[i].r31));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int32x4_t a = simde_test_arm_neon_random_i32x4();
    simde_uint32x4_t r0 = simde_vqshluq_n_s32(a, 0);
    simde_uint32x4_t r4 = simde_vqshluq_n_s32(a, 4);
    simde_uint32x4_t r10 = simde_vqshluq_n_s32(a, 10);
    simde_uint32x4_t r15 = simde_vqshluq_n_s32(a, 15);
    simde_uint32x4_t r23 = simde_vqshluq_n_s32(a, 23);
    simde_uint32x4_t r28 = simde_vqshluq_n_s32(a, 28);
    simde_uint32x4_t r31 = simde_vqshluq_n_s32(a, 31);

    simde_test_arm_neon_write_i32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u32x4(2, r0, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x4(2, r4, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x4(2, r10, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x4(2, r15, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x4(2, r23, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x4(2, r28, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x4(2, r31, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vqshluq_n_s64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int64_t a[2];
    uint64_t r0[2];
    uint64_t r3[2];
    uint64_t r12[2];
    uint64_t r27[2];
    uint64_t r35[2];
    uint64_t r48[2];
    uint64_t r63[2];
  } test_vec[] = {
    { { -INT64_C( 1209751964727193159), -INT64_C( 2341309450467053371) },
          { UINT64_C(                   0), UINT64_C(                   0) },
          { UINT64_C(                   0), UINT64_C(                   0) },
          { UINT64_C(                   0), UINT64_C(                   0) },
          { UINT64_C(                   0), UINT64_C(                   0) },
          { UINT64_C(                   0), UINT64_C(                   0) },
          { UINT64_C(                   0), UINT64_C(                   0) },
          { UINT64_C(                   0), UINT64_C(                   0) } },
        { {  INT64_C(  492815255323390162), -INT64_C( 1365191897190827129) },
          { UINT64_C(  492815255323390162), UINT64_C(                   0) },
          { UINT64_C( 3942522042587121296), UINT64_C(                   0) },
          {                     UINT64_MAX, UINT64_C(                   0) },
          {                     UINT64_MAX, UINT64_C(                   0) },
          {                     UINT64_MAX, UINT64_C(                   0) },
          {                     UINT64_MAX, UINT64_C(                   0) },
          {                     UINT64_MAX, UINT64_C(                   0) } },
        { {  INT64_C(  404628253405423535),  INT64_C( 1534651336357594104) },
          { UINT64_C(  404628253405423535), UINT64_C( 1534651336357594104) },
          { UINT64_C( 3237026027243388280), UINT64_C(12277210690860752832) },
          {                     UINT64_MAX,                     UINT64_MAX },
          {                     UINT64_MAX,                     UINT64_MAX },
          {                     UINT64_MAX,                     UINT64_MAX },
          {                     UINT64_MAX,                     UINT64_MAX },
          {                     UINT64_MAX,                     UINT64_MAX } },
        { {  INT64_C( 1856051024682204894),  INT64_C(    9011946065458431) },
          { UINT64_C( 1856051024682204894), UINT64_C(    9011946065458431) },
          { UINT64_C(14848408197457639152), UINT64_C(   72095568523667448) },
          {                     UINT64_MAX,                     UINT64_MAX },
          {                     UINT64_MAX,                     UINT64_MAX },
          {                     UINT64_MAX,                     UINT64_MAX },
          {                     UINT64_MAX,                     UINT64_MAX },
          {                     UINT64_MAX,                     UINT64_MAX } },
        { { -INT64_C( 1121311677372993237),  INT64_C( 2947511719470898575) },
          { UINT64_C(                   0), UINT64_C( 2947511719470898575) },
          { UINT64_C(                   0),                     UINT64_MAX },
          { UINT64_C(                   0),                     UINT64_MAX },
          { UINT64_C(                   0),                     UINT64_MAX },
          { UINT64_C(                   0),                     UINT64_MAX },
          { UINT64_C(                   0),                     UINT64_MAX },
          { UINT64_C(                   0),                     UINT64_MAX } },
        { {  INT64_C( 1735194386958128488),  INT64_C( 4209857465653332762) },
          { UINT64_C( 1735194386958128488), UINT64_C( 4209857465653332762) },
          { UINT64_C(13881555095665027904),                     UINT64_MAX },
          {                     UINT64_MAX,                     UINT64_MAX },
          {                     UINT64_MAX,                     UINT64_MAX },
          {                     UINT64_MAX,                     UINT64_MAX },
          {                     UINT64_MAX,                     UINT64_MAX },
          {                     UINT64_MAX,                     UINT64_MAX } },
        { { -INT64_C(  593043140707476516),  INT64_C( 3865971726786044723) },
          { UINT64_C(                   0), UINT64_C( 3865971726786044723) },
          { UINT64_C(                   0),                     UINT64_MAX },
          { UINT64_C(                   0),                     UINT64_MAX },
          { UINT64_C(                   0),                     UINT64_MAX },
          { UINT64_C(                   0),                     UINT64_MAX },
          { UINT64_C(                   0),                     UINT64_MAX },
          { UINT64_C(                   0),                     UINT64_MAX } },
        { {  INT64_C( 5401578680242637509), -INT64_C( 8459973772018564530) },
          { UINT64_C( 5401578680242637509), UINT64_C(                   0) },
          {                     UINT64_MAX, UINT64_C(                   0) },
          {                     UINT64_MAX, UINT64_C(                   0) },
          {                     UINT64_MAX, UINT64_C(                   0) },
          {                     UINT64_MAX, UINT64_C(                   0) },
          {                     UINT64_MAX, UINT64_C(                   0) },
          {                     UINT64_MAX, UINT64_C(                   0) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int64x2_t a = simde_vld1q_s64(test_vec[i].a);
    simde_uint64x2_t r0 = simde_vqshluq_n_s64(a, 0);
    simde_uint64x2_t r3 = simde_vqshluq_n_s64(a, 3);
    simde_uint64x2_t r12 = simde_vqshluq_n_s64(a, 12);
    simde_uint64x2_t r27 = simde_vqshluq_n_s64(a, 27);
    simde_uint64x2_t r35 = simde_vqshluq_n_s64(a, 35);
    simde_uint64x2_t r48 = simde_vqshluq_n_s64(a, 48);
    simde_uint64x2_t r63 = simde_vqshluq_n_s64(a, 63);

    simde_test_arm_neon_assert_equal_u64x2(r0, simde_vld1q_u64(test_vec[i].r0));
    simde_test_arm_neon_assert_equal_u64x2(r3, simde_vld1q_u64(test_vec[i].r3));
    simde_test_arm_neon_assert_equal_u64x2(r12, simde_vld1q_u64(test_vec[i].r12));
    simde_test_arm_neon_assert_equal_u64x2(r27, simde_vld1q_u64(test_vec[i].r27));
    simde_test_arm_neon_assert_equal_u64x2(r35, simde_vld1q_u64(test_vec[i].r35));
    simde_test_arm_neon_assert_equal_u64x2(r48, simde_vld1q_u64(test_vec[i].r48));
    simde_test_arm_neon_assert_equal_u64x2(r63, simde_vld1q_u64(test_vec[i].r63));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int64x2_t a = simde_test_arm_neon_random_i64x2();
    simde_uint64x2_t r0 = simde_vqshluq_n_s64(a, 0);
    simde_uint64x2_t r3 = simde_vqshluq_n_s64(a, 3);
    simde_uint64x2_t r12 = simde_vqshluq_n_s64(a, 12);
    simde_uint64x2_t r27 = simde_vqshluq_n_s64(a, 27);
    simde_uint64x2_t r35 = simde_vqshluq_n_s64(a, 35);
    simde_uint64x2_t r48 = simde_vqshluq_n_s64(a, 48);
    simde_uint64x2_t r63 = simde_vqshluq_n_s64(a, 63);

    simde_test_arm_neon_write_i64x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u64x2(2, r0, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u64x2(2, r3, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u64x2(2, r12, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u64x2(2, r27, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u64x2(2, r35, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u64x2(2, r48, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u64x2(2, r63, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(vqshluh_n_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vqshlus_n_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vqshlud_n_s64)

SIMDE_TEST_FUNC_LIST_ENTRY(vqshlu_n_s8)
SIMDE_TEST_FUNC_LIST_ENTRY(vqshlu_n_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vqshlu_n_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vqshlu_n_s64)

SIMDE_TEST_FUNC_LIST_ENTRY(vqshluq_n_s8)
SIMDE_TEST_FUNC_LIST_ENTRY(vqshluq_n_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vqshluq_n_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vqshluq_n_s64)
SIMDE_TEST_FUNC_LIST_END

#include "test-neon-footer.h"
