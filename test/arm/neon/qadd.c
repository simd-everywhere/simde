#define SIMDE_TEST_ARM_NEON_INSN qadd

#include "test-neon.h"
#include "../../../simde/arm/neon/qadd.h"

static int
test_simde_vqaddb_s8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int8_t a;
    int8_t b;
    int8_t r;
  } test_vec[] = {
    { -INT8_C(  47),
       INT8_C(  10),
      -INT8_C(  37) },
    {  INT8_C(  58),
       INT8_C( 109),
           INT8_MAX },
    { -INT8_C(  66),
       INT8_C(  31),
      -INT8_C(  35) },
    {      INT8_MAX,
      -INT8_C(   3),
       INT8_C( 124) },
    {  INT8_C(  88),
       INT8_C(  75),
           INT8_MAX },
    {  INT8_C(  32),
       INT8_C( 124),
           INT8_MAX },
    { -INT8_C(  95),
      -INT8_C(  49),
           INT8_MIN },
    { -INT8_C( 102),
       INT8_C(  38),
      -INT8_C(  64) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    int8_t r = simde_vqaddb_s8(test_vec[i].a, test_vec[i].b);

    simde_assert_equal_i8(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    int8_t a = simde_test_codegen_random_i8();
    int8_t b = simde_test_codegen_random_i8();
    int8_t r = simde_vqaddb_s8(a, b);

    simde_test_codegen_write_i8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_i8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vqaddh_s16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int16_t a;
    int16_t b;
    int16_t r;
  } test_vec[] = {
    { -INT16_C( 11727),
      -INT16_C(  7161),
      -INT16_C( 18888) },
    {  INT16_C( 29017),
      -INT16_C( 13336),
       INT16_C( 15681) },
    {  INT16_C( 21856),
      -INT16_C( 24160),
      -INT16_C(  2304) },
    {  INT16_C( 32040),
      -INT16_C( 18828),
       INT16_C( 13212) },
    {  INT16_C( 18671),
       INT16_C( 31739),
            INT16_MAX },
    { -INT16_C( 18049),
      -INT16_C( 17707),
            INT16_MIN },
    {  INT16_C(  2161),
      -INT16_C( 28800),
      -INT16_C( 26639) },
    {  INT16_C( 28052),
      -INT16_C( 14641),
       INT16_C( 13411) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    int16_t r = simde_vqaddh_s16(test_vec[i].a, test_vec[i].b);

    simde_assert_equal_i16(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    int16_t a = simde_test_codegen_random_i16();
    int16_t b = simde_test_codegen_random_i16();
    int16_t r = simde_vqaddh_s16(a, b);

    simde_test_codegen_write_i16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_i16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vqadds_s32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int32_t a;
    int32_t b;
    int32_t r;
  } test_vec[] = {
    { -INT32_C(  1924326973),
       INT32_C(      676628),
      -INT32_C(  1923650345) },
    {  INT32_C(  1307766957),
      -INT32_C(   113624017),
       INT32_C(  1194142940) },
    { -INT32_C(   921041363),
      -INT32_C(  1022157195),
      -INT32_C(  1943198558) },
    {  INT32_C(  1938109522),
       INT32_C(  1742412708),
                 INT32_MAX },
    {  INT32_C(  1223960628),
       INT32_C(   675872635),
       INT32_C(  1899833263) },
    {  INT32_C(   510999535),
      -INT32_C(  1541951369),
      -INT32_C(  1030951834) },
    {  INT32_C(   745419190),
      -INT32_C(  1561362096),
      -INT32_C(   815942906) },
    {  INT32_C(  1511355573),
      -INT32_C(   993922929),
       INT32_C(   517432644) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    int32_t r = simde_vqadds_s32(test_vec[i].a, test_vec[i].b);

    simde_assert_equal_i32(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    int32_t a = simde_test_codegen_random_i32();
    int32_t b = simde_test_codegen_random_i32();
    int32_t r = simde_vqadds_s32(a, b);

    simde_test_codegen_write_i32(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_i32(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vqaddd_s64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int64_t a;
    int64_t b;
    int64_t r;
  } test_vec[] = {
    { -INT64_C(  340247776837815537),
       INT64_C( 3360683632828815009),
       INT64_C( 3020435855990999472) },
    {  INT64_C( 6414212653139999150),
      -INT64_C( 1181778323891955332),
       INT64_C( 5232434329248043818) },
    {  INT64_C( 7213452425197097133),
      -INT64_C( 7958316966115190934),
      -INT64_C(  744864540918093801) },
    {  INT64_C( 2296594619730872089),
       INT64_C( 3516443261144205821),
       INT64_C( 5813037880875077910) },
    { -INT64_C( 7448554466647680646),
      -INT64_C( 2866955959388315966),
                          INT64_MIN },
    {  INT64_C( 8651201011724998477),
      -INT64_C( 4181274173947682746),
       INT64_C( 4469926837777315731) },
    {  INT64_C( 8629077984009144827),
      -INT64_C( 8387582401519503358),
       INT64_C(  241495582489641469) },
    {  INT64_C( 8907147219098662825),
       INT64_C( 1079524787921154539),
                          INT64_MAX }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    int64_t r = simde_vqaddd_s64(test_vec[i].a, test_vec[i].b);

    simde_assert_equal_i64(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    int64_t a = simde_test_codegen_random_i64();
    int64_t b = simde_test_codegen_random_i64();
    int64_t r = simde_vqaddd_s64(a, b);

    simde_test_codegen_write_i64(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_i64(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i64(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vqaddb_u8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint8_t a;
    uint8_t b;
    uint8_t r;
  } test_vec[] = {
    { UINT8_C(138),
      UINT8_C(251),
         UINT8_MAX },
    { UINT8_C( 66),
      UINT8_C(220),
         UINT8_MAX },
    { UINT8_C( 74),
      UINT8_C(241),
         UINT8_MAX },
    { UINT8_C(  3),
      UINT8_C( 37),
      UINT8_C( 40) },
    { UINT8_C( 75),
      UINT8_C(226),
         UINT8_MAX },
    { UINT8_C(118),
      UINT8_C(137),
         UINT8_MAX },
    { UINT8_C(238),
      UINT8_C( 97),
         UINT8_MAX },
    { UINT8_C(103),
      UINT8_C(148),
      UINT8_C(251) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    uint8_t r = simde_vqaddb_u8(test_vec[i].a, test_vec[i].b);

    simde_assert_equal_u8(r, test_vec[i].r);
  }
  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    uint8_t a = simde_test_codegen_random_u8();
    uint8_t b = simde_test_codegen_random_u8();
    uint8_t r = simde_vqaddb_u8(a, b);

    simde_test_codegen_write_u8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_u8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_u8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vqaddh_u16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint16_t a;
    uint16_t b;
    uint16_t r;
  } test_vec[] = {
    { UINT16_C(16243),
      UINT16_C(65009),
           UINT16_MAX },
    { UINT16_C(20266),
      UINT16_C(14387),
      UINT16_C(34653) },
    { UINT16_C( 2966),
      UINT16_C(24188),
      UINT16_C(27154) },
    { UINT16_C(53306),
      UINT16_C(50252),
           UINT16_MAX },
    { UINT16_C(36555),
      UINT16_C( 5537),
      UINT16_C(42092) },
    { UINT16_C(42111),
      UINT16_C(51771),
           UINT16_MAX },
    { UINT16_C(45447),
      UINT16_C(30035),
           UINT16_MAX },
    { UINT16_C(47890),
      UINT16_C(34057),
           UINT16_MAX }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    uint16_t r = simde_vqaddh_u16(test_vec[i].a, test_vec[i].b);

    simde_assert_equal_u16(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    uint16_t a = simde_test_codegen_random_u16();
    uint16_t b = simde_test_codegen_random_u16();
    uint16_t r = simde_vqaddh_u16(a, b);

    simde_test_codegen_write_u16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_u16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_u16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vqadds_u32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint32_t a;
    uint32_t b;
    uint32_t r;
  } test_vec[] = {
    { UINT32_C( 612629242),
      UINT32_C(3747460681),
                UINT32_MAX },
    { UINT32_C(4215134657),
      UINT32_C(1958775465),
                UINT32_MAX },
    { UINT32_C(2559140120),
      UINT32_C(2355282949),
                UINT32_MAX },
    { UINT32_C(2281813622),
      UINT32_C(1796082545),
      UINT32_C(4077896167) },
    { UINT32_C(1334808837),
      UINT32_C( 137292871),
      UINT32_C(1472101708) },
    { UINT32_C(1845783749),
      UINT32_C( 249742582),
      UINT32_C(2095526331) },
    { UINT32_C( 715549733),
      UINT32_C(2797013296),
      UINT32_C(3512563029) },
    { UINT32_C( 808433855),
      UINT32_C(3382394307),
      UINT32_C(4190828162) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    uint32_t r = simde_vqadds_u32(test_vec[i].a, test_vec[i].b);

    simde_assert_equal_u32(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    uint32_t a = simde_test_codegen_random_u32();
    uint32_t b = simde_test_codegen_random_u32();
    uint32_t r = simde_vqadds_u32(a, b);

    simde_test_codegen_write_u32(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_u32(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_u32(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vqaddd_u64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint64_t a;
    uint64_t b;
    uint64_t r;
  } test_vec[] = {
    { UINT64_C(11868383189900131719),
      UINT64_C(14734087086196248751),
                         UINT64_MAX },
    { UINT64_C( 7756480039837890037),
      UINT64_C(12583229052650908031),
                         UINT64_MAX },
    { UINT64_C( 9070143878369891994),
      UINT64_C( 3990158769449026671),
      UINT64_C(13060302647818918665) },
    { UINT64_C( 6684755670146830553),
      UINT64_C(11368367503293966062),
      UINT64_C(18053123173440796615) },
    { UINT64_C(13668346040092766053),
      UINT64_C(15597847870258027260),
                         UINT64_MAX },
    { UINT64_C(14644008195626031103),
      UINT64_C( 2016950410859849565),
      UINT64_C(16660958606485880668) },
    { UINT64_C( 9970966889071760980),
      UINT64_C( 6768699537814564631),
      UINT64_C(16739666426886325611) },
    { UINT64_C( 8484908248979874071),
      UINT64_C(11127219603306357146),
                         UINT64_MAX }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    uint64_t r = simde_vqaddd_u64(test_vec[i].a, test_vec[i].b);

    simde_assert_equal_u64(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    uint64_t a = simde_test_codegen_random_u64();
    uint64_t b = simde_test_codegen_random_u64();
    uint64_t r = simde_vqaddd_u64(a, b);

    simde_test_codegen_write_u64(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_u64(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_u64(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vqadd_s8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int8_t a[8];
    int8_t b[8];
    int8_t r[8];
  } test_vec[] = {
    { { -INT8_C(  88), -INT8_C(  39), -INT8_C( 126), -INT8_C(  86), -INT8_C( 106), -INT8_C(  49),  INT8_C(  70),  INT8_C( 124) },
      {  INT8_C(  64), -INT8_C(  91),  INT8_C(  64),  INT8_C(  47),  INT8_C(  38),  INT8_C(  91), -INT8_C(  80), -INT8_C(  15) },
      { -INT8_C(  24),      INT8_MIN, -INT8_C(  62), -INT8_C(  39), -INT8_C(  68),  INT8_C(  42), -INT8_C(  10),  INT8_C( 109) } },
    { { -INT8_C(  18), -INT8_C( 104),  INT8_C( 112),  INT8_C(  14),  INT8_C(  66),  INT8_C(  72), -INT8_C(  83), -INT8_C(  71) },
      { -INT8_C( 106), -INT8_C( 119),  INT8_C(  15), -INT8_C(  10),  INT8_C(  78),  INT8_C(  70),      INT8_MAX, -INT8_C(   9) },
      { -INT8_C( 124),      INT8_MIN,      INT8_MAX,  INT8_C(   4),      INT8_MAX,      INT8_MAX,  INT8_C(  44), -INT8_C(  80) } },
    { {  INT8_C(  31),  INT8_C(   1), -INT8_C(  95), -INT8_C(  74), -INT8_C(  48), -INT8_C(  25),  INT8_C(  50),  INT8_C(  16) },
      { -INT8_C( 116),  INT8_C( 114),  INT8_C(  64), -INT8_C(  78), -INT8_C(  51), -INT8_C(  16), -INT8_C(  93), -INT8_C(  69) },
      { -INT8_C(  85),  INT8_C( 115), -INT8_C(  31),      INT8_MIN, -INT8_C(  99), -INT8_C(  41), -INT8_C(  43), -INT8_C(  53) } },
    { { -INT8_C( 119),  INT8_C(  19), -INT8_C(  54), -INT8_C(  53),  INT8_C(  92),  INT8_C( 119), -INT8_C( 124), -INT8_C(  14) },
      {  INT8_C(   0), -INT8_C( 109), -INT8_C(  23),  INT8_C(  79), -INT8_C(  39),  INT8_C( 104),  INT8_C(  70), -INT8_C(   7) },
      { -INT8_C( 119), -INT8_C(  90), -INT8_C(  77),  INT8_C(  26),  INT8_C(  53),      INT8_MAX, -INT8_C(  54), -INT8_C(  21) } },
    { {  INT8_C( 105), -INT8_C(  25), -INT8_C(  81),  INT8_C(  58), -INT8_C(  50), -INT8_C(  31),  INT8_C(  74),  INT8_C(  90) },
      {  INT8_C(  83), -INT8_C( 118),  INT8_C(  12),  INT8_C(  32),  INT8_C( 123), -INT8_C(  80), -INT8_C(  37),  INT8_C(   4) },
      {      INT8_MAX,      INT8_MIN, -INT8_C(  69),  INT8_C(  90),  INT8_C(  73), -INT8_C( 111),  INT8_C(  37),  INT8_C(  94) } },
    { { -INT8_C(  61), -INT8_C(  91), -INT8_C(  49),  INT8_C(  31),  INT8_C(  29),  INT8_C(  83),  INT8_C(  18),  INT8_C(  29) },
      { -INT8_C(  25), -INT8_C(   5),  INT8_C( 108), -INT8_C(  64),  INT8_C(  99), -INT8_C(  78), -INT8_C(  71), -INT8_C(  52) },
      { -INT8_C(  86), -INT8_C(  96),  INT8_C(  59), -INT8_C(  33),      INT8_MAX,  INT8_C(   5), -INT8_C(  53), -INT8_C(  23) } },
    { { -INT8_C( 103),  INT8_C( 104),  INT8_C(   6),  INT8_C( 103),  INT8_C(  73),  INT8_C(  81), -INT8_C(  63), -INT8_C( 100) },
      { -INT8_C(  37), -INT8_C(  50), -INT8_C(  68),  INT8_C(  86),  INT8_C( 126), -INT8_C( 104),  INT8_C(  90),  INT8_C(  65) },
      {      INT8_MIN,  INT8_C(  54), -INT8_C(  62),      INT8_MAX,      INT8_MAX, -INT8_C(  23),  INT8_C(  27), -INT8_C(  35) } },
    { {  INT8_C(  61),  INT8_C(  41),  INT8_C(  97),  INT8_C(  90),  INT8_C( 125),  INT8_C( 115),  INT8_C( 120),  INT8_C( 100) },
      {  INT8_C( 110), -INT8_C(  28),  INT8_C(  36), -INT8_C(  47), -INT8_C( 105), -INT8_C(  34), -INT8_C(  99),  INT8_C(  48) },
      {      INT8_MAX,  INT8_C(  13),      INT8_MAX,  INT8_C(  43),  INT8_C(  20),  INT8_C(  81),  INT8_C(  21),      INT8_MAX } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int8x8_t a = simde_vld1_s8(test_vec[i].a);
    simde_int8x8_t b = simde_vld1_s8(test_vec[i].b);
    simde_int8x8_t r = simde_vqadd_s8(a, b);

    simde_test_arm_neon_assert_equal_i8x8(r, simde_vld1_s8(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int8x8_t a = simde_test_arm_neon_random_i8x8();
    simde_int8x8_t b = simde_test_arm_neon_random_i8x8();
    simde_int8x8_t r = simde_vqadd_s8(a, b);

    simde_test_arm_neon_write_i8x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i8x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i8x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vqadd_s16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int16_t a[4];
    int16_t b[4];
    int16_t r[4];
  } test_vec[] = {
    { { -INT16_C( 18685),  INT16_C(  3599),  INT16_C(   636), -INT16_C( 12418) },
      {  INT16_C(  7207),  INT16_C( 12614),  INT16_C( 27874),  INT16_C( 29127) },
      { -INT16_C( 11478),  INT16_C( 16213),  INT16_C( 28510),  INT16_C( 16709) } },
    { {  INT16_C(  3398),  INT16_C(  3218),  INT16_C( 18051),  INT16_C(    32) },
      { -INT16_C( 20943),  INT16_C( 15609),  INT16_C( 11436), -INT16_C( 20499) },
      { -INT16_C( 17545),  INT16_C( 18827),  INT16_C( 29487), -INT16_C( 20467) } },
    { { -INT16_C(   796),  INT16_C( 24765),  INT16_C( 15358),  INT16_C(  9519) },
      {  INT16_C( 30295),  INT16_C( 14679),  INT16_C(  7906),  INT16_C( 10410) },
      {  INT16_C( 29499),       INT16_MAX,  INT16_C( 23264),  INT16_C( 19929) } },
    { {  INT16_C( 15659), -INT16_C( 20940),  INT16_C( 21635), -INT16_C( 19026) },
      { -INT16_C( 22782), -INT16_C( 20751), -INT16_C(  8492), -INT16_C( 18339) },
      { -INT16_C(  7123),       INT16_MIN,  INT16_C( 13143),       INT16_MIN } },
    { {  INT16_C(  6874), -INT16_C(  9960),  INT16_C( 18262), -INT16_C( 20994) },
      {  INT16_C( 21949), -INT16_C( 24601), -INT16_C( 28301), -INT16_C( 24632) },
      {  INT16_C( 28823),       INT16_MIN, -INT16_C( 10039),       INT16_MIN } },
    { { -INT16_C(   818),  INT16_C( 21069), -INT16_C(   943),  INT16_C( 21255) },
      { -INT16_C(  1885),  INT16_C( 30466),  INT16_C( 24535), -INT16_C( 20177) },
      { -INT16_C(  2703),       INT16_MAX,  INT16_C( 23592),  INT16_C(  1078) } },
    { {  INT16_C( 18298), -INT16_C( 12150), -INT16_C( 30321),  INT16_C( 19581) },
      {  INT16_C( 25822),  INT16_C( 21228), -INT16_C( 19210), -INT16_C( 15119) },
      {       INT16_MAX,  INT16_C(  9078),       INT16_MIN,  INT16_C(  4462) } },
    { {  INT16_C( 16048),  INT16_C(   278),  INT16_C(  7482), -INT16_C(  8619) },
      {  INT16_C( 22294), -INT16_C(  4779), -INT16_C( 31306),  INT16_C( 12446) },
      {       INT16_MAX, -INT16_C(  4501), -INT16_C( 23824),  INT16_C(  3827) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x4_t a = simde_vld1_s16(test_vec[i].a);
    simde_int16x4_t b = simde_vld1_s16(test_vec[i].b);
    simde_int16x4_t r = simde_vqadd_s16(a, b);

    simde_test_arm_neon_assert_equal_i16x4(r, simde_vld1_s16(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int16x4_t a = simde_test_arm_neon_random_i16x4();
    simde_int16x4_t b = simde_test_arm_neon_random_i16x4();
    simde_int16x4_t r = simde_vqadd_s16(a, b);

    simde_test_arm_neon_write_i16x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i16x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i16x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vqadd_s32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int32_t a[2];
    int32_t b[2];
    int32_t r[2];
  } test_vec[] = {
    { {  INT32_C(  1708613354), -INT32_C(   360181531) },
      { -INT32_C(  1233544421), -INT32_C(   501103337) },
      {  INT32_C(   475068933), -INT32_C(   861284868) } },
    { { -INT32_C(   455086879),  INT32_C(  1497246780) },
      {  INT32_C(  1790669567), -INT32_C(   235132410) },
      {  INT32_C(  1335582688),  INT32_C(  1262114370) } },
    { {  INT32_C(  1851184009), -INT32_C(    10887452) },
      { -INT32_C(  1850289543),  INT32_C(  2020857751) },
      {  INT32_C(      894466),  INT32_C(  2009970299) } },
    { {  INT32_C(     6050755),  INT32_C(  2136578687) },
      {  INT32_C(   334042380), -INT32_C(   939203265) },
      {  INT32_C(   340093135),  INT32_C(  1197375422) } },
    { { -INT32_C(  1674093896), -INT32_C(  1298362311) },
      { -INT32_C(   113028510), -INT32_C(   328091863) },
      { -INT32_C(  1787122406), -INT32_C(  1626454174) } },
    { { -INT32_C(  1980969718),  INT32_C(  1929922151) },
      { -INT32_C(  1702432421), -INT32_C(  1889301802) },
      {            INT32_MIN,  INT32_C(    40620349) } },
    { {  INT32_C(   506174181), -INT32_C(  1932474582) },
      {  INT32_C(  1116017689), -INT32_C(   718276917) },
      {  INT32_C(  1622191870),            INT32_MIN } },
    { {  INT32_C(   710810563), -INT32_C(  1130535071) },
      {  INT32_C(   794240088), -INT32_C(  1816216914) },
      {  INT32_C(  1505050651),            INT32_MIN } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x2_t a = simde_vld1_s32(test_vec[i].a);
    simde_int32x2_t b = simde_vld1_s32(test_vec[i].b);
    simde_int32x2_t r = simde_vqadd_s32(a, b);

    simde_test_arm_neon_assert_equal_i32x2(r, simde_vld1_s32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int32x2_t a = simde_test_arm_neon_random_i32x2();
    simde_int32x2_t b = simde_test_arm_neon_random_i32x2();
    simde_int32x2_t r = simde_vqadd_s32(a, b);

    simde_test_arm_neon_write_i32x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i32x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i32x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vqadd_s64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int64_t a[1];
    int64_t b[1];
    int64_t r[1];
  } test_vec[] = {
    { { -INT64_C( 6407494046951039651) },
      { -INT64_C(  969804030585533899) },
      { -INT64_C( 7377298077536573550) } },
    { { -INT64_C(  756558871846176206) },
      {  INT64_C( 3565986500388755763) },
      {  INT64_C( 2809427628542579557) } },
    { { -INT64_C( 4589979959597430390) },
      {  INT64_C( 5005928091048444711) },
      {  INT64_C(  415948131451014321) } },
    { { -INT64_C( 4213209180864222756) },
      { -INT64_C( 9202148206401943226) },
      {                     INT64_MIN } },
    { { -INT64_C( 7549593798898658321) },
      { -INT64_C( 3508138139130637577) },
      {                     INT64_MIN } },
    { {  INT64_C( 8023137625942621439) },
      { -INT64_C( 7464201085452205326) },
      {  INT64_C(  558936540490416113) } },
    { { -INT64_C(  274916365824782297) },
      { -INT64_C( 2061989040168153697) },
      { -INT64_C( 2336905405992935994) } },
    { { -INT64_C( 6959242656317324333) },
      { -INT64_C( 1130419137071746033) },
      { -INT64_C( 8089661793389070366) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int64x1_t a = simde_vld1_s64(test_vec[i].a);
    simde_int64x1_t b = simde_vld1_s64(test_vec[i].b);
    simde_int64x1_t r = simde_vqadd_s64(a, b);

    simde_test_arm_neon_assert_equal_i64x1(r, simde_vld1_s64(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int64x1_t a = simde_test_arm_neon_random_i64x1();
    simde_int64x1_t b = simde_test_arm_neon_random_i64x1();
    simde_int64x1_t r = simde_vqadd_s64(a, b);

    simde_test_arm_neon_write_i64x1(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i64x1(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i64x1(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vqadd_u8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint8_t a[8];
    uint8_t b[8];
    uint8_t r[8];
  } test_vec[] = {
    { { UINT8_C(117), UINT8_C(158), UINT8_C(103), UINT8_C( 86), UINT8_C(230), UINT8_C( 91), UINT8_C( 90), UINT8_C( 30) },
      { UINT8_C(105), UINT8_C( 10), UINT8_C( 94), UINT8_C( 46), UINT8_C(204), UINT8_C(120), UINT8_C( 27), UINT8_C( 58) },
      { UINT8_C(222), UINT8_C(168), UINT8_C(197), UINT8_C(132),    UINT8_MAX, UINT8_C(211), UINT8_C(117), UINT8_C( 88) } },
    { { UINT8_C( 43), UINT8_C(155), UINT8_C(114), UINT8_C(189), UINT8_C( 69), UINT8_C(227), UINT8_C(189), UINT8_C(131) },
      { UINT8_C(141), UINT8_C(146), UINT8_C(231), UINT8_C(209), UINT8_C(205), UINT8_C( 58), UINT8_C(250), UINT8_C( 66) },
      { UINT8_C(184),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(197) } },
    { { UINT8_C(217), UINT8_C( 98), UINT8_C(152), UINT8_C(191), UINT8_C(189), UINT8_C(243), UINT8_C(222), UINT8_C( 38) },
      { UINT8_C(253), UINT8_C( 60), UINT8_C( 84), UINT8_C(201), UINT8_C(180), UINT8_C(111), UINT8_C(  4), UINT8_C(223) },
      {    UINT8_MAX, UINT8_C(158), UINT8_C(236),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(226),    UINT8_MAX } },
    { { UINT8_C( 10), UINT8_C(118), UINT8_C(156), UINT8_C( 79), UINT8_C( 89), UINT8_C( 89), UINT8_C(210), UINT8_C(231) },
      { UINT8_C(235), UINT8_C(186), UINT8_C(184), UINT8_C(184), UINT8_C(244), UINT8_C(178), UINT8_C(251), UINT8_C(205) },
      { UINT8_C(245),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX } },
    { { UINT8_C( 20), UINT8_C(147), UINT8_C(141), UINT8_C(209), UINT8_C(134), UINT8_C(107), UINT8_C(247), UINT8_C(132) },
      { UINT8_C(167), UINT8_C( 76), UINT8_C( 77), UINT8_C( 91), UINT8_C(187), UINT8_C( 81), UINT8_C( 58), UINT8_C(198) },
      { UINT8_C(187), UINT8_C(223), UINT8_C(218),    UINT8_MAX,    UINT8_MAX, UINT8_C(188),    UINT8_MAX,    UINT8_MAX } },
    { { UINT8_C(200), UINT8_C(214), UINT8_C( 21), UINT8_C( 33), UINT8_C( 48), UINT8_C(232), UINT8_C(  8), UINT8_C( 27) },
      { UINT8_C(162), UINT8_C(192), UINT8_C(212), UINT8_C(150), UINT8_C(115), UINT8_C(207), UINT8_C(100), UINT8_C(135) },
      {    UINT8_MAX,    UINT8_MAX, UINT8_C(233), UINT8_C(183), UINT8_C(163),    UINT8_MAX, UINT8_C(108), UINT8_C(162) } },
    { { UINT8_C( 98), UINT8_C(241), UINT8_C( 89), UINT8_C(233), UINT8_C( 92), UINT8_C( 80), UINT8_C(109), UINT8_C(  3) },
      { UINT8_C(156), UINT8_C(186), UINT8_C( 94), UINT8_C( 88), UINT8_C( 12), UINT8_C(152), UINT8_C( 30), UINT8_C(212) },
      { UINT8_C(254),    UINT8_MAX, UINT8_C(183),    UINT8_MAX, UINT8_C(104), UINT8_C(232), UINT8_C(139), UINT8_C(215) } },
    { { UINT8_C(110), UINT8_C( 51), UINT8_C(245), UINT8_C(158), UINT8_C( 27), UINT8_C(254), UINT8_C(186), UINT8_C(189) },
      { UINT8_C(190), UINT8_C(142), UINT8_C( 84), UINT8_C( 49), UINT8_C( 93), UINT8_C(184), UINT8_C(185), UINT8_C(191) },
      {    UINT8_MAX, UINT8_C(193),    UINT8_MAX, UINT8_C(207), UINT8_C(120),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint8x8_t a = simde_vld1_u8(test_vec[i].a);
    simde_uint8x8_t b = simde_vld1_u8(test_vec[i].b);
    simde_uint8x8_t r = simde_vqadd_u8(a, b);

    simde_test_arm_neon_assert_equal_u8x8(r, simde_vld1_u8(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint8x8_t a = simde_test_arm_neon_random_u8x8();
    simde_uint8x8_t b = simde_test_arm_neon_random_u8x8();
    simde_uint8x8_t r = simde_vqadd_u8(a, b);

    simde_test_arm_neon_write_u8x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u8x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u8x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vqadd_u16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint16_t a[4];
    uint16_t b[4];
    uint16_t r[4];
  } test_vec[] = {
    { { UINT16_C(11966), UINT16_C(44150), UINT16_C(30001), UINT16_C( 2927) },
      { UINT16_C(10232), UINT16_C(33651), UINT16_C( 4051), UINT16_C(25723) },
      { UINT16_C(22198),      UINT16_MAX, UINT16_C(34052), UINT16_C(28650) } },
    { { UINT16_C(26150), UINT16_C(62035), UINT16_C(51754), UINT16_C(33204) },
      { UINT16_C(17207), UINT16_C(27830), UINT16_C(15972), UINT16_C( 9059) },
      { UINT16_C(43357),      UINT16_MAX,      UINT16_MAX, UINT16_C(42263) } },
    { { UINT16_C(55660), UINT16_C(40399), UINT16_C(15951), UINT16_C(18344) },
      { UINT16_C( 7014), UINT16_C(14794), UINT16_C(17707), UINT16_C(20893) },
      { UINT16_C(62674), UINT16_C(55193), UINT16_C(33658), UINT16_C(39237) } },
    { { UINT16_C(61611), UINT16_C(54851), UINT16_C(63419), UINT16_C(62039) },
      { UINT16_C( 3642), UINT16_C(40798), UINT16_C(49484), UINT16_C(47298) },
      { UINT16_C(65253),      UINT16_MAX,      UINT16_MAX,      UINT16_MAX } },
    { { UINT16_C(37274), UINT16_C(59733), UINT16_C(65232), UINT16_C(13872) },
      { UINT16_C(64281), UINT16_C(17519), UINT16_C( 3136), UINT16_C(60566) },
      {      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX } },
    { { UINT16_C(55804), UINT16_C(47042), UINT16_C( 6609), UINT16_C( 2985) },
      { UINT16_C( 1831), UINT16_C(29610), UINT16_C(27848), UINT16_C(25387) },
      { UINT16_C(57635),      UINT16_MAX, UINT16_C(34457), UINT16_C(28372) } },
    { { UINT16_C(33278), UINT16_C(52812), UINT16_C(32127), UINT16_C(38916) },
      { UINT16_C(29560), UINT16_C(47325), UINT16_C(29567), UINT16_C(31652) },
      { UINT16_C(62838),      UINT16_MAX, UINT16_C(61694),      UINT16_MAX } },
    { { UINT16_C(26188), UINT16_C( 7475), UINT16_C(56448), UINT16_C(42793) },
      { UINT16_C(54244), UINT16_C(44059), UINT16_C(17984), UINT16_C(15887) },
      {      UINT16_MAX, UINT16_C(51534),      UINT16_MAX, UINT16_C(58680) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint16x4_t a = simde_vld1_u16(test_vec[i].a);
    simde_uint16x4_t b = simde_vld1_u16(test_vec[i].b);
    simde_uint16x4_t r = simde_vqadd_u16(a, b);
    simde_test_arm_neon_assert_equal_u16x4(r, simde_vld1_u16(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint16x4_t a = simde_test_arm_neon_random_u16x4();
    simde_uint16x4_t b = simde_test_arm_neon_random_u16x4();
    simde_uint16x4_t r = simde_vqadd_u16(a, b);

    simde_test_arm_neon_write_u16x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u16x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u16x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vqadd_u32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint32_t a[2];
    uint32_t b[2];
    uint32_t r[2];
  } test_vec[] = {
    { { UINT32_C(  94467099), UINT32_C(1607547519) },
      { UINT32_C(1088442987), UINT32_C( 531747472) },
      { UINT32_C(1182910086), UINT32_C(2139294991) } },
    { { UINT32_C(3018317671), UINT32_C(4236516707) },
      { UINT32_C( 963062607), UINT32_C(1805733967) },
      { UINT32_C(3981380278),           UINT32_MAX } },
    { { UINT32_C(1148207813), UINT32_C(3886301564) },
      { UINT32_C( 606569619), UINT32_C(3192117334) },
      { UINT32_C(1754777432),           UINT32_MAX } },
    { { UINT32_C( 460401336), UINT32_C(2534929992) },
      { UINT32_C(1909489185), UINT32_C(2497475023) },
      { UINT32_C(2369890521),           UINT32_MAX } },
    { { UINT32_C( 802704563), UINT32_C( 555121806) },
      { UINT32_C(1464155393), UINT32_C(3440740373) },
      { UINT32_C(2266859956), UINT32_C(3995862179) } },
    { { UINT32_C(4226385843), UINT32_C(2660368509) },
      { UINT32_C(1309631103), UINT32_C(2263018451) },
      {           UINT32_MAX,           UINT32_MAX } },
    { { UINT32_C(3333798456), UINT32_C( 954714935) },
      { UINT32_C( 495922440), UINT32_C(1760273845) },
      { UINT32_C(3829720896), UINT32_C(2714988780) } },
    { { UINT32_C(2841891884), UINT32_C(1397224916) },
      { UINT32_C( 715216727), UINT32_C(2058388290) },
      { UINT32_C(3557108611), UINT32_C(3455613206) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint32x2_t a = simde_vld1_u32(test_vec[i].a);
    simde_uint32x2_t b = simde_vld1_u32(test_vec[i].b);
    simde_uint32x2_t r = simde_vqadd_u32(a, b);
    simde_test_arm_neon_assert_equal_u32x2(r, simde_vld1_u32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint32x2_t a = simde_test_arm_neon_random_u32x2();
    simde_uint32x2_t b = simde_test_arm_neon_random_u32x2();
    simde_uint32x2_t r = simde_vqadd_u32(a, b);

    simde_test_arm_neon_write_u32x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u32x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vqadd_u64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint64_t a[1];
    uint64_t b[1];
    uint64_t r[1];
  } test_vec[] = {
    { { UINT64_C( 7980904046589353852) },
      { UINT64_C( 1728305938133397857) },
      { UINT64_C( 9709209984722751709) } },
    { { UINT64_C( 2205678454715127659) },
      { UINT64_C( 8848910256038185308) },
      { UINT64_C(11054588710753312967) } },
    { { UINT64_C( 8909060253653810243) },
      { UINT64_C(16084739608838686217) },
      {                    UINT64_MAX } },
    { { UINT64_C(13802628386871132048) },
      { UINT64_C(16918644631544726354) },
      {                    UINT64_MAX } },
    { { UINT64_C(13973195990776111445) },
      { UINT64_C( 8024319282771093001) },
      {                    UINT64_MAX } },
    { { UINT64_C(11853027073396148571) },
      { UINT64_C( 4107213462431975789) },
      { UINT64_C(15960240535828124360) } },
    { { UINT64_C(16977323619508493857) },
      { UINT64_C(17601973458158780151) },
      {                    UINT64_MAX } },
    { { UINT64_C(18033874767248041038) },
      { UINT64_C( 1951482484148353786) },
      {                    UINT64_MAX } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint64x1_t a = simde_vld1_u64(test_vec[i].a);
    simde_uint64x1_t b = simde_vld1_u64(test_vec[i].b);
    simde_uint64x1_t r = simde_vqadd_u64(a, b);
    simde_test_arm_neon_assert_equal_u64x1(r, simde_vld1_u64(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint64x1_t a = simde_test_arm_neon_random_u64x1();
    simde_uint64x1_t b = simde_test_arm_neon_random_u64x1();
    simde_uint64x1_t r = simde_vqadd_u64(a, b);

    simde_test_arm_neon_write_u64x1(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u64x1(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u64x1(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vqaddq_s8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int8_t a[16];
    int8_t b[16];
    int8_t r[16];
  } test_vec[] = {
    { {  INT8_C(  51), -INT8_C(  81),  INT8_C(   4), -INT8_C( 100), -INT8_C( 121), -INT8_C(  54),  INT8_C(  38),  INT8_C( 101),
         INT8_C(  84),  INT8_C(  97), -INT8_C( 115),  INT8_C(  67),  INT8_C( 116), -INT8_C( 108), -INT8_C(  16), -INT8_C(  88) },
      {  INT8_C(  79),  INT8_C(  77), -INT8_C(   7), -INT8_C(  47), -INT8_C(  36),  INT8_C(  48), -INT8_C(  22),  INT8_C(  40),
        -INT8_C(  24), -INT8_C(  37),  INT8_C(  32), -INT8_C(  72), -INT8_C(  71), -INT8_C(   8), -INT8_C(  12), -INT8_C(  19) },
      {      INT8_MAX, -INT8_C(   4), -INT8_C(   3),      INT8_MIN,      INT8_MIN, -INT8_C(   6),  INT8_C(  16),      INT8_MAX,
         INT8_C(  60),  INT8_C(  60), -INT8_C(  83), -INT8_C(   5),  INT8_C(  45), -INT8_C( 116), -INT8_C(  28), -INT8_C( 107) } },
    { { -INT8_C(  89), -INT8_C(   8), -INT8_C( 119),  INT8_C(  47), -INT8_C(  61), -INT8_C(  81), -INT8_C( 108),  INT8_C(  23),
         INT8_C(  17),  INT8_C(  33),  INT8_C(  90), -INT8_C( 123), -INT8_C(  75),  INT8_C(  74),  INT8_C(  46),  INT8_C(   4) },
      { -INT8_C( 104),  INT8_C(  39), -INT8_C(  42),  INT8_C( 116),  INT8_C(  87), -INT8_C(  64), -INT8_C(  99),  INT8_C(  63),
        -INT8_C( 101), -INT8_C(  67), -INT8_C(   9),  INT8_C(  84), -INT8_C(  75), -INT8_C(  20),  INT8_C(  65),  INT8_C(  93) },
      {      INT8_MIN,  INT8_C(  31),      INT8_MIN,      INT8_MAX,  INT8_C(  26),      INT8_MIN,      INT8_MIN,  INT8_C(  86),
        -INT8_C(  84), -INT8_C(  34),  INT8_C(  81), -INT8_C(  39),      INT8_MIN,  INT8_C(  54),  INT8_C( 111),  INT8_C(  97) } },
    { { -INT8_C(  28), -INT8_C(  53), -INT8_C( 116), -INT8_C(  89),  INT8_C( 122),  INT8_C(  32), -INT8_C(  65), -INT8_C( 117),
         INT8_C(  66),  INT8_C(  25),  INT8_C(  17), -INT8_C(   9),  INT8_C( 100),  INT8_C(  63), -INT8_C(   4), -INT8_C(   4) },
      {  INT8_C( 102), -INT8_C(  46),  INT8_C( 112), -INT8_C(  67), -INT8_C( 110),  INT8_C(  13), -INT8_C(   3),  INT8_C(  45),
        -INT8_C(  53), -INT8_C(  12), -INT8_C( 127),      INT8_MIN, -INT8_C(  32), -INT8_C(  61), -INT8_C(  35), -INT8_C(  59) },
      {  INT8_C(  74), -INT8_C(  99), -INT8_C(   4),      INT8_MIN,  INT8_C(  12),  INT8_C(  45), -INT8_C(  68), -INT8_C(  72),
         INT8_C(  13),  INT8_C(  13), -INT8_C( 110),      INT8_MIN,  INT8_C(  68),  INT8_C(   2), -INT8_C(  39), -INT8_C(  63) } },
    { { -INT8_C( 114),  INT8_C( 105),  INT8_C( 108),  INT8_C(   8), -INT8_C( 118),  INT8_C(  43), -INT8_C( 108), -INT8_C(  52),
         INT8_C(  69), -INT8_C(  91), -INT8_C(  61), -INT8_C(  87), -INT8_C(  28), -INT8_C(  65), -INT8_C(  91),  INT8_C(  74) },
      { -INT8_C( 111),  INT8_C(  21),  INT8_C(   7),  INT8_C(  35),  INT8_C(  35),  INT8_C(   4),  INT8_C(  80), -INT8_C(  18),
        -INT8_C(   7), -INT8_C(  46),  INT8_C( 110), -INT8_C(  39), -INT8_C( 107),  INT8_C(  76), -INT8_C(  98),  INT8_C(  35) },
      {      INT8_MIN,  INT8_C( 126),  INT8_C( 115),  INT8_C(  43), -INT8_C(  83),  INT8_C(  47), -INT8_C(  28), -INT8_C(  70),
         INT8_C(  62),      INT8_MIN,  INT8_C(  49), -INT8_C( 126),      INT8_MIN,  INT8_C(  11),      INT8_MIN,  INT8_C( 109) } },
    { { -INT8_C(  75),  INT8_C(  11),  INT8_C(  43),  INT8_C(  63),  INT8_C(  54), -INT8_C(  65),  INT8_C(  11),  INT8_C( 123),
         INT8_C( 100), -INT8_C(  49),  INT8_C(  36),  INT8_C(  72), -INT8_C( 114), -INT8_C(  55), -INT8_C( 110),  INT8_C(  32) },
      { -INT8_C(  33), -INT8_C( 102),  INT8_C(  67),  INT8_C(   2), -INT8_C(  98), -INT8_C( 108), -INT8_C(  16), -INT8_C( 105),
         INT8_C( 102),  INT8_C(  94),  INT8_C( 113), -INT8_C(   5), -INT8_C(  86),  INT8_C(  15),  INT8_C(  30),  INT8_C(  96) },
      { -INT8_C( 108), -INT8_C(  91),  INT8_C( 110),  INT8_C(  65), -INT8_C(  44),      INT8_MIN, -INT8_C(   5),  INT8_C(  18),
             INT8_MAX,  INT8_C(  45),      INT8_MAX,  INT8_C(  67),      INT8_MIN, -INT8_C(  40), -INT8_C(  80),      INT8_MAX } },
    { {  INT8_C(  26),  INT8_C(  73), -INT8_C(  97),  INT8_C(  81),  INT8_C(   9), -INT8_C(  85), -INT8_C(  52),  INT8_C( 109),
         INT8_C( 122), -INT8_C(  15), -INT8_C(  74),  INT8_C(   8), -INT8_C(  70),  INT8_C(  72),  INT8_C(  40), -INT8_C( 103) },
      { -INT8_C(  30),  INT8_C( 108), -INT8_C( 101), -INT8_C( 127),  INT8_C(   0), -INT8_C( 117),  INT8_C(  24),  INT8_C( 102),
        -INT8_C(  22), -INT8_C( 119),  INT8_C(  97), -INT8_C( 108), -INT8_C( 103),      INT8_MAX, -INT8_C(  12), -INT8_C(  77) },
      { -INT8_C(   4),      INT8_MAX,      INT8_MIN, -INT8_C(  46),  INT8_C(   9),      INT8_MIN, -INT8_C(  28),      INT8_MAX,
         INT8_C( 100),      INT8_MIN,  INT8_C(  23), -INT8_C( 100),      INT8_MIN,      INT8_MAX,  INT8_C(  28),      INT8_MIN } },
    { { -INT8_C(  56), -INT8_C( 108),  INT8_C(   4), -INT8_C(  47),  INT8_C(  63), -INT8_C(  47),  INT8_C(  63), -INT8_C(  71),
        -INT8_C(  62), -INT8_C(  11), -INT8_C(  63),  INT8_C( 124),  INT8_C(  61), -INT8_C(  22),  INT8_C(  22),  INT8_C(  32) },
      {  INT8_C(  86), -INT8_C(  79), -INT8_C(  95),  INT8_C(  86),  INT8_C(  61), -INT8_C(  71), -INT8_C(  68),  INT8_C(  39),
         INT8_C(  67),  INT8_C(  29), -INT8_C(  69), -INT8_C(  36), -INT8_C( 100), -INT8_C(  80), -INT8_C( 113),  INT8_C( 100) },
      {  INT8_C(  30),      INT8_MIN, -INT8_C(  91),  INT8_C(  39),  INT8_C( 124), -INT8_C( 118), -INT8_C(   5), -INT8_C(  32),
         INT8_C(   5),  INT8_C(  18),      INT8_MIN,  INT8_C(  88), -INT8_C(  39), -INT8_C( 102), -INT8_C(  91),      INT8_MAX } },
    { {  INT8_C(  68), -INT8_C( 108),  INT8_C(  54), -INT8_C( 125),  INT8_C( 101),  INT8_C( 117),  INT8_C(  60),  INT8_C(  39),
         INT8_C( 106), -INT8_C(   3), -INT8_C(  93), -INT8_C(  89), -INT8_C(  25), -INT8_C(  71), -INT8_C(  57),  INT8_C(  61) },
      {  INT8_C( 107),  INT8_C( 104), -INT8_C( 109), -INT8_C(  88),  INT8_C(  34),  INT8_C(  79), -INT8_C(  49),  INT8_C( 101),
         INT8_C( 108), -INT8_C( 118),  INT8_C(  65),  INT8_C(   8),  INT8_C(  58), -INT8_C(  48),  INT8_C( 109),  INT8_C( 126) },
      {      INT8_MAX, -INT8_C(   4), -INT8_C(  55),      INT8_MIN,      INT8_MAX,      INT8_MAX,  INT8_C(  11),      INT8_MAX,
             INT8_MAX, -INT8_C( 121), -INT8_C(  28), -INT8_C(  81),  INT8_C(  33), -INT8_C( 119),  INT8_C(  52),      INT8_MAX } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int8x16_t a = simde_vld1q_s8(test_vec[i].a);
    simde_int8x16_t b = simde_vld1q_s8(test_vec[i].b);
    simde_int8x16_t r = simde_vqaddq_s8(a, b);

    simde_test_arm_neon_assert_equal_i8x16(r, simde_vld1q_s8(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int8x16_t a = simde_test_arm_neon_random_i8x16();
    simde_int8x16_t b = simde_test_arm_neon_random_i8x16();
    simde_int8x16_t r = simde_vqaddq_s8(a, b);

    simde_test_arm_neon_write_i8x16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i8x16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i8x16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vqaddq_s16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int16_t a[8];
    int16_t b[8];
    int16_t r[8];
  } test_vec[] = {
    { { -INT16_C(  9717),  INT16_C( 12151), -INT16_C( 21744), -INT16_C( 18219), -INT16_C( 22282),  INT16_C( 12709),  INT16_C( 21139),  INT16_C( 14023) },
      {  INT16_C(   348), -INT16_C( 31129),  INT16_C( 15964),  INT16_C( 17917),  INT16_C( 21690),  INT16_C(  3256), -INT16_C( 19649),  INT16_C( 19310) },
      { -INT16_C(  9369), -INT16_C( 18978), -INT16_C(  5780), -INT16_C(   302), -INT16_C(   592),  INT16_C( 15965),  INT16_C(  1490),       INT16_MAX } },
    { { -INT16_C(  6771), -INT16_C( 25222),  INT16_C( 20369), -INT16_C( 30890), -INT16_C(  1033), -INT16_C( 29768), -INT16_C( 32691), -INT16_C( 22079) },
      {  INT16_C( 10369), -INT16_C(  8657),  INT16_C( 11623),  INT16_C(  8483), -INT16_C(  9343), -INT16_C( 16339), -INT16_C( 25713),  INT16_C(  7179) },
      {  INT16_C(  3598),       INT16_MIN,  INT16_C( 31992), -INT16_C( 22407), -INT16_C( 10376),       INT16_MIN,       INT16_MIN, -INT16_C( 14900) } },
    { { -INT16_C( 31359),  INT16_C(  4794),  INT16_C(  4309), -INT16_C( 13159),  INT16_C( 21003),  INT16_C( 22615),  INT16_C(  6354),  INT16_C( 21250) },
      {  INT16_C( 12609), -INT16_C( 22479),  INT16_C( 21854), -INT16_C(  8247), -INT16_C(  2512), -INT16_C( 16480), -INT16_C( 21614),  INT16_C(  5084) },
      { -INT16_C( 18750), -INT16_C( 17685),  INT16_C( 26163), -INT16_C( 21406),  INT16_C( 18491),  INT16_C(  6135), -INT16_C( 15260),  INT16_C( 26334) } },
    { { -INT16_C( 27087),  INT16_C(  1573), -INT16_C( 16730), -INT16_C( 20014),  INT16_C( 10768), -INT16_C(  7671),  INT16_C(  2882), -INT16_C( 31946) },
      {  INT16_C( 26429), -INT16_C( 25813), -INT16_C(  2884), -INT16_C(  4741),  INT16_C(  7147),  INT16_C( 32172), -INT16_C( 30522), -INT16_C(  2160) },
      { -INT16_C(   658), -INT16_C( 24240), -INT16_C( 19614), -INT16_C( 24755),  INT16_C( 17915),  INT16_C( 24501), -INT16_C( 27640),       INT16_MIN } },
    { { -INT16_C( 19170), -INT16_C( 15107), -INT16_C( 12173), -INT16_C( 31627),  INT16_C( 32762),  INT16_C( 15462), -INT16_C( 25462), -INT16_C( 14400) },
      { -INT16_C(  5372), -INT16_C( 16285), -INT16_C(  8480), -INT16_C( 13395),  INT16_C( 23289), -INT16_C( 16568), -INT16_C( 10014),  INT16_C(   439) },
      { -INT16_C( 24542), -INT16_C( 31392), -INT16_C( 20653),       INT16_MIN,       INT16_MAX, -INT16_C(  1106),       INT16_MIN, -INT16_C( 13961) } },
    { { -INT16_C( 19315),  INT16_C(   197),  INT16_C( 15236),  INT16_C( 32388), -INT16_C(  5190),  INT16_C( 17595),  INT16_C( 31623), -INT16_C( 29940) },
      {  INT16_C( 28518),  INT16_C( 17996), -INT16_C(  1715),  INT16_C( 17937),  INT16_C( 22867),  INT16_C( 13829), -INT16_C( 17359), -INT16_C( 16841) },
      {  INT16_C(  9203),  INT16_C( 18193),  INT16_C( 13521),       INT16_MAX,  INT16_C( 17677),  INT16_C( 31424),  INT16_C( 14264),       INT16_MIN } },
    { { -INT16_C(   911), -INT16_C(  2625),  INT16_C( 17207), -INT16_C(  3724),  INT16_C( 12078), -INT16_C( 18890),  INT16_C( 17066),  INT16_C(  4161) },
      { -INT16_C( 29263), -INT16_C(   425),  INT16_C( 26759), -INT16_C(  9660),  INT16_C( 18882), -INT16_C(  3312),  INT16_C( 18182),  INT16_C( 30642) },
      { -INT16_C( 30174), -INT16_C(  3050),       INT16_MAX, -INT16_C( 13384),  INT16_C( 30960), -INT16_C( 22202),       INT16_MAX,       INT16_MAX } },
    { {  INT16_C( 28996),  INT16_C( 31596), -INT16_C(  8012), -INT16_C(  7315), -INT16_C( 23793), -INT16_C( 18023), -INT16_C(  9499), -INT16_C( 26934) },
      {  INT16_C(  8552), -INT16_C(  4204), -INT16_C( 10103),  INT16_C( 19401), -INT16_C(  9695),  INT16_C( 10047), -INT16_C(  3807),  INT16_C( 26014) },
      {       INT16_MAX,  INT16_C( 27392), -INT16_C( 18115),  INT16_C( 12086),       INT16_MIN, -INT16_C(  7976), -INT16_C( 13306), -INT16_C(   920) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x8_t a = simde_vld1q_s16(test_vec[i].a);
    simde_int16x8_t b = simde_vld1q_s16(test_vec[i].b);
    simde_int16x8_t r = simde_vqaddq_s16(a, b);

    simde_test_arm_neon_assert_equal_i16x8(r, simde_vld1q_s16(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int16x8_t a = simde_test_arm_neon_random_i16x8();
    simde_int16x8_t b = simde_test_arm_neon_random_i16x8();
    simde_int16x8_t r = simde_vqaddq_s16(a, b);

    simde_test_arm_neon_write_i16x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i16x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i16x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vqaddq_s32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int32_t a[4];
    int32_t b[4];
    int32_t r[4];
  } test_vec[] = {
    { {  INT32_C(   405785285), -INT32_C(  2001782660),  INT32_C(   676703092),  INT32_C(   215642211) },
      {  INT32_C(   833772085),  INT32_C(   197532335),  INT32_C(  1777678421),  INT32_C(  2076218293) },
      {  INT32_C(  1239557370), -INT32_C(  1804250325),            INT32_MAX,            INT32_MAX } },
    { { -INT32_C(   627839139), -INT32_C(  1688059097),  INT32_C(  1371781102),  INT32_C(  1566416423) },
      { -INT32_C(  1483861768), -INT32_C(  2135796694),  INT32_C(  1122609292), -INT32_C(  1732400581) },
      { -INT32_C(  2111700907),            INT32_MIN,            INT32_MAX, -INT32_C(   165984158) } },
    { { -INT32_C(  1049472871), -INT32_C(  2107845229), -INT32_C(  1261231988), -INT32_C(  1240387138) },
      {  INT32_C(  1801297729),  INT32_C(  2146111731), -INT32_C(   205400648),  INT32_C(   411795071) },
      {  INT32_C(   751824858),  INT32_C(    38266502), -INT32_C(  1466632636), -INT32_C(   828592067) } },
    { {  INT32_C(  1658453711),  INT32_C(  1608791763),  INT32_C(   336836694),  INT32_C(   717890793) },
      { -INT32_C(  1231738941), -INT32_C(   281640649), -INT32_C(   706545834),  INT32_C(  1173188214) },
      {  INT32_C(   426714770),  INT32_C(  1327151114), -INT32_C(   369709140),  INT32_C(  1891079007) } },
    { {  INT32_C(  1067960172),  INT32_C(  1402899709),  INT32_C(   761770564), -INT32_C(  1705561642) },
      { -INT32_C(  1873744808), -INT32_C(  1015052691), -INT32_C(   191339906),  INT32_C(  1010403024) },
      { -INT32_C(   805784636),  INT32_C(   387847018),  INT32_C(   570430658), -INT32_C(   695158618) } },
    { {  INT32_C(  1249632333), -INT32_C(  1331881620), -INT32_C(  1562573621), -INT32_C(  1925434315) },
      { -INT32_C(  1910666207), -INT32_C(  1856856813), -INT32_C(   813307137), -INT32_C(  1123303824) },
      { -INT32_C(   661033874),            INT32_MIN,            INT32_MIN,            INT32_MIN } },
    { {  INT32_C(   185042590),  INT32_C(  1807459487), -INT32_C(   586311256), -INT32_C(   294958643) },
      { -INT32_C(   394426155),  INT32_C(   611962661),  INT32_C(   720633529),  INT32_C(  1541930684) },
      { -INT32_C(   209383565),            INT32_MAX,  INT32_C(   134322273),  INT32_C(  1246972041) } },
    { {  INT32_C(   610725764),  INT32_C(  1016013203), -INT32_C(  2011587398), -INT32_C(  1166637851) },
      {  INT32_C(   849605389),  INT32_C(  2086083778), -INT32_C(   676967909), -INT32_C(   852325047) },
      {  INT32_C(  1460331153),            INT32_MAX,            INT32_MIN, -INT32_C(  2018962898) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x4_t a = simde_vld1q_s32(test_vec[i].a);
    simde_int32x4_t b = simde_vld1q_s32(test_vec[i].b);
    simde_int32x4_t r = simde_vqaddq_s32(a, b);
    simde_test_arm_neon_assert_equal_i32x4(r, simde_vld1q_s32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int32x4_t a = simde_test_arm_neon_random_i32x4();
    simde_int32x4_t b = simde_test_arm_neon_random_i32x4();
    simde_int32x4_t r = simde_vqaddq_s32(a, b);

    simde_test_arm_neon_write_i32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vqaddq_s64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int64_t a[2];
    int64_t b[2];
    int64_t r[2];
  } test_vec[] = {
    { { -INT64_C(  247047943962692106), -INT64_C( 1789219120264728378) },
      { -INT64_C( 7416386688530799948),  INT64_C( 8227642745494112686) },
      { -INT64_C( 7663434632493492054),  INT64_C( 6438423625229384308) } },
    { { -INT64_C( 2262437474353296534),  INT64_C(   35363921426178789) },
      {  INT64_C( 1042527654696889669),  INT64_C( 6180465821605525207) },
      { -INT64_C( 1219909819656406865),  INT64_C( 6215829743031703996) } },
    { { -INT64_C( 8921192576213292745), -INT64_C( 7944746336789026447) },
      {  INT64_C( 2068249840679090244), -INT64_C( 7809746033345302435) },
      { -INT64_C( 6852942735534202501),                     INT64_MIN } },
    { { -INT64_C( 7944325414965177698), -INT64_C( 5288055603979101505) },
      {  INT64_C( 5829644682889203077),  INT64_C( 3021413471688939262) },
      { -INT64_C( 2114680732075974621), -INT64_C( 2266642132290162243) } },
    { { -INT64_C( 6306404067117182007),  INT64_C( 6640930210847181313) },
      { -INT64_C( 7952497594911521697),  INT64_C( 4330732708174773348) },
      {                     INT64_MIN,                     INT64_MAX } },
    { { -INT64_C( 6467273906831654995), -INT64_C( 6585033115421772950) },
      {  INT64_C( 3885369327502214343),  INT64_C( 6882976536663021526) },
      { -INT64_C( 2581904579329440652),  INT64_C(  297943421241248576) } },
    { { -INT64_C( 5401728779666740547),  INT64_C( 3247821444645069352) },
      {  INT64_C( 8745835046495521112),  INT64_C( 9176444618500375625) },
      {  INT64_C( 3344106266828780565),                     INT64_MAX } },
    { { -INT64_C( 6056519599965188111), -INT64_C( 2981335135517284083) },
      { -INT64_C( 2139104708659239116),  INT64_C( 5343017766601102052) },
      { -INT64_C( 8195624308624427227),  INT64_C( 2361682631083817969) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int64x2_t a = simde_vld1q_s64(test_vec[i].a);
    simde_int64x2_t b = simde_vld1q_s64(test_vec[i].b);
    simde_int64x2_t r = simde_vqaddq_s64(a, b);
    simde_test_arm_neon_assert_equal_i64x2(r, simde_vld1q_s64(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int64x2_t a = simde_test_arm_neon_random_i64x2();
    simde_int64x2_t b = simde_test_arm_neon_random_i64x2();
    simde_int64x2_t r = simde_vqaddq_s64(a, b);

    simde_test_arm_neon_write_i64x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i64x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vqaddq_u8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint8_t a[16];
    uint8_t b[16];
    uint8_t r[16];
  } test_vec[] = {
    { { UINT8_C( 19), UINT8_C(249), UINT8_C( 68), UINT8_C( 15), UINT8_C(214), UINT8_C(186), UINT8_C(154), UINT8_C(108),
        UINT8_C(248), UINT8_C( 33), UINT8_C( 46), UINT8_C(216), UINT8_C( 99), UINT8_C(130), UINT8_C(158), UINT8_C(  3) },
      { UINT8_C( 66), UINT8_C(193), UINT8_C(146), UINT8_C(243), UINT8_C(113), UINT8_C(248), UINT8_C(189), UINT8_C(191),
        UINT8_C(249), UINT8_C(237), UINT8_C(119), UINT8_C(109), UINT8_C( 90), UINT8_C( 39), UINT8_C(171), UINT8_C(109) },
      { UINT8_C( 85),    UINT8_MAX, UINT8_C(214),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,
           UINT8_MAX,    UINT8_MAX, UINT8_C(165),    UINT8_MAX, UINT8_C(189), UINT8_C(169),    UINT8_MAX, UINT8_C(112) } },
    { { UINT8_C( 33), UINT8_C(239), UINT8_C(124), UINT8_C(247), UINT8_C(170), UINT8_C( 22), UINT8_C(100), UINT8_C(162),
        UINT8_C( 55), UINT8_C(146), UINT8_C(122), UINT8_C(154), UINT8_C( 20), UINT8_C( 24), UINT8_C(157), UINT8_C( 87) },
      { UINT8_C(217), UINT8_C( 48), UINT8_C( 74), UINT8_C( 75), UINT8_C( 40), UINT8_C(  7), UINT8_C( 10), UINT8_C( 34),
        UINT8_C(245), UINT8_C(129), UINT8_C(143), UINT8_C( 79), UINT8_C(169), UINT8_C( 58), UINT8_C(188), UINT8_C(202) },
      { UINT8_C(250),    UINT8_MAX, UINT8_C(198),    UINT8_MAX, UINT8_C(210), UINT8_C( 29), UINT8_C(110), UINT8_C(196),
           UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(233), UINT8_C(189), UINT8_C( 82),    UINT8_MAX,    UINT8_MAX } },
    { { UINT8_C( 42), UINT8_C( 56), UINT8_C(193), UINT8_C(212), UINT8_C( 78), UINT8_C( 37), UINT8_C(118), UINT8_C(133),
        UINT8_C(183), UINT8_C(240), UINT8_C( 31), UINT8_C(204), UINT8_C(  9), UINT8_C(188), UINT8_C( 35), UINT8_C(226) },
      { UINT8_C(236), UINT8_C(109), UINT8_C( 45), UINT8_C( 21), UINT8_C(116), UINT8_C( 55), UINT8_C( 55), UINT8_C(105),
        UINT8_C(185), UINT8_C(198), UINT8_C(184), UINT8_C( 98), UINT8_C(  0), UINT8_C(116), UINT8_C( 44), UINT8_C( 42) },
      {    UINT8_MAX, UINT8_C(165), UINT8_C(238), UINT8_C(233), UINT8_C(194), UINT8_C( 92), UINT8_C(173), UINT8_C(238),
           UINT8_MAX,    UINT8_MAX, UINT8_C(215),    UINT8_MAX, UINT8_C(  9),    UINT8_MAX, UINT8_C( 79),    UINT8_MAX } },
    { { UINT8_C(172), UINT8_C(237), UINT8_C(254), UINT8_C(250), UINT8_C( 19), UINT8_C(116), UINT8_C(127), UINT8_C(202),
        UINT8_C(101), UINT8_C(158), UINT8_C(150), UINT8_C(110), UINT8_C( 91), UINT8_C(185), UINT8_C( 80), UINT8_C( 71) },
      { UINT8_C( 38), UINT8_C(126), UINT8_C( 92), UINT8_C(155), UINT8_C(181), UINT8_C(147), UINT8_C(  4), UINT8_C(110),
        UINT8_C( 89), UINT8_C(189), UINT8_C(208), UINT8_C( 90), UINT8_C( 49), UINT8_C(252), UINT8_C(132), UINT8_C(222) },
      { UINT8_C(210),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(200),    UINT8_MAX, UINT8_C(131),    UINT8_MAX,
        UINT8_C(190),    UINT8_MAX,    UINT8_MAX, UINT8_C(200), UINT8_C(140),    UINT8_MAX, UINT8_C(212),    UINT8_MAX } },
    { { UINT8_C(234), UINT8_C(131), UINT8_C(216), UINT8_C(253), UINT8_C(247), UINT8_C( 88), UINT8_C(199), UINT8_C( 92),
        UINT8_C(246), UINT8_C( 94), UINT8_C(202), UINT8_C( 81), UINT8_C( 23), UINT8_C( 27), UINT8_C(153), UINT8_C( 62) },
      { UINT8_C(153), UINT8_C(245), UINT8_C(217), UINT8_C( 78), UINT8_C(137), UINT8_C(221), UINT8_C(189), UINT8_C(226),
        UINT8_C(154), UINT8_C(141), UINT8_C( 60), UINT8_C(204), UINT8_C(138), UINT8_C(193), UINT8_C(170), UINT8_C(116) },
      {    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,    UINT8_MAX,
           UINT8_MAX, UINT8_C(235),    UINT8_MAX,    UINT8_MAX, UINT8_C(161), UINT8_C(220),    UINT8_MAX, UINT8_C(178) } },
    { { UINT8_C( 68), UINT8_C(130), UINT8_C(113), UINT8_C( 59), UINT8_C(218), UINT8_C( 56), UINT8_C(152), UINT8_C(209),
        UINT8_C(150), UINT8_C( 98), UINT8_C( 34), UINT8_C(174), UINT8_C(125), UINT8_C(187), UINT8_C(236), UINT8_C( 22) },
      { UINT8_C(177), UINT8_C(197), UINT8_C(101), UINT8_C( 58), UINT8_C(162), UINT8_C( 34), UINT8_C( 28), UINT8_C( 61),
        UINT8_C(175), UINT8_C( 89), UINT8_C(  9), UINT8_C( 57), UINT8_C( 26), UINT8_C(179), UINT8_C(173), UINT8_C( 94) },
      { UINT8_C(245),    UINT8_MAX, UINT8_C(214), UINT8_C(117),    UINT8_MAX, UINT8_C( 90), UINT8_C(180),    UINT8_MAX,
           UINT8_MAX, UINT8_C(187), UINT8_C( 43), UINT8_C(231), UINT8_C(151),    UINT8_MAX,    UINT8_MAX, UINT8_C(116) } },
    { { UINT8_C( 53), UINT8_C( 30), UINT8_C(153), UINT8_C( 16), UINT8_C( 87), UINT8_C( 49), UINT8_C(225), UINT8_C(237),
        UINT8_C(148), UINT8_C(  3), UINT8_C(155), UINT8_C( 17), UINT8_C(191), UINT8_C(135), UINT8_C( 40), UINT8_C(112) },
      { UINT8_C( 76), UINT8_C(141), UINT8_C(170), UINT8_C(239), UINT8_C(175), UINT8_C(198), UINT8_C( 44), UINT8_C( 94),
        UINT8_C( 31), UINT8_C( 53), UINT8_C(152), UINT8_C( 57), UINT8_C(232), UINT8_C( 69), UINT8_C(151), UINT8_C( 29) },
      { UINT8_C(129), UINT8_C(171),    UINT8_MAX,    UINT8_MAX,    UINT8_MAX, UINT8_C(247),    UINT8_MAX,    UINT8_MAX,
        UINT8_C(179), UINT8_C( 56),    UINT8_MAX, UINT8_C( 74),    UINT8_MAX, UINT8_C(204), UINT8_C(191), UINT8_C(141) } },
    { { UINT8_C(100), UINT8_C( 49), UINT8_C( 45), UINT8_C(187), UINT8_C( 98), UINT8_C( 14), UINT8_C(168), UINT8_C(246),
        UINT8_C( 18), UINT8_C( 68), UINT8_C(  8), UINT8_C(209), UINT8_C(203), UINT8_C( 48), UINT8_C( 65), UINT8_C( 24) },
      { UINT8_C(189), UINT8_C(235), UINT8_C(  7), UINT8_C(108), UINT8_C(177), UINT8_C( 51), UINT8_C(202), UINT8_C(209),
        UINT8_C(104), UINT8_C( 98), UINT8_C( 10), UINT8_C( 80), UINT8_C(168), UINT8_C(162), UINT8_C(109), UINT8_C( 12) },
      {    UINT8_MAX,    UINT8_MAX, UINT8_C( 52),    UINT8_MAX,    UINT8_MAX, UINT8_C( 65),    UINT8_MAX,    UINT8_MAX,
        UINT8_C(122), UINT8_C(166), UINT8_C( 18),    UINT8_MAX,    UINT8_MAX, UINT8_C(210), UINT8_C(174), UINT8_C( 36) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint8x16_t a = simde_vld1q_u8(test_vec[i].a);
    simde_uint8x16_t b = simde_vld1q_u8(test_vec[i].b);
    simde_uint8x16_t r = simde_vqaddq_u8(a, b);

    simde_test_arm_neon_assert_equal_u8x16(r, simde_vld1q_u8(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint8x16_t a = simde_test_arm_neon_random_u8x16();
    simde_uint8x16_t b = simde_test_arm_neon_random_u8x16();
    simde_uint8x16_t r = simde_vqaddq_u8(a, b);

    simde_test_arm_neon_write_u8x16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u8x16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u8x16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vqaddq_u16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint16_t a[8];
    uint16_t b[8];
    uint16_t r[8];
  } test_vec[] = {
    { { UINT16_C(44137), UINT16_C(29135), UINT16_C( 5385), UINT16_C(65255), UINT16_C( 4257), UINT16_C(32373), UINT16_C(42489), UINT16_C( 1882) },
      { UINT16_C(11291), UINT16_C( 2242), UINT16_C(33329), UINT16_C(22790), UINT16_C(17167), UINT16_C(45739), UINT16_C(24707), UINT16_C(60522) },
      { UINT16_C(55428), UINT16_C(31377), UINT16_C(38714),      UINT16_MAX, UINT16_C(21424),      UINT16_MAX,      UINT16_MAX, UINT16_C(62404) } },
    { { UINT16_C(14605), UINT16_C( 5725), UINT16_C(17742), UINT16_C(61204), UINT16_C(35413), UINT16_C(20078), UINT16_C(51247), UINT16_C(19030) },
      { UINT16_C( 6388), UINT16_C( 9554), UINT16_C(22682), UINT16_C(43390), UINT16_C(10652), UINT16_C( 8027), UINT16_C(50570), UINT16_C(38667) },
      { UINT16_C(20993), UINT16_C(15279), UINT16_C(40424),      UINT16_MAX, UINT16_C(46065), UINT16_C(28105),      UINT16_MAX, UINT16_C(57697) } },
    { { UINT16_C(26878), UINT16_C(19885), UINT16_C(49837), UINT16_C(  828), UINT16_C(43596), UINT16_C(31569), UINT16_C(42866), UINT16_C(26309) },
      { UINT16_C( 6335), UINT16_C(22923), UINT16_C( 2672), UINT16_C( 3074), UINT16_C(24115), UINT16_C(48427), UINT16_C(13859), UINT16_C( 8788) },
      { UINT16_C(33213), UINT16_C(42808), UINT16_C(52509), UINT16_C( 3902),      UINT16_MAX,      UINT16_MAX, UINT16_C(56725), UINT16_C(35097) } },
    { { UINT16_C(  671), UINT16_C(19567), UINT16_C(43972), UINT16_C( 4175), UINT16_C(41302), UINT16_C(51339), UINT16_C(20552), UINT16_C( 2095) },
      { UINT16_C(47720), UINT16_C(55649), UINT16_C(25796), UINT16_C(63717), UINT16_C( 4546), UINT16_C(58805), UINT16_C( 2631), UINT16_C(58887) },
      { UINT16_C(48391),      UINT16_MAX,      UINT16_MAX,      UINT16_MAX, UINT16_C(45848),      UINT16_MAX, UINT16_C(23183), UINT16_C(60982) } },
    { { UINT16_C(30220), UINT16_C(53299), UINT16_C(33314), UINT16_C(30944), UINT16_C(27427), UINT16_C(27712), UINT16_C(28603), UINT16_C( 9332) },
      { UINT16_C(54570), UINT16_C(61181), UINT16_C(57913), UINT16_C(64486), UINT16_C(40179), UINT16_C(15329), UINT16_C(59558), UINT16_C(45601) },
      {      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX, UINT16_C(43041),      UINT16_MAX, UINT16_C(54933) } },
    { { UINT16_C(21599), UINT16_C(33154), UINT16_C(25303), UINT16_C(64249), UINT16_C(14797), UINT16_C(34918), UINT16_C(55977), UINT16_C(54188) },
      { UINT16_C(43440), UINT16_C(59841), UINT16_C(43148), UINT16_C(32741), UINT16_C(50756), UINT16_C(60090), UINT16_C(56494), UINT16_C( 3484) },
      { UINT16_C(65039),      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX,      UINT16_MAX, UINT16_C(57672) } },
    { { UINT16_C( 7728), UINT16_C( 1934), UINT16_C(34688), UINT16_C(19714), UINT16_C(26817), UINT16_C(27349), UINT16_C(33347), UINT16_C(62269) },
      { UINT16_C(65067), UINT16_C(47068), UINT16_C(49574), UINT16_C(59959), UINT16_C(61831), UINT16_C(14036), UINT16_C(28877), UINT16_C(65091) },
      {      UINT16_MAX, UINT16_C(49002),      UINT16_MAX,      UINT16_MAX,      UINT16_MAX, UINT16_C(41385), UINT16_C(62224),      UINT16_MAX } },
    { { UINT16_C(53902), UINT16_C( 3589), UINT16_C( 1881), UINT16_C( 6747), UINT16_C(12656), UINT16_C(45956), UINT16_C(49587), UINT16_C(56998) },
      { UINT16_C(33472), UINT16_C(26262), UINT16_C(52548), UINT16_C(52049), UINT16_C( 9662), UINT16_C(35841), UINT16_C(17814), UINT16_C( 9354) },
      {      UINT16_MAX, UINT16_C(29851), UINT16_C(54429), UINT16_C(58796), UINT16_C(22318),      UINT16_MAX,      UINT16_MAX,      UINT16_MAX } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint16x8_t a = simde_vld1q_u16(test_vec[i].a);
    simde_uint16x8_t b = simde_vld1q_u16(test_vec[i].b);
    simde_uint16x8_t r = simde_vqaddq_u16(a, b);
    simde_test_arm_neon_assert_equal_u16x8(r, simde_vld1q_u16(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint16x8_t a = simde_test_arm_neon_random_u16x8();
    simde_uint16x8_t b = simde_test_arm_neon_random_u16x8();
    simde_uint16x8_t r = simde_vqaddq_u16(a, b);

    simde_test_arm_neon_write_u16x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u16x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u16x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vqaddq_u32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint32_t a[4];
    uint32_t b[4];
    uint32_t r[4];
  } test_vec[] = {
    { { UINT32_C(3666842669), UINT32_C(2390080161), UINT32_C( 817569982), UINT32_C(4145787418) },
      { UINT32_C( 135928911), UINT32_C(3146748057), UINT32_C(2147957260), UINT32_C( 895976456) },
      { UINT32_C(3802771580),           UINT32_MAX, UINT32_C(2965527242),           UINT32_MAX } },
    { { UINT32_C(3104831000), UINT32_C(1866958256), UINT32_C(3231646629), UINT32_C(  79149749) },
      { UINT32_C(1879953879), UINT32_C(1831574625), UINT32_C(3740086998), UINT32_C(3457373366) },
      {           UINT32_MAX, UINT32_C(3698532881),           UINT32_MAX, UINT32_C(3536523115) } },
    { { UINT32_C(4220002891), UINT32_C(1298845607), UINT32_C(2282556114), UINT32_C(2609693892) },
      { UINT32_C(4127955349), UINT32_C( 191051317), UINT32_C( 518606952), UINT32_C(4025351332) },
      {           UINT32_MAX, UINT32_C(1489896924), UINT32_C(2801163066),           UINT32_MAX } },
    { { UINT32_C(3337319711), UINT32_C( 387142980), UINT32_C( 614408287), UINT32_C(2042571748) },
      { UINT32_C(4201630661), UINT32_C(1778831873), UINT32_C(3347640098), UINT32_C( 196507116) },
      {           UINT32_MAX, UINT32_C(2165974853), UINT32_C(3962048385), UINT32_C(2239078864) } },
    { { UINT32_C( 802267626), UINT32_C(1447486967), UINT32_C(3933922565), UINT32_C(3580049936) },
      { UINT32_C( 114348805), UINT32_C(3362838181), UINT32_C(2979002821), UINT32_C(1505510766) },
      { UINT32_C( 916616431),           UINT32_MAX,           UINT32_MAX,           UINT32_MAX } },
    { { UINT32_C(3733491431), UINT32_C(2016726643), UINT32_C(3278024627), UINT32_C(4003055337) },
      { UINT32_C(1056205209), UINT32_C(  67527999), UINT32_C(3434517854), UINT32_C(3257234139) },
      {           UINT32_MAX, UINT32_C(2084254642),           UINT32_MAX,           UINT32_MAX } },
    { { UINT32_C(1939909888), UINT32_C( 787272827), UINT32_C(1827819139), UINT32_C(2908392212) },
      { UINT32_C( 871124980), UINT32_C( 305656500), UINT32_C(1675554184), UINT32_C(1613038688) },
      { UINT32_C(2811034868), UINT32_C(1092929327), UINT32_C(3503373323),           UINT32_MAX } },
    { { UINT32_C( 768918961), UINT32_C( 492552345), UINT32_C( 596200718), UINT32_C(3436242136) },
      { UINT32_C(3892296755), UINT32_C( 939079599), UINT32_C(2224740132), UINT32_C(2380644315) },
      {           UINT32_MAX, UINT32_C(1431631944), UINT32_C(2820940850),           UINT32_MAX } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint32x4_t a = simde_vld1q_u32(test_vec[i].a);
    simde_uint32x4_t b = simde_vld1q_u32(test_vec[i].b);
    simde_uint32x4_t r = simde_vqaddq_u32(a, b);

    simde_test_arm_neon_assert_equal_u32x4(r, simde_vld1q_u32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint32x4_t a = simde_test_arm_neon_random_u32x4();
    simde_uint32x4_t b = simde_test_arm_neon_random_u32x4();
    simde_uint32x4_t r = simde_vqaddq_u32(a, b);

    simde_test_arm_neon_write_u32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vqaddq_u64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint64_t a[2];
    uint64_t b[2];
    uint64_t r[2];
  } test_vec[] = {
    { { UINT64_C(17243729724880665306), UINT64_C(  479918823202608748) },
      { UINT64_C( 9159647833849261395), UINT64_C(12959692697279553431) },
      {                    UINT64_MAX, UINT64_C(13439611520482162179) } },
    { { UINT64_C(12254249772932216397), UINT64_C( 7517869064982434477) },
      { UINT64_C(14442852904420611779), UINT64_C( 7078785694487478705) },
      {                    UINT64_MAX, UINT64_C(14596654759469913182) } },
    { { UINT64_C( 5405605557765850652), UINT64_C(14637240881365201315) },
      { UINT64_C( 6448356046027773571), UINT64_C( 9989581481856698411) },
      { UINT64_C(11853961603793624223),                    UINT64_MAX } },
    { { UINT64_C( 6543424278721996261), UINT64_C(15559149823588525850) },
      { UINT64_C(18198211363880019851), UINT64_C( 8469826759267479697) },
      {                    UINT64_MAX,                    UINT64_MAX } },
    { { UINT64_C( 8220413299959295491), UINT64_C(16598158656689940269) },
      { UINT64_C( 9076345260268512040), UINT64_C( 1376700779674218775) },
      { UINT64_C(17296758560227807531), UINT64_C(17974859436364159044) } },
    { { UINT64_C(  450045338343773045), UINT64_C( 8956216358241554952) },
      { UINT64_C( 2462460794197337283), UINT64_C( 2648368024063158428) },
      { UINT64_C( 2912506132541110328), UINT64_C(11604584382304713380) } },
    { { UINT64_C( 8635704442793004536), UINT64_C(  202985511673618177) },
      { UINT64_C( 5672527485480289930), UINT64_C( 6798388585654026629) },
      { UINT64_C(14308231928273294466), UINT64_C( 7001374097327644806) } },
    { { UINT64_C( 8731924942568769864), UINT64_C(13450175318447753831) },
      { UINT64_C(13539237984830773734), UINT64_C(16307051131059626122) },
      {                    UINT64_MAX,                    UINT64_MAX } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint64x2_t a = simde_vld1q_u64(test_vec[i].a);
    simde_uint64x2_t b = simde_vld1q_u64(test_vec[i].b);
    simde_uint64x2_t r = simde_vqaddq_u64(a, b);
    simde_test_arm_neon_assert_equal_u64x2(r, simde_vld1q_u64(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint64x2_t a = simde_test_arm_neon_random_u64x2();
    simde_uint64x2_t b = simde_test_arm_neon_random_u64x2();
    simde_uint64x2_t r = simde_vqaddq_u64(a, b);

    simde_test_arm_neon_write_u64x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u64x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(vqaddb_s8)
SIMDE_TEST_FUNC_LIST_ENTRY(vqaddh_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vqadds_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vqaddd_s64)
SIMDE_TEST_FUNC_LIST_ENTRY(vqaddb_u8)
SIMDE_TEST_FUNC_LIST_ENTRY(vqaddh_u16)
SIMDE_TEST_FUNC_LIST_ENTRY(vqadds_u32)
SIMDE_TEST_FUNC_LIST_ENTRY(vqaddd_u64)

SIMDE_TEST_FUNC_LIST_ENTRY(vqadd_s8)
SIMDE_TEST_FUNC_LIST_ENTRY(vqadd_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vqadd_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vqadd_s64)
SIMDE_TEST_FUNC_LIST_ENTRY(vqadd_u8)
SIMDE_TEST_FUNC_LIST_ENTRY(vqadd_u16)
SIMDE_TEST_FUNC_LIST_ENTRY(vqadd_u32)
SIMDE_TEST_FUNC_LIST_ENTRY(vqadd_u64)

SIMDE_TEST_FUNC_LIST_ENTRY(vqaddq_s8)
SIMDE_TEST_FUNC_LIST_ENTRY(vqaddq_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vqaddq_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vqaddq_s64)
SIMDE_TEST_FUNC_LIST_ENTRY(vqaddq_u8)
SIMDE_TEST_FUNC_LIST_ENTRY(vqaddq_u16)
SIMDE_TEST_FUNC_LIST_ENTRY(vqaddq_u32)
SIMDE_TEST_FUNC_LIST_ENTRY(vqaddq_u64)
SIMDE_TEST_FUNC_LIST_END

#include "test-neon-footer.h"
