#define SIMDE_TEST_ARM_NEON_INSN st3

#include "test-neon.h"
#include "../../../simde/arm/neon/st3.h"
#include "../../../simde/arm/neon/ld3.h"

static int
test_simde_vst3_f32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float32 r[3][2];
  } test_vec[] = {
    {
        { { SIMDE_FLOAT32_C(    80.07), SIMDE_FLOAT32_C(  -149.86) },
          { SIMDE_FLOAT32_C(  -229.33), SIMDE_FLOAT32_C(   604.10) },
          { SIMDE_FLOAT32_C(   417.42), SIMDE_FLOAT32_C(  -903.95) } },
    },
    {
        { { SIMDE_FLOAT32_C(  -736.40), SIMDE_FLOAT32_C(   644.17) },
          { SIMDE_FLOAT32_C(  -142.47), SIMDE_FLOAT32_C(  -184.71) },
          { SIMDE_FLOAT32_C(  -274.71), SIMDE_FLOAT32_C(  -516.39) } },
    },
    {
        { { SIMDE_FLOAT32_C(   770.57), SIMDE_FLOAT32_C(  -388.63) },
          { SIMDE_FLOAT32_C(   -14.08), SIMDE_FLOAT32_C(   212.31) },
          { SIMDE_FLOAT32_C(   -54.85), SIMDE_FLOAT32_C(   549.33) } },
    },
    {
        { { SIMDE_FLOAT32_C(  -967.93), SIMDE_FLOAT32_C(    47.52) },
          { SIMDE_FLOAT32_C(  -450.11), SIMDE_FLOAT32_C(    87.29) },
          { SIMDE_FLOAT32_C(   614.85), SIMDE_FLOAT32_C(  -663.71) } },
    },
    {
        { { SIMDE_FLOAT32_C(   976.86), SIMDE_FLOAT32_C(   750.46) },
          { SIMDE_FLOAT32_C(   482.97), SIMDE_FLOAT32_C(  -967.27) },
          { SIMDE_FLOAT32_C(   646.19), SIMDE_FLOAT32_C(   314.03) } },
    },
    {
        { { SIMDE_FLOAT32_C(  -407.19), SIMDE_FLOAT32_C(  -273.74) },
          { SIMDE_FLOAT32_C(  -835.84), SIMDE_FLOAT32_C(   363.48) },
          { SIMDE_FLOAT32_C(  -669.64), SIMDE_FLOAT32_C(   581.58) } },
    },
    {
        { { SIMDE_FLOAT32_C(   459.53), SIMDE_FLOAT32_C(  -406.05) },
          { SIMDE_FLOAT32_C(   225.76), SIMDE_FLOAT32_C(  -682.94) },
          { SIMDE_FLOAT32_C(   409.25), SIMDE_FLOAT32_C(   951.05) } },
    },
    {
        { { SIMDE_FLOAT32_C(  -199.33), SIMDE_FLOAT32_C(   179.82) },
          { SIMDE_FLOAT32_C(  -437.58), SIMDE_FLOAT32_C(   786.60) },
          { SIMDE_FLOAT32_C(  -607.87), SIMDE_FLOAT32_C(   507.57) } },
    },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x2x3_t a = simde_vld3_f32(test_vec[i].r[0]);
    simde_float32_t r_[3][2];
    simde_vst3_f32(r_[0], a);
    simde_test_arm_neon_assert_equal_f32x2(simde_vld1_f32(r_[0]), simde_vld1_f32(test_vec[i].r[0]), 1);
    simde_test_arm_neon_assert_equal_f32x2(simde_vld1_f32(r_[1]), simde_vld1_f32(test_vec[i].r[1]), 1);
    simde_test_arm_neon_assert_equal_f32x2(simde_vld1_f32(r_[2]), simde_vld1_f32(test_vec[i].r[2]), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float32x2x3_t a = { { simde_test_arm_neon_random_f32x2(-1000.0f, 1000.0f),
                                simde_test_arm_neon_random_f32x2(-1000.0f, 1000.0f),
                                simde_test_arm_neon_random_f32x2(-1000.0f, 1000.0f), } };
    simde_test_arm_neon_write_f32x2x3(2, a, SIMDE_TEST_VEC_POS_FIRST);
  }
  return 1;
#endif
}

static int
test_simde_vst3_f64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float64 r[3][1];
  } test_vec[] = {
    {
        { { SIMDE_FLOAT64_C(   289.30) },
          { SIMDE_FLOAT64_C(   603.27) },
          { SIMDE_FLOAT64_C(   754.88) } },
    },
    {
        { { SIMDE_FLOAT64_C(  -636.02) },
          { SIMDE_FLOAT64_C(  -152.48) },
          { SIMDE_FLOAT64_C(  -255.67) } },
    },
    {
        { { SIMDE_FLOAT64_C(   609.01) },
          { SIMDE_FLOAT64_C(   588.12) },
          { SIMDE_FLOAT64_C(   -35.06) } },
    },
    {
        { { SIMDE_FLOAT64_C(  -333.68) },
          { SIMDE_FLOAT64_C(   808.52) },
          { SIMDE_FLOAT64_C(   390.95) } },
    },
    {
        { { SIMDE_FLOAT64_C(  -556.97) },
          { SIMDE_FLOAT64_C(   721.17) },
          { SIMDE_FLOAT64_C(    34.32) } },
    },
    {
        { { SIMDE_FLOAT64_C(   568.79) },
          { SIMDE_FLOAT64_C(    97.31) },
          { SIMDE_FLOAT64_C(  -899.83) } },
    },
    {
        { { SIMDE_FLOAT64_C(  -962.49) },
          { SIMDE_FLOAT64_C(   229.87) },
          { SIMDE_FLOAT64_C(  -693.60) } },
    },
    {
        { { SIMDE_FLOAT64_C(  -468.12) },
          { SIMDE_FLOAT64_C(  -750.16) },
          { SIMDE_FLOAT64_C(  -103.61) } },
    },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float64x1x3_t a = simde_vld3_f64(test_vec[i].r[0]);
    simde_float64_t r_[3][1];
    simde_vst3_f64(r_[0], a);
    simde_test_arm_neon_assert_equal_f64x1(simde_vld1_f64(r_[0]), simde_vld1_f64(test_vec[i].r[0]), 1);
    simde_test_arm_neon_assert_equal_f64x1(simde_vld1_f64(r_[1]), simde_vld1_f64(test_vec[i].r[1]), 1);
    simde_test_arm_neon_assert_equal_f64x1(simde_vld1_f64(r_[2]), simde_vld1_f64(test_vec[i].r[2]), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float64x1x3_t a = { { simde_test_arm_neon_random_f64x1(-1000.0, 1000.0),
                                simde_test_arm_neon_random_f64x1(-1000.0, 1000.0),
                                simde_test_arm_neon_random_f64x1(-1000.0, 1000.0), } };
    simde_test_arm_neon_write_f64x1x3(2,a, SIMDE_TEST_VEC_POS_FIRST);
  }
  return 1;
#endif
}

static int
test_simde_vst3_s8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int8_t r[3][8];
  } test_vec[] = {
    {
        { { -INT8_C(  59),  INT8_C(  26),  INT8_C(  13),  INT8_C(  48),  INT8_C( 102), -INT8_C( 107),  INT8_C(  12),  INT8_C( 107) },
          {  INT8_C(   2), -INT8_C(   1),  INT8_C(  75), -INT8_C(  71), -INT8_C(  16),  INT8_C(  14),  INT8_C(  32), -INT8_C(  22) },
          {  INT8_C(  17), -INT8_C(  96),      INT8_MIN,  INT8_C(  90), -INT8_C(  93), -INT8_C( 111), -INT8_C(  64),  INT8_C(  18) } },
    },
    {
        { {  INT8_C( 106), -INT8_C(  52), -INT8_C(  69),  INT8_C(  56), -INT8_C( 106), -INT8_C(  88), -INT8_C(  60),  INT8_C(  92) },
          { -INT8_C(  62), -INT8_C(  47), -INT8_C( 116),  INT8_C(  41),  INT8_C( 103), -INT8_C( 104), -INT8_C( 108),  INT8_C( 105) },
          { -INT8_C( 105), -INT8_C(  32),  INT8_C(  34), -INT8_C( 121), -INT8_C(  18),  INT8_C(  67),  INT8_C( 113),  INT8_C(   0) } },
    },
    {
        { { -INT8_C(  29), -INT8_C(  15),  INT8_C(  90), -INT8_C( 122), -INT8_C( 125),  INT8_C(  26), -INT8_C( 104), -INT8_C(  19) },
          { -INT8_C(  26),  INT8_C(  84),  INT8_C(  37),  INT8_C( 125), -INT8_C(   4), -INT8_C(  22), -INT8_C(  39), -INT8_C(  65) },
          { -INT8_C(  69),  INT8_C( 101), -INT8_C(  24),  INT8_C(  34), -INT8_C(   3),  INT8_C( 124), -INT8_C( 117), -INT8_C( 108) } },
    },
    {
        { {  INT8_C(  92), -INT8_C(  82),  INT8_C(  27),  INT8_C(  75), -INT8_C(  15), -INT8_C( 116),  INT8_C(  75), -INT8_C(  44) },
          {  INT8_C( 125), -INT8_C(  91),  INT8_C(  90),  INT8_C(   0), -INT8_C(  65), -INT8_C(  13), -INT8_C(  19), -INT8_C(  91) },
          {  INT8_C(  71),  INT8_C(  19),  INT8_C(  34),  INT8_C(  67), -INT8_C(   3), -INT8_C(   5),  INT8_C(   2), -INT8_C(  72) } },
    },
    {
        { {  INT8_C(  96), -INT8_C(  22), -INT8_C(  37),  INT8_C(  93),  INT8_C( 103),  INT8_C( 102), -INT8_C(  15), -INT8_C(  61) },
          {  INT8_C(  20),  INT8_C(  12),  INT8_C(  14),  INT8_C(   5), -INT8_C( 104),  INT8_C(  89), -INT8_C(  39),  INT8_C(  22) },
          { -INT8_C(   2),  INT8_C(  52),  INT8_C(  22), -INT8_C(  67),  INT8_C(  39),  INT8_C(   4),  INT8_C(  99),  INT8_C( 110) } },
    },
    {
        { {  INT8_C(  23), -INT8_C( 123), -INT8_C(  79),  INT8_C(  20), -INT8_C( 127), -INT8_C(  76), -INT8_C(  52), -INT8_C(  31) },
          { -INT8_C(  98), -INT8_C(  89),  INT8_C(  63),  INT8_C(   5),  INT8_C(  14),  INT8_C(  48), -INT8_C(  55),  INT8_C(  34) },
          {  INT8_C(  61), -INT8_C(  41),  INT8_C(  40), -INT8_C(  43),  INT8_C(  49),  INT8_C(   1), -INT8_C(  21),  INT8_C(  47) } },
    },
    {
        { {  INT8_C(  53),  INT8_C(   2), -INT8_C(  19),  INT8_C(  92),  INT8_C(   6),  INT8_C(  80), -INT8_C(  54),  INT8_C(  29) },
          { -INT8_C(  43),  INT8_C( 124),  INT8_C(  49),  INT8_C(  86),  INT8_C(  48), -INT8_C(   3),  INT8_C(  56), -INT8_C(  50) },
          { -INT8_C(  91),  INT8_C( 119), -INT8_C(  44), -INT8_C(  77), -INT8_C(  89), -INT8_C(  99), -INT8_C(  43), -INT8_C(  28) } },
    },
    {
        { {  INT8_C( 116), -INT8_C(   3), -INT8_C(  70), -INT8_C(  91), -INT8_C(   1), -INT8_C(  91), -INT8_C(  43),  INT8_C(  52) },
          { -INT8_C(  89), -INT8_C(  62), -INT8_C( 111), -INT8_C(  83),  INT8_C(  18),  INT8_C(  91), -INT8_C(  54), -INT8_C(  25) },
          { -INT8_C(  41), -INT8_C(   5),  INT8_C(  62),  INT8_C(   7), -INT8_C(   7),  INT8_C( 118), -INT8_C(  42), -INT8_C(  98) } },
    },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int8x8x3_t a = simde_vld3_s8(test_vec[i].r[0]);
    int8_t r_[3][8];
    simde_vst3_s8(r_[0], a);
    simde_test_arm_neon_assert_equal_i8x8(simde_vld1_s8(r_[0]), simde_vld1_s8(test_vec[i].r[0]));
    simde_test_arm_neon_assert_equal_i8x8(simde_vld1_s8(r_[1]), simde_vld1_s8(test_vec[i].r[1]));
    simde_test_arm_neon_assert_equal_i8x8(simde_vld1_s8(r_[2]), simde_vld1_s8(test_vec[i].r[2]));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int8x8x3_t a = { { simde_test_arm_neon_random_i8x8(),
                             simde_test_arm_neon_random_i8x8(),
                             simde_test_arm_neon_random_i8x8(), } };
    simde_test_arm_neon_write_i8x8x3(2, a, SIMDE_TEST_VEC_POS_FIRST);
  }
  return 1;
#endif
}

static int
test_simde_vst3_s16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int16_t r[3][4];
  } test_vec[] = {
    {
        { {  INT16_C( 25111), -INT16_C( 26376), -INT16_C(  6486),  INT16_C(  4910) },
          { -INT16_C( 25344), -INT16_C( 11008),  INT16_C( 21576),  INT16_C( 28428) },
          { -INT16_C( 27926),  INT16_C(  2568),  INT16_C( 15399),  INT16_C( 15083) } },
    },
    {
        { { -INT16_C( 28070),  INT16_C(  9055),  INT16_C( 17883), -INT16_C(  3324) },
          { -INT16_C(   856),  INT16_C( 21131), -INT16_C( 17950), -INT16_C(  7579) },
          {  INT16_C( 26198), -INT16_C( 24905), -INT16_C( 15430), -INT16_C( 23538) } },
    },
    {
        { {  INT16_C(  5718),  INT16_C( 32174), -INT16_C( 26285), -INT16_C( 21065) },
          {  INT16_C(  5931),  INT16_C(  2001), -INT16_C( 10916),  INT16_C(  1274) },
          { -INT16_C( 31279), -INT16_C( 19625), -INT16_C( 17345), -INT16_C( 27243) } },
    },
    {
        { {  INT16_C( 19490), -INT16_C(  9164),  INT16_C( 16912),  INT16_C( 26240) },
          {  INT16_C( 11864), -INT16_C( 21533), -INT16_C( 25912), -INT16_C(  3239) },
          {  INT16_C( 10929),  INT16_C(  3834), -INT16_C(  2817), -INT16_C( 12270) } },
    },
    {
        { {  INT16_C( 27002), -INT16_C( 18045),  INT16_C(  6182),  INT16_C( 18510) },
          { -INT16_C( 32156),  INT16_C( 29733), -INT16_C( 23100),  INT16_C(  7642) },
          { -INT16_C( 16940), -INT16_C( 25400),  INT16_C(  8536),  INT16_C(  2447) } },
    },
    {
        { { -INT16_C( 30133),  INT16_C( 18967),  INT16_C( 10878), -INT16_C(  2022) },
          { -INT16_C( 25197), -INT16_C( 17999),  INT16_C(   181),  INT16_C(  6658) },
          {  INT16_C( 10114),  INT16_C( 18318),  INT16_C( 27084), -INT16_C( 24476) } },
    },
    {
        { {  INT16_C( 11302),  INT16_C( 32316), -INT16_C( 13234), -INT16_C( 26232) },
          { -INT16_C( 24746), -INT16_C( 11036), -INT16_C(   311),  INT16_C( 24013) },
          {  INT16_C( 32412),  INT16_C( 20758),  INT16_C(  6270),  INT16_C(   363) } },
    },
    {
        { { -INT16_C(  1473),  INT16_C(  3144), -INT16_C( 21405), -INT16_C( 30292) },
          { -INT16_C(  5672),  INT16_C(  9736), -INT16_C( 28491),  INT16_C(  3008) },
          { -INT16_C( 23505), -INT16_C(  1569), -INT16_C( 21342),  INT16_C( 15958) } },
    },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x4x3_t a = simde_vld3_s16(test_vec[i].r[0]);
    int16_t r_[3][4];
    simde_vst3_s16(r_[0], a);
    simde_test_arm_neon_assert_equal_i16x4(simde_vld1_s16(r_[0]), simde_vld1_s16(test_vec[i].r[0]));
    simde_test_arm_neon_assert_equal_i16x4(simde_vld1_s16(r_[1]), simde_vld1_s16(test_vec[i].r[1]));
    simde_test_arm_neon_assert_equal_i16x4(simde_vld1_s16(r_[2]), simde_vld1_s16(test_vec[i].r[2]));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int16x4x3_t a = { { simde_test_arm_neon_random_i16x4(),
                              simde_test_arm_neon_random_i16x4(),
                              simde_test_arm_neon_random_i16x4(), } };
    simde_test_arm_neon_write_i16x4x3(2, a, SIMDE_TEST_VEC_POS_FIRST);
  }
  return 1;
#endif
}

static int
test_simde_vst3_s32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int32_t r[3][2];
  } test_vec[] = {
    {
        { { -INT32_C(  1495698562), -INT32_C(  1977551975) },
          { -INT32_C(   308515369),  INT32_C(  2101474231) },
          { -INT32_C(   646256666), -INT32_C(   485659544) } },
    },
    {
        { {  INT32_C(   554941248), -INT32_C(  1329020111) },
          { -INT32_C(   799628746),  INT32_C(  1817867925) },
          { -INT32_C(  1705314333), -INT32_C(   786916374) } },
    },
    {
        { { -INT32_C(   357920126),  INT32_C(  1070446590) },
          { -INT32_C(  1537154958), -INT32_C(   648795741) },
          {  INT32_C(  1621732043),  INT32_C(    80479264) } },
    },
    {
        { { -INT32_C(   442620165),  INT32_C(  1136047809) },
          {  INT32_C(  1194156361), -INT32_C(  1954088424) },
          {  INT32_C(  2100291546), -INT32_C(   615021808) } },
    },
    {
        { {  INT32_C(  1295712301), -INT32_C(    11467004) },
          { -INT32_C(   270143442), -INT32_C(   281830490) },
          {  INT32_C(   355950844),  INT32_C(   899726683) } },
    },
    {
        { { -INT32_C(  1263284316),  INT32_C(  2140080722) },
          {  INT32_C(   265079306),  INT32_C(      925394) },
          { -INT32_C(  1259343090), -INT32_C(  1952177521) } },
    },
    {
        { { -INT32_C(   559883389),  INT32_C(  1024671896) },
          {  INT32_C(  1643234831), -INT32_C(   606043696) },
          {  INT32_C(   501919051), -INT32_C(   652347189) } },
    },
    {
        { {  INT32_C(  2072841708), -INT32_C(  1308217041) },
          { -INT32_C(  1517246708), -INT32_C(   136141593) },
          {  INT32_C(   995677034), -INT32_C(  1609156268) } },
    },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x2x3_t a = simde_vld3_s32(test_vec[i].r[0]);
    int32_t r_[3][2];
    simde_vst3_s32(r_[0], a);
    simde_test_arm_neon_assert_equal_i32x2(simde_vld1_s32(r_[0]), simde_vld1_s32(test_vec[i].r[0]));
    simde_test_arm_neon_assert_equal_i32x2(simde_vld1_s32(r_[1]), simde_vld1_s32(test_vec[i].r[1]));
    simde_test_arm_neon_assert_equal_i32x2(simde_vld1_s32(r_[2]), simde_vld1_s32(test_vec[i].r[2]));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int32x2x3_t a = { { simde_test_arm_neon_random_i32x2(),
                              simde_test_arm_neon_random_i32x2(),
                              simde_test_arm_neon_random_i32x2(), } };
    simde_test_arm_neon_write_i32x2x3(2, a, SIMDE_TEST_VEC_POS_FIRST);
  }
  return 1;
#endif
}

static int
test_simde_vst3_s64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int64_t r[3][1];
  } test_vec[] = {
    {
        { { -INT64_C(  406404427608087546) },
          { -INT64_C( 5505834001930946931) },
          {  INT64_C(  893831862051522656) } },
    },
    {
        { { -INT64_C( 1385834458675211214) },
          { -INT64_C( 4469592604627629142) },
          {  INT64_C( 6206192238057987144) } },
    },
    {
        { {  INT64_C( 6556819020846768539) },
          {  INT64_C( 6513925451035388308) },
          { -INT64_C(  856721127910089945) } },
    },
    {
        { { -INT64_C( 4235493428355311636) },
          {  INT64_C( 7252684156154892323) },
          {  INT64_C( 4676781614592622046) } },
    },
    {
        { {  INT64_C( 8989386688767409951) },
          { -INT64_C( 4107680182329007601) },
          {  INT64_C( 5196230838556210663) } },
    },
    {
        { {  INT64_C( 6777844045983382197) },
          {  INT64_C( 8145300209567181820) },
          { -INT64_C( 1911873704956369139) } },
    },
    {
        { { -INT64_C(  716151223067309731) },
          { -INT64_C( 7038891321745611341) },
          {  INT64_C( 8310324828891216768) } },
    },
    {
        { {  INT64_C(  323866267836743323) },
          { -INT64_C( 8765170548770858205) },
          {  INT64_C( 8431242033170489536) } },
    },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int64x1x3_t a = simde_vld3_s64(test_vec[i].r[0]);
    int64_t r_[3][1];
    simde_vst3_s64(r_[0], a);
    simde_test_arm_neon_assert_equal_i64x1(simde_vld1_s64(r_[0]), simde_vld1_s64(test_vec[i].r[0]));
    simde_test_arm_neon_assert_equal_i64x1(simde_vld1_s64(r_[1]), simde_vld1_s64(test_vec[i].r[1]));
    simde_test_arm_neon_assert_equal_i64x1(simde_vld1_s64(r_[2]), simde_vld1_s64(test_vec[i].r[2]));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int64x1x3_t a = { { simde_test_arm_neon_random_i64x1(),
                              simde_test_arm_neon_random_i64x1(),
                              simde_test_arm_neon_random_i64x1(), } };
    simde_test_arm_neon_write_i64x1x3(2, a, SIMDE_TEST_VEC_POS_FIRST);
  }
  return 1;
#endif
}

static int
test_simde_vst3_u8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint8_t r[3][8];
  } test_vec[] = {
    {
        { { UINT8_C(141), UINT8_C(240), UINT8_C( 91), UINT8_C(143), UINT8_C( 21), UINT8_C( 12), UINT8_C(197), UINT8_C(229) },
          { UINT8_C(213), UINT8_C(120), UINT8_C( 32), UINT8_C(171), UINT8_C(148), UINT8_C(229), UINT8_C( 92), UINT8_C(137) },
          { UINT8_C( 98), UINT8_C(167), UINT8_C( 87), UINT8_C(102), UINT8_C(112), UINT8_C(160), UINT8_C(101), UINT8_C(205) } },
    },
    {
        { { UINT8_C( 43), UINT8_C( 85), UINT8_C(100), UINT8_C(180), UINT8_C( 90), UINT8_C( 14), UINT8_C(118), UINT8_C(231) },
          { UINT8_C(254), UINT8_C(209), UINT8_C(118), UINT8_C( 19), UINT8_C(221), UINT8_C( 59), UINT8_C(248), UINT8_C(178) },
          { UINT8_C(179), UINT8_C( 25), UINT8_C( 94), UINT8_C( 71), UINT8_C(254), UINT8_C(186), UINT8_C(209), UINT8_C( 96) } },
    },
    {
        { { UINT8_C( 98), UINT8_C( 40), UINT8_C(199), UINT8_C(210), UINT8_C(200), UINT8_C( 44), UINT8_C(159), UINT8_C(243) },
          { UINT8_C(129), UINT8_C(  3), UINT8_C(168), UINT8_C(219), UINT8_C( 17), UINT8_C( 30), UINT8_C(195), UINT8_C( 16) },
          { UINT8_C(240), UINT8_C( 57), UINT8_C( 35), UINT8_C(205), UINT8_C(117), UINT8_C( 28), UINT8_C(128), UINT8_C( 40) } },
    },
    {
        { { UINT8_C( 53), UINT8_C(222), UINT8_C(112), UINT8_C( 51), UINT8_C(152), UINT8_C( 65), UINT8_C(147), UINT8_C(250) },
          { UINT8_C(105), UINT8_C( 90), UINT8_C(204), UINT8_C( 49), UINT8_C(135), UINT8_C(108), UINT8_C( 37), UINT8_C(  8) },
          { UINT8_C(111), UINT8_C(205), UINT8_C(228), UINT8_C(129), UINT8_C(235), UINT8_C(167), UINT8_C(145), UINT8_C(219) } },
    },
    {
        { { UINT8_C(224), UINT8_C(180), UINT8_C(169), UINT8_C( 85), UINT8_C(208), UINT8_C( 41), UINT8_C(126), UINT8_C(  5) },
          { UINT8_C(  7), UINT8_C(238), UINT8_C( 56), UINT8_C(159), UINT8_C( 47), UINT8_C(204), UINT8_C(154), UINT8_C(152) },
          { UINT8_C( 38), UINT8_C(102), UINT8_C(201), UINT8_C(173), UINT8_C(210), UINT8_C(238), UINT8_C(182), UINT8_C( 66) } },
    },
    {
        { { UINT8_C(187), UINT8_C(154), UINT8_C(195), UINT8_C(167), UINT8_C( 65), UINT8_C( 84), UINT8_C(130), UINT8_C( 33) },
          { UINT8_C(  8), UINT8_C( 43), UINT8_C(119), UINT8_C(217), UINT8_C( 84), UINT8_C(245), UINT8_C(222), UINT8_C( 91) },
          { UINT8_C(227), UINT8_C( 23), UINT8_C(251), UINT8_C( 18), UINT8_C(227), UINT8_C(149), UINT8_C(170), UINT8_C(  9) } },
    },
    {
        { { UINT8_C(251), UINT8_C(115), UINT8_C(183), UINT8_C(206), UINT8_C( 98), UINT8_C(109), UINT8_C( 16), UINT8_C( 29) },
          { UINT8_C(  7), UINT8_C(211), UINT8_C(196), UINT8_C( 72), UINT8_C( 39), UINT8_C( 71), UINT8_C(105), UINT8_C( 47) },
          { UINT8_C(114), UINT8_C(224), UINT8_C(  8), UINT8_C(199), UINT8_C(213), UINT8_C(231), UINT8_C( 34), UINT8_C(184) } },
    },
    {
        { { UINT8_C(254), UINT8_C( 29), UINT8_C(202), UINT8_C(225), UINT8_C(178), UINT8_C(116), UINT8_C(234), UINT8_C(174) },
          { UINT8_C(232), UINT8_C(161), UINT8_C(124), UINT8_C( 74), UINT8_C( 14), UINT8_C(140), UINT8_C(103), UINT8_C( 21) },
          { UINT8_C( 95), UINT8_C( 44), UINT8_C( 93), UINT8_C(134), UINT8_C(115), UINT8_C(199), UINT8_C(181), UINT8_C(229) } },
    },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint8x8x3_t a = simde_vld3_u8(test_vec[i].r[0]);
    uint8_t r_[3][8];
    simde_vst3_u8(r_[0], a);
    simde_test_arm_neon_assert_equal_u8x8(simde_vld1_u8(r_[0]), simde_vld1_u8(test_vec[i].r[0]));
    simde_test_arm_neon_assert_equal_u8x8(simde_vld1_u8(r_[1]), simde_vld1_u8(test_vec[i].r[1]));
    simde_test_arm_neon_assert_equal_u8x8(simde_vld1_u8(r_[2]), simde_vld1_u8(test_vec[i].r[2]));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint8x8x3_t a = { { simde_test_arm_neon_random_u8x8(),
                              simde_test_arm_neon_random_u8x8(),
                              simde_test_arm_neon_random_u8x8(), } };
    simde_test_arm_neon_write_u8x8x3(2, a, SIMDE_TEST_VEC_POS_FIRST);
  }
  return 1;
#endif
}

static int
test_simde_vst3_u16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint16_t r[3][4];
  } test_vec[] = {
    {
        { { UINT16_C(31580), UINT16_C(45240), UINT16_C(48244), UINT16_C(55401) },
          { UINT16_C(53205), UINT16_C(16337), UINT16_C(40129), UINT16_C(48272) },
          { UINT16_C(59082), UINT16_C(39938), UINT16_C(28189), UINT16_C(55248) } },
    },
    {
        { { UINT16_C( 7882), UINT16_C(28856), UINT16_C(24291), UINT16_C(16334) },
          { UINT16_C(34521), UINT16_C(19952), UINT16_C(22850), UINT16_C( 6181) },
          { UINT16_C(63272), UINT16_C(59991), UINT16_C(59283), UINT16_C(23974) } },
    },
    {
        { { UINT16_C(43214), UINT16_C(60410), UINT16_C(51735), UINT16_C(57794) },
          { UINT16_C(31721), UINT16_C(52305), UINT16_C( 8153), UINT16_C(45836) },
          { UINT16_C(64677), UINT16_C(59392), UINT16_C( 9813), UINT16_C(32000) } },
    },
    {
        { { UINT16_C(22301), UINT16_C(45159), UINT16_C( 3391), UINT16_C( 3341) },
          { UINT16_C( 1974), UINT16_C(52728), UINT16_C(48082), UINT16_C(48046) },
          { UINT16_C(   54), UINT16_C( 3975), UINT16_C(37663), UINT16_C(50626) } },
    },
    {
        { { UINT16_C(50063), UINT16_C(58541), UINT16_C(44521), UINT16_C( 1634) },
          { UINT16_C(51460), UINT16_C(17334), UINT16_C(50135), UINT16_C(36176) },
          { UINT16_C(18891), UINT16_C(40282), UINT16_C( 2052), UINT16_C(14936) } },
    },
    {
        { { UINT16_C(57096), UINT16_C(10313), UINT16_C( 3187), UINT16_C(  749) },
          { UINT16_C(39631), UINT16_C(47335), UINT16_C(18759), UINT16_C(19390) },
          { UINT16_C(29714), UINT16_C(59791), UINT16_C(57143), UINT16_C(  630) } },
    },
    {
        { { UINT16_C(53288), UINT16_C(11423), UINT16_C(63449), UINT16_C(57702) },
          { UINT16_C(45271), UINT16_C(18953), UINT16_C(63164), UINT16_C(35660) },
          { UINT16_C(13200), UINT16_C(55107), UINT16_C(  380), UINT16_C(36643) } },
    },
    {
        { { UINT16_C(45685), UINT16_C(44152), UINT16_C(61329), UINT16_C(47791) },
          { UINT16_C(20159), UINT16_C(39142), UINT16_C(19782), UINT16_C( 7546) },
          { UINT16_C(33789), UINT16_C(47463), UINT16_C(45946), UINT16_C( 2628) } },
    },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint16x4x3_t a = simde_vld3_u16(test_vec[i].r[0]);
    uint16_t r_[3][4];
    simde_vst3_u16(r_[0], a);
    simde_test_arm_neon_assert_equal_u16x4(simde_vld1_u16(r_[0]), simde_vld1_u16(test_vec[i].r[0]));
    simde_test_arm_neon_assert_equal_u16x4(simde_vld1_u16(r_[1]), simde_vld1_u16(test_vec[i].r[1]));
    simde_test_arm_neon_assert_equal_u16x4(simde_vld1_u16(r_[2]), simde_vld1_u16(test_vec[i].r[2]));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint16x4x3_t a = { { simde_test_arm_neon_random_u16x4(),
                               simde_test_arm_neon_random_u16x4(),
                               simde_test_arm_neon_random_u16x4(), } };
    simde_test_arm_neon_write_u16x4x3(2, a, SIMDE_TEST_VEC_POS_FIRST);
  }
  return 1;
#endif
}

static int
test_simde_vst3_u32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint32_t r[3][2];
  } test_vec[] = {
    {
        { { UINT32_C(3898263705), UINT32_C(4253068479) },
          { UINT32_C(2900873406), UINT32_C(2941577262) },
          { UINT32_C( 147747937), UINT32_C(  71597277) } },
    },
    {
        { { UINT32_C( 305305389), UINT32_C(2791717389) },
          { UINT32_C(3247357954), UINT32_C( 733875820) },
          { UINT32_C( 232236766), UINT32_C(4038864014) } },
    },
    {
        { { UINT32_C(2113440416), UINT32_C( 880884742) },
          { UINT32_C(3779507156), UINT32_C(4018646253) },
          { UINT32_C(3652195692), UINT32_C(  17067811) } },
    },
    {
        { { UINT32_C(2735659797), UINT32_C(2811480839) },
          { UINT32_C(1545899093), UINT32_C(2626725320) },
          { UINT32_C(1165874776), UINT32_C(3996386434) } },
    },
    {
        { { UINT32_C(1019733273), UINT32_C(1765722964) },
          { UINT32_C(2920041639), UINT32_C(1834393623) },
          { UINT32_C(4106844716), UINT32_C(2022791456) } },
    },
    {
        { { UINT32_C(2982022703), UINT32_C( 748679699) },
          { UINT32_C( 728328151), UINT32_C(3650398002) },
          { UINT32_C( 193503731), UINT32_C(1836637761) } },
    },
    {
        { { UINT32_C(2019639640), UINT32_C(3388076698) },
          { UINT32_C( 343584513), UINT32_C(2034244001) },
          { UINT32_C(3013912960), UINT32_C(1150040400) } },
    },
    {
        { { UINT32_C( 458167514), UINT32_C(1267255282) },
          { UINT32_C(2730748168), UINT32_C(3714823388) },
          { UINT32_C(  99738979), UINT32_C(2138976766) } },
    },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint32x2x3_t a = simde_vld3_u32(test_vec[i].r[0]);
    uint32_t r_[3][2];
    simde_vst3_u32(r_[0], a);
    simde_test_arm_neon_assert_equal_u32x2(simde_vld1_u32(r_[0]), simde_vld1_u32(test_vec[i].r[0]));
    simde_test_arm_neon_assert_equal_u32x2(simde_vld1_u32(r_[1]), simde_vld1_u32(test_vec[i].r[1]));
    simde_test_arm_neon_assert_equal_u32x2(simde_vld1_u32(r_[2]), simde_vld1_u32(test_vec[i].r[2]));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint32x2x3_t a = { { simde_test_arm_neon_random_u32x2(),
                               simde_test_arm_neon_random_u32x2(),
                               simde_test_arm_neon_random_u32x2(), } };
    simde_test_arm_neon_write_u32x2x3(2, a, SIMDE_TEST_VEC_POS_FIRST);
  }
  return 1;
#endif
}

static int
test_simde_vst3_u64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint64_t r[3][1];
  } test_vec[] = {
    {
        { { UINT64_C(15789501704054640379) },
          { UINT64_C( 7466887149545453677) },
          { UINT64_C(16429816211507043145) } },
    },
    {
        { { UINT64_C(16434954356342722899) },
          { UINT64_C(12735543420519362237) },
          { UINT64_C( 5866622445306204853) } },
    },
    {
        { { UINT64_C(   70359591970684746) },
          { UINT64_C(17858261510127979016) },
          { UINT64_C(16639838761917117432) } },
    },
    {
        { { UINT64_C( 8305011726943370215) },
          { UINT64_C( 3765151315542947219) },
          { UINT64_C(13275761500987159819) } },
    },
    {
        { { UINT64_C(10486033231323010158) },
          { UINT64_C( 6212648357052116890) },
          { UINT64_C( 5573440114146066679) } },
    },
    {
        { { UINT64_C(16628361264167550539) },
          { UINT64_C( 3467221504352433890) },
          { UINT64_C( 6382493893077016442) } },
    },
    {
        { { UINT64_C( 5366837197921855980) },
          { UINT64_C(13669015147016162387) },
          { UINT64_C(13588880985525139407) } },
    },
    {
        { { UINT64_C(11727528144729115142) },
          { UINT64_C( 7277616962762390709) },
          { UINT64_C( 4390695645337375830) } },
    },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint64x1x3_t a = simde_vld3_u64(test_vec[i].r[0]);
    uint64_t r_[3][1];
    simde_vst3_u64(r_[0], a);
    simde_test_arm_neon_assert_equal_u64x1(simde_vld1_u64(r_[0]), simde_vld1_u64(test_vec[i].r[0]));
    simde_test_arm_neon_assert_equal_u64x1(simde_vld1_u64(r_[1]), simde_vld1_u64(test_vec[i].r[1]));
    simde_test_arm_neon_assert_equal_u64x1(simde_vld1_u64(r_[2]), simde_vld1_u64(test_vec[i].r[2]));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint64x1x3_t a = { { simde_test_arm_neon_random_u64x1(),
                               simde_test_arm_neon_random_u64x1(),
                               simde_test_arm_neon_random_u64x1(), } };
    simde_test_arm_neon_write_u64x1x3(2, a, SIMDE_TEST_VEC_POS_FIRST);
  }
  return 1;
#endif
}

static int
test_simde_vst3q_f32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float32 r[3][4];
  } test_vec[] = {
    {
        { { SIMDE_FLOAT32_C(   306.99), SIMDE_FLOAT32_C(  -739.77), SIMDE_FLOAT32_C(  -728.18), SIMDE_FLOAT32_C(   488.86) },
          { SIMDE_FLOAT32_C(  -393.31), SIMDE_FLOAT32_C(   589.07), SIMDE_FLOAT32_C(  -849.91), SIMDE_FLOAT32_C(   333.90) },
          { SIMDE_FLOAT32_C(    46.56), SIMDE_FLOAT32_C(   612.95), SIMDE_FLOAT32_C(    -7.21), SIMDE_FLOAT32_C(  -296.72) } },
    },
    {
        { { SIMDE_FLOAT32_C(  -612.74), SIMDE_FLOAT32_C(  -155.69), SIMDE_FLOAT32_C(   885.57), SIMDE_FLOAT32_C(  -226.79) },
          { SIMDE_FLOAT32_C(   437.49), SIMDE_FLOAT32_C(  -396.59), SIMDE_FLOAT32_C(   284.25), SIMDE_FLOAT32_C(  -899.95) },
          { SIMDE_FLOAT32_C(  -935.21), SIMDE_FLOAT32_C(  -204.05), SIMDE_FLOAT32_C(   972.74), SIMDE_FLOAT32_C(  -484.76) } },
    },
    {
        { { SIMDE_FLOAT32_C(    89.60), SIMDE_FLOAT32_C(  -815.10), SIMDE_FLOAT32_C(   758.50), SIMDE_FLOAT32_C(  -315.00) },
          { SIMDE_FLOAT32_C(   529.62), SIMDE_FLOAT32_C(   765.35), SIMDE_FLOAT32_C(   917.99), SIMDE_FLOAT32_C(  -163.40) },
          { SIMDE_FLOAT32_C(  -974.42), SIMDE_FLOAT32_C(  -810.19), SIMDE_FLOAT32_C(  -674.53), SIMDE_FLOAT32_C(  -367.73) } },
    },
    {
        { { SIMDE_FLOAT32_C(   778.89), SIMDE_FLOAT32_C(  -524.44), SIMDE_FLOAT32_C(   966.17), SIMDE_FLOAT32_C(  -174.56) },
          { SIMDE_FLOAT32_C(  -911.49), SIMDE_FLOAT32_C(   -41.04), SIMDE_FLOAT32_C(   528.72), SIMDE_FLOAT32_C(  -524.23) },
          { SIMDE_FLOAT32_C(   803.27), SIMDE_FLOAT32_C(   414.29), SIMDE_FLOAT32_C(   248.98), SIMDE_FLOAT32_C(   240.76) } },
    },
    {
        { { SIMDE_FLOAT32_C(  -982.30), SIMDE_FLOAT32_C(  -466.76), SIMDE_FLOAT32_C(   340.81), SIMDE_FLOAT32_C(  -917.51) },
          { SIMDE_FLOAT32_C(   329.19), SIMDE_FLOAT32_C(   313.55), SIMDE_FLOAT32_C(  -402.28), SIMDE_FLOAT32_C(  -581.21) },
          { SIMDE_FLOAT32_C(   498.45), SIMDE_FLOAT32_C(  -643.77), SIMDE_FLOAT32_C(   103.79), SIMDE_FLOAT32_C(    28.07) } },
    },
    {
        { { SIMDE_FLOAT32_C(  -878.42), SIMDE_FLOAT32_C(    21.78), SIMDE_FLOAT32_C(   864.67), SIMDE_FLOAT32_C(  -852.85) },
          { SIMDE_FLOAT32_C(   211.59), SIMDE_FLOAT32_C(  -809.86), SIMDE_FLOAT32_C(  -220.58), SIMDE_FLOAT32_C(    -9.52) },
          { SIMDE_FLOAT32_C(  -334.30), SIMDE_FLOAT32_C(  -254.40), SIMDE_FLOAT32_C(   815.92), SIMDE_FLOAT32_C(  -245.78) } },
    },
    {
        { { SIMDE_FLOAT32_C(   704.56), SIMDE_FLOAT32_C(   344.64), SIMDE_FLOAT32_C(   229.99), SIMDE_FLOAT32_C(   507.83) },
          { SIMDE_FLOAT32_C(  -241.07), SIMDE_FLOAT32_C(  -521.02), SIMDE_FLOAT32_C(  -251.41), SIMDE_FLOAT32_C(  -223.38) },
          { SIMDE_FLOAT32_C(    12.21), SIMDE_FLOAT32_C(  -910.60), SIMDE_FLOAT32_C(  -140.89), SIMDE_FLOAT32_C(  -658.60) } },
    },
    {
        { { SIMDE_FLOAT32_C(   402.95), SIMDE_FLOAT32_C(   456.83), SIMDE_FLOAT32_C(  -239.81), SIMDE_FLOAT32_C(   -98.60) },
          { SIMDE_FLOAT32_C(   813.06), SIMDE_FLOAT32_C(   863.98), SIMDE_FLOAT32_C(   929.47), SIMDE_FLOAT32_C(   934.64) },
          { SIMDE_FLOAT32_C(  -114.24), SIMDE_FLOAT32_C(   794.14), SIMDE_FLOAT32_C(  -918.21), SIMDE_FLOAT32_C(  -902.65) } },
    },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x4x3_t a = simde_vld3q_f32(test_vec[i].r[0]);
    simde_float32_t r_[3][4];
    simde_vst3q_f32(r_[0], a);
    simde_test_arm_neon_assert_equal_f32x4(simde_vld1q_f32(r_[0]), simde_vld1q_f32(test_vec[i].r[0]), 1);
    simde_test_arm_neon_assert_equal_f32x4(simde_vld1q_f32(r_[1]), simde_vld1q_f32(test_vec[i].r[1]), 1);
    simde_test_arm_neon_assert_equal_f32x4(simde_vld1q_f32(r_[2]), simde_vld1q_f32(test_vec[i].r[2]), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float32x4x3_t a = { { simde_test_arm_neon_random_f32x4(-1000.0f, 1000.0f),
                                simde_test_arm_neon_random_f32x4(-1000.0f, 1000.0f),
                                simde_test_arm_neon_random_f32x4(-1000.0f, 1000.0f), } };
    simde_test_arm_neon_write_f32x4x3(2, a, SIMDE_TEST_VEC_POS_FIRST);
  }
  return 1;
#endif
}

static int
test_simde_vst3q_f64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float64 r[3][2];
  } test_vec[] = {
    {
        { { SIMDE_FLOAT64_C(   514.43), SIMDE_FLOAT64_C(   640.29) },
          { SIMDE_FLOAT64_C(   135.00), SIMDE_FLOAT64_C(    21.80) },
          { SIMDE_FLOAT64_C(   -39.40), SIMDE_FLOAT64_C(   544.73) } },
    },
    {
        { { SIMDE_FLOAT64_C(   264.10), SIMDE_FLOAT64_C(  -617.18) },
          { SIMDE_FLOAT64_C(   458.01), SIMDE_FLOAT64_C(   -92.97) },
          { SIMDE_FLOAT64_C(   361.07), SIMDE_FLOAT64_C(   182.08) } },
    },
    {
        { { SIMDE_FLOAT64_C(   826.88), SIMDE_FLOAT64_C(  -734.27) },
          { SIMDE_FLOAT64_C(   117.13), SIMDE_FLOAT64_C(   941.67) },
          { SIMDE_FLOAT64_C(  -144.49), SIMDE_FLOAT64_C(    63.36) } },
    },
    {
        { { SIMDE_FLOAT64_C(    82.62), SIMDE_FLOAT64_C(   663.09) },
          { SIMDE_FLOAT64_C(  -197.23), SIMDE_FLOAT64_C(  -822.35) },
          { SIMDE_FLOAT64_C(  -775.24), SIMDE_FLOAT64_C(  -832.91) } },
    },
    {
        { { SIMDE_FLOAT64_C(  -255.19), SIMDE_FLOAT64_C(  -758.38) },
          { SIMDE_FLOAT64_C(    19.80), SIMDE_FLOAT64_C(   -77.83) },
          { SIMDE_FLOAT64_C(  -875.36), SIMDE_FLOAT64_C(  -945.72) } },
    },
    {
        { { SIMDE_FLOAT64_C(  -150.10), SIMDE_FLOAT64_C(   639.07) },
          { SIMDE_FLOAT64_C(   694.57), SIMDE_FLOAT64_C(   984.90) },
          { SIMDE_FLOAT64_C(  -339.13), SIMDE_FLOAT64_C(  -344.83) } },
    },
    {
        { { SIMDE_FLOAT64_C(   529.63), SIMDE_FLOAT64_C(   924.97) },
          { SIMDE_FLOAT64_C(    37.98), SIMDE_FLOAT64_C(   -12.36) },
          { SIMDE_FLOAT64_C(  -168.00), SIMDE_FLOAT64_C(  -600.95) } },
    },
    {
        { { SIMDE_FLOAT64_C(  -830.28), SIMDE_FLOAT64_C(  -341.12) },
          { SIMDE_FLOAT64_C(  -335.22), SIMDE_FLOAT64_C(   286.85) },
          { SIMDE_FLOAT64_C(  -399.45), SIMDE_FLOAT64_C(   520.29) } },
    },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float64x2x3_t a = simde_vld3q_f64(test_vec[i].r[0]);
    simde_float64_t r_[3][2];
    simde_vst3q_f64(r_[0], a);
    simde_test_arm_neon_assert_equal_f64x2(simde_vld1q_f64(r_[0]), simde_vld1q_f64(test_vec[i].r[0]), 1);
    simde_test_arm_neon_assert_equal_f64x2(simde_vld1q_f64(r_[1]), simde_vld1q_f64(test_vec[i].r[1]), 1);
    simde_test_arm_neon_assert_equal_f64x2(simde_vld1q_f64(r_[2]), simde_vld1q_f64(test_vec[i].r[2]), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float64x2x3_t a = { { simde_test_arm_neon_random_f64x2(-1000.0, 1000.0),
                                simde_test_arm_neon_random_f64x2(-1000.0, 1000.0),
                                simde_test_arm_neon_random_f64x2(-1000.0, 1000.0), } };
    simde_test_arm_neon_write_f64x2x3(2, a, SIMDE_TEST_VEC_POS_FIRST);
  }
  return 1;
#endif
}

static int
test_simde_vst3q_s8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int8_t r[3][16];
  } test_vec[] = {
    {
        { {  INT8_C(  34),  INT8_C(  38),  INT8_C(  10),  INT8_C(  31),  INT8_C(  81), -INT8_C(  48),  INT8_C(  18), -INT8_C(  66),
             INT8_C(  51),  INT8_C( 114), -INT8_C( 107), -INT8_C( 112), -INT8_C(  73), -INT8_C(  81),  INT8_C( 125), -INT8_C(  41) },
          {  INT8_C( 108), -INT8_C(  13), -INT8_C(   6), -INT8_C(  55), -INT8_C(  29),  INT8_C(  70),  INT8_C(  62), -INT8_C(  49),
            -INT8_C( 118), -INT8_C(  82), -INT8_C(  33),  INT8_C(  89), -INT8_C(  68), -INT8_C(  86), -INT8_C(  42), -INT8_C(  34) },
          { -INT8_C(  48), -INT8_C(  32), -INT8_C(   3),  INT8_C(  33), -INT8_C(  79),  INT8_C(  16), -INT8_C(  33), -INT8_C(  28),
            -INT8_C( 126),  INT8_C( 117),  INT8_C( 116),  INT8_C(  57),  INT8_C(  36), -INT8_C(  15),  INT8_C(  16), -INT8_C( 112) } },
    },
    {
        { { -INT8_C(  27),  INT8_C(  10),  INT8_C(  89), -INT8_C(  56),  INT8_C(  80), -INT8_C( 104), -INT8_C( 104), -INT8_C(  37),
             INT8_C(  70),  INT8_C( 119),  INT8_C(  52),  INT8_C(   2),  INT8_C(  33),  INT8_C(  10), -INT8_C(  32), -INT8_C(  15) },
          { -INT8_C(  22), -INT8_C(  34),  INT8_C(  19), -INT8_C( 101), -INT8_C(  18), -INT8_C(  14),      INT8_MAX,  INT8_C( 112),
             INT8_C( 103), -INT8_C(  12), -INT8_C(  87), -INT8_C( 116), -INT8_C(  27), -INT8_C(  71),  INT8_C(  28), -INT8_C(  54) },
          { -INT8_C(  60),  INT8_C( 118), -INT8_C( 109),  INT8_C(  20),  INT8_C(  14),  INT8_C(  43), -INT8_C(  17),  INT8_C(  84),
            -INT8_C(  94),  INT8_C(  35),  INT8_C(  86), -INT8_C(  60),  INT8_C(  45),  INT8_C(  54), -INT8_C(  75),  INT8_C(  24) } },
    },
    {
        { {  INT8_C(  20), -INT8_C(  56), -INT8_C(  77),  INT8_C(   2), -INT8_C(  69),  INT8_C(  51),  INT8_C( 114),  INT8_C(  34),
             INT8_C(  39),  INT8_C(  27), -INT8_C(  82),  INT8_C(  12), -INT8_C(  43), -INT8_C(  53), -INT8_C(  41), -INT8_C( 103) },
          {  INT8_C(  65),  INT8_C( 106), -INT8_C(  83),  INT8_C(  79), -INT8_C( 107), -INT8_C(  99), -INT8_C(  93),  INT8_C(  55),
            -INT8_C(  64), -INT8_C(   7), -INT8_C(   5), -INT8_C(  18),  INT8_C(  47), -INT8_C(  79),  INT8_C(   6),  INT8_C(  68) },
          {  INT8_C( 121), -INT8_C(  71),  INT8_C(  70),  INT8_C(  52), -INT8_C(  20), -INT8_C(  71),  INT8_C(  87),  INT8_C(  19),
            -INT8_C(  44),  INT8_C(   5),  INT8_C(  32), -INT8_C(  87), -INT8_C(  48), -INT8_C(   9),  INT8_C(  66),  INT8_C(  17) } },
    },
    {
        { {  INT8_C(  97), -INT8_C(  16),  INT8_C(  96), -INT8_C(  10), -INT8_C( 115),  INT8_C(   3),  INT8_C(  45),  INT8_C(  77),
            -INT8_C(   4),  INT8_C(  41),  INT8_C(  59),  INT8_C(  44), -INT8_C(  38),  INT8_C(  65),  INT8_C( 112),  INT8_C(  83) },
          { -INT8_C(   5), -INT8_C(  74), -INT8_C( 120), -INT8_C(  25),  INT8_C( 111), -INT8_C(  33), -INT8_C(   5),  INT8_C(  68),
            -INT8_C(  28),  INT8_C(  27), -INT8_C(  19), -INT8_C(  75),  INT8_C(  18),  INT8_C(  48), -INT8_C(  58),  INT8_C( 115) },
          {  INT8_C(  32),  INT8_C(  39),  INT8_C( 105), -INT8_C(  83),  INT8_C(  42), -INT8_C( 106), -INT8_C(   6),  INT8_C(  39),
            -INT8_C(  65),  INT8_C(  54),  INT8_C(  83), -INT8_C( 103),  INT8_C( 119), -INT8_C(  61), -INT8_C(  19),  INT8_C( 114) } },
    },
    {
        { {  INT8_C( 121),  INT8_C( 117),  INT8_C(  90), -INT8_C(  23),  INT8_C(  84),  INT8_C(  85),  INT8_C(  45),  INT8_C(  56),
             INT8_C( 112),  INT8_C(  26), -INT8_C(  19), -INT8_C( 126),  INT8_C(  74), -INT8_C(  76), -INT8_C(  11),  INT8_C( 106) },
          { -INT8_C(  37),  INT8_C(  94),  INT8_C(  23),  INT8_C(   5), -INT8_C(  12),  INT8_C(  18),  INT8_C(  44), -INT8_C(  76),
             INT8_C(  72),      INT8_MAX,  INT8_C(  77), -INT8_C(  65),  INT8_C(  66),  INT8_C(  58),  INT8_C(  50), -INT8_C(  68) },
          { -INT8_C(  81), -INT8_C( 116), -INT8_C(  91),  INT8_C(   3), -INT8_C(  31), -INT8_C(  46),  INT8_C(  60),  INT8_C(  81),
            -INT8_C(  20),  INT8_C(  41), -INT8_C(  45),  INT8_C(  55), -INT8_C(  35), -INT8_C(  56), -INT8_C(  95), -INT8_C(  72) } },
    },
    {
        { {  INT8_C(  38), -INT8_C(  71), -INT8_C(  66),  INT8_C(  26), -INT8_C(  53), -INT8_C(  22), -INT8_C(  50),  INT8_C(  19),
             INT8_C( 106),  INT8_C(  28), -INT8_C(  46), -INT8_C(  84),  INT8_C(  86),  INT8_C(   4),  INT8_C( 104),  INT8_C(   6) },
          { -INT8_C( 112),  INT8_C(  13),  INT8_C(   9),  INT8_C( 113), -INT8_C(  33),  INT8_C(  69), -INT8_C(  62), -INT8_C(  52),
             INT8_C( 111), -INT8_C( 107),  INT8_C(   3),  INT8_C(  76),  INT8_C(  93), -INT8_C(  92),  INT8_C(   5), -INT8_C( 125) },
          {  INT8_C(  93), -INT8_C(  61), -INT8_C(  98),  INT8_C(  40), -INT8_C(  83),  INT8_C( 108),  INT8_C(  59),  INT8_C(  23),
            -INT8_C( 120),  INT8_C(  14), -INT8_C(  60), -INT8_C(  33),  INT8_C(  18),  INT8_C(  44), -INT8_C(  27), -INT8_C(  93) } },
    },
    {
        { {  INT8_C(  58), -INT8_C(  18),  INT8_C(  20),  INT8_C(  25),  INT8_C(  52), -INT8_C(  41), -INT8_C(  27), -INT8_C(  93),
             INT8_C( 108), -INT8_C(  24), -INT8_C(  17), -INT8_C(  54), -INT8_C( 115), -INT8_C(  12),  INT8_C(  77), -INT8_C(  22) },
          { -INT8_C(  73), -INT8_C(  21),  INT8_C(  19),  INT8_C( 101),  INT8_C(  88),  INT8_C(  78),  INT8_C( 124), -INT8_C(  32),
             INT8_C(  92),  INT8_C(  64), -INT8_C(  65),  INT8_C( 111),  INT8_C( 109), -INT8_C(  92),  INT8_C(  18), -INT8_C(  89) },
          { -INT8_C( 109),  INT8_C(  38), -INT8_C(  64), -INT8_C(  57), -INT8_C(   3), -INT8_C(  90),  INT8_C( 106),  INT8_C( 106),
            -INT8_C( 114),  INT8_C(  89),  INT8_C(  52),  INT8_C(  27),  INT8_C(  78), -INT8_C( 127),  INT8_C(   6),  INT8_C(   5) } },
    },
    {
        { {  INT8_C( 109),  INT8_C(  25),  INT8_C( 106), -INT8_C(  59),  INT8_C( 103), -INT8_C(  25), -INT8_C(  91), -INT8_C(  60),
             INT8_C(  39),  INT8_C( 101),  INT8_C(  51), -INT8_C( 108),  INT8_C(   9),  INT8_C(  69),  INT8_C(  59), -INT8_C( 100) },
          {  INT8_C( 107), -INT8_C(   4),  INT8_C(  99),  INT8_C( 105), -INT8_C(  94), -INT8_C(  51), -INT8_C(  45),  INT8_C(  48),
             INT8_C(  39),  INT8_C(   7),  INT8_C(  76),  INT8_C( 117), -INT8_C( 120),  INT8_C(  82),  INT8_C( 122), -INT8_C(  11) },
          {  INT8_C( 107), -INT8_C(  27), -INT8_C(  70), -INT8_C(  46), -INT8_C(  52),  INT8_C(  96), -INT8_C( 106), -INT8_C(  13),
            -INT8_C(  59), -INT8_C(  55), -INT8_C( 120), -INT8_C(  50),  INT8_C(  14), -INT8_C(  61),  INT8_C( 107),  INT8_C( 122) } },
    },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int8x16x3_t a = simde_vld3q_s8(test_vec[i].r[0]);
    int8_t r_[3][16];
    simde_vst3q_s8(r_[0], a);
    simde_test_arm_neon_assert_equal_i8x16(simde_vld1q_s8(r_[0]), simde_vld1q_s8(test_vec[i].r[0]));
    simde_test_arm_neon_assert_equal_i8x16(simde_vld1q_s8(r_[1]), simde_vld1q_s8(test_vec[i].r[1]));
    simde_test_arm_neon_assert_equal_i8x16(simde_vld1q_s8(r_[2]), simde_vld1q_s8(test_vec[i].r[2]));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int8x16x3_t a = { { simde_test_arm_neon_random_i8x16(),
                              simde_test_arm_neon_random_i8x16(),
                              simde_test_arm_neon_random_i8x16(), } };
    simde_test_arm_neon_write_i8x16x3(2, a, SIMDE_TEST_VEC_POS_FIRST);
  }
  return 1;
#endif
}

static int
test_simde_vst3q_s16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int16_t r[3][8];
  } test_vec[] = {
    {
        { { -INT16_C( 10425), -INT16_C( 25927),  INT16_C(  5009),  INT16_C( 14559),  INT16_C( 25678),  INT16_C(  2739), -INT16_C( 28300), -INT16_C(  8867) },
          { -INT16_C( 21978), -INT16_C( 19696), -INT16_C( 18017), -INT16_C(  3465),  INT16_C( 15749), -INT16_C( 27871), -INT16_C( 16573), -INT16_C( 30049) },
          {  INT16_C( 22679),  INT16_C( 10276),  INT16_C(   876), -INT16_C( 17823),  INT16_C(  5224), -INT16_C(  9020),  INT16_C(  8613), -INT16_C( 13383) } },
    },
    {
        { { -INT16_C( 13877),  INT16_C( 27263), -INT16_C(  2429),  INT16_C(  2141),  INT16_C( 32307),  INT16_C( 30363),  INT16_C( 14910), -INT16_C( 11008) },
          {  INT16_C(  9363), -INT16_C(     3),  INT16_C( 24104), -INT16_C( 28487),  INT16_C( 32115),  INT16_C(  6252),  INT16_C(  9630),  INT16_C( 27108) },
          {  INT16_C( 25582),  INT16_C( 29139),  INT16_C( 12377), -INT16_C( 29319),  INT16_C(  5551), -INT16_C(  4861),  INT16_C(  1103), -INT16_C(  7486) } },
    },
    {
        { { -INT16_C( 16600),  INT16_C( 20705), -INT16_C( 26082), -INT16_C( 28192),  INT16_C( 19479), -INT16_C( 19031), -INT16_C( 29327),  INT16_C( 24606) },
          { -INT16_C(  3344),  INT16_C( 19153),  INT16_C( 19234), -INT16_C( 11817), -INT16_C(  9632), -INT16_C( 20546), -INT16_C( 32546),  INT16_C(  1938) },
          {  INT16_C( 29504),  INT16_C( 24151),  INT16_C( 14350),  INT16_C(  9711), -INT16_C( 26492), -INT16_C(  2341), -INT16_C(  1754),  INT16_C(  5718) } },
    },
    {
        { {  INT16_C( 10219),  INT16_C(  3680),  INT16_C( 14194), -INT16_C( 11553), -INT16_C( 25070), -INT16_C(  3966),  INT16_C(  5150),  INT16_C( 24311) },
          {  INT16_C( 20359), -INT16_C( 27204), -INT16_C( 21625),  INT16_C(  3003), -INT16_C( 27068),  INT16_C( 27137),  INT16_C( 22415),  INT16_C( 31616) },
          { -INT16_C(  7809), -INT16_C(  3703),  INT16_C( 26648),  INT16_C( 10948),  INT16_C( 17926),  INT16_C(  9499),  INT16_C(  4698), -INT16_C(  7805) } },
    },
    {
        { {  INT16_C( 16481), -INT16_C(  6025),  INT16_C( 13035),  INT16_C( 12276), -INT16_C(  2616),  INT16_C( 22425),  INT16_C(  6733), -INT16_C( 13102) },
          {  INT16_C( 23547),  INT16_C(  5053), -INT16_C( 32316), -INT16_C( 13762),  INT16_C( 22983),  INT16_C(  8687),  INT16_C( 29547), -INT16_C( 13053) },
          {  INT16_C( 31411), -INT16_C( 24907), -INT16_C( 22100),  INT16_C( 29902),  INT16_C( 26527), -INT16_C(  4917), -INT16_C( 24959),  INT16_C( 31928) } },
    },
    {
        { {  INT16_C( 30201), -INT16_C( 17008), -INT16_C( 12553), -INT16_C( 16760),  INT16_C( 30503), -INT16_C( 27936), -INT16_C(  7190), -INT16_C( 25249) },
          {  INT16_C(  5469),  INT16_C(  2364),  INT16_C(  2750),  INT16_C( 23933),  INT16_C( 18545), -INT16_C(  3255),  INT16_C(   486), -INT16_C(  8081) },
          { -INT16_C(   137),  INT16_C( 28317),  INT16_C(  9677), -INT16_C(  3028),  INT16_C(  3229), -INT16_C( 30841), -INT16_C(  6417),  INT16_C( 19493) } },
    },
    {
        { {  INT16_C( 25083), -INT16_C( 17835), -INT16_C( 11669), -INT16_C(  9193),  INT16_C( 24859),  INT16_C(   463),  INT16_C( 16226), -INT16_C(  9759) },
          {  INT16_C( 32574),  INT16_C(  3143),  INT16_C( 29860),  INT16_C( 16640), -INT16_C( 30848),  INT16_C( 28873), -INT16_C(  4498),  INT16_C( 27068) },
          {  INT16_C(  4687), -INT16_C( 17885),  INT16_C( 15332), -INT16_C(   106),  INT16_C( 26268), -INT16_C(   511), -INT16_C(  7515), -INT16_C(  7208) } },
    },
    {
        { {  INT16_C(  8033),  INT16_C(  1775), -INT16_C(  3949),  INT16_C(  5191),  INT16_C(  4215), -INT16_C(  6780),  INT16_C( 16638),  INT16_C( 19791) },
          {  INT16_C( 29266),  INT16_C( 14087), -INT16_C( 24915),  INT16_C( 18742),  INT16_C( 14084), -INT16_C( 22200),  INT16_C(  8218),  INT16_C( 31628) },
          {  INT16_C( 31807), -INT16_C( 11391), -INT16_C( 13972), -INT16_C(  7193),  INT16_C( 27609), -INT16_C( 10039),  INT16_C(  6315), -INT16_C(   475) } },
    },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x8x3_t a = simde_vld3q_s16(test_vec[i].r[0]);
    int16_t r_[3][8];
    simde_vst3q_s16(r_[0], a);
    simde_test_arm_neon_assert_equal_i16x8(simde_vld1q_s16(r_[0]), simde_vld1q_s16(test_vec[i].r[0]));
    simde_test_arm_neon_assert_equal_i16x8(simde_vld1q_s16(r_[1]), simde_vld1q_s16(test_vec[i].r[1]));
    simde_test_arm_neon_assert_equal_i16x8(simde_vld1q_s16(r_[2]), simde_vld1q_s16(test_vec[i].r[2]));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int16x8x3_t a = { { simde_test_arm_neon_random_i16x8(),
                              simde_test_arm_neon_random_i16x8(),
                              simde_test_arm_neon_random_i16x8(), } };
    simde_test_arm_neon_write_i16x8x3(2, a, SIMDE_TEST_VEC_POS_FIRST);
  }
  return 1;
#endif
}

static int
test_simde_vst3q_s32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int32_t r[3][4];
  } test_vec[] = {
    {
        { {  INT32_C(  1417668229),  INT32_C(  1107809607), -INT32_C(   921250624),  INT32_C(  1732349749) },
          { -INT32_C(   714719365),  INT32_C(   670118319),  INT32_C(  1269399837), -INT32_C(   795000245) },
          {  INT32_C(  1864637736), -INT32_C(  1297011726),  INT32_C(   897370367), -INT32_C(   761479849) } },
    },
    {
        { { -INT32_C(  1415118084),  INT32_C(  1372821555),  INT32_C(  1704754202), -INT32_C(   432719170) },
          {  INT32_C(  1230330455), -INT32_C(  2047146363),  INT32_C(   632977358),  INT32_C(   821581364) },
          { -INT32_C(  1948475560),  INT32_C(  1390194488), -INT32_C(   373851861),  INT32_C(   181398707) } },
    },
    {
        { { -INT32_C(   866966458), -INT32_C(   112112086), -INT32_C(    98694202), -INT32_C(  1188358559) },
          { -INT32_C(   297531466), -INT32_C(   515890762),  INT32_C(  1305147290),  INT32_C(   710384099) },
          { -INT32_C(   403264835), -INT32_C(  1092597768), -INT32_C(  1279656110), -INT32_C(   882056171) } },
    },
    {
        { { -INT32_C(  1581666069),  INT32_C(  1803745745), -INT32_C(   726119184), -INT32_C(  1560408091) },
          { -INT32_C(  1299581767), -INT32_C(  1922012613),  INT32_C(  2118134121), -INT32_C(   129324019) },
          {  INT32_C(   781779804), -INT32_C(   308732931),  INT32_C(  1287737959),  INT32_C(   468631393) } },
    },
    {
        { { -INT32_C(   288524109),  INT32_C(  1266367970),  INT32_C(  1959377767), -INT32_C(   999484569) },
          {  INT32_C(   351405591), -INT32_C(  1996387550),  INT32_C(  1071039453),  INT32_C(   911918210) },
          {  INT32_C(   505685820), -INT32_C(   882270108), -INT32_C(  1019202725),  INT32_C(  1569172806) } },
    },
    {
        { { -INT32_C(   713983565), -INT32_C(   497061116), -INT32_C(  1205783242),  INT32_C(   921598969) },
          {  INT32_C(   106173346),  INT32_C(   248692403),  INT32_C(   936448753),  INT32_C(  1922390207) },
          { -INT32_C(   699922735), -INT32_C(  1346852999), -INT32_C(   714548772), -INT32_C(   167029164) } },
    },
    {
        { {  INT32_C(   486301801),  INT32_C(   254529054), -INT32_C(  1622737696),  INT32_C(   638770005) },
          {  INT32_C(  1543264994), -INT32_C(   586435583), -INT32_C(   508398707),  INT32_C(   869777097) },
          {  INT32_C(  1011864606), -INT32_C(  2092205406), -INT32_C(   870149769),  INT32_C(  1341273197) } },
    },
    {
        { { -INT32_C(  1884622962),  INT32_C(   829207971), -INT32_C(   233693400), -INT32_C(    81401123) },
          {  INT32_C(  1614247102),  INT32_C(  1726186223), -INT32_C(  2144205293), -INT32_C(   909171654) },
          { -INT32_C(  1218938349),  INT32_C(  1491649839), -INT32_C(  1052050716), -INT32_C(  1564708892) } },
    },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x4x3_t a = simde_vld3q_s32(test_vec[i].r[0]);
    int32_t r_[3][4];
    simde_vst3q_s32(r_[0], a);
    simde_test_arm_neon_assert_equal_i32x4(simde_vld1q_s32(r_[0]), simde_vld1q_s32(test_vec[i].r[0]));
    simde_test_arm_neon_assert_equal_i32x4(simde_vld1q_s32(r_[1]), simde_vld1q_s32(test_vec[i].r[1]));
    simde_test_arm_neon_assert_equal_i32x4(simde_vld1q_s32(r_[2]), simde_vld1q_s32(test_vec[i].r[2]));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int32x4x3_t a = { { simde_test_arm_neon_random_i32x4(),
                              simde_test_arm_neon_random_i32x4(),
                              simde_test_arm_neon_random_i32x4(), } };
    simde_test_arm_neon_write_i32x4x3(2, a, SIMDE_TEST_VEC_POS_FIRST);
  }
  return 1;
#endif
}

static int
test_simde_vst3q_s64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int64_t r[3][2];
  } test_vec[] = {
    {
        { {  INT64_C( 4526164690243662608),  INT64_C( 1342451240730493191) },
          { -INT64_C( 1032874779489033641),  INT64_C( 2480984295370324534) },
          { -INT64_C( 9009152555481148947), -INT64_C( 5878155912669626608) } },
    },
    {
        { {  INT64_C( 3965594298928694330),  INT64_C(  994740404594796185) },
          {  INT64_C( 3123177191882886233),  INT64_C( 2361559545870110144) },
          { -INT64_C(  815364449262716042), -INT64_C( 6246091016670066652) } },
    },
    {
        { { -INT64_C( 7295315886087530118), -INT64_C( 5897614104487442910) },
          { -INT64_C( 4503365858539250126),  INT64_C(  510691872684187677) },
          { -INT64_C( 8438234524770528400),  INT64_C( 4650733038694668196) } },
    },
    {
        { { -INT64_C( 6812735103957159913),  INT64_C( 4684347046680754797) },
          { -INT64_C( 6797494256063963208),  INT64_C(  817131701850225417) },
          { -INT64_C( 2459471789332421704), -INT64_C( 3908884707880145491) } },
    },
    {
        { { -INT64_C( 4100646489449476999),  INT64_C( 6255277363448157647) },
          {  INT64_C( 8045525435956825689), -INT64_C( 3298133177437159585) },
          { -INT64_C( 8754892432932854790), -INT64_C( 1303483590741762315) } },
    },
    {
        { {  INT64_C( 5681112737786527142),  INT64_C( 7784463650344846556) },
          { -INT64_C( 6604066303493517540),  INT64_C( 7026777308672795139) },
          {  INT64_C( 8420219030380034717), -INT64_C( 5961726241761748635) } },
    },
    {
        { {  INT64_C( 1104746457136654081),  INT64_C( 5303035476090194812) },
          {  INT64_C( 7453932385153147492), -INT64_C( 3636513982266860727) },
          {  INT64_C( 6774770512183494889),  INT64_C( 4058075127937870428) } },
    },
    {
        { {  INT64_C( 2304056124882888335), -INT64_C( 6747655883222009663) },
          {  INT64_C(  489374665791756426),  INT64_C( 2040798640767655749) },
          { -INT64_C( 1261948882788644986), -INT64_C( 9062131986961041696) } },
    },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int64x2x3_t a = simde_vld3q_s64(test_vec[i].r[0]);
    int64_t r_[3][2];
    simde_vst3q_s64(r_[0], a);
    simde_test_arm_neon_assert_equal_i64x2(simde_vld1q_s64(r_[0]), simde_vld1q_s64(test_vec[i].r[0]));
    simde_test_arm_neon_assert_equal_i64x2(simde_vld1q_s64(r_[1]), simde_vld1q_s64(test_vec[i].r[1]));
    simde_test_arm_neon_assert_equal_i64x2(simde_vld1q_s64(r_[2]), simde_vld1q_s64(test_vec[i].r[2]));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int64x2x3_t a = { { simde_test_arm_neon_random_i64x2(),
                              simde_test_arm_neon_random_i64x2(),
                              simde_test_arm_neon_random_i64x2(), } };
    simde_test_arm_neon_write_i64x2x3(2, a, SIMDE_TEST_VEC_POS_FIRST);
  }
  return 1;
#endif
}

static int
test_simde_vst3q_u8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint8_t r[3][16];
  } test_vec[] = {
    {
        { { UINT8_C(183), UINT8_C(182), UINT8_C(228), UINT8_C(219), UINT8_C(227), UINT8_C( 50), UINT8_C(201), UINT8_C( 34),
            UINT8_C( 68), UINT8_C(199), UINT8_C(125), UINT8_C(116), UINT8_C(225), UINT8_C(131), UINT8_C(145), UINT8_C( 70) },
          { UINT8_C(252), UINT8_C(103), UINT8_C( 79), UINT8_C( 58), UINT8_C(112), UINT8_C( 43), UINT8_C(205), UINT8_C(235),
            UINT8_C( 95), UINT8_C( 18), UINT8_C(232), UINT8_C(203), UINT8_C( 22), UINT8_C(123), UINT8_C(203), UINT8_C(205) },
          { UINT8_C( 49), UINT8_C(175), UINT8_C(168), UINT8_C( 20), UINT8_C(225), UINT8_C(114), UINT8_C( 55), UINT8_C( 38),
            UINT8_C( 57), UINT8_C(180), UINT8_C(154), UINT8_C( 27), UINT8_C( 55), UINT8_C( 43), UINT8_C( 97), UINT8_C( 51) } },
    },
    {
        { { UINT8_C(146), UINT8_C(176), UINT8_C(109), UINT8_C(  3), UINT8_C(219), UINT8_C( 58), UINT8_C(238), UINT8_C( 58),
            UINT8_C( 77), UINT8_C(214), UINT8_C(  6), UINT8_C( 99), UINT8_C( 82), UINT8_C(209), UINT8_C( 48), UINT8_C(131) },
          { UINT8_C(128), UINT8_C(216), UINT8_C(152), UINT8_C( 98), UINT8_C( 74), UINT8_C(207), UINT8_C(136), UINT8_C(132),
            UINT8_C(131), UINT8_C( 34), UINT8_C(159), UINT8_C(186), UINT8_C( 77), UINT8_C(  0), UINT8_C(237), UINT8_C(223) },
          { UINT8_C(177), UINT8_C( 90), UINT8_C(226), UINT8_C(140), UINT8_C(148), UINT8_C(208), UINT8_C(199), UINT8_C(225),
            UINT8_C(167), UINT8_C(205), UINT8_C( 68), UINT8_C(249), UINT8_C(158), UINT8_C(116), UINT8_C(124), UINT8_C( 30) } },
    },
    {
        { { UINT8_C( 77), UINT8_C( 20), UINT8_C(128), UINT8_C(151), UINT8_C(227), UINT8_C(  8), UINT8_C( 27), UINT8_C(102),
            UINT8_C( 42), UINT8_C(186), UINT8_C( 32), UINT8_C(119), UINT8_C(187), UINT8_C( 13), UINT8_C( 87), UINT8_C(108) },
          { UINT8_C(103), UINT8_C( 57), UINT8_C(248), UINT8_C(252), UINT8_C( 10), UINT8_C(191), UINT8_C(221), UINT8_C(177),
            UINT8_C(140), UINT8_C( 34), UINT8_C(170), UINT8_C( 42), UINT8_C(150), UINT8_C( 38), UINT8_C( 73), UINT8_C(227) },
          { UINT8_C( 59), UINT8_C(201), UINT8_C(123), UINT8_C( 30), UINT8_C(210), UINT8_C(150), UINT8_C(133), UINT8_C(252),
            UINT8_C( 81), UINT8_C(165), UINT8_C(116), UINT8_C( 12), UINT8_C(179), UINT8_C(203), UINT8_C(120), UINT8_C( 26) } },
    },
    {
        { { UINT8_C(  4), UINT8_C(112), UINT8_C( 22), UINT8_C( 14), UINT8_C( 48), UINT8_C(244), UINT8_C(191), UINT8_C(188),
            UINT8_C( 22), UINT8_C(105), UINT8_C(231), UINT8_C(172), UINT8_C(144), UINT8_C( 48), UINT8_C(144), UINT8_C(203) },
          { UINT8_C(249), UINT8_C( 11), UINT8_C(233), UINT8_C(203), UINT8_C(161), UINT8_C(110), UINT8_C(200), UINT8_C(242),
            UINT8_C( 20), UINT8_C( 60), UINT8_C(254), UINT8_C(199), UINT8_C(  7), UINT8_C(118), UINT8_C(225), UINT8_C( 11) },
          { UINT8_C(231), UINT8_C(248), UINT8_C( 26), UINT8_C( 23), UINT8_C(236), UINT8_C(217), UINT8_C(211), UINT8_C(  2),
            UINT8_C( 67), UINT8_C(186), UINT8_C(174), UINT8_C(211), UINT8_C(234), UINT8_C( 62), UINT8_C(158), UINT8_C(228) } },
    },
    {
        { { UINT8_C( 73), UINT8_C(135), UINT8_C(175), UINT8_C(235), UINT8_C(246), UINT8_C(119), UINT8_C(221), UINT8_C( 10),
            UINT8_C(179), UINT8_C(220), UINT8_C(209), UINT8_C(186), UINT8_C( 82), UINT8_C(178), UINT8_C(198), UINT8_C( 57) },
          { UINT8_C(170), UINT8_C(224), UINT8_C( 80), UINT8_C(150), UINT8_C(185), UINT8_C( 36), UINT8_C(152), UINT8_C(252),
            UINT8_C(222), UINT8_C( 71), UINT8_C(207), UINT8_C(201), UINT8_C(133), UINT8_C(109), UINT8_C(173), UINT8_C(207) },
          { UINT8_C(245), UINT8_C( 92), UINT8_C(186), UINT8_C(235), UINT8_C(212), UINT8_C(151), UINT8_C(245), UINT8_C(135),
            UINT8_C(115), UINT8_C(198), UINT8_C( 66), UINT8_C(198), UINT8_C(120), UINT8_C(  8),    UINT8_MAX, UINT8_C( 35) } },
    },
    {
        { { UINT8_C(232), UINT8_C( 80), UINT8_C(185), UINT8_C(161), UINT8_C(116), UINT8_C( 82), UINT8_C(158), UINT8_C( 82),
            UINT8_C(153), UINT8_C(109), UINT8_C( 27), UINT8_C( 30), UINT8_C(219), UINT8_C(200), UINT8_C(237), UINT8_C(208) },
          { UINT8_C( 37), UINT8_C(167), UINT8_C(187), UINT8_C(249), UINT8_C( 63), UINT8_C(176), UINT8_C(128), UINT8_C(178),
            UINT8_C(118), UINT8_C(194), UINT8_C(120), UINT8_C(238), UINT8_C(202), UINT8_C(120), UINT8_C( 17), UINT8_C(178) },
          { UINT8_C(200), UINT8_C(203), UINT8_C( 84), UINT8_C( 60), UINT8_C( 29), UINT8_C(242), UINT8_C(142), UINT8_C(182),
            UINT8_C( 95), UINT8_C(170), UINT8_C(212), UINT8_C( 58), UINT8_C(114), UINT8_C(194), UINT8_C( 10), UINT8_C(151) } },
    },
    {
        { { UINT8_C(105), UINT8_C(197), UINT8_C(144), UINT8_C(168), UINT8_C(117), UINT8_C( 17), UINT8_C( 91), UINT8_C(235),
            UINT8_C(211), UINT8_C(211), UINT8_C(218), UINT8_C(158), UINT8_C( 75), UINT8_C(235), UINT8_C( 80), UINT8_C( 19) },
          { UINT8_C(182), UINT8_C(164), UINT8_C( 79), UINT8_C(211), UINT8_C(150), UINT8_C(222), UINT8_C(137), UINT8_C(246),
            UINT8_C(136), UINT8_C( 94), UINT8_C( 48), UINT8_C(250), UINT8_C( 32), UINT8_C( 59), UINT8_C(146), UINT8_C(137) },
          { UINT8_C(  0), UINT8_C( 34), UINT8_C( 50), UINT8_C(118), UINT8_C( 51), UINT8_C(141), UINT8_C( 97), UINT8_C(  7),
            UINT8_C( 96), UINT8_C( 59), UINT8_C(165), UINT8_C(172), UINT8_C( 39), UINT8_C(245), UINT8_C(191), UINT8_C(221) } },
    },
    {
        { { UINT8_C(154), UINT8_C( 15), UINT8_C(177), UINT8_C( 48), UINT8_C(237), UINT8_C( 58), UINT8_C( 38), UINT8_C(117),
            UINT8_C(152), UINT8_C( 87), UINT8_C(111), UINT8_C(184), UINT8_C(146), UINT8_C(  1), UINT8_C( 66), UINT8_C(146) },
          { UINT8_C( 36), UINT8_C(116), UINT8_C(  8), UINT8_C( 87), UINT8_C(  1), UINT8_C(106), UINT8_C( 94), UINT8_C( 97),
            UINT8_C(165), UINT8_C(  3), UINT8_C( 13), UINT8_C(204), UINT8_C(249), UINT8_C(205), UINT8_C(170), UINT8_C(147) },
          { UINT8_C(220), UINT8_C( 91), UINT8_C(195), UINT8_C(201), UINT8_C(149), UINT8_C(234), UINT8_C( 62), UINT8_C( 46),
            UINT8_C( 65), UINT8_C(173), UINT8_C(230), UINT8_C(211), UINT8_C(175), UINT8_C( 40), UINT8_C(101), UINT8_C(211) } },
    },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint8x16x3_t a = simde_vld3q_u8(test_vec[i].r[0]);
    uint8_t r_[3][16];
    simde_vst3q_u8(r_[0], a);
    simde_test_arm_neon_assert_equal_u8x16(simde_vld1q_u8(r_[0]), simde_vld1q_u8(test_vec[i].r[0]));
    simde_test_arm_neon_assert_equal_u8x16(simde_vld1q_u8(r_[1]), simde_vld1q_u8(test_vec[i].r[1]));
    simde_test_arm_neon_assert_equal_u8x16(simde_vld1q_u8(r_[2]), simde_vld1q_u8(test_vec[i].r[2]));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint8x16x3_t a = { { simde_test_arm_neon_random_u8x16(),
                               simde_test_arm_neon_random_u8x16(),
                               simde_test_arm_neon_random_u8x16(), } };
    simde_test_arm_neon_write_u8x16x3(2, a, SIMDE_TEST_VEC_POS_FIRST);
  }
  return 1;
#endif
}

static int
test_simde_vst3q_u16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint16_t r[3][8];
  } test_vec[] = {
    {
        { { UINT16_C(24880), UINT16_C(32120), UINT16_C(64108), UINT16_C(24639), UINT16_C(34782), UINT16_C(27884), UINT16_C( 2819), UINT16_C( 6175) },
          { UINT16_C(27413), UINT16_C(51484), UINT16_C(28387), UINT16_C(40049), UINT16_C(17885), UINT16_C(48498), UINT16_C(30983), UINT16_C(14242) },
          { UINT16_C( 6874), UINT16_C(18357), UINT16_C(62484), UINT16_C(62375), UINT16_C(38011), UINT16_C(32351), UINT16_C(32415), UINT16_C(46486) } },
    },
    {
        { { UINT16_C(45801), UINT16_C(52350), UINT16_C(61216), UINT16_C(64873), UINT16_C(56117), UINT16_C(15547), UINT16_C(23892), UINT16_C(12148) },
          { UINT16_C(10615), UINT16_C(35702), UINT16_C( 7453), UINT16_C(39038), UINT16_C(56753), UINT16_C(20758), UINT16_C(44124), UINT16_C(17670) },
          { UINT16_C(33886), UINT16_C(32274), UINT16_C(31604), UINT16_C(43387), UINT16_C(13910), UINT16_C(44005), UINT16_C(22931), UINT16_C( 2778) } },
    },
    {
        { { UINT16_C(20610), UINT16_C(40854), UINT16_C( 5229), UINT16_C( 7991), UINT16_C(19954), UINT16_C(20080), UINT16_C(30457), UINT16_C(22419) },
          { UINT16_C(42490), UINT16_C(28373), UINT16_C(20768), UINT16_C(30487), UINT16_C(64903), UINT16_C( 6946), UINT16_C(64598), UINT16_C(55589) },
          { UINT16_C(47948), UINT16_C(47480), UINT16_C(45264), UINT16_C(49880), UINT16_C(18685), UINT16_C(63248), UINT16_C(41918), UINT16_C(47438) } },
    },
    {
        { { UINT16_C( 9289), UINT16_C(26919), UINT16_C(16245), UINT16_C(64736), UINT16_C(  572), UINT16_C(37399), UINT16_C(15870), UINT16_C(19051) },
          { UINT16_C(58616), UINT16_C(51204), UINT16_C(56468), UINT16_C(37258), UINT16_C(39461), UINT16_C(58248), UINT16_C(55102), UINT16_C(34716) },
          { UINT16_C(50427), UINT16_C(28912), UINT16_C(53507), UINT16_C(16236), UINT16_C(34003), UINT16_C(53969), UINT16_C(15809), UINT16_C(47388) } },
    },
    {
        { { UINT16_C( 8225), UINT16_C(46466), UINT16_C( 3325), UINT16_C( 8774), UINT16_C(53159), UINT16_C(58629), UINT16_C(41638), UINT16_C(41324) },
          { UINT16_C(23654), UINT16_C(26897), UINT16_C(32045), UINT16_C(  424), UINT16_C(30977), UINT16_C(49875), UINT16_C(61366), UINT16_C(55164) },
          { UINT16_C(65040), UINT16_C( 3468), UINT16_C(54026), UINT16_C(45359), UINT16_C(13474), UINT16_C(18582), UINT16_C(  726), UINT16_C(15593) } },
    },
    {
        { { UINT16_C(64095), UINT16_C(36005), UINT16_C(19831), UINT16_C(31117), UINT16_C(24775), UINT16_C(32059), UINT16_C(46928), UINT16_C(24661) },
          { UINT16_C(57781), UINT16_C(49261), UINT16_C(40116), UINT16_C(22129), UINT16_C( 2256), UINT16_C(42910), UINT16_C(34570), UINT16_C(27107) },
          { UINT16_C(35201), UINT16_C(63990), UINT16_C(33750), UINT16_C(40306), UINT16_C(44516), UINT16_C(13339), UINT16_C(28773), UINT16_C( 6804) } },
    },
    {
        { { UINT16_C(  337), UINT16_C( 1754), UINT16_C(19613), UINT16_C(27996), UINT16_C(64340), UINT16_C(24084), UINT16_C(63618), UINT16_C( 1224) },
          { UINT16_C(48769), UINT16_C(22525), UINT16_C(28481), UINT16_C( 9717), UINT16_C( 4124), UINT16_C(33113), UINT16_C(60800), UINT16_C(53660) },
          { UINT16_C(30446), UINT16_C(35799), UINT16_C(13506), UINT16_C( 5881), UINT16_C( 3375), UINT16_C(45429), UINT16_C(15621), UINT16_C(34485) } },
    },
    {
        { { UINT16_C(45819), UINT16_C(15582), UINT16_C(54049), UINT16_C(15970), UINT16_C(48099), UINT16_C(25535), UINT16_C(23465), UINT16_C(38708) },
          { UINT16_C( 3282), UINT16_C(37923), UINT16_C( 7232), UINT16_C(28587), UINT16_C( 8233), UINT16_C(12064), UINT16_C(54877), UINT16_C(22709) },
          { UINT16_C(37768), UINT16_C(43668), UINT16_C(63078), UINT16_C(18920), UINT16_C(42930), UINT16_C(23468), UINT16_C(57603), UINT16_C(54770) } },
    },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint16x8x3_t a = simde_vld3q_u16(test_vec[i].r[0]);
    uint16_t r_[3][8];
    simde_vst3q_u16(r_[0], a);
    simde_test_arm_neon_assert_equal_u16x8(simde_vld1q_u16(r_[0]), simde_vld1q_u16(test_vec[i].r[0]));
    simde_test_arm_neon_assert_equal_u16x8(simde_vld1q_u16(r_[1]), simde_vld1q_u16(test_vec[i].r[1]));
    simde_test_arm_neon_assert_equal_u16x8(simde_vld1q_u16(r_[2]), simde_vld1q_u16(test_vec[i].r[2]));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint16x8x3_t a = { { simde_test_arm_neon_random_u16x8(),
                               simde_test_arm_neon_random_u16x8(),
                               simde_test_arm_neon_random_u16x8(), } };
    simde_test_arm_neon_write_u16x8x3(2, a, SIMDE_TEST_VEC_POS_FIRST);
  }
  return 1;
#endif
}

static int
test_simde_vst3q_u32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint32_t r[3][4];
  } test_vec[] = {
    {
        { { UINT32_C(1625813263), UINT32_C( 721280747), UINT32_C(1497519426), UINT32_C(1203552935) },
          { UINT32_C(3051101490), UINT32_C( 266840050), UINT32_C(3081083779), UINT32_C(4205500395) },
          { UINT32_C(3025900232), UINT32_C(3000916080), UINT32_C(1410080941), UINT32_C( 362531042) } },
    },
    {
        { { UINT32_C(3620370405), UINT32_C(2733027615), UINT32_C( 928615500), UINT32_C( 741409635) },
          { UINT32_C(  98602133), UINT32_C(2444803812), UINT32_C(3253060830), UINT32_C(1909883020) },
          { UINT32_C( 390635768), UINT32_C(2646158929), UINT32_C( 517214906), UINT32_C(2873754901) } },
    },
    {
        { { UINT32_C(1991256722), UINT32_C(3322439912), UINT32_C(3095915820), UINT32_C(1713986926) },
          { UINT32_C(1316844029), UINT32_C(1525364384), UINT32_C(1568194376), UINT32_C(1460191941) },
          { UINT32_C(3570252268), UINT32_C(1318835489), UINT32_C( 822485699), UINT32_C(2107060352) } },
    },
    {
        { { UINT32_C(1103893665), UINT32_C(2459744074), UINT32_C(1022301303), UINT32_C(3281254615) },
          { UINT32_C(3533201585), UINT32_C(4179637046), UINT32_C(3576309589), UINT32_C(4166238551) },
          { UINT32_C( 523902933), UINT32_C(1303500502), UINT32_C(3247022314), UINT32_C(1233460376) } },
    },
    {
        { { UINT32_C(3004964221), UINT32_C(2779528272), UINT32_C(3128677987), UINT32_C(1823723159) },
          { UINT32_C(3280727533), UINT32_C(2903588035), UINT32_C(1970248412), UINT32_C( 884929719) },
          { UINT32_C(1642584593), UINT32_C(2047251223), UINT32_C(   3506537), UINT32_C(1013770319) } },
    },
    {
        { { UINT32_C(2550200277), UINT32_C( 256184627), UINT32_C(1652864171), UINT32_C(3113632680) },
          { UINT32_C( 874151197), UINT32_C(2041520400), UINT32_C(4068074658), UINT32_C(2704205260) },
          { UINT32_C( 255405788), UINT32_C(3944709695), UINT32_C(3679298355), UINT32_C(  76932326) } },
    },
    {
        { { UINT32_C(1916317537), UINT32_C(1944840144), UINT32_C(2540004811), UINT32_C( 658019146) },
          { UINT32_C(  20345282), UINT32_C( 602691056), UINT32_C(3757980409), UINT32_C(2145620766) },
          { UINT32_C( 334568515), UINT32_C(3481722115), UINT32_C(2355555138), UINT32_C(1102290815) } },
    },
    {
        { { UINT32_C(   4385296), UINT32_C( 941829951), UINT32_C(2266505833), UINT32_C(4161207221) },
          { UINT32_C( 453834775), UINT32_C( 401248981), UINT32_C(4255338622), UINT32_C(   4085743) },
          { UINT32_C(2147516481), UINT32_C( 414786735), UINT32_C(4221555014), UINT32_C(3841238732) } },
    },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint32x4x3_t a = simde_vld3q_u32(test_vec[i].r[0]);
    uint32_t r_[3][4];
    simde_vst3q_u32(r_[0], a);
    simde_test_arm_neon_assert_equal_u32x4(simde_vld1q_u32(r_[0]), simde_vld1q_u32(test_vec[i].r[0]));
    simde_test_arm_neon_assert_equal_u32x4(simde_vld1q_u32(r_[1]), simde_vld1q_u32(test_vec[i].r[1]));
    simde_test_arm_neon_assert_equal_u32x4(simde_vld1q_u32(r_[2]), simde_vld1q_u32(test_vec[i].r[2]));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint32x4x3_t a = { { simde_test_arm_neon_random_u32x4(),
                               simde_test_arm_neon_random_u32x4(),
                               simde_test_arm_neon_random_u32x4(), } };
    simde_test_arm_neon_write_u32x4x3(2, a, SIMDE_TEST_VEC_POS_FIRST);
  }
  return 1;
#endif
}

static int
test_simde_vst3q_u64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint64_t r[3][2];
  } test_vec[] = {
    {
        { { UINT64_C(12256945634260565323), UINT64_C(15373482284772513076) },
          { UINT64_C(16029400785989491440), UINT64_C( 2337404308043619706) },
          { UINT64_C( 8080718027284402269), UINT64_C( 5211890004908885199) } },
    },
    {
        { { UINT64_C(17557599225954212276), UINT64_C(10264240324271935868) },
          { UINT64_C( 2045528464274543288), UINT64_C( 8255924667498063089) },
          { UINT64_C(15705431087674900105), UINT64_C(  916090359969901815) } },
    },
    {
        { { UINT64_C(15985073795782197101), UINT64_C(16859430128775033287) },
          { UINT64_C( 1382568923436365304), UINT64_C( 7182664117495028300) },
          { UINT64_C(15599328987008839089), UINT64_C( 6173965996091351652) } },
    },
    {
        { { UINT64_C(14175882988846029195), UINT64_C(11136578246205109812) },
          { UINT64_C(  119261405516442303), UINT64_C(16503286192905979221) },
          { UINT64_C(13927741991481553420), UINT64_C( 9205771880004038205) } },
    },
    {
        { { UINT64_C(  126372011370871074), UINT64_C(  377100573879797243) },
          { UINT64_C( 5528964657626925164), UINT64_C( 4594291870161675650) },
          { UINT64_C(  277743272263029037), UINT64_C(13061166006810545731) } },
    },
    {
        { { UINT64_C( 2573922225269689437), UINT64_C(10117662427062872845) },
          { UINT64_C( 7513482082109450042), UINT64_C(10505744766676082638) },
          { UINT64_C(17183402882653583795), UINT64_C( 4597472654165335521) } },
    },
    {
        { { UINT64_C( 4645119358346015464), UINT64_C(13054565339438193510) },
          { UINT64_C(13721483853464938652), UINT64_C(17195530655073535069) },
          { UINT64_C( 5886612543505179902), UINT64_C(14358625888317933709) } },
    },
    {
        { { UINT64_C( 3232090081858965054), UINT64_C(11756982887966038325) },
          { UINT64_C( 2635105609905874261), UINT64_C(15042296065555659982) },
          { UINT64_C(16879709884427011398), UINT64_C( 6262060673738854303) } },
    },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint64x2x3_t a = simde_vld3q_u64(test_vec[i].r[0]);
    uint64_t r_[3][2];
    simde_vst3q_u64(r_[0], a);
    simde_test_arm_neon_assert_equal_u64x2(simde_vld1q_u64(r_[0]), simde_vld1q_u64(test_vec[i].r[0]));
    simde_test_arm_neon_assert_equal_u64x2(simde_vld1q_u64(r_[1]), simde_vld1q_u64(test_vec[i].r[1]));
    simde_test_arm_neon_assert_equal_u64x2(simde_vld1q_u64(r_[2]), simde_vld1q_u64(test_vec[i].r[2]));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint64x2x3_t a = { { simde_test_arm_neon_random_u64x2(),
                               simde_test_arm_neon_random_u64x2(),
                               simde_test_arm_neon_random_u64x2(), } };
    simde_test_arm_neon_write_u64x2x3(2, a, SIMDE_TEST_VEC_POS_FIRST);
  }
  return 1;
#endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(vst3_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vst3_f64)
SIMDE_TEST_FUNC_LIST_ENTRY(vst3_s8)
SIMDE_TEST_FUNC_LIST_ENTRY(vst3_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vst3_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vst3_s64)
SIMDE_TEST_FUNC_LIST_ENTRY(vst3_u8)
SIMDE_TEST_FUNC_LIST_ENTRY(vst3_u16)
SIMDE_TEST_FUNC_LIST_ENTRY(vst3_u32)
SIMDE_TEST_FUNC_LIST_ENTRY(vst3_u64)

SIMDE_TEST_FUNC_LIST_ENTRY(vst3q_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vst3q_f64)
SIMDE_TEST_FUNC_LIST_ENTRY(vst3q_s8)
SIMDE_TEST_FUNC_LIST_ENTRY(vst3q_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vst3q_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vst3q_s64)
SIMDE_TEST_FUNC_LIST_ENTRY(vst3q_u8)
SIMDE_TEST_FUNC_LIST_ENTRY(vst3q_u16)
SIMDE_TEST_FUNC_LIST_ENTRY(vst3q_u32)
SIMDE_TEST_FUNC_LIST_ENTRY(vst3q_u64)
SIMDE_TEST_FUNC_LIST_END

#include "test-neon-footer.h"
