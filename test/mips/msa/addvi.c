#define SIMDE_TEST_MIPS_MSA_INSN addvi

#include "test-msa.h"
#include "../../../simde/mips/msa/addvi.h"

static int
test_simde_addvi_b (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int8_t   a[16];
    int8_t  r3[16];
    int8_t r17[16];
    int8_t r29[16];
  } test_vec[] = {
    { {  INT8_C(  79), -INT8_C(  20), -INT8_C(   1),  INT8_C(  31),  INT8_C(  18),  INT8_C(  24),  INT8_C(  46), -INT8_C(  99),
        -INT8_C(  71),  INT8_C(  81),  INT8_C(   7), -INT8_C( 117), -INT8_C(  53),  INT8_C(  76), -INT8_C(  40),  INT8_C(  23) },
      {  INT8_C(  82), -INT8_C(  17),  INT8_C(   2),  INT8_C(  34),  INT8_C(  21),  INT8_C(  27),  INT8_C(  49), -INT8_C(  96),
        -INT8_C(  68),  INT8_C(  84),  INT8_C(  10), -INT8_C( 114), -INT8_C(  50),  INT8_C(  79), -INT8_C(  37),  INT8_C(  26) },
      {  INT8_C(  96), -INT8_C(   3),  INT8_C(  16),  INT8_C(  48),  INT8_C(  35),  INT8_C(  41),  INT8_C(  63), -INT8_C(  82),
        -INT8_C(  54),  INT8_C(  98),  INT8_C(  24), -INT8_C( 100), -INT8_C(  36),  INT8_C(  93), -INT8_C(  23),  INT8_C(  40) },
      {  INT8_C( 108),  INT8_C(   9),  INT8_C(  28),  INT8_C(  60),  INT8_C(  47),  INT8_C(  53),  INT8_C(  75), -INT8_C(  70),
        -INT8_C(  42),  INT8_C( 110),  INT8_C(  36), -INT8_C(  88), -INT8_C(  24),  INT8_C( 105), -INT8_C(  11),  INT8_C(  52) } },
    { { -INT8_C( 112), -INT8_C(  17), -INT8_C( 121),  INT8_C(  54), -INT8_C(  93), -INT8_C(  22), -INT8_C(   1),  INT8_C( 112),
         INT8_C(  85),  INT8_C( 125),  INT8_C(  66),  INT8_C(  49),  INT8_C(  24),  INT8_C(  75), -INT8_C(  66),  INT8_C( 104) },
      { -INT8_C( 109), -INT8_C(  14), -INT8_C( 118),  INT8_C(  57), -INT8_C(  90), -INT8_C(  19),  INT8_C(   2),  INT8_C( 115),
         INT8_C(  88),      INT8_MIN,  INT8_C(  69),  INT8_C(  52),  INT8_C(  27),  INT8_C(  78), -INT8_C(  63),  INT8_C( 107) },
      { -INT8_C(  95),  INT8_C(   0), -INT8_C( 104),  INT8_C(  71), -INT8_C(  76), -INT8_C(   5),  INT8_C(  16), -INT8_C( 127),
         INT8_C( 102), -INT8_C( 114),  INT8_C(  83),  INT8_C(  66),  INT8_C(  41),  INT8_C(  92), -INT8_C(  49),  INT8_C( 121) },
      { -INT8_C(  83),  INT8_C(  12), -INT8_C(  92),  INT8_C(  83), -INT8_C(  64),  INT8_C(   7),  INT8_C(  28), -INT8_C( 115),
         INT8_C( 114), -INT8_C( 102),  INT8_C(  95),  INT8_C(  78),  INT8_C(  53),  INT8_C( 104), -INT8_C(  37), -INT8_C( 123) } },
    { {  INT8_C(  55), -INT8_C(  67), -INT8_C( 121),  INT8_C(  73), -INT8_C(  43), -INT8_C(  75), -INT8_C(  25), -INT8_C( 114),
         INT8_C(   6), -INT8_C(  18),  INT8_C(  25), -INT8_C(  47),  INT8_C(  58), -INT8_C(  15), -INT8_C(  24), -INT8_C(  53) },
      {  INT8_C(  58), -INT8_C(  64), -INT8_C( 118),  INT8_C(  76), -INT8_C(  40), -INT8_C(  72), -INT8_C(  22), -INT8_C( 111),
         INT8_C(   9), -INT8_C(  15),  INT8_C(  28), -INT8_C(  44),  INT8_C(  61), -INT8_C(  12), -INT8_C(  21), -INT8_C(  50) },
      {  INT8_C(  72), -INT8_C(  50), -INT8_C( 104),  INT8_C(  90), -INT8_C(  26), -INT8_C(  58), -INT8_C(   8), -INT8_C(  97),
         INT8_C(  23), -INT8_C(   1),  INT8_C(  42), -INT8_C(  30),  INT8_C(  75),  INT8_C(   2), -INT8_C(   7), -INT8_C(  36) },
      {  INT8_C(  84), -INT8_C(  38), -INT8_C(  92),  INT8_C( 102), -INT8_C(  14), -INT8_C(  46),  INT8_C(   4), -INT8_C(  85),
         INT8_C(  35),  INT8_C(  11),  INT8_C(  54), -INT8_C(  18),  INT8_C(  87),  INT8_C(  14),  INT8_C(   5), -INT8_C(  24) } },
    { { -INT8_C(  31),  INT8_C( 111),  INT8_C(   1), -INT8_C( 124),  INT8_C(  89),  INT8_C(   0), -INT8_C(  12), -INT8_C(  82),
         INT8_C( 125),  INT8_C(  54), -INT8_C(  33), -INT8_C( 106), -INT8_C( 126), -INT8_C(  99), -INT8_C(   2), -INT8_C(  71) },
      { -INT8_C(  28),  INT8_C( 114),  INT8_C(   4), -INT8_C( 121),  INT8_C(  92),  INT8_C(   3), -INT8_C(   9), -INT8_C(  79),
             INT8_MIN,  INT8_C(  57), -INT8_C(  30), -INT8_C( 103), -INT8_C( 123), -INT8_C(  96),  INT8_C(   1), -INT8_C(  68) },
      { -INT8_C(  14),      INT8_MIN,  INT8_C(  18), -INT8_C( 107),  INT8_C( 106),  INT8_C(  17),  INT8_C(   5), -INT8_C(  65),
        -INT8_C( 114),  INT8_C(  71), -INT8_C(  16), -INT8_C(  89), -INT8_C( 109), -INT8_C(  82),  INT8_C(  15), -INT8_C(  54) },
      { -INT8_C(   2), -INT8_C( 116),  INT8_C(  30), -INT8_C(  95),  INT8_C( 118),  INT8_C(  29),  INT8_C(  17), -INT8_C(  53),
        -INT8_C( 102),  INT8_C(  83), -INT8_C(   4), -INT8_C(  77), -INT8_C(  97), -INT8_C(  70),  INT8_C(  27), -INT8_C(  42) } },
    { {  INT8_C(  90), -INT8_C( 123),  INT8_C(   3),  INT8_C(  48),  INT8_C(  58), -INT8_C(  22), -INT8_C(  66),  INT8_C(  64),
        -INT8_C(  40), -INT8_C(  40),  INT8_C(  17),  INT8_C(  18), -INT8_C(  55), -INT8_C(   7), -INT8_C(  35), -INT8_C(  86) },
      {  INT8_C(  93), -INT8_C( 120),  INT8_C(   6),  INT8_C(  51),  INT8_C(  61), -INT8_C(  19), -INT8_C(  63),  INT8_C(  67),
        -INT8_C(  37), -INT8_C(  37),  INT8_C(  20),  INT8_C(  21), -INT8_C(  52), -INT8_C(   4), -INT8_C(  32), -INT8_C(  83) },
      {  INT8_C( 107), -INT8_C( 106),  INT8_C(  20),  INT8_C(  65),  INT8_C(  75), -INT8_C(   5), -INT8_C(  49),  INT8_C(  81),
        -INT8_C(  23), -INT8_C(  23),  INT8_C(  34),  INT8_C(  35), -INT8_C(  38),  INT8_C(  10), -INT8_C(  18), -INT8_C(  69) },
      {  INT8_C( 119), -INT8_C(  94),  INT8_C(  32),  INT8_C(  77),  INT8_C(  87),  INT8_C(   7), -INT8_C(  37),  INT8_C(  93),
        -INT8_C(  11), -INT8_C(  11),  INT8_C(  46),  INT8_C(  47), -INT8_C(  26),  INT8_C(  22), -INT8_C(   6), -INT8_C(  57) } },
    { {  INT8_C( 104), -INT8_C(  34),  INT8_C(  46), -INT8_C(  63), -INT8_C(  34),  INT8_C(  34),  INT8_C( 111),  INT8_C(  92),
         INT8_C(  89),  INT8_C(  78), -INT8_C(  14), -INT8_C(  37), -INT8_C(  21), -INT8_C(  16), -INT8_C( 108),  INT8_C(  69) },
      {  INT8_C( 107), -INT8_C(  31),  INT8_C(  49), -INT8_C(  60), -INT8_C(  31),  INT8_C(  37),  INT8_C( 114),  INT8_C(  95),
         INT8_C(  92),  INT8_C(  81), -INT8_C(  11), -INT8_C(  34), -INT8_C(  18), -INT8_C(  13), -INT8_C( 105),  INT8_C(  72) },
      {  INT8_C( 121), -INT8_C(  17),  INT8_C(  63), -INT8_C(  46), -INT8_C(  17),  INT8_C(  51),      INT8_MIN,  INT8_C( 109),
         INT8_C( 106),  INT8_C(  95),  INT8_C(   3), -INT8_C(  20), -INT8_C(   4),  INT8_C(   1), -INT8_C(  91),  INT8_C(  86) },
      { -INT8_C( 123), -INT8_C(   5),  INT8_C(  75), -INT8_C(  34), -INT8_C(   5),  INT8_C(  63), -INT8_C( 116),  INT8_C( 121),
         INT8_C( 118),  INT8_C( 107),  INT8_C(  15), -INT8_C(   8),  INT8_C(   8),  INT8_C(  13), -INT8_C(  79),  INT8_C(  98) } },
    { {  INT8_C( 117), -INT8_C( 105),  INT8_C( 117), -INT8_C(  81), -INT8_C( 127),  INT8_C(  52), -INT8_C(  17),  INT8_C(  89),
         INT8_C(  12),  INT8_C(   0),  INT8_C( 108), -INT8_C(  43), -INT8_C(   7),  INT8_C(  73),      INT8_MIN,  INT8_C(  97) },
      {  INT8_C( 120), -INT8_C( 102),  INT8_C( 120), -INT8_C(  78), -INT8_C( 124),  INT8_C(  55), -INT8_C(  14),  INT8_C(  92),
         INT8_C(  15),  INT8_C(   3),  INT8_C( 111), -INT8_C(  40), -INT8_C(   4),  INT8_C(  76), -INT8_C( 125),  INT8_C( 100) },
      { -INT8_C( 122), -INT8_C(  88), -INT8_C( 122), -INT8_C(  64), -INT8_C( 110),  INT8_C(  69),  INT8_C(   0),  INT8_C( 106),
         INT8_C(  29),  INT8_C(  17),  INT8_C( 125), -INT8_C(  26),  INT8_C(  10),  INT8_C(  90), -INT8_C( 111),  INT8_C( 114) },
      { -INT8_C( 110), -INT8_C(  76), -INT8_C( 110), -INT8_C(  52), -INT8_C(  98),  INT8_C(  81),  INT8_C(  12),  INT8_C( 118),
         INT8_C(  41),  INT8_C(  29), -INT8_C( 119), -INT8_C(  14),  INT8_C(  22),  INT8_C( 102), -INT8_C(  99),  INT8_C( 126) } },
    { {  INT8_C(  40), -INT8_C(  82),  INT8_C(  34),  INT8_C(   6), -INT8_C(  47), -INT8_C( 111),  INT8_C(  98),  INT8_C(  42),
        -INT8_C(  33),  INT8_C(  84),  INT8_C(   5), -INT8_C(  54),  INT8_C(  68), -INT8_C( 103),  INT8_C(  15), -INT8_C(  71) },
      {  INT8_C(  43), -INT8_C(  79),  INT8_C(  37),  INT8_C(   9), -INT8_C(  44), -INT8_C( 108),  INT8_C( 101),  INT8_C(  45),
        -INT8_C(  30),  INT8_C(  87),  INT8_C(   8), -INT8_C(  51),  INT8_C(  71), -INT8_C( 100),  INT8_C(  18), -INT8_C(  68) },
      {  INT8_C(  57), -INT8_C(  65),  INT8_C(  51),  INT8_C(  23), -INT8_C(  30), -INT8_C(  94),  INT8_C( 115),  INT8_C(  59),
        -INT8_C(  16),  INT8_C( 101),  INT8_C(  22), -INT8_C(  37),  INT8_C(  85), -INT8_C(  86),  INT8_C(  32), -INT8_C(  54) },
      {  INT8_C(  69), -INT8_C(  53),  INT8_C(  63),  INT8_C(  35), -INT8_C(  18), -INT8_C(  82),      INT8_MAX,  INT8_C(  71),
        -INT8_C(   4),  INT8_C( 113),  INT8_C(  34), -INT8_C(  25),  INT8_C(  97), -INT8_C(  74),  INT8_C(  44), -INT8_C(  42) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_v16i8   a = simde_msa_ld_b(test_vec[i].a, 0);
    simde_v16i8  r3 = simde_msa_addvi_b(a, 3);
    simde_v16i8 r17 = simde_msa_addvi_b(a, 17);
    simde_v16i8 r29 = simde_msa_addvi_b(a, 29);

    simde_test_msa_v16i8_assert_equal( r3, simde_msa_ld_b(test_vec[i].r3 , 0));
    simde_test_msa_v16i8_assert_equal(r17, simde_msa_ld_b(test_vec[i].r17, 0));
    simde_test_msa_v16i8_assert_equal(r29, simde_msa_ld_b(test_vec[i].r29, 0));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_v16i8   a = simde_test_msa_v16i8_random();
    simde_v16i8  r3 = simde_msa_addvi_b(a, 3);
    simde_v16i8 r17 = simde_msa_addvi_b(a, 17);
    simde_v16i8 r29 = simde_msa_addvi_b(a, 29);

    simde_test_msa_v16i8_write(2,   a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_msa_v16i8_write(2,  r3, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_msa_v16i8_write(2, r17, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_msa_v16i8_write(2, r29, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_addvi_h (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int16_t   a[8];
    int16_t  r3[8];
    int16_t r17[8];
    int16_t r29[8];
  } test_vec[] = {
    { {  INT16_C( 16989), -INT16_C( 12326),  INT16_C( 29939),  INT16_C(  3154), -INT16_C( 30101),  INT16_C( 13133),  INT16_C( 10430), -INT16_C(  7772) },
      {  INT16_C( 16992), -INT16_C( 12323),  INT16_C( 29942),  INT16_C(  3157), -INT16_C( 30098),  INT16_C( 13136),  INT16_C( 10433), -INT16_C(  7769) },
      {  INT16_C( 17006), -INT16_C( 12309),  INT16_C( 29956),  INT16_C(  3171), -INT16_C( 30084),  INT16_C( 13150),  INT16_C( 10447), -INT16_C(  7755) },
      {  INT16_C( 17018), -INT16_C( 12297),  INT16_C( 29968),  INT16_C(  3183), -INT16_C( 30072),  INT16_C( 13162),  INT16_C( 10459), -INT16_C(  7743) } },
    { { -INT16_C( 11094), -INT16_C(  2870),  INT16_C(  2203),  INT16_C( 25357), -INT16_C( 27214),  INT16_C( 19476), -INT16_C(  4045), -INT16_C( 28512) },
      { -INT16_C( 11091), -INT16_C(  2867),  INT16_C(  2206),  INT16_C( 25360), -INT16_C( 27211),  INT16_C( 19479), -INT16_C(  4042), -INT16_C( 28509) },
      { -INT16_C( 11077), -INT16_C(  2853),  INT16_C(  2220),  INT16_C( 25374), -INT16_C( 27197),  INT16_C( 19493), -INT16_C(  4028), -INT16_C( 28495) },
      { -INT16_C( 11065), -INT16_C(  2841),  INT16_C(  2232),  INT16_C( 25386), -INT16_C( 27185),  INT16_C( 19505), -INT16_C(  4016), -INT16_C( 28483) } },
    { {  INT16_C( 31538),  INT16_C(  9567), -INT16_C( 19985),  INT16_C( 23346),  INT16_C( 32571), -INT16_C(  1394),  INT16_C( 13223),  INT16_C( 21211) },
      {  INT16_C( 31541),  INT16_C(  9570), -INT16_C( 19982),  INT16_C( 23349),  INT16_C( 32574), -INT16_C(  1391),  INT16_C( 13226),  INT16_C( 21214) },
      {  INT16_C( 31555),  INT16_C(  9584), -INT16_C( 19968),  INT16_C( 23363),  INT16_C( 32588), -INT16_C(  1377),  INT16_C( 13240),  INT16_C( 21228) },
      {  INT16_C( 31567),  INT16_C(  9596), -INT16_C( 19956),  INT16_C( 23375),  INT16_C( 32600), -INT16_C(  1365),  INT16_C( 13252),  INT16_C( 21240) } },
    { { -INT16_C( 23289), -INT16_C( 23994),  INT16_C( 21421),  INT16_C( 24325),  INT16_C(  6632),  INT16_C(  7083),  INT16_C( 19465),  INT16_C( 15275) },
      { -INT16_C( 23286), -INT16_C( 23991),  INT16_C( 21424),  INT16_C( 24328),  INT16_C(  6635),  INT16_C(  7086),  INT16_C( 19468),  INT16_C( 15278) },
      { -INT16_C( 23272), -INT16_C( 23977),  INT16_C( 21438),  INT16_C( 24342),  INT16_C(  6649),  INT16_C(  7100),  INT16_C( 19482),  INT16_C( 15292) },
      { -INT16_C( 23260), -INT16_C( 23965),  INT16_C( 21450),  INT16_C( 24354),  INT16_C(  6661),  INT16_C(  7112),  INT16_C( 19494),  INT16_C( 15304) } },
    { {  INT16_C(  3015), -INT16_C( 18847), -INT16_C( 27716), -INT16_C(  2031), -INT16_C( 24558), -INT16_C( 17678), -INT16_C( 12845), -INT16_C(  9716) },
      {  INT16_C(  3018), -INT16_C( 18844), -INT16_C( 27713), -INT16_C(  2028), -INT16_C( 24555), -INT16_C( 17675), -INT16_C( 12842), -INT16_C(  9713) },
      {  INT16_C(  3032), -INT16_C( 18830), -INT16_C( 27699), -INT16_C(  2014), -INT16_C( 24541), -INT16_C( 17661), -INT16_C( 12828), -INT16_C(  9699) },
      {  INT16_C(  3044), -INT16_C( 18818), -INT16_C( 27687), -INT16_C(  2002), -INT16_C( 24529), -INT16_C( 17649), -INT16_C( 12816), -INT16_C(  9687) } },
    { {  INT16_C( 21106),  INT16_C(  8060), -INT16_C( 32347), -INT16_C( 29058),  INT16_C( 10651), -INT16_C( 23383),  INT16_C( 21877),  INT16_C( 15584) },
      {  INT16_C( 21109),  INT16_C(  8063), -INT16_C( 32344), -INT16_C( 29055),  INT16_C( 10654), -INT16_C( 23380),  INT16_C( 21880),  INT16_C( 15587) },
      {  INT16_C( 21123),  INT16_C(  8077), -INT16_C( 32330), -INT16_C( 29041),  INT16_C( 10668), -INT16_C( 23366),  INT16_C( 21894),  INT16_C( 15601) },
      {  INT16_C( 21135),  INT16_C(  8089), -INT16_C( 32318), -INT16_C( 29029),  INT16_C( 10680), -INT16_C( 23354),  INT16_C( 21906),  INT16_C( 15613) } },
    { {  INT16_C( 16736),  INT16_C(  7411),  INT16_C(  1236), -INT16_C(  6636),  INT16_C(  1700),  INT16_C( 30624), -INT16_C( 21293),  INT16_C( 17745) },
      {  INT16_C( 16739),  INT16_C(  7414),  INT16_C(  1239), -INT16_C(  6633),  INT16_C(  1703),  INT16_C( 30627), -INT16_C( 21290),  INT16_C( 17748) },
      {  INT16_C( 16753),  INT16_C(  7428),  INT16_C(  1253), -INT16_C(  6619),  INT16_C(  1717),  INT16_C( 30641), -INT16_C( 21276),  INT16_C( 17762) },
      {  INT16_C( 16765),  INT16_C(  7440),  INT16_C(  1265), -INT16_C(  6607),  INT16_C(  1729),  INT16_C( 30653), -INT16_C( 21264),  INT16_C( 17774) } },
    { { -INT16_C( 12802), -INT16_C( 23452), -INT16_C(  7601), -INT16_C(  5582), -INT16_C(  9460), -INT16_C( 32370),  INT16_C( 28208), -INT16_C( 28482) },
      { -INT16_C( 12799), -INT16_C( 23449), -INT16_C(  7598), -INT16_C(  5579), -INT16_C(  9457), -INT16_C( 32367),  INT16_C( 28211), -INT16_C( 28479) },
      { -INT16_C( 12785), -INT16_C( 23435), -INT16_C(  7584), -INT16_C(  5565), -INT16_C(  9443), -INT16_C( 32353),  INT16_C( 28225), -INT16_C( 28465) },
      { -INT16_C( 12773), -INT16_C( 23423), -INT16_C(  7572), -INT16_C(  5553), -INT16_C(  9431), -INT16_C( 32341),  INT16_C( 28237), -INT16_C( 28453) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_v8i16   a = simde_msa_ld_h(test_vec[i].a, 0);
    simde_v8i16  r3 = simde_msa_addvi_h(a, 3);
    simde_v8i16 r17 = simde_msa_addvi_h(a, 17);
    simde_v8i16 r29 = simde_msa_addvi_h(a, 29);

    simde_test_msa_v8i16_assert_equal( r3, simde_msa_ld_h(test_vec[i].r3 , 0));
    simde_test_msa_v8i16_assert_equal(r17, simde_msa_ld_h(test_vec[i].r17, 0));
    simde_test_msa_v8i16_assert_equal(r29, simde_msa_ld_h(test_vec[i].r29, 0));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_v8i16   a = simde_test_msa_v8i16_random();
    simde_v8i16  r3 = simde_msa_addvi_h(a, 3);
    simde_v8i16 r17 = simde_msa_addvi_h(a, 17);
    simde_v8i16 r29 = simde_msa_addvi_h(a, 29);

    simde_test_msa_v8i16_write(2,   a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_msa_v8i16_write(2,  r3, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_msa_v8i16_write(2, r17, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_msa_v8i16_write(2, r29, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_addvi_w (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int32_t   a[4];
    int32_t  r3[4];
    int32_t r17[4];
    int32_t r29[4];
  } test_vec[] = {
    { { -INT32_C(  2085768785),  INT32_C(  1516945845), -INT32_C(  1680799032), -INT32_C(  1243536457) },
      { -INT32_C(  2085768782),  INT32_C(  1516945848), -INT32_C(  1680799029), -INT32_C(  1243536454) },
      { -INT32_C(  2085768768),  INT32_C(  1516945862), -INT32_C(  1680799015), -INT32_C(  1243536440) },
      { -INT32_C(  2085768756),  INT32_C(  1516945874), -INT32_C(  1680799003), -INT32_C(  1243536428) } },
    { {  INT32_C(  1062815216),  INT32_C(   875137832), -INT32_C(  1749698457), -INT32_C(   701992154) },
      {  INT32_C(  1062815219),  INT32_C(   875137835), -INT32_C(  1749698454), -INT32_C(   701992151) },
      {  INT32_C(  1062815233),  INT32_C(   875137849), -INT32_C(  1749698440), -INT32_C(   701992137) },
      {  INT32_C(  1062815245),  INT32_C(   875137861), -INT32_C(  1749698428), -INT32_C(   701992125) } },
    { { -INT32_C(   631646940),  INT32_C(  1580516246), -INT32_C(  2047212082),  INT32_C(   423287592) },
      { -INT32_C(   631646937),  INT32_C(  1580516249), -INT32_C(  2047212079),  INT32_C(   423287595) },
      { -INT32_C(   631646923),  INT32_C(  1580516263), -INT32_C(  2047212065),  INT32_C(   423287609) },
      { -INT32_C(   631646911),  INT32_C(  1580516275), -INT32_C(  2047212053),  INT32_C(   423287621) } },
    { {  INT32_C(  1213764640), -INT32_C(  2038660577),  INT32_C(  1612591674), -INT32_C(   902412635) },
      {  INT32_C(  1213764643), -INT32_C(  2038660574),  INT32_C(  1612591677), -INT32_C(   902412632) },
      {  INT32_C(  1213764657), -INT32_C(  2038660560),  INT32_C(  1612591691), -INT32_C(   902412618) },
      {  INT32_C(  1213764669), -INT32_C(  2038660548),  INT32_C(  1612591703), -INT32_C(   902412606) } },
    { { -INT32_C(  1314615269),  INT32_C(   554752083),  INT32_C(   111545053),  INT32_C(    85975525) },
      { -INT32_C(  1314615266),  INT32_C(   554752086),  INT32_C(   111545056),  INT32_C(    85975528) },
      { -INT32_C(  1314615252),  INT32_C(   554752100),  INT32_C(   111545070),  INT32_C(    85975542) },
      { -INT32_C(  1314615240),  INT32_C(   554752112),  INT32_C(   111545082),  INT32_C(    85975554) } },
    { { -INT32_C(  1806796939),  INT32_C(   857459449), -INT32_C(  1567344132), -INT32_C(  1704146305) },
      { -INT32_C(  1806796936),  INT32_C(   857459452), -INT32_C(  1567344129), -INT32_C(  1704146302) },
      { -INT32_C(  1806796922),  INT32_C(   857459466), -INT32_C(  1567344115), -INT32_C(  1704146288) },
      { -INT32_C(  1806796910),  INT32_C(   857459478), -INT32_C(  1567344103), -INT32_C(  1704146276) } },
    { { -INT32_C(  1370812326), -INT32_C(   976266264),  INT32_C(  1254848101), -INT32_C(   867112361) },
      { -INT32_C(  1370812323), -INT32_C(   976266261),  INT32_C(  1254848104), -INT32_C(   867112358) },
      { -INT32_C(  1370812309), -INT32_C(   976266247),  INT32_C(  1254848118), -INT32_C(   867112344) },
      { -INT32_C(  1370812297), -INT32_C(   976266235),  INT32_C(  1254848130), -INT32_C(   867112332) } },
    { {  INT32_C(  1533058658),  INT32_C(  1703902056),  INT32_C(   856105908),  INT32_C(  1221424109) },
      {  INT32_C(  1533058661),  INT32_C(  1703902059),  INT32_C(   856105911),  INT32_C(  1221424112) },
      {  INT32_C(  1533058675),  INT32_C(  1703902073),  INT32_C(   856105925),  INT32_C(  1221424126) },
      {  INT32_C(  1533058687),  INT32_C(  1703902085),  INT32_C(   856105937),  INT32_C(  1221424138) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_v4i32   a = simde_msa_ld_w(test_vec[i].a, 0);
    simde_v4i32  r3 = simde_msa_addvi_w(a, 3);
    simde_v4i32 r17 = simde_msa_addvi_w(a, 17);
    simde_v4i32 r29 = simde_msa_addvi_w(a, 29);

    simde_test_msa_v4i32_assert_equal( r3, simde_msa_ld_w(test_vec[i].r3 , 0));
    simde_test_msa_v4i32_assert_equal(r17, simde_msa_ld_w(test_vec[i].r17, 0));
    simde_test_msa_v4i32_assert_equal(r29, simde_msa_ld_w(test_vec[i].r29, 0));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_v4i32   a = simde_test_msa_v4i32_random();
    simde_v4i32  r3 = simde_msa_addvi_w(a, 3);
    simde_v4i32 r17 = simde_msa_addvi_w(a, 17);
    simde_v4i32 r29 = simde_msa_addvi_w(a, 29);

    simde_test_msa_v4i32_write(2,   a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_msa_v4i32_write(2,  r3, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_msa_v4i32_write(2, r17, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_msa_v4i32_write(2, r29, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_addvi_d (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int64_t   a[2];
    int64_t  r3[2];
    int64_t r17[2];
    int64_t r29[2];
  } test_vec[] = {
    { { -INT64_C( 2724460670740981373),  INT64_C( 5214733952184810555) },
      { -INT64_C( 2724460670740981370),  INT64_C( 5214733952184810558) },
      { -INT64_C( 2724460670740981356),  INT64_C( 5214733952184810572) },
      { -INT64_C( 2724460670740981344),  INT64_C( 5214733952184810584) } },
    { { -INT64_C( 1161872377586073838), -INT64_C( 2482626499100612778) },
      { -INT64_C( 1161872377586073835), -INT64_C( 2482626499100612775) },
      { -INT64_C( 1161872377586073821), -INT64_C( 2482626499100612761) },
      { -INT64_C( 1161872377586073809), -INT64_C( 2482626499100612749) } },
    { { -INT64_C( 9054636277365178103),  INT64_C(  262180679475100788) },
      { -INT64_C( 9054636277365178100),  INT64_C(  262180679475100791) },
      { -INT64_C( 9054636277365178086),  INT64_C(  262180679475100805) },
      { -INT64_C( 9054636277365178074),  INT64_C(  262180679475100817) } },
    { { -INT64_C( 3432764936047147214),  INT64_C( 8609931885089685061) },
      { -INT64_C( 3432764936047147211),  INT64_C( 8609931885089685064) },
      { -INT64_C( 3432764936047147197),  INT64_C( 8609931885089685078) },
      { -INT64_C( 3432764936047147185),  INT64_C( 8609931885089685090) } },
    { { -INT64_C( 5626600962103327711), -INT64_C( 6504130850269102136) },
      { -INT64_C( 5626600962103327708), -INT64_C( 6504130850269102133) },
      { -INT64_C( 5626600962103327694), -INT64_C( 6504130850269102119) },
      { -INT64_C( 5626600962103327682), -INT64_C( 6504130850269102107) } },
    { { -INT64_C( 2503316841853469961),  INT64_C( 1644932021605914349) },
      { -INT64_C( 2503316841853469958),  INT64_C( 1644932021605914352) },
      { -INT64_C( 2503316841853469944),  INT64_C( 1644932021605914366) },
      { -INT64_C( 2503316841853469932),  INT64_C( 1644932021605914378) } },
    { { -INT64_C( 2474330981474056004),  INT64_C( 6665699520914306408) },
      { -INT64_C( 2474330981474056001),  INT64_C( 6665699520914306411) },
      { -INT64_C( 2474330981474055987),  INT64_C( 6665699520914306425) },
      { -INT64_C( 2474330981474055975),  INT64_C( 6665699520914306437) } },
    { { -INT64_C( 1224681121786260596),  INT64_C( 3562661170106760549) },
      { -INT64_C( 1224681121786260593),  INT64_C( 3562661170106760552) },
      { -INT64_C( 1224681121786260579),  INT64_C( 3562661170106760566) },
      { -INT64_C( 1224681121786260567),  INT64_C( 3562661170106760578) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_v2i64   a = simde_msa_ld_d(test_vec[i].a, 0);
    simde_v2i64  r3 = simde_msa_addvi_d(a, 3);
    simde_v2i64 r17 = simde_msa_addvi_d(a, 17);
    simde_v2i64 r29 = simde_msa_addvi_d(a, 29);

    simde_test_msa_v2i64_assert_equal( r3, simde_msa_ld_d(test_vec[i].r3 , 0));
    simde_test_msa_v2i64_assert_equal(r17, simde_msa_ld_d(test_vec[i].r17, 0));
    simde_test_msa_v2i64_assert_equal(r29, simde_msa_ld_d(test_vec[i].r29, 0));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_v2i64   a = simde_test_msa_v2i64_random();
    simde_v2i64  r3 = simde_msa_addvi_d(a, 3);
    simde_v2i64 r17 = simde_msa_addvi_d(a, 17);
    simde_v2i64 r29 = simde_msa_addvi_d(a, 29);

    simde_test_msa_v2i64_write(2,   a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_msa_v2i64_write(2,  r3, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_msa_v2i64_write(2, r17, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_msa_v2i64_write(2, r29, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(addvi_b)
SIMDE_TEST_FUNC_LIST_ENTRY(addvi_h)
SIMDE_TEST_FUNC_LIST_ENTRY(addvi_w)
SIMDE_TEST_FUNC_LIST_ENTRY(addvi_d)
SIMDE_TEST_FUNC_LIST_END

#include "test-msa-footer.h"
