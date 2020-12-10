#define SIMDE_TEST_ARM_NEON_INSN clz

#include "test-neon.h"
#include "../../../simde/arm/neon/clz.h"
#include "../../../simde/arm/neon/and.h"
#include "../../../simde/arm/neon/dup_n.h"
#include "../../../simde/arm/neon/neg.h"
#include "../../../simde/arm/neon/set_lane.h"
#include "../../../simde/arm/neon/shl.h"

static int
test_simde_x_vclzb_s8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int8_t a;
    int8_t r;
  } test_vec[] = {
    {  INT8_C(   0),
       INT8_C(   8) },
    { -INT8_C(   1),
       INT8_C(   0) },
    {  INT8_C(  44),
       INT8_C(   2) },
    {  INT8_C(  43),
       INT8_C(   2) },
    { -INT8_C(  35),
       INT8_C(   0) },
    {  INT8_C(  27),
       INT8_C(   3) },
    {  INT8_C(  48),
       INT8_C(   2) },
    {  INT8_C(  79),
       INT8_C(   1) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    int8_t r = simde_x_vclzb_s8(test_vec[i].a);

    simde_assert_equal_i8(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    int8_t a;
    switch (i) {
      case 0:
        a = INT8_C(0);
        break;
      case 1:
        a = INT8_MIN;
        break;
      default:
        a = simde_test_codegen_random_i8();
        break;
    }
    int8_t r = simde_x_vclzb_s8(a);

    simde_test_codegen_write_i8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_i8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_x_vclzh_s16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int16_t a;
    int16_t r;
  } test_vec[] = {
    {  INT16_C(     0),
       INT16_C(    16) },
    {       INT16_MIN,
       INT16_C(     0) },
    {  INT16_C( 26700),
       INT16_C(     1) },
    { -INT16_C( 21932),
       INT16_C(     0) },
    { -INT16_C( 30991),
       INT16_C(     0) },
    { -INT16_C( 21858),
       INT16_C(     0) },
    { -INT16_C( 15362),
       INT16_C(     0) },
    {  INT16_C( 14920),
       INT16_C(     2) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    int16_t r = simde_x_vclzh_s16(test_vec[i].a);

    simde_assert_equal_i16(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    int16_t a;
    switch (i) {
      case 0:
        a = INT16_C(0);
        break;
      case 1:
        a = INT16_MIN;
        break;
      default:
        a = simde_test_codegen_random_i16();
        break;
    }
    int16_t r = simde_x_vclzh_s16(a);

    simde_test_codegen_write_i16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_i16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_x_vclzs_s32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int32_t a;
    int32_t r;
  } test_vec[] = {
    {  INT32_C(           0),
       INT32_C(          32) },
    {            INT32_MIN,
       INT32_C(           0) },
    {  INT32_C(  1347396202),
       INT32_C(           1) },
    { -INT32_C(   239946416),
       INT32_C(           0) },
    { -INT32_C(  1214188073),
       INT32_C(           0) },
    {  INT32_C(  1550140061),
       INT32_C(           1) },
    {  INT32_C(  1239879933),
       INT32_C(           1) },
    {  INT32_C(  1794325369),
       INT32_C(           1) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    int32_t r = simde_x_vclzs_s32(test_vec[i].a);

    simde_assert_equal_i32(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    int32_t a;
    switch (i) {
      case 0:
        a = INT32_C(0);
        break;
      case 1:
        a = INT32_MIN;
        break;
      default:
        a = simde_test_codegen_random_i32();
        break;
    }
    int32_t r = simde_x_vclzs_s32(a);

    simde_test_codegen_write_i32(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_i32(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_x_vclzb_u8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint8_t a;
    uint8_t r;
  } test_vec[] = {
    { UINT8_C(  0),
      UINT8_C(  8) },
    {    UINT8_MAX,
      UINT8_C(  0) },
    { UINT8_C(243),
      UINT8_C(  0) },
    { UINT8_C(128),
      UINT8_C(  0) },
    { UINT8_C(240),
      UINT8_C(  0) },
    { UINT8_C( 44),
      UINT8_C(  2) },
    { UINT8_C(119),
      UINT8_C(  1) },
    { UINT8_C(181),
      UINT8_C(  0) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    uint8_t r = simde_x_vclzb_u8(test_vec[i].a);

    simde_assert_equal_u8(r, test_vec[i].r);
  }
  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    uint8_t a;
    switch (i) {
      case 0:
        a = UINT8_C(0);
        break;
      case 1:
        a = UINT8_MAX;
        break;
      default:
        a = simde_test_codegen_random_u8();
        break;
    }
    uint8_t r = simde_x_vclzb_u8(a);

    simde_test_codegen_write_u8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_u8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_x_vclzh_u16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint16_t a;
    uint16_t r;
  } test_vec[] = {
    { UINT16_C(    0),
      UINT16_C(   16) },
    {      UINT16_MAX,
      UINT16_C(    0) },
    { UINT16_C(47597),
      UINT16_C(    0) },
    { UINT16_C(13283),
      UINT16_C(    2) },
    { UINT16_C(30782),
      UINT16_C(    1) },
    { UINT16_C(47971),
      UINT16_C(    0) },
    { UINT16_C(10652),
      UINT16_C(    2) },
    { UINT16_C(15587),
      UINT16_C(    2) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    uint16_t r = simde_x_vclzh_u16(test_vec[i].a);

    simde_assert_equal_u16(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    uint16_t a;
    switch (i) {
      case 0:
        a = UINT16_C(0);
        break;
      case 1:
        a = UINT16_MAX;
        break;
      default:
        a = simde_test_codegen_random_u16();
        break;
    }
    uint16_t r = simde_x_vclzh_u16(a);

    simde_test_codegen_write_u16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_u16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_x_vclzs_u32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint32_t a;
    uint32_t r;
  } test_vec[] = {
    { UINT32_C(         0),
      UINT32_C(        32) },
    {           UINT32_MAX,
      UINT32_C(         0) },
    { UINT32_C( 216644308),
      UINT32_C(         4) },
    { UINT32_C(3628548586),
      UINT32_C(         0) },
    { UINT32_C(2274079924),
      UINT32_C(         0) },
    { UINT32_C( 805797440),
      UINT32_C(         2) },
    { UINT32_C(2565242795),
      UINT32_C(         0) },
    { UINT32_C(2009844024),
      UINT32_C(         1) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    uint32_t r = simde_x_vclzs_u32(test_vec[i].a);

    simde_assert_equal_u32(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    uint32_t a;
    switch (i) {
      case 0:
        a = UINT32_C(0);
        break;
      case 1:
        a = UINT32_MAX;
        break;
      default:
        a = simde_test_codegen_random_u32();
        break;
    }
    uint32_t r = simde_x_vclzs_u32(a);

    simde_test_codegen_write_u32(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_u32(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vclz_s8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int8_t a[8];
    int8_t r[8];
  } test_vec[] = {
    { {  INT8_C(   0), -INT8_C(   1),  INT8_C(  26), -INT8_C(   5), -INT8_C(  62),  INT8_C(   9), -INT8_C(   9),  INT8_C(  26) },
      {  INT8_C(   8),  INT8_C(   0),  INT8_C(   3),  INT8_C(   0),  INT8_C(   0),  INT8_C(   4),  INT8_C(   0),  INT8_C(   3) } },
    { { -INT8_C(  87),  INT8_C(   0),  INT8_C(   2), -INT8_C(   4), -INT8_C(  15), -INT8_C(   3), -INT8_C(   2),  INT8_C(   4) },
      {  INT8_C(   0),  INT8_C(   8),  INT8_C(   6),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   5) } },
    { {  INT8_C(  49), -INT8_C(   8), -INT8_C(  26), -INT8_C(   7), -INT8_C(   2), -INT8_C(  13),  INT8_C(   5),  INT8_C(   1) },
      {  INT8_C(   2),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   5),  INT8_C(   7) } },
    { { -INT8_C(  30), -INT8_C(   1), -INT8_C(  25),  INT8_C(  30), -INT8_C(   5),  INT8_C(  84), -INT8_C(   4), -INT8_C(   1) },
      {  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   3),  INT8_C(   0),  INT8_C(   1),  INT8_C(   0),  INT8_C(   0) } },
    { {  INT8_C(  36), -INT8_C( 117), -INT8_C(   3),  INT8_C(   1),  INT8_C(   5),  INT8_C(   3),  INT8_C(  44),  INT8_C(  15) },
      {  INT8_C(   2),  INT8_C(   0),  INT8_C(   0),  INT8_C(   7),  INT8_C(   5),  INT8_C(   6),  INT8_C(   2),  INT8_C(   4) } },
    { {  INT8_C(   0),  INT8_C(   0), -INT8_C( 115), -INT8_C(   2), -INT8_C(   2),  INT8_C(   1), -INT8_C(  18),  INT8_C(   0) },
      {  INT8_C(   8),  INT8_C(   8),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   7),  INT8_C(   0),  INT8_C(   8) } },
    { { -INT8_C(  12), -INT8_C(   6), -INT8_C(   2), -INT8_C(   1), -INT8_C(   2), -INT8_C(   1),  INT8_C(  58),  INT8_C(   0) },
      {  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   2),  INT8_C(   8) } },
    { { -INT8_C(   2),  INT8_C(   0),  INT8_C( 117),  INT8_C(   0),  INT8_C(   2),  INT8_C(  12),  INT8_C(   1),  INT8_C(   0) },
      {  INT8_C(   0),  INT8_C(   8),  INT8_C(   1),  INT8_C(   8),  INT8_C(   6),  INT8_C(   4),  INT8_C(   7),  INT8_C(   8) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int8x8_t a = simde_vld1_s8(test_vec[i].a);
    simde_int8x8_t r = simde_vclz_s8(a);

    simde_test_arm_neon_assert_equal_i8x8(r, simde_vld1_s8(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int8x8_t a = simde_test_arm_neon_random_i8x8();
    a = simde_vshl_s8(a, simde_vneg_s8(simde_vand_s8(simde_test_arm_neon_random_i8x8(), simde_vdup_n_s8(7))));
    if (i == 0) {
      a = simde_vset_lane_s8( INT8_C(0), a, 0);
      a = simde_vset_lane_s8(-INT8_C(1), a, 1);
    }
    simde_int8x8_t r = simde_vclz_s8(a);

    simde_test_arm_neon_write_i8x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i8x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vclz_s16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int16_t a[4];
    int16_t r[4];
  } test_vec[] = {
    { {  INT16_C(     0), -INT16_C(     1),  INT16_C(  9072), -INT16_C(   590) },
      {  INT16_C(    16),  INT16_C(     0),  INT16_C(     2),  INT16_C(     0) } },
    { {  INT16_C( 26912),  INT16_C(     3), -INT16_C(    93),  INT16_C(    15) },
      {  INT16_C(     1),  INT16_C(    14),  INT16_C(     0),  INT16_C(    12) } },
    { {  INT16_C(    15), -INT16_C( 14146), -INT16_C(   191), -INT16_C(  4389) },
      {  INT16_C(    12),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0) } },
    { { -INT16_C( 15217),  INT16_C(     5), -INT16_C(  9323),  INT16_C(  2408) },
      {  INT16_C(     0),  INT16_C(    13),  INT16_C(     0),  INT16_C(     4) } },
    { { -INT16_C(     7), -INT16_C(   224),  INT16_C(   505), -INT16_C(     5) },
      {  INT16_C(     0),  INT16_C(     0),  INT16_C(     7),  INT16_C(     0) } },
    { {  INT16_C(     1), -INT16_C(   254),  INT16_C(   158), -INT16_C(     1) },
      {  INT16_C(    15),  INT16_C(     0),  INT16_C(     8),  INT16_C(     0) } },
    { { -INT16_C(     1),  INT16_C(     2), -INT16_C(     2), -INT16_C(    59) },
      {  INT16_C(     0),  INT16_C(    14),  INT16_C(     0),  INT16_C(     0) } },
    { { -INT16_C( 11275),  INT16_C(   397), -INT16_C(  1009),  INT16_C(  2750) },
      {  INT16_C(     0),  INT16_C(     7),  INT16_C(     0),  INT16_C(     4) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x4_t a = simde_vld1_s16(test_vec[i].a);
    simde_int16x4_t r = simde_vclz_s16(a);

    simde_test_arm_neon_assert_equal_i16x4(r, simde_vld1_s16(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int16x4_t a = simde_test_arm_neon_random_i16x4();
    a = simde_vshl_s16(a, simde_vneg_s16(simde_vand_s16(simde_test_arm_neon_random_i16x4(), simde_vdup_n_s16(15))));
    if (i == 0) {
      a = simde_vset_lane_s16( INT16_C(0), a, 0);
      a = simde_vset_lane_s16(-INT16_C(1), a, 1);
    }
    simde_int16x4_t r = simde_vclz_s16(a);

    simde_test_arm_neon_write_i16x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i16x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vclz_s32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int32_t a[2];
    int32_t r[2];
  } test_vec[] = {
    { {  INT32_C(           0), -INT32_C(           1) },
      {  INT32_C(          32),  INT32_C(           0) } },
    { { -INT32_C(     7795023), -INT32_C(         688) },
      {  INT32_C(           0),  INT32_C(           0) } },
    { {  INT32_C(      124434),  INT32_C(         134) },
      {  INT32_C(          15),  INT32_C(          24) } },
    { {  INT32_C(       14659),  INT32_C(           0) },
      {  INT32_C(          18),  INT32_C(          32) } },
    { { -INT32_C(     4567066), -INT32_C(           1) },
      {  INT32_C(           0),  INT32_C(           0) } },
    { {  INT32_C(        5168),  INT32_C(          23) },
      {  INT32_C(          19),  INT32_C(          27) } },
    { {  INT32_C(           0),  INT32_C(     2017326) },
      {  INT32_C(          32),  INT32_C(          11) } },
    { {  INT32_C(      211567),  INT32_C(    17387595) },
      {  INT32_C(          14),  INT32_C(           7) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x2_t a = simde_vld1_s32(test_vec[i].a);
    simde_int32x2_t r = simde_vclz_s32(a);

    simde_test_arm_neon_assert_equal_i32x2(r, simde_vld1_s32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int32x2_t a = simde_test_arm_neon_random_i32x2();
    a = simde_vshl_s32(a, simde_vneg_s32(simde_vand_s32(simde_test_arm_neon_random_i32x2(), simde_vdup_n_s32(31))));
    if (i == 0) {
      a = simde_vset_lane_s32( INT32_C(0), a, 0);
      a = simde_vset_lane_s32(-INT32_C(1), a, 1);
    }
    simde_int32x2_t r = simde_vclz_s32(a);

    simde_test_arm_neon_write_i32x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i32x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vclz_u8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint8_t a[8];
    uint8_t r[8];
  } test_vec[] = {
    { { UINT8_C(  0),    UINT8_MAX, UINT8_C(216), UINT8_C( 23), UINT8_C(  1), UINT8_C( 14), UINT8_C( 35), UINT8_C(  1) },
      { UINT8_C(  8), UINT8_C(  0), UINT8_C(  0), UINT8_C(  3), UINT8_C(  7), UINT8_C(  4), UINT8_C(  2), UINT8_C(  7) } },
    { { UINT8_C(  6), UINT8_C(148), UINT8_C(  0), UINT8_C(  3), UINT8_C(  7), UINT8_C( 52), UINT8_C(222), UINT8_C(  2) },
      { UINT8_C(  5), UINT8_C(  0), UINT8_C(  8), UINT8_C(  6), UINT8_C(  5), UINT8_C(  2), UINT8_C(  0), UINT8_C(  6) } },
    { { UINT8_C( 50), UINT8_C( 30), UINT8_C( 44), UINT8_C(  2), UINT8_C(  1), UINT8_C(  3), UINT8_C(  2), UINT8_C( 13) },
      { UINT8_C(  2), UINT8_C(  3), UINT8_C(  2), UINT8_C(  6), UINT8_C(  7), UINT8_C(  6), UINT8_C(  6), UINT8_C(  4) } },
    { { UINT8_C(120), UINT8_C(  9), UINT8_C( 69), UINT8_C( 63), UINT8_C(  0), UINT8_C( 52), UINT8_C(  9), UINT8_C(110) },
      { UINT8_C(  1), UINT8_C(  4), UINT8_C(  1), UINT8_C(  2), UINT8_C(  8), UINT8_C(  2), UINT8_C(  4), UINT8_C(  1) } },
    { { UINT8_C(233), UINT8_C( 10), UINT8_C(  8), UINT8_C(  1), UINT8_C(229), UINT8_C(  9), UINT8_C( 92), UINT8_C( 19) },
      { UINT8_C(  0), UINT8_C(  4), UINT8_C(  4), UINT8_C(  7), UINT8_C(  0), UINT8_C(  4), UINT8_C(  1), UINT8_C(  3) } },
    { { UINT8_C( 35), UINT8_C(  5), UINT8_C(  2), UINT8_C(126), UINT8_C(  9), UINT8_C(  7), UINT8_C( 54), UINT8_C(  1) },
      { UINT8_C(  2), UINT8_C(  5), UINT8_C(  6), UINT8_C(  1), UINT8_C(  4), UINT8_C(  5), UINT8_C(  2), UINT8_C(  7) } },
    { { UINT8_C( 13), UINT8_C( 13), UINT8_C(  3), UINT8_C(  4), UINT8_C(  7), UINT8_C(  1), UINT8_C(  3), UINT8_C( 29) },
      { UINT8_C(  4), UINT8_C(  4), UINT8_C(  6), UINT8_C(  5), UINT8_C(  5), UINT8_C(  7), UINT8_C(  6), UINT8_C(  3) } },
    { { UINT8_C( 12), UINT8_C( 14), UINT8_C(  2), UINT8_C( 44), UINT8_C(  4), UINT8_C(113), UINT8_C(  1), UINT8_C(  2) },
      { UINT8_C(  4), UINT8_C(  4), UINT8_C(  6), UINT8_C(  2), UINT8_C(  5), UINT8_C(  1), UINT8_C(  7), UINT8_C(  6) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint8x8_t a = simde_vld1_u8(test_vec[i].a);
    simde_uint8x8_t r = simde_vclz_u8(a);

    simde_test_arm_neon_assert_equal_u8x8(r, simde_vld1_u8(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint8x8_t a = simde_test_arm_neon_random_u8x8();
    a = simde_vshl_u8(a, simde_vneg_s8(simde_vand_s8(simde_test_arm_neon_random_i8x8(), simde_vdup_n_s8(7))));
    if (i == 0) {
      a = simde_vset_lane_u8(UINT8_C(0), a, 0);
      a = simde_vset_lane_u8( UINT8_MAX, a, 1);
    }
    simde_uint8x8_t r = simde_vclz_u8(a);

    simde_test_arm_neon_write_u8x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u8x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vclz_u16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint16_t a[4];
    uint16_t r[4];
  } test_vec[] = {
    { { UINT16_C(    0),      UINT16_MAX, UINT16_C(    0), UINT16_C(26770) },
      { UINT16_C(   16), UINT16_C(    0), UINT16_C(   16), UINT16_C(    1) } },
    { { UINT16_C( 6421), UINT16_C(  130), UINT16_C( 3843), UINT16_C(  205) },
      { UINT16_C(    3), UINT16_C(    8), UINT16_C(    4), UINT16_C(    8) } },
    { { UINT16_C( 1603), UINT16_C(  290), UINT16_C(  486), UINT16_C(  386) },
      { UINT16_C(    5), UINT16_C(    7), UINT16_C(    7), UINT16_C(    7) } },
    { { UINT16_C(  495), UINT16_C(    1), UINT16_C(    7), UINT16_C( 1608) },
      { UINT16_C(    7), UINT16_C(   15), UINT16_C(   13), UINT16_C(    5) } },
    { { UINT16_C( 1655), UINT16_C(24204), UINT16_C(   50), UINT16_C(    6) },
      { UINT16_C(    5), UINT16_C(    1), UINT16_C(   10), UINT16_C(   13) } },
    { { UINT16_C(    2), UINT16_C( 6868), UINT16_C(57838), UINT16_C(  413) },
      { UINT16_C(   14), UINT16_C(    3), UINT16_C(    0), UINT16_C(    7) } },
    { { UINT16_C(  128), UINT16_C(   94), UINT16_C(  204), UINT16_C(   51) },
      { UINT16_C(    8), UINT16_C(    9), UINT16_C(    8), UINT16_C(   10) } },
    { { UINT16_C( 1010), UINT16_C(    9), UINT16_C(    0), UINT16_C(    1) },
      { UINT16_C(    6), UINT16_C(   12), UINT16_C(   16), UINT16_C(   15) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint16x4_t a = simde_vld1_u16(test_vec[i].a);
    simde_uint16x4_t r = simde_vclz_u16(a);

    simde_test_arm_neon_assert_equal_u16x4(r, simde_vld1_u16(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint16x4_t a = simde_test_arm_neon_random_u16x4();
    a = simde_vshl_u16(a, simde_vneg_s16(simde_vand_s16(simde_test_arm_neon_random_i16x4(), simde_vdup_n_s16(15))));
    if (i == 0) {
      a = simde_vset_lane_u16(UINT16_C(0), a, 0);
      a = simde_vset_lane_u16( UINT16_MAX, a, 1);
    }
    simde_uint16x4_t r = simde_vclz_u16(a);

    simde_test_arm_neon_write_u16x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u16x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vclz_u32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint32_t a[2];
    uint32_t r[2];
  } test_vec[] = {
    { { UINT32_C(         0),           UINT32_MAX },
      { UINT32_C(        32), UINT32_C(         0) } },
    { { UINT32_C(1423272567), UINT32_C(   3536156) },
      { UINT32_C(         1), UINT32_C(        10) } },
    { { UINT32_C(      1801), UINT32_C(    154636) },
      { UINT32_C(        21), UINT32_C(        14) } },
    { { UINT32_C(       149), UINT32_C( 322967635) },
      { UINT32_C(        24), UINT32_C(         3) } },
    { { UINT32_C(   1828682), UINT32_C(1728249100) },
      { UINT32_C(        11), UINT32_C(         1) } },
    { { UINT32_C(  10614514), UINT32_C(        38) },
      { UINT32_C(         8), UINT32_C(        26) } },
    { { UINT32_C(    519401), UINT32_C(   1505652) },
      { UINT32_C(        13), UINT32_C(        11) } },
    { { UINT32_C(      1945), UINT32_C(       266) },
      { UINT32_C(        21), UINT32_C(        23) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint32x2_t a = simde_vld1_u32(test_vec[i].a);
    simde_uint32x2_t r = simde_vclz_u32(a);

    simde_test_arm_neon_assert_equal_u32x2(r, simde_vld1_u32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint32x2_t a = simde_test_arm_neon_random_u32x2();
    a = simde_vshl_u32(a, simde_vneg_s32(simde_vand_s32(simde_test_arm_neon_random_i32x2(), simde_vdup_n_s32(31))));
    if (i == 0) {
      a = simde_vset_lane_u32(UINT32_C(0), a, 0);
      a = simde_vset_lane_u32( UINT32_MAX, a, 1);
    }
    simde_uint32x2_t r = simde_vclz_u32(a);

    simde_test_arm_neon_write_u32x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u32x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vclzq_s8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int8_t a[16];
    int8_t r[16];
  } test_vec[] = {
    { {  INT8_C(   0), -INT8_C(   1),  INT8_C(   1), -INT8_C(   5),  INT8_C(  11), -INT8_C(   1),  INT8_C(   8),  INT8_C(  54),
         INT8_C(   1), -INT8_C(  20), -INT8_C(  15),  INT8_C(  26),  INT8_C(   1),  INT8_C(   0), -INT8_C(  99), -INT8_C(   7) },
      {  INT8_C(   8),  INT8_C(   0),  INT8_C(   7),  INT8_C(   0),  INT8_C(   4),  INT8_C(   0),  INT8_C(   4),  INT8_C(   2),
         INT8_C(   7),  INT8_C(   0),  INT8_C(   0),  INT8_C(   3),  INT8_C(   7),  INT8_C(   8),  INT8_C(   0),  INT8_C(   0) } },
    { {  INT8_C(   0),  INT8_C(  15),  INT8_C(  16),  INT8_C(  23),  INT8_C(  96),  INT8_C(   5), -INT8_C(   4), -INT8_C(   1),
         INT8_C(   3), -INT8_C(   3), -INT8_C(  23),  INT8_C(  44),  INT8_C(   1), -INT8_C( 121), -INT8_C(   1), -INT8_C(   1) },
      {  INT8_C(   8),  INT8_C(   4),  INT8_C(   3),  INT8_C(   3),  INT8_C(   1),  INT8_C(   5),  INT8_C(   0),  INT8_C(   0),
         INT8_C(   6),  INT8_C(   0),  INT8_C(   0),  INT8_C(   2),  INT8_C(   7),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0) } },
    { { -INT8_C(   2), -INT8_C(   4),  INT8_C(   6), -INT8_C(   1), -INT8_C(   9), -INT8_C(   2), -INT8_C(   3),  INT8_C(   0),
        -INT8_C(  31), -INT8_C(   4), -INT8_C(   1), -INT8_C(   1),  INT8_C(   1),  INT8_C(   7),  INT8_C(   3),      INT8_MAX },
      {  INT8_C(   0),  INT8_C(   0),  INT8_C(   5),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   8),
         INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   7),  INT8_C(   5),  INT8_C(   6),  INT8_C(   1) } },
    { { -INT8_C(   3), -INT8_C(   2),  INT8_C(  68), -INT8_C(   6), -INT8_C(  22), -INT8_C(   1),  INT8_C(  20),  INT8_C(   1),
        -INT8_C(  15), -INT8_C(   1), -INT8_C(   4), -INT8_C(  84),  INT8_C(   0),  INT8_C(  37),  INT8_C(  21),  INT8_C(   0) },
      {  INT8_C(   0),  INT8_C(   0),  INT8_C(   1),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   3),  INT8_C(   7),
         INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   8),  INT8_C(   2),  INT8_C(   3),  INT8_C(   8) } },
    { { -INT8_C(  23), -INT8_C(  62),  INT8_C(   0),  INT8_C(   5),  INT8_C(   1),  INT8_C( 115), -INT8_C(  63),  INT8_C(   2),
         INT8_C(   0),  INT8_C(   2), -INT8_C(  20),  INT8_C(   2), -INT8_C(   1), -INT8_C(   5),  INT8_C(  12), -INT8_C(   5) },
      {  INT8_C(   0),  INT8_C(   0),  INT8_C(   8),  INT8_C(   5),  INT8_C(   7),  INT8_C(   1),  INT8_C(   0),  INT8_C(   6),
         INT8_C(   8),  INT8_C(   6),  INT8_C(   0),  INT8_C(   6),  INT8_C(   0),  INT8_C(   0),  INT8_C(   4),  INT8_C(   0) } },
    { { -INT8_C(  16), -INT8_C(   2),  INT8_C(   2),  INT8_C(   0),  INT8_C(   0), -INT8_C(   8),  INT8_C( 109),  INT8_C(   0),
        -INT8_C(  17),  INT8_C(   7),  INT8_C(  23),  INT8_C( 122), -INT8_C(   1),  INT8_C(   8),  INT8_C(   5), -INT8_C(   3) },
      {  INT8_C(   0),  INT8_C(   0),  INT8_C(   6),  INT8_C(   8),  INT8_C(   8),  INT8_C(   0),  INT8_C(   1),  INT8_C(   8),
         INT8_C(   0),  INT8_C(   5),  INT8_C(   3),  INT8_C(   1),  INT8_C(   0),  INT8_C(   4),  INT8_C(   5),  INT8_C(   0) } },
    { {  INT8_C(  12),  INT8_C(   0),  INT8_C(  29),  INT8_C(  31), -INT8_C(   4), -INT8_C(   4),  INT8_C(   0), -INT8_C(   4),
         INT8_C(   0), -INT8_C( 125),  INT8_C(   1), -INT8_C(   1), -INT8_C(   7), -INT8_C(  54), -INT8_C(  76),  INT8_C(   0) },
      {  INT8_C(   4),  INT8_C(   8),  INT8_C(   3),  INT8_C(   3),  INT8_C(   0),  INT8_C(   0),  INT8_C(   8),  INT8_C(   0),
         INT8_C(   8),  INT8_C(   0),  INT8_C(   7),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   8) } },
    { { -INT8_C(   2),  INT8_C(   1),  INT8_C(   1),  INT8_C(  58),  INT8_C(  41),  INT8_C(   7),  INT8_C(   0),  INT8_C(   1),
        -INT8_C(   1),  INT8_C(  14),  INT8_C(  41), -INT8_C(  56),  INT8_C(   0),  INT8_C(   1),  INT8_C(   0), -INT8_C(   4) },
      {  INT8_C(   0),  INT8_C(   7),  INT8_C(   7),  INT8_C(   2),  INT8_C(   2),  INT8_C(   5),  INT8_C(   8),  INT8_C(   7),
         INT8_C(   0),  INT8_C(   4),  INT8_C(   2),  INT8_C(   0),  INT8_C(   8),  INT8_C(   7),  INT8_C(   8),  INT8_C(   0) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int8x16_t a = simde_vld1q_s8(test_vec[i].a);
    simde_int8x16_t r = simde_vclzq_s8(a);

    simde_test_arm_neon_assert_equal_i8x16(r, simde_vld1q_s8(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int8x16_t a = simde_test_arm_neon_random_i8x16();
    a = simde_vshlq_s8(a, simde_vnegq_s8(simde_vandq_s8(simde_test_arm_neon_random_i8x16(), simde_vdupq_n_s8(7))));
    if (i == 0) {
      a = simde_vsetq_lane_s8( INT8_C(0), a, 0);
      a = simde_vsetq_lane_s8(-INT8_C(1), a, 1);
    }
    simde_int8x16_t r = simde_vclzq_s8(a);

    simde_test_arm_neon_write_i8x16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i8x16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vclzq_s16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int16_t a[8];
    int16_t r[8];
  } test_vec[] = {
    { {  INT16_C(     0), -INT16_C(     1),  INT16_C(   363), -INT16_C(     6), -INT16_C(    14), -INT16_C(  1226), -INT16_C(   297), -INT16_C(  3820) },
      {  INT16_C(    16),  INT16_C(     0),  INT16_C(     7),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0) } },
    { { -INT16_C(    14), -INT16_C(    15), -INT16_C(     5),  INT16_C(     3), -INT16_C(   463),  INT16_C(     2), -INT16_C(     1), -INT16_C(  3686) },
      {  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(    14),  INT16_C(     0),  INT16_C(    14),  INT16_C(     0),  INT16_C(     0) } },
    { {  INT16_C(    31),  INT16_C(    94), -INT16_C(  4149), -INT16_C(     3), -INT16_C(     1), -INT16_C(   921), -INT16_C(     8), -INT16_C(     1) },
      {  INT16_C(    11),  INT16_C(     9),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0) } },
    { {  INT16_C(  4538), -INT16_C(     3), -INT16_C(     6),  INT16_C(     1),  INT16_C(   226),  INT16_C(   843), -INT16_C(     6), -INT16_C(  4618) },
      {  INT16_C(     3),  INT16_C(     0),  INT16_C(     0),  INT16_C(    15),  INT16_C(     8),  INT16_C(     6),  INT16_C(     0),  INT16_C(     0) } },
    { {  INT16_C(   326), -INT16_C(   174), -INT16_C(    12),  INT16_C(    15), -INT16_C(   223), -INT16_C(  2325), -INT16_C(  3828), -INT16_C(  5687) },
      {  INT16_C(     7),  INT16_C(     0),  INT16_C(     0),  INT16_C(    12),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0) } },
    { {  INT16_C(  1044),  INT16_C(     8),  INT16_C(     6), -INT16_C( 14693),  INT16_C(  1199),  INT16_C(   749),  INT16_C(    52),  INT16_C(  3096) },
      {  INT16_C(     5),  INT16_C(    12),  INT16_C(    13),  INT16_C(     0),  INT16_C(     5),  INT16_C(     6),  INT16_C(    10),  INT16_C(     4) } },
    { {  INT16_C( 21944), -INT16_C( 12245), -INT16_C(   115), -INT16_C( 17817),  INT16_C(    73),  INT16_C(  1803),  INT16_C(     4), -INT16_C(  8055) },
      {  INT16_C(     1),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     9),  INT16_C(     5),  INT16_C(    13),  INT16_C(     0) } },
    { { -INT16_C(    15), -INT16_C(     1),  INT16_C(    60), -INT16_C(    10), -INT16_C(  2776), -INT16_C(    32), -INT16_C(     1),  INT16_C(   648) },
      {  INT16_C(     0),  INT16_C(     0),  INT16_C(    10),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     6) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x8_t a = simde_vld1q_s16(test_vec[i].a);
    simde_int16x8_t r = simde_vclzq_s16(a);

    simde_test_arm_neon_assert_equal_i16x8(r, simde_vld1q_s16(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int16x8_t a = simde_test_arm_neon_random_i16x8();
    a = simde_vshlq_s16(a, simde_vnegq_s16(simde_vandq_s16(simde_test_arm_neon_random_i16x8(), simde_vdupq_n_s16(15))));
    if (i == 0) {
      a = simde_vsetq_lane_s16( INT16_C(0), a, 0);
      a = simde_vsetq_lane_s16(-INT16_C(1), a, 1);
    }
    simde_int16x8_t r = simde_vclzq_s16(a);

    simde_test_arm_neon_write_i16x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i16x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vclzq_s32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int32_t a[4];
    int32_t r[4];
  } test_vec[] = {
    { {  INT32_C(           0), -INT32_C(           1), -INT32_C(     2742371),  INT32_C(     5307732) },
      {  INT32_C(          32),  INT32_C(           0),  INT32_C(           0),  INT32_C(           9) } },
    { {  INT32_C(           0),  INT32_C(   169886544), -INT32_C(           1),  INT32_C(    33527206) },
      {  INT32_C(          32),  INT32_C(           4),  INT32_C(           0),  INT32_C(           7) } },
    { { -INT32_C(          14),  INT32_C(           1), -INT32_C(     5141852),  INT32_C(      166875) },
      {  INT32_C(           0),  INT32_C(          31),  INT32_C(           0),  INT32_C(          14) } },
    { { -INT32_C(         119), -INT32_C(    13104593),  INT32_C(    29218601),  INT32_C(       30162) },
      {  INT32_C(           0),  INT32_C(           0),  INT32_C(           7),  INT32_C(          17) } },
    { {  INT32_C(           2), -INT32_C(          74),  INT32_C(        2009), -INT32_C(     6734631) },
      {  INT32_C(          30),  INT32_C(           0),  INT32_C(          21),  INT32_C(           0) } },
    { { -INT32_C(          55), -INT32_C(    23134680), -INT32_C(           1),  INT32_C(          22) },
      {  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(          27) } },
    { { -INT32_C(    64880981),  INT32_C(     1021439),  INT32_C(          65), -INT32_C(           2) },
      {  INT32_C(           0),  INT32_C(          12),  INT32_C(          25),  INT32_C(           0) } },
    { { -INT32_C(          20), -INT32_C(        2791),  INT32_C(           2),  INT32_C(         115) },
      {  INT32_C(           0),  INT32_C(           0),  INT32_C(          30),  INT32_C(          25) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x4_t a = simde_vld1q_s32(test_vec[i].a);
    simde_int32x4_t r = simde_vclzq_s32(a);

    simde_test_arm_neon_assert_equal_i32x4(r, simde_vld1q_s32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int32x4_t a = simde_test_arm_neon_random_i32x4();
    a = simde_vshlq_s32(a, simde_vnegq_s32(simde_vandq_s32(simde_test_arm_neon_random_i32x4(), simde_vdupq_n_s32(31))));
    if (i == 0) {
      a = simde_vsetq_lane_s32( INT32_C(0), a, 0);
      a = simde_vsetq_lane_s32(-INT32_C(1), a, 1);
    }
    simde_int32x4_t r = simde_vclzq_s32(a);

    simde_test_arm_neon_write_i32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vclzq_u8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint8_t a[16];
    uint8_t r[16];
  } test_vec[] = {
    { { UINT8_C(  0),    UINT8_MAX, UINT8_C(  1), UINT8_C(  8), UINT8_C( 83), UINT8_C( 20), UINT8_C( 67), UINT8_C(  1),
        UINT8_C( 52), UINT8_C(  0), UINT8_C(  6), UINT8_C( 11), UINT8_C(211), UINT8_C(  7), UINT8_C( 14), UINT8_C(  1) },
      { UINT8_C(  8), UINT8_C(  0), UINT8_C(  7), UINT8_C(  4), UINT8_C(  1), UINT8_C(  3), UINT8_C(  1), UINT8_C(  7),
        UINT8_C(  2), UINT8_C(  8), UINT8_C(  5), UINT8_C(  4), UINT8_C(  0), UINT8_C(  5), UINT8_C(  4), UINT8_C(  7) } },
    { { UINT8_C(  3), UINT8_C( 81), UINT8_C( 12), UINT8_C(  0), UINT8_C( 51), UINT8_C( 14), UINT8_C(  3), UINT8_C( 10),
        UINT8_C(  8), UINT8_C( 11), UINT8_C( 94), UINT8_C( 61), UINT8_C( 88), UINT8_C( 25), UINT8_C( 92), UINT8_C(  4) },
      { UINT8_C(  6), UINT8_C(  1), UINT8_C(  4), UINT8_C(  8), UINT8_C(  2), UINT8_C(  4), UINT8_C(  6), UINT8_C(  4),
        UINT8_C(  4), UINT8_C(  4), UINT8_C(  1), UINT8_C(  2), UINT8_C(  1), UINT8_C(  3), UINT8_C(  1), UINT8_C(  5) } },
    { { UINT8_C( 55), UINT8_C(  9), UINT8_C(  0), UINT8_C(  0), UINT8_C( 64), UINT8_C( 30), UINT8_C(  2), UINT8_C( 20),
        UINT8_C(  1), UINT8_C(  0), UINT8_C(  2), UINT8_C( 98), UINT8_C( 52), UINT8_C(  0), UINT8_C(  3), UINT8_C( 47) },
      { UINT8_C(  2), UINT8_C(  4), UINT8_C(  8), UINT8_C(  8), UINT8_C(  1), UINT8_C(  3), UINT8_C(  6), UINT8_C(  3),
        UINT8_C(  7), UINT8_C(  8), UINT8_C(  6), UINT8_C(  1), UINT8_C(  2), UINT8_C(  8), UINT8_C(  6), UINT8_C(  2) } },
    { { UINT8_C(  0), UINT8_C(  5), UINT8_C(102), UINT8_C(153), UINT8_C(180), UINT8_C(  0), UINT8_C(  7), UINT8_C(102),
        UINT8_C(  1), UINT8_C(104), UINT8_C(201), UINT8_C( 66), UINT8_C( 15), UINT8_C(  3), UINT8_C( 80), UINT8_C( 25) },
      { UINT8_C(  8), UINT8_C(  5), UINT8_C(  1), UINT8_C(  0), UINT8_C(  0), UINT8_C(  8), UINT8_C(  5), UINT8_C(  1),
        UINT8_C(  7), UINT8_C(  1), UINT8_C(  0), UINT8_C(  1), UINT8_C(  4), UINT8_C(  6), UINT8_C(  1), UINT8_C(  3) } },
    { { UINT8_C(  0), UINT8_C(  0), UINT8_C( 16), UINT8_C(  3), UINT8_C(  1), UINT8_C(  1), UINT8_C(  1), UINT8_C(  1),
        UINT8_C(  0), UINT8_C(  0), UINT8_C(  4), UINT8_C(110), UINT8_C(  6), UINT8_C(  0), UINT8_C( 53), UINT8_C( 52) },
      { UINT8_C(  8), UINT8_C(  8), UINT8_C(  3), UINT8_C(  6), UINT8_C(  7), UINT8_C(  7), UINT8_C(  7), UINT8_C(  7),
        UINT8_C(  8), UINT8_C(  8), UINT8_C(  5), UINT8_C(  1), UINT8_C(  5), UINT8_C(  8), UINT8_C(  2), UINT8_C(  2) } },
    { { UINT8_C(  1), UINT8_C(  0), UINT8_C(  1), UINT8_C(  1), UINT8_C( 17), UINT8_C(  6), UINT8_C( 23), UINT8_C( 27),
        UINT8_C( 14), UINT8_C( 57), UINT8_C(  9), UINT8_C( 96), UINT8_C(  1), UINT8_C(  0), UINT8_C(  9), UINT8_C( 56) },
      { UINT8_C(  7), UINT8_C(  8), UINT8_C(  7), UINT8_C(  7), UINT8_C(  3), UINT8_C(  5), UINT8_C(  3), UINT8_C(  3),
        UINT8_C(  4), UINT8_C(  2), UINT8_C(  4), UINT8_C(  1), UINT8_C(  7), UINT8_C(  8), UINT8_C(  4), UINT8_C(  2) } },
    { { UINT8_C( 19), UINT8_C(  8), UINT8_C(  8), UINT8_C(  6), UINT8_C( 42), UINT8_C(  0), UINT8_C(180), UINT8_C(  1),
        UINT8_C(124), UINT8_C( 15), UINT8_C(  1), UINT8_C(  3), UINT8_C(  7), UINT8_C( 17), UINT8_C(182), UINT8_C(  3) },
      { UINT8_C(  3), UINT8_C(  4), UINT8_C(  4), UINT8_C(  5), UINT8_C(  2), UINT8_C(  8), UINT8_C(  0), UINT8_C(  7),
        UINT8_C(  1), UINT8_C(  4), UINT8_C(  7), UINT8_C(  6), UINT8_C(  5), UINT8_C(  3), UINT8_C(  0), UINT8_C(  6) } },
    { { UINT8_C(  4), UINT8_C(163), UINT8_C(  5), UINT8_C(  7), UINT8_C(  1), UINT8_C(  1), UINT8_C( 44), UINT8_C(  0),
        UINT8_C( 28), UINT8_C( 84), UINT8_C(  0), UINT8_C(  8), UINT8_C(  3), UINT8_C(  3), UINT8_C( 21), UINT8_C(  0) },
      { UINT8_C(  5), UINT8_C(  0), UINT8_C(  5), UINT8_C(  5), UINT8_C(  7), UINT8_C(  7), UINT8_C(  2), UINT8_C(  8),
        UINT8_C(  3), UINT8_C(  1), UINT8_C(  8), UINT8_C(  4), UINT8_C(  6), UINT8_C(  6), UINT8_C(  3), UINT8_C(  8) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint8x16_t a = simde_vld1q_u8(test_vec[i].a);
    simde_uint8x16_t r = simde_vclzq_u8(a);

    simde_test_arm_neon_assert_equal_u8x16(r, simde_vld1q_u8(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint8x16_t a = simde_test_arm_neon_random_u8x16();
    a = simde_vshlq_u8(a, simde_vnegq_s8(simde_vandq_s8(simde_test_arm_neon_random_i8x16(), simde_vdupq_n_s8(7))));
    if (i == 0) {
      a = simde_vsetq_lane_u8(UINT8_C(0), a, 0);
      a = simde_vsetq_lane_u8( UINT8_MAX, a, 1);
    }
    simde_uint8x16_t r = simde_vclzq_u8(a);

    simde_test_arm_neon_write_u8x16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u8x16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vclzq_u16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint16_t a[8];
    uint16_t r[8];
  } test_vec[] = {
    { { UINT16_C(    0),      UINT16_MAX, UINT16_C( 6985), UINT16_C(   29), UINT16_C(   14), UINT16_C(    0), UINT16_C(  115), UINT16_C(  282) },
      { UINT16_C(   16), UINT16_C(    0), UINT16_C(    3), UINT16_C(   11), UINT16_C(   12), UINT16_C(   16), UINT16_C(    9), UINT16_C(    7) } },
    { { UINT16_C(26256), UINT16_C( 5768), UINT16_C(    3), UINT16_C( 1821), UINT16_C(    9), UINT16_C( 6047), UINT16_C(  177), UINT16_C(  150) },
      { UINT16_C(    1), UINT16_C(    3), UINT16_C(   14), UINT16_C(    5), UINT16_C(   12), UINT16_C(    3), UINT16_C(    8), UINT16_C(    8) } },
    { { UINT16_C(    1), UINT16_C( 7339), UINT16_C(    0), UINT16_C(  118), UINT16_C(  123), UINT16_C(    1), UINT16_C(  248), UINT16_C( 1779) },
      { UINT16_C(   15), UINT16_C(    3), UINT16_C(   16), UINT16_C(    9), UINT16_C(    9), UINT16_C(   15), UINT16_C(    8), UINT16_C(    5) } },
    { { UINT16_C(  451), UINT16_C(   44), UINT16_C( 3245), UINT16_C(32974), UINT16_C(    0), UINT16_C(   12), UINT16_C(  416), UINT16_C( 1978) },
      { UINT16_C(    7), UINT16_C(   10), UINT16_C(    4), UINT16_C(    0), UINT16_C(   16), UINT16_C(   12), UINT16_C(    7), UINT16_C(    5) } },
    { { UINT16_C(  159), UINT16_C(    4), UINT16_C(  275), UINT16_C(   22), UINT16_C(    7), UINT16_C(  319), UINT16_C(  677), UINT16_C(34586) },
      { UINT16_C(    8), UINT16_C(   13), UINT16_C(    7), UINT16_C(   11), UINT16_C(   13), UINT16_C(    7), UINT16_C(    6), UINT16_C(    0) } },
    { { UINT16_C(  419), UINT16_C(  114), UINT16_C(  490), UINT16_C(    3), UINT16_C(   12), UINT16_C( 6178), UINT16_C(    0), UINT16_C( 1013) },
      { UINT16_C(    7), UINT16_C(    9), UINT16_C(    7), UINT16_C(   14), UINT16_C(   12), UINT16_C(    3), UINT16_C(   16), UINT16_C(    6) } },
    { { UINT16_C( 3257), UINT16_C(    0), UINT16_C(   51), UINT16_C( 1557), UINT16_C(52698), UINT16_C(18497), UINT16_C(   12), UINT16_C(   34) },
      { UINT16_C(    4), UINT16_C(   16), UINT16_C(   10), UINT16_C(    5), UINT16_C(    0), UINT16_C(    1), UINT16_C(   12), UINT16_C(   10) } },
    { { UINT16_C( 3452), UINT16_C(   90), UINT16_C(   61), UINT16_C(16486), UINT16_C( 2618), UINT16_C( 1696), UINT16_C(   39), UINT16_C( 9222) },
      { UINT16_C(    4), UINT16_C(    9), UINT16_C(   10), UINT16_C(    1), UINT16_C(    4), UINT16_C(    5), UINT16_C(   10), UINT16_C(    2) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint16x8_t a = simde_vld1q_u16(test_vec[i].a);
    simde_uint16x8_t r = simde_vclzq_u16(a);

    simde_test_arm_neon_assert_equal_u16x8(r, simde_vld1q_u16(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint16x8_t a = simde_test_arm_neon_random_u16x8();
    a = simde_vshlq_u16(a, simde_vnegq_s16(simde_vandq_s16(simde_test_arm_neon_random_i16x8(), simde_vdupq_n_s16(15))));
    if (i == 0) {
      a = simde_vsetq_lane_u16(UINT16_C(0), a, 0);
      a = simde_vsetq_lane_u16( UINT16_MAX, a, 1);
    }
    simde_uint16x8_t r = simde_vclzq_u16(a);

    simde_test_arm_neon_write_u16x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u16x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vclzq_u32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint32_t a[4];
    uint32_t r[4];
  } test_vec[] = {
    { { UINT32_C(         0),           UINT32_MAX, UINT32_C(     62094), UINT32_C( 456339214) },
      { UINT32_C(        32), UINT32_C(         0), UINT32_C(        16), UINT32_C(         3) } },
    { { UINT32_C(      4054), UINT32_C( 911429422), UINT32_C(         0), UINT32_C(    399294) },
      { UINT32_C(        20), UINT32_C(         2), UINT32_C(        32), UINT32_C(        13) } },
    { { UINT32_C(         7), UINT32_C(     11236), UINT32_C(        11), UINT32_C(    465108) },
      { UINT32_C(        29), UINT32_C(        18), UINT32_C(        28), UINT32_C(        13) } },
    { { UINT32_C(   2604114), UINT32_C(         3), UINT32_C(    237743), UINT32_C( 468898133) },
      { UINT32_C(        10), UINT32_C(        30), UINT32_C(        14), UINT32_C(         3) } },
    { { UINT32_C(     13205), UINT32_C(         6), UINT32_C( 984219941), UINT32_C(  10668962) },
      { UINT32_C(        18), UINT32_C(        29), UINT32_C(         2), UINT32_C(         8) } },
    { { UINT32_C(    750849), UINT32_C(   4307860), UINT32_C(  15522368), UINT32_C(    678060) },
      { UINT32_C(        12), UINT32_C(         9), UINT32_C(         8), UINT32_C(        12) } },
    { { UINT32_C(      3291), UINT32_C(      1005), UINT32_C(  14643902), UINT32_C(         7) },
      { UINT32_C(        20), UINT32_C(        22), UINT32_C(         8), UINT32_C(        29) } },
    { { UINT32_C(         5), UINT32_C(       188), UINT32_C(      4073), UINT32_C(         4) },
      { UINT32_C(        29), UINT32_C(        24), UINT32_C(        20), UINT32_C(        29) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint32x4_t a = simde_vld1q_u32(test_vec[i].a);
    simde_uint32x4_t r = simde_vclzq_u32(a);

    simde_test_arm_neon_assert_equal_u32x4(r, simde_vld1q_u32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint32x4_t a = simde_test_arm_neon_random_u32x4();
    a = simde_vshlq_u32(a, simde_vnegq_s32(simde_vandq_s32(simde_test_arm_neon_random_i32x4(), simde_vdupq_n_s32(31))));
    if (i == 0) {
      a = simde_vsetq_lane_u32(UINT32_C(0), a, 0);
      a = simde_vsetq_lane_u32( UINT32_MAX, a, 1);
    }
    simde_uint32x4_t r = simde_vclzq_u32(a);

    simde_test_arm_neon_write_u32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(x_vclzb_s8)
SIMDE_TEST_FUNC_LIST_ENTRY(x_vclzh_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(x_vclzs_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(x_vclzb_u8)
SIMDE_TEST_FUNC_LIST_ENTRY(x_vclzh_u16)
SIMDE_TEST_FUNC_LIST_ENTRY(x_vclzs_u32)

SIMDE_TEST_FUNC_LIST_ENTRY(vclz_s8)
SIMDE_TEST_FUNC_LIST_ENTRY(vclz_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vclz_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vclz_u8)
SIMDE_TEST_FUNC_LIST_ENTRY(vclz_u16)
SIMDE_TEST_FUNC_LIST_ENTRY(vclz_u32)

SIMDE_TEST_FUNC_LIST_ENTRY(vclzq_s8)
SIMDE_TEST_FUNC_LIST_ENTRY(vclzq_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vclzq_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vclzq_u8)
SIMDE_TEST_FUNC_LIST_ENTRY(vclzq_u16)
SIMDE_TEST_FUNC_LIST_ENTRY(vclzq_u32)
SIMDE_TEST_FUNC_LIST_END

#include "test-neon-footer.h"
