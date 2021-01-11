#define SIMDE_TEST_ARM_NEON_INSN qmovn

#include "test-neon.h"
#include "../../../simde/arm/neon/qmovn.h"
#include "../../../simde/arm/neon/and.h"
#include "../../../simde/arm/neon/shl.h"
#include "../../../simde/arm/neon/neg.h"
#include "../../../simde/arm/neon/dup_n.h"

static int
test_simde_vqmovn_s16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int16_t a[8];
    int8_t r[8];
  } test_vec[] = {
    { {  INT16_C(    12),  INT16_C(  2618),  INT16_C(  1578), -INT16_C(  3171),  INT16_C(     0),  INT16_C(  4882), -INT16_C( 13300),  INT16_C(     1) },
      {  INT8_C(  12),      INT8_MAX,      INT8_MAX,      INT8_MIN,  INT8_C(   0),      INT8_MAX,      INT8_MIN,  INT8_C(   1) } },
    { {  INT16_C(   599), -INT16_C(    43), -INT16_C( 27285), -INT16_C(    97), -INT16_C(     3),  INT16_C(     3),  INT16_C(    86), -INT16_C(  2810) },
      {      INT8_MAX, -INT8_C(  43),      INT8_MIN, -INT8_C(  97), -INT8_C(   3),  INT8_C(   3),  INT8_C(  86),      INT8_MIN } },
    { { -INT16_C(    21), -INT16_C(     1),  INT16_C(   201),  INT16_C(    58),  INT16_C(     0),  INT16_C(  2864), -INT16_C(    10), -INT16_C( 32766) },
      { -INT8_C(  21), -INT8_C(   1),      INT8_MAX,  INT8_C(  58),  INT8_C(   0),      INT8_MAX, -INT8_C(  10),      INT8_MIN } },
    { {  INT16_C(   918),  INT16_C(    44), -INT16_C(    93), -INT16_C(  1357),  INT16_C(   623),  INT16_C(     1),  INT16_C(     4),  INT16_C(     1) },
      {      INT8_MAX,  INT8_C(  44), -INT8_C(  93),      INT8_MIN,      INT8_MAX,  INT8_C(   1),  INT8_C(   4),  INT8_C(   1) } },
    { {  INT16_C(   106),  INT16_C(  7840),  INT16_C( 19948), -INT16_C(   618), -INT16_C(    23), -INT16_C(   408), -INT16_C(     1),  INT16_C(  2676) },
      {  INT8_C( 106),      INT8_MAX,      INT8_MAX,      INT8_MIN, -INT8_C(  23),      INT8_MIN, -INT8_C(   1),      INT8_MAX } },
    { {  INT16_C( 10178),  INT16_C( 29083), -INT16_C(     1),  INT16_C(   108),  INT16_C(   179), -INT16_C(   217),  INT16_C(     1),  INT16_C(     0) },
      {      INT8_MAX,      INT8_MAX, -INT8_C(   1),  INT8_C( 108),      INT8_MAX,      INT8_MIN,  INT8_C(   1),  INT8_C(   0) } },
    { {  INT16_C(  4038), -INT16_C(     1),  INT16_C(     0),  INT16_C(     4), -INT16_C(   602), -INT16_C(    63), -INT16_C(     4), -INT16_C(  3598) },
      {      INT8_MAX, -INT8_C(   1),  INT8_C(   0),  INT8_C(   4),      INT8_MIN, -INT8_C(  63), -INT8_C(   4),      INT8_MIN } },
    { { -INT16_C(  1871), -INT16_C(    51),  INT16_C(   209),  INT16_C(    23),  INT16_C(   118), -INT16_C(     4),  INT16_C(   168), -INT16_C(    40) },
      {      INT8_MIN, -INT8_C(  51),      INT8_MAX,  INT8_C(  23),  INT8_C( 118), -INT8_C(   4),      INT8_MAX, -INT8_C(  40) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x8_t a = simde_vld1q_s16(test_vec[i].a);
    simde_int8x8_t r = simde_vqmovn_s16(a);

    simde_test_arm_neon_assert_equal_i8x8(r, simde_vld1_s8(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int16x8_t s = simde_vandq_s16(simde_test_arm_neon_random_i16x8(), simde_vdupq_n_s16(15));
    simde_int16x8_t a = simde_vshlq_s16(simde_test_arm_neon_random_i16x8(), simde_vnegq_s16(s));
    simde_int8x8_t r = simde_vqmovn_s16(a);

    simde_test_arm_neon_write_i16x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i8x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vqmovn_s32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int32_t a[4];
    int16_t r[4];
  } test_vec[] = {
    { { -INT32_C(         313),  INT32_C(   228909576), -INT32_C(           4), -INT32_C(       19412) },
      { -INT16_C(   313),       INT16_MAX, -INT16_C(     4), -INT16_C( 19412) } },
    { {  INT32_C(       67996),  INT32_C(          67), -INT32_C(        6652),  INT32_C(      395687) },
      {       INT16_MAX,  INT16_C(    67), -INT16_C(  6652),       INT16_MAX } },
    { { -INT32_C(         895),  INT32_C(   752146193),  INT32_C(          37), -INT32_C(     3293944) },
      { -INT16_C(   895),       INT16_MAX,  INT16_C(    37),       INT16_MIN } },
    { {  INT32_C(     1375968), -INT32_C(    16384195), -INT32_C(      572655),  INT32_C(   131998101) },
      {       INT16_MAX,       INT16_MIN,       INT16_MIN,       INT16_MAX } },
    { { -INT32_C(   409962415),  INT32_C(      211718),  INT32_C(          90), -INT32_C(      436309) },
      {       INT16_MIN,       INT16_MAX,  INT16_C(    90),       INT16_MIN } },
    { {  INT32_C(           0),  INT32_C(     3784027),  INT32_C(        1395),  INT32_C(        5674) },
      {  INT16_C(     0),       INT16_MAX,  INT16_C(  1395),  INT16_C(  5674) } },
    { {  INT32_C(       43298), -INT32_C(       37946), -INT32_C(         128),  INT32_C(        1445) },
      {       INT16_MAX,       INT16_MIN, -INT16_C(   128),  INT16_C(  1445) } },
    { {  INT32_C(         612), -INT32_C(           2),  INT32_C(         110), -INT32_C(    49395955) },
      {  INT16_C(   612), -INT16_C(     2),  INT16_C(   110),       INT16_MIN } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x4_t a = simde_vld1q_s32(test_vec[i].a);
    simde_int16x4_t r = simde_vqmovn_s32(a);

    simde_test_arm_neon_assert_equal_i16x4(r, simde_vld1_s16(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int32x4_t s = simde_vandq_s32(simde_test_arm_neon_random_i32x4(), simde_vdupq_n_s32(31));
    simde_int32x4_t a = simde_vshlq_s32(simde_test_arm_neon_random_i32x4(), simde_vnegq_s32(s));
    simde_int16x4_t r = simde_vqmovn_s32(a);

    simde_test_arm_neon_write_i32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i16x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vqmovn_s64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int64_t a[2];
    int32_t r[2];
  } test_vec[] = {
    { {  INT64_C(     139526682078321),  INT64_C(       2088817746455) },
      {            INT32_MAX,            INT32_MAX } },
    { { -INT64_C(            17035200), -INT64_C(              955712) },
      { -INT32_C(    17035200), -INT32_C(      955712) } },
    { {  INT64_C(             1425567), -INT64_C(                   3) },
      {  INT32_C(     1425567), -INT32_C(           3) } },
    { { -INT64_C(    8297862809411069),  INT64_C(            82481668) },
      {            INT32_MIN,  INT32_C(    82481668) } },
    { { -INT64_C(                  86), -INT64_C(                6848) },
      { -INT32_C(          86), -INT32_C(        6848) } },
    { { -INT64_C(   24045364990477906), -INT64_C(            59096770) },
      {            INT32_MIN, -INT32_C(    59096770) } },
    { {  INT64_C(    4080946299684606), -INT64_C(    2138562467329891) },
      {            INT32_MAX,            INT32_MIN } },
    { { -INT64_C(        273036987440),  INT64_C(            31037958) },
      {            INT32_MIN,  INT32_C(    31037958) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int64x2_t a = simde_vld1q_s64(test_vec[i].a);
    simde_int32x2_t r = simde_vqmovn_s64(a);

    simde_test_arm_neon_assert_equal_i32x2(r, simde_vld1_s32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int64x2_t s = simde_vandq_s64(simde_test_arm_neon_random_i64x2(), simde_vdupq_n_s64(63));
    simde_int64x2_t a = simde_vshlq_s64(simde_test_arm_neon_random_i64x2(), simde_vnegq_s64(s));
    simde_int32x2_t r = simde_vqmovn_s64(a);

    simde_test_arm_neon_write_i64x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i32x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vqmovn_u16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint16_t a[8];
    uint8_t r[8];
  } test_vec[] = {
    { { UINT16_C( 1408), UINT16_C(  423), UINT16_C(   15), UINT16_C( 5546), UINT16_C(  459), UINT16_C(    3), UINT16_C(    5), UINT16_C( 9903) },
      {    UINT8_MAX,    UINT8_MAX, UINT8_C( 15),    UINT8_MAX,    UINT8_MAX, UINT8_C(  3), UINT8_C(  5),    UINT8_MAX } },
    { { UINT16_C(    2), UINT16_C(  298), UINT16_C(65062), UINT16_C(    3), UINT16_C(   84), UINT16_C(  315), UINT16_C(  613), UINT16_C(    0) },
      { UINT8_C(  2),    UINT8_MAX,    UINT8_MAX, UINT8_C(  3), UINT8_C( 84),    UINT8_MAX,    UINT8_MAX, UINT8_C(  0) } },
    { { UINT16_C(    3), UINT16_C(   88), UINT16_C(   85), UINT16_C(  603), UINT16_C(    0), UINT16_C(  266), UINT16_C(    3), UINT16_C(  482) },
      { UINT8_C(  3), UINT8_C( 88), UINT8_C( 85),    UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  3),    UINT8_MAX } },
    { { UINT16_C(    5), UINT16_C(   43), UINT16_C(31330), UINT16_C( 4222), UINT16_C(   75), UINT16_C(  230), UINT16_C(   15), UINT16_C(10269) },
      { UINT8_C(  5), UINT8_C( 43),    UINT8_MAX,    UINT8_MAX, UINT8_C( 75), UINT8_C(230), UINT8_C( 15),    UINT8_MAX } },
    { { UINT16_C( 9768), UINT16_C(  374), UINT16_C(23872), UINT16_C( 4467), UINT16_C(    0), UINT16_C(    1), UINT16_C(  465), UINT16_C( 2289) },
      {    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0), UINT8_C(  1),    UINT8_MAX,    UINT8_MAX } },
    { { UINT16_C(    9), UINT16_C(    9), UINT16_C(  113), UINT16_C( 1321), UINT16_C(  196), UINT16_C( 5575), UINT16_C( 1620), UINT16_C(  227) },
      { UINT8_C(  9), UINT8_C(  9), UINT8_C(113),    UINT8_MAX, UINT8_C(196),    UINT8_MAX,    UINT8_MAX, UINT8_C(227) } },
    { { UINT16_C(    6), UINT16_C(  873), UINT16_C(   28), UINT16_C(  115), UINT16_C(   10), UINT16_C(    1), UINT16_C( 4430), UINT16_C(   33) },
      { UINT8_C(  6),    UINT8_MAX, UINT8_C( 28), UINT8_C(115), UINT8_C( 10), UINT8_C(  1),    UINT8_MAX, UINT8_C( 33) } },
    { { UINT16_C(  138), UINT16_C( 1701), UINT16_C(   75), UINT16_C(  744), UINT16_C(   88), UINT16_C(  367), UINT16_C(   23), UINT16_C(  246) },
      { UINT8_C(138),    UINT8_MAX, UINT8_C( 75),    UINT8_MAX, UINT8_C( 88),    UINT8_MAX, UINT8_C( 23), UINT8_C(246) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint16x8_t a = simde_vld1q_u16(test_vec[i].a);
    simde_uint8x8_t r = simde_vqmovn_u16(a);

    simde_test_arm_neon_assert_equal_u8x8(r, simde_vld1_u8(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int16x8_t s = simde_vandq_s16(simde_test_arm_neon_random_i16x8(), simde_vdupq_n_s16(15));
    simde_uint16x8_t a = simde_vshlq_u16(simde_test_arm_neon_random_u16x8(), simde_vnegq_s16(s));
    simde_uint8x8_t r = simde_vqmovn_u16(a);

    simde_test_arm_neon_write_u16x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u8x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vqmovn_u32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint32_t a[4];
    uint16_t r[4];
  } test_vec[] = {
    { { UINT32_C(       157), UINT32_C(        14), UINT32_C(        23), UINT32_C(        46) },
      { UINT16_C(  157), UINT16_C(   14), UINT16_C(   23), UINT16_C(   46) } },
    { { UINT32_C(   1647047), UINT32_C(         0), UINT32_C( 106273110), UINT32_C(     68243) },
      {      UINT16_MAX, UINT16_C(    0),      UINT16_MAX,      UINT16_MAX } },
    { { UINT32_C(        99), UINT32_C( 504538727), UINT32_C(      1480), UINT32_C(    394467) },
      { UINT16_C(   99),      UINT16_MAX, UINT16_C( 1480),      UINT16_MAX } },
    { { UINT32_C(         1), UINT32_C(   1555382), UINT32_C(   3035558), UINT32_C(   9561996) },
      { UINT16_C(    1),      UINT16_MAX,      UINT16_MAX,      UINT16_MAX } },
    { { UINT32_C(   1571819), UINT32_C(      1870), UINT32_C(        15), UINT32_C(     67123) },
      {      UINT16_MAX, UINT16_C( 1870), UINT16_C(   15),      UINT16_MAX } },
    { { UINT32_C(       442), UINT32_C(      4721), UINT32_C(       212), UINT32_C(    963971) },
      { UINT16_C(  442), UINT16_C( 4721), UINT16_C(  212),      UINT16_MAX } },
    { { UINT32_C(      2436), UINT32_C(        23), UINT32_C(        25), UINT32_C(     28600) },
      { UINT16_C( 2436), UINT16_C(   23), UINT16_C(   25), UINT16_C(28600) } },
    { { UINT32_C(        58), UINT32_C(    157917), UINT32_C(  56493959), UINT32_C(         7) },
      { UINT16_C(   58),      UINT16_MAX,      UINT16_MAX, UINT16_C(    7) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint32x4_t a = simde_vld1q_u32(test_vec[i].a);
    simde_uint16x4_t r = simde_vqmovn_u32(a);
    simde_test_arm_neon_assert_equal_u16x4(r, simde_vld1_u16(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int32x4_t s = simde_vandq_s32(simde_test_arm_neon_random_i32x4(), simde_vdupq_n_s32(31));
    simde_uint32x4_t a = simde_vshlq_u32(simde_test_arm_neon_random_u32x4(), simde_vnegq_s32(s));
    simde_uint16x4_t r = simde_vqmovn_u32(a);


    simde_test_arm_neon_write_u32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u16x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vqmovn_u64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint64_t a[2];
    uint32_t r[2];
  } test_vec[] = {
    { { UINT64_C(              868814), UINT64_C(             1506946) },
      { UINT32_C(    868814), UINT32_C(   1506946) } },
    { { UINT64_C(             3231520), UINT64_C(     278576143467030) },
      { UINT32_C(   3231520),           UINT32_MAX } },
    { { UINT64_C(                  29), UINT64_C(  288187650150740947) },
      { UINT32_C(        29),           UINT32_MAX } },
    { { UINT64_C(     141800033160582), UINT64_C(              192885) },
      {           UINT32_MAX, UINT32_C(    192885) } },
    { { UINT64_C(      31175358884501), UINT64_C(         10525926877) },
      {           UINT32_MAX,           UINT32_MAX } },
    { { UINT64_C(             7224308), UINT64_C(  142567009801148782) },
      { UINT32_C(   7224308),           UINT32_MAX } },
    { { UINT64_C(                 200), UINT64_C(                 979) },
      { UINT32_C(       200), UINT32_C(       979) } },
    { { UINT64_C(         60957747479), UINT64_C(              573775) },
      {           UINT32_MAX, UINT32_C(    573775) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint64x2_t a = simde_vld1q_u64(test_vec[i].a);
    simde_uint32x2_t r = simde_vqmovn_u64(a);
    simde_test_arm_neon_assert_equal_u32x2(r, simde_vld1_u32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int64x2_t s = simde_vandq_s64(simde_test_arm_neon_random_i64x2(), simde_vdupq_n_s64(63));
    simde_uint64x2_t a = simde_vshlq_u64(simde_test_arm_neon_random_u64x2(), simde_vnegq_s64(s));
    simde_uint32x2_t r = simde_vqmovn_u64(a);

    simde_test_arm_neon_write_u64x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u32x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}


SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(vqmovn_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vqmovn_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vqmovn_s64)
SIMDE_TEST_FUNC_LIST_ENTRY(vqmovn_u16)
SIMDE_TEST_FUNC_LIST_ENTRY(vqmovn_u32)
SIMDE_TEST_FUNC_LIST_ENTRY(vqmovn_u64)
SIMDE_TEST_FUNC_LIST_END

#include "test-neon-footer.h"
