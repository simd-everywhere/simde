#define SIMDE_TEST_X86_AVX512_INSN dbsad

#include <test/x86/avx512/test-avx512.h>
#include <simde/x86/avx512/setzero.h>
#include <simde/x86/avx512/dbsad.h>

static int
test_simde_mm_dbsad_epu8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int8_t a[16];
    const int8_t b[16];
    const int imm8;
    const int16_t r[8];
  } test_vec[] = {
    { { -INT8_C( 106), -INT8_C(  15),  INT8_C(  92),  INT8_C(   5),  INT8_C( 125), -INT8_C(  30),  INT8_C( 104), -INT8_C(  65),
        -INT8_C(  70),  INT8_C(  78),  INT8_C(  11),      INT8_MIN,  INT8_C( 117), -INT8_C(  68), -INT8_C(   7), -INT8_C(  36) },
      {  INT8_C(   1), -INT8_C(  75), -INT8_C(   3),  INT8_C(  86), -INT8_C(  97), -INT8_C(  87), -INT8_C( 127), -INT8_C( 113),
        -INT8_C(  77),  INT8_C(  16), -INT8_C(  15),  INT8_C(  31),  INT8_C( 121), -INT8_C(  85),  INT8_C( 121),  INT8_C(  15) },
       INT32_C(         156),
      {  INT16_C(   451),  INT16_C(   165),  INT16_C(   305),  INT16_C(   281),  INT16_C(   251),  INT16_C(   251),  INT16_C(   331),  INT16_C(   289) } },
    { { -INT8_C(  72),  INT8_C( 124), -INT8_C(  39),  INT8_C( 115), -INT8_C(  53), -INT8_C(  28), -INT8_C(  13),  INT8_C(  64),
        -INT8_C(  96), -INT8_C(  20),  INT8_C(  29), -INT8_C(  95), -INT8_C(  94),  INT8_C(  26), -INT8_C(   8),  INT8_C(  65) },
      { -INT8_C(  61),  INT8_C( 121), -INT8_C(  48),  INT8_C( 118), -INT8_C( 119), -INT8_C(  63), -INT8_C( 106),  INT8_C(   2),
         INT8_C( 108),  INT8_C(  15),  INT8_C(  17),  INT8_C(   9), -INT8_C(  27),  INT8_C(  38),  INT8_C(  35), -INT8_C(  98) },
       INT32_C(         162),
      {  INT16_C(   491),  INT16_C(   564),  INT16_C(   510),  INT16_C(   493),  INT16_C(   437),  INT16_C(   437),  INT16_C(   352),  INT16_C(   516) } },
    { { -INT8_C(  31),  INT8_C(   4), -INT8_C(  82), -INT8_C( 127), -INT8_C(  16), -INT8_C(  53),  INT8_C(  35), -INT8_C( 110),
        -INT8_C(  27),  INT8_C(  27), -INT8_C(  44), -INT8_C(  88), -INT8_C( 108), -INT8_C(  92),  INT8_C(  30),  INT8_C(  30) },
      {  INT8_C( 102), -INT8_C(  76),  INT8_C(  32), -INT8_C(  46), -INT8_C(  60),  INT8_C(  50), -INT8_C(  37), -INT8_C(  87),
         INT8_C(  88), -INT8_C(   2),  INT8_C(  71), -INT8_C(   6), -INT8_C(   5),  INT8_C(  88),  INT8_C( 104), -INT8_C(  36) },
       INT32_C(          92),
      {  INT16_C(   522),  INT16_C(   231),  INT16_C(   489),  INT16_C(   173),  INT16_C(    64),  INT16_C(   442),  INT16_C(   262),  INT16_C(   262) } },
    { { -INT8_C(  31),      INT8_MIN, -INT8_C(  33), -INT8_C(  58), -INT8_C( 101), -INT8_C(  77),  INT8_C( 110),  INT8_C(  48),
         INT8_C(  88), -INT8_C( 116),  INT8_C(  78), -INT8_C(  66),  INT8_C(  65),  INT8_C( 110), -INT8_C( 112),  INT8_C(   5) },
      { -INT8_C(  96),  INT8_C( 108), -INT8_C(  82), -INT8_C(   8),  INT8_C( 106), -INT8_C(  10), -INT8_C(  13),  INT8_C( 101),
         INT8_C(  78),  INT8_C(  91),  INT8_C(  65), -INT8_C(  85),  INT8_C( 113), -INT8_C(  97), -INT8_C(   8),  INT8_C(  82) },
       INT32_C(          31),
      {  INT16_C(   284),  INT16_C(   412),  INT16_C(   304),  INT16_C(   388),  INT16_C(   378),  INT16_C(   314),  INT16_C(   306),  INT16_C(   291) } },
    { { -INT8_C( 117), -INT8_C( 122), -INT8_C(  21), -INT8_C(  29),  INT8_C(  18),  INT8_C(  57), -INT8_C(  95),  INT8_C(  83),
        -INT8_C(  89),  INT8_C(  49),  INT8_C(  88),  INT8_C(  72), -INT8_C(  99),  INT8_C(   7),  INT8_C(  64),  INT8_C(   8) },
      { -INT8_C(   3),  INT8_C(  51),  INT8_C( 109),  INT8_C(  75), -INT8_C( 114), -INT8_C(  81), -INT8_C(  10), -INT8_C(   1),
         INT8_C(  78), -INT8_C(  18),  INT8_C(  81),  INT8_C( 109), -INT8_C(  58),  INT8_C( 105),  INT8_C(  40),  INT8_C(  81) },
       INT32_C(         239),
      {  INT16_C(   429),  INT16_C(   311),  INT16_C(   105),  INT16_C(   303),  INT16_C(   322),  INT16_C(   250),  INT16_C(   409),  INT16_C(   312) } },
    { {  INT8_C(  76), -INT8_C(  43),  INT8_C(  85), -INT8_C(  12),  INT8_C(   6), -INT8_C(  82),  INT8_C(  60), -INT8_C(  92),
        -INT8_C(  75),  INT8_C( 124), -INT8_C(  84), -INT8_C(  78), -INT8_C(  80),  INT8_C(  25), -INT8_C(   3),  INT8_C(  62) },
      { -INT8_C(  56), -INT8_C(  12),  INT8_C(  62),  INT8_C(  22), -INT8_C(  30), -INT8_C( 113), -INT8_C( 124), -INT8_C(  88),
        -INT8_C(   7), -INT8_C(  84), -INT8_C(   7), -INT8_C(  24), -INT8_C(  64),  INT8_C(  45), -INT8_C(  22),  INT8_C(  12) },
       INT32_C(           2),
      {  INT16_C(   390),  INT16_C(   323),  INT16_C(   521),  INT16_C(   538),  INT16_C(   405),  INT16_C(   297),  INT16_C(   352),  INT16_C(   338) } },
    { { -INT8_C(  18),  INT8_C(  60), -INT8_C(  83), -INT8_C(  93), -INT8_C(  71),  INT8_C(  89),  INT8_C(  85),  INT8_C( 105),
         INT8_C( 114),  INT8_C(  82), -INT8_C(  89),  INT8_C(  59),  INT8_C(  70), -INT8_C(  27),  INT8_C(  81),  INT8_C(  41) },
      {  INT8_C( 117), -INT8_C(  43), -INT8_C(  47),  INT8_C( 110), -INT8_C( 126), -INT8_C(  53),  INT8_C(  86),  INT8_C(  66),
        -INT8_C(   8),  INT8_C(  65),  INT8_C(  78), -INT8_C(   5), -INT8_C( 127),  INT8_C(  79),  INT8_C(   4),  INT8_C( 111) },
       INT32_C(         139),
      {  INT16_C(   349),  INT16_C(   362),  INT16_C(   406),  INT16_C(   280),  INT16_C(   227),  INT16_C(   472),  INT16_C(   449),  INT16_C(   112) } },
    { {  INT8_C(  10),  INT8_C( 103), -INT8_C(  83),  INT8_C( 124), -INT8_C(  71),  INT8_C(  85), -INT8_C(  73),  INT8_C(   0),
         INT8_C(  58),  INT8_C(   9),  INT8_C(  41), -INT8_C(  81), -INT8_C(  34), -INT8_C(   6),  INT8_C(  29),  INT8_C(  96) },
      { -INT8_C(  59),  INT8_C( 116), -INT8_C(  94), -INT8_C(  66), -INT8_C(  75), -INT8_C(  15), -INT8_C(  71),  INT8_C(  54),
         INT8_C(  64), -INT8_C(  67), -INT8_C(  91), -INT8_C(  53),  INT8_C( 110), -INT8_C(  73),  INT8_C(  16),  INT8_C( 120) },
       INT32_C(          30),
      {  INT16_C(   227),  INT16_C(   285),  INT16_C(   394),  INT16_C(    59),  INT16_C(   620),  INT16_C(   394),  INT16_C(   421),  INT16_C(   374) } },
  };

  simde__m128i a, b, r;

  a = simde_x_mm_loadu_epi8(test_vec[0].a);
  b = simde_x_mm_loadu_epi8(test_vec[0].b);
  r = simde_mm_dbsad_epu8(a, b, INT32_C(         156));
  simde_test_x86_assert_equal_i16x8(r, simde_x_mm_loadu_epi64(test_vec[0].r));

  a = simde_x_mm_loadu_epi8(test_vec[1].a);
  b = simde_x_mm_loadu_epi8(test_vec[1].b);
  r = simde_mm_dbsad_epu8(a, b, INT32_C(         162));
  simde_test_x86_assert_equal_i16x8(r, simde_x_mm_loadu_epi64(test_vec[1].r));

  a = simde_x_mm_loadu_epi8(test_vec[2].a);
  b = simde_x_mm_loadu_epi8(test_vec[2].b);
  r = simde_mm_dbsad_epu8(a, b, INT32_C(          92));
  simde_test_x86_assert_equal_i16x8(r, simde_x_mm_loadu_epi64(test_vec[2].r));

  a = simde_x_mm_loadu_epi8(test_vec[3].a);
  b = simde_x_mm_loadu_epi8(test_vec[3].b);
  r = simde_mm_dbsad_epu8(a, b, INT32_C(          31));
  simde_test_x86_assert_equal_i16x8(r, simde_x_mm_loadu_epi64(test_vec[3].r));

  a = simde_x_mm_loadu_epi8(test_vec[4].a);
  b = simde_x_mm_loadu_epi8(test_vec[4].b);
  r = simde_mm_dbsad_epu8(a, b, INT32_C(         239));
  simde_test_x86_assert_equal_i16x8(r, simde_x_mm_loadu_epi64(test_vec[4].r));

  a = simde_x_mm_loadu_epi8(test_vec[5].a);
  b = simde_x_mm_loadu_epi8(test_vec[5].b);
  r = simde_mm_dbsad_epu8(a, b, INT32_C(           2));
  simde_test_x86_assert_equal_i16x8(r, simde_x_mm_loadu_epi64(test_vec[5].r));

  a = simde_x_mm_loadu_epi8(test_vec[6].a);
  b = simde_x_mm_loadu_epi8(test_vec[6].b);
  r = simde_mm_dbsad_epu8(a, b, INT32_C(         139));
  simde_test_x86_assert_equal_i16x8(r, simde_x_mm_loadu_epi64(test_vec[6].r));

  a = simde_x_mm_loadu_epi8(test_vec[7].a);
  b = simde_x_mm_loadu_epi8(test_vec[7].b);
  r = simde_mm_dbsad_epu8(a, b, INT32_C(          30));
  simde_test_x86_assert_equal_i16x8(r, simde_x_mm_loadu_epi64(test_vec[7].r));

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m128i a = simde_test_x86_random_i8x16();
    simde__m128i b = simde_test_x86_random_i8x16();
    int imm8 = simde_test_codegen_random_i32() & 255;
    simde__m128i r;
    SIMDE_CONSTIFY_256_(simde_mm_dbsad_epu8, r, simde_mm_setzero_si128(), imm8, a, b);

    simde_test_x86_write_i8x16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i8x16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, imm8, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i16x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_mask_dbsad_epu8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int16_t src[8];
    const simde__mmask8 k;
    const int8_t a[16];
    const int8_t b[16];
    const int imm8;
    const int16_t r[8];
  } test_vec[] = {
    { { -INT16_C( 21486),  INT16_C( 19927),  INT16_C(   181), -INT16_C( 27652),  INT16_C(  6907), -INT16_C( 16140), -INT16_C( 26994),  INT16_C( 17278) },
      UINT8_C(135),
      {  INT8_C(  55),  INT8_C( 121), -INT8_C(  57), -INT8_C(  12),  INT8_C(  30), -INT8_C( 109),  INT8_C(  98), -INT8_C(  43),
        -INT8_C(  93), -INT8_C(  38), -INT8_C(  13),  INT8_C(  96), -INT8_C(  49), -INT8_C(  54),  INT8_C( 115),  INT8_C( 123) },
      { -INT8_C(  94), -INT8_C(  64),  INT8_C(  48), -INT8_C(  94), -INT8_C(  68), -INT8_C(  61), -INT8_C(  99), -INT8_C(  42),
        -INT8_C(  73),  INT8_C(  94),  INT8_C( 100),  INT8_C(  78), -INT8_C(  36), -INT8_C(  89), -INT8_C(  43),  INT8_C(  20) },
       INT32_C(          32),
      {  INT16_C(   411),  INT16_C(   329),  INT16_C(   118), -INT16_C( 27652),  INT16_C(  6907), -INT16_C( 16140), -INT16_C( 26994),  INT16_C(   321) } },
    { {  INT16_C( 27440), -INT16_C( 11501),  INT16_C(  1605),  INT16_C(  5171), -INT16_C( 22831),  INT16_C( 29583), -INT16_C( 16538),  INT16_C(  8981) },
      UINT8_C(131),
      { -INT8_C(  77), -INT8_C(   7),  INT8_C(  58),  INT8_C(  17),  INT8_C(  94), -INT8_C( 120), -INT8_C(  19),  INT8_C(   5),
         INT8_C(  94),  INT8_C(   1),  INT8_C(  38), -INT8_C(   5),  INT8_C(  10),  INT8_C( 100),  INT8_C(  43),  INT8_C( 117) },
      {  INT8_C( 120), -INT8_C(   2), -INT8_C(  70),  INT8_C( 126),  INT8_C(  49), -INT8_C(  49),  INT8_C(  79), -INT8_C(  40),
         INT8_C(  94), -INT8_C(  62),  INT8_C(  62),  INT8_C(  30), -INT8_C(  40),  INT8_C(  97), -INT8_C(  95), -INT8_C( 117) },
       INT32_C(          91),
      {  INT16_C(   414),  INT16_C(   328),  INT16_C(  1605),  INT16_C(  5171), -INT16_C( 22831),  INT16_C( 29583), -INT16_C( 16538),  INT16_C(   459) } },
    { { -INT16_C( 30364), -INT16_C( 15682), -INT16_C(  7029), -INT16_C( 27203), -INT16_C(  6071), -INT16_C( 16118), -INT16_C( 15130),  INT16_C(  5951) },
      UINT8_C(147),
      { -INT8_C( 113), -INT8_C(  17), -INT8_C(  14),  INT8_C(  81),  INT8_C(  46),  INT8_C(  16),  INT8_C(  41), -INT8_C( 113),
        -INT8_C(  79), -INT8_C(  76), -INT8_C(  22), -INT8_C( 116),  INT8_C(  80), -INT8_C(  93), -INT8_C(  16), -INT8_C(  38) },
      {  INT8_C(  98), -INT8_C(  78),  INT8_C( 101),  INT8_C(  70),  INT8_C( 111), -INT8_C(   6), -INT8_C( 113),  INT8_C(  87),
         INT8_C(   4),  INT8_C(  80),  INT8_C(  61), -INT8_C(  56), -INT8_C( 112),  INT8_C(  85),  INT8_C(  92),  INT8_C(  31) },
       INT32_C(          68),
      {  INT16_C(   258),  INT16_C(   375), -INT16_C(  7029), -INT16_C( 27203),  INT16_C(   284), -INT16_C( 16118), -INT16_C( 15130),  INT16_C(   147) } },
    { { -INT16_C( 26018),  INT16_C(  3842), -INT16_C(  5042), -INT16_C( 24677), -INT16_C( 29552), -INT16_C(  3463), -INT16_C(  8642), -INT16_C( 20936) },
      UINT8_C(216),
      { -INT8_C(  56),  INT8_C(   5), -INT8_C(  36),  INT8_C(  24),  INT8_C(  67), -INT8_C(  92), -INT8_C(  88), -INT8_C( 104),
         INT8_C(   0), -INT8_C(  57), -INT8_C(  36),  INT8_C(  78),  INT8_C(  56),  INT8_C(  79), -INT8_C(  84), -INT8_C(  46) },
      {  INT8_C(  81), -INT8_C(  69),  INT8_C(  32),  INT8_C(  61),  INT8_C(  87), -INT8_C(  65), -INT8_C(  51), -INT8_C(  29),
         INT8_C(  56), -INT8_C(  65),  INT8_C(  33),  INT8_C(  22), -INT8_C(   8), -INT8_C(  49), -INT8_C(  18), -INT8_C(  64) },
       INT32_C(         213),
      { -INT16_C( 26018),  INT16_C(  3842), -INT16_C(  5042),  INT16_C(   313),  INT16_C(   259), -INT16_C(  3463),  INT16_C(   376),  INT16_C(   403) } },
    { { -INT16_C( 32401),  INT16_C( 28592), -INT16_C( 29624), -INT16_C( 32578),  INT16_C( 27355),  INT16_C( 11346),  INT16_C( 29478),  INT16_C( 32106) },
      UINT8_C( 50),
      {  INT8_C(  55),  INT8_C(  96),  INT8_C( 107), -INT8_C(   9), -INT8_C( 127), -INT8_C( 127), -INT8_C(  17),  INT8_C(  81),
         INT8_C( 112), -INT8_C(  81),  INT8_C(  38),  INT8_C(  58), -INT8_C( 121),  INT8_C(  62), -INT8_C(  87),  INT8_C(   8) },
      { -INT8_C(  18),  INT8_C(  25),  INT8_C(  81),  INT8_C( 122), -INT8_C(  41), -INT8_C(  47),  INT8_C(  86),  INT8_C(  65),
         INT8_C(  36), -INT8_C( 126),  INT8_C( 103), -INT8_C( 105), -INT8_C(  20), -INT8_C(  28), -INT8_C(  55),  INT8_C(  36) },
       INT32_C(          68),
      { -INT16_C( 32401),  INT16_C(    92), -INT16_C( 29624), -INT16_C( 32578),  INT16_C(   383),  INT16_C(   422),  INT16_C( 29478),  INT16_C( 32106) } },
    { {  INT16_C(  2742),  INT16_C(  9751),  INT16_C( 15801),  INT16_C( 16480),  INT16_C(  2683),  INT16_C( 26953), -INT16_C( 26077), -INT16_C(  1309) },
      UINT8_C(107),
      {  INT8_C(  57),  INT8_C(  59), -INT8_C( 113), -INT8_C(  68), -INT8_C(  93),  INT8_C(  38), -INT8_C(  88), -INT8_C( 121),
        -INT8_C(  16), -INT8_C(  52), -INT8_C(  52),  INT8_C(  36), -INT8_C(  25), -INT8_C( 110), -INT8_C(  38), -INT8_C(  15) },
      { -INT8_C(  87),  INT8_C(   0), -INT8_C(  86), -INT8_C(  26),  INT8_C(  97), -INT8_C(  21),  INT8_C(  97),  INT8_C( 107),
         INT8_C(  52), -INT8_C(  54), -INT8_C( 114), -INT8_C(  50), -INT8_C(  83), -INT8_C( 120),  INT8_C(  57), -INT8_C(  25) },
       INT32_C(         195),
      {  INT16_C(   322),  INT16_C(   188),  INT16_C( 15801),  INT16_C(   402),  INT16_C(  2683),  INT16_C(   437),  INT16_C(   295), -INT16_C(  1309) } },
    { {  INT16_C( 19439), -INT16_C(  8210), -INT16_C( 17896), -INT16_C(   252), -INT16_C(  8628), -INT16_C(  2575), -INT16_C( 25633),  INT16_C( 16603) },
      UINT8_C(134),
      {  INT8_C(  60), -INT8_C(  85), -INT8_C(  70),  INT8_C(   6),  INT8_C(  57), -INT8_C( 120), -INT8_C(  77), -INT8_C(  63),
        -INT8_C(  62), -INT8_C( 102), -INT8_C( 124), -INT8_C( 117),  INT8_C(  61), -INT8_C(  21),  INT8_C( 122), -INT8_C( 119) },
      { -INT8_C(  39),  INT8_C(  90), -INT8_C(  95), -INT8_C( 109),  INT8_C(  94), -INT8_C(  96), -INT8_C(  33),  INT8_C(  60),
        -INT8_C( 111), -INT8_C(  44),  INT8_C(  27),  INT8_C(  45), -INT8_C(  81),  INT8_C(  91), -INT8_C(  77), -INT8_C(  21) },
       INT32_C(           6),
      {  INT16_C( 19439),  INT16_C(   525),  INT16_C(   239), -INT16_C(   252), -INT16_C(  8628), -INT16_C(  2575), -INT16_C( 25633),  INT16_C(   160) } },
    { { -INT16_C( 23306), -INT16_C( 18432), -INT16_C( 31425),  INT16_C( 31811), -INT16_C( 16784),  INT16_C( 18693), -INT16_C( 23016),  INT16_C( 30428) },
      UINT8_C( 71),
      { -INT8_C(  69), -INT8_C(  78), -INT8_C(  40), -INT8_C( 113), -INT8_C(  50),  INT8_C(   5),  INT8_C(  62),  INT8_C(  41),
        -INT8_C(  71),  INT8_C(  41),  INT8_C(  48),  INT8_C(  39),  INT8_C(  26),  INT8_C( 111),  INT8_C(  29), -INT8_C(  66) },
      {  INT8_C( 112), -INT8_C(  42), -INT8_C(   3), -INT8_C(  11),  INT8_C(  25),  INT8_C( 122),  INT8_C( 101), -INT8_C(  41),
             INT8_MAX, -INT8_C(  82), -INT8_C(  17),  INT8_C(  38), -INT8_C( 118),  INT8_C( 101),  INT8_C( 109),  INT8_C(  69) },
       INT32_C(          24),
      {  INT16_C(   250),  INT16_C(   147),  INT16_C(   485),  INT16_C( 31811), -INT16_C( 16784),  INT16_C( 18693),  INT16_C(   286),  INT16_C( 30428) } },
  };

  simde__m128i src, a, b, r;

  src = simde_x_mm_loadu_epi16(test_vec[0].src);
  a = simde_x_mm_loadu_epi8(test_vec[0].a);
  b = simde_x_mm_loadu_epi8(test_vec[0].b);
  r = simde_mm_mask_dbsad_epu8(src, test_vec[0].k, a, b, INT32_C(          32));
  simde_test_x86_assert_equal_i16x8(r, simde_x_mm_loadu_epi16(test_vec[0].r));

  src = simde_x_mm_loadu_epi16(test_vec[1].src);
  a = simde_x_mm_loadu_epi8(test_vec[1].a);
  b = simde_x_mm_loadu_epi8(test_vec[1].b);
  r = simde_mm_mask_dbsad_epu8(src, test_vec[1].k, a, b, INT32_C(          91));
  simde_test_x86_assert_equal_i16x8(r, simde_x_mm_loadu_epi16(test_vec[1].r));

  src = simde_x_mm_loadu_epi16(test_vec[2].src);
  a = simde_x_mm_loadu_epi8(test_vec[2].a);
  b = simde_x_mm_loadu_epi8(test_vec[2].b);
  r = simde_mm_mask_dbsad_epu8(src, test_vec[2].k, a, b, INT32_C(          68));
  simde_test_x86_assert_equal_i16x8(r, simde_x_mm_loadu_epi16(test_vec[2].r));

  src = simde_x_mm_loadu_epi16(test_vec[3].src);
  a = simde_x_mm_loadu_epi8(test_vec[3].a);
  b = simde_x_mm_loadu_epi8(test_vec[3].b);
  r = simde_mm_mask_dbsad_epu8(src, test_vec[3].k, a, b, INT32_C(         213));
  simde_test_x86_assert_equal_i16x8(r, simde_x_mm_loadu_epi16(test_vec[3].r));

  src = simde_x_mm_loadu_epi16(test_vec[4].src);
  a = simde_x_mm_loadu_epi8(test_vec[4].a);
  b = simde_x_mm_loadu_epi8(test_vec[4].b);
  r = simde_mm_mask_dbsad_epu8(src, test_vec[4].k, a, b, INT32_C(          68));
  simde_test_x86_assert_equal_i16x8(r, simde_x_mm_loadu_epi16(test_vec[4].r));

  src = simde_x_mm_loadu_epi16(test_vec[5].src);
  a = simde_x_mm_loadu_epi8(test_vec[5].a);
  b = simde_x_mm_loadu_epi8(test_vec[5].b);
  r = simde_mm_mask_dbsad_epu8(src, test_vec[5].k, a, b, INT32_C(         195));
  simde_test_x86_assert_equal_i16x8(r, simde_x_mm_loadu_epi16(test_vec[5].r));

  src = simde_x_mm_loadu_epi16(test_vec[6].src);
  a = simde_x_mm_loadu_epi8(test_vec[6].a);
  b = simde_x_mm_loadu_epi8(test_vec[6].b);
  r = simde_mm_mask_dbsad_epu8(src, test_vec[6].k, a, b, INT32_C(           6));
  simde_test_x86_assert_equal_i16x8(r, simde_x_mm_loadu_epi16(test_vec[6].r));

  src = simde_x_mm_loadu_epi16(test_vec[7].src);
  a = simde_x_mm_loadu_epi8(test_vec[7].a);
  b = simde_x_mm_loadu_epi8(test_vec[7].b);
  r = simde_mm_mask_dbsad_epu8(src, test_vec[7].k, a, b, INT32_C(          24));
  simde_test_x86_assert_equal_i16x8(r, simde_x_mm_loadu_epi16(test_vec[7].r));

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m128i src = simde_test_x86_random_i16x8();
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m128i a = simde_test_x86_random_i8x16();
    simde__m128i b = simde_test_x86_random_i8x16();
    int imm8 = simde_test_codegen_random_i32() & 255;
    simde__m128i r;
    SIMDE_CONSTIFY_256_(simde_mm_mask_dbsad_epu8, r, simde_mm_setzero_si128(), imm8, src, k, a, b);

    simde_test_x86_write_i16x8(2, src, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i8x16(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i8x16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, imm8, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i16x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_maskz_dbsad_epu8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask8 k;
    const int8_t a[16];
    const int8_t b[16];
    const int imm8;
    const int16_t r[8];
  } test_vec[] = {
    { UINT8_C( 75),
      {  INT8_C(  18),  INT8_C(  15),  INT8_C(   4),  INT8_C(  59),  INT8_C(  63),  INT8_C(  43),  INT8_C(  85), -INT8_C(  81),
         INT8_C(  72),  INT8_C(  19),  INT8_C(  31),  INT8_C(  30),  INT8_C(  17),  INT8_C(  20),  INT8_C(  56), -INT8_C( 117) },
      {  INT8_C( 121),  INT8_C(  15),  INT8_C(  10),  INT8_C(  39), -INT8_C(   1),  INT8_C(  48), -INT8_C(  79),  INT8_C( 100),
        -INT8_C(  99), -INT8_C(  10),  INT8_C( 124), -INT8_C(  29), -INT8_C(  54),  INT8_C(  98),  INT8_C(  46), -INT8_C(  36) },
       INT32_C(         114),
      {  INT16_C(   658),  INT16_C(   622),  INT16_C(     0),  INT16_C(   477),  INT16_C(     0),  INT16_C(     0),  INT16_C(   519),  INT16_C(     0) } },
    { UINT8_C( 93),
      {  INT8_C( 108),  INT8_C(  96), -INT8_C(  91),      INT8_MAX,      INT8_MAX, -INT8_C(  60), -INT8_C( 112), -INT8_C( 109),
        -INT8_C(   4),  INT8_C(  27),  INT8_C(  12),  INT8_C(  11),  INT8_C(  38),  INT8_C(  51),  INT8_C(  10),  INT8_C(  86) },
      { -INT8_C(  28),  INT8_C( 111), -INT8_C(  12), -INT8_C(  38), -INT8_C(  21), -INT8_C(  41), -INT8_C(  92),  INT8_C(  78),
         INT8_C(   5),      INT8_MIN, -INT8_C(  64),  INT8_C(  55), -INT8_C( 105),  INT8_C( 113), -INT8_C( 108),  INT8_C(   3) },
       INT32_C(         210),
      {  INT16_C(   234),  INT16_C(     0),  INT16_C(   326),  INT16_C(   234),  INT16_C(   424),  INT16_C(     0),  INT16_C(   321),  INT16_C(     0) } },
    { UINT8_C(253),
      {  INT8_C(  19), -INT8_C(  27), -INT8_C(   7),  INT8_C(  47), -INT8_C(  15),  INT8_C(   5),  INT8_C(  85),  INT8_C(  37),
         INT8_C(  15), -INT8_C(  85),  INT8_C(   9),  INT8_C( 126), -INT8_C(  97), -INT8_C(  28),  INT8_C( 106),  INT8_C( 118) },
      { -INT8_C( 120), -INT8_C(  72),  INT8_C( 123),  INT8_C(   9),  INT8_C( 120), -INT8_C(  78), -INT8_C(  96), -INT8_C(  23),
         INT8_C(  70), -INT8_C(  92), -INT8_C(  69),      INT8_MIN,  INT8_C(  39),  INT8_C(  13),  INT8_C( 125),  INT8_C(  58) },
       INT32_C(         242),
      {  INT16_C(   259),  INT16_C(     0),  INT16_C(   375),  INT16_C(   429),  INT16_C(   366),  INT16_C(   184),  INT16_C(   376),  INT16_C(   390) } },
    { UINT8_C(124),
      { -INT8_C(  66),  INT8_C(   8), -INT8_C( 117),  INT8_C( 106),  INT8_C(  18),  INT8_C(  10),  INT8_C(   9), -INT8_C(  10),
         INT8_C( 116),      INT8_MIN,  INT8_C( 126),  INT8_C(  44), -INT8_C(   5), -INT8_C( 121), -INT8_C(  92), -INT8_C(  82) },
      {  INT8_C(  40), -INT8_C( 115), -INT8_C(  12), -INT8_C(  52),  INT8_C(  73),  INT8_C( 116), -INT8_C(  13),  INT8_C(  86),
        -INT8_C(  14),  INT8_C(  45),  INT8_C(  72),  INT8_C( 105), -INT8_C( 105),  INT8_C(  43), -INT8_C(  27),  INT8_C(  85) },
       INT32_C(          52),
      {  INT16_C(     0),  INT16_C(     0),  INT16_C(   614),  INT16_C(   359),  INT16_C(   264),  INT16_C(   219),  INT16_C(   229),  INT16_C(     0) } },
    { UINT8_C(122),
      { -INT8_C(  55),  INT8_C(  60), -INT8_C(  18),  INT8_C(  73), -INT8_C(  70),  INT8_C(  26),  INT8_C(  68),  INT8_C(  66),
        -INT8_C(  66), -INT8_C(  14),  INT8_C( 106),  INT8_C(  76), -INT8_C(  25),  INT8_C(  54), -INT8_C( 107),  INT8_C(  91) },
      {  INT8_C(  41), -INT8_C(  21),  INT8_C(  77),  INT8_C(  86),  INT8_C(  51), -INT8_C(  74), -INT8_C(  19),  INT8_C(  94),
        -INT8_C( 101),  INT8_C(  67), -INT8_C( 110),  INT8_C(  12),  INT8_C(   2), -INT8_C(  40), -INT8_C( 122), -INT8_C(  53) },
       INT32_C(          20),
      {  INT16_C(     0),  INT16_C(   225),  INT16_C(     0),  INT16_C(   410),  INT16_C(   348),  INT16_C(    60),  INT16_C(   298),  INT16_C(     0) } },
    { UINT8_C(143),
      {  INT8_C(  89),  INT8_C(  17),  INT8_C(  78),  INT8_C(  75),  INT8_C( 123), -INT8_C( 102),  INT8_C(  50), -INT8_C(  79),
         INT8_C(  47), -INT8_C( 114), -INT8_C(  38),  INT8_C(  26), -INT8_C(  37),  INT8_C(  48),  INT8_C(  77), -INT8_C( 110) },
      {  INT8_C(  30), -INT8_C(  85),  INT8_C(  45),  INT8_C(  97),  INT8_C(  62),  INT8_C(  57),  INT8_C(  99),  INT8_C(  22),
        -INT8_C(  64),  INT8_C(  47),  INT8_C(  43),  INT8_C(  53),  INT8_C(  67), -INT8_C(   6), -INT8_C(  60), -INT8_C( 100) },
       INT32_C(          11),
      {  INT16_C(   454),  INT16_C(   535),  INT16_C(   347),  INT16_C(   208),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(   335) } },
    { UINT8_C(172),
      {  INT8_C(  26),  INT8_C(  55), -INT8_C(  37), -INT8_C(  88),  INT8_C(  17), -INT8_C(  11), -INT8_C( 124),  INT8_C(  65),
         INT8_C(  66),  INT8_C(  22),  INT8_C(  95), -INT8_C(  18),  INT8_C(  67), -INT8_C(  64),  INT8_C(  44),  INT8_C( 125) },
      {  INT8_C(  36),  INT8_C(  66),  INT8_C(  61),  INT8_C(  83),  INT8_C( 109),  INT8_C( 114), -INT8_C( 106),  INT8_C( 103),
         INT8_C(  54),  INT8_C(  51),  INT8_C( 114),  INT8_C(  73),  INT8_C(  27), -INT8_C(   8), -INT8_C(  11),  INT8_C(  53) },
       INT32_C(          47),
      {  INT16_C(     0),  INT16_C(     0),  INT16_C(   708),  INT16_C(   550),  INT16_C(     0),  INT16_C(   331),  INT16_C(     0),  INT16_C(   248) } },
    { UINT8_C(198),
      {  INT8_C(  98), -INT8_C( 126),  INT8_C(   9),  INT8_C( 120), -INT8_C(  31), -INT8_C(   9), -INT8_C(  69), -INT8_C(  94),
         INT8_C(  35),  INT8_C(  56), -INT8_C(  58),  INT8_C( 101),  INT8_C( 117),  INT8_C(  25), -INT8_C(  45), -INT8_C(  25) },
      { -INT8_C(  81),  INT8_C(  58),  INT8_C(  30), -INT8_C(  30), -INT8_C(  83),  INT8_C( 103), -INT8_C(   3), -INT8_C(  91),
         INT8_C(  92),  INT8_C(  51), -INT8_C(  43),  INT8_C(  45),  INT8_C(  17),  INT8_C(  21), -INT8_C(  12),  INT8_C( 115) },
       INT32_C(         151),
      {  INT16_C(     0),  INT16_C(   350),  INT16_C(   224),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(   575),  INT16_C(   293) } },
  };

  simde__m128i a, b, r;

  a = simde_x_mm_loadu_epi8(test_vec[0].a);
  b = simde_x_mm_loadu_epi8(test_vec[0].b);
  r = simde_mm_maskz_dbsad_epu8(test_vec[0].k, a, b, INT32_C(         114));
  simde_test_x86_assert_equal_i16x8(r, simde_x_mm_loadu_epi16(test_vec[0].r));

  a = simde_x_mm_loadu_epi8(test_vec[1].a);
  b = simde_x_mm_loadu_epi8(test_vec[1].b);
  r = simde_mm_maskz_dbsad_epu8(test_vec[1].k, a, b, INT32_C(         210));
  simde_test_x86_assert_equal_i16x8(r, simde_x_mm_loadu_epi16(test_vec[1].r));

  a = simde_x_mm_loadu_epi8(test_vec[2].a);
  b = simde_x_mm_loadu_epi8(test_vec[2].b);
  r = simde_mm_maskz_dbsad_epu8(test_vec[2].k, a, b, INT32_C(         242));
  simde_test_x86_assert_equal_i16x8(r, simde_x_mm_loadu_epi16(test_vec[2].r));

  a = simde_x_mm_loadu_epi8(test_vec[3].a);
  b = simde_x_mm_loadu_epi8(test_vec[3].b);
  r = simde_mm_maskz_dbsad_epu8(test_vec[3].k, a, b, INT32_C(          52));
  simde_test_x86_assert_equal_i16x8(r, simde_x_mm_loadu_epi16(test_vec[3].r));

  a = simde_x_mm_loadu_epi8(test_vec[4].a);
  b = simde_x_mm_loadu_epi8(test_vec[4].b);
  r = simde_mm_maskz_dbsad_epu8(test_vec[4].k, a, b, INT32_C(          20));
  simde_test_x86_assert_equal_i16x8(r, simde_x_mm_loadu_epi16(test_vec[4].r));

  a = simde_x_mm_loadu_epi8(test_vec[5].a);
  b = simde_x_mm_loadu_epi8(test_vec[5].b);
  r = simde_mm_maskz_dbsad_epu8(test_vec[5].k, a, b, INT32_C(          11));
  simde_test_x86_assert_equal_i16x8(r, simde_x_mm_loadu_epi16(test_vec[5].r));

  a = simde_x_mm_loadu_epi8(test_vec[6].a);
  b = simde_x_mm_loadu_epi8(test_vec[6].b);
  r = simde_mm_maskz_dbsad_epu8(test_vec[6].k, a, b, INT32_C(          47));
  simde_test_x86_assert_equal_i16x8(r, simde_x_mm_loadu_epi16(test_vec[6].r));

  a = simde_x_mm_loadu_epi8(test_vec[7].a);
  b = simde_x_mm_loadu_epi8(test_vec[7].b);
  r = simde_mm_maskz_dbsad_epu8(test_vec[7].k, a, b, INT32_C(         151));
  simde_test_x86_assert_equal_i16x8(r, simde_x_mm_loadu_epi16(test_vec[7].r));

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m128i a = simde_test_x86_random_i8x16();
    simde__m128i b = simde_test_x86_random_i8x16();
    int imm8 = simde_test_codegen_random_i32() & 255;
    simde__m128i r;
    SIMDE_CONSTIFY_256_(simde_mm_maskz_dbsad_epu8, r, simde_mm_setzero_si128(), imm8, k, a, b);

    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i8x16(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i8x16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, imm8, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i16x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm256_dbsad_epu8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int8_t a[32];
    const int8_t b[32];
    const int imm8;
    const int16_t r[16];
  } test_vec[] = {
    { { -INT8_C(  41), -INT8_C(  40),  INT8_C(  35),  INT8_C(  39),  INT8_C(  21),  INT8_C(  23), -INT8_C( 105),  INT8_C(  33),
         INT8_C(  59),  INT8_C( 107), -INT8_C(  47), -INT8_C(  71), -INT8_C(  27),  INT8_C(  87), -INT8_C(  45),  INT8_C(  12),
        -INT8_C(  93),  INT8_C(  39), -INT8_C(  77), -INT8_C(  18), -INT8_C(  47), -INT8_C(  35),  INT8_C(  70),  INT8_C(  12),
        -INT8_C(  82), -INT8_C(  41), -INT8_C(  69), -INT8_C(  92),  INT8_C(  90),  INT8_C(  15),  INT8_C(  68),  INT8_C(  49) },
      { -INT8_C(  25),  INT8_C( 104),  INT8_C(  88), -INT8_C(   3),      INT8_MAX, -INT8_C(  17),  INT8_C(  30), -INT8_C(  70),
         INT8_C(  90), -INT8_C(  17),  INT8_C( 115),  INT8_C(  63),  INT8_C(  71),  INT8_C(  70),  INT8_C(  76), -INT8_C(  22),
         INT8_C( 110), -INT8_C(   1), -INT8_C(  40),  INT8_C(  63), -INT8_C(  36),  INT8_C(  31),  INT8_C(  76), -INT8_C( 118),
        -INT8_C(  10),  INT8_C(   7),  INT8_C(  47),  INT8_C(  80),  INT8_C(  23),  INT8_C( 115), -INT8_C( 127), -INT8_C(   2) },
       INT32_C(         219),
      {  INT16_C(   526),  INT16_C(   535),  INT16_C(   533),  INT16_C(   450),  INT16_C(   380),  INT16_C(   394),  INT16_C(   496),  INT16_C(   264),
         INT16_C(   282),  INT16_C(   221),  INT16_C(   294),  INT16_C(   168),  INT16_C(   367),  INT16_C(   472),  INT16_C(   248),  INT16_C(   183) } },
    { { -INT8_C(  55),  INT8_C(  26),  INT8_C(  21),  INT8_C(  36),  INT8_C(   9), -INT8_C( 119),  INT8_C(  99),  INT8_C(  80),
        -INT8_C(  49), -INT8_C(  81),  INT8_C(  59),  INT8_C(  61), -INT8_C(  82),  INT8_C(  19),  INT8_C( 125), -INT8_C( 117),
         INT8_C(  50), -INT8_C(  55),  INT8_C(  21),  INT8_C(  40), -INT8_C(  48),  INT8_C(  68),  INT8_C( 120), -INT8_C(  25),
        -INT8_C(  72), -INT8_C(   6), -INT8_C(  26), -INT8_C( 109), -INT8_C(  44), -INT8_C(  31), -INT8_C(  18), -INT8_C(  99) },
      { -INT8_C(   5),  INT8_C(   4), -INT8_C(  63),  INT8_C(   5), -INT8_C( 115),  INT8_C(  37),  INT8_C(  85),  INT8_C(  92),
        -INT8_C(  44), -INT8_C( 112), -INT8_C( 102), -INT8_C( 125), -INT8_C(  92),  INT8_C(  23),  INT8_C(  14), -INT8_C(  42),
        -INT8_C(  32),  INT8_C(  35), -INT8_C(   1), -INT8_C(  80),  INT8_C( 104),  INT8_C( 119), -INT8_C( 104),  INT8_C(  32),
         INT8_C( 113),  INT8_C( 126), -INT8_C(  77),  INT8_C(  69),  INT8_C(  95), -INT8_C(  94), -INT8_C(  29),  INT8_C(  91) },
       INT32_C(         166),
      {  INT16_C(   357),  INT16_C(   400),  INT16_C(   236),  INT16_C(   193),  INT16_C(   201),  INT16_C(   307),  INT16_C(   224),  INT16_C(   270),
         INT16_C(   325),  INT16_C(   210),  INT16_C(   158),  INT16_C(   255),  INT16_C(   324),  INT16_C(   324),  INT16_C(   345),  INT16_C(   389) } },
    { { -INT8_C(  55), -INT8_C(  75), -INT8_C( 113), -INT8_C(  98),  INT8_C(  70),  INT8_C(  41),  INT8_C(  33), -INT8_C(  22),
         INT8_C(  64),  INT8_C(  47), -INT8_C(  64),  INT8_C(  32),  INT8_C(  82), -INT8_C(  65), -INT8_C(  47), -INT8_C(  70),
         INT8_C(  55),  INT8_C( 105), -INT8_C(  38), -INT8_C(  88), -INT8_C(  25), -INT8_C( 114), -INT8_C(  18),  INT8_C(  70),
         INT8_C(  48), -INT8_C(  47), -INT8_C(  95), -INT8_C(  42),  INT8_C( 117),  INT8_C(   1),  INT8_C(   9),  INT8_C(  63) },
      { -INT8_C(  73), -INT8_C( 104), -INT8_C(  35), -INT8_C(   3), -INT8_C(  62), -INT8_C(   2), -INT8_C(  25),  INT8_C(   2),
         INT8_C(  45), -INT8_C(  89),  INT8_C(  35),      INT8_MAX,  INT8_C( 103), -INT8_C(  12),  INT8_C(  58), -INT8_C(  98),
         INT8_C(  93),  INT8_C(  20),  INT8_C(  70),  INT8_C(  68), -INT8_C(  94),  INT8_C(  52), -INT8_C( 118), -INT8_C(  46),
         INT8_C(   5),  INT8_C(  44), -INT8_C(  88),  INT8_C( 123),  INT8_C(  45), -INT8_C(  79), -INT8_C(  70), -INT8_C(  28) },
       INT32_C(          74),
      {  INT16_C(   309),  INT16_C(   309),  INT16_C(   200),  INT16_C(   394),  INT16_C(   474),  INT16_C(   485),  INT16_C(   284),  INT16_C(   264),
         INT16_C(   206),  INT16_C(   332),  INT16_C(   341),  INT16_C(   537),  INT16_C(   471),  INT16_C(   312),  INT16_C(   278),  INT16_C(   328) } },
    { { -INT8_C( 107), -INT8_C(  56),  INT8_C(  14), -INT8_C(  62),  INT8_C( 112),  INT8_C(  49),  INT8_C(  65), -INT8_C(  41),
         INT8_C(  37),  INT8_C( 123),  INT8_C( 117), -INT8_C( 126), -INT8_C( 112), -INT8_C(  69), -INT8_C(  58),  INT8_C(  50),
        -INT8_C(  16),  INT8_C(  81),  INT8_C(   5), -INT8_C(  11),  INT8_C( 125), -INT8_C(  83),  INT8_C( 112), -INT8_C(  86),
         INT8_C(  95),  INT8_C(  42), -INT8_C( 113), -INT8_C(  87), -INT8_C(  63),  INT8_C( 112), -INT8_C(  75),  INT8_C(  86) },
      {  INT8_C(  57), -INT8_C(  61),  INT8_C(  24), -INT8_C(  87), -INT8_C(  11),  INT8_C(  90),      INT8_MIN,  INT8_C(  26),
        -INT8_C(  43), -INT8_C(  11), -INT8_C(  99),  INT8_C( 101), -INT8_C(  80),  INT8_C(  99), -INT8_C( 104), -INT8_C(  96),
        -INT8_C(  76), -INT8_C(  99), -INT8_C( 106),  INT8_C(  49),  INT8_C(  74),  INT8_C(   6), -INT8_C(  36), -INT8_C(  87),
         INT8_C(  49),  INT8_C( 107),  INT8_C(  82), -INT8_C(  14), -INT8_C(  37),  INT8_C(   7),  INT8_C(  73),  INT8_C(  20) },
       INT32_C(         203),
      {  INT16_C(   300),  INT16_C(   263),  INT16_C(   329),  INT16_C(   450),  INT16_C(   224),  INT16_C(   355),  INT16_C(   209),  INT16_C(   237),
         INT16_C(   388),  INT16_C(   452),  INT16_C(   331),  INT16_C(   322),  INT16_C(   327),  INT16_C(   314),  INT16_C(   223),  INT16_C(   438) } },
    { { -INT8_C(  69),  INT8_C(  61), -INT8_C(  38), -INT8_C( 111),  INT8_C(  50),  INT8_C( 119), -INT8_C(  10), -INT8_C(  29),
        -INT8_C(  37), -INT8_C( 114), -INT8_C( 125), -INT8_C( 113),  INT8_C(  43),  INT8_C(  25), -INT8_C(  63),  INT8_C( 118),
         INT8_C(  32), -INT8_C(  99),  INT8_C(  31),  INT8_C(  81),  INT8_C(   8),  INT8_C( 114),  INT8_C(  67), -INT8_C(  29),
         INT8_C( 121), -INT8_C( 116), -INT8_C(   8),  INT8_C(  68), -INT8_C(  18), -INT8_C(  75),  INT8_C(   4), -INT8_C(  87) },
      { -INT8_C(  13), -INT8_C(  33),  INT8_C(  58),  INT8_C(  37),  INT8_C(  86),  INT8_C(  49),  INT8_C(   8),  INT8_C(  49),
        -INT8_C(  65), -INT8_C( 116), -INT8_C(  63), -INT8_C(  21), -INT8_C(  91), -INT8_C( 126),  INT8_C(  97), -INT8_C(  59),
         INT8_C(  31),      INT8_MIN,  INT8_C(  22),  INT8_C(  39), -INT8_C(  14),  INT8_C(  90),  INT8_C(  10),  INT8_C( 108),
        -INT8_C(  26),  INT8_C(   2), -INT8_C(  80), -INT8_C(  44), -INT8_C(  72), -INT8_C(  75),  INT8_C( 126), -INT8_C(  85) },
       INT32_C(         148),
      {  INT16_C(   486),  INT16_C(   279),  INT16_C(   428),  INT16_C(   462),  INT16_C(   443),  INT16_C(   434),  INT16_C(    83),  INT16_C(   300),
         INT16_C(    81),  INT16_C(   400),  INT16_C(   401),  INT16_C(   399),  INT16_C(   449),  INT16_C(   463),  INT16_C(   694),  INT16_C(   188) } },
    { { -INT8_C(  23), -INT8_C(  39),  INT8_C(  28), -INT8_C(  87),  INT8_C( 101), -INT8_C(  35), -INT8_C( 108),  INT8_C(  10),
         INT8_C(  95), -INT8_C(  11), -INT8_C(  48),  INT8_C( 126),  INT8_C( 117), -INT8_C(  26), -INT8_C(  91),  INT8_C( 104),
         INT8_C(  64), -INT8_C(  81), -INT8_C(  44),  INT8_C(  39), -INT8_C(  78), -INT8_C( 124), -INT8_C(   5),  INT8_C( 106),
         INT8_C(  57),  INT8_C( 121),  INT8_C(  21), -INT8_C(  51),  INT8_C(  50), -INT8_C(  27), -INT8_C(  72),  INT8_C(  27) },
      { -INT8_C(  66), -INT8_C(  44), -INT8_C(  60),  INT8_C(  35), -INT8_C(  79),  INT8_C(  88),  INT8_C(  46),  INT8_C(  16),
         INT8_C(  77), -INT8_C(   2), -INT8_C( 114), -INT8_C(  61), -INT8_C(  28),  INT8_C(  51),  INT8_C(  43),  INT8_C(  37),
        -INT8_C(  30), -INT8_C(   1),  INT8_C(  76), -INT8_C( 108), -INT8_C( 125),  INT8_C(  71), -INT8_C(   2), -INT8_C(  67),
        -INT8_C(  63),  INT8_C(  19), -INT8_C( 118), -INT8_C(  13), -INT8_C(   7),  INT8_C(  66),  INT8_C(  14), -INT8_C(  73) },
       INT32_C(          22),
      {  INT16_C(   333),  INT16_C(   271),  INT16_C(   174),  INT16_C(   234),  INT16_C(   511),  INT16_C(   462),  INT16_C(   418),  INT16_C(   280),
         INT16_C(   563),  INT16_C(   205),  INT16_C(   306),  INT16_C(   394),  INT16_C(   373),  INT16_C(   336),  INT16_C(   514),  INT16_C(   262) } },
    { {  INT8_C(  43),  INT8_C(   9), -INT8_C(  41),  INT8_C( 121),  INT8_C(   7),  INT8_C( 101),  INT8_C(  60), -INT8_C(  21),
        -INT8_C( 104),  INT8_C( 103),  INT8_C(  16),  INT8_C( 123),  INT8_C( 102),  INT8_C(  92),  INT8_C(  15), -INT8_C(  23),
        -INT8_C(  92),  INT8_C(  14), -INT8_C(  90),  INT8_C( 101),  INT8_C(  33),  INT8_C(  49),  INT8_C(  88),  INT8_C(  26),
         INT8_C( 115),  INT8_C( 102), -INT8_C(  46), -INT8_C( 118),  INT8_C(  57), -INT8_C(  83),  INT8_C(  81),  INT8_C( 101) },
      { -INT8_C(  74),  INT8_C(  41), -INT8_C(  34), -INT8_C(  67), -INT8_C( 114),  INT8_C(  26), -INT8_C(  88),  INT8_C(  39),
        -INT8_C( 127), -INT8_C(  71), -INT8_C(  94), -INT8_C(  25),  INT8_C(  21), -INT8_C(  79), -INT8_C(  48), -INT8_C(  71),
        -INT8_C(  65),  INT8_C( 119),  INT8_C(  30), -INT8_C(  31), -INT8_C(  88),  INT8_C( 118), -INT8_C(   5),  INT8_C(  27),
        -INT8_C(  35), -INT8_C(  51), -INT8_C(  91),  INT8_C(  22),  INT8_C( 122), -INT8_C(   9),  INT8_C( 123),  INT8_C(  48) },
       INT32_C(          32),
      {  INT16_C(   246),  INT16_C(   302),  INT16_C(   619),  INT16_C(   295),  INT16_C(   359),  INT16_C(   366),  INT16_C(   558),  INT16_C(   256),
         INT16_C(   392),  INT16_C(   210),  INT16_C(   375),  INT16_C(   369),  INT16_C(   370),  INT16_C(   394),  INT16_C(   387),  INT16_C(   162) } },
    { {  INT8_C( 115), -INT8_C( 106), -INT8_C(  43), -INT8_C(  12),  INT8_C(  79),  INT8_C( 119), -INT8_C(  37),  INT8_C( 100),
         INT8_C(  41), -INT8_C(  84),  INT8_C(  30), -INT8_C(  24),  INT8_C(  35),  INT8_C(  60), -INT8_C(  55), -INT8_C(  53),
        -INT8_C(  77), -INT8_C(  59), -INT8_C(  26), -INT8_C( 112), -INT8_C( 110), -INT8_C( 116), -INT8_C(  90),  INT8_C(  13),
        -INT8_C( 125),  INT8_C(  34),  INT8_C(  61), -INT8_C(  93),  INT8_C( 123),  INT8_C(  43),  INT8_C(  81), -INT8_C(  17) },
      { -INT8_C(  63),  INT8_C(  39), -INT8_C(  29),  INT8_C(  16), -INT8_C(  98), -INT8_C(  65),  INT8_C( 116), -INT8_C(  57),
         INT8_C( 107), -INT8_C( 110), -INT8_C(  80), -INT8_C( 114), -INT8_C(  49),  INT8_C( 121),  INT8_C(  89), -INT8_C( 126),
         INT8_C(  62),  INT8_C(  63),  INT8_C(  18), -INT8_C(  47), -INT8_C(  53), -INT8_C(  72), -INT8_C(  34),  INT8_C(  78),
        -INT8_C(  38),  INT8_C(  27), -INT8_C(  15),  INT8_C(  86),  INT8_C(  70),  INT8_C(  67),  INT8_C(  69),  INT8_C(   7) },
       INT32_C(         106),
      {  INT16_C(   151),  INT16_C(   265),  INT16_C(   278),  INT16_C(   224),  INT16_C(   328),  INT16_C(   295),  INT16_C(   278),  INT16_C(   302),
         INT16_C(   278),  INT16_C(   414),  INT16_C(   215),  INT16_C(   505),  INT16_C(   351),  INT16_C(   376),  INT16_C(   338),  INT16_C(   317) } },
  };

  simde__m256i a, b, r;

  a = simde_x_mm256_loadu_epi8(test_vec[0].a);
  b = simde_x_mm256_loadu_epi8(test_vec[0].b);
  r = simde_mm256_dbsad_epu8(a, b, INT32_C(         219));
  simde_test_x86_assert_equal_i16x16(r, simde_x_mm256_loadu_epi16(test_vec[0].r));

  a = simde_x_mm256_loadu_epi8(test_vec[1].a);
  b = simde_x_mm256_loadu_epi8(test_vec[1].b);
  r = simde_mm256_dbsad_epu8(a, b, INT32_C(         166));
  simde_test_x86_assert_equal_i16x16(r, simde_x_mm256_loadu_epi16(test_vec[1].r));

  a = simde_x_mm256_loadu_epi8(test_vec[2].a);
  b = simde_x_mm256_loadu_epi8(test_vec[2].b);
  r = simde_mm256_dbsad_epu8(a, b, INT32_C(          74));
  simde_test_x86_assert_equal_i16x16(r, simde_x_mm256_loadu_epi16(test_vec[2].r));

  a = simde_x_mm256_loadu_epi8(test_vec[3].a);
  b = simde_x_mm256_loadu_epi8(test_vec[3].b);
  r = simde_mm256_dbsad_epu8(a, b, INT32_C(         203));
  simde_test_x86_assert_equal_i16x16(r, simde_x_mm256_loadu_epi16(test_vec[3].r));

  a = simde_x_mm256_loadu_epi8(test_vec[4].a);
  b = simde_x_mm256_loadu_epi8(test_vec[4].b);
  r = simde_mm256_dbsad_epu8(a, b, INT32_C(         148));
  simde_test_x86_assert_equal_i16x16(r, simde_x_mm256_loadu_epi16(test_vec[4].r));

  a = simde_x_mm256_loadu_epi8(test_vec[5].a);
  b = simde_x_mm256_loadu_epi8(test_vec[5].b);
  r = simde_mm256_dbsad_epu8(a, b, INT32_C(          22));
  simde_test_x86_assert_equal_i16x16(r, simde_x_mm256_loadu_epi16(test_vec[5].r));

  a = simde_x_mm256_loadu_epi8(test_vec[6].a);
  b = simde_x_mm256_loadu_epi8(test_vec[6].b);
  r = simde_mm256_dbsad_epu8(a, b, INT32_C(          32));
  simde_test_x86_assert_equal_i16x16(r, simde_x_mm256_loadu_epi16(test_vec[6].r));

  a = simde_x_mm256_loadu_epi8(test_vec[7].a);
  b = simde_x_mm256_loadu_epi8(test_vec[7].b);
  r = simde_mm256_dbsad_epu8(a, b, INT32_C(         106));
  simde_test_x86_assert_equal_i16x16(r, simde_x_mm256_loadu_epi16(test_vec[7].r));

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m256i a = simde_test_x86_random_i8x32();
    simde__m256i b = simde_test_x86_random_i8x32();
    int imm8 = simde_test_codegen_random_i32() & 255;
    simde__m256i r;
    SIMDE_CONSTIFY_256_(simde_mm256_dbsad_epu8, r, simde_mm256_setzero_si256(), imm8, a, b);

    simde_test_x86_write_i8x32(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i8x32(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, imm8, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i16x16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm256_mask_dbsad_epu8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int16_t src[16];
    const simde__mmask16 k;
    const int8_t a[32];
    const int8_t b[32];
    const int imm8;
    const int16_t r[16];
  } test_vec[] = {
    { { -INT16_C( 19070), -INT16_C( 28589),  INT16_C(  1660),  INT16_C( 14252),  INT16_C( 13131), -INT16_C( 25728),  INT16_C( 26178),  INT16_C(  4866),
        -INT16_C( 19303), -INT16_C(  4014),  INT16_C( 18642), -INT16_C( 20994), -INT16_C( 30021), -INT16_C( 13101),  INT16_C(  7186), -INT16_C( 27467) },
      UINT16_C( 2514),
      {  INT8_C(  36),  INT8_C(  78),  INT8_C(  15), -INT8_C(  48), -INT8_C( 123),  INT8_C(  90),  INT8_C(   3),  INT8_C(   5),
        -INT8_C(  10),  INT8_C(  69),  INT8_C( 108), -INT8_C(   8),  INT8_C(  88),  INT8_C(   5), -INT8_C(  84), -INT8_C(  86),
        -INT8_C(  11),  INT8_C( 126), -INT8_C(  14), -INT8_C(  13),  INT8_C(  44), -INT8_C(  83),  INT8_C( 126), -INT8_C(   1),
         INT8_C( 122), -INT8_C( 112),  INT8_C(  27),  INT8_C(  47),  INT8_C(  36), -INT8_C(  19),  INT8_C(  56),  INT8_C(  72) },
      {  INT8_C(  60),  INT8_C(  72),  INT8_C(  25), -INT8_C(  63), -INT8_C(  94),  INT8_C(  28), -INT8_C(  57), -INT8_C( 104),
         INT8_C(  98),  INT8_C(  51), -INT8_C( 111), -INT8_C(  70),  INT8_C(  56),  INT8_C(  61),  INT8_C( 101),  INT8_C(  46),
        -INT8_C(  68),  INT8_C(  87),  INT8_C(  33), -INT8_C(  24),  INT8_C(   5), -INT8_C(  97), -INT8_C(  25),      INT8_MAX,
         INT8_C(  47),  INT8_C(   2), -INT8_C(  82),  INT8_C(  83), -INT8_C(  16), -INT8_C(  25), -INT8_C( 100),  INT8_C(  44) },
       INT32_C(          47),
      { -INT16_C( 19070),  INT16_C(   231),  INT16_C(  1660),  INT16_C( 14252),  INT16_C(   265), -INT16_C( 25728),  INT16_C(   448),  INT16_C(   398),
         INT16_C(   395), -INT16_C(  4014),  INT16_C( 18642),  INT16_C(   271), -INT16_C( 30021), -INT16_C( 13101),  INT16_C(  7186), -INT16_C( 27467) } },
    { { -INT16_C( 19247),  INT16_C( 13162), -INT16_C(  1049),  INT16_C(  8430),  INT16_C( 21304), -INT16_C(  2994),  INT16_C( 28586), -INT16_C( 20516),
        -INT16_C( 15601),  INT16_C( 15918), -INT16_C(  8762), -INT16_C( 18798),  INT16_C( 11972), -INT16_C(  3102), -INT16_C( 12317), -INT16_C( 19260) },
      UINT16_C(11908),
      { -INT8_C(  24),  INT8_C( 107),  INT8_C(  41), -INT8_C(  42), -INT8_C( 117),  INT8_C(  98),  INT8_C(  41), -INT8_C(  39),
         INT8_C(  86), -INT8_C(  45),  INT8_C(  73),  INT8_C(  51), -INT8_C( 125),  INT8_C(  88), -INT8_C(  10), -INT8_C(  79),
        -INT8_C( 106), -INT8_C(  68), -INT8_C( 114),  INT8_C(  40),  INT8_C( 114),  INT8_C(  82),  INT8_C(  86),  INT8_C(  84),
         INT8_C(  69),  INT8_C(  57),  INT8_C(  36),  INT8_C(  10), -INT8_C(  18), -INT8_C(  88),  INT8_C(  56), -INT8_C(  42) },
      {  INT8_C(  19),  INT8_C(  98), -INT8_C(  84), -INT8_C(  97), -INT8_C(  60), -INT8_C(  43),  INT8_C( 120),  INT8_C(  26),
        -INT8_C(  88), -INT8_C(  63),  INT8_C(  77),  INT8_C(  43),  INT8_C(  25),  INT8_C(  68), -INT8_C(  35), -INT8_C(  80),
         INT8_C(   0),  INT8_C( 107), -INT8_C(  40),  INT8_C( 115), -INT8_C(  66),  INT8_C(  47), -INT8_C(  57),  INT8_C(   3),
         INT8_C( 104), -INT8_C(  21),  INT8_C(  13),  INT8_C(  86), -INT8_C( 109),  INT8_C(  70),  INT8_C(  44), -INT8_C(  89) },
       INT32_C(         168),
      { -INT16_C( 19247),  INT16_C( 13162),  INT16_C(   245),  INT16_C(  8430),  INT16_C( 21304), -INT16_C(  2994),  INT16_C( 28586),  INT16_C(   321),
        -INT16_C( 15601),  INT16_C(   162),  INT16_C(   304),  INT16_C(   243),  INT16_C( 11972),  INT16_C(   354), -INT16_C( 12317), -INT16_C( 19260) } },
    { { -INT16_C( 16723),  INT16_C( 22150), -INT16_C( 11136), -INT16_C( 26239),  INT16_C( 24088),  INT16_C(  6217),  INT16_C(  8906), -INT16_C( 30581),
         INT16_C( 21329), -INT16_C( 18037), -INT16_C( 26306), -INT16_C( 11760),  INT16_C( 15583), -INT16_C( 30855), -INT16_C( 16619), -INT16_C( 15629) },
      UINT16_C(31101),
      {  INT8_C(  24), -INT8_C(   3),  INT8_C(  77), -INT8_C( 102), -INT8_C( 105),  INT8_C( 101), -INT8_C(   8), -INT8_C(  32),
         INT8_C( 126), -INT8_C(  62),  INT8_C(   2),  INT8_C(   9),  INT8_C(  74),  INT8_C(  83),  INT8_C(  92), -INT8_C(  42),
         INT8_C(  13), -INT8_C( 101),  INT8_C( 111),  INT8_C(  29),  INT8_C( 109),  INT8_C(  78),  INT8_C(  89), -INT8_C(  26),
        -INT8_C(  43),  INT8_C( 110), -INT8_C(  91), -INT8_C(  56),  INT8_C(  49),  INT8_C(  34),  INT8_C(  65),  INT8_C(  73) },
      {  INT8_C(  32), -INT8_C( 113), -INT8_C(  29), -INT8_C(  73), -INT8_C(  12), -INT8_C(  36), -INT8_C( 105),  INT8_C( 114),
        -INT8_C(  98), -INT8_C( 102),  INT8_C( 124), -INT8_C(  23), -INT8_C(  19), -INT8_C(  40), -INT8_C(  65), -INT8_C(   6),
         INT8_C( 115),  INT8_C(  46),  INT8_C(  23), -INT8_C(  32),  INT8_C( 124),  INT8_C( 113), -INT8_C(  58),  INT8_C(  81),
        -INT8_C(  33),  INT8_C( 107),  INT8_C(  25),  INT8_C(  16), -INT8_C( 114),  INT8_C(  90),  INT8_C(  90), -INT8_C(  82) },
       INT32_C(         233),
      {  INT16_C(   367),  INT16_C( 22150),  INT16_C(   173),  INT16_C(   288),  INT16_C(   418),  INT16_C(   557),  INT16_C(   347), -INT16_C( 30581),
         INT16_C(   292), -INT16_C( 18037), -INT16_C( 26306),  INT16_C(   396),  INT16_C(   337),  INT16_C(   398),  INT16_C(   136), -INT16_C( 15629) } },
    { { -INT16_C(   999), -INT16_C( 18352), -INT16_C( 13162), -INT16_C( 31583),  INT16_C( 24741),  INT16_C(  6270), -INT16_C( 26994),  INT16_C(  2809),
        -INT16_C( 16633), -INT16_C(  6565),  INT16_C( 29739), -INT16_C( 17929),  INT16_C( 20942), -INT16_C( 18329), -INT16_C( 13170), -INT16_C( 22378) },
      UINT16_C(59080),
      {  INT8_C(  96),  INT8_C(  95), -INT8_C(  77),  INT8_C(   1), -INT8_C(  29),  INT8_C(  88),  INT8_C(  97),  INT8_C(  97),
         INT8_C( 112), -INT8_C(  17), -INT8_C(   9),  INT8_C( 105), -INT8_C(   7), -INT8_C(   2),  INT8_C(  41),  INT8_C(  84),
        -INT8_C(  27),  INT8_C(  84), -INT8_C(  56), -INT8_C(  36),  INT8_C(  13), -INT8_C( 106),  INT8_C(  45),  INT8_C( 116),
         INT8_C(  78), -INT8_C(  69),  INT8_C(  64), -INT8_C(  28),  INT8_C(  99),  INT8_C(   8), -INT8_C(  53), -INT8_C(  61) },
      {  INT8_C( 103),  INT8_C( 126), -INT8_C(  60),  INT8_C(  74), -INT8_C(  42),  INT8_C(  37), -INT8_C(  84),  INT8_C(  70),
         INT8_C(  20), -INT8_C(  93), -INT8_C(  80),  INT8_C(  13), -INT8_C(  94), -INT8_C(  39),  INT8_C(  97), -INT8_C( 121),
         INT8_C(  45),  INT8_C(  41),  INT8_C(  99),  INT8_C(  58), -INT8_C(  64), -INT8_C( 112), -INT8_C(  82),  INT8_C(  14),
         INT8_C(  75), -INT8_C(  18), -INT8_C(  13), -INT8_C(  81), -INT8_C(  10), -INT8_C(  66),  INT8_C( 114),  INT8_C(  94) },
       INT32_C(          60),
      { -INT16_C(   999), -INT16_C( 18352), -INT16_C( 13162),  INT16_C(   347),  INT16_C( 24741),  INT16_C(  6270),  INT16_C(   375),  INT16_C(   462),
        -INT16_C( 16633),  INT16_C(   371),  INT16_C(   453), -INT16_C( 17929),  INT16_C( 20942),  INT16_C(   398),  INT16_C(   413),  INT16_C(   300) } },
    { {  INT16_C( 21596),  INT16_C( 29016),  INT16_C(  2296), -INT16_C( 25986), -INT16_C(  7967),  INT16_C(  3617), -INT16_C( 31735), -INT16_C( 14008),
        -INT16_C(  2540),  INT16_C( 24536), -INT16_C( 13340), -INT16_C(  9458), -INT16_C( 32375), -INT16_C( 15047), -INT16_C(  7752),  INT16_C(  5335) },
      UINT16_C(12086),
      { -INT8_C( 123),  INT8_C(  46),  INT8_C(  56),  INT8_C(   4), -INT8_C(  56),  INT8_C(  25), -INT8_C(  28), -INT8_C(  23),
         INT8_C(  40), -INT8_C(  19),  INT8_C( 109),  INT8_C( 112), -INT8_C(  73), -INT8_C( 127),  INT8_C( 103), -INT8_C( 113),
        -INT8_C(  32),  INT8_C(  75),  INT8_C(  90), -INT8_C(  17),  INT8_C(  38), -INT8_C(  29),  INT8_C( 112),  INT8_C(  95),
        -INT8_C(  88),  INT8_C(  40),  INT8_C(  65),      INT8_MAX,  INT8_C(  60),  INT8_C( 119), -INT8_C(  82), -INT8_C(  62) },
      { -INT8_C(  91), -INT8_C(  26), -INT8_C(  58),  INT8_C( 109),  INT8_C(   0), -INT8_C(  86),  INT8_C(  86),  INT8_C(  40),
        -INT8_C( 105), -INT8_C(  61), -INT8_C( 104),  INT8_C(  78),  INT8_C(  68), -INT8_C(   1), -INT8_C(  35),  INT8_C(  36),
         INT8_C(  75),  INT8_C(  55),  INT8_C(  19),  INT8_C( 113),  INT8_C(  26), -INT8_C( 125), -INT8_C(  47), -INT8_C(  62),
        -INT8_C(  85),  INT8_C(  18),  INT8_C(  65), -INT8_C(  24), -INT8_C( 119), -INT8_C(  16), -INT8_C(  86),  INT8_C(  46) },
       INT32_C(         214),
      {  INT16_C( 21596),  INT16_C(   194),  INT16_C(   392), -INT16_C( 25986),  INT16_C(   202),  INT16_C(   394), -INT16_C( 31735), -INT16_C( 14008),
         INT16_C(   142),  INT16_C(   571),  INT16_C(   154),  INT16_C(   528), -INT16_C( 32375),  INT16_C(   345), -INT16_C(  7752),  INT16_C(  5335) } },
    { { -INT16_C(  3814), -INT16_C( 19970), -INT16_C( 26700), -INT16_C(  2048), -INT16_C(  8810), -INT16_C(  7908),  INT16_C( 12309),  INT16_C( 12115),
         INT16_C(  9395),  INT16_C( 24562),  INT16_C( 13110), -INT16_C( 16569), -INT16_C(  3805), -INT16_C(  1299), -INT16_C( 30623),  INT16_C( 31696) },
      UINT16_C(53113),
      {  INT8_C(  44),  INT8_C(  45),  INT8_C( 102),  INT8_C(  44),  INT8_C(  37), -INT8_C(   4),  INT8_C(  10),  INT8_C(  65),
        -INT8_C(  34),  INT8_C(  31),  INT8_C( 113),  INT8_C(  49),  INT8_C(  78),  INT8_C(  37),  INT8_C(  85),  INT8_C(  64),
        -INT8_C( 124), -INT8_C( 117),  INT8_C( 116), -INT8_C(  53),  INT8_C(  74), -INT8_C( 105), -INT8_C(  68),  INT8_C(  55),
        -INT8_C( 111),  INT8_C(  29), -INT8_C(  65),  INT8_C(  98), -INT8_C( 104),  INT8_C(  56),  INT8_C(  49), -INT8_C(  60) },
      {  INT8_C( 101), -INT8_C( 105), -INT8_C(  15), -INT8_C( 118), -INT8_C( 109), -INT8_C(   5), -INT8_C(  53),  INT8_C( 113),
         INT8_C(  26),  INT8_C(  61), -INT8_C(  94),  INT8_C( 104),  INT8_C(  98), -INT8_C(   9), -INT8_C(  87), -INT8_C(  26),
        -INT8_C( 126),  INT8_C(  29), -INT8_C(  79), -INT8_C(  52), -INT8_C(  76),  INT8_C( 109),  INT8_C(   3),  INT8_C(  70),
        -INT8_C( 118), -INT8_C(  62), -INT8_C(  88),  INT8_C(  34), -INT8_C(   6), -INT8_C(  39), -INT8_C(  26),  INT8_C(  95) },
       INT32_C(         112),
      {  INT16_C(   396), -INT16_C( 19970), -INT16_C( 26700),  INT16_C(   569),  INT16_C(   577),  INT16_C(   378),  INT16_C(   533),  INT16_C( 12115),
         INT16_C(   174),  INT16_C(   302),  INT16_C(   240),  INT16_C(   432), -INT16_C(  3805), -INT16_C(  1299),  INT16_C(   335),  INT16_C(   434) } },
    { { -INT16_C( 18990), -INT16_C(  5003),  INT16_C(  6130),  INT16_C( 21589), -INT16_C(   497), -INT16_C( 28358), -INT16_C(  5349), -INT16_C( 12450),
         INT16_C( 24920), -INT16_C(  7659), -INT16_C( 17116),  INT16_C(  7684), -INT16_C(  5482),  INT16_C(  1662),  INT16_C( 26562), -INT16_C( 27638) },
      UINT16_C(32540),
      { -INT8_C( 127),  INT8_C(  14), -INT8_C( 106), -INT8_C(  42),  INT8_C(  98), -INT8_C(  91), -INT8_C(  44), -INT8_C( 100),
         INT8_C(  55), -INT8_C(  17), -INT8_C( 121), -INT8_C( 107), -INT8_C(  66), -INT8_C(  33), -INT8_C(  10), -INT8_C(  44),
        -INT8_C(  63),  INT8_C(  26), -INT8_C( 111), -INT8_C(  59),  INT8_C(  57),  INT8_C(  40), -INT8_C(  80), -INT8_C(  73),
         INT8_C(  46),  INT8_C( 114),  INT8_C(  30),  INT8_C(  56),  INT8_C(   6),  INT8_C(  59), -INT8_C(  73), -INT8_C( 121) },
      {  INT8_C(  73),  INT8_C(  78),  INT8_C(  93), -INT8_C(  84), -INT8_C(  13),  INT8_C(  49),  INT8_C(  72),  INT8_C(  42),
         INT8_C(  32), -INT8_C(  48), -INT8_C(  65), -INT8_C(  33), -INT8_C(  81), -INT8_C(  74), -INT8_C(  77),  INT8_C( 113),
        -INT8_C(  48),  INT8_C(  68),  INT8_C(  54),  INT8_C(   9),  INT8_C( 108), -INT8_C(  26), -INT8_C(  64), -INT8_C( 101),
         INT8_C(  88), -INT8_C(  33), -INT8_C(  45),  INT8_C(  95),  INT8_C(  26), -INT8_C( 117), -INT8_C(  26),  INT8_C(  99) },
       INT32_C(         217),
      { -INT16_C( 18990), -INT16_C(  5003),  INT16_C(   381),  INT16_C(   228),  INT16_C(   548), -INT16_C( 28358), -INT16_C(  5349), -INT16_C( 12450),
         INT16_C(   378),  INT16_C(   322),  INT16_C(   378),  INT16_C(   221),  INT16_C(   439),  INT16_C(   417),  INT16_C(   443), -INT16_C( 27638) } },
    { {  INT16_C( 22645), -INT16_C( 26889), -INT16_C( 18904), -INT16_C( 10379),  INT16_C( 10348),  INT16_C( 15688),  INT16_C( 32620), -INT16_C(  9914),
         INT16_C(  1893), -INT16_C( 16780),  INT16_C( 18406),  INT16_C(    29),  INT16_C(   978), -INT16_C( 21661),  INT16_C( 29511), -INT16_C( 17032) },
      UINT16_C(28619),
      {  INT8_C(  83), -INT8_C(  13),  INT8_C(  37), -INT8_C(  56), -INT8_C(  54), -INT8_C( 110), -INT8_C(  16),  INT8_C(  19),
        -INT8_C(  49),  INT8_C(  92), -INT8_C( 110),  INT8_C(  21),  INT8_C(  53), -INT8_C(   9),  INT8_C(  28), -INT8_C(  87),
        -INT8_C(  75),  INT8_C(   2), -INT8_C(  15), -INT8_C(  46),  INT8_C(   2), -INT8_C(  61), -INT8_C(  42),  INT8_C( 102),
         INT8_C( 111),  INT8_C(  29), -INT8_C(  39), -INT8_C(  25), -INT8_C(  38), -INT8_C(  92),  INT8_C(  86),  INT8_C(  45) },
      { -INT8_C( 105),  INT8_C( 123), -INT8_C(  11),  INT8_C(  97),  INT8_C(  13), -INT8_C(  27),  INT8_C( 116), -INT8_C(  36),
         INT8_C(  66),  INT8_C(   6), -INT8_C(  14),  INT8_C( 119), -INT8_C(   2),  INT8_C(  14),  INT8_C(  33), -INT8_C(  77),
         INT8_C(  17),  INT8_C(  18), -INT8_C( 122),  INT8_C(  19), -INT8_C(  43),  INT8_C(  92),  INT8_C( 121),  INT8_C(  68),
         INT8_C( 121),  INT8_C(  82),  INT8_C(  43),  INT8_C(  84), -INT8_C(  10), -INT8_C( 127), -INT8_C( 127), -INT8_C( 115) },
       INT32_C(         253),
      {  INT16_C(   183),  INT16_C(   510), -INT16_C( 18904),  INT16_C(   366),  INT16_C( 10348),  INT16_C( 15688),  INT16_C(   469),  INT16_C(   283),
         INT16_C(   384),  INT16_C(   417),  INT16_C(   305),  INT16_C(   229),  INT16_C(   978),  INT16_C(   209),  INT16_C(   356), -INT16_C( 17032) } },
  };

  simde__m256i src, a, b, r;

  src = simde_x_mm256_loadu_epi16(test_vec[0].src);
  a = simde_x_mm256_loadu_epi8(test_vec[0].a);
  b = simde_x_mm256_loadu_epi8(test_vec[0].b);
  r = simde_mm256_mask_dbsad_epu8(src, test_vec[0].k, a, b, INT32_C(          47));
  simde_test_x86_assert_equal_i16x16(r, simde_x_mm256_loadu_epi16(test_vec[0].r));

  src = simde_x_mm256_loadu_epi16(test_vec[1].src);
  a = simde_x_mm256_loadu_epi8(test_vec[1].a);
  b = simde_x_mm256_loadu_epi8(test_vec[1].b);
  r = simde_mm256_mask_dbsad_epu8(src, test_vec[1].k, a, b, INT32_C(         168));
  simde_test_x86_assert_equal_i16x16(r, simde_x_mm256_loadu_epi16(test_vec[1].r));

  src = simde_x_mm256_loadu_epi16(test_vec[2].src);
  a = simde_x_mm256_loadu_epi8(test_vec[2].a);
  b = simde_x_mm256_loadu_epi8(test_vec[2].b);
  r = simde_mm256_mask_dbsad_epu8(src, test_vec[2].k, a, b, INT32_C(         233));
  simde_test_x86_assert_equal_i16x16(r, simde_x_mm256_loadu_epi16(test_vec[2].r));

  src = simde_x_mm256_loadu_epi16(test_vec[3].src);
  a = simde_x_mm256_loadu_epi8(test_vec[3].a);
  b = simde_x_mm256_loadu_epi8(test_vec[3].b);
  r = simde_mm256_mask_dbsad_epu8(src, test_vec[3].k, a, b, INT32_C(          60));
  simde_test_x86_assert_equal_i16x16(r, simde_x_mm256_loadu_epi16(test_vec[3].r));

  src = simde_x_mm256_loadu_epi16(test_vec[4].src);
  a = simde_x_mm256_loadu_epi8(test_vec[4].a);
  b = simde_x_mm256_loadu_epi8(test_vec[4].b);
  r = simde_mm256_mask_dbsad_epu8(src, test_vec[4].k, a, b, INT32_C(         214));
  simde_test_x86_assert_equal_i16x16(r, simde_x_mm256_loadu_epi16(test_vec[4].r));

  src = simde_x_mm256_loadu_epi16(test_vec[5].src);
  a = simde_x_mm256_loadu_epi8(test_vec[5].a);
  b = simde_x_mm256_loadu_epi8(test_vec[5].b);
  r = simde_mm256_mask_dbsad_epu8(src, test_vec[5].k, a, b, INT32_C(         112));
  simde_test_x86_assert_equal_i16x16(r, simde_x_mm256_loadu_epi16(test_vec[5].r));

  src = simde_x_mm256_loadu_epi16(test_vec[6].src);
  a = simde_x_mm256_loadu_epi8(test_vec[6].a);
  b = simde_x_mm256_loadu_epi8(test_vec[6].b);
  r = simde_mm256_mask_dbsad_epu8(src, test_vec[6].k, a, b, INT32_C(         217));
  simde_test_x86_assert_equal_i16x16(r, simde_x_mm256_loadu_epi16(test_vec[6].r));

  src = simde_x_mm256_loadu_epi16(test_vec[7].src);
  a = simde_x_mm256_loadu_epi8(test_vec[7].a);
  b = simde_x_mm256_loadu_epi8(test_vec[7].b);
  r = simde_mm256_mask_dbsad_epu8(src, test_vec[7].k, a, b, INT32_C(         253));
  simde_test_x86_assert_equal_i16x16(r, simde_x_mm256_loadu_epi16(test_vec[7].r));

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m256i src = simde_test_x86_random_i16x16();
    simde__mmask16 k = simde_test_x86_random_mmask16();
    simde__m256i a = simde_test_x86_random_i8x32();
    simde__m256i b = simde_test_x86_random_i8x32();
    int imm8 = simde_test_codegen_random_i32() & 255;
    simde__m256i r;
    SIMDE_CONSTIFY_256_(simde_mm256_mask_dbsad_epu8, r, simde_mm256_setzero_si256(), imm8, src, k, a, b);

    simde_test_x86_write_i16x16(2, src, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_mmask16(2, k, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i8x32(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i8x32(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, imm8, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i16x16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm256_maskz_dbsad_epu8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask16 k;
    const int8_t a[32];
    const int8_t b[32];
    const int imm8;
    const int16_t r[16];
  } test_vec[] = {
    { UINT16_C( 1344),
      {  INT8_C(  45),  INT8_C(  84), -INT8_C(  64), -INT8_C(  68),  INT8_C(  64), -INT8_C(  34), -INT8_C( 125),  INT8_C( 119),
        -INT8_C(  95), -INT8_C(  36),  INT8_C(  49), -INT8_C(  66),  INT8_C(  41), -INT8_C(  78),  INT8_C(  35),  INT8_C(  68),
        -INT8_C( 108), -INT8_C(  38),  INT8_C(  18), -INT8_C(  16), -INT8_C(  20),  INT8_C(  97), -INT8_C( 112),  INT8_C(  67),
         INT8_C(  88),  INT8_C(  58),  INT8_C(  61),  INT8_C(  56), -INT8_C(  25),  INT8_C( 125),  INT8_C(  61),  INT8_C(  20) },
      { -INT8_C(  46), -INT8_C(   2), -INT8_C(  48),  INT8_C(  18), -INT8_C(  36),  INT8_C(  83), -INT8_C( 119),  INT8_C( 125),
         INT8_C(  48), -INT8_C(  69),  INT8_C(  59),  INT8_C(  89),  INT8_C( 109),  INT8_C(  95), -INT8_C(  98),  INT8_C(   1),
         INT8_C(  57), -INT8_C(  80), -INT8_C(  15),  INT8_C(  37),  INT8_C(  17), -INT8_C( 127),  INT8_C( 104),  INT8_C( 105),
        -INT8_C(  68), -INT8_C(  90), -INT8_C(  94), -INT8_C(  93),  INT8_C(  35), -INT8_C(  33), -INT8_C(  73), -INT8_C(  11) },
       INT32_C(         221),
      {  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(   250),  INT16_C(     0),
         INT16_C(   441),  INT16_C(     0),  INT16_C(   405),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0) } },
    { UINT16_C(37338),
      {  INT8_C(  54),  INT8_C(  10),  INT8_C(  76),  INT8_C( 114),  INT8_C( 100), -INT8_C(  71), -INT8_C(  47),  INT8_C(   2),
        -INT8_C(  70),  INT8_C(  10), -INT8_C(  78), -INT8_C(  85),  INT8_C(  47), -INT8_C(  61),  INT8_C(  44), -INT8_C( 104),
         INT8_C(  44), -INT8_C(  24),  INT8_C(  62), -INT8_C(  50), -INT8_C( 117),  INT8_C(  97), -INT8_C(  82),  INT8_C(  66),
         INT8_C(  87), -INT8_C( 117), -INT8_C(  55),  INT8_C(  94),  INT8_C(  69), -INT8_C(  92), -INT8_C(  17),  INT8_C( 123) },
      { -INT8_C(  82),  INT8_C(  59), -INT8_C(  19),  INT8_C(  18), -INT8_C(  12), -INT8_C(  66),  INT8_C(  20), -INT8_C(  82),
        -INT8_C(  56), -INT8_C(  58),  INT8_C(  89), -INT8_C(   8), -INT8_C( 119), -INT8_C( 122), -INT8_C( 112), -INT8_C(  74),
         INT8_C( 110), -INT8_C(  50), -INT8_C( 124), -INT8_C(   6),  INT8_C(  47),  INT8_C(  50),  INT8_C(  60), -INT8_C( 122),
        -INT8_C(  66),  INT8_C(   6), -INT8_C(  27),  INT8_C(   3), -INT8_C(  86), -INT8_C(  44),  INT8_C( 126),  INT8_C(  88) },
       INT32_C(          16),
      {  INT16_C(     0),  INT16_C(   350),  INT16_C(     0),  INT16_C(   478),  INT16_C(   399),  INT16_C(     0),  INT16_C(   271),  INT16_C(   248),
         INT16_C(   206),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(   310),  INT16_C(     0),  INT16_C(     0),  INT16_C(   161) } },
    { UINT16_C(32554),
      { -INT8_C(  77), -INT8_C(  13),  INT8_C(  70),  INT8_C(  12), -INT8_C(  21), -INT8_C(  49), -INT8_C( 110),  INT8_C( 123),
        -INT8_C( 123),  INT8_C(   1),  INT8_C(  73),  INT8_C(  10), -INT8_C(   5),  INT8_C( 120),  INT8_C(  60),  INT8_C(  55),
        -INT8_C(   1), -INT8_C(   6),  INT8_C(  61), -INT8_C(  28), -INT8_C(   3), -INT8_C(  25), -INT8_C(  72),  INT8_C( 124),
         INT8_C(  64), -INT8_C(  56), -INT8_C(  24), -INT8_C(  85), -INT8_C(  51),  INT8_C(  18),  INT8_C(  42),      INT8_MIN },
      {  INT8_C(   5),  INT8_C( 112), -INT8_C( 116), -INT8_C(  16),  INT8_C(  64),  INT8_C(  31),  INT8_C( 107), -INT8_C(  59),
         INT8_C(  32), -INT8_C(  76), -INT8_C(  49),  INT8_C(  27),  INT8_C(  45),  INT8_C(  12),  INT8_C(  82),  INT8_C(  44),
         INT8_C(   6), -INT8_C( 112),  INT8_C(  16),  INT8_C(   4),  INT8_C( 119), -INT8_C(  56),      INT8_MIN, -INT8_C(  73),
        -INT8_C( 111),  INT8_C( 104),  INT8_C(  98),  INT8_C(  94),  INT8_C( 122), -INT8_C( 115), -INT8_C(  34),      INT8_MIN },
       INT32_C(         253),
      {  INT16_C(     0),  INT16_C(   444),  INT16_C(     0),  INT16_C(   375),  INT16_C(     0),  INT16_C(   266),  INT16_C(     0),  INT16_C(     0),
         INT16_C(   298),  INT16_C(   405),  INT16_C(   252),  INT16_C(   320),  INT16_C(   170),  INT16_C(   252),  INT16_C(   220),  INT16_C(     0) } },
    { UINT16_C(56457),
      {  INT8_C(   3), -INT8_C(  87), -INT8_C( 112), -INT8_C(  46), -INT8_C(  60), -INT8_C(  67), -INT8_C(  34),  INT8_C(  23),
        -INT8_C(  23), -INT8_C(  27), -INT8_C(  89), -INT8_C(   7), -INT8_C(  23),  INT8_C(  30), -INT8_C(  62),  INT8_C( 105),
        -INT8_C(  42),  INT8_C(  83), -INT8_C(  47),  INT8_C(  56), -INT8_C(  79),  INT8_C(  75), -INT8_C(  59), -INT8_C( 113),
        -INT8_C(  53), -INT8_C(  61), -INT8_C(   7),  INT8_C(  60),  INT8_C(   0), -INT8_C( 125),  INT8_C(  24),  INT8_C(   3) },
      {  INT8_C(  44), -INT8_C(  88), -INT8_C(  42), -INT8_C(  15),  INT8_C( 102), -INT8_C(  76),  INT8_C(   8),  INT8_C(  79),
        -INT8_C( 103), -INT8_C(  81),  INT8_C(  73), -INT8_C( 126), -INT8_C(  51),  INT8_C(  11), -INT8_C(  21), -INT8_C(  93),
         INT8_C(  94), -INT8_C(  68), -INT8_C(  36),  INT8_C(  15),  INT8_C(   8), -INT8_C(  95), -INT8_C(  98), -INT8_C(  45),
         INT8_C( 100), -INT8_C( 105),  INT8_C(  15),  INT8_C( 101),  INT8_C(  26),  INT8_C(  39),  INT8_C( 104),  INT8_C(  71) },
       INT32_C(         208),
      {  INT16_C(   143),  INT16_C(     0),  INT16_C(     0),  INT16_C(   435),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(   642),
         INT16_C(     0),  INT16_C(     0),  INT16_C(   251),  INT16_C(   267),  INT16_C(   471),  INT16_C(     0),  INT16_C(   276),  INT16_C(   432) } },
    { UINT16_C(16627),
      { -INT8_C( 123), -INT8_C( 116), -INT8_C(  17), -INT8_C(  50),  INT8_C(  15), -INT8_C(  68), -INT8_C(  39), -INT8_C(   6),
         INT8_C(  96),  INT8_C(  55), -INT8_C(  73),  INT8_C(  60),  INT8_C(  70), -INT8_C(  65), -INT8_C(  35), -INT8_C(  28),
        -INT8_C( 110),  INT8_C(  66),  INT8_C( 124), -INT8_C(  94), -INT8_C(  89), -INT8_C( 106), -INT8_C(  55),  INT8_C(  15),
        -INT8_C(  35), -INT8_C( 103),  INT8_C(  78),  INT8_C(  21), -INT8_C(  49),  INT8_C(  65),  INT8_C(  85),  INT8_C(  85) },
      { -INT8_C(  51),  INT8_C(  68),  INT8_C(  35), -INT8_C(  36),  INT8_C(   1), -INT8_C(   3), -INT8_C(  41),  INT8_C(  97),
         INT8_C(  52), -INT8_C( 114), -INT8_C(  99),  INT8_C( 123),  INT8_C(  77),  INT8_C( 122),  INT8_C(  95), -INT8_C(  33),
        -INT8_C(  68), -INT8_C(  37), -INT8_C( 127),  INT8_C(  99),  INT8_C( 114),  INT8_C(  75),  INT8_C( 115),  INT8_C(  79),
        -INT8_C(  28), -INT8_C(  63),  INT8_C( 101), -INT8_C(  76),  INT8_C(   2), -INT8_C(  70),  INT8_C(   9), -INT8_C(  49) },
       INT32_C(         255),
      {  INT16_C(   235),  INT16_C(   201),  INT16_C(     0),  INT16_C(     0),  INT16_C(   337),  INT16_C(   123),  INT16_C(   307),  INT16_C(   499),
         INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(   524),  INT16_C(     0) } },
    { UINT16_C(33577),
      {  INT8_C(  97),  INT8_C(  94),  INT8_C(  17), -INT8_C(   2), -INT8_C(  39),  INT8_C(  94),  INT8_C( 120),  INT8_C(  56),
         INT8_C(  61),  INT8_C(  53),  INT8_C(  20), -INT8_C(  65), -INT8_C( 104), -INT8_C( 122),  INT8_C(  10),  INT8_C(  11),
        -INT8_C(  43), -INT8_C(  18), -INT8_C(  52),  INT8_C(  58), -INT8_C(  94), -INT8_C(  50), -INT8_C(  11), -INT8_C(  85),
        -INT8_C(  98), -INT8_C(  12), -INT8_C(  40),  INT8_C(  74), -INT8_C(  12),  INT8_C(   1), -INT8_C(  51),  INT8_C(  85) },
      {  INT8_C(  95), -INT8_C(  34),  INT8_C(  83),  INT8_C(  56),  INT8_C(  60), -INT8_C(  53),  INT8_C( 113),  INT8_C( 121),
         INT8_C(   0), -INT8_C( 123),  INT8_C(  56), -INT8_C( 103),  INT8_C(  11),  INT8_C(  66), -INT8_C(  92), -INT8_C(  32),
         INT8_C(  49),  INT8_C( 113),  INT8_C(  27), -INT8_C(  45),  INT8_C(  63),  INT8_C(  16),      INT8_MAX, -INT8_C(  35),
         INT8_C(   4),  INT8_C(  87),  INT8_C(  39), -INT8_C(   8),  INT8_C(  88), -INT8_C(  12),  INT8_C(  77), -INT8_C(  72) },
       INT32_C(         210),
      {  INT16_C(   276),  INT16_C(     0),  INT16_C(     0),  INT16_C(   194),  INT16_C(     0),  INT16_C(   483),  INT16_C(     0),  INT16_C(     0),
         INT16_C(   715),  INT16_C(   378),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(   157) } },
    { UINT16_C(24939),
      { -INT8_C( 120),  INT8_C( 108), -INT8_C(  26), -INT8_C(  64),  INT8_C(   5), -INT8_C(  15),  INT8_C(   3), -INT8_C(  87),
        -INT8_C(  46),  INT8_C(  52),  INT8_C(  26), -INT8_C(  19),  INT8_C(   7),  INT8_C(  90), -INT8_C(   3), -INT8_C( 122),
         INT8_C(  55),  INT8_C(   1), -INT8_C(  35),  INT8_C(  95), -INT8_C(   7),  INT8_C(  54),  INT8_C(  83),  INT8_C(  70),
        -INT8_C(  18),  INT8_C(  38), -INT8_C(  26), -INT8_C(  34),  INT8_C(  52),  INT8_C(  81),  INT8_C(  64), -INT8_C(  68) },
      { -INT8_C(  67),  INT8_C(  38),  INT8_C( 125), -INT8_C(  62),  INT8_C(  24),      INT8_MIN,  INT8_C( 108), -INT8_C(  22),
        -INT8_C(  76), -INT8_C( 122), -INT8_C(  41), -INT8_C(  69), -INT8_C(  32), -INT8_C(  44),  INT8_C(  66),  INT8_C(  24),
        -INT8_C(  43),  INT8_C(  31),  INT8_C( 119), -INT8_C(  50),  INT8_C(  85), -INT8_C(  54),  INT8_C(  20),  INT8_C(  67),
        -INT8_C(  16), -INT8_C(   6),  INT8_C(  34),  INT8_C(  37),  INT8_C(  75),  INT8_C(  98), -INT8_C(  31),  INT8_C(   9) },
       INT32_C(         136),
      {  INT16_C(   230),  INT16_C(   163),  INT16_C(     0),  INT16_C(   427),  INT16_C(     0),  INT16_C(   470),  INT16_C(   295),  INT16_C(     0),
         INT16_C(   401),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(   330),  INT16_C(   430),  INT16_C(     0) } },
    { UINT16_C(14302),
      { -INT8_C( 118), -INT8_C( 110), -INT8_C(  66),  INT8_C(  97),  INT8_C(  78), -INT8_C(  98),  INT8_C(  53), -INT8_C( 112),
        -INT8_C(  74),  INT8_C(  10), -INT8_C(  81),  INT8_C(  45), -INT8_C(  40),  INT8_C(   5), -INT8_C(   8), -INT8_C(  20),
         INT8_C(  72), -INT8_C(  24), -INT8_C(  26),  INT8_C( 106),  INT8_C(  13),  INT8_C(  50), -INT8_C(  52), -INT8_C(  17),
         INT8_C(  59),  INT8_C(  85),  INT8_C(  77),  INT8_C(   6), -INT8_C(  11),  INT8_C(  44),  INT8_C(  62),      INT8_MIN },
      { -INT8_C(  66), -INT8_C(   4), -INT8_C(  31),  INT8_C(  12), -INT8_C( 102),  INT8_C(  23), -INT8_C( 100),  INT8_C(  81),
         INT8_C(  33),  INT8_C(  76),  INT8_C( 126), -INT8_C(   6),  INT8_C(  81),  INT8_C( 118), -INT8_C(  26), -INT8_C( 103),
         INT8_C(  95), -INT8_C(  51),  INT8_C(   4),  INT8_C( 108), -INT8_C(   1), -INT8_C(  48),  INT8_C(  91),  INT8_C(  58),
         INT8_C(  37), -INT8_C(  87),  INT8_C(  64),  INT8_C(  27), -INT8_C(  43),  INT8_C( 126), -INT8_C( 101), -INT8_C( 109) },
       INT32_C(         122),
      {  INT16_C(     0),  INT16_C(   206),  INT16_C(   228),  INT16_C(   338),  INT16_C(   372),  INT16_C(     0),  INT16_C(   469),  INT16_C(   517),
         INT16_C(   343),  INT16_C(   537),  INT16_C(   311),  INT16_C(     0),  INT16_C(   414),  INT16_C(   456),  INT16_C(     0),  INT16_C(     0) } },
  };

  simde__m256i a, b, r;

  a = simde_x_mm256_loadu_epi8(test_vec[0].a);
  b = simde_x_mm256_loadu_epi8(test_vec[0].b);
  r = simde_mm256_maskz_dbsad_epu8(test_vec[0].k, a, b, INT32_C(         221));
  simde_test_x86_assert_equal_i16x16(r, simde_x_mm256_loadu_epi16(test_vec[0].r));

  a = simde_x_mm256_loadu_epi8(test_vec[1].a);
  b = simde_x_mm256_loadu_epi8(test_vec[1].b);
  r = simde_mm256_maskz_dbsad_epu8(test_vec[1].k, a, b, INT32_C(          16));
  simde_test_x86_assert_equal_i16x16(r, simde_x_mm256_loadu_epi16(test_vec[1].r));

  a = simde_x_mm256_loadu_epi8(test_vec[2].a);
  b = simde_x_mm256_loadu_epi8(test_vec[2].b);
  r = simde_mm256_maskz_dbsad_epu8(test_vec[2].k, a, b, INT32_C(         253));
  simde_test_x86_assert_equal_i16x16(r, simde_x_mm256_loadu_epi16(test_vec[2].r));

  a = simde_x_mm256_loadu_epi8(test_vec[3].a);
  b = simde_x_mm256_loadu_epi8(test_vec[3].b);
  r = simde_mm256_maskz_dbsad_epu8(test_vec[3].k, a, b, INT32_C(         208));
  simde_test_x86_assert_equal_i16x16(r, simde_x_mm256_loadu_epi16(test_vec[3].r));

  a = simde_x_mm256_loadu_epi8(test_vec[4].a);
  b = simde_x_mm256_loadu_epi8(test_vec[4].b);
  r = simde_mm256_maskz_dbsad_epu8(test_vec[4].k, a, b, INT32_C(         255));
  simde_test_x86_assert_equal_i16x16(r, simde_x_mm256_loadu_epi16(test_vec[4].r));

  a = simde_x_mm256_loadu_epi8(test_vec[5].a);
  b = simde_x_mm256_loadu_epi8(test_vec[5].b);
  r = simde_mm256_maskz_dbsad_epu8(test_vec[5].k, a, b, INT32_C(         210));
  simde_test_x86_assert_equal_i16x16(r, simde_x_mm256_loadu_epi16(test_vec[5].r));

  a = simde_x_mm256_loadu_epi8(test_vec[6].a);
  b = simde_x_mm256_loadu_epi8(test_vec[6].b);
  r = simde_mm256_maskz_dbsad_epu8(test_vec[6].k, a, b, INT32_C(         136));
  simde_test_x86_assert_equal_i16x16(r, simde_x_mm256_loadu_epi16(test_vec[6].r));

  a = simde_x_mm256_loadu_epi8(test_vec[7].a);
  b = simde_x_mm256_loadu_epi8(test_vec[7].b);
  r = simde_mm256_maskz_dbsad_epu8(test_vec[7].k, a, b, INT32_C(         122));
  simde_test_x86_assert_equal_i16x16(r, simde_x_mm256_loadu_epi16(test_vec[7].r));

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__mmask16 k = simde_test_x86_random_mmask16();
    simde__m256i a = simde_test_x86_random_i8x32();
    simde__m256i b = simde_test_x86_random_i8x32();
    int imm8 = simde_test_codegen_random_i32() & 255;
    simde__m256i r;
    SIMDE_CONSTIFY_256_(simde_mm256_maskz_dbsad_epu8, r, simde_mm256_setzero_si256(), imm8, k, a, b);

    simde_test_x86_write_mmask16(2, k, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i8x32(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i8x32(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, imm8, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i16x16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm512_dbsad_epu8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int8_t a[64];
    const int8_t b[64];
    const int imm8;
    const int16_t r[32];
  } test_vec[] = {
    { { -INT8_C(  26), -INT8_C(  57), -INT8_C(  18),  INT8_C(  50),  INT8_C(  86), -INT8_C(  19), -INT8_C(  97), -INT8_C(  10),
         INT8_C(  75), -INT8_C( 104), -INT8_C(   5), -INT8_C( 114),  INT8_C( 123),  INT8_C( 106), -INT8_C(   1), -INT8_C(  49),
         INT8_C(  24),  INT8_C(  81),  INT8_C( 122), -INT8_C( 107), -INT8_C(  11),  INT8_C(  36),  INT8_C(  92), -INT8_C(   7),
         INT8_C(  31),  INT8_C( 111),  INT8_C( 115),  INT8_C(  94), -INT8_C(   4), -INT8_C( 100),  INT8_C( 121), -INT8_C(  30),
         INT8_C(  99),  INT8_C( 103),  INT8_C(  21), -INT8_C(  71),  INT8_C(  85), -INT8_C(  76), -INT8_C(  80), -INT8_C(  96),
         INT8_C(  77), -INT8_C(  85),  INT8_C(  46), -INT8_C(  56),  INT8_C(  21),  INT8_C(  45), -INT8_C( 105),  INT8_C(  45),
         INT8_C( 126),  INT8_C(  17), -INT8_C(  61),  INT8_C( 116),  INT8_C(  53),  INT8_C(  31),  INT8_C( 109),  INT8_C(  84),
        -INT8_C( 114), -INT8_C(  31), -INT8_C(  78), -INT8_C( 118),  INT8_C( 125),  INT8_C(  43),  INT8_C( 109), -INT8_C(  31) },
      { -INT8_C( 109), -INT8_C( 126), -INT8_C( 102), -INT8_C(  24),  INT8_C(  54),  INT8_C(  74), -INT8_C( 120), -INT8_C( 125),
        -INT8_C(  11), -INT8_C(  73),  INT8_C(  75),  INT8_C(  10), -INT8_C(  28), -INT8_C(  30),  INT8_C(  56),  INT8_C(  99),
        -INT8_C(  13), -INT8_C(   5), -INT8_C(  41),  INT8_C(  40),  INT8_C(  26),  INT8_C(  68),  INT8_C( 124), -INT8_C(  88),
         INT8_C(  37),  INT8_C(  46),  INT8_C(  50), -INT8_C(  93),  INT8_C(  90), -INT8_C(  97), -INT8_C( 124), -INT8_C(  19),
         INT8_C(  33),  INT8_C(  30), -INT8_C(  43),  INT8_C(  88),  INT8_C( 105),  INT8_C(  93), -INT8_C(  37),  INT8_C(  94),
         INT8_C(  20),  INT8_C(  39),  INT8_C( 105), -INT8_C(   7),  INT8_C(   9), -INT8_C(  95),  INT8_C(  92), -INT8_C(   3),
        -INT8_C( 100),  INT8_C(  51),  INT8_C(  37), -INT8_C(  74),  INT8_C( 119), -INT8_C(  94),  INT8_C(  94), -INT8_C(  99),
        -INT8_C(  48), -INT8_C( 112),  INT8_C(  64),  INT8_C(  42),  INT8_C(  48), -INT8_C(  60),  INT8_C(  23),  INT8_C(  81) },
       INT32_C(         226),
      {  INT16_C(   234),  INT16_C(   496),  INT16_C(   366),  INT16_C(   287),  INT16_C(   509),  INT16_C(   512),  INT16_C(   190),  INT16_C(   415),
         INT16_C(   134),  INT16_C(   188),  INT16_C(   475),  INT16_C(   482),  INT16_C(   205),  INT16_C(   128),  INT16_C(   307),  INT16_C(   287),
         INT16_C(   291),  INT16_C(   442),  INT16_C(   362),  INT16_C(   510),  INT16_C(   297),  INT16_C(   498),  INT16_C(   546),  INT16_C(   321),
         INT16_C(   414),  INT16_C(   258),  INT16_C(   102),  INT16_C(   241),  INT16_C(   357),  INT16_C(   389),  INT16_C(   152),  INT16_C(   377) } },
    { {  INT8_C(  74), -INT8_C( 123), -INT8_C(  86),  INT8_C(  94), -INT8_C(  84),  INT8_C(  19),  INT8_C(  87), -INT8_C(  75),
        -INT8_C(  76), -INT8_C(  77), -INT8_C(  78),  INT8_C(  80), -INT8_C(  26), -INT8_C(  40),  INT8_C(   6),  INT8_C(  94),
         INT8_C( 122),  INT8_C( 100), -INT8_C(   5),  INT8_C(  74), -INT8_C(  12),  INT8_C(  59),  INT8_C( 117),  INT8_C(  36),
        -INT8_C(   1), -INT8_C( 116),  INT8_C( 118), -INT8_C(  31),  INT8_C( 121),  INT8_C(  31),  INT8_C(  45), -INT8_C(  61),
        -INT8_C(  92), -INT8_C(  41),  INT8_C(  33),  INT8_C(  80), -INT8_C(  22),  INT8_C( 121),  INT8_C(   6), -INT8_C(  98),
         INT8_C(  44), -INT8_C(  72), -INT8_C(  18),  INT8_C(  19), -INT8_C( 112), -INT8_C(  12),  INT8_C( 113),  INT8_C(  10),
         INT8_C(  88),  INT8_C( 108),  INT8_C(  85),  INT8_C(  76), -INT8_C(  89), -INT8_C(  54),  INT8_C( 113), -INT8_C(  90),
         INT8_C(  86), -INT8_C(  25), -INT8_C( 121), -INT8_C(  49),  INT8_C(   6), -INT8_C(  76), -INT8_C( 110), -INT8_C(  85) },
      { -INT8_C( 117), -INT8_C(  76), -INT8_C(   5),  INT8_C( 117),  INT8_C(  45),  INT8_C(   1),  INT8_C(  19),  INT8_C(  89),
        -INT8_C(  70),  INT8_C(   1),  INT8_C( 108),  INT8_C(  74), -INT8_C(  11), -INT8_C(  35),  INT8_C(  85),  INT8_C(  77),
         INT8_C(  73), -INT8_C(  86), -INT8_C( 102), -INT8_C(  16),  INT8_C( 116),  INT8_C(  11), -INT8_C( 106), -INT8_C(  54),
        -INT8_C(  14),  INT8_C(  30), -INT8_C( 102), -INT8_C(   8), -INT8_C(  46),  INT8_C(  44), -INT8_C(  93),  INT8_C(  94),
        -INT8_C(  32), -INT8_C(  97), -INT8_C(  45),  INT8_C(  13), -INT8_C(  96), -INT8_C(  25),  INT8_C( 103),  INT8_C(  90),
        -INT8_C(  24), -INT8_C(  45), -INT8_C(  91), -INT8_C(  34), -INT8_C(  79), -INT8_C(   6),  INT8_C(  43), -INT8_C(   6),
        -INT8_C(  92), -INT8_C(  59), -INT8_C(  21),  INT8_C(  24), -INT8_C(  48), -INT8_C( 127), -INT8_C(  30), -INT8_C(  62),
        -INT8_C(  97),  INT8_C( 124), -INT8_C(  69),  INT8_C( 114), -INT8_C(  87),  INT8_C(  94), -INT8_C(  48), -INT8_C( 119) },
       INT32_C(         253),
      {  INT16_C(   317),  INT16_C(   419),  INT16_C(   421),  INT16_C(   539),  INT16_C(   203),  INT16_C(   401),  INT16_C(   650),  INT16_C(   406),
         INT16_C(   324),  INT16_C(   346),  INT16_C(   338),  INT16_C(   393),  INT16_C(   317),  INT16_C(   273),  INT16_C(   421),  INT16_C(   239),
         INT16_C(   100),  INT16_C(   333),  INT16_C(   425),  INT16_C(   559),  INT16_C(   625),  INT16_C(   517),  INT16_C(   411),  INT16_C(   343),
         INT16_C(   400),  INT16_C(   361),  INT16_C(   195),  INT16_C(   121),  INT16_C(   363),  INT16_C(    71),  INT16_C(   345),  INT16_C(   231) } },
    { { -INT8_C( 118), -INT8_C(   2), -INT8_C(   8),  INT8_C( 115), -INT8_C(  47), -INT8_C(  99),  INT8_C(  81), -INT8_C( 126),
        -INT8_C( 105),  INT8_C( 124),  INT8_C( 125),  INT8_C(  59),  INT8_C(  66),  INT8_C( 104),  INT8_C(  83),  INT8_C(  18),
        -INT8_C(  23),  INT8_C(  54), -INT8_C(  43), -INT8_C( 119), -INT8_C(  78), -INT8_C( 112), -INT8_C(   5),  INT8_C(  91),
        -INT8_C(  18), -INT8_C(  53), -INT8_C(  27), -INT8_C(  20),  INT8_C( 110),  INT8_C( 124), -INT8_C( 118), -INT8_C(   7),
         INT8_C( 122), -INT8_C( 126),  INT8_C( 108),  INT8_C(  75),  INT8_C(  32), -INT8_C(  67), -INT8_C(  50), -INT8_C(  73),
         INT8_C(  57),  INT8_C(  75), -INT8_C(  13),  INT8_C( 123), -INT8_C(  77),  INT8_C(  70), -INT8_C( 114), -INT8_C( 100),
         INT8_C( 124),  INT8_C(  99),  INT8_C(  37),  INT8_C(  47), -INT8_C(  13),  INT8_C(  32), -INT8_C( 118), -INT8_C(  31),
        -INT8_C(  21),  INT8_C( 111), -INT8_C(  51),  INT8_C(  90), -INT8_C(  21),  INT8_C(  87),  INT8_C(  83),  INT8_C( 101) },
      { -INT8_C(  38), -INT8_C(  65), -INT8_C(  79), -INT8_C(   6),  INT8_C( 124),      INT8_MAX, -INT8_C(  79), -INT8_C(  75),
        -INT8_C(  54), -INT8_C(  92),  INT8_C(  49),  INT8_C( 125), -INT8_C(  21), -INT8_C(  65),  INT8_C(  25),  INT8_C( 103),
         INT8_C(  34),  INT8_C(  63), -INT8_C( 106),  INT8_C(  21),  INT8_C(  95),  INT8_C(  33), -INT8_C(  10),  INT8_C(  75),
        -INT8_C( 112), -INT8_C(  60), -INT8_C(  91),  INT8_C( 124),  INT8_C(  27), -INT8_C(   8), -INT8_C(  31), -INT8_C(  11),
        -INT8_C(  73), -INT8_C( 110), -INT8_C(  17),  INT8_C(  51),  INT8_C(  17), -INT8_C(  95), -INT8_C(  24), -INT8_C(  37),
         INT8_C(  69),  INT8_C(  25),  INT8_C(  88),  INT8_C(  48), -INT8_C(  40),  INT8_C( 114), -INT8_C( 104), -INT8_C(   6),
        -INT8_C(  79),  INT8_C(  46),  INT8_C(  15),  INT8_C(  16),  INT8_C(  79),  INT8_C(   6),  INT8_C(  91), -INT8_C(  32),
        -INT8_C(  54),  INT8_C(   0),  INT8_C(  92), -INT8_C(  27), -INT8_C(   8),  INT8_C(  61), -INT8_C(  37), -INT8_C(  81) },
       INT32_C(         208),
      {  INT16_C(   349),  INT16_C(   235),  INT16_C(   323),  INT16_C(   259),  INT16_C(   204),  INT16_C(   309),  INT16_C(   513),  INT16_C(   361),
         INT16_C(   387),  INT16_C(   561),  INT16_C(   396),  INT16_C(   514),  INT16_C(   491),  INT16_C(   611),  INT16_C(   297),  INT16_C(   266),
         INT16_C(   232),  INT16_C(   298),  INT16_C(   405),  INT16_C(   141),  INT16_C(   233),  INT16_C(   378),  INT16_C(   318),  INT16_C(   218),
         INT16_C(   159),  INT16_C(   313),  INT16_C(   462),  INT16_C(   674),  INT16_C(   509),  INT16_C(   426),  INT16_C(   486),  INT16_C(   312) } },
    { {  INT8_C( 107), -INT8_C(  53), -INT8_C(  67), -INT8_C(  79), -INT8_C(  28),  INT8_C(  21), -INT8_C(  31), -INT8_C(  67),
        -INT8_C( 121),  INT8_C( 121), -INT8_C(  73),  INT8_C(  56), -INT8_C(  88), -INT8_C(  57),  INT8_C(  73), -INT8_C(   9),
        -INT8_C(  51), -INT8_C(  92), -INT8_C(  41), -INT8_C( 105), -INT8_C(  91),  INT8_C(  51),  INT8_C( 124), -INT8_C(  99),
         INT8_C( 113),  INT8_C(  87),  INT8_C(  77),  INT8_C(  65),  INT8_C(  34),  INT8_C(  47),  INT8_C(  34), -INT8_C( 115),
        -INT8_C(   6), -INT8_C(  33),  INT8_C(  62), -INT8_C(  33), -INT8_C(  11),  INT8_C(  32), -INT8_C( 100),  INT8_C( 124),
        -INT8_C( 103),  INT8_C(  83), -INT8_C(  75),  INT8_C(  65),  INT8_C(  26), -INT8_C(   2),  INT8_C(  57), -INT8_C(  25),
        -INT8_C(  94),  INT8_C(  16),  INT8_C( 126),  INT8_C(  71),  INT8_C(  68), -INT8_C(   5), -INT8_C(  27), -INT8_C(  75),
         INT8_C(  82),  INT8_C(  50), -INT8_C(  10),  INT8_C( 116),  INT8_C(  97),  INT8_C(  24),  INT8_C(   2),  INT8_C(  92) },
      { -INT8_C(   8),  INT8_C(  64),  INT8_C(  59), -INT8_C(  19),  INT8_C(  96), -INT8_C(  41),  INT8_C( 105), -INT8_C(   6),
         INT8_C(  42),  INT8_C(  30),  INT8_C(  59),  INT8_C(  69),  INT8_C(  28),  INT8_C( 116),  INT8_C(  44), -INT8_C(  65),
        -INT8_C( 123), -INT8_C(  85),  INT8_C(   6), -INT8_C(  55), -INT8_C(  90), -INT8_C(  21),  INT8_C( 126), -INT8_C(   8),
         INT8_C(  29),  INT8_C( 116),  INT8_C( 109),      INT8_MAX, -INT8_C( 116),  INT8_C( 111), -INT8_C(  37), -INT8_C( 124),
        -INT8_C(  81),  INT8_C(  22),  INT8_C( 113),  INT8_C(  16), -INT8_C(  19), -INT8_C(  37),  INT8_C(  10),  INT8_C(  23),
        -INT8_C(   7),  INT8_C(  69),  INT8_C(  92),  INT8_C(  22), -INT8_C(  70), -INT8_C( 119), -INT8_C(  43),  INT8_C(  63),
         INT8_C(  52), -INT8_C(  37),  INT8_C(   8), -INT8_C(  38), -INT8_C(  57), -INT8_C( 122), -INT8_C(  46), -INT8_C(  28),
        -INT8_C(   6),  INT8_C(  63),  INT8_C(  99), -INT8_C( 122), -INT8_C(  82),  INT8_C(  62),  INT8_C(  11),  INT8_C(  94) },
       INT32_C(          84),
      {  INT16_C(   470),  INT16_C(   316),  INT16_C(   540),  INT16_C(   178),  INT16_C(   405),  INT16_C(   203),  INT16_C(   169),  INT16_C(   469),
         INT16_C(   338),  INT16_C(   221),  INT16_C(   429),  INT16_C(   293),  INT16_C(   433),  INT16_C(   433),  INT16_C(   519),  INT16_C(   549),
         INT16_C(   534),  INT16_C(   398),  INT16_C(   324),  INT16_C(   611),  INT16_C(   433),  INT16_C(   469),  INT16_C(   439),  INT16_C(   403),
         INT16_C(   578),  INT16_C(   285),  INT16_C(   170),  INT16_C(   326),  INT16_C(   349),  INT16_C(   313),  INT16_C(   556),  INT16_C(   556) } },
    { {  INT8_C(  87),  INT8_C( 120),  INT8_C(  89),  INT8_C(  81), -INT8_C(  67), -INT8_C(  75),  INT8_C( 103),  INT8_C( 119),
         INT8_C(  62),  INT8_C(  60), -INT8_C(  74),  INT8_C( 114),  INT8_C(  23), -INT8_C(  66),  INT8_C(  76), -INT8_C(  34),
         INT8_C(  68),  INT8_C(  31), -INT8_C(  61),  INT8_C(  62),  INT8_C(  94),  INT8_C(  38), -INT8_C(  59),  INT8_C(  13),
         INT8_C( 101), -INT8_C(  48),  INT8_C( 107), -INT8_C(  71),  INT8_C(  76), -INT8_C(  39), -INT8_C(   5), -INT8_C(  92),
         INT8_C(  81),  INT8_C(  84), -INT8_C(  11),  INT8_C(  14),  INT8_C(   9),  INT8_C(  92), -INT8_C( 122),  INT8_C(  72),
        -INT8_C( 104),  INT8_C(  60), -INT8_C(  70), -INT8_C(  81), -INT8_C(   5),  INT8_C(   7), -INT8_C( 114),  INT8_C(  63),
         INT8_C(  38),  INT8_C(  81),  INT8_C( 126), -INT8_C( 124),  INT8_C( 119),  INT8_C(  67), -INT8_C( 111), -INT8_C(  36),
         INT8_C(  19), -INT8_C(   4), -INT8_C( 106),  INT8_C(  95), -INT8_C(  43), -INT8_C( 111),  INT8_C(   3),  INT8_C(  38) },
      { -INT8_C(  27), -INT8_C(   8),  INT8_C(  53), -INT8_C(  18),  INT8_C(  84), -INT8_C(  69),  INT8_C(  54), -INT8_C(  20),
        -INT8_C(   9), -INT8_C(  15), -INT8_C( 100), -INT8_C(  14), -INT8_C(   8),  INT8_C(  42),  INT8_C(  50),  INT8_C(  30),
         INT8_C( 123), -INT8_C(  80), -INT8_C(  94), -INT8_C(  14), -INT8_C(  13),  INT8_C(  52), -INT8_C(  49),  INT8_C(   6),
         INT8_C(  48),  INT8_C( 101),  INT8_C( 101),  INT8_C(   6), -INT8_C(  10),  INT8_C( 105),  INT8_C(  44), -INT8_C(  37),
         INT8_C(  97),  INT8_C(  97), -INT8_C(  55), -INT8_C(  74),  INT8_C(  28),  INT8_C(   0), -INT8_C(  94),  INT8_C(  20),
        -INT8_C(  15),  INT8_C(  62),  INT8_C(   6), -INT8_C(  23),  INT8_C( 104),  INT8_C(  56),  INT8_C(   7), -INT8_C(  29),
        -INT8_C(  24), -INT8_C(  87), -INT8_C(  42), -INT8_C(  37), -INT8_C(  35), -INT8_C(  91), -INT8_C(  31),  INT8_C(  14),
         INT8_C(  10),  INT8_C(  71),  INT8_C(  20),  INT8_C(   0), -INT8_C(  80),  INT8_C(  64), -INT8_C(  37),  INT8_C(  17) },
       INT32_C(         162),
      {  INT16_C(   509),  INT16_C(   491),  INT16_C(   349),  INT16_C(   312),  INT16_C(   520),  INT16_C(   468),  INT16_C(   375),  INT16_C(   507),
         INT16_C(   240),  INT16_C(   353),  INT16_C(   276),  INT16_C(   343),  INT16_C(   345),  INT16_C(   345),  INT16_C(   502),  INT16_C(   452),
         INT16_C(   640),  INT16_C(   192),  INT16_C(   206),  INT16_C(   395),  INT16_C(   329),  INT16_C(   257),  INT16_C(   571),  INT16_C(   389),
         INT16_C(   276),  INT16_C(   320),  INT16_C(   304),  INT16_C(   314),  INT16_C(   415),  INT16_C(   519),  INT16_C(   378),  INT16_C(   434) } },
    { { -INT8_C(  92),  INT8_C( 106), -INT8_C(  46), -INT8_C( 107), -INT8_C(  88), -INT8_C(  39),  INT8_C( 126),  INT8_C(  17),
         INT8_C(  17), -INT8_C( 123), -INT8_C(  12), -INT8_C(   6),  INT8_C(  47), -INT8_C(  54), -INT8_C(  43),  INT8_C(  12),
         INT8_C( 111), -INT8_C(  73),  INT8_C(  26),  INT8_C( 121), -INT8_C(   2),  INT8_C(  46),  INT8_C( 121), -INT8_C(  82),
         INT8_C( 111),  INT8_C(  84), -INT8_C(  65),  INT8_C(  17), -INT8_C(   7), -INT8_C( 121), -INT8_C(  49), -INT8_C(  99),
        -INT8_C(  15), -INT8_C(  94),  INT8_C(  51), -INT8_C( 103),  INT8_C( 123), -INT8_C(  79), -INT8_C(  86), -INT8_C( 116),
         INT8_C(  55), -INT8_C(  97), -INT8_C( 122),  INT8_C( 102),  INT8_C( 105),  INT8_C(  92),  INT8_C( 114), -INT8_C(  39),
         INT8_C(  19), -INT8_C( 115),  INT8_C(  82),  INT8_C(  17), -INT8_C(  69), -INT8_C(  52), -INT8_C(  65),  INT8_C(  42),
         INT8_C(  32),  INT8_C( 126),  INT8_C(  59),  INT8_C(  25),  INT8_C(   5),  INT8_C(  11), -INT8_C(  73), -INT8_C(  10) },
      { -INT8_C(  83), -INT8_C(  22), -INT8_C( 112),  INT8_C(  40), -INT8_C( 101),  INT8_C(  58), -INT8_C(  76), -INT8_C(  46),
        -INT8_C(  39),  INT8_C(  59),  INT8_C(  56),  INT8_C(  67), -INT8_C( 105), -INT8_C(  85),  INT8_C(  28), -INT8_C(  86),
         INT8_C(  56),  INT8_C( 110), -INT8_C(  69), -INT8_C(  13),  INT8_C(  58),  INT8_C( 122),  INT8_C(  30),  INT8_C(  91),
        -INT8_C(   8),  INT8_C(  89),  INT8_C( 116), -INT8_C(   2),  INT8_C( 100),  INT8_C(  43), -INT8_C(  12),  INT8_C(  17),
         INT8_C(  21), -INT8_C( 124),  INT8_C(  57), -INT8_C(  79), -INT8_C(  65), -INT8_C(  18), -INT8_C( 125), -INT8_C( 104),
         INT8_C(  41), -INT8_C(  68), -INT8_C(  37), -INT8_C(  64),  INT8_C( 103), -INT8_C(   9),  INT8_C( 106), -INT8_C(  97),
         INT8_C( 102),  INT8_C(  37), -INT8_C( 110), -INT8_C(  96), -INT8_C(  97), -INT8_C(  80), -INT8_C(   5), -INT8_C( 105),
         INT8_C(  10),  INT8_C( 112), -INT8_C( 107),  INT8_C( 110), -INT8_C( 101), -INT8_C( 118),      INT8_MIN, -INT8_C(  79) },
       INT32_C(          14),
      {  INT16_C(   336),  INT16_C(   300),  INT16_C(   441),  INT16_C(   223),  INT16_C(   567),  INT16_C(   509),  INT16_C(   521),  INT16_C(   189),
         INT16_C(   454),  INT16_C(   338),  INT16_C(   498),  INT16_C(   202),  INT16_C(   311),  INT16_C(   195),  INT16_C(   368),  INT16_C(   212),
         INT16_C(   433),  INT16_C(   301),  INT16_C(   285),  INT16_C(   254),  INT16_C(   213),  INT16_C(   303),  INT16_C(   311),  INT16_C(   321),
         INT16_C(   198),  INT16_C(   267),  INT16_C(   264),  INT16_C(   265),  INT16_C(   381),  INT16_C(   203),  INT16_C(   580),  INT16_C(   492) } },
    { { -INT8_C(  89), -INT8_C(  27),  INT8_C( 102), -INT8_C(  48), -INT8_C(  95),  INT8_C(  65), -INT8_C( 112),  INT8_C(   8),
         INT8_C(  57), -INT8_C(   6), -INT8_C(  89), -INT8_C(  97),  INT8_C(  31),  INT8_C(  58),  INT8_C(  63), -INT8_C(  66),
        -INT8_C(  22),  INT8_C(  59),  INT8_C(  86), -INT8_C(  12), -INT8_C(  85), -INT8_C(  21),  INT8_C(  99),  INT8_C(  70),
         INT8_C( 117), -INT8_C(  29), -INT8_C(   9), -INT8_C( 124), -INT8_C( 100),  INT8_C(  89),  INT8_C(  81),  INT8_C(  68),
         INT8_C(  63), -INT8_C(  73),  INT8_C(  20), -INT8_C(  32), -INT8_C(   7), -INT8_C(  91), -INT8_C(  23),  INT8_C(  50),
        -INT8_C(  97), -INT8_C( 112), -INT8_C(  47), -INT8_C(  65), -INT8_C(  54),  INT8_C(  16),  INT8_C( 125), -INT8_C(  75),
         INT8_C(  75), -INT8_C(  45), -INT8_C(  87), -INT8_C(  10), -INT8_C(  65),  INT8_C(  12),  INT8_C(  61),  INT8_C(  52),
        -INT8_C(  17),  INT8_C(  52), -INT8_C(  72), -INT8_C( 116), -INT8_C( 114),  INT8_C(  10), -INT8_C(  48), -INT8_C(  51) },
      { -INT8_C(  63), -INT8_C(  28), -INT8_C(  83), -INT8_C(  70), -INT8_C( 119), -INT8_C( 106), -INT8_C(  20),  INT8_C(  41),
         INT8_C(  39), -INT8_C(  67), -INT8_C(  24), -INT8_C(  15), -INT8_C(  50),  INT8_C( 101), -INT8_C(  90),  INT8_C(  25),
         INT8_C(  57),  INT8_C(  80),  INT8_C(  16), -INT8_C(   8),  INT8_C(  92),  INT8_C(  77),  INT8_C(  44),  INT8_C(  76),
        -INT8_C( 127), -INT8_C(  27), -INT8_C(  40),  INT8_C(  15), -INT8_C(  17), -INT8_C(  88), -INT8_C(  36), -INT8_C(  80),
        -INT8_C( 116), -INT8_C( 118),  INT8_C( 107),  INT8_C(  22),  INT8_C(  32),  INT8_C(  87),  INT8_C(  63),  INT8_C(  71),
         INT8_C(  21),  INT8_C(  39),  INT8_C(  57), -INT8_C(  29), -INT8_C( 116), -INT8_C(  33), -INT8_C(   4), -INT8_C(  59),
         INT8_C(  47),  INT8_C(  12), -INT8_C(  67), -INT8_C( 116),  INT8_C(  89), -INT8_C(  22), -INT8_C(  40), -INT8_C(  37),
        -INT8_C(  49), -INT8_C(  80), -INT8_C(  22), -INT8_C(  66),  INT8_C(  88), -INT8_C(  57),  INT8_C( 110), -INT8_C(  28) },
       INT32_C(          81),
      {  INT16_C(   410),  INT16_C(   100),  INT16_C(   368),  INT16_C(   497),  INT16_C(   367),  INT16_C(   255),  INT16_C(   336),  INT16_C(   222),
         INT16_C(   370),  INT16_C(   369),  INT16_C(   338),  INT16_C(   346),  INT16_C(   434),  INT16_C(   434),  INT16_C(   145),  INT16_C(   111),
         INT16_C(   323),  INT16_C(   279),  INT16_C(   461),  INT16_C(   355),  INT16_C(   450),  INT16_C(   450),  INT16_C(   381),  INT16_C(   303),
         INT16_C(   111),  INT16_C(   413),  INT16_C(   286),  INT16_C(   249),  INT16_C(   443),  INT16_C(   255),  INT16_C(   431),  INT16_C(   193) } },
    { {  INT8_C(  49),  INT8_C(  57), -INT8_C(  71),  INT8_C(  70),  INT8_C(  96), -INT8_C(  14),  INT8_C(  41), -INT8_C(  19),
        -INT8_C(  47),  INT8_C(  37), -INT8_C(  78),  INT8_C(   1),  INT8_C(  50),  INT8_C( 112), -INT8_C( 115), -INT8_C( 117),
         INT8_C(  90),  INT8_C( 101),  INT8_C( 102),  INT8_C(  41),  INT8_C(  21),  INT8_C(  81), -INT8_C(  25),  INT8_C( 109),
         INT8_C(  24),  INT8_C(  85),  INT8_C(  81),  INT8_C( 105),  INT8_C(  47),  INT8_C(  76), -INT8_C(  38),  INT8_C(  96),
        -INT8_C( 123), -INT8_C( 109), -INT8_C(  90), -INT8_C(  26), -INT8_C( 123), -INT8_C(  49), -INT8_C(  45),  INT8_C(  87),
        -INT8_C(  12), -INT8_C( 123),  INT8_C(  88),  INT8_C(  38), -INT8_C(  11), -INT8_C(  27), -INT8_C(  78),  INT8_C(  79),
         INT8_C(  74),  INT8_C(  24),  INT8_C( 120),  INT8_C(  95),  INT8_C( 105),  INT8_C(  95), -INT8_C(  52), -INT8_C( 127),
        -INT8_C(  75),  INT8_C(  29), -INT8_C(  22), -INT8_C(  28),  INT8_C( 105), -INT8_C(  59),  INT8_C(  68), -INT8_C(  17) },
      {  INT8_C(  88), -INT8_C(  22), -INT8_C(  43), -INT8_C(  34), -INT8_C(  71), -INT8_C(  88),  INT8_C(  53), -INT8_C(  83),
         INT8_C(  45), -INT8_C( 115), -INT8_C(  44),  INT8_C(  35),  INT8_C( 114), -INT8_C( 122),  INT8_C( 114), -INT8_C(  68),
        -INT8_C(  98), -INT8_C(  21),  INT8_C(  27),  INT8_C(   8),  INT8_C(  74), -INT8_C(  25), -INT8_C( 119), -INT8_C(   1),
         INT8_C(   4),  INT8_C( 116), -INT8_C(  29),  INT8_C( 110),  INT8_C(  57),  INT8_C(  39),  INT8_C(  93), -INT8_C( 111),
         INT8_C(  17),  INT8_C(  50),  INT8_C( 111), -INT8_C(  54), -INT8_C(  38), -INT8_C(  92),  INT8_C( 120),  INT8_C(   7),
         INT8_C(  49),  INT8_C(  76),  INT8_C(  42), -INT8_C(  93), -INT8_C(  46), -INT8_C(  99),  INT8_C(  95),  INT8_C( 112),
        -INT8_C( 120),  INT8_C( 122),  INT8_C( 120), -INT8_C(  46),  INT8_C(  97),  INT8_C(   2), -INT8_C(  46),  INT8_C( 102),
         INT8_C( 118), -INT8_C(  75), -INT8_C(  44), -INT8_C(  81), -INT8_C(  35),  INT8_C(  49),  INT8_C(  64), -INT8_C(  18) },
       INT32_C(          99),
      {  INT16_C(   331),  INT16_C(   163),  INT16_C(   122),  INT16_C(   463),  INT16_C(   336),  INT16_C(   570),  INT16_C(   312),  INT16_C(   201),
         INT16_C(   208),  INT16_C(   219),  INT16_C(   335),  INT16_C(   287),  INT16_C(   202),  INT16_C(   294),  INT16_C(   493),  INT16_C(   119),
         INT16_C(   276),  INT16_C(   343),  INT16_C(   364),  INT16_C(   396),  INT16_C(   423),  INT16_C(   514),  INT16_C(   394),  INT16_C(   148),
         INT16_C(   371),  INT16_C(   224),  INT16_C(   259),  INT16_C(   265),  INT16_C(   290),  INT16_C(   373),  INT16_C(   395),  INT16_C(   265) } },
  };

  simde__m512i a, b, r;

  a = simde_mm512_loadu_epi8(test_vec[0].a);
  b = simde_mm512_loadu_epi8(test_vec[0].b);
  r = simde_mm512_dbsad_epu8(a, b, INT32_C(         226));
  simde_test_x86_assert_equal_i16x32(r, simde_mm512_loadu_epi16(test_vec[0].r));

  a = simde_mm512_loadu_epi8(test_vec[1].a);
  b = simde_mm512_loadu_epi8(test_vec[1].b);
  r = simde_mm512_dbsad_epu8(a, b, INT32_C(         253));
  simde_test_x86_assert_equal_i16x32(r, simde_mm512_loadu_epi16(test_vec[1].r));

  a = simde_mm512_loadu_epi8(test_vec[2].a);
  b = simde_mm512_loadu_epi8(test_vec[2].b);
  r = simde_mm512_dbsad_epu8(a, b, INT32_C(         208));
  simde_test_x86_assert_equal_i16x32(r, simde_mm512_loadu_epi16(test_vec[2].r));

  a = simde_mm512_loadu_epi8(test_vec[3].a);
  b = simde_mm512_loadu_epi8(test_vec[3].b);
  r = simde_mm512_dbsad_epu8(a, b, INT32_C(          84));
  simde_test_x86_assert_equal_i16x32(r, simde_mm512_loadu_epi16(test_vec[3].r));

  a = simde_mm512_loadu_epi8(test_vec[4].a);
  b = simde_mm512_loadu_epi8(test_vec[4].b);
  r = simde_mm512_dbsad_epu8(a, b, INT32_C(         162));
  simde_test_x86_assert_equal_i16x32(r, simde_mm512_loadu_epi16(test_vec[4].r));

  a = simde_mm512_loadu_epi8(test_vec[5].a);
  b = simde_mm512_loadu_epi8(test_vec[5].b);
  r = simde_mm512_dbsad_epu8(a, b, INT32_C(          14));
  simde_test_x86_assert_equal_i16x32(r, simde_mm512_loadu_epi16(test_vec[5].r));

  a = simde_mm512_loadu_epi8(test_vec[6].a);
  b = simde_mm512_loadu_epi8(test_vec[6].b);
  r = simde_mm512_dbsad_epu8(a, b, INT32_C(          81));
  simde_test_x86_assert_equal_i16x32(r, simde_mm512_loadu_epi16(test_vec[6].r));

  a = simde_mm512_loadu_epi8(test_vec[7].a);
  b = simde_mm512_loadu_epi8(test_vec[7].b);
  r = simde_mm512_dbsad_epu8(a, b, INT32_C(          99));
  simde_test_x86_assert_equal_i16x32(r, simde_mm512_loadu_epi16(test_vec[7].r));

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m512i a = simde_test_x86_random_i8x64();
    simde__m512i b = simde_test_x86_random_i8x64();
    int imm8 = simde_test_codegen_random_i32() & 255;
    simde__m512i r;
    SIMDE_CONSTIFY_256_(simde_mm512_dbsad_epu8, r, simde_mm512_setzero_si512(), imm8, a, b);

    simde_test_x86_write_i8x64(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i8x64(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, imm8, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i16x32(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm512_mask_dbsad_epu8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int16_t src[32];
    const simde__mmask32 k;
    const int8_t a[64];
    const int8_t b[64];
    const int imm8;
    const int16_t r[32];
  } test_vec[] = {
    { {  INT16_C( 12628), -INT16_C( 31164),  INT16_C( 28541),  INT16_C( 20265), -INT16_C( 30452), -INT16_C( 27457),  INT16_C( 14339),  INT16_C( 25958),
         INT16_C( 14394), -INT16_C( 20277), -INT16_C( 24594), -INT16_C( 13473), -INT16_C( 24624),  INT16_C( 13241),  INT16_C( 29263), -INT16_C( 23440),
        -INT16_C( 19293),  INT16_C(  8234),  INT16_C( 21283),  INT16_C( 12143),  INT16_C( 12252), -INT16_C(  7997),  INT16_C( 10855), -INT16_C( 24251),
         INT16_C(  4194),  INT16_C( 20561), -INT16_C( 20305),  INT16_C( 32539), -INT16_C( 10929), -INT16_C( 24654),  INT16_C(  8775), -INT16_C(  5309) },
      UINT32_C(4195053014),
      { -INT8_C(  64),  INT8_C( 123),  INT8_C(  41), -INT8_C(  99), -INT8_C(  86), -INT8_C(  19),  INT8_C( 125),  INT8_C(  17),
         INT8_C(  23), -INT8_C(  62), -INT8_C(  78),  INT8_C( 121), -INT8_C(  46),  INT8_C(   3), -INT8_C(  54), -INT8_C( 127),
        -INT8_C(  77), -INT8_C(  27),  INT8_C(   0),  INT8_C(   2), -INT8_C(  70), -INT8_C(  78), -INT8_C(  95),  INT8_C(   2),
        -INT8_C(  44), -INT8_C(  28), -INT8_C(  19), -INT8_C(  86),  INT8_C(  81), -INT8_C(   8), -INT8_C(  92),  INT8_C(  18),
         INT8_C( 115), -INT8_C(  50), -INT8_C(  81),  INT8_C(  29), -INT8_C(  69),  INT8_C(  44),  INT8_C(  46), -INT8_C(  46),
        -INT8_C(  18), -INT8_C(  32),  INT8_C(  75), -INT8_C(  64), -INT8_C(  29),  INT8_C(  21),  INT8_C(  65), -INT8_C( 106),
        -INT8_C(   5),  INT8_C(  65), -INT8_C( 103), -INT8_C(  75), -INT8_C(  13),  INT8_C(  58), -INT8_C(  73), -INT8_C(  57),
         INT8_C(  31), -INT8_C(  92),  INT8_C( 113),  INT8_C( 112), -INT8_C(  99),  INT8_C(  22), -INT8_C( 126),  INT8_C(  16) },
      { -INT8_C(  28),  INT8_C(  49),  INT8_C(  46), -INT8_C(  97),  INT8_C(  93),  INT8_C(  92),  INT8_C( 113),  INT8_C(  75),
         INT8_C(  61), -INT8_C(  68),  INT8_C(  11),  INT8_C(  32), -INT8_C(  46),  INT8_C(  76), -INT8_C(  73), -INT8_C(  51),
        -INT8_C( 115),  INT8_C(  80), -INT8_C( 126),      INT8_MIN, -INT8_C( 118),  INT8_C(  58),  INT8_C(  71), -INT8_C(  87),
        -INT8_C(  34), -INT8_C(  71),  INT8_C(  26),  INT8_C( 123), -INT8_C(  49), -INT8_C( 100), -INT8_C( 116), -INT8_C(  77),
        -INT8_C(  50), -INT8_C(  70),  INT8_C(  82),  INT8_C(  43),  INT8_C(  22), -INT8_C(  61),  INT8_C( 119),  INT8_C(  83),
             INT8_MAX, -INT8_C( 126),  INT8_C( 116),  INT8_C(  81), -INT8_C(  49),  INT8_C(  43),  INT8_C(  30),  INT8_C(  92),
         INT8_C( 123), -INT8_C(  95), -INT8_C(  35),  INT8_C(   5), -INT8_C(  37),  INT8_C(  36), -INT8_C(  81), -INT8_C(  71),
        -INT8_C(  35), -INT8_C(  55),  INT8_C(  53), -INT8_C(  84),  INT8_C( 101), -INT8_C(  63),  INT8_C(  95),  INT8_C(  51) },
       INT32_C(         123),
      {  INT16_C( 12628),  INT16_C(   436),  INT16_C(   280),  INT16_C( 20265),  INT16_C(   394), -INT16_C( 27457),  INT16_C(   375),  INT16_C(   221),
         INT16_C(   418), -INT16_C( 20277),  INT16_C(   291),  INT16_C(    99), -INT16_C( 24624),  INT16_C(   234),  INT16_C(   194), -INT16_C( 23440),
         INT16_C(   463),  INT16_C(   429),  INT16_C( 21283),  INT16_C(   356),  INT16_C( 12252), -INT16_C(  7997),  INT16_C( 10855), -INT16_C( 24251),
         INT16_C(  4194),  INT16_C(   230), -INT16_C( 20305),  INT16_C(   519),  INT16_C(   178),  INT16_C(   400),  INT16_C(   200),  INT16_C(   556) } },
    { { -INT16_C( 10636), -INT16_C(  2843),  INT16_C( 22872),  INT16_C( 10053),  INT16_C( 25732), -INT16_C(   124),  INT16_C( 24837), -INT16_C(  8188),
        -INT16_C( 19579),  INT16_C( 25497), -INT16_C( 12676), -INT16_C(  7665),  INT16_C( 28559),  INT16_C(  2581),  INT16_C( 29728), -INT16_C( 27236),
        -INT16_C( 32438), -INT16_C( 23671), -INT16_C( 12582),  INT16_C( 24266),  INT16_C( 20018),  INT16_C( 14173),  INT16_C( 25007),  INT16_C( 13591),
        -INT16_C( 20203), -INT16_C( 28264), -INT16_C( 22657),  INT16_C(  3955), -INT16_C( 30442),  INT16_C( 14105), -INT16_C( 18947),  INT16_C( 18636) },
      UINT32_C( 283858230),
      {  INT8_C(  35), -INT8_C(  75),  INT8_C( 110),  INT8_C(  86),  INT8_C(   4), -INT8_C(  53), -INT8_C( 115), -INT8_C(  77),
         INT8_C(  45), -INT8_C(  91), -INT8_C(  24),  INT8_C(  66),  INT8_C(  86),      INT8_MIN, -INT8_C(  45), -INT8_C(  43),
         INT8_C(  40),  INT8_C(  71), -INT8_C(  28),  INT8_C(  62), -INT8_C(  48), -INT8_C(   2),  INT8_C( 117), -INT8_C(  51),
        -INT8_C(  77),  INT8_C(  65),  INT8_C(  21), -INT8_C(  22), -INT8_C( 106),  INT8_C(   0), -INT8_C(   6), -INT8_C(  70),
        -INT8_C(  74),  INT8_C( 105),  INT8_C(  16), -INT8_C(  70),  INT8_C(  52), -INT8_C(  99),  INT8_C( 109),  INT8_C(  97),
         INT8_C(  66),  INT8_C(  86), -INT8_C(  93), -INT8_C( 104), -INT8_C(  42),  INT8_C( 119),  INT8_C( 110), -INT8_C(   2),
        -INT8_C(  66),  INT8_C(  82),  INT8_C(  61), -INT8_C( 114),  INT8_C(  80), -INT8_C(  78),  INT8_C(  91),  INT8_C(   4),
        -INT8_C(  12),  INT8_C( 113), -INT8_C(  18), -INT8_C( 118),  INT8_C( 113), -INT8_C(  24),  INT8_C(  68),  INT8_C(  39) },
      {  INT8_C(  81),  INT8_C(  84), -INT8_C(  31), -INT8_C( 122), -INT8_C(  14),  INT8_C(  79), -INT8_C(  25),  INT8_C(  52),
        -INT8_C(  91), -INT8_C( 117), -INT8_C(  51),  INT8_C( 123),  INT8_C(   2),  INT8_C(  59),  INT8_C( 122), -INT8_C(  64),
        -INT8_C( 115), -INT8_C(  73),  INT8_C(  78), -INT8_C(  34),  INT8_C( 105), -INT8_C(  87), -INT8_C(  30),  INT8_C(  93),
         INT8_C(  26), -INT8_C(  48), -INT8_C(  24), -INT8_C( 116), -INT8_C(  72),  INT8_C(  44), -INT8_C(  77),  INT8_C(  10),
        -INT8_C( 127), -INT8_C( 107), -INT8_C( 112),  INT8_C( 115), -INT8_C(  28),  INT8_C( 119), -INT8_C(  89), -INT8_C( 119),
         INT8_C(   2),  INT8_C( 116),  INT8_C(   4),  INT8_C(   4), -INT8_C(  81),  INT8_C( 126), -INT8_C(  60),  INT8_C(  61),
         INT8_C(  53),  INT8_C(  18),  INT8_C(  27), -INT8_C(  97), -INT8_C(  68), -INT8_C(   3), -INT8_C(   4), -INT8_C(  42),
        -INT8_C(  51), -INT8_C(  28),  INT8_C(  98), -INT8_C( 123),  INT8_C(  17),  INT8_C(  22), -INT8_C( 113), -INT8_C( 110) },
       INT32_C(         171),
      { -INT16_C( 10636),  INT16_C(   244),  INT16_C(   193),  INT16_C( 10053),  INT16_C(   230),  INT16_C(   342),  INT16_C( 24837), -INT16_C(  8188),
         INT16_C(   272),  INT16_C( 25497),  INT16_C(   367), -INT16_C(  7665),  INT16_C(   601),  INT16_C(  2581),  INT16_C(   468), -INT16_C( 27236),
         INT16_C(   333),  INT16_C(   376), -INT16_C( 12582),  INT16_C(   264),  INT16_C( 20018),  INT16_C(   441),  INT16_C(   571),  INT16_C(   583),
        -INT16_C( 20203), -INT16_C( 28264), -INT16_C( 22657),  INT16_C(  3955),  INT16_C(   299),  INT16_C( 14105), -INT16_C( 18947),  INT16_C( 18636) } },
    { { -INT16_C( 21353), -INT16_C( 26344),  INT16_C(  7201), -INT16_C( 12130),  INT16_C( 25243), -INT16_C( 12275),  INT16_C( 10357),  INT16_C( 12655),
         INT16_C( 27685), -INT16_C(  3577),  INT16_C( 27216),  INT16_C( 24952),  INT16_C(  1920),  INT16_C( 11251), -INT16_C(  2009), -INT16_C( 16710),
        -INT16_C( 11611), -INT16_C( 14761), -INT16_C(  2578), -INT16_C( 30314), -INT16_C( 23464), -INT16_C( 12966), -INT16_C( 13876), -INT16_C(  3330),
         INT16_C(  1333), -INT16_C( 31004),  INT16_C( 23663), -INT16_C(  4121), -INT16_C(  9372), -INT16_C( 29926), -INT16_C( 11053),  INT16_C( 30793) },
      UINT32_C(2503909542),
      { -INT8_C( 106), -INT8_C(  43),  INT8_C(  30), -INT8_C(  18),  INT8_C( 121),  INT8_C( 120), -INT8_C(  69),  INT8_C(  69),
         INT8_C(  66), -INT8_C(  71),  INT8_C(  55),  INT8_C( 119), -INT8_C(  66),  INT8_C(  28), -INT8_C(   3),  INT8_C(  46),
         INT8_C( 120), -INT8_C(  27),  INT8_C(  29), -INT8_C(  36), -INT8_C(  64),  INT8_C(  56),  INT8_C( 103), -INT8_C( 109),
         INT8_C(  12), -INT8_C(  80),  INT8_C(  12), -INT8_C(  77),  INT8_C(  81),  INT8_C(  74),  INT8_C(  72), -INT8_C(  25),
         INT8_C(  31),  INT8_C( 102), -INT8_C(  43), -INT8_C( 104), -INT8_C(  33), -INT8_C( 112), -INT8_C(  34),  INT8_C(  33),
         INT8_C(  73),  INT8_C(  21), -INT8_C( 104),  INT8_C(   7),  INT8_C(  49), -INT8_C( 106),  INT8_C(  53), -INT8_C(  86),
         INT8_C( 123),  INT8_C(  83), -INT8_C( 122),  INT8_C(  59), -INT8_C( 117), -INT8_C(  18), -INT8_C(  50), -INT8_C( 105),
        -INT8_C(  98), -INT8_C(  38),  INT8_C(  74), -INT8_C(  17),  INT8_C(  37), -INT8_C( 110), -INT8_C(  42),  INT8_C(  68) },
      { -INT8_C(   7), -INT8_C(  85), -INT8_C(  35), -INT8_C(  40),  INT8_C(  59), -INT8_C(  69), -INT8_C(   7), -INT8_C( 124),
        -INT8_C(  48), -INT8_C( 111), -INT8_C( 116),  INT8_C(   2),  INT8_C(  39), -INT8_C(  63), -INT8_C(  84), -INT8_C(  94),
         INT8_C(  20),  INT8_C(  50), -INT8_C(  35), -INT8_C(  97),  INT8_C(  32), -INT8_C(  84),  INT8_C(  55), -INT8_C(  65),
        -INT8_C( 122), -INT8_C( 127), -INT8_C(  82), -INT8_C(  85),  INT8_C(  20), -INT8_C( 123), -INT8_C(  16),  INT8_C(  13),
         INT8_C(  48), -INT8_C(  51), -INT8_C(  27),  INT8_C( 108), -INT8_C( 120), -INT8_C(  34), -INT8_C(  16),  INT8_C(  88),
         INT8_C( 111),  INT8_C( 124),  INT8_C(  90), -INT8_C( 105),  INT8_C(  62),  INT8_C(   6),  INT8_C(  57),  INT8_C(  82),
         INT8_C(  57),  INT8_C(  23), -INT8_C(  14),  INT8_C(  89), -INT8_C(  61),  INT8_C(  41),  INT8_C(  24),  INT8_C(  73),
        -INT8_C(  86), -INT8_C(  57), -INT8_C(  11), -INT8_C(  66),  INT8_C(  76), -INT8_C(  27), -INT8_C(  53),  INT8_C( 124) },
       INT32_C(         178),
      { -INT16_C( 21353),  INT16_C(   117),  INT16_C(   301), -INT16_C( 12130),  INT16_C( 25243),  INT16_C(   336),  INT16_C( 10357),  INT16_C(   410),
         INT16_C( 27685), -INT16_C(  3577),  INT16_C( 27216),  INT16_C( 24952),  INT16_C(  1920),  INT16_C(   231), -INT16_C(  2009),  INT16_C(   242),
        -INT16_C( 11611),  INT16_C(   271),  INT16_C(   486),  INT16_C(   381),  INT16_C(   196),  INT16_C(   277), -INT16_C( 13876), -INT16_C(  3330),
         INT16_C(   405), -INT16_C( 31004),  INT16_C(   431), -INT16_C(  4121),  INT16_C(   337), -INT16_C( 29926), -INT16_C( 11053),  INT16_C(   303) } },
    { { -INT16_C(  9842), -INT16_C(   366), -INT16_C(  4779), -INT16_C( 27755), -INT16_C( 12557),  INT16_C( 11494), -INT16_C( 10011), -INT16_C( 22394),
        -INT16_C( 25087), -INT16_C( 21518), -INT16_C(  6299), -INT16_C( 20118),  INT16_C( 13772),  INT16_C( 32302),  INT16_C(  5862),  INT16_C( 29880),
         INT16_C( 19183),  INT16_C( 17778),  INT16_C(  1847),  INT16_C( 11224), -INT16_C( 16682), -INT16_C( 17577), -INT16_C(  8810), -INT16_C( 26780),
         INT16_C( 22140), -INT16_C(  7869), -INT16_C( 21187),  INT16_C(  2451), -INT16_C( 15902), -INT16_C( 14201),  INT16_C( 16343), -INT16_C( 14531) },
      UINT32_C(3238834057),
      { -INT8_C(  73), -INT8_C(  28), -INT8_C(  20), -INT8_C( 115), -INT8_C(  93),  INT8_C(  67),  INT8_C(  72),  INT8_C(  57),
         INT8_C(  33), -INT8_C(  84), -INT8_C(  47), -INT8_C(  99),  INT8_C(   2),  INT8_C(  20),  INT8_C( 126),  INT8_C(  63),
        -INT8_C(  63),  INT8_C(  17),  INT8_C(  72), -INT8_C(  93), -INT8_C(  46), -INT8_C(  49),  INT8_C( 108), -INT8_C(  86),
         INT8_C(  14), -INT8_C(  87),  INT8_C( 113), -INT8_C( 104),  INT8_C(  88),  INT8_C( 125),  INT8_C(  89),  INT8_C(  15),
         INT8_C(  97),  INT8_C(  69), -INT8_C( 100),  INT8_C(   4), -INT8_C( 120), -INT8_C(  27),  INT8_C(  62), -INT8_C(  87),
        -INT8_C( 111),  INT8_C(  15),  INT8_C(  70), -INT8_C( 108),  INT8_C(  35), -INT8_C(  59), -INT8_C(  45), -INT8_C(  28),
        -INT8_C(  42),  INT8_C(  28), -INT8_C( 121), -INT8_C(  87), -INT8_C(  21), -INT8_C(  13),  INT8_C(  83), -INT8_C(   6),
        -INT8_C( 100), -INT8_C(  60), -INT8_C( 110), -INT8_C(  11),  INT8_C(  65), -INT8_C(  21),  INT8_C(   4), -INT8_C(  94) },
      {  INT8_C(  48), -INT8_C(  95), -INT8_C(  89), -INT8_C(  72), -INT8_C( 122), -INT8_C(  27),  INT8_C(  98),  INT8_C(  23),
        -INT8_C(  12), -INT8_C(  88), -INT8_C(  85),  INT8_C(  23),  INT8_C( 109),      INT8_MAX, -INT8_C(   5),  INT8_C(  68),
        -INT8_C( 101), -INT8_C( 126), -INT8_C(  19), -INT8_C( 122),  INT8_C( 118),  INT8_C(  64),      INT8_MIN,  INT8_C(  18),
         INT8_C(   4),  INT8_C(  18),  INT8_C(   7),  INT8_C(  69), -INT8_C(   3),  INT8_C(  12), -INT8_C(  25),  INT8_C(  45),
        -INT8_C(  83), -INT8_C( 114), -INT8_C(  26),  INT8_C(  51),  INT8_C( 115),  INT8_C(  72),  INT8_C(  74),  INT8_C( 103),
        -INT8_C(  16), -INT8_C(  10),  INT8_C( 126),  INT8_C(  94),  INT8_C( 117),  INT8_C( 121), -INT8_C(  94),  INT8_C(  16),
        -INT8_C(   4), -INT8_C( 113), -INT8_C( 106),  INT8_C( 114), -INT8_C(  49),  INT8_C(  23), -INT8_C( 124), -INT8_C(  45),
         INT8_C(  41), -INT8_C( 116),  INT8_C(  24),  INT8_C(  39), -INT8_C( 104), -INT8_C(   1),  INT8_C(  84),  INT8_C(  69) },
       INT32_C(         142),
      {  INT16_C(   304), -INT16_C(   366), -INT16_C(  4779),  INT16_C(   431), -INT16_C( 12557),  INT16_C( 11494), -INT16_C( 10011),  INT16_C(   556),
         INT16_C(   349),  INT16_C(   278),  INT16_C(   644),  INT16_C(   344),  INT16_C( 13772),  INT16_C(   353),  INT16_C(  5862),  INT16_C(   246),
         INT16_C( 19183),  INT16_C( 17778),  INT16_C(   248),  INT16_C(   220), -INT16_C( 16682), -INT16_C( 17577), -INT16_C(  8810), -INT16_C( 26780),
         INT16_C(   526), -INT16_C(  7869), -INT16_C( 21187),  INT16_C(  2451), -INT16_C( 15902), -INT16_C( 14201),  INT16_C(   265),  INT16_C(   517) } },
    { { -INT16_C( 15742),  INT16_C( 29545), -INT16_C(  6216),  INT16_C( 11729),  INT16_C( 29537),  INT16_C( 23869), -INT16_C( 11262), -INT16_C( 11825),
         INT16_C( 21483),  INT16_C(  5284), -INT16_C( 17185),  INT16_C( 30523), -INT16_C( 28485),  INT16_C( 18876),  INT16_C( 13514),  INT16_C( 19787),
        -INT16_C( 19209), -INT16_C( 20544), -INT16_C( 28261), -INT16_C(   803),  INT16_C(  6660),  INT16_C(  1625),  INT16_C( 10478), -INT16_C(  9769),
         INT16_C( 31612),  INT16_C( 23534),  INT16_C( 10551), -INT16_C(  3373), -INT16_C( 28743), -INT16_C( 31684), -INT16_C( 30780), -INT16_C( 17455) },
      UINT32_C(3597308219),
      {  INT8_C(  34),  INT8_C(  71), -INT8_C(  45),  INT8_C(  38),  INT8_C(  98),  INT8_C(  44),  INT8_C(  44),  INT8_C(  80),
         INT8_C(  85),  INT8_C(   3),  INT8_C(  42), -INT8_C(  47),  INT8_C( 126),  INT8_C(  24),  INT8_C(  44), -INT8_C(  75),
         INT8_C(  65), -INT8_C(   1), -INT8_C(  89), -INT8_C(   5), -INT8_C( 113), -INT8_C(  29),      INT8_MAX,  INT8_C(  83),
         INT8_C( 106),  INT8_C(  80),  INT8_C(  14), -INT8_C(  91), -INT8_C(  31),  INT8_C( 120),  INT8_C( 124),  INT8_C(   3),
        -INT8_C(  64),  INT8_C(  79),  INT8_C(  41),  INT8_C(  34),  INT8_C( 123),  INT8_C(  85),  INT8_C( 114), -INT8_C(  48),
         INT8_C(  88), -INT8_C( 100), -INT8_C(  95), -INT8_C(  42), -INT8_C(  76), -INT8_C(  50), -INT8_C( 117), -INT8_C(  10),
        -INT8_C(  51),  INT8_C(  50), -INT8_C(  15),  INT8_C(  92),  INT8_C(  22),  INT8_C( 112), -INT8_C(  81),      INT8_MIN,
        -INT8_C(  64), -INT8_C(  67),  INT8_C(  38), -INT8_C(  95),  INT8_C(  54), -INT8_C(  94), -INT8_C(  92), -INT8_C(  10) },
      { -INT8_C(  15), -INT8_C(  51),  INT8_C(  24),  INT8_C( 108),  INT8_C(  34), -INT8_C( 118),  INT8_C(  61),  INT8_C( 122),
         INT8_C(  39), -INT8_C(  34),  INT8_C(  80), -INT8_C(  37), -INT8_C(  84), -INT8_C(  37), -INT8_C(  47),  INT8_C( 122),
         INT8_C(  13), -INT8_C(  62), -INT8_C(  42),  INT8_C(  35),  INT8_C(  50), -INT8_C( 122), -INT8_C(  92), -INT8_C(  14),
         INT8_C(  67), -INT8_C(  54), -INT8_C( 109),  INT8_C( 121),  INT8_C( 108),  INT8_C(  55),  INT8_C( 111),  INT8_C(  93),
         INT8_C(   4), -INT8_C( 121), -INT8_C(  55),  INT8_C(  38),  INT8_C(  18),  INT8_C(   6), -INT8_C(  96),  INT8_C(  57),
        -INT8_C(  27), -INT8_C(  16),  INT8_C(  20), -INT8_C( 111), -INT8_C(  53), -INT8_C(  26),  INT8_C(  11), -INT8_C(  39),
        -INT8_C(  88), -INT8_C(  30), -INT8_C(   4), -INT8_C(  37),  INT8_C( 104), -INT8_C(  96), -INT8_C(  51), -INT8_C(  85),
         INT8_C( 106),  INT8_C(  97),  INT8_C(  37), -INT8_C(  42), -INT8_C( 104), -INT8_C( 108),  INT8_C(  51), -INT8_C(  99) },
       INT32_C(          28),
      {  INT16_C(   598),  INT16_C(   455), -INT16_C(  6216),  INT16_C(   442),  INT16_C(   292),  INT16_C(   223), -INT16_C( 11262), -INT16_C( 11825),
         INT16_C(   376),  INT16_C(  5284), -INT16_C( 17185),  INT16_C( 30523),  INT16_C(   337),  INT16_C( 18876),  INT16_C( 13514),  INT16_C(   405),
        -INT16_C( 19209),  INT16_C(   351), -INT16_C( 28261),  INT16_C(   516),  INT16_C(  6660),  INT16_C(   400),  INT16_C(   415), -INT16_C(  9769),
         INT16_C( 31612),  INT16_C(   305),  INT16_C(   380), -INT16_C(  3373),  INT16_C(   294), -INT16_C( 31684),  INT16_C(   184),  INT16_C(   191) } },
    { {  INT16_C( 25603), -INT16_C(  6041),  INT16_C( 31572),  INT16_C(  8314), -INT16_C( 31391),  INT16_C(  2809), -INT16_C(  2713), -INT16_C( 12315),
        -INT16_C( 19818),  INT16_C(   123), -INT16_C( 24557), -INT16_C( 21289),  INT16_C(  2612),  INT16_C( 20553),  INT16_C(  3079),  INT16_C(  2942),
        -INT16_C(  6800), -INT16_C( 14861),  INT16_C( 28001), -INT16_C( 15643), -INT16_C(  8461),  INT16_C( 23244), -INT16_C( 20013),  INT16_C( 26922),
        -INT16_C( 23196),  INT16_C( 30570),  INT16_C( 16709),  INT16_C( 31011),  INT16_C( 27723),  INT16_C( 21450),  INT16_C( 18553), -INT16_C(  5794) },
      UINT32_C(2410565934),
      { -INT8_C(  65), -INT8_C( 109),  INT8_C(  81), -INT8_C(  78),  INT8_C( 113),  INT8_C(  30),  INT8_C(  12),  INT8_C(  69),
        -INT8_C(  49),  INT8_C(  54), -INT8_C(  82),  INT8_C(  51), -INT8_C(  37),  INT8_C(  24), -INT8_C(  85),  INT8_C(  32),
         INT8_C(  89), -INT8_C(  50), -INT8_C( 102), -INT8_C(  91),  INT8_C(  59),  INT8_C( 100), -INT8_C(   8), -INT8_C(  76),
        -INT8_C(  84),  INT8_C(  86), -INT8_C(  99), -INT8_C(  38), -INT8_C(  89),  INT8_C(  76),  INT8_C( 105),  INT8_C( 102),
        -INT8_C(  33), -INT8_C(  69),  INT8_C(  24),  INT8_C(  81), -INT8_C(  39),  INT8_C(  37), -INT8_C( 106), -INT8_C(  88),
         INT8_C(  91),  INT8_C(  68), -INT8_C(  36),  INT8_C(  55),  INT8_C(  93), -INT8_C( 121),  INT8_C(  87), -INT8_C(  74),
         INT8_C(  85), -INT8_C(  15),  INT8_C(  91), -INT8_C( 112),  INT8_C(  85),  INT8_C(  83),  INT8_C(  68),  INT8_C(   2),
        -INT8_C(  87), -INT8_C(  30), -INT8_C(  36),  INT8_C(  81),  INT8_C(  46),  INT8_C(  70), -INT8_C(  73),  INT8_C(  13) },
      {  INT8_C(   1), -INT8_C(  48),  INT8_C(  94), -INT8_C(  38), -INT8_C(  11), -INT8_C(  12), -INT8_C( 126),  INT8_C(  80),
         INT8_C(  57),  INT8_C(  94), -INT8_C( 121), -INT8_C( 106), -INT8_C(  27), -INT8_C(  33),  INT8_C(  76),  INT8_C(  59),
        -INT8_C(  48), -INT8_C(  88), -INT8_C(  53),  INT8_C(  38), -INT8_C(   5),  INT8_C(  16),  INT8_C(  40), -INT8_C(  91),
        -INT8_C(  14),  INT8_C(   4), -INT8_C(  10),  INT8_C(  32),  INT8_C(  74), -INT8_C(  83),  INT8_C(  45),  INT8_C(  75),
         INT8_C( 125), -INT8_C( 116),  INT8_C(  37),  INT8_C( 114),      INT8_MIN, -INT8_C(  88), -INT8_C(  61), -INT8_C(  71),
         INT8_C(   6),  INT8_C(  74),  INT8_C(  79), -INT8_C(  20),  INT8_C(  41), -INT8_C( 100),  INT8_C(  39), -INT8_C(   6),
         INT8_C(  68), -INT8_C(  14),  INT8_C(  32),  INT8_C(  63),  INT8_C(   2),  INT8_C(  72), -INT8_C(  28), -INT8_C(  12),
         INT8_C(  76), -INT8_C(  38),  INT8_C(  20), -INT8_C( 105), -INT8_C( 120),  INT8_C(  66), -INT8_C(  30),  INT8_C(   5) },
       INT32_C(         206),
      {  INT16_C( 25603),  INT16_C(   229),  INT16_C(   513),  INT16_C(   454), -INT16_C( 31391),  INT16_C(   263), -INT16_C(  2713), -INT16_C( 12315),
         INT16_C(   580),  INT16_C(   123), -INT16_C( 24557), -INT16_C( 21289),  INT16_C(   344),  INT16_C( 20553),  INT16_C(   176),  INT16_C(  2942),
        -INT16_C(  6800),  INT16_C(   509),  INT16_C(   458),  INT16_C(   158), -INT16_C(  8461),  INT16_C(   200), -INT16_C( 20013),  INT16_C(   327),
         INT16_C(   110),  INT16_C(   422),  INT16_C(   265),  INT16_C(   345),  INT16_C( 27723),  INT16_C( 21450),  INT16_C( 18553),  INT16_C(   413) } },
    { {  INT16_C( 15280), -INT16_C( 18936),  INT16_C( 22405), -INT16_C( 20574), -INT16_C( 13837),  INT16_C( 14249), -INT16_C( 13892), -INT16_C( 16777),
         INT16_C( 23313),  INT16_C( 23987), -INT16_C( 14538), -INT16_C( 16652), -INT16_C( 10487), -INT16_C( 10301),  INT16_C( 15327), -INT16_C( 28890),
         INT16_C( 11894), -INT16_C(   955), -INT16_C(  6011),  INT16_C( 31147),  INT16_C( 21681),  INT16_C( 28080),  INT16_C( 10013),  INT16_C( 11820),
        -INT16_C(  8317), -INT16_C( 18037), -INT16_C( 32602), -INT16_C( 20361),  INT16_C( 14935),  INT16_C( 13959), -INT16_C( 21130), -INT16_C(  4923) },
      UINT32_C(1642597083),
      { -INT8_C(  14), -INT8_C( 109), -INT8_C(  38), -INT8_C(  92), -INT8_C(  25), -INT8_C( 118),  INT8_C(  17),  INT8_C(   4),
        -INT8_C(  78),  INT8_C(  61),  INT8_C(  50),  INT8_C(  53),  INT8_C(  28), -INT8_C(  66), -INT8_C(  18), -INT8_C(  61),
         INT8_C(  62),  INT8_C( 101),  INT8_C( 115), -INT8_C( 107), -INT8_C(  97), -INT8_C(   6), -INT8_C(  53),  INT8_C(  21),
        -INT8_C(  88), -INT8_C( 112),  INT8_C(   2), -INT8_C( 125), -INT8_C( 102), -INT8_C(  22), -INT8_C(  28), -INT8_C( 115),
         INT8_C( 126), -INT8_C(  66),  INT8_C(  49),  INT8_C( 101),  INT8_C(  73),  INT8_C(  66),  INT8_C( 106), -INT8_C(   5),
             INT8_MIN, -INT8_C( 100),  INT8_C(  48), -INT8_C( 100),  INT8_C(  90),  INT8_C(  30),  INT8_C(  95), -INT8_C( 104),
        -INT8_C( 125), -INT8_C(  46),  INT8_C(  45),  INT8_C(  34), -INT8_C(  51), -INT8_C(   8),  INT8_C(  56),  INT8_C( 117),
        -INT8_C( 120),  INT8_C(  58), -INT8_C(   8),  INT8_C(  35),  INT8_C(  36), -INT8_C(  35), -INT8_C(  80), -INT8_C(  94) },
      { -INT8_C( 101), -INT8_C(  31),  INT8_C(   8), -INT8_C(  28),  INT8_C(  35),  INT8_C( 114), -INT8_C(  33), -INT8_C(  93),
         INT8_C(  14),  INT8_C(  15),  INT8_C(  64),  INT8_C( 105),  INT8_C(  45), -INT8_C(  97),  INT8_C(   1), -INT8_C(  80),
         INT8_C( 114),  INT8_C(  47), -INT8_C(  45),  INT8_C(  63),  INT8_C(  39),  INT8_C(  11), -INT8_C(  76), -INT8_C(  80),
         INT8_C(  69), -INT8_C(  84), -INT8_C(  45),  INT8_C( 105), -INT8_C( 119), -INT8_C( 125),  INT8_C(  12),  INT8_C(  37),
         INT8_C( 100),  INT8_C(  20),  INT8_C(   9), -INT8_C( 121), -INT8_C( 122), -INT8_C(  23),  INT8_C(  43), -INT8_C( 108),
        -INT8_C(   8),  INT8_C( 107), -INT8_C(   3),  INT8_C(  38),  INT8_C(  10), -INT8_C(   1), -INT8_C(  42),  INT8_C( 124),
         INT8_C(  46), -INT8_C(  87), -INT8_C(  69),  INT8_C(  85), -INT8_C(  76),  INT8_C( 111),  INT8_C(   5), -INT8_C(   7),
         INT8_C(  28), -INT8_C(  40),  INT8_C(  99), -INT8_C(  91),  INT8_C(  91),  INT8_C( 111), -INT8_C(  54), -INT8_C(  65) },
       INT32_C(         131),
      {  INT16_C(   438),  INT16_C(   280),  INT16_C( 22405),  INT16_C(   284),  INT16_C(   404),  INT16_C( 14249),  INT16_C(   462),  INT16_C(   730),
         INT16_C( 23313),  INT16_C(   271), -INT16_C( 14538),  INT16_C(   604), -INT16_C( 10487), -INT16_C( 10301),  INT16_C( 15327), -INT16_C( 28890),
         INT16_C( 11894), -INT16_C(   955), -INT16_C(  6011),  INT16_C(   413),  INT16_C( 21681),  INT16_C(   434),  INT16_C(   384),  INT16_C(   376),
         INT16_C(   453), -INT16_C( 18037), -INT16_C( 32602), -INT16_C( 20361),  INT16_C( 14935),  INT16_C(   332),  INT16_C(   489), -INT16_C(  4923) } },
    { {  INT16_C( 29373), -INT16_C( 19043), -INT16_C( 25635), -INT16_C(  6181), -INT16_C( 19814), -INT16_C( 14236),  INT16_C(  8027),  INT16_C(  4125),
         INT16_C(  9103), -INT16_C( 21751),  INT16_C( 27899),  INT16_C( 22352),  INT16_C(  7131),  INT16_C( 24086),  INT16_C( 24047), -INT16_C( 21401),
         INT16_C(  1487), -INT16_C( 21407),  INT16_C( 15776),  INT16_C( 14996), -INT16_C(  1809),  INT16_C( 18946),  INT16_C(  7959), -INT16_C( 22950),
         INT16_C( 25666),  INT16_C( 15953), -INT16_C( 23856), -INT16_C( 21355), -INT16_C( 21571), -INT16_C( 21494),  INT16_C( 29193), -INT16_C( 10152) },
      UINT32_C( 394639735),
      { -INT8_C(  10),  INT8_C(  25),  INT8_C(  81), -INT8_C(  27),  INT8_C(  17),  INT8_C(  83),  INT8_C(  48),  INT8_C(  40),
         INT8_C( 114), -INT8_C( 118), -INT8_C(  49), -INT8_C(  75), -INT8_C(  18),  INT8_C(  32), -INT8_C(  13), -INT8_C(  65),
        -INT8_C(  62), -INT8_C( 120),  INT8_C( 107),      INT8_MAX,  INT8_C(  51),  INT8_C( 117),  INT8_C(  43),  INT8_C(  60),
        -INT8_C(  25), -INT8_C( 125),  INT8_C(  21),  INT8_C(  94),  INT8_C(  61), -INT8_C( 102),  INT8_C( 117),  INT8_C(  51),
        -INT8_C(  77), -INT8_C(  58),  INT8_C(  25), -INT8_C(  60),  INT8_C(  25),  INT8_C(  73), -INT8_C(  20), -INT8_C( 116),
        -INT8_C(  45), -INT8_C(  69),  INT8_C(  65), -INT8_C(  62), -INT8_C(  36),  INT8_C(  52), -INT8_C( 127), -INT8_C(  98),
        -INT8_C(  68), -INT8_C(  20),  INT8_C(  30), -INT8_C(  17),  INT8_C(  97),  INT8_C(  73),  INT8_C(  44),  INT8_C(  73),
        -INT8_C(  51),  INT8_C(  65), -INT8_C(  89),  INT8_C(  10), -INT8_C(  37),  INT8_C(  29),  INT8_C(  61), -INT8_C( 114) },
      { -INT8_C(  29),  INT8_C(  86),  INT8_C(  82), -INT8_C(   3), -INT8_C(  97),  INT8_C(  62), -INT8_C( 119),  INT8_C( 115),
        -INT8_C(   6), -INT8_C(  54),  INT8_C(  53), -INT8_C(  42), -INT8_C(   2), -INT8_C(  74),  INT8_C( 116), -INT8_C(  70),
        -INT8_C(  94), -INT8_C( 110), -INT8_C(  87),  INT8_C(   3), -INT8_C(  36), -INT8_C(  43),  INT8_C(  76), -INT8_C(  87),
         INT8_C(  22), -INT8_C(  12), -INT8_C(  77), -INT8_C(  15),  INT8_C(  17), -INT8_C(  16),      INT8_MAX, -INT8_C(  12),
         INT8_C(  71), -INT8_C(  47), -INT8_C(  15), -INT8_C(  26),  INT8_C(  16),  INT8_C( 122),  INT8_C(  89),  INT8_C(  10),
         INT8_C(  68), -INT8_C( 114), -INT8_C(  32),  INT8_C(  66),  INT8_C(  68),  INT8_C(  84), -INT8_C(   4), -INT8_C(  26),
        -INT8_C(  25), -INT8_C(  90), -INT8_C(  22), -INT8_C(  61),  INT8_C( 123),  INT8_C(  54),  INT8_C( 108), -INT8_C( 110),
         INT8_C(  42),  INT8_C(  31), -INT8_C( 125),  INT8_C(  59),  INT8_C(  15),  INT8_C(   3),  INT8_C(  48),  INT8_C(  86) },
       INT32_C(         212),
      {  INT16_C(   105),  INT16_C(   459),  INT16_C(   368), -INT16_C(  6181),  INT16_C(   257),  INT16_C(   218),  INT16_C(   204),  INT16_C(  4125),
         INT16_C(   228), -INT16_C( 21751),  INT16_C( 27899),  INT16_C(   337),  INT16_C(   223),  INT16_C(   298),  INT16_C( 24047),  INT16_C(   444),
         INT16_C(   369), -INT16_C( 21407),  INT16_C(   611),  INT16_C( 14996), -INT16_C(  1809),  INT16_C( 18946),  INT16_C(  7959),  INT16_C(   365),
         INT16_C(   361),  INT16_C(   305),  INT16_C(   357), -INT16_C( 21355),  INT16_C(   288), -INT16_C( 21494),  INT16_C( 29193), -INT16_C( 10152) } },
  };

  simde__m512i src, a, b, r;

  src = simde_mm512_loadu_epi16(test_vec[0].src);
  a = simde_mm512_loadu_epi8(test_vec[0].a);
  b = simde_mm512_loadu_epi8(test_vec[0].b);
  r = simde_mm512_mask_dbsad_epu8(src, test_vec[0].k, a, b, INT32_C(         123));
  simde_test_x86_assert_equal_i16x32(r, simde_mm512_loadu_epi16(test_vec[0].r));

  src = simde_mm512_loadu_epi16(test_vec[1].src);
  a = simde_mm512_loadu_epi8(test_vec[1].a);
  b = simde_mm512_loadu_epi8(test_vec[1].b);
  r = simde_mm512_mask_dbsad_epu8(src, test_vec[1].k, a, b, INT32_C(         171));
  simde_test_x86_assert_equal_i16x32(r, simde_mm512_loadu_epi16(test_vec[1].r));

  src = simde_mm512_loadu_epi16(test_vec[2].src);
  a = simde_mm512_loadu_epi8(test_vec[2].a);
  b = simde_mm512_loadu_epi8(test_vec[2].b);
  r = simde_mm512_mask_dbsad_epu8(src, test_vec[2].k, a, b, INT32_C(         178));
  simde_test_x86_assert_equal_i16x32(r, simde_mm512_loadu_epi16(test_vec[2].r));

  src = simde_mm512_loadu_epi16(test_vec[3].src);
  a = simde_mm512_loadu_epi8(test_vec[3].a);
  b = simde_mm512_loadu_epi8(test_vec[3].b);
  r = simde_mm512_mask_dbsad_epu8(src, test_vec[3].k, a, b, INT32_C(         142));
  simde_test_x86_assert_equal_i16x32(r, simde_mm512_loadu_epi16(test_vec[3].r));

  src = simde_mm512_loadu_epi16(test_vec[4].src);
  a = simde_mm512_loadu_epi8(test_vec[4].a);
  b = simde_mm512_loadu_epi8(test_vec[4].b);
  r = simde_mm512_mask_dbsad_epu8(src, test_vec[4].k, a, b, INT32_C(          28));
  simde_test_x86_assert_equal_i16x32(r, simde_mm512_loadu_epi16(test_vec[4].r));

  src = simde_mm512_loadu_epi16(test_vec[5].src);
  a = simde_mm512_loadu_epi8(test_vec[5].a);
  b = simde_mm512_loadu_epi8(test_vec[5].b);
  r = simde_mm512_mask_dbsad_epu8(src, test_vec[5].k, a, b, INT32_C(         206));
  simde_test_x86_assert_equal_i16x32(r, simde_mm512_loadu_epi16(test_vec[5].r));

  src = simde_mm512_loadu_epi16(test_vec[6].src);
  a = simde_mm512_loadu_epi8(test_vec[6].a);
  b = simde_mm512_loadu_epi8(test_vec[6].b);
  r = simde_mm512_mask_dbsad_epu8(src, test_vec[6].k, a, b, INT32_C(         131));
  simde_test_x86_assert_equal_i16x32(r, simde_mm512_loadu_epi16(test_vec[6].r));

  src = simde_mm512_loadu_epi16(test_vec[7].src);
  a = simde_mm512_loadu_epi8(test_vec[7].a);
  b = simde_mm512_loadu_epi8(test_vec[7].b);
  r = simde_mm512_mask_dbsad_epu8(src, test_vec[7].k, a, b, INT32_C(         212));
  simde_test_x86_assert_equal_i16x32(r, simde_mm512_loadu_epi16(test_vec[7].r));

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m512i src = simde_test_x86_random_i16x32();
    simde__mmask32 k = simde_test_x86_random_mmask32();
    simde__m512i a = simde_test_x86_random_i8x64();
    simde__m512i b = simde_test_x86_random_i8x64();
    int imm8 = simde_test_codegen_random_i32() & 255;
    simde__m512i r;
    SIMDE_CONSTIFY_256_(simde_mm512_mask_dbsad_epu8, r, simde_mm512_setzero_si512(), imm8, src, k, a, b);

    simde_test_x86_write_i16x32(2, src, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_mmask32(2, k, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i8x64(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i8x64(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, imm8, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i16x32(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm512_maskz_dbsad_epu8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask32 k;
    const int8_t a[64];
    const int8_t b[64];
    const int imm8;
    const int16_t r[32];
  } test_vec[] = {
    { UINT32_C(3773732508),
      {  INT8_C(  37), -INT8_C(  50),  INT8_C(  35),  INT8_C( 105),  INT8_C(  35),  INT8_C(  31),  INT8_C(  80),  INT8_C(  10),
        -INT8_C(  59),  INT8_C(  58), -INT8_C(  51),  INT8_C(  65),  INT8_C( 112),  INT8_C(  57), -INT8_C(  45), -INT8_C( 101),
         INT8_C(  88),  INT8_C(  86), -INT8_C(  42),  INT8_C( 103),  INT8_C(  89),  INT8_C(   6), -INT8_C(  66),  INT8_C(  46),
         INT8_C(  40), -INT8_C(   5),  INT8_C(  18), -INT8_C(  60), -INT8_C( 111),  INT8_C(   1), -INT8_C(  92), -INT8_C(  74),
        -INT8_C(  49), -INT8_C(  57),  INT8_C(  32), -INT8_C(  14), -INT8_C(  25),  INT8_C( 112), -INT8_C(   4), -INT8_C(  84),
        -INT8_C(  86), -INT8_C(  55), -INT8_C(  19),  INT8_C(  26),  INT8_C(   2), -INT8_C(  64), -INT8_C(  75),  INT8_C(  90),
         INT8_C(  23), -INT8_C( 116), -INT8_C(  62),  INT8_C( 112), -INT8_C( 110),      INT8_MIN, -INT8_C(  98), -INT8_C(  70),
         INT8_C( 123), -INT8_C(  79),  INT8_C( 126),  INT8_C(  12), -INT8_C(  78),  INT8_C(  35), -INT8_C(  61), -INT8_C( 127) },
      { -INT8_C(  22), -INT8_C(  29),  INT8_C( 116), -INT8_C(  47),  INT8_C(  83),  INT8_C( 112),  INT8_C( 126), -INT8_C(   3),
         INT8_C(  58),  INT8_C( 107),  INT8_C(  23),  INT8_C(  60),  INT8_C(  44), -INT8_C(  51), -INT8_C( 105),  INT8_C(  67),
         INT8_C(  89),  INT8_C(  89), -INT8_C(  77), -INT8_C(  21), -INT8_C(  39),  INT8_C(  82), -INT8_C(  90),  INT8_C(  84),
         INT8_C(   3),  INT8_C(  36),  INT8_C(  96), -INT8_C(  75),  INT8_C(  71),  INT8_C(  35),  INT8_C(  54),  INT8_C(  50),
         INT8_C(   6), -INT8_C(  86),  INT8_C(   3),  INT8_C(  89),  INT8_C(  27), -INT8_C( 127),  INT8_C(  86),  INT8_C(  85),
        -INT8_C(  19),  INT8_C( 110), -INT8_C( 111),  INT8_C(  25),  INT8_C(  59),  INT8_C(  40),  INT8_C(  92), -INT8_C( 108),
        -INT8_C( 127),  INT8_C(  15),      INT8_MAX,  INT8_C(  90),  INT8_C(  97),  INT8_C(  37), -INT8_C(  82),  INT8_C( 100),
         INT8_C(  74),  INT8_C(  15),  INT8_C(  25), -INT8_C( 111),  INT8_C(  50),  INT8_C(  80), -INT8_C(  61),  INT8_C(  57) },
       INT32_C(         250),
      {  INT16_C(     0),  INT16_C(     0),  INT16_C(   160),  INT16_C(    92),  INT16_C(   356),  INT16_C(     0),  INT16_C(     0),  INT16_C(    68),
         INT16_C(     0),  INT16_C(   195),  INT16_C(   379),  INT16_C(     0),  INT16_C(   429),  INT16_C(     0),  INT16_C(     0),  INT16_C(   422),
         INT16_C(     0),  INT16_C(   163),  INT16_C(   250),  INT16_C(   500),  INT16_C(     0),  INT16_C(   361),  INT16_C(   306),  INT16_C(   422),
         INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(   168),  INT16_C(   233),  INT16_C(   317) } },
    { UINT32_C( 896198984),
      {  INT8_C(  87), -INT8_C(   4),  INT8_C(  78), -INT8_C( 110),  INT8_C(  36), -INT8_C(  86),  INT8_C(  38), -INT8_C(  90),
        -INT8_C(  70), -INT8_C(  91),  INT8_C(   0),  INT8_C(  27), -INT8_C(  53), -INT8_C(  81),      INT8_MIN,  INT8_C(  21),
        -INT8_C(  66), -INT8_C( 103), -INT8_C(  90), -INT8_C(  16), -INT8_C(  23),  INT8_C( 106),  INT8_C(  41), -INT8_C(  28),
         INT8_C(  49), -INT8_C(  68), -INT8_C(   7),  INT8_C( 121), -INT8_C(  91),  INT8_C( 100), -INT8_C(  81), -INT8_C(   4),
         INT8_C(  96), -INT8_C(   3), -INT8_C( 114), -INT8_C( 124), -INT8_C(  88), -INT8_C(  76),  INT8_C(  42),  INT8_C(  98),
         INT8_C(  89),  INT8_C(  43),  INT8_C( 125),  INT8_C(  36), -INT8_C(  38), -INT8_C(   3),  INT8_C(  57), -INT8_C( 104),
        -INT8_C( 105), -INT8_C(  32), -INT8_C( 120),      INT8_MIN,  INT8_C(  74), -INT8_C(  78),  INT8_C( 100),  INT8_C( 123),
         INT8_C( 110),  INT8_C(  94), -INT8_C(  12),  INT8_C(  19), -INT8_C(  62), -INT8_C(  93),  INT8_C(  15),  INT8_C(  34) },
      { -INT8_C(  95), -INT8_C(  99), -INT8_C(  90),  INT8_C(  73),  INT8_C(  81), -INT8_C(  47), -INT8_C(  85), -INT8_C(  86),
        -INT8_C(   4),  INT8_C(  40), -INT8_C(  49), -INT8_C(  42),  INT8_C(  38),  INT8_C(   8),  INT8_C( 110), -INT8_C(  67),
        -INT8_C(  24), -INT8_C(  10),  INT8_C(  61),  INT8_C(  50), -INT8_C(  88), -INT8_C(  94), -INT8_C(  83),  INT8_C(  22),
         INT8_C(   0), -INT8_C(  94),  INT8_C(  41), -INT8_C(  62),  INT8_C(  69),  INT8_C(  56), -INT8_C(  28), -INT8_C(  26),
        -INT8_C(  43), -INT8_C( 118),  INT8_C(  47),  INT8_C(  38),  INT8_C(  91), -INT8_C(  38), -INT8_C(  47),  INT8_C(  87),
         INT8_C(   3), -INT8_C(  96),  INT8_C(  45),  INT8_C(  41), -INT8_C(  88), -INT8_C( 101), -INT8_C(  26), -INT8_C( 111),
        -INT8_C( 110),  INT8_C(  35), -INT8_C(  61),  INT8_C(  58), -INT8_C(  59),  INT8_C( 113),  INT8_C(  81), -INT8_C(  59),
         INT8_C(  19),  INT8_C( 122), -INT8_C( 121),  INT8_C(  88), -INT8_C(  77),  INT8_C( 107),  INT8_C(  63), -INT8_C( 120) },
       INT32_C(         246),
      {  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(   443),  INT16_C(     0),  INT16_C(     0),  INT16_C(   210),  INT16_C(     0),
         INT16_C(   370),  INT16_C(     0),  INT16_C(     0),  INT16_C(   277),  INT16_C(     0),  INT16_C(   118),  INT16_C(   495),  INT16_C(   239),
         INT16_C(     0),  INT16_C(   414),  INT16_C(     0),  INT16_C(   503),  INT16_C(     0),  INT16_C(   405),  INT16_C(   234),  INT16_C(     0),
         INT16_C(   275),  INT16_C(     0),  INT16_C(   258),  INT16_C(     0),  INT16_C(   380),  INT16_C(   302),  INT16_C(     0),  INT16_C(     0) } },
    { UINT32_C(1286176841),
      {  INT8_C(  32), -INT8_C(  42),  INT8_C( 117), -INT8_C(  56),  INT8_C( 114),  INT8_C(  91),  INT8_C(  89),  INT8_C(   4),
         INT8_C( 126),  INT8_C(  29),  INT8_C(  62),  INT8_C(  68), -INT8_C( 114), -INT8_C( 113),  INT8_C(   9), -INT8_C(  95),
         INT8_C(  10), -INT8_C( 111), -INT8_C(   7), -INT8_C(  67), -INT8_C(   4),  INT8_C(  56),  INT8_C(  69), -INT8_C(  14),
        -INT8_C(  89), -INT8_C(  12),  INT8_C(  68), -INT8_C(  16),  INT8_C( 116), -INT8_C(  19),  INT8_C(  60), -INT8_C( 108),
        -INT8_C(  61), -INT8_C(  79),  INT8_C(  93),  INT8_C(  53),  INT8_C(  12), -INT8_C(  74),  INT8_C(  57), -INT8_C( 118),
        -INT8_C(  45),  INT8_C( 120), -INT8_C(  50),  INT8_C(  97),  INT8_C(   7), -INT8_C(  40),  INT8_C(   2),  INT8_C(  17),
         INT8_C( 105), -INT8_C(   4), -INT8_C(  50),  INT8_C( 101),  INT8_C(  52),  INT8_C(  20),  INT8_C(  88), -INT8_C(  37),
         INT8_C(   8), -INT8_C( 100), -INT8_C(  53),  INT8_C( 125), -INT8_C( 119),  INT8_C(   7),  INT8_C(  17),  INT8_C(  76) },
      { -INT8_C(  72),  INT8_C( 110), -INT8_C( 126), -INT8_C(  60),  INT8_C(  37), -INT8_C(  69),  INT8_C(  79), -INT8_C(   8),
         INT8_C(  51),  INT8_C(  29),  INT8_C(  90),  INT8_C(  59), -INT8_C(  11),  INT8_C(  92),  INT8_C(  76),  INT8_C(  94),
         INT8_C(  88),  INT8_C(  27), -INT8_C(  60), -INT8_C( 115),  INT8_C(  47),  INT8_C(  28),  INT8_C( 104),  INT8_C(  55),
        -INT8_C(  72),  INT8_C(  52), -INT8_C(  76),  INT8_C(  65),  INT8_C(  59), -INT8_C(  58), -INT8_C( 115), -INT8_C(  12),
         INT8_C(  52),  INT8_C(  15), -INT8_C(  72),  INT8_C(  89), -INT8_C(  53),  INT8_C(   7),  INT8_C(  82), -INT8_C(   2),
         INT8_C(  37), -INT8_C(  84),  INT8_C(  57),  INT8_C(  26),  INT8_C(   8), -INT8_C( 122),  INT8_C( 121),  INT8_C(  97),
        -INT8_C(  95),  INT8_C(  61), -INT8_C(  18), -INT8_C(  48),  INT8_C(  89),  INT8_C(  86),  INT8_C(   7),  INT8_C(  17),
        -INT8_C( 118), -INT8_C(  68),  INT8_C(  82), -INT8_C(  58), -INT8_C( 126), -INT8_C(  33), -INT8_C(  70), -INT8_C(  74) },
       INT32_C(         239),
      {  INT16_C(   482),  INT16_C(     0),  INT16_C(     0),  INT16_C(   249),  INT16_C(     0),  INT16_C(     0),  INT16_C(   441),  INT16_C(     0),
         INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(   374),
         INT16_C(   302),  INT16_C(     0),  INT16_C(     0),  INT16_C(   353),  INT16_C(     0),  INT16_C(   371),  INT16_C(     0),  INT16_C(   463),
         INT16_C(     0),  INT16_C(     0),  INT16_C(   342),  INT16_C(   408),  INT16_C(     0),  INT16_C(     0),  INT16_C(   506),  INT16_C(     0) } },
    { UINT32_C(2679661178),
      {  INT8_C(  14), -INT8_C(  14), -INT8_C(  71),  INT8_C(  22),  INT8_C( 120),  INT8_C(  50),  INT8_C( 119),  INT8_C(  25),
         INT8_C( 111),  INT8_C( 101), -INT8_C(  23), -INT8_C(  56), -INT8_C(  68), -INT8_C(  16), -INT8_C(  39),  INT8_C(  70),
        -INT8_C(  84),  INT8_C(  43),  INT8_C(  12),  INT8_C(  46),  INT8_C(  11), -INT8_C(  58), -INT8_C(  27), -INT8_C(   6),
         INT8_C(  57), -INT8_C(  11), -INT8_C(  76), -INT8_C(  77),  INT8_C(  87),  INT8_C( 108),  INT8_C(  82),  INT8_C( 101),
         INT8_C(  94),  INT8_C(  11),  INT8_C( 123), -INT8_C(  42),  INT8_C(  62), -INT8_C(  13), -INT8_C(  17), -INT8_C(  83),
         INT8_C(  88), -INT8_C(  40),  INT8_C( 118),  INT8_C(  20), -INT8_C(  55),  INT8_C(  79),  INT8_C(  91),  INT8_C( 117),
         INT8_C( 123),  INT8_C( 103), -INT8_C(  92), -INT8_C( 122),  INT8_C(  46), -INT8_C( 119),      INT8_MIN,  INT8_C( 103),
         INT8_C( 126),  INT8_C(  52),  INT8_C(  26), -INT8_C(  43), -INT8_C(  96),  INT8_C( 108),  INT8_C(  58), -INT8_C(   1) },
      {  INT8_C( 119), -INT8_C(  75), -INT8_C(  43), -INT8_C(  75), -INT8_C(  88), -INT8_C(  59),  INT8_C(  99),  INT8_C(   1),
        -INT8_C(  99), -INT8_C(  39),  INT8_C(  21),  INT8_C( 102),  INT8_C(  40),  INT8_C( 112), -INT8_C(  36), -INT8_C(  93),
        -INT8_C(  40),      INT8_MIN,  INT8_C(  41),  INT8_C(   6),  INT8_C(   9), -INT8_C(  87),  INT8_C( 109), -INT8_C( 121),
        -INT8_C(  35), -INT8_C( 121),  INT8_C(  92),  INT8_C( 126), -INT8_C(  13), -INT8_C( 106),  INT8_C( 125),  INT8_C( 106),
         INT8_C(  75),  INT8_C(  82),  INT8_C(  32), -INT8_C(  12),  INT8_C(  23), -INT8_C( 125), -INT8_C(  11), -INT8_C(  75),
         INT8_C(  92),  INT8_C(  10),  INT8_C(  27), -INT8_C( 124),  INT8_C( 123), -INT8_C(   9),  INT8_C(  40),  INT8_C(  83),
         INT8_C( 119),  INT8_C(  81),  INT8_C(  89),      INT8_MIN, -INT8_C(   5), -INT8_C(  58),  INT8_C(   7), -INT8_C(  40),
         INT8_C(  77),  INT8_C(  99),  INT8_C(  86),  INT8_C(  64), -INT8_C(   7), -INT8_C(  45), -INT8_C(  86),  INT8_C(  69) },
       INT32_C(          38),
      {  INT16_C(     0),  INT16_C(   653),  INT16_C(     0),  INT16_C(   288),  INT16_C(   472),  INT16_C(   398),  INT16_C(   514),  INT16_C(     0),
         INT16_C(     0),  INT16_C(   237),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(   322),  INT16_C(   184),  INT16_C(     0),
         INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(   470),  INT16_C(   413),  INT16_C(   336),  INT16_C(     0),  INT16_C(   167),
         INT16_C(   198),  INT16_C(   258),  INT16_C(   331),  INT16_C(   298),  INT16_C(   305),  INT16_C(     0),  INT16_C(     0),  INT16_C(   296) } },
    { UINT32_C(2851221069),
      {  INT8_C(  56),  INT8_C(  14),  INT8_C(  46), -INT8_C(  77),  INT8_C(   5),  INT8_C(  86),  INT8_C(   6),  INT8_C( 125),
        -INT8_C(  89),  INT8_C(  95), -INT8_C(   3), -INT8_C(  94),  INT8_C(  37),  INT8_C(   5),  INT8_C( 123),  INT8_C( 114),
         INT8_C( 104), -INT8_C(  47), -INT8_C(  78),  INT8_C(  98), -INT8_C(  91),  INT8_C(  93), -INT8_C(  89), -INT8_C(  53),
         INT8_C(  39), -INT8_C(  32),  INT8_C(   8),  INT8_C( 117),  INT8_C(  14), -INT8_C(   5),  INT8_C(  30),  INT8_C(  70),
         INT8_C(   9),  INT8_C(  76), -INT8_C(   6),  INT8_C(  14), -INT8_C(  94),  INT8_C(   0), -INT8_C( 117),  INT8_C(  74),
         INT8_C(  96), -INT8_C( 119), -INT8_C(  20), -INT8_C( 123), -INT8_C( 114),  INT8_C( 103), -INT8_C(   8), -INT8_C(  10),
         INT8_C(  57), -INT8_C(  86),  INT8_C(  88), -INT8_C(  34),  INT8_C(   7), -INT8_C(   1), -INT8_C(  87),  INT8_C(  47),
        -INT8_C(  33), -INT8_C(  79), -INT8_C(  92), -INT8_C(  19), -INT8_C(  84), -INT8_C(  62),  INT8_C(  52), -INT8_C(  75) },
      {  INT8_C(  15),  INT8_C(  46), -INT8_C(  60), -INT8_C(  79),  INT8_C(  46),  INT8_C(  79), -INT8_C(   5), -INT8_C( 114),
        -INT8_C(  40), -INT8_C(  24),  INT8_C(  20),  INT8_C( 102),  INT8_C(  79),  INT8_C(  12),  INT8_C(  93), -INT8_C( 120),
        -INT8_C(  74), -INT8_C(  75),  INT8_C( 102), -INT8_C(  66), -INT8_C(  75),  INT8_C(  15), -INT8_C(  19), -INT8_C( 108),
        -INT8_C(  63), -INT8_C( 111), -INT8_C( 126),  INT8_C( 109),  INT8_C(  83), -INT8_C(  74),  INT8_C(  35),  INT8_C(  98),
        -INT8_C(  28), -INT8_C(  25),  INT8_C(  20),  INT8_C(  18),  INT8_C(  54),  INT8_C(  15), -INT8_C(  95),  INT8_C(  15),
        -INT8_C(   9), -INT8_C(  75),  INT8_C( 117),  INT8_C(  71), -INT8_C(  63), -INT8_C(  46), -INT8_C(  49),  INT8_C( 119),
        -INT8_C( 120),  INT8_C(  54),  INT8_C(  53),  INT8_C(  61),  INT8_C(  69),  INT8_C(  34), -INT8_C(  47),  INT8_C(   6),
        -INT8_C(  77),  INT8_C(  83),  INT8_C( 116),  INT8_C(   7),  INT8_C(   9), -INT8_C( 105),  INT8_C( 105), -INT8_C(  19) },
       INT32_C(         126),
      {  INT16_C(   481),  INT16_C(     0),  INT16_C(   217),  INT16_C(   142),  INT16_C(     0),  INT16_C(     0),  INT16_C(   299),  INT16_C(     0),
         INT16_C(     0),  INT16_C(   204),  INT16_C(   156),  INT16_C(   249),  INT16_C(     0),  INT16_C(   486),  INT16_C(     0),  INT16_C(     0),
         INT16_C(     0),  INT16_C(   571),  INT16_C(     0),  INT16_C(     0),  INT16_C(   213),  INT16_C(   380),  INT16_C(   506),  INT16_C(   390),
         INT16_C(   452),  INT16_C(     0),  INT16_C(     0),  INT16_C(   322),  INT16_C(     0),  INT16_C(   385),  INT16_C(     0),  INT16_C(   236) } },
    { UINT32_C(2227413389),
      {  INT8_C(  86),  INT8_C(  57), -INT8_C(  53),  INT8_C(  23),  INT8_C(  11), -INT8_C( 101), -INT8_C( 114), -INT8_C( 109),
        -INT8_C(  47), -INT8_C(  60), -INT8_C(  48),  INT8_C(  22), -INT8_C(  26), -INT8_C(  94),  INT8_C(  29), -INT8_C( 102),
        -INT8_C(  11), -INT8_C( 111), -INT8_C(  95), -INT8_C(   1),  INT8_C(  40),  INT8_C(  10), -INT8_C(  20), -INT8_C(  90),
        -INT8_C( 120), -INT8_C(  20),  INT8_C(  90),  INT8_C(  21), -INT8_C( 115),  INT8_C(  30), -INT8_C( 103), -INT8_C(  29),
         INT8_C(  87),  INT8_C( 101), -INT8_C(   6),  INT8_C(  98),  INT8_C(   0), -INT8_C( 119), -INT8_C(  10), -INT8_C(  47),
         INT8_C(  77), -INT8_C(  58), -INT8_C(  25),  INT8_C(  51),  INT8_C( 104),  INT8_C(   4), -INT8_C(  51),  INT8_C(  94),
        -INT8_C( 107),  INT8_C( 110),  INT8_C(  93), -INT8_C(  67),  INT8_C( 121),  INT8_C(  73),  INT8_C(  99),  INT8_C(   1),
         INT8_C(  54), -INT8_C(  66),  INT8_C(  22), -INT8_C(  61), -INT8_C(  36), -INT8_C(  81), -INT8_C(  89),  INT8_C(  51) },
      {  INT8_C(  20), -INT8_C(  95), -INT8_C( 107),  INT8_C(  20),  INT8_C(  42), -INT8_C( 117), -INT8_C(  27),  INT8_C( 119),
         INT8_C(  82), -INT8_C(  51), -INT8_C(  85), -INT8_C(  70), -INT8_C(  47),  INT8_C( 120),  INT8_C(  24),  INT8_C( 103),
        -INT8_C(  25),  INT8_C( 117),  INT8_C(  36),  INT8_C(  96), -INT8_C(  65), -INT8_C( 120),  INT8_C(  97), -INT8_C(  11),
         INT8_C(  70),  INT8_C( 119), -INT8_C(  72),  INT8_C(  34),  INT8_C(  38),  INT8_C(  95),  INT8_C(  85),  INT8_C(  59),
         INT8_C(   1), -INT8_C(  22),  INT8_C(  79),  INT8_C(  43),  INT8_C( 118),  INT8_C(  53), -INT8_C(  93), -INT8_C(  56),
         INT8_C(   2),  INT8_C(  78), -INT8_C( 126), -INT8_C(  45), -INT8_C(  58), -INT8_C( 101),  INT8_C(  58), -INT8_C(  83),
         INT8_C(  16),  INT8_C(  95),  INT8_C(  13), -INT8_C(  49), -INT8_C(  25),  INT8_C( 110), -INT8_C(  60),  INT8_C(  45),
        -INT8_C(  27),  INT8_C( 125),  INT8_C(  79),  INT8_C(  12), -INT8_C(  36), -INT8_C(  92),  INT8_C(  71), -INT8_C(  35) },
       INT32_C(         142),
      {  INT16_C(   347),  INT16_C(     0),  INT16_C(   285),  INT16_C(   374),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(   483),
         INT16_C(   445),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(   274),  INT16_C(     0),  INT16_C(   162),
         INT16_C(   341),  INT16_C(   177),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(   283),  INT16_C(   226),
         INT16_C(     0),  INT16_C(     0),  INT16_C(   387),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(   137) } },
    { UINT32_C(3452742859),
      { -INT8_C(   6),  INT8_C(  79), -INT8_C(  95), -INT8_C(  64), -INT8_C(  22), -INT8_C(  37),  INT8_C( 110), -INT8_C(   6),
         INT8_C(  58),  INT8_C( 123), -INT8_C(  54),  INT8_C(  33), -INT8_C(  22), -INT8_C( 114),  INT8_C(  78), -INT8_C(  49),
         INT8_C(  11), -INT8_C(  99), -INT8_C(  37), -INT8_C(  24),  INT8_C(  65),  INT8_C(  34), -INT8_C(  59), -INT8_C(  48),
        -INT8_C(  71), -INT8_C(  50), -INT8_C(  44), -INT8_C( 124),  INT8_C( 122), -INT8_C(  95),  INT8_C(  82),  INT8_C( 116),
        -INT8_C(  16), -INT8_C(  13),  INT8_C(  53), -INT8_C(  38), -INT8_C(  50), -INT8_C(  93), -INT8_C(  44),  INT8_C(   9),
         INT8_C(  30), -INT8_C(  98),  INT8_C(  42),  INT8_C(   8),  INT8_C(  45),  INT8_C( 121), -INT8_C(  40),  INT8_C(  56),
         INT8_C(  22), -INT8_C(  77),  INT8_C(  32),  INT8_C(  88), -INT8_C(  42), -INT8_C(  26),  INT8_C(  40), -INT8_C( 113),
        -INT8_C(  76), -INT8_C(   4),  INT8_C(  19),  INT8_C(  47), -INT8_C(  99),  INT8_C( 101), -INT8_C(  93), -INT8_C( 115) },
      {  INT8_C(  88), -INT8_C(  40),  INT8_C( 103),  INT8_C(  39),  INT8_C( 123),  INT8_C(  60),  INT8_C(  48), -INT8_C( 102),
        -INT8_C(  38),  INT8_C(  90), -INT8_C(  94),  INT8_C(   7), -INT8_C(  45),  INT8_C( 122),  INT8_C(  64), -INT8_C(  22),
         INT8_C(  46),  INT8_C(  96),  INT8_C(  66),  INT8_C(   4),  INT8_C(  70),  INT8_C( 106), -INT8_C( 109), -INT8_C(   5),
         INT8_C( 102), -INT8_C(  90),  INT8_C(  42),  INT8_C(   4),  INT8_C(  12), -INT8_C(  51), -INT8_C( 111),  INT8_C( 100),
        -INT8_C(  90), -INT8_C(   7), -INT8_C( 117),  INT8_C(  33),  INT8_C(  53), -INT8_C(  69), -INT8_C(  69),  INT8_C(  15),
         INT8_C(  22),  INT8_C(  94),  INT8_C(  23), -INT8_C(  23), -INT8_C(  40),  INT8_C(  87), -INT8_C(  45),  INT8_C(   6),
        -INT8_C(  73),  INT8_C(  21),  INT8_C(  10), -INT8_C(   2),      INT8_MAX, -INT8_C(  99), -INT8_C(   7), -INT8_C(  26),
         INT8_C(  68),  INT8_C(  35), -INT8_C(  22),  INT8_C(  80), -INT8_C(  16),  INT8_C( 123), -INT8_C(  76), -INT8_C( 106) },
       INT32_C(         116),
      {  INT16_C(   510),  INT16_C(   249),  INT16_C(     0),  INT16_C(   543),  INT16_C(     0),  INT16_C(     0),  INT16_C(   454),  INT16_C(   196),
         INT16_C(     0),  INT16_C(     0),  INT16_C(   260),  INT16_C(   249),  INT16_C(     0),  INT16_C(   255),  INT16_C(     0),  INT16_C(   168),
         INT16_C(     0),  INT16_C(     0),  INT16_C(   534),  INT16_C(   486),  INT16_C(     0),  INT16_C(     0),  INT16_C(   575),  INT16_C(   267),
         INT16_C(   507),  INT16_C(     0),  INT16_C(   329),  INT16_C(   366),  INT16_C(     0),  INT16_C(     0),  INT16_C(   124),  INT16_C(   147) } },
    { UINT32_C( 297366523),
      { -INT8_C(  47), -INT8_C(  48), -INT8_C(   5), -INT8_C(  86),  INT8_C(  39), -INT8_C(  50), -INT8_C(  80), -INT8_C(  34),
        -INT8_C(  28), -INT8_C(  69), -INT8_C(  36),  INT8_C(  99),  INT8_C(  88), -INT8_C(  43),  INT8_C(  73), -INT8_C( 100),
        -INT8_C(   8),  INT8_C(  51), -INT8_C(  20), -INT8_C(  23), -INT8_C(  81), -INT8_C(  95),      INT8_MAX,  INT8_C(  35),
        -INT8_C(  31),  INT8_C(  55), -INT8_C(  51), -INT8_C(  36), -INT8_C(  85), -INT8_C( 122), -INT8_C(  18),  INT8_C( 124),
         INT8_C(  86), -INT8_C(  23),  INT8_C(  38),  INT8_C( 125), -INT8_C(  73), -INT8_C(  41),  INT8_C(  91), -INT8_C( 101),
        -INT8_C( 110),  INT8_C(  56), -INT8_C(   1), -INT8_C(  22),  INT8_C(  13),  INT8_C(  72), -INT8_C( 121),  INT8_C(   6),
         INT8_C( 124),  INT8_C( 115), -INT8_C(  17),  INT8_C(  43),  INT8_C(  20),  INT8_C( 110),  INT8_C(  78), -INT8_C(  11),
        -INT8_C(  90),  INT8_C(  27), -INT8_C(  46),  INT8_C(  81), -INT8_C(  95), -INT8_C(  64), -INT8_C(  51), -INT8_C(   9) },
      { -INT8_C(  87), -INT8_C(  12),  INT8_C( 116),  INT8_C(  96), -INT8_C(  53), -INT8_C(  48), -INT8_C(   4),  INT8_C(  93),
         INT8_C(   8), -INT8_C(   5),  INT8_C(  71),  INT8_C(  21),  INT8_C(  67), -INT8_C(  50),  INT8_C(  27), -INT8_C(  65),
         INT8_C(  66),  INT8_C(  10), -INT8_C(  22),  INT8_C(  86),  INT8_C( 121),  INT8_C(  57),  INT8_C(  76),  INT8_C(  31),
         INT8_C(  84),  INT8_C(  30),  INT8_C( 112), -INT8_C(  10), -INT8_C(  34),  INT8_C(  61), -INT8_C(  19), -INT8_C( 121),
         INT8_C(  49),  INT8_C(  98), -INT8_C(  25), -INT8_C(   4),  INT8_C(  50), -INT8_C(  29),  INT8_C(  89),  INT8_C(  58),
        -INT8_C(  34), -INT8_C(  95),  INT8_C(  79),  INT8_C(  34),  INT8_C( 111),  INT8_C( 107), -INT8_C(  31), -INT8_C(  79),
         INT8_C( 117), -INT8_C(  52),  INT8_C(   8), -INT8_C(  18),  INT8_C(   5),  INT8_C(  84),  INT8_C(  13),  INT8_C(  89),
         INT8_C( 114),  INT8_C( 125),  INT8_C(  79),  INT8_C(  80), -INT8_C(  69),  INT8_C(  61), -INT8_C(  41), -INT8_C(  20) },
       INT32_C(         159),
      {  INT16_C(   389),  INT16_C(   347),  INT16_C(     0),  INT16_C(   516),  INT16_C(    84),  INT16_C(   303),  INT16_C(   444),  INT16_C(   473),
         INT16_C(   135),  INT16_C(   485),  INT16_C(     0),  INT16_C(     0),  INT16_C(   424),  INT16_C(   499),  INT16_C(   446),  INT16_C(     0),
         INT16_C(   390),  INT16_C(     0),  INT16_C(     0),  INT16_C(   196),  INT16_C(   609),  INT16_C(   323),  INT16_C(     0),  INT16_C(   294),
         INT16_C(   334),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(   423),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0) } },
  };

  simde__m512i a, b, r;

  a = simde_mm512_loadu_epi8(test_vec[0].a);
  b = simde_mm512_loadu_epi8(test_vec[0].b);
  r = simde_mm512_maskz_dbsad_epu8(test_vec[0].k, a, b, INT32_C(         250));
  simde_test_x86_assert_equal_i16x32(r, simde_mm512_loadu_epi16(test_vec[0].r));

  a = simde_mm512_loadu_epi8(test_vec[1].a);
  b = simde_mm512_loadu_epi8(test_vec[1].b);
  r = simde_mm512_maskz_dbsad_epu8(test_vec[1].k, a, b, INT32_C(         246));
  simde_test_x86_assert_equal_i16x32(r, simde_mm512_loadu_epi16(test_vec[1].r));

  a = simde_mm512_loadu_epi8(test_vec[2].a);
  b = simde_mm512_loadu_epi8(test_vec[2].b);
  r = simde_mm512_maskz_dbsad_epu8(test_vec[2].k, a, b, INT32_C(         239));
  simde_test_x86_assert_equal_i16x32(r, simde_mm512_loadu_epi16(test_vec[2].r));

  a = simde_mm512_loadu_epi8(test_vec[3].a);
  b = simde_mm512_loadu_epi8(test_vec[3].b);
  r = simde_mm512_maskz_dbsad_epu8(test_vec[3].k, a, b, INT32_C(          38));
  simde_test_x86_assert_equal_i16x32(r, simde_mm512_loadu_epi16(test_vec[3].r));

  a = simde_mm512_loadu_epi8(test_vec[4].a);
  b = simde_mm512_loadu_epi8(test_vec[4].b);
  r = simde_mm512_maskz_dbsad_epu8(test_vec[4].k, a, b, INT32_C(         126));
  simde_test_x86_assert_equal_i16x32(r, simde_mm512_loadu_epi16(test_vec[4].r));

  a = simde_mm512_loadu_epi8(test_vec[5].a);
  b = simde_mm512_loadu_epi8(test_vec[5].b);
  r = simde_mm512_maskz_dbsad_epu8(test_vec[5].k, a, b, INT32_C(         142));
  simde_test_x86_assert_equal_i16x32(r, simde_mm512_loadu_epi16(test_vec[5].r));

  a = simde_mm512_loadu_epi8(test_vec[6].a);
  b = simde_mm512_loadu_epi8(test_vec[6].b);
  r = simde_mm512_maskz_dbsad_epu8(test_vec[6].k, a, b, INT32_C(         116));
  simde_test_x86_assert_equal_i16x32(r, simde_mm512_loadu_epi16(test_vec[6].r));

  a = simde_mm512_loadu_epi8(test_vec[7].a);
  b = simde_mm512_loadu_epi8(test_vec[7].b);
  r = simde_mm512_maskz_dbsad_epu8(test_vec[7].k, a, b, INT32_C(         159));
  simde_test_x86_assert_equal_i16x32(r, simde_mm512_loadu_epi16(test_vec[7].r));

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__mmask32 k = simde_test_x86_random_mmask32();
    simde__m512i a = simde_test_x86_random_i8x64();
    simde__m512i b = simde_test_x86_random_i8x64();
    int imm8 = simde_test_codegen_random_i32() & 255;
    simde__m512i r;
    SIMDE_CONSTIFY_256_(simde_mm512_maskz_dbsad_epu8, r, simde_mm512_setzero_si512(), imm8, k, a, b);

    simde_test_x86_write_mmask32(2, k, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i8x64(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i8x64(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, imm8, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i16x32(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_dbsad_epu8)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_mask_dbsad_epu8)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_maskz_dbsad_epu8)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_dbsad_epu8)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_mask_dbsad_epu8)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_maskz_dbsad_epu8)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_dbsad_epu8)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_mask_dbsad_epu8)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_maskz_dbsad_epu8)
SIMDE_TEST_FUNC_LIST_END

#include <test/x86/avx512/test-avx512-footer.h>
