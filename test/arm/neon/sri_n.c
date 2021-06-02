#define SIMDE_TEST_ARM_NEON_INSN sri_n

#include <test/arm/neon/test-neon.h>
#include <simde/arm/neon/sri_n.h>

static int
test_simde_vsri_n_s8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    int8_t a[8];
    int8_t b[8];
    int8_t r1[8];
    int8_t r3[8];
    int8_t r5[8];
    int8_t r8[8];
  } test_vec[] = {
    { { -INT8_C(  10), -INT8_C(  27),  INT8_C(  61), -INT8_C(  67),  INT8_C(  54),  INT8_C(  81),  INT8_C( 123),  INT8_C(  14) },
      {  INT8_C( 108), -INT8_C( 105), -INT8_C(  69), -INT8_C(  22),  INT8_C(  83),  INT8_C( 115), -INT8_C(   2), -INT8_C(  18) },
      { -INT8_C(  74), -INT8_C(  53),  INT8_C(  93), -INT8_C(  11),  INT8_C(  41),  INT8_C(  57),      INT8_MAX,  INT8_C( 119) },
      { -INT8_C(  19), -INT8_C(  14),  INT8_C(  55), -INT8_C(  67),  INT8_C(  42),  INT8_C(  78),      INT8_MAX,  INT8_C(  29) },
      { -INT8_C(  13), -INT8_C(  28),  INT8_C(  61), -INT8_C(  65),  INT8_C(  50),  INT8_C(  83),      INT8_MAX,  INT8_C(  15) },
      { -INT8_C(  10), -INT8_C(  27),  INT8_C(  61), -INT8_C(  67),  INT8_C(  54),  INT8_C(  81),  INT8_C( 123),  INT8_C(  14) } },
    { {  INT8_C( 116), -INT8_C( 103), -INT8_C(  59),  INT8_C(  70),  INT8_C(  72),  INT8_C(   7),  INT8_C(  40), -INT8_C( 118) },
      {  INT8_C(  79),  INT8_C(  34),  INT8_C(  79), -INT8_C(  92), -INT8_C(   7), -INT8_C(  26),  INT8_C(  76), -INT8_C(  16) },
      {  INT8_C(  39), -INT8_C( 111), -INT8_C(  89),  INT8_C(  82),  INT8_C( 124),  INT8_C( 115),  INT8_C(  38), -INT8_C(   8) },
      {  INT8_C( 105), -INT8_C( 124), -INT8_C(  55),  INT8_C(  84),  INT8_C(  95),  INT8_C(  28),  INT8_C(  41), -INT8_C(  98) },
      {  INT8_C( 114), -INT8_C( 103), -INT8_C(  62),  INT8_C(  69),  INT8_C(  79),  INT8_C(   7),  INT8_C(  42), -INT8_C( 113) },
      {  INT8_C( 116), -INT8_C( 103), -INT8_C(  59),  INT8_C(  70),  INT8_C(  72),  INT8_C(   7),  INT8_C(  40), -INT8_C( 118) } },
    { { -INT8_C(  53), -INT8_C( 119), -INT8_C(  83),  INT8_C(   1), -INT8_C(  38),  INT8_C(  40),  INT8_C(  15),  INT8_C(  71) },
      { -INT8_C(  65), -INT8_C(  53),  INT8_C(  49),  INT8_C(  18),  INT8_C(  62),  INT8_C(  47),  INT8_C(   0), -INT8_C(  78) },
      { -INT8_C(  33), -INT8_C(  27), -INT8_C( 104),  INT8_C(   9), -INT8_C(  97),  INT8_C(  23),  INT8_C(   0),  INT8_C(  89) },
      { -INT8_C(  41), -INT8_C( 103), -INT8_C(  90),  INT8_C(   2), -INT8_C(  57),  INT8_C(  37),  INT8_C(   0),  INT8_C(  86) },
      { -INT8_C(  51), -INT8_C( 114), -INT8_C(  87),  INT8_C(   0), -INT8_C(  39),  INT8_C(  41),  INT8_C(   8),  INT8_C(  69) },
      { -INT8_C(  53), -INT8_C( 119), -INT8_C(  83),  INT8_C(   1), -INT8_C(  38),  INT8_C(  40),  INT8_C(  15),  INT8_C(  71) } },
    { { -INT8_C(  56), -INT8_C(  59), -INT8_C(   8),  INT8_C(  16), -INT8_C(  51),  INT8_C(  32), -INT8_C( 102),  INT8_C(  28) },
      {  INT8_C(  67), -INT8_C(  23), -INT8_C(  64),  INT8_C(  60), -INT8_C(  49),  INT8_C(  12),  INT8_C(  44), -INT8_C( 102) },
      { -INT8_C(  95), -INT8_C(  12), -INT8_C(  32),  INT8_C(  30), -INT8_C(  25),  INT8_C(   6), -INT8_C( 106),  INT8_C(  77) },
      { -INT8_C(  56), -INT8_C(  35), -INT8_C(   8),  INT8_C(   7), -INT8_C(  39),  INT8_C(  33), -INT8_C( 123),  INT8_C(  19) },
      { -INT8_C(  54), -INT8_C(  57), -INT8_C(   2),  INT8_C(  17), -INT8_C(  50),  INT8_C(  32), -INT8_C( 103),  INT8_C(  28) },
      { -INT8_C(  56), -INT8_C(  59), -INT8_C(   8),  INT8_C(  16), -INT8_C(  51),  INT8_C(  32), -INT8_C( 102),  INT8_C(  28) } },
    { { -INT8_C( 107), -INT8_C(  39), -INT8_C( 100),  INT8_C( 112),  INT8_C(   1), -INT8_C(  85), -INT8_C(  73), -INT8_C(  64) },
      {  INT8_C( 118), -INT8_C(  24), -INT8_C(  45), -INT8_C(  75),  INT8_C(  23), -INT8_C(  45),  INT8_C( 103), -INT8_C(  33) },
      { -INT8_C(  69), -INT8_C(  12), -INT8_C(  23),  INT8_C(  90),  INT8_C(  11), -INT8_C(  23), -INT8_C(  77), -INT8_C(  17) },
      { -INT8_C( 114), -INT8_C(  35), -INT8_C( 102),  INT8_C( 118),  INT8_C(   2), -INT8_C(  70), -INT8_C(  84), -INT8_C(  37) },
      { -INT8_C( 109), -INT8_C(  33), -INT8_C(  98),  INT8_C( 117),  INT8_C(   0), -INT8_C(  82), -INT8_C(  77), -INT8_C(  58) },
      { -INT8_C( 107), -INT8_C(  39), -INT8_C( 100),  INT8_C( 112),  INT8_C(   1), -INT8_C(  85), -INT8_C(  73), -INT8_C(  64) } },
    { { -INT8_C( 103),  INT8_C(  96), -INT8_C(  17),  INT8_C( 102),      INT8_MIN, -INT8_C( 119), -INT8_C( 126), -INT8_C(  61) },
      {  INT8_C( 115),  INT8_C(  66),  INT8_C(   0),  INT8_C(  66),  INT8_C(  78),  INT8_C(  44), -INT8_C(  35), -INT8_C(  29) },
      { -INT8_C(  71),  INT8_C(  33),      INT8_MIN,  INT8_C(  33), -INT8_C(  89), -INT8_C( 106), -INT8_C(  18), -INT8_C(  15) },
      { -INT8_C( 114),  INT8_C( 104), -INT8_C(  32),  INT8_C( 104), -INT8_C( 119), -INT8_C( 123), -INT8_C( 101), -INT8_C(  36) },
      { -INT8_C( 101),  INT8_C(  98), -INT8_C(  24),  INT8_C(  98), -INT8_C( 126), -INT8_C( 119), -INT8_C( 122), -INT8_C(  57) },
      { -INT8_C( 103),  INT8_C(  96), -INT8_C(  17),  INT8_C( 102),      INT8_MIN, -INT8_C( 119), -INT8_C( 126), -INT8_C(  61) } },
    { {  INT8_C(   6),  INT8_C( 121),  INT8_C(  83),  INT8_C(   7),  INT8_C(  36),  INT8_C(  10), -INT8_C(  56), -INT8_C( 101) },
      { -INT8_C(  14), -INT8_C( 101),  INT8_C(  80),  INT8_C(   9),  INT8_C( 110), -INT8_C(  73), -INT8_C(  24),  INT8_C(   7) },
      {  INT8_C( 121),  INT8_C(  77),  INT8_C(  40),  INT8_C(   4),  INT8_C(  55),  INT8_C(  91), -INT8_C(  12), -INT8_C( 125) },
      {  INT8_C(  30),  INT8_C( 115),  INT8_C(  74),  INT8_C(   1),  INT8_C(  45),  INT8_C(  22), -INT8_C(  35),      INT8_MIN },
      {  INT8_C(   7),  INT8_C( 124),  INT8_C(  82),  INT8_C(   0),  INT8_C(  35),  INT8_C(  13), -INT8_C(  49), -INT8_C( 104) },
      {  INT8_C(   6),  INT8_C( 121),  INT8_C(  83),  INT8_C(   7),  INT8_C(  36),  INT8_C(  10), -INT8_C(  56), -INT8_C( 101) } },
    { {  INT8_C(  23), -INT8_C(  41),  INT8_C( 109), -INT8_C( 104),  INT8_C(  97), -INT8_C(  17),  INT8_C(  91), -INT8_C(  44) },
      {  INT8_C(  49),  INT8_C(  91),  INT8_C(  22),      INT8_MAX, -INT8_C( 120), -INT8_C(  13),  INT8_C(  99), -INT8_C( 114) },
      {  INT8_C(  24), -INT8_C(  83),  INT8_C(  11), -INT8_C(  65),  INT8_C(  68), -INT8_C(   7),  INT8_C(  49), -INT8_C(  57) },
      {  INT8_C(   6), -INT8_C(  53),  INT8_C(  98), -INT8_C( 113),  INT8_C( 113), -INT8_C(   2),  INT8_C(  76), -INT8_C(  47) },
      {  INT8_C(  17), -INT8_C(  46),  INT8_C( 104), -INT8_C( 101),  INT8_C( 100), -INT8_C(  17),  INT8_C(  91), -INT8_C(  44) },
      {  INT8_C(  23), -INT8_C(  41),  INT8_C( 109), -INT8_C( 104),  INT8_C(  97), -INT8_C(  17),  INT8_C(  91), -INT8_C(  44) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int8x8_t a = simde_vld1_s8(test_vec[i].a);
    simde_int8x8_t b = simde_vld1_s8(test_vec[i].b);

    simde_int8x8_t r1 = simde_vsri_n_s8(a, b, 1);
    simde_int8x8_t r3 = simde_vsri_n_s8(a, b, 3);
    simde_int8x8_t r5 = simde_vsri_n_s8(a, b, 5);
    simde_int8x8_t r8 = simde_vsri_n_s8(a, b, 8);

    simde_test_arm_neon_assert_equal_i8x8(r1, simde_vld1_s8(test_vec[i].r1));
    simde_test_arm_neon_assert_equal_i8x8(r3, simde_vld1_s8(test_vec[i].r3));
    simde_test_arm_neon_assert_equal_i8x8(r5, simde_vld1_s8(test_vec[i].r5));
    simde_test_arm_neon_assert_equal_i8x8(r8, simde_vld1_s8(test_vec[i].r8));
  }
  return 0;
#else
  for (int i = 0 ; i < 8 ; i++) {
    simde_int8x8_t a = simde_test_arm_neon_random_i8x8();
    simde_int8x8_t b = simde_test_arm_neon_random_i8x8();
    simde_int8x8_t r1 = simde_vsri_n_s8(a, b, 1);
    simde_int8x8_t r3 = simde_vsri_n_s8(a, b, 3);
    simde_int8x8_t r5 = simde_vsri_n_s8(a, b, 5);
    simde_int8x8_t r8 = simde_vsri_n_s8(a, b, 8);

    simde_test_arm_neon_write_i8x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i8x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i8x8(2, r1, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i8x8(2, r3, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i8x8(2, r5, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i8x8(2, r8, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vsri_n_s16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    int16_t a[4];
    int16_t b[4];
    int16_t r3[4];
    int16_t r6[4];
    int16_t r10[4];
    int16_t r13[4];
    int16_t r16[4];
  } test_vec[] = {
    { {  INT16_C( 14952),  INT16_C( 15493),  INT16_C( 23525),  INT16_C( 19805) },
      {  INT16_C(   294), -INT16_C( 13220),  INT16_C(   649), -INT16_C( 25787) },
      {  INT16_C(  8228),  INT16_C( 14731),  INT16_C( 16465),  INT16_C( 21352) },
      {  INT16_C( 14340),  INT16_C( 16177),  INT16_C( 22538),  INT16_C( 20077) },
      {  INT16_C( 14912),  INT16_C( 15539),  INT16_C( 23488),  INT16_C( 19814) },
      {  INT16_C( 14952),  INT16_C( 15494),  INT16_C( 23520),  INT16_C( 19804) },
      {  INT16_C( 14952),  INT16_C( 15493),  INT16_C( 23525),  INT16_C( 19805) } },
    { {  INT16_C( 14226), -INT16_C( 12600), -INT16_C(  7394), -INT16_C( 14450) },
      { -INT16_C( 10041),  INT16_C( 13441),  INT16_C( 29548), -INT16_C( 10840) },
      {  INT16_C( 15128), -INT16_C( 14704), -INT16_C(  4499), -INT16_C(  9547) },
      {  INT16_C( 14179), -INT16_C( 13102), -INT16_C(  7731), -INT16_C( 14506) },
      {  INT16_C( 14262), -INT16_C( 12595), -INT16_C(  7396), -INT16_C( 14411) },
      {  INT16_C( 14230), -INT16_C( 12599), -INT16_C(  7397), -INT16_C( 14450) },
      {  INT16_C( 14226), -INT16_C( 12600), -INT16_C(  7394), -INT16_C( 14450) } },
    { {  INT16_C( 11693), -INT16_C( 27887),  INT16_C( 28296), -INT16_C( 20768) },
      {  INT16_C( 15472), -INT16_C(  1669), -INT16_C( 16322), -INT16_C( 11884) },
      {  INT16_C( 10126), -INT16_C( 24785),  INT16_C( 30727), -INT16_C( 17870) },
      {  INT16_C( 11505), -INT16_C( 27675),  INT16_C( 28416), -INT16_C( 20666) },
      {  INT16_C( 11663), -INT16_C( 27842),  INT16_C( 28336), -INT16_C( 20748) },
      {  INT16_C( 11689), -INT16_C( 27881),  INT16_C( 28302), -INT16_C( 20762) },
      {  INT16_C( 11693), -INT16_C( 27887),  INT16_C( 28296), -INT16_C( 20768) } },
    { {  INT16_C( 23799),  INT16_C(  5535),  INT16_C( 11584),  INT16_C(  2013) },
      {  INT16_C( 24069),  INT16_C( 28987), -INT16_C(  6959),  INT16_C( 32582) },
      {  INT16_C( 19392),  INT16_C(  3623),  INT16_C( 15514),  INT16_C(  4072) },
      {  INT16_C( 23928),  INT16_C(  5572),  INT16_C( 12179),  INT16_C(  1533) },
      {  INT16_C( 23767),  INT16_C(  5532),  INT16_C( 11641),  INT16_C(  2015) },
      {  INT16_C( 23794),  INT16_C(  5531),  INT16_C( 11591),  INT16_C(  2011) },
      {  INT16_C( 23799),  INT16_C(  5535),  INT16_C( 11584),  INT16_C(  2013) } },
    { {  INT16_C( 22545), -INT16_C( 26094), -INT16_C(  3386),  INT16_C( 13896) },
      { -INT16_C( 15569),  INT16_C( 27951), -INT16_C( 15484),  INT16_C( 31550) },
      {  INT16_C( 22629), -INT16_C( 29275), -INT16_C(  1936),  INT16_C( 12135) },
      {  INT16_C( 23308), -INT16_C( 26188), -INT16_C(  3314),  INT16_C( 13804) },
      {  INT16_C( 22576), -INT16_C( 26085), -INT16_C(  3344),  INT16_C( 13918) },
      {  INT16_C( 22550), -INT16_C( 26093), -INT16_C(  3386),  INT16_C( 13899) },
      {  INT16_C( 22545), -INT16_C( 26094), -INT16_C(  3386),  INT16_C( 13896) } },
    { { -INT16_C(  8928),  INT16_C( 24721),  INT16_C( 28170),  INT16_C(  3943) },
      { -INT16_C( 23860), -INT16_C( 24959), -INT16_C( 14458), -INT16_C( 26595) },
      { -INT16_C( 11175),  INT16_C( 29648),  INT16_C( 30960),  INT16_C(  4867) },
      { -INT16_C(  8565),  INT16_C( 25210),  INT16_C( 28446),  INT16_C(  3680) },
      { -INT16_C(  8920),  INT16_C( 24743),  INT16_C( 28209),  INT16_C(  3942) },
      { -INT16_C(  8923),  INT16_C( 24724),  INT16_C( 28174),  INT16_C(  3940) },
      { -INT16_C(  8928),  INT16_C( 24721),  INT16_C( 28170),  INT16_C(  3943) } },
    { {  INT16_C( 12063), -INT16_C(  6606),  INT16_C( 31265),  INT16_C( 20508) },
      {  INT16_C( 19518), -INT16_C( 15682), -INT16_C(  1009),  INT16_C( 12093) },
      {  INT16_C( 10631), -INT16_C(  1961),  INT16_C( 32641),  INT16_C( 17895) },
      {  INT16_C( 11568), -INT16_C(  6390),  INT16_C( 31728),  INT16_C( 20668) },
      {  INT16_C( 12051), -INT16_C(  6608),  INT16_C( 31295),  INT16_C( 20491) },
      {  INT16_C( 12058), -INT16_C(  6602),  INT16_C( 31271),  INT16_C( 20505) },
      {  INT16_C( 12063), -INT16_C(  6606),  INT16_C( 31265),  INT16_C( 20508) } },
    { { -INT16_C( 12582), -INT16_C(  7025), -INT16_C(  2500),  INT16_C(  2548) },
      {  INT16_C( 30105),  INT16_C(  8103), -INT16_C( 15300),  INT16_C( 23735) },
      { -INT16_C( 12621), -INT16_C(  7180), -INT16_C(  1913),  INT16_C(  2966) },
      { -INT16_C( 12842), -INT16_C(  7042), -INT16_C(  2288),  INT16_C(  2418) },
      { -INT16_C( 12579), -INT16_C(  7033), -INT16_C(  2511),  INT16_C(  2519) },
      { -INT16_C( 12581), -INT16_C(  7032), -INT16_C(  2498),  INT16_C(  2546) },
      { -INT16_C( 12582), -INT16_C(  7025), -INT16_C(  2500),  INT16_C(  2548) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x4_t a = simde_vld1_s16(test_vec[i].a);
    simde_int16x4_t b = simde_vld1_s16(test_vec[i].b);

    simde_int16x4_t r3 = simde_vsri_n_s16(a, b, 3);
    simde_int16x4_t r6 = simde_vsri_n_s16(a, b, 6);
    simde_int16x4_t r10 = simde_vsri_n_s16(a, b, 10);
    simde_int16x4_t r13 = simde_vsri_n_s16(a, b, 13);
    simde_int16x4_t r16 = simde_vsri_n_s16(a, b, 16);

    simde_test_arm_neon_assert_equal_i16x4(r3, simde_vld1_s16(test_vec[i].r3));
    simde_test_arm_neon_assert_equal_i16x4(r6, simde_vld1_s16(test_vec[i].r6));
    simde_test_arm_neon_assert_equal_i16x4(r10, simde_vld1_s16(test_vec[i].r10));
    simde_test_arm_neon_assert_equal_i16x4(r13, simde_vld1_s16(test_vec[i].r13));
    simde_test_arm_neon_assert_equal_i16x4(r16, simde_vld1_s16(test_vec[i].r16));
  }
  return 0;
#else
  for (int i = 0 ; i < 8 ; i++) {
    simde_int16x4_t a = simde_test_arm_neon_random_i16x4();
    simde_int16x4_t b = simde_test_arm_neon_random_i16x4();
    simde_int16x4_t r3 = simde_vsri_n_s16(a, b, 3);
    simde_int16x4_t r6 = simde_vsri_n_s16(a, b, 6);
    simde_int16x4_t r10 = simde_vsri_n_s16(a, b, 10);
    simde_int16x4_t r13 = simde_vsri_n_s16(a, b, 13);
    simde_int16x4_t r16 = simde_vsri_n_s16(a, b, 16);

    simde_test_arm_neon_write_i16x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i16x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
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
test_simde_vsri_n_s32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    int32_t a[2];
    int32_t b[2];
    int32_t r6[2];
    int32_t r13[2];
    int32_t r19[2];
    int32_t r26[2];
    int32_t r32[2];
  } test_vec[] = {
    { {  INT32_C(  1758510553), -INT32_C(  1793051611) },
      { -INT32_C(  1014387387),  INT32_C(  1239290189) },
      {  INT32_C(  1796089525), -INT32_C(  1792575419) },
      {  INT32_C(  1758862413), -INT32_C(  1792913680) },
      {  INT32_C(  1758509169), -INT32_C(  1793054405) },
      {  INT32_C(  1758510576), -INT32_C(  1793051630) },
      {  INT32_C(  1758510553), -INT32_C(  1793051611) } },
    { { -INT32_C(  1759344659), -INT32_C(  1544578780) },
      { -INT32_C(   308292702),  INT32_C(  1830665364) },
      { -INT32_C(  1749647538), -INT32_C(  1582008590) },
      { -INT32_C(  1759023874), -INT32_C(  1544853267) },
      { -INT32_C(  1759339085), -INT32_C(  1544581725) },
      { -INT32_C(  1759344645), -INT32_C(  1544578789) },
      { -INT32_C(  1759344659), -INT32_C(  1544578780) } },
    { { -INT32_C(  1613304455),  INT32_C(  1731524129) },
      { -INT32_C(   265634397), -INT32_C(  1153890098) },
      { -INT32_C(  1614763274),  INT32_C(  1726800931) },
      { -INT32_C(  1613266603),  INT32_C(  1731582408) },
      { -INT32_C(  1613300219),  INT32_C(  1731524455) },
      { -INT32_C(  1613304452),  INT32_C(  1731524142) },
      { -INT32_C(  1613304455),  INT32_C(  1731524129) } },
    { { -INT32_C(  1286382705), -INT32_C(  1772666124) },
      { -INT32_C(  1450969579),  INT32_C(   722968754) },
      { -INT32_C(  1297739816), -INT32_C(  1800642942) },
      { -INT32_C(  1286255585), -INT32_C(  1773053763) },
      { -INT32_C(  1286384336), -INT32_C(  1772665502) },
      { -INT32_C(  1286382678), -INT32_C(  1772666166) },
      { -INT32_C(  1286382705), -INT32_C(  1772666124) } },
    { { -INT32_C(  1345655411), -INT32_C(  2045313309) },
      { -INT32_C(  1971961669), -INT32_C(   683299000) },
      { -INT32_C(  1372989182), -INT32_C(  2023942467) },
      { -INT32_C(  1345563726), -INT32_C(  2045330899) },
      { -INT32_C(  1345654450), -INT32_C(  2045314328) },
      { -INT32_C(  1345655390), -INT32_C(  2045313291) },
      { -INT32_C(  1345655411), -INT32_C(  2045313309) } },
    { { -INT32_C(    24406006), -INT32_C(   275455270) },
      { -INT32_C(  1969678376),  INT32_C(  1169535160) },
      { -INT32_C(    30776225), -INT32_C(   317270334) },
      { -INT32_C(    24357688), -INT32_C(   275632723) },
      { -INT32_C(    24407725), -INT32_C(   275453770) },
      { -INT32_C(    24405982), -INT32_C(   275455279) },
      { -INT32_C(    24406006), -INT32_C(   275455270) } },
    { { -INT32_C(  2131459939),  INT32_C(   973474430) },
      { -INT32_C(  1832616886),  INT32_C(   896141611) },
      { -INT32_C(  2109009423),  INT32_C(   953526308) },
      { -INT32_C(  2131454429),  INT32_C(   973187920) },
      { -INT32_C(  2131455400),  INT32_C(   973473453) },
      { -INT32_C(  2131459932),  INT32_C(   973474381) },
      { -INT32_C(  2131459939),  INT32_C(   973474430) } },
    { {  INT32_C(  2083780002), -INT32_C(  1351825449) },
      { -INT32_C(  1774647842),  INT32_C(  1390210741) },
      {  INT32_C(  2119754775), -INT32_C(  1387564102) },
      {  INT32_C(  2083828168), -INT32_C(  1351969049) },
      {  INT32_C(  2083779271), -INT32_C(  1351824805) },
      {  INT32_C(  2083780005), -INT32_C(  1351825452) },
      {  INT32_C(  2083780002), -INT32_C(  1351825449) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x2_t a = simde_vld1_s32(test_vec[i].a);
    simde_int32x2_t b = simde_vld1_s32(test_vec[i].b);

    simde_int32x2_t r6 = simde_vsri_n_s32(a, b, 6);
    simde_int32x2_t r13 = simde_vsri_n_s32(a, b, 13);
    simde_int32x2_t r19 = simde_vsri_n_s32(a, b, 19);
    simde_int32x2_t r26 = simde_vsri_n_s32(a, b, 26);
    simde_int32x2_t r32 = simde_vsri_n_s32(a, b, 32);

    simde_test_arm_neon_assert_equal_i32x2(r6, simde_vld1_s32(test_vec[i].r6));
    simde_test_arm_neon_assert_equal_i32x2(r13, simde_vld1_s32(test_vec[i].r13));
    simde_test_arm_neon_assert_equal_i32x2(r19, simde_vld1_s32(test_vec[i].r19));
    simde_test_arm_neon_assert_equal_i32x2(r26, simde_vld1_s32(test_vec[i].r26));
    simde_test_arm_neon_assert_equal_i32x2(r32, simde_vld1_s32(test_vec[i].r32));
  }
  return 0;
#else
  for (int i = 0 ; i < 8 ; i++) {
    simde_int32x2_t a = simde_test_arm_neon_random_i32x2();
    simde_int32x2_t b = simde_test_arm_neon_random_i32x2();
    simde_int32x2_t r6 = simde_vsri_n_s32(a, b, 6);
    simde_int32x2_t r13 = simde_vsri_n_s32(a, b, 13);
    simde_int32x2_t r19 = simde_vsri_n_s32(a, b, 19);
    simde_int32x2_t r26 = simde_vsri_n_s32(a, b, 26);
    simde_int32x2_t r32 = simde_vsri_n_s32(a, b, 32);

    simde_test_arm_neon_write_i32x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i32x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
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
test_simde_vsri_n_s64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    int64_t a[1];
    int64_t b[1];
    int64_t r13[1];
    int64_t r26[1];
    int64_t r39[1];
    int64_t r52[1];
    int64_t r64[1];
  } test_vec[] = {
    { {  INT64_C( 6541811536121993564) },
      {  INT64_C( 8791746725968987275) },
      {  INT64_C( 6542551670025905326) },
      {  INT64_C( 6541811466908189763) },
      {  INT64_C( 6541811536136242462) },
      {  INT64_C( 6541811536121993120) },
      {  INT64_C( 6541811536121993564) } },
    { {  INT64_C( 1542730604924527419) },
      {  INT64_C( 7849752232625405149) },
      {  INT64_C( 1543441094082479035) },
      {  INT64_C( 1542730654338974774) },
      {  INT64_C( 1542730604927901656) },
      {  INT64_C( 1542730604924528334) },
      {  INT64_C( 1542730604924527419) } },
    { { -INT64_C( 4337578626686252411) },
      {  INT64_C( 3180336222238106263) },
      { -INT64_C( 4338830016334969221) },
      { -INT64_C( 4337578821743756182) },
      { -INT64_C( 4337578626697902683) },
      { -INT64_C( 4337578626686254398) },
      { -INT64_C( 4337578626686252411) } },
    { { -INT64_C( 8675816712871425739) },
      { -INT64_C( 8987409154173890102) },
      { -INT64_C( 8675029978159590664) },
      { -INT64_C( 8675816754534695050) },
      { -INT64_C( 8675816712869344099) },
      { -INT64_C( 8675816712871425996) },
      { -INT64_C( 8675816712871425739) } },
    { { -INT64_C( 4948395904220114856) },
      {  INT64_C( 3045707635243623206) },
      { -INT64_C( 4949084199997357279) },
      { -INT64_C( 4948396015886418618) },
      { -INT64_C( 4948395904230717171) },
      { -INT64_C( 4948395904220114268) },
      { -INT64_C( 4948395904220114856) } },
    { {  INT64_C( 4936024880315312975) },
      { -INT64_C( 8729553677999743143) },
      {  INT64_C( 4937131372066289910) },
      {  INT64_C( 4936024776110590869) },
      {  INT64_C( 4936024880304731338) },
      {  INT64_C( 4936024880315312237) },
      {  INT64_C( 4936024880315312975) } },
    { { -INT64_C( 4929917029557219147) },
      { -INT64_C( 3482101100464309875) },
      { -INT64_C( 4929614853326498145) },
      { -INT64_C( 4929916896108224544) },
      { -INT64_C( 4929917029548336594) },
      { -INT64_C( 4929917029557216006) },
      { -INT64_C( 4929917029557219147) } },
    { { -INT64_C(  144034216185144254) },
      {  INT64_C( 4169541071150587432) },
      { -INT64_C(  143606210894318936) },
      { -INT64_C(  144034311840210731) },
      { -INT64_C(  144034216190690721) },
      { -INT64_C(  144034216185146467) },
      { -INT64_C(  144034216185144254) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int64x1_t a = simde_vld1_s64(test_vec[i].a);
    simde_int64x1_t b = simde_vld1_s64(test_vec[i].b);

    simde_int64x1_t r13 = simde_vsri_n_s64(a, b, 13);
    simde_int64x1_t r26 = simde_vsri_n_s64(a, b, 26);
    simde_int64x1_t r39 = simde_vsri_n_s64(a, b, 39);
    simde_int64x1_t r52 = simde_vsri_n_s64(a, b, 52);
    simde_int64x1_t r64 = simde_vsri_n_s64(a, b, 64);

    simde_test_arm_neon_assert_equal_i64x1(r13, simde_vld1_s64(test_vec[i].r13));
    simde_test_arm_neon_assert_equal_i64x1(r26, simde_vld1_s64(test_vec[i].r26));
    simde_test_arm_neon_assert_equal_i64x1(r39, simde_vld1_s64(test_vec[i].r39));
    simde_test_arm_neon_assert_equal_i64x1(r52, simde_vld1_s64(test_vec[i].r52));
    simde_test_arm_neon_assert_equal_i64x1(r64, simde_vld1_s64(test_vec[i].r64));
  }
  return 0;
#else
  for (int i = 0 ; i < 8 ; i++) {
    simde_int64x1_t a = simde_test_arm_neon_random_i64x1();
    simde_int64x1_t b = simde_test_arm_neon_random_i64x1();
    simde_int64x1_t r13 = simde_vsri_n_s64(a, b, 13);
    simde_int64x1_t r26 = simde_vsri_n_s64(a, b, 26);
    simde_int64x1_t r39 = simde_vsri_n_s64(a, b, 39);
    simde_int64x1_t r52 = simde_vsri_n_s64(a, b, 52);
    simde_int64x1_t r64 = simde_vsri_n_s64(a, b, 64);

    simde_test_arm_neon_write_i64x1(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i64x1(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i64x1(2, r13, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i64x1(2, r26, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i64x1(2, r39, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i64x1(2, r52, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i64x1(2, r64, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vsri_n_u8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    uint8_t a[8];
    uint8_t b[8];
    uint8_t r1[8];
    uint8_t r3[8];
    uint8_t r5[8];
    uint8_t r8[8];
  } test_vec[] = {
    { { UINT8_C( 38), UINT8_C(200), UINT8_C(178), UINT8_C(146), UINT8_C( 54), UINT8_C(237), UINT8_C( 21), UINT8_C( 51) },
      { UINT8_C(146), UINT8_C( 32), UINT8_C(194), UINT8_C(175), UINT8_C(165), UINT8_C( 98), UINT8_C(240), UINT8_C(111) },
      { UINT8_C( 73), UINT8_C(144), UINT8_C(225), UINT8_C(215), UINT8_C( 82), UINT8_C(177), UINT8_C(120), UINT8_C( 55) },
      { UINT8_C( 50), UINT8_C(196), UINT8_C(184), UINT8_C(149), UINT8_C( 52), UINT8_C(236), UINT8_C( 30), UINT8_C( 45) },
      { UINT8_C( 36), UINT8_C(201), UINT8_C(182), UINT8_C(149), UINT8_C( 53), UINT8_C(235), UINT8_C( 23), UINT8_C( 51) },
      { UINT8_C( 38), UINT8_C(200), UINT8_C(178), UINT8_C(146), UINT8_C( 54), UINT8_C(237), UINT8_C( 21), UINT8_C( 51) } },
    { { UINT8_C(112), UINT8_C(201), UINT8_C(148), UINT8_C(  5), UINT8_C( 89), UINT8_C(135), UINT8_C(195), UINT8_C(245) },
      { UINT8_C(180), UINT8_C(126), UINT8_C(124), UINT8_C( 90), UINT8_C(208), UINT8_C(208), UINT8_C(138), UINT8_C(247) },
      { UINT8_C( 90), UINT8_C(191), UINT8_C(190), UINT8_C( 45), UINT8_C(104), UINT8_C(232), UINT8_C(197), UINT8_C(251) },
      { UINT8_C(118), UINT8_C(207), UINT8_C(143), UINT8_C( 11), UINT8_C( 90), UINT8_C(154), UINT8_C(209), UINT8_C(254) },
      { UINT8_C(117), UINT8_C(203), UINT8_C(147), UINT8_C(  2), UINT8_C( 94), UINT8_C(134), UINT8_C(196), UINT8_C(247) },
      { UINT8_C(112), UINT8_C(201), UINT8_C(148), UINT8_C(  5), UINT8_C( 89), UINT8_C(135), UINT8_C(195), UINT8_C(245) } },
    { { UINT8_C(152), UINT8_C( 61), UINT8_C(137), UINT8_C(206), UINT8_C( 42), UINT8_C(158), UINT8_C(  2), UINT8_C(188) },
      { UINT8_C(191), UINT8_C(196), UINT8_C(107), UINT8_C(100), UINT8_C( 38), UINT8_C( 91), UINT8_C(211), UINT8_C(150) },
      { UINT8_C(223), UINT8_C( 98), UINT8_C(181), UINT8_C(178), UINT8_C( 19), UINT8_C(173), UINT8_C(105), UINT8_C(203) },
      { UINT8_C(151), UINT8_C( 56), UINT8_C(141), UINT8_C(204), UINT8_C( 36), UINT8_C(139), UINT8_C( 26), UINT8_C(178) },
      { UINT8_C(157), UINT8_C( 62), UINT8_C(139), UINT8_C(203), UINT8_C( 41), UINT8_C(154), UINT8_C(  6), UINT8_C(188) },
      { UINT8_C(152), UINT8_C( 61), UINT8_C(137), UINT8_C(206), UINT8_C( 42), UINT8_C(158), UINT8_C(  2), UINT8_C(188) } },
    { { UINT8_C( 36), UINT8_C(103), UINT8_C(155), UINT8_C(126), UINT8_C(238), UINT8_C( 94), UINT8_C(115), UINT8_C(162) },
      { UINT8_C(220), UINT8_C(239), UINT8_C(252), UINT8_C(173), UINT8_C(191), UINT8_C(135), UINT8_C(164), UINT8_C( 88) },
      { UINT8_C(110), UINT8_C(119), UINT8_C(254), UINT8_C( 86), UINT8_C(223), UINT8_C( 67), UINT8_C( 82), UINT8_C(172) },
      { UINT8_C( 59), UINT8_C(125), UINT8_C(159), UINT8_C(117), UINT8_C(247), UINT8_C( 80), UINT8_C(116), UINT8_C(171) },
      { UINT8_C( 38), UINT8_C(103), UINT8_C(159), UINT8_C(125), UINT8_C(237), UINT8_C( 92), UINT8_C(117), UINT8_C(162) },
      { UINT8_C( 36), UINT8_C(103), UINT8_C(155), UINT8_C(126), UINT8_C(238), UINT8_C( 94), UINT8_C(115), UINT8_C(162) } },
    { { UINT8_C(196), UINT8_C( 45), UINT8_C( 38), UINT8_C(238), UINT8_C(203), UINT8_C( 40), UINT8_C(170), UINT8_C(138) },
      { UINT8_C(236), UINT8_C( 22), UINT8_C(238), UINT8_C( 18), UINT8_C(113), UINT8_C(193), UINT8_C(168), UINT8_C(150) },
      { UINT8_C(246), UINT8_C( 11), UINT8_C(119), UINT8_C(137), UINT8_C(184), UINT8_C( 96), UINT8_C(212), UINT8_C(203) },
      { UINT8_C(221), UINT8_C( 34), UINT8_C( 61), UINT8_C(226), UINT8_C(206), UINT8_C( 56), UINT8_C(181), UINT8_C(146) },
      { UINT8_C(199), UINT8_C( 40), UINT8_C( 39), UINT8_C(232), UINT8_C(203), UINT8_C( 46), UINT8_C(173), UINT8_C(140) },
      { UINT8_C(196), UINT8_C( 45), UINT8_C( 38), UINT8_C(238), UINT8_C(203), UINT8_C( 40), UINT8_C(170), UINT8_C(138) } },
    { { UINT8_C( 40), UINT8_C( 68), UINT8_C( 20), UINT8_C( 23), UINT8_C(162), UINT8_C(135), UINT8_C(185), UINT8_C(127) },
      { UINT8_C(118), UINT8_C(182), UINT8_C( 44), UINT8_C( 53), UINT8_C( 61), UINT8_C(208), UINT8_C(141), UINT8_C(  1) },
      { UINT8_C( 59), UINT8_C( 91), UINT8_C( 22), UINT8_C( 26), UINT8_C(158), UINT8_C(232), UINT8_C(198), UINT8_C(  0) },
      { UINT8_C( 46), UINT8_C( 86), UINT8_C(  5), UINT8_C(  6), UINT8_C(167), UINT8_C(154), UINT8_C(177), UINT8_C( 96) },
      { UINT8_C( 43), UINT8_C( 69), UINT8_C( 17), UINT8_C( 17), UINT8_C(161), UINT8_C(134), UINT8_C(188), UINT8_C(120) },
      { UINT8_C( 40), UINT8_C( 68), UINT8_C( 20), UINT8_C( 23), UINT8_C(162), UINT8_C(135), UINT8_C(185), UINT8_C(127) } },
    { { UINT8_C(253), UINT8_C(180), UINT8_C(239), UINT8_C(200), UINT8_C(220), UINT8_C(153), UINT8_C( 83), UINT8_C(201) },
      { UINT8_C(175), UINT8_C( 65), UINT8_C(219), UINT8_C( 33), UINT8_C(  3), UINT8_C(132), UINT8_C(183), UINT8_C( 43) },
      { UINT8_C(215), UINT8_C(160), UINT8_C(237), UINT8_C(144), UINT8_C(129), UINT8_C(194), UINT8_C( 91), UINT8_C(149) },
      { UINT8_C(245), UINT8_C(168), UINT8_C(251), UINT8_C(196), UINT8_C(192), UINT8_C(144), UINT8_C( 86), UINT8_C(197) },
      { UINT8_C(253), UINT8_C(178), UINT8_C(238), UINT8_C(201), UINT8_C(216), UINT8_C(156), UINT8_C( 85), UINT8_C(201) },
      { UINT8_C(253), UINT8_C(180), UINT8_C(239), UINT8_C(200), UINT8_C(220), UINT8_C(153), UINT8_C( 83), UINT8_C(201) } },
    { { UINT8_C(200), UINT8_C(203), UINT8_C( 66), UINT8_C(106), UINT8_C( 82), UINT8_C(252), UINT8_C(233), UINT8_C(200) },
      { UINT8_C(178), UINT8_C( 21), UINT8_C(253), UINT8_C(239), UINT8_C(229), UINT8_C(139), UINT8_C(240), UINT8_C(226) },
      { UINT8_C(217), UINT8_C(138), UINT8_C(126), UINT8_C(119), UINT8_C(114), UINT8_C(197), UINT8_C(248), UINT8_C(241) },
      { UINT8_C(214), UINT8_C(194), UINT8_C( 95), UINT8_C(125), UINT8_C( 92), UINT8_C(241), UINT8_C(254), UINT8_C(220) },
      { UINT8_C(205), UINT8_C(200), UINT8_C( 71), UINT8_C(111), UINT8_C( 87), UINT8_C(252), UINT8_C(239), UINT8_C(207) },
      { UINT8_C(200), UINT8_C(203), UINT8_C( 66), UINT8_C(106), UINT8_C( 82), UINT8_C(252), UINT8_C(233), UINT8_C(200) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint8x8_t a = simde_vld1_u8(test_vec[i].a);
    simde_uint8x8_t b = simde_vld1_u8(test_vec[i].b);

    simde_uint8x8_t r1 = simde_vsri_n_u8(a, b, 1);
    simde_uint8x8_t r3 = simde_vsri_n_u8(a, b, 3);
    simde_uint8x8_t r5 = simde_vsri_n_u8(a, b, 5);
    simde_uint8x8_t r8 = simde_vsri_n_u8(a, b, 8);

    simde_test_arm_neon_assert_equal_u8x8(r1, simde_vld1_u8(test_vec[i].r1));
    simde_test_arm_neon_assert_equal_u8x8(r3, simde_vld1_u8(test_vec[i].r3));
    simde_test_arm_neon_assert_equal_u8x8(r5, simde_vld1_u8(test_vec[i].r5));
    simde_test_arm_neon_assert_equal_u8x8(r8, simde_vld1_u8(test_vec[i].r8));
  }
  return 0;
#else
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint8x8_t a = simde_test_arm_neon_random_u8x8();
    simde_uint8x8_t b = simde_test_arm_neon_random_u8x8();
    simde_uint8x8_t r1 = simde_vsri_n_u8(a, b, 1);
    simde_uint8x8_t r3 = simde_vsri_n_u8(a, b, 3);
    simde_uint8x8_t r5 = simde_vsri_n_u8(a, b, 5);
    simde_uint8x8_t r8 = simde_vsri_n_u8(a, b, 8);

    simde_test_arm_neon_write_u8x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u8x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u8x8(2, r1, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u8x8(2, r3, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u8x8(2, r5, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u8x8(2, r8, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vsri_n_u16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    uint16_t a[4];
    uint16_t b[4];
    uint16_t r3[4];
    uint16_t r6[4];
    uint16_t r10[4];
    uint16_t r13[4];
    uint16_t r16[4];
  } test_vec[] = {
    { { UINT16_C(55040), UINT16_C( 1880), UINT16_C( 2015), UINT16_C(19781) },
      { UINT16_C(60444), UINT16_C( 3065), UINT16_C(25249), UINT16_C(15013) },
      { UINT16_C(56707), UINT16_C(  383), UINT16_C( 3156), UINT16_C(18260) },
      { UINT16_C(55216), UINT16_C( 1071), UINT16_C( 1418), UINT16_C(19690) },
      { UINT16_C(55099), UINT16_C( 1858), UINT16_C( 2008), UINT16_C(19790) },
      { UINT16_C(55047), UINT16_C( 1880), UINT16_C( 2011), UINT16_C(19777) },
      { UINT16_C(55040), UINT16_C( 1880), UINT16_C( 2015), UINT16_C(19781) } },
    { { UINT16_C(37479), UINT16_C(62916), UINT16_C(17723), UINT16_C( 4921) },
      { UINT16_C(64640), UINT16_C(46068), UINT16_C(62262), UINT16_C(13947) },
      { UINT16_C(40848), UINT16_C(63102), UINT16_C(24166), UINT16_C( 1743) },
      { UINT16_C(37874), UINT16_C(63183), UINT16_C(18380), UINT16_C( 4313) },
      { UINT16_C(37503), UINT16_C(62956), UINT16_C(17724), UINT16_C( 4877) },
      { UINT16_C(37479), UINT16_C(62917), UINT16_C(17727), UINT16_C( 4921) },
      { UINT16_C(37479), UINT16_C(62916), UINT16_C(17723), UINT16_C( 4921) } },
    { { UINT16_C(54218), UINT16_C(43582), UINT16_C(33754), UINT16_C(63223) },
      { UINT16_C(61551), UINT16_C( 4354), UINT16_C(42834), UINT16_C(47691) },
      { UINT16_C(56845), UINT16_C(41504), UINT16_C(38122), UINT16_C(63305) },
      { UINT16_C(54209), UINT16_C(43076), UINT16_C(33437), UINT16_C(63209) },
      { UINT16_C(54268), UINT16_C(43524), UINT16_C(33769), UINT16_C(63214) },
      { UINT16_C(54223), UINT16_C(43576), UINT16_C(33757), UINT16_C(63221) },
      { UINT16_C(54218), UINT16_C(43582), UINT16_C(33754), UINT16_C(63223) } },
    { { UINT16_C( 4153), UINT16_C(29871), UINT16_C(59477), UINT16_C(54664) },
      { UINT16_C(31973), UINT16_C( 7048), UINT16_C( 1135), UINT16_C(14674) },
      { UINT16_C( 3996), UINT16_C(25457), UINT16_C(57485), UINT16_C(50986) },
      { UINT16_C( 4595), UINT16_C(29806), UINT16_C(59409), UINT16_C(54501) },
      { UINT16_C( 4127), UINT16_C(29830), UINT16_C(59457), UINT16_C(54670) },
      { UINT16_C( 4155), UINT16_C(29864), UINT16_C(59472), UINT16_C(54665) },
      { UINT16_C( 4153), UINT16_C(29871), UINT16_C(59477), UINT16_C(54664) } },
    { { UINT16_C(37079), UINT16_C(45795), UINT16_C(55827), UINT16_C(33448) },
      { UINT16_C(43723), UINT16_C( 7571), UINT16_C(57170), UINT16_C(35799) },
      { UINT16_C(38233), UINT16_C(41906), UINT16_C(56298), UINT16_C(37242) },
      { UINT16_C(37547), UINT16_C(45174), UINT16_C(56189), UINT16_C(33327) },
      { UINT16_C(37098), UINT16_C(45767), UINT16_C(55863), UINT16_C(33442) },
      { UINT16_C(37077), UINT16_C(45792), UINT16_C(55830), UINT16_C(33452) },
      { UINT16_C(37079), UINT16_C(45795), UINT16_C(55827), UINT16_C(33448) } },
    { { UINT16_C(34799), UINT16_C(17408), UINT16_C(34927), UINT16_C(21529) },
      { UINT16_C(41220), UINT16_C(29552), UINT16_C(49829), UINT16_C(32172) },
      { UINT16_C(37920), UINT16_C(20078), UINT16_C(38996), UINT16_C(20405) },
      { UINT16_C(34436), UINT16_C(17869), UINT16_C(35594), UINT16_C(22006) },
      { UINT16_C(34792), UINT16_C(17436), UINT16_C(34928), UINT16_C(21535) },
      { UINT16_C(34797), UINT16_C(17411), UINT16_C(34926), UINT16_C(21531) },
      { UINT16_C(34799), UINT16_C(17408), UINT16_C(34927), UINT16_C(21529) } },
    { { UINT16_C(36946), UINT16_C(25903), UINT16_C(55146), UINT16_C(13799) },
      { UINT16_C(31618), UINT16_C(54355), UINT16_C(10842), UINT16_C(18783) },
      { UINT16_C(36720), UINT16_C(31370), UINT16_C(50507), UINT16_C(10539) },
      { UINT16_C(37358), UINT16_C(26449), UINT16_C(54441), UINT16_C(13605) },
      { UINT16_C(36958), UINT16_C(25909), UINT16_C(55114), UINT16_C(13778) },
      { UINT16_C(36947), UINT16_C(25902), UINT16_C(55145), UINT16_C(13794) },
      { UINT16_C(36946), UINT16_C(25903), UINT16_C(55146), UINT16_C(13799) } },
    { { UINT16_C(24497), UINT16_C( 8589), UINT16_C(42727), UINT16_C(60277) },
      { UINT16_C(58695), UINT16_C(60766), UINT16_C( 2983), UINT16_C(63850) },
      { UINT16_C(23720), UINT16_C(15787), UINT16_C(41332), UINT16_C(65325) },
      { UINT16_C(24469), UINT16_C( 9141), UINT16_C(42030), UINT16_C(60389) },
      { UINT16_C(24505), UINT16_C( 8635), UINT16_C(42690), UINT16_C(60286) },
      { UINT16_C(24503), UINT16_C( 8591), UINT16_C(42720), UINT16_C(60279) },
      { UINT16_C(24497), UINT16_C( 8589), UINT16_C(42727), UINT16_C(60277) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint16x4_t a = simde_vld1_u16(test_vec[i].a);
    simde_uint16x4_t b = simde_vld1_u16(test_vec[i].b);

    simde_uint16x4_t r3 = simde_vsri_n_u16(a, b, 3);
    simde_uint16x4_t r6 = simde_vsri_n_u16(a, b, 6);
    simde_uint16x4_t r10 = simde_vsri_n_u16(a, b, 10);
    simde_uint16x4_t r13 = simde_vsri_n_u16(a, b, 13);
    simde_uint16x4_t r16 = simde_vsri_n_u16(a, b, 16);

    simde_test_arm_neon_assert_equal_u16x4(r3, simde_vld1_u16(test_vec[i].r3));
    simde_test_arm_neon_assert_equal_u16x4(r6, simde_vld1_u16(test_vec[i].r6));
    simde_test_arm_neon_assert_equal_u16x4(r10, simde_vld1_u16(test_vec[i].r10));
    simde_test_arm_neon_assert_equal_u16x4(r13, simde_vld1_u16(test_vec[i].r13));
    simde_test_arm_neon_assert_equal_u16x4(r16, simde_vld1_u16(test_vec[i].r16));
  }
  return 0;
#else
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint16x4_t a = simde_test_arm_neon_random_u16x4();
    simde_uint16x4_t b = simde_test_arm_neon_random_u16x4();
    simde_uint16x4_t r3 = simde_vsri_n_u16(a, b, 3);
    simde_uint16x4_t r6 = simde_vsri_n_u16(a, b, 6);
    simde_uint16x4_t r10 = simde_vsri_n_u16(a, b, 10);
    simde_uint16x4_t r13 = simde_vsri_n_u16(a, b, 13);
    simde_uint16x4_t r16 = simde_vsri_n_u16(a, b, 16);

    simde_test_arm_neon_write_u16x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u16x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
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
test_simde_vsri_n_u32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    uint32_t a[2];
    uint32_t b[2];
    uint32_t r6[2];
    uint32_t r13[2];
    uint32_t r19[2];
    uint32_t r26[2];
    uint32_t r32[2];
  } test_vec[] = {
    { { UINT32_C(1477947539), UINT32_C( 585870188) },
      { UINT32_C(2654228731), UINT32_C(3050175411) },
      { UINT32_C(1517867331), UINT32_C( 584529902) },
      { UINT32_C(1477767586), UINT32_C( 586002031) },
      { UINT32_C(1477948358), UINT32_C( 585873081) },
      { UINT32_C(1477947559), UINT32_C( 585870189) },
      { UINT32_C(1477947539), UINT32_C( 585870188) } },
    { { UINT32_C(1373028245), UINT32_C(1748496598) },
      { UINT32_C(2748917309), UINT32_C(2265457139) },
      { UINT32_C(1385129112), UINT32_C(1780228231) },
      { UINT32_C(1372921545), UINT32_C(1748252737) },
      { UINT32_C(1373025403), UINT32_C(1748496609) },
      { UINT32_C(1373028264), UINT32_C(1748496609) },
      { UINT32_C(1373028245), UINT32_C(1748496598) } },
    { { UINT32_C(1054810322), UINT32_C(3345075147) },
      { UINT32_C(3462763803), UINT32_C( 646132369) },
      { UINT32_C(1060738644), UINT32_C(3298430154) },
      { UINT32_C(1054765868), UINT32_C(3345036313) },
      { UINT32_C(1054816716), UINT32_C(3345073360) },
      { UINT32_C(1054810355), UINT32_C(3345075145) },
      { UINT32_C(1054810322), UINT32_C(3345075147) } },
    { { UINT32_C(3363265010), UINT32_C(2251402825) },
      { UINT32_C(3358132949), UINT32_C(4249825835) },
      { UINT32_C(3407914027), UINT32_C(2280996040) },
      { UINT32_C(3363193160), UINT32_C(2251811449) },
      { UINT32_C(3363264773), UINT32_C(2251407273) },
      { UINT32_C(3363265010), UINT32_C(2251402879) },
      { UINT32_C(3363265010), UINT32_C(2251402825) } },
    { { UINT32_C( 490483538), UINT32_C( 367304186) },
      { UINT32_C(3286452786), UINT32_C(1860789884) },
      { UINT32_C( 521112872), UINT32_C( 364619161) },
      { UINT32_C( 490610458), UINT32_C( 367228747) },
      { UINT32_C( 490485884), UINT32_C( 367300061) },
      { UINT32_C( 490483568), UINT32_C( 367304155) },
      { UINT32_C( 490483538), UINT32_C( 367304186) } },
    { { UINT32_C( 137847231), UINT32_C(3834603535) },
      { UINT32_C(2645407858), UINT32_C(1016855786) },
      { UINT32_C( 175552225), UINT32_C(3841093619) },
      { UINT32_C( 137686381), UINT32_C(3834242271) },
      { UINT32_C( 137851829), UINT32_C(3834603411) },
      { UINT32_C( 137847207), UINT32_C(3834603535) },
      { UINT32_C( 137847231), UINT32_C(3834603535) } },
    { { UINT32_C( 626710315), UINT32_C(2788834932) },
      { UINT32_C(  90840456), UINT32_C(1114854275) },
      { UINT32_C( 605399158), UINT32_C(2768883022) },
      { UINT32_C( 626535248), UINT32_C(2788823962) },
      { UINT32_C( 626704557), UINT32_C(2788829262) },
      { UINT32_C( 626710273), UINT32_C(2788834896) },
      { UINT32_C( 626710315), UINT32_C(2788834932) } },
    { { UINT32_C(3293293236), UINT32_C(2225658386) },
      { UINT32_C(2099402130), UINT32_C(2109324626) },
      { UINT32_C(3321137494), UINT32_C(2247550709) },
      { UINT32_C(3293309202), UINT32_C(2225860045) },
      { UINT32_C(3293294500), UINT32_C(2225655735) },
      { UINT32_C(3293293215), UINT32_C(2225658399) },
      { UINT32_C(3293293236), UINT32_C(2225658386) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint32x2_t a = simde_vld1_u32(test_vec[i].a);
    simde_uint32x2_t b = simde_vld1_u32(test_vec[i].b);

    simde_uint32x2_t r6 = simde_vsri_n_u32(a, b, 6);
    simde_uint32x2_t r13 = simde_vsri_n_u32(a, b, 13);
    simde_uint32x2_t r19 = simde_vsri_n_u32(a, b, 19);
    simde_uint32x2_t r26 = simde_vsri_n_u32(a, b, 26);
    simde_uint32x2_t r32 = simde_vsri_n_u32(a, b, 32);

    simde_test_arm_neon_assert_equal_u32x2(r6, simde_vld1_u32(test_vec[i].r6));
    simde_test_arm_neon_assert_equal_u32x2(r13, simde_vld1_u32(test_vec[i].r13));
    simde_test_arm_neon_assert_equal_u32x2(r19, simde_vld1_u32(test_vec[i].r19));
    simde_test_arm_neon_assert_equal_u32x2(r26, simde_vld1_u32(test_vec[i].r26));
    simde_test_arm_neon_assert_equal_u32x2(r32, simde_vld1_u32(test_vec[i].r32));
  }
  return 0;
#else
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint32x2_t a = simde_test_arm_neon_random_u32x2();
    simde_uint32x2_t b = simde_test_arm_neon_random_u32x2();
    simde_uint32x2_t r6 = simde_vsri_n_u32(a, b, 6);
    simde_uint32x2_t r13 = simde_vsri_n_u32(a, b, 13);
    simde_uint32x2_t r19 = simde_vsri_n_u32(a, b, 19);
    simde_uint32x2_t r26 = simde_vsri_n_u32(a, b, 26);
    simde_uint32x2_t r32 = simde_vsri_n_u32(a, b, 32);

    simde_test_arm_neon_write_u32x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u32x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
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
test_simde_vsri_n_u64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    uint64_t a[1];
    uint64_t b[1];
    uint64_t r13[1];
    uint64_t r26[1];
    uint64_t r39[1];
    uint64_t r52[1];
    uint64_t r64[1];
  } test_vec[] = {
    { { UINT64_C( 8118597999197857303) },
      { UINT64_C( 6700592405235548485) },
      { UINT64_C( 8118556271744161270) },
      { UINT64_C( 8118597971396940452) },
      { UINT64_C( 8118597999203580562) },
      { UINT64_C( 8118597999197857231) },
      { UINT64_C( 8118597999197857303) } },
    { { UINT64_C( 5437571887890467294) },
      { UINT64_C( 2299076651735266132) },
      { UINT64_C( 5436125399241527449) },
      { UINT64_C( 5437571842384429608) },
      { UINT64_C( 5437571887888584684) },
      { UINT64_C( 5437571887890465278) },
      { UINT64_C( 5437571887890467294) } },
    { { UINT64_C(11306711651708258716) },
      { UINT64_C(14981836526368827203) },
      { UINT64_C(11308115701980227965) },
      { UINT64_C(11306711774126619747) },
      { UINT64_C(11306711651704624217) },
      { UINT64_C(11306711651708259582) },
      { UINT64_C(11306711651708258716) } },
    { { UINT64_C(13606175367699187381) },
      { UINT64_C( 8661343315588736267) },
      { UINT64_C(13606431767171472119) },
      { UINT64_C(13606175322693269188) },
      { UINT64_C(13606175367691789963) },
      { UINT64_C(13606175367699187587) },
      { UINT64_C(13606175367699187381) } },
    { { UINT64_C(15024812709372824207) },
      { UINT64_C(10539347668937650562) },
      { UINT64_C(15025294898371468021) },
      { UINT64_C(15024812806712211292) },
      { UINT64_C(15024812709376198289) },
      { UINT64_C(15024812709372823844) },
      { UINT64_C(15024812709372824207) } },
    { { UINT64_C( 9850194256950043790) },
      { UINT64_C(16511549005505433808) },
      { UINT64_C( 9851387955006235864) },
      { UINT64_C( 9850194241164383659) },
      { UINT64_C( 9850194256978397596) },
      { UINT64_C( 9850194256950046290) },
      { UINT64_C( 9850194256950043790) } },
    { { UINT64_C( 8301908658016163289) },
      { UINT64_C( 7669394719010886911) },
      { UINT64_C( 8301070318653859636) },
      { UINT64_C( 8301908564416034615) },
      { UINT64_C( 8301908658016804435) },
      { UINT64_C( 8301908658016163494) },
      { UINT64_C( 8301908658016163289) } },
    { { UINT64_C( 4959046430361684174) },
      { UINT64_C( 1539690372583681571) },
      { UINT64_C( 4958651140219850627) },
      { UINT64_C( 4959046228718718750) },
      { UINT64_C( 4959046430358158376) },
      { UINT64_C( 4959046430361682261) },
      { UINT64_C( 4959046430361684174) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint64x1_t a = simde_vld1_u64(test_vec[i].a);
    simde_uint64x1_t b = simde_vld1_u64(test_vec[i].b);

    simde_uint64x1_t r13 = simde_vsri_n_u64(a, b, 13);
    simde_uint64x1_t r26 = simde_vsri_n_u64(a, b, 26);
    simde_uint64x1_t r39 = simde_vsri_n_u64(a, b, 39);
    simde_uint64x1_t r52 = simde_vsri_n_u64(a, b, 52);
    simde_uint64x1_t r64 = simde_vsri_n_u64(a, b, 64);

    simde_test_arm_neon_assert_equal_u64x1(r13, simde_vld1_u64(test_vec[i].r13));
    simde_test_arm_neon_assert_equal_u64x1(r26, simde_vld1_u64(test_vec[i].r26));
    simde_test_arm_neon_assert_equal_u64x1(r39, simde_vld1_u64(test_vec[i].r39));
    simde_test_arm_neon_assert_equal_u64x1(r52, simde_vld1_u64(test_vec[i].r52));
    simde_test_arm_neon_assert_equal_u64x1(r64, simde_vld1_u64(test_vec[i].r64));
  }
  return 0;
#else
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint64x1_t a = simde_test_arm_neon_random_u64x1();
    simde_uint64x1_t b = simde_test_arm_neon_random_u64x1();
    simde_uint64x1_t r13 = simde_vsri_n_u64(a, b, 13);
    simde_uint64x1_t r26 = simde_vsri_n_u64(a, b, 26);
    simde_uint64x1_t r39 = simde_vsri_n_u64(a, b, 39);
    simde_uint64x1_t r52 = simde_vsri_n_u64(a, b, 52);
    simde_uint64x1_t r64 = simde_vsri_n_u64(a, b, 64);

    simde_test_arm_neon_write_u64x1(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u64x1(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u64x1(2, r13, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u64x1(2, r26, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u64x1(2, r39, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u64x1(2, r52, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u64x1(2, r64, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(vsri_n_s8)
SIMDE_TEST_FUNC_LIST_ENTRY(vsri_n_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vsri_n_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vsri_n_s64)
SIMDE_TEST_FUNC_LIST_ENTRY(vsri_n_u8)
SIMDE_TEST_FUNC_LIST_ENTRY(vsri_n_u16)
SIMDE_TEST_FUNC_LIST_ENTRY(vsri_n_u32)
SIMDE_TEST_FUNC_LIST_ENTRY(vsri_n_u64)
SIMDE_TEST_FUNC_LIST_END

#include <test/arm/neon/test-neon-footer.h>
