#define SIMDE_TEST_ARM_NEON_INSN cltz

#include "test-neon.h"
#include "../../../simde/arm/neon/cltz.h"
#include "../../../simde/arm/neon/reinterpret.h"

static int
test_simde_vcltz_f32 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    simde_float32 a[2];
    uint32_t r[2];
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(  -600.28), SIMDE_FLOAT32_C(  -155.01) },
      {           UINT32_MAX,           UINT32_MAX } },
    { { SIMDE_FLOAT32_C(   941.01), SIMDE_FLOAT32_C(   717.45) },
      { UINT32_C(         0), UINT32_C(         0) } },
    { { SIMDE_FLOAT32_C(    22.41), SIMDE_FLOAT32_C(  -542.54) },
      { UINT32_C(         0),           UINT32_MAX } },
    { { SIMDE_FLOAT32_C(  -400.37), SIMDE_FLOAT32_C(  -711.08) },
      {           UINT32_MAX,           UINT32_MAX } },
    { { SIMDE_FLOAT32_C(   591.87), SIMDE_FLOAT32_C(  -579.22) },
      { UINT32_C(         0),           UINT32_MAX } },
    { { SIMDE_FLOAT32_C(  -322.37), SIMDE_FLOAT32_C(    93.44) },
      {           UINT32_MAX, UINT32_C(         0) } },
    { { SIMDE_FLOAT32_C(  -455.16), SIMDE_FLOAT32_C(   540.07) },
      {           UINT32_MAX, UINT32_C(         0) } },
    { { SIMDE_FLOAT32_C(   983.37), SIMDE_FLOAT32_C(   113.16) },
      { UINT32_C(         0), UINT32_C(         0) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x2_t a = simde_vld1_f32(test_vec[i].a);
    simde_uint32x2_t r = simde_vcltz_f32(a);

    simde_test_arm_neon_assert_equal_u32x2(r, simde_vld1_u32(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vcltz_f64 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    simde_float64 a[1];
    uint64_t r[1];
  } test_vec[] = {
    { { SIMDE_FLOAT64_C(  -383.68) },
      {                    UINT64_MAX } },
    { { SIMDE_FLOAT64_C(  -437.89) },
      {                    UINT64_MAX } },
    { { SIMDE_FLOAT64_C(   762.24) },
      { UINT64_C(                   0) } },
    { { SIMDE_FLOAT64_C(  -529.26) },
      {                    UINT64_MAX } },
    { { SIMDE_FLOAT64_C(   863.53) },
      { UINT64_C(                   0) } },
    { { SIMDE_FLOAT64_C(  -770.66) },
      {                    UINT64_MAX } },
    { { SIMDE_FLOAT64_C(  -387.78) },
      {                    UINT64_MAX } },
    { { SIMDE_FLOAT64_C(   354.63) },
      { UINT64_C(                   0) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float64x1_t a = simde_vld1_f64(test_vec[i].a);
    simde_uint64x1_t r = simde_vcltz_f64(a);

    simde_test_arm_neon_assert_equal_u64x1(r, simde_vld1_u64(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vcltz_s8 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    int8_t a[8];
    uint8_t r[8];
  } test_vec[] = {
    { {  INT8_C( 123),  INT8_C(  25),  INT8_C(  43), -INT8_C(   6),  INT8_C(  91),  INT8_C(  15), -INT8_C(   4), -INT8_C(  78) },
      { UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,    UINT8_MAX } },
    { {  INT8_C(   9), -INT8_C(  67),  INT8_C(  14),  INT8_C(  50),      INT8_MAX, -INT8_C(  98),  INT8_C( 122),  INT8_C(  87) },
      { UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  0) } },
    { { -INT8_C(  59), -INT8_C(  40),  INT8_C(  23), -INT8_C( 123),  INT8_C(   0),  INT8_C(  81), -INT8_C( 111), -INT8_C(  11) },
      {    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,    UINT8_MAX } },
    { {  INT8_C(  78), -INT8_C( 120), -INT8_C(  45),  INT8_C( 104),  INT8_C( 116), -INT8_C(  31), -INT8_C(  94), -INT8_C(  17) },
      { UINT8_C(  0),    UINT8_MAX,    UINT8_MAX, UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX } },
    { { -INT8_C(   6), -INT8_C(  51), -INT8_C(  23),  INT8_C(  86), -INT8_C(  36), -INT8_C(  27),  INT8_C(   8), -INT8_C(  27) },
      {    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX } },
    { { -INT8_C(  94),  INT8_C(  22),  INT8_C(  24),  INT8_C(  33), -INT8_C(  76), -INT8_C( 110),  INT8_C( 120),  INT8_C( 121) },
      {    UINT8_MAX, UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,    UINT8_MAX, UINT8_C(  0), UINT8_C(  0) } },
    { {  INT8_C( 106), -INT8_C( 113), -INT8_C(   2),  INT8_C( 106), -INT8_C(  32), -INT8_C( 112),  INT8_C(  95),  INT8_C(  47) },
      { UINT8_C(  0),    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX, UINT8_C(  0), UINT8_C(  0) } },
    { {  INT8_C(  24),  INT8_C(  51), -INT8_C( 105), -INT8_C( 116),  INT8_C(  20),  INT8_C(  57),  INT8_C( 123),  INT8_C(  14) },
      { UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,    UINT8_MAX, UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int8x8_t a = simde_vld1_s8(test_vec[i].a);
    simde_uint8x8_t r = simde_vcltz_s8(a);

    simde_test_arm_neon_assert_equal_u8x8(r, simde_vld1_u8(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vcltz_s16 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    int16_t a[4];
    uint16_t r[4];
  } test_vec[] = {
    { { -INT16_C(  3899), -INT16_C(  2710), -INT16_C( 12036),  INT16_C( 14864) },
      {      UINT16_MAX,      UINT16_MAX,      UINT16_MAX, UINT16_C(    0) } },
    { {  INT16_C( 15179), -INT16_C(  3300), -INT16_C( 24965), -INT16_C( 23761) },
      { UINT16_C(    0),      UINT16_MAX,      UINT16_MAX,      UINT16_MAX } },
    { {  INT16_C( 27808), -INT16_C( 10552), -INT16_C(  3829), -INT16_C( 15215) },
      { UINT16_C(    0),      UINT16_MAX,      UINT16_MAX,      UINT16_MAX } },
    { { -INT16_C( 18422), -INT16_C( 27002),  INT16_C( 16021),  INT16_C( 23504) },
      {      UINT16_MAX,      UINT16_MAX, UINT16_C(    0), UINT16_C(    0) } },
    { {  INT16_C( 14894),  INT16_C( 10832),  INT16_C( 24586),  INT16_C( 21860) },
      { UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0) } },
    { { -INT16_C( 32613),  INT16_C(  5704),  INT16_C( 30494), -INT16_C( 16455) },
      {      UINT16_MAX, UINT16_C(    0), UINT16_C(    0),      UINT16_MAX } },
    { { -INT16_C( 32285), -INT16_C(  4203),  INT16_C(  9843),  INT16_C( 32179) },
      {      UINT16_MAX,      UINT16_MAX, UINT16_C(    0), UINT16_C(    0) } },
    { {  INT16_C( 14814),  INT16_C( 29715), -INT16_C(  7305), -INT16_C( 23089) },
      { UINT16_C(    0), UINT16_C(    0),      UINT16_MAX,      UINT16_MAX } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x4_t a = simde_vld1_s16(test_vec[i].a);
    simde_uint16x4_t r = simde_vcltz_s16(a);

    simde_test_arm_neon_assert_equal_u16x4(r, simde_vld1_u16(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vcltz_s32 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    int32_t a[2];
    uint32_t r[2];
  } test_vec[] = {
    { {  INT32_C(   887751135), -INT32_C(  1880768565) },
      { UINT32_C(         0),           UINT32_MAX } },
    { {  INT32_C(  1143275059), -INT32_C(   106841879) },
      { UINT32_C(         0),           UINT32_MAX } },
    { { -INT32_C(  1429312649),  INT32_C(   192520880) },
      {           UINT32_MAX, UINT32_C(         0) } },
    { { -INT32_C(  1228640489), -INT32_C(  1630219841) },
      {           UINT32_MAX,           UINT32_MAX } },
    { { -INT32_C(  1630290221), -INT32_C(  1322403714) },
      {           UINT32_MAX,           UINT32_MAX } },
    { { -INT32_C(  1594535498), -INT32_C(  2120641014) },
      {           UINT32_MAX,           UINT32_MAX } },
    { { -INT32_C(  1322555391),  INT32_C(   566076426) },
      {           UINT32_MAX, UINT32_C(         0) } },
    { { -INT32_C(   757628653),  INT32_C(   628206418) },
      {           UINT32_MAX, UINT32_C(         0) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x2_t a = simde_vld1_s32(test_vec[i].a);
    simde_uint32x2_t r = simde_vcltz_s32(a);

    simde_test_arm_neon_assert_equal_u32x2(r, simde_vld1_u32(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vcltz_s64 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    int64_t a[1];
    uint64_t r[1];
  } test_vec[] = {
    { { -INT64_C( 8326563804285590750) },
      {                    UINT64_MAX } },
    { { -INT64_C( 3208424567556038596) },
      {                    UINT64_MAX } },
    { {  INT64_C( 2329024188526806682) },
      { UINT64_C(                   0) } },
    { { -INT64_C( 8809616594128501407) },
      {                    UINT64_MAX } },
    { {  INT64_C(  106393993243962263) },
      { UINT64_C(                   0) } },
    { { -INT64_C( 6536608672518002276) },
      {                    UINT64_MAX } },
    { {  INT64_C( 8384819676651960083) },
      { UINT64_C(                   0) } },
    { {  INT64_C( 9028095364871221859) },
      { UINT64_C(                   0) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int64x1_t a = simde_vld1_s64(test_vec[i].a);
    simde_uint64x1_t r = simde_vcltz_s64(a);

    simde_test_arm_neon_assert_equal_u64x1(r, simde_vld1_u64(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vcltzq_f32 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    simde_float32 a[4];
    uint32_t r[4];
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(  -442.45), SIMDE_FLOAT32_C(   552.37), SIMDE_FLOAT32_C(  -139.46), SIMDE_FLOAT32_C(   880.73) },
      {           UINT32_MAX, UINT32_C(         0),           UINT32_MAX, UINT32_C(         0) } },
    { { SIMDE_FLOAT32_C(  -535.61), SIMDE_FLOAT32_C(  -314.97), SIMDE_FLOAT32_C(  -324.37), SIMDE_FLOAT32_C(  -863.63) },
      {           UINT32_MAX,           UINT32_MAX,           UINT32_MAX,           UINT32_MAX } },
    { { SIMDE_FLOAT32_C(  -142.67), SIMDE_FLOAT32_C(  -456.23), SIMDE_FLOAT32_C(   330.18), SIMDE_FLOAT32_C(  -127.74) },
      {           UINT32_MAX,           UINT32_MAX, UINT32_C(         0),           UINT32_MAX } },
    { { SIMDE_FLOAT32_C(   725.38), SIMDE_FLOAT32_C(  -382.66), SIMDE_FLOAT32_C(   959.27), SIMDE_FLOAT32_C(  -336.93) },
      { UINT32_C(         0),           UINT32_MAX, UINT32_C(         0),           UINT32_MAX } },
    { { SIMDE_FLOAT32_C(   249.07), SIMDE_FLOAT32_C(   860.93), SIMDE_FLOAT32_C(    46.17), SIMDE_FLOAT32_C(   812.32) },
      { UINT32_C(         0), UINT32_C(         0), UINT32_C(         0), UINT32_C(         0) } },
    { { SIMDE_FLOAT32_C(  -849.19), SIMDE_FLOAT32_C(  -336.50), SIMDE_FLOAT32_C(   322.45), SIMDE_FLOAT32_C(  -511.47) },
      {           UINT32_MAX,           UINT32_MAX, UINT32_C(         0),           UINT32_MAX } },
    { { SIMDE_FLOAT32_C(  -105.46), SIMDE_FLOAT32_C(   857.83), SIMDE_FLOAT32_C(   267.60), SIMDE_FLOAT32_C(  -602.28) },
      {           UINT32_MAX, UINT32_C(         0), UINT32_C(         0),           UINT32_MAX } },
    { { SIMDE_FLOAT32_C(   768.23), SIMDE_FLOAT32_C(  -752.53), SIMDE_FLOAT32_C(  -518.24), SIMDE_FLOAT32_C(  -674.22) },
      { UINT32_C(         0),           UINT32_MAX,           UINT32_MAX,           UINT32_MAX } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x4_t a = simde_vld1q_f32(test_vec[i].a);
    simde_uint32x4_t r = simde_vcltzq_f32(a);
    simde_test_arm_neon_assert_equal_u32x4(r, simde_vld1q_u32(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vcltzq_f64 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    simde_float64 a[2];
    uint64_t r[2];
  } test_vec[] = {
    { { SIMDE_FLOAT64_C(   -80.27), SIMDE_FLOAT64_C(   326.82) },
      {                    UINT64_MAX, UINT64_C(                   0) } },
    { { SIMDE_FLOAT64_C(  -489.46), SIMDE_FLOAT64_C(  -457.68) },
      {                    UINT64_MAX,                    UINT64_MAX } },
    { { SIMDE_FLOAT64_C(  -441.47), SIMDE_FLOAT64_C(     2.14) },
      {                    UINT64_MAX, UINT64_C(                   0) } },
    { { SIMDE_FLOAT64_C(  -692.88), SIMDE_FLOAT64_C(   270.65) },
      {                    UINT64_MAX, UINT64_C(                   0) } },
    { { SIMDE_FLOAT64_C(   806.25), SIMDE_FLOAT64_C(   705.39) },
      { UINT64_C(                   0), UINT64_C(                   0) } },
    { { SIMDE_FLOAT64_C(  -398.22), SIMDE_FLOAT64_C(  -504.15) },
      {                    UINT64_MAX,                    UINT64_MAX } },
    { { SIMDE_FLOAT64_C(   952.43), SIMDE_FLOAT64_C(  -573.18) },
      { UINT64_C(                   0),                    UINT64_MAX } },
    { { SIMDE_FLOAT64_C(  -443.24), SIMDE_FLOAT64_C(   861.65) },
      {                    UINT64_MAX, UINT64_C(                   0) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float64x2_t a = simde_vld1q_f64(test_vec[i].a);
    simde_uint64x2_t r = simde_vcltzq_f64(a);

    simde_test_arm_neon_assert_equal_u64x2(r, simde_vld1q_u64(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vcltzq_s8 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    int8_t a[16];
    uint8_t r[16];
  } test_vec[] = {
    { {  INT8_C( 120),  INT8_C(  63),  INT8_C(  43), -INT8_C(   2), -INT8_C(  79),  INT8_C(  47),  INT8_C( 121),  INT8_C(   7),
         INT8_C(  59),      INT8_MAX, -INT8_C(  81), -INT8_C(  20), -INT8_C(  61), -INT8_C(  30),  INT8_C(  90),  INT8_C(  60) },
      { UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,    UINT8_MAX, UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),
        UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0), UINT8_C(  0) } },
    { { -INT8_C(  87),  INT8_C(  32),  INT8_C( 104), -INT8_C(  78),  INT8_C(  22),  INT8_C(  85), -INT8_C(  93), -INT8_C(  97),
         INT8_C(  26), -INT8_C(   7), -INT8_C(  98),  INT8_C(  56), -INT8_C(  40),  INT8_C(  11),  INT8_C( 103),  INT8_C(  81) },
      {    UINT8_MAX, UINT8_C(  0), UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,
        UINT8_C(  0),    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  0), UINT8_C(  0) } },
    { {  INT8_C(  74), -INT8_C( 110),  INT8_C(  79), -INT8_C(   5), -INT8_C(  63), -INT8_C(  55),  INT8_C(   2), -INT8_C(   4),
         INT8_C(  72), -INT8_C(  79), -INT8_C(  23),  INT8_C(  11), -INT8_C( 109),  INT8_C(  67),  INT8_C(  72),  INT8_C(  60) },
      { UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,
        UINT8_C(  0),    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  0), UINT8_C(  0) } },
    { {  INT8_C(  99), -INT8_C(  80), -INT8_C(  18),  INT8_C( 121),  INT8_C(   5), -INT8_C( 111),  INT8_C(  25),  INT8_C(  31),
        -INT8_C( 118), -INT8_C(  73),  INT8_C(  87),  INT8_C(  99), -INT8_C(  61), -INT8_C(  65), -INT8_C(  76),  INT8_C(  13) },
      { UINT8_C(  0),    UINT8_MAX,    UINT8_MAX, UINT8_C(  0), UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  0),
           UINT8_MAX,    UINT8_MAX, UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0) } },
    { {  INT8_C(  81),  INT8_C(   3),  INT8_C(   9),  INT8_C(  19), -INT8_C(  52),  INT8_C(  11),  INT8_C(  15),  INT8_C(  21),
        -INT8_C(  67), -INT8_C(   8),  INT8_C(  32),  INT8_C(  80),  INT8_C(  60),  INT8_C( 104), -INT8_C( 115), -INT8_C(  97) },
      { UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),
           UINT8_MAX,    UINT8_MAX, UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,    UINT8_MAX } },
    { {  INT8_C(  24),  INT8_C( 123),  INT8_C(  25),  INT8_C(  29),  INT8_C(  13),  INT8_C(  50),  INT8_C(  61), -INT8_C( 105),
        -INT8_C(  23), -INT8_C( 108), -INT8_C(   6), -INT8_C(  84),  INT8_C(  83), -INT8_C(  82), -INT8_C(  70), -INT8_C(  91) },
      { UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,
           UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX } },
    { { -INT8_C(  78), -INT8_C(  61), -INT8_C(  72),  INT8_C( 126), -INT8_C(  50), -INT8_C(  57), -INT8_C( 109), -INT8_C( 117),
        -INT8_C(  64), -INT8_C(  76), -INT8_C(  36), -INT8_C(   4),  INT8_C(  28),  INT8_C( 105), -INT8_C( 101),  INT8_C(  53) },
      {    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,
           UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0), UINT8_C(  0),    UINT8_MAX, UINT8_C(  0) } },
    { { -INT8_C(  28), -INT8_C(  76),  INT8_C(  82), -INT8_C(  15), -INT8_C(  26), -INT8_C( 113), -INT8_C( 119), -INT8_C(  48),
         INT8_C(  36), -INT8_C( 125),  INT8_C( 124),  INT8_C( 119),  INT8_C(  50),  INT8_C(  54),  INT8_C(  28), -INT8_C(  28) },
      {    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,
        UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),    UINT8_MAX } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int8x16_t a = simde_vld1q_s8(test_vec[i].a);
    simde_uint8x16_t r = simde_vcltzq_s8(a);

    simde_test_arm_neon_assert_equal_u8x16(r, simde_vld1q_u8(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vcltzq_s16 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    int16_t a[8];
    uint16_t r[8];
  } test_vec[] = {
    { { -INT16_C( 30173),  INT16_C( 19444), -INT16_C( 28978), -INT16_C( 15017),  INT16_C( 17496),  INT16_C(  7636), -INT16_C( 12918),  INT16_C(  3110) },
      {      UINT16_MAX, UINT16_C(    0),      UINT16_MAX,      UINT16_MAX, UINT16_C(    0), UINT16_C(    0),      UINT16_MAX, UINT16_C(    0) } },
    { { -INT16_C( 17031),  INT16_C( 23923), -INT16_C( 15294),  INT16_C(   828),  INT16_C(  7152), -INT16_C( 19786),  INT16_C( 22798),  INT16_C( 12797) },
      {      UINT16_MAX, UINT16_C(    0),      UINT16_MAX, UINT16_C(    0), UINT16_C(    0),      UINT16_MAX, UINT16_C(    0), UINT16_C(    0) } },
    { { -INT16_C(  3613), -INT16_C( 20099), -INT16_C( 11137), -INT16_C( 10378),  INT16_C( 19224), -INT16_C( 23820),  INT16_C(  6936), -INT16_C( 27986) },
      {      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX, UINT16_C(    0),      UINT16_MAX, UINT16_C(    0),      UINT16_MAX } },
    { {  INT16_C(  8920),  INT16_C(  6895),  INT16_C( 11238), -INT16_C( 10723), -INT16_C( 11450),  INT16_C( 21896), -INT16_C( 31188),  INT16_C(  3974) },
      { UINT16_C(    0), UINT16_C(    0), UINT16_C(    0),      UINT16_MAX,      UINT16_MAX, UINT16_C(    0),      UINT16_MAX, UINT16_C(    0) } },
    { {  INT16_C(   887), -INT16_C(  2111),  INT16_C( 14295), -INT16_C(  4146), -INT16_C( 15486), -INT16_C( 25711),  INT16_C( 16606), -INT16_C( 18899) },
      { UINT16_C(    0),      UINT16_MAX, UINT16_C(    0),      UINT16_MAX,      UINT16_MAX,      UINT16_MAX, UINT16_C(    0),      UINT16_MAX } },
    { {  INT16_C(  7266),  INT16_C( 18640), -INT16_C(  4792), -INT16_C( 29153), -INT16_C( 22591), -INT16_C(  4637),  INT16_C( 27181), -INT16_C( 23043) },
      { UINT16_C(    0), UINT16_C(    0),      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX, UINT16_C(    0),      UINT16_MAX } },
    { { -INT16_C( 16787),  INT16_C( 17820),  INT16_C( 27381),  INT16_C( 30772), -INT16_C( 14803),  INT16_C(  2835),  INT16_C( 16390),  INT16_C( 26817) },
      {      UINT16_MAX, UINT16_C(    0), UINT16_C(    0), UINT16_C(    0),      UINT16_MAX, UINT16_C(    0), UINT16_C(    0), UINT16_C(    0) } },
    { { -INT16_C( 28324), -INT16_C( 23376), -INT16_C( 12417),  INT16_C( 16435),  INT16_C(  5751), -INT16_C( 23507),  INT16_C( 10880), -INT16_C(  4535) },
      {      UINT16_MAX,      UINT16_MAX,      UINT16_MAX, UINT16_C(    0), UINT16_C(    0),      UINT16_MAX, UINT16_C(    0),      UINT16_MAX } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x8_t a = simde_vld1q_s16(test_vec[i].a);
    simde_uint16x8_t r = simde_vcltzq_s16(a);

    simde_test_arm_neon_assert_equal_u16x8(r, simde_vld1q_u16(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vcltzq_s32 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    int32_t a[4];
    uint32_t r[4];
  } test_vec[] = {
    { {  INT32_C(   104066264),  INT32_C(  1548859983), -INT32_C(   983940808),  INT32_C(  1490571068) },
      { UINT32_C(         0), UINT32_C(         0),           UINT32_MAX, UINT32_C(         0) } },
    { { -INT32_C(   222302292), -INT32_C(  1438018326),  INT32_C(   756148753), -INT32_C(  1515649587) },
      {           UINT32_MAX,           UINT32_MAX, UINT32_C(         0),           UINT32_MAX } },
    { {  INT32_C(  1085070577), -INT32_C(   811729513),  INT32_C(  2073425726), -INT32_C(   221024954) },
      { UINT32_C(         0),           UINT32_MAX, UINT32_C(         0),           UINT32_MAX } },
    { {  INT32_C(  1189450332),  INT32_C(   955264550), -INT32_C(   446365160), -INT32_C(   108392953) },
      { UINT32_C(         0), UINT32_C(         0),           UINT32_MAX,           UINT32_MAX } },
    { { -INT32_C(  2126956822),  INT32_C(  1917965875),  INT32_C(   351135437), -INT32_C(  1358512045) },
      {           UINT32_MAX, UINT32_C(         0), UINT32_C(         0),           UINT32_MAX } },
    { {  INT32_C(  2046159698),  INT32_C(   833742105), -INT32_C(   283765017),  INT32_C(   250126628) },
      { UINT32_C(         0), UINT32_C(         0),           UINT32_MAX, UINT32_C(         0) } },
    { {  INT32_C(   193995223), -INT32_C(   981605896),  INT32_C(   450456263),  INT32_C(  2093604906) },
      { UINT32_C(         0),           UINT32_MAX, UINT32_C(         0), UINT32_C(         0) } },
    { { -INT32_C(   436879669), -INT32_C(  1961449821), -INT32_C(   528863812), -INT32_C(  1511038258) },
      {           UINT32_MAX,           UINT32_MAX,           UINT32_MAX,           UINT32_MAX } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x4_t a = simde_vld1q_s32(test_vec[i].a);
    simde_uint32x4_t r = simde_vcltzq_s32(a);
    simde_test_arm_neon_assert_equal_u32x4(r, simde_vld1q_u32(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vcltzq_s64 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    int64_t a[2];
    uint64_t r[2];
  } test_vec[] = {
    { { -INT64_C( 4367700174058313457), -INT64_C( 7730538683494878666) },
      {                    UINT64_MAX,                    UINT64_MAX } },
    { { -INT64_C( 4741576537993497024), -INT64_C( 8245872675751211559) },
      {                    UINT64_MAX,                    UINT64_MAX } },
    { {  INT64_C( 7856281297696352367), -INT64_C( 4329458411663726768) },
      { UINT64_C(                   0),                    UINT64_MAX } },
    { { -INT64_C( 2313814442133127710), -INT64_C( 2844345970244083077) },
      {                    UINT64_MAX,                    UINT64_MAX } },
    { { -INT64_C( 5627489208313822654),  INT64_C( 7589113511113448203) },
      {                    UINT64_MAX, UINT64_C(                   0) } },
    { { -INT64_C(  552410599904063889), -INT64_C( 4948198726902374637) },
      {                    UINT64_MAX,                    UINT64_MAX } },
    { { -INT64_C( 6932135403521281863),  INT64_C( 3956552763142165751) },
      {                    UINT64_MAX, UINT64_C(                   0) } },
    { { -INT64_C(  378018798689814963), -INT64_C( 2029775254167571808) },
      {                    UINT64_MAX,                    UINT64_MAX } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int64x2_t a = simde_vld1q_s64(test_vec[i].a);
    simde_uint64x2_t r = simde_vcltzq_s64(a);
    simde_test_arm_neon_assert_equal_u64x2(r, simde_vld1q_u64(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vcltzd_s64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int64_t a;
    uint64_t r;
  } test_vec[] = {
    {  INT64_C( 4895556179217159423),
      UINT64_C(                   0) },
    { -INT64_C( 5958045163452274988),
                          UINT64_MAX },
    { -INT64_C( 7404907283308324771),
                          UINT64_MAX },
    { -INT64_C( 5357149720396651297),
                          UINT64_MAX },
    {  INT64_C( 3626495416649243816),
      UINT64_C(                   0) },
    {  INT64_C( 2771735539879904332),
      UINT64_C(                   0) },
    { -INT64_C( 8777399505245099129),
                          UINT64_MAX },
    { -INT64_C( 7459753252293551091),
                          UINT64_MAX }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    uint64_t r = simde_vcltzd_s64(test_vec[i].a);
    simde_assert_equal_u64(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    int64_t a = simde_test_codegen_random_i64();
    uint64_t r = simde_vcltzd_s64(a);

    simde_test_codegen_write_i64(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_u64(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcltzd_f64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float64_t a;
    uint64_t r;
  } test_vec[] = {
    { SIMDE_FLOAT64_C(   918.77),
      UINT64_C(                   0) },
    { SIMDE_FLOAT64_C(  -706.44),
                          UINT64_MAX },
    { SIMDE_FLOAT64_C(  -108.73),
                          UINT64_MAX },
    { SIMDE_FLOAT64_C(  -943.89),
                          UINT64_MAX },
    { SIMDE_FLOAT64_C(   654.01),
      UINT64_C(                   0) },
    { SIMDE_FLOAT64_C(   689.80),
      UINT64_C(                   0) },
    { SIMDE_FLOAT64_C(   101.37),
      UINT64_C(                   0) },
    { SIMDE_FLOAT64_C(   763.46),
      UINT64_C(                   0) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    uint64_t r = simde_vcltzd_f64(test_vec[i].a);
    simde_assert_equal_u64(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float64_t a = simde_test_codegen_random_f64(-1000, 1000);
    uint64_t r = simde_vcltzd_f64(a);

    simde_test_codegen_write_f64(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_u64(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcltzs_f32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float32_t a;
    uint32_t r;
  } test_vec[] = {
    { SIMDE_FLOAT32_C(   418.80),
      UINT32_C(         0) },
    { SIMDE_FLOAT32_C(   -38.64),
                UINT32_MAX },
    { SIMDE_FLOAT32_C(   835.62),
      UINT32_C(         0) },
    { SIMDE_FLOAT32_C(  -210.67),
                UINT32_MAX },
    { SIMDE_FLOAT32_C(   753.71),
      UINT32_C(         0) },
    { SIMDE_FLOAT32_C(   601.27),
      UINT32_C(         0) },
    { SIMDE_FLOAT32_C(  -439.56),
                UINT32_MAX },
    { SIMDE_FLOAT32_C(   192.08),
      UINT32_C(         0) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    uint32_t r = simde_vcltzs_f32(test_vec[i].a);
    simde_assert_equal_u32(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float32_t a = simde_test_codegen_random_f32(-1000, 1000);
    uint32_t r = simde_vcltzs_f32(a);

    simde_test_codegen_write_f32(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_u32(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(vcltz_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vcltz_f64)
SIMDE_TEST_FUNC_LIST_ENTRY(vcltz_s8)
SIMDE_TEST_FUNC_LIST_ENTRY(vcltz_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vcltz_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vcltz_s64)

SIMDE_TEST_FUNC_LIST_ENTRY(vcltzq_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vcltzq_f64)
SIMDE_TEST_FUNC_LIST_ENTRY(vcltzq_s8)
SIMDE_TEST_FUNC_LIST_ENTRY(vcltzq_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vcltzq_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vcltzq_s64)

SIMDE_TEST_FUNC_LIST_ENTRY(vcltzd_f64)
SIMDE_TEST_FUNC_LIST_ENTRY(vcltzd_s64)
SIMDE_TEST_FUNC_LIST_ENTRY(vcltzs_f32)
SIMDE_TEST_FUNC_LIST_END

#include "test-neon-footer.h"
