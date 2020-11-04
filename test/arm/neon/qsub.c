#define SIMDE_TEST_ARM_NEON_INSN qsub

#include "test-neon.h"
#include "../../../simde/arm/neon/qsub.h"

static int
test_simde_vqsubb_s8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int8_t a;
    int8_t b;
    int8_t r;
  } test_vec[] = {
    { -INT8_C(  66),
       INT8_C(  22),
      -INT8_C(  88) },
    { -INT8_C(  36),
      -INT8_C(  62),
       INT8_C(  26) },
    { -INT8_C(  75),
      -INT8_C(   8),
      -INT8_C(  67) },
    { -INT8_C(  35),
      -INT8_C( 127),
       INT8_C(  92) },
    {  INT8_C(  98),
      -INT8_C( 121),
           INT8_MAX },
    { -INT8_C( 118),
      -INT8_C(  45),
      -INT8_C(  73) },
    {  INT8_C(  39),
      -INT8_C(  30),
       INT8_C(  69) },
    {  INT8_C( 106),
       INT8_C( 114),
      -INT8_C(   8) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    int8_t r = simde_vqsubb_s8(test_vec[i].a, test_vec[i].b);

    simde_assert_equal_i8(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    int8_t a = simde_test_codegen_random_i8();
    int8_t b = simde_test_codegen_random_i8();
    int8_t r = simde_vqsubb_s8(a, b);

    simde_test_codegen_write_i8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_i8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vqsubh_s16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int16_t a;
    int16_t b;
    int16_t r;
  } test_vec[] = {
    {  INT16_C(  8855),
       INT16_C( 23221),
      -INT16_C( 14366) },
    { -INT16_C( 31415),
       INT16_C( 22921),
            INT16_MIN },
    {  INT16_C( 21653),
      -INT16_C( 22868),
            INT16_MAX },
    {  INT16_C( 29215),
      -INT16_C(  5971),
            INT16_MAX },
    { -INT16_C( 29041),
       INT16_C( 12520),
            INT16_MIN },
    {  INT16_C( 15481),
      -INT16_C( 24981),
            INT16_MAX },
    {  INT16_C( 16324),
       INT16_C( 12426),
       INT16_C(  3898) },
    { -INT16_C( 19369),
      -INT16_C(  4418),
      -INT16_C( 14951) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    int16_t r = simde_vqsubh_s16(test_vec[i].a, test_vec[i].b);

    simde_assert_equal_i16(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    int16_t a = simde_test_codegen_random_i16();
    int16_t b = simde_test_codegen_random_i16();
    int16_t r = simde_vqsubh_s16(a, b);

    simde_test_codegen_write_i16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_i16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vqsubs_s32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int32_t a;
    int32_t b;
    int32_t r;
  } test_vec[] = {
    {  INT32_C(   541619415),
      -INT32_C(  1904553479),
                 INT32_MAX },
    {  INT32_C(  1144333861),
       INT32_C(   657318552),
       INT32_C(   487015309) },
    { -INT32_C(   380168848),
       INT32_C(   361218641),
      -INT32_C(   741387489) },
    {  INT32_C(  1497698561),
      -INT32_C(  1656290106),
                 INT32_MAX },
    {  INT32_C(  1908248696),
      -INT32_C(  2013317279),
                 INT32_MAX },
    { -INT32_C(   171232163),
      -INT32_C(  2028079082),
       INT32_C(  1856846919) },
    {  INT32_C(  1584428045),
       INT32_C(   947124279),
       INT32_C(   637303766) },
    { -INT32_C(   812533495),
       INT32_C(   896326077),
      -INT32_C(  1708859572) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    int32_t r = simde_vqsubs_s32(test_vec[i].a, test_vec[i].b);

    simde_assert_equal_i32(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    int32_t a = simde_test_codegen_random_i32();
    int32_t b = simde_test_codegen_random_i32();
    int32_t r = simde_vqsubs_s32(a, b);

    simde_test_codegen_write_i32(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_i32(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vqsubd_s64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int64_t a;
    int64_t b;
    int64_t r;
  } test_vec[] = {
    { -INT64_C( 4660762299921454487),
       INT64_C( 2555741205718900186),
      -INT64_C( 7216503505640354673) },
    { -INT64_C( 1606107347560568762),
      -INT64_C( 8529776873063233618),
       INT64_C( 6923669525502664856) },
    { -INT64_C( 4219690419135232433),
       INT64_C( 4393874924657583298),
      -INT64_C( 8613565343792815731) },
    {  INT64_C( 2296675770715175957),
       INT64_C(  963254365123680437),
       INT64_C( 1333421405591495520) },
    {  INT64_C( 1810779477915906672),
       INT64_C( 1910910545548072786),
      -INT64_C(  100131067632166114) },
    {  INT64_C( 7059373367053204839),
       INT64_C( 1968519074954051974),
       INT64_C( 5090854292099152865) },
    { -INT64_C( 8090831914640470201),
      -INT64_C(  392555804137838482),
      -INT64_C( 7698276110502631719) },
    {  INT64_C( 1272207019781299354),
      -INT64_C( 4967287367727194550),
       INT64_C( 6239494387508493904) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    int64_t r = simde_vqsubd_s64(test_vec[i].a, test_vec[i].b);

    simde_assert_equal_i64(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    int64_t a = simde_test_codegen_random_i64();
    int64_t b = simde_test_codegen_random_i64();
    int64_t r = simde_vqsubd_s64(a, b);

    simde_test_codegen_write_i64(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_i64(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i64(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vqsubb_u8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint8_t a;
    uint8_t b;
    uint8_t r;
  } test_vec[] = {
    { UINT8_C(181),
      UINT8_C(134),
      UINT8_C( 47) },
    { UINT8_C( 90),
      UINT8_C(242),
      UINT8_C(  0) },
    { UINT8_C( 30),
      UINT8_C( 17),
      UINT8_C( 13) },
    { UINT8_C(130),
      UINT8_C(140),
      UINT8_C(  0) },
    { UINT8_C(185),
      UINT8_C( 90),
      UINT8_C( 95) },
    {    UINT8_MAX,
      UINT8_C( 76),
      UINT8_C(179) },
    { UINT8_C(182),
      UINT8_C(140),
      UINT8_C( 42) },
    { UINT8_C( 70),
      UINT8_C( 80),
      UINT8_C(  0) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    uint8_t r = simde_vqsubb_u8(test_vec[i].a, test_vec[i].b);

    simde_assert_equal_u8(r, test_vec[i].r);
  }
  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    uint8_t a = simde_test_codegen_random_u8();
    uint8_t b = simde_test_codegen_random_u8();
    uint8_t r = simde_vqsubb_u8(a, b);

    simde_test_codegen_write_u8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_u8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_u8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vqsubh_u16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint16_t a;
    uint16_t b;
    uint16_t r;
  } test_vec[] = {
    { UINT16_C( 6185),
      UINT16_C(46230),
      UINT16_C(    0) },
    { UINT16_C(16097),
      UINT16_C(11205),
      UINT16_C( 4892) },
    { UINT16_C( 6940),
      UINT16_C(36896),
      UINT16_C(    0) },
    { UINT16_C(12481),
      UINT16_C(30540),
      UINT16_C(    0) },
    { UINT16_C(42679),
      UINT16_C(54633),
      UINT16_C(    0) },
    { UINT16_C(60343),
      UINT16_C(29025),
      UINT16_C(31318) },
    { UINT16_C(24901),
      UINT16_C(64701),
      UINT16_C(    0) },
    { UINT16_C( 1261),
      UINT16_C( 5708),
      UINT16_C(    0) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    uint16_t r = simde_vqsubh_u16(test_vec[i].a, test_vec[i].b);

    simde_assert_equal_u16(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    uint16_t a = simde_test_codegen_random_u16();
    uint16_t b = simde_test_codegen_random_u16();
    uint16_t r = simde_vqsubh_u16(a, b);

    simde_test_codegen_write_u16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_u16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_u16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vqsubs_u32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint32_t a;
    uint32_t b;
    uint32_t r;
  } test_vec[] = {
    { UINT32_C(4274709276),
      UINT32_C(1026134049),
      UINT32_C(3248575227) },
    { UINT32_C(1825458859),
      UINT32_C( 836967034),
      UINT32_C( 988491825) },
    { UINT32_C(1996901824),
      UINT32_C(2129160248),
      UINT32_C(         0) },
    { UINT32_C(3061491401),
      UINT32_C(3335374506),
      UINT32_C(         0) },
    { UINT32_C(3401881513),
      UINT32_C(3523800615),
      UINT32_C(         0) },
    { UINT32_C(2990528056),
      UINT32_C(2967741168),
      UINT32_C(  22786888) },
    { UINT32_C(2821188207),
      UINT32_C( 455479378),
      UINT32_C(2365708829) },
    { UINT32_C(1624416438),
      UINT32_C( 270966630),
      UINT32_C(1353449808) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    uint32_t r = simde_vqsubs_u32(test_vec[i].a, test_vec[i].b);

    simde_assert_equal_u32(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    uint32_t a = simde_test_codegen_random_u32();
    uint32_t b = simde_test_codegen_random_u32();
    uint32_t r = simde_vqsubs_u32(a, b);

    simde_test_codegen_write_u32(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_u32(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_u32(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vqsubd_u64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint64_t a;
    uint64_t b;
    uint64_t r;
  } test_vec[] = {
    { UINT64_C( 1238739320754072374),
      UINT64_C(   97011640326909880),
      UINT64_C( 1141727680427162494) },
    { UINT64_C( 5044259803873509522),
      UINT64_C(12098582238282044015),
      UINT64_C(                   0) },
    { UINT64_C( 6602618604825723063),
      UINT64_C(11401245139197519269),
      UINT64_C(                   0) },
    { UINT64_C( 2428147951454118620),
      UINT64_C(15883594615127234645),
      UINT64_C(                   0) },
    { UINT64_C( 5664418551435195294),
      UINT64_C(15645153251035619443),
      UINT64_C(                   0) },
    { UINT64_C( 8752174285764075937),
      UINT64_C(16740633300212608081),
      UINT64_C(                   0) },
    { UINT64_C( 4690435028858552096),
      UINT64_C(18319764071651581286),
      UINT64_C(                   0) },
    { UINT64_C(14708693142388966017),
      UINT64_C( 3199125891678625587),
      UINT64_C(11509567250710340430) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    uint64_t r = simde_vqsubd_u64(test_vec[i].a, test_vec[i].b);

    simde_assert_equal_u64(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    uint64_t a = simde_test_codegen_random_u64();
    uint64_t b = simde_test_codegen_random_u64();
    uint64_t r = simde_vqsubd_u64(a, b);

    simde_test_codegen_write_u64(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_u64(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_u64(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vqsub_s8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int8_t a[8];
    int8_t b[8];
    int8_t r[8];
  } test_vec[] = {
    { {  INT8_C(  84), -INT8_C( 114), -INT8_C(  11),  INT8_C(  34),  INT8_C(  83),  INT8_C(  12),  INT8_C(  99), -INT8_C(  71) },
      { -INT8_C(  86),  INT8_C(  37),  INT8_C(  28),  INT8_C(   6),  INT8_C(   5),  INT8_C(  89),  INT8_C(   4), -INT8_C( 122) },
      {      INT8_MAX,      INT8_MIN, -INT8_C(  39),  INT8_C(  28),  INT8_C(  78), -INT8_C(  77),  INT8_C(  95),  INT8_C(  51) } },
    { { -INT8_C(  37),  INT8_C(  86),  INT8_C(  44),  INT8_C(  86),  INT8_C(  28),  INT8_C(  76),  INT8_C(  34),  INT8_C(  79) },
      { -INT8_C(  85),  INT8_C( 100), -INT8_C(  52), -INT8_C(  73), -INT8_C(   7),  INT8_C(  49), -INT8_C(  29),  INT8_C(  77) },
      {  INT8_C(  48), -INT8_C(  14),  INT8_C(  96),      INT8_MAX,  INT8_C(  35),  INT8_C(  27),  INT8_C(  63),  INT8_C(   2) } },
    { { -INT8_C(  65), -INT8_C(  40),  INT8_C( 111),  INT8_C(  19), -INT8_C(  28), -INT8_C(  46), -INT8_C(  52), -INT8_C( 114) },
      { -INT8_C(   9), -INT8_C(  23), -INT8_C( 107), -INT8_C(   4),  INT8_C(  66), -INT8_C( 103), -INT8_C( 125),  INT8_C(  29) },
      { -INT8_C(  56), -INT8_C(  17),      INT8_MAX,  INT8_C(  23), -INT8_C(  94),  INT8_C(  57),  INT8_C(  73),      INT8_MIN } },
    { { -INT8_C(  17), -INT8_C(  81),  INT8_C( 116),  INT8_C(  12), -INT8_C(   5), -INT8_C( 106),  INT8_C(  91), -INT8_C(  90) },
      { -INT8_C(   5),  INT8_C(  40),  INT8_C(  93), -INT8_C(  12),  INT8_C(  89),  INT8_C(  64),  INT8_C(  65),  INT8_C(  25) },
      { -INT8_C(  12), -INT8_C( 121),  INT8_C(  23),  INT8_C(  24), -INT8_C(  94),      INT8_MIN,  INT8_C(  26), -INT8_C( 115) } },
    { {  INT8_C(  24), -INT8_C(  80),  INT8_C(  44), -INT8_C(   3), -INT8_C( 126), -INT8_C(   8), -INT8_C( 117),  INT8_C( 122) },
      { -INT8_C(  31),  INT8_C(  32),  INT8_C( 118),  INT8_C(  35), -INT8_C(  70), -INT8_C(   7),  INT8_C(  65), -INT8_C(  87) },
      {  INT8_C(  55), -INT8_C( 112), -INT8_C(  74), -INT8_C(  38), -INT8_C(  56), -INT8_C(   1),      INT8_MIN,      INT8_MAX } },
    { { -INT8_C(  87), -INT8_C(  75), -INT8_C(  75), -INT8_C(  92),  INT8_C(  75),  INT8_C(  17),  INT8_C(  75),  INT8_C(  70) },
      {  INT8_C(  57), -INT8_C(  88),  INT8_C(  58), -INT8_C( 110), -INT8_C(  23),  INT8_C( 123), -INT8_C(  85),  INT8_C(   1) },
      {      INT8_MIN,  INT8_C(  13),      INT8_MIN,  INT8_C(  18),  INT8_C(  98), -INT8_C( 106),      INT8_MAX,  INT8_C(  69) } },
    { {  INT8_C(  43), -INT8_C(  41), -INT8_C(   2), -INT8_C(  82), -INT8_C(  48), -INT8_C( 118),  INT8_C(  40), -INT8_C(  79) },
      { -INT8_C(  86), -INT8_C(  98), -INT8_C(  43),  INT8_C( 100), -INT8_C( 104),  INT8_C(  22),  INT8_C(  14),  INT8_C(  65) },
      {      INT8_MAX,  INT8_C(  57),  INT8_C(  41),      INT8_MIN,  INT8_C(  56),      INT8_MIN,  INT8_C(  26),      INT8_MIN } },
    { { -INT8_C(  53), -INT8_C(  61), -INT8_C(  27),  INT8_C(  22), -INT8_C(  44),  INT8_C(  48),  INT8_C(  93),  INT8_C(  13) },
      { -INT8_C(  39), -INT8_C( 105), -INT8_C(  96), -INT8_C(  62),  INT8_C(  19),  INT8_C(  75), -INT8_C(  61),  INT8_C(  62) },
      { -INT8_C(  14),  INT8_C(  44),  INT8_C(  69),  INT8_C(  84), -INT8_C(  63), -INT8_C(  27),      INT8_MAX, -INT8_C(  49) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int8x8_t a = simde_vld1_s8(test_vec[i].a);
    simde_int8x8_t b = simde_vld1_s8(test_vec[i].b);
    simde_int8x8_t r = simde_vqsub_s8(a, b);

    simde_test_arm_neon_assert_equal_i8x8(r, simde_vld1_s8(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int8x8_t a = simde_test_arm_neon_random_i8x8();
    simde_int8x8_t b = simde_test_arm_neon_random_i8x8();
    simde_int8x8_t r = simde_vqsub_s8(a, b);

    simde_test_arm_neon_write_i8x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i8x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i8x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vqsub_s16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int16_t a[4];
    int16_t b[4];
    int16_t r[4];
  } test_vec[] = {
    { { -INT16_C( 15837), -INT16_C(  3092),  INT16_C(  5196), -INT16_C(  2396) },
      {  INT16_C( 31155),  INT16_C( 19291),  INT16_C( 27023),  INT16_C( 23180) },
      {       INT16_MIN, -INT16_C( 22383), -INT16_C( 21827), -INT16_C( 25576) } },
    { {  INT16_C( 28972),  INT16_C(   369), -INT16_C( 12638),  INT16_C( 31502) },
      { -INT16_C( 20891),  INT16_C( 30781),  INT16_C(   250),  INT16_C(  7607) },
      {       INT16_MAX, -INT16_C( 30412), -INT16_C( 12888),  INT16_C( 23895) } },
    { { -INT16_C( 23614),  INT16_C(  3600), -INT16_C( 19272),  INT16_C( 27397) },
      {  INT16_C( 24622), -INT16_C( 16970),  INT16_C( 17097), -INT16_C(  2792) },
      {       INT16_MIN,  INT16_C( 20570),       INT16_MIN,  INT16_C( 30189) } },
    { { -INT16_C( 30285),  INT16_C( 22006),  INT16_C(  1367), -INT16_C( 17200) },
      {  INT16_C(  3507), -INT16_C( 21195), -INT16_C(  5106), -INT16_C( 12086) },
      {       INT16_MIN,       INT16_MAX,  INT16_C(  6473), -INT16_C(  5114) } },
    { { -INT16_C(  9585),  INT16_C( 18399), -INT16_C(  7025), -INT16_C( 16974) },
      {  INT16_C( 26692),  INT16_C(  3450), -INT16_C( 27990),  INT16_C( 24066) },
      {       INT16_MIN,  INT16_C( 14949),  INT16_C( 20965),       INT16_MIN } },
    { { -INT16_C(  1765),  INT16_C( 29363), -INT16_C( 31490), -INT16_C( 20177) },
      {  INT16_C( 25745), -INT16_C( 24737),  INT16_C( 10576), -INT16_C(  8336) },
      { -INT16_C( 27510),       INT16_MAX,       INT16_MIN, -INT16_C( 11841) } },
    { {  INT16_C( 20228), -INT16_C( 27865), -INT16_C(  9933),  INT16_C( 30544) },
      { -INT16_C( 13758), -INT16_C(  4988), -INT16_C( 31139),  INT16_C( 30794) },
      {       INT16_MAX, -INT16_C( 22877),  INT16_C( 21206), -INT16_C(   250) } },
    { { -INT16_C(   385),  INT16_C( 32235),  INT16_C(  6786),  INT16_C(  4911) },
      { -INT16_C( 29058), -INT16_C( 12621),  INT16_C(  9143), -INT16_C( 17491) },
      {  INT16_C( 28673),       INT16_MAX, -INT16_C(  2357),  INT16_C( 22402) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x4_t a = simde_vld1_s16(test_vec[i].a);
    simde_int16x4_t b = simde_vld1_s16(test_vec[i].b);
    simde_int16x4_t r = simde_vqsub_s16(a, b);

    simde_test_arm_neon_assert_equal_i16x4(r, simde_vld1_s16(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int16x4_t a = simde_test_arm_neon_random_i16x4();
    simde_int16x4_t b = simde_test_arm_neon_random_i16x4();
    simde_int16x4_t r = simde_vqsub_s16(a, b);

    simde_test_arm_neon_write_i16x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i16x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i16x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vqsub_s32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int32_t a[2];
    int32_t b[2];
    int32_t r[2];
  } test_vec[] = {
    { { -INT32_C(  1521560462), -INT32_C(   266559826) },
      { -INT32_C(   958619543), -INT32_C(  1505876186) },
      { -INT32_C(   562940919),  INT32_C(  1239316360) } },
    { { -INT32_C(  1490867931), -INT32_C(  1044753853) },
      { -INT32_C(  1735430688),  INT32_C(    39009680) },
      {  INT32_C(   244562757), -INT32_C(  1083763533) } },
    { { -INT32_C(  1079533039), -INT32_C(  1448099008) },
      { -INT32_C(  1972401053), -INT32_C(   667898189) },
      {  INT32_C(   892868014), -INT32_C(   780200819) } },
    { {  INT32_C(   461329367), -INT32_C(  2032387674) },
      {  INT32_C(   924740775), -INT32_C(  1170574679) },
      { -INT32_C(   463411408), -INT32_C(   861812995) } },
    { {  INT32_C(  1417339156),  INT32_C(   150874533) },
      {  INT32_C(  1754426805), -INT32_C(   213859813) },
      { -INT32_C(   337087649),  INT32_C(   364734346) } },
    { { -INT32_C(  1139884266), -INT32_C(  1606227207) },
      { -INT32_C(     2662058), -INT32_C(   407236141) },
      { -INT32_C(  1137222208), -INT32_C(  1198991066) } },
    { { -INT32_C(  1740950285),  INT32_C(   329267549) },
      { -INT32_C(  1032113241),  INT32_C(   196459765) },
      { -INT32_C(   708837044),  INT32_C(   132807784) } },
    { {  INT32_C(  1959248763),  INT32_C(    68422318) },
      {  INT32_C(  1040510059), -INT32_C(   265961731) },
      {  INT32_C(   918738704),  INT32_C(   334384049) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x2_t a = simde_vld1_s32(test_vec[i].a);
    simde_int32x2_t b = simde_vld1_s32(test_vec[i].b);
    simde_int32x2_t r = simde_vqsub_s32(a, b);

    simde_test_arm_neon_assert_equal_i32x2(r, simde_vld1_s32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int32x2_t a = simde_test_arm_neon_random_i32x2();
    simde_int32x2_t b = simde_test_arm_neon_random_i32x2();
    simde_int32x2_t r = simde_vqsub_s32(a, b);

    simde_test_arm_neon_write_i32x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i32x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i32x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vqsub_s64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int64_t a[1];
    int64_t b[1];
    int64_t r[1];
  } test_vec[] = {
    { {  INT64_C( 4711373902919000306) },
      {  INT64_C( 1539590720065887836) },
      {  INT64_C( 3171783182853112470) } },
    { { -INT64_C( 7408528940881795972) },
      { -INT64_C( 2055615115581508726) },
      { -INT64_C( 5352913825300287246) } },
    { { -INT64_C( 8775099862162996899) },
      {  INT64_C( 8152136498302892915) },
      {                     INT64_MIN } },
    { { -INT64_C( 3088965443652965287) },
      {  INT64_C( 5967787332997085437) },
      { -INT64_C( 9056752776650050724) } },
    { {  INT64_C(  902832744462615767) },
      { -INT64_C( 1431516226032935236) },
      {  INT64_C( 2334348970495551003) } },
    { { -INT64_C( 8860668954151764504) },
      {  INT64_C( 1428843107972310669) },
      {                     INT64_MIN } },
    { {  INT64_C( 6552345614570757449) },
      {  INT64_C( 3132303308971771897) },
      {  INT64_C( 3420042305598985552) } },
    { {  INT64_C( 1006667218594753771) },
      { -INT64_C(  352578529519506228) },
      {  INT64_C( 1359245748114259999) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int64x1_t a = simde_vld1_s64(test_vec[i].a);
    simde_int64x1_t b = simde_vld1_s64(test_vec[i].b);
    simde_int64x1_t r = simde_vqsub_s64(a, b);

    simde_test_arm_neon_assert_equal_i64x1(r, simde_vld1_s64(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int64x1_t a = simde_test_arm_neon_random_i64x1();
    simde_int64x1_t b = simde_test_arm_neon_random_i64x1();
    simde_int64x1_t r = simde_vqsub_s64(a, b);

    simde_test_arm_neon_write_i64x1(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i64x1(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i64x1(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vqsub_u8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint8_t a[8];
    uint8_t b[8];
    uint8_t r[8];
  } test_vec[] = {
    { { UINT8_C(128), UINT8_C( 47), UINT8_C(222), UINT8_C( 30), UINT8_C(202), UINT8_C(204), UINT8_C(121), UINT8_C(196) },
      { UINT8_C(212), UINT8_C(132), UINT8_C( 80), UINT8_C( 23), UINT8_C(178), UINT8_C(201), UINT8_C( 66), UINT8_C(157) },
      { UINT8_C(  0), UINT8_C(  0), UINT8_C(142), UINT8_C(  7), UINT8_C( 24), UINT8_C(  3), UINT8_C( 55), UINT8_C( 39) } },
    { { UINT8_C(181), UINT8_C(160), UINT8_C( 16), UINT8_C( 53), UINT8_C(  6), UINT8_C(  8), UINT8_C( 67), UINT8_C(211) },
      { UINT8_C(117), UINT8_C(210), UINT8_C(219), UINT8_C( 39), UINT8_C( 54), UINT8_C(247), UINT8_C( 34), UINT8_C(182) },
      { UINT8_C( 64), UINT8_C(  0), UINT8_C(  0), UINT8_C( 14), UINT8_C(  0), UINT8_C(  0), UINT8_C( 33), UINT8_C( 29) } },
    { { UINT8_C( 38), UINT8_C(  0), UINT8_C(213), UINT8_C(241), UINT8_C(205), UINT8_C( 78), UINT8_C(181), UINT8_C(161) },
      { UINT8_C(210), UINT8_C(  5), UINT8_C(184), UINT8_C(132), UINT8_C(206), UINT8_C(250), UINT8_C( 33), UINT8_C(131) },
      { UINT8_C(  0), UINT8_C(  0), UINT8_C( 29), UINT8_C(109), UINT8_C(  0), UINT8_C(  0), UINT8_C(148), UINT8_C( 30) } },
    { { UINT8_C(154), UINT8_C( 49), UINT8_C(185), UINT8_C(160), UINT8_C( 58), UINT8_C(252), UINT8_C(115), UINT8_C(175) },
      { UINT8_C(206), UINT8_C( 79), UINT8_C(214), UINT8_C(  4), UINT8_C( 70), UINT8_C(248), UINT8_C(187), UINT8_C(108) },
      { UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(156), UINT8_C(  0), UINT8_C(  4), UINT8_C(  0), UINT8_C( 67) } },
    { { UINT8_C(249), UINT8_C(144), UINT8_C( 93), UINT8_C(198), UINT8_C(222), UINT8_C( 18), UINT8_C(103), UINT8_C(176) },
      { UINT8_C( 24), UINT8_C( 31), UINT8_C( 53), UINT8_C(230), UINT8_C( 25), UINT8_C( 86), UINT8_C(106), UINT8_C(179) },
      { UINT8_C(225), UINT8_C(113), UINT8_C( 40), UINT8_C(  0), UINT8_C(197), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0) } },
    { { UINT8_C(136), UINT8_C( 35), UINT8_C( 83), UINT8_C(194), UINT8_C( 31), UINT8_C(199), UINT8_C(113), UINT8_C(237) },
      { UINT8_C( 22), UINT8_C( 71), UINT8_C(242), UINT8_C( 92), UINT8_C( 63), UINT8_C(173), UINT8_C(200), UINT8_C( 56) },
      { UINT8_C(114), UINT8_C(  0), UINT8_C(  0), UINT8_C(102), UINT8_C(  0), UINT8_C( 26), UINT8_C(  0), UINT8_C(181) } },
    { { UINT8_C( 61), UINT8_C( 38), UINT8_C(254), UINT8_C( 27), UINT8_C( 56), UINT8_C(101), UINT8_C(203), UINT8_C( 80) },
      { UINT8_C(132), UINT8_C(  0), UINT8_C( 55), UINT8_C(157), UINT8_C( 87), UINT8_C(161), UINT8_C( 80), UINT8_C(223) },
      { UINT8_C(  0), UINT8_C( 38), UINT8_C(199), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(123), UINT8_C(  0) } },
    { { UINT8_C(196), UINT8_C(164), UINT8_C(161), UINT8_C(227), UINT8_C(107), UINT8_C( 18), UINT8_C(208), UINT8_C(129) },
      { UINT8_C( 89), UINT8_C(194), UINT8_C(221), UINT8_C(152), UINT8_C(111), UINT8_C(165), UINT8_C(209), UINT8_C(172) },
      { UINT8_C(107), UINT8_C(  0), UINT8_C(  0), UINT8_C( 75), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint8x8_t a = simde_vld1_u8(test_vec[i].a);
    simde_uint8x8_t b = simde_vld1_u8(test_vec[i].b);
    simde_uint8x8_t r = simde_vqsub_u8(a, b);

    simde_test_arm_neon_assert_equal_u8x8(r, simde_vld1_u8(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint8x8_t a = simde_test_arm_neon_random_u8x8();
    simde_uint8x8_t b = simde_test_arm_neon_random_u8x8();
    simde_uint8x8_t r = simde_vqsub_u8(a, b);

    simde_test_arm_neon_write_u8x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u8x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u8x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vqsub_u16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint16_t a[4];
    uint16_t b[4];
    uint16_t r[4];
  } test_vec[] = {
    { { UINT16_C(53195), UINT16_C( 1223), UINT16_C(37685), UINT16_C(47444) },
      { UINT16_C(35731), UINT16_C(59991), UINT16_C(42796), UINT16_C(61641) },
      { UINT16_C(17464), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0) } },
    { { UINT16_C(27211), UINT16_C(46803), UINT16_C(42108), UINT16_C(54583) },
      { UINT16_C( 5222), UINT16_C(54894), UINT16_C(16314), UINT16_C(34178) },
      { UINT16_C(21989), UINT16_C(    0), UINT16_C(25794), UINT16_C(20405) } },
    { { UINT16_C(18958), UINT16_C(17289), UINT16_C(57053), UINT16_C(28925) },
      { UINT16_C(21609), UINT16_C(38491), UINT16_C( 9467), UINT16_C(18310) },
      { UINT16_C(    0), UINT16_C(    0), UINT16_C(47586), UINT16_C(10615) } },
    { { UINT16_C(23183), UINT16_C( 3069), UINT16_C(13822), UINT16_C(25825) },
      { UINT16_C(20297), UINT16_C(  826), UINT16_C(48526), UINT16_C(40073) },
      { UINT16_C( 2886), UINT16_C( 2243), UINT16_C(    0), UINT16_C(    0) } },
    { { UINT16_C( 4615), UINT16_C(58592), UINT16_C(56816), UINT16_C(23124) },
      { UINT16_C(44849), UINT16_C(11504), UINT16_C(30420), UINT16_C(25459) },
      { UINT16_C(    0), UINT16_C(47088), UINT16_C(26396), UINT16_C(    0) } },
    { { UINT16_C(29136), UINT16_C(52846), UINT16_C(20390), UINT16_C(61235) },
      { UINT16_C(28062), UINT16_C(11507), UINT16_C(31786), UINT16_C(12745) },
      { UINT16_C( 1074), UINT16_C(41339), UINT16_C(    0), UINT16_C(48490) } },
    { { UINT16_C(43406), UINT16_C(32533), UINT16_C(27270), UINT16_C(47065) },
      { UINT16_C(51481), UINT16_C(60899), UINT16_C(22335), UINT16_C( 4176) },
      { UINT16_C(    0), UINT16_C(    0), UINT16_C( 4935), UINT16_C(42889) } },
    { { UINT16_C(49096), UINT16_C(28382), UINT16_C( 4366), UINT16_C(44381) },
      { UINT16_C(20607), UINT16_C(43481), UINT16_C(41676), UINT16_C(23515) },
      { UINT16_C(28489), UINT16_C(    0), UINT16_C(    0), UINT16_C(20866) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint16x4_t a = simde_vld1_u16(test_vec[i].a);
    simde_uint16x4_t b = simde_vld1_u16(test_vec[i].b);
    simde_uint16x4_t r = simde_vqsub_u16(a, b);
    simde_test_arm_neon_assert_equal_u16x4(r, simde_vld1_u16(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint16x4_t a = simde_test_arm_neon_random_u16x4();
    simde_uint16x4_t b = simde_test_arm_neon_random_u16x4();
    simde_uint16x4_t r = simde_vqsub_u16(a, b);

    simde_test_arm_neon_write_u16x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u16x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u16x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vqsub_u32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint32_t a[2];
    uint32_t b[2];
    uint32_t r[2];
  } test_vec[] = {
    { { UINT32_C(3520786507), UINT32_C(1955115866) },
      { UINT32_C(3143724156), UINT32_C(2345382595) },
      { UINT32_C( 377062351), UINT32_C(         0) } },
    { { UINT32_C(2147068529), UINT32_C( 975984315) },
      { UINT32_C(1944323751), UINT32_C(4107190184) },
      { UINT32_C( 202744778), UINT32_C(         0) } },
    { { UINT32_C( 180725935), UINT32_C(3615379035) },
      { UINT32_C(2106843066), UINT32_C(  34102929) },
      { UINT32_C(         0), UINT32_C(3581276106) } },
    { { UINT32_C(3296854280), UINT32_C(4278103639) },
      { UINT32_C(1567810228), UINT32_C(1364279457) },
      { UINT32_C(1729044052), UINT32_C(2913824182) } },
    { { UINT32_C(1146820329), UINT32_C( 505207140) },
      { UINT32_C(1251717048), UINT32_C( 374121229) },
      { UINT32_C(         0), UINT32_C( 131085911) } },
    { { UINT32_C(4242198180), UINT32_C( 838523005) },
      { UINT32_C(1552837819), UINT32_C(2527977389) },
      { UINT32_C(2689360361), UINT32_C(         0) } },
    { { UINT32_C(1524238582), UINT32_C(2591684321) },
      { UINT32_C(3018069157), UINT32_C(1556689080) },
      { UINT32_C(         0), UINT32_C(1034995241) } },
    { { UINT32_C(2086183935), UINT32_C( 917328763) },
      { UINT32_C(1821588671), UINT32_C( 285360155) },
      { UINT32_C( 264595264), UINT32_C( 631968608) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint32x2_t a = simde_vld1_u32(test_vec[i].a);
    simde_uint32x2_t b = simde_vld1_u32(test_vec[i].b);
    simde_uint32x2_t r = simde_vqsub_u32(a, b);
    simde_test_arm_neon_assert_equal_u32x2(r, simde_vld1_u32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint32x2_t a = simde_test_arm_neon_random_u32x2();
    simde_uint32x2_t b = simde_test_arm_neon_random_u32x2();
    simde_uint32x2_t r = simde_vqsub_u32(a, b);

    simde_test_arm_neon_write_u32x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u32x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vqsub_u64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint64_t a[1];
    uint64_t b[1];
    uint64_t r[1];
  } test_vec[] = {
    { { UINT64_C( 8774390669137206601) },
      { UINT64_C(15568651277195585785) },
      { UINT64_C(                   0) } },
    { { UINT64_C( 8739799921270744728) },
      { UINT64_C( 7379966152159911229) },
      { UINT64_C( 1359833769110833499) } },
    { { UINT64_C(13047303859675977413) },
      { UINT64_C(14605019878296796670) },
      { UINT64_C(                   0) } },
    { { UINT64_C( 4759504381343040475) },
      { UINT64_C(11567783556614451973) },
      { UINT64_C(                   0) } },
    { { UINT64_C( 7875751691503016668) },
      { UINT64_C(  181537236956001159) },
      { UINT64_C( 7694214454547015509) } },
    { { UINT64_C(10321586837836489462) },
      { UINT64_C(13335787268895594647) },
      { UINT64_C(                   0) } },
    { { UINT64_C( 2031859648466864981) },
      { UINT64_C( 6951969487651763792) },
      { UINT64_C(                   0) } },
    { { UINT64_C( 5609119769578639805) },
      { UINT64_C( 1803641916361836912) },
      { UINT64_C( 3805477853216802893) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint64x1_t a = simde_vld1_u64(test_vec[i].a);
    simde_uint64x1_t b = simde_vld1_u64(test_vec[i].b);
    simde_uint64x1_t r = simde_vqsub_u64(a, b);
    simde_test_arm_neon_assert_equal_u64x1(r, simde_vld1_u64(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint64x1_t a = simde_test_arm_neon_random_u64x1();
    simde_uint64x1_t b = simde_test_arm_neon_random_u64x1();
    simde_uint64x1_t r = simde_vqsub_u64(a, b);

    simde_test_arm_neon_write_u64x1(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u64x1(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u64x1(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vqsubq_s8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int8_t a[16];
    int8_t b[16];
    int8_t r[16];
  } test_vec[] = {
    { {  INT8_C(  29),  INT8_C(  88), -INT8_C(  34), -INT8_C(  78), -INT8_C(  10),  INT8_C(  16), -INT8_C(  49),  INT8_C(  70),
        -INT8_C( 122), -INT8_C(  91), -INT8_C(  66), -INT8_C(  16),  INT8_C(   0),  INT8_C(  57),  INT8_C(  81), -INT8_C(  66) },
      {  INT8_C(  74), -INT8_C(  84),  INT8_C(   6),  INT8_C(   0),  INT8_C(  69), -INT8_C(  35),  INT8_C(  78), -INT8_C(  75),
         INT8_C( 103),  INT8_C(  14),  INT8_C(   3),  INT8_C(  43), -INT8_C(  32),  INT8_C(  11),  INT8_C(  69), -INT8_C(   2) },
      { -INT8_C(  45),      INT8_MAX, -INT8_C(  40), -INT8_C(  78), -INT8_C(  79),  INT8_C(  51), -INT8_C( 127),      INT8_MAX,
             INT8_MIN, -INT8_C( 105), -INT8_C(  69), -INT8_C(  59),  INT8_C(  32),  INT8_C(  46),  INT8_C(  12), -INT8_C(  64) } },
    { {  INT8_C(  99),  INT8_C(  35), -INT8_C(  80),  INT8_C(  89),  INT8_C(  51),      INT8_MAX, -INT8_C(  96), -INT8_C(  71),
         INT8_C(  37),  INT8_C(  94), -INT8_C(  86),  INT8_C(  37), -INT8_C( 105), -INT8_C(   5), -INT8_C(  29), -INT8_C(  30) },
      { -INT8_C(  89), -INT8_C(  23), -INT8_C(  30), -INT8_C(  20), -INT8_C(  57),  INT8_C(  48), -INT8_C(  94),  INT8_C(  46),
         INT8_C(  62), -INT8_C(  91),  INT8_C(  89),  INT8_C(  31), -INT8_C(  80), -INT8_C(  98),  INT8_C(  29),  INT8_C(  20) },
      {      INT8_MAX,  INT8_C(  58), -INT8_C(  50),  INT8_C( 109),  INT8_C( 108),  INT8_C(  79), -INT8_C(   2), -INT8_C( 117),
        -INT8_C(  25),      INT8_MAX,      INT8_MIN,  INT8_C(   6), -INT8_C(  25),  INT8_C(  93), -INT8_C(  58), -INT8_C(  50) } },
    { { -INT8_C(  63), -INT8_C(  51),  INT8_C( 109), -INT8_C(  12),  INT8_C(  77),  INT8_C(  13), -INT8_C(  82),  INT8_C( 114),
         INT8_C( 108),  INT8_C(  88), -INT8_C( 105),  INT8_C(   3),  INT8_C(  83),  INT8_C( 123), -INT8_C(  27), -INT8_C(   6) },
      {  INT8_C( 100), -INT8_C(  56), -INT8_C(  25),  INT8_C(  43), -INT8_C(   8), -INT8_C( 119),  INT8_C(  89),  INT8_C(  55),
         INT8_C(  46), -INT8_C(  77),  INT8_C(  86), -INT8_C(  33),  INT8_C(  81),  INT8_C( 115), -INT8_C(  13),  INT8_C(  19) },
      {      INT8_MIN,  INT8_C(   5),      INT8_MAX, -INT8_C(  55),  INT8_C(  85),      INT8_MAX,      INT8_MIN,  INT8_C(  59),
         INT8_C(  62),      INT8_MAX,      INT8_MIN,  INT8_C(  36),  INT8_C(   2),  INT8_C(   8), -INT8_C(  14), -INT8_C(  25) } },
    { {  INT8_C(  64),  INT8_C(  96),  INT8_C(   7), -INT8_C( 115),  INT8_C( 110), -INT8_C(  75), -INT8_C(   1), -INT8_C(  38),
         INT8_C(  13), -INT8_C( 105), -INT8_C(  35),  INT8_C(  96),  INT8_C(  18), -INT8_C(  61),  INT8_C(  91),  INT8_C( 118) },
      { -INT8_C( 117),  INT8_C(  66), -INT8_C(  94), -INT8_C( 125), -INT8_C(  53), -INT8_C(   5), -INT8_C(  70), -INT8_C(   7),
        -INT8_C(  82),  INT8_C(  16), -INT8_C(  40),  INT8_C(   0), -INT8_C( 125), -INT8_C(  53),  INT8_C(  19), -INT8_C(  60) },
      {      INT8_MAX,  INT8_C(  30),  INT8_C( 101),  INT8_C(  10),      INT8_MAX, -INT8_C(  70),  INT8_C(  69), -INT8_C(  31),
         INT8_C(  95), -INT8_C( 121),  INT8_C(   5),  INT8_C(  96),      INT8_MAX, -INT8_C(   8),  INT8_C(  72),      INT8_MAX } },
    { {  INT8_C(  44),  INT8_C(  26),  INT8_C(  81), -INT8_C( 102), -INT8_C(  48),  INT8_C(  81),  INT8_C( 116), -INT8_C(  35),
        -INT8_C(  24),  INT8_C(  81),  INT8_C(  62), -INT8_C(   6),  INT8_C(  20), -INT8_C( 103),  INT8_C( 112), -INT8_C(  97) },
      { -INT8_C(  37),  INT8_C(  18),  INT8_C(  35), -INT8_C(  90),  INT8_C(  14), -INT8_C(  35), -INT8_C(  97), -INT8_C(  68),
        -INT8_C(  18),  INT8_C( 120), -INT8_C(  68),  INT8_C( 113),  INT8_C(  67), -INT8_C(  49),  INT8_C(  53),  INT8_C( 111) },
      {  INT8_C(  81),  INT8_C(   8),  INT8_C(  46), -INT8_C(  12), -INT8_C(  62),  INT8_C( 116),      INT8_MAX,  INT8_C(  33),
        -INT8_C(   6), -INT8_C(  39),      INT8_MAX, -INT8_C( 119), -INT8_C(  47), -INT8_C(  54),  INT8_C(  59),      INT8_MIN } },
    { { -INT8_C(  22), -INT8_C( 121),  INT8_C(   9), -INT8_C(  70), -INT8_C(  40),  INT8_C( 125), -INT8_C( 105), -INT8_C(  64),
        -INT8_C(  49), -INT8_C(  43), -INT8_C(  70), -INT8_C(  29),  INT8_C( 110),  INT8_C(  42), -INT8_C( 125),  INT8_C(  73) },
      {  INT8_C(  61), -INT8_C(  90), -INT8_C(  17),  INT8_C(  75), -INT8_C( 125), -INT8_C( 113),  INT8_C(   7),  INT8_C( 113),
         INT8_C(   7), -INT8_C(  60), -INT8_C(  29),  INT8_C(  74), -INT8_C( 109),  INT8_C(  24), -INT8_C(  70),  INT8_C( 125) },
      { -INT8_C(  83), -INT8_C(  31),  INT8_C(  26),      INT8_MIN,  INT8_C(  85),      INT8_MAX, -INT8_C( 112),      INT8_MIN,
        -INT8_C(  56),  INT8_C(  17), -INT8_C(  41), -INT8_C( 103),      INT8_MAX,  INT8_C(  18), -INT8_C(  55), -INT8_C(  52) } },
    { { -INT8_C(  97), -INT8_C(  61),  INT8_C(  55),  INT8_C( 119),  INT8_C(  65), -INT8_C(  49),  INT8_C(  55),  INT8_C(  16),
        -INT8_C(  92), -INT8_C(  15), -INT8_C(  13),  INT8_C(  19),  INT8_C(  28),  INT8_C( 118),  INT8_C(  92),  INT8_C(  89) },
      {  INT8_C(  28),  INT8_C(  76), -INT8_C(  92), -INT8_C(  96), -INT8_C(  37), -INT8_C(  85),  INT8_C(  17), -INT8_C(  30),
         INT8_C( 111), -INT8_C(  12),  INT8_C(  44),  INT8_C(   3),  INT8_C(  13), -INT8_C(  26),      INT8_MIN, -INT8_C(  84) },
      { -INT8_C( 125),      INT8_MIN,      INT8_MAX,      INT8_MAX,  INT8_C( 102),  INT8_C(  36),  INT8_C(  38),  INT8_C(  46),
             INT8_MIN, -INT8_C(   3), -INT8_C(  57),  INT8_C(  16),  INT8_C(  15),      INT8_MAX,      INT8_MAX,      INT8_MAX } },
    { { -INT8_C(  86), -INT8_C(  72),  INT8_C(  36), -INT8_C(  21), -INT8_C( 121),  INT8_C(  91), -INT8_C(   5),  INT8_C(  43),
         INT8_C(  77), -INT8_C(  18),  INT8_C(  62),  INT8_C( 105),  INT8_C( 101), -INT8_C( 101), -INT8_C(  62), -INT8_C( 127) },
      { -INT8_C(  25),  INT8_C( 102),  INT8_C(  33), -INT8_C(  62),  INT8_C(  17),  INT8_C(  51), -INT8_C(  92), -INT8_C( 127),
         INT8_C(  39), -INT8_C(  48), -INT8_C( 124),  INT8_C(  52), -INT8_C(  73),  INT8_C(   4), -INT8_C(  31),  INT8_C(  97) },
      { -INT8_C(  61),      INT8_MIN,  INT8_C(   3),  INT8_C(  41),      INT8_MIN,  INT8_C(  40),  INT8_C(  87),      INT8_MAX,
         INT8_C(  38),  INT8_C(  30),      INT8_MAX,  INT8_C(  53),      INT8_MAX, -INT8_C( 105), -INT8_C(  31),      INT8_MIN } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int8x16_t a = simde_vld1q_s8(test_vec[i].a);
    simde_int8x16_t b = simde_vld1q_s8(test_vec[i].b);
    simde_int8x16_t r = simde_vqsubq_s8(a, b);

    simde_test_arm_neon_assert_equal_i8x16(r, simde_vld1q_s8(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int8x16_t a = simde_test_arm_neon_random_i8x16();
    simde_int8x16_t b = simde_test_arm_neon_random_i8x16();
    simde_int8x16_t r = simde_vqsubq_s8(a, b);

    simde_test_arm_neon_write_i8x16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i8x16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i8x16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vqsubq_s16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int16_t a[8];
    int16_t b[8];
    int16_t r[8];
  } test_vec[] = {
    { {  INT16_C(  1468),  INT16_C( 17228),  INT16_C( 18272), -INT16_C( 21137), -INT16_C( 21195), -INT16_C( 26090), -INT16_C( 10168),  INT16_C( 12060) },
      {  INT16_C( 15678),  INT16_C( 20721), -INT16_C( 27280), -INT16_C( 26415),  INT16_C( 21862),  INT16_C(  7628), -INT16_C( 21159),  INT16_C(  5758) },
      { -INT16_C( 14210), -INT16_C(  3493),       INT16_MAX,  INT16_C(  5278),       INT16_MIN,       INT16_MIN,  INT16_C( 10991),  INT16_C(  6302) } },
    { { -INT16_C( 13646),  INT16_C(  4953), -INT16_C( 14319),  INT16_C( 18112), -INT16_C( 10378), -INT16_C( 16671), -INT16_C(   593), -INT16_C(  4370) },
      { -INT16_C(  8390), -INT16_C( 21698),  INT16_C(  3957), -INT16_C(  9405),  INT16_C(  3940), -INT16_C( 16904),  INT16_C( 30397),  INT16_C( 28627) },
      { -INT16_C(  5256),  INT16_C( 26651), -INT16_C( 18276),  INT16_C( 27517), -INT16_C( 14318),  INT16_C(   233), -INT16_C( 30990),       INT16_MIN } },
    { {  INT16_C( 11584),  INT16_C( 20866),  INT16_C( 17397),  INT16_C( 27543),  INT16_C( 30746), -INT16_C( 14038),  INT16_C(  6261), -INT16_C( 20297) },
      { -INT16_C(  2569),  INT16_C( 27739), -INT16_C( 25084),  INT16_C( 26695),  INT16_C( 16301),  INT16_C( 27174), -INT16_C(  1611), -INT16_C(  2598) },
      {  INT16_C( 14153), -INT16_C(  6873),       INT16_MAX,  INT16_C(   848),  INT16_C( 14445),       INT16_MIN,  INT16_C(  7872), -INT16_C( 17699) } },
    { {  INT16_C( 23590),  INT16_C(  7238), -INT16_C(  8545), -INT16_C( 18041), -INT16_C( 20138), -INT16_C( 13181),  INT16_C( 15049), -INT16_C( 16004) },
      { -INT16_C( 10448),  INT16_C( 13357),  INT16_C( 30069),  INT16_C(  8861), -INT16_C( 15436),  INT16_C( 27277),  INT16_C( 26556), -INT16_C(  7329) },
      {       INT16_MAX, -INT16_C(  6119),       INT16_MIN, -INT16_C( 26902), -INT16_C(  4702),       INT16_MIN, -INT16_C( 11507), -INT16_C(  8675) } },
    { { -INT16_C( 22845),  INT16_C( 25599), -INT16_C( 31100), -INT16_C(  9700), -INT16_C( 24776),  INT16_C(   422),  INT16_C(  8922),  INT16_C(  2754) },
      { -INT16_C(  3847),  INT16_C( 28222), -INT16_C(  9371),  INT16_C(  6545),  INT16_C(  7838),  INT16_C( 23427), -INT16_C(  7291),  INT16_C( 18494) },
      { -INT16_C( 18998), -INT16_C(  2623), -INT16_C( 21729), -INT16_C( 16245), -INT16_C( 32614), -INT16_C( 23005),  INT16_C( 16213), -INT16_C( 15740) } },
    { {  INT16_C( 15753),  INT16_C(  3499), -INT16_C( 14141), -INT16_C(  1049), -INT16_C( 29081),  INT16_C( 16893), -INT16_C( 16464), -INT16_C( 21941) },
      { -INT16_C( 30033),  INT16_C(  5144), -INT16_C( 22171),  INT16_C(  1070), -INT16_C( 20025),  INT16_C( 19551), -INT16_C( 25196),  INT16_C(  7573) },
      {       INT16_MAX, -INT16_C(  1645),  INT16_C(  8030), -INT16_C(  2119), -INT16_C(  9056), -INT16_C(  2658),  INT16_C(  8732), -INT16_C( 29514) } },
    { {  INT16_C( 16602), -INT16_C( 25302),  INT16_C(  4616),  INT16_C( 28825), -INT16_C( 26976),  INT16_C( 20657), -INT16_C(   683),  INT16_C(  1530) },
      {  INT16_C(  4999), -INT16_C(  5095),  INT16_C( 18364), -INT16_C( 31504),  INT16_C( 20473), -INT16_C( 29232),  INT16_C( 26092), -INT16_C( 14677) },
      {  INT16_C( 11603), -INT16_C( 20207), -INT16_C( 13748),       INT16_MAX,       INT16_MIN,       INT16_MAX, -INT16_C( 26775),  INT16_C( 16207) } },
    { { -INT16_C( 10842), -INT16_C( 20892), -INT16_C(   537), -INT16_C( 30946), -INT16_C( 12141), -INT16_C(  5928), -INT16_C( 11571),  INT16_C( 21741) },
      {  INT16_C(  2021), -INT16_C( 24000),  INT16_C( 12622),  INT16_C( 18214), -INT16_C(  2432),  INT16_C( 28117), -INT16_C( 32676),  INT16_C(   563) },
      { -INT16_C( 12863),  INT16_C(  3108), -INT16_C( 13159),       INT16_MIN, -INT16_C(  9709),       INT16_MIN,  INT16_C( 21105),  INT16_C( 21178) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x8_t a = simde_vld1q_s16(test_vec[i].a);
    simde_int16x8_t b = simde_vld1q_s16(test_vec[i].b);
    simde_int16x8_t r = simde_vqsubq_s16(a, b);

    simde_test_arm_neon_assert_equal_i16x8(r, simde_vld1q_s16(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int16x8_t a = simde_test_arm_neon_random_i16x8();
    simde_int16x8_t b = simde_test_arm_neon_random_i16x8();
    simde_int16x8_t r = simde_vqsubq_s16(a, b);

    simde_test_arm_neon_write_i16x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i16x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i16x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vqsubq_s32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int32_t a[4];
    int32_t b[4];
    int32_t r[4];
  } test_vec[] = {
    { {  INT32_C(  1034983253),  INT32_C(   667209620),  INT32_C(  1813027999),  INT32_C(  1421933935) },
      {  INT32_C(  1408630788), -INT32_C(  1298523087),  INT32_C(  1864331027),  INT32_C(  1165054703) },
      { -INT32_C(   373647535),  INT32_C(  1965732707), -INT32_C(    51303028),  INT32_C(   256879232) } },
    { {  INT32_C(  2122457578), -INT32_C(  1884928272),  INT32_C(  1392228067), -INT32_C(  1197032525) },
      { -INT32_C(   318005828), -INT32_C(   861952583),  INT32_C(    71024149), -INT32_C(    79057903) },
      {            INT32_MAX, -INT32_C(  1022975689),  INT32_C(  1321203918), -INT32_C(  1117974622) } },
    { { -INT32_C(  1099314226), -INT32_C(   179429614), -INT32_C(  1991816747), -INT32_C(  1052644091) },
      {  INT32_C(  1152273546),  INT32_C(   101732081),  INT32_C(   487279628), -INT32_C(   971483912) },
      {            INT32_MIN, -INT32_C(   281161695),            INT32_MIN, -INT32_C(    81160179) } },
    { {  INT32_C(   847614496), -INT32_C(  2027433039),  INT32_C(   554724892), -INT32_C(   421375653) },
      { -INT32_C(  1909812835), -INT32_C(   342541601),  INT32_C(  2131337350),  INT32_C(   340074996) },
      {            INT32_MAX, -INT32_C(  1684891438), -INT32_C(  1576612458), -INT32_C(   761450649) } },
    { {  INT32_C(  1699138227), -INT32_C(  1158910563),  INT32_C(   937163995), -INT32_C(   367149491) },
      {  INT32_C(   779634511),  INT32_C(   135859585), -INT32_C(  1568202067), -INT32_C(   139015100) },
      {  INT32_C(   919503716), -INT32_C(  1294770148),            INT32_MAX, -INT32_C(   228134391) } },
    { {  INT32_C(   878509463),  INT32_C(  1190021226), -INT32_C(  1854027196), -INT32_C(   679765368) },
      {  INT32_C(  1644557537), -INT32_C(  1351999999), -INT32_C(  2058227391),  INT32_C(  1434191806) },
      { -INT32_C(   766048074),            INT32_MAX,  INT32_C(   204200195), -INT32_C(  2113957174) } },
    { {  INT32_C(  1871304964),  INT32_C(  1723168801), -INT32_C(   889769406), -INT32_C(  1381927988) },
      {  INT32_C(  1745856103),  INT32_C(    85424836),  INT32_C(   696936555),  INT32_C(  1954416496) },
      {  INT32_C(   125448861),  INT32_C(  1637743965), -INT32_C(  1586705961),            INT32_MIN } },
    { {  INT32_C(    31656160), -INT32_C(  1033398144), -INT32_C(  1769185334),  INT32_C(   960703954) },
      { -INT32_C(  1751034925),  INT32_C(   949860813), -INT32_C(  1855838431),  INT32_C(   235331630) },
      {  INT32_C(  1782691085), -INT32_C(  1983258957),  INT32_C(    86653097),  INT32_C(   725372324) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x4_t a = simde_vld1q_s32(test_vec[i].a);
    simde_int32x4_t b = simde_vld1q_s32(test_vec[i].b);
    simde_int32x4_t r = simde_vqsubq_s32(a, b);
    simde_test_arm_neon_assert_equal_i32x4(r, simde_vld1q_s32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int32x4_t a = simde_test_arm_neon_random_i32x4();
    simde_int32x4_t b = simde_test_arm_neon_random_i32x4();
    simde_int32x4_t r = simde_vqsubq_s32(a, b);

    simde_test_arm_neon_write_i32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vqsubq_s64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int64_t a[2];
    int64_t b[2];
    int64_t r[2];
  } test_vec[] = {
    { {  INT64_C( 5488330497879763432), -INT64_C( 5268887329813842218) },
      {  INT64_C( 6737362211679667065), -INT64_C( 6174446353717927662) },
      { -INT64_C( 1249031713799903633),  INT64_C(  905559023904085444) } },
    { { -INT64_C( 5932017138937995298),  INT64_C( 3498513743973093619) },
      { -INT64_C( 2786332034548180038),  INT64_C( 1603960109088261078) },
      { -INT64_C( 3145685104389815260),  INT64_C( 1894553634884832541) } },
    { { -INT64_C( 8841370285577382711), -INT64_C( 7666558287053282380) },
      { -INT64_C( 2493621974940773947), -INT64_C( 5660541048033280477) },
      { -INT64_C( 6347748310636608764), -INT64_C( 2006017239020001903) } },
    { { -INT64_C( 4601942092203038709),  INT64_C( 3220853730185018946) },
      {  INT64_C( 4736128877027933910), -INT64_C( 1066210828566646885) },
      {                     INT64_MIN,  INT64_C( 4287064558751665831) } },
    { {  INT64_C( 7332898282719315446), -INT64_C( 8448130901258080722) },
      {  INT64_C( 3662307856862378611),  INT64_C( 8370196635761078352) },
      {  INT64_C( 3670590425856936835),                     INT64_MIN } },
    { { -INT64_C( 7640572926802545042),  INT64_C( 2479494029669792041) },
      {  INT64_C( 4697685359771045736),  INT64_C( 4461555193753429751) },
      {                     INT64_MIN, -INT64_C( 1982061164083637710) } },
    { { -INT64_C( 4155759654631153322), -INT64_C( 3093960381515465153) },
      {  INT64_C( 4831524897867220187),  INT64_C( 9005407212867716588) },
      { -INT64_C( 8987284552498373509),                     INT64_MIN } },
    { { -INT64_C( 3574014710070523900), -INT64_C( 1131305013801645557) },
      {  INT64_C( 1377760808561025424),  INT64_C( 9075256247633041231) },
      { -INT64_C( 4951775518631549324),                     INT64_MIN } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int64x2_t a = simde_vld1q_s64(test_vec[i].a);
    simde_int64x2_t b = simde_vld1q_s64(test_vec[i].b);
    simde_int64x2_t r = simde_vqsubq_s64(a, b);
    simde_test_arm_neon_assert_equal_i64x2(r, simde_vld1q_s64(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int64x2_t a = simde_test_arm_neon_random_i64x2();
    simde_int64x2_t b = simde_test_arm_neon_random_i64x2();
    simde_int64x2_t r = simde_vqsubq_s64(a, b);

    simde_test_arm_neon_write_i64x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i64x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vqsubq_u8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint8_t a[16];
    uint8_t b[16];
    uint8_t r[16];
  } test_vec[] = {
    { { UINT8_C(145), UINT8_C( 42), UINT8_C( 30), UINT8_C( 32), UINT8_C(183), UINT8_C(132), UINT8_C(238), UINT8_C(194),
        UINT8_C(142), UINT8_C(170), UINT8_C( 57), UINT8_C(164), UINT8_C(118), UINT8_C(134), UINT8_C(148), UINT8_C(  6) },
      { UINT8_C(167), UINT8_C( 81), UINT8_C(225), UINT8_C(206), UINT8_C( 27), UINT8_C(  0), UINT8_C(225), UINT8_C(106),
        UINT8_C(215), UINT8_C(177), UINT8_C(223), UINT8_C( 80), UINT8_C(122), UINT8_C(208), UINT8_C(206), UINT8_C( 11) },
      { UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(156), UINT8_C(132), UINT8_C( 13), UINT8_C( 88),
        UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C( 84), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0) } },
    { { UINT8_C(251), UINT8_C(236), UINT8_C( 43), UINT8_C(178), UINT8_C(112), UINT8_C( 25), UINT8_C(116),    UINT8_MAX,
        UINT8_C(195), UINT8_C(173), UINT8_C(163), UINT8_C( 57), UINT8_C( 51), UINT8_C( 55), UINT8_C( 63), UINT8_C(218) },
      { UINT8_C(136), UINT8_C( 33), UINT8_C(168), UINT8_C(163), UINT8_C( 33), UINT8_C(138), UINT8_C( 14), UINT8_C(248),
        UINT8_C( 59), UINT8_C(237), UINT8_C( 72), UINT8_C(181), UINT8_C(190), UINT8_C( 22), UINT8_C(192), UINT8_C(185) },
      { UINT8_C(115), UINT8_C(203), UINT8_C(  0), UINT8_C( 15), UINT8_C( 79), UINT8_C(  0), UINT8_C(102), UINT8_C(  7),
        UINT8_C(136), UINT8_C(  0), UINT8_C( 91), UINT8_C(  0), UINT8_C(  0), UINT8_C( 33), UINT8_C(  0), UINT8_C( 33) } },
    { { UINT8_C(  2), UINT8_C(236), UINT8_C(107), UINT8_C(115), UINT8_C(  5), UINT8_C(223), UINT8_C(114), UINT8_C(201),
        UINT8_C(140), UINT8_C( 21), UINT8_C(  2), UINT8_C(192), UINT8_C( 76), UINT8_C( 66), UINT8_C(154), UINT8_C(213) },
      { UINT8_C( 99), UINT8_C( 67), UINT8_C(120), UINT8_C(132), UINT8_C(205), UINT8_C(134), UINT8_C(124), UINT8_C(  8),
        UINT8_C(116), UINT8_C(196), UINT8_C(189), UINT8_C( 50), UINT8_C(219), UINT8_C(125), UINT8_C(235), UINT8_C(221) },
      { UINT8_C(  0), UINT8_C(169), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C( 89), UINT8_C(  0), UINT8_C(193),
        UINT8_C( 24), UINT8_C(  0), UINT8_C(  0), UINT8_C(142), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0) } },
    { { UINT8_C(105), UINT8_C( 86), UINT8_C( 80), UINT8_C(111), UINT8_C( 53), UINT8_C(194), UINT8_C( 56), UINT8_C(193),
        UINT8_C(215), UINT8_C( 58), UINT8_C(129), UINT8_C( 36), UINT8_C(124), UINT8_C( 28), UINT8_C(249), UINT8_C(223) },
      { UINT8_C( 95), UINT8_C(113), UINT8_C( 99), UINT8_C( 44), UINT8_C(248), UINT8_C(223), UINT8_C( 52), UINT8_C(108),
        UINT8_C(164), UINT8_C(241), UINT8_C(158), UINT8_C(127), UINT8_C(110), UINT8_C(137), UINT8_C( 92), UINT8_C(216) },
      { UINT8_C( 10), UINT8_C(  0), UINT8_C(  0), UINT8_C( 67), UINT8_C(  0), UINT8_C(  0), UINT8_C(  4), UINT8_C( 85),
        UINT8_C( 51), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C( 14), UINT8_C(  0), UINT8_C(157), UINT8_C(  7) } },
    { { UINT8_C(223), UINT8_C(173), UINT8_C( 71), UINT8_C( 20), UINT8_C(111), UINT8_C(127), UINT8_C(213), UINT8_C( 71),
        UINT8_C(185), UINT8_C( 87), UINT8_C(107), UINT8_C( 54), UINT8_C(115), UINT8_C(100), UINT8_C( 21), UINT8_C(210) },
      { UINT8_C(213), UINT8_C(121), UINT8_C(254), UINT8_C(205), UINT8_C( 88), UINT8_C( 50), UINT8_C( 57), UINT8_C(252),
        UINT8_C( 35), UINT8_C(215), UINT8_C(123), UINT8_C(145), UINT8_C( 96), UINT8_C(216), UINT8_C(105), UINT8_C( 63) },
      { UINT8_C( 10), UINT8_C( 52), UINT8_C(  0), UINT8_C(  0), UINT8_C( 23), UINT8_C( 77), UINT8_C(156), UINT8_C(  0),
        UINT8_C(150), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C( 19), UINT8_C(  0), UINT8_C(  0), UINT8_C(147) } },
    { { UINT8_C(133), UINT8_C(176), UINT8_C( 83), UINT8_C(244), UINT8_C( 47), UINT8_C( 41), UINT8_C( 59), UINT8_C(233),
        UINT8_C(128), UINT8_C(166), UINT8_C( 31), UINT8_C(243), UINT8_C( 10), UINT8_C( 52), UINT8_C(197), UINT8_C(224) },
      { UINT8_C(173), UINT8_C(195), UINT8_C(173), UINT8_C(  6), UINT8_C(245), UINT8_C(231), UINT8_C(  2), UINT8_C( 24),
        UINT8_C(190), UINT8_C(126), UINT8_C(169), UINT8_C( 31), UINT8_C( 86), UINT8_C( 19), UINT8_C( 94), UINT8_C(219) },
      { UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(238), UINT8_C(  0), UINT8_C(  0), UINT8_C( 57), UINT8_C(209),
        UINT8_C(  0), UINT8_C( 40), UINT8_C(  0), UINT8_C(212), UINT8_C(  0), UINT8_C( 33), UINT8_C(103), UINT8_C(  5) } },
    { { UINT8_C(195), UINT8_C(178), UINT8_C(207), UINT8_C(243), UINT8_C(219), UINT8_C( 11), UINT8_C(220), UINT8_C( 91),
        UINT8_C(177), UINT8_C(251), UINT8_C( 78), UINT8_C(188), UINT8_C( 47), UINT8_C( 19), UINT8_C(156), UINT8_C(221) },
      { UINT8_C(214), UINT8_C( 73), UINT8_C(227), UINT8_C(203), UINT8_C( 48), UINT8_C(229), UINT8_C(227), UINT8_C(239),
        UINT8_C( 99), UINT8_C(140), UINT8_C( 14), UINT8_C(185), UINT8_C(159), UINT8_C(108), UINT8_C(148), UINT8_C( 99) },
      { UINT8_C(  0), UINT8_C(105), UINT8_C(  0), UINT8_C( 40), UINT8_C(171), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),
        UINT8_C( 78), UINT8_C(111), UINT8_C( 64), UINT8_C(  3), UINT8_C(  0), UINT8_C(  0), UINT8_C(  8), UINT8_C(122) } },
    { { UINT8_C( 30), UINT8_C(100), UINT8_C( 86), UINT8_C(249), UINT8_C(111), UINT8_C( 50), UINT8_C( 84), UINT8_C( 32),
        UINT8_C( 45), UINT8_C(162), UINT8_C(220), UINT8_C( 92), UINT8_C(181), UINT8_C(120), UINT8_C( 57), UINT8_C(139) },
      { UINT8_C(194), UINT8_C( 28), UINT8_C( 86), UINT8_C(242), UINT8_C(  2), UINT8_C( 57), UINT8_C(225), UINT8_C(101),
        UINT8_C(198), UINT8_C(239), UINT8_C( 31), UINT8_C(101), UINT8_C( 92), UINT8_C(179), UINT8_C(200), UINT8_C(122) },
      { UINT8_C(  0), UINT8_C( 72), UINT8_C(  0), UINT8_C(  7), UINT8_C(109), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),
        UINT8_C(  0), UINT8_C(  0), UINT8_C(189), UINT8_C(  0), UINT8_C( 89), UINT8_C(  0), UINT8_C(  0), UINT8_C( 17) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint8x16_t a = simde_vld1q_u8(test_vec[i].a);
    simde_uint8x16_t b = simde_vld1q_u8(test_vec[i].b);
    simde_uint8x16_t r = simde_vqsubq_u8(a, b);

    simde_test_arm_neon_assert_equal_u8x16(r, simde_vld1q_u8(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint8x16_t a = simde_test_arm_neon_random_u8x16();
    simde_uint8x16_t b = simde_test_arm_neon_random_u8x16();
    simde_uint8x16_t r = simde_vqsubq_u8(a, b);

    simde_test_arm_neon_write_u8x16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u8x16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u8x16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vqsubq_u16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint16_t a[8];
    uint16_t b[8];
    uint16_t r[8];
  } test_vec[] = {
    { { UINT16_C( 7703), UINT16_C(34420), UINT16_C(51280), UINT16_C(32167), UINT16_C(33643), UINT16_C( 8410), UINT16_C( 5116), UINT16_C(48812) },
      { UINT16_C(  560), UINT16_C(12976), UINT16_C(37436), UINT16_C(  663), UINT16_C(46721), UINT16_C(56679), UINT16_C(12394), UINT16_C(33112) },
      { UINT16_C( 7143), UINT16_C(21444), UINT16_C(13844), UINT16_C(31504), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(15700) } },
    { { UINT16_C(52302), UINT16_C(40712), UINT16_C(44948), UINT16_C(65308), UINT16_C(63026), UINT16_C(11808), UINT16_C(52234), UINT16_C(15084) },
      { UINT16_C(40398), UINT16_C( 2668), UINT16_C(  815), UINT16_C(45068), UINT16_C(29882), UINT16_C( 9358), UINT16_C(59044), UINT16_C(62117) },
      { UINT16_C(11904), UINT16_C(38044), UINT16_C(44133), UINT16_C(20240), UINT16_C(33144), UINT16_C( 2450), UINT16_C(    0), UINT16_C(    0) } },
    { { UINT16_C(44466), UINT16_C(18065), UINT16_C(44636), UINT16_C(36678), UINT16_C(26276), UINT16_C(44733), UINT16_C(43570), UINT16_C(  232) },
      { UINT16_C(21575), UINT16_C(30219), UINT16_C( 5976), UINT16_C( 4646), UINT16_C(46219), UINT16_C(12086), UINT16_C(56218), UINT16_C(19490) },
      { UINT16_C(22891), UINT16_C(    0), UINT16_C(38660), UINT16_C(32032), UINT16_C(    0), UINT16_C(32647), UINT16_C(    0), UINT16_C(    0) } },
    { { UINT16_C(45961), UINT16_C(58771), UINT16_C(55649), UINT16_C( 1652), UINT16_C(12863), UINT16_C(29108), UINT16_C(40412), UINT16_C( 9073) },
      { UINT16_C(31985), UINT16_C(18841), UINT16_C(49044), UINT16_C( 8027), UINT16_C(37236), UINT16_C( 3663), UINT16_C(29037), UINT16_C(63067) },
      { UINT16_C(13976), UINT16_C(39930), UINT16_C( 6605), UINT16_C(    0), UINT16_C(    0), UINT16_C(25445), UINT16_C(11375), UINT16_C(    0) } },
    { { UINT16_C(60964), UINT16_C(34523), UINT16_C(20679), UINT16_C( 1676), UINT16_C(16514), UINT16_C(24183), UINT16_C(59613), UINT16_C(53121) },
      { UINT16_C( 6757), UINT16_C(63768), UINT16_C(29913), UINT16_C(19736), UINT16_C(26373), UINT16_C(29276), UINT16_C(47064), UINT16_C(64872) },
      { UINT16_C(54207), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(12549), UINT16_C(    0) } },
    { { UINT16_C(17573), UINT16_C(27779), UINT16_C( 3988), UINT16_C( 5746), UINT16_C(59727), UINT16_C(11636), UINT16_C(62929), UINT16_C(14076) },
      { UINT16_C( 5135), UINT16_C(59439), UINT16_C(18568), UINT16_C(36406), UINT16_C(37551), UINT16_C(34816), UINT16_C(26953), UINT16_C(61061) },
      { UINT16_C(12438), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(22176), UINT16_C(    0), UINT16_C(35976), UINT16_C(    0) } },
    { { UINT16_C( 2221), UINT16_C(16730), UINT16_C(52247), UINT16_C(26199), UINT16_C(52149), UINT16_C(34451), UINT16_C(36800), UINT16_C(53181) },
      { UINT16_C(60580), UINT16_C(11447), UINT16_C(60724), UINT16_C(58554), UINT16_C(47999), UINT16_C(51308), UINT16_C(61732), UINT16_C(53686) },
      { UINT16_C(    0), UINT16_C( 5283), UINT16_C(    0), UINT16_C(    0), UINT16_C( 4150), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0) } },
    { { UINT16_C( 4345), UINT16_C( 4114), UINT16_C(27100), UINT16_C(37238), UINT16_C( 2612), UINT16_C(62488), UINT16_C(54681), UINT16_C(15811) },
      { UINT16_C(31425), UINT16_C(63082), UINT16_C( 9320), UINT16_C(59354), UINT16_C(18143), UINT16_C(  944), UINT16_C(26167), UINT16_C(12500) },
      { UINT16_C(    0), UINT16_C(    0), UINT16_C(17780), UINT16_C(    0), UINT16_C(    0), UINT16_C(61544), UINT16_C(28514), UINT16_C( 3311) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint16x8_t a = simde_vld1q_u16(test_vec[i].a);
    simde_uint16x8_t b = simde_vld1q_u16(test_vec[i].b);
    simde_uint16x8_t r = simde_vqsubq_u16(a, b);
    simde_test_arm_neon_assert_equal_u16x8(r, simde_vld1q_u16(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint16x8_t a = simde_test_arm_neon_random_u16x8();
    simde_uint16x8_t b = simde_test_arm_neon_random_u16x8();
    simde_uint16x8_t r = simde_vqsubq_u16(a, b);

    simde_test_arm_neon_write_u16x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u16x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u16x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vqsubq_u32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint32_t a[4];
    uint32_t b[4];
    uint32_t r[4];
  } test_vec[] = {
    { { UINT32_C(1396762231), UINT32_C(2212869711), UINT32_C(1517813184), UINT32_C(2476161746) },
      { UINT32_C( 495518133), UINT32_C(  84173606), UINT32_C(3758732457), UINT32_C(2450578715) },
      { UINT32_C( 901244098), UINT32_C(2128696105), UINT32_C(         0), UINT32_C(  25583031) } },
    { { UINT32_C( 333795524), UINT32_C(3348613639), UINT32_C(2569080519), UINT32_C(4264409417) },
      { UINT32_C(3759912634), UINT32_C(3286638362), UINT32_C(4020563924), UINT32_C(2424419532) },
      { UINT32_C(         0), UINT32_C(  61975277), UINT32_C(         0), UINT32_C(1839989885) } },
    { { UINT32_C( 212100613), UINT32_C(4174592817), UINT32_C(2459104585), UINT32_C(1754316718) },
      { UINT32_C(2403969909), UINT32_C(2673029067), UINT32_C(3935237918), UINT32_C(2960854955) },
      { UINT32_C(         0), UINT32_C(1501563750), UINT32_C(         0), UINT32_C(         0) } },
    { { UINT32_C(2797346677), UINT32_C(2745143386), UINT32_C( 859189637), UINT32_C(1704707824) },
      { UINT32_C(1039524978), UINT32_C( 836519955), UINT32_C(3927730751), UINT32_C(4003174265) },
      { UINT32_C(1757821699), UINT32_C(1908623431), UINT32_C(         0), UINT32_C(         0) } },
    { { UINT32_C( 278222774), UINT32_C(1823683815), UINT32_C(1436543333), UINT32_C( 582630320) },
      { UINT32_C( 861908767), UINT32_C( 912538615), UINT32_C( 505512101), UINT32_C(3440163863) },
      { UINT32_C(         0), UINT32_C( 911145200), UINT32_C( 931031232), UINT32_C(         0) } },
    { { UINT32_C(4225605907), UINT32_C( 979866069), UINT32_C( 714016634), UINT32_C(1632389698) },
      { UINT32_C(4053052409), UINT32_C(2334652902), UINT32_C(2443790457), UINT32_C( 408860164) },
      { UINT32_C( 172553498), UINT32_C(         0), UINT32_C(         0), UINT32_C(1223529534) } },
    { { UINT32_C( 756235351), UINT32_C(1197963981), UINT32_C(3279091585), UINT32_C( 975552065) },
      { UINT32_C(1345042794), UINT32_C( 752636850), UINT32_C(2696775067), UINT32_C(2478316347) },
      { UINT32_C(         0), UINT32_C( 445327131), UINT32_C( 582316518), UINT32_C(         0) } },
    { { UINT32_C( 616614743), UINT32_C(3345753925), UINT32_C(1602936350), UINT32_C( 110800796) },
      { UINT32_C( 458737001), UINT32_C(3024565016), UINT32_C(4099146936), UINT32_C(2005339168) },
      { UINT32_C( 157877742), UINT32_C( 321188909), UINT32_C(         0), UINT32_C(         0) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint32x4_t a = simde_vld1q_u32(test_vec[i].a);
    simde_uint32x4_t b = simde_vld1q_u32(test_vec[i].b);
    simde_uint32x4_t r = simde_vqsubq_u32(a, b);

    simde_test_arm_neon_assert_equal_u32x4(r, simde_vld1q_u32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint32x4_t a = simde_test_arm_neon_random_u32x4();
    simde_uint32x4_t b = simde_test_arm_neon_random_u32x4();
    simde_uint32x4_t r = simde_vqsubq_u32(a, b);

    simde_test_arm_neon_write_u32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vqsubq_u64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint64_t a[2];
    uint64_t b[2];
    uint64_t r[2];
  } test_vec[] = {
    { { UINT64_C(10224024848080586711), UINT64_C( 9694427134200409830) },
      { UINT64_C(14634703258642473036), UINT64_C( 5730063582356270318) },
      { UINT64_C(                   0), UINT64_C( 3964363551844139512) } },
    { { UINT64_C( 1119513024125477261), UINT64_C( 5215480616301262269) },
      { UINT64_C(15841910786196505595), UINT64_C( 7924486926259296561) },
      { UINT64_C(                   0), UINT64_C(                   0) } },
    { { UINT64_C( 8271409052956321168), UINT64_C( 8190833270310394727) },
      { UINT64_C( 5654929166370298034), UINT64_C( 7079362651552769009) },
      { UINT64_C( 2616479886586023134), UINT64_C( 1111470618757625718) } },
    { { UINT64_C(   35998668026521431), UINT64_C( 3325362398858366015) },
      { UINT64_C(17281236453137687911), UINT64_C( 1576258484415024043) },
      { UINT64_C(                   0), UINT64_C( 1749103914443341972) } },
    { { UINT64_C( 2251695219389103013), UINT64_C( 1879966640302760813) },
      { UINT64_C(15532476601301132448), UINT64_C(17442217391346241085) },
      { UINT64_C(                   0), UINT64_C(                   0) } },
    { { UINT64_C( 4480642722485580079), UINT64_C(11447936937942778387) },
      { UINT64_C( 3181171840948928033), UINT64_C(16021615797036612121) },
      { UINT64_C( 1299470881536652046), UINT64_C(                   0) } },
    { { UINT64_C(  898217407916378471), UINT64_C(18282839721204948509) },
      { UINT64_C(15657732499944764719), UINT64_C( 1186302306518266602) },
      { UINT64_C(                   0), UINT64_C(17096537414686681907) } },
    { { UINT64_C(11252174941359530785), UINT64_C(15724723450389461343) },
      { UINT64_C(16068356335904326757), UINT64_C(17757954831424044471) },
      { UINT64_C(                   0), UINT64_C(                   0) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint64x2_t a = simde_vld1q_u64(test_vec[i].a);
    simde_uint64x2_t b = simde_vld1q_u64(test_vec[i].b);
    simde_uint64x2_t r = simde_vqsubq_u64(a, b);
    simde_test_arm_neon_assert_equal_u64x2(r, simde_vld1q_u64(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint64x2_t a = simde_test_arm_neon_random_u64x2();
    simde_uint64x2_t b = simde_test_arm_neon_random_u64x2();
    simde_uint64x2_t r = simde_vqsubq_u64(a, b);

    simde_test_arm_neon_write_u64x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u64x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(vqsubb_s8)
SIMDE_TEST_FUNC_LIST_ENTRY(vqsubh_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vqsubs_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vqsubd_s64)
SIMDE_TEST_FUNC_LIST_ENTRY(vqsubb_u8)
SIMDE_TEST_FUNC_LIST_ENTRY(vqsubh_u16)
SIMDE_TEST_FUNC_LIST_ENTRY(vqsubs_u32)
SIMDE_TEST_FUNC_LIST_ENTRY(vqsubd_u64)

SIMDE_TEST_FUNC_LIST_ENTRY(vqsub_s8)
SIMDE_TEST_FUNC_LIST_ENTRY(vqsub_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vqsub_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vqsub_s64)
SIMDE_TEST_FUNC_LIST_ENTRY(vqsub_u8)
SIMDE_TEST_FUNC_LIST_ENTRY(vqsub_u16)
SIMDE_TEST_FUNC_LIST_ENTRY(vqsub_u32)
SIMDE_TEST_FUNC_LIST_ENTRY(vqsub_u64)

SIMDE_TEST_FUNC_LIST_ENTRY(vqsubq_s8)
SIMDE_TEST_FUNC_LIST_ENTRY(vqsubq_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vqsubq_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vqsubq_s64)
SIMDE_TEST_FUNC_LIST_ENTRY(vqsubq_u8)
SIMDE_TEST_FUNC_LIST_ENTRY(vqsubq_u16)
SIMDE_TEST_FUNC_LIST_ENTRY(vqsubq_u32)
SIMDE_TEST_FUNC_LIST_ENTRY(vqsubq_u64)
SIMDE_TEST_FUNC_LIST_END

#include "test-neon-footer.h"
