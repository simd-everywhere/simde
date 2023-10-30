#define SIMDE_TEST_ARM_NEON_INSN usdot

#include "test-neon.h"
#include "../../../simde/arm/neon/usdot.h"


static int
test_simde_vusdot_s32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int32_t a[2];
    uint8_t b[8];
    int8_t c[8];
    int32_t r[2];
  } test_vec[] = {
    { { -INT32_C(  1879677382), -INT32_C(   594386451) },
      {  UINT8_C(   214),  UINT8_C(   148),  UINT8_C(    96),  UINT8_C(   232),
         UINT8_C(    98),  UINT8_C(   149),  UINT8_C(   131),  UINT8_C(    34) },
      {  INT8_C(    60), -INT8_C(   120), -INT8_C(    34), -INT8_C(    78),
         INT8_C(    42), -INT8_C(    18), -INT8_C(    56), -INT8_C(    40) },
      { -INT32_C(  1879703662), -INT32_C(   594393713) } },
    { { -INT32_C(  1185567567), -INT32_C(  1520797139) },
      {  UINT8_C(   160),  UINT8_C(   120),  UINT8_C(   201),  UINT8_C(     0),
         UINT8_C(   240),  UINT8_C(   158),  UINT8_C(   240),  UINT8_C(   187) },
      {  INT8_C(    64),  INT8_C(    93), -INT8_C(    58), -INT8_C(    77),
         INT8_C(   111), -INT8_C(    75), -INT8_C(   126), -INT8_C(   112) },
      { -INT32_C(  1185557825), -INT32_C(  1520833533) } },
    { { -INT32_C(  1740844034), -INT32_C(  1215282822) },
      {  UINT8_C(     5),  UINT8_C(   239),  UINT8_C(     7),  UINT8_C(   214),
         UINT8_C(   121),  UINT8_C(   105),  UINT8_C(    84),  UINT8_C(   221) },
      { -INT8_C(   128), -INT8_C(    95),  INT8_C(    13), -INT8_C(    31),
         INT8_C(   124), -INT8_C(    39), -INT8_C(   117), -INT8_C(    85) },
      { -INT32_C(  1740873922), -INT32_C(  1215300526) } },
    { { -INT32_C(   637381383),  INT32_C(  2022785690) },
      {  UINT8_C(    88),  UINT8_C(   124),  UINT8_C(   128),  UINT8_C(   163),
         UINT8_C(   107),  UINT8_C(    66),  UINT8_C(    63),  UINT8_C(   100) },
      {  INT8_C(   114),  INT8_C(    83),  INT8_C(    54),  INT8_C(    74),
        -INT8_C(    39), -INT8_C(     4),  INT8_C(   104), -INT8_C(    93) },
      { -INT32_C(   637342085),  INT32_C(  2022778505) } },
    { { -INT32_C(   736850156),  INT32_C(  1674449836) },
      {  UINT8_C(    88),  UINT8_C(    13),  UINT8_C(   161),  UINT8_C(   236),
         UINT8_C(    44),  UINT8_C(   251),  UINT8_C(    54),  UINT8_C(   169) },
      { -INT8_C(    10), -INT8_C(   103),  INT8_C(    30), -INT8_C(   107),
        -INT8_C(   102), -INT8_C(    51),  INT8_C(   122), -INT8_C(   105) },
      { -INT32_C(   736872797),  INT32_C(  1674421390) } },
    { {  INT32_C(   178016619),  INT32_C(  2035784344) },
      {  UINT8_C(   141),  UINT8_C(   224),  UINT8_C(    23),  UINT8_C(   238),
         UINT8_C(   195),  UINT8_C(    87),  UINT8_C(     4),  UINT8_C(    98) },
      {  INT8_C(    30),  INT8_C(    35), -INT8_C(    37),  INT8_C(   100),
        -INT8_C(    87), -INT8_C(     5),  INT8_C(    46),  INT8_C(    28) },
      {  INT32_C(   178051638),  INT32_C(  2035769872) } },
    { { -INT32_C(  1544102905),  INT32_C(  1765920918) },
      {  UINT8_C(    14),  UINT8_C(   206),  UINT8_C(   175),  UINT8_C(     0),
         UINT8_C(    65),  UINT8_C(    58),  UINT8_C(   157),  UINT8_C(   252) },
      {  INT8_C(     4), -INT8_C(     1),  INT8_C(    36),  INT8_C(    67),
        -INT8_C(    46), -INT8_C(    75), -INT8_C(    30), -INT8_C(    76) },
      { -INT32_C(  1544096755),  INT32_C(  1765889716) } },
    { {  INT32_C(  1415092707),  INT32_C(    77304162) },
      {  UINT8_C(   120),  UINT8_C(   102),  UINT8_C(   185),  UINT8_C(    19),
         UINT8_C(   197),  UINT8_C(    62),  UINT8_C(   138),  UINT8_C(   230) },
      {  INT8_C(   115), -INT8_C(    35),  INT8_C(    34), -INT8_C(    25),
        -INT8_C(    66),  INT8_C(    63),  INT8_C(   110),  INT8_C(    14) },
      {  INT32_C(  1415108752),  INT32_C(    77313466) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x2_t a = simde_vld1_s32(test_vec[i].a);
    simde_uint8x8_t b = simde_vld1_u8(test_vec[i].b);
    simde_int8x8_t c = simde_vld1_s8(test_vec[i].c);
    simde_int32x2_t r = simde_vusdot_s32(a, b, c);

    simde_test_arm_neon_assert_equal_i32x2(r, simde_vld1_s32(test_vec[i].r));
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int32x2_t a = simde_test_arm_neon_random_i32x2();
    simde_uint8x8_t b = simde_test_arm_neon_random_u8x8();
    simde_int8x8_t c = simde_test_arm_neon_random_i8x8();
    simde_int32x2_t r = simde_vusdot_s32(a, b, c);

    simde_test_arm_neon_write_i32x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u8x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i8x8(2, c, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i32x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vusdotq_s32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int32_t a[4];
    uint8_t b[16];
    int8_t c[16];
    int32_t r[4];
  } test_vec[] = {
    { { -INT32_C(  1879677382), -INT32_C(   594386451) },
      {  UINT8_C(   214),  UINT8_C(   148),  UINT8_C(    96),  UINT8_C(   232),
         UINT8_C(    98),  UINT8_C(   149),  UINT8_C(   131),  UINT8_C(    34) },
      {  INT8_C(    60), -INT8_C(   120), -INT8_C(    34), -INT8_C(    78),
         INT8_C(    42), -INT8_C(    18), -INT8_C(    56), -INT8_C(    40) },
      { -INT32_C(  1879703662), -INT32_C(   594393713) } },
    { { -INT32_C(  1185567567), -INT32_C(  1520797139) },
      {  UINT8_C(   160),  UINT8_C(   120),  UINT8_C(   201),  UINT8_C(     0),
         UINT8_C(   240),  UINT8_C(   158),  UINT8_C(   240),  UINT8_C(   187) },
      {  INT8_C(    64),  INT8_C(    93), -INT8_C(    58), -INT8_C(    77),
         INT8_C(   111), -INT8_C(    75), -INT8_C(   126), -INT8_C(   112) },
      { -INT32_C(  1185557825), -INT32_C(  1520833533) } },
    { { -INT32_C(  1740844034), -INT32_C(  1215282822) },
      {  UINT8_C(     5),  UINT8_C(   239),  UINT8_C(     7),  UINT8_C(   214),
         UINT8_C(   121),  UINT8_C(   105),  UINT8_C(    84),  UINT8_C(   221) },
      { -INT8_C(   128), -INT8_C(    95),  INT8_C(    13), -INT8_C(    31),
         INT8_C(   124), -INT8_C(    39), -INT8_C(   117), -INT8_C(    85) },
      { -INT32_C(  1740873922), -INT32_C(  1215300526) } },
    { { -INT32_C(   637381383),  INT32_C(  2022785690) },
      {  UINT8_C(    88),  UINT8_C(   124),  UINT8_C(   128),  UINT8_C(   163),
         UINT8_C(   107),  UINT8_C(    66),  UINT8_C(    63),  UINT8_C(   100) },
      {  INT8_C(   114),  INT8_C(    83),  INT8_C(    54),  INT8_C(    74),
        -INT8_C(    39), -INT8_C(     4),  INT8_C(   104), -INT8_C(    93) },
      { -INT32_C(   637342085),  INT32_C(  2022778505) } },
    { { -INT32_C(   736850156),  INT32_C(  1674449836) },
      {  UINT8_C(    88),  UINT8_C(    13),  UINT8_C(   161),  UINT8_C(   236),
         UINT8_C(    44),  UINT8_C(   251),  UINT8_C(    54),  UINT8_C(   169) },
      { -INT8_C(    10), -INT8_C(   103),  INT8_C(    30), -INT8_C(   107),
        -INT8_C(   102), -INT8_C(    51),  INT8_C(   122), -INT8_C(   105) },
      { -INT32_C(   736872797),  INT32_C(  1674421390) } },
    { {  INT32_C(   178016619),  INT32_C(  2035784344) },
      {  UINT8_C(   141),  UINT8_C(   224),  UINT8_C(    23),  UINT8_C(   238),
         UINT8_C(   195),  UINT8_C(    87),  UINT8_C(     4),  UINT8_C(    98) },
      {  INT8_C(    30),  INT8_C(    35), -INT8_C(    37),  INT8_C(   100),
        -INT8_C(    87), -INT8_C(     5),  INT8_C(    46),  INT8_C(    28) },
      {  INT32_C(   178051638),  INT32_C(  2035769872) } },
    { { -INT32_C(  1544102905),  INT32_C(  1765920918) },
      {  UINT8_C(    14),  UINT8_C(   206),  UINT8_C(   175),  UINT8_C(     0),
         UINT8_C(    65),  UINT8_C(    58),  UINT8_C(   157),  UINT8_C(   252) },
      {  INT8_C(     4), -INT8_C(     1),  INT8_C(    36),  INT8_C(    67),
        -INT8_C(    46), -INT8_C(    75), -INT8_C(    30), -INT8_C(    76) },
      { -INT32_C(  1544096755),  INT32_C(  1765889716) } },
    { {  INT32_C(  1415092707),  INT32_C(    77304162) },
      {  UINT8_C(   120),  UINT8_C(   102),  UINT8_C(   185),  UINT8_C(    19),
         UINT8_C(   197),  UINT8_C(    62),  UINT8_C(   138),  UINT8_C(   230) },
      {  INT8_C(   115), -INT8_C(    35),  INT8_C(    34), -INT8_C(    25),
        -INT8_C(    66),  INT8_C(    63),  INT8_C(   110),  INT8_C(    14) },
      {  INT32_C(  1415108752),  INT32_C(    77313466) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x4_t a = simde_vld1q_s32(test_vec[i].a);
    simde_uint8x16_t b = simde_vld1q_u8(test_vec[i].b);
    simde_int8x16_t c = simde_vld1q_s8(test_vec[i].c);
    simde_int32x4_t r = simde_vusdotq_s32(a, b, c);
    simde_test_arm_neon_assert_equal_i32x4(r, simde_vld1q_s32(test_vec[i].r));
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int32x4_t a = simde_test_arm_neon_random_i32x4();
    simde_uint8x16_t b = simde_test_arm_neon_random_u8x16();
    simde_int8x16_t c = simde_test_arm_neon_random_i8x16();
    simde_int32x4_t r = simde_vusdotq_s32(a, b, c);

    simde_test_arm_neon_write_i32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u8x16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i8x16(2, c, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(vusdot_s32)

SIMDE_TEST_FUNC_LIST_ENTRY(vusdotq_s32)
SIMDE_TEST_FUNC_LIST_END

#include "test-neon-footer.h"
