#define SIMDE_TEST_ARM_NEON_INSN create

#include "test-neon.h"

/* Check that both of these work */
#if defined(__cplusplus)
  #include "../../../simde/arm/neon/create.h"
#else
  #include "../../../simde/arm/neon.h"
#endif

#include "../../../simde/arm/neon/rev64.h"

static int
test_simde_vcreate_s8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint64_t a;
    int8_t r[8];
  } test_vec[] = {
    { UINT64_C( 9036562365592986592),
      { -INT8_C(  32),  INT8_C(  99), -INT8_C(  43), -INT8_C(   1), -INT8_C( 105),  INT8_C(  81),  INT8_C( 104),  INT8_C( 125) } },
    { UINT64_C( 6390498601993659455),
      {  INT8_C(  63),  INT8_C( 100),  INT8_C( 118), -INT8_C(  59), -INT8_C(  98), -INT8_C( 100), -INT8_C(  81),  INT8_C(  88) } },
    { UINT64_C(  275998905612244718),
      { -INT8_C(  18),  INT8_C(  22),  INT8_C( 106), -INT8_C(  41), -INT8_C( 118), -INT8_C( 117), -INT8_C(  44),  INT8_C(   3) } },
    { UINT64_C( 7789210356557776686),
      {  INT8_C(  46), -INT8_C( 121),  INT8_C( 107), -INT8_C(  33), -INT8_C( 116), -INT8_C(  43),  INT8_C(  24),  INT8_C( 108) } },
    { UINT64_C( 9101162688723807544),
      {  INT8_C(  56), -INT8_C(  19),  INT8_C( 107), -INT8_C(  48),  INT8_C(  62), -INT8_C(  45),  INT8_C(  77),  INT8_C( 126) } },
    { UINT64_C( 5633706681612616759),
      {  INT8_C(  55), -INT8_C(  60),  INT8_C(  67), -INT8_C(  42),  INT8_C(  96), -INT8_C(  14),  INT8_C(  46),  INT8_C(  78) } },
    { UINT64_C( 6023276586649098505),
      {  INT8_C(   9), -INT8_C( 103),  INT8_C(  37), -INT8_C( 109),  INT8_C(  36), -INT8_C(   6), -INT8_C( 106),  INT8_C(  83) } },
    { UINT64_C( 1115004665955746177),
      { -INT8_C( 127),  INT8_C(   1),  INT8_C(  50),  INT8_C(  13), -INT8_C(  42),  INT8_C(  74),  INT8_C( 121),  INT8_C(  15) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int8x8_t r = simde_vcreate_s8(test_vec[i].a);
    #if SIMDE_ENDIAN_ORDER == SIMDE_ENDIAN_BIG
      r = simde_vrev64_s8(r);
    #endif
    simde_test_arm_neon_assert_equal_i8x8(r, simde_vld1_s8(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    uint64_t a;
    simde_test_codegen_random_memory(sizeof(a), HEDLEY_REINTERPRET_CAST(uint8_t*, &a));
    simde_int8x8_t r = simde_vcreate_s8(a);
    #if SIMDE_ENDIAN_ORDER == SIMDE_ENDIAN_BIG
      r = simde_vrev64_s8(r);
    #endif
    simde_test_codegen_write_u64(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i8x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcreate_s16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint64_t a;
    int16_t r[4];
  } test_vec[] = {
    { UINT64_C(13869738154059565533),
      {  INT16_C(  2525), -INT16_C( 18329),  INT16_C( 13661), -INT16_C( 16261) } },
    { UINT64_C(17551629148839487683),
      {  INT16_C( 10435), -INT16_C(  6664), -INT16_C(  5705), -INT16_C(  3181) } },
    { UINT64_C( 8696084256691645363),
      { -INT16_C(  5197), -INT16_C( 16136), -INT16_C( 19826),  INT16_C( 30894) } },
    { UINT64_C( 6363979328255624973),
      {  INT16_C(  1805),  INT16_C( 12955),  INT16_C( 25979),  INT16_C( 22609) } },
    { UINT64_C(12721696900845189230),
      { -INT16_C( 18322), -INT16_C( 13552), -INT16_C( 29715), -INT16_C( 20340) } },
    { UINT64_C( 2332347206957630643),
      { -INT16_C( 31565),  INT16_C( 27541),  INT16_C( 10605),  INT16_C(  8286) } },
    { UINT64_C( 1665081758810461972),
      {  INT16_C( 22292), -INT16_C( 23583), -INT16_C( 28919),  INT16_C(  5915) } },
    { UINT64_C( 9901614696795584150),
      { -INT16_C( 18794),  INT16_C(  4425), -INT16_C( 26085), -INT16_C( 30359) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x4_t r = simde_vcreate_s16(test_vec[i].a);
    #if SIMDE_ENDIAN_ORDER == SIMDE_ENDIAN_BIG
      r = simde_vrev64_s16(r);
    #endif
    simde_test_arm_neon_assert_equal_i16x4(r, simde_vld1_s16(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    uint64_t a;
    simde_test_codegen_random_memory(sizeof(a), HEDLEY_REINTERPRET_CAST(uint8_t*, &a));
    simde_int16x4_t r = simde_vcreate_s16(a);
    #if SIMDE_ENDIAN_ORDER == SIMDE_ENDIAN_BIG
      r = simde_vrev64_s16(r);
    #endif
    simde_test_codegen_write_u64(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i16x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcreate_s32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint64_t a;
    int32_t r[2];
  } test_vec[] = {
    { UINT64_C(14886582890744402759),
      {  INT32_C(  1111118663), -INT32_C(   828914620) } },
    { UINT64_C(14848114052146918100),
      { -INT32_C(   827067692), -INT32_C(   837871345) } },
    { UINT64_C( 6411870351562025644),
      { -INT32_C(    88692052),  INT32_C(  1492879900) } },
    { UINT64_C(17705438690848254358),
      { -INT32_C(  1871205994), -INT32_C(   172598610) } },
    { UINT64_C( 9926443434061131950),
      { -INT32_C(   231149394), -INT32_C(  1983787083) } },
    { UINT64_C( 4224207739063596225),
      { -INT32_C(   799574847),  INT32_C(   983525006) } },
    { UINT64_C( 8540284903960630545),
      {  INT32_C(   758404369),  INT32_C(  1988440031) } },
    { UINT64_C(  395679426392030681),
      { -INT32_C(  2029584935),  INT32_C(    92126295) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x2_t r = simde_vcreate_s32(test_vec[i].a);
    #if SIMDE_ENDIAN_ORDER == SIMDE_ENDIAN_BIG
      r = simde_vrev64_s32(r);
    #endif
    simde_test_arm_neon_assert_equal_i32x2(r, simde_vld1_s32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    uint64_t a;
    simde_test_codegen_random_memory(sizeof(a), HEDLEY_REINTERPRET_CAST(uint8_t*, &a));
    simde_int32x2_t r = simde_vcreate_s32(a);
    #if SIMDE_ENDIAN_ORDER == SIMDE_ENDIAN_BIG
      r = simde_vrev64_s32(r);
    #endif
    simde_test_codegen_write_u64(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i32x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcreate_s64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint64_t a;
    int64_t r[1];
  } test_vec[] = {
    { UINT64_C(  173093934806015498),
      {  INT64_C(  173093934806015498) } },
    { UINT64_C(15550406187577994147),
      { -INT64_C( 2896337886131557469) } },
    { UINT64_C(16933375426449159219),
      { -INT64_C( 1513368647260392397) } },
    { UINT64_C( 1523575716469224309),
      {  INT64_C( 1523575716469224309) } },
    { UINT64_C(11455112343060809714),
      { -INT64_C( 6991631730648741902) } },
    { UINT64_C(17223497509831808806),
      { -INT64_C( 1223246563877742810) } },
    { UINT64_C(13691421468694731484),
      { -INT64_C( 4755322605014820132) } },
    { UINT64_C( 6198811695460552935),
      {  INT64_C( 6198811695460552935) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int64x1_t r = simde_vcreate_s64(test_vec[i].a);
    simde_test_arm_neon_assert_equal_i64x1(r, simde_vld1_s64(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    uint64_t a;
    simde_test_codegen_random_memory(sizeof(a), HEDLEY_REINTERPRET_CAST(uint8_t*, &a));
    simde_int64x1_t r = simde_vcreate_s64(a);
    simde_test_codegen_write_u64(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i64x1(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcreate_u8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint64_t a;
    uint8_t r[8];
  } test_vec[] = {
    { UINT64_C( 6265775979767995226),
      { UINT8_C( 90), UINT8_C( 27), UINT8_C( 63), UINT8_C( 92), UINT8_C( 14), UINT8_C(130), UINT8_C(244), UINT8_C( 86) } },
    { UINT64_C(17068010367454769237),
      { UINT8_C( 85), UINT8_C(112), UINT8_C(211), UINT8_C(190),    UINT8_MAX, UINT8_C(192), UINT8_C(221), UINT8_C(236) } },
    { UINT64_C( 7606247877238926857),
      { UINT8_C(  9), UINT8_C( 46), UINT8_C(101), UINT8_C( 12), UINT8_C( 37), UINT8_C(210), UINT8_C(142), UINT8_C(105) } },
    { UINT64_C(17606029561281669668),
      { UINT8_C( 36), UINT8_C(106), UINT8_C( 56), UINT8_C(241), UINT8_C(154), UINT8_C( 46), UINT8_C( 85), UINT8_C(244) } },
    { UINT64_C( 7831271669100483658),
      { UINT8_C( 74), UINT8_C(148), UINT8_C( 80), UINT8_C( 88), UINT8_C( 23), UINT8_C( 68), UINT8_C(174), UINT8_C(108) } },
    { UINT64_C( 5521422225739842229),
      { UINT8_C(181), UINT8_C(130), UINT8_C( 43), UINT8_C(180), UINT8_C( 66), UINT8_C(  8), UINT8_C(160), UINT8_C( 76) } },
    { UINT64_C(18142161586068391222),
      { UINT8_C( 54), UINT8_C(  5), UINT8_C( 88), UINT8_C( 91), UINT8_C(215), UINT8_C(231), UINT8_C(197), UINT8_C(251) } },
    { UINT64_C( 8493861653629959505),
      { UINT8_C( 81), UINT8_C(253), UINT8_C(236), UINT8_C(235), UINT8_C( 43), UINT8_C( 66), UINT8_C(224), UINT8_C(117) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint8x8_t r = simde_vcreate_u8(test_vec[i].a);
    #if SIMDE_ENDIAN_ORDER == SIMDE_ENDIAN_BIG
      r = simde_vrev64_u8(r);
    #endif
    simde_test_arm_neon_assert_equal_u8x8(r, simde_vld1_u8(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    uint64_t a;
    simde_test_codegen_random_memory(sizeof(a), HEDLEY_REINTERPRET_CAST(uint8_t*, &a));
    simde_uint8x8_t r = simde_vcreate_u8(a);
    #if SIMDE_ENDIAN_ORDER == SIMDE_ENDIAN_BIG
      r = simde_vrev64_u8(r);
    #endif
    simde_test_codegen_write_u64(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u8x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcreate_u16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint64_t a;
    uint16_t r[4];
  } test_vec[] = {
    { UINT64_C( 2175637234227998332),
      { UINT16_C(61052), UINT16_C(39493), UINT16_C(27273), UINT16_C( 7729) } },
    { UINT64_C( 9869096237078089814),
      { UINT16_C( 4182), UINT16_C(10543), UINT16_C( 4797), UINT16_C(35062) } },
    { UINT64_C(12585410908464048241),
      { UINT16_C(26737), UINT16_C(30547), UINT16_C(23690), UINT16_C(44712) } },
    { UINT64_C(  425717200186149581),
      { UINT16_C(35533), UINT16_C(48094), UINT16_C(29577), UINT16_C( 1512) } },
    { UINT64_C(17152188536030441057),
      { UINT16_C(11873), UINT16_C(60063), UINT16_C(53400), UINT16_C(60936) } },
    { UINT64_C(13485762219020335073),
      { UINT16_C(14305), UINT16_C(40471), UINT16_C( 3401), UINT16_C(47911) } },
    { UINT64_C(11866663784635595381),
      { UINT16_C(31349), UINT16_C(   50), UINT16_C(56279), UINT16_C(42158) } },
    { UINT64_C( 6986006611523243109),
      { UINT16_C(35941), UINT16_C(61023), UINT16_C(18431), UINT16_C(24819) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint16x4_t r = simde_vcreate_u16(test_vec[i].a);
    #if SIMDE_ENDIAN_ORDER == SIMDE_ENDIAN_BIG
      r = simde_vrev64_u16(r);
    #endif
    simde_test_arm_neon_assert_equal_u16x4(r, simde_vld1_u16(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    uint64_t a;
    simde_test_codegen_random_memory(sizeof(a), HEDLEY_REINTERPRET_CAST(uint8_t*, &a));
    simde_uint16x4_t r = simde_vcreate_u16(a);
    #if SIMDE_ENDIAN_ORDER == SIMDE_ENDIAN_BIG
      r = simde_vrev64_u16(r);
    #endif
    simde_test_codegen_write_u64(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u16x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcreate_u32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint64_t a;
    uint32_t r[2];
  } test_vec[] = {
    { UINT64_C( 7274848568988698280),
      { UINT32_C(3444868776), UINT32_C(1693807674) } },
    { UINT64_C(11997937038239001643),
      { UINT32_C( 566029355), UINT32_C(2793487403) } },
    { UINT64_C( 8080675061059094450),
      { UINT32_C(2680752050), UINT32_C(1881428775) } },
    { UINT64_C(15028290027952369840),
      { UINT32_C( 967143600), UINT32_C(3499046440) } },
    { UINT64_C( 9465321047858275260),
      { UINT32_C(4137608124), UINT32_C(2203816791) } },
    { UINT64_C(  455186082928269183),
      { UINT32_C(2879657855), UINT32_C( 105981268) } },
    { UINT64_C( 2216838016795023916),
      { UINT32_C(1403394604), UINT32_C( 516147822) } },
    { UINT64_C( 6571568378511059258),
      { UINT32_C(1649895738), UINT32_C(1530062495) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint32x2_t r = simde_vcreate_u32(test_vec[i].a);
    #if SIMDE_ENDIAN_ORDER == SIMDE_ENDIAN_BIG
      r = simde_vrev64_u32(r);
    #endif
    simde_test_arm_neon_assert_equal_u32x2(r, simde_vld1_u32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    uint64_t a;
    simde_test_codegen_random_memory(sizeof(a), HEDLEY_REINTERPRET_CAST(uint8_t*, &a));
    simde_uint32x2_t r = simde_vcreate_u32(a);
    #if SIMDE_ENDIAN_ORDER == SIMDE_ENDIAN_BIG
      r = simde_vrev64_u32(r);
    #endif
    simde_test_codegen_write_u64(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u32x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcreate_u64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint64_t a;
    uint64_t r[1];
  } test_vec[] = {
    { UINT64_C(16088289664478506354),
      { UINT64_C(16088289664478506354) } },
    { UINT64_C(14353663115278615191),
      { UINT64_C(14353663115278615191) } },
    { UINT64_C(10055237719326986796),
      { UINT64_C(10055237719326986796) } },
    { UINT64_C( 2676819004817795461),
      { UINT64_C( 2676819004817795461) } },
    { UINT64_C(12068038487161698661),
      { UINT64_C(12068038487161698661) } },
    { UINT64_C(16834390251795532107),
      { UINT64_C(16834390251795532107) } },
    { UINT64_C( 2148425483949258710),
      { UINT64_C( 2148425483949258710) } },
    { UINT64_C( 6592735446083894694),
      { UINT64_C( 6592735446083894694) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint64x1_t r = simde_vcreate_u64(test_vec[i].a);

    simde_test_arm_neon_assert_equal_u64x1(r, simde_vld1_u64(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    uint64_t a;
    simde_test_codegen_random_memory(sizeof(a), HEDLEY_REINTERPRET_CAST(uint8_t*, &a));
    simde_uint64x1_t r = simde_vcreate_u64(a);

    simde_test_codegen_write_u64(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u64x1(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcreate_f32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint64_t a;
    simde_float32_t r[2];
  } test_vec[] = {
    { UINT64_C( 4895421239950625997),
      { SIMDE_FLOAT32_C(    10.55), SIMDE_FLOAT32_C(   480.06) } },
    { UINT64_C( 4881962515438488781),
      { SIMDE_FLOAT32_C(  -251.80), SIMDE_FLOAT32_C(   384.43) } },
    { UINT64_C(14107076883095552983),
      { SIMDE_FLOAT32_C(  -548.06), SIMDE_FLOAT32_C(  -396.81) } },
    { UINT64_C(14033351546794605281),
      { SIMDE_FLOAT32_C(   111.49), SIMDE_FLOAT32_C(   -96.24) } },
    { UINT64_C( 4847263689415344620),
      { SIMDE_FLOAT32_C(  -769.03), SIMDE_FLOAT32_C(   196.94) } },
    { UINT64_C(14098345528097009828),
      { SIMDE_FLOAT32_C(  -120.22), SIMDE_FLOAT32_C(  -334.77) } },
    { UINT64_C( 4863914339169869332),
      { SIMDE_FLOAT32_C(   664.47), SIMDE_FLOAT32_C(   256.19) } },
    { UINT64_C(14140687808940682445),
      { SIMDE_FLOAT32_C(   310.35), SIMDE_FLOAT32_C(  -759.26) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x2_t r = simde_vcreate_f32(test_vec[i].a);
    #if SIMDE_ENDIAN_ORDER == SIMDE_ENDIAN_BIG
      r = simde_vrev64_f32(r);
    #endif
    simde_test_arm_neon_assert_equal_f32x2(r, simde_vld1_f32(test_vec[i].r), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    uint64_t a;
    simde_float32x2_t a_ = simde_test_arm_neon_random_f32x2(-1000.0, 1000.0);
    simde_memcpy(&a, &a_, sizeof(a));
    simde_float32x2_t r = simde_vcreate_f32(a);
    #if SIMDE_ENDIAN_ORDER == SIMDE_ENDIAN_BIG
      r = simde_vrev64_f32(r);
    #endif
    simde_test_codegen_write_u64(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f32x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vcreate_f64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint64_t a;
    simde_float64_t r[1];
  } test_vec[] = {
    { UINT64_C(13866319721726811832),
      { SIMDE_FLOAT64_C(  -248.51) } },
    { UINT64_C(13863552470862025196),
      { SIMDE_FLOAT64_C(  -169.86) } },
    { UINT64_C( 4649352999810807890),
      { SIMDE_FLOAT64_C(   698.24) } },
    { UINT64_C(13865571701976203264),
      { SIMDE_FLOAT64_C(  -227.25) } },
    { UINT64_C(13873420367818989240),
      { SIMDE_FLOAT64_C(  -777.29) } },
    { UINT64_C( 4633280778640629432),
      { SIMDE_FLOAT64_C(    57.44) } },
    { UINT64_C(13872760748803253862),
      { SIMDE_FLOAT64_C(  -702.30) } },
    { UINT64_C( 4651543842699849236),
      { SIMDE_FLOAT64_C(   947.31) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float64x1_t r = simde_vcreate_f64(test_vec[i].a);

    simde_test_arm_neon_assert_equal_f64x1(r, simde_vld1_f64(test_vec[i].r), 1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    uint64_t a;
    simde_float64x1_t a_ = simde_test_arm_neon_random_f64x1(-1000.0, 1000.0);
    simde_memcpy(&a, &a_, sizeof(a));
    simde_float64x1_t r = simde_vcreate_f64(a);

    simde_test_codegen_write_u64(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f64x1(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(vcreate_s8)
SIMDE_TEST_FUNC_LIST_ENTRY(vcreate_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vcreate_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vcreate_s64)

SIMDE_TEST_FUNC_LIST_ENTRY(vcreate_u8)
SIMDE_TEST_FUNC_LIST_ENTRY(vcreate_u16)
SIMDE_TEST_FUNC_LIST_ENTRY(vcreate_u32)
SIMDE_TEST_FUNC_LIST_ENTRY(vcreate_u64)

SIMDE_TEST_FUNC_LIST_ENTRY(vcreate_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vcreate_f64)
SIMDE_TEST_FUNC_LIST_END

#include "test-neon-footer.h"
