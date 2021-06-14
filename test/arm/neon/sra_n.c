#define SIMDE_TEST_ARM_NEON_INSN sra_n

#include <test/arm/neon/test-neon.h>
#include <simde/arm/neon/sra_n.h>

static int
test_simde_vsra_n_s8 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    int8_t a[8];
    int8_t b[8];
    int8_t r1[8];
    int8_t r3[8];
    int8_t r5[8];
    int8_t r6[8];
    int8_t r8[8];
  } test_vec[] = {
    { { -INT8_C( 110), -INT8_C(  96), -INT8_C(  68),  INT8_C(  99),  INT8_C( 115),  INT8_C(  79),  INT8_C(  90), -INT8_C( 125) },
      {  INT8_C(  44),  INT8_C(  15),  INT8_C(  85),  INT8_C(  89),  INT8_C(   6), -INT8_C(  90), -INT8_C(  51), -INT8_C(  80) },
      { -INT8_C(  88), -INT8_C(  89), -INT8_C(  26), -INT8_C( 113),  INT8_C( 118),  INT8_C(  34),  INT8_C(  64),  INT8_C(  91) },
      { -INT8_C( 105), -INT8_C(  95), -INT8_C(  58),  INT8_C( 110),  INT8_C( 115),  INT8_C(  67),  INT8_C(  83),  INT8_C( 121) },
      { -INT8_C( 109), -INT8_C(  96), -INT8_C(  66),  INT8_C( 101),  INT8_C( 115),  INT8_C(  76),  INT8_C(  88),      INT8_MIN },
      { -INT8_C( 110), -INT8_C(  96), -INT8_C(  67),  INT8_C( 100),  INT8_C( 115),  INT8_C(  77),  INT8_C(  89), -INT8_C( 127) },
      { -INT8_C( 110), -INT8_C(  96), -INT8_C(  68),  INT8_C(  99),  INT8_C( 115),  INT8_C(  78),  INT8_C(  89), -INT8_C( 126) } },
    { {  INT8_C(  22), -INT8_C(  35),  INT8_C(  93), -INT8_C(  94), -INT8_C(  68),  INT8_C( 118),  INT8_C(  60), -INT8_C(  98) },
      { -INT8_C( 104),  INT8_C(   7),  INT8_C(  42),  INT8_C( 107), -INT8_C(  70),  INT8_C(  83), -INT8_C(  72),  INT8_C(  76) },
      { -INT8_C(  30), -INT8_C(  32),  INT8_C( 114), -INT8_C(  41), -INT8_C( 103), -INT8_C(  97),  INT8_C(  24), -INT8_C(  60) },
      {  INT8_C(   9), -INT8_C(  35),  INT8_C(  98), -INT8_C(  81), -INT8_C(  77),      INT8_MIN,  INT8_C(  51), -INT8_C(  89) },
      {  INT8_C(  18), -INT8_C(  35),  INT8_C(  94), -INT8_C(  91), -INT8_C(  71),  INT8_C( 120),  INT8_C(  57), -INT8_C(  96) },
      {  INT8_C(  20), -INT8_C(  35),  INT8_C(  93), -INT8_C(  93), -INT8_C(  70),  INT8_C( 119),  INT8_C(  58), -INT8_C(  97) },
      {  INT8_C(  21), -INT8_C(  35),  INT8_C(  93), -INT8_C(  94), -INT8_C(  69),  INT8_C( 118),  INT8_C(  59), -INT8_C(  98) } },
    { { -INT8_C(  13),  INT8_C( 116), -INT8_C(  81),  INT8_C( 102), -INT8_C(  60),  INT8_C(  10), -INT8_C(  23), -INT8_C(  16) },
      {  INT8_C(  25),  INT8_C(  63),  INT8_C(  74),  INT8_C(  31), -INT8_C(  27),  INT8_C(  23), -INT8_C(  49), -INT8_C(   4) },
      { -INT8_C(   1), -INT8_C( 109), -INT8_C(  44),  INT8_C( 117), -INT8_C(  74),  INT8_C(  21), -INT8_C(  48), -INT8_C(  18) },
      { -INT8_C(  10),  INT8_C( 123), -INT8_C(  72),  INT8_C( 105), -INT8_C(  64),  INT8_C(  12), -INT8_C(  30), -INT8_C(  17) },
      { -INT8_C(  13),  INT8_C( 117), -INT8_C(  79),  INT8_C( 102), -INT8_C(  61),  INT8_C(  10), -INT8_C(  25), -INT8_C(  17) },
      { -INT8_C(  13),  INT8_C( 116), -INT8_C(  80),  INT8_C( 102), -INT8_C(  61),  INT8_C(  10), -INT8_C(  24), -INT8_C(  17) },
      { -INT8_C(  13),  INT8_C( 116), -INT8_C(  81),  INT8_C( 102), -INT8_C(  61),  INT8_C(  10), -INT8_C(  24), -INT8_C(  17) } },
    { { -INT8_C(  12),  INT8_C(  44), -INT8_C(  98), -INT8_C(  80), -INT8_C(  93), -INT8_C(  38),  INT8_C(  79),  INT8_C(  59) },
      { -INT8_C(  31),  INT8_C( 121), -INT8_C(  90), -INT8_C( 100), -INT8_C(  52),  INT8_C(  95), -INT8_C(  24), -INT8_C(  64) },
      { -INT8_C(  28),  INT8_C( 104),  INT8_C( 113),  INT8_C( 126), -INT8_C( 119),  INT8_C(   9),  INT8_C(  67),  INT8_C(  27) },
      { -INT8_C(  16),  INT8_C(  59), -INT8_C( 110), -INT8_C(  93), -INT8_C( 100), -INT8_C(  27),  INT8_C(  76),  INT8_C(  51) },
      { -INT8_C(  13),  INT8_C(  47), -INT8_C( 101), -INT8_C(  84), -INT8_C(  95), -INT8_C(  36),  INT8_C(  78),  INT8_C(  57) },
      { -INT8_C(  13),  INT8_C(  45), -INT8_C( 100), -INT8_C(  82), -INT8_C(  94), -INT8_C(  37),  INT8_C(  78),  INT8_C(  58) },
      { -INT8_C(  13),  INT8_C(  44), -INT8_C(  99), -INT8_C(  81), -INT8_C(  94), -INT8_C(  38),  INT8_C(  78),  INT8_C(  58) } },
    { { -INT8_C(  45), -INT8_C( 104),  INT8_C(  38), -INT8_C( 105), -INT8_C(  94),  INT8_C(  16), -INT8_C( 120), -INT8_C(  69) },
      {  INT8_C(  79), -INT8_C(  46), -INT8_C(  37),  INT8_C(  52), -INT8_C(  23), -INT8_C(  86),  INT8_C(  48), -INT8_C(  34) },
      { -INT8_C(   6), -INT8_C( 127),  INT8_C(  19), -INT8_C(  79), -INT8_C( 106), -INT8_C(  27), -INT8_C(  96), -INT8_C(  86) },
      { -INT8_C(  36), -INT8_C( 110),  INT8_C(  33), -INT8_C(  99), -INT8_C(  97),  INT8_C(   5), -INT8_C( 114), -INT8_C(  74) },
      { -INT8_C(  43), -INT8_C( 106),  INT8_C(  36), -INT8_C( 104), -INT8_C(  95),  INT8_C(  13), -INT8_C( 119), -INT8_C(  71) },
      { -INT8_C(  44), -INT8_C( 105),  INT8_C(  37), -INT8_C( 105), -INT8_C(  95),  INT8_C(  14), -INT8_C( 120), -INT8_C(  70) },
      { -INT8_C(  45), -INT8_C( 105),  INT8_C(  37), -INT8_C( 105), -INT8_C(  95),  INT8_C(  15), -INT8_C( 120), -INT8_C(  70) } },
    { { -INT8_C(  41), -INT8_C(  49), -INT8_C( 114),  INT8_C( 122), -INT8_C(  87), -INT8_C(  35), -INT8_C(  75), -INT8_C( 117) },
      {  INT8_C(  87),  INT8_C(  92),  INT8_C(  39),  INT8_C(  35), -INT8_C(  69),  INT8_C(  15), -INT8_C(  29), -INT8_C( 114) },
      {  INT8_C(   2), -INT8_C(   3), -INT8_C(  95), -INT8_C( 117), -INT8_C( 122), -INT8_C(  28), -INT8_C(  90),  INT8_C(  82) },
      { -INT8_C(  31), -INT8_C(  38), -INT8_C( 110),  INT8_C( 126), -INT8_C(  96), -INT8_C(  34), -INT8_C(  79),  INT8_C( 124) },
      { -INT8_C(  39), -INT8_C(  47), -INT8_C( 113),  INT8_C( 123), -INT8_C(  90), -INT8_C(  35), -INT8_C(  76), -INT8_C( 121) },
      { -INT8_C(  40), -INT8_C(  48), -INT8_C( 114),  INT8_C( 122), -INT8_C(  89), -INT8_C(  35), -INT8_C(  76), -INT8_C( 119) },
      { -INT8_C(  41), -INT8_C(  49), -INT8_C( 114),  INT8_C( 122), -INT8_C(  88), -INT8_C(  35), -INT8_C(  76), -INT8_C( 118) } },
    { { -INT8_C(  89),  INT8_C(  10),  INT8_C(  38),  INT8_C(  73),  INT8_C(  26), -INT8_C(  82),  INT8_C(   5),  INT8_C( 105) },
      {      INT8_MIN, -INT8_C(  32), -INT8_C(  99),  INT8_C( 105), -INT8_C( 118), -INT8_C(  50),  INT8_C(  71),  INT8_C(  97) },
      {  INT8_C( 103), -INT8_C(   6), -INT8_C(  12),  INT8_C( 125), -INT8_C(  33), -INT8_C( 107),  INT8_C(  40), -INT8_C( 103) },
      { -INT8_C( 105),  INT8_C(   6),  INT8_C(  25),  INT8_C(  86),  INT8_C(  11), -INT8_C(  89),  INT8_C(  13),  INT8_C( 117) },
      { -INT8_C(  93),  INT8_C(   9),  INT8_C(  34),  INT8_C(  76),  INT8_C(  22), -INT8_C(  84),  INT8_C(   7),  INT8_C( 108) },
      { -INT8_C(  91),  INT8_C(   9),  INT8_C(  36),  INT8_C(  74),  INT8_C(  24), -INT8_C(  83),  INT8_C(   6),  INT8_C( 106) },
      { -INT8_C(  90),  INT8_C(   9),  INT8_C(  37),  INT8_C(  73),  INT8_C(  25), -INT8_C(  83),  INT8_C(   5),  INT8_C( 105) } },
    { { -INT8_C(  99), -INT8_C(  42), -INT8_C(  37),  INT8_C(  70), -INT8_C(  77), -INT8_C( 111), -INT8_C(  47),  INT8_C(  10) },
      { -INT8_C(  19), -INT8_C(   8),  INT8_C(  46), -INT8_C(  88),  INT8_C(   8),  INT8_C(  17),  INT8_C(  54), -INT8_C(  81) },
      { -INT8_C( 109), -INT8_C(  46), -INT8_C(  14),  INT8_C(  26), -INT8_C(  73), -INT8_C( 103), -INT8_C(  20), -INT8_C(  31) },
      { -INT8_C( 102), -INT8_C(  43), -INT8_C(  32),  INT8_C(  59), -INT8_C(  76), -INT8_C( 109), -INT8_C(  41), -INT8_C(   1) },
      { -INT8_C( 100), -INT8_C(  43), -INT8_C(  36),  INT8_C(  67), -INT8_C(  77), -INT8_C( 111), -INT8_C(  46),  INT8_C(   7) },
      { -INT8_C( 100), -INT8_C(  43), -INT8_C(  37),  INT8_C(  68), -INT8_C(  77), -INT8_C( 111), -INT8_C(  47),  INT8_C(   8) },
      { -INT8_C( 100), -INT8_C(  43), -INT8_C(  37),  INT8_C(  69), -INT8_C(  77), -INT8_C( 111), -INT8_C(  47),  INT8_C(   9) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int8x8_t a = simde_vld1_s8(test_vec[i].a);
    simde_int8x8_t b = simde_vld1_s8(test_vec[i].b);

    simde_int8x8_t r1 = simde_vsra_n_s8(a, b, 1);
    simde_int8x8_t r3 = simde_vsra_n_s8(a, b, 3);
    simde_int8x8_t r5 = simde_vsra_n_s8(a, b, 5);
    simde_int8x8_t r6 = simde_vsra_n_s8(a, b, 6);
    simde_int8x8_t r8 = simde_vsra_n_s8(a, b, 8);

    simde_test_arm_neon_assert_equal_i8x8(r1, simde_vld1_s8(test_vec[i].r1));
    simde_test_arm_neon_assert_equal_i8x8(r3, simde_vld1_s8(test_vec[i].r3));
    simde_test_arm_neon_assert_equal_i8x8(r5, simde_vld1_s8(test_vec[i].r5));
    simde_test_arm_neon_assert_equal_i8x8(r6, simde_vld1_s8(test_vec[i].r6));
    simde_test_arm_neon_assert_equal_i8x8(r8, simde_vld1_s8(test_vec[i].r8));
  }

  return 0;
}

static int
test_simde_vsra_n_s16 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    int16_t a[4];
    int16_t b[4];
    int16_t r3[4];
    int16_t r6[4];
    int16_t r10[4];
    int16_t r13[4];
    int16_t r16[4];
  } test_vec[] = {
    { {  INT16_C( 16993), -INT16_C( 28686),  INT16_C(  3619),  INT16_C( 18657) },
      {  INT16_C(  1775),  INT16_C( 16485),  INT16_C( 22371),  INT16_C(  8441) },
      {  INT16_C( 17214), -INT16_C( 26626),  INT16_C(  6415),  INT16_C( 19712) },
      {  INT16_C( 17020), -INT16_C( 28429),  INT16_C(  3968),  INT16_C( 18788) },
      {  INT16_C( 16994), -INT16_C( 28670),  INT16_C(  3640),  INT16_C( 18665) },
      {  INT16_C( 16993), -INT16_C( 28684),  INT16_C(  3621),  INT16_C( 18658) },
      {  INT16_C( 16993), -INT16_C( 28686),  INT16_C(  3619),  INT16_C( 18657) } },
    { { -INT16_C( 20281),  INT16_C( 10068),  INT16_C( 32106),  INT16_C( 23214) },
      { -INT16_C( 24984), -INT16_C(  5113), -INT16_C(  5004), -INT16_C( 10556) },
      { -INT16_C( 23404),  INT16_C(  9428),  INT16_C( 31480),  INT16_C( 21894) },
      { -INT16_C( 20672),  INT16_C(  9988),  INT16_C( 32027),  INT16_C( 23049) },
      { -INT16_C( 20306),  INT16_C( 10063),  INT16_C( 32101),  INT16_C( 23203) },
      { -INT16_C( 20285),  INT16_C( 10067),  INT16_C( 32105),  INT16_C( 23212) },
      { -INT16_C( 20282),  INT16_C( 10067),  INT16_C( 32105),  INT16_C( 23213) } },
    { { -INT16_C( 18897),  INT16_C( 21093),  INT16_C( 18372), -INT16_C( 19302) },
      { -INT16_C(   179), -INT16_C( 20236), -INT16_C(  4521),  INT16_C(  7888) },
      { -INT16_C( 18920),  INT16_C( 18563),  INT16_C( 17806), -INT16_C( 18316) },
      { -INT16_C( 18900),  INT16_C( 20776),  INT16_C( 18301), -INT16_C( 19179) },
      { -INT16_C( 18898),  INT16_C( 21073),  INT16_C( 18367), -INT16_C( 19295) },
      { -INT16_C( 18898),  INT16_C( 21090),  INT16_C( 18371), -INT16_C( 19302) },
      { -INT16_C( 18898),  INT16_C( 21092),  INT16_C( 18371), -INT16_C( 19302) } },
    { {  INT16_C(  9630),  INT16_C(  2117), -INT16_C(  3166),  INT16_C(  2658) },
      {  INT16_C( 27025),  INT16_C(  1782), -INT16_C( 17834), -INT16_C( 31268) },
      {  INT16_C( 13008),  INT16_C(  2339), -INT16_C(  5396), -INT16_C(  1251) },
      {  INT16_C( 10052),  INT16_C(  2144), -INT16_C(  3445),  INT16_C(  2169) },
      {  INT16_C(  9656),  INT16_C(  2118), -INT16_C(  3184),  INT16_C(  2627) },
      {  INT16_C(  9633),  INT16_C(  2117), -INT16_C(  3169),  INT16_C(  2654) },
      {  INT16_C(  9630),  INT16_C(  2117), -INT16_C(  3167),  INT16_C(  2657) } },
    { {  INT16_C( 16752),  INT16_C( 13783),  INT16_C( 29064), -INT16_C( 10775) },
      { -INT16_C(  8847), -INT16_C( 14203),  INT16_C( 22219),  INT16_C( 27110) },
      {  INT16_C( 15646),  INT16_C( 12007),  INT16_C( 31841), -INT16_C(  7387) },
      {  INT16_C( 16613),  INT16_C( 13561),  INT16_C( 29411), -INT16_C( 10352) },
      {  INT16_C( 16743),  INT16_C( 13769),  INT16_C( 29085), -INT16_C( 10749) },
      {  INT16_C( 16750),  INT16_C( 13781),  INT16_C( 29066), -INT16_C( 10772) },
      {  INT16_C( 16751),  INT16_C( 13782),  INT16_C( 29064), -INT16_C( 10775) } },
    { {  INT16_C( 11387),  INT16_C(  7538), -INT16_C( 11233), -INT16_C( 20185) },
      {  INT16_C(  7742), -INT16_C( 27465), -INT16_C( 27688),  INT16_C( 18713) },
      {  INT16_C( 12354),  INT16_C(  4104), -INT16_C( 14694), -INT16_C( 17846) },
      {  INT16_C( 11507),  INT16_C(  7108), -INT16_C( 11666), -INT16_C( 19893) },
      {  INT16_C( 11394),  INT16_C(  7511), -INT16_C( 11261), -INT16_C( 20167) },
      {  INT16_C( 11387),  INT16_C(  7534), -INT16_C( 11237), -INT16_C( 20183) },
      {  INT16_C( 11387),  INT16_C(  7537), -INT16_C( 11234), -INT16_C( 20185) } },
    { { -INT16_C(  3884),  INT16_C( 23934),  INT16_C( 26465), -INT16_C( 11726) },
      { -INT16_C( 18364),  INT16_C(  4250), -INT16_C( 32498), -INT16_C( 30343) },
      { -INT16_C(  6180),  INT16_C( 24465),  INT16_C( 22402), -INT16_C( 15519) },
      { -INT16_C(  4171),  INT16_C( 24000),  INT16_C( 25957), -INT16_C( 12201) },
      { -INT16_C(  3902),  INT16_C( 23938),  INT16_C( 26433), -INT16_C( 11756) },
      { -INT16_C(  3887),  INT16_C( 23934),  INT16_C( 26461), -INT16_C( 11730) },
      { -INT16_C(  3885),  INT16_C( 23934),  INT16_C( 26464), -INT16_C( 11727) } },
    { { -INT16_C(  5203), -INT16_C( 13146), -INT16_C( 12864), -INT16_C(   387) },
      {  INT16_C( 13547), -INT16_C( 15214), -INT16_C( 21561), -INT16_C( 25587) },
      { -INT16_C(  3510), -INT16_C( 15048), -INT16_C( 15560), -INT16_C(  3586) },
      { -INT16_C(  4992), -INT16_C( 13384), -INT16_C( 13201), -INT16_C(   787) },
      { -INT16_C(  5190), -INT16_C( 13161), -INT16_C( 12886), -INT16_C(   412) },
      { -INT16_C(  5202), -INT16_C( 13148), -INT16_C( 12867), -INT16_C(   391) },
      { -INT16_C(  5203), -INT16_C( 13147), -INT16_C( 12865), -INT16_C(   388) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x4_t a = simde_vld1_s16(test_vec[i].a);
    simde_int16x4_t b = simde_vld1_s16(test_vec[i].b);

    simde_int16x4_t r3 = simde_vsra_n_s16(a, b, 3);
    simde_int16x4_t r6 = simde_vsra_n_s16(a, b, 6);
    simde_int16x4_t r10 = simde_vsra_n_s16(a, b, 10);
    simde_int16x4_t r13 = simde_vsra_n_s16(a, b, 13);
    simde_int16x4_t r16 = simde_vsra_n_s16(a, b, 16);

    simde_test_arm_neon_assert_equal_i16x4(r3, simde_vld1_s16(test_vec[i].r3));
    simde_test_arm_neon_assert_equal_i16x4(r6, simde_vld1_s16(test_vec[i].r6));
    simde_test_arm_neon_assert_equal_i16x4(r10, simde_vld1_s16(test_vec[i].r10));
    simde_test_arm_neon_assert_equal_i16x4(r13, simde_vld1_s16(test_vec[i].r13));
    simde_test_arm_neon_assert_equal_i16x4(r16, simde_vld1_s16(test_vec[i].r16));
  }

  return 0;
}

static int
test_simde_vsra_n_s32 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    int32_t a[2];
    int32_t b[2];
    int32_t r6[2];
    int32_t r13[2];
    int32_t r19[2];
    int32_t r26[2];
    int32_t r32[2];
  } test_vec[] = {
    { {  INT32_C(  1211834128),  INT32_C(  1573037445) },
      {  INT32_C(  1562803979), -INT32_C(  2071099084) },
      {  INT32_C(  1236252940),  INT32_C(  1540676521) },
      {  INT32_C(  1212024899),  INT32_C(  1572784625) },
      {  INT32_C(  1211837108),  INT32_C(  1573033494) },
      {  INT32_C(  1211834151),  INT32_C(  1573037414) },
      {  INT32_C(  1211834128),  INT32_C(  1573037444) } },
    { { -INT32_C(  1716331456),  INT32_C(  1015424990) },
      {  INT32_C(   665328187), -INT32_C(  1086393426) },
      { -INT32_C(  1705935704),  INT32_C(   998450092) },
      { -INT32_C(  1716250240),  INT32_C(  1015292373) },
      { -INT32_C(  1716330187),  INT32_C(  1015422917) },
      { -INT32_C(  1716331447),  INT32_C(  1015424973) },
      { -INT32_C(  1716331456),  INT32_C(  1015424989) } },
    { { -INT32_C(  1744340462),  INT32_C(   720750879) },
      {  INT32_C(  2106071880), -INT32_C(   452913755) },
      { -INT32_C(  1711433089),  INT32_C(   713674101) },
      { -INT32_C(  1744083374),  INT32_C(   720695591) },
      { -INT32_C(  1744336445),  INT32_C(   720750015) },
      { -INT32_C(  1744340431),  INT32_C(   720750872) },
      { -INT32_C(  1744340462),  INT32_C(   720750878) } },
    { { -INT32_C(   797002767),  INT32_C(   369886426) },
      { -INT32_C(   851593954), -INT32_C(  1165198424) },
      { -INT32_C(   810308923),  INT32_C(   351680200) },
      { -INT32_C(   797106722),  INT32_C(   369744189) },
      { -INT32_C(   797004392),  INT32_C(   369884203) },
      { -INT32_C(   797002780),  INT32_C(   369886408) },
      { -INT32_C(   797002768),  INT32_C(   369886425) } },
    { {  INT32_C(   357733365), -INT32_C(  1539356580) },
      {  INT32_C(   136431459), -INT32_C(   823319843) },
      {  INT32_C(   359865106), -INT32_C(  1552220953) },
      {  INT32_C(   357750019), -INT32_C(  1539457083) },
      {  INT32_C(   357733625), -INT32_C(  1539358151) },
      {  INT32_C(   357733367), -INT32_C(  1539356593) },
      {  INT32_C(   357733365), -INT32_C(  1539356581) } },
    { { -INT32_C(  1331794731), -INT32_C(  1882805392) },
      {  INT32_C(   140247904),  INT32_C(  1958930558) },
      { -INT32_C(  1329603358), -INT32_C(  1852197103) },
      { -INT32_C(  1331777611), -INT32_C(  1882566265) },
      { -INT32_C(  1331794464), -INT32_C(  1882801656) },
      { -INT32_C(  1331794729), -INT32_C(  1882805363) },
      { -INT32_C(  1331794731), -INT32_C(  1882805392) } },
    { { -INT32_C(   678881925), -INT32_C(  1065629603) },
      {  INT32_C(  1841929616), -INT32_C(  1791248705) },
      { -INT32_C(   650101775), -INT32_C(  1093617865) },
      { -INT32_C(   678657081), -INT32_C(  1065848262) },
      { -INT32_C(   678878412), -INT32_C(  1065633020) },
      { -INT32_C(   678881898), -INT32_C(  1065629630) },
      { -INT32_C(   678881925), -INT32_C(  1065629604) } },
    { { -INT32_C(  1824138718), -INT32_C(   450753659) },
      { -INT32_C(  1930592754), -INT32_C(   520048794) },
      { -INT32_C(  1854304230), -INT32_C(   458879422) },
      { -INT32_C(  1824374387), -INT32_C(   450817142) },
      { -INT32_C(  1824142401), -INT32_C(   450754651) },
      { -INT32_C(  1824138747), -INT32_C(   450753667) },
      { -INT32_C(  1824138719), -INT32_C(   450753660) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x2_t a = simde_vld1_s32(test_vec[i].a);
    simde_int32x2_t b = simde_vld1_s32(test_vec[i].b);

    simde_int32x2_t r6 = simde_vsra_n_s32(a, b, 6);
    simde_int32x2_t r13 = simde_vsra_n_s32(a, b, 13);
    simde_int32x2_t r19 = simde_vsra_n_s32(a, b, 19);
    simde_int32x2_t r26 = simde_vsra_n_s32(a, b, 26);
    simde_int32x2_t r32 = simde_vsra_n_s32(a, b, 32);

    simde_test_arm_neon_assert_equal_i32x2(r6, simde_vld1_s32(test_vec[i].r6));
    simde_test_arm_neon_assert_equal_i32x2(r13, simde_vld1_s32(test_vec[i].r13));
    simde_test_arm_neon_assert_equal_i32x2(r19, simde_vld1_s32(test_vec[i].r19));
    simde_test_arm_neon_assert_equal_i32x2(r26, simde_vld1_s32(test_vec[i].r26));
    simde_test_arm_neon_assert_equal_i32x2(r32, simde_vld1_s32(test_vec[i].r32));
  }

  return 0;
}

static int
test_simde_vsra_n_s64 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    int64_t a[1];
    int64_t b[1];
    int64_t r13[1];
    int64_t r26[1];
    int64_t r39[1];
    int64_t r52[1];
    int64_t r64[1];
  } test_vec[] = {
    { {  INT64_C(  881464614002129577) },
      {  INT64_C( 7580105769023611175) },
      {  INT64_C(  882389919882137342) },
      {  INT64_C(  881464726954507507) },
      {  INT64_C(  881464614015917709) },
      {  INT64_C(  881464614002131260) },
      {  INT64_C(  881464614002129577) } },
    { { -INT64_C( 6596341350465540194) },
      { -INT64_C( 4922836740847382444) },
      { -INT64_C( 6596942282684881916) },
      { -INT64_C( 6596341423821524001) },
      { -INT64_C( 6596341350474494782) },
      { -INT64_C( 6596341350465541288) },
      { -INT64_C( 6596341350465540195) } },
    { {  INT64_C( 1764960191635937804) },
      { -INT64_C( 7459521215422330873) },
      {  INT64_C( 1764049605550070820) },
      {  INT64_C( 1764960080480409744) },
      {  INT64_C( 1764960191622369013) },
      {  INT64_C( 1764960191635936147) },
      {  INT64_C( 1764960191635937803) } },
    { {  INT64_C( 3135817985201324387) },
      { -INT64_C( 5816714875682811526) },
      {  INT64_C( 3135107936998726387) },
      {  INT64_C( 3135817898525518405) },
      {  INT64_C( 3135817985190743844) },
      {  INT64_C( 3135817985201323095) },
      {  INT64_C( 3135817985201324386) } },
    { { -INT64_C( 2502418275722235589) },
      {  INT64_C( 6861912416510183591) },
      { -INT64_C( 2501580639929204561) },
      { -INT64_C( 2502418173471772573) },
      { -INT64_C( 2502418275709753844) },
      { -INT64_C( 2502418275722234066) },
      { -INT64_C( 2502418275722235589) } },
    { { -INT64_C( 7913734837817545175) },
      {  INT64_C( 8802395695456542421) },
      { -INT64_C( 7912660326624252141) },
      { -INT64_C( 7913734706651628025) },
      { -INT64_C( 7913734837801533711) },
      { -INT64_C( 7913734837817543221) },
      { -INT64_C( 7913734837817545175) } },
    { { -INT64_C( 8103686669931755051) },
      {  INT64_C(  634843580358227827) },
      { -INT64_C( 8103609174377512104) },
      { -INT64_C( 8103686660471848528) },
      { -INT64_C( 8103686669930600278) },
      { -INT64_C( 8103686669931754911) },
      { -INT64_C( 8103686669931755051) } },
    { { -INT64_C( 6232077175440732199) },
      { -INT64_C( 2788492309201575788) },
      { -INT64_C( 6232417567568320282) },
      { -INT64_C( 6232077216992505587) },
      { -INT64_C( 6232077175445804437) },
      { -INT64_C( 6232077175440732819) },
      { -INT64_C( 6232077175440732200) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int64x1_t a = simde_vld1_s64(test_vec[i].a);
    simde_int64x1_t b = simde_vld1_s64(test_vec[i].b);

    simde_int64x1_t r13 = simde_vsra_n_s64(a, b, 13);
    simde_int64x1_t r26 = simde_vsra_n_s64(a, b, 26);
    simde_int64x1_t r39 = simde_vsra_n_s64(a, b, 39);
    simde_int64x1_t r52 = simde_vsra_n_s64(a, b, 52);
    simde_int64x1_t r64 = simde_vsra_n_s64(a, b, 64);

    simde_test_arm_neon_assert_equal_i64x1(r13, simde_vld1_s64(test_vec[i].r13));
    simde_test_arm_neon_assert_equal_i64x1(r26, simde_vld1_s64(test_vec[i].r26));
    simde_test_arm_neon_assert_equal_i64x1(r39, simde_vld1_s64(test_vec[i].r39));
    simde_test_arm_neon_assert_equal_i64x1(r52, simde_vld1_s64(test_vec[i].r52));
    simde_test_arm_neon_assert_equal_i64x1(r64, simde_vld1_s64(test_vec[i].r64));
  }

  return 0;
}

static int
test_simde_vsra_n_u8 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    uint8_t a[8];
    uint8_t b[8];
    uint8_t r1[8];
    uint8_t r3[8];
    uint8_t r5[8];
    uint8_t r6[8];
    uint8_t r8[8];
  } test_vec[] = {
    { { UINT8_C(141), UINT8_C(222), UINT8_C(212), UINT8_C(  6), UINT8_C(198), UINT8_C( 82), UINT8_C(111), UINT8_C(181) },
      { UINT8_C(141), UINT8_C(166), UINT8_C( 70), UINT8_C(142), UINT8_C(210), UINT8_C(176), UINT8_C(168), UINT8_C(170) },
      { UINT8_C(211), UINT8_C( 49), UINT8_C(247), UINT8_C( 77), UINT8_C( 47), UINT8_C(170), UINT8_C(195), UINT8_C( 10) },
      { UINT8_C(158), UINT8_C(242), UINT8_C(220), UINT8_C( 23), UINT8_C(224), UINT8_C(104), UINT8_C(132), UINT8_C(202) },
      { UINT8_C(145), UINT8_C(227), UINT8_C(214), UINT8_C( 10), UINT8_C(204), UINT8_C( 87), UINT8_C(116), UINT8_C(186) },
      { UINT8_C(143), UINT8_C(224), UINT8_C(213), UINT8_C(  8), UINT8_C(201), UINT8_C( 84), UINT8_C(113), UINT8_C(183) },
      { UINT8_C(141), UINT8_C(222), UINT8_C(212), UINT8_C(  6), UINT8_C(198), UINT8_C( 82), UINT8_C(111), UINT8_C(181) } },
    { { UINT8_C(183), UINT8_C( 33), UINT8_C( 32), UINT8_C( 32), UINT8_C( 41), UINT8_C(119), UINT8_C(166), UINT8_C(158) },
      { UINT8_C(237), UINT8_C( 83), UINT8_C( 80), UINT8_C(142), UINT8_C(111), UINT8_C(137), UINT8_C( 95), UINT8_C(252) },
      { UINT8_C( 45), UINT8_C( 74), UINT8_C( 72), UINT8_C(103), UINT8_C( 96), UINT8_C(187), UINT8_C(213), UINT8_C( 28) },
      { UINT8_C(212), UINT8_C( 43), UINT8_C( 42), UINT8_C( 49), UINT8_C( 54), UINT8_C(136), UINT8_C(177), UINT8_C(189) },
      { UINT8_C(190), UINT8_C( 35), UINT8_C( 34), UINT8_C( 36), UINT8_C( 44), UINT8_C(123), UINT8_C(168), UINT8_C(165) },
      { UINT8_C(186), UINT8_C( 34), UINT8_C( 33), UINT8_C( 34), UINT8_C( 42), UINT8_C(121), UINT8_C(167), UINT8_C(161) },
      { UINT8_C(183), UINT8_C( 33), UINT8_C( 32), UINT8_C( 32), UINT8_C( 41), UINT8_C(119), UINT8_C(166), UINT8_C(158) } },
    { { UINT8_C(103), UINT8_C( 51), UINT8_C(  2), UINT8_C( 45), UINT8_C(133), UINT8_C(113), UINT8_C(226), UINT8_C( 19) },
      { UINT8_C( 23), UINT8_C( 40), UINT8_C(161), UINT8_C(233), UINT8_C(217), UINT8_C( 73), UINT8_C(148), UINT8_C(144) },
      { UINT8_C(114), UINT8_C( 71), UINT8_C( 82), UINT8_C(161), UINT8_C(241), UINT8_C(149), UINT8_C( 44), UINT8_C( 91) },
      { UINT8_C(105), UINT8_C( 56), UINT8_C( 22), UINT8_C( 74), UINT8_C(160), UINT8_C(122), UINT8_C(244), UINT8_C( 37) },
      { UINT8_C(103), UINT8_C( 52), UINT8_C(  7), UINT8_C( 52), UINT8_C(139), UINT8_C(115), UINT8_C(230), UINT8_C( 23) },
      { UINT8_C(103), UINT8_C( 51), UINT8_C(  4), UINT8_C( 48), UINT8_C(136), UINT8_C(114), UINT8_C(228), UINT8_C( 21) },
      { UINT8_C(103), UINT8_C( 51), UINT8_C(  2), UINT8_C( 45), UINT8_C(133), UINT8_C(113), UINT8_C(226), UINT8_C( 19) } },
    { { UINT8_C(107), UINT8_C(180), UINT8_C(176), UINT8_C(148), UINT8_C( 43), UINT8_C( 86), UINT8_C( 50), UINT8_C( 25) },
      { UINT8_C(169), UINT8_C(130), UINT8_C(167), UINT8_C( 24), UINT8_C( 11), UINT8_C(  6), UINT8_C( 20), UINT8_C(114) },
      { UINT8_C(191), UINT8_C(245), UINT8_C(  3), UINT8_C(160), UINT8_C( 48), UINT8_C( 89), UINT8_C( 60), UINT8_C( 82) },
      { UINT8_C(128), UINT8_C(196), UINT8_C(196), UINT8_C(151), UINT8_C( 44), UINT8_C( 86), UINT8_C( 52), UINT8_C( 39) },
      { UINT8_C(112), UINT8_C(184), UINT8_C(181), UINT8_C(148), UINT8_C( 43), UINT8_C( 86), UINT8_C( 50), UINT8_C( 28) },
      { UINT8_C(109), UINT8_C(182), UINT8_C(178), UINT8_C(148), UINT8_C( 43), UINT8_C( 86), UINT8_C( 50), UINT8_C( 26) },
      { UINT8_C(107), UINT8_C(180), UINT8_C(176), UINT8_C(148), UINT8_C( 43), UINT8_C( 86), UINT8_C( 50), UINT8_C( 25) } },
    { { UINT8_C( 57), UINT8_C( 22), UINT8_C(160), UINT8_C(191), UINT8_C(135), UINT8_C(130), UINT8_C(210), UINT8_C(158) },
      { UINT8_C(171), UINT8_C(115), UINT8_C(136), UINT8_C(132), UINT8_C(188), UINT8_C( 28), UINT8_C( 20), UINT8_C( 39) },
      { UINT8_C(142), UINT8_C( 79), UINT8_C(228), UINT8_C(  1), UINT8_C(229), UINT8_C(144), UINT8_C(220), UINT8_C(177) },
      { UINT8_C( 78), UINT8_C( 36), UINT8_C(177), UINT8_C(207), UINT8_C(158), UINT8_C(133), UINT8_C(212), UINT8_C(162) },
      { UINT8_C( 62), UINT8_C( 25), UINT8_C(164), UINT8_C(195), UINT8_C(140), UINT8_C(130), UINT8_C(210), UINT8_C(159) },
      { UINT8_C( 59), UINT8_C( 23), UINT8_C(162), UINT8_C(193), UINT8_C(137), UINT8_C(130), UINT8_C(210), UINT8_C(158) },
      { UINT8_C( 57), UINT8_C( 22), UINT8_C(160), UINT8_C(191), UINT8_C(135), UINT8_C(130), UINT8_C(210), UINT8_C(158) } },
    { { UINT8_C(208), UINT8_C(196), UINT8_C(187), UINT8_C(252), UINT8_C( 26), UINT8_C(238), UINT8_C( 21), UINT8_C(195) },
      { UINT8_C(112), UINT8_C(188), UINT8_C(219), UINT8_C(124), UINT8_C(194), UINT8_C(239), UINT8_C(238), UINT8_C(251) },
      { UINT8_C(  8), UINT8_C( 34), UINT8_C( 40), UINT8_C( 58), UINT8_C(123), UINT8_C(101), UINT8_C(140), UINT8_C( 64) },
      { UINT8_C(222), UINT8_C(219), UINT8_C(214), UINT8_C( 11), UINT8_C( 50), UINT8_C( 11), UINT8_C( 50), UINT8_C(226) },
      { UINT8_C(211), UINT8_C(201), UINT8_C(193),    UINT8_MAX, UINT8_C( 32), UINT8_C(245), UINT8_C( 28), UINT8_C(202) },
      { UINT8_C(209), UINT8_C(198), UINT8_C(190), UINT8_C(253), UINT8_C( 29), UINT8_C(241), UINT8_C( 24), UINT8_C(198) },
      { UINT8_C(208), UINT8_C(196), UINT8_C(187), UINT8_C(252), UINT8_C( 26), UINT8_C(238), UINT8_C( 21), UINT8_C(195) } },
    { { UINT8_C(  5), UINT8_C(142), UINT8_C(186), UINT8_C(140), UINT8_C( 17), UINT8_C(140), UINT8_C( 42), UINT8_C(188) },
      {    UINT8_MAX, UINT8_C(178), UINT8_C( 64), UINT8_C(188), UINT8_C(206), UINT8_C( 84), UINT8_C(227), UINT8_C(159) },
      { UINT8_C(132), UINT8_C(231), UINT8_C(218), UINT8_C(234), UINT8_C(120), UINT8_C(182), UINT8_C(155), UINT8_C( 11) },
      { UINT8_C( 36), UINT8_C(164), UINT8_C(194), UINT8_C(163), UINT8_C( 42), UINT8_C(150), UINT8_C( 70), UINT8_C(207) },
      { UINT8_C( 12), UINT8_C(147), UINT8_C(188), UINT8_C(145), UINT8_C( 23), UINT8_C(142), UINT8_C( 49), UINT8_C(192) },
      { UINT8_C(  8), UINT8_C(144), UINT8_C(187), UINT8_C(142), UINT8_C( 20), UINT8_C(141), UINT8_C( 45), UINT8_C(190) },
      { UINT8_C(  5), UINT8_C(142), UINT8_C(186), UINT8_C(140), UINT8_C( 17), UINT8_C(140), UINT8_C( 42), UINT8_C(188) } },
    { { UINT8_C( 24), UINT8_C(159), UINT8_C(155), UINT8_C( 50), UINT8_C(141), UINT8_C(176), UINT8_C(245), UINT8_C(253) },
      { UINT8_C(108), UINT8_C(208), UINT8_C(121), UINT8_C( 46), UINT8_C(191), UINT8_C(104), UINT8_C( 41), UINT8_C(196) },
      { UINT8_C( 78), UINT8_C(  7), UINT8_C(215), UINT8_C( 73), UINT8_C(236), UINT8_C(228), UINT8_C(  9), UINT8_C( 95) },
      { UINT8_C( 37), UINT8_C(185), UINT8_C(170), UINT8_C( 55), UINT8_C(164), UINT8_C(189), UINT8_C(250), UINT8_C( 21) },
      { UINT8_C( 27), UINT8_C(165), UINT8_C(158), UINT8_C( 51), UINT8_C(146), UINT8_C(179), UINT8_C(246), UINT8_C(  3) },
      { UINT8_C( 25), UINT8_C(162), UINT8_C(156), UINT8_C( 50), UINT8_C(143), UINT8_C(177), UINT8_C(245), UINT8_C(  0) },
      { UINT8_C( 24), UINT8_C(159), UINT8_C(155), UINT8_C( 50), UINT8_C(141), UINT8_C(176), UINT8_C(245), UINT8_C(253) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint8x8_t a = simde_vld1_u8(test_vec[i].a);
    simde_uint8x8_t b = simde_vld1_u8(test_vec[i].b);

    simde_uint8x8_t r1 = simde_vsra_n_u8(a, b, 1);
    simde_uint8x8_t r3 = simde_vsra_n_u8(a, b, 3);
    simde_uint8x8_t r5 = simde_vsra_n_u8(a, b, 5);
    simde_uint8x8_t r6 = simde_vsra_n_u8(a, b, 6);
    simde_uint8x8_t r8 = simde_vsra_n_u8(a, b, 8);

    simde_test_arm_neon_assert_equal_u8x8(r1, simde_vld1_u8(test_vec[i].r1));
    simde_test_arm_neon_assert_equal_u8x8(r3, simde_vld1_u8(test_vec[i].r3));
    simde_test_arm_neon_assert_equal_u8x8(r5, simde_vld1_u8(test_vec[i].r5));
    simde_test_arm_neon_assert_equal_u8x8(r6, simde_vld1_u8(test_vec[i].r6));
    simde_test_arm_neon_assert_equal_u8x8(r8, simde_vld1_u8(test_vec[i].r8));
  }

  return 0;
}

static int
test_simde_vsra_n_u16 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    uint16_t a[4];
    uint16_t b[4];
    uint16_t r3[4];
    uint16_t r6[4];
    uint16_t r10[4];
    uint16_t r13[4];
    uint16_t r16[4];
  } test_vec[] = {
    { { UINT16_C(20498), UINT16_C(25529), UINT16_C( 4469), UINT16_C( 6127) },
      { UINT16_C(49386), UINT16_C( 6749), UINT16_C(16746), UINT16_C(54822) },
      { UINT16_C(26671), UINT16_C(26372), UINT16_C( 6562), UINT16_C(12979) },
      { UINT16_C(21269), UINT16_C(25634), UINT16_C( 4730), UINT16_C( 6983) },
      { UINT16_C(20546), UINT16_C(25535), UINT16_C( 4485), UINT16_C( 6180) },
      { UINT16_C(20504), UINT16_C(25529), UINT16_C( 4471), UINT16_C( 6133) },
      { UINT16_C(20498), UINT16_C(25529), UINT16_C( 4469), UINT16_C( 6127) } },
    { { UINT16_C(61768), UINT16_C(49523), UINT16_C(29425), UINT16_C(46079) },
      { UINT16_C(25128), UINT16_C(13143), UINT16_C( 8747), UINT16_C(15851) },
      { UINT16_C(64909), UINT16_C(51165), UINT16_C(30518), UINT16_C(48060) },
      { UINT16_C(62160), UINT16_C(49728), UINT16_C(29561), UINT16_C(46326) },
      { UINT16_C(61792), UINT16_C(49535), UINT16_C(29433), UINT16_C(46094) },
      { UINT16_C(61771), UINT16_C(49524), UINT16_C(29426), UINT16_C(46080) },
      { UINT16_C(61768), UINT16_C(49523), UINT16_C(29425), UINT16_C(46079) } },
    { { UINT16_C(42098), UINT16_C(59296), UINT16_C(36790), UINT16_C(41214) },
      { UINT16_C(23631), UINT16_C(47802), UINT16_C(57757), UINT16_C(58768) },
      { UINT16_C(45051), UINT16_C(65271), UINT16_C(44009), UINT16_C(48560) },
      { UINT16_C(42467), UINT16_C(60042), UINT16_C(37692), UINT16_C(42132) },
      { UINT16_C(42121), UINT16_C(59342), UINT16_C(36846), UINT16_C(41271) },
      { UINT16_C(42100), UINT16_C(59301), UINT16_C(36797), UINT16_C(41221) },
      { UINT16_C(42098), UINT16_C(59296), UINT16_C(36790), UINT16_C(41214) } },
    { { UINT16_C( 1234), UINT16_C(50342), UINT16_C(42614), UINT16_C(40567) },
      { UINT16_C(52744), UINT16_C(13521), UINT16_C(48368), UINT16_C(25457) },
      { UINT16_C( 7827), UINT16_C(52032), UINT16_C(48660), UINT16_C(43749) },
      { UINT16_C( 2058), UINT16_C(50553), UINT16_C(43369), UINT16_C(40964) },
      { UINT16_C( 1285), UINT16_C(50355), UINT16_C(42661), UINT16_C(40591) },
      { UINT16_C( 1240), UINT16_C(50343), UINT16_C(42619), UINT16_C(40570) },
      { UINT16_C( 1234), UINT16_C(50342), UINT16_C(42614), UINT16_C(40567) } },
    { { UINT16_C( 4705), UINT16_C( 5962), UINT16_C(18849), UINT16_C(61879) },
      { UINT16_C(29093), UINT16_C(17067), UINT16_C(15186), UINT16_C( 9511) },
      { UINT16_C( 8341), UINT16_C( 8095), UINT16_C(20747), UINT16_C(63067) },
      { UINT16_C( 5159), UINT16_C( 6228), UINT16_C(19086), UINT16_C(62027) },
      { UINT16_C( 4733), UINT16_C( 5978), UINT16_C(18863), UINT16_C(61888) },
      { UINT16_C( 4708), UINT16_C( 5964), UINT16_C(18850), UINT16_C(61880) },
      { UINT16_C( 4705), UINT16_C( 5962), UINT16_C(18849), UINT16_C(61879) } },
    { { UINT16_C(52543), UINT16_C(46569), UINT16_C(24691), UINT16_C(31828) },
      { UINT16_C( 9519), UINT16_C( 8112), UINT16_C( 8674), UINT16_C(17282) },
      { UINT16_C(53732), UINT16_C(47583), UINT16_C(25775), UINT16_C(33988) },
      { UINT16_C(52691), UINT16_C(46695), UINT16_C(24826), UINT16_C(32098) },
      { UINT16_C(52552), UINT16_C(46576), UINT16_C(24699), UINT16_C(31844) },
      { UINT16_C(52544), UINT16_C(46569), UINT16_C(24692), UINT16_C(31830) },
      { UINT16_C(52543), UINT16_C(46569), UINT16_C(24691), UINT16_C(31828) } },
    { { UINT16_C(52531), UINT16_C(54618), UINT16_C( 4374), UINT16_C(48070) },
      { UINT16_C(29058), UINT16_C(54781), UINT16_C( 9388), UINT16_C(60666) },
      { UINT16_C(56163), UINT16_C(61465), UINT16_C( 5547), UINT16_C(55653) },
      { UINT16_C(52985), UINT16_C(55473), UINT16_C( 4520), UINT16_C(49017) },
      { UINT16_C(52559), UINT16_C(54671), UINT16_C( 4383), UINT16_C(48129) },
      { UINT16_C(52534), UINT16_C(54624), UINT16_C( 4375), UINT16_C(48077) },
      { UINT16_C(52531), UINT16_C(54618), UINT16_C( 4374), UINT16_C(48070) } },
    { { UINT16_C(58353), UINT16_C(26017), UINT16_C(62787), UINT16_C(29409) },
      { UINT16_C(37147), UINT16_C(64914), UINT16_C( 5298), UINT16_C(58944) },
      { UINT16_C(62996), UINT16_C(34131), UINT16_C(63449), UINT16_C(36777) },
      { UINT16_C(58933), UINT16_C(27031), UINT16_C(62869), UINT16_C(30330) },
      { UINT16_C(58389), UINT16_C(26080), UINT16_C(62792), UINT16_C(29466) },
      { UINT16_C(58357), UINT16_C(26024), UINT16_C(62787), UINT16_C(29416) },
      { UINT16_C(58353), UINT16_C(26017), UINT16_C(62787), UINT16_C(29409) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint16x4_t a = simde_vld1_u16(test_vec[i].a);
    simde_uint16x4_t b = simde_vld1_u16(test_vec[i].b);

    simde_uint16x4_t r3 = simde_vsra_n_u16(a, b, 3);
    simde_uint16x4_t r6 = simde_vsra_n_u16(a, b, 6);
    simde_uint16x4_t r10 = simde_vsra_n_u16(a, b, 10);
    simde_uint16x4_t r13 = simde_vsra_n_u16(a, b, 13);
    simde_uint16x4_t r16 = simde_vsra_n_u16(a, b, 16);

    simde_test_arm_neon_assert_equal_u16x4(r3, simde_vld1_u16(test_vec[i].r3));
    simde_test_arm_neon_assert_equal_u16x4(r6, simde_vld1_u16(test_vec[i].r6));
    simde_test_arm_neon_assert_equal_u16x4(r10, simde_vld1_u16(test_vec[i].r10));
    simde_test_arm_neon_assert_equal_u16x4(r13, simde_vld1_u16(test_vec[i].r13));
    simde_test_arm_neon_assert_equal_u16x4(r16, simde_vld1_u16(test_vec[i].r16));
  }

  return 0;
}

static int
test_simde_vsra_n_u32 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    uint32_t a[2];
    uint32_t b[2];
    uint32_t r6[2];
    uint32_t r13[2];
    uint32_t r19[2];
    uint32_t r26[2];
    uint32_t r32[2];
  } test_vec[] = {
    { { UINT32_C(3659509063), UINT32_C(2568259154) },
      { UINT32_C(2718098257), UINT32_C(1952907512) },
      { UINT32_C(3701979348), UINT32_C(2598773333) },
      { UINT32_C(3659840862), UINT32_C(2568497546) },
      { UINT32_C(3659514247), UINT32_C(2568262878) },
      { UINT32_C(3659509103), UINT32_C(2568259183) },
      { UINT32_C(3659509063), UINT32_C(2568259154) } },
    { { UINT32_C(1073588353), UINT32_C(2728011964) },
      { UINT32_C(3612159475), UINT32_C(4002580135) },
      { UINT32_C(1130028344), UINT32_C(2790552278) },
      { UINT32_C(1074029290), UINT32_C(2728500560) },
      { UINT32_C(1073595242), UINT32_C(2728019598) },
      { UINT32_C(1073588406), UINT32_C(2728012023) },
      { UINT32_C(1073588353), UINT32_C(2728011964) } },
    { { UINT32_C(2261299508), UINT32_C(2300566584) },
      { UINT32_C(3073057215), UINT32_C(2737541922) },
      { UINT32_C(2309316026), UINT32_C(2343340676) },
      { UINT32_C(2261674637), UINT32_C(2300900756) },
      { UINT32_C(2261305369), UINT32_C(2300571805) },
      { UINT32_C(2261299553), UINT32_C(2300566624) },
      { UINT32_C(2261299508), UINT32_C(2300566584) } },
    { { UINT32_C(4175571259), UINT32_C(1167752529) },
      { UINT32_C(1360849066), UINT32_C(2722082670) },
      { UINT32_C(4196834525), UINT32_C(1210285070) },
      { UINT32_C(4175737378), UINT32_C(1168084814) },
      { UINT32_C(4175573854), UINT32_C(1167757720) },
      { UINT32_C(4175571279), UINT32_C(1167752569) },
      { UINT32_C(4175571259), UINT32_C(1167752529) } },
    { { UINT32_C(2552760160), UINT32_C(2736932836) },
      { UINT32_C(2338016617), UINT32_C( 472811232) },
      { UINT32_C(2589291669), UINT32_C(2744320511) },
      { UINT32_C(2553045562), UINT32_C(2736990552) },
      { UINT32_C(2552764619), UINT32_C(2736933737) },
      { UINT32_C(2552760194), UINT32_C(2736932843) },
      { UINT32_C(2552760160), UINT32_C(2736932836) } },
    { { UINT32_C(  18092207), UINT32_C( 944156301) },
      { UINT32_C(  92889750), UINT32_C(1923598609) },
      { UINT32_C(  19543609), UINT32_C( 974212529) },
      { UINT32_C(  18103546), UINT32_C( 944391115) },
      { UINT32_C(  18092384), UINT32_C( 944159969) },
      { UINT32_C(  18092208), UINT32_C( 944156329) },
      { UINT32_C(  18092207), UINT32_C( 944156301) } },
    { { UINT32_C(3020607696), UINT32_C(2153262103) },
      { UINT32_C(1510716282), UINT32_C(3916839225) },
      { UINT32_C(3044212637), UINT32_C(2214462715) },
      { UINT32_C(3020792109), UINT32_C(2153740232) },
      { UINT32_C(3020610577), UINT32_C(2153269573) },
      { UINT32_C(3020607718), UINT32_C(2153262161) },
      { UINT32_C(3020607696), UINT32_C(2153262103) } },
    { { UINT32_C(3622472266), UINT32_C(3473879097) },
      { UINT32_C(2765396370), UINT32_C( 840334434) },
      { UINT32_C(3665681584), UINT32_C(3487009322) },
      { UINT32_C(3622809838), UINT32_C(3473981676) },
      { UINT32_C(3622477540), UINT32_C(3473880699) },
      { UINT32_C(3622472307), UINT32_C(3473879109) },
      { UINT32_C(3622472266), UINT32_C(3473879097) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint32x2_t a = simde_vld1_u32(test_vec[i].a);
    simde_uint32x2_t b = simde_vld1_u32(test_vec[i].b);

    simde_uint32x2_t r6 = simde_vsra_n_u32(a, b, 6);
    simde_uint32x2_t r13 = simde_vsra_n_u32(a, b, 13);
    simde_uint32x2_t r19 = simde_vsra_n_u32(a, b, 19);
    simde_uint32x2_t r26 = simde_vsra_n_u32(a, b, 26);
    simde_uint32x2_t r32 = simde_vsra_n_u32(a, b, 32);

    simde_test_arm_neon_assert_equal_u32x2(r6, simde_vld1_u32(test_vec[i].r6));
    simde_test_arm_neon_assert_equal_u32x2(r13, simde_vld1_u32(test_vec[i].r13));
    simde_test_arm_neon_assert_equal_u32x2(r19, simde_vld1_u32(test_vec[i].r19));
    simde_test_arm_neon_assert_equal_u32x2(r26, simde_vld1_u32(test_vec[i].r26));
    simde_test_arm_neon_assert_equal_u32x2(r32, simde_vld1_u32(test_vec[i].r32));
  }

  return 0;
}

static int
test_simde_vsra_n_u64 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    uint64_t a[1];
    uint64_t b[1];
    uint64_t r13[1];
    uint64_t r26[1];
    uint64_t r39[1];
    uint64_t r52[1];
    uint64_t r64[1];
  } test_vec[] = {
    { { UINT64_C(13919412844583952900) },
      { UINT64_C( 1584289983876654346) },
      { UINT64_C(13919606239357375343) },
      { UINT64_C(13919412868191713327) },
      { UINT64_C(13919412844586834706) },
      { UINT64_C(13919412844583953251) },
      { UINT64_C(13919412844583952900) } },
    { { UINT64_C( 3471010265826057447) },
      { UINT64_C( 6591570382045680709) },
      { UINT64_C( 3471814900882459507) },
      { UINT64_C( 3471010364048110230) },
      { UINT64_C( 3471010265838047443) },
      { UINT64_C( 3471010265826058910) },
      { UINT64_C( 3471010265826057447) } },
    { { UINT64_C(11715387210285901976) },
      { UINT64_C( 3547795583048729295) },
      { UINT64_C(11715820290801410854) },
      { UINT64_C(11715387263152175841) },
      { UINT64_C(11715387210292355378) },
      { UINT64_C(11715387210285902763) },
      { UINT64_C(11715387210285901976) } },
    { { UINT64_C( 5606046988161484585) },
      { UINT64_C( 3167302207410969923) },
      { UINT64_C( 5606433621731725181) },
      { UINT64_C( 5606047035357965327) },
      { UINT64_C( 5606046988167245874) },
      { UINT64_C( 5606046988161485288) },
      { UINT64_C( 5606046988161484585) } },
    { { UINT64_C( 7829389879338283884) },
      { UINT64_C( 8057449110591240278) },
      { UINT64_C( 7830373454669166603) },
      { UINT64_C( 7829389999403631892) },
      { UINT64_C( 7829389879352940298) },
      { UINT64_C( 7829389879338285673) },
      { UINT64_C( 7829389879338283884) } },
    { { UINT64_C( 5092400213135152214) },
      { UINT64_C(11975867704836863604) },
      { UINT64_C( 5093862111048340307) },
      { UINT64_C( 5092400391589487319) },
      { UINT64_C( 5092400213156936190) },
      { UINT64_C( 5092400213135154873) },
      { UINT64_C( 5092400213135152214) } },
    { { UINT64_C( 2022208341025698055) },
      { UINT64_C(14411955805773144907) },
      { UINT64_C( 2023967612974644972) },
      { UINT64_C( 2022208555780574635) },
      { UINT64_C( 2022208341051913249) },
      { UINT64_C( 2022208341025701255) },
      { UINT64_C( 2022208341025698055) } },
    { { UINT64_C( 6281063407037058273) },
      { UINT64_C(16530621718664710791) },
      { UINT64_C( 6283081305196074961) },
      { UINT64_C( 6281063653362517137) },
      { UINT64_C( 6281063407067127298) },
      { UINT64_C( 6281063407037061943) },
      { UINT64_C( 6281063407037058273) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint64x1_t a = simde_vld1_u64(test_vec[i].a);
    simde_uint64x1_t b = simde_vld1_u64(test_vec[i].b);

    simde_uint64x1_t r13 = simde_vsra_n_u64(a, b, 13);
    simde_uint64x1_t r26 = simde_vsra_n_u64(a, b, 26);
    simde_uint64x1_t r39 = simde_vsra_n_u64(a, b, 39);
    simde_uint64x1_t r52 = simde_vsra_n_u64(a, b, 52);
    simde_uint64x1_t r64 = simde_vsra_n_u64(a, b, 64);

    simde_test_arm_neon_assert_equal_u64x1(r13, simde_vld1_u64(test_vec[i].r13));
    simde_test_arm_neon_assert_equal_u64x1(r26, simde_vld1_u64(test_vec[i].r26));
    simde_test_arm_neon_assert_equal_u64x1(r39, simde_vld1_u64(test_vec[i].r39));
    simde_test_arm_neon_assert_equal_u64x1(r52, simde_vld1_u64(test_vec[i].r52));
    simde_test_arm_neon_assert_equal_u64x1(r64, simde_vld1_u64(test_vec[i].r64));
  }

  return 0;
}

static int
test_simde_vsraq_n_s8 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    int8_t a[16];
    int8_t b[16];
    int8_t r1[16];
    int8_t r3[16];
    int8_t r5[16];
    int8_t r6[16];
    int8_t r8[16];
  } test_vec[] = {
    { {  INT8_C( 110),  INT8_C(  63), -INT8_C(  32),  INT8_C(  64), -INT8_C( 122), -INT8_C(  34),  INT8_C(  93), -INT8_C( 112),
         INT8_C(  37), -INT8_C(   2),  INT8_C( 120), -INT8_C(  61), -INT8_C(  24),  INT8_C(  68), -INT8_C(  47), -INT8_C(  81) },
      {  INT8_C(  67),  INT8_C(   4),  INT8_C(  19), -INT8_C(  68), -INT8_C(  34),  INT8_C(  22), -INT8_C(  66),      INT8_MAX,
        -INT8_C(  50), -INT8_C(  39), -INT8_C(  16), -INT8_C(  65),  INT8_C(  92), -INT8_C(  85),  INT8_C(  75), -INT8_C(  54) },
      { -INT8_C( 113),  INT8_C(  65), -INT8_C(  23),  INT8_C(  30),  INT8_C( 117), -INT8_C(  23),  INT8_C(  60), -INT8_C(  49),
         INT8_C(  12), -INT8_C(  22),  INT8_C( 112), -INT8_C(  94),  INT8_C(  22),  INT8_C(  25), -INT8_C(  10), -INT8_C( 108) },
      {  INT8_C( 118),  INT8_C(  63), -INT8_C(  30),  INT8_C(  55), -INT8_C( 127), -INT8_C(  32),  INT8_C(  84), -INT8_C(  97),
         INT8_C(  30), -INT8_C(   7),  INT8_C( 118), -INT8_C(  70), -INT8_C(  13),  INT8_C(  57), -INT8_C(  38), -INT8_C(  88) },
      {  INT8_C( 112),  INT8_C(  63), -INT8_C(  32),  INT8_C(  61), -INT8_C( 124), -INT8_C(  34),  INT8_C(  90), -INT8_C( 109),
         INT8_C(  35), -INT8_C(   4),  INT8_C( 119), -INT8_C(  64), -INT8_C(  22),  INT8_C(  65), -INT8_C(  45), -INT8_C(  83) },
      {  INT8_C( 111),  INT8_C(  63), -INT8_C(  32),  INT8_C(  62), -INT8_C( 123), -INT8_C(  34),  INT8_C(  91), -INT8_C( 111),
         INT8_C(  36), -INT8_C(   3),  INT8_C( 119), -INT8_C(  63), -INT8_C(  23),  INT8_C(  66), -INT8_C(  46), -INT8_C(  82) },
      {  INT8_C( 110),  INT8_C(  63), -INT8_C(  32),  INT8_C(  63), -INT8_C( 123), -INT8_C(  34),  INT8_C(  92), -INT8_C( 112),
         INT8_C(  36), -INT8_C(   3),  INT8_C( 119), -INT8_C(  62), -INT8_C(  24),  INT8_C(  67), -INT8_C(  47), -INT8_C(  82) } },
    { { -INT8_C(  22),  INT8_C(  43),  INT8_C(  10),  INT8_C( 112),  INT8_C(  10),  INT8_C( 104),  INT8_C(   0),  INT8_C(  47),
         INT8_C( 102),  INT8_C( 121), -INT8_C(  14),  INT8_C(  78), -INT8_C(  67), -INT8_C(  61), -INT8_C(   3),  INT8_C(   1) },
      { -INT8_C(  57),  INT8_C(  16), -INT8_C(  67), -INT8_C(  91),  INT8_C(  38),  INT8_C( 123),  INT8_C(  36), -INT8_C(  12),
         INT8_C(  84),  INT8_C(  20), -INT8_C(  77), -INT8_C(  80), -INT8_C(  64), -INT8_C(   2),  INT8_C( 122), -INT8_C(  86) },
      { -INT8_C(  51),  INT8_C(  51), -INT8_C(  24),  INT8_C(  66),  INT8_C(  29), -INT8_C(  91),  INT8_C(  18),  INT8_C(  41),
        -INT8_C( 112), -INT8_C( 125), -INT8_C(  53),  INT8_C(  38), -INT8_C(  99), -INT8_C(  62),  INT8_C(  58), -INT8_C(  42) },
      { -INT8_C(  30),  INT8_C(  45),  INT8_C(   1),  INT8_C( 100),  INT8_C(  14),  INT8_C( 119),  INT8_C(   4),  INT8_C(  45),
         INT8_C( 112),  INT8_C( 123), -INT8_C(  24),  INT8_C(  68), -INT8_C(  75), -INT8_C(  62),  INT8_C(  12), -INT8_C(  10) },
      { -INT8_C(  24),  INT8_C(  43),  INT8_C(   7),  INT8_C( 109),  INT8_C(  11),  INT8_C( 107),  INT8_C(   1),  INT8_C(  46),
         INT8_C( 104),  INT8_C( 121), -INT8_C(  17),  INT8_C(  75), -INT8_C(  69), -INT8_C(  62),  INT8_C(   0), -INT8_C(   2) },
      { -INT8_C(  23),  INT8_C(  43),  INT8_C(   8),  INT8_C( 110),  INT8_C(  10),  INT8_C( 105),  INT8_C(   0),  INT8_C(  46),
         INT8_C( 103),  INT8_C( 121), -INT8_C(  16),  INT8_C(  76), -INT8_C(  68), -INT8_C(  62), -INT8_C(   2), -INT8_C(   1) },
      { -INT8_C(  23),  INT8_C(  43),  INT8_C(   9),  INT8_C( 111),  INT8_C(  10),  INT8_C( 104),  INT8_C(   0),  INT8_C(  46),
         INT8_C( 102),  INT8_C( 121), -INT8_C(  15),  INT8_C(  77), -INT8_C(  68), -INT8_C(  62), -INT8_C(   3),  INT8_C(   0) } },
    { {  INT8_C(  42), -INT8_C( 123),  INT8_C(  27),  INT8_C(  52), -INT8_C(  19),  INT8_C(  27),  INT8_C(  99),  INT8_C(  83),
        -INT8_C( 108),  INT8_C(  85), -INT8_C(  94),  INT8_C(  82),  INT8_C(  25), -INT8_C(  97),  INT8_C(  83), -INT8_C(  32) },
      { -INT8_C(  80),  INT8_C(  16), -INT8_C( 122), -INT8_C(  42), -INT8_C( 117), -INT8_C(  86), -INT8_C(  53), -INT8_C(  33),
        -INT8_C(  65),  INT8_C( 126), -INT8_C( 112),      INT8_MAX,  INT8_C( 125),  INT8_C(  10),  INT8_C(  41), -INT8_C(  89) },
      {  INT8_C(   2), -INT8_C( 115), -INT8_C(  34),  INT8_C(  31), -INT8_C(  78), -INT8_C(  16),  INT8_C(  72),  INT8_C(  66),
         INT8_C( 115), -INT8_C( 108),  INT8_C( 106), -INT8_C( 111),  INT8_C(  87), -INT8_C(  92),  INT8_C( 103), -INT8_C(  77) },
      {  INT8_C(  32), -INT8_C( 121),  INT8_C(  11),  INT8_C(  46), -INT8_C(  34),  INT8_C(  16),  INT8_C(  92),  INT8_C(  78),
        -INT8_C( 117),  INT8_C( 100), -INT8_C( 108),  INT8_C(  97),  INT8_C(  40), -INT8_C(  96),  INT8_C(  88), -INT8_C(  44) },
      {  INT8_C(  39), -INT8_C( 123),  INT8_C(  23),  INT8_C(  50), -INT8_C(  23),  INT8_C(  24),  INT8_C(  97),  INT8_C(  81),
        -INT8_C( 111),  INT8_C(  88), -INT8_C(  98),  INT8_C(  85),  INT8_C(  28), -INT8_C(  97),  INT8_C(  84), -INT8_C(  35) },
      {  INT8_C(  40), -INT8_C( 123),  INT8_C(  25),  INT8_C(  51), -INT8_C(  21),  INT8_C(  25),  INT8_C(  98),  INT8_C(  82),
        -INT8_C( 110),  INT8_C(  86), -INT8_C(  96),  INT8_C(  83),  INT8_C(  26), -INT8_C(  97),  INT8_C(  83), -INT8_C(  34) },
      {  INT8_C(  41), -INT8_C( 123),  INT8_C(  26),  INT8_C(  51), -INT8_C(  20),  INT8_C(  26),  INT8_C(  98),  INT8_C(  82),
        -INT8_C( 109),  INT8_C(  85), -INT8_C(  95),  INT8_C(  82),  INT8_C(  25), -INT8_C(  97),  INT8_C(  83), -INT8_C(  33) } },
    { { -INT8_C( 113),  INT8_C(  68), -INT8_C(  37),  INT8_C( 124),  INT8_C(  96),  INT8_C(  62), -INT8_C(  48), -INT8_C(  12),
        -INT8_C( 109),  INT8_C( 114),  INT8_C(  70), -INT8_C(  84),  INT8_C(  17), -INT8_C( 103), -INT8_C( 115), -INT8_C(  63) },
      { -INT8_C(  87),  INT8_C(  19), -INT8_C( 104),  INT8_C(  52), -INT8_C(  67),  INT8_C(  99),  INT8_C(  20),  INT8_C( 124),
        -INT8_C(  31), -INT8_C(  92), -INT8_C(   5),  INT8_C(  94), -INT8_C(  82),  INT8_C(  37),  INT8_C(   5),  INT8_C(  62) },
      {  INT8_C(  99),  INT8_C(  77), -INT8_C(  89), -INT8_C( 106),  INT8_C(  62),  INT8_C( 111), -INT8_C(  38),  INT8_C(  50),
        -INT8_C( 125),  INT8_C(  68),  INT8_C(  67), -INT8_C(  37), -INT8_C(  24), -INT8_C(  85), -INT8_C( 113), -INT8_C(  32) },
      { -INT8_C( 124),  INT8_C(  70), -INT8_C(  50), -INT8_C( 126),  INT8_C(  87),  INT8_C(  74), -INT8_C(  46),  INT8_C(   3),
        -INT8_C( 113),  INT8_C( 102),  INT8_C(  69), -INT8_C(  73),  INT8_C(   6), -INT8_C(  99), -INT8_C( 115), -INT8_C(  56) },
      { -INT8_C( 116),  INT8_C(  68), -INT8_C(  41),  INT8_C( 125),  INT8_C(  93),  INT8_C(  65), -INT8_C(  48), -INT8_C(   9),
        -INT8_C( 110),  INT8_C( 111),  INT8_C(  69), -INT8_C(  82),  INT8_C(  14), -INT8_C( 102), -INT8_C( 115), -INT8_C(  62) },
      { -INT8_C( 115),  INT8_C(  68), -INT8_C(  39),  INT8_C( 124),  INT8_C(  94),  INT8_C(  63), -INT8_C(  48), -INT8_C(  11),
        -INT8_C( 110),  INT8_C( 112),  INT8_C(  69), -INT8_C(  83),  INT8_C(  15), -INT8_C( 103), -INT8_C( 115), -INT8_C(  63) },
      { -INT8_C( 114),  INT8_C(  68), -INT8_C(  38),  INT8_C( 124),  INT8_C(  95),  INT8_C(  62), -INT8_C(  48), -INT8_C(  12),
        -INT8_C( 110),  INT8_C( 113),  INT8_C(  69), -INT8_C(  84),  INT8_C(  16), -INT8_C( 103), -INT8_C( 115), -INT8_C(  63) } },
    { {  INT8_C( 105), -INT8_C(  32), -INT8_C(  70), -INT8_C(  55),  INT8_C(  30), -INT8_C( 118), -INT8_C(  66), -INT8_C(  78),
        -INT8_C(   4),  INT8_C(   4),  INT8_C(  94),  INT8_C(  14), -INT8_C(  98), -INT8_C(  21), -INT8_C(  49),  INT8_C(  71) },
      { -INT8_C(   2),  INT8_C( 103),  INT8_C( 124), -INT8_C(  68), -INT8_C(  54), -INT8_C( 112),  INT8_C(  56), -INT8_C(  84),
         INT8_C(  52),  INT8_C(  52),  INT8_C(  10), -INT8_C(  30),  INT8_C(  89),  INT8_C(  16),  INT8_C(  32), -INT8_C(  62) },
      {  INT8_C( 104),  INT8_C(  19), -INT8_C(   8), -INT8_C(  89),  INT8_C(   3),  INT8_C(  82), -INT8_C(  38), -INT8_C( 120),
         INT8_C(  22),  INT8_C(  30),  INT8_C(  99), -INT8_C(   1), -INT8_C(  54), -INT8_C(  13), -INT8_C(  33),  INT8_C(  40) },
      {  INT8_C( 104), -INT8_C(  20), -INT8_C(  55), -INT8_C(  64),  INT8_C(  23),  INT8_C( 124), -INT8_C(  59), -INT8_C(  89),
         INT8_C(   2),  INT8_C(  10),  INT8_C(  95),  INT8_C(  10), -INT8_C(  87), -INT8_C(  19), -INT8_C(  45),  INT8_C(  63) },
      {  INT8_C( 104), -INT8_C(  29), -INT8_C(  67), -INT8_C(  58),  INT8_C(  28), -INT8_C( 122), -INT8_C(  65), -INT8_C(  81),
        -INT8_C(   3),  INT8_C(   5),  INT8_C(  94),  INT8_C(  13), -INT8_C(  96), -INT8_C(  21), -INT8_C(  48),  INT8_C(  69) },
      {  INT8_C( 104), -INT8_C(  31), -INT8_C(  69), -INT8_C(  57),  INT8_C(  29), -INT8_C( 120), -INT8_C(  66), -INT8_C(  80),
        -INT8_C(   4),  INT8_C(   4),  INT8_C(  94),  INT8_C(  13), -INT8_C(  97), -INT8_C(  21), -INT8_C(  49),  INT8_C(  70) },
      {  INT8_C( 104), -INT8_C(  32), -INT8_C(  70), -INT8_C(  56),  INT8_C(  29), -INT8_C( 119), -INT8_C(  66), -INT8_C(  79),
        -INT8_C(   4),  INT8_C(   4),  INT8_C(  94),  INT8_C(  13), -INT8_C(  98), -INT8_C(  21), -INT8_C(  49),  INT8_C(  70) } },
    { { -INT8_C(  16), -INT8_C(  37), -INT8_C( 116),  INT8_C(  15),  INT8_C( 101),  INT8_C(  74), -INT8_C(  63),  INT8_C(  98),
         INT8_C(  78),  INT8_C(  31),  INT8_C( 112), -INT8_C(  20),  INT8_C(  11),  INT8_C(  63),  INT8_C(  52),  INT8_C(   9) },
      { -INT8_C(  89), -INT8_C(  80), -INT8_C(  59),  INT8_C( 113),  INT8_C(  64), -INT8_C(   2),  INT8_C(  29),  INT8_C( 116),
         INT8_C(  50),  INT8_C(  40),  INT8_C(  86), -INT8_C( 117),  INT8_C(  56),  INT8_C( 119),  INT8_C(  77),  INT8_C(  40) },
      { -INT8_C(  61), -INT8_C(  77),  INT8_C( 110),  INT8_C(  71), -INT8_C( 123),  INT8_C(  73), -INT8_C(  49), -INT8_C( 100),
         INT8_C( 103),  INT8_C(  51), -INT8_C( 101), -INT8_C(  79),  INT8_C(  39),  INT8_C( 122),  INT8_C(  90),  INT8_C(  29) },
      { -INT8_C(  28), -INT8_C(  47), -INT8_C( 124),  INT8_C(  29),  INT8_C( 109),  INT8_C(  73), -INT8_C(  60),  INT8_C( 112),
         INT8_C(  84),  INT8_C(  36),  INT8_C( 122), -INT8_C(  35),  INT8_C(  18),  INT8_C(  77),  INT8_C(  61),  INT8_C(  14) },
      { -INT8_C(  19), -INT8_C(  40), -INT8_C( 118),  INT8_C(  18),  INT8_C( 103),  INT8_C(  73), -INT8_C(  63),  INT8_C( 101),
         INT8_C(  79),  INT8_C(  32),  INT8_C( 114), -INT8_C(  24),  INT8_C(  12),  INT8_C(  66),  INT8_C(  54),  INT8_C(  10) },
      { -INT8_C(  18), -INT8_C(  39), -INT8_C( 117),  INT8_C(  16),  INT8_C( 102),  INT8_C(  73), -INT8_C(  63),  INT8_C(  99),
         INT8_C(  78),  INT8_C(  31),  INT8_C( 113), -INT8_C(  22),  INT8_C(  11),  INT8_C(  64),  INT8_C(  53),  INT8_C(   9) },
      { -INT8_C(  17), -INT8_C(  38), -INT8_C( 117),  INT8_C(  15),  INT8_C( 101),  INT8_C(  73), -INT8_C(  63),  INT8_C(  98),
         INT8_C(  78),  INT8_C(  31),  INT8_C( 112), -INT8_C(  21),  INT8_C(  11),  INT8_C(  63),  INT8_C(  52),  INT8_C(   9) } },
    { {  INT8_C(  82), -INT8_C(  39),  INT8_C(  55), -INT8_C(  73),  INT8_C(  35), -INT8_C(   8),  INT8_C(  25),  INT8_C( 114),
         INT8_C(  24), -INT8_C( 119),  INT8_C(  94),  INT8_C(  35), -INT8_C(  55), -INT8_C( 110),  INT8_C(  44),  INT8_C( 112) },
      {  INT8_C(  66), -INT8_C(  14), -INT8_C(  31), -INT8_C( 126), -INT8_C(  16), -INT8_C(   1), -INT8_C(  10),  INT8_C(  34),
         INT8_C(  39),  INT8_C(  77), -INT8_C(  83),  INT8_C(  95), -INT8_C(  60), -INT8_C(   6), -INT8_C( 121),  INT8_C(  22) },
      {  INT8_C( 115), -INT8_C(  46),  INT8_C(  39),  INT8_C( 120),  INT8_C(  27), -INT8_C(   9),  INT8_C(  20), -INT8_C( 125),
         INT8_C(  43), -INT8_C(  81),  INT8_C(  52),  INT8_C(  82), -INT8_C(  85), -INT8_C( 113), -INT8_C(  17),  INT8_C( 123) },
      {  INT8_C(  90), -INT8_C(  41),  INT8_C(  51), -INT8_C(  89),  INT8_C(  33), -INT8_C(   9),  INT8_C(  23),  INT8_C( 118),
         INT8_C(  28), -INT8_C( 110),  INT8_C(  83),  INT8_C(  46), -INT8_C(  63), -INT8_C( 111),  INT8_C(  28),  INT8_C( 114) },
      {  INT8_C(  84), -INT8_C(  40),  INT8_C(  54), -INT8_C(  77),  INT8_C(  34), -INT8_C(   9),  INT8_C(  24),  INT8_C( 115),
         INT8_C(  25), -INT8_C( 117),  INT8_C(  91),  INT8_C(  37), -INT8_C(  57), -INT8_C( 111),  INT8_C(  40),  INT8_C( 112) },
      {  INT8_C(  83), -INT8_C(  40),  INT8_C(  54), -INT8_C(  75),  INT8_C(  34), -INT8_C(   9),  INT8_C(  24),  INT8_C( 114),
         INT8_C(  24), -INT8_C( 118),  INT8_C(  92),  INT8_C(  36), -INT8_C(  56), -INT8_C( 111),  INT8_C(  42),  INT8_C( 112) },
      {  INT8_C(  82), -INT8_C(  40),  INT8_C(  54), -INT8_C(  74),  INT8_C(  34), -INT8_C(   9),  INT8_C(  24),  INT8_C( 114),
         INT8_C(  24), -INT8_C( 119),  INT8_C(  93),  INT8_C(  35), -INT8_C(  56), -INT8_C( 111),  INT8_C(  43),  INT8_C( 112) } },
    { { -INT8_C(  44), -INT8_C(  65), -INT8_C(  51), -INT8_C(   9), -INT8_C(  73), -INT8_C(  25),  INT8_C( 105), -INT8_C(  49),
         INT8_C( 112), -INT8_C(  56), -INT8_C(  14),  INT8_C(  57),  INT8_C(  90),  INT8_C(  31), -INT8_C(  87), -INT8_C(  99) },
      {  INT8_C(  17), -INT8_C( 117),  INT8_C(  31),  INT8_C(   1), -INT8_C( 118),  INT8_C(  22),  INT8_C(  35), -INT8_C(  79),
         INT8_C(  99), -INT8_C(  48),  INT8_C(  16),  INT8_C(  39), -INT8_C(  54), -INT8_C( 105),  INT8_C(  61), -INT8_C(  98) },
      { -INT8_C(  36), -INT8_C( 124), -INT8_C(  36), -INT8_C(   9),  INT8_C( 124), -INT8_C(  14),  INT8_C( 122), -INT8_C(  89),
        -INT8_C(  95), -INT8_C(  80), -INT8_C(   6),  INT8_C(  76),  INT8_C(  63), -INT8_C(  22), -INT8_C(  57),  INT8_C( 108) },
      { -INT8_C(  42), -INT8_C(  80), -INT8_C(  48), -INT8_C(   9), -INT8_C(  88), -INT8_C(  23),  INT8_C( 109), -INT8_C(  59),
         INT8_C( 124), -INT8_C(  62), -INT8_C(  12),  INT8_C(  61),  INT8_C(  83),  INT8_C(  17), -INT8_C(  80), -INT8_C( 112) },
      { -INT8_C(  44), -INT8_C(  69), -INT8_C(  51), -INT8_C(   9), -INT8_C(  77), -INT8_C(  25),  INT8_C( 106), -INT8_C(  52),
         INT8_C( 115), -INT8_C(  58), -INT8_C(  14),  INT8_C(  58),  INT8_C(  88),  INT8_C(  27), -INT8_C(  86), -INT8_C( 103) },
      { -INT8_C(  44), -INT8_C(  67), -INT8_C(  51), -INT8_C(   9), -INT8_C(  75), -INT8_C(  25),  INT8_C( 105), -INT8_C(  51),
         INT8_C( 113), -INT8_C(  57), -INT8_C(  14),  INT8_C(  57),  INT8_C(  89),  INT8_C(  29), -INT8_C(  87), -INT8_C( 101) },
      { -INT8_C(  44), -INT8_C(  66), -INT8_C(  51), -INT8_C(   9), -INT8_C(  74), -INT8_C(  25),  INT8_C( 105), -INT8_C(  50),
         INT8_C( 112), -INT8_C(  57), -INT8_C(  14),  INT8_C(  57),  INT8_C(  89),  INT8_C(  30), -INT8_C(  87), -INT8_C( 100) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int8x16_t a = simde_vld1q_s8(test_vec[i].a);
    simde_int8x16_t b = simde_vld1q_s8(test_vec[i].b);

    simde_int8x16_t r1 = simde_vsraq_n_s8(a, b, 1);
    simde_int8x16_t r3 = simde_vsraq_n_s8(a, b, 3);
    simde_int8x16_t r5 = simde_vsraq_n_s8(a, b, 5);
    simde_int8x16_t r6 = simde_vsraq_n_s8(a, b, 6);
    simde_int8x16_t r8 = simde_vsraq_n_s8(a, b, 8);

    simde_test_arm_neon_assert_equal_i8x16(r1, simde_vld1q_s8(test_vec[i].r1));
    simde_test_arm_neon_assert_equal_i8x16(r3, simde_vld1q_s8(test_vec[i].r3));
    simde_test_arm_neon_assert_equal_i8x16(r5, simde_vld1q_s8(test_vec[i].r5));
    simde_test_arm_neon_assert_equal_i8x16(r6, simde_vld1q_s8(test_vec[i].r6));
    simde_test_arm_neon_assert_equal_i8x16(r8, simde_vld1q_s8(test_vec[i].r8));
  }

  return 0;
}

static int
test_simde_vsraq_n_s16 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    int16_t a[8];
    int16_t b[8];
    int16_t r3[8];
    int16_t r6[8];
    int16_t r10[8];
    int16_t r13[8];
    int16_t r16[8];
  } test_vec[] = {
    { {  INT16_C( 19770),  INT16_C( 15436), -INT16_C( 22964),  INT16_C( 18988),  INT16_C( 13523), -INT16_C( 16063), -INT16_C( 25309), -INT16_C(  5024) },
      {  INT16_C( 15790), -INT16_C( 31011), -INT16_C(  5854), -INT16_C( 25855),  INT16_C( 22081),  INT16_C( 11412), -INT16_C( 32023),  INT16_C(  9002) },
      {  INT16_C( 21743),  INT16_C( 11559), -INT16_C( 23696),  INT16_C( 15756),  INT16_C( 16283), -INT16_C( 14637), -INT16_C( 29312), -INT16_C(  3899) },
      {  INT16_C( 20016),  INT16_C( 14951), -INT16_C( 23056),  INT16_C( 18584),  INT16_C( 13868), -INT16_C( 15885), -INT16_C( 25810), -INT16_C(  4884) },
      {  INT16_C( 19785),  INT16_C( 15405), -INT16_C( 22970),  INT16_C( 18962),  INT16_C( 13544), -INT16_C( 16052), -INT16_C( 25341), -INT16_C(  5016) },
      {  INT16_C( 19771),  INT16_C( 15432), -INT16_C( 22965),  INT16_C( 18984),  INT16_C( 13525), -INT16_C( 16062), -INT16_C( 25313), -INT16_C(  5023) },
      {  INT16_C( 19770),  INT16_C( 15435), -INT16_C( 22965),  INT16_C( 18987),  INT16_C( 13523), -INT16_C( 16063), -INT16_C( 25310), -INT16_C(  5024) } },
    { {  INT16_C( 30671),  INT16_C(  7008), -INT16_C( 29667), -INT16_C(  3995), -INT16_C( 22848), -INT16_C(  6991),  INT16_C(  4419), -INT16_C(  3376) },
      { -INT16_C( 21169),  INT16_C( 29048),  INT16_C( 31126), -INT16_C( 10483), -INT16_C( 24112), -INT16_C( 18172),  INT16_C( 11812), -INT16_C(  3107) },
      {  INT16_C( 28024),  INT16_C( 10639), -INT16_C( 25777), -INT16_C(  5306), -INT16_C( 25862), -INT16_C(  9263),  INT16_C(  5895), -INT16_C(  3765) },
      {  INT16_C( 30340),  INT16_C(  7461), -INT16_C( 29181), -INT16_C(  4159), -INT16_C( 23225), -INT16_C(  7275),  INT16_C(  4603), -INT16_C(  3425) },
      {  INT16_C( 30650),  INT16_C(  7036), -INT16_C( 29637), -INT16_C(  4006), -INT16_C( 22872), -INT16_C(  7009),  INT16_C(  4430), -INT16_C(  3380) },
      {  INT16_C( 30668),  INT16_C(  7011), -INT16_C( 29664), -INT16_C(  3997), -INT16_C( 22851), -INT16_C(  6994),  INT16_C(  4420), -INT16_C(  3377) },
      {  INT16_C( 30670),  INT16_C(  7008), -INT16_C( 29667), -INT16_C(  3996), -INT16_C( 22849), -INT16_C(  6992),  INT16_C(  4419), -INT16_C(  3377) } },
    { {  INT16_C( 15781), -INT16_C( 15857),  INT16_C( 29897), -INT16_C( 30030),  INT16_C( 25627),  INT16_C( 24174),  INT16_C( 15989), -INT16_C( 15280) },
      { -INT16_C( 13845), -INT16_C( 32458),  INT16_C( 17218),  INT16_C(  4696),  INT16_C( 23780),  INT16_C(  2252), -INT16_C( 22133),  INT16_C( 12540) },
      {  INT16_C( 14050), -INT16_C( 19915),  INT16_C( 32049), -INT16_C( 29443),  INT16_C( 28599),  INT16_C( 24455),  INT16_C( 13222), -INT16_C( 13713) },
      {  INT16_C( 15564), -INT16_C( 16365),  INT16_C( 30166), -INT16_C( 29957),  INT16_C( 25998),  INT16_C( 24209),  INT16_C( 15643), -INT16_C( 15085) },
      {  INT16_C( 15767), -INT16_C( 15889),  INT16_C( 29913), -INT16_C( 30026),  INT16_C( 25650),  INT16_C( 24176),  INT16_C( 15967), -INT16_C( 15268) },
      {  INT16_C( 15779), -INT16_C( 15861),  INT16_C( 29899), -INT16_C( 30030),  INT16_C( 25629),  INT16_C( 24174),  INT16_C( 15986), -INT16_C( 15279) },
      {  INT16_C( 15780), -INT16_C( 15858),  INT16_C( 29897), -INT16_C( 30030),  INT16_C( 25627),  INT16_C( 24174),  INT16_C( 15988), -INT16_C( 15280) } },
    { {  INT16_C(  3046), -INT16_C( 20493), -INT16_C( 23169), -INT16_C( 26055), -INT16_C( 22775),  INT16_C( 32761),  INT16_C( 18917), -INT16_C( 12221) },
      {  INT16_C( 30994),  INT16_C( 21841), -INT16_C( 21828), -INT16_C( 24217),  INT16_C( 13062), -INT16_C( 28247), -INT16_C( 23076), -INT16_C( 15678) },
      {  INT16_C(  6920), -INT16_C( 17763), -INT16_C( 25898), -INT16_C( 29083), -INT16_C( 21143),  INT16_C( 29230),  INT16_C( 16032), -INT16_C( 14181) },
      {  INT16_C(  3530), -INT16_C( 20152), -INT16_C( 23511), -INT16_C( 26434), -INT16_C( 22571),  INT16_C( 32319),  INT16_C( 18556), -INT16_C( 12466) },
      {  INT16_C(  3076), -INT16_C( 20472), -INT16_C( 23191), -INT16_C( 26079), -INT16_C( 22763),  INT16_C( 32733),  INT16_C( 18894), -INT16_C( 12237) },
      {  INT16_C(  3049), -INT16_C( 20491), -INT16_C( 23172), -INT16_C( 26058), -INT16_C( 22774),  INT16_C( 32757),  INT16_C( 18914), -INT16_C( 12223) },
      {  INT16_C(  3046), -INT16_C( 20493), -INT16_C( 23170), -INT16_C( 26056), -INT16_C( 22775),  INT16_C( 32760),  INT16_C( 18916), -INT16_C( 12222) } },
    { { -INT16_C( 19024),  INT16_C( 12402), -INT16_C( 21670),  INT16_C( 25802), -INT16_C( 15533),  INT16_C( 14563),  INT16_C(  9741),  INT16_C(  7945) },
      {  INT16_C( 23200),  INT16_C( 23668), -INT16_C(  9212),  INT16_C(  3069), -INT16_C( 22769), -INT16_C(  4964),  INT16_C( 24140), -INT16_C(   594) },
      { -INT16_C( 16124),  INT16_C( 15360), -INT16_C( 22822),  INT16_C( 26185), -INT16_C( 18380),  INT16_C( 13942),  INT16_C( 12758),  INT16_C(  7870) },
      { -INT16_C( 18662),  INT16_C( 12771), -INT16_C( 21814),  INT16_C( 25849), -INT16_C( 15889),  INT16_C( 14485),  INT16_C( 10118),  INT16_C(  7935) },
      { -INT16_C( 19002),  INT16_C( 12425), -INT16_C( 21679),  INT16_C( 25804), -INT16_C( 15556),  INT16_C( 14558),  INT16_C(  9764),  INT16_C(  7944) },
      { -INT16_C( 19022),  INT16_C( 12404), -INT16_C( 21672),  INT16_C( 25802), -INT16_C( 15536),  INT16_C( 14562),  INT16_C(  9743),  INT16_C(  7944) },
      { -INT16_C( 19024),  INT16_C( 12402), -INT16_C( 21671),  INT16_C( 25802), -INT16_C( 15534),  INT16_C( 14562),  INT16_C(  9741),  INT16_C(  7944) } },
    { {  INT16_C(  8211),  INT16_C( 28205), -INT16_C(  2100),  INT16_C(  8146), -INT16_C( 19013), -INT16_C( 14249),  INT16_C( 24795),  INT16_C( 31719) },
      {  INT16_C( 23739), -INT16_C( 16424), -INT16_C( 10952),  INT16_C( 18378),  INT16_C( 26492), -INT16_C( 14029), -INT16_C(  7483), -INT16_C(  9786) },
      {  INT16_C( 11178),  INT16_C( 26152), -INT16_C(  3469),  INT16_C( 10443), -INT16_C( 15702), -INT16_C( 16003),  INT16_C( 23859),  INT16_C( 30495) },
      {  INT16_C(  8581),  INT16_C( 27948), -INT16_C(  2272),  INT16_C(  8433), -INT16_C( 18600), -INT16_C( 14469),  INT16_C( 24678),  INT16_C( 31566) },
      {  INT16_C(  8234),  INT16_C( 28188), -INT16_C(  2111),  INT16_C(  8163), -INT16_C( 18988), -INT16_C( 14263),  INT16_C( 24787),  INT16_C( 31709) },
      {  INT16_C(  8213),  INT16_C( 28202), -INT16_C(  2102),  INT16_C(  8148), -INT16_C( 19010), -INT16_C( 14251),  INT16_C( 24794),  INT16_C( 31717) },
      {  INT16_C(  8211),  INT16_C( 28204), -INT16_C(  2101),  INT16_C(  8146), -INT16_C( 19013), -INT16_C( 14250),  INT16_C( 24794),  INT16_C( 31718) } },
    { { -INT16_C(  3326), -INT16_C( 12729),  INT16_C(  6634), -INT16_C( 23059),  INT16_C( 17870), -INT16_C( 22163),  INT16_C( 21925),  INT16_C( 24613) },
      { -INT16_C(   591), -INT16_C(  5856), -INT16_C(  5422),  INT16_C( 20272),  INT16_C( 25681),  INT16_C(  5912), -INT16_C(  8634),  INT16_C( 18672) },
      { -INT16_C(  3400), -INT16_C( 13461),  INT16_C(  5956), -INT16_C( 20525),  INT16_C( 21080), -INT16_C( 21424),  INT16_C( 20845),  INT16_C( 26947) },
      { -INT16_C(  3336), -INT16_C( 12821),  INT16_C(  6549), -INT16_C( 22743),  INT16_C( 18271), -INT16_C( 22071),  INT16_C( 21790),  INT16_C( 24904) },
      { -INT16_C(  3327), -INT16_C( 12735),  INT16_C(  6628), -INT16_C( 23040),  INT16_C( 17895), -INT16_C( 22158),  INT16_C( 21916),  INT16_C( 24631) },
      { -INT16_C(  3327), -INT16_C( 12730),  INT16_C(  6633), -INT16_C( 23057),  INT16_C( 17873), -INT16_C( 22163),  INT16_C( 21923),  INT16_C( 24615) },
      { -INT16_C(  3327), -INT16_C( 12730),  INT16_C(  6633), -INT16_C( 23059),  INT16_C( 17870), -INT16_C( 22163),  INT16_C( 21924),  INT16_C( 24613) } },
    { {  INT16_C( 14289), -INT16_C( 17641),  INT16_C(  1104),  INT16_C(  7777), -INT16_C( 12727), -INT16_C(  4153), -INT16_C(  5085), -INT16_C( 11185) },
      {  INT16_C( 28649), -INT16_C( 17219), -INT16_C(  4518), -INT16_C( 21749),  INT16_C(  9042), -INT16_C( 26430), -INT16_C( 19967), -INT16_C( 11552) },
      {  INT16_C( 17870), -INT16_C( 19794),  INT16_C(   539),  INT16_C(  5058), -INT16_C( 11597), -INT16_C(  7457), -INT16_C(  7581), -INT16_C( 12629) },
      {  INT16_C( 14736), -INT16_C( 17911),  INT16_C(  1033),  INT16_C(  7437), -INT16_C( 12586), -INT16_C(  4566), -INT16_C(  5397), -INT16_C( 11366) },
      {  INT16_C( 14316), -INT16_C( 17658),  INT16_C(  1099),  INT16_C(  7755), -INT16_C( 12719), -INT16_C(  4179), -INT16_C(  5105), -INT16_C( 11197) },
      {  INT16_C( 14292), -INT16_C( 17644),  INT16_C(  1103),  INT16_C(  7774), -INT16_C( 12726), -INT16_C(  4157), -INT16_C(  5088), -INT16_C( 11187) },
      {  INT16_C( 14289), -INT16_C( 17642),  INT16_C(  1103),  INT16_C(  7776), -INT16_C( 12727), -INT16_C(  4154), -INT16_C(  5086), -INT16_C( 11186) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x8_t a = simde_vld1q_s16(test_vec[i].a);
    simde_int16x8_t b = simde_vld1q_s16(test_vec[i].b);

    simde_int16x8_t r3 = simde_vsraq_n_s16(a, b, 3);
    simde_int16x8_t r6 = simde_vsraq_n_s16(a, b, 6);
    simde_int16x8_t r10 = simde_vsraq_n_s16(a, b, 10);
    simde_int16x8_t r13 = simde_vsraq_n_s16(a, b, 13);
    simde_int16x8_t r16 = simde_vsraq_n_s16(a, b, 16);

    simde_test_arm_neon_assert_equal_i16x8(r3, simde_vld1q_s16(test_vec[i].r3));
    simde_test_arm_neon_assert_equal_i16x8(r6, simde_vld1q_s16(test_vec[i].r6));
    simde_test_arm_neon_assert_equal_i16x8(r10, simde_vld1q_s16(test_vec[i].r10));
    simde_test_arm_neon_assert_equal_i16x8(r13, simde_vld1q_s16(test_vec[i].r13));
    simde_test_arm_neon_assert_equal_i16x8(r16, simde_vld1q_s16(test_vec[i].r16));
  }

  return 0;
}

static int
test_simde_vsraq_n_s32 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    int32_t a[4];
    int32_t b[4];
    int32_t r6[4];
    int32_t r13[4];
    int32_t r19[4];
    int32_t r26[4];
    int32_t r32[4];
  } test_vec[] = {
    { { -INT32_C(  1161302666), -INT32_C(   522417114),  INT32_C(   348743160),  INT32_C(  1895160957) },
      { -INT32_C(  1197267636), -INT32_C(  1580672420),  INT32_C(  1226420721),  INT32_C(  1011036358) },
      { -INT32_C(  1180009973), -INT32_C(   547115121),  INT32_C(   367905983),  INT32_C(  1910958400) },
      { -INT32_C(  1161448817), -INT32_C(   522610068),  INT32_C(   348892869),  INT32_C(  1895284374) },
      { -INT32_C(  1161304950), -INT32_C(   522420129),  INT32_C(   348745499),  INT32_C(  1895162885) },
      { -INT32_C(  1161302684), -INT32_C(   522417138),  INT32_C(   348743178),  INT32_C(  1895160972) },
      { -INT32_C(  1161302667), -INT32_C(   522417115),  INT32_C(   348743160),  INT32_C(  1895160957) } },
    { {  INT32_C(  1140198173), -INT32_C(  1893477481), -INT32_C(  1230771144),  INT32_C(   354851016) },
      {  INT32_C(   432916925), -INT32_C(  1782933852),  INT32_C(   232707143),  INT32_C(   558506500) },
      {  INT32_C(  1146962499), -INT32_C(  1921335823), -INT32_C(  1227135095),  INT32_C(   363577680) },
      {  INT32_C(  1140251019), -INT32_C(  1893695125), -INT32_C(  1230742738),  INT32_C(   354919193) },
      {  INT32_C(  1140198998), -INT32_C(  1893480882), -INT32_C(  1230770701),  INT32_C(   354852081) },
      {  INT32_C(  1140198179), -INT32_C(  1893477508), -INT32_C(  1230771141),  INT32_C(   354851024) },
      {  INT32_C(  1140198173), -INT32_C(  1893477482), -INT32_C(  1230771144),  INT32_C(   354851016) } },
    { { -INT32_C(   999997395),  INT32_C(  1280608275),  INT32_C(  1023604597),  INT32_C(  1297229968) },
      { -INT32_C(  1771626254), -INT32_C(    47504970), -INT32_C(   116716811),  INT32_C(  1494963500) },
      { -INT32_C(  1027679056),  INT32_C(  1279866009),  INT32_C(  1021780896),  INT32_C(  1320588772) },
      { -INT32_C(  1000213658),  INT32_C(  1280602476),  INT32_C(  1023590349),  INT32_C(  1297412458) },
      { -INT32_C(  1000000775),  INT32_C(  1280608184),  INT32_C(  1023604374),  INT32_C(  1297232819) },
      { -INT32_C(   999997422),  INT32_C(  1280608274),  INT32_C(  1023604595),  INT32_C(  1297229990) },
      { -INT32_C(   999997396),  INT32_C(  1280608274),  INT32_C(  1023604596),  INT32_C(  1297229968) } },
    { { -INT32_C(  1457684331),  INT32_C(  2113237256), -INT32_C(   105121943),  INT32_C(   289803551) },
      { -INT32_C(   475550419), -INT32_C(   991833137),  INT32_C(   163507421), -INT32_C(   698164927) },
      { -INT32_C(  1465114807),  INT32_C(  2097739863), -INT32_C(   102567140),  INT32_C(   278894724) },
      { -INT32_C(  1457742382),  INT32_C(  2113116182), -INT32_C(   105101984),  INT32_C(   289718325) },
      { -INT32_C(  1457685239),  INT32_C(  2113235364), -INT32_C(   105121632),  INT32_C(   289802219) },
      { -INT32_C(  1457684339),  INT32_C(  2113237241), -INT32_C(   105121941),  INT32_C(   289803540) },
      { -INT32_C(  1457684332),  INT32_C(  2113237255), -INT32_C(   105121943),  INT32_C(   289803550) } },
    { {  INT32_C(  1635745625),  INT32_C(  1524593905), -INT32_C(  1957455253), -INT32_C(   711157337) },
      {  INT32_C(   381174855), -INT32_C(   187000553), -INT32_C(   956458875), -INT32_C(   895656079) },
      {  INT32_C(  1641701482),  INT32_C(  1521672021), -INT32_C(  1972399923), -INT32_C(   725151964) },
      {  INT32_C(  1635792155),  INT32_C(  1524571077), -INT32_C(  1957572009), -INT32_C(   711266671) },
      {  INT32_C(  1635746352),  INT32_C(  1524593548), -INT32_C(  1957457078), -INT32_C(   711159046) },
      {  INT32_C(  1635745630),  INT32_C(  1524593902), -INT32_C(  1957455268), -INT32_C(   711157351) },
      {  INT32_C(  1635745625),  INT32_C(  1524593904), -INT32_C(  1957455254), -INT32_C(   711157338) } },
    { { -INT32_C(   819192610), -INT32_C(    64418927),  INT32_C(  1283947685),  INT32_C(  1562453014) },
      {  INT32_C(  2138298984), -INT32_C(   109884045),  INT32_C(  1472164070), -INT32_C(  1390256945) },
      { -INT32_C(   785781689), -INT32_C(    66135866),  INT32_C(  1306950248),  INT32_C(  1540730249) },
      { -INT32_C(   818931588), -INT32_C(    64432341),  INT32_C(  1284127392),  INT32_C(  1562283304) },
      { -INT32_C(   819188532), -INT32_C(    64419137),  INT32_C(  1283950492),  INT32_C(  1562450362) },
      { -INT32_C(   819192579), -INT32_C(    64418929),  INT32_C(  1283947706),  INT32_C(  1562452993) },
      { -INT32_C(   819192610), -INT32_C(    64418928),  INT32_C(  1283947685),  INT32_C(  1562453013) } },
    { {  INT32_C(   175984249), -INT32_C(    33118631),  INT32_C(   961187363),  INT32_C(   446065842) },
      { -INT32_C(  1181152954),  INT32_C(  1018301526),  INT32_C(  1268019836),  INT32_C(  1207482062) },
      {  INT32_C(   157528734), -INT32_C(    17207670),  INT32_C(   981000172),  INT32_C(   464932749) },
      {  INT32_C(   175840065), -INT32_C(    32994327),  INT32_C(   961342150),  INT32_C(   446213239) },
      {  INT32_C(   175981996), -INT32_C(    33116689),  INT32_C(   961189781),  INT32_C(   446068145) },
      {  INT32_C(   175984231), -INT32_C(    33118616),  INT32_C(   961187381),  INT32_C(   446065859) },
      {  INT32_C(   175984248), -INT32_C(    33118631),  INT32_C(   961187363),  INT32_C(   446065842) } },
    { {  INT32_C(  1565619460),  INT32_C(  1062950940), -INT32_C(  1736923674),  INT32_C(  1471286801) },
      {  INT32_C(  1829849879), -INT32_C(   743783593),  INT32_C(    69090869), -INT32_C(   129296652) },
      {  INT32_C(  1594210864),  INT32_C(  1051329321), -INT32_C(  1735844130),  INT32_C(  1469266540) },
      {  INT32_C(  1565842830),  INT32_C(  1062860146), -INT32_C(  1736915241),  INT32_C(  1471271017) },
      {  INT32_C(  1565622950),  INT32_C(  1062949521), -INT32_C(  1736923543),  INT32_C(  1471286554) },
      {  INT32_C(  1565619487),  INT32_C(  1062950928), -INT32_C(  1736923673),  INT32_C(  1471286799) },
      {  INT32_C(  1565619460),  INT32_C(  1062950939), -INT32_C(  1736923674),  INT32_C(  1471286800) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x4_t a = simde_vld1q_s32(test_vec[i].a);
    simde_int32x4_t b = simde_vld1q_s32(test_vec[i].b);

    simde_int32x4_t r6 = simde_vsraq_n_s32(a, b, 6);
    simde_int32x4_t r13 = simde_vsraq_n_s32(a, b, 13);
    simde_int32x4_t r19 = simde_vsraq_n_s32(a, b, 19);
    simde_int32x4_t r26 = simde_vsraq_n_s32(a, b, 26);
    simde_int32x4_t r32 = simde_vsraq_n_s32(a, b, 32);

    simde_test_arm_neon_assert_equal_i32x4(r6, simde_vld1q_s32(test_vec[i].r6));
    simde_test_arm_neon_assert_equal_i32x4(r13, simde_vld1q_s32(test_vec[i].r13));
    simde_test_arm_neon_assert_equal_i32x4(r19, simde_vld1q_s32(test_vec[i].r19));
    simde_test_arm_neon_assert_equal_i32x4(r26, simde_vld1q_s32(test_vec[i].r26));
    simde_test_arm_neon_assert_equal_i32x4(r32, simde_vld1q_s32(test_vec[i].r32));
  }

  return 0;
}

static int
test_simde_vsraq_n_s64 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    int64_t a[2];
    int64_t b[2];
    int64_t r13[2];
    int64_t r26[2];
    int64_t r39[2];
    int64_t r52[2];
    int64_t r64[2];
  } test_vec[] = {
    { { -INT64_C( 1487247765215587762), -INT64_C( 2795427882804660423) },
      { -INT64_C( 6291787764080571768), -INT64_C( 9040106312942818602) },
      { -INT64_C( 1488015805714132754), -INT64_C( 2796531411407314576) },
      { -INT64_C( 1487247858970531433), -INT64_C( 2795428017512741802) },
      { -INT64_C( 1487247765227032458), -INT64_C( 2795427882821104281) },
      { -INT64_C( 1487247765215589160), -INT64_C( 2795427882804662431) },
      { -INT64_C( 1487247765215587763), -INT64_C( 2795427882804660424) } },
    { {  INT64_C( 6187220334653006057),  INT64_C( 4549844769850200356) },
      { -INT64_C( 2064032859925579690), -INT64_C( 6793991508038475265) },
      {  INT64_C( 6186968377516784672),  INT64_C( 4549015425183691753) },
      {  INT64_C( 6187220303896519701),  INT64_C( 4549844668611837745) },
      {  INT64_C( 6187220334649251603),  INT64_C( 4549844769837842157) },
      {  INT64_C( 6187220334653005598),  INT64_C( 4549844769850198847) },
      {  INT64_C( 6187220334653006056),  INT64_C( 4549844769850200355) } },
    { {  INT64_C( 6284333698155529924), -INT64_C( 1191266314545443454) },
      { -INT64_C(  959831922041496130), -INT64_C( 5838954393325140322) },
      {  INT64_C( 6284216531172858842), -INT64_C( 1191979077532909902) },
      {  INT64_C( 6284333683852919734), -INT64_C( 1191266401552644073) },
      {  INT64_C( 6284333698153783999), -INT64_C( 1191266314556064451) },
      {  INT64_C( 6284333698155529710), -INT64_C( 1191266314545444751) },
      {  INT64_C( 6284333698155529923), -INT64_C( 1191266314545443455) } },
    { {  INT64_C( 8948024616275577507),  INT64_C( 5952118874571132690) },
      { -INT64_C( 2886866485712700406), -INT64_C( 7608790941223282992) },
      {  INT64_C( 8947672215581520780),  INT64_C( 5951190067083190394) },
      {  INT64_C( 8948024573257914658),  INT64_C( 5952118761191312384) },
      {  INT64_C( 8948024616270326327),  INT64_C( 5952118874557292379) },
      {  INT64_C( 8948024616275576865),  INT64_C( 5952118874571131000) },
      {  INT64_C( 8948024616275577506),  INT64_C( 5952118874571132689) } },
    { { -INT64_C( 3664352591020689490),  INT64_C( 1175459323992136297) },
      {  INT64_C(  603197819340025166),  INT64_C( 6745314372626909971) },
      { -INT64_C( 3664278958474383335),  INT64_C( 1176282726625513605) },
      { -INT64_C( 3664352582032341553),  INT64_C( 1175459424505153066) },
      { -INT64_C( 3664352591019592280),  INT64_C( 1175459324004405952) },
      { -INT64_C( 3664352591020689357),  INT64_C( 1175459323992137794) },
      { -INT64_C( 3664352591020689490),  INT64_C( 1175459323992136297) } },
    { {  INT64_C(  984928930610153762), -INT64_C( 8855101380133968891) },
      {  INT64_C( 4110215420899502537),  INT64_C( 1946642424453385718) },
      {  INT64_C(  985430665891025283), -INT64_C( 8854863752884890109) },
      {  INT64_C(  984928991857136290), -INT64_C( 8855101351126736338) },
      {  INT64_C(  984928930617630200), -INT64_C( 8855101380130427970) },
      {  INT64_C(  984928930610154674), -INT64_C( 8855101380133968459) },
      {  INT64_C(  984928930610153762), -INT64_C( 8855101380133968891) } },
    { {  INT64_C( 4149966127205255653), -INT64_C( 3997962821365816632) },
      { -INT64_C(  942708094007668598), -INT64_C( 1462373526339573088) },
      {  INT64_C( 4149851050533623857), -INT64_C( 3998141333759168631) },
      {  INT64_C( 4149966113157810385), -INT64_C( 3997962843156880274) },
      {  INT64_C( 4149966127203540876), -INT64_C( 3997962821368476674) },
      {  INT64_C( 4149966127205255443), -INT64_C( 3997962821365816957) },
      {  INT64_C( 4149966127205255652), -INT64_C( 3997962821365816633) } },
    { {  INT64_C( 1878859015223881125),  INT64_C( 4860964793614948526) },
      { -INT64_C( 5612647241480913363), -INT64_C(  866099267586247927) },
      {  INT64_C( 1878173877621161286),  INT64_C( 4860859068606698251) },
      {  INT64_C( 1878858931588919855),  INT64_C( 4860964780709063729) },
      {  INT64_C( 1878859015213671779),  INT64_C( 4860964793613373100) },
      {  INT64_C( 1878859015223879878),  INT64_C( 4860964793614948333) },
      {  INT64_C( 1878859015223881124),  INT64_C( 4860964793614948525) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int64x2_t a = simde_vld1q_s64(test_vec[i].a);
    simde_int64x2_t b = simde_vld1q_s64(test_vec[i].b);

    simde_int64x2_t r13 = simde_vsraq_n_s64(a, b, 13);
    simde_int64x2_t r26 = simde_vsraq_n_s64(a, b, 26);
    simde_int64x2_t r39 = simde_vsraq_n_s64(a, b, 39);
    simde_int64x2_t r52 = simde_vsraq_n_s64(a, b, 52);
    simde_int64x2_t r64 = simde_vsraq_n_s64(a, b, 64);

    simde_test_arm_neon_assert_equal_i64x2(r13, simde_vld1q_s64(test_vec[i].r13));
    simde_test_arm_neon_assert_equal_i64x2(r26, simde_vld1q_s64(test_vec[i].r26));
    simde_test_arm_neon_assert_equal_i64x2(r39, simde_vld1q_s64(test_vec[i].r39));
    simde_test_arm_neon_assert_equal_i64x2(r52, simde_vld1q_s64(test_vec[i].r52));
    simde_test_arm_neon_assert_equal_i64x2(r64, simde_vld1q_s64(test_vec[i].r64));
  }

  return 0;
}

static int
test_simde_vsraq_n_u8 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    uint8_t a[16];
    uint8_t b[16];
    uint8_t r1[16];
    uint8_t r3[16];
    uint8_t r5[16];
    uint8_t r6[16];
    uint8_t r8[16];
  } test_vec[] = {
    { { UINT8_C(207), UINT8_C(199), UINT8_C(161), UINT8_C(  7), UINT8_C( 24), UINT8_C(229), UINT8_C(  6), UINT8_C(223),
        UINT8_C( 93), UINT8_C( 54), UINT8_C( 83), UINT8_C( 89), UINT8_C( 94), UINT8_C(134), UINT8_C(165), UINT8_C(240) },
      { UINT8_C(171), UINT8_C(176), UINT8_C( 43), UINT8_C( 82), UINT8_C(162), UINT8_C(176), UINT8_C(226), UINT8_C(136),
        UINT8_C(199), UINT8_C(117),    UINT8_MAX, UINT8_C(140), UINT8_C( 70), UINT8_C(104), UINT8_C(145), UINT8_C( 22) },
      { UINT8_C( 36), UINT8_C( 31), UINT8_C(182), UINT8_C( 48), UINT8_C(105), UINT8_C( 61), UINT8_C(119), UINT8_C( 35),
        UINT8_C(192), UINT8_C(112), UINT8_C(210), UINT8_C(159), UINT8_C(129), UINT8_C(186), UINT8_C(237), UINT8_C(251) },
      { UINT8_C(228), UINT8_C(221), UINT8_C(166), UINT8_C( 17), UINT8_C( 44), UINT8_C(251), UINT8_C( 34), UINT8_C(240),
        UINT8_C(117), UINT8_C( 68), UINT8_C(114), UINT8_C(106), UINT8_C(102), UINT8_C(147), UINT8_C(183), UINT8_C(242) },
      { UINT8_C(212), UINT8_C(204), UINT8_C(162), UINT8_C(  9), UINT8_C( 29), UINT8_C(234), UINT8_C( 13), UINT8_C(227),
        UINT8_C( 99), UINT8_C( 57), UINT8_C( 90), UINT8_C( 93), UINT8_C( 96), UINT8_C(137), UINT8_C(169), UINT8_C(240) },
      { UINT8_C(209), UINT8_C(201), UINT8_C(161), UINT8_C(  8), UINT8_C( 26), UINT8_C(231), UINT8_C(  9), UINT8_C(225),
        UINT8_C( 96), UINT8_C( 55), UINT8_C( 86), UINT8_C( 91), UINT8_C( 95), UINT8_C(135), UINT8_C(167), UINT8_C(240) },
      { UINT8_C(207), UINT8_C(199), UINT8_C(161), UINT8_C(  7), UINT8_C( 24), UINT8_C(229), UINT8_C(  6), UINT8_C(223),
        UINT8_C( 93), UINT8_C( 54), UINT8_C( 83), UINT8_C( 89), UINT8_C( 94), UINT8_C(134), UINT8_C(165), UINT8_C(240) } },
    { { UINT8_C( 47), UINT8_C( 50), UINT8_C( 29), UINT8_C( 71), UINT8_C( 24), UINT8_C( 35), UINT8_C( 38), UINT8_C(117),
        UINT8_C( 90), UINT8_C(121), UINT8_C(206), UINT8_C(184),    UINT8_MAX, UINT8_C(116), UINT8_C(168), UINT8_C(171) },
      { UINT8_C( 36), UINT8_C(211), UINT8_C(253), UINT8_C(199), UINT8_C(132), UINT8_C(224), UINT8_C( 79), UINT8_C( 75),
        UINT8_C( 85), UINT8_C( 78), UINT8_C(215), UINT8_C(156), UINT8_C(182), UINT8_C(104), UINT8_C(178), UINT8_C(229) },
      { UINT8_C( 65), UINT8_C(155), UINT8_C(155), UINT8_C(170), UINT8_C( 90), UINT8_C(147), UINT8_C( 77), UINT8_C(154),
        UINT8_C(132), UINT8_C(160), UINT8_C( 57), UINT8_C(  6), UINT8_C( 90), UINT8_C(168), UINT8_C(  1), UINT8_C( 29) },
      { UINT8_C( 51), UINT8_C( 76), UINT8_C( 60), UINT8_C( 95), UINT8_C( 40), UINT8_C( 63), UINT8_C( 47), UINT8_C(126),
        UINT8_C(100), UINT8_C(130), UINT8_C(232), UINT8_C(203), UINT8_C( 21), UINT8_C(129), UINT8_C(190), UINT8_C(199) },
      { UINT8_C( 48), UINT8_C( 56), UINT8_C( 36), UINT8_C( 77), UINT8_C( 28), UINT8_C( 42), UINT8_C( 40), UINT8_C(119),
        UINT8_C( 92), UINT8_C(123), UINT8_C(212), UINT8_C(188), UINT8_C(  4), UINT8_C(119), UINT8_C(173), UINT8_C(178) },
      { UINT8_C( 47), UINT8_C( 53), UINT8_C( 32), UINT8_C( 74), UINT8_C( 26), UINT8_C( 38), UINT8_C( 39), UINT8_C(118),
        UINT8_C( 91), UINT8_C(122), UINT8_C(209), UINT8_C(186), UINT8_C(  1), UINT8_C(117), UINT8_C(170), UINT8_C(174) },
      { UINT8_C( 47), UINT8_C( 50), UINT8_C( 29), UINT8_C( 71), UINT8_C( 24), UINT8_C( 35), UINT8_C( 38), UINT8_C(117),
        UINT8_C( 90), UINT8_C(121), UINT8_C(206), UINT8_C(184),    UINT8_MAX, UINT8_C(116), UINT8_C(168), UINT8_C(171) } },
    { { UINT8_C(155), UINT8_C(207), UINT8_C( 44), UINT8_C(179), UINT8_C(243), UINT8_C( 82), UINT8_C( 40), UINT8_C( 77),
        UINT8_C(204), UINT8_C(247), UINT8_C(  5), UINT8_C(203), UINT8_C(107), UINT8_C(173), UINT8_C(118), UINT8_C(143) },
      { UINT8_C(129), UINT8_C(116), UINT8_C( 86), UINT8_C(  5), UINT8_C( 84), UINT8_C(165), UINT8_C( 80), UINT8_C(169),
        UINT8_C(244), UINT8_C( 39), UINT8_C( 69), UINT8_C(170), UINT8_C(144), UINT8_C(247), UINT8_C(144), UINT8_C( 43) },
      { UINT8_C(219), UINT8_C(  9), UINT8_C( 87), UINT8_C(181), UINT8_C( 29), UINT8_C(164), UINT8_C( 80), UINT8_C(161),
        UINT8_C( 70), UINT8_C( 10), UINT8_C( 39), UINT8_C( 32), UINT8_C(179), UINT8_C( 40), UINT8_C(190), UINT8_C(164) },
      { UINT8_C(171), UINT8_C(221), UINT8_C( 54), UINT8_C(179), UINT8_C(253), UINT8_C(102), UINT8_C( 50), UINT8_C( 98),
        UINT8_C(234), UINT8_C(251), UINT8_C( 13), UINT8_C(224), UINT8_C(125), UINT8_C(203), UINT8_C(136), UINT8_C(148) },
      { UINT8_C(159), UINT8_C(210), UINT8_C( 46), UINT8_C(179), UINT8_C(245), UINT8_C( 87), UINT8_C( 42), UINT8_C( 82),
        UINT8_C(211), UINT8_C(248), UINT8_C(  7), UINT8_C(208), UINT8_C(111), UINT8_C(180), UINT8_C(122), UINT8_C(144) },
      { UINT8_C(157), UINT8_C(208), UINT8_C( 45), UINT8_C(179), UINT8_C(244), UINT8_C( 84), UINT8_C( 41), UINT8_C( 79),
        UINT8_C(207), UINT8_C(247), UINT8_C(  6), UINT8_C(205), UINT8_C(109), UINT8_C(176), UINT8_C(120), UINT8_C(143) },
      { UINT8_C(155), UINT8_C(207), UINT8_C( 44), UINT8_C(179), UINT8_C(243), UINT8_C( 82), UINT8_C( 40), UINT8_C( 77),
        UINT8_C(204), UINT8_C(247), UINT8_C(  5), UINT8_C(203), UINT8_C(107), UINT8_C(173), UINT8_C(118), UINT8_C(143) } },
    { { UINT8_C(199), UINT8_C(188), UINT8_C(222), UINT8_C(186), UINT8_C( 15), UINT8_C(  6), UINT8_C(  7), UINT8_C(219),
        UINT8_C(253), UINT8_C( 12), UINT8_C(166), UINT8_C(104), UINT8_C(185), UINT8_C( 29), UINT8_C(248), UINT8_C( 58) },
      { UINT8_C(145), UINT8_C( 78), UINT8_C( 63), UINT8_C(229), UINT8_C(244), UINT8_C(143), UINT8_C(142), UINT8_C(232),
        UINT8_C(183), UINT8_C(212), UINT8_C(146), UINT8_C( 71), UINT8_C(203), UINT8_C( 34), UINT8_C(114), UINT8_C(146) },
      { UINT8_C( 15), UINT8_C(227), UINT8_C(253), UINT8_C( 44), UINT8_C(137), UINT8_C( 77), UINT8_C( 78), UINT8_C( 79),
        UINT8_C( 88), UINT8_C(118), UINT8_C(239), UINT8_C(139), UINT8_C( 30), UINT8_C( 46), UINT8_C( 49), UINT8_C(131) },
      { UINT8_C(217), UINT8_C(197), UINT8_C(229), UINT8_C(214), UINT8_C( 45), UINT8_C( 23), UINT8_C( 24), UINT8_C(248),
        UINT8_C( 19), UINT8_C( 38), UINT8_C(184), UINT8_C(112), UINT8_C(210), UINT8_C( 33), UINT8_C(  6), UINT8_C( 76) },
      { UINT8_C(203), UINT8_C(190), UINT8_C(223), UINT8_C(193), UINT8_C( 22), UINT8_C( 10), UINT8_C( 11), UINT8_C(226),
        UINT8_C(  2), UINT8_C( 18), UINT8_C(170), UINT8_C(106), UINT8_C(191), UINT8_C( 30), UINT8_C(251), UINT8_C( 62) },
      { UINT8_C(201), UINT8_C(189), UINT8_C(222), UINT8_C(189), UINT8_C( 18), UINT8_C(  8), UINT8_C(  9), UINT8_C(222),
           UINT8_MAX, UINT8_C( 15), UINT8_C(168), UINT8_C(105), UINT8_C(188), UINT8_C( 29), UINT8_C(249), UINT8_C( 60) },
      { UINT8_C(199), UINT8_C(188), UINT8_C(222), UINT8_C(186), UINT8_C( 15), UINT8_C(  6), UINT8_C(  7), UINT8_C(219),
        UINT8_C(253), UINT8_C( 12), UINT8_C(166), UINT8_C(104), UINT8_C(185), UINT8_C( 29), UINT8_C(248), UINT8_C( 58) } },
    { { UINT8_C(223), UINT8_C( 80), UINT8_C( 76), UINT8_C(238), UINT8_C( 86), UINT8_C( 83), UINT8_C(201), UINT8_C( 84),
        UINT8_C( 95), UINT8_C(111), UINT8_C(188), UINT8_C( 25), UINT8_C(140), UINT8_C(180), UINT8_C( 83), UINT8_C( 29) },
      { UINT8_C(  3), UINT8_C(147), UINT8_C(  2), UINT8_C(247), UINT8_C( 34), UINT8_C(145), UINT8_C(223), UINT8_C(217),
        UINT8_C(101), UINT8_C(113), UINT8_C( 32), UINT8_C( 48), UINT8_C(148), UINT8_C(146), UINT8_C(195), UINT8_C(115) },
      { UINT8_C(224), UINT8_C(153), UINT8_C( 77), UINT8_C(105), UINT8_C(103), UINT8_C(155), UINT8_C( 56), UINT8_C(192),
        UINT8_C(145), UINT8_C(167), UINT8_C(204), UINT8_C( 49), UINT8_C(214), UINT8_C(253), UINT8_C(180), UINT8_C( 86) },
      { UINT8_C(223), UINT8_C( 98), UINT8_C( 76), UINT8_C( 12), UINT8_C( 90), UINT8_C(101), UINT8_C(228), UINT8_C(111),
        UINT8_C(107), UINT8_C(125), UINT8_C(192), UINT8_C( 31), UINT8_C(158), UINT8_C(198), UINT8_C(107), UINT8_C( 43) },
      { UINT8_C(223), UINT8_C( 84), UINT8_C( 76), UINT8_C(245), UINT8_C( 87), UINT8_C( 87), UINT8_C(207), UINT8_C( 90),
        UINT8_C( 98), UINT8_C(114), UINT8_C(189), UINT8_C( 26), UINT8_C(144), UINT8_C(184), UINT8_C( 89), UINT8_C( 32) },
      { UINT8_C(223), UINT8_C( 82), UINT8_C( 76), UINT8_C(241), UINT8_C( 86), UINT8_C( 85), UINT8_C(204), UINT8_C( 87),
        UINT8_C( 96), UINT8_C(112), UINT8_C(188), UINT8_C( 25), UINT8_C(142), UINT8_C(182), UINT8_C( 86), UINT8_C( 30) },
      { UINT8_C(223), UINT8_C( 80), UINT8_C( 76), UINT8_C(238), UINT8_C( 86), UINT8_C( 83), UINT8_C(201), UINT8_C( 84),
        UINT8_C( 95), UINT8_C(111), UINT8_C(188), UINT8_C( 25), UINT8_C(140), UINT8_C(180), UINT8_C( 83), UINT8_C( 29) } },
    { { UINT8_C(226), UINT8_C( 15), UINT8_C( 97), UINT8_C( 57), UINT8_C( 99), UINT8_C( 42), UINT8_C(141), UINT8_C(194),
        UINT8_C(153), UINT8_C( 73), UINT8_C(219), UINT8_C( 38), UINT8_C(254), UINT8_C( 47), UINT8_C( 67), UINT8_C(  1) },
      { UINT8_C(194), UINT8_C( 70), UINT8_C(248), UINT8_C(228), UINT8_C(215), UINT8_C(215), UINT8_C(190), UINT8_C( 60),
        UINT8_C( 72), UINT8_C(222), UINT8_C(108), UINT8_C(220), UINT8_C(113), UINT8_C( 47), UINT8_C( 79), UINT8_C( 83) },
      { UINT8_C( 67), UINT8_C( 50), UINT8_C(221), UINT8_C(171), UINT8_C(206), UINT8_C(149), UINT8_C(236), UINT8_C(224),
        UINT8_C(189), UINT8_C(184), UINT8_C( 17), UINT8_C(148), UINT8_C( 54), UINT8_C( 70), UINT8_C(106), UINT8_C( 42) },
      { UINT8_C(250), UINT8_C( 23), UINT8_C(128), UINT8_C( 85), UINT8_C(125), UINT8_C( 68), UINT8_C(164), UINT8_C(201),
        UINT8_C(162), UINT8_C(100), UINT8_C(232), UINT8_C( 65), UINT8_C( 12), UINT8_C( 52), UINT8_C( 76), UINT8_C( 11) },
      { UINT8_C(232), UINT8_C( 17), UINT8_C(104), UINT8_C( 64), UINT8_C(105), UINT8_C( 48), UINT8_C(146), UINT8_C(195),
        UINT8_C(155), UINT8_C( 79), UINT8_C(222), UINT8_C( 44), UINT8_C(  1), UINT8_C( 48), UINT8_C( 69), UINT8_C(  3) },
      { UINT8_C(229), UINT8_C( 16), UINT8_C(100), UINT8_C( 60), UINT8_C(102), UINT8_C( 45), UINT8_C(143), UINT8_C(194),
        UINT8_C(154), UINT8_C( 76), UINT8_C(220), UINT8_C( 41),    UINT8_MAX, UINT8_C( 47), UINT8_C( 68), UINT8_C(  2) },
      { UINT8_C(226), UINT8_C( 15), UINT8_C( 97), UINT8_C( 57), UINT8_C( 99), UINT8_C( 42), UINT8_C(141), UINT8_C(194),
        UINT8_C(153), UINT8_C( 73), UINT8_C(219), UINT8_C( 38), UINT8_C(254), UINT8_C( 47), UINT8_C( 67), UINT8_C(  1) } },
    { { UINT8_C( 63), UINT8_C(176), UINT8_C(140), UINT8_C(162), UINT8_C(218), UINT8_C( 25), UINT8_C(100), UINT8_C(116),
        UINT8_C( 99), UINT8_C( 64), UINT8_C(154), UINT8_C( 97), UINT8_C(111), UINT8_C(221), UINT8_C( 98), UINT8_C( 49) },
      { UINT8_C( 35), UINT8_C( 90), UINT8_C( 21), UINT8_C(250), UINT8_C( 49), UINT8_C(211), UINT8_C( 54), UINT8_C(121),
        UINT8_C(178), UINT8_C(163), UINT8_C( 86), UINT8_C( 35), UINT8_C(210), UINT8_C(165), UINT8_C(118), UINT8_C( 17) },
      { UINT8_C( 80), UINT8_C(221), UINT8_C(150), UINT8_C( 31), UINT8_C(242), UINT8_C(130), UINT8_C(127), UINT8_C(176),
        UINT8_C(188), UINT8_C(145), UINT8_C(197), UINT8_C(114), UINT8_C(216), UINT8_C( 47), UINT8_C(157), UINT8_C( 57) },
      { UINT8_C( 67), UINT8_C(187), UINT8_C(142), UINT8_C(193), UINT8_C(224), UINT8_C( 51), UINT8_C(106), UINT8_C(131),
        UINT8_C(121), UINT8_C( 84), UINT8_C(164), UINT8_C(101), UINT8_C(137), UINT8_C(241), UINT8_C(112), UINT8_C( 51) },
      { UINT8_C( 64), UINT8_C(178), UINT8_C(140), UINT8_C(169), UINT8_C(219), UINT8_C( 31), UINT8_C(101), UINT8_C(119),
        UINT8_C(104), UINT8_C( 69), UINT8_C(156), UINT8_C( 98), UINT8_C(117), UINT8_C(226), UINT8_C(101), UINT8_C( 49) },
      { UINT8_C( 63), UINT8_C(177), UINT8_C(140), UINT8_C(165), UINT8_C(218), UINT8_C( 28), UINT8_C(100), UINT8_C(117),
        UINT8_C(101), UINT8_C( 66), UINT8_C(155), UINT8_C( 97), UINT8_C(114), UINT8_C(223), UINT8_C( 99), UINT8_C( 49) },
      { UINT8_C( 63), UINT8_C(176), UINT8_C(140), UINT8_C(162), UINT8_C(218), UINT8_C( 25), UINT8_C(100), UINT8_C(116),
        UINT8_C( 99), UINT8_C( 64), UINT8_C(154), UINT8_C( 97), UINT8_C(111), UINT8_C(221), UINT8_C( 98), UINT8_C( 49) } },
    { { UINT8_C( 86), UINT8_C(  3), UINT8_C(179), UINT8_C( 48), UINT8_C( 28), UINT8_C( 24), UINT8_C(164), UINT8_C(127),
        UINT8_C( 88), UINT8_C( 62), UINT8_C(224), UINT8_C(199), UINT8_C( 28), UINT8_C( 66), UINT8_C(248), UINT8_C( 63) },
      { UINT8_C(156), UINT8_C( 13), UINT8_C( 58), UINT8_C(205), UINT8_C(225), UINT8_C(112), UINT8_C( 71), UINT8_C(147),
        UINT8_C( 19), UINT8_C(157), UINT8_C(182), UINT8_C(230), UINT8_C( 66), UINT8_C( 44), UINT8_C(247), UINT8_C(152) },
      { UINT8_C(164), UINT8_C(  9), UINT8_C(208), UINT8_C(150), UINT8_C(140), UINT8_C( 80), UINT8_C(199), UINT8_C(200),
        UINT8_C( 97), UINT8_C(140), UINT8_C( 59), UINT8_C( 58), UINT8_C( 61), UINT8_C( 88), UINT8_C(115), UINT8_C(139) },
      { UINT8_C(105), UINT8_C(  4), UINT8_C(186), UINT8_C( 73), UINT8_C( 56), UINT8_C( 38), UINT8_C(172), UINT8_C(145),
        UINT8_C( 90), UINT8_C( 81), UINT8_C(246), UINT8_C(227), UINT8_C( 36), UINT8_C( 71), UINT8_C( 22), UINT8_C( 82) },
      { UINT8_C( 90), UINT8_C(  3), UINT8_C(180), UINT8_C( 54), UINT8_C( 35), UINT8_C( 27), UINT8_C(166), UINT8_C(131),
        UINT8_C( 88), UINT8_C( 66), UINT8_C(229), UINT8_C(206), UINT8_C( 30), UINT8_C( 67),    UINT8_MAX, UINT8_C( 67) },
      { UINT8_C( 88), UINT8_C(  3), UINT8_C(179), UINT8_C( 51), UINT8_C( 31), UINT8_C( 25), UINT8_C(165), UINT8_C(129),
        UINT8_C( 88), UINT8_C( 64), UINT8_C(226), UINT8_C(202), UINT8_C( 29), UINT8_C( 66), UINT8_C(251), UINT8_C( 65) },
      { UINT8_C( 86), UINT8_C(  3), UINT8_C(179), UINT8_C( 48), UINT8_C( 28), UINT8_C( 24), UINT8_C(164), UINT8_C(127),
        UINT8_C( 88), UINT8_C( 62), UINT8_C(224), UINT8_C(199), UINT8_C( 28), UINT8_C( 66), UINT8_C(248), UINT8_C( 63) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint8x16_t a = simde_vld1q_u8(test_vec[i].a);
    simde_uint8x16_t b = simde_vld1q_u8(test_vec[i].b);

    simde_uint8x16_t r1 = simde_vsraq_n_u8(a, b, 1);
    simde_uint8x16_t r3 = simde_vsraq_n_u8(a, b, 3);
    simde_uint8x16_t r5 = simde_vsraq_n_u8(a, b, 5);
    simde_uint8x16_t r6 = simde_vsraq_n_u8(a, b, 6);
    simde_uint8x16_t r8 = simde_vsraq_n_u8(a, b, 8);

    simde_test_arm_neon_assert_equal_u8x16(r1, simde_vld1q_u8(test_vec[i].r1));
    simde_test_arm_neon_assert_equal_u8x16(r3, simde_vld1q_u8(test_vec[i].r3));
    simde_test_arm_neon_assert_equal_u8x16(r5, simde_vld1q_u8(test_vec[i].r5));
    simde_test_arm_neon_assert_equal_u8x16(r6, simde_vld1q_u8(test_vec[i].r6));
    simde_test_arm_neon_assert_equal_u8x16(r8, simde_vld1q_u8(test_vec[i].r8));
  }

  return 0;
}

static int
test_simde_vsraq_n_u16 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    uint16_t a[8];
    uint16_t b[8];
    uint16_t r3[8];
    uint16_t r6[8];
    uint16_t r10[8];
    uint16_t r13[8];
    uint16_t r16[8];
  } test_vec[] = {
    { { UINT16_C(29593), UINT16_C(36810), UINT16_C(36769), UINT16_C(28231), UINT16_C( 6255), UINT16_C(25272), UINT16_C(37052), UINT16_C(22697) },
      { UINT16_C( 6890), UINT16_C(46431), UINT16_C(39077), UINT16_C(28289), UINT16_C(61361), UINT16_C( 1761), UINT16_C(17578), UINT16_C(17438) },
      { UINT16_C(30454), UINT16_C(42613), UINT16_C(41653), UINT16_C(31767), UINT16_C(13925), UINT16_C(25492), UINT16_C(39249), UINT16_C(24876) },
      { UINT16_C(29700), UINT16_C(37535), UINT16_C(37379), UINT16_C(28673), UINT16_C( 7213), UINT16_C(25299), UINT16_C(37326), UINT16_C(22969) },
      { UINT16_C(29599), UINT16_C(36855), UINT16_C(36807), UINT16_C(28258), UINT16_C( 6314), UINT16_C(25273), UINT16_C(37069), UINT16_C(22714) },
      { UINT16_C(29593), UINT16_C(36815), UINT16_C(36773), UINT16_C(28234), UINT16_C( 6262), UINT16_C(25272), UINT16_C(37054), UINT16_C(22699) },
      { UINT16_C(29593), UINT16_C(36810), UINT16_C(36769), UINT16_C(28231), UINT16_C( 6255), UINT16_C(25272), UINT16_C(37052), UINT16_C(22697) } },
    { { UINT16_C(59575), UINT16_C(22739), UINT16_C( 6775), UINT16_C(59079), UINT16_C(32562), UINT16_C(61000), UINT16_C(61711), UINT16_C(64070) },
      { UINT16_C(42508), UINT16_C(45487), UINT16_C(12350), UINT16_C(61215), UINT16_C(  287), UINT16_C(51957), UINT16_C( 4933), UINT16_C(64782) },
      { UINT16_C(64888), UINT16_C(28424), UINT16_C( 8318), UINT16_C( 1194), UINT16_C(32597), UINT16_C( 1958), UINT16_C(62327), UINT16_C( 6631) },
      { UINT16_C(60239), UINT16_C(23449), UINT16_C( 6967), UINT16_C(60035), UINT16_C(32566), UINT16_C(61811), UINT16_C(61788), UINT16_C(65082) },
      { UINT16_C(59616), UINT16_C(22783), UINT16_C( 6787), UINT16_C(59138), UINT16_C(32562), UINT16_C(61050), UINT16_C(61715), UINT16_C(64133) },
      { UINT16_C(59580), UINT16_C(22744), UINT16_C( 6776), UINT16_C(59086), UINT16_C(32562), UINT16_C(61006), UINT16_C(61711), UINT16_C(64077) },
      { UINT16_C(59575), UINT16_C(22739), UINT16_C( 6775), UINT16_C(59079), UINT16_C(32562), UINT16_C(61000), UINT16_C(61711), UINT16_C(64070) } },
    { { UINT16_C(57851), UINT16_C(29269), UINT16_C( 7419), UINT16_C(11608), UINT16_C(41371), UINT16_C(43803), UINT16_C(24978), UINT16_C(40613) },
      { UINT16_C(21511), UINT16_C(17744), UINT16_C(28548), UINT16_C(42036), UINT16_C(10864), UINT16_C(46702), UINT16_C(31805), UINT16_C(14771) },
      { UINT16_C(60539), UINT16_C(31487), UINT16_C(10987), UINT16_C(16862), UINT16_C(42729), UINT16_C(49640), UINT16_C(28953), UINT16_C(42459) },
      { UINT16_C(58187), UINT16_C(29546), UINT16_C( 7865), UINT16_C(12264), UINT16_C(41540), UINT16_C(44532), UINT16_C(25474), UINT16_C(40843) },
      { UINT16_C(57872), UINT16_C(29286), UINT16_C( 7446), UINT16_C(11649), UINT16_C(41381), UINT16_C(43848), UINT16_C(25009), UINT16_C(40627) },
      { UINT16_C(57853), UINT16_C(29271), UINT16_C( 7422), UINT16_C(11613), UINT16_C(41372), UINT16_C(43808), UINT16_C(24981), UINT16_C(40614) },
      { UINT16_C(57851), UINT16_C(29269), UINT16_C( 7419), UINT16_C(11608), UINT16_C(41371), UINT16_C(43803), UINT16_C(24978), UINT16_C(40613) } },
    { { UINT16_C( 2141), UINT16_C(22699), UINT16_C( 1061), UINT16_C(49285), UINT16_C(41125), UINT16_C(14187), UINT16_C( 4097), UINT16_C( 2518) },
      { UINT16_C( 9828), UINT16_C(59726), UINT16_C(33685), UINT16_C( 1677), UINT16_C(64429), UINT16_C(60092), UINT16_C(28535), UINT16_C(54307) },
      { UINT16_C( 3369), UINT16_C(30164), UINT16_C( 5271), UINT16_C(49494), UINT16_C(49178), UINT16_C(21698), UINT16_C( 7663), UINT16_C( 9306) },
      { UINT16_C( 2294), UINT16_C(23632), UINT16_C( 1587), UINT16_C(49311), UINT16_C(42131), UINT16_C(15125), UINT16_C( 4542), UINT16_C( 3366) },
      { UINT16_C( 2150), UINT16_C(22757), UINT16_C( 1093), UINT16_C(49286), UINT16_C(41187), UINT16_C(14245), UINT16_C( 4124), UINT16_C( 2571) },
      { UINT16_C( 2142), UINT16_C(22706), UINT16_C( 1065), UINT16_C(49285), UINT16_C(41132), UINT16_C(14194), UINT16_C( 4100), UINT16_C( 2524) },
      { UINT16_C( 2141), UINT16_C(22699), UINT16_C( 1061), UINT16_C(49285), UINT16_C(41125), UINT16_C(14187), UINT16_C( 4097), UINT16_C( 2518) } },
    { { UINT16_C(53111), UINT16_C(39980), UINT16_C(45523), UINT16_C(30813), UINT16_C(51281), UINT16_C(21167), UINT16_C(34265), UINT16_C(15707) },
      { UINT16_C(43691), UINT16_C(16678), UINT16_C(45869), UINT16_C(55879), UINT16_C(  942), UINT16_C( 9668), UINT16_C(59506), UINT16_C(59897) },
      { UINT16_C(58572), UINT16_C(42064), UINT16_C(51256), UINT16_C(37797), UINT16_C(51398), UINT16_C(22375), UINT16_C(41703), UINT16_C(23194) },
      { UINT16_C(53793), UINT16_C(40240), UINT16_C(46239), UINT16_C(31686), UINT16_C(51295), UINT16_C(21318), UINT16_C(35194), UINT16_C(16642) },
      { UINT16_C(53153), UINT16_C(39996), UINT16_C(45567), UINT16_C(30867), UINT16_C(51281), UINT16_C(21176), UINT16_C(34323), UINT16_C(15765) },
      { UINT16_C(53116), UINT16_C(39982), UINT16_C(45528), UINT16_C(30819), UINT16_C(51281), UINT16_C(21168), UINT16_C(34272), UINT16_C(15714) },
      { UINT16_C(53111), UINT16_C(39980), UINT16_C(45523), UINT16_C(30813), UINT16_C(51281), UINT16_C(21167), UINT16_C(34265), UINT16_C(15707) } },
    { { UINT16_C( 9655), UINT16_C(35462), UINT16_C(58326), UINT16_C( 9986), UINT16_C(45483), UINT16_C(33914), UINT16_C(54583), UINT16_C(58050) },
      { UINT16_C(59519), UINT16_C(44067), UINT16_C(27292), UINT16_C(19078), UINT16_C(19309), UINT16_C(57200), UINT16_C(26931), UINT16_C(60105) },
      { UINT16_C(17094), UINT16_C(40970), UINT16_C(61737), UINT16_C(12370), UINT16_C(47896), UINT16_C(41064), UINT16_C(57949), UINT16_C(   27) },
      { UINT16_C(10584), UINT16_C(36150), UINT16_C(58752), UINT16_C(10284), UINT16_C(45784), UINT16_C(34807), UINT16_C(55003), UINT16_C(58989) },
      { UINT16_C( 9713), UINT16_C(35505), UINT16_C(58352), UINT16_C(10004), UINT16_C(45501), UINT16_C(33969), UINT16_C(54609), UINT16_C(58108) },
      { UINT16_C( 9662), UINT16_C(35467), UINT16_C(58329), UINT16_C( 9988), UINT16_C(45485), UINT16_C(33920), UINT16_C(54586), UINT16_C(58057) },
      { UINT16_C( 9655), UINT16_C(35462), UINT16_C(58326), UINT16_C( 9986), UINT16_C(45483), UINT16_C(33914), UINT16_C(54583), UINT16_C(58050) } },
    { { UINT16_C(20367), UINT16_C(25972), UINT16_C(30258), UINT16_C(56717), UINT16_C( 1831), UINT16_C(24162), UINT16_C( 9436), UINT16_C(23617) },
      { UINT16_C(25612), UINT16_C(43016), UINT16_C(36815), UINT16_C(15603), UINT16_C(25562), UINT16_C( 3356), UINT16_C(58828), UINT16_C(23543) },
      { UINT16_C(23568), UINT16_C(31349), UINT16_C(34859), UINT16_C(58667), UINT16_C( 5026), UINT16_C(24581), UINT16_C(16789), UINT16_C(26559) },
      { UINT16_C(20767), UINT16_C(26644), UINT16_C(30833), UINT16_C(56960), UINT16_C( 2230), UINT16_C(24214), UINT16_C(10355), UINT16_C(23984) },
      { UINT16_C(20392), UINT16_C(26014), UINT16_C(30293), UINT16_C(56732), UINT16_C( 1855), UINT16_C(24165), UINT16_C( 9493), UINT16_C(23639) },
      { UINT16_C(20370), UINT16_C(25977), UINT16_C(30262), UINT16_C(56718), UINT16_C( 1834), UINT16_C(24162), UINT16_C( 9443), UINT16_C(23619) },
      { UINT16_C(20367), UINT16_C(25972), UINT16_C(30258), UINT16_C(56717), UINT16_C( 1831), UINT16_C(24162), UINT16_C( 9436), UINT16_C(23617) } },
    { { UINT16_C(27444), UINT16_C(26305), UINT16_C(20193), UINT16_C( 2115), UINT16_C(42325), UINT16_C(12647), UINT16_C(43209), UINT16_C(54925) },
      { UINT16_C(38412), UINT16_C(56190), UINT16_C(28965), UINT16_C(65304), UINT16_C(13524), UINT16_C(41228), UINT16_C(  793), UINT16_C(19964) },
      { UINT16_C(32245), UINT16_C(33328), UINT16_C(23813), UINT16_C(10278), UINT16_C(44015), UINT16_C(17800), UINT16_C(43308), UINT16_C(57420) },
      { UINT16_C(28044), UINT16_C(27182), UINT16_C(20645), UINT16_C( 3135), UINT16_C(42536), UINT16_C(13291), UINT16_C(43221), UINT16_C(55236) },
      { UINT16_C(27481), UINT16_C(26359), UINT16_C(20221), UINT16_C( 2178), UINT16_C(42338), UINT16_C(12687), UINT16_C(43209), UINT16_C(54944) },
      { UINT16_C(27448), UINT16_C(26311), UINT16_C(20196), UINT16_C( 2122), UINT16_C(42326), UINT16_C(12652), UINT16_C(43209), UINT16_C(54927) },
      { UINT16_C(27444), UINT16_C(26305), UINT16_C(20193), UINT16_C( 2115), UINT16_C(42325), UINT16_C(12647), UINT16_C(43209), UINT16_C(54925) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint16x8_t a = simde_vld1q_u16(test_vec[i].a);
    simde_uint16x8_t b = simde_vld1q_u16(test_vec[i].b);

    simde_uint16x8_t r3 = simde_vsraq_n_u16(a, b, 3);
    simde_uint16x8_t r6 = simde_vsraq_n_u16(a, b, 6);
    simde_uint16x8_t r10 = simde_vsraq_n_u16(a, b, 10);
    simde_uint16x8_t r13 = simde_vsraq_n_u16(a, b, 13);
    simde_uint16x8_t r16 = simde_vsraq_n_u16(a, b, 16);

    simde_test_arm_neon_assert_equal_u16x8(r3, simde_vld1q_u16(test_vec[i].r3));
    simde_test_arm_neon_assert_equal_u16x8(r6, simde_vld1q_u16(test_vec[i].r6));
    simde_test_arm_neon_assert_equal_u16x8(r10, simde_vld1q_u16(test_vec[i].r10));
    simde_test_arm_neon_assert_equal_u16x8(r13, simde_vld1q_u16(test_vec[i].r13));
    simde_test_arm_neon_assert_equal_u16x8(r16, simde_vld1q_u16(test_vec[i].r16));
  }

  return 0;
}

static int
test_simde_vsraq_n_u32 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    uint32_t a[4];
    uint32_t b[4];
    uint32_t r6[4];
    uint32_t r13[4];
    uint32_t r19[4];
    uint32_t r26[4];
    uint32_t r32[4];
  } test_vec[] = {
    { { UINT32_C(1979807148), UINT32_C(3348053427), UINT32_C(1572125531), UINT32_C( 385796267) },
      { UINT32_C( 891890417), UINT32_C(3586666332), UINT32_C(3784648901), UINT32_C(1110980757) },
      { UINT32_C(1993742935), UINT32_C(3404095088), UINT32_C(1631260670), UINT32_C( 403155341) },
      { UINT32_C(1979916021), UINT32_C(3348491252), UINT32_C(1572587524), UINT32_C( 385931884) },
      { UINT32_C(1979808849), UINT32_C(3348060268), UINT32_C(1572132749), UINT32_C( 385798386) },
      { UINT32_C(1979807161), UINT32_C(3348053480), UINT32_C(1572125587), UINT32_C( 385796283) },
      { UINT32_C(1979807148), UINT32_C(3348053427), UINT32_C(1572125531), UINT32_C( 385796267) } },
    { { UINT32_C(1622686125), UINT32_C(3525789558), UINT32_C(2905594882), UINT32_C(2529373604) },
      { UINT32_C(3033263192), UINT32_C(3767112475), UINT32_C(1371676347), UINT32_C(  60029526) },
      { UINT32_C(1670080862), UINT32_C(3584650690), UINT32_C(2927027324), UINT32_C(2530311565) },
      { UINT32_C(1623056396), UINT32_C(3526249410), UINT32_C(2905762322), UINT32_C(2529380931) },
      { UINT32_C(1622691910), UINT32_C(3525796743), UINT32_C(2905597498), UINT32_C(2529373718) },
      { UINT32_C(1622686170), UINT32_C(3525789614), UINT32_C(2905594902), UINT32_C(2529373604) },
      { UINT32_C(1622686125), UINT32_C(3525789558), UINT32_C(2905594882), UINT32_C(2529373604) } },
    { { UINT32_C(2858699572), UINT32_C(2491190162), UINT32_C( 205630567), UINT32_C( 832701913) },
      { UINT32_C( 233139697), UINT32_C(3152899840), UINT32_C(3826036621), UINT32_C(3739721642) },
      { UINT32_C(2862342379), UINT32_C(2540454222), UINT32_C( 265412389), UINT32_C( 891135063) },
      { UINT32_C(2858728031), UINT32_C(2491575037), UINT32_C( 206097612), UINT32_C( 833158421) },
      { UINT32_C(2858700016), UINT32_C(2491196175), UINT32_C( 205637864), UINT32_C( 832709045) },
      { UINT32_C(2858699575), UINT32_C(2491190208), UINT32_C( 205630624), UINT32_C( 832701968) },
      { UINT32_C(2858699572), UINT32_C(2491190162), UINT32_C( 205630567), UINT32_C( 832701913) } },
    { { UINT32_C(2089307114), UINT32_C(1041237463), UINT32_C(2320126641), UINT32_C(1220340823) },
      { UINT32_C(1498784089), UINT32_C(2652193552), UINT32_C(2625774066), UINT32_C(2876926401) },
      { UINT32_C(2112725615), UINT32_C(1082677987), UINT32_C(2361154360), UINT32_C(1265292798) },
      { UINT32_C(2089490071), UINT32_C(1041561217), UINT32_C(2320447170), UINT32_C(1220692010) },
      { UINT32_C(2089309972), UINT32_C(1041242521), UINT32_C(2320131649), UINT32_C(1220346310) },
      { UINT32_C(2089307136), UINT32_C(1041237502), UINT32_C(2320126680), UINT32_C(1220340865) },
      { UINT32_C(2089307114), UINT32_C(1041237463), UINT32_C(2320126641), UINT32_C(1220340823) } },
    { { UINT32_C(2351432629), UINT32_C(3117037576), UINT32_C(3779270026), UINT32_C(1529544449) },
      { UINT32_C(2981396385), UINT32_C(3041905090), UINT32_C(2891043307), UINT32_C(4032285755) },
      { UINT32_C(2398016947), UINT32_C(3164567343), UINT32_C(3824442577), UINT32_C(1592548913) },
      { UINT32_C(2351796568), UINT32_C(3117408902), UINT32_C(3779622936), UINT32_C(1530036671) },
      { UINT32_C(2351438315), UINT32_C(3117043377), UINT32_C(3779275540), UINT32_C(1529552139) },
      { UINT32_C(2351432673), UINT32_C(3117037621), UINT32_C(3779270069), UINT32_C(1529544509) },
      { UINT32_C(2351432629), UINT32_C(3117037576), UINT32_C(3779270026), UINT32_C(1529544449) } },
    { { UINT32_C(3615260623), UINT32_C(1116751544), UINT32_C(1562694491), UINT32_C(1958235859) },
      { UINT32_C(2418371789), UINT32_C( 558200118), UINT32_C(2177734214), UINT32_C( 829498466) },
      { UINT32_C(3653047682), UINT32_C(1125473420), UINT32_C(1596721588), UINT32_C(1971196772) },
      { UINT32_C(3615555834), UINT32_C(1116819683), UINT32_C(1562960327), UINT32_C(1958337116) },
      { UINT32_C(3615265235), UINT32_C(1116752608), UINT32_C(1562698644), UINT32_C(1958237441) },
      { UINT32_C(3615260659), UINT32_C(1116751552), UINT32_C(1562694523), UINT32_C(1958235871) },
      { UINT32_C(3615260623), UINT32_C(1116751544), UINT32_C(1562694491), UINT32_C(1958235859) } },
    { { UINT32_C(1544088996), UINT32_C(2409535540), UINT32_C(1072480876), UINT32_C(3736314896) },
      { UINT32_C(1198446609), UINT32_C(2489889613), UINT32_C(2887071049), UINT32_C(4259153753) },
      { UINT32_C(1562814724), UINT32_C(2448440065), UINT32_C(1117591361), UINT32_C(3802864173) },
      { UINT32_C(1544235290), UINT32_C(2409839481), UINT32_C(1072833301), UINT32_C(3736834812) },
      { UINT32_C(1544091281), UINT32_C(2409540289), UINT32_C(1072486382), UINT32_C(3736323019) },
      { UINT32_C(1544089013), UINT32_C(2409535577), UINT32_C(1072480919), UINT32_C(3736314959) },
      { UINT32_C(1544088996), UINT32_C(2409535540), UINT32_C(1072480876), UINT32_C(3736314896) } },
    { { UINT32_C(2824463988), UINT32_C(3929602174), UINT32_C(3408471226), UINT32_C(3668565193) },
      { UINT32_C(  35723189), UINT32_C( 328632778), UINT32_C( 398437566), UINT32_C(2803211571) },
      { UINT32_C(2825022162), UINT32_C(3934737061), UINT32_C(3414696812), UINT32_C(3712365373) },
      { UINT32_C(2824468348), UINT32_C(3929642290), UINT32_C(3408519863), UINT32_C(3668907381) },
      { UINT32_C(2824464056), UINT32_C(3929602800), UINT32_C(3408471985), UINT32_C(3668570539) },
      { UINT32_C(2824463988), UINT32_C(3929602178), UINT32_C(3408471231), UINT32_C(3668565234) },
      { UINT32_C(2824463988), UINT32_C(3929602174), UINT32_C(3408471226), UINT32_C(3668565193) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint32x4_t a = simde_vld1q_u32(test_vec[i].a);
    simde_uint32x4_t b = simde_vld1q_u32(test_vec[i].b);

    simde_uint32x4_t r6 = simde_vsraq_n_u32(a, b, 6);
    simde_uint32x4_t r13 = simde_vsraq_n_u32(a, b, 13);
    simde_uint32x4_t r19 = simde_vsraq_n_u32(a, b, 19);
    simde_uint32x4_t r26 = simde_vsraq_n_u32(a, b, 26);
    simde_uint32x4_t r32 = simde_vsraq_n_u32(a, b, 32);

    simde_test_arm_neon_assert_equal_u32x4(r6, simde_vld1q_u32(test_vec[i].r6));
    simde_test_arm_neon_assert_equal_u32x4(r13, simde_vld1q_u32(test_vec[i].r13));
    simde_test_arm_neon_assert_equal_u32x4(r19, simde_vld1q_u32(test_vec[i].r19));
    simde_test_arm_neon_assert_equal_u32x4(r26, simde_vld1q_u32(test_vec[i].r26));
    simde_test_arm_neon_assert_equal_u32x4(r32, simde_vld1q_u32(test_vec[i].r32));
  }

  return 0;
}

static int
test_simde_vsraq_n_u64 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    uint64_t a[2];
    uint64_t b[2];
    uint64_t r13[2];
    uint64_t r26[2];
    uint64_t r39[2];
    uint64_t r52[2];
    uint64_t r64[2];
  } test_vec[] = {
    { { UINT64_C(17874051099209012816), UINT64_C( 8625195464406836271) },
      { UINT64_C(16725053657440447411), UINT64_C(   14759499813092458) },
      { UINT64_C(17876092731735555839), UINT64_C( 8625197266103590798) },
      { UINT64_C(17874051348431733341), UINT64_C( 8625195464626769956) },
      { UINT64_C(17874051099239435511), UINT64_C( 8625195464406863118) },
      { UINT64_C(17874051099209016529), UINT64_C( 8625195464406836274) },
      { UINT64_C(17874051099209012816), UINT64_C( 8625195464406836271) } },
    { { UINT64_C( 5675430669503806469), UINT64_C(10942796997914856402) },
      { UINT64_C(12619904489882514058), UINT64_C(  113922584089103844) },
      { UINT64_C( 5676971185188606580), UINT64_C(10942810904480296966) },
      { UINT64_C( 5675430857555037523), UINT64_C(10942796999612435191) },
      { UINT64_C( 5675430669526761941), UINT64_C(10942796997915063625) },
      { UINT64_C( 5675430669503809271), UINT64_C(10942796997914856427) },
      { UINT64_C( 5675430669503806469), UINT64_C(10942796997914856402) } },
    { { UINT64_C(13107040498182042999), UINT64_C(18092920619843375770) },
      { UINT64_C(12744720525670343657), UINT64_C(10944266200905180388) },
      { UINT64_C(13108596250199336742), UINT64_C(18094256589838603453) },
      { UINT64_C(13107040688093177922), UINT64_C(18092920782925650578) },
      { UINT64_C(13107040498205225510), UINT64_C(18092920619863283274) },
      { UINT64_C(13107040498182045828), UINT64_C(18092920619843378200) },
      { UINT64_C(13107040498182042999), UINT64_C(18092920619843375770) } },
    { { UINT64_C(15502817343082179981), UINT64_C( 2256422393928368100) },
      { UINT64_C(13892246799416984912), UINT64_C( 8378808463846805392) },
      { UINT64_C(15504513173990311937), UINT64_C( 2257445197695927524) },
      { UINT64_C(15502817550092788883), UINT64_C( 2256422518782343632) },
      { UINT64_C(15502817343107449830), UINT64_C( 2256422393943609063) },
      { UINT64_C(15502817343082183065), UINT64_C( 2256422393928369960) },
      { UINT64_C(15502817343082179981), UINT64_C( 2256422393928368100) } },
    { { UINT64_C( 7728750387756561454), UINT64_C( 6097611131503876169) },
      { UINT64_C(12192435071695777175), UINT64_C( 9558785026189546571) },
      { UINT64_C( 7730238722115899317), UINT64_C( 6098777975379143447) },
      { UINT64_C( 7728750569438001802), UINT64_C( 6097611273940872661) },
      { UINT64_C( 7728750387778739364), UINT64_C( 6097611131521263497) },
      { UINT64_C( 7728750387756564161), UINT64_C( 6097611131503878291) },
      { UINT64_C( 7728750387756561454), UINT64_C( 6097611131503876169) } },
    { { UINT64_C(15998810719909808917), UINT64_C( 8152356292189341897) },
      { UINT64_C( 1849880820033295081), UINT64_C(13531050401365427693) },
      { UINT64_C(15999036535439598137), UINT64_C( 8154008031740289825) },
      { UINT64_C(15998810747475181205), UINT64_C( 8152356493817705049) },
      { UINT64_C(15998810719913173830), UINT64_C( 8152356292213954734) },
      { UINT64_C(15998810719909809327), UINT64_C( 8152356292189344901) },
      { UINT64_C(15998810719909808917), UINT64_C( 8152356292189341897) } },
    { { UINT64_C(12894191558988380030), UINT64_C( 3779261480348700199) },
      { UINT64_C( 6637430016772101685), UINT64_C(15585100524618213352) },
      { UINT64_C(12895001792144724280), UINT64_C( 3781163958440084258) },
      { UINT64_C(12894191657893794622), UINT64_C( 3779261712584795338) },
      { UINT64_C(12894191559000453444), UINT64_C( 3779261480377049331) },
      { UINT64_C(12894191558988381503), UINT64_C( 3779261480348703659) },
      { UINT64_C(12894191558988380030), UINT64_C( 3779261480348700199) } },
    { { UINT64_C( 2790222957046898717), UINT64_C( 1128883820157155370) },
      { UINT64_C(12446311941118550511), UINT64_C(15981169241923213718) },
      { UINT64_C( 2791742282235023540), UINT64_C( 1130834646480632324) },
      { UINT64_C( 2790223142511399220), UINT64_C( 1128884058295134310) },
      { UINT64_C( 2790222957069538426), UINT64_C( 1128883820186224947) },
      { UINT64_C( 2790222957046901480), UINT64_C( 1128883820157158918) },
      { UINT64_C( 2790222957046898717), UINT64_C( 1128883820157155370) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint64x2_t a = simde_vld1q_u64(test_vec[i].a);
    simde_uint64x2_t b = simde_vld1q_u64(test_vec[i].b);

    simde_uint64x2_t r13 = simde_vsraq_n_u64(a, b, 13);
    simde_uint64x2_t r26 = simde_vsraq_n_u64(a, b, 26);
    simde_uint64x2_t r39 = simde_vsraq_n_u64(a, b, 39);
    simde_uint64x2_t r52 = simde_vsraq_n_u64(a, b, 52);
    simde_uint64x2_t r64 = simde_vsraq_n_u64(a, b, 64);

    simde_test_arm_neon_assert_equal_u64x2(r13, simde_vld1q_u64(test_vec[i].r13));
    simde_test_arm_neon_assert_equal_u64x2(r26, simde_vld1q_u64(test_vec[i].r26));
    simde_test_arm_neon_assert_equal_u64x2(r39, simde_vld1q_u64(test_vec[i].r39));
    simde_test_arm_neon_assert_equal_u64x2(r52, simde_vld1q_u64(test_vec[i].r52));
    simde_test_arm_neon_assert_equal_u64x2(r64, simde_vld1q_u64(test_vec[i].r64));
  }

  return 0;
}

static int
test_simde_vsrad_n_s64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int64_t a;
    int64_t b;
    int64_t r1;
    int64_t r13;
    int64_t r23;
    int64_t r37;
    int64_t r46;
    int64_t r55;
    int64_t r64;
  } test_vec[] = {
    { -INT64_C( 5941007582965108752),
       INT64_C( 8641151255525186942),
      -INT64_C( 1620431955202515281),
      -INT64_C( 5939952754930987026),
      -INT64_C( 5941006552859606681),
      -INT64_C( 5941007582902236102),
      -INT64_C( 5941007582964985954),
      -INT64_C( 5941007582965108513),
      -INT64_C( 5941007582965108752) },
    {  INT64_C( 8761373520960992027),
       INT64_C(  689984336478112434),
       INT64_C( 9106365689200048244),
       INT64_C( 8761457747564566015),
       INT64_C( 8761373603213534579),
       INT64_C( 8761373520966012323),
       INT64_C( 8761373520961001832),
       INT64_C( 8761373520960992046),
       INT64_C( 8761373520960992027) },
    { -INT64_C( 3134198203972712000),
       INT64_C( 2716930659612328180),
      -INT64_C( 1775732874166547910),
      -INT64_C( 3133866547398052292),
      -INT64_C( 3134197880089338309),
      -INT64_C( 3134198203952943728),
      -INT64_C( 3134198203972673391),
      -INT64_C( 3134198203972711925),
      -INT64_C( 3134198203972712000) },
    {  INT64_C( 8175416234332002350),
      -INT64_C( 2191511248017960845),
       INT64_C( 7079660610323021927),
       INT64_C( 8175148715869109532),
       INT64_C( 8175415973083503431),
       INT64_C( 8175416234316057007),
       INT64_C( 8175416234331971206),
       INT64_C( 8175416234332002289),
       INT64_C( 8175416234332002349) },
    {  INT64_C( 3198459776920264761),
      -INT64_C( 7213325771435543626),
      -INT64_C(  408203108797507052),
       INT64_C( 3197579243989181320),
       INT64_C( 3198458917024824249),
       INT64_C( 3198459776867780908),
       INT64_C( 3198459776920162253),
       INT64_C( 3198459776920264560),
       INT64_C( 3198459776920264760) },
    { -INT64_C( 7753217092524558282),
       INT64_C( 7988460182011118810),
      -INT64_C( 3758987001518998877),
      -INT64_C( 7752241938693746378),
      -INT64_C( 7753216140225895380),
      -INT64_C( 7753217092466434585),
      -INT64_C( 7753217092524444760),
      -INT64_C( 7753217092524558061),
      -INT64_C( 7753217092524558282) },
    {  INT64_C( 9023913785961648599),
      -INT64_C(  478186661746924204),
       INT64_C( 8784820455088186497),
       INT64_C( 9023855413566415820),
       INT64_C( 9023913728957356379),
       INT64_C( 9023913785958169333),
       INT64_C( 9023913785961641803),
       INT64_C( 9023913785961648585),
       INT64_C( 9023913785961648598) },
    { -INT64_C( 2949762109204860069),
      -INT64_C( 4684114252845141670),
      -INT64_C( 5291819235627430904),
      -INT64_C( 2950333900495490580),
      -INT64_C( 2949762667594792326),
      -INT64_C( 2949762109238941486),
      -INT64_C( 2949762109204926635),
      -INT64_C( 2949762109204860200),
      -INT64_C( 2949762109204860070) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    int64_t r1 = simde_vsrad_n_s64(test_vec[i].a, test_vec[i].b, 1);
    int64_t r13 = simde_vsrad_n_s64(test_vec[i].a, test_vec[i].b, 13);
    int64_t r23 = simde_vsrad_n_s64(test_vec[i].a, test_vec[i].b, 23);
    int64_t r37 = simde_vsrad_n_s64(test_vec[i].a, test_vec[i].b, 37);
    int64_t r46 = simde_vsrad_n_s64(test_vec[i].a, test_vec[i].b, 46);
    int64_t r55 = simde_vsrad_n_s64(test_vec[i].a, test_vec[i].b, 55);
    int64_t r64 = simde_vsrad_n_s64(test_vec[i].a, test_vec[i].b, 64);

    simde_assert_equal_i64(r1, test_vec[i].r1);
    simde_assert_equal_i64(r13, test_vec[i].r13);
    simde_assert_equal_i64(r23, test_vec[i].r23);
    simde_assert_equal_i64(r37, test_vec[i].r37);
    simde_assert_equal_i64(r46, test_vec[i].r46);
    simde_assert_equal_i64(r55, test_vec[i].r55);
    simde_assert_equal_i64(r64, test_vec[i].r64);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    int64_t a = simde_test_codegen_random_i64();
    int64_t b = simde_test_codegen_random_i64();
    int64_t r1 = simde_vsrad_n_s64(a, b, 1);
    int64_t r13 = simde_vsrad_n_s64(a, b, 13);
    int64_t r23 = simde_vsrad_n_s64(a, b, 23);
    int64_t r37 = simde_vsrad_n_s64(a, b, 37);
    int64_t r46 = simde_vsrad_n_s64(a, b, 46);
    int64_t r55 = simde_vsrad_n_s64(a, b, 55);
    int64_t r64 = simde_vsrad_n_s64(a, b, 64);

    simde_test_codegen_write_i64(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_i64(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i64(2, r1, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i64(2, r13, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i64(2, r23, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i64(2, r37, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i64(2, r46, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i64(2, r55, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i64(2, r64, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vsrad_n_u64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint64_t a;
    uint64_t b;
    uint64_t r1;
    uint64_t r13;
    uint64_t r23;
    uint64_t r37;
    uint64_t r46;
    uint64_t r55;
    uint64_t r64;
  } test_vec[] = {
    { UINT64_C( 9698906179435153121),
      UINT64_C(10624195180459403855),
      UINT64_C(15011003769664855048),
      UINT64_C( 9700203078260892794),
      UINT64_C( 9698907445937912632),
      UINT64_C( 9698906179512454314),
      UINT64_C( 9698906179435304099),
      UINT64_C( 9698906179435153415),
      UINT64_C( 9698906179435153121) },
    { UINT64_C( 6909288780698600732),
      UINT64_C( 1255345618514113698),
      UINT64_C( 7536961589955657581),
      UINT64_C( 6909442021130548255),
      UINT64_C( 6909288930347460055),
      UINT64_C( 6909288780707734573),
      UINT64_C( 6909288780698618571),
      UINT64_C( 6909288780698600766),
      UINT64_C( 6909288780698600732) },
    { UINT64_C( 4393026057000746408),
      UINT64_C( 9160558464645704275),
      UINT64_C( 8973305289323598545),
      UINT64_C( 4394144289235200229),
      UINT64_C( 4393027149024412866),
      UINT64_C( 4393026057067398243),
      UINT64_C( 4393026057000876587),
      UINT64_C( 4393026057000746662),
      UINT64_C( 4393026057000746408) },
    { UINT64_C(11351150216649654941),
      UINT64_C(17444524145478690774),
      UINT64_C( 1626668215679448712),
      UINT64_C(11353279675163507320),
      UINT64_C(11351152296198984874),
      UINT64_C(11351150216776580559),
      UINT64_C(11351150216649902842),
      UINT64_C(11351150216649655425),
      UINT64_C(11351150216649654941) },
    { UINT64_C( 2597268363476641763),
      UINT64_C(16710274684413899267),
      UINT64_C(10952405705683591396),
      UINT64_C( 2599308191929329006),
      UINT64_C( 2597270355496615090),
      UINT64_C( 2597268363598225013),
      UINT64_C( 2597268363476879230),
      UINT64_C( 2597268363476642226),
      UINT64_C( 2597268363476641763) },
    { UINT64_C(11506017309480085012),
      UINT64_C(17381850630848882940),
      UINT64_C( 1750198551194974866),
      UINT64_C(11508139117418421057),
      UINT64_C(11506019381558149793),
      UINT64_C(11506017309606554620),
      UINT64_C(11506017309480332022),
      UINT64_C(11506017309480085494),
      UINT64_C(11506017309480085012) },
    { UINT64_C(17823502349541349988),
      UINT64_C(17325143105000573502),
      UINT64_C( 8039329828332085123),
      UINT64_C(17825617235174284628),
      UINT64_C(17823504414859350900),
      UINT64_C(17823502349667406994),
      UINT64_C(17823502349541596193),
      UINT64_C(17823502349541350468),
      UINT64_C(17823502349541349988) },
    { UINT64_C( 1158459828226522795),
      UINT64_C(15732356033140930645),
      UINT64_C( 9024637844796988117),
      UINT64_C( 1160380281843849568),
      UINT64_C( 1158461703669508465),
      UINT64_C( 1158459828340990750),
      UINT64_C( 1158459828226746365),
      UINT64_C( 1158459828226523231),
      UINT64_C( 1158459828226522795) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    uint64_t r1 = simde_vsrad_n_u64(test_vec[i].a, test_vec[i].b, 1);
    uint64_t r13 = simde_vsrad_n_u64(test_vec[i].a, test_vec[i].b, 13);
    uint64_t r23 = simde_vsrad_n_u64(test_vec[i].a, test_vec[i].b, 23);
    uint64_t r37 = simde_vsrad_n_u64(test_vec[i].a, test_vec[i].b, 37);
    uint64_t r46 = simde_vsrad_n_u64(test_vec[i].a, test_vec[i].b, 46);
    uint64_t r55 = simde_vsrad_n_u64(test_vec[i].a, test_vec[i].b, 55);
    uint64_t r64 = simde_vsrad_n_u64(test_vec[i].a, test_vec[i].b, 64);

    simde_assert_equal_u64(r1, test_vec[i].r1);
    simde_assert_equal_u64(r13, test_vec[i].r13);
    simde_assert_equal_u64(r23, test_vec[i].r23);
    simde_assert_equal_u64(r37, test_vec[i].r37);
    simde_assert_equal_u64(r46, test_vec[i].r46);
    simde_assert_equal_u64(r55, test_vec[i].r55);
    simde_assert_equal_u64(r64, test_vec[i].r64);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    uint64_t a = simde_test_codegen_random_u64();
    uint64_t b = simde_test_codegen_random_u64();
    uint64_t r1 = simde_vsrad_n_u64(a, b, 1);
    uint64_t r13 = simde_vsrad_n_u64(a, b, 13);
    uint64_t r23 = simde_vsrad_n_u64(a, b, 23);
    uint64_t r37 = simde_vsrad_n_u64(a, b, 37);
    uint64_t r46 = simde_vsrad_n_u64(a, b, 46);
    uint64_t r55 = simde_vsrad_n_u64(a, b, 55);
    uint64_t r64 = simde_vsrad_n_u64(a, b, 64);

    simde_test_codegen_write_u64(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_u64(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_u64(2, r1, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_u64(2, r13, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_u64(2, r23, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_u64(2, r37, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_u64(2, r46, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_u64(2, r55, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_u64(2, r64, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(vsra_n_s8)
SIMDE_TEST_FUNC_LIST_ENTRY(vsra_n_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vsra_n_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vsra_n_s64)
SIMDE_TEST_FUNC_LIST_ENTRY(vsra_n_u8)
SIMDE_TEST_FUNC_LIST_ENTRY(vsra_n_u16)
SIMDE_TEST_FUNC_LIST_ENTRY(vsra_n_u32)
SIMDE_TEST_FUNC_LIST_ENTRY(vsra_n_u64)

SIMDE_TEST_FUNC_LIST_ENTRY(vsraq_n_s8)
SIMDE_TEST_FUNC_LIST_ENTRY(vsraq_n_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vsraq_n_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vsraq_n_s64)
SIMDE_TEST_FUNC_LIST_ENTRY(vsraq_n_u8)
SIMDE_TEST_FUNC_LIST_ENTRY(vsraq_n_u16)
SIMDE_TEST_FUNC_LIST_ENTRY(vsraq_n_u32)
SIMDE_TEST_FUNC_LIST_ENTRY(vsraq_n_u64)

SIMDE_TEST_FUNC_LIST_ENTRY(vsrad_n_s64)
SIMDE_TEST_FUNC_LIST_ENTRY(vsrad_n_u64)
SIMDE_TEST_FUNC_LIST_END

#include <test/arm/neon/test-neon-footer.h>
