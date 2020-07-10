#define SIMDE_TEST_ARM_NEON_INSN movn

#include "test-neon.h"
#include "../../../simde/arm/neon/movn.h"

static int
test_simde_vmovn_s16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int16_t a[8];
    int8_t r[8];
  } test_vec[] = {
    { { -INT16_C(  9747),  INT16_C(  2915),  INT16_C( 12465), -INT16_C( 19440), -INT16_C( 27230),  INT16_C( 26615), -INT16_C( 10739), -INT16_C(  1162) },
      { -INT8_C(  19),  INT8_C(  99), -INT8_C(  79),  INT8_C(  16), -INT8_C(  94), -INT8_C(   9),  INT8_C(  13),  INT8_C( 118) } },
    { { -INT16_C(  4564),  INT16_C( 11796),  INT16_C(   560), -INT16_C(  5089), -INT16_C(  4592), -INT16_C( 22646),  INT16_C(  6419),  INT16_C(   136) },
      {  INT8_C(  44),  INT8_C(  20),  INT8_C(  48),  INT8_C(  31),  INT8_C(  16), -INT8_C( 118),  INT8_C(  19), -INT8_C( 120) } },
    { { -INT16_C(  5134), -INT16_C( 23541),  INT16_C(  7196), -INT16_C( 16808),  INT16_C( 20657), -INT16_C( 16602), -INT16_C( 25562),  INT16_C( 21178) },
      { -INT8_C(  14),  INT8_C(  11),  INT8_C(  28),  INT8_C(  88), -INT8_C(  79),  INT8_C(  38),  INT8_C(  38), -INT8_C(  70) } },
    { { -INT16_C( 12661), -INT16_C( 17536), -INT16_C( 24623), -INT16_C(  7769),  INT16_C( 12941), -INT16_C( 24440),  INT16_C(  4171),  INT16_C( 16032) },
      { -INT8_C( 117),      INT8_MIN, -INT8_C(  47), -INT8_C(  89), -INT8_C( 115), -INT8_C( 120),  INT8_C(  75), -INT8_C(  96) } },
    { { -INT16_C( 21253),  INT16_C(  6114),  INT16_C( 15048),  INT16_C( 31190), -INT16_C(   886), -INT16_C( 20424), -INT16_C(  3432),  INT16_C(  8962) },
      { -INT8_C(   5), -INT8_C(  30), -INT8_C(  56), -INT8_C(  42), -INT8_C( 118),  INT8_C(  56), -INT8_C( 104),  INT8_C(   2) } },
    { { -INT16_C( 31807), -INT16_C( 27937), -INT16_C( 31198), -INT16_C( 20365), -INT16_C(  1096),  INT16_C(  1104), -INT16_C(  3829),  INT16_C(  1602) },
      { -INT8_C(  63), -INT8_C(  33),  INT8_C(  34),  INT8_C( 115), -INT8_C(  72),  INT8_C(  80),  INT8_C(  11),  INT8_C(  66) } },
    { {  INT16_C(  9373),  INT16_C( 25886), -INT16_C(  2978), -INT16_C(  5666),  INT16_C(  6128), -INT16_C( 30567), -INT16_C( 25591), -INT16_C( 13652) },
      { -INT8_C(  99),  INT8_C(  30),  INT8_C(  94), -INT8_C(  34), -INT8_C(  16), -INT8_C( 103),  INT8_C(   9), -INT8_C(  84) } },
    { { -INT16_C( 29921),  INT16_C( 16732), -INT16_C( 12527), -INT16_C( 13583),  INT16_C( 17098), -INT16_C( 10802),  INT16_C(  4147), -INT16_C( 12068) },
      {  INT8_C(  31),  INT8_C(  92),  INT8_C(  17), -INT8_C(  15), -INT8_C(  54), -INT8_C(  50),  INT8_C(  51), -INT8_C(  36) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x8_t a = simde_vld1q_s16(test_vec[i].a);
    simde_int8x8_t r = simde_vmovn_s16(a);

    simde_test_arm_neon_assert_equal_i8x8(r, simde_vld1_s8(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int16x8_t a = simde_test_arm_neon_random_i16x8();
    simde_int8x8_t r = simde_vmovn_s16(a);

    simde_test_arm_neon_write_i16x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i8x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vmovn_s32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int32_t a[4];
    int16_t r[4];
  } test_vec[] = {
    { { -INT32_C(   881259170),  INT32_C(   492400936), -INT32_C(   382033531), -INT32_C(  1489116661) },
      {  INT16_C(  3422),  INT16_C( 28968), -INT16_C( 24187), -INT16_C(  7669) } },
    { {  INT32_C(  1727619065),  INT32_C(  1734264326),  INT32_C(   485245415),  INT32_C(   444708540) },
      {  INT16_C( 24569), -INT16_C( 14842),  INT16_C( 16871), -INT16_C( 18756) } },
    { { -INT32_C(   320406844), -INT32_C(   251052181), -INT32_C(   338017312),  INT32_C(   529733414) },
      { -INT16_C(  1340),  INT16_C( 16235),  INT16_C( 17376),  INT16_C(  5926) } },
    { {  INT32_C(  2089192566),  INT32_C(   971236434), -INT32_C(   514404571),  INT32_C(  1258084230) },
      { -INT16_C( 29578), -INT16_C(  7086), -INT16_C( 12507), -INT16_C( 10362) } },
    { {  INT32_C(  1027007186),  INT32_C(    36585249), -INT32_C(  1460860798), -INT32_C(  1782022113) },
      { -INT16_C(  7470),  INT16_C( 16161),  INT16_C(  2178), -INT16_C( 32737) } },
    { {  INT32_C(  1594969612),  INT32_C(  1486418994),  INT32_C(  1245310660), -INT32_C(  1735117370) },
      {  INT16_C( 19980), -INT16_C(  3022), -INT16_C(  4412),  INT16_C( 13766) } },
    { {  INT32_C(   970312215), -INT32_C(  1959066615),  INT32_C(   741615628), -INT32_C(  1245578071) },
      { -INT16_C( 13801),  INT16_C(  1033),  INT16_C( 10252), -INT16_C(   855) } },
    { {  INT32_C(  2081739594), -INT32_C(  1948996153),  INT32_C(  1641352859),  INT32_C(  1543072067) },
      { -INT16_C( 11446), -INT16_C( 21049),  INT16_C(  3739),  INT16_C( 26947) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x4_t a = simde_vld1q_s32(test_vec[i].a);
    simde_int16x4_t r = simde_vmovn_s32(a);

    simde_test_arm_neon_assert_equal_i16x4(r, simde_vld1_s16(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int32x4_t a = simde_test_arm_neon_random_i32x4();
    simde_int16x4_t r = simde_vmovn_s32(a);

    simde_test_arm_neon_write_i32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i16x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vmovn_s64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int64_t a[2];
    int32_t r[2];
  } test_vec[] = {
    { {  INT64_C( 8720536517257111466), -INT64_C( 4813755463156168939) },
      {  INT32_C(  1374594986),  INT32_C(   519767829) } },
    { { -INT64_C( 6024405302477077041),  INT64_C( 1994957680940228729) },
      { -INT32_C(   891304497), -INT32_C(   362733447) } },
    { {  INT64_C( 4856693694531411243),  INT64_C( 5413208539070095737) },
      { -INT32_C(   311648981),  INT32_C(  1650614649) } },
    { {  INT64_C( 8813679717742214745),  INT64_C( 6928247294813123227) },
      { -INT32_C(  1541996967),  INT32_C(   191214235) } },
    { {  INT64_C( 9016967336968491697),  INT64_C( 8277051071673631766) },
      { -INT32_C(   548498767), -INT32_C(  1830845418) } },
    { {  INT64_C(  682127594960122876), -INT64_C( 6796147409390543847) },
      { -INT32_C(    48827396),  INT32_C(  1310055449) } },
    { { -INT64_C( 4084866352865542706),  INT64_C( 2932466970569289255) },
      { -INT32_C(   763298354),  INT32_C(  1079586343) } },
    { {  INT64_C( 5233917445204723754), -INT64_C( 4536454188383094919) },
      { -INT32_C(  1725577174),  INT32_C(  1771550585) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int64x2_t a = simde_vld1q_s64(test_vec[i].a);
    simde_int32x2_t r = simde_vmovn_s64(a);

    simde_test_arm_neon_assert_equal_i32x2(r, simde_vld1_s32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int64x2_t a = simde_test_arm_neon_random_i64x2();
    simde_int32x2_t r = simde_vmovn_s64(a);

    simde_test_arm_neon_write_i64x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i32x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vmovn_u16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint16_t a[8];
    uint8_t r[8];
  } test_vec[] = {
    { { UINT16_C( 8289), UINT16_C(49720), UINT16_C(65062), UINT16_C(62879), UINT16_C(25787), UINT16_C( 7725), UINT16_C(13523), UINT16_C(54160) },
      { UINT8_C( 97), UINT8_C( 56), UINT8_C( 38), UINT8_C(159), UINT8_C(187), UINT8_C( 45), UINT8_C(211), UINT8_C(144) } },
    { { UINT16_C( 5140), UINT16_C(59810), UINT16_C(19299), UINT16_C( 5030), UINT16_C(17392), UINT16_C(20341), UINT16_C(61775), UINT16_C(45550) },
      { UINT8_C( 20), UINT8_C(162), UINT8_C( 99), UINT8_C(166), UINT8_C(240), UINT8_C(117), UINT8_C( 79), UINT8_C(238) } },
    { { UINT16_C( 9745), UINT16_C(14195), UINT16_C( 4644), UINT16_C(57388), UINT16_C(22902), UINT16_C(18942), UINT16_C(36494), UINT16_C(41501) },
      { UINT8_C( 17), UINT8_C(115), UINT8_C( 36), UINT8_C( 44), UINT8_C(118), UINT8_C(254), UINT8_C(142), UINT8_C( 29) } },
    { { UINT16_C(49058), UINT16_C( 1419), UINT16_C(12554), UINT16_C(64025), UINT16_C(36469), UINT16_C(50249), UINT16_C(14207), UINT16_C(36981) },
      { UINT8_C(162), UINT8_C(139), UINT8_C( 10), UINT8_C( 25), UINT8_C(117), UINT8_C( 73), UINT8_C(127), UINT8_C(117) } },
    { { UINT16_C(59741), UINT16_C(33480), UINT16_C(62715), UINT16_C(29282), UINT16_C(24654), UINT16_C(56507), UINT16_C(55534), UINT16_C(36990) },
      { UINT8_C( 93), UINT8_C(200), UINT8_C(251), UINT8_C( 98), UINT8_C( 78), UINT8_C(187), UINT8_C(238), UINT8_C(126) } },
    { { UINT16_C( 2711), UINT16_C(41365), UINT16_C(44603), UINT16_C(45211), UINT16_C(58684), UINT16_C(47989), UINT16_C(59932), UINT16_C(31308) },
      { UINT8_C(151), UINT8_C(149), UINT8_C( 59), UINT8_C(155), UINT8_C( 60), UINT8_C(117), UINT8_C( 28), UINT8_C( 76) } },
    { { UINT16_C( 5331), UINT16_C(53244), UINT16_C(24072), UINT16_C(22081), UINT16_C(64702), UINT16_C(44082), UINT16_C(45525), UINT16_C(27708) },
      { UINT8_C(211), UINT8_C(252), UINT8_C(  8), UINT8_C( 65), UINT8_C(190), UINT8_C( 50), UINT8_C(213), UINT8_C( 60) } },
    { { UINT16_C(53691), UINT16_C(62990), UINT16_C(43392), UINT16_C(48295), UINT16_C( 7310), UINT16_C(43896), UINT16_C(50182), UINT16_C(55845) },
      { UINT8_C(187), UINT8_C( 14), UINT8_C(128), UINT8_C(167), UINT8_C(142), UINT8_C(120), UINT8_C(  6), UINT8_C( 37) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint16x8_t a = simde_vld1q_u16(test_vec[i].a);
    simde_uint8x8_t r = simde_vmovn_u16(a);
    simde_test_arm_neon_assert_equal_u8x8(r, simde_vld1_u8(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint16x8_t a = simde_test_arm_neon_random_u16x8();
    simde_uint8x8_t r = simde_vmovn_u16(a);

    simde_test_arm_neon_write_u16x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u8x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vmovn_u32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint32_t a[4];
    uint16_t r[4];
  } test_vec[] = {
    { { UINT32_C( 659436180), UINT32_C(2964530838), UINT32_C(1315824826), UINT32_C(1173187531) },
      { UINT16_C(12948), UINT16_C( 9878), UINT16_C(58554), UINT16_C(27595) } },
    { { UINT32_C(2193938838), UINT32_C(1661786804), UINT32_C(2666353876), UINT32_C(3589341761) },
      { UINT16_C(55702), UINT16_C(55988), UINT16_C(21716), UINT16_C(  577) } },
    { { UINT32_C(3405528884), UINT32_C( 528199525), UINT32_C(1584261267), UINT32_C(3936574036) },
      { UINT16_C(16180), UINT16_C(44901), UINT16_C(59539), UINT16_C(23124) } },
    { { UINT32_C(3899484211), UINT32_C( 390822210), UINT32_C( 246757837), UINT32_C(1893967419) },
      { UINT16_C(26675), UINT16_C(31042), UINT16_C(14797), UINT16_C(42555) } },
    { { UINT32_C(1262149862), UINT32_C( 594261391), UINT32_C(4068595870), UINT32_C(1725703475) },
      { UINT16_C(57574), UINT16_C(46479), UINT16_C(55454), UINT16_C( 9523) } },
    { { UINT32_C(3478014349), UINT32_C(2431032003), UINT32_C( 245341395), UINT32_C( 679379522) },
      { UINT16_C(18829), UINT16_C(39619), UINT16_C(40147), UINT16_C(33346) } },
    { { UINT32_C(4067735906), UINT32_C( 202760046), UINT32_C(3942553271), UINT32_C(1213324219) },
      { UINT16_C(47458), UINT16_C(57198), UINT16_C(38583), UINT16_C(56251) } },
    { { UINT32_C(3877150500), UINT32_C( 209255993), UINT32_C(3709540250), UINT32_C(4228225433) },
      { UINT16_C(40740), UINT16_C(65081), UINT16_C( 6042), UINT16_C(39321) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint32x4_t a = simde_vld1q_u32(test_vec[i].a);
    simde_uint16x4_t r = simde_vmovn_u32(a);
    simde_test_arm_neon_assert_equal_u16x4(r, simde_vld1_u16(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint32x4_t a = simde_test_arm_neon_random_u32x4();
    simde_uint16x4_t r = simde_vmovn_u32(a);

    simde_test_arm_neon_write_u32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u16x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vmovn_u64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint64_t a[2];
    uint32_t r[2];
  } test_vec[] = {
    { { UINT64_C( 9187982830363858881), UINT64_C( 5472703971259775409) },
      { UINT32_C(1178195905), UINT32_C( 667875761) } },
    { { UINT64_C(15094741277317888312), UINT64_C( 3672368221012049671) },
      { UINT32_C(1660254520), UINT32_C(2715500295) } },
    { { UINT64_C( 2804048724730851254), UINT64_C(16394299647680493812) },
      { UINT32_C(1786261430), UINT32_C( 961460468) } },
    { { UINT64_C(14754285810614631097), UINT64_C( 3648589129453575423) },
      { UINT32_C(4031085241), UINT32_C(1886297343) } },
    { { UINT64_C(  733952689181563539), UINT64_C( 8632775679215369534) },
      { UINT32_C( 144448147), UINT32_C(3913514302) } },
    { { UINT64_C(15191531954389848641), UINT64_C( 4139903880899215813) },
      { UINT32_C( 124195393), UINT32_C(1094861253) } },
    { { UINT64_C(15212720376896360447), UINT64_C( 7647827028808131053) },
      { UINT32_C( 339808255), UINT32_C(2881315309) } },
    { { UINT64_C( 8665565265690462620), UINT64_C( 7522467582825825414) },
      { UINT32_C(1869711772), UINT32_C( 750355590) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint64x2_t a = simde_vld1q_u64(test_vec[i].a);
    simde_uint32x2_t r = simde_vmovn_u64(a);
    simde_test_arm_neon_assert_equal_u32x2(r, simde_vld1_u32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint64x2_t a = simde_test_arm_neon_random_u64x2();
    simde_uint32x2_t r = simde_vmovn_u64(a);

    simde_test_arm_neon_write_u64x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u32x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(vmovn_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vmovn_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vmovn_s64)
SIMDE_TEST_FUNC_LIST_ENTRY(vmovn_u16)
SIMDE_TEST_FUNC_LIST_ENTRY(vmovn_u32)
SIMDE_TEST_FUNC_LIST_ENTRY(vmovn_u64)
SIMDE_TEST_FUNC_LIST_END

#include "test-neon-footer.h"
