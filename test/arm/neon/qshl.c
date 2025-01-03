#define SIMDE_TEST_ARM_NEON_INSN qshl

#include "test-neon.h"
#include "../../../simde/arm/neon/qshl.h"
#include "../../../simde/arm/neon/and.h"
#include "../../../simde/arm/neon/dup_n.h"
#include "../../../simde/arm/neon/neg.h"
#include "../../../simde/arm/neon/shl.h"

/* Until v12, clang used unsigned parameters on the scalar versions, so
 * when testing we need to disable the -Wsign-conversion to avoid a
 * diagnostic.  If this is a problem in your code you might want to
 * consider using simde_vqshl* instead of vqshl* so you can avoid an
 * ifdef. */

#if HEDLEY_HAS_WARNING("-Wsign-conversion") && defined(SIMDE_NATIVE_ALIASES_TESTING)
  #pragma clang diagnostic ignored "-Wsign-conversion"
#endif

static int
test_simde_vqshlb_s8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int8_t a;
    int8_t b;
    int8_t r;
  } test_vec[] = {
    { -INT8_C(   1),
       INT8_C(  15),
           INT8_MIN },
    {  INT8_C(   0),
       INT8_C(   6),
       INT8_C(   0) },
    {  INT8_C(   7),
       INT8_C(  12),
           INT8_MAX },
    {  INT8_C(   1),
       INT8_C(  13),
           INT8_MAX },
    { -INT8_C(  20),
       INT8_C(  11),
           INT8_MIN },
    { -INT8_C(  30),
       INT8_C(   0),
      -INT8_C(  30) },
    {  INT8_C(  10),
       INT8_C(   6),
           INT8_MAX },
    { -INT8_C(   2),
       INT8_C(  15),
           INT8_MIN },
    {  INT8_C(   1),
       INT8_C(  11),
           INT8_MAX },
    { -INT8_C(   2),
       INT8_C(   6),
           INT8_MIN },
    { -INT8_C(   2),
       INT8_C(   5),
      -INT8_C(  64) },
    {  INT8_C(   2),
       INT8_C(  12),
           INT8_MAX },
    {  INT8_C(   0),
       INT8_C(   0),
       INT8_C(   0) },
    { -INT8_C(  10),
       INT8_C(   6),
           INT8_MIN },
    {  INT8_C(   1),
       INT8_C(   0),
       INT8_C(   1) },
    { -INT8_C(  29),
       INT8_C(   2),
      -INT8_C( 116) },
    {  INT8_C(   6),
       INT8_C(   5),
           INT8_MAX },
    {  INT8_C(   7),
       INT8_C(   8),
           INT8_MAX },
    { -INT8_C(  27),
       INT8_C(  15),
           INT8_MIN },
    { -INT8_C(   2),
       INT8_C(   2),
      -INT8_C(   8) },
    {  INT8_C(  38),
       INT8_C(   7),
           INT8_MAX },
    {  INT8_C(   7),
       INT8_C(   8),
           INT8_MAX },
    { -INT8_C(   1),
       INT8_C(   8),
           INT8_MIN },
    {  INT8_C(   2),
       INT8_C(   3),
       INT8_C(  16) },
    {  INT8_C(   7),
       INT8_C(   1),
       INT8_C(  14) },
    {  INT8_C( 110),
       INT8_C(   4),
           INT8_MAX },
    { -INT8_C(   1),
       INT8_C(   8),
           INT8_MIN },
    { -INT8_C(   5),
       INT8_C(   4),
      -INT8_C(  80) },
    { -INT8_C(  98),
       INT8_C(  15),
           INT8_MIN },
    {  INT8_C( 125),
       INT8_C(  11),
           INT8_MAX },
    { -INT8_C(   2),
       INT8_C(  11),
           INT8_MIN },
    {  INT8_C(  51),
       INT8_C(   0),
       INT8_C(  51) },
    {  INT8_C(  95),
       INT8_C(  25),
           INT8_MAX },
    { -INT8_C(  97),
      -INT8_C(  73),
      -INT8_C(   1) },
    {  INT8_C( 113),
       INT8_C(   4),
           INT8_MAX },
    { -INT8_C(  38),
           INT8_MAX,
           INT8_MIN },
    { -INT8_C(  66),
       INT8_C( 123),
           INT8_MIN },
    { -INT8_C(  18),
       INT8_C(   6),
           INT8_MIN },
    {  INT8_C(  95),
      -INT8_C(  34),
       INT8_C(   0) },
    { -INT8_C(  66),
      -INT8_C(  40),
      -INT8_C(   1) },
    { -INT8_C( 108),
      -INT8_C(  22),
      -INT8_C(   1) },
    { -INT8_C(  36),
       INT8_C(  50),
           INT8_MIN },
    { -INT8_C(  85),
      -INT8_C(  69),
      -INT8_C(   1) },
    { -INT8_C(  81),
       INT8_C(  91),
           INT8_MIN },
    {  INT8_C( 102),
       INT8_C(  62),
           INT8_MAX },
    {  INT8_C(  49),
      -INT8_C(  78),
       INT8_C(   0) },
    { -INT8_C(  92),
      -INT8_C( 126),
      -INT8_C(   1) },
    { -INT8_C(  94),
       INT8_C(   3),
           INT8_MIN },
    { -INT8_C( 100),
       INT8_C(  65),
           INT8_MIN },
    { -INT8_C(  70),
       INT8_C(  13),
           INT8_MIN },
    {  INT8_C(  69),
      -INT8_C( 108),
       INT8_C(   0) },
    { -INT8_C( 115),
       INT8_C(   3),
           INT8_MIN },
    {  INT8_C(  16),
       INT8_C( 123),
           INT8_MAX },
    {  INT8_C(  10),
       INT8_C( 111),
           INT8_MAX },
    {  INT8_C(  89),
      -INT8_C(  56),
       INT8_C(   0) },
    {  INT8_C(  71),
      -INT8_C(  19),
       INT8_C(   0) },
    { -INT8_C(  78),
       INT8_C(  36),
           INT8_MIN },
    {  INT8_C(  31),
       INT8_C(  93),
           INT8_MAX },
    { -INT8_C(  33),
      -INT8_C(  50),
      -INT8_C(   1) },
    { -INT8_C(  72),
       INT8_C(  70),
           INT8_MIN },
    {  INT8_C(  12),
      -INT8_C(  23),
       INT8_C(   0) },
    { -INT8_C(   8),
      -INT8_C(  79),
      -INT8_C(   1) },
    {  INT8_C( 108),
      -INT8_C( 102),
       INT8_C(   0) },
    { -INT8_C(  76),
       INT8_C(   8),
           INT8_MIN },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    int8_t r = simde_vqshlb_s8(test_vec[i].a, test_vec[i].b);

    simde_assert_equal_i8(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 32 ; i++) {
    int8_t a = simde_test_codegen_random_i8() >> (simde_test_codegen_random_i8() & 7);
    int8_t b = simde_test_codegen_random_i8() & 15;
    int8_t r = simde_vqshlb_s8(a, b);

    simde_test_codegen_write_i8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_i8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  for (int i = 0 ; i < 32 ; i++) {
    int8_t a = simde_test_codegen_random_i8();
    int8_t b = simde_test_codegen_random_i8();
    int8_t r = simde_vqshlb_s8(a, b);

    simde_test_codegen_write_i8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_i8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vqshlh_s16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int16_t a;
    int16_t b;
    int16_t r;
  } test_vec[] = {
    {  INT16_C(   168),
       INT16_C(     4),
       INT16_C(  2688) },
    { -INT16_C(   121),
       INT16_C(    17),
             INT16_MIN },
    {  INT16_C(    62),
       INT16_C(     4),
       INT16_C(   992) },
    { -INT16_C(    13),
       INT16_C(     4),
      -INT16_C(   208) },
    { -INT16_C(   765),
       INT16_C(    23),
             INT16_MIN },
    {  INT16_C(  1304),
       INT16_C(    10),
             INT16_MAX },
    { -INT16_C(     1),
       INT16_C(    29),
             INT16_MIN },
    {  INT16_C(     1),
       INT16_C(     2),
       INT16_C(     4) },
    {  INT16_C(  4097),
       INT16_C(    13),
             INT16_MAX },
    { -INT16_C(   285),
       INT16_C(    24),
             INT16_MIN },
    {  INT16_C(   464),
       INT16_C(    19),
             INT16_MAX },
    {  INT16_C(   244),
       INT16_C(     9),
             INT16_MAX },
    { -INT16_C(  1249),
       INT16_C(    18),
             INT16_MIN },
    {  INT16_C(    84),
       INT16_C(    18),
             INT16_MAX },
    { -INT16_C(     1),
       INT16_C(     8),
      -INT16_C(   256) },
    {  INT16_C(  1762),
       INT16_C(     4),
       INT16_C( 28192) },
    { -INT16_C(     2),
       INT16_C(    31),
             INT16_MIN },
    { -INT16_C(    19),
       INT16_C(     5),
      -INT16_C(   608) },
    {  INT16_C(   214),
       INT16_C(    30),
             INT16_MAX },
    {  INT16_C(   134),
       INT16_C(     9),
             INT16_MAX },
    { -INT16_C(     6),
       INT16_C(    23),
             INT16_MIN },
    { -INT16_C(  2582),
       INT16_C(    31),
             INT16_MIN },
    {  INT16_C(     1),
       INT16_C(    26),
             INT16_MAX },
    {  INT16_C(   318),
       INT16_C(    11),
             INT16_MAX },
    {  INT16_C(   137),
       INT16_C(    23),
             INT16_MAX },
    { -INT16_C(    14),
       INT16_C(     2),
      -INT16_C(    56) },
    { -INT16_C(  6791),
       INT16_C(     7),
             INT16_MIN },
    {  INT16_C(  1041),
       INT16_C(    18),
             INT16_MAX },
    {  INT16_C(   892),
       INT16_C(    14),
             INT16_MAX },
    {  INT16_C(    91),
       INT16_C(     8),
       INT16_C( 23296) },
    {  INT16_C(     3),
       INT16_C(     3),
       INT16_C(    24) },
    {  INT16_C(   639),
       INT16_C(    15),
             INT16_MAX },
    { -INT16_C(  1702),
      -INT16_C(  8469),
      -INT16_C(     1) },
    {  INT16_C( 32162),
       INT16_C( 12251),
       INT16_C(     0) },
    {  INT16_C(   237),
      -INT16_C( 17502),
       INT16_C(     0) },
    {  INT16_C( 22704),
       INT16_C( 29371),
       INT16_C(     0) },
    { -INT16_C( 31884),
      -INT16_C(  8758),
      -INT16_C(     1) },
    { -INT16_C( 18509),
      -INT16_C(  2238),
             INT16_MIN },
    {  INT16_C( 15078),
      -INT16_C( 21986),
             INT16_MAX },
    { -INT16_C( 29325),
      -INT16_C( 12682),
             INT16_MIN },
    {  INT16_C( 24967),
       INT16_C( 10668),
       INT16_C(     0) },
    { -INT16_C( 30753),
      -INT16_C( 13223),
             INT16_MIN },
    { -INT16_C(  1144),
       INT16_C( 14471),
      -INT16_C(     1) },
    {  INT16_C( 16979),
      -INT16_C( 14422),
       INT16_C(     0) },
    {  INT16_C( 30149),
       INT16_C( 31141),
       INT16_C(     0) },
    { -INT16_C(  6356),
       INT16_C(  4720),
             INT16_MIN },
    { -INT16_C( 29151),
      -INT16_C( 27204),
      -INT16_C(     1) },
    {  INT16_C( 12828),
      -INT16_C( 23709),
             INT16_MAX },
    {  INT16_C(  3988),
       INT16_C( 29644),
       INT16_C(     0) },
    {  INT16_C(  9622),
       INT16_C(  7743),
             INT16_MAX },
    { -INT16_C( 14816),
       INT16_C( 29783),
             INT16_MIN },
    {  INT16_C(   264),
      -INT16_C( 12997),
             INT16_MAX },
    { -INT16_C(  8074),
      -INT16_C( 23994),
             INT16_MIN },
    { -INT16_C( 18744),
      -INT16_C(  5708),
      -INT16_C(     1) },
    {  INT16_C( 28997),
       INT16_C( 24958),
             INT16_MAX },
    { -INT16_C(  7773),
       INT16_C( 14084),
             INT16_MIN },
    { -INT16_C( 12048),
      -INT16_C( 30806),
      -INT16_C(     1) },
    { -INT16_C(  5642),
       INT16_C(  5797),
      -INT16_C(     1) },
    { -INT16_C(   849),
      -INT16_C( 18550),
      -INT16_C(     1) },
    { -INT16_C( 14594),
       INT16_C( 29829),
      -INT16_C(     1) },
    { -INT16_C( 13402),
       INT16_C( 28183),
             INT16_MIN },
    { -INT16_C( 13438),
      -INT16_C( 14504),
             INT16_MIN },
    { -INT16_C( 10692),
      -INT16_C(  8152),
             INT16_MIN },
    {  INT16_C( 11448),
      -INT16_C( 22505),
             INT16_MAX },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    int16_t r = simde_vqshlh_s16(test_vec[i].a, test_vec[i].b);

    simde_assert_equal_i16(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 32 ; i++) {
    int16_t a = simde_test_codegen_random_i16() >> (simde_test_codegen_random_i16() & 15);
    int16_t b = simde_test_codegen_random_i16() & 31;
    int16_t r = simde_vqshlh_s16(a, b);

    simde_test_codegen_write_i16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_i16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  for (int i = 0 ; i < 32 ; i++) {
    int16_t a = simde_test_codegen_random_i16();
    int16_t b = simde_test_codegen_random_i16();
    int16_t r = simde_vqshlh_s16(a, b);

    simde_test_codegen_write_i16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_i16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vqshls_s32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int32_t a;
    int32_t b;
    int32_t r;
  } test_vec[] = {
    { -INT32_C(   364792463),
       INT32_C(          24),
                   INT32_MIN },
    {  INT32_C(    12102947),
       INT32_C(          51),
                   INT32_MAX },
    { -INT32_C(        1915),
       INT32_C(          27),
                   INT32_MIN },
    { -INT32_C(    20908871),
       INT32_C(          61),
                   INT32_MIN },
    {  INT32_C(       35160),
       INT32_C(          38),
                   INT32_MAX },
    {  INT32_C(           0),
       INT32_C(           5),
       INT32_C(           0) },
    { -INT32_C(     1105305),
       INT32_C(          39),
                   INT32_MIN },
    {  INT32_C(          91),
       INT32_C(          36),
                   INT32_MAX },
    {  INT32_C(           1),
       INT32_C(          11),
       INT32_C(        2048) },
    { -INT32_C(  1007154321),
       INT32_C(          20),
                   INT32_MIN },
    {  INT32_C(        4449),
       INT32_C(          48),
                   INT32_MAX },
    {  INT32_C(           0),
       INT32_C(          22),
       INT32_C(           0) },
    {  INT32_C(    15629316),
       INT32_C(          48),
                   INT32_MAX },
    {  INT32_C(      218290),
       INT32_C(          18),
                   INT32_MAX },
    { -INT32_C(   229219001),
       INT32_C(          48),
                   INT32_MIN },
    { -INT32_C(          63),
       INT32_C(          30),
                   INT32_MIN },
    {  INT32_C(       30779),
       INT32_C(           8),
       INT32_C(     7879424) },
    { -INT32_C(          39),
       INT32_C(           1),
      -INT32_C(          78) },
    { -INT32_C(        1263),
       INT32_C(          56),
                   INT32_MIN },
    { -INT32_C(        6541),
       INT32_C(          39),
                   INT32_MIN },
    { -INT32_C(         874),
       INT32_C(          29),
                   INT32_MIN },
    {  INT32_C(      475811),
       INT32_C(          53),
                   INT32_MAX },
    { -INT32_C(    50038301),
       INT32_C(           1),
      -INT32_C(   100076602) },
    {  INT32_C(          24),
       INT32_C(          44),
                   INT32_MAX },
    { -INT32_C(      854906),
       INT32_C(           1),
      -INT32_C(     1709812) },
    { -INT32_C(          12),
       INT32_C(          44),
                   INT32_MIN },
    {  INT32_C(           1),
       INT32_C(           1),
       INT32_C(           2) },
    {  INT32_C(  1704744100),
       INT32_C(           2),
                   INT32_MAX },
    { -INT32_C(      729850),
       INT32_C(          53),
                   INT32_MIN },
    { -INT32_C(      264580),
       INT32_C(          33),
                   INT32_MIN },
    { -INT32_C(           2),
       INT32_C(          23),
      -INT32_C(    16777216) },
    { -INT32_C(    11963761),
       INT32_C(          41),
                   INT32_MIN },
    { -INT32_C(  1742353482),
       INT32_C(   911858318),
      -INT32_C(           1) },
    {  INT32_C(  1965021912),
      -INT32_C(   754219333),
       INT32_C(           0) },
    { -INT32_C(  2060105514),
      -INT32_C(   148181105),
      -INT32_C(           1) },
    {  INT32_C(  1639751736),
      -INT32_C(  2143919670),
       INT32_C(           0) },
    { -INT32_C(  1156031700),
       INT32_C(   250704438),
                   INT32_MIN },
    {  INT32_C(   142807116),
       INT32_C(  1843105687),
       INT32_C(           0) },
    {  INT32_C(  1743917271),
       INT32_C(   928914687),
       INT32_C(   871958635) },
    { -INT32_C(  2020009283),
      -INT32_C(  1475883141),
                   INT32_MIN },
    {  INT32_C(  1633886251),
      -INT32_C(   563129198),
       INT32_C(           0) },
    { -INT32_C(    68750492),
       INT32_C(  1500037506),
      -INT32_C(           1) },
    { -INT32_C(   775922734),
       INT32_C(   873012855),
                   INT32_MIN },
    { -INT32_C(  1262771655),
      -INT32_C(  1671642255),
                   INT32_MIN },
    {  INT32_C(  1979564003),
       INT32_C(  2018733331),
                   INT32_MAX },
    { -INT32_C(   495764896),
      -INT32_C(   851714821),
      -INT32_C(    15492653) },
    { -INT32_C(  1365246921),
       INT32_C(  1407428634),
                   INT32_MIN },
    { -INT32_C(  1157063094),
       INT32_C(  1146643553),
                   INT32_MIN },
    {  INT32_C(   934892836),
       INT32_C(   581897666),
       INT32_C(           0) },
    {  INT32_C(  1107567431),
       INT32_C(   907034879),
       INT32_C(   553783715) },
    {  INT32_C(  1457827644),
      -INT32_C(  1582643369),
                   INT32_MAX },
    { -INT32_C(   950226330),
       INT32_C(   973911062),
                   INT32_MIN },
    { -INT32_C(   864893686),
       INT32_C(   435102162),
      -INT32_C(           1) },
    {  INT32_C(  1130165060),
       INT32_C(  1870228531),
                   INT32_MAX },
    {  INT32_C(  1925602843),
      -INT32_C(  1961660379),
                   INT32_MAX },
    {  INT32_C(   944992034),
       INT32_C(   779312932),
                   INT32_MAX },
    { -INT32_C(   134552284),
       INT32_C(  1259399430),
                   INT32_MIN },
    {  INT32_C(   277769437),
      -INT32_C(   209712936),
       INT32_C(           0) },
    { -INT32_C(  1956297114),
      -INT32_C(   669550410),
      -INT32_C(           1) },
    {  INT32_C(   202402536),
      -INT32_C(   314932279),
       INT32_C(           0) },
    {  INT32_C(  1877226600),
      -INT32_C(    71633634),
                   INT32_MAX },
    {  INT32_C(   973817953),
      -INT32_C(  1238529200),
                   INT32_MAX },
    { -INT32_C(  2025679919),
      -INT32_C(   211855093),
                   INT32_MIN },
    { -INT32_C(  1929416509),
       INT32_C(  1551448563),
      -INT32_C(      235525) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    int32_t r = simde_vqshls_s32(test_vec[i].a, test_vec[i].b);

    simde_assert_equal_i32(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 32 ; i++) {
    int32_t a = simde_test_codegen_random_i32() >> (simde_test_codegen_random_i32() & 31);
    int32_t b = simde_test_codegen_random_i32() & 63;
    int32_t r = simde_vqshls_s32(a, b);

    simde_test_codegen_write_i32(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_i32(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  for (int i = 0 ; i < 32 ; i++) {
    int32_t a = simde_test_codegen_random_i32();
    int32_t b = simde_test_codegen_random_i32();
    int32_t r = simde_vqshls_s32(a, b);

    simde_test_codegen_write_i32(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_i32(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vqshld_s64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int64_t a;
    int64_t b;
    int64_t r;
  } test_vec[] = {
    { -INT64_C(          9603080251),
       INT64_C(                  46),
                           INT64_MIN },
    {  INT64_C( 1294821452757624905),
       INT64_C(                  24),
                           INT64_MAX },
    {  INT64_C(    2132540204216942),
       INT64_C(                  59),
                           INT64_MAX },
    { -INT64_C(    2883484485881735),
       INT64_C(                  60),
                           INT64_MIN },
    { -INT64_C(  106663695980358031),
       INT64_C(                  40),
                           INT64_MIN },
    { -INT64_C(        442225756044),
       INT64_C(                  50),
                           INT64_MIN },
    { -INT64_C(  129704200762429325),
       INT64_C(                  33),
                           INT64_MIN },
    {  INT64_C(      55779518749930),
       INT64_C(                  47),
                           INT64_MAX },
    {  INT64_C(  132079233730759690),
       INT64_C(                  25),
                           INT64_MAX },
    { -INT64_C(        216554371979),
       INT64_C(                  54),
                           INT64_MIN },
    { -INT64_C(        901287020181),
       INT64_C(                  30),
                           INT64_MIN },
    {  INT64_C(   27158339241030257),
       INT64_C(                  10),
                           INT64_MAX },
    { -INT64_C(         41824901937),
       INT64_C(                   7),
      -INT64_C(       5353587447936) },
    {  INT64_C(      31768600374220),
       INT64_C(                  16),
       INT64_C( 2081986994124881920) },
    {  INT64_C(         13270745028),
       INT64_C(                  25),
       INT64_C(  445292311631364096) },
    {  INT64_C(     496925752384670),
       INT64_C(                  37),
                           INT64_MAX },
    {  INT64_C(        124759521399),
       INT64_C(                  15),
       INT64_C(    4088119997202432) },
    { -INT64_C(   10434663993467968),
       INT64_C(                   0),
      -INT64_C(   10434663993467968) },
    {  INT64_C(      97017729285729),
       INT64_C(                  58),
                           INT64_MAX },
    {  INT64_C(        329419536077),
       INT64_C(                   1),
       INT64_C(        658839072154) },
    {  INT64_C(     393189134324523),
       INT64_C(                  22),
                           INT64_MAX },
    { -INT64_C(    8868369498123251),
       INT64_C(                  20),
                           INT64_MIN },
    {  INT64_C(         30736994067),
       INT64_C(                  55),
                           INT64_MAX },
    { -INT64_C(    5116039957190441),
       INT64_C(                  20),
                           INT64_MIN },
    { -INT64_C(      10083466236236),
       INT64_C(                  38),
                           INT64_MIN },
    { -INT64_C(          3901629790),
       INT64_C(                  35),
                           INT64_MIN },
    {  INT64_C(      58326053897677),
       INT64_C(                  12),
       INT64_C(  238903516764884992) },
    { -INT64_C(  198117999449297547),
       INT64_C(                  14),
                           INT64_MIN },
    { -INT64_C(          3699678780),
       INT64_C(                  37),
                           INT64_MIN },
    {  INT64_C(          2378087083),
       INT64_C(                  26),
       INT64_C(  159590722633203712) },
    {  INT64_C( 5001603701541282984),
       INT64_C(                   8),
                           INT64_MAX },
    {  INT64_C(  381658124344810160),
       INT64_C(                  17),
                           INT64_MAX },
    {  INT64_C( 5924439430123102526),
      -INT64_C( 3927135141997730687),
       INT64_C(                   0) },
    { -INT64_C( 6496448148762790297),
       INT64_C( 5360047771590464638),
                           INT64_MIN },
    { -INT64_C( 8687356793521164072),
       INT64_C( 2315471129083688435),
      -INT64_C(    1060468358584127) },
    { -INT64_C( 2764077279105556182),
      -INT64_C(  400566232974791910),
                           INT64_MIN },
    { -INT64_C( 3772177180371941352),
      -INT64_C( 5109820246888064451),
                           INT64_MIN },
    {  INT64_C( 7339561494951511462),
       INT64_C( 6981982712417181895),
       INT64_C(                  50) },
    { -INT64_C( 4528610749391635324),
       INT64_C( 3947069241537612414),
                           INT64_MIN },
    { -INT64_C( 6717941440531890668),
      -INT64_C( 3378984720056758157),
                           INT64_MIN },
    {  INT64_C( 4445427486224652907),
       INT64_C( 5432766354678245790),
       INT64_C(                   0) },
    {  INT64_C( 2524954444067216782),
       INT64_C( 8205270470730159808),
       INT64_C(                   0) },
    { -INT64_C(  175621284349080684),
       INT64_C( 8718284890856807034),
                           INT64_MIN },
    { -INT64_C( 2809706200451471314),
       INT64_C( 8068133704597692545),
      -INT64_C(                   1) },
    { -INT64_C( 2005418597353891633),
       INT64_C( 1625399140547974956),
                           INT64_MIN },
    { -INT64_C( 2653193737618559172),
      -INT64_C( 6475796006253292586),
      -INT64_C(              603267) },
    {  INT64_C( 7133139092179837873),
       INT64_C( 7229974121251705943),
                           INT64_MAX },
    {  INT64_C( 1705710054238866294),
       INT64_C( 1691077912428088825),
       INT64_C(   13325859798741142) },
    { -INT64_C( 6672592694873600819),
       INT64_C( 6723939007155396548),
      -INT64_C(                   6) },
    { -INT64_C( 1666936663211964027),
       INT64_C( 6801334358091867878),
      -INT64_C(         24839291919) },
    { -INT64_C( 8544234745022540675),
       INT64_C( 1146947353500274854),
      -INT64_C(                   1) },
    { -INT64_C( 2979497356395472945),
       INT64_C( 1028937901605544025),
                           INT64_MIN },
    {  INT64_C( 1686390737527613722),
       INT64_C( 8227107450527210899),
       INT64_C(                   0) },
    {  INT64_C(  967384091079999909),
       INT64_C( 3374671754759147318),
                           INT64_MAX },
    { -INT64_C( 8976108431701332761),
       INT64_C( 5072968121462100561),
                           INT64_MIN },
    { -INT64_C( 6660744213680056625),
      -INT64_C( 6117505929305159977),
      -INT64_C(             3028956) },
    { -INT64_C( 1341947770419599379),
      -INT64_C( 7031727813671386748),
      -INT64_C(                   1) },
    {  INT64_C( 7417342340318185183),
      -INT64_C( 8599784446720058825),
                           INT64_MAX },
    { -INT64_C( 6908868053478036844),
       INT64_C( 2824934855081722055),
      -INT64_C(                  48) },
    {  INT64_C( 4425739936317265269),
      -INT64_C( 4620445645697073731),
       INT64_C(                   0) },
    { -INT64_C( 3294650258684951157),
      -INT64_C( 5729251372278739955),
                           INT64_MIN },
    {  INT64_C( 1239651346738967025),
      -INT64_C( 2682093349771776291),
       INT64_C(            36078602) },
    { -INT64_C( 3355804301061343600),
       INT64_C( 7116150791243027925),
      -INT64_C(              381511) },
    {  INT64_C( 8357429212832429718),
       INT64_C( 4622173917496960507),
       INT64_C(  261169662901013428) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    int64_t r = simde_vqshld_s64(test_vec[i].a, test_vec[i].b);

    simde_assert_equal_i64(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 32 ; i++) {
    int64_t a = simde_test_codegen_random_i64() >> (simde_test_codegen_random_i64() & 31);
    int64_t b = simde_test_codegen_random_i64() & 63;
    int64_t r = simde_vqshld_s64(a, b);

    simde_test_codegen_write_i64(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_i64(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i64(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  for (int i = 0 ; i < 32 ; i++) {
    int64_t a = simde_test_codegen_random_i64();
    int64_t b = simde_test_codegen_random_i64();
    int64_t r = simde_vqshld_s64(a, b);

    simde_test_codegen_write_i64(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_i64(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i64(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vqshlb_u8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint8_t a;
    int8_t b;
    uint8_t r;
  } test_vec[] = {
    { UINT8_C( 92),
      -INT8_C(  10),
      UINT8_C(  0) },
    { UINT8_C( 13),
      -INT8_C(   9),
      UINT8_C(  0) },
    { UINT8_C( 15),
       INT8_C(  14),
         UINT8_MAX },
    { UINT8_C(  2),
       INT8_C(  15),
         UINT8_MAX },
    { UINT8_C(  6),
       INT8_C(  10),
         UINT8_MAX },
    { UINT8_C(  1),
       INT8_C(   0),
      UINT8_C(  1) },
    { UINT8_C( 10),
      -INT8_C(   9),
      UINT8_C(  0) },
    { UINT8_C(  1),
       INT8_C(  13),
         UINT8_MAX },
    { UINT8_C(  9),
       INT8_C(   2),
      UINT8_C( 36) },
    { UINT8_C(  0),
       INT8_C(   1),
      UINT8_C(  0) },
    { UINT8_C(  0),
      -INT8_C(   6),
      UINT8_C(  0) },
    { UINT8_C(  2),
       INT8_C(   6),
      UINT8_C(128) },
    { UINT8_C(  2),
       INT8_C(   1),
      UINT8_C(  4) },
    { UINT8_C( 18),
       INT8_C(   0),
      UINT8_C( 18) },
    { UINT8_C( 28),
       INT8_C(   5),
         UINT8_MAX },
    { UINT8_C( 43),
      -INT8_C(  13),
      UINT8_C(  0) },
    { UINT8_C(  1),
      -INT8_C(  10),
      UINT8_C(  0) },
    { UINT8_C(  1),
      -INT8_C(  11),
      UINT8_C(  0) },
    { UINT8_C( 24),
       INT8_C(   9),
         UINT8_MAX },
    { UINT8_C( 50),
       INT8_C(   8),
         UINT8_MAX },
    { UINT8_C(  0),
       INT8_C(   0),
      UINT8_C(  0) },
    { UINT8_C( 31),
      -INT8_C(   3),
      UINT8_C(  3) },
    { UINT8_C(  0),
      -INT8_C(   7),
      UINT8_C(  0) },
    { UINT8_C( 59),
      -INT8_C(  12),
      UINT8_C(  0) },
    { UINT8_C( 17),
       INT8_C(   7),
         UINT8_MAX },
    { UINT8_C(  4),
       INT8_C(   0),
      UINT8_C(  4) },
    { UINT8_C( 71),
       INT8_C(  12),
         UINT8_MAX },
    { UINT8_C(  5),
      -INT8_C(  13),
      UINT8_C(  0) },
    { UINT8_C( 14),
      -INT8_C(  10),
      UINT8_C(  0) },
    { UINT8_C(  0),
      -INT8_C(   9),
      UINT8_C(  0) },
    { UINT8_C( 14),
      -INT8_C(   2),
      UINT8_C(  3) },
    { UINT8_C(187),
      -INT8_C(  15),
      UINT8_C(  0) },
    { UINT8_C(137),
       INT8_C(  28),
         UINT8_MAX },
    { UINT8_C(216),
       INT8_C(  34),
         UINT8_MAX },
    { UINT8_C(146),
      -INT8_C( 111),
      UINT8_C(  0) },
    { UINT8_C( 23),
      -INT8_C(  40),
      UINT8_C(  0) },
    { UINT8_C( 43),
       INT8_C(  46),
         UINT8_MAX },
    { UINT8_C(116),
      -INT8_C(  15),
      UINT8_C(  0) },
    { UINT8_C(158),
       INT8_C(   2),
         UINT8_MAX },
    { UINT8_C(210),
      -INT8_C(  69),
      UINT8_C(  0) },
    { UINT8_C( 87),
       INT8_C(  87),
         UINT8_MAX },
    { UINT8_C( 78),
       INT8_C(  64),
         UINT8_MAX },
    { UINT8_C(155),
      -INT8_C(  11),
      UINT8_C(  0) },
    { UINT8_C(115),
       INT8_C(  18),
         UINT8_MAX },
    { UINT8_C(236),
      -INT8_C(  81),
      UINT8_C(  0) },
    { UINT8_C(252),
      -INT8_C( 102),
      UINT8_C(  0) },
    { UINT8_C(106),
      -INT8_C(  28),
      UINT8_C(  0) },
    { UINT8_C( 75),
      -INT8_C(  13),
      UINT8_C(  0) },
    { UINT8_C(  0),
       INT8_C(  36),
      UINT8_C(  0) },
    { UINT8_C( 22),
      -INT8_C( 109),
      UINT8_C(  0) },
    { UINT8_C(181),
       INT8_C(  45),
         UINT8_MAX },
    { UINT8_C(107),
      -INT8_C(  31),
      UINT8_C(  0) },
    { UINT8_C( 91),
      -INT8_C(  33),
      UINT8_C(  0) },
    { UINT8_C(210),
      -INT8_C(   6),
      UINT8_C(  3) },
    { UINT8_C(226),
      -INT8_C(  92),
      UINT8_C(  0) },
    { UINT8_C(181),
       INT8_C(  57),
         UINT8_MAX },
    { UINT8_C(251),
       INT8_C(   3),
         UINT8_MAX },
    { UINT8_C(121),
      -INT8_C( 105),
      UINT8_C(  0) },
    { UINT8_C(248),
      -INT8_C(  19),
      UINT8_C(  0) },
    { UINT8_C(169),
      -INT8_C(  28),
      UINT8_C(  0) },
    { UINT8_C(156),
      -INT8_C(  91),
      UINT8_C(  0) },
    { UINT8_C(126),
       INT8_C(   6),
         UINT8_MAX },
    { UINT8_C(137),
      -INT8_C(  54),
      UINT8_C(  0) },
    { UINT8_C(250),
      -INT8_C( 119),
      UINT8_C(  0) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    uint8_t r = simde_vqshlb_u8(test_vec[i].a, test_vec[i].b);

    simde_assert_equal_u8(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 32 ; i++) {
    uint8_t a = simde_test_codegen_random_u8() >> (simde_test_codegen_random_u8() & 7);
    int8_t b = simde_test_codegen_random_i8() % 16;
    uint8_t r = simde_vqshlb_u8(a, b);

    simde_test_codegen_write_u8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_i8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_u8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  for (int i = 0 ; i < 32 ; i++) {
    uint8_t a = simde_test_codegen_random_u8();
    int8_t b = simde_test_codegen_random_i8();
    uint8_t r = simde_vqshlb_u8(a, b);

    simde_test_codegen_write_u8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_i8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_u8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vqshlh_u16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint16_t a;
    int16_t b;
    uint16_t r;
  } test_vec[] = {
    { UINT16_C(  438),
      -INT16_C(    13),
      UINT16_C(    0) },
    { UINT16_C( 4827),
       INT16_C(    31),
           UINT16_MAX },
    { UINT16_C(  318),
       INT16_C(     8),
           UINT16_MAX },
    { UINT16_C(27051),
       INT16_C(    16),
           UINT16_MAX },
    { UINT16_C(  688),
      -INT16_C(    21),
      UINT16_C(    0) },
    { UINT16_C(  752),
       INT16_C(     1),
      UINT16_C( 1504) },
    { UINT16_C(    1),
      -INT16_C(    31),
      UINT16_C(    0) },
    { UINT16_C(    2),
       INT16_C(     0),
      UINT16_C(    2) },
    { UINT16_C(   92),
      -INT16_C(    22),
      UINT16_C(    0) },
    { UINT16_C(  687),
      -INT16_C(    11),
      UINT16_C(    0) },
    { UINT16_C(    4),
       INT16_C(     8),
      UINT16_C( 1024) },
    { UINT16_C(    6),
      -INT16_C(     2),
      UINT16_C(    1) },
    { UINT16_C(    1),
      -INT16_C(     7),
      UINT16_C(    0) },
    { UINT16_C(  211),
      -INT16_C(    18),
      UINT16_C(    0) },
    { UINT16_C(  248),
      -INT16_C(    16),
      UINT16_C(    0) },
    { UINT16_C(  351),
      -INT16_C(    12),
      UINT16_C(    0) },
    { UINT16_C( 2361),
       INT16_C(     0),
      UINT16_C( 2361) },
    { UINT16_C(    1),
      -INT16_C(    25),
      UINT16_C(    0) },
    { UINT16_C(   25),
      -INT16_C(    15),
      UINT16_C(    0) },
    { UINT16_C(  933),
      -INT16_C(     5),
      UINT16_C(   29) },
    { UINT16_C( 3382),
       INT16_C(    24),
           UINT16_MAX },
    { UINT16_C(   13),
       INT16_C(     9),
      UINT16_C( 6656) },
    { UINT16_C(  183),
       INT16_C(     5),
      UINT16_C( 5856) },
    { UINT16_C(  178),
       INT16_C(    24),
           UINT16_MAX },
    { UINT16_C(    4),
      -INT16_C(     1),
      UINT16_C(    2) },
    { UINT16_C(    6),
      -INT16_C(    17),
      UINT16_C(    0) },
    { UINT16_C(    2),
      -INT16_C(    26),
      UINT16_C(    0) },
    { UINT16_C(    0),
      -INT16_C(     5),
      UINT16_C(    0) },
    { UINT16_C(   42),
       INT16_C(    11),
           UINT16_MAX },
    { UINT16_C(    0),
      -INT16_C(    16),
      UINT16_C(    0) },
    { UINT16_C(   34),
       INT16_C(     9),
      UINT16_C(17408) },
    { UINT16_C(    4),
       INT16_C(     3),
      UINT16_C(   32) },
    { UINT16_C(20950),
      -INT16_C( 31334),
      UINT16_C(    0) },
    { UINT16_C(62728),
       INT16_C(  3610),
           UINT16_MAX },
    { UINT16_C(24842),
       INT16_C( 13869),
           UINT16_MAX },
    { UINT16_C(38272),
       INT16_C(  8033),
           UINT16_MAX },
    { UINT16_C(61882),
      -INT16_C(  9795),
      UINT16_C(    0) },
    { UINT16_C(51067),
       INT16_C( 17860),
      UINT16_C(    0) },
    { UINT16_C(29664),
      -INT16_C( 29850),
           UINT16_MAX },
    { UINT16_C( 2385),
       INT16_C( 10236),
      UINT16_C(  149) },
    { UINT16_C(38491),
       INT16_C( 25517),
      UINT16_C(    0) },
    { UINT16_C(51083),
      -INT16_C( 27023),
           UINT16_MAX },
    { UINT16_C(40488),
      -INT16_C( 22324),
      UINT16_C(    0) },
    { UINT16_C(11571),
      -INT16_C(  4409),
      UINT16_C(    0) },
    { UINT16_C(33822),
      -INT16_C( 26169),
      UINT16_C(    0) },
    { UINT16_C(35660),
       INT16_C( 11486),
      UINT16_C(    0) },
    { UINT16_C(17662),
       INT16_C( 20664),
      UINT16_C(    0) },
    { UINT16_C(46158),
      -INT16_C( 22153),
           UINT16_MAX },
    { UINT16_C( 9291),
      -INT16_C( 10740),
           UINT16_MAX },
    { UINT16_C(32235),
       INT16_C(  4972),
           UINT16_MAX },
    { UINT16_C(14364),
       INT16_C( 20411),
      UINT16_C(    0) },
    { UINT16_C(33381),
      -INT16_C( 31939),
           UINT16_MAX },
    { UINT16_C( 1031),
       INT16_C( 21277),
           UINT16_MAX },
    { UINT16_C(64399),
      -INT16_C( 29057),
           UINT16_MAX },
    { UINT16_C(14144),
      -INT16_C( 28962),
      UINT16_C(    0) },
    { UINT16_C(21996),
       INT16_C( 14135),
           UINT16_MAX },
    { UINT16_C(17274),
       INT16_C( 25869),
           UINT16_MAX },
    { UINT16_C(31424),
      -INT16_C(  9095),
           UINT16_MAX },
    { UINT16_C(13490),
       INT16_C(  6188),
           UINT16_MAX },
    { UINT16_C(27063),
      -INT16_C( 16741),
      UINT16_C(    0) },
    { UINT16_C(47214),
      -INT16_C(   751),
           UINT16_MAX },
    { UINT16_C(37044),
      -INT16_C(  2933),
      UINT16_C(    0) },
    { UINT16_C(27080),
      -INT16_C( 19326),
      UINT16_C(    0) },
    { UINT16_C(47551),
       INT16_C( 14827),
      UINT16_C(    0) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    uint16_t r = simde_vqshlh_u16(test_vec[i].a, test_vec[i].b);

    simde_assert_equal_u16(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 32 ; i++) {
    uint16_t a = simde_test_codegen_random_u16() >> (simde_test_codegen_random_u16() & 15);
    int16_t b = simde_test_codegen_random_i16() % 32;
    uint16_t r = simde_vqshlh_u16(a, b);

    simde_test_codegen_write_u16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_i16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_u16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  for (int i = 0 ; i < 32 ; i++) {
    uint16_t a = simde_test_codegen_random_u16();
    int16_t b = simde_test_codegen_random_i16();
    uint16_t r = simde_vqshlh_u16(a, b);

    simde_test_codegen_write_u16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_i16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_u16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vqshls_u32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint32_t a;
    int32_t b;
    uint32_t r;
  } test_vec[] = {
    { UINT32_C(    361782),
       INT32_C(          11),
      UINT32_C( 740929536) },
    { UINT32_C( 733482402),
       INT32_C(          12),
                UINT32_MAX },
    { UINT32_C(        45),
       INT32_C(          55),
                UINT32_MAX },
    { UINT32_C(        18),
       INT32_C(          17),
      UINT32_C(   2359296) },
    { UINT32_C(         0),
       INT32_C(          32),
      UINT32_C(         0) },
    { UINT32_C(     38501),
       INT32_C(          35),
                UINT32_MAX },
    { UINT32_C(         3),
       INT32_C(          35),
                UINT32_MAX },
    { UINT32_C(   3571217),
       INT32_C(          54),
                UINT32_MAX },
    { UINT32_C(      8922),
       INT32_C(          46),
                UINT32_MAX },
    { UINT32_C(     24353),
       INT32_C(          33),
                UINT32_MAX },
    { UINT32_C(      1906),
       INT32_C(          18),
      UINT32_C( 499646464) },
    { UINT32_C(         0),
       INT32_C(           3),
      UINT32_C(         0) },
    { UINT32_C(         8),
       INT32_C(          61),
                UINT32_MAX },
    { UINT32_C(         9),
       INT32_C(          50),
                UINT32_MAX },
    { UINT32_C(   6386253),
       INT32_C(          50),
                UINT32_MAX },
    { UINT32_C(        25),
       INT32_C(           8),
      UINT32_C(      6400) },
    { UINT32_C(       917),
       INT32_C(          26),
                UINT32_MAX },
    { UINT32_C(         1),
       INT32_C(          21),
      UINT32_C(   2097152) },
    { UINT32_C(        63),
       INT32_C(          13),
      UINT32_C(    516096) },
    { UINT32_C(    102087),
       INT32_C(          24),
                UINT32_MAX },
    { UINT32_C(    159940),
       INT32_C(          33),
                UINT32_MAX },
    { UINT32_C(       113),
       INT32_C(          16),
      UINT32_C(   7405568) },
    { UINT32_C(    454362),
       INT32_C(          37),
                UINT32_MAX },
    { UINT32_C(     53481),
       INT32_C(          28),
                UINT32_MAX },
    { UINT32_C(         0),
       INT32_C(          59),
      UINT32_C(         0) },
    { UINT32_C(        24),
       INT32_C(          39),
                UINT32_MAX },
    { UINT32_C(  28215471),
       INT32_C(           2),
      UINT32_C( 112861884) },
    { UINT32_C(   7364106),
       INT32_C(           2),
      UINT32_C(  29456424) },
    { UINT32_C(         1),
       INT32_C(          17),
      UINT32_C(    131072) },
    { UINT32_C(     74260),
       INT32_C(          18),
                UINT32_MAX },
    { UINT32_C(       251),
       INT32_C(          49),
                UINT32_MAX },
    { UINT32_C(     45415),
       INT32_C(          29),
                UINT32_MAX },
    { UINT32_C(2405066877),
       INT32_C(    76080137),
                UINT32_MAX },
    { UINT32_C(3380683282),
      -INT32_C(   260793154),
      UINT32_C(         0) },
    { UINT32_C(2495429172),
      -INT32_C(  1572526767),
                UINT32_MAX },
    { UINT32_C(1580772416),
       INT32_C(   357111448),
      UINT32_C(         0) },
    { UINT32_C(2275779454),
      -INT32_C(  1702154872),
      UINT32_C(         0) },
    { UINT32_C( 224660559),
      -INT32_C(   570566488),
      UINT32_C(         0) },
    { UINT32_C(1685175059),
       INT32_C(   537310944),
      UINT32_C(         0) },
    { UINT32_C(4202577506),
      -INT32_C(   770652076),
                UINT32_MAX },
    { UINT32_C(4082742635),
       INT32_C(   831448290),
      UINT32_C(         3) },
    { UINT32_C(2571039473),
      -INT32_C(   579453750),
      UINT32_C(         0) },
    { UINT32_C(3611486199),
      -INT32_C(      571235),
      UINT32_C(         0) },
    { UINT32_C(3690624647),
      -INT32_C(  1448211906),
                UINT32_MAX },
    { UINT32_C(2711422911),
      -INT32_C(   573428756),
      UINT32_C(      2585) },
    { UINT32_C(3883274269),
       INT32_C(  1137044812),
                UINT32_MAX },
    { UINT32_C(1914308564),
      -INT32_C(   697232817),
                UINT32_MAX },
    { UINT32_C(3333581704),
       INT32_C(   879714421),
                UINT32_MAX },
    { UINT32_C(1406471271),
       INT32_C(  1412474679),
                UINT32_MAX },
    { UINT32_C(  71083960),
       INT32_C(  1749549460),
      UINT32_C(         0) },
    { UINT32_C(1473929736),
      -INT32_C(    64074636),
                UINT32_MAX },
    { UINT32_C( 767746231),
      -INT32_C(  1486802368),
                UINT32_MAX },
    { UINT32_C(1996175166),
      -INT32_C(  1765135394),
      UINT32_C(         0) },
    { UINT32_C(1721435858),
       INT32_C(   265282311),
                UINT32_MAX },
    { UINT32_C(3127355717),
      -INT32_C(  1380542987),
      UINT32_C(   1527029) },
    { UINT32_C(3050994037),
      -INT32_C(   379831381),
      UINT32_C(         0) },
    { UINT32_C(1365202802),
       INT32_C(  1441213059),
      UINT32_C(         0) },
    { UINT32_C( 951878192),
      -INT32_C(  1421374619),
                UINT32_MAX },
    { UINT32_C( 711306804),
      -INT32_C(  1193862333),
                UINT32_MAX },
    { UINT32_C(1064153492),
       INT32_C(  1596574444),
      UINT32_C(      1014) },
    { UINT32_C(2763032609),
      -INT32_C(   470116430),
      UINT32_C(         0) },
    { UINT32_C(2132522522),
       INT32_C(  1965711937),
                UINT32_MAX },
    { UINT32_C(1419742993),
       INT32_C(  1057846955),
      UINT32_C(         0) },
    { UINT32_C( 343898663),
       INT32_C(  1718855748),
                UINT32_MAX },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    uint32_t r = simde_vqshls_u32(test_vec[i].a, test_vec[i].b);

    simde_assert_equal_u32(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 32 ; i++) {
    uint32_t a = simde_test_codegen_random_u32() >> (simde_test_codegen_random_u32() & 31);
    int32_t b = simde_test_codegen_random_u32() % 64;
    uint32_t r = simde_vqshls_u32(a, b);

    simde_test_codegen_write_u32(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_i32(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_u32(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  for (int i = 0 ; i < 32 ; i++) {
    uint32_t a = simde_test_codegen_random_u32();
    int32_t b = simde_test_codegen_random_u32();
    uint32_t r = simde_vqshls_u32(a, b);

    simde_test_codegen_write_u32(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_i32(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_u32(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vqshld_u64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint64_t a;
    int64_t b;
    uint64_t r;
  } test_vec[] = {
    { UINT64_C(        183866033650),
       INT64_C(                   4),
      UINT64_C(       2941856538400) },
    { UINT64_C(         21089992168),
      -INT64_C(                  32),
      UINT64_C(                   4) },
    { UINT64_C(        374647962792),
      -INT64_C(                  14),
      UINT64_C(            22866696) },
    { UINT64_C(     532647477413927),
      -INT64_C(                  23),
      UINT64_C(            63496527) },
    { UINT64_C(      11057802498083),
      -INT64_C(                  37),
      UINT64_C(                  80) },
    { UINT64_C(        522392987228),
       INT64_C(                  45),
                          UINT64_MAX },
    { UINT64_C(    4886096686954538),
       INT64_C(                  18),
                          UINT64_MAX },
    { UINT64_C(   42462571399247667),
       INT64_C(                  40),
                          UINT64_MAX },
    { UINT64_C(    2665792981257447),
      -INT64_C(                  58),
      UINT64_C(                   0) },
    { UINT64_C(     126176952856937),
       INT64_C(                  52),
                          UINT64_MAX },
    { UINT64_C(         42118751396),
       INT64_C(                  44),
                          UINT64_MAX },
    { UINT64_C(      16412306278963),
      -INT64_C(                   2),
      UINT64_C(       4103076569740) },
    { UINT64_C(     126846483618011),
       INT64_C(                  25),
                          UINT64_MAX },
    { UINT64_C(     188955178628796),
      -INT64_C(                  25),
      UINT64_C(             5631303) },
    { UINT64_C(   11893523753086503),
       INT64_C(                   0),
      UINT64_C(   11893523753086503) },
    { UINT64_C( 2149941896915331978),
      -INT64_C(                  12),
      UINT64_C(     524888158426594) },
    { UINT64_C(          3023396958),
       INT64_C(                  56),
                          UINT64_MAX },
    { UINT64_C(          2513847216),
       INT64_C(                  43),
                          UINT64_MAX },
    { UINT64_C(    1764507551197969),
      -INT64_C(                  17),
      UINT64_C(         13462124261) },
    { UINT64_C(    5734492454037041),
      -INT64_C(                  15),
      UINT64_C(        175002821473) },
    { UINT64_C(      58136807991560),
       INT64_C(                  33),
                          UINT64_MAX },
    { UINT64_C( 2448556644355543150),
       INT64_C(                  52),
                          UINT64_MAX },
    { UINT64_C( 3239953245059005003),
      -INT64_C(                  34),
      UINT64_C(           188590099) },
    { UINT64_C(      34461270701508),
       INT64_C(                  47),
                          UINT64_MAX },
    { UINT64_C(  152189993257588583),
       INT64_C(                  38),
                          UINT64_MAX },
    { UINT64_C(    1414182626672464),
       INT64_C(                   0),
      UINT64_C(    1414182626672464) },
    { UINT64_C(      33583860916806),
       INT64_C(                  35),
                          UINT64_MAX },
    { UINT64_C(     248927369104612),
      -INT64_C(                  44),
      UINT64_C(                  14) },
    { UINT64_C(       6745142361563),
       INT64_C(                  48),
                          UINT64_MAX },
    { UINT64_C(     133465845500345),
      -INT64_C(                  62),
      UINT64_C(                   0) },
    { UINT64_C(        349466480417),
      -INT64_C(                  12),
      UINT64_C(            85318964) },
    { UINT64_C(       3462032895839),
       INT64_C(                  54),
                          UINT64_MAX },
    { UINT64_C(12092059502143658539),
      -INT64_C( 6812253075605054399),
                          UINT64_MAX },
    { UINT64_C( 4680064967690846736),
      -INT64_C( 5341577524864075621),
      UINT64_C(                   0) },
    { UINT64_C(16750717317971773122),
       INT64_C(  624042083762894108),
                          UINT64_MAX },
    { UINT64_C( 2889269776890044301),
       INT64_C(  448047984021298423),
      UINT64_C(    5643105032988367) },
    { UINT64_C( 9610200471680903376),
      -INT64_C( 8484721236779338945),
                          UINT64_MAX },
    { UINT64_C(14090490877418016213),
       INT64_C( 1162065318622099158),
      UINT64_C(             3203806) },
    { UINT64_C( 9174928928077706596),
      -INT64_C( 1485917299097018152),
      UINT64_C(             8344549) },
    { UINT64_C( 1338653468970107395),
      -INT64_C( 5143025748865591216),
                          UINT64_MAX },
    { UINT64_C(16429651563376944962),
      -INT64_C( 5640167344728066119),
      UINT64_C(                   0) },
    { UINT64_C( 3686782210540636635),
      -INT64_C( 1731523400099932180),
      UINT64_C(       3515989504376) },
    { UINT64_C( 1187659851177229963),
       INT64_C( 3062898884874286369),
                          UINT64_MAX },
    { UINT64_C(  196305803253187235),
       INT64_C( 7876297542387006914),
      UINT64_C(                   0) },
    { UINT64_C( 4765230760225781689),
       INT64_C( 4408623374944829621),
      UINT64_C(                   0) },
    { UINT64_C(11361875817358651285),
      -INT64_C( 2140808333122801670),
      UINT64_C(  177529309646228926) },
    { UINT64_C( 9614363659517251337),
      -INT64_C( 6346496483989553388),
                          UINT64_MAX },
    { UINT64_C( 2855281257536991270),
      -INT64_C(    1602031005162514),
      UINT64_C(      10892033605716) },
    { UINT64_C( 1581210976549268893),
       INT64_C( 6399528420212242966),
                          UINT64_MAX },
    { UINT64_C( 1060026106026467681),
      -INT64_C( 6588450662489146980),
      UINT64_C(                   0) },
    { UINT64_C( 7503843955559217932),
      -INT64_C(  502609199036831875),
                          UINT64_MAX },
    { UINT64_C(17631097042061713536),
       INT64_C(   45626382453495030),
      UINT64_C(   17217868205138392) },
    { UINT64_C( 3714960301507851219),
      -INT64_C(   23951217166049512),
                          UINT64_MAX },
    { UINT64_C( 7319843006408765768),
       INT64_C(  510319849736706850),
                          UINT64_MAX },
    { UINT64_C( 7755967475307324345),
      -INT64_C( 5523446778611072038),
      UINT64_C(            28216045) },
    { UINT64_C( 7479328090457700343),
      -INT64_C( 1423258208537072124),
                          UINT64_MAX },
    { UINT64_C(  177044629476830389),
       INT64_C( 5665725517146067073),
      UINT64_C(                   0) },
    { UINT64_C(16237587572710503594),
       INT64_C( 2075412206452331693),
      UINT64_C(                   0) },
    { UINT64_C(12100778740752394436),
      -INT64_C( 6426860983635719894),
                          UINT64_MAX },
    { UINT64_C(12675079893715157799),
       INT64_C( 2037417415155908546),
      UINT64_C(                   2) },
    { UINT64_C( 3482115966115539845),
       INT64_C( 4675440209028048191),
                          UINT64_MAX },
    { UINT64_C( 3005074568538060803),
       INT64_C( 2711053315848946474),
                          UINT64_MAX },
    { UINT64_C(15940810418219427588),
       INT64_C( 7881857256098753031),
                          UINT64_MAX },
    { UINT64_C(18087343211205011059),
      -INT64_C(  995544084410116758),
                          UINT64_MAX },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    uint64_t r = simde_vqshld_u64(test_vec[i].a, test_vec[i].b);

    simde_assert_equal_u64(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 32 ; i++) {
    uint64_t a = simde_test_codegen_random_u64() >> (simde_test_codegen_random_u64() & 31);
    int64_t b = simde_test_codegen_random_i64() % 64;
    uint64_t r = simde_vqshld_u64(a, b);

    simde_test_codegen_write_u64(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_i64(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_u64(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  for (int i = 0 ; i < 32 ; i++) {
    uint64_t a = simde_test_codegen_random_u64();
    int64_t b = simde_test_codegen_random_i64();
    uint64_t r = simde_vqshld_u64(a, b);

    simde_test_codegen_write_u64(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_i64(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_u64(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vqshl_s8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int8_t a[8];
    int8_t b[8];
    int8_t r[8];
  } test_vec[] = {
    { {  INT8_C(   0), -INT8_C(   3),  INT8_C(   1), -INT8_C(   2), -INT8_C(   1),  INT8_C(  87),  INT8_C(   6),  INT8_C(   8) },
      {  INT8_C(   4),  INT8_C(  11),  INT8_C(  13),  INT8_C(   5),  INT8_C(   3),  INT8_C(  12),  INT8_C(  10),  INT8_C(   9) },
      {  INT8_C(   0),      INT8_MIN,      INT8_MAX, -INT8_C(  64), -INT8_C(   8),      INT8_MAX,      INT8_MAX,      INT8_MAX } },
    { {  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),  INT8_C(  45),  INT8_C(  11), -INT8_C(  87), -INT8_C(  18),  INT8_C( 109) },
      {  INT8_C(  13),  INT8_C(  13),  INT8_C(  11),  INT8_C(   7),  INT8_C(   4),  INT8_C(   2),  INT8_C(   9),  INT8_C(   8) },
      {  INT8_C(   0),      INT8_MIN,  INT8_C(   0),      INT8_MAX,      INT8_MAX,      INT8_MIN,      INT8_MIN,      INT8_MAX } },
    { {  INT8_C( 124),  INT8_C(   4), -INT8_C(  15), -INT8_C(   3),  INT8_C(   0),  INT8_C(   0), -INT8_C(   2),  INT8_C(   2) },
      {  INT8_C(  10),  INT8_C(  12),  INT8_C(  11),  INT8_C(   4),  INT8_C(   5),  INT8_C(   3),  INT8_C(   1),  INT8_C(   2) },
      {      INT8_MAX,      INT8_MAX,      INT8_MIN, -INT8_C(  48),  INT8_C(   0),  INT8_C(   0), -INT8_C(   4),  INT8_C(   8) } },
    { { -INT8_C(  15), -INT8_C(  13), -INT8_C(   5), -INT8_C(  99),  INT8_C(   0),  INT8_C(   3),  INT8_C(   2), -INT8_C(   1) },
      {  INT8_C(   0),  INT8_C(  12),  INT8_C(  10),  INT8_C(   8),  INT8_C(  13),  INT8_C(  15),  INT8_C(   8),  INT8_C(   7) },
      { -INT8_C(  15),      INT8_MIN,      INT8_MIN,      INT8_MIN,  INT8_C(   0),      INT8_MAX,      INT8_MAX,      INT8_MIN } },
    { {  INT8_C(  52), -INT8_C(  13), -INT8_C(   8),  INT8_C(   1), -INT8_C(  24),  INT8_C(   4), -INT8_C(   2),  INT8_C(   1) },
      {  INT8_C(   5),  INT8_C(   3),  INT8_C(   7),  INT8_C(   8),  INT8_C(  12),  INT8_C(  13),  INT8_C(   8),  INT8_C(  12) },
      {      INT8_MAX, -INT8_C( 104),      INT8_MIN,      INT8_MAX,      INT8_MIN,      INT8_MAX,      INT8_MIN,      INT8_MAX } },
    { {  INT8_C(  15),  INT8_C( 105),  INT8_C(   0),  INT8_C(   0),  INT8_C(   1), -INT8_C(   1),  INT8_C(  30), -INT8_C(   2) },
      {  INT8_C(  14),  INT8_C(   8),  INT8_C(   8),  INT8_C(  14),  INT8_C(   2),  INT8_C(  14),  INT8_C(   9),  INT8_C(   7) },
      {      INT8_MAX,      INT8_MAX,  INT8_C(   0),  INT8_C(   0),  INT8_C(   4),      INT8_MIN,      INT8_MAX,      INT8_MIN } },
    { {  INT8_C(   7), -INT8_C(   3),  INT8_C(   1),  INT8_C(   0),  INT8_C(  52), -INT8_C(   2), -INT8_C(   4), -INT8_C(  15) },
      {  INT8_C(   4),  INT8_C(   7),  INT8_C(  14),  INT8_C(  11),  INT8_C(   8),  INT8_C(  10),  INT8_C(  11),  INT8_C(   6) },
      {  INT8_C( 112),      INT8_MIN,      INT8_MAX,  INT8_C(   0),      INT8_MAX,      INT8_MIN,      INT8_MIN,      INT8_MIN } },
    { {  INT8_C(  19), -INT8_C(   1), -INT8_C(  24),  INT8_C(  11),  INT8_C(   4),  INT8_C(   0), -INT8_C(  31),  INT8_C(   2) },
      {  INT8_C(   7),  INT8_C(  15),  INT8_C(   9),  INT8_C(   1),  INT8_C(  10),  INT8_C(   2),  INT8_C(   9),  INT8_C(  15) },
      {      INT8_MAX,      INT8_MIN,      INT8_MIN,  INT8_C(  22),      INT8_MAX,  INT8_C(   0),      INT8_MIN,      INT8_MAX } },
    { { -INT8_C(  72), -INT8_C(  13), -INT8_C(  54), -INT8_C(  11),  INT8_C(   0),  INT8_C(  59),  INT8_C(  31),  INT8_C(   0) },
      {  INT8_C(   1),  INT8_C(  13),  INT8_C(   6),  INT8_C(   4),  INT8_C(   7),  INT8_C(   9),  INT8_C(   1),  INT8_C(  15) },
      {      INT8_MIN,      INT8_MIN,      INT8_MIN,      INT8_MIN,  INT8_C(   0),      INT8_MAX,  INT8_C(  62),  INT8_C(   0) } },
    { {  INT8_C(   1), -INT8_C(   3), -INT8_C(   2), -INT8_C(   3), -INT8_C(   1),  INT8_C(   0), -INT8_C(   4), -INT8_C(   1) },
      {  INT8_C(   0),  INT8_C(   2),  INT8_C(   3),  INT8_C(  12),  INT8_C(   8),  INT8_C(   0),  INT8_C(   7),  INT8_C(   9) },
      {  INT8_C(   1), -INT8_C(  12), -INT8_C(  16),      INT8_MIN,      INT8_MIN,  INT8_C(   0),      INT8_MIN,      INT8_MIN } },
    { {  INT8_C(   7),  INT8_C(   0), -INT8_C(   1),  INT8_C(   6), -INT8_C(   2), -INT8_C(   1),  INT8_C(   3), -INT8_C(   1) },
      {  INT8_C(   0),  INT8_C(   7),  INT8_C(   2),  INT8_C(   1),  INT8_C(  10),  INT8_C(  10),  INT8_C(  10),  INT8_C(  10) },
      {  INT8_C(   7),  INT8_C(   0), -INT8_C(   4),  INT8_C(  12),      INT8_MIN,      INT8_MIN,      INT8_MAX,      INT8_MIN } },
    { {  INT8_C(  45),  INT8_C(  26), -INT8_C( 126),  INT8_C(   2),  INT8_C(   1), -INT8_C(   7),  INT8_C(   0), -INT8_C( 107) },
      {  INT8_C(  11),  INT8_C(   3),  INT8_C(  12),  INT8_C(   9),  INT8_C(   7),  INT8_C(  10),  INT8_C(   8),  INT8_C(   7) },
      {      INT8_MAX,      INT8_MAX,      INT8_MIN,      INT8_MAX,      INT8_MAX,      INT8_MIN,  INT8_C(   0),      INT8_MIN } },
    { {  INT8_C(   0),  INT8_C(  30),  INT8_C(   4),  INT8_C(  13),  INT8_C(   7),  INT8_C(  49), -INT8_C(  14), -INT8_C(   7) },
      {  INT8_C(  13),  INT8_C(  13),  INT8_C(   8),  INT8_C(   8),  INT8_C(   4),  INT8_C(   9),  INT8_C(  13),  INT8_C(  15) },
      {  INT8_C(   0),      INT8_MAX,      INT8_MAX,      INT8_MAX,  INT8_C( 112),      INT8_MAX,      INT8_MIN,      INT8_MIN } },
    { {  INT8_C(   0), -INT8_C(   1),  INT8_C( 112), -INT8_C(   9),  INT8_C(   1),  INT8_C(   3), -INT8_C(  34),  INT8_C(   8) },
      {  INT8_C(   3),  INT8_C(   2),  INT8_C(   4),  INT8_C(  14),  INT8_C(   3),  INT8_C(   0),  INT8_C(   4),  INT8_C(   0) },
      {  INT8_C(   0), -INT8_C(   4),      INT8_MAX,      INT8_MIN,  INT8_C(   8),  INT8_C(   3),      INT8_MIN,  INT8_C(   8) } },
    { { -INT8_C(   2),  INT8_C(   6), -INT8_C(   2), -INT8_C(   5), -INT8_C(  18), -INT8_C(  56), -INT8_C(   1), -INT8_C(  62) },
      {  INT8_C(   3),  INT8_C(   6),  INT8_C(   0),  INT8_C(   8),  INT8_C(  12),  INT8_C(  14),  INT8_C(  14),  INT8_C(  15) },
      { -INT8_C(  16),      INT8_MAX, -INT8_C(   2),      INT8_MIN,      INT8_MIN,      INT8_MIN,      INT8_MIN,      INT8_MIN } },
    { {  INT8_C(   0), -INT8_C(   2),  INT8_C(   0),  INT8_C(   5),  INT8_C(   5),  INT8_C(  25), -INT8_C(  60),  INT8_C(   2) },
      {  INT8_C(  10),  INT8_C(  14),  INT8_C(   2),  INT8_C(   3),  INT8_C(  15),  INT8_C(   8),  INT8_C(   5),  INT8_C(   3) },
      {  INT8_C(   0),      INT8_MIN,  INT8_C(   0),  INT8_C(  40),      INT8_MAX,      INT8_MAX,      INT8_MIN,  INT8_C(  16) } },
    { { -INT8_C(  68),  INT8_C(  70), -INT8_C(   7), -INT8_C(  18),  INT8_C(  72),  INT8_C(  45), -INT8_C(  18),  INT8_C( 118) },
      { -INT8_C(  54), -INT8_C(  16), -INT8_C( 117),  INT8_C(  29),  INT8_C(  34),  INT8_C(  19),  INT8_C( 110),  INT8_C( 108) },
      { -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),      INT8_MIN,      INT8_MAX,      INT8_MAX,      INT8_MIN,      INT8_MAX } },
    { {  INT8_C(  98),  INT8_C( 112),  INT8_C( 111),  INT8_C(  65),  INT8_C( 105),  INT8_C(  53), -INT8_C( 108), -INT8_C(  57) },
      { -INT8_C(  85), -INT8_C(  96),  INT8_C(   2), -INT8_C(  81), -INT8_C(  87), -INT8_C(  53),  INT8_C(  36),  INT8_C( 101) },
      {  INT8_C(   0),  INT8_C(   0),      INT8_MAX,  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),      INT8_MIN,      INT8_MIN } },
    { {  INT8_C(  18),  INT8_C(  29),  INT8_C(  84),  INT8_C(  90),  INT8_C(  75),  INT8_C(  66), -INT8_C(  48),  INT8_C(  21) },
      {  INT8_C(  50),  INT8_C(  92),  INT8_C(  50),  INT8_C(  84),  INT8_C( 111), -INT8_C(  96), -INT8_C(  63), -INT8_C(  47) },
      {      INT8_MAX,      INT8_MAX,      INT8_MAX,      INT8_MAX,      INT8_MAX,  INT8_C(   0), -INT8_C(   1),  INT8_C(   0) } },
    { {  INT8_C(  17),  INT8_C(  48),  INT8_C(  19),  INT8_C( 122),  INT8_C( 101), -INT8_C(  89),  INT8_C(  65),  INT8_C(  16) },
      {  INT8_C(  71),  INT8_C(  67), -INT8_C(  64), -INT8_C(  15),  INT8_C(  15), -INT8_C(  28),  INT8_C(  86),  INT8_C(  33) },
      {      INT8_MAX,      INT8_MAX,  INT8_C(   0),  INT8_C(   0),      INT8_MAX, -INT8_C(   1),      INT8_MAX,      INT8_MAX } },
    { {  INT8_C(   2), -INT8_C(  86),  INT8_C( 123),  INT8_C(  77), -INT8_C(  19),  INT8_C(  75),  INT8_C(  98),  INT8_C(  31) },
      { -INT8_C(  89), -INT8_C( 107),  INT8_C( 116),  INT8_C(  23),  INT8_C(  53),  INT8_C(  53), -INT8_C(  24),  INT8_C(  70) },
      {  INT8_C(   0), -INT8_C(   1),      INT8_MAX,      INT8_MAX,      INT8_MIN,      INT8_MAX,  INT8_C(   0),      INT8_MAX } },
    { {  INT8_C( 101), -INT8_C(   5), -INT8_C(  64), -INT8_C(  53), -INT8_C(  93),  INT8_C(   2), -INT8_C(  37), -INT8_C(  22) },
      {  INT8_C(  69), -INT8_C( 101), -INT8_C(  37),  INT8_C(  84),      INT8_MIN,  INT8_C(  50),  INT8_C( 117), -INT8_C( 126) },
      {      INT8_MAX, -INT8_C(   1), -INT8_C(   1),      INT8_MIN, -INT8_C(   1),      INT8_MAX,      INT8_MIN, -INT8_C(   1) } },
    { { -INT8_C(  36), -INT8_C(  16), -INT8_C(  49), -INT8_C(  55),  INT8_C(  60),  INT8_C(  49), -INT8_C(  23), -INT8_C(  29) },
      { -INT8_C(  58),  INT8_C(  93), -INT8_C(   6), -INT8_C(   4), -INT8_C( 110), -INT8_C(  29),  INT8_C(  66), -INT8_C(   9) },
      { -INT8_C(   1),      INT8_MIN, -INT8_C(   1), -INT8_C(   4),  INT8_C(   0),  INT8_C(   0),      INT8_MIN, -INT8_C(   1) } },
    { { -INT8_C(  34),  INT8_C(   3), -INT8_C(  62), -INT8_C( 127),  INT8_C(   5), -INT8_C(  98),  INT8_C( 108),  INT8_C(  74) },
      {  INT8_C(  57),  INT8_C(  71), -INT8_C(  97), -INT8_C(  71),  INT8_C( 121),  INT8_C(  20),  INT8_C(  59),  INT8_C(  86) },
      {      INT8_MIN,      INT8_MAX, -INT8_C(   1), -INT8_C(   1),      INT8_MAX,      INT8_MIN,      INT8_MAX,      INT8_MAX } },
    { {  INT8_C(   5),  INT8_C(  10),  INT8_C(  31),  INT8_C(  65),  INT8_C(  60),  INT8_C(   8),  INT8_C(  36),  INT8_C(   2) },
      {  INT8_C( 101),  INT8_C(  31), -INT8_C(   2), -INT8_C(   9),  INT8_C(   2),  INT8_C(  65), -INT8_C(  17), -INT8_C(  32) },
      {      INT8_MAX,      INT8_MAX,  INT8_C(   7),  INT8_C(   0),      INT8_MAX,      INT8_MAX,  INT8_C(   0),  INT8_C(   0) } },
    { {  INT8_C(  68), -INT8_C(  79),  INT8_C(  98),  INT8_C(  73),  INT8_C(  79), -INT8_C(  50), -INT8_C( 109), -INT8_C( 119) },
      {  INT8_C(  21),  INT8_C(  50),  INT8_C(  66), -INT8_C( 113),  INT8_C(  71),  INT8_C( 126), -INT8_C(  27),  INT8_C(  76) },
      {      INT8_MAX,      INT8_MIN,      INT8_MAX,  INT8_C(   0),      INT8_MAX,      INT8_MIN, -INT8_C(   1),      INT8_MIN } },
    { { -INT8_C( 120),  INT8_C(   4), -INT8_C( 115), -INT8_C(  60),  INT8_C(  13), -INT8_C(  79), -INT8_C(  57),  INT8_C( 114) },
      { -INT8_C(  48), -INT8_C(  59),  INT8_C( 106), -INT8_C(  46),  INT8_C(   6),  INT8_C(  89), -INT8_C(  77),  INT8_C(  74) },
      { -INT8_C(   1),  INT8_C(   0),      INT8_MIN, -INT8_C(   1),      INT8_MAX,      INT8_MIN, -INT8_C(   1),      INT8_MAX } },
    { {  INT8_C(  10),  INT8_C(  21), -INT8_C( 109),  INT8_C(  90), -INT8_C(  29),  INT8_C(  39), -INT8_C(  29), -INT8_C(   8) },
      {  INT8_C(  89),  INT8_C(  37), -INT8_C( 121), -INT8_C(  96), -INT8_C(  93),  INT8_C( 108), -INT8_C(  20),  INT8_C(  44) },
      {      INT8_MAX,      INT8_MAX, -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),      INT8_MAX, -INT8_C(   1),      INT8_MIN } },
    { {  INT8_C( 113),  INT8_C( 121), -INT8_C(  16),  INT8_C( 126),  INT8_C(  43), -INT8_C(  73), -INT8_C(  16), -INT8_C(   5) },
      {  INT8_C( 125),  INT8_C(  90), -INT8_C(  50), -INT8_C( 125), -INT8_C(  77), -INT8_C( 127), -INT8_C(  50), -INT8_C(  66) },
      {      INT8_MAX,      INT8_MAX, -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1), -INT8_C(   1) } },
    { { -INT8_C( 106),  INT8_C(  97),  INT8_C(  24),  INT8_C( 121), -INT8_C( 120), -INT8_C(   5),  INT8_C( 113), -INT8_C(  30) },
      {  INT8_C(  32), -INT8_C(   7), -INT8_C( 126), -INT8_C(  60),  INT8_C( 101),  INT8_C( 111), -INT8_C(  16), -INT8_C(  42) },
      {      INT8_MIN,  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),      INT8_MIN,      INT8_MIN,  INT8_C(   0), -INT8_C(   1) } },
    { { -INT8_C(  24), -INT8_C(  32),  INT8_C(  84),  INT8_C(  19), -INT8_C( 104),  INT8_C(  69),  INT8_C(  15),  INT8_C(  21) },
      { -INT8_C(  97), -INT8_C(  35), -INT8_C( 104),  INT8_C(  83),  INT8_C(  94),  INT8_C( 102),  INT8_C(  17), -INT8_C(  12) },
      { -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),      INT8_MAX,      INT8_MIN,      INT8_MAX,      INT8_MAX,  INT8_C(   0) } },
    { { -INT8_C(  56),  INT8_C(  41),  INT8_C( 109),  INT8_C(  80),  INT8_C(  36), -INT8_C(  34),  INT8_C(  50),  INT8_C(  68) },
      { -INT8_C(  41), -INT8_C(  75),  INT8_C(   8),  INT8_C(  61),  INT8_C(  36), -INT8_C(   8),  INT8_C(  19),  INT8_C(  12) },
      { -INT8_C(   1),  INT8_C(   0),      INT8_MAX,      INT8_MAX,      INT8_MAX, -INT8_C(   1),      INT8_MAX,      INT8_MAX } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int8x8_t a = simde_vld1_s8(test_vec[i].a);
    simde_int8x8_t b = simde_vld1_s8(test_vec[i].b);
    simde_int8x8_t r = simde_vqshl_s8(a, b);

    simde_test_arm_neon_assert_equal_i8x8(r, simde_vld1_s8(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 16 ; i++) {
    simde_int8x8_t a = simde_test_arm_neon_random_i8x8();
    simde_int8x8_t b = simde_test_arm_neon_random_i8x8();

    a = simde_vshl_s8(a, simde_vneg_s8(simde_vand_s8(simde_test_arm_neon_random_i8x8(), simde_vdup_n_s8(7))));
    b = simde_vand_s8(b, simde_vdup_n_s8(15));

    simde_int8x8_t r = simde_vqshl_s8(a, b);

    simde_test_arm_neon_write_i8x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i8x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i8x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  for (int i = 0 ; i < 16 ; i++) {
    simde_int8x8_t a = simde_test_arm_neon_random_i8x8();
    simde_int8x8_t b = simde_test_arm_neon_random_i8x8();

    simde_int8x8_t r = simde_vqshl_s8(a, b);

    simde_test_arm_neon_write_i8x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i8x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i8x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vqshl_s16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int16_t a[4];
    int16_t b[4];
    int16_t r[4];
  } test_vec[] = {
    { {  INT16_C( 12615), -INT16_C(     4), -INT16_C(     2), -INT16_C(     1) },
      {  INT16_C(    24),  INT16_C(     0),  INT16_C(     5),  INT16_C(     6) },
      {        INT16_MAX, -INT16_C(     4), -INT16_C(    64), -INT16_C(    64) } },
    { { -INT16_C(     9),  INT16_C( 11644), -INT16_C(    64), -INT16_C( 17465) },
      {  INT16_C(    18),  INT16_C(     5),  INT16_C(     7),  INT16_C(    21) },
      {        INT16_MIN,        INT16_MAX, -INT16_C(  8192),        INT16_MIN } },
    { {  INT16_C(     0),  INT16_C(   800),  INT16_C(     5),  INT16_C(  1776) },
      {  INT16_C(    25),  INT16_C(     9),  INT16_C(    21),  INT16_C(     0) },
      {  INT16_C(     0),        INT16_MAX,        INT16_MAX,  INT16_C(  1776) } },
    { { -INT16_C(   491), -INT16_C(     1),  INT16_C( 14332),  INT16_C(  3669) },
      {  INT16_C(     4),  INT16_C(    22),  INT16_C(     1),  INT16_C(    22) },
      { -INT16_C(  7856),        INT16_MIN,  INT16_C( 28664),        INT16_MAX } },
    { {  INT16_C(     1),  INT16_C(  1323), -INT16_C(  7359), -INT16_C(    16) },
      {  INT16_C(    11),  INT16_C(     8),  INT16_C(     8),  INT16_C(    25) },
      {  INT16_C(  2048),        INT16_MAX,        INT16_MIN,        INT16_MIN } },
    { { -INT16_C(     1),  INT16_C(  3942),  INT16_C( 11116),  INT16_C( 24504) },
      {  INT16_C(    14),  INT16_C(    18),  INT16_C(    16),  INT16_C(    19) },
      { -INT16_C( 16384),        INT16_MAX,        INT16_MAX,        INT16_MAX } },
    { {  INT16_C(   168),  INT16_C(     7),  INT16_C(    20),  INT16_C(  1338) },
      {  INT16_C(     2),  INT16_C(     4),  INT16_C(    29),  INT16_C(    27) },
      {  INT16_C(   672),  INT16_C(   112),        INT16_MAX,        INT16_MAX } },
    { {  INT16_C(    54),  INT16_C(  3866),  INT16_C(     9), -INT16_C(  8283) },
      {  INT16_C(    30),  INT16_C(    28),  INT16_C(     3),  INT16_C(     6) },
      {        INT16_MAX,        INT16_MAX,  INT16_C(    72),        INT16_MIN } },
    { {  INT16_C(    29), -INT16_C(   430), -INT16_C(  1108), -INT16_C(  6766) },
      {  INT16_C(    17),  INT16_C(    18),  INT16_C(    27),  INT16_C(     3) },
      {        INT16_MAX,        INT16_MIN,        INT16_MIN,        INT16_MIN } },
    { { -INT16_C(     8), -INT16_C(    80),  INT16_C(     0), -INT16_C( 29633) },
      {  INT16_C(    27),  INT16_C(     0),  INT16_C(     2),  INT16_C(    30) },
      {        INT16_MIN, -INT16_C(    80),  INT16_C(     0),        INT16_MIN } },
    { { -INT16_C(  5674),  INT16_C(  4832), -INT16_C(  7534),  INT16_C(    12) },
      {  INT16_C(     9),  INT16_C(    28),  INT16_C(    15),  INT16_C(    23) },
      {        INT16_MIN,        INT16_MAX,        INT16_MIN,        INT16_MAX } },
    { {  INT16_C(   647),  INT16_C( 10137),  INT16_C(  2354),  INT16_C(     0) },
      {  INT16_C(    11),  INT16_C(    17),  INT16_C(    30),  INT16_C(    27) },
      {        INT16_MAX,        INT16_MAX,        INT16_MAX,  INT16_C(     0) } },
    { { -INT16_C(     1), -INT16_C(     1),  INT16_C(    56),  INT16_C(   787) },
      {  INT16_C(     1),  INT16_C(     0),  INT16_C(    21),  INT16_C(    19) },
      { -INT16_C(     2), -INT16_C(     1),        INT16_MAX,        INT16_MAX } },
    { { -INT16_C(     4), -INT16_C(  4928), -INT16_C(    40), -INT16_C(  1142) },
      {  INT16_C(    17),  INT16_C(    15),  INT16_C(    19),  INT16_C(    19) },
      {        INT16_MIN,        INT16_MIN,        INT16_MIN,        INT16_MIN } },
    { { -INT16_C(    16), -INT16_C(    46),  INT16_C(   228),  INT16_C(   388) },
      {  INT16_C(    30),  INT16_C(     0),  INT16_C(    22),  INT16_C(    26) },
      {        INT16_MIN, -INT16_C(    46),        INT16_MAX,        INT16_MAX } },
    { { -INT16_C( 10897),  INT16_C(    60), -INT16_C(    10),  INT16_C(     0) },
      {  INT16_C(    26),  INT16_C(     9),  INT16_C(    14),  INT16_C(    18) },
      {        INT16_MIN,  INT16_C( 30720),        INT16_MIN,  INT16_C(     0) } },
    { {  INT16_C( 14141),  INT16_C(  4867), -INT16_C(  2508), -INT16_C( 23705) },
      { -INT16_C( 12853),  INT16_C( 13596), -INT16_C( 13147),  INT16_C( 16218) },
      {  INT16_C(     0),        INT16_MAX, -INT16_C(     1),        INT16_MIN } },
    { {  INT16_C(  9026), -INT16_C(  3867), -INT16_C( 26865),  INT16_C(  8029) },
      { -INT16_C( 10487),  INT16_C( 25350),  INT16_C( 13387), -INT16_C( 30520) },
      {        INT16_MAX,        INT16_MIN,        INT16_MIN,  INT16_C(     0) } },
    { { -INT16_C( 13461), -INT16_C( 24676),  INT16_C(   961), -INT16_C( 29629) },
      {  INT16_C( 24528),  INT16_C( 30146),  INT16_C(  7211),  INT16_C( 28085) },
      { -INT16_C(     1), -INT16_C(     1),        INT16_MAX, -INT16_C(     1) } },
    { { -INT16_C( 26048),  INT16_C( 20318), -INT16_C( 17615),  INT16_C( 14958) },
      {  INT16_C( 29842), -INT16_C(  8803),  INT16_C( 26280),  INT16_C(  5222) },
      { -INT16_C(     1),  INT16_C(     0), -INT16_C(     1),        INT16_MAX } },
    { {  INT16_C(   561), -INT16_C(  3149), -INT16_C(  2555), -INT16_C( 10881) },
      {  INT16_C( 16725), -INT16_C( 32438), -INT16_C(   162), -INT16_C( 24850) },
      {        INT16_MAX,        INT16_MIN,        INT16_MIN, -INT16_C(     1) } },
    { {  INT16_C( 19609), -INT16_C( 13587),  INT16_C( 23304), -INT16_C( 26108) },
      { -INT16_C( 23856),  INT16_C( 30840), -INT16_C(  8696),  INT16_C( 14732) },
      {  INT16_C(     0),        INT16_MIN,        INT16_MAX, -INT16_C(     1) } },
    { {  INT16_C( 16608), -INT16_C(  6868), -INT16_C( 21450), -INT16_C( 29510) },
      {  INT16_C(  1261),  INT16_C( 19213), -INT16_C(  1276), -INT16_C( 25111) },
      {  INT16_C(     0),        INT16_MIN,        INT16_MIN, -INT16_C(     1) } },
    { { -INT16_C( 10680),  INT16_C( 20584),  INT16_C( 27698),  INT16_C(   746) },
      {  INT16_C( 25102),  INT16_C(  5754),  INT16_C(  1856),  INT16_C(  8272) },
      {        INT16_MIN,        INT16_MAX,        INT16_MAX,        INT16_MAX } },
    { {  INT16_C( 31815),  INT16_C( 32005), -INT16_C( 16600),  INT16_C(  5641) },
      {  INT16_C(  5828), -INT16_C( 14239),  INT16_C( 19218),  INT16_C( 23141) },
      {  INT16_C(     0),        INT16_MAX,        INT16_MIN,        INT16_MAX } },
    { { -INT16_C( 13023),  INT16_C( 21418), -INT16_C( 27590),  INT16_C( 18517) },
      { -INT16_C( 12041),  INT16_C( 14175), -INT16_C( 20521),  INT16_C(  7768) },
      { -INT16_C(    26),        INT16_MAX, -INT16_C(     1),        INT16_MAX } },
    { {  INT16_C( 23851),  INT16_C( 21659), -INT16_C( 23267), -INT16_C(  7830) },
      { -INT16_C( 13381), -INT16_C( 12887),  INT16_C(  3606),  INT16_C( 14375) },
      {  INT16_C(     0),  INT16_C(     0),        INT16_MIN,        INT16_MIN } },
    { { -INT16_C( 11812),  INT16_C(  5771), -INT16_C(  7834),  INT16_C( 23902) },
      { -INT16_C( 16975), -INT16_C( 30572), -INT16_C(  5012), -INT16_C( 26458) },
      { -INT16_C(     1),  INT16_C(     0),        INT16_MIN,  INT16_C(     0) } },
    { {  INT16_C( 16714),  INT16_C( 26604),  INT16_C( 22246), -INT16_C( 23992) },
      { -INT16_C(  3807),  INT16_C( 14447), -INT16_C( 26625), -INT16_C(  9360) },
      {        INT16_MAX,        INT16_MAX,  INT16_C( 11123),        INT16_MIN } },
    { { -INT16_C(  1176), -INT16_C( 12559),  INT16_C( 20700), -INT16_C( 29397) },
      { -INT16_C( 16371),  INT16_C( 31253), -INT16_C( 17492), -INT16_C(  2542) },
      {        INT16_MIN,        INT16_MIN,  INT16_C(     0),        INT16_MIN } },
    { { -INT16_C(   259), -INT16_C(  7331), -INT16_C( 23212),  INT16_C( 30085) },
      { -INT16_C(  2666), -INT16_C( 26963),  INT16_C(  7564), -INT16_C(  2959) },
      { -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),        INT16_MAX } },
    { {  INT16_C( 25369), -INT16_C(  2621), -INT16_C(  4429), -INT16_C( 16253) },
      { -INT16_C( 26450),  INT16_C( 23354),  INT16_C( 19540),  INT16_C( 20817) },
      {  INT16_C(     0),        INT16_MIN,        INT16_MIN,        INT16_MIN } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x4_t a = simde_vld1_s16(test_vec[i].a);
    simde_int16x4_t b = simde_vld1_s16(test_vec[i].b);
    simde_int16x4_t r = simde_vqshl_s16(a, b);

    simde_test_arm_neon_assert_equal_i16x4(r, simde_vld1_s16(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 16 ; i++) {
    simde_int16x4_t a = simde_test_arm_neon_random_i16x4();
    simde_int16x4_t b = simde_test_arm_neon_random_i16x4();

    a = simde_vshl_s16(a, simde_vneg_s16(simde_vand_s16(simde_test_arm_neon_random_i16x4(), simde_vdup_n_s16(15))));
    b = simde_vand_s16(b, simde_vdup_n_s16(31));

    simde_int16x4_t r = simde_vqshl_s16(a, b);

    simde_test_arm_neon_write_i16x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i16x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i16x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  for (int i = 0 ; i < 16 ; i++) {
    simde_int16x4_t a = simde_test_arm_neon_random_i16x4();
    simde_int16x4_t b = simde_test_arm_neon_random_i16x4();

    simde_int16x4_t r = simde_vqshl_s16(a, b);

    simde_test_arm_neon_write_i16x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i16x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i16x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vqshl_s32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int32_t a[2];
    int32_t b[2];
    int32_t r[2];
  } test_vec[] = {
    { {  INT32_C(    10301969), -INT32_C(           7) },
      {  INT32_C(          17),  INT32_C(          61) },
      {              INT32_MAX,              INT32_MIN } },
    { {  INT32_C(   128576247), -INT32_C(      614336) },
      {  INT32_C(          12),  INT32_C(          11) },
      {              INT32_MAX, -INT32_C(  1258160128) } },
    { { -INT32_C(   293177025), -INT32_C(          64) },
      {  INT32_C(          57),  INT32_C(           2) },
      {              INT32_MIN, -INT32_C(         256) } },
    { { -INT32_C(        7275), -INT32_C(         128) },
      {  INT32_C(          29),  INT32_C(          60) },
      {              INT32_MIN,              INT32_MIN } },
    { {  INT32_C(        2352), -INT32_C(   413075398) },
      {  INT32_C(          50),  INT32_C(          15) },
      {              INT32_MAX,              INT32_MIN } },
    { { -INT32_C(           4),  INT32_C(  1043079748) },
      {  INT32_C(          39),  INT32_C(          16) },
      {              INT32_MIN,              INT32_MAX } },
    { { -INT32_C(    72844965), -INT32_C(     1697964) },
      {  INT32_C(          56),  INT32_C(          22) },
      {              INT32_MIN,              INT32_MIN } },
    { {  INT32_C(        8297),  INT32_C(        3722) },
      {  INT32_C(          53),  INT32_C(           0) },
      {              INT32_MAX,  INT32_C(        3722) } },
    { {  INT32_C(        4260),  INT32_C(     1095023) },
      {  INT32_C(          11),  INT32_C(          39) },
      {  INT32_C(     8724480),              INT32_MAX } },
    { {  INT32_C(           0),  INT32_C(           1) },
      {  INT32_C(           3),  INT32_C(          61) },
      {  INT32_C(           0),              INT32_MAX } },
    { {  INT32_C(       49870), -INT32_C(    18310395) },
      {  INT32_C(          33),  INT32_C(          58) },
      {              INT32_MAX,              INT32_MIN } },
    { {  INT32_C(        1385), -INT32_C(           1) },
      {  INT32_C(           4),  INT32_C(          48) },
      {  INT32_C(       22160),              INT32_MIN } },
    { {  INT32_C(       12555),  INT32_C(      268900) },
      {  INT32_C(          41),  INT32_C(          28) },
      {              INT32_MAX,              INT32_MAX } },
    { { -INT32_C(      315989), -INT32_C(    56742724) },
      {  INT32_C(           3),  INT32_C(          37) },
      { -INT32_C(     2527912),              INT32_MIN } },
    { { -INT32_C(    86043607),  INT32_C(    21146968) },
      {  INT32_C(          10),  INT32_C(          26) },
      {              INT32_MIN,              INT32_MAX } },
    { { -INT32_C(      722637),  INT32_C(   982237936) },
      {  INT32_C(          35),  INT32_C(          47) },
      {              INT32_MIN,              INT32_MAX } },
    { { -INT32_C(    20147399),  INT32_C(   776987423) },
      {  INT32_C(   102909974),  INT32_C(  1832955402) },
      {              INT32_MIN,              INT32_MAX } },
    { {  INT32_C(  1641893938), -INT32_C(   577014347) },
      {  INT32_C(  1868526863), -INT32_C(  1116504188) },
      {              INT32_MAX, -INT32_C(           1) } },
    { {  INT32_C(   834420498),  INT32_C(   945752866) },
      {  INT32_C(  1581154900),  INT32_C(  1657568816) },
      {              INT32_MAX,              INT32_MAX } },
    { { -INT32_C(  2084329010),  INT32_C(   778133023) },
      {  INT32_C(  1486733524),  INT32_C(  1377177663) },
      { -INT32_C(           1),              INT32_MAX } },
    { {  INT32_C(  1904464463),  INT32_C(   833217501) },
      { -INT32_C(  1785665691),  INT32_C(   871849061) },
      {              INT32_MAX,              INT32_MAX } },
    { {  INT32_C(   616020485), -INT32_C(   313386983) },
      {  INT32_C(   407236824),  INT32_C(  1349147392) },
      {  INT32_C(           0), -INT32_C(   313386983) } },
    { {  INT32_C(   197258541),  INT32_C(   893152208) },
      { -INT32_C(  1194668974),  INT32_C(   787202344) },
      {              INT32_MAX,              INT32_MAX } },
    { { -INT32_C(  1789746564), -INT32_C(  1820154438) },
      { -INT32_C(  1783904363),  INT32_C(  1357190435) },
      { -INT32_C(           1),              INT32_MIN } },
    { { -INT32_C(   748968190),  INT32_C(  1678284818) },
      { -INT32_C(  1927490716),  INT32_C(   280692884) },
      {              INT32_MIN,  INT32_C(           0) } },
    { {  INT32_C(  1705315754),  INT32_C(  1207445426) },
      {  INT32_C(   316515311), -INT32_C(  1167932744) },
      {  INT32_C(       13010),  INT32_C(           0) } },
    { {  INT32_C(  2072886889), -INT32_C(  1159686570) },
      { -INT32_C(    45613975), -INT32_C(  1358036476) },
      {              INT32_MAX,              INT32_MIN } },
    { { -INT32_C(  1038830832), -INT32_C(   905311013) },
      {  INT32_C(  1742530479),  INT32_C(   320945833) },
      { -INT32_C(           1), -INT32_C(           1) } },
    { {  INT32_C(  1385082876), -INT32_C(  1374851515) },
      {  INT32_C(  1873499243),  INT32_C(  1730066775) },
      {              INT32_MAX,              INT32_MIN } },
    { {  INT32_C(  1210659437), -INT32_C(   317574338) },
      { -INT32_C(  1001066982),  INT32_C(   701986348) },
      {              INT32_MAX,              INT32_MIN } },
    { {  INT32_C(  1786471717),  INT32_C(  1058572500) },
      {  INT32_C(   883868637), -INT32_C(   358888067) },
      {  INT32_C(           0),              INT32_MAX } },
    { {  INT32_C(  1043514623),  INT32_C(   304825592) },
      {  INT32_C(  1591115826),  INT32_C(   461876726) },
      {              INT32_MAX,  INT32_C(      297681) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x2_t a = simde_vld1_s32(test_vec[i].a);
    simde_int32x2_t b = simde_vld1_s32(test_vec[i].b);
    simde_int32x2_t r = simde_vqshl_s32(a, b);

    simde_test_arm_neon_assert_equal_i32x2(r, simde_vld1_s32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 16 ; i++) {
    simde_int32x2_t a = simde_test_arm_neon_random_i32x2();
    simde_int32x2_t b = simde_test_arm_neon_random_i32x2();

    a = simde_vshl_s32(a, simde_vneg_s32(simde_vand_s32(simde_test_arm_neon_random_i32x2(), simde_vdup_n_s32(31))));
    b = simde_vand_s32(b, simde_vdup_n_s32(63));

    simde_int32x2_t r = simde_vqshl_s32(a, b);

    simde_test_arm_neon_write_i32x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i32x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i32x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  for (int i = 0 ; i < 16 ; i++) {
    simde_int32x2_t a = simde_test_arm_neon_random_i32x2();
    simde_int32x2_t b = simde_test_arm_neon_random_i32x2();

    simde_int32x2_t r = simde_vqshl_s32(a, b);

    simde_test_arm_neon_write_i32x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i32x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i32x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vqshl_s64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int64_t a[1];
    int64_t b[1];
    int64_t r[1];
  } test_vec[] = {
    { { -INT64_C(                6076) },
      {  INT64_C(                  38) },
      { -INT64_C(    1670158162591744) } },
    { {  INT64_C(     111268011261729) },
      {  INT64_C(                  34) },
      {                      INT64_MAX } },
    { { -INT64_C(              987120) },
      {  INT64_C(                  41) },
      { -INT64_C( 2170699836020490240) } },
    { { -INT64_C(              348814) },
      {  INT64_C(                  37) },
      { -INT64_C(   47940631116382208) } },
    { {  INT64_C(   66121719747893008) },
      {  INT64_C(                  10) },
      {                      INT64_MAX } },
    { { -INT64_C(             2826671) },
      {  INT64_C(                  43) },
      {                      INT64_MIN } },
    { {  INT64_C(            13736439) },
      {  INT64_C(                  35) },
      {  INT64_C(  471980450147991552) } },
    { {  INT64_C(              512775) },
      {  INT64_C(                   3) },
      {  INT64_C(             4102200) } },
    { {  INT64_C( 1563165490977805508) },
      {  INT64_C(                  63) },
      {                      INT64_MAX } },
    { {  INT64_C(                   1) },
      {  INT64_C(                  31) },
      {  INT64_C(          2147483648) } },
    { { -INT64_C(   30513113372710963) },
      {  INT64_C(                  59) },
      {                      INT64_MIN } },
    { {  INT64_C(               47309) },
      {  INT64_C(                  32) },
      {  INT64_C(     203190607806464) } },
    { { -INT64_C(               13846) },
      {  INT64_C(                  37) },
      { -INT64_C(    1902979749773312) } },
    { { -INT64_C(          1797564691) },
      {  INT64_C(                  43) },
      {                      INT64_MIN } },
    { { -INT64_C(                  72) },
      {  INT64_C(                  41) },
      { -INT64_C(     158329674399744) } },
    { {  INT64_C(          5095842997) },
      {  INT64_C(                  54) },
      {                      INT64_MAX } },
    { {  INT64_C( 3962614928916152391) },
      {  INT64_C( 6650018016084692433) },
      {  INT64_C(               28156) } },
    { { -INT64_C( 5547802155389235843) },
      { -INT64_C( 8248728344309374983) },
      { -INT64_C(   43342204338978406) } },
    { {  INT64_C( 1594554939537963938) },
      { -INT64_C( 1833142717411701492) },
      {                      INT64_MAX } },
    { { -INT64_C( 6326373652469027029) },
      {  INT64_C( 3919947608821133971) },
      { -INT64_C(                   1) } },
    { {  INT64_C( 8217169806024009646) },
      { -INT64_C( 6386890991665341171) },
      {                      INT64_MAX } },
    { {  INT64_C( 6195083652568157859) },
      {  INT64_C(  511322770985903694) },
      {                      INT64_MAX } },
    { { -INT64_C( 8803126081017464580) },
      {  INT64_C( 5855621447493057057) },
      {                      INT64_MIN } },
    { {  INT64_C( 1513100376883293159) },
      { -INT64_C( 4619832562675208830) },
      {  INT64_C(                   0) } },
    { {  INT64_C(  163246560445128006) },
      {  INT64_C( 9111594134839115634) },
      {                      INT64_MAX } },
    { {  INT64_C( 3758297530524767565) },
      {  INT64_C( 8347125234852109908) },
      {                      INT64_MAX } },
    { {  INT64_C( 7040100314840758480) },
      { -INT64_C( 9166245590395104844) },
      {  INT64_C(                   0) } },
    { {  INT64_C( 7993533207319736841) },
      { -INT64_C( 4576963509815476518) },
      {  INT64_C(            29080304) } },
    { { -INT64_C( 2908159729812263597) },
      {  INT64_C( 2534098439111911030) },
      {                      INT64_MIN } },
    { {  INT64_C( 6082054650337279712) },
      { -INT64_C( 7315016466663936822) },
      {  INT64_C(                 337) } },
    { { -INT64_C( 8683642593686459260) },
      {  INT64_C( 7990611208035147943) },
      { -INT64_C(                   1) } },
    { {  INT64_C( 6334259607873503512) },
      { -INT64_C( 7017297501513169989) },
      {  INT64_C(                   0) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int64x1_t a = simde_vld1_s64(test_vec[i].a);
    simde_int64x1_t b = simde_vld1_s64(test_vec[i].b);
    simde_int64x1_t r = simde_vqshl_s64(a, b);

    simde_test_arm_neon_assert_equal_i64x1(r, simde_vld1_s64(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 16 ; i++) {
    simde_int64x1_t a = simde_test_arm_neon_random_i64x1();
    simde_int64x1_t b = simde_test_arm_neon_random_i64x1();

    a = simde_vshl_s64(a, simde_vneg_s64(simde_vand_s64(simde_test_arm_neon_random_i64x1(), simde_vdup_n_s64(63))));
    b = simde_vand_s64(b, simde_vdup_n_s64(63));

    simde_int64x1_t r = simde_vqshl_s64(a, b);

    simde_test_arm_neon_write_i64x1(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i64x1(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i64x1(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  for (int i = 0 ; i < 16 ; i++) {
    simde_int64x1_t a = simde_test_arm_neon_random_i64x1();
    simde_int64x1_t b = simde_test_arm_neon_random_i64x1();

    simde_int64x1_t r = simde_vqshl_s64(a, b);

    simde_test_arm_neon_write_i64x1(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i64x1(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i64x1(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vqshl_u8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint8_t a[8];
    int8_t b[8];
    uint8_t r[8];
  } test_vec[] = {
    { { UINT8_C(129), UINT8_C(  0), UINT8_C(  4), UINT8_C(  1), UINT8_C(  6), UINT8_C(  3), UINT8_C(228), UINT8_C(  1) },
      {  INT8_C(   0),  INT8_C(  15),  INT8_C(   5),  INT8_C(   2),  INT8_C(   2),  INT8_C(  14),  INT8_C(  13),  INT8_C(  12) },
      { UINT8_C(129), UINT8_C(  0), UINT8_C(128), UINT8_C(  4), UINT8_C( 24),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX } },
    { { UINT8_C(195), UINT8_C( 62), UINT8_C(  4), UINT8_C( 13), UINT8_C(  3), UINT8_C( 58), UINT8_C(  1), UINT8_C(  1) },
      {  INT8_C(   6),  INT8_C(   4),  INT8_C(  13),  INT8_C(  10),  INT8_C(  10),  INT8_C(   1),  INT8_C(   3),  INT8_C(  11) },
      {    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(116), UINT8_C(  8),    UINT8_MAX } },
    { { UINT8_C(  2), UINT8_C(  3), UINT8_C(  8), UINT8_C(  1), UINT8_C(  0), UINT8_C(  6), UINT8_C( 17), UINT8_C(230) },
      {  INT8_C(   9),  INT8_C(   1),  INT8_C(  15),  INT8_C(   5),  INT8_C(   9),  INT8_C(   1),  INT8_C(   1),  INT8_C(  15) },
      {    UINT8_MAX, UINT8_C(  6),    UINT8_MAX, UINT8_C( 32), UINT8_C(  0), UINT8_C( 12), UINT8_C( 34),    UINT8_MAX } },
    { { UINT8_C( 45), UINT8_C(183), UINT8_C(  1), UINT8_C(  4), UINT8_C( 89), UINT8_C(  1), UINT8_C( 30), UINT8_C(  0) },
      {  INT8_C(  15),  INT8_C(   4),  INT8_C(   2),  INT8_C(   2),  INT8_C(  15),  INT8_C(   9),  INT8_C(   8),  INT8_C(   9) },
      {    UINT8_MAX,    UINT8_MAX, UINT8_C(  4), UINT8_C( 16),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0) } },
    { { UINT8_C(103), UINT8_C(  0), UINT8_C(  7), UINT8_C( 46), UINT8_C( 42), UINT8_C(  0), UINT8_C( 31), UINT8_C( 27) },
      {  INT8_C(  15),  INT8_C(   0),  INT8_C(  11),  INT8_C(   1),  INT8_C(   3),  INT8_C(  13),  INT8_C(  13),  INT8_C(   2) },
      {    UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C( 92),    UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(108) } },
    { { UINT8_C(  2), UINT8_C(  2), UINT8_C( 24), UINT8_C(  1), UINT8_C( 61), UINT8_C(170), UINT8_C(  2), UINT8_C( 24) },
      {  INT8_C(   8),  INT8_C(  10),  INT8_C(   3),  INT8_C(   2),  INT8_C(   2),  INT8_C(   0),  INT8_C(   2),  INT8_C(   1) },
      {    UINT8_MAX,    UINT8_MAX, UINT8_C(192), UINT8_C(  4), UINT8_C(244), UINT8_C(170), UINT8_C(  8), UINT8_C( 48) } },
    { { UINT8_C(  3), UINT8_C(  3), UINT8_C(  0), UINT8_C(  7), UINT8_C(  1), UINT8_C( 75), UINT8_C(  1), UINT8_C(254) },
      {  INT8_C(  14),  INT8_C(   2),  INT8_C(  13),  INT8_C(   6),  INT8_C(  12),  INT8_C(   9),  INT8_C(  11),  INT8_C(   4) },
      {    UINT8_MAX, UINT8_C( 12), UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX } },
    { { UINT8_C(  3), UINT8_C( 34), UINT8_C(  4), UINT8_C(  0), UINT8_C(  1), UINT8_C(  3), UINT8_C(  0), UINT8_C(  0) },
      {  INT8_C(   6),  INT8_C(   8),  INT8_C(   1),  INT8_C(  15),  INT8_C(  14),  INT8_C(  12),  INT8_C(  13),  INT8_C(  13) },
      { UINT8_C(192),    UINT8_MAX, UINT8_C(  8), UINT8_C(  0),    UINT8_MAX,    UINT8_MAX, UINT8_C(  0), UINT8_C(  0) } },
    { { UINT8_C( 46), UINT8_C( 12), UINT8_C(  1), UINT8_C(  1), UINT8_C(  0), UINT8_C(  4), UINT8_C(  9), UINT8_C(  0) },
      {  INT8_C(  14),  INT8_C(   0),  INT8_C(   5),  INT8_C(   8),  INT8_C(  10),  INT8_C(   1),  INT8_C(   1),  INT8_C(   0) },
      {    UINT8_MAX, UINT8_C( 12), UINT8_C( 32),    UINT8_MAX, UINT8_C(  0), UINT8_C(  8), UINT8_C( 18), UINT8_C(  0) } },
    { { UINT8_C( 30), UINT8_C( 91), UINT8_C( 42), UINT8_C(  4), UINT8_C( 21), UINT8_C( 31), UINT8_C(  2), UINT8_C( 22) },
      {  INT8_C(  15),  INT8_C(   0),  INT8_C(  15),  INT8_C(  14),  INT8_C(   4),  INT8_C(  11),  INT8_C(   4),  INT8_C(   2) },
      {    UINT8_MAX, UINT8_C( 91),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C( 32), UINT8_C( 88) } },
    { { UINT8_C( 62), UINT8_C(  0), UINT8_C( 11), UINT8_C( 14), UINT8_C(  8), UINT8_C(  0), UINT8_C(  1), UINT8_C(  0) },
      {  INT8_C(   7),  INT8_C(   5),  INT8_C(   5),  INT8_C(  13),  INT8_C(  13),  INT8_C(   8),  INT8_C(   0),  INT8_C(  12) },
      {    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0), UINT8_C(  1), UINT8_C(  0) } },
    { { UINT8_C( 12), UINT8_C( 88), UINT8_C(  3), UINT8_C(  1), UINT8_C(  4), UINT8_C(  2), UINT8_C( 16), UINT8_C( 33) },
      {  INT8_C(   6),  INT8_C(   1),  INT8_C(   0),  INT8_C(   8),  INT8_C(   1),  INT8_C(  12),  INT8_C(   2),  INT8_C(   8) },
      {    UINT8_MAX, UINT8_C(176), UINT8_C(  3),    UINT8_MAX, UINT8_C(  8),    UINT8_MAX, UINT8_C( 64),    UINT8_MAX } },
    { { UINT8_C(114), UINT8_C(  8), UINT8_C(  6), UINT8_C( 11), UINT8_C( 69), UINT8_C(  0), UINT8_C( 16), UINT8_C( 47) },
      {  INT8_C(  12),  INT8_C(  13),  INT8_C(   1),  INT8_C(   0),  INT8_C(  14),  INT8_C(   7),  INT8_C(   3),  INT8_C(   4) },
      {    UINT8_MAX,    UINT8_MAX, UINT8_C( 12), UINT8_C( 11),    UINT8_MAX, UINT8_C(  0), UINT8_C(128),    UINT8_MAX } },
    { { UINT8_C(  3), UINT8_C(  1), UINT8_C(  0), UINT8_C(  9), UINT8_C(  2), UINT8_C( 31), UINT8_C( 16), UINT8_C(  1) },
      {  INT8_C(   2),  INT8_C(   6),  INT8_C(  14),  INT8_C(   8),  INT8_C(  10),  INT8_C(   1),  INT8_C(   6),  INT8_C(   6) },
      { UINT8_C( 12), UINT8_C( 64), UINT8_C(  0),    UINT8_MAX,    UINT8_MAX, UINT8_C( 62),    UINT8_MAX, UINT8_C( 64) } },
    { { UINT8_C(110), UINT8_C(  2), UINT8_C(  3), UINT8_C( 23), UINT8_C(  6), UINT8_C(  1), UINT8_C( 39), UINT8_C( 12) },
      {  INT8_C(  10),  INT8_C(  15),  INT8_C(  10),  INT8_C(   6),  INT8_C(  11),  INT8_C(  11),  INT8_C(   6),  INT8_C(  14) },
      {    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX } },
    { { UINT8_C( 12), UINT8_C(  0), UINT8_C(  0), UINT8_C(  1), UINT8_C( 40), UINT8_C(  3), UINT8_C(  2), UINT8_C( 16) },
      {  INT8_C(  14),  INT8_C(  10),  INT8_C(  13),  INT8_C(  10),  INT8_C(  14),  INT8_C(  12),  INT8_C(  13),  INT8_C(   8) },
      {    UINT8_MAX, UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX } },
    { { UINT8_C( 10), UINT8_C( 11), UINT8_C(142), UINT8_C(207), UINT8_C( 87), UINT8_C( 16), UINT8_C( 67), UINT8_C( 26) },
      {  INT8_C(  24),  INT8_C( 116), -INT8_C(  20), -INT8_C(  69), -INT8_C(  43),  INT8_C(  69),  INT8_C(  59),  INT8_C(  99) },
      {    UINT8_MAX,    UINT8_MAX, UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX } },
    { { UINT8_C(143), UINT8_C(120), UINT8_C(189), UINT8_C(237), UINT8_C(  5), UINT8_C(218), UINT8_C( 86), UINT8_C( 49) },
      {  INT8_C(  81),  INT8_C( 101),  INT8_C( 120),  INT8_C(  52), -INT8_C( 102), -INT8_C(  98), -INT8_C(   9), -INT8_C(  92) },
      {    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0) } },
    { { UINT8_C(169), UINT8_C(134), UINT8_C(116), UINT8_C(  1), UINT8_C(150), UINT8_C(183), UINT8_C( 27), UINT8_C(174) },
      {  INT8_C(  43),  INT8_C(   7),  INT8_C( 105),  INT8_C(   0),  INT8_C(  76), -INT8_C(  92),  INT8_C(  99), -INT8_C(  36) },
      {    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  1),    UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  0) } },
    { { UINT8_C( 29), UINT8_C( 32), UINT8_C(201), UINT8_C( 34), UINT8_C(250), UINT8_C( 31), UINT8_C( 83), UINT8_C( 76) },
      { -INT8_C( 124), -INT8_C(  53),      INT8_MIN,  INT8_C(  31),  INT8_C( 105),  INT8_C( 119), -INT8_C(  61),  INT8_C(  19) },
      { UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX } },
    { { UINT8_C(253), UINT8_C( 55), UINT8_C( 20), UINT8_C(147), UINT8_C(239), UINT8_C( 47), UINT8_C( 66), UINT8_C( 26) },
      {  INT8_C(  55), -INT8_C(  85),  INT8_C(  27), -INT8_C( 125),  INT8_C(  80),  INT8_C( 126),  INT8_C(  95),  INT8_C( 109) },
      {    UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX } },
    { { UINT8_C(159), UINT8_C( 41), UINT8_C(143), UINT8_C(153), UINT8_C( 72), UINT8_C(226), UINT8_C(229), UINT8_C(205) },
      { -INT8_C(  83),  INT8_C( 101), -INT8_C(  20),  INT8_C(  23), -INT8_C(  35), -INT8_C(  81),  INT8_C(  42), -INT8_C(  38) },
      { UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  0),    UINT8_MAX, UINT8_C(  0) } },
    { { UINT8_C(231), UINT8_C( 62), UINT8_C(110), UINT8_C(214), UINT8_C(109), UINT8_C(176), UINT8_C(240), UINT8_C(164) },
      {  INT8_C(  91),  INT8_C(  11),  INT8_C(  40), -INT8_C(  85), -INT8_C( 118), -INT8_C( 121),  INT8_C(  24),  INT8_C(  41) },
      {    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,    UINT8_MAX } },
    { { UINT8_C(176), UINT8_C(167), UINT8_C(194), UINT8_C(249), UINT8_C(137), UINT8_C(168), UINT8_C(198), UINT8_C( 55) },
      {  INT8_C(  13), -INT8_C(  78),  INT8_C(  78), -INT8_C(  22),  INT8_C(  97),  INT8_C( 120), -INT8_C(  59),  INT8_C(  72) },
      {    UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX } },
    { { UINT8_C(182), UINT8_C( 51), UINT8_C( 30), UINT8_C( 35), UINT8_C(227), UINT8_C( 15), UINT8_C(200), UINT8_C( 62) },
      {  INT8_C(  26), -INT8_C(  16), -INT8_C(  22), -INT8_C(  92),  INT8_C( 119),  INT8_C(   2), -INT8_C(  51),  INT8_C(  40) },
      {    UINT8_MAX, UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),    UINT8_MAX, UINT8_C( 60), UINT8_C(  0),    UINT8_MAX } },
    { { UINT8_C(170), UINT8_C(144), UINT8_C( 33), UINT8_C( 51), UINT8_C( 56), UINT8_C(231), UINT8_C(106), UINT8_C( 69) },
      { -INT8_C( 103), -INT8_C(  72),  INT8_C(  48), -INT8_C(   6),  INT8_C(  48), -INT8_C(  11),  INT8_C(  67), -INT8_C(  26) },
      { UINT8_C(  0), UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  0) } },
    { { UINT8_C( 40), UINT8_C( 97), UINT8_C( 10), UINT8_C( 11), UINT8_C(112), UINT8_C(210), UINT8_C( 73), UINT8_C(139) },
      { -INT8_C(  62),  INT8_C(  51),  INT8_C(  47),  INT8_C(  57),  INT8_C(  54), -INT8_C(   3),  INT8_C(  97), -INT8_C(  32) },
      { UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C( 26),    UINT8_MAX, UINT8_C(  0) } },
    { { UINT8_C(141), UINT8_C(130), UINT8_C( 19), UINT8_C(197), UINT8_C(105), UINT8_C(126), UINT8_C( 10), UINT8_C(  2) },
      {  INT8_C(  54),  INT8_C(  58), -INT8_C(   3),  INT8_C( 103),  INT8_C(  47),  INT8_C(  64),  INT8_C(  77),  INT8_C(  87) },
      {    UINT8_MAX,    UINT8_MAX, UINT8_C(  2),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX } },
    { { UINT8_C(161), UINT8_C( 87), UINT8_C( 98), UINT8_C( 18), UINT8_C( 41), UINT8_C(172), UINT8_C(157), UINT8_C(235) },
      { -INT8_C(  33), -INT8_C(  52),  INT8_C(  37),  INT8_C(  21), -INT8_C(  55), -INT8_C( 122), -INT8_C(  11),  INT8_C(  86) },
      { UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,    UINT8_MAX, UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),    UINT8_MAX } },
    { { UINT8_C(  9), UINT8_C(  9), UINT8_C( 27), UINT8_C(114), UINT8_C(135), UINT8_C( 38), UINT8_C(117), UINT8_C(189) },
      {  INT8_C(  96),  INT8_C( 114),  INT8_C(  36), -INT8_C( 112), -INT8_C(  78),  INT8_C( 114), -INT8_C(  25),  INT8_C(  83) },
      {    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0), UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),    UINT8_MAX } },
    { { UINT8_C(201), UINT8_C( 74), UINT8_C(101), UINT8_C(243), UINT8_C(246), UINT8_C(  2), UINT8_C(222), UINT8_C(213) },
      { -INT8_C(  49),  INT8_C(   3), -INT8_C(  21), -INT8_C( 104), -INT8_C( 118), -INT8_C(  32), -INT8_C(  17), -INT8_C( 109) },
      { UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0) } },
    { { UINT8_C(233), UINT8_C( 10), UINT8_C(  5), UINT8_C(112), UINT8_C( 48), UINT8_C(122), UINT8_C( 46), UINT8_C(145) },
      { -INT8_C(  20),  INT8_C(  82),  INT8_C(  33), -INT8_C(  98), -INT8_C(  60),  INT8_C(   8), -INT8_C(  14), -INT8_C( 114) },
      { UINT8_C(  0),    UINT8_MAX,    UINT8_MAX, UINT8_C(  0), UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  0) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint8x8_t a = simde_vld1_u8(test_vec[i].a);
    simde_int8x8_t b = simde_vld1_s8(test_vec[i].b);
    simde_uint8x8_t r = simde_vqshl_u8(a, b);

    simde_test_arm_neon_assert_equal_u8x8(r, simde_vld1_u8(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 16 ; i++) {
    simde_uint8x8_t a = simde_test_arm_neon_random_u8x8();
    simde_int8x8_t b = simde_test_arm_neon_random_i8x8();

    a = simde_vshl_u8(a, simde_vneg_s8(simde_vand_s8(simde_test_arm_neon_random_i8x8(), simde_vdup_n_s8(7))));
    b = simde_vand_s8(b, simde_vdup_n_s8(15));

    simde_uint8x8_t r = simde_vqshl_u8(a, b);

    simde_test_arm_neon_write_u8x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i8x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u8x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  for (int i = 0 ; i < 16 ; i++) {
    simde_uint8x8_t a = simde_test_arm_neon_random_u8x8();
    simde_int8x8_t b = simde_test_arm_neon_random_i8x8();

    simde_uint8x8_t r = simde_vqshl_u8(a, b);

    simde_test_arm_neon_write_u8x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i8x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u8x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vqshl_u16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint16_t a[4];
    int16_t b[4];
    uint16_t r[4];
  } test_vec[] = {
    { { UINT16_C(    4), UINT16_C(   54), UINT16_C( 1107), UINT16_C( 1821) },
      {  INT16_C(     4),  INT16_C(    28),  INT16_C(    15),  INT16_C(     6) },
      { UINT16_C(   64),      UINT16_MAX,      UINT16_MAX,      UINT16_MAX } },
    { { UINT16_C( 3349), UINT16_C(  109), UINT16_C(   63), UINT16_C(13202) },
      {  INT16_C(     0),  INT16_C(     1),  INT16_C(    27),  INT16_C(    16) },
      { UINT16_C( 3349), UINT16_C(  218),      UINT16_MAX,      UINT16_MAX } },
    { { UINT16_C(   51), UINT16_C(    4), UINT16_C(   14), UINT16_C( 1553) },
      {  INT16_C(     1),  INT16_C(     6),  INT16_C(    18),  INT16_C(    11) },
      { UINT16_C(  102), UINT16_C(  256),      UINT16_MAX,      UINT16_MAX } },
    { { UINT16_C( 1196), UINT16_C(61456), UINT16_C(   16), UINT16_C(  121) },
      {  INT16_C(    23),  INT16_C(     5),  INT16_C(     7),  INT16_C(     9) },
      {      UINT16_MAX,      UINT16_MAX, UINT16_C( 2048), UINT16_C(61952) } },
    { { UINT16_C(   20), UINT16_C(12789), UINT16_C(  781), UINT16_C(   25) },
      {  INT16_C(     2),  INT16_C(     3),  INT16_C(    31),  INT16_C(    13) },
      { UINT16_C(   80),      UINT16_MAX,      UINT16_MAX,      UINT16_MAX } },
    { { UINT16_C(   54), UINT16_C(    1), UINT16_C(   67), UINT16_C(31491) },
      {  INT16_C(    26),  INT16_C(    12),  INT16_C(    17),  INT16_C(    26) },
      {      UINT16_MAX, UINT16_C( 4096),      UINT16_MAX,      UINT16_MAX } },
    { { UINT16_C(28758), UINT16_C(    1), UINT16_C(    0), UINT16_C(  327) },
      {  INT16_C(     7),  INT16_C(    21),  INT16_C(    29),  INT16_C(     7) },
      {      UINT16_MAX,      UINT16_MAX, UINT16_C(    0), UINT16_C(41856) } },
    { { UINT16_C(   57), UINT16_C(   79), UINT16_C(    2), UINT16_C(    0) },
      {  INT16_C(     2),  INT16_C(    28),  INT16_C(    21),  INT16_C(    31) },
      { UINT16_C(  228),      UINT16_MAX,      UINT16_MAX, UINT16_C(    0) } },
    { { UINT16_C( 5937), UINT16_C(    1), UINT16_C(   88), UINT16_C( 1707) },
      {  INT16_C(    28),  INT16_C(    25),  INT16_C(    17),  INT16_C(     7) },
      {      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX } },
    { { UINT16_C(    2), UINT16_C(    1), UINT16_C(   41), UINT16_C( 6179) },
      {  INT16_C(     5),  INT16_C(     3),  INT16_C(     6),  INT16_C(     4) },
      { UINT16_C(   64), UINT16_C(    8), UINT16_C( 2624),      UINT16_MAX } },
    { { UINT16_C(    6), UINT16_C(    2), UINT16_C( 5326), UINT16_C( 1179) },
      {  INT16_C(    19),  INT16_C(     2),  INT16_C(    24),  INT16_C(    16) },
      {      UINT16_MAX, UINT16_C(    8),      UINT16_MAX,      UINT16_MAX } },
    { { UINT16_C(    1), UINT16_C(  193), UINT16_C(   73), UINT16_C(    1) },
      {  INT16_C(    20),  INT16_C(    20),  INT16_C(     5),  INT16_C(    24) },
      {      UINT16_MAX,      UINT16_MAX, UINT16_C( 2336),      UINT16_MAX } },
    { { UINT16_C(   91), UINT16_C(   19), UINT16_C(    5), UINT16_C(  217) },
      {  INT16_C(    18),  INT16_C(    14),  INT16_C(    18),  INT16_C(    13) },
      {      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX } },
    { { UINT16_C(12061), UINT16_C(  883), UINT16_C( 1832), UINT16_C(  121) },
      {  INT16_C(    29),  INT16_C(    17),  INT16_C(     4),  INT16_C(    29) },
      {      UINT16_MAX,      UINT16_MAX, UINT16_C(29312),      UINT16_MAX } },
    { { UINT16_C(    2), UINT16_C(   62), UINT16_C( 7510), UINT16_C(  117) },
      {  INT16_C(     5),  INT16_C(    28),  INT16_C(    12),  INT16_C(    31) },
      { UINT16_C(   64),      UINT16_MAX,      UINT16_MAX,      UINT16_MAX } },
    { { UINT16_C(   25), UINT16_C(   10), UINT16_C( 2018), UINT16_C(26774) },
      {  INT16_C(    18),  INT16_C(     4),  INT16_C(    25),  INT16_C(     0) },
      {      UINT16_MAX, UINT16_C(  160),      UINT16_MAX, UINT16_C(26774) } },
    { { UINT16_C(63771), UINT16_C(48484), UINT16_C(48368), UINT16_C( 4496) },
      { -INT16_C(  6779), -INT16_C( 21144), -INT16_C(   413),  INT16_C( 29973) },
      { UINT16_C(    0),      UINT16_MAX,      UINT16_MAX,      UINT16_MAX } },
    { { UINT16_C(63874), UINT16_C(31968), UINT16_C(49373), UINT16_C(43034) },
      {  INT16_C( 25884),  INT16_C(    63),  INT16_C( 16208),  INT16_C( 27523) },
      {      UINT16_MAX,      UINT16_MAX,      UINT16_MAX, UINT16_C(    0) } },
    { { UINT16_C(59193), UINT16_C(10537), UINT16_C(47524), UINT16_C(10554) },
      { -INT16_C( 23650),  INT16_C(   470), -INT16_C(  5215),  INT16_C(  9334) },
      { UINT16_C(    0), UINT16_C(    0), UINT16_C(    0),      UINT16_MAX } },
    { { UINT16_C(22244), UINT16_C(49824), UINT16_C(47638), UINT16_C(12906) },
      { -INT16_C( 21984),  INT16_C( 28723), -INT16_C( 18711),  INT16_C(  8923) },
      {      UINT16_MAX,      UINT16_MAX, UINT16_C(    0), UINT16_C(    0) } },
    { { UINT16_C( 1181), UINT16_C(16715), UINT16_C(34493), UINT16_C(23403) },
      {  INT16_C( 16681), -INT16_C( 13732), -INT16_C( 11475),  INT16_C(  4590) },
      {      UINT16_MAX,      UINT16_MAX,      UINT16_MAX, UINT16_C(    0) } },
    { { UINT16_C(36393), UINT16_C(16595), UINT16_C(15945), UINT16_C(26994) },
      { -INT16_C( 23064), -INT16_C( 11815), -INT16_C( 19365), -INT16_C(  1548) },
      { UINT16_C(    0), UINT16_C(    0),      UINT16_MAX, UINT16_C(    6) } },
    { { UINT16_C(16313), UINT16_C(30266), UINT16_C(42437), UINT16_C(61138) },
      {  INT16_C( 12007),  INT16_C(  5305), -INT16_C( 22783),  INT16_C( 11045) },
      { UINT16_C(    0), UINT16_C(    0),      UINT16_MAX,      UINT16_MAX } },
    { { UINT16_C(63798), UINT16_C(32619), UINT16_C(56631), UINT16_C( 8168) },
      { -INT16_C( 15997), -INT16_C(  8464), -INT16_C(  7051),  INT16_C( 11991) },
      { UINT16_C(    0), UINT16_C(    0),      UINT16_MAX, UINT16_C(    0) } },
    { { UINT16_C( 4644), UINT16_C(59813), UINT16_C(30647), UINT16_C(40664) },
      { -INT16_C( 28251), -INT16_C( 22606), -INT16_C( 10184),  INT16_C( 28370) },
      { UINT16_C(    0), UINT16_C(    0),      UINT16_MAX, UINT16_C(    0) } },
    { { UINT16_C(15825), UINT16_C( 2285), UINT16_C(54554), UINT16_C(40231) },
      {  INT16_C(  6038),  INT16_C(  3196),  INT16_C( 21500),  INT16_C(  8250) },
      { UINT16_C(    0),      UINT16_MAX, UINT16_C( 3409),      UINT16_MAX } },
    { { UINT16_C(57189), UINT16_C( 7433), UINT16_C(57686), UINT16_C(64699) },
      {  INT16_C( 28274), -INT16_C( 21597),  INT16_C( 30022),  INT16_C(  5913) },
      {      UINT16_MAX, UINT16_C(    0),      UINT16_MAX,      UINT16_MAX } },
    { { UINT16_C( 1970), UINT16_C(52255), UINT16_C(18140), UINT16_C(29546) },
      { -INT16_C(  6563),  INT16_C( 22911), -INT16_C( 18119), -INT16_C( 24711) },
      {      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX } },
    { { UINT16_C(33689), UINT16_C(61372), UINT16_C(30564), UINT16_C(55275) },
      { -INT16_C( 28955),  INT16_C( 11138), -INT16_C( 25853), -INT16_C( 19134) },
      { UINT16_C(    0), UINT16_C(    0),      UINT16_MAX,      UINT16_MAX } },
    { { UINT16_C(24994), UINT16_C(32642), UINT16_C(60583), UINT16_C( 1522) },
      {  INT16_C( 29138),  INT16_C(  2910), -INT16_C( 10198), -INT16_C( 15446) },
      { UINT16_C(    0),      UINT16_MAX,      UINT16_MAX, UINT16_C(    0) } },
    { { UINT16_C(26203), UINT16_C(49075), UINT16_C(40670), UINT16_C(50070) },
      {  INT16_C(  6189),  INT16_C( 12527),  INT16_C( 12724),  INT16_C( 22246) },
      {      UINT16_MAX, UINT16_C(    0), UINT16_C(    0), UINT16_C(    0) } },
    { { UINT16_C(26771), UINT16_C(15061), UINT16_C(51028), UINT16_C( 9791) },
      { -INT16_C( 25032),  INT16_C( 25393), -INT16_C(  9098), -INT16_C( 11994) },
      {      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint16x4_t a = simde_vld1_u16(test_vec[i].a);
    simde_int16x4_t b = simde_vld1_s16(test_vec[i].b);
    simde_uint16x4_t r = simde_vqshl_u16(a, b);

    simde_test_arm_neon_assert_equal_u16x4(r, simde_vld1_u16(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 16 ; i++) {
    simde_uint16x4_t a = simde_test_arm_neon_random_u16x4();
    simde_int16x4_t b = simde_test_arm_neon_random_i16x4();

    a = simde_vshl_u16(a, simde_vneg_s16(simde_vand_s16(simde_test_arm_neon_random_i16x4(), simde_vdup_n_s16(15))));
    b = simde_vand_s16(b, simde_vdup_n_s16(31));

    simde_uint16x4_t r = simde_vqshl_u16(a, b);

    simde_test_arm_neon_write_u16x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i16x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u16x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  for (int i = 0 ; i < 16 ; i++) {
    simde_uint16x4_t a = simde_test_arm_neon_random_u16x4();
    simde_int16x4_t b = simde_test_arm_neon_random_i16x4();

    simde_uint16x4_t r = simde_vqshl_u16(a, b);

    simde_test_arm_neon_write_u16x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i16x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u16x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vqshl_u32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint32_t a[2];
    int32_t b[2];
    uint32_t r[2];
  } test_vec[] = {
    { { UINT32_C(      2544), UINT32_C(      1248) },
      {  INT32_C(          20),  INT32_C(          27) },
      { UINT32_C(2667577344),           UINT32_MAX } },
    { { UINT32_C(  65971353), UINT32_C(      6240) },
      {  INT32_C(          47),  INT32_C(          43) },
      {           UINT32_MAX,           UINT32_MAX } },
    { { UINT32_C(     28908), UINT32_C(   6940219) },
      {  INT32_C(          34),  INT32_C(          21) },
      {           UINT32_MAX,           UINT32_MAX } },
    { { UINT32_C(       195), UINT32_C(     12628) },
      {  INT32_C(          35),  INT32_C(          33) },
      {           UINT32_MAX,           UINT32_MAX } },
    { { UINT32_C(    194774), UINT32_C(       372) },
      {  INT32_C(          42),  INT32_C(           7) },
      {           UINT32_MAX, UINT32_C(     47616) } },
    { { UINT32_C(  24132472), UINT32_C(         1) },
      {  INT32_C(          46),  INT32_C(          24) },
      {           UINT32_MAX, UINT32_C(  16777216) } },
    { { UINT32_C( 792063689), UINT32_C(1710605760) },
      {  INT32_C(           7),  INT32_C(          23) },
      {           UINT32_MAX,           UINT32_MAX } },
    { { UINT32_C(    128237), UINT32_C(     40737) },
      {  INT32_C(           9),  INT32_C(           4) },
      { UINT32_C(  65657344), UINT32_C(    651792) } },
    { { UINT32_C(      9606), UINT32_C(   1544857) },
      {  INT32_C(          46),  INT32_C(          25) },
      {           UINT32_MAX,           UINT32_MAX } },
    { { UINT32_C(   8937823), UINT32_C(4271525396) },
      {  INT32_C(          57),  INT32_C(          47) },
      {           UINT32_MAX,           UINT32_MAX } },
    { { UINT32_C(     10049), UINT32_C(         1) },
      {  INT32_C(           6),  INT32_C(           8) },
      { UINT32_C(    643136), UINT32_C(       256) } },
    { { UINT32_C(      2306), UINT32_C(     34113) },
      {  INT32_C(          27),  INT32_C(          45) },
      {           UINT32_MAX,           UINT32_MAX } },
    { { UINT32_C( 208549184), UINT32_C(        86) },
      {  INT32_C(          37),  INT32_C(          32) },
      {           UINT32_MAX,           UINT32_MAX } },
    { { UINT32_C(  18617189), UINT32_C(        13) },
      {  INT32_C(          27),  INT32_C(          20) },
      {           UINT32_MAX, UINT32_C(  13631488) } },
    { { UINT32_C(      2667), UINT32_C(       196) },
      {  INT32_C(           9),  INT32_C(           4) },
      { UINT32_C(   1365504), UINT32_C(      3136) } },
    { { UINT32_C(  54942519), UINT32_C(   5692020) },
      {  INT32_C(          18),  INT32_C(          60) },
      {           UINT32_MAX,           UINT32_MAX } },
    { { UINT32_C(1116134731), UINT32_C(2397063446) },
      { -INT32_C(  1648212484),  INT32_C(  1078687278) },
      { UINT32_C(  69758420),           UINT32_MAX } },
    { { UINT32_C( 397778651), UINT32_C(2849803621) },
      { -INT32_C(  1636761003), -INT32_C(  1277487000) },
      {           UINT32_MAX,           UINT32_MAX } },
    { { UINT32_C( 200631029), UINT32_C(2811876779) },
      {  INT32_C(  1229282075), -INT32_C(  1383493423) },
      {           UINT32_MAX, UINT32_C(         0) } },
    { { UINT32_C(2495888942), UINT32_C( 540910027) },
      {  INT32_C(   213823395), -INT32_C(  1111516473) },
      { UINT32_C(         0), UINT32_C(         0) } },
    { { UINT32_C(2814948860), UINT32_C(2773377674) },
      { -INT32_C(  1880190019),  INT32_C(  1379694371) },
      { UINT32_C(         0),           UINT32_MAX } },
    { { UINT32_C(2179334326), UINT32_C(1168253857) },
      { -INT32_C(  1705942830), -INT32_C(   162066182) },
      { UINT32_C(         0), UINT32_C(  18253966) } },
    { { UINT32_C(1352474565), UINT32_C(1073081473) },
      { -INT32_C(  1546722177),  INT32_C(   301271643) },
      {           UINT32_MAX,           UINT32_MAX } },
    { { UINT32_C(2895371018), UINT32_C(3522246142) },
      { -INT32_C(  1872018795),  INT32_C(   411484754) },
      { UINT32_C(         0),           UINT32_MAX } },
    { { UINT32_C(1667769569), UINT32_C(2409782544) },
      { -INT32_C(  1657638847), -INT32_C(  2068961414) },
      {           UINT32_MAX,           UINT32_MAX } },
    { { UINT32_C(  19939586), UINT32_C( 215097718) },
      { -INT32_C(  1231274653), -INT32_C(   523361537) },
      {           UINT32_MAX, UINT32_C( 107548859) } },
    { { UINT32_C(1447245382), UINT32_C(3588679059) },
      { -INT32_C(   814606251),  INT32_C(  1112809536) },
      {           UINT32_MAX,           UINT32_MAX } },
    { { UINT32_C(3628303458), UINT32_C( 165942694) },
      {  INT32_C(  1371504722), -INT32_C(   382562909) },
      {           UINT32_MAX, UINT32_C(         0) } },
    { { UINT32_C(1463842243), UINT32_C(2955683419) },
      {  INT32_C(  2122358334),  INT32_C(   549573822) },
      {           UINT32_MAX, UINT32_C(         0) } },
    { { UINT32_C(4277732440), UINT32_C(1812520218) },
      {  INT32_C(    29280094),  INT32_C(   418050133) },
      {           UINT32_MAX,           UINT32_MAX } },
    { { UINT32_C(3228510821), UINT32_C(2406587216) },
      { -INT32_C(   133304007),  INT32_C(   488165061) },
      {           UINT32_MAX, UINT32_C(         0) } },
    { { UINT32_C(3978039763), UINT32_C(1297687791) },
      {  INT32_C(  1078859755),  INT32_C(  1834563591) },
      { UINT32_C(      1896),           UINT32_MAX } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint32x2_t a = simde_vld1_u32(test_vec[i].a);
    simde_int32x2_t b = simde_vld1_s32(test_vec[i].b);
    simde_uint32x2_t r = simde_vqshl_u32(a, b);

    simde_test_arm_neon_assert_equal_u32x2(r, simde_vld1_u32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 16 ; i++) {
    simde_uint32x2_t a = simde_test_arm_neon_random_u32x2();
    simde_int32x2_t b = simde_test_arm_neon_random_i32x2();

    a = simde_vshl_u32(a, simde_vneg_s32(simde_vand_s32(simde_test_arm_neon_random_i32x2(), simde_vdup_n_s32(31))));
    b = simde_vand_s32(b, simde_vdup_n_s32(63));

    simde_uint32x2_t r = simde_vqshl_u32(a, b);

    simde_test_arm_neon_write_u32x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i32x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  for (int i = 0 ; i < 16 ; i++) {
    simde_uint32x2_t a = simde_test_arm_neon_random_u32x2();
    simde_int32x2_t b = simde_test_arm_neon_random_i32x2();

    simde_uint32x2_t r = simde_vqshl_u32(a, b);

    simde_test_arm_neon_write_u32x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i32x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vqshl_u64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint64_t a[1];
    int64_t b[1];
    uint64_t r[1];
  } test_vec[] = {
    { { UINT64_C(           119147058) },
      {  INT64_C(                  61) },
      {                     UINT64_MAX } },
    { { UINT64_C(       1573063114268) },
      {  INT64_C(                  49) },
      {                     UINT64_MAX } },
    { { UINT64_C(          3027636902) },
      {  INT64_C(                  31) },
      { UINT64_C( 6501800739126378496) } },
    { { UINT64_C(                3245) },
      {  INT64_C(                   5) },
      { UINT64_C(              103840) } },
    { { UINT64_C(     317326385869371) },
      {  INT64_C(                  25) },
      {                     UINT64_MAX } },
    { { UINT64_C(               35254) },
      {  INT64_C(                  60) },
      {                     UINT64_MAX } },
    { { UINT64_C(              416218) },
      {  INT64_C(                  30) },
      { UINT64_C(     446910674501632) } },
    { { UINT64_C(  517053331109190300) },
      {  INT64_C(                  23) },
      {                     UINT64_MAX } },
    { { UINT64_C(       1305879171864) },
      {  INT64_C(                  48) },
      {                     UINT64_MAX } },
    { { UINT64_C(          1226548653) },
      {  INT64_C(                  45) },
      {                     UINT64_MAX } },
    { { UINT64_C(             1758283) },
      {  INT64_C(                   5) },
      { UINT64_C(            56265056) } },
    { { UINT64_C(                  19) },
      {  INT64_C(                  53) },
      { UINT64_C(  171136785840078848) } },
    { { UINT64_C(            26879170) },
      {  INT64_C(                  63) },
      {                     UINT64_MAX } },
    { { UINT64_C(         11238651338) },
      {  INT64_C(                  31) },
      {                     UINT64_MAX } },
    { { UINT64_C(  426182137800385540) },
      {  INT64_C(                  46) },
      {                     UINT64_MAX } },
    { { UINT64_C(                 125) },
      {  INT64_C(                  47) },
      { UINT64_C(   17592186044416000) } },
    { { UINT64_C(10437630542991542235) },
      {  INT64_C( 5297690124391230158) },
      { UINT64_C(                9270) } },
    { { UINT64_C(13629218229989725249) },
      { -INT64_C( 7347741822446391900) },
      { UINT64_C(                   0) } },
    { { UINT64_C( 9590695470685343450) },
      { -INT64_C(  753343911219460312) },
      {                     UINT64_MAX } },
    { { UINT64_C(13036256330123402089) },
      {  INT64_C( 2710268996846401603) },
      {                     UINT64_MAX } },
    { { UINT64_C(16706600618745971101) },
      { -INT64_C( 1732280024114271925) },
      {                     UINT64_MAX } },
    { { UINT64_C( 4671639072313501199) },
      {  INT64_C(  587401352582438070) },
      { UINT64_C(                   0) } },
    { { UINT64_C(16376555643753780127) },
      {  INT64_C( 3712328540832821023) },
      {                     UINT64_MAX } },
    { { UINT64_C( 5618847013422733502) },
      { -INT64_C( 5100197822673830716) },
      { UINT64_C(                   4) } },
    { { UINT64_C(16844128682226717768) },
      {  INT64_C( 4188922135118783948) },
      { UINT64_C(                3740) } },
    { { UINT64_C( 7027567727119529378) },
      { -INT64_C( 7998172721167936468) },
      {                     UINT64_MAX } },
    { { UINT64_C( 4616527667002414941) },
      {  INT64_C( 4940258173416151000) },
      { UINT64_C(             4198707) } },
    { { UINT64_C(11584950889910994120) },
      {  INT64_C( 8985778702921389784) },
      { UINT64_C(            10536451) } },
    { { UINT64_C( 3509346822330197246) },
      { -INT64_C(  202076811410676916) },
      {                     UINT64_MAX } },
    { { UINT64_C(10064745491731755161) },
      {  INT64_C( 8654335713710281599) },
      {                     UINT64_MAX } },
    { { UINT64_C(13694212208591551876) },
      {  INT64_C( 4518199654498472064) },
      { UINT64_C(                   0) } },
    { { UINT64_C(13676860589677942414) },
      {  INT64_C( 6808727790907259531) },
      { UINT64_C(                   0) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint64x1_t a = simde_vld1_u64(test_vec[i].a);
    simde_int64x1_t b = simde_vld1_s64(test_vec[i].b);
    simde_uint64x1_t r = simde_vqshl_u64(a, b);

    simde_test_arm_neon_assert_equal_u64x1(r, simde_vld1_u64(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 16 ; i++) {
    simde_uint64x1_t a = simde_test_arm_neon_random_u64x1();
    simde_int64x1_t b = simde_test_arm_neon_random_i64x1();

    a = simde_vshl_u64(a, simde_vneg_s64(simde_vand_s64(simde_test_arm_neon_random_i64x1(), simde_vdup_n_s64(63))));
    b = simde_vand_s64(b, simde_vdup_n_s64(63));

    simde_uint64x1_t r = simde_vqshl_u64(a, b);

    simde_test_arm_neon_write_u64x1(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i64x1(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u64x1(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  for (int i = 0 ; i < 16 ; i++) {
    simde_uint64x1_t a = simde_test_arm_neon_random_u64x1();
    simde_int64x1_t b = simde_test_arm_neon_random_i64x1();

    simde_uint64x1_t r = simde_vqshl_u64(a, b);

    simde_test_arm_neon_write_u64x1(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i64x1(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u64x1(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vqshlq_s8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int8_t a[16];
    int8_t b[16];
    int8_t r[16];
  } test_vec[] = {
    { {  INT8_C(   3),  INT8_C(   6), -INT8_C(  89),  INT8_C(  51), -INT8_C(   9), -INT8_C(   7),  INT8_C(  17), -INT8_C(  26),
        -INT8_C(  57),  INT8_C(   0),  INT8_C( 118), -INT8_C(  23),  INT8_C(  44),  INT8_C(  65),  INT8_C(   0), -INT8_C(   3) },
      {  INT8_C(  12),  INT8_C(   9),  INT8_C(   8),  INT8_C(   6),  INT8_C(   9),  INT8_C(   8),  INT8_C(   2),  INT8_C(   3),
         INT8_C(   8),  INT8_C(   9),  INT8_C(  13),  INT8_C(   4),  INT8_C(  13),  INT8_C(   3),  INT8_C(  13),  INT8_C(  10) },
      {      INT8_MAX,      INT8_MAX,      INT8_MIN,      INT8_MAX,      INT8_MIN,      INT8_MIN,  INT8_C(  68),      INT8_MIN,
             INT8_MIN,  INT8_C(   0),      INT8_MAX,      INT8_MIN,      INT8_MAX,      INT8_MAX,  INT8_C(   0),      INT8_MIN } },
    { {  INT8_C( 113),  INT8_C(   0), -INT8_C(   2), -INT8_C(   2), -INT8_C(   2), -INT8_C(   6), -INT8_C(   9), -INT8_C(   4),
        -INT8_C(   9), -INT8_C(   3),  INT8_C(  10),  INT8_C(   1), -INT8_C(   2),  INT8_C(  39),  INT8_C(   7), -INT8_C( 102) },
      {  INT8_C(  11),  INT8_C(  15),  INT8_C(   4),  INT8_C(   7),  INT8_C(   3),  INT8_C(   5),  INT8_C(   1),  INT8_C(  12),
         INT8_C(  13),  INT8_C(   1),  INT8_C(  14),  INT8_C(   6),  INT8_C(   9),  INT8_C(  11),  INT8_C(  11),  INT8_C(  11) },
      {      INT8_MAX,  INT8_C(   0), -INT8_C(  32),      INT8_MIN, -INT8_C(  16),      INT8_MIN, -INT8_C(  18),      INT8_MIN,
             INT8_MIN, -INT8_C(   6),      INT8_MAX,  INT8_C(  64),      INT8_MIN,      INT8_MAX,      INT8_MAX,      INT8_MIN } },
    { { -INT8_C(   1), -INT8_C(  17),  INT8_C(  55),  INT8_C(   0), -INT8_C(  16),  INT8_C(   0),  INT8_C(   0),  INT8_C(   3),
         INT8_C(   9),  INT8_C(   3),  INT8_C(   0),  INT8_C(   2), -INT8_C(   1), -INT8_C(   4),  INT8_C(   9), -INT8_C(   1) },
      {  INT8_C(   8),  INT8_C(   4),  INT8_C(   6),  INT8_C(  14),  INT8_C(   8),  INT8_C(   9),  INT8_C(  12),  INT8_C(   8),
         INT8_C(   7),  INT8_C(  14),  INT8_C(   7),  INT8_C(  11),  INT8_C(  14),  INT8_C(   0),  INT8_C(  11),  INT8_C(  14) },
      {      INT8_MIN,      INT8_MIN,      INT8_MAX,  INT8_C(   0),      INT8_MIN,  INT8_C(   0),  INT8_C(   0),      INT8_MAX,
             INT8_MAX,      INT8_MAX,  INT8_C(   0),      INT8_MAX,      INT8_MIN, -INT8_C(   4),      INT8_MAX,      INT8_MIN } },
    { {  INT8_C(   2), -INT8_C(  56),  INT8_C(  92), -INT8_C(   1),  INT8_C(  13),  INT8_C(  26), -INT8_C(  35), -INT8_C(  31),
         INT8_C(   6), -INT8_C(   2),  INT8_C(   0), -INT8_C(   3),  INT8_C(   1),  INT8_C( 104),  INT8_C(  24), -INT8_C(  49) },
      {  INT8_C(  11),  INT8_C(   3),  INT8_C(  13),  INT8_C(   5),  INT8_C(   2),  INT8_C(  12),  INT8_C(   9),  INT8_C(  14),
         INT8_C(   1),  INT8_C(   0),  INT8_C(   1),  INT8_C(   6),  INT8_C(   5),  INT8_C(  12),  INT8_C(   4),  INT8_C(  14) },
      {      INT8_MAX,      INT8_MIN,      INT8_MAX, -INT8_C(  32),  INT8_C(  52),      INT8_MAX,      INT8_MIN,      INT8_MIN,
         INT8_C(  12), -INT8_C(   2),  INT8_C(   0),      INT8_MIN,  INT8_C(  32),      INT8_MAX,      INT8_MAX,      INT8_MIN } },
    { {  INT8_C(   0), -INT8_C(   2),  INT8_C(  55), -INT8_C(  11),  INT8_C(   1), -INT8_C(   1),  INT8_C(  60),  INT8_C(   0),
         INT8_C(  22), -INT8_C(   1),  INT8_C(  11),  INT8_C(   1), -INT8_C(   3),  INT8_C(  96),  INT8_C(  14),  INT8_C(   2) },
      {  INT8_C(   1),  INT8_C(  13),  INT8_C(  13),  INT8_C(  10),  INT8_C(   7),  INT8_C(   6),  INT8_C(  10),  INT8_C(   2),
         INT8_C(  12),  INT8_C(  15),  INT8_C(  14),  INT8_C(  11),  INT8_C(   7),  INT8_C(   8),  INT8_C(   4),  INT8_C(   3) },
      {  INT8_C(   0),      INT8_MIN,      INT8_MAX,      INT8_MIN,      INT8_MAX, -INT8_C(  64),      INT8_MAX,  INT8_C(   0),
             INT8_MAX,      INT8_MIN,      INT8_MAX,      INT8_MAX,      INT8_MIN,      INT8_MAX,      INT8_MAX,  INT8_C(  16) } },
    { {  INT8_C(   1), -INT8_C(   3),  INT8_C(   3),  INT8_C(   6),  INT8_C(   0), -INT8_C(  22),  INT8_C(   3), -INT8_C(  71),
         INT8_C(   0),  INT8_C(  26),  INT8_C(  34), -INT8_C(  12),  INT8_C(  15), -INT8_C(   3), -INT8_C(   1),  INT8_C(   0) },
      {  INT8_C(  12),  INT8_C(   5),  INT8_C(  15),  INT8_C(   8),  INT8_C(   2),  INT8_C(   8),  INT8_C(  13),  INT8_C(  12),
         INT8_C(  12),  INT8_C(   1),  INT8_C(  15),  INT8_C(   0),  INT8_C(   1),  INT8_C(   8),  INT8_C(   5),  INT8_C(  15) },
      {      INT8_MAX, -INT8_C(  96),      INT8_MAX,      INT8_MAX,  INT8_C(   0),      INT8_MIN,      INT8_MAX,      INT8_MIN,
         INT8_C(   0),  INT8_C(  52),      INT8_MAX, -INT8_C(  12),  INT8_C(  30),      INT8_MIN, -INT8_C(  32),  INT8_C(   0) } },
    { { -INT8_C(  10), -INT8_C(  90),  INT8_C(   0), -INT8_C(   6),  INT8_C(   0), -INT8_C(   2),  INT8_C(   2), -INT8_C(   3),
        -INT8_C(   1),  INT8_C(   0), -INT8_C(  13), -INT8_C(   6),  INT8_C(   0), -INT8_C(  17), -INT8_C(  19), -INT8_C(  11) },
      {  INT8_C(   4),  INT8_C(  10),  INT8_C(   1),  INT8_C(   2),  INT8_C(   4),  INT8_C(   6),  INT8_C(  10),  INT8_C(   2),
         INT8_C(  15),  INT8_C(   3),  INT8_C(  13),  INT8_C(   2),  INT8_C(   0),  INT8_C(   4),  INT8_C(   1),  INT8_C(   2) },
      {      INT8_MIN,      INT8_MIN,  INT8_C(   0), -INT8_C(  24),  INT8_C(   0),      INT8_MIN,      INT8_MAX, -INT8_C(  12),
             INT8_MIN,  INT8_C(   0),      INT8_MIN, -INT8_C(  24),  INT8_C(   0),      INT8_MIN, -INT8_C(  38), -INT8_C(  44) } },
    { { -INT8_C(  43), -INT8_C(   1), -INT8_C(   6),  INT8_C(  19),  INT8_C(   0),  INT8_C(   0), -INT8_C(   6),  INT8_C(  36),
         INT8_C(   0),  INT8_C(   3), -INT8_C(   2), -INT8_C(  20),  INT8_C(  50), -INT8_C(  59), -INT8_C(  14), -INT8_C(   1) },
      {  INT8_C(   4),  INT8_C(  12),  INT8_C(   8),  INT8_C(   1),  INT8_C(   2),  INT8_C(  12),  INT8_C(   5),  INT8_C(   8),
         INT8_C(  11),  INT8_C(   0),  INT8_C(   4),  INT8_C(   9),  INT8_C(   1),  INT8_C(   6),  INT8_C(  11),  INT8_C(  13) },
      {      INT8_MIN,      INT8_MIN,      INT8_MIN,  INT8_C(  38),  INT8_C(   0),  INT8_C(   0),      INT8_MIN,      INT8_MAX,
         INT8_C(   0),  INT8_C(   3), -INT8_C(  32),      INT8_MIN,  INT8_C( 100),      INT8_MIN,      INT8_MIN,      INT8_MIN } },
    { {  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   3),  INT8_C(   0),  INT8_C(   0),  INT8_C(   1), -INT8_C(  10),
         INT8_C(   9),  INT8_C(  84),  INT8_C(  42),  INT8_C(   0), -INT8_C(   4), -INT8_C(   3),  INT8_C(  15), -INT8_C(  23) },
      {  INT8_C(   4),  INT8_C(   6),  INT8_C(   7),  INT8_C(   3),  INT8_C(   5),  INT8_C(   2),  INT8_C(   4),  INT8_C(   3),
         INT8_C(   7),  INT8_C(   8),  INT8_C(   5),  INT8_C(   8),  INT8_C(   1),  INT8_C(   6),  INT8_C(  13),  INT8_C(   7) },
      {  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(  24),  INT8_C(   0),  INT8_C(   0),  INT8_C(  16), -INT8_C(  80),
             INT8_MAX,      INT8_MAX,      INT8_MAX,  INT8_C(   0), -INT8_C(   8),      INT8_MIN,      INT8_MAX,      INT8_MIN } },
    { { -INT8_C(   2), -INT8_C(   1), -INT8_C(  19),  INT8_C(  31),  INT8_C(   3), -INT8_C( 127),  INT8_C(   1),  INT8_C(   1),
         INT8_C(   1),  INT8_C(  25),  INT8_C(  60), -INT8_C(  35), -INT8_C(   3), -INT8_C(  30),  INT8_C(   5),  INT8_C(  61) },
      {  INT8_C(  13),  INT8_C(   0),  INT8_C(   0),  INT8_C(  13),  INT8_C(  15),  INT8_C(   7),  INT8_C(   8),  INT8_C(   3),
         INT8_C(   7),  INT8_C(   0),  INT8_C(   1),  INT8_C(  13),  INT8_C(   2),  INT8_C(   4),  INT8_C(   7),  INT8_C(  10) },
      {      INT8_MIN, -INT8_C(   1), -INT8_C(  19),      INT8_MAX,      INT8_MAX,      INT8_MIN,      INT8_MAX,  INT8_C(   8),
             INT8_MAX,  INT8_C(  25),  INT8_C( 120),      INT8_MIN, -INT8_C(  12),      INT8_MIN,      INT8_MAX,      INT8_MAX } },
    { { -INT8_C(   5), -INT8_C(   1), -INT8_C(   3), -INT8_C(  38), -INT8_C(   7),  INT8_C(  21), -INT8_C(   5),  INT8_C(   8),
         INT8_C(   3),  INT8_C(   4),  INT8_C(  20),  INT8_C(   3), -INT8_C(   6), -INT8_C(   4),  INT8_C(   1),  INT8_C(   0) },
      {  INT8_C(  11),  INT8_C(  10),  INT8_C(  12),  INT8_C(   0),  INT8_C(   3),  INT8_C(  10),  INT8_C(  14),  INT8_C(   1),
         INT8_C(   4),  INT8_C(   7),  INT8_C(  10),  INT8_C(   7),  INT8_C(   1),  INT8_C(  15),  INT8_C(   8),  INT8_C(  11) },
      {      INT8_MIN,      INT8_MIN,      INT8_MIN, -INT8_C(  38), -INT8_C(  56),      INT8_MAX,      INT8_MIN,  INT8_C(  16),
         INT8_C(  48),      INT8_MAX,      INT8_MAX,      INT8_MAX, -INT8_C(  12),      INT8_MIN,      INT8_MAX,  INT8_C(   0) } },
    { { -INT8_C(   1), -INT8_C(  28),  INT8_C(   0),  INT8_C(  13),  INT8_C(  11),  INT8_C(  29),  INT8_C(  91), -INT8_C(   1),
        -INT8_C(  67), -INT8_C(   1), -INT8_C(   2),  INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   1), -INT8_C(   3) },
      {  INT8_C(   6),  INT8_C(  15),  INT8_C(   9),  INT8_C(   2),  INT8_C(   1),  INT8_C(  12),  INT8_C(   5),  INT8_C(   2),
         INT8_C(   0),  INT8_C(  15),  INT8_C(   6),  INT8_C(  12),  INT8_C(  12),  INT8_C(  12),  INT8_C(   3),  INT8_C(   4) },
      { -INT8_C(  64),      INT8_MIN,  INT8_C(   0),  INT8_C(  52),  INT8_C(  22),      INT8_MAX,      INT8_MAX, -INT8_C(   4),
        -INT8_C(  67),      INT8_MIN,      INT8_MIN,      INT8_MAX,  INT8_C(   0),      INT8_MIN,  INT8_C(   8), -INT8_C(  48) } },
    { {  INT8_C(   0), -INT8_C(   2),  INT8_C(   3), -INT8_C(  23), -INT8_C(  15),  INT8_C(   0),  INT8_C(   0),  INT8_C(   3),
        -INT8_C(   3), -INT8_C(   2), -INT8_C(   1),  INT8_C(   0),  INT8_C(  45),  INT8_C(  12),  INT8_C(   0), -INT8_C(   1) },
      {  INT8_C(  13),  INT8_C(  11),  INT8_C(   1),  INT8_C(  14),  INT8_C(   5),  INT8_C(   9),  INT8_C(  11),  INT8_C(   5),
         INT8_C(   9),  INT8_C(   7),  INT8_C(  10),  INT8_C(   8),  INT8_C(  12),  INT8_C(   8),  INT8_C(  13),  INT8_C(   0) },
      {  INT8_C(   0),      INT8_MIN,  INT8_C(   6),      INT8_MIN,      INT8_MIN,  INT8_C(   0),  INT8_C(   0),  INT8_C(  96),
             INT8_MIN,      INT8_MIN,      INT8_MIN,  INT8_C(   0),      INT8_MAX,      INT8_MAX,  INT8_C(   0), -INT8_C(   1) } },
    { { -INT8_C(   1),  INT8_C(   2), -INT8_C( 123), -INT8_C(  62), -INT8_C(   2),  INT8_C(   0), -INT8_C(  19), -INT8_C(   2),
        -INT8_C(  89),  INT8_C(   1), -INT8_C(   6),  INT8_C(   9), -INT8_C(  15),  INT8_C(   1), -INT8_C(  15), -INT8_C(   1) },
      {  INT8_C(  11),  INT8_C(   9),  INT8_C(  10),  INT8_C(  12),  INT8_C(   6),  INT8_C(   1),  INT8_C(   9),  INT8_C(   2),
         INT8_C(   7),  INT8_C(  15),  INT8_C(   9),  INT8_C(   1),  INT8_C(   1),  INT8_C(   7),  INT8_C(   8),  INT8_C(  14) },
      {      INT8_MIN,      INT8_MAX,      INT8_MIN,      INT8_MIN,      INT8_MIN,  INT8_C(   0),      INT8_MIN, -INT8_C(   8),
             INT8_MIN,      INT8_MAX,      INT8_MIN,  INT8_C(  18), -INT8_C(  30),      INT8_MAX,      INT8_MIN,      INT8_MIN } },
    { {  INT8_C(   0),  INT8_C(   3), -INT8_C(  51),  INT8_C(   3), -INT8_C(   3),  INT8_C(   0),  INT8_C(   0),  INT8_C(  60),
        -INT8_C(   2), -INT8_C(   7),  INT8_C(   6), -INT8_C(   3),  INT8_C(  31), -INT8_C(   1), -INT8_C(  32),  INT8_C(   6) },
      {  INT8_C(   2),  INT8_C(   2),  INT8_C(   5),  INT8_C(  15),  INT8_C(   9),  INT8_C(   7),  INT8_C(   4),  INT8_C(   1),
         INT8_C(   3),  INT8_C(  13),  INT8_C(   2),  INT8_C(   6),  INT8_C(   9),  INT8_C(  11),  INT8_C(   5),  INT8_C(  14) },
      {  INT8_C(   0),  INT8_C(  12),      INT8_MIN,      INT8_MAX,      INT8_MIN,  INT8_C(   0),  INT8_C(   0),  INT8_C( 120),
        -INT8_C(  16),      INT8_MIN,  INT8_C(  24),      INT8_MIN,      INT8_MAX,      INT8_MIN,      INT8_MIN,      INT8_MAX } },
    { {  INT8_C(   4),  INT8_C(  44),  INT8_C(   2), -INT8_C(  30), -INT8_C(  17),  INT8_C(   0),  INT8_C(   3),  INT8_C(   0),
         INT8_C(   0),  INT8_C(   0), -INT8_C(  10), -INT8_C(  10), -INT8_C(   1), -INT8_C(   1), -INT8_C(   2), -INT8_C(  13) },
      {  INT8_C(  14),  INT8_C(   5),  INT8_C(  13),  INT8_C(   3),  INT8_C(  12),  INT8_C(  12),  INT8_C(  11),  INT8_C(  11),
         INT8_C(   9),  INT8_C(   7),  INT8_C(   8),  INT8_C(  10),  INT8_C(   6),  INT8_C(  10),  INT8_C(  14),  INT8_C(   8) },
      {      INT8_MAX,      INT8_MAX,      INT8_MAX,      INT8_MIN,      INT8_MIN,  INT8_C(   0),      INT8_MAX,  INT8_C(   0),
         INT8_C(   0),  INT8_C(   0),      INT8_MIN,      INT8_MIN, -INT8_C(  64),      INT8_MIN,      INT8_MIN,      INT8_MIN } },
    { {  INT8_C(  91), -INT8_C(  65),  INT8_C(  46), -INT8_C(  57), -INT8_C( 100), -INT8_C(  87),  INT8_C(  18), -INT8_C(  91),
        -INT8_C( 111),  INT8_C( 122), -INT8_C(  65),  INT8_C( 103),  INT8_C(  53), -INT8_C(  51),  INT8_C(  79),  INT8_C(  71) },
      { -INT8_C(  18), -INT8_C(  62),  INT8_C(  73),  INT8_C(  39), -INT8_C(  94),  INT8_C(  94),  INT8_C( 116), -INT8_C(  64),
         INT8_C(  77), -INT8_C(  82), -INT8_C(  55),  INT8_C(  42), -INT8_C(  28),  INT8_C( 108), -INT8_C(  91),  INT8_C(  63) },
      {  INT8_C(   0), -INT8_C(   1),      INT8_MAX,      INT8_MIN, -INT8_C(   1),      INT8_MIN,      INT8_MAX, -INT8_C(   1),
             INT8_MIN,  INT8_C(   0), -INT8_C(   1),      INT8_MAX,  INT8_C(   0),      INT8_MIN,  INT8_C(   0),      INT8_MAX } },
    { {  INT8_C(  43), -INT8_C(  44),  INT8_C(   7), -INT8_C(  57),  INT8_C( 125),  INT8_C(  25),  INT8_C( 108),  INT8_C(  14),
        -INT8_C( 108),  INT8_C(  44),  INT8_C( 118), -INT8_C(  55), -INT8_C(   7), -INT8_C(  59),  INT8_C(  16), -INT8_C(  24) },
      { -INT8_C( 120),  INT8_C(  90),  INT8_C(  15),  INT8_C(  42), -INT8_C(  72), -INT8_C( 125), -INT8_C(  22),  INT8_C(   5),
         INT8_C(  49), -INT8_C(  76),  INT8_C(  47),  INT8_C(  22),  INT8_C(  32), -INT8_C(  43),  INT8_C(  85),  INT8_C(  75) },
      {  INT8_C(   0),      INT8_MIN,      INT8_MAX,      INT8_MIN,  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),      INT8_MAX,
             INT8_MIN,  INT8_C(   0),      INT8_MAX,      INT8_MIN,      INT8_MIN, -INT8_C(   1),      INT8_MAX,      INT8_MIN } },
    { { -INT8_C(  87),  INT8_C(  92),  INT8_C(  19),  INT8_C(  38),  INT8_C( 118),      INT8_MAX,  INT8_C(  53),  INT8_C(  10),
        -INT8_C(  85), -INT8_C(  85), -INT8_C(  45), -INT8_C(  91),  INT8_C( 112), -INT8_C(  29), -INT8_C( 115), -INT8_C(   8) },
      {  INT8_C(  61), -INT8_C( 100),  INT8_C(  34), -INT8_C(  10),  INT8_C(  31),  INT8_C(  13), -INT8_C(   5),  INT8_C(  80),
        -INT8_C(  63),  INT8_C(  43),  INT8_C( 102), -INT8_C(  31),  INT8_C(   0), -INT8_C(  68),  INT8_C(  44), -INT8_C(  87) },
      {      INT8_MIN,  INT8_C(   0),      INT8_MAX,  INT8_C(   0),      INT8_MAX,      INT8_MAX,  INT8_C(   1),      INT8_MAX,
        -INT8_C(   1),      INT8_MIN,      INT8_MIN, -INT8_C(   1),  INT8_C( 112), -INT8_C(   1),      INT8_MIN, -INT8_C(   1) } },
    { {  INT8_C(  24),  INT8_C(  63), -INT8_C(  49), -INT8_C( 114), -INT8_C(  65),  INT8_C(   4), -INT8_C( 104),  INT8_C( 106),
        -INT8_C(  81),  INT8_C( 107),  INT8_C(  15),  INT8_C(  32),  INT8_C(  79), -INT8_C( 100),  INT8_C(  24), -INT8_C( 116) },
      {  INT8_C(  56),  INT8_C(  59), -INT8_C( 126),  INT8_C(  87),  INT8_C(  72),  INT8_C( 126), -INT8_C(  88),  INT8_C(   9),
        -INT8_C(  87),  INT8_C(  14), -INT8_C(  22), -INT8_C(  87), -INT8_C(  54),  INT8_C(  22),  INT8_C(  82), -INT8_C(  29) },
      {      INT8_MAX,      INT8_MAX, -INT8_C(   1),      INT8_MIN,      INT8_MIN,      INT8_MAX, -INT8_C(   1),      INT8_MAX,
        -INT8_C(   1),      INT8_MAX,  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),      INT8_MIN,      INT8_MAX, -INT8_C(   1) } },
    { {  INT8_C(  86),  INT8_C(  33),  INT8_C( 113),  INT8_C(  21),  INT8_C(  38),  INT8_C(  10),      INT8_MAX, -INT8_C(  43),
         INT8_C( 117), -INT8_C( 113), -INT8_C(  11), -INT8_C(  60),  INT8_C(  43),  INT8_C(  14),  INT8_C(  81),  INT8_C( 100) },
      {  INT8_C(  73), -INT8_C(  45), -INT8_C(  69), -INT8_C( 111),  INT8_C(  81),  INT8_C(  99), -INT8_C( 102), -INT8_C(   6),
         INT8_C( 114), -INT8_C( 124), -INT8_C(  93),  INT8_C(  60), -INT8_C( 102), -INT8_C(  11),  INT8_C(  31), -INT8_C(  16) },
      {      INT8_MAX,  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),      INT8_MAX,      INT8_MAX,  INT8_C(   0), -INT8_C(   1),
             INT8_MAX, -INT8_C(   1), -INT8_C(   1),      INT8_MIN,  INT8_C(   0),  INT8_C(   0),      INT8_MAX,  INT8_C(   0) } },
    { {  INT8_C(  23), -INT8_C( 111),  INT8_C(   5),  INT8_C(  61), -INT8_C( 101), -INT8_C( 123),  INT8_C(  18),  INT8_C(  16),
         INT8_C(  20),  INT8_C(   8), -INT8_C(  43),  INT8_C(  63),  INT8_C(  22),  INT8_C(  38), -INT8_C(  93),  INT8_C(  95) },
      { -INT8_C(   7),  INT8_C(  95), -INT8_C(  16),  INT8_C(  75), -INT8_C(  62), -INT8_C( 118),  INT8_C(  69),  INT8_C(  52),
         INT8_C(  14), -INT8_C(  23),  INT8_C( 113), -INT8_C(  88), -INT8_C(  34), -INT8_C( 112), -INT8_C( 103), -INT8_C(  11) },
      {  INT8_C(   0),      INT8_MIN,  INT8_C(   0),      INT8_MAX, -INT8_C(   1), -INT8_C(   1),      INT8_MAX,      INT8_MAX,
             INT8_MAX,  INT8_C(   0),      INT8_MIN,  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0) } },
    { {  INT8_C(  33), -INT8_C(  98),  INT8_C(  50), -INT8_C(  68),  INT8_C(  35),  INT8_C(  69), -INT8_C(  51),  INT8_C(  55),
         INT8_C(  77), -INT8_C(  94),  INT8_C( 119),  INT8_C(  99), -INT8_C(  56),  INT8_C(  26), -INT8_C(  62), -INT8_C(  63) },
      {  INT8_C( 121), -INT8_C(  78),  INT8_C(  12),  INT8_C(  60),  INT8_C(  60),  INT8_C(  82),  INT8_C( 112),  INT8_C(  74),
         INT8_C(  59), -INT8_C(  31), -INT8_C(  14),  INT8_C(  25),  INT8_C( 114), -INT8_C( 117),  INT8_C(  15), -INT8_C( 109) },
      {      INT8_MAX, -INT8_C(   1),      INT8_MAX,      INT8_MIN,      INT8_MAX,      INT8_MAX,      INT8_MIN,      INT8_MAX,
             INT8_MAX, -INT8_C(   1),  INT8_C(   0),      INT8_MAX,      INT8_MIN,  INT8_C(   0),      INT8_MIN, -INT8_C(   1) } },
    { {  INT8_C(  42),  INT8_C(  65),  INT8_C(  80),  INT8_C(  77), -INT8_C( 122),  INT8_C(  29), -INT8_C( 123), -INT8_C(  45),
        -INT8_C(  65), -INT8_C(   4),  INT8_C(  54), -INT8_C( 121),  INT8_C(  22), -INT8_C(   8),  INT8_C(  72), -INT8_C( 112) },
      { -INT8_C(  86),  INT8_C(  85), -INT8_C(  52), -INT8_C(  26), -INT8_C(  89),  INT8_C(  60),  INT8_C(  48), -INT8_C(  30),
         INT8_C(  30),  INT8_C(  35), -INT8_C(   5), -INT8_C( 112), -INT8_C(  82),  INT8_C(  10),  INT8_C(  35), -INT8_C(  40) },
      {  INT8_C(   0),      INT8_MAX,  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),      INT8_MAX,      INT8_MIN, -INT8_C(   1),
             INT8_MIN,      INT8_MIN,  INT8_C(   1), -INT8_C(   1),  INT8_C(   0),      INT8_MIN,      INT8_MAX, -INT8_C(   1) } },
    { {  INT8_C(  76),  INT8_C( 115),  INT8_C(  38), -INT8_C(  46), -INT8_C( 112), -INT8_C(  85), -INT8_C(  90),  INT8_C(  79),
        -INT8_C(  89), -INT8_C(  36), -INT8_C(  42), -INT8_C(  67), -INT8_C(  43),  INT8_C(  31),  INT8_C(  77),      INT8_MAX },
      {  INT8_C( 116),  INT8_C(  25),  INT8_C( 102),  INT8_C(  27),  INT8_C(  86), -INT8_C( 106), -INT8_C(   3),  INT8_C( 116),
        -INT8_C(  71), -INT8_C(   8),  INT8_C(   4),  INT8_C( 104),  INT8_C(   3),  INT8_C(  39),  INT8_C(  64),  INT8_C(  79) },
      {      INT8_MAX,      INT8_MAX,      INT8_MAX,      INT8_MIN,      INT8_MIN, -INT8_C(   1), -INT8_C(  12),      INT8_MAX,
        -INT8_C(   1), -INT8_C(   1),      INT8_MIN,      INT8_MIN,      INT8_MIN,      INT8_MAX,      INT8_MAX,      INT8_MAX } },
    { { -INT8_C( 101),  INT8_C( 102),  INT8_C(  33),  INT8_C(  43),  INT8_C(  17), -INT8_C(  57),  INT8_C( 123), -INT8_C(  72),
        -INT8_C(  92),  INT8_C(  81),  INT8_C( 118),  INT8_C( 121),  INT8_C( 112), -INT8_C(  61), -INT8_C(   8), -INT8_C(  28) },
      { -INT8_C(  35),  INT8_C(  94), -INT8_C(   1),  INT8_C(  51), -INT8_C(  11), -INT8_C(   4), -INT8_C(  89), -INT8_C(  82),
        -INT8_C(  11), -INT8_C(  85),  INT8_C(  22), -INT8_C(   8), -INT8_C(  46),  INT8_C(  87),  INT8_C(  71),  INT8_C( 109) },
      { -INT8_C(   1),      INT8_MAX,  INT8_C(  16),      INT8_MAX,  INT8_C(   0), -INT8_C(   4),  INT8_C(   0), -INT8_C(   1),
        -INT8_C(   1),  INT8_C(   0),      INT8_MAX,  INT8_C(   0),  INT8_C(   0),      INT8_MIN,      INT8_MIN,      INT8_MIN } },
    { { -INT8_C(  67),  INT8_C( 104), -INT8_C( 103), -INT8_C(  49),  INT8_C(  48),  INT8_C(  20), -INT8_C( 121), -INT8_C(  44),
         INT8_C( 101), -INT8_C(   3),  INT8_C(  77), -INT8_C(  42), -INT8_C(  63),  INT8_C(  69), -INT8_C(  70), -INT8_C(  98) },
      { -INT8_C(  92), -INT8_C(  70), -INT8_C(  47), -INT8_C( 103), -INT8_C(  74),  INT8_C( 120),  INT8_C(  71), -INT8_C(  85),
         INT8_C(  35),  INT8_C(  94), -INT8_C(  93), -INT8_C(  11), -INT8_C(  75), -INT8_C(  22),  INT8_C(  99),  INT8_C( 114) },
      { -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),      INT8_MAX,      INT8_MIN, -INT8_C(   1),
             INT8_MAX,      INT8_MIN,  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),      INT8_MIN,      INT8_MIN } },
    { {  INT8_C(  83), -INT8_C(   4),  INT8_C(  65), -INT8_C( 125),  INT8_C(  16), -INT8_C(  55),  INT8_C(  87),  INT8_C( 117),
        -INT8_C(  58), -INT8_C(  92),  INT8_C(  75), -INT8_C( 121), -INT8_C(  23),  INT8_C(   6),  INT8_C(  37), -INT8_C( 115) },
      { -INT8_C(  64), -INT8_C(  10),  INT8_C(  38),  INT8_C( 118),  INT8_C( 110),  INT8_C( 110),  INT8_C(  34), -INT8_C( 111),
        -INT8_C(  52), -INT8_C(  59), -INT8_C( 121), -INT8_C( 127), -INT8_C(  80), -INT8_C(  22), -INT8_C(  13),  INT8_C(   3) },
      {  INT8_C(   0), -INT8_C(   1),      INT8_MAX,      INT8_MIN,      INT8_MAX,      INT8_MIN,      INT8_MAX,  INT8_C(   0),
        -INT8_C(   1), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0),      INT8_MIN } },
    { { -INT8_C(  26),  INT8_C(  53), -INT8_C( 122), -INT8_C(  10), -INT8_C(   2), -INT8_C(  35),  INT8_C( 107), -INT8_C(  60),
        -INT8_C( 127), -INT8_C(  73),  INT8_C(  76),  INT8_C( 106), -INT8_C(  67),  INT8_C( 113), -INT8_C(   8),  INT8_C( 125) },
      {  INT8_C( 104),  INT8_C(  30), -INT8_C(  13), -INT8_C(  42), -INT8_C( 116),  INT8_C(  21),  INT8_C( 104),  INT8_C(  88),
        -INT8_C(  37), -INT8_C(  17), -INT8_C(  39), -INT8_C( 117), -INT8_C(  39), -INT8_C(  51), -INT8_C( 114), -INT8_C(  65) },
      {      INT8_MIN,      INT8_MAX, -INT8_C(   1), -INT8_C(   1), -INT8_C(   1),      INT8_MIN,      INT8_MAX,      INT8_MIN,
        -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0), -INT8_C(   1),  INT8_C(   0) } },
    { {  INT8_C(   2),  INT8_C(  20), -INT8_C(  75),  INT8_C(   0), -INT8_C(  15),  INT8_C(  32), -INT8_C(  60),  INT8_C( 114),
        -INT8_C(  41),  INT8_C(  16), -INT8_C(  36), -INT8_C( 108), -INT8_C( 126), -INT8_C(  44),  INT8_C(  17), -INT8_C(  22) },
      { -INT8_C(  13),  INT8_C(   5), -INT8_C(  64),      INT8_MAX,  INT8_C(  26),  INT8_C(  40), -INT8_C(  40), -INT8_C(  11),
         INT8_C(  23), -INT8_C(  79),      INT8_MIN, -INT8_C(  16),  INT8_C( 126),  INT8_C(  14), -INT8_C(  81),      INT8_MIN },
      {  INT8_C(   0),      INT8_MAX, -INT8_C(   1),  INT8_C(   0),      INT8_MIN,      INT8_MAX, -INT8_C(   1),  INT8_C(   0),
             INT8_MIN,  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),      INT8_MIN,      INT8_MIN,  INT8_C(   0), -INT8_C(   1) } },
    { {  INT8_C(  34),  INT8_C( 100),      INT8_MIN,  INT8_C(  19), -INT8_C( 123),  INT8_C(  69), -INT8_C( 123),  INT8_C(  92),
         INT8_C(  85),  INT8_C(  98), -INT8_C(  15), -INT8_C(  41),  INT8_C(  54),  INT8_C(   2), -INT8_C(  63),  INT8_C(  41) },
      {  INT8_C(   7), -INT8_C( 126), -INT8_C(  87),  INT8_C(  34), -INT8_C(  86), -INT8_C( 127),  INT8_C(  23), -INT8_C(  62),
         INT8_C(  50), -INT8_C( 104), -INT8_C(  78), -INT8_C(  79), -INT8_C(  90),  INT8_C(  98),  INT8_C(  49), -INT8_C(  55) },
      {      INT8_MAX,  INT8_C(   0), -INT8_C(   1),      INT8_MAX, -INT8_C(   1),  INT8_C(   0),      INT8_MIN,  INT8_C(   0),
             INT8_MAX,  INT8_C(   0), -INT8_C(   1), -INT8_C(   1),  INT8_C(   0),      INT8_MAX,      INT8_MIN,  INT8_C(   0) } },
    { { -INT8_C(  58), -INT8_C(  78), -INT8_C(  36),  INT8_C(  75), -INT8_C(   9),  INT8_C(  98), -INT8_C(  88),  INT8_C(  76),
        -INT8_C(  60), -INT8_C( 103),  INT8_C(  36), -INT8_C(   6), -INT8_C( 101), -INT8_C(  27),  INT8_C(  36), -INT8_C(  93) },
      {  INT8_C( 103), -INT8_C(  51), -INT8_C(  59),  INT8_C(  18),  INT8_C(  78), -INT8_C(  36), -INT8_C(  44),      INT8_MIN,
         INT8_C( 116), -INT8_C( 122),  INT8_C(  49),  INT8_C(  27), -INT8_C(  24),  INT8_C(  99), -INT8_C(  28), -INT8_C(  81) },
      {      INT8_MIN, -INT8_C(   1), -INT8_C(   1),      INT8_MAX,      INT8_MIN,  INT8_C(   0), -INT8_C(   1),  INT8_C(   0),
             INT8_MIN, -INT8_C(   1),      INT8_MAX,      INT8_MIN, -INT8_C(   1),      INT8_MIN,  INT8_C(   0), -INT8_C(   1) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int8x16_t a = simde_vld1q_s8(test_vec[i].a);
    simde_int8x16_t b = simde_vld1q_s8(test_vec[i].b);
    simde_int8x16_t r = simde_vqshlq_s8(a, b);

    simde_test_arm_neon_assert_equal_i8x16(r, simde_vld1q_s8(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 16 ; i++) {
    simde_int8x16_t a = simde_test_arm_neon_random_i8x16();
    simde_int8x16_t b = simde_test_arm_neon_random_i8x16();

    a = simde_vshlq_s8(a, simde_vnegq_s8(simde_vandq_s8(simde_test_arm_neon_random_i8x16(), simde_vdupq_n_s8(7))));
    b = simde_vandq_s8(b, simde_vdupq_n_s8(15));

    simde_int8x16_t r = simde_vqshlq_s8(a, b);

    simde_test_arm_neon_write_i8x16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i8x16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i8x16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  for (int i = 0 ; i < 16 ; i++) {
    simde_int8x16_t a = simde_test_arm_neon_random_i8x16();
    simde_int8x16_t b = simde_test_arm_neon_random_i8x16();

    simde_int8x16_t r = simde_vqshlq_s8(a, b);

    simde_test_arm_neon_write_i8x16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i8x16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i8x16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vqshlq_s16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int16_t a[8];
    int16_t b[8];
    int16_t r[8];
  } test_vec[] = {
    { {  INT16_C(     3), -INT16_C(   100), -INT16_C( 15366),  INT16_C(     1),  INT16_C(     0), -INT16_C(    34), -INT16_C(  4336),  INT16_C(   143) },
      {  INT16_C(    31),  INT16_C(     7),  INT16_C(    24),  INT16_C(     1),  INT16_C(    17),  INT16_C(    16),  INT16_C(     2),  INT16_C(    14) },
      {        INT16_MAX, -INT16_C( 12800),        INT16_MIN,  INT16_C(     2),  INT16_C(     0),        INT16_MIN, -INT16_C( 17344),        INT16_MAX } },
    { {  INT16_C(     0), -INT16_C(   933),  INT16_C(  1447),  INT16_C( 29180),  INT16_C(     1),  INT16_C(     1),  INT16_C(     0),  INT16_C(   288) },
      {  INT16_C(    17),  INT16_C(    12),  INT16_C(    26),  INT16_C(    10),  INT16_C(    29),  INT16_C(    28),  INT16_C(     2),  INT16_C(     0) },
      {  INT16_C(     0),        INT16_MIN,        INT16_MAX,        INT16_MAX,        INT16_MAX,        INT16_MAX,  INT16_C(     0),  INT16_C(   288) } },
    { { -INT16_C(  4259),  INT16_C(  7676), -INT16_C(   556), -INT16_C(     8), -INT16_C(   705), -INT16_C(   247),  INT16_C( 12775), -INT16_C(     2) },
      {  INT16_C(    29),  INT16_C(    13),  INT16_C(    22),  INT16_C(    25),  INT16_C(     6),  INT16_C(    13),  INT16_C(    29),  INT16_C(    21) },
      {        INT16_MIN,        INT16_MAX,        INT16_MIN,        INT16_MIN,        INT16_MIN,        INT16_MIN,        INT16_MAX,        INT16_MIN } },
    { {  INT16_C(    11),  INT16_C( 10511),  INT16_C(     1),  INT16_C( 16230), -INT16_C(    20), -INT16_C(    10),  INT16_C(     2), -INT16_C(  3806) },
      {  INT16_C(     0),  INT16_C(    11),  INT16_C(    14),  INT16_C(     8),  INT16_C(     4),  INT16_C(    30),  INT16_C(     3),  INT16_C(     4) },
      {  INT16_C(    11),        INT16_MAX,  INT16_C( 16384),        INT16_MAX, -INT16_C(   320),        INT16_MIN,  INT16_C(    16),        INT16_MIN } },
    { {  INT16_C(     1),  INT16_C( 11106),  INT16_C(     2), -INT16_C(    18), -INT16_C(   873),  INT16_C(     0),  INT16_C(   136),  INT16_C(   155) },
      {  INT16_C(    20),  INT16_C(    14),  INT16_C(     3),  INT16_C(    28),  INT16_C(    18),  INT16_C(    28),  INT16_C(    24),  INT16_C(    13) },
      {        INT16_MAX,        INT16_MAX,  INT16_C(    16),        INT16_MIN,        INT16_MIN,  INT16_C(     0),        INT16_MAX,        INT16_MAX } },
    { {  INT16_C(     0),  INT16_C(   121),  INT16_C(   475),  INT16_C(    27),  INT16_C(  4438), -INT16_C(   248), -INT16_C(  4868), -INT16_C(     1) },
      {  INT16_C(     2),  INT16_C(    28),  INT16_C(     5),  INT16_C(    16),  INT16_C(    23),  INT16_C(    18),  INT16_C(     9),  INT16_C(    22) },
      {  INT16_C(     0),        INT16_MAX,  INT16_C( 15200),        INT16_MAX,        INT16_MAX,        INT16_MIN,        INT16_MIN,        INT16_MIN } },
    { {  INT16_C(     3),  INT16_C(   323), -INT16_C(     6),  INT16_C(  7570), -INT16_C(    18),  INT16_C(   361), -INT16_C(     2), -INT16_C(  2929) },
      {  INT16_C(     9),  INT16_C(    23),  INT16_C(    15),  INT16_C(     2),  INT16_C(    16),  INT16_C(     2),  INT16_C(    11),  INT16_C(    23) },
      {  INT16_C(  1536),        INT16_MAX,        INT16_MIN,  INT16_C( 30280),        INT16_MIN,  INT16_C(  1444), -INT16_C(  4096),        INT16_MIN } },
    { {  INT16_C( 15680),  INT16_C(     0),  INT16_C(     0), -INT16_C(   106),  INT16_C(   963),  INT16_C(     1),  INT16_C(     5), -INT16_C(   185) },
      {  INT16_C(    14),  INT16_C(    13),  INT16_C(    25),  INT16_C(    22),  INT16_C(    21),  INT16_C(     3),  INT16_C(    28),  INT16_C(    27) },
      {        INT16_MAX,  INT16_C(     0),  INT16_C(     0),        INT16_MIN,        INT16_MAX,  INT16_C(     8),        INT16_MAX,        INT16_MIN } },
    { { -INT16_C(    23),  INT16_C(    12),  INT16_C(     3), -INT16_C(   205),  INT16_C(  1500), -INT16_C(   246), -INT16_C(     1), -INT16_C(     1) },
      {  INT16_C(    27),  INT16_C(    19),  INT16_C(    26),  INT16_C(    23),  INT16_C(    31),  INT16_C(    15),  INT16_C(    23),  INT16_C(     2) },
      {        INT16_MIN,        INT16_MAX,        INT16_MAX,        INT16_MIN,        INT16_MAX,        INT16_MIN,        INT16_MIN, -INT16_C(     4) } },
    { { -INT16_C(   118), -INT16_C(   207), -INT16_C(  9170), -INT16_C(     1), -INT16_C(  3895), -INT16_C(  1763),  INT16_C(     3),  INT16_C(   433) },
      {  INT16_C(    28),  INT16_C(     4),  INT16_C(     9),  INT16_C(    29),  INT16_C(    16),  INT16_C(     5),  INT16_C(     8),  INT16_C(     8) },
      {        INT16_MIN, -INT16_C(  3312),        INT16_MIN,        INT16_MIN,        INT16_MIN,        INT16_MIN,  INT16_C(   768),        INT16_MAX } },
    { { -INT16_C(    87), -INT16_C(    18), -INT16_C( 10486),  INT16_C(  4851), -INT16_C(    11),  INT16_C(     3), -INT16_C(  1280),  INT16_C(  3461) },
      {  INT16_C(     4),  INT16_C(     9),  INT16_C(    24),  INT16_C(    19),  INT16_C(    29),  INT16_C(    10),  INT16_C(     1),  INT16_C(    17) },
      { -INT16_C(  1392), -INT16_C(  9216),        INT16_MIN,        INT16_MAX,        INT16_MIN,  INT16_C(  3072), -INT16_C(  2560),        INT16_MAX } },
    { {  INT16_C(   730),  INT16_C(     1), -INT16_C( 12470), -INT16_C(    20),  INT16_C(   295), -INT16_C(    23),  INT16_C(     0),  INT16_C(     0) },
      {  INT16_C(    29),  INT16_C(    28),  INT16_C(    16),  INT16_C(    17),  INT16_C(    19),  INT16_C(     7),  INT16_C(    30),  INT16_C(    24) },
      {        INT16_MAX,        INT16_MAX,        INT16_MIN,        INT16_MIN,        INT16_MAX, -INT16_C(  2944),  INT16_C(     0),  INT16_C(     0) } },
    { {  INT16_C(     0), -INT16_C( 19893), -INT16_C(     3),  INT16_C(  7951),  INT16_C(  1205),  INT16_C(     0),  INT16_C(    36),  INT16_C(   467) },
      {  INT16_C(    11),  INT16_C(    29),  INT16_C(    14),  INT16_C(    17),  INT16_C(    27),  INT16_C(    19),  INT16_C(    28),  INT16_C(    22) },
      {  INT16_C(     0),        INT16_MIN,        INT16_MIN,        INT16_MAX,        INT16_MAX,  INT16_C(     0),        INT16_MAX,        INT16_MAX } },
    { { -INT16_C(   742), -INT16_C(  3808), -INT16_C(   922), -INT16_C(   853),  INT16_C(     0),  INT16_C(    41),  INT16_C(     4),  INT16_C(  1304) },
      {  INT16_C(     7),  INT16_C(    30),  INT16_C(     5),  INT16_C(    12),  INT16_C(    18),  INT16_C(    11),  INT16_C(    28),  INT16_C(    16) },
      {        INT16_MIN,        INT16_MIN, -INT16_C( 29504),        INT16_MIN,  INT16_C(     0),        INT16_MAX,        INT16_MAX,        INT16_MAX } },
    { { -INT16_C( 19849),  INT16_C(     0),  INT16_C(     5),  INT16_C(    40),  INT16_C(   134),  INT16_C(   347), -INT16_C(   127), -INT16_C(  5510) },
      {  INT16_C(    16),  INT16_C(    25),  INT16_C(     0),  INT16_C(     1),  INT16_C(    19),  INT16_C(    26),  INT16_C(    26),  INT16_C(    17) },
      {        INT16_MIN,  INT16_C(     0),  INT16_C(     5),  INT16_C(    80),        INT16_MAX,        INT16_MAX,        INT16_MIN,        INT16_MIN } },
    { { -INT16_C(  8732), -INT16_C(  1904),  INT16_C(    45),  INT16_C(     6),  INT16_C(  5029), -INT16_C(    13), -INT16_C(  1208), -INT16_C(   990) },
      {  INT16_C(     5),  INT16_C(     4),  INT16_C(     4),  INT16_C(    12),  INT16_C(     2),  INT16_C(     3),  INT16_C(     1),  INT16_C(     0) },
      {        INT16_MIN, -INT16_C( 30464),  INT16_C(   720),  INT16_C( 24576),  INT16_C( 20116), -INT16_C(   104), -INT16_C(  2416), -INT16_C(   990) } },
    { { -INT16_C(  6325), -INT16_C(  4247), -INT16_C(  2590),  INT16_C( 25785),  INT16_C( 15814), -INT16_C( 14547),  INT16_C( 28195), -INT16_C( 15214) },
      { -INT16_C(  6472),  INT16_C(  3776), -INT16_C( 13869), -INT16_C( 11510), -INT16_C( 23090), -INT16_C( 16139), -INT16_C(  1711), -INT16_C( 25417) },
      { -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),        INT16_MAX,  INT16_C(     0), -INT16_C(     8),        INT16_MAX, -INT16_C(     1) } },
    { {  INT16_C(  8416), -INT16_C( 15476),  INT16_C( 17685), -INT16_C(  9177),  INT16_C( 21890), -INT16_C( 23133),  INT16_C( 13763),  INT16_C( 31594) },
      {  INT16_C( 10779), -INT16_C(  4470), -INT16_C( 27405), -INT16_C( 15934), -INT16_C( 18631), -INT16_C( 30079),  INT16_C( 14512), -INT16_C( 28378) },
      {        INT16_MAX, -INT16_C(     1),  INT16_C(     2), -INT16_C(     1),        INT16_MAX, -INT16_C(     1),  INT16_C(     0),        INT16_MAX } },
    { { -INT16_C( 19879),  INT16_C( 28244),  INT16_C( 31736),  INT16_C( 31306), -INT16_C(  4400), -INT16_C( 27872), -INT16_C( 30173),  INT16_C( 16143) },
      { -INT16_C( 26188), -INT16_C( 22739), -INT16_C(  4307),  INT16_C( 26216), -INT16_C(  5721),  INT16_C( 22512),  INT16_C(  5665),  INT16_C( 31464) },
      { -INT16_C(     1),        INT16_MAX,        INT16_MAX,        INT16_MAX, -INT16_C(     1), -INT16_C(     1),        INT16_MIN,  INT16_C(     0) } },
    { {  INT16_C( 15561), -INT16_C( 15895),  INT16_C( 13240), -INT16_C( 30661),  INT16_C( 23329),  INT16_C( 17692),  INT16_C( 11237), -INT16_C( 26236) },
      { -INT16_C( 20028), -INT16_C(  3776), -INT16_C( 22367),  INT16_C( 18519),  INT16_C( 18321), -INT16_C( 19553), -INT16_C( 30627),  INT16_C(  9773) },
      {  INT16_C(     0),        INT16_MIN,  INT16_C(     0),        INT16_MIN,  INT16_C(     0),  INT16_C(     0),        INT16_MAX,        INT16_MIN } },
    { {  INT16_C(  5828),  INT16_C( 31975),  INT16_C(  9034),  INT16_C( 27397),  INT16_C(  8574),  INT16_C( 25776),  INT16_C( 13388),  INT16_C(  4349) },
      {  INT16_C( 16102), -INT16_C( 30975),  INT16_C( 22758),  INT16_C( 30927),  INT16_C( 28319), -INT16_C(   981),  INT16_C( 22774), -INT16_C( 17629) },
      {  INT16_C(     0),        INT16_MAX,  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),        INT16_MAX,  INT16_C(    13),        INT16_MAX } },
    { {  INT16_C(  2671), -INT16_C( 18121),  INT16_C( 15405), -INT16_C( 21468), -INT16_C( 10915), -INT16_C( 22256),  INT16_C(  3337), -INT16_C(  4167) },
      { -INT16_C( 17845),  INT16_C( 12918),  INT16_C( 17682), -INT16_C( 20054), -INT16_C( 10828), -INT16_C( 21842), -INT16_C( 11987), -INT16_C( 25499) },
      {        INT16_MAX,        INT16_MIN,        INT16_MAX, -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),        INT16_MAX,        INT16_MIN } },
    { { -INT16_C( 25125),  INT16_C(  2389),  INT16_C( 31449),  INT16_C( 14261), -INT16_C( 15025),  INT16_C( 22752), -INT16_C( 25902),  INT16_C(  7752) },
      { -INT16_C( 16812),  INT16_C( 26448), -INT16_C(  1532), -INT16_C( 18408), -INT16_C( 14641), -INT16_C(   926), -INT16_C( 14185),  INT16_C( 29593) },
      {        INT16_MIN,        INT16_MAX,        INT16_MAX,        INT16_MAX, -INT16_C(     1),        INT16_MAX, -INT16_C(     1),  INT16_C(     0) } },
    { { -INT16_C(  4507),  INT16_C( 15996),  INT16_C( 12648), -INT16_C( 18571),  INT16_C( 22262), -INT16_C( 14320),  INT16_C( 22768),  INT16_C( 17638) },
      {  INT16_C( 13846),  INT16_C(  6827), -INT16_C( 15312), -INT16_C(    46),  INT16_C( 13706),  INT16_C(  8956), -INT16_C( 27139),  INT16_C( 25237) },
      {        INT16_MIN,  INT16_C(     0),        INT16_MAX, -INT16_C(     1),  INT16_C(     0), -INT16_C(   895),  INT16_C(  2846),  INT16_C(     0) } },
    { {  INT16_C(  4483), -INT16_C(  4960),  INT16_C(  5698),  INT16_C( 14499), -INT16_C( 19604),  INT16_C( 23552), -INT16_C(  6389),  INT16_C(  8864) },
      {  INT16_C( 19485),  INT16_C( 20028),  INT16_C(  3856), -INT16_C( 26035),  INT16_C( 18756),  INT16_C( 16828),  INT16_C( 20958),  INT16_C( 25251) },
      {        INT16_MAX,        INT16_MIN,        INT16_MAX,        INT16_MAX,        INT16_MIN,  INT16_C(     0), -INT16_C(     1),  INT16_C(     0) } },
    { {  INT16_C( 17250), -INT16_C( 23474), -INT16_C(  3751), -INT16_C( 14884), -INT16_C(  8795), -INT16_C( 20447), -INT16_C( 15676), -INT16_C(  7726) },
      {  INT16_C(  3854),  INT16_C(  7727),  INT16_C( 32030),  INT16_C( 25272),  INT16_C( 30150), -INT16_C( 23133),  INT16_C( 18118),  INT16_C( 10503) },
      {        INT16_MAX,        INT16_MIN,        INT16_MIN, -INT16_C(     1), -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),        INT16_MIN } },
    { {  INT16_C( 21897), -INT16_C(  7219), -INT16_C( 21946), -INT16_C(  5208), -INT16_C( 13689),  INT16_C( 19356),  INT16_C( 28300), -INT16_C( 26068) },
      {  INT16_C( 23677), -INT16_C( 25672),  INT16_C( 28889), -INT16_C( 24579), -INT16_C( 24347), -INT16_C( 21436),  INT16_C( 19430),  INT16_C( 28885) },
      {        INT16_MAX, -INT16_C(     1), -INT16_C(     1), -INT16_C(   651), -INT16_C(     1),        INT16_MAX,  INT16_C(     0), -INT16_C(     1) } },
    { { -INT16_C( 23904), -INT16_C(  6317), -INT16_C(  1204), -INT16_C( 11310),  INT16_C( 28357),  INT16_C( 20766),  INT16_C( 19421),  INT16_C( 23275) },
      { -INT16_C( 23641), -INT16_C( 32522), -INT16_C(  3308), -INT16_C(  1761),  INT16_C( 25748),  INT16_C( 31397),  INT16_C( 31407),  INT16_C( 20714) },
      { -INT16_C(     1), -INT16_C(     7),        INT16_MIN,        INT16_MIN,  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0) } },
    { {  INT16_C( 15645),  INT16_C( 26935),  INT16_C(  2361), -INT16_C(   451),  INT16_C( 23416),  INT16_C( 21840),  INT16_C( 15270),  INT16_C( 19887) },
      { -INT16_C( 23073), -INT16_C(  3123), -INT16_C(  4711),  INT16_C( 11756), -INT16_C( 28079),  INT16_C(   167), -INT16_C( 28148),  INT16_C( 10576) },
      {  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(     1),        INT16_MAX,  INT16_C(     0),        INT16_MAX,        INT16_MAX } },
    { { -INT16_C( 30769),  INT16_C(  2195), -INT16_C( 12143),  INT16_C(  2311),  INT16_C( 22315), -INT16_C( 11682),  INT16_C(  3474),  INT16_C( 28959) },
      { -INT16_C(  4685),  INT16_C( 19556),  INT16_C( 20954),  INT16_C( 11129),  INT16_C(  8419), -INT16_C(  4309),  INT16_C( 31922), -INT16_C( 32231) },
      { -INT16_C(     1),        INT16_MAX, -INT16_C(     1),        INT16_MAX,  INT16_C(     0),        INT16_MIN,  INT16_C(     0),        INT16_MAX } },
    { { -INT16_C( 21501), -INT16_C( 27510), -INT16_C( 28292), -INT16_C( 22627), -INT16_C(  1048),  INT16_C( 31609), -INT16_C( 26359), -INT16_C( 17172) },
      {  INT16_C( 20870),  INT16_C( 24584), -INT16_C( 32350), -INT16_C( 31349), -INT16_C( 18783),  INT16_C( 21620), -INT16_C( 29390),  INT16_C( 14038) },
      { -INT16_C(     1),        INT16_MIN, -INT16_C(     1), -INT16_C(     1), -INT16_C(     1),        INT16_MAX,        INT16_MIN, -INT16_C(     1) } },
    { {  INT16_C( 24633), -INT16_C( 18998),  INT16_C( 26866), -INT16_C(  9635), -INT16_C( 10653),  INT16_C( 27733),  INT16_C( 17007), -INT16_C(  2776) },
      {  INT16_C( 12435),  INT16_C( 13653), -INT16_C(  8015),  INT16_C( 21434),  INT16_C( 11927), -INT16_C( 13913),  INT16_C( 32188), -INT16_C(  2561) },
      {  INT16_C(     0),        INT16_MIN,  INT16_C(     0), -INT16_C(     1), -INT16_C(     1),  INT16_C(     0),  INT16_C(     0), -INT16_C(  1388) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x8_t a = simde_vld1q_s16(test_vec[i].a);
    simde_int16x8_t b = simde_vld1q_s16(test_vec[i].b);
    simde_int16x8_t r = simde_vqshlq_s16(a, b);

    simde_test_arm_neon_assert_equal_i16x8(r, simde_vld1q_s16(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 16 ; i++) {
    simde_int16x8_t a = simde_test_arm_neon_random_i16x8();
    simde_int16x8_t b = simde_test_arm_neon_random_i16x8();

    a = simde_vshlq_s16(a, simde_vnegq_s16(simde_vandq_s16(simde_test_arm_neon_random_i16x8(), simde_vdupq_n_s16(15))));
    b = simde_vandq_s16(b, simde_vdupq_n_s16(31));

    simde_int16x8_t r = simde_vqshlq_s16(a, b);

    simde_test_arm_neon_write_i16x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i16x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i16x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  for (int i = 0 ; i < 16 ; i++) {
    simde_int16x8_t a = simde_test_arm_neon_random_i16x8();
    simde_int16x8_t b = simde_test_arm_neon_random_i16x8();

    simde_int16x8_t r = simde_vqshlq_s16(a, b);

    simde_test_arm_neon_write_i16x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i16x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i16x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vqshlq_s32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int32_t a[4];
    int32_t b[4];
    int32_t r[4];
  } test_vec[] = {
    { {  INT32_C(           8),  INT32_C(         384), -INT32_C(        3674),  INT32_C(       17330) },
      {  INT32_C(           7),  INT32_C(          27),  INT32_C(          59),  INT32_C(          53) },
      {  INT32_C(        1024),              INT32_MAX,              INT32_MIN,              INT32_MAX } },
    { {  INT32_C(   462070733), -INT32_C(           3), -INT32_C(          58),  INT32_C(     1645042) },
      {  INT32_C(          40),  INT32_C(          43),  INT32_C(          14),  INT32_C(          58) },
      {              INT32_MAX,              INT32_MIN, -INT32_C(      950272),              INT32_MAX } },
    { {  INT32_C(         480), -INT32_C(      103154), -INT32_C(           1),  INT32_C(      260443) },
      {  INT32_C(          60),  INT32_C(          39),  INT32_C(           0),  INT32_C(          51) },
      {              INT32_MAX,              INT32_MIN, -INT32_C(           1),              INT32_MAX } },
    { { -INT32_C(           1),  INT32_C(      392928), -INT32_C(          87), -INT32_C(       17482) },
      {  INT32_C(          21),  INT32_C(           7),  INT32_C(          12),  INT32_C(          35) },
      { -INT32_C(     2097152),  INT32_C(    50294784), -INT32_C(      356352),              INT32_MIN } },
    { { -INT32_C(     2686569), -INT32_C(           1),  INT32_C(           1),  INT32_C(           0) },
      {  INT32_C(           5),  INT32_C(          26),  INT32_C(          24),  INT32_C(          28) },
      { -INT32_C(    85970208), -INT32_C(    67108864),  INT32_C(    16777216),  INT32_C(           0) } },
    { { -INT32_C(      682320), -INT32_C(          13),  INT32_C(        3622), -INT32_C(           2) },
      {  INT32_C(          43),  INT32_C(           3),  INT32_C(          56),  INT32_C(          55) },
      {              INT32_MIN, -INT32_C(         104),              INT32_MAX,              INT32_MIN } },
    { { -INT32_C(  1187761675),  INT32_C(           0), -INT32_C(       49280), -INT32_C(         414) },
      {  INT32_C(          43),  INT32_C(          17),  INT32_C(          52),  INT32_C(          50) },
      {              INT32_MIN,  INT32_C(           0),              INT32_MIN,              INT32_MIN } },
    { {  INT32_C(    15218116), -INT32_C(   203173291),  INT32_C(   129391777),  INT32_C(       29541) },
      {  INT32_C(          31),  INT32_C(           1),  INT32_C(          23),  INT32_C(          54) },
      {              INT32_MAX, -INT32_C(   406346582),              INT32_MAX,              INT32_MAX } },
    { {  INT32_C(   118604238),  INT32_C(           1),  INT32_C(          35), -INT32_C(           5) },
      {  INT32_C(          43),  INT32_C(          50),  INT32_C(          56),  INT32_C(          59) },
      {              INT32_MAX,              INT32_MAX,              INT32_MAX,              INT32_MIN } },
    { { -INT32_C(       88632),  INT32_C(          83), -INT32_C(     1747144), -INT32_C(     5041878) },
      {  INT32_C(          28),  INT32_C(          37),  INT32_C(          57),  INT32_C(           8) },
      {              INT32_MIN,              INT32_MAX,              INT32_MIN, -INT32_C(  1290720768) } },
    { {  INT32_C(         518),  INT32_C(    54283327),  INT32_C(           1), -INT32_C(           1) },
      {  INT32_C(          35),  INT32_C(          16),  INT32_C(          60),  INT32_C(           6) },
      {              INT32_MAX,              INT32_MAX,              INT32_MAX, -INT32_C(          64) } },
    { { -INT32_C(       18625),  INT32_C(       56902),  INT32_C(     4864522),  INT32_C(           0) },
      {  INT32_C(          35),  INT32_C(          26),  INT32_C(          63),  INT32_C(          14) },
      {              INT32_MIN,              INT32_MAX,              INT32_MAX,  INT32_C(           0) } },
    { { -INT32_C(       12376),  INT32_C(       18855),  INT32_C(       17169),  INT32_C(         229) },
      {  INT32_C(          11),  INT32_C(           1),  INT32_C(           2),  INT32_C(          26) },
      { -INT32_C(    25346048),  INT32_C(       37710),  INT32_C(       68676),              INT32_MAX } },
    { {  INT32_C(       66529),  INT32_C(       63908),  INT32_C(    52940252),  INT32_C(     9451267) },
      {  INT32_C(          12),  INT32_C(          62),  INT32_C(          49),  INT32_C(          33) },
      {  INT32_C(   272502784),              INT32_MAX,              INT32_MAX,              INT32_MAX } },
    { { -INT32_C(     2149916), -INT32_C(      205973), -INT32_C(         414), -INT32_C(           3) },
      {  INT32_C(          51),  INT32_C(           6),  INT32_C(          47),  INT32_C(          54) },
      {              INT32_MIN, -INT32_C(    13182272),              INT32_MIN,              INT32_MIN } },
    { { -INT32_C(         655),  INT32_C(      866276), -INT32_C(           7),  INT32_C(       39517) },
      {  INT32_C(          49),  INT32_C(           6),  INT32_C(          26),  INT32_C(          20) },
      {              INT32_MIN,  INT32_C(    55441664), -INT32_C(   469762048),              INT32_MAX } },
    { {  INT32_C(  1002343861),  INT32_C(   852951064),  INT32_C(  1403647102),  INT32_C(  1094250604) },
      {  INT32_C(   853275975),  INT32_C(   226404752),  INT32_C(  1387159971),  INT32_C(   678600051) },
      {              INT32_MAX,  INT32_C(           0),  INT32_C(           0),              INT32_MAX } },
    { {  INT32_C(  1113796650), -INT32_C(  1368114640), -INT32_C(  1694425554),  INT32_C(  1440496142) },
      { -INT32_C(  1081624785),  INT32_C(    63702368), -INT32_C(   631932057),  INT32_C(  1107478296) },
      {              INT32_MAX,              INT32_MIN,              INT32_MIN,              INT32_MAX } },
    { {  INT32_C(   662988279), -INT32_C(   841549665),  INT32_C(   610850582),  INT32_C(  1081754641) },
      {  INT32_C(  1543504379),  INT32_C(  1851771911),  INT32_C(  1598600519),  INT32_C(  1956727420) },
      {  INT32_C(    20718383),              INT32_MIN,              INT32_MAX,              INT32_MAX } },
    { {  INT32_C(  1318790575),  INT32_C(   874213662),  INT32_C(  1515816009), -INT32_C(   996420664) },
      { -INT32_C(   618619948), -INT32_C(  1354137753), -INT32_C(  1324445388), -INT32_C(  1977241381) },
      {  INT32_C(           0),              INT32_MAX,              INT32_MAX, -INT32_C(           1) } },
    { { -INT32_C(   203898667),  INT32_C(  2066281522),  INT32_C(  1087734136),  INT32_C(   671379540) },
      {  INT32_C(  1929651211), -INT32_C(   668840540), -INT32_C(  1165414177), -INT32_C(  1236947232) },
      {              INT32_MIN,  INT32_C(           0),  INT32_C(           0),  INT32_C(           0) } },
    { { -INT32_C(  1582752401), -INT32_C(  1994600175), -INT32_C(  1496649390),  INT32_C(  1842335330) },
      { -INT32_C(  1746873357), -INT32_C(     9502176),  INT32_C(   331020595),  INT32_C(   382336935) },
      { -INT32_C(      193208),              INT32_MIN,              INT32_MIN,  INT32_C(           0) } },
    { {  INT32_C(   783774492), -INT32_C(  1749560508),  INT32_C(   658342341),  INT32_C(  1133775952) },
      {  INT32_C(    14317023), -INT32_C(  1426110089), -INT32_C(   356599486), -INT32_C(   721385544) },
      {  INT32_C(           0),              INT32_MIN,              INT32_MAX,  INT32_C(           0) } },
    { {  INT32_C(  1057208570),  INT32_C(  1356249739), -INT32_C(  1938353348), -INT32_C(     3208160) },
      { -INT32_C(   117462655),  INT32_C(   899940338),  INT32_C(  1897882040), -INT32_C(   481943576) },
      {  INT32_C(           0),  INT32_C(       82778), -INT32_C(           1), -INT32_C(           1) } },
    { {  INT32_C(  1663191511),  INT32_C(  1068759043),  INT32_C(   734735115), -INT32_C(  1205102025) },
      {  INT32_C(   917514819), -INT32_C(   496282839), -INT32_C(  1655469388), -INT32_C(  2122278487) },
      {              INT32_MAX,              INT32_MAX,  INT32_C(           0), -INT32_C(           1) } },
    { { -INT32_C(   438000926), -INT32_C(  1524263014), -INT32_C(   103681854), -INT32_C(   827196277) },
      {  INT32_C(  1342464550),  INT32_C(  1781690293), -INT32_C(  1559788039),  INT32_C(     2393886) },
      {              INT32_MIN, -INT32_C(           1), -INT32_C(      810015),              INT32_MIN } },
    { { -INT32_C(  1008400343),  INT32_C(  1650985631), -INT32_C(  2040841733),  INT32_C(  1549012277) },
      {  INT32_C(   615274863), -INT32_C(  1030824248), -INT32_C(  2124049053),  INT32_C(  1166117148) },
      {              INT32_MIN,  INT32_C(           0),              INT32_MIN,              INT32_MAX } },
    { {  INT32_C(   805856913),  INT32_C(  1821536625), -INT32_C(   520950102),  INT32_C(  1782335227) },
      {  INT32_C(  1754196127),  INT32_C(   690625990), -INT32_C(   810905678), -INT32_C(  1458296040) },
      {  INT32_C(           0),  INT32_C(           0), -INT32_C(           1),              INT32_MAX } },
    { {  INT32_C(    47783313),  INT32_C(   946760846),  INT32_C(  1427660890),  INT32_C(  1186944167) },
      {  INT32_C(    44977468),  INT32_C(   489412714),  INT32_C(  2146227559), -INT32_C(  1842872320) },
      {              INT32_MAX,              INT32_MAX,              INT32_MAX,  INT32_C(  1186944167) } },
    { { -INT32_C(  1416363491), -INT32_C(   924581010),  INT32_C(   169737315), -INT32_C(  1924015023) },
      { -INT32_C(  1802436823),  INT32_C(  1068612568), -INT32_C(  1849713263), -INT32_C(  1155274851) },
      {              INT32_MIN, -INT32_C(           1),  INT32_C(           0), -INT32_C(           1) } },
    { {  INT32_C(  1466349801),  INT32_C(   505367227), -INT32_C(  1742128057),  INT32_C(  1109752344) },
      {  INT32_C(  1373025657),  INT32_C(    43091825), -INT32_C(  1047310300),  INT32_C(   561821495) },
      {              INT32_MAX,              INT32_MAX,              INT32_MIN,              INT32_MAX } },
    { {  INT32_C(   712565615),  INT32_C(  1950914605), -INT32_C(   317951532),  INT32_C(  1697592043) },
      {  INT32_C(  1488324071), -INT32_C(  1336260724), -INT32_C(   814616937),  INT32_C(   351334053) },
      {  INT32_C(          21),  INT32_C(           0), -INT32_C(           1),  INT32_C(           0) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x4_t a = simde_vld1q_s32(test_vec[i].a);
    simde_int32x4_t b = simde_vld1q_s32(test_vec[i].b);
    simde_int32x4_t r = simde_vqshlq_s32(a, b);

    simde_test_arm_neon_assert_equal_i32x4(r, simde_vld1q_s32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 16 ; i++) {
    simde_int32x4_t a = simde_test_arm_neon_random_i32x4();
    simde_int32x4_t b = simde_test_arm_neon_random_i32x4();

    a = simde_vshlq_s32(a, simde_vnegq_s32(simde_vandq_s32(simde_test_arm_neon_random_i32x4(), simde_vdupq_n_s32(31))));
    b = simde_vandq_s32(b, simde_vdupq_n_s32(63));

    simde_int32x4_t r = simde_vqshlq_s32(a, b);

    simde_test_arm_neon_write_i32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  for (int i = 0 ; i < 16 ; i++) {
    simde_int32x4_t a = simde_test_arm_neon_random_i32x4();
    simde_int32x4_t b = simde_test_arm_neon_random_i32x4();

    simde_int32x4_t r = simde_vqshlq_s32(a, b);

    simde_test_arm_neon_write_i32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vqshlq_s64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int64_t a[2];
    int64_t b[2];
    int64_t r[2];
  } test_vec[] = {
    { { -INT64_C(               23807),  INT64_C(            93622130) },
      {  INT64_C(                  61),  INT64_C(                  29) },
      {                      INT64_MIN,  INT64_C(   50262998316482560) } },
    { { -INT64_C(      20333988516515),  INT64_C(     242085261526482) },
      {  INT64_C(                  30),  INT64_C(                  11) },
      {                      INT64_MIN,  INT64_C(  495790615606235136) } },
    { { -INT64_C(      14286080864952), -INT64_C(             1262618) },
      {  INT64_C(                  35),  INT64_C(                  10) },
      {                      INT64_MIN, -INT64_C(          1292920832) } },
    { { -INT64_C(                7362), -INT64_C(               53410) },
      {  INT64_C(                  37),  INT64_C(                  61) },
      { -INT64_C(    1011825575460864),                      INT64_MIN } },
    { {  INT64_C(    2661045400278874),  INT64_C(          1552491388) },
      {  INT64_C(                  16),  INT64_C(                  57) },
      {                      INT64_MAX,                      INT64_MAX } },
    { { -INT64_C(    2191344494207376),  INT64_C(                  64) },
      {  INT64_C(                  54),  INT64_C(                  27) },
      {                      INT64_MIN,  INT64_C(          8589934592) } },
    { {  INT64_C(  312486730496188944), -INT64_C(               20250) },
      {  INT64_C(                  40),  INT64_C(                  56) },
      {                      INT64_MAX,                      INT64_MIN } },
    { { -INT64_C(                 346), -INT64_C(                   5) },
      {  INT64_C(                  32),  INT64_C(                  16) },
      { -INT64_C(       1486058684416), -INT64_C(              327680) } },
    { { -INT64_C(              128382),  INT64_C(   32230240374868328) },
      {  INT64_C(                   9),  INT64_C(                  16) },
      { -INT64_C(            65731584),                      INT64_MAX } },
    { { -INT64_C(                   7), -INT64_C(         15668510970) },
      {  INT64_C(                   6),  INT64_C(                  62) },
      { -INT64_C(                 448),                      INT64_MIN } },
    { {  INT64_C(    7839476773962599),  INT64_C(         13290256696) },
      {  INT64_C(                  41),  INT64_C(                  49) },
      {                      INT64_MAX,                      INT64_MAX } },
    { { -INT64_C(                6359), -INT64_C(  783415933684492636) },
      {  INT64_C(                  44),  INT64_C(                  34) },
      { -INT64_C(  111868711056441344),                      INT64_MIN } },
    { { -INT64_C(               14859), -INT64_C(                   4) },
      {  INT64_C(                  55),  INT64_C(                  27) },
      {                      INT64_MIN, -INT64_C(           536870912) } },
    { { -INT64_C(                   6), -INT64_C(                   5) },
      {  INT64_C(                  56),  INT64_C(                  11) },
      { -INT64_C(  432345564227567616), -INT64_C(               10240) } },
    { { -INT64_C(                2390),  INT64_C(               74712) },
      {  INT64_C(                  62),  INT64_C(                  57) },
      {                      INT64_MIN,                      INT64_MAX } },
    { { -INT64_C(              312217), -INT64_C(         21098713438) },
      {  INT64_C(                  30),  INT64_C(                  17) },
      { -INT64_C(     335240451063808), -INT64_C(    2765450567745536) } },
    { { -INT64_C(  330084479043502892), -INT64_C( 3292373330402441427) },
      { -INT64_C( 4725028448840902445),  INT64_C( 4698804091963345645) },
      { -INT64_C(                9382), -INT64_C(       6279703770452) } },
    { {  INT64_C( 7810073256971072125), -INT64_C( 4812920928398620804) },
      { -INT64_C( 5868149899598074327),  INT64_C( 3340551281836044462) },
      {                      INT64_MAX, -INT64_C(                   1) } },
    { {  INT64_C( 6243107124567992055), -INT64_C( 6960332509951728449) },
      { -INT64_C( 1095781804667822756), -INT64_C( 7417032066811061199) },
      {                      INT64_MAX,                      INT64_MIN } },
    { {  INT64_C( 6737229591184647758), -INT64_C( 9012989118488561449) },
      { -INT64_C( 8233307596944089973),  INT64_C( 9097694768249489414) },
      {  INT64_C(                   0),                      INT64_MIN } },
    { {  INT64_C( 6495077435013795879),  INT64_C( 2595923418983836254) },
      {  INT64_C( 1646257044509009390), -INT64_C( 1142225688900777866) },
      {  INT64_C(      24776754131369),                      INT64_MAX } },
    { {  INT64_C( 5831276352916343823),  INT64_C( 1423658812322386692) },
      { -INT64_C( 2979916889597300097),  INT64_C( 8158168892489687933) },
      {                      INT64_MAX,                      INT64_MAX } },
    { { -INT64_C( 3696627604984107665), -INT64_C( 2181102995605190781) },
      { -INT64_C( 3741904914625848868), -INT64_C( 6752222729261117320) },
      { -INT64_C(            53793012),                      INT64_MIN } },
    { { -INT64_C( 4338453801250566345),  INT64_C( 4143354940240966462) },
      {  INT64_C( 9032963035084746816), -INT64_C( 1230147115563913960) },
      {                      INT64_MIN,                      INT64_MAX } },
    { { -INT64_C( 1731995069345631502), -INT64_C( 3854791519843753238) },
      { -INT64_C( 7531508965019355145),  INT64_C( 7477892336352154145) },
      { -INT64_C(    3382802869815687),                      INT64_MIN } },
    { {  INT64_C( 6075796159028966337), -INT64_C( 3006963230999521038) },
      {  INT64_C( 8370870448989380117), -INT64_C( 6990690683467330272) },
      {                      INT64_MAX,                      INT64_MIN } },
    { {  INT64_C( 1766636073897203398),  INT64_C( 6118097483707195698) },
      {  INT64_C( 2971833736890989432),  INT64_C( 7249311742214179616) },
      {                      INT64_MAX,                      INT64_MAX } },
    { {  INT64_C( 3427266793340969809),  INT64_C( 8488203367284220985) },
      { -INT64_C( 1795670954303507230), -INT64_C( 2446722825673453047) },
      {  INT64_C(          3191890933),                      INT64_MAX } },
    { { -INT64_C( 1058937758416527583), -INT64_C( 7531084325728908023) },
      {  INT64_C( 4943429823646383339),  INT64_C( 2221954657040498282) },
      { -INT64_C(        504940871438),                      INT64_MIN } },
    { {  INT64_C( 1819606052111133335), -INT64_C( 3718673799183291881) },
      { -INT64_C( 1668275255027767463),  INT64_C( 6030800098053571990) },
      {                      INT64_MAX, -INT64_C(                   1) } },
    { { -INT64_C( 8140006222211125793),  INT64_C( 2250321822800882061) },
      {  INT64_C( 7497804884062026150), -INT64_C( 9195597681396028078) },
      { -INT64_C(                   1),                      INT64_MAX } },
    { {  INT64_C( 8475907432536540313),  INT64_C( 7027338058808949665) },
      {  INT64_C( 1806107035822340823),  INT64_C( 5882698057432697729) },
      {  INT64_C(             3854396),  INT64_C(                   0) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int64x2_t a = simde_vld1q_s64(test_vec[i].a);
    simde_int64x2_t b = simde_vld1q_s64(test_vec[i].b);
    simde_int64x2_t r = simde_vqshlq_s64(a, b);

    simde_test_arm_neon_assert_equal_i64x2(r, simde_vld1q_s64(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 16 ; i++) {
    simde_int64x2_t a = simde_test_arm_neon_random_i64x2();
    simde_int64x2_t b = simde_test_arm_neon_random_i64x2();

    a = simde_vshlq_s64(a, simde_vnegq_s64(simde_vandq_s64(simde_test_arm_neon_random_i64x2(), simde_vdupq_n_s64(63))));
    b = simde_vandq_s64(b, simde_vdupq_n_s64(63));

    simde_int64x2_t r = simde_vqshlq_s64(a, b);

    simde_test_arm_neon_write_i64x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i64x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  for (int i = 0 ; i < 16 ; i++) {
    simde_int64x2_t a = simde_test_arm_neon_random_i64x2();
    simde_int64x2_t b = simde_test_arm_neon_random_i64x2();

    simde_int64x2_t r = simde_vqshlq_s64(a, b);

    simde_test_arm_neon_write_i64x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i64x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vqshlq_u8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint8_t a[16];
    int8_t b[16];
    uint8_t r[16];
  } test_vec[] = {
    { { UINT8_C( 11), UINT8_C( 22), UINT8_C( 81), UINT8_C( 20), UINT8_C(102), UINT8_C(  4), UINT8_C( 33), UINT8_C( 45),
        UINT8_C( 24), UINT8_C(  2), UINT8_C( 10), UINT8_C(  2), UINT8_C(  0), UINT8_C( 16), UINT8_C( 20), UINT8_C(220) },
      {  INT8_C(   1),  INT8_C(   2),  INT8_C(  14),  INT8_C(   8),  INT8_C(  14),  INT8_C(   0),  INT8_C(   6),  INT8_C(   6),
         INT8_C(  14),  INT8_C(   1),  INT8_C(  15),  INT8_C(   4),  INT8_C(   6),  INT8_C(  14),  INT8_C(   2),  INT8_C(   4) },
      { UINT8_C( 22), UINT8_C( 88),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  4),    UINT8_MAX,    UINT8_MAX,
           UINT8_MAX, UINT8_C(  4),    UINT8_MAX, UINT8_C( 32), UINT8_C(  0),    UINT8_MAX, UINT8_C( 80),    UINT8_MAX } },
    { { UINT8_C(  4), UINT8_C(153), UINT8_C( 23), UINT8_C(  3), UINT8_C(  1), UINT8_C(  0), UINT8_C(  2), UINT8_C(119),
        UINT8_C( 16), UINT8_C( 37), UINT8_C(  1), UINT8_C( 11), UINT8_C(  1), UINT8_C( 63), UINT8_C(  3), UINT8_C(  1) },
      {  INT8_C(   0),  INT8_C(   3),  INT8_C(   8),  INT8_C(   8),  INT8_C(   1),  INT8_C(  10),  INT8_C(   3),  INT8_C(   3),
         INT8_C(   7),  INT8_C(   5),  INT8_C(   1),  INT8_C(   6),  INT8_C(   9),  INT8_C(  12),  INT8_C(   7),  INT8_C(  15) },
      { UINT8_C(  4),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  2), UINT8_C(  0), UINT8_C( 16),    UINT8_MAX,
           UINT8_MAX,    UINT8_MAX, UINT8_C(  2),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX } },
    { { UINT8_C(198), UINT8_C( 61), UINT8_C( 27), UINT8_C(247), UINT8_C(  7), UINT8_C(  1), UINT8_C( 90), UINT8_C(  2),
        UINT8_C( 80), UINT8_C(  1), UINT8_C(  1), UINT8_C(108), UINT8_C( 11), UINT8_C(  0), UINT8_C(  2), UINT8_C(  3) },
      {  INT8_C(   5),  INT8_C(  12),  INT8_C(  12),  INT8_C(   5),  INT8_C(  10),  INT8_C(   2),  INT8_C(   5),  INT8_C(   3),
         INT8_C(   3),  INT8_C(  12),  INT8_C(   4),  INT8_C(   2),  INT8_C(  14),  INT8_C(   2),  INT8_C(   2),  INT8_C(   4) },
      {    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  4),    UINT8_MAX, UINT8_C( 16),
           UINT8_MAX,    UINT8_MAX, UINT8_C( 16),    UINT8_MAX,    UINT8_MAX, UINT8_C(  0), UINT8_C(  8), UINT8_C( 48) } },
    { { UINT8_C(  0), UINT8_C(  4), UINT8_C( 39), UINT8_C(  1), UINT8_C(100), UINT8_C( 13), UINT8_C(  8), UINT8_C(248),
        UINT8_C(  1), UINT8_C(  3), UINT8_C(  1), UINT8_C(  3), UINT8_C( 49), UINT8_C(  3), UINT8_C(  5), UINT8_C( 87) },
      {  INT8_C(   6),  INT8_C(  14),  INT8_C(   7),  INT8_C(  11),  INT8_C(   4),  INT8_C(   8),  INT8_C(   1),  INT8_C(   5),
         INT8_C(   7),  INT8_C(   0),  INT8_C(  14),  INT8_C(  11),  INT8_C(   7),  INT8_C(   4),  INT8_C(   5),  INT8_C(  11) },
      { UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C( 16),    UINT8_MAX,
        UINT8_C(128), UINT8_C(  3),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C( 48), UINT8_C(160),    UINT8_MAX } },
    { { UINT8_C( 68), UINT8_C(252), UINT8_C( 28), UINT8_C(  0), UINT8_C(  4), UINT8_C(110), UINT8_C(104), UINT8_C( 25),
        UINT8_C( 22), UINT8_C( 95), UINT8_C( 55), UINT8_C(  5), UINT8_C(  6), UINT8_C(156), UINT8_C(144), UINT8_C(  2) },
      {  INT8_C(   1),  INT8_C(   9),  INT8_C(   6),  INT8_C(   9),  INT8_C(   3),  INT8_C(  10),  INT8_C(   2),  INT8_C(   2),
         INT8_C(   8),  INT8_C(   9),  INT8_C(   8),  INT8_C(   2),  INT8_C(   3),  INT8_C(  13),  INT8_C(   3),  INT8_C(  11) },
      { UINT8_C(136),    UINT8_MAX,    UINT8_MAX, UINT8_C(  0), UINT8_C( 32),    UINT8_MAX,    UINT8_MAX, UINT8_C(100),
           UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C( 20), UINT8_C( 48),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX } },
    { { UINT8_C(  1), UINT8_C(  0), UINT8_C( 13), UINT8_C(  1), UINT8_C(  8), UINT8_C( 46), UINT8_C(110), UINT8_C( 26),
        UINT8_C( 18), UINT8_C(  2), UINT8_C(179), UINT8_C( 16), UINT8_C( 33), UINT8_C( 83), UINT8_C(  1), UINT8_C(108) },
      {  INT8_C(   6),  INT8_C(   9),  INT8_C(  10),  INT8_C(   4),  INT8_C(   2),  INT8_C(   4),  INT8_C(  15),  INT8_C(  11),
         INT8_C(   4),  INT8_C(  15),  INT8_C(   8),  INT8_C(   1),  INT8_C(  15),  INT8_C(   0),  INT8_C(  15),  INT8_C(   8) },
      { UINT8_C( 64), UINT8_C(  0),    UINT8_MAX, UINT8_C( 16), UINT8_C( 32),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,
           UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C( 32),    UINT8_MAX, UINT8_C( 83),    UINT8_MAX,    UINT8_MAX } },
    { { UINT8_C( 14), UINT8_C(146), UINT8_C(  0), UINT8_C(122), UINT8_C(  4), UINT8_C( 43), UINT8_C( 12), UINT8_C(  3),
        UINT8_C( 85), UINT8_C(169), UINT8_C(  3), UINT8_C( 30), UINT8_C(  7), UINT8_C(  0), UINT8_C(  4), UINT8_C(  0) },
      {  INT8_C(   2),  INT8_C(   5),  INT8_C(   0),  INT8_C(   3),  INT8_C(   7),  INT8_C(   8),  INT8_C(   6),  INT8_C(  15),
         INT8_C(   3),  INT8_C(  14),  INT8_C(  10),  INT8_C(   4),  INT8_C(   8),  INT8_C(   1),  INT8_C(  12),  INT8_C(  10) },
      { UINT8_C( 56),    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,
           UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  0) } },
    { { UINT8_C( 30), UINT8_C( 13), UINT8_C(  3), UINT8_C(  5), UINT8_C(211), UINT8_C( 75), UINT8_C( 12), UINT8_C(  3),
        UINT8_C(  5), UINT8_C(  1), UINT8_C(  5), UINT8_C( 21), UINT8_C( 15), UINT8_C(  4), UINT8_C(  0), UINT8_C( 14) },
      {  INT8_C(  15),  INT8_C(   7),  INT8_C(  11),  INT8_C(   3),  INT8_C(   7),  INT8_C(  15),  INT8_C(   0),  INT8_C(   0),
         INT8_C(  15),  INT8_C(   7),  INT8_C(   3),  INT8_C(  10),  INT8_C(  14),  INT8_C(  14),  INT8_C(   8),  INT8_C(  11) },
      {    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C( 40),    UINT8_MAX,    UINT8_MAX, UINT8_C( 12), UINT8_C(  3),
           UINT8_MAX, UINT8_C(128), UINT8_C( 40),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX } },
    { { UINT8_C(  7), UINT8_C(  4), UINT8_C(  3), UINT8_C(  1), UINT8_C( 21), UINT8_C(198), UINT8_C( 53), UINT8_C(230),
        UINT8_C(  3), UINT8_C( 51), UINT8_C(  2), UINT8_C( 51), UINT8_C(  9), UINT8_C(  7), UINT8_C(  1), UINT8_C(  7) },
      {  INT8_C(   2),  INT8_C(   5),  INT8_C(   1),  INT8_C(   3),  INT8_C(   6),  INT8_C(   3),  INT8_C(   9),  INT8_C(   4),
         INT8_C(  15),  INT8_C(  12),  INT8_C(  15),  INT8_C(   3),  INT8_C(   8),  INT8_C(  12),  INT8_C(   6),  INT8_C(  11) },
      { UINT8_C( 28), UINT8_C(128), UINT8_C(  6), UINT8_C(  8),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,
           UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C( 64),    UINT8_MAX } },
    { { UINT8_C(120), UINT8_C( 30), UINT8_C( 80), UINT8_C( 19), UINT8_C(  5), UINT8_C(  7), UINT8_C(  2), UINT8_C( 28),
        UINT8_C(  0), UINT8_C( 13), UINT8_C(107), UINT8_C(  7), UINT8_C(207), UINT8_C(  3), UINT8_C( 12), UINT8_C( 19) },
      {  INT8_C(   8),  INT8_C(  14),  INT8_C(  15),  INT8_C(  10),  INT8_C(  15),  INT8_C(   0),  INT8_C(  10),  INT8_C(  13),
         INT8_C(   2),  INT8_C(   6),  INT8_C(   8),  INT8_C(  13),  INT8_C(   9),  INT8_C(   7),  INT8_C(  11),  INT8_C(   2) },
      {    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  7),    UINT8_MAX,    UINT8_MAX,
        UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C( 76) } },
    { { UINT8_C( 40), UINT8_C(  0), UINT8_C( 48), UINT8_C( 15), UINT8_C(  9), UINT8_C(  0), UINT8_C(  4), UINT8_C(107),
        UINT8_C(  6), UINT8_C(  5), UINT8_C(  0), UINT8_C(189), UINT8_C( 54), UINT8_C(  6), UINT8_C(  4), UINT8_C( 20) },
      {  INT8_C(  15),  INT8_C(   0),  INT8_C(   0),  INT8_C(   4),  INT8_C(   4),  INT8_C(  14),  INT8_C(  15),  INT8_C(  11),
         INT8_C(   3),  INT8_C(   8),  INT8_C(   0),  INT8_C(   3),  INT8_C(  10),  INT8_C(   9),  INT8_C(  12),  INT8_C(  10) },
      {    UINT8_MAX, UINT8_C(  0), UINT8_C( 48), UINT8_C(240), UINT8_C(144), UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,
        UINT8_C( 48),    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX } },
    { { UINT8_C(  1), UINT8_C( 31), UINT8_C(  1), UINT8_C( 56), UINT8_C(  0), UINT8_C(  6), UINT8_C( 94), UINT8_C(158),
        UINT8_C(117), UINT8_C(  7), UINT8_C(  2), UINT8_C( 82), UINT8_C( 59), UINT8_C(  4), UINT8_C( 43), UINT8_C(  0) },
      {  INT8_C(  13),  INT8_C(   9),  INT8_C(   3),  INT8_C(   9),  INT8_C(   0),  INT8_C(   8),  INT8_C(  10),  INT8_C(  12),
         INT8_C(   5),  INT8_C(   8),  INT8_C(   5),  INT8_C(   6),  INT8_C(   5),  INT8_C(   2),  INT8_C(   6),  INT8_C(   3) },
      {    UINT8_MAX,    UINT8_MAX, UINT8_C(  8),    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,
           UINT8_MAX,    UINT8_MAX, UINT8_C( 64),    UINT8_MAX,    UINT8_MAX, UINT8_C( 16),    UINT8_MAX, UINT8_C(  0) } },
    { { UINT8_C(  4), UINT8_C(  1), UINT8_C( 79), UINT8_C( 29), UINT8_C( 61), UINT8_C( 25), UINT8_C(  7), UINT8_C(121),
        UINT8_C(  9), UINT8_C(  1), UINT8_C( 41), UINT8_C(  0), UINT8_C(  0), UINT8_C( 29), UINT8_C(186), UINT8_C(  0) },
      {  INT8_C(  10),  INT8_C(   0),  INT8_C(   4),  INT8_C(   7),  INT8_C(   4),  INT8_C(  13),  INT8_C(   0),  INT8_C(   5),
         INT8_C(   8),  INT8_C(  13),  INT8_C(  14),  INT8_C(   1),  INT8_C(  10),  INT8_C(   0),  INT8_C(   7),  INT8_C(   1) },
      {    UINT8_MAX, UINT8_C(  1),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  7),    UINT8_MAX,
           UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0), UINT8_C(  0), UINT8_C( 29),    UINT8_MAX, UINT8_C(  0) } },
    { { UINT8_C(  0), UINT8_C( 15), UINT8_C(  1), UINT8_C(  8), UINT8_C( 42), UINT8_C(  4), UINT8_C( 14), UINT8_C(  3),
        UINT8_C(252), UINT8_C(  1), UINT8_C(  6), UINT8_C(  4), UINT8_C(  1), UINT8_C(  0), UINT8_C(  1), UINT8_C(  2) },
      {  INT8_C(  15),  INT8_C(   0),  INT8_C(   4),  INT8_C(  15),  INT8_C(  11),  INT8_C(   9),  INT8_C(   1),  INT8_C(  15),
         INT8_C(   7),  INT8_C(   9),  INT8_C(  14),  INT8_C(   4),  INT8_C(  12),  INT8_C(   6),  INT8_C(  12),  INT8_C(   0) },
      { UINT8_C(  0), UINT8_C( 15), UINT8_C( 16),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C( 28),    UINT8_MAX,
           UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C( 64),    UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  2) } },
    { { UINT8_C(  5), UINT8_C(  1), UINT8_C(  1), UINT8_C(  0), UINT8_C(  3), UINT8_C(  1), UINT8_C(176), UINT8_C(  1),
        UINT8_C(  0), UINT8_C(  0), UINT8_C( 28), UINT8_C( 63), UINT8_C(164), UINT8_C(114), UINT8_C(126), UINT8_C(  5) },
      {  INT8_C(  13),  INT8_C(   4),  INT8_C(   1),  INT8_C(   7),  INT8_C(   9),  INT8_C(  13),  INT8_C(  13),  INT8_C(   9),
         INT8_C(  11),  INT8_C(  11),  INT8_C(   5),  INT8_C(   2),  INT8_C(   0),  INT8_C(   2),  INT8_C(   9),  INT8_C(   6) },
      {    UINT8_MAX, UINT8_C( 16), UINT8_C(  2), UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,
        UINT8_C(  0), UINT8_C(  0),    UINT8_MAX, UINT8_C(252), UINT8_C(164),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX } },
    { { UINT8_C(  4), UINT8_C(194), UINT8_C( 62), UINT8_C(  0), UINT8_C( 80), UINT8_C(217), UINT8_C( 19), UINT8_C(  3),
        UINT8_C( 14), UINT8_C(  1), UINT8_C(  9), UINT8_C( 24), UINT8_C(  1), UINT8_C(  3), UINT8_C(  7), UINT8_C(  9) },
      {  INT8_C(   6),  INT8_C(   2),  INT8_C(   1),  INT8_C(  12),  INT8_C(   9),  INT8_C(   1),  INT8_C(   2),  INT8_C(  15),
         INT8_C(   7),  INT8_C(   6),  INT8_C(  10),  INT8_C(  15),  INT8_C(   6),  INT8_C(  11),  INT8_C(   4),  INT8_C(  11) },
      {    UINT8_MAX,    UINT8_MAX, UINT8_C(124), UINT8_C(  0),    UINT8_MAX,    UINT8_MAX, UINT8_C( 76),    UINT8_MAX,
           UINT8_MAX, UINT8_C( 64),    UINT8_MAX,    UINT8_MAX, UINT8_C( 64),    UINT8_MAX, UINT8_C(112),    UINT8_MAX } },
    { { UINT8_C(176), UINT8_C(190), UINT8_C(192), UINT8_C(  9), UINT8_C( 31), UINT8_C(162), UINT8_C(137), UINT8_C(  6),
        UINT8_C(216), UINT8_C(211), UINT8_C(229), UINT8_C( 95), UINT8_C(142), UINT8_C( 73), UINT8_C(122), UINT8_C( 11) },
      {  INT8_C(  41), -INT8_C(  92),  INT8_C(  41), -INT8_C(  29), -INT8_C(  12),  INT8_C(  18), -INT8_C( 127),  INT8_C(   1),
         INT8_C(  73), -INT8_C(  28),  INT8_C( 108),  INT8_C(  71),  INT8_C(  66),  INT8_C( 105),  INT8_C( 123), -INT8_C(  14) },
      {    UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C( 12),
           UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0) } },
    { { UINT8_C( 40), UINT8_C( 59), UINT8_C(251), UINT8_C( 71), UINT8_C(221), UINT8_C(132), UINT8_C( 78), UINT8_C(182),
        UINT8_C( 87), UINT8_C( 51), UINT8_C( 21), UINT8_C(229), UINT8_C(125), UINT8_C(143), UINT8_C(241), UINT8_C(166) },
      {  INT8_C(  51),  INT8_C(  26), -INT8_C( 119),  INT8_C(  40),  INT8_C(  44),  INT8_C(  10),  INT8_C(  41),  INT8_C( 117),
        -INT8_C(  18), -INT8_C( 107), -INT8_C(  68),  INT8_C(  48), -INT8_C(   2),  INT8_C(  55),  INT8_C(  34),  INT8_C(  38) },
      {    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,
        UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),    UINT8_MAX, UINT8_C( 31),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX } },
    { { UINT8_C(114), UINT8_C( 30), UINT8_C(110), UINT8_C( 79), UINT8_C(162), UINT8_C(188), UINT8_C(  5), UINT8_C(250),
        UINT8_C(239), UINT8_C( 26), UINT8_C(223), UINT8_C(108), UINT8_C(170), UINT8_C(208), UINT8_C( 19), UINT8_C(221) },
      { -INT8_C(  22), -INT8_C( 100),  INT8_C(   5),  INT8_C(  22), -INT8_C(  89),  INT8_C(  46), -INT8_C( 117), -INT8_C( 107),
        -INT8_C(  61),  INT8_C(  71), -INT8_C(  58), -INT8_C(  62),  INT8_C( 126), -INT8_C(  24), -INT8_C(  24), -INT8_C(  16) },
      { UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  0),
        UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  0), UINT8_C(  0) } },
    { { UINT8_C(  6), UINT8_C( 86), UINT8_C( 64), UINT8_C(169), UINT8_C( 18), UINT8_C( 69), UINT8_C(163), UINT8_C(  2),
        UINT8_C( 96), UINT8_C(130), UINT8_C(110), UINT8_C( 10), UINT8_C( 83), UINT8_C(129), UINT8_C(231), UINT8_C( 61) },
      {  INT8_C(  30), -INT8_C(  19),  INT8_C(  84), -INT8_C(  59),  INT8_C(  27), -INT8_C(  33),  INT8_C(  90), -INT8_C(  33),
         INT8_C(  39),  INT8_C(  32), -INT8_C(  95), -INT8_C(  91),  INT8_C(   9), -INT8_C( 119), -INT8_C( 106),  INT8_C(  15) },
      {    UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),
           UINT8_MAX,    UINT8_MAX, UINT8_C(  0), UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  0),    UINT8_MAX } },
    { { UINT8_C(224), UINT8_C(214), UINT8_C(184), UINT8_C(242), UINT8_C( 27), UINT8_C( 91), UINT8_C(244), UINT8_C(123),
        UINT8_C(222), UINT8_C( 99), UINT8_C(133), UINT8_C( 49), UINT8_C(228), UINT8_C(109), UINT8_C(110), UINT8_C(  2) },
      {  INT8_C(  90), -INT8_C(  62), -INT8_C(  57),  INT8_C( 117), -INT8_C(  94),  INT8_C(  34),  INT8_C(  84), -INT8_C(  55),
         INT8_C(  66), -INT8_C(  11),  INT8_C( 110),  INT8_C(  75),      INT8_MAX,  INT8_C(   4),  INT8_C(  91),  INT8_C(  95) },
      {    UINT8_MAX, UINT8_C(  0), UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),
           UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX } },
    { { UINT8_C(218), UINT8_C( 19), UINT8_C( 81), UINT8_C(246), UINT8_C(111), UINT8_C( 70), UINT8_C(113), UINT8_C( 77),
        UINT8_C(169), UINT8_C(247), UINT8_C(126), UINT8_C(141), UINT8_C(100), UINT8_C(236), UINT8_C(144), UINT8_C(190) },
      { -INT8_C(  81),  INT8_C(  87),  INT8_C(  51),  INT8_C(  81),  INT8_C( 121), -INT8_C( 120),  INT8_C(  26), -INT8_C(  68),
         INT8_C( 125), -INT8_C( 120),  INT8_C(   7), -INT8_C(   4), -INT8_C( 115),  INT8_C(  98),  INT8_C(  91),  INT8_C( 103) },
      { UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),
           UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  8), UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX } },
    { { UINT8_C(118), UINT8_C(173), UINT8_C( 93), UINT8_C(229), UINT8_C(243), UINT8_C(207), UINT8_C( 50), UINT8_C(156),
        UINT8_C(198), UINT8_C(176), UINT8_C( 41), UINT8_C( 42), UINT8_C(156), UINT8_C(185), UINT8_C(232), UINT8_C( 75) },
      {  INT8_C(  17),  INT8_C(  27), -INT8_C( 100), -INT8_C( 118), -INT8_C(  93), -INT8_C(  74),  INT8_C(  70),  INT8_C(  33),
         INT8_C(  63),  INT8_C(  78),  INT8_C(  29), -INT8_C(  52), -INT8_C(  80),  INT8_C( 121),  INT8_C(  51),  INT8_C(  38) },
      {    UINT8_MAX,    UINT8_MAX, UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,
           UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX } },
    { { UINT8_C( 38), UINT8_C(145), UINT8_C( 11), UINT8_C( 25), UINT8_C( 96), UINT8_C( 61), UINT8_C(181), UINT8_C( 38),
        UINT8_C(237), UINT8_C(222), UINT8_C( 80), UINT8_C(138), UINT8_C(152), UINT8_C( 56), UINT8_C(213), UINT8_C(169) },
      {  INT8_C(  83),  INT8_C( 114),  INT8_C(  51), -INT8_C(   9),  INT8_C(  40),  INT8_C( 122),  INT8_C(  24),  INT8_C( 103),
        -INT8_C(  56),  INT8_C(  53),  INT8_C(  51),  INT8_C( 120), -INT8_C(  82),  INT8_C( 103), -INT8_C(  97), -INT8_C(  44) },
      {    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,
        UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  0) } },
    { { UINT8_C(248), UINT8_C(170), UINT8_C(237), UINT8_C( 88), UINT8_C(232), UINT8_C(162), UINT8_C(126), UINT8_C(213),
        UINT8_C(129), UINT8_C(206), UINT8_C( 95), UINT8_C( 25), UINT8_C(  6), UINT8_C( 53), UINT8_C(194), UINT8_C( 89) },
      { -INT8_C(  89), -INT8_C(  11),  INT8_C(  80), -INT8_C(  49),  INT8_C( 111),  INT8_C( 104),  INT8_C(  55),  INT8_C(  55),
        -INT8_C(  98),  INT8_C( 106), -INT8_C(  80),  INT8_C(  76), -INT8_C(  47),  INT8_C(  79),  INT8_C(  33), -INT8_C(  55) },
      { UINT8_C(  0), UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,
        UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX, UINT8_C(  0) } },
    { { UINT8_C(249), UINT8_C( 14), UINT8_C( 33), UINT8_C(225), UINT8_C(177), UINT8_C(159), UINT8_C(183), UINT8_C( 50),
        UINT8_C(109), UINT8_C( 22), UINT8_C( 75), UINT8_C(115), UINT8_C( 75), UINT8_C( 13), UINT8_C(205), UINT8_C(242) },
      {  INT8_C(   2),  INT8_C(  29), -INT8_C(  62),  INT8_C( 114), -INT8_C( 122), -INT8_C(   7), -INT8_C(  87),  INT8_C(  36),
         INT8_C(  99),  INT8_C(  89),  INT8_C( 112),  INT8_C(  53), -INT8_C(  88), -INT8_C( 111), -INT8_C(   2), -INT8_C(  94) },
      {    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  1), UINT8_C(  0),    UINT8_MAX,
           UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0), UINT8_C(  0), UINT8_C( 51), UINT8_C(  0) } },
    { { UINT8_C(160), UINT8_C( 32), UINT8_C(131), UINT8_C( 81), UINT8_C(191), UINT8_C( 58), UINT8_C(131), UINT8_C( 45),
        UINT8_C( 81), UINT8_C(206), UINT8_C(160), UINT8_C(156), UINT8_C(219), UINT8_C(109), UINT8_C(143), UINT8_C(221) },
      { -INT8_C( 117),  INT8_C(  81),  INT8_C(  79),  INT8_C(  17),  INT8_C(  74), -INT8_C(   7),  INT8_C(  53), -INT8_C(  83),
         INT8_C(  82), -INT8_C(  91), -INT8_C(  30), -INT8_C(   5),  INT8_C(  55), -INT8_C(  31), -INT8_C(  99), -INT8_C(  41) },
      { UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),
           UINT8_MAX, UINT8_C(  0), UINT8_C(  0), UINT8_C(  4),    UINT8_MAX, UINT8_C(  0), UINT8_C(  0), UINT8_C(  0) } },
    { { UINT8_C(  1), UINT8_C( 32), UINT8_C( 40), UINT8_C(192), UINT8_C( 91), UINT8_C(171), UINT8_C(237), UINT8_C(172),
        UINT8_C(121), UINT8_C(142), UINT8_C( 72), UINT8_C( 84), UINT8_C(251), UINT8_C(215), UINT8_C( 49), UINT8_C(134) },
      {  INT8_C(  40), -INT8_C( 127), -INT8_C( 105),  INT8_C( 114),  INT8_C( 122), -INT8_C(  52),  INT8_C(  32), -INT8_C(  52),
         INT8_C( 114),  INT8_C(   2), -INT8_C(  57), -INT8_C(  87), -INT8_C(  29),  INT8_C( 100),      INT8_MIN, -INT8_C(  28) },
      {    UINT8_MAX, UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),
           UINT8_MAX,    UINT8_MAX, UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  0) } },
    { { UINT8_C(133), UINT8_C(168), UINT8_C(165), UINT8_C(224), UINT8_C( 83), UINT8_C(146), UINT8_C(140), UINT8_C(204),
        UINT8_C( 32), UINT8_C(212), UINT8_C( 32), UINT8_C( 28), UINT8_C(172), UINT8_C( 81), UINT8_C(162), UINT8_C(212) },
      { -INT8_C(  46),  INT8_C(  58),  INT8_C(  71),  INT8_C(  76),  INT8_C(   6),  INT8_C( 103),  INT8_C(  25),  INT8_C( 120),
         INT8_C( 105), -INT8_C(  32),  INT8_C(  33),  INT8_C(  77),  INT8_C(  69), -INT8_C(  95),  INT8_C(  49), -INT8_C(  54) },
      { UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,
           UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  0) } },
    { { UINT8_C( 73), UINT8_C(214), UINT8_C(170), UINT8_C(156), UINT8_C(105), UINT8_C( 54), UINT8_C(104), UINT8_C(137),
        UINT8_C( 10), UINT8_C(136), UINT8_C(165), UINT8_C(182), UINT8_C(218), UINT8_C( 72), UINT8_C(139), UINT8_C(172) },
      { -INT8_C( 126), -INT8_C(  46), -INT8_C(   7), -INT8_C( 120),  INT8_C(  57),  INT8_C(  18),  INT8_C(   1), -INT8_C(  94),
        -INT8_C(  14),  INT8_C(  34), -INT8_C(  17),  INT8_C(  55), -INT8_C(  60),  INT8_C(  33),  INT8_C(   1),  INT8_C(  13) },
      { UINT8_C(  0), UINT8_C(  0), UINT8_C(  1), UINT8_C(  0),    UINT8_MAX,    UINT8_MAX, UINT8_C(208), UINT8_C(  0),
        UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX } },
    { { UINT8_C(247), UINT8_C(171), UINT8_C(170), UINT8_C( 96), UINT8_C(225), UINT8_C( 18), UINT8_C(234), UINT8_C(236),
        UINT8_C(155), UINT8_C(143), UINT8_C(162), UINT8_C(117), UINT8_C(215), UINT8_C( 45), UINT8_C( 33), UINT8_C( 89) },
      { -INT8_C(   1),  INT8_C(  26), -INT8_C(  30),  INT8_C(  56),  INT8_C(  44), -INT8_C(  29), -INT8_C(  37),  INT8_C(  31),
         INT8_C(   5), -INT8_C(  54),  INT8_C(  86), -INT8_C(  55), -INT8_C(  21),  INT8_C(  88), -INT8_C(  41), -INT8_C(  29) },
      { UINT8_C(123),    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX, UINT8_C(  0), UINT8_C(  0),    UINT8_MAX,
           UINT8_MAX, UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  0) } },
    { { UINT8_C(  3), UINT8_C(129), UINT8_C( 67), UINT8_C(229), UINT8_C(147), UINT8_C( 45), UINT8_C(209), UINT8_C( 46),
        UINT8_C(189), UINT8_C(115), UINT8_C(163), UINT8_C(148), UINT8_C(161), UINT8_C(197), UINT8_C(238), UINT8_C(160) },
      { -INT8_C(  33), -INT8_C(  48), -INT8_C(  39),  INT8_C(  12), -INT8_C(  77), -INT8_C(  76),  INT8_C(  43), -INT8_C(  72),
         INT8_C( 126), -INT8_C( 127), -INT8_C( 126),  INT8_C( 106), -INT8_C(  39),  INT8_C(  89),  INT8_C(  77), -INT8_C(  35) },
      { UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),    UINT8_MAX, UINT8_C(  0), UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),
           UINT8_MAX, UINT8_C(  0), UINT8_C(  0),    UINT8_MAX, UINT8_C(  0),    UINT8_MAX,    UINT8_MAX, UINT8_C(  0) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint8x16_t a = simde_vld1q_u8(test_vec[i].a);
    simde_int8x16_t b = simde_vld1q_s8(test_vec[i].b);
    simde_uint8x16_t r = simde_vqshlq_u8(a, b);

    simde_test_arm_neon_assert_equal_u8x16(r, simde_vld1q_u8(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 16 ; i++) {
    simde_uint8x16_t a = simde_test_arm_neon_random_u8x16();
    simde_int8x16_t b = simde_test_arm_neon_random_i8x16();

    a = simde_vshlq_u8(a, simde_vnegq_s8(simde_vandq_s8(simde_test_arm_neon_random_i8x16(), simde_vdupq_n_s8(7))));
    b = simde_vandq_s8(b, simde_vdupq_n_s8(15));

    simde_uint8x16_t r = simde_vqshlq_u8(a, b);

    simde_test_arm_neon_write_u8x16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i8x16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u8x16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  for (int i = 0 ; i < 16 ; i++) {
    simde_uint8x16_t a = simde_test_arm_neon_random_u8x16();
    simde_int8x16_t b = simde_test_arm_neon_random_i8x16();

    simde_uint8x16_t r = simde_vqshlq_u8(a, b);

    simde_test_arm_neon_write_u8x16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i8x16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u8x16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vqshlq_u16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint16_t a[8];
    int16_t b[8];
    uint16_t r[8];
  } test_vec[] = {
    { { UINT16_C(   53), UINT16_C(   73), UINT16_C(    1), UINT16_C(   41), UINT16_C( 1831), UINT16_C(   99), UINT16_C(    0), UINT16_C(  965) },
      {  INT16_C(    21),  INT16_C(     9),  INT16_C(    25),  INT16_C(     7),  INT16_C(    10),  INT16_C(    27),  INT16_C(    29),  INT16_C(    19) },
      {      UINT16_MAX, UINT16_C(37376),      UINT16_MAX, UINT16_C( 5248),      UINT16_MAX,      UINT16_MAX, UINT16_C(    0),      UINT16_MAX } },
    { { UINT16_C(  817), UINT16_C(50286), UINT16_C(   43), UINT16_C(    5), UINT16_C(  610), UINT16_C(   89), UINT16_C(    0), UINT16_C(    6) },
      {  INT16_C(     3),  INT16_C(    13),  INT16_C(    28),  INT16_C(    21),  INT16_C(     1),  INT16_C(    22),  INT16_C(    17),  INT16_C(    20) },
      { UINT16_C( 6536),      UINT16_MAX,      UINT16_MAX,      UINT16_MAX, UINT16_C( 1220),      UINT16_MAX, UINT16_C(    0),      UINT16_MAX } },
    { { UINT16_C( 3706), UINT16_C(    1), UINT16_C(    0), UINT16_C( 1809), UINT16_C(    0), UINT16_C(    2), UINT16_C(    3), UINT16_C(    1) },
      {  INT16_C(     8),  INT16_C(    23),  INT16_C(     3),  INT16_C(    15),  INT16_C(    17),  INT16_C(    14),  INT16_C(     2),  INT16_C(    17) },
      {      UINT16_MAX,      UINT16_MAX, UINT16_C(    0),      UINT16_MAX, UINT16_C(    0), UINT16_C(32768), UINT16_C(   12),      UINT16_MAX } },
    { { UINT16_C(    0), UINT16_C( 1004), UINT16_C(    4), UINT16_C(13973), UINT16_C(    0), UINT16_C(    1), UINT16_C(   23), UINT16_C(    4) },
      {  INT16_C(     0),  INT16_C(     3),  INT16_C(    25),  INT16_C(    19),  INT16_C(     0),  INT16_C(    27),  INT16_C(    19),  INT16_C(     3) },
      { UINT16_C(    0), UINT16_C( 8032),      UINT16_MAX,      UINT16_MAX, UINT16_C(    0),      UINT16_MAX,      UINT16_MAX, UINT16_C(   32) } },
    { { UINT16_C(20362), UINT16_C(12786), UINT16_C( 4876), UINT16_C(    1), UINT16_C(  633), UINT16_C(  172), UINT16_C(   13), UINT16_C(  506) },
      {  INT16_C(    15),  INT16_C(     7),  INT16_C(    25),  INT16_C(    30),  INT16_C(     6),  INT16_C(    21),  INT16_C(     3),  INT16_C(    21) },
      {      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX, UINT16_C(40512),      UINT16_MAX, UINT16_C(  104),      UINT16_MAX } },
    { { UINT16_C(   45), UINT16_C(    1), UINT16_C(  150), UINT16_C(  245), UINT16_C( 7830), UINT16_C(46775), UINT16_C(    5), UINT16_C(    0) },
      {  INT16_C(     7),  INT16_C(    30),  INT16_C(    19),  INT16_C(     6),  INT16_C(    18),  INT16_C(    27),  INT16_C(    13),  INT16_C(    27) },
      { UINT16_C( 5760),      UINT16_MAX,      UINT16_MAX, UINT16_C(15680),      UINT16_MAX,      UINT16_MAX, UINT16_C(40960), UINT16_C(    0) } },
    { { UINT16_C(    3), UINT16_C(  502), UINT16_C(   81), UINT16_C(   15), UINT16_C(    6), UINT16_C(   90), UINT16_C(    1), UINT16_C(14881) },
      {  INT16_C(    26),  INT16_C(     6),  INT16_C(     5),  INT16_C(    26),  INT16_C(    12),  INT16_C(     1),  INT16_C(    30),  INT16_C(    10) },
      {      UINT16_MAX, UINT16_C(32128), UINT16_C( 2592),      UINT16_MAX, UINT16_C(24576), UINT16_C(  180),      UINT16_MAX,      UINT16_MAX } },
    { { UINT16_C(   97), UINT16_C(  675), UINT16_C(18939), UINT16_C(    0), UINT16_C(   17), UINT16_C(   55), UINT16_C(    0), UINT16_C(    1) },
      {  INT16_C(    28),  INT16_C(    28),  INT16_C(     6),  INT16_C(    15),  INT16_C(    12),  INT16_C(    27),  INT16_C(     5),  INT16_C(     4) },
      {      UINT16_MAX,      UINT16_MAX,      UINT16_MAX, UINT16_C(    0),      UINT16_MAX,      UINT16_MAX, UINT16_C(    0), UINT16_C(   16) } },
    { { UINT16_C( 5886), UINT16_C(    1), UINT16_C(20225), UINT16_C(60915), UINT16_C(10107), UINT16_C( 3995), UINT16_C( 1481), UINT16_C(  838) },
      {  INT16_C(    25),  INT16_C(    31),  INT16_C(    17),  INT16_C(    25),  INT16_C(     8),  INT16_C(    24),  INT16_C(    19),  INT16_C(     1) },
      {      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX, UINT16_C( 1676) } },
    { { UINT16_C(  161), UINT16_C(    4), UINT16_C(   22), UINT16_C(    1), UINT16_C(  434), UINT16_C(  200), UINT16_C(  252), UINT16_C(   24) },
      {  INT16_C(    31),  INT16_C(    22),  INT16_C(     8),  INT16_C(    22),  INT16_C(    15),  INT16_C(     6),  INT16_C(     3),  INT16_C(    17) },
      {      UINT16_MAX,      UINT16_MAX, UINT16_C( 5632),      UINT16_MAX,      UINT16_MAX, UINT16_C(12800), UINT16_C( 2016),      UINT16_MAX } },
    { { UINT16_C(  768), UINT16_C(  185), UINT16_C(11045), UINT16_C(17146), UINT16_C(  123), UINT16_C( 2185), UINT16_C( 2991), UINT16_C( 2975) },
      {  INT16_C(     4),  INT16_C(    15),  INT16_C(    12),  INT16_C(    16),  INT16_C(     4),  INT16_C(    11),  INT16_C(    23),  INT16_C(    17) },
      { UINT16_C(12288),      UINT16_MAX,      UINT16_MAX,      UINT16_MAX, UINT16_C( 1968),      UINT16_MAX,      UINT16_MAX,      UINT16_MAX } },
    { { UINT16_C( 4735), UINT16_C(  202), UINT16_C(  100), UINT16_C( 4697), UINT16_C(    1), UINT16_C(  848), UINT16_C(    1), UINT16_C(    1) },
      {  INT16_C(    20),  INT16_C(    14),  INT16_C(    25),  INT16_C(    31),  INT16_C(    25),  INT16_C(    28),  INT16_C(    16),  INT16_C(     6) },
      {      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX, UINT16_C(   64) } },
    { { UINT16_C(  505), UINT16_C(  711), UINT16_C(   88), UINT16_C(  979), UINT16_C(  223), UINT16_C(  232), UINT16_C(    1), UINT16_C(   25) },
      {  INT16_C(     7),  INT16_C(    19),  INT16_C(    19),  INT16_C(    12),  INT16_C(    22),  INT16_C(    29),  INT16_C(    12),  INT16_C(     6) },
      { UINT16_C(64640),      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX, UINT16_C( 4096), UINT16_C( 1600) } },
    { { UINT16_C(   30), UINT16_C(    0), UINT16_C(29057), UINT16_C( 3840), UINT16_C(    0), UINT16_C(  161), UINT16_C(18788), UINT16_C(   24) },
      {  INT16_C(    18),  INT16_C(    18),  INT16_C(    21),  INT16_C(    27),  INT16_C(     0),  INT16_C(     4),  INT16_C(     2),  INT16_C(     6) },
      {      UINT16_MAX, UINT16_C(    0),      UINT16_MAX,      UINT16_MAX, UINT16_C(    0), UINT16_C( 2576),      UINT16_MAX, UINT16_C( 1536) } },
    { { UINT16_C(   11), UINT16_C(    0), UINT16_C( 1697), UINT16_C( 3219), UINT16_C(   20), UINT16_C( 6337), UINT16_C(21846), UINT16_C(    3) },
      {  INT16_C(     8),  INT16_C(     1),  INT16_C(    15),  INT16_C(     0),  INT16_C(    19),  INT16_C(    23),  INT16_C(    22),  INT16_C(     8) },
      { UINT16_C( 2816), UINT16_C(    0),      UINT16_MAX, UINT16_C( 3219),      UINT16_MAX,      UINT16_MAX,      UINT16_MAX, UINT16_C(  768) } },
    { { UINT16_C(   31), UINT16_C(16418), UINT16_C(    8), UINT16_C( 1747), UINT16_C( 1875), UINT16_C( 1665), UINT16_C(18938), UINT16_C(   26) },
      {  INT16_C(    26),  INT16_C(    16),  INT16_C(    26),  INT16_C(    13),  INT16_C(    27),  INT16_C(    29),  INT16_C(     0),  INT16_C(     5) },
      {      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX, UINT16_C(18938), UINT16_C(  832) } },
    { { UINT16_C(56309), UINT16_C( 3976), UINT16_C(13775), UINT16_C( 2757), UINT16_C(49667), UINT16_C(  822), UINT16_C(64510), UINT16_C(47252) },
      {  INT16_C( 25827), -INT16_C(  4618),  INT16_C( 27091), -INT16_C( 18383),  INT16_C( 17927),  INT16_C( 14482),  INT16_C( 15644),  INT16_C(  4356) },
      { UINT16_C(    0), UINT16_C(    3), UINT16_C(    0),      UINT16_MAX,      UINT16_MAX, UINT16_C(    0),      UINT16_MAX,      UINT16_MAX } },
    { { UINT16_C(35864), UINT16_C(59424), UINT16_C(58817), UINT16_C(50418), UINT16_C(10664), UINT16_C(42696), UINT16_C(23588), UINT16_C( 1886) },
      {  INT16_C( 21696), -INT16_C( 27404),  INT16_C(  9918), -INT16_C( 15028), -INT16_C(  8596), -INT16_C( 30466),  INT16_C(   539),  INT16_C( 13209) },
      { UINT16_C(    0), UINT16_C(   14), UINT16_C(    0),      UINT16_MAX,      UINT16_MAX, UINT16_C(10674),      UINT16_MAX, UINT16_C(    0) } },
    { { UINT16_C(47758), UINT16_C(20251), UINT16_C( 3743), UINT16_C(18195), UINT16_C(56119), UINT16_C(23533), UINT16_C(19511), UINT16_C(63587) },
      {  INT16_C( 22432),  INT16_C( 24204), -INT16_C( 10115), -INT16_C(  5596),  INT16_C(  8886), -INT16_C( 11918),  INT16_C(  3108), -INT16_C( 19964) },
      { UINT16_C(    0), UINT16_C(    0),      UINT16_MAX,      UINT16_MAX, UINT16_C(    0),      UINT16_MAX,      UINT16_MAX,      UINT16_MAX } },
    { { UINT16_C( 8390), UINT16_C(25857), UINT16_C( 5166), UINT16_C(26029), UINT16_C(39664), UINT16_C(10176), UINT16_C( 9190), UINT16_C(34591) },
      { -INT16_C( 21637), -INT16_C(  1819),  INT16_C(  2435),  INT16_C( 14818),  INT16_C( 21803),  INT16_C( 20234),  INT16_C(  3937),  INT16_C(  9985) },
      {      UINT16_MAX, UINT16_C(    0), UINT16_C(    0), UINT16_C(    0),      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX } },
    { { UINT16_C(  559), UINT16_C(23948), UINT16_C(14615), UINT16_C( 1986), UINT16_C(33492), UINT16_C(47662), UINT16_C(20134), UINT16_C( 8513) },
      {  INT16_C( 10233),  INT16_C( 32025), -INT16_C(   976),  INT16_C( 23734), -INT16_C( 16047), -INT16_C( 19797), -INT16_C( 21040), -INT16_C(    39) },
      { UINT16_C(    4),      UINT16_MAX,      UINT16_MAX, UINT16_C(    0),      UINT16_MAX, UINT16_C(    0), UINT16_C(    0), UINT16_C(    0) } },
    { { UINT16_C(26031), UINT16_C(50780), UINT16_C( 7839), UINT16_C(29645), UINT16_C(64672), UINT16_C(17965), UINT16_C(28490), UINT16_C(17255) },
      { -INT16_C( 32362), -INT16_C( 14656),  INT16_C( 30589), -INT16_C( 12766), -INT16_C( 12744),  INT16_C(  2176),  INT16_C( 22907),  INT16_C( 10759) },
      { UINT16_C(    0), UINT16_C(    0),      UINT16_MAX,      UINT16_MAX,      UINT16_MAX, UINT16_C(    0),      UINT16_MAX,      UINT16_MAX } },
    { { UINT16_C(25534), UINT16_C(24049), UINT16_C(48769), UINT16_C( 8656), UINT16_C(65210), UINT16_C( 1128), UINT16_C(53101), UINT16_C(  840) },
      {  INT16_C(  2128), -INT16_C( 12855), -INT16_C(  4993), -INT16_C( 18533),  INT16_C(  7098),  INT16_C( 13759), -INT16_C( 14732),  INT16_C( 13151) },
      {      UINT16_MAX, UINT16_C(    0),      UINT16_MAX, UINT16_C(    0), UINT16_C(    0), UINT16_C(    0),      UINT16_MAX,      UINT16_MAX } },
    { { UINT16_C(20521), UINT16_C(43664), UINT16_C(24847), UINT16_C(51660), UINT16_C(13407), UINT16_C(52430), UINT16_C( 5635), UINT16_C(21711) },
      { -INT16_C( 26594), -INT16_C( 25055), -INT16_C( 17020),  INT16_C( 15957),  INT16_C(  5592),  INT16_C( 19827), -INT16_C( 11301),  INT16_C(  1408) },
      {      UINT16_MAX,      UINT16_MAX, UINT16_C(    0),      UINT16_MAX, UINT16_C(    0),      UINT16_MAX, UINT16_C(    0), UINT16_C(    0) } },
    { { UINT16_C( 4131), UINT16_C(12975), UINT16_C(31601), UINT16_C(53500), UINT16_C(51887), UINT16_C(45980), UINT16_C(27616), UINT16_C(65031) },
      {  INT16_C( 10244), -INT16_C( 30564), -INT16_C(  3355), -INT16_C( 16697),  INT16_C( 14855), -INT16_C(  7669), -INT16_C( 29939),  INT16_C( 12775) },
      {      UINT16_MAX, UINT16_C(    0), UINT16_C(    0), UINT16_C(    0),      UINT16_MAX,      UINT16_MAX,      UINT16_MAX, UINT16_C(    0) } },
    { { UINT16_C(38811), UINT16_C( 3427), UINT16_C(24338), UINT16_C(49885), UINT16_C(31273), UINT16_C( 2421), UINT16_C(31973), UINT16_C(59656) },
      { -INT16_C( 23388), -INT16_C( 30094),  INT16_C( 14742), -INT16_C( 25272),  INT16_C( 21363), -INT16_C( 32384),  INT16_C( 26590),  INT16_C( 31154) },
      { UINT16_C(    0),      UINT16_MAX, UINT16_C(    0),      UINT16_MAX,      UINT16_MAX, UINT16_C(    0), UINT16_C(    0), UINT16_C(    0) } },
    { { UINT16_C( 5630), UINT16_C( 4486), UINT16_C(25717), UINT16_C(40659), UINT16_C(18654), UINT16_C(50088), UINT16_C(45252), UINT16_C(26797) },
      {  INT16_C(  8020), -INT16_C(  5134),  INT16_C( 14936), -INT16_C( 13432),  INT16_C(  2189),  INT16_C( 27468), -INT16_C(   400),  INT16_C( 28389) },
      {      UINT16_MAX, UINT16_C(    0),      UINT16_MAX, UINT16_C(    0), UINT16_C(    0),      UINT16_MAX,      UINT16_MAX, UINT16_C(    0) } },
    { { UINT16_C(27412), UINT16_C(35199), UINT16_C(21199), UINT16_C(44327), UINT16_C(53146), UINT16_C(24177), UINT16_C( 7807), UINT16_C(54471) },
      { -INT16_C( 18115), -INT16_C( 27201),  INT16_C( 18420), -INT16_C( 32416), -INT16_C( 21168), -INT16_C( 16147), -INT16_C( 11605), -INT16_C( 16594) },
      {      UINT16_MAX, UINT16_C(    0), UINT16_C(    5),      UINT16_MAX,      UINT16_MAX, UINT16_C(    0), UINT16_C(    0),      UINT16_MAX } },
    { { UINT16_C(44605), UINT16_C( 3400), UINT16_C(28672), UINT16_C(39866), UINT16_C(11071), UINT16_C(49145), UINT16_C(49225), UINT16_C(34451) },
      {  INT16_C( 21114),  INT16_C( 28187),  INT16_C( 31897), -INT16_C(  5649), -INT16_C(  9175), -INT16_C( 11095), -INT16_C( 10066), -INT16_C(  4972) },
      {      UINT16_MAX,      UINT16_MAX, UINT16_C(    0), UINT16_C(    0),      UINT16_MAX, UINT16_C(    0), UINT16_C(    0), UINT16_C(    0) } },
    { { UINT16_C(56454), UINT16_C(34553), UINT16_C(45900), UINT16_C(35873), UINT16_C( 7135), UINT16_C(10315), UINT16_C(57051), UINT16_C(21935) },
      { -INT16_C( 13776), -INT16_C( 13885), -INT16_C( 19642),  INT16_C( 28595),  INT16_C( 23695),  INT16_C( 15940), -INT16_C( 10188), -INT16_C( 17878) },
      {      UINT16_MAX, UINT16_C(    0),      UINT16_MAX, UINT16_C(    0), UINT16_C(    0),      UINT16_MAX,      UINT16_MAX,      UINT16_MAX } },
    { { UINT16_C( 9140), UINT16_C(  321), UINT16_C(25302), UINT16_C(46477), UINT16_C(55421), UINT16_C(23006), UINT16_C(36278), UINT16_C(59054) },
      {  INT16_C( 29271), -INT16_C( 24913),  INT16_C( 25125), -INT16_C( 19443),  INT16_C( 20927), -INT16_C(  3086),  INT16_C(  7209), -INT16_C(  8530) },
      {      UINT16_MAX, UINT16_C(    0),      UINT16_MAX,      UINT16_MAX, UINT16_C(    0), UINT16_C(    1),      UINT16_MAX, UINT16_C(    0) } },
    { { UINT16_C(61247), UINT16_C( 5855), UINT16_C(27729), UINT16_C(53195), UINT16_C(43332), UINT16_C(64040), UINT16_C(54838), UINT16_C(36576) },
      { -INT16_C( 28856),  INT16_C( 27948),  INT16_C( 14834), -INT16_C( 20190),  INT16_C(  5259), -INT16_C( 19292),  INT16_C( 21041),  INT16_C( 28818) },
      {      UINT16_MAX,      UINT16_MAX, UINT16_C(    1),      UINT16_MAX, UINT16_C(    0), UINT16_C(    0),      UINT16_MAX, UINT16_C(    0) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint16x8_t a = simde_vld1q_u16(test_vec[i].a);
    simde_int16x8_t b = simde_vld1q_s16(test_vec[i].b);
    simde_uint16x8_t r = simde_vqshlq_u16(a, b);

    simde_test_arm_neon_assert_equal_u16x8(r, simde_vld1q_u16(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 16 ; i++) {
    simde_uint16x8_t a = simde_test_arm_neon_random_u16x8();
    simde_int16x8_t b = simde_test_arm_neon_random_i16x8();

    a = simde_vshlq_u16(a, simde_vnegq_s16(simde_vandq_s16(simde_test_arm_neon_random_i16x8(), simde_vdupq_n_s16(15))));
    b = simde_vandq_s16(b, simde_vdupq_n_s16(31));

    simde_uint16x8_t r = simde_vqshlq_u16(a, b);

    simde_test_arm_neon_write_u16x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i16x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u16x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  for (int i = 0 ; i < 16 ; i++) {
    simde_uint16x8_t a = simde_test_arm_neon_random_u16x8();
    simde_int16x8_t b = simde_test_arm_neon_random_i16x8();

    simde_uint16x8_t r = simde_vqshlq_u16(a, b);

    simde_test_arm_neon_write_u16x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i16x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u16x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vqshlq_u32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint32_t a[4];
    int32_t b[4];
    uint32_t r[4];
  } test_vec[] = {
    { { UINT32_C( 310318890), UINT32_C( 147682281), UINT32_C(  27720320), UINT32_C(        25) },
      {  INT32_C(          26),  INT32_C(          57),  INT32_C(          29),  INT32_C(          23) },
      {           UINT32_MAX,           UINT32_MAX,           UINT32_MAX, UINT32_C( 209715200) } },
    { { UINT32_C(        54), UINT32_C(         0), UINT32_C(     45689), UINT32_C(         0) },
      {  INT32_C(          36),  INT32_C(          28),  INT32_C(          41),  INT32_C(          36) },
      {           UINT32_MAX, UINT32_C(         0),           UINT32_MAX, UINT32_C(         0) } },
    { { UINT32_C(  10818744), UINT32_C(         1), UINT32_C(   1682018), UINT32_C(      3903) },
      {  INT32_C(           6),  INT32_C(          25),  INT32_C(          45),  INT32_C(           2) },
      { UINT32_C( 692399616), UINT32_C(  33554432),           UINT32_MAX, UINT32_C(     15612) } },
    { { UINT32_C(         2), UINT32_C(   2140737), UINT32_C( 178973910), UINT32_C(         3) },
      {  INT32_C(          22),  INT32_C(          15),  INT32_C(          56),  INT32_C(          37) },
      { UINT32_C(   8388608),           UINT32_MAX,           UINT32_MAX,           UINT32_MAX } },
    { { UINT32_C(     40841), UINT32_C(  63644684), UINT32_C(      5249), UINT32_C(      5257) },
      {  INT32_C(          20),  INT32_C(          23),  INT32_C(          39),  INT32_C(          46) },
      {           UINT32_MAX,           UINT32_MAX,           UINT32_MAX,           UINT32_MAX } },
    { { UINT32_C(       286), UINT32_C(     15062), UINT32_C(         2), UINT32_C(    649935) },
      {  INT32_C(          63),  INT32_C(          62),  INT32_C(          15),  INT32_C(          38) },
      {           UINT32_MAX,           UINT32_MAX, UINT32_C(     65536),           UINT32_MAX } },
    { { UINT32_C(    243889), UINT32_C(1536178452), UINT32_C(       166), UINT32_C(     10929) },
      {  INT32_C(          47),  INT32_C(          13),  INT32_C(          47),  INT32_C(          47) },
      {           UINT32_MAX,           UINT32_MAX,           UINT32_MAX,           UINT32_MAX } },
    { { UINT32_C(         0), UINT32_C(         1), UINT32_C(         0), UINT32_C(       750) },
      {  INT32_C(          39),  INT32_C(          59),  INT32_C(          62),  INT32_C(          63) },
      { UINT32_C(         0),           UINT32_MAX, UINT32_C(         0),           UINT32_MAX } },
    { { UINT32_C(  68171718), UINT32_C(  42382850), UINT32_C(        40), UINT32_C(    414253) },
      {  INT32_C(           9),  INT32_C(          59),  INT32_C(          25),  INT32_C(          41) },
      {           UINT32_MAX,           UINT32_MAX, UINT32_C(1342177280),           UINT32_MAX } },
    { { UINT32_C(      3811), UINT32_C(1251055601), UINT32_C(    101330), UINT32_C(     43874) },
      {  INT32_C(          26),  INT32_C(          60),  INT32_C(          11),  INT32_C(          49) },
      {           UINT32_MAX,           UINT32_MAX, UINT32_C( 207523840),           UINT32_MAX } },
    { { UINT32_C(    418361), UINT32_C(      7376), UINT32_C(  10723065), UINT32_C(       466) },
      {  INT32_C(          19),  INT32_C(          42),  INT32_C(           7),  INT32_C(          48) },
      {           UINT32_MAX,           UINT32_MAX, UINT32_C(1372552320),           UINT32_MAX } },
    { { UINT32_C(1490974254), UINT32_C(   2068975), UINT32_C(    257675), UINT32_C(        17) },
      {  INT32_C(           0),  INT32_C(          59),  INT32_C(          18),  INT32_C(          60) },
      { UINT32_C(1490974254),           UINT32_MAX,           UINT32_MAX,           UINT32_MAX } },
    { { UINT32_C(     16264), UINT32_C(    106605), UINT32_C(2834818348), UINT32_C(        10) },
      {  INT32_C(          61),  INT32_C(          37),  INT32_C(          26),  INT32_C(          20) },
      {           UINT32_MAX,           UINT32_MAX,           UINT32_MAX, UINT32_C(  10485760) } },
    { { UINT32_C(     87747), UINT32_C(        22), UINT32_C(       115), UINT32_C(         1) },
      {  INT32_C(          61),  INT32_C(          63),  INT32_C(          32),  INT32_C(          17) },
      {           UINT32_MAX,           UINT32_MAX,           UINT32_MAX, UINT32_C(    131072) } },
    { { UINT32_C(        55), UINT32_C(     32526), UINT32_C(  30830505), UINT32_C( 831708221) },
      {  INT32_C(          39),  INT32_C(          10),  INT32_C(          45),  INT32_C(          37) },
      {           UINT32_MAX, UINT32_C(  33306624),           UINT32_MAX,           UINT32_MAX } },
    { { UINT32_C(    111921), UINT32_C(    276102), UINT32_C(     78820), UINT32_C(        21) },
      {  INT32_C(           7),  INT32_C(          56),  INT32_C(          11),  INT32_C(          44) },
      { UINT32_C(  14325888),           UINT32_MAX, UINT32_C( 161423360),           UINT32_MAX } },
    { { UINT32_C(1838811636), UINT32_C(1842079714), UINT32_C(1780156094), UINT32_C( 314151652) },
      { -INT32_C(   455510698), -INT32_C(   265935103),  INT32_C(  1133379944),  INT32_C(  1856362105) },
      {           UINT32_MAX, UINT32_C(3684159428),           UINT32_MAX,           UINT32_MAX } },
    { { UINT32_C(3269148639), UINT32_C(3828327974), UINT32_C(2437827245), UINT32_C( 866322653) },
      {  INT32_C(  2132245629),  INT32_C(   208616868), -INT32_C(  1202717121), -INT32_C(  1289292588) },
      {           UINT32_MAX, UINT32_C(         0),           UINT32_MAX, UINT32_C(         0) } },
    { { UINT32_C(1500840243), UINT32_C(1430103464), UINT32_C(3437661167), UINT32_C( 285247891) },
      { -INT32_C(  1450174715), -INT32_C(  1800011947), -INT32_C(   783547139),  INT32_C(   730166264) },
      {           UINT32_MAX,           UINT32_MAX, UINT32_C( 429707645), UINT32_C(   1114249) } },
    { { UINT32_C( 478476916), UINT32_C(2406597023), UINT32_C(3764082509), UINT32_C(3874577376) },
      { -INT32_C(   930119309),  INT32_C(  2119976321),  INT32_C(  1112582217), -INT32_C(  1871850213) },
      {           UINT32_MAX, UINT32_C(         0),           UINT32_MAX,           UINT32_MAX } },
    { { UINT32_C(1873605327), UINT32_C(  16654003), UINT32_C(1457609077), UINT32_C( 675074741) },
      { -INT32_C(   705639596),  INT32_C(  1515408400),  INT32_C(   278701044),  INT32_C(  1218447736) },
      {           UINT32_MAX,           UINT32_MAX, UINT32_C(    355861),           UINT32_MAX } },
    { { UINT32_C(2948025595), UINT32_C(3769611626), UINT32_C(3275132942), UINT32_C(3085660771) },
      {  INT32_C(  1317854013),  INT32_C(   480829223), -INT32_C(    80984957),  INT32_C(  1229179981) },
      {           UINT32_MAX,           UINT32_MAX, UINT32_C(         0),           UINT32_MAX } },
    { { UINT32_C(2214132248), UINT32_C(3194202031), UINT32_C(2608961848), UINT32_C(1213361419) },
      {  INT32_C(  1888935496),  INT32_C(  1082932925), -INT32_C(   801326974), -INT32_C(  1676050556) },
      {           UINT32_MAX, UINT32_C(         0), UINT32_C(         0), UINT32_C(         0) } },
    { { UINT32_C( 689901946), UINT32_C(4041704120), UINT32_C( 646670619), UINT32_C( 510647766) },
      {  INT32_C(  2039350715), -INT32_C(   960947644),  INT32_C(  1452733906), -INT32_C(   269242507) },
      { UINT32_C(         0),           UINT32_MAX, UINT32_C(         0),           UINT32_MAX } },
    { { UINT32_C(2031620800), UINT32_C(2959671445), UINT32_C(1071117673), UINT32_C(2388477650) },
      { -INT32_C(  1895306165), -INT32_C(   648626170),  INT32_C(   724561078),  INT32_C(  1545216668) },
      {           UINT32_MAX,           UINT32_MAX, UINT32_C(         0), UINT32_C(         0) } },
    { { UINT32_C(3402969653), UINT32_C(2608480050), UINT32_C( 114970932), UINT32_C(3818141847) },
      {  INT32_C(   712153892),  INT32_C(   302237788),  INT32_C(  1362965429), -INT32_C(  1968351403) },
      {           UINT32_MAX,           UINT32_MAX, UINT32_C(         0),           UINT32_MAX } },
    { { UINT32_C(3159655305), UINT32_C(4132949954), UINT32_C(3103535648), UINT32_C(2392559978) },
      { -INT32_C(  2001203924), -INT32_C(  1952793386),  INT32_C(  1155323887), -INT32_C(  1194358482) },
      {           UINT32_MAX, UINT32_C(         0), UINT32_C(     23678),           UINT32_MAX } },
    { { UINT32_C(3463717644), UINT32_C( 331664370), UINT32_C(1741406717), UINT32_C(2130011730) },
      {  INT32_C(  1225240179),  INT32_C(  1507107178), -INT32_C(  1482837895),  INT32_C(  1180658746) },
      {           UINT32_MAX,           UINT32_MAX,           UINT32_MAX,           UINT32_MAX } },
    { { UINT32_C(2182468496), UINT32_C(2627066271), UINT32_C(3959709850), UINT32_C( 980154822) },
      {  INT32_C(   293827239), -INT32_C(  1939187693),  INT32_C(  1110706184),  INT32_C(    76125044) },
      { UINT32_C(         0),           UINT32_MAX,           UINT32_MAX,           UINT32_MAX } },
    { { UINT32_C( 109551207), UINT32_C( 312614007), UINT32_C(1140762237), UINT32_C(1199401376) },
      { -INT32_C(   279379493),  INT32_C(  1635500889),  INT32_C(  1084534731), -INT32_C(  1438372541) },
      { UINT32_C(         0),           UINT32_MAX, UINT32_C(         0),           UINT32_MAX } },
    { { UINT32_C(1118882763), UINT32_C(1700025064), UINT32_C(2577945593), UINT32_C(2564826812) },
      { -INT32_C(  2138621657), -INT32_C(   924777731), -INT32_C(   183990862),  INT32_C(  2107592114) },
      {           UINT32_MAX, UINT32_C( 212503133), UINT32_C(         0), UINT32_C(         0) } },
    { { UINT32_C(  12603160), UINT32_C(2590315681), UINT32_C( 607325799), UINT32_C(1539052596) },
      {  INT32_C(  1255883597), -INT32_C(   149701563), -INT32_C(   185853118), -INT32_C(  2123199640) },
      {           UINT32_MAX,           UINT32_MAX,           UINT32_MAX,           UINT32_MAX } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint32x4_t a = simde_vld1q_u32(test_vec[i].a);
    simde_int32x4_t b = simde_vld1q_s32(test_vec[i].b);
    simde_uint32x4_t r = simde_vqshlq_u32(a, b);

    simde_test_arm_neon_assert_equal_u32x4(r, simde_vld1q_u32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 16 ; i++) {
    simde_uint32x4_t a = simde_test_arm_neon_random_u32x4();
    simde_int32x4_t b = simde_test_arm_neon_random_i32x4();

    a = simde_vshlq_u32(a, simde_vnegq_s32(simde_vandq_s32(simde_test_arm_neon_random_i32x4(), simde_vdupq_n_s32(31))));
    b = simde_vandq_s32(b, simde_vdupq_n_s32(63));

    simde_uint32x4_t r = simde_vqshlq_u32(a, b);

    simde_test_arm_neon_write_u32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  for (int i = 0 ; i < 16 ; i++) {
    simde_uint32x4_t a = simde_test_arm_neon_random_u32x4();
    simde_int32x4_t b = simde_test_arm_neon_random_i32x4();

    simde_uint32x4_t r = simde_vqshlq_u32(a, b);

    simde_test_arm_neon_write_u32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vqshlq_u64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint64_t a[2];
    int64_t b[2];
    uint64_t r[2];
  } test_vec[] = {
    { { UINT64_C(           104331535), UINT64_C(     140333733799447) },
      {  INT64_C(                  39),  INT64_C(                  10) },
      {                     UINT64_MAX, UINT64_C(  143701743410633728) } },
    { { UINT64_C( 2293987312730849898), UINT64_C(  637453611640476887) },
      {  INT64_C(                  15),  INT64_C(                  16) },
      {                     UINT64_MAX,                     UINT64_MAX } },
    { { UINT64_C(     318053277767081), UINT64_C(              244331) },
      {  INT64_C(                  46),  INT64_C(                  24) },
      {                     UINT64_MAX, UINT64_C(       4099193962496) } },
    { { UINT64_C(               65216), UINT64_C( 4213368362918658757) },
      {  INT64_C(                   0),  INT64_C(                  54) },
      { UINT64_C(               65216),                     UINT64_MAX } },
    { { UINT64_C(    1134957596075865), UINT64_C(               15744) },
      {  INT64_C(                  48),  INT64_C(                   0) },
      {                     UINT64_MAX, UINT64_C(               15744) } },
    { { UINT64_C(    8515082140345961), UINT64_C(               28251) },
      {  INT64_C(                   9),  INT64_C(                  37) },
      { UINT64_C( 4359722055857132032), UINT64_C(    3882787874537472) } },
    { { UINT64_C(                6117), UINT64_C(          4398145905) },
      {  INT64_C(                  43),  INT64_C(                  49) },
      { UINT64_C(   53805701016846336),                     UINT64_MAX } },
    { { UINT64_C(             2064168), UINT64_C(                6028) },
      {  INT64_C(                  41),  INT64_C(                  58) },
      { UINT64_C( 4539153435366260736),                     UINT64_MAX } },
    { { UINT64_C(              465641), UINT64_C(                7719) },
      {  INT64_C(                   6),  INT64_C(                  35) },
      { UINT64_C(            29801024), UINT64_C(     265222820462592) } },
    { { UINT64_C(                1746), UINT64_C(  220432428976506484) },
      {  INT64_C(                  63),  INT64_C(                   6) },
      {                     UINT64_MAX, UINT64_C(14107675454496414976) } },
    { { UINT64_C(      10272240971968), UINT64_C(              934985) },
      {  INT64_C(                  37),  INT64_C(                  15) },
      {                     UINT64_MAX, UINT64_C(         30637588480) } },
    { { UINT64_C( 1642524673382803956), UINT64_C(   17104657199364072) },
      {  INT64_C(                  37),  INT64_C(                  25) },
      {                     UINT64_MAX,                     UINT64_MAX } },
    { { UINT64_C( 2661600818130073547), UINT64_C(         82450256390) },
      {  INT64_C(                  39),  INT64_C(                  22) },
      {                     UINT64_MAX, UINT64_C(  345821440177602560) } },
    { { UINT64_C(                 421), UINT64_C(        131792432779) },
      {  INT64_C(                  21),  INT64_C(                  41) },
      { UINT64_C(           882900992),                     UINT64_MAX } },
    { { UINT64_C(            15025919), UINT64_C(          1212450988) },
      {  INT64_C(                  43),  INT64_C(                  24) },
      {                     UINT64_MAX, UINT64_C(   20341552115089408) } },
    { { UINT64_C(         29424283991), UINT64_C(                 503) },
      {  INT64_C(                  50),  INT64_C(                   5) },
      {                     UINT64_MAX, UINT64_C(               16096) } },
    { { UINT64_C( 9714795193090437851), UINT64_C(13993338141655914042) },
      { -INT64_C( 3690959013803690592),  INT64_C( 6731296505574406224) },
      { UINT64_C(                   0),                     UINT64_MAX } },
    { { UINT64_C( 6528236078453964112), UINT64_C(15993389747812559690) },
      {  INT64_C(  830565292831319908), -INT64_C( 3685498674268398086) },
      {                     UINT64_MAX, UINT64_C(  249896714809571245) } },
    { { UINT64_C( 4265321103177481655), UINT64_C( 4719033390021275234) },
      {  INT64_C( 3732781751244388102),  INT64_C( 1073697667889028510) },
      {                     UINT64_MAX, UINT64_C(                   0) } },
    { { UINT64_C(11291394230651896967), UINT64_C( 9594278535812095750) },
      {  INT64_C( 4583842679238369328),  INT64_C( 6797972356403383793) },
      {                     UINT64_MAX, UINT64_C(     292794144769656) } },
    { { UINT64_C( 6546697102772550915), UINT64_C(   48804912355481257) },
      { -INT64_C(  404471809981090685),  INT64_C(   39294330116160853) },
      { UINT64_C(                   0),                     UINT64_MAX } },
    { { UINT64_C(10774045081875669462), UINT64_C(12249344752209478447) },
      { -INT64_C( 4224322091642689442),  INT64_C( 1435096032352510958) },
      {                     UINT64_MAX, UINT64_C(      46727541931951) } },
    { { UINT64_C( 8097123867375315166), UINT64_C(16381682590491220871) },
      {  INT64_C( 4830860833519707349),  INT64_C( 6241171564598852685) },
      { UINT64_C(              920536),                     UINT64_MAX } },
    { { UINT64_C( 2734387143020436289), UINT64_C(11746279313602994330) },
      {  INT64_C( 5037262953186348366),  INT64_C( 8051992130350945775) },
      {                     UINT64_MAX, UINT64_C(      89616999157737) } },
    { { UINT64_C(17729514346208419399), UINT64_C( 6247646105506864707) },
      {  INT64_C( 9125104900390952038),  INT64_C( 2635912951649169911) },
      {                     UINT64_MAX, UINT64_C(   12202433799818095) } },
    { { UINT64_C(12453883884708988290), UINT64_C( 7661028707351260147) },
      {  INT64_C( 2673847552222645261),  INT64_C( 2872698040203543003) },
      {                     UINT64_MAX, UINT64_C(            55741320) } },
    { { UINT64_C(17256065326064789349), UINT64_C(13057127911015462598) },
      {  INT64_C( 4745506915982965640),  INT64_C( 7727287481782642287) },
      { UINT64_C(                   0),                     UINT64_MAX } },
    { { UINT64_C(16405401908391985855), UINT64_C( 6432795932960331240) },
      {  INT64_C( 8323754939831523292),  INT64_C( 1405901899144133905) },
      { UINT64_C(           238730017),                     UINT64_MAX } },
    { { UINT64_C( 6126718952254978822), UINT64_C( 8086822899830600463) },
      {  INT64_C( 5060134161410575041), -INT64_C( 8423173291084168782) },
      { UINT64_C(                   0), UINT64_C(                   0) } },
    { { UINT64_C( 8313280299612957083), UINT64_C( 3417262824581514087) },
      {  INT64_C(  456041500329189080),  INT64_C( 3314975410232341232) },
      { UINT64_C(             7560884), UINT64_C(      52143292611412) } },
    { { UINT64_C(14765214537518329873), UINT64_C(11778377344321273048) },
      { -INT64_C( 8454377338213209262), -INT64_C(  903250029353846090) },
      {                     UINT64_MAX, UINT64_C(                   0) } },
    { { UINT64_C( 1937199034496757170), UINT64_C( 3457310810590718604) },
      {  INT64_C( 7306389662280821312),  INT64_C( 1806266050378884412) },
      {                     UINT64_MAX,                     UINT64_MAX } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint64x2_t a = simde_vld1q_u64(test_vec[i].a);
    simde_int64x2_t b = simde_vld1q_s64(test_vec[i].b);
    simde_uint64x2_t r = simde_vqshlq_u64(a, b);

    simde_test_arm_neon_assert_equal_u64x2(r, simde_vld1q_u64(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 16 ; i++) {
    simde_uint64x2_t a = simde_test_arm_neon_random_u64x2();
    simde_int64x2_t b = simde_test_arm_neon_random_i64x2();

    a = simde_vshlq_u64(a, simde_vnegq_s64(simde_vandq_s64(simde_test_arm_neon_random_i64x2(), simde_vdupq_n_s64(63))));
    b = simde_vandq_s64(b, simde_vdupq_n_s64(63));

    simde_uint64x2_t r = simde_vqshlq_u64(a, b);

    simde_test_arm_neon_write_u64x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i64x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  for (int i = 0 ; i < 16 ; i++) {
    simde_uint64x2_t a = simde_test_arm_neon_random_u64x2();
    simde_int64x2_t b = simde_test_arm_neon_random_i64x2();

    simde_uint64x2_t r = simde_vqshlq_u64(a, b);

    simde_test_arm_neon_write_u64x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i64x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(vqshlb_s8)
SIMDE_TEST_FUNC_LIST_ENTRY(vqshlh_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vqshls_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vqshld_s64)
SIMDE_TEST_FUNC_LIST_ENTRY(vqshlb_u8)
SIMDE_TEST_FUNC_LIST_ENTRY(vqshlh_u16)
SIMDE_TEST_FUNC_LIST_ENTRY(vqshls_u32)
SIMDE_TEST_FUNC_LIST_ENTRY(vqshld_u64)

SIMDE_TEST_FUNC_LIST_ENTRY(vqshl_s8)
SIMDE_TEST_FUNC_LIST_ENTRY(vqshl_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vqshl_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vqshl_s64)
SIMDE_TEST_FUNC_LIST_ENTRY(vqshl_u8)
SIMDE_TEST_FUNC_LIST_ENTRY(vqshl_u16)
SIMDE_TEST_FUNC_LIST_ENTRY(vqshl_u32)
SIMDE_TEST_FUNC_LIST_ENTRY(vqshl_u64)

SIMDE_TEST_FUNC_LIST_ENTRY(vqshlq_s8)
SIMDE_TEST_FUNC_LIST_ENTRY(vqshlq_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vqshlq_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vqshlq_s64)
SIMDE_TEST_FUNC_LIST_ENTRY(vqshlq_u8)
SIMDE_TEST_FUNC_LIST_ENTRY(vqshlq_u16)
SIMDE_TEST_FUNC_LIST_ENTRY(vqshlq_u32)
SIMDE_TEST_FUNC_LIST_ENTRY(vqshlq_u64)
SIMDE_TEST_FUNC_LIST_END

#include "test-neon-footer.h"
