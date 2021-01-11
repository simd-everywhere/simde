#define SIMDE_TEST_ARM_NEON_INSN uqadd

#include "test-neon.h"
#include "../../../simde/arm/neon/uqadd.h"

static int
test_simde_vuqaddb_s8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int8_t a;
    uint8_t b;
    int8_t r;
  } test_vec[] = {
    {  INT8_C(  63),
      UINT8_C(186),
           INT8_MAX },
    {  INT8_C(  46),
      UINT8_C(228),
           INT8_MAX },
    {  INT8_C(   4),
      UINT8_C( 92),
       INT8_C(  96) },
    {  INT8_C(  80),
      UINT8_C(144),
           INT8_MAX },
    { -INT8_C(  91),
      UINT8_C(184),
       INT8_C(  93) },
    { -INT8_C(  82),
      UINT8_C(209),
           INT8_MAX },
    {  INT8_C(  71),
      UINT8_C(212),
           INT8_MAX },
    {  INT8_C( 126),
      UINT8_C(232),
           INT8_MAX }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    int8_t r = simde_vuqaddb_s8(test_vec[i].a, test_vec[i].b);

    simde_assert_equal_i8(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    int8_t a = simde_test_codegen_random_i8();
    uint8_t b = simde_test_codegen_random_u8();
    int8_t r = simde_vuqaddb_s8(a, b);

    simde_test_codegen_write_i8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_u8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vuqaddh_s16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int16_t a;
    uint16_t b;
    int16_t r;
  } test_vec[] = {
    { -INT16_C( 29377),
      UINT16_C( 4536),
      -INT16_C( 24841) },
    { -INT16_C( 10071),
      UINT16_C( 5627),
      -INT16_C(  4444) },
    {  INT16_C(  1195),
      UINT16_C(  268),
       INT16_C(  1463) },
    { -INT16_C( 21310),
      UINT16_C( 8582),
      -INT16_C( 12728) },
    {  INT16_C( 21719),
      UINT16_C(40392),
            INT16_MAX },
    { -INT16_C( 13629),
      UINT16_C(23905),
       INT16_C( 10276) },
    { -INT16_C( 17304),
      UINT16_C(51167),
            INT16_MAX },
    { -INT16_C( 16371),
      UINT16_C(19572),
       INT16_C(  3201) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    int16_t r = simde_vuqaddh_s16(test_vec[i].a, test_vec[i].b);

    simde_assert_equal_i16(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    int16_t a = simde_test_codegen_random_i16();
    uint16_t b = simde_test_codegen_random_u16();
    int16_t r = simde_vuqaddh_s16(a, b);

    simde_test_codegen_write_i16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_u16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vuqadds_s32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int32_t a;
    uint32_t b;
    int32_t r;
  } test_vec[] = {
    { -INT32_C(   161600179),
      UINT32_C(2970310917),
                 INT32_MAX },
    {  INT32_C(   548542301),
      UINT32_C(2604742851),
                 INT32_MAX },
    {  INT32_C(  1329072524),
      UINT32_C(1001167315),
                 INT32_MAX },
    {  INT32_C(  1644399445),
      UINT32_C(2578413388),
                 INT32_MAX },
    { -INT32_C(  1433399900),
      UINT32_C(3277560678),
       INT32_C(  1844160778) },
    {  INT32_C(  1994591667),
      UINT32_C(3507561541),
                 INT32_MAX },
    {  INT32_C(    18893101),
      UINT32_C( 943508707),
       INT32_C(   962401808) },
    { -INT32_C(  1533329576),
      UINT32_C(1530743479),
      -INT32_C(     2586097) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    int32_t r = simde_vuqadds_s32(test_vec[i].a, test_vec[i].b);

    simde_assert_equal_i32(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    int32_t a = simde_test_codegen_random_i32();
    uint32_t b = simde_test_codegen_random_u32();
    int32_t r = simde_vuqadds_s32(a, b);

    simde_test_codegen_write_i32(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_u32(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vuqaddd_s64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int64_t a;
    uint64_t b;
    int64_t r;
  } test_vec[] = {
    {  INT64_C(                   0),
      HEDLEY_STATIC_CAST(uint64_t, INT64_MAX) - 1,
                          INT64_MAX - 1 },
    {  INT64_C(                   0),
      HEDLEY_STATIC_CAST(uint64_t, INT64_MAX),
                          INT64_MAX },
    {  INT64_C(                   0),
      HEDLEY_STATIC_CAST(uint64_t, INT64_MAX) + 1,
                          INT64_MAX },
    {  INT64_C( 2053747437340052823),
      UINT64_C(13151536243870426221),
                          INT64_MAX },
    {  INT64_C( 2053747437340052823),
      UINT64_C(13151536243870426221),
                          INT64_MAX },
    { -INT64_C( 4032424325469985811),
      UINT64_C( 4991582605610361907),
       INT64_C(  959158280140376096) },
    {  INT64_C( 1872515219788548983),
      UINT64_C( 2316344661394558694),
       INT64_C( 4188859881183107677) },
    {  INT64_C(  156211806211202290),
      UINT64_C(13245141756903462557),
                          INT64_MAX },
    {  INT64_C( 4269855915686482557),
      UINT64_C( 5653371427721186593),
                          INT64_MAX },
    { -INT64_C(  324862399252175701),
      UINT64_C( 1831091054024551026),
       INT64_C( 1506228654772375325) },
    { -INT64_C( 5423878131695943638),
      UINT64_C(16157363179885192592),
                          INT64_MAX },
    {  INT64_C( 4123846759084190689),
      UINT64_C( 4897475589879611714),
       INT64_C( 9021322348963802403) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    int64_t r = simde_vuqaddd_s64(test_vec[i].a, test_vec[i].b);

    simde_assert_equal_i64(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    int64_t a = simde_test_codegen_random_i64();
    uint64_t b = simde_test_codegen_random_u64();
    int64_t r = simde_vuqaddd_s64(a, b);

    simde_test_codegen_write_i64(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_u64(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i64(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vuqadd_s8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int8_t a[8];
    uint8_t b[8];
    int8_t r[8];
  } test_vec[] = {
    { {  INT8_C(  84),  INT8_C(  57), -INT8_C(  62), -INT8_C(  25), -INT8_C(  68),  INT8_C( 124), -INT8_C( 101),  INT8_C(  76) },
      { UINT8_C(225), UINT8_C(164), UINT8_C( 56), UINT8_C( 22), UINT8_C( 32), UINT8_C(114), UINT8_C(246), UINT8_C(  1) },
      {      INT8_MAX,      INT8_MAX, -INT8_C(   6), -INT8_C(   3), -INT8_C(  36),      INT8_MAX,      INT8_MAX,  INT8_C(  77) } },
    { {  INT8_C(  94),  INT8_C(  81),  INT8_C(  64),  INT8_C(  37),  INT8_C(  41),  INT8_C( 123),  INT8_C(  94),  INT8_C( 108) },
      { UINT8_C( 60), UINT8_C( 73), UINT8_C( 74), UINT8_C( 85), UINT8_C(157), UINT8_C( 66), UINT8_C(152), UINT8_C(241) },
      {      INT8_MAX,      INT8_MAX,      INT8_MAX,  INT8_C( 122),      INT8_MAX,      INT8_MAX,      INT8_MAX,      INT8_MAX } },
    { {  INT8_C( 123),  INT8_C(  90), -INT8_C(  40),  INT8_C(  55), -INT8_C(  41),  INT8_C( 115), -INT8_C( 125), -INT8_C(  72) },
      { UINT8_C( 23), UINT8_C(187), UINT8_C(206), UINT8_C( 56), UINT8_C( 45), UINT8_C(196), UINT8_C( 57), UINT8_C(139) },
      {      INT8_MAX,      INT8_MAX,      INT8_MAX,  INT8_C( 111),  INT8_C(   4),      INT8_MAX, -INT8_C(  68),  INT8_C(  67) } },
    { {  INT8_C(  21),  INT8_C( 122), -INT8_C(  80),  INT8_C(  63), -INT8_C(  11),  INT8_C(  14), -INT8_C(  85),  INT8_C(  49) },
      { UINT8_C( 87), UINT8_C(245), UINT8_C(135), UINT8_C(244), UINT8_C( 55), UINT8_C( 31), UINT8_C(229), UINT8_C(178) },
      {  INT8_C( 108),      INT8_MAX,  INT8_C(  55),      INT8_MAX,  INT8_C(  44),  INT8_C(  45),      INT8_MAX,      INT8_MAX } },
    { {  INT8_C( 122), -INT8_C(  67), -INT8_C(  23),  INT8_C(  81),  INT8_C(  49),  INT8_C( 108),  INT8_C(   9),  INT8_C(  72) },
      { UINT8_C( 39), UINT8_C(216), UINT8_C(128), UINT8_C( 85), UINT8_C(156), UINT8_C(186), UINT8_C(224), UINT8_C(178) },
      {      INT8_MAX,      INT8_MAX,  INT8_C( 105),      INT8_MAX,      INT8_MAX,      INT8_MAX,      INT8_MAX,      INT8_MAX } },
    { {  INT8_C(  52), -INT8_C( 111), -INT8_C(  15),  INT8_C(  41), -INT8_C(  97), -INT8_C( 100),  INT8_C(  90), -INT8_C(   9) },
      { UINT8_C(145), UINT8_C(225), UINT8_C(235), UINT8_C(201), UINT8_C(  1), UINT8_C(209), UINT8_C(123), UINT8_C(123) },
      {      INT8_MAX,  INT8_C( 114),      INT8_MAX,      INT8_MAX, -INT8_C(  96),  INT8_C( 109),      INT8_MAX,  INT8_C( 114) } },
    { { -INT8_C( 114),  INT8_C( 101), -INT8_C(  52), -INT8_C(  65), -INT8_C(  47), -INT8_C(  43),  INT8_C(   8), -INT8_C(   7) },
      { UINT8_C(173), UINT8_C(136), UINT8_C( 78), UINT8_C( 74), UINT8_C( 66), UINT8_C( 46), UINT8_C(252), UINT8_C(118) },
      {  INT8_C(  59),      INT8_MAX,  INT8_C(  26),  INT8_C(   9),  INT8_C(  19),  INT8_C(   3),      INT8_MAX,  INT8_C( 111) } },
    { { -INT8_C(  65), -INT8_C(  19), -INT8_C(  97),  INT8_C(  95), -INT8_C( 119), -INT8_C(   6),  INT8_C(  86),  INT8_C(  26) },
      { UINT8_C(219), UINT8_C( 65), UINT8_C(227), UINT8_C(220), UINT8_C( 18), UINT8_C( 95), UINT8_C( 87), UINT8_C(161) },
      {      INT8_MAX,  INT8_C(  46),      INT8_MAX,      INT8_MAX, -INT8_C( 101),  INT8_C(  89),      INT8_MAX,      INT8_MAX } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int8x8_t a = simde_vld1_s8(test_vec[i].a);
    simde_uint8x8_t b = simde_vld1_u8(test_vec[i].b);
    simde_int8x8_t r = simde_vuqadd_s8(a, b);

    simde_test_arm_neon_assert_equal_i8x8(r, simde_vld1_s8(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int8x8_t a = simde_test_arm_neon_random_i8x8();
    simde_uint8x8_t b = simde_test_arm_neon_random_u8x8();
    simde_int8x8_t r = simde_vuqadd_s8(a, b);

    simde_test_arm_neon_write_i8x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u8x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i8x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vuqadd_s16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int16_t a[4];
    uint16_t b[4];
    int16_t r[4];
  } test_vec[] = {
    { {  INT16_C(  9156), -INT16_C( 27296),  INT16_C( 26873), -INT16_C( 22898) },
      { UINT16_C(56561), UINT16_C(13296), UINT16_C(60427), UINT16_C(51882) },
      {       INT16_MAX, -INT16_C( 14000),       INT16_MAX,  INT16_C( 28984) } },
    { {  INT16_C( 18905),  INT16_C( 25129),  INT16_C( 32579),  INT16_C(  8061) },
      { UINT16_C(24769), UINT16_C(54267), UINT16_C(21439), UINT16_C(33652) },
      {       INT16_MAX,       INT16_MAX,       INT16_MAX,       INT16_MAX } },
    { { -INT16_C( 10890),  INT16_C( 28441), -INT16_C( 22723),  INT16_C( 11798) },
      { UINT16_C( 1668), UINT16_C(36706), UINT16_C( 3315), UINT16_C(52313) },
      { -INT16_C(  9222),       INT16_MAX, -INT16_C( 19408),       INT16_MAX } },
    { { -INT16_C( 31915), -INT16_C( 26321), -INT16_C( 21502), -INT16_C( 15432) },
      { UINT16_C(45836), UINT16_C(52375), UINT16_C( 2822), UINT16_C(32079) },
      {  INT16_C( 13921),  INT16_C( 26054), -INT16_C( 18680),  INT16_C( 16647) } },
    { {  INT16_C( 26848),  INT16_C(  7916),  INT16_C(   528), -INT16_C( 27572) },
      { UINT16_C(44553), UINT16_C(64547), UINT16_C(31930), UINT16_C( 4296) },
      {       INT16_MAX,       INT16_MAX,  INT16_C( 32458), -INT16_C( 23276) } },
    { { -INT16_C(  2049),  INT16_C(   681),  INT16_C( 24995), -INT16_C( 20283) },
      { UINT16_C(23572), UINT16_C( 7036), UINT16_C(52072), UINT16_C(18584) },
      {  INT16_C( 21523),  INT16_C(  7717),       INT16_MAX, -INT16_C(  1699) } },
    { { -INT16_C( 31692),  INT16_C( 17510), -INT16_C( 19577), -INT16_C( 28456) },
      { UINT16_C(64353), UINT16_C( 7308), UINT16_C(21623), UINT16_C(30508) },
      {  INT16_C( 32661),  INT16_C( 24818),  INT16_C(  2046),  INT16_C(  2052) } },
    { { -INT16_C( 10932), -INT16_C(  4231),  INT16_C( 15926),  INT16_C( 19103) },
      { UINT16_C( 7067), UINT16_C(  869), UINT16_C(64999), UINT16_C( 6987) },
      { -INT16_C(  3865), -INT16_C(  3362),       INT16_MAX,  INT16_C( 26090) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x4_t a = simde_vld1_s16(test_vec[i].a);
    simde_uint16x4_t b = simde_vld1_u16(test_vec[i].b);
    simde_int16x4_t r = simde_vuqadd_s16(a, b);

    simde_test_arm_neon_assert_equal_i16x4(r, simde_vld1_s16(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int16x4_t a = simde_test_arm_neon_random_i16x4();
    simde_uint16x4_t b = simde_test_arm_neon_random_u16x4();
    simde_int16x4_t r = simde_vuqadd_s16(a, b);

    simde_test_arm_neon_write_i16x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u16x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i16x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vuqadd_s32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int32_t a[2];
    uint32_t b[2];
    int32_t r[2];
  } test_vec[] = {
    { {  INT32_C(   157266562), -INT32_C(   963037339) },
      { UINT32_C(2850170162), UINT32_C(3307212409) },
      {            INT32_MAX,            INT32_MAX } },
    { {  INT32_C(   431331811),  INT32_C(  1935955160) },
      { UINT32_C(1467402608), UINT32_C(1232257479) },
      {  INT32_C(  1898734419),            INT32_MAX } },
    { { -INT32_C(   665661069),  INT32_C(   983558920) },
      { UINT32_C(2313388304), UINT32_C(1934558352) },
      {  INT32_C(  1647727235),            INT32_MAX } },
    { {  INT32_C(  1972176029), -INT32_C(   924257960) },
      { UINT32_C(2166316730), UINT32_C(2479526176) },
      {            INT32_MAX,  INT32_C(  1555268216) } },
    { {  INT32_C(  1785470050),  INT32_C(   396626695) },
      { UINT32_C( 480348300), UINT32_C( 697364620) },
      {            INT32_MAX,  INT32_C(  1093991315) } },
    { {  INT32_C(  1285496308), -INT32_C(   938113266) },
      { UINT32_C( 105526502), UINT32_C( 681120966) },
      {  INT32_C(  1391022810), -INT32_C(   256992300) } },
    { {  INT32_C(   949159217), -INT32_C(  1655687408) },
      { UINT32_C(1270477247), UINT32_C(3581233633) },
      {            INT32_MAX,  INT32_C(  1925546225) } },
    { {  INT32_C(  1948324966), -INT32_C(  2126694757) },
      { UINT32_C( 830965611), UINT32_C(3428393371) },
      {            INT32_MAX,  INT32_C(  1301698614) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x2_t a = simde_vld1_s32(test_vec[i].a);
    simde_uint32x2_t b = simde_vld1_u32(test_vec[i].b);
    simde_int32x2_t r = simde_vuqadd_s32(a, b);

    simde_test_arm_neon_assert_equal_i32x2(r, simde_vld1_s32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int32x2_t a = simde_test_arm_neon_random_i32x2();
    simde_uint32x2_t b = simde_test_arm_neon_random_u32x2();
    simde_int32x2_t r = simde_vuqadd_s32(a, b);

    simde_test_arm_neon_write_i32x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u32x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i32x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vuqadd_s64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int64_t a[1];
    uint64_t b[1];
    int64_t r[1];
  } test_vec[] = {
    { { -INT64_C( 2029903918006932442) },
      { UINT64_C( 4466626174427041094) },
      {  INT64_C( 2436722256420108652) } },
    { { -INT64_C( 4623526296965472840) },
      { UINT64_C(11880013668570651766) },
      {  INT64_C( 7256487371605178926) } },
    { {  INT64_C( 9096619478935659318) },
      { UINT64_C(14434495371120307260) },
      {                     INT64_MAX } },
    { {  INT64_C( 7553084072065237950) },
      { UINT64_C( 4715083043050209613) },
      {                     INT64_MAX } },
    { {  INT64_C( 3886845044301974074) },
      { UINT64_C(17662724346743461189) },
      {                     INT64_MAX } },
    { {  INT64_C( 8716674384905321117) },
      { UINT64_C(  209051007555170458) },
      {  INT64_C( 8925725392460491575) } },
    { { -INT64_C( 6977371756340870660) },
      { UINT64_C(12332564481777628411) },
      {  INT64_C( 5355192725436757751) } },
    { { -INT64_C( 6777863531057762740) },
      { UINT64_C(16315466017688466337) },
      {                     INT64_MAX } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int64x1_t a = simde_vld1_s64(test_vec[i].a);
    simde_uint64x1_t b = simde_vld1_u64(test_vec[i].b);
    simde_int64x1_t r = simde_vuqadd_s64(a, b);

    simde_test_arm_neon_assert_equal_i64x1(r, simde_vld1_s64(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int64x1_t a = simde_test_arm_neon_random_i64x1();
    simde_uint64x1_t b = simde_test_arm_neon_random_u64x1();
    simde_int64x1_t r = simde_vuqadd_s64(a, b);

    simde_test_arm_neon_write_i64x1(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u64x1(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i64x1(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vuqaddq_s8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int8_t a[16];
    uint8_t b[16];
    int8_t r[16];
  } test_vec[] = {
    { { -INT8_C(  81), -INT8_C(  31), -INT8_C(  40),  INT8_C(   9),  INT8_C(  70),  INT8_C(   3), -INT8_C(  88),  INT8_C(  65),
         INT8_C( 119), -INT8_C( 100),  INT8_C( 115), -INT8_C( 123), -INT8_C(  81), -INT8_C( 103),  INT8_C(  48), -INT8_C(   5) },
      { UINT8_C(199), UINT8_C(106), UINT8_C(115), UINT8_C(206), UINT8_C(155), UINT8_C( 99), UINT8_C(112), UINT8_C( 60),
        UINT8_C(150), UINT8_C(183), UINT8_C(166), UINT8_C(124), UINT8_C(228), UINT8_C( 18), UINT8_C( 95), UINT8_C(147) },
      {  INT8_C( 118),  INT8_C(  75),  INT8_C(  75),      INT8_MAX,      INT8_MAX,  INT8_C( 102),  INT8_C(  24),  INT8_C( 125),
             INT8_MAX,  INT8_C(  83),      INT8_MAX,  INT8_C(   1),      INT8_MAX, -INT8_C(  85),      INT8_MAX,      INT8_MAX } },
    { { -INT8_C(  13),  INT8_C(  55), -INT8_C( 100),  INT8_C(  57),  INT8_C(  58),  INT8_C(  68),  INT8_C( 123), -INT8_C(  79),
        -INT8_C(  31), -INT8_C(  18),  INT8_C(  54), -INT8_C( 112), -INT8_C( 121),  INT8_C( 102), -INT8_C( 117),  INT8_C(  79) },
      { UINT8_C(208), UINT8_C(254), UINT8_C( 29), UINT8_C(107), UINT8_C( 97), UINT8_C(141), UINT8_C(167), UINT8_C(248),
        UINT8_C( 68), UINT8_C( 77), UINT8_C(116), UINT8_C( 41), UINT8_C( 95), UINT8_C(211), UINT8_C(188), UINT8_C( 82) },
      {      INT8_MAX,      INT8_MAX, -INT8_C(  71),      INT8_MAX,      INT8_MAX,      INT8_MAX,      INT8_MAX,      INT8_MAX,
         INT8_C(  37),  INT8_C(  59),      INT8_MAX, -INT8_C(  71), -INT8_C(  26),      INT8_MAX,  INT8_C(  71),      INT8_MAX } },
    { {  INT8_C(  10),  INT8_C(  89), -INT8_C( 116),  INT8_C(  68), -INT8_C(  99),  INT8_C(   7), -INT8_C(  11),  INT8_C( 126),
        -INT8_C(  11),  INT8_C(  43),  INT8_C(  14),  INT8_C( 124), -INT8_C( 111), -INT8_C( 102), -INT8_C(  53),  INT8_C(  97) },
      { UINT8_C(152), UINT8_C(233), UINT8_C(204), UINT8_C(250), UINT8_C(118), UINT8_C(116), UINT8_C(242), UINT8_C(187),
        UINT8_C(193), UINT8_C(102), UINT8_C(228), UINT8_C( 33), UINT8_C( 58), UINT8_C(160), UINT8_C(115), UINT8_C( 68) },
      {      INT8_MAX,      INT8_MAX,  INT8_C(  88),      INT8_MAX,  INT8_C(  19),  INT8_C( 123),      INT8_MAX,      INT8_MAX,
             INT8_MAX,      INT8_MAX,      INT8_MAX,      INT8_MAX, -INT8_C(  53),  INT8_C(  58),  INT8_C(  62),      INT8_MAX } },
    { { -INT8_C(   7), -INT8_C(   1), -INT8_C( 119), -INT8_C( 105),  INT8_C(   6),  INT8_C( 126),  INT8_C(  21), -INT8_C(   5),
        -INT8_C(  86),  INT8_C(  36),  INT8_C( 120),  INT8_C(  59), -INT8_C(  66),  INT8_C(  67), -INT8_C(  99),  INT8_C(  86) },
      { UINT8_C( 44), UINT8_C(105), UINT8_C( 80), UINT8_C(163), UINT8_C(221), UINT8_C( 66), UINT8_C( 94), UINT8_C(159),
        UINT8_C(169), UINT8_C( 66), UINT8_C(192), UINT8_C(227), UINT8_C(226), UINT8_C( 51), UINT8_C( 39), UINT8_C(220) },
      {  INT8_C(  37),  INT8_C( 104), -INT8_C(  39),  INT8_C(  58),      INT8_MAX,      INT8_MAX,  INT8_C( 115),      INT8_MAX,
         INT8_C(  83),  INT8_C( 102),      INT8_MAX,      INT8_MAX,      INT8_MAX,  INT8_C( 118), -INT8_C(  60),      INT8_MAX } },
    { {  INT8_C(  51), -INT8_C(  80),  INT8_C( 115),  INT8_C(  57),  INT8_C(  47), -INT8_C( 120),  INT8_C(  53), -INT8_C(  39),
        -INT8_C(  84), -INT8_C(  83),  INT8_C(  20),  INT8_C( 106), -INT8_C(  16), -INT8_C(  79), -INT8_C(  63),  INT8_C(  29) },
      { UINT8_C( 27), UINT8_C( 17), UINT8_C(192), UINT8_C(248), UINT8_C( 84), UINT8_C( 30), UINT8_C(151), UINT8_C(253),
        UINT8_C( 96), UINT8_C( 87), UINT8_C(224), UINT8_C( 66), UINT8_C(139), UINT8_C(  7), UINT8_C( 30), UINT8_C(190) },
      {  INT8_C(  78), -INT8_C(  63),      INT8_MAX,      INT8_MAX,      INT8_MAX, -INT8_C(  90),      INT8_MAX,      INT8_MAX,
         INT8_C(  12),  INT8_C(   4),      INT8_MAX,      INT8_MAX,  INT8_C( 123), -INT8_C(  72), -INT8_C(  33),      INT8_MAX } },
    { { -INT8_C(  72), -INT8_C( 111), -INT8_C(   9), -INT8_C(  25),  INT8_C(  26),  INT8_C(  44), -INT8_C(  64), -INT8_C(  58),
        -INT8_C(  39), -INT8_C(  44),  INT8_C(  49), -INT8_C(  54), -INT8_C( 122), -INT8_C(  14), -INT8_C(  25), -INT8_C(  95) },
      { UINT8_C(  3), UINT8_C(167), UINT8_C(153), UINT8_C( 87), UINT8_C(197), UINT8_C( 49), UINT8_C( 84), UINT8_C( 37),
        UINT8_C(136), UINT8_C( 52), UINT8_C(103), UINT8_C( 19), UINT8_C( 60), UINT8_C(134), UINT8_C(209), UINT8_C(244) },
      { -INT8_C(  69),  INT8_C(  56),      INT8_MAX,  INT8_C(  62),      INT8_MAX,  INT8_C(  93),  INT8_C(  20), -INT8_C(  21),
         INT8_C(  97),  INT8_C(   8),      INT8_MAX, -INT8_C(  35), -INT8_C(  62),  INT8_C( 120),      INT8_MAX,      INT8_MAX } },
    { {  INT8_C(  23), -INT8_C(  55), -INT8_C(  37),  INT8_C(  49), -INT8_C(  11), -INT8_C( 101), -INT8_C(   8), -INT8_C(  49),
         INT8_C( 111),  INT8_C(  41), -INT8_C( 103), -INT8_C(  11),  INT8_C(  27),      INT8_MIN, -INT8_C( 106),  INT8_C(  30) },
      { UINT8_C( 39), UINT8_C( 48), UINT8_C(118), UINT8_C(236), UINT8_C( 97), UINT8_C(202), UINT8_C( 17), UINT8_C(233),
           UINT8_MAX, UINT8_C(120), UINT8_C(253), UINT8_C( 59), UINT8_C(254), UINT8_C(206), UINT8_C( 47), UINT8_C( 22) },
      {  INT8_C(  62), -INT8_C(   7),  INT8_C(  81),      INT8_MAX,  INT8_C(  86),  INT8_C( 101),  INT8_C(   9),      INT8_MAX,
             INT8_MAX,      INT8_MAX,      INT8_MAX,  INT8_C(  48),      INT8_MAX,  INT8_C(  78), -INT8_C(  59),  INT8_C(  52) } },
    { { -INT8_C( 105),  INT8_C(  10),  INT8_C(  71), -INT8_C( 115), -INT8_C(  91),  INT8_C(  63),  INT8_C(  92),  INT8_C(  20),
         INT8_C( 104), -INT8_C(  11),  INT8_C(  10), -INT8_C( 125),  INT8_C( 117), -INT8_C(  96), -INT8_C(  94), -INT8_C( 100) },
      { UINT8_C(208), UINT8_C( 24), UINT8_C(136), UINT8_C( 49), UINT8_C(226), UINT8_C(153), UINT8_C( 27), UINT8_C(225),
        UINT8_C( 17), UINT8_C( 24), UINT8_C( 28), UINT8_C( 16), UINT8_C(230), UINT8_C( 75), UINT8_C( 38), UINT8_C(126) },
      {  INT8_C( 103),  INT8_C(  34),      INT8_MAX, -INT8_C(  66),      INT8_MAX,      INT8_MAX,  INT8_C( 119),      INT8_MAX,
         INT8_C( 121),  INT8_C(  13),  INT8_C(  38), -INT8_C( 109),      INT8_MAX, -INT8_C(  21), -INT8_C(  56),  INT8_C(  26) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int8x16_t a = simde_vld1q_s8(test_vec[i].a);
    simde_uint8x16_t b = simde_vld1q_u8(test_vec[i].b);
    simde_int8x16_t r = simde_vuqaddq_s8(a, b);

    simde_test_arm_neon_assert_equal_i8x16(r, simde_vld1q_s8(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int8x16_t a = simde_test_arm_neon_random_i8x16();
    simde_uint8x16_t b = simde_test_arm_neon_random_u8x16();
    simde_int8x16_t r = simde_vuqaddq_s8(a, b);

    simde_test_arm_neon_write_i8x16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u8x16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i8x16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vuqaddq_s16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int16_t a[8];
    uint16_t b[8];
    int16_t r[8];
  } test_vec[] = {
    { {  INT16_C( 27989), -INT16_C(  1525),  INT16_C( 26541),  INT16_C(  5391),  INT16_C(  6492), -INT16_C( 11879),  INT16_C( 15289), -INT16_C( 30099) },
      { UINT16_C(62803), UINT16_C(13755), UINT16_C(54926), UINT16_C(40727), UINT16_C(13294), UINT16_C(54703), UINT16_C(54655), UINT16_C(54355) },
      {       INT16_MAX,  INT16_C( 12230),       INT16_MAX,       INT16_MAX,  INT16_C( 19786),       INT16_MAX,       INT16_MAX,  INT16_C( 24256) } },
    { {  INT16_C( 24131), -INT16_C(  3889), -INT16_C(  8507),  INT16_C(  8453), -INT16_C( 24841), -INT16_C( 20238),  INT16_C( 24537),  INT16_C( 11322) },
      { UINT16_C(63060), UINT16_C(57954), UINT16_C(31180), UINT16_C(48001), UINT16_C(12716), UINT16_C(11152), UINT16_C(58118), UINT16_C(18688) },
      {       INT16_MAX,       INT16_MAX,  INT16_C( 22673),       INT16_MAX, -INT16_C( 12125), -INT16_C(  9086),       INT16_MAX,  INT16_C( 30010) } },
    { { -INT16_C( 12479),  INT16_C(  1593),  INT16_C( 16301), -INT16_C( 23513),  INT16_C(  6621), -INT16_C( 18604), -INT16_C( 28808), -INT16_C( 13085) },
      { UINT16_C(17797), UINT16_C(20910), UINT16_C(12222), UINT16_C(27404), UINT16_C(40032), UINT16_C(26518), UINT16_C(38527), UINT16_C(49328) },
      {  INT16_C(  5318),  INT16_C( 22503),  INT16_C( 28523),  INT16_C(  3891),       INT16_MAX,  INT16_C(  7914),  INT16_C(  9719),       INT16_MAX } },
    { { -INT16_C(  5531),  INT16_C(  4806), -INT16_C(  4823),  INT16_C(  1718),  INT16_C(  2822),  INT16_C( 32445), -INT16_C( 24166),  INT16_C(  8010) },
      { UINT16_C(63718), UINT16_C(42352), UINT16_C(32040), UINT16_C(34832), UINT16_C(42521), UINT16_C(39407), UINT16_C(41021), UINT16_C(41561) },
      {       INT16_MAX,       INT16_MAX,  INT16_C( 27217),       INT16_MAX,       INT16_MAX,       INT16_MAX,  INT16_C( 16855),       INT16_MAX } },
    { {  INT16_C(  8330), -INT16_C( 19531),  INT16_C( 27405),  INT16_C(  5305),  INT16_C( 30582),  INT16_C(  4242), -INT16_C(  8936), -INT16_C(   465) },
      { UINT16_C(41173), UINT16_C(64931), UINT16_C(45853), UINT16_C(13958), UINT16_C(30042), UINT16_C(38863), UINT16_C(10517), UINT16_C(40761) },
      {       INT16_MAX,       INT16_MAX,       INT16_MAX,  INT16_C( 19263),       INT16_MAX,       INT16_MAX,  INT16_C(  1581),       INT16_MAX } },
    { { -INT16_C(  4535),  INT16_C( 22098),  INT16_C(  3162), -INT16_C( 12182), -INT16_C(   637), -INT16_C( 25631),  INT16_C(  4314), -INT16_C( 20583) },
      { UINT16_C(15792), UINT16_C(52653), UINT16_C(13296), UINT16_C(18948), UINT16_C(54184), UINT16_C(48865), UINT16_C( 7164), UINT16_C(17757) },
      {  INT16_C( 11257),       INT16_MAX,  INT16_C( 16458),  INT16_C(  6766),       INT16_MAX,  INT16_C( 23234),  INT16_C( 11478), -INT16_C(  2826) } },
    { { -INT16_C( 20471),  INT16_C( 25500),  INT16_C(  1724),  INT16_C( 16180),  INT16_C(  5379), -INT16_C(  8742),  INT16_C( 29477), -INT16_C( 10611) },
      { UINT16_C(15024), UINT16_C(41379), UINT16_C(42861), UINT16_C( 5611), UINT16_C(52603), UINT16_C(30675), UINT16_C(12776), UINT16_C(61885) },
      { -INT16_C(  5447),       INT16_MAX,       INT16_MAX,  INT16_C( 21791),       INT16_MAX,  INT16_C( 21933),       INT16_MAX,       INT16_MAX } },
    { {  INT16_C( 23009), -INT16_C( 25259), -INT16_C( 30369),  INT16_C( 25564), -INT16_C( 18786), -INT16_C( 15552), -INT16_C( 13015), -INT16_C(  9575) },
      { UINT16_C(15623), UINT16_C(29819), UINT16_C(26340), UINT16_C(24458), UINT16_C(23859), UINT16_C( 7127), UINT16_C(38030), UINT16_C(28429) },
      {       INT16_MAX,  INT16_C(  4560), -INT16_C(  4029),       INT16_MAX,  INT16_C(  5073), -INT16_C(  8425),  INT16_C( 25015),  INT16_C( 18854) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x8_t a = simde_vld1q_s16(test_vec[i].a);
    simde_uint16x8_t b = simde_vld1q_u16(test_vec[i].b);
    simde_int16x8_t r = simde_vuqaddq_s16(a, b);

    simde_test_arm_neon_assert_equal_i16x8(r, simde_vld1q_s16(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int16x8_t a = simde_test_arm_neon_random_i16x8();
    simde_uint16x8_t b = simde_test_arm_neon_random_u16x8();
    simde_int16x8_t r = simde_vuqaddq_s16(a, b);

    simde_test_arm_neon_write_i16x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u16x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i16x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vuqaddq_s32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int32_t a[4];
    uint32_t b[4];
    int32_t r[4];
  } test_vec[] = {
    { {  INT32_C(  1275880173), -INT32_C(  1984960277), -INT32_C(   934481762), -INT32_C(   979179843) },
      { UINT32_C( 121183523), UINT32_C(3077030787), UINT32_C(2949791265), UINT32_C(3206537170) },
      {  INT32_C(  1397063696),  INT32_C(  1092070510),  INT32_C(  2015309503),            INT32_MAX } },
    { {  INT32_C(   738929473), -INT32_C(  1296712940),  INT32_C(  1752826539),  INT32_C(   187505896) },
      { UINT32_C(3172099897), UINT32_C(1265924394), UINT32_C(2314946231), UINT32_C(1732778534) },
      {            INT32_MAX, -INT32_C(    30788546),            INT32_MAX,  INT32_C(  1920284430) } },
    { {  INT32_C(  1502893125), -INT32_C(  1173599985),  INT32_C(   857900619), -INT32_C(   599895901) },
      { UINT32_C(3784921527), UINT32_C(2183990730), UINT32_C(2047551572), UINT32_C(2279691330) },
      {            INT32_MAX,  INT32_C(  1010390745),            INT32_MAX,  INT32_C(  1679795429) } },
    { { -INT32_C(  1209961048),  INT32_C(   175238591),  INT32_C(   373199731), -INT32_C(  1695318813) },
      { UINT32_C(2558299341), UINT32_C(3994724762), UINT32_C( 325592529), UINT32_C( 563759481) },
      {  INT32_C(  1348338293),            INT32_MAX,  INT32_C(   698792260), -INT32_C(  1131559332) } },
    { {  INT32_C(  2128116671), -INT32_C(   595048088), -INT32_C(  1057831203),  INT32_C(   274457923) },
      { UINT32_C( 212391794), UINT32_C(1375388288), UINT32_C(1633968872), UINT32_C(1787035307) },
      {            INT32_MAX,  INT32_C(   780340200),  INT32_C(   576137669),  INT32_C(  2061493230) } },
    { { -INT32_C(   488088710), -INT32_C(  2101448283),  INT32_C(  2051191095),  INT32_C(   143367574) },
      { UINT32_C(4094964596), UINT32_C(3729067766), UINT32_C( 473934192), UINT32_C( 579257000) },
      {            INT32_MAX,  INT32_C(  1627619483),            INT32_MAX,  INT32_C(   722624574) } },
    { { -INT32_C(  1023119586),  INT32_C(   390448096),  INT32_C(   177375092), -INT32_C(  1726800603) },
      { UINT32_C(1183721296), UINT32_C(2787431222), UINT32_C( 633496701), UINT32_C(1145522470) },
      {  INT32_C(   160601710),            INT32_MAX,  INT32_C(   810871793), -INT32_C(   581278133) } },
    { { -INT32_C(  1744352328), -INT32_C(  2102440946), -INT32_C(   108183084), -INT32_C(  1349345186) },
      { UINT32_C(4260700359), UINT32_C(1906580212), UINT32_C(2761320062), UINT32_C(1743379887) },
      {            INT32_MAX, -INT32_C(   195860734),            INT32_MAX,  INT32_C(   394034701) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x4_t a = simde_vld1q_s32(test_vec[i].a);
    simde_uint32x4_t b = simde_vld1q_u32(test_vec[i].b);
    simde_int32x4_t r = simde_vuqaddq_s32(a, b);
    simde_test_arm_neon_assert_equal_i32x4(r, simde_vld1q_s32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int32x4_t a = simde_test_arm_neon_random_i32x4();
    simde_uint32x4_t b = simde_test_arm_neon_random_u32x4();
    simde_int32x4_t r = simde_vuqaddq_s32(a, b);

    simde_test_arm_neon_write_i32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vuqaddq_s64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int64_t a[2];
    uint64_t b[2];
    int64_t r[2];
  } test_vec[] = {
    { {  INT64_C( 1277244646803632168), -INT64_C( 5837055554043099408) },
      { UINT64_C(10025662640714150845), UINT64_C(13676615772832577718) },
      {                     INT64_MAX,  INT64_C( 7839560218789478310) } },
    { {  INT64_C( 7806900323564702729), -INT64_C( 4933207412548345356) },
      { UINT64_C( 4198918928307336364), UINT64_C(10995657851050882374) },
      {                     INT64_MAX,  INT64_C( 6062450438502537018) } },
    { {  INT64_C( 3395773749102808377),  INT64_C( 4706423876967127959) },
      { UINT64_C(10414081876204174536), UINT64_C(14689621110835324342) },
      {                     INT64_MAX,                     INT64_MAX } },
    { { -INT64_C( 8576084105018492015),  INT64_C( 7012507698472027771) },
      { UINT64_C( 4757546734726237227), UINT64_C(  483683368102752601) },
      { -INT64_C( 3818537370292254788),  INT64_C( 7496191066574780372) } },
    { {  INT64_C( 5879676728020972830),  INT64_C( 5751011118699099860) },
      { UINT64_C(  706444675669916926), UINT64_C(15472304225789432892) },
      {  INT64_C( 6586121403690889756),                     INT64_MAX } },
    { {  INT64_C( 3244418405824302047),  INT64_C( 1704446541564634931) },
      { UINT64_C( 8403556614726053094), UINT64_C( 2040374986822554562) },
      {                     INT64_MAX,  INT64_C( 3744821528387189493) } },
    { { -INT64_C( 1805987758484671127), -INT64_C( 2779029987225859522) },
      { UINT64_C( 4755254193201025106), UINT64_C( 7852882482205238433) },
      {  INT64_C( 2949266434716353979),  INT64_C( 5073852494979378911) } },
    { { -INT64_C( 2100332582411514816),  INT64_C( 5869783500826745000) },
      { UINT64_C(10698540553456051384), UINT64_C( 9109495888139727869) },
      {  INT64_C( 8598207971044536568),                     INT64_MAX } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int64x2_t a = simde_vld1q_s64(test_vec[i].a);
    simde_uint64x2_t b = simde_vld1q_u64(test_vec[i].b);
    simde_int64x2_t r = simde_vuqaddq_s64(a, b);
    simde_test_arm_neon_assert_equal_i64x2(r, simde_vld1q_s64(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int64x2_t a = simde_test_arm_neon_random_i64x2();
    simde_uint64x2_t b = simde_test_arm_neon_random_u64x2();
    simde_int64x2_t r = simde_vuqaddq_s64(a, b);

    simde_test_arm_neon_write_i64x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u64x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(vuqaddb_s8)
SIMDE_TEST_FUNC_LIST_ENTRY(vuqaddh_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vuqadds_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vuqaddd_s64)

SIMDE_TEST_FUNC_LIST_ENTRY(vuqadd_s8)
SIMDE_TEST_FUNC_LIST_ENTRY(vuqadd_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vuqadd_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vuqadd_s64)

SIMDE_TEST_FUNC_LIST_ENTRY(vuqaddq_s8)
SIMDE_TEST_FUNC_LIST_ENTRY(vuqaddq_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vuqaddq_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vuqaddq_s64)
SIMDE_TEST_FUNC_LIST_END

#include "test-neon-footer.h"
