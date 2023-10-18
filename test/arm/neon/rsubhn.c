#define SIMDE_TEST_ARM_NEON_INSN rsubhn

#include "test-neon.h"
#include "../../../simde/arm/neon/rsubhn.h"

static int
test_simde_vrsubhn_s16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int16_t a[8];
    int16_t b[8];
    int8_t r[8];
  } test_vec[] = {
    { {  INT16_C(   1165), -INT16_C(  25577), -INT16_C(  19629),  INT16_C(  16709), -INT16_C(  10414),  INT16_C(  11317), -INT16_C(  25725), -INT16_C(   8539)  },
      {  INT16_C(  30857),  INT16_C(  31003), -INT16_C(  19117),  INT16_C(  17860),  INT16_C(  26198),  INT16_C(   3923),  INT16_C(   1999),  INT16_C(   6514)  },
      { -INT8_C(    116),  INT8_C(     35), -INT8_C(      2), -INT8_C(      4),  INT8_C(    113),  INT8_C(     29), -INT8_C(    108), -INT8_C(     59)  } },
    { { -INT16_C(  25274),  INT16_C(  25728), -INT16_C(   2273),  INT16_C(  28917), -INT16_C(  20745), -INT16_C(  17220),  INT16_C(  17034),  INT16_C(  10018)  },
      {  INT16_C(   8191), -INT16_C(  17753),  INT16_C(   9836),  INT16_C(  10532), -INT16_C(  17563), -INT16_C(  19211), -INT16_C(  27082), -INT16_C(  27159)  },
      {  INT8_C(    125), -INT8_C(     86), -INT8_C(     47),  INT8_C(     72), -INT8_C(     12),  INT8_C(      8), -INT8_C(     84), -INT8_C(    111)  } },
    { {  INT16_C(   3119),  INT16_C(  22524),  INT16_C(  31293), -INT16_C(  17154), -INT16_C(    555), -INT16_C(   4005),  INT16_C(   3508), -INT16_C(  18031)  },
      {  INT16_C(  13560), -INT16_C(  15028),  INT16_C(  24566), -INT16_C(  22220),  INT16_C(  11155),  INT16_C(   3919), -INT16_C(   6841), -INT16_C(  24138)  },
      { -INT8_C(     41), -INT8_C(    109),  INT8_C(     26),  INT8_C(     20), -INT8_C(     46), -INT8_C(     31),  INT8_C(     40),  INT8_C(     24)  } },
    { {  INT16_C(  18265),  INT16_C(  11526), -INT16_C(   4342),  INT16_C(   6872), -INT16_C(   2835), -INT16_C(  19093), -INT16_C(   8816), -INT16_C(   5583)  },
      {  INT16_C(   7850), -INT16_C(  18627), -INT16_C(  12018), -INT16_C(   7828), -INT16_C(  20995),  INT16_C(  25319), -INT16_C(  23122), -INT16_C(  30516)  },
      {  INT8_C(     41),  INT8_C(    118),  INT8_C(     30),  INT8_C(     57),  INT8_C(     71),  INT8_C(     83),  INT8_C(     56),  INT8_C(     97)  } },
    { { -INT16_C(   3909), -INT16_C(   7574), -INT16_C(  19525),  INT16_C(  25595), -INT16_C(  16839), -INT16_C(    248), -INT16_C(   8970), -INT16_C(   9537)  },
      { -INT16_C(  29539), -INT16_C(  29907),  INT16_C(  26573),  INT16_C(   4862), -INT16_C(  28200), -INT16_C(  16755), -INT16_C(   2122), -INT16_C(  11964)  },
      {  INT8_C(    100),  INT8_C(     87),  INT8_C(     76),  INT8_C(     81),  INT8_C(     44),  INT8_C(     64), -INT8_C(     27),  INT8_C(      9)  } },
    { { -INT16_C(   1140), -INT16_C(   9092), -INT16_C(  26626),  INT16_C(  21004),  INT16_C(  12235), -INT16_C(   3154), -INT16_C(  13931),  INT16_C(  31373)  },
      {  INT16_C(   2858), -INT16_C(    940),  INT16_C(  20724),  INT16_C(  16815), -INT16_C(  20556),  INT16_C(  26572),  INT16_C(  14270),  INT16_C(  17145)  },
      { -INT8_C(     16), -INT8_C(     32),  INT8_C(     71),  INT8_C(     16),       INT8_MIN, -INT8_C(    116), -INT8_C(    110),  INT8_C(     56)  } },
    { { -INT16_C(  23074), -INT16_C(  26996),  INT16_C(   4526),  INT16_C(   1349), -INT16_C(   8754),  INT16_C(  10657),  INT16_C(  19463),  INT16_C(  30408)  },
      { -INT16_C(  19757), -INT16_C(  28653), -INT16_C(  21984),  INT16_C(  15377), -INT16_C(  24759),  INT16_C(  25557), -INT16_C(  10359), -INT16_C(  25279)  },
      { -INT8_C(     13),  INT8_C(      6),  INT8_C(    104), -INT8_C(     55),  INT8_C(     63), -INT8_C(     58),  INT8_C(    116), -INT8_C(     38)  } },
    { {  INT16_C(  32372),  INT16_C(  32113),  INT16_C(  23030), -INT16_C(  26077), -INT16_C(   7480), -INT16_C(  15356),  INT16_C(  20553),  INT16_C(  19760)  },
      {  INT16_C(  25860),  INT16_C(  30792), -INT16_C(  29580), -INT16_C(   5399),  INT16_C(  26520), -INT16_C(   9373), -INT16_C(  29052),  INT16_C(  26833)  },
      {  INT8_C(     25),  INT8_C(      5), -INT8_C(     50), -INT8_C(     81),  INT8_C(    123), -INT8_C(     23), -INT8_C(     62), -INT8_C(     28)  } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x8_t a = simde_vld1q_s16(test_vec[i].a);
    simde_int16x8_t b = simde_vld1q_s16(test_vec[i].b);
    simde_int8x8_t r = simde_vrsubhn_s16(a, b);

    simde_test_arm_neon_assert_equal_i8x8(r, simde_vld1_s8(test_vec[i].r));
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int16x8_t a = simde_test_arm_neon_random_i16x8();
    simde_int16x8_t b = simde_test_arm_neon_random_i16x8();
    simde_int8x8_t r = simde_vrsubhn_s16(a, b);

    simde_test_arm_neon_write_i16x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i16x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i8x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vrsubhn_s32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int32_t a[4];
    int32_t b[4];
    int16_t r[4];
  } test_vec[] = {
    { {  INT32_C(1812595993), -INT32_C( 667570689),  INT32_C( 929976915), -INT32_C(1112037646)  },
      { -INT32_C( 420586090),  INT32_C( 955493168), -INT32_C(1240693863),  INT32_C( 630754689)  },
      { -INT16_C(     31460), -INT16_C(     24766), -INT16_C(     32414), -INT16_C(     26593)  } },
    { {  INT32_C(1653728956), -INT32_C(1166867047), -INT32_C( 410466735),  INT32_C(1990199230)  },
      {  INT32_C(1117439081), -INT32_C( 433903381),  INT32_C(1330312943),  INT32_C( 502661614)  },
      {  INT16_C(      8183), -INT16_C(     11184), -INT16_C(     26562),  INT16_C(     22698)  } },
    { {  INT32_C(1227370350),  INT32_C(1202094101),  INT32_C(1855902672), -INT32_C(1132663354)  },
      { -INT32_C(1821465079), -INT32_C( 646635233),  INT32_C( 164397446), -INT32_C(1082154980)  },
      { -INT16_C(     19014),  INT16_C(     28209),  INT16_C(     25810), -INT16_C(       771)  } },
    { { -INT32_C(2038980475),  INT32_C(1726066676),  INT32_C(1672820009),  INT32_C(1817557340)  },
      {  INT32_C( 663258981), -INT32_C(1055985839), -INT32_C(  57347798),  INT32_C( 547465596)  },
      {  INT16_C(     24303), -INT16_C(     23085),  INT16_C(     26400),  INT16_C(     19380)  } },
    { { -INT32_C(1997625374), -INT32_C(2093685407), -INT32_C(1254548881), -INT32_C(2146851755)  },
      { -INT32_C(1874675543),  INT32_C(1522988084), -INT32_C(1415862084),  INT32_C(  42689605)  },
      { -INT16_C(      1876),  INT16_C(     10350),  INT16_C(      2461),  INT16_C(     32126)  } },
    { { -INT32_C(1987048678), -INT32_C( 616391684),  INT32_C( 981121408), -INT32_C(1218383321)  },
      { -INT32_C( 546058595), -INT32_C(2076611794), -INT32_C( 884668964),  INT32_C( 291582647)  },
      { -INT16_C(     21988),  INT16_C(     22281),  INT16_C(     28470), -INT16_C(     23040)  } },
    { { -INT32_C(2043385215),  INT32_C(1957693319),  INT32_C( 927930365), -INT32_C(1269369000)  },
      {  INT32_C( 195513466),  INT32_C(2020898934), -INT32_C(1610338607),  INT32_C( 111181957)  },
      {  INT16_C(     31373), -INT16_C(       964), -INT16_C(     26805), -INT16_C(     21066)  } },
    { { -INT32_C( 438254734),  INT32_C(  48171334), -INT32_C( 393918305),  INT32_C(1540695454)  },
      { -INT32_C(1959842633), -INT32_C(1766366061),  INT32_C( 903709532), -INT32_C(1070121217)  },
      {  INT16_C(     23218),  INT16_C(     27688), -INT16_C(     19800), -INT16_C(     25698)  } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x4_t a = simde_vld1q_s32(test_vec[i].a);
    simde_int32x4_t b = simde_vld1q_s32(test_vec[i].b);
    simde_int16x4_t r = simde_vrsubhn_s32(a, b);

    simde_test_arm_neon_assert_equal_i16x4(r, simde_vld1_s16(test_vec[i].r));
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int32x4_t a = simde_test_arm_neon_random_i32x4();
    simde_int32x4_t b = simde_test_arm_neon_random_i32x4();
    simde_int16x4_t r = simde_vrsubhn_s32(a, b);

    simde_test_arm_neon_write_i32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i16x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vrsubhn_s64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int64_t a[2];
    int64_t b[2];
    int32_t r[2];
  } test_vec[] = {
    { { -INT64_C( 7131656646972370489), -INT64_C( 9191719478619199873)  },
      {  INT64_C( 6956781457684521314), -INT64_C( 8857608276428189746)  },
      {  INT32_C(          1014747184), -INT32_C(            77791326)  } },
    { {  INT64_C( 5467516521056656280), -INT64_C( 5805162430751730775)  },
      {  INT64_C( 7753254591744264402),  INT64_C( 2694334893554550518)  },
      { -INT32_C(           532189866), -INT32_C(          1978943433)  } },
    { {  INT64_C( 2528882371772547758),  INT64_C( 2442999325206047751)  },
      { -INT64_C( 2912812053305232400), -INT64_C( 4780790296547683821)  },
      {  INT32_C(          1266993216),  INT32_C(          1681919587)  } },
    { {  INT64_C( 5312513145232874807),  INT64_C( 5345053565558734413)  },
      {  INT64_C( 2551668690573666092),  INT64_C( 1866764780563808235)  },
      {  INT32_C(           642809191),  INT32_C(           809852217)  } },
    { { -INT64_C( 6982640720335884570), -INT64_C(  553324913872001245)  },
      { -INT64_C( 4454923573749713898),  INT64_C( 8917356586784945114)  },
      { -INT32_C(           588530010),  INT32_C(          2089902426)  } },
    { {  INT64_C( 5067003250906428870), -INT64_C(  866627165876107086)  },
      { -INT64_C( 7807865972529963603), -INT64_C( 4443756904747231981)  },
      { -INT32_C(          1297303208),  INT32_C(           832865420)  } },
    { {  INT64_C( 8070297654783732279),  INT64_C( 4172239274647255845)  },
      { -INT64_C( 5873247660730130865),  INT64_C( 1169429670015049654)  },
      { -INT32_C(          1048482665),  INT32_C(           699146093)  } },
    { {  INT64_C( 8748447386439770518), -INT64_C( 5024017480446161880)  },
      { -INT64_C( 1171128945334562910),  INT64_C( 2824347558001420556)  },
      { -INT32_C(          1985385954), -INT32_C(          1827339884)  } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int64x2_t a = simde_vld1q_s64(test_vec[i].a);
    simde_int64x2_t b = simde_vld1q_s64(test_vec[i].b);
    simde_int32x2_t r = simde_vrsubhn_s64(a, b);

    simde_test_arm_neon_assert_equal_i32x2(r, simde_vld1_s32(test_vec[i].r));
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int64x2_t a = simde_test_arm_neon_random_i64x2();
    simde_int64x2_t b = simde_test_arm_neon_random_i64x2();
    simde_int32x2_t r = simde_vrsubhn_s64(a, b);

    simde_test_arm_neon_write_i64x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i64x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i32x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vrsubhn_u16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint16_t a[8];
    uint16_t b[8];
    uint8_t r[8];
  } test_vec[] = {
    { {  UINT16_C(  12161),  UINT16_C(  18617),  UINT16_C(  52789),  UINT16_C(  32554),  UINT16_C(  56627),  UINT16_C(  51906),  UINT16_C(  34962),  UINT16_C(  25867)  },
      {  UINT16_C(  49337),  UINT16_C(  32743),  UINT16_C(  49165),  UINT16_C(  22352),  UINT16_C(  18327),  UINT16_C(  48111),  UINT16_C(   8359),  UINT16_C(  29201)  },
      {  UINT8_C(    111),  UINT8_C(    201),  UINT8_C(     14),  UINT8_C(     40),  UINT8_C(    150),  UINT8_C(     15),  UINT8_C(    104),  UINT8_C(    243)  } },
    { {  UINT16_C(    933),  UINT16_C(  64397),  UINT16_C(  24717),  UINT16_C(  49563),  UINT16_C(   1496),  UINT16_C(  39516),  UINT16_C(  40868),  UINT16_C(  40604)  },
      {  UINT16_C(  53778),  UINT16_C(  12903),  UINT16_C(   9411),  UINT16_C(  46927),  UINT16_C(   6143),  UINT16_C(  21411),  UINT16_C(  52782),  UINT16_C(  41568)  },
      {  UINT8_C(     50),  UINT8_C(    201),  UINT8_C(     60),  UINT8_C(     10),  UINT8_C(    238),  UINT8_C(     71),  UINT8_C(    209),  UINT8_C(    252)  } },
    { {  UINT16_C(  53842),  UINT16_C(  11057),  UINT16_C(   8569),  UINT16_C(  32369),  UINT16_C(  11083),  UINT16_C(  45511),  UINT16_C(  41076),  UINT16_C(  36202)  },
      {  UINT16_C(   4513),  UINT16_C(  33804),  UINT16_C(  57068),  UINT16_C(   8207),  UINT16_C(  33162),  UINT16_C(  35568),  UINT16_C(  20399),  UINT16_C(  28487)  },
      {  UINT8_C(    193),  UINT8_C(    167),  UINT8_C(     67),  UINT8_C(     94),  UINT8_C(    170),  UINT8_C(     39),  UINT8_C(     81),  UINT8_C(     30)  } },
    { {  UINT16_C(  56256),  UINT16_C(  57420),  UINT16_C(  48695),  UINT16_C(  54799),  UINT16_C(  19578),  UINT16_C(  52367),  UINT16_C(  53650),  UINT16_C(  42276)  },
      {  UINT16_C(  54033),  UINT16_C(  28158),  UINT16_C(  54584),  UINT16_C(  64405),  UINT16_C(  41000),  UINT16_C(  15510),  UINT16_C(  61147),  UINT16_C(  15301)  },
      {  UINT8_C(      9),  UINT8_C(    114),  UINT8_C(    233),  UINT8_C(    218),  UINT8_C(    172),  UINT8_C(    144),  UINT8_C(    227),  UINT8_C(    105)  } },
    { {  UINT16_C(  61976),  UINT16_C(    423),  UINT16_C(  25133),  UINT16_C(  49612),  UINT16_C(  53580),  UINT16_C(  29501),  UINT16_C(    116),  UINT16_C(  24297)  },
      {  UINT16_C(  47876),  UINT16_C(  38860),  UINT16_C(   9421),  UINT16_C(  35565),  UINT16_C(  21120),  UINT16_C(  45197),  UINT16_C(  26024),  UINT16_C(  31506)  },
      {  UINT8_C(     55),  UINT8_C(    106),  UINT8_C(     61),  UINT8_C(     55),  UINT8_C(    127),  UINT8_C(    195),  UINT8_C(    155),  UINT8_C(    228)  } },
    { {  UINT16_C(  23831),  UINT16_C(  13364),  UINT16_C(  50466),  UINT16_C(  47525),  UINT16_C(  46256),  UINT16_C(  59041),  UINT16_C(  48757),  UINT16_C(  33825)  },
      {  UINT16_C(  27017),  UINT16_C(  56722),  UINT16_C(  18848),  UINT16_C(  31122),  UINT16_C(  15506),  UINT16_C(  10463),  UINT16_C(  64239),  UINT16_C(  24932)  },
      {  UINT8_C(    244),  UINT8_C(     87),  UINT8_C(    124),  UINT8_C(     64),  UINT8_C(    120),  UINT8_C(    190),  UINT8_C(    196),  UINT8_C(     35)  } },
    { {  UINT16_C(   4668),  UINT16_C(  47405),  UINT16_C(   1280),  UINT16_C(  37355),  UINT16_C(  44987),  UINT16_C(  61159),  UINT16_C(  58037),  UINT16_C(   9495)  },
      {  UINT16_C(  30152),  UINT16_C(  23980),  UINT16_C(  29476),  UINT16_C(  55866),  UINT16_C(   6527),  UINT16_C(  16904),  UINT16_C(  53829),  UINT16_C(  44599)  },
      {  UINT8_C(    156),  UINT8_C(     92),  UINT8_C(    146),  UINT8_C(    184),  UINT8_C(    150),  UINT8_C(    173),  UINT8_C(     16),  UINT8_C(    119)  } },
    { {  UINT16_C(   2917),  UINT16_C(  65077),  UINT16_C(  49136),  UINT16_C(  55605),  UINT16_C(  20567),  UINT16_C(  28302),  UINT16_C(   2185),  UINT16_C(  41419)  },
      {  UINT16_C(  51639),  UINT16_C(  17009),  UINT16_C(  41304),  UINT16_C(  39702),  UINT16_C(  58523),  UINT16_C(  13517),  UINT16_C(  31125),  UINT16_C(  63522)  },
      {  UINT8_C(     66),  UINT8_C(    188),  UINT8_C(     31),  UINT8_C(     62),  UINT8_C(    108),  UINT8_C(     58),  UINT8_C(    143),  UINT8_C(    170)  } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint16x8_t a = simde_vld1q_u16(test_vec[i].a);
    simde_uint16x8_t b = simde_vld1q_u16(test_vec[i].b);
    simde_uint8x8_t r = simde_vrsubhn_u16(a, b);

    simde_test_arm_neon_assert_equal_u8x8(r, simde_vld1_u8(test_vec[i].r));
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint16x8_t a = simde_test_arm_neon_random_u16x8();
    simde_uint16x8_t b = simde_test_arm_neon_random_u16x8();
    simde_uint8x8_t r = simde_vrsubhn_u16(a, b);

    simde_test_arm_neon_write_u16x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u16x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u8x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vrsubhn_u32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint32_t a[4];
    uint32_t b[4];
    uint16_t r[4];
  } test_vec[] = {
    { {  UINT32_C( 584512549),  UINT32_C( 242317329),  UINT32_C(4038352609),  UINT32_C(1922938507)  },
      {  UINT32_C(  86125608),  UINT32_C(1276565899),  UINT32_C(1508346116),  UINT32_C(1339170290)  },
      {  UINT16_C(      7605),  UINT16_C(     49755),  UINT16_C(     38605),  UINT16_C(      8908)  } },
    { {  UINT32_C( 890467764),  UINT32_C( 183007246),  UINT32_C(4011717609),  UINT32_C( 913780066)  },
      {  UINT32_C(2320321187),  UINT32_C(2559194385),  UINT32_C(2289723378),  UINT32_C(2752114807)  },
      {  UINT16_C(     43718),  UINT16_C(     29278),  UINT16_C(     26276),  UINT16_C(     37485)  } },
    { {  UINT32_C(1047477475),  UINT32_C(3144558603),  UINT32_C(1468018416),  UINT32_C(1111064548)  },
      {  UINT32_C(2437846973),  UINT32_C(1713756673),  UINT32_C(1570329625),  UINT32_C( 889747248)  },
      {  UINT16_C(     44321),  UINT16_C(     21832),  UINT16_C(     63975),  UINT16_C(      3377)  } },
    { {  UINT32_C(3841402048),  UINT32_C(1239918712),  UINT32_C(3441073611),  UINT32_C(3082239364)  },
      {  UINT32_C(3647154593),  UINT32_C(3728341984),  UINT32_C(1420184183),  UINT32_C( 354953863)  },
      {  UINT16_C(      2964),  UINT16_C(     27566),  UINT16_C(     30836),  UINT16_C(     41615)  } },
    { {  UINT32_C(1660863637),  UINT32_C(3738580126),  UINT32_C(1177643969),  UINT32_C(3262696681)  },
      {  UINT32_C(1896420512),  UINT32_C(1257348162),  UINT32_C(2435569234),  UINT32_C(3525887081)  },
      {  UINT16_C(     61942),  UINT16_C(     37861),  UINT16_C(     46342),  UINT16_C(     61520)  } },
    { {  UINT32_C(3096824198),  UINT32_C(3621319602),  UINT32_C(3142426518),  UINT32_C(3645582469)  },
      {  UINT32_C( 796952733),  UINT32_C(2091671964),  UINT32_C(1100615639),  UINT32_C(2144998799)  },
      {  UINT16_C(     35093),  UINT16_C(     23341),  UINT16_C(     31156),  UINT16_C(     22897)  } },
    { {  UINT32_C(1396282785),  UINT32_C(3730226499),  UINT32_C(3654754584),  UINT32_C( 959659968)  },
      {  UINT32_C(1651744654),  UINT32_C(4017901029),  UINT32_C(1629456713),  UINT32_C(4160987821)  },
      {  UINT16_C(     61638),  UINT16_C(     61146),  UINT16_C(     30904),  UINT16_C(     16688)  } },
    { {  UINT32_C(1715960303),  UINT32_C(4039562533),  UINT32_C(3828483314),  UINT32_C(2407488645)  },
      {  UINT32_C(3912234216),  UINT32_C(2924013893),  UINT32_C( 423861645),  UINT32_C(3779652142)  },
      {  UINT16_C(     32024),  UINT16_C(     17022),  UINT16_C(     51950),  UINT16_C(     44598)  } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint32x4_t a = simde_vld1q_u32(test_vec[i].a);
    simde_uint32x4_t b = simde_vld1q_u32(test_vec[i].b);
    simde_uint16x4_t r = simde_vrsubhn_u32(a, b);

    simde_test_arm_neon_assert_equal_u16x4(r, simde_vld1_u16(test_vec[i].r));
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint32x4_t a = simde_test_arm_neon_random_u32x4();
    simde_uint32x4_t b = simde_test_arm_neon_random_u32x4();
    simde_uint16x4_t r = simde_vrsubhn_u32(a, b);

    simde_test_arm_neon_write_u32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u16x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vrsubhn_u64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint64_t a[2];
    uint64_t b[2];
    uint32_t r[2];
  } test_vec[] = {
    { {  UINT64_C( 5720579107695434868),  UINT64_C(10158864097640915505)  },
      {  UINT64_C( 2944425187806881986),  UINT64_C( 6881001908194755993)  },
      {  UINT32_C(           646373704),  UINT32_C(           763186763)  } },
    { {  UINT64_C(14151069090009110415),  UINT64_C( 3427730040787600922)  },
      {  UINT64_C( 1162921553288783224),  UINT64_C( 6896780722481148156)  },
      {  UINT32_C(          3024038751),  UINT32_C(          3487265993)  } },
    { {  UINT64_C( 5957476926263911949),  UINT64_C( 7246487387568598101)  },
      {  UINT64_C( 7480154478098634778),  UINT64_C( 7158156165420539990)  },
      {  UINT32_C(          3940441302),  UINT32_C(            20566215)  } },
    { {  UINT64_C( 7814423941832542988),  UINT64_C(14658162422605217111)  },
      {  UINT64_C(14460842918693877557),  UINT64_C(16532515342099580551)  },
      {  UINT32_C(          2747477288),  UINT32_C(          3858560499)  } },
    { {  UINT64_C(15985923743401242236),  UINT64_C(14565191298281482105)  },
      {  UINT64_C( 3644320369892282462),  UINT64_C(10380643387119289025)  },
      {  UINT32_C(          2873503457),  UINT32_C(           974290984)  } },
    { {  UINT64_C(15842686916909780856),  UINT64_C( 6007490528874810545)  },
      {  UINT64_C( 5998344717132929260),  UINT64_C(17066458207901803814)  },
      {  UINT32_C(          2292064531),  UINT32_C(          1720100733)  } },
    { {  UINT64_C( 8906256487824497186),  UINT64_C(16273672314943311094)  },
      {  UINT64_C(14134855410931785930),  UINT64_C( 2718685512824199260)  },
      {  UINT32_C(          3077589243),  UINT32_C(          3156016302)  } },
    { {  UINT64_C(11260902580370141307),  UINT64_C( 6856970678142061529)  },
      {  UINT64_C( 4916313494196341874),  UINT64_C(15477497448153835858)  },
      {  UINT32_C(          1477214761),  UINT32_C(          2287844500)  } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint64x2_t a = simde_vld1q_u64(test_vec[i].a);
    simde_uint64x2_t b = simde_vld1q_u64(test_vec[i].b);
    simde_uint32x2_t r = simde_vrsubhn_u64(a, b);

    simde_test_arm_neon_assert_equal_u32x2(r, simde_vld1_u32(test_vec[i].r));
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint64x2_t a = simde_test_arm_neon_random_u64x2();
    simde_uint64x2_t b = simde_test_arm_neon_random_u64x2();
    simde_uint32x2_t r = simde_vrsubhn_u64(a, b);

    simde_test_arm_neon_write_u64x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u64x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(vrsubhn_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vrsubhn_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vrsubhn_s64)

SIMDE_TEST_FUNC_LIST_ENTRY(vrsubhn_u16)
SIMDE_TEST_FUNC_LIST_ENTRY(vrsubhn_u32)
SIMDE_TEST_FUNC_LIST_ENTRY(vrsubhn_u64)
SIMDE_TEST_FUNC_LIST_END

#include "test-neon-footer.h"
