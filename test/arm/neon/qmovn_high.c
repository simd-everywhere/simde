#define SIMDE_TEST_ARM_NEON_INSN qmovn_high

#include "test-neon.h"
#include "../../../simde/arm/neon/and.h"
#include "../../../simde/arm/neon/dup_n.h"
#include "../../../simde/arm/neon/neg.h"
#include "../../../simde/arm/neon/qmovn_high.h"
#include "../../../simde/arm/neon/shl.h"


static int
test_simde_vqmovn_high_s16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int8_t r[8];
    int16_t a[8];
    int8_t r_[16];
  } test_vec[] = {
    { { -INT8_C(  41),  INT8_C( 124),  INT8_C(  42), -INT8_C( 105), -INT8_C(  24),  INT8_C(  41), -INT8_C(  16), -INT8_C(  76) },
      { -INT16_C(   171), -INT16_C(     1), -INT16_C(   586),  INT16_C(     1), -INT16_C(    55),  INT16_C(     2), -INT16_C(    16), -INT16_C(    12) },
      { -INT8_C(  41),  INT8_C( 124),  INT8_C(  42), -INT8_C( 105), -INT8_C(  24),  INT8_C(  41), -INT8_C(  16), -INT8_C(  76),
             INT8_MIN, -INT8_C(   1),      INT8_MIN,  INT8_C(   1), -INT8_C(  55),  INT8_C(   2), -INT8_C(  16), -INT8_C(  12) } },
    { { -INT8_C(  50), -INT8_C( 109),  INT8_C(  47), -INT8_C(  30),  INT8_C(  64),  INT8_C(  29), -INT8_C(  77),  INT8_C(  10) },
      { -INT16_C(     2), -INT16_C( 10467),  INT16_C(     1),  INT16_C( 13137), -INT16_C(  8144),  INT16_C(    24), -INT16_C(  3545), -INT16_C(  1011) },
      { -INT8_C(  50), -INT8_C( 109),  INT8_C(  47), -INT8_C(  30),  INT8_C(  64),  INT8_C(  29), -INT8_C(  77),  INT8_C(  10),
        -INT8_C(   2),      INT8_MIN,  INT8_C(   1),      INT8_MAX,      INT8_MIN,  INT8_C(  24),      INT8_MIN,      INT8_MIN } },
    { {  INT8_C(  57), -INT8_C( 114),  INT8_C(  53), -INT8_C(  58), -INT8_C(  21), -INT8_C(  75), -INT8_C(  48),  INT8_C(  29) },
      { -INT16_C(     6),  INT16_C(  3281),  INT16_C(  1353), -INT16_C(    88),  INT16_C(   807), -INT16_C(   807),  INT16_C( 13580), -INT16_C(     4) },
      {  INT8_C(  57), -INT8_C( 114),  INT8_C(  53), -INT8_C(  58), -INT8_C(  21), -INT8_C(  75), -INT8_C(  48),  INT8_C(  29),
        -INT8_C(   6),      INT8_MAX,      INT8_MAX, -INT8_C(  88),      INT8_MAX,      INT8_MIN,      INT8_MAX, -INT8_C(   4) } },
    { {  INT8_C(  48), -INT8_C(  99), -INT8_C(  78),  INT8_C(  84),  INT8_C(  32), -INT8_C(  54),  INT8_C( 106),  INT8_C(  69) },
      {  INT16_C(     6), -INT16_C(     1),  INT16_C(   381),  INT16_C(   296),  INT16_C(     0), -INT16_C(     2), -INT16_C(     4), -INT16_C(     1) },
      {  INT8_C(  48), -INT8_C(  99), -INT8_C(  78),  INT8_C(  84),  INT8_C(  32), -INT8_C(  54),  INT8_C( 106),  INT8_C(  69),
         INT8_C(   6), -INT8_C(   1),      INT8_MAX,      INT8_MAX,  INT8_C(   0), -INT8_C(   2), -INT8_C(   4), -INT8_C(   1) } },
    { { -INT8_C(  17), -INT8_C(  23), -INT8_C( 122),  INT8_C(  51),  INT8_C( 117),  INT8_C( 103),  INT8_C(  13), -INT8_C(  44) },
      {  INT16_C( 12294), -INT16_C(     1),  INT16_C(   161), -INT16_C(     5),  INT16_C(  1043), -INT16_C(  1295),  INT16_C(     0),  INT16_C(    28) },
      { -INT8_C(  17), -INT8_C(  23), -INT8_C( 122),  INT8_C(  51),  INT8_C( 117),  INT8_C( 103),  INT8_C(  13), -INT8_C(  44),
             INT8_MAX, -INT8_C(   1),      INT8_MAX, -INT8_C(   5),      INT8_MAX,      INT8_MIN,  INT8_C(   0),  INT8_C(  28) } },
    { {  INT8_C(  58),  INT8_C(  82),  INT8_C(  69), -INT8_C( 111), -INT8_C(  18), -INT8_C(  79), -INT8_C( 118), -INT8_C(  13) },
      { -INT16_C(    37), -INT16_C(    16),  INT16_C(  5045),  INT16_C(     1),  INT16_C(  2068), -INT16_C(     8),  INT16_C(  2812),  INT16_C(  1872) },
      {  INT8_C(  58),  INT8_C(  82),  INT8_C(  69), -INT8_C( 111), -INT8_C(  18), -INT8_C(  79), -INT8_C( 118), -INT8_C(  13),
        -INT8_C(  37), -INT8_C(  16),      INT8_MAX,  INT8_C(   1),      INT8_MAX, -INT8_C(   8),      INT8_MAX,      INT8_MAX } },
    { {  INT8_C( 106),  INT8_C(  76),  INT8_C(  50), -INT8_C(  84), -INT8_C(  17), -INT8_C( 115), -INT8_C(  11), -INT8_C(  61) },
      {  INT16_C(     0), -INT16_C(    30), -INT16_C(    12), -INT16_C(     1),  INT16_C( 24117),  INT16_C(   586), -INT16_C(   195),  INT16_C(    95) },
      {  INT8_C( 106),  INT8_C(  76),  INT8_C(  50), -INT8_C(  84), -INT8_C(  17), -INT8_C( 115), -INT8_C(  11), -INT8_C(  61),
         INT8_C(   0), -INT8_C(  30), -INT8_C(  12), -INT8_C(   1),      INT8_MAX,      INT8_MAX,      INT8_MIN,  INT8_C(  95) } },
    { { -INT8_C(  81),  INT8_C( 110),  INT8_C(  13), -INT8_C( 104), -INT8_C( 103),  INT8_C(  43), -INT8_C( 102),  INT8_C( 121) },
      { -INT16_C(  1751), -INT16_C(     1), -INT16_C(     3), -INT16_C(  1039), -INT16_C(    13), -INT16_C(     2),  INT16_C(   600), -INT16_C(    19) },
      { -INT8_C(  81),  INT8_C( 110),  INT8_C(  13), -INT8_C( 104), -INT8_C( 103),  INT8_C(  43), -INT8_C( 102),  INT8_C( 121),
             INT8_MIN, -INT8_C(   1), -INT8_C(   3),      INT8_MIN, -INT8_C(  13), -INT8_C(   2),      INT8_MAX, -INT8_C(  19) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int8x8_t r = simde_vld1_s8(test_vec[i].r);
    simde_int16x8_t a = simde_vld1q_s16(test_vec[i].a);
    simde_int8x16_t r_ = simde_vqmovn_high_s16(r, a);

    simde_test_arm_neon_assert_equal_i8x16(r_, simde_vld1q_s8(test_vec[i].r_));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int8x8_t r = simde_test_arm_neon_random_i8x8();
    simde_int16x8_t s = simde_vandq_s16(simde_test_arm_neon_random_i16x8(), simde_vdupq_n_s16(15));
    simde_int16x8_t a = simde_vshlq_s16(simde_test_arm_neon_random_i16x8(), simde_vnegq_s16(s));
    simde_int8x16_t r_ = simde_vqmovn_high_s16(r, a);

    simde_test_arm_neon_write_i8x8(2, r, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i16x8(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i8x16(2, r_, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vqmovn_high_s32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int16_t r[4];
    int32_t a[4];
    int16_t r_[8];
  } test_vec[] = {
    { { -INT16_C( 15725), -INT16_C( 13295),  INT16_C(  5444),  INT16_C( 13069) },
      {  INT32_C(           0), -INT32_C(        2066), -INT32_C(          11), -INT32_C(          16) },
      { -INT16_C( 15725), -INT16_C( 13295),  INT16_C(  5444),  INT16_C( 13069),  INT16_C(     0), -INT16_C(  2066), -INT16_C(    11), -INT16_C(    16) } },
    { {  INT16_C(  9425),  INT16_C( 17262), -INT16_C( 25798),  INT16_C( 29641) },
      { -INT32_C(        1524), -INT32_C(           1),  INT32_C(     4385743),  INT32_C(          63) },
      {  INT16_C(  9425),  INT16_C( 17262), -INT16_C( 25798),  INT16_C( 29641), -INT16_C(  1524), -INT16_C(     1),       INT16_MAX,  INT16_C(    63) } },
    { { -INT16_C( 28066), -INT16_C( 17139), -INT16_C( 23754),  INT16_C( 32468) },
      { -INT32_C(          15),  INT32_C(           0),  INT32_C(   532089106), -INT32_C(         513) },
      { -INT16_C( 28066), -INT16_C( 17139), -INT16_C( 23754),  INT16_C( 32468), -INT16_C(    15),  INT16_C(     0),       INT16_MAX, -INT16_C(   513) } },
    { {  INT16_C(  4028), -INT16_C( 17938), -INT16_C(  1645),  INT16_C( 13940) },
      {  INT32_C(      372262),  INT32_C(        8026),  INT32_C(           2), -INT32_C(       15418) },
      {  INT16_C(  4028), -INT16_C( 17938), -INT16_C(  1645),  INT16_C( 13940),       INT16_MAX,  INT16_C(  8026),  INT16_C(     2), -INT16_C( 15418) } },
    { {  INT16_C( 15621), -INT16_C( 27897),  INT16_C( 17166), -INT16_C(  5202) },
      { -INT32_C(           1),  INT32_C(      370136),  INT32_C(    98573054), -INT32_C(          15) },
      {  INT16_C( 15621), -INT16_C( 27897),  INT16_C( 17166), -INT16_C(  5202), -INT16_C(     1),       INT16_MAX,       INT16_MAX, -INT16_C(    15) } },
    { { -INT16_C( 32465),  INT16_C(  6761),  INT16_C(  5320), -INT16_C( 21933) },
      {  INT32_C(         221), -INT32_C(     2648018), -INT32_C(           3),  INT32_C(           1) },
      { -INT16_C( 32465),  INT16_C(  6761),  INT16_C(  5320), -INT16_C( 21933),  INT16_C(   221),       INT16_MIN, -INT16_C(     3),  INT16_C(     1) } },
    { {  INT16_C( 10176), -INT16_C( 30030),  INT16_C(  6961),  INT16_C( 11837) },
      { -INT32_C(         114), -INT32_C(   933690393),  INT32_C(          47),  INT32_C(        3555) },
      {  INT16_C( 10176), -INT16_C( 30030),  INT16_C(  6961),  INT16_C( 11837), -INT16_C(   114),       INT16_MIN,  INT16_C(    47),  INT16_C(  3555) } },
    { { -INT16_C(  7441),  INT16_C(  4172), -INT16_C( 17272),  INT16_C( 16880) },
      {  INT32_C(       10512), -INT32_C(       41434),  INT32_C(         103),  INT32_C(        1131) },
      { -INT16_C(  7441),  INT16_C(  4172), -INT16_C( 17272),  INT16_C( 16880),  INT16_C( 10512),       INT16_MIN,  INT16_C(   103),  INT16_C(  1131) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x4_t r = simde_vld1_s16(test_vec[i].r);
    simde_int32x4_t a = simde_vld1q_s32(test_vec[i].a);
    simde_int16x8_t r_ = simde_vqmovn_high_s32(r, a);

    simde_test_arm_neon_assert_equal_i16x8(r_, simde_vld1q_s16(test_vec[i].r_));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int16x4_t r = simde_test_arm_neon_random_i16x4();
    simde_int32x4_t s = simde_vandq_s32(simde_test_arm_neon_random_i32x4(), simde_vdupq_n_s32(31));
    simde_int32x4_t a = simde_vshlq_s32(simde_test_arm_neon_random_i32x4(), simde_vnegq_s32(s));
    simde_int16x8_t r_ = simde_vqmovn_high_s32(r, a);

    simde_test_arm_neon_write_i16x4(2, r, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i32x4(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i16x8(2, r_, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vqmovn_high_s64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int32_t r[2];
    int64_t a[2];
    int32_t r_[4];
  } test_vec[] = {
    { { -INT32_C(  1906760496),  INT32_C(  1718814463) },
      {  INT64_C(      24815211807137), -INT64_C(                1160) },
      { -INT32_C(  1906760496),  INT32_C(  1718814463),            INT32_MAX, -INT32_C(        1160) } },
    { { -INT32_C(   316764895), -INT32_C(    38613431) },
      { -INT64_C(     145384723163912), -INT64_C(                1094) },
      { -INT32_C(   316764895), -INT32_C(    38613431),            INT32_MIN, -INT32_C(        1094) } },
    { { -INT32_C(   779066945),  INT32_C(  1600804844) },
      {  INT64_C(            10057642), -INT64_C(                1094) },
      { -INT32_C(   779066945),  INT32_C(  1600804844),  INT32_C(    10057642), -INT32_C(        1094) } },
    { {  INT32_C(  1252458329), -INT32_C(  1463815501) },
      {  INT64_C(                  28), -INT64_C(                   2) },
      {  INT32_C(  1252458329), -INT32_C(  1463815501),  INT32_C(          28), -INT32_C(           2) } },
    { { -INT32_C(  1136281637), -INT32_C(  1155525315) },
      { -INT64_C(    5572144560772544), -INT64_C(                   7) },
      { -INT32_C(  1136281637), -INT32_C(  1155525315),            INT32_MIN, -INT32_C(           7) } },
    { {  INT32_C(  1052741768),  INT32_C(  1016459777) },
      {  INT64_C(             8192254),  INT64_C(        779949925665) },
      {  INT32_C(  1052741768),  INT32_C(  1016459777),  INT32_C(     8192254),            INT32_MAX } },
    { {  INT32_C(   349986035), -INT32_C(  1983095886) },
      { -INT64_C(               34635),  INT64_C(    9221390498424859) },
      {  INT32_C(   349986035), -INT32_C(  1983095886), -INT32_C(       34635),            INT32_MAX } },
    { { -INT32_C(  1365712188),  INT32_C(   889823723) },
      {  INT64_C(            24599642), -INT64_C(             9686486) },
      { -INT32_C(  1365712188),  INT32_C(   889823723),  INT32_C(    24599642), -INT32_C(     9686486) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x2_t r = simde_vld1_s32(test_vec[i].r);
    simde_int64x2_t a = simde_vld1q_s64(test_vec[i].a);
    simde_int32x4_t r_ = simde_vqmovn_high_s64(r, a);

    simde_test_arm_neon_assert_equal_i32x4(r_, simde_vld1q_s32(test_vec[i].r_));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int32x2_t r = simde_test_arm_neon_random_i32x2();
    simde_int64x2_t s = simde_vandq_s64(simde_test_arm_neon_random_i64x2(), simde_vdupq_n_s64(63));
    simde_int64x2_t a = simde_vshlq_s64(simde_test_arm_neon_random_i64x2(), simde_vnegq_s64(s));
    simde_int32x4_t r_ = simde_vqmovn_high_s64(r, a);

    simde_test_arm_neon_write_i32x2(2, r, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i64x2(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i32x4(2, r_, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vqmovn_high_u16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint8_t r[8];
    uint16_t a[8];
    uint8_t r_[16];
  } test_vec[] = {
    { { UINT8_C(228), UINT8_C(126), UINT8_C(244), UINT8_C(201), UINT8_C(244), UINT8_C(214), UINT8_C( 11), UINT8_C(240) },
      { UINT16_C( 1088), UINT16_C(   60), UINT16_C(   29), UINT16_C(   99), UINT16_C(  603), UINT16_C( 6179), UINT16_C( 1233), UINT16_C(  201) },
      { UINT8_C(228), UINT8_C(126), UINT8_C(244), UINT8_C(201), UINT8_C(244), UINT8_C(214), UINT8_C( 11), UINT8_C(240),
           UINT8_MAX, UINT8_C( 60), UINT8_C( 29), UINT8_C( 99),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(201) } },
    { { UINT8_C( 43), UINT8_C( 72), UINT8_C(155), UINT8_C(214), UINT8_C(248), UINT8_C( 84), UINT8_C(251), UINT8_C(189) },
      { UINT16_C(    4), UINT16_C(13913), UINT16_C(  361), UINT16_C(    8), UINT16_C(   10), UINT16_C( 3933), UINT16_C(  437), UINT16_C( 1931) },
      { UINT8_C( 43), UINT8_C( 72), UINT8_C(155), UINT8_C(214), UINT8_C(248), UINT8_C( 84), UINT8_C(251), UINT8_C(189),
        UINT8_C(  4),    UINT8_MAX,    UINT8_MAX, UINT8_C(  8), UINT8_C( 10),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX } },
    { { UINT8_C(184), UINT8_C( 20), UINT8_C(233), UINT8_C( 79), UINT8_C( 28), UINT8_C(193), UINT8_C( 39), UINT8_C( 40) },
      { UINT16_C(   26), UINT16_C(  928), UINT16_C(  194), UINT16_C(  401), UINT16_C(    2), UINT16_C(  121), UINT16_C(    3), UINT16_C( 3779) },
      { UINT8_C(184), UINT8_C( 20), UINT8_C(233), UINT8_C( 79), UINT8_C( 28), UINT8_C(193), UINT8_C( 39), UINT8_C( 40),
        UINT8_C( 26),    UINT8_MAX, UINT8_C(194),    UINT8_MAX, UINT8_C(  2), UINT8_C(121), UINT8_C(  3),    UINT8_MAX } },
    { { UINT8_C( 23), UINT8_C( 49), UINT8_C(121), UINT8_C(191), UINT8_C(252), UINT8_C(127), UINT8_C( 30), UINT8_C(  9) },
      { UINT16_C(   62), UINT16_C(  635), UINT16_C(   13), UINT16_C( 3571), UINT16_C(    5), UINT16_C(  919), UINT16_C(  310), UINT16_C(   31) },
      { UINT8_C( 23), UINT8_C( 49), UINT8_C(121), UINT8_C(191), UINT8_C(252), UINT8_C(127), UINT8_C( 30), UINT8_C(  9),
        UINT8_C( 62),    UINT8_MAX, UINT8_C( 13),    UINT8_MAX, UINT8_C(  5),    UINT8_MAX,    UINT8_MAX, UINT8_C( 31) } },
    { { UINT8_C(164), UINT8_C(  5), UINT8_C(134), UINT8_C( 65), UINT8_C(237), UINT8_C(169), UINT8_C(202), UINT8_C(167) },
      { UINT16_C(    2), UINT16_C(    4), UINT16_C(    2), UINT16_C(    0), UINT16_C( 1291), UINT16_C(10175), UINT16_C(   72), UINT16_C(    1) },
      { UINT8_C(164), UINT8_C(  5), UINT8_C(134), UINT8_C( 65), UINT8_C(237), UINT8_C(169), UINT8_C(202), UINT8_C(167),
        UINT8_C(  2), UINT8_C(  4), UINT8_C(  2), UINT8_C(  0),    UINT8_MAX,    UINT8_MAX, UINT8_C( 72), UINT8_C(  1) } },
    { { UINT8_C(131), UINT8_C(  4), UINT8_C(251), UINT8_C(145), UINT8_C(220), UINT8_C(154), UINT8_C(186), UINT8_C( 49) },
      { UINT16_C(   77), UINT16_C(    2), UINT16_C(   49), UINT16_C(  822), UINT16_C(  399), UINT16_C(   10), UINT16_C(    5), UINT16_C(    5) },
      { UINT8_C(131), UINT8_C(  4), UINT8_C(251), UINT8_C(145), UINT8_C(220), UINT8_C(154), UINT8_C(186), UINT8_C( 49),
        UINT8_C( 77), UINT8_C(  2), UINT8_C( 49),    UINT8_MAX,    UINT8_MAX, UINT8_C( 10), UINT8_C(  5), UINT8_C(  5) } },
    { { UINT8_C(189), UINT8_C(182), UINT8_C(140), UINT8_C(183), UINT8_C(177), UINT8_C(  1), UINT8_C(184), UINT8_C(248) },
      { UINT16_C(13223), UINT16_C(  253), UINT16_C(    3), UINT16_C(    0), UINT16_C(    1), UINT16_C(   82), UINT16_C( 2766), UINT16_C(  337) },
      { UINT8_C(189), UINT8_C(182), UINT8_C(140), UINT8_C(183), UINT8_C(177), UINT8_C(  1), UINT8_C(184), UINT8_C(248),
           UINT8_MAX, UINT8_C(253), UINT8_C(  3), UINT8_C(  0), UINT8_C(  1), UINT8_C( 82),    UINT8_MAX,    UINT8_MAX } },
    { { UINT8_C(  1), UINT8_C(117), UINT8_C(136), UINT8_C( 13), UINT8_C(105), UINT8_C(231), UINT8_C(114), UINT8_C(248) },
      { UINT16_C(  772), UINT16_C(    2), UINT16_C(41070), UINT16_C(   55), UINT16_C(15125), UINT16_C(   63), UINT16_C(   14), UINT16_C(    1) },
      { UINT8_C(  1), UINT8_C(117), UINT8_C(136), UINT8_C( 13), UINT8_C(105), UINT8_C(231), UINT8_C(114), UINT8_C(248),
           UINT8_MAX, UINT8_C(  2),    UINT8_MAX, UINT8_C( 55),    UINT8_MAX, UINT8_C( 63), UINT8_C( 14), UINT8_C(  1) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint8x8_t r = simde_vld1_u8(test_vec[i].r);
    simde_uint16x8_t a = simde_vld1q_u16(test_vec[i].a);
    simde_uint8x16_t r_ = simde_vqmovn_high_u16(r, a);

    simde_test_arm_neon_assert_equal_u8x16(r_, simde_vld1q_u8(test_vec[i].r_));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint8x8_t r = simde_test_arm_neon_random_u8x8();
    simde_int16x8_t s = simde_vandq_s16(simde_test_arm_neon_random_i16x8(), simde_vdupq_n_s16(15));
    simde_uint16x8_t a = simde_vshlq_u16(simde_test_arm_neon_random_u16x8(), simde_vnegq_s16(s));
    simde_uint8x16_t r_ = simde_vqmovn_high_u16(r, a);

    simde_test_arm_neon_write_u8x8(2, r, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u16x8(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u8x16(2, r_, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vqmovn_high_u32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint16_t r[4];
    uint32_t a[4];
    uint16_t r_[8];
  } test_vec[] = {
    { { UINT16_C(16687), UINT16_C(10500), UINT16_C( 9731), UINT16_C(45994) },
      { UINT32_C(     13651), UINT32_C(  74952074), UINT32_C(2069626105), UINT32_C(    107346) },
      { UINT16_C(16687), UINT16_C(10500), UINT16_C( 9731), UINT16_C(45994), UINT16_C(13651),      UINT16_MAX,      UINT16_MAX,      UINT16_MAX } },
    { { UINT16_C(13209), UINT16_C(48667), UINT16_C(12327), UINT16_C(51627) },
      { UINT32_C(      7335), UINT32_C(     14346), UINT32_C(        10), UINT32_C( 140622373) },
      { UINT16_C(13209), UINT16_C(48667), UINT16_C(12327), UINT16_C(51627), UINT16_C( 7335), UINT16_C(14346), UINT16_C(   10),      UINT16_MAX } },
    { { UINT16_C( 3311), UINT16_C(48966), UINT16_C(44359), UINT16_C(57878) },
      { UINT32_C( 987656421), UINT32_C(   3677986), UINT32_C( 321929665), UINT32_C( 169339866) },
      { UINT16_C( 3311), UINT16_C(48966), UINT16_C(44359), UINT16_C(57878),      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX } },
    { { UINT16_C( 2842), UINT16_C(32216), UINT16_C(62574), UINT16_C( 4347) },
      { UINT32_C(         0), UINT32_C(       200), UINT32_C(         1), UINT32_C( 161853309) },
      { UINT16_C( 2842), UINT16_C(32216), UINT16_C(62574), UINT16_C( 4347), UINT16_C(    0), UINT16_C(  200), UINT16_C(    1),      UINT16_MAX } },
    { { UINT16_C(32557), UINT16_C(40717), UINT16_C(22859), UINT16_C(35062) },
      { UINT32_C( 160838827), UINT32_C(         9), UINT32_C(        85), UINT32_C(  34130831) },
      { UINT16_C(32557), UINT16_C(40717), UINT16_C(22859), UINT16_C(35062),      UINT16_MAX, UINT16_C(    9), UINT16_C(   85),      UINT16_MAX } },
    { { UINT16_C( 2412), UINT16_C(18216), UINT16_C(63024), UINT16_C(27003) },
      { UINT32_C(         8), UINT32_C(  12926794), UINT32_C(       733), UINT32_C( 472135829) },
      { UINT16_C( 2412), UINT16_C(18216), UINT16_C(63024), UINT16_C(27003), UINT16_C(    8),      UINT16_MAX, UINT16_C(  733),      UINT16_MAX } },
    { { UINT16_C(44161), UINT16_C(41727), UINT16_C(45661), UINT16_C(45857) },
      { UINT32_C(       140), UINT32_C(    101454), UINT32_C( 397677545), UINT32_C(  63146535) },
      { UINT16_C(44161), UINT16_C(41727), UINT16_C(45661), UINT16_C(45857), UINT16_C(  140),      UINT16_MAX,      UINT16_MAX,      UINT16_MAX } },
    { { UINT16_C( 3189), UINT16_C(50251), UINT16_C(18427), UINT16_C(39964) },
      { UINT32_C(     30161), UINT32_C(   8303449), UINT32_C(   1538102), UINT32_C(     69809) },
      { UINT16_C( 3189), UINT16_C(50251), UINT16_C(18427), UINT16_C(39964), UINT16_C(30161),      UINT16_MAX,      UINT16_MAX,      UINT16_MAX } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint16x4_t r = simde_vld1_u16(test_vec[i].r);
    simde_uint32x4_t a = simde_vld1q_u32(test_vec[i].a);
    simde_uint16x8_t r_ = simde_vqmovn_high_u32(r, a);

    simde_test_arm_neon_assert_equal_u16x8(r_, simde_vld1q_u16(test_vec[i].r_));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint16x4_t r = simde_test_arm_neon_random_u16x4();
    simde_int32x4_t s = simde_vandq_s32(simde_test_arm_neon_random_i32x4(), simde_vdupq_n_s32(31));
    simde_uint32x4_t a = simde_vshlq_u32(simde_test_arm_neon_random_u32x4(), simde_vnegq_s32(s));
    simde_uint16x8_t r_ = simde_vqmovn_high_u32(r, a);

    simde_test_arm_neon_write_u16x4(2, r, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u32x4(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u16x8(2, r_, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vqmovn_high_u64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint32_t r[2];
    uint64_t a[2];
    uint32_t r_[4];
  } test_vec[] = {
    { { UINT32_C(2600053184), UINT32_C(3225579596) },
      { UINT64_C(   39493657923431738), UINT64_C(         16872038636) },
      { UINT32_C(2600053184), UINT32_C(3225579596),           UINT32_MAX,           UINT32_MAX } },
    { { UINT32_C(3665814127), UINT32_C(3092249826) },
      { UINT64_C( 1275278610937403067), UINT64_C(                 296) },
      { UINT32_C(3665814127), UINT32_C(3092249826),           UINT32_MAX, UINT32_C(       296) } },
    { { UINT32_C(1321041292), UINT32_C(2955657081) },
      { UINT64_C(               38279), UINT64_C(                 190) },
      { UINT32_C(1321041292), UINT32_C(2955657081), UINT32_C(     38279), UINT32_C(       190) } },
    { { UINT32_C( 932333107), UINT32_C(2115459463) },
      { UINT64_C(                   6), UINT64_C(                   3) },
      { UINT32_C( 932333107), UINT32_C(2115459463), UINT32_C(         6), UINT32_C(         3) } },
    { { UINT32_C(1173992368), UINT32_C( 603532775) },
      { UINT64_C(                 307), UINT64_C( 4129860144000901197) },
      { UINT32_C(1173992368), UINT32_C( 603532775), UINT32_C(       307),           UINT32_MAX } },
    { { UINT32_C( 873684659), UINT32_C(  81502658) },
      { UINT64_C(               20538), UINT64_C(            50037503) },
      { UINT32_C( 873684659), UINT32_C(  81502658), UINT32_C(     20538), UINT32_C(  50037503) } },
    { { UINT32_C(3514062919), UINT32_C(1579501817) },
      { UINT64_C(                   0), UINT64_C(        261667593493) },
      { UINT32_C(3514062919), UINT32_C(1579501817), UINT32_C(         0),           UINT32_MAX } },
    { { UINT32_C( 355163949), UINT32_C(1319326452) },
      { UINT64_C( 1960864181916608585), UINT64_C(         48518210310) },
      { UINT32_C( 355163949), UINT32_C(1319326452),           UINT32_MAX,           UINT32_MAX } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint32x2_t r = simde_vld1_u32(test_vec[i].r);
    simde_uint64x2_t a = simde_vld1q_u64(test_vec[i].a);
    simde_uint32x4_t r_ = simde_vqmovn_high_u64(r, a);

    simde_test_arm_neon_assert_equal_u32x4(r_, simde_vld1q_u32(test_vec[i].r_));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint32x2_t r = simde_test_arm_neon_random_u32x2();
    simde_int64x2_t s = simde_vandq_s64(simde_test_arm_neon_random_i64x2(), simde_vdupq_n_s64(63));
    simde_uint64x2_t a = simde_vshlq_u64(simde_test_arm_neon_random_u64x2(), simde_vnegq_s64(s));
    simde_uint32x4_t r_ = simde_vqmovn_high_u64(r, a);

    simde_test_arm_neon_write_u32x2(2, r, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u64x2(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x4(2, r_, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(vqmovn_high_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vqmovn_high_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vqmovn_high_s64)
SIMDE_TEST_FUNC_LIST_ENTRY(vqmovn_high_u16)
SIMDE_TEST_FUNC_LIST_ENTRY(vqmovn_high_u32)
SIMDE_TEST_FUNC_LIST_ENTRY(vqmovn_high_u64)
SIMDE_TEST_FUNC_LIST_END

#include "test-neon-footer.h"
