#define SIMDE_TEST_ARM_NEON_INSN movn_high

#include "test-neon.h"
#include "../../../simde/arm/neon/movn_high.h"

static int
test_simde_vmovn_high_s16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int8_t r[8];
    int16_t a[8];
    int8_t res[16];
  } test_vec[] = {
    { { -INT8_C(  75), -INT8_C(  23), -INT8_C( 101), -INT8_C(  44), -INT8_C(  30), -INT8_C(   4), -INT8_C(  58),  INT8_C(  42) },
      { -INT16_C(  2815),  INT16_C( 20026), -INT16_C( 27075), -INT16_C(  9535), -INT16_C( 19091), -INT16_C( 13510), -INT16_C( 18313),  INT16_C( 21770) },
      { -INT8_C(  75), -INT8_C(  23), -INT8_C( 101), -INT8_C(  44), -INT8_C(  30), -INT8_C(   4), -INT8_C(  58),  INT8_C(  42),
         INT8_C(   1),  INT8_C(  58),  INT8_C(  61), -INT8_C(  63),  INT8_C( 109),  INT8_C(  58),  INT8_C( 119),  INT8_C(  10) } },
    { {  INT8_C(  77), -INT8_C(  89), -INT8_C(  42),  INT8_C(  17), -INT8_C(  17),  INT8_C(  74), -INT8_C( 118), -INT8_C(  92) },
      {  INT16_C(  9523),  INT16_C(  5496),  INT16_C( 16161),  INT16_C(  8767),  INT16_C( 31028),  INT16_C( 29297),  INT16_C( 12815),  INT16_C( 31820) },
      {  INT8_C(  77), -INT8_C(  89), -INT8_C(  42),  INT8_C(  17), -INT8_C(  17),  INT8_C(  74), -INT8_C( 118), -INT8_C(  92),
         INT8_C(  51),  INT8_C( 120),  INT8_C(  33),  INT8_C(  63),  INT8_C(  52),  INT8_C( 113),  INT8_C(  15),  INT8_C(  76) } },
    { { -INT8_C(  25), -INT8_C( 121),  INT8_C(  71),  INT8_C(  95),  INT8_C(  63),  INT8_C(  81), -INT8_C(  76), -INT8_C( 115) },
      { -INT16_C( 29959), -INT16_C(  5986),  INT16_C( 10452),  INT16_C(  1933),  INT16_C(  1357),  INT16_C( 28188),  INT16_C( 23364),  INT16_C( 31120) },
      { -INT8_C(  25), -INT8_C( 121),  INT8_C(  71),  INT8_C(  95),  INT8_C(  63),  INT8_C(  81), -INT8_C(  76), -INT8_C( 115),
        -INT8_C(   7), -INT8_C(  98), -INT8_C(  44), -INT8_C( 115),  INT8_C(  77),  INT8_C(  28),  INT8_C(  68), -INT8_C( 112) } },
    { { -INT8_C(  44),  INT8_C(   1), -INT8_C(  21), -INT8_C(  29),  INT8_C(  51),  INT8_C(  55),  INT8_C(  96),  INT8_C(  27) },
      { -INT16_C( 22594), -INT16_C(   390),  INT16_C( 12025), -INT16_C(  3445),  INT16_C( 10681), -INT16_C( 29222),  INT16_C( 26449), -INT16_C( 24939) },
      { -INT8_C(  44),  INT8_C(   1), -INT8_C(  21), -INT8_C(  29),  INT8_C(  51),  INT8_C(  55),  INT8_C(  96),  INT8_C(  27),
        -INT8_C(  66),  INT8_C( 122), -INT8_C(   7), -INT8_C( 117), -INT8_C(  71), -INT8_C(  38),  INT8_C(  81), -INT8_C( 107) } },
    { {  INT8_C( 109), -INT8_C(  79),  INT8_C(  12), -INT8_C(  79),  INT8_C(  13), -INT8_C( 100),  INT8_C(  42), -INT8_C(  31) },
      {  INT16_C(  5534), -INT16_C( 11835),  INT16_C(  9549),  INT16_C(  3052),  INT16_C( 26316), -INT16_C( 15095), -INT16_C( 27499),  INT16_C( 20151) },
      {  INT8_C( 109), -INT8_C(  79),  INT8_C(  12), -INT8_C(  79),  INT8_C(  13), -INT8_C( 100),  INT8_C(  42), -INT8_C(  31),
        -INT8_C(  98), -INT8_C(  59),  INT8_C(  77), -INT8_C(  20), -INT8_C(  52),  INT8_C(   9), -INT8_C( 107), -INT8_C(  73) } },
    { { -INT8_C(  67), -INT8_C( 110), -INT8_C(  37),  INT8_C(  14), -INT8_C(   7),  INT8_C( 112), -INT8_C(  84),  INT8_C( 102) },
      { -INT16_C( 18398),  INT16_C( 12056),  INT16_C( 16981), -INT16_C(  3312), -INT16_C( 10920), -INT16_C( 23100), -INT16_C( 19974), -INT16_C( 14416) },
      { -INT8_C(  67), -INT8_C( 110), -INT8_C(  37),  INT8_C(  14), -INT8_C(   7),  INT8_C( 112), -INT8_C(  84),  INT8_C( 102),
         INT8_C(  34),  INT8_C(  24),  INT8_C(  85),  INT8_C(  16),  INT8_C(  88), -INT8_C(  60), -INT8_C(   6), -INT8_C(  80) } },
    { {  INT8_C(  23), -INT8_C(  70), -INT8_C( 116), -INT8_C(  84),  INT8_C(  78),  INT8_C(  68), -INT8_C(   6),  INT8_C(  12) },
      { -INT16_C( 10538), -INT16_C( 12518), -INT16_C( 14522),  INT16_C( 26678),  INT16_C( 20095), -INT16_C( 11113), -INT16_C( 22384), -INT16_C(  5945) },
      {  INT8_C(  23), -INT8_C(  70), -INT8_C( 116), -INT8_C(  84),  INT8_C(  78),  INT8_C(  68), -INT8_C(   6),  INT8_C(  12),
        -INT8_C(  42),  INT8_C(  26),  INT8_C(  70),  INT8_C(  54),      INT8_MAX, -INT8_C( 105), -INT8_C( 112), -INT8_C(  57) } },
    { {  INT8_C( 125), -INT8_C( 116), -INT8_C( 115),  INT8_C( 120),  INT8_C(  61),  INT8_C(  62),  INT8_C(  63),  INT8_C(  84) },
      { -INT16_C( 13320),  INT16_C( 17921), -INT16_C(  1265), -INT16_C(  6830),  INT16_C( 28113),  INT16_C(  6325), -INT16_C(  5324), -INT16_C( 19584) },
      {  INT8_C( 125), -INT8_C( 116), -INT8_C( 115),  INT8_C( 120),  INT8_C(  61),  INT8_C(  62),  INT8_C(  63),  INT8_C(  84),
        -INT8_C(   8),  INT8_C(   1),  INT8_C(  15),  INT8_C(  82), -INT8_C(  47), -INT8_C(  75),  INT8_C(  52),      INT8_MIN } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int8x8_t r = simde_vld1_s8(test_vec[i].r);
    simde_int16x8_t a = simde_vld1q_s16(test_vec[i].a);
    simde_int8x16_t res = simde_vmovn_high_s16(r, a);

    simde_test_arm_neon_assert_equal_i8x16(res, simde_vld1q_s8(test_vec[i].res));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int8x8_t r = simde_test_arm_neon_random_i8x8();
    simde_int16x8_t a = simde_test_arm_neon_random_i16x8();
    simde_int8x16_t res = simde_vmovn_high_s16(r, a);

    simde_test_arm_neon_write_i8x8(2, r, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i16x8(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i8x16(2, res, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vmovn_high_s32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int16_t r[4];
    int32_t a[4];
    int16_t res[8];
  } test_vec[] = {
    { {  INT16_C( 16471), -INT16_C( 23696), -INT16_C( 17690), -INT16_C(  5790) },
      {  INT32_C(   191683823), -INT32_C(   713549285), -INT32_C(  2095428269), -INT32_C(   654902461) },
      {  INT16_C( 16471), -INT16_C( 23696), -INT16_C( 17690), -INT16_C(  5790), -INT16_C(  8977),  INT16_C(  6683),  INT16_C( 19795), -INT16_C(  1213) } },
    { { -INT16_C(  3155),  INT16_C( 24211), -INT16_C(  1303),  INT16_C( 16724) },
      {  INT32_C(   568640570),  INT32_C(  1846167166),  INT32_C(  1031370530), -INT32_C(   468520303) },
      { -INT16_C(  3155),  INT16_C( 24211), -INT16_C(  1303),  INT16_C( 16724), -INT16_C( 15302),  INT16_C( 18046),  INT16_C( 30498), -INT16_C(  3439) } },
    { {  INT16_C( 11583), -INT16_C( 32153),  INT16_C( 24104), -INT16_C( 10918) },
      {  INT32_C(   993259089),  INT32_C(   578586600), -INT32_C(   901554101), -INT32_C(   935833946) },
      {  INT16_C( 11583), -INT16_C( 32153),  INT16_C( 24104), -INT16_C( 10918), -INT16_C(  4527), -INT16_C( 30744),  INT16_C( 24651),  INT16_C( 20134) } },
    { { -INT16_C( 20027),  INT16_C( 22021),  INT16_C(  6051), -INT16_C(  7621) },
      {  INT32_C(  1818600004),  INT32_C(  1380105984), -INT32_C(  1785891411),  INT32_C(  1220020733) },
      { -INT16_C( 20027),  INT16_C( 22021),  INT16_C(  6051), -INT16_C(  7621), -INT16_C( 23996), -INT16_C( 16640),  INT16_C( 30125),  INT16_C(  2557) } },
    { { -INT16_C(  1175),  INT16_C(  3858),  INT16_C( 19017),  INT16_C(  3799) },
      { -INT32_C(  1620714244),  INT32_C(   948084979),  INT32_C(  1134880578),  INT32_C(  1419110054) },
      { -INT16_C(  1175),  INT16_C(  3858),  INT16_C( 19017),  INT16_C(  3799), -INT16_C(  8964), -INT16_C( 24333), -INT16_C(  6334), -INT16_C(  6490) } },
    { {  INT16_C(  8796),  INT16_C( 23017), -INT16_C( 24277), -INT16_C( 27487) },
      { -INT32_C(   425479011), -INT32_C(    84575490),  INT32_C(  1234852438),  INT32_C(  1015094522) },
      {  INT16_C(  8796),  INT16_C( 23017), -INT16_C( 24277), -INT16_C( 27487), -INT16_C( 19299),  INT16_C( 31486),  INT16_C( 23126),  INT16_C(  7418) } },
    { {  INT16_C(  9731), -INT16_C( 22145),  INT16_C(  5132),  INT16_C( 26877) },
      {  INT32_C(  1640097590),  INT32_C(   636838792),  INT32_C(   353146903),  INT32_C(  1745879314) },
      {  INT16_C(  9731), -INT16_C( 22145),  INT16_C(  5132),  INT16_C( 26877), -INT16_C(  6346),  INT16_C( 25480), -INT16_C( 26601),  INT16_C(   274) } },
    { { -INT16_C( 21925),  INT16_C( 21938),  INT16_C( 13254), -INT16_C( 13935) },
      {  INT32_C(  1718751577),  INT32_C(  1557032997), -INT32_C(   541224873),  INT32_C(   168145907) },
      { -INT16_C( 21925),  INT16_C( 21938),  INT16_C( 13254), -INT16_C( 13935),  INT16_C(  4441),  INT16_C( 28709), -INT16_C( 28585), -INT16_C( 19469) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x4_t r = simde_vld1_s16(test_vec[i].r);
    simde_int32x4_t a = simde_vld1q_s32(test_vec[i].a);
    simde_int16x8_t res = simde_vmovn_high_s32(r, a);

    simde_test_arm_neon_assert_equal_i16x8(res, simde_vld1q_s16(test_vec[i].res));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int16x4_t r = simde_test_arm_neon_random_i16x4();
    simde_int32x4_t a = simde_test_arm_neon_random_i32x4();
    simde_int16x8_t res = simde_vmovn_high_s32(r, a);

    simde_test_arm_neon_write_i16x4(2, r, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i32x4(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i16x8(2, res, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vmovn_high_s64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int32_t r[2];
    int64_t a[2];
    int32_t res[4];
  } test_vec[] = {
    { { -INT32_C(  1624253440), -INT32_C(  1322384523) },
      {  INT64_C( 5771356035658123911), -INT64_C( 4696279848783989999) },
      { -INT32_C(  1624253440), -INT32_C(  1322384523), -INT32_C(  1984591225),  INT32_C(   124236561) } },
    { { -INT32_C(  1855335696), -INT32_C(  2096352893) },
      { -INT64_C( 4236953495512401139), -INT64_C(  871614883780630309) },
      { -INT32_C(  1855335696), -INT32_C(  2096352893), -INT32_C(  2111685875), -INT32_C(  1756370725) } },
    { {  INT32_C(  1996115482), -INT32_C(  1271542332) },
      { -INT64_C( 2547257489644675425), -INT64_C(  823717716859893619) },
      {  INT32_C(  1996115482), -INT32_C(  1271542332),  INT32_C(   575053471), -INT32_C(   882980723) } },
    { {  INT32_C(  1535893626),  INT32_C(  1615753798) },
      { -INT64_C( 5387980717616052031),  INT64_C( 6869535149564330154) },
      {  INT32_C(  1535893626),  INT32_C(  1615753798), -INT32_C(  2049488703),  INT32_C(  2044166314) } },
    { {  INT32_C(  1596633926), -INT32_C(  1101743292) },
      {  INT64_C( 1387786340373553051), -INT64_C( 3495969626035578447) },
      {  INT32_C(  1596633926), -INT32_C(  1101743292), -INT32_C(   501555301), -INT32_C(   963110479) } },
    { {  INT32_C(   608719698),  INT32_C(   377724368) },
      {  INT64_C(  383872948084584016), -INT64_C( 8714982225589342807) },
      {  INT32_C(   608719698),  INT32_C(   377724368), -INT32_C(  1787384240), -INT32_C(    68719191) } },
    { {  INT32_C(  1749919555), -INT32_C(   868693639) },
      {  INT64_C( 7927307445275230236), -INT64_C( 1400523536505538270) },
      {  INT32_C(  1749919555), -INT32_C(   868693639), -INT32_C(   319782884), -INT32_C(  1962706654) } },
    { { -INT32_C(  1696041020), -INT32_C(   467536223) },
      {  INT64_C( 6116878095343185821),  INT64_C( 7606935218418668293) },
      { -INT32_C(  1696041020), -INT32_C(   467536223),  INT32_C(   390885277),  INT32_C(   591450885) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x2_t r = simde_vld1_s32(test_vec[i].r);
    simde_int64x2_t a = simde_vld1q_s64(test_vec[i].a);
    simde_int32x4_t res = simde_vmovn_high_s64(r, a);

    simde_test_arm_neon_assert_equal_i32x4(res, simde_vld1q_s32(test_vec[i].res));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int32x2_t r = simde_test_arm_neon_random_i32x2();
    simde_int64x2_t a = simde_test_arm_neon_random_i64x2();
    simde_int32x4_t res = simde_vmovn_high_s64(r, a);

    simde_test_arm_neon_write_i32x2(2, r, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i64x2(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i32x4(2, res, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vmovn_high_u16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint8_t r[8];
    uint16_t a[8];
    uint8_t res[16];
  } test_vec[] = {
    { { UINT8_C(213), UINT8_C(212), UINT8_C(127), UINT8_C(175), UINT8_C(133), UINT8_C( 47), UINT8_C( 76), UINT8_C( 45) },
      { UINT16_C(46071), UINT16_C(11665), UINT16_C(45861), UINT16_C(64159), UINT16_C(43655), UINT16_C(56017), UINT16_C( 9101), UINT16_C(43587) },
      { UINT8_C(213), UINT8_C(212), UINT8_C(127), UINT8_C(175), UINT8_C(133), UINT8_C( 47), UINT8_C( 76), UINT8_C( 45),
        UINT8_C(247), UINT8_C(145), UINT8_C( 37), UINT8_C(159), UINT8_C(135), UINT8_C(209), UINT8_C(141), UINT8_C( 67) } },
    { { UINT8_C(112), UINT8_C(211), UINT8_C(183), UINT8_C(247), UINT8_C(  1), UINT8_C(237), UINT8_C( 68), UINT8_C(215) },
      { UINT16_C(50113), UINT16_C(18310), UINT16_C(54002), UINT16_C(60020), UINT16_C( 1413), UINT16_C(43543), UINT16_C(46776), UINT16_C(16548) },
      { UINT8_C(112), UINT8_C(211), UINT8_C(183), UINT8_C(247), UINT8_C(  1), UINT8_C(237), UINT8_C( 68), UINT8_C(215),
        UINT8_C(193), UINT8_C(134), UINT8_C(242), UINT8_C(116), UINT8_C(133), UINT8_C( 23), UINT8_C(184), UINT8_C(164) } },
    { { UINT8_C( 96), UINT8_C(118), UINT8_C( 26), UINT8_C(238), UINT8_C(153), UINT8_C( 93), UINT8_C(152), UINT8_C(  9) },
      { UINT16_C(20272), UINT16_C(12800), UINT16_C(17468), UINT16_C(64777), UINT16_C(36615), UINT16_C(63812), UINT16_C(47457), UINT16_C(59363) },
      { UINT8_C( 96), UINT8_C(118), UINT8_C( 26), UINT8_C(238), UINT8_C(153), UINT8_C( 93), UINT8_C(152), UINT8_C(  9),
        UINT8_C( 48), UINT8_C(  0), UINT8_C( 60), UINT8_C(  9), UINT8_C(  7), UINT8_C( 68), UINT8_C( 97), UINT8_C(227) } },
    { { UINT8_C(190), UINT8_C(250), UINT8_C(145), UINT8_C(119), UINT8_C(176), UINT8_C( 54), UINT8_C(183), UINT8_C( 17) },
      { UINT16_C(53676), UINT16_C(17919), UINT16_C(38703), UINT16_C(24398), UINT16_C(20198), UINT16_C( 8849), UINT16_C(39570), UINT16_C(39199) },
      { UINT8_C(190), UINT8_C(250), UINT8_C(145), UINT8_C(119), UINT8_C(176), UINT8_C( 54), UINT8_C(183), UINT8_C( 17),
        UINT8_C(172),    UINT8_MAX, UINT8_C( 47), UINT8_C( 78), UINT8_C(230), UINT8_C(145), UINT8_C(146), UINT8_C( 31) } },
    { { UINT8_C( 41), UINT8_C(100), UINT8_C(146), UINT8_C(139), UINT8_C( 29), UINT8_C(118), UINT8_C(114), UINT8_C(219) },
      { UINT16_C(  880), UINT16_C( 8530), UINT16_C( 2361), UINT16_C(58674), UINT16_C(12763), UINT16_C( 2602), UINT16_C(30920), UINT16_C(44649) },
      { UINT8_C( 41), UINT8_C(100), UINT8_C(146), UINT8_C(139), UINT8_C( 29), UINT8_C(118), UINT8_C(114), UINT8_C(219),
        UINT8_C(112), UINT8_C( 82), UINT8_C( 57), UINT8_C( 50), UINT8_C(219), UINT8_C( 42), UINT8_C(200), UINT8_C(105) } },
    { { UINT8_C(198), UINT8_C(251), UINT8_C(208), UINT8_C( 88), UINT8_C(149), UINT8_C(239), UINT8_C(241), UINT8_C(191) },
      { UINT16_C(33875), UINT16_C(28746), UINT16_C(48378), UINT16_C(27212), UINT16_C(40639), UINT16_C(63883), UINT16_C(48552), UINT16_C(33758) },
      { UINT8_C(198), UINT8_C(251), UINT8_C(208), UINT8_C( 88), UINT8_C(149), UINT8_C(239), UINT8_C(241), UINT8_C(191),
        UINT8_C( 83), UINT8_C( 74), UINT8_C(250), UINT8_C( 76), UINT8_C(191), UINT8_C(139), UINT8_C(168), UINT8_C(222) } },
    { { UINT8_C(238), UINT8_C(  9), UINT8_C(141), UINT8_C(182), UINT8_C(129), UINT8_C(246), UINT8_C(100), UINT8_C( 72) },
      { UINT16_C(13553), UINT16_C(34720), UINT16_C(37412), UINT16_C(30534), UINT16_C(36886), UINT16_C( 4328), UINT16_C(13388), UINT16_C( 2938) },
      { UINT8_C(238), UINT8_C(  9), UINT8_C(141), UINT8_C(182), UINT8_C(129), UINT8_C(246), UINT8_C(100), UINT8_C( 72),
        UINT8_C(241), UINT8_C(160), UINT8_C( 36), UINT8_C( 70), UINT8_C( 22), UINT8_C(232), UINT8_C( 76), UINT8_C(122) } },
    { { UINT8_C(210), UINT8_C(  6), UINT8_C(  4), UINT8_C(122), UINT8_C(195), UINT8_C(227), UINT8_C(253), UINT8_C(178) },
      { UINT16_C(35564), UINT16_C(28008), UINT16_C(52609), UINT16_C(29365), UINT16_C(22017), UINT16_C( 9721), UINT16_C(16360), UINT16_C(65181) },
      { UINT8_C(210), UINT8_C(  6), UINT8_C(  4), UINT8_C(122), UINT8_C(195), UINT8_C(227), UINT8_C(253), UINT8_C(178),
        UINT8_C(236), UINT8_C(104), UINT8_C(129), UINT8_C(181), UINT8_C(  1), UINT8_C(249), UINT8_C(232), UINT8_C(157) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint8x8_t r = simde_vld1_u8(test_vec[i].r);
    simde_uint16x8_t a = simde_vld1q_u16(test_vec[i].a);
    simde_uint8x16_t res = simde_vmovn_high_u16(r, a);

    simde_test_arm_neon_assert_equal_u8x16(res, simde_vld1q_u8(test_vec[i].res));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint8x8_t r = simde_test_arm_neon_random_u8x8();
    simde_uint16x8_t a = simde_test_arm_neon_random_u16x8();
    simde_uint8x16_t res = simde_vmovn_high_u16(r, a);

    simde_test_arm_neon_write_u8x8(2, r, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u16x8(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u8x16(2, res, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vmovn_high_u32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint16_t r[4];
    uint32_t a[4];
    uint16_t res[8];
  } test_vec[] = {
    { { UINT16_C(34255), UINT16_C( 6926), UINT16_C(35001), UINT16_C(35623) },
      { UINT32_C(1376136078), UINT32_C(4194566926), UINT32_C( 258501774), UINT32_C( 998317369) },
      { UINT16_C(34255), UINT16_C( 6926), UINT16_C(35001), UINT16_C(35623), UINT16_C(11150), UINT16_C(  782), UINT16_C(27790), UINT16_C( 7481) } },
    { { UINT16_C(31603), UINT16_C(23392), UINT16_C(64954), UINT16_C(35417) },
      { UINT32_C(1000695682), UINT32_C(2127023344), UINT32_C( 114347512), UINT32_C(1577178320) },
      { UINT16_C(31603), UINT16_C(23392), UINT16_C(64954), UINT16_C(35417), UINT16_C(26498), UINT16_C(52464), UINT16_C(52728), UINT16_C(54480) } },
    { { UINT16_C(26945), UINT16_C(31341), UINT16_C(61318), UINT16_C(64181) },
      { UINT32_C( 609556074), UINT32_C(2528030483), UINT32_C( 114381846), UINT32_C( 411408416) },
      { UINT16_C(26945), UINT16_C(31341), UINT16_C(61318), UINT16_C(64181), UINT16_C( 5738), UINT16_C(44819), UINT16_C(21526), UINT16_C(38944) } },
    { { UINT16_C(21861), UINT16_C(13855), UINT16_C( 8234), UINT16_C(27540) },
      { UINT32_C( 266666633), UINT32_C(1527356401), UINT32_C(3296681905), UINT32_C( 609889806) },
      { UINT16_C(21861), UINT16_C(13855), UINT16_C( 8234), UINT16_C(27540), UINT16_C(  649), UINT16_C(39921), UINT16_C(24497), UINT16_C(11790) } },
    { { UINT16_C(11394), UINT16_C(41515), UINT16_C(45252), UINT16_C(10939) },
      { UINT32_C( 794876421), UINT32_C(2207970554), UINT32_C(3885138166), UINT32_C(3426917403) },
      { UINT16_C(11394), UINT16_C(41515), UINT16_C(45252), UINT16_C(10939), UINT16_C(55813), UINT16_C(62714), UINT16_C(33014), UINT16_C(39963) } },
    { { UINT16_C(49915), UINT16_C( 2448), UINT16_C(60400), UINT16_C(29229) },
      { UINT32_C(3675543575), UINT32_C( 235261704), UINT32_C(2738709929), UINT32_C(1344723034) },
      { UINT16_C(49915), UINT16_C( 2448), UINT16_C(60400), UINT16_C(29229), UINT16_C(22551), UINT16_C(53000), UINT16_C(26025), UINT16_C(55386) } },
    { { UINT16_C(47448), UINT16_C(29496), UINT16_C(31317), UINT16_C(20543) },
      { UINT32_C( 744083260), UINT32_C(3516827322), UINT32_C(3886920671), UINT32_C( 754299522) },
      { UINT16_C(47448), UINT16_C(29496), UINT16_C(31317), UINT16_C(20543), UINT16_C(53052), UINT16_C(34490), UINT16_C(46047), UINT16_C(45698) } },
    { { UINT16_C(13080), UINT16_C(29391), UINT16_C(62987), UINT16_C(25538) },
      { UINT32_C(  81197743), UINT32_C(2975077749), UINT32_C(2682170852), UINT32_C( 309361715) },
      { UINT16_C(13080), UINT16_C(29391), UINT16_C(62987), UINT16_C(25538), UINT16_C(64175), UINT16_C( 5493), UINT16_C(44516), UINT16_C(31795) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint16x4_t r = simde_vld1_u16(test_vec[i].r);
    simde_uint32x4_t a = simde_vld1q_u32(test_vec[i].a);
    simde_uint16x8_t res = simde_vmovn_high_u32(r, a);

    simde_test_arm_neon_assert_equal_u16x8(res, simde_vld1q_u16(test_vec[i].res));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint16x4_t r = simde_test_arm_neon_random_u16x4();
    simde_uint32x4_t a = simde_test_arm_neon_random_u32x4();
    simde_uint16x8_t res = simde_vmovn_high_u32(r, a);

    simde_test_arm_neon_write_u16x4(2, r, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u32x4(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u16x8(2, res, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vmovn_high_u64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint32_t r[2];
    uint64_t a[2];
    uint32_t res[4];
  } test_vec[] = {
    { { UINT32_C(3002735919), UINT32_C(3906924496) },
      { UINT64_C( 5949286594922589474), UINT64_C( 6934886448832603671) },
      { UINT32_C(3002735919), UINT32_C(3906924496), UINT32_C( 760917282), UINT32_C(2354472471) } },
    { { UINT32_C(2348751703), UINT32_C(3348983704) },
      { UINT64_C(12197251404703307661), UINT64_C(15202859022808489733) },
      { UINT32_C(2348751703), UINT32_C(3348983704), UINT32_C(1568249741), UINT32_C(2832703237) } },
    { { UINT32_C(1230918094), UINT32_C(1403624700) },
      { UINT64_C(11896113384583506103), UINT64_C(17096869149747089427) },
      { UINT32_C(1230918094), UINT32_C(1403624700), UINT32_C(1339992247), UINT32_C(2583859219) } },
    { { UINT32_C(2710903782), UINT32_C(1349816450) },
      { UINT64_C( 2752054990760235746), UINT64_C(11504881256092733676) },
      { UINT32_C(2710903782), UINT32_C(1349816450), UINT32_C(3734688482), UINT32_C(  74780908) } },
    { { UINT32_C(  87730973), UINT32_C(3639770866) },
      { UINT64_C(18045058494762682265), UINT64_C( 3842706591977047744) },
      { UINT32_C(  87730973), UINT32_C(3639770866), UINT32_C( 460949401), UINT32_C( 785909440) } },
    { { UINT32_C(2772027929), UINT32_C(1933959766) },
      { UINT64_C(10833245065660891021), UINT64_C( 9080415450746180082) },
      { UINT32_C(2772027929), UINT32_C(1933959766), UINT32_C(2138603405), UINT32_C( 179425778) } },
    { { UINT32_C(1840110627), UINT32_C(4288807397) },
      { UINT64_C( 5518573921246698699), UINT64_C( 7708794187185589864) },
      { UINT32_C(1840110627), UINT32_C(4288807397), UINT32_C( 581229771), UINT32_C(1707806312) } },
    { { UINT32_C(2993991156), UINT32_C(3996219594) },
      { UINT64_C(12338171789356818004), UINT64_C( 3450991823874285017) },
      { UINT32_C(2993991156), UINT32_C(3996219594), UINT32_C( 979099220), UINT32_C(2563628505) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint32x2_t r = simde_vld1_u32(test_vec[i].r);
    simde_uint64x2_t a = simde_vld1q_u64(test_vec[i].a);
    simde_uint32x4_t res = simde_vmovn_high_u64(r, a);

    simde_test_arm_neon_assert_equal_u32x4(res, simde_vld1q_u32(test_vec[i].res));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint32x2_t r = simde_test_arm_neon_random_u32x2();
    simde_uint64x2_t a = simde_test_arm_neon_random_u64x2();
    simde_uint32x4_t res = simde_vmovn_high_u64(r, a);

    simde_test_arm_neon_write_u32x2(2, r, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u64x2(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x4(2, res, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(vmovn_high_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vmovn_high_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vmovn_high_s64)
SIMDE_TEST_FUNC_LIST_ENTRY(vmovn_high_u16)
SIMDE_TEST_FUNC_LIST_ENTRY(vmovn_high_u32)
SIMDE_TEST_FUNC_LIST_ENTRY(vmovn_high_u64)
SIMDE_TEST_FUNC_LIST_END

#include "test-neon-footer.h"
