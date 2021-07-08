#define SIMDE_TEST_X86_AVX512_INSN popcnt

#include <test/x86/avx512/test-avx512.h>
#include <simde/x86/avx512/popcnt.h>

static int
test_simde_mm_popcnt_epi8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int8_t a[16];
    const int8_t r[16];
  } test_vec[] = {
    { { -INT8_C(  95), -INT8_C( 112),  INT8_C(  35),  INT8_C(  57),  INT8_C( 117), -INT8_C(  49),  INT8_C(  91), -INT8_C( 116),
         INT8_C(  48), -INT8_C(  74), -INT8_C(  33),  INT8_C(  26),  INT8_C(  20), -INT8_C( 110), -INT8_C(  77),  INT8_C( 125) },
      {  INT8_C(   3),  INT8_C(   2),  INT8_C(   3),  INT8_C(   4),  INT8_C(   5),  INT8_C(   6),  INT8_C(   5),  INT8_C(   3),
         INT8_C(   2),  INT8_C(   5),  INT8_C(   7),  INT8_C(   3),  INT8_C(   2),  INT8_C(   3),  INT8_C(   5),  INT8_C(   6) } },
    { {  INT8_C(   4),  INT8_C(   1),  INT8_C(  71), -INT8_C(  23), -INT8_C(  44),  INT8_C(   8), -INT8_C(   5), -INT8_C(  69),
         INT8_C(  21), -INT8_C(   3),  INT8_C(  44),  INT8_C(  97),  INT8_C(  81), -INT8_C(  14),  INT8_C( 125), -INT8_C(  13) },
      {  INT8_C(   1),  INT8_C(   1),  INT8_C(   4),  INT8_C(   5),  INT8_C(   4),  INT8_C(   1),  INT8_C(   7),  INT8_C(   6),
         INT8_C(   3),  INT8_C(   7),  INT8_C(   3),  INT8_C(   3),  INT8_C(   3),  INT8_C(   5),  INT8_C(   6),  INT8_C(   6) } },
    { { -INT8_C( 125), -INT8_C(  96),  INT8_C(  44), -INT8_C(   8),  INT8_C( 111), -INT8_C( 121), -INT8_C( 124), -INT8_C(  97),
         INT8_C(  62),  INT8_C(  99), -INT8_C(  70),  INT8_C(  82), -INT8_C(  11),  INT8_C( 109), -INT8_C(  48), -INT8_C(   7) },
      {  INT8_C(   3),  INT8_C(   2),  INT8_C(   3),  INT8_C(   5),  INT8_C(   6),  INT8_C(   4),  INT8_C(   2),  INT8_C(   6),
         INT8_C(   5),  INT8_C(   4),  INT8_C(   5),  INT8_C(   3),  INT8_C(   6),  INT8_C(   5),  INT8_C(   3),  INT8_C(   6) } },
    { {  INT8_C( 110),  INT8_C(  23), -INT8_C(  30),  INT8_C(  67),  INT8_C(  31), -INT8_C(  35), -INT8_C(   2),  INT8_C(  53),
        -INT8_C(  37),  INT8_C(  42), -INT8_C( 106),  INT8_C(  44),  INT8_C(  29),  INT8_C(  19),  INT8_C(  31), -INT8_C(  96) },
      {  INT8_C(   5),  INT8_C(   4),  INT8_C(   4),  INT8_C(   3),  INT8_C(   5),  INT8_C(   6),  INT8_C(   7),  INT8_C(   4),
         INT8_C(   6),  INT8_C(   3),  INT8_C(   4),  INT8_C(   3),  INT8_C(   4),  INT8_C(   3),  INT8_C(   5),  INT8_C(   2) } },
    { { -INT8_C(  76),  INT8_C(  75), -INT8_C( 104),  INT8_C(  35), -INT8_C(  45),  INT8_C(  28), -INT8_C(  61),  INT8_C(  17),
             INT8_MIN,  INT8_C( 125),  INT8_C(  99),  INT8_C( 117), -INT8_C(  22),  INT8_C(  51),  INT8_C( 111),  INT8_C(  88) },
      {  INT8_C(   4),  INT8_C(   4),  INT8_C(   3),  INT8_C(   3),  INT8_C(   5),  INT8_C(   3),  INT8_C(   4),  INT8_C(   2),
         INT8_C(   1),  INT8_C(   6),  INT8_C(   4),  INT8_C(   5),  INT8_C(   5),  INT8_C(   4),  INT8_C(   6),  INT8_C(   3) } },
    { {  INT8_C(  75),  INT8_C(  81), -INT8_C( 101),  INT8_C( 106),  INT8_C(  47), -INT8_C( 102), -INT8_C(  97),  INT8_C(  10),
        -INT8_C(  60),  INT8_C(  53),  INT8_C(  54), -INT8_C(  31),  INT8_C(  73),  INT8_C(  86), -INT8_C( 127), -INT8_C(   3) },
      {  INT8_C(   4),  INT8_C(   3),  INT8_C(   5),  INT8_C(   4),  INT8_C(   5),  INT8_C(   4),  INT8_C(   6),  INT8_C(   2),
         INT8_C(   3),  INT8_C(   4),  INT8_C(   4),  INT8_C(   4),  INT8_C(   3),  INT8_C(   4),  INT8_C(   2),  INT8_C(   7) } },
    { { -INT8_C(  95),  INT8_C(  25),  INT8_C(  32),  INT8_C( 116),  INT8_C(  54), -INT8_C(  29), -INT8_C( 123), -INT8_C(  74),
         INT8_C(  96), -INT8_C(  23),  INT8_C(  43),  INT8_C(  74),  INT8_C(  28), -INT8_C( 102), -INT8_C(  93),  INT8_C( 103) },
      {  INT8_C(   3),  INT8_C(   3),  INT8_C(   1),  INT8_C(   4),  INT8_C(   4),  INT8_C(   5),  INT8_C(   3),  INT8_C(   5),
         INT8_C(   2),  INT8_C(   5),  INT8_C(   4),  INT8_C(   3),  INT8_C(   3),  INT8_C(   4),  INT8_C(   4),  INT8_C(   5) } },
    { { -INT8_C(  20),  INT8_C(  62), -INT8_C(  46),  INT8_C(  27), -INT8_C(  40),  INT8_C( 113),  INT8_C(  37), -INT8_C(  99),
        -INT8_C(  89),  INT8_C(  91),  INT8_C( 126), -INT8_C(  16), -INT8_C(  79),  INT8_C(   0), -INT8_C(  19),  INT8_C(  83) },
      {  INT8_C(   5),  INT8_C(   5),  INT8_C(   4),  INT8_C(   4),  INT8_C(   4),  INT8_C(   4),  INT8_C(   3),  INT8_C(   5),
         INT8_C(   5),  INT8_C(   5),  INT8_C(   6),  INT8_C(   4),  INT8_C(   4),  INT8_C(   0),  INT8_C(   6),  INT8_C(   4) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i a = simde_x_mm_loadu_epi8(test_vec[i].a);
    simde__m128i r = simde_mm_popcnt_epi8(a);
    simde_test_x86_assert_equal_i8x16(r, simde_x_mm_loadu_epi8(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m128i a = simde_test_x86_random_i8x16();
    simde__m128i r = simde_mm_popcnt_epi8(a);

    simde_test_x86_write_i8x16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i8x16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_popcnt_epi16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int16_t a[8];
    const int16_t r[8];
  } test_vec[] = {
    { {  INT16_C( 16477),  INT16_C( 20158),  INT16_C( 18616), -INT16_C( 15068),  INT16_C( 14754),  INT16_C(  9995), -INT16_C( 22730), -INT16_C(  6367) },
      {  INT16_C(     6),  INT16_C(    10),  INT16_C(     6),  INT16_C(     6),  INT16_C(     7),  INT16_C(     7),  INT16_C(     9),  INT16_C(     8) } },
    { {  INT16_C( 22158),  INT16_C( 29113), -INT16_C(  3006),  INT16_C( 18235), -INT16_C(   973),  INT16_C( 20169),  INT16_C( 18356),  INT16_C(  4535) },
      {  INT16_C(     8),  INT16_C(     9),  INT16_C(     7),  INT16_C(     9),  INT16_C(    10),  INT16_C(     8),  INT16_C(     8),  INT16_C(     8) } },
    { {  INT16_C( 30343),  INT16_C( 16479), -INT16_C( 31554),  INT16_C( 24581),  INT16_C(  4285), -INT16_C(  3193), -INT16_C( 22345),  INT16_C( 18139) },
      {  INT16_C(     9),  INT16_C(     7),  INT16_C(     8),  INT16_C(     4),  INT16_C(     7),  INT16_C(    10),  INT16_C(     9),  INT16_C(     9) } },
    { { -INT16_C( 27393),  INT16_C( 16823), -INT16_C(  3192), -INT16_C( 17528),  INT16_C( 20975), -INT16_C( 23799), -INT16_C( 16231),  INT16_C(  8372) },
      {  INT16_C(    11),  INT16_C(     8),  INT16_C(     8),  INT16_C(     8),  INT16_C(    10),  INT16_C(     6),  INT16_C(     6),  INT16_C(     5) } },
    { {  INT16_C(  5174), -INT16_C(  2976),  INT16_C( 26264),  INT16_C( 21844), -INT16_C(  9354),  INT16_C( 11849),  INT16_C(  9348), -INT16_C( 31884) },
      {  INT16_C(     6),  INT16_C(     7),  INT16_C(     7),  INT16_C(     7),  INT16_C(    11),  INT16_C(     7),  INT16_C(     4),  INT16_C(     7) } },
    { {  INT16_C( 11192),  INT16_C( 16580),  INT16_C( 19486),  INT16_C(  3579),  INT16_C(  1181),  INT16_C( 14000),  INT16_C( 26052), -INT16_C(  1193) },
      {  INT16_C(     8),  INT16_C(     4),  INT16_C(     7),  INT16_C(    10),  INT16_C(     6),  INT16_C(     7),  INT16_C(     7),  INT16_C(    12) } },
    { { -INT16_C( 18567),  INT16_C(  4591),  INT16_C( 17437), -INT16_C( 27546), -INT16_C( 20705), -INT16_C( 23614),  INT16_C( 14035), -INT16_C( 29914) },
      {  INT16_C(    11),  INT16_C(     9),  INT16_C(     6),  INT16_C(     7),  INT16_C(    11),  INT16_C(     7),  INT16_C(     9),  INT16_C(     7) } },
    { { -INT16_C(  5535), -INT16_C( 32565), -INT16_C( 14794), -INT16_C( 11123),  INT16_C( 16074), -INT16_C( 28918),  INT16_C( 24995),  INT16_C(  7306) },
      {  INT16_C(     8),  INT16_C(     6),  INT16_C(     8),  INT16_C(     8),  INT16_C(     9),  INT16_C(     7),  INT16_C(     7),  INT16_C(     6) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i a = simde_x_mm_loadu_epi16(test_vec[i].a);
    simde__m128i r = simde_mm_popcnt_epi16(a);
    simde_test_x86_assert_equal_i16x8(r, simde_x_mm_loadu_epi16(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m128i a = simde_test_x86_random_i16x8();
    simde__m128i r = simde_mm_popcnt_epi16(a);

    simde_test_x86_write_i16x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i16x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_popcnt_epi8)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_popcnt_epi16)
SIMDE_TEST_FUNC_LIST_END

#include <test/x86/avx512/test-avx512-footer.h>
