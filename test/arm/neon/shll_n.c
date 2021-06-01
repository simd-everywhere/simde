#define SIMDE_TEST_ARM_NEON_INSN shll_n

#include "test-neon.h"
#include "../../../simde/arm/neon/shll_n.h"
#include "../../../simde/arm/neon/dup_n.h"

static int
test_simde_vshll_n_s8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int8_t a[8];
    int16_t r[8];
  } test_vec[] = {
    { { -INT8_C( 102), -INT8_C(   3), -INT8_C(  44), -INT8_C(  59),  INT8_C( 123), -INT8_C(  42),  INT8_C(  95),  INT8_C( 119) },
      { -INT16_C( 26112), -INT16_C(   768), -INT16_C( 11264), -INT16_C( 15104),  INT16_C( 31488), -INT16_C( 10752),  INT16_C( 24320),  INT16_C( 30464) } },
    { { -INT8_C(   3), -INT8_C(  91), -INT8_C( 106), -INT8_C(  74), -INT8_C( 120),  INT8_C( 116),  INT8_C(  82), -INT8_C(   3) },
      { -INT16_C(   768), -INT16_C( 23296), -INT16_C( 27136), -INT16_C( 18944), -INT16_C( 30720),  INT16_C( 29696),  INT16_C( 20992), -INT16_C(   768) } },
    { {  INT8_C(  56),  INT8_C(  30), -INT8_C( 125), -INT8_C( 120), -INT8_C(  59), -INT8_C(  21), -INT8_C(  78),  INT8_C(  66) },
      {  INT16_C( 14336),  INT16_C(  7680), -INT16_C( 32000), -INT16_C( 30720), -INT16_C( 15104), -INT16_C(  5376), -INT16_C( 19968),  INT16_C( 16896) } },
    { { -INT8_C(  17),  INT8_C(  75),  INT8_C(  23), -INT8_C( 114), -INT8_C(  72), -INT8_C( 106),  INT8_C(  54),  INT8_C(  82) },
      { -INT16_C(  4352),  INT16_C( 19200),  INT16_C(  5888), -INT16_C( 29184), -INT16_C( 18432), -INT16_C( 27136),  INT16_C( 13824),  INT16_C( 20992) } },
    { { -INT8_C( 109),  INT8_C(  11),  INT8_C(  24),  INT8_C(  15), -INT8_C(  31),  INT8_C( 119), -INT8_C( 122), -INT8_C(  34) },
      { -INT16_C( 27904),  INT16_C(  2816),  INT16_C(  6144),  INT16_C(  3840), -INT16_C(  7936),  INT16_C( 30464), -INT16_C( 31232), -INT16_C(  8704) } },
    { {  INT8_C(  28),  INT8_C(  28), -INT8_C( 108), -INT8_C(  92), -INT8_C( 111), -INT8_C(  25), -INT8_C(  95), -INT8_C(  55) },
      {  INT16_C(  7168),  INT16_C(  7168), -INT16_C( 27648), -INT16_C( 23552), -INT16_C( 28416), -INT16_C(  6400), -INT16_C( 24320), -INT16_C( 14080) } },
    { {  INT8_C(   5),  INT8_C(  36),  INT8_C(  81), -INT8_C(  53),  INT8_C(  15),  INT8_C(   3),  INT8_C(  13), -INT8_C(   1) },
      {  INT16_C(  1280),  INT16_C(  9216),  INT16_C( 20736), -INT16_C( 13568),  INT16_C(  3840),  INT16_C(   768),  INT16_C(  3328), -INT16_C(   256) } },
    { {  INT8_C(  78),  INT8_C(  36), -INT8_C( 115),  INT8_C(   7), -INT8_C(  69), -INT8_C(  61),  INT8_C(  89),  INT8_C(  78) },
      {  INT16_C( 19968),  INT16_C(  9216), -INT16_C( 29440),  INT16_C(  1792), -INT16_C( 17664), -INT16_C( 15616),  INT16_C( 22784),  INT16_C( 19968) } },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int8x8_t a = simde_vld1_s8(test_vec[i].a);
    simde_int16x8_t r = simde_vshll_n_s8(a, 8);

    simde_test_arm_neon_assert_equal_i16x8(r, simde_vld1q_s16(test_vec[i].r));
  }

  return 0;
#else
  for (int i = 0 ; i < 8 ; i++) {
    simde_int8x8_t a = simde_test_arm_neon_random_i8x8();
    simde_int16x8_t r = simde_vshll_n_s8(a, 8);

    simde_test_arm_neon_write_i8x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i16x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vshll_n_s16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int16_t a[4];
    int32_t r[4];
  } test_vec[] = {
    { {  INT16_C( 26400),  INT16_C( 19974), -INT16_C( 26444), -INT16_C(  5770) },
      {  INT32_C(  1730150400),  INT32_C(  1309016064), -INT32_C(  1733033984), -INT32_C(   378142720) } },
    { {  INT16_C(  5868),  INT16_C( 15028),  INT16_C( 21907),  INT16_C( 16957) },
      {  INT32_C(   384565248),  INT32_C(   984875008),  INT32_C(  1435697152),  INT32_C(  1111293952) } },
    { { -INT16_C( 25526), -INT16_C( 30142), -INT16_C( 28139), -INT16_C( 25746) },
      { -INT32_C(  1672871936), -INT32_C(  1975386112), -INT32_C(  1844117504), -INT32_C(  1687289856) } },
    { {  INT16_C( 11497), -INT16_C( 29908), -INT16_C( 25593),  INT16_C( 10101) },
      {  INT32_C(   753467392), -INT32_C(  1960050688), -INT32_C(  1677262848),  INT32_C(   661979136) } },
    { {  INT16_C( 31747), -INT16_C( 18571), -INT16_C(  5356),  INT16_C(   416) },
      {  INT32_C(  2080571392), -INT32_C(  1217069056), -INT32_C(   351010816),  INT32_C(    27262976) } },
    { {  INT16_C( 21506), -INT16_C( 27333),  INT16_C( 31146), -INT16_C(  2857) },
      {  INT32_C(  1409417216), -INT32_C(  1791295488),  INT32_C(  2041184256), -INT32_C(   187236352) } },
    { {  INT16_C(  6421),  INT16_C( 10878), -INT16_C(  4948), -INT16_C( 27195) },
      {  INT32_C(   420806656),  INT32_C(   712900608), -INT32_C(   324272128), -INT32_C(  1782251520) } },
    { { -INT16_C(  3816),  INT16_C(  7968), -INT16_C( 26995), -INT16_C( 28346) },
      { -INT32_C(   250085376),  INT32_C(   522190848), -INT32_C(  1769144320), -INT32_C(  1857683456) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x4_t a = simde_vld1_s16(test_vec[i].a);
    simde_int32x4_t r = simde_vshll_n_s16(a, 16);

    simde_test_arm_neon_assert_equal_i32x4(r, simde_vld1q_s32(test_vec[i].r));
  }

  return 0;
#else
  for (int i = 0 ; i < 8 ; i++) {
    simde_int16x4_t a = simde_test_arm_neon_random_i16x4();
    simde_int32x4_t r = simde_vshll_n_s16(a, 16);

    simde_test_arm_neon_write_i16x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vshll_n_s32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int32_t a[2];
    int64_t r[2];
  } test_vec[] = {
    { {  INT32_C(    91929669),  INT32_C(   603684158) },
      {  INT64_C(  394834921887105024),  INT64_C( 2592803715723296768) } },
    { { -INT32_C(   391088900),  INT32_C(   159890270) },
      { -INT64_C( 1679714035328614400),  INT64_C(  686723480598609920) } },
    { {  INT32_C(  1914631810), -INT32_C(    13836177) },
      {  INT64_C( 8223281007831285760), -INT64_C(   59425927716667392) } },
    { {  INT32_C(  1276098347), -INT32_C(  1896841655) },
      {  INT64_C( 5480800666844659712), -INT64_C( 8146872873915514880) } },
    { {  INT32_C(  2039704122), -INT32_C(   459501592) },
      {  INT64_C( 8760462497506394112), -INT64_C( 1973544310099935232) } },
    { {  INT32_C(  1640778755), -INT32_C(  1972743416) },
      {  INT64_C( 7047091092696596480), -INT64_C( 8472868455119323136) } },
    { { -INT32_C(  1174632374), -INT32_C(  1799870104) },
      { -INT64_C( 5045007631152840704), -INT64_C( 7730383233728118784) } },
    { {  INT32_C(   702597088), -INT32_C(  2135371450) },
      {  INT64_C( 3017631515224834048), -INT64_C( 9171350542562099200) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x2_t a = simde_vld1_s32(test_vec[i].a);
    simde_int64x2_t r = simde_vshll_n_s32(a, 32);

    simde_test_arm_neon_assert_equal_i64x2(r, simde_vld1q_s64(test_vec[i].r));
  }

  return 0;
#else
  for (int i = 0 ; i < 8 ; i++) {
    simde_int32x2_t a = simde_test_arm_neon_random_i32x2();
    simde_int64x2_t r = simde_vshll_n_s32(a, 32);

    simde_test_arm_neon_write_i32x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vshll_n_u8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint8_t a[8];
    uint16_t r[8];
  } test_vec[] = {
    { { UINT8_C( 90), UINT8_C(254), UINT8_C( 71), UINT8_C( 16), UINT8_C(114), UINT8_C( 40), UINT8_C(237), UINT8_C(166) },
      { UINT16_C(23040), UINT16_C(65024), UINT16_C(18176), UINT16_C( 4096), UINT16_C(29184), UINT16_C(10240), UINT16_C(60672), UINT16_C(42496) } },
    { { UINT8_C( 35), UINT8_C( 99), UINT8_C(202), UINT8_C(159), UINT8_C( 63), UINT8_C(225), UINT8_C(232), UINT8_C(174) },
      { UINT16_C( 8960), UINT16_C(25344), UINT16_C(51712), UINT16_C(40704), UINT16_C(16128), UINT16_C(57600), UINT16_C(59392), UINT16_C(44544) } },
    { { UINT8_C( 94), UINT8_C(102), UINT8_C(216), UINT8_C(217), UINT8_C(212), UINT8_C( 16), UINT8_C( 77), UINT8_C( 40) },
      { UINT16_C(24064), UINT16_C(26112), UINT16_C(55296), UINT16_C(55552), UINT16_C(54272), UINT16_C( 4096), UINT16_C(19712), UINT16_C(10240) } },
    { { UINT8_C(243), UINT8_C(223), UINT8_C( 20), UINT8_C(126), UINT8_C(222), UINT8_C( 64), UINT8_C( 78), UINT8_C( 56) },
      { UINT16_C(62208), UINT16_C(57088), UINT16_C( 5120), UINT16_C(32256), UINT16_C(56832), UINT16_C(16384), UINT16_C(19968), UINT16_C(14336) } },
    { { UINT8_C( 63), UINT8_C(150), UINT8_C( 72), UINT8_C(177), UINT8_C(190), UINT8_C( 54), UINT8_C( 88), UINT8_C(225) },
      { UINT16_C(16128), UINT16_C(38400), UINT16_C(18432), UINT16_C(45312), UINT16_C(48640), UINT16_C(13824), UINT16_C(22528), UINT16_C(57600) } },
    { { UINT8_C(153), UINT8_C( 34), UINT8_C(128), UINT8_C(216), UINT8_C(  3), UINT8_C(105), UINT8_C(134), UINT8_C( 97) },
      { UINT16_C(39168), UINT16_C( 8704), UINT16_C(32768), UINT16_C(55296), UINT16_C(  768), UINT16_C(26880), UINT16_C(34304), UINT16_C(24832) } },
    { { UINT8_C(207), UINT8_C( 94), UINT8_C( 58), UINT8_C(164), UINT8_C(110), UINT8_C(135), UINT8_C(204), UINT8_C( 98) },
      { UINT16_C(52992), UINT16_C(24064), UINT16_C(14848), UINT16_C(41984), UINT16_C(28160), UINT16_C(34560), UINT16_C(52224), UINT16_C(25088) } },
    { { UINT8_C(102), UINT8_C(224), UINT8_C(224), UINT8_C( 68), UINT8_C( 33), UINT8_C( 46), UINT8_C(125), UINT8_C( 96) },
      { UINT16_C(26112), UINT16_C(57344), UINT16_C(57344), UINT16_C(17408), UINT16_C( 8448), UINT16_C(11776), UINT16_C(32000), UINT16_C(24576) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint8x8_t a = simde_vld1_u8(test_vec[i].a);
    simde_uint16x8_t r = simde_vshll_n_u8(a, 8);

    simde_test_arm_neon_assert_equal_u16x8(r, simde_vld1q_u16(test_vec[i].r));
  }

  return 0;
#else
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint8x8_t a = simde_test_arm_neon_random_u8x8();
    simde_uint16x8_t r = simde_vshll_n_u8(a, 8);

    simde_test_arm_neon_write_u8x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u16x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vshll_n_u16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint16_t a[4];
    uint32_t r[4];
  } test_vec[] = {
    { { UINT16_C(44411), UINT16_C( 7109), UINT16_C( 2267), UINT16_C(48260) },
      { UINT32_C(2910519296), UINT32_C( 465895424), UINT32_C( 148570112), UINT32_C(3162767360) } },
    { { UINT16_C(32556), UINT16_C(22007), UINT16_C( 3250), UINT16_C(31046) },
      { UINT32_C(2133590016), UINT32_C(1442250752), UINT32_C( 212992000), UINT32_C(2034630656) } },
    { { UINT16_C( 7265), UINT16_C(14313), UINT16_C(52510), UINT16_C(  404) },
      { UINT32_C( 476119040), UINT32_C( 938016768), UINT32_C(3441295360), UINT32_C(  26476544) } },
    { { UINT16_C( 9784), UINT16_C(38916), UINT16_C(32318), UINT16_C(47592) },
      { UINT32_C( 641204224), UINT32_C(2550398976), UINT32_C(2117992448), UINT32_C(3118989312) } },
    { { UINT16_C(44331), UINT16_C( 1748), UINT16_C(22965), UINT16_C(58050) },
      { UINT32_C(2905276416), UINT32_C( 114556928), UINT32_C(1505034240), UINT32_C(3804364800) } },
    { { UINT16_C(47832), UINT16_C(35383), UINT16_C(32198), UINT16_C(10243) },
      { UINT32_C(3134717952), UINT32_C(2318860288), UINT32_C(2110128128), UINT32_C( 671285248) } },
    { { UINT16_C(60570), UINT16_C(47199), UINT16_C(62394), UINT16_C(62138) },
      { UINT32_C(3969515520), UINT32_C(3093233664), UINT32_C(4089053184), UINT32_C(4072275968) } },
    { { UINT16_C(48666), UINT16_C(22666), UINT16_C(29244), UINT16_C(26386) },
      { UINT32_C(3189374976), UINT32_C(1485438976), UINT32_C(1916534784), UINT32_C(1729232896) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint16x4_t a = simde_vld1_u16(test_vec[i].a);
    simde_uint32x4_t r = simde_vshll_n_u16(a, 16);

    simde_test_arm_neon_assert_equal_u32x4(r, simde_vld1q_u32(test_vec[i].r));
  }

  return 0;
#else
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint16x4_t a = simde_test_arm_neon_random_u16x4();
    simde_uint32x4_t r = simde_vshll_n_u16(a, 16);

    simde_test_arm_neon_write_u16x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vshll_n_u32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint32_t a[2];
    uint64_t r[2];
  } test_vec[] = {
    { { UINT32_C( 813396765), UINT32_C(1025231812) },
      { UINT64_C( 3493512504347197440), UINT64_C( 4403337103358820352) } },
    { { UINT32_C(2187497033), UINT32_C(3685685983) },
      { UINT64_C( 9395228216832032768), UINT64_C(15829900760310611968) } },
    { { UINT32_C(1335549523), UINT32_C(1175695617) },
      { UINT64_C( 5736141523473399808), UINT64_C( 5049574225065541632) } },
    { { UINT32_C(3539106351), UINT32_C( 227431152) },
      { UINT64_C(15200346034610896896), UINT64_C(  976809359931604992) } },
    { { UINT32_C(2302478789), UINT32_C( 516381140) },
      { UINT64_C( 9889071098488684544), UINT64_C( 2217840108571197440) } },
    { { UINT32_C(3332385255), UINT32_C(2527154243) },
      { UINT64_C(14312485687897620480), UINT64_C(10854044825632636928) } },
    { { UINT32_C( 803617582), UINT32_C( 477559276) },
      { UINT64_C( 3451511233180598272), UINT64_C( 2051101472321437696) } },
    { { UINT32_C(1676568691), UINT32_C(2138143930) },
      { UINT64_C( 7200807697342529536), UINT64_C( 9183258253490913280) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint32x2_t a = simde_vld1_u32(test_vec[i].a);
    simde_uint64x2_t r = simde_vshll_n_u32(a, 32);

    simde_test_arm_neon_assert_equal_u64x2(r, simde_vld1q_u64(test_vec[i].r));
  }

  return 0;
#else
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint32x2_t a = simde_test_arm_neon_random_u32x2();
    simde_uint64x2_t r = simde_vshll_n_u32(a, 32);

    simde_test_arm_neon_write_u32x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(vshll_n_s8)
SIMDE_TEST_FUNC_LIST_ENTRY(vshll_n_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vshll_n_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vshll_n_u8)
SIMDE_TEST_FUNC_LIST_ENTRY(vshll_n_u16)
SIMDE_TEST_FUNC_LIST_ENTRY(vshll_n_u32)
SIMDE_TEST_FUNC_LIST_END

#include "test-neon-footer.h"
