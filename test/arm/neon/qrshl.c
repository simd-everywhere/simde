#define SIMDE_TEST_ARM_NEON_INSN qrshl

#include "test-neon.h"

/* Check that both of these work */
#if defined(__cplusplus)
  #include "../../../simde/arm/neon/qrshl.h"
#else
  #include "../../../simde/arm/neon.h"
#endif

#if 0
#define PROBABILITY 80
#define probability(p) (rand() < (((int64_t) RAND_MAX * (p)) / 100))
#endif

static int
test_simde_vqrshlb_s8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int8_t a;
    int8_t b;
    int8_t r;
  } test_vec[] = {
    {    INT8_C(   50),
         INT8_C(   41),
              INT8_MAX },
    {    INT8_C(   25),
        -INT8_C(    6),
         INT8_C(    0) },
    {    INT8_C(    8),
        -INT8_C(   56),
         INT8_C(    0) },
    {   -INT8_C(  120),
         INT8_C(    7),
              INT8_MIN },
    {   -INT8_C(  116),
         INT8_C(   23),
              INT8_MIN },
    {   -INT8_C(  123),
         INT8_C(    8),
              INT8_MIN },
    {    INT8_C(   63),
        -INT8_C(   58),
         INT8_C(    0) },
    {    INT8_C(    7),
         INT8_C(    0),
         INT8_C(    7) },
    {         INT8_MAX,
        -INT8_C(    1),
         INT8_C(   64) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    int8_t r = simde_vqrshlb_s8(test_vec[i].a, test_vec[i].b);

    simde_assert_equal_i8(r, test_vec[i].r);
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int8_t a = simde_test_arm_neon_random_i8();
    simde_int8_t b = simde_test_arm_neon_random_i8();
    simde_int8_t r = simde_vqrshlb_s8(a, b);

    simde_test_arm_neon_write_i8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vqrshlh_s16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int16_t a;
    int16_t b;
    int16_t r;
  } test_vec[] = {
    {   -INT16_C(   18529),
        -INT16_C(   16129),
        -INT16_C(    9264) },
    {    INT16_C(   23969),
         INT16_C(       5),
                INT16_MAX },
    {    INT16_C(   12527),
         INT16_C(   19725),
                INT16_MAX },
    {   -INT16_C(   22762),
        -INT16_C(      16),
         INT16_C(       0) },
    {   -INT16_C(   17650),
        -INT16_C(   19012),
         INT16_C(       0) },
    {   -INT16_C(   18897),
        -INT16_C(       2),
        -INT16_C(    4724) },
    {   -INT16_C(   19983),
        -INT16_C(   27798),
                INT16_MIN },
    {    INT16_C(     329),
         INT16_C(      14),
                INT16_MAX },
    {            INT16_MAX,
        -INT16_C(       1),
         INT16_C(   16384) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    int16_t r = simde_vqrshlh_s16(test_vec[i].a, test_vec[i].b);

    simde_assert_equal_i16(r, test_vec[i].r);
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int16_t a = simde_test_arm_neon_random_i16();
    simde_int16_t b = simde_test_arm_neon_random_i16();
    simde_int16_t r = simde_vqrshlh_s16(a, b);

    simde_test_arm_neon_write_i16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vqrshls_s32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int32_t a;
    int32_t b;
    int32_t r;
  } test_vec[] = {
    {   -INT32_C(   356193628),
        -INT32_C(           6),
        -INT32_C(     5565525) },
    {   -INT32_C(  1204375858),
         INT32_C(          57),
                    INT32_MIN },
    {   -INT32_C(  1282375307),
         INT32_C(          36),
                    INT32_MIN },
    {    INT32_C(    66359825),
         INT32_C(          46),
                    INT32_MAX },
    {   -INT32_C(    79322588),
        -INT32_C(          55),
         INT32_C(           0) },
    {   -INT32_C(   930923386),
         INT32_C(           9),
                    INT32_MIN },
    {   -INT32_C(   649560211),
        -INT32_C(          27),
        -INT32_C(           5) },
    {    INT32_C(  1204135454),
         INT32_C(          63),
                    INT32_MAX },
    {  INT32_C(  1162581765),
       INT32_C(          32),
                  INT32_MAX },
    {  INT32_C(   155224493),
       INT32_C(          32),
                  INT32_MAX },
    {  INT32_C(   109880828),
       INT32_C(          32),
                  INT32_MAX },
    {  INT32_C(   882539136),
       INT32_C(          32),
                  INT32_MAX },
    { -INT32_C(    25440898),
       INT32_C(          32),
                  INT32_MIN },
    { -INT32_C(  1324715201),
       INT32_C(          32),
                  INT32_MIN },
    { -INT32_C(  2085551108),
       INT32_C(          32),
                  INT32_MIN },
    {  INT32_C(   435262094),
       INT32_C(          32),
                  INT32_MAX },
    {              INT32_MAX,
      -INT32_C(           1),
       INT32_C( 1073741824) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    int32_t r = simde_vqrshls_s32(test_vec[i].a, test_vec[i].b);

    simde_assert_equal_i32(r, test_vec[i].r);
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int32_t a = simde_test_arm_neon_random_i32();
    simde_int32_t b = simde_test_arm_neon_random_i32();
    simde_int32_t r = simde_vqrshls_s32(a, b);

    simde_test_arm_neon_write_i32(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i32(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i32(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vqrshld_s64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int64_t a;
    int64_t b;
    int64_t r;
  } test_vec[] = {
    {    INT64_C( 4843512680152437875),
         INT64_C(                  63),
                            INT64_MAX },
    {    INT64_C( 8241406571090019417),
         INT64_C(                  56),
                            INT64_MAX },
    {   -INT64_C( 7297452753530989252),
        -INT64_C(                   8),
        -INT64_C(   28505674818480427) },
    {   -INT64_C( 7093894782106403155),
         INT64_C(                  12),
                            INT64_MIN },
    {   -INT64_C( 5066332558751241991),
        -INT64_C(                  16),
        -INT64_C(      77306099834461) },
    {    INT64_C( 1160675192825562685),
         INT64_C(                  48),
                            INT64_MAX },
    {    INT64_C( 3559677482238416902),
        -INT64_C(                  17),
         INT64_C(      27158183916004) },
    {    INT64_C( 3143776020433277350),
         INT64_C(                  21),
                            INT64_MAX },
    {                        INT64_MAX,
        -INT64_C(                   1),
         INT64_C( 4611686018427387904) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    int64_t r = simde_vqrshld_s64(test_vec[i].a, test_vec[i].b);

    simde_assert_equal_i64(r, test_vec[i].r);
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int64_t a = simde_test_arm_neon_random_i64();
    simde_int64_t b = simde_test_arm_neon_random_i64();
    simde_int64_t r = simde_vqrshld_s64(a, b);

    simde_test_arm_neon_write_i64(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i64(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i64(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vqrshlb_u8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint8_t a;
    int8_t b;
    uint8_t r;
  } test_vec[] = {
    {  UINT8_C(  156),
       INT8_C(    7),
       UINT8_C(  255) },
    {  UINT8_C(  128),
      -INT8_C(    7),
       UINT8_C(    1) },
    {  UINT8_C(  191),
       INT8_C(    0),
       UINT8_C(  191) },
    {  UINT8_C(  212),
       INT8_C(    0),
       UINT8_C(  212) },
    {  UINT8_C(   45),
       INT8_C(    1),
       UINT8_C(   90) },
    {  UINT8_C(  141),
      -INT8_C(    2),
       UINT8_C(   35) },
    {  UINT8_C(    0),
      -INT8_C(    3),
       UINT8_C(    0) },
    {  UINT8_C(  147),
      -INT8_C(    8),
       UINT8_C(    1) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    uint8_t r = simde_vqrshlb_u8(test_vec[i].a, test_vec[i].b);

    simde_assert_equal_u8(r, test_vec[i].r);
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint8_t a = simde_test_arm_neon_random_u8();
    simde_int8_t b = simde_test_arm_neon_random_i8();
    simde_uint8_t r = simde_vqrshlb_u8(a, b);

    simde_test_arm_neon_write_u8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vqrshlh_u16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint16_t a;
    int16_t b;
    uint16_t r;
  } test_vec[] = {
    {  UINT16_C(    6825),
      -INT16_C(       7),
       UINT16_C(      53) },
    {  UINT16_C(   37778),
       INT16_C(       4),
       UINT16_C(   65535) },
    {  UINT16_C(    5210),
       INT16_C(      10),
       UINT16_C(   65535) },
    {  UINT16_C(   58556),
      -INT16_C(      21),
       UINT16_C(       0) },
    {  UINT16_C(   42502),
      -INT16_C(      24),
       UINT16_C(       0) },
    {  UINT16_C(   63509),
      -INT16_C(      32),
       UINT16_C(       0) },
    {  UINT16_C(   47814),
      -INT16_C(       3),
       UINT16_C(    5977) },
    {  UINT16_C(   52229),
       INT16_C(       4),
       UINT16_C(   65535) },
    {  UINT16_C(   60609),
       INT16_C(      16),
       UINT16_C(   65535) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    uint16_t r = simde_vqrshlh_u16(test_vec[i].a, test_vec[i].b);

    simde_assert_equal_u16(r, test_vec[i].r);
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint16_t a = simde_test_arm_neon_random_u16();
    simde_int16_t b = simde_test_arm_neon_random_i16();
    simde_uint16_t r = simde_vqrshlh_u16(a, b);

    simde_test_arm_neon_write_u16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vqrshls_u32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint32_t a;
    int32_t b;
    uint32_t r;
  } test_vec[] = {
    {    UINT32_C(   266226573),
         INT32_C(   376254835),
                   UINT32_MAX },
    {    UINT32_C(   627439137),
        -INT32_C(          30),
         UINT32_C(           1) },
    {    UINT32_C(  1026024828),
         INT32_C(   827959370),
                   UINT32_MAX },
    {    UINT32_C(  1847505906),
        -INT32_C(          13),
         UINT32_C(      225526) },
    {    UINT32_C(   912395655),
         INT32_C(  1671239939),
                   UINT32_MAX },
    {    UINT32_C(  2010933546),
        -INT32_C(           2),
         UINT32_C(   502733387) },
    {    UINT32_C(  2631640868),
         INT32_C(  1562231698),
         UINT32_C(           0) },
    {    UINT32_C(   468197513),
        -INT32_C(          24),
         UINT32_C(          28) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    uint32_t r = simde_vqrshls_u32(test_vec[i].a, test_vec[i].b);

    simde_assert_equal_u32(r, test_vec[i].r);
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint32_t a = simde_test_arm_neon_random_u32();
    simde_int32_t b = simde_test_arm_neon_random_i32();
    simde_uint32_t r = simde_vqrshls_u32(a, b);

    simde_test_arm_neon_write_u32(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i32(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vqrshld_u64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint64_t a;
    int64_t b;
    uint64_t r;
  } test_vec[] = {
    {    UINT64_C( 2962349988052721578),
         INT64_C( 5539606120659599506),
         UINT64_C(                   0) },
    {    UINT64_C(10064468895855897213),
         INT64_C(                  16),
                           UINT64_MAX },
    {    UINT64_C(15743453338776996870),
         INT64_C( 3803046405739062919),
         UINT64_C(                   0) },
    {    UINT64_C( 5520169503289739711),
         INT64_C(                  31),
                           UINT64_MAX },
    {    UINT64_C( 5174950593436841605),
         INT64_C( 6612268300308619863),
                           UINT64_MAX },
    {    UINT64_C(13897644625553180665),
        -INT64_C(                  12),
         UINT64_C(    3392979644910444) },
    {    UINT64_C(15140102277279441050),
        -INT64_C( 8156124063209764011),
                           UINT64_MAX },
    {    UINT64_C( 9024129550253675895),
         INT64_C(                  26),
                           UINT64_MAX },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    uint64_t r = simde_vqrshld_u64(test_vec[i].a, test_vec[i].b);

    simde_assert_equal_u64(r, test_vec[i].r);
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint64_t a = simde_test_arm_neon_random_u64();
    simde_int64_t b = simde_test_arm_neon_random_i64();
    simde_uint64_t r = simde_vqrshld_u64(a, b);

    simde_test_arm_neon_write_u64(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i64(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u64(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vqrshl_s8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    int8_t a[8];
    int8_t b[8];
    int8_t r[8];
  } test_vec[] = {
    { { -INT8_C(   87), -INT8_C(    1),  INT8_C(   80),  INT8_C(   77),
         INT8_C(   56), -INT8_C(   54),  INT8_C(  102),  INT8_C(  111) },
      {  INT8_C(    8),  INT8_C(    3), -INT8_C(    7),  INT8_C(    2),
         INT8_C(    1),  INT8_C(    7),  INT8_C(    4), -INT8_C(    7) },
      {       INT8_MIN, -INT8_C(    8),  INT8_C(    1),       INT8_MAX,
         INT8_C(  112),       INT8_MIN,       INT8_MAX,  INT8_C(    1) } },
    { {  INT8_C(   42),  INT8_C(   74), -INT8_C(  106), -INT8_C(   29),
        -INT8_C(   94), -INT8_C(   66), -INT8_C(   22),  INT8_C(   88) },
      {  INT8_C(    5),  INT8_C(    4), -INT8_C(    5),  INT8_C(    1),
        -INT8_C(    7), -INT8_C(    6), -INT8_C(    4),  INT8_C(    0) },
      {       INT8_MAX,       INT8_MAX, -INT8_C(    3), -INT8_C(   58),
        -INT8_C(    1), -INT8_C(    1), -INT8_C(    1),  INT8_C(   88) } },
    { {       INT8_MIN,  INT8_C(  100),  INT8_C(    4),  INT8_C(   14),
         INT8_C(   92),  INT8_C(   74),  INT8_C(   59), -INT8_C(   98) },
      { -INT8_C(    3),  INT8_C(    8),  INT8_C(    8),  INT8_C(    6),
         INT8_C(    5),  INT8_C(    5),  INT8_C(    5), -INT8_C(    6) },
      { -INT8_C(   16),       INT8_MAX,       INT8_MAX,       INT8_MAX,
              INT8_MAX,       INT8_MAX,       INT8_MAX, -INT8_C(    2) } },
    { {  INT8_C(   40),  INT8_C(   61),  INT8_C(   73), -INT8_C(   94),
         INT8_C(  120),  INT8_C(   65),  INT8_C(   61), -INT8_C(   71) },
      {  INT8_C(    7),  INT8_C(    1), -INT8_C(    6), -INT8_C(    8),
         INT8_C(    6), -INT8_C(    5), -INT8_C(    4), -INT8_C(    6) },
      {       INT8_MAX,  INT8_C(  122),  INT8_C(    1),  INT8_C(    0),
              INT8_MAX,  INT8_C(    2),  INT8_C(    4), -INT8_C(    1) } },
    { {  INT8_C(   32), -INT8_C(   33), -INT8_C(   42), -INT8_C(  124),
         INT8_C(   13), -INT8_C(   93),  INT8_C(   29),  INT8_C(   93) },
      { -INT8_C(    8), -INT8_C(    1),  INT8_C(    1), -INT8_C(    1),
         INT8_C(    7), -INT8_C(    2),  INT8_C(    0),  INT8_C(    6) },
      {  INT8_C(    0), -INT8_C(   16), -INT8_C(   84), -INT8_C(   62),
              INT8_MAX, -INT8_C(   23),  INT8_C(   29),       INT8_MAX } },
    { {  INT8_C(  109), -INT8_C(  121), -INT8_C(   67), -INT8_C(   26),
         INT8_C(  116), -INT8_C(   14), -INT8_C(  107),  INT8_C(  120) },
      { -INT8_C(    8),  INT8_C(    1), -INT8_C(    7),  INT8_C(    2),
         INT8_C(    1), -INT8_C(    5),  INT8_C(    2),  INT8_C(    2) },
      {  INT8_C(    0),       INT8_MIN, -INT8_C(    1), -INT8_C(  104),
              INT8_MAX,  INT8_C(    0),       INT8_MIN,       INT8_MAX } },
    { { -INT8_C(   75),  INT8_C(    9),  INT8_C(   17),  INT8_C(    9),
        -INT8_C(   82),  INT8_C(   82), -INT8_C(   91), -INT8_C(   24) },
      {  INT8_C(    1),  INT8_C(    7),  INT8_C(    4), -INT8_C(    4),
         INT8_C(    0),  INT8_C(    6), -INT8_C(    8), -INT8_C(    7) },
      {       INT8_MIN,       INT8_MAX,       INT8_MAX,  INT8_C(    1),
        -INT8_C(   82),       INT8_MAX,  INT8_C(    0),  INT8_C(    0) } },
    { { -INT8_C(    3), -INT8_C(  107),  INT8_C(   50), -INT8_C(   31),
              INT8_MIN,  INT8_C(   61),  INT8_C(   53), -INT8_C(    4) },
      { -INT8_C(    5),  INT8_C(    5),  INT8_C(    6),  INT8_C(    2),
        -INT8_C(    2),  INT8_C(    5), -INT8_C(    6), -INT8_C(    5) },
      {  INT8_C(    0),       INT8_MIN,       INT8_MAX, -INT8_C(  124),
        -INT8_C(   32),       INT8_MAX,  INT8_C(    1),  INT8_C(    0) } },
    { {       INT8_MAX,       INT8_MAX,       INT8_MAX,       INT8_MAX,
              INT8_MAX,       INT8_MAX,       INT8_MAX,       INT8_MAX },
      { -INT8_C(    1), -INT8_C(    1), -INT8_C(    1), -INT8_C(    1),
        -INT8_C(    1), -INT8_C(    1), -INT8_C(    1), -INT8_C(    1) },
      {  INT8_C(   64),  INT8_C(   64),  INT8_C(   64),  INT8_C(   64),
         INT8_C(   64),  INT8_C(   64),  INT8_C(   64),  INT8_C(   64) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int8x8_t a = simde_vld1_s8(test_vec[i].a);
    simde_int8x8_t b = simde_vld1_s8(test_vec[i].b);
    simde_int8x8_t r = simde_vqrshl_s8(a, b);

    simde_test_arm_neon_assert_equal_i8x8(r, simde_vld1_s8(test_vec[i].r));
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int8x8_t a = simde_test_arm_neon_random_i8x8();
    simde_int8x8_t b = simde_test_arm_neon_random_i8x8();
    simde_int8x8_t r = simde_vqrshl_s8(a, b);

    simde_test_arm_neon_write_i8x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i8x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i8x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}


static int
test_simde_vqrshl_s16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    int16_t a[4];
    int16_t b[4];
    int16_t r[4];
  } test_vec[] = {
    { {  INT16_C(   31263),  INT16_C(   18737),  INT16_C(   14706), -INT16_C(   22084) },
      {  INT16_C(       0), -INT16_C(       6),  INT16_C(       5),  INT16_C(      11) },
      {  INT16_C(   31263),  INT16_C(     293),          INT16_MAX,          INT16_MIN } },
    { { -INT16_C(   27185),  INT16_C(    1410),  INT16_C(   26995), -INT16_C(    8974) },
      { -INT16_C(      15),  INT16_C(       9), -INT16_C(       4),  INT16_C(       4) },
      { -INT16_C(       1),          INT16_MAX,  INT16_C(    1687),          INT16_MIN } },
    { { -INT16_C(    5300),  INT16_C(    1064), -INT16_C(    4694),  INT16_C(   25472) },
      {  INT16_C(       3),  INT16_C(       0),  INT16_C(       5),  INT16_C(       8) },
      {          INT16_MIN,  INT16_C(    1064),          INT16_MIN,          INT16_MAX } },
    { { -INT16_C(    9080),  INT16_C(   16802), -INT16_C(   10592), -INT16_C(   30376) },
      { -INT16_C(       4), -INT16_C(       8),  INT16_C(       0),  INT16_C(      16) },
      { -INT16_C(     567),  INT16_C(      66), -INT16_C(   10592),          INT16_MIN } },
    { { -INT16_C(   10167),  INT16_C(   25018),  INT16_C(   28423), -INT16_C(    9608) },
      { -INT16_C(       2), -INT16_C(       4), -INT16_C(       6), -INT16_C(       8) },
      { -INT16_C(    2542),  INT16_C(    1564),  INT16_C(     444), -INT16_C(      38) } },
    { {  INT16_C(   32142), -INT16_C(   28370),  INT16_C(   24856),  INT16_C(   26195) },
      { -INT16_C(       3), -INT16_C(       8),  INT16_C(      15),  INT16_C(       9) },
      {  INT16_C(    4018), -INT16_C(     111),          INT16_MAX,          INT16_MAX } },
    { { -INT16_C(   23494), -INT16_C(   25691), -INT16_C(    8401), -INT16_C(   31132) },
      {  INT16_C(       3), -INT16_C(      13), -INT16_C(      16),  INT16_C(      14) },
      {          INT16_MIN, -INT16_C(       3),  INT16_C(       0),          INT16_MIN } },
    { {  INT16_C(   14453), -INT16_C(   12196),  INT16_C(   27445),  INT16_C(   31840) },
      {  INT16_C(      14),  INT16_C(       5),  INT16_C(      13), -INT16_C(       9) },
      {          INT16_MAX,          INT16_MIN,          INT16_MAX,  INT16_C(      62) } },
    { {          INT16_MAX,          INT16_MAX,          INT16_MAX,          INT16_MAX },
      { -INT16_C(       1), -INT16_C(       1), -INT16_C(       1), -INT16_C(       1) },
      {  INT16_C(   16384),  INT16_C(   16384),  INT16_C(   16384),  INT16_C(   16384) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x4_t a = simde_vld1_s16(test_vec[i].a);
    simde_int16x4_t b = simde_vld1_s16(test_vec[i].b);
    simde_int16x4_t r = simde_vqrshl_s16(a, b);

    simde_test_arm_neon_assert_equal_i16x4(r, simde_vld1_s16(test_vec[i].r));
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int16x4_t a = simde_test_arm_neon_random_i16x4();
    simde_int16x4_t b = simde_test_arm_neon_random_i16x4();
    simde_int16x4_t r = simde_vqrshl_s16(a, b);

    simde_test_arm_neon_write_i16x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i16x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i16x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vqrshl_s32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    int32_t a[2];
    int32_t b[2];
    int32_t r[2];
  } test_vec[] = {
    { {  INT32_C(    37316345),  INT32_C(   852588016) },
      { -INT32_C(          21),  INT32_C(          22) },
      {  INT32_C(          18),              INT32_MAX } },
    { {  INT32_C(  1713047364), -INT32_C(   718155773) },
      { -INT32_C(           2),  INT32_C(          18) },
      {  INT32_C(   428261841),              INT32_MIN } },
    { {  INT32_C(  2011282434), -INT32_C(  1644508231) },
      {  INT32_C(          12), -INT32_C(          21) },
      {              INT32_MAX, -INT32_C(         784) } },
    { { -INT32_C(     8819381), -INT32_C(   112184656) },
      { -INT32_C(          12), -INT32_C(          21) },
      { -INT32_C(        2153), -INT32_C(          53) } },
    { {  INT32_C(   305438996),  INT32_C(  1662430416) },
      {  INT32_C(          29), -INT32_C(          19) },
      {              INT32_MAX,  INT32_C(        3171) } },
    { {  INT32_C(  1246050521), -INT32_C(   703046011) },
      {  INT32_C(          11),  INT32_C(          11) },
      {              INT32_MAX,              INT32_MIN } },
    { { -INT32_C(   129492298), -INT32_C(  1643446120) },
      {  INT32_C(          13),  INT32_C(          25) },
      {              INT32_MIN,              INT32_MIN } },
    { {  INT32_C(    58593943), -INT32_C(   594339506) },
      { -INT32_C(          21), -INT32_C(           9) },
      {  INT32_C(          28), -INT32_C(     1160819) } },
    { {              INT32_MAX,              INT32_MAX },
      { -INT32_C(           1), -INT32_C(           1) },
      {  INT32_C(  1073741824),  INT32_C(  1073741824) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x2_t a = simde_vld1_s32(test_vec[i].a);
    simde_int32x2_t b = simde_vld1_s32(test_vec[i].b);
    simde_int32x2_t r = simde_vqrshl_s32(a, b);

    simde_test_arm_neon_assert_equal_i32x2(r, simde_vld1_s32(test_vec[i].r));
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int32x2_t a = simde_test_arm_neon_random_i32x2();
    simde_int32x2_t b = simde_test_arm_neon_random_i32x2();
    simde_int32x2_t r = simde_vqrshl_s32(a, b);

    simde_test_arm_neon_write_i32x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i32x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i32x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vqrshl_s64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    int64_t a[1];
    int64_t b[1];
    int64_t r[1];
  } test_vec[] = {
    { {  INT64_C( 2379025802943267314) },
      { -INT64_C(                   3) },
      {  INT64_C(  297378225367908414) } },
    { { -INT64_C( 7880843795017100943) },
      {  INT64_C(                  13) },
      {                      INT64_MIN } },
    { {  INT64_C( 5060086036473607234) },
      { -INT64_C(                  12) },
      {  INT64_C(    1235372567498439) } },
    { { -INT64_C( 1251288881944570923) },
      {  INT64_C(                  59) },
      {                      INT64_MIN } },
    { { -INT64_C(  818197169458855311) },
      { -INT64_C(                  46) },
      { -INT64_C(               11627) } },
    { { -INT64_C( 3470264563169298453) },
      { -INT64_C(                  56) },
      { -INT64_C(                  48) } },
    { { -INT64_C( 6566310065777805324) },
      { -INT64_C(                  54) },
      { -INT64_C(                 365) } },
    { {  INT64_C( 8846445702649439056) },
      { -INT64_C(                   5) },
      {  INT64_C(  276451428207794971) } },
    { {                      INT64_MAX },
      { -INT64_C(                   1) },
      {  INT64_C( 4611686018427387904) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int64x1_t a = simde_vld1_s64(test_vec[i].a);
    simde_int64x1_t b = simde_vld1_s64(test_vec[i].b);
    simde_int64x1_t r = simde_vqrshl_s64(a, b);

    simde_test_arm_neon_assert_equal_i64x1(r, simde_vld1_s64(test_vec[i].r));
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int64x1_t a = simde_test_arm_neon_random_i64x1();
    simde_int64x1_t b = simde_test_arm_neon_random_i64x1();
    simde_int64x1_t r = simde_vqrshl_s64(a, b);

    simde_test_arm_neon_write_i64x1(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i64x1(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i64x1(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vqrshl_u8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    uint8_t a[8];
    int8_t b[8];
    uint8_t r[8];
  } test_vec[] = {
    { {  UINT8_C(    17),  UINT8_C(   254),  UINT8_C(   166),  UINT8_C(   242),
         UINT8_C(   224),  UINT8_C(    96),  UINT8_C(   134),  UINT8_C(    31) },
      { -INT8_C(     2),  INT8_C(     6), -INT8_C(     5), -INT8_C(     2),
        -INT8_C(     1),  INT8_C(     0), -INT8_C(     4),  INT8_C(     4) },
      {  UINT8_C(     4),  UINT8_C(   255),  UINT8_C(     5),  UINT8_C(    61),
         UINT8_C(   112),  UINT8_C(    96),  UINT8_C(     8),  UINT8_C(   255) } },
    { {  UINT8_C(   236),  UINT8_C(    17),  UINT8_C(   172),  UINT8_C(    17),
         UINT8_C(    72),  UINT8_C(    97),  UINT8_C(   108),  UINT8_C(   128) },
      {  INT8_C(     6),  INT8_C(     0),  INT8_C(     6),  INT8_C(     7),
        -INT8_C(     4), -INT8_C(     5),  INT8_C(     1), -INT8_C(     7) },
      {  UINT8_C(   255),  UINT8_C(    17),  UINT8_C(   255),  UINT8_C(   255),
         UINT8_C(     5),  UINT8_C(     3),  UINT8_C(   216),  UINT8_C(     1) } },
    { {  UINT8_C(   101),  UINT8_C(   167),  UINT8_C(    60),  UINT8_C(   143),
         UINT8_C(   234),  UINT8_C(   177),  UINT8_C(   216),  UINT8_C(   221) },
      { -INT8_C(     3), -INT8_C(     8),  INT8_C(     3), -INT8_C(     6),
         INT8_C(     3),  INT8_C(     5), -INT8_C(     8),  INT8_C(     5) },
      {  UINT8_C(    13),  UINT8_C(     1),  UINT8_C(   255),  UINT8_C(     2),
         UINT8_C(   255),  UINT8_C(   255),  UINT8_C(     1),  UINT8_C(   255) } },
    { {  UINT8_C(     9),  UINT8_C(   223),  UINT8_C(    27),  UINT8_C(   204),
         UINT8_C(   106),  UINT8_C(   241),  UINT8_C(    32),  UINT8_C(   220) },
      { -INT8_C(     5),  INT8_C(     8),  INT8_C(     3),  INT8_C(     4),
        -INT8_C(     4),  INT8_C(     6),  INT8_C(     6), -INT8_C(     8) },
      {  UINT8_C(     0),  UINT8_C(   255),  UINT8_C(   216),  UINT8_C(   255),
         UINT8_C(     7),  UINT8_C(   255),  UINT8_C(   255),  UINT8_C(     1) } },
    { {  UINT8_C(   175),  UINT8_C(   114),  UINT8_C(    53),  UINT8_C(    46),
         UINT8_C(    26),  UINT8_C(   170),  UINT8_C(   171),  UINT8_C(   213) },
      { -INT8_C(     6), -INT8_C(     6), -INT8_C(     4),  INT8_C(     3),
         INT8_C(     1), -INT8_C(     2), -INT8_C(     3), -INT8_C(     8) },
      {  UINT8_C(     3),  UINT8_C(     2),  UINT8_C(     3),  UINT8_C(   255),
         UINT8_C(    52),  UINT8_C(    43),  UINT8_C(    21),  UINT8_C(     1) } },
    { {  UINT8_C(    37),  UINT8_C(   113),  UINT8_C(   207),  UINT8_C(   209),
         UINT8_C(   209),  UINT8_C(     8),  UINT8_C(   239),  UINT8_C(    42) },
      { -INT8_C(     8), -INT8_C(     6), -INT8_C(     7), -INT8_C(     5),
         INT8_C(     2),  INT8_C(     7),  INT8_C(     1), -INT8_C(     5) },
      {  UINT8_C(     0),  UINT8_C(     2),  UINT8_C(     2),  UINT8_C(     7),
         UINT8_C(   255),  UINT8_C(   255),  UINT8_C(   255),  UINT8_C(     1) } },
    { {  UINT8_C(   249),  UINT8_C(    98),  UINT8_C(    62),  UINT8_C(   112),
         UINT8_C(    21),  UINT8_C(    89),  UINT8_C(   159),  UINT8_C(   208) },
      {  INT8_C(     4), -INT8_C(     3),  INT8_C(     8),  INT8_C(     0),
        -INT8_C(     4), -INT8_C(     6), -INT8_C(     3),  INT8_C(     2) },
      {  UINT8_C(   255),  UINT8_C(    12),  UINT8_C(   255),  UINT8_C(   112),
         UINT8_C(     1),  UINT8_C(     1),  UINT8_C(    20),  UINT8_C(   255) } },
    { {  UINT8_C(    38),  UINT8_C(   128),  UINT8_C(   239),  UINT8_C(   139),
         UINT8_C(   165),  UINT8_C(   233),  UINT8_C(   134),  UINT8_C(   247) },
      { -INT8_C(     3),  INT8_C(     5),  INT8_C(     6),  INT8_C(     3),
        -INT8_C(     5),  INT8_C(     4),  INT8_C(     1),  INT8_C(     7) },
      {  UINT8_C(     5),  UINT8_C(   255),  UINT8_C(   255),  UINT8_C(   255),
         UINT8_C(     5),  UINT8_C(   255),  UINT8_C(   255),  UINT8_C(   255) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint8x8_t a = simde_vld1_u8(test_vec[i].a);
    simde_int8x8_t b = simde_vld1_s8(test_vec[i].b);
    simde_uint8x8_t r = simde_vqrshl_u8(a, b);

    simde_test_arm_neon_assert_equal_u8x8(r, simde_vld1_u8(test_vec[i].r));
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint8x8_t a = simde_test_arm_neon_random_u8x8();
    simde_int8x8_t b = simde_test_arm_neon_random_i8x8();
    simde_uint8x8_t r = simde_vqrshl_u8(a, b);

    simde_test_arm_neon_write_u8x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i8x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u8x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vqrshl_u16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    uint16_t a[4];
    int16_t b[4];
    uint16_t r[4];
  } test_vec[] = {
    { {  UINT16_C(   36529),  UINT16_C(   29829),  UINT16_C(    2096),  UINT16_C(    2729) },
      {  INT16_C(       0),  INT16_C(       4),  INT16_C(       9), -INT16_C(       4) },
      {  UINT16_C(   36529),  UINT16_C(   65535),  UINT16_C(   65535),  UINT16_C(     171) } },
    { {  UINT16_C(   39946),  UINT16_C(   27950),  UINT16_C(   23605),  UINT16_C(    4911) },
      {  INT16_C(      11), -INT16_C(      14), -INT16_C(       7),  INT16_C(       9) },
      {  UINT16_C(   65535),  UINT16_C(       2),  UINT16_C(     184),  UINT16_C(   65535) } },
    { {  UINT16_C(   42859),  UINT16_C(    2240),  UINT16_C(   20043),  UINT16_C(   10036) },
      {  INT16_C(       8),  INT16_C(      14), -INT16_C(      15), -INT16_C(      12) },
      {  UINT16_C(   65535),  UINT16_C(   65535),  UINT16_C(       1),  UINT16_C(       2) } },
    { {  UINT16_C(   50980),  UINT16_C(     165),  UINT16_C(   10039),  UINT16_C(   30538) },
      {  INT16_C(       8), -INT16_C(       8),  INT16_C(      11), -INT16_C(       9) },
      {  UINT16_C(   65535),  UINT16_C(       1),  UINT16_C(   65535),  UINT16_C(      60) } },
    { {  UINT16_C(   61605),  UINT16_C(   27801),  UINT16_C(   14514),  UINT16_C(   31459) },
      { -INT16_C(       2),  INT16_C(       9),  INT16_C(       7),  INT16_C(      13) },
      {  UINT16_C(   15401),  UINT16_C(   65535),  UINT16_C(   65535),  UINT16_C(   65535) } },
    { {  UINT16_C(   27895),  UINT16_C(   11683),  UINT16_C(   16781),  UINT16_C(   38533) },
      { -INT16_C(      10), -INT16_C(       4),  INT16_C(      16), -INT16_C(      10) },
      {  UINT16_C(      27),  UINT16_C(     730),  UINT16_C(   65535),  UINT16_C(      38) } },
    { {  UINT16_C(   53996),  UINT16_C(   31874),  UINT16_C(   57883),  UINT16_C(    4747) },
      { -INT16_C(      16),  INT16_C(       8), -INT16_C(       9),  INT16_C(       9) },
      {  UINT16_C(       1),  UINT16_C(   65535),  UINT16_C(     113),  UINT16_C(   65535) } },
    { {  UINT16_C(   37059),  UINT16_C(   57524),  UINT16_C(   51263),  UINT16_C(   61052) },
      {  INT16_C(       6), -INT16_C(      11), -INT16_C(       1), -INT16_C(       6) },
      {  UINT16_C(   65535),  UINT16_C(      28),  UINT16_C(   25632),  UINT16_C(     954) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint16x4_t a = simde_vld1_u16(test_vec[i].a);
    simde_int16x4_t b = simde_vld1_s16(test_vec[i].b);
    simde_uint16x4_t r = simde_vqrshl_u16(a, b);
    simde_test_arm_neon_assert_equal_u16x4(r, simde_vld1_u16(test_vec[i].r));
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint16x4_t a = simde_test_arm_neon_random_u16x4();
    simde_int16x4_t b = simde_test_arm_neon_random_i16x4();
    simde_uint16x4_t r = simde_vqrshl_u16(a, b);

    simde_test_arm_neon_write_u16x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i16x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u16x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vqrshl_u32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    uint32_t a[2];
    int32_t b[2];
    uint32_t r[2];
  } test_vec[] = {
    { {  UINT32_C(  4032142366),  UINT32_C(  2503991721) },
      {  INT32_C(          23), -INT32_C(          11) },
      {  UINT32_C(  4294967295),  UINT32_C(     1222652) } },
    { {  UINT32_C(  1849889977),  UINT32_C(  1539239213) },
      {  INT32_C(           3), -INT32_C(          31) },
      {  UINT32_C(  4294967295),  UINT32_C(           1) } },
    { {  UINT32_C(  3780982194),  UINT32_C(  1551554012) },
      {  INT32_C(           8),  INT32_C(          30) },
      {  UINT32_C(  4294967295),  UINT32_C(  4294967295) } },
    { {  UINT32_C(   457931350),  UINT32_C(  2322708363) },
      { -INT32_C(          24), -INT32_C(          15) },
      {  UINT32_C(          27),  UINT32_C(       70883) } },
    { {  UINT32_C(  1302772324),  UINT32_C(  3149457440) },
      { -INT32_C(           8),  INT32_C(          31) },
      {  UINT32_C(     5088954),  UINT32_C(  4294967295) } },
    { {  UINT32_C(  2656566271),  UINT32_C(    10727285) },
      { -INT32_C(          11),  INT32_C(          23) },
      {  UINT32_C(     1297151),  UINT32_C(  4294967295) } },
    { {  UINT32_C(   580186040),  UINT32_C(   879645142) },
      {  INT32_C(          26),  INT32_C(           8) },
      {  UINT32_C(  4294967295),  UINT32_C(  4294967295) } },
    { {  UINT32_C(  2842364758),  UINT32_C(   627566619) },
      { -INT32_C(          19), -INT32_C(          17) },
      {  UINT32_C(        5421),  UINT32_C(        4788) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint32x2_t a = simde_vld1_u32(test_vec[i].a);
    simde_int32x2_t b = simde_vld1_s32(test_vec[i].b);
    simde_uint32x2_t r = simde_vqrshl_u32(a, b);
    simde_test_arm_neon_assert_equal_u32x2(r, simde_vld1_u32(test_vec[i].r));
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint32x2_t a = simde_test_arm_neon_random_u32x2();
    simde_int32x2_t b = simde_test_arm_neon_random_i32x2();
    simde_uint32x2_t r = simde_vqrshl_u32(a, b);

    simde_test_arm_neon_write_u32x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i32x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vqrshl_u64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    uint64_t a[1];
    int64_t b[1];
    uint64_t r[1];
  } test_vec[] = {
    { {  UINT64_C(10606652271688138073) },
      { -INT64_C(                  24) },
      {  UINT64_C(        632205740910) } },
    { {  UINT64_C( 6951000685328207734) },
      { -INT64_C(                  41) },
      {  UINT64_C(             3160949) } },
    { {  UINT64_C( 2652753700446653166) },
      {  INT64_C(                  16) },
      {  UINT64_C(18446744073709551615) } },
    { {  UINT64_C( 2887850072060195408) },
      {  INT64_C(                   8) },
      {  UINT64_C(18446744073709551615) } },
    { {  UINT64_C( 3003532981166020057) },
      { -INT64_C(                  18) },
      {  UINT64_C(      11457569050469) } },
    { {  UINT64_C( 2467308484911859140) },
      { -INT64_C(                   4) },
      {  UINT64_C(  154206780306991196) } },
    { {  UINT64_C(10329885492628171968) },
      {  INT64_C(                   8) },
      {  UINT64_C(18446744073709551615) } },
    { {  UINT64_C( 2016469675685954892) },
      { -INT64_C(                  62) },
      {  UINT64_C(                   0) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint64x1_t a = simde_vld1_u64(test_vec[i].a);
    simde_int64x1_t b = simde_vld1_s64(test_vec[i].b);
    simde_uint64x1_t r = simde_vqrshl_u64(a, b);
    simde_test_arm_neon_assert_equal_u64x1(r, simde_vld1_u64(test_vec[i].r));
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint64x1_t a = simde_test_arm_neon_random_u64x1();
    simde_int64x1_t b = simde_test_arm_neon_random_i64x1();
    simde_uint64x1_t r = simde_vqrshl_u64(a, b);

    simde_test_arm_neon_write_u64x1(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i64x1(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u64x1(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vqrshlq_s8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    int8_t a[16];
    int8_t b[16];
    int8_t r[16];
  } test_vec[] = {
    { {  INT8_C(   40), -INT8_C(   12), -INT8_C(  107),  INT8_C(   91),
         INT8_C(   39),  INT8_C(   70), -INT8_C(   66), -INT8_C(   32),
         INT8_C(   44),  INT8_C(  106),  INT8_C(   13), -INT8_C(   17),
         INT8_C(   42), -INT8_C(   33),  INT8_C(    0),  INT8_C(   99) },
      { -INT8_C(    1),  INT8_C(    5),  INT8_C(    7), -INT8_C(    6),
         INT8_C(    5),  INT8_C(    3), -INT8_C(    4), -INT8_C(    2),
         INT8_C(    8),  INT8_C(    7), -INT8_C(    8), -INT8_C(    8),
         INT8_C(    8),  INT8_C(    4),  INT8_C(    4), -INT8_C(    7) },
      {  INT8_C(   20),       INT8_MIN,       INT8_MIN,  INT8_C(    1),
              INT8_MAX,       INT8_MAX, -INT8_C(    4), -INT8_C(    8),
              INT8_MAX,       INT8_MAX,  INT8_C(    0),  INT8_C(    0),
              INT8_MAX,       INT8_MIN,  INT8_C(    0),  INT8_C(    1) } },
    { {  INT8_C(   13), -INT8_C(   18), -INT8_C(  109),  INT8_C(  117),
        -INT8_C(  115),  INT8_C(   11),  INT8_C(   28),  INT8_C(   34),
         INT8_C(   84),  INT8_C(   24), -INT8_C(   56),  INT8_C(   69),
         INT8_C(  112), -INT8_C(   93), -INT8_C(   57),  INT8_C(   46) },
      {  INT8_C(    3),  INT8_C(    1), -INT8_C(    6),  INT8_C(    4),
        -INT8_C(    7),  INT8_C(    1),  INT8_C(    3), -INT8_C(    4),
         INT8_C(    6),  INT8_C(    1), -INT8_C(    2), -INT8_C(    3),
         INT8_C(    0),  INT8_C(    6),  INT8_C(    3),  INT8_C(    8) },
      {  INT8_C(  104), -INT8_C(   36), -INT8_C(    2),       INT8_MAX,
        -INT8_C(    1),  INT8_C(   22),       INT8_MAX,  INT8_C(    2),
              INT8_MAX,  INT8_C(   48), -INT8_C(   14),  INT8_C(    9),
         INT8_C(  112),       INT8_MIN,       INT8_MIN,       INT8_MAX } },
    { { -INT8_C(   20),  INT8_C(   92), -INT8_C(  120),  INT8_C(   62),
        -INT8_C(   85),  INT8_C(   61), -INT8_C(    9), -INT8_C(  121),
         INT8_C(   18), -INT8_C(   16), -INT8_C(  124), -INT8_C(  109),
         INT8_C(  101),  INT8_C(   14), -INT8_C(   15), -INT8_C(   69) },
      {  INT8_C(    2), -INT8_C(    3),  INT8_C(    3),  INT8_C(    2),
        -INT8_C(    2), -INT8_C(    2), -INT8_C(    2),  INT8_C(    6),
         INT8_C(    0),  INT8_C(    2),  INT8_C(    4),  INT8_C(    5),
        -INT8_C(    8), -INT8_C(    3), -INT8_C(    1),  INT8_C(    8) },
      { -INT8_C(   80),  INT8_C(   12),       INT8_MIN,       INT8_MAX,
        -INT8_C(   21),  INT8_C(   15), -INT8_C(    2),       INT8_MIN,
         INT8_C(   18), -INT8_C(   64),       INT8_MIN,       INT8_MIN,
         INT8_C(    0),  INT8_C(    2), -INT8_C(    7),       INT8_MIN } },
    { {  INT8_C(   38),  INT8_C(   60), -INT8_C(   70),  INT8_C(   91),
         INT8_C(  120), -INT8_C(  121),  INT8_C(   71), -INT8_C(   22),
         INT8_C(   92),  INT8_C(    8),  INT8_C(  124), -INT8_C(  117),
         INT8_C(  115),  INT8_C(   44), -INT8_C(   93),  INT8_C(   66) },
      {  INT8_C(    1),  INT8_C(    5),  INT8_C(    2),  INT8_C(    8),
        -INT8_C(    6), -INT8_C(    4),  INT8_C(    8), -INT8_C(    2),
         INT8_C(    5),  INT8_C(    4), -INT8_C(    2),  INT8_C(    2),
         INT8_C(    8),  INT8_C(    0), -INT8_C(    5),  INT8_C(    0) },
      {  INT8_C(   76),       INT8_MAX,       INT8_MIN,       INT8_MAX,
         INT8_C(    2), -INT8_C(    8),       INT8_MAX, -INT8_C(    5),
              INT8_MAX,       INT8_MAX,  INT8_C(   31),       INT8_MIN,
              INT8_MAX,  INT8_C(   44), -INT8_C(    3),  INT8_C(   66) } },
    { {  INT8_C(  122), -INT8_C(  112), -INT8_C(  124),  INT8_C(   42),
         INT8_C(   87), -INT8_C(  117),  INT8_C(   56), -INT8_C(   93),
         INT8_C(   78),  INT8_C(   31), -INT8_C(    3), -INT8_C(   50),
         INT8_C(  116),  INT8_C(   68),  INT8_C(   64),  INT8_C(   69) },
      {  INT8_C(    2),  INT8_C(    4), -INT8_C(    7),  INT8_C(    4),
        -INT8_C(    3), -INT8_C(    8),  INT8_C(    8),  INT8_C(    1),
        -INT8_C(    5), -INT8_C(    1),  INT8_C(    6), -INT8_C(    3),
        -INT8_C(    3),  INT8_C(    5),  INT8_C(    2),  INT8_C(    1) },
      {       INT8_MAX,       INT8_MIN, -INT8_C(    1),       INT8_MAX,
         INT8_C(   11),  INT8_C(    0),       INT8_MAX,       INT8_MIN,
         INT8_C(    2),  INT8_C(   16),       INT8_MIN, -INT8_C(    6),
         INT8_C(   15),       INT8_MAX,       INT8_MAX,       INT8_MAX } },
    { { -INT8_C(   34), -INT8_C(    5), -INT8_C(   85), -INT8_C(   77),
         INT8_C(   98),  INT8_C(  107),  INT8_C(   84), -INT8_C(  115),
        -INT8_C(  127), -INT8_C(    1), -INT8_C(   33),  INT8_C(  111),
         INT8_C(   33),  INT8_C(   97),  INT8_C(   46),  INT8_C(   76) },
      {  INT8_C(    8),  INT8_C(    4),  INT8_C(    0), -INT8_C(    7),
         INT8_C(    2), -INT8_C(    6),  INT8_C(    4), -INT8_C(    8),
         INT8_C(    4),  INT8_C(    6),  INT8_C(    4), -INT8_C(    8),
         INT8_C(    1), -INT8_C(    5), -INT8_C(    6), -INT8_C(    7) },
      {       INT8_MIN, -INT8_C(   80), -INT8_C(   85), -INT8_C(    1),
              INT8_MAX,  INT8_C(    2),       INT8_MAX,  INT8_C(    0),
              INT8_MIN, -INT8_C(   64),       INT8_MIN,  INT8_C(    0),
         INT8_C(   66),  INT8_C(    3),  INT8_C(    1),  INT8_C(    1) } },
    { { -INT8_C(   69), -INT8_C(   87),  INT8_C(   96),  INT8_C(   21),
         INT8_C(   66), -INT8_C(   29), -INT8_C(   72), -INT8_C(  116),
        -INT8_C(  125),  INT8_C(   72),  INT8_C(   98),  INT8_C(   60),
         INT8_C(   99),  INT8_C(  102), -INT8_C(   72), -INT8_C(   39) },
      {  INT8_C(    2), -INT8_C(    3), -INT8_C(    6), -INT8_C(    3),
        -INT8_C(    3),  INT8_C(    4),  INT8_C(    4), -INT8_C(    2),
         INT8_C(    0), -INT8_C(    5),  INT8_C(    1),  INT8_C(    5),
        -INT8_C(    3), -INT8_C(    3), -INT8_C(    7), -INT8_C(    7) },
      {       INT8_MIN, -INT8_C(   11),  INT8_C(    2),  INT8_C(    3),
         INT8_C(    8),       INT8_MIN,       INT8_MIN, -INT8_C(   29),
        -INT8_C(  125),  INT8_C(    2),       INT8_MAX,       INT8_MAX,
         INT8_C(   12),  INT8_C(   13), -INT8_C(    1),  INT8_C(    0) } },
    { { -INT8_C(  121),  INT8_C(   38),  INT8_C(  117),  INT8_C(   37),
        -INT8_C(   14), -INT8_C(   96),  INT8_C(   74),  INT8_C(  115),
        -INT8_C(   24),  INT8_C(   64),  INT8_C(  105), -INT8_C(  122),
        -INT8_C(   82),  INT8_C(    2),  INT8_C(  119),  INT8_C(   84) },
      {  INT8_C(    5),  INT8_C(    1),  INT8_C(    1),  INT8_C(    3),
        -INT8_C(    1),  INT8_C(    3),  INT8_C(    8),  INT8_C(    2),
         INT8_C(    0), -INT8_C(    4),  INT8_C(    8),  INT8_C(    3),
         INT8_C(    0),  INT8_C(    0), -INT8_C(    6), -INT8_C(    1) },
      {       INT8_MIN,  INT8_C(   76),       INT8_MAX,       INT8_MAX,
        -INT8_C(    7),       INT8_MIN,       INT8_MAX,       INT8_MAX,
        -INT8_C(   24),  INT8_C(    4),       INT8_MAX,       INT8_MIN,
        -INT8_C(   82),  INT8_C(    2),  INT8_C(    2),  INT8_C(   42) } },
    { {       INT8_MAX,       INT8_MAX,       INT8_MAX,       INT8_MAX,
              INT8_MAX,       INT8_MAX,       INT8_MAX,       INT8_MAX,
              INT8_MAX,       INT8_MAX,       INT8_MAX,       INT8_MAX,
              INT8_MAX,       INT8_MAX,       INT8_MAX,       INT8_MAX },
      { -INT8_C(    1), -INT8_C(    1), -INT8_C(    1), -INT8_C(    1),
        -INT8_C(    1), -INT8_C(    1), -INT8_C(    1), -INT8_C(    1),
        -INT8_C(    1), -INT8_C(    1), -INT8_C(    1), -INT8_C(    1),
        -INT8_C(    1), -INT8_C(    1), -INT8_C(    1), -INT8_C(    1) },
      {  INT8_C(   64),  INT8_C(   64),  INT8_C(   64),  INT8_C(   64),
         INT8_C(   64),  INT8_C(   64),  INT8_C(   64),  INT8_C(   64),
         INT8_C(   64),  INT8_C(   64),  INT8_C(   64),  INT8_C(   64),
         INT8_C(   64),  INT8_C(   64),  INT8_C(   64),  INT8_C(   64) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int8x16_t a = simde_vld1q_s8(test_vec[i].a);
    simde_int8x16_t b = simde_vld1q_s8(test_vec[i].b);
    simde_int8x16_t r = simde_vqrshlq_s8(a, b);

    simde_test_arm_neon_assert_equal_i8x16(r, simde_vld1q_s8(test_vec[i].r));
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int8x16_t a = simde_test_arm_neon_random_i8x16();
    simde_int8x16_t b = simde_test_arm_neon_random_i8x16();
    simde_int8x16_t r = simde_vqrshlq_s8(a, b);

    simde_test_arm_neon_write_i8x16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i8x16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i8x16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vqrshlq_s16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    int16_t a[8];
    int16_t b[8];
    int16_t r[8];
  } test_vec[] = {
    { {  INT16_C(      17), -INT16_C(   18060),  INT16_C(    2082),  INT16_C(    3026),
        -INT16_C(   23678),  INT16_C(   13144), -INT16_C(   19898),  INT16_C(   26465) },
      { -INT16_C(       9),  INT16_C(       4), -INT16_C(       9), -INT16_C(       7),
         INT16_C(       6), -INT16_C(       8), -INT16_C(       5), -INT16_C(       7) },
      {  INT16_C(       0),          INT16_MIN,  INT16_C(       4),  INT16_C(      24),
                 INT16_MIN,  INT16_C(      51), -INT16_C(     622),  INT16_C(     207) } },
    { { -INT16_C(   31358),  INT16_C(   28497), -INT16_C(   24101), -INT16_C(   29556),
         INT16_C(   23640),  INT16_C(   26523),  INT16_C(   30555),  INT16_C(   32733) },
      {  INT16_C(       8),  INT16_C(      12),  INT16_C(      11), -INT16_C(       9),
        -INT16_C(       8), -INT16_C(      11),  INT16_C(       4), -INT16_C(       3) },
      {          INT16_MIN,          INT16_MAX,          INT16_MIN, -INT16_C(      58),
         INT16_C(      92),  INT16_C(      13),          INT16_MAX,  INT16_C(    4092) } },
    { { -INT16_C(   25371), -INT16_C(   28626), -INT16_C(   10661), -INT16_C(   29662),
         INT16_C(    8039),  INT16_C(   27599),  INT16_C(   27158),  INT16_C(   14531) },
      {  INT16_C(       0), -INT16_C(      10),  INT16_C(       2),  INT16_C(      11),
        -INT16_C(       2), -INT16_C(       9),  INT16_C(      15),  INT16_C(       6) },
      { -INT16_C(   25371), -INT16_C(      28),          INT16_MIN,          INT16_MIN,
         INT16_C(    2010),  INT16_C(      54),          INT16_MAX,          INT16_MAX } },
    { {  INT16_C(   29383),  INT16_C(   13775),  INT16_C(    1669),  INT16_C(   16370),
        -INT16_C(   31950), -INT16_C(   10488), -INT16_C(    4281), -INT16_C(   15443) },
      {  INT16_C(       6), -INT16_C(      14),  INT16_C(       6), -INT16_C(      13),
        -INT16_C(       7),  INT16_C(       5),  INT16_C(      12), -INT16_C(       2) },
      {          INT16_MAX,  INT16_C(       1),          INT16_MAX,  INT16_C(       2),
        -INT16_C(     250),          INT16_MIN,          INT16_MIN, -INT16_C(    3861) } },
    { { -INT16_C(   16008),  INT16_C(    6576),  INT16_C(   25375), -INT16_C(    2472),
        -INT16_C(   22062), -INT16_C(    1594), -INT16_C(      33), -INT16_C(   29140) },
      { -INT16_C(      10), -INT16_C(      16), -INT16_C(      14),  INT16_C(      15),
        -INT16_C(      11), -INT16_C(      13),  INT16_C(       3), -INT16_C(      13) },
      { -INT16_C(      16),  INT16_C(       0),  INT16_C(       2),          INT16_MIN,
        -INT16_C(      11),  INT16_C(       0), -INT16_C(     264), -INT16_C(       4) } },
    { { -INT16_C(   17438),  INT16_C(   21035), -INT16_C(    4482), -INT16_C(    5337),
        -INT16_C(   25235), -INT16_C(    6754), -INT16_C(    9668), -INT16_C(   27862) },
      { -INT16_C(       1), -INT16_C(      15),  INT16_C(       5), -INT16_C(       4),
        -INT16_C(       5),  INT16_C(      14), -INT16_C(       8), -INT16_C(       9) },
      { -INT16_C(    8719),  INT16_C(       1),          INT16_MIN, -INT16_C(     334),
        -INT16_C(     789),          INT16_MIN, -INT16_C(      38), -INT16_C(      54) } },
    { {  INT16_C(   10172), -INT16_C(    6237), -INT16_C(   25431), -INT16_C(   30731),
        -INT16_C(    2806), -INT16_C(   24307), -INT16_C(    1303), -INT16_C(   17051) },
      { -INT16_C(       4),  INT16_C(      13), -INT16_C(      11), -INT16_C(       1),
         INT16_C(      10),  INT16_C(       7), -INT16_C(      16),  INT16_C(       1) },
      {  INT16_C(     636),          INT16_MIN, -INT16_C(      12), -INT16_C(   15365),
                 INT16_MIN,          INT16_MIN,  INT16_C(       0),          INT16_MIN } },
    { { -INT16_C(    1297),  INT16_C(    6102),  INT16_C(   12306),  INT16_C(   23191),
        -INT16_C(    2630), -INT16_C(   28109), -INT16_C(   20844),  INT16_C(     271) },
      {  INT16_C(       3),  INT16_C(      15),  INT16_C(       8),  INT16_C(       6),
         INT16_C(       0),  INT16_C(      15), -INT16_C(       5), -INT16_C(      13) },
      { -INT16_C(   10376),          INT16_MAX,          INT16_MAX,          INT16_MAX,
        -INT16_C(    2630),          INT16_MIN, -INT16_C(     651),  INT16_C(       0) } },
    { {          INT16_MAX,          INT16_MAX,          INT16_MAX,          INT16_MAX,
                 INT16_MAX,          INT16_MAX,          INT16_MAX,          INT16_MAX },
      { -INT16_C(       1), -INT16_C(       1), -INT16_C(       1), -INT16_C(       1),
        -INT16_C(       1), -INT16_C(       1), -INT16_C(       1), -INT16_C(       1) },
      {  INT16_C(   16384),  INT16_C(   16384),  INT16_C(   16384),  INT16_C(   16384),
         INT16_C(   16384),  INT16_C(   16384),  INT16_C(   16384),  INT16_C(   16384) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x8_t a = simde_vld1q_s16(test_vec[i].a);
    simde_int16x8_t b = simde_vld1q_s16(test_vec[i].b);
    simde_int16x8_t r = simde_vqrshlq_s16(a, b);

    simde_test_arm_neon_assert_equal_i16x8(r, simde_vld1q_s16(test_vec[i].r));
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int16x8_t a = simde_test_arm_neon_random_i16x8();
    simde_int16x8_t b = simde_test_arm_neon_random_i16x8();
    simde_int16x8_t r = simde_vqrshlq_s16(a, b);

    simde_test_arm_neon_write_i16x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i16x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i16x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vqrshlq_s32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    int32_t a[4];
    int32_t b[4];
    int32_t r[4];
  } test_vec[] = {
    { {  INT32_C(  1814886595), -INT32_C(  1646956830),  INT32_C(  1237502269),  INT32_C(   534733024) },
      { -INT32_C(          21), -INT32_C(          25),  INT32_C(          31), -INT32_C(          11) },
      {  INT32_C(         865), -INT32_C(          49),              INT32_MAX,  INT32_C(      261100) } },
    { {  INT32_C(  1736113552),  INT32_C(  1258318563),  INT32_C(  1069774949),  INT32_C(   755812542) },
      { -INT32_C(          32),  INT32_C(           8),  INT32_C(          32),  INT32_C(          19) },
      {  INT32_C(           0),              INT32_MAX,              INT32_MAX,              INT32_MAX } },
    { { -INT32_C(  1923447339), -INT32_C(  1220148547), -INT32_C(  1485011002), -INT32_C(  1143271085) },
      { -INT32_C(          30), -INT32_C(          24), -INT32_C(          25),  INT32_C(          30) },
      { -INT32_C(           2), -INT32_C(          73), -INT32_C(          44),              INT32_MIN } },
    { {  INT32_C(  1865665830),  INT32_C(  2143927441), -INT32_C(  1135678127),  INT32_C(   123259338) },
      {  INT32_C(          20), -INT32_C(           9), -INT32_C(          31), -INT32_C(          14) },
      {              INT32_MAX,  INT32_C(     4187358), -INT32_C(           1),  INT32_C(        7523) } },
    { {  INT32_C(     3352422), -INT32_C(   698249524),  INT32_C(  1806447909),  INT32_C(   800823842) },
      { -INT32_C(           6),  INT32_C(           4), -INT32_C(           6),  INT32_C(          32) },
      {  INT32_C(       52382),              INT32_MIN,  INT32_C(    28225749),              INT32_MAX } },
    { { -INT32_C(   337342704),  INT32_C(  1303521110),  INT32_C(   425408117),  INT32_C(   231996299) },
      { -INT32_C(          32), -INT32_C(          16), -INT32_C(          31),  INT32_C(           2) },
      {  INT32_C(           0),  INT32_C(       19890),  INT32_C(           0),  INT32_C(   927985196) } },
    { { -INT32_C(   529877133), -INT32_C(  1960225014), -INT32_C(  1757285913),  INT32_C(  1764816475) },
      {  INT32_C(          20), -INT32_C(           6),  INT32_C(          32),  INT32_C(          24) },
      {              INT32_MIN, -INT32_C(    30628516),              INT32_MIN,              INT32_MAX } },
    { {  INT32_C(   219035158),  INT32_C(  2118934887),  INT32_C(   641686675),  INT32_C(   264846024) },
      {  INT32_C(           6),  INT32_C(          28), -INT32_C(           1),  INT32_C(          12) },
      {              INT32_MAX,              INT32_MAX,  INT32_C(   320843338),              INT32_MAX } },
    { {              INT32_MAX,              INT32_MAX,              INT32_MAX,              INT32_MAX },
      { -INT32_C(           1), -INT32_C(           1), -INT32_C(           1), -INT32_C(           1) },
      {  INT32_C(  1073741824),  INT32_C(  1073741824),  INT32_C(  1073741824),  INT32_C(  1073741824) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x4_t a = simde_vld1q_s32(test_vec[i].a);
    simde_int32x4_t b = simde_vld1q_s32(test_vec[i].b);
    simde_int32x4_t r = simde_vqrshlq_s32(a, b);
    simde_test_arm_neon_assert_equal_i32x4(r, simde_vld1q_s32(test_vec[i].r));
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int32x4_t a = simde_test_arm_neon_random_i32x4();
    simde_int32x4_t b = simde_test_arm_neon_random_i32x4();
    simde_int32x4_t r = simde_vqrshlq_s32(a, b);

    simde_test_arm_neon_write_i32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vqrshlq_s64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    int64_t a[2];
    int64_t b[2];
    int64_t r[2];
  } test_vec[] = {
    { { -INT64_C( 5414884328532004708), -INT64_C( 7732031084687741673) },
      { -INT64_C(                  63),  INT64_C(                  61) },
      { -INT64_C(                   1),                      INT64_MIN } },
    { {  INT64_C( 3932969372243887233), -INT64_C( 7443478377457562434) },
      { -INT64_C(                  45), -INT64_C(                   1) },
      {  INT64_C(              111782), -INT64_C( 3721739188728781217) } },
    { { -INT64_C( 4624332781887269652),  INT64_C( 9194359439567769551) },
      {  INT64_C(                  18),  INT64_C(                  12) },
      {                      INT64_MIN,                      INT64_MAX } },
    { {  INT64_C( 1303116637892605202),  INT64_C( 2411425157371539502) },
      { -INT64_C(                  35), -INT64_C(                  12) },
      {  INT64_C(            37925686),  INT64_C(     588726845061411) } },
    { { -INT64_C( 5953546370211056151),  INT64_C( 4807810721811645268) },
      { -INT64_C(                  15),  INT64_C(                  44) },
      { -INT64_C(     181687816473726),                      INT64_MAX } },
    { { -INT64_C(  671209687377174666), -INT64_C( 2105758642682840471) },
      {  INT64_C(                  35),  INT64_C(                   6) },
      {                      INT64_MIN,                      INT64_MIN } },
    { { -INT64_C( 1318546396640194493),  INT64_C( 4726180957159977633) },
      {  INT64_C(                  33),  INT64_C(                   3) },
      {                      INT64_MIN,                      INT64_MAX } },
    { {  INT64_C(  570160631599597498),  INT64_C( 7291438976119207855) },
      { -INT64_C(                  54),  INT64_C(                  30) },
      {  INT64_C(                  32),                      INT64_MAX } },
    { {                      INT64_MAX,                      INT64_MAX },
      { -INT64_C(                   1), -INT64_C(                   1) },
      {  INT64_C( 4611686018427387904),  INT64_C( 4611686018427387904) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int64x2_t a = simde_vld1q_s64(test_vec[i].a);
    simde_int64x2_t b = simde_vld1q_s64(test_vec[i].b);
    simde_int64x2_t r = simde_vqrshlq_s64(a, b);
    simde_test_arm_neon_assert_equal_i64x2(r, simde_vld1q_s64(test_vec[i].r));
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int64x2_t a = simde_test_arm_neon_random_i64x2();
    simde_int64x2_t b = simde_test_arm_neon_random_i64x2();
    simde_int64x2_t r = simde_vqrshlq_s64(a, b);

    simde_test_arm_neon_write_i64x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i64x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vqrshlq_u8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    uint8_t a[16];
    int8_t b[16];
    uint8_t r[16];
  } test_vec[] = {
    { {  UINT8_C(    48),  UINT8_C(   110),  UINT8_C(   160),  UINT8_C(   230),
         UINT8_C(   244),  UINT8_C(    14),  UINT8_C(    38),  UINT8_C(   180),
         UINT8_C(    44),  UINT8_C(     4),  UINT8_C(   143),  UINT8_C(   172),
         UINT8_C(    51),  UINT8_C(    77),  UINT8_C(   188),  UINT8_C(    81) },
      {  INT8_C(     2), -INT8_C(     3),  INT8_C(     1),  INT8_C(     7),
         INT8_C(     1), -INT8_C(     7), -INT8_C(     3), -INT8_C(     3),
        -INT8_C(     6), -INT8_C(     6),  INT8_C(     0), -INT8_C(     5),
        -INT8_C(     7),  INT8_C(     0),  INT8_C(     1), -INT8_C(     7) },
      {  UINT8_C(   192),  UINT8_C(    14),  UINT8_C(   255),  UINT8_C(   255),
         UINT8_C(   255),  UINT8_C(     0),  UINT8_C(     5),  UINT8_C(    23),
         UINT8_C(     1),  UINT8_C(     0),  UINT8_C(   143),  UINT8_C(     5),
         UINT8_C(     0),  UINT8_C(    77),  UINT8_C(   255),  UINT8_C(     1) } },
    { {  UINT8_C(   145),  UINT8_C(   198),  UINT8_C(    59),  UINT8_C(   229),
         UINT8_C(   193),  UINT8_C(    40),  UINT8_C(   202),  UINT8_C(    18),
         UINT8_C(   189),  UINT8_C(   226),  UINT8_C(    53),  UINT8_C(   190),
         UINT8_C(   171),  UINT8_C(   119),  UINT8_C(   184),  UINT8_C(   228) },
      { -INT8_C(     5),  INT8_C(     2),  INT8_C(     3), -INT8_C(     1),
        -INT8_C(     6),  INT8_C(     6),  INT8_C(     0),  INT8_C(     5),
         INT8_C(     5),  INT8_C(     1), -INT8_C(     3),  INT8_C(     1),
        -INT8_C(     5),  INT8_C(     7), -INT8_C(     4),  INT8_C(     4) },
      {  UINT8_C(     5),  UINT8_C(   255),  UINT8_C(   255),  UINT8_C(   115),
         UINT8_C(     3),  UINT8_C(   255),  UINT8_C(   202),  UINT8_C(   255),
         UINT8_C(   255),  UINT8_C(   255),  UINT8_C(     7),  UINT8_C(   255),
         UINT8_C(     5),  UINT8_C(   255),  UINT8_C(    12),  UINT8_C(   255) } },
    { {  UINT8_C(   144),  UINT8_C(    70),  UINT8_C(    74),  UINT8_C(     4),
         UINT8_C(   109),  UINT8_C(   142),  UINT8_C(   116),  UINT8_C(   159),
         UINT8_C(   142),  UINT8_C(    25),  UINT8_C(   177),  UINT8_C(   177),
         UINT8_C(    76),  UINT8_C(   150),  UINT8_C(    86),  UINT8_C(   238) },
      {  INT8_C(     0), -INT8_C(     3),  INT8_C(     3), -INT8_C(     3),
         INT8_C(     5), -INT8_C(     4), -INT8_C(     3), -INT8_C(     2),
         INT8_C(     3), -INT8_C(     4), -INT8_C(     3),  INT8_C(     3),
         INT8_C(     1),  INT8_C(     5),  INT8_C(     7),  INT8_C(     5) },
      {  UINT8_C(   144),  UINT8_C(     9),  UINT8_C(   255),  UINT8_C(     1),
         UINT8_C(   255),  UINT8_C(     9),  UINT8_C(    15),  UINT8_C(    40),
         UINT8_C(   255),  UINT8_C(     2),  UINT8_C(    22),  UINT8_C(   255),
         UINT8_C(   152),  UINT8_C(   255),  UINT8_C(   255),  UINT8_C(   255) } },
    { {  UINT8_C(   199),  UINT8_C(   104),  UINT8_C(    74),  UINT8_C(    67),
         UINT8_C(   128),  UINT8_C(   140),  UINT8_C(    56),  UINT8_C(   104),
         UINT8_C(    88),  UINT8_C(   100),  UINT8_C(   110),  UINT8_C(    42),
         UINT8_C(   123),  UINT8_C(   111),  UINT8_C(   252),  UINT8_C(   156) },
      { -INT8_C(     8),  INT8_C(     0), -INT8_C(     7), -INT8_C(     1),
        -INT8_C(     8),  INT8_C(     4), -INT8_C(     5),  INT8_C(     4),
        -INT8_C(     2),  INT8_C(     5),  INT8_C(     0), -INT8_C(     6),
         INT8_C(     5), -INT8_C(     8),  INT8_C(     8),  INT8_C(     5) },
      {  UINT8_C(     1),  UINT8_C(   104),  UINT8_C(     1),  UINT8_C(    34),
         UINT8_C(     1),  UINT8_C(   255),  UINT8_C(     2),  UINT8_C(   255),
         UINT8_C(    22),  UINT8_C(   255),  UINT8_C(   110),  UINT8_C(     1),
         UINT8_C(   255),  UINT8_C(     0),  UINT8_C(   255),  UINT8_C(   255) } },
    { {  UINT8_C(   140),  UINT8_C(    24),  UINT8_C(    20),  UINT8_C(   116),
         UINT8_C(     5),  UINT8_C(   138),  UINT8_C(    42),  UINT8_C(   115),
         UINT8_C(   111),  UINT8_C(   129),  UINT8_C(   142),  UINT8_C(   213),
         UINT8_C(   155),  UINT8_C(   130),  UINT8_C(   150),  UINT8_C(   231) },
      {  INT8_C(     2), -INT8_C(     8), -INT8_C(     8), -INT8_C(     6),
         INT8_C(     1), -INT8_C(     5),  INT8_C(     1),  INT8_C(     2),
        -INT8_C(     1), -INT8_C(     2),  INT8_C(     5),  INT8_C(     5),
        -INT8_C(     3),  INT8_C(     6), -INT8_C(     1), -INT8_C(     6) },
      {  UINT8_C(   255),  UINT8_C(     0),  UINT8_C(     0),  UINT8_C(     2),
         UINT8_C(    10),  UINT8_C(     4),  UINT8_C(    84),  UINT8_C(   255),
         UINT8_C(    56),  UINT8_C(    32),  UINT8_C(   255),  UINT8_C(   255),
         UINT8_C(    19),  UINT8_C(   255),  UINT8_C(    75),  UINT8_C(     4) } },
    { {  UINT8_C(   123),  UINT8_C(    36),  UINT8_C(    41),  UINT8_C(   105),
         UINT8_C(    46),  UINT8_C(    64),  UINT8_C(   195),  UINT8_C(   242),
         UINT8_C(   155),  UINT8_C(   176),  UINT8_C(   255),  UINT8_C(   148),
         UINT8_C(    51),  UINT8_C(    35),  UINT8_C(   168),  UINT8_C(   226) },
      {  INT8_C(     0),  INT8_C(     6),  INT8_C(     5), -INT8_C(     6),
         INT8_C(     1), -INT8_C(     5), -INT8_C(     4),  INT8_C(     2),
         INT8_C(     6),  INT8_C(     3), -INT8_C(     1),  INT8_C(     7),
        -INT8_C(     2), -INT8_C(     2), -INT8_C(     1),  INT8_C(     4) },
      {  UINT8_C(   123),  UINT8_C(   255),  UINT8_C(   255),  UINT8_C(     2),
         UINT8_C(    92),  UINT8_C(     2),  UINT8_C(    12),  UINT8_C(   255),
         UINT8_C(   255),  UINT8_C(   255),  UINT8_C(   128),  UINT8_C(   255),
         UINT8_C(    13),  UINT8_C(     9),  UINT8_C(    84),  UINT8_C(   255) } },
    { {  UINT8_C(   209),  UINT8_C(   246),  UINT8_C(   234),  UINT8_C(   223),
         UINT8_C(   203),  UINT8_C(   186),  UINT8_C(   139),  UINT8_C(   148),
         UINT8_C(   180),  UINT8_C(    18),  UINT8_C(     7),  UINT8_C(   172),
         UINT8_C(   225),  UINT8_C(    26),  UINT8_C(   149),  UINT8_C(    28) },
      {  INT8_C(     5), -INT8_C(     1),  INT8_C(     4),  INT8_C(     1),
         INT8_C(     1),  INT8_C(     1),  INT8_C(     7), -INT8_C(     5),
        -INT8_C(     2),  INT8_C(     4), -INT8_C(     7),  INT8_C(     1),
        -INT8_C(     3), -INT8_C(     2),  INT8_C(     7),  INT8_C(     0) },
      {  UINT8_C(   255),  UINT8_C(   123),  UINT8_C(   255),  UINT8_C(   255),
         UINT8_C(   255),  UINT8_C(   255),  UINT8_C(   255),  UINT8_C(     5),
         UINT8_C(    45),  UINT8_C(   255),  UINT8_C(     0),  UINT8_C(   255),
         UINT8_C(    28),  UINT8_C(     7),  UINT8_C(   255),  UINT8_C(    28) } },
    { {  UINT8_C(   186),  UINT8_C(   147),  UINT8_C(    83),  UINT8_C(   114),
         UINT8_C(   130),  UINT8_C(    80),  UINT8_C(   252),  UINT8_C(    63),
         UINT8_C(   137),  UINT8_C(   214),  UINT8_C(   119),  UINT8_C(   227),
         UINT8_C(    29),  UINT8_C(   181),  UINT8_C(   148),  UINT8_C(    21) },
      {  INT8_C(     2),  INT8_C(     0),  INT8_C(     4),  INT8_C(     1),
         INT8_C(     8), -INT8_C(     6),  INT8_C(     3),  INT8_C(     6),
         INT8_C(     5), -INT8_C(     2), -INT8_C(     6),  INT8_C(     0),
         INT8_C(     6),  INT8_C(     5),  INT8_C(     0),  INT8_C(     7) },
      {  UINT8_C(   255),  UINT8_C(   147),  UINT8_C(   255),  UINT8_C(   228),
         UINT8_C(   255),  UINT8_C(     1),  UINT8_C(   255),  UINT8_C(   255),
         UINT8_C(   255),  UINT8_C(    54),  UINT8_C(     2),  UINT8_C(   227),
         UINT8_C(   255),  UINT8_C(   255),  UINT8_C(   148),  UINT8_C(   255) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint8x16_t a = simde_vld1q_u8(test_vec[i].a);
    simde_int8x16_t b = simde_vld1q_s8(test_vec[i].b);
    simde_uint8x16_t r = simde_vqrshlq_u8(a, b);

    simde_test_arm_neon_assert_equal_u8x16(r, simde_vld1q_u8(test_vec[i].r));
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint8x16_t a = simde_test_arm_neon_random_u8x16();
    simde_int8x16_t b = simde_test_arm_neon_random_i8x16();
    simde_uint8x16_t r = simde_vqrshlq_u8(a, b);

    simde_test_arm_neon_write_u8x16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i8x16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u8x16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vqrshlq_u16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    uint16_t a[8];
    int16_t b[8];
    uint16_t r[8];
  } test_vec[] = {
    { {  UINT16_C(   61506),  UINT16_C(   19083),  UINT16_C(   60908),  UINT16_C(   40546),
         UINT16_C(   29927),  UINT16_C(   62112),  UINT16_C(   60795),  UINT16_C(   39381) },
      {  INT16_C(       5), -INT16_C(       9), -INT16_C(       2), -INT16_C(       8),
        -INT16_C(       7), -INT16_C(       4),  INT16_C(       4), -INT16_C(       9) },
      {  UINT16_C(   65535),  UINT16_C(      37),  UINT16_C(   15227),  UINT16_C(     158),
         UINT16_C(     234),  UINT16_C(    3882),  UINT16_C(   65535),  UINT16_C(      77) } },
    { {  UINT16_C(   52703),  UINT16_C(   30753),  UINT16_C(   21922),  UINT16_C(   13244),
         UINT16_C(   23660),  UINT16_C(   33835),  UINT16_C(    6910),  UINT16_C(   21793) },
      { -INT16_C(      11), -INT16_C(      12),  INT16_C(      15),  INT16_C(      11),
         INT16_C(       6), -INT16_C(       1), -INT16_C(      16), -INT16_C(       1) },
      {  UINT16_C(      26),  UINT16_C(       8),  UINT16_C(   65535),  UINT16_C(   65535),
         UINT16_C(   65535),  UINT16_C(   16918),  UINT16_C(       0),  UINT16_C(   10897) } },
    { {  UINT16_C(   49424),  UINT16_C(    1272),  UINT16_C(   11256),  UINT16_C(   15451),
         UINT16_C(   38439),  UINT16_C(   22519),  UINT16_C(   53624),  UINT16_C(   56406) },
      { -INT16_C(      11), -INT16_C(       3),  INT16_C(      10), -INT16_C(      10),
         INT16_C(      12),  INT16_C(       3),  INT16_C(       9),  INT16_C(       6) },
      {  UINT16_C(      24),  UINT16_C(     159),  UINT16_C(   65535),  UINT16_C(      15),
         UINT16_C(   65535),  UINT16_C(   65535),  UINT16_C(   65535),  UINT16_C(   65535) } },
    { {  UINT16_C(   34648),  UINT16_C(   38658),  UINT16_C(   18124),  UINT16_C(   29610),
         UINT16_C(   34257),  UINT16_C(   23288),  UINT16_C(    2479),  UINT16_C(   51223) },
      { -INT16_C(      11), -INT16_C(       3),  INT16_C(       4), -INT16_C(      10),
         INT16_C(       7), -INT16_C(       7),  INT16_C(      10),  INT16_C(       5) },
      {  UINT16_C(      17),  UINT16_C(    4832),  UINT16_C(   65535),  UINT16_C(      29),
         UINT16_C(   65535),  UINT16_C(     182),  UINT16_C(   65535),  UINT16_C(   65535) } },
    { {  UINT16_C(   34910),  UINT16_C(   29561),  UINT16_C(   57208),  UINT16_C(     321),
         UINT16_C(   59682),  UINT16_C(   10906),  UINT16_C(   56329),  UINT16_C(     122) },
      { -INT16_C(       9),  INT16_C(       4), -INT16_C(      16), -INT16_C(       1),
         INT16_C(      10), -INT16_C(       7), -INT16_C(       1), -INT16_C(       1) },
      {  UINT16_C(      68),  UINT16_C(   65535),  UINT16_C(       1),  UINT16_C(     161),
         UINT16_C(   65535),  UINT16_C(      85),  UINT16_C(   28165),  UINT16_C(      61) } },
    { {  UINT16_C(   17592),  UINT16_C(     628),  UINT16_C(   30585),  UINT16_C(   18746),
         UINT16_C(    2909),  UINT16_C(    4209),  UINT16_C(    6780),  UINT16_C(   29795) },
      { -INT16_C(      12),  INT16_C(       9), -INT16_C(      11), -INT16_C(       9),
         INT16_C(       8),  INT16_C(       0),  INT16_C(       1),  INT16_C(       7) },
      {  UINT16_C(       4),  UINT16_C(   65535),  UINT16_C(      15),  UINT16_C(      37),
         UINT16_C(   65535),  UINT16_C(    4209),  UINT16_C(   13560),  UINT16_C(   65535) } },
    { {  UINT16_C(   27761),  UINT16_C(   46906),  UINT16_C(   25315),  UINT16_C(   54517),
         UINT16_C(    3930),  UINT16_C(   38934),  UINT16_C(   33158),  UINT16_C(   15978) },
      { -INT16_C(       5),  INT16_C(       3), -INT16_C(      14), -INT16_C(       8),
        -INT16_C(      13),  INT16_C(      16), -INT16_C(       1), -INT16_C(      15) },
      {  UINT16_C(     868),  UINT16_C(   65535),  UINT16_C(       2),  UINT16_C(     213),
         UINT16_C(       0),  UINT16_C(   65535),  UINT16_C(   16579),  UINT16_C(       0) } },
    { {  UINT16_C(   52730),  UINT16_C(   21619),  UINT16_C(   31344),  UINT16_C(   36500),
         UINT16_C(   25393),  UINT16_C(   44945),  UINT16_C(   18048),  UINT16_C(   31672) },
      { -INT16_C(       6), -INT16_C(       9), -INT16_C(       7),  INT16_C(       1),
         INT16_C(       8), -INT16_C(       5),  INT16_C(       0),  INT16_C(       7) },
      {  UINT16_C(     824),  UINT16_C(      42),  UINT16_C(     245),  UINT16_C(   65535),
         UINT16_C(   65535),  UINT16_C(    1405),  UINT16_C(   18048),  UINT16_C(   65535) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint16x8_t a = simde_vld1q_u16(test_vec[i].a);
    simde_int16x8_t b = simde_vld1q_s16(test_vec[i].b);
    simde_uint16x8_t r = simde_vqrshlq_u16(a, b);
    simde_test_arm_neon_assert_equal_u16x8(r, simde_vld1q_u16(test_vec[i].r));
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint16x8_t a = simde_test_arm_neon_random_u16x8();
    simde_int16x8_t b = simde_test_arm_neon_random_i16x8();
    simde_uint16x8_t r = simde_vqrshlq_u16(a, b);

    simde_test_arm_neon_write_u16x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i16x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u16x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vqrshlq_u32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    uint32_t a[4];
    int32_t b[4];
    uint32_t r[4];
  } test_vec[] = {
    { {  UINT32_C(  1500975547),  UINT32_C(  2108068888),  UINT32_C(  2683398431),  UINT32_C(   367549241) },
      {  INT32_C(          32),  INT32_C(           4),  INT32_C(          12),  INT32_C(           7) },
      {  UINT32_C(  4294967295),  UINT32_C(  4294967295),  UINT32_C(  4294967295),  UINT32_C(  4294967295) } },
    { {  UINT32_C(  3541445283),  UINT32_C(  2942869736),  UINT32_C(  2791986498),  UINT32_C(  3847214939) },
      { -INT32_C(          15), -INT32_C(           2),  INT32_C(           3), -INT32_C(           5) },
      {  UINT32_C(      108076),  UINT32_C(   735717434),  UINT32_C(  4294967295),  UINT32_C(   120225467) } },
    { {  UINT32_C(  2758985098),  UINT32_C(  1301200120),  UINT32_C(  2500937308),  UINT32_C(  1482943544) },
      { -INT32_C(          15),  INT32_C(          26),  INT32_C(           4), -INT32_C(          31) },
      {  UINT32_C(       84198),  UINT32_C(  4294967295),  UINT32_C(  4294967295),  UINT32_C(           1) } },
    { {  UINT32_C(  1695104610),  UINT32_C(  2154042730),  UINT32_C(  1247813531),  UINT32_C(   539880566) },
      { -INT32_C(           5), -INT32_C(          21),  INT32_C(          12),  INT32_C(           6) },
      {  UINT32_C(    52972019),  UINT32_C(        1027),  UINT32_C(  4294967295),  UINT32_C(  4294967295) } },
    { {  UINT32_C(  4087492662),  UINT32_C(   442729018),  UINT32_C(   640768667),  UINT32_C(  1635123388) },
      {  INT32_C(           7), -INT32_C(           3),  INT32_C(           7),  INT32_C(          31) },
      {  UINT32_C(  4294967295),  UINT32_C(    55341127),  UINT32_C(  4294967295),  UINT32_C(  4294967295) } },
    { {  UINT32_C(  4260977946),  UINT32_C(  2996827211),  UINT32_C(   864415427),  UINT32_C(  4108108071) },
      { -INT32_C(          16),  INT32_C(           7),  INT32_C(          10), -INT32_C(          27) },
      {  UINT32_C(       65017),  UINT32_C(  4294967295),  UINT32_C(  4294967295),  UINT32_C(          31) } },
    { {  UINT32_C(  4249729102),  UINT32_C(  3434311192),  UINT32_C(  2916969933),  UINT32_C(  1847713867) },
      { -INT32_C(          31), -INT32_C(          15), -INT32_C(          21), -INT32_C(          21) },
      {  UINT32_C(           2),  UINT32_C(      104807),  UINT32_C(        1391),  UINT32_C(         881) } },
    { {  UINT32_C(  2544619547),  UINT32_C(  3247194592),  UINT32_C(  2391939879),  UINT32_C(  2988854179) },
      {  INT32_C(           5),  INT32_C(           5),  INT32_C(          30), -INT32_C(          29) },
      {  UINT32_C(  4294967295),  UINT32_C(  4294967295),  UINT32_C(  4294967295),  UINT32_C(           6) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint32x4_t a = simde_vld1q_u32(test_vec[i].a);
    simde_int32x4_t b = simde_vld1q_s32(test_vec[i].b);
    simde_uint32x4_t r = simde_vqrshlq_u32(a, b);

    simde_test_arm_neon_assert_equal_u32x4(r, simde_vld1q_u32(test_vec[i].r));
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint32x4_t a = simde_test_arm_neon_random_u32x4();
    simde_int32x4_t b = simde_test_arm_neon_random_i32x4();
    simde_uint32x4_t r = simde_vqrshlq_u32(a, b);

    simde_test_arm_neon_write_u32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vqrshlq_u64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  struct {
    uint64_t a[2];
    int64_t b[2];
    uint64_t r[2];
  } test_vec[] = {
    { {  UINT64_C(12257908650438209556),  UINT64_C(  734662789645664798) },
      { -INT64_C(                  53), -INT64_C(                  24) },
      {  UINT64_C(                1361),  UINT64_C(         43789314607) } },
    { {  UINT64_C(15401328157929644581),  UINT64_C(11927978306316211307) },
      {  INT64_C(                  54), -INT64_C(                  26) },
      {  UINT64_C(18446744073709551615),  UINT64_C(        177740727459) } },
    { {  UINT64_C( 9806006901024356755),  UINT64_C( 2220988353704575177) },
      {  INT64_C(                  18),  INT64_C(                  48) },
      {  UINT64_C(18446744073709551615),  UINT64_C(18446744073709551615) } },
    { {  UINT64_C(17911317278255258189),  UINT64_C(16943905161406011814) },
      {  INT64_C(                  60),  INT64_C(                   1) },
      {  UINT64_C(18446744073709551615),  UINT64_C(18446744073709551615) } },
    { {  UINT64_C( 2887718461795313073),  UINT64_C(17639433086009224754) },
      {  INT64_C(                  32),  INT64_C(                  23) },
      {  UINT64_C(18446744073709551615),  UINT64_C(18446744073709551615) } },
    { {  UINT64_C( 5907043747386205374),  UINT64_C(11542381187061170644) },
      {  INT64_C(                  57), -INT64_C(                  15) },
      {  UINT64_C(18446744073709551615),  UINT64_C(     352245519624670) } },
    { {  UINT64_C(15325393461537196969),  UINT64_C(16407202451519969415) },
      { -INT64_C(                  15), -INT64_C(                  50) },
      {  UINT64_C(     467693892258826),  UINT64_C(               14573) } },
    { {  UINT64_C(17890801295880430688),  UINT64_C(12355916188791687384) },
      { -INT64_C(                  38), -INT64_C(                  25) },
      {  UINT64_C(            65086356),  UINT64_C(        368234997654) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint64x2_t a = simde_vld1q_u64(test_vec[i].a);
    simde_int64x2_t b = simde_vld1q_s64(test_vec[i].b);
    simde_uint64x2_t r = simde_vqrshlq_u64(a, b);
    simde_test_arm_neon_assert_equal_u64x2(r, simde_vld1q_u64(test_vec[i].r));
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint64x2_t a = simde_test_arm_neon_random_u64x2();
    simde_int64x2_t b = simde_test_arm_neon_random_i64x2();
    simde_uint64x2_t r = simde_vqrshlq_u64(a, b);

    simde_test_arm_neon_write_u64x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i64x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}


SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(vqrshlb_s8)
SIMDE_TEST_FUNC_LIST_ENTRY(vqrshlh_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vqrshls_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vqrshld_s64)
SIMDE_TEST_FUNC_LIST_ENTRY(vqrshlb_u8)
SIMDE_TEST_FUNC_LIST_ENTRY(vqrshlh_u16)
SIMDE_TEST_FUNC_LIST_ENTRY(vqrshls_u32)
SIMDE_TEST_FUNC_LIST_ENTRY(vqrshld_u64)

SIMDE_TEST_FUNC_LIST_ENTRY(vqrshl_s8)
SIMDE_TEST_FUNC_LIST_ENTRY(vqrshl_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vqrshl_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vqrshl_s64)
SIMDE_TEST_FUNC_LIST_ENTRY(vqrshl_u8)
SIMDE_TEST_FUNC_LIST_ENTRY(vqrshl_u16)
SIMDE_TEST_FUNC_LIST_ENTRY(vqrshl_u32)
SIMDE_TEST_FUNC_LIST_ENTRY(vqrshl_u64)

SIMDE_TEST_FUNC_LIST_ENTRY(vqrshlq_s8)
SIMDE_TEST_FUNC_LIST_ENTRY(vqrshlq_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vqrshlq_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vqrshlq_s64)
SIMDE_TEST_FUNC_LIST_ENTRY(vqrshlq_u8)
SIMDE_TEST_FUNC_LIST_ENTRY(vqrshlq_u16)
SIMDE_TEST_FUNC_LIST_ENTRY(vqrshlq_u32)
SIMDE_TEST_FUNC_LIST_ENTRY(vqrshlq_u64)
SIMDE_TEST_FUNC_LIST_END

#include "test-neon-footer.h"
