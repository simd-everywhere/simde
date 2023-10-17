#define SIMDE_TEST_ARM_NEON_INSN qshl

#include "test-neon.h"
#include "../../../simde/arm/neon/qshl_n.h"

/* Until v12, clang used unsigned parameters on the scalar versions, so
 * when testing we need to disable the -Wsign-conversion to avoid a
 * diagnostic.  If this is a problem in your code you might want to
 * consider using simde_vqshl* instead of vqshl* so you can avoid an
 * ifdef. */

#if HEDLEY_HAS_WARNING("-Wsign-conversion") && defined(SIMDE_NATIVE_ALIASES_TESTING)
  #pragma clang diagnostic ignored "-Wsign-conversion"
#endif

static int
test_simde_vqshlb_n_s8 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    int8_t a;
    int8_t n;
    int8_t r;
  } test_vec[] = {
    {    INT8_C(   84),
         INT8_C(    1),
              INT8_MAX },
    {    INT8_C(   76),
         INT8_C(    3),
              INT8_MAX },
    {   -INT8_C(   66),
         INT8_C(    0),
        -INT8_C(   66) },
    {   -INT8_C(   71),
         INT8_C(    2),
              INT8_MIN },
    {   -INT8_C(  123),
         INT8_C(    6),
              INT8_MIN },
    {   -INT8_C(   64),
         INT8_C(    6),
              INT8_MIN },
    {    INT8_C(   53),
         INT8_C(    4),
              INT8_MAX },
    {   -INT8_C(   36),
         INT8_C(    1),
        -INT8_C(   72) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    int8_t r;
    SIMDE_CONSTIFY_8_(simde_vqshlb_n_s8, r, (HEDLEY_UNREACHABLE(), r), test_vec[i].n, test_vec[i].a);

    simde_assert_equal_i8(r, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_vqshlh_n_s16 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    int16_t a;
    int16_t n;
    int16_t r;
  } test_vec[] = {
    {   -INT16_C(  24158),
         INT16_C(      6),
               INT16_MIN },
    {   -INT16_C(   3172),
         INT16_C(      0),
        -INT16_C(   3172) },
    {   -INT16_C(   1716),
         INT16_C(      9),
               INT16_MIN },
    {    INT16_C(  12698),
         INT16_C(      0),
         INT16_C(  12698) },
    {   -INT16_C(  20989),
         INT16_C(     13),
               INT16_MIN },
    {    INT16_C(  29643),
         INT16_C(      2),
               INT16_MAX },
    {   -INT16_C(  32563),
         INT16_C(     15),
               INT16_MIN },
    {   -INT16_C(   9395),
         INT16_C(      9),
               INT16_MIN },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    int16_t r;
    SIMDE_CONSTIFY_16_(simde_vqshlh_n_s16, r, (HEDLEY_UNREACHABLE(), r), test_vec[i].n, test_vec[i].a);

    simde_assert_equal_i16(r, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_vqshls_n_s32 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    int32_t a;
    int32_t n;
    int32_t r;
  } test_vec[] = {
    {    INT32_C(   734070998),
         INT32_C(          22),
                    INT32_MAX },
    {   -INT32_C(  1381815004),
         INT32_C(           9),
                    INT32_MIN },
    {    INT32_C(    56553928),
         INT32_C(           0),
         INT32_C(    56553928) },
    {   -INT32_C(  2086394238),
         INT32_C(          23),
                    INT32_MIN },
    {   -INT32_C(  2044455317),
         INT32_C(          14),
                    INT32_MIN },
    {   -INT32_C(  1355920605),
         INT32_C(           6),
                    INT32_MIN },
    {   -INT32_C(  1446659077),
         INT32_C(          17),
                    INT32_MIN },
    {   -INT32_C(   474948635),
         INT32_C(          17),
                    INT32_MIN },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    int32_t r;
    SIMDE_CONSTIFY_32_(simde_vqshls_n_s32, r, (HEDLEY_UNREACHABLE(), r), test_vec[i].n, test_vec[i].a);

    simde_assert_equal_i32(r, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_vqshld_n_s64 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    int64_t a;
    int64_t n;
    int64_t r;
  } test_vec[] = {
    {   -INT64_C( 3292810008776062702),
         INT64_C(                  25),
                            INT64_MIN },
    {    INT64_C( 2746279207385181801),
         INT64_C(                   4),
                            INT64_MAX },
    {    INT64_C( 6492565024277658433),
         INT64_C(                  59),
                            INT64_MAX },
    {    INT64_C( 9109811792200353237),
         INT64_C(                  17),
                            INT64_MAX },
    {    INT64_C( 8088818188310847726),
         INT64_C(                  46),
                            INT64_MAX },
    {   -INT64_C( 1088132690814548021),
         INT64_C(                  58),
                            INT64_MIN },
    {   -INT64_C( 6033727136566393495),
         INT64_C(                  12),
                            INT64_MIN },
    {   -INT64_C( 7914593034248993296),
         INT64_C(                  40),
                            INT64_MIN },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    int64_t r;
    SIMDE_CONSTIFY_64_(simde_vqshld_n_s64, r, (HEDLEY_UNREACHABLE(), r), test_vec[i].n, test_vec[i].a);

    simde_assert_equal_i64(r, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_vqshlb_n_u8 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    uint8_t a;
    int8_t n;
    uint8_t r;
  } test_vec[] = {
    {    UINT8_C(  179),
         INT8_C(    0),
         UINT8_C(  179) },
    {    UINT8_C(  125),
         INT8_C(    0),
         UINT8_C(  125) },
    {    UINT8_C(  162),
         INT8_C(    4),
             UINT8_MAX },
    {    UINT8_C(  107),
         INT8_C(    7),
             UINT8_MAX },
    {    UINT8_C(  149),
         INT8_C(    0),
         UINT8_C(  149) },
    {    UINT8_C(   80),
         INT8_C(    2),
             UINT8_MAX },
    {    UINT8_C(  209),
         INT8_C(    5),
             UINT8_MAX },
    {    UINT8_C(  248),
         INT8_C(    3),
             UINT8_MAX },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    uint8_t r;
    SIMDE_CONSTIFY_8_(simde_vqshlb_n_u8, r, (HEDLEY_UNREACHABLE(), r), test_vec[i].n, test_vec[i].a);

    simde_assert_equal_u8(r, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_vqshlh_n_u16 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    uint16_t a;
    int16_t n;
    uint16_t r;
  } test_vec[] = {
    {    UINT16_C(   16208),
         INT16_C(       2),
         UINT16_C(   64832) },
    {    UINT16_C(    6064),
         INT16_C(       9),
               UINT16_MAX },
    {    UINT16_C(   24349),
         INT16_C(      12),
               UINT16_MAX },
    {    UINT16_C(   43044),
         INT16_C(      15),
               UINT16_MAX },
    {    UINT16_C(   17835),
         INT16_C(      10),
               UINT16_MAX },
    {    UINT16_C(   35158),
         INT16_C(       7),
               UINT16_MAX },
    {    UINT16_C(   29392),
         INT16_C(       4),
               UINT16_MAX },
    {    UINT16_C(   45176),
         INT16_C(       3),
               UINT16_MAX },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    uint16_t r;
    SIMDE_CONSTIFY_16_(simde_vqshlh_n_u16, r, (HEDLEY_UNREACHABLE(), r), test_vec[i].n, test_vec[i].a);

    simde_assert_equal_u16(r, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_vqshls_n_u32 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    uint32_t a;
    int32_t n;
    uint32_t r;
  } test_vec[] = {
    {    UINT32_C(449556519),
         INT32_C(       0),
         UINT32_C(449556519) },
    {    UINT32_C(789920460),
         INT32_C(       3),
               UINT32_MAX },
    {    UINT32_C(34137786),
         INT32_C(      21),
               UINT32_MAX },
    {    UINT32_C(949374081),
         INT32_C(       4),
               UINT32_MAX },
    {    UINT32_C(3915653368),
         INT32_C(       2),
               UINT32_MAX },
    {    UINT32_C(1460287780),
         INT32_C(      25),
               UINT32_MAX },
    {    UINT32_C(4178386259),
         INT32_C(      20),
               UINT32_MAX },
    {    UINT32_C(750328005),
         INT32_C(      11),
               UINT32_MAX },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    uint32_t r;
    SIMDE_CONSTIFY_32_(simde_vqshls_n_u32, r, (HEDLEY_UNREACHABLE(), r), test_vec[i].n, test_vec[i].a);

    simde_assert_equal_u32(r, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_vqshld_n_u64 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    uint64_t a;
    int64_t n;
    uint64_t r;
  } test_vec[] = {
    {    UINT64_C( 8344124081252985275),
         INT64_C(                  55),
                           UINT64_MAX },
    {    UINT64_C(  636454356997588084),
         INT64_C(                  52),
                           UINT64_MAX },
    {    UINT64_C(13982781360687174434),
         INT64_C(                  35),
                           UINT64_MAX },
    {    UINT64_C(12813806123922193343),
         INT64_C(                  10),
                           UINT64_MAX },
    {    UINT64_C( 8314098057120347358),
         INT64_C(                  23),
                           UINT64_MAX },
    {    UINT64_C( 1432565870918233790),
         INT64_C(                  31),
                           UINT64_MAX },
    {    UINT64_C(16708691832672280797),
         INT64_C(                  20),
                           UINT64_MAX },
    {    UINT64_C(10506927218060336816),
         INT64_C(                  28),
                           UINT64_MAX },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    uint64_t r;
    SIMDE_CONSTIFY_64_(simde_vqshld_n_u64, r, (HEDLEY_UNREACHABLE(), r), test_vec[i].n, test_vec[i].a);

    simde_assert_equal_u64(r, test_vec[i].r);
  }

  return 0;
}

static int
test_simde_vqshl_n_s8 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    int8_t a[8];
    int8_t n;
    int8_t r[8];
  } test_vec[] = {
    { { -INT8_C(   80), -INT8_C(  100), -INT8_C(   63),  INT8_C(    1),
         INT8_C(  115), -INT8_C(   83),  INT8_C(   75), -INT8_C(   33) },
         INT8_C(    7),
      {       INT8_MIN,       INT8_MIN,       INT8_MIN,       INT8_MAX,
              INT8_MAX,       INT8_MIN,       INT8_MAX,       INT8_MIN } },
    { {  INT8_C(    5), -INT8_C(  106),  INT8_C(   59),  INT8_C(  120),
        -INT8_C(  119), -INT8_C(  120), -INT8_C(   53),  INT8_C(   28) },
         INT8_C(    4),
      {  INT8_C(   80),       INT8_MIN,       INT8_MAX,       INT8_MAX,
              INT8_MIN,       INT8_MIN,       INT8_MIN,       INT8_MAX } },
    { {  INT8_C(  115),  INT8_C(  109), -INT8_C(   77), -INT8_C(   38),
        -INT8_C(   98), -INT8_C(   64), -INT8_C(   55),  INT8_C(  118) },
         INT8_C(    3),
      {       INT8_MAX,       INT8_MAX,       INT8_MIN,       INT8_MIN,
              INT8_MIN,       INT8_MIN,       INT8_MIN,       INT8_MAX } },
    { { -INT8_C(   32),  INT8_C(  121), -INT8_C(   61),  INT8_C(   46),
        -INT8_C(  110),  INT8_C(  119),  INT8_C(   37),  INT8_C(   70) },
         INT8_C(    1),
      { -INT8_C(   64),       INT8_MAX, -INT8_C(  122),  INT8_C(   92),
              INT8_MIN,       INT8_MAX,  INT8_C(   74),       INT8_MAX } },
    { { -INT8_C(   46), -INT8_C(   52),  INT8_C(   66),  INT8_C(  116),
         INT8_C(   16),  INT8_C(   16), -INT8_C(  118),  INT8_C(   75) },
         INT8_C(    5),
      {       INT8_MIN,       INT8_MIN,       INT8_MAX,       INT8_MAX,
              INT8_MAX,       INT8_MAX,       INT8_MIN,       INT8_MAX } },
    { { -INT8_C(  114), -INT8_C(   34),  INT8_C(  123),  INT8_C(   13),
         INT8_C(  125),  INT8_C(    7),       INT8_MAX,  INT8_C(   87) },
         INT8_C(    7),
      {       INT8_MIN,       INT8_MIN,       INT8_MAX,       INT8_MAX,
              INT8_MAX,       INT8_MAX,       INT8_MAX,       INT8_MAX } },
    { { -INT8_C(  125),  INT8_C(   70), -INT8_C(   83), -INT8_C(   88),
         INT8_C(  125), -INT8_C(   81), -INT8_C(   97),  INT8_C(  116) },
         INT8_C(    5),
      {       INT8_MIN,       INT8_MAX,       INT8_MIN,       INT8_MIN,
              INT8_MAX,       INT8_MIN,       INT8_MIN,       INT8_MAX } },
    { { -INT8_C(  123), -INT8_C(  110),  INT8_C(   87), -INT8_C(   18),
         INT8_C(   43),  INT8_C(   53),  INT8_C(    1), -INT8_C(   74) },
         INT8_C(    2),
      {       INT8_MIN,       INT8_MIN,       INT8_MAX, -INT8_C(   72),
              INT8_MAX,       INT8_MAX,  INT8_C(    4),       INT8_MIN } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int8x8_t a = simde_vld1_s8(test_vec[i].a);
    int8_t n = test_vec[i].n;
    simde_int8x8_t r;
    SIMDE_CONSTIFY_8_(simde_vqshl_n_s8, r, (HEDLEY_UNREACHABLE(), r), n, a);

    simde_test_arm_neon_assert_equal_i8x8(r, simde_vld1_s8(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vqshl_n_s16 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    int16_t a[4];
    int16_t n;
    int16_t r[4];
  } test_vec[] = {
    { {  INT16_C(   9725),  INT16_C(  16146),  INT16_C(  30907),  INT16_C(  10580) },
         INT16_C(     11),
      {        INT16_MAX,        INT16_MAX,        INT16_MAX,        INT16_MAX } },
    { { -INT16_C(  31565), -INT16_C(   4370),  INT16_C(   3592), -INT16_C(   9974) },
         INT16_C(      9),
      {        INT16_MIN,        INT16_MIN,        INT16_MAX,        INT16_MIN } },
    { { -INT16_C(  30344),  INT16_C(  13984),  INT16_C(   7545),  INT16_C(  22501) },
         INT16_C(      7),
      {        INT16_MIN,        INT16_MAX,        INT16_MAX,        INT16_MAX } },
    { { -INT16_C(  14652), -INT16_C(  20646), -INT16_C(  25937),  INT16_C(  31330) },
         INT16_C(      1),
      { -INT16_C(  29304),        INT16_MIN,        INT16_MIN,        INT16_MAX } },
    { {  INT16_C(   5001),  INT16_C(  16082),  INT16_C(    243),  INT16_C(  17363) },
         INT16_C(      8),
      {        INT16_MAX,        INT16_MAX,        INT16_MAX,        INT16_MAX } },
    { {  INT16_C(   6796), -INT16_C(  10974), -INT16_C(  26277),  INT16_C(  20908) },
         INT16_C(      7),
      {        INT16_MAX,        INT16_MIN,        INT16_MIN,        INT16_MAX } },
    { { -INT16_C(  27688), -INT16_C(   2852),  INT16_C(    160), -INT16_C(  10339) },
         INT16_C(     12),
      {        INT16_MIN,        INT16_MIN,        INT16_MAX,        INT16_MIN } },
    { {  INT16_C(  31921), -INT16_C(    242),  INT16_C(  31809), -INT16_C(   5166) },
         INT16_C(     11),
      {        INT16_MAX,        INT16_MIN,        INT16_MAX,        INT16_MIN } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x4_t a = simde_vld1_s16(test_vec[i].a);
    int16_t n = test_vec[i].n;
    simde_int16x4_t r;
    SIMDE_CONSTIFY_16_(simde_vqshl_n_s16, r, (HEDLEY_UNREACHABLE(), r), n, a);

    simde_test_arm_neon_assert_equal_i16x4(r, simde_vld1_s16(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vqshl_n_s32 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    int32_t a[2];
    int32_t n;
    int32_t r[2];
  } test_vec[] = {
    { {  INT32_C(  1884530711),  INT32_C(   365640215) },
         INT32_C(           5),
      {             INT32_MAX,             INT32_MAX } },
    { {  INT32_C(   221212881),  INT32_C(   337739226) },
         INT32_C(          14),
      {             INT32_MAX,             INT32_MAX } },
    { { -INT32_C(   607613899),  INT32_C(  1197518390) },
         INT32_C(          27),
      {             INT32_MIN,             INT32_MAX } },
    { { -INT32_C(  1520164690),  INT32_C(  1403295604) },
         INT32_C(           1),
      {             INT32_MIN,             INT32_MAX } },
    { {  INT32_C(   334195012),  INT32_C(  1395495779) },
         INT32_C(          25),
      {             INT32_MAX,             INT32_MAX } },
    { { -INT32_C(   546807629), -INT32_C(  1654755203) },
         INT32_C(          27),
      {             INT32_MIN,             INT32_MIN } },
    { { -INT32_C(  2111406087), -INT32_C(   945040322) },
         INT32_C(           2),
      {             INT32_MIN,             INT32_MIN } },
    { {  INT32_C(   698760047),  INT32_C(  1029414862) },
         INT32_C(           4),
      {             INT32_MAX,             INT32_MAX } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x2_t a = simde_vld1_s32(test_vec[i].a);
    int32_t n = test_vec[i].n;
    simde_int32x2_t r;
    SIMDE_CONSTIFY_32_(simde_vqshl_n_s32, r, (HEDLEY_UNREACHABLE(), r), n, a);

    simde_test_arm_neon_assert_equal_i32x2(r, simde_vld1_s32(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vqshl_n_s64 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    int64_t a[1];
    int64_t n;
    int64_t r[1];
  } test_vec[] = {
    { {  INT64_C(  317419771032513583) },
         INT64_C(                  18),
      {                     INT64_MAX } },
    { { -INT64_C(  222543486516657844) },
         INT64_C(                  52),
      {                     INT64_MIN } },
    { {  INT64_C( 4878483773718223654) },
         INT64_C(                  41),
      {                     INT64_MAX } },
    { { -INT64_C( 1366810703334118649) },
         INT64_C(                  58),
      {                     INT64_MIN } },
    { {  INT64_C( 8647965643940482670) },
         INT64_C(                  56),
      {                     INT64_MAX } },
    { {  INT64_C( 5183741275295133239) },
         INT64_C(                   3),
      {                     INT64_MAX } },
    { { -INT64_C( 4131520758077874604) },
         INT64_C(                  53),
      {                     INT64_MIN } },
    { {  INT64_C( 1919316409459330283) },
         INT64_C(                   1),
      {  INT64_C( 3838632818918660566) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int64x1_t a = simde_vld1_s64(test_vec[i].a);
    int64_t n = test_vec[i].n;
    simde_int64x1_t r;
    SIMDE_CONSTIFY_64_(simde_vqshl_n_s64, r, (HEDLEY_UNREACHABLE(), r), n, a);

    simde_test_arm_neon_assert_equal_i64x1(r, simde_vld1_s64(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vqshl_n_u8 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    uint8_t a[8];
    int8_t n;
    uint8_t r[8];
  } test_vec[] = {
    { {  UINT8_C(  146),  UINT8_C(  209),  UINT8_C(    5),  UINT8_C(   55),
         UINT8_C(  228),  UINT8_C(  113),  UINT8_C(   10),  UINT8_C(   75) },
         INT8_C(    0),
      {  UINT8_C(  146),  UINT8_C(  209),  UINT8_C(    5),  UINT8_C(   55),
         UINT8_C(  228),  UINT8_C(  113),  UINT8_C(   10),  UINT8_C(   75) } },
    { {  UINT8_C(    8),  UINT8_C(  125),  UINT8_C(   50),  UINT8_C(   60),
         UINT8_C(  168),  UINT8_C(  192),  UINT8_C(  133),  UINT8_C(  210) },
         INT8_C(    5),
      {      UINT8_MAX,      UINT8_MAX,      UINT8_MAX,      UINT8_MAX,
             UINT8_MAX,      UINT8_MAX,      UINT8_MAX,      UINT8_MAX } },
    { {  UINT8_C(   47),  UINT8_C(  234),  UINT8_C(  171),  UINT8_C(   41),
         UINT8_C(  212),  UINT8_C(  203),  UINT8_C(  184),  UINT8_C(    9) },
         INT8_C(    3),
      {      UINT8_MAX,      UINT8_MAX,      UINT8_MAX,      UINT8_MAX,
             UINT8_MAX,      UINT8_MAX,      UINT8_MAX,  UINT8_C(   72) } },
    { {  UINT8_C(  123),  UINT8_C(   74),  UINT8_C(   23),  UINT8_C(  204),
         UINT8_C(   97),  UINT8_C(   84),  UINT8_C(  249),  UINT8_C(   45) },
         INT8_C(    2),
      {      UINT8_MAX,      UINT8_MAX,  UINT8_C(   92),      UINT8_MAX,
             UINT8_MAX,      UINT8_MAX,      UINT8_MAX,  UINT8_C(  180) } },
    { {  UINT8_C(  141),  UINT8_C(  216),  UINT8_C(  188),  UINT8_C(   30),
         UINT8_C(  231),  UINT8_C(   14),  UINT8_C(  129),  UINT8_C(  227) },
         INT8_C(    2),
      {      UINT8_MAX,      UINT8_MAX,      UINT8_MAX,  UINT8_C(  120),
             UINT8_MAX,  UINT8_C(   56),      UINT8_MAX,      UINT8_MAX } },
    { {  UINT8_C(  221),  UINT8_C(    8),  UINT8_C(   50),  UINT8_C(  126),
         UINT8_C(   44),  UINT8_C(  181),  UINT8_C(  112),  UINT8_C(  221) },
         INT8_C(    1),
      {      UINT8_MAX,  UINT8_C(   16),  UINT8_C(  100),  UINT8_C(  252),
         UINT8_C(   88),      UINT8_MAX,  UINT8_C(  224),      UINT8_MAX } },
    { {  UINT8_C(  135),  UINT8_C(  224),  UINT8_C(   43),  UINT8_C(  156),
         UINT8_C(  223),  UINT8_C(   65),  UINT8_C(   24),  UINT8_C(  124) },
         INT8_C(    3),
      {      UINT8_MAX,      UINT8_MAX,      UINT8_MAX,      UINT8_MAX,
             UINT8_MAX,      UINT8_MAX,  UINT8_C(  192),      UINT8_MAX } },
    { {  UINT8_C(  160),  UINT8_C(   69),  UINT8_C(   70),  UINT8_C(    3),
         UINT8_C(   34),  UINT8_C(  141),  UINT8_C(  170),  UINT8_C(  146) },
         INT8_C(    2),
      {      UINT8_MAX,      UINT8_MAX,      UINT8_MAX,  UINT8_C(   12),
         UINT8_C(  136),      UINT8_MAX,      UINT8_MAX,      UINT8_MAX } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint8x8_t a = simde_vld1_u8(test_vec[i].a);
    int8_t n = test_vec[i].n;
    simde_uint8x8_t r;
    SIMDE_CONSTIFY_8_(simde_vqshl_n_u8, r, (HEDLEY_UNREACHABLE(), r), n, a);

    simde_test_arm_neon_assert_equal_u8x8(r, simde_vld1_u8(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vqshl_n_u16 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    uint16_t a[4];
    int16_t n;
    uint16_t r[4];
  } test_vec[] = {
    { {  UINT16_C(23557),  UINT16_C(62573),  UINT16_C(56816),  UINT16_C(33942) },
         INT16_C(    0),
      {  UINT16_C(23557),  UINT16_C(62573),  UINT16_C(56816),  UINT16_C(33942) } },
    { {  UINT16_C(16407),  UINT16_C(21374),  UINT16_C(  769),  UINT16_C(30772) },
         INT16_C(    6),
      {     UINT16_MAX,     UINT16_MAX,  UINT16_C(49216),     UINT16_MAX } },
    { {  UINT16_C(59806),  UINT16_C( 6417),  UINT16_C(55258),  UINT16_C(55600) },
         INT16_C(   11),
      {     UINT16_MAX,     UINT16_MAX,     UINT16_MAX,     UINT16_MAX } },
    { {  UINT16_C(42142),  UINT16_C(38610),  UINT16_C(40324),  UINT16_C(26101) },
         INT16_C(   15),
      {     UINT16_MAX,     UINT16_MAX,     UINT16_MAX,     UINT16_MAX } },
    { {  UINT16_C(11943),  UINT16_C(59523),  UINT16_C(33503),  UINT16_C(21075) },
         INT16_C(   13),
      {     UINT16_MAX,     UINT16_MAX,     UINT16_MAX,     UINT16_MAX } },
    { {  UINT16_C(50967),  UINT16_C( 2200),  UINT16_C(35906),  UINT16_C(34630) },
         INT16_C(   14),
      {     UINT16_MAX,     UINT16_MAX,     UINT16_MAX,     UINT16_MAX } },
    { {  UINT16_C(10546),  UINT16_C(48207),  UINT16_C(52042),  UINT16_C(37855) },
         INT16_C(   12),
      {     UINT16_MAX,     UINT16_MAX,     UINT16_MAX,     UINT16_MAX } },
    { {  UINT16_C(29483),  UINT16_C(43989),  UINT16_C(56132),  UINT16_C(31170) },
         INT16_C(    2),
      {     UINT16_MAX,     UINT16_MAX,     UINT16_MAX,     UINT16_MAX } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint16x4_t a = simde_vld1_u16(test_vec[i].a);
    int16_t n = test_vec[i].n;
    simde_uint16x4_t r;
    SIMDE_CONSTIFY_16_(simde_vqshl_n_u16, r, (HEDLEY_UNREACHABLE(), r), n, a);

    simde_test_arm_neon_assert_equal_u16x4(r, simde_vld1_u16(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vqshl_n_u32 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    uint32_t a[2];
    int32_t n;
    uint32_t r[2];
  } test_vec[] = {
    { {  UINT32_C(  3837263964),  UINT32_C(  4037083674) },
         INT32_C(           2),
      {            UINT32_MAX,            UINT32_MAX } },
    { {  UINT32_C(   827273341),  UINT32_C(  1695249226) },
         INT32_C(          11),
      {            UINT32_MAX,            UINT32_MAX } },
    { {  UINT32_C(  3696103338),  UINT32_C(  1664182853) },
         INT32_C(           6),
      {            UINT32_MAX,            UINT32_MAX } },
    { {  UINT32_C(  2503106558),  UINT32_C(  3522453693) },
         INT32_C(           7),
      {            UINT32_MAX,            UINT32_MAX } },
    { {  UINT32_C(  1922781787),  UINT32_C(  1012930042) },
         INT32_C(          24),
      {            UINT32_MAX,            UINT32_MAX } },
    { {  UINT32_C(  3662817880),  UINT32_C(  1393521286) },
         INT32_C(          28),
      {            UINT32_MAX,            UINT32_MAX } },
    { {  UINT32_C(   406630999),  UINT32_C(  2068454351) },
         INT32_C(           3),
      {  UINT32_C(  3253047992),            UINT32_MAX } },
    { {  UINT32_C(  2431908342),  UINT32_C(  1900918880) },
         INT32_C(           0),
      {  UINT32_C(  2431908342),  UINT32_C(  1900918880) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint32x2_t a = simde_vld1_u32(test_vec[i].a);
    int32_t n = test_vec[i].n;
    simde_uint32x2_t r;
    SIMDE_CONSTIFY_32_(simde_vqshl_n_u32, r, (HEDLEY_UNREACHABLE(), r), n, a);

    simde_test_arm_neon_assert_equal_u32x2(r, simde_vld1_u32(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vqshl_n_u64 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    uint64_t a[1];
    int64_t n;
    uint64_t r[1];
  } test_vec[] = {
    { {  UINT64_C(14791235225441363636) },
         INT64_C(                  15),
      {                    UINT64_MAX } },
    { {  UINT64_C( 6444339481039961058) },
         INT64_C(                  33),
      {                    UINT64_MAX } },
    { {  UINT64_C(  165573460250930159) },
         INT64_C(                  19),
      {                    UINT64_MAX } },
    { {  UINT64_C( 1670120376566874410) },
         INT64_C(                  13),
      {                    UINT64_MAX } },
    { {  UINT64_C( 8676255852403586864) },
         INT64_C(                   2),
      {                    UINT64_MAX } },
    { {  UINT64_C( 3980418442267725771) },
         INT64_C(                  55),
      {                    UINT64_MAX } },
    { {  UINT64_C(13746015185500539990) },
         INT64_C(                  47),
      {                    UINT64_MAX } },
    { {  UINT64_C( 5376833857251923407) },
         INT64_C(                  38),
      {                    UINT64_MAX } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint64x1_t a = simde_vld1_u64(test_vec[i].a);
    int64_t n = test_vec[i].n;
    simde_uint64x1_t r;
    SIMDE_CONSTIFY_64_(simde_vqshl_n_u64, r, (HEDLEY_UNREACHABLE(), r), n, a);

    simde_test_arm_neon_assert_equal_u64x1(r, simde_vld1_u64(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vqshlq_n_s8 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    int8_t a[16];
    int8_t n;
    int8_t r[16];
  } test_vec[] = {
    { {       INT8_MAX,  INT8_C(   68),  INT8_C(   19), -INT8_C(   19),
         INT8_C(  112), -INT8_C(   21), -INT8_C(    7), -INT8_C(   32),
        -INT8_C(  115), -INT8_C(   57),  INT8_C(    3),  INT8_C(   93),
        -INT8_C(   16), -INT8_C(   46), -INT8_C(   12), -INT8_C(   51) },
         INT8_C(    5),
      {       INT8_MAX,       INT8_MAX,       INT8_MAX,       INT8_MIN,
              INT8_MAX,       INT8_MIN,       INT8_MIN,       INT8_MIN,
              INT8_MIN,       INT8_MIN,  INT8_C(   96),       INT8_MAX,
              INT8_MIN,       INT8_MIN,       INT8_MIN,       INT8_MIN } },
    { {  INT8_C(   75),  INT8_C(   41), -INT8_C(   49), -INT8_C(    3),
        -INT8_C(   26), -INT8_C(   18), -INT8_C(   72),  INT8_C(  123),
        -INT8_C(  111),  INT8_C(   52), -INT8_C(    1),  INT8_C(  125),
        -INT8_C(   94), -INT8_C(  127), -INT8_C(   67),  INT8_C(   70) },
         INT8_C(    4),
      {       INT8_MAX,       INT8_MAX,       INT8_MIN, -INT8_C(   48),
              INT8_MIN,       INT8_MIN,       INT8_MIN,       INT8_MAX,
              INT8_MIN,       INT8_MAX, -INT8_C(   16),       INT8_MAX,
              INT8_MIN,       INT8_MIN,       INT8_MIN,       INT8_MAX } },
    { { -INT8_C(    7),  INT8_C(   17),  INT8_C(   62), -INT8_C(   33),
        -INT8_C(    7),  INT8_C(   54), -INT8_C(   34),  INT8_C(  126),
         INT8_C(   44),  INT8_C(   36),  INT8_C(  112),  INT8_C(   21),
        -INT8_C(   65), -INT8_C(  103), -INT8_C(   42), -INT8_C(   73) },
         INT8_C(    3),
      { -INT8_C(   56),       INT8_MAX,       INT8_MAX,       INT8_MIN,
        -INT8_C(   56),       INT8_MAX,       INT8_MIN,       INT8_MAX,
              INT8_MAX,       INT8_MAX,       INT8_MAX,       INT8_MAX,
              INT8_MIN,       INT8_MIN,       INT8_MIN,       INT8_MIN } },
    { {  INT8_C(   45), -INT8_C(  127), -INT8_C(  113),  INT8_C(   84),
         INT8_C(    2), -INT8_C(  111), -INT8_C(  122),  INT8_C(   92),
        -INT8_C(  123), -INT8_C(  117), -INT8_C(   67), -INT8_C(   30),
        -INT8_C(    7),  INT8_C(   18), -INT8_C(   74), -INT8_C(   20) },
         INT8_C(    2),
      {       INT8_MAX,       INT8_MIN,       INT8_MIN,       INT8_MAX,
         INT8_C(    8),       INT8_MIN,       INT8_MIN,       INT8_MAX,
              INT8_MIN,       INT8_MIN,       INT8_MIN, -INT8_C(  120),
        -INT8_C(   28),  INT8_C(   72),       INT8_MIN, -INT8_C(   80) } },
    { {  INT8_C(  109),  INT8_C(   46),  INT8_C(   12),  INT8_C(   78),
         INT8_C(   18),  INT8_C(    3),  INT8_C(   80),  INT8_C(    7),
        -INT8_C(   55), -INT8_C(   56),  INT8_C(    4), -INT8_C(   63),
         INT8_C(  114), -INT8_C(   82), -INT8_C(   66),  INT8_C(  119) },
         INT8_C(    5),
      {       INT8_MAX,       INT8_MAX,       INT8_MAX,       INT8_MAX,
              INT8_MAX,  INT8_C(   96),       INT8_MAX,       INT8_MAX,
              INT8_MIN,       INT8_MIN,       INT8_MAX,       INT8_MIN,
              INT8_MAX,       INT8_MIN,       INT8_MIN,       INT8_MAX } },
    { {  INT8_C(   35), -INT8_C(  115), -INT8_C(   60), -INT8_C(  100),
         INT8_C(   55), -INT8_C(   23),  INT8_C(   40),  INT8_C(   84),
        -INT8_C(  104),  INT8_C(    3), -INT8_C(   91),  INT8_C(  109),
        -INT8_C(  120),  INT8_C(   98), -INT8_C(  110),  INT8_C(   34) },
         INT8_C(    3),
      {       INT8_MAX,       INT8_MIN,       INT8_MIN,       INT8_MIN,
              INT8_MAX,       INT8_MIN,       INT8_MAX,       INT8_MAX,
              INT8_MIN,  INT8_C(   24),       INT8_MIN,       INT8_MAX,
              INT8_MIN,       INT8_MAX,       INT8_MIN,       INT8_MAX } },
    { {  INT8_C(  103), -INT8_C(   47),  INT8_C(   52), -INT8_C(  121),
        -INT8_C(   67), -INT8_C(   59), -INT8_C(   28), -INT8_C(   29),
         INT8_C(    2),  INT8_C(   21),  INT8_C(   21), -INT8_C(   43),
        -INT8_C(   60),  INT8_C(   31), -INT8_C(   34),  INT8_C(  113) },
         INT8_C(    1),
      {       INT8_MAX, -INT8_C(   94),  INT8_C(  104),       INT8_MIN,
              INT8_MIN, -INT8_C(  118), -INT8_C(   56), -INT8_C(   58),
         INT8_C(    4),  INT8_C(   42),  INT8_C(   42), -INT8_C(   86),
        -INT8_C(  120),  INT8_C(   62), -INT8_C(   68),       INT8_MAX } },
    { { -INT8_C(   79),  INT8_C(   78),  INT8_C(   39),  INT8_C(   89),
        -INT8_C(   89), -INT8_C(  100),  INT8_C(  115), -INT8_C(   48),
        -INT8_C(   33), -INT8_C(  101), -INT8_C(   53),  INT8_C(   88),
        -INT8_C(   81),  INT8_C(   27), -INT8_C(   18),  INT8_C(   19) },
         INT8_C(    6),
      {       INT8_MIN,       INT8_MAX,       INT8_MAX,       INT8_MAX,
              INT8_MIN,       INT8_MIN,       INT8_MAX,       INT8_MIN,
              INT8_MIN,       INT8_MIN,       INT8_MIN,       INT8_MAX,
              INT8_MIN,       INT8_MAX,       INT8_MIN,       INT8_MAX } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int8x16_t a = simde_vld1q_s8(test_vec[i].a);
    int8_t n = test_vec[i].n;
    simde_int8x16_t r;
    SIMDE_CONSTIFY_8_(simde_vqshlq_n_s8, r, (HEDLEY_UNREACHABLE(), r), n, a);

    simde_test_arm_neon_assert_equal_i8x16(r, simde_vld1q_s8(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vqshlq_n_s16 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    int16_t a[8];
    int16_t n;
    int16_t r[8];
  } test_vec[] = {
    { {  INT16_C(  11402), -INT16_C(  20682), -INT16_C(  13768),  INT16_C(  31974),
        -INT16_C(   6132), -INT16_C(  21000),  INT16_C(   8430), -INT16_C(  10986) },
         INT16_C(      4),
      {        INT16_MAX,        INT16_MIN,        INT16_MIN,        INT16_MAX,
               INT16_MIN,        INT16_MIN,        INT16_MAX,        INT16_MIN } },
    { { -INT16_C(  24232),  INT16_C(  13117), -INT16_C(  17819), -INT16_C(  14174),
         INT16_C(  26072), -INT16_C(  32178), -INT16_C(  11710),  INT16_C(  21944) },
         INT16_C(      7),
      {        INT16_MIN,        INT16_MAX,        INT16_MIN,        INT16_MIN,
               INT16_MAX,        INT16_MIN,        INT16_MIN,        INT16_MAX } },
    { {  INT16_C(   7021), -INT16_C(  21234),  INT16_C(   5328), -INT16_C(  28727),
         INT16_C(  14164), -INT16_C(  27093), -INT16_C(  17534),  INT16_C(   2033) },
         INT16_C(     12),
      {        INT16_MAX,        INT16_MIN,        INT16_MAX,        INT16_MIN,
               INT16_MAX,        INT16_MIN,        INT16_MIN,        INT16_MAX } },
    { { -INT16_C(  30558), -INT16_C(  31585),  INT16_C(  22733), -INT16_C(  28634),
         INT16_C(  15106), -INT16_C(  14901), -INT16_C(  18342),  INT16_C(  10197) },
         INT16_C(      2),
      {        INT16_MIN,        INT16_MIN,        INT16_MAX,        INT16_MIN,
               INT16_MAX,        INT16_MIN,        INT16_MIN,        INT16_MAX } },
    { { -INT16_C(  18543),  INT16_C(  14497), -INT16_C(   1780),  INT16_C(  13368),
         INT16_C(  32003),  INT16_C(  13327), -INT16_C(  21518), -INT16_C(   7936) },
         INT16_C(     13),
      {        INT16_MIN,        INT16_MAX,        INT16_MIN,        INT16_MAX,
               INT16_MAX,        INT16_MAX,        INT16_MIN,        INT16_MIN } },
    { {  INT16_C(    155), -INT16_C(  13819), -INT16_C(  26598), -INT16_C(  19722),
         INT16_C(  19524), -INT16_C(  18703), -INT16_C(  30213), -INT16_C(  29351) },
         INT16_C(      2),
      {  INT16_C(    620),        INT16_MIN,        INT16_MIN,        INT16_MIN,
               INT16_MAX,        INT16_MIN,        INT16_MIN,        INT16_MIN } },
    { { -INT16_C(  20411),  INT16_C(  30376), -INT16_C(  17575),  INT16_C(  15232),
         INT16_C(  16824), -INT16_C(  25087), -INT16_C(  28836),  INT16_C(  29871) },
         INT16_C(     14),
      {        INT16_MIN,        INT16_MAX,        INT16_MIN,        INT16_MAX,
               INT16_MAX,        INT16_MIN,        INT16_MIN,        INT16_MAX } },
    { {  INT16_C(  14794), -INT16_C(  27275), -INT16_C(  22632), -INT16_C(   5225),
        -INT16_C(  11754), -INT16_C(  17095),  INT16_C(   9679), -INT16_C(  29724) },
         INT16_C(      2),
      {        INT16_MAX,        INT16_MIN,        INT16_MIN, -INT16_C(  20900),
               INT16_MIN,        INT16_MIN,        INT16_MAX,        INT16_MIN } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x8_t a = simde_vld1q_s16(test_vec[i].a);
    int16_t n = test_vec[i].n;
    simde_int16x8_t r;
    SIMDE_CONSTIFY_16_(simde_vqshlq_n_s16, r, (HEDLEY_UNREACHABLE(), r), n, a);

    simde_test_arm_neon_assert_equal_i16x8(r, simde_vld1q_s16(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vqshlq_n_s32 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    int32_t a[4];
    int32_t n;
    int32_t r[4];
  } test_vec[] = {
    { {  INT32_C(  1074729899), -INT32_C(   350055315), -INT32_C(   594235603), -INT32_C(  2026764391) },
         INT32_C(          21),
      {             INT32_MAX,             INT32_MIN,             INT32_MIN,             INT32_MIN } },
    { { -INT32_C(  1545159008),  INT32_C(  1350275068),  INT32_C(  1650390489), -INT32_C(  1738000333) },
         INT32_C(          16),
      {             INT32_MIN,             INT32_MAX,             INT32_MAX,             INT32_MIN } },
    { { -INT32_C(   494308548),  INT32_C(   694414272),  INT32_C(  1701559315),  INT32_C(   611372704) },
         INT32_C(          14),
      {             INT32_MIN,             INT32_MAX,             INT32_MAX,             INT32_MAX } },
    { { -INT32_C(  2137731107),  INT32_C(   914115316), -INT32_C(   540329282),  INT32_C(  2086573817) },
         INT32_C(           8),
      {             INT32_MIN,             INT32_MAX,             INT32_MIN,             INT32_MAX } },
    { { -INT32_C(  1951684747),  INT32_C(  1204536179),  INT32_C(   922714634), -INT32_C(  1800556517) },
         INT32_C(          15),
      {             INT32_MIN,             INT32_MAX,             INT32_MAX,             INT32_MIN } },
    { {  INT32_C(   945136202), -INT32_C(   472613203),  INT32_C(  1912776620), -INT32_C(   164578039) },
         INT32_C(           0),
      {  INT32_C(   945136202), -INT32_C(   472613203),  INT32_C(  1912776620), -INT32_C(   164578039) } },
    { {  INT32_C(   750743177), -INT32_C(  1595705273), -INT32_C(   774986565),  INT32_C(  1814824482) },
         INT32_C(           2),
      {             INT32_MAX,             INT32_MIN,             INT32_MIN,             INT32_MAX } },
    { { -INT32_C(   484591267), -INT32_C(  1792996225),  INT32_C(  1020785704), -INT32_C(  2059266172) },
         INT32_C(           6),
      {             INT32_MIN,             INT32_MIN,             INT32_MAX,             INT32_MIN } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x4_t a = simde_vld1q_s32(test_vec[i].a);
    int32_t n = test_vec[i].n;
    simde_int32x4_t r;
    SIMDE_CONSTIFY_32_(simde_vqshlq_n_s32, r, (HEDLEY_UNREACHABLE(), r), n, a);

    simde_test_arm_neon_assert_equal_i32x4(r, simde_vld1q_s32(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vqshlq_n_s64 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    int64_t a[2];
    int64_t n;
    int64_t r[2];
  } test_vec[] = {
    { { -INT64_C( 4042258481157755441), -INT64_C( 5433841412613238413) },
         INT64_C(                  59),
      {                     INT64_MIN,                     INT64_MIN } },
    { { -INT64_C( 2646123060523157640),  INT64_C( 3641907379906915618) },
         INT64_C(                   9),
      {                     INT64_MIN,                     INT64_MAX } },
    { {  INT64_C( 2503202682359869433),  INT64_C( 1978542443908903786) },
         INT64_C(                  11),
      {                     INT64_MAX,                     INT64_MAX } },
    { { -INT64_C( 7077121127573266665), -INT64_C( 7559225274706753147) },
         INT64_C(                  40),
      {                     INT64_MIN,                     INT64_MIN } },
    { {  INT64_C( 2763049935594417468),  INT64_C( 9127028968420169616) },
         INT64_C(                  47),
      {                     INT64_MAX,                     INT64_MAX } },
    { {  INT64_C( 5001850119325242351),  INT64_C( 3813836005973833327) },
         INT64_C(                  25),
      {                     INT64_MAX,                     INT64_MAX } },
    { {  INT64_C( 8591594818391808077),  INT64_C( 4108322868374008343) },
         INT64_C(                  45),
      {                     INT64_MAX,                     INT64_MAX } },
    { { -INT64_C( 4504095822229056778),  INT64_C( 6849365327622501025) },
         INT64_C(                   5),
      {                     INT64_MIN,                     INT64_MAX } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int64x2_t a = simde_vld1q_s64(test_vec[i].a);
    int64_t n = test_vec[i].n;
    simde_int64x2_t r;
    SIMDE_CONSTIFY_64_(simde_vqshlq_n_s64, r, (HEDLEY_UNREACHABLE(), r), n, a);

    simde_test_arm_neon_assert_equal_i64x2(r, simde_vld1q_s64(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vqshlq_n_u8 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    uint8_t a[16];
    int8_t n;
    uint8_t r[16];
  } test_vec[] = {
    { {  UINT8_C(  186),  UINT8_C(  109),  UINT8_C(   81),  UINT8_C(  134),
         UINT8_C(  246),  UINT8_C(  134),  UINT8_C(  185),  UINT8_C(  141),
         UINT8_C(   53),  UINT8_C(  217),  UINT8_C(    4),  UINT8_C(  118),
         UINT8_C(   66),  UINT8_C(   45),  UINT8_C(   17),  UINT8_C(   65) },
         INT8_C(    0),
      {  UINT8_C(  186),  UINT8_C(  109),  UINT8_C(   81),  UINT8_C(  134),
         UINT8_C(  246),  UINT8_C(  134),  UINT8_C(  185),  UINT8_C(  141),
         UINT8_C(   53),  UINT8_C(  217),  UINT8_C(    4),  UINT8_C(  118),
         UINT8_C(   66),  UINT8_C(   45),  UINT8_C(   17),  UINT8_C(   65) } },
    { {  UINT8_C(  132),  UINT8_C(   39),  UINT8_C(   54),  UINT8_C(   85),
         UINT8_C(  113),  UINT8_C(  202),  UINT8_C(  126),  UINT8_C(  234),
         UINT8_C(   66),  UINT8_C(  109),  UINT8_C(   75),  UINT8_C(  160),
         UINT8_C(   23),  UINT8_C(  174),  UINT8_C(  144),  UINT8_C(  169) },
         INT8_C(    4),
      {      UINT8_MAX,      UINT8_MAX,      UINT8_MAX,      UINT8_MAX,
             UINT8_MAX,      UINT8_MAX,      UINT8_MAX,      UINT8_MAX,
             UINT8_MAX,      UINT8_MAX,      UINT8_MAX,      UINT8_MAX,
             UINT8_MAX,      UINT8_MAX,      UINT8_MAX,      UINT8_MAX } },
    { {  UINT8_C(  107),  UINT8_C(  195),  UINT8_C(    7),  UINT8_C(  117),
         UINT8_C(    8),  UINT8_C(  215),  UINT8_C(   35),  UINT8_C(   11),
         UINT8_C(   23),  UINT8_C(  194),  UINT8_C(  151),  UINT8_C(   21),
         UINT8_C(  181),  UINT8_C(  123),  UINT8_C(  222),  UINT8_C(  212) },
         INT8_C(    7),
      {      UINT8_MAX,      UINT8_MAX,      UINT8_MAX,      UINT8_MAX,
             UINT8_MAX,      UINT8_MAX,      UINT8_MAX,      UINT8_MAX,
             UINT8_MAX,      UINT8_MAX,      UINT8_MAX,      UINT8_MAX,
             UINT8_MAX,      UINT8_MAX,      UINT8_MAX,      UINT8_MAX } },
    { {  UINT8_C(   58),  UINT8_C(  168),  UINT8_C(  225),  UINT8_C(  204),
         UINT8_C(  148),  UINT8_C(   52),  UINT8_C(  237),  UINT8_C(  118),
         UINT8_C(   62),  UINT8_C(  154),      UINT8_MAX,  UINT8_C(  103),
         UINT8_C(   31),  UINT8_C(  152),  UINT8_C(   61),  UINT8_C(  177) },
         INT8_C(    6),
      {      UINT8_MAX,      UINT8_MAX,      UINT8_MAX,      UINT8_MAX,
             UINT8_MAX,      UINT8_MAX,      UINT8_MAX,      UINT8_MAX,
             UINT8_MAX,      UINT8_MAX,      UINT8_MAX,      UINT8_MAX,
             UINT8_MAX,      UINT8_MAX,      UINT8_MAX,      UINT8_MAX } },
    { {  UINT8_C(  117),  UINT8_C(    3),  UINT8_C(    6),  UINT8_C(  170),
         UINT8_C(  220),  UINT8_C(  137),  UINT8_C(  137),  UINT8_C(  114),
         UINT8_C(  139),  UINT8_C(  224),  UINT8_C(  117),  UINT8_C(   34),
         UINT8_C(  126),  UINT8_C(  143),  UINT8_C(   47),  UINT8_C(  245) },
         INT8_C(    5),
      {      UINT8_MAX,  UINT8_C(   96),  UINT8_C(  192),      UINT8_MAX,
             UINT8_MAX,      UINT8_MAX,      UINT8_MAX,      UINT8_MAX,
             UINT8_MAX,      UINT8_MAX,      UINT8_MAX,      UINT8_MAX,
             UINT8_MAX,      UINT8_MAX,      UINT8_MAX,      UINT8_MAX } },
    { {  UINT8_C(  100),  UINT8_C(  121),  UINT8_C(  133),  UINT8_C(  168),
         UINT8_C(  236),  UINT8_C(  205),  UINT8_C(  116),  UINT8_C(  163),
         UINT8_C(  147),  UINT8_C(  117),  UINT8_C(   41),  UINT8_C(  166),
         UINT8_C(  170),  UINT8_C(   76),  UINT8_C(  212),  UINT8_C(   62) },
         INT8_C(    7),
      {      UINT8_MAX,      UINT8_MAX,      UINT8_MAX,      UINT8_MAX,
             UINT8_MAX,      UINT8_MAX,      UINT8_MAX,      UINT8_MAX,
             UINT8_MAX,      UINT8_MAX,      UINT8_MAX,      UINT8_MAX,
             UINT8_MAX,      UINT8_MAX,      UINT8_MAX,      UINT8_MAX } },
    { {  UINT8_C(  193),  UINT8_C(   91),  UINT8_C(  159),  UINT8_C(  251),
         UINT8_C(   51),  UINT8_C(  137),  UINT8_C(   73),  UINT8_C(  100),
         UINT8_C(   86),  UINT8_C(  110),  UINT8_C(    7),  UINT8_C(  116),
         UINT8_C(   62),  UINT8_C(  173),  UINT8_C(  209),  UINT8_C(  170) },
         INT8_C(    6),
      {      UINT8_MAX,      UINT8_MAX,      UINT8_MAX,      UINT8_MAX,
             UINT8_MAX,      UINT8_MAX,      UINT8_MAX,      UINT8_MAX,
             UINT8_MAX,      UINT8_MAX,      UINT8_MAX,      UINT8_MAX,
             UINT8_MAX,      UINT8_MAX,      UINT8_MAX,      UINT8_MAX } },
    { {  UINT8_C(  223),  UINT8_C(  187),  UINT8_C(   86),  UINT8_C(   89),
         UINT8_C(  188),  UINT8_C(  139),  UINT8_C(   84),  UINT8_C(   48),
         UINT8_C(  199),  UINT8_C(   56),  UINT8_C(  174),  UINT8_C(  180),
         UINT8_C(  121),  UINT8_C(  197),  UINT8_C(  124),  UINT8_C(  123) },
         INT8_C(    5),
      {      UINT8_MAX,      UINT8_MAX,      UINT8_MAX,      UINT8_MAX,
             UINT8_MAX,      UINT8_MAX,      UINT8_MAX,      UINT8_MAX,
             UINT8_MAX,      UINT8_MAX,      UINT8_MAX,      UINT8_MAX,
             UINT8_MAX,      UINT8_MAX,      UINT8_MAX,      UINT8_MAX } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint8x16_t a = simde_vld1q_u8(test_vec[i].a);
    int8_t n = test_vec[i].n;
    simde_uint8x16_t r;
    SIMDE_CONSTIFY_8_(simde_vqshlq_n_u8, r, (HEDLEY_UNREACHABLE(), r), n, a);

    simde_test_arm_neon_assert_equal_u8x16(r, simde_vld1q_u8(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vqshlq_n_u16 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    uint16_t a[8];
    int16_t n;
    uint16_t r[8];
  } test_vec[] = {
    { {  UINT16_C(20921),  UINT16_C(44565),  UINT16_C(48346),  UINT16_C(18082),
         UINT16_C(31795),  UINT16_C(38471),  UINT16_C(  261),  UINT16_C( 9990) },
         INT16_C(   10),
      {     UINT16_MAX,     UINT16_MAX,     UINT16_MAX,     UINT16_MAX,
            UINT16_MAX,     UINT16_MAX,     UINT16_MAX,     UINT16_MAX } },
    { {  UINT16_C(19165),  UINT16_C(14129),  UINT16_C(23876),  UINT16_C(44179),
         UINT16_C(14014),  UINT16_C(45088),  UINT16_C(35405),  UINT16_C(21342) },
         INT16_C(    1),
      {  UINT16_C(38330),  UINT16_C(28258),  UINT16_C(47752),     UINT16_MAX,
         UINT16_C(28028),     UINT16_MAX,     UINT16_MAX,  UINT16_C(42684) } },
    { {  UINT16_C( 2818),  UINT16_C(48024),  UINT16_C(31015),  UINT16_C(28717),
         UINT16_C(39774),  UINT16_C(43608),  UINT16_C(31534),  UINT16_C(13717) },
         INT16_C(    9),
      {     UINT16_MAX,     UINT16_MAX,     UINT16_MAX,     UINT16_MAX,
            UINT16_MAX,     UINT16_MAX,     UINT16_MAX,     UINT16_MAX } },
    { {  UINT16_C(19963),  UINT16_C(59131),  UINT16_C(34949),  UINT16_C(19923),
         UINT16_C(36646),  UINT16_C( 4078),  UINT16_C(53516),  UINT16_C(24038) },
         INT16_C(    1),
      {  UINT16_C(39926),     UINT16_MAX,     UINT16_MAX,  UINT16_C(39846),
            UINT16_MAX,  UINT16_C( 8156),     UINT16_MAX,  UINT16_C(48076) } },
    { {  UINT16_C(11014),  UINT16_C( 7857),  UINT16_C(61776),  UINT16_C(20318),
         UINT16_C(15467),  UINT16_C(53633),  UINT16_C(44067),  UINT16_C(42553) },
         INT16_C(    7),
      {     UINT16_MAX,     UINT16_MAX,     UINT16_MAX,     UINT16_MAX,
            UINT16_MAX,     UINT16_MAX,     UINT16_MAX,     UINT16_MAX } },
    { {  UINT16_C(13019),  UINT16_C(19351),  UINT16_C(10797),  UINT16_C(64624),
         UINT16_C(36591),  UINT16_C(29446),  UINT16_C(42245),  UINT16_C(33465) },
         INT16_C(    6),
      {     UINT16_MAX,     UINT16_MAX,     UINT16_MAX,     UINT16_MAX,
            UINT16_MAX,     UINT16_MAX,     UINT16_MAX,     UINT16_MAX } },
    { {  UINT16_C(15341),  UINT16_C(22299),  UINT16_C(14571),  UINT16_C(29620),
         UINT16_C(54193),  UINT16_C(26425),  UINT16_C(32143),  UINT16_C( 6653) },
         INT16_C(    8),
      {     UINT16_MAX,     UINT16_MAX,     UINT16_MAX,     UINT16_MAX,
            UINT16_MAX,     UINT16_MAX,     UINT16_MAX,     UINT16_MAX } },
    { {  UINT16_C(51956),  UINT16_C(21950),  UINT16_C(38324),  UINT16_C(54094),
         UINT16_C(41677),  UINT16_C(14867),  UINT16_C(39747),  UINT16_C(55099) },
         INT16_C(    4),
      {     UINT16_MAX,     UINT16_MAX,     UINT16_MAX,     UINT16_MAX,
            UINT16_MAX,     UINT16_MAX,     UINT16_MAX,     UINT16_MAX } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint16x8_t a = simde_vld1q_u16(test_vec[i].a);
    int16_t n = test_vec[i].n;
    simde_uint16x8_t r;
    SIMDE_CONSTIFY_16_(simde_vqshlq_n_u16, r, (HEDLEY_UNREACHABLE(), r), n, a);

    simde_test_arm_neon_assert_equal_u16x8(r, simde_vld1q_u16(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vqshlq_n_u32 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    uint32_t a[4];
    int32_t n;
    uint32_t r[4];
  } test_vec[] = {
    { {  UINT32_C(    77096255),  UINT32_C(  3070792671),  UINT32_C(  2120128025),  UINT32_C(   452322529) },
         INT32_C(          30),
      {            UINT32_MAX,            UINT32_MAX,            UINT32_MAX,            UINT32_MAX } },
    { {  UINT32_C(  3510062727),  UINT32_C(  1881790280),  UINT32_C(  1143057217),  UINT32_C(  1329755098) },
         INT32_C(          11),
      {            UINT32_MAX,            UINT32_MAX,            UINT32_MAX,            UINT32_MAX } },
    { {  UINT32_C(  1998881456),  UINT32_C(  2891577961),  UINT32_C(  3965455494),  UINT32_C(  1907172378) },
         INT32_C(           5),
      {            UINT32_MAX,            UINT32_MAX,            UINT32_MAX,            UINT32_MAX } },
    { {  UINT32_C(  3960644261),  UINT32_C(  2580070008),  UINT32_C(  3811852699),  UINT32_C(  3327946214) },
         INT32_C(           5),
      {            UINT32_MAX,            UINT32_MAX,            UINT32_MAX,            UINT32_MAX } },
    { {  UINT32_C(  2229128376),  UINT32_C(  2833259986),  UINT32_C(   489617211),  UINT32_C(  2210012836) },
         INT32_C(          30),
      {            UINT32_MAX,            UINT32_MAX,            UINT32_MAX,            UINT32_MAX } },
    { {  UINT32_C(  4163257641),  UINT32_C(  3821803140),  UINT32_C(  1681327744),  UINT32_C(  3941018405) },
         INT32_C(          31),
      {            UINT32_MAX,            UINT32_MAX,            UINT32_MAX,            UINT32_MAX } },
    { {  UINT32_C(  3661383228),  UINT32_C(   325227988),  UINT32_C(  1713852693),  UINT32_C(   682566008) },
         INT32_C(          30),
      {            UINT32_MAX,            UINT32_MAX,            UINT32_MAX,            UINT32_MAX } },
    { {  UINT32_C(  2377386162),  UINT32_C(  3794665476),  UINT32_C(  2685443980),  UINT32_C(  3553657506) },
         INT32_C(          19),
      {            UINT32_MAX,            UINT32_MAX,            UINT32_MAX,            UINT32_MAX } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint32x4_t a = simde_vld1q_u32(test_vec[i].a);
    int32_t n = test_vec[i].n;
    simde_uint32x4_t r;
    SIMDE_CONSTIFY_32_(simde_vqshlq_n_u32, r, (HEDLEY_UNREACHABLE(), r), n, a);

    simde_test_arm_neon_assert_equal_u32x4(r, simde_vld1q_u32(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vqshlq_n_u64 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    uint64_t a[2];
    int64_t n;
    uint64_t r[2];
  } test_vec[] = {
    { {  UINT64_C(10322855567311411961),  UINT64_C(11440125154735590159) },
         INT64_C(                  28),
      {                    UINT64_MAX,                    UINT64_MAX } },
    { {  UINT64_C( 9512585635638000888),  UINT64_C( 4961040813524946467) },
         INT64_C(                  13),
      {                    UINT64_MAX,                    UINT64_MAX } },
    { {  UINT64_C( 2911675089381803092),  UINT64_C(17223170097124323585) },
         INT64_C(                  35),
      {                    UINT64_MAX,                    UINT64_MAX } },
    { {  UINT64_C(13241740830667826537),  UINT64_C(10243761294436612052) },
         INT64_C(                   6),
      {                    UINT64_MAX,                    UINT64_MAX } },
    { {  UINT64_C(12871405697179562635),  UINT64_C( 5888130355122776938) },
         INT64_C(                  51),
      {                    UINT64_MAX,                    UINT64_MAX } },
    { {  UINT64_C( 3754104458717627412),  UINT64_C( 1305152970539606068) },
         INT64_C(                  35),
      {                    UINT64_MAX,                    UINT64_MAX } },
    { {  UINT64_C( 9656345281810485236),  UINT64_C(12018909814426922402) },
         INT64_C(                  37),
      {                    UINT64_MAX,                    UINT64_MAX } },
    { {  UINT64_C(10478671498998178654),  UINT64_C( 9663870709090986916) },
         INT64_C(                   8),
      {                    UINT64_MAX,                    UINT64_MAX } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint64x2_t a = simde_vld1q_u64(test_vec[i].a);
    int64_t n = test_vec[i].n;
    simde_uint64x2_t r;
    SIMDE_CONSTIFY_64_(simde_vqshlq_n_u64, r, (HEDLEY_UNREACHABLE(), r), n, a);

    simde_test_arm_neon_assert_equal_u64x2(r, simde_vld1q_u64(test_vec[i].r));
  }

  return 0;
}

SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(vqshlb_n_s8)
SIMDE_TEST_FUNC_LIST_ENTRY(vqshlh_n_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vqshls_n_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vqshld_n_s64)
SIMDE_TEST_FUNC_LIST_ENTRY(vqshlb_n_u8)
SIMDE_TEST_FUNC_LIST_ENTRY(vqshlh_n_u16)
SIMDE_TEST_FUNC_LIST_ENTRY(vqshls_n_u32)
SIMDE_TEST_FUNC_LIST_ENTRY(vqshld_n_u64)

SIMDE_TEST_FUNC_LIST_ENTRY(vqshl_n_s8)
SIMDE_TEST_FUNC_LIST_ENTRY(vqshl_n_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vqshl_n_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vqshl_n_s64)
SIMDE_TEST_FUNC_LIST_ENTRY(vqshl_n_u8)
SIMDE_TEST_FUNC_LIST_ENTRY(vqshl_n_u16)
SIMDE_TEST_FUNC_LIST_ENTRY(vqshl_n_u32)
SIMDE_TEST_FUNC_LIST_ENTRY(vqshl_n_u64)

SIMDE_TEST_FUNC_LIST_ENTRY(vqshlq_n_s8)
SIMDE_TEST_FUNC_LIST_ENTRY(vqshlq_n_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vqshlq_n_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vqshlq_n_s64)
SIMDE_TEST_FUNC_LIST_ENTRY(vqshlq_n_u8)
SIMDE_TEST_FUNC_LIST_ENTRY(vqshlq_n_u16)
SIMDE_TEST_FUNC_LIST_ENTRY(vqshlq_n_u32)
SIMDE_TEST_FUNC_LIST_ENTRY(vqshlq_n_u64)
SIMDE_TEST_FUNC_LIST_END

#include "test-neon-footer.h"
