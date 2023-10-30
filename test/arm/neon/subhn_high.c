#define SIMDE_TEST_ARM_NEON_INSN subhn_high

#include "test-neon.h"
#include "../../../simde/arm/neon/subhn_high.h"

static int
test_simde_vsubhn_high_s16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int8_t r_[8];
    int16_t a[8];
    int16_t b[8];
    int8_t r[16];
  } test_vec[] = {
    { { -INT8_C(     117),  INT8_C(     112),  INT8_C(      27),  INT8_C(      16),
        -INT8_C(     120),  INT8_C(      46), -INT8_C(     109),  INT8_C(      13) },
      { -INT16_C(    9788),  INT16_C(   19552),  INT16_C(   21637), -INT16_C(   12887),
         INT16_C(    9621), -INT16_C(   13623), -INT16_C(    5166),  INT16_C(   30339) },
      {  INT16_C(   20984), -INT16_C(   21988), -INT16_C(   23953), -INT16_C(   24294),
         INT16_C(   10052), -INT16_C(   17355), -INT16_C(   15994), -INT16_C(   17361) },
      { -INT8_C(     117),  INT8_C(     112),  INT8_C(      27),  INT8_C(      16),
        -INT8_C(     120),  INT8_C(      46), -INT8_C(     109),  INT8_C(      13),
        -INT8_C(     121), -INT8_C(      94), -INT8_C(      78),  INT8_C(      44),
        -INT8_C(       2),  INT8_C(      14),  INT8_C(      42), -INT8_C(      70) } },
    { {  INT8_C(      18),  INT8_C(      57),  INT8_C(      24), -INT8_C(      81),
         INT8_C(      96),  INT8_C(      24),  INT8_C(       9),  INT8_C(      92) },
      {  INT16_C(   31116), -INT16_C(   17379), -INT16_C(   22564),  INT16_C(   24397),
         INT16_C(   23021),  INT16_C(    5094),  INT16_C(   14601), -INT16_C(    1573) },
      { -INT16_C(   12470), -INT16_C(   28767), -INT16_C(   29490), -INT16_C(    7072),
         INT16_C(    4332),  INT16_C(      38),  INT16_C(   26740), -INT16_C(   14382) },
      {  INT8_C(      18),  INT8_C(      57),  INT8_C(      24), -INT8_C(      81),
         INT8_C(      96),  INT8_C(      24),  INT8_C(       9),  INT8_C(      92),
        -INT8_C(      86),  INT8_C(      44),  INT8_C(      27),  INT8_C(     122),
         INT8_C(      73),  INT8_C(      19), -INT8_C(      48),  INT8_C(      50) } },
    { {  INT8_C(     102),  INT8_C(      87), -INT8_C(      31), -INT8_C(      82),
         INT8_C(      40), -INT8_C(      14), -INT8_C(      10),  INT8_C(      26) },
      {  INT16_C(   31240), -INT16_C(   13917), -INT16_C(      82), -INT16_C(    9125),
        -INT16_C(   15430), -INT16_C(   11953),  INT16_C(   32208), -INT16_C(   24914) },
      { -INT16_C(   16820),  INT16_C(    2568),  INT16_C(    6720), -INT16_C(   26171),
         INT16_C(   26840),  INT16_C(    4905),  INT16_C(   32387),  INT16_C(    4776) },
      {  INT8_C(     102),  INT8_C(      87), -INT8_C(      31), -INT8_C(      82),
         INT8_C(      40), -INT8_C(      14), -INT8_C(      10),  INT8_C(      26),
        -INT8_C(      69), -INT8_C(      65), -INT8_C(      27),  INT8_C(      66),
         INT8_C(      90), -INT8_C(      66), -INT8_C(       1), -INT8_C(     116) } },
    { { -INT8_C(      14),  INT8_C(      99), -INT8_C(      55),  INT8_C(      33),
        -INT8_C(      23),  INT8_C(      27), -INT8_C(     109),  INT8_C(      60) },
      { -INT16_C(   21281), -INT16_C(   13096),  INT16_C(   22168),  INT16_C(   25258),
         INT16_C(   12177), -INT16_C(   30502),  INT16_C(   15149), -INT16_C(   27941) },
      {  INT16_C(   18394),  INT16_C(   24287), -INT16_C(   25430), -INT16_C(   13340),
         INT16_C(   10866),  INT16_C(   17678), -INT16_C(   10282),  INT16_C(    1395) },
      { -INT8_C(      14),  INT8_C(      99), -INT8_C(      55),  INT8_C(      33),
        -INT8_C(      23),  INT8_C(      27), -INT8_C(     109),  INT8_C(      60),
         INT8_C(     101),  INT8_C(     109), -INT8_C(      71), -INT8_C(     106),
         INT8_C(       5),  INT8_C(      67),  INT8_C(      99), -INT8_C(     115) } },
    { { -INT8_C(     103),  INT8_C(     122),  INT8_C(       6), -INT8_C(      40),
         INT8_C(      43), -INT8_C(      71), -INT8_C(      77), -INT8_C(      89) },
      { -INT16_C(   25294), -INT16_C(    5550), -INT16_C(   25768), -INT16_C(   25112),
         INT16_C(   29775),  INT16_C(   17688), -INT16_C(    5919),  INT16_C(      25) },
      { -INT16_C(   17300), -INT16_C(   20485), -INT16_C(   28702),  INT16_C(   27012),
         INT16_C(   18149), -INT16_C(     696),  INT16_C(    3323),  INT16_C(    8549) },
      { -INT8_C(     103),  INT8_C(     122),  INT8_C(       6), -INT8_C(      40),
         INT8_C(      43), -INT8_C(      71), -INT8_C(      77), -INT8_C(      89),
        -INT8_C(      32),  INT8_C(      58),  INT8_C(      11),  INT8_C(      52),
         INT8_C(      45),  INT8_C(      71), -INT8_C(      37), -INT8_C(      34) } },
    { {  INT8_C(     120),  INT8_C(      78),  INT8_C(       6),  INT8_C(       2),
        -INT8_C(      78),  INT8_C(      98),  INT8_C(      79), -INT8_C(     125) },
      { -INT16_C(    1905), -INT16_C(   15769),  INT16_C(    2596),  INT16_C(    5234),
         INT16_C(   12744), -INT16_C(    8464),  INT16_C(     910),  INT16_C(    5381) },
      { -INT16_C(   22604), -INT16_C(    6455),  INT16_C(   14639),  INT16_C(    9589),
         INT16_C(   29328), -INT16_C(   13186),  INT16_C(   17255), -INT16_C(    3295) },
      {  INT8_C(     120),  INT8_C(      78),  INT8_C(       6),  INT8_C(       2),
        -INT8_C(      78),  INT8_C(      98),  INT8_C(      79), -INT8_C(     125),
         INT8_C(      80), -INT8_C(      37), -INT8_C(      48), -INT8_C(      18),
        -INT8_C(      65),  INT8_C(      18), -INT8_C(      64),  INT8_C(      33) } },
    { {  INT8_C(      28), -INT8_C(      46), -INT8_C(     100), -INT8_C(      98),
         INT8_C(       8), -INT8_C(      29), -INT8_C(      86),  INT8_C(      71) },
      { -INT16_C(    2272), -INT16_C(   21599),  INT16_C(   27125), -INT16_C(   27192),
         INT16_C(   28731), -INT16_C(   16840),  INT16_C(   12920), -INT16_C(    1949) },
      {  INT16_C(    4217),  INT16_C(   27364), -INT16_C(   29204),  INT16_C(   18794),
         INT16_C(    6596),  INT16_C(    9775), -INT16_C(   24499),  INT16_C(    2857) },
      {  INT8_C(      28), -INT8_C(      46), -INT8_C(     100), -INT8_C(      98),
         INT8_C(       8), -INT8_C(      29), -INT8_C(      86),  INT8_C(      71),
        -INT8_C(      26),  INT8_C(      64), -INT8_C(      36),  INT8_C(      76),
         INT8_C(      86), -INT8_C(     104), -INT8_C(     110), -INT8_C(      19) } },
    { { -INT8_C(      69), -INT8_C(      46),  INT8_C(      14),  INT8_C(      55),
        -INT8_C(      88), -INT8_C(      21), -INT8_C(      78),  INT8_C(      74) },
      { -INT16_C(   24201), -INT16_C(    4699),  INT16_C(    9518), -INT16_C(    6489),
         INT16_C(   26111),  INT16_C(   19948), -INT16_C(   31665),  INT16_C(   19959) },
      {  INT16_C(   32205),  INT16_C(    6352), -INT16_C(    2043),  INT16_C(   32653),
        -INT16_C(   15687), -INT16_C(    2655),  INT16_C(    2092), -INT16_C(   19348) },
      { -INT8_C(      69), -INT8_C(      46),  INT8_C(      14),  INT8_C(      55),
        -INT8_C(      88), -INT8_C(      21), -INT8_C(      78),  INT8_C(      74),
         INT8_C(      35), -INT8_C(      44),  INT8_C(      45),  INT8_C(     103),
        -INT8_C(      93),  INT8_C(      88),  INT8_C(     124), -INT8_C(     103) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int8x8_t r_ = simde_vld1_s8(test_vec[i].r_);
    simde_int16x8_t a = simde_vld1q_s16(test_vec[i].a);
    simde_int16x8_t b = simde_vld1q_s16(test_vec[i].b);
    simde_int8x16_t r = simde_vsubhn_high_s16(r_, a, b);

    simde_test_arm_neon_assert_equal_i8x16(r, simde_vld1q_s8(test_vec[i].r));
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int8x8_t r_ = simde_test_arm_neon_random_i8x8();
    simde_int16x8_t a = simde_test_arm_neon_random_i16x8();
    simde_int16x8_t b = simde_test_arm_neon_random_i16x8();
    simde_int8x16_t r = simde_vsubhn_high_s16(r_, a, b);

    simde_test_arm_neon_write_i8x8(2, r_, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i16x8(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i16x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i8x16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vsubhn_high_s32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int16_t r_[4];
    int32_t a[4];
    int32_t b[4];
    int16_t r[8];
  } test_vec[] = {
    { {  INT16_C(        6369),  INT16_C(       24709),  INT16_C(        2997),  INT16_C(        4792) },
      {  INT32_C(  1439254570), -INT32_C(   472655675), -INT32_C(  1402675053), -INT32_C(  1157950118) },
      {  INT32_C(   892517918),  INT32_C(  1834606942),  INT32_C(    43483114),  INT32_C(  1348293436) },
      {  INT16_C(        6369),  INT16_C(       24709),  INT16_C(        2997),  INT16_C(        4792),
         INT16_C(        8342),  INT16_C(       30329), -INT16_C(       22067),  INT16_C(       27293) } },
    { {  INT16_C(       25600), -INT16_C(       25377), -INT16_C(        1370),  INT16_C(         660) },
      {  INT32_C(   670947662), -INT32_C(  1535293312),  INT32_C(   937641728),  INT32_C(  1932622533) },
      {  INT32_C(    19850762),  INT32_C(  1459326630), -INT32_C(  1893892437), -INT32_C(   119070833) },
      {  INT16_C(       25600), -INT16_C(       25377), -INT16_C(        1370),  INT16_C(         660),
         INT16_C(        9934),  INT16_C(       19841), -INT16_C(       22331),  INT16_C(       31306) } },
    { {  INT16_C(       28925), -INT16_C(        9832),  INT16_C(       21345), -INT16_C(       19583) },
      { -INT32_C(  2093055507), -INT32_C(  1011911496), -INT32_C(  1804639498),  INT32_C(   303687540) },
      {  INT32_C(  2010835777), -INT32_C(  1694291572), -INT32_C(   627130717), -INT32_C(  1445863737) },
      {  INT16_C(       28925), -INT16_C(        9832),  INT16_C(       21345), -INT16_C(       19583),
         INT16_C(        2915),  INT16_C(       10412), -INT16_C(       17968),  INT16_C(       26696) } },
    { { -INT16_C(       12911),  INT16_C(       24138), -INT16_C(       25983),  INT16_C(       23648) },
      {  INT32_C(    52340318), -INT32_C(   863808383), -INT32_C(   555540630),  INT32_C(  1774755419) },
      { -INT32_C(   795691217), -INT32_C(   335968196), -INT32_C(   713717059), -INT32_C(   647818329) },
      { -INT16_C(       12911),  INT16_C(       24138), -INT16_C(       25983),  INT16_C(       23648),
         INT16_C(       12939), -INT16_C(        8055),  INT16_C(        2413), -INT16_C(       28571) } },
    { { -INT16_C(       17852), -INT16_C(       12636),  INT16_C(        3614),  INT16_C(       18211) },
      { -INT32_C(  1379133148), -INT32_C(  1224843108), -INT32_C(  1172311476), -INT32_C(  1948533636) },
      { -INT32_C(   223917205), -INT32_C(  1143265830),  INT32_C(   751940812),  INT32_C(  1833020540) },
      { -INT16_C(       17852), -INT16_C(       12636),  INT16_C(        3614),  INT16_C(       18211),
        -INT16_C(       17628), -INT16_C(        1245), -INT16_C(       29362),  INT16_C(        7834) } },
    { {  INT16_C(       22019),  INT16_C(        3476),  INT16_C(       10940),  INT16_C(       25549) },
      {  INT32_C(  1547672807),  INT32_C(  1658972008), -INT32_C(   397622022),  INT32_C(  2038136246) },
      {  INT32_C(  1167599887),  INT32_C(   866454403), -INT32_C(   597692646), -INT32_C(  1706654893) },
      {  INT16_C(       22019),  INT16_C(        3476),  INT16_C(       10940),  INT16_C(       25549),
         INT16_C(        5799),  INT16_C(       12092),  INT16_C(        3052), -INT16_C(        8396) } },
    { {  INT16_C(       29074),  INT16_C(         286), -INT16_C(       17413), -INT16_C(       21175) },
      {  INT32_C(   698825048), -INT32_C(  1003482864),  INT32_C(  1243797008), -INT32_C(  1801579672) },
      {  INT32_C(  2039811071),  INT32_C(  1039380535), -INT32_C(  1945617293), -INT32_C(   791076684) },
      {  INT16_C(       29074),  INT16_C(         286), -INT16_C(       17413), -INT16_C(       21175),
        -INT16_C(       20462), -INT16_C(       31172), -INT16_C(       16870), -INT16_C(       15420) } },
    { {  INT16_C(       11827),  INT16_C(       14170),  INT16_C(        4401),  INT16_C(        1570) },
      {  INT32_C(  1398282069),  INT32_C(  1254418806),  INT32_C(   391659863),  INT32_C(  1913746244) },
      { -INT32_C(  1971809439),  INT32_C(  1385986908), -INT32_C(   739592010),  INT32_C(  1307803221) },
      {  INT16_C(       11827),  INT16_C(       14170),  INT16_C(        4401),  INT16_C(        1570),
        -INT16_C(       14113), -INT16_C(        2008),  INT16_C(       17261),  INT16_C(        9245) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x4_t r_ = simde_vld1_s16(test_vec[i].r_);
    simde_int32x4_t a = simde_vld1q_s32(test_vec[i].a);
    simde_int32x4_t b = simde_vld1q_s32(test_vec[i].b);
    simde_int16x8_t r = simde_vsubhn_high_s32(r_, a, b);

    simde_test_arm_neon_assert_equal_i16x8(r, simde_vld1q_s16(test_vec[i].r));
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int16x4_t r_ = simde_test_arm_neon_random_i16x4();
    simde_int32x4_t a = simde_test_arm_neon_random_i32x4();
    simde_int32x4_t b = simde_test_arm_neon_random_i32x4();
    simde_int16x8_t r = simde_vsubhn_high_s32(r_, a, b);

    simde_test_arm_neon_write_i16x4(2, r_, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i32x4(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i16x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vsubhn_high_s64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int32_t r_[2];
    int64_t a[2];
    int64_t b[2];
    int32_t r[4];
  } test_vec[] = {
    { { -INT32_C(          1345837580),  INT32_C(          1700336653) },
      { -INT64_C( 2753610254988905297),  INT64_C( 6385676709539608043) },
      {  INT64_C( 7900566264575188422),  INT64_C( 3639573331698101730) },
      { -INT32_C(          1345837580),  INT32_C(          1700336653),  INT32_C(          1814348519),  INT32_C(           639377017) } },
    { {  INT32_C(           793296646), -INT32_C(           475088083) },
      { -INT64_C(   19520665629207987), -INT64_C(  755298648432975096) },
      { -INT64_C( 3502088111990473340), -INT64_C( 2396094240927981562) },
      {  INT32_C(           793296646), -INT32_C(           475088083),  INT32_C(           810848420),  INT32_C(           382027493) } },
    { { -INT32_C(           592338498),  INT32_C(           139040483) },
      { -INT64_C( 7253734356412758440), -INT64_C( 1612409167884579005) },
      { -INT64_C( 1830773530429079327),  INT64_C( 2329268992581229480) },
      { -INT32_C(           592338498),  INT32_C(           139040483), -INT32_C(          1262631460), -INT32_C(           917743464) } },
    { {  INT32_C(           664390283), -INT32_C(            68709652) },
      {  INT64_C( 1548465429520676198), -INT64_C(  371716712216087614) },
      { -INT64_C(  549111039462059100), -INT64_C( 2690433626302333615) },
      {  INT32_C(           664390283), -INT32_C(            68709652),  INT32_C(           488380079),  INT32_C(           539868351) } },
    { { -INT32_C(          1992760265),  INT32_C(           994118646) },
      { -INT64_C( 6434967836066178244), -INT64_C( 7974896683015646751) },
      {  INT64_C( 2966314510471691257),  INT64_C( 5828665420006592533) },
      { -INT32_C(          1992760265),  INT32_C(           994118646),  INT32_C(          2106060676),  INT32_C(          1081075046) } },
    { {  INT32_C(          1731865086), -INT32_C(          1710860974) },
      {  INT64_C( 8140411609455794264), -INT64_C(   13180250881711242) },
      { -INT64_C(   27628431305474532),  INT64_C(  239131349871858432) },
      {  INT32_C(          1731865086), -INT32_C(          1710860974),  INT32_C(          1901770020), -INT32_C(            58745873) } },
    { {  INT32_C(          1203174676), -INT32_C(            57989697) },
      { -INT64_C(  814143540967833940),  INT64_C( 9072764515854364307) },
      { -INT64_C(   30008794202133902), -INT64_C( 2288744623078980675) },
      {  INT32_C(          1203174676), -INT32_C(            57989697), -INT32_C(           182570598), -INT32_C(          1649659811) } },
    { { -INT32_C(           747972824), -INT32_C(           346056247) },
      {  INT64_C( 2778365201094315420), -INT64_C( 1429503064753223877) },
      { -INT64_C( 2469363646925528149),  INT64_C( 3822471788356618393) },
      { -INT32_C(           747972824), -INT32_C(           346056247),  INT32_C(          1221832085), -INT32_C(          1222820686) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x2_t r_ = simde_vld1_s32(test_vec[i].r_);
    simde_int64x2_t a = simde_vld1q_s64(test_vec[i].a);
    simde_int64x2_t b = simde_vld1q_s64(test_vec[i].b);
    simde_int32x4_t r = simde_vsubhn_high_s64(r_, a, b);

    simde_test_arm_neon_assert_equal_i32x4(r, simde_vld1q_s32(test_vec[i].r));
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int32x2_t r_ = simde_test_arm_neon_random_i32x2();
    simde_int64x2_t a = simde_test_arm_neon_random_i64x2();
    simde_int64x2_t b = simde_test_arm_neon_random_i64x2();
    simde_int32x4_t r = simde_vsubhn_high_s64(r_, a, b);

    simde_test_arm_neon_write_i32x2(2, r_, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i64x2(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i64x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vsubhn_high_u16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint8_t r_[8];
    uint16_t a[8];
    uint16_t b[8];
    uint8_t r[16];
  } test_vec[] = {
    { {  UINT8_C(     147),  UINT8_C(     146),  UINT8_C(     108),  UINT8_C(     122),
         UINT8_C(       5),  UINT8_C(     252),  UINT8_C(     244),  UINT8_C(     212) },
      {  UINT16_C(   36936),  UINT16_C(   30660),  UINT16_C(   47515),  UINT16_C(   12375),
         UINT16_C(   58617),  UINT16_C(   58625),  UINT16_C(   13059),  UINT16_C(    1551) },
      {  UINT16_C(   62367),  UINT16_C(   16668),  UINT16_C(   11939),  UINT16_C(   61374),
         UINT16_C(   56677),  UINT16_C(   31974),  UINT16_C(   11727),  UINT16_C(   48657) },
      {  UINT8_C(     147),  UINT8_C(     146),  UINT8_C(     108),  UINT8_C(     122),
         UINT8_C(       5),  UINT8_C(     252),  UINT8_C(     244),  UINT8_C(     212),
         UINT8_C(     156),  UINT8_C(      54),  UINT8_C(     138),  UINT8_C(      64),
         UINT8_C(       7),  UINT8_C(     104),  UINT8_C(       5),  UINT8_C(      71) } },
    { {  UINT8_C(     182),  UINT8_C(     130),  UINT8_C(     199),  UINT8_C(     197),
         UINT8_C(      28),  UINT8_C(      35),  UINT8_C(     132),  UINT8_C(      28) },
      {  UINT16_C(   21901),  UINT16_C(   47315),  UINT16_C(   59632),  UINT16_C(   65338),
         UINT16_C(   20497),  UINT16_C(   12373),  UINT16_C(   18523),  UINT16_C(    6660) },
      {  UINT16_C(   44805),  UINT16_C(   47565),  UINT16_C(   54457),  UINT16_C(   46465),
         UINT16_C(   20799),  UINT16_C(   48837),  UINT16_C(   12260),  UINT16_C(   23478) },
      {  UINT8_C(     182),  UINT8_C(     130),  UINT8_C(     199),  UINT8_C(     197),
         UINT8_C(      28),  UINT8_C(      35),  UINT8_C(     132),  UINT8_C(      28),
         UINT8_C(     166),           UINT8_MAX,  UINT8_C(      20),  UINT8_C(      73),
         UINT8_C(     254),  UINT8_C(     113),  UINT8_C(      24),  UINT8_C(     190) } },
    { {  UINT8_C(     132),  UINT8_C(     164),  UINT8_C(     201),  UINT8_C(     169),
         UINT8_C(     105),  UINT8_C(     124),  UINT8_C(     182),  UINT8_C(     250) },
      {  UINT16_C(   18300),  UINT16_C(   11106),  UINT16_C(   17252),  UINT16_C(   38473),
         UINT16_C(   18517),  UINT16_C(   59003),  UINT16_C(   42817),  UINT16_C(   29319) },
      {  UINT16_C(   62661),  UINT16_C(    6686),  UINT16_C(   32330),  UINT16_C(   51232),
         UINT16_C(   50679),  UINT16_C(   47360),  UINT16_C(   57457),  UINT16_C(   58547) },
      {  UINT8_C(     132),  UINT8_C(     164),  UINT8_C(     201),  UINT8_C(     169),
         UINT8_C(     105),  UINT8_C(     124),  UINT8_C(     182),  UINT8_C(     250),
         UINT8_C(      82),  UINT8_C(      17),  UINT8_C(     197),  UINT8_C(     206),
         UINT8_C(     130),  UINT8_C(      45),  UINT8_C(     198),  UINT8_C(     141) } },
    { {  UINT8_C(      56),  UINT8_C(      26),  UINT8_C(      11),  UINT8_C(      34),
         UINT8_C(      31),  UINT8_C(      10),  UINT8_C(     242),  UINT8_C(     145) },
      {  UINT16_C(   47454),  UINT16_C(   27461),  UINT16_C(   59534),  UINT16_C(   52583),
         UINT16_C(    8607),  UINT16_C(   16799),  UINT16_C(   60264),  UINT16_C(   28574) },
      {  UINT16_C(   11001),  UINT16_C(   14260),  UINT16_C(   35342),  UINT16_C(   41621),
         UINT16_C(   56075),  UINT16_C(   35362),  UINT16_C(   44265),  UINT16_C(   22275) },
      {  UINT8_C(      56),  UINT8_C(      26),  UINT8_C(      11),  UINT8_C(      34),
         UINT8_C(      31),  UINT8_C(      10),  UINT8_C(     242),  UINT8_C(     145),
         UINT8_C(     142),  UINT8_C(      51),  UINT8_C(      94),  UINT8_C(      42),
         UINT8_C(      70),  UINT8_C(     183),  UINT8_C(      62),  UINT8_C(      24) } },
    { {  UINT8_C(     242),  UINT8_C(     111),  UINT8_C(     164),  UINT8_C(     156),
         UINT8_C(      75),  UINT8_C(     169),  UINT8_C(     249),  UINT8_C(      34) },
      {  UINT16_C(   14937),  UINT16_C(   55996),  UINT16_C(   39570),  UINT16_C(   57168),
         UINT16_C(   24875),  UINT16_C(   17588),  UINT16_C(   55235),  UINT16_C(   53029) },
      {  UINT16_C(   41069),  UINT16_C(   12710),  UINT16_C(   18101),  UINT16_C(    6114),
         UINT16_C(   60209),  UINT16_C(   36496),  UINT16_C(   57501),  UINT16_C(   42607) },
      {  UINT8_C(     242),  UINT8_C(     111),  UINT8_C(     164),  UINT8_C(     156),
         UINT8_C(      75),  UINT8_C(     169),  UINT8_C(     249),  UINT8_C(      34),
         UINT8_C(     153),  UINT8_C(     169),  UINT8_C(      83),  UINT8_C(     199),
         UINT8_C(     117),  UINT8_C(     182),  UINT8_C(     247),  UINT8_C(      40) } },
    { {  UINT8_C(     235),  UINT8_C(     188),  UINT8_C(      59),  UINT8_C(      48),
         UINT8_C(     156),  UINT8_C(     183),  UINT8_C(      94),  UINT8_C(      16) },
      {  UINT16_C(    9802),  UINT16_C(   46372),  UINT16_C(   41866),  UINT16_C(   41251),
         UINT16_C(   48020),  UINT16_C(    9909),  UINT16_C(   58807),  UINT16_C(    5530) },
      {  UINT16_C(   12728),  UINT16_C(   50063),  UINT16_C(   22046),  UINT16_C(   63995),
         UINT16_C(   56333),  UINT16_C(   43957),  UINT16_C(   56740),  UINT16_C(   62685) },
      {  UINT8_C(     235),  UINT8_C(     188),  UINT8_C(      59),  UINT8_C(      48),
         UINT8_C(     156),  UINT8_C(     183),  UINT8_C(      94),  UINT8_C(      16),
         UINT8_C(     244),  UINT8_C(     241),  UINT8_C(      77),  UINT8_C(     167),
         UINT8_C(     223),  UINT8_C(     123),  UINT8_C(       8),  UINT8_C(      32) } },
    { {  UINT8_C(     224),  UINT8_C(     151),  UINT8_C(     179),  UINT8_C(     162),
         UINT8_C(      70),  UINT8_C(     141),  UINT8_C(     205),  UINT8_C(     132) },
      {  UINT16_C(   47638),  UINT16_C(    9156),  UINT16_C(   55951),  UINT16_C(   18486),
         UINT16_C(   56254),  UINT16_C(    4317),  UINT16_C(   38658),  UINT16_C(   63844) },
      {  UINT16_C(   52904),  UINT16_C(   31574),  UINT16_C(   40630),  UINT16_C(   48553),
         UINT16_C(    2858),  UINT16_C(   27713),  UINT16_C(    1088),  UINT16_C(   51626) },
      {  UINT8_C(     224),  UINT8_C(     151),  UINT8_C(     179),  UINT8_C(     162),
         UINT8_C(      70),  UINT8_C(     141),  UINT8_C(     205),  UINT8_C(     132),
         UINT8_C(     235),  UINT8_C(     168),  UINT8_C(      59),  UINT8_C(     138),
         UINT8_C(     208),  UINT8_C(     164),  UINT8_C(     146),  UINT8_C(      47) } },
    { {  UINT8_C(     199),  UINT8_C(     213),  UINT8_C(     102),  UINT8_C(     201),
         UINT8_C(     134),  UINT8_C(      76),  UINT8_C(      30),  UINT8_C(     169) },
      {  UINT16_C(   48047),  UINT16_C(    7034),  UINT16_C(   33304),  UINT16_C(   25095),
         UINT16_C(   16845),  UINT16_C(   59312),  UINT16_C(   30973),  UINT16_C(   29539) },
      {  UINT16_C(   20636),  UINT16_C(   35281),  UINT16_C(   21704),  UINT16_C(   42160),
         UINT16_C(    6216),  UINT16_C(   41235),  UINT16_C(   15144),  UINT16_C(   16247) },
      {  UINT8_C(     199),  UINT8_C(     213),  UINT8_C(     102),  UINT8_C(     201),
         UINT8_C(     134),  UINT8_C(      76),  UINT8_C(      30),  UINT8_C(     169),
         UINT8_C(     107),  UINT8_C(     145),  UINT8_C(      45),  UINT8_C(     189),
         UINT8_C(      41),  UINT8_C(      70),  UINT8_C(      61),  UINT8_C(      51) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint8x8_t r_ = simde_vld1_u8(test_vec[i].r_);
    simde_uint16x8_t a = simde_vld1q_u16(test_vec[i].a);
    simde_uint16x8_t b = simde_vld1q_u16(test_vec[i].b);
    simde_uint8x16_t r = simde_vsubhn_high_u16(r_, a, b);

    simde_test_arm_neon_assert_equal_u8x16(r, simde_vld1q_u8(test_vec[i].r));
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint8x8_t r_ = simde_test_arm_neon_random_u8x8();
    simde_uint16x8_t a = simde_test_arm_neon_random_u16x8();
    simde_uint16x8_t b = simde_test_arm_neon_random_u16x8();
    simde_uint8x16_t r = simde_vsubhn_high_u16(r_, a, b);

    simde_test_arm_neon_write_u8x8(2, r_, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u16x8(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u16x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u8x16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vsubhn_high_u32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint16_t r_[4];
    uint32_t a[4];
    uint32_t b[4];
    uint16_t r[8];
  } test_vec[] = {
    { {  UINT16_C(       42853),  UINT16_C(       48701),  UINT16_C(       54678),  UINT16_C(       15608) },
      {  UINT32_C(  4114723048),  UINT32_C(   879996611),  UINT32_C(   423829357),  UINT32_C(   333443981) },
      {  UINT32_C(   340376883),  UINT32_C(  2292439510),  UINT32_C(  1227714565),  UINT32_C(  3985607050) },
      {  UINT16_C(       42853),  UINT16_C(       48701),  UINT16_C(       54678),  UINT16_C(       15608),
         UINT16_C(       57591),  UINT16_C(       43983),  UINT16_C(       53269),  UINT16_C(        9808) } },
    { {  UINT16_C(       19702),  UINT16_C(       58614),  UINT16_C(       24824),  UINT16_C(       21625) },
      {  UINT32_C(   866418138),  UINT32_C(  1226726679),  UINT32_C(  2249730439),  UINT32_C(   974672907) },
      {  UINT32_C(  2119397408),  UINT32_C(  3360192224),  UINT32_C(  2912408184),  UINT32_C(  4111890075) },
      {  UINT16_C(       19702),  UINT16_C(       58614),  UINT16_C(       24824),  UINT16_C(       21625),
         UINT16_C(       46417),  UINT16_C(       32981),  UINT16_C(       55424),  UINT16_C(       17665) } },
    { {  UINT16_C(       31234),  UINT16_C(       53946),  UINT16_C(       24940),  UINT16_C(       56204) },
      {  UINT32_C(  3646397308),  UINT32_C(  1939799332),  UINT32_C(  1347161347),  UINT32_C(  2534513859) },
      {  UINT32_C(  4167380972),  UINT32_C(   243009603),  UINT32_C(  1117610809),  UINT32_C(  2555484787) },
      {  UINT16_C(       31234),  UINT16_C(       53946),  UINT16_C(       24940),  UINT16_C(       56204),
         UINT16_C(       57586),  UINT16_C(       25890),  UINT16_C(        3502),  UINT16_C(       65216) } },
    { {  UINT16_C(        3842),  UINT16_C(       52578),  UINT16_C(        1917),  UINT16_C(       12351) },
      {  UINT32_C(  2019509961),  UINT32_C(   498610467),  UINT32_C(  1424604554),  UINT32_C(     3436901) },
      {  UINT32_C(  2721660223),  UINT32_C(  1456725260),  UINT32_C(  3830797284),  UINT32_C(   673476721) },
      {  UINT16_C(        3842),  UINT16_C(       52578),  UINT16_C(        1917),  UINT16_C(       12351),
         UINT16_C(       54822),  UINT16_C(       50916),  UINT16_C(       28820),  UINT16_C(       55312) } },
    { {  UINT16_C(       19859),  UINT16_C(       13877),  UINT16_C(       29034),  UINT16_C(       18772) },
      {  UINT32_C(  3657098557),  UINT32_C(   513952031),  UINT32_C(    45793756),  UINT32_C(   179441664) },
      {  UINT32_C(  2048034348),  UINT32_C(  1787355684),  UINT32_C(  3473367000),  UINT32_C(  3876123832) },
      {  UINT16_C(       19859),  UINT16_C(       13877),  UINT16_C(       29034),  UINT16_C(       18772),
         UINT16_C(       24552),  UINT16_C(       46105),  UINT16_C(       13235),  UINT16_C(        9129) } },
    { {  UINT16_C(       62782),  UINT16_C(       36163),  UINT16_C(       48621),  UINT16_C(       41641) },
      {  UINT32_C(  1606568453),  UINT32_C(  3834482767),  UINT32_C(  1855577627),  UINT32_C(  2523260026) },
      {  UINT32_C(  2825725408),  UINT32_C(  3901417436),  UINT32_C(  3848675181),  UINT32_C(  1411776378) },
      {  UINT16_C(       62782),  UINT16_C(       36163),  UINT16_C(       48621),  UINT16_C(       41641),
         UINT16_C(       46933),  UINT16_C(       64514),  UINT16_C(       35123),  UINT16_C(       16959) } },
    { {  UINT16_C(       54935),  UINT16_C(       19778),  UINT16_C(       45657),  UINT16_C(       45646) },
      {  UINT32_C(   710944102),  UINT32_C(  4212965950),  UINT32_C(  2242905219),  UINT32_C(  3581119777) },
      {  UINT32_C(  3593557678),  UINT32_C(  3039522476),  UINT32_C(  1459472258),  UINT32_C(  1234047683) },
      {  UINT16_C(       54935),  UINT16_C(       19778),  UINT16_C(       45657),  UINT16_C(       45646),
         UINT16_C(       21550),  UINT16_C(       17905),  UINT16_C(       11954),  UINT16_C(       35813) } },
    { {  UINT16_C(       62920),  UINT16_C(       56364),  UINT16_C(       54440),  UINT16_C(       40838) },
      {  UINT32_C(  3817372455),  UINT32_C(  3637270083),  UINT32_C(  3445540932),  UINT32_C(  2755387517) },
      {  UINT32_C(  3603364315),  UINT32_C(    56137272),  UINT32_C(  4044736650),  UINT32_C(  1595697871) },
      {  UINT16_C(       62920),  UINT16_C(       56364),  UINT16_C(       54440),  UINT16_C(       40838),
         UINT16_C(        3265),  UINT16_C(       54643),  UINT16_C(       56392),  UINT16_C(       17695) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint16x4_t r_ = simde_vld1_u16(test_vec[i].r_);
    simde_uint32x4_t a = simde_vld1q_u32(test_vec[i].a);
    simde_uint32x4_t b = simde_vld1q_u32(test_vec[i].b);
    simde_uint16x8_t r = simde_vsubhn_high_u32(r_, a, b);

    simde_test_arm_neon_assert_equal_u16x8(r, simde_vld1q_u16(test_vec[i].r));
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint16x4_t r_ = simde_test_arm_neon_random_u16x4();
    simde_uint32x4_t a = simde_test_arm_neon_random_u32x4();
    simde_uint32x4_t b = simde_test_arm_neon_random_u32x4();
    simde_uint16x8_t r = simde_vsubhn_high_u32(r_, a, b);

    simde_test_arm_neon_write_u16x4(2, r_, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u32x4(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u16x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vsubhn_high_u64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint32_t r_[2];
    uint64_t a[2];
    uint64_t b[2];
    uint32_t r[4];
  } test_vec[] = {
    { {  UINT32_C(          3999226384),  UINT32_C(          1456512388) },
      {  UINT64_C( 5295613403484507553),  UINT64_C( 2360867411919127306) },
      {  UINT64_C( 6378586174956318971),  UINT64_C( 7323495984650455120) },
      {  UINT32_C(          3999226384),  UINT32_C(          1456512388),  UINT32_C(          4042818048),  UINT32_C(          3139515291) } },
    { {  UINT32_C(           795035943),  UINT32_C(           267614517) },
      {  UINT64_C( 8409167043032500407),  UINT64_C( 1856326087528438149) },
      {  UINT64_C( 8642324801815231533),  UINT64_C( 6601241283110469243) },
      {  UINT32_C(           795035943),  UINT32_C(           267614517),  UINT32_C(          4240681024),  UINT32_C(          3190205636) } },
    { {  UINT32_C(           110890792),  UINT32_C(          2835010238) },
      {  UINT64_C(16847630262686556554),  UINT64_C( 4642232485745656480) },
      {  UINT64_C(14892974777062455988),  UINT64_C(15786854231406459525) },
      {  UINT32_C(           110890792),  UINT32_C(          2835010238),  UINT32_C(           455103694),  UINT32_C(          1700157841) } },
    { {  UINT32_C(            62923248),  UINT32_C(          4046510662) },
      {  UINT64_C(14359019773823311122),  UINT64_C( 8395935295601164604) },
      {  UINT64_C(14400417960678629140),  UINT64_C( 1123477169126852572) },
      {  UINT32_C(            62923248),  UINT32_C(          4046510662),  UINT32_C(          4285328529),  UINT32_C(          1693251106) } },
    { {  UINT32_C(          2589970395),  UINT32_C(          3510258348) },
      {  UINT64_C( 2992859837514780136),  UINT64_C(13131056774101454902) },
      {  UINT64_C(  421135565451070621),  UINT64_C(17576841297553179106) },
      {  UINT32_C(          2589970395),  UINT32_C(          3510258348),  UINT32_C(           598776217),  UINT32_C(          3259852423) } },
    { {  UINT32_C(          2074460255),  UINT32_C(           240387781) },
      {  UINT64_C( 4342187632938287006),  UINT64_C(14450507041290722633) },
      {  UINT64_C( 6057404012886260873),  UINT64_C(12296044901719458900) },
      {  UINT32_C(          2074460255),  UINT32_C(           240387781),  UINT32_C(          3895612362),  UINT32_C(           501624806) } },
    { {  UINT32_C(          1070196305),  UINT32_C(          4060491162) },
      {  UINT64_C(15773575918054509905),  UINT64_C( 8026162729548608673) },
      {  UINT64_C(10252799268081500051),  UINT64_C( 9540755129528454575) },
      {  UINT32_C(          1070196305),  UINT32_C(          4060491162),  UINT32_C(          1285405980),  UINT32_C(          3942323772) } },
    { {  UINT32_C(          3147519145),  UINT32_C(          2034848115) },
      {  UINT64_C( 7246468941990502906),  UINT64_C( 7085230927245629820) },
      {  UINT64_C(14209449065934210238),  UINT64_C( 5958706855350969136) },
      {  UINT32_C(          3147519145),  UINT32_C(          2034848115),  UINT32_C(          2673772151),  UINT32_C(           262289324) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint32x2_t r_ = simde_vld1_u32(test_vec[i].r_);
    simde_uint64x2_t a = simde_vld1q_u64(test_vec[i].a);
    simde_uint64x2_t b = simde_vld1q_u64(test_vec[i].b);
    simde_uint32x4_t r = simde_vsubhn_high_u64(r_, a, b);

    simde_test_arm_neon_assert_equal_u32x4(r, simde_vld1q_u32(test_vec[i].r));
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint32x2_t r_ = simde_test_arm_neon_random_u32x2();
    simde_uint64x2_t a = simde_test_arm_neon_random_u64x2();
    simde_uint64x2_t b = simde_test_arm_neon_random_u64x2();
    simde_uint32x4_t r = simde_vsubhn_high_u64(r_, a, b);

    simde_test_arm_neon_write_u32x2(2, r_, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u64x2(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u64x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}


SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(vsubhn_high_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vsubhn_high_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vsubhn_high_s64)

SIMDE_TEST_FUNC_LIST_ENTRY(vsubhn_high_u16)
SIMDE_TEST_FUNC_LIST_ENTRY(vsubhn_high_u32)
SIMDE_TEST_FUNC_LIST_ENTRY(vsubhn_high_u64)
SIMDE_TEST_FUNC_LIST_END

#include "test-neon-footer.h"
