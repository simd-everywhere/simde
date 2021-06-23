#define SIMDE_TEST_ARM_NEON_INSN qrshrn_n

#include "test-neon.h"
#include "../../../simde/arm/neon/qrshrn_n.h"

static int
test_simde_vqrshrn_n_s16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int16_t a[8];
    int8_t r1[8];
    int8_t r3[8];
    int8_t r5[8];
    int8_t r6[8];
    int8_t r8[8];
  } test_vec[] = {
    { { -INT16_C(  4618), -INT16_C( 28204),  INT16_C( 30834),  INT16_C(  6009),  INT16_C( 28312), -INT16_C(  2262), -INT16_C( 24784),  INT16_C( 13790) },
      {      INT8_MIN,      INT8_MIN,      INT8_MAX,      INT8_MAX,      INT8_MAX,      INT8_MIN,      INT8_MIN,      INT8_MAX },
      {      INT8_MIN,      INT8_MIN,      INT8_MAX,      INT8_MAX,      INT8_MAX,      INT8_MIN,      INT8_MIN,      INT8_MAX },
      {      INT8_MIN,      INT8_MIN,      INT8_MAX,      INT8_MAX,      INT8_MAX, -INT8_C(  71),      INT8_MIN,      INT8_MAX },
      { -INT8_C(  72),      INT8_MIN,      INT8_MAX,  INT8_C(  94),      INT8_MAX, -INT8_C(  35),      INT8_MIN,      INT8_MAX },
      { -INT8_C(  18), -INT8_C( 110),  INT8_C( 120),  INT8_C(  23),  INT8_C( 111), -INT8_C(   9), -INT8_C(  97),  INT8_C(  54) } },
    { {  INT16_C(  5394), -INT16_C( 25767),  INT16_C(  6140), -INT16_C( 10336), -INT16_C( 32548),  INT16_C(  8710), -INT16_C( 30648),  INT16_C( 16110) },
      {      INT8_MAX,      INT8_MIN,      INT8_MAX,      INT8_MIN,      INT8_MIN,      INT8_MAX,      INT8_MIN,      INT8_MAX },
      {      INT8_MAX,      INT8_MIN,      INT8_MAX,      INT8_MIN,      INT8_MIN,      INT8_MAX,      INT8_MIN,      INT8_MAX },
      {      INT8_MAX,      INT8_MIN,      INT8_MAX,      INT8_MIN,      INT8_MIN,      INT8_MAX,      INT8_MIN,      INT8_MAX },
      {  INT8_C(  84),      INT8_MIN,  INT8_C(  96),      INT8_MIN,      INT8_MIN,      INT8_MAX,      INT8_MIN,      INT8_MAX },
      {  INT8_C(  21), -INT8_C( 101),  INT8_C(  24), -INT8_C(  40), -INT8_C( 127),  INT8_C(  34), -INT8_C( 120),  INT8_C(  63) } },
    { { -INT16_C( 15754), -INT16_C(  5937),  INT16_C( 18491), -INT16_C( 11265),  INT16_C( 10678), -INT16_C(  6198), -INT16_C( 22327), -INT16_C(  9444) },
      {      INT8_MIN,      INT8_MIN,      INT8_MAX,      INT8_MIN,      INT8_MAX,      INT8_MIN,      INT8_MIN,      INT8_MIN },
      {      INT8_MIN,      INT8_MIN,      INT8_MAX,      INT8_MIN,      INT8_MAX,      INT8_MIN,      INT8_MIN,      INT8_MIN },
      {      INT8_MIN,      INT8_MIN,      INT8_MAX,      INT8_MIN,      INT8_MAX,      INT8_MIN,      INT8_MIN,      INT8_MIN },
      {      INT8_MIN, -INT8_C(  93),      INT8_MAX,      INT8_MIN,      INT8_MAX, -INT8_C(  97),      INT8_MIN,      INT8_MIN },
      { -INT8_C(  62), -INT8_C(  23),  INT8_C(  72), -INT8_C(  44),  INT8_C(  42), -INT8_C(  24), -INT8_C(  87), -INT8_C(  37) } },
    { {  INT16_C( 30141), -INT16_C( 18058),  INT16_C(  6028),  INT16_C( 26768), -INT16_C( 26985), -INT16_C(  8053),  INT16_C( 31007), -INT16_C( 27362) },
      {      INT8_MAX,      INT8_MIN,      INT8_MAX,      INT8_MAX,      INT8_MIN,      INT8_MIN,      INT8_MAX,      INT8_MIN },
      {      INT8_MAX,      INT8_MIN,      INT8_MAX,      INT8_MAX,      INT8_MIN,      INT8_MIN,      INT8_MAX,      INT8_MIN },
      {      INT8_MAX,      INT8_MIN,      INT8_MAX,      INT8_MAX,      INT8_MIN,      INT8_MIN,      INT8_MAX,      INT8_MIN },
      {      INT8_MAX,      INT8_MIN,  INT8_C(  94),      INT8_MAX,      INT8_MIN, -INT8_C( 126),      INT8_MAX,      INT8_MIN },
      {  INT8_C( 118), -INT8_C(  71),  INT8_C(  24),  INT8_C( 105), -INT8_C( 105), -INT8_C(  31),  INT8_C( 121), -INT8_C( 107) } },
    { { -INT16_C(  4549),  INT16_C( 30333),  INT16_C( 32054), -INT16_C(  4791),  INT16_C(  5030),  INT16_C( 28628), -INT16_C(  3908),  INT16_C( 31051) },
      {      INT8_MIN,      INT8_MAX,      INT8_MAX,      INT8_MIN,      INT8_MAX,      INT8_MAX,      INT8_MIN,      INT8_MAX },
      {      INT8_MIN,      INT8_MAX,      INT8_MAX,      INT8_MIN,      INT8_MAX,      INT8_MAX,      INT8_MIN,      INT8_MAX },
      {      INT8_MIN,      INT8_MAX,      INT8_MAX,      INT8_MIN,      INT8_MAX,      INT8_MAX, -INT8_C( 122),      INT8_MAX },
      { -INT8_C(  71),      INT8_MAX,      INT8_MAX, -INT8_C(  75),  INT8_C(  79),      INT8_MAX, -INT8_C(  61),      INT8_MAX },
      { -INT8_C(  18),  INT8_C( 118),  INT8_C( 125), -INT8_C(  19),  INT8_C(  20),  INT8_C( 112), -INT8_C(  15),  INT8_C( 121) } },
    { { -INT16_C( 16027), -INT16_C(  3789), -INT16_C( 15400),  INT16_C( 28761), -INT16_C(  7078),  INT16_C( 31056),  INT16_C( 28253), -INT16_C( 26354) },
      {      INT8_MIN,      INT8_MIN,      INT8_MIN,      INT8_MAX,      INT8_MIN,      INT8_MAX,      INT8_MAX,      INT8_MIN },
      {      INT8_MIN,      INT8_MIN,      INT8_MIN,      INT8_MAX,      INT8_MIN,      INT8_MAX,      INT8_MAX,      INT8_MIN },
      {      INT8_MIN, -INT8_C( 118),      INT8_MIN,      INT8_MAX,      INT8_MIN,      INT8_MAX,      INT8_MAX,      INT8_MIN },
      {      INT8_MIN, -INT8_C(  59),      INT8_MIN,      INT8_MAX, -INT8_C( 111),      INT8_MAX,      INT8_MAX,      INT8_MIN },
      { -INT8_C(  63), -INT8_C(  15), -INT8_C(  60),  INT8_C( 112), -INT8_C(  28),  INT8_C( 121),  INT8_C( 110), -INT8_C( 103) } },
    { { -INT16_C( 29860), -INT16_C( 27889),  INT16_C( 22792), -INT16_C( 20608),  INT16_C( 21612),  INT16_C( 10270),  INT16_C( 26948), -INT16_C( 22110) },
      {      INT8_MIN,      INT8_MIN,      INT8_MAX,      INT8_MIN,      INT8_MAX,      INT8_MAX,      INT8_MAX,      INT8_MIN },
      {      INT8_MIN,      INT8_MIN,      INT8_MAX,      INT8_MIN,      INT8_MAX,      INT8_MAX,      INT8_MAX,      INT8_MIN },
      {      INT8_MIN,      INT8_MIN,      INT8_MAX,      INT8_MIN,      INT8_MAX,      INT8_MAX,      INT8_MAX,      INT8_MIN },
      {      INT8_MIN,      INT8_MIN,      INT8_MAX,      INT8_MIN,      INT8_MAX,      INT8_MAX,      INT8_MAX,      INT8_MIN },
      { -INT8_C( 117), -INT8_C( 109),  INT8_C(  89), -INT8_C(  80),  INT8_C(  84),  INT8_C(  40),  INT8_C( 105), -INT8_C(  86) } },
    { { -INT16_C( 10965),  INT16_C(   922), -INT16_C(  3176), -INT16_C(  3469), -INT16_C( 15400),  INT16_C( 13675),  INT16_C( 31026), -INT16_C( 28978) },
      {      INT8_MIN,      INT8_MAX,      INT8_MIN,      INT8_MIN,      INT8_MIN,      INT8_MAX,      INT8_MAX,      INT8_MIN },
      {      INT8_MIN,  INT8_C( 115),      INT8_MIN,      INT8_MIN,      INT8_MIN,      INT8_MAX,      INT8_MAX,      INT8_MIN },
      {      INT8_MIN,  INT8_C(  29), -INT8_C(  99), -INT8_C( 108),      INT8_MIN,      INT8_MAX,      INT8_MAX,      INT8_MIN },
      {      INT8_MIN,  INT8_C(  14), -INT8_C(  50), -INT8_C(  54),      INT8_MIN,      INT8_MAX,      INT8_MAX,      INT8_MIN },
      { -INT8_C(  43),  INT8_C(   4), -INT8_C(  12), -INT8_C(  14), -INT8_C(  60),  INT8_C(  53),  INT8_C( 121), -INT8_C( 113) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x8_t a = simde_vld1q_s16(test_vec[i].a);

    simde_int8x8_t r1 = simde_vqrshrn_n_s16(a, 1);
    simde_int8x8_t r3 = simde_vqrshrn_n_s16(a, 3);
    simde_int8x8_t r5 = simde_vqrshrn_n_s16(a, 5);
    simde_int8x8_t r6 = simde_vqrshrn_n_s16(a, 6);
    simde_int8x8_t r8 = simde_vqrshrn_n_s16(a, 8);

    simde_test_arm_neon_assert_equal_i8x8(r1, simde_vld1_s8(test_vec[i].r1));
    simde_test_arm_neon_assert_equal_i8x8(r3, simde_vld1_s8(test_vec[i].r3));
    simde_test_arm_neon_assert_equal_i8x8(r5, simde_vld1_s8(test_vec[i].r5));
    simde_test_arm_neon_assert_equal_i8x8(r6, simde_vld1_s8(test_vec[i].r6));
    simde_test_arm_neon_assert_equal_i8x8(r8, simde_vld1_s8(test_vec[i].r8));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int16x8_t a = simde_test_arm_neon_random_i16x8();

    simde_int8x8_t r1 = simde_vqrshrn_n_s16(a, 1);
    simde_int8x8_t r3 = simde_vqrshrn_n_s16(a, 3);
    simde_int8x8_t r5 = simde_vqrshrn_n_s16(a, 5);
    simde_int8x8_t r6 = simde_vqrshrn_n_s16(a, 6);
    simde_int8x8_t r8 = simde_vqrshrn_n_s16(a, 8);

    simde_test_arm_neon_write_i16x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i8x8(2, r1, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i8x8(2, r3, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i8x8(2, r5, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i8x8(2, r6, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i8x8(2, r8, SIMDE_TEST_VEC_POS_LAST);

  }
  return 1;
#endif
}

static int
test_simde_vqrshrn_n_s32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int32_t a[4];
    int16_t r3[4];
    int16_t r6[4];
    int16_t r10[4];
    int16_t r13[4];
    int16_t r16[4];
  } test_vec[] = {
    { {  INT32_C(  1611043215), -INT32_C(   806630736), -INT32_C(  1117656904), -INT32_C(  1792958115) },
      {        INT16_MAX,        INT16_MIN,        INT16_MIN,        INT16_MIN },
      {        INT16_MAX,        INT16_MIN,        INT16_MIN,        INT16_MIN },
      {        INT16_MAX,        INT16_MIN,        INT16_MIN,        INT16_MIN },
      {        INT16_MAX,        INT16_MIN,        INT16_MIN,        INT16_MIN },
      {  INT16_C( 24583), -INT16_C( 12308), -INT16_C( 17054), -INT16_C( 27358) } },
    { { -INT32_C(   380986648),  INT32_C(  1819959490), -INT32_C(  1487019498), -INT32_C(   813418944) },
      {        INT16_MIN,        INT16_MAX,        INT16_MIN,        INT16_MIN },
      {        INT16_MIN,        INT16_MAX,        INT16_MIN,        INT16_MIN },
      {        INT16_MIN,        INT16_MAX,        INT16_MIN,        INT16_MIN },
      {        INT16_MIN,        INT16_MAX,        INT16_MIN,        INT16_MIN },
      { -INT16_C(  5813),  INT16_C( 27770), -INT16_C( 22690), -INT16_C( 12412) } },
    { {  INT32_C(  2016447176),  INT32_C(   222829397),  INT32_C(  1640671491),  INT32_C(   855043146) },
      {        INT16_MAX,        INT16_MAX,        INT16_MAX,        INT16_MAX },
      {        INT16_MAX,        INT16_MAX,        INT16_MAX,        INT16_MAX },
      {        INT16_MAX,        INT16_MAX,        INT16_MAX,        INT16_MAX },
      {        INT16_MAX,  INT16_C( 27201),        INT16_MAX,        INT16_MAX },
      {  INT16_C( 30769),  INT16_C(  3400),  INT16_C( 25035),  INT16_C( 13047) } },
    { {  INT32_C(  1226522758), -INT32_C(  1229613664), -INT32_C(  1201794440),  INT32_C(   294117961) },
      {        INT16_MAX,        INT16_MIN,        INT16_MIN,        INT16_MAX },
      {        INT16_MAX,        INT16_MIN,        INT16_MIN,        INT16_MAX },
      {        INT16_MAX,        INT16_MIN,        INT16_MIN,        INT16_MAX },
      {        INT16_MAX,        INT16_MIN,        INT16_MIN,        INT16_MAX },
      {  INT16_C( 18715), -INT16_C( 18762), -INT16_C( 18338),  INT16_C(  4488) } },
    { { -INT32_C(  1031162003), -INT32_C(   691023406), -INT32_C(  1002989190),  INT32_C(   217525637) },
      {        INT16_MIN,        INT16_MIN,        INT16_MIN,        INT16_MAX },
      {        INT16_MIN,        INT16_MIN,        INT16_MIN,        INT16_MAX },
      {        INT16_MIN,        INT16_MIN,        INT16_MIN,        INT16_MAX },
      {        INT16_MIN,        INT16_MIN,        INT16_MIN,  INT16_C( 26553) },
      { -INT16_C( 15734), -INT16_C( 10544), -INT16_C( 15304),  INT16_C(  3319) } },
    { {  INT32_C(   223679085),  INT32_C(   549718696),  INT32_C(  1725440541),  INT32_C(  1903648516) },
      {        INT16_MAX,        INT16_MAX,        INT16_MAX,        INT16_MAX },
      {        INT16_MAX,        INT16_MAX,        INT16_MAX,        INT16_MAX },
      {        INT16_MAX,        INT16_MAX,        INT16_MAX,        INT16_MAX },
      {  INT16_C( 27305),        INT16_MAX,        INT16_MAX,        INT16_MAX },
      {  INT16_C(  3413),  INT16_C(  8388),  INT16_C( 26328),  INT16_C( 29047) } },
    { { -INT32_C(   382533609),  INT32_C(  1287586514),  INT32_C(   554825372), -INT32_C(  1876096989) },
      {        INT16_MIN,        INT16_MAX,        INT16_MAX,        INT16_MIN },
      {        INT16_MIN,        INT16_MAX,        INT16_MAX,        INT16_MIN },
      {        INT16_MIN,        INT16_MAX,        INT16_MAX,        INT16_MIN },
      {        INT16_MIN,        INT16_MAX,        INT16_MAX,        INT16_MIN },
      { -INT16_C(  5837),  INT16_C( 19647),  INT16_C(  8466), -INT16_C( 28627) } },
    { { -INT32_C(  1029799398), -INT32_C(  1428004211), -INT32_C(  2012169596),  INT32_C(   838502170) },
      {        INT16_MIN,        INT16_MIN,        INT16_MIN,        INT16_MAX },
      {        INT16_MIN,        INT16_MIN,        INT16_MIN,        INT16_MAX },
      {        INT16_MIN,        INT16_MIN,        INT16_MIN,        INT16_MAX },
      {        INT16_MIN,        INT16_MIN,        INT16_MIN,        INT16_MAX },
      { -INT16_C( 15713), -INT16_C( 21790), -INT16_C( 30703),  INT16_C( 12795) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x4_t a = simde_vld1q_s32(test_vec[i].a);

    simde_int16x4_t r3 = simde_vqrshrn_n_s32(a, 3);
    simde_int16x4_t r6 = simde_vqrshrn_n_s32(a, 6);
    simde_int16x4_t r10 = simde_vqrshrn_n_s32(a, 10);
    simde_int16x4_t r13 = simde_vqrshrn_n_s32(a, 13);
    simde_int16x4_t r16 = simde_vqrshrn_n_s32(a, 16);

    simde_test_arm_neon_assert_equal_i16x4(r3, simde_vld1_s16(test_vec[i].r3));
    simde_test_arm_neon_assert_equal_i16x4(r6, simde_vld1_s16(test_vec[i].r6));
    simde_test_arm_neon_assert_equal_i16x4(r10, simde_vld1_s16(test_vec[i].r10));
    simde_test_arm_neon_assert_equal_i16x4(r13, simde_vld1_s16(test_vec[i].r13));
    simde_test_arm_neon_assert_equal_i16x4(r16, simde_vld1_s16(test_vec[i].r16));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int32x4_t a = simde_test_arm_neon_random_i32x4();

    simde_int16x4_t r3 = simde_vqrshrn_n_s32(a, 3);
    simde_int16x4_t r6 = simde_vqrshrn_n_s32(a, 6);
    simde_int16x4_t r10 = simde_vqrshrn_n_s32(a, 10);
    simde_int16x4_t r13 = simde_vqrshrn_n_s32(a, 13);
    simde_int16x4_t r16 = simde_vqrshrn_n_s32(a, 16);

    simde_test_arm_neon_write_i32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i16x4(2, r3, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i16x4(2, r6, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i16x4(2, r10, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i16x4(2, r13, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i16x4(2, r16, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vqrshrn_n_s64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int64_t a[2];
    int32_t r6[2];
    int32_t r13[2];
    int32_t r19[2];
    int32_t r26[2];
    int32_t r32[2];
  } test_vec[] = {
    { {  INT64_C( 2302647728353811175),  INT64_C(  535769041607280145) },
      {              INT32_MAX,              INT32_MAX },
      {              INT32_MAX,              INT32_MAX },
      {              INT32_MAX,              INT32_MAX },
      {              INT32_MAX,              INT32_MAX },
      {  INT32_C(   536126953),  INT32_C(   124743451) } },
    { {  INT64_C(  372114569886920277),  INT64_C( 6467035410437456687) },
      {              INT32_MAX,              INT32_MAX },
      {              INT32_MAX,              INT32_MAX },
      {              INT32_MAX,              INT32_MAX },
      {              INT32_MAX,              INT32_MAX },
      {  INT32_C(    86639675),  INT32_C(  1505724017) } },
    { { -INT64_C( 2871325382591897056), -INT64_C( 7824979899685810618) },
      {              INT32_MIN,              INT32_MIN },
      {              INT32_MIN,              INT32_MIN },
      {              INT32_MIN,              INT32_MIN },
      {              INT32_MIN,              INT32_MIN },
      { -INT32_C(   668532537), -INT32_C(  1821895107) } },
    { {  INT64_C( 8558121630715626373),  INT64_C( 7682114339395585234) },
      {              INT32_MAX,              INT32_MAX },
      {              INT32_MAX,              INT32_MAX },
      {              INT32_MAX,              INT32_MAX },
      {              INT32_MAX,              INT32_MAX },
      {  INT32_C(  1992592968),  INT32_C(  1788631626) } },
    { { -INT64_C( 1144871252998837892),  INT64_C( 6789098208188482407) },
      {              INT32_MIN,              INT32_MAX },
      {              INT32_MIN,              INT32_MAX },
      {              INT32_MIN,              INT32_MAX },
      {              INT32_MIN,              INT32_MAX },
      { -INT32_C(   266561111),  INT32_C(  1580710106) } },
    { { -INT64_C(  235908834334434053),  INT64_C( 3051994341410100390) },
      {              INT32_MIN,              INT32_MAX },
      {              INT32_MIN,              INT32_MAX },
      {              INT32_MIN,              INT32_MAX },
      {              INT32_MIN,              INT32_MAX },
      { -INT32_C(    54926806),  INT32_C(   710597807) } },
    { { -INT64_C( 3738118098013795195),  INT64_C( 2559355378650410828) },
      {              INT32_MIN,              INT32_MAX },
      {              INT32_MIN,              INT32_MAX },
      {              INT32_MIN,              INT32_MAX },
      {              INT32_MIN,              INT32_MAX },
      { -INT32_C(   870348443),  INT32_C(   595896360) } },
    { {  INT64_C( 3128629024099050052),  INT64_C(  957989672789519219) },
      {              INT32_MAX,              INT32_MAX },
      {              INT32_MAX,              INT32_MAX },
      {              INT32_MAX,              INT32_MAX },
      {              INT32_MAX,              INT32_MAX },
      {  INT32_C(   728440709),  INT32_C(   223049352) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int64x2_t a = simde_vld1q_s64(test_vec[i].a);

    simde_int32x2_t r6 = simde_vqrshrn_n_s64(a, 6);
    simde_int32x2_t r13 = simde_vqrshrn_n_s64(a, 13);
    simde_int32x2_t r19 = simde_vqrshrn_n_s64(a, 19);
    simde_int32x2_t r26 = simde_vqrshrn_n_s64(a, 26);
    simde_int32x2_t r32 = simde_vqrshrn_n_s64(a, 32);

    simde_test_arm_neon_assert_equal_i32x2(r6, simde_vld1_s32(test_vec[i].r6));
    simde_test_arm_neon_assert_equal_i32x2(r13, simde_vld1_s32(test_vec[i].r13));
    simde_test_arm_neon_assert_equal_i32x2(r19, simde_vld1_s32(test_vec[i].r19));
    simde_test_arm_neon_assert_equal_i32x2(r26, simde_vld1_s32(test_vec[i].r26));
    simde_test_arm_neon_assert_equal_i32x2(r32, simde_vld1_s32(test_vec[i].r32));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int64x2_t a = simde_test_arm_neon_random_i64x2();

    simde_int32x2_t r6 = simde_vqrshrn_n_s64(a, 6);
    simde_int32x2_t r13 = simde_vqrshrn_n_s64(a, 13);
    simde_int32x2_t r19 = simde_vqrshrn_n_s64(a, 19);
    simde_int32x2_t r26 = simde_vqrshrn_n_s64(a, 26);
    simde_int32x2_t r32 = simde_vqrshrn_n_s64(a, 32);

    simde_test_arm_neon_write_i64x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i32x2(2, r6, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i32x2(2, r13, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i32x2(2, r19, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i32x2(2, r26, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i32x2(2, r32, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vqrshrn_n_u16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint16_t a[8];
    uint8_t r1[8];
    uint8_t r3[8];
    uint8_t r5[8];
    uint8_t r6[8];
    uint8_t r8[8];
  } test_vec[] = {
    { { UINT16_C(37470), UINT16_C(46454), UINT16_C(45891), UINT16_C(37397), UINT16_C(50551), UINT16_C( 7497), UINT16_C(52835), UINT16_C(11860) },
      {    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX },
      {    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX },
      {    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(234),    UINT8_MAX,    UINT8_MAX },
      {    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(117),    UINT8_MAX, UINT8_C(185) },
      { UINT8_C(146), UINT8_C(181), UINT8_C(179), UINT8_C(146), UINT8_C(197), UINT8_C( 29), UINT8_C(206), UINT8_C( 46) } },
    { { UINT16_C(30356), UINT16_C(27442), UINT16_C( 6753), UINT16_C(44735), UINT16_C(30099), UINT16_C(51988), UINT16_C(24248), UINT16_C( 5664) },
      {    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX },
      {    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX },
      {    UINT8_MAX,    UINT8_MAX, UINT8_C(211),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(177) },
      {    UINT8_MAX,    UINT8_MAX, UINT8_C(106),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C( 89) },
      { UINT8_C(119), UINT8_C(107), UINT8_C( 26), UINT8_C(175), UINT8_C(118), UINT8_C(203), UINT8_C( 95), UINT8_C( 22) } },
    { { UINT16_C(38640), UINT16_C(13259), UINT16_C(57418), UINT16_C(49606), UINT16_C( 4005), UINT16_C( 2527), UINT16_C(13277), UINT16_C(28983) },
      {    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX },
      {    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX },
      {    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(125), UINT8_C( 79),    UINT8_MAX,    UINT8_MAX },
      {    UINT8_MAX, UINT8_C(207),    UINT8_MAX,    UINT8_MAX, UINT8_C( 63), UINT8_C( 39), UINT8_C(207),    UINT8_MAX },
      { UINT8_C(151), UINT8_C( 52), UINT8_C(224), UINT8_C(194), UINT8_C( 16), UINT8_C( 10), UINT8_C( 52), UINT8_C(113) } },
    { { UINT16_C(27049), UINT16_C( 2780), UINT16_C(40067), UINT16_C( 5817), UINT16_C(52497), UINT16_C(51681), UINT16_C(  555), UINT16_C( 7391) },
      {    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX },
      {    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C( 69),    UINT8_MAX },
      {    UINT8_MAX, UINT8_C( 87),    UINT8_MAX, UINT8_C(182),    UINT8_MAX,    UINT8_MAX, UINT8_C( 17), UINT8_C(231) },
      {    UINT8_MAX, UINT8_C( 43),    UINT8_MAX, UINT8_C( 91),    UINT8_MAX,    UINT8_MAX, UINT8_C(  9), UINT8_C(115) },
      { UINT8_C(106), UINT8_C( 11), UINT8_C(157), UINT8_C( 23), UINT8_C(205), UINT8_C(202), UINT8_C(  2), UINT8_C( 29) } },
    { { UINT16_C(43928), UINT16_C(57935), UINT16_C( 5515), UINT16_C(12708), UINT16_C(33573), UINT16_C(  570), UINT16_C(29110), UINT16_C(24436) },
      {    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX },
      {    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C( 71),    UINT8_MAX,    UINT8_MAX },
      {    UINT8_MAX,    UINT8_MAX, UINT8_C(172),    UINT8_MAX,    UINT8_MAX, UINT8_C( 18),    UINT8_MAX,    UINT8_MAX },
      {    UINT8_MAX,    UINT8_MAX, UINT8_C( 86), UINT8_C(199),    UINT8_MAX, UINT8_C(  9),    UINT8_MAX,    UINT8_MAX },
      { UINT8_C(172), UINT8_C(226), UINT8_C( 22), UINT8_C( 50), UINT8_C(131), UINT8_C(  2), UINT8_C(114), UINT8_C( 95) } },
    { { UINT16_C(20699), UINT16_C(24169), UINT16_C( 8940), UINT16_C(65141), UINT16_C(22255), UINT16_C( 7111), UINT16_C(42840), UINT16_C(61751) },
      {    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX },
      {    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX },
      {    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(222),    UINT8_MAX,    UINT8_MAX },
      {    UINT8_MAX,    UINT8_MAX, UINT8_C(140),    UINT8_MAX,    UINT8_MAX, UINT8_C(111),    UINT8_MAX,    UINT8_MAX },
      { UINT8_C( 81), UINT8_C( 94), UINT8_C( 35), UINT8_C(254), UINT8_C( 87), UINT8_C( 28), UINT8_C(167), UINT8_C(241) } },
    { { UINT16_C(34386), UINT16_C(56787), UINT16_C(30620), UINT16_C(49422), UINT16_C(18682), UINT16_C(45251), UINT16_C(14266), UINT16_C(38159) },
      {    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX },
      {    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX },
      {    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX },
      {    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(223),    UINT8_MAX },
      { UINT8_C(134), UINT8_C(222), UINT8_C(120), UINT8_C(193), UINT8_C( 73), UINT8_C(177), UINT8_C( 56), UINT8_C(149) } },
    { { UINT16_C(31112), UINT16_C(29939), UINT16_C(26779), UINT16_C(35698), UINT16_C(15039), UINT16_C( 6054), UINT16_C(56801), UINT16_C(13064) },
      {    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX },
      {    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX },
      {    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(189),    UINT8_MAX,    UINT8_MAX },
      {    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(235), UINT8_C( 95),    UINT8_MAX, UINT8_C(204) },
      { UINT8_C(122), UINT8_C(117), UINT8_C(105), UINT8_C(139), UINT8_C( 59), UINT8_C( 24), UINT8_C(222), UINT8_C( 51) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint16x8_t a = simde_vld1q_u16(test_vec[i].a);

    simde_uint8x8_t r1 = simde_vqrshrn_n_u16(a, 1);
    simde_uint8x8_t r3 = simde_vqrshrn_n_u16(a, 3);
    simde_uint8x8_t r5 = simde_vqrshrn_n_u16(a, 5);
    simde_uint8x8_t r6 = simde_vqrshrn_n_u16(a, 6);
    simde_uint8x8_t r8 = simde_vqrshrn_n_u16(a, 8);

    simde_test_arm_neon_assert_equal_u8x8(r1, simde_vld1_u8(test_vec[i].r1));
    simde_test_arm_neon_assert_equal_u8x8(r3, simde_vld1_u8(test_vec[i].r3));
    simde_test_arm_neon_assert_equal_u8x8(r5, simde_vld1_u8(test_vec[i].r5));
    simde_test_arm_neon_assert_equal_u8x8(r6, simde_vld1_u8(test_vec[i].r6));
    simde_test_arm_neon_assert_equal_u8x8(r8, simde_vld1_u8(test_vec[i].r8));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint16x8_t a = simde_test_arm_neon_random_u16x8();

    simde_uint8x8_t r1 = simde_vqrshrn_n_u16(a, 1);
    simde_uint8x8_t r3 = simde_vqrshrn_n_u16(a, 3);
    simde_uint8x8_t r5 = simde_vqrshrn_n_u16(a, 5);
    simde_uint8x8_t r6 = simde_vqrshrn_n_u16(a, 6);
    simde_uint8x8_t r8 = simde_vqrshrn_n_u16(a, 8);

    simde_test_arm_neon_write_u16x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u8x8(2, r1, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u8x8(2, r3, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u8x8(2, r5, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u8x8(2, r6, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u8x8(2, r8, SIMDE_TEST_VEC_POS_LAST);

  }
  return 1;
#endif
}

static int
test_simde_vqrshrn_n_u32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint32_t a[4];
    uint16_t r3[4];
    uint16_t r6[4];
    uint16_t r10[4];
    uint16_t r13[4];
    uint16_t r16[4];
  } test_vec[] = {
    { { UINT32_C( 893479839), UINT32_C(3809009923), UINT32_C(4130245700), UINT32_C(2676063480) },
      {      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX },
      {      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX },
      {      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX },
      {      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX },
      { UINT16_C(13633), UINT16_C(58121), UINT16_C(63023), UINT16_C(40833) } },
    { { UINT32_C(1030506720), UINT32_C(1777159214), UINT32_C( 180267616), UINT32_C(2246033382) },
      {      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX },
      {      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX },
      {      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX },
      {      UINT16_MAX,      UINT16_MAX, UINT16_C(22005),      UINT16_MAX },
      { UINT16_C(15724), UINT16_C(27117), UINT16_C( 2751), UINT16_C(34272) } },
    { { UINT32_C( 783949867), UINT32_C(1175568897), UINT32_C(1195130703), UINT32_C(2615590331) },
      {      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX },
      {      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX },
      {      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX },
      {      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX },
      { UINT16_C(11962), UINT16_C(17938), UINT16_C(18236), UINT16_C(39911) } },
    { { UINT32_C( 886592005), UINT32_C(4288529822), UINT32_C(1426676591), UINT32_C(1188817179) },
      {      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX },
      {      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX },
      {      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX },
      {      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX },
      { UINT16_C(13528), UINT16_C(65438), UINT16_C(21769), UINT16_C(18140) } },
    { { UINT32_C( 192189705), UINT32_C(2807137624), UINT32_C(2146340292), UINT32_C(1344001098) },
      {      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX },
      {      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX },
      {      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX },
      { UINT16_C(23461),      UINT16_MAX,      UINT16_MAX,      UINT16_MAX },
      { UINT16_C( 2933), UINT16_C(42834), UINT16_C(32751), UINT16_C(20508) } },
    { { UINT32_C(3313824550), UINT32_C( 683942329), UINT32_C(2541669756), UINT32_C(3235731894) },
      {      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX },
      {      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX },
      {      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX },
      {      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX },
      { UINT16_C(50565), UINT16_C(10436), UINT16_C(38783), UINT16_C(49373) } },
    { { UINT32_C(1187729902), UINT32_C(2599230678), UINT32_C(4078623657), UINT32_C(3594728879) },
      {      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX },
      {      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX },
      {      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX },
      {      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX },
      { UINT16_C(18123), UINT16_C(39661), UINT16_C(62235), UINT16_C(54851) } },
    { { UINT32_C(3785082664), UINT32_C(1695178728), UINT32_C(3824977964), UINT32_C(3483622113) },
      {      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX },
      {      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX },
      {      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX },
      {      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX },
      { UINT16_C(57756), UINT16_C(25866), UINT16_C(58365), UINT16_C(53156) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint32x4_t a = simde_vld1q_u32(test_vec[i].a);

    simde_uint16x4_t r3 = simde_vqrshrn_n_u32(a, 3);
    simde_uint16x4_t r6 = simde_vqrshrn_n_u32(a, 6);
    simde_uint16x4_t r10 = simde_vqrshrn_n_u32(a, 10);
    simde_uint16x4_t r13 = simde_vqrshrn_n_u32(a, 13);
    simde_uint16x4_t r16 = simde_vqrshrn_n_u32(a, 16);

    simde_test_arm_neon_assert_equal_u16x4(r3, simde_vld1_u16(test_vec[i].r3));
    simde_test_arm_neon_assert_equal_u16x4(r6, simde_vld1_u16(test_vec[i].r6));
    simde_test_arm_neon_assert_equal_u16x4(r10, simde_vld1_u16(test_vec[i].r10));
    simde_test_arm_neon_assert_equal_u16x4(r13, simde_vld1_u16(test_vec[i].r13));
    simde_test_arm_neon_assert_equal_u16x4(r16, simde_vld1_u16(test_vec[i].r16));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint32x4_t a = simde_test_arm_neon_random_u32x4();

    simde_uint16x4_t r3 = simde_vqrshrn_n_u32(a, 3);
    simde_uint16x4_t r6 = simde_vqrshrn_n_u32(a, 6);
    simde_uint16x4_t r10 = simde_vqrshrn_n_u32(a, 10);
    simde_uint16x4_t r13 = simde_vqrshrn_n_u32(a, 13);
    simde_uint16x4_t r16 = simde_vqrshrn_n_u32(a, 16);

    simde_test_arm_neon_write_u32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u16x4(2, r3, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u16x4(2, r6, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u16x4(2, r10, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u16x4(2, r13, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u16x4(2, r16, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vqrshrn_n_u64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint64_t a[2];
    uint32_t r6[2];
    uint32_t r13[2];
    uint32_t r19[2];
    uint32_t r26[2];
    uint32_t r32[2];
  } test_vec[] = {
    { { UINT64_C(15941048582454662066), UINT64_C( 2447769967807526190) },
      {           UINT32_MAX,           UINT32_MAX },
      {           UINT32_MAX,           UINT32_MAX },
      {           UINT32_MAX,           UINT32_MAX },
      {           UINT32_MAX,           UINT32_MAX },
      { UINT32_C(3711564602), UINT32_C( 569915857) } },
    { { UINT64_C(16343434646581711482), UINT64_C( 8511602926397521579) },
      {           UINT32_MAX,           UINT32_MAX },
      {           UINT32_MAX,           UINT32_MAX },
      {           UINT32_MAX,           UINT32_MAX },
      {           UINT32_MAX,           UINT32_MAX },
      { UINT32_C(3805252408), UINT32_C(1981761988) } },
    { { UINT64_C(13597397031398052765), UINT64_C( 8075188288926563357) },
      {           UINT32_MAX,           UINT32_MAX },
      {           UINT32_MAX,           UINT32_MAX },
      {           UINT32_MAX,           UINT32_MAX },
      {           UINT32_MAX,           UINT32_MAX },
      { UINT32_C(3165890703), UINT32_C(1880151287) } },
    { { UINT64_C(10917155318277824614), UINT64_C( 9240990489987553797) },
      {           UINT32_MAX,           UINT32_MAX },
      {           UINT32_MAX,           UINT32_MAX },
      {           UINT32_MAX,           UINT32_MAX },
      {           UINT32_MAX,           UINT32_MAX },
      { UINT32_C(2541848300), UINT32_C(2151585764) } },
    { { UINT64_C( 8247227081391779114), UINT64_C(10028514877135474886) },
      {           UINT32_MAX,           UINT32_MAX },
      {           UINT32_MAX,           UINT32_MAX },
      {           UINT32_MAX,           UINT32_MAX },
      {           UINT32_MAX,           UINT32_MAX },
      { UINT32_C(1920207190), UINT32_C(2334945574) } },
    { { UINT64_C( 7950167712849388497), UINT64_C(10207819099165674565) },
      {           UINT32_MAX,           UINT32_MAX },
      {           UINT32_MAX,           UINT32_MAX },
      {           UINT32_MAX,           UINT32_MAX },
      {           UINT32_MAX,           UINT32_MAX },
      { UINT32_C(1851042666), UINT32_C(2376693091) } },
    { { UINT64_C(14981990560708231202), UINT64_C(10284734722228308746) },
      {           UINT32_MAX,           UINT32_MAX },
      {           UINT32_MAX,           UINT32_MAX },
      {           UINT32_MAX,           UINT32_MAX },
      {           UINT32_MAX,           UINT32_MAX },
      { UINT32_C(3488266505), UINT32_C(2394601405) } },
    { { UINT64_C(15452588712357782938), UINT64_C( 4709542689916299627) },
      {           UINT32_MAX,           UINT32_MAX },
      {           UINT32_MAX,           UINT32_MAX },
      {           UINT32_MAX,           UINT32_MAX },
      {           UINT32_MAX,           UINT32_MAX },
      { UINT32_C(3597836176), UINT32_C(1096525856) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint64x2_t a = simde_vld1q_u64(test_vec[i].a);

    simde_uint32x2_t r6 = simde_vqrshrn_n_u64(a, 6);
    simde_uint32x2_t r13 = simde_vqrshrn_n_u64(a, 13);
    simde_uint32x2_t r19 = simde_vqrshrn_n_u64(a, 19);
    simde_uint32x2_t r26 = simde_vqrshrn_n_u64(a, 26);
    simde_uint32x2_t r32 = simde_vqrshrn_n_u64(a, 32);

    simde_test_arm_neon_assert_equal_u32x2(r6, simde_vld1_u32(test_vec[i].r6));
    simde_test_arm_neon_assert_equal_u32x2(r13, simde_vld1_u32(test_vec[i].r13));
    simde_test_arm_neon_assert_equal_u32x2(r19, simde_vld1_u32(test_vec[i].r19));
    simde_test_arm_neon_assert_equal_u32x2(r26, simde_vld1_u32(test_vec[i].r26));
    simde_test_arm_neon_assert_equal_u32x2(r32, simde_vld1_u32(test_vec[i].r32));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint64x2_t a = simde_test_arm_neon_random_u64x2();

    simde_uint32x2_t r6 = simde_vqrshrn_n_u64(a, 6);
    simde_uint32x2_t r13 = simde_vqrshrn_n_u64(a, 13);
    simde_uint32x2_t r19 = simde_vqrshrn_n_u64(a, 19);
    simde_uint32x2_t r26 = simde_vqrshrn_n_u64(a, 26);
    simde_uint32x2_t r32 = simde_vqrshrn_n_u64(a, 32);

    simde_test_arm_neon_write_u64x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u32x2(2, r6, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x2(2, r13, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x2(2, r19, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x2(2, r26, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x2(2, r32, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vqrshrns_n_s32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int32_t a;
    int16_t r3;
    int16_t r6;
    int16_t r10;
    int16_t r13;
    int16_t r16;
  } test_vec[] = {
    {  INT32_C(  1725319345),
             INT16_MAX,
             INT16_MAX,
             INT16_MAX,
             INT16_MAX,
       INT16_C( 26326) },
    {  INT32_C(   984584680),
             INT16_MAX,
             INT16_MAX,
             INT16_MAX,
             INT16_MAX,
       INT16_C( 15024) },
    { -INT32_C(  1251825132),
             INT16_MIN,
             INT16_MIN,
             INT16_MIN,
             INT16_MIN,
      -INT16_C( 19101) },
    {  INT32_C(   152031266),
             INT16_MAX,
             INT16_MAX,
             INT16_MAX,
       INT16_C( 18559),
       INT16_C(  2320) },
    {  INT32_C(    53193801),
             INT16_MAX,
             INT16_MAX,
             INT16_MAX,
       INT16_C(  6493),
       INT16_C(   812) },
    {  INT32_C(   832974775),
             INT16_MAX,
             INT16_MAX,
             INT16_MAX,
             INT16_MAX,
       INT16_C( 12710) },
    { -INT32_C(   541785881),
             INT16_MIN,
             INT16_MIN,
             INT16_MIN,
             INT16_MIN,
      -INT16_C(  8267) },
    {  INT32_C(   221418844),
             INT16_MAX,
             INT16_MAX,
             INT16_MAX,
       INT16_C( 27029),
       INT16_C(  3379) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    int16_t r3 = simde_vqrshrns_n_s32(test_vec[i].a, 3);
    int16_t r6 = simde_vqrshrns_n_s32(test_vec[i].a, 6);
    int16_t r10 = simde_vqrshrns_n_s32(test_vec[i].a, 10);
    int16_t r13 = simde_vqrshrns_n_s32(test_vec[i].a, 13);
    int16_t r16 = simde_vqrshrns_n_s32(test_vec[i].a, 16);

    simde_assert_equal_i16(r3, test_vec[i].r3);
    simde_assert_equal_i16(r6, test_vec[i].r6);
    simde_assert_equal_i16(r10, test_vec[i].r10);
    simde_assert_equal_i16(r13, test_vec[i].r13);
    simde_assert_equal_i16(r16, test_vec[i].r16);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    int32_t a = simde_test_codegen_random_i32();

    int16_t r3 = simde_vqrshrns_n_s32(a, 3);
    int16_t r6 = simde_vqrshrns_n_s32(a, 6);
    int16_t r10 = simde_vqrshrns_n_s32(a, 10);
    int16_t r13 = simde_vqrshrns_n_s32(a, 13);
    int16_t r16 = simde_vqrshrns_n_s32(a, 16);

    simde_test_codegen_write_i32(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_i16(2, r3, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i16(2, r6, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i16(2, r10, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i16(2, r13, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i16(2, r16, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vqrshrns_n_u32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint32_t a;
    uint16_t r3;
    uint16_t r6;
    uint16_t r10;
    uint16_t r13;
    uint16_t r16;
  } test_vec[] = {
    { UINT32_C(1293559948),
           UINT16_MAX,
           UINT16_MAX,
           UINT16_MAX,
           UINT16_MAX,
      UINT16_C(19738) },
    { UINT32_C(4172659806),
           UINT16_MAX,
           UINT16_MAX,
           UINT16_MAX,
           UINT16_MAX,
      UINT16_C(63670) },
    { UINT32_C( 784322373),
           UINT16_MAX,
           UINT16_MAX,
           UINT16_MAX,
           UINT16_MAX,
      UINT16_C(11968) },
    { UINT32_C(1658522438),
           UINT16_MAX,
           UINT16_MAX,
           UINT16_MAX,
           UINT16_MAX,
      UINT16_C(25307) },
    { UINT32_C(1605117815),
           UINT16_MAX,
           UINT16_MAX,
           UINT16_MAX,
           UINT16_MAX,
      UINT16_C(24492) },
    { UINT32_C(1910216879),
           UINT16_MAX,
           UINT16_MAX,
           UINT16_MAX,
           UINT16_MAX,
      UINT16_C(29148) },
    { UINT32_C(3031827291),
           UINT16_MAX,
           UINT16_MAX,
           UINT16_MAX,
           UINT16_MAX,
      UINT16_C(46262) },
    { UINT32_C(3342166075),
           UINT16_MAX,
           UINT16_MAX,
           UINT16_MAX,
           UINT16_MAX,
      UINT16_C(50997) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    uint16_t r3 = simde_vqrshrns_n_u32(test_vec[i].a, 3);
    uint16_t r6 = simde_vqrshrns_n_u32(test_vec[i].a, 6);
    uint16_t r10 = simde_vqrshrns_n_u32(test_vec[i].a, 10);
    uint16_t r13 = simde_vqrshrns_n_u32(test_vec[i].a, 13);
    uint16_t r16 = simde_vqrshrns_n_u32(test_vec[i].a, 16);

    simde_assert_equal_u16(r3, test_vec[i].r3);
    simde_assert_equal_u16(r6, test_vec[i].r6);
    simde_assert_equal_u16(r10, test_vec[i].r10);
    simde_assert_equal_u16(r13, test_vec[i].r13);
    simde_assert_equal_u16(r16, test_vec[i].r16);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    uint32_t a = simde_test_codegen_random_u32();

    uint16_t r3 = simde_vqrshrns_n_u32(a, 3);
    uint16_t r6 = simde_vqrshrns_n_u32(a, 6);
    uint16_t r13 = simde_vqrshrns_n_u32(a, 13);
    uint16_t r10 = simde_vqrshrns_n_u32(a, 10);
    uint16_t r16 = simde_vqrshrns_n_u32(a, 16);

    simde_test_codegen_write_u32(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_u16(2, r3, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_u16(2, r6, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_u16(2, r10, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_u16(2, r13, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_u16(2, r16, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vqrshrnd_n_s64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int64_t a;
    int32_t r6;
    int32_t r13;
    int32_t r19;
    int32_t r26;
    int32_t r32;
  } test_vec[] = {
    {  INT64_C( 6927553365441106267),
                   INT32_MAX,
                   INT32_MAX,
                   INT32_MAX,
                   INT32_MAX,
       INT32_C(  1612946709) },
    { -INT64_C( 8829126342669598221),
                   INT32_MIN,
                   INT32_MIN,
                   INT32_MIN,
                   INT32_MIN,
      -INT32_C(  2055691169) },
    {  INT64_C( 8284716732429802677),
                   INT32_MAX,
                   INT32_MAX,
                   INT32_MAX,
                   INT32_MAX,
       INT32_C(  1928935929) },
    {  INT64_C( 3447712035466944575),
                   INT32_MAX,
                   INT32_MAX,
                   INT32_MAX,
                   INT32_MAX,
       INT32_C(   802733012) },
    {  INT64_C( 1585926924561319309),
                   INT32_MAX,
                   INT32_MAX,
                   INT32_MAX,
                   INT32_MAX,
       INT32_C(   369252387) },
    {  INT64_C( 9132537847462634969),
                   INT32_MAX,
                   INT32_MAX,
                   INT32_MAX,
                   INT32_MAX,
       INT32_C(  2126334665) },
    {  INT64_C( 7805235330517038054),
                   INT32_MAX,
                   INT32_MAX,
                   INT32_MAX,
                   INT32_MAX,
       INT32_C(  1817297966) },
    {  INT64_C( 8171956226922785125),
                   INT32_MAX,
                   INT32_MAX,
                   INT32_MAX,
                   INT32_MAX,
       INT32_C(  1902681828) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    int32_t r6 = simde_vqrshrnd_n_s64(test_vec[i].a, 6);
    int32_t r13 = simde_vqrshrnd_n_s64(test_vec[i].a, 13);
    int32_t r19 = simde_vqrshrnd_n_s64(test_vec[i].a, 19);
    int32_t r26 = simde_vqrshrnd_n_s64(test_vec[i].a, 26);
    int32_t r32 = simde_vqrshrnd_n_s64(test_vec[i].a, 32);

    simde_assert_equal_i64(r6, test_vec[i].r6);
    simde_assert_equal_i32(r19, test_vec[i].r19);
    simde_assert_equal_i32(r13, test_vec[i].r13);
    simde_assert_equal_i32(r26, test_vec[i].r26);
    simde_assert_equal_i32(r32, test_vec[i].r32);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    int64_t a = simde_test_codegen_random_i64();

    int32_t r6 = simde_vqrshrnd_n_s64(a, 6);
    int32_t r13 = simde_vqrshrnd_n_s64(a, 13);
    int32_t r19 = simde_vqrshrnd_n_s64(a, 19);
    int32_t r26 = simde_vqrshrnd_n_s64(a, 26);
    int32_t r32 = simde_vqrshrnd_n_s64(a, 32);

    simde_test_codegen_write_i64(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_i32(2, r6, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, r13, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, r19, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, r26, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, r32, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vqrshrnd_n_u64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint64_t a;
    uint32_t r6;
    uint32_t r13;
    uint32_t r19;
    uint32_t r26;
    uint32_t r32;
  } test_vec[] = {
    { UINT64_C(17612460806734474661),
                UINT32_MAX,
                UINT32_MAX,
                UINT32_MAX,
                UINT32_MAX,
      UINT32_C(4100720586) },
    { UINT64_C(11430663175853402152),
                UINT32_MAX,
                UINT32_MAX,
                UINT32_MAX,
                UINT32_MAX,
      UINT32_C(2661408665) },
    { UINT64_C( 3784893571764207616),
                UINT32_MAX,
                UINT32_MAX,
                UINT32_MAX,
                UINT32_MAX,
      UINT32_C( 881239206) },
    { UINT64_C( 7027636030523933078),
                UINT32_MAX,
                UINT32_MAX,
                UINT32_MAX,
                UINT32_MAX,
      UINT32_C(1636249020) },
    { UINT64_C(11229940573367921690),
                UINT32_MAX,
                UINT32_MAX,
                UINT32_MAX,
                UINT32_MAX,
      UINT32_C(2614674292) },
    { UINT64_C(10980299915174525227),
                UINT32_MAX,
                UINT32_MAX,
                UINT32_MAX,
                UINT32_MAX,
      UINT32_C(2556550297) },
    { UINT64_C( 5113722687328422684),
                UINT32_MAX,
                UINT32_MAX,
                UINT32_MAX,
                UINT32_MAX,
      UINT32_C(1190631345) },
    { UINT64_C( 6572484969399063576),
                UINT32_MAX,
                UINT32_MAX,
                UINT32_MAX,
                UINT32_MAX,
      UINT32_C(1530275906) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    uint32_t r6 = simde_vqrshrnd_n_u64(test_vec[i].a, 6);
    uint32_t r13 = simde_vqrshrnd_n_u64(test_vec[i].a, 13);
    uint32_t r19 = simde_vqrshrnd_n_u64(test_vec[i].a, 19);
    uint32_t r26 = simde_vqrshrnd_n_u64(test_vec[i].a, 26);
    uint32_t r32 = simde_vqrshrnd_n_u64(test_vec[i].a, 32);

    simde_assert_equal_u64(r6, test_vec[i].r6);
    simde_assert_equal_u32(r19, test_vec[i].r19);
    simde_assert_equal_u32(r13, test_vec[i].r13);
    simde_assert_equal_u32(r26, test_vec[i].r26);
    simde_assert_equal_u32(r32, test_vec[i].r32);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    uint64_t a = simde_test_codegen_random_u64();

    uint32_t r6 = simde_vqrshrnd_n_u64(a, 6);
    uint32_t r13 = simde_vqrshrnd_n_u64(a, 13);
    uint32_t r19 = simde_vqrshrnd_n_u64(a, 19);
    uint32_t r26 = simde_vqrshrnd_n_u64(a, 26);
    uint32_t r32 = simde_vqrshrnd_n_u64(a, 32);

    simde_test_codegen_write_u64(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_u32(2, r6, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_u32(2, r13, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_u32(2, r19, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_u32(2, r26, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_u32(2, r32, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(vqrshrn_n_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vqrshrn_n_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vqrshrn_n_s64)
SIMDE_TEST_FUNC_LIST_ENTRY(vqrshrn_n_u16)
SIMDE_TEST_FUNC_LIST_ENTRY(vqrshrn_n_u32)
SIMDE_TEST_FUNC_LIST_ENTRY(vqrshrn_n_u64)
SIMDE_TEST_FUNC_LIST_ENTRY(vqrshrns_n_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vqrshrns_n_u32)
SIMDE_TEST_FUNC_LIST_ENTRY(vqrshrnd_n_s64)
SIMDE_TEST_FUNC_LIST_ENTRY(vqrshrnd_n_u64)
SIMDE_TEST_FUNC_LIST_END

#include "test-neon-footer.h"
