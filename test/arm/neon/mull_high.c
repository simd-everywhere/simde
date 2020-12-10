#define SIMDE_TEST_ARM_NEON_INSN mull_high

#include "test-neon.h"
#include "../../../simde/arm/neon/mull_high.h"

static int
test_simde_vmull_high_s8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int8_t a[16];
    int8_t b[16];
    int16_t r[8];
  } test_vec[] = {
    { {  INT8_C(   1),  INT8_C(  41),      INT8_MIN,  INT8_C(  91),  INT8_C(  79), -INT8_C( 119),  INT8_C(  78), -INT8_C(  75),
        -INT8_C(  74), -INT8_C(  42), -INT8_C( 125), -INT8_C(  81), -INT8_C(  49),  INT8_C(  57), -INT8_C(  30), -INT8_C(  14) },
      {  INT8_C(  81),  INT8_C(  59),  INT8_C( 120),  INT8_C(  49), -INT8_C(  28), -INT8_C(  59), -INT8_C(  81), -INT8_C(  20),
         INT8_C(  66), -INT8_C( 124), -INT8_C(  49),      INT8_MIN,  INT8_C(  30), -INT8_C(  80), -INT8_C(  63),  INT8_C(  32) },
      { -INT16_C(  4884),  INT16_C(  5208),  INT16_C(  6125),  INT16_C( 10368), -INT16_C(  1470), -INT16_C(  4560),  INT16_C(  1890), -INT16_C(   448) } },
    { { -INT8_C(  39),  INT8_C(  65),  INT8_C( 123),  INT8_C(  41), -INT8_C(  53), -INT8_C(  55), -INT8_C(  34), -INT8_C( 127),
        -INT8_C(  96),  INT8_C(  97),  INT8_C(  48),  INT8_C( 111), -INT8_C( 102),  INT8_C(  18),  INT8_C(  97), -INT8_C(  20) },
      {  INT8_C(  77), -INT8_C(  39),  INT8_C(  29),  INT8_C(  50), -INT8_C(  98), -INT8_C(  51),  INT8_C(  30), -INT8_C(  32),
         INT8_C(  81), -INT8_C(  18),  INT8_C(  96),  INT8_C( 112), -INT8_C(  98),  INT8_C(  33), -INT8_C( 112),  INT8_C( 120) },
      { -INT16_C(  7776), -INT16_C(  1746),  INT16_C(  4608),  INT16_C( 12432),  INT16_C(  9996),  INT16_C(   594), -INT16_C( 10864), -INT16_C(  2400) } },
    { {  INT8_C(  99),  INT8_C(  11), -INT8_C(  95),  INT8_C(  46), -INT8_C(  44),      INT8_MAX, -INT8_C(  81),  INT8_C( 116),
        -INT8_C(  31), -INT8_C(  33), -INT8_C(  29),  INT8_C( 123), -INT8_C(  14),  INT8_C(  68),  INT8_C( 103),  INT8_C(  63) },
      {  INT8_C(  29), -INT8_C( 123),  INT8_C( 113), -INT8_C(  69),  INT8_C(  82), -INT8_C( 112), -INT8_C( 100), -INT8_C(  93),
         INT8_C( 126), -INT8_C(   4),  INT8_C(  19),  INT8_C(  28),  INT8_C(  30), -INT8_C(  93), -INT8_C( 108), -INT8_C( 127) },
      { -INT16_C(  3906),  INT16_C(   132), -INT16_C(   551),  INT16_C(  3444), -INT16_C(   420), -INT16_C(  6324), -INT16_C( 11124), -INT16_C(  8001) } },
    { { -INT8_C(  82),  INT8_C(  53), -INT8_C(  81), -INT8_C( 125), -INT8_C(  75),  INT8_C(  94), -INT8_C(   9), -INT8_C( 106),
         INT8_C(  61), -INT8_C(  37),  INT8_C(  17),  INT8_C(  47),  INT8_C(  31),  INT8_C( 121),  INT8_C( 111),  INT8_C(  61) },
      { -INT8_C(   2), -INT8_C(  32), -INT8_C(   8),  INT8_C(  80),  INT8_C( 112), -INT8_C( 108), -INT8_C(  13), -INT8_C(  18),
        -INT8_C( 111),  INT8_C(   7),  INT8_C(  11), -INT8_C(  81), -INT8_C(  86), -INT8_C(  97),  INT8_C(  48),  INT8_C(  89) },
      { -INT16_C(  6771), -INT16_C(   259),  INT16_C(   187), -INT16_C(  3807), -INT16_C(  2666), -INT16_C( 11737),  INT16_C(  5328),  INT16_C(  5429) } },
    { { -INT8_C(  43), -INT8_C(  33), -INT8_C(  36), -INT8_C( 118),  INT8_C(  61), -INT8_C(  45),  INT8_C(  32),  INT8_C( 122),
        -INT8_C(  82),  INT8_C(  49), -INT8_C(  86), -INT8_C(  50), -INT8_C(  86),  INT8_C(  25),  INT8_C(  11), -INT8_C(  88) },
      { -INT8_C(   7),  INT8_C(   3), -INT8_C(   8),  INT8_C( 106), -INT8_C( 104), -INT8_C(  20),  INT8_C(  88),  INT8_C(  41),
        -INT8_C(  13),  INT8_C(  99), -INT8_C(  40), -INT8_C(  99),  INT8_C(   3),  INT8_C(   8), -INT8_C(  10), -INT8_C(  40) },
      {  INT16_C(  1066),  INT16_C(  4851),  INT16_C(  3440),  INT16_C(  4950), -INT16_C(   258),  INT16_C(   200), -INT16_C(   110),  INT16_C(  3520) } },
    { { -INT8_C(  25), -INT8_C(  46),  INT8_C(  98),  INT8_C(  36), -INT8_C(  90), -INT8_C( 126), -INT8_C(  98),  INT8_C(  84),
        -INT8_C(  77),  INT8_C(  72),  INT8_C(  34),  INT8_C(  94),  INT8_C(  97),  INT8_C(  45),  INT8_C(   6),  INT8_C(  91) },
      {  INT8_C(  49), -INT8_C(   1), -INT8_C(  59), -INT8_C(  55), -INT8_C(  21),  INT8_C(  29), -INT8_C(  14), -INT8_C(  34),
        -INT8_C( 127), -INT8_C(  54),  INT8_C( 123), -INT8_C( 124), -INT8_C(  46),  INT8_C( 114),  INT8_C(  92), -INT8_C(  71) },
      {  INT16_C(  9779), -INT16_C(  3888),  INT16_C(  4182), -INT16_C( 11656), -INT16_C(  4462),  INT16_C(  5130),  INT16_C(   552), -INT16_C(  6461) } },
    { {  INT8_C(  68), -INT8_C(  66), -INT8_C(  35), -INT8_C(  22),  INT8_C(  64),  INT8_C( 123),  INT8_C(  63), -INT8_C(  13),
        -INT8_C(  60),  INT8_C(  97),  INT8_C(  81),  INT8_C(  37), -INT8_C( 113),  INT8_C(  88),      INT8_MIN, -INT8_C(  64) },
      {  INT8_C(  87),  INT8_C(  69), -INT8_C( 119),  INT8_C(  66),  INT8_C(  99),  INT8_C( 123),  INT8_C(  32), -INT8_C(  28),
         INT8_C(  69), -INT8_C( 101),  INT8_C( 104),  INT8_C(  23),  INT8_C(  13), -INT8_C(  60), -INT8_C(  48),  INT8_C(  82) },
      { -INT16_C(  4140), -INT16_C(  9797),  INT16_C(  8424),  INT16_C(   851), -INT16_C(  1469), -INT16_C(  5280),  INT16_C(  6144), -INT16_C(  5248) } },
    { { -INT8_C( 126), -INT8_C(  83),  INT8_C(  60), -INT8_C(  62),  INT8_C(  40),  INT8_C( 123), -INT8_C(  75), -INT8_C(  20),
        -INT8_C(  35),  INT8_C(   7),  INT8_C(  18),  INT8_C( 108),  INT8_C(  95), -INT8_C( 110),  INT8_C(  44), -INT8_C(  74) },
      { -INT8_C(  40), -INT8_C(  75), -INT8_C(   8),  INT8_C(  59),  INT8_C(  48),  INT8_C(  24),  INT8_C(  31),  INT8_C( 117),
        -INT8_C(  77), -INT8_C( 121), -INT8_C( 116), -INT8_C(  63),  INT8_C(  75),  INT8_C(  92),  INT8_C(  19), -INT8_C(  51) },
      {  INT16_C(  2695), -INT16_C(   847), -INT16_C(  2088), -INT16_C(  6804),  INT16_C(  7125), -INT16_C( 10120),  INT16_C(   836),  INT16_C(  3774) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int8x16_t a = simde_vld1q_s8(test_vec[i].a);
    simde_int8x16_t b = simde_vld1q_s8(test_vec[i].b);
    simde_int16x8_t r = simde_vmull_high_s8(a, b);

    simde_test_arm_neon_assert_equal_i16x8(r, simde_vld1q_s16(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int8x16_t a = simde_test_arm_neon_random_i8x16();
    simde_int8x16_t b = simde_test_arm_neon_random_i8x16();
    simde_int16x8_t r = simde_vmull_high_s8(a, b);

    simde_test_arm_neon_write_i8x16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i8x16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i16x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vmull_high_s16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int16_t a[8];
    int16_t b[8];
    int32_t r[4];
  } test_vec[] = {
    { {  INT16_C( 26020),  INT16_C( 28555),  INT16_C(  1681), -INT16_C( 31395),  INT16_C(  1137),  INT16_C(  4438),  INT16_C( 10954), -INT16_C(  8728) },
      {  INT16_C(   853), -INT16_C(  8018),  INT16_C(  7096), -INT16_C( 14876), -INT16_C( 12102), -INT16_C(  1906), -INT16_C( 10046),  INT16_C( 26192) },
      { -INT32_C(    13759974), -INT32_C(     8458828), -INT32_C(   110043884), -INT32_C(   228603776) } },
    { { -INT16_C(  9411), -INT16_C( 12587),  INT16_C( 13281),  INT16_C( 21076), -INT16_C( 21961),  INT16_C(   355),  INT16_C( 19668),  INT16_C( 10718) },
      { -INT16_C( 29361),  INT16_C(  1801), -INT16_C(  4440),  INT16_C( 25548),  INT16_C( 23230), -INT16_C( 32677), -INT16_C( 21709),  INT16_C( 28903) },
      { -INT32_C(   510154030), -INT32_C(    11600335), -INT32_C(   426972612),  INT32_C(   309782354) } },
    { { -INT16_C( 17274),  INT16_C( 26687), -INT16_C( 27665),  INT16_C( 10170),  INT16_C(  7741),  INT16_C(  4392),  INT16_C(  1898), -INT16_C( 18117) },
      {  INT16_C( 17556),  INT16_C( 15552), -INT16_C( 29390), -INT16_C(  3937), -INT16_C(  1049),  INT16_C(  6769),  INT16_C( 22694),  INT16_C( 11659) },
      { -INT32_C(     8120309),  INT32_C(    29729448),  INT32_C(    43073212), -INT32_C(   211226103) } },
    { { -INT16_C( 13804),  INT16_C(  1173),  INT16_C( 20317), -INT16_C( 26069),  INT16_C( 21357), -INT16_C( 10325), -INT16_C(  6566), -INT16_C(  4464) },
      {  INT16_C( 20779),  INT16_C( 23851), -INT16_C( 13602), -INT16_C( 15026), -INT16_C( 16443),  INT16_C( 27872),  INT16_C( 27415),  INT16_C( 11161) },
      { -INT32_C(   351173151), -INT32_C(   287778400), -INT32_C(   180006890), -INT32_C(    49822704) } },
    { {  INT16_C( 11829), -INT16_C( 28113),  INT16_C( 23165), -INT16_C(  5332), -INT16_C( 10322),  INT16_C(  2242),  INT16_C( 21438), -INT16_C(  5641) },
      {  INT16_C(  8868), -INT16_C( 32186), -INT16_C( 27412), -INT16_C( 19897),  INT16_C( 10067),  INT16_C( 27166), -INT16_C( 18542), -INT16_C( 14442) },
      { -INT32_C(   103911574),  INT32_C(    60906172), -INT32_C(   397503396),  INT32_C(    81467322) } },
    { { -INT16_C( 14875),  INT16_C( 25177), -INT16_C( 31456), -INT16_C( 12723),  INT16_C(  4189),  INT16_C(  7126), -INT16_C( 12957),  INT16_C(  1796) },
      {  INT16_C( 19183), -INT16_C(  9079), -INT16_C( 12065),  INT16_C( 12942), -INT16_C( 21256), -INT16_C( 30051),  INT16_C( 13155),  INT16_C( 18514) },
      { -INT32_C(    89041384), -INT32_C(   214143426), -INT32_C(   170449335),  INT32_C(    33251144) } },
    { { -INT16_C( 21512),  INT16_C(  6314), -INT16_C(  1999), -INT16_C( 28954), -INT16_C( 17144),  INT16_C( 27561), -INT16_C( 21110),  INT16_C( 31346) },
      { -INT16_C(  1033), -INT16_C( 10666), -INT16_C(  6965), -INT16_C( 15607), -INT16_C( 22896), -INT16_C(  3250), -INT16_C( 24359), -INT16_C( 11973) },
      {  INT32_C(   392529024), -INT32_C(    89573250),  INT32_C(   514218490), -INT32_C(   375305658) } },
    { { -INT16_C(  6837),  INT16_C( 31978), -INT16_C( 12067), -INT16_C(  6902), -INT16_C( 19571),  INT16_C(  6224), -INT16_C( 15776),  INT16_C( 22674) },
      { -INT16_C(  5955), -INT16_C( 30418),  INT16_C( 14284),  INT16_C( 23628), -INT16_C( 25891), -INT16_C( 18865), -INT16_C( 30150), -INT16_C( 31096) },
      {  INT32_C(   506712761), -INT32_C(   117415760),  INT32_C(   475646400), -INT32_C(   705070704) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x8_t a = simde_vld1q_s16(test_vec[i].a);
    simde_int16x8_t b = simde_vld1q_s16(test_vec[i].b);
    simde_int32x4_t r = simde_vmull_high_s16(a, b);

    simde_test_arm_neon_assert_equal_i32x4(r, simde_vld1q_s32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int16x8_t a = simde_test_arm_neon_random_i16x8();
    simde_int16x8_t b = simde_test_arm_neon_random_i16x8();
    simde_int32x4_t r = simde_vmull_high_s16(a, b);

    simde_test_arm_neon_write_i16x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i16x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vmull_high_s32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int32_t a[4];
    int32_t b[4];
    int64_t r[2];
  } test_vec[] = {
    { { -INT32_C(  1126387473), -INT32_C(   122861674), -INT32_C(   249089497), -INT32_C(   774744012) },
      {  INT32_C(   824384446),  INT32_C(  2060991692), -INT32_C(   829349104),  INT32_C(   297697313) },
      {  INT64_C(  206582151152760688), -INT64_C(  230639210635239756) } },
    { { -INT32_C(   942826960),  INT32_C(   163543778), -INT32_C(   503584851), -INT32_C(    38613697) },
      { -INT32_C(  1255221528),  INT32_C(   573507090),  INT32_C(  1257357353),  INT32_C(  1885056832) },
      { -INT64_C(  633186115264259403), -INT64_C(   72789013338627904) } },
    { {  INT32_C(   725035081),  INT32_C(  1345714083),  INT32_C(   489763038), -INT32_C(   451222531) },
      { -INT32_C(   862304071),  INT32_C(  2012137806), -INT32_C(   910041207), -INT32_C(   667279986) },
      { -INT64_C(  445704546245506866),  INT64_C(  301091764168564566) } },
    { { -INT32_C(   402427579),  INT32_C(  1178089576),  INT32_C(  1701013864),  INT32_C(   105610573) },
      {  INT32_C(   332588485),  INT32_C(   948617647),  INT32_C(   788679840), -INT32_C(  1375257495) },
      {  INT64_C( 1341555342097301760), -INT64_C(  145241732069494635) } },
    { {  INT32_C(   378997421), -INT32_C(  1419980989), -INT32_C(  2045657031),  INT32_C(    59530301) },
      { -INT32_C(   266969279), -INT32_C(  1071013600),  INT32_C(  1458514925),  INT32_C(   335869543) },
      { -INT64_C( 2983621311144687675),  INT64_C(   19994414991522443) } },
    { {  INT32_C(  1143642881), -INT32_C(  1527806101), -INT32_C(  2077622201), -INT32_C(  1635273124) },
      {  INT32_C(   898539029),  INT32_C(   754366271),  INT32_C(  1233315298), -INT32_C(   581007652) },
      { -INT64_C( 2562363243957730898),  INT64_C(  950106198153944848) } },
    { { -INT32_C(  1927182302),  INT32_C(  1446055951),  INT32_C(  1843092241),  INT32_C(   655057425) },
      {  INT32_C(  1063033344),  INT32_C(   879448657),  INT32_C(   343797048), -INT32_C(  1762534540) },
      {  INT64_C(  633649671647504568), -INT64_C( 1154561337245959500) } },
    { {  INT32_C(  1931678308),  INT32_C(   868897826), -INT32_C(  1063148113),  INT32_C(   149400583) },
      { -INT32_C(  1740159930), -INT32_C(   825445482),  INT32_C(   350374304), -INT32_C(  1985293531) },
      { -INT64_C(  372499780141288352), -INT64_C(  296604010957528573) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x4_t a = simde_vld1q_s32(test_vec[i].a);
    simde_int32x4_t b = simde_vld1q_s32(test_vec[i].b);
    simde_int64x2_t r = simde_vmull_high_s32(a, b);

    simde_test_arm_neon_assert_equal_i64x2(r, simde_vld1q_s64(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int32x4_t a = simde_test_arm_neon_random_i32x4();
    simde_int32x4_t b = simde_test_arm_neon_random_i32x4();
    simde_int64x2_t r = simde_vmull_high_s32(a, b);

    simde_test_arm_neon_write_i32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vmull_high_u8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint8_t a[16];
    uint8_t b[16];
    uint16_t r[8];
  } test_vec[] = {
    { { UINT8_C(179), UINT8_C( 51), UINT8_C( 59), UINT8_C( 26), UINT8_C(136), UINT8_C(207), UINT8_C( 24), UINT8_C(152),
        UINT8_C( 17), UINT8_C(185), UINT8_C(236), UINT8_C( 76), UINT8_C( 36), UINT8_C(205), UINT8_C( 64), UINT8_C(207) },
      { UINT8_C( 48), UINT8_C( 72), UINT8_C(171), UINT8_C( 31), UINT8_C(148), UINT8_C(163), UINT8_C(148), UINT8_C( 63),
        UINT8_C( 78), UINT8_C(254), UINT8_C(102), UINT8_C( 44), UINT8_C(198), UINT8_C(233), UINT8_C(197), UINT8_C(121) },
      { UINT16_C( 1326), UINT16_C(46990), UINT16_C(24072), UINT16_C( 3344), UINT16_C( 7128), UINT16_C(47765), UINT16_C(12608), UINT16_C(25047) } },
    { { UINT8_C( 29), UINT8_C(  1), UINT8_C(147), UINT8_C(165), UINT8_C(208), UINT8_C(171), UINT8_C( 61), UINT8_C(226),
        UINT8_C(100), UINT8_C( 42), UINT8_C( 46), UINT8_C(136), UINT8_C(247), UINT8_C(110), UINT8_C( 88), UINT8_C( 39) },
      { UINT8_C(182), UINT8_C(  3), UINT8_C( 71), UINT8_C( 75), UINT8_C(166), UINT8_C(219), UINT8_C(138), UINT8_C(244),
        UINT8_C(217), UINT8_C(240), UINT8_C( 33), UINT8_C(159), UINT8_C(218), UINT8_C(230), UINT8_C( 25), UINT8_C(247) },
      { UINT16_C(21700), UINT16_C(10080), UINT16_C( 1518), UINT16_C(21624), UINT16_C(53846), UINT16_C(25300), UINT16_C( 2200), UINT16_C( 9633) } },
    { { UINT8_C(231), UINT8_C(172), UINT8_C(156), UINT8_C(184), UINT8_C( 88), UINT8_C(217), UINT8_C(154), UINT8_C(188),
        UINT8_C(  3), UINT8_C(200), UINT8_C( 69), UINT8_C(250), UINT8_C( 55), UINT8_C(157), UINT8_C( 34), UINT8_C(237) },
      { UINT8_C(160), UINT8_C(105), UINT8_C( 56), UINT8_C( 71), UINT8_C( 68), UINT8_C(195), UINT8_C( 59), UINT8_C( 30),
        UINT8_C(179), UINT8_C( 92), UINT8_C(189), UINT8_C(141), UINT8_C( 67), UINT8_C(214), UINT8_C(132), UINT8_C( 42) },
      { UINT16_C(  537), UINT16_C(18400), UINT16_C(13041), UINT16_C(35250), UINT16_C( 3685), UINT16_C(33598), UINT16_C( 4488), UINT16_C( 9954) } },
    { { UINT8_C(131), UINT8_C( 32), UINT8_C(226), UINT8_C(219), UINT8_C(250), UINT8_C(124), UINT8_C(151), UINT8_C(253),
        UINT8_C( 69), UINT8_C(220), UINT8_C(248), UINT8_C(124), UINT8_C(121), UINT8_C( 26), UINT8_C(105), UINT8_C( 26) },
      { UINT8_C(131), UINT8_C(162), UINT8_C( 97), UINT8_C(199), UINT8_C(101), UINT8_C(156), UINT8_C(229), UINT8_C( 24),
        UINT8_C(249), UINT8_C(163), UINT8_C(166), UINT8_C( 60), UINT8_C(121), UINT8_C( 42), UINT8_C(102), UINT8_C(252) },
      { UINT16_C(17181), UINT16_C(35860), UINT16_C(41168), UINT16_C( 7440), UINT16_C(14641), UINT16_C( 1092), UINT16_C(10710), UINT16_C( 6552) } },
    { { UINT8_C( 75), UINT8_C( 73), UINT8_C(215), UINT8_C( 69), UINT8_C(197), UINT8_C(111), UINT8_C( 66), UINT8_C( 10),
        UINT8_C( 75), UINT8_C( 58), UINT8_C(134), UINT8_C(197), UINT8_C( 84), UINT8_C(240), UINT8_C(223), UINT8_C(215) },
      { UINT8_C(146), UINT8_C( 64), UINT8_C(159), UINT8_C(247), UINT8_C(220), UINT8_C(132), UINT8_C( 15), UINT8_C(213),
        UINT8_C( 39), UINT8_C(181), UINT8_C( 17), UINT8_C(161), UINT8_C(224), UINT8_C(120), UINT8_C(157), UINT8_C( 43) },
      { UINT16_C( 2925), UINT16_C(10498), UINT16_C( 2278), UINT16_C(31717), UINT16_C(18816), UINT16_C(28800), UINT16_C(35011), UINT16_C( 9245) } },
    { { UINT8_C(193), UINT8_C(117), UINT8_C(112), UINT8_C(134), UINT8_C(228), UINT8_C(178), UINT8_C(145), UINT8_C( 47),
        UINT8_C(237), UINT8_C( 23), UINT8_C(244), UINT8_C( 65), UINT8_C(  7), UINT8_C(211), UINT8_C( 25), UINT8_C(153) },
      { UINT8_C( 19), UINT8_C(184), UINT8_C(144), UINT8_C(240), UINT8_C( 60), UINT8_C(160), UINT8_C(197), UINT8_C(100),
        UINT8_C( 85), UINT8_C(215), UINT8_C(  5), UINT8_C( 53), UINT8_C( 79), UINT8_C(162), UINT8_C( 96), UINT8_C( 16) },
      { UINT16_C(20145), UINT16_C( 4945), UINT16_C( 1220), UINT16_C( 3445), UINT16_C(  553), UINT16_C(34182), UINT16_C( 2400), UINT16_C( 2448) } },
    { { UINT8_C( 23), UINT8_C(208), UINT8_C(150), UINT8_C(251), UINT8_C(131), UINT8_C( 39), UINT8_C( 43), UINT8_C(112),
        UINT8_C( 63), UINT8_C( 31), UINT8_C(177), UINT8_C( 70), UINT8_C(243), UINT8_C(202), UINT8_C(224), UINT8_C(  6) },
      { UINT8_C(130), UINT8_C(112), UINT8_C(246), UINT8_C(191), UINT8_C( 16), UINT8_C(188), UINT8_C( 35), UINT8_C(102),
        UINT8_C(147), UINT8_C( 40), UINT8_C(155), UINT8_C(226), UINT8_C(202), UINT8_C(252), UINT8_C(242), UINT8_C(226) },
      { UINT16_C( 9261), UINT16_C( 1240), UINT16_C(27435), UINT16_C(15820), UINT16_C(49086), UINT16_C(50904), UINT16_C(54208), UINT16_C( 1356) } },
    { { UINT8_C(204), UINT8_C(136), UINT8_C(221), UINT8_C( 79), UINT8_C(176), UINT8_C(  8), UINT8_C(191), UINT8_C(239),
        UINT8_C( 40), UINT8_C(113), UINT8_C( 53), UINT8_C( 27), UINT8_C( 59), UINT8_C( 21), UINT8_C( 33), UINT8_C(190) },
      { UINT8_C(134), UINT8_C( 24), UINT8_C(125), UINT8_C(150), UINT8_C(212), UINT8_C(160), UINT8_C(252), UINT8_C(103),
        UINT8_C(200), UINT8_C(152), UINT8_C( 73), UINT8_C(146), UINT8_C(148), UINT8_C( 59), UINT8_C(116), UINT8_C( 96) },
      { UINT16_C( 8000), UINT16_C(17176), UINT16_C( 3869), UINT16_C( 3942), UINT16_C( 8732), UINT16_C( 1239), UINT16_C( 3828), UINT16_C(18240) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint8x16_t a = simde_vld1q_u8(test_vec[i].a);
    simde_uint8x16_t b = simde_vld1q_u8(test_vec[i].b);
    simde_uint16x8_t r = simde_vmull_high_u8(a, b);

    simde_test_arm_neon_assert_equal_u16x8(r, simde_vld1q_u16(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint8x16_t a = simde_test_arm_neon_random_u8x16();
    simde_uint8x16_t b = simde_test_arm_neon_random_u8x16();
    simde_uint16x8_t r = simde_vmull_high_u8(a, b);

    simde_test_arm_neon_write_u8x16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u8x16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u16x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vmull_high_u16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint16_t a[8];
    uint16_t b[8];
    uint32_t r[4];
  } test_vec[] = {
    { { UINT16_C(21187), UINT16_C(29616), UINT16_C(28506), UINT16_C(33378), UINT16_C(39136), UINT16_C( 7325), UINT16_C(49069), UINT16_C(13274) },
      { UINT16_C(22487), UINT16_C(43978), UINT16_C(50935), UINT16_C(48914), UINT16_C(23390), UINT16_C(62033), UINT16_C(50838), UINT16_C(22867) },
      { UINT32_C( 915391040), UINT32_C( 454391725), UINT32_C(2494569822), UINT32_C( 303536558) } },
    { { UINT16_C(  792), UINT16_C(29389), UINT16_C(12146), UINT16_C(21493), UINT16_C(37575), UINT16_C(30063), UINT16_C(18769), UINT16_C(10408) },
      { UINT16_C(29344), UINT16_C(38867), UINT16_C(58681), UINT16_C(38742), UINT16_C(42816), UINT16_C(54922), UINT16_C(56685), UINT16_C(34096) },
      { UINT32_C(1608811200), UINT32_C(1651120086), UINT32_C(1063920765), UINT32_C( 354871168) } },
    { { UINT16_C(64992), UINT16_C(21240), UINT16_C(60716), UINT16_C(62629), UINT16_C( 5247), UINT16_C(53609), UINT16_C( 4445), UINT16_C(65017) },
      { UINT16_C(52612), UINT16_C(48532), UINT16_C(60082), UINT16_C(62292), UINT16_C(56978), UINT16_C(65481), UINT16_C(63931), UINT16_C(39813) },
      { UINT32_C( 298963566), UINT32_C(3510370929), UINT32_C( 284173295), UINT32_C(2588521821) } },
    { { UINT16_C(32246), UINT16_C( 9198), UINT16_C(37738), UINT16_C(59671), UINT16_C(32936), UINT16_C( 1466), UINT16_C(46225), UINT16_C( 5379) },
      { UINT16_C(38785), UINT16_C(13266), UINT16_C(10114), UINT16_C( 5158), UINT16_C(61445), UINT16_C(49427), UINT16_C(39145), UINT16_C(57436) },
      { UINT32_C(2023752520), UINT32_C(  72459982), UINT32_C(1809477625), UINT32_C( 308948244) } },
    { { UINT16_C(18965), UINT16_C(32515), UINT16_C( 6878), UINT16_C(34409), UINT16_C( 9114), UINT16_C(11147), UINT16_C(36567), UINT16_C(22593) },
      { UINT16_C( 4902), UINT16_C(43148), UINT16_C(45626), UINT16_C(16572), UINT16_C(53154), UINT16_C(35841), UINT16_C(23912), UINT16_C(32108) },
      { UINT32_C( 484445556), UINT32_C( 399519627), UINT32_C( 874390104), UINT32_C( 725416044) } },
    { { UINT16_C(28584), UINT16_C(34557), UINT16_C(26249), UINT16_C( 8972), UINT16_C(38793), UINT16_C(24910), UINT16_C(36646), UINT16_C(19641) },
      { UINT16_C(17827), UINT16_C(56820), UINT16_C(45304), UINT16_C(39453), UINT16_C( 7807), UINT16_C(59174), UINT16_C(37500), UINT16_C( 9317) },
      { UINT32_C( 302856951), UINT32_C(1474024340), UINT32_C(1374225000), UINT32_C( 182995197) } },
    { { UINT16_C(25089), UINT16_C(35498), UINT16_C(46792), UINT16_C(20909), UINT16_C(64589), UINT16_C(29618), UINT16_C(27787), UINT16_C(11967) },
      { UINT16_C(46001), UINT16_C(43276), UINT16_C(10595), UINT16_C(58180), UINT16_C(27208), UINT16_C(50378), UINT16_C(12285), UINT16_C(65256) },
      { UINT32_C(1757337512), UINT32_C(1492095604), UINT32_C( 341363295), UINT32_C( 780918552) } },
    { { UINT16_C(37521), UINT16_C(22921), UINT16_C(13896), UINT16_C(38315), UINT16_C(23858), UINT16_C(48649), UINT16_C(51401), UINT16_C(31724) },
      { UINT16_C(63612), UINT16_C(57124), UINT16_C(26658), UINT16_C(27330), UINT16_C(36307), UINT16_C(53294), UINT16_C( 5820), UINT16_C(20174) },
      { UINT32_C( 866212406), UINT32_C(2592699806), UINT32_C( 299153820), UINT32_C( 639999976) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint16x8_t a = simde_vld1q_u16(test_vec[i].a);
    simde_uint16x8_t b = simde_vld1q_u16(test_vec[i].b);
    simde_uint32x4_t r = simde_vmull_high_u16(a, b);

    simde_test_arm_neon_assert_equal_u32x4(r, simde_vld1q_u32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint16x8_t a = simde_test_arm_neon_random_u16x8();
    simde_uint16x8_t b = simde_test_arm_neon_random_u16x8();
    simde_uint32x4_t r = simde_vmull_high_u16(a, b);

    simde_test_arm_neon_write_u16x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u16x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vmull_high_u32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint32_t a[4];
    uint32_t b[4];
    uint64_t r[2];
  } test_vec[] = {
    { { UINT32_C(4037498792), UINT32_C(3229962894), UINT32_C(2038337200), UINT32_C(3556010839) },
      { UINT32_C(2243041635), UINT32_C(1424979329), UINT32_C(3190037762), UINT32_C(3675058995) },
      { UINT64_C( 6502372639689346400), UINT64_C(13068549620184446805) } },
    { { UINT32_C(3637228618), UINT32_C(3063501062), UINT32_C( 909121503), UINT32_C(3859358850) },
      { UINT32_C(3211508797), UINT32_C( 856906545), UINT32_C(2901489784), UINT32_C(1971846699) },
      { UINT64_C( 2637806753369225352), UINT64_C( 7610064008628936150) } },
    { { UINT32_C(3092140978), UINT32_C(2205149092), UINT32_C(2176491518), UINT32_C(  23577539) },
      { UINT32_C(2965426815), UINT32_C(2799948589), UINT32_C( 911398155), UINT32_C(2242697683) },
      { UINT64_C( 1983650353878349290), UINT64_C(   52877292086142137) } },
    { { UINT32_C(3493722668), UINT32_C(3746868449), UINT32_C( 257953355), UINT32_C(1360054225) },
      { UINT32_C(3338784922), UINT32_C(2943215011), UINT32_C(2380644282), UINT32_C(3306328473) },
      { UINT64_C(  614095179603466110), UINT64_C( 4496786008941448425) } },
    { { UINT32_C(1821790091), UINT32_C(1196223228), UINT32_C(3377900792), UINT32_C( 236611188) },
      { UINT32_C(3671399478), UINT32_C(3146334977), UINT32_C(2605215234), UINT32_C(2338413056) },
      { UINT64_C( 8800158602259065328), UINT64_C(  553294691214870528) } },
    { { UINT32_C(2784556969), UINT32_C(3656205537), UINT32_C(1688355824), UINT32_C(3765616042) },
      { UINT32_C(3669641433), UINT32_C(2375369611), UINT32_C(2989088178), UINT32_C(3762129463) },
      { UINT64_C( 5046644433775848672), UINT64_C(14166735057953645446) } },
    { { UINT32_C(1652962689), UINT32_C(1782281081), UINT32_C(1624169910), UINT32_C(1933656474) },
      { UINT32_C( 340654985), UINT32_C(4053918271), UINT32_C(4137929407), UINT32_C(3587694676) },
      { UINT64_C( 6720700432553543370), UINT64_C( 6937369036982732424) } },
    { { UINT32_C(2402770198), UINT32_C(2264494800), UINT32_C(3941058640), UINT32_C(2455644169) },
      { UINT32_C(1655089955), UINT32_C(1297303438), UINT32_C(1715795474), UINT32_C(3980139479) },
      { UINT64_C( 6762050577280595360), UINT64_C( 9773806303413047951) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint32x4_t a = simde_vld1q_u32(test_vec[i].a);
    simde_uint32x4_t b = simde_vld1q_u32(test_vec[i].b);
    simde_uint64x2_t r = simde_vmull_high_u32(a, b);

    simde_test_arm_neon_assert_equal_u64x2(r, simde_vld1q_u64(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint32x4_t a = simde_test_arm_neon_random_u32x4();
    simde_uint32x4_t b = simde_test_arm_neon_random_u32x4();
    simde_uint64x2_t r = simde_vmull_high_u32(a, b);

    simde_test_arm_neon_write_u32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(vmull_high_s8)
SIMDE_TEST_FUNC_LIST_ENTRY(vmull_high_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vmull_high_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vmull_high_u8)
SIMDE_TEST_FUNC_LIST_ENTRY(vmull_high_u16)
SIMDE_TEST_FUNC_LIST_ENTRY(vmull_high_u32)

SIMDE_TEST_FUNC_LIST_END

#include "test-neon-footer.h"
