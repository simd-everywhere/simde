#define SIMDE_TEST_X86_AVX512_INSN loadu

#include <test/x86/avx512/test-avx512.h>
#include <simde/x86/avx512/loadu.h>
#include <simde/x86/avx512/set.h>

static int
test_simde_mm_loadu_epi8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    SIMDE_ALIGN_LIKE_16(simde__m128i) const int8_t a[16];
    const int8_t r[16];
  } test_vec[] = {
    { {  INT8_C(  98),  INT8_C( 124), -INT8_C(  57), -INT8_C(  74),  INT8_C( 104),  INT8_C(  59),  INT8_C(  69), -INT8_C(  25),
         INT8_C(  20), -INT8_C(  48), -INT8_C(  57), -INT8_C(  59),  INT8_C(  21),  INT8_C( 119), -INT8_C(  97),  INT8_C(  28) },
      {  INT8_C(  98),  INT8_C( 124), -INT8_C(  57), -INT8_C(  74),  INT8_C( 104),  INT8_C(  59),  INT8_C(  69), -INT8_C(  25),
         INT8_C(  20), -INT8_C(  48), -INT8_C(  57), -INT8_C(  59),  INT8_C(  21),  INT8_C( 119), -INT8_C(  97),  INT8_C(  28) } },
    { {  INT8_C(  70), -INT8_C(  33),  INT8_C(  29),  INT8_C(  10),  INT8_C(  39),  INT8_C(  31), -INT8_C(  91),  INT8_C(  90),
         INT8_C( 111), -INT8_C(  46), -INT8_C(  65),  INT8_C( 124), -INT8_C(  81),  INT8_C(  57), -INT8_C(  34),  INT8_C(  17) },
      {  INT8_C(  70), -INT8_C(  33),  INT8_C(  29),  INT8_C(  10),  INT8_C(  39),  INT8_C(  31), -INT8_C(  91),  INT8_C(  90),
         INT8_C( 111), -INT8_C(  46), -INT8_C(  65),  INT8_C( 124), -INT8_C(  81),  INT8_C(  57), -INT8_C(  34),  INT8_C(  17) } },
    { { -INT8_C(  75), -INT8_C(  91), -INT8_C(  56),  INT8_C(  30), -INT8_C(  31),  INT8_C(  13),  INT8_C(   5), -INT8_C(  11),
        -INT8_C(  35), -INT8_C(  52), -INT8_C(  70), -INT8_C(  14),  INT8_C(  67),  INT8_C(  89),  INT8_C(  15), -INT8_C( 118) },
      { -INT8_C(  75), -INT8_C(  91), -INT8_C(  56),  INT8_C(  30), -INT8_C(  31),  INT8_C(  13),  INT8_C(   5), -INT8_C(  11),
        -INT8_C(  35), -INT8_C(  52), -INT8_C(  70), -INT8_C(  14),  INT8_C(  67),  INT8_C(  89),  INT8_C(  15), -INT8_C( 118) } },
    { {  INT8_C(  56),  INT8_C(  44), -INT8_C( 108),  INT8_C(  96),  INT8_C(  75),  INT8_C(  57), -INT8_C(  70), -INT8_C(  70),
         INT8_C(  12),  INT8_C( 121),  INT8_C(  55), -INT8_C(  69), -INT8_C(  78),  INT8_C(  21), -INT8_C(  51),  INT8_C( 104) },
      {  INT8_C(  56),  INT8_C(  44), -INT8_C( 108),  INT8_C(  96),  INT8_C(  75),  INT8_C(  57), -INT8_C(  70), -INT8_C(  70),
         INT8_C(  12),  INT8_C( 121),  INT8_C(  55), -INT8_C(  69), -INT8_C(  78),  INT8_C(  21), -INT8_C(  51),  INT8_C( 104) } },
    { { -INT8_C(  69), -INT8_C( 107), -INT8_C( 122), -INT8_C( 100), -INT8_C(  94), -INT8_C( 117), -INT8_C( 111),      INT8_MAX,
         INT8_C(  87),  INT8_C(  75),  INT8_C( 114), -INT8_C( 102), -INT8_C(  91), -INT8_C( 127),  INT8_C(  36), -INT8_C(  35) },
      { -INT8_C(  69), -INT8_C( 107), -INT8_C( 122), -INT8_C( 100), -INT8_C(  94), -INT8_C( 117), -INT8_C( 111),      INT8_MAX,
         INT8_C(  87),  INT8_C(  75),  INT8_C( 114), -INT8_C( 102), -INT8_C(  91), -INT8_C( 127),  INT8_C(  36), -INT8_C(  35) } },
    { { -INT8_C(  83), -INT8_C(  72),  INT8_C(  61), -INT8_C(   8), -INT8_C(  14), -INT8_C(   8), -INT8_C(  78), -INT8_C(   2),
         INT8_C( 113), -INT8_C(  23), -INT8_C(  71),  INT8_C(  36), -INT8_C(   1), -INT8_C( 122), -INT8_C( 116), -INT8_C(  70) },
      { -INT8_C(  83), -INT8_C(  72),  INT8_C(  61), -INT8_C(   8), -INT8_C(  14), -INT8_C(   8), -INT8_C(  78), -INT8_C(   2),
         INT8_C( 113), -INT8_C(  23), -INT8_C(  71),  INT8_C(  36), -INT8_C(   1), -INT8_C( 122), -INT8_C( 116), -INT8_C(  70) } },
    { {  INT8_C(  27),  INT8_C(  18),  INT8_C(  86), -INT8_C(  67), -INT8_C(  99), -INT8_C(  25),  INT8_C(  61), -INT8_C(  12),
         INT8_C(  50), -INT8_C(  81), -INT8_C( 114), -INT8_C(  41),  INT8_C(  48), -INT8_C(  77), -INT8_C(  75), -INT8_C(  35) },
      {  INT8_C(  27),  INT8_C(  18),  INT8_C(  86), -INT8_C(  67), -INT8_C(  99), -INT8_C(  25),  INT8_C(  61), -INT8_C(  12),
         INT8_C(  50), -INT8_C(  81), -INT8_C( 114), -INT8_C(  41),  INT8_C(  48), -INT8_C(  77), -INT8_C(  75), -INT8_C(  35) } },
    { {  INT8_C( 107), -INT8_C(  14), -INT8_C(  43),  INT8_C(  93), -INT8_C(  22), -INT8_C( 121),  INT8_C(  91),  INT8_C(  92),
         INT8_C( 113),  INT8_C(  21),      INT8_MIN,  INT8_C( 112), -INT8_C( 101),  INT8_C(  12),  INT8_C(  42), -INT8_C(  73) },
      {  INT8_C( 107), -INT8_C(  14), -INT8_C(  43),  INT8_C(  93), -INT8_C(  22), -INT8_C( 121),  INT8_C(  91),  INT8_C(  92),
         INT8_C( 113),  INT8_C(  21),      INT8_MIN,  INT8_C( 112), -INT8_C( 101),  INT8_C(  12),  INT8_C(  42), -INT8_C(  73) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_test_x86_assert_equal_i8x16(simde_mm_load_si128(SIMDE_ALIGN_CAST(simde__m128i const *, test_vec[i].a)), simde_mm_loadu_epi8(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m128i a = simde_test_x86_random_i8x16();
    simde__m128i r = a;

    simde_test_x86_write_i8x16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i8x16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_loadu_epi16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    SIMDE_ALIGN_LIKE_16(simde__m128i) const int16_t a[8];
    const int16_t r[8];
  } test_vec[] = {
    { { -INT16_C( 32738), -INT16_C( 17548), -INT16_C( 20121), -INT16_C( 26193),  INT16_C( 15712), -INT16_C( 28559),  INT16_C(  9968),  INT16_C( 23661) },
      { -INT16_C( 32738), -INT16_C( 17548), -INT16_C( 20121), -INT16_C( 26193),  INT16_C( 15712), -INT16_C( 28559),  INT16_C(  9968),  INT16_C( 23661) } },
    { {  INT16_C( 16920),  INT16_C(   953),  INT16_C(  5578),  INT16_C( 15199), -INT16_C(  8406), -INT16_C( 14933), -INT16_C( 10773),  INT16_C(  2428) },
      {  INT16_C( 16920),  INT16_C(   953),  INT16_C(  5578),  INT16_C( 15199), -INT16_C(  8406), -INT16_C( 14933), -INT16_C( 10773),  INT16_C(  2428) } },
    { { -INT16_C(  3755), -INT16_C( 17212),  INT16_C( 29602),  INT16_C(   853), -INT16_C( 14672), -INT16_C( 24173),  INT16_C(   492),  INT16_C(  1533) },
      { -INT16_C(  3755), -INT16_C( 17212),  INT16_C( 29602),  INT16_C(   853), -INT16_C( 14672), -INT16_C( 24173),  INT16_C(   492),  INT16_C(  1533) } },
    { { -INT16_C( 18877),  INT16_C(  3336),  INT16_C( 26571), -INT16_C(  2744), -INT16_C(  3258),  INT16_C( 12731),  INT16_C( 14280),  INT16_C(  7482) },
      { -INT16_C( 18877),  INT16_C(  3336),  INT16_C( 26571), -INT16_C(  2744), -INT16_C(  3258),  INT16_C( 12731),  INT16_C( 14280),  INT16_C(  7482) } },
    { { -INT16_C(   472), -INT16_C( 13351),  INT16_C( 12145),  INT16_C(  8654),  INT16_C( 25077), -INT16_C(  7486), -INT16_C( 16542), -INT16_C( 22809) },
      { -INT16_C(   472), -INT16_C( 13351),  INT16_C( 12145),  INT16_C(  8654),  INT16_C( 25077), -INT16_C(  7486), -INT16_C( 16542), -INT16_C( 22809) } },
    { { -INT16_C(  4234),  INT16_C( 16819), -INT16_C(   938), -INT16_C( 25545), -INT16_C(  3345), -INT16_C( 18227),  INT16_C(  1833),  INT16_C( 21205) },
      { -INT16_C(  4234),  INT16_C( 16819), -INT16_C(   938), -INT16_C( 25545), -INT16_C(  3345), -INT16_C( 18227),  INT16_C(  1833),  INT16_C( 21205) } },
    { { -INT16_C( 20731),  INT16_C( 30237), -INT16_C(  5154), -INT16_C( 11369),  INT16_C( 23116), -INT16_C( 20555), -INT16_C( 25575), -INT16_C( 28843) },
      { -INT16_C( 20731),  INT16_C( 30237), -INT16_C(  5154), -INT16_C( 11369),  INT16_C( 23116), -INT16_C( 20555), -INT16_C( 25575), -INT16_C( 28843) } },
    { {  INT16_C(  2187), -INT16_C(  7727),  INT16_C(  2052), -INT16_C(  2947),  INT16_C( 19194),  INT16_C(  9132), -INT16_C( 32431),  INT16_C( 22133) },
      {  INT16_C(  2187), -INT16_C(  7727),  INT16_C(  2052), -INT16_C(  2947),  INT16_C( 19194),  INT16_C(  9132), -INT16_C( 32431),  INT16_C( 22133) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_test_x86_assert_equal_i16x8(simde_mm_load_si128(SIMDE_ALIGN_CAST(simde__m128i const *, test_vec[i].a)), simde_mm_loadu_epi16(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m128i a = simde_test_x86_random_i16x8();
    simde__m128i r = a;

    simde_test_x86_write_i16x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i16x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_loadu_epi32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    SIMDE_ALIGN_LIKE_16(simde__m128i) const int32_t a[4];
    const int32_t r[4];
  } test_vec[] = {
    { {  INT32_C(   248287792), -INT32_C(   891132803), -INT32_C(   679897154), -INT32_C(  1083716044) },
      {  INT32_C(   248287792), -INT32_C(   891132803), -INT32_C(   679897154), -INT32_C(  1083716044) } },
    { { -INT32_C(   610191146),  INT32_C(   986652224), -INT32_C(  1168278679),  INT32_C(   756143100) },
      { -INT32_C(   610191146),  INT32_C(   986652224), -INT32_C(  1168278679),  INT32_C(   756143100) } },
    { { -INT32_C(   482615963), -INT32_C(     5431999), -INT32_C(   371775819), -INT32_C(   894943500) },
      { -INT32_C(   482615963), -INT32_C(     5431999), -INT32_C(   371775819), -INT32_C(   894943500) } },
    { { -INT32_C(  1230681738), -INT32_C(   772770712), -INT32_C(   326414865), -INT32_C(  2045141984) },
      { -INT32_C(  1230681738), -INT32_C(   772770712), -INT32_C(   326414865), -INT32_C(  2045141984) } },
    { { -INT32_C(  1150724998),  INT32_C(   666572402),  INT32_C(   806392380),  INT32_C(  1190836432) },
      { -INT32_C(  1150724998),  INT32_C(   666572402),  INT32_C(   806392380),  INT32_C(  1190836432) } },
    { {  INT32_C(  1794940930),  INT32_C(    71035924),  INT32_C(  1525728825), -INT32_C(   572520093) },
      {  INT32_C(  1794940930),  INT32_C(    71035924),  INT32_C(  1525728825), -INT32_C(   572520093) } },
    { { -INT32_C(   812103331), -INT32_C(  1678355617), -INT32_C(  1244985627), -INT32_C(  1040464449) },
      { -INT32_C(   812103331), -INT32_C(  1678355617), -INT32_C(  1244985627), -INT32_C(  1040464449) } },
    { {  INT32_C(  2049701733),  INT32_C(   494823139), -INT32_C(  1887998420), -INT32_C(   731097225) },
      {  INT32_C(  2049701733),  INT32_C(   494823139), -INT32_C(  1887998420), -INT32_C(   731097225) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_test_x86_assert_equal_i32x4(simde_mm_load_si128(SIMDE_ALIGN_CAST(simde__m128i const *, test_vec[i].a)), simde_mm_loadu_epi32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m128i a = simde_test_x86_random_i32x4();
    simde__m128i r = a;

    simde_test_x86_write_i32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_loadu_epi64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    SIMDE_ALIGN_LIKE_16(simde__m128i) const int64_t a[2];
    const int64_t r[2];
  } test_vec[] = {
    { {  INT64_C( 4511087683801712032), -INT64_C( 8060898892722248287) },
      {  INT64_C( 4511087683801712032), -INT64_C( 8060898892722248287) } },
    { { -INT64_C( 2384787176194159386),  INT64_C( 6143431839469952758) },
      { -INT64_C( 2384787176194159386),  INT64_C( 6143431839469952758) } },
    { {  INT64_C( 2411376884971791839),  INT64_C( 4543466100033153363) },
      {  INT64_C( 2411376884971791839),  INT64_C( 4543466100033153363) } },
    { { -INT64_C( 7674432146617329682), -INT64_C( 6460338043923272626) },
      { -INT64_C( 7674432146617329682), -INT64_C( 6460338043923272626) } },
    { { -INT64_C( 1312143318173438935), -INT64_C( 2642072646704280642) },
      { -INT64_C( 1312143318173438935), -INT64_C( 2642072646704280642) } },
    { { -INT64_C( 7150315094646497649),  INT64_C( 3770910417545578470) },
      { -INT64_C( 7150315094646497649),  INT64_C( 3770910417545578470) } },
    { {  INT64_C( 4983981236450898595), -INT64_C( 7152365960020912652) },
      {  INT64_C( 4983981236450898595), -INT64_C( 7152365960020912652) } },
    { {  INT64_C( 1871967141139003407),  INT64_C( 3861302942246541911) },
      {  INT64_C( 1871967141139003407),  INT64_C( 3861302942246541911) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_test_x86_assert_equal_i64x2(simde_mm_load_si128(SIMDE_ALIGN_CAST(simde__m128i const *, test_vec[i].a)), simde_mm_loadu_epi64(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m128i a = simde_test_x86_random_i64x2();
    simde__m128i r = a;

    simde_test_x86_write_i64x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm256_loadu_epi8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    SIMDE_ALIGN_LIKE_32(simde__m256i) const int8_t a[32];
    const int8_t r[32];
  } test_vec[] = {
    { {  INT8_C(  29), -INT8_C(  94),  INT8_C(  76),  INT8_C(  20),  INT8_C(  54), -INT8_C(  63),      INT8_MAX,  INT8_C(  69),
        -INT8_C(   2),  INT8_C( 122),  INT8_C(  91),  INT8_C(  14),  INT8_C( 107),  INT8_C( 122), -INT8_C(  75),  INT8_C( 113),
         INT8_C(  74), -INT8_C(  31), -INT8_C(  17), -INT8_C(  25),  INT8_C(  39),  INT8_C(  64), -INT8_C(  71),  INT8_C( 123),
             INT8_MAX, -INT8_C(  97), -INT8_C( 125), -INT8_C(  43), -INT8_C(  70), -INT8_C( 126),  INT8_C( 107), -INT8_C(  41) },
      {  INT8_C(  29), -INT8_C(  94),  INT8_C(  76),  INT8_C(  20),  INT8_C(  54), -INT8_C(  63),      INT8_MAX,  INT8_C(  69),
        -INT8_C(   2),  INT8_C( 122),  INT8_C(  91),  INT8_C(  14),  INT8_C( 107),  INT8_C( 122), -INT8_C(  75),  INT8_C( 113),
         INT8_C(  74), -INT8_C(  31), -INT8_C(  17), -INT8_C(  25),  INT8_C(  39),  INT8_C(  64), -INT8_C(  71),  INT8_C( 123),
             INT8_MAX, -INT8_C(  97), -INT8_C( 125), -INT8_C(  43), -INT8_C(  70), -INT8_C( 126),  INT8_C( 107), -INT8_C(  41) } },
    { {  INT8_C(  37), -INT8_C(  73), -INT8_C(  21),  INT8_C(  91),  INT8_C( 121),  INT8_C( 107), -INT8_C(  96),  INT8_C( 119),
        -INT8_C(  27), -INT8_C(   5), -INT8_C( 123),  INT8_C(  80),  INT8_C( 118),  INT8_C(  59), -INT8_C(  63), -INT8_C(  64),
         INT8_C(  28), -INT8_C(  80), -INT8_C(  89),  INT8_C(  67), -INT8_C(  16),  INT8_C(  96), -INT8_C(  65),  INT8_C( 112),
        -INT8_C(   1),  INT8_C(  66),  INT8_C(  69), -INT8_C(  71), -INT8_C(  59), -INT8_C(  80), -INT8_C( 111), -INT8_C(  22) },
      {  INT8_C(  37), -INT8_C(  73), -INT8_C(  21),  INT8_C(  91),  INT8_C( 121),  INT8_C( 107), -INT8_C(  96),  INT8_C( 119),
        -INT8_C(  27), -INT8_C(   5), -INT8_C( 123),  INT8_C(  80),  INT8_C( 118),  INT8_C(  59), -INT8_C(  63), -INT8_C(  64),
         INT8_C(  28), -INT8_C(  80), -INT8_C(  89),  INT8_C(  67), -INT8_C(  16),  INT8_C(  96), -INT8_C(  65),  INT8_C( 112),
        -INT8_C(   1),  INT8_C(  66),  INT8_C(  69), -INT8_C(  71), -INT8_C(  59), -INT8_C(  80), -INT8_C( 111), -INT8_C(  22) } },
    { {  INT8_C( 103),  INT8_C( 124),  INT8_C(  69), -INT8_C(  32), -INT8_C(  25), -INT8_C(  27),  INT8_C(  87), -INT8_C(  52),
        -INT8_C(  31), -INT8_C(  35),  INT8_C(  28),  INT8_C(  87),  INT8_C(  24), -INT8_C(  34),  INT8_C(  23),  INT8_C(  52),
        -INT8_C( 114), -INT8_C(  66),  INT8_C( 120),      INT8_MAX,  INT8_C(  30),  INT8_C(  55), -INT8_C(  17),  INT8_C(  29),
         INT8_C( 121),  INT8_C(  52), -INT8_C(  42),  INT8_C(  62), -INT8_C(  28),  INT8_C( 103),  INT8_C(  40),  INT8_C(  75) },
      {  INT8_C( 103),  INT8_C( 124),  INT8_C(  69), -INT8_C(  32), -INT8_C(  25), -INT8_C(  27),  INT8_C(  87), -INT8_C(  52),
        -INT8_C(  31), -INT8_C(  35),  INT8_C(  28),  INT8_C(  87),  INT8_C(  24), -INT8_C(  34),  INT8_C(  23),  INT8_C(  52),
        -INT8_C( 114), -INT8_C(  66),  INT8_C( 120),      INT8_MAX,  INT8_C(  30),  INT8_C(  55), -INT8_C(  17),  INT8_C(  29),
         INT8_C( 121),  INT8_C(  52), -INT8_C(  42),  INT8_C(  62), -INT8_C(  28),  INT8_C( 103),  INT8_C(  40),  INT8_C(  75) } },
    { { -INT8_C(  28),  INT8_C( 109),  INT8_C(  44), -INT8_C(  53),  INT8_C(  83), -INT8_C( 125), -INT8_C( 104),  INT8_C(  52),
         INT8_C(  96), -INT8_C(  76), -INT8_C( 117),  INT8_C( 120), -INT8_C( 110), -INT8_C(  94), -INT8_C(  83),  INT8_C(  33),
         INT8_C(  96),  INT8_C(  37), -INT8_C(  96),  INT8_C( 126),  INT8_C(  92), -INT8_C( 113), -INT8_C( 101), -INT8_C(  43),
        -INT8_C(  61),  INT8_C( 113),  INT8_C(  20), -INT8_C(  89), -INT8_C(  39),  INT8_C(  60), -INT8_C(  14), -INT8_C(  67) },
      { -INT8_C(  28),  INT8_C( 109),  INT8_C(  44), -INT8_C(  53),  INT8_C(  83), -INT8_C( 125), -INT8_C( 104),  INT8_C(  52),
         INT8_C(  96), -INT8_C(  76), -INT8_C( 117),  INT8_C( 120), -INT8_C( 110), -INT8_C(  94), -INT8_C(  83),  INT8_C(  33),
         INT8_C(  96),  INT8_C(  37), -INT8_C(  96),  INT8_C( 126),  INT8_C(  92), -INT8_C( 113), -INT8_C( 101), -INT8_C(  43),
        -INT8_C(  61),  INT8_C( 113),  INT8_C(  20), -INT8_C(  89), -INT8_C(  39),  INT8_C(  60), -INT8_C(  14), -INT8_C(  67) } },
    { { -INT8_C(  86),  INT8_C(  30), -INT8_C( 120), -INT8_C(   3), -INT8_C(  94),  INT8_C(  32),  INT8_C(  49),  INT8_C(   2),
        -INT8_C(  43), -INT8_C(  68),  INT8_C( 123),  INT8_C( 103),  INT8_C(  94),  INT8_C(  40), -INT8_C( 120), -INT8_C(  66),
         INT8_C(  77),  INT8_C(  40),  INT8_C(  60), -INT8_C(  87), -INT8_C(  73), -INT8_C(  41),  INT8_C( 126),  INT8_C( 122),
         INT8_C(  72), -INT8_C( 110),  INT8_C(  33),  INT8_C(  33), -INT8_C(  49),  INT8_C(  20), -INT8_C(  34),  INT8_C( 121) },
      { -INT8_C(  86),  INT8_C(  30), -INT8_C( 120), -INT8_C(   3), -INT8_C(  94),  INT8_C(  32),  INT8_C(  49),  INT8_C(   2),
        -INT8_C(  43), -INT8_C(  68),  INT8_C( 123),  INT8_C( 103),  INT8_C(  94),  INT8_C(  40), -INT8_C( 120), -INT8_C(  66),
         INT8_C(  77),  INT8_C(  40),  INT8_C(  60), -INT8_C(  87), -INT8_C(  73), -INT8_C(  41),  INT8_C( 126),  INT8_C( 122),
         INT8_C(  72), -INT8_C( 110),  INT8_C(  33),  INT8_C(  33), -INT8_C(  49),  INT8_C(  20), -INT8_C(  34),  INT8_C( 121) } },
    { {  INT8_C(  50),  INT8_C( 103),  INT8_C( 118), -INT8_C(  44), -INT8_C( 121), -INT8_C(  89), -INT8_C(  41),  INT8_C(  92),
         INT8_C(  99),  INT8_C(  82), -INT8_C(  60), -INT8_C(  63),  INT8_C( 122),  INT8_C(  76),      INT8_MAX, -INT8_C(  57),
         INT8_C( 117), -INT8_C(  69),  INT8_C( 112),  INT8_C(  44), -INT8_C( 110), -INT8_C(  18), -INT8_C(  89), -INT8_C(  38),
        -INT8_C( 127), -INT8_C(  56), -INT8_C(   4),  INT8_C(  80), -INT8_C(  36), -INT8_C(  38), -INT8_C(  55),  INT8_C(  15) },
      {  INT8_C(  50),  INT8_C( 103),  INT8_C( 118), -INT8_C(  44), -INT8_C( 121), -INT8_C(  89), -INT8_C(  41),  INT8_C(  92),
         INT8_C(  99),  INT8_C(  82), -INT8_C(  60), -INT8_C(  63),  INT8_C( 122),  INT8_C(  76),      INT8_MAX, -INT8_C(  57),
         INT8_C( 117), -INT8_C(  69),  INT8_C( 112),  INT8_C(  44), -INT8_C( 110), -INT8_C(  18), -INT8_C(  89), -INT8_C(  38),
        -INT8_C( 127), -INT8_C(  56), -INT8_C(   4),  INT8_C(  80), -INT8_C(  36), -INT8_C(  38), -INT8_C(  55),  INT8_C(  15) } },
    { {  INT8_C(  65),  INT8_C(  63), -INT8_C(  29), -INT8_C(  55), -INT8_C(  26), -INT8_C(  70),  INT8_C(  37),  INT8_C(  73),
         INT8_C(  12), -INT8_C(  23),  INT8_C(  10), -INT8_C( 122),  INT8_C(  54), -INT8_C( 119),  INT8_C(  77), -INT8_C(  85),
         INT8_C(  68), -INT8_C(  67), -INT8_C(  41), -INT8_C(  42), -INT8_C(  84),  INT8_C( 126), -INT8_C(  80),  INT8_C(  45),
         INT8_C(  71), -INT8_C(  84),  INT8_C( 125),  INT8_C(  35), -INT8_C( 121),  INT8_C(  70),  INT8_C(  50), -INT8_C(  56) },
      {  INT8_C(  65),  INT8_C(  63), -INT8_C(  29), -INT8_C(  55), -INT8_C(  26), -INT8_C(  70),  INT8_C(  37),  INT8_C(  73),
         INT8_C(  12), -INT8_C(  23),  INT8_C(  10), -INT8_C( 122),  INT8_C(  54), -INT8_C( 119),  INT8_C(  77), -INT8_C(  85),
         INT8_C(  68), -INT8_C(  67), -INT8_C(  41), -INT8_C(  42), -INT8_C(  84),  INT8_C( 126), -INT8_C(  80),  INT8_C(  45),
         INT8_C(  71), -INT8_C(  84),  INT8_C( 125),  INT8_C(  35), -INT8_C( 121),  INT8_C(  70),  INT8_C(  50), -INT8_C(  56) } },
    { { -INT8_C( 123),  INT8_C(  22), -INT8_C( 111),  INT8_C( 107), -INT8_C(  48), -INT8_C(  73), -INT8_C(  76), -INT8_C(  35),
        -INT8_C(  96), -INT8_C(  66),  INT8_C(  99), -INT8_C(  42),  INT8_C(  71), -INT8_C(  79), -INT8_C( 127), -INT8_C( 117),
         INT8_C( 110),  INT8_C(  89),  INT8_C(  97),  INT8_C(  26), -INT8_C(  41),  INT8_C(  17),  INT8_C(  71),  INT8_C(  30),
        -INT8_C(  66), -INT8_C(  60),  INT8_C(  66),  INT8_C(  69),  INT8_C(  10),  INT8_C( 116),  INT8_C(  13), -INT8_C( 113) },
      { -INT8_C( 123),  INT8_C(  22), -INT8_C( 111),  INT8_C( 107), -INT8_C(  48), -INT8_C(  73), -INT8_C(  76), -INT8_C(  35),
        -INT8_C(  96), -INT8_C(  66),  INT8_C(  99), -INT8_C(  42),  INT8_C(  71), -INT8_C(  79), -INT8_C( 127), -INT8_C( 117),
         INT8_C( 110),  INT8_C(  89),  INT8_C(  97),  INT8_C(  26), -INT8_C(  41),  INT8_C(  17),  INT8_C(  71),  INT8_C(  30),
        -INT8_C(  66), -INT8_C(  60),  INT8_C(  66),  INT8_C(  69),  INT8_C(  10),  INT8_C( 116),  INT8_C(  13), -INT8_C( 113) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_test_x86_assert_equal_i8x32(simde_mm256_load_si256(SIMDE_ALIGN_CAST(simde__m256i const *, test_vec[i].a)), simde_mm256_loadu_epi8(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m256i a = simde_test_x86_random_i8x32();
    simde__m256i r = a;

    simde_test_x86_write_i8x32(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i8x32(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm256_loadu_epi16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    SIMDE_ALIGN_LIKE_32(simde__m256i) const int16_t a[16];
    const int16_t r[16];
  } test_vec[] = {
    { { -INT16_C( 24694),  INT16_C( 23546), -INT16_C( 20906), -INT16_C(  2504), -INT16_C( 25748), -INT16_C( 19507),  INT16_C( 20044), -INT16_C( 17602),
        -INT16_C( 24665),  INT16_C( 32725),  INT16_C(  7601),  INT16_C( 28573), -INT16_C(  8223), -INT16_C(  4940), -INT16_C( 16044), -INT16_C(  8581) },
      { -INT16_C( 24694),  INT16_C( 23546), -INT16_C( 20906), -INT16_C(  2504), -INT16_C( 25748), -INT16_C( 19507),  INT16_C( 20044), -INT16_C( 17602),
        -INT16_C( 24665),  INT16_C( 32725),  INT16_C(  7601),  INT16_C( 28573), -INT16_C(  8223), -INT16_C(  4940), -INT16_C( 16044), -INT16_C(  8581) } },
    { {  INT16_C( 30304), -INT16_C( 18887),  INT16_C( 28964), -INT16_C( 28243),  INT16_C( 31245),  INT16_C( 22852), -INT16_C( 31800),  INT16_C( 28692),
        -INT16_C(  5598), -INT16_C( 11281), -INT16_C( 29689), -INT16_C(  6078), -INT16_C(  2452), -INT16_C( 16172),  INT16_C( 20664),  INT16_C(  6302) },
      {  INT16_C( 30304), -INT16_C( 18887),  INT16_C( 28964), -INT16_C( 28243),  INT16_C( 31245),  INT16_C( 22852), -INT16_C( 31800),  INT16_C( 28692),
        -INT16_C(  5598), -INT16_C( 11281), -INT16_C( 29689), -INT16_C(  6078), -INT16_C(  2452), -INT16_C( 16172),  INT16_C( 20664),  INT16_C(  6302) } },
    { { -INT16_C( 10042), -INT16_C(  5425),  INT16_C( 31817),  INT16_C( 22139), -INT16_C( 16138), -INT16_C( 16720), -INT16_C( 15293),  INT16_C( 25902),
         INT16_C(  7598), -INT16_C( 19143),  INT16_C( 31658),  INT16_C(  5790),  INT16_C( 29298),  INT16_C( 10966),  INT16_C( 29890), -INT16_C( 30654) },
      { -INT16_C( 10042), -INT16_C(  5425),  INT16_C( 31817),  INT16_C( 22139), -INT16_C( 16138), -INT16_C( 16720), -INT16_C( 15293),  INT16_C( 25902),
         INT16_C(  7598), -INT16_C( 19143),  INT16_C( 31658),  INT16_C(  5790),  INT16_C( 29298),  INT16_C( 10966),  INT16_C( 29890), -INT16_C( 30654) } },
    { {  INT16_C(  4428), -INT16_C( 27021), -INT16_C(  4467), -INT16_C( 31764), -INT16_C( 25426), -INT16_C(  3774),  INT16_C( 28769),  INT16_C(  3927),
        -INT16_C( 28530),  INT16_C( 14533),  INT16_C( 25355),  INT16_C( 32078),  INT16_C(  9429), -INT16_C( 26457), -INT16_C(  5480), -INT16_C(  6880) },
      {  INT16_C(  4428), -INT16_C( 27021), -INT16_C(  4467), -INT16_C( 31764), -INT16_C( 25426), -INT16_C(  3774),  INT16_C( 28769),  INT16_C(  3927),
        -INT16_C( 28530),  INT16_C( 14533),  INT16_C( 25355),  INT16_C( 32078),  INT16_C(  9429), -INT16_C( 26457), -INT16_C(  5480), -INT16_C(  6880) } },
    { { -INT16_C( 27653), -INT16_C( 30341),  INT16_C( 26498),  INT16_C( 12300),  INT16_C( 19972),  INT16_C( 25890),  INT16_C( 31167),  INT16_C( 19828),
         INT16_C( 14601),  INT16_C(  5253), -INT16_C( 11364),  INT16_C( 29330),  INT16_C( 14839), -INT16_C( 28918),  INT16_C( 10787),  INT16_C(  8052) },
      { -INT16_C( 27653), -INT16_C( 30341),  INT16_C( 26498),  INT16_C( 12300),  INT16_C( 19972),  INT16_C( 25890),  INT16_C( 31167),  INT16_C( 19828),
         INT16_C( 14601),  INT16_C(  5253), -INT16_C( 11364),  INT16_C( 29330),  INT16_C( 14839), -INT16_C( 28918),  INT16_C( 10787),  INT16_C(  8052) } },
    { { -INT16_C(  4162),  INT16_C( 16552), -INT16_C( 19369),  INT16_C( 23408), -INT16_C( 28157), -INT16_C( 15680),  INT16_C( 13323),  INT16_C(  5135),
        -INT16_C( 27538),  INT16_C(  2601), -INT16_C( 17561),  INT16_C( 24188), -INT16_C( 30988),  INT16_C(  6381),  INT16_C( 25265),  INT16_C( 28471) },
      { -INT16_C(  4162),  INT16_C( 16552), -INT16_C( 19369),  INT16_C( 23408), -INT16_C( 28157), -INT16_C( 15680),  INT16_C( 13323),  INT16_C(  5135),
        -INT16_C( 27538),  INT16_C(  2601), -INT16_C( 17561),  INT16_C( 24188), -INT16_C( 30988),  INT16_C(  6381),  INT16_C( 25265),  INT16_C( 28471) } },
    { { -INT16_C(  8367), -INT16_C( 22353),  INT16_C(  8083), -INT16_C( 27133), -INT16_C( 15438), -INT16_C( 17064),  INT16_C( 26616),  INT16_C( 26322),
        -INT16_C(  1029),  INT16_C( 25200), -INT16_C(  4682), -INT16_C( 21824), -INT16_C( 20877),  INT16_C(  9410), -INT16_C(  1776),  INT16_C( 24979) },
      { -INT16_C(  8367), -INT16_C( 22353),  INT16_C(  8083), -INT16_C( 27133), -INT16_C( 15438), -INT16_C( 17064),  INT16_C( 26616),  INT16_C( 26322),
        -INT16_C(  1029),  INT16_C( 25200), -INT16_C(  4682), -INT16_C( 21824), -INT16_C( 20877),  INT16_C(  9410), -INT16_C(  1776),  INT16_C( 24979) } },
    { {  INT16_C( 17112),  INT16_C( 27658),  INT16_C(  3426),  INT16_C(  5122),  INT16_C( 23505), -INT16_C( 13871), -INT16_C( 23614), -INT16_C( 16849),
        -INT16_C( 24674),  INT16_C( 21536), -INT16_C(  7796),  INT16_C(   255), -INT16_C( 15985), -INT16_C( 24796), -INT16_C( 18245), -INT16_C( 27904) },
      {  INT16_C( 17112),  INT16_C( 27658),  INT16_C(  3426),  INT16_C(  5122),  INT16_C( 23505), -INT16_C( 13871), -INT16_C( 23614), -INT16_C( 16849),
        -INT16_C( 24674),  INT16_C( 21536), -INT16_C(  7796),  INT16_C(   255), -INT16_C( 15985), -INT16_C( 24796), -INT16_C( 18245), -INT16_C( 27904) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_test_x86_assert_equal_i16x16(simde_mm256_load_si256(SIMDE_ALIGN_CAST(simde__m256i const *, test_vec[i].a)), simde_mm256_loadu_epi16(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m256i a = simde_test_x86_random_i16x16();
    simde__m256i r = a;

    simde_test_x86_write_i16x16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i16x16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm256_maskz_loadu_epi16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask16 k;
    SIMDE_ALIGN_LIKE_32(simde__m256i) const int16_t a[16];
    const int16_t r[16];
  } test_vec[] = {
    { UINT16_C(59107),
      { -INT16_C( 14944),  INT16_C(  6511), -INT16_C( 24883),  INT16_C( 24697),  INT16_C( 10614), -INT16_C( 12384), -INT16_C( 19130), -INT16_C( 23475),
        -INT16_C(  5657), -INT16_C( 18548),  INT16_C( 31282), -INT16_C( 23251),  INT16_C( 20678),  INT16_C( 28405), -INT16_C(  9994), -INT16_C( 27052) },
      { -INT16_C( 14944),  INT16_C(  6511),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C( 12384), -INT16_C( 19130), -INT16_C( 23475),
         INT16_C(     0), -INT16_C( 18548),  INT16_C( 31282),  INT16_C(     0),  INT16_C(     0),  INT16_C( 28405), -INT16_C(  9994), -INT16_C( 27052) } },
    { UINT16_C(50077),
      {  INT16_C( 27311),  INT16_C( 10593), -INT16_C( 10293),  INT16_C( 27474), -INT16_C( 26457), -INT16_C(  3039),  INT16_C(  2109), -INT16_C( 13859),
         INT16_C(  4287), -INT16_C(  4797),  INT16_C(  2485), -INT16_C( 21955),  INT16_C( 13175), -INT16_C( 13438),  INT16_C(  8138),  INT16_C( 31119) },
      {  INT16_C( 27311),  INT16_C(     0), -INT16_C( 10293),  INT16_C( 27474), -INT16_C( 26457),  INT16_C(     0),  INT16_C(     0), -INT16_C( 13859),
         INT16_C(  4287), -INT16_C(  4797),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(  8138),  INT16_C( 31119) } },
    { UINT16_C(61577),
      {  INT16_C( 21666), -INT16_C(  2616),  INT16_C( 28608), -INT16_C(  7795), -INT16_C( 13725),  INT16_C( 16617), -INT16_C( 22125), -INT16_C( 10416),
         INT16_C(  1430), -INT16_C( 11296),  INT16_C( 22703),  INT16_C( 12551), -INT16_C( 11997), -INT16_C( 19888), -INT16_C(  9654), -INT16_C(  4701) },
      {  INT16_C( 21666),  INT16_C(     0),  INT16_C(     0), -INT16_C(  7795),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C( 10416),
         INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C( 11997), -INT16_C( 19888), -INT16_C(  9654), -INT16_C(  4701) } },
    { UINT16_C(27438),
      { -INT16_C(  4382),  INT16_C( 28634),  INT16_C( 15823), -INT16_C( 18118), -INT16_C( 12931), -INT16_C( 12702), -INT16_C(  1884), -INT16_C( 31277),
        -INT16_C( 31797), -INT16_C( 11555),  INT16_C(   180),  INT16_C(  1443), -INT16_C(  4429),  INT16_C( 22239),  INT16_C(  3547), -INT16_C( 16959) },
      {  INT16_C(     0),  INT16_C( 28634),  INT16_C( 15823), -INT16_C( 18118),  INT16_C(     0), -INT16_C( 12702),  INT16_C(     0),  INT16_C(     0),
        -INT16_C( 31797), -INT16_C( 11555),  INT16_C(     0),  INT16_C(  1443),  INT16_C(     0),  INT16_C( 22239),  INT16_C(  3547),  INT16_C(     0) } },
    { UINT16_C(39932),
      { -INT16_C( 13524),  INT16_C( 26328),  INT16_C( 21892), -INT16_C(  6604), -INT16_C( 10205), -INT16_C(  2082), -INT16_C( 21923),  INT16_C( 14970),
         INT16_C( 11900),  INT16_C(  8251), -INT16_C(  4557),  INT16_C(  4622), -INT16_C(  5820),  INT16_C(  1312),  INT16_C(  7334), -INT16_C( 11616) },
      {  INT16_C(     0),  INT16_C(     0),  INT16_C( 21892), -INT16_C(  6604), -INT16_C( 10205), -INT16_C(  2082), -INT16_C( 21923),  INT16_C( 14970),
         INT16_C( 11900),  INT16_C(  8251),  INT16_C(     0),  INT16_C(  4622), -INT16_C(  5820),  INT16_C(     0),  INT16_C(     0), -INT16_C( 11616) } },
    { UINT16_C(30951),
      {  INT16_C( 27705),  INT16_C( 28109), -INT16_C(  3758),  INT16_C( 12613), -INT16_C( 23576),  INT16_C( 25307),  INT16_C( 22493),  INT16_C(  6288),
        -INT16_C( 15241), -INT16_C( 31482),  INT16_C( 19158), -INT16_C(  2450),  INT16_C(  5199), -INT16_C(  4334), -INT16_C(  1305),  INT16_C(  8295) },
      {  INT16_C( 27705),  INT16_C( 28109), -INT16_C(  3758),  INT16_C(     0),  INT16_C(     0),  INT16_C( 25307),  INT16_C( 22493),  INT16_C(  6288),
         INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(  2450),  INT16_C(  5199), -INT16_C(  4334), -INT16_C(  1305),  INT16_C(     0) } },
    { UINT16_C(13670),
      { -INT16_C( 18291), -INT16_C( 11738),  INT16_C(  3817), -INT16_C( 15243),  INT16_C( 21360),  INT16_C(    28), -INT16_C( 27797),  INT16_C( 29380),
        -INT16_C( 25831), -INT16_C( 30788),  INT16_C(  3217), -INT16_C( 23396), -INT16_C( 31749),  INT16_C( 25502),  INT16_C(  1187),  INT16_C( 12440) },
      {  INT16_C(     0), -INT16_C( 11738),  INT16_C(  3817),  INT16_C(     0),  INT16_C(     0),  INT16_C(    28), -INT16_C( 27797),  INT16_C(     0),
        -INT16_C( 25831),  INT16_C(     0),  INT16_C(  3217),  INT16_C(     0), -INT16_C( 31749),  INT16_C( 25502),  INT16_C(     0),  INT16_C(     0) } },
    { UINT16_C(48828),
      { -INT16_C( 23038),  INT16_C( 30924),  INT16_C( 15466), -INT16_C( 31029),  INT16_C( 13884),  INT16_C(   282),  INT16_C( 13224),  INT16_C( 26012),
         INT16_C( 11706),  INT16_C( 22129),  INT16_C( 27857),  INT16_C( 28633),  INT16_C( 31951),  INT16_C( 26483),  INT16_C( 12460), -INT16_C( 20699) },
      {  INT16_C(     0),  INT16_C(     0),  INT16_C( 15466), -INT16_C( 31029),  INT16_C( 13884),  INT16_C(   282),  INT16_C(     0),  INT16_C( 26012),
         INT16_C(     0),  INT16_C( 22129),  INT16_C( 27857),  INT16_C( 28633),  INT16_C( 31951),  INT16_C( 26483),  INT16_C(     0), -INT16_C( 20699) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_test_x86_assert_equal_i16x16(simde_mm256_load_si256(SIMDE_ALIGN_CAST(simde__m256i const *, test_vec[i].r)), simde_mm256_maskz_loadu_epi16(test_vec[i].k, test_vec[i].a));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__mmask16 k = simde_test_x86_random_mmask16();
    simde__m256i a = simde_test_x86_random_i16x16();
    simde__m256i r = simde_mm256_maskz_loadu_epi16(k, &a);

    simde_test_x86_write_mmask16(2, k, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i16x16(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i16x16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm256_loadu_epi32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    SIMDE_ALIGN_LIKE_32(simde__m256i) const int32_t a[8];
    const int32_t r[8];
  } test_vec[] = {
    { {  INT32_C(  1560218362), -INT32_C(   378535400),  INT32_C(   531776093), -INT32_C(  2065833499),  INT32_C(   232324736),  INT32_C(  1846400991),  INT32_C(  1410150809), -INT32_C(   454619671) },
      {  INT32_C(  1560218362), -INT32_C(   378535400),  INT32_C(   531776093), -INT32_C(  2065833499),  INT32_C(   232324736),  INT32_C(  1846400991),  INT32_C(  1410150809), -INT32_C(   454619671) } },
    { {  INT32_C(   809559832),  INT32_C(  1176089065), -INT32_C(   664417293),  INT32_C(   744244140),  INT32_C(   540620097), -INT32_C(  1517402612),  INT32_C(  1643748216), -INT32_C(  1069162072) },
      {  INT32_C(   809559832),  INT32_C(  1176089065), -INT32_C(   664417293),  INT32_C(   744244140),  INT32_C(   540620097), -INT32_C(  1517402612),  INT32_C(  1643748216), -INT32_C(  1069162072) } },
    { { -INT32_C(  1309636920),  INT32_C(   720832823), -INT32_C(  2147328812), -INT32_C(   525508705), -INT32_C(  1610553708), -INT32_C(  1522102739), -INT32_C(   771342551), -INT32_C(   393065440) },
      { -INT32_C(  1309636920),  INT32_C(   720832823), -INT32_C(  2147328812), -INT32_C(   525508705), -INT32_C(  1610553708), -INT32_C(  1522102739), -INT32_C(   771342551), -INT32_C(   393065440) } },
    { {  INT32_C(   161055698),  INT32_C(  1630769292), -INT32_C(  1931397651),  INT32_C(   678268564), -INT32_C(  1563857547),  INT32_C(   625414140),  INT32_C(  1878478158),  INT32_C(  1800899225) },
      {  INT32_C(   161055698),  INT32_C(  1630769292), -INT32_C(  1931397651),  INT32_C(   678268564), -INT32_C(  1563857547),  INT32_C(   625414140),  INT32_C(  1878478158),  INT32_C(  1800899225) } },
    { { -INT32_C(  1720389363),  INT32_C(  1861920641),  INT32_C(  1912331485), -INT32_C(   543528854), -INT32_C(   780049451), -INT32_C(  1057503118), -INT32_C(  1355813354), -INT32_C(  2061793416) },
      { -INT32_C(  1720389363),  INT32_C(  1861920641),  INT32_C(  1912331485), -INT32_C(   543528854), -INT32_C(   780049451), -INT32_C(  1057503118), -INT32_C(  1355813354), -INT32_C(  2061793416) } },
    { { -INT32_C(   115372168),  INT32_C(   342366519),  INT32_C(  1619354613), -INT32_C(  1606475829), -INT32_C(   193805950), -INT32_C(  1615500919), -INT32_C(   800070569), -INT32_C(   480941461) },
      { -INT32_C(   115372168),  INT32_C(   342366519),  INT32_C(  1619354613), -INT32_C(  1606475829), -INT32_C(   193805950), -INT32_C(  1615500919), -INT32_C(   800070569), -INT32_C(   480941461) } },
    { {  INT32_C(   819819769), -INT32_C(  2092677746),  INT32_C(  1944308392),  INT32_C(  1813193705),  INT32_C(  1835042276),  INT32_C(  1175262702),  INT32_C(  1695964410), -INT32_C(  1085707322) },
      {  INT32_C(   819819769), -INT32_C(  2092677746),  INT32_C(  1944308392),  INT32_C(  1813193705),  INT32_C(  1835042276),  INT32_C(  1175262702),  INT32_C(  1695964410), -INT32_C(  1085707322) } },
    { {  INT32_C(  1861232352),  INT32_C(   334574699), -INT32_C(   393816578), -INT32_C(   598435336),  INT32_C(   222934047), -INT32_C(  1001171254),  INT32_C(  2015979954), -INT32_C(  1254591787) },
      {  INT32_C(  1861232352),  INT32_C(   334574699), -INT32_C(   393816578), -INT32_C(   598435336),  INT32_C(   222934047), -INT32_C(  1001171254),  INT32_C(  2015979954), -INT32_C(  1254591787) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_test_x86_assert_equal_i32x8(simde_mm256_load_si256(SIMDE_ALIGN_CAST(simde__m256i const *, test_vec[i].a)), simde_mm256_loadu_epi32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m256i a = simde_test_x86_random_i32x8();
    simde__m256i r = a;

    simde_test_x86_write_i32x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i32x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm256_loadu_epi64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    SIMDE_ALIGN_LIKE_32(simde__m256i) const int64_t a[4];
    const int64_t r[4];
  } test_vec[] = {
    { { -INT64_C( 2730480485383468799),  INT64_C( 3961809025040497319), -INT64_C( 7760876929369986550),  INT64_C( 2630957754019333904) },
      { -INT64_C( 2730480485383468799),  INT64_C( 3961809025040497319), -INT64_C( 7760876929369986550),  INT64_C( 2630957754019333904) } },
    { {  INT64_C( 2406427958756382740),  INT64_C( 1484904791614610964), -INT64_C( 2360563711534695397), -INT64_C( 4781223386344087970) },
      {  INT64_C( 2406427958756382740),  INT64_C( 1484904791614610964), -INT64_C( 2360563711534695397), -INT64_C( 4781223386344087970) } },
    { {  INT64_C( 5864722717878051783),  INT64_C( 7398096197995911564), -INT64_C( 1370136013387598003), -INT64_C( 7183219597633509398) },
      {  INT64_C( 5864722717878051783),  INT64_C( 7398096197995911564), -INT64_C( 1370136013387598003), -INT64_C( 7183219597633509398) } },
    { { -INT64_C( 3205083785718752777), -INT64_C( 2680742885939594470),  INT64_C( 1263244472435006221),  INT64_C(   39394444786922777) },
      { -INT64_C( 3205083785718752777), -INT64_C( 2680742885939594470),  INT64_C( 1263244472435006221),  INT64_C(   39394444786922777) } },
    { { -INT64_C( 4203624633801086578),  INT64_C( 3916713484056400884),  INT64_C( 6704269143766553041),  INT64_C( 3699662719747403598) },
      { -INT64_C( 4203624633801086578),  INT64_C( 3916713484056400884),  INT64_C( 6704269143766553041),  INT64_C( 3699662719747403598) } },
    { {  INT64_C( 4084959771584138049), -INT64_C( 6690919879014753339), -INT64_C( 7060055079283591580),  INT64_C( 7578517111345336660) },
      {  INT64_C( 4084959771584138049), -INT64_C( 6690919879014753339), -INT64_C( 7060055079283591580),  INT64_C( 7578517111345336660) } },
    { { -INT64_C( 6100963634310728488), -INT64_C( 8766892043372261664), -INT64_C( 1539611403198992203), -INT64_C( 4821648871914235772) },
      { -INT64_C( 6100963634310728488), -INT64_C( 8766892043372261664), -INT64_C( 1539611403198992203), -INT64_C( 4821648871914235772) } },
    { {  INT64_C( 5896672549719927620), -INT64_C( 2096610149610066370), -INT64_C( 3618209875233467063),  INT64_C(   55047857207160097) },
      {  INT64_C( 5896672549719927620), -INT64_C( 2096610149610066370), -INT64_C( 3618209875233467063),  INT64_C(   55047857207160097) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_test_x86_assert_equal_i64x4(simde_mm256_load_si256(SIMDE_ALIGN_CAST(simde__m256i const *, test_vec[i].a)), simde_mm256_loadu_epi64(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m256i a = simde_test_x86_random_i64x4();
    simde__m256i r = a;

    simde_test_x86_write_i64x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i64x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm256_maskz_loadu_ps (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask8 k;
    SIMDE_ALIGN_LIKE_32(simde__m256) const simde_float32 a[8];
    const simde_float32 r[8];
  } test_vec[] = {
    { UINT8_C(247),
      { SIMDE_FLOAT32_C(   747.25), SIMDE_FLOAT32_C(    -3.23), SIMDE_FLOAT32_C(   869.72), SIMDE_FLOAT32_C(   218.32),
        SIMDE_FLOAT32_C(  -401.59), SIMDE_FLOAT32_C(   338.41), SIMDE_FLOAT32_C(   689.40), SIMDE_FLOAT32_C(  -844.30) },
      { SIMDE_FLOAT32_C(   747.25), SIMDE_FLOAT32_C(    -3.23), SIMDE_FLOAT32_C(   869.72), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(  -401.59), SIMDE_FLOAT32_C(   338.41), SIMDE_FLOAT32_C(   689.40), SIMDE_FLOAT32_C(  -844.30) } },
    { UINT8_C(192),
      { SIMDE_FLOAT32_C(  -418.09), SIMDE_FLOAT32_C(   478.59), SIMDE_FLOAT32_C(  -133.75), SIMDE_FLOAT32_C(   102.33),
        SIMDE_FLOAT32_C(  -149.37), SIMDE_FLOAT32_C(  -417.83), SIMDE_FLOAT32_C(  -368.64), SIMDE_FLOAT32_C(  -256.56) },
      { SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -368.64), SIMDE_FLOAT32_C(  -256.56) } },
    { UINT8_C( 34),
      { SIMDE_FLOAT32_C(   858.87), SIMDE_FLOAT32_C(   275.05), SIMDE_FLOAT32_C(  -943.74), SIMDE_FLOAT32_C(  -339.31),
        SIMDE_FLOAT32_C(  -548.52), SIMDE_FLOAT32_C(   114.53), SIMDE_FLOAT32_C(  -765.40), SIMDE_FLOAT32_C(   -50.56) },
      { SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   275.05), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   114.53), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00) } },
    { UINT8_C(240),
      { SIMDE_FLOAT32_C(   724.83), SIMDE_FLOAT32_C(   573.58), SIMDE_FLOAT32_C(  -613.30), SIMDE_FLOAT32_C(  -484.46),
        SIMDE_FLOAT32_C(   320.82), SIMDE_FLOAT32_C(   383.47), SIMDE_FLOAT32_C(  -614.74), SIMDE_FLOAT32_C(  -460.85) },
      { SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(   320.82), SIMDE_FLOAT32_C(   383.47), SIMDE_FLOAT32_C(  -614.74), SIMDE_FLOAT32_C(  -460.85) } },
    { UINT8_C( 17),
      { SIMDE_FLOAT32_C(   723.67), SIMDE_FLOAT32_C(  -771.45), SIMDE_FLOAT32_C(  -862.43), SIMDE_FLOAT32_C(   476.46),
        SIMDE_FLOAT32_C(  -189.55), SIMDE_FLOAT32_C(   616.16), SIMDE_FLOAT32_C(  -657.29), SIMDE_FLOAT32_C(   912.78) },
      { SIMDE_FLOAT32_C(   723.67), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(  -189.55), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00) } },
    { UINT8_C( 79),
      { SIMDE_FLOAT32_C(   -75.12), SIMDE_FLOAT32_C(  -455.86), SIMDE_FLOAT32_C(   210.23), SIMDE_FLOAT32_C(  -947.70),
        SIMDE_FLOAT32_C(  -596.99), SIMDE_FLOAT32_C(  -514.72), SIMDE_FLOAT32_C(  -891.44), SIMDE_FLOAT32_C(    63.70) },
      { SIMDE_FLOAT32_C(   -75.12), SIMDE_FLOAT32_C(  -455.86), SIMDE_FLOAT32_C(   210.23), SIMDE_FLOAT32_C(  -947.70),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -891.44), SIMDE_FLOAT32_C(     0.00) } },
    { UINT8_C(174),
      { SIMDE_FLOAT32_C(   223.09), SIMDE_FLOAT32_C(   298.30), SIMDE_FLOAT32_C(   886.20), SIMDE_FLOAT32_C(   241.03),
        SIMDE_FLOAT32_C(    23.13), SIMDE_FLOAT32_C(   459.77), SIMDE_FLOAT32_C(   627.72), SIMDE_FLOAT32_C(   538.67) },
      { SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   298.30), SIMDE_FLOAT32_C(   886.20), SIMDE_FLOAT32_C(   241.03),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   459.77), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   538.67) } },
    { UINT8_C(202),
      { SIMDE_FLOAT32_C(    11.19), SIMDE_FLOAT32_C(   923.93), SIMDE_FLOAT32_C(   319.75), SIMDE_FLOAT32_C(    -6.93),
        SIMDE_FLOAT32_C(   647.60), SIMDE_FLOAT32_C(   548.29), SIMDE_FLOAT32_C(   130.64), SIMDE_FLOAT32_C(   124.06) },
      { SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   923.93), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(    -6.93),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   130.64), SIMDE_FLOAT32_C(   124.06) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_test_x86_assert_equal_f32x8(simde_mm256_load_ps(SIMDE_ALIGN_CAST(simde_float32 const *, test_vec[i].r)), simde_mm256_maskz_loadu_ps(test_vec[i].k, test_vec[i].a), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m256 a = simde_test_x86_random_f32x8(SIMDE_FLOAT32_C(-1000.0), SIMDE_FLOAT32_C(1000.0));
    simde__m256 r = simde_mm256_maskz_loadu_ps(k, &a);

    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_f32x8(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f32x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm512_loadu_epi8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    SIMDE_ALIGN_LIKE_64(simde__m512i) const int8_t a[64];
    const int8_t r[64];
  } test_vec[] = {
    { {  INT8_C( 115),  INT8_C(   0), -INT8_C(  90), -INT8_C(  57),  INT8_C(  50),  INT8_C(  15), -INT8_C( 121),  INT8_C(  47),
        -INT8_C(   4), -INT8_C(  87), -INT8_C(  26), -INT8_C( 116),  INT8_C(  32), -INT8_C(  59),  INT8_C(  96),  INT8_C(  45),
         INT8_C(  33), -INT8_C(  50), -INT8_C(  83), -INT8_C(  99),  INT8_C(  12),  INT8_C(  64), -INT8_C(  87),  INT8_C( 109),
        -INT8_C(  66), -INT8_C(  55),  INT8_C(  19), -INT8_C(  76), -INT8_C(  80),  INT8_C(  43),  INT8_C(  80),  INT8_C(  36),
         INT8_C(  43), -INT8_C(   9), -INT8_C(  21),  INT8_C(  94),  INT8_C(   6),  INT8_C( 114), -INT8_C( 115),  INT8_C(   2),
         INT8_C(  27),  INT8_C( 115), -INT8_C( 114),  INT8_C(  59),  INT8_C(  56), -INT8_C(  17),  INT8_C( 104),  INT8_C(  89),
        -INT8_C(  67),  INT8_C(  21), -INT8_C(  10), -INT8_C(  55),  INT8_C(  85), -INT8_C(  96),  INT8_C(  55),  INT8_C(  20),
         INT8_C( 105),  INT8_C(  74), -INT8_C(  56),  INT8_C(  26),  INT8_C( 117),  INT8_C(  24),  INT8_C(  62), -INT8_C(  95) },
      {  INT8_C( 115),  INT8_C(   0), -INT8_C(  90), -INT8_C(  57),  INT8_C(  50),  INT8_C(  15), -INT8_C( 121),  INT8_C(  47),
        -INT8_C(   4), -INT8_C(  87), -INT8_C(  26), -INT8_C( 116),  INT8_C(  32), -INT8_C(  59),  INT8_C(  96),  INT8_C(  45),
         INT8_C(  33), -INT8_C(  50), -INT8_C(  83), -INT8_C(  99),  INT8_C(  12),  INT8_C(  64), -INT8_C(  87),  INT8_C( 109),
        -INT8_C(  66), -INT8_C(  55),  INT8_C(  19), -INT8_C(  76), -INT8_C(  80),  INT8_C(  43),  INT8_C(  80),  INT8_C(  36),
         INT8_C(  43), -INT8_C(   9), -INT8_C(  21),  INT8_C(  94),  INT8_C(   6),  INT8_C( 114), -INT8_C( 115),  INT8_C(   2),
         INT8_C(  27),  INT8_C( 115), -INT8_C( 114),  INT8_C(  59),  INT8_C(  56), -INT8_C(  17),  INT8_C( 104),  INT8_C(  89),
        -INT8_C(  67),  INT8_C(  21), -INT8_C(  10), -INT8_C(  55),  INT8_C(  85), -INT8_C(  96),  INT8_C(  55),  INT8_C(  20),
         INT8_C( 105),  INT8_C(  74), -INT8_C(  56),  INT8_C(  26),  INT8_C( 117),  INT8_C(  24),  INT8_C(  62), -INT8_C(  95) } },
    { {  INT8_C(  15),  INT8_C(  41), -INT8_C(   1),  INT8_C(  22), -INT8_C( 101), -INT8_C( 116),  INT8_C(  24), -INT8_C(  74),
        -INT8_C(   1), -INT8_C(  89), -INT8_C(  15),  INT8_C(  55), -INT8_C( 106),  INT8_C(  90), -INT8_C( 112),  INT8_C(  83),
         INT8_C( 111), -INT8_C( 121),  INT8_C(  29), -INT8_C(  59),  INT8_C(  39),  INT8_C(  84), -INT8_C(  39), -INT8_C( 112),
        -INT8_C(  98), -INT8_C(  95), -INT8_C(  86),  INT8_C(  20), -INT8_C(  71), -INT8_C(  24), -INT8_C(  75), -INT8_C(  55),
         INT8_C(  17), -INT8_C(  76), -INT8_C(  33), -INT8_C(  84),  INT8_C(  64), -INT8_C(   9),  INT8_C(  98),  INT8_C(  63),
        -INT8_C(  98),  INT8_C(  84),  INT8_C( 118),  INT8_C(  52), -INT8_C(  82),  INT8_C(   6), -INT8_C( 120),  INT8_C(  29),
        -INT8_C( 115), -INT8_C(  91), -INT8_C(  30), -INT8_C(  76), -INT8_C(   7), -INT8_C(  69),  INT8_C(  69), -INT8_C( 105),
         INT8_C(  92), -INT8_C(  17), -INT8_C(  85),  INT8_C(  22), -INT8_C(  40),  INT8_C(  96), -INT8_C(  33), -INT8_C(  23) },
      {  INT8_C(  15),  INT8_C(  41), -INT8_C(   1),  INT8_C(  22), -INT8_C( 101), -INT8_C( 116),  INT8_C(  24), -INT8_C(  74),
        -INT8_C(   1), -INT8_C(  89), -INT8_C(  15),  INT8_C(  55), -INT8_C( 106),  INT8_C(  90), -INT8_C( 112),  INT8_C(  83),
         INT8_C( 111), -INT8_C( 121),  INT8_C(  29), -INT8_C(  59),  INT8_C(  39),  INT8_C(  84), -INT8_C(  39), -INT8_C( 112),
        -INT8_C(  98), -INT8_C(  95), -INT8_C(  86),  INT8_C(  20), -INT8_C(  71), -INT8_C(  24), -INT8_C(  75), -INT8_C(  55),
         INT8_C(  17), -INT8_C(  76), -INT8_C(  33), -INT8_C(  84),  INT8_C(  64), -INT8_C(   9),  INT8_C(  98),  INT8_C(  63),
        -INT8_C(  98),  INT8_C(  84),  INT8_C( 118),  INT8_C(  52), -INT8_C(  82),  INT8_C(   6), -INT8_C( 120),  INT8_C(  29),
        -INT8_C( 115), -INT8_C(  91), -INT8_C(  30), -INT8_C(  76), -INT8_C(   7), -INT8_C(  69),  INT8_C(  69), -INT8_C( 105),
         INT8_C(  92), -INT8_C(  17), -INT8_C(  85),  INT8_C(  22), -INT8_C(  40),  INT8_C(  96), -INT8_C(  33), -INT8_C(  23) } },
    { {  INT8_C(  20), -INT8_C(  66), -INT8_C( 106),  INT8_C(  84), -INT8_C(  75), -INT8_C(   8), -INT8_C( 109),  INT8_C(  84),
         INT8_C(  76),  INT8_C(   9), -INT8_C( 120), -INT8_C(   6),  INT8_C(  16),  INT8_C(  16),  INT8_C(  24), -INT8_C(  99),
        -INT8_C(  75), -INT8_C(   6),  INT8_C(  82), -INT8_C(  82), -INT8_C(  74), -INT8_C( 105),  INT8_C(  70),  INT8_C(  18),
        -INT8_C( 122), -INT8_C(  15),  INT8_C(  40),  INT8_C(  94),  INT8_C(  82),  INT8_C(   7),  INT8_C(  72),  INT8_C( 102),
        -INT8_C(  59), -INT8_C(  34), -INT8_C(  69),  INT8_C( 123), -INT8_C(  42),  INT8_C(  78), -INT8_C(  49),  INT8_C(  35),
         INT8_C(  88),  INT8_C(  87),  INT8_C(  29),  INT8_C( 104),  INT8_C( 104),  INT8_C(  53),  INT8_C(   5),  INT8_C(  29),
         INT8_C(  48),  INT8_C(  87), -INT8_C(  52), -INT8_C(  26), -INT8_C(  18),  INT8_C(  18), -INT8_C(   8),  INT8_C( 117),
         INT8_C(   3),  INT8_C(  33), -INT8_C(  45),  INT8_C(  85),  INT8_C(  40),  INT8_C(  27), -INT8_C(  68), -INT8_C(  18) },
      {  INT8_C(  20), -INT8_C(  66), -INT8_C( 106),  INT8_C(  84), -INT8_C(  75), -INT8_C(   8), -INT8_C( 109),  INT8_C(  84),
         INT8_C(  76),  INT8_C(   9), -INT8_C( 120), -INT8_C(   6),  INT8_C(  16),  INT8_C(  16),  INT8_C(  24), -INT8_C(  99),
        -INT8_C(  75), -INT8_C(   6),  INT8_C(  82), -INT8_C(  82), -INT8_C(  74), -INT8_C( 105),  INT8_C(  70),  INT8_C(  18),
        -INT8_C( 122), -INT8_C(  15),  INT8_C(  40),  INT8_C(  94),  INT8_C(  82),  INT8_C(   7),  INT8_C(  72),  INT8_C( 102),
        -INT8_C(  59), -INT8_C(  34), -INT8_C(  69),  INT8_C( 123), -INT8_C(  42),  INT8_C(  78), -INT8_C(  49),  INT8_C(  35),
         INT8_C(  88),  INT8_C(  87),  INT8_C(  29),  INT8_C( 104),  INT8_C( 104),  INT8_C(  53),  INT8_C(   5),  INT8_C(  29),
         INT8_C(  48),  INT8_C(  87), -INT8_C(  52), -INT8_C(  26), -INT8_C(  18),  INT8_C(  18), -INT8_C(   8),  INT8_C( 117),
         INT8_C(   3),  INT8_C(  33), -INT8_C(  45),  INT8_C(  85),  INT8_C(  40),  INT8_C(  27), -INT8_C(  68), -INT8_C(  18) } },
    { { -INT8_C(   7),  INT8_C( 119),  INT8_C( 105), -INT8_C(  48), -INT8_C(  59),  INT8_C(  56), -INT8_C(  13),  INT8_C(  29),
        -INT8_C( 113),  INT8_C(  16), -INT8_C( 123), -INT8_C(   9),  INT8_C(  70), -INT8_C( 117),  INT8_C(  21),  INT8_C( 118),
        -INT8_C(  30), -INT8_C(  31),  INT8_C(  92), -INT8_C(  47), -INT8_C(  13),  INT8_C(  84),  INT8_C(  70), -INT8_C(  10),
         INT8_C( 117),  INT8_C(  25),  INT8_C(  76), -INT8_C(  98),  INT8_C(  53),  INT8_C(   8), -INT8_C( 116),  INT8_C(  46),
             INT8_MAX, -INT8_C(  11), -INT8_C(   2),  INT8_C(  68),  INT8_C(  45), -INT8_C(  15),  INT8_C(  98), -INT8_C(  68),
         INT8_C(   2), -INT8_C(  25), -INT8_C(  76),  INT8_C(  72),  INT8_C( 114), -INT8_C(  55), -INT8_C(  66),  INT8_C(  85),
        -INT8_C(  86),  INT8_C(  26),  INT8_C(  38), -INT8_C(  99),  INT8_C( 110),  INT8_C( 108), -INT8_C( 109), -INT8_C(  28),
        -INT8_C( 123), -INT8_C(  33), -INT8_C( 126), -INT8_C(  70), -INT8_C(  25),  INT8_C(  14), -INT8_C(  23),  INT8_C( 102) },
      { -INT8_C(   7),  INT8_C( 119),  INT8_C( 105), -INT8_C(  48), -INT8_C(  59),  INT8_C(  56), -INT8_C(  13),  INT8_C(  29),
        -INT8_C( 113),  INT8_C(  16), -INT8_C( 123), -INT8_C(   9),  INT8_C(  70), -INT8_C( 117),  INT8_C(  21),  INT8_C( 118),
        -INT8_C(  30), -INT8_C(  31),  INT8_C(  92), -INT8_C(  47), -INT8_C(  13),  INT8_C(  84),  INT8_C(  70), -INT8_C(  10),
         INT8_C( 117),  INT8_C(  25),  INT8_C(  76), -INT8_C(  98),  INT8_C(  53),  INT8_C(   8), -INT8_C( 116),  INT8_C(  46),
             INT8_MAX, -INT8_C(  11), -INT8_C(   2),  INT8_C(  68),  INT8_C(  45), -INT8_C(  15),  INT8_C(  98), -INT8_C(  68),
         INT8_C(   2), -INT8_C(  25), -INT8_C(  76),  INT8_C(  72),  INT8_C( 114), -INT8_C(  55), -INT8_C(  66),  INT8_C(  85),
        -INT8_C(  86),  INT8_C(  26),  INT8_C(  38), -INT8_C(  99),  INT8_C( 110),  INT8_C( 108), -INT8_C( 109), -INT8_C(  28),
        -INT8_C( 123), -INT8_C(  33), -INT8_C( 126), -INT8_C(  70), -INT8_C(  25),  INT8_C(  14), -INT8_C(  23),  INT8_C( 102) } },
    { {  INT8_C(   3), -INT8_C(  25), -INT8_C(  85),  INT8_C(  48), -INT8_C(  39),  INT8_C(  13), -INT8_C(  20), -INT8_C(  37),
        -INT8_C(  12), -INT8_C(  96),  INT8_C(  35),  INT8_C( 103),  INT8_C( 105), -INT8_C(  31), -INT8_C(  68),  INT8_C(  19),
        -INT8_C(   5), -INT8_C(  30), -INT8_C(  80),  INT8_C( 105),  INT8_C(  78),  INT8_C(  68),  INT8_C(  77), -INT8_C(  45),
         INT8_C(  35), -INT8_C(  49), -INT8_C( 114),  INT8_C(  11), -INT8_C(  35),  INT8_C( 119),  INT8_C( 113), -INT8_C(  32),
         INT8_C(  94),  INT8_C(  28),  INT8_C(  16),  INT8_C(  55),  INT8_C(  41), -INT8_C(   3),  INT8_C(  18),  INT8_C(  30),
        -INT8_C(  99),  INT8_C(  53), -INT8_C( 123),  INT8_C(   7),  INT8_C(  22),  INT8_C(  65),  INT8_C(  26),  INT8_C(  17),
         INT8_C(  35), -INT8_C(  53),  INT8_C( 123),  INT8_C( 113),  INT8_C(  15), -INT8_C(  56),  INT8_C(  68),  INT8_C(  50),
        -INT8_C( 104), -INT8_C(  46),  INT8_C(  61),  INT8_C( 117),  INT8_C(  73), -INT8_C(  81),  INT8_C(  86), -INT8_C(  88) },
      {  INT8_C(   3), -INT8_C(  25), -INT8_C(  85),  INT8_C(  48), -INT8_C(  39),  INT8_C(  13), -INT8_C(  20), -INT8_C(  37),
        -INT8_C(  12), -INT8_C(  96),  INT8_C(  35),  INT8_C( 103),  INT8_C( 105), -INT8_C(  31), -INT8_C(  68),  INT8_C(  19),
        -INT8_C(   5), -INT8_C(  30), -INT8_C(  80),  INT8_C( 105),  INT8_C(  78),  INT8_C(  68),  INT8_C(  77), -INT8_C(  45),
         INT8_C(  35), -INT8_C(  49), -INT8_C( 114),  INT8_C(  11), -INT8_C(  35),  INT8_C( 119),  INT8_C( 113), -INT8_C(  32),
         INT8_C(  94),  INT8_C(  28),  INT8_C(  16),  INT8_C(  55),  INT8_C(  41), -INT8_C(   3),  INT8_C(  18),  INT8_C(  30),
        -INT8_C(  99),  INT8_C(  53), -INT8_C( 123),  INT8_C(   7),  INT8_C(  22),  INT8_C(  65),  INT8_C(  26),  INT8_C(  17),
         INT8_C(  35), -INT8_C(  53),  INT8_C( 123),  INT8_C( 113),  INT8_C(  15), -INT8_C(  56),  INT8_C(  68),  INT8_C(  50),
        -INT8_C( 104), -INT8_C(  46),  INT8_C(  61),  INT8_C( 117),  INT8_C(  73), -INT8_C(  81),  INT8_C(  86), -INT8_C(  88) } },
    { { -INT8_C(  53),  INT8_C( 102), -INT8_C(  33), -INT8_C(  11),  INT8_C(  99), -INT8_C(  14),  INT8_C(  19),  INT8_C(   1),
         INT8_C(  39), -INT8_C( 104),  INT8_C(   8),  INT8_C(  62), -INT8_C(  39),  INT8_C(  34),  INT8_C(  79), -INT8_C(   4),
        -INT8_C(  19), -INT8_C(  54),  INT8_C( 109), -INT8_C(   4), -INT8_C( 109), -INT8_C(  79),  INT8_C(  47),  INT8_C(  43),
        -INT8_C( 124),  INT8_C( 108), -INT8_C(  96), -INT8_C(  51),  INT8_C(  27), -INT8_C(  10),  INT8_C( 117), -INT8_C(  25),
         INT8_C(  93),  INT8_C(  85), -INT8_C(  36), -INT8_C(  64),  INT8_C(  71), -INT8_C(  17), -INT8_C(  63),  INT8_C( 110),
        -INT8_C( 121), -INT8_C(  55), -INT8_C(  84),  INT8_C(  96), -INT8_C(  20), -INT8_C(   4),  INT8_C(  92), -INT8_C(  39),
        -INT8_C(  58), -INT8_C(  55), -INT8_C(  42),  INT8_C(  89),  INT8_C( 122),  INT8_C(   5), -INT8_C( 124), -INT8_C(   2),
         INT8_C( 113),  INT8_C(  37), -INT8_C(  52), -INT8_C( 115),  INT8_C(  27),  INT8_C(  65),  INT8_C( 116),  INT8_C( 120) },
      { -INT8_C(  53),  INT8_C( 102), -INT8_C(  33), -INT8_C(  11),  INT8_C(  99), -INT8_C(  14),  INT8_C(  19),  INT8_C(   1),
         INT8_C(  39), -INT8_C( 104),  INT8_C(   8),  INT8_C(  62), -INT8_C(  39),  INT8_C(  34),  INT8_C(  79), -INT8_C(   4),
        -INT8_C(  19), -INT8_C(  54),  INT8_C( 109), -INT8_C(   4), -INT8_C( 109), -INT8_C(  79),  INT8_C(  47),  INT8_C(  43),
        -INT8_C( 124),  INT8_C( 108), -INT8_C(  96), -INT8_C(  51),  INT8_C(  27), -INT8_C(  10),  INT8_C( 117), -INT8_C(  25),
         INT8_C(  93),  INT8_C(  85), -INT8_C(  36), -INT8_C(  64),  INT8_C(  71), -INT8_C(  17), -INT8_C(  63),  INT8_C( 110),
        -INT8_C( 121), -INT8_C(  55), -INT8_C(  84),  INT8_C(  96), -INT8_C(  20), -INT8_C(   4),  INT8_C(  92), -INT8_C(  39),
        -INT8_C(  58), -INT8_C(  55), -INT8_C(  42),  INT8_C(  89),  INT8_C( 122),  INT8_C(   5), -INT8_C( 124), -INT8_C(   2),
         INT8_C( 113),  INT8_C(  37), -INT8_C(  52), -INT8_C( 115),  INT8_C(  27),  INT8_C(  65),  INT8_C( 116),  INT8_C( 120) } },
    { { -INT8_C( 106),  INT8_C(  80),  INT8_C(  57), -INT8_C(  35),  INT8_C(  63), -INT8_C(   6),  INT8_C(  76), -INT8_C(  58),
        -INT8_C(  60), -INT8_C(   8),  INT8_C(  38), -INT8_C(  80), -INT8_C(  12), -INT8_C( 126), -INT8_C( 119), -INT8_C(  69),
         INT8_C(  75),  INT8_C(  95),  INT8_C(  20), -INT8_C(  59),  INT8_C( 100), -INT8_C( 103), -INT8_C(  60), -INT8_C(  42),
        -INT8_C(  66), -INT8_C( 112),  INT8_C(  99), -INT8_C(  39), -INT8_C(  47), -INT8_C(  41),  INT8_C(  82),  INT8_C( 104),
         INT8_C(  39), -INT8_C( 117),  INT8_C(  69),  INT8_C( 102), -INT8_C( 123), -INT8_C( 111),  INT8_C(  44),  INT8_C(  73),
        -INT8_C( 118),  INT8_C(  82), -INT8_C(   7),  INT8_C( 126), -INT8_C(  44), -INT8_C( 125),  INT8_C(  57),  INT8_C(  31),
        -INT8_C(  30),  INT8_C(  78), -INT8_C(  28),  INT8_C(  71), -INT8_C(  25), -INT8_C(  88),  INT8_C(  29), -INT8_C(  91),
         INT8_C(  56),      INT8_MIN,  INT8_C( 126),  INT8_C(  10),  INT8_C(  87), -INT8_C(  48),  INT8_C( 114),  INT8_C( 126) },
      { -INT8_C( 106),  INT8_C(  80),  INT8_C(  57), -INT8_C(  35),  INT8_C(  63), -INT8_C(   6),  INT8_C(  76), -INT8_C(  58),
        -INT8_C(  60), -INT8_C(   8),  INT8_C(  38), -INT8_C(  80), -INT8_C(  12), -INT8_C( 126), -INT8_C( 119), -INT8_C(  69),
         INT8_C(  75),  INT8_C(  95),  INT8_C(  20), -INT8_C(  59),  INT8_C( 100), -INT8_C( 103), -INT8_C(  60), -INT8_C(  42),
        -INT8_C(  66), -INT8_C( 112),  INT8_C(  99), -INT8_C(  39), -INT8_C(  47), -INT8_C(  41),  INT8_C(  82),  INT8_C( 104),
         INT8_C(  39), -INT8_C( 117),  INT8_C(  69),  INT8_C( 102), -INT8_C( 123), -INT8_C( 111),  INT8_C(  44),  INT8_C(  73),
        -INT8_C( 118),  INT8_C(  82), -INT8_C(   7),  INT8_C( 126), -INT8_C(  44), -INT8_C( 125),  INT8_C(  57),  INT8_C(  31),
        -INT8_C(  30),  INT8_C(  78), -INT8_C(  28),  INT8_C(  71), -INT8_C(  25), -INT8_C(  88),  INT8_C(  29), -INT8_C(  91),
         INT8_C(  56),      INT8_MIN,  INT8_C( 126),  INT8_C(  10),  INT8_C(  87), -INT8_C(  48),  INT8_C( 114),  INT8_C( 126) } },
    { {  INT8_C(  91), -INT8_C(  73), -INT8_C(  28), -INT8_C(  31),  INT8_C(  73),  INT8_C(  16),  INT8_C(  42), -INT8_C(  45),
         INT8_C(  98),  INT8_C(  36),  INT8_C(  81),  INT8_C(  54), -INT8_C(  89), -INT8_C( 117),  INT8_C(  85), -INT8_C( 119),
        -INT8_C(  39),  INT8_C(  57), -INT8_C(  48), -INT8_C(  64), -INT8_C(  30), -INT8_C(  19),  INT8_C( 101),  INT8_C(  26),
         INT8_C( 109), -INT8_C(  29),  INT8_C(  36), -INT8_C(  60), -INT8_C(  76), -INT8_C( 106),  INT8_C(  66),  INT8_C(  15),
         INT8_C(  78),  INT8_C(  38), -INT8_C(  16), -INT8_C( 105),  INT8_C(  54),  INT8_C(  27),  INT8_C( 106), -INT8_C( 104),
         INT8_C(  63), -INT8_C(  69), -INT8_C(  50), -INT8_C(  26),  INT8_C(  70),  INT8_C(  35),  INT8_C( 111),  INT8_C(  31),
         INT8_C(  93),  INT8_C(  64), -INT8_C(  33),  INT8_C(  63),  INT8_C(  45),  INT8_C(  68),  INT8_C(  89), -INT8_C( 101),
         INT8_C(  40),  INT8_C( 126),  INT8_C(  95), -INT8_C(  36),  INT8_C(  20), -INT8_C(  94), -INT8_C(  21),  INT8_C(  98) },
      {  INT8_C(  91), -INT8_C(  73), -INT8_C(  28), -INT8_C(  31),  INT8_C(  73),  INT8_C(  16),  INT8_C(  42), -INT8_C(  45),
         INT8_C(  98),  INT8_C(  36),  INT8_C(  81),  INT8_C(  54), -INT8_C(  89), -INT8_C( 117),  INT8_C(  85), -INT8_C( 119),
        -INT8_C(  39),  INT8_C(  57), -INT8_C(  48), -INT8_C(  64), -INT8_C(  30), -INT8_C(  19),  INT8_C( 101),  INT8_C(  26),
         INT8_C( 109), -INT8_C(  29),  INT8_C(  36), -INT8_C(  60), -INT8_C(  76), -INT8_C( 106),  INT8_C(  66),  INT8_C(  15),
         INT8_C(  78),  INT8_C(  38), -INT8_C(  16), -INT8_C( 105),  INT8_C(  54),  INT8_C(  27),  INT8_C( 106), -INT8_C( 104),
         INT8_C(  63), -INT8_C(  69), -INT8_C(  50), -INT8_C(  26),  INT8_C(  70),  INT8_C(  35),  INT8_C( 111),  INT8_C(  31),
         INT8_C(  93),  INT8_C(  64), -INT8_C(  33),  INT8_C(  63),  INT8_C(  45),  INT8_C(  68),  INT8_C(  89), -INT8_C( 101),
         INT8_C(  40),  INT8_C( 126),  INT8_C(  95), -INT8_C(  36),  INT8_C(  20), -INT8_C(  94), -INT8_C(  21),  INT8_C(  98) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_test_x86_assert_equal_i8x64(simde_mm512_load_si512(test_vec[i].a), simde_mm512_loadu_epi8(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m512i a = simde_test_x86_random_i8x64();
    simde__m512i r = a;

    simde_test_x86_write_i8x64(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i8x64(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm512_loadu_epi16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    SIMDE_ALIGN_LIKE_64(simde__m512i) const int16_t a[32];
    const int16_t r[32];
  } test_vec[] = {
    { {  INT16_C(  1628), -INT16_C( 19656), -INT16_C( 13922),  INT16_C(   835), -INT16_C(  2787), -INT16_C( 10395),  INT16_C(  6399),  INT16_C( 11765),
         INT16_C(  4017),  INT16_C( 12521),  INT16_C( 21092), -INT16_C( 30322),  INT16_C(  5175),  INT16_C( 12717), -INT16_C( 28003), -INT16_C(  1686),
        -INT16_C( 23911),  INT16_C( 14252), -INT16_C(  4245), -INT16_C( 30662), -INT16_C( 24604), -INT16_C(  7329),  INT16_C( 21687),  INT16_C( 26897),
        -INT16_C(  1436), -INT16_C( 14183),  INT16_C( 10060), -INT16_C( 31919), -INT16_C(   452), -INT16_C(  9803),  INT16_C(  8081),  INT16_C( 10962) },
      {  INT16_C(  1628), -INT16_C( 19656), -INT16_C( 13922),  INT16_C(   835), -INT16_C(  2787), -INT16_C( 10395),  INT16_C(  6399),  INT16_C( 11765),
         INT16_C(  4017),  INT16_C( 12521),  INT16_C( 21092), -INT16_C( 30322),  INT16_C(  5175),  INT16_C( 12717), -INT16_C( 28003), -INT16_C(  1686),
        -INT16_C( 23911),  INT16_C( 14252), -INT16_C(  4245), -INT16_C( 30662), -INT16_C( 24604), -INT16_C(  7329),  INT16_C( 21687),  INT16_C( 26897),
        -INT16_C(  1436), -INT16_C( 14183),  INT16_C( 10060), -INT16_C( 31919), -INT16_C(   452), -INT16_C(  9803),  INT16_C(  8081),  INT16_C( 10962) } },
    { {  INT16_C( 32450),  INT16_C( 11617), -INT16_C( 25746),  INT16_C( 21174),  INT16_C(  5434), -INT16_C(  3786),  INT16_C( 18282), -INT16_C( 12710),
        -INT16_C(  3263), -INT16_C( 29034), -INT16_C(  6373),  INT16_C( 22289), -INT16_C( 14618),  INT16_C( 30512),  INT16_C(   742), -INT16_C( 22367),
         INT16_C(   640), -INT16_C(  4395), -INT16_C( 29795), -INT16_C( 10431),  INT16_C( 30625),  INT16_C(  3016),  INT16_C(  9150), -INT16_C(    39),
         INT16_C( 28438),  INT16_C( 12685), -INT16_C( 24746),  INT16_C( 15496), -INT16_C( 18331),  INT16_C( 19379),  INT16_C( 21690),  INT16_C( 15347) },
      {  INT16_C( 32450),  INT16_C( 11617), -INT16_C( 25746),  INT16_C( 21174),  INT16_C(  5434), -INT16_C(  3786),  INT16_C( 18282), -INT16_C( 12710),
        -INT16_C(  3263), -INT16_C( 29034), -INT16_C(  6373),  INT16_C( 22289), -INT16_C( 14618),  INT16_C( 30512),  INT16_C(   742), -INT16_C( 22367),
         INT16_C(   640), -INT16_C(  4395), -INT16_C( 29795), -INT16_C( 10431),  INT16_C( 30625),  INT16_C(  3016),  INT16_C(  9150), -INT16_C(    39),
         INT16_C( 28438),  INT16_C( 12685), -INT16_C( 24746),  INT16_C( 15496), -INT16_C( 18331),  INT16_C( 19379),  INT16_C( 21690),  INT16_C( 15347) } },
    { { -INT16_C( 13994), -INT16_C(  3287),  INT16_C( 27220), -INT16_C(  2614), -INT16_C( 27679), -INT16_C( 24832), -INT16_C(  9802), -INT16_C( 13153),
         INT16_C( 11336), -INT16_C( 24578), -INT16_C( 31029),  INT16_C( 12763), -INT16_C( 28865), -INT16_C(  1668),  INT16_C( 28899),  INT16_C( 14900),
         INT16_C( 24121), -INT16_C( 29395), -INT16_C(  1848), -INT16_C( 21885), -INT16_C( 31861),  INT16_C( 16713), -INT16_C(  6051), -INT16_C( 23283),
         INT16_C(  2837), -INT16_C(  8124),  INT16_C(  8338), -INT16_C( 12015), -INT16_C( 29009), -INT16_C( 27958), -INT16_C(     2),  INT16_C( 14284) },
      { -INT16_C( 13994), -INT16_C(  3287),  INT16_C( 27220), -INT16_C(  2614), -INT16_C( 27679), -INT16_C( 24832), -INT16_C(  9802), -INT16_C( 13153),
         INT16_C( 11336), -INT16_C( 24578), -INT16_C( 31029),  INT16_C( 12763), -INT16_C( 28865), -INT16_C(  1668),  INT16_C( 28899),  INT16_C( 14900),
         INT16_C( 24121), -INT16_C( 29395), -INT16_C(  1848), -INT16_C( 21885), -INT16_C( 31861),  INT16_C( 16713), -INT16_C(  6051), -INT16_C( 23283),
         INT16_C(  2837), -INT16_C(  8124),  INT16_C(  8338), -INT16_C( 12015), -INT16_C( 29009), -INT16_C( 27958), -INT16_C(     2),  INT16_C( 14284) } },
    { { -INT16_C(  1443),  INT16_C(  9668),  INT16_C( 18418),  INT16_C( 32207),  INT16_C(  6603),  INT16_C( 10430), -INT16_C( 13567),  INT16_C(  5837),
         INT16_C(  4823),  INT16_C( 27127),  INT16_C(  2098), -INT16_C(  7878),  INT16_C(  1174), -INT16_C( 27533),  INT16_C( 16387),  INT16_C( 24779),
        -INT16_C( 28614),  INT16_C( 11398),  INT16_C( 21975), -INT16_C( 23895),  INT16_C( 26478),  INT16_C( 28874), -INT16_C( 26574),  INT16_C(  2438),
         INT16_C( 32170), -INT16_C(  9102), -INT16_C( 21370),  INT16_C(  7357),  INT16_C( 12465), -INT16_C( 19279),  INT16_C( 31856), -INT16_C( 21995) },
      { -INT16_C(  1443),  INT16_C(  9668),  INT16_C( 18418),  INT16_C( 32207),  INT16_C(  6603),  INT16_C( 10430), -INT16_C( 13567),  INT16_C(  5837),
         INT16_C(  4823),  INT16_C( 27127),  INT16_C(  2098), -INT16_C(  7878),  INT16_C(  1174), -INT16_C( 27533),  INT16_C( 16387),  INT16_C( 24779),
        -INT16_C( 28614),  INT16_C( 11398),  INT16_C( 21975), -INT16_C( 23895),  INT16_C( 26478),  INT16_C( 28874), -INT16_C( 26574),  INT16_C(  2438),
         INT16_C( 32170), -INT16_C(  9102), -INT16_C( 21370),  INT16_C(  7357),  INT16_C( 12465), -INT16_C( 19279),  INT16_C( 31856), -INT16_C( 21995) } },
    { { -INT16_C( 25844), -INT16_C(  6954),  INT16_C( 32752),  INT16_C( 24454),  INT16_C( 20966),  INT16_C(  6607),  INT16_C( 21993), -INT16_C( 27870),
        -INT16_C( 27181),  INT16_C( 22895),  INT16_C( 11329), -INT16_C(  3467),  INT16_C(  9820), -INT16_C( 12889), -INT16_C( 17245), -INT16_C( 20617),
         INT16_C( 20055),  INT16_C( 18323),  INT16_C(  6861), -INT16_C( 19290),  INT16_C( 30059),  INT16_C( 21709), -INT16_C(  4149), -INT16_C( 24857),
         INT16_C( 22148), -INT16_C( 14601),  INT16_C( 27778), -INT16_C(  8520),  INT16_C( 24467),  INT16_C( 13995),  INT16_C(  8987),  INT16_C( 29413) },
      { -INT16_C( 25844), -INT16_C(  6954),  INT16_C( 32752),  INT16_C( 24454),  INT16_C( 20966),  INT16_C(  6607),  INT16_C( 21993), -INT16_C( 27870),
        -INT16_C( 27181),  INT16_C( 22895),  INT16_C( 11329), -INT16_C(  3467),  INT16_C(  9820), -INT16_C( 12889), -INT16_C( 17245), -INT16_C( 20617),
         INT16_C( 20055),  INT16_C( 18323),  INT16_C(  6861), -INT16_C( 19290),  INT16_C( 30059),  INT16_C( 21709), -INT16_C(  4149), -INT16_C( 24857),
         INT16_C( 22148), -INT16_C( 14601),  INT16_C( 27778), -INT16_C(  8520),  INT16_C( 24467),  INT16_C( 13995),  INT16_C(  8987),  INT16_C( 29413) } },
    { {  INT16_C( 31089),  INT16_C( 16058),  INT16_C( 24723), -INT16_C(   270), -INT16_C( 16426), -INT16_C( 24238),  INT16_C( 14767),  INT16_C( 13119),
         INT16_C( 13967),  INT16_C(  4601), -INT16_C( 19806),  INT16_C( 13807), -INT16_C( 25839),  INT16_C( 11627),  INT16_C( 20926),  INT16_C( 12191),
         INT16_C( 22986),  INT16_C( 23917),  INT16_C( 24762), -INT16_C( 28581), -INT16_C( 21217), -INT16_C( 12751),  INT16_C( 28902),  INT16_C( 29954),
        -INT16_C(  1114),  INT16_C( 18566),  INT16_C( 30125), -INT16_C( 16514), -INT16_C(  5872), -INT16_C( 12564), -INT16_C( 29894),  INT16_C(  1277) },
      {  INT16_C( 31089),  INT16_C( 16058),  INT16_C( 24723), -INT16_C(   270), -INT16_C( 16426), -INT16_C( 24238),  INT16_C( 14767),  INT16_C( 13119),
         INT16_C( 13967),  INT16_C(  4601), -INT16_C( 19806),  INT16_C( 13807), -INT16_C( 25839),  INT16_C( 11627),  INT16_C( 20926),  INT16_C( 12191),
         INT16_C( 22986),  INT16_C( 23917),  INT16_C( 24762), -INT16_C( 28581), -INT16_C( 21217), -INT16_C( 12751),  INT16_C( 28902),  INT16_C( 29954),
        -INT16_C(  1114),  INT16_C( 18566),  INT16_C( 30125), -INT16_C( 16514), -INT16_C(  5872), -INT16_C( 12564), -INT16_C( 29894),  INT16_C(  1277) } },
    { {  INT16_C( 27621), -INT16_C( 24735), -INT16_C( 17205), -INT16_C(  5585),  INT16_C( 24681),  INT16_C( 20409), -INT16_C( 17456),  INT16_C( 30404),
         INT16_C( 19126),  INT16_C( 25790),  INT16_C( 15552), -INT16_C( 12253),  INT16_C(  3878),  INT16_C( 24735), -INT16_C( 25446),  INT16_C( 32613),
        -INT16_C( 14841), -INT16_C( 11746),  INT16_C( 19843), -INT16_C(  4931),  INT16_C( 30381),  INT16_C( 32060),  INT16_C(    49), -INT16_C(  6157),
        -INT16_C( 19893),  INT16_C(  2891),  INT16_C( 28398),  INT16_C(  5339),  INT16_C( 31357),  INT16_C(  6261), -INT16_C(  9705),  INT16_C(  7831) },
      {  INT16_C( 27621), -INT16_C( 24735), -INT16_C( 17205), -INT16_C(  5585),  INT16_C( 24681),  INT16_C( 20409), -INT16_C( 17456),  INT16_C( 30404),
         INT16_C( 19126),  INT16_C( 25790),  INT16_C( 15552), -INT16_C( 12253),  INT16_C(  3878),  INT16_C( 24735), -INT16_C( 25446),  INT16_C( 32613),
        -INT16_C( 14841), -INT16_C( 11746),  INT16_C( 19843), -INT16_C(  4931),  INT16_C( 30381),  INT16_C( 32060),  INT16_C(    49), -INT16_C(  6157),
        -INT16_C( 19893),  INT16_C(  2891),  INT16_C( 28398),  INT16_C(  5339),  INT16_C( 31357),  INT16_C(  6261), -INT16_C(  9705),  INT16_C(  7831) } },
    { { -INT16_C( 18784),  INT16_C(  9201), -INT16_C( 20989), -INT16_C( 20208),  INT16_C( 19492),  INT16_C( 21806),  INT16_C(  8780), -INT16_C( 26820),
        -INT16_C( 30508), -INT16_C( 15710),  INT16_C( 32502),  INT16_C( 29911),  INT16_C( 19704),  INT16_C(  3980),  INT16_C(  8998), -INT16_C( 14802),
         INT16_C(  8153), -INT16_C(  8726), -INT16_C(  1331), -INT16_C(  3698), -INT16_C( 17338), -INT16_C( 28090), -INT16_C( 32034), -INT16_C( 19926),
        -INT16_C( 13302),  INT16_C(   373),  INT16_C( 19530),  INT16_C( 17269),  INT16_C(   408), -INT16_C( 16814), -INT16_C( 32732), -INT16_C(   380) },
      { -INT16_C( 18784),  INT16_C(  9201), -INT16_C( 20989), -INT16_C( 20208),  INT16_C( 19492),  INT16_C( 21806),  INT16_C(  8780), -INT16_C( 26820),
        -INT16_C( 30508), -INT16_C( 15710),  INT16_C( 32502),  INT16_C( 29911),  INT16_C( 19704),  INT16_C(  3980),  INT16_C(  8998), -INT16_C( 14802),
         INT16_C(  8153), -INT16_C(  8726), -INT16_C(  1331), -INT16_C(  3698), -INT16_C( 17338), -INT16_C( 28090), -INT16_C( 32034), -INT16_C( 19926),
        -INT16_C( 13302),  INT16_C(   373),  INT16_C( 19530),  INT16_C( 17269),  INT16_C(   408), -INT16_C( 16814), -INT16_C( 32732), -INT16_C(   380) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_test_x86_assert_equal_i16x32(simde_mm512_load_si512(test_vec[i].a), simde_mm512_loadu_epi16(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m512i a = simde_test_x86_random_i16x32();
    simde__m512i r = a;

    simde_test_x86_write_i16x32(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i16x32(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm512_mask_loadu_epi16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int16_t src[32];
    const simde__mmask32 k;
    SIMDE_ALIGN_LIKE_32(simde__m512i) const int16_t a[32];
    const int16_t r[32];
  } test_vec[] = {
    { {  INT16_C(  1838), -INT16_C( 19150), -INT16_C(  9189),  INT16_C(  4849), -INT16_C( 30106), -INT16_C( 30933), -INT16_C(  2244), -INT16_C( 14462),
         INT16_C(  7688), -INT16_C(   767), -INT16_C( 30260),  INT16_C( 18851), -INT16_C( 29529),  INT16_C( 26354), -INT16_C( 21034),  INT16_C(  1210),
        -INT16_C(  4940), -INT16_C( 12102), -INT16_C( 21559),  INT16_C( 12258),  INT16_C(  3637),  INT16_C( 29366),  INT16_C( 14597),  INT16_C(  3385),
         INT16_C( 15191),  INT16_C(  8970), -INT16_C( 21052),  INT16_C( 27501),  INT16_C( 24378),  INT16_C(  4306), -INT16_C( 29684), -INT16_C( 16363) },
      UINT32_C(1116786553),
      {  INT16_C( 29562), -INT16_C( 20623),  INT16_C( 10369), -INT16_C( 31199),  INT16_C( 23393), -INT16_C( 18285), -INT16_C( 24938),  INT16_C( 23259),
         INT16_C( 18507), -INT16_C( 31291), -INT16_C( 26713), -INT16_C( 19562), -INT16_C( 21724), -INT16_C( 25228),  INT16_C(  1146), -INT16_C(  2849),
         INT16_C( 20599), -INT16_C(  1885), -INT16_C( 14984), -INT16_C(  9858),  INT16_C(  4640), -INT16_C( 18799),  INT16_C( 28080), -INT16_C(  1264),
        -INT16_C( 10827),  INT16_C( 23937),  INT16_C(  5997), -INT16_C( 28400), -INT16_C( 31550),  INT16_C( 15406),  INT16_C(  3465),  INT16_C(    48) },
      {  INT16_C( 29562), -INT16_C( 19150), -INT16_C(  9189), -INT16_C( 31199),  INT16_C( 23393), -INT16_C( 18285), -INT16_C( 24938), -INT16_C( 14462),
         INT16_C( 18507), -INT16_C( 31291), -INT16_C( 26713), -INT16_C( 19562), -INT16_C( 29529),  INT16_C( 26354),  INT16_C(  1146), -INT16_C(  2849),
        -INT16_C(  4940), -INT16_C( 12102), -INT16_C( 21559),  INT16_C( 12258),  INT16_C(  4640),  INT16_C( 29366),  INT16_C( 14597), -INT16_C(  1264),
         INT16_C( 15191),  INT16_C( 23937), -INT16_C( 21052),  INT16_C( 27501),  INT16_C( 24378),  INT16_C(  4306),  INT16_C(  3465), -INT16_C( 16363) } },
    { { -INT16_C( 11427), -INT16_C( 10503),  INT16_C( 30616), -INT16_C( 18257),  INT16_C( 16777),  INT16_C( 14702),  INT16_C( 32430),  INT16_C( 25397),
        -INT16_C( 18860), -INT16_C( 15936), -INT16_C( 11827), -INT16_C( 28846), -INT16_C( 32683), -INT16_C(  8501), -INT16_C(  1139), -INT16_C(  5409),
        -INT16_C( 10034),  INT16_C( 26560),  INT16_C( 28751), -INT16_C(  9953), -INT16_C( 29007),  INT16_C( 24338),  INT16_C( 18188),  INT16_C( 24770),
        -INT16_C( 31747), -INT16_C( 13791),  INT16_C( 29524), -INT16_C( 22183),  INT16_C(  9459), -INT16_C( 32632),  INT16_C( 26399), -INT16_C(  4501) },
      UINT32_C(2387946303),
      {  INT16_C( 29851),  INT16_C( 19559),  INT16_C( 31234),  INT16_C(  4011),  INT16_C( 28353), -INT16_C( 16529), -INT16_C( 28175),  INT16_C( 17801),
        -INT16_C(  7420), -INT16_C(  1810),  INT16_C( 30215),  INT16_C( 10104), -INT16_C(  7203),  INT16_C(  7189),  INT16_C( 27151), -INT16_C( 21845),
         INT16_C(  4830), -INT16_C(  7689), -INT16_C( 23924),  INT16_C( 20208),  INT16_C( 24336),  INT16_C(   269), -INT16_C( 26896), -INT16_C(  2746),
         INT16_C( 13689), -INT16_C( 32275),  INT16_C( 26027), -INT16_C( 30296), -INT16_C( 17079),  INT16_C( 22693),  INT16_C( 20519),  INT16_C(  1282) },
      {  INT16_C( 29851),  INT16_C( 19559),  INT16_C( 31234),  INT16_C(  4011),  INT16_C( 28353), -INT16_C( 16529),  INT16_C( 32430),  INT16_C( 25397),
        -INT16_C(  7420), -INT16_C(  1810), -INT16_C( 11827),  INT16_C( 10104), -INT16_C( 32683),  INT16_C(  7189), -INT16_C(  1139), -INT16_C(  5409),
         INT16_C(  4830),  INT16_C( 26560), -INT16_C( 23924), -INT16_C(  9953),  INT16_C( 24336),  INT16_C( 24338), -INT16_C( 26896),  INT16_C( 24770),
        -INT16_C( 31747), -INT16_C( 32275),  INT16_C( 26027), -INT16_C( 30296),  INT16_C(  9459), -INT16_C( 32632),  INT16_C( 26399),  INT16_C(  1282) } },
    { { -INT16_C(  1693), -INT16_C(  4122), -INT16_C( 10596), -INT16_C( 21443),  INT16_C( 18998),  INT16_C(  9902), -INT16_C(  2847),  INT16_C( 23067),
         INT16_C(  2089), -INT16_C( 10789), -INT16_C( 31890), -INT16_C( 18594),  INT16_C(   832),  INT16_C( 26383),  INT16_C(  4436), -INT16_C( 18579),
         INT16_C( 21259), -INT16_C( 22618), -INT16_C(  7126),  INT16_C( 24659),  INT16_C(   302),  INT16_C(  3974), -INT16_C( 23818),  INT16_C(  8042),
         INT16_C( 17834),  INT16_C(  6388),  INT16_C( 21193),  INT16_C(  2511), -INT16_C(  8618), -INT16_C( 21903), -INT16_C(  8464), -INT16_C(  1183) },
      UINT32_C(1537345329),
      { -INT16_C(  2581),  INT16_C(  6843),  INT16_C( 17143), -INT16_C(  4823), -INT16_C( 27676), -INT16_C( 29172),  INT16_C(   473), -INT16_C( 23897),
         INT16_C( 30291), -INT16_C( 22101),  INT16_C(  7253),  INT16_C( 17747), -INT16_C( 19206),  INT16_C( 11328), -INT16_C(  7492), -INT16_C( 22649),
         INT16_C( 17367), -INT16_C( 12607), -INT16_C(  5243),  INT16_C( 27067), -INT16_C( 14210),  INT16_C( 22519), -INT16_C( 24887),  INT16_C(  7417),
        -INT16_C( 23275),  INT16_C( 27334),  INT16_C(  6593), -INT16_C( 17233), -INT16_C(  4146), -INT16_C( 29976),  INT16_C( 28625), -INT16_C( 22479) },
      { -INT16_C(  2581), -INT16_C(  4122), -INT16_C( 10596), -INT16_C( 21443), -INT16_C( 27676), -INT16_C( 29172), -INT16_C(  2847),  INT16_C( 23067),
         INT16_C( 30291), -INT16_C( 22101),  INT16_C(  7253), -INT16_C( 18594),  INT16_C(   832),  INT16_C( 26383),  INT16_C(  4436), -INT16_C( 18579),
         INT16_C( 21259), -INT16_C( 12607), -INT16_C(  7126),  INT16_C( 24659),  INT16_C(   302),  INT16_C( 22519), -INT16_C( 23818),  INT16_C(  7417),
        -INT16_C( 23275),  INT16_C( 27334),  INT16_C( 21193), -INT16_C( 17233), -INT16_C(  4146), -INT16_C( 21903),  INT16_C( 28625), -INT16_C(  1183) } },
    { { -INT16_C(  3150),  INT16_C( 14199),  INT16_C( 13022),  INT16_C( 23712), -INT16_C( 26374), -INT16_C( 15436), -INT16_C( 21194),  INT16_C( 19424),
        -INT16_C( 22958),  INT16_C(  5301),  INT16_C( 25791), -INT16_C( 29232), -INT16_C( 18349),  INT16_C(  9239),  INT16_C( 18727), -INT16_C(  9523),
         INT16_C( 17468),  INT16_C(  6673), -INT16_C( 19850),  INT16_C( 29046),  INT16_C( 10826), -INT16_C( 32716),  INT16_C(  5336),  INT16_C( 10956),
        -INT16_C( 32326),  INT16_C( 31294),  INT16_C(  3814),  INT16_C( 14599),  INT16_C(  8134), -INT16_C(  4514),  INT16_C( 11112), -INT16_C( 23352) },
      UINT32_C(3854489967),
      {  INT16_C( 13451), -INT16_C( 10922), -INT16_C( 29857),  INT16_C( 14166),  INT16_C(  8863),  INT16_C( 23137), -INT16_C( 24413), -INT16_C( 30252),
        -INT16_C(  9298),  INT16_C( 30147),  INT16_C(  8698),  INT16_C( 25187),  INT16_C( 11084), -INT16_C( 17658), -INT16_C( 15356), -INT16_C( 28512),
        -INT16_C(  2055),  INT16_C( 22629), -INT16_C( 17534),  INT16_C(  8591), -INT16_C(  3875), -INT16_C( 32389),  INT16_C( 20368),  INT16_C( 16138),
        -INT16_C( 13013),  INT16_C(  9652),  INT16_C(  6126),  INT16_C( 14984), -INT16_C( 29118),  INT16_C( 18165), -INT16_C( 27053),  INT16_C( 19670) },
      {  INT16_C( 13451), -INT16_C( 10922), -INT16_C( 29857),  INT16_C( 14166), -INT16_C( 26374),  INT16_C( 23137), -INT16_C( 24413),  INT16_C( 19424),
        -INT16_C(  9298),  INT16_C(  5301),  INT16_C( 25791),  INT16_C( 25187),  INT16_C( 11084),  INT16_C(  9239), -INT16_C( 15356), -INT16_C( 28512),
         INT16_C( 17468),  INT16_C( 22629), -INT16_C( 17534),  INT16_C(  8591), -INT16_C(  3875), -INT16_C( 32389),  INT16_C(  5336),  INT16_C( 16138),
        -INT16_C( 13013),  INT16_C( 31294),  INT16_C(  6126),  INT16_C( 14599),  INT16_C(  8134),  INT16_C( 18165), -INT16_C( 27053),  INT16_C( 19670) } },
    { {  INT16_C( 15501),  INT16_C(  4004),  INT16_C( 13303), -INT16_C( 10960), -INT16_C( 21469), -INT16_C( 19370),  INT16_C( 24827),  INT16_C(  9971),
        -INT16_C( 22738),  INT16_C(  7244), -INT16_C( 11074),  INT16_C(    87),  INT16_C( 19554), -INT16_C( 19130),  INT16_C(  7650),  INT16_C( 28417),
        -INT16_C( 23207),  INT16_C( 20606), -INT16_C( 20520), -INT16_C(   987),  INT16_C( 31579),  INT16_C( 22192), -INT16_C( 23588),  INT16_C(  2685),
        -INT16_C( 14006),  INT16_C(  2086),  INT16_C( 32157), -INT16_C(   248),  INT16_C( 20170), -INT16_C( 21323), -INT16_C( 18837), -INT16_C( 15332) },
      UINT32_C( 873831004),
      {  INT16_C( 14921), -INT16_C( 23504), -INT16_C(  8010), -INT16_C( 27909),  INT16_C( 30851), -INT16_C( 12900), -INT16_C( 15807), -INT16_C(  8491),
        -INT16_C(  8896),  INT16_C(  2781), -INT16_C( 28116), -INT16_C( 26698), -INT16_C( 11703), -INT16_C( 23204),  INT16_C( 29037), -INT16_C( 18727),
         INT16_C(  2731),  INT16_C( 24923),  INT16_C( 22250),  INT16_C( 28403), -INT16_C( 28722),  INT16_C(  3899),  INT16_C(  4434), -INT16_C( 27923),
        -INT16_C( 13586),  INT16_C(  6812),  INT16_C( 21085), -INT16_C( 22862),  INT16_C(  3621), -INT16_C( 28085),  INT16_C(  9343),  INT16_C( 10824) },
      {  INT16_C( 15501),  INT16_C(  4004), -INT16_C(  8010), -INT16_C( 27909),  INT16_C( 30851), -INT16_C( 19370), -INT16_C( 15807),  INT16_C(  9971),
        -INT16_C( 22738),  INT16_C(  2781), -INT16_C( 11074), -INT16_C( 26698), -INT16_C( 11703), -INT16_C( 19130),  INT16_C(  7650), -INT16_C( 18727),
         INT16_C(  2731),  INT16_C( 20606),  INT16_C( 22250), -INT16_C(   987), -INT16_C( 28722),  INT16_C( 22192), -INT16_C( 23588),  INT16_C(  2685),
        -INT16_C( 14006),  INT16_C(  2086),  INT16_C( 21085), -INT16_C(   248),  INT16_C(  3621), -INT16_C( 28085), -INT16_C( 18837), -INT16_C( 15332) } },
    { { -INT16_C( 23762),  INT16_C(  6540),  INT16_C( 32761), -INT16_C( 14457), -INT16_C( 15857),  INT16_C( 25046), -INT16_C( 15405), -INT16_C( 15629),
        -INT16_C( 28786), -INT16_C(  5156), -INT16_C( 28959),  INT16_C(  1681), -INT16_C(  9060),  INT16_C(  7064), -INT16_C(  7936),  INT16_C( 12102),
        -INT16_C( 11644),  INT16_C( 32328), -INT16_C( 12463),  INT16_C( 24645),  INT16_C(  7313),  INT16_C( 26049), -INT16_C( 19233),  INT16_C( 27943),
         INT16_C(   835),  INT16_C(  9560), -INT16_C(  5742),  INT16_C( 11819), -INT16_C( 15163), -INT16_C( 14774), -INT16_C( 28507),  INT16_C( 10741) },
      UINT32_C(3014081890),
      { -INT16_C(  4852), -INT16_C( 25324), -INT16_C( 10999), -INT16_C(  6142),  INT16_C( 10634), -INT16_C( 12970), -INT16_C( 20947), -INT16_C( 16398),
         INT16_C(  7832),  INT16_C( 24045),  INT16_C( 14306), -INT16_C( 30941),  INT16_C(  6343),  INT16_C( 10672),  INT16_C( 22613),  INT16_C( 25053),
        -INT16_C(  3771),  INT16_C( 20223),  INT16_C(   454),  INT16_C( 20534), -INT16_C( 29653),  INT16_C( 22558),  INT16_C(  4155), -INT16_C( 11497),
         INT16_C(  1070),  INT16_C(  4144),  INT16_C( 21564),  INT16_C(   919),  INT16_C( 18540), -INT16_C( 15827),  INT16_C(  2720), -INT16_C(  6877) },
      { -INT16_C( 23762), -INT16_C( 25324),  INT16_C( 32761), -INT16_C( 14457), -INT16_C( 15857), -INT16_C( 12970), -INT16_C( 20947), -INT16_C( 15629),
         INT16_C(  7832), -INT16_C(  5156),  INT16_C( 14306), -INT16_C( 30941),  INT16_C(  6343),  INT16_C( 10672), -INT16_C(  7936),  INT16_C( 12102),
        -INT16_C(  3771),  INT16_C( 20223),  INT16_C(   454),  INT16_C( 24645),  INT16_C(  7313),  INT16_C( 22558), -INT16_C( 19233), -INT16_C( 11497),
         INT16_C(  1070),  INT16_C(  4144), -INT16_C(  5742),  INT16_C( 11819),  INT16_C( 18540), -INT16_C( 15827), -INT16_C( 28507), -INT16_C(  6877) } },
    { {  INT16_C(  8955), -INT16_C( 16077),  INT16_C( 26916),  INT16_C( 20242),  INT16_C( 12534),  INT16_C( 12711), -INT16_C( 16832),  INT16_C( 28420),
         INT16_C( 13506), -INT16_C(   385),  INT16_C(  6024), -INT16_C(  2814),  INT16_C( 12127), -INT16_C(    73), -INT16_C(  9671),  INT16_C( 13540),
         INT16_C(  6141),  INT16_C(  8693),  INT16_C(  1920),  INT16_C( 30320),  INT16_C(  5943),  INT16_C( 30887), -INT16_C( 21547), -INT16_C( 26649),
         INT16_C( 26336),  INT16_C( 26774), -INT16_C( 26499), -INT16_C(  9123),  INT16_C(  5319),  INT16_C(   219), -INT16_C( 16401), -INT16_C(  5068) },
      UINT32_C(1460480470),
      {  INT16_C( 32049),  INT16_C( 26829),  INT16_C( 30100),  INT16_C( 27104), -INT16_C( 14560),  INT16_C(     0), -INT16_C( 27090), -INT16_C( 21655),
        -INT16_C( 14802), -INT16_C(  2680),  INT16_C( 25563), -INT16_C( 13579),  INT16_C( 10531), -INT16_C(  1610), -INT16_C( 15533), -INT16_C( 31664),
         INT16_C(  7744), -INT16_C( 11028), -INT16_C( 12909), -INT16_C( 19651),  INT16_C( 15764), -INT16_C( 15692),  INT16_C(  7636),  INT16_C(   622),
        -INT16_C(  2333), -INT16_C( 16648), -INT16_C(  4775),  INT16_C( 31880),  INT16_C( 15895),  INT16_C( 27254), -INT16_C( 14847),  INT16_C( 16878) },
      {  INT16_C(  8955),  INT16_C( 26829),  INT16_C( 30100),  INT16_C( 20242), -INT16_C( 14560),  INT16_C( 12711), -INT16_C( 27090), -INT16_C( 21655),
        -INT16_C( 14802), -INT16_C(   385),  INT16_C(  6024), -INT16_C( 13579),  INT16_C( 12127), -INT16_C(  1610), -INT16_C(  9671),  INT16_C( 13540),
         INT16_C(  7744),  INT16_C(  8693), -INT16_C( 12909), -INT16_C( 19651),  INT16_C(  5943),  INT16_C( 30887), -INT16_C( 21547), -INT16_C( 26649),
        -INT16_C(  2333), -INT16_C( 16648), -INT16_C(  4775), -INT16_C(  9123),  INT16_C( 15895),  INT16_C(   219), -INT16_C( 14847), -INT16_C(  5068) } },
    { { -INT16_C(  9500),  INT16_C( 30485),  INT16_C( 21159),  INT16_C( 15403), -INT16_C(  8304),  INT16_C( 25854),  INT16_C( 27900), -INT16_C(  8346),
         INT16_C( 24162), -INT16_C( 17250),  INT16_C(  9804),  INT16_C( 25400), -INT16_C( 20891),  INT16_C( 26317), -INT16_C( 17547),  INT16_C( 22952),
        -INT16_C( 17003),  INT16_C( 15825), -INT16_C(  1008), -INT16_C( 24455),  INT16_C( 30683), -INT16_C( 10492),  INT16_C( 27364),  INT16_C( 18102),
         INT16_C( 21705),  INT16_C(  5378),  INT16_C( 15227), -INT16_C(  8072),  INT16_C( 17897),  INT16_C( 24134), -INT16_C(  4608), -INT16_C( 27208) },
      UINT32_C(3167914412),
      {  INT16_C( 19333),  INT16_C( 24668),  INT16_C( 24771), -INT16_C( 22729), -INT16_C(  4662), -INT16_C( 27667), -INT16_C(  4030), -INT16_C( 16984),
         INT16_C(  8235),  INT16_C(  5277), -INT16_C(  7323),  INT16_C( 25971),  INT16_C( 11218),  INT16_C( 32507), -INT16_C( 12876),  INT16_C( 14650),
        -INT16_C( 27111), -INT16_C(  9063), -INT16_C( 12042), -INT16_C( 16253),  INT16_C( 28861), -INT16_C(   172), -INT16_C(   928), -INT16_C( 29764),
         INT16_C( 22813), -INT16_C( 32096),  INT16_C(  4925),  INT16_C(  4072), -INT16_C(  7362), -INT16_C(  3443), -INT16_C( 14416), -INT16_C( 14037) },
      { -INT16_C(  9500),  INT16_C( 30485),  INT16_C( 24771), -INT16_C( 22729), -INT16_C(  8304), -INT16_C( 27667),  INT16_C( 27900), -INT16_C( 16984),
         INT16_C(  8235), -INT16_C( 17250),  INT16_C(  9804),  INT16_C( 25971), -INT16_C( 20891),  INT16_C( 26317), -INT16_C( 17547),  INT16_C( 14650),
        -INT16_C( 17003), -INT16_C(  9063), -INT16_C(  1008), -INT16_C( 24455),  INT16_C( 28861), -INT16_C( 10492), -INT16_C(   928), -INT16_C( 29764),
         INT16_C( 21705),  INT16_C(  5378),  INT16_C(  4925),  INT16_C(  4072), -INT16_C(  7362), -INT16_C(  3443), -INT16_C(  4608), -INT16_C( 14037) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m512i src = simde_mm512_loadu_epi16(test_vec[i].src);
    simde_test_x86_assert_equal_i16x32(simde_mm512_load_si512(SIMDE_ALIGN_CAST(simde__m512i const *, test_vec[i].r)), simde_mm512_mask_loadu_epi16(src, test_vec[i].k, test_vec[i].a));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m512i src = simde_test_x86_random_i16x32();
    simde__mmask32 k = simde_test_x86_random_mmask32();
    simde__m512i a = simde_test_x86_random_i16x32();
    simde__m512i r = simde_mm512_mask_loadu_epi16(src, k, &a);

    simde_test_x86_write_i16x32(2, src, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_mmask32(2, k, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i16x32(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i16x32(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm512_maskz_loadu_epi16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask32 k;
    SIMDE_ALIGN_LIKE_32(simde__m512i) const int16_t a[32];
    const int16_t r[32];
  } test_vec[] = {
    { UINT32_C(2431718168),
      { -INT16_C(  4952),  INT16_C( 14258),  INT16_C( 22489),  INT16_C(  1404),  INT16_C( 16512), -INT16_C( 30609),  INT16_C( 15530),  INT16_C(  2009),
        -INT16_C( 16140), -INT16_C( 13502), -INT16_C(  5388), -INT16_C( 30196), -INT16_C(  5379),  INT16_C(  5579), -INT16_C( 17155), -INT16_C( 23131),
         INT16_C( 22697), -INT16_C( 32035),  INT16_C( 22959),  INT16_C( 12167), -INT16_C(  2407),  INT16_C( 17335), -INT16_C( 28366),  INT16_C(  9803),
        -INT16_C( 29359),  INT16_C( 17906), -INT16_C(   392),  INT16_C( 30159), -INT16_C( 25880), -INT16_C(  6517),  INT16_C( 12375),  INT16_C(   139) },
      {  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(  1404),  INT16_C( 16512),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
        -INT16_C( 16140), -INT16_C( 13502),  INT16_C(     0),  INT16_C(     0), -INT16_C(  5379),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
         INT16_C( 22697),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(  2407),  INT16_C( 17335), -INT16_C( 28366),  INT16_C(  9803),
         INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C( 25880),  INT16_C(     0),  INT16_C(     0),  INT16_C(   139) } },
    { UINT32_C( 931293320),
      {  INT16_C(  2497),  INT16_C( 23143),  INT16_C(  7935),  INT16_C( 12702), -INT16_C(  5713),  INT16_C(    88),  INT16_C( 19062), -INT16_C(  4538),
         INT16_C(  5448),  INT16_C( 12644), -INT16_C(  4176),  INT16_C(  1815), -INT16_C( 24033), -INT16_C( 22521), -INT16_C( 30453), -INT16_C( 13089),
         INT16_C( 18066), -INT16_C( 28377), -INT16_C( 15003),  INT16_C(  5314),  INT16_C(  6830),  INT16_C(  9237),  INT16_C( 23396), -INT16_C( 21229),
         INT16_C( 30576),  INT16_C(  8414), -INT16_C(  2714), -INT16_C( 31449),  INT16_C( 11927), -INT16_C( 24019),  INT16_C(  3511),  INT16_C( 18799) },
      {  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C( 12702),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C(  4538),
         INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(  1815),  INT16_C(     0), -INT16_C( 22521), -INT16_C( 30453),  INT16_C(     0),
         INT16_C(     0), -INT16_C( 28377),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C( 21229),
         INT16_C( 30576),  INT16_C(  8414), -INT16_C(  2714),  INT16_C(     0),  INT16_C( 11927), -INT16_C( 24019),  INT16_C(     0),  INT16_C(     0) } },
    { UINT32_C(3101333075),
      { -INT16_C( 25253),  INT16_C(  2509), -INT16_C(  7497),  INT16_C(  7213),  INT16_C( 16445), -INT16_C( 21047), -INT16_C( 22601),  INT16_C(  7630),
        -INT16_C(  2660),  INT16_C( 13219), -INT16_C( 12252), -INT16_C(  9258),  INT16_C( 17885),  INT16_C( 12581), -INT16_C(    37),  INT16_C( 14057),
        -INT16_C( 18788),  INT16_C( 21567),  INT16_C( 27800), -INT16_C( 10896),  INT16_C( 14765),  INT16_C( 25731),  INT16_C( 20960),  INT16_C( 31874),
         INT16_C(  9542),  INT16_C( 27311), -INT16_C( 31243), -INT16_C( 11450),  INT16_C( 27594), -INT16_C( 23292), -INT16_C(  4758),  INT16_C(  2011) },
      { -INT16_C( 25253),  INT16_C(  2509),  INT16_C(     0),  INT16_C(     0),  INT16_C( 16445),  INT16_C(     0), -INT16_C( 22601),  INT16_C(     0),
         INT16_C(     0),  INT16_C( 13219), -INT16_C( 12252),  INT16_C(     0),  INT16_C( 17885),  INT16_C(     0),  INT16_C(     0),  INT16_C( 14057),
         INT16_C(     0),  INT16_C( 21567),  INT16_C(     0), -INT16_C( 10896),  INT16_C( 14765),  INT16_C(     0),  INT16_C( 20960),  INT16_C( 31874),
         INT16_C(     0),  INT16_C(     0),  INT16_C(     0), -INT16_C( 11450),  INT16_C( 27594), -INT16_C( 23292),  INT16_C(     0),  INT16_C(  2011) } },
    { UINT32_C(1012603556),
      { -INT16_C( 13433),  INT16_C( 13330), -INT16_C( 27388), -INT16_C(  7016),  INT16_C(  6886),  INT16_C( 11360),  INT16_C(  3903),  INT16_C( 13719),
        -INT16_C(  8811),  INT16_C( 24328),  INT16_C(  3144), -INT16_C( 19963), -INT16_C(  7943), -INT16_C( 25159),  INT16_C(  5371), -INT16_C( 32038),
        -INT16_C(  4897), -INT16_C(  7242),  INT16_C( 20097),  INT16_C( 26567),  INT16_C( 10089), -INT16_C( 22381),  INT16_C( 10807), -INT16_C( 13091),
        -INT16_C(  6905),  INT16_C( 20267),  INT16_C( 12529), -INT16_C(  5374), -INT16_C( 17647),  INT16_C(  3208),  INT16_C( 25296), -INT16_C( 20594) },
      {  INT16_C(     0),  INT16_C(     0), -INT16_C( 27388),  INT16_C(     0),  INT16_C(     0),  INT16_C( 11360),  INT16_C(     0),  INT16_C( 13719),
         INT16_C(     0),  INT16_C( 24328),  INT16_C(     0), -INT16_C( 19963), -INT16_C(  7943),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
        -INT16_C(  4897), -INT16_C(  7242),  INT16_C(     0),  INT16_C( 26567),  INT16_C( 10089),  INT16_C(     0),  INT16_C( 10807),  INT16_C(     0),
         INT16_C(     0),  INT16_C(     0),  INT16_C( 12529), -INT16_C(  5374), -INT16_C( 17647),  INT16_C(  3208),  INT16_C(     0),  INT16_C(     0) } },
    { UINT32_C(3482534990),
      {  INT16_C( 23186), -INT16_C(  1226), -INT16_C( 13694), -INT16_C( 18012), -INT16_C( 32268), -INT16_C(   891), -INT16_C( 20377),  INT16_C( 22603),
         INT16_C( 19937), -INT16_C(  3517), -INT16_C( 13303), -INT16_C(  9730), -INT16_C( 29650),  INT16_C( 32136),  INT16_C(  7120),  INT16_C( 25164),
        -INT16_C( 31882), -INT16_C(  1954),  INT16_C(   589),  INT16_C( 16817),  INT16_C( 13955), -INT16_C(  5571), -INT16_C( 30234), -INT16_C( 14525),
        -INT16_C( 31018), -INT16_C(  8263), -INT16_C( 18606), -INT16_C( 32328),  INT16_C( 16707),  INT16_C(  5118),  INT16_C( 19036), -INT16_C( 11658) },
      {  INT16_C(     0), -INT16_C(  1226), -INT16_C( 13694), -INT16_C( 18012),  INT16_C(     0),  INT16_C(     0), -INT16_C( 20377),  INT16_C(     0),
         INT16_C(     0),  INT16_C(     0), -INT16_C( 13303),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(  7120),  INT16_C(     0),
        -INT16_C( 31882), -INT16_C(  1954),  INT16_C(     0),  INT16_C(     0),  INT16_C( 13955),  INT16_C(     0),  INT16_C(     0), -INT16_C( 14525),
        -INT16_C( 31018), -INT16_C(  8263), -INT16_C( 18606), -INT16_C( 32328),  INT16_C(     0),  INT16_C(     0),  INT16_C( 19036), -INT16_C( 11658) } },
    { UINT32_C( 449500365),
      {  INT16_C( 31702),  INT16_C( 22876), -INT16_C( 26191), -INT16_C( 26556), -INT16_C( 30942), -INT16_C(  1697),  INT16_C(  6413),  INT16_C( 24792),
        -INT16_C( 28208),  INT16_C(  5345), -INT16_C(  8238),  INT16_C( 11815), -INT16_C( 25303), -INT16_C(  2303), -INT16_C( 13455),  INT16_C( 18193),
         INT16_C( 27975), -INT16_C(  1887), -INT16_C(  6905),  INT16_C( 10640), -INT16_C(  3988),  INT16_C( 31010), -INT16_C(  1271), -INT16_C(  9767),
        -INT16_C( 17780),  INT16_C( 24301),  INT16_C(  5529), -INT16_C( 15476), -INT16_C( 29262),  INT16_C(  9402), -INT16_C( 13479), -INT16_C( 24469) },
      {  INT16_C( 31702),  INT16_C(     0), -INT16_C( 26191), -INT16_C( 26556),  INT16_C(     0),  INT16_C(     0),  INT16_C(  6413),  INT16_C( 24792),
         INT16_C(     0),  INT16_C(     0), -INT16_C(  8238),  INT16_C(     0), -INT16_C( 25303),  INT16_C(     0), -INT16_C( 13455),  INT16_C( 18193),
         INT16_C(     0), -INT16_C(  1887),  INT16_C(     0),  INT16_C( 10640),  INT16_C(     0),  INT16_C(     0), -INT16_C(  1271), -INT16_C(  9767),
         INT16_C(     0),  INT16_C( 24301),  INT16_C(     0), -INT16_C( 15476), -INT16_C( 29262),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0) } },
    { UINT32_C(1083706425),
      {  INT16_C( 10737),  INT16_C( 23913), -INT16_C( 29671),  INT16_C(  8919), -INT16_C( 20345),  INT16_C(  5115), -INT16_C(  5781),  INT16_C(  1137),
        -INT16_C(   514), -INT16_C( 20281), -INT16_C( 32373), -INT16_C(  6956),  INT16_C( 16461), -INT16_C( 31100),  INT16_C(  7244),  INT16_C( 16070),
         INT16_C( 12101),  INT16_C( 24219),  INT16_C( 29371),  INT16_C( 17024),  INT16_C( 31779), -INT16_C( 29099), -INT16_C( 14747),  INT16_C( 25490),
         INT16_C( 23236),  INT16_C( 20243), -INT16_C(  5925),  INT16_C( 10291), -INT16_C( 18648),  INT16_C( 29870),  INT16_C( 29907),  INT16_C(  6578) },
      {  INT16_C( 10737),  INT16_C(     0),  INT16_C(     0),  INT16_C(  8919), -INT16_C( 20345),  INT16_C(  5115),  INT16_C(     0),  INT16_C(     0),
         INT16_C(     0),  INT16_C(     0), -INT16_C( 32373), -INT16_C(  6956),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),
         INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C( 17024),  INT16_C( 31779),  INT16_C(     0),  INT16_C(     0),  INT16_C( 25490),
         INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C( 29907),  INT16_C(     0) } },
    { UINT32_C(1601654436),
      { -INT16_C(  1856), -INT16_C(  7262), -INT16_C(  2188), -INT16_C(  9871),  INT16_C(  1214), -INT16_C( 32196),  INT16_C( 20318),  INT16_C( 14801),
         INT16_C(  1079),  INT16_C( 24418),  INT16_C(  4283), -INT16_C( 28972), -INT16_C( 31099),  INT16_C( 10663),  INT16_C(  8148), -INT16_C( 27256),
         INT16_C( 10775), -INT16_C( 29832), -INT16_C(  5598), -INT16_C(  8092), -INT16_C( 24338),  INT16_C( 19554),  INT16_C( 13295),  INT16_C( 10117),
        -INT16_C(  6345), -INT16_C(  3450),  INT16_C( 23288),  INT16_C( 32128),  INT16_C( 10465), -INT16_C( 19034),  INT16_C( 11847),  INT16_C( 24138) },
      {  INT16_C(     0),  INT16_C(     0), -INT16_C(  2188),  INT16_C(     0),  INT16_C(     0), -INT16_C( 32196),  INT16_C(     0),  INT16_C( 14801),
         INT16_C(     0),  INT16_C( 24418),  INT16_C(  4283), -INT16_C( 28972),  INT16_C(     0),  INT16_C(     0),  INT16_C(  8148),  INT16_C(     0),
         INT16_C( 10775), -INT16_C( 29832), -INT16_C(  5598),  INT16_C(     0), -INT16_C( 24338),  INT16_C( 19554),  INT16_C( 13295),  INT16_C(     0),
        -INT16_C(  6345), -INT16_C(  3450),  INT16_C( 23288),  INT16_C( 32128),  INT16_C( 10465),  INT16_C(     0),  INT16_C( 11847),  INT16_C(     0) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_test_x86_assert_equal_i16x32(simde_mm512_load_si512(SIMDE_ALIGN_CAST(simde__m512i const *, test_vec[i].r)), simde_mm512_maskz_loadu_epi16(test_vec[i].k, test_vec[i].a));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__mmask32 k = simde_test_x86_random_mmask32();
    simde__m512i a = simde_test_x86_random_i16x32();
    simde__m512i r = simde_mm512_maskz_loadu_epi16(k, &a);

    simde_test_x86_write_mmask32(2, k, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i16x32(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i16x32(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm512_loadu_epi32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    SIMDE_ALIGN_LIKE_64(simde__m512i) const int32_t a[16];
    const int32_t r[16];
  } test_vec[] = {
    { { -INT32_C(  1085279312),  INT32_C(  1689654203), -INT32_C(  1704027444),  INT32_C(  1992004399),  INT32_C(  1598136076), -INT32_C(  1107314712),  INT32_C(  1634510512),  INT32_C(  2144272078),
        -INT32_C(  1405215247), -INT32_C(    65931984), -INT32_C(  1097433201),  INT32_C(   523522579), -INT32_C(   629246223), -INT32_C(   560497363), -INT32_C(   230751453), -INT32_C(   210694911) },
      { -INT32_C(  1085279312),  INT32_C(  1689654203), -INT32_C(  1704027444),  INT32_C(  1992004399),  INT32_C(  1598136076), -INT32_C(  1107314712),  INT32_C(  1634510512),  INT32_C(  2144272078),
        -INT32_C(  1405215247), -INT32_C(    65931984), -INT32_C(  1097433201),  INT32_C(   523522579), -INT32_C(   629246223), -INT32_C(   560497363), -INT32_C(   230751453), -INT32_C(   210694911) } },
    { {  INT32_C(  1537191723),  INT32_C(   878227620),  INT32_C(  1139994160),  INT32_C(   845293376), -INT32_C(   905125475), -INT32_C(  2102877346), -INT32_C(  1468733529),  INT32_C(   547087861),
         INT32_C(   964377492),  INT32_C(   460182507),  INT32_C(    39739330),  INT32_C(   590659974),  INT32_C(    15614114), -INT32_C(  1954375964),  INT32_C(  1932785278),  INT32_C(  1888735195) },
      {  INT32_C(  1537191723),  INT32_C(   878227620),  INT32_C(  1139994160),  INT32_C(   845293376), -INT32_C(   905125475), -INT32_C(  2102877346), -INT32_C(  1468733529),  INT32_C(   547087861),
         INT32_C(   964377492),  INT32_C(   460182507),  INT32_C(    39739330),  INT32_C(   590659974),  INT32_C(    15614114), -INT32_C(  1954375964),  INT32_C(  1932785278),  INT32_C(  1888735195) } },
    { { -INT32_C(   173470198), -INT32_C(  1542383902), -INT32_C(    56201355), -INT32_C(   769664208), -INT32_C(     2945765),  INT32_C(   579491236),  INT32_C(   664125004), -INT32_C(  1751701363),
         INT32_C(   411844662), -INT32_C(   860054186),  INT32_C(  1036542733),  INT32_C(  1494279998), -INT32_C(  1722162187), -INT32_C(  2068061384),  INT32_C(   783044769), -INT32_C(  1362803848) },
      { -INT32_C(   173470198), -INT32_C(  1542383902), -INT32_C(    56201355), -INT32_C(   769664208), -INT32_C(     2945765),  INT32_C(   579491236),  INT32_C(   664125004), -INT32_C(  1751701363),
         INT32_C(   411844662), -INT32_C(   860054186),  INT32_C(  1036542733),  INT32_C(  1494279998), -INT32_C(  1722162187), -INT32_C(  2068061384),  INT32_C(   783044769), -INT32_C(  1362803848) } },
    { { -INT32_C(   624471420), -INT32_C(    56196113),  INT32_C(   607809254),  INT32_C(  1266567766),  INT32_C(  1709496109),  INT32_C(  1558880186),  INT32_C(  1737135855),  INT32_C(  1561678041),
        -INT32_C(  1858544478),  INT32_C(  1183768160), -INT32_C(  1553217459),  INT32_C(  1072621842),  INT32_C(  2057622208),  INT32_C(  1624673905), -INT32_C(    20487900),  INT32_C(  1398529201) },
      { -INT32_C(   624471420), -INT32_C(    56196113),  INT32_C(   607809254),  INT32_C(  1266567766),  INT32_C(  1709496109),  INT32_C(  1558880186),  INT32_C(  1737135855),  INT32_C(  1561678041),
        -INT32_C(  1858544478),  INT32_C(  1183768160), -INT32_C(  1553217459),  INT32_C(  1072621842),  INT32_C(  2057622208),  INT32_C(  1624673905), -INT32_C(    20487900),  INT32_C(  1398529201) } },
    { {  INT32_C(   434410425), -INT32_C(  1084263822),  INT32_C(  1281542714),  INT32_C(  1938510003), -INT32_C(  1813106654), -INT32_C(   470563650), -INT32_C(   689849819),  INT32_C(  1328102550),
         INT32_C(  1114115792), -INT32_C(  1157511040),  INT32_C(  1174889362), -INT32_C(   709258317), -INT32_C(  2123847741), -INT32_C(  1855693972), -INT32_C(  1419229931),  INT32_C(  1392218498) },
      {  INT32_C(   434410425), -INT32_C(  1084263822),  INT32_C(  1281542714),  INT32_C(  1938510003), -INT32_C(  1813106654), -INT32_C(   470563650), -INT32_C(   689849819),  INT32_C(  1328102550),
         INT32_C(  1114115792), -INT32_C(  1157511040),  INT32_C(  1174889362), -INT32_C(   709258317), -INT32_C(  2123847741), -INT32_C(  1855693972), -INT32_C(  1419229931),  INT32_C(  1392218498) } },
    { {  INT32_C(   546595743), -INT32_C(  1092905685), -INT32_C(  1425743112),  INT32_C(   947961205), -INT32_C(   776279963),  INT32_C(  1482825283), -INT32_C(   435959196), -INT32_C(    80150948),
        -INT32_C(  1927558046),  INT32_C(  1498150497),  INT32_C(  1308905433),  INT32_C(  1921483789), -INT32_C(  1354546836), -INT32_C(  1022909089), -INT32_C(   861336976),  INT32_C(  1808261385) },
      {  INT32_C(   546595743), -INT32_C(  1092905685), -INT32_C(  1425743112),  INT32_C(   947961205), -INT32_C(   776279963),  INT32_C(  1482825283), -INT32_C(   435959196), -INT32_C(    80150948),
        -INT32_C(  1927558046),  INT32_C(  1498150497),  INT32_C(  1308905433),  INT32_C(  1921483789), -INT32_C(  1354546836), -INT32_C(  1022909089), -INT32_C(   861336976),  INT32_C(  1808261385) } },
    { {  INT32_C(   251192237), -INT32_C(  1301855015), -INT32_C(  1610519661),  INT32_C(  1527941359),  INT32_C(   671765961),  INT32_C(  1810633211),  INT32_C(   624399644),  INT32_C(   613482103),
        -INT32_C(  1154250527),  INT32_C(  1617795788), -INT32_C(   184521210), -INT32_C(  1085205514),  INT32_C(  1676172136), -INT32_C(  1982933907), -INT32_C(   525466263), -INT32_C(   452641276) },
      {  INT32_C(   251192237), -INT32_C(  1301855015), -INT32_C(  1610519661),  INT32_C(  1527941359),  INT32_C(   671765961),  INT32_C(  1810633211),  INT32_C(   624399644),  INT32_C(   613482103),
        -INT32_C(  1154250527),  INT32_C(  1617795788), -INT32_C(   184521210), -INT32_C(  1085205514),  INT32_C(  1676172136), -INT32_C(  1982933907), -INT32_C(   525466263), -INT32_C(   452641276) } },
    { { -INT32_C(  1818216250), -INT32_C(   655159598),  INT32_C(  1942942588),  INT32_C(  1865555718), -INT32_C(   405661062),  INT32_C(  1483776494), -INT32_C(  1439162714),  INT32_C(   596655452),
         INT32_C(  1219899509), -INT32_C(  1155487426), -INT32_C(  1557205348), -INT32_C(  2012061683),  INT32_C(  1768940667),  INT32_C(   750903429),  INT32_C(  1540815614), -INT32_C(  1384225225) },
      { -INT32_C(  1818216250), -INT32_C(   655159598),  INT32_C(  1942942588),  INT32_C(  1865555718), -INT32_C(   405661062),  INT32_C(  1483776494), -INT32_C(  1439162714),  INT32_C(   596655452),
         INT32_C(  1219899509), -INT32_C(  1155487426), -INT32_C(  1557205348), -INT32_C(  2012061683),  INT32_C(  1768940667),  INT32_C(   750903429),  INT32_C(  1540815614), -INT32_C(  1384225225) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_test_x86_assert_equal_i32x16(simde_mm512_load_si512(test_vec[i].a), simde_mm512_loadu_epi32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m512i a = simde_test_x86_random_i32x16();
    simde__m512i r = a;

    simde_test_x86_write_i32x16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i32x16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm512_mask_loadu_epi32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int32_t src[16];
    const simde__mmask16 k;
    SIMDE_ALIGN_LIKE_32(simde__m512i) const int32_t a[16];
    const int32_t r[16];
  } test_vec[] = {
    { { -INT32_C(   640709495), -INT32_C(  1607141307), -INT32_C(  1798478791),  INT32_C(  1157732015), -INT32_C(   280149911),  INT32_C(   276154626), -INT32_C(  1400980507), -INT32_C(   434108323),
        -INT32_C(   624955244),  INT32_C(   578483176),  INT32_C(   112609111),  INT32_C(  1179367645), -INT32_C(    97150728),  INT32_C(  1191946850), -INT32_C(  1024226971),  INT32_C(   648549265) },
      UINT16_C(26371),
      {  INT32_C(  2052779008), -INT32_C(   993939186),  INT32_C(    41721527),  INT32_C(   429618660),  INT32_C(  2059730287),  INT32_C(   923019588), -INT32_C(  1807051284), -INT32_C(  1141092677),
         INT32_C(  1211455034), -INT32_C(  1089669624),  INT32_C(  2026015124),  INT32_C(  1838308862), -INT32_C(  1628940710),  INT32_C(  1809181823),  INT32_C(  1023418241), -INT32_C(  1476854675) },
      {  INT32_C(  2052779008), -INT32_C(   993939186), -INT32_C(  1798478791),  INT32_C(  1157732015), -INT32_C(   280149911),  INT32_C(   276154626), -INT32_C(  1400980507), -INT32_C(   434108323),
         INT32_C(  1211455034), -INT32_C(  1089669624),  INT32_C(  2026015124),  INT32_C(  1179367645), -INT32_C(    97150728),  INT32_C(  1809181823),  INT32_C(  1023418241),  INT32_C(   648549265) } },
    { {  INT32_C(  1525624402), -INT32_C(  1189413852), -INT32_C(  2093884283), -INT32_C(  1812937927), -INT32_C(  1724786663),  INT32_C(  1174668996), -INT32_C(  1820130267),  INT32_C(  1396341504),
        -INT32_C(   827512151), -INT32_C(  1417165018), -INT32_C(   600917853), -INT32_C(  1787879812), -INT32_C(  1154572041), -INT32_C(   872336474),  INT32_C(   945783863), -INT32_C(  1450469120) },
      UINT16_C(14531),
      { -INT32_C(    33494665), -INT32_C(  1028152428), -INT32_C(   270453888), -INT32_C(   141502264), -INT32_C(  1792395629),  INT32_C(  1629053186),  INT32_C(   620435865),  INT32_C(   979222211),
         INT32_C(  1010392488), -INT32_C(  2130710528), -INT32_C(   344924125),  INT32_C(  1273102520),  INT32_C(   970984502),  INT32_C(   127597166), -INT32_C(   701721325), -INT32_C(    65959596) },
      { -INT32_C(    33494665), -INT32_C(  1028152428), -INT32_C(  2093884283), -INT32_C(  1812937927), -INT32_C(  1724786663),  INT32_C(  1174668996),  INT32_C(   620435865),  INT32_C(   979222211),
        -INT32_C(   827512151), -INT32_C(  1417165018), -INT32_C(   600917853),  INT32_C(  1273102520),  INT32_C(   970984502),  INT32_C(   127597166),  INT32_C(   945783863), -INT32_C(  1450469120) } },
    { { -INT32_C(   432518426),  INT32_C(  1567045434), -INT32_C(   817309929),  INT32_C(   219884503), -INT32_C(  1522074825),  INT32_C(   162390517), -INT32_C(   891299466),  INT32_C(  1220997218),
         INT32_C(  1949237050),  INT32_C(  1322358070),  INT32_C(  1125980780),  INT32_C(  2085697605),  INT32_C(   690132788), -INT32_C(   281882760),  INT32_C(   179901096),  INT32_C(  1028816898) },
      UINT16_C(32895),
      { -INT32_C(  2095663695),  INT32_C(   563970563),  INT32_C(   391766726), -INT32_C(  2136044194), -INT32_C(   380688457), -INT32_C(   805570794),  INT32_C(  1397751297), -INT32_C(   321597893),
        -INT32_C(  2022708604),  INT32_C(   849874028),  INT32_C(  1296630510),  INT32_C(  1187903631),  INT32_C(   892345631),  INT32_C(   369371924),  INT32_C(  1684624425), -INT32_C(  1504625374) },
      { -INT32_C(  2095663695),  INT32_C(   563970563),  INT32_C(   391766726), -INT32_C(  2136044194), -INT32_C(   380688457), -INT32_C(   805570794),  INT32_C(  1397751297),  INT32_C(  1220997218),
         INT32_C(  1949237050),  INT32_C(  1322358070),  INT32_C(  1125980780),  INT32_C(  2085697605),  INT32_C(   690132788), -INT32_C(   281882760),  INT32_C(   179901096), -INT32_C(  1504625374) } },
    { { -INT32_C(  1808875481), -INT32_C(  1144596787),  INT32_C(  1745359064),  INT32_C(   665769480),  INT32_C(   123526899),  INT32_C(   857563146), -INT32_C(   677869644), -INT32_C(   327292476),
         INT32_C(  1988144041),  INT32_C(  1513244290),  INT32_C(  1589787222),  INT32_C(    59076880),  INT32_C(  1493950799), -INT32_C(   158521278),  INT32_C(  1959601583), -INT32_C(  1218426098) },
      UINT16_C(57590),
      {  INT32_C(  1613133870), -INT32_C(  1785037357),  INT32_C(  1627827163), -INT32_C(  1186834770),  INT32_C(  1021478063),  INT32_C(  1214353787),  INT32_C(  1704161029),  INT32_C(  1430620711),
        -INT32_C(   709530622), -INT32_C(   999600151), -INT32_C(  1457163782),  INT32_C(  2002938055),  INT32_C(  1739801836), -INT32_C(   609217066), -INT32_C(  1421786236), -INT32_C(   805271859) },
      { -INT32_C(  1808875481), -INT32_C(  1785037357),  INT32_C(  1627827163),  INT32_C(   665769480),  INT32_C(  1021478063),  INT32_C(  1214353787),  INT32_C(  1704161029),  INT32_C(  1430620711),
         INT32_C(  1988144041),  INT32_C(  1513244290),  INT32_C(  1589787222),  INT32_C(    59076880),  INT32_C(  1493950799), -INT32_C(   609217066), -INT32_C(  1421786236), -INT32_C(   805271859) } },
    { { -INT32_C(   609896974), -INT32_C(     6287355),  INT32_C(  1235797378),  INT32_C(   448793389),  INT32_C(   629240911),  INT32_C(   218182025),  INT32_C(  1119437429), -INT32_C(  1156400696),
         INT32_C(  1956034671),  INT32_C(  1249064648),  INT32_C(   697572604),  INT32_C(  1984123943),  INT32_C(  1369228744),  INT32_C(  1801428470), -INT32_C(  1481762593),  INT32_C(  1080213713) },
      UINT16_C(63864),
      {  INT32_C(   674185652),  INT32_C(   524561291), -INT32_C(  1737200811),  INT32_C(  2103262433), -INT32_C(   317041522),  INT32_C(  1829108159),  INT32_C(    53401249), -INT32_C(   872634857),
         INT32_C(  1945316583), -INT32_C(  1399703721), -INT32_C(  2075851102), -INT32_C(   788422077), -INT32_C(  1229054730), -INT32_C(  1239170283), -INT32_C(  1329966695), -INT32_C(   545474824) },
      { -INT32_C(   609896974), -INT32_C(     6287355),  INT32_C(  1235797378),  INT32_C(  2103262433), -INT32_C(   317041522),  INT32_C(  1829108159),  INT32_C(    53401249), -INT32_C(  1156400696),
         INT32_C(  1945316583),  INT32_C(  1249064648),  INT32_C(   697572604), -INT32_C(   788422077), -INT32_C(  1229054730), -INT32_C(  1239170283), -INT32_C(  1329966695), -INT32_C(   545474824) } },
    { {  INT32_C(   978481122),  INT32_C(  1239868839),  INT32_C(   785198059), -INT32_C(   989868082),  INT32_C(     8044011),  INT32_C(   448241280), -INT32_C(   406162961),  INT32_C(   180831783),
         INT32_C(  1564744118), -INT32_C(   358208770),  INT32_C(   605582422),  INT32_C(   786962499),  INT32_C(  1445880789), -INT32_C(   261036799),  INT32_C(  2128099926),  INT32_C(   931700609) },
      UINT16_C(52408),
      {  INT32_C(   989247380), -INT32_C(  1179759455),  INT32_C(  1506931056),  INT32_C(  1320986399),  INT32_C(  1832107517), -INT32_C(  2052617555), -INT32_C(  1876678648), -INT32_C(   212017825),
         INT32_C(   892228244),  INT32_C(   267312287), -INT32_C(   311902002),  INT32_C(  1681597543), -INT32_C(  1882099743),  INT32_C(    18118905),  INT32_C(     9517473), -INT32_C(  1426789098) },
      {  INT32_C(   978481122),  INT32_C(  1239868839),  INT32_C(   785198059),  INT32_C(  1320986399),  INT32_C(  1832107517), -INT32_C(  2052617555), -INT32_C(   406162961), -INT32_C(   212017825),
         INT32_C(  1564744118), -INT32_C(   358208770), -INT32_C(   311902002),  INT32_C(  1681597543),  INT32_C(  1445880789), -INT32_C(   261036799),  INT32_C(     9517473), -INT32_C(  1426789098) } },
    { { -INT32_C(   555802049), -INT32_C(   856764930), -INT32_C(   189114739),  INT32_C(  1549333883),  INT32_C(  1575692644),  INT32_C(  1130234018),  INT32_C(  1329852217),  INT32_C(   486094812),
         INT32_C(  1492834393),  INT32_C(   858056869), -INT32_C(  1171792321),  INT32_C(   940998868),  INT32_C(  1268122281),  INT32_C(   999224322), -INT32_C(  1064643868),  INT32_C(  1675395849) },
      UINT16_C(55131),
      { -INT32_C(   541130565),  INT32_C(  1539243571), -INT32_C(   807693640),  INT32_C(  1624343754),  INT32_C(  1582683088), -INT32_C(  1741670130), -INT32_C(   702858503),  INT32_C(  1487763101),
        -INT32_C(  1439208330),  INT32_C(   587593067),  INT32_C(  1391648903),  INT32_C(   884130660), -INT32_C(  1533868138),  INT32_C(   977060672), -INT32_C(  1710204931),  INT32_C(  1156758989) },
      { -INT32_C(   541130565),  INT32_C(  1539243571), -INT32_C(   189114739),  INT32_C(  1624343754),  INT32_C(  1582683088),  INT32_C(  1130234018), -INT32_C(   702858503),  INT32_C(   486094812),
        -INT32_C(  1439208330),  INT32_C(   587593067),  INT32_C(  1391648903),  INT32_C(   940998868), -INT32_C(  1533868138),  INT32_C(   999224322), -INT32_C(  1710204931),  INT32_C(  1156758989) } },
    { { -INT32_C(  1796330967), -INT32_C(  1481051361),  INT32_C(   939109075),  INT32_C(    74230638), -INT32_C(   206962765), -INT32_C(  1070733886),  INT32_C(   173686077),  INT32_C(   609111546),
        -INT32_C(  1766310793),  INT32_C(    37580847), -INT32_C(  1992673765), -INT32_C(  1785878814),  INT32_C(  1736980133),  INT32_C(  1495774748), -INT32_C(   295468301),  INT32_C(  1175630543) },
      UINT16_C(51950),
      {  INT32_C(   440082140),  INT32_C(  1515214368),  INT32_C(  1811952351),  INT32_C(  1352902087),  INT32_C(   872857357),  INT32_C(  2075588888), -INT32_C(   114457113), -INT32_C(  1463542581),
         INT32_C(  1522728762),  INT32_C(   884281941),  INT32_C(   211858757),  INT32_C(  1750877019),  INT32_C(   446456322),  INT32_C(  1133925212), -INT32_C(  1539456040),  INT32_C(   424411615) },
      { -INT32_C(  1796330967),  INT32_C(  1515214368),  INT32_C(  1811952351),  INT32_C(  1352902087), -INT32_C(   206962765),  INT32_C(  2075588888), -INT32_C(   114457113), -INT32_C(  1463542581),
        -INT32_C(  1766310793),  INT32_C(   884281941), -INT32_C(  1992673765),  INT32_C(  1750877019),  INT32_C(  1736980133),  INT32_C(  1495774748), -INT32_C(  1539456040),  INT32_C(   424411615) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m512i src = simde_mm512_loadu_epi32(test_vec[i].src);
    simde_test_x86_assert_equal_i32x16(simde_mm512_load_si512(SIMDE_ALIGN_CAST(simde__m512i const *, test_vec[i].r)), simde_mm512_mask_loadu_epi32(src, test_vec[i].k, test_vec[i].a));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m512i src = simde_test_x86_random_i32x16();
    simde__mmask32 k = simde_test_x86_random_mmask16();
    simde__m512i a = simde_test_x86_random_i32x16();
    simde__m512i r = simde_mm512_mask_loadu_epi32(src, k, &a);

    simde_test_x86_write_i32x16(2, src, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_mmask16(2, k, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x16(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm512_loadu_epi64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    SIMDE_ALIGN_LIKE_64(simde__m512i) const int64_t a[8];
    const int64_t r[8];
  } test_vec[] = {
    { { -INT64_C( 2031689546876671122), -INT64_C( 4181824216786536295),  INT64_C( 3378378289711491617),  INT64_C( 1413316256384642707),
        -INT64_C( 4698950795030485050),  INT64_C( 7475600748512024817), -INT64_C( 2293462173326056235),  INT64_C( 2603685720003003242) },
      { -INT64_C( 2031689546876671122), -INT64_C( 4181824216786536295),  INT64_C( 3378378289711491617),  INT64_C( 1413316256384642707),
        -INT64_C( 4698950795030485050),  INT64_C( 7475600748512024817), -INT64_C( 2293462173326056235),  INT64_C( 2603685720003003242) } },
    { {  INT64_C( 4049249843808980558),  INT64_C( 7392641815426491883),  INT64_C( 1801878204460544724), -INT64_C(   48330471621752111),
         INT64_C( 2024547467117354649),  INT64_C( 1044804576756910729),  INT64_C( 4782031642370761366),  INT64_C( 7668159918304822970) },
      {  INT64_C( 4049249843808980558),  INT64_C( 7392641815426491883),  INT64_C( 1801878204460544724), -INT64_C(   48330471621752111),
         INT64_C( 2024547467117354649),  INT64_C( 1044804576756910729),  INT64_C( 4782031642370761366),  INT64_C( 7668159918304822970) } },
    { {  INT64_C(  680433322035960868),  INT64_C( 4032026382637907372),  INT64_C( 1024807869850854276), -INT64_C( 7738621839182026145),
        -INT64_C(  916101787114937152), -INT64_C( 7858554787118552041), -INT64_C( 6533667226337645326),  INT64_C( 8173594282907061610) },
      {  INT64_C(  680433322035960868),  INT64_C( 4032026382637907372),  INT64_C( 1024807869850854276), -INT64_C( 7738621839182026145),
        -INT64_C(  916101787114937152), -INT64_C( 7858554787118552041), -INT64_C( 6533667226337645326),  INT64_C( 8173594282907061610) } },
    { { -INT64_C( 3994697604197623979),  INT64_C( 3028796336221808999), -INT64_C( 4986958888383311650),  INT64_C( 7327921812528210064),
        -INT64_C( 4048013273381903271), -INT64_C( 6603326236083268358),  INT64_C( 2296716578005830869), -INT64_C( 3555290135981427917) },
      { -INT64_C( 3994697604197623979),  INT64_C( 3028796336221808999), -INT64_C( 4986958888383311650),  INT64_C( 7327921812528210064),
        -INT64_C( 4048013273381903271), -INT64_C( 6603326236083268358),  INT64_C( 2296716578005830869), -INT64_C( 3555290135981427917) } },
    { {  INT64_C( 3935770298369485431), -INT64_C(  762861917337756674), -INT64_C(  558453203728190831),  INT64_C( 2931813335080607596),
         INT64_C( 3458938454811838351), -INT64_C( 4643389136534410887),  INT64_C( 1174628764682791568), -INT64_C(  245550163283572547) },
      {  INT64_C( 3935770298369485431), -INT64_C(  762861917337756674), -INT64_C(  558453203728190831),  INT64_C( 2931813335080607596),
         INT64_C( 3458938454811838351), -INT64_C( 4643389136534410887),  INT64_C( 1174628764682791568), -INT64_C(  245550163283572547) } },
    { { -INT64_C( 5869378661672118744),  INT64_C( 7934735468561203248), -INT64_C( 2939425477300585343), -INT64_C( 1152397282285115752),
        -INT64_C( 4659583426481174413), -INT64_C(  675194194085700267),  INT64_C(  947814707075179574), -INT64_C( 4886946240843846537) },
      { -INT64_C( 5869378661672118744),  INT64_C( 7934735468561203248), -INT64_C( 2939425477300585343), -INT64_C( 1152397282285115752),
        -INT64_C( 4659583426481174413), -INT64_C(  675194194085700267),  INT64_C(  947814707075179574), -INT64_C( 4886946240843846537) } },
    { { -INT64_C( 6617272956007253540), -INT64_C( 5205464620909246634), -INT64_C( 6530450158184309283),  INT64_C( 7034361509239288218),
         INT64_C( 1332492355739845515), -INT64_C( 6091786111122778819),  INT64_C( 4994593874853592189), -INT64_C( 3335539744629574450) },
      { -INT64_C( 6617272956007253540), -INT64_C( 5205464620909246634), -INT64_C( 6530450158184309283),  INT64_C( 7034361509239288218),
         INT64_C( 1332492355739845515), -INT64_C( 6091786111122778819),  INT64_C( 4994593874853592189), -INT64_C( 3335539744629574450) } },
    { { -INT64_C( 5361209383270579765), -INT64_C( 7640663431528024195),  INT64_C( 2185812967214347366),  INT64_C( 1286946775314366149),
         INT64_C( 3158766812587919016), -INT64_C( 7397886743846434135), -INT64_C( 1382324539653187999),  INT64_C( 1284884244920222333) },
      { -INT64_C( 5361209383270579765), -INT64_C( 7640663431528024195),  INT64_C( 2185812967214347366),  INT64_C( 1286946775314366149),
         INT64_C( 3158766812587919016), -INT64_C( 7397886743846434135), -INT64_C( 1382324539653187999),  INT64_C( 1284884244920222333) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_test_x86_assert_equal_i64x8(simde_mm512_load_si512(test_vec[i].a), simde_mm512_loadu_epi64(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m512i a = simde_test_x86_random_i64x8();
    simde__m512i r = a;

    simde_test_x86_write_i64x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i64x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm512_mask_loadu_epi64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int64_t src[8];
    const simde__mmask8 k;
    SIMDE_ALIGN_LIKE_64(simde__m512i) const int64_t a[8];
    const int64_t r[8];
  } test_vec[] = {
    { { -INT64_C( 5891717348901396017), -INT64_C( 6324217136638969121),  INT64_C( 5044298211983013792),  INT64_C(  503410536364060286),
        -INT64_C(   48784091231570598),  INT64_C(  186533672071496937),  INT64_C( 7507637927224866923),  INT64_C( 3451896779000077226) },
      UINT8_C( 79),
      { -INT64_C( 6200772635879550374),  INT64_C( 8071873813979849190),  INT64_C( 8913119679872692106), -INT64_C( 3078070179162188960),
         INT64_C(  873646815866435409), -INT64_C( 4352259307171599694),  INT64_C( 1672660340674589851),  INT64_C( 6295567209419802126) },
      { -INT64_C( 6200772635879550374),  INT64_C( 8071873813979849190),  INT64_C( 8913119679872692106), -INT64_C( 3078070179162188960),
        -INT64_C(   48784091231570598),  INT64_C(  186533672071496937),  INT64_C( 1672660340674589851),  INT64_C( 3451896779000077226) } },
    { { -INT64_C( 4664625247527551984),  INT64_C( 3463974641203800342),  INT64_C( 7369051548601277558), -INT64_C( 4754589893958609496),
        -INT64_C( 3146264902722268791),  INT64_C( 4100023621163106081), -INT64_C( 7219645190222982895), -INT64_C( 7751736150359228929) },
      UINT8_C( 30),
      { -INT64_C( 4487080008042665119),  INT64_C( 2961604212452192723),  INT64_C(  994089700415013153),  INT64_C( 5074339505987156479),
        -INT64_C( 3883903916003342377),  INT64_C( 8758352665199680522),  INT64_C( 6758233289406130028),  INT64_C( 7328787670118359690) },
      { -INT64_C( 4664625247527551984),  INT64_C( 2961604212452192723),  INT64_C(  994089700415013153),  INT64_C( 5074339505987156479),
        -INT64_C( 3883903916003342377),  INT64_C( 4100023621163106081), -INT64_C( 7219645190222982895), -INT64_C( 7751736150359228929) } },
    { {  INT64_C( 4043624630127006812),  INT64_C( 5063494977697017715),  INT64_C( 2704356167567772364), -INT64_C( 6727734327308439121),
        -INT64_C( 6178074240484024355), -INT64_C( 3593105031253598975), -INT64_C( 6843641902609717947), -INT64_C( 4496139557076559183) },
      UINT8_C(223),
      { -INT64_C( 1395060286178276209), -INT64_C( 4164214876716237003), -INT64_C( 5267706215756458572),  INT64_C(  474667376178814007),
        -INT64_C( 6763197812241290200), -INT64_C( 8993187287205276982),  INT64_C( 8768117335991511516), -INT64_C( 3749871607809554311) },
      { -INT64_C( 1395060286178276209), -INT64_C( 4164214876716237003), -INT64_C( 5267706215756458572),  INT64_C(  474667376178814007),
        -INT64_C( 6763197812241290200), -INT64_C( 3593105031253598975),  INT64_C( 8768117335991511516), -INT64_C( 3749871607809554311) } },
    { { -INT64_C( 5511799108508869261), -INT64_C( 5220708966364933063),  INT64_C( 6482471932392325946),  INT64_C( 6995285310070859429),
         INT64_C( 8680902956104619995),  INT64_C( 2407469665077991383),  INT64_C( 2056337940214061392), -INT64_C( 1510543091849375302) },
      UINT8_C(145),
      { -INT64_C( 4691546678752202934),  INT64_C( 1739735257670129352), -INT64_C( 5785810651401202587), -INT64_C( 5829160514109940720),
        -INT64_C(  486494100259018151),  INT64_C( 1319258562317182262), -INT64_C( 7434387968417342137), -INT64_C( 7768924605940395493) },
      { -INT64_C( 4691546678752202934), -INT64_C( 5220708966364933063),  INT64_C( 6482471932392325946),  INT64_C( 6995285310070859429),
        -INT64_C(  486494100259018151),  INT64_C( 2407469665077991383),  INT64_C( 2056337940214061392), -INT64_C( 7768924605940395493) } },
    { { -INT64_C( 4516735993837655258),  INT64_C( 6410668537760128825), -INT64_C( 2431292051812449502), -INT64_C( 4201138688322804766),
         INT64_C( 6108691006903666553),  INT64_C( 2663651591927283085), -INT64_C( 6353153261179079628),  INT64_C( 4312609789328044916) },
      UINT8_C( 63),
      { -INT64_C( 4255427730900107018), -INT64_C(  409850079860060183),  INT64_C( 5638056053066122937),  INT64_C( 2369257525453279531),
        -INT64_C( 3146479110029296501), -INT64_C( 4573901268926456827), -INT64_C( 2959488740687723133), -INT64_C( 3214063492626055910) },
      { -INT64_C( 4255427730900107018), -INT64_C(  409850079860060183),  INT64_C( 5638056053066122937),  INT64_C( 2369257525453279531),
        -INT64_C( 3146479110029296501), -INT64_C( 4573901268926456827), -INT64_C( 6353153261179079628),  INT64_C( 4312609789328044916) } },
    { {  INT64_C( 7229889696168733078),  INT64_C(  332551148129960918),  INT64_C(  737342326176950458), -INT64_C( 6581812879600667507),
        -INT64_C( 7178602810976170851), -INT64_C( 9204487077491027779),  INT64_C(  232535122256455231), -INT64_C( 2700048448281343531) },
      UINT8_C(140),
      { -INT64_C( 8654811038730692692),  INT64_C( 5458307109224260201), -INT64_C( 5645046453278478670), -INT64_C( 4708292330783863908),
         INT64_C( 6079798937238436768),  INT64_C( 3141985839284006122), -INT64_C( 4946176011281671295), -INT64_C( 5547169120260765133) },
      {  INT64_C( 7229889696168733078),  INT64_C(  332551148129960918), -INT64_C( 5645046453278478670), -INT64_C( 4708292330783863908),
        -INT64_C( 7178602810976170851), -INT64_C( 9204487077491027779),  INT64_C(  232535122256455231), -INT64_C( 5547169120260765133) } },
    { { -INT64_C( 7297263302356572037), -INT64_C( 6756944112908661099),  INT64_C( 1421071366711163358), -INT64_C( 8450902381665087502),
        -INT64_C( 4498908917644901819), -INT64_C( 2523411082961192392), -INT64_C( 2146085137327503293),  INT64_C( 3655409888641126433) },
      UINT8_C(225),
      {  INT64_C( 3714572187559864490),  INT64_C( 3020803613404489119), -INT64_C( 2983076998075052058),  INT64_C( 3414562516473465570),
        -INT64_C( 2447125581137743842),  INT64_C( 3314494603147033589), -INT64_C(  747809658900244350),  INT64_C( 8628009964783690505) },
      {  INT64_C( 3714572187559864490), -INT64_C( 6756944112908661099),  INT64_C( 1421071366711163358), -INT64_C( 8450902381665087502),
        -INT64_C( 4498908917644901819),  INT64_C( 3314494603147033589), -INT64_C(  747809658900244350),  INT64_C( 8628009964783690505) } },
    { {  INT64_C( 5000782638660665417), -INT64_C( 2159164443523748460), -INT64_C(  631264885985267916), -INT64_C( 3062938626887994450),
        -INT64_C( 4965566963345666687), -INT64_C( 9010681072780365136), -INT64_C( 7551121601366221232),  INT64_C( 8870998326776871354) },
      UINT8_C(234),
      { -INT64_C( 7643227166467863431), -INT64_C( 8118470667405099420), -INT64_C( 9011965877268409553), -INT64_C( 3767551003747141969),
        -INT64_C(  486962062073214908), -INT64_C( 5371575517185105676), -INT64_C( 5966465768887751192), -INT64_C( 1500490704886321392) },
      {  INT64_C( 5000782638660665417), -INT64_C( 8118470667405099420), -INT64_C(  631264885985267916), -INT64_C( 3767551003747141969),
        -INT64_C( 4965566963345666687), -INT64_C( 5371575517185105676), -INT64_C( 5966465768887751192), -INT64_C( 1500490704886321392) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m512i src = simde_mm512_loadu_epi64(test_vec[i].src);
    simde_test_x86_assert_equal_i64x8(simde_mm512_load_si512(SIMDE_ALIGN_CAST(simde__m512i const *, test_vec[i].r)), simde_mm512_mask_loadu_epi64(src, test_vec[i].k, test_vec[i].a));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m512i src = simde_test_x86_random_i64x8();
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m512i a = simde_test_x86_random_i64x8();
    simde__m512i r = simde_mm512_mask_loadu_epi64(src, k, &a);

    simde_test_x86_write_i64x8(2, src, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i64x8(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i64x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm512_maskz_loadu_epi64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask8 k;
    SIMDE_ALIGN_LIKE_64(simde__m512i) const int64_t a[8];
    const int64_t r[8];
  } test_vec[] = {
    { UINT8_C(146),
      { -INT64_C( 4380784222295849717),  INT64_C( 3967251434438982638),  INT64_C( 7589823404447444216), -INT64_C( 6093331122021819583),
         INT64_C( 2116884439609629608),  INT64_C( 4614834228702594474), -INT64_C( 3607085829794950053), -INT64_C( 3822118874658373718) },
      {  INT64_C(                   0),  INT64_C( 3967251434438982638),  INT64_C(                   0),  INT64_C(                   0),
         INT64_C( 2116884439609629608),  INT64_C(                   0),  INT64_C(                   0), -INT64_C( 3822118874658373718) } },
    { UINT8_C(246),
      { -INT64_C( 8229974516271126672), -INT64_C( 4904960234204390301),  INT64_C( 7459954843600844494),  INT64_C( 3950031561244135872),
        -INT64_C( 7345337768465795397), -INT64_C( 4027031733891373638),  INT64_C( 4278187081989449105), -INT64_C(  506118131138696707) },
      {  INT64_C(                   0), -INT64_C( 4904960234204390301),  INT64_C( 7459954843600844494),  INT64_C(                   0),
        -INT64_C( 7345337768465795397), -INT64_C( 4027031733891373638),  INT64_C( 4278187081989449105), -INT64_C(  506118131138696707) } },
    { UINT8_C(222),
      {  INT64_C( 8153398292556184654),  INT64_C(  831252398451951837), -INT64_C( 3890614331372043560),  INT64_C(  837670345678243033),
         INT64_C( 4934429403292087932), -INT64_C( 1092186574805998298), -INT64_C(  435453745456456120),  INT64_C( 8611263998584355769) },
      {  INT64_C(                   0),  INT64_C(  831252398451951837), -INT64_C( 3890614331372043560),  INT64_C(  837670345678243033),
         INT64_C( 4934429403292087932),  INT64_C(                   0), -INT64_C(  435453745456456120),  INT64_C( 8611263998584355769) } },
    { UINT8_C( 16),
      { -INT64_C( 2325058097682874120), -INT64_C( 4826197027262593033),  INT64_C( 2200525342263554011),  INT64_C( 8717721486591983504),
         INT64_C( 2732217319249768977), -INT64_C( 6670700999400562352), -INT64_C( 5739560514028877545),  INT64_C( 1581772840134996731) },
      {  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),
         INT64_C( 2732217319249768977),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0) } },
    { UINT8_C(  9),
      { -INT64_C( 1361675831130840831), -INT64_C( 9206103974162871746),  INT64_C( 4811058055798028236),  INT64_C( 3785938713528647914),
         INT64_C( 6518143646036836476),  INT64_C( 5807881565237160675),  INT64_C( 8306288663992023348),  INT64_C( 7171277513634908957) },
      { -INT64_C( 1361675831130840831),  INT64_C(                   0),  INT64_C(                   0),  INT64_C( 3785938713528647914),
         INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0) } },
    { UINT8_C( 62),
      { -INT64_C( 8394511378368763004),  INT64_C( 7792738307415120180), -INT64_C(  400143693296424585), -INT64_C( 3668106812514516133),
         INT64_C( 6565098337470149168),  INT64_C(    9696080707791491), -INT64_C( 2736843329381263461),  INT64_C( 6458666721148659083) },
      {  INT64_C(                   0),  INT64_C( 7792738307415120180), -INT64_C(  400143693296424585), -INT64_C( 3668106812514516133),
         INT64_C( 6565098337470149168),  INT64_C(    9696080707791491),  INT64_C(                   0),  INT64_C(                   0) } },
    { UINT8_C( 62),
      {  INT64_C( 3420695048812358155),  INT64_C( 7501792264507109133),  INT64_C( 1035758824728241421), -INT64_C( 2342274415389559948),
        -INT64_C( 5642924968442010757),  INT64_C( 3257875084214364284),  INT64_C( 5956681065862143346), -INT64_C( 1204413337466379627) },
      {  INT64_C(                   0),  INT64_C( 7501792264507109133),  INT64_C( 1035758824728241421), -INT64_C( 2342274415389559948),
        -INT64_C( 5642924968442010757),  INT64_C( 3257875084214364284),  INT64_C(                   0),  INT64_C(                   0) } },
    { UINT8_C(243),
      { -INT64_C( 8510035141805510627),  INT64_C(  520121685323134073),  INT64_C( 6903797764780839897), -INT64_C( 6931390008715494966),
         INT64_C( 2800096220537316657),  INT64_C( 3788973537648936100),  INT64_C( 8994320341974088438), -INT64_C( 7522941677857233801) },
      { -INT64_C( 8510035141805510627),  INT64_C(  520121685323134073),  INT64_C(                   0),  INT64_C(                   0),
         INT64_C( 2800096220537316657),  INT64_C( 3788973537648936100),  INT64_C( 8994320341974088438), -INT64_C( 7522941677857233801) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_test_x86_assert_equal_i64x8(simde_mm512_load_si512(SIMDE_ALIGN_CAST(simde__m512i const *, test_vec[i].r)), simde_mm512_maskz_loadu_epi64(test_vec[i].k, test_vec[i].a));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m512i a = simde_test_x86_random_i64x8();
    simde__m512i r = simde_mm512_maskz_loadu_epi64(k, &a);

    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i64x8(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i64x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm512_loadu_si512(SIMDE_MUNIT_TEST_ARGS) {
  const struct {
    simde__m512i a;
    simde__m512i r;
  } test_vec[8] = {
    { simde_x_mm512_set_epu32(UINT32_C(2465927924), UINT32_C(3593197775), UINT32_C( 612910812), UINT32_C(3812769805),
                              UINT32_C(4149829677), UINT32_C(3483799324), UINT32_C(1459962882), UINT32_C(4149819515),
                              UINT32_C(2650201844), UINT32_C( 758753621), UINT32_C(1440172455), UINT32_C(1093653043),
                              UINT32_C(4135659774), UINT32_C(2249292246), UINT32_C(3926208727), UINT32_C( 363227362)),
      simde_x_mm512_set_epu32(UINT32_C(2465927924), UINT32_C(3593197775), UINT32_C( 612910812), UINT32_C(3812769805),
                              UINT32_C(4149829677), UINT32_C(3483799324), UINT32_C(1459962882), UINT32_C(4149819515),
                              UINT32_C(2650201844), UINT32_C( 758753621), UINT32_C(1440172455), UINT32_C(1093653043),
                              UINT32_C(4135659774), UINT32_C(2249292246), UINT32_C(3926208727), UINT32_C( 363227362)) },
    { simde_x_mm512_set_epu32(UINT32_C( 468967701), UINT32_C(1464888328), UINT32_C(2623912787), UINT32_C(3584306317),
                              UINT32_C(3441172772), UINT32_C(1957813224), UINT32_C(3956090282), UINT32_C(2819645236),
                              UINT32_C(2119397630), UINT32_C(3325357179), UINT32_C( 910080153), UINT32_C(3698201489),
                              UINT32_C(3945376801), UINT32_C(2699586726), UINT32_C(1169343086), UINT32_C(2983594096)),
      simde_x_mm512_set_epu32(UINT32_C( 468967701), UINT32_C(1464888328), UINT32_C(2623912787), UINT32_C(3584306317),
                              UINT32_C(3441172772), UINT32_C(1957813224), UINT32_C(3956090282), UINT32_C(2819645236),
                              UINT32_C(2119397630), UINT32_C(3325357179), UINT32_C( 910080153), UINT32_C(3698201489),
                              UINT32_C(3945376801), UINT32_C(2699586726), UINT32_C(1169343086), UINT32_C(2983594096)) },
    { simde_x_mm512_set_epu32(UINT32_C(3220925730), UINT32_C(4163700514), UINT32_C( 208162340), UINT32_C(  72282893),
                              UINT32_C(2784701415), UINT32_C(2960668076), UINT32_C(2280551509), UINT32_C( 511971347),
                              UINT32_C(3142311802), UINT32_C(3582165504), UINT32_C(3533175269), UINT32_C(3138584679),
                              UINT32_C(3117232701), UINT32_C(1582887517), UINT32_C(2957127939), UINT32_C(3388466484)),
      simde_x_mm512_set_epu32(UINT32_C(3220925730), UINT32_C(4163700514), UINT32_C( 208162340), UINT32_C(  72282893),
                              UINT32_C(2784701415), UINT32_C(2960668076), UINT32_C(2280551509), UINT32_C( 511971347),
                              UINT32_C(3142311802), UINT32_C(3582165504), UINT32_C(3533175269), UINT32_C(3138584679),
                              UINT32_C(3117232701), UINT32_C(1582887517), UINT32_C(2957127939), UINT32_C(3388466484)) },
    { simde_x_mm512_set_epu32(UINT32_C(2382371522), UINT32_C(  66180421), UINT32_C(3915007092), UINT32_C(3548556152),
                              UINT32_C(3063171483), UINT32_C( 175336822), UINT32_C(2621074902), UINT32_C(2785523281),
                              UINT32_C(3351907467), UINT32_C(3611626580), UINT32_C(3274777282), UINT32_C(2819588991),
                              UINT32_C(4142757399), UINT32_C(3841212820), UINT32_C(1375549108), UINT32_C(3217099434)),
      simde_x_mm512_set_epu32(UINT32_C(2382371522), UINT32_C(  66180421), UINT32_C(3915007092), UINT32_C(3548556152),
                              UINT32_C(3063171483), UINT32_C( 175336822), UINT32_C(2621074902), UINT32_C(2785523281),
                              UINT32_C(3351907467), UINT32_C(3611626580), UINT32_C(3274777282), UINT32_C(2819588991),
                              UINT32_C(4142757399), UINT32_C(3841212820), UINT32_C(1375549108), UINT32_C(3217099434)) },
    { simde_x_mm512_set_epu32(UINT32_C(1625945136), UINT32_C(  82950125), UINT32_C(3598722192), UINT32_C(2456005821),
                              UINT32_C(3054050921), UINT32_C(3350002014), UINT32_C(1546778759), UINT32_C(3175686900),
                              UINT32_C(3418645543), UINT32_C(1247476579), UINT32_C(2559569107), UINT32_C(3884223622),
                              UINT32_C(2206347705), UINT32_C(1195297710), UINT32_C(4206427691), UINT32_C(2187435296)),
      simde_x_mm512_set_epu32(UINT32_C(1625945136), UINT32_C(  82950125), UINT32_C(3598722192), UINT32_C(2456005821),
                              UINT32_C(3054050921), UINT32_C(3350002014), UINT32_C(1546778759), UINT32_C(3175686900),
                              UINT32_C(3418645543), UINT32_C(1247476579), UINT32_C(2559569107), UINT32_C(3884223622),
                              UINT32_C(2206347705), UINT32_C(1195297710), UINT32_C(4206427691), UINT32_C(2187435296)) },
    { simde_x_mm512_set_epu32(UINT32_C(3055114510), UINT32_C( 314498376), UINT32_C( 259740532), UINT32_C(2845634146),
                              UINT32_C(3528445754), UINT32_C(1438308061), UINT32_C(1618483487), UINT32_C(4280155704),
                              UINT32_C(4191548278), UINT32_C( 955760205), UINT32_C(3071952989), UINT32_C(3353486020),
                              UINT32_C(3091053226), UINT32_C(2241572393), UINT32_C(3491849165), UINT32_C(2750648051)),
      simde_x_mm512_set_epu32(UINT32_C(3055114510), UINT32_C( 314498376), UINT32_C( 259740532), UINT32_C(2845634146),
                              UINT32_C(3528445754), UINT32_C(1438308061), UINT32_C(1618483487), UINT32_C(4280155704),
                              UINT32_C(4191548278), UINT32_C( 955760205), UINT32_C(3071952989), UINT32_C(3353486020),
                              UINT32_C(3091053226), UINT32_C(2241572393), UINT32_C(3491849165), UINT32_C(2750648051)) },
    { simde_x_mm512_set_epu32(UINT32_C(2791699552), UINT32_C(1697626027), UINT32_C(3068022880), UINT32_C( 492436222),
                              UINT32_C(2413088982), UINT32_C(1530446668), UINT32_C(1370127960), UINT32_C(2402932897),
                              UINT32_C(4061542194), UINT32_C( 154485056), UINT32_C(3577835063), UINT32_C(3500138573),
                              UINT32_C(  48074834), UINT32_C(1773313389), UINT32_C(3571862316), UINT32_C(1059958902)),
      simde_x_mm512_set_epu32(UINT32_C(2791699552), UINT32_C(1697626027), UINT32_C(3068022880), UINT32_C( 492436222),
                              UINT32_C(2413088982), UINT32_C(1530446668), UINT32_C(1370127960), UINT32_C(2402932897),
                              UINT32_C(4061542194), UINT32_C( 154485056), UINT32_C(3577835063), UINT32_C(3500138573),
                              UINT32_C(  48074834), UINT32_C(1773313389), UINT32_C(3571862316), UINT32_C(1059958902)) },
    { simde_x_mm512_set_epu32(UINT32_C(1166001194), UINT32_C( 115042765), UINT32_C( 557502548), UINT32_C(2408114255),
                              UINT32_C( 870354895), UINT32_C( 955362708), UINT32_C(1149136654), UINT32_C(1920883489),
                              UINT32_C(3238897491), UINT32_C(1952390233), UINT32_C( 223001918), UINT32_C( 310736118),
                              UINT32_C(2747509005), UINT32_C( 134376306), UINT32_C(1234549716), UINT32_C( 594304164)),
      simde_x_mm512_set_epu32(UINT32_C(1166001194), UINT32_C( 115042765), UINT32_C( 557502548), UINT32_C(2408114255),
                              UINT32_C( 870354895), UINT32_C( 955362708), UINT32_C(1149136654), UINT32_C(1920883489),
                              UINT32_C(3238897491), UINT32_C(1952390233), UINT32_C( 223001918), UINT32_C( 310736118),
                              UINT32_C(2747509005), UINT32_C( 134376306), UINT32_C(1234549716), UINT32_C( 594304164)) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde__m512i r = simde_mm512_loadu_si512(&(test_vec[i].a));
    simde_assert_m512i_i32(r, ==, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_mm512_mask_loadu_ps (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde_float32 src[16];
    const simde__mmask16 k;
    SIMDE_ALIGN_LIKE_32(simde__m512) const simde_float32 a[16];
    const simde_float32 r[16];
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(   415.75), SIMDE_FLOAT32_C(     4.33), SIMDE_FLOAT32_C(   -57.11), SIMDE_FLOAT32_C(   258.31),
        SIMDE_FLOAT32_C(   961.16), SIMDE_FLOAT32_C(   146.22), SIMDE_FLOAT32_C(   186.28), SIMDE_FLOAT32_C(   183.14),
        SIMDE_FLOAT32_C(  -153.88), SIMDE_FLOAT32_C(  -312.93), SIMDE_FLOAT32_C(   569.13), SIMDE_FLOAT32_C(   373.96),
        SIMDE_FLOAT32_C(  -112.78), SIMDE_FLOAT32_C(   379.85), SIMDE_FLOAT32_C(  -370.93), SIMDE_FLOAT32_C(   928.80) },
      UINT16_C(53283),
      { SIMDE_FLOAT32_C(   866.47), SIMDE_FLOAT32_C(  -601.29), SIMDE_FLOAT32_C(   606.13), SIMDE_FLOAT32_C(   227.72),
        SIMDE_FLOAT32_C(  -133.60), SIMDE_FLOAT32_C(   923.82), SIMDE_FLOAT32_C(   522.60), SIMDE_FLOAT32_C(   284.30),
        SIMDE_FLOAT32_C(   701.08), SIMDE_FLOAT32_C(  -664.23), SIMDE_FLOAT32_C(  -337.15), SIMDE_FLOAT32_C(   484.66),
        SIMDE_FLOAT32_C(  -371.64), SIMDE_FLOAT32_C(  -921.40), SIMDE_FLOAT32_C(  -511.01), SIMDE_FLOAT32_C(   571.25) },
      { SIMDE_FLOAT32_C(   866.47), SIMDE_FLOAT32_C(  -601.29), SIMDE_FLOAT32_C(   -57.11), SIMDE_FLOAT32_C(   258.31),
        SIMDE_FLOAT32_C(   961.16), SIMDE_FLOAT32_C(   923.82), SIMDE_FLOAT32_C(   186.28), SIMDE_FLOAT32_C(   183.14),
        SIMDE_FLOAT32_C(  -153.88), SIMDE_FLOAT32_C(  -312.93), SIMDE_FLOAT32_C(   569.13), SIMDE_FLOAT32_C(   373.96),
        SIMDE_FLOAT32_C(  -371.64), SIMDE_FLOAT32_C(   379.85), SIMDE_FLOAT32_C(  -511.01), SIMDE_FLOAT32_C(   571.25) } },
    { { SIMDE_FLOAT32_C(   336.92), SIMDE_FLOAT32_C(  -549.85), SIMDE_FLOAT32_C(  -282.53), SIMDE_FLOAT32_C(  -476.80),
        SIMDE_FLOAT32_C(   633.29), SIMDE_FLOAT32_C(   563.59), SIMDE_FLOAT32_C(   210.28), SIMDE_FLOAT32_C(   202.42),
        SIMDE_FLOAT32_C(   -62.45), SIMDE_FLOAT32_C(  -902.50), SIMDE_FLOAT32_C(  -417.73), SIMDE_FLOAT32_C(   566.61),
        SIMDE_FLOAT32_C(  -973.70), SIMDE_FLOAT32_C(  -758.30), SIMDE_FLOAT32_C(   626.99), SIMDE_FLOAT32_C(   892.76) },
      UINT16_C(62115),
      { SIMDE_FLOAT32_C(   120.49), SIMDE_FLOAT32_C(   506.81), SIMDE_FLOAT32_C(   156.94), SIMDE_FLOAT32_C(  -356.91),
        SIMDE_FLOAT32_C(  -208.89), SIMDE_FLOAT32_C(  -141.98), SIMDE_FLOAT32_C(   -21.14), SIMDE_FLOAT32_C(   453.97),
        SIMDE_FLOAT32_C(  -657.32), SIMDE_FLOAT32_C(   607.22), SIMDE_FLOAT32_C(   532.57), SIMDE_FLOAT32_C(  -168.33),
        SIMDE_FLOAT32_C(   178.47), SIMDE_FLOAT32_C(  -130.51), SIMDE_FLOAT32_C(   281.82), SIMDE_FLOAT32_C(   895.93) },
      { SIMDE_FLOAT32_C(   120.49), SIMDE_FLOAT32_C(   506.81), SIMDE_FLOAT32_C(  -282.53), SIMDE_FLOAT32_C(  -476.80),
        SIMDE_FLOAT32_C(   633.29), SIMDE_FLOAT32_C(  -141.98), SIMDE_FLOAT32_C(   210.28), SIMDE_FLOAT32_C(   453.97),
        SIMDE_FLOAT32_C(   -62.45), SIMDE_FLOAT32_C(   607.22), SIMDE_FLOAT32_C(  -417.73), SIMDE_FLOAT32_C(   566.61),
        SIMDE_FLOAT32_C(   178.47), SIMDE_FLOAT32_C(  -130.51), SIMDE_FLOAT32_C(   281.82), SIMDE_FLOAT32_C(   895.93) } },
    { { SIMDE_FLOAT32_C(   392.69), SIMDE_FLOAT32_C(   -84.89), SIMDE_FLOAT32_C(   459.52), SIMDE_FLOAT32_C(  -397.03),
        SIMDE_FLOAT32_C(  -882.47), SIMDE_FLOAT32_C(  -602.93), SIMDE_FLOAT32_C(  -299.53), SIMDE_FLOAT32_C(  -300.20),
        SIMDE_FLOAT32_C(   963.68), SIMDE_FLOAT32_C(  -273.23), SIMDE_FLOAT32_C(   -58.50), SIMDE_FLOAT32_C(   590.67),
        SIMDE_FLOAT32_C(  -380.47), SIMDE_FLOAT32_C(   581.92), SIMDE_FLOAT32_C(  -176.22), SIMDE_FLOAT32_C(   740.02) },
      UINT16_C( 6850),
      { SIMDE_FLOAT32_C(  -616.89), SIMDE_FLOAT32_C(   879.84), SIMDE_FLOAT32_C(  -161.25), SIMDE_FLOAT32_C(   361.97),
        SIMDE_FLOAT32_C(   333.81), SIMDE_FLOAT32_C(   181.43), SIMDE_FLOAT32_C(   -30.82), SIMDE_FLOAT32_C(  -133.62),
        SIMDE_FLOAT32_C(  -986.90), SIMDE_FLOAT32_C(  -852.35), SIMDE_FLOAT32_C(   735.87), SIMDE_FLOAT32_C(   294.92),
        SIMDE_FLOAT32_C(  -956.42), SIMDE_FLOAT32_C(   128.57), SIMDE_FLOAT32_C(  -789.97), SIMDE_FLOAT32_C(   503.10) },
      { SIMDE_FLOAT32_C(   392.69), SIMDE_FLOAT32_C(   879.84), SIMDE_FLOAT32_C(   459.52), SIMDE_FLOAT32_C(  -397.03),
        SIMDE_FLOAT32_C(  -882.47), SIMDE_FLOAT32_C(  -602.93), SIMDE_FLOAT32_C(   -30.82), SIMDE_FLOAT32_C(  -133.62),
        SIMDE_FLOAT32_C(   963.68), SIMDE_FLOAT32_C(  -852.35), SIMDE_FLOAT32_C(   -58.50), SIMDE_FLOAT32_C(   294.92),
        SIMDE_FLOAT32_C(  -956.42), SIMDE_FLOAT32_C(   581.92), SIMDE_FLOAT32_C(  -176.22), SIMDE_FLOAT32_C(   740.02) } },
    { { SIMDE_FLOAT32_C(   731.54), SIMDE_FLOAT32_C(  -672.43), SIMDE_FLOAT32_C(   900.17), SIMDE_FLOAT32_C(  -567.99),
        SIMDE_FLOAT32_C(    27.36), SIMDE_FLOAT32_C(   863.85), SIMDE_FLOAT32_C(   158.78), SIMDE_FLOAT32_C(   968.87),
        SIMDE_FLOAT32_C(   454.52), SIMDE_FLOAT32_C(   778.31), SIMDE_FLOAT32_C(   550.78), SIMDE_FLOAT32_C(  -721.70),
        SIMDE_FLOAT32_C(   518.33), SIMDE_FLOAT32_C(  -360.49), SIMDE_FLOAT32_C(  -740.98), SIMDE_FLOAT32_C(   901.43) },
      UINT16_C( 8666),
      { SIMDE_FLOAT32_C(   263.40), SIMDE_FLOAT32_C(   853.16), SIMDE_FLOAT32_C(  -720.81), SIMDE_FLOAT32_C(  -767.41),
        SIMDE_FLOAT32_C(  -280.46), SIMDE_FLOAT32_C(  -707.71), SIMDE_FLOAT32_C(  -619.77), SIMDE_FLOAT32_C(  -544.58),
        SIMDE_FLOAT32_C(   587.21), SIMDE_FLOAT32_C(  -576.18), SIMDE_FLOAT32_C(   583.99), SIMDE_FLOAT32_C(   797.24),
        SIMDE_FLOAT32_C(   926.92), SIMDE_FLOAT32_C(   315.53), SIMDE_FLOAT32_C(  -875.19), SIMDE_FLOAT32_C(   827.09) },
      { SIMDE_FLOAT32_C(   731.54), SIMDE_FLOAT32_C(   853.16), SIMDE_FLOAT32_C(   900.17), SIMDE_FLOAT32_C(  -767.41),
        SIMDE_FLOAT32_C(  -280.46), SIMDE_FLOAT32_C(   863.85), SIMDE_FLOAT32_C(  -619.77), SIMDE_FLOAT32_C(  -544.58),
        SIMDE_FLOAT32_C(   587.21), SIMDE_FLOAT32_C(   778.31), SIMDE_FLOAT32_C(   550.78), SIMDE_FLOAT32_C(  -721.70),
        SIMDE_FLOAT32_C(   518.33), SIMDE_FLOAT32_C(   315.53), SIMDE_FLOAT32_C(  -740.98), SIMDE_FLOAT32_C(   901.43) } },
    { { SIMDE_FLOAT32_C(   747.54), SIMDE_FLOAT32_C(   152.17), SIMDE_FLOAT32_C(   690.94), SIMDE_FLOAT32_C(   -93.68),
        SIMDE_FLOAT32_C(   121.04), SIMDE_FLOAT32_C(   145.45), SIMDE_FLOAT32_C(  -315.38), SIMDE_FLOAT32_C(  -328.18),
        SIMDE_FLOAT32_C(   423.75), SIMDE_FLOAT32_C(  -797.05), SIMDE_FLOAT32_C(   311.33), SIMDE_FLOAT32_C(   682.78),
        SIMDE_FLOAT32_C(  -895.62), SIMDE_FLOAT32_C(   830.68), SIMDE_FLOAT32_C(  -219.46), SIMDE_FLOAT32_C(   367.79) },
      UINT16_C(  742),
      { SIMDE_FLOAT32_C(   600.37), SIMDE_FLOAT32_C(  -596.62), SIMDE_FLOAT32_C(   352.03), SIMDE_FLOAT32_C(   980.61),
        SIMDE_FLOAT32_C(  -141.20), SIMDE_FLOAT32_C(   -60.77), SIMDE_FLOAT32_C(  -595.58), SIMDE_FLOAT32_C(  -557.21),
        SIMDE_FLOAT32_C(  -263.53), SIMDE_FLOAT32_C(  -668.66), SIMDE_FLOAT32_C(   758.32), SIMDE_FLOAT32_C(  -138.72),
        SIMDE_FLOAT32_C(  -841.56), SIMDE_FLOAT32_C(   505.86), SIMDE_FLOAT32_C(  -986.55), SIMDE_FLOAT32_C(   849.37) },
      { SIMDE_FLOAT32_C(   747.54), SIMDE_FLOAT32_C(  -596.62), SIMDE_FLOAT32_C(   352.03), SIMDE_FLOAT32_C(   -93.68),
        SIMDE_FLOAT32_C(   121.04), SIMDE_FLOAT32_C(   -60.77), SIMDE_FLOAT32_C(  -595.58), SIMDE_FLOAT32_C(  -557.21),
        SIMDE_FLOAT32_C(   423.75), SIMDE_FLOAT32_C(  -668.66), SIMDE_FLOAT32_C(   311.33), SIMDE_FLOAT32_C(   682.78),
        SIMDE_FLOAT32_C(  -895.62), SIMDE_FLOAT32_C(   830.68), SIMDE_FLOAT32_C(  -219.46), SIMDE_FLOAT32_C(   367.79) } },
    { { SIMDE_FLOAT32_C(  -587.83), SIMDE_FLOAT32_C(   134.49), SIMDE_FLOAT32_C(    -5.17), SIMDE_FLOAT32_C(    96.80),
        SIMDE_FLOAT32_C(   806.31), SIMDE_FLOAT32_C(  -581.42), SIMDE_FLOAT32_C(   299.75), SIMDE_FLOAT32_C(   117.63),
        SIMDE_FLOAT32_C(  -898.64), SIMDE_FLOAT32_C(   404.13), SIMDE_FLOAT32_C(   -51.69), SIMDE_FLOAT32_C(  -118.10),
        SIMDE_FLOAT32_C(  -228.09), SIMDE_FLOAT32_C(  -367.85), SIMDE_FLOAT32_C(   941.64), SIMDE_FLOAT32_C(  -627.71) },
      UINT16_C( 7446),
      { SIMDE_FLOAT32_C(  -647.11), SIMDE_FLOAT32_C(   894.34), SIMDE_FLOAT32_C(  -767.10), SIMDE_FLOAT32_C(  -242.68),
        SIMDE_FLOAT32_C(  -662.87), SIMDE_FLOAT32_C(   -30.62), SIMDE_FLOAT32_C(    88.66), SIMDE_FLOAT32_C(  -904.55),
        SIMDE_FLOAT32_C(   830.66), SIMDE_FLOAT32_C(   247.10), SIMDE_FLOAT32_C(   601.31), SIMDE_FLOAT32_C(   844.11),
        SIMDE_FLOAT32_C(    96.47), SIMDE_FLOAT32_C(  -986.52), SIMDE_FLOAT32_C(   -21.40), SIMDE_FLOAT32_C(  -908.70) },
      { SIMDE_FLOAT32_C(  -587.83), SIMDE_FLOAT32_C(   894.34), SIMDE_FLOAT32_C(  -767.10), SIMDE_FLOAT32_C(    96.80),
        SIMDE_FLOAT32_C(  -662.87), SIMDE_FLOAT32_C(  -581.42), SIMDE_FLOAT32_C(   299.75), SIMDE_FLOAT32_C(   117.63),
        SIMDE_FLOAT32_C(   830.66), SIMDE_FLOAT32_C(   404.13), SIMDE_FLOAT32_C(   601.31), SIMDE_FLOAT32_C(   844.11),
        SIMDE_FLOAT32_C(    96.47), SIMDE_FLOAT32_C(  -367.85), SIMDE_FLOAT32_C(   941.64), SIMDE_FLOAT32_C(  -627.71) } },
    { { SIMDE_FLOAT32_C(   110.28), SIMDE_FLOAT32_C(  -215.10), SIMDE_FLOAT32_C(  -490.12), SIMDE_FLOAT32_C(  -589.98),
        SIMDE_FLOAT32_C(   902.54), SIMDE_FLOAT32_C(  -388.76), SIMDE_FLOAT32_C(   814.15), SIMDE_FLOAT32_C(  -149.15),
        SIMDE_FLOAT32_C(   493.15), SIMDE_FLOAT32_C(  -413.94), SIMDE_FLOAT32_C(   483.00), SIMDE_FLOAT32_C(   434.79),
        SIMDE_FLOAT32_C(   -41.65), SIMDE_FLOAT32_C(  -481.46), SIMDE_FLOAT32_C(  -271.54), SIMDE_FLOAT32_C(   311.24) },
      UINT16_C(38988),
      { SIMDE_FLOAT32_C(  -931.44), SIMDE_FLOAT32_C(  -249.99), SIMDE_FLOAT32_C(   930.73), SIMDE_FLOAT32_C(   157.22),
        SIMDE_FLOAT32_C(  -154.54), SIMDE_FLOAT32_C(   761.39), SIMDE_FLOAT32_C(  -595.69), SIMDE_FLOAT32_C(  -553.23),
        SIMDE_FLOAT32_C(   605.50), SIMDE_FLOAT32_C(   500.78), SIMDE_FLOAT32_C(  -539.75), SIMDE_FLOAT32_C(  -415.90),
        SIMDE_FLOAT32_C(   592.08), SIMDE_FLOAT32_C(   570.53), SIMDE_FLOAT32_C(   369.00), SIMDE_FLOAT32_C(  -898.04) },
      { SIMDE_FLOAT32_C(   110.28), SIMDE_FLOAT32_C(  -215.10), SIMDE_FLOAT32_C(   930.73), SIMDE_FLOAT32_C(   157.22),
        SIMDE_FLOAT32_C(   902.54), SIMDE_FLOAT32_C(  -388.76), SIMDE_FLOAT32_C(  -595.69), SIMDE_FLOAT32_C(  -149.15),
        SIMDE_FLOAT32_C(   493.15), SIMDE_FLOAT32_C(  -413.94), SIMDE_FLOAT32_C(   483.00), SIMDE_FLOAT32_C(  -415.90),
        SIMDE_FLOAT32_C(   592.08), SIMDE_FLOAT32_C(  -481.46), SIMDE_FLOAT32_C(  -271.54), SIMDE_FLOAT32_C(  -898.04) } },
    { { SIMDE_FLOAT32_C(   980.55), SIMDE_FLOAT32_C(   271.53), SIMDE_FLOAT32_C(  -286.79), SIMDE_FLOAT32_C(   794.70),
        SIMDE_FLOAT32_C(  -877.62), SIMDE_FLOAT32_C(  -793.65), SIMDE_FLOAT32_C(  -619.24), SIMDE_FLOAT32_C(   605.38),
        SIMDE_FLOAT32_C(   641.14), SIMDE_FLOAT32_C(   339.11), SIMDE_FLOAT32_C(  -876.08), SIMDE_FLOAT32_C(  -630.40),
        SIMDE_FLOAT32_C(  -349.65), SIMDE_FLOAT32_C(  -463.20), SIMDE_FLOAT32_C(   330.95), SIMDE_FLOAT32_C(  -281.09) },
      UINT16_C(26151),
      { SIMDE_FLOAT32_C(   876.12), SIMDE_FLOAT32_C(  -867.73), SIMDE_FLOAT32_C(    23.08), SIMDE_FLOAT32_C(  -719.57),
        SIMDE_FLOAT32_C(  -420.96), SIMDE_FLOAT32_C(  -371.42), SIMDE_FLOAT32_C(   781.22), SIMDE_FLOAT32_C(    39.29),
        SIMDE_FLOAT32_C(   212.68), SIMDE_FLOAT32_C(   373.30), SIMDE_FLOAT32_C(  -390.19), SIMDE_FLOAT32_C(  -418.32),
        SIMDE_FLOAT32_C(   475.26), SIMDE_FLOAT32_C(  -409.64), SIMDE_FLOAT32_C(   853.21), SIMDE_FLOAT32_C(  -811.53) },
      { SIMDE_FLOAT32_C(   876.12), SIMDE_FLOAT32_C(  -867.73), SIMDE_FLOAT32_C(    23.08), SIMDE_FLOAT32_C(   794.70),
        SIMDE_FLOAT32_C(  -877.62), SIMDE_FLOAT32_C(  -371.42), SIMDE_FLOAT32_C(  -619.24), SIMDE_FLOAT32_C(   605.38),
        SIMDE_FLOAT32_C(   641.14), SIMDE_FLOAT32_C(   373.30), SIMDE_FLOAT32_C(  -390.19), SIMDE_FLOAT32_C(  -630.40),
        SIMDE_FLOAT32_C(  -349.65), SIMDE_FLOAT32_C(  -409.64), SIMDE_FLOAT32_C(   853.21), SIMDE_FLOAT32_C(  -281.09) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m512 src = simde_mm512_load_ps(test_vec[i].src);
    simde_test_x86_assert_equal_f32x16(simde_mm512_load_ps(SIMDE_ALIGN_CAST(simde__m512 const *, test_vec[i].r)), simde_mm512_mask_loadu_ps(src, test_vec[i].k, test_vec[i].a), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m512 src = simde_test_x86_random_f32x16(SIMDE_FLOAT32_C(-1000.0), SIMDE_FLOAT32_C(1000.0));
    simde__mmask16 k = simde_test_x86_random_mmask16();
    simde__m512 a = simde_test_x86_random_f32x16(SIMDE_FLOAT32_C(-1000.0), SIMDE_FLOAT32_C(1000.0));
    simde__m512 r = simde_mm512_mask_loadu_ps(src, k, &a);

    simde_test_x86_write_f32x16(2, src, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_mmask16(2, k, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f32x16(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f32x16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm512_maskz_loadu_ps (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask16 k;
    SIMDE_ALIGN_LIKE_32(simde__m512) const simde_float32 a[16];
    const simde_float32 r[16];
  } test_vec[] = {
    { UINT16_C(13665),
      { SIMDE_FLOAT32_C(   981.30), SIMDE_FLOAT32_C(  -716.31), SIMDE_FLOAT32_C(  -524.40), SIMDE_FLOAT32_C(  -854.89),
        SIMDE_FLOAT32_C(   653.89), SIMDE_FLOAT32_C(  -663.13), SIMDE_FLOAT32_C(  -422.61), SIMDE_FLOAT32_C(   834.91),
        SIMDE_FLOAT32_C(   150.58), SIMDE_FLOAT32_C(   125.00), SIMDE_FLOAT32_C(  -465.05), SIMDE_FLOAT32_C(  -857.39),
        SIMDE_FLOAT32_C(   572.38), SIMDE_FLOAT32_C(   285.19), SIMDE_FLOAT32_C(  -300.66), SIMDE_FLOAT32_C(   -23.38) },
      { SIMDE_FLOAT32_C(   981.30), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -663.13), SIMDE_FLOAT32_C(  -422.61), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(   150.58), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -465.05), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(   572.38), SIMDE_FLOAT32_C(   285.19), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00) } },
    { UINT16_C(  577),
      { SIMDE_FLOAT32_C(   155.71), SIMDE_FLOAT32_C(  -683.30), SIMDE_FLOAT32_C(  -920.49), SIMDE_FLOAT32_C(   390.47),
        SIMDE_FLOAT32_C(   560.81), SIMDE_FLOAT32_C(   894.46), SIMDE_FLOAT32_C(  -199.86), SIMDE_FLOAT32_C(   777.00),
        SIMDE_FLOAT32_C(   499.40), SIMDE_FLOAT32_C(   776.40), SIMDE_FLOAT32_C(   622.16), SIMDE_FLOAT32_C(  -425.34),
        SIMDE_FLOAT32_C(   921.77), SIMDE_FLOAT32_C(   603.47), SIMDE_FLOAT32_C(  -141.65), SIMDE_FLOAT32_C(  -602.63) },
      { SIMDE_FLOAT32_C(   155.71), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -199.86), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   776.40), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00) } },
    { UINT16_C(46069),
      { SIMDE_FLOAT32_C(  -265.76), SIMDE_FLOAT32_C(  -674.04), SIMDE_FLOAT32_C(  -652.85), SIMDE_FLOAT32_C(   884.83),
        SIMDE_FLOAT32_C(   450.96), SIMDE_FLOAT32_C(  -117.90), SIMDE_FLOAT32_C(  -972.57), SIMDE_FLOAT32_C(    23.34),
        SIMDE_FLOAT32_C(  -832.71), SIMDE_FLOAT32_C(  -273.23), SIMDE_FLOAT32_C(   999.96), SIMDE_FLOAT32_C(   729.88),
        SIMDE_FLOAT32_C(  -467.03), SIMDE_FLOAT32_C(   155.67), SIMDE_FLOAT32_C(  -953.43), SIMDE_FLOAT32_C(  -387.52) },
      { SIMDE_FLOAT32_C(  -265.76), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -652.85), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(   450.96), SIMDE_FLOAT32_C(  -117.90), SIMDE_FLOAT32_C(  -972.57), SIMDE_FLOAT32_C(    23.34),
        SIMDE_FLOAT32_C(  -832.71), SIMDE_FLOAT32_C(  -273.23), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(  -467.03), SIMDE_FLOAT32_C(   155.67), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -387.52) } },
    { UINT16_C( 4281),
      { SIMDE_FLOAT32_C(  -493.05), SIMDE_FLOAT32_C(   346.28), SIMDE_FLOAT32_C(   384.39), SIMDE_FLOAT32_C(  -993.66),
        SIMDE_FLOAT32_C(   122.68), SIMDE_FLOAT32_C(     6.55), SIMDE_FLOAT32_C(  -419.00), SIMDE_FLOAT32_C(    44.45),
        SIMDE_FLOAT32_C(  -389.98), SIMDE_FLOAT32_C(   439.36), SIMDE_FLOAT32_C(   441.82), SIMDE_FLOAT32_C(  -641.41),
        SIMDE_FLOAT32_C(   951.60), SIMDE_FLOAT32_C(  -823.93), SIMDE_FLOAT32_C(  -315.45), SIMDE_FLOAT32_C(  -701.25) },
      { SIMDE_FLOAT32_C(  -493.05), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -993.66),
        SIMDE_FLOAT32_C(   122.68), SIMDE_FLOAT32_C(     6.55), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(    44.45),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(   951.60), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00) } },
    { UINT16_C(16117),
      { SIMDE_FLOAT32_C(   180.85), SIMDE_FLOAT32_C(  -911.67), SIMDE_FLOAT32_C(   158.86), SIMDE_FLOAT32_C(   348.13),
        SIMDE_FLOAT32_C(  -184.90), SIMDE_FLOAT32_C(   158.82), SIMDE_FLOAT32_C(    78.01), SIMDE_FLOAT32_C(   348.07),
        SIMDE_FLOAT32_C(  -685.51), SIMDE_FLOAT32_C(   124.59), SIMDE_FLOAT32_C(   960.56), SIMDE_FLOAT32_C(  -139.37),
        SIMDE_FLOAT32_C(  -268.03), SIMDE_FLOAT32_C(  -532.50), SIMDE_FLOAT32_C(  -793.09), SIMDE_FLOAT32_C(  -883.63) },
      { SIMDE_FLOAT32_C(   180.85), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   158.86), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(  -184.90), SIMDE_FLOAT32_C(   158.82), SIMDE_FLOAT32_C(    78.01), SIMDE_FLOAT32_C(   348.07),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   124.59), SIMDE_FLOAT32_C(   960.56), SIMDE_FLOAT32_C(  -139.37),
        SIMDE_FLOAT32_C(  -268.03), SIMDE_FLOAT32_C(  -532.50), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00) } },
    { UINT16_C(29622),
      { SIMDE_FLOAT32_C(   122.92), SIMDE_FLOAT32_C(    54.85), SIMDE_FLOAT32_C(  -625.96), SIMDE_FLOAT32_C(   732.94),
        SIMDE_FLOAT32_C(  -505.79), SIMDE_FLOAT32_C(   815.86), SIMDE_FLOAT32_C(  -908.47), SIMDE_FLOAT32_C(  -554.20),
        SIMDE_FLOAT32_C(   991.93), SIMDE_FLOAT32_C(  -223.91), SIMDE_FLOAT32_C(  -255.45), SIMDE_FLOAT32_C(  -947.17),
        SIMDE_FLOAT32_C(   -88.40), SIMDE_FLOAT32_C(   925.40), SIMDE_FLOAT32_C(  -858.84), SIMDE_FLOAT32_C(  -929.54) },
      { SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(    54.85), SIMDE_FLOAT32_C(  -625.96), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(  -505.79), SIMDE_FLOAT32_C(   815.86), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -554.20),
        SIMDE_FLOAT32_C(   991.93), SIMDE_FLOAT32_C(  -223.91), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(   -88.40), SIMDE_FLOAT32_C(   925.40), SIMDE_FLOAT32_C(  -858.84), SIMDE_FLOAT32_C(     0.00) } },
    { UINT16_C(21641),
      { SIMDE_FLOAT32_C(   229.27), SIMDE_FLOAT32_C(  -648.46), SIMDE_FLOAT32_C(  -695.67), SIMDE_FLOAT32_C(   543.76),
        SIMDE_FLOAT32_C(   476.13), SIMDE_FLOAT32_C(  -735.11), SIMDE_FLOAT32_C(  -595.61), SIMDE_FLOAT32_C(  -791.90),
        SIMDE_FLOAT32_C(  -267.61), SIMDE_FLOAT32_C(  -388.70), SIMDE_FLOAT32_C(  -675.53), SIMDE_FLOAT32_C(   206.24),
        SIMDE_FLOAT32_C(   940.89), SIMDE_FLOAT32_C(   447.39), SIMDE_FLOAT32_C(  -738.92), SIMDE_FLOAT32_C(  -685.07) },
      { SIMDE_FLOAT32_C(   229.27), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   543.76),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -791.90),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -675.53), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(   940.89), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -738.92), SIMDE_FLOAT32_C(     0.00) } },
    { UINT16_C(19155),
      { SIMDE_FLOAT32_C(  -869.21), SIMDE_FLOAT32_C(   271.86), SIMDE_FLOAT32_C(   201.09), SIMDE_FLOAT32_C(  -877.27),
        SIMDE_FLOAT32_C(  -952.05), SIMDE_FLOAT32_C(   945.65), SIMDE_FLOAT32_C(  -824.45), SIMDE_FLOAT32_C(   -40.45),
        SIMDE_FLOAT32_C(   871.04), SIMDE_FLOAT32_C(  -683.29), SIMDE_FLOAT32_C(    30.01), SIMDE_FLOAT32_C(   144.58),
        SIMDE_FLOAT32_C(   272.97), SIMDE_FLOAT32_C(  -740.71), SIMDE_FLOAT32_C(   496.12), SIMDE_FLOAT32_C(   577.30) },
      { SIMDE_FLOAT32_C(  -869.21), SIMDE_FLOAT32_C(   271.86), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(  -952.05), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -824.45), SIMDE_FLOAT32_C(   -40.45),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -683.29), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   144.58),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   496.12), SIMDE_FLOAT32_C(     0.00) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_test_x86_assert_equal_f32x16(simde_mm512_load_ps(SIMDE_ALIGN_CAST(simde__m512 const *, test_vec[i].r)), simde_mm512_maskz_loadu_ps(test_vec[i].k, test_vec[i].a), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__mmask16 k = simde_test_x86_random_mmask16();
    simde__m512 a = simde_test_x86_random_f32x16(SIMDE_FLOAT32_C(-1000.0), SIMDE_FLOAT32_C(1000.0));
    simde__m512 r = simde_mm512_maskz_loadu_ps(k, &a);

    simde_test_x86_write_mmask16(2, k, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_f32x16(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f32x16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm512_mask_loadu_pd (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde_float64 src[8];
    const simde__mmask8 k;
    SIMDE_ALIGN_LIKE_64(simde__m512) const simde_float64 a[8];
    const simde_float64 r[8];
  } test_vec[] = {
    { { SIMDE_FLOAT64_C(   487.51), SIMDE_FLOAT64_C(  -524.34), SIMDE_FLOAT64_C(   337.50), SIMDE_FLOAT64_C(   203.22),
        SIMDE_FLOAT64_C(  -353.82), SIMDE_FLOAT64_C(   775.31), SIMDE_FLOAT64_C(  -924.29), SIMDE_FLOAT64_C(    85.45) },
      UINT8_C(240),
      { SIMDE_FLOAT64_C(   774.60), SIMDE_FLOAT64_C(  -731.10), SIMDE_FLOAT64_C(   196.31), SIMDE_FLOAT64_C(   712.71),
        SIMDE_FLOAT64_C(   228.20), SIMDE_FLOAT64_C(   884.38), SIMDE_FLOAT64_C(   263.93), SIMDE_FLOAT64_C(   702.03) },
      { SIMDE_FLOAT64_C(   487.51), SIMDE_FLOAT64_C(  -524.34), SIMDE_FLOAT64_C(   337.50), SIMDE_FLOAT64_C(   203.22),
        SIMDE_FLOAT64_C(   228.20), SIMDE_FLOAT64_C(   884.38), SIMDE_FLOAT64_C(   263.93), SIMDE_FLOAT64_C(   702.03) } },
    { { SIMDE_FLOAT64_C(   828.16), SIMDE_FLOAT64_C(  -860.82), SIMDE_FLOAT64_C(   771.13), SIMDE_FLOAT64_C(   966.77),
        SIMDE_FLOAT64_C(   980.38), SIMDE_FLOAT64_C(   979.46), SIMDE_FLOAT64_C(   -44.14), SIMDE_FLOAT64_C(  -546.57) },
      UINT8_C(185),
      { SIMDE_FLOAT64_C(   104.67), SIMDE_FLOAT64_C(  -156.72), SIMDE_FLOAT64_C(   332.27), SIMDE_FLOAT64_C(  -770.36),
        SIMDE_FLOAT64_C(   462.37), SIMDE_FLOAT64_C(  -180.22), SIMDE_FLOAT64_C(  -294.71), SIMDE_FLOAT64_C(  -200.13) },
      { SIMDE_FLOAT64_C(   104.67), SIMDE_FLOAT64_C(  -860.82), SIMDE_FLOAT64_C(   771.13), SIMDE_FLOAT64_C(  -770.36),
        SIMDE_FLOAT64_C(   462.37), SIMDE_FLOAT64_C(  -180.22), SIMDE_FLOAT64_C(   -44.14), SIMDE_FLOAT64_C(  -200.13) } },
    { { SIMDE_FLOAT64_C(  -977.00), SIMDE_FLOAT64_C(   351.48), SIMDE_FLOAT64_C(  -424.82), SIMDE_FLOAT64_C(  -901.29),
        SIMDE_FLOAT64_C(  -563.07), SIMDE_FLOAT64_C(   778.24), SIMDE_FLOAT64_C(   873.31), SIMDE_FLOAT64_C(  -294.17) },
      UINT8_C( 64),
      { SIMDE_FLOAT64_C(   586.02), SIMDE_FLOAT64_C(   934.03), SIMDE_FLOAT64_C(  -141.06), SIMDE_FLOAT64_C(  -150.05),
        SIMDE_FLOAT64_C(   636.05), SIMDE_FLOAT64_C(  -312.91), SIMDE_FLOAT64_C(   -10.87), SIMDE_FLOAT64_C(   407.19) },
      { SIMDE_FLOAT64_C(  -977.00), SIMDE_FLOAT64_C(   351.48), SIMDE_FLOAT64_C(  -424.82), SIMDE_FLOAT64_C(  -901.29),
        SIMDE_FLOAT64_C(  -563.07), SIMDE_FLOAT64_C(   778.24), SIMDE_FLOAT64_C(   -10.87), SIMDE_FLOAT64_C(  -294.17) } },
    { { SIMDE_FLOAT64_C(  -346.14), SIMDE_FLOAT64_C(   -30.49), SIMDE_FLOAT64_C(   386.65), SIMDE_FLOAT64_C(   609.72),
        SIMDE_FLOAT64_C(   422.94), SIMDE_FLOAT64_C(  -680.71), SIMDE_FLOAT64_C(  -285.60), SIMDE_FLOAT64_C(  -733.78) },
      UINT8_C( 17),
      { SIMDE_FLOAT64_C(   -55.97), SIMDE_FLOAT64_C(   728.59), SIMDE_FLOAT64_C(  -528.66), SIMDE_FLOAT64_C(   649.32),
        SIMDE_FLOAT64_C(  -471.55), SIMDE_FLOAT64_C(  -505.66), SIMDE_FLOAT64_C(     0.80), SIMDE_FLOAT64_C(   103.63) },
      { SIMDE_FLOAT64_C(   -55.97), SIMDE_FLOAT64_C(   -30.49), SIMDE_FLOAT64_C(   386.65), SIMDE_FLOAT64_C(   609.72),
        SIMDE_FLOAT64_C(  -471.55), SIMDE_FLOAT64_C(  -680.71), SIMDE_FLOAT64_C(  -285.60), SIMDE_FLOAT64_C(  -733.78) } },
    { { SIMDE_FLOAT64_C(  -406.95), SIMDE_FLOAT64_C(   437.73), SIMDE_FLOAT64_C(  -118.13), SIMDE_FLOAT64_C(  -533.65),
        SIMDE_FLOAT64_C(  -856.44), SIMDE_FLOAT64_C(   856.42), SIMDE_FLOAT64_C(  -947.63), SIMDE_FLOAT64_C(  -922.42) },
      UINT8_C(253),
      { SIMDE_FLOAT64_C(   -97.68), SIMDE_FLOAT64_C(   713.64), SIMDE_FLOAT64_C(   402.45), SIMDE_FLOAT64_C(   891.44),
        SIMDE_FLOAT64_C(   120.82), SIMDE_FLOAT64_C(  -943.68), SIMDE_FLOAT64_C(  -139.05), SIMDE_FLOAT64_C(  -492.53) },
      { SIMDE_FLOAT64_C(   -97.68), SIMDE_FLOAT64_C(   437.73), SIMDE_FLOAT64_C(   402.45), SIMDE_FLOAT64_C(   891.44),
        SIMDE_FLOAT64_C(   120.82), SIMDE_FLOAT64_C(  -943.68), SIMDE_FLOAT64_C(  -139.05), SIMDE_FLOAT64_C(  -492.53) } },
    { { SIMDE_FLOAT64_C(   666.04), SIMDE_FLOAT64_C(  -716.11), SIMDE_FLOAT64_C(  -173.24), SIMDE_FLOAT64_C(  -619.56),
        SIMDE_FLOAT64_C(  -449.89), SIMDE_FLOAT64_C(  -521.67), SIMDE_FLOAT64_C(   324.47), SIMDE_FLOAT64_C(  -721.30) },
      UINT8_C(234),
      { SIMDE_FLOAT64_C(   -26.21), SIMDE_FLOAT64_C(  -192.85), SIMDE_FLOAT64_C(   444.01), SIMDE_FLOAT64_C(   974.59),
        SIMDE_FLOAT64_C(   910.79), SIMDE_FLOAT64_C(  -962.94), SIMDE_FLOAT64_C(   412.32), SIMDE_FLOAT64_C(  -207.34) },
      { SIMDE_FLOAT64_C(   666.04), SIMDE_FLOAT64_C(  -192.85), SIMDE_FLOAT64_C(  -173.24), SIMDE_FLOAT64_C(   974.59),
        SIMDE_FLOAT64_C(  -449.89), SIMDE_FLOAT64_C(  -962.94), SIMDE_FLOAT64_C(   412.32), SIMDE_FLOAT64_C(  -207.34) } },
    { { SIMDE_FLOAT64_C(  -496.59), SIMDE_FLOAT64_C(   555.88), SIMDE_FLOAT64_C(  -350.92), SIMDE_FLOAT64_C(  -444.22),
        SIMDE_FLOAT64_C(   633.46), SIMDE_FLOAT64_C(   364.44), SIMDE_FLOAT64_C(   458.10), SIMDE_FLOAT64_C(   347.10) },
      UINT8_C(219),
      { SIMDE_FLOAT64_C(   349.54), SIMDE_FLOAT64_C(  -532.08), SIMDE_FLOAT64_C(  -176.79), SIMDE_FLOAT64_C(  -789.50),
        SIMDE_FLOAT64_C(   -24.61), SIMDE_FLOAT64_C(  -510.74), SIMDE_FLOAT64_C(  -505.61), SIMDE_FLOAT64_C(   802.15) },
      { SIMDE_FLOAT64_C(   349.54), SIMDE_FLOAT64_C(  -532.08), SIMDE_FLOAT64_C(  -350.92), SIMDE_FLOAT64_C(  -789.50),
        SIMDE_FLOAT64_C(   -24.61), SIMDE_FLOAT64_C(   364.44), SIMDE_FLOAT64_C(  -505.61), SIMDE_FLOAT64_C(   802.15) } },
    { { SIMDE_FLOAT64_C(  -130.31), SIMDE_FLOAT64_C(    44.50), SIMDE_FLOAT64_C(  -719.52), SIMDE_FLOAT64_C(  -805.84),
        SIMDE_FLOAT64_C(   323.20), SIMDE_FLOAT64_C(   230.15), SIMDE_FLOAT64_C(   167.96), SIMDE_FLOAT64_C(  -869.65) },
      UINT8_C( 33),
      { SIMDE_FLOAT64_C(   142.55), SIMDE_FLOAT64_C(  -958.86), SIMDE_FLOAT64_C(  -288.78), SIMDE_FLOAT64_C(  -445.13),
        SIMDE_FLOAT64_C(  -166.20), SIMDE_FLOAT64_C(   214.63), SIMDE_FLOAT64_C(  -889.25), SIMDE_FLOAT64_C(   482.88) },
      { SIMDE_FLOAT64_C(   142.55), SIMDE_FLOAT64_C(    44.50), SIMDE_FLOAT64_C(  -719.52), SIMDE_FLOAT64_C(  -805.84),
        SIMDE_FLOAT64_C(   323.20), SIMDE_FLOAT64_C(   214.63), SIMDE_FLOAT64_C(   167.96), SIMDE_FLOAT64_C(  -869.65) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m512d src = simde_mm512_load_pd(test_vec[i].src);
    simde_test_x86_assert_equal_f64x8(simde_mm512_load_pd(SIMDE_ALIGN_CAST(simde__m512d const *, test_vec[i].r)), simde_mm512_mask_loadu_pd(src, test_vec[i].k, test_vec[i].a), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m512d src = simde_test_x86_random_f64x8(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m512d a = simde_test_x86_random_f64x8(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
    simde__m512d r = simde_mm512_mask_loadu_pd(src, k, &a);

    simde_test_x86_write_f64x8(2, src, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f64x8(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f64x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm512_maskz_loadu_pd (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask8 k;
    SIMDE_ALIGN_LIKE_64(simde__m512) const simde_float64 a[8];
    const simde_float64 r[8];
  } test_vec[] = {
    { UINT8_C(174),
      { SIMDE_FLOAT64_C(  -504.20), SIMDE_FLOAT64_C(   262.37), SIMDE_FLOAT64_C(  -857.17), SIMDE_FLOAT64_C(   425.50),
        SIMDE_FLOAT64_C(   649.41), SIMDE_FLOAT64_C(    67.83), SIMDE_FLOAT64_C(   753.60), SIMDE_FLOAT64_C(  -690.27) },
      { SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(   262.37), SIMDE_FLOAT64_C(  -857.17), SIMDE_FLOAT64_C(   425.50),
        SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(    67.83), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(  -690.27) } },
    { UINT8_C(218),
      { SIMDE_FLOAT64_C(    96.52), SIMDE_FLOAT64_C(  -357.91), SIMDE_FLOAT64_C(    98.33), SIMDE_FLOAT64_C(  -425.12),
        SIMDE_FLOAT64_C(  -387.13), SIMDE_FLOAT64_C(  -109.78), SIMDE_FLOAT64_C(  -854.41), SIMDE_FLOAT64_C(   129.89) },
      { SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(  -357.91), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(  -425.12),
        SIMDE_FLOAT64_C(  -387.13), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(  -854.41), SIMDE_FLOAT64_C(   129.89) } },
    { UINT8_C(252),
      { SIMDE_FLOAT64_C(   730.74), SIMDE_FLOAT64_C(  -130.29), SIMDE_FLOAT64_C(   421.98), SIMDE_FLOAT64_C(  -302.47),
        SIMDE_FLOAT64_C(    61.76), SIMDE_FLOAT64_C(   904.48), SIMDE_FLOAT64_C(   916.96), SIMDE_FLOAT64_C(  -703.51) },
      { SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(   421.98), SIMDE_FLOAT64_C(  -302.47),
        SIMDE_FLOAT64_C(    61.76), SIMDE_FLOAT64_C(   904.48), SIMDE_FLOAT64_C(   916.96), SIMDE_FLOAT64_C(  -703.51) } },
    { UINT8_C(239),
      { SIMDE_FLOAT64_C(   -12.44), SIMDE_FLOAT64_C(  -686.14), SIMDE_FLOAT64_C(  -743.22), SIMDE_FLOAT64_C(  -239.70),
        SIMDE_FLOAT64_C(  -190.34), SIMDE_FLOAT64_C(   519.16), SIMDE_FLOAT64_C(   -96.87), SIMDE_FLOAT64_C(  -764.84) },
      { SIMDE_FLOAT64_C(   -12.44), SIMDE_FLOAT64_C(  -686.14), SIMDE_FLOAT64_C(  -743.22), SIMDE_FLOAT64_C(  -239.70),
        SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(   519.16), SIMDE_FLOAT64_C(   -96.87), SIMDE_FLOAT64_C(  -764.84) } },
    { UINT8_C(201),
      { SIMDE_FLOAT64_C(   970.96), SIMDE_FLOAT64_C(   988.77), SIMDE_FLOAT64_C(   478.30), SIMDE_FLOAT64_C(   -87.24),
        SIMDE_FLOAT64_C(    85.28), SIMDE_FLOAT64_C(  -879.61), SIMDE_FLOAT64_C(  -988.92), SIMDE_FLOAT64_C(   660.16) },
      { SIMDE_FLOAT64_C(   970.96), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(   -87.24),
        SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(  -988.92), SIMDE_FLOAT64_C(   660.16) } },
    { UINT8_C(130),
      { SIMDE_FLOAT64_C(   -98.70), SIMDE_FLOAT64_C(   805.76), SIMDE_FLOAT64_C(   863.15), SIMDE_FLOAT64_C(  -831.44),
        SIMDE_FLOAT64_C(   536.50), SIMDE_FLOAT64_C(  -267.14), SIMDE_FLOAT64_C(   590.54), SIMDE_FLOAT64_C(  -765.97) },
      { SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(   805.76), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00),
        SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(  -765.97) } },
    { UINT8_C(199),
      { SIMDE_FLOAT64_C(   495.01), SIMDE_FLOAT64_C(  -849.01), SIMDE_FLOAT64_C(  -908.89), SIMDE_FLOAT64_C(  -783.46),
        SIMDE_FLOAT64_C(   138.55), SIMDE_FLOAT64_C(  -595.02), SIMDE_FLOAT64_C(  -526.67), SIMDE_FLOAT64_C(   898.85) },
      { SIMDE_FLOAT64_C(   495.01), SIMDE_FLOAT64_C(  -849.01), SIMDE_FLOAT64_C(  -908.89), SIMDE_FLOAT64_C(     0.00),
        SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(  -526.67), SIMDE_FLOAT64_C(   898.85) } },
    { UINT8_C(137),
      { SIMDE_FLOAT64_C(   992.48), SIMDE_FLOAT64_C(  -198.02), SIMDE_FLOAT64_C(   449.80), SIMDE_FLOAT64_C(   161.05),
        SIMDE_FLOAT64_C(  -227.06), SIMDE_FLOAT64_C(   438.57), SIMDE_FLOAT64_C(  -360.65), SIMDE_FLOAT64_C(   685.69) },
      { SIMDE_FLOAT64_C(   992.48), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(   161.05),
        SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(   685.69) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_test_x86_assert_equal_f64x8(simde_mm512_load_pd(SIMDE_ALIGN_CAST(simde__m512d const *, test_vec[i].r)), simde_mm512_maskz_loadu_pd(test_vec[i].k, test_vec[i].a), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m512d a = simde_test_x86_random_f64x8(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
    simde__m512d r = simde_mm512_maskz_loadu_pd(k, &a);

    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_f64x8(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f64x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

#if defined(SIMDE_FLOAT16_IS_SCALAR)
static int
test_simde_mm512_loadu_ph (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    SIMDE_ALIGN_LIKE_16(simde__m512h) const simde_float16 a[32];
    const simde_float16 r[32];
  } test_vec[] = {
    { { SIMDE_FLOAT16_VALUE(    52.12), SIMDE_FLOAT16_VALUE(   -27.91), SIMDE_FLOAT16_VALUE(   -48.81), SIMDE_FLOAT16_VALUE(    74.75),
        SIMDE_FLOAT16_VALUE(    -5.89), SIMDE_FLOAT16_VALUE(   -98.19), SIMDE_FLOAT16_VALUE(   -11.91), SIMDE_FLOAT16_VALUE(    97.75),
        SIMDE_FLOAT16_VALUE(    53.81), SIMDE_FLOAT16_VALUE(   -28.80), SIMDE_FLOAT16_VALUE(    11.48), SIMDE_FLOAT16_VALUE(   -97.62),
        SIMDE_FLOAT16_VALUE(   -25.86), SIMDE_FLOAT16_VALUE(    59.69), SIMDE_FLOAT16_VALUE(   -20.98), SIMDE_FLOAT16_VALUE(   -68.81),
        SIMDE_FLOAT16_VALUE(    20.19), SIMDE_FLOAT16_VALUE(   -64.00), SIMDE_FLOAT16_VALUE(    86.38), SIMDE_FLOAT16_VALUE(   -42.59),
        SIMDE_FLOAT16_VALUE(   -66.19), SIMDE_FLOAT16_VALUE(   -29.02), SIMDE_FLOAT16_VALUE(    -2.12), SIMDE_FLOAT16_VALUE(   -98.94),
        SIMDE_FLOAT16_VALUE(    37.47), SIMDE_FLOAT16_VALUE(    34.91), SIMDE_FLOAT16_VALUE(   -72.69), SIMDE_FLOAT16_VALUE(    76.88),
        SIMDE_FLOAT16_VALUE(    79.06), SIMDE_FLOAT16_VALUE(   -80.25), SIMDE_FLOAT16_VALUE(    69.38), SIMDE_FLOAT16_VALUE(    31.19) },
      { SIMDE_FLOAT16_VALUE(    52.12), SIMDE_FLOAT16_VALUE(   -27.91), SIMDE_FLOAT16_VALUE(   -48.81), SIMDE_FLOAT16_VALUE(    74.75),
        SIMDE_FLOAT16_VALUE(    -5.89), SIMDE_FLOAT16_VALUE(   -98.19), SIMDE_FLOAT16_VALUE(   -11.91), SIMDE_FLOAT16_VALUE(    97.75),
        SIMDE_FLOAT16_VALUE(    53.81), SIMDE_FLOAT16_VALUE(   -28.80), SIMDE_FLOAT16_VALUE(    11.48), SIMDE_FLOAT16_VALUE(   -97.62),
        SIMDE_FLOAT16_VALUE(   -25.86), SIMDE_FLOAT16_VALUE(    59.69), SIMDE_FLOAT16_VALUE(   -20.98), SIMDE_FLOAT16_VALUE(   -68.81),
        SIMDE_FLOAT16_VALUE(    20.19), SIMDE_FLOAT16_VALUE(   -64.00), SIMDE_FLOAT16_VALUE(    86.38), SIMDE_FLOAT16_VALUE(   -42.59),
        SIMDE_FLOAT16_VALUE(   -66.19), SIMDE_FLOAT16_VALUE(   -29.02), SIMDE_FLOAT16_VALUE(    -2.12), SIMDE_FLOAT16_VALUE(   -98.94),
        SIMDE_FLOAT16_VALUE(    37.47), SIMDE_FLOAT16_VALUE(    34.91), SIMDE_FLOAT16_VALUE(   -72.69), SIMDE_FLOAT16_VALUE(    76.88),
        SIMDE_FLOAT16_VALUE(    79.06), SIMDE_FLOAT16_VALUE(   -80.25), SIMDE_FLOAT16_VALUE(    69.38), SIMDE_FLOAT16_VALUE(    31.19) } },
    { { SIMDE_FLOAT16_VALUE(    -8.16), SIMDE_FLOAT16_VALUE(   -79.44), SIMDE_FLOAT16_VALUE(     5.97), SIMDE_FLOAT16_VALUE(    85.94),
        SIMDE_FLOAT16_VALUE(   -77.62), SIMDE_FLOAT16_VALUE(    94.06), SIMDE_FLOAT16_VALUE(    83.69), SIMDE_FLOAT16_VALUE(    76.19),
        SIMDE_FLOAT16_VALUE(   -34.75), SIMDE_FLOAT16_VALUE(    -4.85), SIMDE_FLOAT16_VALUE(    78.56), SIMDE_FLOAT16_VALUE(    39.41),
        SIMDE_FLOAT16_VALUE(   -45.16), SIMDE_FLOAT16_VALUE(   -42.41), SIMDE_FLOAT16_VALUE(    70.56), SIMDE_FLOAT16_VALUE(    75.00),
        SIMDE_FLOAT16_VALUE(    -6.41), SIMDE_FLOAT16_VALUE(    56.94), SIMDE_FLOAT16_VALUE(   -67.56), SIMDE_FLOAT16_VALUE(    27.39),
        SIMDE_FLOAT16_VALUE(   -72.06), SIMDE_FLOAT16_VALUE(    30.31), SIMDE_FLOAT16_VALUE(    28.47), SIMDE_FLOAT16_VALUE(    65.44),
        SIMDE_FLOAT16_VALUE(   -34.75), SIMDE_FLOAT16_VALUE(    55.75), SIMDE_FLOAT16_VALUE(    42.34), SIMDE_FLOAT16_VALUE(   -55.69),
        SIMDE_FLOAT16_VALUE(    75.50), SIMDE_FLOAT16_VALUE(    11.71), SIMDE_FLOAT16_VALUE(    75.50), SIMDE_FLOAT16_VALUE(   -32.66) },
      { SIMDE_FLOAT16_VALUE(    -8.16), SIMDE_FLOAT16_VALUE(   -79.44), SIMDE_FLOAT16_VALUE(     5.97), SIMDE_FLOAT16_VALUE(    85.94),
        SIMDE_FLOAT16_VALUE(   -77.62), SIMDE_FLOAT16_VALUE(    94.06), SIMDE_FLOAT16_VALUE(    83.69), SIMDE_FLOAT16_VALUE(    76.19),
        SIMDE_FLOAT16_VALUE(   -34.75), SIMDE_FLOAT16_VALUE(    -4.85), SIMDE_FLOAT16_VALUE(    78.56), SIMDE_FLOAT16_VALUE(    39.41),
        SIMDE_FLOAT16_VALUE(   -45.16), SIMDE_FLOAT16_VALUE(   -42.41), SIMDE_FLOAT16_VALUE(    70.56), SIMDE_FLOAT16_VALUE(    75.00),
        SIMDE_FLOAT16_VALUE(    -6.41), SIMDE_FLOAT16_VALUE(    56.94), SIMDE_FLOAT16_VALUE(   -67.56), SIMDE_FLOAT16_VALUE(    27.39),
        SIMDE_FLOAT16_VALUE(   -72.06), SIMDE_FLOAT16_VALUE(    30.31), SIMDE_FLOAT16_VALUE(    28.47), SIMDE_FLOAT16_VALUE(    65.44),
        SIMDE_FLOAT16_VALUE(   -34.75), SIMDE_FLOAT16_VALUE(    55.75), SIMDE_FLOAT16_VALUE(    42.34), SIMDE_FLOAT16_VALUE(   -55.69),
        SIMDE_FLOAT16_VALUE(    75.50), SIMDE_FLOAT16_VALUE(    11.71), SIMDE_FLOAT16_VALUE(    75.50), SIMDE_FLOAT16_VALUE(   -32.66) } },
    { { SIMDE_FLOAT16_VALUE(    32.28), SIMDE_FLOAT16_VALUE(   -18.55), SIMDE_FLOAT16_VALUE(   -46.72), SIMDE_FLOAT16_VALUE(    54.62),
        SIMDE_FLOAT16_VALUE(   -24.48), SIMDE_FLOAT16_VALUE(   -63.03), SIMDE_FLOAT16_VALUE(    30.81), SIMDE_FLOAT16_VALUE(    40.78),
        SIMDE_FLOAT16_VALUE(    32.12), SIMDE_FLOAT16_VALUE(     9.38), SIMDE_FLOAT16_VALUE(   -19.81), SIMDE_FLOAT16_VALUE(    86.94),
        SIMDE_FLOAT16_VALUE(    66.94), SIMDE_FLOAT16_VALUE(   -49.25), SIMDE_FLOAT16_VALUE(    61.97), SIMDE_FLOAT16_VALUE(   -39.47),
        SIMDE_FLOAT16_VALUE(   -92.31), SIMDE_FLOAT16_VALUE(    94.38), SIMDE_FLOAT16_VALUE(    87.94), SIMDE_FLOAT16_VALUE(   -64.31),
        SIMDE_FLOAT16_VALUE(    24.72), SIMDE_FLOAT16_VALUE(    16.41), SIMDE_FLOAT16_VALUE(   -98.94), SIMDE_FLOAT16_VALUE(    89.94),
        SIMDE_FLOAT16_VALUE(   -27.83), SIMDE_FLOAT16_VALUE(    43.41), SIMDE_FLOAT16_VALUE(   -65.75), SIMDE_FLOAT16_VALUE(   -52.34),
        SIMDE_FLOAT16_VALUE(   -44.88), SIMDE_FLOAT16_VALUE(   -90.25), SIMDE_FLOAT16_VALUE(    15.00), SIMDE_FLOAT16_VALUE(    87.38) },
      { SIMDE_FLOAT16_VALUE(    32.28), SIMDE_FLOAT16_VALUE(   -18.55), SIMDE_FLOAT16_VALUE(   -46.72), SIMDE_FLOAT16_VALUE(    54.62),
        SIMDE_FLOAT16_VALUE(   -24.48), SIMDE_FLOAT16_VALUE(   -63.03), SIMDE_FLOAT16_VALUE(    30.81), SIMDE_FLOAT16_VALUE(    40.78),
        SIMDE_FLOAT16_VALUE(    32.12), SIMDE_FLOAT16_VALUE(     9.38), SIMDE_FLOAT16_VALUE(   -19.81), SIMDE_FLOAT16_VALUE(    86.94),
        SIMDE_FLOAT16_VALUE(    66.94), SIMDE_FLOAT16_VALUE(   -49.25), SIMDE_FLOAT16_VALUE(    61.97), SIMDE_FLOAT16_VALUE(   -39.47),
        SIMDE_FLOAT16_VALUE(   -92.31), SIMDE_FLOAT16_VALUE(    94.38), SIMDE_FLOAT16_VALUE(    87.94), SIMDE_FLOAT16_VALUE(   -64.31),
        SIMDE_FLOAT16_VALUE(    24.72), SIMDE_FLOAT16_VALUE(    16.41), SIMDE_FLOAT16_VALUE(   -98.94), SIMDE_FLOAT16_VALUE(    89.94),
        SIMDE_FLOAT16_VALUE(   -27.83), SIMDE_FLOAT16_VALUE(    43.41), SIMDE_FLOAT16_VALUE(   -65.75), SIMDE_FLOAT16_VALUE(   -52.34),
        SIMDE_FLOAT16_VALUE(   -44.88), SIMDE_FLOAT16_VALUE(   -90.25), SIMDE_FLOAT16_VALUE(    15.00), SIMDE_FLOAT16_VALUE(    87.38) } },
    { { SIMDE_FLOAT16_VALUE(    -8.80), SIMDE_FLOAT16_VALUE(    68.31), SIMDE_FLOAT16_VALUE(    42.03), SIMDE_FLOAT16_VALUE(    66.69),
        SIMDE_FLOAT16_VALUE(   -94.75), SIMDE_FLOAT16_VALUE(   -27.14), SIMDE_FLOAT16_VALUE(     7.48), SIMDE_FLOAT16_VALUE(    37.38),
        SIMDE_FLOAT16_VALUE(    82.25), SIMDE_FLOAT16_VALUE(    87.69), SIMDE_FLOAT16_VALUE(    24.30), SIMDE_FLOAT16_VALUE(    49.19),
        SIMDE_FLOAT16_VALUE(   -61.59), SIMDE_FLOAT16_VALUE(   -13.74), SIMDE_FLOAT16_VALUE(   -90.25), SIMDE_FLOAT16_VALUE(   -53.88),
        SIMDE_FLOAT16_VALUE(   -19.34), SIMDE_FLOAT16_VALUE(    97.69), SIMDE_FLOAT16_VALUE(   -18.22), SIMDE_FLOAT16_VALUE(   -94.62),
        SIMDE_FLOAT16_VALUE(    14.08), SIMDE_FLOAT16_VALUE(   -17.16), SIMDE_FLOAT16_VALUE(    95.31), SIMDE_FLOAT16_VALUE(    86.25),
        SIMDE_FLOAT16_VALUE(   -73.75), SIMDE_FLOAT16_VALUE(   -70.38), SIMDE_FLOAT16_VALUE(   -66.06), SIMDE_FLOAT16_VALUE(   -18.62),
        SIMDE_FLOAT16_VALUE(   -60.66), SIMDE_FLOAT16_VALUE(    48.91), SIMDE_FLOAT16_VALUE(   -31.23), SIMDE_FLOAT16_VALUE(    30.55) },
      { SIMDE_FLOAT16_VALUE(    -8.80), SIMDE_FLOAT16_VALUE(    68.31), SIMDE_FLOAT16_VALUE(    42.03), SIMDE_FLOAT16_VALUE(    66.69),
        SIMDE_FLOAT16_VALUE(   -94.75), SIMDE_FLOAT16_VALUE(   -27.14), SIMDE_FLOAT16_VALUE(     7.48), SIMDE_FLOAT16_VALUE(    37.38),
        SIMDE_FLOAT16_VALUE(    82.25), SIMDE_FLOAT16_VALUE(    87.69), SIMDE_FLOAT16_VALUE(    24.30), SIMDE_FLOAT16_VALUE(    49.19),
        SIMDE_FLOAT16_VALUE(   -61.59), SIMDE_FLOAT16_VALUE(   -13.74), SIMDE_FLOAT16_VALUE(   -90.25), SIMDE_FLOAT16_VALUE(   -53.88),
        SIMDE_FLOAT16_VALUE(   -19.34), SIMDE_FLOAT16_VALUE(    97.69), SIMDE_FLOAT16_VALUE(   -18.22), SIMDE_FLOAT16_VALUE(   -94.62),
        SIMDE_FLOAT16_VALUE(    14.08), SIMDE_FLOAT16_VALUE(   -17.16), SIMDE_FLOAT16_VALUE(    95.31), SIMDE_FLOAT16_VALUE(    86.25),
        SIMDE_FLOAT16_VALUE(   -73.75), SIMDE_FLOAT16_VALUE(   -70.38), SIMDE_FLOAT16_VALUE(   -66.06), SIMDE_FLOAT16_VALUE(   -18.62),
        SIMDE_FLOAT16_VALUE(   -60.66), SIMDE_FLOAT16_VALUE(    48.91), SIMDE_FLOAT16_VALUE(   -31.23), SIMDE_FLOAT16_VALUE(    30.55) } },
    { { SIMDE_FLOAT16_VALUE(    17.20), SIMDE_FLOAT16_VALUE(   -89.19), SIMDE_FLOAT16_VALUE(    -2.74), SIMDE_FLOAT16_VALUE(    22.45),
        SIMDE_FLOAT16_VALUE(   -16.33), SIMDE_FLOAT16_VALUE(   -95.25), SIMDE_FLOAT16_VALUE(   -40.19), SIMDE_FLOAT16_VALUE(   -34.09),
        SIMDE_FLOAT16_VALUE(    92.38), SIMDE_FLOAT16_VALUE(    84.12), SIMDE_FLOAT16_VALUE(   -84.88), SIMDE_FLOAT16_VALUE(   -69.19),
        SIMDE_FLOAT16_VALUE(   -29.64), SIMDE_FLOAT16_VALUE(   -75.19), SIMDE_FLOAT16_VALUE(   -23.06), SIMDE_FLOAT16_VALUE(    51.03),
        SIMDE_FLOAT16_VALUE(   -77.50), SIMDE_FLOAT16_VALUE(    58.72), SIMDE_FLOAT16_VALUE(    56.41), SIMDE_FLOAT16_VALUE(    36.59),
        SIMDE_FLOAT16_VALUE(   -58.44), SIMDE_FLOAT16_VALUE(    51.75), SIMDE_FLOAT16_VALUE(    22.84), SIMDE_FLOAT16_VALUE(   -32.16),
        SIMDE_FLOAT16_VALUE(    81.38), SIMDE_FLOAT16_VALUE(    56.75), SIMDE_FLOAT16_VALUE(    49.19), SIMDE_FLOAT16_VALUE(   -79.31),
        SIMDE_FLOAT16_VALUE(     5.67), SIMDE_FLOAT16_VALUE(   -82.00), SIMDE_FLOAT16_VALUE(    51.25), SIMDE_FLOAT16_VALUE(   -77.12) },
      { SIMDE_FLOAT16_VALUE(    17.20), SIMDE_FLOAT16_VALUE(   -89.19), SIMDE_FLOAT16_VALUE(    -2.74), SIMDE_FLOAT16_VALUE(    22.45),
        SIMDE_FLOAT16_VALUE(   -16.33), SIMDE_FLOAT16_VALUE(   -95.25), SIMDE_FLOAT16_VALUE(   -40.19), SIMDE_FLOAT16_VALUE(   -34.09),
        SIMDE_FLOAT16_VALUE(    92.38), SIMDE_FLOAT16_VALUE(    84.12), SIMDE_FLOAT16_VALUE(   -84.88), SIMDE_FLOAT16_VALUE(   -69.19),
        SIMDE_FLOAT16_VALUE(   -29.64), SIMDE_FLOAT16_VALUE(   -75.19), SIMDE_FLOAT16_VALUE(   -23.06), SIMDE_FLOAT16_VALUE(    51.03),
        SIMDE_FLOAT16_VALUE(   -77.50), SIMDE_FLOAT16_VALUE(    58.72), SIMDE_FLOAT16_VALUE(    56.41), SIMDE_FLOAT16_VALUE(    36.59),
        SIMDE_FLOAT16_VALUE(   -58.44), SIMDE_FLOAT16_VALUE(    51.75), SIMDE_FLOAT16_VALUE(    22.84), SIMDE_FLOAT16_VALUE(   -32.16),
        SIMDE_FLOAT16_VALUE(    81.38), SIMDE_FLOAT16_VALUE(    56.75), SIMDE_FLOAT16_VALUE(    49.19), SIMDE_FLOAT16_VALUE(   -79.31),
        SIMDE_FLOAT16_VALUE(     5.67), SIMDE_FLOAT16_VALUE(   -82.00), SIMDE_FLOAT16_VALUE(    51.25), SIMDE_FLOAT16_VALUE(   -77.12) } },
    { { SIMDE_FLOAT16_VALUE(   -71.19), SIMDE_FLOAT16_VALUE(   -51.50), SIMDE_FLOAT16_VALUE(    45.31), SIMDE_FLOAT16_VALUE(    12.46),
        SIMDE_FLOAT16_VALUE(   -46.75), SIMDE_FLOAT16_VALUE(   -94.88), SIMDE_FLOAT16_VALUE(    78.38), SIMDE_FLOAT16_VALUE(   -54.34),
        SIMDE_FLOAT16_VALUE(    89.25), SIMDE_FLOAT16_VALUE(    93.50), SIMDE_FLOAT16_VALUE(   -23.52), SIMDE_FLOAT16_VALUE(   -40.41),
        SIMDE_FLOAT16_VALUE(   -81.69), SIMDE_FLOAT16_VALUE(    53.41), SIMDE_FLOAT16_VALUE(   -89.38), SIMDE_FLOAT16_VALUE(   -59.16),
        SIMDE_FLOAT16_VALUE(    12.13), SIMDE_FLOAT16_VALUE(    67.00), SIMDE_FLOAT16_VALUE(    77.44), SIMDE_FLOAT16_VALUE(    53.69),
        SIMDE_FLOAT16_VALUE(    18.77), SIMDE_FLOAT16_VALUE(     0.25), SIMDE_FLOAT16_VALUE(   -78.50), SIMDE_FLOAT16_VALUE(     0.12),
        SIMDE_FLOAT16_VALUE(   -43.00), SIMDE_FLOAT16_VALUE(    70.75), SIMDE_FLOAT16_VALUE(    20.81), SIMDE_FLOAT16_VALUE(    62.66),
        SIMDE_FLOAT16_VALUE(    88.69), SIMDE_FLOAT16_VALUE(   -27.94), SIMDE_FLOAT16_VALUE(    85.56), SIMDE_FLOAT16_VALUE(   -82.50) },
      { SIMDE_FLOAT16_VALUE(   -71.19), SIMDE_FLOAT16_VALUE(   -51.50), SIMDE_FLOAT16_VALUE(    45.31), SIMDE_FLOAT16_VALUE(    12.46),
        SIMDE_FLOAT16_VALUE(   -46.75), SIMDE_FLOAT16_VALUE(   -94.88), SIMDE_FLOAT16_VALUE(    78.38), SIMDE_FLOAT16_VALUE(   -54.34),
        SIMDE_FLOAT16_VALUE(    89.25), SIMDE_FLOAT16_VALUE(    93.50), SIMDE_FLOAT16_VALUE(   -23.52), SIMDE_FLOAT16_VALUE(   -40.41),
        SIMDE_FLOAT16_VALUE(   -81.69), SIMDE_FLOAT16_VALUE(    53.41), SIMDE_FLOAT16_VALUE(   -89.38), SIMDE_FLOAT16_VALUE(   -59.16),
        SIMDE_FLOAT16_VALUE(    12.13), SIMDE_FLOAT16_VALUE(    67.00), SIMDE_FLOAT16_VALUE(    77.44), SIMDE_FLOAT16_VALUE(    53.69),
        SIMDE_FLOAT16_VALUE(    18.77), SIMDE_FLOAT16_VALUE(     0.25), SIMDE_FLOAT16_VALUE(   -78.50), SIMDE_FLOAT16_VALUE(     0.12),
        SIMDE_FLOAT16_VALUE(   -43.00), SIMDE_FLOAT16_VALUE(    70.75), SIMDE_FLOAT16_VALUE(    20.81), SIMDE_FLOAT16_VALUE(    62.66),
        SIMDE_FLOAT16_VALUE(    88.69), SIMDE_FLOAT16_VALUE(   -27.94), SIMDE_FLOAT16_VALUE(    85.56), SIMDE_FLOAT16_VALUE(   -82.50) } },
    { { SIMDE_FLOAT16_VALUE(    20.58), SIMDE_FLOAT16_VALUE(    30.86), SIMDE_FLOAT16_VALUE(    29.95), SIMDE_FLOAT16_VALUE(    73.81),
        SIMDE_FLOAT16_VALUE(    36.00), SIMDE_FLOAT16_VALUE(     8.33), SIMDE_FLOAT16_VALUE(   -80.50), SIMDE_FLOAT16_VALUE(    25.22),
        SIMDE_FLOAT16_VALUE(     1.81), SIMDE_FLOAT16_VALUE(    -4.02), SIMDE_FLOAT16_VALUE(    84.81), SIMDE_FLOAT16_VALUE(    20.12),
        SIMDE_FLOAT16_VALUE(   -50.59), SIMDE_FLOAT16_VALUE(    95.44), SIMDE_FLOAT16_VALUE(    60.97), SIMDE_FLOAT16_VALUE(    61.53),
        SIMDE_FLOAT16_VALUE(    62.44), SIMDE_FLOAT16_VALUE(    38.38), SIMDE_FLOAT16_VALUE(    15.22), SIMDE_FLOAT16_VALUE(   -18.80),
        SIMDE_FLOAT16_VALUE(   -61.38), SIMDE_FLOAT16_VALUE(    36.75), SIMDE_FLOAT16_VALUE(    81.31), SIMDE_FLOAT16_VALUE(    -4.37),
        SIMDE_FLOAT16_VALUE(     7.46), SIMDE_FLOAT16_VALUE(     2.15), SIMDE_FLOAT16_VALUE(   -41.69), SIMDE_FLOAT16_VALUE(    -3.84),
        SIMDE_FLOAT16_VALUE(    74.19), SIMDE_FLOAT16_VALUE(   -56.16), SIMDE_FLOAT16_VALUE(    13.65), SIMDE_FLOAT16_VALUE(    -5.20) },
      { SIMDE_FLOAT16_VALUE(    20.58), SIMDE_FLOAT16_VALUE(    30.86), SIMDE_FLOAT16_VALUE(    29.95), SIMDE_FLOAT16_VALUE(    73.81),
        SIMDE_FLOAT16_VALUE(    36.00), SIMDE_FLOAT16_VALUE(     8.33), SIMDE_FLOAT16_VALUE(   -80.50), SIMDE_FLOAT16_VALUE(    25.22),
        SIMDE_FLOAT16_VALUE(     1.81), SIMDE_FLOAT16_VALUE(    -4.02), SIMDE_FLOAT16_VALUE(    84.81), SIMDE_FLOAT16_VALUE(    20.12),
        SIMDE_FLOAT16_VALUE(   -50.59), SIMDE_FLOAT16_VALUE(    95.44), SIMDE_FLOAT16_VALUE(    60.97), SIMDE_FLOAT16_VALUE(    61.53),
        SIMDE_FLOAT16_VALUE(    62.44), SIMDE_FLOAT16_VALUE(    38.38), SIMDE_FLOAT16_VALUE(    15.22), SIMDE_FLOAT16_VALUE(   -18.80),
        SIMDE_FLOAT16_VALUE(   -61.38), SIMDE_FLOAT16_VALUE(    36.75), SIMDE_FLOAT16_VALUE(    81.31), SIMDE_FLOAT16_VALUE(    -4.37),
        SIMDE_FLOAT16_VALUE(     7.46), SIMDE_FLOAT16_VALUE(     2.15), SIMDE_FLOAT16_VALUE(   -41.69), SIMDE_FLOAT16_VALUE(    -3.84),
        SIMDE_FLOAT16_VALUE(    74.19), SIMDE_FLOAT16_VALUE(   -56.16), SIMDE_FLOAT16_VALUE(    13.65), SIMDE_FLOAT16_VALUE(    -5.20) } },
    { { SIMDE_FLOAT16_VALUE(    74.69), SIMDE_FLOAT16_VALUE(   -56.41), SIMDE_FLOAT16_VALUE(   -31.36), SIMDE_FLOAT16_VALUE(    10.70),
        SIMDE_FLOAT16_VALUE(    51.94), SIMDE_FLOAT16_VALUE(   -11.86), SIMDE_FLOAT16_VALUE(   -64.06), SIMDE_FLOAT16_VALUE(   -46.25),
        SIMDE_FLOAT16_VALUE(    84.12), SIMDE_FLOAT16_VALUE(   -79.25), SIMDE_FLOAT16_VALUE(    73.88), SIMDE_FLOAT16_VALUE(   -66.50),
        SIMDE_FLOAT16_VALUE(   -83.88), SIMDE_FLOAT16_VALUE(    34.84), SIMDE_FLOAT16_VALUE(    95.06), SIMDE_FLOAT16_VALUE(    78.56),
        SIMDE_FLOAT16_VALUE(   -26.80), SIMDE_FLOAT16_VALUE(    10.27), SIMDE_FLOAT16_VALUE(   -40.19), SIMDE_FLOAT16_VALUE(    11.82),
        SIMDE_FLOAT16_VALUE(   -53.00), SIMDE_FLOAT16_VALUE(   -58.88), SIMDE_FLOAT16_VALUE(   -92.56), SIMDE_FLOAT16_VALUE(    54.47),
        SIMDE_FLOAT16_VALUE(    43.28), SIMDE_FLOAT16_VALUE(   -34.25), SIMDE_FLOAT16_VALUE(   -49.38), SIMDE_FLOAT16_VALUE(    17.48),
        SIMDE_FLOAT16_VALUE(     9.59), SIMDE_FLOAT16_VALUE(    64.25), SIMDE_FLOAT16_VALUE(   -87.69), SIMDE_FLOAT16_VALUE(   -15.70) },
      { SIMDE_FLOAT16_VALUE(    74.69), SIMDE_FLOAT16_VALUE(   -56.41), SIMDE_FLOAT16_VALUE(   -31.36), SIMDE_FLOAT16_VALUE(    10.70),
        SIMDE_FLOAT16_VALUE(    51.94), SIMDE_FLOAT16_VALUE(   -11.86), SIMDE_FLOAT16_VALUE(   -64.06), SIMDE_FLOAT16_VALUE(   -46.25),
        SIMDE_FLOAT16_VALUE(    84.12), SIMDE_FLOAT16_VALUE(   -79.25), SIMDE_FLOAT16_VALUE(    73.88), SIMDE_FLOAT16_VALUE(   -66.50),
        SIMDE_FLOAT16_VALUE(   -83.88), SIMDE_FLOAT16_VALUE(    34.84), SIMDE_FLOAT16_VALUE(    95.06), SIMDE_FLOAT16_VALUE(    78.56),
        SIMDE_FLOAT16_VALUE(   -26.80), SIMDE_FLOAT16_VALUE(    10.27), SIMDE_FLOAT16_VALUE(   -40.19), SIMDE_FLOAT16_VALUE(    11.82),
        SIMDE_FLOAT16_VALUE(   -53.00), SIMDE_FLOAT16_VALUE(   -58.88), SIMDE_FLOAT16_VALUE(   -92.56), SIMDE_FLOAT16_VALUE(    54.47),
        SIMDE_FLOAT16_VALUE(    43.28), SIMDE_FLOAT16_VALUE(   -34.25), SIMDE_FLOAT16_VALUE(   -49.38), SIMDE_FLOAT16_VALUE(    17.48),
        SIMDE_FLOAT16_VALUE(     9.59), SIMDE_FLOAT16_VALUE(    64.25), SIMDE_FLOAT16_VALUE(   -87.69), SIMDE_FLOAT16_VALUE(   -15.70) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_test_x86_assert_equal_f16x32(simde_mm512_load_ph(SIMDE_ALIGN_CAST(simde__m512h const *, test_vec[i].a)), simde_mm512_loadu_ph(test_vec[i].r), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m512h a = simde_test_x86_random_f16x32(SIMDE_FLOAT16_VALUE(-100), SIMDE_FLOAT16_VALUE(100));
    simde__m512h r = a;

    simde_test_x86_write_f16x32(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_f16x32(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}
#endif

SIMDE_TEST_FUNC_LIST_BEGIN
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_loadu_epi8)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_loadu_epi16)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_loadu_epi32)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_loadu_epi64)

  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_loadu_epi8)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_loadu_epi16)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_maskz_loadu_epi16)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_loadu_epi32)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_loadu_epi64)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_maskz_loadu_ps)

  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_loadu_epi8)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_loadu_epi16)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_mask_loadu_epi16)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_maskz_loadu_epi16)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_loadu_epi32)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_mask_loadu_epi32)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_loadu_epi64)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_mask_loadu_epi64)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_maskz_loadu_epi64)

  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_mask_loadu_ps)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_maskz_loadu_ps)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_mask_loadu_pd)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_maskz_loadu_pd)

  #if defined(SIMDE_FLOAT16_IS_SCALAR)
    SIMDE_TEST_FUNC_LIST_ENTRY(mm512_loadu_ph)
  #endif

  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_loadu_si512)
SIMDE_TEST_FUNC_LIST_END
#include <test/x86/avx512/test-avx512-footer.h>
