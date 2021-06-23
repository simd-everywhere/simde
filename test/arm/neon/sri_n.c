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

static int
test_simde_vsriq_n_s8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    int8_t a[16];
    int8_t b[16];
    int8_t r1[16];
    int8_t r3[16];
    int8_t r5[16];
    int8_t r8[16];
  } test_vec[] = {
    { { -INT8_C(  76), -INT8_C(  56), -INT8_C( 103), -INT8_C(  71),  INT8_C(  73), -INT8_C(  46),  INT8_C(  41),  INT8_C(  93),
        -INT8_C(  63), -INT8_C(  61), -INT8_C(  64), -INT8_C(  57), -INT8_C( 108),  INT8_C( 117), -INT8_C(  40), -INT8_C(  40) },
      { -INT8_C(  88), -INT8_C(  16),  INT8_C(   7),  INT8_C(  87), -INT8_C(  75),  INT8_C(   1),  INT8_C(  35), -INT8_C( 113),
         INT8_C( 104), -INT8_C(  82),  INT8_C(  51),  INT8_C(  17),  INT8_C(  72),  INT8_C(  62), -INT8_C(  57), -INT8_C(   4) },
      { -INT8_C(  44), -INT8_C(   8), -INT8_C( 125), -INT8_C(  85),  INT8_C(  90),      INT8_MIN,  INT8_C(  17),  INT8_C(  71),
        -INT8_C(  76), -INT8_C(  41), -INT8_C( 103), -INT8_C( 120), -INT8_C(  92),  INT8_C(  31), -INT8_C(  29), -INT8_C(   2) },
      { -INT8_C(  75), -INT8_C(  34),      INT8_MIN, -INT8_C(  86),  INT8_C(  86), -INT8_C(  64),  INT8_C(  36),  INT8_C(  81),
        -INT8_C(  51), -INT8_C(  43), -INT8_C(  58), -INT8_C(  62), -INT8_C( 119),  INT8_C( 103), -INT8_C(  40), -INT8_C(  33) },
      { -INT8_C(  75), -INT8_C(  49), -INT8_C( 104), -INT8_C(  70),  INT8_C(  77), -INT8_C(  48),  INT8_C(  41),  INT8_C(  92),
        -INT8_C(  61), -INT8_C(  59), -INT8_C(  63), -INT8_C(  64), -INT8_C( 110),  INT8_C( 113), -INT8_C(  34), -INT8_C(  33) },
      { -INT8_C(  76), -INT8_C(  56), -INT8_C( 103), -INT8_C(  71),  INT8_C(  73), -INT8_C(  46),  INT8_C(  41),  INT8_C(  93),
        -INT8_C(  63), -INT8_C(  61), -INT8_C(  64), -INT8_C(  57), -INT8_C( 108),  INT8_C( 117), -INT8_C(  40), -INT8_C(  40) } },
    { {  INT8_C(   6),  INT8_C(  96), -INT8_C(  75),  INT8_C(  80),  INT8_C(  50), -INT8_C(  33), -INT8_C(  83), -INT8_C(  13),
        -INT8_C(  94),  INT8_C( 109), -INT8_C(  70),  INT8_C(  55), -INT8_C(  30), -INT8_C( 109),  INT8_C(  15), -INT8_C( 117) },
      { -INT8_C( 125),  INT8_C(  23), -INT8_C(  30),  INT8_C(  57),  INT8_C(  24),  INT8_C(   6), -INT8_C(  56), -INT8_C( 127),
        -INT8_C(  76), -INT8_C(   5), -INT8_C( 110), -INT8_C(   4),  INT8_C(  57),  INT8_C(  89), -INT8_C(   7),  INT8_C(  63) },
      {  INT8_C(  65),  INT8_C(  11), -INT8_C(  15),  INT8_C(  28),  INT8_C(  12), -INT8_C( 125), -INT8_C(  28), -INT8_C(  64),
        -INT8_C(  38),  INT8_C( 125), -INT8_C(  55),  INT8_C( 126), -INT8_C( 100), -INT8_C(  84),  INT8_C( 124), -INT8_C(  97) },
      {  INT8_C(  16),  INT8_C(  98), -INT8_C(  68),  INT8_C(  71),  INT8_C(  35), -INT8_C(  64), -INT8_C(  71), -INT8_C(  16),
        -INT8_C(  74),      INT8_MAX, -INT8_C(  78),  INT8_C(  63), -INT8_C(  25), -INT8_C( 117),  INT8_C(  31), -INT8_C( 121) },
      {  INT8_C(   4),  INT8_C(  96), -INT8_C(  73),  INT8_C(  81),  INT8_C(  48), -INT8_C(  40), -INT8_C(  82), -INT8_C(  12),
        -INT8_C(  91),  INT8_C( 111), -INT8_C(  68),  INT8_C(  55), -INT8_C(  31), -INT8_C( 110),  INT8_C(  15), -INT8_C( 119) },
      {  INT8_C(   6),  INT8_C(  96), -INT8_C(  75),  INT8_C(  80),  INT8_C(  50), -INT8_C(  33), -INT8_C(  83), -INT8_C(  13),
        -INT8_C(  94),  INT8_C( 109), -INT8_C(  70),  INT8_C(  55), -INT8_C(  30), -INT8_C( 109),  INT8_C(  15), -INT8_C( 117) } },
    { { -INT8_C(  71), -INT8_C(  82), -INT8_C( 113), -INT8_C(  21), -INT8_C( 115),  INT8_C(  60), -INT8_C(  34),  INT8_C(  48),
        -INT8_C(  86), -INT8_C( 103),  INT8_C( 103), -INT8_C( 116),  INT8_C(  44),  INT8_C( 118),  INT8_C(  23), -INT8_C(  81) },
      { -INT8_C( 115), -INT8_C(   6), -INT8_C(  24), -INT8_C(  90),  INT8_C(   0), -INT8_C(  80),  INT8_C(  39), -INT8_C(  76),
        -INT8_C(  85), -INT8_C(  71), -INT8_C(  80), -INT8_C(  28),  INT8_C(  18), -INT8_C(  87),  INT8_C(  36), -INT8_C(  53) },
      { -INT8_C(  58), -INT8_C(   3), -INT8_C(  12), -INT8_C(  45),      INT8_MIN,  INT8_C(  88), -INT8_C( 109),  INT8_C(  90),
        -INT8_C(  43), -INT8_C(  36),  INT8_C(  88), -INT8_C(  14),  INT8_C(   9),  INT8_C(  84),  INT8_C(  18), -INT8_C(  27) },
      { -INT8_C(  79), -INT8_C(  65), -INT8_C(  99), -INT8_C(  12),      INT8_MIN,  INT8_C(  54), -INT8_C(  60),  INT8_C(  54),
        -INT8_C(  75), -INT8_C( 105),  INT8_C( 118), -INT8_C( 100),  INT8_C(  34),  INT8_C( 117),  INT8_C(   4), -INT8_C(  71) },
      { -INT8_C(  68), -INT8_C(  81), -INT8_C( 113), -INT8_C(  19), -INT8_C( 120),  INT8_C(  61), -INT8_C(  39),  INT8_C(  53),
        -INT8_C(  83), -INT8_C(  99),  INT8_C( 101), -INT8_C( 113),  INT8_C(  40),  INT8_C( 117),  INT8_C(  17), -INT8_C(  82) },
      { -INT8_C(  71), -INT8_C(  82), -INT8_C( 113), -INT8_C(  21), -INT8_C( 115),  INT8_C(  60), -INT8_C(  34),  INT8_C(  48),
        -INT8_C(  86), -INT8_C( 103),  INT8_C( 103), -INT8_C( 116),  INT8_C(  44),  INT8_C( 118),  INT8_C(  23), -INT8_C(  81) } },
    { {  INT8_C(  88), -INT8_C(  77), -INT8_C(  74), -INT8_C(  27), -INT8_C(  16), -INT8_C( 108),  INT8_C(  21), -INT8_C( 102),
         INT8_C(  45),  INT8_C( 124),  INT8_C(  38),  INT8_C(  89), -INT8_C(  13),  INT8_C(  62),  INT8_C(   9),      INT8_MIN },
      {  INT8_C(  56), -INT8_C(  15),  INT8_C(  38),  INT8_C(  56), -INT8_C(  94),  INT8_C(  77), -INT8_C(  20),  INT8_C(  77),
         INT8_C(   6), -INT8_C( 100),  INT8_C(  50),  INT8_C(  24),  INT8_C(  70),  INT8_C(  86), -INT8_C(  29), -INT8_C(  98) },
      {  INT8_C(  28), -INT8_C(   8), -INT8_C( 109), -INT8_C( 100), -INT8_C(  47), -INT8_C(  90),  INT8_C( 118), -INT8_C(  90),
         INT8_C(   3),  INT8_C(  78),  INT8_C(  25),  INT8_C(  12), -INT8_C(  93),  INT8_C(  43),  INT8_C( 113), -INT8_C(  49) },
      {  INT8_C(  71), -INT8_C(  66), -INT8_C(  92), -INT8_C(  25), -INT8_C(  12), -INT8_C( 119),  INT8_C(  29), -INT8_C( 119),
         INT8_C(  32),  INT8_C( 115),  INT8_C(  38),  INT8_C(  67), -INT8_C(  24),  INT8_C(  42),  INT8_C(  28), -INT8_C( 109) },
      {  INT8_C(  89), -INT8_C(  73), -INT8_C(  79), -INT8_C(  31), -INT8_C(  11), -INT8_C( 110),  INT8_C(  23), -INT8_C( 102),
         INT8_C(  40),  INT8_C( 124),  INT8_C(  33),  INT8_C(  88), -INT8_C(  14),  INT8_C(  58),  INT8_C(  15), -INT8_C( 124) },
      {  INT8_C(  88), -INT8_C(  77), -INT8_C(  74), -INT8_C(  27), -INT8_C(  16), -INT8_C( 108),  INT8_C(  21), -INT8_C( 102),
         INT8_C(  45),  INT8_C( 124),  INT8_C(  38),  INT8_C(  89), -INT8_C(  13),  INT8_C(  62),  INT8_C(   9),      INT8_MIN } },
    { {  INT8_C(   9), -INT8_C( 103), -INT8_C( 125), -INT8_C(   7),  INT8_C(  46), -INT8_C( 103), -INT8_C( 109),  INT8_C(  91),
         INT8_C(  21), -INT8_C(  70), -INT8_C(  75),  INT8_C(   8), -INT8_C(   8), -INT8_C(  66), -INT8_C( 119),  INT8_C(  48) },
      { -INT8_C(  81), -INT8_C(  81),  INT8_C( 104),  INT8_C(  81), -INT8_C(   3),  INT8_C(  84), -INT8_C(  97),  INT8_C(   3),
        -INT8_C(  16), -INT8_C(  47),  INT8_C(  28),  INT8_C(  54),  INT8_C(  39), -INT8_C(   1), -INT8_C(  44),  INT8_C(  48) },
      {  INT8_C(  87), -INT8_C(  41), -INT8_C(  76), -INT8_C(  88),  INT8_C( 126), -INT8_C(  86), -INT8_C(  49),  INT8_C(   1),
         INT8_C( 120), -INT8_C(  24), -INT8_C( 114),  INT8_C(  27), -INT8_C( 109), -INT8_C(   1), -INT8_C(  22),  INT8_C(  24) },
      {  INT8_C(  21), -INT8_C( 107), -INT8_C( 115), -INT8_C(  22),  INT8_C(  63), -INT8_C( 118), -INT8_C( 109),  INT8_C(  64),
         INT8_C(  30), -INT8_C(  70), -INT8_C(  93),  INT8_C(   6), -INT8_C(  28), -INT8_C(  65), -INT8_C( 102),  INT8_C(  38) },
      {  INT8_C(  13), -INT8_C(  99), -INT8_C( 125), -INT8_C(   6),  INT8_C(  47), -INT8_C( 102), -INT8_C( 108),  INT8_C(  88),
         INT8_C(  23), -INT8_C(  66), -INT8_C(  80),  INT8_C(   9), -INT8_C(   7), -INT8_C(  65), -INT8_C( 114),  INT8_C(  49) },
      {  INT8_C(   9), -INT8_C( 103), -INT8_C( 125), -INT8_C(   7),  INT8_C(  46), -INT8_C( 103), -INT8_C( 109),  INT8_C(  91),
         INT8_C(  21), -INT8_C(  70), -INT8_C(  75),  INT8_C(   8), -INT8_C(   8), -INT8_C(  66), -INT8_C( 119),  INT8_C(  48) } },
    { { -INT8_C( 103),  INT8_C(  88),  INT8_C(  42), -INT8_C(  57), -INT8_C(  15), -INT8_C(  67),  INT8_C(  34),  INT8_C(   6),
         INT8_C( 119), -INT8_C(  41),  INT8_C(  15),  INT8_C( 111), -INT8_C( 107), -INT8_C( 104), -INT8_C(  97),  INT8_C(  69) },
      {  INT8_C(  71),  INT8_C(   7), -INT8_C( 106),  INT8_C(  68),  INT8_C(  91),  INT8_C(  53),  INT8_C(  72),  INT8_C(  76),
         INT8_C(   6),  INT8_C( 100), -INT8_C( 126),  INT8_C(  45),  INT8_C(  99),  INT8_C(  87),  INT8_C(  94), -INT8_C(   4) },
      { -INT8_C(  93),  INT8_C(   3),  INT8_C(  75), -INT8_C(  94), -INT8_C(  83), -INT8_C( 102),  INT8_C(  36),  INT8_C(  38),
         INT8_C(   3), -INT8_C(  78),  INT8_C(  65),  INT8_C(  22), -INT8_C(  79), -INT8_C(  85), -INT8_C(  81),  INT8_C( 126) },
      { -INT8_C( 120),  INT8_C(  64),  INT8_C(  50), -INT8_C(  56), -INT8_C(  21), -INT8_C(  90),  INT8_C(  41),  INT8_C(   9),
         INT8_C(  96), -INT8_C(  52),  INT8_C(  16),  INT8_C( 101), -INT8_C( 116), -INT8_C( 118), -INT8_C( 117),  INT8_C(  95) },
      { -INT8_C( 102),  INT8_C(  88),  INT8_C(  44), -INT8_C(  62), -INT8_C(  14), -INT8_C(  71),  INT8_C(  34),  INT8_C(   2),
         INT8_C( 112), -INT8_C(  45),  INT8_C(  12),  INT8_C( 105), -INT8_C( 109), -INT8_C( 102), -INT8_C( 102),  INT8_C(  71) },
      { -INT8_C( 103),  INT8_C(  88),  INT8_C(  42), -INT8_C(  57), -INT8_C(  15), -INT8_C(  67),  INT8_C(  34),  INT8_C(   6),
         INT8_C( 119), -INT8_C(  41),  INT8_C(  15),  INT8_C( 111), -INT8_C( 107), -INT8_C( 104), -INT8_C(  97),  INT8_C(  69) } },
    { { -INT8_C(  81), -INT8_C( 120), -INT8_C(  61), -INT8_C(  96),  INT8_C(  69), -INT8_C(  26), -INT8_C(  90), -INT8_C(  67),
        -INT8_C(  67), -INT8_C(  75),  INT8_C(  44),  INT8_C(  83),  INT8_C(  77), -INT8_C(  52), -INT8_C( 104), -INT8_C( 107) },
      { -INT8_C(  45),  INT8_C(  46), -INT8_C(  39),  INT8_C(  47),  INT8_C( 100),  INT8_C(  33),  INT8_C( 123),  INT8_C( 106),
        -INT8_C( 123), -INT8_C(   3), -INT8_C( 104), -INT8_C(  23),  INT8_C(  84), -INT8_C(  10), -INT8_C(  27),  INT8_C(   3) },
      { -INT8_C(  23), -INT8_C( 105), -INT8_C(  20), -INT8_C( 105),  INT8_C(  50), -INT8_C( 112), -INT8_C(  67), -INT8_C(  75),
        -INT8_C(  62), -INT8_C(   2),  INT8_C(  76),  INT8_C( 116),  INT8_C(  42), -INT8_C(   5), -INT8_C(  14), -INT8_C( 127) },
      { -INT8_C(  70), -INT8_C( 123), -INT8_C(  37), -INT8_C(  91),  INT8_C(  76), -INT8_C(  28), -INT8_C(  81), -INT8_C(  83),
        -INT8_C(  80), -INT8_C(  65),  INT8_C(  51),  INT8_C(  93),  INT8_C(  74), -INT8_C(  34), -INT8_C( 100),      INT8_MIN },
      { -INT8_C(  82), -INT8_C( 119), -INT8_C(  58), -INT8_C(  95),  INT8_C(  67), -INT8_C(  31), -INT8_C(  93), -INT8_C(  69),
        -INT8_C(  68), -INT8_C(  73),  INT8_C(  44),  INT8_C(  87),  INT8_C(  74), -INT8_C(  49), -INT8_C(  97), -INT8_C( 112) },
      { -INT8_C(  81), -INT8_C( 120), -INT8_C(  61), -INT8_C(  96),  INT8_C(  69), -INT8_C(  26), -INT8_C(  90), -INT8_C(  67),
        -INT8_C(  67), -INT8_C(  75),  INT8_C(  44),  INT8_C(  83),  INT8_C(  77), -INT8_C(  52), -INT8_C( 104), -INT8_C( 107) } },
    { {  INT8_C( 126), -INT8_C(  87), -INT8_C(  93), -INT8_C(  61), -INT8_C( 113),  INT8_C(  74),      INT8_MIN,  INT8_C(  76),
        -INT8_C(   1), -INT8_C(  83), -INT8_C(  97),  INT8_C(  77),  INT8_C( 121),  INT8_C(  55), -INT8_C(  30),  INT8_C(  76) },
      {  INT8_C( 102), -INT8_C(  69),  INT8_C( 123), -INT8_C(  54), -INT8_C(  35), -INT8_C(  10),  INT8_C(  52),  INT8_C(  98),
        -INT8_C(  12), -INT8_C(  52),  INT8_C(  75),  INT8_C(  72), -INT8_C(  62),  INT8_C(  49),  INT8_C(  76),  INT8_C(  64) },
      {  INT8_C(  51), -INT8_C(  35), -INT8_C(  67), -INT8_C(  27), -INT8_C(  18),  INT8_C( 123), -INT8_C( 102),  INT8_C(  49),
        -INT8_C(   6), -INT8_C(  26), -INT8_C(  91),  INT8_C(  36),  INT8_C(  97),  INT8_C(  24), -INT8_C(  90),  INT8_C(  32) },
      {  INT8_C( 108), -INT8_C(  73), -INT8_C(  81), -INT8_C(  39), -INT8_C( 101),  INT8_C(  94), -INT8_C( 122),  INT8_C(  76),
        -INT8_C(   2), -INT8_C(  71), -INT8_C( 119),  INT8_C(  73),  INT8_C( 120),  INT8_C(  38), -INT8_C(  23),  INT8_C(  72) },
      {  INT8_C( 123), -INT8_C(  83), -INT8_C(  93), -INT8_C(  58), -INT8_C( 114),  INT8_C(  79), -INT8_C( 127),  INT8_C(  75),
        -INT8_C(   1), -INT8_C(  82), -INT8_C( 102),  INT8_C(  74),  INT8_C( 126),  INT8_C(  49), -INT8_C(  30),  INT8_C(  74) },
      {  INT8_C( 126), -INT8_C(  87), -INT8_C(  93), -INT8_C(  61), -INT8_C( 113),  INT8_C(  74),      INT8_MIN,  INT8_C(  76),
        -INT8_C(   1), -INT8_C(  83), -INT8_C(  97),  INT8_C(  77),  INT8_C( 121),  INT8_C(  55), -INT8_C(  30),  INT8_C(  76) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int8x16_t a = simde_vld1q_s8(test_vec[i].a);
    simde_int8x16_t b = simde_vld1q_s8(test_vec[i].b);

    simde_int8x16_t r1 = simde_vsriq_n_s8(a, b, 1);
    simde_int8x16_t r3 = simde_vsriq_n_s8(a, b, 3);
    simde_int8x16_t r5 = simde_vsriq_n_s8(a, b, 5);
    simde_int8x16_t r8 = simde_vsriq_n_s8(a, b, 8);

    simde_test_arm_neon_assert_equal_i8x16(r1, simde_vld1q_s8(test_vec[i].r1));
    simde_test_arm_neon_assert_equal_i8x16(r3, simde_vld1q_s8(test_vec[i].r3));
    simde_test_arm_neon_assert_equal_i8x16(r5, simde_vld1q_s8(test_vec[i].r5));
    simde_test_arm_neon_assert_equal_i8x16(r8, simde_vld1q_s8(test_vec[i].r8));
  }
  return 0;
#else
  for (int i = 0 ; i < 8 ; i++) {
    simde_int8x16_t a = simde_test_arm_neon_random_i8x16();
    simde_int8x16_t b = simde_test_arm_neon_random_i8x16();
    simde_int8x16_t r1 = simde_vsriq_n_s8(a, b, 1);
    simde_int8x16_t r3 = simde_vsriq_n_s8(a, b, 3);
    simde_int8x16_t r5 = simde_vsriq_n_s8(a, b, 5);
    simde_int8x16_t r8 = simde_vsriq_n_s8(a, b, 8);

    simde_test_arm_neon_write_i8x16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i8x16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i8x16(2, r1, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i8x16(2, r3, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i8x16(2, r5, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i8x16(2, r8, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vsriq_n_s16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    int16_t a[8];
    int16_t b[8];
    int16_t r3[8];
    int16_t r6[8];
    int16_t r10[8];
    int16_t r13[8];
    int16_t r16[8];
  } test_vec[] = {
    { { -INT16_C(  4134),  INT16_C( 26884), -INT16_C( 31687),  INT16_C( 14773),  INT16_C( 21809), -INT16_C( 21882),  INT16_C( 26764), -INT16_C(  3337) },
      {  INT16_C( 29219),  INT16_C(   188), -INT16_C(  3735),  INT16_C( 23907), -INT16_C( 20803), -INT16_C( 32603), -INT16_C(  3617), -INT16_C( 17984) },
      { -INT16_C(  4540),  INT16_C( 24599), -INT16_C( 25043),  INT16_C( 11180),  INT16_C( 21975), -INT16_C( 20460),  INT16_C( 32315), -INT16_C(  2248) },
      { -INT16_C(  4664),  INT16_C( 26626), -INT16_C( 30779),  INT16_C( 14709),  INT16_C( 22202), -INT16_C( 22014),  INT16_C( 27591), -INT16_C(  3353) },
      { -INT16_C(  4132),  INT16_C( 26880), -INT16_C( 31684),  INT16_C( 14743),  INT16_C( 21803), -INT16_C( 21856),  INT16_C( 26812), -INT16_C(  3346) },
      { -INT16_C(  4133),  INT16_C( 26880), -INT16_C( 31681),  INT16_C( 14770),  INT16_C( 21813), -INT16_C( 21884),  INT16_C( 26767), -INT16_C(  3339) },
      { -INT16_C(  4134),  INT16_C( 26884), -INT16_C( 31687),  INT16_C( 14773),  INT16_C( 21809), -INT16_C( 21882),  INT16_C( 26764), -INT16_C(  3337) } },
    { { -INT16_C( 15135),  INT16_C(  6690), -INT16_C( 10167),  INT16_C( 31315), -INT16_C(  9939), -INT16_C( 18139),  INT16_C(  7233),  INT16_C( 26028) },
      {  INT16_C( 26766), -INT16_C(  2203), -INT16_C( 14247),  INT16_C(  5972), -INT16_C(  1417),  INT16_C( 22167),  INT16_C( 22507), -INT16_C( 13296) },
      { -INT16_C( 13039),  INT16_C(  7916), -INT16_C(  9973),  INT16_C( 25322), -INT16_C(  8370), -INT16_C( 21806),  INT16_C(  2813),  INT16_C( 31106) },
      { -INT16_C( 14942),  INT16_C(  7133), -INT16_C(  9439),  INT16_C( 30813), -INT16_C(  9239), -INT16_C( 18086),  INT16_C(  7519),  INT16_C( 26416) },
      { -INT16_C( 15142),  INT16_C(  6717), -INT16_C( 10126),  INT16_C( 31301), -INT16_C(  9922), -INT16_C( 18155),  INT16_C(  7253),  INT16_C( 26035) },
      { -INT16_C( 15133),  INT16_C(  6695), -INT16_C( 10162),  INT16_C( 31312), -INT16_C(  9937), -INT16_C( 18142),  INT16_C(  7234),  INT16_C( 26030) },
      { -INT16_C( 15135),  INT16_C(  6690), -INT16_C( 10167),  INT16_C( 31315), -INT16_C(  9939), -INT16_C( 18139),  INT16_C(  7233),  INT16_C( 26028) } },
    { {  INT16_C( 12828),  INT16_C( 26087),  INT16_C( 14858),  INT16_C( 14303),  INT16_C(  1044),  INT16_C( 22001), -INT16_C( 25312), -INT16_C( 20550) },
      {  INT16_C(  8197),  INT16_C( 24486), -INT16_C(  1048),  INT16_C( 24438),  INT16_C(  3573), -INT16_C(  8010), -INT16_C( 14748), -INT16_C( 32595) },
      {  INT16_C(  9216),  INT16_C( 27636),  INT16_C( 16253),  INT16_C( 11246),  INT16_C(   446),  INT16_C( 23574), -INT16_C( 26420), -INT16_C( 20459) },
      {  INT16_C( 12416),  INT16_C( 25982),  INT16_C( 15343),  INT16_C( 13693),  INT16_C(  1079),  INT16_C( 22402), -INT16_C( 24807), -INT16_C( 20990) },
      {  INT16_C( 12808),  INT16_C( 26071),  INT16_C( 14910),  INT16_C( 14295),  INT16_C(  1027),  INT16_C( 22008), -INT16_C( 25295), -INT16_C( 20576) },
      {  INT16_C( 12825),  INT16_C( 26082),  INT16_C( 14863),  INT16_C( 14298),  INT16_C(  1040),  INT16_C( 22007), -INT16_C( 25306), -INT16_C( 20548) },
      {  INT16_C( 12828),  INT16_C( 26087),  INT16_C( 14858),  INT16_C( 14303),  INT16_C(  1044),  INT16_C( 22001), -INT16_C( 25312), -INT16_C( 20550) } },
    { { -INT16_C( 27400),  INT16_C(   997), -INT16_C( 14898), -INT16_C(  7622),  INT16_C( 11209), -INT16_C(  5576), -INT16_C(  3384), -INT16_C( 12647) },
      {  INT16_C( 16146), -INT16_C(  1235), -INT16_C( 23750),  INT16_C( 12122),  INT16_C(  4272),  INT16_C(  5136), -INT16_C( 16938), -INT16_C( 12395) },
      { -INT16_C( 30750),  INT16_C(  8037), -INT16_C( 11161), -INT16_C(  6677),  INT16_C(  8726), -INT16_C(  7550), -INT16_C(  2118), -INT16_C(  9742) },
      { -INT16_C( 27396),  INT16_C(  1004), -INT16_C( 14708), -INT16_C(  8003),  INT16_C( 10306), -INT16_C(  6064), -INT16_C(  3337), -INT16_C( 12482) },
      { -INT16_C( 27441),  INT16_C(  1022), -INT16_C( 14872), -INT16_C(  7669),  INT16_C( 11204), -INT16_C(  5627), -INT16_C(  3345), -INT16_C( 12621) },
      { -INT16_C( 27399),  INT16_C(   999), -INT16_C( 14899), -INT16_C(  7623),  INT16_C( 11208), -INT16_C(  5576), -INT16_C(  3379), -INT16_C( 12642) },
      { -INT16_C( 27400),  INT16_C(   997), -INT16_C( 14898), -INT16_C(  7622),  INT16_C( 11209), -INT16_C(  5576), -INT16_C(  3384), -INT16_C( 12647) } },
    { {  INT16_C( 31313),  INT16_C(  8146),  INT16_C(  3135),  INT16_C(  2306),  INT16_C( 14904),  INT16_C(   243), -INT16_C( 29652),  INT16_C( 16334) },
      { -INT16_C(  1077),  INT16_C(  1594), -INT16_C( 27490),  INT16_C( 20021),  INT16_C( 17829),  INT16_C( 31587), -INT16_C(  2046),  INT16_C( 21322) },
      {  INT16_C( 32633),  INT16_C(   199),  INT16_C(  4755),  INT16_C(  2502),  INT16_C( 10420),  INT16_C(  3948), -INT16_C( 24832),  INT16_C( 10857) },
      {  INT16_C( 31727),  INT16_C(  7192),  INT16_C(  3666),  INT16_C(  2360),  INT16_C( 14614),  INT16_C(   493), -INT16_C( 28704),  INT16_C( 15693) },
      {  INT16_C( 31358),  INT16_C(  8129),  INT16_C(  3109),  INT16_C(  2323),  INT16_C( 14865),  INT16_C(   222), -INT16_C( 29634),  INT16_C( 16340) },
      {  INT16_C( 31319),  INT16_C(  8144),  INT16_C(  3132),  INT16_C(  2306),  INT16_C( 14906),  INT16_C(   243), -INT16_C( 29649),  INT16_C( 16330) },
      {  INT16_C( 31313),  INT16_C(  8146),  INT16_C(  3135),  INT16_C(  2306),  INT16_C( 14904),  INT16_C(   243), -INT16_C( 29652),  INT16_C( 16334) } },
    { {  INT16_C(  7282), -INT16_C( 19853),  INT16_C( 29993),  INT16_C( 25019), -INT16_C( 20817), -INT16_C(  9375),  INT16_C( 12346),  INT16_C(  1306) },
      {  INT16_C( 21547), -INT16_C( 13813),  INT16_C( 16873), -INT16_C( 29160),  INT16_C( 31622), -INT16_C( 30455),  INT16_C( 21619), -INT16_C(  6436) },
      {  INT16_C(  2693), -INT16_C( 18111),  INT16_C( 26685),  INT16_C( 29123), -INT16_C( 20624), -INT16_C( 11999),  INT16_C( 10894),  INT16_C(  7387) },
      {  INT16_C(  7504), -INT16_C( 19672),  INT16_C( 29959),  INT16_C( 25144), -INT16_C( 21010), -INT16_C(  9692),  INT16_C( 12625),  INT16_C(  1947) },
      {  INT16_C(  7253), -INT16_C( 19854),  INT16_C( 29968),  INT16_C( 24995), -INT16_C( 20834), -INT16_C(  9374),  INT16_C( 12309),  INT16_C(  1337) },
      {  INT16_C(  7282), -INT16_C( 19850),  INT16_C( 29994),  INT16_C( 25020), -INT16_C( 20821), -INT16_C(  9372),  INT16_C( 12346),  INT16_C(  1311) },
      {  INT16_C(  7282), -INT16_C( 19853),  INT16_C( 29993),  INT16_C( 25019), -INT16_C( 20817), -INT16_C(  9375),  INT16_C( 12346),  INT16_C(  1306) } },
    { {  INT16_C( 20336), -INT16_C( 26216),  INT16_C( 21444),  INT16_C( 29690),  INT16_C( 23553),  INT16_C( 15183),  INT16_C( 27020), -INT16_C( 18624) },
      {  INT16_C( 19646), -INT16_C( 22655), -INT16_C( 25971),  INT16_C(  4917),  INT16_C( 15893), -INT16_C( 30308),  INT16_C( 31122),  INT16_C(   879) },
      {  INT16_C( 18839), -INT16_C( 27408),  INT16_C( 21329),  INT16_C( 25190),  INT16_C( 18370),  INT16_C( 12595),  INT16_C( 28466), -INT16_C( 24467) },
      {  INT16_C( 19762), -INT16_C( 25954),  INT16_C( 21098),  INT16_C( 28748),  INT16_C( 23800),  INT16_C( 14886),  INT16_C( 27110), -INT16_C( 19443) },
      {  INT16_C( 20307), -INT16_C( 26199),  INT16_C( 21478),  INT16_C( 29636),  INT16_C( 23567),  INT16_C( 15202),  INT16_C( 27038), -INT16_C( 18624) },
      {  INT16_C( 20338), -INT16_C( 26211),  INT16_C( 21444),  INT16_C( 29688),  INT16_C( 23553),  INT16_C( 15180),  INT16_C( 27019), -INT16_C( 18624) },
      {  INT16_C( 20336), -INT16_C( 26216),  INT16_C( 21444),  INT16_C( 29690),  INT16_C( 23553),  INT16_C( 15183),  INT16_C( 27020), -INT16_C( 18624) } },
    { {  INT16_C(  1992), -INT16_C( 29284), -INT16_C( 26790),  INT16_C( 23296),  INT16_C( 20467),  INT16_C( 32662), -INT16_C( 10567),  INT16_C( 30518) },
      { -INT16_C( 18398), -INT16_C( 20706),  INT16_C( 21330),  INT16_C( 26563),  INT16_C( 24465),  INT16_C(  9456),  INT16_C( 24536), -INT16_C( 24281) },
      {  INT16_C(  5892), -INT16_C( 27165), -INT16_C( 30102),  INT16_C( 19704),  INT16_C( 19442),  INT16_C( 25758), -INT16_C( 13317),  INT16_C( 29732) },
      {  INT16_C(  1760), -INT16_C( 28996), -INT16_C( 27315),  INT16_C( 22943),  INT16_C( 19838),  INT16_C( 31891), -INT16_C( 10881),  INT16_C( 30340) },
      {  INT16_C(  2030), -INT16_C( 29269), -INT16_C( 26796),  INT16_C( 23321),  INT16_C( 20439),  INT16_C( 32649), -INT16_C( 10601),  INT16_C( 30504) },
      {  INT16_C(  1997), -INT16_C( 29283), -INT16_C( 26790),  INT16_C( 23299),  INT16_C( 20466),  INT16_C( 32657), -INT16_C( 10566),  INT16_C( 30517) },
      {  INT16_C(  1992), -INT16_C( 29284), -INT16_C( 26790),  INT16_C( 23296),  INT16_C( 20467),  INT16_C( 32662), -INT16_C( 10567),  INT16_C( 30518) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x8_t a = simde_vld1q_s16(test_vec[i].a);
    simde_int16x8_t b = simde_vld1q_s16(test_vec[i].b);

    simde_int16x8_t r3 = simde_vsriq_n_s16(a, b, 3);
    simde_int16x8_t r6 = simde_vsriq_n_s16(a, b, 6);
    simde_int16x8_t r10 = simde_vsriq_n_s16(a, b, 10);
    simde_int16x8_t r13 = simde_vsriq_n_s16(a, b, 13);
    simde_int16x8_t r16 = simde_vsriq_n_s16(a, b, 16);

    simde_test_arm_neon_assert_equal_i16x8(r3, simde_vld1q_s16(test_vec[i].r3));
    simde_test_arm_neon_assert_equal_i16x8(r6, simde_vld1q_s16(test_vec[i].r6));
    simde_test_arm_neon_assert_equal_i16x8(r10, simde_vld1q_s16(test_vec[i].r10));
    simde_test_arm_neon_assert_equal_i16x8(r13, simde_vld1q_s16(test_vec[i].r13));
    simde_test_arm_neon_assert_equal_i16x8(r16, simde_vld1q_s16(test_vec[i].r16));
  }
  return 0;
#else
  for (int i = 0 ; i < 8 ; i++) {
    simde_int16x8_t a = simde_test_arm_neon_random_i16x8();
    simde_int16x8_t b = simde_test_arm_neon_random_i16x8();
    simde_int16x8_t r3 = simde_vsriq_n_s16(a, b, 3);
    simde_int16x8_t r6 = simde_vsriq_n_s16(a, b, 6);
    simde_int16x8_t r10 = simde_vsriq_n_s16(a, b, 10);
    simde_int16x8_t r13 = simde_vsriq_n_s16(a, b, 13);
    simde_int16x8_t r16 = simde_vsriq_n_s16(a, b, 16);

    simde_test_arm_neon_write_i16x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i16x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i16x8(2, r3, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i16x8(2, r6, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i16x8(2, r10, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i16x8(2, r13, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i16x8(2, r16, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vsriq_n_s32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    int32_t a[4];
    int32_t b[4];
    int32_t r6[4];
    int32_t r13[4];
    int32_t r19[4];
    int32_t r26[4];
    int32_t r32[4];
  } test_vec[] = {
    { { -INT32_C(  1070677146),  INT32_C(  1293626970),  INT32_C(   936161662), -INT32_C(  1431436408) },
      {  INT32_C(   224054459), -INT32_C(  1334567649),  INT32_C(  1439982972),  INT32_C(   737606596) },
      { -INT32_C(  1070240974),  INT32_C(  1321324660),  INT32_C(   894914965), -INT32_C(  1464869905) },
      { -INT32_C(  1071093034),  INT32_C(  1293779872),  INT32_C(   936029859), -INT32_C(  1431740489) },
      { -INT32_C(  1070677589),  INT32_C(  1293628942),  INT32_C(   936159930), -INT32_C(  1431435906) },
      { -INT32_C(  1070677181),  INT32_C(  1293626988),  INT32_C(   936161621), -INT32_C(  1431436406) },
      { -INT32_C(  1070677146),  INT32_C(  1293626970),  INT32_C(   936161662), -INT32_C(  1431436408) } },
    { {  INT32_C(   434840767), -INT32_C(   798554286),  INT32_C(  1074213816), -INT32_C(   236210890) },
      { -INT32_C(  1593948799), -INT32_C(   565087390), -INT32_C(  1674369576), -INT32_C(   523818719) },
      {  INT32_C(   444856598), -INT32_C(   747026995),  INT32_C(  1114688663), -INT32_C(   209511260) },
      {  INT32_C(   434964466), -INT32_C(   798559605),  INT32_C(  1074061721), -INT32_C(   235993543) },
      {  INT32_C(   434844703), -INT32_C(   798549046),  INT32_C(  1074213766), -INT32_C(   236209128) },
      {  INT32_C(   434840744), -INT32_C(   798554249),  INT32_C(  1074213799), -INT32_C(   236210888) },
      {  INT32_C(   434840767), -INT32_C(   798554286),  INT32_C(  1074213816), -INT32_C(   236210890) } },
    { { -INT32_C(  1594248371),  INT32_C(  1919967418), -INT32_C(   894207852), -INT32_C(  1346593235) },
      {  INT32_C(  1162853091),  INT32_C(    86220845), -INT32_C(   408791098), -INT32_C(   825792128) },
      { -INT32_C(  1592443157),  INT32_C(  1880395392), -INT32_C(   878802593), -INT32_C(  1355080282) },
      { -INT32_C(  1594217859),  INT32_C(  1919953181), -INT32_C(   893960942), -INT32_C(  1346472389) },
      { -INT32_C(  1594251095),  INT32_C(  1919967396), -INT32_C(   894206732), -INT32_C(  1346594344) },
      { -INT32_C(  1594248367),  INT32_C(  1919967361), -INT32_C(   894207815), -INT32_C(  1346593229) },
      { -INT32_C(  1594248371),  INT32_C(  1919967418), -INT32_C(   894207852), -INT32_C(  1346593235) } },
    { { -INT32_C(   697384932), -INT32_C(  1253450207), -INT32_C(  2071987114),  INT32_C(  2100509594) },
      {  INT32_C(   599950070), -INT32_C(   383130333), -INT32_C(  1110389956),  INT32_C(  1368102708) },
      { -INT32_C(   728823285), -INT32_C(  1213945964), -INT32_C(  2030615764),  INT32_C(  2101751388) },
      { -INT32_C(   697754092), -INT32_C(  1253095089), -INT32_C(  2072121722),  INT32_C(  2100464732) },
      { -INT32_C(   697383816), -INT32_C(  1253450459), -INT32_C(  2071988294),  INT32_C(  2100505137) },
      { -INT32_C(   697384952), -INT32_C(  1253450182), -INT32_C(  2071987089),  INT32_C(  2100509588) },
      { -INT32_C(   697384932), -INT32_C(  1253450207), -INT32_C(  2071987114),  INT32_C(  2100509594) } },
    { {  INT32_C(  2015885655),  INT32_C(   774729943),  INT32_C(   112373100), -INT32_C(   561781272) },
      { -INT32_C(  1979562649),  INT32_C(  1735600939),  INT32_C(   707019766),  INT32_C(   846966746) },
      {  INT32_C(  2049444117),  INT32_C(   765316268),  INT32_C(    78156047), -INT32_C(   590745921) },
      {  INT32_C(  2015645714),  INT32_C(   774585241),  INT32_C(   112283938), -INT32_C(   561933347) },
      {  INT32_C(  2015883584),  INT32_C(   774728942),  INT32_C(   112371012), -INT32_C(   561781169) },
      {  INT32_C(  2015885666),  INT32_C(   774729945),  INT32_C(   112373066), -INT32_C(   561781300) },
      {  INT32_C(  2015885655),  INT32_C(   774729943),  INT32_C(   112373100), -INT32_C(   561781272) } },
    { { -INT32_C(  2136300632), -INT32_C(  2136025069),  INT32_C(  1837523077), -INT32_C(  1404302779) },
      {  INT32_C(  2050444879),  INT32_C(  1877125753), -INT32_C(   929495314),  INT32_C(  1593447862) },
      { -INT32_C(  2115445447), -INT32_C(  2118153559),  INT32_C(  1864524827), -INT32_C(  1384388522) },
      { -INT32_C(  2136223302), -INT32_C(  2136244459),  INT32_C(  1837515976), -INT32_C(  1404373040) },
      { -INT32_C(  2136297658), -INT32_C(  2136027652),  INT32_C(  1837529363), -INT32_C(  1404302369) },
      { -INT32_C(  2136300642), -INT32_C(  2136025061),  INT32_C(  1837523122), -INT32_C(  1404302761) },
      { -INT32_C(  2136300632), -INT32_C(  2136025069),  INT32_C(  1837523077), -INT32_C(  1404302779) } },
    { { -INT32_C(   874601032),  INT32_C(    38505597),  INT32_C(   829412076),  INT32_C(   736017372) },
      { -INT32_C(  2103044855), -INT32_C(  1376679745),  INT32_C(  1148619662),  INT32_C(  1487106208) },
      { -INT32_C(   905275308),  INT32_C(    45598242),  INT32_C(   823253550),  INT32_C(   694324674) },
      { -INT32_C(   874769104),  INT32_C(    38629260),  INT32_C(   829039540),  INT32_C(   735757595) },
      { -INT32_C(   874598316),  INT32_C(    38507966),  INT32_C(   829409422),  INT32_C(   736013076) },
      { -INT32_C(   874601056),  INT32_C(    38505579),  INT32_C(   829412049),  INT32_C(   736017366) },
      { -INT32_C(   874601032),  INT32_C(    38505597),  INT32_C(   829412076),  INT32_C(   736017372) } },
    { { -INT32_C(  1843166955), -INT32_C(    90935538),  INT32_C(   489423937), -INT32_C(   918025537) },
      { -INT32_C(   565449185),  INT32_C(    93076854),  INT32_C(  1749615304), -INT32_C(  2000622478) },
      { -INT32_C(  1820774472), -INT32_C(   132763403),  INT32_C(   497099787), -INT32_C(   903674959) },
      { -INT32_C(  1842941345), -INT32_C(    91214751),  INT32_C(   489374280), -INT32_C(   917748217) },
      { -INT32_C(  1843160119), -INT32_C(    90939215),  INT32_C(   489426185), -INT32_C(   918023912) },
      { -INT32_C(  1843166921), -INT32_C(    90935551),  INT32_C(   489423962), -INT32_C(   918025566) },
      { -INT32_C(  1843166955), -INT32_C(    90935538),  INT32_C(   489423937), -INT32_C(   918025537) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x4_t a = simde_vld1q_s32(test_vec[i].a);
    simde_int32x4_t b = simde_vld1q_s32(test_vec[i].b);

    simde_int32x4_t r6 = simde_vsriq_n_s32(a, b, 6);
    simde_int32x4_t r13 = simde_vsriq_n_s32(a, b, 13);
    simde_int32x4_t r19 = simde_vsriq_n_s32(a, b, 19);
    simde_int32x4_t r26 = simde_vsriq_n_s32(a, b, 26);
    simde_int32x4_t r32 = simde_vsriq_n_s32(a, b, 32);

    simde_test_arm_neon_assert_equal_i32x4(r6, simde_vld1q_s32(test_vec[i].r6));
    simde_test_arm_neon_assert_equal_i32x4(r13, simde_vld1q_s32(test_vec[i].r13));
    simde_test_arm_neon_assert_equal_i32x4(r19, simde_vld1q_s32(test_vec[i].r19));
    simde_test_arm_neon_assert_equal_i32x4(r26, simde_vld1q_s32(test_vec[i].r26));
    simde_test_arm_neon_assert_equal_i32x4(r32, simde_vld1q_s32(test_vec[i].r32));
  }
  return 0;
#else
  for (int i = 0 ; i < 8 ; i++) {
    simde_int32x4_t a = simde_test_arm_neon_random_i32x4();
    simde_int32x4_t b = simde_test_arm_neon_random_i32x4();
    simde_int32x4_t r6 = simde_vsriq_n_s32(a, b, 6);
    simde_int32x4_t r13 = simde_vsriq_n_s32(a, b, 13);
    simde_int32x4_t r19 = simde_vsriq_n_s32(a, b, 19);
    simde_int32x4_t r26 = simde_vsriq_n_s32(a, b, 26);
    simde_int32x4_t r32 = simde_vsriq_n_s32(a, b, 32);

    simde_test_arm_neon_write_i32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i32x4(2, r6, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i32x4(2, r13, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i32x4(2, r19, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i32x4(2, r26, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i32x4(2, r32, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vsriq_n_s64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    int64_t a[2];
    int64_t b[2];
    int64_t r13[2];
    int64_t r26[2];
    int64_t r39[2];
    int64_t r52[2];
    int64_t r64[2];
  } test_vec[] = {
    { { -INT64_C( 7820870934077971602), -INT64_C( 3802170941330382157) },
      { -INT64_C( 8330754668675561497),  INT64_C(  518675479192185912) },
      { -INT64_C( 7821517690754632364), -INT64_C( 3803226570436552795) },
      { -INT64_C( 7820870862729531113), -INT64_C( 3802171124504254870) },
      { -INT64_C( 7820870934061332883), -INT64_C( 3802170941341014679) },
      { -INT64_C( 7820870934077970234), -INT64_C( 3802170941330382733) },
      { -INT64_C( 7820870934077971602), -INT64_C( 3802170941330382157) } },
    { { -INT64_C( 5801205880321782377),  INT64_C( 1014538239360446108) },
      {  INT64_C( 3185399486162452196),  INT64_C( 8294515454573422716) },
      { -INT64_C( 5802499277156170907),  INT64_C( 1014322430251937457) },
      { -INT64_C( 5801206094488142550),  INT64_C( 1014538194244499205) },
      { -INT64_C( 5801205880324593249),  INT64_C( 1014538239373359123) },
      { -INT64_C( 5801205880321785149),  INT64_C( 1014538239360444209) },
      { -INT64_C( 5801205880321782377),  INT64_C( 1014538239360446108) } },
    { {  INT64_C( 3747517812212342614),  INT64_C( 7151313233771307529) },
      { -INT64_C(  689262423620998321), -INT64_C( 6577745513665575577) },
      {  INT64_C( 3749162551306491997),  INT64_C( 7150913260813949018) },
      {  INT64_C( 3747517972358356624),  INT64_C( 7151313139236721552) },
      {  INT64_C( 3747517812238507646),  INT64_C( 7151313233784696398) },
      {  INT64_C( 3747517812212342630),  INT64_C( 7151313233771309643) },
      {  INT64_C( 3747517812212342614),  INT64_C( 7151313233771307529) } },
    { { -INT64_C(  534811323247749946), -INT64_C( 1081594391742115814) },
      { -INT64_C( 5799613462649567214),  INT64_C( 8996972380185399016) },
      { -INT64_C(  534384516471168616), -INT64_C( 1082017447152601188) },
      { -INT64_C(  534811338264243677), -INT64_C( 1081594401980240499) },
      { -INT64_C(  534811323257649340), -INT64_C( 1081594391745153195) },
      { -INT64_C(  534811323247748360), -INT64_C( 1081594391742113843) },
      { -INT64_C(  534811323247749946), -INT64_C( 1081594391742115814) } },
    { { -INT64_C( 2042822468953189954),  INT64_C( 5193065118731915135) },
      { -INT64_C( 3496666982624508542), -INT64_C( 3091473656966648602) },
      { -INT64_C( 2042809270243797342),  INT64_C( 5194524793016475699) },
      { -INT64_C( 2042822287768028686),  INT64_C( 5193065115053213095) },
      { -INT64_C( 2042822468940402001),  INT64_C( 5193065118734889410) },
      { -INT64_C( 2042822468953187081),  INT64_C( 5193065118731914577) },
      { -INT64_C( 2042822468953189954),  INT64_C( 5193065118731915135) } },
    { { -INT64_C( 2135223666076289870), -INT64_C( 2993181451047674888) },
      { -INT64_C( 8642096925759222950), -INT64_C( 6164796801919215738) },
      { -INT64_C( 2135761166845997822), -INT64_C( 2993394491059803872) },
      { -INT64_C( 2135223672371763056), -INT64_C( 2993181354703749593) },
      { -INT64_C( 2135223666083880395), -INT64_C( 2993181451025587077) },
      { -INT64_C( 2135223666076288895), -INT64_C( 2993181451047675225) },
      { -INT64_C( 2135223666076289870), -INT64_C( 2993181451047674888) } },
    { {  INT64_C( 1690683976993666353), -INT64_C( 1618273790695474593) },
      { -INT64_C( 3804913564797752569), -INT64_C( 4254253946838165934) },
      {  INT64_C( 1690637193089730897), -INT64_C( 1617311584334752958) },
      {  INT64_C( 1690684063839342954), -INT64_C( 1618273646659853102) },
      {  INT64_C( 1690683977017746550), -INT64_C( 1618273790674211915) },
      {  INT64_C( 1690683976993668275), -INT64_C( 1618273790695474097) },
      {  INT64_C( 1690683976993666353), -INT64_C( 1618273790695474593) } },
    { { -INT64_C(   70421933348873265),  INT64_C(  991140492612946505) },
      {  INT64_C( 8753283707398777704), -INT64_C( 8388031560296373953) },
      { -INT64_C(   70989077960364609),  INT64_C(  992019788201369127) },
      { -INT64_C(   70421940057519637),  INT64_C(  991140613094010676) },
      { -INT64_C(   70421933338725422),  INT64_C(  991140492619493235) },
      { -INT64_C(   70421933348874345),  INT64_C(  991140492612946105) },
      { -INT64_C(   70421933348873265),  INT64_C(  991140492612946505) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int64x2_t a = simde_vld1q_s64(test_vec[i].a);
    simde_int64x2_t b = simde_vld1q_s64(test_vec[i].b);

    simde_int64x2_t r13 = simde_vsriq_n_s64(a, b, 13);
    simde_int64x2_t r26 = simde_vsriq_n_s64(a, b, 26);
    simde_int64x2_t r39 = simde_vsriq_n_s64(a, b, 39);
    simde_int64x2_t r52 = simde_vsriq_n_s64(a, b, 52);
    simde_int64x2_t r64 = simde_vsriq_n_s64(a, b, 64);

    simde_test_arm_neon_assert_equal_i64x2(r13, simde_vld1q_s64(test_vec[i].r13));
    simde_test_arm_neon_assert_equal_i64x2(r26, simde_vld1q_s64(test_vec[i].r26));
    simde_test_arm_neon_assert_equal_i64x2(r39, simde_vld1q_s64(test_vec[i].r39));
    simde_test_arm_neon_assert_equal_i64x2(r52, simde_vld1q_s64(test_vec[i].r52));
    simde_test_arm_neon_assert_equal_i64x2(r64, simde_vld1q_s64(test_vec[i].r64));
  }
  return 0;
#else
  for (int i = 0 ; i < 8 ; i++) {
    simde_int64x2_t a = simde_test_arm_neon_random_i64x2();
    simde_int64x2_t b = simde_test_arm_neon_random_i64x2();
    simde_int64x2_t r13 = simde_vsriq_n_s64(a, b, 13);
    simde_int64x2_t r26 = simde_vsriq_n_s64(a, b, 26);
    simde_int64x2_t r39 = simde_vsriq_n_s64(a, b, 39);
    simde_int64x2_t r52 = simde_vsriq_n_s64(a, b, 52);
    simde_int64x2_t r64 = simde_vsriq_n_s64(a, b, 64);

    simde_test_arm_neon_write_i64x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i64x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i64x2(2, r13, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i64x2(2, r26, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i64x2(2, r39, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i64x2(2, r52, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i64x2(2, r64, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vsriq_n_u8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    uint8_t a[16];
    uint8_t b[16];
    uint8_t r1[16];
    uint8_t r3[16];
    uint8_t r5[16];
    uint8_t r8[16];
  } test_vec[] = {
    { { UINT8_C(212), UINT8_C(240), UINT8_C(121), UINT8_C(115), UINT8_C(191), UINT8_C(126), UINT8_C(114), UINT8_C(  8),
        UINT8_C(201), UINT8_C( 37), UINT8_C(224), UINT8_C(207), UINT8_C( 99), UINT8_C(161), UINT8_C(221), UINT8_C(203) },
      { UINT8_C(140), UINT8_C(148), UINT8_C(121), UINT8_C(179), UINT8_C(125), UINT8_C(242), UINT8_C( 45), UINT8_C(188),
        UINT8_C(211), UINT8_C(241), UINT8_C(143), UINT8_C(143), UINT8_C(170), UINT8_C( 39), UINT8_C( 27), UINT8_C(126) },
      { UINT8_C(198), UINT8_C(202), UINT8_C( 60), UINT8_C( 89), UINT8_C(190), UINT8_C(121), UINT8_C( 22), UINT8_C( 94),
        UINT8_C(233), UINT8_C(120), UINT8_C(199), UINT8_C(199), UINT8_C( 85), UINT8_C(147), UINT8_C(141), UINT8_C(191) },
      { UINT8_C(209), UINT8_C(242), UINT8_C(111), UINT8_C(118), UINT8_C(175), UINT8_C(126), UINT8_C(101), UINT8_C( 23),
        UINT8_C(218), UINT8_C( 62), UINT8_C(241), UINT8_C(209), UINT8_C(117), UINT8_C(164), UINT8_C(195), UINT8_C(207) },
      { UINT8_C(212), UINT8_C(244), UINT8_C(123), UINT8_C(117), UINT8_C(187), UINT8_C(127), UINT8_C(113), UINT8_C( 13),
        UINT8_C(206), UINT8_C( 39), UINT8_C(228), UINT8_C(204), UINT8_C(101), UINT8_C(161), UINT8_C(216), UINT8_C(203) },
      { UINT8_C(212), UINT8_C(240), UINT8_C(121), UINT8_C(115), UINT8_C(191), UINT8_C(126), UINT8_C(114), UINT8_C(  8),
        UINT8_C(201), UINT8_C( 37), UINT8_C(224), UINT8_C(207), UINT8_C( 99), UINT8_C(161), UINT8_C(221), UINT8_C(203) } },
    { { UINT8_C( 23), UINT8_C(148), UINT8_C(241), UINT8_C(214), UINT8_C( 19), UINT8_C(100), UINT8_C(222), UINT8_C(220),
        UINT8_C(137), UINT8_C(190), UINT8_C(171), UINT8_C(236), UINT8_C( 95), UINT8_C(136), UINT8_C(184), UINT8_C(235) },
      { UINT8_C( 28), UINT8_C( 49), UINT8_C(159), UINT8_C(153), UINT8_C( 35), UINT8_C(204), UINT8_C( 86), UINT8_C(246),
        UINT8_C(189), UINT8_C(229), UINT8_C(134), UINT8_C(103), UINT8_C( 12), UINT8_C(161), UINT8_C(229), UINT8_C( 35) },
      { UINT8_C( 14), UINT8_C(152), UINT8_C(207), UINT8_C(204), UINT8_C( 17), UINT8_C(102), UINT8_C(171), UINT8_C(251),
        UINT8_C(222), UINT8_C(242), UINT8_C(195), UINT8_C(179), UINT8_C(  6), UINT8_C(208), UINT8_C(242), UINT8_C(145) },
      { UINT8_C(  3), UINT8_C(134), UINT8_C(243), UINT8_C(211), UINT8_C(  4), UINT8_C(121), UINT8_C(202), UINT8_C(222),
        UINT8_C(151), UINT8_C(188), UINT8_C(176), UINT8_C(236), UINT8_C( 65), UINT8_C(148), UINT8_C(188), UINT8_C(228) },
      { UINT8_C( 16), UINT8_C(145), UINT8_C(244), UINT8_C(212), UINT8_C( 17), UINT8_C(102), UINT8_C(218), UINT8_C(223),
        UINT8_C(141), UINT8_C(191), UINT8_C(172), UINT8_C(235), UINT8_C( 88), UINT8_C(141), UINT8_C(191), UINT8_C(233) },
      { UINT8_C( 23), UINT8_C(148), UINT8_C(241), UINT8_C(214), UINT8_C( 19), UINT8_C(100), UINT8_C(222), UINT8_C(220),
        UINT8_C(137), UINT8_C(190), UINT8_C(171), UINT8_C(236), UINT8_C( 95), UINT8_C(136), UINT8_C(184), UINT8_C(235) } },
    { { UINT8_C( 53), UINT8_C(214), UINT8_C(249), UINT8_C( 72), UINT8_C( 58), UINT8_C(215), UINT8_C( 36), UINT8_C(196),
        UINT8_C(149), UINT8_C(208), UINT8_C(176), UINT8_C(244), UINT8_C( 88), UINT8_C(104), UINT8_C(224), UINT8_C(117) },
      { UINT8_C(153), UINT8_C(127), UINT8_C( 14), UINT8_C(188), UINT8_C( 75), UINT8_C(100), UINT8_C(179), UINT8_C(  8),
        UINT8_C( 74), UINT8_C( 57), UINT8_C(111), UINT8_C( 86), UINT8_C(218), UINT8_C( 84), UINT8_C(122), UINT8_C( 15) },
      { UINT8_C( 76), UINT8_C(191), UINT8_C(135), UINT8_C( 94), UINT8_C( 37), UINT8_C(178), UINT8_C( 89), UINT8_C(132),
        UINT8_C(165), UINT8_C(156), UINT8_C(183), UINT8_C(171), UINT8_C(109), UINT8_C( 42), UINT8_C(189), UINT8_C(  7) },
      { UINT8_C( 51), UINT8_C(207), UINT8_C(225), UINT8_C( 87), UINT8_C( 41), UINT8_C(204), UINT8_C( 54), UINT8_C(193),
        UINT8_C(137), UINT8_C(199), UINT8_C(173), UINT8_C(234), UINT8_C( 91), UINT8_C(106), UINT8_C(239), UINT8_C( 97) },
      { UINT8_C( 52), UINT8_C(211), UINT8_C(248), UINT8_C( 77), UINT8_C( 58), UINT8_C(211), UINT8_C( 37), UINT8_C(192),
        UINT8_C(146), UINT8_C(209), UINT8_C(179), UINT8_C(242), UINT8_C( 94), UINT8_C(106), UINT8_C(227), UINT8_C(112) },
      { UINT8_C( 53), UINT8_C(214), UINT8_C(249), UINT8_C( 72), UINT8_C( 58), UINT8_C(215), UINT8_C( 36), UINT8_C(196),
        UINT8_C(149), UINT8_C(208), UINT8_C(176), UINT8_C(244), UINT8_C( 88), UINT8_C(104), UINT8_C(224), UINT8_C(117) } },
    { { UINT8_C( 42), UINT8_C(115), UINT8_C( 88), UINT8_C(101), UINT8_C( 75), UINT8_C(124), UINT8_C( 41), UINT8_C(224),
        UINT8_C( 76), UINT8_C(217), UINT8_C(213), UINT8_C(165), UINT8_C( 66), UINT8_C(181), UINT8_C( 26), UINT8_C(219) },
      { UINT8_C( 52), UINT8_C( 40), UINT8_C(152), UINT8_C(127), UINT8_C(141), UINT8_C( 75), UINT8_C(135), UINT8_C(215),
        UINT8_C(132), UINT8_C(246), UINT8_C( 45), UINT8_C( 94), UINT8_C( 74), UINT8_C(167), UINT8_C(109), UINT8_C(116) },
      { UINT8_C( 26), UINT8_C( 20), UINT8_C( 76), UINT8_C( 63), UINT8_C( 70), UINT8_C( 37), UINT8_C( 67), UINT8_C(235),
        UINT8_C( 66), UINT8_C(251), UINT8_C(150), UINT8_C(175), UINT8_C( 37), UINT8_C(211), UINT8_C( 54), UINT8_C(186) },
      { UINT8_C( 38), UINT8_C(101), UINT8_C( 83), UINT8_C(111), UINT8_C( 81), UINT8_C(105), UINT8_C( 48), UINT8_C(250),
        UINT8_C( 80), UINT8_C(222), UINT8_C(197), UINT8_C(171), UINT8_C( 73), UINT8_C(180), UINT8_C( 13), UINT8_C(206) },
      { UINT8_C( 41), UINT8_C(113), UINT8_C( 92), UINT8_C( 99), UINT8_C( 76), UINT8_C(122), UINT8_C( 44), UINT8_C(230),
        UINT8_C( 76), UINT8_C(223), UINT8_C(209), UINT8_C(162), UINT8_C( 66), UINT8_C(181), UINT8_C( 27), UINT8_C(219) },
      { UINT8_C( 42), UINT8_C(115), UINT8_C( 88), UINT8_C(101), UINT8_C( 75), UINT8_C(124), UINT8_C( 41), UINT8_C(224),
        UINT8_C( 76), UINT8_C(217), UINT8_C(213), UINT8_C(165), UINT8_C( 66), UINT8_C(181), UINT8_C( 26), UINT8_C(219) } },
    { { UINT8_C( 27), UINT8_C(197), UINT8_C(217), UINT8_C(102), UINT8_C( 66), UINT8_C(  2), UINT8_C( 70), UINT8_C(142),
        UINT8_C(220), UINT8_C( 27), UINT8_C( 51), UINT8_C( 30), UINT8_C(208), UINT8_C( 77), UINT8_C(249), UINT8_C(  4) },
      { UINT8_C(118), UINT8_C(145), UINT8_C(131), UINT8_C(  3), UINT8_C(220), UINT8_C( 10), UINT8_C(218), UINT8_C( 96),
        UINT8_C(  0), UINT8_C(  7), UINT8_C(190), UINT8_C( 74), UINT8_C(175), UINT8_C( 44), UINT8_C(191), UINT8_C(202) },
      { UINT8_C( 59), UINT8_C(200), UINT8_C(193), UINT8_C(  1), UINT8_C(110), UINT8_C(  5), UINT8_C(109), UINT8_C(176),
        UINT8_C(128), UINT8_C(  3), UINT8_C( 95), UINT8_C( 37), UINT8_C(215), UINT8_C( 22), UINT8_C(223), UINT8_C(101) },
      { UINT8_C( 14), UINT8_C(210), UINT8_C(208), UINT8_C( 96), UINT8_C( 91), UINT8_C(  1), UINT8_C( 91), UINT8_C(140),
        UINT8_C(192), UINT8_C(  0), UINT8_C( 55), UINT8_C(  9), UINT8_C(213), UINT8_C( 69), UINT8_C(247), UINT8_C( 25) },
      { UINT8_C( 27), UINT8_C(196), UINT8_C(220), UINT8_C( 96), UINT8_C( 70), UINT8_C(  0), UINT8_C( 70), UINT8_C(139),
        UINT8_C(216), UINT8_C( 24), UINT8_C( 53), UINT8_C( 26), UINT8_C(213), UINT8_C( 73), UINT8_C(253), UINT8_C(  6) },
      { UINT8_C( 27), UINT8_C(197), UINT8_C(217), UINT8_C(102), UINT8_C( 66), UINT8_C(  2), UINT8_C( 70), UINT8_C(142),
        UINT8_C(220), UINT8_C( 27), UINT8_C( 51), UINT8_C( 30), UINT8_C(208), UINT8_C( 77), UINT8_C(249), UINT8_C(  4) } },
    { { UINT8_C(241), UINT8_C(152), UINT8_C( 48), UINT8_C( 51), UINT8_C(155), UINT8_C(118), UINT8_C(194), UINT8_C(119),
        UINT8_C(146), UINT8_C(245), UINT8_C(149), UINT8_C( 98), UINT8_C( 67), UINT8_C(142), UINT8_C(103), UINT8_C(185) },
      { UINT8_C( 32), UINT8_C(234), UINT8_C(188), UINT8_C(252), UINT8_C(245), UINT8_C(150), UINT8_C( 93), UINT8_C(245),
        UINT8_C(157), UINT8_C( 27), UINT8_C( 64), UINT8_C( 76), UINT8_C( 71),    UINT8_MAX, UINT8_C( 22), UINT8_C( 57) },
      { UINT8_C(144), UINT8_C(245), UINT8_C( 94), UINT8_C(126), UINT8_C(250), UINT8_C( 75), UINT8_C(174), UINT8_C(122),
        UINT8_C(206), UINT8_C(141), UINT8_C(160), UINT8_C( 38), UINT8_C( 35),    UINT8_MAX, UINT8_C( 11), UINT8_C(156) },
      { UINT8_C(228), UINT8_C(157), UINT8_C( 55), UINT8_C( 63), UINT8_C(158), UINT8_C(114), UINT8_C(203), UINT8_C(126),
        UINT8_C(147), UINT8_C(227), UINT8_C(136), UINT8_C(105), UINT8_C( 72), UINT8_C(159), UINT8_C( 98), UINT8_C(167) },
      { UINT8_C(241), UINT8_C(159), UINT8_C( 53), UINT8_C( 55), UINT8_C(159), UINT8_C(116), UINT8_C(194), UINT8_C(119),
        UINT8_C(148), UINT8_C(240), UINT8_C(146), UINT8_C( 98), UINT8_C( 66), UINT8_C(143), UINT8_C( 96), UINT8_C(185) },
      { UINT8_C(241), UINT8_C(152), UINT8_C( 48), UINT8_C( 51), UINT8_C(155), UINT8_C(118), UINT8_C(194), UINT8_C(119),
        UINT8_C(146), UINT8_C(245), UINT8_C(149), UINT8_C( 98), UINT8_C( 67), UINT8_C(142), UINT8_C(103), UINT8_C(185) } },
    { { UINT8_C(151), UINT8_C( 70), UINT8_C(108), UINT8_C( 50), UINT8_C(189), UINT8_C( 46), UINT8_C(169), UINT8_C( 79),
        UINT8_C( 36), UINT8_C( 62), UINT8_C(177), UINT8_C(103), UINT8_C(205), UINT8_C( 24), UINT8_C( 32), UINT8_C(237) },
      { UINT8_C(  3), UINT8_C(220), UINT8_C(233), UINT8_C(248), UINT8_C(114), UINT8_C( 70), UINT8_C(237), UINT8_C( 15),
        UINT8_C( 98), UINT8_C( 45), UINT8_C( 92), UINT8_C(169), UINT8_C( 44), UINT8_C(114), UINT8_C(226), UINT8_C(196) },
      { UINT8_C(129), UINT8_C(110), UINT8_C(116), UINT8_C(124), UINT8_C(185), UINT8_C( 35), UINT8_C(246), UINT8_C(  7),
        UINT8_C( 49), UINT8_C( 22), UINT8_C(174), UINT8_C( 84), UINT8_C(150), UINT8_C( 57), UINT8_C(113), UINT8_C(226) },
      { UINT8_C(128), UINT8_C( 91), UINT8_C(125), UINT8_C( 63), UINT8_C(174), UINT8_C( 40), UINT8_C(189), UINT8_C( 65),
        UINT8_C( 44), UINT8_C( 37), UINT8_C(171), UINT8_C(117), UINT8_C(197), UINT8_C( 14), UINT8_C( 60), UINT8_C(248) },
      { UINT8_C(144), UINT8_C( 70), UINT8_C(111), UINT8_C( 55), UINT8_C(187), UINT8_C( 42), UINT8_C(175), UINT8_C( 72),
        UINT8_C( 35), UINT8_C( 57), UINT8_C(178), UINT8_C(101), UINT8_C(201), UINT8_C( 27), UINT8_C( 39), UINT8_C(238) },
      { UINT8_C(151), UINT8_C( 70), UINT8_C(108), UINT8_C( 50), UINT8_C(189), UINT8_C( 46), UINT8_C(169), UINT8_C( 79),
        UINT8_C( 36), UINT8_C( 62), UINT8_C(177), UINT8_C(103), UINT8_C(205), UINT8_C( 24), UINT8_C( 32), UINT8_C(237) } },
    { { UINT8_C(185), UINT8_C( 79), UINT8_C(246), UINT8_C(118), UINT8_C(125), UINT8_C(160), UINT8_C(197), UINT8_C(161),
        UINT8_C(222), UINT8_C(118), UINT8_C(  8), UINT8_C(171), UINT8_C(143), UINT8_C( 40), UINT8_C(152), UINT8_C(146) },
      { UINT8_C(  4), UINT8_C(130), UINT8_C(138), UINT8_C(118), UINT8_C(200), UINT8_C(119), UINT8_C(134), UINT8_C( 42),
        UINT8_C(165), UINT8_C(226), UINT8_C(212), UINT8_C(209), UINT8_C( 84), UINT8_C(182), UINT8_C(149), UINT8_C( 13) },
      { UINT8_C(130), UINT8_C( 65), UINT8_C(197), UINT8_C( 59), UINT8_C(100), UINT8_C(187), UINT8_C(195), UINT8_C(149),
        UINT8_C(210), UINT8_C(113), UINT8_C(106), UINT8_C(232), UINT8_C(170), UINT8_C( 91), UINT8_C(202), UINT8_C(134) },
      { UINT8_C(160), UINT8_C( 80), UINT8_C(241), UINT8_C(110), UINT8_C(121), UINT8_C(174), UINT8_C(208), UINT8_C(165),
        UINT8_C(212), UINT8_C(124), UINT8_C( 26), UINT8_C(186), UINT8_C(138), UINT8_C( 54), UINT8_C(146), UINT8_C(129) },
      { UINT8_C(184), UINT8_C( 76), UINT8_C(244), UINT8_C(115), UINT8_C(126), UINT8_C(163), UINT8_C(196), UINT8_C(161),
        UINT8_C(221), UINT8_C(119), UINT8_C( 14), UINT8_C(174), UINT8_C(138), UINT8_C( 45), UINT8_C(156), UINT8_C(144) },
      { UINT8_C(185), UINT8_C( 79), UINT8_C(246), UINT8_C(118), UINT8_C(125), UINT8_C(160), UINT8_C(197), UINT8_C(161),
        UINT8_C(222), UINT8_C(118), UINT8_C(  8), UINT8_C(171), UINT8_C(143), UINT8_C( 40), UINT8_C(152), UINT8_C(146) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint8x16_t a = simde_vld1q_u8(test_vec[i].a);
    simde_uint8x16_t b = simde_vld1q_u8(test_vec[i].b);

    simde_uint8x16_t r1 = simde_vsriq_n_u8(a, b, 1);
    simde_uint8x16_t r3 = simde_vsriq_n_u8(a, b, 3);
    simde_uint8x16_t r5 = simde_vsriq_n_u8(a, b, 5);
    simde_uint8x16_t r8 = simde_vsriq_n_u8(a, b, 8);

    simde_test_arm_neon_assert_equal_u8x16(r1, simde_vld1q_u8(test_vec[i].r1));
    simde_test_arm_neon_assert_equal_u8x16(r3, simde_vld1q_u8(test_vec[i].r3));
    simde_test_arm_neon_assert_equal_u8x16(r5, simde_vld1q_u8(test_vec[i].r5));
    simde_test_arm_neon_assert_equal_u8x16(r8, simde_vld1q_u8(test_vec[i].r8));
  }
  return 0;
#else
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint8x16_t a = simde_test_arm_neon_random_u8x16();
    simde_uint8x16_t b = simde_test_arm_neon_random_u8x16();
    simde_uint8x16_t r1 = simde_vsriq_n_u8(a, b, 1);
    simde_uint8x16_t r3 = simde_vsriq_n_u8(a, b, 3);
    simde_uint8x16_t r5 = simde_vsriq_n_u8(a, b, 5);
    simde_uint8x16_t r8 = simde_vsriq_n_u8(a, b, 8);

    simde_test_arm_neon_write_u8x16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u8x16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u8x16(2, r1, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u8x16(2, r3, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u8x16(2, r5, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u8x16(2, r8, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vsriq_n_u16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    uint16_t a[8];
    uint16_t b[8];
    uint16_t r3[8];
    uint16_t r6[8];
    uint16_t r10[8];
    uint16_t r13[8];
    uint16_t r16[8];
  } test_vec[] = {
    { { UINT16_C(35845), UINT16_C(33667), UINT16_C(18476), UINT16_C( 2596), UINT16_C(11711), UINT16_C(20150), UINT16_C(20053), UINT16_C(23264) },
      { UINT16_C(27344), UINT16_C(39376), UINT16_C(22241), UINT16_C(34499), UINT16_C(38712), UINT16_C(36184), UINT16_C(60750), UINT16_C(21402) },
      { UINT16_C(36186), UINT16_C(37690), UINT16_C(19164), UINT16_C( 4312), UINT16_C(13031), UINT16_C(20907), UINT16_C(23977), UINT16_C(19059) },
      { UINT16_C(36267), UINT16_C(33383), UINT16_C(18779), UINT16_C( 2587), UINT16_C(11868), UINT16_C(20021), UINT16_C(20405), UINT16_C(22862) },
      { UINT16_C(35866), UINT16_C(33702), UINT16_C(18453), UINT16_C( 2593), UINT16_C(11685), UINT16_C(20131), UINT16_C(20091), UINT16_C(23252) },
      { UINT16_C(35843), UINT16_C(33668), UINT16_C(18474), UINT16_C( 2596), UINT16_C(11708), UINT16_C(20148), UINT16_C(20055), UINT16_C(23266) },
      { UINT16_C(35845), UINT16_C(33667), UINT16_C(18476), UINT16_C( 2596), UINT16_C(11711), UINT16_C(20150), UINT16_C(20053), UINT16_C(23264) } },
    { { UINT16_C( 7801), UINT16_C(42454), UINT16_C(64358), UINT16_C( 9648), UINT16_C(26152), UINT16_C(32115), UINT16_C(21428), UINT16_C(34263) },
      { UINT16_C(43197), UINT16_C(40734), UINT16_C(57854), UINT16_C(14117), UINT16_C(32121), UINT16_C(51140), UINT16_C(24171), UINT16_C(58394) },
      { UINT16_C( 5399), UINT16_C(46051), UINT16_C(64575), UINT16_C( 9956), UINT16_C(28591), UINT16_C(30968), UINT16_C(19405), UINT16_C(40067) },
      { UINT16_C( 7842), UINT16_C(42620), UINT16_C(64391), UINT16_C( 9436), UINT16_C(26101), UINT16_C(32543), UINT16_C(20857), UINT16_C(34704) },
      { UINT16_C( 7786), UINT16_C(42471), UINT16_C(64376), UINT16_C( 9613), UINT16_C(26143), UINT16_C(32113), UINT16_C(21399), UINT16_C(34297) },
      { UINT16_C( 7805), UINT16_C(42452), UINT16_C(64359), UINT16_C( 9649), UINT16_C(26155), UINT16_C(32118), UINT16_C(21426), UINT16_C(34263) },
      { UINT16_C( 7801), UINT16_C(42454), UINT16_C(64358), UINT16_C( 9648), UINT16_C(26152), UINT16_C(32115), UINT16_C(21428), UINT16_C(34263) } },
    { { UINT16_C(61820), UINT16_C(58250), UINT16_C(15084), UINT16_C( 5128), UINT16_C(31904), UINT16_C(21649), UINT16_C(27087), UINT16_C(36313) },
      { UINT16_C(63249), UINT16_C( 3884), UINT16_C(20953), UINT16_C(21062), UINT16_C( 2767), UINT16_C(14873), UINT16_C(13161), UINT16_C(58654) },
      { UINT16_C(65250), UINT16_C(57829), UINT16_C(10811), UINT16_C( 2632), UINT16_C(24921), UINT16_C(18243), UINT16_C(26221), UINT16_C(40099) },
      { UINT16_C(62428), UINT16_C(57404), UINT16_C(14663), UINT16_C( 5449), UINT16_C(31787), UINT16_C(21736), UINT16_C(26829), UINT16_C(36756) },
      { UINT16_C(61821), UINT16_C(58243), UINT16_C(15060), UINT16_C( 5140), UINT16_C(31874), UINT16_C(21646), UINT16_C(27084), UINT16_C(36345) },
      { UINT16_C(61823), UINT16_C(58248), UINT16_C(15082), UINT16_C( 5130), UINT16_C(31904), UINT16_C(21649), UINT16_C(27081), UINT16_C(36319) },
      { UINT16_C(61820), UINT16_C(58250), UINT16_C(15084), UINT16_C( 5128), UINT16_C(31904), UINT16_C(21649), UINT16_C(27087), UINT16_C(36313) } },
    { { UINT16_C(43044), UINT16_C( 4296), UINT16_C(53730), UINT16_C(33316), UINT16_C(46669), UINT16_C( 7383), UINT16_C(45087), UINT16_C(12457) },
      { UINT16_C(54696), UINT16_C(33087), UINT16_C(34343), UINT16_C(63187), UINT16_C(60560), UINT16_C(63792), UINT16_C(19999), UINT16_C(17631) },
      { UINT16_C(47797), UINT16_C( 4135), UINT16_C(53444), UINT16_C(40666), UINT16_C(48530), UINT16_C( 7974), UINT16_C(43459), UINT16_C(10395) },
      { UINT16_C(43862), UINT16_C( 4612), UINT16_C(53784), UINT16_C(33755), UINT16_C(47026), UINT16_C( 8164), UINT16_C(45368), UINT16_C(12563) },
      { UINT16_C(43061), UINT16_C( 4320), UINT16_C(53729), UINT16_C(33341), UINT16_C(46715), UINT16_C( 7422), UINT16_C(45075), UINT16_C(12433) },
      { UINT16_C(43046), UINT16_C( 4300), UINT16_C(53732), UINT16_C(33319), UINT16_C(46671), UINT16_C( 7383), UINT16_C(45082), UINT16_C(12458) },
      { UINT16_C(43044), UINT16_C( 4296), UINT16_C(53730), UINT16_C(33316), UINT16_C(46669), UINT16_C( 7383), UINT16_C(45087), UINT16_C(12457) } },
    { { UINT16_C(42999), UINT16_C(55636), UINT16_C(31096), UINT16_C(50524), UINT16_C(13103), UINT16_C(20194), UINT16_C(35811), UINT16_C(35710) },
      { UINT16_C(48481), UINT16_C(34828), UINT16_C(57155), UINT16_C(54398), UINT16_C(44747), UINT16_C(60365), UINT16_C(44284), UINT16_C(62255) },
      { UINT16_C(47020), UINT16_C(53505), UINT16_C(31720), UINT16_C(55951), UINT16_C(13785), UINT16_C(23929), UINT16_C(38303), UINT16_C(40549) },
      { UINT16_C(42741), UINT16_C(55840), UINT16_C(31613), UINT16_C(51025), UINT16_C(12987), UINT16_C(20399), UINT16_C(35507), UINT16_C(35788) },
      { UINT16_C(42991), UINT16_C(55650), UINT16_C(31095), UINT16_C(50549), UINT16_C(13099), UINT16_C(20218), UINT16_C(35819), UINT16_C(35708) },
      { UINT16_C(42997), UINT16_C(55636), UINT16_C(31102), UINT16_C(50526), UINT16_C(13101), UINT16_C(20199), UINT16_C(35813), UINT16_C(35711) },
      { UINT16_C(42999), UINT16_C(55636), UINT16_C(31096), UINT16_C(50524), UINT16_C(13103), UINT16_C(20194), UINT16_C(35811), UINT16_C(35710) } },
    { { UINT16_C(33620), UINT16_C(52429), UINT16_C(10748), UINT16_C(11154), UINT16_C(29788), UINT16_C(16249), UINT16_C(63487), UINT16_C(24779) },
      { UINT16_C(55221), UINT16_C(63720), UINT16_C(26295), UINT16_C(33484), UINT16_C(39444), UINT16_C( 4461), UINT16_C(40006), UINT16_C(39428) },
      { UINT16_C(39670), UINT16_C(57117), UINT16_C(11478), UINT16_C(12377), UINT16_C(29506), UINT16_C( 8749), UINT16_C(62344), UINT16_C(29504) },
      { UINT16_C(33630), UINT16_C(53219), UINT16_C(10650), UINT16_C(10763), UINT16_C(30312), UINT16_C(15429), UINT16_C(63089), UINT16_C(25192) },
      { UINT16_C(33653), UINT16_C(52478), UINT16_C(10713), UINT16_C(11168), UINT16_C(29798), UINT16_C(16196), UINT16_C(63463), UINT16_C(24806) },
      { UINT16_C(33622), UINT16_C(52431), UINT16_C(10747), UINT16_C(11156), UINT16_C(29788), UINT16_C(16248), UINT16_C(63484), UINT16_C(24780) },
      { UINT16_C(33620), UINT16_C(52429), UINT16_C(10748), UINT16_C(11154), UINT16_C(29788), UINT16_C(16249), UINT16_C(63487), UINT16_C(24779) } },
    { { UINT16_C(53536), UINT16_C( 7271), UINT16_C(63994), UINT16_C(22088), UINT16_C(49517), UINT16_C(27798), UINT16_C(25017), UINT16_C(28365) },
      { UINT16_C(46392), UINT16_C(61286), UINT16_C(13084), UINT16_C(12402), UINT16_C(57293), UINT16_C( 4929), UINT16_C(18044), UINT16_C(40110) },
      { UINT16_C(54951), UINT16_C( 7660), UINT16_C(58979), UINT16_C(17934), UINT16_C(56313), UINT16_C(25192), UINT16_C(26831), UINT16_C(29589) },
      { UINT16_C(53972), UINT16_C( 8125), UINT16_C(63692), UINT16_C(21697), UINT16_C(50047), UINT16_C(27725), UINT16_C(24857), UINT16_C(28274) },
      { UINT16_C(53549), UINT16_C( 7291), UINT16_C(63948), UINT16_C(22092), UINT16_C(49527), UINT16_C(27780), UINT16_C(24977), UINT16_C(28391) },
      { UINT16_C(53541), UINT16_C( 7271), UINT16_C(63993), UINT16_C(22089), UINT16_C(49518), UINT16_C(27792), UINT16_C(25018), UINT16_C(28364) },
      { UINT16_C(53536), UINT16_C( 7271), UINT16_C(63994), UINT16_C(22088), UINT16_C(49517), UINT16_C(27798), UINT16_C(25017), UINT16_C(28365) } },
    { { UINT16_C( 5399), UINT16_C( 4792), UINT16_C(   14), UINT16_C(31592), UINT16_C(65218), UINT16_C(31719), UINT16_C(46175), UINT16_C(39145) },
      { UINT16_C(20330), UINT16_C(34439), UINT16_C(63874), UINT16_C(20406), UINT16_C(63705), UINT16_C(21859), UINT16_C( 4414), UINT16_C(22001) },
      { UINT16_C( 2541), UINT16_C( 4304), UINT16_C( 7984), UINT16_C(27126), UINT16_C(65307), UINT16_C(27308), UINT16_C(41511), UINT16_C(35518) },
      { UINT16_C( 5437), UINT16_C( 4634), UINT16_C(  998), UINT16_C(31038), UINT16_C(65507), UINT16_C(31061), UINT16_C(46148), UINT16_C(39255) },
      { UINT16_C( 5395), UINT16_C( 4769), UINT16_C(   62), UINT16_C(31571), UINT16_C(65278), UINT16_C(31701), UINT16_C(46148), UINT16_C(39125) },
      { UINT16_C( 5394), UINT16_C( 4796), UINT16_C(   15), UINT16_C(31594), UINT16_C(65223), UINT16_C(31714), UINT16_C(46168), UINT16_C(39146) },
      { UINT16_C( 5399), UINT16_C( 4792), UINT16_C(   14), UINT16_C(31592), UINT16_C(65218), UINT16_C(31719), UINT16_C(46175), UINT16_C(39145) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint16x8_t a = simde_vld1q_u16(test_vec[i].a);
    simde_uint16x8_t b = simde_vld1q_u16(test_vec[i].b);

    simde_uint16x8_t r3 = simde_vsriq_n_u16(a, b, 3);
    simde_uint16x8_t r6 = simde_vsriq_n_u16(a, b, 6);
    simde_uint16x8_t r10 = simde_vsriq_n_u16(a, b, 10);
    simde_uint16x8_t r13 = simde_vsriq_n_u16(a, b, 13);
    simde_uint16x8_t r16 = simde_vsriq_n_u16(a, b, 16);

    simde_test_arm_neon_assert_equal_u16x8(r3, simde_vld1q_u16(test_vec[i].r3));
    simde_test_arm_neon_assert_equal_u16x8(r6, simde_vld1q_u16(test_vec[i].r6));
    simde_test_arm_neon_assert_equal_u16x8(r10, simde_vld1q_u16(test_vec[i].r10));
    simde_test_arm_neon_assert_equal_u16x8(r13, simde_vld1q_u16(test_vec[i].r13));
    simde_test_arm_neon_assert_equal_u16x8(r16, simde_vld1q_u16(test_vec[i].r16));
  }
  return 0;
#else
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint16x8_t a = simde_test_arm_neon_random_u16x8();
    simde_uint16x8_t b = simde_test_arm_neon_random_u16x8();
    simde_uint16x8_t r3 = simde_vsriq_n_u16(a, b, 3);
    simde_uint16x8_t r6 = simde_vsriq_n_u16(a, b, 6);
    simde_uint16x8_t r10 = simde_vsriq_n_u16(a, b, 10);
    simde_uint16x8_t r13 = simde_vsriq_n_u16(a, b, 13);
    simde_uint16x8_t r16 = simde_vsriq_n_u16(a, b, 16);

    simde_test_arm_neon_write_u16x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u16x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u16x8(2, r3, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u16x8(2, r6, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u16x8(2, r10, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u16x8(2, r13, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u16x8(2, r16, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vsriq_n_u32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    uint32_t a[4];
    uint32_t b[4];
    uint32_t r6[4];
    uint32_t r13[4];
    uint32_t r19[4];
    uint32_t r26[4];
    uint32_t r32[4];
  } test_vec[] = {
    { { UINT32_C( 879208742), UINT32_C(1823461546), UINT32_C( 786929358), UINT32_C(3049705547) },
      { UINT32_C(2721795359), UINT32_C( 552726855), UINT32_C( 662000873), UINT32_C(2340251237) },
      { UINT32_C( 914943284), UINT32_C(1820575685), UINT32_C( 748541267), UINT32_C(3056465305) },
      { UINT32_C( 879038938), UINT32_C(1823016847), UINT32_C( 786512810), UINT32_C(3049544683) },
      { UINT32_C( 879211591), UINT32_C(1823458334), UINT32_C( 786924782), UINT32_C(3049705839) },
      { UINT32_C( 879208744), UINT32_C(1823461512), UINT32_C( 786929353), UINT32_C(3049705570) },
      { UINT32_C( 879208742), UINT32_C(1823461546), UINT32_C( 786929358), UINT32_C(3049705547) } },
    { { UINT32_C(3116360719), UINT32_C(2200268468), UINT32_C(1353780229), UINT32_C(4228216796) },
      { UINT32_C( 194920644), UINT32_C( 455839537), UINT32_C(1229103332), UINT32_C( 383106822) },
      { UINT32_C(3090053379), UINT32_C(2154606140), UINT32_C(1361382019), UINT32_C(4233844476) },
      { UINT32_C(3115867378), UINT32_C(2199968092), UINT32_C(1353861653), UINT32_C(4227905197) },
      { UINT32_C(3116360051), UINT32_C(2200265573), UINT32_C(1353779496), UINT32_C(4228211418) },
      { UINT32_C(3116360706), UINT32_C(2200268422), UINT32_C(1353780242), UINT32_C(4228216773) },
      { UINT32_C(3116360719), UINT32_C(2200268468), UINT32_C(1353780229), UINT32_C(4228216796) } },
    { { UINT32_C(1489999012), UINT32_C( 148632835), UINT32_C(3730344961), UINT32_C(3369753859) },
      { UINT32_C(3469965469), UINT32_C(3957980935), UINT32_C(2788502687), UINT32_C(2411465451) },
      { UINT32_C(1530613218), UINT32_C( 196061180), UINT32_C(3734557874), UINT32_C(3393122347) },
      { UINT32_C(1489925787), UINT32_C( 148856655), UINT32_C(3730649513), UINT32_C(3369893344) },
      { UINT32_C(1490000346), UINT32_C( 148635005), UINT32_C(3730347206), UINT32_C(3369751031) },
      { UINT32_C(1489999027), UINT32_C( 148632890), UINT32_C(3730345001), UINT32_C(3369753891) },
      { UINT32_C(1489999012), UINT32_C( 148632835), UINT32_C(3730344961), UINT32_C(3369753859) } },
    { { UINT32_C(2716371870), UINT32_C(2192163712), UINT32_C(1398800720), UINT32_C(4212865630) },
      { UINT32_C(3117084594), UINT32_C(2376446958), UINT32_C(3409173215), UINT32_C(2186997732) },
      { UINT32_C(2733059006), UINT32_C(2184615631), UINT32_C(1395445611), UINT32_C(4194921407) },
      { UINT32_C(2716716631), UINT32_C(2192338221), UINT32_C(1399216542), UINT32_C(4212921047) },
      { UINT32_C(2716374841), UINT32_C(2192167348), UINT32_C(1398806886), UINT32_C(4212863051) },
      { UINT32_C(2716371886), UINT32_C(2192163747), UINT32_C(1398800754), UINT32_C(4212865632) },
      { UINT32_C(2716371870), UINT32_C(2192163712), UINT32_C(1398800720), UINT32_C(4212865630) } },
    { { UINT32_C(4213457531), UINT32_C(1451085062), UINT32_C( 766107087), UINT32_C(3374957847) },
      { UINT32_C(2726556596), UINT32_C(2251237542), UINT32_C(3864093442), UINT32_C(3446188882) },
      { UINT32_C(4203352014), UINT32_C(1444461730), UINT32_C( 798573964), UINT32_C(3409289901) },
      { UINT32_C(4213511199), UINT32_C(1450979705), UINT32_C( 766456459), UINT32_C(3375262533) },
      { UINT32_C(4213462096), UINT32_C(1451086021), UINT32_C( 766106826), UINT32_C(3374963117) },
      { UINT32_C(4213457512), UINT32_C(1451085089), UINT32_C( 766107129), UINT32_C(3374957875) },
      { UINT32_C(4213457531), UINT32_C(1451085062), UINT32_C( 766107087), UINT32_C(3374957847) } },
    { { UINT32_C(4106849518), UINT32_C( 692733530), UINT32_C( 995554084), UINT32_C(1812299704) },
      { UINT32_C( 420382834), UINT32_C(2996780720), UINT32_C(4086886561), UINT32_C(2311127195) },
      { UINT32_C(4100209185), UINT32_C( 717913338), UINT32_C(1003381698), UINT32_C(1848050690) },
      { UINT32_C(4106799220), UINT32_C( 692950265), UINT32_C( 995597511), UINT32_C(1812221448) },
      { UINT32_C(4106847009), UINT32_C( 692737619), UINT32_C( 995556979), UINT32_C(1812295992) },
      { UINT32_C(4106849478), UINT32_C( 692733548), UINT32_C( 995554108), UINT32_C(1812299682) },
      { UINT32_C(4106849518), UINT32_C( 692733530), UINT32_C( 995554084), UINT32_C(1812299704) } },
    { { UINT32_C(3883764365), UINT32_C(4094740432), UINT32_C(1932551867), UINT32_C(1491088870) },
      { UINT32_C(1836183229), UINT32_C(3441365036), UINT32_C(2629940992), UINT32_C(1143308983) },
      { UINT32_C(3853895610), UINT32_C(4147412032), UINT32_C(1920141020), UINT32_C(1494259210) },
      { UINT32_C(3883625359), UINT32_C(4095109368), UINT32_C(1932846605), UINT32_C(1491214636) },
      { UINT32_C(3883765166), UINT32_C(4094744995), UINT32_C(1932555160), UINT32_C(1491085444) },
      { UINT32_C(3883764379), UINT32_C(4094740467), UINT32_C(1932551847), UINT32_C(1491088849) },
      { UINT32_C(3883764365), UINT32_C(4094740432), UINT32_C(1932551867), UINT32_C(1491088870) } },
    { { UINT32_C(3693847308), UINT32_C( 634469226), UINT32_C(2291728802), UINT32_C(4091574582) },
      { UINT32_C(2489340519), UINT32_C(1667333986), UINT32_C(3992920630), UINT32_C(2956076196) },
      { UINT32_C(3729883465), UINT32_C( 630031869), UINT32_C(2344090760), UINT32_C(4072720530) },
      { UINT32_C(3693912834), UINT32_C( 634592011), UINT32_C(2292150265), UINT32_C(4091904401) },
      { UINT32_C(3693851276), UINT32_C( 634465388), UINT32_C(2291735999), UINT32_C(4091573766) },
      { UINT32_C(3693847333), UINT32_C( 634469208), UINT32_C(2291728827), UINT32_C(4091574572) },
      { UINT32_C(3693847308), UINT32_C( 634469226), UINT32_C(2291728802), UINT32_C(4091574582) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint32x4_t a = simde_vld1q_u32(test_vec[i].a);
    simde_uint32x4_t b = simde_vld1q_u32(test_vec[i].b);

    simde_uint32x4_t r6 = simde_vsriq_n_u32(a, b, 6);
    simde_uint32x4_t r13 = simde_vsriq_n_u32(a, b, 13);
    simde_uint32x4_t r19 = simde_vsriq_n_u32(a, b, 19);
    simde_uint32x4_t r26 = simde_vsriq_n_u32(a, b, 26);
    simde_uint32x4_t r32 = simde_vsriq_n_u32(a, b, 32);

    simde_test_arm_neon_assert_equal_u32x4(r6, simde_vld1q_u32(test_vec[i].r6));
    simde_test_arm_neon_assert_equal_u32x4(r13, simde_vld1q_u32(test_vec[i].r13));
    simde_test_arm_neon_assert_equal_u32x4(r19, simde_vld1q_u32(test_vec[i].r19));
    simde_test_arm_neon_assert_equal_u32x4(r26, simde_vld1q_u32(test_vec[i].r26));
    simde_test_arm_neon_assert_equal_u32x4(r32, simde_vld1q_u32(test_vec[i].r32));
  }
  return 0;
#else
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint32x4_t a = simde_test_arm_neon_random_u32x4();
    simde_uint32x4_t b = simde_test_arm_neon_random_u32x4();
    simde_uint32x4_t r6 = simde_vsriq_n_u32(a, b, 6);
    simde_uint32x4_t r13 = simde_vsriq_n_u32(a, b, 13);
    simde_uint32x4_t r19 = simde_vsriq_n_u32(a, b, 19);
    simde_uint32x4_t r26 = simde_vsriq_n_u32(a, b, 26);
    simde_uint32x4_t r32 = simde_vsriq_n_u32(a, b, 32);

    simde_test_arm_neon_write_u32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x4(2, r6, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x4(2, r13, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x4(2, r19, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x4(2, r26, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x4(2, r32, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vsriq_n_u64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    uint64_t a[2];
    uint64_t b[2];
    uint64_t r13[2];
    uint64_t r26[2];
    uint64_t r39[2];
    uint64_t r52[2];
    uint64_t r64[2];
  } test_vec[] = {
    { { UINT64_C( 4365139260797155633), UINT64_C(11130453238157857993) },
      { UINT64_C(14955214256351167976), UINT64_C( 2141459339168947609) },
      { UINT64_C( 4365813626599787866), UINT64_C(11128656087843234012) },
      { UINT64_C( 4365139450446350418), UINT64_C(11130452996909923091) },
      { UINT64_C( 4365139260808828720), UINT64_C(11130453238136664059) },
      { UINT64_C( 4365139260797156600), UINT64_C(11130453238157857243) },
      { UINT64_C( 4365139260797155633), UINT64_C(11130453238157857993) } },
    { { UINT64_C( 9455989917996262390), UINT64_C(17301022207733774400) },
      { UINT64_C(17782961611069834713), UINT64_C(15595114360048116834) },
      { UINT64_C( 9457478189345395150), UINT64_C(17302481669027164695) },
      { UINT64_C( 9455989929616168830), UINT64_C(17301022403626694803) },
      { UINT64_C( 9455989917997699978), UINT64_C(17301022207743416819) },
      { UINT64_C( 9455989917996265324), UINT64_C(17301022207733775750) },
      { UINT64_C( 9455989917996262390), UINT64_C(17301022207733774400) } },
    { { UINT64_C(17283144865266680732), UINT64_C( 7259952733400004552) },
      { UINT64_C( 2423261778652625485), UINT64_C( 8774942670212555532) },
      { UINT64_C(17282859378356867831), UINT64_C( 7260873759315161983) },
      { UINT64_C(17283144698038972394), UINT64_C( 7259952813415266171) },
      { UINT64_C(17283144865240269391), UINT64_C( 7259952733408693687) },
      { UINT64_C(17283144865266680346), UINT64_C( 7259952733400004508) },
      { UINT64_C(17283144865266680732), UINT64_C( 7259952733400004552) } },
    { { UINT64_C( 8412349912667167775), UINT64_C(  113159212066155682) },
      { UINT64_C( 2656927073845441023), UINT64_C( 5298442261255835184) },
      { UINT64_C( 8410796636032595303), UINT64_C(  113236773186857106) },
      { UINT64_C( 8412349759810127407), UINT64_C(  113159066904578691) },
      { UINT64_C( 8412349912658329242), UINT64_C(  113159212071325618) },
      { UINT64_C( 8412349912667165261), UINT64_C(  113159212066153624) },
      { UINT64_C( 8412349912667167775), UINT64_C(  113159212066155682) } },
    { { UINT64_C(11931958467903313781), UINT64_C(16120746881987107586) },
      { UINT64_C(16254472581633893462), UINT64_C(17599353210776037066) },
      { UINT64_C(11932019601452006635), UINT64_C(16122783224718927741) },
      { UINT64_C(11931958700951940187), UINT64_C(16120747003731615741) },
      { UINT64_C(11931958467931350777), UINT64_C(16120746882005236460) },
      { UINT64_C(11931958467903315481), UINT64_C(16120746881987108675) },
      { UINT64_C(11931958467903313781), UINT64_C(16120746881987107586) } },
    { { UINT64_C( 3203657109335332301), UINT64_C(  308386268589541512) },
      { UINT64_C( 3067239833563030783), UINT64_C(14132397843043811500) },
      { UINT64_C( 3202433753985418143), UINT64_C(  307969920882268412) },
      { UINT64_C( 3203656971161016364), UINT64_C(  308386284145425802) },
      { UINT64_C( 3203657109339447820), UINT64_C(  308386268600352953) },
      { UINT64_C( 3203657109335331497), UINT64_C(  308386268589542466) },
      { UINT64_C( 3203657109335332301), UINT64_C(  308386268589541512) } },
    { { UINT64_C( 7712425236134901425), UINT64_C( 9584252124101077841) },
      { UINT64_C( 2921085170296911358), UINT64_C(13115172626430732359) },
      { UINT64_C( 7712770939651551659), UINT64_C( 9585260980265415333) },
      { UINT64_C( 7712425125637906199), UINT64_C( 9584252289487274255) },
      { UINT64_C( 7712425236130501518), UINT64_C( 9584252124111045864) },
      { UINT64_C( 7712425236134900360), UINT64_C( 9584252124101077856) },
      { UINT64_C( 7712425236134901425), UINT64_C( 9584252124101077841) } },
    { { UINT64_C(17364079848386107050), UINT64_C(16614607949979897222) },
      { UINT64_C(15423647362425603942), UINT64_C( 9020735151165169525) },
      { UINT64_C(17365511132780368422), UINT64_C(16614880189328642210) },
      { UINT64_C(17364079942680404920), UINT64_C(16614607916678624478) },
      { UINT64_C(17364079848404555675), UINT64_C(16614607949980655661) },
      { UINT64_C(17364079848386108768), UINT64_C(16614607949979895763) },
      { UINT64_C(17364079848386107050), UINT64_C(16614607949979897222) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint64x2_t a = simde_vld1q_u64(test_vec[i].a);
    simde_uint64x2_t b = simde_vld1q_u64(test_vec[i].b);

    simde_uint64x2_t r13 = simde_vsriq_n_u64(a, b, 13);
    simde_uint64x2_t r26 = simde_vsriq_n_u64(a, b, 26);
    simde_uint64x2_t r39 = simde_vsriq_n_u64(a, b, 39);
    simde_uint64x2_t r52 = simde_vsriq_n_u64(a, b, 52);
    simde_uint64x2_t r64 = simde_vsriq_n_u64(a, b, 64);

    simde_test_arm_neon_assert_equal_u64x2(r13, simde_vld1q_u64(test_vec[i].r13));
    simde_test_arm_neon_assert_equal_u64x2(r26, simde_vld1q_u64(test_vec[i].r26));
    simde_test_arm_neon_assert_equal_u64x2(r39, simde_vld1q_u64(test_vec[i].r39));
    simde_test_arm_neon_assert_equal_u64x2(r52, simde_vld1q_u64(test_vec[i].r52));
    simde_test_arm_neon_assert_equal_u64x2(r64, simde_vld1q_u64(test_vec[i].r64));
  }
  return 0;
#else
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint64x2_t a = simde_test_arm_neon_random_u64x2();
    simde_uint64x2_t b = simde_test_arm_neon_random_u64x2();
    simde_uint64x2_t r13 = simde_vsriq_n_u64(a, b, 13);
    simde_uint64x2_t r26 = simde_vsriq_n_u64(a, b, 26);
    simde_uint64x2_t r39 = simde_vsriq_n_u64(a, b, 39);
    simde_uint64x2_t r52 = simde_vsriq_n_u64(a, b, 52);
    simde_uint64x2_t r64 = simde_vsriq_n_u64(a, b, 64);

    simde_test_arm_neon_write_u64x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u64x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u64x2(2, r13, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u64x2(2, r26, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u64x2(2, r39, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u64x2(2, r52, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u64x2(2, r64, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vsrid_n_s64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    int64_t a;
    int64_t b;
    int64_t r13;
    int64_t r26;
    int64_t r39;
    int64_t r52;
    int64_t r64;
  } test_vec[] = {
    {  INT64_C( 3038338084825327649),
      -INT64_C( 2639957407124750664),
       INT64_C( 3039607488049410391),
       INT64_C( 3038338166055448171),
       INT64_C( 3038338084828002809),
       INT64_C( 3038338084825329077),
       INT64_C( 3038338084825327649) },
    { -INT64_C( 7888945905166066395),
      -INT64_C( 8445492395703210646),
      -INT64_C( 7889085691235383609),
      -INT64_C( 7888946027361379742),
      -INT64_C( 7888945905152977110),
      -INT64_C( 7888945905166067540),
      -INT64_C( 7888945905166066395) },
    {  INT64_C( 7497263785757333630),
       INT64_C( 6283492565175448991),
       INT64_C( 7497008607659212985),
       INT64_C( 7497263669447543958),
       INT64_C( 7497263785744164582),
       INT64_C( 7497263785757332851),
       INT64_C( 7497263785757333630) },
    { -INT64_C( 4584099998333042608),
       INT64_C( 5684127465250241263),
      -INT64_C( 4583970557447191999),
      -INT64_C( 4584100011620109290),
      -INT64_C( 4584099998330928089),
      -INT64_C( 4584099998333041426),
      -INT64_C( 4584099998333042608) },
    { -INT64_C( 7312655049053742741),
       INT64_C( 6915600551404280688),
      -INT64_C( 7313001605329250412),
      -INT64_C( 7312655195584232472),
      -INT64_C( 7312655049044266420),
      -INT64_C( 7312655049053743617),
      -INT64_C( 7312655049053742741) },
    {  INT64_C( 7475010529852880806),
      -INT64_C( 8941156987404614452),
       INT64_C( 7474883931607459320),
       INT64_C( 7475010426748028391),
       INT64_C( 7475010529867060546),
       INT64_C( 7475010529852880958),
       INT64_C( 7475010529852880806) },
    { -INT64_C( 4283165872800982534),
       INT64_C( 5633263883237360063),
      -INT64_C( 4284487391160405196),
      -INT64_C( 4283165878879000077),
      -INT64_C( 4283165872817939777),
      -INT64_C( 4283165872800983838),
      -INT64_C( 4283165872800982534) },
    { -INT64_C( 4920736818446836266),
       INT64_C( 1343834205961352715),
      -INT64_C( 4922270350454482237),
      -INT64_C( 4920737001615882808),
      -INT64_C( 4920736818466042748),
      -INT64_C( 4920736818446839510),
      -INT64_C( 4920736818446836266) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    int64_t r13 = simde_vsrid_n_s64(test_vec[i].a, test_vec[i].b, 13);
    int64_t r26 = simde_vsrid_n_s64(test_vec[i].a, test_vec[i].b, 26);
    int64_t r39 = simde_vsrid_n_s64(test_vec[i].a, test_vec[i].b, 39);
    int64_t r52 = simde_vsrid_n_s64(test_vec[i].a, test_vec[i].b, 52);
    int64_t r64 = simde_vsrid_n_s64(test_vec[i].a, test_vec[i].b, 64);

    simde_assert_equal_i64(r13, test_vec[i].r13);
    simde_assert_equal_i64(r26, test_vec[i].r26);
    simde_assert_equal_i64(r39, test_vec[i].r39);
    simde_assert_equal_i64(r52, test_vec[i].r52);
    simde_assert_equal_i64(r64, test_vec[i].r64);
  }
  return 0;
#else
  for (int i = 0 ; i < 8 ; i++) {
    int64_t a = simde_test_codegen_random_i64();
    int64_t b = simde_test_codegen_random_i64();
    int64_t r13 = simde_vsrid_n_s64(a, b, 13);
    int64_t r26 = simde_vsrid_n_s64(a, b, 26);
    int64_t r39 = simde_vsrid_n_s64(a, b, 39);
    int64_t r52 = simde_vsrid_n_s64(a, b, 52);
    int64_t r64 = simde_vsrid_n_s64(a, b, 64);

    simde_test_codegen_write_i64(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_i64(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i64(2, r13, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i64(2, r26, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i64(2, r39, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i64(2, r52, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i64(2, r64, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vsrid_n_u64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    uint64_t a;
    uint64_t b;
    uint64_t r13;
    uint64_t r26;
    uint64_t r39;
    uint64_t r52;
    uint64_t r64;
  } test_vec[] = {
    { UINT64_C(17603990000659042020),
      UINT64_C(18432033531320989821),
      UINT64_C(17604569147670762447),
      UINT64_C(17603990126154692028),
      UINT64_C(17603990000678967161),
      UINT64_C(17603990000659042300),
      UINT64_C(17603990000659042020) },
    { UINT64_C(15992106754582201151),
      UINT64_C( 6090506551897131884),
      UINT64_C(15990773947017019428),
      UINT64_C(15992106720565713962),
      UINT64_C(15992106754576550822),
      UINT64_C(15992106754582201672),
      UINT64_C(15992106754582201151) },
    { UINT64_C(13904682717901902945),
      UINT64_C( 7794180837573095508),
      UINT64_C(13903563487783245211),
      UINT64_C(13904682821108075338),
      UINT64_C(13904682717898364156),
      UINT64_C(13904682717901903554),
      UINT64_C(13904682717901902945) },
    { UINT64_C(17796933294910613953),
      UINT64_C( 3726486603193843699),
      UINT64_C(17796428820938693879),
      UINT64_C(17796933306978727064),
      UINT64_C(17796933294909517383),
      UINT64_C(17796933294910612283),
      UINT64_C(17796933294910613953) },
    { UINT64_C( 8393353048649811319),
      UINT64_C( 7942319691150601886),
      UINT64_C( 8393427427051592953),
      UINT64_C( 8393353026419714930),
      UINT64_C( 8393353048643891603),
      UINT64_C( 8393353048649811683),
      UINT64_C( 8393353048649811319) },
    { UINT64_C(  824871320512475378),
      UINT64_C(12433916528002208136),
      UINT64_C(  825676543884972912),
      UINT64_C(  824871400623394070),
      UINT64_C(  824871320525806666),
      UINT64_C(  824871320512477896),
      UINT64_C(  824871320512475378) },
    { UINT64_C(10484347986743117034),
      UINT64_C(15721104122295623185),
      UINT64_C(10484047212797883104),
      UINT64_C(10484348006066108911),
      UINT64_C(10484347986748135721),
      UINT64_C(10484347986743119266),
      UINT64_C(10484347986743117034) },
    { UINT64_C(14585410155087051077),
      UINT64_C(16697855368363300826),
      UINT64_C(14586945705662247206),
      UINT64_C(14585410393748586307),
      UINT64_C(14585410155094963557),
      UINT64_C(14585410155087052411),
      UINT64_C(14585410155087051077) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    uint64_t r13 = simde_vsrid_n_u64(test_vec[i].a, test_vec[i].b, 13);
    uint64_t r26 = simde_vsrid_n_u64(test_vec[i].a, test_vec[i].b, 26);
    uint64_t r39 = simde_vsrid_n_u64(test_vec[i].a, test_vec[i].b, 39);
    uint64_t r52 = simde_vsrid_n_u64(test_vec[i].a, test_vec[i].b, 52);
    uint64_t r64 = simde_vsrid_n_u64(test_vec[i].a, test_vec[i].b, 64);

    simde_assert_equal_u64(r13, test_vec[i].r13);
    simde_assert_equal_u64(r26, test_vec[i].r26);
    simde_assert_equal_u64(r39, test_vec[i].r39);
    simde_assert_equal_u64(r52, test_vec[i].r52);
    simde_assert_equal_u64(r64, test_vec[i].r64);
  }
  return 0;
#else
  for (int i = 0 ; i < 8 ; i++) {
    uint64_t a = simde_test_codegen_random_u64();
    uint64_t b = simde_test_codegen_random_u64();
    uint64_t r13 = simde_vsrid_n_u64(a, b, 13);
    uint64_t r26 = simde_vsrid_n_u64(a, b, 26);
    uint64_t r39 = simde_vsrid_n_u64(a, b, 39);
    uint64_t r52 = simde_vsrid_n_u64(a, b, 52);
    uint64_t r64 = simde_vsrid_n_u64(a, b, 64);

    simde_test_codegen_write_u64(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_u64(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_u64(2, r13, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_u64(2, r26, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_u64(2, r39, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_u64(2, r52, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_u64(2, r64, SIMDE_TEST_VEC_POS_LAST);
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
SIMDE_TEST_FUNC_LIST_ENTRY(vsriq_n_s8)
SIMDE_TEST_FUNC_LIST_ENTRY(vsriq_n_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vsriq_n_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vsriq_n_s64)
SIMDE_TEST_FUNC_LIST_ENTRY(vsriq_n_u8)
SIMDE_TEST_FUNC_LIST_ENTRY(vsriq_n_u16)
SIMDE_TEST_FUNC_LIST_ENTRY(vsriq_n_u32)
SIMDE_TEST_FUNC_LIST_ENTRY(vsriq_n_u64)
SIMDE_TEST_FUNC_LIST_ENTRY(vsrid_n_s64)
SIMDE_TEST_FUNC_LIST_ENTRY(vsrid_n_u64)
SIMDE_TEST_FUNC_LIST_END

#include <test/arm/neon/test-neon-footer.h>
