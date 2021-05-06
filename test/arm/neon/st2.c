
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
    { { SIMDE_FLOAT32_C(   404.07), SIMDE_FLOAT32_C(   254.87) },
      { SIMDE_FLOAT32_C(   742.29), SIMDE_FLOAT32_C(  -968.01) },
      { SIMDE_FLOAT32_C(   404.07), SIMDE_FLOAT32_C(   742.29), SIMDE_FLOAT32_C(   254.87), SIMDE_FLOAT32_C(  -968.01) } },
    { { SIMDE_FLOAT32_C(   438.19), SIMDE_FLOAT32_C(   761.80) },
      { SIMDE_FLOAT32_C(  -480.90), SIMDE_FLOAT32_C(  -971.16) },
      { SIMDE_FLOAT32_C(   438.19), SIMDE_FLOAT32_C(  -480.90), SIMDE_FLOAT32_C(   761.80), SIMDE_FLOAT32_C(  -971.16) } },
    { { SIMDE_FLOAT32_C(    39.70), SIMDE_FLOAT32_C(   811.40) },
      { SIMDE_FLOAT32_C(   187.69), SIMDE_FLOAT32_C(  -226.72) },
      { SIMDE_FLOAT32_C(    39.70), SIMDE_FLOAT32_C(   187.69), SIMDE_FLOAT32_C(   811.40), SIMDE_FLOAT32_C(  -226.72) } },
    { { SIMDE_FLOAT32_C(  -923.76), SIMDE_FLOAT32_C(   745.66) },
      { SIMDE_FLOAT32_C(  -918.27), SIMDE_FLOAT32_C(  -929.94) },
      { SIMDE_FLOAT32_C(  -923.76), SIMDE_FLOAT32_C(  -918.27), SIMDE_FLOAT32_C(   745.66), SIMDE_FLOAT32_C(  -929.94) } },
    { { SIMDE_FLOAT32_C(  -473.93), SIMDE_FLOAT32_C(   501.79) },
      { SIMDE_FLOAT32_C(   -55.28), SIMDE_FLOAT32_C(  -594.27) },
      { SIMDE_FLOAT32_C(  -473.93), SIMDE_FLOAT32_C(   -55.28), SIMDE_FLOAT32_C(   501.79), SIMDE_FLOAT32_C(  -594.27) } },
    { { SIMDE_FLOAT32_C(   580.49), SIMDE_FLOAT32_C(  -364.17) },
      { SIMDE_FLOAT32_C(   138.53), SIMDE_FLOAT32_C(   966.17) },
      { SIMDE_FLOAT32_C(   580.49), SIMDE_FLOAT32_C(   138.53), SIMDE_FLOAT32_C(  -364.17), SIMDE_FLOAT32_C(   966.17) } },
    { { SIMDE_FLOAT32_C(   372.45), SIMDE_FLOAT32_C(   850.59) },
      { SIMDE_FLOAT32_C(  -522.32), SIMDE_FLOAT32_C(   386.97) },
      { SIMDE_FLOAT32_C(   372.45), SIMDE_FLOAT32_C(  -522.32), SIMDE_FLOAT32_C(   850.59), SIMDE_FLOAT32_C(   386.97) } },
    { { SIMDE_FLOAT32_C(   320.85), SIMDE_FLOAT32_C(  -875.27) },
      { SIMDE_FLOAT32_C(  -753.89), SIMDE_FLOAT32_C(  -275.08) },
      { SIMDE_FLOAT32_C(   320.85), SIMDE_FLOAT32_C(  -753.89), SIMDE_FLOAT32_C(  -875.27), SIMDE_FLOAT32_C(  -275.08) } },
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
test_simde_vst2_s8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int8_t r0[8];
    int8_t r1[8];
    int8_t a[16];
  } test_vec[] = {
    { { -INT8_C(  75),  INT8_C( 115), -INT8_C(  23),  INT8_C(  93),  INT8_C(  53), -INT8_C( 109), -INT8_C(  88), -INT8_C(  42) },
      {  INT8_C(  14),  INT8_C(   7),  INT8_C(  83),  INT8_C(  35), -INT8_C( 119), -INT8_C(  91),  INT8_C(  97),  INT8_C(  77) },
      { -INT8_C(  75),  INT8_C(  14),  INT8_C( 115),  INT8_C(   7), -INT8_C(  23),  INT8_C(  83),  INT8_C(  93),  INT8_C(  35),
         INT8_C(  53), -INT8_C( 119), -INT8_C( 109), -INT8_C(  91), -INT8_C(  88),  INT8_C(  97), -INT8_C(  42),  INT8_C(  77) } },
    { { -INT8_C(   2), -INT8_C( 119),  INT8_C(  15), -INT8_C( 125),  INT8_C(  79), -INT8_C(  99), -INT8_C(   5),  INT8_C(  95) },
      { -INT8_C(  79), -INT8_C(  55), -INT8_C(  65),  INT8_C(  53),  INT8_C(  40), -INT8_C(  48), -INT8_C( 116), -INT8_C(  34) },
      { -INT8_C(   2), -INT8_C(  79), -INT8_C( 119), -INT8_C(  55),  INT8_C(  15), -INT8_C(  65), -INT8_C( 125),  INT8_C(  53),
         INT8_C(  79),  INT8_C(  40), -INT8_C(  99), -INT8_C(  48), -INT8_C(   5), -INT8_C( 116),  INT8_C(  95), -INT8_C(  34) } },
    { {  INT8_C(  68),  INT8_C( 117),  INT8_C(  59),  INT8_C( 121),  INT8_C(   9), -INT8_C(  29),  INT8_C(  79),  INT8_C(  23) },
      { -INT8_C(  22), -INT8_C(  94),  INT8_C(  58),  INT8_C( 116),  INT8_C(  72), -INT8_C( 101), -INT8_C(  63),  INT8_C(  70) },
      {  INT8_C(  68), -INT8_C(  22),  INT8_C( 117), -INT8_C(  94),  INT8_C(  59),  INT8_C(  58),  INT8_C( 121),  INT8_C( 116),
         INT8_C(   9),  INT8_C(  72), -INT8_C(  29), -INT8_C( 101),  INT8_C(  79), -INT8_C(  63),  INT8_C(  23),  INT8_C(  70) } },
    { {  INT8_C(  37), -INT8_C(  47), -INT8_C(  54),  INT8_C( 116),  INT8_C( 110), -INT8_C(  59), -INT8_C(  45),  INT8_C(  31) },
      { -INT8_C( 113), -INT8_C( 109),  INT8_C(  84), -INT8_C(  73),  INT8_C(  99), -INT8_C(  32), -INT8_C( 107), -INT8_C(  89) },
      {  INT8_C(  37), -INT8_C( 113), -INT8_C(  47), -INT8_C( 109), -INT8_C(  54),  INT8_C(  84),  INT8_C( 116), -INT8_C(  73),
         INT8_C( 110),  INT8_C(  99), -INT8_C(  59), -INT8_C(  32), -INT8_C(  45), -INT8_C( 107),  INT8_C(  31), -INT8_C(  89) } },
    { {  INT8_C(  86), -INT8_C(  48),  INT8_C(  32),  INT8_C(  95), -INT8_C(  76),  INT8_C( 112),  INT8_C( 118), -INT8_C(  98) },
      {  INT8_C(  18), -INT8_C(  80),  INT8_C(  18),  INT8_C(  90),  INT8_C(  75), -INT8_C(  44), -INT8_C(  95),  INT8_C( 112) },
      {  INT8_C(  86),  INT8_C(  18), -INT8_C(  48), -INT8_C(  80),  INT8_C(  32),  INT8_C(  18),  INT8_C(  95),  INT8_C(  90),
        -INT8_C(  76),  INT8_C(  75),  INT8_C( 112), -INT8_C(  44),  INT8_C( 118), -INT8_C(  95), -INT8_C(  98),  INT8_C( 112) } },
    { { -INT8_C(  91),  INT8_C( 107), -INT8_C(  28),  INT8_C(  19),  INT8_C(  48), -INT8_C(  72),  INT8_C(  50), -INT8_C(  65) },
      {  INT8_C(  75), -INT8_C( 121),  INT8_C( 119), -INT8_C(  82),  INT8_C( 103),  INT8_C(  12),  INT8_C(  86), -INT8_C(  67) },
      { -INT8_C(  91),  INT8_C(  75),  INT8_C( 107), -INT8_C( 121), -INT8_C(  28),  INT8_C( 119),  INT8_C(  19), -INT8_C(  82),
         INT8_C(  48),  INT8_C( 103), -INT8_C(  72),  INT8_C(  12),  INT8_C(  50),  INT8_C(  86), -INT8_C(  65), -INT8_C(  67) } },
    { { -INT8_C(  35),  INT8_C( 118),  INT8_C(  28), -INT8_C( 111), -INT8_C(  26), -INT8_C( 110),  INT8_C(  47), -INT8_C(   7) },
      {  INT8_C(  66),  INT8_C(  66),  INT8_C(  83), -INT8_C( 114),  INT8_C(  22), -INT8_C(  12), -INT8_C(   2), -INT8_C(  69) },
      { -INT8_C(  35),  INT8_C(  66),  INT8_C( 118),  INT8_C(  66),  INT8_C(  28),  INT8_C(  83), -INT8_C( 111), -INT8_C( 114),
        -INT8_C(  26),  INT8_C(  22), -INT8_C( 110), -INT8_C(  12),  INT8_C(  47), -INT8_C(   2), -INT8_C(   7), -INT8_C(  69) } },
    { {  INT8_C(  95), -INT8_C(  29), -INT8_C(  50), -INT8_C( 112), -INT8_C( 101),  INT8_C(   0),  INT8_C(  79), -INT8_C(  26) },
      { -INT8_C( 121), -INT8_C(  58), -INT8_C( 108), -INT8_C(  17), -INT8_C(  45), -INT8_C(  22), -INT8_C(  84), -INT8_C(  80) },
      {  INT8_C(  95), -INT8_C( 121), -INT8_C(  29), -INT8_C(  58), -INT8_C(  50), -INT8_C( 108), -INT8_C( 112), -INT8_C(  17),
        -INT8_C( 101), -INT8_C(  45),  INT8_C(   0), -INT8_C(  22),  INT8_C(  79), -INT8_C(  84), -INT8_C(  26), -INT8_C(  80) } },
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
    { { -INT16_C( 23784), -INT16_C(  7325),  INT16_C( 10993),  INT16_C( 26166) },
      { -INT16_C( 32546),  INT16_C( 25304), -INT16_C( 13889), -INT16_C( 14660) },
      { -INT16_C( 23784), -INT16_C( 32546), -INT16_C(  7325),  INT16_C( 25304),  INT16_C( 10993), -INT16_C( 13889),  INT16_C( 26166), -INT16_C( 14660) } },
    { { -INT16_C( 32563), -INT16_C( 17198), -INT16_C( 20910), -INT16_C( 11255) },
      { -INT16_C( 24180), -INT16_C( 14355), -INT16_C(  5284),  INT16_C( 29911) },
      { -INT16_C( 32563), -INT16_C( 24180), -INT16_C( 17198), -INT16_C( 14355), -INT16_C( 20910), -INT16_C(  5284), -INT16_C( 11255),  INT16_C( 29911) } },
    { {  INT16_C( 14990),  INT16_C( 32599), -INT16_C( 29340),  INT16_C( 17126) },
      { -INT16_C( 16882), -INT16_C( 12892),  INT16_C( 24967),  INT16_C( 21907) },
      {  INT16_C( 14990), -INT16_C( 16882),  INT16_C( 32599), -INT16_C( 12892), -INT16_C( 29340),  INT16_C( 24967),  INT16_C( 17126),  INT16_C( 21907) } },
    { {  INT16_C( 26337),  INT16_C( 13073),  INT16_C(  6676), -INT16_C( 24568) },
      { -INT16_C(  2628),  INT16_C(  6247),  INT16_C( 16096),  INT16_C( 28301) },
      {  INT16_C( 26337), -INT16_C(  2628),  INT16_C( 13073),  INT16_C(  6247),  INT16_C(  6676),  INT16_C( 16096), -INT16_C( 24568),  INT16_C( 28301) } },
    { { -INT16_C(  7048), -INT16_C(  8978), -INT16_C( 11150), -INT16_C( 32738) },
      { -INT16_C( 15470),  INT16_C(  6733), -INT16_C(  8156),  INT16_C(  1391) },
      { -INT16_C(  7048), -INT16_C( 15470), -INT16_C(  8978),  INT16_C(  6733), -INT16_C( 11150), -INT16_C(  8156), -INT16_C( 32738),  INT16_C(  1391) } },
    { { -INT16_C( 32698),  INT16_C( 23096),  INT16_C( 16538),  INT16_C( 22266) },
      {  INT16_C( 25142),  INT16_C(  5743), -INT16_C(   864),  INT16_C(  6533) },
      { -INT16_C( 32698),  INT16_C( 25142),  INT16_C( 23096),  INT16_C(  5743),  INT16_C( 16538), -INT16_C(   864),  INT16_C( 22266),  INT16_C(  6533) } },
    { {  INT16_C( 29664),  INT16_C( 21237),  INT16_C(  5191), -INT16_C(  9774) },
      {  INT16_C(  8151), -INT16_C(  1037),  INT16_C( 25088),  INT16_C( 17920) },
      {  INT16_C( 29664),  INT16_C(  8151),  INT16_C( 21237), -INT16_C(  1037),  INT16_C(  5191),  INT16_C( 25088), -INT16_C(  9774),  INT16_C( 17920) } },
    { {  INT16_C( 14562),  INT16_C( 32161), -INT16_C( 25735), -INT16_C( 20525) },
      {  INT16_C( 17149), -INT16_C( 24891),  INT16_C( 19006),  INT16_C(  8119) },
      {  INT16_C( 14562),  INT16_C( 17149),  INT16_C( 32161), -INT16_C( 24891), -INT16_C( 25735),  INT16_C( 19006), -INT16_C( 20525),  INT16_C(  8119) } },
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
    { {  INT32_C(  1542839313), -INT32_C(  1938060411) },
      { -INT32_C(   693853004), -INT32_C(  1813779275) },
      {  INT32_C(  1542839313), -INT32_C(   693853004), -INT32_C(  1938060411), -INT32_C(  1813779275) } },
    { { -INT32_C(   928208941),  INT32_C(  1357925824) },
      { -INT32_C(   807804729),  INT32_C(   956564520) },
      { -INT32_C(   928208941), -INT32_C(   807804729),  INT32_C(  1357925824),  INT32_C(   956564520) } },
    { {  INT32_C(  1704262112),  INT32_C(   972165252) },
      {  INT32_C(  1762629300),  INT32_C(  1442706050) },
      {  INT32_C(  1704262112),  INT32_C(  1762629300),  INT32_C(   972165252),  INT32_C(  1442706050) } },
    { {  INT32_C(  1511958937), -INT32_C(  1112928522) },
      {  INT32_C(   395150319),  INT32_C(  1733333383) },
      {  INT32_C(  1511958937),  INT32_C(   395150319), -INT32_C(  1112928522),  INT32_C(  1733333383) } },
    { {  INT32_C(   265151883), -INT32_C(  1454850059) },
      { -INT32_C(   686663851), -INT32_C(   483586230) },
      {  INT32_C(   265151883), -INT32_C(   686663851), -INT32_C(  1454850059), -INT32_C(   483586230) } },
    { { -INT32_C(  1354937415),  INT32_C(  1215162457) },
      { -INT32_C(   211813781),  INT32_C(   375042187) },
      { -INT32_C(  1354937415), -INT32_C(   211813781),  INT32_C(  1215162457),  INT32_C(   375042187) } },
    { { -INT32_C(  1977210987),  INT32_C(   993226470) },
      {  INT32_C(   269698502),  INT32_C(   250822741) },
      { -INT32_C(  1977210987),  INT32_C(   269698502),  INT32_C(   993226470),  INT32_C(   250822741) } },
    { { -INT32_C(   457363061), -INT32_C(  2077414887) },
      { -INT32_C(  1334342620), -INT32_C(   775499204) },
      { -INT32_C(   457363061), -INT32_C(  1334342620), -INT32_C(  2077414887), -INT32_C(   775499204) } },
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
test_simde_vst2_u8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint8_t r0[8];
    uint8_t r1[8];
    uint8_t a[16];
  } test_vec[] = {
    { { UINT8_C(128), UINT8_C( 46), UINT8_C( 28), UINT8_C( 68), UINT8_C( 61), UINT8_C( 35), UINT8_C(134), UINT8_C( 27) },
      { UINT8_C(134), UINT8_C(163), UINT8_C( 89), UINT8_C( 60), UINT8_C(201), UINT8_C(108), UINT8_C(202), UINT8_C(142) },
      { UINT8_C(128), UINT8_C(134), UINT8_C( 46), UINT8_C(163), UINT8_C( 28), UINT8_C( 89), UINT8_C( 68), UINT8_C( 60),
        UINT8_C( 61), UINT8_C(201), UINT8_C( 35), UINT8_C(108), UINT8_C(134), UINT8_C(202), UINT8_C( 27), UINT8_C(142) } },
    { { UINT8_C(203), UINT8_C(243), UINT8_C(166), UINT8_C(159), UINT8_C( 31), UINT8_C( 84), UINT8_C(184), UINT8_C( 18) },
      { UINT8_C( 56), UINT8_C( 87), UINT8_C(124), UINT8_C(205), UINT8_C(232), UINT8_C(113), UINT8_C(122), UINT8_C(104) },
      { UINT8_C(203), UINT8_C( 56), UINT8_C(243), UINT8_C( 87), UINT8_C(166), UINT8_C(124), UINT8_C(159), UINT8_C(205),
        UINT8_C( 31), UINT8_C(232), UINT8_C( 84), UINT8_C(113), UINT8_C(184), UINT8_C(122), UINT8_C( 18), UINT8_C(104) } },
    { { UINT8_C(159), UINT8_C(150), UINT8_C(172), UINT8_C(220), UINT8_C(185), UINT8_C( 50), UINT8_C(247), UINT8_C( 64) },
      { UINT8_C(214), UINT8_C( 80), UINT8_C(124), UINT8_C(159), UINT8_C(188), UINT8_C( 70), UINT8_C( 45), UINT8_C(135) },
      { UINT8_C(159), UINT8_C(214), UINT8_C(150), UINT8_C( 80), UINT8_C(172), UINT8_C(124), UINT8_C(220), UINT8_C(159),
        UINT8_C(185), UINT8_C(188), UINT8_C( 50), UINT8_C( 70), UINT8_C(247), UINT8_C( 45), UINT8_C( 64), UINT8_C(135) } },
    { { UINT8_C( 58), UINT8_C(211), UINT8_C( 38), UINT8_C( 89), UINT8_C( 40), UINT8_C(222), UINT8_C(107), UINT8_C( 96) },
      { UINT8_C( 53), UINT8_C(231), UINT8_C( 45), UINT8_C( 29), UINT8_C( 88), UINT8_C(167), UINT8_C(134), UINT8_C(247) },
      { UINT8_C( 58), UINT8_C( 53), UINT8_C(211), UINT8_C(231), UINT8_C( 38), UINT8_C( 45), UINT8_C( 89), UINT8_C( 29),
        UINT8_C( 40), UINT8_C( 88), UINT8_C(222), UINT8_C(167), UINT8_C(107), UINT8_C(134), UINT8_C( 96), UINT8_C(247) } },
    { { UINT8_C( 61), UINT8_C( 50), UINT8_C(211), UINT8_C(247), UINT8_C(101), UINT8_C(202), UINT8_C( 55), UINT8_C( 59) },
      { UINT8_C( 26), UINT8_C(179), UINT8_C(218), UINT8_C(214), UINT8_C(249), UINT8_C(  7), UINT8_C( 94), UINT8_C( 51) },
      { UINT8_C( 61), UINT8_C( 26), UINT8_C( 50), UINT8_C(179), UINT8_C(211), UINT8_C(218), UINT8_C(247), UINT8_C(214),
        UINT8_C(101), UINT8_C(249), UINT8_C(202), UINT8_C(  7), UINT8_C( 55), UINT8_C( 94), UINT8_C( 59), UINT8_C( 51) } },
    { { UINT8_C(218), UINT8_C(132), UINT8_C(141), UINT8_C(  2), UINT8_C( 99), UINT8_C(248), UINT8_C( 98), UINT8_C(152) },
      { UINT8_C(224), UINT8_C(143), UINT8_C(182), UINT8_C( 56), UINT8_C( 54), UINT8_C( 60), UINT8_C( 48), UINT8_C(116) },
      { UINT8_C(218), UINT8_C(224), UINT8_C(132), UINT8_C(143), UINT8_C(141), UINT8_C(182), UINT8_C(  2), UINT8_C( 56),
        UINT8_C( 99), UINT8_C( 54), UINT8_C(248), UINT8_C( 60), UINT8_C( 98), UINT8_C( 48), UINT8_C(152), UINT8_C(116) } },
    { { UINT8_C(110), UINT8_C(  3), UINT8_C(107), UINT8_C(211), UINT8_C(206), UINT8_C(162), UINT8_C( 14), UINT8_C(232) },
      { UINT8_C( 85), UINT8_C(232), UINT8_C(191), UINT8_C( 78), UINT8_C(239), UINT8_C( 29), UINT8_C(130), UINT8_C(202) },
      { UINT8_C(110), UINT8_C( 85), UINT8_C(  3), UINT8_C(232), UINT8_C(107), UINT8_C(191), UINT8_C(211), UINT8_C( 78),
        UINT8_C(206), UINT8_C(239), UINT8_C(162), UINT8_C( 29), UINT8_C( 14), UINT8_C(130), UINT8_C(232), UINT8_C(202) } },
    { { UINT8_C(161), UINT8_C( 15), UINT8_C(204), UINT8_C(  4), UINT8_C(  7), UINT8_C( 47), UINT8_C(157), UINT8_C(231) },
      { UINT8_C(190), UINT8_C( 83), UINT8_C( 32), UINT8_C(245), UINT8_C(143), UINT8_C( 80), UINT8_C(105), UINT8_C(253) },
      { UINT8_C(161), UINT8_C(190), UINT8_C( 15), UINT8_C( 83), UINT8_C(204), UINT8_C( 32), UINT8_C(  4), UINT8_C(245),
        UINT8_C(  7), UINT8_C(143), UINT8_C( 47), UINT8_C( 80), UINT8_C(157), UINT8_C(105), UINT8_C(231), UINT8_C(253) } },
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
    { { UINT16_C(64129), UINT16_C(13358), UINT16_C(40825), UINT16_C( 1959) },
      { UINT16_C(25405), UINT16_C(23760), UINT16_C( 6166), UINT16_C(56825) },
      { UINT16_C(64129), UINT16_C(25405), UINT16_C(13358), UINT16_C(23760), UINT16_C(40825), UINT16_C( 6166), UINT16_C( 1959), UINT16_C(56825) } },
    { { UINT16_C( 5470), UINT16_C(10643), UINT16_C(39274), UINT16_C(24474) },
      { UINT16_C(25420), UINT16_C(11141), UINT16_C(10577), UINT16_C(53973) },
      { UINT16_C( 5470), UINT16_C(25420), UINT16_C(10643), UINT16_C(11141), UINT16_C(39274), UINT16_C(10577), UINT16_C(24474), UINT16_C(53973) } },
    { { UINT16_C(  803), UINT16_C(39942), UINT16_C(44450), UINT16_C(57508) },
      { UINT16_C(29713), UINT16_C(10044), UINT16_C(13709), UINT16_C(60164) },
      { UINT16_C(  803), UINT16_C(29713), UINT16_C(39942), UINT16_C(10044), UINT16_C(44450), UINT16_C(13709), UINT16_C(57508), UINT16_C(60164) } },
    { { UINT16_C(38730), UINT16_C(46100), UINT16_C(44593), UINT16_C(32019) },
      { UINT16_C(38929), UINT16_C(25512), UINT16_C(32193), UINT16_C(58677) },
      { UINT16_C(38730), UINT16_C(38929), UINT16_C(46100), UINT16_C(25512), UINT16_C(44593), UINT16_C(32193), UINT16_C(32019), UINT16_C(58677) } },
    { { UINT16_C(15488), UINT16_C( 8833), UINT16_C( 9705), UINT16_C(64002) },
      { UINT16_C(16026), UINT16_C(10017), UINT16_C( 9587), UINT16_C(48402) },
      { UINT16_C(15488), UINT16_C(16026), UINT16_C( 8833), UINT16_C(10017), UINT16_C( 9705), UINT16_C( 9587), UINT16_C(64002), UINT16_C(48402) } },
    { { UINT16_C( 9917), UINT16_C(61041), UINT16_C(34005), UINT16_C(58987) },
      { UINT16_C( 4893), UINT16_C(56905), UINT16_C(32656), UINT16_C( 4291) },
      { UINT16_C( 9917), UINT16_C( 4893), UINT16_C(61041), UINT16_C(56905), UINT16_C(34005), UINT16_C(32656), UINT16_C(58987), UINT16_C( 4291) } },
    { { UINT16_C(17851), UINT16_C(42034), UINT16_C(13674), UINT16_C( 1183) },
      { UINT16_C(49267), UINT16_C(59179), UINT16_C(15846), UINT16_C(41892) },
      { UINT16_C(17851), UINT16_C(49267), UINT16_C(42034), UINT16_C(59179), UINT16_C(13674), UINT16_C(15846), UINT16_C( 1183), UINT16_C(41892) } },
    { { UINT16_C( 5732), UINT16_C(14737), UINT16_C(64666), UINT16_C(46879) },
      { UINT16_C(26895), UINT16_C(40854), UINT16_C(23016), UINT16_C(41903) },
      { UINT16_C( 5732), UINT16_C(26895), UINT16_C(14737), UINT16_C(40854), UINT16_C(64666), UINT16_C(23016), UINT16_C(46879), UINT16_C(41903) } },
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
    { { UINT32_C(1465855755), UINT32_C(1903543286) },
      { UINT32_C(3129735551), UINT32_C(  15210267) },
      { UINT32_C(1465855755), UINT32_C(3129735551), UINT32_C(1903543286), UINT32_C(  15210267) } },
    { { UINT32_C(3343853614), UINT32_C(2724607266) },
      { UINT32_C(1793977130), UINT32_C(3324349627) },
      { UINT32_C(3343853614), UINT32_C(1793977130), UINT32_C(2724607266), UINT32_C(3324349627) } },
    { { UINT32_C(2988278972), UINT32_C(3340997448) },
      { UINT32_C(2810293900), UINT32_C(4104612550) },
      { UINT32_C(2988278972), UINT32_C(2810293900), UINT32_C(3340997448), UINT32_C(4104612550) } },
    { { UINT32_C(3032217490), UINT32_C(1448485164) },
      { UINT32_C(3368108812), UINT32_C(2358175440) },
      { UINT32_C(3032217490), UINT32_C(3368108812), UINT32_C(1448485164), UINT32_C(2358175440) } },
    { { UINT32_C(3007229035), UINT32_C(3413795391) },
      { UINT32_C(3597859600), UINT32_C(4157282917) },
      { UINT32_C(3007229035), UINT32_C(3597859600), UINT32_C(3413795391), UINT32_C(4157282917) } },
    { { UINT32_C(1034651153), UINT32_C(3029533096) },
      { UINT32_C( 360469573), UINT32_C(2795572027) },
      { UINT32_C(1034651153), UINT32_C( 360469573), UINT32_C(3029533096), UINT32_C(2795572027) } },
    { { UINT32_C(4133085111), UINT32_C(1388434241) },
      { UINT32_C( 875049934), UINT32_C(1579938637) },
      { UINT32_C(4133085111), UINT32_C( 875049934), UINT32_C(1388434241), UINT32_C(1579938637) } },
    { { UINT32_C( 580638586), UINT32_C( 500576216) },
      { UINT32_C(3190969219), UINT32_C( 358929246) },
      { UINT32_C( 580638586), UINT32_C(3190969219), UINT32_C( 500576216), UINT32_C( 358929246) } },
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

#endif /* !defined(SIMDE_BUG_INTEL_857088) */

SIMDE_TEST_FUNC_LIST_BEGIN
#if !defined(SIMDE_BUG_INTEL_857088)
SIMDE_TEST_FUNC_LIST_ENTRY(vst2_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vst2_s8)
SIMDE_TEST_FUNC_LIST_ENTRY(vst2_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vst2_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vst2_u8)
SIMDE_TEST_FUNC_LIST_ENTRY(vst2_u16)
SIMDE_TEST_FUNC_LIST_ENTRY(vst2_u32)

SIMDE_TEST_FUNC_LIST_ENTRY(vst2q_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vst2q_s8)
SIMDE_TEST_FUNC_LIST_ENTRY(vst2q_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vst2q_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vst2q_u8)
SIMDE_TEST_FUNC_LIST_ENTRY(vst2q_u16)
SIMDE_TEST_FUNC_LIST_ENTRY(vst2q_u32)
#endif /* !defined(SIMDE_BUG_INTEL_857088) */
SIMDE_TEST_FUNC_LIST_END

#include "test-neon-footer.h"
