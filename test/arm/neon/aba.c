#define SIMDE_TEST_ARM_NEON_INSN aba

#include "test-neon.h"
#include "../../../simde/arm/neon/aba.h"

/* https://community.intel.com/t5/Intel-C-Compiler/ICC-generates-incorrect-code/td-p/1199261 */
#if defined(HEDLEY_INTEL_VERSION)
#  define TEST_SIMDE_VABD_NO_TEST_32
#endif

static int
test_simde_vaba_s8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int8_t a[8];
    int8_t b[8];
    int8_t c[8];
    int8_t r[8];
  } test_vec[] = {
    { { -INT8_C(  63), -INT8_C(  30),  INT8_C(  29), -INT8_C(  57), -INT8_C(  97), -INT8_C(  25), -INT8_C(  66), -INT8_C(  96) },
      { -INT8_C( 103),  INT8_C(  34),  INT8_C(  89),  INT8_C(   7), -INT8_C(  11),  INT8_C( 119), -INT8_C(  68),  INT8_C(   2) },
      {  INT8_C(  18),  INT8_C(  15),  INT8_C(  41), -INT8_C(  14), -INT8_C(  24),      INT8_MIN, -INT8_C(  66), -INT8_C( 116) },
      {  INT8_C(  58), -INT8_C(  11),  INT8_C(  77), -INT8_C(  36), -INT8_C(  84), -INT8_C(  34), -INT8_C(  64),  INT8_C(  22) } },
    { {  INT8_C(  10), -INT8_C(  95), -INT8_C(  46),  INT8_C(  88),  INT8_C(  46),  INT8_C(  34),  INT8_C(  80), -INT8_C(  17) },
      {  INT8_C(   4),  INT8_C( 109), -INT8_C(  73), -INT8_C(  93),  INT8_C(  85),  INT8_C( 117),  INT8_C(  67), -INT8_C(  18) },
      { -INT8_C( 104), -INT8_C(  99), -INT8_C(  10), -INT8_C( 115),  INT8_C(  20), -INT8_C(  78), -INT8_C( 113),  INT8_C(  39) },
      {  INT8_C( 118),  INT8_C( 113),  INT8_C(  17),  INT8_C( 110),  INT8_C( 111), -INT8_C(  27),  INT8_C(   4),  INT8_C(  40) } },
    { { -INT8_C(  62), -INT8_C(  71),  INT8_C(  25), -INT8_C(  86),  INT8_C(  57), -INT8_C(  40),  INT8_C(  55),  INT8_C(  67) },
      {  INT8_C( 121),  INT8_C(   9), -INT8_C( 101), -INT8_C(  89),  INT8_C(  43), -INT8_C(  20), -INT8_C( 105),  INT8_C(  47) },
      {  INT8_C(  89),  INT8_C(  78), -INT8_C(  45), -INT8_C(  82), -INT8_C(  61),  INT8_C(  22), -INT8_C(  99),  INT8_C(  91) },
      { -INT8_C(  30), -INT8_C(   2),  INT8_C(  81), -INT8_C(  79), -INT8_C(  95),  INT8_C(   2),  INT8_C(  61),  INT8_C( 111) } },
    { { -INT8_C(  77), -INT8_C( 109), -INT8_C(  23), -INT8_C(  56),  INT8_C(  69),  INT8_C( 120), -INT8_C(  17),  INT8_C(   7) },
      {  INT8_C(  49),  INT8_C(   8), -INT8_C(  78),  INT8_C( 106), -INT8_C(  32), -INT8_C(  23), -INT8_C(  83),  INT8_C(  89) },
      { -INT8_C(  14),  INT8_C(  73),  INT8_C(   1),  INT8_C(  29),  INT8_C(  53), -INT8_C( 104),  INT8_C(  76), -INT8_C( 114) },
      { -INT8_C(  14), -INT8_C(  44),  INT8_C(  56),  INT8_C(  21), -INT8_C( 102), -INT8_C(  55), -INT8_C( 114), -INT8_C(  46) } },
    { { -INT8_C(  26),  INT8_C(  31),  INT8_C(  61), -INT8_C(  87),  INT8_C(  54), -INT8_C(  38),  INT8_C(   5), -INT8_C(  23) },
      {  INT8_C( 109), -INT8_C(  18), -INT8_C(  79), -INT8_C(  78),  INT8_C( 102), -INT8_C(  96), -INT8_C(  70), -INT8_C( 104) },
      { -INT8_C(  87),  INT8_C( 108),  INT8_C(   2), -INT8_C( 119),  INT8_C(  85), -INT8_C(  80), -INT8_C(  29),  INT8_C(  71) },
      { -INT8_C(  86), -INT8_C(  99), -INT8_C( 114), -INT8_C(  46),  INT8_C(  71), -INT8_C(  22),  INT8_C(  46), -INT8_C( 104) } },
    { { -INT8_C(   7), -INT8_C(  28),  INT8_C( 100),  INT8_C(  46),  INT8_C( 124), -INT8_C(  80), -INT8_C(  68),  INT8_C(  98) },
      { -INT8_C(  48), -INT8_C(   7),  INT8_C(  11),  INT8_C(   6), -INT8_C(  45),  INT8_C(  16), -INT8_C(  17),  INT8_C(  64) },
      { -INT8_C(   2), -INT8_C(  95), -INT8_C(  13),  INT8_C( 101),  INT8_C(  65), -INT8_C(  83), -INT8_C(   3), -INT8_C(  22) },
      {  INT8_C(  39),  INT8_C(  60),  INT8_C( 124), -INT8_C( 115), -INT8_C(  22),  INT8_C(  19), -INT8_C(  54), -INT8_C(  72) } },
    { {  INT8_C(  25), -INT8_C(   1),  INT8_C( 116),  INT8_C( 110), -INT8_C(  81),  INT8_C(  87), -INT8_C(  75), -INT8_C(  88) },
      {  INT8_C(  59),  INT8_C(  25), -INT8_C(  42), -INT8_C(  73), -INT8_C(  55), -INT8_C( 109),  INT8_C(  25), -INT8_C( 103) },
      { -INT8_C( 116),  INT8_C(  36), -INT8_C(  97),  INT8_C(  96),  INT8_C(  53), -INT8_C( 113), -INT8_C(  96),  INT8_C(  51) },
      { -INT8_C(  56),  INT8_C(  10), -INT8_C(  85),  INT8_C(  23),  INT8_C(  27),  INT8_C(  91),  INT8_C(  46),  INT8_C(  66) } },
    { {  INT8_C(  48), -INT8_C( 109), -INT8_C( 104),  INT8_C( 113),  INT8_C(  64), -INT8_C( 107),  INT8_C(  92),  INT8_C(  89) },
      { -INT8_C( 107), -INT8_C(  48), -INT8_C(  57),  INT8_C(  68),  INT8_C(  39),  INT8_C( 124), -INT8_C(  19),  INT8_C(  98) },
      { -INT8_C( 107), -INT8_C(  61),  INT8_C(  25),  INT8_C(  95),  INT8_C(  86),  INT8_C(  50), -INT8_C(   8), -INT8_C(  29) },
      {  INT8_C(  48), -INT8_C(  96), -INT8_C(  22), -INT8_C( 116),  INT8_C( 111), -INT8_C(  33),  INT8_C( 103), -INT8_C(  40) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int8x8_t a = simde_vld1_s8(test_vec[i].a);
    simde_int8x8_t b = simde_vld1_s8(test_vec[i].b);
    simde_int8x8_t c = simde_vld1_s8(test_vec[i].c);
    simde_int8x8_t r = simde_vaba_s8(a, b, c);

    simde_test_arm_neon_assert_equal_i8x8(r, simde_vld1_s8(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int8x8_t a = simde_test_arm_neon_random_i8x8();
    simde_int8x8_t b = simde_test_arm_neon_random_i8x8();
    simde_int8x8_t c = simde_test_arm_neon_random_i8x8();
    simde_int8x8_t r = simde_vaba_s8(a, b, c);

    simde_test_arm_neon_write_i8x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i8x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i8x8(2, c, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i8x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vaba_s16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int16_t a[4];
    int16_t b[4];
    int16_t c[4];
    int16_t r[4];
  } test_vec[] = {
    { { -INT16_C( 17843),  INT16_C( 24491), -INT16_C( 27890), -INT16_C( 20171) },
      { -INT16_C( 23451), -INT16_C(  7916),  INT16_C( 14616),  INT16_C( 19459) },
      {  INT16_C( 27799), -INT16_C( 19103), -INT16_C( 26200),  INT16_C(  3764) },
      { -INT16_C( 32129), -INT16_C( 29858),  INT16_C( 12926), -INT16_C(  4476) } },
    { { -INT16_C( 27609), -INT16_C( 31965), -INT16_C( 14129),  INT16_C(  7408) },
      { -INT16_C( 25470), -INT16_C( 28549), -INT16_C( 20433), -INT16_C( 27326) },
      {  INT16_C( 22101),  INT16_C( 28022),  INT16_C( 31120),  INT16_C( 10169) },
      {  INT16_C( 19962),  INT16_C( 24606), -INT16_C( 28112), -INT16_C( 20633) } },
    { {  INT16_C(  6886), -INT16_C( 28964), -INT16_C( 28237), -INT16_C(  9571) },
      { -INT16_C( 16347), -INT16_C(  2978),  INT16_C( 20104),  INT16_C(  2576) },
      { -INT16_C( 29718),  INT16_C(  6811), -INT16_C(  8901), -INT16_C( 28497) },
      {  INT16_C( 20257), -INT16_C( 19175),  INT16_C(   768),  INT16_C( 21502) } },
    { {  INT16_C(  9523), -INT16_C( 15363), -INT16_C( 18785), -INT16_C( 31253) },
      { -INT16_C( 14383), -INT16_C( 31725), -INT16_C( 20392),  INT16_C( 32095) },
      { -INT16_C( 17040), -INT16_C(  1935), -INT16_C( 32501), -INT16_C(  2557) },
      {  INT16_C( 12180),  INT16_C( 14427), -INT16_C(  6676),  INT16_C(  3399) } },
    { { -INT16_C( 25076),  INT16_C( 18448), -INT16_C( 16517), -INT16_C( 20776) },
      { -INT16_C( 10524), -INT16_C( 31886),  INT16_C( 23948),  INT16_C( 23816) },
      {  INT16_C(  7204),  INT16_C( 32226),  INT16_C( 16844),  INT16_C( 15866) },
      { -INT16_C(  7348),  INT16_C( 17024), -INT16_C(  9413), -INT16_C( 12826) } },
    { {  INT16_C( 27902),  INT16_C(  2357),  INT16_C( 14573), -INT16_C(  1281) },
      {  INT16_C(  4054),  INT16_C( 20802),  INT16_C(  6862), -INT16_C( 19712) },
      {  INT16_C( 29424),  INT16_C( 32054),  INT16_C( 16335), -INT16_C(  3110) },
      { -INT16_C( 12264),  INT16_C( 13609),  INT16_C( 24046),  INT16_C( 15321) } },
    { { -INT16_C( 17317),  INT16_C( 10096),  INT16_C( 27645), -INT16_C(  1180) },
      { -INT16_C( 25897), -INT16_C( 15355),  INT16_C(  1234), -INT16_C( 22082) },
      {  INT16_C(    20), -INT16_C(  7430), -INT16_C(  1509),  INT16_C(  2965) },
      {  INT16_C(  8600),  INT16_C( 18021),  INT16_C( 30388),  INT16_C( 23867) } },
    { { -INT16_C( 13204),  INT16_C( 15240),  INT16_C( 25355),  INT16_C( 26159) },
      { -INT16_C( 24801),  INT16_C(  7565), -INT16_C(  3574), -INT16_C(  7912) },
      {  INT16_C(  7564),  INT16_C( 24230),  INT16_C( 25634),  INT16_C( 13831) },
      {  INT16_C( 19161),  INT16_C( 31905), -INT16_C( 10973), -INT16_C( 17634) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x4_t a = simde_vld1_s16(test_vec[i].a);
    simde_int16x4_t b = simde_vld1_s16(test_vec[i].b);
    simde_int16x4_t c = simde_vld1_s16(test_vec[i].c);
    simde_int16x4_t r = simde_vaba_s16(a, b, c);

    simde_test_arm_neon_assert_equal_i16x4(r, simde_vld1_s16(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int16x4_t a = simde_test_arm_neon_random_i16x4();
    simde_int16x4_t b = simde_test_arm_neon_random_i16x4();
    simde_int16x4_t c = simde_test_arm_neon_random_i16x4();
    simde_int16x4_t r = simde_vaba_s16(a, b, c);

    simde_test_arm_neon_write_i16x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i16x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i16x4(2, c, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i16x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vaba_s32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int32_t a[2];
    int32_t b[2];
    int32_t c[2];
    int32_t r[2];
  } test_vec[] = {
    { { -INT32_C(   850247872),  INT32_C(   228627924) },
      { -INT32_C(  1002407850), -INT32_C(  1479470080) },
      {  INT32_C(   156520649),  INT32_C(  1948288923) },
      {  INT32_C(   308680627), -INT32_C(   638580369) } },
    { {  INT32_C(  1567609108), -INT32_C(  1636072610) },
      { -INT32_C(  1771254078), -INT32_C(  1163654045) },
      { -INT32_C(  2072058748), -INT32_C(  1037348615) },
      {  INT32_C(  1868413778), -INT32_C(  1509767180) } },
    { {  INT32_C(  1003192480),  INT32_C(   464579591) },
      {  INT32_C(   477700029),  INT32_C(  1706751138) },
      {  INT32_C(   653993666), -INT32_C(  1210015950) },
      {  INT32_C(  1179486117), -INT32_C(   913620617) } },
    { {  INT32_C(  2101042820),  INT32_C(  1312778158) },
      { -INT32_C(   292942873), -INT32_C(  1274397961) },
      { -INT32_C(    70220967),  INT32_C(   979405687) },
      { -INT32_C(  1971202570), -INT32_C(   728385490) } },
    { { -INT32_C(   463446863),  INT32_C(  2140881147) },
      {  INT32_C(  1308415646),  INT32_C(   614153277) },
      {  INT32_C(  1041442119), -INT32_C(  1192092321) },
      { -INT32_C(   196473336), -INT32_C(   347840551) } },
    { {  INT32_C(   397722528), -INT32_C(    11463602) },
      {  INT32_C(  1826861424), -INT32_C(  1863614735) },
      { -INT32_C(  1830950827),  INT32_C(  1807185956) },
      { -INT32_C(   239432517), -INT32_C(   635630207) } },
    { { -INT32_C(    39204194), -INT32_C(  2018075673) },
      { -INT32_C(  1398904226), -INT32_C(   273878914) },
      { -INT32_C(  1822715999),  INT32_C(  1663256078) },
      {  INT32_C(   384607579), -INT32_C(    80940681) } },
    { {  INT32_C(  1391788078),  INT32_C(   381529208) },
      {  INT32_C(  1561618038),  INT32_C(  1625606658) },
      { -INT32_C(  1307737292),  INT32_C(   346143091) },
      { -INT32_C(    33823888),  INT32_C(  1660992775) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x2_t a = simde_vld1_s32(test_vec[i].a);
    simde_int32x2_t b = simde_vld1_s32(test_vec[i].b);
    simde_int32x2_t c = simde_vld1_s32(test_vec[i].c);
    simde_int32x2_t r = simde_vaba_s32(a, b, c);

    simde_test_arm_neon_assert_equal_i32x2(r, simde_vld1_s32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int32x2_t a = simde_test_arm_neon_random_i32x2();
    simde_int32x2_t b = simde_test_arm_neon_random_i32x2();
    simde_int32x2_t c = simde_test_arm_neon_random_i32x2();
    simde_int32x2_t r = simde_vaba_s32(a, b, c);

    simde_test_arm_neon_write_i32x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i32x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i32x2(2, c, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i32x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vaba_u8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint8_t a[8];
    uint8_t b[8];
    uint8_t c[8];
    uint8_t r[8];
  } test_vec[] = {
    { { UINT8_C( 17), UINT8_C(246), UINT8_C(124), UINT8_C( 27), UINT8_C(  1), UINT8_C( 92), UINT8_C(248), UINT8_C(208) },
      { UINT8_C(212), UINT8_C(211), UINT8_C(252), UINT8_C( 10), UINT8_C( 66), UINT8_C( 76), UINT8_C( 57), UINT8_C(253) },
      { UINT8_C( 40), UINT8_C(175), UINT8_C(209), UINT8_C(209), UINT8_C(140), UINT8_C(241), UINT8_C(147), UINT8_C(212) },
      { UINT8_C(189), UINT8_C( 26), UINT8_C(167), UINT8_C(226), UINT8_C( 75), UINT8_C(  1), UINT8_C( 82), UINT8_C(249) } },
    { { UINT8_C( 17), UINT8_C(152), UINT8_C(248), UINT8_C( 62), UINT8_C(  2), UINT8_C(241), UINT8_C( 63), UINT8_C( 19) },
      { UINT8_C(231), UINT8_C(188), UINT8_C( 46), UINT8_C(233), UINT8_C( 24), UINT8_C( 39), UINT8_C(185), UINT8_C(236) },
      { UINT8_C(250), UINT8_C(181), UINT8_C(247), UINT8_C( 60), UINT8_C(  1), UINT8_C( 48), UINT8_C( 58), UINT8_C( 41) },
      { UINT8_C( 36), UINT8_C(159), UINT8_C(193), UINT8_C(235), UINT8_C( 25), UINT8_C(250), UINT8_C(190), UINT8_C(214) } },
    { { UINT8_C(223), UINT8_C( 11), UINT8_C(251), UINT8_C(108), UINT8_C(252), UINT8_C(142), UINT8_C( 64), UINT8_C( 13) },
      { UINT8_C( 38), UINT8_C( 57), UINT8_C( 75), UINT8_C( 40), UINT8_C( 42), UINT8_C(139), UINT8_C( 60), UINT8_C( 18) },
      { UINT8_C( 71), UINT8_C(106), UINT8_C(251), UINT8_C( 95), UINT8_C(145), UINT8_C(180), UINT8_C( 76), UINT8_C(140) },
      { UINT8_C(  0), UINT8_C( 60), UINT8_C(171), UINT8_C(163), UINT8_C( 99), UINT8_C(183), UINT8_C( 80), UINT8_C(135) } },
    { { UINT8_C(105), UINT8_C( 67), UINT8_C(200), UINT8_C(106), UINT8_C(115), UINT8_C(  2), UINT8_C(148), UINT8_C( 82) },
      { UINT8_C( 13), UINT8_C(143), UINT8_C(190), UINT8_C(  9), UINT8_C( 29),    UINT8_MAX, UINT8_C( 23), UINT8_C( 67) },
      { UINT8_C( 56), UINT8_C( 98), UINT8_C(107), UINT8_C( 98), UINT8_C(237), UINT8_C(167), UINT8_C(116), UINT8_C( 52) },
      { UINT8_C(148), UINT8_C(112), UINT8_C( 27), UINT8_C(195), UINT8_C( 67), UINT8_C( 90), UINT8_C(241), UINT8_C( 97) } },
    { { UINT8_C( 18), UINT8_C(111), UINT8_C(148), UINT8_C(163), UINT8_C( 35), UINT8_C(224), UINT8_C( 47), UINT8_C(140) },
      { UINT8_C( 35), UINT8_C(248), UINT8_C(247), UINT8_C(150), UINT8_C(250), UINT8_C(139), UINT8_C(232), UINT8_C(  8) },
      { UINT8_C( 26), UINT8_C(167), UINT8_C( 17), UINT8_C( 55), UINT8_C(166), UINT8_C( 40), UINT8_C(122), UINT8_C(222) },
      { UINT8_C( 27), UINT8_C(192), UINT8_C(122), UINT8_C(  2), UINT8_C(119), UINT8_C( 67), UINT8_C(157), UINT8_C( 98) } },
    { { UINT8_C(139), UINT8_C(229), UINT8_C( 64), UINT8_C(120), UINT8_C(141), UINT8_C(181), UINT8_C(173), UINT8_C(159) },
      { UINT8_C( 36), UINT8_C( 65), UINT8_C( 66), UINT8_C( 72), UINT8_C( 33), UINT8_C(114), UINT8_C(212), UINT8_C( 68) },
      { UINT8_C(106), UINT8_C(203), UINT8_C(218), UINT8_C(100), UINT8_C( 86), UINT8_C(194), UINT8_C(108), UINT8_C(112) },
      { UINT8_C(209), UINT8_C(111), UINT8_C(216), UINT8_C(148), UINT8_C(194), UINT8_C(  5), UINT8_C( 21), UINT8_C(203) } },
    { { UINT8_C(105), UINT8_C(126), UINT8_C(167), UINT8_C( 15), UINT8_C(166), UINT8_C( 33), UINT8_C(237), UINT8_C( 49) },
      { UINT8_C(  7), UINT8_C( 46), UINT8_C(170), UINT8_C(148), UINT8_C(227), UINT8_C( 87), UINT8_C( 51), UINT8_C(  7) },
      { UINT8_C(152), UINT8_C(117), UINT8_C( 79), UINT8_C(185), UINT8_C(231), UINT8_C( 36), UINT8_C(253), UINT8_C( 81) },
      { UINT8_C(250), UINT8_C(197), UINT8_C(  2), UINT8_C( 52), UINT8_C(170), UINT8_C( 84), UINT8_C(183), UINT8_C(123) } },
    { { UINT8_C(239), UINT8_C(215), UINT8_C(182), UINT8_C( 70), UINT8_C(153), UINT8_C( 34), UINT8_C(182), UINT8_C(  3) },
      { UINT8_C(160), UINT8_C( 94), UINT8_C( 18), UINT8_C( 71), UINT8_C(127), UINT8_C(  0), UINT8_C(120), UINT8_C(134) },
      { UINT8_C( 46), UINT8_C( 34), UINT8_C( 26), UINT8_C( 17), UINT8_C(121), UINT8_C( 77), UINT8_C( 24), UINT8_C( 17) },
      { UINT8_C( 97), UINT8_C( 19), UINT8_C(190), UINT8_C(124), UINT8_C(159), UINT8_C(111), UINT8_C( 22), UINT8_C(120) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint8x8_t a = simde_vld1_u8(test_vec[i].a);
    simde_uint8x8_t b = simde_vld1_u8(test_vec[i].b);
    simde_uint8x8_t c = simde_vld1_u8(test_vec[i].c);
    simde_uint8x8_t r = simde_vaba_u8(a, b, c);

    simde_test_arm_neon_assert_equal_u8x8(r, simde_vld1_u8(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint8x8_t a = simde_test_arm_neon_random_u8x8();
    simde_uint8x8_t b = simde_test_arm_neon_random_u8x8();
    simde_uint8x8_t c = simde_test_arm_neon_random_u8x8();
    simde_uint8x8_t r = simde_vaba_u8(a, b, c);

    simde_test_arm_neon_write_u8x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u8x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u8x8(2, c, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u8x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vaba_u16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint16_t a[4];
    uint16_t b[4];
    uint16_t c[4];
    uint16_t r[4];
  } test_vec[] = {
    { { UINT16_C(26819), UINT16_C(43722), UINT16_C(51084), UINT16_C(31740) },
      { UINT16_C(45726), UINT16_C(14529), UINT16_C(30932), UINT16_C(30011) },
      { UINT16_C(19926), UINT16_C(21948), UINT16_C(13389), UINT16_C(31708) },
      { UINT16_C(52619), UINT16_C(51141), UINT16_C( 3091), UINT16_C(33437) } },
    { { UINT16_C(63063), UINT16_C(53388), UINT16_C(42308), UINT16_C( 2018) },
      { UINT16_C(44045), UINT16_C(39345), UINT16_C(44404), UINT16_C( 4628) },
      { UINT16_C(54879), UINT16_C(13386), UINT16_C(34126), UINT16_C( 9385) },
      { UINT16_C( 8361), UINT16_C(13811), UINT16_C(52586), UINT16_C( 6775) } },
    { { UINT16_C(26067), UINT16_C( 8313), UINT16_C(21913), UINT16_C(61596) },
      { UINT16_C(10316), UINT16_C(37057), UINT16_C(41933), UINT16_C(55959) },
      { UINT16_C(18511), UINT16_C(50035), UINT16_C(35062), UINT16_C(21974) },
      { UINT16_C(34262), UINT16_C(21291), UINT16_C(28784), UINT16_C(30045) } },
    { { UINT16_C( 8286), UINT16_C(44169), UINT16_C(12966), UINT16_C(31184) },
      { UINT16_C(18839), UINT16_C(12697), UINT16_C(13727), UINT16_C(60193) },
      { UINT16_C(57950), UINT16_C(11131), UINT16_C( 4741), UINT16_C(54534) },
      { UINT16_C(47397), UINT16_C(45735), UINT16_C(21952), UINT16_C(36843) } },
    { { UINT16_C(31066), UINT16_C(20632), UINT16_C(28161), UINT16_C(24486) },
      { UINT16_C(12175), UINT16_C(13579), UINT16_C(56162), UINT16_C(63918) },
      { UINT16_C(18213), UINT16_C(50218), UINT16_C(19581), UINT16_C(56239) },
      { UINT16_C(37104), UINT16_C(57271), UINT16_C(64742), UINT16_C(32165) } },
    { { UINT16_C(10798), UINT16_C(46086), UINT16_C( 3132), UINT16_C(38537) },
      { UINT16_C( 8582), UINT16_C(34791), UINT16_C(36240), UINT16_C( 8167) },
      { UINT16_C(62140), UINT16_C( 7764), UINT16_C(  718), UINT16_C(62232) },
      { UINT16_C(64356), UINT16_C( 7577), UINT16_C(38654), UINT16_C(27066) } },
    { { UINT16_C(16969), UINT16_C(50871), UINT16_C(26254), UINT16_C(48545) },
      { UINT16_C(43152), UINT16_C(52337), UINT16_C(64180), UINT16_C(14946) },
      { UINT16_C(18715), UINT16_C(43970), UINT16_C(43478), UINT16_C(37834) },
      { UINT16_C(41406), UINT16_C(59238), UINT16_C(46956), UINT16_C( 5897) } },
    { { UINT16_C( 7835), UINT16_C(27057), UINT16_C(51488), UINT16_C(27228) },
      { UINT16_C( 4876), UINT16_C(39472), UINT16_C(53881), UINT16_C( 2391) },
      { UINT16_C(51322), UINT16_C(11989), UINT16_C(14530), UINT16_C(56937) },
      { UINT16_C(54281), UINT16_C(54540), UINT16_C(25303), UINT16_C(16238) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint16x4_t a = simde_vld1_u16(test_vec[i].a);
    simde_uint16x4_t b = simde_vld1_u16(test_vec[i].b);
    simde_uint16x4_t c = simde_vld1_u16(test_vec[i].c);
    simde_uint16x4_t r = simde_vaba_u16(a, b, c);

    simde_test_arm_neon_assert_equal_u16x4(r, simde_vld1_u16(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint16x4_t a = simde_test_arm_neon_random_u16x4();
    simde_uint16x4_t b = simde_test_arm_neon_random_u16x4();
    simde_uint16x4_t c = simde_test_arm_neon_random_u16x4();
    simde_uint16x4_t r = simde_vaba_u16(a, b, c);

    simde_test_arm_neon_write_u16x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u16x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u16x4(2, c, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u16x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vaba_u32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint32_t a[2];
    uint32_t b[2];
    uint32_t c[2];
    uint32_t r[2];
  } test_vec[] = {
    { { UINT32_C(1485384577), UINT32_C(1877693652) },
      { UINT32_C(2480512114), UINT32_C(1929196902) },
      { UINT32_C(3255577929), UINT32_C(2043438335) },
      { UINT32_C(2260450392), UINT32_C(1991935085) } },
    { { UINT32_C(4020805932), UINT32_C(1540166105) },
      { UINT32_C( 280188476), UINT32_C( 494902954) },
      { UINT32_C(2695911482), UINT32_C(3608325518) },
      { UINT32_C(2141561642), UINT32_C( 358621373) } },
    { { UINT32_C(3667468250), UINT32_C(2941478275) },
      { UINT32_C(3768515335), UINT32_C(1211853580) },
      { UINT32_C(1817767618), UINT32_C(3347699852) },
      { UINT32_C(1323248671), UINT32_C( 782357251) } },
    { { UINT32_C(3194435888), UINT32_C(3247799014) },
      { UINT32_C( 479932313), UINT32_C(2613833364) },
      { UINT32_C(4135348970), UINT32_C(2537535445) },
      { UINT32_C(2554885249), UINT32_C(3324096933) } },
    { { UINT32_C( 839161766), UINT32_C(2700709231) },
      { UINT32_C(2908643783), UINT32_C(1953428699) },
      { UINT32_C(3079670051), UINT32_C(3797113848) },
      { UINT32_C(1010188034), UINT32_C( 249427084) } },
    { { UINT32_C(2614677445), UINT32_C( 741480326) },
      { UINT32_C( 509556399), UINT32_C(2344507588) },
      { UINT32_C(2486705593), UINT32_C( 872982289) },
      { UINT32_C( 296859343), UINT32_C(2213005625) } },
    { { UINT32_C(2834012336), UINT32_C(3112845044) },
      { UINT32_C(2488558349), UINT32_C( 700483450) },
      { UINT32_C(2168987581), UINT32_C( 822871672) },
      { UINT32_C(3153583104), UINT32_C(3235233266) } },
    { { UINT32_C( 885409059), UINT32_C(2624114412) },
      { UINT32_C(1531270247), UINT32_C(2685718418) },
      { UINT32_C(2905893170), UINT32_C(2916545776) },
      { UINT32_C(2260031982), UINT32_C(2854941770) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint32x2_t a = simde_vld1_u32(test_vec[i].a);
    simde_uint32x2_t b = simde_vld1_u32(test_vec[i].b);
    simde_uint32x2_t c = simde_vld1_u32(test_vec[i].c);
    simde_uint32x2_t r = simde_vaba_u32(a, b, c);

    simde_test_arm_neon_assert_equal_u32x2(r, simde_vld1_u32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint32x2_t a = simde_test_arm_neon_random_u32x2();
    simde_uint32x2_t b = simde_test_arm_neon_random_u32x2();
    simde_uint32x2_t c = simde_test_arm_neon_random_u32x2();
    simde_uint32x2_t r = simde_vaba_u32(a, b, c);

    simde_test_arm_neon_write_u32x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u32x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x2(2, c, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vabaq_s8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int8_t a[16];
    int8_t b[16];
    int8_t c[16];
    int8_t r[16];
  } test_vec[] = {
    { {  INT8_C(  74),  INT8_C( 104), -INT8_C(  55),  INT8_C(  64), -INT8_C(  42), -INT8_C(  57),  INT8_C(  12), -INT8_C(  72),
        -INT8_C(  63),  INT8_C(  99), -INT8_C( 106), -INT8_C(  48),  INT8_C(  72),  INT8_C(  62),  INT8_C(  20),  INT8_C(  88) },
      {  INT8_C(  87), -INT8_C(  93),  INT8_C( 118), -INT8_C(  53), -INT8_C(  18),  INT8_C(  24),  INT8_C(  78), -INT8_C(  62),
        -INT8_C(  33), -INT8_C( 104),  INT8_C(  27),  INT8_C(  88),  INT8_C(  68),  INT8_C( 102),  INT8_C( 102), -INT8_C( 114) },
      { -INT8_C(  50),  INT8_C(  47), -INT8_C(  50), -INT8_C(  92), -INT8_C(   9), -INT8_C(  37),  INT8_C(  93), -INT8_C(  72),
         INT8_C(  62), -INT8_C(  13), -INT8_C( 120), -INT8_C( 122),  INT8_C(  50), -INT8_C( 100), -INT8_C(  33), -INT8_C( 119) },
      { -INT8_C(  45), -INT8_C(  12),  INT8_C( 113),  INT8_C( 103), -INT8_C(  33),  INT8_C(   4),  INT8_C(  27), -INT8_C(  62),
         INT8_C(  32), -INT8_C(  66),  INT8_C(  41), -INT8_C(  94),  INT8_C(  90),  INT8_C(   8), -INT8_C( 101),  INT8_C(  93) } },
    { {  INT8_C(  63),  INT8_C(  85),  INT8_C(  84),  INT8_C(  45),  INT8_C( 110), -INT8_C(  94), -INT8_C(  16),  INT8_C(  77),
         INT8_C(  59),  INT8_C(  11), -INT8_C(  91),      INT8_MAX,  INT8_C( 113),  INT8_C(  12),  INT8_C(  13),  INT8_C(  63) },
      {  INT8_C(  59), -INT8_C(  36), -INT8_C(  28),  INT8_C(  50), -INT8_C(  73),  INT8_C(  65), -INT8_C(  22), -INT8_C(  11),
         INT8_C(  52),  INT8_C( 115),  INT8_C( 124),  INT8_C( 102),  INT8_C(  15),  INT8_C(  91), -INT8_C(  17),  INT8_C(  79) },
      { -INT8_C(  80),  INT8_C(  67),  INT8_C( 124),  INT8_C(  30), -INT8_C(  26),  INT8_C( 108),  INT8_C( 107),  INT8_C(  33),
         INT8_C( 119),  INT8_C(  17), -INT8_C(  96), -INT8_C(  24),  INT8_C(  29), -INT8_C(  83),  INT8_C(  40),  INT8_C(  88) },
      { -INT8_C(  54), -INT8_C(  68), -INT8_C(  20),  INT8_C(  65), -INT8_C(  99), -INT8_C(  51),  INT8_C( 113),  INT8_C( 121),
         INT8_C( 126),  INT8_C( 109), -INT8_C( 127), -INT8_C(   3),      INT8_MAX, -INT8_C(  70),  INT8_C(  70),  INT8_C(  72) } },
    { { -INT8_C( 119),  INT8_C(  12), -INT8_C( 117),  INT8_C(  64),  INT8_C(  77),  INT8_C( 117),  INT8_C(  54), -INT8_C( 127),
        -INT8_C(  24), -INT8_C(  78), -INT8_C(  24), -INT8_C(   8),  INT8_C(  13), -INT8_C(  41),  INT8_C(  71), -INT8_C(  67) },
      {  INT8_C(  27), -INT8_C(  61), -INT8_C(  36),  INT8_C(   1),  INT8_C(  48),  INT8_C(  71),  INT8_C(  34), -INT8_C(  89),
         INT8_C(  88), -INT8_C(  62), -INT8_C( 112),  INT8_C( 117),  INT8_C( 111), -INT8_C(  72), -INT8_C(  50), -INT8_C(   7) },
      { -INT8_C(  60),  INT8_C(  89),  INT8_C(  57),  INT8_C(  17), -INT8_C(  50),  INT8_C( 111), -INT8_C( 110), -INT8_C(  73),
         INT8_C(  33),  INT8_C( 122), -INT8_C(  81),  INT8_C(  46),  INT8_C(  82), -INT8_C(  10), -INT8_C(  20),  INT8_C( 109) },
      { -INT8_C(  32), -INT8_C(  94), -INT8_C(  24),  INT8_C(  80), -INT8_C(  81), -INT8_C(  99), -INT8_C(  58), -INT8_C( 111),
         INT8_C(  31),  INT8_C( 106),  INT8_C(   7),  INT8_C(  63),  INT8_C(  42),  INT8_C(  21),  INT8_C( 101),  INT8_C(  49) } },
    { { -INT8_C(  71), -INT8_C(  56),  INT8_C( 110), -INT8_C(  23),  INT8_C(  15), -INT8_C( 112), -INT8_C( 111),  INT8_C( 104),
         INT8_C(  82),  INT8_C(  33), -INT8_C(  35), -INT8_C(  63), -INT8_C(  39), -INT8_C(  85), -INT8_C(  70), -INT8_C(  99) },
      {  INT8_C(   4), -INT8_C(  12), -INT8_C(  82), -INT8_C(  45),  INT8_C(  99),  INT8_C(  64), -INT8_C( 118), -INT8_C( 123),
        -INT8_C(  69),  INT8_C(  57), -INT8_C(  77),  INT8_C(  13),  INT8_C(  47), -INT8_C(  97),  INT8_C( 122), -INT8_C(  24) },
      {  INT8_C( 103), -INT8_C(  24), -INT8_C(  46),  INT8_C( 119),  INT8_C( 120),  INT8_C(  99), -INT8_C(  33), -INT8_C(  54),
        -INT8_C( 124), -INT8_C(  68), -INT8_C( 117),  INT8_C(  93),  INT8_C( 104),  INT8_C(  70), -INT8_C(   6),  INT8_C( 108) },
      {  INT8_C(  28), -INT8_C(  44), -INT8_C( 110), -INT8_C( 115),  INT8_C(  36), -INT8_C(  77), -INT8_C(  26), -INT8_C(  83),
        -INT8_C( 119), -INT8_C(  98),  INT8_C(   5),  INT8_C(  17),  INT8_C(  18),  INT8_C(  82),  INT8_C(  58),  INT8_C(  33) } },
    { {  INT8_C(  58), -INT8_C(  88),  INT8_C(  63), -INT8_C(  99), -INT8_C(  24), -INT8_C(  55),  INT8_C(  34), -INT8_C(  93),
         INT8_C(   2), -INT8_C(  42), -INT8_C(  80),  INT8_C(  49),  INT8_C( 117),  INT8_C(  42),  INT8_C(  26), -INT8_C(  35) },
      {  INT8_C(  18), -INT8_C(  20),  INT8_C(  84), -INT8_C( 118),  INT8_C(  79),  INT8_C(  51),  INT8_C(  84), -INT8_C(  45),
        -INT8_C(  17), -INT8_C(  32),  INT8_C(  48),  INT8_C(  87),  INT8_C(  38),  INT8_C(  42), -INT8_C(  60),  INT8_C(  96) },
      { -INT8_C(  46),  INT8_C(   3), -INT8_C(   3), -INT8_C(  70), -INT8_C(  51),  INT8_C(  32),  INT8_C(  94), -INT8_C(  49),
        -INT8_C(  10),  INT8_C(  14),  INT8_C(   1),  INT8_C( 107),  INT8_C(  57),  INT8_C(  27),  INT8_C(  72),  INT8_C(  75) },
      {  INT8_C( 122), -INT8_C(  65), -INT8_C( 106), -INT8_C(  51),  INT8_C( 106), -INT8_C(  36),  INT8_C(  44), -INT8_C(  89),
         INT8_C(   9),  INT8_C(   4), -INT8_C(  33),  INT8_C(  69), -INT8_C( 120),  INT8_C(  57), -INT8_C(  98), -INT8_C(  14) } },
    { {  INT8_C(   7), -INT8_C( 100), -INT8_C(  42),  INT8_C(  86), -INT8_C(  49),  INT8_C(  42),  INT8_C(  41), -INT8_C(  65),
         INT8_C(  10),  INT8_C(  89),  INT8_C(  22),  INT8_C(  48), -INT8_C( 125), -INT8_C(  38), -INT8_C( 112),  INT8_C(  85) },
      { -INT8_C(  34), -INT8_C( 114),  INT8_C(  15), -INT8_C(  85), -INT8_C(  82),  INT8_C( 109),  INT8_C( 122), -INT8_C(  92),
         INT8_C( 124),  INT8_C( 123),  INT8_C(  15), -INT8_C(  75), -INT8_C( 106),  INT8_C(  88),  INT8_C(   0), -INT8_C(  99) },
      { -INT8_C(  12), -INT8_C(  42), -INT8_C(  13), -INT8_C(  60),  INT8_C(   1),  INT8_C(  28), -INT8_C( 125),  INT8_C(  11),
         INT8_C( 117), -INT8_C( 103),  INT8_C(  60), -INT8_C(   8),  INT8_C( 116), -INT8_C(  52),  INT8_C(  77),  INT8_C(  82) },
      {  INT8_C(  29), -INT8_C(  28), -INT8_C(  14),  INT8_C( 111),  INT8_C(  34),  INT8_C( 123),  INT8_C(  32),  INT8_C(  38),
         INT8_C(  17),  INT8_C(  59),  INT8_C(  67),  INT8_C( 115),  INT8_C(  97),  INT8_C( 102), -INT8_C(  35),  INT8_C(  10) } },
    { {  INT8_C(  90),  INT8_C(  93), -INT8_C(   3),  INT8_C(   8), -INT8_C(  54),  INT8_C( 119), -INT8_C(  84),  INT8_C(  70),
        -INT8_C(  13), -INT8_C(  68), -INT8_C(   5), -INT8_C( 119),  INT8_C(  20), -INT8_C(   4),  INT8_C(  39),  INT8_C(   8) },
      { -INT8_C(  46),  INT8_C(  26), -INT8_C(  52), -INT8_C(  45),  INT8_C(  55),  INT8_C(  79), -INT8_C(  33), -INT8_C(  84),
        -INT8_C(  23),  INT8_C(  27), -INT8_C(  91),  INT8_C(  93), -INT8_C(  25), -INT8_C(  14), -INT8_C(  81),  INT8_C(  66) },
      {  INT8_C(  79), -INT8_C(  84),  INT8_C(  74),  INT8_C(  26),  INT8_C(  35), -INT8_C(   9),  INT8_C(  96),  INT8_C(  22),
        -INT8_C(  77),  INT8_C(  92), -INT8_C(  96), -INT8_C(  57),  INT8_C(  88), -INT8_C(  57), -INT8_C(  49),  INT8_C(  42) },
      { -INT8_C(  41), -INT8_C(  53),  INT8_C( 123),  INT8_C(  79), -INT8_C(  34), -INT8_C(  49),  INT8_C(  45), -INT8_C(  80),
         INT8_C(  41), -INT8_C(   3),  INT8_C(   0),  INT8_C(  31), -INT8_C( 123),  INT8_C(  39),  INT8_C(  71),  INT8_C(  32) } },
    { { -INT8_C(  31), -INT8_C( 100), -INT8_C(   2),  INT8_C(  24), -INT8_C(  21), -INT8_C(  35), -INT8_C(  59), -INT8_C(  44),
        -INT8_C(   8),  INT8_C( 106),  INT8_C(  49), -INT8_C(  33),  INT8_C(  92), -INT8_C(  32),  INT8_C(  33), -INT8_C(  84) },
      { -INT8_C( 116),  INT8_C( 108), -INT8_C(  58), -INT8_C(  80),  INT8_C(  99),  INT8_C(  38), -INT8_C(  58),  INT8_C(  22),
        -INT8_C( 126),  INT8_C( 102), -INT8_C(  35), -INT8_C(  38),  INT8_C(  45), -INT8_C(  84),  INT8_C(   5),  INT8_C(  15) },
      {  INT8_C(  72),  INT8_C(   3),  INT8_C(  39),  INT8_C(  52), -INT8_C(  32), -INT8_C(  20),  INT8_C(   8), -INT8_C(  40),
         INT8_C(  86),  INT8_C(  58), -INT8_C(  73), -INT8_C(  77),  INT8_C(  26), -INT8_C(  39),  INT8_C(  95), -INT8_C(  89) },
      { -INT8_C(  99),  INT8_C(   5),  INT8_C(  95), -INT8_C( 100),  INT8_C( 110),  INT8_C(  23),  INT8_C(   7),  INT8_C(  18),
        -INT8_C(  52), -INT8_C( 106),  INT8_C(  87),  INT8_C(   6),  INT8_C( 111),  INT8_C(  13),  INT8_C( 123),  INT8_C(  20) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int8x16_t a = simde_vld1q_s8(test_vec[i].a);
    simde_int8x16_t b = simde_vld1q_s8(test_vec[i].b);
    simde_int8x16_t c = simde_vld1q_s8(test_vec[i].c);
    simde_int8x16_t r = simde_vabaq_s8(a, b, c);

    simde_test_arm_neon_assert_equal_i8x16(r, simde_vld1q_s8(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int8x16_t a = simde_test_arm_neon_random_i8x16();
    simde_int8x16_t b = simde_test_arm_neon_random_i8x16();
    simde_int8x16_t c = simde_test_arm_neon_random_i8x16();
    simde_int8x16_t r = simde_vabaq_s8(a, b, c);

    simde_test_arm_neon_write_i8x16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i8x16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i8x16(2, c, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i8x16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vabaq_s16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int16_t a[8];
    int16_t b[8];
    int16_t c[8];
    int16_t r[8];
  } test_vec[] = {
    { {  INT16_C( 30977),  INT16_C( 12491),  INT16_C(  2221), -INT16_C(  1303), -INT16_C( 21084),  INT16_C( 23557), -INT16_C( 31169), -INT16_C( 24084) },
      {  INT16_C( 24241), -INT16_C( 32243), -INT16_C(  7993),  INT16_C( 14763), -INT16_C( 29538), -INT16_C(  2390), -INT16_C( 29998), -INT16_C( 11061) },
      { -INT16_C( 27132), -INT16_C( 20220), -INT16_C(  4449),  INT16_C( 17323), -INT16_C( 20325), -INT16_C(  9569), -INT16_C( 29897), -INT16_C(  6021) },
      {  INT16_C( 16814),  INT16_C( 24514),  INT16_C(  5765),  INT16_C(  1257), -INT16_C( 11871),  INT16_C( 30736), -INT16_C( 31068), -INT16_C( 19044) } },
    { { -INT16_C( 30487), -INT16_C( 20118),  INT16_C(  5480),  INT16_C(  2026), -INT16_C( 27487),  INT16_C( 29949), -INT16_C( 14306),  INT16_C(  8776) },
      {  INT16_C( 19551), -INT16_C(   300),  INT16_C( 32570), -INT16_C( 10943), -INT16_C(  8144),  INT16_C( 26544),  INT16_C( 11116),  INT16_C( 21839) },
      { -INT16_C( 17996),  INT16_C(  7174), -INT16_C(  3890),  INT16_C( 28707),  INT16_C(  8580), -INT16_C( 23580),  INT16_C( 11497),  INT16_C( 18629) },
      {  INT16_C(  7060), -INT16_C( 12644), -INT16_C( 23596), -INT16_C( 23860), -INT16_C( 10763),  INT16_C( 14537), -INT16_C( 13925),  INT16_C( 11986) } },
    { { -INT16_C( 26248), -INT16_C( 19642), -INT16_C( 30951),  INT16_C( 18824),  INT16_C( 14440), -INT16_C( 11088), -INT16_C(   156),  INT16_C(  6185) },
      {  INT16_C( 12472), -INT16_C( 31180),  INT16_C( 22560), -INT16_C( 23050), -INT16_C(  9607),  INT16_C( 25160),  INT16_C(  3334),  INT16_C( 32683) },
      { -INT16_C(  3673), -INT16_C( 16334), -INT16_C( 17799), -INT16_C(  7927), -INT16_C( 17933),  INT16_C( 22453), -INT16_C(  8520),  INT16_C( 28783) },
      { -INT16_C( 10103), -INT16_C(  4796),  INT16_C(  9408), -INT16_C( 31589),  INT16_C( 22766), -INT16_C(  8381),  INT16_C( 11698),  INT16_C( 10085) } },
    { { -INT16_C( 23794),  INT16_C( 12278), -INT16_C(  4613),  INT16_C( 29908),  INT16_C(  7367), -INT16_C( 12585), -INT16_C( 32215), -INT16_C( 12211) },
      {  INT16_C( 32627), -INT16_C(  4976), -INT16_C( 26311),  INT16_C( 11469), -INT16_C( 32174),  INT16_C(  2691), -INT16_C(  3487),  INT16_C( 28538) },
      {  INT16_C( 29078), -INT16_C( 28258),  INT16_C( 29278),  INT16_C(  9478), -INT16_C(  8818), -INT16_C( 18189),  INT16_C( 16479), -INT16_C( 11640) },
      { -INT16_C( 20245), -INT16_C( 29976), -INT16_C( 14560),  INT16_C( 31899),  INT16_C( 30723),  INT16_C(  8295), -INT16_C( 12249),  INT16_C( 27967) } },
    { {  INT16_C(  6591), -INT16_C(  1601), -INT16_C( 29518),  INT16_C(  1317), -INT16_C( 22257),  INT16_C( 28687), -INT16_C( 30053),  INT16_C( 12767) },
      {  INT16_C( 32507),  INT16_C( 22979), -INT16_C( 13840),  INT16_C( 32638),  INT16_C( 29350),  INT16_C(  1335), -INT16_C( 16462),  INT16_C( 29399) },
      { -INT16_C( 26920), -INT16_C( 29845), -INT16_C( 28637),  INT16_C( 12944), -INT16_C( 24775), -INT16_C( 10846), -INT16_C( 32471),  INT16_C(  9222) },
      {  INT16_C(   482), -INT16_C( 14313), -INT16_C( 14721),  INT16_C( 21011),  INT16_C( 31868), -INT16_C( 24668), -INT16_C( 14044), -INT16_C( 32592) } },
    { { -INT16_C( 13825), -INT16_C(  3971), -INT16_C(   878),  INT16_C( 14447), -INT16_C( 22930),  INT16_C(  8253),  INT16_C(  5477),  INT16_C( 16018) },
      { -INT16_C(   597), -INT16_C( 12599),  INT16_C( 22926), -INT16_C( 14592), -INT16_C( 23816),  INT16_C(  8860), -INT16_C( 23772),  INT16_C(  9030) },
      { -INT16_C( 15252), -INT16_C(   237), -INT16_C( 32064),  INT16_C( 11831),  INT16_C( 29992), -INT16_C( 29106), -INT16_C(  7798),  INT16_C( 13772) },
      {  INT16_C(   830),  INT16_C(  8391), -INT16_C( 11424), -INT16_C( 24666),  INT16_C( 30878), -INT16_C( 19317),  INT16_C( 21451),  INT16_C( 20760) } },
    { { -INT16_C( 27170),  INT16_C( 27652),  INT16_C(  1262), -INT16_C(  6604), -INT16_C( 12121), -INT16_C( 13560),  INT16_C( 20339), -INT16_C(  7954) },
      {  INT16_C(   531), -INT16_C( 11297),  INT16_C(  5764), -INT16_C( 21247),  INT16_C( 20363),  INT16_C(  5435),  INT16_C(  1840),  INT16_C(  3915) },
      {  INT16_C( 20380), -INT16_C( 30085), -INT16_C( 20653), -INT16_C(  1424),  INT16_C( 31104), -INT16_C(  3131), -INT16_C( 19256), -INT16_C(  9261) },
      { -INT16_C(  7321), -INT16_C( 19096),  INT16_C( 27679),  INT16_C( 13219), -INT16_C(  1380), -INT16_C(  4994), -INT16_C( 24101),  INT16_C(  5222) } },
    { { -INT16_C( 19786),  INT16_C( 15022), -INT16_C( 20535),  INT16_C( 21735),  INT16_C(  8958),  INT16_C( 12138), -INT16_C( 19159), -INT16_C( 15042) },
      { -INT16_C( 18172),  INT16_C( 22351), -INT16_C( 16279), -INT16_C(  5806),  INT16_C(  5945),  INT16_C(   476), -INT16_C( 20277), -INT16_C( 32292) },
      { -INT16_C( 30110),  INT16_C( 11196), -INT16_C( 23751),  INT16_C( 14208), -INT16_C(  5434), -INT16_C(  4250), -INT16_C( 23393), -INT16_C( 23627) },
      { -INT16_C(  7848),  INT16_C( 26177), -INT16_C( 13063), -INT16_C( 23787),  INT16_C( 20337),  INT16_C( 16864), -INT16_C( 16043), -INT16_C(  6377) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x8_t a = simde_vld1q_s16(test_vec[i].a);
    simde_int16x8_t b = simde_vld1q_s16(test_vec[i].b);
    simde_int16x8_t c = simde_vld1q_s16(test_vec[i].c);
    simde_int16x8_t r = simde_vabaq_s16(a, b, c);

    simde_test_arm_neon_assert_equal_i16x8(r, simde_vld1q_s16(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int16x8_t a = simde_test_arm_neon_random_i16x8();
    simde_int16x8_t b = simde_test_arm_neon_random_i16x8();
    simde_int16x8_t c = simde_test_arm_neon_random_i16x8();
    simde_int16x8_t r = simde_vabaq_s16(a, b, c);

    simde_test_arm_neon_write_i16x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i16x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i16x8(2, c, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i16x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

#if !defined(TEST_SIMDE_VABD_NO_TEST_32)
static int
test_simde_vabaq_s32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int32_t a[4];
    int32_t b[4];
    int32_t c[4];
    int32_t r[4];
  } test_vec[] = {
    { { -INT32_C(   939916194), -INT32_C(    38777660),  INT32_C(   805211236), -INT32_C(  1615734212) },
      { -INT32_C(  1647678108), -INT32_C(   690664944), -INT32_C(   741983436),  INT32_C(  1047952352) },
      {  INT32_C(  1141207423),  INT32_C(   557954493),  INT32_C(  2119254081),  INT32_C(  2132607514) },
      {  INT32_C(  1848969337),  INT32_C(  1209841777), -INT32_C(   628518543), -INT32_C(   531079050) } },
    { {  INT32_C(  2132600687),  INT32_C(  1716973874),  INT32_C(   221912109),  INT32_C(   374059159) },
      { -INT32_C(   547729375),  INT32_C(  1174445061), -INT32_C(   154906148), -INT32_C(  1032461997) },
      { -INT32_C(    79523127), -INT32_C(  1335781245),  INT32_C(  1270717364),  INT32_C(  1835075660) },
      { -INT32_C(  1694160361), -INT32_C(    67767116),  INT32_C(  1647535621), -INT32_C(  1053370480) } },
    { {  INT32_C(  1565310040),  INT32_C(   883182936), -INT32_C(   232101730),  INT32_C(   330604618) },
      { -INT32_C(  1257310670),  INT32_C(  1114009486),  INT32_C(  1468867339), -INT32_C(  2067468500) },
      {  INT32_C(    65147307), -INT32_C(    63469986),  INT32_C(   955146734),  INT32_C(   860594945) },
      { -INT32_C(  1407199279),  INT32_C(  2060662408),  INT32_C(   281618875), -INT32_C(  1036299233) } },
    { {  INT32_C(   686381465), -INT32_C(   731230263), -INT32_C(  1641285518), -INT32_C(  1843138585) },
      {  INT32_C(  1586824448),  INT32_C(  2036059275),  INT32_C(   800213293), -INT32_C(  2040332820) },
      {  INT32_C(   548293463),  INT32_C(   234100890), -INT32_C(   139780336),  INT32_C(   260689422) },
      {  INT32_C(  1724912450),  INT32_C(  1070728122), -INT32_C(   701291889),  INT32_C(   457883657) } },
    { {  INT32_C(  1584209619),  INT32_C(   416860394), -INT32_C(    28866030), -INT32_C(   561731193) },
      { -INT32_C(  1879166219),  INT32_C(  1537012299),  INT32_C(   542328849), -INT32_C(   365962218) },
      { -INT32_C(   448226053),  INT32_C(  2013077605),  INT32_C(   846546090), -INT32_C(   485426450) },
      { -INT32_C(  1279817511),  INT32_C(   892925700),  INT32_C(   275351211), -INT32_C(   442266961) } },
    { {  INT32_C(  2003963692),  INT32_C(   332599041),  INT32_C(  1832068695), -INT32_C(    44604926) },
      {  INT32_C(  1675862270),  INT32_C(  1809506496),  INT32_C(   329076773),  INT32_C(  1995877706) },
      { -INT32_C(  1091671876), -INT32_C(   825114249), -INT32_C(   381942553),  INT32_C(  1692898150) },
      {  INT32_C(   476530542), -INT32_C(  1327747510), -INT32_C(  1751879275),  INT32_C(   258374630) } },
    { { -INT32_C(   188167629), -INT32_C(   815816022),  INT32_C(  1021508850),  INT32_C(  1723062441) },
      { -INT32_C(  1205558975),  INT32_C(  1233646946),  INT32_C(  1597162489), -INT32_C(  1966925482) },
      { -INT32_C(  1904309277),  INT32_C(   543022382), -INT32_C(  2107817767),  INT32_C(  1508380696) },
      {  INT32_C(   510582673), -INT32_C(   125191458),  INT32_C(   431521810),  INT32_C(   903401323) } },
    { {  INT32_C(   319950001), -INT32_C(    94594815), -INT32_C(  1302753700), -INT32_C(  1958994520) },
      { -INT32_C(   702956888),  INT32_C(  1895266199), -INT32_C(   806136649),  INT32_C(   355064676) },
      { -INT32_C(   383239192),  INT32_C(   820282580), -INT32_C(  1159578350),  INT32_C(    54927194) },
      {  INT32_C(   639667697),  INT32_C(   980388804), -INT32_C(   949311999), -INT32_C(  1658857038) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x4_t a = simde_vld1q_s32(test_vec[i].a);
    simde_int32x4_t b = simde_vld1q_s32(test_vec[i].b);
    simde_int32x4_t c = simde_vld1q_s32(test_vec[i].c);
    simde_int32x4_t r = simde_vabaq_s32(a, b, c);

    simde_test_arm_neon_assert_equal_i32x4(r, simde_vld1q_s32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int32x4_t a = simde_test_arm_neon_random_i32x4();
    simde_int32x4_t b = simde_test_arm_neon_random_i32x4();
    simde_int32x4_t c = simde_test_arm_neon_random_i32x4();
    simde_int32x4_t r = simde_vabaq_s32(a, b, c);

    simde_test_arm_neon_write_i32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i32x4(2, c, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}
#endif

static int
test_simde_vabaq_u8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint8_t a[16];
    uint8_t b[16];
    uint8_t c[16];
    uint8_t r[16];
  } test_vec[] = {
    { { UINT8_C(216), UINT8_C( 11), UINT8_C( 40), UINT8_C(228), UINT8_C(187), UINT8_C(225), UINT8_C( 32), UINT8_C(216),
        UINT8_C( 90), UINT8_C(133), UINT8_C(229), UINT8_C( 30), UINT8_C(182), UINT8_C( 36), UINT8_C(239), UINT8_C(187) },
      { UINT8_C(110), UINT8_C( 19), UINT8_C( 78), UINT8_C(165), UINT8_C(167), UINT8_C(104), UINT8_C(134), UINT8_C( 18),
        UINT8_C( 94), UINT8_C(254), UINT8_C(151), UINT8_C( 42), UINT8_C(254), UINT8_C(121), UINT8_C(219), UINT8_C(215) },
      { UINT8_C(132), UINT8_C(  3), UINT8_C(187), UINT8_C( 63), UINT8_C(228), UINT8_C(220), UINT8_C( 24), UINT8_C( 62),
        UINT8_C( 97), UINT8_C(253), UINT8_C( 93), UINT8_C( 23), UINT8_C( 33), UINT8_C( 76), UINT8_C(211), UINT8_C(144) },
      { UINT8_C(238), UINT8_C( 27), UINT8_C(149), UINT8_C( 74), UINT8_C(248), UINT8_C( 85), UINT8_C(142), UINT8_C(  4),
        UINT8_C( 93), UINT8_C(134), UINT8_C( 31), UINT8_C( 49), UINT8_C(147), UINT8_C( 81), UINT8_C(247), UINT8_C(  2) } },
    { { UINT8_C( 95), UINT8_C( 33), UINT8_C( 53), UINT8_C(  6), UINT8_C(138), UINT8_C(187), UINT8_C( 24), UINT8_C(232),
        UINT8_C(186), UINT8_C(175), UINT8_C( 18), UINT8_C(184), UINT8_C( 40), UINT8_C(237), UINT8_C(143), UINT8_C(173) },
      { UINT8_C(240), UINT8_C( 75), UINT8_C(236), UINT8_C(212), UINT8_C( 39), UINT8_C(  4), UINT8_C( 18), UINT8_C(136),
        UINT8_C(  2), UINT8_C(111), UINT8_C(160), UINT8_C( 35), UINT8_C(187), UINT8_C(115), UINT8_C(179), UINT8_C( 27) },
      { UINT8_C(148), UINT8_C(232), UINT8_C( 33), UINT8_C( 30), UINT8_C(164), UINT8_C( 58), UINT8_C(  6), UINT8_C( 94),
        UINT8_C(233), UINT8_C( 24), UINT8_C( 22), UINT8_C( 18), UINT8_C(  5), UINT8_C(166), UINT8_C(191), UINT8_C(245) },
      { UINT8_C(187), UINT8_C(190), UINT8_C(  0), UINT8_C(188), UINT8_C(  7), UINT8_C(241), UINT8_C( 36), UINT8_C( 18),
        UINT8_C(161), UINT8_C(  6), UINT8_C(156), UINT8_C(201), UINT8_C(222), UINT8_C( 32), UINT8_C(155), UINT8_C(135) } },
    { { UINT8_C(241), UINT8_C(171), UINT8_C(201), UINT8_C( 24), UINT8_C(176), UINT8_C(220), UINT8_C(160), UINT8_C(178),
        UINT8_C( 75), UINT8_C( 64), UINT8_C(213), UINT8_C(  7), UINT8_C(179), UINT8_C(137), UINT8_C( 34), UINT8_C( 72) },
      { UINT8_C(113), UINT8_C( 67), UINT8_C(102), UINT8_C( 21), UINT8_C(125), UINT8_C(109), UINT8_C(115), UINT8_C(103),
        UINT8_C(133), UINT8_C(138), UINT8_C(121), UINT8_C(139), UINT8_C( 48), UINT8_C( 56), UINT8_C(128), UINT8_C( 33) },
      { UINT8_C(227), UINT8_C( 74), UINT8_C( 57), UINT8_C(147), UINT8_C( 38), UINT8_C(217), UINT8_C( 69), UINT8_C(113),
        UINT8_C( 26), UINT8_C( 27), UINT8_C(120), UINT8_C(205), UINT8_C(164), UINT8_C(154), UINT8_C( 21), UINT8_C( 21) },
      { UINT8_C( 99), UINT8_C(178), UINT8_C(246), UINT8_C(150), UINT8_C(  7), UINT8_C( 72), UINT8_C(206), UINT8_C(188),
        UINT8_C(182), UINT8_C(175), UINT8_C(214), UINT8_C( 73), UINT8_C( 39), UINT8_C(235), UINT8_C(141), UINT8_C( 84) } },
    { { UINT8_C(222), UINT8_C(124), UINT8_C( 43), UINT8_C( 91), UINT8_C(233), UINT8_C(158), UINT8_C(194), UINT8_C(110),
        UINT8_C( 40), UINT8_C( 59), UINT8_C(249), UINT8_C( 88), UINT8_C(115), UINT8_C(122), UINT8_C(121), UINT8_C( 87) },
      { UINT8_C(196), UINT8_C(178), UINT8_C(234), UINT8_C(234), UINT8_C(140), UINT8_C( 48), UINT8_C( 91), UINT8_C(166),
        UINT8_C( 75), UINT8_C(212), UINT8_C(115), UINT8_C(239), UINT8_C(110), UINT8_C(137), UINT8_C(  4), UINT8_C( 76) },
      { UINT8_C(  5), UINT8_C( 47), UINT8_C(168), UINT8_C(238), UINT8_C(206), UINT8_C(106), UINT8_C( 92), UINT8_C(246),
        UINT8_C(166), UINT8_C( 86), UINT8_C( 79), UINT8_C( 25), UINT8_C(208), UINT8_C(200), UINT8_C(112), UINT8_C(148) },
      { UINT8_C(157),    UINT8_MAX, UINT8_C(109), UINT8_C( 95), UINT8_C( 43), UINT8_C(216), UINT8_C(195), UINT8_C(190),
        UINT8_C(131), UINT8_C(185), UINT8_C( 29), UINT8_C( 46), UINT8_C(213), UINT8_C(185), UINT8_C(229), UINT8_C(159) } },
    { { UINT8_C(123), UINT8_C( 91), UINT8_C(126), UINT8_C(  7), UINT8_C(139), UINT8_C(217), UINT8_C(173), UINT8_C(214),
        UINT8_C(173), UINT8_C( 32), UINT8_C(197), UINT8_C( 28), UINT8_C(169), UINT8_C(201), UINT8_C(104), UINT8_C(174) },
      { UINT8_C(249), UINT8_C( 16), UINT8_C(156), UINT8_C(199), UINT8_C(123), UINT8_C(249), UINT8_C(189), UINT8_C( 33),
        UINT8_C( 79), UINT8_C( 12), UINT8_C( 58), UINT8_C( 31), UINT8_C(213), UINT8_C(171), UINT8_C(179), UINT8_C( 80) },
      { UINT8_C(  6), UINT8_C( 49), UINT8_C( 87), UINT8_C(145), UINT8_C( 10), UINT8_C(  4), UINT8_C(103), UINT8_C(184),
        UINT8_C( 36), UINT8_C( 44), UINT8_C(212), UINT8_C(206), UINT8_C(245), UINT8_C( 60), UINT8_C(124), UINT8_C(238) },
      { UINT8_C(110), UINT8_C(124), UINT8_C(195), UINT8_C( 61), UINT8_C(252), UINT8_C(206), UINT8_C(  3), UINT8_C(109),
        UINT8_C(216), UINT8_C( 64), UINT8_C( 95), UINT8_C(203), UINT8_C(201), UINT8_C( 56), UINT8_C(159), UINT8_C( 76) } },
    { { UINT8_C( 77), UINT8_C( 25), UINT8_C(181), UINT8_C(200), UINT8_C( 18), UINT8_C(115), UINT8_C(233), UINT8_C( 97),
        UINT8_C(127), UINT8_C( 35), UINT8_C(128), UINT8_C( 84), UINT8_C(206), UINT8_C( 51), UINT8_C(164), UINT8_C(212) },
      { UINT8_C(100), UINT8_C(251), UINT8_C(101), UINT8_C(110),    UINT8_MAX, UINT8_C(204), UINT8_C( 38), UINT8_C( 36),
        UINT8_C(248), UINT8_C(250), UINT8_C(242), UINT8_C(238), UINT8_C( 55), UINT8_C(110), UINT8_C(220), UINT8_C(132) },
      { UINT8_C(135), UINT8_C(146), UINT8_C( 76), UINT8_C(153), UINT8_C(  5), UINT8_C( 53), UINT8_C(250), UINT8_C(132),
        UINT8_C( 88), UINT8_C(122), UINT8_C(217), UINT8_C( 39), UINT8_C(173), UINT8_C(125), UINT8_C(251), UINT8_C( 17) },
      { UINT8_C(112), UINT8_C(130), UINT8_C(206), UINT8_C(243), UINT8_C( 12), UINT8_C( 10), UINT8_C(189), UINT8_C(193),
        UINT8_C( 31), UINT8_C(163), UINT8_C(153), UINT8_C( 27), UINT8_C( 68), UINT8_C( 66), UINT8_C(195), UINT8_C( 71) } },
    { { UINT8_C(121), UINT8_C( 97), UINT8_C(128), UINT8_C(120), UINT8_C( 45), UINT8_C(166), UINT8_C(156), UINT8_C( 38),
        UINT8_C(161), UINT8_C(142), UINT8_C( 20), UINT8_C(216), UINT8_C(253), UINT8_C(240), UINT8_C( 92), UINT8_C(132) },
      { UINT8_C(130), UINT8_C(168), UINT8_C( 30), UINT8_C(135), UINT8_C(221), UINT8_C( 24), UINT8_C( 12), UINT8_C( 53),
        UINT8_C(147), UINT8_C(229), UINT8_C( 92), UINT8_C( 64), UINT8_C( 98), UINT8_C( 88), UINT8_C( 82), UINT8_C(219) },
      { UINT8_C(185), UINT8_C(210), UINT8_C( 84), UINT8_C(230), UINT8_C(120), UINT8_C(240), UINT8_C( 12), UINT8_C( 25),
        UINT8_C(127), UINT8_C( 32), UINT8_C(241), UINT8_C(124), UINT8_C( 17), UINT8_C( 77), UINT8_C(  0), UINT8_C(147) },
      { UINT8_C(176), UINT8_C(139), UINT8_C(182), UINT8_C(215), UINT8_C(146), UINT8_C(126), UINT8_C(156), UINT8_C( 66),
        UINT8_C(181), UINT8_C( 83), UINT8_C(169), UINT8_C( 20), UINT8_C( 78), UINT8_C(251), UINT8_C(174), UINT8_C(204) } },
    { { UINT8_C(245), UINT8_C( 30), UINT8_C( 27), UINT8_C(210), UINT8_C( 55), UINT8_C( 39), UINT8_C(  8), UINT8_C(202),
        UINT8_C( 12), UINT8_C(100), UINT8_C( 10), UINT8_C(110), UINT8_C(188), UINT8_C( 92), UINT8_C( 74), UINT8_C(117) },
      { UINT8_C( 46), UINT8_C(158), UINT8_C( 92), UINT8_C(167), UINT8_C(142), UINT8_C(104), UINT8_C(192), UINT8_C( 13),
        UINT8_C(137), UINT8_C(178), UINT8_C(137), UINT8_C(154),    UINT8_MAX, UINT8_C(138), UINT8_C( 45), UINT8_C(245) },
      { UINT8_C(168), UINT8_C( 72), UINT8_C(199), UINT8_C(223), UINT8_C(111), UINT8_C(207), UINT8_C(169), UINT8_C(123),
        UINT8_C( 52), UINT8_C(180), UINT8_C(234), UINT8_C(240), UINT8_C( 16), UINT8_C( 52), UINT8_C(102), UINT8_C( 63) },
      { UINT8_C(111), UINT8_C(116), UINT8_C(134), UINT8_C( 10), UINT8_C( 86), UINT8_C(142), UINT8_C( 31), UINT8_C( 56),
        UINT8_C( 97), UINT8_C(102), UINT8_C(107), UINT8_C(196), UINT8_C(171), UINT8_C(178), UINT8_C(131), UINT8_C( 43) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint8x16_t a = simde_vld1q_u8(test_vec[i].a);
    simde_uint8x16_t b = simde_vld1q_u8(test_vec[i].b);
    simde_uint8x16_t c = simde_vld1q_u8(test_vec[i].c);
    simde_uint8x16_t r = simde_vabaq_u8(a, b, c);

    simde_test_arm_neon_assert_equal_u8x16(r, simde_vld1q_u8(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint8x16_t a = simde_test_arm_neon_random_u8x16();
    simde_uint8x16_t b = simde_test_arm_neon_random_u8x16();
    simde_uint8x16_t c = simde_test_arm_neon_random_u8x16();
    simde_uint8x16_t r = simde_vabaq_u8(a, b, c);

    simde_test_arm_neon_write_u8x16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u8x16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u8x16(2, c, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u8x16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vabaq_u16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint16_t a[8];
    uint16_t b[8];
    uint16_t c[8];
    uint16_t r[8];
  } test_vec[] = {
    { { UINT16_C(49874), UINT16_C(24806), UINT16_C(42538), UINT16_C(45934), UINT16_C(63320), UINT16_C(22605), UINT16_C(31617), UINT16_C(10829) },
      { UINT16_C( 5315), UINT16_C(13065), UINT16_C(46052), UINT16_C( 6318), UINT16_C(39015), UINT16_C(30472), UINT16_C(28364), UINT16_C(40630) },
      { UINT16_C(39984), UINT16_C(23551), UINT16_C(27971), UINT16_C(39694), UINT16_C(23652), UINT16_C(59123), UINT16_C(16599), UINT16_C(39440) },
      { UINT16_C(19007), UINT16_C(35292), UINT16_C(60619), UINT16_C(13774), UINT16_C(13147), UINT16_C(51256), UINT16_C(43382), UINT16_C(12019) } },
    { { UINT16_C( 6485), UINT16_C(14797), UINT16_C(31948), UINT16_C(13137), UINT16_C(22804), UINT16_C(57771), UINT16_C(25032), UINT16_C(63615) },
      { UINT16_C(32510), UINT16_C(16723), UINT16_C(25323), UINT16_C(20700), UINT16_C(53438), UINT16_C(38198), UINT16_C(17936), UINT16_C(25903) },
      { UINT16_C(64863), UINT16_C(11422), UINT16_C(61305), UINT16_C(36191), UINT16_C( 2633), UINT16_C( 4462), UINT16_C(61036), UINT16_C(27145) },
      { UINT16_C(38838), UINT16_C(20098), UINT16_C( 2394), UINT16_C(28628), UINT16_C( 8073), UINT16_C(25971), UINT16_C( 2596), UINT16_C(64857) } },
    { { UINT16_C(23916), UINT16_C(22699), UINT16_C(34751), UINT16_C(32168), UINT16_C(56919), UINT16_C(26642), UINT16_C(16676), UINT16_C(33741) },
      { UINT16_C(27710), UINT16_C(47023), UINT16_C( 3931), UINT16_C(42053), UINT16_C(45849), UINT16_C(34229), UINT16_C(49057), UINT16_C( 3823) },
      { UINT16_C(39452), UINT16_C(56166), UINT16_C( 3618), UINT16_C(31064), UINT16_C(27372), UINT16_C( 4321), UINT16_C(44971), UINT16_C(60051) },
      { UINT16_C(35658), UINT16_C(31842), UINT16_C(35064), UINT16_C(43157), UINT16_C( 9860), UINT16_C(56550), UINT16_C(20762), UINT16_C(24433) } },
    { { UINT16_C(17179), UINT16_C(30369), UINT16_C(58962), UINT16_C(27419), UINT16_C(53402), UINT16_C(15345), UINT16_C(57487), UINT16_C(43849) },
      { UINT16_C(44923), UINT16_C(40326), UINT16_C(57021), UINT16_C(43286), UINT16_C(63560), UINT16_C(62649), UINT16_C(19879), UINT16_C(49886) },
      { UINT16_C(32656), UINT16_C(57912), UINT16_C(21350), UINT16_C(   77), UINT16_C(15908), UINT16_C(45883), UINT16_C(34079), UINT16_C(39519) },
      { UINT16_C(29446), UINT16_C(47955), UINT16_C(29097), UINT16_C( 5092), UINT16_C(35518), UINT16_C(32111), UINT16_C( 6151), UINT16_C(54216) } },
    { { UINT16_C(58676), UINT16_C(62007), UINT16_C(19908), UINT16_C( 3227), UINT16_C(21829), UINT16_C(60416), UINT16_C(56994), UINT16_C(12974) },
      { UINT16_C(59230), UINT16_C(50196), UINT16_C(24890), UINT16_C(24260), UINT16_C(65440), UINT16_C(48914), UINT16_C(29060), UINT16_C(47449) },
      { UINT16_C(36950), UINT16_C( 6827), UINT16_C(18141), UINT16_C( 8999), UINT16_C(10139), UINT16_C(15631), UINT16_C(48646), UINT16_C(25711) },
      { UINT16_C(15420), UINT16_C(39840), UINT16_C(26657), UINT16_C(18488), UINT16_C(11594), UINT16_C(28163), UINT16_C(11044), UINT16_C(34712) } },
    { { UINT16_C(33701), UINT16_C(57128), UINT16_C(60645), UINT16_C(34110), UINT16_C(20715), UINT16_C(28740), UINT16_C(40385), UINT16_C( 5929) },
      { UINT16_C(54317), UINT16_C( 2610), UINT16_C(22810), UINT16_C(46637), UINT16_C(15744), UINT16_C(34547), UINT16_C(25595), UINT16_C(41194) },
      { UINT16_C( 4838), UINT16_C(52095), UINT16_C(48638), UINT16_C(59984), UINT16_C(37901), UINT16_C(52826), UINT16_C(33585), UINT16_C(24294) },
      { UINT16_C(17644), UINT16_C(41077), UINT16_C(20937), UINT16_C(47457), UINT16_C(42872), UINT16_C(47019), UINT16_C(48375), UINT16_C(22829) } },
    { { UINT16_C( 6231), UINT16_C(29033), UINT16_C(38513), UINT16_C(61735), UINT16_C( 7123), UINT16_C(52856), UINT16_C(25214), UINT16_C(25710) },
      { UINT16_C(61045), UINT16_C(29488), UINT16_C(32939), UINT16_C(47453), UINT16_C(46869), UINT16_C(18055), UINT16_C(27962), UINT16_C(37285) },
      { UINT16_C( 3717), UINT16_C(62979), UINT16_C(10916), UINT16_C(30952), UINT16_C(24645), UINT16_C(49990), UINT16_C(46530), UINT16_C(14120) },
      { UINT16_C(63559), UINT16_C(62524), UINT16_C(60536), UINT16_C(12700), UINT16_C(29347), UINT16_C(19255), UINT16_C(43782), UINT16_C(48875) } },
    { { UINT16_C(22691), UINT16_C(20139), UINT16_C( 2264), UINT16_C(60679), UINT16_C(36800), UINT16_C(64052), UINT16_C(55804), UINT16_C(33420) },
      { UINT16_C(36839), UINT16_C(35704), UINT16_C(24761), UINT16_C(65283), UINT16_C(19136), UINT16_C(33730), UINT16_C(60159), UINT16_C(41658) },
      { UINT16_C(25922), UINT16_C( 7152), UINT16_C(63598), UINT16_C(11784), UINT16_C(15495), UINT16_C(33576), UINT16_C(46101), UINT16_C(64517) },
      { UINT16_C(33608), UINT16_C(48691), UINT16_C(41101), UINT16_C(48642), UINT16_C(40441), UINT16_C(64206), UINT16_C( 4326), UINT16_C(56279) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint16x8_t a = simde_vld1q_u16(test_vec[i].a);
    simde_uint16x8_t b = simde_vld1q_u16(test_vec[i].b);
    simde_uint16x8_t c = simde_vld1q_u16(test_vec[i].c);
    simde_uint16x8_t r = simde_vabaq_u16(a, b, c);

    simde_test_arm_neon_assert_equal_u16x8(r, simde_vld1q_u16(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint16x8_t a = simde_test_arm_neon_random_u16x8();
    simde_uint16x8_t b = simde_test_arm_neon_random_u16x8();
    simde_uint16x8_t c = simde_test_arm_neon_random_u16x8();
    simde_uint16x8_t r = simde_vabaq_u16(a, b, c);

    simde_test_arm_neon_write_u16x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u16x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u16x8(2, c, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u16x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

#if !defined(TEST_SIMDE_VABD_NO_TEST_32)
static int
test_simde_vabaq_u32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint32_t a[4];
    uint32_t b[4];
    uint32_t c[4];
    uint32_t r[4];
  } test_vec[] = {
    { { UINT32_C(4253580867), UINT32_C(2684128222), UINT32_C(3559046869), UINT32_C(3950435497) },
      { UINT32_C(2953209666), UINT32_C(3873312607), UINT32_C(1634272843), UINT32_C(4267536315) },
      { UINT32_C(3422283245), UINT32_C(1181415281), UINT32_C(1595641014), UINT32_C(2873790825) },
      { UINT32_C( 427687150), UINT32_C(1081058252), UINT32_C(3597678698), UINT32_C(1049213691) } },
    { { UINT32_C(1465602552), UINT32_C(2872916320), UINT32_C(4195133247), UINT32_C(  66677270) },
      { UINT32_C(3234788431), UINT32_C(2718382572), UINT32_C( 771826373), UINT32_C(2899921843) },
      { UINT32_C(4228068508), UINT32_C(2913485165), UINT32_C(4272403688), UINT32_C(1845600286) },
      { UINT32_C(2458882629), UINT32_C(3068018913), UINT32_C(3400743266), UINT32_C(1120998827) } },
    { { UINT32_C(2167328661), UINT32_C(3458413832), UINT32_C( 201073751), UINT32_C( 213374575) },
      { UINT32_C(2013837834), UINT32_C(3810898171), UINT32_C(2212613221), UINT32_C(  49406573) },
      { UINT32_C(3129155762), UINT32_C(2911413845), UINT32_C( 968394186), UINT32_C(1699049307) },
      { UINT32_C(3282646589), UINT32_C(  62930862), UINT32_C(1445292786), UINT32_C(1863017309) } },
    { { UINT32_C( 635260457), UINT32_C(1661469438), UINT32_C(1021831887), UINT32_C(2118047948) },
      { UINT32_C(1312408056), UINT32_C( 838582631), UINT32_C(2708124486), UINT32_C(1258795042) },
      { UINT32_C(4235257086), UINT32_C(3059775975), UINT32_C( 804407139), UINT32_C( 414068767) },
      { UINT32_C(3558109487), UINT32_C(3882662782), UINT32_C(2925549234), UINT32_C(2962774223) } },
    { { UINT32_C(1483139057), UINT32_C(4018758056), UINT32_C( 915469076), UINT32_C(2709624739) },
      { UINT32_C(1671361148), UINT32_C(3457810027), UINT32_C(1694305093), UINT32_C( 746367803) },
      { UINT32_C( 998564498), UINT32_C(1462373699), UINT32_C(2760751616), UINT32_C(3460632402) },
      { UINT32_C(2155935707), UINT32_C(1719227088), UINT32_C(1981915599), UINT32_C(1128922042) } },
    { { UINT32_C(1815208705), UINT32_C( 641354465), UINT32_C(2425042773), UINT32_C(1975257059) },
      { UINT32_C( 766525674), UINT32_C(1300617805), UINT32_C(3891335829), UINT32_C( 582301473) },
      { UINT32_C(4237223450), UINT32_C(2233649200), UINT32_C(3809848576), UINT32_C(2673398197) },
      { UINT32_C( 990939185), UINT32_C(1574385860), UINT32_C(2506530026), UINT32_C(4066353783) } },
    { { UINT32_C(1590429969), UINT32_C(2024493539), UINT32_C(2237635940), UINT32_C(4003992788) },
      { UINT32_C( 719992570), UINT32_C(4289662463), UINT32_C(1877132474), UINT32_C(2785950357) },
      { UINT32_C( 654629699), UINT32_C(2426384428), UINT32_C( 555155277), UINT32_C( 235912723) },
      { UINT32_C(1655792840), UINT32_C(3887771574), UINT32_C(3559613137), UINT32_C(2259063126) } },
    { { UINT32_C(4080597748), UINT32_C(3253921799), UINT32_C(1110561964), UINT32_C(1390952207) },
      { UINT32_C(1199172890), UINT32_C(3939965341), UINT32_C( 722201880), UINT32_C(2688096939) },
      { UINT32_C( 462647828), UINT32_C( 115181146), UINT32_C(1766329946), UINT32_C(1757163853) },
      { UINT32_C( 522155514), UINT32_C(2783738698), UINT32_C(2154690030), UINT32_C(2321885293) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint32x4_t a = simde_vld1q_u32(test_vec[i].a);
    simde_uint32x4_t b = simde_vld1q_u32(test_vec[i].b);
    simde_uint32x4_t c = simde_vld1q_u32(test_vec[i].c);
    simde_uint32x4_t r = simde_vabaq_u32(a, b, c);

    simde_test_arm_neon_assert_equal_u32x4(r, simde_vld1q_u32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint32x4_t a = simde_test_arm_neon_random_u32x4();
    simde_uint32x4_t b = simde_test_arm_neon_random_u32x4();
    simde_uint32x4_t c = simde_test_arm_neon_random_u32x4();
    simde_uint32x4_t r = simde_vabaq_u32(a, b, c);

    simde_test_arm_neon_write_u32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x4(2, c, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}
#endif

SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(vaba_s8)
SIMDE_TEST_FUNC_LIST_ENTRY(vaba_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vaba_u8)
SIMDE_TEST_FUNC_LIST_ENTRY(vaba_u16)
SIMDE_TEST_FUNC_LIST_ENTRY(vaba_u32)
SIMDE_TEST_FUNC_LIST_ENTRY(vaba_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vabaq_s8)
SIMDE_TEST_FUNC_LIST_ENTRY(vabaq_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vabaq_u8)
SIMDE_TEST_FUNC_LIST_ENTRY(vabaq_u16)
#if !defined(TEST_SIMDE_VABD_NO_TEST_32)
  SIMDE_TEST_FUNC_LIST_ENTRY(vabaq_s32)
  SIMDE_TEST_FUNC_LIST_ENTRY(vabaq_u32)
#endif
SIMDE_TEST_FUNC_LIST_END

#include "test-neon-footer.h"
