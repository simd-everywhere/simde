#define SIMDE_TEST_ARM_NEON_INSN qmovun_high

#include "test-neon.h"
#include "../../../simde/arm/neon/and.h"
#include "../../../simde/arm/neon/dup_n.h"
#include "../../../simde/arm/neon/neg.h"
#include "../../../simde/arm/neon/qmovun_high.h"
#include "../../../simde/arm/neon/shl.h"


static int
test_simde_vqmovun_high_s16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint8_t r[8];
    int16_t a[8];
    uint8_t r_[16];
  } test_vec[] = {
    { {  UINT8_C(    70),  UINT8_C(   233),  UINT8_C(    97),  UINT8_C(   131),
         UINT8_C(    65),  UINT8_C(    89),  UINT8_C(    31),  UINT8_C(     3) },
      { -INT16_C(  1375), -INT16_C( 24891),  INT16_C( 20043), -INT16_C( 30999),
        -INT16_C( 30875),  INT16_C(  2365), -INT16_C(  4962), -INT16_C(  3962) },
      {  UINT8_C(    70),  UINT8_C(   233),  UINT8_C(    97),  UINT8_C(   131),
         UINT8_C(    65),  UINT8_C(    89),  UINT8_C(    31),  UINT8_C(     3),
         UINT8_C(     0),  UINT8_C(     0),        UINT8_MAX,  UINT8_C(     0),
         UINT8_C(     0),        UINT8_MAX,  UINT8_C(     0),  UINT8_C(     0) } },
    { {  UINT8_C(   197),  UINT8_C(    34),  UINT8_C(    11),  UINT8_C(   159),
         UINT8_C(    17),  UINT8_C(   174),  UINT8_C(    60),  UINT8_C(    99) },
      { -INT16_C( 27744), -INT16_C( 30747),  INT16_C( 20084), -INT16_C(  6335),
         INT16_C(  1366), -INT16_C( 25387),  INT16_C(  9596),  INT16_C( 22244) },
      {  UINT8_C(   197),  UINT8_C(    34),  UINT8_C(    11),  UINT8_C(   159),
         UINT8_C(    17),  UINT8_C(   174),  UINT8_C(    60),  UINT8_C(    99),
         UINT8_C(     0),  UINT8_C(     0),        UINT8_MAX,  UINT8_C(     0),
               UINT8_MAX,  UINT8_C(     0),        UINT8_MAX,        UINT8_MAX } },
    { {  UINT8_C(   207),  UINT8_C(    82),  UINT8_C(   228),  UINT8_C(   132),
         UINT8_C(   100),  UINT8_C(   172),  UINT8_C(   198),  UINT8_C(   103) },
      { -INT16_C( 30077), -INT16_C(  6590),  INT16_C( 22183),  INT16_C( 24951),
        -INT16_C( 15849),  INT16_C( 31257), -INT16_C( 10430),  INT16_C(  4141) },
      {  UINT8_C(   207),  UINT8_C(    82),  UINT8_C(   228),  UINT8_C(   132),
         UINT8_C(   100),  UINT8_C(   172),  UINT8_C(   198),  UINT8_C(   103),
         UINT8_C(     0),  UINT8_C(     0),        UINT8_MAX,        UINT8_MAX,
         UINT8_C(     0),        UINT8_MAX,  UINT8_C(     0),        UINT8_MAX } },
    { {  UINT8_C(   121),  UINT8_C(    38),  UINT8_C(   138),  UINT8_C(   189),
         UINT8_C(   164),  UINT8_C(   107),  UINT8_C(    44),  UINT8_C(    88) },
      {  INT16_C( 13456), -INT16_C(   170), -INT16_C( 10331),  INT16_C( 13801),
        -INT16_C( 19413), -INT16_C( 12123),  INT16_C(  3721),  INT16_C( 30427) },
      {  UINT8_C(   121),  UINT8_C(    38),  UINT8_C(   138),  UINT8_C(   189),
         UINT8_C(   164),  UINT8_C(   107),  UINT8_C(    44),  UINT8_C(    88),
               UINT8_MAX,  UINT8_C(     0),  UINT8_C(     0),        UINT8_MAX,
         UINT8_C(     0),  UINT8_C(     0),        UINT8_MAX,        UINT8_MAX } },
    { {  UINT8_C(     9),  UINT8_C(   224),  UINT8_C(    15),  UINT8_C(    29),
         UINT8_C(   101),  UINT8_C(    78),  UINT8_C(    46),  UINT8_C(   181) },
      {  INT16_C( 21533),  INT16_C( 21485), -INT16_C( 12034),  INT16_C(  5941),
         INT16_C(  5193), -INT16_C( 21529), -INT16_C( 18380), -INT16_C( 21392) },
      {  UINT8_C(     9),  UINT8_C(   224),  UINT8_C(    15),  UINT8_C(    29),
         UINT8_C(   101),  UINT8_C(    78),  UINT8_C(    46),  UINT8_C(   181),
               UINT8_MAX,        UINT8_MAX,  UINT8_C(     0),        UINT8_MAX,
               UINT8_MAX,  UINT8_C(     0),  UINT8_C(     0),  UINT8_C(     0) } },
    { {  UINT8_C(    51),  UINT8_C(    33),  UINT8_C(   177),  UINT8_C(    36),
         UINT8_C(    47),  UINT8_C(   251),  UINT8_C(   112),  UINT8_C(   250) },
      { -INT16_C(  5062),  INT16_C( 17207),  INT16_C( 20772),  INT16_C( 26563),
         INT16_C(  1992),  INT16_C( 26471), -INT16_C( 26519), -INT16_C( 18185) },
      {  UINT8_C(    51),  UINT8_C(    33),  UINT8_C(   177),  UINT8_C(    36),
         UINT8_C(    47),  UINT8_C(   251),  UINT8_C(   112),  UINT8_C(   250),
         UINT8_C(     0),        UINT8_MAX,        UINT8_MAX,        UINT8_MAX,
               UINT8_MAX,        UINT8_MAX,  UINT8_C(     0),  UINT8_C(     0) } },
    { {  UINT8_C(   125),  UINT8_C(   190),  UINT8_C(    40),  UINT8_C(    25),
         UINT8_C(   178),  UINT8_C(    20),        UINT8_MAX,  UINT8_C(   118) },
      { -INT16_C( 15910),  INT16_C( 19213), -INT16_C( 16703),  INT16_C( 31393),
         INT16_C(  3462),  INT16_C( 20147), -INT16_C( 28743),  INT16_C(  1967) },
      {  UINT8_C(   125),  UINT8_C(   190),  UINT8_C(    40),  UINT8_C(    25),
         UINT8_C(   178),  UINT8_C(    20),        UINT8_MAX,  UINT8_C(   118),
         UINT8_C(     0),        UINT8_MAX,  UINT8_C(     0),        UINT8_MAX,
               UINT8_MAX,        UINT8_MAX,  UINT8_C(     0),        UINT8_MAX } },
    { {  UINT8_C(    49),  UINT8_C(     1),  UINT8_C(    91),  UINT8_C(    51),
         UINT8_C(   211),  UINT8_C(    47),  UINT8_C(   240),  UINT8_C(    48) },
      { -INT16_C( 15905), -INT16_C( 14679), -INT16_C( 14286),  INT16_C( 15476),
         INT16_C( 30018),  INT16_C( 24404), -INT16_C( 19201),  INT16_C(  2489) },
      {  UINT8_C(    49),  UINT8_C(     1),  UINT8_C(    91),  UINT8_C(    51),
         UINT8_C(   211),  UINT8_C(    47),  UINT8_C(   240),  UINT8_C(    48),
         UINT8_C(     0),  UINT8_C(     0),  UINT8_C(     0),        UINT8_MAX,
               UINT8_MAX,        UINT8_MAX,  UINT8_C(     0),        UINT8_MAX } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint8x8_t r = simde_vld1_u8(test_vec[i].r);
    simde_int16x8_t a = simde_vld1q_s16(test_vec[i].a);
    simde_uint8x16_t r_ = simde_vqmovun_high_s16(r, a);

    simde_test_arm_neon_assert_equal_u8x16(r_, simde_vld1q_u8(test_vec[i].r_));
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint8x8_t r = simde_test_arm_neon_random_u8x8();
    simde_int16x8_t a = simde_test_arm_neon_random_i16x8();
    simde_uint8x16_t r_ = simde_vqmovun_high_s16(r, a);

    simde_test_arm_neon_write_u8x8(2, r, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i16x8(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u8x16(2, r_, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vqmovun_high_s32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint16_t r[4];
    int32_t a[4];
    uint16_t r_[8];
  } test_vec[] = {
    { {  UINT16_C(       15459),  UINT16_C(        4351),  UINT16_C(       12656),  UINT16_C(        6614) },
      { -INT32_C(   182587592),  INT32_C(  1541977638), -INT32_C(  1026787635),  INT32_C(   607942002) },
      {  UINT16_C(       15459),  UINT16_C(        4351),  UINT16_C(       12656),  UINT16_C(        6614),
         UINT16_C(           0),             UINT16_MAX,  UINT16_C(           0),             UINT16_MAX } },
    { {  UINT16_C(       15905),  UINT16_C(       55497),  UINT16_C(       63941),  UINT16_C(       56338) },
      {  INT32_C(   233494632),  INT32_C(   144087000),  INT32_C(  1097601820),  INT32_C(  1458787634) },
      {  UINT16_C(       15905),  UINT16_C(       55497),  UINT16_C(       63941),  UINT16_C(       56338),
                    UINT16_MAX,             UINT16_MAX,             UINT16_MAX,             UINT16_MAX } },
    { {  UINT16_C(       55618),  UINT16_C(       61753),  UINT16_C(        2667),  UINT16_C(        1134) },
      {  INT32_C(   415596866),  INT32_C(   424698450),  INT32_C(   982412422),  INT32_C(  1384414106) },
      {  UINT16_C(       55618),  UINT16_C(       61753),  UINT16_C(        2667),  UINT16_C(        1134),
                    UINT16_MAX,             UINT16_MAX,             UINT16_MAX,             UINT16_MAX } },
    { {  UINT16_C(       15320),  UINT16_C(       43038),  UINT16_C(       40770),  UINT16_C(       17266) },
      { -INT32_C(  1847049081),  INT32_C(  1873582794),  INT32_C(   199115753),  INT32_C(   430737766) },
      {  UINT16_C(       15320),  UINT16_C(       43038),  UINT16_C(       40770),  UINT16_C(       17266),
         UINT16_C(           0),             UINT16_MAX,             UINT16_MAX,             UINT16_MAX } },
    { {  UINT16_C(       23363),  UINT16_C(       17127),  UINT16_C(       64193),  UINT16_C(       36380) },
      {  INT32_C(    62535925), -INT32_C(   922017641), -INT32_C(  1896375721),  INT32_C(  1752944573) },
      {  UINT16_C(       23363),  UINT16_C(       17127),  UINT16_C(       64193),  UINT16_C(       36380),
                    UINT16_MAX,  UINT16_C(           0),  UINT16_C(           0),             UINT16_MAX } },
    { {  UINT16_C(        2442),  UINT16_C(       59479),  UINT16_C(       55529),  UINT16_C(        3387) },
      { -INT32_C(  1383259155),  INT32_C(  2005807990),  INT32_C(   474859984),  INT32_C(   255382651) },
      {  UINT16_C(        2442),  UINT16_C(       59479),  UINT16_C(       55529),  UINT16_C(        3387),
         UINT16_C(           0),             UINT16_MAX,             UINT16_MAX,             UINT16_MAX } },
    { {  UINT16_C(       25034),  UINT16_C(       11981),  UINT16_C(       18099),  UINT16_C(       21153) },
      {  INT32_C(   867173010),  INT32_C(   895624384), -INT32_C(   476058435),  INT32_C(  1784197246) },
      {  UINT16_C(       25034),  UINT16_C(       11981),  UINT16_C(       18099),  UINT16_C(       21153),
                    UINT16_MAX,             UINT16_MAX,  UINT16_C(           0),             UINT16_MAX } },
    { {  UINT16_C(        2409),  UINT16_C(       26246),  UINT16_C(       36596),  UINT16_C(       13078) },
      {  INT32_C(    63793175),  INT32_C(  2114008373), -INT32_C(   716757662),  INT32_C(   315856431) },
      {  UINT16_C(        2409),  UINT16_C(       26246),  UINT16_C(       36596),  UINT16_C(       13078),
                    UINT16_MAX,             UINT16_MAX,  UINT16_C(           0),             UINT16_MAX } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint16x4_t r = simde_vld1_u16(test_vec[i].r);
    simde_int32x4_t a = simde_vld1q_s32(test_vec[i].a);
    simde_uint16x8_t r_ = simde_vqmovun_high_s32(r, a);

    simde_test_arm_neon_assert_equal_u16x8(r_, simde_vld1q_u16(test_vec[i].r_));
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint16x4_t r = simde_test_arm_neon_random_u16x4();
    simde_int32x4_t a = simde_test_arm_neon_random_i32x4();
    simde_uint16x8_t r_ = simde_vqmovun_high_s32(r, a);

    simde_test_arm_neon_write_u16x4(2, r, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i32x4(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u16x8(2, r_, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vqmovun_high_s64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint32_t r[2];
    int64_t a[2];
    uint32_t r_[4];
  } test_vec[] = {
    { {  UINT32_C(          2415092437),  UINT32_C(          3575704709) },
      {  INT64_C( 2911680581077970760), -INT64_C( 6252317630098635365) },
      {  UINT32_C(          2415092437),  UINT32_C(          3575704709),                     UINT32_MAX,  UINT32_C(                   0) } },
    { {  UINT32_C(           361185363),  UINT32_C(          3561844857) },
      {  INT64_C( 3456422891132729761),  INT64_C( 5944392633432056076) },
      {  UINT32_C(           361185363),  UINT32_C(          3561844857),                     UINT32_MAX,                     UINT32_MAX } },
    { {  UINT32_C(          2357604500),  UINT32_C(           158087901) },
      {  INT64_C( 3605910035214013990),  INT64_C( 6332893229733095198) },
      {  UINT32_C(          2357604500),  UINT32_C(           158087901),                     UINT32_MAX,                     UINT32_MAX } },
    { {  UINT32_C(           199250580),  UINT32_C(           736952756) },
      {  INT64_C( 6094478834361115605), -INT64_C( 6436117526249144274) },
      {  UINT32_C(           199250580),  UINT32_C(           736952756),                     UINT32_MAX,  UINT32_C(                   0) } },
    { {  UINT32_C(          1045100459),  UINT32_C(          3740520697) },
      { -INT64_C( 6088890537249912848), -INT64_C( 5092729419029814959) },
      {  UINT32_C(          1045100459),  UINT32_C(          3740520697),  UINT32_C(                   0),  UINT32_C(                   0) } },
    { {  UINT32_C(          1381721982),  UINT32_C(          3324835420) },
      { -INT64_C( 2977051630141059168),  INT64_C( 1844939807592380975) },
      {  UINT32_C(          1381721982),  UINT32_C(          3324835420),  UINT32_C(                   0),                     UINT32_MAX } },
    { {  UINT32_C(          3200178230),  UINT32_C(           594850118) },
      { -INT64_C( 4162916676129157332),  INT64_C( 3453539636068050539) },
      {  UINT32_C(          3200178230),  UINT32_C(           594850118),  UINT32_C(                   0),                     UINT32_MAX } },
    { {  UINT32_C(          4161023475),  UINT32_C(           528806468) },
      { -INT64_C( 9166699490801161822), -INT64_C( 3274626501092316433) },
      {  UINT32_C(          4161023475),  UINT32_C(           528806468),  UINT32_C(                   0),  UINT32_C(                   0) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint32x2_t r = simde_vld1_u32(test_vec[i].r);
    simde_int64x2_t a = simde_vld1q_s64(test_vec[i].a);
    simde_uint32x4_t r_ = simde_vqmovun_high_s64(r, a);

    simde_test_arm_neon_assert_equal_u32x4(r_, simde_vld1q_u32(test_vec[i].r_));
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint32x2_t r = simde_test_arm_neon_random_u32x2();
    simde_int64x2_t a = simde_test_arm_neon_random_i64x2();
    simde_uint32x4_t r_ = simde_vqmovun_high_s64(r, a);

    simde_test_arm_neon_write_u32x2(2, r, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i64x2(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x4(2, r_, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(vqmovun_high_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vqmovun_high_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vqmovun_high_s64)
SIMDE_TEST_FUNC_LIST_END

#include "test-neon-footer.h"
