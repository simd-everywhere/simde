#define SIMDE_TEST_MIPS_MSA_INSN adds

#include "test-msa.h"
#include "../../../simde/mips/msa/adds.h"

static int
test_simde_adds_s_b (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int8_t a[16];
    int8_t b[16];
    int8_t r[16];
  } test_vec[] = {
    { { -INT8_C(  53), -INT8_C(  15),  INT8_C( 120), -INT8_C(  91),  INT8_C(  31),  INT8_C(  83), -INT8_C(   2), -INT8_C(  62),
        -INT8_C( 117), -INT8_C(  67), -INT8_C(  40), -INT8_C(  64), -INT8_C(  94),  INT8_C(  63),  INT8_C(  23), -INT8_C( 126) },
      { -INT8_C(  74),  INT8_C( 103), -INT8_C(  35),  INT8_C(  48),  INT8_C(  33),  INT8_C(  34),  INT8_C( 120),  INT8_C(  39),
        -INT8_C(  72), -INT8_C(  77),  INT8_C(  53), -INT8_C(  64),  INT8_C(   1),  INT8_C( 112), -INT8_C(  47), -INT8_C(  52) },
      { -INT8_C( 127),  INT8_C(  88),  INT8_C(  85), -INT8_C(  43),  INT8_C(  64),  INT8_C( 117),  INT8_C( 118), -INT8_C(  23),
             INT8_MIN,      INT8_MIN,  INT8_C(  13),      INT8_MIN, -INT8_C(  93),      INT8_MAX, -INT8_C(  24),      INT8_MIN } },
    { {  INT8_C(  97),  INT8_C(  73),  INT8_C( 113),      INT8_MIN, -INT8_C( 100),  INT8_C( 111),  INT8_C(  67),  INT8_C(  39),
         INT8_C(  45),  INT8_C(  27), -INT8_C(  24), -INT8_C(  49),  INT8_C(  90), -INT8_C(   1),  INT8_C(  81),  INT8_C(  16) },
      {  INT8_C( 102),  INT8_C(  46),  INT8_C(  64), -INT8_C( 121),  INT8_C(  80), -INT8_C(  72), -INT8_C(  82),  INT8_C(   8),
         INT8_C( 107), -INT8_C(  29), -INT8_C(  56),  INT8_C( 108),  INT8_C(  83), -INT8_C( 102),  INT8_C(  56), -INT8_C(  76) },
      {      INT8_MAX,  INT8_C( 119),      INT8_MAX,      INT8_MIN, -INT8_C(  20),  INT8_C(  39), -INT8_C(  15),  INT8_C(  47),
             INT8_MAX, -INT8_C(   2), -INT8_C(  80),  INT8_C(  59),      INT8_MAX, -INT8_C( 103),      INT8_MAX, -INT8_C(  60) } },
    { { -INT8_C(  29), -INT8_C(  87),  INT8_C(  53),      INT8_MIN,  INT8_C(  25),  INT8_C( 120), -INT8_C(  89),  INT8_C(  70),
        -INT8_C( 109), -INT8_C( 113),  INT8_C(  21), -INT8_C(  19), -INT8_C( 114),  INT8_C( 102), -INT8_C(   3), -INT8_C(  12) },
      { -INT8_C( 108),  INT8_C(  61),  INT8_C( 123), -INT8_C(  28), -INT8_C(  11),  INT8_C(  42), -INT8_C(  20),  INT8_C(  96),
         INT8_C(  13), -INT8_C(  75), -INT8_C(  52),  INT8_C(  97),  INT8_C(  79),  INT8_C(   4),  INT8_C(  21),  INT8_C(  50) },
      {      INT8_MIN, -INT8_C(  26),      INT8_MAX,      INT8_MIN,  INT8_C(  14),      INT8_MAX, -INT8_C( 109),      INT8_MAX,
        -INT8_C(  96),      INT8_MIN, -INT8_C(  31),  INT8_C(  78), -INT8_C(  35),  INT8_C( 106),  INT8_C(  18),  INT8_C(  38) } },
    { { -INT8_C(  83),  INT8_C(  74), -INT8_C(  78), -INT8_C(  58), -INT8_C(  62),  INT8_C(  90),  INT8_C(  12),  INT8_C(  85),
        -INT8_C(  23),  INT8_C(  33),  INT8_C(  66),  INT8_C( 120), -INT8_C( 121),  INT8_C(  63),  INT8_C( 108),  INT8_C(  27) },
      {  INT8_C( 124), -INT8_C(  24), -INT8_C(   1),  INT8_C( 113),  INT8_C(  18), -INT8_C(  20), -INT8_C(  47),  INT8_C(  31),
        -INT8_C(  95), -INT8_C(  99),      INT8_MIN, -INT8_C(  16), -INT8_C(  95), -INT8_C( 106),  INT8_C(  34),  INT8_C(  79) },
      {  INT8_C(  41),  INT8_C(  50), -INT8_C(  79),  INT8_C(  55), -INT8_C(  44),  INT8_C(  70), -INT8_C(  35),  INT8_C( 116),
        -INT8_C( 118), -INT8_C(  66), -INT8_C(  62),  INT8_C( 104),      INT8_MIN, -INT8_C(  43),      INT8_MAX,  INT8_C( 106) } },
    { { -INT8_C(  32), -INT8_C(  43),  INT8_C(  21), -INT8_C(  93),  INT8_C(  47),  INT8_C(  34), -INT8_C(   8),  INT8_C(  24),
         INT8_C(  67),  INT8_C(  59), -INT8_C( 112), -INT8_C(  53),  INT8_C( 122), -INT8_C(   3), -INT8_C(  26), -INT8_C(   9) },
      { -INT8_C(  27), -INT8_C(  26),  INT8_C( 104), -INT8_C(   9), -INT8_C(  46),  INT8_C(  58),  INT8_C(  22),  INT8_C( 115),
        -INT8_C(  41), -INT8_C( 105),  INT8_C(  99),  INT8_C( 121),  INT8_C(  45), -INT8_C( 123), -INT8_C(  56),  INT8_C(  13) },
      { -INT8_C(  59), -INT8_C(  69),  INT8_C( 125), -INT8_C( 102),  INT8_C(   1),  INT8_C(  92),  INT8_C(  14),      INT8_MAX,
         INT8_C(  26), -INT8_C(  46), -INT8_C(  13),  INT8_C(  68),      INT8_MAX, -INT8_C( 126), -INT8_C(  82),  INT8_C(   4) } },
    { {  INT8_C(  90), -INT8_C(  35), -INT8_C(  80), -INT8_C( 119), -INT8_C(   1), -INT8_C(  87), -INT8_C(  94),  INT8_C(  67),
        -INT8_C(  28),  INT8_C(  50),  INT8_C(  14),  INT8_C(  94),  INT8_C(  47), -INT8_C(  12),  INT8_C(  85),  INT8_C(  20) },
      { -INT8_C(  38), -INT8_C(  66),  INT8_C(  11), -INT8_C(  84), -INT8_C(   8),  INT8_C(  34),  INT8_C(  31), -INT8_C(  49),
        -INT8_C(  71), -INT8_C( 126),  INT8_C(  72), -INT8_C(  26),  INT8_C(   8),  INT8_C(  16), -INT8_C(  13),  INT8_C(  98) },
      {  INT8_C(  52), -INT8_C( 101), -INT8_C(  69),      INT8_MIN, -INT8_C(   9), -INT8_C(  53), -INT8_C(  63),  INT8_C(  18),
        -INT8_C(  99), -INT8_C(  76),  INT8_C(  86),  INT8_C(  68),  INT8_C(  55),  INT8_C(   4),  INT8_C(  72),  INT8_C( 118) } },
    { { -INT8_C(  18), -INT8_C(  92), -INT8_C(  20), -INT8_C(  19),  INT8_C(  77), -INT8_C( 114),  INT8_C(  48),  INT8_C(  49),
        -INT8_C(  64),  INT8_C(  62), -INT8_C( 113), -INT8_C(  16),  INT8_C(  51), -INT8_C(  27),  INT8_C(   4),  INT8_C(  13) },
      { -INT8_C(  93),  INT8_C(  16), -INT8_C(  70), -INT8_C( 101),  INT8_C(  50), -INT8_C(  39),  INT8_C( 106), -INT8_C(  21),
         INT8_C(  92), -INT8_C(  77), -INT8_C(  47),  INT8_C( 100), -INT8_C(  61), -INT8_C(  60), -INT8_C(  58), -INT8_C(  79) },
      { -INT8_C( 111), -INT8_C(  76), -INT8_C(  90), -INT8_C( 120),      INT8_MAX,      INT8_MIN,      INT8_MAX,  INT8_C(  28),
         INT8_C(  28), -INT8_C(  15),      INT8_MIN,  INT8_C(  84), -INT8_C(  10), -INT8_C(  87), -INT8_C(  54), -INT8_C(  66) } },
    { {  INT8_C( 104), -INT8_C(  78), -INT8_C(  97), -INT8_C(  75),  INT8_C(  64), -INT8_C(  49), -INT8_C(  26),  INT8_C(   1),
         INT8_C(  14),  INT8_C( 118), -INT8_C(  15),  INT8_C(  65),  INT8_C(  91), -INT8_C(  11),  INT8_C(  78), -INT8_C(   2) },
      {  INT8_C(   5),  INT8_C(   8), -INT8_C( 103),  INT8_C(  55), -INT8_C(  30),  INT8_C(   3),  INT8_C(  34),  INT8_C(  62),
        -INT8_C(  74), -INT8_C(  13), -INT8_C(  94),  INT8_C( 122), -INT8_C(  72),  INT8_C( 104),  INT8_C(  43),  INT8_C(  32) },
      {  INT8_C( 109), -INT8_C(  70),      INT8_MIN, -INT8_C(  20),  INT8_C(  34), -INT8_C(  46),  INT8_C(   8),  INT8_C(  63),
        -INT8_C(  60),  INT8_C( 105), -INT8_C( 109),      INT8_MAX,  INT8_C(  19),  INT8_C(  93),  INT8_C( 121),  INT8_C(  30) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_v16i8 a = simde_msa_ld_b(test_vec[i].a, 0);
    simde_v16i8 b = simde_msa_ld_b(test_vec[i].b, 0);
    simde_v16i8 r = simde_msa_adds_s_b(a, b);

    simde_test_msa_v16i8_assert_equal(r, simde_msa_ld_b(test_vec[i].r, 0));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_v16i8 a = simde_test_msa_v16i8_random();
    simde_v16i8 b = simde_test_msa_v16i8_random();
    simde_v16i8 r = simde_msa_adds_s_b(a, b);

    simde_test_msa_v16i8_write(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_msa_v16i8_write(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_msa_v16i8_write(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_adds_s_h (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int16_t a[8];
    int16_t b[8];
    int16_t r[8];
  } test_vec[] = {
    { { -INT16_C( 13797),  INT16_C( 23510), -INT16_C( 17254), -INT16_C( 22436),  INT16_C( 19762), -INT16_C( 29207),  INT16_C( 14147),  INT16_C( 18571) },
      {  INT16_C(  9280),  INT16_C(  8832), -INT16_C( 24024), -INT16_C(  8608),  INT16_C(   662),  INT16_C( 20056), -INT16_C( 31638), -INT16_C( 31378) },
      { -INT16_C(  4517),  INT16_C( 32342),        INT16_MIN, -INT16_C( 31044),  INT16_C( 20424), -INT16_C(  9151), -INT16_C( 17491), -INT16_C( 12807) } },
    { {  INT16_C( 17486), -INT16_C(  5919),  INT16_C( 15617),  INT16_C( 13200),  INT16_C( 31115), -INT16_C( 12607),  INT16_C( 19633), -INT16_C(  3818) },
      { -INT16_C( 27023), -INT16_C( 26349),  INT16_C( 29497), -INT16_C( 12425), -INT16_C( 12171), -INT16_C(  8419), -INT16_C( 29868), -INT16_C( 23963) },
      { -INT16_C(  9537), -INT16_C( 32268),        INT16_MAX,  INT16_C(   775),  INT16_C( 18944), -INT16_C( 21026), -INT16_C( 10235), -INT16_C( 27781) } },
    { {  INT16_C( 18128), -INT16_C( 11893),  INT16_C(  7043),  INT16_C(  3588), -INT16_C( 14955),  INT16_C( 18140), -INT16_C(  3310), -INT16_C( 31945) },
      {  INT16_C( 19081), -INT16_C( 15844), -INT16_C( 27715),  INT16_C( 12945), -INT16_C( 20893), -INT16_C( 18671),  INT16_C( 30266),  INT16_C(  2650) },
      {        INT16_MAX, -INT16_C( 27737), -INT16_C( 20672),  INT16_C( 16533),        INT16_MIN, -INT16_C(   531),  INT16_C( 26956), -INT16_C( 29295) } },
    { { -INT16_C(  6724),  INT16_C( 16603), -INT16_C(  8448), -INT16_C( 27314),  INT16_C( 11173), -INT16_C( 18469),  INT16_C(  4638), -INT16_C( 22726) },
      {  INT16_C( 22108),  INT16_C(  6506), -INT16_C(  1047),  INT16_C( 19787),  INT16_C( 23978), -INT16_C(  7164),  INT16_C( 24275), -INT16_C( 28434) },
      {  INT16_C( 15384),  INT16_C( 23109), -INT16_C(  9495), -INT16_C(  7527),        INT16_MAX, -INT16_C( 25633),  INT16_C( 28913),        INT16_MIN } },
    { { -INT16_C( 14013),  INT16_C( 17616),  INT16_C(  7848),  INT16_C( 19929), -INT16_C( 19127),  INT16_C( 26372),  INT16_C( 16071),  INT16_C(  9231) },
      {  INT16_C( 31124),  INT16_C( 32317), -INT16_C( 30348),  INT16_C(  7883), -INT16_C( 12314), -INT16_C( 18174), -INT16_C(  4050),  INT16_C( 29001) },
      {  INT16_C( 17111),        INT16_MAX, -INT16_C( 22500),  INT16_C( 27812), -INT16_C( 31441),  INT16_C(  8198),  INT16_C( 12021),        INT16_MAX } },
    { {  INT16_C(  6585),  INT16_C( 25269), -INT16_C( 28872), -INT16_C( 32337), -INT16_C( 19388),  INT16_C(  3049), -INT16_C(  1806), -INT16_C( 30929) },
      {  INT16_C( 28017), -INT16_C(  6907), -INT16_C( 12042), -INT16_C(  9212),  INT16_C(  1695), -INT16_C( 12907), -INT16_C(  8201), -INT16_C( 20417) },
      {        INT16_MAX,  INT16_C( 18362),        INT16_MIN,        INT16_MIN, -INT16_C( 17693), -INT16_C(  9858), -INT16_C( 10007),        INT16_MIN } },
    { { -INT16_C(  2824),  INT16_C( 12306), -INT16_C( 15741), -INT16_C( 14414), -INT16_C( 25738),  INT16_C( 26835),  INT16_C(   659),  INT16_C(  1263) },
      { -INT16_C(  2961),  INT16_C( 26089), -INT16_C(  4668),  INT16_C( 25665), -INT16_C( 10252), -INT16_C(  5327),  INT16_C( 28854), -INT16_C( 20837) },
      { -INT16_C(  5785),        INT16_MAX, -INT16_C( 20409),  INT16_C( 11251),        INT16_MIN,  INT16_C( 21508),  INT16_C( 29513), -INT16_C( 19574) } },
    { { -INT16_C( 20891), -INT16_C(  5921), -INT16_C( 28304), -INT16_C(  6480), -INT16_C( 31956), -INT16_C( 16562),  INT16_C( 16005), -INT16_C(  2621) },
      { -INT16_C( 21454), -INT16_C(  2214), -INT16_C( 25446), -INT16_C( 29093), -INT16_C( 29581),  INT16_C( 10617),  INT16_C(  5373),  INT16_C( 25303) },
      {        INT16_MIN, -INT16_C(  8135),        INT16_MIN,        INT16_MIN,        INT16_MIN, -INT16_C(  5945),  INT16_C( 21378),  INT16_C( 22682) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_v8i16 a = simde_msa_ld_h(test_vec[i].a, 0);
    simde_v8i16 b = simde_msa_ld_h(test_vec[i].b, 0);
    simde_v8i16 r = simde_msa_adds_s_h(a, b);

    simde_test_msa_v8i16_assert_equal(r, simde_msa_ld_h(test_vec[i].r, 0));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_v8i16 a = simde_test_msa_v8i16_random();
    simde_v8i16 b = simde_test_msa_v8i16_random();
    simde_v8i16 r = simde_msa_adds_s_h(a, b);

    simde_test_msa_v8i16_write(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_msa_v8i16_write(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_msa_v8i16_write(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_adds_s_w (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int32_t a[4];
    int32_t b[4];
    int32_t r[4];
  } test_vec[] = {
    { {  INT32_C(   843757250),  INT32_C(  1931016775),  INT32_C(    53634941), -INT32_C(   671550043) },
      {  INT32_C(  1020154530),  INT32_C(  1640638958), -INT32_C(  1282784330),  INT32_C(   437609047) },
      {  INT32_C(  1863911780),              INT32_MAX, -INT32_C(  1229149389), -INT32_C(   233940996) } },
    { {  INT32_C(  1615617816), -INT32_C(   674011814),  INT32_C(  1910113996), -INT32_C(  1656171781) },
      {  INT32_C(   332994341), -INT32_C(   160062656),  INT32_C(  1051328486),  INT32_C(  2052636257) },
      {  INT32_C(  1948612157), -INT32_C(   834074470),              INT32_MAX,  INT32_C(   396464476) } },
    { {  INT32_C(  2027594782), -INT32_C(   716198647), -INT32_C(  1354356045),  INT32_C(   558665724) },
      { -INT32_C(   432724314), -INT32_C(  1327650103),  INT32_C(   200181417),  INT32_C(  1669678661) },
      {  INT32_C(  1594870468), -INT32_C(  2043848750), -INT32_C(  1154174628),              INT32_MAX } },
    { { -INT32_C(   186949654), -INT32_C(  1060558324),  INT32_C(  1366233172),  INT32_C(  1165147039) },
      { -INT32_C(  1423202335), -INT32_C(    77920175), -INT32_C(   737785457),  INT32_C(  2033683343) },
      { -INT32_C(  1610151989), -INT32_C(  1138478499),  INT32_C(   628447715),              INT32_MAX } },
    { { -INT32_C(   160623894), -INT32_C(  1850329284), -INT32_C(   421386937), -INT32_C(  1037347615) },
      {  INT32_C(  1299011324), -INT32_C(   297220001), -INT32_C(  1597878767), -INT32_C(  1021642279) },
      {  INT32_C(  1138387430),              INT32_MIN, -INT32_C(  2019265704), -INT32_C(  2058989894) } },
    { {  INT32_C(  1203406603),  INT32_C(    98070718),  INT32_C(  2011937430),  INT32_C(   188290575) },
      { -INT32_C(   866605203), -INT32_C(  2118475409), -INT32_C(   920552209), -INT32_C(  2138293387) },
      {  INT32_C(   336801400), -INT32_C(  2020404691),  INT32_C(  1091385221), -INT32_C(  1950002812) } },
    { { -INT32_C(  2117646653),  INT32_C(  1300734135),  INT32_C(  1774482010), -INT32_C(   160105079) },
      {  INT32_C(   348310948),  INT32_C(  1570077806),  INT32_C(  1831253752), -INT32_C(  1242713102) },
      { -INT32_C(  1769335705),              INT32_MAX,              INT32_MAX, -INT32_C(  1402818181) } },
    { { -INT32_C(  1338592007), -INT32_C(  1342325420), -INT32_C(  1189560016),  INT32_C(  1672449471) },
      { -INT32_C(   931696294), -INT32_C(   450556691), -INT32_C(  1252897597), -INT32_C(   127254529) },
      {              INT32_MIN, -INT32_C(  1792882111),              INT32_MIN,  INT32_C(  1545194942) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_v4i32 a = simde_msa_ld_w(test_vec[i].a, 0);
    simde_v4i32 b = simde_msa_ld_w(test_vec[i].b, 0);
    simde_v4i32 r = simde_msa_adds_s_w(a, b);

    simde_test_msa_v4i32_assert_equal(r, simde_msa_ld_w(test_vec[i].r, 0));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_v4i32 a = simde_test_msa_v4i32_random();
    simde_v4i32 b = simde_test_msa_v4i32_random();
    simde_v4i32 r = simde_msa_adds_s_w(a, b);

    simde_test_msa_v4i32_write(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_msa_v4i32_write(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_msa_v4i32_write(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_adds_s_d (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int64_t a[2];
    int64_t b[2];
    int64_t r[2];
  } test_vec[] = {
    { { -INT64_C( 8144858477200039693), -INT64_C(  681461243058909336) },
      { -INT64_C( 3370412095907691929), -INT64_C( 4816616525278049488) },
      {                      INT64_MIN, -INT64_C( 5498077768336958824) } },
    { { -INT64_C( 2342438639121346415),  INT64_C( 2422814255905948684) },
      {  INT64_C( 8174787870535802258),  INT64_C( 8845290571269470521) },
      {  INT64_C( 5832349231414455843),                      INT64_MAX } },
    { { -INT64_C( 3535634936282626408),  INT64_C( 1694785596946904234) },
      { -INT64_C( 2223041362457462157),  INT64_C( 2848708798143842084) },
      { -INT64_C( 5758676298740088565),  INT64_C( 4543494395090746318) } },
    { { -INT64_C( 9008283544246029973), -INT64_C(  236882592041307366) },
      { -INT64_C( 4687727580916125849), -INT64_C( 1921537881767422561) },
      {                      INT64_MIN, -INT64_C( 2158420473808729927) } },
    { { -INT64_C( 3702223111008842683),  INT64_C( 6487191116002854530) },
      {  INT64_C( 3524166287945742736),  INT64_C( 5517106389033333808) },
      { -INT64_C(  178056823063099947),                      INT64_MAX } },
    { {  INT64_C( 3800485799723115328), -INT64_C( 2604129198700287601) },
      { -INT64_C( 3404458944913651969),  INT64_C( 1366292536367980194) },
      {  INT64_C(  396026854809463359), -INT64_C( 1237836662332307407) } },
    { { -INT64_C(  534588702206959698),  INT64_C( 1806039216358609899) },
      { -INT64_C( 6481126247292660067),  INT64_C( 4786277007460632968) },
      { -INT64_C( 7015714949499619765),  INT64_C( 6592316223819242867) } },
    { {  INT64_C( 2091137190588477605),  INT64_C( 8375397707670585353) },
      { -INT64_C( 2944299383238040199),  INT64_C( 6709975011634082632) },
      { -INT64_C(  853162192649562594),                      INT64_MAX } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_v2i64 a = simde_msa_ld_d(test_vec[i].a, 0);
    simde_v2i64 b = simde_msa_ld_d(test_vec[i].b, 0);
    simde_v2i64 r = simde_msa_adds_s_d(a, b);

    simde_test_msa_v2i64_assert_equal(r, simde_msa_ld_d(test_vec[i].r, 0));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_v2i64 a = simde_test_msa_v2i64_random();
    simde_v2i64 b = simde_test_msa_v2i64_random();
    simde_v2i64 r = simde_msa_adds_s_d(a, b);

    simde_test_msa_v2i64_write(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_msa_v2i64_write(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_msa_v2i64_write(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_adds_u_b (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint8_t a[16];
    uint8_t b[16];
    uint8_t r[16];
  } test_vec[] = {
    { { UINT8_C(103), UINT8_C(213), UINT8_C( 35), UINT8_C(195), UINT8_C(162), UINT8_C(240), UINT8_C(148), UINT8_C(186),
        UINT8_C( 33), UINT8_C( 62), UINT8_C(108), UINT8_C(147), UINT8_C(233), UINT8_C(188), UINT8_C(250), UINT8_C(178) },
      { UINT8_C( 54), UINT8_C( 78), UINT8_C( 87), UINT8_C( 62), UINT8_C(205), UINT8_C(213), UINT8_C( 88), UINT8_C( 70),
        UINT8_C(  7), UINT8_C( 86), UINT8_C( 90), UINT8_C(114), UINT8_C(214), UINT8_C( 61), UINT8_C(210), UINT8_C( 61) },
      { UINT8_C(157),    UINT8_MAX, UINT8_C(122),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(236),    UINT8_MAX,
        UINT8_C( 40), UINT8_C(148), UINT8_C(198),    UINT8_MAX,    UINT8_MAX, UINT8_C(249),    UINT8_MAX, UINT8_C(239) } },
    { { UINT8_C( 18), UINT8_C(245), UINT8_C(  0), UINT8_C(180), UINT8_C(229), UINT8_C(148), UINT8_C(110), UINT8_C(  6),
        UINT8_C(210), UINT8_C(218), UINT8_C(153), UINT8_C(187), UINT8_C(150), UINT8_C(147), UINT8_C(110), UINT8_C(204) },
      { UINT8_C(225), UINT8_C(197), UINT8_C( 11), UINT8_C(175), UINT8_C(154), UINT8_C( 99), UINT8_C(245), UINT8_C(162),
        UINT8_C(186), UINT8_C( 80), UINT8_C( 20), UINT8_C(144), UINT8_C(141), UINT8_C(230), UINT8_C(206), UINT8_C(159) },
      { UINT8_C(243),    UINT8_MAX, UINT8_C( 11),    UINT8_MAX,    UINT8_MAX, UINT8_C(247),    UINT8_MAX, UINT8_C(168),
           UINT8_MAX,    UINT8_MAX, UINT8_C(173),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX } },
    { { UINT8_C(219), UINT8_C(206), UINT8_C( 84), UINT8_C(192), UINT8_C( 99), UINT8_C(194), UINT8_C(199), UINT8_C( 53),
        UINT8_C(157), UINT8_C( 96), UINT8_C(241), UINT8_C( 51), UINT8_C(244), UINT8_C( 95), UINT8_C(  0), UINT8_C(213) },
      { UINT8_C( 36), UINT8_C( 11), UINT8_C(132), UINT8_C(190), UINT8_C(110), UINT8_C(122), UINT8_C( 96), UINT8_C( 40),
        UINT8_C(202), UINT8_C(116), UINT8_C(185), UINT8_C( 87), UINT8_C( 90), UINT8_C(135), UINT8_C(246), UINT8_C( 53) },
      {    UINT8_MAX, UINT8_C(217), UINT8_C(216),    UINT8_MAX, UINT8_C(209),    UINT8_MAX,    UINT8_MAX, UINT8_C( 93),
           UINT8_MAX, UINT8_C(212),    UINT8_MAX, UINT8_C(138),    UINT8_MAX, UINT8_C(230), UINT8_C(246),    UINT8_MAX } },
    { { UINT8_C( 85), UINT8_C( 74), UINT8_C(246), UINT8_C(184), UINT8_C( 13), UINT8_C(189), UINT8_C(238), UINT8_C(170),
        UINT8_C( 29), UINT8_C(223), UINT8_C(221), UINT8_C( 17), UINT8_C( 62), UINT8_C(221), UINT8_C(231), UINT8_C( 98) },
      { UINT8_C(232), UINT8_C(107), UINT8_C( 32), UINT8_C( 87), UINT8_C(229), UINT8_C(129), UINT8_C(127), UINT8_C(175),
        UINT8_C(245), UINT8_C( 56), UINT8_C(  6), UINT8_C( 80), UINT8_C(191), UINT8_C(253), UINT8_C(133), UINT8_C( 21) },
      {    UINT8_MAX, UINT8_C(181),    UINT8_MAX,    UINT8_MAX, UINT8_C(242),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,
           UINT8_MAX,    UINT8_MAX, UINT8_C(227), UINT8_C( 97), UINT8_C(253),    UINT8_MAX,    UINT8_MAX, UINT8_C(119) } },
    { { UINT8_C( 71), UINT8_C(123), UINT8_C(205), UINT8_C( 84), UINT8_C( 56), UINT8_C(187), UINT8_C(254), UINT8_C( 86),
        UINT8_C(154), UINT8_C(220), UINT8_C(103), UINT8_C(216), UINT8_C(185), UINT8_C( 78), UINT8_C( 58), UINT8_C(162) },
      { UINT8_C(186), UINT8_C( 91), UINT8_C(249), UINT8_C(159), UINT8_C(220), UINT8_C(120), UINT8_C( 79), UINT8_C(209),
        UINT8_C(177), UINT8_C( 85), UINT8_C( 33), UINT8_C(112), UINT8_C( 82), UINT8_C(167), UINT8_C(133), UINT8_C(154) },
      {    UINT8_MAX, UINT8_C(214),    UINT8_MAX, UINT8_C(243),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,
           UINT8_MAX,    UINT8_MAX, UINT8_C(136),    UINT8_MAX,    UINT8_MAX, UINT8_C(245), UINT8_C(191),    UINT8_MAX } },
    { { UINT8_C( 34), UINT8_C( 83), UINT8_C(238), UINT8_C( 91), UINT8_C( 14), UINT8_C(237), UINT8_C(177), UINT8_C(169),
        UINT8_C(201), UINT8_C( 24), UINT8_C(129), UINT8_C(130), UINT8_C(103), UINT8_C(188), UINT8_C( 36), UINT8_C( 33) },
      { UINT8_C( 23), UINT8_C( 29), UINT8_C(192), UINT8_C(243), UINT8_C(150), UINT8_C( 15), UINT8_C(196), UINT8_C( 71),
        UINT8_C(101), UINT8_C(230), UINT8_C(183), UINT8_C(183), UINT8_C(141), UINT8_C( 61), UINT8_C( 81), UINT8_C(175) },
      { UINT8_C( 57), UINT8_C(112),    UINT8_MAX,    UINT8_MAX, UINT8_C(164), UINT8_C(252),    UINT8_MAX, UINT8_C(240),
           UINT8_MAX, UINT8_C(254),    UINT8_MAX,    UINT8_MAX, UINT8_C(244), UINT8_C(249), UINT8_C(117), UINT8_C(208) } },
    { { UINT8_C(144), UINT8_C( 64), UINT8_C( 10), UINT8_C(158), UINT8_C( 45), UINT8_C(187), UINT8_C( 71), UINT8_C(246),
        UINT8_C(212), UINT8_C(201), UINT8_C(120), UINT8_C( 59), UINT8_C(133), UINT8_C(157), UINT8_C( 92), UINT8_C(156) },
      { UINT8_C(186), UINT8_C( 28), UINT8_C(143), UINT8_C( 80), UINT8_C( 44), UINT8_C( 83), UINT8_C(151), UINT8_C(145),
        UINT8_C( 57), UINT8_C( 79), UINT8_C( 72), UINT8_C(198), UINT8_C(140), UINT8_C(154), UINT8_C(118), UINT8_C( 28) },
      {    UINT8_MAX, UINT8_C( 92), UINT8_C(153), UINT8_C(238), UINT8_C( 89),    UINT8_MAX, UINT8_C(222),    UINT8_MAX,
           UINT8_MAX,    UINT8_MAX, UINT8_C(192),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(210), UINT8_C(184) } },
    { { UINT8_C(218), UINT8_C(128), UINT8_C(186), UINT8_C(  7), UINT8_C( 60), UINT8_C(  2), UINT8_C(253), UINT8_C( 16),
        UINT8_C(203), UINT8_C(117), UINT8_C( 75), UINT8_C( 80), UINT8_C( 18), UINT8_C(167), UINT8_C(236), UINT8_C(205) },
      { UINT8_C(195), UINT8_C(123), UINT8_C( 29), UINT8_C(239), UINT8_C(206), UINT8_C(181), UINT8_C(128), UINT8_C(  8),
        UINT8_C(  4), UINT8_C(201), UINT8_C(206), UINT8_C(144), UINT8_C( 99), UINT8_C( 68), UINT8_C(172), UINT8_C( 61) },
      {    UINT8_MAX, UINT8_C(251), UINT8_C(215), UINT8_C(246),    UINT8_MAX, UINT8_C(183),    UINT8_MAX, UINT8_C( 24),
        UINT8_C(207),    UINT8_MAX,    UINT8_MAX, UINT8_C(224), UINT8_C(117), UINT8_C(235),    UINT8_MAX,    UINT8_MAX } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_v16u8 a = simde_x_msa_ld_u_b(test_vec[i].a, 0);
    simde_v16u8 b = simde_x_msa_ld_u_b(test_vec[i].b, 0);
    simde_v16u8 r = simde_msa_adds_u_b(a, b);

    simde_test_msa_v16u8_assert_equal(r, simde_x_msa_ld_u_b(test_vec[i].r, 0));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_v16u8 a = simde_test_msa_v16u8_random();
    simde_v16u8 b = simde_test_msa_v16u8_random();
    simde_v16u8 r = simde_msa_adds_u_b(a, b);

    simde_test_msa_v16u8_write(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_msa_v16u8_write(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_msa_v16u8_write(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_adds_u_h (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint16_t a[8];
    uint16_t b[8];
    uint16_t r[8];
  } test_vec[] = {
    { { UINT16_C(26309), UINT16_C(  324), UINT16_C(16744), UINT16_C(13073), UINT16_C(23734), UINT16_C(51587), UINT16_C(28419), UINT16_C(50838) },
      { UINT16_C(46058), UINT16_C(47542), UINT16_C(13928), UINT16_C(27841), UINT16_C(36863), UINT16_C(25340), UINT16_C(43220), UINT16_C(39327) },
      {      UINT16_MAX, UINT16_C(47866), UINT16_C(30672), UINT16_C(40914), UINT16_C(60597),      UINT16_MAX,      UINT16_MAX,      UINT16_MAX } },
    { { UINT16_C(58127), UINT16_C(30618), UINT16_C(43812), UINT16_C(56235), UINT16_C(11783), UINT16_C( 2724), UINT16_C(15006), UINT16_C(35024) },
      { UINT16_C(34541), UINT16_C(22081), UINT16_C(  701), UINT16_C(48322), UINT16_C(49042), UINT16_C(26143), UINT16_C(48743), UINT16_C(30463) },
      {      UINT16_MAX, UINT16_C(52699), UINT16_C(44513),      UINT16_MAX, UINT16_C(60825), UINT16_C(28867), UINT16_C(63749), UINT16_C(65487) } },
    { { UINT16_C(39330), UINT16_C(50926), UINT16_C(39236), UINT16_C(19361), UINT16_C(17863), UINT16_C(25941), UINT16_C( 9599), UINT16_C(28142) },
      { UINT16_C(12204), UINT16_C(27075), UINT16_C(34098), UINT16_C(50213), UINT16_C(17476), UINT16_C(44074), UINT16_C(10499), UINT16_C(42274) },
      { UINT16_C(51534),      UINT16_MAX,      UINT16_MAX,      UINT16_MAX, UINT16_C(35339),      UINT16_MAX, UINT16_C(20098),      UINT16_MAX } },
    { { UINT16_C( 4290), UINT16_C( 1643), UINT16_C( 3497), UINT16_C(29009), UINT16_C(42578), UINT16_C(53974), UINT16_C(50379), UINT16_C(30527) },
      { UINT16_C(  756), UINT16_C( 9952), UINT16_C( 1671), UINT16_C(52458), UINT16_C( 5194), UINT16_C(19832), UINT16_C(39485), UINT16_C(65522) },
      { UINT16_C( 5046), UINT16_C(11595), UINT16_C( 5168),      UINT16_MAX, UINT16_C(47772),      UINT16_MAX,      UINT16_MAX,      UINT16_MAX } },
    { { UINT16_C(24235), UINT16_C(21509), UINT16_C(22123), UINT16_C(48581), UINT16_C(40188), UINT16_C(51087), UINT16_C(52832), UINT16_C(21567) },
      { UINT16_C( 8144), UINT16_C(22650), UINT16_C(25637), UINT16_C(28708), UINT16_C(40056), UINT16_C(46525), UINT16_C(45110), UINT16_C(57780) },
      { UINT16_C(32379), UINT16_C(44159), UINT16_C(47760),      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX } },
    { { UINT16_C(47374), UINT16_C(31030), UINT16_C(64271), UINT16_C( 2870), UINT16_C(50839), UINT16_C(63699), UINT16_C( 4756), UINT16_C(25932) },
      { UINT16_C(50993), UINT16_C(22461), UINT16_C(57643), UINT16_C(42183), UINT16_C(33917), UINT16_C(45913), UINT16_C( 3636), UINT16_C(17045) },
      {      UINT16_MAX, UINT16_C(53491),      UINT16_MAX, UINT16_C(45053),      UINT16_MAX,      UINT16_MAX, UINT16_C( 8392), UINT16_C(42977) } },
    { { UINT16_C(52167), UINT16_C(55227), UINT16_C(62150), UINT16_C(24290), UINT16_C(46520), UINT16_C(19542), UINT16_C(41671), UINT16_C(63921) },
      { UINT16_C(28265), UINT16_C(38224), UINT16_C( 5967), UINT16_C(52281), UINT16_C(37531), UINT16_C(53376), UINT16_C( 5536), UINT16_C(26642) },
      {      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX, UINT16_C(47207),      UINT16_MAX } },
    { { UINT16_C(52960), UINT16_C(42559), UINT16_C( 8640), UINT16_C(30724), UINT16_C(23255), UINT16_C(40644), UINT16_C(30461), UINT16_C(26263) },
      { UINT16_C(59364), UINT16_C(13563), UINT16_C(13566), UINT16_C(39424), UINT16_C(32967), UINT16_C(26474), UINT16_C(31893), UINT16_C(30159) },
      {      UINT16_MAX, UINT16_C(56122), UINT16_C(22206),      UINT16_MAX, UINT16_C(56222),      UINT16_MAX, UINT16_C(62354), UINT16_C(56422) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_v8u16 a = simde_x_msa_ld_u_h(test_vec[i].a, 0);
    simde_v8u16 b = simde_x_msa_ld_u_h(test_vec[i].b, 0);
    simde_v8u16 r = simde_msa_adds_u_h(a, b);

    simde_test_msa_v8u16_assert_equal(r, simde_x_msa_ld_u_h(test_vec[i].r, 0));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_v8u16 a = simde_test_msa_v8u16_random();
    simde_v8u16 b = simde_test_msa_v8u16_random();
    simde_v8u16 r = simde_msa_adds_u_h(a, b);

    simde_test_msa_v8u16_write(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_msa_v8u16_write(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_msa_v8u16_write(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_adds_u_w (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint32_t a[4];
    uint32_t b[4];
    uint32_t r[4];
  } test_vec[] = {
    { { UINT32_C( 169610826), UINT32_C( 125968432), UINT32_C(2024097659), UINT32_C(2715696573) },
      { UINT32_C( 601217572), UINT32_C(3585988110), UINT32_C(3963430742), UINT32_C(3999337635) },
      { UINT32_C( 770828398), UINT32_C(3711956542),           UINT32_MAX,           UINT32_MAX } },
    { { UINT32_C(1274576155), UINT32_C( 424835998), UINT32_C(2140272578), UINT32_C(1495297844) },
      { UINT32_C(1484584521), UINT32_C( 573389260), UINT32_C(  51276384), UINT32_C(2465296503) },
      { UINT32_C(2759160676), UINT32_C( 998225258), UINT32_C(2191548962), UINT32_C(3960594347) } },
    { { UINT32_C(2346576621), UINT32_C( 665071461), UINT32_C(1537619238), UINT32_C(4004824741) },
      { UINT32_C(2286301372), UINT32_C(3383456873), UINT32_C(1439480286), UINT32_C( 401063465) },
      {           UINT32_MAX, UINT32_C(4048528334), UINT32_C(2977099524),           UINT32_MAX } },
    { { UINT32_C( 228770984), UINT32_C( 439633907), UINT32_C( 561371772), UINT32_C(1561340320) },
      { UINT32_C(3269809753), UINT32_C(2844496074), UINT32_C(1946048330), UINT32_C(3179996693) },
      { UINT32_C(3498580737), UINT32_C(3284129981), UINT32_C(2507420102),           UINT32_MAX } },
    { { UINT32_C(2664050090), UINT32_C(4038655604), UINT32_C(2031234520), UINT32_C(2950046294) },
      { UINT32_C(1131527032), UINT32_C(2532113484), UINT32_C(1762257491), UINT32_C(2066126032) },
      { UINT32_C(3795577122),           UINT32_MAX, UINT32_C(3793492011),           UINT32_MAX } },
    { { UINT32_C( 890892737), UINT32_C(3357921775), UINT32_C(1413560318), UINT32_C(3523417945) },
      { UINT32_C( 504722642), UINT32_C(3283353968), UINT32_C(3157049067), UINT32_C( 322392914) },
      { UINT32_C(1395615379),           UINT32_MAX,           UINT32_MAX, UINT32_C(3845810859) } },
    { { UINT32_C( 860377156), UINT32_C( 536571169), UINT32_C(4268965029), UINT32_C( 651195987) },
      { UINT32_C(1514464746), UINT32_C(3525179878), UINT32_C( 160320183), UINT32_C(3776759197) },
      { UINT32_C(2374841902), UINT32_C(4061751047),           UINT32_MAX,           UINT32_MAX } },
    { { UINT32_C( 907306005), UINT32_C(1985286353), UINT32_C(2692073548), UINT32_C( 684082494) },
      { UINT32_C( 293734955), UINT32_C(3135479555), UINT32_C(2260955625), UINT32_C(1265098550) },
      { UINT32_C(1201040960),           UINT32_MAX,           UINT32_MAX, UINT32_C(1949181044) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_v4u32 a = simde_x_msa_ld_u_w(test_vec[i].a, 0);
    simde_v4u32 b = simde_x_msa_ld_u_w(test_vec[i].b, 0);
    simde_v4u32 r = simde_msa_adds_u_w(a, b);

    simde_test_msa_v4u32_assert_equal(r, simde_x_msa_ld_u_w(test_vec[i].r, 0));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_v4u32 a = simde_test_msa_v4u32_random();
    simde_v4u32 b = simde_test_msa_v4u32_random();
    simde_v4u32 r = simde_msa_adds_u_w(a, b);

    simde_test_msa_v4u32_write(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_msa_v4u32_write(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_msa_v4u32_write(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_adds_u_d (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint64_t a[2];
    uint64_t b[2];
    uint64_t r[2];
  } test_vec[] = {
    { { UINT64_C(15603801231099788355), UINT64_C( 8143702500260184222) },
      { UINT64_C( 1082946550084306505), UINT64_C(17102979966747200215) },
      { UINT64_C(16686747781184094860),                     UINT64_MAX } },
    { { UINT64_C( 5827251858808429433), UINT64_C(16016262169392600718) },
      { UINT64_C(  427051617018890423), UINT64_C(18055895730367988732) },
      { UINT64_C( 6254303475827319856),                     UINT64_MAX } },
    { { UINT64_C(12847042562933888584), UINT64_C( 6820645181688608308) },
      { UINT64_C(18431026571134161300), UINT64_C(10387051473214495660) },
      {                     UINT64_MAX, UINT64_C(17207696654903103968) } },
    { { UINT64_C( 4009843057150797518), UINT64_C(10182541970128251977) },
      { UINT64_C( 6952176513723632505), UINT64_C( 2867864254265696499) },
      { UINT64_C(10962019570874430023), UINT64_C(13050406224393948476) } },
    { { UINT64_C( 8292461900891510489), UINT64_C( 3850774205740291306) },
      { UINT64_C(14578482774759554877), UINT64_C( 7695474811744935500) },
      {                     UINT64_MAX, UINT64_C(11546249017485226806) } },
    { { UINT64_C(10287447106310825255), UINT64_C( 1684594587784521583) },
      { UINT64_C( 9890285476718907808), UINT64_C( 4626315127089350456) },
      {                     UINT64_MAX, UINT64_C( 6310909714873872039) } },
    { { UINT64_C( 4832175296387054302), UINT64_C(  175304352971260028) },
      { UINT64_C(  767225818336819167), UINT64_C(12275132307556520706) },
      { UINT64_C( 5599401114723873469), UINT64_C(12450436660527780734) } },
    { { UINT64_C(13662016092097997697), UINT64_C(13051293001753757627) },
      { UINT64_C( 6184699390055323896), UINT64_C( 3440972964360660810) },
      {                     UINT64_MAX, UINT64_C(16492265966114418437) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_v2u64 a = simde_x_msa_ld_u_d(test_vec[i].a, 0);
    simde_v2u64 b = simde_x_msa_ld_u_d(test_vec[i].b, 0);
    simde_v2u64 r = simde_msa_adds_u_d(a, b);

    simde_test_msa_v2u64_assert_equal(r, simde_x_msa_ld_u_d(test_vec[i].r, 0));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_v2u64 a = simde_test_msa_v2u64_random();
    simde_v2u64 b = simde_test_msa_v2u64_random();
    simde_v2u64 r = simde_msa_adds_u_d(a, b);

    simde_test_msa_v2u64_write(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_msa_v2u64_write(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_msa_v2u64_write(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(adds_s_b)
SIMDE_TEST_FUNC_LIST_ENTRY(adds_s_h)
SIMDE_TEST_FUNC_LIST_ENTRY(adds_s_w)
SIMDE_TEST_FUNC_LIST_ENTRY(adds_s_d)
SIMDE_TEST_FUNC_LIST_ENTRY(adds_u_b)
SIMDE_TEST_FUNC_LIST_ENTRY(adds_u_h)
SIMDE_TEST_FUNC_LIST_ENTRY(adds_u_w)
SIMDE_TEST_FUNC_LIST_ENTRY(adds_u_d)
SIMDE_TEST_FUNC_LIST_END

#include "test-msa-footer.h"
