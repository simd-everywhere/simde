#define SIMDE_TEST_MIPS_MSA_INSN subv

#include "test-msa.h"
#include "../../../simde/mips/msa/subv.h"

static int
test_simde_subv_b (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int8_t a[16];
    int8_t b[16];
    int8_t r[16];
  } test_vec[] = {
    { { -INT8_C(  18),  INT8_C(  66),  INT8_C(  30),  INT8_C( 115),  INT8_C(  55), -INT8_C(  99),  INT8_C(  58),  INT8_C(  26),
         INT8_C(  81),  INT8_C(  58),  INT8_C(  72), -INT8_C( 114), -INT8_C( 105), -INT8_C( 101), -INT8_C(  68),  INT8_C(  32) },
      { -INT8_C(  48), -INT8_C(   4), -INT8_C(  85), -INT8_C(  25),  INT8_C(  41),  INT8_C( 101), -INT8_C(  25), -INT8_C(  62),
         INT8_C(  93), -INT8_C(  30), -INT8_C(  99),  INT8_C(  25), -INT8_C(  31), -INT8_C( 105), -INT8_C(  87), -INT8_C(  48) },
      {  INT8_C(  30),  INT8_C(  70),  INT8_C( 115), -INT8_C( 116),  INT8_C(  14),  INT8_C(  56),  INT8_C(  83),  INT8_C(  88),
        -INT8_C(  12),  INT8_C(  88), -INT8_C(  85),  INT8_C( 117), -INT8_C(  74),  INT8_C(   4),  INT8_C(  19),  INT8_C(  80) } },
    { { -INT8_C(  39), -INT8_C(  57),  INT8_C(  67),  INT8_C(  16),  INT8_C( 101),  INT8_C( 126),  INT8_C(  43), -INT8_C(  74),
        -INT8_C(  72),  INT8_C( 115),  INT8_C(  68),  INT8_C(  80),  INT8_C(  14),  INT8_C(   0),  INT8_C( 112), -INT8_C(  34) },
      { -INT8_C(   3),  INT8_C(  27), -INT8_C(  59),  INT8_C(  38), -INT8_C( 127), -INT8_C(  83), -INT8_C(  23), -INT8_C(  34),
        -INT8_C( 113), -INT8_C( 122), -INT8_C(   9),  INT8_C( 112),  INT8_C(  29), -INT8_C(  95),  INT8_C(  64), -INT8_C(   9) },
      { -INT8_C(  36), -INT8_C(  84),  INT8_C( 126), -INT8_C(  22), -INT8_C(  28), -INT8_C(  47),  INT8_C(  66), -INT8_C(  40),
         INT8_C(  41), -INT8_C(  19),  INT8_C(  77), -INT8_C(  32), -INT8_C(  15),  INT8_C(  95),  INT8_C(  48), -INT8_C(  25) } },
    { {  INT8_C( 104), -INT8_C( 124),  INT8_C(   7), -INT8_C(  51),  INT8_C(   2),  INT8_C(  50), -INT8_C( 125), -INT8_C(  70),
        -INT8_C(  91), -INT8_C(  57),  INT8_C(  10), -INT8_C(  77), -INT8_C(  56),  INT8_C( 122), -INT8_C( 111), -INT8_C(  59) },
      { -INT8_C( 106),  INT8_C(  87), -INT8_C(  21),  INT8_C(  23),  INT8_C(   4), -INT8_C(  44), -INT8_C(  11), -INT8_C( 109),
         INT8_C(  90), -INT8_C(  19),  INT8_C(   3),  INT8_C( 120), -INT8_C( 114),  INT8_C(  68),  INT8_C( 111), -INT8_C(  10) },
      { -INT8_C(  46),  INT8_C(  45),  INT8_C(  28), -INT8_C(  74), -INT8_C(   2),  INT8_C(  94), -INT8_C( 114),  INT8_C(  39),
         INT8_C(  75), -INT8_C(  38),  INT8_C(   7),  INT8_C(  59),  INT8_C(  58),  INT8_C(  54),  INT8_C(  34), -INT8_C(  49) } },
    { { -INT8_C(  56),  INT8_C( 118), -INT8_C(  60), -INT8_C(  54), -INT8_C(  87),  INT8_C(  71), -INT8_C( 124),  INT8_C(  78),
         INT8_C(  15), -INT8_C( 113),  INT8_C(   2), -INT8_C(  41),  INT8_C(   9), -INT8_C( 109), -INT8_C( 100), -INT8_C(  97) },
      { -INT8_C(  22), -INT8_C( 121), -INT8_C(  74), -INT8_C(  18),  INT8_C(  92), -INT8_C(  84), -INT8_C( 127), -INT8_C(  74),
        -INT8_C( 103), -INT8_C( 123),  INT8_C(  46),  INT8_C(  39), -INT8_C(  55), -INT8_C(  99),  INT8_C(  29), -INT8_C( 111) },
      { -INT8_C(  34), -INT8_C(  17),  INT8_C(  14), -INT8_C(  36),  INT8_C(  77), -INT8_C( 101),  INT8_C(   3), -INT8_C( 104),
         INT8_C( 118),  INT8_C(  10), -INT8_C(  44), -INT8_C(  80),  INT8_C(  64), -INT8_C(  10),      INT8_MAX,  INT8_C(  14) } },
    { {  INT8_C(  20), -INT8_C(  31),  INT8_C(  91), -INT8_C(  67),  INT8_C(  41), -INT8_C(  33),  INT8_C(  11),  INT8_C(  56),
         INT8_C( 110),  INT8_C(  13),  INT8_C(  15),  INT8_C( 120), -INT8_C(  95), -INT8_C(  85),  INT8_C(  23), -INT8_C( 117) },
      {  INT8_C(  50), -INT8_C(  50),  INT8_C( 122), -INT8_C( 114),  INT8_C( 122), -INT8_C(   5),  INT8_C(  69),  INT8_C(  19),
             INT8_MIN,  INT8_C( 115),  INT8_C(  58),  INT8_C(  73),  INT8_C(  17),  INT8_C(  87), -INT8_C(  38),  INT8_C(  37) },
      { -INT8_C(  30),  INT8_C(  19), -INT8_C(  31),  INT8_C(  47), -INT8_C(  81), -INT8_C(  28), -INT8_C(  58),  INT8_C(  37),
        -INT8_C(  18), -INT8_C( 102), -INT8_C(  43),  INT8_C(  47), -INT8_C( 112),  INT8_C(  84),  INT8_C(  61),  INT8_C( 102) } },
    { {  INT8_C(  57),  INT8_C(  53), -INT8_C(  30),  INT8_C(  98),  INT8_C(  21), -INT8_C(  19), -INT8_C( 102), -INT8_C( 125),
        -INT8_C(   5), -INT8_C(  87), -INT8_C(   5), -INT8_C( 100),  INT8_C(  84),  INT8_C(  19),  INT8_C(  39), -INT8_C( 122) },
      { -INT8_C(  31), -INT8_C(  95),  INT8_C(  21),  INT8_C(  91), -INT8_C(  99),  INT8_C(  90),  INT8_C( 110),  INT8_C(  29),
        -INT8_C(  51), -INT8_C(  88),  INT8_C( 103), -INT8_C(  34), -INT8_C(   1),  INT8_C(  65),  INT8_C(   3),  INT8_C(  56) },
      {  INT8_C(  88), -INT8_C( 108), -INT8_C(  51),  INT8_C(   7),  INT8_C( 120), -INT8_C( 109),  INT8_C(  44),  INT8_C( 102),
         INT8_C(  46),  INT8_C(   1), -INT8_C( 108), -INT8_C(  66),  INT8_C(  85), -INT8_C(  46),  INT8_C(  36),  INT8_C(  78) } },
    { {  INT8_C( 119), -INT8_C(  27), -INT8_C( 102), -INT8_C( 116), -INT8_C(  45),  INT8_C(  52),  INT8_C(  15), -INT8_C(  50),
        -INT8_C(  35),  INT8_C(  11),  INT8_C( 106),  INT8_C(  49),  INT8_C(  30), -INT8_C( 111), -INT8_C(  72), -INT8_C(   1) },
      {  INT8_C(  51), -INT8_C(  51),  INT8_C(  90), -INT8_C(  48),  INT8_C(  39), -INT8_C(  56), -INT8_C(  19), -INT8_C(  12),
         INT8_C( 112),  INT8_C(  84), -INT8_C(  45),  INT8_C( 111), -INT8_C( 106), -INT8_C(  42), -INT8_C(  88),  INT8_C(  13) },
      {  INT8_C(  68),  INT8_C(  24),  INT8_C(  64), -INT8_C(  68), -INT8_C(  84),  INT8_C( 108),  INT8_C(  34), -INT8_C(  38),
         INT8_C( 109), -INT8_C(  73), -INT8_C( 105), -INT8_C(  62), -INT8_C( 120), -INT8_C(  69),  INT8_C(  16), -INT8_C(  14) } },
    { { -INT8_C(  68),  INT8_C(  66), -INT8_C( 103), -INT8_C( 113),  INT8_C( 119), -INT8_C(  88),  INT8_C(  93),  INT8_C(  84),
        -INT8_C(  77), -INT8_C(  57), -INT8_C( 122), -INT8_C(  47),  INT8_C(  88),  INT8_C(  62), -INT8_C(  48), -INT8_C( 117) },
      {  INT8_C(  11),  INT8_C(  42),  INT8_C(  91),  INT8_C(  50), -INT8_C(  14),  INT8_C(  73),  INT8_C(  38),  INT8_C(  98),
        -INT8_C(  99), -INT8_C(   7), -INT8_C(  46),  INT8_C(  51), -INT8_C(  48),  INT8_C( 122),  INT8_C(  64), -INT8_C( 116) },
      { -INT8_C(  79),  INT8_C(  24),  INT8_C(  62),  INT8_C(  93), -INT8_C( 123),  INT8_C(  95),  INT8_C(  55), -INT8_C(  14),
         INT8_C(  22), -INT8_C(  50), -INT8_C(  76), -INT8_C(  98), -INT8_C( 120), -INT8_C(  60), -INT8_C( 112), -INT8_C(   1) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_v16i8 a = simde_msa_ld_b(test_vec[i].a, 0);
    simde_v16i8 b = simde_msa_ld_b(test_vec[i].b, 0);
    simde_v16i8 r = simde_msa_subv_b(a, b);

    simde_test_msa_v16i8_assert_equal(r, simde_msa_ld_b(test_vec[i].r, 0));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_v16i8 a = simde_test_msa_v16i8_random();
    simde_v16i8 b = simde_test_msa_v16i8_random();
    simde_v16i8 r = simde_msa_subv_b(a, b);

    simde_test_msa_v16i8_write(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_msa_v16i8_write(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_msa_v16i8_write(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_subv_h (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int16_t a[8];
    int16_t b[8];
    int16_t r[8];
  } test_vec[] = {
    { { -INT16_C(  9796),  INT16_C( 13083),  INT16_C( 30850),  INT16_C( 13704),  INT16_C(  3647), -INT16_C( 26873), -INT16_C( 10420),  INT16_C( 22307) },
      {  INT16_C( 32258), -INT16_C(  2935), -INT16_C( 20537),  INT16_C( 25943),  INT16_C( 10665),  INT16_C( 31128), -INT16_C(  9821),  INT16_C( 24325) },
      {  INT16_C( 23482),  INT16_C( 16018), -INT16_C( 14149), -INT16_C( 12239), -INT16_C(  7018),  INT16_C(  7535), -INT16_C(   599), -INT16_C(  2018) } },
    { {  INT16_C(  8370),  INT16_C( 13459),  INT16_C(  7064), -INT16_C( 10390),  INT16_C( 28969),  INT16_C( 30062), -INT16_C( 28344),  INT16_C( 19148) },
      {  INT16_C( 21776), -INT16_C( 10433), -INT16_C( 27132), -INT16_C( 21188), -INT16_C( 10817),  INT16_C( 25126),  INT16_C( 11182),  INT16_C( 24769) },
      { -INT16_C( 13406),  INT16_C( 23892), -INT16_C( 31340),  INT16_C( 10798), -INT16_C( 25750),  INT16_C(  4936),  INT16_C( 26010), -INT16_C(  5621) } },
    { {  INT16_C( 21579), -INT16_C(  7275), -INT16_C(   145), -INT16_C( 26438),  INT16_C( 10608), -INT16_C( 18419), -INT16_C(  9798), -INT16_C( 13821) },
      {  INT16_C( 16942),  INT16_C( 13218), -INT16_C(  8488), -INT16_C( 26656),  INT16_C(  1971),  INT16_C( 25081), -INT16_C( 17870),  INT16_C( 32450) },
      {  INT16_C(  4637), -INT16_C( 20493),  INT16_C(  8343),  INT16_C(   218),  INT16_C(  8637),  INT16_C( 22036),  INT16_C(  8072),  INT16_C( 19265) } },
    { {  INT16_C( 22287),  INT16_C( 32353),  INT16_C(  7254), -INT16_C( 14825),  INT16_C(  9285), -INT16_C(   130), -INT16_C( 32258),  INT16_C( 11466) },
      {  INT16_C( 27843), -INT16_C( 25761),  INT16_C( 16458), -INT16_C(   462),  INT16_C( 11079),  INT16_C( 31071),  INT16_C(  8678), -INT16_C(  2569) },
      { -INT16_C(  5556), -INT16_C(  7422), -INT16_C(  9204), -INT16_C( 14363), -INT16_C(  1794), -INT16_C( 31201),  INT16_C( 24600),  INT16_C( 14035) } },
    { {  INT16_C( 22904), -INT16_C( 12685), -INT16_C( 30091), -INT16_C( 17772),  INT16_C(  5039), -INT16_C( 21063), -INT16_C( 31852),  INT16_C( 22745) },
      {  INT16_C( 14831),  INT16_C( 15091),  INT16_C(  9849), -INT16_C( 16328), -INT16_C( 26799),  INT16_C( 14137),  INT16_C( 12729),  INT16_C( 12588) },
      {  INT16_C(  8073), -INT16_C( 27776),  INT16_C( 25596), -INT16_C(  1444),  INT16_C( 31838),  INT16_C( 30336),  INT16_C( 20955),  INT16_C( 10157) } },
    { { -INT16_C( 24438), -INT16_C(   256), -INT16_C( 27606), -INT16_C(  9799),  INT16_C( 29351),  INT16_C( 15494),  INT16_C( 24822), -INT16_C(  6764) },
      { -INT16_C( 30823),  INT16_C(  4639),  INT16_C( 22445), -INT16_C(    46),  INT16_C(  3055), -INT16_C( 22474),  INT16_C( 25404), -INT16_C( 14631) },
      {  INT16_C(  6385), -INT16_C(  4895),  INT16_C( 15485), -INT16_C(  9753),  INT16_C( 26296), -INT16_C( 27568), -INT16_C(   582),  INT16_C(  7867) } },
    { { -INT16_C(  9981),  INT16_C( 11717),  INT16_C( 32366),  INT16_C(  5383), -INT16_C( 29199), -INT16_C(  6319), -INT16_C(  6675), -INT16_C( 31028) },
      { -INT16_C(  5011),  INT16_C(  6808),  INT16_C( 27203),  INT16_C( 12825),  INT16_C( 20598), -INT16_C( 19750), -INT16_C( 19277), -INT16_C( 18823) },
      { -INT16_C(  4970),  INT16_C(  4909),  INT16_C(  5163), -INT16_C(  7442),  INT16_C( 15739),  INT16_C( 13431),  INT16_C( 12602), -INT16_C( 12205) } },
    { {  INT16_C( 16013), -INT16_C(  1053), -INT16_C(  5443), -INT16_C( 20975),  INT16_C( 25208),  INT16_C( 26005),  INT16_C( 24904), -INT16_C( 18964) },
      { -INT16_C( 31667), -INT16_C( 28209), -INT16_C(  5649),  INT16_C( 26051), -INT16_C( 25031), -INT16_C(  5097), -INT16_C( 28590), -INT16_C(  8286) },
      { -INT16_C( 17856),  INT16_C( 27156),  INT16_C(   206),  INT16_C( 18510), -INT16_C( 15297),  INT16_C( 31102), -INT16_C( 12042), -INT16_C( 10678) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_v8i16 a = simde_msa_ld_h(test_vec[i].a, 0);
    simde_v8i16 b = simde_msa_ld_h(test_vec[i].b, 0);
    simde_v8i16 r = simde_msa_subv_h(a, b);

    simde_test_msa_v8i16_assert_equal(r, simde_msa_ld_h(test_vec[i].r, 0));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_v8i16 a = simde_test_msa_v8i16_random();
    simde_v8i16 b = simde_test_msa_v8i16_random();
    simde_v8i16 r = simde_msa_subv_h(a, b);

    simde_test_msa_v8i16_write(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_msa_v8i16_write(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_msa_v8i16_write(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_subv_w (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int32_t a[4];
    int32_t b[4];
    int32_t r[4];
  } test_vec[] = {
    { { -INT32_C(  1931770417), -INT32_C(   398791568), -INT32_C(  1773285554),  INT32_C(  2118859056) },
      { -INT32_C(  1391518786),  INT32_C(  1024643588), -INT32_C(  1037489808), -INT32_C(  1985819718) },
      { -INT32_C(   540251631), -INT32_C(  1423435156), -INT32_C(   735795746), -INT32_C(   190288522) } },
    { { -INT32_C(  1072333488), -INT32_C(  1213706391),  INT32_C(  1313797662), -INT32_C(   305358545) },
      { -INT32_C(  1197810764),  INT32_C(   519417006), -INT32_C(  1864294698),  INT32_C(   974750697) },
      {  INT32_C(   125477276), -INT32_C(  1733123397), -INT32_C(  1116874936), -INT32_C(  1280109242) } },
    { {  INT32_C(  1778003456), -INT32_C(  1692359811), -INT32_C(   924225895), -INT32_C(  1128876536) },
      {  INT32_C(  1064652945), -INT32_C(   748786947),  INT32_C(  1919106953), -INT32_C(  1028883262) },
      {  INT32_C(   713350511), -INT32_C(   943572864),  INT32_C(  1451634448), -INT32_C(    99993274) } },
    { {  INT32_C(   657172394), -INT32_C(   473806006), -INT32_C(  1028936774), -INT32_C(   209821343) },
      { -INT32_C(  1355615310), -INT32_C(   410873762), -INT32_C(  1856379441),  INT32_C(   189990497) },
      {  INT32_C(  2012787704), -INT32_C(    62932244),  INT32_C(   827442667), -INT32_C(   399811840) } },
    { { -INT32_C(   147685715), -INT32_C(  2066025270),  INT32_C(    21398943), -INT32_C(  1712012057) },
      {  INT32_C(   373827256), -INT32_C(  2030187849),  INT32_C(   270030511),  INT32_C(   152791900) },
      { -INT32_C(   521512971), -INT32_C(    35837421), -INT32_C(   248631568), -INT32_C(  1864803957) } },
    { { -INT32_C(  1275048470), -INT32_C(   533145023),  INT32_C(  1205960288), -INT32_C(    85928638) },
      { -INT32_C(  1290786564), -INT32_C(  1590096398), -INT32_C(  1062121116), -INT32_C(  1479881539) },
      {  INT32_C(    15738094),  INT32_C(  1056951375), -INT32_C(  2026885892),  INT32_C(  1393952901) } },
    { {  INT32_C(  1515964953),  INT32_C(    87724965),  INT32_C(  1397496849), -INT32_C(   313643791) },
      {  INT32_C(  1184915028), -INT32_C(   790111636), -INT32_C(   393177045),  INT32_C(  2106546788) },
      {  INT32_C(   331049925),  INT32_C(   877836601),  INT32_C(  1790673894),  INT32_C(  1874776717) } },
    { { -INT32_C(   891819483), -INT32_C(  1899032195),  INT32_C(   534911789), -INT32_C(  1693700025) },
      { -INT32_C(    85873266), -INT32_C(  1295333241), -INT32_C(   996451488), -INT32_C(   633263435) },
      { -INT32_C(   805946217), -INT32_C(   603698954),  INT32_C(  1531363277), -INT32_C(  1060436590) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_v4i32 a = simde_msa_ld_w(test_vec[i].a, 0);
    simde_v4i32 b = simde_msa_ld_w(test_vec[i].b, 0);
    simde_v4i32 r = simde_msa_subv_w(a, b);

    simde_test_msa_v4i32_assert_equal(r, simde_msa_ld_w(test_vec[i].r, 0));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_v4i32 a = simde_test_msa_v4i32_random();
    simde_v4i32 b = simde_test_msa_v4i32_random();
    simde_v4i32 r = simde_msa_subv_w(a, b);

    simde_test_msa_v4i32_write(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_msa_v4i32_write(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_msa_v4i32_write(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_subv_d (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int64_t a[2];
    int64_t b[2];
    int64_t r[2];
  } test_vec[] = {
    { {  INT64_C( 6278425977922263061), -INT64_C( 4507960067861642354) },
      {  INT64_C( 8748671196141998383),  INT64_C( 4859804211480429793) },
      { -INT64_C( 2470245218219735322),  INT64_C( 9078979794367479469) } },
    { {  INT64_C( 1736128352392451734),  INT64_C( 4606722888134659578) },
      {  INT64_C( 1315717609080335023), -INT64_C( 7650459086816182174) },
      {  INT64_C(  420410743312116711), -INT64_C( 6189562098758709864) } },
    { { -INT64_C( 7218587810849773007), -INT64_C( 3654751232963591943) },
      { -INT64_C(   97432554716119711), -INT64_C( 7283337193273209255) },
      { -INT64_C( 7121155256133653296),  INT64_C( 3628585960309617312) } },
    { { -INT64_C( 6464029213235789554),  INT64_C( 3230196705293964263) },
      { -INT64_C( 7220005489000683213), -INT64_C( 3623462838272303950) },
      {  INT64_C(  755976275764893659),  INT64_C( 6853659543566268213) } },
    { {  INT64_C( 1906650137799494433),  INT64_C( 5679868276337747163) },
      { -INT64_C( 6468599578418638756),  INT64_C( 3302113845312564550) },
      {  INT64_C( 8375249716218133189),  INT64_C( 2377754431025182613) } },
    { { -INT64_C(  878359051367591806),  INT64_C( 4466845022479314581) },
      {  INT64_C( 5374506316278209276),  INT64_C( 5871607387480151874) },
      { -INT64_C( 6252865367645801082), -INT64_C( 1404762365000837293) } },
    { {  INT64_C( 9114957894881015923),  INT64_C( 9214975631965427908) },
      {  INT64_C( 1555155651371449670),  INT64_C( 8898515863974765917) },
      {  INT64_C( 7559802243509566253),  INT64_C(  316459767990661991) } },
    { {  INT64_C( 2144140416516523097),  INT64_C( 7034521579396722588) },
      {  INT64_C( 8163407730106371938), -INT64_C( 1610006560730403035) },
      { -INT64_C( 6019267313589848841),  INT64_C( 8644528140127125623) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_v2i64 a = simde_msa_ld_d(test_vec[i].a, 0);
    simde_v2i64 b = simde_msa_ld_d(test_vec[i].b, 0);
    simde_v2i64 r = simde_msa_subv_d(a, b);

    simde_test_msa_v2i64_assert_equal(r, simde_msa_ld_d(test_vec[i].r, 0));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_v2i64 a = simde_test_msa_v2i64_random();
    simde_v2i64 b = simde_test_msa_v2i64_random();
    simde_v2i64 r = simde_msa_subv_d(a, b);

    simde_test_msa_v2i64_write(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_msa_v2i64_write(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_msa_v2i64_write(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(subv_b)
SIMDE_TEST_FUNC_LIST_ENTRY(subv_h)
SIMDE_TEST_FUNC_LIST_ENTRY(subv_w)
SIMDE_TEST_FUNC_LIST_ENTRY(subv_d)
SIMDE_TEST_FUNC_LIST_END

#include "test-msa-footer.h"
