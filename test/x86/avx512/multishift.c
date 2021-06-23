#define SIMDE_TEST_X86_AVX512_INSN multishift

#include <test/x86/avx512/test-avx512.h>
#include <simde/x86/avx512/multishift.h>

static int
test_simde_mm_multishift_epi64_epi8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int8_t a[16];
    const int64_t b[2];
    const int8_t r[16];
  } test_vec[] = {
    { {  INT8_C(  44),  INT8_C(  48),  INT8_C(  92), -INT8_C(  87),  INT8_C(  78), -INT8_C(  73),  INT8_C( 116),  INT8_C(  73),
         INT8_C(   9),  INT8_C(  82),  INT8_C(  27), -INT8_C( 121),  INT8_C(   2), -INT8_C(  28), -INT8_C(  26), -INT8_C( 101) },
      {  INT64_C( 5763271140136713756), -INT64_C( 7092618072189247633) },
      { -INT8_C(  76), -INT8_C(   5),  INT8_C(  17), -INT8_C(  96),  INT8_C( 111), -INT8_C(  97), -INT8_C(   1), -INT8_C(   1),
         INT8_C( 111), -INT8_C(  23),  INT8_C(  33), -INT8_C(  66), -INT8_C(  37),  INT8_C(  87), -INT8_C(  43),  INT8_C(  33) } },
    { {  INT8_C(  38), -INT8_C(  19),  INT8_C(  70),  INT8_C( 116), -INT8_C(  92), -INT8_C(  70), -INT8_C(  66), -INT8_C(  83),
         INT8_C(  12), -INT8_C(  39),  INT8_C(  52),  INT8_C(  14), -INT8_C(  67),  INT8_C(  26), -INT8_C(  87), -INT8_C(  39) },
      {  INT64_C( 8429032084717552920), -INT64_C( 5125917082985914929) },
      { -INT8_C(  64), -INT8_C(  49),  INT8_C(  20),  INT8_C(  79),  INT8_C(   0),  INT8_C(  29),  INT8_C(  97), -INT8_C(  49),
         INT8_C(  73),  INT8_C(  32), -INT8_C( 115),  INT8_C(  18),  INT8_C( 125), -INT8_C( 112), -INT8_C( 118),  INT8_C(  32) } },
    { {  INT8_C(   2),  INT8_C(  35),  INT8_C(  45), -INT8_C(  90), -INT8_C(  35), -INT8_C(  21),  INT8_C(  84), -INT8_C(  22),
        -INT8_C(  60), -INT8_C( 120), -INT8_C(   8), -INT8_C( 127), -INT8_C(  93), -INT8_C(  94),  INT8_C(  90), -INT8_C(  69) },
      {  INT64_C( 1144017931846635367),  INT64_C( 8882837315119965435) },
      { -INT8_C(  39), -INT8_C(  57),  INT8_C(   2),  INT8_C( 120), -INT8_C(   5),  INT8_C(  11), -INT8_C(  58),  INT8_C(  23),
         INT8_C(  79),  INT8_C( 100),  INT8_C( 123),  INT8_C( 125), -INT8_C(  81),  INT8_C(  94),  INT8_C(  99),  INT8_C( 111) } },
    { {  INT8_C(  80),  INT8_C( 115),  INT8_C(  34),  INT8_C(  46),  INT8_C(  94),  INT8_C( 118),  INT8_C(  24),  INT8_C(  34),
        -INT8_C(   2),  INT8_C(  16), -INT8_C(  93), -INT8_C(  95), -INT8_C(  78), -INT8_C(   3),  INT8_C(  93),  INT8_C(  25) },
      {  INT64_C( 1989014475403280972),  INT64_C( 7475955690161892042) },
      { -INT8_C( 123),  INT8_C( 115), -INT8_C( 120),  INT8_C( 105), -INT8_C( 126),  INT8_C( 110), -INT8_C( 117), -INT8_C( 120),
         INT8_C(  41), -INT8_C(  88), -INT8_C(  62),  INT8_C(  11), -INT8_C(  17),  INT8_C(  83), -INT8_C(  70), -INT8_C(  94) } },
    { {  INT8_C(  97), -INT8_C(  31), -INT8_C( 107), -INT8_C(  65),  INT8_C(  87), -INT8_C(  83), -INT8_C(  31),  INT8_C(  86),
        -INT8_C(  66), -INT8_C( 124), -INT8_C(   9),  INT8_C( 112), -INT8_C( 127),  INT8_C(  84), -INT8_C( 118), -INT8_C(  51) },
      {  INT64_C( 4634753176289480470),  INT64_C( 5358232324477876957) },
      { -INT8_C(  70), -INT8_C(  70), -INT8_C(  78),  INT8_C(  44),  INT8_C( 108), -INT8_C( 113), -INT8_C(  70), -INT8_C(  39),
         INT8_C( 117), -INT8_C(  83), -INT8_C( 108),  INT8_C(  92),  INT8_C( 110),  INT8_C(  72),  INT8_C(  62),  INT8_C(  39) } },
    { {  INT8_C(  37), -INT8_C(  15),  INT8_C(   9),  INT8_C( 124), -INT8_C(  97), -INT8_C(  21), -INT8_C(  46),  INT8_C(  93),
         INT8_C( 111), -INT8_C(  54), -INT8_C(  51), -INT8_C(  15),  INT8_C(  30),  INT8_C(  87), -INT8_C(  66),  INT8_C(  53) },
      { -INT64_C( 1721293098922076313),  INT64_C(  714165670012362935) },
      { -INT8_C(  24),  INT8_C(  14), -INT8_C( 117),  INT8_C( 126),  INT8_C(  23), -INT8_C( 105),  INT8_C(  26),  INT8_C(  94),
        -INT8_C(  46),  INT8_C( 104), -INT8_C(  19), -INT8_C(  12), -INT8_C( 110),  INT8_C(  63), -INT8_C(  36),  INT8_C(  79) } },
    { {  INT8_C(  42), -INT8_C(  13), -INT8_C( 123), -INT8_C(  55), -INT8_C(  34),  INT8_C(  88),  INT8_C(  38),  INT8_C(  77),
         INT8_C(  34), -INT8_C(  12),  INT8_C(  62),  INT8_C(  64),  INT8_C(  75), -INT8_C(   3),  INT8_C( 117), -INT8_C(  78) },
      {  INT64_C( 6127335988660265236),  INT64_C( 5204435065655059788) },
      {  INT8_C(  42), -INT8_C(  95),  INT8_C(   8), -INT8_C(  16),  INT8_C( 120),  INT8_C(  31), -INT8_C(  82),      INT8_MAX,
        -INT8_C( 121), -INT8_C( 125),  INT8_C(  49),  INT8_C(  76), -INT8_C( 100),  INT8_C(  98),  INT8_C(  65),  INT8_C(  14) } },
    { { -INT8_C(  47), -INT8_C(  66),  INT8_C(  18), -INT8_C(  81),  INT8_C(  22),  INT8_C(  56), -INT8_C(   4),  INT8_C(  56),
         INT8_C(  44),  INT8_C(  59),  INT8_C( 121),  INT8_C( 120),  INT8_C(  56), -INT8_C(  18),  INT8_C(  42),  INT8_C(  76) },
      { -INT64_C( 5637815804538078769),  INT64_C( 7403665541684115289) },
      { -INT8_C(  74),  INT8_C(  62),  INT8_C(  91), -INT8_C( 124), -INT8_C(  75), -INT8_C(  79), -INT8_C(   5), -INT8_C(  79),
        -INT8_C(  15),  INT8_C(  44), -INT8_C(  77),  INT8_C( 102),  INT8_C( 102), -INT8_C(   4), -INT8_C(  58),  INT8_C(  27) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i a = simde_x_mm_loadu_epi8(test_vec[i].a);
    simde__m128i b = simde_x_mm_loadu_epi64(test_vec[i].b);
    simde__m128i r = simde_mm_multishift_epi64_epi8(a, b);
    simde_test_x86_assert_equal_i8x16(r, simde_x_mm_loadu_epi8(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m128i a = simde_test_x86_random_i8x16();
    simde__m128i b = simde_test_x86_random_i64x2();
    simde__m128i r = simde_mm_multishift_epi64_epi8(a, b);

    simde_test_x86_write_i8x16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i64x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i8x16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_mask_multishift_epi64_epi8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int8_t src[16];
    const simde__mmask16 k;
    const int8_t a[16];
    const int64_t b[2];
    const int8_t r[16];
  } test_vec[] = {
    { { -INT8_C(  40), -INT8_C(  47),  INT8_C(  21), -INT8_C(  17),  INT8_C(  10),  INT8_C(  17),  INT8_C(  39),  INT8_C(  54),
         INT8_C(  76), -INT8_C(  96), -INT8_C(  82), -INT8_C( 124), -INT8_C( 113), -INT8_C(  39), -INT8_C(  47),  INT8_C(  94) },
      UINT16_C(15762),
      { -INT8_C(  52), -INT8_C(   9), -INT8_C(  79), -INT8_C( 114), -INT8_C(  88),  INT8_C(  10),  INT8_C(  69), -INT8_C( 119),
        -INT8_C( 127), -INT8_C(  38), -INT8_C(  93),  INT8_C(  64),  INT8_C(  64),  INT8_C( 124),  INT8_C(  18),  INT8_C(  85) },
      {  INT64_C(   86609985075092587), -INT64_C( 1421329747528728008) },
      { -INT8_C(  40),  INT8_C(   2),  INT8_C(  21), -INT8_C(  17), -INT8_C(  77),  INT8_C(  17),  INT8_C(  39), -INT8_C( 114),
         INT8_C(  28), -INT8_C(  96), -INT8_C( 124),  INT8_C(  56),  INT8_C(  56), -INT8_C( 114), -INT8_C(  47),  INT8_C(  94) } },
    { {  INT8_C( 100), -INT8_C(   9),  INT8_C( 123),  INT8_C(  12),  INT8_C(   1), -INT8_C(  64), -INT8_C( 106), -INT8_C( 126),
        -INT8_C( 101),  INT8_C(  57), -INT8_C(  62), -INT8_C(  37), -INT8_C(  75), -INT8_C(  44),  INT8_C(  49),  INT8_C(  32) },
      UINT16_C(39152),
      { -INT8_C(  77),  INT8_C(  67),  INT8_C(  75), -INT8_C(  26),  INT8_C(  68), -INT8_C( 125), -INT8_C(  88),  INT8_C(  30),
        -INT8_C( 116), -INT8_C(  56), -INT8_C( 118), -INT8_C(  46), -INT8_C(  75), -INT8_C(  18), -INT8_C(  55),  INT8_C(  48) },
      {  INT64_C( 1137875016846723835),  INT64_C( 5994524890255032423) },
      {  INT8_C( 100), -INT8_C(   9),  INT8_C( 123),  INT8_C(  12), -INT8_C(  81),  INT8_C(  95), -INT8_C( 117),  INT8_C(  50),
        -INT8_C( 101),  INT8_C(  57), -INT8_C(  62),  INT8_C(  56), -INT8_C( 103), -INT8_C(  44),  INT8_C(  49),  INT8_C(  48) } },
    { {  INT8_C(  23),  INT8_C( 123),  INT8_C(  57),  INT8_C(  91), -INT8_C(   1), -INT8_C(  31),  INT8_C( 121), -INT8_C( 117),
        -INT8_C(  86),  INT8_C(   3),  INT8_C(  94),  INT8_C(  95), -INT8_C(  14),  INT8_C(  39), -INT8_C( 113), -INT8_C(  19) },
      UINT16_C(32754),
      {  INT8_C( 126),  INT8_C(  62),  INT8_C(  11),  INT8_C(  72),  INT8_C(  77),  INT8_C( 114), -INT8_C(  56),  INT8_C(  49),
         INT8_C(  10),  INT8_C( 105),  INT8_C(   5),  INT8_C(  58), -INT8_C(  68),  INT8_C(  28), -INT8_C(  75), -INT8_C(  10) },
      { -INT64_C( 6993103680457689993),  INT64_C( 5832082156914337248) },
      {  INT8_C(  23), -INT8_C(  34),  INT8_C(  57),  INT8_C(  91), -INT8_C(  67), -INT8_C(  68), -INT8_C(  76),  INT8_C( 121),
         INT8_C( 121), -INT8_C(  37),  INT8_C(  47),  INT8_C(  20),  INT8_C(   5),  INT8_C(  38), -INT8_C( 121), -INT8_C(  19) } },
    { { -INT8_C(  10), -INT8_C(   6), -INT8_C( 103),  INT8_C(  67),  INT8_C( 108),  INT8_C(  97),  INT8_C( 116),  INT8_C( 118),
        -INT8_C(  54),  INT8_C( 121), -INT8_C(  80), -INT8_C( 121), -INT8_C( 107),  INT8_C( 101),  INT8_C( 125),  INT8_C(  12) },
      UINT16_C(21530),
      { -INT8_C(   4),  INT8_C(  90), -INT8_C(  42), -INT8_C(  16), -INT8_C(   8), -INT8_C(  74), -INT8_C(  43), -INT8_C(  67),
         INT8_C(  38), -INT8_C(  88),  INT8_C( 117),  INT8_C(  21), -INT8_C(   8),  INT8_C( 107),  INT8_C(  15), -INT8_C( 111) },
      { -INT64_C( 6801352493848364114),  INT64_C( 4257625951623852612) },
      { -INT8_C(  10),  INT8_C(  72), -INT8_C( 103), -INT8_C( 100), -INT8_C(  95),  INT8_C(  97),  INT8_C( 116),  INT8_C( 118),
        -INT8_C(  54),  INT8_C( 121), -INT8_C(  40), -INT8_C( 121),  INT8_C(  59),  INT8_C( 101),  INT8_C(  12),  INT8_C(  12) } },
    { {  INT8_C( 122), -INT8_C(  20),  INT8_C(  43),  INT8_C( 114), -INT8_C(  94),  INT8_C(   0),  INT8_C(  48), -INT8_C(  56),
        -INT8_C(  88), -INT8_C(  91), -INT8_C(  35), -INT8_C(  95),  INT8_C(  16), -INT8_C(  20),  INT8_C(  50), -INT8_C(  66) },
      UINT16_C( 9575),
      { -INT8_C(  31),  INT8_C(  88), -INT8_C(  29),  INT8_C( 126), -INT8_C(   7),  INT8_C(  39), -INT8_C(  80),  INT8_C(   0),
        -INT8_C(  23), -INT8_C(  18),  INT8_C(  32), -INT8_C(   1),  INT8_C(  41), -INT8_C( 101), -INT8_C(  21),  INT8_C(  84) },
      {  INT64_C( 3738829187508964621), -INT64_C( 7856943302113693026) },
      { -INT8_C(  85),  INT8_C(  61), -INT8_C(  86),  INT8_C( 114), -INT8_C(  94), -INT8_C(   6), -INT8_C(  30), -INT8_C(  56),
         INT8_C(  67), -INT8_C(  91), -INT8_C(  79), -INT8_C(  95),  INT8_C(  16),  INT8_C(  58),  INT8_C(  50), -INT8_C(  66) } },
    { { -INT8_C(  32), -INT8_C(  39),  INT8_C(  16), -INT8_C(  39),  INT8_C(   1), -INT8_C(  64), -INT8_C(  39), -INT8_C(  22),
        -INT8_C(  81), -INT8_C(   6), -INT8_C(  23), -INT8_C(  40), -INT8_C( 107), -INT8_C(  44),  INT8_C(  45), -INT8_C(  94) },
      UINT16_C(33377),
      { -INT8_C(  32), -INT8_C(  73),      INT8_MAX, -INT8_C(  62), -INT8_C(  21),  INT8_C(  30), -INT8_C(  75),  INT8_C(  11),
        -INT8_C(  17),  INT8_C( 102), -INT8_C( 110), -INT8_C(  27), -INT8_C(   8),  INT8_C( 114), -INT8_C(  65),  INT8_C(   9) },
      { -INT64_C( 7845419353682362292),  INT64_C( 3963387950194472017) },
      { -INT8_C(  86), -INT8_C(  39),  INT8_C(  16), -INT8_C(  39),  INT8_C(   1), -INT8_C(  88), -INT8_C( 104), -INT8_C(  22),
        -INT8_C(  81),  INT8_C(  33), -INT8_C(  23), -INT8_C(  40), -INT8_C( 107), -INT8_C(  44),  INT8_C(  45), -INT8_C(  38) } },
    { {      INT8_MIN,      INT8_MAX, -INT8_C(   7),  INT8_C( 107), -INT8_C(  99), -INT8_C(  82),  INT8_C( 118), -INT8_C( 116),
         INT8_C(  20),  INT8_C(   8),  INT8_C( 114),  INT8_C(  13),  INT8_C( 123),  INT8_C(  49),  INT8_C(  22), -INT8_C(  57) },
      UINT16_C(57329),
      { -INT8_C(  20), -INT8_C( 101),  INT8_C(  88),  INT8_C(  12),  INT8_C(  46), -INT8_C(  87), -INT8_C(  64), -INT8_C( 107),
         INT8_C(  39),  INT8_C(  23),  INT8_C(  93),  INT8_C(  39),  INT8_C(  78), -INT8_C(  35), -INT8_C(  90),  INT8_C(  72) },
      {  INT64_C( 4811827718053577800), -INT64_C(  788864369123180008) },
      {  INT8_C( 112),      INT8_MAX, -INT8_C(   7),  INT8_C( 107),  INT8_C(  28), -INT8_C( 123),  INT8_C(  72), -INT8_C(   9),
        -INT8_C(  56),  INT8_C(  92),  INT8_C(  73), -INT8_C(  56), -INT8_C(  51),  INT8_C(  49), -INT8_C( 112),  INT8_C(  66) } },
    { { -INT8_C(   1),  INT8_C( 101),  INT8_C(   1),  INT8_C(  45),  INT8_C(  14), -INT8_C(  62), -INT8_C(  62),  INT8_C(  53),
        -INT8_C(  39),  INT8_C(  32),  INT8_C(  92),  INT8_C(  40), -INT8_C(   3),  INT8_C(   3),  INT8_C( 112),  INT8_C(  70) },
      UINT16_C(26183),
      {  INT8_C(   4),  INT8_C(  23),  INT8_C( 113), -INT8_C(  53),  INT8_C(  90), -INT8_C( 119),  INT8_C(  13), -INT8_C(  51),
        -INT8_C(  73),  INT8_C(  22),  INT8_C(  50), -INT8_C(  59),  INT8_C(  12),  INT8_C(  49),  INT8_C(  42),  INT8_C(  13) },
      { -INT64_C( 3800570320045262497), -INT64_C( 8527823707323875375) },
      { -INT8_C( 107),  INT8_C(  67), -INT8_C(  96),  INT8_C(  45),  INT8_C(  14), -INT8_C(  62),  INT8_C( 121),  INT8_C(  53),
        -INT8_C(  39),  INT8_C(   7),  INT8_C( 105),  INT8_C(  40), -INT8_C(   3), -INT8_C(  45), -INT8_C(  59),  INT8_C(  70) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i src = simde_x_mm_loadu_epi8(test_vec[i].src);
    simde__m128i a = simde_x_mm_loadu_epi64(test_vec[i].a);
    simde__m128i b = simde_x_mm_loadu_epi8(test_vec[i].b);
    simde__m128i r = simde_mm_mask_multishift_epi64_epi8(src, test_vec[i].k, a, b);
    simde_test_x86_assert_equal_i8x16(r, simde_x_mm_loadu_epi8(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m128i src = simde_test_x86_random_i8x16();
    simde__mmask16 k = simde_test_x86_random_mmask16();
    simde__m128i a = simde_test_x86_random_i8x16();
    simde__m128i b = simde_test_x86_random_i64x2();
    simde__m128i r = simde_mm_mask_multishift_epi64_epi8(src, k, a, b);

    simde_test_x86_write_i8x16(2, src, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_mmask16(2, k, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i8x16(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i64x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i8x16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_maskz_multishift_epi64_epi8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask16 k;
    const int8_t a[16];
    const int64_t b[2];
    const int8_t r[16];
  } test_vec[] = {
    { UINT16_C( 6444),
      {  INT8_C(  85), -INT8_C( 122), -INT8_C(  94),  INT8_C(  98),  INT8_C(  84),  INT8_C(  90),  INT8_C( 121), -INT8_C( 122),
         INT8_C(  31), -INT8_C( 123), -INT8_C(  73),  INT8_C(  73), -INT8_C( 110),  INT8_C(  22), -INT8_C( 126),  INT8_C(  98) },
      { -INT64_C( 8450761998717947592),  INT64_C( 2080042661772737821) },
      {  INT8_C(   0),  INT8_C(   0),  INT8_C(  47),  INT8_C(  47),  INT8_C(   0),  INT8_C(  30),  INT8_C(   0),  INT8_C(   0),
        -INT8_C( 113),  INT8_C(   0),  INT8_C(   0), -INT8_C(  98),  INT8_C(  39),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0) } },
    { UINT16_C(32850),
      {  INT8_C( 126), -INT8_C(  90), -INT8_C(  38), -INT8_C(   9),  INT8_C(  44), -INT8_C(   7),  INT8_C( 124), -INT8_C(  29),
         INT8_C(  66),  INT8_C(  15), -INT8_C(   6), -INT8_C(  59),  INT8_C( 113),  INT8_C(  50), -INT8_C(  74),  INT8_C( 124) },
      { -INT64_C( 7232369799704579413),  INT64_C(  258878381064874041) },
      {  INT8_C(   0), -INT8_C(  41),  INT8_C(   0),  INT8_C(   0),  INT8_C(  23),  INT8_C(   0), -INT8_C(  71),  INT8_C(   0),
         INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C( 112) } },
    { UINT16_C(29022),
      { -INT8_C(   6), -INT8_C( 118),  INT8_C( 106),  INT8_C( 119),  INT8_C( 110), -INT8_C(  84), -INT8_C( 122),  INT8_C( 104),
         INT8_C( 113), -INT8_C(   9), -INT8_C( 102),  INT8_C(  39),  INT8_C( 115),  INT8_C(  69), -INT8_C( 103), -INT8_C(  53) },
      { -INT64_C( 7515530104823310935),  INT64_C( 3862028249556007056) },
      {  INT8_C(   0),  INT8_C(  37), -INT8_C(  34),  INT8_C(  47), -INT8_C(  51),  INT8_C(   0),  INT8_C(  86),  INT8_C(   0),
        -INT8_C(  52),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(  77), -INT8_C(  60), -INT8_C( 109),  INT8_C(   0) } },
    { UINT16_C(  568),
      { -INT8_C(  84), -INT8_C(  90), -INT8_C(  81),  INT8_C(  50),  INT8_C(  14),  INT8_C(  32),  INT8_C(  41), -INT8_C(  88),
         INT8_C(  72), -INT8_C( 100), -INT8_C(  18), -INT8_C(  31),  INT8_C( 103), -INT8_C( 105),  INT8_C( 119), -INT8_C(  89) },
      { -INT64_C( 8156386992756512798), -INT64_C( 1480430565961496103) },
      {  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(  77), -INT8_C( 122),  INT8_C(  62),  INT8_C(   0),  INT8_C(   0),
         INT8_C(   0), -INT8_C(  25),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0) } },
    { UINT16_C( 8987),
      {  INT8_C(  29),  INT8_C(  41),  INT8_C(  67),  INT8_C(  71), -INT8_C(  46), -INT8_C( 117), -INT8_C(  29), -INT8_C(  64),
         INT8_C( 109),  INT8_C(  75),  INT8_C(  87), -INT8_C(  28), -INT8_C(  14),  INT8_C(  58), -INT8_C( 117),  INT8_C(  19) },
      { -INT64_C( 7735039731527464240), -INT64_C( 1250272468090166001) },
      { -INT8_C(  60), -INT8_C(  49),  INT8_C(   0), -INT8_C( 107), -INT8_C(  79),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
         INT8_C(  49),  INT8_C(  28),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   5),  INT8_C(   0),  INT8_C(   0) } },
    { UINT16_C(59981),
      {  INT8_C(  53),  INT8_C(  31),  INT8_C( 117),  INT8_C(  24), -INT8_C(  33), -INT8_C(  30),  INT8_C(  99),  INT8_C(  54),
        -INT8_C(  58),  INT8_C(  86),  INT8_C( 112),  INT8_C(  82),  INT8_C( 105),  INT8_C(  64),  INT8_C(  28),  INT8_C(  46) },
      {  INT64_C( 1183281256277505246),  INT64_C( 6841109847173512031) },
      { -INT8_C( 125),  INT8_C(   0), -INT8_C( 125), -INT8_C( 123),  INT8_C(   0),  INT8_C(   0), -INT8_C( 127),  INT8_C(   0),
         INT8_C(   0),  INT8_C(  24),  INT8_C(   0), -INT8_C( 115),  INT8_C(   0),  INT8_C(  95), -INT8_C( 112), -INT8_C(  62) } },
    { UINT16_C(26016),
      {  INT8_C( 119),      INT8_MAX,  INT8_C(  72), -INT8_C(  38), -INT8_C(  75),  INT8_C(  14),  INT8_C(  48),  INT8_C(  38),
         INT8_C(  96), -INT8_C( 102),  INT8_C( 102),  INT8_C( 124), -INT8_C(  56),  INT8_C(  69), -INT8_C(  16), -INT8_C( 107) },
      {  INT64_C( 4427548646651853002),  INT64_C( 8082939858097445590) },
      {  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(  57),  INT8_C(   0),  INT8_C(  64),
        -INT8_C(   7),  INT8_C(   0),  INT8_C( 123),  INT8_C(   0),  INT8_C(   0), -INT8_C(  42),  INT8_C(  44),  INT8_C(   0) } },
    { UINT16_C(29917),
      {  INT8_C(  74), -INT8_C( 110), -INT8_C( 126),  INT8_C( 123), -INT8_C(  72), -INT8_C(  29),  INT8_C(  21),  INT8_C(  31),
         INT8_C(  95), -INT8_C(  35),  INT8_C( 100),  INT8_C(  80),  INT8_C( 114),  INT8_C(  46),  INT8_C(  72), -INT8_C(  29) },
      {  INT64_C( 5507773215372759396),  INT64_C( 2590000624605751377) },
      {  INT8_C(  20),  INT8_C(   0),  INT8_C(  89), -INT8_C( 119),  INT8_C(  76),  INT8_C(   0), -INT8_C(  83),  INT8_C(  29),
         INT8_C(   0),  INT8_C(   0),  INT8_C( 125),  INT8_C(   0), -INT8_C(   4), -INT8_C(  58),  INT8_C( 104),  INT8_C(   0) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i a = simde_x_mm_loadu_epi8(test_vec[i].a);
    simde__m128i b = simde_x_mm_loadu_epi64(test_vec[i].b);
    simde__m128i r = simde_mm_maskz_multishift_epi64_epi8(test_vec[i].k, a, b);
    simde_test_x86_assert_equal_i8x16(r, simde_x_mm_loadu_epi8(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__mmask16 k = simde_test_x86_random_mmask16();
    simde__m128i a = simde_test_x86_random_i8x16();
    simde__m128i b = simde_test_x86_random_i64x2();
    simde__m128i r = simde_mm_maskz_multishift_epi64_epi8(k, a, b);

    simde_test_x86_write_mmask16(2, k, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i8x16(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i64x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i8x16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm256_multishift_epi64_epi8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int8_t a[32];
    const int64_t b[4];
    const int8_t r[32];
  } test_vec[] = {
    { { -INT8_C(  68), -INT8_C( 115), -INT8_C(  73), -INT8_C(  23),  INT8_C(  37),  INT8_C(  12), -INT8_C(  30),  INT8_C(   2),
        -INT8_C(  29),  INT8_C(   3),  INT8_C(  19),  INT8_C( 102), -INT8_C(  25),  INT8_C(  91),  INT8_C(  28),  INT8_C(  37),
         INT8_C(  10),  INT8_C(  97), -INT8_C( 116), -INT8_C(  12), -INT8_C(  83),  INT8_C(  35),  INT8_C(  11), -INT8_C(  36),
         INT8_C(   2), -INT8_C( 101), -INT8_C( 110), -INT8_C(  43),  INT8_C(  79),  INT8_C(  34), -INT8_C(  55),  INT8_C(  11) },
      {  INT64_C( 8131203552597278895),  INT64_C( 5829613153391405786), -INT64_C( 7503753902756171181),  INT64_C( 4630886314205343722) },
      { -INT8_C(   9), -INT8_C(  92), -INT8_C(  31), -INT8_C(  21), -INT8_C(  76),  INT8_C(  72), -INT8_C(  93),  INT8_C(  43),
         INT8_C(  72),  INT8_C(  91),  INT8_C(  58), -INT8_C(  55), -INT8_C(  28), -INT8_C(  40),  INT8_C( 108), -INT8_C( 110),
         INT8_C(  28), -INT8_C(  54),  INT8_C(  71),  INT8_C( 125), -INT8_C(  22), -INT8_C(  14), -INT8_C( 114),  INT8_C(  80),
        -INT8_C(   6),  INT8_C(  39),  INT8_C(  91), -INT8_C(  53), -INT8_C(  38), -INT8_C(  92), -INT8_C(  73), -INT8_C(  83) } },
    { { -INT8_C(  73),  INT8_C(  56),  INT8_C(  21),  INT8_C(  67),  INT8_C(  15), -INT8_C(  20), -INT8_C(  77), -INT8_C(  23),
        -INT8_C(  42), -INT8_C( 119), -INT8_C(  86),  INT8_C(  28),  INT8_C( 123), -INT8_C( 112),  INT8_C( 108), -INT8_C(  50),
         INT8_C(   2), -INT8_C(  80), -INT8_C(  49), -INT8_C( 105), -INT8_C(   1), -INT8_C(  84),  INT8_C(  47), -INT8_C(  22),
         INT8_C(  27), -INT8_C( 100),  INT8_C(  35), -INT8_C(  84), -INT8_C(  46),  INT8_C( 104), -INT8_C(  20), -INT8_C( 119) },
      { -INT64_C( 4280529687470603872), -INT64_C( 3146804673040596470), -INT64_C( 1520075031601994755),  INT64_C( 1410614534595807799) },
      { -INT8_C( 119), -INT8_C(  60),  INT8_C( 126),  INT8_C(  52), -INT8_C( 102), -INT8_C( 120), -INT8_C( 109),  INT8_C(  64),
         INT8_C(  23),  INT8_C(  33),  INT8_C(  19),  INT8_C(  40),  INT8_C(  90), -INT8_C(  32),  INT8_C(  68), -INT8_C( 127),
        -INT8_C(   1), -INT8_C(  25), -INT8_C(  40), -INT8_C(   6), -INT8_C(   5),  INT8_C( 121), -INT8_C(  49), -INT8_C(  26),
         INT8_C(  65),  INT8_C(  32),  INT8_C(  78),  INT8_C(  56),  INT8_C( 101), -INT8_C( 126),  INT8_C(  56),  INT8_C(   5) } },
    { { -INT8_C( 124),  INT8_C(  96), -INT8_C(  62),  INT8_C( 113), -INT8_C(  32),  INT8_C(  91),  INT8_C(  53), -INT8_C(  22),
        -INT8_C(  99),  INT8_C(  22),  INT8_C( 112),  INT8_C( 112),  INT8_C(  99), -INT8_C(  60),  INT8_C(  68),  INT8_C(  96),
        -INT8_C(  25), -INT8_C(  80),  INT8_C(  93), -INT8_C(  74),  INT8_C(  75),  INT8_C(  68), -INT8_C(  96), -INT8_C( 126),
         INT8_C(  79),  INT8_C(  54), -INT8_C( 116), -INT8_C(  63), -INT8_C(  72),  INT8_C(  31), -INT8_C(  44),  INT8_C(  60) },
      { -INT64_C( 8121428347882399873),  INT64_C( 7331091077945867001), -INT64_C( 5853910547856418060), -INT64_C( 1376337398330339599) },
      {  INT8_C( 119), -INT8_C(  14), -INT8_C(  33), -INT8_C(  91), -INT8_C(  14),  INT8_C(  75),  INT8_C( 122), -INT8_C(  72),
        -INT8_C(  14),  INT8_C( 115), -INT8_C(  67), -INT8_C(  67), -INT8_C( 113), -INT8_C(  81), -INT8_C(  81),  INT8_C( 126),
         INT8_C( 118), -INT8_C(  62), -INT8_C(   6), -INT8_C(  69),  INT8_C(  99), -INT8_C(  81),  INT8_C(  95), -INT8_C(  67),
        -INT8_C(  34), -INT8_C(  77), -INT8_C(  12),  INT8_C( 120), -INT8_C(  20), -INT8_C(  37), -INT8_C( 106),  INT8_C(  30) } },
    { { -INT8_C(  37), -INT8_C( 108),  INT8_C(  76), -INT8_C(  51),  INT8_C( 119), -INT8_C( 106),  INT8_C(  92),  INT8_C( 113),
         INT8_C(  80),  INT8_C(  92), -INT8_C(  51), -INT8_C(  50), -INT8_C(  96), -INT8_C( 118),  INT8_C(  51), -INT8_C( 108),
        -INT8_C(  91),  INT8_C(  78), -INT8_C(  44),  INT8_C(   4),  INT8_C(   9), -INT8_C( 105), -INT8_C(  78), -INT8_C(   6),
        -INT8_C(  27),  INT8_C(  33), -INT8_C(  93),  INT8_C(  83),  INT8_C( 101), -INT8_C( 119),  INT8_C(  63),  INT8_C(  64) },
      {  INT64_C( 8144313668613278493),  INT64_C(  286667276059399110),  INT64_C( 5459411024413708224),  INT64_C( 1045080237007595482) },
      {  INT8_C(  50),  INT8_C(  80), -INT8_C(  40),  INT8_C( 108), -INT8_C(  30),  INT8_C(  84),  INT8_C(  25), -INT8_C( 125),
         INT8_C(  63), -INT8_C(  26), -INT8_C(   2), -INT8_C(   1),  INT8_C(  94), -INT8_C(  12),      INT8_MAX,  INT8_C(  99),
        -INT8_C(  53),  INT8_C(  31), -INT8_C( 112), -INT8_C(   4), -INT8_C(  25), -INT8_C( 110), -INT8_C(  16),  INT8_C(  18),
        -INT8_C(   9),  INT8_C( 120), -INT8_C(  34),  INT8_C(  19), -INT8_C(   9),  INT8_C(  51), -INT8_C(  76), -INT8_C(  38) } },
    { {  INT8_C( 105), -INT8_C( 114), -INT8_C(  93), -INT8_C( 117), -INT8_C(   8), -INT8_C(  87), -INT8_C(   4), -INT8_C(  66),
         INT8_C( 124),  INT8_C(  60),  INT8_C(  36), -INT8_C(  38), -INT8_C(  82),  INT8_C(  30), -INT8_C(  35),  INT8_C( 111),
        -INT8_C(  19), -INT8_C(  28),  INT8_C(  56),  INT8_C(  83), -INT8_C(  99), -INT8_C(   4), -INT8_C(  97),  INT8_C( 120),
         INT8_C(  99),  INT8_C(  61), -INT8_C(  72),  INT8_C(  83),  INT8_C(  27),  INT8_C(  56),  INT8_C(  97), -INT8_C( 123) },
      {  INT64_C( 3061335787062691014), -INT64_C( 6023878137450553272), -INT64_C(  154072801785897274), -INT64_C( 7818896784636144420) },
      {  INT8_C(   6),  INT8_C(  64), -INT8_C( 107),  INT8_C(   0),  INT8_C(  42),  INT8_C(   6),  INT8_C(  98),  INT8_C(  24),
        -INT8_C( 118), -INT8_C( 118),  INT8_C(  43), -INT8_C(   3), -INT8_C( 101), -INT8_C(   1), -INT8_C(   1), -INT8_C(  51),
        -INT8_C(  28), -INT8_C(   7), -INT8_C(   3),      INT8_MIN, -INT8_C(  45),  INT8_C( 111),  INT8_C(  52), -INT8_C(   3),
         INT8_C(  89), -INT8_C(  28), -INT8_C( 109),  INT8_C(  10), -INT8_C(  97), -INT8_C( 109),  INT8_C( 102), -INT8_C(  90) } },
    { { -INT8_C(  73), -INT8_C( 115),  INT8_C(  81),  INT8_C( 100), -INT8_C( 103), -INT8_C(  50), -INT8_C( 114), -INT8_C(  30),
         INT8_C( 110), -INT8_C( 109), -INT8_C(  39),  INT8_C(  45),  INT8_C( 117),  INT8_C(  63), -INT8_C(  38),  INT8_C(  59),
        -INT8_C(  35), -INT8_C(  38), -INT8_C(  97),  INT8_C( 120),  INT8_C( 121),  INT8_C( 123),  INT8_C( 117),  INT8_C(  85),
         INT8_C(  15), -INT8_C(  58),  INT8_C(  77), -INT8_C(  36),  INT8_C( 121), -INT8_C(  54),  INT8_C( 111),  INT8_C(  48) },
      { -INT64_C(  156742465182449577), -INT64_C( 4006509410411434826), -INT64_C( 7949497100608207138),  INT64_C( 2028269949984569980) },
      { -INT8_C(   5), -INT8_C(  90), -INT8_C(  54),  INT8_C(  56),  INT8_C( 120),  INT8_C(  83),  INT8_C(  83), -INT8_C(  29),
        -INT8_C( 104),  INT8_C( 101), -INT8_C( 107),  INT8_C(  48),  INT8_C(  67),  INT8_C( 109), -INT8_C(  54), -INT8_C(  39),
         INT8_C(  10),  INT8_C(  85),  INT8_C(   2), -INT8_C( 111),  INT8_C(  72), -INT8_C(  46), -INT8_C( 115), -INT8_C(  70),
        -INT8_C(  37), -INT8_C(  23),  INT8_C( 111),  INT8_C(  95),  INT8_C(  14),  INT8_C( 126),  INT8_C(  75),  INT8_C(  37) } },
    { { -INT8_C( 100), -INT8_C(  70),  INT8_C(  13),  INT8_C(  43), -INT8_C(  35), -INT8_C(  32),  INT8_C(  40), -INT8_C( 109),
        -INT8_C( 116),  INT8_C(  82), -INT8_C(  66),  INT8_C( 119),  INT8_C(  87),  INT8_C(  36),  INT8_C(  64),  INT8_C(  53),
         INT8_C(  42),      INT8_MIN, -INT8_C( 115), -INT8_C(  84),  INT8_C(  54),  INT8_C(  58),  INT8_C(  61), -INT8_C(  77),
         INT8_C(  52), -INT8_C(  86), -INT8_C(  88), -INT8_C(   7), -INT8_C( 122), -INT8_C(  50),  INT8_C(  22),  INT8_C(  34) },
      { -INT64_C( 8000516076283812984),  INT64_C(  384011969894069960),  INT64_C( 5814971872910107080), -INT64_C( 5746488498613298536) },
      {  INT8_C(  70),  INT8_C(  36),  INT8_C( 105),  INT8_C(  14),  INT8_C(  35),  INT8_C(   4),  INT8_C( 117), -INT8_C(  87),
        -INT8_C( 117), -INT8_C(  62),  INT8_C(  32),  INT8_C(  10),  INT8_C(  62), -INT8_C( 115), -INT8_C(  56),  INT8_C(  42),
        -INT8_C(  69), -INT8_C(  56), -INT8_C( 113),  INT8_C(  46),  INT8_C(  66),  INT8_C(  20),  INT8_C(  66),  INT8_C(  22),
         INT8_C(   4),  INT8_C(  23),  INT8_C(  95),  INT8_C(  88),  INT8_C( 106),  INT8_C(  37),  INT8_C( 121), -INT8_C(  54) } },
    { { -INT8_C( 125), -INT8_C( 114),  INT8_C(  21), -INT8_C( 121),  INT8_C(   3),  INT8_C(  13),  INT8_C(  23), -INT8_C(  53),
        -INT8_C(  61),  INT8_C(  31), -INT8_C(  22), -INT8_C(  98),  INT8_C( 103),  INT8_C(  63), -INT8_C(  93),  INT8_C(  48),
         INT8_C(  32),  INT8_C(  84),  INT8_C(  47),  INT8_C(  60),  INT8_C(  66), -INT8_C(  31), -INT8_C( 116), -INT8_C(  38),
         INT8_C(  59), -INT8_C(  43), -INT8_C(   8),  INT8_C( 100),  INT8_C(  53),  INT8_C(  56),  INT8_C(  20), -INT8_C(  72) },
      { -INT64_C(  318253401043424570), -INT64_C( 2374174633800138634),  INT64_C( 6461723311890709648), -INT64_C( 6671289152174185347) },
      {  INT8_C(  88), -INT8_C(   4),  INT8_C(  81),  INT8_C(  85),  INT8_C(  88), -INT8_C(   7), -INT8_C( 108), -INT8_C(  27),
         INT8_C(  14),      INT8_MAX,  INT8_C(  79), -INT8_C(   1),  INT8_C( 121), -INT8_C(  19), -INT8_C( 105),  INT8_C(  13),
         INT8_C(  29),  INT8_C(  33),  INT8_C(  89),  INT8_C(   5),  INT8_C(  36), -INT8_C( 114), -INT8_C(  77),  INT8_C( 116),
        -INT8_C(  76), -INT8_C( 107), -INT8_C(  93),  INT8_C(  29),  INT8_C(  27), -INT8_C(  93),  INT8_C(  43), -INT8_C(  93) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m256i a = simde_x_mm256_loadu_epi8(test_vec[i].a);
    simde__m256i b = simde_x_mm256_loadu_epi64(test_vec[i].b);
    simde__m256i r = simde_mm256_multishift_epi64_epi8(a, b);
    simde_test_x86_assert_equal_i8x32(r, simde_x_mm256_loadu_epi8(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m256i a = simde_test_x86_random_i8x32();
    simde__m256i b = simde_test_x86_random_i64x4();
    simde__m256i r = simde_mm256_multishift_epi64_epi8(a, b);

    simde_test_x86_write_i8x32(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i64x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i8x32(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm256_mask_multishift_epi64_epi8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int8_t src[32];
    const simde__mmask32 k;
    const int8_t a[32];
    const int64_t b[4];
    const int8_t r[32];
  } test_vec[] = {
    { { -INT8_C(   5), -INT8_C(  87),  INT8_C( 109),  INT8_C(  51), -INT8_C(   1),  INT8_C(   2),  INT8_C(  46),  INT8_C( 117),
        -INT8_C( 126), -INT8_C(  57),  INT8_C(  83),  INT8_C(  65),  INT8_C(   3),  INT8_C(  96),  INT8_C(  33), -INT8_C( 109),
        -INT8_C(  99),  INT8_C(  60),  INT8_C( 101), -INT8_C(  70), -INT8_C(  28),  INT8_C(  17),  INT8_C(  19),  INT8_C(  97),
        -INT8_C(  75), -INT8_C(  48),  INT8_C(  19), -INT8_C( 111), -INT8_C(  94),  INT8_C( 125),  INT8_C(  52), -INT8_C(  99) },
      UINT32_C( 634429734),
      { -INT8_C(  92), -INT8_C(   2), -INT8_C( 101),  INT8_C(  38), -INT8_C(  59), -INT8_C(  18),  INT8_C( 104), -INT8_C(  56),
         INT8_C(  78), -INT8_C( 119),  INT8_C(  91), -INT8_C(  21), -INT8_C(  59), -INT8_C(  64), -INT8_C(  90), -INT8_C(  87),
        -INT8_C(  47), -INT8_C(  71),  INT8_C(  10), -INT8_C( 122), -INT8_C( 118),  INT8_C(  29),  INT8_C(  24),  INT8_C(  44),
        -INT8_C( 102),  INT8_C(  76), -INT8_C(  55), -INT8_C(  64), -INT8_C(  18), -INT8_C( 102), -INT8_C(  26), -INT8_C( 110) },
      { -INT64_C( 4817127088723557992),  INT64_C( 1447994426959430313), -INT64_C( 2612454743421082872), -INT64_C( 5008142273597437697) },
      { -INT8_C(   5),  INT8_C(  98), -INT8_C(  21),  INT8_C(  51), -INT8_C(   1), -INT8_C( 104),  INT8_C(  46),  INT8_C( 117),
        -INT8_C(  90), -INT8_C(  57),  INT8_C(  83),  INT8_C(  65),  INT8_C(   3), -INT8_C(  87),  INT8_C(  33),  INT8_C(  39),
        -INT8_C(  99),  INT8_C(  60),  INT8_C( 101), -INT8_C(  70), -INT8_C( 120),  INT8_C(  17), -INT8_C( 110), -INT8_C(  21),
        -INT8_C(  69), -INT8_C(  48), -INT8_C(  60), -INT8_C( 111), -INT8_C(  94), -INT8_C(  69),  INT8_C(  52), -INT8_C(  99) } },
    { {  INT8_C(   2),  INT8_C(  55),  INT8_C(  24),  INT8_C( 113),  INT8_C(  88),  INT8_C(  63),  INT8_C(  47),  INT8_C(   1),
        -INT8_C(  63), -INT8_C(  40),  INT8_C( 112),  INT8_C(   3),  INT8_C(  39), -INT8_C( 119),  INT8_C(  23),  INT8_C(  47),
        -INT8_C(  84), -INT8_C(  78), -INT8_C(  62), -INT8_C(  20),  INT8_C( 100),      INT8_MIN, -INT8_C(  57),  INT8_C(  99),
         INT8_C(   8),  INT8_C(  99),  INT8_C(  80),  INT8_C(  42), -INT8_C(  28), -INT8_C(  49), -INT8_C(  27), -INT8_C(  25) },
      UINT32_C(1599667463),
      {  INT8_C(  60), -INT8_C( 121),  INT8_C(  96), -INT8_C(   3),  INT8_C(  95), -INT8_C(  47),  INT8_C(   1), -INT8_C( 122),
         INT8_C(  90),  INT8_C(  24), -INT8_C(  74),  INT8_C(   6), -INT8_C(  54),  INT8_C( 120), -INT8_C(  14),  INT8_C(  47),
        -INT8_C(   8), -INT8_C(  70), -INT8_C( 110),  INT8_C(   1),  INT8_C(  29), -INT8_C(  29),  INT8_C(  43),  INT8_C(   1),
        -INT8_C(  78),  INT8_C(  16), -INT8_C(  24), -INT8_C(  71),  INT8_C(  14),  INT8_C(  65),  INT8_C(  24),  INT8_C(  74) },
      { -INT64_C( 6580241422689470008), -INT64_C( 3072689851294129055), -INT64_C( 8974264687657554602),  INT64_C( 7451862671071927570) },
      { -INT8_C( 118), -INT8_C(  13),  INT8_C(  74),  INT8_C( 113),  INT8_C(  88),  INT8_C(  63),  INT8_C(  47),  INT8_C(   1),
         INT8_C(  11), -INT8_C(  40),  INT8_C(  85), -INT8_C( 111), -INT8_C( 103), -INT8_C(  43),  INT8_C(  86), -INT8_C(  73),
        -INT8_C(  84), -INT8_C(  78), -INT8_C(  62), -INT8_C(  85), -INT8_C( 125),      INT8_MIN, -INT8_C(  96),  INT8_C(  99),
        -INT8_C(  38),  INT8_C(  60),  INT8_C(  85),  INT8_C(  51), -INT8_C(  15), -INT8_C(  49),  INT8_C(  32), -INT8_C(  25) } },
    { { -INT8_C(  50), -INT8_C(  78), -INT8_C( 113),  INT8_C(  24), -INT8_C(   5),  INT8_C(  61), -INT8_C(  68),  INT8_C(  93),
        -INT8_C(  94),  INT8_C( 102), -INT8_C( 119),  INT8_C( 126),  INT8_C(   2), -INT8_C(  28),  INT8_C(  83),  INT8_C(  89),
        -INT8_C(  47),  INT8_C(  41), -INT8_C(  52), -INT8_C(  94),  INT8_C(  43),  INT8_C(  65),  INT8_C(  37),  INT8_C(  61),
        -INT8_C(  97),  INT8_C(  97),  INT8_C(  93),  INT8_C(  61), -INT8_C(  74), -INT8_C(  57), -INT8_C(  92), -INT8_C( 124) },
      UINT32_C(1973171066),
      {  INT8_C( 113),  INT8_C(  88), -INT8_C(  46),  INT8_C(  19), -INT8_C(  66),  INT8_C(  91), -INT8_C( 111), -INT8_C(  63),
         INT8_C(  63), -INT8_C(  27),  INT8_C(  26),  INT8_C(  17),  INT8_C(  14), -INT8_C(  26), -INT8_C(  77),  INT8_C(  57),
         INT8_C(  40), -INT8_C(  40),  INT8_C( 118), -INT8_C(  57),  INT8_C(  57), -INT8_C(  45),  INT8_C(   4), -INT8_C(  16),
        -INT8_C( 101), -INT8_C(  87),  INT8_C( 116),  INT8_C(  21), -INT8_C(  36),  INT8_C(  17), -INT8_C( 118),  INT8_C(  77) },
      { -INT64_C(  510610209964532375),  INT64_C( 1233912535678780375),  INT64_C(  341672593244853652), -INT64_C( 6003118793480916346) },
      { -INT8_C(  50),  INT8_C(  40), -INT8_C( 113),  INT8_C(  12), -INT8_C(  89),  INT8_C(   5),  INT8_C(  48),  INT8_C(  93),
        -INT8_C(  82), -INT8_C(  25), -INT8_C( 119),  INT8_C( 126),  INT8_C(  36), -INT8_C(  13),  INT8_C(  83),  INT8_C(  89),
        -INT8_C(  47),  INT8_C(  41),  INT8_C(  18),  INT8_C(  43),  INT8_C(   2),  INT8_C(  65),  INT8_C(  37), -INT8_C(  67),
         INT8_C( 108),  INT8_C(  97), -INT8_C(  53),  INT8_C(  61),  INT8_C(  54),  INT8_C(  12),  INT8_C(  76), -INT8_C( 124) } },
    { {  INT8_C(   0),  INT8_C(  16), -INT8_C(  44), -INT8_C(  71),  INT8_C(   2), -INT8_C(  67), -INT8_C(  79), -INT8_C(  39),
        -INT8_C(  64), -INT8_C(  70), -INT8_C(  65), -INT8_C(  86),  INT8_C( 118), -INT8_C(  34), -INT8_C(  69),  INT8_C(  10),
         INT8_C( 115), -INT8_C( 108), -INT8_C(  41), -INT8_C(  36),  INT8_C( 113), -INT8_C( 107), -INT8_C(  32), -INT8_C(   9),
        -INT8_C(  57), -INT8_C(   7),  INT8_C(  89),  INT8_C(  10), -INT8_C(  99),  INT8_C(   9), -INT8_C(  74), -INT8_C(  99) },
      UINT32_C( 475433754),
      {  INT8_C(  72),  INT8_C(   7), -INT8_C(  10),  INT8_C(   9), -INT8_C(  63), -INT8_C(  75), -INT8_C(  77),  INT8_C(  55),
        -INT8_C( 109),  INT8_C( 110),  INT8_C(  65),  INT8_C(   6),  INT8_C(   2),  INT8_C(  25), -INT8_C(  29),  INT8_C( 115),
        -INT8_C(  82), -INT8_C(  61),  INT8_C( 106),  INT8_C( 117), -INT8_C(  67), -INT8_C(  60),      INT8_MAX,  INT8_C(  90),
        -INT8_C(  51),  INT8_C(  53), -INT8_C(   9), -INT8_C(  25), -INT8_C(  64),  INT8_C(  78),  INT8_C(   4),  INT8_C(   9) },
      {  INT64_C( 4777973610483743317),  INT64_C( 6316627958124023859), -INT64_C( 6555468813607103249), -INT64_C( 6824482532918166144) },
      {  INT8_C(   0), -INT8_C(  12), -INT8_C(  44),  INT8_C( 125),  INT8_C(  42), -INT8_C(  67), -INT8_C(  79), -INT8_C(  39),
        -INT8_C(  55), -INT8_C(  92), -INT8_C(  65),  INT8_C(  64),  INT8_C( 118), -INT8_C(  34), -INT8_C(  69), -INT8_C(  11),
         INT8_C( 115), -INT8_C(  99), -INT8_C( 110), -INT8_C(  36),  INT8_C( 125), -INT8_C( 107), -INT8_C(  33), -INT8_C(   9),
        -INT8_C(  57), -INT8_C(   7),  INT8_C(  66),  INT8_C(  34),      INT8_MIN,  INT8_C(   9), -INT8_C(  74), -INT8_C(  99) } },
    { { -INT8_C( 117),  INT8_C(  92), -INT8_C(  72),  INT8_C(  58),  INT8_C(  33),  INT8_C(   6),  INT8_C( 124),  INT8_C(  84),
        -INT8_C( 106), -INT8_C(  60), -INT8_C( 118),  INT8_C(  63), -INT8_C(  16),  INT8_C(  52), -INT8_C( 106), -INT8_C(  33),
         INT8_C(  72),  INT8_C(  98), -INT8_C( 117),  INT8_C(  32), -INT8_C(  83), -INT8_C( 111), -INT8_C(  59),  INT8_C(  46),
        -INT8_C( 114),  INT8_C(  82),  INT8_C( 111), -INT8_C(  38), -INT8_C(  29), -INT8_C(  71),  INT8_C( 123),  INT8_C( 110) },
      UINT32_C( 916992789),
      {  INT8_C(  57),  INT8_C(  36), -INT8_C( 118), -INT8_C(  48), -INT8_C(  23),  INT8_C(  21),  INT8_C(  15), -INT8_C(  39),
         INT8_C(  73), -INT8_C(  90), -INT8_C(  72), -INT8_C( 111),  INT8_C(   8),  INT8_C(  67), -INT8_C(  79), -INT8_C(  74),
        -INT8_C(  44),  INT8_C( 118), -INT8_C(  28),  INT8_C(  98), -INT8_C(  55),  INT8_C(  83),  INT8_C(  60), -INT8_C(  84),
         INT8_C(  12), -INT8_C(  73),  INT8_C(  27),  INT8_C(  33), -INT8_C(  22), -INT8_C(  61),  INT8_C(  87),  INT8_C(  36) },
      {  INT64_C( 4587483529049596392),  INT64_C( 8748384824836776617), -INT64_C( 6094187646331171592),  INT64_C( 3809521147260471503) },
      {  INT8_C(  31),  INT8_C(  92),  INT8_C(  56),  INT8_C(  58),  INT8_C(   1),  INT8_C(   6),  INT8_C( 124),  INT8_C(  84),
         INT8_C(  49),  INT8_C(   6), -INT8_C( 118),  INT8_C(  63),  INT8_C(  98),  INT8_C(  85), -INT8_C( 106), -INT8_C(  33),
         INT8_C(  72),  INT8_C(  98), -INT8_C( 117),  INT8_C(  39), -INT8_C(  83),  INT8_C(  59), -INT8_C(  59), -INT8_C(  47),
        -INT8_C( 114),  INT8_C( 105), -INT8_C( 105), -INT8_C(  38), -INT8_C( 120),  INT8_C(  25),  INT8_C( 123),  INT8_C( 110) } },
    { {  INT8_C(   4), -INT8_C(  46),  INT8_C(   5), -INT8_C(   5), -INT8_C(  43), -INT8_C(  81),  INT8_C(  58),      INT8_MAX,
         INT8_C(  17),  INT8_C(  11),  INT8_C(  49), -INT8_C(  74), -INT8_C( 116), -INT8_C( 103),  INT8_C(  47), -INT8_C( 124),
        -INT8_C(  27),  INT8_C(  10),  INT8_C(  69), -INT8_C( 124),  INT8_C(  34), -INT8_C(  77),  INT8_C(  47), -INT8_C(  14),
         INT8_C(  59), -INT8_C(   5), -INT8_C(  84), -INT8_C( 121),  INT8_C(  30), -INT8_C( 118), -INT8_C(  69),  INT8_C(  34) },
      UINT32_C( 824033372),
      {  INT8_C( 111),  INT8_C(  88), -INT8_C(  80),      INT8_MIN,  INT8_C(  99), -INT8_C(  31),  INT8_C(  54), -INT8_C(  17),
         INT8_C( 122),  INT8_C( 101),  INT8_C( 116),  INT8_C(  95),  INT8_C( 112), -INT8_C(  71), -INT8_C(  29), -INT8_C( 110),
         INT8_C( 108),  INT8_C(  18), -INT8_C( 124), -INT8_C(  88),  INT8_C(  13),  INT8_C(  48),  INT8_C(  47),  INT8_C(  43),
        -INT8_C(  70), -INT8_C(  21),  INT8_C(  78),  INT8_C(  22), -INT8_C(  85),  INT8_C( 107),  INT8_C(  72),  INT8_C(  27) },
      {  INT64_C( 6059262183066040515), -INT64_C( 5748115657552786889), -INT64_C( 6204966397943431510),  INT64_C( 6933582567937421682) },
      {  INT8_C(   4), -INT8_C(  46),  INT8_C(  22), -INT8_C(  61),  INT8_C(  91), -INT8_C(  81),  INT8_C(  80),      INT8_MAX,
         INT8_C(  17),  INT8_C(  11),  INT8_C(  49), -INT8_C(  74), -INT8_C( 116), -INT8_C( 103), -INT8_C(  24), -INT8_C(  19),
         INT8_C(  56),  INT8_C(  10), -INT8_C(  22), -INT8_C( 121), -INT8_C(  59), -INT8_C(  77),  INT8_C(  47), -INT8_C(  14),
        -INT8_C( 104), -INT8_C(   5), -INT8_C(  84), -INT8_C( 121),  INT8_C(  33),  INT8_C(  33), -INT8_C(  69),  INT8_C(  34) } },
    { {  INT8_C(   0), -INT8_C(  44), -INT8_C( 122), -INT8_C(  38), -INT8_C(  90), -INT8_C( 100),  INT8_C(  47), -INT8_C(  34),
         INT8_C(  38), -INT8_C(  29), -INT8_C( 123),  INT8_C( 106),  INT8_C( 122), -INT8_C(  65),  INT8_C(  26),  INT8_C(  36),
         INT8_C( 126),  INT8_C( 114), -INT8_C(  36),  INT8_C( 109), -INT8_C(   7), -INT8_C(  65),  INT8_C(  22),  INT8_C( 108),
        -INT8_C(  16), -INT8_C(  42), -INT8_C( 118), -INT8_C( 116), -INT8_C(  34), -INT8_C(  61), -INT8_C(  20), -INT8_C(  33) },
      UINT32_C(1052341143),
      {  INT8_C(  15), -INT8_C(  24),  INT8_C(  28),  INT8_C(  54), -INT8_C(  53), -INT8_C(  95), -INT8_C(  96),  INT8_C(  70),
         INT8_C(  97), -INT8_C(  70),  INT8_C( 106), -INT8_C(  33),  INT8_C(  44),  INT8_C(  70),  INT8_C(  76),  INT8_C(  37),
         INT8_C(   5),  INT8_C(  98), -INT8_C( 111), -INT8_C(  11),  INT8_C(  57),  INT8_C(  27), -INT8_C( 126),  INT8_C(  23),
        -INT8_C(  34),  INT8_C( 110), -INT8_C(  10),  INT8_C( 118), -INT8_C(  31), -INT8_C(  80), -INT8_C(  76), -INT8_C(  15) },
      { -INT64_C( 3266579289878310760),  INT64_C( 6976917342948234369),  INT64_C( 6823191478011323488), -INT64_C( 1217792316298451130) },
      {  INT8_C(  79), -INT8_C(  57),  INT8_C(  22), -INT8_C(  38), -INT8_C(   6), -INT8_C( 100),  INT8_C(  47),  INT8_C(  66),
        -INT8_C(  83),  INT8_C(  88), -INT8_C( 123),  INT8_C( 106),  INT8_C(  47),  INT8_C(  82),  INT8_C(  17),  INT8_C(  36),
         INT8_C(  35),  INT8_C( 114), -INT8_C(  36), -INT8_C(  11),  INT8_C(  47), -INT8_C(  13),  INT8_C(  22),  INT8_C(  50),
        -INT8_C(  16),  INT8_C( 102), -INT8_C(  68), -INT8_C(  68),  INT8_C(  43),  INT8_C(  25), -INT8_C(  20), -INT8_C(  33) } },
    { {  INT8_C(  88),  INT8_C(  64),  INT8_C(  83), -INT8_C(  55),  INT8_C(   7), -INT8_C(   3), -INT8_C( 100), -INT8_C( 120),
         INT8_C(  18),  INT8_C(  77),  INT8_C(  53),  INT8_C( 109),  INT8_C(  75),  INT8_C(   7), -INT8_C(  51), -INT8_C(  85),
         INT8_C( 107),  INT8_C(  35),  INT8_C(  68), -INT8_C(  21), -INT8_C(   5), -INT8_C(  12),  INT8_C(  73),  INT8_C(  66),
        -INT8_C( 101),  INT8_C(  29),  INT8_C( 106), -INT8_C(  14), -INT8_C(  91), -INT8_C( 125), -INT8_C(  30), -INT8_C(   3) },
      UINT32_C(3401987523),
      {  INT8_C(  51),  INT8_C(  98),  INT8_C(  82),  INT8_C(  69), -INT8_C(  80), -INT8_C( 121), -INT8_C(  78), -INT8_C(   5),
        -INT8_C( 114),      INT8_MAX, -INT8_C(  90), -INT8_C(   6), -INT8_C(  93), -INT8_C(  22), -INT8_C(  27), -INT8_C(  98),
        -INT8_C(  34),  INT8_C(  46), -INT8_C(  32),  INT8_C( 122),  INT8_C(  75),  INT8_C(  74),  INT8_C( 108), -INT8_C(  16),
        -INT8_C(  51),  INT8_C(  78), -INT8_C(  19), -INT8_C( 112), -INT8_C( 124), -INT8_C(  77),  INT8_C(  90), -INT8_C(  73) },
      { -INT64_C( 4413054622441362410),  INT64_C( 3418128014963926829),  INT64_C( 7424771786801762255), -INT64_C( 4566840603123845276) },
      {  INT8_C(  88), -INT8_C( 116),  INT8_C(  83), -INT8_C(  55),  INT8_C(   7), -INT8_C(   3), -INT8_C(  80), -INT8_C(  40),
        -INT8_C(  15),  INT8_C(  77), -INT8_C( 123),  INT8_C( 109),  INT8_C(  42), -INT8_C(  24), -INT8_C(  51), -INT8_C(  85),
         INT8_C( 107),  INT8_C(  40), -INT8_C( 102), -INT8_C(  21), -INT8_C(   5), -INT8_C(  12), -INT8_C(  95),  INT8_C(  10),
        -INT8_C( 101), -INT8_C(  29),  INT8_C( 106), -INT8_C(   8), -INT8_C(  91), -INT8_C( 125), -INT8_C(  70), -INT8_C( 127) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m256i src = simde_x_mm256_loadu_epi8(test_vec[i].src);
    simde__m256i a = simde_x_mm256_loadu_epi8(test_vec[i].a);
    simde__m256i b = simde_x_mm256_loadu_epi64(test_vec[i].b);
    simde__m256i r = simde_mm256_mask_multishift_epi64_epi8(src, test_vec[i].k, a, b);
    simde_test_x86_assert_equal_i8x32(r, simde_x_mm256_loadu_epi8(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m256i src = simde_test_x86_random_i8x32();
    simde__mmask32 k = simde_test_x86_random_mmask32();
    simde__m256i a = simde_test_x86_random_i8x32();
    simde__m256i b = simde_test_x86_random_i64x4();
    simde__m256i r = simde_mm256_mask_multishift_epi64_epi8(src, k, a, b);

    simde_test_x86_write_i8x32(2, src, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_mmask32(2, k, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i8x32(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i64x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i8x32(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm256_maskz_multishift_epi64_epi8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask32 k;
    const int8_t a[32];
    const int64_t b[32];
    const int8_t r[32];
  } test_vec[] = {
    { UINT32_C( 847682559),
      {  INT8_C(  73),  INT8_C(  71), -INT8_C(  12),  INT8_C( 119), -INT8_C(  82), -INT8_C(  80),  INT8_C(  71), -INT8_C(   1),
         INT8_C(  81), -INT8_C(  74),  INT8_C(  47),  INT8_C(  32),  INT8_C(   6), -INT8_C(  40),  INT8_C(  58), -INT8_C(  96),
        -INT8_C(  18),  INT8_C(  68),  INT8_C(   7),  INT8_C(  83),  INT8_C(  59), -INT8_C(   1),  INT8_C(  59), -INT8_C(  26),
         INT8_C(  82), -INT8_C(  37), -INT8_C(  90),  INT8_C(  81),  INT8_C( 118),  INT8_C(  45), -INT8_C( 125), -INT8_C(  64) },
      {  INT64_C( 8800735332689999988),  INT64_C( 1791259654175215925),  INT64_C( 3763786504135762457), -INT64_C( 8955398998634143358) },
      { -INT8_C(  68), -INT8_C(  16), -INT8_C(  94), -INT8_C(  12), -INT8_C( 119),  INT8_C(  34), -INT8_C(  16), -INT8_C(  24),
        -INT8_C(  51),  INT8_C(  99),  INT8_C(   0),  INT8_C(  42),  INT8_C(  68),  INT8_C(   0),  INT8_C(   0),  INT8_C(  42),
         INT8_C(   0),  INT8_C(  33), -INT8_C(  60),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(  97),
         INT8_C(   0), -INT8_C(  33),  INT8_C(   0),  INT8_C(   0),  INT8_C(  14), -INT8_C(  64),  INT8_C(   0),  INT8_C(   0) } },
    { UINT32_C(2846289792),
      {  INT8_C( 110), -INT8_C(  56),  INT8_C(  35), -INT8_C(  93),  INT8_C(  26), -INT8_C(  67), -INT8_C(  34),  INT8_C(  68),
        -INT8_C( 110), -INT8_C(  71),  INT8_C(  92), -INT8_C(  84), -INT8_C( 101), -INT8_C(  56),  INT8_C(   1),  INT8_C( 125),
         INT8_C( 111),  INT8_C(  60), -INT8_C(  79), -INT8_C(  15),  INT8_C(  29),  INT8_C(  54), -INT8_C(  23),  INT8_C(  44),
         INT8_C(  63), -INT8_C(  94), -INT8_C(  81), -INT8_C(  65), -INT8_C( 111),  INT8_C(  85),  INT8_C( 104), -INT8_C(   1) },
      { -INT64_C( 2631368505313555683),  INT64_C( 1104095083017787449),  INT64_C( 8723165967372256452),  INT64_C( 3394765318302317963) },
      {  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(  79),
         INT8_C(  97), -INT8_C( 121),  INT8_C(  13),  INT8_C(  40),  INT8_C(   0), -INT8_C(  40),  INT8_C(  28), -INT8_C(  56),
         INT8_C(   0),  INT8_C(  71), -INT8_C( 121),  INT8_C(   0),  INT8_C(   0), -INT8_C(  28),  INT8_C(   0), -INT8_C(  18),
         INT8_C(  22),  INT8_C(   0),  INT8_C(   0),  INT8_C(  22),  INT8_C(   0), -INT8_C(  23),  INT8_C(   0),  INT8_C(  22) } },
    { UINT32_C(1986510637),
      {  INT8_C(  63), -INT8_C(  30),  INT8_C(  81),  INT8_C( 121), -INT8_C(  70), -INT8_C(  39),  INT8_C(  78),  INT8_C(  90),
         INT8_C(  97), -INT8_C(  96),  INT8_C( 105),  INT8_C(  38), -INT8_C(  92),  INT8_C( 105),  INT8_C(   8), -INT8_C(  33),
         INT8_C(  83),  INT8_C(  22),  INT8_C(  88), -INT8_C(  34), -INT8_C(  45), -INT8_C( 111), -INT8_C(   5), -INT8_C(  27),
         INT8_C(  51),  INT8_C(  24),  INT8_C(  20),  INT8_C(  96), -INT8_C(  41),  INT8_C( 123), -INT8_C(  42),  INT8_C(  22) },
      {  INT64_C( 7094256830520436574), -INT64_C( 7421492080028361602),  INT64_C( 2188313924141013670),  INT64_C( 5510247526919205515) },
      { -INT8_C(  68),  INT8_C(   0),  INT8_C(  71),  INT8_C(  49),  INT8_C(   0),  INT8_C(  12),  INT8_C(   0),  INT8_C(   0),
         INT8_C(  35),  INT8_C(  70), -INT8_C(  56),  INT8_C(  65),  INT8_C(   4), -INT8_C(  56),  INT8_C(   0), -INT8_C( 116),
         INT8_C(  46), -INT8_C(  27),  INT8_C( 121),  INT8_C(   0),  INT8_C(   0), -INT8_C(  69), -INT8_C(  61),  INT8_C(   0),
         INT8_C(   0),  INT8_C(  98),  INT8_C(  39),  INT8_C(   0), -INT8_C(  60),  INT8_C( 105), -INT8_C( 119),  INT8_C(   0) } },
    { UINT32_C(2086930556),
      { -INT8_C(  27), -INT8_C(  41), -INT8_C(  34),  INT8_C(  99), -INT8_C(  76),  INT8_C( 102), -INT8_C( 122), -INT8_C(   6),
        -INT8_C(  10), -INT8_C( 121), -INT8_C( 109), -INT8_C( 100), -INT8_C(  31),  INT8_C(  10),  INT8_C(  21), -INT8_C(  51),
         INT8_C( 125),  INT8_C( 115), -INT8_C(  21),  INT8_C(   8), -INT8_C(  26),  INT8_C( 106),  INT8_C( 106), -INT8_C(  44),
        -INT8_C(  66), -INT8_C(  29),  INT8_C(  32),  INT8_C(  58), -INT8_C(  21), -INT8_C( 124), -INT8_C(  73), -INT8_C(  48) },
      { -INT64_C( 1005785974997478052),  INT64_C( 2733866011576999233),  INT64_C(  347507547645532952), -INT64_C( 3299179788131962245) },
      {  INT8_C(   0),  INT8_C(   0), -INT8_C(  16),  INT8_C(  95),  INT8_C(  32), -INT8_C(  21),  INT8_C(  85),  INT8_C(   0),
         INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C( 114),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
         INT8_C(   0),  INT8_C(   0),  INT8_C(  83),  INT8_C(   0),  INT8_C(   0), -INT8_C(  90), -INT8_C(  90),  INT8_C(   0),
         INT8_C(   0),  INT8_C(   0),  INT8_C( 118), -INT8_C(  12), -INT8_C(  34),  INT8_C(  39), -INT8_C(  92),  INT8_C(   0) } },
    { UINT32_C(2279762571),
      {  INT8_C(  36), -INT8_C(  20),  INT8_C( 121),  INT8_C( 102), -INT8_C( 119),  INT8_C(   8), -INT8_C( 119),  INT8_C(  49),
        -INT8_C(  83),  INT8_C( 121),  INT8_C(  86), -INT8_C(  59),  INT8_C(  84), -INT8_C( 125), -INT8_C(  61), -INT8_C( 102),
         INT8_C(  27), -INT8_C( 107), -INT8_C(  98), -INT8_C( 106), -INT8_C( 121), -INT8_C(  36), -INT8_C(   4), -INT8_C(   3),
        -INT8_C(  46),  INT8_C(  51), -INT8_C(  48),  INT8_C(  93), -INT8_C(  99), -INT8_C(  78), -INT8_C(  28), -INT8_C(  62) },
      {  INT64_C( 1394340611966393759),  INT64_C( 5627418379873201962),  INT64_C( 7328730518200366640), -INT64_C( 2993585094142032876) },
      {  INT8_C(  22), -INT8_C( 101),  INT8_C(   0), -INT8_C(  59),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(  84),
         INT8_C(   0),  INT8_C(  39),  INT8_C(   0),  INT8_C( 121),  INT8_C(   0), -INT8_C(  27), -INT8_C(  27),  INT8_C(   0),
         INT8_C(   0), -INT8_C(  65),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(  59),  INT8_C(   6), -INT8_C( 125),
        -INT8_C(  80), -INT8_C(  50), -INT8_C(  62),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   5) } },
    { UINT32_C(1778293763),
      {  INT8_C(  77),  INT8_C(  88),  INT8_C( 124),  INT8_C( 119),  INT8_C(   7),  INT8_C(  84), -INT8_C(  11),  INT8_C(  58),
        -INT8_C(  17),  INT8_C(  14), -INT8_C( 119),  INT8_C(  31), -INT8_C(  60),  INT8_C( 110), -INT8_C(  42),  INT8_C(  87),
         INT8_C(  79), -INT8_C( 117), -INT8_C(  68),  INT8_C( 100),  INT8_C(  15),  INT8_C( 126),  INT8_C(  22),  INT8_C(  70),
         INT8_C(  36), -INT8_C( 118),  INT8_C(  28),  INT8_C(  40),  INT8_C(  38),  INT8_C(  27), -INT8_C( 111),  INT8_C( 115) },
      {  INT64_C( 5959915295956668019), -INT64_C(  357674788833902867),  INT64_C( 7577716786743723731), -INT64_C( 3199769738904254977) },
      {  INT8_C(  80),  INT8_C( 122),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
         INT8_C(   0),  INT8_C(   0), -INT8_C(  97),  INT8_C(  89), -INT8_C(  18),  INT8_C(   0),  INT8_C(   0),  INT8_C( 100),
         INT8_C(   0), -INT8_C(   8),  INT8_C(  54),  INT8_C(  84), -INT8_C(  65),  INT8_C(  77), -INT8_C( 119),  INT8_C(  27),
         INT8_C(  38),  INT8_C(   0),  INT8_C(   0),  INT8_C(  34),  INT8_C(   0),  INT8_C(   4), -INT8_C(  56),  INT8_C(   0) } },
    { UINT32_C(2471395888),
      {  INT8_C(  98),  INT8_C(   3), -INT8_C(  27),  INT8_C(  79),  INT8_C(  65),  INT8_C(  86),  INT8_C(   1), -INT8_C(  19),
        -INT8_C(  98),  INT8_C(  11), -INT8_C(  24),  INT8_C( 113), -INT8_C(  47),  INT8_C(  72),  INT8_C(  84),  INT8_C(  21),
        -INT8_C(  67),  INT8_C( 125),  INT8_C( 126), -INT8_C(  67), -INT8_C(  62),  INT8_C(  15), -INT8_C(  30),  INT8_C(  35),
         INT8_C(  50),  INT8_C( 123), -INT8_C(  10),  INT8_C(  98), -INT8_C(   3),  INT8_C(  68), -INT8_C(  11),  INT8_C(  95) },
      { -INT64_C( 3497695808790209977),  INT64_C( 7179465298532196027),  INT64_C( 7131172043216658450),  INT64_C( 8852874218514476670) },
      {  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(  35),  INT8_C(  34),  INT8_C(   0),  INT8_C(   0),
         INT8_C(   0),  INT8_C(  43),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(  98),
         INT8_C(   0), -INT8_C( 109),  INT8_C(  73), -INT8_C( 109),  INT8_C(   0),  INT8_C(   0), -INT8_C(  52),  INT8_C(   0),
        -INT8_C(  74), -INT8_C(  49),  INT8_C(   0),  INT8_C(   0), -INT8_C(  13),  INT8_C(   0),  INT8_C(   0),  INT8_C( 100) } },
    { UINT32_C(3305278100),
      {  INT8_C(  58),  INT8_C( 120), -INT8_C( 107), -INT8_C(  10), -INT8_C(  42), -INT8_C(  42), -INT8_C( 126),  INT8_C( 124),
         INT8_C( 107),  INT8_C(  36), -INT8_C(  33),  INT8_C( 125),  INT8_C(  69),  INT8_C(   0),  INT8_C(  81),  INT8_C( 117),
         INT8_C(   3),  INT8_C(  73), -INT8_C(  41), -INT8_C( 127),  INT8_C(  55), -INT8_C( 101), -INT8_C(   4),  INT8_C( 105),
         INT8_C(  85), -INT8_C(  41), -INT8_C(  29), -INT8_C(  22),  INT8_C(  97), -INT8_C(  26), -INT8_C(  81), -INT8_C( 100) },
      { -INT64_C( 8813522367980354466), -INT64_C( 7857843949560230087), -INT64_C( 4954785985501869411),  INT64_C( 7342367157774524903) },
      {  INT8_C(   0),  INT8_C(   0), -INT8_C(  92),  INT8_C(   0), -INT8_C(  46),  INT8_C(   0),  INT8_C(   0), -INT8_C(  24),
         INT8_C(   0),  INT8_C(  72),  INT8_C(   0), -INT8_C(  52),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C( 105),
         INT8_C(   0), -INT8_C(  27),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
         INT8_C(  77),  INT8_C(   0),      INT8_MIN,  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(  54),  INT8_C( 116) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m256i a = simde_x_mm256_loadu_epi8(test_vec[i].a);
    simde__m256i b = simde_x_mm256_loadu_epi64(test_vec[i].b);
    simde__m256i r = simde_mm256_maskz_multishift_epi64_epi8(test_vec[i].k, a, b);
    simde_test_x86_assert_equal_i8x32(r, simde_x_mm256_loadu_epi8(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__mmask32 k = simde_test_x86_random_mmask32();
    simde__m256i a = simde_test_x86_random_i8x32();
    simde__m256i b = simde_test_x86_random_i64x4();
    simde__m256i r = simde_mm256_maskz_multishift_epi64_epi8(k, a, b);

    simde_test_x86_write_mmask32(2, k, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i8x32(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i64x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i8x32(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm512_multishift_epi64_epi8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int8_t a[64];
    const int64_t b[8];
    const int8_t r[64];
  } test_vec[] = {
    { { -INT8_C(  62), -INT8_C(  23), -INT8_C(  72), -INT8_C(  70), -INT8_C(  32), -INT8_C(  30), -INT8_C(  31),  INT8_C( 105),
        -INT8_C(  58), -INT8_C( 115), -INT8_C(  10),  INT8_C( 105),  INT8_C(  17),  INT8_C(  67), -INT8_C( 121), -INT8_C(   3),
         INT8_C(  55), -INT8_C(  75),  INT8_C(  57),  INT8_C(  30), -INT8_C(  95), -INT8_C(   5), -INT8_C(  63), -INT8_C( 127),
         INT8_C(  59),  INT8_C(   9), -INT8_C( 106),  INT8_C( 100),  INT8_C(  93), -INT8_C( 122),  INT8_C(  12),  INT8_C(  31),
         INT8_C( 111), -INT8_C(  60), -INT8_C(  38),  INT8_C(  79), -INT8_C(  90), -INT8_C(  69), -INT8_C(  72),  INT8_C( 108),
         INT8_C(  72), -INT8_C(  82), -INT8_C(  42),  INT8_C(  89), -INT8_C(  15),  INT8_C(  93),  INT8_C(  86),  INT8_C(  40),
         INT8_C(  18), -INT8_C( 112),  INT8_C(  70), -INT8_C(  76), -INT8_C( 117),  INT8_C(   8),  INT8_C(  53), -INT8_C(  58),
         INT8_C(  17), -INT8_C(  52),  INT8_C(  43),  INT8_C( 111),  INT8_C(  82),  INT8_C(  55), -INT8_C( 114), -INT8_C(  63) },
      {  INT64_C( 7714323267100633339),  INT64_C( 6093681738553615479), -INT64_C( 1009582712550795349),  INT64_C( 6565384450121672713),
         INT64_C( 7846972549697973335),  INT64_C( 8252113794140253168), -INT64_C( 3166691571682144963), -INT64_C( 5509788710315463217) },
      {  INT8_C(  62),  INT8_C( 100),  INT8_C( 107), -INT8_C(  38),  INT8_C(  35),  INT8_C(   8),  INT8_C(  17),  INT8_C( 100),
        -INT8_C( 111),  INT8_C(  47),  INT8_C(  82), -INT8_C( 115),  INT8_C(  98), -INT8_C( 114), -INT8_C(  56), -INT8_C(  70),
        -INT8_C(  29), -INT8_C( 113), -INT8_C(   8),  INT8_C( 124), -INT8_C(  17),  INT8_C( 126), -INT8_C(  43), -INT8_C(  43),
         INT8_C(  43),  INT8_C(  20),  INT8_C( 109), -INT8_C(  27), -INT8_C(   6), -INT8_C(  96),  INT8_C(   2), -INT8_C(  66),
        -INT8_C(  52), -INT8_C(  59),  INT8_C(  94), -INT8_C(   6),  INT8_C(  47), -INT8_C(  19),  INT8_C( 108),  INT8_C(  96),
        -INT8_C(  85),  INT8_C(  21), -INT8_C(  57),  INT8_C(  24),  INT8_C(  66),  INT8_C(  49), -INT8_C(  57),  INT8_C( 101),
         INT8_C(  42), -INT8_C(  87),  INT8_C(  52),  INT8_C(  64),  INT8_C(  49), -INT8_C( 115), -INT8_C(  96),  INT8_C(  52),
         INT8_C(  24),  INT8_C(   6),  INT8_C(  41),  INT8_C(  18), -INT8_C( 116),  INT8_C( 103), -INT8_C(  63), -INT8_C(  25) } },
    { {  INT8_C( 121), -INT8_C( 122),  INT8_C(  45),  INT8_C( 110), -INT8_C( 110),  INT8_C(  19), -INT8_C(  38), -INT8_C( 126),
        -INT8_C(  66), -INT8_C(  82), -INT8_C(  77), -INT8_C( 123),  INT8_C(  20),  INT8_C(  57), -INT8_C(   9),  INT8_C(  81),
        -INT8_C(  58), -INT8_C(  96),  INT8_C( 109), -INT8_C( 111),  INT8_C(  70),  INT8_C( 123),  INT8_C( 102),  INT8_C(  21),
        -INT8_C(  24), -INT8_C( 106),  INT8_C(  68),  INT8_C(  68), -INT8_C(  30), -INT8_C(  51), -INT8_C(   9),  INT8_C(  91),
         INT8_C(  84),  INT8_C(  37), -INT8_C(  55), -INT8_C(  26),  INT8_C(  56), -INT8_C(  93),  INT8_C( 104), -INT8_C(   9),
         INT8_C(  82),  INT8_C(  27),  INT8_C( 124),  INT8_C( 102),  INT8_C(  84),  INT8_C( 115), -INT8_C(  73),  INT8_C(  27),
         INT8_C(  19),  INT8_C(  36), -INT8_C(  84),  INT8_C(  89), -INT8_C(  97),  INT8_C(  18),  INT8_C( 111), -INT8_C( 120),
        -INT8_C(  88), -INT8_C(  77), -INT8_C(  52), -INT8_C( 117),      INT8_MIN, -INT8_C(  60), -INT8_C(  26), -INT8_C(  44) },
      { -INT64_C( 6550447917566873367),  INT64_C( 1922405953727861822),  INT64_C( 1517400179722181351), -INT64_C( 8580616647186785386),
         INT64_C(  445789054708589878), -INT64_C( 1983757581828998314),  INT64_C( 7287239602235763872),  INT64_C( 9113991833934676308) },
      { -INT8_C(  46), -INT8_C(  61), -INT8_C(  63),  INT8_C(  96),  INT8_C( 110),  INT8_C(  55), -INT8_C(  56),  INT8_C(  58),
        -INT8_C(   8), -INT8_C(  73),  INT8_C(  85), -INT8_C(  95),  INT8_C(  32),  INT8_C(  13),  INT8_C(  53),  INT8_C(   5),
         INT8_C( 107),  INT8_C( 108),  INT8_C( 119),  INT8_C(  58),  INT8_C( 107), -INT8_C(  30), -INT8_C( 115),  INT8_C(  51),
        -INT8_C( 122),  INT8_C(  90), -INT8_C(  71), -INT8_C(  71), -INT8_C(  89),  INT8_C(   6),  INT8_C(  17), -INT8_C(  30),
        -INT8_C(  86),  INT8_C(  22), -INT8_C(  46),  INT8_C(  11),  INT8_C(   6),  INT8_C(  89), -INT8_C(  62),  INT8_C(  12),
        -INT8_C(  90), -INT8_C(  85),  INT8_C( 110),  INT8_C(  27), -INT8_C(  23), -INT8_C( 113), -INT8_C(  56), -INT8_C(  85),
        -INT8_C( 115), -INT8_C( 100),  INT8_C(  23), -INT8_C( 122), -INT8_C(  98),  INT8_C(  26),  INT8_C(  66), -INT8_C(  20),
         INT8_C( 103), -INT8_C(  49), -INT8_C(  52), -INT8_C( 104),  INT8_C(  84),  INT8_C(  21), -INT8_C(  99),  INT8_C(  55) } },
    { {  INT8_C(  12),  INT8_C(  37),  INT8_C(   8), -INT8_C(  44), -INT8_C(  25),  INT8_C(  56), -INT8_C(  38),  INT8_C(  61),
         INT8_C( 115),  INT8_C( 115), -INT8_C( 101),  INT8_C( 112), -INT8_C(  71),  INT8_C(  20),  INT8_C(  85),  INT8_C(  89),
         INT8_C(   0), -INT8_C(  64),  INT8_C( 101), -INT8_C(  48),  INT8_C(  57), -INT8_C( 121),  INT8_C(  53), -INT8_C( 114),
         INT8_C(  72), -INT8_C(  79), -INT8_C( 127), -INT8_C( 112),  INT8_C(  24), -INT8_C(   3),  INT8_C(  15),  INT8_C(  37),
         INT8_C(  34),  INT8_C(  23), -INT8_C(   7),  INT8_C(   9),  INT8_C(  79), -INT8_C(  44),  INT8_C(  70), -INT8_C(  62),
         INT8_C(  71), -INT8_C(  30),  INT8_C(  51),  INT8_C(   0), -INT8_C(  10), -INT8_C( 120),  INT8_C(  89), -INT8_C(  10),
         INT8_C(  72), -INT8_C(  66), -INT8_C(  58), -INT8_C( 127),  INT8_C(  69), -INT8_C(   4),  INT8_C(  15), -INT8_C( 114),
        -INT8_C(  83), -INT8_C( 111),  INT8_C(  30), -INT8_C(  58), -INT8_C( 114),  INT8_C(  45), -INT8_C(  21), -INT8_C(  80) },
      { -INT64_C(   47288102829824955),  INT64_C( 6543264146572413665),  INT64_C( 4533694980167537687),  INT64_C( 8915701427708627324),
         INT64_C( 6092076662622548947), -INT64_C(  405893637987398671), -INT64_C( 6963619304732936050),  INT64_C( 2593056678587490378) },
      { -INT8_C(  98), -INT8_C(   3), -INT8_C(  28),  INT8_C(  75), -INT8_C(   1), -INT8_C(   1),  INT8_C(  37),  INT8_C(  47),
         INT8_C(  89),  INT8_C(  89),  INT8_C(  90), -INT8_C(  50), -INT8_C(  83),      INT8_MAX, -INT8_C(  65),  INT8_C( 107),
         INT8_C(  23),  INT8_C(  23),  INT8_C(  92), -INT8_C(  37), -INT8_C(  97),  INT8_C(  40), -INT8_C(   9),  INT8_C( 110),
         INT8_C(   9), -INT8_C(  35), -INT8_C(  66),  INT8_C(   4),  INT8_C(  10), -INT8_C(  29),  INT8_C(   8),  INT8_C( 121),
        -INT8_C(  36),  INT8_C(  24), -INT8_C(  86),  INT8_C(  57),  INT8_C(  32), -INT8_C(  63), -INT8_C(  49), -INT8_C(  12),
         INT8_C(  23),  INT8_C( 120),  INT8_C(  75), -INT8_C(  15), -INT8_C(  23), -INT8_C( 117), -INT8_C( 127), -INT8_C(  23),
         INT8_C(  56),  INT8_C(  58), -INT8_C(  30),  INT8_C(  71), -INT8_C(  60), -INT8_C(  23), -INT8_C(  82),  INT8_C(  92),
        -INT8_C(  29), -INT8_C(  44),  INT8_C(  62), -INT8_C( 127), -INT8_C(  91), -INT8_C(  29), -INT8_C( 116), -INT8_C(   4) } },
    { { -INT8_C(  42),  INT8_C(  12), -INT8_C(  81),  INT8_C(  73),  INT8_C( 115),  INT8_C(  58), -INT8_C(  99),  INT8_C( 100),
        -INT8_C(  59), -INT8_C(  56),  INT8_C( 103), -INT8_C(  87), -INT8_C(  62), -INT8_C(  60), -INT8_C(  93),  INT8_C(  80),
        -INT8_C(   3), -INT8_C(   6),  INT8_C( 110),  INT8_C(  32),  INT8_C(  60), -INT8_C(  53), -INT8_C(  64), -INT8_C( 122),
         INT8_C(  43),  INT8_C( 105),  INT8_C(   7),  INT8_C( 123), -INT8_C(  51),  INT8_C(   4), -INT8_C(  98), -INT8_C(  93),
         INT8_C(  16),  INT8_C(  77), -INT8_C(  20), -INT8_C( 124), -INT8_C( 121), -INT8_C( 119), -INT8_C(  24),  INT8_C(  77),
         INT8_C(  82),  INT8_C(  80), -INT8_C(  10),  INT8_C(  20),  INT8_C(  20), -INT8_C( 103),  INT8_C( 100),  INT8_C(  17),
        -INT8_C( 108), -INT8_C(  46),  INT8_C(  50), -INT8_C(  48), -INT8_C(  99), -INT8_C(  14),  INT8_C(  86), -INT8_C(  55),
         INT8_C(  91),  INT8_C(  94),  INT8_C(  68),  INT8_C(  40),  INT8_C(  98), -INT8_C(  30), -INT8_C(  52),  INT8_C( 114) },
      { -INT64_C( 7781130253535627217),  INT64_C( 2834185367134468399), -INT64_C( 3151027180092815394), -INT64_C( 7313624333216282197),
        -INT64_C( 8910560610403453311), -INT64_C( 1583264807144325299), -INT64_C(  580494533554930012),  INT64_C( 4123473957527875124) },
      { -INT8_C(  37),  INT8_C( 107),  INT8_C(   7),  INT8_C(  92),      INT8_MIN, -INT8_C(  27),  INT8_C(  21), -INT8_C(  12),
        -INT8_C(  55), -INT8_C(   7),  INT8_C(  25), -INT8_C( 122),  INT8_C(  75), -INT8_C( 110), -INT8_C( 110), -INT8_C(  88),
        -INT8_C(  10), -INT8_C(  75),  INT8_C(  21),  INT8_C( 121), -INT8_C(  19), -INT8_C(  16), -INT8_C(  34),  INT8_C(  31),
         INT8_C(  25),  INT8_C( 100),  INT8_C(  19),  INT8_C( 115), -INT8_C(  20), -INT8_C( 102), -INT8_C(  84),  INT8_C(  45),
         INT8_C(  80), -INT8_C( 125),  INT8_C( 117),  INT8_C( 104), -INT8_C(  19),  INT8_C(  59),  INT8_C(  84), -INT8_C( 125),
         INT8_C(  50), -INT8_C(  56), -INT8_C(  88),  INT8_C(  12),  INT8_C(  12), -INT8_C(  16), -INT8_C(  48),  INT8_C( 100),
        -INT8_C(  42),  INT8_C(  89), -INT8_C(   4),  INT8_C( 102),  INT8_C(  96), -INT8_C(   4),  INT8_C( 117),      INT8_MAX,
        -INT8_C(  13), -INT8_C(  34), -INT8_C(  29), -INT8_C( 123),  INT8_C( 109),  INT8_C( 109),  INT8_C(  94),  INT8_C(  78) } },
    { { -INT8_C(   5), -INT8_C( 119), -INT8_C(   4),  INT8_C(  81), -INT8_C(  35),  INT8_C(  84), -INT8_C(  43),  INT8_C(  43),
         INT8_C(  83), -INT8_C(  99),  INT8_C(  11),  INT8_C(  95), -INT8_C(  70),  INT8_C(  19),  INT8_C(  73),  INT8_C(  94),
         INT8_C(  17), -INT8_C(  81),  INT8_C( 123),  INT8_C(  93),  INT8_C(  90),  INT8_C( 109),  INT8_C(  85), -INT8_C( 114),
         INT8_C(  91),  INT8_C(  90),  INT8_C(  45),  INT8_C(  19), -INT8_C(  33),  INT8_C( 102),  INT8_C(  76), -INT8_C(  38),
        -INT8_C(  17),  INT8_C(  72),  INT8_C(  43), -INT8_C(  51), -INT8_C( 100),  INT8_C(   1), -INT8_C(   8), -INT8_C(  16),
        -INT8_C(  98),  INT8_C(   3),  INT8_C(  79),  INT8_C(  89),  INT8_C(  22), -INT8_C( 104), -INT8_C(  73),  INT8_C(  40),
         INT8_C(  71),  INT8_C(  51), -INT8_C( 123), -INT8_C(  95), -INT8_C(  96), -INT8_C(  38),  INT8_C(  47), -INT8_C(   5),
         INT8_C(  52),  INT8_C(  92),  INT8_C(  14),  INT8_C(  19), -INT8_C(  62),  INT8_C(  90), -INT8_C(  18), -INT8_C(  79) },
      { -INT64_C( 5102729997681026653),  INT64_C( 6753368739985653370),  INT64_C( 5591268521116843772), -INT64_C( 6557999714915015031),
         INT64_C( 7798849112021105512),  INT64_C( 1370700774828166545), -INT64_C( 4947124815179807501),  INT64_C( 8039773092396317166) },
      {  INT8_C( 119),  INT8_C(  12),  INT8_C(  59), -INT8_C(  65), -INT8_C(  47), -INT8_C(   9), -INT8_C(   5), -INT8_C(  18),
         INT8_C(   2), -INT8_C(  76),  INT8_C(  79),  INT8_C(  45), -INT8_C( 105),  INT8_C(   2),  INT8_C(  63),  INT8_C(  90),
             INT8_MAX,  INT8_C(  48), -INT8_C( 119), -INT8_C(  60),  INT8_C(  39), -INT8_C(  63), -INT8_C(  25), -INT8_C(   8),
         INT8_C(  41),  INT8_C(  82), -INT8_C(  22),  INT8_C( 108),  INT8_C(   2),  INT8_C(  56),  INT8_C(  10),  INT8_C(  82),
         INT8_C( 118),  INT8_C( 123),  INT8_C(  98),  INT8_C(  27),  INT8_C(  40), -INT8_C(  76),  INT8_C( 108),  INT8_C(  59),
         INT8_C(  94), -INT8_C(  78), -INT8_C(   8), -INT8_C(  44), -INT8_C(  93), -INT8_C(  88),  INT8_C(  38), -INT8_C(  75),
         INT8_C(   9),  INT8_C( 107),  INT8_C(  39),  INT8_C(  24),  INT8_C(  49),  INT8_C(  66), -INT8_C(  80),  INT8_C( 119),
        -INT8_C(   7),  INT8_C( 126),  INT8_C(  26), -INT8_C(  32),  INT8_C( 123), -INT8_C(   5),  INT8_C(  76), -INT8_C(  55) } },
    { {      INT8_MAX,  INT8_C( 119), -INT8_C(  14),  INT8_C( 113), -INT8_C( 118),  INT8_C(  45), -INT8_C(  35),  INT8_C(  27),
         INT8_C( 123), -INT8_C(  39), -INT8_C(  61), -INT8_C( 110), -INT8_C( 114), -INT8_C(  55), -INT8_C(  91), -INT8_C( 127),
        -INT8_C(  51),  INT8_C(  85), -INT8_C( 115), -INT8_C(   2), -INT8_C(  99), -INT8_C(  27), -INT8_C(  71), -INT8_C( 116),
        -INT8_C(  98), -INT8_C(  64),  INT8_C( 123), -INT8_C(  90), -INT8_C(  61),  INT8_C(  15),  INT8_C(  21),  INT8_C(  66),
        -INT8_C( 122),  INT8_C(   7), -INT8_C(  77),  INT8_C(  16),  INT8_C(  53), -INT8_C( 112),  INT8_C(  43), -INT8_C(  80),
         INT8_C( 106), -INT8_C(  17),  INT8_C(  66), -INT8_C(   8), -INT8_C(  72), -INT8_C(  25),  INT8_C( 122), -INT8_C( 123),
         INT8_C(  61),  INT8_C(   7), -INT8_C( 125), -INT8_C(  38), -INT8_C(  20),  INT8_C(  61),  INT8_C( 102), -INT8_C( 117),
        -INT8_C(   3), -INT8_C(  30),  INT8_C(  49), -INT8_C(  64), -INT8_C(  15),  INT8_C(  70),  INT8_C(   3),  INT8_C( 119) },
      { -INT64_C( 5677998684964932018), -INT64_C( 7359405861528570463), -INT64_C( 7159920080737508822),  INT64_C( 7432169848955524028),
        -INT64_C(   68084653224187114),  INT64_C(  398629984775288722), -INT64_C( 7794395223502816103), -INT64_C( 6480005241809849967) },
      { -INT8_C(  99),  INT8_C(  98),  INT8_C(  76), -INT8_C( 103), -INT8_C(  19), -INT8_C(  99),  INT8_C(  60), -INT8_C(  16),
         INT8_C(  51),  INT8_C(  44), -INT8_C(  76),  INT8_C( 106), -INT8_C(  91), -INT8_C(  70),  INT8_C(  26), -INT8_C(  48),
        -INT8_C(  93), -INT8_C(  69), -INT8_C(  93), -INT8_C(  86), -INT8_C(   8), -INT8_C(  44),  INT8_C(  78),  INT8_C(  70),
         INT8_C( 102), -INT8_C(  68), -INT8_C( 116),  INT8_C( 124),  INT8_C( 119), -INT8_C(  71),  INT8_C( 106), -INT8_C(  17),
        -INT8_C(  84),  INT8_C(  86), -INT8_C(  31), -INT8_C(  22), -INT8_C(   8), -INT8_C(  22), -INT8_C(  61),  INT8_C(  14),
         INT8_C(  13),  INT8_C(  16), -INT8_C(  28),  INT8_C(   5),  INT8_C(   5),  INT8_C( 111), -INT8_C( 127), -INT8_C(  68),
        -INT8_C(  52), -INT8_C(   7), -INT8_C( 109), -INT8_C(  50),  INT8_C(  75), -INT8_C(  52), -INT8_C(   5), -INT8_C(  97),
        -INT8_C( 115),  INT8_C( 100),  INT8_C(   9), -INT8_C( 111),  INT8_C(   9), -INT8_C(  58),  INT8_C(  50),  INT8_C(  76) } },
    { {  INT8_C(  17), -INT8_C(   3),  INT8_C(   3),  INT8_C( 111),  INT8_C(  26),  INT8_C(  17),  INT8_C( 110), -INT8_C(  83),
        -INT8_C(  55), -INT8_C(  57), -INT8_C( 100), -INT8_C(  92), -INT8_C(   1),  INT8_C(  36), -INT8_C(  87), -INT8_C( 104),
         INT8_C(  33), -INT8_C(  58), -INT8_C(  47), -INT8_C(   8), -INT8_C( 124), -INT8_C(  91), -INT8_C( 117),  INT8_C(  22),
        -INT8_C(  42), -INT8_C(  52), -INT8_C(  63),  INT8_C( 103),  INT8_C(  50), -INT8_C(  45),  INT8_C(  13),  INT8_C(  67),
        -INT8_C(  48),  INT8_C(  17), -INT8_C(  78), -INT8_C(  21),  INT8_C(  34),  INT8_C(  32), -INT8_C( 104), -INT8_C(  21),
        -INT8_C(  24),  INT8_C(  52), -INT8_C( 113), -INT8_C(  25),  INT8_C(  88),  INT8_C(  57),      INT8_MAX,  INT8_C( 121),
        -INT8_C(   1),  INT8_C(  80),  INT8_C( 113), -INT8_C( 125), -INT8_C(  10), -INT8_C(   3), -INT8_C( 103), -INT8_C(  52),
        -INT8_C(  55),  INT8_C(  90),  INT8_C(  51), -INT8_C(   5),  INT8_C(  46),  INT8_C(  65),  INT8_C(  62), -INT8_C(   2) },
      { -INT64_C(  477239648525356974),  INT64_C( 2848349914988081077), -INT64_C( 4651579638971369040),  INT64_C( 4164697054418544287),
        -INT64_C( 1372457456639298070), -INT64_C( 2067854597212678915), -INT64_C( 2652342844004894598), -INT64_C( 3548145031503615070) },
      {  INT8_C( 116), -INT8_C( 105),  INT8_C(  10), -INT8_C(  63),  INT8_C(  93),  INT8_C( 116), -INT8_C( 126),  INT8_C(   4),
         INT8_C( 119), -INT8_C(  33),      INT8_MIN, -INT8_C(  14),  INT8_C( 106), -INT8_C(  14), -INT8_C(  81),  INT8_C(  14),
         INT8_C( 123), -INT8_C(  26),  INT8_C(  85), -INT8_C(  65), -INT8_C( 101),  INT8_C(  39),      INT8_MAX, -INT8_C( 102),
         INT8_C(  54), -INT8_C(  70),  INT8_C(  79), -INT8_C(  13),  INT8_C( 114), -INT8_C(  73), -INT8_C(  35), -INT8_C(  45),
        -INT8_C(  83), -INT8_C(  42),  INT8_C(  61), -INT8_C( 127),  INT8_C(  77),  INT8_C(  54), -INT8_C(   5), -INT8_C( 127),
        -INT8_C( 127),  INT8_C(  52), -INT8_C(  11),  INT8_C(   2),  INT8_C(  37), -INT8_C(  15), -INT8_C(   5), -INT8_C(  15),
        -INT8_C(  11), -INT8_C( 119), -INT8_C( 104),  INT8_C(  15),  INT8_C( 108), -INT8_C(  42),  INT8_C(  56), -INT8_C(  97),
         INT8_C( 117),  INT8_C(  34), -INT8_C(  40),  INT8_C(  89),  INT8_C(   9), -INT8_C(  47), -INT8_C( 117), -INT8_C( 117) } },
    { {  INT8_C(  41),  INT8_C( 111), -INT8_C(  55),  INT8_C(  95),  INT8_C( 125), -INT8_C(  67),  INT8_C(  75),  INT8_C( 122),
        -INT8_C( 111),  INT8_C(  69), -INT8_C(  97), -INT8_C(  59), -INT8_C(  57), -INT8_C(  20), -INT8_C(  88),  INT8_C(  65),
        -INT8_C(  28),  INT8_C(  50), -INT8_C(  78),  INT8_C(  33),  INT8_C(  46), -INT8_C(  30), -INT8_C(   4), -INT8_C(  48),
        -INT8_C(  51), -INT8_C(  91),  INT8_C(  89), -INT8_C(  79),  INT8_C(  25),  INT8_C(  27),      INT8_MIN,  INT8_C(  66),
        -INT8_C( 118),  INT8_C(  73), -INT8_C(  95),  INT8_C(   7),  INT8_C(   7), -INT8_C(  19), -INT8_C( 127), -INT8_C( 104),
         INT8_C(  50),  INT8_C(  33),  INT8_C(  93), -INT8_C(   7),  INT8_C(  13),  INT8_C(   6),  INT8_C(  59), -INT8_C(  14),
         INT8_C(  56), -INT8_C(  19),  INT8_C(  19),  INT8_C( 102), -INT8_C(  49),  INT8_C(  15),  INT8_C(  54), -INT8_C( 100),
        -INT8_C(  76), -INT8_C( 113),  INT8_C(  77), -INT8_C(  51), -INT8_C(  86), -INT8_C(  51),  INT8_C(  15),  INT8_C(  52) },
      { -INT64_C( 3407327581249425129),  INT64_C( 5971215769139811550), -INT64_C( 5377880692992970254), -INT64_C( 8116732858648581507),
         INT64_C( 3724867587321730883),  INT64_C( 8278739268669504375),  INT64_C(  478666382506171374), -INT64_C(  341559195353668037) },
      {  INT8_C(  94),  INT8_C( 109),  INT8_C(  88),  INT8_C(  60), -INT8_C(  66), -INT8_C(  66), -INT8_C( 106), -INT8_C(  12),
         INT8_C( 101), -INT8_C(  90),  INT8_C(  53), -INT8_C(  90),  INT8_C(  41), -INT8_C(  32),  INT8_C(   5),  INT8_C( 111),
        -INT8_C(  32),  INT8_C(  87),  INT8_C(  87),  INT8_C(   0),  INT8_C( 119),      INT8_MIN,  INT8_C(  43), -INT8_C(  72),
         INT8_C(  21), -INT8_C( 109),  INT8_C(  19), -INT8_C(  83),  INT8_C(  19),  INT8_C(   4),  INT8_C( 125), -INT8_C(  97),
         INT8_C( 101), -INT8_C(  53), -INT8_C(  86),  INT8_C(  46),  INT8_C(  46), -INT8_C( 117), -INT8_C(  95), -INT8_C(  31),
        -INT8_C(  72), -INT8_C(  64),  INT8_C(   4), -INT8_C(  71), -INT8_C(   5), -INT8_C(  19), -INT8_C(  18), -INT8_C(  72),
         INT8_C(   6),  INT8_C(  36), -INT8_C(  26),  INT8_C(  66),  INT8_C( 103),  INT8_C( 103),  INT8_C(  26), -INT8_C(  98),
        -INT8_C(  76),  INT8_C(  90),  INT8_C( 105),  INT8_C( 105), -INT8_C(  94),  INT8_C( 105),  INT8_C(  90), -INT8_C(  76) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m512i a = simde_mm512_loadu_epi8(test_vec[i].a);
    simde__m512i b = simde_mm512_loadu_epi64(test_vec[i].b);
    simde__m512i r = simde_mm512_multishift_epi64_epi8(a, b);
    simde_test_x86_assert_equal_i8x64(r, simde_mm512_loadu_epi8(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m512i a = simde_test_x86_random_i8x64();
    simde__m512i b = simde_test_x86_random_i64x8();
    simde__m512i r = simde_mm512_multishift_epi64_epi8(a, b);

    simde_test_x86_write_i8x64(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i64x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i8x64(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm512_mask_multishift_epi64_epi8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int8_t src[64];
    const simde__mmask64 k;
    const int8_t a[64];
    const int64_t b[8];
    const int8_t r[64];
  } test_vec[] = {
    { {  INT8_C(  32), -INT8_C(  17), -INT8_C(  36),  INT8_C( 117),  INT8_C(  82), -INT8_C( 114), -INT8_C(  87), -INT8_C(  54),
         INT8_C(   9), -INT8_C(  56),  INT8_C(  91), -INT8_C( 118), -INT8_C(  58),  INT8_C(  63), -INT8_C(   4), -INT8_C(  76),
        -INT8_C(  38),  INT8_C(  48), -INT8_C(  93),  INT8_C( 100), -INT8_C(  64),  INT8_C(  71),  INT8_C( 106), -INT8_C(   5),
         INT8_C( 110), -INT8_C( 104), -INT8_C(  82),  INT8_C(  38),  INT8_C(  33), -INT8_C(  16),  INT8_C(  34),  INT8_C(  65),
        -INT8_C(  33), -INT8_C(   2), -INT8_C(  73),  INT8_C(  50), -INT8_C( 116),  INT8_C(  96), -INT8_C(   4), -INT8_C( 106),
         INT8_C(  40),  INT8_C(  87),  INT8_C(  32), -INT8_C(  18), -INT8_C( 106),  INT8_C(  28), -INT8_C(  93),  INT8_C( 113),
         INT8_C(  76),  INT8_C(  70), -INT8_C(  43),  INT8_C(  13), -INT8_C( 114),  INT8_C(  63),  INT8_C(   8), -INT8_C(   4),
        -INT8_C(  41), -INT8_C(  73),  INT8_C(  34), -INT8_C(   8), -INT8_C(  89),  INT8_C(  68),  INT8_C(  58), -INT8_C( 121) },
      UINT64_C( 8747597214219104579),
      {  INT8_C(  12), -INT8_C( 123),  INT8_C( 104), -INT8_C(  93), -INT8_C(  94),  INT8_C(  11),  INT8_C(  20), -INT8_C(  18),
         INT8_C(  81), -INT8_C(  23), -INT8_C(   5), -INT8_C(  33),  INT8_C(  40),  INT8_C(   4), -INT8_C(  37),  INT8_C(   0),
        -INT8_C(  69), -INT8_C(   2), -INT8_C(   8),  INT8_C(  98),  INT8_C(  66),  INT8_C(  50), -INT8_C(  23), -INT8_C( 123),
         INT8_C(  35), -INT8_C(  94),  INT8_C(  85),  INT8_C( 116),  INT8_C(  87), -INT8_C(  70), -INT8_C(  18),  INT8_C( 100),
         INT8_C(  64),  INT8_C(  86),  INT8_C(   7), -INT8_C(  30),  INT8_C(  97),  INT8_C(  27), -INT8_C(  48), -INT8_C(  78),
         INT8_C(   4), -INT8_C(  52), -INT8_C( 110),  INT8_C(  44), -INT8_C(  48),  INT8_C( 109),  INT8_C(  44), -INT8_C( 117),
         INT8_C( 107),  INT8_C(  37), -INT8_C(  19), -INT8_C(  82),  INT8_C(  87), -INT8_C(  41),  INT8_C(  51),  INT8_C( 123),
         INT8_C( 121), -INT8_C( 120), -INT8_C(  17), -INT8_C(  47),  INT8_C(  67), -INT8_C(  35),  INT8_C(  53), -INT8_C( 125) },
      {  INT64_C( 6577284431065988147), -INT64_C( 5594398420844947199), -INT64_C( 7301580600096306471), -INT64_C( 5989048115591931108),
         INT64_C( 9119375262977378268), -INT64_C( 6676114986209700256),  INT64_C( 7543950815616285174), -INT64_C( 7332236511636153062) },
      {  INT8_C(  83), -INT8_C(  31), -INT8_C(  36),  INT8_C( 117),  INT8_C(  82), -INT8_C( 114),  INT8_C(  70), -INT8_C(  54),
        -INT8_C(  61), -INT8_C(  56),  INT8_C(  91), -INT8_C( 118), -INT8_C(  76), -INT8_C( 112), -INT8_C(  38),  INT8_C(   1),
         INT8_C(  51),  INT8_C(  48), -INT8_C(  93), -INT8_C(  56), -INT8_C(  74), -INT8_C(  86),  INT8_C( 106),  INT8_C(  86),
         INT8_C(  15),  INT8_C(  30), -INT8_C(   5), -INT8_C(  50),  INT8_C(  33), -INT8_C(  16), -INT8_C( 118),  INT8_C(   7),
        -INT8_C(  36), -INT8_C(   2), -INT8_C(  73),  INT8_C(  50), -INT8_C(  66),  INT8_C(  96),  INT8_C(  64), -INT8_C( 106),
         INT8_C( 102),  INT8_C(  87), -INT8_C(  45), -INT8_C(  18),  INT8_C(  79), -INT8_C(  51), -INT8_C(  93), -INT8_C(  30),
         INT8_C(  47),  INT8_C(  70), -INT8_C( 117),  INT8_C(  13), -INT8_C( 114),  INT8_C(  47),  INT8_C(  22), -INT8_C(   4),
         INT8_C(  77), -INT8_C(  73),  INT8_C(  34),  INT8_C(  99), -INT8_C(  93), -INT8_C(  20), -INT8_C(  47), -INT8_C( 121) } },
    { { -INT8_C(  16),      INT8_MAX, -INT8_C(  51),  INT8_C( 109),  INT8_C(   6),  INT8_C(  92), -INT8_C(  21),  INT8_C( 103),
         INT8_C( 114),  INT8_C(  58),  INT8_C(  14),  INT8_C(  60), -INT8_C(  26),  INT8_C( 103), -INT8_C(  33), -INT8_C(  36),
         INT8_C(  32), -INT8_C(  78), -INT8_C(  13),  INT8_C( 108),  INT8_C(  49), -INT8_C(  91), -INT8_C(  43),  INT8_C(  75),
        -INT8_C(  62), -INT8_C( 100), -INT8_C(  34),      INT8_MAX,  INT8_C(  70),  INT8_C(  28),  INT8_C(  25),  INT8_C(  54),
        -INT8_C( 101), -INT8_C(  25), -INT8_C(  93), -INT8_C(  94),  INT8_C(  67), -INT8_C( 114),  INT8_C(   9), -INT8_C(  75),
        -INT8_C(  55),  INT8_C(  23), -INT8_C(  15), -INT8_C(  81),  INT8_C( 126), -INT8_C(  48), -INT8_C( 116), -INT8_C(  98),
        -INT8_C( 126),      INT8_MAX,  INT8_C(  10), -INT8_C(  76),  INT8_C(  36), -INT8_C(  33), -INT8_C(   1), -INT8_C(  26),
         INT8_C( 124), -INT8_C(  35),  INT8_C( 102), -INT8_C(  62), -INT8_C(   6),      INT8_MAX, -INT8_C(   8), -INT8_C( 107) },
      UINT64_C(17536524550999088230),
      {  INT8_C(  87),  INT8_C(  79), -INT8_C(  93), -INT8_C(  43),  INT8_C(  31),  INT8_C(  47),  INT8_C( 115), -INT8_C(  94),
        -INT8_C(  82),  INT8_C( 126),  INT8_C(  86), -INT8_C(  45),  INT8_C(  93),  INT8_C(  85), -INT8_C(  71), -INT8_C(  39),
         INT8_C(  51),  INT8_C(  31), -INT8_C( 101),  INT8_C(  45), -INT8_C(  97), -INT8_C( 108), -INT8_C(  62),  INT8_C(   5),
         INT8_C(  48), -INT8_C(   6), -INT8_C(  81),  INT8_C(  90),  INT8_C(  58),  INT8_C(  13),  INT8_C(  78), -INT8_C( 110),
         INT8_C(  93), -INT8_C(  15),  INT8_C( 103),  INT8_C( 124),  INT8_C(  32), -INT8_C(  37),  INT8_C(  30), -INT8_C(  50),
         INT8_C(  89),  INT8_C( 116), -INT8_C(  95), -INT8_C(  74), -INT8_C(  54),  INT8_C(  91), -INT8_C( 112), -INT8_C(   3),
         INT8_C( 122),  INT8_C(  43),  INT8_C(  42),  INT8_C(  25), -INT8_C(  65), -INT8_C(  20),  INT8_C(  31), -INT8_C(  17),
        -INT8_C(  26), -INT8_C(  50),  INT8_C(  74),  INT8_C(  33), -INT8_C(  37), -INT8_C( 104), -INT8_C(  77),  INT8_C(  56) },
      {  INT64_C( 5654220909254613641), -INT64_C( 1292650242280974008),  INT64_C(  895977892885313984), -INT64_C( 2735408656661235211),
        -INT64_C( 2792518114699133190), -INT64_C( 7388442330737720556), -INT64_C( 7321295375475048909),  INT64_C( 7813310438982783554) },
      { -INT8_C(  16),  INT8_C( 106),  INT8_C( 126),  INT8_C( 109),  INT8_C(   6), -INT8_C(  17), -INT8_C(  50),  INT8_C( 103),
         INT8_C( 114),  INT8_C(  58),  INT8_C(  72),  INT8_C(  64), -INT8_C(  96),  INT8_C( 103), -INT8_C(  33),  INT8_C(   9),
        -INT8_C( 115),  INT8_C(  75), -INT8_C(  80),  INT8_C( 108),  INT8_C(  75),  INT8_C(   0), -INT8_C(  43),  INT8_C(  75),
         INT8_C(   9), -INT8_C( 100), -INT8_C(  34),  INT8_C( 116),  INT8_C(  70),  INT8_C( 109),  INT8_C(  25),  INT8_C(  11),
        -INT8_C( 101), -INT8_C(  97), -INT8_C(  93), -INT8_C(  83),  INT8_C(  67),  INT8_C(  62),  INT8_C(   9), -INT8_C(  75),
        -INT8_C(  55),  INT8_C(  23), -INT8_C(  15), -INT8_C(  81),  INT8_C( 126), -INT8_C(  48), -INT8_C(  21), -INT8_C(  98),
        -INT8_C( 126), -INT8_C(  79),  INT8_C(  98), -INT8_C(  84),  INT8_C( 103), -INT8_C(  33),  INT8_C(  74), -INT8_C(  26),
        -INT8_C(  47), -INT8_C(  82),  INT8_C( 102), -INT8_C(  62),  INT8_C(  82), -INT8_C( 109), -INT8_C( 115),  INT8_C( 108) } },
    { {  INT8_C(  50), -INT8_C(  15),  INT8_C(  92), -INT8_C(  61), -INT8_C(  20), -INT8_C( 101), -INT8_C(  99),  INT8_C(   0),
        -INT8_C(  34), -INT8_C( 120), -INT8_C( 120), -INT8_C(  73), -INT8_C( 125), -INT8_C(   1),  INT8_C(  80), -INT8_C(  74),
         INT8_C( 125),  INT8_C( 105),  INT8_C(  15),  INT8_C(  35), -INT8_C(  15),  INT8_C( 116), -INT8_C(  67),  INT8_C(  51),
         INT8_C(   6),  INT8_C(  40), -INT8_C(  57),  INT8_C( 120), -INT8_C( 100),  INT8_C(  53), -INT8_C(  27), -INT8_C(  50),
         INT8_C(  38),  INT8_C(  65), -INT8_C( 110),  INT8_C(  19), -INT8_C(  36),  INT8_C(  47),  INT8_C(  19), -INT8_C(  69),
        -INT8_C(  73), -INT8_C( 100),  INT8_C( 114),  INT8_C(  58), -INT8_C( 101), -INT8_C(  62), -INT8_C(  15),  INT8_C(  24),
         INT8_C(  43),  INT8_C(   0),  INT8_C(  59),  INT8_C(  28),  INT8_C( 117), -INT8_C(   7),  INT8_C(  80),  INT8_C( 123),
         INT8_C(  33),  INT8_C(  23), -INT8_C(  12), -INT8_C(  66),  INT8_C(  76), -INT8_C(  39), -INT8_C( 116),  INT8_C( 114) },
      UINT64_C(  410559076188364314),
      {  INT8_C(  53),  INT8_C(  36),  INT8_C(  63), -INT8_C(  48), -INT8_C(  26),  INT8_C(  48), -INT8_C(  24),  INT8_C(  17),
         INT8_C(  49),  INT8_C(  36),  INT8_C(  45), -INT8_C(  90),  INT8_C(  29),  INT8_C( 125),  INT8_C(  33),  INT8_C(  62),
        -INT8_C( 108),  INT8_C(  21), -INT8_C(   4), -INT8_C(  32), -INT8_C(  18), -INT8_C( 119),  INT8_C(  83),  INT8_C(   9),
        -INT8_C(  89), -INT8_C(  40),  INT8_C(   0), -INT8_C(  11),  INT8_C( 113), -INT8_C(  78), -INT8_C(   6), -INT8_C(  90),
        -INT8_C(  42),  INT8_C(  57),  INT8_C( 118), -INT8_C(  68),  INT8_C( 106),  INT8_C(  95), -INT8_C(  51), -INT8_C( 101),
        -INT8_C( 125), -INT8_C(   6),  INT8_C(  65), -INT8_C(  96),  INT8_C( 120),  INT8_C(  98), -INT8_C(  34),  INT8_C(  12),
         INT8_C( 120), -INT8_C(  37), -INT8_C(  19),  INT8_C( 102),  INT8_C( 100),  INT8_C(  64),  INT8_C( 111),  INT8_C(  11),
         INT8_C(  24),  INT8_C( 111),  INT8_C(   0), -INT8_C( 118),  INT8_C(  33), -INT8_C(   6),  INT8_C(  48), -INT8_C(   9) },
      { -INT64_C( 8558668850920184012),  INT64_C( 6124622663800945275),  INT64_C( 4995101306360949986), -INT64_C( 9100649712657149286),
         INT64_C( 7076660141531031206),  INT64_C( 5189083995649171154), -INT64_C( 9028905914537623999),  INT64_C( 2810793180960555315) },
      {  INT8_C(  50),  INT8_C(   0),  INT8_C(  92), -INT8_C(  77),  INT8_C(   0), -INT8_C( 101), -INT8_C(  99),  INT8_C(   0),
        -INT8_C(  34),  INT8_C( 125), -INT8_C(   8),  INT8_C(  31), -INT8_C(  25), -INT8_C(   1),  INT8_C(  80), -INT8_C(  74),
         INT8_C( 107),  INT8_C( 105),  INT8_C(  36),  INT8_C(  35), -INT8_C(  15),  INT8_C( 116), -INT8_C(  67), -INT8_C(  10),
        -INT8_C(   2), -INT8_C(  69), -INT8_C( 102),  INT8_C( 120), -INT8_C(  39),  INT8_C( 108), -INT8_C(  96), -INT8_C(   3),
        -INT8_C(  80),  INT8_C(  65), -INT8_C( 120),  INT8_C( 102), -INT8_C(  36),  INT8_C(  47), -INT8_C(   5), -INT8_C(  69),
        -INT8_C(  38), -INT8_C( 100),  INT8_C( 114),  INT8_C( 102),  INT8_C(  72), -INT8_C(  62), -INT8_C(  15),  INT8_C(  85),
         INT8_C(  43),  INT8_C(  13),  INT8_C(  59),  INT8_C(  28),  INT8_C(  30),  INT8_C(  65),  INT8_C(  80), -INT8_C(   9),
             INT8_MIN,  INT8_C(  23),  INT8_C(  51), -INT8_C(  66),  INT8_C(  76), -INT8_C(  39), -INT8_C( 116),  INT8_C( 114) } },
    { {  INT8_C(  87),  INT8_C(  32), -INT8_C(  44),  INT8_C(  62),  INT8_C( 120),  INT8_C(   9), -INT8_C(  96),  INT8_C(  74),
         INT8_C( 104), -INT8_C(  11), -INT8_C(   7), -INT8_C(  50),  INT8_C(  74), -INT8_C(   4),  INT8_C(  22), -INT8_C( 117),
        -INT8_C(  70), -INT8_C(  91), -INT8_C(   8), -INT8_C(  94), -INT8_C( 122), -INT8_C(  85),  INT8_C(  37), -INT8_C(  70),
         INT8_C(  44),  INT8_C(  99),  INT8_C(  58), -INT8_C(  83),  INT8_C(  84),  INT8_C(  60), -INT8_C(  43), -INT8_C(  85),
         INT8_C(  92), -INT8_C(  87), -INT8_C(  22), -INT8_C(  43), -INT8_C(  78), -INT8_C( 118),  INT8_C(  31),  INT8_C(  26),
             INT8_MIN,  INT8_C(  24), -INT8_C(  24), -INT8_C(  54),  INT8_C(  20), -INT8_C(   1),  INT8_C(  85), -INT8_C(  50),
        -INT8_C(  92),  INT8_C(  77),  INT8_C( 113),  INT8_C(  43), -INT8_C(   8), -INT8_C( 106), -INT8_C(  27),  INT8_C(  37),
        -INT8_C(   7),  INT8_C(  31), -INT8_C(  46),  INT8_C(  77),  INT8_C(  91), -INT8_C(  89), -INT8_C(   8), -INT8_C(  72) },
      UINT64_C(17086002145524572752),
      { -INT8_C(  59),  INT8_C(   6), -INT8_C(  73), -INT8_C(  39),  INT8_C(   5),  INT8_C(  12), -INT8_C(  88), -INT8_C(  87),
         INT8_C(  89),  INT8_C(  25), -INT8_C(  44),  INT8_C(  82), -INT8_C(  81), -INT8_C(  71),  INT8_C( 119), -INT8_C(  88),
        -INT8_C(  39),  INT8_C(  73), -INT8_C(  11),  INT8_C(  52), -INT8_C(  15), -INT8_C(  19), -INT8_C(  20),  INT8_C(  65),
        -INT8_C(  48),  INT8_C( 121),  INT8_C(  68),  INT8_C(  61),  INT8_C(  38),  INT8_C(  98),  INT8_C(  42), -INT8_C(  21),
         INT8_C( 104), -INT8_C(  31), -INT8_C(  60),  INT8_C( 109), -INT8_C(  19),  INT8_C( 108),  INT8_C(  22),  INT8_C(  70),
        -INT8_C( 123), -INT8_C(  21), -INT8_C( 104),  INT8_C(  52), -INT8_C(  92),  INT8_C(  15), -INT8_C(  36),  INT8_C( 125),
         INT8_C(  89), -INT8_C(  47), -INT8_C(  78),  INT8_C(  74), -INT8_C(  65), -INT8_C(  98), -INT8_C( 117), -INT8_C( 113),
         INT8_C(  24), -INT8_C(  48), -INT8_C(  52),  INT8_C(  62),  INT8_C(  50), -INT8_C(  10),  INT8_C(  41), -INT8_C( 102) },
      { -INT64_C( 2375053577811399209),  INT64_C(  804720133637710600), -INT64_C( 7849526229939659582), -INT64_C( 6233550525538640719),
        -INT64_C( 6187532878559214361), -INT64_C( 1740499256619879142), -INT64_C( 4581154711475311010),  INT64_C( 2220028562560466260) },
      {  INT8_C(  87),  INT8_C(  32), -INT8_C(  44),  INT8_C(  62),  INT8_C( 110),  INT8_C(   9),  INT8_C(  29),  INT8_C(  74),
         INT8_C( 104),  INT8_C(  86), -INT8_C(   7), -INT8_C(  50),  INT8_C(  74),  INT8_C(   5),  INT8_C(  22), -INT8_C(  16),
        -INT8_C(  64), -INT8_C(  91), -INT8_C( 104),  INT8_C(  49), -INT8_C( 122), -INT8_C(  85),  INT8_C(  37),  INT8_C(  97),
        -INT8_C(  47), -INT8_C(  44),  INT8_C(  58), -INT8_C(  83),  INT8_C(  84),  INT8_C(  60), -INT8_C(  43), -INT8_C(  85),
         INT8_C( 119), -INT8_C(  87),  INT8_C(  78),  INT8_C(  11), -INT8_C(  78),  INT8_C(  23),  INT8_C(   5),  INT8_C(  26),
             INT8_MIN,  INT8_C(  24), -INT8_C(  51),  INT8_C( 125),  INT8_C(  20), -INT8_C(  82),  INT8_C(  85), -INT8_C(  41),
        -INT8_C(  20),  INT8_C(  77),  INT8_C(  27),  INT8_C(  11), -INT8_C(  67), -INT8_C( 106), -INT8_C(  27),  INT8_C(  37),
         INT8_C(  38),  INT8_C(  31),  INT8_C(  51),  INT8_C(  80),  INT8_C(  91),  INT8_C( 123), -INT8_C( 112), -INT8_C(  55) } },
    { { -INT8_C(  92),  INT8_C(  60),  INT8_C(  96),  INT8_C(  69), -INT8_C(  76), -INT8_C( 127), -INT8_C(  17), -INT8_C(  50),
        -INT8_C(  74),  INT8_C(  70), -INT8_C( 101), -INT8_C(  37), -INT8_C(  56),  INT8_C( 116), -INT8_C(  61),  INT8_C(  38),
        -INT8_C(  94),  INT8_C(  43), -INT8_C(   1), -INT8_C(  79), -INT8_C(  92),  INT8_C( 107),  INT8_C( 113), -INT8_C(   8),
        -INT8_C(  88),  INT8_C(  20),  INT8_C(  31), -INT8_C(  33),  INT8_C(  52), -INT8_C(  18), -INT8_C(   3), -INT8_C(  40),
         INT8_C(  43),  INT8_C(  93),  INT8_C(  29), -INT8_C(  33), -INT8_C(  34),  INT8_C(  13), -INT8_C(  83), -INT8_C( 108),
         INT8_C(  83),  INT8_C(  73),  INT8_C( 112),  INT8_C(  27), -INT8_C(  67),  INT8_C(  51),  INT8_C(  65),  INT8_C(  95),
         INT8_C(  94),  INT8_C(  64),  INT8_C(  16),  INT8_C(   2), -INT8_C(  85), -INT8_C( 127), -INT8_C(   5),  INT8_C(  83),
        -INT8_C( 107),  INT8_C(  26),  INT8_C(  50), -INT8_C(  55),  INT8_C(   8),  INT8_C(  48), -INT8_C(  95),  INT8_C(  51) },
      UINT64_C( 2233997395099827853),
      {  INT8_C(   9),  INT8_C( 112),  INT8_C(  58), -INT8_C(  58), -INT8_C(  93),  INT8_C( 124),  INT8_C(  37),  INT8_C(   2),
        -INT8_C(  68),  INT8_C(  53),  INT8_C(   4),  INT8_C( 104), -INT8_C(  74), -INT8_C(   1), -INT8_C(  69),  INT8_C(  75),
         INT8_C(  25), -INT8_C(  18),  INT8_C(  20),  INT8_C(  34),  INT8_C(  30), -INT8_C(  75),  INT8_C(  85), -INT8_C(  85),
         INT8_C( 115),  INT8_C( 104),  INT8_C(  23),  INT8_C(  63),  INT8_C(  40),  INT8_C(  24),  INT8_C(  94),  INT8_C(  49),
        -INT8_C( 120), -INT8_C( 104), -INT8_C(   9),  INT8_C(  44),  INT8_C(  20),  INT8_C(  28),  INT8_C(  46), -INT8_C(  47),
         INT8_C(  81),  INT8_C(  50),  INT8_C(  57),  INT8_C(   7),  INT8_C(  50), -INT8_C(  12),  INT8_C(  82),  INT8_C(  75),
        -INT8_C(  30),  INT8_C( 102),  INT8_C( 109),  INT8_C(   0),  INT8_C(  27), -INT8_C(  61), -INT8_C(  84), -INT8_C( 114),
         INT8_C(  43), -INT8_C(  61), -INT8_C(  51),  INT8_C(  83), -INT8_C(  37),  INT8_C(  43), -INT8_C( 124),  INT8_C( 100) },
      { -INT64_C( 1681603426463482940), -INT64_C( 5085054536994790672), -INT64_C( 3940536841891292249),  INT64_C(  966479830526467625),
        -INT64_C( 6369620703818876645),  INT64_C( 8143133517711837554),  INT64_C( 5511143853571423251),  INT64_C( 6123129922015828130) },
      {  INT8_C(  61),  INT8_C(  60),  INT8_C(  58), -INT8_C(  17), -INT8_C(  76), -INT8_C( 127), -INT8_C(  17), -INT8_C(  15),
        -INT8_C(  74), -INT8_C(  53),  INT8_C(  47),  INT8_C(  65), -INT8_C(  27), -INT8_C(  31), -INT8_C(  61), -INT8_C(   4),
        -INT8_C(  94),  INT8_C(  65), -INT8_C(   1), -INT8_C(  79),  INT8_C( 123),  INT8_C( 107),  INT8_C( 113), -INT8_C(   8),
        -INT8_C(  88),  INT8_C(  20),  INT8_C(  10),  INT8_C(  82),  INT8_C(  52),  INT8_C(   5),  INT8_C(  36), -INT8_C(  40),
        -INT8_C(   7), -INT8_C(  78),  INT8_C(  29), -INT8_C(  88), -INT8_C(  34),  INT8_C(  13),  INT8_C( 106),  INT8_C( 115),
         INT8_C(  83),  INT8_C(  73),  INT8_C( 112),  INT8_C(  27), -INT8_C(  67),  INT8_C(  51),  INT8_C( 114),  INT8_C(  81),
         INT8_C(  94),  INT8_C(  64),  INT8_C(  16),  INT8_C(   2), -INT8_C(  85), -INT8_C( 127), -INT8_C(   5),  INT8_C(  83),
         INT8_C(  55),  INT8_C(  20), -INT8_C( 116),  INT8_C( 106),  INT8_C(  29),  INT8_C(  48), -INT8_C(  95),  INT8_C(  51) } },
    { { -INT8_C(  77), -INT8_C(  33),  INT8_C(   6),  INT8_C( 106),  INT8_C( 110), -INT8_C(  95),  INT8_C(  17), -INT8_C(  32),
         INT8_C(  42), -INT8_C(  37),  INT8_C(  41), -INT8_C(  11),  INT8_C(  19),  INT8_C(  44),  INT8_C( 102),  INT8_C(  39),
        -INT8_C(  24), -INT8_C( 102), -INT8_C(  39),  INT8_C(  11),  INT8_C(  30),  INT8_C(  84),  INT8_C(  87), -INT8_C(  64),
        -INT8_C(  20), -INT8_C(  88), -INT8_C(  85),  INT8_C(  37),  INT8_C(  98), -INT8_C(  92),  INT8_C( 121),  INT8_C(  21),
        -INT8_C( 125),      INT8_MAX,      INT8_MAX, -INT8_C(  14),  INT8_C(  32), -INT8_C( 112), -INT8_C(  46),  INT8_C(  75),
         INT8_C( 108), -INT8_C(   4),  INT8_C(  64),      INT8_MAX,  INT8_C(  40), -INT8_C(  90), -INT8_C(  90),  INT8_C(  16),
         INT8_C(  64),      INT8_MAX,  INT8_C(  27),  INT8_C(  94), -INT8_C(  44),  INT8_C( 114),  INT8_C(  30), -INT8_C(  64),
         INT8_C(  26), -INT8_C(  54), -INT8_C(  27),  INT8_C( 124),  INT8_C( 110),  INT8_C(  94), -INT8_C( 111), -INT8_C(  14) },
      UINT64_C(  957497202675290334),
      { -INT8_C(  78), -INT8_C( 119), -INT8_C( 116), -INT8_C(  38),  INT8_C(  48),  INT8_C(  51), -INT8_C(  21),  INT8_C( 112),
        -INT8_C(  78),  INT8_C(   6), -INT8_C(  49), -INT8_C( 122),  INT8_C( 121), -INT8_C(  19),  INT8_C(  71), -INT8_C( 109),
        -INT8_C(  73),  INT8_C(  44),  INT8_C(  16),  INT8_C(  38), -INT8_C( 117), -INT8_C(  95),  INT8_C(  24),  INT8_C( 105),
        -INT8_C(  78), -INT8_C(   4),  INT8_C( 103),  INT8_C(  83), -INT8_C(  78), -INT8_C(  79),  INT8_C(  96),  INT8_C( 101),
         INT8_C(  58), -INT8_C(  20),  INT8_C(  63),  INT8_C( 106),  INT8_C(  31),  INT8_C(  42), -INT8_C(  37), -INT8_C(  46),
         INT8_C(  49), -INT8_C(  86),  INT8_C(  88), -INT8_C(  86), -INT8_C( 105), -INT8_C(  97),  INT8_C(  61),  INT8_C(  79),
        -INT8_C(  52),  INT8_C(  77),  INT8_C( 117),  INT8_C(  87), -INT8_C(  17), -INT8_C( 115), -INT8_C(  64), -INT8_C(  95),
        -INT8_C( 119),  INT8_C(  39), -INT8_C(  12),  INT8_C(  59), -INT8_C(  40),  INT8_C(  84), -INT8_C(  96),  INT8_C(  19) },
      {  INT64_C( 4265568598665060416), -INT64_C(  654953604911363582),  INT64_C( 8358696212967022192), -INT64_C( 8565758220861180876),
        -INT64_C(  543215960687272656), -INT64_C( 1169392743654204507),  INT64_C( 6068687495737774809),  INT64_C( 7500042834328807491) },
      { -INT8_C(  77), -INT8_C(  16), -INT8_C(  34), -INT8_C( 104),  INT8_C(  50), -INT8_C(  95),  INT8_C(  75),  INT8_C(  50),
         INT8_C(  42), -INT8_C(  37),  INT8_C(  41), -INT8_C(  11),  INT8_C( 123),  INT8_C(  44),  INT8_C( 102),  INT8_C(  39),
        -INT8_C(  24), -INT8_C( 102),  INT8_C(  77),  INT8_C(  11),  INT8_C(  30), -INT8_C(  11),  INT8_C(  95),  INT8_C(   6),
        -INT8_C(  20),  INT8_C(  72), -INT8_C(  96), -INT8_C(  75),  INT8_C(  72), -INT8_C( 112),  INT8_C(  72), -INT8_C( 126),
         INT8_C(  62),      INT8_MAX,      INT8_MAX, -INT8_C(  14),  INT8_C(  32), -INT8_C( 122), -INT8_C(  46), -INT8_C(  70),
         INT8_C( 108),  INT8_C(  94), -INT8_C(  49),      INT8_MAX, -INT8_C(  97), -INT8_C(   3), -INT8_C(  90),  INT8_C(  36),
        -INT8_C(  31),      INT8_MAX,  INT8_C(  27), -INT8_C( 120), -INT8_C(  44),  INT8_C( 114), -INT8_C(  39), -INT8_C(  64),
        -INT8_C(  12), -INT8_C(  54), -INT8_C( 127),  INT8_C( 109),  INT8_C( 110),  INT8_C(  94), -INT8_C( 111), -INT8_C(  14) } },
    { {  INT8_C(  30), -INT8_C(   2), -INT8_C(  94),  INT8_C(  20),  INT8_C(  25),  INT8_C(  24),  INT8_C(  13), -INT8_C(  66),
         INT8_C( 116), -INT8_C(  97), -INT8_C( 114), -INT8_C(  14),  INT8_C(  27),  INT8_C(  83), -INT8_C(  31), -INT8_C(  12),
         INT8_C( 102),  INT8_C(  48), -INT8_C(  71), -INT8_C( 123),      INT8_MAX, -INT8_C(  15), -INT8_C(  39), -INT8_C(  62),
        -INT8_C(  39),  INT8_C(  58),  INT8_C(  78),  INT8_C(  17), -INT8_C(  69),  INT8_C(  99),  INT8_C( 121), -INT8_C(  38),
         INT8_C(  97),  INT8_C(  28), -INT8_C(  18),  INT8_C( 122),  INT8_C(  52), -INT8_C(   5),  INT8_C(  57), -INT8_C(  88),
        -INT8_C( 101), -INT8_C(  57), -INT8_C( 101), -INT8_C(  74),  INT8_C(  26),  INT8_C( 124), -INT8_C(  86),      INT8_MIN,
        -INT8_C(  84),  INT8_C(  99),  INT8_C(   6),  INT8_C(  43),  INT8_C(  85), -INT8_C(  33), -INT8_C(  18),  INT8_C(  46),
         INT8_C(  26),  INT8_C(  60),  INT8_C(  64), -INT8_C(  43), -INT8_C(  96), -INT8_C(  71), -INT8_C(  81),  INT8_C(   1) },
      UINT64_C( 3797297104737312469),
      {  INT8_C( 124),  INT8_C(  77), -INT8_C(  22), -INT8_C( 106), -INT8_C(  54), -INT8_C( 107),  INT8_C(  23),  INT8_C( 118),
        -INT8_C(   8),  INT8_C(  29), -INT8_C(  94),  INT8_C(  77), -INT8_C(   4), -INT8_C( 112),  INT8_C( 124),  INT8_C(  22),
        -INT8_C(  52), -INT8_C(  68), -INT8_C(  20),  INT8_C( 108),  INT8_C( 117), -INT8_C( 101),  INT8_C( 110),  INT8_C(  75),
         INT8_C(  57), -INT8_C(  22),  INT8_C(  85), -INT8_C(  45), -INT8_C(  97),  INT8_C(   7),  INT8_C(   7),  INT8_C(  27),
         INT8_C(  85), -INT8_C(  14), -INT8_C(  79),  INT8_C(  31), -INT8_C( 121), -INT8_C(  56), -INT8_C( 107),      INT8_MAX,
        -INT8_C(  27),  INT8_C(  55), -INT8_C(  51), -INT8_C(  30), -INT8_C(  57),  INT8_C(  73), -INT8_C(   8), -INT8_C( 108),
         INT8_C(   5), -INT8_C(  28),  INT8_C(   0),  INT8_C( 122),      INT8_MIN,  INT8_C( 110), -INT8_C(  59), -INT8_C(  71),
         INT8_C(  88),  INT8_C(  26), -INT8_C( 116), -INT8_C(   9),  INT8_C(  34), -INT8_C( 108),  INT8_C(  18),  INT8_C( 119) },
      {  INT64_C( 8254020097586676870), -INT64_C( 6359561364421977757), -INT64_C( 8760935941664489679),  INT64_C( 1268766647322015490),
        -INT64_C( 4660475348501253804),  INT64_C( 2616214197979751940),  INT64_C( 6420795339155271783),  INT64_C( 8994277969136293942) },
      {  INT8_C( 103), -INT8_C(   2),  INT8_C(  10),  INT8_C(  20), -INT8_C(  79),  INT8_C(  24),  INT8_C(  27), -INT8_C(  54),
         INT8_C( 116),  INT8_C(  17),  INT8_C(  40), -INT8_C(  94),  INT8_C(  58),  INT8_C(  83), -INT8_C(  31), -INT8_C(  87),
         INT8_C( 102),  INT8_C(  48), -INT8_C(  82), -INT8_C(  82),  INT8_C(  51), -INT8_C(  74), -INT8_C(  85), -INT8_C(  62),
        -INT8_C(  39), -INT8_C(  28),  INT8_C(  78), -INT8_C( 113), -INT8_C(  69),  INT8_C(  99),  INT8_C( 121), -INT8_C(  38),
         INT8_C(   0),  INT8_C(  28), -INT8_C(  18), -INT8_C(  71),  INT8_C(  98), -INT8_C(   5),  INT8_C(  57), -INT8_C(  87),
         INT8_C(  71), -INT8_C(  57),  INT8_C(  85), -INT8_C(  74),  INT8_C(  76),  INT8_C(  83), -INT8_C(  86),  INT8_C( 110),
        -INT8_C(  84), -INT8_C(  11),  INT8_C(   6),  INT8_C(  43),  INT8_C( 103),  INT8_C( 108), -INT8_C(  18), -INT8_C(  84),
         INT8_C(  26),  INT8_C(  60), -INT8_C(  39), -INT8_C(  43),  INT8_C(  10),  INT8_C(  23), -INT8_C(  81),  INT8_C(   1) } },
    { {  INT8_C(  73), -INT8_C(  16),  INT8_C(  93), -INT8_C(  90), -INT8_C( 101), -INT8_C(  81),  INT8_C( 101), -INT8_C(  97),
         INT8_C(  86),  INT8_C(  79),  INT8_C(  69),  INT8_C(  73), -INT8_C(   8), -INT8_C( 109),  INT8_C( 109),  INT8_C(  95),
         INT8_C(   3),  INT8_C(  66), -INT8_C(  12),  INT8_C(  91), -INT8_C( 127),  INT8_C(  15), -INT8_C(  76), -INT8_C(  72),
        -INT8_C(  88),  INT8_C(  50),  INT8_C( 121), -INT8_C(  48),  INT8_C(  74),  INT8_C(  76),  INT8_C(  77), -INT8_C( 108),
         INT8_C(  60), -INT8_C(  86),  INT8_C(  58), -INT8_C(  41),  INT8_C(  89), -INT8_C(  97),  INT8_C( 118), -INT8_C(  81),
        -INT8_C(  17), -INT8_C(  68), -INT8_C(   8), -INT8_C(  25),  INT8_C(  79),  INT8_C( 101),  INT8_C(  70),  INT8_C(  83),
        -INT8_C(  89),  INT8_C(  59), -INT8_C(  82),  INT8_C(  41),  INT8_C(  74),  INT8_C(  98), -INT8_C(  31), -INT8_C(  14),
        -INT8_C( 108),  INT8_C(  90), -INT8_C(  61), -INT8_C(  33), -INT8_C(  90),  INT8_C(  16),  INT8_C( 115), -INT8_C(  29) },
      UINT64_C( 4306339871514602938),
      { -INT8_C(  19), -INT8_C(  69),  INT8_C(  34),  INT8_C(  60),  INT8_C(  33),  INT8_C( 105), -INT8_C( 113), -INT8_C(  56),
        -INT8_C(  92),  INT8_C(  61), -INT8_C(  15), -INT8_C(  18), -INT8_C(  96), -INT8_C(  46), -INT8_C(  31),  INT8_C(  52),
         INT8_C(  45), -INT8_C(  92),  INT8_C(  19), -INT8_C(  45), -INT8_C(  76), -INT8_C( 122), -INT8_C(  74),  INT8_C( 110),
         INT8_C(  51),  INT8_C( 113), -INT8_C( 127),      INT8_MIN, -INT8_C(  94),  INT8_C(  68), -INT8_C(  69), -INT8_C( 113),
         INT8_C(   0), -INT8_C(  34), -INT8_C(  53),  INT8_C(  33),  INT8_C(  71),  INT8_C(  91), -INT8_C(  23), -INT8_C(  21),
        -INT8_C( 104), -INT8_C(  37), -INT8_C(  39),  INT8_C(  56), -INT8_C(  83), -INT8_C(  70),  INT8_C( 109), -INT8_C(  38),
         INT8_C(  94),      INT8_MIN, -INT8_C(  82),  INT8_C(  18),  INT8_C(   7),  INT8_C( 100),      INT8_MIN,  INT8_C(  58),
        -INT8_C(  43),  INT8_C(   2), -INT8_C(  70),  INT8_C( 119),  INT8_C(  70),  INT8_C( 118),  INT8_C(   6),  INT8_C(  70) },
      { -INT64_C( 4213591145035869612),  INT64_C( 8697694543429918508), -INT64_C( 7193080080740162837), -INT64_C( 5649173794437994739),
         INT64_C( 9214033141995143916),  INT64_C( 3730119891732716594),  INT64_C( 7552908601764171630), -INT64_C( 1564622644555488198) },
      {  INT8_C(  73), -INT8_C( 104),  INT8_C(  93),  INT8_C(  76), -INT8_C( 106),  INT8_C(  40),  INT8_C( 101), -INT8_C(  46),
        -INT8_C(  79),  INT8_C(  79),  INT8_C(  90), -INT8_C(  47), -INT8_C(   8),      INT8_MAX,  INT8_C( 109), -INT8_C( 117),
         INT8_C(   3), -INT8_C(  68), -INT8_C(  12),  INT8_C(  81), -INT8_C(  62), -INT8_C( 117), -INT8_C(  76), -INT8_C(  76),
         INT8_C(  51), -INT8_C(  51),  INT8_C( 121), -INT8_C(  48), -INT8_C( 105),  INT8_C(  76),  INT8_C(  77), -INT8_C( 108),
         INT8_C(  60), -INT8_C(  86),      INT8_MIN,  INT8_C(  41),  INT8_C(  89), -INT8_C(  97),  INT8_C( 105), -INT8_C(  81),
         INT8_C(  76), -INT8_C(  68), -INT8_C(   8), -INT8_C(  25),  INT8_C(  32), -INT8_C( 116),  INT8_C(  70),  INT8_C(  83),
         INT8_C( 108),  INT8_C( 110), -INT8_C(  82),  INT8_C(  41),  INT8_C(  74),  INT8_C(  98),  INT8_C( 110), -INT8_C( 102),
        -INT8_C(  67),  INT8_C(  14), -INT8_C(  61), -INT8_C(  44), -INT8_C( 112), -INT8_C(  87),  INT8_C( 115), -INT8_C(  29) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m512i src = simde_mm512_loadu_epi8(test_vec[i].src);
    simde__m512i a = simde_mm512_loadu_epi8(test_vec[i].a);
    simde__m512i b = simde_mm512_loadu_epi64(test_vec[i].b);
    simde__m512i r = simde_mm512_mask_multishift_epi64_epi8(src, test_vec[i].k, a, b);
    simde_test_x86_assert_equal_i8x64(r, simde_mm512_loadu_epi8(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m512i src = simde_test_x86_random_i8x64();
    simde__mmask64 k = simde_test_x86_random_mmask64();
    simde__m512i a = simde_test_x86_random_i8x64();
    simde__m512i b = simde_test_x86_random_i64x8();
    simde__m512i r = simde_mm512_mask_multishift_epi64_epi8(src, k, a, b);

    simde_test_x86_write_i8x64(2, src, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_mmask64(2, k, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i8x64(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i64x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i8x64(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm512_maskz_multishift_epi64_epi8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask64 k;
    const int8_t a[64];
    const int64_t b[8];
    const int8_t r[64];
  } test_vec[] = {
    { UINT64_C(11109221845029852505),
      { -INT8_C(  66), -INT8_C( 125), -INT8_C(  26),  INT8_C(   6), -INT8_C( 112), -INT8_C(  86),  INT8_C(  57), -INT8_C(   2),
        -INT8_C(   6),  INT8_C(  94),  INT8_C(  51),  INT8_C(  85), -INT8_C(  79),  INT8_C(   4), -INT8_C(  67), -INT8_C(  21),
        -INT8_C(  23),  INT8_C( 122), -INT8_C( 126), -INT8_C(  25), -INT8_C(  47), -INT8_C(  53), -INT8_C(  46),  INT8_C(  42),
         INT8_C(  97), -INT8_C(  43), -INT8_C(  42), -INT8_C(  55), -INT8_C(  73),  INT8_C(   1),  INT8_C(  99),  INT8_C( 118),
        -INT8_C( 124),  INT8_C(  73),  INT8_C( 124),  INT8_C(  20), -INT8_C(  13), -INT8_C(  75),  INT8_C(  19), -INT8_C(  19),
         INT8_C(  19),  INT8_C(  70),  INT8_C(  66), -INT8_C(  60),  INT8_C(  75),  INT8_C(   0), -INT8_C(  81),  INT8_C(  52),
         INT8_C( 122),  INT8_C(  50),  INT8_C(  27),  INT8_C(  75), -INT8_C(   3), -INT8_C(  19),  INT8_C( 117),  INT8_C(  94),
        -INT8_C(  61),  INT8_C(  75),  INT8_C(  39),  INT8_C( 122),  INT8_C(  76), -INT8_C( 118), -INT8_C(  16), -INT8_C(  48) },
      {  INT64_C( 3869990803789409491),  INT64_C( 8195893777521047358), -INT64_C( 8559317836684797477), -INT64_C( 4856862913198793092),
        -INT64_C( 5424805148792488607),  INT64_C( 3861831570100695343),  INT64_C(   10208435472520148),  INT64_C( 9027571128801437859) },
      {  INT8_C(  76),  INT8_C(   0),  INT8_C(   0), -INT8_C(  77), -INT8_C(  27),  INT8_C(   0), -INT8_C( 102),  INT8_C(   0),
        -INT8_C( 100),  INT8_C(   0),  INT8_C(  55),  INT8_C(   0), -INT8_C(  34),  INT8_C(   0),  INT8_C(   0), -INT8_C(  75),
        -INT8_C( 104), -INT8_C(  30),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
         INT8_C(   0),  INT8_C(   0),  INT8_C(  32),  INT8_C(  47),  INT8_C(   0),  INT8_C(  62),  INT8_C(   0), -INT8_C(  14),
         INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(  40),  INT8_C(   0), -INT8_C(  91),  INT8_C(  80),  INT8_C(   0),
         INT8_C(   0), -INT8_C(  60),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(  47),  INT8_C(  47),  INT8_C(  89),
         INT8_C(   0),  INT8_C(   9),  INT8_C(   0), -INT8_C(  86),  INT8_C(   0),  INT8_C(  34),  INT8_C(   0),  INT8_C(   0),
         INT8_C(   0),  INT8_C(   5),  INT8_C(   0), -INT8_C(  33), -INT8_C( 126),  INT8_C(   0),  INT8_C(   0), -INT8_C(  56) } },
    { UINT64_C( 3677108849971612894),
      {  INT8_C( 104),  INT8_C(  69),  INT8_C(  89), -INT8_C(  62),  INT8_C(  64), -INT8_C(  16), -INT8_C(   9),  INT8_C(  20),
         INT8_C(  67),  INT8_C(   5), -INT8_C(  82), -INT8_C(  57),  INT8_C(  73), -INT8_C(  46), -INT8_C(  57), -INT8_C(  20),
        -INT8_C(   6), -INT8_C( 113),  INT8_C( 120),  INT8_C(  23), -INT8_C(  17), -INT8_C(  63), -INT8_C( 108), -INT8_C(  51),
        -INT8_C( 115), -INT8_C( 108),  INT8_C(  33), -INT8_C( 111),  INT8_C(  76),  INT8_C(  40), -INT8_C(  60), -INT8_C(  76),
         INT8_C( 109),  INT8_C(  29),  INT8_C( 119), -INT8_C(  83),  INT8_C(  13),  INT8_C( 110), -INT8_C(  63),  INT8_C(  80),
         INT8_C( 115),  INT8_C( 112),  INT8_C(  23), -INT8_C(  67),  INT8_C(  66), -INT8_C(  34), -INT8_C(  87),  INT8_C(  61),
         INT8_C( 109),  INT8_C(  34),  INT8_C(  84),  INT8_C(  92), -INT8_C(  29), -INT8_C(  24),  INT8_C(  42),  INT8_C( 112),
         INT8_C( 125),  INT8_C(  75),  INT8_C(   1), -INT8_C(  55),  INT8_C( 115), -INT8_C(  59),  INT8_C( 125), -INT8_C(  31) },
      { -INT64_C( 3008597635909094174), -INT64_C( 6827671216479578432), -INT64_C(  454257197757656225),  INT64_C( 6541266772279079794),
         INT64_C( 7308648015081329972), -INT64_C( 7083133903885041186),  INT64_C( 5381961914691596347), -INT64_C( 1939090246797856188) },
      {  INT8_C(   0), -INT8_C(  89), -INT8_C(   9),  INT8_C(  56), -INT8_C(  30),  INT8_C(   0), -INT8_C(  84), -INT8_C(   8),
         INT8_C(   0),  INT8_C(   0), -INT8_C(   4), -INT8_C(  83),  INT8_C(   0),  INT8_C(   0), -INT8_C(  83), -INT8_C(  13),
         INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
         INT8_C(  21),  INT8_C( 108),  INT8_C(   0),  INT8_C(   0),  INT8_C(  43),  INT8_C(   0),  INT8_C(  55),  INT8_C(   0),
         INT8_C(   0),  INT8_C(   0), -INT8_C(  54),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
        -INT8_C(  74), -INT8_C(  77),  INT8_C(  36),  INT8_C(   0),  INT8_C( 119), -INT8_C(   8),  INT8_C(   0), -INT8_C(  12),
        -INT8_C( 124),  INT8_C( 118),  INT8_C( 125),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
         INT8_C(  39),  INT8_C(  14),  INT8_C(   0),  INT8_C(   0), -INT8_C(  94), -INT8_C( 110),  INT8_C(   0),  INT8_C(   0) } },
    { UINT64_C(14220374105348923213),
      { -INT8_C(  21), -INT8_C(  64), -INT8_C(  41),  INT8_C(  41),  INT8_C( 103), -INT8_C( 118), -INT8_C(  58), -INT8_C(  94),
         INT8_C(  58), -INT8_C(  91),  INT8_C(  89),  INT8_C(  18),  INT8_C(  54),  INT8_C(   9),  INT8_C(  93),  INT8_C( 122),
         INT8_C( 123), -INT8_C( 115),  INT8_C(  54),  INT8_C(  45), -INT8_C( 123),  INT8_C(  76),  INT8_C(  18), -INT8_C(  46),
        -INT8_C(  85), -INT8_C( 113), -INT8_C(  60), -INT8_C( 110),  INT8_C( 121),  INT8_C(  28),  INT8_C(  87),  INT8_C( 100),
        -INT8_C(  36),  INT8_C(  46), -INT8_C( 115),  INT8_C(  68), -INT8_C(  72),  INT8_C(  83), -INT8_C(  26), -INT8_C(  14),
        -INT8_C(   8),  INT8_C(  64),  INT8_C(   5),  INT8_C(  46),  INT8_C(  73),  INT8_C(  98), -INT8_C(  88), -INT8_C(  59),
        -INT8_C(  17), -INT8_C(  34), -INT8_C(  14),  INT8_C( 116),  INT8_C(  42),  INT8_C(   4),  INT8_C(  70), -INT8_C(  43),
        -INT8_C( 109),  INT8_C(  11),  INT8_C( 103),  INT8_C(  12),  INT8_C(  39), -INT8_C(  66),  INT8_C( 112),  INT8_C(   4) },
      {  INT64_C( 5230418941125918188), -INT64_C( 1333875839561458834),  INT64_C(  575238589938495484),  INT64_C(  927323849917424307),
        -INT64_C( 4388116452986575231), -INT64_C( 5994862094691102238), -INT64_C( 8511012923570508185), -INT64_C(  334037708531501776) },
      { -INT8_C(  59),  INT8_C(   0),  INT8_C(  72),  INT8_C(  23),  INT8_C(   0),  INT8_C(   0), -INT8_C(   9),  INT8_C(   0),
        -INT8_C(  69), -INT8_C(   9), -INT8_C(  36),  INT8_C(  29), -INT8_C(  75),  INT8_C(   0), -INT8_C(  19),  INT8_C(   0),
         INT8_C(   0),  INT8_C(   0),  INT8_C(  31), -INT8_C(  35),      INT8_MAX,  INT8_C(  22), -INT8_C( 104),  INT8_C(   0),
         INT8_C(   0),  INT8_C(  38),  INT8_C(   0),  INT8_C(   0), -INT8_C( 122),  INT8_C(  13), -INT8_C(  76),  INT8_C(  66),
         INT8_C(  93),  INT8_C( 105), -INT8_C( 127),  INT8_C(   0),  INT8_C(   0),  INT8_C(  86),  INT8_C(  29), -INT8_C(  58),
         INT8_C(   0), -INT8_C(  30),  INT8_C(   0),  INT8_C(  55),  INT8_C(   0),  INT8_C(  43), -INT8_C(   8), -INT8_C( 113),
         INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(  98), -INT8_C(  77),  INT8_C(   0), -INT8_C(  71),  INT8_C(   0),
         INT8_C(  44),  INT8_C(   0), -INT8_C( 124),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(  93),  INT8_C(  83) } },
    { UINT64_C( 3999732299541057129),
      {  INT8_C( 120), -INT8_C(   3),  INT8_C(  23),  INT8_C(  40), -INT8_C(  11), -INT8_C(  28), -INT8_C(  44),  INT8_C(  93),
         INT8_C(  19), -INT8_C(  90),  INT8_C(  56), -INT8_C(  23),  INT8_C( 116),  INT8_C(  26),  INT8_C( 115), -INT8_C(  91),
         INT8_C(  15), -INT8_C(  41), -INT8_C(  10), -INT8_C( 119),  INT8_C(  25),  INT8_C(  83), -INT8_C( 124), -INT8_C( 126),
         INT8_C(  97),  INT8_C(  81),  INT8_C(  64), -INT8_C(  74),  INT8_C(  56), -INT8_C(  62), -INT8_C(  18), -INT8_C(  79),
        -INT8_C(  65),  INT8_C(   5), -INT8_C(  39), -INT8_C(  76), -INT8_C(  22), -INT8_C(  83),  INT8_C(  17), -INT8_C(   3),
         INT8_C(  83),  INT8_C(  73), -INT8_C(  26), -INT8_C(  56),  INT8_C(  99),  INT8_C(  89),  INT8_C( 109),  INT8_C( 115),
         INT8_C(  48),  INT8_C(  99), -INT8_C(   4),  INT8_C(  74), -INT8_C(  74),      INT8_MIN, -INT8_C(  52),  INT8_C(  24),
        -INT8_C(  47),  INT8_C(  13), -INT8_C(  50),  INT8_C(   9), -INT8_C(  49), -INT8_C(  68), -INT8_C(  70), -INT8_C( 114) },
      { -INT64_C( 7734558248287431742),  INT64_C( 1834312950834040733), -INT64_C( 4469205869063344084),  INT64_C( 5159583129598085437),
        -INT64_C( 3535998400934454248),  INT64_C( 4480592424234600748), -INT64_C(   43879573592436045), -INT64_C( 3696991629114396956) },
      { -INT8_C( 108),  INT8_C(   0),  INT8_C(   0),  INT8_C(  84),  INT8_C(   0),  INT8_C(  68), -INT8_C(  60),  INT8_C(   0),
         INT8_C(   0),  INT8_C(  39),  INT8_C(  25),  INT8_C( 100),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
        -INT8_C(  58),  INT8_C(   0),  INT8_C(   7), -INT8_C(  72),  INT8_C(   0),  INT8_C(   0),  INT8_C(   2),  INT8_C(  11),
         INT8_C(   0),  INT8_C( 101),  INT8_C(  61),  INT8_C(  30),  INT8_C(  71),  INT8_C(  79),  INT8_C(   0), -INT8_C(  51),
         INT8_C(  49),  INT8_C(   0),  INT8_C(  44),  INT8_C(   0),  INT8_C( 103),  INT8_C(   0), -INT8_C(   7),  INT8_C(   0),
        -INT8_C(  71), -INT8_C(  92),  INT8_C(  12),  INT8_C(   0),  INT8_C(   0),  INT8_C(  10),  INT8_C( 114), -INT8_C(  59),
         INT8_C( 100),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(  93),
        -INT8_C( 123),  INT8_C(  89),  INT8_C(  44),  INT8_C(   0),  INT8_C(  22),  INT8_C(  76),  INT8_C(   0),  INT8_C(   0) } },
    { UINT64_C( 7890326620524094593),
      {  INT8_C(  91),  INT8_C(  79), -INT8_C( 126),  INT8_C( 109), -INT8_C( 110), -INT8_C(  80), -INT8_C(  85),  INT8_C(  69),
         INT8_C(  66), -INT8_C(  53), -INT8_C(  24),  INT8_C(   4), -INT8_C(  26),  INT8_C(  76),  INT8_C(   3), -INT8_C(  54),
         INT8_C( 122),  INT8_C(  14),  INT8_C(  52),  INT8_C(  46), -INT8_C(  77), -INT8_C(  27), -INT8_C(   6),  INT8_C(  53),
        -INT8_C( 119),  INT8_C(  31), -INT8_C(  25), -INT8_C(  54),  INT8_C(  49),  INT8_C( 103),  INT8_C(  55), -INT8_C( 116),
        -INT8_C(  74), -INT8_C(  71), -INT8_C(   7),  INT8_C(  72),  INT8_C( 106), -INT8_C(  92), -INT8_C( 115), -INT8_C(  84),
         INT8_C( 111),  INT8_C( 117), -INT8_C(  79),  INT8_C(  86), -INT8_C(  63), -INT8_C(  76),  INT8_C(  32),  INT8_C(  59),
        -INT8_C(  61),  INT8_C(  84),  INT8_C( 105),  INT8_C( 118),  INT8_C(  57),  INT8_C(  99), -INT8_C(  85), -INT8_C(  61),
        -INT8_C( 126), -INT8_C( 110), -INT8_C( 115), -INT8_C(  77), -INT8_C(   7), -INT8_C(  59),  INT8_C(  63), -INT8_C(  81) },
      {  INT64_C( 5518463002748598398), -INT64_C( 4758401574141540615),  INT64_C( 4977568043131756311), -INT64_C( 2009950796141452942),
        -INT64_C( 8027276458826329487),  INT64_C( 1540303634461047720), -INT64_C( 1897852231464151904),  INT64_C( 5432586736227164698) },
      { -INT8_C(  99),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(  61),
         INT8_C(   0),  INT8_C(   0), -INT8_C(  62),  INT8_C(   0),  INT8_C(   0),  INT8_C(  36),  INT8_C(   0), -INT8_C( 111),
        -INT8_C(  47),  INT8_C(   0),  INT8_C(  81),  INT8_C(   0),  INT8_C(   0), -INT8_C(   2),  INT8_C(   0),  INT8_C(   0),
         INT8_C(   0), -INT8_C(  52),  INT8_C(   0),  INT8_C(   0),  INT8_C(  13),  INT8_C( 112),  INT8_C(   0), -INT8_C( 102),
         INT8_C(  66),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C( 104),  INT8_C(   0),
         INT8_C(   0), -INT8_C(  85),  INT8_C(   0),  INT8_C(   0), -INT8_C(  44),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
         INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C( 108),
        -INT8_C( 122),  INT8_C(   0), -INT8_C( 115),  INT8_C( 108),  INT8_C(   0),  INT8_C(  16),  INT8_C(  52),  INT8_C(   0) } },
    { UINT64_C( 4298178501675659646),
      {  INT8_C( 110), -INT8_C(  15), -INT8_C(  34),  INT8_C( 108),  INT8_C(  50),  INT8_C(  62), -INT8_C( 127), -INT8_C(  46),
        -INT8_C(  46), -INT8_C(  26),  INT8_C(  54),  INT8_C(  69),  INT8_C(  95), -INT8_C(  33),  INT8_C(  43),  INT8_C( 121),
        -INT8_C( 127),  INT8_C( 124), -INT8_C(   7),  INT8_C(  91), -INT8_C(  24),  INT8_C(  94), -INT8_C(  89),  INT8_C( 102),
        -INT8_C( 113),  INT8_C(  64),  INT8_C( 124),  INT8_C(  35),  INT8_C( 114),  INT8_C(  34),  INT8_C(  94), -INT8_C(  32),
         INT8_C(  19),  INT8_C(  60),  INT8_C(  76),  INT8_C(  69),  INT8_C( 122), -INT8_C(  51),  INT8_C(  23),  INT8_C(  76),
        -INT8_C(  76),  INT8_C(  77), -INT8_C( 110),  INT8_C(  19),  INT8_C(  44), -INT8_C(  67), -INT8_C( 115), -INT8_C(  83),
         INT8_C(  57), -INT8_C( 122),  INT8_C(   9),  INT8_C(  33), -INT8_C(  28), -INT8_C(  80), -INT8_C( 121),  INT8_C( 116),
        -INT8_C(  16),  INT8_C(   3), -INT8_C( 105),  INT8_C(  98),  INT8_C(  37), -INT8_C(  11),  INT8_C(  67),  INT8_C(  56) },
      {  INT64_C( 1295230597404135218), -INT64_C( 9098202224145429534),  INT64_C( 7318394977445397816),  INT64_C( 5731687171329894189),
        -INT64_C( 9220851277733623654),  INT64_C( 1605616687360454015),  INT64_C( 4750386199887342097),  INT64_C( 6437647998180898027) },
      {  INT8_C(   0), -INT8_C(   4),  INT8_C( 118), -INT8_C( 103),  INT8_C( 126), -INT8_C(  56), -INT8_C( 103),  INT8_C(   0),
        -INT8_C(  55),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C( 112), -INT8_C( 112),  INT8_C(   0),  INT8_C(   0),
        -INT8_C( 100),  INT8_C(   0),  INT8_C(   0), -INT8_C(  93),  INT8_C(  41),  INT8_C(   0),  INT8_C(   0), -INT8_C(  91),
        -INT8_C( 112),  INT8_C(   0), -INT8_C(  44),  INT8_C(   0), -INT8_C(  30),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
        -INT8_C(   1), -INT8_C(  88),  INT8_C(   0),  INT8_C(   0), -INT8_C(  96),  INT8_C(   0),  INT8_C(   0), -INT8_C(  80),
         INT8_C(   0),  INT8_C( 121),  INT8_C(   0),  INT8_C(   0), -INT8_C( 124), -INT8_C(   8),  INT8_C(   0),  INT8_C(   0),
         INT8_C(   0), -INT8_C(  88), -INT8_C(  11),  INT8_C(   0),  INT8_C(   0), -INT8_C(  20),  INT8_C(   0),  INT8_C(  30),
         INT8_C(  87), -INT8_C(  99),  INT8_C(   0), -INT8_C(  81), -INT8_C(  11), -INT8_C(  54),  INT8_C(   0),  INT8_C(   0) } },
    { UINT64_C(14286642082697269799),
      { -INT8_C( 122), -INT8_C(  45), -INT8_C( 114),  INT8_C( 101),  INT8_C(  31), -INT8_C(  42),  INT8_C( 123),  INT8_C(  48),
        -INT8_C(  63), -INT8_C(  82), -INT8_C(  74), -INT8_C(  43),  INT8_C( 114), -INT8_C(  94),  INT8_C(  22),  INT8_C(  93),
         INT8_C(  86), -INT8_C(  87),  INT8_C( 101),  INT8_C(  21), -INT8_C(  56), -INT8_C(  68),  INT8_C( 111), -INT8_C(  17),
         INT8_C(  14), -INT8_C(  64), -INT8_C(  77),  INT8_C(  85),  INT8_C(  25), -INT8_C(   8),  INT8_C(  28), -INT8_C(  96),
        -INT8_C(  53), -INT8_C(  86),  INT8_C(   5), -INT8_C(  22),      INT8_MIN,      INT8_MIN,  INT8_C(  26),  INT8_C(  65),
         INT8_C(  47), -INT8_C(  47),  INT8_C(  22), -INT8_C(  95),  INT8_C( 115),  INT8_C(  44), -INT8_C(   2), -INT8_C(  54),
        -INT8_C(  42),  INT8_C(  99), -INT8_C(  33), -INT8_C(  98),  INT8_C(  31),  INT8_C(  78), -INT8_C( 115),  INT8_C(  45),
         INT8_C(  14),  INT8_C(  64), -INT8_C( 125),  INT8_C(  40),  INT8_C(  56), -INT8_C(  97), -INT8_C(  56),  INT8_C(   4) },
      {  INT64_C( 8938248115151883593),  INT64_C( 2600577332944904666),  INT64_C( 6110064479876347774),  INT64_C( 3948606761358610063),
        -INT64_C( 7072046955626513903), -INT64_C( 7881860010866902996),  INT64_C( 4509224382025982201),  INT64_C( 7236389956108029769) },
      {  INT8_C(  53),  INT8_C(  61), -INT8_C(  69),  INT8_C(   0),  INT8_C(   0),  INT8_C(  39),  INT8_C(   0),  INT8_C(   0),
         INT8_C(   0),  INT8_C(  92),  INT8_C(   0),  INT8_C(   0),  INT8_C(   5),  INT8_C(   0),  INT8_C(  52),  INT8_C(   0),
         INT8_C( 119),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(   9),  INT8_C(   0), -INT8_C( 106),  INT8_C(   0),
         INT8_C(   0),  INT8_C(   0), -INT8_C(  39),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(  36), -INT8_C(  19),
        -INT8_C(   9), -INT8_C(  62), -INT8_C(  48),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(  41),  INT8_C(   0),
         INT8_C(  60),  INT8_C(   0),  INT8_C(   0),  INT8_C(  10),  INT8_C(  83),  INT8_C(   0), -INT8_C(  78),  INT8_C(   0),
         INT8_C(   0),  INT8_C(   0),  INT8_C(  94),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C( 125),  INT8_C(   0),
         INT8_C(   0),  INT8_C(  73), -INT8_C(  23),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(  15), -INT8_C(  12) } },
    { UINT64_C(11740494410088082317),
      { -INT8_C( 106), -INT8_C(  39),  INT8_C(  28), -INT8_C(  86), -INT8_C(  37), -INT8_C(  70),  INT8_C(  60), -INT8_C(  43),
         INT8_C(  26),  INT8_C( 108),  INT8_C(  20), -INT8_C(  55),  INT8_C( 103), -INT8_C(  89),  INT8_C(   7), -INT8_C(  80),
        -INT8_C(  74),  INT8_C(  14), -INT8_C(  26),  INT8_C(   9), -INT8_C(  32),  INT8_C(  82),  INT8_C( 109),  INT8_C( 109),
        -INT8_C(  66),  INT8_C(  47), -INT8_C(  66),  INT8_C(  52), -INT8_C(  51), -INT8_C(  84), -INT8_C(  42),  INT8_C(  99),
        -INT8_C( 123), -INT8_C(  14),  INT8_C(  13),  INT8_C(  96), -INT8_C(  84),  INT8_C(  73),  INT8_C(  53), -INT8_C(  58),
        -INT8_C(  74),  INT8_C(  73), -INT8_C( 113),  INT8_C(  29), -INT8_C(  16), -INT8_C( 106), -INT8_C(  50), -INT8_C(  90),
        -INT8_C(  92), -INT8_C(  76), -INT8_C(  81), -INT8_C( 123),  INT8_C(   7),  INT8_C(  28), -INT8_C(  14), -INT8_C(  59),
         INT8_C(  76), -INT8_C(  80), -INT8_C(   7),  INT8_C(  25),  INT8_C(  92), -INT8_C(  49),  INT8_C( 124), -INT8_C(  31) },
      { -INT64_C( 8632424315079194175), -INT64_C(  191275059876805951),  INT64_C( 8139258125330024232),  INT64_C( 9035071584620637477),
        -INT64_C( 2456400114031614578),  INT64_C( 3113648718416416735),  INT64_C( 5801286316416808942), -INT64_C( 7028090346461328579) },
      { -INT8_C(  75),  INT8_C(   0),  INT8_C(  38), -INT8_C(  35),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C( 106),
         INT8_C(  44), -INT8_C( 121),  INT8_C(   0),  INT8_C(  97),  INT8_C(   0), -INT8_C(  24), -INT8_C( 123),  INT8_C(   0),
         INT8_C(   0),  INT8_C(   8),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(  93), -INT8_C(  93),
         INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(  79),  INT8_C(   0),  INT8_C(   6),  INT8_C(   0),
         INT8_C(   0),  INT8_C( 122),  INT8_C(  85),  INT8_C(   0), -INT8_C( 111),  INT8_C(  82), -INT8_C(  17),  INT8_C(   0),
        -INT8_C(  84),  INT8_C(   0),  INT8_C(  31),  INT8_C(  25),  INT8_C(  53),  INT8_C(   0),  INT8_C(   0), -INT8_C( 100),
         INT8_C(   0),  INT8_C(   8),  INT8_C(   4), -INT8_C(  65),  INT8_C(   0), -INT8_C(  79),  INT8_C(  32), -INT8_C(  65),
         INT8_C(   0),  INT8_C( 119),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(  92),  INT8_C(   0), -INT8_C( 120) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m512i a = simde_mm512_loadu_epi8(test_vec[i].a);
    simde__m512i b = simde_mm512_loadu_epi64(test_vec[i].b);
    simde__m512i r = simde_mm512_maskz_multishift_epi64_epi8(test_vec[i].k, a, b);
    simde_test_x86_assert_equal_i8x64(r, simde_mm512_loadu_epi8(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__mmask64 k = simde_test_x86_random_mmask64();
    simde__m512i a = simde_test_x86_random_i8x64();
    simde__m512i b = simde_test_x86_random_i64x8();
    simde__m512i r = simde_mm512_maskz_multishift_epi64_epi8(k, a, b);

    simde_test_x86_write_mmask64(2, k, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i8x64(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i64x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i8x64(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_multishift_epi64_epi8)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_mask_multishift_epi64_epi8)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_maskz_multishift_epi64_epi8)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_multishift_epi64_epi8)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_mask_multishift_epi64_epi8)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_maskz_multishift_epi64_epi8)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_multishift_epi64_epi8)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_mask_multishift_epi64_epi8)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_maskz_multishift_epi64_epi8)
SIMDE_TEST_FUNC_LIST_END

#include <test/x86/avx512/test-avx512-footer.h>
