#define SIMDE_TEST_ARM_NEON_INSN movl

#include "test-neon.h"
#include <simde/arm/neon/movl.h>

static int
test_simde_vmovl_s8 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    int8_t a[8];
    int16_t r[8];
  } test_vec[] = {
    { {  INT8_C(  31),  INT8_C(  71),  INT8_C(  44),  INT8_C(  91), -INT8_C(  52),  INT8_C(   8),  INT8_C(  55), -INT8_C(  52) },
      {  INT16_C(    31),  INT16_C(    71),  INT16_C(    44),  INT16_C(    91), -INT16_C(    52),  INT16_C(     8),  INT16_C(    55), -INT16_C(    52) } },
    { {  INT8_C(  65), -INT8_C(  81), -INT8_C(  57),  INT8_C(  44),  INT8_C(  26), -INT8_C(  47),  INT8_C(  67), -INT8_C( 127) },
      {  INT16_C(    65), -INT16_C(    81), -INT16_C(    57),  INT16_C(    44),  INT16_C(    26), -INT16_C(    47),  INT16_C(    67), -INT16_C(   127) } },
    { {  INT8_C(  98),  INT8_C( 108),  INT8_C(  40),  INT8_C(  95), -INT8_C( 117), -INT8_C(  15),  INT8_C( 121),  INT8_C(  41) },
      {  INT16_C(    98),  INT16_C(   108),  INT16_C(    40),  INT16_C(    95), -INT16_C(   117), -INT16_C(    15),  INT16_C(   121),  INT16_C(    41) } },
    { { -INT8_C(  21), -INT8_C(  77), -INT8_C(  55), -INT8_C(  69),  INT8_C( 110),  INT8_C( 126),  INT8_C(  54), -INT8_C( 115) },
      { -INT16_C(    21), -INT16_C(    77), -INT16_C(    55), -INT16_C(    69),  INT16_C(   110),  INT16_C(   126),  INT16_C(    54), -INT16_C(   115) } },
    { { -INT8_C(  59),  INT8_C(  98), -INT8_C(  24), -INT8_C( 110),  INT8_C( 106),  INT8_C(  31),  INT8_C(  94), -INT8_C(  85) },
      { -INT16_C(    59),  INT16_C(    98), -INT16_C(    24), -INT16_C(   110),  INT16_C(   106),  INT16_C(    31),  INT16_C(    94), -INT16_C(    85) } },
    { { -INT8_C(  49),  INT8_C(  38), -INT8_C(  40), -INT8_C(  23), -INT8_C(   9),  INT8_C(  27),  INT8_C( 107),  INT8_C(  90) },
      { -INT16_C(    49),  INT16_C(    38), -INT16_C(    40), -INT16_C(    23), -INT16_C(     9),  INT16_C(    27),  INT16_C(   107),  INT16_C(    90) } },
    { { -INT8_C( 121), -INT8_C( 109), -INT8_C(  71),  INT8_C(  19), -INT8_C( 124),  INT8_C(  50),  INT8_C(  60),  INT8_C( 112) },
      { -INT16_C(   121), -INT16_C(   109), -INT16_C(    71),  INT16_C(    19), -INT16_C(   124),  INT16_C(    50),  INT16_C(    60),  INT16_C(   112) } },
    { { -INT8_C(  27),  INT8_C(   5),  INT8_C(  43),  INT8_C(  83), -INT8_C( 125),  INT8_C(  98), -INT8_C(  32),  INT8_C(  72) },
      { -INT16_C(    27),  INT16_C(     5),  INT16_C(    43),  INT16_C(    83), -INT16_C(   125),  INT16_C(    98), -INT16_C(    32),  INT16_C(    72) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int8x8_t a = simde_vld1_s8(test_vec[i].a);
    simde_int16x8_t r = simde_vmovl_s8(a);

    simde_test_arm_neon_assert_equal_i16x8(r, simde_vld1q_s16(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vmovl_s16 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    int16_t a[4];
    int32_t r[4];
  } test_vec[] = {
    { {  INT16_C(  6049),  INT16_C(  7552),  INT16_C(  6479),  INT16_C( 19559) },
      {  INT32_C(        6049),  INT32_C(        7552),  INT32_C(        6479),  INT32_C(       19559) } },
    { {  INT16_C( 29363), -INT16_C(  9131), -INT16_C(   587), -INT16_C(  3980) },
      {  INT32_C(       29363), -INT32_C(        9131), -INT32_C(         587), -INT32_C(        3980) } },
    { {  INT16_C(   709), -INT16_C( 16398),  INT16_C(  8777), -INT16_C(  5159) },
      {  INT32_C(         709), -INT32_C(       16398),  INT32_C(        8777), -INT32_C(        5159) } },
    { { -INT16_C(  2426), -INT16_C(  1197),  INT16_C( 12053), -INT16_C( 18840) },
      { -INT32_C(        2426), -INT32_C(        1197),  INT32_C(       12053), -INT32_C(       18840) } },
    { { -INT16_C(  6074), -INT16_C( 27181),  INT16_C( 14849), -INT16_C( 19231) },
      { -INT32_C(        6074), -INT32_C(       27181),  INT32_C(       14849), -INT32_C(       19231) } },
    { {  INT16_C( 13997),  INT16_C( 25232),  INT16_C(  1075), -INT16_C(  1966) },
      {  INT32_C(       13997),  INT32_C(       25232),  INT32_C(        1075), -INT32_C(        1966) } },
    { {  INT16_C( 17415),  INT16_C( 20663), -INT16_C( 28570), -INT16_C(  5060) },
      {  INT32_C(       17415),  INT32_C(       20663), -INT32_C(       28570), -INT32_C(        5060) } },
    { { -INT16_C( 28794), -INT16_C( 25369),  INT16_C( 20414),  INT16_C(  1106) },
      { -INT32_C(       28794), -INT32_C(       25369),  INT32_C(       20414),  INT32_C(        1106) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x4_t a = simde_vld1_s16(test_vec[i].a);
    simde_int32x4_t r = simde_vmovl_s16(a);

    simde_test_arm_neon_assert_equal_i32x4(r, simde_vld1q_s32(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vmovl_s32 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    int32_t a[2];
    int64_t r[2];
  } test_vec[] = {
    { { -INT32_C(  1337807957),  INT32_C(    63141997) },
      { -INT64_C(          1337807957),  INT64_C(            63141997) } },
    { { -INT32_C(   455737023), -INT32_C(  1346288334) },
      { -INT64_C(           455737023), -INT64_C(          1346288334) } },
    { { -INT32_C(  1909724594), -INT32_C(   253267815) },
      { -INT64_C(          1909724594), -INT64_C(           253267815) } },
    { { -INT32_C(  1154621214), -INT32_C(   662767571) },
      { -INT64_C(          1154621214), -INT64_C(           662767571) } },
    { {  INT32_C(   294174883),  INT32_C(  2048150585) },
      {  INT64_C(           294174883),  INT64_C(          2048150585) } },
    { {  INT32_C(  2136992333),  INT32_C(  2116952112) },
      {  INT64_C(          2136992333),  INT64_C(          2116952112) } },
    { { -INT32_C(  1559471862), -INT32_C(  1416301623) },
      { -INT64_C(          1559471862), -INT64_C(          1416301623) } },
    { {  INT32_C(    23577043),  INT32_C(  1574561209) },
      {  INT64_C(            23577043),  INT64_C(          1574561209) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x2_t a = simde_vld1_s32(test_vec[i].a);
    simde_int64x2_t r = simde_vmovl_s32(a);

    simde_test_arm_neon_assert_equal_i64x2(r, simde_vld1q_s64(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vmovl_u8 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    uint8_t a[8];
    uint16_t r[8];
  } test_vec[] = {
    { { UINT8_C(189), UINT8_C(244), UINT8_C(174), UINT8_C( 32), UINT8_C( 26), UINT8_C(250), UINT8_C(  0), UINT8_C(155) },
      { UINT16_C(  189), UINT16_C(  244), UINT16_C(  174), UINT16_C(   32), UINT16_C(   26), UINT16_C(  250), UINT16_C(    0), UINT16_C(  155) } },
    { { UINT8_C( 40), UINT8_C(141), UINT8_C( 72), UINT8_C(225), UINT8_C(243), UINT8_C( 40), UINT8_C( 73), UINT8_C(157) },
      { UINT16_C(   40), UINT16_C(  141), UINT16_C(   72), UINT16_C(  225), UINT16_C(  243), UINT16_C(   40), UINT16_C(   73), UINT16_C(  157) } },
    { { UINT8_C(119), UINT8_C(113), UINT8_C(175), UINT8_C(165), UINT8_C(177), UINT8_C(181), UINT8_C(183), UINT8_C(236) },
      { UINT16_C(  119), UINT16_C(  113), UINT16_C(  175), UINT16_C(  165), UINT16_C(  177), UINT16_C(  181), UINT16_C(  183), UINT16_C(  236) } },
    { { UINT8_C(  8), UINT8_C( 38), UINT8_C( 77), UINT8_C(212), UINT8_C( 67), UINT8_C(220), UINT8_C(111), UINT8_C(  0) },
      { UINT16_C(    8), UINT16_C(   38), UINT16_C(   77), UINT16_C(  212), UINT16_C(   67), UINT16_C(  220), UINT16_C(  111), UINT16_C(    0) } },
    { { UINT8_C(208), UINT8_C( 29), UINT8_C( 32), UINT8_C(234), UINT8_C( 23), UINT8_C( 33), UINT8_C(133), UINT8_C( 63) },
      { UINT16_C(  208), UINT16_C(   29), UINT16_C(   32), UINT16_C(  234), UINT16_C(   23), UINT16_C(   33), UINT16_C(  133), UINT16_C(   63) } },
    { { UINT8_C(174), UINT8_C(206), UINT8_C( 32), UINT8_C(161), UINT8_C(246), UINT8_C(106), UINT8_C( 62), UINT8_C(109) },
      { UINT16_C(  174), UINT16_C(  206), UINT16_C(   32), UINT16_C(  161), UINT16_C(  246), UINT16_C(  106), UINT16_C(   62), UINT16_C(  109) } },
    { { UINT8_C(219), UINT8_C(237), UINT8_C( 18), UINT8_C(141), UINT8_C(162), UINT8_C(201), UINT8_C(121), UINT8_C(170) },
      { UINT16_C(  219), UINT16_C(  237), UINT16_C(   18), UINT16_C(  141), UINT16_C(  162), UINT16_C(  201), UINT16_C(  121), UINT16_C(  170) } },
    { { UINT8_C(240), UINT8_C(198), UINT8_C(126), UINT8_C( 51), UINT8_C(162), UINT8_C(238), UINT8_C( 51), UINT8_C(114) },
      { UINT16_C(  240), UINT16_C(  198), UINT16_C(  126), UINT16_C(   51), UINT16_C(  162), UINT16_C(  238), UINT16_C(   51), UINT16_C(  114) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint8x8_t a = simde_vld1_u8(test_vec[i].a);
    simde_uint16x8_t r = simde_vmovl_u8(a);

    simde_test_arm_neon_assert_equal_u16x8(r, simde_vld1q_u16(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vmovl_u16 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    uint16_t a[4];
    uint32_t r[4];
  } test_vec[] = {
    { { UINT16_C(33781), UINT16_C(23125), UINT16_C(60863), UINT16_C(50162) },
      { UINT32_C(     33781), UINT32_C(     23125), UINT32_C(     60863), UINT32_C(     50162) } },
    { { UINT16_C(50430), UINT16_C(23639), UINT16_C(48165), UINT16_C(43126) },
      { UINT32_C(     50430), UINT32_C(     23639), UINT32_C(     48165), UINT32_C(     43126) } },
    { { UINT16_C(33936), UINT16_C(59873), UINT16_C(56243), UINT16_C(57822) },
      { UINT32_C(     33936), UINT32_C(     59873), UINT32_C(     56243), UINT32_C(     57822) } },
    { { UINT16_C( 1496), UINT16_C(57739), UINT16_C(11575), UINT16_C(11738) },
      { UINT32_C(      1496), UINT32_C(     57739), UINT32_C(     11575), UINT32_C(     11738) } },
    { { UINT16_C(12208), UINT16_C(28807), UINT16_C(31004), UINT16_C( 6707) },
      { UINT32_C(     12208), UINT32_C(     28807), UINT32_C(     31004), UINT32_C(      6707) } },
    { { UINT16_C(35389), UINT16_C(25463), UINT16_C(60742), UINT16_C(54795) },
      { UINT32_C(     35389), UINT32_C(     25463), UINT32_C(     60742), UINT32_C(     54795) } },
    { { UINT16_C(60529), UINT16_C( 9407), UINT16_C(40392), UINT16_C(40965) },
      { UINT32_C(     60529), UINT32_C(      9407), UINT32_C(     40392), UINT32_C(     40965) } },
    { { UINT16_C(37027), UINT16_C(55937), UINT16_C(23486), UINT16_C(28167) },
      { UINT32_C(     37027), UINT32_C(     55937), UINT32_C(     23486), UINT32_C(     28167) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint16x4_t a = simde_vld1_u16(test_vec[i].a);
    simde_uint32x4_t r = simde_vmovl_u16(a);

    simde_test_arm_neon_assert_equal_u32x4(r, simde_vld1q_u32(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vmovl_u32 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    uint32_t a[2];
    uint64_t r[2];
  } test_vec[] = {
    { { UINT32_C(1405182796), UINT32_C(3853144912) },
      { UINT64_C(          1405182796), UINT64_C(          3853144912) } },
    { { UINT32_C( 231259192), UINT32_C(1147577182) },
      { UINT64_C(           231259192), UINT64_C(          1147577182) } },
    { { UINT32_C(1620251097), UINT32_C(3067746191) },
      { UINT64_C(          1620251097), UINT64_C(          3067746191) } },
    { { UINT32_C(3303260614), UINT32_C( 925867243) },
      { UINT64_C(          3303260614), UINT64_C(           925867243) } },
    { { UINT32_C(1351282944), UINT32_C(2100639044) },
      { UINT64_C(          1351282944), UINT64_C(          2100639044) } },
    { { UINT32_C(1351286257), UINT32_C(2056581281) },
      { UINT64_C(          1351286257), UINT64_C(          2056581281) } },
    { { UINT32_C(2447058946), UINT32_C( 105428287) },
      { UINT64_C(          2447058946), UINT64_C(           105428287) } },
    { { UINT32_C(1657416566), UINT32_C(3348756935) },
      { UINT64_C(          1657416566), UINT64_C(          3348756935) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint32x2_t a = simde_vld1_u32(test_vec[i].a);
    simde_uint64x2_t r = simde_vmovl_u32(a);

    simde_test_arm_neon_assert_equal_u64x2(r, simde_vld1q_u64(test_vec[i].r));
  }

  return 0;
}

SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(vmovl_s8)
SIMDE_TEST_FUNC_LIST_ENTRY(vmovl_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vmovl_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vmovl_u8)
SIMDE_TEST_FUNC_LIST_ENTRY(vmovl_u16)
SIMDE_TEST_FUNC_LIST_ENTRY(vmovl_u32)

SIMDE_TEST_FUNC_LIST_END

#include "test-neon-footer.h"
