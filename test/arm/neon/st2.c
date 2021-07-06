
#include "test/test.h"
#define SIMDE_TEST_ARM_NEON_INSN st2
#include "test-neon.h"
#include "../../../simde/arm/neon/st2.h"

#if !defined(SIMDE_BUG_INTEL_857088)

static int
test_simde_vst2_f32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float32 r0[2];
    simde_float32 r1[2];
    simde_float32 a[4];
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(    16.58), SIMDE_FLOAT32_C(  -833.98) },
      { SIMDE_FLOAT32_C(   104.15), SIMDE_FLOAT32_C(  -390.57) },
      { SIMDE_FLOAT32_C(    16.58), SIMDE_FLOAT32_C(   104.15), SIMDE_FLOAT32_C(  -833.98), SIMDE_FLOAT32_C(  -390.57) } },
    { { SIMDE_FLOAT32_C(  -490.85), SIMDE_FLOAT32_C(   -58.75) },
      { SIMDE_FLOAT32_C(   959.78), SIMDE_FLOAT32_C(   101.04) },
      { SIMDE_FLOAT32_C(  -490.85), SIMDE_FLOAT32_C(   959.78), SIMDE_FLOAT32_C(   -58.75), SIMDE_FLOAT32_C(   101.04) } },
    { { SIMDE_FLOAT32_C(  -997.46), SIMDE_FLOAT32_C(   256.92) },
      { SIMDE_FLOAT32_C(   188.22), SIMDE_FLOAT32_C(  -745.54) },
      { SIMDE_FLOAT32_C(  -997.46), SIMDE_FLOAT32_C(   188.22), SIMDE_FLOAT32_C(   256.92), SIMDE_FLOAT32_C(  -745.54) } },
    { { SIMDE_FLOAT32_C(   -96.17), SIMDE_FLOAT32_C(   503.93) },
      { SIMDE_FLOAT32_C(  -366.65), SIMDE_FLOAT32_C(   363.77) },
      { SIMDE_FLOAT32_C(   -96.17), SIMDE_FLOAT32_C(  -366.65), SIMDE_FLOAT32_C(   503.93), SIMDE_FLOAT32_C(   363.77) } },
    { { SIMDE_FLOAT32_C(   624.56), SIMDE_FLOAT32_C(   975.47) },
      { SIMDE_FLOAT32_C(  -418.14), SIMDE_FLOAT32_C(  -827.91) },
      { SIMDE_FLOAT32_C(   624.56), SIMDE_FLOAT32_C(  -418.14), SIMDE_FLOAT32_C(   975.47), SIMDE_FLOAT32_C(  -827.91) } },
    { { SIMDE_FLOAT32_C(   877.41), SIMDE_FLOAT32_C(    17.43) },
      { SIMDE_FLOAT32_C(   269.24), SIMDE_FLOAT32_C(   712.61) },
      { SIMDE_FLOAT32_C(   877.41), SIMDE_FLOAT32_C(   269.24), SIMDE_FLOAT32_C(    17.43), SIMDE_FLOAT32_C(   712.61) } },
    { { SIMDE_FLOAT32_C(  -244.13), SIMDE_FLOAT32_C(  -617.42) },
      { SIMDE_FLOAT32_C(   500.72), SIMDE_FLOAT32_C(  -493.36) },
      { SIMDE_FLOAT32_C(  -244.13), SIMDE_FLOAT32_C(   500.72), SIMDE_FLOAT32_C(  -617.42), SIMDE_FLOAT32_C(  -493.36) } },
    { { SIMDE_FLOAT32_C(  -230.20), SIMDE_FLOAT32_C(   102.18) },
      { SIMDE_FLOAT32_C(   293.56), SIMDE_FLOAT32_C(   786.38) },
      { SIMDE_FLOAT32_C(  -230.20), SIMDE_FLOAT32_C(   293.56), SIMDE_FLOAT32_C(   102.18), SIMDE_FLOAT32_C(   786.38) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x2x2_t r_ = { { simde_vld1_f32(test_vec[i].r0),
                                 simde_vld1_f32(test_vec[i].r1) } };

    simde_float32 a_[4];
    simde_vst2_f32(a_, r_);

    simde_assert_equal_i(0, simde_memcmp(a_, test_vec[i].a, sizeof(test_vec[i].a)));
  }

  return 0;
#else
  for (int i = 0 ; i < 8 ; i++) {
    simde_float32x2_t a = simde_test_arm_neon_random_f32x2(-1000.0f, 1000.0f);
    simde_float32x2_t b = simde_test_arm_neon_random_f32x2(-1000.0f, 1000.0f);
    simde_float32x2x2_t c = {{a, b}};

    simde_test_arm_neon_write_f32x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f32x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);

    simde_float32 buf[4];
    simde_vst2_f32(buf, c);

    simde_test_codegen_write_vf32(2, sizeof(buf) / sizeof(buf[0]), buf,
                                  SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vst2_f64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float64 r0[1];
    simde_float64 r1[1];
    simde_float64 a[2];
  } test_vec[] = {
    { { SIMDE_FLOAT64_C(   392.49) },
      { SIMDE_FLOAT64_C(   204.55) },
      { SIMDE_FLOAT64_C(   392.49), SIMDE_FLOAT64_C(   204.55) } },
    { { SIMDE_FLOAT64_C(   727.16) },
      { SIMDE_FLOAT64_C(   738.24) },
      { SIMDE_FLOAT64_C(   727.16), SIMDE_FLOAT64_C(   738.24) } },
    { { SIMDE_FLOAT64_C(   987.55) },
      { SIMDE_FLOAT64_C(  -537.01) },
      { SIMDE_FLOAT64_C(   987.55), SIMDE_FLOAT64_C(  -537.01) } },
    { { SIMDE_FLOAT64_C(   727.60) },
      { SIMDE_FLOAT64_C(  -348.79) },
      { SIMDE_FLOAT64_C(   727.60), SIMDE_FLOAT64_C(  -348.79) } },
    { { SIMDE_FLOAT64_C(  -739.96) },
      { SIMDE_FLOAT64_C(  -473.84) },
      { SIMDE_FLOAT64_C(  -739.96), SIMDE_FLOAT64_C(  -473.84) } },
    { { SIMDE_FLOAT64_C(   -82.16) },
      { SIMDE_FLOAT64_C(  -848.99) },
      { SIMDE_FLOAT64_C(   -82.16), SIMDE_FLOAT64_C(  -848.99) } },
    { { SIMDE_FLOAT64_C(  -651.42) },
      { SIMDE_FLOAT64_C(  -148.81) },
      { SIMDE_FLOAT64_C(  -651.42), SIMDE_FLOAT64_C(  -148.81) } },
    { { SIMDE_FLOAT64_C(  -782.36) },
      { SIMDE_FLOAT64_C(  -642.06) },
      { SIMDE_FLOAT64_C(  -782.36), SIMDE_FLOAT64_C(  -642.06) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float64x1x2_t r_ = { { simde_vld1_f64(test_vec[i].r0),
                                 simde_vld1_f64(test_vec[i].r1) } };

    simde_float64 a_[2];
    simde_vst2_f64(a_, r_);

    simde_assert_equal_i(0, simde_memcmp(a_, test_vec[i].a, sizeof(test_vec[i].a)));
  }

  return 0;
#else
  for (int i = 0 ; i < 8 ; i++) {
    simde_float64x1_t a = simde_test_arm_neon_random_f64x1(-1000.0, 1000.0);
    simde_float64x1_t b = simde_test_arm_neon_random_f64x1(-1000.0, 1000.0);
    simde_float64x1x2_t c = {{a, b}};

    simde_test_arm_neon_write_f64x1(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f64x1(2, b, SIMDE_TEST_VEC_POS_MIDDLE);

    simde_float64 buf[2];
    simde_vst2_f64(buf, c);

    simde_test_codegen_write_vf64(2, sizeof(buf) / sizeof(buf[0]), buf,
                                  SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vst2_s8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int8_t r0[8];
    int8_t r1[8];
    int8_t a[16];
  } test_vec[] = {
    { { -INT8_C(  46),  INT8_C(  78),  INT8_C(  45), -INT8_C(  21),  INT8_C(  71), -INT8_C(  34),  INT8_C(   2),  INT8_C( 120) },
      {  INT8_C(  65), -INT8_C(  36), -INT8_C(  88),  INT8_C( 102),  INT8_C(  72), -INT8_C(  80),  INT8_C(  81), -INT8_C(  48) },
      { -INT8_C(  46),  INT8_C(  65),  INT8_C(  78), -INT8_C(  36),  INT8_C(  45), -INT8_C(  88), -INT8_C(  21),  INT8_C( 102),
         INT8_C(  71),  INT8_C(  72), -INT8_C(  34), -INT8_C(  80),  INT8_C(   2),  INT8_C(  81),  INT8_C( 120), -INT8_C(  48) } },
    { { -INT8_C(  56), -INT8_C(   9), -INT8_C(  53),  INT8_C( 125), -INT8_C(   1), -INT8_C(   9),  INT8_C(   0),  INT8_C(   1) },
      {  INT8_C(  38), -INT8_C(  57), -INT8_C(  50), -INT8_C( 100), -INT8_C( 106), -INT8_C( 120), -INT8_C(  69),  INT8_C( 104) },
      { -INT8_C(  56),  INT8_C(  38), -INT8_C(   9), -INT8_C(  57), -INT8_C(  53), -INT8_C(  50),  INT8_C( 125), -INT8_C( 100),
        -INT8_C(   1), -INT8_C( 106), -INT8_C(   9), -INT8_C( 120),  INT8_C(   0), -INT8_C(  69),  INT8_C(   1),  INT8_C( 104) } },
    { { -INT8_C(  42), -INT8_C(  24),  INT8_C(  83),  INT8_C(  29), -INT8_C(  57),  INT8_C(  85), -INT8_C( 106),  INT8_C(   8) },
      {  INT8_C(  50),  INT8_C(  62),  INT8_C( 110),  INT8_C( 122), -INT8_C(  17), -INT8_C(  64),  INT8_C(  75), -INT8_C(  73) },
      { -INT8_C(  42),  INT8_C(  50), -INT8_C(  24),  INT8_C(  62),  INT8_C(  83),  INT8_C( 110),  INT8_C(  29),  INT8_C( 122),
        -INT8_C(  57), -INT8_C(  17),  INT8_C(  85), -INT8_C(  64), -INT8_C( 106),  INT8_C(  75),  INT8_C(   8), -INT8_C(  73) } },
    { { -INT8_C(  73),  INT8_C(  22),  INT8_C(  52), -INT8_C(  74),  INT8_C(  13),  INT8_C(  52), -INT8_C(  72),  INT8_C(  51) },
      { -INT8_C(   5), -INT8_C( 122), -INT8_C(  48), -INT8_C( 110),  INT8_C(  14), -INT8_C( 117), -INT8_C(   6), -INT8_C(  28) },
      { -INT8_C(  73), -INT8_C(   5),  INT8_C(  22), -INT8_C( 122),  INT8_C(  52), -INT8_C(  48), -INT8_C(  74), -INT8_C( 110),
         INT8_C(  13),  INT8_C(  14),  INT8_C(  52), -INT8_C( 117), -INT8_C(  72), -INT8_C(   6),  INT8_C(  51), -INT8_C(  28) } },
    { {  INT8_C( 115),  INT8_C(  78),  INT8_C(   2),  INT8_C(  58), -INT8_C(  93), -INT8_C( 104),  INT8_C(  67), -INT8_C(  43) },
      { -INT8_C(  42), -INT8_C(  79),  INT8_C(  80), -INT8_C(  59),  INT8_C( 113), -INT8_C( 101),  INT8_C( 124),  INT8_C(  40) },
      {  INT8_C( 115), -INT8_C(  42),  INT8_C(  78), -INT8_C(  79),  INT8_C(   2),  INT8_C(  80),  INT8_C(  58), -INT8_C(  59),
        -INT8_C(  93),  INT8_C( 113), -INT8_C( 104), -INT8_C( 101),  INT8_C(  67),  INT8_C( 124), -INT8_C(  43),  INT8_C(  40) } },
    { { -INT8_C(  79), -INT8_C(  79), -INT8_C(  33), -INT8_C(  66), -INT8_C(  27), -INT8_C( 105), -INT8_C(  15), -INT8_C(  31) },
      {  INT8_C(  29), -INT8_C(  63),  INT8_C( 115),  INT8_C(  43),  INT8_C(  76),  INT8_C( 109),  INT8_C(  15), -INT8_C(  64) },
      { -INT8_C(  79),  INT8_C(  29), -INT8_C(  79), -INT8_C(  63), -INT8_C(  33),  INT8_C( 115), -INT8_C(  66),  INT8_C(  43),
        -INT8_C(  27),  INT8_C(  76), -INT8_C( 105),  INT8_C( 109), -INT8_C(  15),  INT8_C(  15), -INT8_C(  31), -INT8_C(  64) } },
    { { -INT8_C(  69),  INT8_C(  17), -INT8_C(   6),  INT8_C(  95), -INT8_C(  87),  INT8_C(  61),  INT8_C(  52),      INT8_MIN },
      { -INT8_C(  17), -INT8_C( 124),  INT8_C(  69),  INT8_C(  96),  INT8_C(  31), -INT8_C(  62), -INT8_C( 119), -INT8_C(  48) },
      { -INT8_C(  69), -INT8_C(  17),  INT8_C(  17), -INT8_C( 124), -INT8_C(   6),  INT8_C(  69),  INT8_C(  95),  INT8_C(  96),
        -INT8_C(  87),  INT8_C(  31),  INT8_C(  61), -INT8_C(  62),  INT8_C(  52), -INT8_C( 119),      INT8_MIN, -INT8_C(  48) } },
    { {  INT8_C( 115),  INT8_C( 104), -INT8_C( 114),  INT8_C(  88), -INT8_C(   1),      INT8_MIN,  INT8_C(  57),  INT8_C(  28) },
      {  INT8_C(  65), -INT8_C(  84),  INT8_C(  71), -INT8_C( 114),  INT8_C(  26),  INT8_C(  86),  INT8_C(  78), -INT8_C(  43) },
      {  INT8_C( 115),  INT8_C(  65),  INT8_C( 104), -INT8_C(  84), -INT8_C( 114),  INT8_C(  71),  INT8_C(  88), -INT8_C( 114),
        -INT8_C(   1),  INT8_C(  26),      INT8_MIN,  INT8_C(  86),  INT8_C(  57),  INT8_C(  78),  INT8_C(  28), -INT8_C(  43) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int8x8x2_t r_ = { { simde_vld1_s8(test_vec[i].r0),
                              simde_vld1_s8(test_vec[i].r1) } };

    int8_t a_[16];
    simde_vst2_s8(a_, r_);

    simde_assert_equal_i(0, simde_memcmp(a_, test_vec[i].a, sizeof(test_vec[i].a)));
  }

  return 0;
#else
  for (int i = 0 ; i < 8 ; i++) {
    simde_int8x8_t a = simde_test_arm_neon_random_i8x8();
    simde_int8x8_t b = simde_test_arm_neon_random_i8x8();
    simde_int8x8x2_t c = {{a, b}};

    simde_test_arm_neon_write_i8x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i8x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);

    int8_t buf[16];
    simde_vst2_s8(buf, c);

    simde_test_codegen_write_vi8(2, sizeof(buf) / sizeof(buf[0]), buf,
                                 SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vst2_s16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int16_t r0[4];
    int16_t r1[4];
    int16_t a[8];
  } test_vec[] = {
    { { -INT16_C(  4782),  INT16_C(  5605),  INT16_C( 13988),  INT16_C( 25106) },
      {  INT16_C(  1533),  INT16_C( 32102),  INT16_C(  5724),  INT16_C( 21869) },
      { -INT16_C(  4782),  INT16_C(  1533),  INT16_C(  5605),  INT16_C( 32102),  INT16_C( 13988),  INT16_C(  5724),  INT16_C( 25106),  INT16_C( 21869) } },
    { { -INT16_C( 19247), -INT16_C( 31901), -INT16_C( 29912),  INT16_C( 10590) },
      {  INT16_C( 19840), -INT16_C( 19893), -INT16_C(  1790),  INT16_C( 21678) },
      { -INT16_C( 19247),  INT16_C( 19840), -INT16_C( 31901), -INT16_C( 19893), -INT16_C( 29912), -INT16_C(  1790),  INT16_C( 10590),  INT16_C( 21678) } },
    { { -INT16_C( 27674), -INT16_C( 30103),  INT16_C( 31690), -INT16_C( 14356) },
      {  INT16_C( 21376), -INT16_C(  9148), -INT16_C( 19863),  INT16_C( 14898) },
      { -INT16_C( 27674),  INT16_C( 21376), -INT16_C( 30103), -INT16_C(  9148),  INT16_C( 31690), -INT16_C( 19863), -INT16_C( 14356),  INT16_C( 14898) } },
    { { -INT16_C( 27290), -INT16_C( 28995),  INT16_C(  6944), -INT16_C( 24393) },
      {  INT16_C(   873),  INT16_C( 27474),  INT16_C(   252), -INT16_C(  7488) },
      { -INT16_C( 27290),  INT16_C(   873), -INT16_C( 28995),  INT16_C( 27474),  INT16_C(  6944),  INT16_C(   252), -INT16_C( 24393), -INT16_C(  7488) } },
    { {  INT16_C( 10643),  INT16_C( 23917),  INT16_C( 22949),  INT16_C(  9509) },
      {  INT16_C( 27052),  INT16_C(  5634),  INT16_C( 13339), -INT16_C( 32432) },
      {  INT16_C( 10643),  INT16_C( 27052),  INT16_C( 23917),  INT16_C(  5634),  INT16_C( 22949),  INT16_C( 13339),  INT16_C(  9509), -INT16_C( 32432) } },
    { {  INT16_C(  3785), -INT16_C(  5873), -INT16_C( 14551), -INT16_C( 28023) },
      { -INT16_C(  9270), -INT16_C( 14594), -INT16_C( 16677),  INT16_C( 28328) },
      {  INT16_C(  3785), -INT16_C(  9270), -INT16_C(  5873), -INT16_C( 14594), -INT16_C( 14551), -INT16_C( 16677), -INT16_C( 28023),  INT16_C( 28328) } },
    { {  INT16_C(  5607), -INT16_C( 29492), -INT16_C(  3729),  INT16_C(  7090) },
      { -INT16_C( 19366),  INT16_C( 30257), -INT16_C( 32024), -INT16_C( 19977) },
      {  INT16_C(  5607), -INT16_C( 19366), -INT16_C( 29492),  INT16_C( 30257), -INT16_C(  3729), -INT16_C( 32024),  INT16_C(  7090), -INT16_C( 19977) } },
    { {  INT16_C(  1936), -INT16_C( 18022),  INT16_C(  9166), -INT16_C( 26548) },
      {  INT16_C( 19198), -INT16_C(  9890),  INT16_C(  1544), -INT16_C(  4281) },
      {  INT16_C(  1936),  INT16_C( 19198), -INT16_C( 18022), -INT16_C(  9890),  INT16_C(  9166),  INT16_C(  1544), -INT16_C( 26548), -INT16_C(  4281) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x4x2_t r_ = { { simde_vld1_s16(test_vec[i].r0),
                               simde_vld1_s16(test_vec[i].r1) } };

    int16_t a_[8];
    simde_vst2_s16(a_, r_);

    simde_assert_equal_i(0, simde_memcmp(a_, test_vec[i].a, sizeof(test_vec[i].a)));
  }

  return 0;
#else
  for (int i = 0 ; i < 8 ; i++) {
    simde_int16x4_t a = simde_test_arm_neon_random_i16x4();
    simde_int16x4_t b = simde_test_arm_neon_random_i16x4();
    simde_int16x4x2_t c = {{a, b}};

    simde_test_arm_neon_write_i16x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i16x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);

    int16_t buf[8];
    simde_vst2_s16(buf, c);

    simde_test_codegen_write_vi16(2, sizeof(buf) / sizeof(buf[0]), buf,
                                  SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vst2_s32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int32_t r0[2];
    int32_t r1[2];
    int32_t a[4];
  } test_vec[] = {
    { {  INT32_C(   414377793), -INT32_C(  1542520057) },
      { -INT32_C(  2064060609),  INT32_C(   908441393) },
      {  INT32_C(   414377793), -INT32_C(  2064060609), -INT32_C(  1542520057),  INT32_C(   908441393) } },
    { {  INT32_C(   896309858),  INT32_C(  1059984617) },
      {  INT32_C(  1357938922), -INT32_C(   189958989) },
      {  INT32_C(   896309858),  INT32_C(  1357938922),  INT32_C(  1059984617), -INT32_C(   189958989) } },
    { {  INT32_C(  1645043547), -INT32_C(  1576592285) },
      {  INT32_C(  1025965836),  INT32_C(   410209206) },
      {  INT32_C(  1645043547),  INT32_C(  1025965836), -INT32_C(  1576592285),  INT32_C(   410209206) } },
    { { -INT32_C(   816914459), -INT32_C(   586253069) },
      { -INT32_C(  1339097347), -INT32_C(   844768398) },
      { -INT32_C(   816914459), -INT32_C(  1339097347), -INT32_C(   586253069), -INT32_C(   844768398) } },
    { { -INT32_C(  1641041349), -INT32_C(   633325874) },
      { -INT32_C(   350787787), -INT32_C(  1744532558) },
      { -INT32_C(  1641041349), -INT32_C(   350787787), -INT32_C(   633325874), -INT32_C(  1744532558) } },
    { {  INT32_C(  1583829610), -INT32_C(   885295666) },
      { -INT32_C(   444831373), -INT32_C(  2135809723) },
      {  INT32_C(  1583829610), -INT32_C(   444831373), -INT32_C(   885295666), -INT32_C(  2135809723) } },
    { { -INT32_C(  1591811629),  INT32_C(  1299996184) },
      {  INT32_C(  2017039301), -INT32_C(  1995424482) },
      { -INT32_C(  1591811629),  INT32_C(  2017039301),  INT32_C(  1299996184), -INT32_C(  1995424482) } },
    { {  INT32_C(  1575450511),  INT32_C(  1596531436) },
      { -INT32_C(   784030324), -INT32_C(  1722681658) },
      {  INT32_C(  1575450511), -INT32_C(   784030324),  INT32_C(  1596531436), -INT32_C(  1722681658) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x2x2_t r_ = { { simde_vld1_s32(test_vec[i].r0),
                               simde_vld1_s32(test_vec[i].r1) } };

    int32_t a_[4];
    simde_vst2_s32(a_, r_);

    simde_assert_equal_i(0, simde_memcmp(a_, test_vec[i].a, sizeof(test_vec[i].a)));
  }

  return 0;
#else
  for (int i = 0 ; i < 8 ; i++) {
    simde_int32x2_t a = simde_test_arm_neon_random_i32x2();
    simde_int32x2_t b = simde_test_arm_neon_random_i32x2();
    simde_int32x2x2_t c = {{a, b}};

    simde_test_arm_neon_write_i32x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i32x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);

    int32_t buf[4];
    simde_vst2_s32(buf, c);

    simde_test_codegen_write_vi32(2, sizeof(buf) / sizeof(buf[0]), buf,
                                  SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vst2_s64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int64_t r0[1];
    int64_t r1[1];
    int64_t a[2];
  } test_vec[] = {
    { {  INT64_C( 3526534134596368706) },
      { -INT64_C(  616614032983477437) },
      {  INT64_C( 3526534134596368706), -INT64_C(  616614032983477437) } },
    { {  INT64_C( 8421314509533026682) },
      { -INT64_C( 1594484654541173543) },
      {  INT64_C( 8421314509533026682), -INT64_C( 1594484654541173543) } },
    { { -INT64_C( 3637143188598831559) },
      { -INT64_C( 2901145689518111239) },
      { -INT64_C( 3637143188598831559), -INT64_C( 2901145689518111239) } },
    { { -INT64_C( 6158004188845355736) },
      {  INT64_C( 5187056111353711980) },
      { -INT64_C( 6158004188845355736),  INT64_C( 5187056111353711980) } },
    { { -INT64_C( 8052959950355475738) },
      {  INT64_C( 1395012986365008936) },
      { -INT64_C( 8052959950355475738),  INT64_C( 1395012986365008936) } },
    { { -INT64_C( 6206607636030694047) },
      {  INT64_C( 2654230134226951809) },
      { -INT64_C( 6206607636030694047),  INT64_C( 2654230134226951809) } },
    { { -INT64_C( 4813553511586041334) },
      { -INT64_C(   23188019053688402) },
      { -INT64_C( 4813553511586041334), -INT64_C(   23188019053688402) } },
    { {  INT64_C(  820235170621871740) },
      { -INT64_C( 2193411526787260883) },
      {  INT64_C(  820235170621871740), -INT64_C( 2193411526787260883) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int64x1x2_t r_ = { { simde_vld1_s64(test_vec[i].r0),
                               simde_vld1_s64(test_vec[i].r1) } };

    int64_t a_[2];
    simde_vst2_s64(a_, r_);

    simde_assert_equal_i(0, simde_memcmp(a_, test_vec[i].a, sizeof(test_vec[i].a)));
  }

  return 0;
#else
  for (int i = 0 ; i < 8 ; i++) {
    simde_int64x1_t a = simde_test_arm_neon_random_i64x1();
    simde_int64x1_t b = simde_test_arm_neon_random_i64x1();
    simde_int64x1x2_t c = {{a, b}};

    simde_test_arm_neon_write_i64x1(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i64x1(2, b, SIMDE_TEST_VEC_POS_MIDDLE);

    int64_t buf[2];
    simde_vst2_s64(buf, c);

    simde_test_codegen_write_vi64(2, sizeof(buf) / sizeof(buf[0]), buf,
                                  SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vst2_u8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint8_t r0[8];
    uint8_t r1[8];
    uint8_t a[16];
  } test_vec[] = {
    { { UINT8_C(137), UINT8_C(176), UINT8_C(156), UINT8_C( 16), UINT8_C( 74), UINT8_C(251), UINT8_C(134), UINT8_C(115) },
      { UINT8_C(110), UINT8_C( 61), UINT8_C( 68), UINT8_C( 47), UINT8_C(  3), UINT8_C(253), UINT8_C( 24), UINT8_C(164) },
      { UINT8_C(137), UINT8_C(110), UINT8_C(176), UINT8_C( 61), UINT8_C(156), UINT8_C( 68), UINT8_C( 16), UINT8_C( 47),
        UINT8_C( 74), UINT8_C(  3), UINT8_C(251), UINT8_C(253), UINT8_C(134), UINT8_C( 24), UINT8_C(115), UINT8_C(164) } },
    { { UINT8_C( 44), UINT8_C( 35), UINT8_C( 76), UINT8_C(171), UINT8_C(181), UINT8_C( 90), UINT8_C(199), UINT8_C(225) },
      { UINT8_C( 58), UINT8_C( 23), UINT8_C(210), UINT8_C(230), UINT8_C(137), UINT8_C(156), UINT8_C(156), UINT8_C( 19) },
      { UINT8_C( 44), UINT8_C( 58), UINT8_C( 35), UINT8_C( 23), UINT8_C( 76), UINT8_C(210), UINT8_C(171), UINT8_C(230),
        UINT8_C(181), UINT8_C(137), UINT8_C( 90), UINT8_C(156), UINT8_C(199), UINT8_C(156), UINT8_C(225), UINT8_C( 19) } },
    { { UINT8_C( 77), UINT8_C( 56), UINT8_C( 35), UINT8_C(151), UINT8_C( 51), UINT8_C(170), UINT8_C( 11), UINT8_C(162) },
      { UINT8_C(231), UINT8_C( 79), UINT8_C(209), UINT8_C(235), UINT8_C( 76), UINT8_C(233), UINT8_C(143), UINT8_C(121) },
      { UINT8_C( 77), UINT8_C(231), UINT8_C( 56), UINT8_C( 79), UINT8_C( 35), UINT8_C(209), UINT8_C(151), UINT8_C(235),
        UINT8_C( 51), UINT8_C( 76), UINT8_C(170), UINT8_C(233), UINT8_C( 11), UINT8_C(143), UINT8_C(162), UINT8_C(121) } },
    { { UINT8_C( 12), UINT8_C(219), UINT8_C( 36), UINT8_C(194), UINT8_C( 53), UINT8_C(235), UINT8_C(163), UINT8_C(112) },
      { UINT8_C(  2), UINT8_C(118), UINT8_C( 86), UINT8_C(140), UINT8_C( 18), UINT8_C(242), UINT8_C(159), UINT8_C( 95) },
      { UINT8_C( 12), UINT8_C(  2), UINT8_C(219), UINT8_C(118), UINT8_C( 36), UINT8_C( 86), UINT8_C(194), UINT8_C(140),
        UINT8_C( 53), UINT8_C( 18), UINT8_C(235), UINT8_C(242), UINT8_C(163), UINT8_C(159), UINT8_C(112), UINT8_C( 95) } },
    { { UINT8_C( 43), UINT8_C(194), UINT8_C(247), UINT8_C( 94), UINT8_C(108), UINT8_C(  2), UINT8_C(  0), UINT8_C( 84) },
      { UINT8_C( 81), UINT8_C(210), UINT8_C( 63), UINT8_C(158), UINT8_C(187), UINT8_C(206), UINT8_C( 23), UINT8_C(200) },
      { UINT8_C( 43), UINT8_C( 81), UINT8_C(194), UINT8_C(210), UINT8_C(247), UINT8_C( 63), UINT8_C( 94), UINT8_C(158),
        UINT8_C(108), UINT8_C(187), UINT8_C(  2), UINT8_C(206), UINT8_C(  0), UINT8_C( 23), UINT8_C( 84), UINT8_C(200) } },
    { { UINT8_C(170), UINT8_C( 59), UINT8_C(138), UINT8_C(223), UINT8_C( 39), UINT8_C( 45), UINT8_C( 79), UINT8_C( 41) },
      { UINT8_C(163), UINT8_C(165), UINT8_C(181), UINT8_C(182), UINT8_C(152), UINT8_C( 84), UINT8_C( 21), UINT8_C(195) },
      { UINT8_C(170), UINT8_C(163), UINT8_C( 59), UINT8_C(165), UINT8_C(138), UINT8_C(181), UINT8_C(223), UINT8_C(182),
        UINT8_C( 39), UINT8_C(152), UINT8_C( 45), UINT8_C( 84), UINT8_C( 79), UINT8_C( 21), UINT8_C( 41), UINT8_C(195) } },
    { { UINT8_C( 23), UINT8_C( 12), UINT8_C( 33), UINT8_C(131), UINT8_C( 14), UINT8_C( 34), UINT8_C(215), UINT8_C( 96) },
      { UINT8_C(244), UINT8_C( 22), UINT8_C(254), UINT8_C(175), UINT8_C(229), UINT8_C( 21), UINT8_C(119), UINT8_C(143) },
      { UINT8_C( 23), UINT8_C(244), UINT8_C( 12), UINT8_C( 22), UINT8_C( 33), UINT8_C(254), UINT8_C(131), UINT8_C(175),
        UINT8_C( 14), UINT8_C(229), UINT8_C( 34), UINT8_C( 21), UINT8_C(215), UINT8_C(119), UINT8_C( 96), UINT8_C(143) } },
    { { UINT8_C( 80), UINT8_C(  1), UINT8_C(110), UINT8_C(119), UINT8_C( 47), UINT8_C(190), UINT8_C(161), UINT8_C(210) },
      { UINT8_C( 99), UINT8_C( 86), UINT8_C(136), UINT8_C(251), UINT8_C(171), UINT8_C(158), UINT8_C(190), UINT8_C(194) },
      { UINT8_C( 80), UINT8_C( 99), UINT8_C(  1), UINT8_C( 86), UINT8_C(110), UINT8_C(136), UINT8_C(119), UINT8_C(251),
        UINT8_C( 47), UINT8_C(171), UINT8_C(190), UINT8_C(158), UINT8_C(161), UINT8_C(190), UINT8_C(210), UINT8_C(194) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint8x8x2_t r_ = { { simde_vld1_u8(test_vec[i].r0),
                               simde_vld1_u8(test_vec[i].r1) } };

    uint8_t a_[16];
    simde_vst2_u8(a_, r_);

    simde_assert_equal_i(0, simde_memcmp(a_, test_vec[i].a, sizeof(test_vec[i].a)));
  }

  return 0;
#else
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint8x8_t a = simde_test_arm_neon_random_u8x8();
    simde_uint8x8_t b = simde_test_arm_neon_random_u8x8();
    simde_uint8x8x2_t c = {{a, b}};

    simde_test_arm_neon_write_u8x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u8x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);

    uint8_t buf[16];
    simde_vst2_u8(buf, c);

    simde_test_codegen_write_vu8(2, sizeof(buf) / sizeof(buf[0]), buf,
                                 SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vst2_u16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint16_t r0[4];
    uint16_t r1[4];
    uint16_t a[8];
  } test_vec[] = {
    { { UINT16_C(28698), UINT16_C(17828), UINT16_C(55501), UINT16_C(64260) },
      { UINT16_C(45604), UINT16_C(24547), UINT16_C(40446), UINT16_C(46146) },
      { UINT16_C(28698), UINT16_C(45604), UINT16_C(17828), UINT16_C(24547), UINT16_C(55501), UINT16_C(40446), UINT16_C(64260), UINT16_C(46146) } },
    { { UINT16_C(41261), UINT16_C(55325), UINT16_C(25201), UINT16_C(49063) },
      { UINT16_C(46317), UINT16_C(50252), UINT16_C(36800), UINT16_C(56019) },
      { UINT16_C(41261), UINT16_C(46317), UINT16_C(55325), UINT16_C(50252), UINT16_C(25201), UINT16_C(36800), UINT16_C(49063), UINT16_C(56019) } },
    { { UINT16_C(30719), UINT16_C(52512), UINT16_C( 9295), UINT16_C(29896) },
      { UINT16_C(44247), UINT16_C(54739), UINT16_C( 5705), UINT16_C(30345) },
      { UINT16_C(30719), UINT16_C(44247), UINT16_C(52512), UINT16_C(54739), UINT16_C( 9295), UINT16_C( 5705), UINT16_C(29896), UINT16_C(30345) } },
    { { UINT16_C(42679), UINT16_C(10319), UINT16_C(62984), UINT16_C(62951) },
      { UINT16_C(13226), UINT16_C(27322), UINT16_C(36290), UINT16_C(49733) },
      { UINT16_C(42679), UINT16_C(13226), UINT16_C(10319), UINT16_C(27322), UINT16_C(62984), UINT16_C(36290), UINT16_C(62951), UINT16_C(49733) } },
    { { UINT16_C(25861), UINT16_C(21647), UINT16_C(22409), UINT16_C(24776) },
      { UINT16_C(39939), UINT16_C(19765), UINT16_C(48818), UINT16_C(27075) },
      { UINT16_C(25861), UINT16_C(39939), UINT16_C(21647), UINT16_C(19765), UINT16_C(22409), UINT16_C(48818), UINT16_C(24776), UINT16_C(27075) } },
    { { UINT16_C( 4708), UINT16_C(28049), UINT16_C(30728), UINT16_C(45922) },
      { UINT16_C( 7339), UINT16_C(28189), UINT16_C(25258), UINT16_C(44848) },
      { UINT16_C( 4708), UINT16_C( 7339), UINT16_C(28049), UINT16_C(28189), UINT16_C(30728), UINT16_C(25258), UINT16_C(45922), UINT16_C(44848) } },
    { { UINT16_C(49095), UINT16_C(20739), UINT16_C(52246), UINT16_C( 6833) },
      { UINT16_C(59240), UINT16_C( 6759), UINT16_C(10917), UINT16_C( 2691) },
      { UINT16_C(49095), UINT16_C(59240), UINT16_C(20739), UINT16_C( 6759), UINT16_C(52246), UINT16_C(10917), UINT16_C( 6833), UINT16_C( 2691) } },
    { { UINT16_C( 5181), UINT16_C(17783), UINT16_C(55692), UINT16_C(14328) },
      { UINT16_C( 5878), UINT16_C(41125), UINT16_C(54648), UINT16_C(16463) },
      { UINT16_C( 5181), UINT16_C( 5878), UINT16_C(17783), UINT16_C(41125), UINT16_C(55692), UINT16_C(54648), UINT16_C(14328), UINT16_C(16463) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint16x4x2_t r_ = { { simde_vld1_u16(test_vec[i].r0),
                                simde_vld1_u16(test_vec[i].r1) } };

    uint16_t a_[8];
    simde_vst2_u16(a_, r_);

    simde_assert_equal_i(0, simde_memcmp(a_, test_vec[i].a, sizeof(test_vec[i].a)));
  }

  return 0;
#else
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint16x4_t a = simde_test_arm_neon_random_u16x4();
    simde_uint16x4_t b = simde_test_arm_neon_random_u16x4();
    simde_uint16x4x2_t c = {{a, b}};

    simde_test_arm_neon_write_u16x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u16x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);

    uint16_t buf[8];
    simde_vst2_u16(buf, c);

    simde_test_codegen_write_vu16(2, sizeof(buf) / sizeof(buf[0]), buf,
                                  SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vst2_u32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint32_t r0[2];
    uint32_t r1[2];
    uint32_t a[4];
  } test_vec[] = {
    { { UINT32_C(3423587604), UINT32_C(4056400014) },
      { UINT32_C(2108728707), UINT32_C( 690694705) },
      { UINT32_C(3423587604), UINT32_C(2108728707), UINT32_C(4056400014), UINT32_C( 690694705) } },
    { { UINT32_C( 317309930), UINT32_C(2111963216) },
      { UINT32_C(1788610845), UINT32_C( 357539073) },
      { UINT32_C( 317309930), UINT32_C(1788610845), UINT32_C(2111963216), UINT32_C( 357539073) } },
    { { UINT32_C(4175519594), UINT32_C(2733221919) },
      { UINT32_C(2132843086), UINT32_C(2930265028) },
      { UINT32_C(4175519594), UINT32_C(2132843086), UINT32_C(2733221919), UINT32_C(2930265028) } },
    { { UINT32_C(1589678606), UINT32_C(2950407058) },
      { UINT32_C(2904193196), UINT32_C(2160224533) },
      { UINT32_C(1589678606), UINT32_C(2904193196), UINT32_C(2950407058), UINT32_C(2160224533) } },
    { { UINT32_C(3883443144), UINT32_C(2575983179) },
      { UINT32_C(3222907644), UINT32_C(  57590261) },
      { UINT32_C(3883443144), UINT32_C(3222907644), UINT32_C(2575983179), UINT32_C(  57590261) } },
    { { UINT32_C(3848417107), UINT32_C(2123709906) },
      { UINT32_C(3408637877), UINT32_C(3779849496) },
      { UINT32_C(3848417107), UINT32_C(3408637877), UINT32_C(2123709906), UINT32_C(3779849496) } },
    { { UINT32_C(3687367568), UINT32_C( 561336869) },
      { UINT32_C(4058091260), UINT32_C(2750763087) },
      { UINT32_C(3687367568), UINT32_C(4058091260), UINT32_C( 561336869), UINT32_C(2750763087) } },
    { { UINT32_C(1367889791), UINT32_C(1255087508) },
      { UINT32_C(3843422924), UINT32_C(2009489639) },
      { UINT32_C(1367889791), UINT32_C(3843422924), UINT32_C(1255087508), UINT32_C(2009489639) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint32x2x2_t r_ = { { simde_vld1_u32(test_vec[i].r0),
                                simde_vld1_u32(test_vec[i].r1) } };

    uint32_t a_[4];
    simde_vst2_u32(a_, r_);

    simde_assert_equal_i(0, simde_memcmp(a_, test_vec[i].a, sizeof(test_vec[i].a)));
  }

  return 0;
#else
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint32x2_t a = simde_test_arm_neon_random_u32x2();
    simde_uint32x2_t b = simde_test_arm_neon_random_u32x2();
    simde_uint32x2x2_t c = {{a, b}};

    simde_test_arm_neon_write_u32x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u32x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);

    uint32_t buf[4];
    simde_vst2_u32(buf, c);

    simde_test_codegen_write_vu32(2, sizeof(buf) / sizeof(buf[0]), buf,
                                  SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vst2_u64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint64_t r0[1];
    uint64_t r1[1];
    uint64_t a[2];
  } test_vec[] = {
    { { UINT64_C( 8807445114109895209) },
      { UINT64_C( 6519373925169032403) },
      { UINT64_C( 8807445114109895209), UINT64_C( 6519373925169032403) } },
    { { UINT64_C( 5321430397114178273) },
      { UINT64_C(12837102308479805126) },
      { UINT64_C( 5321430397114178273), UINT64_C(12837102308479805126) } },
    { { UINT64_C(10724138065184386222) },
      { UINT64_C(15067712779132303542) },
      { UINT64_C(10724138065184386222), UINT64_C(15067712779132303542) } },
    { { UINT64_C( 6496494778930499359) },
      { UINT64_C(12434900361196433749) },
      { UINT64_C( 6496494778930499359), UINT64_C(12434900361196433749) } },
    { { UINT64_C(11629659740313034767) },
      { UINT64_C(10597671910934458193) },
      { UINT64_C(11629659740313034767), UINT64_C(10597671910934458193) } },
    { { UINT64_C(16968607465622103949) },
      { UINT64_C(12445235346039044364) },
      { UINT64_C(16968607465622103949), UINT64_C(12445235346039044364) } },
    { { UINT64_C(16575463885834599547) },
      { UINT64_C( 8436994618425829647) },
      { UINT64_C(16575463885834599547), UINT64_C( 8436994618425829647) } },
    { { UINT64_C( 3396297011456542880) },
      { UINT64_C(14075137826483727371) },
      { UINT64_C( 3396297011456542880), UINT64_C(14075137826483727371) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint64x1x2_t r_ = { { simde_vld1_u64(test_vec[i].r0),
                               simde_vld1_u64(test_vec[i].r1) } };

    uint64_t a_[2];
    simde_vst2_u64(a_, r_);

    simde_assert_equal_i(0, simde_memcmp(a_, test_vec[i].a, sizeof(test_vec[i].a)));
  }

  return 0;
#else
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint64x1_t a = simde_test_arm_neon_random_u64x1();
    simde_uint64x1_t b = simde_test_arm_neon_random_u64x1();
    simde_uint64x1x2_t c = {{a, b}};

    simde_test_arm_neon_write_u64x1(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u64x1(2, b, SIMDE_TEST_VEC_POS_MIDDLE);

    uint64_t buf[2];
    simde_vst2_u64(buf, c);

    simde_test_codegen_write_vu64(2, sizeof(buf) / sizeof(buf[0]), buf,
                                  SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vst2q_f32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float32 r0[4];
    simde_float32 r1[4];
    simde_float32 a[8];
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(   423.81), SIMDE_FLOAT32_C(  -124.71), SIMDE_FLOAT32_C(   516.24), SIMDE_FLOAT32_C(  -556.87) },
      { SIMDE_FLOAT32_C(  -912.68), SIMDE_FLOAT32_C(   430.93), SIMDE_FLOAT32_C(  -749.76), SIMDE_FLOAT32_C(   580.03) },
      { SIMDE_FLOAT32_C(   423.81), SIMDE_FLOAT32_C(  -912.68), SIMDE_FLOAT32_C(  -124.71), SIMDE_FLOAT32_C(   430.93),
        SIMDE_FLOAT32_C(   516.24), SIMDE_FLOAT32_C(  -749.76), SIMDE_FLOAT32_C(  -556.87), SIMDE_FLOAT32_C(   580.03) } },
    { { SIMDE_FLOAT32_C(  -326.15), SIMDE_FLOAT32_C(  -517.81), SIMDE_FLOAT32_C(   402.04), SIMDE_FLOAT32_C(  -647.44) },
      { SIMDE_FLOAT32_C(  -648.95), SIMDE_FLOAT32_C(   211.81), SIMDE_FLOAT32_C(   771.88), SIMDE_FLOAT32_C(   212.81) },
      { SIMDE_FLOAT32_C(  -326.15), SIMDE_FLOAT32_C(  -648.95), SIMDE_FLOAT32_C(  -517.81), SIMDE_FLOAT32_C(   211.81),
        SIMDE_FLOAT32_C(   402.04), SIMDE_FLOAT32_C(   771.88), SIMDE_FLOAT32_C(  -647.44), SIMDE_FLOAT32_C(   212.81) } },
    { { SIMDE_FLOAT32_C(    47.52), SIMDE_FLOAT32_C(   289.92), SIMDE_FLOAT32_C(   340.43), SIMDE_FLOAT32_C(  -471.48) },
      { SIMDE_FLOAT32_C(  -880.10), SIMDE_FLOAT32_C(   -75.95), SIMDE_FLOAT32_C(  -630.49), SIMDE_FLOAT32_C(   244.57) },
      { SIMDE_FLOAT32_C(    47.52), SIMDE_FLOAT32_C(  -880.10), SIMDE_FLOAT32_C(   289.92), SIMDE_FLOAT32_C(   -75.95),
        SIMDE_FLOAT32_C(   340.43), SIMDE_FLOAT32_C(  -630.49), SIMDE_FLOAT32_C(  -471.48), SIMDE_FLOAT32_C(   244.57) } },
    { { SIMDE_FLOAT32_C(   582.67), SIMDE_FLOAT32_C(   160.87), SIMDE_FLOAT32_C(  -192.06), SIMDE_FLOAT32_C(   463.37) },
      { SIMDE_FLOAT32_C(  -193.22), SIMDE_FLOAT32_C(   368.17), SIMDE_FLOAT32_C(   886.93), SIMDE_FLOAT32_C(  -769.41) },
      { SIMDE_FLOAT32_C(   582.67), SIMDE_FLOAT32_C(  -193.22), SIMDE_FLOAT32_C(   160.87), SIMDE_FLOAT32_C(   368.17),
        SIMDE_FLOAT32_C(  -192.06), SIMDE_FLOAT32_C(   886.93), SIMDE_FLOAT32_C(   463.37), SIMDE_FLOAT32_C(  -769.41) } },
    { { SIMDE_FLOAT32_C(  -756.54), SIMDE_FLOAT32_C(   403.17), SIMDE_FLOAT32_C(  -326.28), SIMDE_FLOAT32_C(  -669.22) },
      { SIMDE_FLOAT32_C(  -165.90), SIMDE_FLOAT32_C(   -76.04), SIMDE_FLOAT32_C(   910.81), SIMDE_FLOAT32_C(   507.95) },
      { SIMDE_FLOAT32_C(  -756.54), SIMDE_FLOAT32_C(  -165.90), SIMDE_FLOAT32_C(   403.17), SIMDE_FLOAT32_C(   -76.04),
        SIMDE_FLOAT32_C(  -326.28), SIMDE_FLOAT32_C(   910.81), SIMDE_FLOAT32_C(  -669.22), SIMDE_FLOAT32_C(   507.95) } },
    { { SIMDE_FLOAT32_C(   406.16), SIMDE_FLOAT32_C(   312.85), SIMDE_FLOAT32_C(   860.51), SIMDE_FLOAT32_C(   757.21) },
      { SIMDE_FLOAT32_C(  -475.34), SIMDE_FLOAT32_C(   632.40), SIMDE_FLOAT32_C(   -29.99), SIMDE_FLOAT32_C(   572.19) },
      { SIMDE_FLOAT32_C(   406.16), SIMDE_FLOAT32_C(  -475.34), SIMDE_FLOAT32_C(   312.85), SIMDE_FLOAT32_C(   632.40),
        SIMDE_FLOAT32_C(   860.51), SIMDE_FLOAT32_C(   -29.99), SIMDE_FLOAT32_C(   757.21), SIMDE_FLOAT32_C(   572.19) } },
    { { SIMDE_FLOAT32_C(   -77.68), SIMDE_FLOAT32_C(  -689.55), SIMDE_FLOAT32_C(  -899.30), SIMDE_FLOAT32_C(    42.23) },
      { SIMDE_FLOAT32_C(   234.49), SIMDE_FLOAT32_C(  -529.79), SIMDE_FLOAT32_C(  -713.20), SIMDE_FLOAT32_C(  -182.84) },
      { SIMDE_FLOAT32_C(   -77.68), SIMDE_FLOAT32_C(   234.49), SIMDE_FLOAT32_C(  -689.55), SIMDE_FLOAT32_C(  -529.79),
        SIMDE_FLOAT32_C(  -899.30), SIMDE_FLOAT32_C(  -713.20), SIMDE_FLOAT32_C(    42.23), SIMDE_FLOAT32_C(  -182.84) } },
    { { SIMDE_FLOAT32_C(   631.08), SIMDE_FLOAT32_C(    94.74), SIMDE_FLOAT32_C(  -719.47), SIMDE_FLOAT32_C(  -562.14) },
      { SIMDE_FLOAT32_C(  -537.09), SIMDE_FLOAT32_C(  -832.54), SIMDE_FLOAT32_C(  -331.55), SIMDE_FLOAT32_C(  -293.63) },
      { SIMDE_FLOAT32_C(   631.08), SIMDE_FLOAT32_C(  -537.09), SIMDE_FLOAT32_C(    94.74), SIMDE_FLOAT32_C(  -832.54),
        SIMDE_FLOAT32_C(  -719.47), SIMDE_FLOAT32_C(  -331.55), SIMDE_FLOAT32_C(  -562.14), SIMDE_FLOAT32_C(  -293.63) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x4x2_t r_ = { { simde_vld1q_f32(test_vec[i].r0),
                                 simde_vld1q_f32(test_vec[i].r1) } };

    simde_float32 a_[8];
    simde_vst2q_f32(a_, r_);

    simde_assert_equal_i(0, simde_memcmp(a_, test_vec[i].a, sizeof(test_vec[i].a)));
  }

  return 0;
#else
  for (int i = 0 ; i < 8 ; i++) {
    simde_float32x4_t a = simde_test_arm_neon_random_f32x4(-1000.0f, 1000.0f);
    simde_float32x4_t b = simde_test_arm_neon_random_f32x4(-1000.0f, 1000.0f);
    simde_float32x4x2_t c = {{a, b}};

    simde_test_arm_neon_write_f32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);

    simde_float32 buf[8];
    simde_vst2q_f32(buf, c);

    simde_test_codegen_write_vf32(2, sizeof(buf) / sizeof(buf[0]), buf,
                                  SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vst2q_f64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float64 r0[2];
    simde_float64 r1[2];
    simde_float64 a[4];
  } test_vec[] = {
    { { SIMDE_FLOAT64_C(   773.26), SIMDE_FLOAT64_C(   508.70) },
      { SIMDE_FLOAT64_C(  -400.17), SIMDE_FLOAT64_C(   386.84) },
      { SIMDE_FLOAT64_C(   773.26), SIMDE_FLOAT64_C(  -400.17), SIMDE_FLOAT64_C(   508.70), SIMDE_FLOAT64_C(   386.84) } },
    { { SIMDE_FLOAT64_C(  -216.30), SIMDE_FLOAT64_C(  -930.29) },
      { SIMDE_FLOAT64_C(   128.42), SIMDE_FLOAT64_C(  -901.09) },
      { SIMDE_FLOAT64_C(  -216.30), SIMDE_FLOAT64_C(   128.42), SIMDE_FLOAT64_C(  -930.29), SIMDE_FLOAT64_C(  -901.09) } },
    { { SIMDE_FLOAT64_C(   560.58), SIMDE_FLOAT64_C(  -592.22) },
      { SIMDE_FLOAT64_C(  -591.77), SIMDE_FLOAT64_C(    51.46) },
      { SIMDE_FLOAT64_C(   560.58), SIMDE_FLOAT64_C(  -591.77), SIMDE_FLOAT64_C(  -592.22), SIMDE_FLOAT64_C(    51.46) } },
    { { SIMDE_FLOAT64_C(  -393.97), SIMDE_FLOAT64_C(   150.15) },
      { SIMDE_FLOAT64_C(  -862.47), SIMDE_FLOAT64_C(  -343.60) },
      { SIMDE_FLOAT64_C(  -393.97), SIMDE_FLOAT64_C(  -862.47), SIMDE_FLOAT64_C(   150.15), SIMDE_FLOAT64_C(  -343.60) } },
    { { SIMDE_FLOAT64_C(   750.40), SIMDE_FLOAT64_C(   373.85) },
      { SIMDE_FLOAT64_C(    56.86), SIMDE_FLOAT64_C(  -709.04) },
      { SIMDE_FLOAT64_C(   750.40), SIMDE_FLOAT64_C(    56.86), SIMDE_FLOAT64_C(   373.85), SIMDE_FLOAT64_C(  -709.04) } },
    { { SIMDE_FLOAT64_C(  -350.28), SIMDE_FLOAT64_C(  -848.47) },
      { SIMDE_FLOAT64_C(   -16.93), SIMDE_FLOAT64_C(  -124.16) },
      { SIMDE_FLOAT64_C(  -350.28), SIMDE_FLOAT64_C(   -16.93), SIMDE_FLOAT64_C(  -848.47), SIMDE_FLOAT64_C(  -124.16) } },
    { { SIMDE_FLOAT64_C(   348.09), SIMDE_FLOAT64_C(   770.67) },
      { SIMDE_FLOAT64_C(  -435.48), SIMDE_FLOAT64_C(   628.39) },
      { SIMDE_FLOAT64_C(   348.09), SIMDE_FLOAT64_C(  -435.48), SIMDE_FLOAT64_C(   770.67), SIMDE_FLOAT64_C(   628.39) } },
    { { SIMDE_FLOAT64_C(    89.72), SIMDE_FLOAT64_C(  -857.28) },
      { SIMDE_FLOAT64_C(  -943.86), SIMDE_FLOAT64_C(  -137.01) },
      { SIMDE_FLOAT64_C(    89.72), SIMDE_FLOAT64_C(  -943.86), SIMDE_FLOAT64_C(  -857.28), SIMDE_FLOAT64_C(  -137.01) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float64x2x2_t r_ = { { simde_vld1q_f64(test_vec[i].r0),
                                 simde_vld1q_f64(test_vec[i].r1) } };

    simde_float64 a_[4];
    simde_vst2q_f64(a_, r_);

    simde_assert_equal_i(0, simde_memcmp(a_, test_vec[i].a, sizeof(test_vec[i].a)));
  }

  return 0;
#else
  for (int i = 0 ; i < 8 ; i++) {
    simde_float64x2_t a = simde_test_arm_neon_random_f64x2(-1000.0, 1000.0);
    simde_float64x2_t b = simde_test_arm_neon_random_f64x2(-1000.0, 1000.0);
    simde_float64x2x2_t c = {{a, b}};

    simde_test_arm_neon_write_f64x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f64x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);

    simde_float64 buf[4];
    simde_vst2q_f64(buf, c);

    simde_test_codegen_write_vf64(2, sizeof(buf) / sizeof(buf[0]), buf,
                                  SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vst2q_s8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int8_t r0[16];
    int8_t r1[16];
    int8_t a[32];
  } test_vec[] = {
    { { -INT8_C(   6),  INT8_C(  91), -INT8_C(  60), -INT8_C(  95),  INT8_C(  86), -INT8_C(  21),  INT8_C(  82),  INT8_C(  86),
         INT8_C(  33),  INT8_C( 124),  INT8_C(  90),  INT8_C( 100),  INT8_C(  33),  INT8_C(  93), -INT8_C(  40),  INT8_C(  72) },
      { -INT8_C(  48), -INT8_C(  94), -INT8_C(  17), -INT8_C(  58), -INT8_C(  83), -INT8_C(  23), -INT8_C(  17),  INT8_C(  96),
        -INT8_C(  94), -INT8_C(  18),  INT8_C(  24),  INT8_C(  95),  INT8_C(  49), -INT8_C(   2),  INT8_C(  40),  INT8_C(  43) },
      { -INT8_C(   6), -INT8_C(  48),  INT8_C(  91), -INT8_C(  94), -INT8_C(  60), -INT8_C(  17), -INT8_C(  95), -INT8_C(  58),
         INT8_C(  86), -INT8_C(  83), -INT8_C(  21), -INT8_C(  23),  INT8_C(  82), -INT8_C(  17),  INT8_C(  86),  INT8_C(  96),
         INT8_C(  33), -INT8_C(  94),  INT8_C( 124), -INT8_C(  18),  INT8_C(  90),  INT8_C(  24),  INT8_C( 100),  INT8_C(  95),
         INT8_C(  33),  INT8_C(  49),  INT8_C(  93), -INT8_C(   2), -INT8_C(  40),  INT8_C(  40),  INT8_C(  72),  INT8_C(  43) } },
    { {  INT8_C(  90), -INT8_C(  20), -INT8_C(  51), -INT8_C(  80), -INT8_C(  41),  INT8_C(  31),  INT8_C(   7), -INT8_C(   8),
        -INT8_C( 101),  INT8_C(  97),  INT8_C(  93), -INT8_C(  68), -INT8_C(  65),  INT8_C(  53),  INT8_C(   4), -INT8_C( 113) },
      { -INT8_C(  41), -INT8_C(  13),  INT8_C(  85), -INT8_C( 124), -INT8_C(  36),  INT8_C(  68), -INT8_C(  28),      INT8_MAX,
         INT8_C(  51), -INT8_C(   4), -INT8_C(  34),  INT8_C( 100), -INT8_C(   5),  INT8_C(   6), -INT8_C( 113),  INT8_C(  85) },
      {  INT8_C(  90), -INT8_C(  41), -INT8_C(  20), -INT8_C(  13), -INT8_C(  51),  INT8_C(  85), -INT8_C(  80), -INT8_C( 124),
        -INT8_C(  41), -INT8_C(  36),  INT8_C(  31),  INT8_C(  68),  INT8_C(   7), -INT8_C(  28), -INT8_C(   8),      INT8_MAX,
        -INT8_C( 101),  INT8_C(  51),  INT8_C(  97), -INT8_C(   4),  INT8_C(  93), -INT8_C(  34), -INT8_C(  68),  INT8_C( 100),
        -INT8_C(  65), -INT8_C(   5),  INT8_C(  53),  INT8_C(   6),  INT8_C(   4), -INT8_C( 113), -INT8_C( 113),  INT8_C(  85) } },
    { { -INT8_C(  14),  INT8_C(  92),  INT8_C(   5), -INT8_C(  55),  INT8_C( 124),  INT8_C(  12), -INT8_C(  63),  INT8_C(  23),
         INT8_C( 110),  INT8_C(  30), -INT8_C(  44),  INT8_C(  45),  INT8_C(  83), -INT8_C(  40), -INT8_C(  68),  INT8_C(  42) },
      { -INT8_C(  52),  INT8_C(  17), -INT8_C(  82), -INT8_C(  88),  INT8_C(  85), -INT8_C( 109),  INT8_C(  39), -INT8_C( 120),
        -INT8_C( 113),  INT8_C(   5), -INT8_C(  20), -INT8_C( 118),  INT8_C(  11),  INT8_C( 124), -INT8_C(  33), -INT8_C(   3) },
      { -INT8_C(  14), -INT8_C(  52),  INT8_C(  92),  INT8_C(  17),  INT8_C(   5), -INT8_C(  82), -INT8_C(  55), -INT8_C(  88),
         INT8_C( 124),  INT8_C(  85),  INT8_C(  12), -INT8_C( 109), -INT8_C(  63),  INT8_C(  39),  INT8_C(  23), -INT8_C( 120),
         INT8_C( 110), -INT8_C( 113),  INT8_C(  30),  INT8_C(   5), -INT8_C(  44), -INT8_C(  20),  INT8_C(  45), -INT8_C( 118),
         INT8_C(  83),  INT8_C(  11), -INT8_C(  40),  INT8_C( 124), -INT8_C(  68), -INT8_C(  33),  INT8_C(  42), -INT8_C(   3) } },
    { { -INT8_C(  40), -INT8_C(  27), -INT8_C(  58),  INT8_C(  84), -INT8_C(  15), -INT8_C( 120),  INT8_C( 108),  INT8_C(  95),
        -INT8_C(  90),  INT8_C(  64), -INT8_C( 116), -INT8_C(   6),  INT8_C(  24),  INT8_C(  72),  INT8_C(  36), -INT8_C(  28) },
      {  INT8_C(  89), -INT8_C(  45), -INT8_C( 115), -INT8_C(  81),  INT8_C( 102), -INT8_C(  76),  INT8_C(  55), -INT8_C(  11),
        -INT8_C(  70),  INT8_C(  36),      INT8_MIN, -INT8_C(  59), -INT8_C(  96),  INT8_C(  95), -INT8_C(  61),  INT8_C( 120) },
      { -INT8_C(  40),  INT8_C(  89), -INT8_C(  27), -INT8_C(  45), -INT8_C(  58), -INT8_C( 115),  INT8_C(  84), -INT8_C(  81),
        -INT8_C(  15),  INT8_C( 102), -INT8_C( 120), -INT8_C(  76),  INT8_C( 108),  INT8_C(  55),  INT8_C(  95), -INT8_C(  11),
        -INT8_C(  90), -INT8_C(  70),  INT8_C(  64),  INT8_C(  36), -INT8_C( 116),      INT8_MIN, -INT8_C(   6), -INT8_C(  59),
         INT8_C(  24), -INT8_C(  96),  INT8_C(  72),  INT8_C(  95),  INT8_C(  36), -INT8_C(  61), -INT8_C(  28),  INT8_C( 120) } },
    { {  INT8_C(  68), -INT8_C( 119), -INT8_C(  51),  INT8_C(  54),  INT8_C(  17),  INT8_C(  57), -INT8_C( 107), -INT8_C(  72),
         INT8_C( 121),  INT8_C(  34), -INT8_C(  78), -INT8_C( 111),  INT8_C( 106), -INT8_C(  42),  INT8_C( 118), -INT8_C(  60) },
      { -INT8_C(  87),  INT8_C(   3),  INT8_C( 115),  INT8_C(  15), -INT8_C(  73), -INT8_C(  86),  INT8_C(   5),  INT8_C( 113),
        -INT8_C(  50), -INT8_C( 123),  INT8_C(  55),  INT8_C( 110), -INT8_C(  28), -INT8_C(   6), -INT8_C(  25),  INT8_C(  41) },
      {  INT8_C(  68), -INT8_C(  87), -INT8_C( 119),  INT8_C(   3), -INT8_C(  51),  INT8_C( 115),  INT8_C(  54),  INT8_C(  15),
         INT8_C(  17), -INT8_C(  73),  INT8_C(  57), -INT8_C(  86), -INT8_C( 107),  INT8_C(   5), -INT8_C(  72),  INT8_C( 113),
         INT8_C( 121), -INT8_C(  50),  INT8_C(  34), -INT8_C( 123), -INT8_C(  78),  INT8_C(  55), -INT8_C( 111),  INT8_C( 110),
         INT8_C( 106), -INT8_C(  28), -INT8_C(  42), -INT8_C(   6),  INT8_C( 118), -INT8_C(  25), -INT8_C(  60),  INT8_C(  41) } },
    { { -INT8_C( 125), -INT8_C(  76),  INT8_C(  95), -INT8_C( 107), -INT8_C(  19), -INT8_C(  12),  INT8_C(  77),  INT8_C( 102),
         INT8_C(  22), -INT8_C(   1), -INT8_C(   9), -INT8_C( 127), -INT8_C(  43),  INT8_C( 109),  INT8_C(  69),      INT8_MAX },
      {  INT8_C( 112), -INT8_C(  72), -INT8_C( 114),  INT8_C(  40),  INT8_C(  98), -INT8_C( 109), -INT8_C( 103),  INT8_C(  49),
         INT8_C(  24), -INT8_C(  48), -INT8_C(  97), -INT8_C(   3), -INT8_C(  54), -INT8_C( 122),  INT8_C(  38),  INT8_C(  78) },
      { -INT8_C( 125),  INT8_C( 112), -INT8_C(  76), -INT8_C(  72),  INT8_C(  95), -INT8_C( 114), -INT8_C( 107),  INT8_C(  40),
        -INT8_C(  19),  INT8_C(  98), -INT8_C(  12), -INT8_C( 109),  INT8_C(  77), -INT8_C( 103),  INT8_C( 102),  INT8_C(  49),
         INT8_C(  22),  INT8_C(  24), -INT8_C(   1), -INT8_C(  48), -INT8_C(   9), -INT8_C(  97), -INT8_C( 127), -INT8_C(   3),
        -INT8_C(  43), -INT8_C(  54),  INT8_C( 109), -INT8_C( 122),  INT8_C(  69),  INT8_C(  38),      INT8_MAX,  INT8_C(  78) } },
    { {  INT8_C(  58), -INT8_C( 123), -INT8_C(  29),  INT8_C(  39),  INT8_C( 121),  INT8_C(  48), -INT8_C( 115), -INT8_C( 112),
         INT8_C(  47), -INT8_C( 123),  INT8_C(  17),  INT8_C(   4), -INT8_C(  14),  INT8_C(  86), -INT8_C( 125),  INT8_C(  99) },
      {  INT8_C(  14),  INT8_C(  18), -INT8_C( 117),  INT8_C( 112), -INT8_C(  91),  INT8_C(  36), -INT8_C(  95), -INT8_C(  66),
        -INT8_C(  11),  INT8_C(  65), -INT8_C(  69), -INT8_C(  65), -INT8_C(  57), -INT8_C(  31),  INT8_C(  13),  INT8_C(   2) },
      {  INT8_C(  58),  INT8_C(  14), -INT8_C( 123),  INT8_C(  18), -INT8_C(  29), -INT8_C( 117),  INT8_C(  39),  INT8_C( 112),
         INT8_C( 121), -INT8_C(  91),  INT8_C(  48),  INT8_C(  36), -INT8_C( 115), -INT8_C(  95), -INT8_C( 112), -INT8_C(  66),
         INT8_C(  47), -INT8_C(  11), -INT8_C( 123),  INT8_C(  65),  INT8_C(  17), -INT8_C(  69),  INT8_C(   4), -INT8_C(  65),
        -INT8_C(  14), -INT8_C(  57),  INT8_C(  86), -INT8_C(  31), -INT8_C( 125),  INT8_C(  13),  INT8_C(  99),  INT8_C(   2) } },
    { {  INT8_C( 102), -INT8_C(  16),  INT8_C(  41), -INT8_C(  33),  INT8_C(  32), -INT8_C(  73),  INT8_C( 111),  INT8_C(  79),
         INT8_C(  60),      INT8_MIN,  INT8_C(  84),  INT8_C(  46), -INT8_C(  42), -INT8_C(  41), -INT8_C( 111), -INT8_C(  28) },
      { -INT8_C(  23),  INT8_C(  28),  INT8_C(  85), -INT8_C( 113),  INT8_C(  65), -INT8_C(  10),  INT8_C(  77),  INT8_C(  54),
         INT8_C(  55),  INT8_C(   8), -INT8_C(  11), -INT8_C(   1), -INT8_C(  23),  INT8_C(   3),  INT8_C(   1),  INT8_C(  79) },
      {  INT8_C( 102), -INT8_C(  23), -INT8_C(  16),  INT8_C(  28),  INT8_C(  41),  INT8_C(  85), -INT8_C(  33), -INT8_C( 113),
         INT8_C(  32),  INT8_C(  65), -INT8_C(  73), -INT8_C(  10),  INT8_C( 111),  INT8_C(  77),  INT8_C(  79),  INT8_C(  54),
         INT8_C(  60),  INT8_C(  55),      INT8_MIN,  INT8_C(   8),  INT8_C(  84), -INT8_C(  11),  INT8_C(  46), -INT8_C(   1),
        -INT8_C(  42), -INT8_C(  23), -INT8_C(  41),  INT8_C(   3), -INT8_C( 111),  INT8_C(   1), -INT8_C(  28),  INT8_C(  79) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int8x16x2_t r_ = { { simde_vld1q_s8(test_vec[i].r0),
                               simde_vld1q_s8(test_vec[i].r1) } };

    int8_t a_[32];
    simde_vst2q_s8(a_, r_);

    simde_assert_equal_i(0, simde_memcmp(a_, test_vec[i].a, sizeof(test_vec[i].a)));
  }

  return 0;
#else
  for (int i = 0 ; i < 8 ; i++) {
    simde_int8x16_t a = simde_test_arm_neon_random_i8x16();
    simde_int8x16_t b = simde_test_arm_neon_random_i8x16();
    simde_int8x16x2_t c = {{a, b}};

    simde_test_arm_neon_write_i8x16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i8x16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);

    int8_t buf[32];
    simde_vst2q_s8(buf, c);

    simde_test_codegen_write_vi8(2, sizeof(buf) / sizeof(buf[0]), buf,
                                 SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vst2q_s16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int16_t r0[8];
    int16_t r1[8];
    int16_t a[16];
  } test_vec[] = {
    { { -INT16_C(  2721),  INT16_C( 16396),  INT16_C(   890), -INT16_C( 27695), -INT16_C( 29143),  INT16_C( 16430),  INT16_C(  1834),  INT16_C( 18964) },
      { -INT16_C( 12213),  INT16_C(  2459),  INT16_C(  7250), -INT16_C( 22614), -INT16_C( 17371), -INT16_C( 29290), -INT16_C( 18786), -INT16_C(   543) },
      { -INT16_C(  2721), -INT16_C( 12213),  INT16_C( 16396),  INT16_C(  2459),  INT16_C(   890),  INT16_C(  7250), -INT16_C( 27695), -INT16_C( 22614),
        -INT16_C( 29143), -INT16_C( 17371),  INT16_C( 16430), -INT16_C( 29290),  INT16_C(  1834), -INT16_C( 18786),  INT16_C( 18964), -INT16_C(   543) } },
    { { -INT16_C(  4692),  INT16_C(  9789),  INT16_C(  4080),  INT16_C(  6585), -INT16_C(  6243), -INT16_C( 14503),  INT16_C( 28143),  INT16_C( 14865) },
      { -INT16_C( 21443), -INT16_C( 28860), -INT16_C(  4407), -INT16_C(  4554), -INT16_C( 12886),  INT16_C( 18555),  INT16_C( 23683),  INT16_C( 12102) },
      { -INT16_C(  4692), -INT16_C( 21443),  INT16_C(  9789), -INT16_C( 28860),  INT16_C(  4080), -INT16_C(  4407),  INT16_C(  6585), -INT16_C(  4554),
        -INT16_C(  6243), -INT16_C( 12886), -INT16_C( 14503),  INT16_C( 18555),  INT16_C( 28143),  INT16_C( 23683),  INT16_C( 14865),  INT16_C( 12102) } },
    { { -INT16_C( 31927),  INT16_C( 14678),  INT16_C(  3986),  INT16_C( 12370), -INT16_C( 21513), -INT16_C(  6409),  INT16_C(  2328),  INT16_C( 22048) },
      {  INT16_C( 25781),  INT16_C( 32485),  INT16_C(  7250), -INT16_C(   916), -INT16_C(  5911),  INT16_C( 27717), -INT16_C( 29884), -INT16_C( 29028) },
      { -INT16_C( 31927),  INT16_C( 25781),  INT16_C( 14678),  INT16_C( 32485),  INT16_C(  3986),  INT16_C(  7250),  INT16_C( 12370), -INT16_C(   916),
        -INT16_C( 21513), -INT16_C(  5911), -INT16_C(  6409),  INT16_C( 27717),  INT16_C(  2328), -INT16_C( 29884),  INT16_C( 22048), -INT16_C( 29028) } },
    { { -INT16_C(  3570), -INT16_C( 24121),  INT16_C(  6657), -INT16_C(  1839), -INT16_C( 14139), -INT16_C(  8482), -INT16_C(    47), -INT16_C( 30924) },
      {  INT16_C(  6499), -INT16_C( 18939),  INT16_C( 29237),  INT16_C(  7858), -INT16_C(  2214), -INT16_C( 24949),  INT16_C( 10114), -INT16_C( 28372) },
      { -INT16_C(  3570),  INT16_C(  6499), -INT16_C( 24121), -INT16_C( 18939),  INT16_C(  6657),  INT16_C( 29237), -INT16_C(  1839),  INT16_C(  7858),
        -INT16_C( 14139), -INT16_C(  2214), -INT16_C(  8482), -INT16_C( 24949), -INT16_C(    47),  INT16_C( 10114), -INT16_C( 30924), -INT16_C( 28372) } },
    { { -INT16_C(  3047),  INT16_C(  6706),  INT16_C(   782), -INT16_C( 11501), -INT16_C(  3637), -INT16_C( 25167), -INT16_C(  6672),  INT16_C( 21540) },
      {  INT16_C( 10751),  INT16_C( 13322), -INT16_C( 17253), -INT16_C(  2733), -INT16_C(  8524),  INT16_C( 13972), -INT16_C( 16379),  INT16_C(  7879) },
      { -INT16_C(  3047),  INT16_C( 10751),  INT16_C(  6706),  INT16_C( 13322),  INT16_C(   782), -INT16_C( 17253), -INT16_C( 11501), -INT16_C(  2733),
        -INT16_C(  3637), -INT16_C(  8524), -INT16_C( 25167),  INT16_C( 13972), -INT16_C(  6672), -INT16_C( 16379),  INT16_C( 21540),  INT16_C(  7879) } },
    { { -INT16_C(  1612), -INT16_C( 15816),  INT16_C( 19452), -INT16_C( 14186),  INT16_C( 18237),  INT16_C( 11621), -INT16_C( 30419),  INT16_C( 11393) },
      { -INT16_C( 29774),  INT16_C( 20064), -INT16_C( 19640), -INT16_C(   957), -INT16_C( 10351), -INT16_C( 27086), -INT16_C(  1384),  INT16_C( 19636) },
      { -INT16_C(  1612), -INT16_C( 29774), -INT16_C( 15816),  INT16_C( 20064),  INT16_C( 19452), -INT16_C( 19640), -INT16_C( 14186), -INT16_C(   957),
         INT16_C( 18237), -INT16_C( 10351),  INT16_C( 11621), -INT16_C( 27086), -INT16_C( 30419), -INT16_C(  1384),  INT16_C( 11393),  INT16_C( 19636) } },
    { { -INT16_C(  4621), -INT16_C(  4081), -INT16_C( 23240),  INT16_C( 30136),  INT16_C(  7660),  INT16_C(  6563),  INT16_C(  9382),  INT16_C( 22597) },
      { -INT16_C( 22864), -INT16_C(  1882), -INT16_C(  5543), -INT16_C(  5132),  INT16_C(  9921),  INT16_C( 22913),  INT16_C( 13856),  INT16_C(  5286) },
      { -INT16_C(  4621), -INT16_C( 22864), -INT16_C(  4081), -INT16_C(  1882), -INT16_C( 23240), -INT16_C(  5543),  INT16_C( 30136), -INT16_C(  5132),
         INT16_C(  7660),  INT16_C(  9921),  INT16_C(  6563),  INT16_C( 22913),  INT16_C(  9382),  INT16_C( 13856),  INT16_C( 22597),  INT16_C(  5286) } },
    { { -INT16_C( 19165),  INT16_C( 23300), -INT16_C( 17318),  INT16_C( 18129),  INT16_C( 29913),  INT16_C( 32608), -INT16_C( 23144),  INT16_C( 18647) },
      {  INT16_C( 32331), -INT16_C( 23232),  INT16_C( 13416),  INT16_C( 10640),  INT16_C(  4443),  INT16_C( 31619),  INT16_C( 10567),  INT16_C( 27279) },
      { -INT16_C( 19165),  INT16_C( 32331),  INT16_C( 23300), -INT16_C( 23232), -INT16_C( 17318),  INT16_C( 13416),  INT16_C( 18129),  INT16_C( 10640),
         INT16_C( 29913),  INT16_C(  4443),  INT16_C( 32608),  INT16_C( 31619), -INT16_C( 23144),  INT16_C( 10567),  INT16_C( 18647),  INT16_C( 27279) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x8x2_t r_ = { { simde_vld1q_s16(test_vec[i].r0),
                               simde_vld1q_s16(test_vec[i].r1) } };

    int16_t a_[16];
    simde_vst2q_s16(a_, r_);

    simde_assert_equal_i(0, simde_memcmp(a_, test_vec[i].a, sizeof(test_vec[i].a)));
  }

  return 0;
#else
  for (int i = 0 ; i < 8 ; i++) {
    simde_int16x8_t a = simde_test_arm_neon_random_i16x8();
    simde_int16x8_t b = simde_test_arm_neon_random_i16x8();
    simde_int16x8x2_t c = {{a, b}};

    simde_test_arm_neon_write_i16x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i16x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);

    int16_t buf[16];
    simde_vst2q_s16(buf, c);

    simde_test_codegen_write_vi16(2, sizeof(buf) / sizeof(buf[0]), buf,
                                  SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vst2q_s32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int32_t r0[4];
    int32_t r1[4];
    int32_t a[8];
  } test_vec[] = {
    { {  INT32_C(  1231890958), -INT32_C(    57822455), -INT32_C(   740948287),  INT32_C(  2135141852) },
      { -INT32_C(  2069573063),  INT32_C(  1603362038), -INT32_C(  1762419584),  INT32_C(  1085188657) },
      {  INT32_C(  1231890958), -INT32_C(  2069573063), -INT32_C(    57822455),  INT32_C(  1603362038), -INT32_C(   740948287), -INT32_C(  1762419584),  INT32_C(  2135141852),  INT32_C(  1085188657) } },
    { { -INT32_C(   578216748), -INT32_C(  1864755505), -INT32_C(   127684580), -INT32_C(  1770543523) },
      {  INT32_C(  1863981945), -INT32_C(   120673160),  INT32_C(  2039398728),  INT32_C(  1069104491) },
      { -INT32_C(   578216748),  INT32_C(  1863981945), -INT32_C(  1864755505), -INT32_C(   120673160), -INT32_C(   127684580),  INT32_C(  2039398728), -INT32_C(  1770543523),  INT32_C(  1069104491) } },
    { {  INT32_C(   672940633),  INT32_C(  1958278744),  INT32_C(    74194086),  INT32_C(  1000006594) },
      {  INT32_C(  2007676415), -INT32_C(  1452312479), -INT32_C(  1541210567), -INT32_C(  1797006277) },
      {  INT32_C(   672940633),  INT32_C(  2007676415),  INT32_C(  1958278744), -INT32_C(  1452312479),  INT32_C(    74194086), -INT32_C(  1541210567),  INT32_C(  1000006594), -INT32_C(  1797006277) } },
    { {  INT32_C(  2008809502), -INT32_C(  1645513482),  INT32_C(  1403082896),  INT32_C(   982399803) },
      {  INT32_C(  1370569200), -INT32_C(   335928911),  INT32_C(  1519328543),  INT32_C(   401503225) },
      {  INT32_C(  2008809502),  INT32_C(  1370569200), -INT32_C(  1645513482), -INT32_C(   335928911),  INT32_C(  1403082896),  INT32_C(  1519328543),  INT32_C(   982399803),  INT32_C(   401503225) } },
    { {  INT32_C(  1770957427), -INT32_C(  1358530018),  INT32_C(   218277842), -INT32_C(   750219037) },
      {  INT32_C(  2066086345),  INT32_C(   962993946),  INT32_C(   898889020), -INT32_C(   615677592) },
      {  INT32_C(  1770957427),  INT32_C(  2066086345), -INT32_C(  1358530018),  INT32_C(   962993946),  INT32_C(   218277842),  INT32_C(   898889020), -INT32_C(   750219037), -INT32_C(   615677592) } },
    { {  INT32_C(  1246092075),  INT32_C(   670649173), -INT32_C(   701105165),  INT32_C(  1437171083) },
      { -INT32_C(  1848586634),  INT32_C(   717895406), -INT32_C(  1805623765),  INT32_C(   191868383) },
      {  INT32_C(  1246092075), -INT32_C(  1848586634),  INT32_C(   670649173),  INT32_C(   717895406), -INT32_C(   701105165), -INT32_C(  1805623765),  INT32_C(  1437171083),  INT32_C(   191868383) } },
    { { -INT32_C(   564808568), -INT32_C(   217756160), -INT32_C(   725009847),  INT32_C(   774468279) },
      {  INT32_C(   801110337),  INT32_C(  1532594479), -INT32_C(   940590617), -INT32_C(   271425946) },
      { -INT32_C(   564808568),  INT32_C(   801110337), -INT32_C(   217756160),  INT32_C(  1532594479), -INT32_C(   725009847), -INT32_C(   940590617),  INT32_C(   774468279), -INT32_C(   271425946) } },
    { {  INT32_C(   332211987), -INT32_C(  1106849163), -INT32_C(   997011699), -INT32_C(  2098021311) },
      { -INT32_C(   441339467),  INT32_C(   574622523),  INT32_C(   736702404), -INT32_C(  1608860787) },
      {  INT32_C(   332211987), -INT32_C(   441339467), -INT32_C(  1106849163),  INT32_C(   574622523), -INT32_C(   997011699),  INT32_C(   736702404), -INT32_C(  2098021311), -INT32_C(  1608860787) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x4x2_t r_ = { { simde_vld1q_s32(test_vec[i].r0),
                               simde_vld1q_s32(test_vec[i].r1) } };

    int32_t a_[8];
    simde_vst2q_s32(a_, r_);

    simde_assert_equal_i(0, simde_memcmp(a_, test_vec[i].a, sizeof(test_vec[i].a)));
  }

  return 0;
#else
  for (int i = 0 ; i < 8 ; i++) {
    simde_int32x4_t a = simde_test_arm_neon_random_i32x4();
    simde_int32x4_t b = simde_test_arm_neon_random_i32x4();
    simde_int32x4x2_t c = {{a, b}};

    simde_test_arm_neon_write_i32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);

    int32_t buf[8];
    simde_vst2q_s32(buf, c);

    simde_test_codegen_write_vi32(2, sizeof(buf) / sizeof(buf[0]), buf,
                                  SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vst2q_s64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int64_t r0[2];
    int64_t r1[2];
    int64_t a[4];
  } test_vec[] = {
    { {  INT64_C( 3973218193155053652),  INT64_C( 2124841789486134369) },
      {  INT64_C( 4254946558503982625), -INT64_C( 1327131864618766159) },
      {  INT64_C( 3973218193155053652),  INT64_C( 4254946558503982625),  INT64_C( 2124841789486134369), -INT64_C( 1327131864618766159) } },
    { { -INT64_C( 3852448597841300116), -INT64_C( 2826912879753706930) },
      { -INT64_C(  579608354624263585), -INT64_C( 4519279400378285887) },
      { -INT64_C( 3852448597841300116), -INT64_C(  579608354624263585), -INT64_C( 2826912879753706930), -INT64_C( 4519279400378285887) } },
    { {  INT64_C( 2969170516223688704), -INT64_C( 6202418441386688162) },
      {  INT64_C( 4934915509786423615),  INT64_C( 9055867478745232023) },
      {  INT64_C( 2969170516223688704),  INT64_C( 4934915509786423615), -INT64_C( 6202418441386688162),  INT64_C( 9055867478745232023) } },
    { { -INT64_C( 5085942374918078617),  INT64_C( 1193377832647932827) },
      { -INT64_C( 2363807849477967508),  INT64_C( 2323144622480281923) },
      { -INT64_C( 5085942374918078617), -INT64_C( 2363807849477967508),  INT64_C( 1193377832647932827),  INT64_C( 2323144622480281923) } },
    { { -INT64_C( 2788628400621608137),  INT64_C( 4677356364094183945) },
      { -INT64_C( 3285550134050456001), -INT64_C( 2230179382434844109) },
      { -INT64_C( 2788628400621608137), -INT64_C( 3285550134050456001),  INT64_C( 4677356364094183945), -INT64_C( 2230179382434844109) } },
    { {  INT64_C( 4974999003632726003),  INT64_C( 6336010623555455449) },
      { -INT64_C( 5554831153726284409),  INT64_C( 4468883969955232633) },
      {  INT64_C( 4974999003632726003), -INT64_C( 5554831153726284409),  INT64_C( 6336010623555455449),  INT64_C( 4468883969955232633) } },
    { {  INT64_C( 1196683404577306393),  INT64_C( 5382274084237130307) },
      {  INT64_C( 5835338931186471114),  INT64_C( 6723442427928222149) },
      {  INT64_C( 1196683404577306393),  INT64_C( 5835338931186471114),  INT64_C( 5382274084237130307),  INT64_C( 6723442427928222149) } },
    { {  INT64_C( 8734255621311020526),  INT64_C( 7788559535556588553) },
      { -INT64_C( 8845718650905856234),  INT64_C( 1579887328335605834) },
      {  INT64_C( 8734255621311020526), -INT64_C( 8845718650905856234),  INT64_C( 7788559535556588553),  INT64_C( 1579887328335605834) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int64x2x2_t r_ = { { simde_vld1q_s64(test_vec[i].r0),
                               simde_vld1q_s64(test_vec[i].r1) } };

    int64_t a_[8];
    simde_vst2q_s64(a_, r_);

    simde_assert_equal_i(0, simde_memcmp(a_, test_vec[i].a, sizeof(test_vec[i].a)));
  }

  return 0;
#else
  for (int i = 0 ; i < 8 ; i++) {
    simde_int64x2_t a = simde_test_arm_neon_random_i64x2();
    simde_int64x2_t b = simde_test_arm_neon_random_i64x2();
    simde_int64x2x2_t c = {{a, b}};

    simde_test_arm_neon_write_i64x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i64x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);

    int64_t buf[4];
    simde_vst2q_s64(buf, c);

    simde_test_codegen_write_vi64(2, sizeof(buf) / sizeof(buf[0]), buf,
                                  SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vst2q_u8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint8_t r0[16];
    uint8_t r1[16];
    uint8_t a[32];
  } test_vec[] = {
    { { UINT8_C( 92), UINT8_C(249), UINT8_C(153), UINT8_C( 75), UINT8_C(250), UINT8_C(190), UINT8_C(100), UINT8_C(208),
        UINT8_C( 15), UINT8_C( 64), UINT8_C(137), UINT8_C(101), UINT8_C(140), UINT8_C( 19), UINT8_C(  8), UINT8_C( 34) },
      { UINT8_C(  1), UINT8_C(208), UINT8_C(111), UINT8_C(206), UINT8_C(251), UINT8_C(234), UINT8_C( 24), UINT8_C(160),
        UINT8_C(187), UINT8_C(120), UINT8_C(102), UINT8_C(140), UINT8_C(119), UINT8_C( 96), UINT8_C(  0), UINT8_C(211) },
      { UINT8_C( 92), UINT8_C(  1), UINT8_C(249), UINT8_C(208), UINT8_C(153), UINT8_C(111), UINT8_C( 75), UINT8_C(206),
        UINT8_C(250), UINT8_C(251), UINT8_C(190), UINT8_C(234), UINT8_C(100), UINT8_C( 24), UINT8_C(208), UINT8_C(160),
        UINT8_C( 15), UINT8_C(187), UINT8_C( 64), UINT8_C(120), UINT8_C(137), UINT8_C(102), UINT8_C(101), UINT8_C(140),
        UINT8_C(140), UINT8_C(119), UINT8_C( 19), UINT8_C( 96), UINT8_C(  8), UINT8_C(  0), UINT8_C( 34), UINT8_C(211) } },
    { { UINT8_C( 89), UINT8_C(153), UINT8_C( 31), UINT8_C( 83), UINT8_C( 87), UINT8_C(131), UINT8_C( 36), UINT8_C(103),
        UINT8_C(195), UINT8_C(173), UINT8_C(204), UINT8_C( 80), UINT8_C(193), UINT8_C(212), UINT8_C(114), UINT8_C(194) },
      { UINT8_C(164), UINT8_C(226), UINT8_C(145), UINT8_C(159), UINT8_C(204), UINT8_C(169), UINT8_C( 63), UINT8_C(135),
        UINT8_C( 34), UINT8_C(166), UINT8_C( 19), UINT8_C(153), UINT8_C(  6), UINT8_C( 19), UINT8_C(109), UINT8_C( 96) },
      { UINT8_C( 89), UINT8_C(164), UINT8_C(153), UINT8_C(226), UINT8_C( 31), UINT8_C(145), UINT8_C( 83), UINT8_C(159),
        UINT8_C( 87), UINT8_C(204), UINT8_C(131), UINT8_C(169), UINT8_C( 36), UINT8_C( 63), UINT8_C(103), UINT8_C(135),
        UINT8_C(195), UINT8_C( 34), UINT8_C(173), UINT8_C(166), UINT8_C(204), UINT8_C( 19), UINT8_C( 80), UINT8_C(153),
        UINT8_C(193), UINT8_C(  6), UINT8_C(212), UINT8_C( 19), UINT8_C(114), UINT8_C(109), UINT8_C(194), UINT8_C( 96) } },
    { { UINT8_C(172), UINT8_C(140), UINT8_C(179), UINT8_C(  4), UINT8_C( 15), UINT8_C(215), UINT8_C(107), UINT8_C(211),
        UINT8_C(133), UINT8_C( 55), UINT8_C( 35), UINT8_C( 70), UINT8_C( 11), UINT8_C(149), UINT8_C(  8), UINT8_C(175) },
      { UINT8_C(119), UINT8_C(153), UINT8_C( 79), UINT8_C( 67), UINT8_C( 67), UINT8_C(142), UINT8_C(202), UINT8_C(101),
        UINT8_C( 52), UINT8_C(222), UINT8_C(254), UINT8_C( 59), UINT8_C(241), UINT8_C(107), UINT8_C(155), UINT8_C(158) },
      { UINT8_C(172), UINT8_C(119), UINT8_C(140), UINT8_C(153), UINT8_C(179), UINT8_C( 79), UINT8_C(  4), UINT8_C( 67),
        UINT8_C( 15), UINT8_C( 67), UINT8_C(215), UINT8_C(142), UINT8_C(107), UINT8_C(202), UINT8_C(211), UINT8_C(101),
        UINT8_C(133), UINT8_C( 52), UINT8_C( 55), UINT8_C(222), UINT8_C( 35), UINT8_C(254), UINT8_C( 70), UINT8_C( 59),
        UINT8_C( 11), UINT8_C(241), UINT8_C(149), UINT8_C(107), UINT8_C(  8), UINT8_C(155), UINT8_C(175), UINT8_C(158) } },
    { { UINT8_C(247), UINT8_C( 78), UINT8_C(162), UINT8_C(  7), UINT8_C( 38), UINT8_C( 13), UINT8_C(218), UINT8_C(171),
        UINT8_C( 68), UINT8_C(253), UINT8_C(241), UINT8_C( 79), UINT8_C(146), UINT8_C(249), UINT8_C(254), UINT8_C( 10) },
      { UINT8_C(147), UINT8_C( 77), UINT8_C( 77), UINT8_C(214), UINT8_C(220), UINT8_C( 24), UINT8_C( 59), UINT8_C( 16),
        UINT8_C(246), UINT8_C( 57), UINT8_C( 75), UINT8_C(231), UINT8_C(165), UINT8_C(230), UINT8_C(133), UINT8_C(156) },
      { UINT8_C(247), UINT8_C(147), UINT8_C( 78), UINT8_C( 77), UINT8_C(162), UINT8_C( 77), UINT8_C(  7), UINT8_C(214),
        UINT8_C( 38), UINT8_C(220), UINT8_C( 13), UINT8_C( 24), UINT8_C(218), UINT8_C( 59), UINT8_C(171), UINT8_C( 16),
        UINT8_C( 68), UINT8_C(246), UINT8_C(253), UINT8_C( 57), UINT8_C(241), UINT8_C( 75), UINT8_C( 79), UINT8_C(231),
        UINT8_C(146), UINT8_C(165), UINT8_C(249), UINT8_C(230), UINT8_C(254), UINT8_C(133), UINT8_C( 10), UINT8_C(156) } },
    { { UINT8_C( 53), UINT8_C( 39), UINT8_C(163), UINT8_C( 91), UINT8_C( 52), UINT8_C(125), UINT8_C(  6), UINT8_C(120),
        UINT8_C(122), UINT8_C(247), UINT8_C(199), UINT8_C( 13), UINT8_C(240), UINT8_C(198), UINT8_C( 23), UINT8_C(131) },
      { UINT8_C( 19), UINT8_C(100), UINT8_C( 89), UINT8_C(239), UINT8_C(124), UINT8_C(148), UINT8_C(  0), UINT8_C(114),
        UINT8_C(206), UINT8_C( 75), UINT8_C( 90), UINT8_C(115), UINT8_C( 50), UINT8_C(223), UINT8_C( 15), UINT8_C(103) },
      { UINT8_C( 53), UINT8_C( 19), UINT8_C( 39), UINT8_C(100), UINT8_C(163), UINT8_C( 89), UINT8_C( 91), UINT8_C(239),
        UINT8_C( 52), UINT8_C(124), UINT8_C(125), UINT8_C(148), UINT8_C(  6), UINT8_C(  0), UINT8_C(120), UINT8_C(114),
        UINT8_C(122), UINT8_C(206), UINT8_C(247), UINT8_C( 75), UINT8_C(199), UINT8_C( 90), UINT8_C( 13), UINT8_C(115),
        UINT8_C(240), UINT8_C( 50), UINT8_C(198), UINT8_C(223), UINT8_C( 23), UINT8_C( 15), UINT8_C(131), UINT8_C(103) } },
    { { UINT8_C(  7), UINT8_C(179), UINT8_C(194), UINT8_C( 59), UINT8_C( 48), UINT8_C(200), UINT8_C(180), UINT8_C(171),
        UINT8_C(191), UINT8_C(123), UINT8_C(184), UINT8_C(175), UINT8_C( 65), UINT8_C(207), UINT8_C( 51), UINT8_C( 85) },
      { UINT8_C( 51), UINT8_C(140), UINT8_C( 68), UINT8_C(176), UINT8_C( 33), UINT8_C( 68), UINT8_C( 34), UINT8_C(239),
        UINT8_C(144), UINT8_C(124), UINT8_C( 98), UINT8_C(194), UINT8_C( 92), UINT8_C(113), UINT8_C( 41), UINT8_C( 99) },
      { UINT8_C(  7), UINT8_C( 51), UINT8_C(179), UINT8_C(140), UINT8_C(194), UINT8_C( 68), UINT8_C( 59), UINT8_C(176),
        UINT8_C( 48), UINT8_C( 33), UINT8_C(200), UINT8_C( 68), UINT8_C(180), UINT8_C( 34), UINT8_C(171), UINT8_C(239),
        UINT8_C(191), UINT8_C(144), UINT8_C(123), UINT8_C(124), UINT8_C(184), UINT8_C( 98), UINT8_C(175), UINT8_C(194),
        UINT8_C( 65), UINT8_C( 92), UINT8_C(207), UINT8_C(113), UINT8_C( 51), UINT8_C( 41), UINT8_C( 85), UINT8_C( 99) } },
    { { UINT8_C( 36), UINT8_C(235), UINT8_C(158), UINT8_C( 85), UINT8_C(179), UINT8_C( 82), UINT8_C(  0), UINT8_C(114),
        UINT8_C(206), UINT8_C(184), UINT8_C( 33), UINT8_C( 15), UINT8_C(135), UINT8_C( 84), UINT8_C(100), UINT8_C(186) },
      { UINT8_C(225), UINT8_C(169), UINT8_C(106), UINT8_C(  2), UINT8_C(237), UINT8_C(141), UINT8_C(241), UINT8_C(125),
        UINT8_C(  9), UINT8_C( 83), UINT8_C( 63), UINT8_C(101), UINT8_C(196), UINT8_C(104), UINT8_C(200), UINT8_C(233) },
      { UINT8_C( 36), UINT8_C(225), UINT8_C(235), UINT8_C(169), UINT8_C(158), UINT8_C(106), UINT8_C( 85), UINT8_C(  2),
        UINT8_C(179), UINT8_C(237), UINT8_C( 82), UINT8_C(141), UINT8_C(  0), UINT8_C(241), UINT8_C(114), UINT8_C(125),
        UINT8_C(206), UINT8_C(  9), UINT8_C(184), UINT8_C( 83), UINT8_C( 33), UINT8_C( 63), UINT8_C( 15), UINT8_C(101),
        UINT8_C(135), UINT8_C(196), UINT8_C( 84), UINT8_C(104), UINT8_C(100), UINT8_C(200), UINT8_C(186), UINT8_C(233) } },
    { { UINT8_C( 83), UINT8_C(103), UINT8_C( 62), UINT8_C(  6), UINT8_C(185), UINT8_C( 62), UINT8_C(120), UINT8_C(135),
        UINT8_C(246), UINT8_C(154), UINT8_C(151), UINT8_C(125), UINT8_C(238), UINT8_C(251), UINT8_C( 55), UINT8_C(207) },
      { UINT8_C(164), UINT8_C(162), UINT8_C(209), UINT8_C(146), UINT8_C( 47), UINT8_C(194), UINT8_C( 15), UINT8_C( 56),
        UINT8_C( 21), UINT8_C( 79), UINT8_C(158), UINT8_C(218), UINT8_C(183), UINT8_C(102), UINT8_C(195), UINT8_C( 11) },
      { UINT8_C( 83), UINT8_C(164), UINT8_C(103), UINT8_C(162), UINT8_C( 62), UINT8_C(209), UINT8_C(  6), UINT8_C(146),
        UINT8_C(185), UINT8_C( 47), UINT8_C( 62), UINT8_C(194), UINT8_C(120), UINT8_C( 15), UINT8_C(135), UINT8_C( 56),
        UINT8_C(246), UINT8_C( 21), UINT8_C(154), UINT8_C( 79), UINT8_C(151), UINT8_C(158), UINT8_C(125), UINT8_C(218),
        UINT8_C(238), UINT8_C(183), UINT8_C(251), UINT8_C(102), UINT8_C( 55), UINT8_C(195), UINT8_C(207), UINT8_C( 11) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint8x16x2_t r_ = { { simde_vld1q_u8(test_vec[i].r0),
                                simde_vld1q_u8(test_vec[i].r1) } };

    uint8_t a_[32];
    simde_vst2q_u8(a_, r_);

    simde_assert_equal_i(0, simde_memcmp(a_, test_vec[i].a, sizeof(test_vec[i].a)));
  }

  return 0;
#else
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint8x16_t a = simde_test_arm_neon_random_u8x16();
    simde_uint8x16_t b = simde_test_arm_neon_random_u8x16();
    simde_uint8x16x2_t c = {{a, b}};

    simde_test_arm_neon_write_u8x16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u8x16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);

    uint8_t buf[32];
    simde_vst2q_u8(buf, c);

    simde_test_codegen_write_vu8(2, 32, buf, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vst2q_u16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint16_t r0[8];
    uint16_t r1[8];
    uint16_t a[16];
  } test_vec[] = {
    { { UINT16_C(14846), UINT16_C(33950), UINT16_C(30108), UINT16_C(26390), UINT16_C(33214), UINT16_C(35073), UINT16_C(46076), UINT16_C(64205) },
      { UINT16_C( 2100), UINT16_C(27059), UINT16_C(17140), UINT16_C(36502), UINT16_C(17361), UINT16_C(27325), UINT16_C(54528), UINT16_C(65053) },
      { UINT16_C(14846), UINT16_C( 2100), UINT16_C(33950), UINT16_C(27059), UINT16_C(30108), UINT16_C(17140), UINT16_C(26390), UINT16_C(36502),
        UINT16_C(33214), UINT16_C(17361), UINT16_C(35073), UINT16_C(27325), UINT16_C(46076), UINT16_C(54528), UINT16_C(64205), UINT16_C(65053) } },
    { { UINT16_C(47886), UINT16_C(43651), UINT16_C(39216), UINT16_C(60946), UINT16_C( 4890), UINT16_C( 6007), UINT16_C(17862), UINT16_C(64017) },
      { UINT16_C(50253), UINT16_C(16995), UINT16_C(63750), UINT16_C(55248), UINT16_C(36156), UINT16_C(15425), UINT16_C(24162), UINT16_C(28731) },
      { UINT16_C(47886), UINT16_C(50253), UINT16_C(43651), UINT16_C(16995), UINT16_C(39216), UINT16_C(63750), UINT16_C(60946), UINT16_C(55248),
        UINT16_C( 4890), UINT16_C(36156), UINT16_C( 6007), UINT16_C(15425), UINT16_C(17862), UINT16_C(24162), UINT16_C(64017), UINT16_C(28731) } },
    { { UINT16_C(48665), UINT16_C(18971), UINT16_C(11607), UINT16_C(28984), UINT16_C(45120), UINT16_C( 1672), UINT16_C(39413), UINT16_C(16896) },
      { UINT16_C(25438), UINT16_C(25732), UINT16_C(21596), UINT16_C(38972), UINT16_C(32225), UINT16_C(17365), UINT16_C( 4316), UINT16_C(62900) },
      { UINT16_C(48665), UINT16_C(25438), UINT16_C(18971), UINT16_C(25732), UINT16_C(11607), UINT16_C(21596), UINT16_C(28984), UINT16_C(38972),
        UINT16_C(45120), UINT16_C(32225), UINT16_C( 1672), UINT16_C(17365), UINT16_C(39413), UINT16_C( 4316), UINT16_C(16896), UINT16_C(62900) } },
    { { UINT16_C(53198), UINT16_C( 9535), UINT16_C(30972), UINT16_C(15510), UINT16_C( 7976), UINT16_C( 7490), UINT16_C(17080), UINT16_C( 5727) },
      { UINT16_C(58533), UINT16_C(  379), UINT16_C(46904), UINT16_C( 6809), UINT16_C(28212), UINT16_C( 4189), UINT16_C( 4478), UINT16_C(19462) },
      { UINT16_C(53198), UINT16_C(58533), UINT16_C( 9535), UINT16_C(  379), UINT16_C(30972), UINT16_C(46904), UINT16_C(15510), UINT16_C( 6809),
        UINT16_C( 7976), UINT16_C(28212), UINT16_C( 7490), UINT16_C( 4189), UINT16_C(17080), UINT16_C( 4478), UINT16_C( 5727), UINT16_C(19462) } },
    { { UINT16_C(17888), UINT16_C(56433), UINT16_C( 2237), UINT16_C(58648), UINT16_C(23079), UINT16_C(57090), UINT16_C(25244), UINT16_C(16886) },
      { UINT16_C(28998), UINT16_C(32322), UINT16_C(56360), UINT16_C(23704), UINT16_C(63050), UINT16_C(51565), UINT16_C(29447), UINT16_C(59413) },
      { UINT16_C(17888), UINT16_C(28998), UINT16_C(56433), UINT16_C(32322), UINT16_C( 2237), UINT16_C(56360), UINT16_C(58648), UINT16_C(23704),
        UINT16_C(23079), UINT16_C(63050), UINT16_C(57090), UINT16_C(51565), UINT16_C(25244), UINT16_C(29447), UINT16_C(16886), UINT16_C(59413) } },
    { { UINT16_C(34744), UINT16_C(30404), UINT16_C(56719), UINT16_C(46683), UINT16_C(24119), UINT16_C(54421), UINT16_C(35776), UINT16_C( 1557) },
      { UINT16_C(22780), UINT16_C( 9348), UINT16_C( 7476), UINT16_C(32385), UINT16_C(60947), UINT16_C( 6727), UINT16_C(23905), UINT16_C( 6402) },
      { UINT16_C(34744), UINT16_C(22780), UINT16_C(30404), UINT16_C( 9348), UINT16_C(56719), UINT16_C( 7476), UINT16_C(46683), UINT16_C(32385),
        UINT16_C(24119), UINT16_C(60947), UINT16_C(54421), UINT16_C( 6727), UINT16_C(35776), UINT16_C(23905), UINT16_C( 1557), UINT16_C( 6402) } },
    { { UINT16_C(51172), UINT16_C(29583), UINT16_C(60324), UINT16_C(56105), UINT16_C(48713), UINT16_C( 2479), UINT16_C(50506), UINT16_C(17935) },
      { UINT16_C(37661), UINT16_C(20843), UINT16_C(60592), UINT16_C(50127), UINT16_C( 6106), UINT16_C(15326), UINT16_C(57460), UINT16_C(22612) },
      { UINT16_C(51172), UINT16_C(37661), UINT16_C(29583), UINT16_C(20843), UINT16_C(60324), UINT16_C(60592), UINT16_C(56105), UINT16_C(50127),
        UINT16_C(48713), UINT16_C( 6106), UINT16_C( 2479), UINT16_C(15326), UINT16_C(50506), UINT16_C(57460), UINT16_C(17935), UINT16_C(22612) } },
    { { UINT16_C(58535), UINT16_C(19403), UINT16_C(62671), UINT16_C( 6183), UINT16_C(54962), UINT16_C(64545), UINT16_C(12443), UINT16_C(47171) },
      { UINT16_C(44739), UINT16_C(29705), UINT16_C(55706), UINT16_C(29751), UINT16_C( 5616), UINT16_C(25775), UINT16_C( 1014), UINT16_C(40380) },
      { UINT16_C(58535), UINT16_C(44739), UINT16_C(19403), UINT16_C(29705), UINT16_C(62671), UINT16_C(55706), UINT16_C( 6183), UINT16_C(29751),
        UINT16_C(54962), UINT16_C( 5616), UINT16_C(64545), UINT16_C(25775), UINT16_C(12443), UINT16_C( 1014), UINT16_C(47171), UINT16_C(40380) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint16x8x2_t r_ = { { simde_vld1q_u16(test_vec[i].r0),
                               simde_vld1q_u16(test_vec[i].r1) } };

    uint16_t a_[16];
    simde_vst2q_u16(a_, r_);

    simde_assert_equal_i(0, simde_memcmp(a_, test_vec[i].a, sizeof(test_vec[i].a)));
  }

  return 0;
#else
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint16x8_t a = simde_test_arm_neon_random_u16x8();
    simde_uint16x8_t b = simde_test_arm_neon_random_u16x8();
    simde_uint16x8x2_t c = {{a, b}};

    simde_test_arm_neon_write_u16x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u16x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);

    uint16_t buf[16];
    simde_vst2q_u16(buf, c);

    simde_test_codegen_write_vu16(2, sizeof(buf) / sizeof(buf[0]), buf,
                                  SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vst2q_u32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint32_t r0[4];
    uint32_t r1[4];
    uint32_t a[8];
  } test_vec[] = {
    { { UINT32_C(1804152991), UINT32_C(4182149210), UINT32_C( 339721032), UINT32_C(2730124195) },
      { UINT32_C(3048437295), UINT32_C(4089297023), UINT32_C( 764726619), UINT32_C( 882693269) },
      { UINT32_C(1804152991), UINT32_C(3048437295), UINT32_C(4182149210), UINT32_C(4089297023), UINT32_C( 339721032), UINT32_C( 764726619), UINT32_C(2730124195), UINT32_C( 882693269) } },
    { { UINT32_C(1604265220), UINT32_C(4133021101), UINT32_C(1124767904), UINT32_C( 719701243) },
      { UINT32_C(3135215675), UINT32_C(2897124433), UINT32_C(4275651177), UINT32_C( 456291606) },
      { UINT32_C(1604265220), UINT32_C(3135215675), UINT32_C(4133021101), UINT32_C(2897124433), UINT32_C(1124767904), UINT32_C(4275651177), UINT32_C( 719701243), UINT32_C( 456291606) } },
    { { UINT32_C(1216008858), UINT32_C(1480512183), UINT32_C(1704675434), UINT32_C(1217364237) },
      { UINT32_C(1778544153), UINT32_C(1930866698), UINT32_C( 158461938), UINT32_C(4280591460) },
      { UINT32_C(1216008858), UINT32_C(1778544153), UINT32_C(1480512183), UINT32_C(1930866698), UINT32_C(1704675434), UINT32_C( 158461938), UINT32_C(1217364237), UINT32_C(4280591460) } },
    { { UINT32_C( 759668342), UINT32_C(3682960752), UINT32_C(3661636045), UINT32_C(3139621026) },
      { UINT32_C(1227236670), UINT32_C(3367779541), UINT32_C(2429627948), UINT32_C(1217394130) },
      { UINT32_C( 759668342), UINT32_C(1227236670), UINT32_C(3682960752), UINT32_C(3367779541), UINT32_C(3661636045), UINT32_C(2429627948), UINT32_C(3139621026), UINT32_C(1217394130) } },
    { { UINT32_C(  58054291), UINT32_C( 702479195), UINT32_C(3187875612), UINT32_C( 762914543) },
      { UINT32_C( 544644939), UINT32_C( 149435356), UINT32_C( 865646945), UINT32_C(1098590382) },
      { UINT32_C(  58054291), UINT32_C( 544644939), UINT32_C( 702479195), UINT32_C( 149435356), UINT32_C(3187875612), UINT32_C( 865646945), UINT32_C( 762914543), UINT32_C(1098590382) } },
    { { UINT32_C(1514533118), UINT32_C( 126034923), UINT32_C( 835028546), UINT32_C(4150214572) },
      { UINT32_C(3122189790), UINT32_C(1774321672), UINT32_C(1755077562), UINT32_C(2175408003) },
      { UINT32_C(1514533118), UINT32_C(3122189790), UINT32_C( 126034923), UINT32_C(1774321672), UINT32_C( 835028546), UINT32_C(1755077562), UINT32_C(4150214572), UINT32_C(2175408003) } },
    { { UINT32_C(4091277064), UINT32_C(1442536978), UINT32_C(2441527525), UINT32_C(3733579263) },
      { UINT32_C(3281559995), UINT32_C(1529699233), UINT32_C( 969198006), UINT32_C(3921309409) },
      { UINT32_C(4091277064), UINT32_C(3281559995), UINT32_C(1442536978), UINT32_C(1529699233), UINT32_C(2441527525), UINT32_C( 969198006), UINT32_C(3733579263), UINT32_C(3921309409) } },
    { { UINT32_C(1876727389), UINT32_C(3653556212), UINT32_C(2540391320), UINT32_C(3950375984) },
      { UINT32_C( 917442197), UINT32_C( 529718377), UINT32_C(2253936293), UINT32_C( 560927428) },
      { UINT32_C(1876727389), UINT32_C( 917442197), UINT32_C(3653556212), UINT32_C( 529718377), UINT32_C(2540391320), UINT32_C(2253936293), UINT32_C(3950375984), UINT32_C( 560927428) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint32x4x2_t r_ = { { simde_vld1q_u32(test_vec[i].r0),
                                simde_vld1q_u32(test_vec[i].r1) } };

    uint32_t a_[8];
    simde_vst2q_u32(a_, r_);

    simde_assert_equal_i(0, simde_memcmp(a_, test_vec[i].a, sizeof(test_vec[i].a)));
  }

  return 0;
#else
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint32x4_t a = simde_test_arm_neon_random_u32x4();
    simde_uint32x4_t b = simde_test_arm_neon_random_u32x4();
    simde_uint32x4x2_t c = {{a, b}};

    simde_test_arm_neon_write_u32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);

    uint32_t buf[8];
    simde_vst2q_u32(buf, c);

    simde_test_codegen_write_vu32(2, sizeof(buf) / sizeof(buf[0]), buf,
                                  SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vst2q_u64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint64_t r0[2];
    uint64_t r1[2];
    uint64_t a[4];
  } test_vec[] = {
    { { UINT64_C( 4631073650736452430), UINT64_C(   97977723505869293) },
      { UINT64_C( 9494239399973030355), UINT64_C(17079592208315254370) },
      { UINT64_C( 4631073650736452430), UINT64_C( 9494239399973030355), UINT64_C(   97977723505869293), UINT64_C(17079592208315254370) } },
    { { UINT64_C(11920212063241492282), UINT64_C(14939688989115999515) },
      { UINT64_C(17251338049259715960), UINT64_C(12944237555739824663) },
      { UINT64_C(11920212063241492282), UINT64_C(17251338049259715960), UINT64_C(14939688989115999515), UINT64_C(12944237555739824663) } },
    { { UINT64_C(12420730486100293634), UINT64_C( 6412093291273154866) },
      { UINT64_C( 8218971854782483346), UINT64_C( 7018520676896617274) },
      { UINT64_C(12420730486100293634), UINT64_C( 8218971854782483346), UINT64_C( 6412093291273154866), UINT64_C( 7018520676896617274) } },
    { { UINT64_C(14159733474488698179), UINT64_C( 7504385485434880491) },
      { UINT64_C( 4902051691601814329), UINT64_C( 4506236235466354634) },
      { UINT64_C(14159733474488698179), UINT64_C( 4902051691601814329), UINT64_C( 7504385485434880491), UINT64_C( 4506236235466354634) } },
    { { UINT64_C(  790827166552269987), UINT64_C( 1248898806281857558) },
      { UINT64_C( 4372060045163551837), UINT64_C(11823899563383956700) },
      { UINT64_C(  790827166552269987), UINT64_C( 4372060045163551837), UINT64_C( 1248898806281857558), UINT64_C(11823899563383956700) } },
    { { UINT64_C(15401135067192961427), UINT64_C(16836450525011612093) },
      { UINT64_C(15465922946745322994), UINT64_C( 9748257948440594082) },
      { UINT64_C(15401135067192961427), UINT64_C(15465922946745322994), UINT64_C(16836450525011612093), UINT64_C( 9748257948440594082) } },
    { { UINT64_C(12790773748407542253), UINT64_C( 5403173140480541318) },
      { UINT64_C(17080834295669411130), UINT64_C( 7697452745763109206) },
      { UINT64_C(12790773748407542253), UINT64_C(17080834295669411130), UINT64_C( 5403173140480541318), UINT64_C( 7697452745763109206) } },
    { { UINT64_C( 9628581653808286714), UINT64_C(  972095629878093274) },
      { UINT64_C(15138935343102962912), UINT64_C( 8930055876163446790) },
      { UINT64_C( 9628581653808286714), UINT64_C(15138935343102962912), UINT64_C(  972095629878093274), UINT64_C( 8930055876163446790) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint64x2x2_t r_ = { { simde_vld1q_u64(test_vec[i].r0),
                               simde_vld1q_u64(test_vec[i].r1) } };

    uint64_t a_[8];
    simde_vst2q_u64(a_, r_);

    simde_assert_equal_i(0, simde_memcmp(a_, test_vec[i].a, sizeof(test_vec[i].a)));
  }

  return 0;
#else
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint64x2_t a = simde_test_arm_neon_random_u64x2();
    simde_uint64x2_t b = simde_test_arm_neon_random_u64x2();
    simde_uint64x2x2_t c = {{a, b}};

    simde_test_arm_neon_write_u64x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u64x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);

    uint64_t buf[4];
    simde_vst2q_u64(buf, c);

    simde_test_codegen_write_vu64(2, sizeof(buf) / sizeof(buf[0]), buf,
                                  SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

#endif /* !defined(SIMDE_BUG_INTEL_857088) */

SIMDE_TEST_FUNC_LIST_BEGIN
#if !defined(SIMDE_BUG_INTEL_857088)
SIMDE_TEST_FUNC_LIST_ENTRY(vst2_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vst2_f64)
SIMDE_TEST_FUNC_LIST_ENTRY(vst2_s8)
SIMDE_TEST_FUNC_LIST_ENTRY(vst2_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vst2_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vst2_s64)
SIMDE_TEST_FUNC_LIST_ENTRY(vst2_u8)
SIMDE_TEST_FUNC_LIST_ENTRY(vst2_u16)
SIMDE_TEST_FUNC_LIST_ENTRY(vst2_u32)
SIMDE_TEST_FUNC_LIST_ENTRY(vst2_u64)

SIMDE_TEST_FUNC_LIST_ENTRY(vst2q_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vst2q_f64)
SIMDE_TEST_FUNC_LIST_ENTRY(vst2q_s8)
SIMDE_TEST_FUNC_LIST_ENTRY(vst2q_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vst2q_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vst2q_s64)
SIMDE_TEST_FUNC_LIST_ENTRY(vst2q_u8)
SIMDE_TEST_FUNC_LIST_ENTRY(vst2q_u16)
SIMDE_TEST_FUNC_LIST_ENTRY(vst2q_u32)
SIMDE_TEST_FUNC_LIST_ENTRY(vst2q_u64)
#endif /* !defined(SIMDE_BUG_INTEL_857088) */
SIMDE_TEST_FUNC_LIST_END

#include "test-neon-footer.h"
