#define SIMDE_TEST_ARM_NEON_INSN addl_high

#include "test-neon.h"
#include <simde/arm/neon/addl_high.h>

static int
test_simde_vaddl_high_s8 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    int8_t a[16];
    int8_t b[16];
    int16_t r[8];
  } test_vec[] = {
    { {  INT8_C(  28),  INT8_C(  57),  INT8_C( 116), -INT8_C(  26), -INT8_C(  59),      INT8_MIN,  INT8_C(  27),  INT8_C(  25),
         INT8_C( 118), -INT8_C(  21), -INT8_C( 106),  INT8_C(  96),  INT8_C(  91), -INT8_C(  73), -INT8_C(  21), -INT8_C(  93) },
      {  INT8_C(  19), -INT8_C(  18), -INT8_C(  14),  INT8_C(  50), -INT8_C(  30),  INT8_C( 108), -INT8_C(  16),  INT8_C(   6),
        -INT8_C( 106),  INT8_C(  51), -INT8_C(  85),  INT8_C(  60),  INT8_C(  49), -INT8_C(  12), -INT8_C(  61),  INT8_C(  78) },
      {  INT16_C(    12),  INT16_C(    30), -INT16_C(   191),  INT16_C(   156),  INT16_C(   140), -INT16_C(    85), -INT16_C(    82), -INT16_C(    15) } },
    { {  INT8_C(  46),  INT8_C(  55),  INT8_C(  52), -INT8_C(  13), -INT8_C(  72),  INT8_C(  79),  INT8_C(  13),  INT8_C(  46),
         INT8_C(  59), -INT8_C(  93), -INT8_C( 114), -INT8_C( 106),  INT8_C(  91),  INT8_C( 122),  INT8_C(  57),  INT8_C( 110) },
      {  INT8_C( 104),  INT8_C(  44), -INT8_C(  96),  INT8_C(  74), -INT8_C( 104), -INT8_C( 111),  INT8_C(  80),  INT8_C(  47),
        -INT8_C(  60), -INT8_C(   5),  INT8_C( 107), -INT8_C(  10), -INT8_C(  16),  INT8_C(  46),  INT8_C(  68),  INT8_C(  30) },
      { -INT16_C(     1), -INT16_C(    98), -INT16_C(     7), -INT16_C(   116),  INT16_C(    75),  INT16_C(   168),  INT16_C(   125),  INT16_C(   140) } },
    { {  INT8_C( 102),  INT8_C( 120),  INT8_C(  17),  INT8_C(  30), -INT8_C(  57),  INT8_C(  30),  INT8_C(  76),  INT8_C(   2),
        -INT8_C(  62), -INT8_C(  37), -INT8_C( 104),  INT8_C(  29),  INT8_C(  85), -INT8_C(  46), -INT8_C( 117), -INT8_C(  67) },
      { -INT8_C(   2),  INT8_C(  44),  INT8_C(   7), -INT8_C( 106), -INT8_C(  67),  INT8_C(  87), -INT8_C(  59), -INT8_C( 127),
         INT8_C(  83),  INT8_C(  49),  INT8_C( 119),  INT8_C(  67),  INT8_C(  95), -INT8_C(  69),  INT8_C(  97), -INT8_C(  59) },
      {  INT16_C(    21),  INT16_C(    12),  INT16_C(    15),  INT16_C(    96),  INT16_C(   180), -INT16_C(   115), -INT16_C(    20), -INT16_C(   126) } },
    { {  INT8_C(  51),  INT8_C( 114), -INT8_C(  29), -INT8_C(   5), -INT8_C( 111),  INT8_C(  48), -INT8_C(   3),  INT8_C(  83),
         INT8_C(  11), -INT8_C( 106),  INT8_C( 112),  INT8_C(  96),  INT8_C( 104), -INT8_C(   5),  INT8_C(  29),  INT8_C( 102) },
      {  INT8_C(  39),  INT8_C(  36), -INT8_C(   4), -INT8_C(  28),  INT8_C( 123), -INT8_C(  62),  INT8_C( 102), -INT8_C(  50),
        -INT8_C(  13), -INT8_C(  35),  INT8_C(  17),  INT8_C(  82), -INT8_C( 103),  INT8_C( 114),  INT8_C(  24), -INT8_C(  52) },
      { -INT16_C(     2), -INT16_C(   141),  INT16_C(   129),  INT16_C(   178),  INT16_C(     1),  INT16_C(   109),  INT16_C(    53),  INT16_C(    50) } },
    { { -INT8_C(  27), -INT8_C(   5), -INT8_C(  57),  INT8_C( 118),  INT8_C(  43), -INT8_C(  59), -INT8_C(  55),  INT8_C(  54),
         INT8_C(  91),  INT8_C(  57), -INT8_C( 106), -INT8_C(  61),  INT8_C(  52), -INT8_C(  77),  INT8_C(  41),  INT8_C(  92) },
      { -INT8_C(  41),  INT8_C(  37),  INT8_C(  64),  INT8_C(  83), -INT8_C(  25), -INT8_C(  90),  INT8_C(  33), -INT8_C(  38),
        -INT8_C( 124),  INT8_C(  51),  INT8_C(  45),  INT8_C(  29), -INT8_C(  91),  INT8_C(  69), -INT8_C(  23), -INT8_C( 118) },
      { -INT16_C(    33),  INT16_C(   108), -INT16_C(    61), -INT16_C(    32), -INT16_C(    39), -INT16_C(     8),  INT16_C(    18), -INT16_C(    26) } },
    { {  INT8_C(  64), -INT8_C(  79),  INT8_C(   0),  INT8_C( 108),  INT8_C( 118), -INT8_C(  55), -INT8_C(  94), -INT8_C(  47),
         INT8_C(   2),  INT8_C(  57), -INT8_C( 108),  INT8_C(  55), -INT8_C(  20), -INT8_C(  67), -INT8_C( 109), -INT8_C(  60) },
      { -INT8_C(  30), -INT8_C(  45),  INT8_C(  23), -INT8_C(  54),  INT8_C( 122),  INT8_C(  56), -INT8_C(  92), -INT8_C(   2),
         INT8_C( 107), -INT8_C(  47),  INT8_C(  27),  INT8_C(  17),  INT8_C(  22),  INT8_C(   4), -INT8_C( 101),  INT8_C(  87) },
      {  INT16_C(   109),  INT16_C(    10), -INT16_C(    81),  INT16_C(    72),  INT16_C(     2), -INT16_C(    63), -INT16_C(   210),  INT16_C(    27) } },
    { { -INT8_C(  75), -INT8_C( 100), -INT8_C(  61),  INT8_C(  43),  INT8_C( 101),  INT8_C( 101), -INT8_C(   4),  INT8_C( 104),
        -INT8_C(  98), -INT8_C( 112), -INT8_C(  97), -INT8_C( 117),  INT8_C(  77),  INT8_C(  50),  INT8_C(  79),  INT8_C(  48) },
      {  INT8_C(   5),  INT8_C( 102), -INT8_C(   6),      INT8_MAX, -INT8_C(  98), -INT8_C(  98),  INT8_C( 125),  INT8_C(  10),
         INT8_C( 112), -INT8_C( 104),  INT8_C(  27), -INT8_C( 122), -INT8_C(  99), -INT8_C(  74), -INT8_C(  35),  INT8_C(  82) },
      {  INT16_C(    14), -INT16_C(   216), -INT16_C(    70), -INT16_C(   239), -INT16_C(    22), -INT16_C(    24),  INT16_C(    44),  INT16_C(   130) } },
    { {  INT8_C(  82), -INT8_C(  96),  INT8_C( 126), -INT8_C(  72),  INT8_C(   6),  INT8_C( 122),  INT8_C(  32), -INT8_C(  92),
         INT8_C(  11), -INT8_C(  65),  INT8_C(  47),  INT8_C(  88), -INT8_C(  15),  INT8_C( 126), -INT8_C( 120), -INT8_C(  10) },
      { -INT8_C(  28), -INT8_C( 126),  INT8_C( 118), -INT8_C( 125),  INT8_C(  33), -INT8_C(  13), -INT8_C( 115), -INT8_C( 111),
        -INT8_C( 116), -INT8_C(  88),  INT8_C(  23),  INT8_C(  41),  INT8_C(  94), -INT8_C(  11),  INT8_C( 123), -INT8_C(  79) },
      { -INT16_C(   105), -INT16_C(   153),  INT16_C(    70),  INT16_C(   129),  INT16_C(    79),  INT16_C(   115),  INT16_C(     3), -INT16_C(    89) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int8x16_t a = simde_vld1q_s8(test_vec[i].a);
    simde_int8x16_t b = simde_vld1q_s8(test_vec[i].b);
    simde_int16x8_t r = simde_vaddl_high_s8(a, b);

    simde_test_arm_neon_assert_equal_i16x8(r, simde_vld1q_s16(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vaddl_high_s16 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    int16_t a[8];
    int16_t b[8];
    int32_t r[4];
  } test_vec[] = {
    { {  INT16_C(  7144), -INT16_C( 16648),  INT16_C( 24563),  INT16_C( 13384),  INT16_C( 30230),  INT16_C(  9142),  INT16_C( 26163),  INT16_C( 11375) },
      { -INT16_C( 20538), -INT16_C(  4117),  INT16_C(  6207),  INT16_C( 12335), -INT16_C( 11259),  INT16_C( 30845),  INT16_C( 23245), -INT16_C( 19018) },
      {  INT32_C(       18971),  INT32_C(       39987),  INT32_C(       49408), -INT32_C(        7643) } },
    { { -INT16_C( 20618),  INT16_C( 26995), -INT16_C( 17394),  INT16_C(  9629),  INT16_C( 21298),  INT16_C( 25928), -INT16_C( 18502), -INT16_C( 32623) },
      {  INT16_C( 31847), -INT16_C( 22929), -INT16_C( 24939), -INT16_C( 25898),  INT16_C( 21618),  INT16_C( 16146), -INT16_C( 13906),  INT16_C(  9461) },
      {  INT32_C(       42916),  INT32_C(       42074), -INT32_C(       32408), -INT32_C(       23162) } },
    { {  INT16_C( 26744), -INT16_C( 31090),  INT16_C( 11044),  INT16_C( 22187), -INT16_C(  2945),  INT16_C( 14779),  INT16_C( 19883),  INT16_C(  4793) },
      {  INT16_C( 10441),  INT16_C( 24249), -INT16_C( 28730),  INT16_C( 14584),  INT16_C(  3043), -INT16_C( 28040),  INT16_C( 28116),  INT16_C( 19638) },
      {  INT32_C(          98), -INT32_C(       13261),  INT32_C(       47999),  INT32_C(       24431) } },
    { {  INT16_C( 17621), -INT16_C(  1326),  INT16_C( 32368), -INT16_C(  4272),  INT16_C(  3186),  INT16_C(  7464), -INT16_C(  7847),  INT16_C(  8752) },
      { -INT16_C(  5879), -INT16_C( 12415),  INT16_C( 31096),  INT16_C( 23559),  INT16_C( 32644),  INT16_C( 22766), -INT16_C( 23316), -INT16_C( 15708) },
      {  INT32_C(       35830),  INT32_C(       30230), -INT32_C(       31163), -INT32_C(        6956) } },
    { {  INT16_C( 30697),  INT16_C( 22972),  INT16_C(  3317),  INT16_C( 26440),  INT16_C( 28696),  INT16_C( 29060), -INT16_C( 19375),  INT16_C( 23188) },
      {  INT16_C(  5533),  INT16_C(  5673),  INT16_C( 12430),  INT16_C(  4978),  INT16_C( 24752), -INT16_C( 25493),  INT16_C(  4100), -INT16_C(  4770) },
      {  INT32_C(       53448),  INT32_C(        3567), -INT32_C(       15275),  INT32_C(       18418) } },
    { {  INT16_C(  6791),  INT16_C( 31814), -INT16_C( 29145),  INT16_C( 16355),  INT16_C( 26622),  INT16_C( 20401),  INT16_C( 17692), -INT16_C( 18007) },
      { -INT16_C( 11686), -INT16_C(  5937),  INT16_C( 16643), -INT16_C( 19461),  INT16_C( 26529), -INT16_C( 22961), -INT16_C( 20873), -INT16_C(   365) },
      {  INT32_C(       53151), -INT32_C(        2560), -INT32_C(        3181), -INT32_C(       18372) } },
    { { -INT16_C(  9528), -INT16_C(  4230),  INT16_C( 23912),  INT16_C( 26415), -INT16_C(  7996), -INT16_C(  8010),  INT16_C( 24613),  INT16_C( 32666) },
      {  INT16_C( 26930),  INT16_C( 13671),  INT16_C( 25515),  INT16_C( 19688),  INT16_C( 14538),  INT16_C( 16882), -INT16_C( 31002), -INT16_C( 20929) },
      {  INT32_C(        6542),  INT32_C(        8872), -INT32_C(        6389),  INT32_C(       11737) } },
    { { -INT16_C( 18080), -INT16_C( 14178), -INT16_C( 13034), -INT16_C(  9681), -INT16_C(  6483), -INT16_C( 11589),  INT16_C( 21830),  INT16_C( 30801) },
      { -INT16_C( 18242),  INT16_C( 27054), -INT16_C( 27109), -INT16_C(  6730), -INT16_C( 22322), -INT16_C( 19418),  INT16_C( 25902), -INT16_C( 29085) },
      { -INT32_C(       28805), -INT32_C(       31007),  INT32_C(       47732),  INT32_C(        1716) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x8_t a = simde_vld1q_s16(test_vec[i].a);
    simde_int16x8_t b = simde_vld1q_s16(test_vec[i].b);
    simde_int32x4_t r = simde_vaddl_high_s16(a, b);

    simde_test_arm_neon_assert_equal_i32x4(r, simde_vld1q_s32(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vaddl_high_s32 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    int32_t a[4];
    int32_t b[4];
    int64_t r[2];
  } test_vec[] = {
    { {  INT32_C(  1740465003), -INT32_C(  1432883366), -INT32_C(  1818865170),  INT32_C(   652150671) },
      {  INT32_C(   199936655), -INT32_C(  1706197280), -INT32_C(  1657142648), -INT32_C(   304589439) },
      { -INT64_C(          3476007818),  INT64_C(           347561232) } },
    { {  INT32_C(   324310456),  INT32_C(  1941826692), -INT32_C(   872000707), -INT32_C(   369957286) },
      { -INT32_C(  1863000912), -INT32_C(   483770022), -INT32_C(   981441469),  INT32_C(  1924291001) },
      { -INT64_C(          1853442176),  INT64_C(          1554333715) } },
    { {  INT32_C(  1938097902),  INT32_C(   803619570), -INT32_C(   268702571), -INT32_C(  2099712302) },
      {  INT32_C(   621989066),  INT32_C(  1342716941),  INT32_C(  1511360673), -INT32_C(   791885855) },
      {  INT64_C(          1242658102), -INT64_C(          2891598157) } },
    { { -INT32_C(  1069329970),  INT32_C(   686827923), -INT32_C(   401085675), -INT32_C(  1536495655) },
      { -INT32_C(   926319173),  INT32_C(  1511641529),  INT32_C(  1001729625), -INT32_C(  1005878794) },
      {  INT64_C(           600643950), -INT64_C(          2542374449) } },
    { {  INT32_C(  1719946963), -INT32_C(  1936755593),  INT32_C(   963946080),  INT32_C(  1373495190) },
      {  INT32_C(   354068060), -INT32_C(   781175945),  INT32_C(  1460413793),  INT32_C(  2031818662) },
      {  INT64_C(          2424359873),  INT64_C(          3405313852) } },
    { { -INT32_C(   589258651),  INT32_C(  1953001236), -INT32_C(  1414603499),  INT32_C(   419269564) },
      { -INT32_C(  1456662734), -INT32_C(  1418027702),  INT32_C(  1761838786),  INT32_C(    48373405) },
      {  INT64_C(           347235287),  INT64_C(           467642969) } },
    { { -INT32_C(   740375874),  INT32_C(  1195853617), -INT32_C(   520948444), -INT32_C(  1275531391) },
      {  INT32_C(  1348216070), -INT32_C(  2047027261), -INT32_C(    68223139), -INT32_C(   587345635) },
      { -INT64_C(           589171583), -INT64_C(          1862877026) } },
    { { -INT32_C(   978330477),  INT32_C(  1192031779),  INT32_C(  1831337708), -INT32_C(   199221266) },
      {  INT32_C(   121994308), -INT32_C(  1316142765),  INT32_C(  1571584832), -INT32_C(   533092020) },
      {  INT64_C(          3402922540), -INT64_C(           732313286) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x4_t a = simde_vld1q_s32(test_vec[i].a);
    simde_int32x4_t b = simde_vld1q_s32(test_vec[i].b);
    simde_int64x2_t r = simde_vaddl_high_s32(a, b);

    simde_test_arm_neon_assert_equal_i64x2(r, simde_vld1q_s64(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vaddl_high_u8 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    uint8_t a[16];
    uint8_t b[16];
    uint16_t r[8];
  } test_vec[] = {
    { { UINT8_C( 93), UINT8_C(  0), UINT8_C( 39), UINT8_C( 27), UINT8_C(115), UINT8_C(216), UINT8_C( 74), UINT8_C(133),
        UINT8_C( 58), UINT8_C(177), UINT8_C(  0), UINT8_C( 47), UINT8_C(214), UINT8_C(147), UINT8_C(155), UINT8_C(151) },
      { UINT8_C(136), UINT8_C(233), UINT8_C( 56), UINT8_C(198), UINT8_C(203), UINT8_C(  2), UINT8_C(239), UINT8_C( 15),
        UINT8_C(147), UINT8_C(119), UINT8_C(111), UINT8_C( 53), UINT8_C( 37), UINT8_C(230), UINT8_C( 19), UINT8_C(130) },
      { UINT16_C(  205), UINT16_C(  296), UINT16_C(  111), UINT16_C(  100), UINT16_C(  251), UINT16_C(  377), UINT16_C(  174), UINT16_C(  281) } },
    { { UINT8_C(231), UINT8_C( 58), UINT8_C(158), UINT8_C( 90), UINT8_C( 18), UINT8_C(232), UINT8_C(223), UINT8_C( 77),
        UINT8_C(153), UINT8_C(223), UINT8_C(124), UINT8_C(112), UINT8_C(114), UINT8_C( 23), UINT8_C(  7), UINT8_C(251) },
      { UINT8_C(  0), UINT8_C( 64), UINT8_C(193), UINT8_C(204), UINT8_C( 66), UINT8_C(176), UINT8_C(219), UINT8_C(214),
        UINT8_C( 39), UINT8_C( 75), UINT8_C( 11), UINT8_C( 77), UINT8_C( 49), UINT8_C( 30), UINT8_C(207), UINT8_C( 24) },
      { UINT16_C(  192), UINT16_C(  298), UINT16_C(  135), UINT16_C(  189), UINT16_C(  163), UINT16_C(   53), UINT16_C(  214), UINT16_C(  275) } },
    { { UINT8_C( 89), UINT8_C(109), UINT8_C(114), UINT8_C(107), UINT8_C( 86), UINT8_C( 82), UINT8_C(184), UINT8_C(239),
        UINT8_C( 49), UINT8_C( 52), UINT8_C( 95), UINT8_C(164), UINT8_C( 76), UINT8_C(103), UINT8_C(159), UINT8_C( 76) },
      { UINT8_C(167), UINT8_C( 96), UINT8_C( 24), UINT8_C(233), UINT8_C( 16), UINT8_C(244), UINT8_C(191), UINT8_C( 55),
        UINT8_C( 63), UINT8_C(203), UINT8_C(132), UINT8_C(112), UINT8_C(233), UINT8_C( 84), UINT8_C(137), UINT8_C( 66) },
      { UINT16_C(  112), UINT16_C(  255), UINT16_C(  227), UINT16_C(  276), UINT16_C(  309), UINT16_C(  187), UINT16_C(  296), UINT16_C(  142) } },
    { { UINT8_C(193), UINT8_C(251), UINT8_C(174), UINT8_C( 23), UINT8_C( 77), UINT8_C(102), UINT8_C(  7), UINT8_C(127),
        UINT8_C(155), UINT8_C(102), UINT8_C( 35), UINT8_C(231), UINT8_C(205), UINT8_C(194), UINT8_C( 51), UINT8_C(116) },
      { UINT8_C( 34), UINT8_C( 76), UINT8_C( 94), UINT8_C( 50), UINT8_C( 64), UINT8_C( 29), UINT8_C(105), UINT8_C(127),
        UINT8_C(232), UINT8_C(238), UINT8_C(239), UINT8_C(210), UINT8_C( 66), UINT8_C(120), UINT8_C( 20), UINT8_C(  3) },
      { UINT16_C(  387), UINT16_C(  340), UINT16_C(  274), UINT16_C(  441), UINT16_C(  271), UINT16_C(  314), UINT16_C(   71), UINT16_C(  119) } },
    { { UINT8_C(116), UINT8_C(194), UINT8_C( 27), UINT8_C(193), UINT8_C( 41), UINT8_C( 34), UINT8_C( 64), UINT8_C(196),
        UINT8_C(136), UINT8_C( 99), UINT8_C(171), UINT8_C( 86), UINT8_C( 37), UINT8_C(222), UINT8_C(202), UINT8_C( 71) },
      { UINT8_C( 42), UINT8_C( 40), UINT8_C(121), UINT8_C(106), UINT8_C( 70), UINT8_C(227), UINT8_C(233), UINT8_C( 46),
        UINT8_C(209), UINT8_C(217), UINT8_C(  0), UINT8_C( 19), UINT8_C( 81), UINT8_C( 21), UINT8_C( 22), UINT8_C(197) },
      { UINT16_C(  345), UINT16_C(  316), UINT16_C(  171), UINT16_C(  105), UINT16_C(  118), UINT16_C(  243), UINT16_C(  224), UINT16_C(  268) } },
    { { UINT8_C(215), UINT8_C( 49), UINT8_C(135), UINT8_C(  0), UINT8_C( 83), UINT8_C(199), UINT8_C(196), UINT8_C(220),
        UINT8_C( 43), UINT8_C(111), UINT8_C( 50), UINT8_C( 80), UINT8_C( 78), UINT8_C(252), UINT8_C(152), UINT8_C(120) },
      { UINT8_C( 37), UINT8_C( 17), UINT8_C(227), UINT8_C(107), UINT8_C(244), UINT8_C(204), UINT8_C(153), UINT8_C(197),
        UINT8_C(165), UINT8_C(154), UINT8_C(216), UINT8_C(247), UINT8_C(175), UINT8_C(239), UINT8_C(188), UINT8_C(134) },
      { UINT16_C(  208), UINT16_C(  265), UINT16_C(  266), UINT16_C(  327), UINT16_C(  253), UINT16_C(  491), UINT16_C(  340), UINT16_C(  254) } },
    { { UINT8_C( 32), UINT8_C( 67), UINT8_C(135), UINT8_C(116), UINT8_C( 11), UINT8_C( 75), UINT8_C( 80), UINT8_C( 54),
        UINT8_C(187), UINT8_C(130), UINT8_C(134), UINT8_C(  9), UINT8_C(126), UINT8_C( 30), UINT8_C(129), UINT8_C(163) },
      { UINT8_C( 48), UINT8_C(100), UINT8_C( 14), UINT8_C( 36), UINT8_C( 49), UINT8_C(168), UINT8_C(234), UINT8_C(214),
        UINT8_C( 66), UINT8_C(194), UINT8_C(205), UINT8_C(241), UINT8_C(177), UINT8_C(138), UINT8_C(119), UINT8_C(210) },
      { UINT16_C(  253), UINT16_C(  324), UINT16_C(  339), UINT16_C(  250), UINT16_C(  303), UINT16_C(  168), UINT16_C(  248), UINT16_C(  373) } },
    { { UINT8_C(205), UINT8_C(254), UINT8_C( 70), UINT8_C(216), UINT8_C( 74), UINT8_C(150), UINT8_C( 14), UINT8_C(  5),
        UINT8_C( 24), UINT8_C(149), UINT8_C( 14), UINT8_C(150), UINT8_C(179), UINT8_C(143), UINT8_C( 58), UINT8_C(227) },
      { UINT8_C(244), UINT8_C( 72), UINT8_C(  8), UINT8_C( 37), UINT8_C(240), UINT8_C(242), UINT8_C(251), UINT8_C( 50),
        UINT8_C(180), UINT8_C(201), UINT8_C( 35), UINT8_C(102), UINT8_C( 83), UINT8_C(155), UINT8_C( 56), UINT8_C( 32) },
      { UINT16_C(  204), UINT16_C(  350), UINT16_C(   49), UINT16_C(  252), UINT16_C(  262), UINT16_C(  298), UINT16_C(  114), UINT16_C(  259) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint8x16_t a = simde_vld1q_u8(test_vec[i].a);
    simde_uint8x16_t b = simde_vld1q_u8(test_vec[i].b);
    simde_uint16x8_t r = simde_vaddl_high_u8(a, b);

    simde_test_arm_neon_assert_equal_u16x8(r, simde_vld1q_u16(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vaddl_high_u16 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    uint16_t a[8];
    uint16_t b[8];
    uint32_t r[4];
  } test_vec[] = {
    { { UINT16_C(43232), UINT16_C(36530), UINT16_C(39899), UINT16_C(62799), UINT16_C(56662), UINT16_C(50000), UINT16_C(17537), UINT16_C(41309) },
      { UINT16_C(27727), UINT16_C( 2079), UINT16_C(39125), UINT16_C(32488), UINT16_C( 2495), UINT16_C(36689), UINT16_C(27430), UINT16_C( 1731) },
      { UINT32_C(     59157), UINT32_C(     86689), UINT32_C(     44967), UINT32_C(     43040) } },
    { { UINT16_C(29971), UINT16_C(61077), UINT16_C(58384), UINT16_C(26595), UINT16_C(13505), UINT16_C(17194), UINT16_C(34680), UINT16_C(51172) },
      { UINT16_C( 1011), UINT16_C(51407), UINT16_C(47003), UINT16_C(23111), UINT16_C(39104), UINT16_C(59370), UINT16_C(44291), UINT16_C( 5869) },
      { UINT32_C(     52609), UINT32_C(     76564), UINT32_C(     78971), UINT32_C(     57041) } },
    { { UINT16_C(33314), UINT16_C(12804), UINT16_C(59238), UINT16_C(10393), UINT16_C(49947), UINT16_C(37739), UINT16_C(20299), UINT16_C(15962) },
      { UINT16_C(10578), UINT16_C(60679), UINT16_C(20193), UINT16_C(41287), UINT16_C(12774), UINT16_C(59784), UINT16_C(30430), UINT16_C(  255) },
      { UINT32_C(     62721), UINT32_C(     97523), UINT32_C(     50729), UINT32_C(     16217) } },
    { { UINT16_C( 1016), UINT16_C(24371), UINT16_C(52458), UINT16_C( 1671), UINT16_C(62096), UINT16_C(56217), UINT16_C(62529), UINT16_C(37657) },
      { UINT16_C( 8221), UINT16_C(65152), UINT16_C(51054), UINT16_C(21664), UINT16_C(10489), UINT16_C(55101), UINT16_C(15518), UINT16_C(38872) },
      { UINT32_C(     72585), UINT32_C(    111318), UINT32_C(     78047), UINT32_C(     76529) } },
    { { UINT16_C( 2879), UINT16_C(10998), UINT16_C(32215), UINT16_C(26416), UINT16_C(51567), UINT16_C(45122), UINT16_C(23741), UINT16_C(56131) },
      { UINT16_C(50044), UINT16_C(60377), UINT16_C(31114), UINT16_C(33599), UINT16_C(32162), UINT16_C(16475), UINT16_C(13241), UINT16_C(63959) },
      { UINT32_C(     83729), UINT32_C(     61597), UINT32_C(     36982), UINT32_C(    120090) } },
    { { UINT16_C(52542), UINT16_C( 5411), UINT16_C(21322), UINT16_C(47485), UINT16_C(48924), UINT16_C(55913), UINT16_C(44059), UINT16_C(39093) },
      { UINT16_C(36463), UINT16_C(64131), UINT16_C(49672), UINT16_C(43645), UINT16_C(55359), UINT16_C(63978), UINT16_C(49675), UINT16_C(18930) },
      { UINT32_C(    104283), UINT32_C(    119891), UINT32_C(     93734), UINT32_C(     58023) } },
    { { UINT16_C( 5519), UINT16_C(55903), UINT16_C(56424), UINT16_C(33939), UINT16_C(64923), UINT16_C(46942), UINT16_C( 5033), UINT16_C( 6479) },
      { UINT16_C(53922), UINT16_C(43539), UINT16_C(37012), UINT16_C(54356), UINT16_C(15977), UINT16_C(29901), UINT16_C(48896), UINT16_C(37054) },
      { UINT32_C(     80900), UINT32_C(     76843), UINT32_C(     53929), UINT32_C(     43533) } },
    { { UINT16_C( 7636), UINT16_C(15466), UINT16_C(65017), UINT16_C(38080), UINT16_C( 8186), UINT16_C(42059), UINT16_C(39474), UINT16_C(54461) },
      { UINT16_C(53356), UINT16_C(  382), UINT16_C(53856), UINT16_C(51669), UINT16_C(41489), UINT16_C( 4414), UINT16_C(64609), UINT16_C(13729) },
      { UINT32_C(     49675), UINT32_C(     46473), UINT32_C(    104083), UINT32_C(     68190) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint16x8_t a = simde_vld1q_u16(test_vec[i].a);
    simde_uint16x8_t b = simde_vld1q_u16(test_vec[i].b);
    simde_uint32x4_t r = simde_vaddl_high_u16(a, b);
    simde_test_arm_neon_assert_equal_u32x4(r, simde_vld1q_u32(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vaddl_high_u32 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    uint32_t a[4];
    uint32_t b[4];
    uint64_t r[2];
  } test_vec[] = {
    { { UINT32_C(3588152856), UINT32_C(3931789934), UINT32_C(3351288904), UINT32_C(2406829796) },
      { UINT32_C(3539332684), UINT32_C(2548929043), UINT32_C(3124332951), UINT32_C(3615191487) },
      { UINT64_C(          6475621855), UINT64_C(          6022021283) } },
    { { UINT32_C(3198966351), UINT32_C(4255647412), UINT32_C(2261018786), UINT32_C(  51788471) },
      { UINT32_C(1003817768), UINT32_C( 886227613), UINT32_C( 183438411), UINT32_C(3454102141) },
      { UINT64_C(          2444457197), UINT64_C(          3505890612) } },
    { { UINT32_C(2039188932), UINT32_C( 896938899), UINT32_C(1388067483), UINT32_C(2639647348) },
      { UINT32_C(2060987101), UINT32_C( 951036908), UINT32_C( 876781239), UINT32_C(3439404040) },
      { UINT64_C(          2264848722), UINT64_C(          6079051388) } },
    { { UINT32_C(1162251441), UINT32_C(1534770367), UINT32_C(1806513910), UINT32_C(3842507528) },
      { UINT32_C( 442556461), UINT32_C(1112674187), UINT32_C(3044512941), UINT32_C(1786935480) },
      { UINT64_C(          4851026851), UINT64_C(          5629443008) } },
    { { UINT32_C(3299854341), UINT32_C(2065639812), UINT32_C(1759956320), UINT32_C(4249808592) },
      { UINT32_C(1511501518), UINT32_C(1788635581), UINT32_C(3055490046), UINT32_C(2434835084) },
      { UINT64_C(          4815446366), UINT64_C(          6684643676) } },
    { { UINT32_C(4015378282), UINT32_C(1500149241), UINT32_C( 314658882), UINT32_C( 202313534) },
      { UINT32_C(2053515197), UINT32_C(2397307792), UINT32_C(2722432022), UINT32_C( 271803814) },
      { UINT64_C(          3037090904), UINT64_C(           474117348) } },
    { { UINT32_C( 788498741), UINT32_C(1082616318), UINT32_C(4149364921), UINT32_C( 352608600) },
      { UINT32_C( 428894856), UINT32_C(2225566829), UINT32_C( 505867384), UINT32_C(2268027474) },
      { UINT64_C(          4655232305), UINT64_C(          2620636074) } },
    { { UINT32_C(3786747619), UINT32_C(1361132696), UINT32_C(3695801220), UINT32_C(1576160724) },
      { UINT32_C( 628523703), UINT32_C(1873354230), UINT32_C(1552797450), UINT32_C( 216251433) },
      { UINT64_C(          5248598670), UINT64_C(          1792412157) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint32x4_t a = simde_vld1q_u32(test_vec[i].a);
    simde_uint32x4_t b = simde_vld1q_u32(test_vec[i].b);
    simde_uint64x2_t r = simde_vaddl_high_u32(a, b);
    simde_test_arm_neon_assert_equal_u64x2(r, simde_vld1q_u64(test_vec[i].r));
  }

  return 0;
}

SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(vaddl_high_s8)
SIMDE_TEST_FUNC_LIST_ENTRY(vaddl_high_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vaddl_high_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vaddl_high_u8)
SIMDE_TEST_FUNC_LIST_ENTRY(vaddl_high_u16)
SIMDE_TEST_FUNC_LIST_ENTRY(vaddl_high_u32)

SIMDE_TEST_FUNC_LIST_END

#include "test-neon-footer.h"
