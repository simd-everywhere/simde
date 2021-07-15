#define SIMDE_TEST_MIPS_MSA_INSN adds_a

#include "test-msa.h"
#include "../../../simde/mips/msa/adds_a.h"

static int
test_simde_adds_a_b (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int8_t a[16];
    int8_t b[16];
    int8_t r[16];
  } test_vec[] = {
    { {  INT8_C(  57), -INT8_C(  54), -INT8_C( 115),  INT8_C(  76), -INT8_C(  73),  INT8_C(  22), -INT8_C(  47),  INT8_C(  83),
        -INT8_C( 105),  INT8_C(  34),  INT8_C(  81),  INT8_C( 109),  INT8_C( 105), -INT8_C( 102),  INT8_C(  63), -INT8_C(  33) },
      { -INT8_C(  82), -INT8_C( 125),  INT8_C(   9), -INT8_C(  89), -INT8_C(  31), -INT8_C(   2),  INT8_C(  83),  INT8_C(  98),
        -INT8_C( 110),  INT8_C(  40), -INT8_C(  15),  INT8_C(  54), -INT8_C( 113), -INT8_C(  10),  INT8_C(  26), -INT8_C(  56) },
      {      INT8_MAX,      INT8_MAX,  INT8_C( 124),      INT8_MAX,  INT8_C( 104),  INT8_C(  24),      INT8_MAX,      INT8_MAX,
             INT8_MAX,  INT8_C(  74),  INT8_C(  96),      INT8_MAX,      INT8_MAX,  INT8_C( 112),  INT8_C(  89),  INT8_C(  89) } },
    { { -INT8_C(  63), -INT8_C(  88),  INT8_C(  21),  INT8_C( 120), -INT8_C(  66), -INT8_C(  26), -INT8_C(  53),  INT8_C(  85),
         INT8_C(   9),  INT8_C(  29), -INT8_C(  62),  INT8_C( 114), -INT8_C(  73),  INT8_C(   2),  INT8_C(  81),  INT8_C( 101) },
      { -INT8_C( 123),  INT8_C(  90),  INT8_C(  12),  INT8_C( 102),  INT8_C(  88),  INT8_C(  96), -INT8_C(  56), -INT8_C(  21),
        -INT8_C( 120), -INT8_C(  70),  INT8_C(  33),  INT8_C(  23), -INT8_C(  80),  INT8_C(  60), -INT8_C(  32),  INT8_C( 113) },
      {      INT8_MAX,      INT8_MAX,  INT8_C(  33),      INT8_MAX,      INT8_MAX,  INT8_C( 122),  INT8_C( 109),  INT8_C( 106),
             INT8_MAX,  INT8_C(  99),  INT8_C(  95),      INT8_MAX,      INT8_MAX,  INT8_C(  62),  INT8_C( 113),      INT8_MAX } },
    { { -INT8_C(  28), -INT8_C(  11), -INT8_C(  23), -INT8_C(  94), -INT8_C(  37), -INT8_C(  75), -INT8_C(   9), -INT8_C(  28),
        -INT8_C(  46), -INT8_C(  70),  INT8_C(  87), -INT8_C( 119), -INT8_C(  68), -INT8_C(  88), -INT8_C(  17),  INT8_C(  65) },
      {  INT8_C(   3), -INT8_C(   5), -INT8_C(  88),  INT8_C(  91),  INT8_C(  91),  INT8_C( 112),  INT8_C(  70), -INT8_C(  28),
         INT8_C(  42),  INT8_C( 104), -INT8_C(   5), -INT8_C(  37), -INT8_C(  92), -INT8_C(  37),  INT8_C(  76), -INT8_C( 120) },
      {  INT8_C(  31),  INT8_C(  16),  INT8_C( 111),      INT8_MAX,      INT8_MAX,      INT8_MAX,  INT8_C(  79),  INT8_C(  56),
         INT8_C(  88),      INT8_MAX,  INT8_C(  92),      INT8_MAX,      INT8_MAX,  INT8_C( 125),  INT8_C(  93),      INT8_MAX } },
    { { -INT8_C(  48),  INT8_C(  54),  INT8_C(  42), -INT8_C(  84), -INT8_C(  21),  INT8_C(  33), -INT8_C( 112), -INT8_C(  67),
        -INT8_C(  37), -INT8_C(  25),  INT8_C(  70), -INT8_C( 105), -INT8_C( 112),  INT8_C(  53), -INT8_C(  39), -INT8_C( 109) },
      {  INT8_C(  49), -INT8_C( 127), -INT8_C(  18), -INT8_C( 116), -INT8_C(  15),  INT8_C(  53),  INT8_C( 112),  INT8_C(  28),
        -INT8_C(  99),  INT8_C( 108), -INT8_C(   9),  INT8_C(  65),  INT8_C(  71),  INT8_C(  67), -INT8_C(  55),  INT8_C(  24) },
      {  INT8_C(  97),      INT8_MAX,  INT8_C(  60),      INT8_MAX,  INT8_C(  36),  INT8_C(  86),      INT8_MAX,  INT8_C(  95),
             INT8_MAX,      INT8_MAX,  INT8_C(  79),      INT8_MAX,      INT8_MAX,  INT8_C( 120),  INT8_C(  94),      INT8_MAX } },
    { {  INT8_C( 121), -INT8_C(  13), -INT8_C(  60),  INT8_C( 100),  INT8_C(  20),  INT8_C(  84),  INT8_C(  33), -INT8_C(  16),
         INT8_C(  60),  INT8_C( 104), -INT8_C( 121), -INT8_C(  52), -INT8_C(  99),  INT8_C(  96),  INT8_C(  95), -INT8_C(  50) },
      { -INT8_C(  31),  INT8_C(  77),  INT8_C(  91), -INT8_C(  45), -INT8_C( 126), -INT8_C(  53), -INT8_C(  17),  INT8_C(  31),
         INT8_C(  55), -INT8_C(  26),  INT8_C(  96),      INT8_MAX,  INT8_C(  41),  INT8_C(  41), -INT8_C( 105), -INT8_C(  93) },
      {      INT8_MAX,  INT8_C(  90),      INT8_MAX,      INT8_MAX,      INT8_MAX,      INT8_MAX,  INT8_C(  50),  INT8_C(  47),
         INT8_C( 115),      INT8_MAX,      INT8_MAX,      INT8_MAX,      INT8_MAX,      INT8_MAX,      INT8_MAX,      INT8_MAX } },
    { {  INT8_C(  28),  INT8_C(  91),  INT8_C(   7),  INT8_C(  49), -INT8_C(  81),  INT8_C(  41),  INT8_C(  33), -INT8_C(  21),
        -INT8_C( 111), -INT8_C(  88), -INT8_C(  73),  INT8_C(  46),  INT8_C(   9),  INT8_C(  22), -INT8_C(   3), -INT8_C(  22) },
      {  INT8_C( 100),  INT8_C(  88), -INT8_C(  67), -INT8_C(  26),  INT8_C(  35), -INT8_C(  84),  INT8_C(   6),  INT8_C(  91),
        -INT8_C( 110),  INT8_C( 102), -INT8_C(  38), -INT8_C(  68), -INT8_C( 112),  INT8_C( 113),  INT8_C(  95), -INT8_C(  84) },
      {      INT8_MAX,      INT8_MAX,  INT8_C(  74),  INT8_C(  75),  INT8_C( 116),  INT8_C( 125),  INT8_C(  39),  INT8_C( 112),
             INT8_MAX,      INT8_MAX,  INT8_C( 111),  INT8_C( 114),  INT8_C( 121),      INT8_MAX,  INT8_C(  98),  INT8_C( 106) } },
    { { -INT8_C(  52),  INT8_C( 102), -INT8_C(  35),  INT8_C( 123), -INT8_C( 113), -INT8_C(   2),  INT8_C( 103),  INT8_C(  32),
        -INT8_C(  89),  INT8_C(  30),  INT8_C(  79), -INT8_C(  80),  INT8_C(  53),  INT8_C(  76), -INT8_C( 102), -INT8_C( 103) },
      { -INT8_C(  92),  INT8_C(  88),      INT8_MAX, -INT8_C(  57),  INT8_C(   4), -INT8_C( 123),  INT8_C(  34), -INT8_C( 105),
        -INT8_C(  20), -INT8_C(   4),  INT8_C(  83),  INT8_C( 124),  INT8_C( 109), -INT8_C(  78),  INT8_C(  40),  INT8_C(  57) },
      {      INT8_MAX,      INT8_MAX,      INT8_MAX,      INT8_MAX,  INT8_C( 117),  INT8_C( 125),      INT8_MAX,      INT8_MAX,
         INT8_C( 109),  INT8_C(  34),      INT8_MAX,      INT8_MAX,      INT8_MAX,      INT8_MAX,      INT8_MAX,      INT8_MAX } },
    { {  INT8_C(  24),  INT8_C(   6), -INT8_C(  75), -INT8_C(  88),  INT8_C(   4),  INT8_C(  28), -INT8_C(  56), -INT8_C(  85),
         INT8_C(  58),  INT8_C(  23),  INT8_C(  91),  INT8_C( 111),  INT8_C(  99), -INT8_C(  10),  INT8_C(   8),  INT8_C(   7) },
      {  INT8_C(  78), -INT8_C( 120), -INT8_C(  49),  INT8_C(  82),  INT8_C(  13), -INT8_C(  15), -INT8_C(  23), -INT8_C(   7),
        -INT8_C(  18),  INT8_C(  60),  INT8_C( 117),  INT8_C(  91), -INT8_C(  18), -INT8_C(  98), -INT8_C( 107),  INT8_C(   7) },
      {  INT8_C( 102),  INT8_C( 126),  INT8_C( 124),      INT8_MAX,  INT8_C(  17),  INT8_C(  43),  INT8_C(  79),  INT8_C(  92),
         INT8_C(  76),  INT8_C(  83),      INT8_MAX,      INT8_MAX,  INT8_C( 117),  INT8_C( 108),  INT8_C( 115),  INT8_C(  14) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_v16i8 a = simde_msa_ld_b(test_vec[i].a, 0);
    simde_v16i8 b = simde_msa_ld_b(test_vec[i].b, 0);
    simde_v16i8 r = simde_msa_adds_a_b(a, b);

    simde_test_msa_v16i8_assert_equal(r, simde_msa_ld_b(test_vec[i].r, 0));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_v16i8 a = simde_test_msa_v16i8_random();
    simde_v16i8 b = simde_test_msa_v16i8_random();
    simde_v16i8 r = simde_msa_adds_a_b(a, b);

    simde_test_msa_v16i8_write(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_msa_v16i8_write(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_msa_v16i8_write(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_adds_a_h (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int16_t a[8];
    int16_t b[8];
    int16_t r[8];
  } test_vec[] = {
    { {  INT16_C( 19108), -INT16_C( 22353),  INT16_C( 30566), -INT16_C( 24492), -INT16_C( 20593), -INT16_C(  3568),  INT16_C(  6309), -INT16_C(  3078) },
      { -INT16_C( 13920), -INT16_C( 20922),  INT16_C( 12218), -INT16_C( 22361),  INT16_C(  7532),  INT16_C( 23044), -INT16_C( 26181),  INT16_C( 24417) },
      {        INT16_MAX,        INT16_MAX,        INT16_MAX,        INT16_MAX,  INT16_C( 28125),  INT16_C( 26612),  INT16_C( 32490),  INT16_C( 27495) } },
    { {  INT16_C(  4323),  INT16_C( 18695),  INT16_C( 23432),  INT16_C(  6121), -INT16_C(  1781), -INT16_C( 20471),  INT16_C(   786), -INT16_C( 19804) },
      { -INT16_C(  5428), -INT16_C( 30880),  INT16_C(  2073), -INT16_C( 31441),  INT16_C( 13093), -INT16_C(  7968),  INT16_C( 16844), -INT16_C( 20673) },
      {  INT16_C(  9751),        INT16_MAX,  INT16_C( 25505),        INT16_MAX,  INT16_C( 14874),  INT16_C( 28439),  INT16_C( 17630),        INT16_MAX } },
    { {  INT16_C( 18002), -INT16_C(  9480), -INT16_C(  7518), -INT16_C( 21007), -INT16_C(  1317), -INT16_C(  4771),  INT16_C(   510), -INT16_C( 13664) },
      {  INT16_C(   235),  INT16_C(  1361), -INT16_C( 32504),  INT16_C( 11658),  INT16_C( 27316), -INT16_C( 32499),  INT16_C( 19628), -INT16_C(   464) },
      {  INT16_C( 18237),  INT16_C( 10841),        INT16_MAX,  INT16_C( 32665),  INT16_C( 28633),        INT16_MAX,  INT16_C( 20138),  INT16_C( 14128) } },
    { {  INT16_C( 10643),  INT16_C( 13784), -INT16_C( 14069), -INT16_C(  6430),  INT16_C( 16323), -INT16_C( 15916),  INT16_C( 29761),  INT16_C( 11404) },
      { -INT16_C(  8844),  INT16_C( 32049), -INT16_C( 17314),  INT16_C(  5034), -INT16_C( 18394), -INT16_C( 11628), -INT16_C( 15356), -INT16_C( 26672) },
      {  INT16_C( 19487),        INT16_MAX,  INT16_C( 31383),  INT16_C( 11464),        INT16_MAX,  INT16_C( 27544),        INT16_MAX,        INT16_MAX } },
    { { -INT16_C( 22291), -INT16_C(  1844), -INT16_C( 20879),  INT16_C( 13791), -INT16_C( 19474),  INT16_C( 12278), -INT16_C( 32217), -INT16_C( 25765) },
      { -INT16_C( 29344), -INT16_C( 16872), -INT16_C( 15543),  INT16_C( 28625),  INT16_C( 25979),  INT16_C( 32578),  INT16_C(  4650),  INT16_C(  5911) },
      {        INT16_MAX,  INT16_C( 18716),        INT16_MAX,        INT16_MAX,        INT16_MAX,        INT16_MAX,        INT16_MAX,  INT16_C( 31676) } },
    { { -INT16_C(  7237),  INT16_C( 11280), -INT16_C(  4206), -INT16_C( 32671),  INT16_C( 22690), -INT16_C( 13905),  INT16_C(  2778),  INT16_C( 14948) },
      {  INT16_C( 32151), -INT16_C(  7943), -INT16_C( 13760), -INT16_C( 17584), -INT16_C( 28112),  INT16_C( 23098),  INT16_C( 20900),  INT16_C( 24433) },
      {        INT16_MAX,  INT16_C( 19223),  INT16_C( 17966),        INT16_MAX,        INT16_MAX,        INT16_MAX,  INT16_C( 23678),        INT16_MAX } },
    { { -INT16_C( 32459), -INT16_C( 14452), -INT16_C(  4752),  INT16_C(  4679), -INT16_C(  2491),  INT16_C(  8411),  INT16_C( 16384), -INT16_C( 26534) },
      {  INT16_C( 21437), -INT16_C(   648), -INT16_C( 14306),  INT16_C( 20152), -INT16_C(  3494), -INT16_C(    88),  INT16_C(  6468),  INT16_C( 31070) },
      {        INT16_MAX,  INT16_C( 15100),  INT16_C( 19058),  INT16_C( 24831),  INT16_C(  5985),  INT16_C(  8499),  INT16_C( 22852),        INT16_MAX } },
    { { -INT16_C(  5477),  INT16_C(  2880), -INT16_C( 30760),  INT16_C(  7454), -INT16_C(  1667),  INT16_C( 32061), -INT16_C( 26567), -INT16_C(  2539) },
      { -INT16_C( 28949),  INT16_C(  2547), -INT16_C( 21674), -INT16_C( 20137), -INT16_C(    98), -INT16_C(  7504),  INT16_C(  3609), -INT16_C( 19365) },
      {        INT16_MAX,  INT16_C(  5427),        INT16_MAX,  INT16_C( 27591),  INT16_C(  1765),        INT16_MAX,  INT16_C( 30176),  INT16_C( 21904) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_v8i16 a = simde_msa_ld_h(test_vec[i].a, 0);
    simde_v8i16 b = simde_msa_ld_h(test_vec[i].b, 0);
    simde_v8i16 r = simde_msa_adds_a_h(a, b);

    simde_test_msa_v8i16_assert_equal(r, simde_msa_ld_h(test_vec[i].r, 0));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_v8i16 a = simde_test_msa_v8i16_random();
    simde_v8i16 b = simde_test_msa_v8i16_random();
    simde_v8i16 r = simde_msa_adds_a_h(a, b);

    simde_test_msa_v8i16_write(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_msa_v8i16_write(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_msa_v8i16_write(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_adds_a_w (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int32_t a[4];
    int32_t b[4];
    int32_t r[4];
  } test_vec[] = {
    { { -INT32_C(   775971847), -INT32_C(  1611735774),  INT32_C(   270281943), -INT32_C(  1358482748) },
      {  INT32_C(   381287104),  INT32_C(  1153896614),  INT32_C(   690386704),  INT32_C(  2145223046) },
      {  INT32_C(  1157258951),              INT32_MAX,  INT32_C(   960668647),              INT32_MAX } },
    { {  INT32_C(  1045470236),  INT32_C(  1373453946),  INT32_C(   778172778), -INT32_C(   337745877) },
      {  INT32_C(   151164771), -INT32_C(  1219638873), -INT32_C(   941591743),  INT32_C(   273071604) },
      {  INT32_C(  1196635007),              INT32_MAX,  INT32_C(  1719764521),  INT32_C(   610817481) } },
    { { -INT32_C(   733047206),  INT32_C(  1059400660),  INT32_C(  1349355044),  INT32_C(  1379617775) },
      { -INT32_C(  1973731870),  INT32_C(  1212262407),  INT32_C(   252650011),  INT32_C(   958354911) },
      {              INT32_MAX,              INT32_MAX,  INT32_C(  1602005055),              INT32_MAX } },
    { { -INT32_C(  1089638933), -INT32_C(  1124191592), -INT32_C(  1475580743), -INT32_C(  1694873417) },
      { -INT32_C(  1943775867),  INT32_C(   416572925),  INT32_C(  1730667399),  INT32_C(   597706296) },
      {              INT32_MAX,  INT32_C(  1540764517),              INT32_MAX,              INT32_MAX } },
    { {  INT32_C(  1273212595), -INT32_C(  1727536672),  INT32_C(    88151117), -INT32_C(   509658276) },
      { -INT32_C(  1922120816), -INT32_C(  1331346904),  INT32_C(  1578617894), -INT32_C(   981289198) },
      {              INT32_MAX,              INT32_MAX,  INT32_C(  1666769011),  INT32_C(  1490947474) } },
    { {  INT32_C(  1175479653), -INT32_C(  1797318586), -INT32_C(  2003230420), -INT32_C(   311871396) },
      {  INT32_C(   595253243),  INT32_C(  1087578138), -INT32_C(     6362388),  INT32_C(   130293922) },
      {  INT32_C(  1770732896),              INT32_MAX,  INT32_C(  2009592808),  INT32_C(   442165318) } },
    { { -INT32_C(   867314299),  INT32_C(   425733613), -INT32_C(  1432225458),  INT32_C(   748096049) },
      { -INT32_C(    61926686),  INT32_C(   507257650), -INT32_C(  1356998131), -INT32_C(  2135432453) },
      {  INT32_C(   929240985),  INT32_C(   932991263),              INT32_MAX,              INT32_MAX } },
    { { -INT32_C(  1538521929),  INT32_C(  2143136817), -INT32_C(   701866331),  INT32_C(  1241694568) },
      {  INT32_C(    88494803), -INT32_C(  2111536523),  INT32_C(  1479688541), -INT32_C(   623318749) },
      {  INT32_C(  1627016732),              INT32_MAX,              INT32_MAX,  INT32_C(  1865013317) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_v4i32 a = simde_msa_ld_w(test_vec[i].a, 0);
    simde_v4i32 b = simde_msa_ld_w(test_vec[i].b, 0);
    simde_v4i32 r = simde_msa_adds_a_w(a, b);

    simde_test_msa_v4i32_assert_equal(r, simde_msa_ld_w(test_vec[i].r, 0));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_v4i32 a = simde_test_msa_v4i32_random();
    simde_v4i32 b = simde_test_msa_v4i32_random();
    simde_v4i32 r = simde_msa_adds_a_w(a, b);

    simde_test_msa_v4i32_write(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_msa_v4i32_write(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_msa_v4i32_write(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_adds_a_d (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int64_t a[2];
    int64_t b[2];
    int64_t r[2];
  } test_vec[] = {
    { {  INT64_C( 8619392506196272621),  INT64_C( 6722836897431668889) },
      {  INT64_C( 8257779916416979874), -INT64_C( 6717501796714361912) },
      {                      INT64_MAX,                      INT64_MAX } },
    { {  INT64_C( 1878106050553529800),  INT64_C( 5768944747206696488) },
      { -INT64_C( 4430696538663587077), -INT64_C( 5106390446889873716) },
      {  INT64_C( 6308802589217116877),                      INT64_MAX } },
    { {  INT64_C( 7733915600494453689), -INT64_C( 3116723109028335423) },
      { -INT64_C(  983359053643831649),  INT64_C( 3918296042725116086) },
      {  INT64_C( 8717274654138285338),  INT64_C( 7035019151753451509) } },
    { { -INT64_C( 2943168229533502599),  INT64_C( 1144201759146001460) },
      { -INT64_C( 1926412342645963221), -INT64_C( 4197656889698502901) },
      {  INT64_C( 4869580572179465820),  INT64_C( 5341858648844504361) } },
    { {  INT64_C( 2922177497925758880),  INT64_C(  246597198131090412) },
      {  INT64_C( 2517397941448348892),  INT64_C(  675936221891558479) },
      {  INT64_C( 5439575439374107772),  INT64_C(  922533420022648891) } },
    { {  INT64_C( 8697379467611333527), -INT64_C( 2667747265928108001) },
      {  INT64_C( 3931595090163945046),  INT64_C( 4161946874855700816) },
      {                      INT64_MAX,  INT64_C( 6829694140783808817) } },
    { { -INT64_C( 1433701806281293545), -INT64_C( 8703244550771839137) },
      {  INT64_C( 4560321160527747883),  INT64_C( 7392300688416971708) },
      {  INT64_C( 5994022966809041428),                      INT64_MAX } },
    { {  INT64_C( 3527483788827908667), -INT64_C( 2248487310418127085) },
      { -INT64_C(  139827905282523168), -INT64_C(  212246689587984553) },
      {  INT64_C( 3667311694110431835),  INT64_C( 2460734000006111638) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_v2i64 a = simde_msa_ld_d(test_vec[i].a, 0);
    simde_v2i64 b = simde_msa_ld_d(test_vec[i].b, 0);
    simde_v2i64 r = simde_msa_adds_a_d(a, b);

    simde_test_msa_v2i64_assert_equal(r, simde_msa_ld_d(test_vec[i].r, 0));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_v2i64 a = simde_test_msa_v2i64_random();
    simde_v2i64 b = simde_test_msa_v2i64_random();
    simde_v2i64 r = simde_msa_adds_a_d(a, b);

    simde_test_msa_v2i64_write(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_msa_v2i64_write(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_msa_v2i64_write(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(adds_a_b)
SIMDE_TEST_FUNC_LIST_ENTRY(adds_a_h)
SIMDE_TEST_FUNC_LIST_ENTRY(adds_a_w)
SIMDE_TEST_FUNC_LIST_ENTRY(adds_a_d)
SIMDE_TEST_FUNC_LIST_END

#include "test-msa-footer.h"
