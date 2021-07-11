#define SIMDE_TEST_MIPS_MSA_INSN add_a

#include "test-msa.h"
#include "../../../simde/mips/msa/add_a.h"

static int
test_simde_add_a_b (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int8_t a[16];
    int8_t b[16];
    int8_t r[16];
  } test_vec[] = {
    { { -INT8_C(  87), -INT8_C(  78),  INT8_C(  87), -INT8_C(  18), -INT8_C(  51),  INT8_C( 101), -INT8_C(  94),  INT8_C(  94),
        -INT8_C(  28),  INT8_C(  86), -INT8_C(  70), -INT8_C(  30), -INT8_C(  14),  INT8_C(  19), -INT8_C(  74), -INT8_C( 122) },
      {  INT8_C(  25),  INT8_C(  95),  INT8_C(  48),  INT8_C( 122),  INT8_C(   1),  INT8_C(  54), -INT8_C(  71), -INT8_C( 112),
        -INT8_C(  24), -INT8_C(  64), -INT8_C(  97), -INT8_C(  71), -INT8_C(  86),  INT8_C(  70),  INT8_C(  16),  INT8_C(  83) },
      {  INT8_C( 112), -INT8_C(  83), -INT8_C( 121), -INT8_C( 116),  INT8_C(  52), -INT8_C( 101), -INT8_C(  91), -INT8_C(  50),
         INT8_C(  52), -INT8_C( 106), -INT8_C(  89),  INT8_C( 101),  INT8_C( 100),  INT8_C(  89),  INT8_C(  90), -INT8_C(  51) } },
    { { -INT8_C(   8),  INT8_C( 103),  INT8_C(  66), -INT8_C(  59), -INT8_C(  51), -INT8_C(  28),  INT8_C(  36), -INT8_C(  79),
         INT8_C(  58), -INT8_C(  34), -INT8_C( 109),  INT8_C(  44), -INT8_C(  15),  INT8_C(  73), -INT8_C(  78),  INT8_C(  10) },
      { -INT8_C(  88), -INT8_C(  30), -INT8_C( 123), -INT8_C(  87),  INT8_C(  25),  INT8_C(  62),  INT8_C(  57),  INT8_C(   1),
        -INT8_C(   1), -INT8_C(  40), -INT8_C(  70), -INT8_C(  87),  INT8_C(  31), -INT8_C(  54), -INT8_C(   4),  INT8_C(  23) },
      {  INT8_C(  96), -INT8_C( 123), -INT8_C(  67), -INT8_C( 110),  INT8_C(  76),  INT8_C(  90),  INT8_C(  93),  INT8_C(  80),
         INT8_C(  59),  INT8_C(  74), -INT8_C(  77), -INT8_C( 125),  INT8_C(  46),      INT8_MAX,  INT8_C(  82),  INT8_C(  33) } },
    { {  INT8_C(  50),  INT8_C(  62), -INT8_C(  35), -INT8_C(   1),  INT8_C(  34),  INT8_C(   1), -INT8_C(  80),  INT8_C(  92),
        -INT8_C(  33),  INT8_C(  67), -INT8_C( 120), -INT8_C(  47), -INT8_C( 115),  INT8_C(  59), -INT8_C(  37),  INT8_C(  53) },
      {  INT8_C(  29),  INT8_C(  96), -INT8_C(  33),  INT8_C(  54), -INT8_C(  97),  INT8_C(  24),  INT8_C(  55), -INT8_C(  98),
        -INT8_C(  15), -INT8_C(  14),  INT8_C(  71),  INT8_C(  16), -INT8_C(  68),  INT8_C(  67),  INT8_C(  39), -INT8_C(  18) },
      {  INT8_C(  79), -INT8_C(  98),  INT8_C(  68),  INT8_C(  55), -INT8_C( 125),  INT8_C(  25), -INT8_C( 121), -INT8_C(  66),
         INT8_C(  48),  INT8_C(  81), -INT8_C(  65),  INT8_C(  63), -INT8_C(  73),  INT8_C( 126),  INT8_C(  76),  INT8_C(  71) } },
    { { -INT8_C( 126),  INT8_C(   4), -INT8_C(  19), -INT8_C(  92),  INT8_C(   5), -INT8_C(  99),  INT8_C(   1), -INT8_C(  27),
        -INT8_C(  31), -INT8_C( 119), -INT8_C(  74),  INT8_C( 110), -INT8_C(  60), -INT8_C( 111), -INT8_C(  93), -INT8_C(  30) },
      { -INT8_C(  14), -INT8_C( 126),  INT8_C(  24), -INT8_C( 111), -INT8_C( 101),  INT8_C(  80),  INT8_C(  47), -INT8_C( 116),
         INT8_C(  66),  INT8_C( 118), -INT8_C( 100), -INT8_C(   2), -INT8_C(  71), -INT8_C(  61), -INT8_C(  19),  INT8_C(  59) },
      { -INT8_C( 116), -INT8_C( 126),  INT8_C(  43), -INT8_C(  53),  INT8_C( 106), -INT8_C(  77),  INT8_C(  48), -INT8_C( 113),
         INT8_C(  97), -INT8_C(  19), -INT8_C(  82),  INT8_C( 112), -INT8_C( 125), -INT8_C(  84),  INT8_C( 112),  INT8_C(  89) } },
    { { -INT8_C(  56), -INT8_C(  38), -INT8_C(  32), -INT8_C(  51),  INT8_C( 120), -INT8_C(  31), -INT8_C(  78),  INT8_C(  89),
         INT8_C( 106),  INT8_C( 104), -INT8_C(  57),  INT8_C(  47), -INT8_C(   6),  INT8_C( 106),  INT8_C(  17), -INT8_C(  20) },
      { -INT8_C(  19),  INT8_C(  41),  INT8_C( 125), -INT8_C( 120),  INT8_C( 121), -INT8_C(  84),  INT8_C(  20), -INT8_C(  69),
         INT8_C(  34), -INT8_C(  80), -INT8_C(  70), -INT8_C(  37),  INT8_C( 115), -INT8_C(  89),  INT8_C(  23),  INT8_C(  59) },
      {  INT8_C(  75),  INT8_C(  79), -INT8_C(  99), -INT8_C(  85), -INT8_C(  15),  INT8_C( 115),  INT8_C(  98), -INT8_C(  98),
        -INT8_C( 116), -INT8_C(  72),      INT8_MAX,  INT8_C(  84),  INT8_C( 121), -INT8_C(  61),  INT8_C(  40),  INT8_C(  79) } },
    { { -INT8_C( 127), -INT8_C(   9),  INT8_C(   9), -INT8_C(   7), -INT8_C(  40), -INT8_C(  69),  INT8_C(  82),  INT8_C(  66),
         INT8_C(  36),  INT8_C(  25),  INT8_C( 113),  INT8_C(  30), -INT8_C( 124), -INT8_C( 126),  INT8_C(  10),  INT8_C( 113) },
      { -INT8_C(  84), -INT8_C( 121), -INT8_C(   7),  INT8_C(  37),  INT8_C(  51),  INT8_C(  13), -INT8_C(  31),  INT8_C(  85),
        -INT8_C(  67), -INT8_C( 101),  INT8_C(  48),  INT8_C(  48),  INT8_C(  66),  INT8_C(  71),  INT8_C( 108), -INT8_C(  61) },
      { -INT8_C(  45), -INT8_C( 126),  INT8_C(  16),  INT8_C(  44),  INT8_C(  91),  INT8_C(  82),  INT8_C( 113), -INT8_C( 105),
         INT8_C( 103),  INT8_C( 126), -INT8_C(  95),  INT8_C(  78), -INT8_C(  66), -INT8_C(  59),  INT8_C( 118), -INT8_C(  82) } },
    { {  INT8_C(  62),  INT8_C( 117), -INT8_C(  67),  INT8_C(  22),  INT8_C(  48),  INT8_C(  15),  INT8_C(  89),  INT8_C(  84),
         INT8_C(  41), -INT8_C(  54),  INT8_C( 114), -INT8_C(  83),  INT8_C(  77),  INT8_C( 124),  INT8_C(  30), -INT8_C(   7) },
      {  INT8_C(   3),  INT8_C(  23),  INT8_C(  30),  INT8_C(  54),  INT8_C(  36), -INT8_C(   1), -INT8_C( 117), -INT8_C(  31),
        -INT8_C( 102), -INT8_C(  68),  INT8_C(  17), -INT8_C(  36),  INT8_C(   3),  INT8_C( 125), -INT8_C(  96),  INT8_C(  66) },
      {  INT8_C(  65), -INT8_C( 116),  INT8_C(  97),  INT8_C(  76),  INT8_C(  84),  INT8_C(  16), -INT8_C(  50),  INT8_C( 115),
        -INT8_C( 113),  INT8_C( 122), -INT8_C( 125),  INT8_C( 119),  INT8_C(  80), -INT8_C(   7),  INT8_C( 126),  INT8_C(  73) } },
    { { -INT8_C(  14),  INT8_C(  93),  INT8_C(  88),  INT8_C(  35),  INT8_C( 108), -INT8_C(  79),  INT8_C( 119), -INT8_C( 107),
         INT8_C( 124), -INT8_C(  22),  INT8_C(  66), -INT8_C(  55),  INT8_C( 102),  INT8_C(  96), -INT8_C(  62),  INT8_C( 106) },
      {  INT8_C( 119), -INT8_C(  32), -INT8_C(  96), -INT8_C( 101), -INT8_C(  32),  INT8_C(  44),  INT8_C( 124),  INT8_C( 122),
        -INT8_C(  24), -INT8_C( 114),  INT8_C(  87), -INT8_C(  21),  INT8_C(  11), -INT8_C(   9),  INT8_C(  45), -INT8_C(   2) },
      { -INT8_C( 123),  INT8_C( 125), -INT8_C(  72), -INT8_C( 120), -INT8_C( 116),  INT8_C( 123), -INT8_C(  13), -INT8_C(  27),
        -INT8_C( 108), -INT8_C( 120), -INT8_C( 103),  INT8_C(  76),  INT8_C( 113),  INT8_C( 105),  INT8_C( 107),  INT8_C( 108) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_v16i8 a = simde_msa_ld_b(test_vec[i].a, 0);
    simde_v16i8 b = simde_msa_ld_b(test_vec[i].b, 0);
    simde_v16i8 r = simde_msa_add_a_b(a, b);

    simde_test_msa_v16i8_assert_equal(r, simde_msa_ld_b(test_vec[i].r, 0));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_v16i8 a = simde_test_msa_v16i8_random();
    simde_v16i8 b = simde_test_msa_v16i8_random();
    simde_v16i8 r = simde_msa_add_a_b(a, b);

    simde_test_msa_v16i8_write(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_msa_v16i8_write(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_msa_v16i8_write(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_add_a_h (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int16_t a[8];
    int16_t b[8];
    int16_t r[8];
  } test_vec[] = {
    { { -INT16_C( 31148), -INT16_C( 16351), -INT16_C( 26569), -INT16_C( 19626), -INT16_C( 26494), -INT16_C(  5764),  INT16_C( 16121),  INT16_C( 28755) },
      { -INT16_C(  3297), -INT16_C(   244), -INT16_C( 30689),  INT16_C(  1913), -INT16_C( 12266),  INT16_C(  8947),  INT16_C(  8391),  INT16_C(  6944) },
      { -INT16_C( 31091),  INT16_C( 16595), -INT16_C(  8278),  INT16_C( 21539), -INT16_C( 26776),  INT16_C( 14711),  INT16_C( 24512), -INT16_C( 29837) } },
    { {  INT16_C( 16806), -INT16_C(  8484),  INT16_C( 13017),  INT16_C( 23697),  INT16_C(  3786), -INT16_C( 15547), -INT16_C( 26548),  INT16_C( 27444) },
      {  INT16_C( 16523), -INT16_C( 21654), -INT16_C(  6968), -INT16_C(  8270), -INT16_C( 23116),  INT16_C( 31745),  INT16_C(  8646),  INT16_C( 27799) },
      { -INT16_C( 32207),  INT16_C( 30138),  INT16_C( 19985),  INT16_C( 31967),  INT16_C( 26902), -INT16_C( 18244), -INT16_C( 30342), -INT16_C( 10293) } },
    { {  INT16_C( 29538),  INT16_C( 15178), -INT16_C(  9051),  INT16_C( 28823), -INT16_C(  8982),  INT16_C( 13875),  INT16_C( 26484),  INT16_C(   162) },
      {  INT16_C(  3239),  INT16_C( 28843),  INT16_C( 24048), -INT16_C( 23217),  INT16_C( 20483), -INT16_C( 14047), -INT16_C( 18319), -INT16_C( 11467) },
      { -INT16_C( 32759), -INT16_C( 21515), -INT16_C( 32437), -INT16_C( 13496),  INT16_C( 29465),  INT16_C( 27922), -INT16_C( 20733),  INT16_C( 11629) } },
    { { -INT16_C( 32724), -INT16_C( 12018), -INT16_C( 22948),  INT16_C( 17985),  INT16_C( 30082), -INT16_C(  2180),  INT16_C(  7900), -INT16_C( 31497) },
      { -INT16_C( 24021),  INT16_C(  7156),  INT16_C( 17407),  INT16_C(   704), -INT16_C(  7789),  INT16_C(  1227),  INT16_C(   410), -INT16_C( 14633) },
      { -INT16_C(  8791),  INT16_C( 19174), -INT16_C( 25181),  INT16_C( 18689), -INT16_C( 27665),  INT16_C(  3407),  INT16_C(  8310), -INT16_C( 19406) } },
    { { -INT16_C(  6783), -INT16_C(  8809), -INT16_C(  9845),  INT16_C(  3619), -INT16_C( 24754),  INT16_C( 10757), -INT16_C(   834), -INT16_C(  5714) },
      { -INT16_C( 23906), -INT16_C( 25340), -INT16_C( 14875),  INT16_C( 30880),  INT16_C( 27558),  INT16_C( 16508),  INT16_C( 21356), -INT16_C(  4858) },
      {  INT16_C( 30689), -INT16_C( 31387),  INT16_C( 24720), -INT16_C( 31037), -INT16_C( 13224),  INT16_C( 27265),  INT16_C( 22190),  INT16_C( 10572) } },
    { { -INT16_C( 25031), -INT16_C( 15158), -INT16_C(  4745), -INT16_C( 14894), -INT16_C( 10355),  INT16_C( 19439), -INT16_C( 24877),  INT16_C( 28980) },
      {  INT16_C( 14400),  INT16_C(  9743), -INT16_C( 20483), -INT16_C( 23394),  INT16_C(  6938), -INT16_C( 30748), -INT16_C(  5266), -INT16_C( 22668) },
      { -INT16_C( 26105),  INT16_C( 24901),  INT16_C( 25228), -INT16_C( 27248),  INT16_C( 17293), -INT16_C( 15349),  INT16_C( 30143), -INT16_C( 13888) } },
    { {  INT16_C( 16265),  INT16_C(   108),  INT16_C( 15916), -INT16_C( 17979), -INT16_C( 19434), -INT16_C(  5884),  INT16_C( 14418), -INT16_C( 27813) },
      {  INT16_C( 27249),  INT16_C( 28345),  INT16_C( 22297),  INT16_C( 13074), -INT16_C(  2190), -INT16_C(  7750),  INT16_C( 12258),  INT16_C( 27528) },
      { -INT16_C( 22022),  INT16_C( 28453), -INT16_C( 27323),  INT16_C( 31053),  INT16_C( 21624),  INT16_C( 13634),  INT16_C( 26676), -INT16_C( 10195) } },
    { { -INT16_C(  2962), -INT16_C( 26005),  INT16_C( 12339),  INT16_C( 18772),  INT16_C( 22756),  INT16_C( 14130), -INT16_C( 29295),  INT16_C(   714) },
      { -INT16_C( 31753),  INT16_C(  4208), -INT16_C( 31782),  INT16_C( 19780), -INT16_C(   390),  INT16_C( 23598), -INT16_C( 18899), -INT16_C( 25657) },
      { -INT16_C( 30821),  INT16_C( 30213), -INT16_C( 21415), -INT16_C( 26984),  INT16_C( 23146), -INT16_C( 27808), -INT16_C( 17342),  INT16_C( 26371) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_v8i16 a = simde_msa_ld_h(test_vec[i].a, 0);
    simde_v8i16 b = simde_msa_ld_h(test_vec[i].b, 0);
    simde_v8i16 r = simde_msa_add_a_h(a, b);

    simde_test_msa_v8i16_assert_equal(r, simde_msa_ld_h(test_vec[i].r, 0));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_v8i16 a = simde_test_msa_v8i16_random();
    simde_v8i16 b = simde_test_msa_v8i16_random();
    simde_v8i16 r = simde_msa_add_a_h(a, b);

    simde_test_msa_v8i16_write(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_msa_v8i16_write(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_msa_v8i16_write(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_add_a_w (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int32_t a[4];
    int32_t b[4];
    int32_t r[4];
  } test_vec[] = {
    { { -INT32_C(   566873429),  INT32_C(  1176996450),  INT32_C(  1937594850), -INT32_C(   562739225) },
      { -INT32_C(  1511004470), -INT32_C(   470666391),  INT32_C(  1597972529), -INT32_C(  2114320682) },
      {  INT32_C(  2077877899),  INT32_C(  1647662841), -INT32_C(   759399917), -INT32_C(  1617907389) } },
    { { -INT32_C(  1705037768), -INT32_C(  1646229830), -INT32_C(   955228448),  INT32_C(  1889896101) },
      { -INT32_C(   720006036), -INT32_C(   105379897), -INT32_C(    44501209),  INT32_C(   897536765) },
      { -INT32_C(  1869923492),  INT32_C(  1751609727),  INT32_C(   999729657), -INT32_C(  1507534430) } },
    { {  INT32_C(  1037033091),  INT32_C(  1171959653), -INT32_C(  1290999027), -INT32_C(   584863375) },
      {  INT32_C(   229783622),  INT32_C(  1711696447),  INT32_C(  1583570529),  INT32_C(   882107057) },
      {  INT32_C(  1266816713), -INT32_C(  1411311196), -INT32_C(  1420397740),  INT32_C(  1466970432) } },
    { {  INT32_C(   644965057),  INT32_C(   527125521), -INT32_C(  1462601929),  INT32_C(  1854272808) },
      {  INT32_C(  1820079917),  INT32_C(    47350433), -INT32_C(  1839188511), -INT32_C(   641273064) },
      { -INT32_C(  1829922322),  INT32_C(   574475954), -INT32_C(   993176856), -INT32_C(  1799421424) } },
    { {  INT32_C(  1728001877), -INT32_C(  1165661565),  INT32_C(   157439969),  INT32_C(  2037966668) },
      { -INT32_C(  1075448802),  INT32_C(  1472313206),  INT32_C(    99164653),  INT32_C(  1776201492) },
      { -INT32_C(  1491516617), -INT32_C(  1656992525),  INT32_C(   256604622), -INT32_C(   480799136) } },
    { {  INT32_C(  1792073191),  INT32_C(   673535303), -INT32_C(   114194515), -INT32_C(  1921799825) },
      {  INT32_C(   340613277), -INT32_C(    43315696),  INT32_C(  1141003568), -INT32_C(   340860924) },
      {  INT32_C(  2132686468),  INT32_C(   716850999),  INT32_C(  1255198083), -INT32_C(  2032306547) } },
    { {  INT32_C(    72777405), -INT32_C(  2144568365),  INT32_C(  1903844610), -INT32_C(  1526731513) },
      {  INT32_C(  1438141509), -INT32_C(  1974328230),  INT32_C(  2110739577), -INT32_C(   244744908) },
      {  INT32_C(  1510918914), -INT32_C(   176070701), -INT32_C(   280383109),  INT32_C(  1771476421) } },
    { { -INT32_C(   822755333),  INT32_C(  1011818810), -INT32_C(  2035365505), -INT32_C(    81089098) },
      {  INT32_C(  1397875705), -INT32_C(  2132892921),  INT32_C(   754822648),  INT32_C(   622749226) },
      { -INT32_C(  2074336258), -INT32_C(  1150255565), -INT32_C(  1504779143),  INT32_C(   703838324) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_v4i32 a = simde_msa_ld_w(test_vec[i].a, 0);
    simde_v4i32 b = simde_msa_ld_w(test_vec[i].b, 0);
    simde_v4i32 r = simde_msa_add_a_w(a, b);

    simde_test_msa_v4i32_assert_equal(r, simde_msa_ld_w(test_vec[i].r, 0));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_v4i32 a = simde_test_msa_v4i32_random();
    simde_v4i32 b = simde_test_msa_v4i32_random();
    simde_v4i32 r = simde_msa_add_a_w(a, b);

    simde_test_msa_v4i32_write(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_msa_v4i32_write(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_msa_v4i32_write(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_add_a_d (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int64_t a[2];
    int64_t b[2];
    int64_t r[2];
  } test_vec[] = {
    { { -INT64_C( 5432394253505195227), -INT64_C( 1099611718747010549) },
      { -INT64_C( 6210989790691389881),  INT64_C( 6349499549422636238) },
      { -INT64_C( 6803360029512966508),  INT64_C( 7449111268169646787) } },
    { {  INT64_C( 6913117044979732743), -INT64_C( 2989020643931968867) },
      { -INT64_C( 5168175337671636757),  INT64_C( 1750437977373285567) },
      { -INT64_C( 6365451691058182116),  INT64_C( 4739458621305254434) } },
    { { -INT64_C(  967916212689042977),  INT64_C( 8923050949783040623) },
      { -INT64_C( 5947743357700080941), -INT64_C( 3268511672312060549) },
      {  INT64_C( 6915659570389123918), -INT64_C( 6255181451614450444) } },
    { { -INT64_C( 6038598960555886358), -INT64_C( 7470485773940442808) },
      {  INT64_C( 4905768860484201338), -INT64_C( 8667894790130453521) },
      { -INT64_C( 7502376252669463920), -INT64_C( 2308363509638655287) } },
    { { -INT64_C( 7397733783278536085), -INT64_C(  428188858531643215) },
      {  INT64_C( 2034912546470847279), -INT64_C( 1419278738557825751) },
      { -INT64_C( 9014097743960168252),  INT64_C( 1847467597089468966) } },
    { { -INT64_C( 4802268712145710225), -INT64_C( 4655524026281374742) },
      {  INT64_C( 7345078779069908388),  INT64_C( 1328976004448513283) },
      { -INT64_C( 6299396582493933003),  INT64_C( 5984500030729888025) } },
    { { -INT64_C( 2714213788569958773),  INT64_C( 7946505655341582584) },
      { -INT64_C(  500410871655169939),  INT64_C( 4382265984115685659) },
      {  INT64_C( 3214624660225128712), -INT64_C( 6117972434252283373) } },
    { { -INT64_C( 4053475166719270155),  INT64_C( 1795413064712913841) },
      {  INT64_C( 8324568940466481814), -INT64_C( 1660137266343771128) },
      { -INT64_C( 6068699966523799647),  INT64_C( 3455550331056684969) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_v2i64 a = simde_msa_ld_d(test_vec[i].a, 0);
    simde_v2i64 b = simde_msa_ld_d(test_vec[i].b, 0);
    simde_v2i64 r = simde_msa_add_a_d(a, b);

    simde_test_msa_v2i64_assert_equal(r, simde_msa_ld_d(test_vec[i].r, 0));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_v2i64 a = simde_test_msa_v2i64_random();
    simde_v2i64 b = simde_test_msa_v2i64_random();
    simde_v2i64 r = simde_msa_add_a_d(a, b);

    simde_test_msa_v2i64_write(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_msa_v2i64_write(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_msa_v2i64_write(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(add_a_b)
SIMDE_TEST_FUNC_LIST_ENTRY(add_a_h)
SIMDE_TEST_FUNC_LIST_ENTRY(add_a_w)
SIMDE_TEST_FUNC_LIST_ENTRY(add_a_d)
SIMDE_TEST_FUNC_LIST_END

#include "test-msa-footer.h"
