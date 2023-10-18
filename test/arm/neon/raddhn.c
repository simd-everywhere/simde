#define SIMDE_TEST_ARM_NEON_INSN raddhn

#include "test-neon.h"
#include "../../../simde/arm/neon/raddhn.h"

static int
test_simde_vraddhn_s16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int16_t a[8];
    int16_t b[8];
    int8_t r[8];
  } test_vec[] = {
    { { -INT16_C(   2880), -INT16_C(  31645), -INT16_C(   2485),  INT16_C(   9929),  INT16_C(  16914),  INT16_C(  32272),  INT16_C(   6442), -INT16_C(  14878) },
      { -INT16_C(  29699),  INT16_C(   1511), -INT16_C(  14208), -INT16_C(  13119), -INT16_C(  26161), -INT16_C(   5298), -INT16_C(  19688),  INT16_C(   4298)  },
      { -INT8_C(    127), -INT8_C(    118), -INT8_C(     65), -INT8_C(     12), -INT8_C(     36),  INT8_C(    105), -INT8_C(     52), -INT8_C(     41)  } },
    { { -INT16_C(   5246), -INT16_C(   5174),  INT16_C(  30494), -INT16_C(   7937), -INT16_C(  32450),  INT16_C(  22308), -INT16_C(    538), -INT16_C(  10035) },
      {  INT16_C(   4128), -INT16_C(   6045),  INT16_C(  16379),  INT16_C(   8081),  INT16_C(  22818), -INT16_C(  20555), -INT16_C(   2824),  INT16_C(  14798)  },
      { -INT8_C(      4), -INT8_C(     44), -INT8_C(     73),  INT8_C(      1), -INT8_C(     38),  INT8_C(      7), -INT8_C(     13),  INT8_C(     19)  } },
    { {  INT16_C(   2221),  INT16_C(  27907), -INT16_C(  27153), -INT16_C(  29480),  INT16_C(   8357),  INT16_C(  14864), -INT16_C(  24039),  INT16_C(  11221) },
      { -INT16_C(   2187),  INT16_C(   9428),  INT16_C(    311),  INT16_C(  10685), -INT16_C(  13024), -INT16_C(  19804), -INT16_C(  18044),  INT16_C(  28594)  },
      {  INT8_C(      0), -INT8_C(    110), -INT8_C(    105), -INT8_C(     73), -INT8_C(     18), -INT8_C(     19),  INT8_C(     92), -INT8_C(    100)  } },
    { { -INT16_C(  21915), -INT16_C(  30855),  INT16_C(  31063),  INT16_C(  10494),  INT16_C(  28275), -INT16_C(  22384), -INT16_C(  18957),  INT16_C(  24066) },
      {  INT16_C(  31119),  INT16_C(  12866), -INT16_C(  28606), -INT16_C(    720),  INT16_C(  30735), -INT16_C(   6009), -INT16_C(   3153),  INT16_C(  26950)  },
      {  INT8_C(     36), -INT8_C(     70),  INT8_C(     10),  INT8_C(     38), -INT8_C(     25), -INT8_C(    111), -INT8_C(     86), -INT8_C(     57)  } },
    { { -INT16_C(  13275), -INT16_C(  26026),  INT16_C(  11914), -INT16_C(  15143), -INT16_C(  19155),  INT16_C(  26572),  INT16_C(  15561),  INT16_C(  22917) },
      { -INT16_C(   1816), -INT16_C(   5803),  INT16_C(    765), -INT16_C(  23566),  INT16_C(    959), -INT16_C(   1974), -INT16_C(  27160), -INT16_C(  32154)  },
      { -INT8_C(     59), -INT8_C(    124),  INT8_C(     50),  INT8_C(    105), -INT8_C(     71),  INT8_C(     96), -INT8_C(     45), -INT8_C(     36)  } },
    { {  INT16_C(  19105),  INT16_C(   6883),  INT16_C(  21461), -INT16_C(   4395), -INT16_C(  12916), -INT16_C(  25031), -INT16_C(   8163), -INT16_C(   5903) },
      {  INT16_C(  29537), -INT16_C(  12101),  INT16_C(   3094), -INT16_C(  21595), -INT16_C(  11652),  INT16_C(  19683),  INT16_C(  15385), -INT16_C(  32317)  },
      { -INT8_C(     66), -INT8_C(     20),  INT8_C(     96), -INT8_C(    102), -INT8_C(     96), -INT8_C(     21),  INT8_C(     28),  INT8_C(    107)  } },
    { { -INT16_C(   8550),  INT16_C(   6411),  INT16_C(  32264), -INT16_C(  24002),  INT16_C(  18977),  INT16_C(  19612),  INT16_C(  11311), -INT16_C(  14670) },
      {  INT16_C(   4703), -INT16_C(   5021),  INT16_C(  25452),  INT16_C(     74),  INT16_C(  10589),  INT16_C(  32145),  INT16_C(   5380), -INT16_C(   4592)  },
      { -INT8_C(     15),  INT8_C(      5), -INT8_C(     31), -INT8_C(     93),  INT8_C(    115), -INT8_C(     54),  INT8_C(     65), -INT8_C(     75)  } },
    { {  INT16_C(  11372), -INT16_C(  29543), -INT16_C(   6523),  INT16_C(  12759), -INT16_C(   4369), -INT16_C(   9669), -INT16_C(   8170), -INT16_C(   3584) },
      { -INT16_C(  24236),  INT16_C(  14447),  INT16_C(  11838),  INT16_C(  22580),  INT16_C(  20919), -INT16_C(  21841),  INT16_C(  19904), -INT16_C(  28699)  },
      { -INT8_C(     50), -INT8_C(     59),  INT8_C(     21), -INT8_C(    118),  INT8_C(     65), -INT8_C(    123),  INT8_C(     46), -INT8_C(    126)  } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x8_t a = simde_vld1q_s16(test_vec[i].a);
    simde_int16x8_t b = simde_vld1q_s16(test_vec[i].b);
    simde_int8x8_t r = simde_vraddhn_s16(a, b);

    simde_test_arm_neon_assert_equal_i8x8(r, simde_vld1_s8(test_vec[i].r));
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int16x8_t a = simde_test_arm_neon_random_i16x8();
    simde_int16x8_t b = simde_test_arm_neon_random_i16x8();
    simde_int8x8_t r = simde_vraddhn_s16(a, b);

    simde_test_arm_neon_write_i16x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i16x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i8x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vraddhn_s32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int32_t a[4];
    int32_t b[4];
    int16_t r[4];
  } test_vec[] = {
    { { -INT32_C(1269894241), -INT32_C( 908985094),  INT32_C(1593942511),  INT32_C(1873000021) },
      { -INT32_C(1333379287),  INT32_C( 986415016),  INT32_C( 675741472), -INT32_C( 128971027)  },
      {  INT16_C(     25813),  INT16_C(      1181), -INT16_C(     30903),  INT16_C(     26612)  } },
    { { -INT32_C(1810269671), -INT32_C(1392301115), -INT32_C( 302921755), -INT32_C(1464759437) },
      {  INT32_C(1128784732),  INT32_C(1723276060), -INT32_C(2025469489),  INT32_C(1054571984)  },
      { -INT16_C(     10399),  INT16_C(      5050),  INT16_C(     30008), -INT16_C(      6259)  } },
    { { -INT32_C(1761194184),  INT32_C( 588647362), -INT32_C(2039025143),  INT32_C(1310305073) },
      { -INT32_C(1673982185), -INT32_C( 150884409), -INT32_C(1727266209),  INT32_C(1820153119)  },
      {  INT16_C(     13119),  INT16_C(      6680),  INT16_C(      8067), -INT16_C(     17769)  } },
    { { -INT32_C(2109029467),  INT32_C( 646608259),  INT32_C( 121275142), -INT32_C( 983498707) },
      { -INT32_C( 764346087), -INT32_C( 869225140), -INT32_C(1137915263),  INT32_C(1742440656)  },
      {  INT16_C(     21692), -INT16_C(      3397), -INT16_C(     15513),  INT16_C(     11581)  } },
    { {  INT32_C(1191080987), -INT32_C(1518951834),  INT32_C(1681129750),  INT32_C(1556794469) },
      { -INT32_C(1947985800), -INT32_C(1780488219),  INT32_C(1270142499),  INT32_C(1362476998)  },
      { -INT16_C(     11549),  INT16_C(     15191), -INT16_C(     20503), -INT16_C(     20991)  } },
    { {  INT32_C( 450395115),  INT32_C(1265186736), -INT32_C(1762907759),  INT32_C(1247737336) },
      {  INT32_C( 648615904),  INT32_C(1603026436),  INT32_C(1624246441), -INT32_C( 762443713)  },
      {  INT16_C(     16770), -INT16_C(     21771), -INT16_C(      2116),  INT16_C(      7405)  } },
    { { -INT32_C( 774864597), -INT32_C(1855413885),  INT32_C(1412322840), -INT32_C( 139448448) },
      {  INT32_C(1992971614), -INT32_C( 622334636),  INT32_C( 320697101),  INT32_C(1784563166)  },
      {  INT16_C(     18587),  INT16_C(     27729),  INT16_C(     26444),  INT16_C(     25102)  } },
    { { -INT32_C(1195535887), -INT32_C(1186085804),  INT32_C( 275985911),  INT32_C(  29234507) },
      {  INT32_C(  55469721),  INT32_C(    629254), -INT32_C( 955594344),  INT32_C(  58737092)  },
      { -INT16_C(     17396), -INT16_C(     18089), -INT16_C(     10370),  INT16_C(      1342)  } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x4_t a = simde_vld1q_s32(test_vec[i].a);
    simde_int32x4_t b = simde_vld1q_s32(test_vec[i].b);
    simde_int16x4_t r = simde_vraddhn_s32(a, b);

    simde_test_arm_neon_assert_equal_i16x4(r, simde_vld1_s16(test_vec[i].r));
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int32x4_t a = simde_test_arm_neon_random_i32x4();
    simde_int32x4_t b = simde_test_arm_neon_random_i32x4();
    simde_int16x4_t r = simde_vraddhn_s32(a, b);

    simde_test_arm_neon_write_i32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i16x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vraddhn_s64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int64_t a[2];
    int64_t b[2];
    int32_t r[2];
  } test_vec[] = {
    { { -INT64_C(7820212674889991878), -INT64_C(2197004029258549139) },
      { -INT64_C(2938160914834829241),  INT64_C(2333620714609775238)  },
      {  INT32_C(    1790088248),  INT32_C(      31808551)  } },
    { {  INT64_C(6552516639254251817), -INT64_C(5014084713135562430) },
      {  INT64_C(5319635273832147844), -INT64_C(1063024156379059705)  },
      { -INT32_C(    1530766525), -INT32_C(    1414937170)  } },
    { { -INT64_C(635693026954200109), -INT64_C(4329254798521084257) },
      { -INT64_C(7265744133308457668), -INT64_C(3507927426648019494)  },
      { -INT32_C(    1839696700), -INT32_C(    1824736182)  } },
    { {  INT64_C(7332702632804291068),  INT64_C(692062730911992544) },
      { -INT64_C(3650629987000525309),  INT64_C(3415485980961630011)  },
      {  INT32_C(     857299344),  INT32_C(     956363210)  } },
    { {  INT64_C(5058425555123709374),  INT64_C(4080346964852498566) },
      { -INT64_C(9081086642602264799), -INT64_C(1475383767075495508)  },
      { -INT32_C(     936598770),  INT32_C(     606515258)  } },
    { { -INT64_C(155691658938406433), -INT64_C(3890983314662465847) },
      { -INT64_C(4870030385317886886), -INT64_C(8161888701331778290)  },
      { -INT32_C(    1170142098),  INT32_C(    1488689347)  } },
    { {  INT64_C(320476305215413560), -INT64_C(392761775469036542) },
      { -INT64_C(2571124399223038738), -INT64_C(7295895571957081136)  },
      { -INT32_C(     524019844), -INT32_C(    1790155039)  } },
    { {  INT64_C(6934714921123309528),  INT64_C(1713895963837179772) },
      {  INT64_C(6914907651883119212),  INT64_C(390602164641798265)  },
      { -INT32_C(    1070350758),  INT32_C(     489991654)  } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int64x2_t a = simde_vld1q_s64(test_vec[i].a);
    simde_int64x2_t b = simde_vld1q_s64(test_vec[i].b);
    simde_int32x2_t r = simde_vraddhn_s64(a, b);

    simde_test_arm_neon_assert_equal_i32x2(r, simde_vld1_s32(test_vec[i].r));
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int64x2_t a = simde_test_arm_neon_random_i64x2();
    simde_int64x2_t b = simde_test_arm_neon_random_i64x2();
    simde_int32x2_t r = simde_vraddhn_s64(a, b);

    simde_test_arm_neon_write_i64x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i64x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i32x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vraddhn_u16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint16_t a[8];
    uint16_t b[8];
    uint8_t r[8];
  } test_vec[] = {
    { {  UINT16_C(  37613),  UINT16_C(  43116),  UINT16_C(  23884),  UINT16_C(  20354),  UINT16_C(  17594),  UINT16_C(  35041),  UINT16_C(  41771),  UINT16_C(  50717) },
      {  UINT16_C(  14183),  UINT16_C(  40062),  UINT16_C(  58286),  UINT16_C(  60308),  UINT16_C(  11310),  UINT16_C(  30322),  UINT16_C(  45046),  UINT16_C(  11691)  },
      {  UINT8_C(    202),  UINT8_C(     69),  UINT8_C(     65),  UINT8_C(     59),  UINT8_C(    113),      UINT8_MAX,  UINT8_C(     83),  UINT8_C(    244)  } },
    { {  UINT16_C(  57703),  UINT16_C(  38482),  UINT16_C(  36008),  UINT16_C(   2614),  UINT16_C(  28450),  UINT16_C(   8241),  UINT16_C(  48645),  UINT16_C(  56796) },
      {  UINT16_C(   1851),  UINT16_C(   6016),  UINT16_C(  17360),  UINT16_C(  45761),  UINT16_C(  13621),  UINT16_C(  64150),  UINT16_C(  40219),  UINT16_C(  11061)  },
      {  UINT8_C(    233),  UINT8_C(    174),  UINT8_C(    208),  UINT8_C(    189),  UINT8_C(    164),  UINT8_C(     27),  UINT8_C(     91),  UINT8_C(      9)  } },
    { {  UINT16_C(  31428),  UINT16_C(   7367),  UINT16_C(  45732),  UINT16_C(  24472),  UINT16_C(  54660),  UINT16_C(   7748),  UINT16_C(  54606),  UINT16_C(  39752) },
      {  UINT16_C(  51706),  UINT16_C(  15878),  UINT16_C(  58199),  UINT16_C(   6507),  UINT16_C(  19974),  UINT16_C(  29962),  UINT16_C(  28578),  UINT16_C(   4687)  },
      {  UINT8_C(     69),  UINT8_C(     91),  UINT8_C(    150),  UINT8_C(    121),  UINT8_C(     36),  UINT8_C(    147),  UINT8_C(     69),  UINT8_C(    174)  } },
    { {  UINT16_C(  11063),  UINT16_C(  28529),  UINT16_C(  26453),  UINT16_C(  21236),  UINT16_C(  57102),  UINT16_C(  38754),  UINT16_C(  61126),  UINT16_C(  34925) },
      {  UINT16_C(  46442),  UINT16_C(  33134),  UINT16_C(  17636),  UINT16_C(  36223),  UINT16_C(  21723),  UINT16_C(  56442),  UINT16_C(  10026),  UINT16_C(  61597)  },
      {  UINT8_C(    225),  UINT8_C(    241),  UINT8_C(    172),  UINT8_C(    224),  UINT8_C(     52),  UINT8_C(    116),  UINT8_C(     22),  UINT8_C(    121)  } },
    { {  UINT16_C(   2731),  UINT16_C(   9316),  UINT16_C(  49854),  UINT16_C(  18896),  UINT16_C(  49267),  UINT16_C(  45904),  UINT16_C(  29001),  UINT16_C(   2858) },
      {  UINT16_C(  20162),  UINT16_C(   1776),  UINT16_C(  13357),  UINT16_C(   7672),  UINT16_C(  16606),  UINT16_C(   5538),  UINT16_C(  38719),  UINT16_C(  12760)  },
      {  UINT8_C(     89),  UINT8_C(     43),  UINT8_C(    247),  UINT8_C(    104),  UINT8_C(      1),  UINT8_C(    201),  UINT8_C(      9),  UINT8_C(     61)  } },
    { {  UINT16_C(  12795),  UINT16_C(   4896),  UINT16_C(  23330),  UINT16_C(  10108),  UINT16_C(  23802),  UINT16_C(  27438),  UINT16_C(   8867),  UINT16_C(  30490) },
      {  UINT16_C(  28135),  UINT16_C(  46983),  UINT16_C(  24268),  UINT16_C(  25599),  UINT16_C(  20157),  UINT16_C(  41969),  UINT16_C(  61408),  UINT16_C(  41777)  },
      {  UINT8_C(    160),  UINT8_C(    203),  UINT8_C(    186),  UINT8_C(    139),  UINT8_C(    172),  UINT8_C(     15),  UINT8_C(     19),  UINT8_C(     26)  } },
    { {  UINT16_C(  37491),  UINT16_C(  17703),  UINT16_C(   9458),  UINT16_C(  65074),  UINT16_C(  20959),  UINT16_C(  32245),  UINT16_C(  26919),  UINT16_C(  60176) },
      {  UINT16_C(  22889),  UINT16_C(  32794),  UINT16_C(  15720),  UINT16_C(  31240),  UINT16_C(  32411),  UINT16_C(  62788),  UINT16_C(  43813),  UINT16_C(  63876)  },
      {  UINT8_C(    236),  UINT8_C(    197),  UINT8_C(     98),  UINT8_C(    120),  UINT8_C(    208),  UINT8_C(    115),  UINT8_C(     20),  UINT8_C(    229)  } },
    { {  UINT16_C(  12277),  UINT16_C(  32281),  UINT16_C(  37982),  UINT16_C(  34110),  UINT16_C(  47012),  UINT16_C(  58861),  UINT16_C(  64783),  UINT16_C(  43738) },
      {  UINT16_C(  23822),  UINT16_C(  44289),  UINT16_C(  23707),  UINT16_C(  12158),  UINT16_C(  15480),  UINT16_C(  49961),  UINT16_C(   5675),  UINT16_C(  59593)  },
      {  UINT8_C(    141),  UINT8_C(     43),  UINT8_C(    241),  UINT8_C(    181),  UINT8_C(    244),  UINT8_C(    169),  UINT8_C(     19),  UINT8_C(    148)  } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint16x8_t a = simde_vld1q_u16(test_vec[i].a);
    simde_uint16x8_t b = simde_vld1q_u16(test_vec[i].b);
    simde_uint8x8_t r = simde_vraddhn_u16(a, b);

    simde_test_arm_neon_assert_equal_u8x8(r, simde_vld1_u8(test_vec[i].r));
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint16x8_t a = simde_test_arm_neon_random_u16x8();
    simde_uint16x8_t b = simde_test_arm_neon_random_u16x8();
    simde_uint8x8_t r = simde_vraddhn_u16(a, b);

    simde_test_arm_neon_write_u16x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u16x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u8x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vraddhn_u32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint32_t a[4];
    uint32_t b[4];
    uint16_t r[4];
  } test_vec[] = {
    { {  UINT32_C(1599077134),  UINT32_C(2685955823),  UINT32_C(1535880878),  UINT32_C(1407804329) },
      {  UINT32_C(3668802610),  UINT32_C( 533029653),  UINT32_C(2777570489),  UINT32_C(  85112890)  },
      {  UINT16_C(     14845),  UINT16_C(     49118),  UINT16_C(       282),  UINT16_C(     22780)  } },
    { {  UINT32_C( 844280000),  UINT32_C(1299592057),  UINT32_C(2935929945),  UINT32_C(1509650752) },
      {  UINT32_C( 586314966),  UINT32_C( 647283132),  UINT32_C(1980614668),  UINT32_C(1085490525)  },
      {  UINT16_C(     21829),  UINT16_C(     29707),  UINT16_C(      9485),  UINT16_C(     39599)  } },
    { {  UINT32_C(2656176301),  UINT32_C(2150911055),  UINT32_C( 952074682),  UINT32_C(3083072123) },
      {  UINT32_C(3672636508),  UINT32_C( 752995622),  UINT32_C(2357424942),  UINT32_C(2352627710)  },
      {  UINT16_C(     31034),  UINT16_C(     44310),  UINT16_C(     50499),  UINT16_C(     17406)  } },
    { {  UINT32_C(1590271315),  UINT32_C(1734070346),  UINT32_C(4243366597),  UINT32_C( 181144014) },
      {  UINT32_C( 875291705),  UINT32_C(4233293053),  UINT32_C(2871217210),  UINT32_C(3618956669)  },
      {  UINT16_C(     37622),  UINT16_C(     25519),  UINT16_C(     43024),  UINT16_C(     57985)  } },
    { {  UINT32_C( 893970267),  UINT32_C(  47668152),  UINT32_C( 342513840),  UINT32_C(2414300529) },
      {  UINT32_C(3185116321),  UINT32_C(1517676379),  UINT32_C(1426651672),  UINT32_C(1979158981)  },
      {  UINT16_C(     62242),  UINT16_C(     23885),  UINT16_C(     26995),  UINT16_C(      1503)  } },
    { {  UINT32_C(3923868843),  UINT32_C(2329754825),  UINT32_C(3687450793),  UINT32_C(3801169291) },
      {  UINT32_C(1949399041),  UINT32_C( 508959889),  UINT32_C(1171199549),  UINT32_C(2658068365)  },
      {  UINT16_C(     24083),  UINT16_C(     43315),  UINT16_C(      8601),  UINT16_C(     33024)  } },
    { {  UINT32_C( 700616631),  UINT32_C( 439195780),  UINT32_C(3182273828),  UINT32_C(1928850695) },
      {  UINT32_C(3813632070),  UINT32_C(2483472338),  UINT32_C(1045877070),  UINT32_C(4233527679)  },
      {  UINT16_C(      3346),  UINT16_C(     44596),  UINT16_C(     64516),  UINT16_C(     28494)  } },
    { {  UINT32_C(4193873059),  UINT32_C(1223881358),  UINT32_C( 576680884),  UINT32_C(1649826296) },
      {  UINT32_C( 657078515),  UINT32_C( 653216189),  UINT32_C(2522008160),  UINT32_C(4176276405)  },
      {  UINT16_C(      8484),  UINT16_C(     28642),  UINT16_C(     47282),  UINT16_C(     23363)  } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint32x4_t a = simde_vld1q_u32(test_vec[i].a);
    simde_uint32x4_t b = simde_vld1q_u32(test_vec[i].b);
    simde_uint16x4_t r = simde_vraddhn_u32(a, b);

    simde_test_arm_neon_assert_equal_u16x4(r, simde_vld1_u16(test_vec[i].r));
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint32x4_t a = simde_test_arm_neon_random_u32x4();
    simde_uint32x4_t b = simde_test_arm_neon_random_u32x4();
    simde_uint16x4_t r = simde_vraddhn_u32(a, b);

    simde_test_arm_neon_write_u32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u16x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vraddhn_u64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint64_t a[2];
    uint64_t b[2];
    uint32_t r[2];
  } test_vec[] = {
    { {  UINT64_C( 3658221119983586522),  UINT64_C(13624450708070574745) },
      {  UINT64_C( 7046718151405549136),  UINT64_C( 3296843776638760148)  },
      {  UINT32_C(          2492437901),  UINT32_C(          3939795886)  } },
    { {  UINT64_C(10310172816141081280),  UINT64_C( 3376994261991074207) },
      {  UINT64_C(11494608161389779618),  UINT64_C( 3612232709931170060)  },
      {  UINT32_C(           781853894),  UINT32_C(          1627306215)  } },
    { {  UINT64_C( 3983515379071047640),  UINT64_C(  683812206328697011) },
      {  UINT64_C(17437067970154921917),  UINT64_C( 3851963522941548347)  },
      {  UINT32_C(           692400913),  UINT32_C(          1056067583)  } },
    { {  UINT64_C( 1751127879165911272),  UINT64_C( 5926739473801593863) },
      {  UINT64_C(16950044079879418680),  UINT64_C(17928468287003282561)  },
      {  UINT32_C(            59238608),  UINT32_C(          1259256081)  } },
    { {  UINT64_C(11355337902764347302),  UINT64_C( 8883462255544729120) },
      {  UINT64_C(12547381047271968305),  UINT64_C(10516517387439026716)  },
      {  UINT32_C(          1270318142),  UINT32_C(           221942451)  } },
    { {  UINT64_C( 8246918623211434206),  UINT64_C(  519113934888829026) },
      {  UINT64_C(15938487908952821021),  UINT64_C( 5324233429962735477)  },
      {  UINT32_C(          1336136474),  UINT32_C(          1360510328)  } },
    { {  UINT64_C(17751366330943116804),  UINT64_C(14347530208924216630) },
      {  UINT64_C(11330187298328579592),  UINT64_C(13898502737226142347)  },
      {  UINT32_C(          2476109554),  UINT32_C(          2281574736)  } },
    { {  UINT64_C(  954615016345450251),  UINT64_C( 6743074694315865715) },
      {  UINT64_C(16957999455362759714),  UINT64_C(   28138425858485463)  },
      {  UINT32_C(          4170605557),  UINT32_C(          1576545909)  } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint64x2_t a = simde_vld1q_u64(test_vec[i].a);
    simde_uint64x2_t b = simde_vld1q_u64(test_vec[i].b);
    simde_uint32x2_t r = simde_vraddhn_u64(a, b);

    simde_test_arm_neon_assert_equal_u32x2(r, simde_vld1_u32(test_vec[i].r));
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint64x2_t a = simde_test_arm_neon_random_u64x2();
    simde_uint64x2_t b = simde_test_arm_neon_random_u64x2();
    simde_uint32x2_t r = simde_vraddhn_u64(a, b);

    simde_test_arm_neon_write_u64x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u64x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(vraddhn_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vraddhn_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vraddhn_s64)

SIMDE_TEST_FUNC_LIST_ENTRY(vraddhn_u16)
SIMDE_TEST_FUNC_LIST_ENTRY(vraddhn_u32)
SIMDE_TEST_FUNC_LIST_ENTRY(vraddhn_u64)
SIMDE_TEST_FUNC_LIST_END

#include "test-neon-footer.h"
