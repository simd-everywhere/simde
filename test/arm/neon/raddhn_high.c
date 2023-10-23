#define SIMDE_TEST_ARM_NEON_INSN raddhn_high

#include "test-neon.h"
#include "../../../simde/arm/neon/raddhn_high.h"

static int
test_simde_vraddhn_high_s16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int8_t r_[8];
    int16_t a[8];
    int16_t b[8];
    int8_t r[16];
  } test_vec[] = {
    { {   INT8_C(     15),  -INT8_C(     19),  -INT8_C(     48),  -INT8_C(     13),   INT8_C(     45),  -INT8_C(     48),  -INT8_C(     26),   INT8_C(     33)  },
      { -INT16_C(  12095),  INT16_C(  17211), -INT16_C(   2398),  INT16_C(  19853), -INT16_C(   6852),  INT16_C(  27120),  INT16_C(  31418),  INT16_C(  18743)  },
      {  INT16_C(   5866),  INT16_C(  24735), -INT16_C(  32002),  INT16_C(  26625),  INT16_C(  15989), -INT16_C(  12779), -INT16_C(  11120), -INT16_C(  30611) },
      {   INT8_C(     15),  -INT8_C(     19),  -INT8_C(     48),  -INT8_C(     13),   INT8_C(     45),  -INT8_C(     48),  -INT8_C(     26),   INT8_C(     33),  -INT8_C(     24),  -INT8_C(     92),   INT8_C(    122),  -INT8_C(     74),   INT8_C(     36),   INT8_C(     56),   INT8_C(     79),  -INT8_C(     46)  } },
    { {  -INT8_C(     49),  -INT8_C(    118),  -INT8_C(      5),  -INT8_C(     36),   INT8_C(    117),  -INT8_C(     43),   INT8_C(     69),   INT8_C(    124)  },
      { -INT16_C(  16110),  INT16_C(   1089), -INT16_C(  23667),  INT16_C(  18054), -INT16_C(  13983), -INT16_C(  27284),  INT16_C(  13014),  INT16_C(  15012)  },
      {  INT16_C(  15410), -INT16_C(   3301), -INT16_C(  20015),  INT16_C(  13021), -INT16_C(  23055),  INT16_C(  31860), -INT16_C(  16803), -INT16_C(  12129) },
      {  -INT8_C(     49),  -INT8_C(    118),  -INT8_C(      5),  -INT8_C(     36),   INT8_C(    117),  -INT8_C(     43),   INT8_C(     69),   INT8_C(    124),  -INT8_C(      3),  -INT8_C(      9),   INT8_C(     85),   INT8_C(    121),   INT8_C(    111),   INT8_C(     18),  -INT8_C(     15),   INT8_C(     11)  } },
    { {  -INT8_C(     80),   INT8_C(    118),  -INT8_C(     21),  -INT8_C(     40),  -INT8_C(     62),  -INT8_C(    105),   INT8_C(     54),  -INT8_C(     23)  },
      {  INT16_C(  14270), -INT16_C(  13117), -INT16_C(  10907),  INT16_C(   7523), -INT16_C(  29065), -INT16_C(  18066),  INT16_C(  27774),  INT16_C(  27516)  },
      { -INT16_C(   8467),  INT16_C(  24014),  INT16_C(  31552), -INT16_C(  26398),  INT16_C(   2507),  INT16_C(  19417),  INT16_C(  26328), -INT16_C(  29014) },
      {  -INT8_C(     80),   INT8_C(    118),  -INT8_C(     21),  -INT8_C(     40),  -INT8_C(     62),  -INT8_C(    105),   INT8_C(     54),  -INT8_C(     23),   INT8_C(     23),   INT8_C(     43),   INT8_C(     81),  -INT8_C(     74),  -INT8_C(    104),   INT8_C(      5),  -INT8_C(     45),  -INT8_C(      6)  } },
    { {  -INT8_C(    121),  -INT8_C(      5),   INT8_C(     14),   INT8_C(    123),  -INT8_C(     28),   INT8_C(     83),   INT8_C(     46),  -INT8_C(     41)  },
      { -INT16_C(  23781),  INT16_C(   4459), -INT16_C(   7012), -INT16_C(  27719),  INT16_C(   4462),  INT16_C(   5161),  INT16_C(  10500),  INT16_C(  15575)  },
      { -INT16_C(  21166),  INT16_C(   2663), -INT16_C(  30048), -INT16_C(  22763), -INT16_C(  10851), -INT16_C(   2881),  INT16_C(  16199),  INT16_C(   9949) },
      {  -INT8_C(    121),  -INT8_C(      5),   INT8_C(     14),   INT8_C(    123),  -INT8_C(     28),   INT8_C(     83),   INT8_C(     46),  -INT8_C(     41),   INT8_C(     80),   INT8_C(     28),   INT8_C(    111),   INT8_C(     59),  -INT8_C(     25),   INT8_C(      9),   INT8_C(    104),   INT8_C(    100)  } },
    { {  -INT8_C(     21),   INT8_C(     37),  -INT8_C(    111),  -INT8_C(     34),   INT8_C(     53),   INT8_C(     35),   INT8_C(    125),   INT8_C(      1)  },
      { -INT16_C(   6601),  INT16_C(  30366),  INT16_C(   8187), -INT16_C(  17595),  INT16_C(  20361),  INT16_C(  28645),  INT16_C(  22636),  INT16_C(   9236)  },
      { -INT16_C(  19082), -INT16_C(  23095),  INT16_C(   9752),  INT16_C(   1312), -INT16_C(  16805),  INT16_C(   4906), -INT16_C(   6993), -INT16_C(  11096) },
      {  -INT8_C(     21),   INT8_C(     37),  -INT8_C(    111),  -INT8_C(     34),   INT8_C(     53),   INT8_C(     35),   INT8_C(    125),   INT8_C(      1),  -INT8_C(    100),   INT8_C(     28),   INT8_C(     70),  -INT8_C(     64),   INT8_C(     14),  -INT8_C(    125),   INT8_C(     61),  -INT8_C(      7)  } },
    { {  -INT8_C(     45),   INT8_C(     48),   INT8_C(      0),  -INT8_C(     50),  -INT8_C(     71),   INT8_C(     39),   INT8_C(     35),   INT8_C(      0)  },
      { -INT16_C(  16149),  INT16_C(  24317), -INT16_C(  12198), -INT16_C(  29400),  INT16_C(  22461),  INT16_C(  28947), -INT16_C(  30952),  INT16_C(   6308)  },
      {  INT16_C(  18236), -INT16_C(    943),  INT16_C(  31257),  INT16_C(    601), -INT16_C(  30010), -INT16_C(   2903), -INT16_C(  25370), -INT16_C(   2531) },
      {  -INT8_C(     45),   INT8_C(     48),   INT8_C(      0),  -INT8_C(     50),  -INT8_C(     71),   INT8_C(     39),   INT8_C(     35),   INT8_C(      0),   INT8_C(      8),   INT8_C(     91),   INT8_C(     74),  -INT8_C(    112),  -INT8_C(     29),   INT8_C(    102),   INT8_C(     36),   INT8_C(     15)  } },
    { {   INT8_C(     96),  -INT8_C(     23),  -INT8_C(    112),   INT8_C(     70),  -INT8_C(     40),   INT8_C(     43),   INT8_C(      7),  -INT8_C(     66)  },
      { -INT16_C(   9336), -INT16_C(  24505),  INT16_C(  26635), -INT16_C(   6194),  INT16_C(   2886),  INT16_C(  11325),  INT16_C(  24921),  INT16_C(  17239)  },
      { -INT16_C(  10313),  INT16_C(  15520), -INT16_C(  28030),  INT16_C(   9813), -INT16_C(   5805),  INT16_C(  25109),  INT16_C(   2107),  INT16_C(  10636) },
      {   INT8_C(     96),  -INT8_C(     23),  -INT8_C(    112),   INT8_C(     70),  -INT8_C(     40),   INT8_C(     43),   INT8_C(      7),  -INT8_C(     66),  -INT8_C(     77),  -INT8_C(     35),  -INT8_C(      5),   INT8_C(     14),  -INT8_C(     11),  -INT8_C(    114),   INT8_C(    106),   INT8_C(    109)  } },
    { {  -INT8_C(     48),   INT8_C(      8),   INT8_C(    104),  -INT8_C(     17),   INT8_C(     53),   INT8_C(     86),  -INT8_C(     63),  -INT8_C(     74)  },
      { -INT16_C(  18853),  INT16_C(  18970),  INT16_C(   8488),  INT16_C(  27692), -INT16_C(  27894),  INT16_C(    685),  INT16_C(  28318), -INT16_C(  13629)  },
      {  INT16_C(  29901), -INT16_C(   3380), -INT16_C(  31158), -INT16_C(   1358), -INT16_C(  32145), -INT16_C(  27772),  INT16_C(  22434), -INT16_C(  14729) },
      {  -INT8_C(     48),   INT8_C(      8),   INT8_C(    104),  -INT8_C(     17),   INT8_C(     53),   INT8_C(     86),  -INT8_C(     63),  -INT8_C(     74),   INT8_C(     43),   INT8_C(     61),  -INT8_C(     89),   INT8_C(    103),   INT8_C(     21),  -INT8_C(    106),  -INT8_C(     58),  -INT8_C(    111)  } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int8x8_t r_ = simde_vld1_s8(test_vec[i].r_);
    simde_int16x8_t a = simde_vld1q_s16(test_vec[i].a);
    simde_int16x8_t b = simde_vld1q_s16(test_vec[i].b);
    simde_int8x16_t r = simde_vraddhn_high_s16(r_, a, b);

    simde_test_arm_neon_assert_equal_i8x16(r, simde_vld1q_s8(test_vec[i].r));
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int8x8_t r_ = simde_test_arm_neon_random_i8x8();
    simde_int16x8_t a = simde_test_arm_neon_random_i16x8();
    simde_int16x8_t b = simde_test_arm_neon_random_i16x8();
    simde_int8x16_t r = simde_vraddhn_high_s16(r_, a, b);

    simde_test_arm_neon_write_i8x8(2, r_, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i16x8(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i16x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i8x16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vraddhn_high_s32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int16_t r_[4];
    int32_t a[4];
    int32_t b[4];
    int16_t r[8];
  } test_vec[] = {
    { { -INT16_C(     27776),  INT16_C(     16425), -INT16_C(     28190),  INT16_C(      6709)  },
      { -INT32_C(2073946203), -INT32_C(1363725588), -INT32_C(2019342500), -INT32_C( 640904559)  },
      {  INT32_C( 881477788), -INT32_C( 142697688), -INT32_C(1708525767),  INT32_C(1635527412) },
      { -INT16_C(     27776),  INT16_C(     16425), -INT16_C(     28190),  INT16_C(      6709), -INT16_C(     18196), -INT16_C(     22986),  INT16_C(      8653),  INT16_C(     15177)  } },
    { { -INT16_C(     27280), -INT16_C(      6940), -INT16_C(      2049), -INT16_C(     22912)  },
      {  INT32_C( 709292876),  INT32_C(1720435809),  INT32_C(2140505914), -INT32_C( 286823063)  },
      {  INT32_C( 439340421),  INT32_C( 701800638),  INT32_C( 103055639), -INT32_C( 469027266) },
      { -INT16_C(     27280), -INT16_C(      6940), -INT16_C(      2049), -INT16_C(     22912),  INT16_C(     17527), -INT16_C(     28576), -INT16_C(     31302), -INT16_C(     11533)  } },
    { {  INT16_C(     25933), -INT16_C(     21517),  INT16_C(       243),  INT16_C(     15365)  },
      { -INT32_C(1427898835),  INT32_C( 646153999),  INT32_C(  79164467), -INT32_C(1917300873)  },
      {  INT32_C( 146363064),  INT32_C( 209990670),  INT32_C( 540618427), -INT32_C( 131110686) },
      {  INT16_C(     25933), -INT16_C(     21517),  INT16_C(       243),  INT16_C(     15365), -INT16_C(     19555),  INT16_C(     13064),  INT16_C(      9457), -INT16_C(     31256)  } },
    { {  INT16_C(      9500),  INT16_C(      8869),  INT16_C(      3952),  INT16_C(     28525)  },
      { -INT32_C( 309207677), -INT32_C(1888868347),  INT32_C(1186727381),  INT32_C(1604773216)  },
      {  INT32_C( 972938125),  INT32_C(1919153794), -INT32_C( 117373942),  INT32_C(1664140487) },
      {  INT16_C(      9500),  INT16_C(      8869),  INT16_C(      3952),  INT16_C(     28525),  INT16_C(     10128),  INT16_C(       462),  INT16_C(     16317), -INT16_C(     15656)  } },
    { {  INT16_C(      4181),  INT16_C(     25047), -INT16_C(     30655), -INT16_C(     17944)  },
      { -INT32_C(1606382942),  INT32_C( 793175988),  INT32_C( 477026851),  INT32_C(1629245270)  },
      {  INT32_C(1708901256),  INT32_C(1914777322), -INT32_C( 521976337),  INT32_C(1565363748) },
      {  INT16_C(      4181),  INT16_C(     25047), -INT16_C(     30655), -INT16_C(     17944),  INT16_C(      1564), -INT16_C(     24216), -INT16_C(       686), -INT16_C(     16790)  } },
    { { -INT16_C(     13165), -INT16_C(      4492),  INT16_C(      5206),  INT16_C(     12539)  },
      {  INT32_C( 900494898),  INT32_C(1609560050), -INT32_C(1696559543), -INT32_C(1701266285)  },
      {  INT32_C(1115327487), -INT32_C( 521044433),  INT32_C(1199557110), -INT32_C( 199795036) },
      { -INT16_C(     13165), -INT16_C(      4492),  INT16_C(      5206),  INT16_C(     12539),  INT16_C(     30759),  INT16_C(     16609), -INT16_C(      7584), -INT16_C(     29008)  } },
    { { -INT16_C(     11831),  INT16_C(     30921),  INT16_C(     20387), -INT16_C(      7959)  },
      {  INT32_C( 769588418),  INT32_C(1958588476),  INT32_C(1142744858), -INT32_C( 320146418)  },
      {  INT32_C( 226742139), -INT32_C(1855718613),  INT32_C( 591576080), -INT32_C( 375028857) },
      { -INT16_C(     11831),  INT16_C(     30921),  INT16_C(     20387), -INT16_C(      7959),  INT16_C(     15203),  INT16_C(      1570),  INT16_C(     26464), -INT16_C(     10608)  } },
    { {  INT16_C(     27776),  INT16_C(     29860),  INT16_C(     12208), -INT16_C(     10081)  },
      {  INT32_C(1533933143),  INT32_C(1029248519),  INT32_C( 917892597),  INT32_C(2126715181)  },
      { -INT32_C( 678177319), -INT32_C(1186000480), -INT32_C( 443480976),  INT32_C(1722207944) },
      {  INT16_C(     27776),  INT16_C(     29860),  INT16_C(     12208), -INT16_C(     10081),  INT16_C(     13058), -INT16_C(      2392),  INT16_C(      7239), -INT16_C(      6806)  } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x4_t r_ = simde_vld1_s16(test_vec[i].r_);
    simde_int32x4_t a = simde_vld1q_s32(test_vec[i].a);
    simde_int32x4_t b = simde_vld1q_s32(test_vec[i].b);
    simde_int16x8_t r = simde_vraddhn_high_s32(r_, a, b);

    simde_test_arm_neon_assert_equal_i16x8(r, simde_vld1q_s16(test_vec[i].r));
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int16x4_t r_ = simde_test_arm_neon_random_i16x4();
    simde_int32x4_t a = simde_test_arm_neon_random_i32x4();
    simde_int32x4_t b = simde_test_arm_neon_random_i32x4();
    simde_int16x8_t r = simde_vraddhn_high_s32(r_, a, b);

    simde_test_arm_neon_write_i16x4(2, r_, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i32x4(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i16x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vraddhn_high_s64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int32_t r_[2];
    int64_t a[2];
    int64_t b[2];
    int32_t r[4];
  } test_vec[] = {
    { {  INT32_C( 197796418),  INT32_C( 601210734)  },
      {  INT64_C(6827770305986114088), -INT64_C(3424434265917398540)  },
      { -INT64_C(4870080611125820418), -INT64_C(1280185501390225677) },
      {  INT32_C( 197796418),  INT32_C( 601210734),  INT32_C( 455810152), -INT32_C(1095379649)  } },
    { { -INT32_C(1222698691), -INT32_C( 343308185)  },
      { -INT64_C(1578692060818245119), -INT64_C(6924763905932136884)  },
      {  INT64_C(1395720023092767828),  INT64_C(3170804204799828580) },
      { -INT32_C(1222698691), -INT32_C( 343308185), -INT32_C(  42601497), -INT32_C( 874036853)  } },
    { {  INT32_C(1845387845),  INT32_C(  93834540)  },
      {  INT64_C(3027541176452433987), -INT64_C(1869318515588614046)  },
      { -INT64_C(5554700006883697809), -INT64_C(4084970758226857716) },
      {  INT32_C(1845387845),  INT32_C(  93834540), -INT32_C( 588400017), -INT32_C(1386341004)  } },
    { {  INT32_C(1156951160), -INT32_C( 995571895)  },
      { -INT64_C(5015092532983367815), -INT64_C(3034235131876238016)  },
      {  INT64_C(7727319190775619735),  INT64_C(5183591802858582339) },
      {  INT32_C(1156951160), -INT32_C( 995571895),  INT32_C( 631489478),  INT32_C( 500436097)  } },
    { {  INT32_C( 565302416), -INT32_C(1351836223)  },
      { -INT64_C(2072574158439994684),  INT64_C(3072145173928151423)  },
      {  INT64_C(6430252040398349117),  INT64_C(4075474499164742695) },
      {  INT32_C( 565302416), -INT32_C(1351836223),  INT32_C(1014600946),  INT32_C(1664184889)  } },
    { { -INT32_C(2122233933),  INT32_C(1928251825)  },
      { -INT64_C(4381041607828903039),  INT64_C(6832580255290064194)  },
      { -INT64_C(2447376711268383613),  INT64_C(6815464404358872476) },
      { -INT32_C(2122233933),  INT32_C(1928251825), -INT32_C(1589865032), -INT32_C(1117284273)  } },
    { { -INT32_C(1558854147), -INT32_C( 463274853)  },
      { -INT64_C(5259775076737191257), -INT64_C(2017160973710465181)  },
      { -INT64_C(2456389913055062980),  INT64_C(1004965748914492018) },
      { -INT32_C(1558854147), -INT32_C( 463274853), -INT32_C(1796559661), -INT32_C( 235670066)  } },
    { { -INT32_C( 551418001),  INT32_C( 490707555)  },
      {  INT64_C(5975796747031062393), -INT64_C(6489678503113015990)  },
      { -INT64_C(2243550412969459196), -INT64_C(852550114939876794) },
      { -INT32_C( 551418001),  INT32_C( 490707555),  INT32_C( 868981316), -INT32_C(1709495815)  } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x2_t r_ = simde_vld1_s32(test_vec[i].r_);
    simde_int64x2_t a = simde_vld1q_s64(test_vec[i].a);
    simde_int64x2_t b = simde_vld1q_s64(test_vec[i].b);
    simde_int32x4_t r = simde_vraddhn_high_s64(r_, a, b);

    simde_test_arm_neon_assert_equal_i32x4(r, simde_vld1q_s32(test_vec[i].r));
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int32x2_t r_ = simde_test_arm_neon_random_i32x2();
    simde_int64x2_t a = simde_test_arm_neon_random_i64x2();
    simde_int64x2_t b = simde_test_arm_neon_random_i64x2();
    simde_int32x4_t r = simde_vraddhn_high_s64(r_, a, b);

    simde_test_arm_neon_write_i32x2(2, r_, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i64x2(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i64x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vraddhn_high_u16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint8_t r_[8];
    uint16_t a[8];
    uint16_t b[8];
    uint8_t r[16];
  } test_vec[] = {
    { {  UINT8_C(  248),  UINT8_C(  188),  UINT8_C(   97),  UINT8_C(   28),  UINT8_C(  205),  UINT8_C(   80),  UINT8_C(   73),  UINT8_C(  137)  },
      {  UINT16_C( 6831),  UINT16_C(57295),  UINT16_C(13995),  UINT16_C(51267),  UINT16_C( 2675),  UINT16_C(45311),  UINT16_C(15899),  UINT16_C(40484)  },
      {  UINT16_C(13621),  UINT16_C(62747),  UINT16_C(55364),  UINT16_C(50561),  UINT16_C( 6210),  UINT16_C(10039),  UINT16_C(54493),  UINT16_C( 4603)  },
      {  UINT8_C(  248),  UINT8_C(  188),  UINT8_C(   97),  UINT8_C(   28),  UINT8_C(  205),  UINT8_C(   80),  UINT8_C(   73),  UINT8_C(  137),  UINT8_C(   80),  UINT8_C(  213),  UINT8_C(   15),  UINT8_C(  142),  UINT8_C(   35),  UINT8_C(  216),  UINT8_C(   19),  UINT8_C(  176)  } },
    { {  UINT8_C(  179),  UINT8_C(  238),  UINT8_C(  151),  UINT8_C(  173),  UINT8_C(  227),  UINT8_C(    0),  UINT8_C(  171),  UINT8_C(  109)  },
      {  UINT16_C(43179),  UINT16_C(29009),  UINT16_C(62133),  UINT16_C(47539),  UINT16_C( 5586),  UINT16_C(25158),  UINT16_C(18035),  UINT16_C(31969)  },
      {  UINT16_C(27797),  UINT16_C(35816),  UINT16_C(23267),  UINT16_C(29229),  UINT16_C(34402),  UINT16_C(51753),  UINT16_C(53150),  UINT16_C(28175)  },
      {  UINT8_C(  179),  UINT8_C(  238),  UINT8_C(  151),  UINT8_C(  173),  UINT8_C(  227),  UINT8_C(    0),  UINT8_C(  171),  UINT8_C(  109),  UINT8_C(   21),  UINT8_C(  253),  UINT8_C(   78),  UINT8_C(   44),  UINT8_C(  156),  UINT8_C(   44),  UINT8_C(   22),  UINT8_C(  235)  } },
    { {  UINT8_C(   37),  UINT8_C(  127),  UINT8_C(   87),  UINT8_C(   17),  UINT8_C(  135),  UINT8_C(   44),  UINT8_C(  118),  UINT8_C(   68)  },
      {  UINT16_C(19129),  UINT16_C(46467),  UINT16_C( 2498),  UINT16_C(35093),  UINT16_C(43496),  UINT16_C(34612),  UINT16_C(  934),  UINT16_C(34885)  },
      {  UINT16_C(45931),  UINT16_C(13891),  UINT16_C(17386),  UINT16_C(62037),  UINT16_C(50957),  UINT16_C(62197),  UINT16_C(53339),  UINT16_C(61720)  },
      {  UINT8_C(   37),  UINT8_C(  127),  UINT8_C(   87),  UINT8_C(   17),  UINT8_C(  135),  UINT8_C(   44),  UINT8_C(  118),  UINT8_C(   68),  UINT8_C(  254),  UINT8_C(  236),  UINT8_C(   78),  UINT8_C(  123),  UINT8_C(  113),  UINT8_C(  122),  UINT8_C(  212),  UINT8_C(  121)  } },
    { {  UINT8_C(  213),  UINT8_C(  157),  UINT8_C(  114),  UINT8_C(  125),  UINT8_C(   50),  UINT8_C(  125),  UINT8_C(  116),  UINT8_C(  134)  },
      {  UINT16_C(34704),  UINT16_C(26249),  UINT16_C(40822),  UINT16_C(21393),  UINT16_C(40953),  UINT16_C( 3885),  UINT16_C(41658),  UINT16_C( 3130)  },
      {  UINT16_C(42703),  UINT16_C(33844),  UINT16_C(26839),  UINT16_C(45040),  UINT16_C(55653),  UINT16_C(24812),  UINT16_C(42037),  UINT16_C(11219)  },
      {  UINT8_C(  213),  UINT8_C(  157),  UINT8_C(  114),  UINT8_C(  125),  UINT8_C(   50),  UINT8_C(  125),  UINT8_C(  116),  UINT8_C(  134),  UINT8_C(   46),  UINT8_C(  235),  UINT8_C(    8),  UINT8_C(    4),  UINT8_C(  121),  UINT8_C(  112),  UINT8_C(   71),  UINT8_C(   56)  } },
    { {  UINT8_C(  247),  UINT8_C(  189),  UINT8_C(  115),  UINT8_C(  214),  UINT8_C(  169),  UINT8_C(  148),  UINT8_C(   48),  UINT8_C(   97)  },
      {  UINT16_C( 4319),  UINT16_C( 5865),  UINT16_C(60338),  UINT16_C(56217),  UINT16_C(36234),  UINT16_C(59539),  UINT16_C(53208),  UINT16_C(51404)  },
      {  UINT16_C( 4908),  UINT16_C( 3243),  UINT16_C(37878),  UINT16_C(25620),  UINT16_C(20768),  UINT16_C(44230),  UINT16_C(63129),  UINT16_C(14658)  },
      {  UINT8_C(  247),  UINT8_C(  189),  UINT8_C(  115),  UINT8_C(  214),  UINT8_C(  169),  UINT8_C(  148),  UINT8_C(   48),  UINT8_C(   97),  UINT8_C(   36),  UINT8_C(   36),  UINT8_C(  128),  UINT8_C(   64),  UINT8_C(  223),  UINT8_C(  149),  UINT8_C(  198),  UINT8_C(    2)  } },
    { {  UINT8_C(  123),  UINT8_C(  207),  UINT8_C(   90),  UINT8_C(   66),  UINT8_C(   35),  UINT8_C(  202),  UINT8_C(   11),  UINT8_C(  166)  },
      {  UINT16_C(47921),  UINT16_C(52841),  UINT16_C(39201),  UINT16_C(62255),  UINT16_C(26454),  UINT16_C(46295),  UINT16_C(55742),  UINT16_C(65404)  },
      {  UINT16_C(34926),  UINT16_C( 4068),  UINT16_C( 9426),  UINT16_C(47581),  UINT16_C(31106),  UINT16_C(61539),  UINT16_C(11933),  UINT16_C( 7762)  },
      {  UINT8_C(  123),  UINT8_C(  207),  UINT8_C(   90),  UINT8_C(   66),  UINT8_C(   35),  UINT8_C(  202),  UINT8_C(   11),  UINT8_C(  166),  UINT8_C(   68),  UINT8_C(  222),  UINT8_C(  190),  UINT8_C(  173),  UINT8_C(  225),  UINT8_C(  165),  UINT8_C(    8),  UINT8_C(   30)  } },
    { {  UINT8_C(  214),  UINT8_C(   91),  UINT8_C(  217),  UINT8_C(  199),  UINT8_C(  144),  UINT8_C(   76),  UINT8_C(   91),  UINT8_C(  148)  },
      {  UINT16_C(14970),  UINT16_C(59825),  UINT16_C(39864),  UINT16_C(30311),  UINT16_C(12793),  UINT16_C(29806),  UINT16_C( 4536),  UINT16_C(55184)  },
      {  UINT16_C(14464),  UINT16_C(50342),  UINT16_C(22620),  UINT16_C(44678),  UINT16_C(45214),  UINT16_C(50951),  UINT16_C(63568),  UINT16_C(63058)  },
      {  UINT8_C(  214),  UINT8_C(   91),  UINT8_C(  217),  UINT8_C(  199),  UINT8_C(  144),  UINT8_C(   76),  UINT8_C(   91),  UINT8_C(  148),  UINT8_C(  115),  UINT8_C(  174),  UINT8_C(  244),  UINT8_C(   37),  UINT8_C(  227),  UINT8_C(   59),  UINT8_C(   10),  UINT8_C(  206)  } },
    { {  UINT8_C(  200),  UINT8_C(  252),  UINT8_C(  181),  UINT8_C(  219),  UINT8_C(  210),  UINT8_C(   30),  UINT8_C(  224),  UINT8_C(   92)  },
      {  UINT16_C(64475),  UINT16_C(41045),  UINT16_C(48667),  UINT16_C(15480),  UINT16_C( 5615),  UINT16_C(48980),  UINT16_C(40869),  UINT16_C( 5807)  },
      {  UINT16_C( 3562),  UINT16_C(52315),  UINT16_C(62713),  UINT16_C(18955),  UINT16_C(  183),  UINT16_C(59516),  UINT16_C(  382),  UINT16_C(15339)  },
      {  UINT8_C(  200),  UINT8_C(  252),  UINT8_C(  181),  UINT8_C(  219),  UINT8_C(  210),  UINT8_C(   30),  UINT8_C(  224),  UINT8_C(   92),  UINT8_C(   10),  UINT8_C(  109),  UINT8_C(  179),  UINT8_C(  135),  UINT8_C(   23),  UINT8_C(  168),  UINT8_C(  161),  UINT8_C(   83)  } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint8x8_t r_ = simde_vld1_u8(test_vec[i].r_);
    simde_uint16x8_t a = simde_vld1q_u16(test_vec[i].a);
    simde_uint16x8_t b = simde_vld1q_u16(test_vec[i].b);
    simde_uint8x16_t r = simde_vraddhn_high_u16(r_, a, b);

    simde_test_arm_neon_assert_equal_u8x16(r, simde_vld1q_u8(test_vec[i].r));
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint8x8_t r_ = simde_test_arm_neon_random_u8x8();
    simde_uint16x8_t a = simde_test_arm_neon_random_u16x8();
    simde_uint16x8_t b = simde_test_arm_neon_random_u16x8();
    simde_uint8x16_t r = simde_vraddhn_high_u16(r_, a, b);

    simde_test_arm_neon_write_u8x8(2, r_, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u16x8(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u16x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u8x16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vraddhn_high_u32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint16_t r_[4];
    uint32_t a[4];
    uint32_t b[4];
    uint16_t r[8];
  } test_vec[] = {
    { {  UINT16_C(     23077),  UINT16_C(     46664),  UINT16_C(     36278),  UINT16_C(     22401)  },
      {  UINT32_C( 212850905),  UINT32_C(1467528063),  UINT32_C(1489007594),  UINT32_C(2026089729)  },
      {  UINT32_C( 436730000),  UINT32_C(1221238491),  UINT32_C(2481626902),  UINT32_C(2509229408)  },
      {  UINT16_C(     23077),  UINT16_C(     46664),  UINT16_C(     36278),  UINT16_C(     22401),  UINT16_C(      9912),  UINT16_C(     41027),  UINT16_C(     60587),  UINT16_C(      3667)  } },
    { {  UINT16_C(     26972),  UINT16_C(     25134),  UINT16_C(     54033),  UINT16_C(     46084)  },
      {  UINT32_C( 194934793),  UINT32_C(2438547165),  UINT32_C(4072150333),  UINT32_C(2075239274)  },
      {  UINT32_C(1753146815),  UINT32_C(3111271966),  UINT32_C(2964399735),  UINT32_C(2843280803)  },
      {  UINT16_C(     26972),  UINT16_C(     25134),  UINT16_C(     54033),  UINT16_C(     46084),  UINT16_C(     29725),  UINT16_C(     19148),  UINT16_C(     41833),  UINT16_C(      9515)  } },
    { {  UINT16_C(       993),  UINT16_C(     21997),  UINT16_C(      9029),  UINT16_C(     23301)  },
      {  UINT32_C(4255305104),  UINT32_C(3169505596),  UINT32_C(1310219469),  UINT32_C( 809894928)  },
      {  UINT32_C(2689553230),  UINT32_C(2556160718),  UINT32_C(1341585880),  UINT32_C(2876365377)  },
      {  UINT16_C(       993),  UINT16_C(     21997),  UINT16_C(      9029),  UINT16_C(     23301),  UINT16_C(     40434),  UINT16_C(     21831),  UINT16_C(     40463),  UINT16_C(     56248)  } },
    { {  UINT16_C(     54382),  UINT16_C(       485),  UINT16_C(     47179),  UINT16_C(     37991)  },
      {  UINT32_C( 912277427),  UINT32_C(2598040794),  UINT32_C(2358557871),  UINT32_C( 494170348)  },
      {  UINT32_C(  86749149),  UINT32_C(4016885293),  UINT32_C(1102033753),  UINT32_C(3795884245)  },
      {  UINT16_C(     54382),  UINT16_C(       485),  UINT16_C(     47179),  UINT16_C(     37991),  UINT16_C(     15244),  UINT16_C(     35400),  UINT16_C(     52804),  UINT16_C(     65461)  } },
    { {  UINT16_C(     40375),  UINT16_C(     24908),  UINT16_C(     46986),  UINT16_C(     40104)  },
      {  UINT32_C(3645706326),  UINT32_C(2447247706),  UINT32_C( 319248759),  UINT32_C( 658432665)  },
      {  UINT32_C(1671320241),  UINT32_C(3353978200),  UINT32_C( 428610015),  UINT32_C(1633781989)  },
      {  UINT16_C(     40375),  UINT16_C(     24908),  UINT16_C(     46986),  UINT16_C(     40104),  UINT16_C(     15595),  UINT16_C(     22984),  UINT16_C(     11411),  UINT16_C(     34976)  } },
    { {  UINT16_C(      3244),  UINT16_C(     25605),  UINT16_C(     17142),  UINT16_C(     40589)  },
      {  UINT32_C(3342312085),  UINT32_C( 843603761),  UINT32_C(4192013367),  UINT32_C(2339055831)  },
      {  UINT32_C(1884188089),  UINT32_C(  86746460),  UINT32_C(2553337019),  UINT32_C(2959916542)  },
      {  UINT16_C(      3244),  UINT16_C(     25605),  UINT16_C(     17142),  UINT16_C(     40589),  UINT16_C(     14214),  UINT16_C(     14196),  UINT16_C(     37390),  UINT16_C(     15320)  } },
    { {  UINT16_C(     33641),  UINT16_C(      2906),  UINT16_C(     19825),  UINT16_C(     24144)  },
      {  UINT32_C(1982882836),  UINT32_C(2281243819),  UINT32_C( 946004145),  UINT32_C( 395418665)  },
      {  UINT32_C(1663450668),  UINT32_C(4273103743),  UINT32_C(3004646997),  UINT32_C(1238387319)  },
      {  UINT16_C(     33641),  UINT16_C(      2906),  UINT16_C(     19825),  UINT16_C(     24144),  UINT16_C(     55639),  UINT16_C(     34475),  UINT16_C(     60282),  UINT16_C(     24930)  } },
    { {  UINT16_C(      6456),  UINT16_C(     56808),  UINT16_C(     26148),  UINT16_C(      7183)  },
      {  UINT32_C(2335372976),  UINT32_C(3737714976),  UINT32_C(1714085649),  UINT32_C(3659772348)  },
      {  UINT32_C(3806344607),  UINT32_C( 127876483),  UINT32_C( 823615594),  UINT32_C(1708678494)  },
      {  UINT16_C(      6456),  UINT16_C(     56808),  UINT16_C(     26148),  UINT16_C(      7183),  UINT16_C(     28179),  UINT16_C(     58984),  UINT16_C(     38722),  UINT16_C(     16380)  } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint16x4_t r_ = simde_vld1_u16(test_vec[i].r_);
    simde_uint32x4_t a = simde_vld1q_u32(test_vec[i].a);
    simde_uint32x4_t b = simde_vld1q_u32(test_vec[i].b);
    simde_uint16x8_t r = simde_vraddhn_high_u32(r_, a, b);

    simde_test_arm_neon_assert_equal_u16x8(r, simde_vld1q_u16(test_vec[i].r));
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint16x4_t r_ = simde_test_arm_neon_random_u16x4();
    simde_uint32x4_t a = simde_test_arm_neon_random_u32x4();
    simde_uint32x4_t b = simde_test_arm_neon_random_u32x4();
    simde_uint16x8_t r = simde_vraddhn_high_u32(r_, a, b);

    simde_test_arm_neon_write_u16x4(2, r_, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u32x4(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u16x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vraddhn_high_u64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint32_t r_[2];
    uint64_t a[2];
    uint64_t b[2];
    uint32_t r[4];
  } test_vec[] = {
    { {  UINT32_C(          1833090949),  UINT32_C(           159173040)  },
      {  UINT64_C( 7595685821160238545),  UINT64_C( 5460164061812335858)  },
      {  UINT64_C( 2326480958303370666),  UINT64_C( 8560840016854787856) },
      {  UINT32_C(          1833090949),  UINT32_C(           159173040),  UINT32_C(          2310184478),  UINT32_C(          3264519404)  } },
    { {  UINT32_C(          1340950353),  UINT32_C(          2345674004)  },
      {  UINT64_C(14288960134217676844),  UINT64_C( 9711330258489778561)  },
      {  UINT64_C( 5010837924671730567),  UINT64_C(12706785817686801043) },
      {  UINT32_C(          1340950353),  UINT32_C(          2345674004),  UINT32_C(           198617108),  UINT32_C(           924657100)  } },
    { {  UINT32_C(           167826599),  UINT32_C(          2840686835)  },
      {  UINT64_C(16502632842102257134),  UINT64_C( 9241563249155967922)  },
      {  UINT64_C(12310152090430206381),  UINT64_C( 2353024520452018480) },
      {  UINT32_C(           167826599),  UINT32_C(          2840686835),  UINT32_C(          2413531965),  UINT32_C(          2699575333)  } },
    { {  UINT32_C(          2476932675),  UINT32_C(          2198905573)  },
      {  UINT64_C( 3807331566796253338),  UINT64_C(18435570049911670851)  },
      {  UINT64_C( 3478240210011748394),  UINT64_C(  334130327661001499) },
      {  UINT32_C(          2476932675),  UINT32_C(          2198905573),  UINT32_C(          1696304366),  UINT32_C(            75194124)  } },
    { {  UINT32_C(          2749035874),  UINT32_C(          1323215606)  },
      {  UINT64_C(11951820368738700930),  UINT64_C( 2454177180675006729)  },
      {  UINT64_C(  862517325357223436),  UINT64_C(12539832836604929412) },
      {  UINT32_C(          2749035874),  UINT32_C(          1323215606),  UINT32_C(          2983570493),  UINT32_C(          3491065003)  } },
    { {  UINT32_C(          2261109996),  UINT32_C(          2703799959)  },
      {  UINT64_C(17439214036731252933),  UINT64_C( 4281041593916534883)  },
      {  UINT64_C( 5627168252961347552),  UINT64_C( 4478691679238507457) },
      {  UINT32_C(          2261109996),  UINT32_C(          2703799959),  UINT32_C(          1075593339),  UINT32_C(          2039534336)  } },
    { {  UINT32_C(          4089219629),  UINT32_C(          4037508497)  },
      {  UINT64_C( 6537037128722859108),  UINT64_C( 9912793837125092983)  },
      {  UINT64_C(  192154116194292355),  UINT64_C( 3961895855238817793) },
      {  UINT32_C(          4089219629),  UINT32_C(          4037508497),  UINT32_C(          1566761929),  UINT32_C(          3230452932)  } },
    { {  UINT32_C(          2292246865),  UINT32_C(           776206411)  },
      {  UINT64_C(16001022629824472191),  UINT64_C(14157820913506211794)  },
      {  UINT64_C( 2190238845283507523),  UINT64_C(17377647137311425031) },
      {  UINT32_C(          2292246865),  UINT32_C(           776206411),  UINT32_C(          4235483118),  UINT32_C(          3047456028)  } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint32x2_t r_ = simde_vld1_u32(test_vec[i].r_);
    simde_uint64x2_t a = simde_vld1q_u64(test_vec[i].a);
    simde_uint64x2_t b = simde_vld1q_u64(test_vec[i].b);
    simde_uint32x4_t r = simde_vraddhn_high_u64(r_, a, b);

    simde_test_arm_neon_assert_equal_u32x4(r, simde_vld1q_u32(test_vec[i].r));
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint32x2_t r_ = simde_test_arm_neon_random_u32x2();
    simde_uint64x2_t a = simde_test_arm_neon_random_u64x2();
    simde_uint64x2_t b = simde_test_arm_neon_random_u64x2();
    simde_uint32x4_t r = simde_vraddhn_high_u64(r_, a, b);

    simde_test_arm_neon_write_u32x2(2, r_, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u64x2(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u64x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}


SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(vraddhn_high_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vraddhn_high_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vraddhn_high_s64)

SIMDE_TEST_FUNC_LIST_ENTRY(vraddhn_high_u16)
SIMDE_TEST_FUNC_LIST_ENTRY(vraddhn_high_u32)
SIMDE_TEST_FUNC_LIST_ENTRY(vraddhn_high_u64)
SIMDE_TEST_FUNC_LIST_END

#include "test-neon-footer.h"
