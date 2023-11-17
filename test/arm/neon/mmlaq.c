#define SIMDE_TEST_ARM_NEON_INSN mmlaq

#include "test-neon.h"
#include "../../../simde/arm/neon/mmlaq.h"

static int
test_simde_vmmlaq_s32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    int32_t buf[4];
    int8_t a[16];
    int8_t b[16];
    int32_t r[4];
  } test_vec[] = {
    { {  INT32_C( 121502931), -INT32_C( 890699054), -INT32_C(  95896074),  INT32_C( 723091284) },
      {  INT8_C(        64),  INT8_C(       101),  INT8_C(        95), -INT8_C(       112),
         INT8_C(        88),  INT8_C(        47), -INT8_C(        78), -INT8_C(        71),
         INT8_C(        17),  INT8_C(       106), -INT8_C(        47), -INT8_C(        99),
        -INT8_C(       108), -INT8_C(         8), -INT8_C(       120),  INT8_C(       124) },
      { -INT8_C(       127),  INT8_C(        58),  INT8_C(         2), -INT8_C(        74),
        -INT8_C(        17), -INT8_C(        35), -INT8_C(        41), -INT8_C(        97),
        -INT8_C(        73), -INT8_C(        83), -INT8_C(        42), -INT8_C(        60),
        -INT8_C(        99),  INT8_C(         4),  INT8_C(        16), -INT8_C(        84) },
      {  INT32_C( 121516083), -INT32_C( 890713187), -INT32_C(  95889845),  INT32_C( 723087483) } },
    { {  INT32_C(2010683425), -INT32_C( 396314720), -INT32_C(1398672425), -INT32_C(1179818951) },
      { -INT8_C(        81),  INT8_C(        92), -INT8_C(        94), -INT8_C(       126),
        -INT8_C(        92), -INT8_C(        38),  INT8_C(        48),  INT8_C(        10),
         INT8_C(        70),  INT8_C(        37), -INT8_C(        97), -INT8_C(         4),
         INT8_C(        22),  INT8_C(        13),  INT8_C(        15),  INT8_C(       107) },
      { -INT8_C(        90), -INT8_C(       117),  INT8_C(        81), -INT8_C(        86),
        -INT8_C(        15),  INT8_C(        15), -INT8_C(       121),  INT8_C(        12),
        -INT8_C(        60),  INT8_C(        57),  INT8_C(         5),  INT8_C(        74),
        -INT8_C(       125), -INT8_C(        32),  INT8_C(       121),  INT8_C(       123) },
      {  INT32_C(2010678295), -INT32_C( 396294656), -INT32_C(1398691233), -INT32_C(1179810013) } },
    { {  INT32_C(2059892279), -INT32_C( 783670737), -INT32_C( 989147536), -INT32_C(1192615628) },
      {  INT8_C(        41), -INT8_C(        17),  INT8_C(        32), -INT8_C(        95),
         INT8_C(        85), -INT8_C(        51),  INT8_C(        58),  INT8_C(        59),
         INT8_C(        49), -INT8_C(         9), -INT8_C(        36), -INT8_C(        90),
         INT8_C(         6),  INT8_C(        85), -INT8_C(       111), -INT8_C(        25) },
      { -INT8_C(        52), -INT8_C(        96),  INT8_C(       108),  INT8_C(        78),
         INT8_C(        43),  INT8_C(        25),  INT8_C(        79),  INT8_C(        55),
        -INT8_C(       112),  INT8_C(         0),  INT8_C(        14),  INT8_C(       123),
        -INT8_C(         2),  INT8_C(        26), -INT8_C(       108), -INT8_C(        65) },
      {  INT32_C(2059898032), -INT32_C( 783698161), -INT32_C( 989167889), -INT32_C(1192616879) } },
    { { -INT32_C( 429681119), -INT32_C(1933958892),  INT32_C(1007925534),  INT32_C( 634944359) },
      { -INT8_C(       105),  INT8_C(        66), -INT8_C(        87),  INT8_C(        94),
         INT8_C(        68),  INT8_C(       120), -INT8_C(       101), -INT8_C(        13),
         INT8_C(        52), -INT8_C(       123),  INT8_C(        13),  INT8_C(       122),
        -INT8_C(        98),  INT8_C(       110),  INT8_C(        10),  INT8_C(        59) },
      { -INT8_C(       127), -INT8_C(        49),  INT8_C(        92),  INT8_C(        81),
        -INT8_C(        56), -INT8_C(        55), -INT8_C(        82),  INT8_C(        60),
         INT8_C(        95), -INT8_C(         8), -INT8_C(       124),  INT8_C(        85),
         INT8_C(        73), -INT8_C(       103), -INT8_C(       107), -INT8_C(        54) },
      { -INT32_C( 429674314), -INT32_C(1933946504),  INT32_C(1007938193),  INT32_C( 634936301) } },
    { {  INT32_C(1275300771),  INT32_C( 832023400), -INT32_C( 388824074),  INT32_C( 904630208) },
      { -INT8_C(        69),  INT8_C(        33),  INT8_C(        41), -INT8_C(        14),
         INT8_C(        16),  INT8_C(        68), -INT8_C(        20),  INT8_C(       119),
        -INT8_C(        38), -INT8_C(        47),  INT8_C(        16), -INT8_C(        57),
         INT8_C(        13), -INT8_C(        33), -INT8_C(        82),  INT8_C(         9) },
      { -INT8_C(        17), -INT8_C(        91),  INT8_C(       124),  INT8_C(        42),
         INT8_C(        56), -INT8_C(       124), -INT8_C(        24),  INT8_C(        96),
         INT8_C(        78),  INT8_C(       110), -INT8_C(        21), -INT8_C(        98),
         INT8_C(        15),  INT8_C(       105),  INT8_C(        74),  INT8_C(        38) },
      {  INT32_C(1275307805),  INT32_C( 832032581), -INT32_C( 388811909),  INT32_C( 904618328) } },
    { { -INT32_C(1213504456),  INT32_C(2140022657), -INT32_C(  60484053),  INT32_C( 515033698) },
      { -INT8_C(        84), -INT8_C(        66), -INT8_C(        33),  INT8_C(         7),
         INT8_C(        15), -INT8_C(       126),  INT8_C(        23),  INT8_C(        73),
         INT8_C(        96),  INT8_C(        75),  INT8_C(        84), -INT8_C(       121),
        -INT8_C(        23), -INT8_C(        43),  INT8_C(        42), -INT8_C(        82) },
      { -INT8_C(        29),  INT8_C(       105), -INT8_C(       106),  INT8_C(        74),
         INT8_C(        59), -INT8_C(        29), -INT8_C(       101), -INT8_C(        89),
         INT8_C(        76), -INT8_C(        98),  INT8_C(        47), -INT8_C(        66),
        -INT8_C(        49), -INT8_C(       109), -INT8_C(        44),  INT8_C(        30) },
      { -INT32_C(1213509215),  INT32_C(2140034905), -INT32_C(  60493874),  INT32_C( 515047084) } },
    { { -INT32_C(1641610373), -INT32_C(1466453215), -INT32_C(  28364830), -INT32_C( 889593873) },
      { -INT8_C(        19),  INT8_C(        98), -INT8_C(        90),  INT8_C(        53),
        -INT8_C(       117), -INT8_C(        79),  INT8_C(       101),  INT8_C(       113),
         INT8_C(         3),  INT8_C(        14), -INT8_C(        11), -INT8_C(        60),
        -INT8_C(        69),  INT8_C(        85), -INT8_C(       125), -INT8_C(        66) },
      {  INT8_C(         2), -INT8_C(        76),  INT8_C(        17), -INT8_C(        47),
         INT8_C(        63),  INT8_C(       105),  INT8_C(        86),  INT8_C(        96),
        -INT8_C(       127),  INT8_C(        72), -INT8_C(        52),  INT8_C(        41),
        -INT8_C(       100), -INT8_C(        25), -INT8_C(       113), -INT8_C(        12) },
      { -INT32_C(1641618012), -INT32_C(1466435987), -INT32_C(  28375763), -INT32_C( 889575442) } },
    { {  INT32_C(1433638094), -INT32_C(1717027586), -INT32_C(1630567070), -INT32_C( 713664607) },
      {  INT8_C(       121),  INT8_C(        16),  INT8_C(        83),  INT8_C(        72),
        -INT8_C(       121), -INT8_C(        73),  INT8_C(       125),  INT8_C(       106),
         INT8_C(        36),  INT8_C(        85), -INT8_C(        62),  INT8_C(        64),
         INT8_C(        81), -INT8_C(        64),  INT8_C(        83),  INT8_C(         1) },
      {  INT8_C(        48), -INT8_C(        98),  INT8_C(       117),  INT8_C(        24),
         INT8_C(       105),  INT8_C(        16),  INT8_C(       125),  INT8_C(        56),
        -INT8_C(        19), -INT8_C(        61),  INT8_C(        49), -INT8_C(        99),
        -INT8_C(        66), -INT8_C(        58),  INT8_C(        81), -INT8_C(       119) },
      {  INT32_C(1433661461), -INT32_C(1717024191), -INT32_C(1630561478), -INT32_C( 713674880) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x4_t buf, r;
    simde_int8x16_t a, b;

    buf = simde_vld1q_s32(test_vec[i].buf);
    a = simde_vld1q_s8(test_vec[i].a);
    b = simde_vld1q_s8(test_vec[i].b);
    r = simde_vmmlaq_s32(buf, a, b);

    simde_test_arm_neon_assert_equal_i32x4(r, simde_vld1q_s32(test_vec[i].r));
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int32x4_t buf = simde_test_arm_neon_random_i32x4();
    simde_int8x16_t a = simde_test_arm_neon_random_i8x16();
    simde_int8x16_t b = simde_test_arm_neon_random_i8x16();
    simde_int32x4_t r = simde_vmmlaq_s32(buf, a, b);

    simde_test_arm_neon_write_i32x4(2, buf, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i8x16(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i8x16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vmmlaq_u32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    uint32_t buf[4];
    uint8_t a[16];
    uint8_t b[16];
    uint32_t r[4];
  } test_vec[] = {
    { {  UINT32_C(3573028203),  UINT32_C(2211440563),  UINT32_C(2074392575),  UINT32_C(3833030654) },
      {  UINT32_C(       112),  UINT32_C(        35),  UINT32_C(       195),  UINT32_C(       239),
         UINT32_C(       192),  UINT32_C(       160),  UINT32_C(       242),  UINT32_C(        43),
         UINT32_C(       242),  UINT32_C(       123),  UINT32_C(       212),  UINT32_C(       153),
         UINT32_C(        78),  UINT32_C(       123),  UINT32_C(       154),  UINT32_C(       157) },
      {  UINT32_C(       137),  UINT32_C(        21),  UINT32_C(       223),  UINT32_C(       185),
         UINT32_C(       252),  UINT32_C(       177),  UINT32_C(        68),  UINT32_C(       193),
         UINT32_C(       243),  UINT32_C(        21),  UINT32_C(        49),  UINT32_C(       192),
         UINT32_C(       146),  UINT32_C(       191),  UINT32_C(       253),  UINT32_C(       196) },
      {  UINT32_C(3573233441),  UINT32_C(2211652203),  UINT32_C(2074586093),  UINT32_C(3833236422) } },
    { {  UINT32_C(2859674552),  UINT32_C(1539856971),  UINT32_C(2699298204),  UINT32_C(2528880215) },
      {  UINT32_C(        23),  UINT32_C(       213),  UINT32_C(        27),  UINT32_C(       160),
         UINT32_C(       242),  UINT32_C(        71),  UINT32_C(        48),  UINT32_C(         8),
         UINT32_C(       111),  UINT32_C(        43),  UINT32_C(        99),  UINT32_C(       124),
         UINT32_C(       131),  UINT32_C(        76),  UINT32_C(        38),  UINT32_C(        83) },
      {  UINT32_C(       144),  UINT32_C(       223),  UINT32_C(       241),  UINT32_C(       116),
         UINT32_C(        43),  UINT32_C(       211),  UINT32_C(        99),  UINT32_C(       237),
         UINT32_C(       123),  UINT32_C(        24),  UINT32_C(       184),  UINT32_C(       106),
         UINT32_C(       139),  UINT32_C(       135),  UINT32_C(       186),  UINT32_C(        89) },
      {  UINT32_C(2859782465),  UINT32_C(1539939703),  UINT32_C(2699407122),  UINT32_C(2528969184) } },
    { {  UINT32_C(3931292241),  UINT32_C(4113871089),  UINT32_C(1798782129),  UINT32_C(1190871807) },
      {  UINT32_C(       199),  UINT32_C(        64),  UINT32_C(       171),  UINT32_C(       168),
         UINT32_C(         5),  UINT32_C(       188),  UINT32_C(       169),  UINT32_C(       246),
         UINT32_C(        68),  UINT32_C(       228),  UINT32_C(       111),  UINT32_C(        32),
         UINT32_C(       252),  UINT32_C(       196),  UINT32_C(        29),  UINT32_C(       196) },
      {  UINT32_C(       236),  UINT32_C(       138),  UINT32_C(       180),  UINT32_C(       188),
         UINT32_C(       109),  UINT32_C(       216),  UINT32_C(         8),  UINT32_C(       183),
         UINT32_C(       242),  UINT32_C(       243),  UINT32_C(       197),  UINT32_C(       145),
         UINT32_C(       234),  UINT32_C(       215),  UINT32_C(       153),  UINT32_C(       205) },
      {  UINT32_C(3931497924),  UINT32_C(4114110723),  UINT32_C(1798961541),  UINT32_C(1191115899) } },
    { {  UINT32_C(3341979120),  UINT32_C(2624308177),  UINT32_C(2403712828),  UINT32_C(1901110978) },
      {  UINT32_C(       136),  UINT32_C(         2),  UINT32_C(       240),  UINT32_C(       141),
         UINT32_C(        76),  UINT32_C(        70),  UINT32_C(        27),  UINT32_C(       144),
         UINT32_C(        41),  UINT32_C(        91),  UINT32_C(       155),  UINT32_C(        97),
         UINT32_C(        33),  UINT32_C(       229),  UINT32_C(       118),  UINT32_C(       229) },
      {  UINT32_C(       183),  UINT32_C(        97),  UINT32_C(       160),  UINT32_C(       207),
         UINT32_C(        91),  UINT32_C(       124),  UINT32_C(       157),  UINT32_C(       218),
         UINT32_C(       129),  UINT32_C(       255),  UINT32_C(       123),  UINT32_C(         5),
         UINT32_C(        98),  UINT32_C(       133),  UINT32_C(       122),  UINT32_C(       172) },
      {  UINT32_C(3342123016),  UINT32_C(2624401276),  UINT32_C(2403873884),  UINT32_C(1901246497) } },
    { {  UINT32_C(1715212178),  UINT32_C(1906210618),  UINT32_C(3294143216),  UINT32_C(2469394651) },
      {  UINT32_C(       104),  UINT32_C(        95),  UINT32_C(       148),  UINT32_C(       233),
         UINT32_C(       106),  UINT32_C(       197),  UINT32_C(       133),  UINT32_C(       135),
         UINT32_C(       107),  UINT32_C(       232),  UINT32_C(       111),  UINT32_C(         8),
         UINT32_C(       191),  UINT32_C(        72),  UINT32_C(        64),  UINT32_C(        41) },
      {  UINT32_C(       151),  UINT32_C(        34),  UINT32_C(        28),  UINT32_C(        19),
         UINT32_C(       224),  UINT32_C(       127),  UINT32_C(       230),  UINT32_C(       145),
         UINT32_C(       217),  UINT32_C(       116),  UINT32_C(       237),  UINT32_C(       157),
         UINT32_C(       245),  UINT32_C(       162),  UINT32_C(       143),  UINT32_C(       157) },
      {  UINT32_C(1715338611),  UINT32_C(1906413961),  UINT32_C(3294243114),  UINT32_C(2469546393) } },
    { {  UINT32_C(2314557007),  UINT32_C(1759686670),  UINT32_C(3008047373),  UINT32_C(4258641448) },
      {  UINT32_C(       219),  UINT32_C(        28),  UINT32_C(       184),  UINT32_C(       203),
         UINT32_C(        41),  UINT32_C(       239),  UINT32_C(         6),  UINT32_C(       150),
         UINT32_C(       175),  UINT32_C(       116),  UINT32_C(       108),  UINT32_C(       181),
         UINT32_C(       183),  UINT32_C(       129),  UINT32_C(        92),  UINT32_C(       197) },
      {  UINT32_C(       166),  UINT32_C(       128),  UINT32_C(        56),  UINT32_C(        93),
         UINT32_C(       194),  UINT32_C(        13),  UINT32_C(       157),  UINT32_C(        93),
         UINT32_C(       239),  UINT32_C(       101),  UINT32_C(        82),  UINT32_C(       173),
         UINT32_C(       241),  UINT32_C(       121),  UINT32_C(       161),  UINT32_C(       222) },
      {  UINT32_C(2314652081),  UINT32_C(1759865112),  UINT32_C(3008184096),  UINT32_C(4258853416) } },
    { {  UINT32_C(4108229792),  UINT32_C( 194604719),  UINT32_C(2198988510),  UINT32_C(3815486737) },
      {  UINT32_C(        68),  UINT32_C(       218),  UINT32_C(        25),  UINT32_C(       100),
         UINT32_C(       221),  UINT32_C(       183),  UINT32_C(        27),  UINT32_C(       230),
         UINT32_C(       154),  UINT32_C(       187),  UINT32_C(       149),  UINT32_C(        94),
         UINT32_C(        58),  UINT32_C(       115),  UINT32_C(       131),  UINT32_C(       184) },
      {  UINT32_C(       154),  UINT32_C(         5),  UINT32_C(       203),  UINT32_C(         7),
         UINT32_C(         9),  UINT32_C(        18),  UINT32_C(        37),  UINT32_C(       243),
         UINT32_C(       163),  UINT32_C(       240),  UINT32_C(       221),  UINT32_C(       253),
         UINT32_C(        77),  UINT32_C(        82),  UINT32_C(       179),  UINT32_C(       125) },
      {  UINT32_C(4108309301),  UINT32_C( 194764554),  UINT32_C(2199096217),  UINT32_C(3815673775) } },
    { {  UINT32_C(3605971860),  UINT32_C(3049958308),  UINT32_C(4195630357),  UINT32_C(2144920430) },
      {  UINT32_C(       218),  UINT32_C(       178),  UINT32_C(       118),  UINT32_C(       105),
         UINT32_C(       131),  UINT32_C(        64),  UINT32_C(        86),  UINT32_C(       156),
         UINT32_C(       139),  UINT32_C(       131),  UINT32_C(       161),  UINT32_C(        33),
         UINT32_C(       241),  UINT32_C(       239),  UINT32_C(        52),  UINT32_C(       140) },
      {  UINT32_C(        44),  UINT32_C(        58),  UINT32_C(       226),  UINT32_C(       228),
         UINT32_C(       164),  UINT32_C(       117),  UINT32_C(       224),  UINT32_C(       176),
         UINT32_C(        69),  UINT32_C(       183),  UINT32_C(       218),  UINT32_C(        99),
         UINT32_C(        50),  UINT32_C(        59),  UINT32_C(       181),  UINT32_C(        53) },
      {  UINT32_C(3606118076),  UINT32_C(3050076203),  UINT32_C(4195791756),  UINT32_C(2145035342) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint32x4_t buf, r;
    simde_uint8x16_t a, b;

    buf = simde_vld1q_u32(test_vec[i].buf);
    a = simde_vld1q_u8(test_vec[i].a);
    b = simde_vld1q_u8(test_vec[i].b);
    r = simde_vmmlaq_u32(buf, a, b);

    simde_test_arm_neon_assert_equal_u32x4(r, simde_vld1q_u32(test_vec[i].r));
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint32x4_t buf = simde_test_arm_neon_random_u32x4();
    simde_uint8x16_t a = simde_test_arm_neon_random_u8x16();
    simde_uint8x16_t b = simde_test_arm_neon_random_u8x16();
    simde_uint32x4_t r = simde_vmmlaq_u32(buf, a, b);

    simde_test_arm_neon_write_u32x4(2, buf, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u8x16(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u8x16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vusmmlaq_s32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    int32_t buf[4];
    uint8_t a[16];
    int8_t b[16];
    int32_t r[4];
  } test_vec[] = {
    { {  INT32_C(1792180012),  INT32_C(1148859016),  INT32_C( 208301555),  INT32_C(1161483939) },
      {  UINT8_C(       116),  UINT8_C(       154),  UINT8_C(        70),  UINT8_C(       246),
         UINT8_C(       131),  UINT8_C(         7),  UINT8_C(       126),  UINT8_C(       189),
         UINT8_C(       207),  UINT8_C(        98),  UINT8_C(       164),  UINT8_C(         4),
         UINT8_C(       125),  UINT8_C(       116),  UINT8_C(       222),  UINT8_C(       116) },
      {  INT8_C(         9),  INT8_C(        71),  INT8_C(       109), -INT8_C(        33),
         INT8_C(        46), -INT8_C(        26),  INT8_C(        54),  INT8_C(        82),
         INT8_C(        30),  INT8_C(        20), -INT8_C(        41), -INT8_C(        93),
         INT8_C(        66),  INT8_C(        60), -INT8_C(        94),  INT8_C(        59) },
      {  INT32_C(1792219648),  INT32_C(1148848201),  INT32_C( 208352354),  INT32_C(1161486199) } },
    { { -INT32_C(1524177270),  INT32_C( 924172100), -INT32_C(1008754356),  INT32_C( 923529599) },
      {  UINT8_C(        59),  UINT8_C(       232),  UINT8_C(        26),  UINT8_C(         2),
         UINT8_C(        16),  UINT8_C(        63),  UINT8_C(        62),  UINT8_C(       251),
         UINT8_C(        39),  UINT8_C(       117),  UINT8_C(         2),  UINT8_C(       234),
         UINT8_C(       164),  UINT8_C(       173),  UINT8_C(        88),  UINT8_C(       194) },
      { -INT8_C(        85),  INT8_C(        63), -INT8_C(       124),  INT8_C(        39),
         INT8_C(        56), -INT8_C(        97), -INT8_C(        87), -INT8_C(        33),
        -INT8_C(        35),  INT8_C(       102), -INT8_C(        86),  INT8_C(       109),
         INT8_C(       109),  INT8_C(        93), -INT8_C(        70),  INT8_C(        53) },
      { -INT32_C(1524189707),  INT32_C( 924208247), -INT32_C(1008763077),  INT32_C( 923603589) } },
    { { -INT32_C(1681029339),  INT32_C(1843819007), -INT32_C(1109910199), -INT32_C(1593911054) },
      {  UINT8_C(        43),  UINT8_C(        17),  UINT8_C(       234),  UINT8_C(       118),
         UINT8_C(        19),  UINT8_C(       119),  UINT8_C(        51),  UINT8_C(       193),
         UINT8_C(        93),  UINT8_C(       153),  UINT8_C(        54),  UINT8_C(       220),
         UINT8_C(       248),  UINT8_C(       131),  UINT8_C(       116),  UINT8_C(        90) },
      { -INT8_C(        78), -INT8_C(        65),  INT8_C(        30), -INT8_C(        27),
         INT8_C(        12), -INT8_C(       102), -INT8_C(        11),  INT8_C(       101),
        -INT8_C(        39), -INT8_C(        19), -INT8_C(        90), -INT8_C(        28),
         INT8_C(        25),  INT8_C(        32), -INT8_C(        91), -INT8_C(        92) },
      { -INT32_C(1681022942),  INT32_C(1843774529), -INT32_C(1109934290), -INT32_C(1593937052) } },
    { {  INT32_C( 528222871), -INT32_C(  61520001), -INT32_C(1221837601), -INT32_C( 787543656) },
      {  UINT8_C(       106),  UINT8_C(        69),  UINT8_C(       229),  UINT8_C(       149),
         UINT8_C(        91),  UINT8_C(        80),  UINT8_C(       150),  UINT8_C(       123),
         UINT8_C(       193),  UINT8_C(       130),  UINT8_C(        35),  UINT8_C(       233),
         UINT8_C(        20),  UINT8_C(        52),  UINT8_C(       197),  UINT8_C(       166) },
      {  INT8_C(       121), -INT8_C(        93),  INT8_C(        90),  INT8_C(       114),
         INT8_C(        33), -INT8_C(       121),  INT8_C(         6),  INT8_C(        59),
         INT8_C(       121),  INT8_C(         5), -INT8_C(       118),  INT8_C(        57),
        -INT8_C(        26),  INT8_C(        93), -INT8_C(       104),  INT8_C(       118) },
      {  INT32_C( 528268356), -INT32_C(  61521371), -INT32_C(1221791282), -INT32_C( 787507086) } },
    { { -INT32_C( 652248189), -INT32_C( 783769658),  INT32_C( 734319654), -INT32_C( 101709057) },
      {  UINT8_C(       249),  UINT8_C(         1),  UINT8_C(       207),  UINT8_C(        92),
         UINT8_C(        22),  UINT8_C(       233),  UINT8_C(       145),  UINT8_C(       231),
         UINT8_C(        13),  UINT8_C(       144),  UINT8_C(       229),  UINT8_C(       231),
         UINT8_C(       247),  UINT8_C(        27),  UINT8_C(        56),  UINT8_C(        82) },
      { -INT8_C(        42), -INT8_C(        99),  INT8_C(        82),  INT8_C(         5),
        -INT8_C(        24),  INT8_C(        61),  INT8_C(       124), -INT8_C(        11),
        -INT8_C(       109), -INT8_C(        26),  INT8_C(        17), -INT8_C(       128),
        -INT8_C(        21),  INT8_C(         2),  INT8_C(         0),  INT8_C(       109) },
      { -INT32_C( 652212188), -INT32_C( 783779899),  INT32_C( 734326546), -INT32_C( 101736088) } },
    { {  INT32_C(2085784010), -INT32_C(1427931760), -INT32_C( 369978285),  INT32_C( 497167080) },
      {  UINT8_C(         9),  UINT8_C(       192),  UINT8_C(       231),  UINT8_C(        69),
         UINT8_C(       125),  UINT8_C(        88),  UINT8_C(       183),  UINT8_C(        55),
         UINT8_C(       139),  UINT8_C(       143),  UINT8_C(        35),  UINT8_C(        75),
         UINT8_C(       197),  UINT8_C(       116),  UINT8_C(        71),  UINT8_C(       169) },
      { -INT8_C(        34), -INT8_C(        41),  INT8_C(        78),  INT8_C(        12),
         INT8_C(        39),  INT8_C(        24), -INT8_C(        77),  INT8_C(       101),
        -INT8_C(        23),  INT8_C(        95),  INT8_C(        54),  INT8_C(       108),
        -INT8_C(       102),  INT8_C(         4), -INT8_C(        16), -INT8_C(        66) },
      {  INT32_C(2085793129), -INT32_C(1427912757), -INT32_C( 369963175),  INT32_C( 497155538) } },
    { { -INT32_C(1792908550), -INT32_C(1481162987),  INT32_C(1046363483),  INT32_C(1628578091) },
      {  UINT8_C(       159),  UINT8_C(        29),  UINT8_C(        86),  UINT8_C(        19),
         UINT8_C(       249),  UINT8_C(       163),  UINT8_C(       250),  UINT8_C(        12),
         UINT8_C(       235),  UINT8_C(       189),  UINT8_C(       140),  UINT8_C(        97),
         UINT8_C(       117),  UINT8_C(        61),  UINT8_C(       255),  UINT8_C(       102) },
      { -INT8_C(         3), -INT8_C(       102), -INT8_C(         2),  INT8_C(        67),
         INT8_C(       105), -INT8_C(        34), -INT8_C(         5), -INT8_C(       122),
         INT8_C(        40), -INT8_C(        90), -INT8_C(        70), -INT8_C(       117),
         INT8_C(        76), -INT8_C(       121),  INT8_C(        97),  INT8_C(        13) },
      { -INT32_C(1792892995), -INT32_C(1481143873),  INT32_C(1046346211),  INT32_C(1628576904) } },
    { {  INT32_C(  86937068), -INT32_C(1590406855), -INT32_C( 509274194),  INT32_C( 511096590) },
      {  UINT8_C(       171),  UINT8_C(       185),  UINT8_C(        25),  UINT8_C(       215),
         UINT8_C(       150),  UINT8_C(        25),  UINT8_C(       124),  UINT8_C(       234),
         UINT8_C(        17),  UINT8_C(        42),  UINT8_C(       229),  UINT8_C(        71),
         UINT8_C(        96),  UINT8_C(       248),  UINT8_C(        55),  UINT8_C(       207) },
      { -INT8_C(        77), -INT8_C(        97), -INT8_C(       103), -INT8_C(        96),
         INT8_C(        80),  INT8_C(        89), -INT8_C(         7),  INT8_C(        30),
        -INT8_C(        29), -INT8_C(        26),  INT8_C(         7),  INT8_C(       117),
         INT8_C(       109),  INT8_C(        55), -INT8_C(        71), -INT8_C(        63) },
      {  INT32_C(  86903118), -INT32_C(1590397115), -INT32_C( 509274403),  INT32_C( 511112073) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x4_t buf, r;
    simde_uint8x16_t a;
    simde_int8x16_t b;

    buf = simde_vld1q_s32(test_vec[i].buf);
    a = simde_vld1q_u8(test_vec[i].a);
    b = simde_vld1q_s8(test_vec[i].b);
    r = simde_vusmmlaq_s32(buf, a, b);

    simde_test_arm_neon_assert_equal_i32x4(r, simde_vld1q_s32(test_vec[i].r));
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int32x4_t buf = simde_test_arm_neon_random_i32x4();
    simde_uint8x16_t a = simde_test_arm_neon_random_u8x16();
    simde_int8x16_t b = simde_test_arm_neon_random_i8x16();
    simde_int32x4_t r = simde_vusmmlaq_s32(buf, a, b);

    simde_test_arm_neon_write_i32x4(2, buf, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u8x16(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i8x16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vbfmmlaq_f32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    simde_float32_t buf[4];
    simde_bfloat16_t a[8];
    simde_bfloat16_t b[8];
    simde_float32_t r[4];
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(  -663.97), SIMDE_FLOAT32_C(   103.85), SIMDE_FLOAT32_C(   383.97), SIMDE_FLOAT32_C(  -387.23) },
      { SIMDE_BFLOAT16_VALUE(   -15.12), SIMDE_BFLOAT16_VALUE(    89.00), SIMDE_BFLOAT16_VALUE(    86.00), SIMDE_BFLOAT16_VALUE(    35.00),
        SIMDE_BFLOAT16_VALUE(   -28.50), SIMDE_BFLOAT16_VALUE(    42.75), SIMDE_BFLOAT16_VALUE(   -44.00), SIMDE_BFLOAT16_VALUE(    52.75) },
      { SIMDE_BFLOAT16_VALUE(    95.50), SIMDE_BFLOAT16_VALUE(   -28.00), SIMDE_BFLOAT16_VALUE(    73.00), SIMDE_BFLOAT16_VALUE(    59.50),
        SIMDE_BFLOAT16_VALUE(    76.50), SIMDE_BFLOAT16_VALUE(    -7.16), SIMDE_BFLOAT16_VALUE(   -58.00), SIMDE_BFLOAT16_VALUE(   -14.06) },
      { SIMDE_FLOAT32_C(  3760.09), SIMDE_FLOAT32_C( -7170.31), SIMDE_FLOAT32_C( -3608.16), SIMDE_FLOAT32_C( -1063.21) } },
    { { SIMDE_FLOAT32_C(  -688.33), SIMDE_FLOAT32_C(  -782.95), SIMDE_FLOAT32_C(  -613.46), SIMDE_FLOAT32_C(   710.46) },
      { SIMDE_BFLOAT16_VALUE(    92.00), SIMDE_BFLOAT16_VALUE(    69.00), SIMDE_BFLOAT16_VALUE(   -26.75), SIMDE_BFLOAT16_VALUE(   -40.50),
        SIMDE_BFLOAT16_VALUE(   -99.50), SIMDE_BFLOAT16_VALUE(   -83.50), SIMDE_BFLOAT16_VALUE(    19.88), SIMDE_BFLOAT16_VALUE(   -66.00) },
      { SIMDE_BFLOAT16_VALUE(    26.88), SIMDE_BFLOAT16_VALUE(   -41.75), SIMDE_BFLOAT16_VALUE(    -4.53), SIMDE_BFLOAT16_VALUE(   -88.00),
        SIMDE_BFLOAT16_VALUE(   -52.50), SIMDE_BFLOAT16_VALUE(   -18.50), SIMDE_BFLOAT16_VALUE(    47.00), SIMDE_BFLOAT16_VALUE(    18.88) },
      { SIMDE_FLOAT32_C(  2588.63), SIMDE_FLOAT32_C( -8911.14), SIMDE_FLOAT32_C(  5916.54), SIMDE_FLOAT32_C(  7167.33) } },
    { { SIMDE_FLOAT32_C(  -757.49), SIMDE_FLOAT32_C(  -970.43), SIMDE_FLOAT32_C(  -283.88), SIMDE_FLOAT32_C(  -804.46) },
      { SIMDE_BFLOAT16_VALUE(   -25.12), SIMDE_BFLOAT16_VALUE(   -55.50), SIMDE_BFLOAT16_VALUE(    79.00), SIMDE_BFLOAT16_VALUE(   -48.75),
        SIMDE_BFLOAT16_VALUE(    37.50), SIMDE_BFLOAT16_VALUE(   -79.00), SIMDE_BFLOAT16_VALUE(    37.25), SIMDE_BFLOAT16_VALUE(    68.50) },
      { SIMDE_BFLOAT16_VALUE(   -57.25), SIMDE_BFLOAT16_VALUE(    76.00), SIMDE_BFLOAT16_VALUE(    39.75), SIMDE_BFLOAT16_VALUE(   -65.50),
        SIMDE_BFLOAT16_VALUE(    45.25), SIMDE_BFLOAT16_VALUE(   -87.00), SIMDE_BFLOAT16_VALUE(    -5.84), SIMDE_BFLOAT16_VALUE(    45.75) },
      { SIMDE_FLOAT32_C(  2796.29), SIMDE_FLOAT32_C(    29.20), SIMDE_FLOAT32_C(-11440.82), SIMDE_FLOAT32_C( 10681.61) } },
    { { SIMDE_FLOAT32_C(  -705.94), SIMDE_FLOAT32_C(  -859.67), SIMDE_FLOAT32_C(   799.23), SIMDE_FLOAT32_C(   563.15) },
      { SIMDE_BFLOAT16_VALUE(   -27.75), SIMDE_BFLOAT16_VALUE(   -24.62), SIMDE_BFLOAT16_VALUE(    68.00), SIMDE_BFLOAT16_VALUE(    19.75),
        SIMDE_BFLOAT16_VALUE(    56.75), SIMDE_BFLOAT16_VALUE(    15.06), SIMDE_BFLOAT16_VALUE(   -61.50), SIMDE_BFLOAT16_VALUE(    81.00) },
      { SIMDE_BFLOAT16_VALUE(    18.00), SIMDE_BFLOAT16_VALUE(    10.19), SIMDE_BFLOAT16_VALUE(   -99.50), SIMDE_BFLOAT16_VALUE(    93.00),
        SIMDE_BFLOAT16_VALUE(    54.75), SIMDE_BFLOAT16_VALUE(    79.50), SIMDE_BFLOAT16_VALUE(   -55.75), SIMDE_BFLOAT16_VALUE(    -7.81) },
      { SIMDE_FLOAT32_C( -6385.56), SIMDE_FLOAT32_C( -8281.97), SIMDE_FLOAT32_C( 15626.43), SIMDE_FLOAT32_C(  7663.49) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x4_t buf = simde_vld1q_f32(test_vec[i].buf);
    simde_bfloat16x8_t a = simde_vld1q_bf16(test_vec[i].a);
    simde_bfloat16x8_t b = simde_vld1q_bf16(test_vec[i].b);
    simde_float32x4_t r = simde_vbfmmlaq_f32(buf, a, b);

    simde_test_arm_neon_assert_equal_f32x4(r, simde_vld1q_f32(test_vec[i].r), 1);
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float32x4_t buf = simde_test_arm_neon_random_f32x4(-1000.0f, 1000.0f);
    simde_bfloat16x8_t a = simde_test_arm_neon_random_bf16x8(SIMDE_BFLOAT16_VALUE(-100.0), SIMDE_BFLOAT16_VALUE(100.0));
    simde_bfloat16x8_t b = simde_test_arm_neon_random_bf16x8(SIMDE_BFLOAT16_VALUE(-100.0), SIMDE_BFLOAT16_VALUE(100.0));
    simde_float32x4_t r = simde_vbfmmlaq_f32(buf, a, b);

    simde_test_arm_neon_write_f32x4(2, buf, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_bf16x8(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_bf16x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(vmmlaq_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vmmlaq_u32)
SIMDE_TEST_FUNC_LIST_ENTRY(vusmmlaq_s32)

SIMDE_TEST_FUNC_LIST_ENTRY(vbfmmlaq_f32)
SIMDE_TEST_FUNC_LIST_END

#include "test-neon-footer.h"
