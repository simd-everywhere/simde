#define SIMDE_TEST_ARM_NEON_INSN sqadd

#include "test-neon.h"
#include "../../../simde/arm/neon/sqadd.h"

static int
test_simde_vsqaddb_u8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint8_t a;
    int8_t b;
    uint8_t r;
  } test_vec[] = {
    { UINT8_C(235),
      -INT8_C(   3),
      UINT8_C(232) },
    { UINT8_C( 50),
      -INT8_C(  75),
      UINT8_C(  0) },
    { UINT8_C(154),
      -INT8_C(  12),
      UINT8_C(142) },
    { UINT8_C( 74),
       INT8_C( 115),
      UINT8_C(189) },
    { UINT8_C(171),
           INT8_MIN,
      UINT8_C( 43) },
    { UINT8_C(221),
       INT8_C( 110),
         UINT8_MAX },
    { UINT8_C(153),
       INT8_C(  73),
      UINT8_C(226) },
    { UINT8_C(123),
       INT8_C(  86),
      UINT8_C(209) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    uint8_t r = simde_vsqaddb_u8(test_vec[i].a, test_vec[i].b);

    simde_assert_equal_u8(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    uint8_t a = simde_test_codegen_random_u8();
    int8_t b = simde_test_codegen_random_i8();
    uint8_t r = simde_vsqaddb_u8(a, b);

    simde_test_codegen_write_u8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_i8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_u8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vsqaddh_u16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint16_t a;
    int16_t b;
    uint16_t r;
  } test_vec[] = {
    { UINT16_C(21963),
      -INT16_C( 19903),
      UINT16_C( 2060) },
    { UINT16_C(50794),
      -INT16_C( 21525),
      UINT16_C(29269) },
    { UINT16_C( 5632),
       INT16_C( 23310),
      UINT16_C(28942) },
    { UINT16_C(53916),
      -INT16_C(  2468),
      UINT16_C(51448) },
    { UINT16_C(63450),
      -INT16_C(  5953),
      UINT16_C(57497) },
    { UINT16_C(36384),
       INT16_C( 29456),
           UINT16_MAX },
    { UINT16_C(37098),
       INT16_C( 10552),
      UINT16_C(47650) },
    { UINT16_C(24113),
      -INT16_C(  1009),
      UINT16_C(23104) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    uint16_t r = simde_vsqaddh_u16(test_vec[i].a, test_vec[i].b);
    simde_assert_equal_u16(r,test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    uint16_t a = simde_test_codegen_random_u16();
    int16_t b = simde_test_codegen_random_i16();
    uint16_t r = simde_vsqaddh_u16(a, b);

    simde_test_codegen_write_u16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_i16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_u16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vsqadds_u32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint32_t a;
    int32_t b;
    uint32_t r;
  } test_vec[] = {
    { UINT32_C(3489568587),
      -INT32_C(  1873806719),
      UINT32_C(1615761868) },
    { UINT32_C(2032992756),
       INT32_C(  2127588818),
      UINT32_C(4160581574) },
    { UINT32_C(2523629162),
       INT32_C(   453590793),
      UINT32_C(2977219955) },
    { UINT32_C(2083290111),
       INT32_C(   696202974),
      UINT32_C(2779493085) },
    { UINT32_C(1324907981),
       INT32_C(  1826506872),
      UINT32_C(3151414853) },
    { UINT32_C( 484838473),
      -INT32_C(   476400007),
      UINT32_C(   8438466) },
    { UINT32_C(1165559100),
       INT32_C(  1147241029),
      UINT32_C(2312800129) },
    { UINT32_C(3686829565),
      -INT32_C(  1878769725),
      UINT32_C(1808059840) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    uint32_t r = simde_vsqadds_u32(test_vec[i].a, test_vec[i].b);
    simde_assert_equal_u32(r,test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    uint32_t a = simde_test_codegen_random_u32();
    int32_t b = simde_test_codegen_random_i32();
    uint32_t r = simde_vsqadds_u32(a, b);

    simde_test_codegen_write_u32(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_i32(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_u32(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vsqaddd_u64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint64_t a;
    int64_t b;
    uint64_t r;
  } test_vec[] = {
    { UINT64_C(13376790721018916519),
      -INT64_C( 4863684982274621397),
      UINT64_C( 8513105738744295122) },
    { UINT64_C( 9027932681502520712),
       INT64_C( 5441760830793208911),
      UINT64_C(14469693512295729623) },
    { UINT64_C(12318901336277293042),
       INT64_C( 5983937876230279943),
      UINT64_C(18302839212507572985) },
    { UINT64_C( 1917044475376182060),
      -INT64_C( 6703193874414523638),
      UINT64_C(                   0) },
    { UINT64_C( 7798495559120968975),
       INT64_C( 5981841504337588453),
      UINT64_C(13780337063458557428) },
    { UINT64_C( 3444421546560548840),
       INT64_C( 5118576514238890166),
      UINT64_C( 8562998060799439006) },
    { UINT64_C(11349933868763768243),
      -INT64_C( 1406722859613667840),
      UINT64_C( 9943211009150100403) },
    { UINT64_C(12471995654566046657),
       INT64_C( 8911528310162584109),
                         UINT64_MAX },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    uint64_t r = simde_vsqaddd_u64(test_vec[i].a, test_vec[i].b);
    simde_assert_equal_u64(r,test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    uint64_t a = simde_test_codegen_random_u64();
    int64_t b = simde_test_codegen_random_i64();
    uint64_t r = simde_vsqaddd_u64(a, b);

    simde_test_codegen_write_u64(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_i64(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_u64(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vsqadd_u8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint8_t a[8];
    int8_t b[8];
    uint8_t r[8];
  } test_vec[] = {
    { { UINT8_C(208), UINT8_C( 12), UINT8_C(182), UINT8_C(206), UINT8_C(138), UINT8_C( 82), UINT8_C(138), UINT8_C(210) },
      {  INT8_C(  70), -INT8_C(  34), -INT8_C(  51),  INT8_C(   0),  INT8_C(  26), -INT8_C(   3),  INT8_C(  12),  INT8_C( 116) },
      {    UINT8_MAX, UINT8_C(  0), UINT8_C(131), UINT8_C(206), UINT8_C(164), UINT8_C( 79), UINT8_C(150),    UINT8_MAX } },
    { { UINT8_C( 13), UINT8_C(174), UINT8_C(176), UINT8_C( 99), UINT8_C(171), UINT8_C(252), UINT8_C(208), UINT8_C( 63) },
      { -INT8_C(   4),  INT8_C(  58),  INT8_C( 119),  INT8_C(   3), -INT8_C( 104),  INT8_C(  51), -INT8_C(  69),  INT8_C( 105) },
      { UINT8_C(  9), UINT8_C(232),    UINT8_MAX, UINT8_C(102), UINT8_C( 67),    UINT8_MAX, UINT8_C(139), UINT8_C(168) } },
    { { UINT8_C( 63), UINT8_C(113), UINT8_C( 55), UINT8_C(202), UINT8_C(196), UINT8_C(193), UINT8_C(156), UINT8_C( 10) },
      { -INT8_C(  97),  INT8_C( 106),  INT8_C(  10), -INT8_C(  71),  INT8_C( 103),  INT8_C(  23),  INT8_C(  46),  INT8_C( 116) },
      { UINT8_C(  0), UINT8_C(219), UINT8_C( 65), UINT8_C(131),    UINT8_MAX, UINT8_C(216), UINT8_C(202), UINT8_C(126) } },
    { { UINT8_C(197), UINT8_C(222), UINT8_C(216), UINT8_C(112), UINT8_C(219), UINT8_C(168), UINT8_C(176), UINT8_C(215) },
      { -INT8_C(  29),  INT8_C(  39), -INT8_C(  38),  INT8_C( 123),  INT8_C(  91), -INT8_C( 107), -INT8_C(  28), -INT8_C( 102) },
      { UINT8_C(168),    UINT8_MAX, UINT8_C(178), UINT8_C(235),    UINT8_MAX, UINT8_C( 61), UINT8_C(148), UINT8_C(113) } },
    { { UINT8_C(  6), UINT8_C( 27), UINT8_C(100), UINT8_C(202), UINT8_C(220), UINT8_C(  1), UINT8_C(212), UINT8_C(124) },
      {  INT8_C( 107), -INT8_C(  33),  INT8_C(  53), -INT8_C(  46), -INT8_C(  10),  INT8_C(  99),  INT8_C(  70), -INT8_C(  69) },
      { UINT8_C(113), UINT8_C(  0), UINT8_C(153), UINT8_C(156), UINT8_C(210), UINT8_C(100),    UINT8_MAX, UINT8_C( 55) } },
    { { UINT8_C( 66), UINT8_C( 30), UINT8_C( 43), UINT8_C( 29), UINT8_C(199), UINT8_C(219), UINT8_C(244), UINT8_C(170) },
      {  INT8_C(   3), -INT8_C(  50),  INT8_C(  37),  INT8_C(  94),  INT8_C(  99),  INT8_C(  10), -INT8_C(   8),  INT8_C( 105) },
      { UINT8_C( 69), UINT8_C(  0), UINT8_C( 80), UINT8_C(123),    UINT8_MAX, UINT8_C(229), UINT8_C(236),    UINT8_MAX } },
    { { UINT8_C( 37), UINT8_C( 93), UINT8_C( 52), UINT8_C(  2), UINT8_C( 94), UINT8_C(  8), UINT8_C(126), UINT8_C(201) },
      { -INT8_C(  25), -INT8_C(  77), -INT8_C( 101), -INT8_C(  35),  INT8_C(  23), -INT8_C(  31), -INT8_C( 104),  INT8_C(  89) },
      { UINT8_C( 12), UINT8_C( 16), UINT8_C(  0), UINT8_C(  0), UINT8_C(117), UINT8_C(  0), UINT8_C( 22),    UINT8_MAX } },
    { { UINT8_C(  0), UINT8_C(196), UINT8_C(118), UINT8_C(199), UINT8_C(159), UINT8_C(106), UINT8_C(113), UINT8_C(162) },
      {  INT8_C(  56), -INT8_C( 106),  INT8_C(   0), -INT8_C( 101), -INT8_C(  96), -INT8_C(   7),  INT8_C(   4), -INT8_C(  58) },
      { UINT8_C( 56), UINT8_C( 90), UINT8_C(118), UINT8_C( 98), UINT8_C( 63), UINT8_C( 99), UINT8_C(117), UINT8_C(104) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint8x8_t a = simde_vld1_u8(test_vec[i].a);
    simde_int8x8_t b = simde_vld1_s8(test_vec[i].b);
    simde_uint8x8_t r = simde_vsqadd_u8(a, b);

    simde_test_arm_neon_assert_equal_u8x8(r, simde_vld1_u8(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint8x8_t a = simde_test_arm_neon_random_u8x8();
    simde_int8x8_t b = simde_test_arm_neon_random_i8x8();
    simde_uint8x8_t r = simde_vsqadd_u8(a, b);

    simde_test_arm_neon_write_u8x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i8x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u8x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vsqadd_u16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint16_t a[4];
    int16_t b[4];
    uint16_t r[4];
  } test_vec[] = {
    { { UINT16_C(22188), UINT16_C( 1243), UINT16_C( 4885), UINT16_C(51482) },
      {  INT16_C( 16984),  INT16_C( 13012), -INT16_C( 16284),  INT16_C( 10206) },
      { UINT16_C(39172), UINT16_C(14255), UINT16_C(    0), UINT16_C(61688) } },
    { { UINT16_C(63428), UINT16_C(15507), UINT16_C(48682), UINT16_C(53236) },
      {  INT16_C( 31580),  INT16_C( 32625),  INT16_C( 21616),  INT16_C(  7345) },
      {      UINT16_MAX, UINT16_C(48132),      UINT16_MAX, UINT16_C(60581) } },
    { { UINT16_C(36266), UINT16_C(48928), UINT16_C(15008), UINT16_C(63624) },
      {  INT16_C( 23932), -INT16_C(  7894),  INT16_C(  2077), -INT16_C(  7928) },
      { UINT16_C(60198), UINT16_C(41034), UINT16_C(17085), UINT16_C(55696) } },
    { { UINT16_C(39935), UINT16_C(10781), UINT16_C( 4697), UINT16_C(46841) },
      {  INT16_C( 27533), -INT16_C(   715), -INT16_C(  6209),  INT16_C( 26905) },
      {      UINT16_MAX, UINT16_C(10066), UINT16_C(    0),      UINT16_MAX } },
    { { UINT16_C(14964), UINT16_C( 5161), UINT16_C(45428), UINT16_C(61709) },
      {  INT16_C( 14094),  INT16_C( 11474), -INT16_C(  9664),  INT16_C( 16141) },
      { UINT16_C(29058), UINT16_C(16635), UINT16_C(35764),      UINT16_MAX } },
    { { UINT16_C(11125), UINT16_C(52841), UINT16_C(25405), UINT16_C(51844) },
      { -INT16_C( 17714), -INT16_C( 29240), -INT16_C(  7775),  INT16_C(  5622) },
      { UINT16_C(    0), UINT16_C(23601), UINT16_C(17630), UINT16_C(57466) } },
    { { UINT16_C( 7963), UINT16_C(36905), UINT16_C(14033), UINT16_C(57217) },
      {  INT16_C( 21358), -INT16_C( 20981),  INT16_C(  6445), -INT16_C( 23827) },
      { UINT16_C(29321), UINT16_C(15924), UINT16_C(20478), UINT16_C(33390) } },
    { { UINT16_C(22340), UINT16_C(33136), UINT16_C(62906), UINT16_C(34891) },
      {  INT16_C(  5039),  INT16_C( 20501),  INT16_C(  3061),  INT16_C(  4197) },
      { UINT16_C(27379), UINT16_C(53637),      UINT16_MAX, UINT16_C(39088) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint16x4_t a = simde_vld1_u16(test_vec[i].a);
    simde_int16x4_t b = simde_vld1_s16(test_vec[i].b);
    simde_uint16x4_t r = simde_vsqadd_u16(a, b);
    simde_test_arm_neon_assert_equal_u16x4(r, simde_vld1_u16(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint16x4_t a = simde_test_arm_neon_random_u16x4();
    simde_int16x4_t b = simde_test_arm_neon_random_i16x4();
    simde_uint16x4_t r = simde_vsqadd_u16(a, b);

    simde_test_arm_neon_write_u16x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i16x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u16x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vsqadd_u32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint32_t a[2];
    int32_t b[2];
    uint32_t r[2];
  } test_vec[] = {
    { { UINT32_C(2383070015), UINT32_C(3373088139) },
      {  INT32_C(  1168927325), -INT32_C(  1014613093) },
      { UINT32_C(3551997340), UINT32_C(2358475046) } },
    { { UINT32_C(3277414014), UINT32_C(3080812116) },
      { -INT32_C(   658419766),  INT32_C(   468224987) },
      { UINT32_C(2618994248), UINT32_C(3549037103) } },
    { { UINT32_C(3668570703), UINT32_C(2376381999) },
      { -INT32_C(  1127067616),  INT32_C(   159340939) },
      { UINT32_C(2541503087), UINT32_C(2535722938) } },
    { { UINT32_C( 198039991), UINT32_C( 449015375) },
      { -INT32_C(  1728936771),  INT32_C(  1605622288) },
      { UINT32_C(         0), UINT32_C(2054637663) } },
    { { UINT32_C(4231617996), UINT32_C( 881450259) },
      { -INT32_C(  1175430354),  INT32_C(  1807970228) },
      { UINT32_C(3056187642), UINT32_C(2689420487) } },
    { { UINT32_C(2557972552), UINT32_C(3149019902) },
      { -INT32_C(   833379138),  INT32_C(  1261242239) },
      { UINT32_C(1724593414),           UINT32_MAX } },
    { { UINT32_C(2001168228), UINT32_C(1923862596) },
      { -INT32_C(   533947604),  INT32_C(  1397550859) },
      { UINT32_C(1467220624), UINT32_C(3321413455) } },
    { { UINT32_C(2112603007), UINT32_C(3141049853) },
      { -INT32_C(  1047884990), -INT32_C(   166938734) },
      { UINT32_C(1064718017), UINT32_C(2974111119) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint32x2_t a = simde_vld1_u32(test_vec[i].a);
    simde_int32x2_t b = simde_vld1_s32(test_vec[i].b);
    simde_uint32x2_t r = simde_vsqadd_u32(a, b);
    simde_test_arm_neon_assert_equal_u32x2(r, simde_vld1_u32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint32x2_t a = simde_test_arm_neon_random_u32x2();
    simde_int32x2_t b = simde_test_arm_neon_random_i32x2();
    simde_uint32x2_t r = simde_vsqadd_u32(a, b);

    simde_test_arm_neon_write_u32x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i32x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vsqadd_u64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint64_t a[1];
    int64_t b[1];
    uint64_t r[1];
  } test_vec[] = {
    { { UINT64_C( 7902564638570605863) },
      { -INT64_C( 1146075095428238619) },
      { UINT64_C( 6756489543142367244) } },
    { { UINT64_C(11498359509728529418) },
      {  INT64_C( 2214837495378286594) },
      { UINT64_C(13713197005106816012) } },
    { { UINT64_C(13705607984844786716) },
      { -INT64_C( 6574778702501427445) },
      { UINT64_C( 7130829282343359271) } },
    { { UINT64_C( 4533669330327624509) },
      { -INT64_C( 1080127418621941779) },
      { UINT64_C( 3453541911705682730) } },
    { { UINT64_C(10700813890565468393) },
      {  INT64_C(  608871931896404276) },
      { UINT64_C(11309685822461872669) } },
    { { UINT64_C( 8537485178242839808) },
      { -INT64_C( 2077464573310772124) },
      { UINT64_C( 6460020604932067684) } },
    { { UINT64_C(  425913220778550476) },
      {  INT64_C( 8363826017408929343) },
      { UINT64_C( 8789739238187479819) } },
    { { UINT64_C(  647440427757102844) },
      {  INT64_C( 9179864033216583304) },
      { UINT64_C( 9827304460973686148) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint64x1_t a = simde_vld1_u64(test_vec[i].a);
    simde_int64x1_t b = simde_vld1_s64(test_vec[i].b);
    simde_uint64x1_t r = simde_vsqadd_u64(a, b);
    simde_test_arm_neon_assert_equal_u64x1(r, simde_vld1_u64(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint64x1_t a = simde_test_arm_neon_random_u64x1();
    simde_int64x1_t b = simde_test_arm_neon_random_i64x1();
    simde_uint64x1_t r = simde_vsqadd_u64(a, b);

    simde_test_arm_neon_write_u64x1(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i64x1(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u64x1(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vsqaddq_u8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint8_t a[16];
    int8_t b[16];
    uint8_t r[16];
  } test_vec[] = {
    { { UINT8_C(187), UINT8_C(234), UINT8_C(138), UINT8_C(250), UINT8_C(226), UINT8_C( 64), UINT8_C(225), UINT8_C( 77),
        UINT8_C(123), UINT8_C(  9), UINT8_C( 27), UINT8_C( 23), UINT8_C(229), UINT8_C( 15), UINT8_C(241), UINT8_C(245) },
      {  INT8_C(  38),  INT8_C( 103),  INT8_C( 109), -INT8_C(  28), -INT8_C(  36), -INT8_C( 102),  INT8_C( 122),  INT8_C(   1),
        -INT8_C( 124), -INT8_C(   8),  INT8_C(  35),  INT8_C( 103),  INT8_C(  15), -INT8_C(  38),  INT8_C(  45), -INT8_C(  54) },
      { UINT8_C(225),    UINT8_MAX, UINT8_C(247), UINT8_C(222), UINT8_C(190), UINT8_C(  0),    UINT8_MAX, UINT8_C( 78),
        UINT8_C(  0), UINT8_C(  1), UINT8_C( 62), UINT8_C(126), UINT8_C(244), UINT8_C(  0),    UINT8_MAX, UINT8_C(191) } },
    { { UINT8_C(196), UINT8_C(183), UINT8_C(196), UINT8_C(166), UINT8_C(248), UINT8_C(165), UINT8_C(244), UINT8_C(115),
        UINT8_C(174), UINT8_C( 15), UINT8_C(138), UINT8_C(147), UINT8_C( 30), UINT8_C(123), UINT8_C(136), UINT8_C( 68) },
      { -INT8_C(  29), -INT8_C(  10),  INT8_C(  40), -INT8_C(  65), -INT8_C( 112), -INT8_C(  93), -INT8_C(  63),  INT8_C(  20),
        -INT8_C( 101), -INT8_C(  28),  INT8_C( 124), -INT8_C(  86), -INT8_C(  66), -INT8_C(  87),  INT8_C( 116), -INT8_C( 126) },
      { UINT8_C(167), UINT8_C(173), UINT8_C(236), UINT8_C(101), UINT8_C(136), UINT8_C( 72), UINT8_C(181), UINT8_C(135),
        UINT8_C( 73), UINT8_C(  0),    UINT8_MAX, UINT8_C( 61), UINT8_C(  0), UINT8_C( 36), UINT8_C(252), UINT8_C(  0) } },
    { { UINT8_C( 96), UINT8_C( 56), UINT8_C( 40), UINT8_C( 88), UINT8_C(221), UINT8_C( 28), UINT8_C(204), UINT8_C(139),
        UINT8_C( 43), UINT8_C( 86), UINT8_C( 31), UINT8_C( 74), UINT8_C(210), UINT8_C(167), UINT8_C(142), UINT8_C(181) },
      { -INT8_C(  99), -INT8_C(  73),  INT8_C( 116),  INT8_C(  45),  INT8_C(  90),  INT8_C(  53),  INT8_C(  66), -INT8_C(  11),
         INT8_C(  25), -INT8_C(  66), -INT8_C(  97), -INT8_C(  41),  INT8_C( 103),  INT8_C(  19),  INT8_C(  89), -INT8_C(  57) },
      { UINT8_C(  0), UINT8_C(  0), UINT8_C(156), UINT8_C(133),    UINT8_MAX, UINT8_C( 81),    UINT8_MAX, UINT8_C(128),
        UINT8_C( 68), UINT8_C( 20), UINT8_C(  0), UINT8_C( 33),    UINT8_MAX, UINT8_C(186), UINT8_C(231), UINT8_C(124) } },
    { { UINT8_C( 75), UINT8_C(130), UINT8_C( 32), UINT8_C( 40), UINT8_C(158), UINT8_C(236), UINT8_C(179), UINT8_C(202),
        UINT8_C( 66), UINT8_C(210), UINT8_C( 20), UINT8_C( 20), UINT8_C(122), UINT8_C(162), UINT8_C(201), UINT8_C( 23) },
      {  INT8_C(  89),  INT8_C(  62),  INT8_C(  69), -INT8_C(  77),  INT8_C( 115), -INT8_C( 121), -INT8_C(  88), -INT8_C( 115),
         INT8_C(  69),  INT8_C(  71),  INT8_C( 100), -INT8_C(  84),  INT8_C(  90), -INT8_C(  66),  INT8_C( 115), -INT8_C(  91) },
      { UINT8_C(164), UINT8_C(192), UINT8_C(101), UINT8_C(  0),    UINT8_MAX, UINT8_C(115), UINT8_C( 91), UINT8_C( 87),
        UINT8_C(135),    UINT8_MAX, UINT8_C(120), UINT8_C(  0), UINT8_C(212), UINT8_C( 96),    UINT8_MAX, UINT8_C(  0) } },
    { { UINT8_C( 64), UINT8_C(147), UINT8_C(205), UINT8_C(222), UINT8_C(127), UINT8_C(129), UINT8_C(168), UINT8_C(194),
        UINT8_C( 83), UINT8_C(188), UINT8_C(214), UINT8_C(205), UINT8_C( 95), UINT8_C(160), UINT8_C(229), UINT8_C(184) },
      { -INT8_C(  34),  INT8_C(  42),  INT8_C( 108),  INT8_C(  81), -INT8_C(  79),  INT8_C(  20), -INT8_C(  34), -INT8_C(  10),
         INT8_C(  92),  INT8_C(  67), -INT8_C(  94), -INT8_C(  74),  INT8_C(   1),  INT8_C(  21),  INT8_C(  92),  INT8_C(  65) },
      { UINT8_C( 30), UINT8_C(189),    UINT8_MAX,    UINT8_MAX, UINT8_C( 48), UINT8_C(149), UINT8_C(134), UINT8_C(184),
        UINT8_C(175),    UINT8_MAX, UINT8_C(120), UINT8_C(131), UINT8_C( 96), UINT8_C(181),    UINT8_MAX, UINT8_C(249) } },
    { { UINT8_C(169), UINT8_C( 41), UINT8_C( 31), UINT8_C( 40), UINT8_C(170), UINT8_C(200), UINT8_C(234), UINT8_C(254),
        UINT8_C(132), UINT8_C(193), UINT8_C(203), UINT8_C(227), UINT8_C( 97), UINT8_C(176), UINT8_C(156), UINT8_C( 63) },
      { -INT8_C(  38),  INT8_C(   8), -INT8_C( 112), -INT8_C( 117),  INT8_C(  28),  INT8_C( 111), -INT8_C( 127),  INT8_C( 120),
        -INT8_C(  78),  INT8_C(  35),  INT8_C(  47), -INT8_C(  77),  INT8_C(  57), -INT8_C( 117), -INT8_C(  12), -INT8_C(  30) },
      { UINT8_C(131), UINT8_C( 49), UINT8_C(  0), UINT8_C(  0), UINT8_C(198),    UINT8_MAX, UINT8_C(107),    UINT8_MAX,
        UINT8_C( 54), UINT8_C(228), UINT8_C(250), UINT8_C(150), UINT8_C(154), UINT8_C( 59), UINT8_C(144), UINT8_C( 33) } },
    { { UINT8_C(180), UINT8_C( 19), UINT8_C( 10), UINT8_C( 95), UINT8_C(219), UINT8_C(245), UINT8_C( 93), UINT8_C( 96),
        UINT8_C(182), UINT8_C( 40), UINT8_C( 67), UINT8_C( 23), UINT8_C(217), UINT8_C(223), UINT8_C( 86), UINT8_C(179) },
      { -INT8_C(  25), -INT8_C(  26),  INT8_C(  63),  INT8_C(   4),  INT8_C(  85), -INT8_C(  64),  INT8_C( 124),  INT8_C(   7),
        -INT8_C(  28), -INT8_C(  85), -INT8_C(  70),  INT8_C(  29),  INT8_C(  54), -INT8_C(  82), -INT8_C(   1), -INT8_C(  21) },
      { UINT8_C(155), UINT8_C(  0), UINT8_C( 73), UINT8_C( 99),    UINT8_MAX, UINT8_C(181), UINT8_C(217), UINT8_C(103),
        UINT8_C(154), UINT8_C(  0), UINT8_C(  0), UINT8_C( 52),    UINT8_MAX, UINT8_C(141), UINT8_C( 85), UINT8_C(158) } },
    { { UINT8_C(194), UINT8_C(  9), UINT8_C( 74), UINT8_C(157), UINT8_C(254), UINT8_C(167), UINT8_C(253), UINT8_C(180),
        UINT8_C(207), UINT8_C( 65), UINT8_C(203), UINT8_C(168), UINT8_C( 32), UINT8_C( 33), UINT8_C( 92), UINT8_C(  8) },
      {  INT8_C(   8), -INT8_C( 101),  INT8_C(  12),  INT8_C(  93),  INT8_C(  91), -INT8_C( 120),  INT8_C( 101),  INT8_C(  63),
         INT8_C(  52),  INT8_C(  31),  INT8_C(  92),  INT8_C( 106), -INT8_C(  50),  INT8_C(  91),  INT8_C(  85), -INT8_C( 112) },
      { UINT8_C(202), UINT8_C(  0), UINT8_C( 86), UINT8_C(250),    UINT8_MAX, UINT8_C( 47),    UINT8_MAX, UINT8_C(243),
           UINT8_MAX, UINT8_C( 96),    UINT8_MAX,    UINT8_MAX, UINT8_C(  0), UINT8_C(124), UINT8_C(177), UINT8_C(  0) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint8x16_t a = simde_vld1q_u8(test_vec[i].a);
    simde_int8x16_t b = simde_vld1q_s8(test_vec[i].b);
    simde_uint8x16_t r = simde_vsqaddq_u8(a, b);

    simde_test_arm_neon_assert_equal_u8x16(r, simde_vld1q_u8(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint8x16_t a = simde_test_arm_neon_random_u8x16();
    simde_int8x16_t b = simde_test_arm_neon_random_i8x16();
    simde_uint8x16_t r = simde_vsqaddq_u8(a, b);

    simde_test_arm_neon_write_u8x16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i8x16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u8x16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vsqaddq_u16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint16_t a[8];
    int16_t b[8];
    uint16_t r[8];
  } test_vec[] = {
    { { UINT16_C( 4390), UINT16_C( 7679), UINT16_C( 3074), UINT16_C(48682), UINT16_C( 6020), UINT16_C( 1089), UINT16_C(52588), UINT16_C(46383) },
      { -INT16_C( 15973), -INT16_C( 19793), -INT16_C( 17099), -INT16_C( 22711),  INT16_C(  1523), -INT16_C( 18569), -INT16_C( 19512), -INT16_C(  4290) },
      { UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(25971), UINT16_C( 7543), UINT16_C(    0), UINT16_C(33076), UINT16_C(42093) } },
    { { UINT16_C(15812), UINT16_C(50956), UINT16_C(13897), UINT16_C(52613), UINT16_C(50765), UINT16_C(47569), UINT16_C(  404), UINT16_C(12142) },
      {  INT16_C(  7618), -INT16_C(  2079),  INT16_C( 10970), -INT16_C( 12898),  INT16_C(  5423), -INT16_C(  2171), -INT16_C( 15416), -INT16_C( 29210) },
      { UINT16_C(23430), UINT16_C(48877), UINT16_C(24867), UINT16_C(39715), UINT16_C(56188), UINT16_C(45398), UINT16_C(    0), UINT16_C(    0) } },
    { { UINT16_C(61953), UINT16_C(19028), UINT16_C(55592), UINT16_C(29976), UINT16_C(59808), UINT16_C(13358), UINT16_C(40426), UINT16_C(44131) },
      {  INT16_C( 17594), -INT16_C( 27229),  INT16_C( 16750), -INT16_C( 25246), -INT16_C(  6314),  INT16_C(  8084),  INT16_C( 31659), -INT16_C( 21332) },
      {      UINT16_MAX, UINT16_C(    0),      UINT16_MAX, UINT16_C( 4730), UINT16_C(53494), UINT16_C(21442),      UINT16_MAX, UINT16_C(22799) } },
    { { UINT16_C(  109), UINT16_C(38646), UINT16_C( 3801), UINT16_C(30987), UINT16_C(15096), UINT16_C(58029), UINT16_C( 4311), UINT16_C(37263) },
      {  INT16_C( 12884), -INT16_C( 15834), -INT16_C( 30348), -INT16_C( 13729), -INT16_C(  2960),  INT16_C(  7145), -INT16_C( 27281), -INT16_C(  9017) },
      { UINT16_C(12993), UINT16_C(22812), UINT16_C(    0), UINT16_C(17258), UINT16_C(12136), UINT16_C(65174), UINT16_C(    0), UINT16_C(28246) } },
    { { UINT16_C(48789), UINT16_C(28530), UINT16_C(32460), UINT16_C(50408), UINT16_C(38584), UINT16_C(36775), UINT16_C(13990), UINT16_C(64288) },
      {  INT16_C( 18280), -INT16_C(  9027),  INT16_C(  7632),  INT16_C( 16551), -INT16_C( 28655), -INT16_C( 32676),  INT16_C(  8998), -INT16_C( 17572) },
      {      UINT16_MAX, UINT16_C(19503), UINT16_C(40092),      UINT16_MAX, UINT16_C( 9929), UINT16_C( 4099), UINT16_C(22988), UINT16_C(46716) } },
    { { UINT16_C(53217), UINT16_C(44586), UINT16_C( 4941), UINT16_C( 1394), UINT16_C( 6569), UINT16_C(20372), UINT16_C(46159), UINT16_C(47178) },
      {  INT16_C(  2299), -INT16_C( 13420),  INT16_C( 15141),  INT16_C( 13836),  INT16_C( 26828), -INT16_C(  3402),  INT16_C(  4747),  INT16_C( 28077) },
      { UINT16_C(55516), UINT16_C(31166), UINT16_C(20082), UINT16_C(15230), UINT16_C(33397), UINT16_C(16970), UINT16_C(50906),      UINT16_MAX } },
    { { UINT16_C(55521), UINT16_C(11803), UINT16_C(36331), UINT16_C(37939), UINT16_C(51111), UINT16_C(63203), UINT16_C(11900), UINT16_C(30638) },
      {  INT16_C( 17206),  INT16_C( 23363),  INT16_C( 20350),  INT16_C( 19089),  INT16_C( 18359),  INT16_C( 16956), -INT16_C(  5543),  INT16_C( 15279) },
      {      UINT16_MAX, UINT16_C(35166), UINT16_C(56681), UINT16_C(57028),      UINT16_MAX,      UINT16_MAX, UINT16_C( 6357), UINT16_C(45917) } },
    { { UINT16_C(51906), UINT16_C(44393), UINT16_C(40280), UINT16_C(65345), UINT16_C( 9316), UINT16_C(57589), UINT16_C(42066), UINT16_C(34904) },
      { -INT16_C( 25625),  INT16_C( 26083),  INT16_C( 29930), -INT16_C( 24144), -INT16_C(  4933),  INT16_C(  5603), -INT16_C( 27690), -INT16_C( 26544) },
      { UINT16_C(26281),      UINT16_MAX,      UINT16_MAX, UINT16_C(41201), UINT16_C( 4383), UINT16_C(63192), UINT16_C(14376), UINT16_C( 8360) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint16x8_t a = simde_vld1q_u16(test_vec[i].a);
    simde_int16x8_t b = simde_vld1q_s16(test_vec[i].b);
    simde_uint16x8_t r = simde_vsqaddq_u16(a, b);
    simde_test_arm_neon_assert_equal_u16x8(r, simde_vld1q_u16(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint16x8_t a = simde_test_arm_neon_random_u16x8();
    simde_int16x8_t b = simde_test_arm_neon_random_i16x8();
    simde_uint16x8_t r = simde_vsqaddq_u16(a, b);

    simde_test_arm_neon_write_u16x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i16x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u16x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vsqaddq_u32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint32_t a[4];
    int32_t b[4];
    uint32_t r[4];
  } test_vec[] = {
    { { UINT32_C(3535302333), UINT32_C( 256073739), UINT32_C(4285098820), UINT32_C(1669858744) },
      { -INT32_C(   465589633),  INT32_C(   125697127),  INT32_C(   629862414),  INT32_C(  1251739789) },
      { UINT32_C(3069712700), UINT32_C( 381770866),           UINT32_MAX, UINT32_C(2921598533) } },
    { { UINT32_C(2182960246), UINT32_C(4187054261), UINT32_C(2230909644), UINT32_C(2145878016) },
      { -INT32_C(  1838995925),  INT32_C(   832167970),  INT32_C(  1582703825), -INT32_C(  1565986260) },
      { UINT32_C( 343964321),           UINT32_MAX, UINT32_C(3813613469), UINT32_C( 579891756) } },
    { { UINT32_C(4230268231), UINT32_C(4076188966), UINT32_C(2960584112), UINT32_C(2553240941) },
      { -INT32_C(  1507093629),  INT32_C(  1154991219),  INT32_C(   346172904),  INT32_C(  1723288351) },
      { UINT32_C(2723174602),           UINT32_MAX, UINT32_C(3306757016), UINT32_C(4276529292) } },
    { { UINT32_C( 912448272), UINT32_C(1093162897), UINT32_C(3002179140), UINT32_C(2135564539) },
      {  INT32_C(   656766387),  INT32_C(   577502266),  INT32_C(  1211567657),  INT32_C(  1773137497) },
      { UINT32_C(1569214659), UINT32_C(1670665163), UINT32_C(4213746797), UINT32_C(3908702036) } },
    { { UINT32_C(1520439753), UINT32_C(2912667753), UINT32_C(1650429031), UINT32_C(1625402029) },
      {  INT32_C(  1502021151),  INT32_C(   729608962),  INT32_C(  1517597441),  INT32_C(  1791173537) },
      { UINT32_C(3022460904), UINT32_C(3642276715), UINT32_C(3168026472), UINT32_C(3416575566) } },
    { { UINT32_C(2646958900), UINT32_C(2471190572), UINT32_C(2599791341), UINT32_C(1962596180) },
      { -INT32_C(   523402531),  INT32_C(  1980451189), -INT32_C(  1647280132), -INT32_C(   687303774) },
      { UINT32_C(2123556369),           UINT32_MAX, UINT32_C( 952511209), UINT32_C(1275292406) } },
    { { UINT32_C( 594857463), UINT32_C( 448184109), UINT32_C(3199511402), UINT32_C(1613934466) },
      { -INT32_C(  1505755087),  INT32_C(  1176259401),  INT32_C(  1843653835),  INT32_C(  1984228223) },
      { UINT32_C(         0), UINT32_C(1624443510),           UINT32_MAX, UINT32_C(3598162689) } },
    { { UINT32_C(3868834232), UINT32_C(3791671160), UINT32_C(2107749883), UINT32_C(2514342756) },
      {  INT32_C(   490413523),  INT32_C(   878925673), -INT32_C(  1029618109), -INT32_C(   365304270) },
      {           UINT32_MAX,           UINT32_MAX, UINT32_C(1078131774), UINT32_C(2149038486) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint32x4_t a = simde_vld1q_u32(test_vec[i].a);
    simde_int32x4_t b = simde_vld1q_s32(test_vec[i].b);
    simde_uint32x4_t r = simde_vsqaddq_u32(a, b);

    simde_test_arm_neon_assert_equal_u32x4(r, simde_vld1q_u32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint32x4_t a = simde_test_arm_neon_random_u32x4();
    simde_int32x4_t b = simde_test_arm_neon_random_i32x4();
    simde_uint32x4_t r = simde_vsqaddq_u32(a, b);

    simde_test_arm_neon_write_u32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vsqaddq_u64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint64_t a[2];
    int64_t b[2];
    uint64_t r[2];
  } test_vec[] = {
    { { UINT64_C( 7020914322338813153), UINT64_C(13805675261520561189) },
      { -INT64_C( 8048815091670664102), -INT64_C( 7262527486024997202) },
      { UINT64_C(                   0), UINT64_C( 6543147775495563987) } },
    { { UINT64_C( 2100578450909735781), UINT64_C( 8197935705827342980) },
      {  INT64_C( 8902010957190918056),  INT64_C( 4091398023146013298) },
      { UINT64_C(11002589408100653837), UINT64_C(12289333728973356278) } },
    { { UINT64_C( 6651856061118355515), UINT64_C( 4045963718199256478) },
      { -INT64_C( 2135343455286450923), -INT64_C( 9058192099768355010) },
      { UINT64_C( 4516512605831904592), UINT64_C(                   0) } },
    { { UINT64_C(  658095555514616046), UINT64_C(13867960576690259115) },
      { -INT64_C( 6819294937316415991),  INT64_C( 3423014176672672694) },
      { UINT64_C(                   0), UINT64_C(17290974753362931809) } },
    { { UINT64_C(16769741711918577221), UINT64_C( 7424070037136505244) },
      {  INT64_C( 6936174174878673471),  INT64_C( 4042224705227060648) },
      {                    UINT64_MAX, UINT64_C(11466294742363565892) } },
    { { UINT64_C(13923058728194084115), UINT64_C( 3738286708388027421) },
      { -INT64_C( 6286155364436688199),  INT64_C( 1240929705248563213) },
      { UINT64_C( 7636903363757395916), UINT64_C( 4979216413636590634) } },
    { { UINT64_C(16401715972326630072), UINT64_C( 8006625763088246517) },
      {  INT64_C( 1705339279125967361), -INT64_C( 7006105793039221579) },
      { UINT64_C(18107055251452597433), UINT64_C( 1000519970049024938) } },
    { { UINT64_C(13049771183614666353), UINT64_C(13322982193318820031) },
      {  INT64_C(   58657071557162671), -INT64_C( 6330520421809199200) },
      { UINT64_C(13108428255171829024), UINT64_C( 6992461771509620831) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint64x2_t a = simde_vld1q_u64(test_vec[i].a);
    simde_int64x2_t b = simde_vld1q_s64(test_vec[i].b);
    simde_uint64x2_t r = simde_vsqaddq_u64(a, b);
    simde_test_arm_neon_assert_equal_u64x2(r, simde_vld1q_u64(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint64x2_t a = simde_test_arm_neon_random_u64x2();
    simde_int64x2_t b = simde_test_arm_neon_random_i64x2();
    simde_uint64x2_t r = simde_vsqaddq_u64(a, b);

    simde_test_arm_neon_write_u64x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i64x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(vsqaddb_u8)
SIMDE_TEST_FUNC_LIST_ENTRY(vsqaddh_u16)
SIMDE_TEST_FUNC_LIST_ENTRY(vsqadds_u32)
SIMDE_TEST_FUNC_LIST_ENTRY(vsqaddd_u64)
SIMDE_TEST_FUNC_LIST_ENTRY(vsqadd_u8)
SIMDE_TEST_FUNC_LIST_ENTRY(vsqadd_u16)
SIMDE_TEST_FUNC_LIST_ENTRY(vsqadd_u32)
SIMDE_TEST_FUNC_LIST_ENTRY(vsqadd_u64)
SIMDE_TEST_FUNC_LIST_ENTRY(vsqaddq_u8)
SIMDE_TEST_FUNC_LIST_ENTRY(vsqaddq_u16)
SIMDE_TEST_FUNC_LIST_ENTRY(vsqaddq_u32)
SIMDE_TEST_FUNC_LIST_ENTRY(vsqaddq_u64)
SIMDE_TEST_FUNC_LIST_END

#include "test-neon-footer.h"
