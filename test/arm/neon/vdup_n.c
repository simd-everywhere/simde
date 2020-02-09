/* Copyright (c) 2018-2019 Evan Nemerson <evan@nemerson.com>
 *
 * Permission is hereby granted, free of charge, to any person
 * obtaining a copy of this software and associated documentation
 * files (the "Software"), to deal in the Software without
 * restriction, including without limitation the rights to use, copy,
 * modify, merge, publish, distribute, sublicense, and/or sell copies
 * of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS
 * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN
 * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#define SIMDE_TESTS_CURRENT_NEON_OP dup
#include <test/arm/neon/test-neon-internal.h>
#include <simde/arm/neon.h>

#if defined(SIMDE_NEON_NATIVE) || defined(SIMDE_NO_NATIVE) || defined(SIMDE_ALWAYS_BUILD_NATIVE_TESTS)

static MunitResult
test_simde_vdup_n_s8(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    int8_t a;
    simde_int8x8_t r;
  } test_vec[8] = {
    { INT8_C( -78),
      simde_x_vload_s8(INT8_C( -78), INT8_C( -78), INT8_C( -78), INT8_C( -78),
                       INT8_C( -78), INT8_C( -78), INT8_C( -78), INT8_C( -78)) },
    { INT8_C( -88),
      simde_x_vload_s8(INT8_C( -88), INT8_C( -88), INT8_C( -88), INT8_C( -88),
                       INT8_C( -88), INT8_C( -88), INT8_C( -88), INT8_C( -88)) },
    { INT8_C( -61),
      simde_x_vload_s8(INT8_C( -61), INT8_C( -61), INT8_C( -61), INT8_C( -61),
                       INT8_C( -61), INT8_C( -61), INT8_C( -61), INT8_C( -61)) },
    { INT8_C( -26),
      simde_x_vload_s8(INT8_C( -26), INT8_C( -26), INT8_C( -26), INT8_C( -26),
                       INT8_C( -26), INT8_C( -26), INT8_C( -26), INT8_C( -26)) },
    { INT8_C(  67),
      simde_x_vload_s8(INT8_C(  67), INT8_C(  67), INT8_C(  67), INT8_C(  67),
                       INT8_C(  67), INT8_C(  67), INT8_C(  67), INT8_C(  67)) },
    { INT8_C(  63),
      simde_x_vload_s8(INT8_C(  63), INT8_C(  63), INT8_C(  63), INT8_C(  63),
                       INT8_C(  63), INT8_C(  63), INT8_C(  63), INT8_C(  63)) },
    { INT8_C( -72),
      simde_x_vload_s8(INT8_C( -72), INT8_C( -72), INT8_C( -72), INT8_C( -72),
                       INT8_C( -72), INT8_C( -72), INT8_C( -72), INT8_C( -72)) },
    { INT8_C(  78),
      simde_x_vload_s8(INT8_C(  78), INT8_C(  78), INT8_C(  78), INT8_C(  78),
                       INT8_C(  78), INT8_C(  78), INT8_C(  78), INT8_C(  78)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_int8x8_t r = simde_vdup_n_s8(test_vec[i].a);
    simde_neon_assert_int8x8(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_vdup_n_s16(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    int16_t a;
    simde_int16x4_t r;
  } test_vec[8] = {
    { INT16_C( -1865),
      simde_x_vload_s16(INT16_C( -1865), INT16_C( -1865), INT16_C( -1865), INT16_C( -1865)) },
    { INT16_C( 27689),
      simde_x_vload_s16(INT16_C( 27689), INT16_C( 27689), INT16_C( 27689), INT16_C( 27689)) },
    { INT16_C(-10330),
      simde_x_vload_s16(INT16_C(-10330), INT16_C(-10330), INT16_C(-10330), INT16_C(-10330)) },
    { INT16_C(  5744),
      simde_x_vload_s16(INT16_C(  5744), INT16_C(  5744), INT16_C(  5744), INT16_C(  5744)) },
    { INT16_C( 18577),
      simde_x_vload_s16(INT16_C( 18577), INT16_C( 18577), INT16_C( 18577), INT16_C( 18577)) },
    { INT16_C(  4051),
      simde_x_vload_s16(INT16_C(  4051), INT16_C(  4051), INT16_C(  4051), INT16_C(  4051)) },
    { INT16_C(-16648),
      simde_x_vload_s16(INT16_C(-16648), INT16_C(-16648), INT16_C(-16648), INT16_C(-16648)) },
    { INT16_C( 10953),
      simde_x_vload_s16(INT16_C( 10953), INT16_C( 10953), INT16_C( 10953), INT16_C( 10953)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_int16x4_t r = simde_vdup_n_s16(test_vec[i].a);
    simde_neon_assert_int16x4(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_vdup_n_s32(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    int32_t a;
    simde_int32x2_t r;
  } test_vec[8] = {
    { INT32_C( 1916587522),
      simde_x_vload_s32(INT32_C( 1916587522), INT32_C( 1916587522)) },
    { INT32_C( 1768587922),
      simde_x_vload_s32(INT32_C( 1768587922), INT32_C( 1768587922)) },
    { INT32_C( -691487954),
      simde_x_vload_s32(INT32_C( -691487954), INT32_C( -691487954)) },
    { INT32_C(  543996952),
      simde_x_vload_s32(INT32_C(  543996952), INT32_C(  543996952)) },
    { INT32_C(-1169990649),
      simde_x_vload_s32(INT32_C(-1169990649), INT32_C(-1169990649)) },
    { INT32_C(  112382576),
      simde_x_vload_s32(INT32_C(  112382576), INT32_C(  112382576)) },
    { INT32_C(  106559916),
      simde_x_vload_s32(INT32_C(  106559916), INT32_C(  106559916)) },
    { INT32_C(-1392833028),
      simde_x_vload_s32(INT32_C(-1392833028), INT32_C(-1392833028)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_int32x2_t r = simde_vdup_n_s32(test_vec[i].a);
    simde_neon_assert_int32x2(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_vdup_n_s64(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    int64_t a;
    simde_int64x1_t r;
  } test_vec[8] = {
    { INT64_C(  334131234436610929),
      simde_x_vload_s64(INT64_C(  334131234436610929)) },
    { INT64_C( -381209590406960721),
      simde_x_vload_s64(INT64_C( -381209590406960721)) },
    { INT64_C( 3405124667411469289),
      simde_x_vload_s64(INT64_C( 3405124667411469289)) },
    { INT64_C( 6563288036870666397),
      simde_x_vload_s64(INT64_C( 6563288036870666397)) },
    { INT64_C(-2481307072264039015),
      simde_x_vload_s64(INT64_C(-2481307072264039015)) },
    { INT64_C( 9161860841737114354),
      simde_x_vload_s64(INT64_C( 9161860841737114354)) },
    { INT64_C( 8226355109123244726),
      simde_x_vload_s64(INT64_C( 8226355109123244726)) },
    { INT64_C(-6469854538759863639),
      simde_x_vload_s64(INT64_C(-6469854538759863639)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_int64x1_t r = simde_vdup_n_s64(test_vec[i].a);
    simde_neon_assert_int64x1(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_vdup_n_u8(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    uint8_t a;
    simde_uint8x8_t r;
  } test_vec[8] = {
    { UINT8_C(208),
      simde_x_vload_u8(UINT8_C(208), UINT8_C(208), UINT8_C(208), UINT8_C(208),
                       UINT8_C(208), UINT8_C(208), UINT8_C(208), UINT8_C(208)) },
    { UINT8_C( 37),
      simde_x_vload_u8(UINT8_C( 37), UINT8_C( 37), UINT8_C( 37), UINT8_C( 37),
                       UINT8_C( 37), UINT8_C( 37), UINT8_C( 37), UINT8_C( 37)) },
    { UINT8_C(154),
      simde_x_vload_u8(UINT8_C(154), UINT8_C(154), UINT8_C(154), UINT8_C(154),
                       UINT8_C(154), UINT8_C(154), UINT8_C(154), UINT8_C(154)) },
    { UINT8_C(109),
      simde_x_vload_u8(UINT8_C(109), UINT8_C(109), UINT8_C(109), UINT8_C(109),
                       UINT8_C(109), UINT8_C(109), UINT8_C(109), UINT8_C(109)) },
    { UINT8_C(202),
      simde_x_vload_u8(UINT8_C(202), UINT8_C(202), UINT8_C(202), UINT8_C(202),
                       UINT8_C(202), UINT8_C(202), UINT8_C(202), UINT8_C(202)) },
    { UINT8_C( 54),
      simde_x_vload_u8(UINT8_C( 54), UINT8_C( 54), UINT8_C( 54), UINT8_C( 54),
                       UINT8_C( 54), UINT8_C( 54), UINT8_C( 54), UINT8_C( 54)) },
    { UINT8_C( 84),
      simde_x_vload_u8(UINT8_C( 84), UINT8_C( 84), UINT8_C( 84), UINT8_C( 84),
                       UINT8_C( 84), UINT8_C( 84), UINT8_C( 84), UINT8_C( 84)) },
    { UINT8_C(241),
      simde_x_vload_u8(UINT8_C(241), UINT8_C(241), UINT8_C(241), UINT8_C(241),
                       UINT8_C(241), UINT8_C(241), UINT8_C(241), UINT8_C(241)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_uint8x8_t r = simde_vdup_n_u8(test_vec[i].a);
    simde_neon_assert_uint8x8(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_vdup_n_u16(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    uint16_t a;
    simde_uint16x4_t r;
  } test_vec[8] = {
    { UINT16_C( 7975),
      simde_x_vload_u16(UINT16_C( 7975), UINT16_C( 7975), UINT16_C( 7975), UINT16_C( 7975)) },
    { UINT16_C(47599),
      simde_x_vload_u16(UINT16_C(47599), UINT16_C(47599), UINT16_C(47599), UINT16_C(47599)) },
    { UINT16_C(18065),
      simde_x_vload_u16(UINT16_C(18065), UINT16_C(18065), UINT16_C(18065), UINT16_C(18065)) },
    { UINT16_C(57574),
      simde_x_vload_u16(UINT16_C(57574), UINT16_C(57574), UINT16_C(57574), UINT16_C(57574)) },
    { UINT16_C(26215),
      simde_x_vload_u16(UINT16_C(26215), UINT16_C(26215), UINT16_C(26215), UINT16_C(26215)) },
    { UINT16_C(25160),
      simde_x_vload_u16(UINT16_C(25160), UINT16_C(25160), UINT16_C(25160), UINT16_C(25160)) },
    { UINT16_C(15997),
      simde_x_vload_u16(UINT16_C(15997), UINT16_C(15997), UINT16_C(15997), UINT16_C(15997)) },
    { UINT16_C(10837),
      simde_x_vload_u16(UINT16_C(10837), UINT16_C(10837), UINT16_C(10837), UINT16_C(10837)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_uint16x4_t r = simde_vdup_n_u16(test_vec[i].a);
    simde_neon_assert_uint16x4(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_vdup_n_u32(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    uint32_t a;
    simde_uint32x2_t r;
  } test_vec[8] = {
    { UINT32_C(2191554300),
      simde_x_vload_u32(UINT32_C(2191554300), UINT32_C(2191554300)) },
    { UINT32_C(3680691148),
      simde_x_vload_u32(UINT32_C(3680691148), UINT32_C(3680691148)) },
    { UINT32_C(1032348780),
      simde_x_vload_u32(UINT32_C(1032348780), UINT32_C(1032348780)) },
    { UINT32_C(2246539900),
      simde_x_vload_u32(UINT32_C(2246539900), UINT32_C(2246539900)) },
    { UINT32_C(1509373219),
      simde_x_vload_u32(UINT32_C(1509373219), UINT32_C(1509373219)) },
    { UINT32_C(3567484403),
      simde_x_vload_u32(UINT32_C(3567484403), UINT32_C(3567484403)) },
    { UINT32_C(1519121594),
      simde_x_vload_u32(UINT32_C(1519121594), UINT32_C(1519121594)) },
    { UINT32_C(2118894533),
      simde_x_vload_u32(UINT32_C(2118894533), UINT32_C(2118894533)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_uint32x2_t r = simde_vdup_n_u32(test_vec[i].a);
    simde_neon_assert_uint32x2(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_vdup_n_u64(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    uint64_t a;
    simde_uint64x1_t r;
  } test_vec[8] = {
    { UINT64_C(9284230750851825515),
      simde_x_vload_u64(UINT64_C(9284230750851825515)) },
    { UINT64_C(1047137957001313899),
      simde_x_vload_u64(UINT64_C(1047137957001313899)) },
    { UINT64_C(6667637795209568306),
      simde_x_vload_u64(UINT64_C(6667637795209568306)) },
    { UINT64_C(13739307323863797778),
      simde_x_vload_u64(UINT64_C(13739307323863797778)) },
    { UINT64_C(3093886915367912862),
      simde_x_vload_u64(UINT64_C(3093886915367912862)) },
    { UINT64_C(9010151081532470036),
      simde_x_vload_u64(UINT64_C(9010151081532470036)) },
    { UINT64_C(13460085984077414991),
      simde_x_vload_u64(UINT64_C(13460085984077414991)) },
    { UINT64_C(18082508431338632924),
      simde_x_vload_u64(UINT64_C(18082508431338632924)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_uint64x1_t r = simde_vdup_n_u64(test_vec[i].a);
    simde_neon_assert_uint64x1(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_vdup_n_f32(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde_float32 a;
    simde_float32x2_t r;
  } test_vec[8] = {
    { SIMDE_FLOAT32_C( -324.45),
      simde_x_vload_f32(SIMDE_FLOAT32_C( -324.45), SIMDE_FLOAT32_C( -324.45)) },
    { SIMDE_FLOAT32_C(  705.22),
      simde_x_vload_f32(SIMDE_FLOAT32_C(  705.22), SIMDE_FLOAT32_C(  705.22)) },
    { SIMDE_FLOAT32_C( -996.79),
      simde_x_vload_f32(SIMDE_FLOAT32_C( -996.79), SIMDE_FLOAT32_C( -996.79)) },
    { SIMDE_FLOAT32_C(  843.74),
      simde_x_vload_f32(SIMDE_FLOAT32_C(  843.74), SIMDE_FLOAT32_C(  843.74)) },
    { SIMDE_FLOAT32_C(  946.70),
      simde_x_vload_f32(SIMDE_FLOAT32_C(  946.70), SIMDE_FLOAT32_C(  946.70)) },
    { SIMDE_FLOAT32_C(  387.10),
      simde_x_vload_f32(SIMDE_FLOAT32_C(  387.10), SIMDE_FLOAT32_C(  387.10)) },
    { SIMDE_FLOAT32_C( -613.17),
      simde_x_vload_f32(SIMDE_FLOAT32_C( -613.17), SIMDE_FLOAT32_C( -613.17)) },
    { SIMDE_FLOAT32_C(  182.49),
      simde_x_vload_f32(SIMDE_FLOAT32_C(  182.49), SIMDE_FLOAT32_C(  182.49)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_float32x2_t r = simde_vdup_n_f32(test_vec[i].a);
    simde_neon_assert_float32x2_equal(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_vdup_n_f64(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde_float64 a;
    simde_float64x1_t r;
  } test_vec[8] = {
    { SIMDE_FLOAT64_C( -545.91),
      simde_x_vload_f64(SIMDE_FLOAT64_C( -545.91)) },
    { SIMDE_FLOAT64_C( -308.32),
      simde_x_vload_f64(SIMDE_FLOAT64_C( -308.32)) },
    { SIMDE_FLOAT64_C( -309.58),
      simde_x_vload_f64(SIMDE_FLOAT64_C( -309.58)) },
    { SIMDE_FLOAT64_C(  472.89),
      simde_x_vload_f64(SIMDE_FLOAT64_C(  472.89)) },
    { SIMDE_FLOAT64_C(   94.81),
      simde_x_vload_f64(SIMDE_FLOAT64_C(   94.81)) },
    { SIMDE_FLOAT64_C(  -37.15),
      simde_x_vload_f64(SIMDE_FLOAT64_C(  -37.15)) },
    { SIMDE_FLOAT64_C( -245.92),
      simde_x_vload_f64(SIMDE_FLOAT64_C( -245.92)) },
    { SIMDE_FLOAT64_C(  363.91),
      simde_x_vload_f64(SIMDE_FLOAT64_C(  363.91)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_float64x1_t r = simde_vdup_n_f64(test_vec[i].a);
    simde_neon_assert_float64x1_equal(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_vdupq_n_s8(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    int8_t a;
    simde_int8x16_t r;
  } test_vec[8] = {
    { INT8_C(  15),
      simde_x_vloadq_s8(INT8_C(  15), INT8_C(  15), INT8_C(  15), INT8_C(  15),
			INT8_C(  15), INT8_C(  15), INT8_C(  15), INT8_C(  15),
			INT8_C(  15), INT8_C(  15), INT8_C(  15), INT8_C(  15),
			INT8_C(  15), INT8_C(  15), INT8_C(  15), INT8_C(  15)) },
    { INT8_C( 125),
      simde_x_vloadq_s8(INT8_C( 125), INT8_C( 125), INT8_C( 125), INT8_C( 125),
			INT8_C( 125), INT8_C( 125), INT8_C( 125), INT8_C( 125),
			INT8_C( 125), INT8_C( 125), INT8_C( 125), INT8_C( 125),
			INT8_C( 125), INT8_C( 125), INT8_C( 125), INT8_C( 125)) },
    { INT8_C( -71),
      simde_x_vloadq_s8(INT8_C( -71), INT8_C( -71), INT8_C( -71), INT8_C( -71),
			INT8_C( -71), INT8_C( -71), INT8_C( -71), INT8_C( -71),
			INT8_C( -71), INT8_C( -71), INT8_C( -71), INT8_C( -71),
			INT8_C( -71), INT8_C( -71), INT8_C( -71), INT8_C( -71)) },
    { INT8_C(  -4),
      simde_x_vloadq_s8(INT8_C(  -4), INT8_C(  -4), INT8_C(  -4), INT8_C(  -4),
			INT8_C(  -4), INT8_C(  -4), INT8_C(  -4), INT8_C(  -4),
			INT8_C(  -4), INT8_C(  -4), INT8_C(  -4), INT8_C(  -4),
			INT8_C(  -4), INT8_C(  -4), INT8_C(  -4), INT8_C(  -4)) },
    { INT8_C(  18),
      simde_x_vloadq_s8(INT8_C(  18), INT8_C(  18), INT8_C(  18), INT8_C(  18),
			INT8_C(  18), INT8_C(  18), INT8_C(  18), INT8_C(  18),
			INT8_C(  18), INT8_C(  18), INT8_C(  18), INT8_C(  18),
			INT8_C(  18), INT8_C(  18), INT8_C(  18), INT8_C(  18)) },
    { INT8_C( -97),
      simde_x_vloadq_s8(INT8_C( -97), INT8_C( -97), INT8_C( -97), INT8_C( -97),
			INT8_C( -97), INT8_C( -97), INT8_C( -97), INT8_C( -97),
			INT8_C( -97), INT8_C( -97), INT8_C( -97), INT8_C( -97),
			INT8_C( -97), INT8_C( -97), INT8_C( -97), INT8_C( -97)) },
    { INT8_C( -79),
      simde_x_vloadq_s8(INT8_C( -79), INT8_C( -79), INT8_C( -79), INT8_C( -79),
			INT8_C( -79), INT8_C( -79), INT8_C( -79), INT8_C( -79),
			INT8_C( -79), INT8_C( -79), INT8_C( -79), INT8_C( -79),
			INT8_C( -79), INT8_C( -79), INT8_C( -79), INT8_C( -79)) },
    { INT8_C( -96),
      simde_x_vloadq_s8(INT8_C( -96), INT8_C( -96), INT8_C( -96), INT8_C( -96),
			INT8_C( -96), INT8_C( -96), INT8_C( -96), INT8_C( -96),
			INT8_C( -96), INT8_C( -96), INT8_C( -96), INT8_C( -96),
			INT8_C( -96), INT8_C( -96), INT8_C( -96), INT8_C( -96)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_int8x16_t r = simde_vdupq_n_s8(test_vec[i].a);
    simde_neon_assert_int8x16(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_vdupq_n_s16(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    int16_t a;
    simde_int16x8_t r;
  } test_vec[8] = {
    { INT16_C(-18161),
      simde_x_vloadq_s16(INT16_C(-18161), INT16_C(-18161), INT16_C(-18161), INT16_C(-18161),
			 INT16_C(-18161), INT16_C(-18161), INT16_C(-18161), INT16_C(-18161)) },
    { INT16_C(  3453),
      simde_x_vloadq_s16(INT16_C(  3453), INT16_C(  3453), INT16_C(  3453), INT16_C(  3453),
			 INT16_C(  3453), INT16_C(  3453), INT16_C(  3453), INT16_C(  3453)) },
    { INT16_C( 26809),
      simde_x_vloadq_s16(INT16_C( 26809), INT16_C( 26809), INT16_C( 26809), INT16_C( 26809),
			 INT16_C( 26809), INT16_C( 26809), INT16_C( 26809), INT16_C( 26809)) },
    { INT16_C(-30468),
      simde_x_vloadq_s16(INT16_C(-30468), INT16_C(-30468), INT16_C(-30468), INT16_C(-30468),
			 INT16_C(-30468), INT16_C(-30468), INT16_C(-30468), INT16_C(-30468)) },
    { INT16_C(-32238),
      simde_x_vloadq_s16(INT16_C(-32238), INT16_C(-32238), INT16_C(-32238), INT16_C(-32238),
			 INT16_C(-32238), INT16_C(-32238), INT16_C(-32238), INT16_C(-32238)) },
    { INT16_C(-32609),
      simde_x_vloadq_s16(INT16_C(-32609), INT16_C(-32609), INT16_C(-32609), INT16_C(-32609),
			 INT16_C(-32609), INT16_C(-32609), INT16_C(-32609), INT16_C(-32609)) },
    { INT16_C(-15183),
      simde_x_vloadq_s16(INT16_C(-15183), INT16_C(-15183), INT16_C(-15183), INT16_C(-15183),
			 INT16_C(-15183), INT16_C(-15183), INT16_C(-15183), INT16_C(-15183)) },
    { INT16_C( 24224),
      simde_x_vloadq_s16(INT16_C( 24224), INT16_C( 24224), INT16_C( 24224), INT16_C( 24224),
			 INT16_C( 24224), INT16_C( 24224), INT16_C( 24224), INT16_C( 24224)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_int16x8_t r = simde_vdupq_n_s16(test_vec[i].a);
    simde_neon_assert_int16x8(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_vdupq_n_s32(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    int32_t a;
    simde_int32x4_t r;
  } test_vec[8] = {
    { INT32_C( -600721137),
      simde_x_vloadq_s32(INT32_C( -600721137), INT32_C( -600721137),
			 INT32_C( -600721137), INT32_C( -600721137)) },
    { INT32_C( 1437535613),
      simde_x_vloadq_s32(INT32_C( 1437535613), INT32_C( 1437535613),
			 INT32_C( 1437535613), INT32_C( 1437535613)) },
    { INT32_C(-1830983495),
      simde_x_vloadq_s32(INT32_C(-1830983495), INT32_C(-1830983495),
			 INT32_C(-1830983495), INT32_C(-1830983495)) },
    { INT32_C( 1662028028),
      simde_x_vloadq_s32(INT32_C( 1662028028), INT32_C( 1662028028),
			 INT32_C( 1662028028), INT32_C( 1662028028)) },
    { INT32_C(  735543826),
      simde_x_vloadq_s32(INT32_C(  735543826), INT32_C(  735543826),
			 INT32_C(  735543826), INT32_C(  735543826)) },
    { INT32_C( 1508081823),
      simde_x_vloadq_s32(INT32_C( 1508081823), INT32_C( 1508081823),
			 INT32_C( 1508081823), INT32_C( 1508081823)) },
    { INT32_C(  439469233),
      simde_x_vloadq_s32(INT32_C(  439469233), INT32_C(  439469233),
			 INT32_C(  439469233), INT32_C(  439469233)) },
    { INT32_C( -524525920),
      simde_x_vloadq_s32(INT32_C( -524525920), INT32_C( -524525920),
			 INT32_C( -524525920), INT32_C( -524525920)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_int32x4_t r = simde_vdupq_n_s32(test_vec[i].a);
    simde_neon_assert_int32x4(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_vdupq_n_s64(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    int64_t a;
    simde_int64x2_t r;
  } test_vec[8] = {
    { INT64_C( 6174168448364558607),
      simde_x_vloadq_s64(INT64_C( 6174168448364558607), INT64_C( 6174168448364558607)) },
    { INT64_C( 7138356027759356089),
      simde_x_vloadq_s64(INT64_C( 7138356027759356089), INT64_C( 7138356027759356089)) },
    { INT64_C( 6477162110212604434),
      simde_x_vloadq_s64(INT64_C( 6477162110212604434), INT64_C( 6477162110212604434)) },
    { INT64_C(-2252821671864843087),
      simde_x_vloadq_s64(INT64_C(-2252821671864843087), INT64_C(-2252821671864843087)) },
    { INT64_C( -556506427644455564),
      simde_x_vloadq_s64(INT64_C( -556506427644455564), INT64_C( -556506427644455564)) },
    { INT64_C( 2313226981968176270),
      simde_x_vloadq_s64(INT64_C( 2313226981968176270), INT64_C( 2313226981968176270)) },
    { INT64_C(-5078103753510275894),
      simde_x_vloadq_s64(INT64_C(-5078103753510275894), INT64_C(-5078103753510275894)) },
    { INT64_C(-8872623523915285054),
      simde_x_vloadq_s64(INT64_C(-8872623523915285054), INT64_C(-8872623523915285054)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_int64x2_t r = simde_vdupq_n_s64(test_vec[i].a);
    simde_neon_assert_int64x2(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_vdupq_n_u8(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    uint8_t a;
    simde_uint8x16_t r;
  } test_vec[8] = {
    { UINT8_C(206),
      simde_x_vloadq_u8(UINT8_C(206), UINT8_C(206), UINT8_C(206), UINT8_C(206),
                        UINT8_C(206), UINT8_C(206), UINT8_C(206), UINT8_C(206),
                        UINT8_C(206), UINT8_C(206), UINT8_C(206), UINT8_C(206),
                        UINT8_C(206), UINT8_C(206), UINT8_C(206), UINT8_C(206) ) },
    { UINT8_C(135),
      simde_x_vloadq_u8(UINT8_C(135), UINT8_C(135), UINT8_C(135), UINT8_C(135),
                        UINT8_C(135), UINT8_C(135), UINT8_C(135), UINT8_C(135),
                        UINT8_C(135), UINT8_C(135), UINT8_C(135), UINT8_C(135),
                        UINT8_C(135), UINT8_C(135), UINT8_C(135), UINT8_C(135) ) },
    { UINT8_C(116),
      simde_x_vloadq_u8(UINT8_C(116), UINT8_C(116), UINT8_C(116), UINT8_C(116),
                        UINT8_C(116), UINT8_C(116), UINT8_C(116), UINT8_C(116),
                        UINT8_C(116), UINT8_C(116), UINT8_C(116), UINT8_C(116),
                        UINT8_C(116), UINT8_C(116), UINT8_C(116), UINT8_C(116) ) },
    { UINT8_C(154),
      simde_x_vloadq_u8(UINT8_C(154), UINT8_C(154), UINT8_C(154), UINT8_C(154),
                        UINT8_C(154), UINT8_C(154), UINT8_C(154), UINT8_C(154),
                        UINT8_C(154), UINT8_C(154), UINT8_C(154), UINT8_C(154),
                        UINT8_C(154), UINT8_C(154), UINT8_C(154), UINT8_C(154) ) },
    { UINT8_C(166),
      simde_x_vloadq_u8(UINT8_C(166), UINT8_C(166), UINT8_C(166), UINT8_C(166),
                        UINT8_C(166), UINT8_C(166), UINT8_C(166), UINT8_C(166),
                        UINT8_C(166), UINT8_C(166), UINT8_C(166), UINT8_C(166),
                        UINT8_C(166), UINT8_C(166), UINT8_C(166), UINT8_C(166) ) },
    { UINT8_C( 29),
      simde_x_vloadq_u8(UINT8_C( 29), UINT8_C( 29), UINT8_C( 29), UINT8_C( 29),
                        UINT8_C( 29), UINT8_C( 29), UINT8_C( 29), UINT8_C( 29),
                        UINT8_C( 29), UINT8_C( 29), UINT8_C( 29), UINT8_C( 29),
                        UINT8_C( 29), UINT8_C( 29), UINT8_C( 29), UINT8_C( 29) ) },
    { UINT8_C(241),
      simde_x_vloadq_u8(UINT8_C(241), UINT8_C(241), UINT8_C(241), UINT8_C(241),
                        UINT8_C(241), UINT8_C(241), UINT8_C(241), UINT8_C(241),
                        UINT8_C(241), UINT8_C(241), UINT8_C(241), UINT8_C(241),
                        UINT8_C(241), UINT8_C(241), UINT8_C(241), UINT8_C(241) ) },
    { UINT8_C( 37),
      simde_x_vloadq_u8(UINT8_C( 37), UINT8_C( 37), UINT8_C( 37), UINT8_C( 37),
                        UINT8_C( 37), UINT8_C( 37), UINT8_C( 37), UINT8_C( 37),
                        UINT8_C( 37), UINT8_C( 37), UINT8_C( 37), UINT8_C( 37),
                        UINT8_C( 37), UINT8_C( 37), UINT8_C( 37), UINT8_C( 37) ) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_uint8x16_t r = simde_vdupq_n_u8(test_vec[i].a);
    simde_neon_assert_uint8x16(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_vdupq_n_u16(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    uint16_t a;
    simde_uint16x8_t r;
  } test_vec[8] = {
    { UINT16_C(45182),
      simde_x_vloadq_u16(UINT16_C(45182), UINT16_C(45182), UINT16_C(45182), UINT16_C(45182),
                         UINT16_C(45182), UINT16_C(45182), UINT16_C(45182), UINT16_C(45182)) },
    { UINT16_C(31361),
      simde_x_vloadq_u16(UINT16_C(31361), UINT16_C(31361), UINT16_C(31361), UINT16_C(31361),
                         UINT16_C(31361), UINT16_C(31361), UINT16_C(31361), UINT16_C(31361)) },
    { UINT16_C( 4643),
      simde_x_vloadq_u16(UINT16_C( 4643), UINT16_C( 4643), UINT16_C( 4643), UINT16_C( 4643),
                         UINT16_C( 4643), UINT16_C( 4643), UINT16_C( 4643), UINT16_C( 4643)) },
    { UINT16_C(25762),
      simde_x_vloadq_u16(UINT16_C(25762), UINT16_C(25762), UINT16_C(25762), UINT16_C(25762),
                         UINT16_C(25762), UINT16_C(25762), UINT16_C(25762), UINT16_C(25762)) },
    { UINT16_C(26213),
      simde_x_vloadq_u16(UINT16_C(26213), UINT16_C(26213), UINT16_C(26213), UINT16_C(26213),
                         UINT16_C(26213), UINT16_C(26213), UINT16_C(26213), UINT16_C(26213)) },
    { UINT16_C(11045),
      simde_x_vloadq_u16(UINT16_C(11045), UINT16_C(11045), UINT16_C(11045), UINT16_C(11045),
                         UINT16_C(11045), UINT16_C(11045), UINT16_C(11045), UINT16_C(11045)) },
    { UINT16_C(56313),
      simde_x_vloadq_u16(UINT16_C(56313), UINT16_C(56313), UINT16_C(56313), UINT16_C(56313),
                         UINT16_C(56313), UINT16_C(56313), UINT16_C(56313), UINT16_C(56313)) },
    { UINT16_C( 1055),
      simde_x_vloadq_u16(UINT16_C( 1055), UINT16_C( 1055), UINT16_C( 1055), UINT16_C( 1055),
                         UINT16_C( 1055), UINT16_C( 1055), UINT16_C( 1055), UINT16_C( 1055)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_uint16x8_t r = simde_vdupq_n_u16(test_vec[i].a);
    simde_neon_assert_uint16x8(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_vdupq_n_u32(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    uint32_t a;
    simde_uint32x4_t r;
  } test_vec[8] = {
    { UINT32_C(3205406207),
      simde_x_vloadq_u32(UINT32_C(3205406207), UINT32_C(3205406207),
                         UINT32_C(3205406207), UINT32_C(3205406207)) },
    { UINT32_C(2641608279),
      simde_x_vloadq_u32(UINT32_C(2641608279), UINT32_C(2641608279),
                         UINT32_C(2641608279), UINT32_C(2641608279)) },
    { UINT32_C(     69583),
      simde_x_vloadq_u32(UINT32_C(     69583), UINT32_C(     69583),
                         UINT32_C(     69583), UINT32_C(     69583)) },
    { UINT32_C(1363136797),
      simde_x_vloadq_u32(UINT32_C(1363136797), UINT32_C(1363136797),
                         UINT32_C(1363136797), UINT32_C(1363136797)) },
    { UINT32_C(1146760842),
      simde_x_vloadq_u32(UINT32_C(1146760842), UINT32_C(1146760842),
                         UINT32_C(1146760842), UINT32_C(1146760842)) },
    { UINT32_C(3800978822),
      simde_x_vloadq_u32(UINT32_C(3800978822), UINT32_C(3800978822),
                         UINT32_C(3800978822), UINT32_C(3800978822)) },
    { UINT32_C( 414287630),
      simde_x_vloadq_u32(UINT32_C( 414287630), UINT32_C( 414287630),
                         UINT32_C( 414287630), UINT32_C( 414287630)) },
    { UINT32_C(1867338402),
      simde_x_vloadq_u32(UINT32_C(1867338402), UINT32_C(1867338402),
                         UINT32_C(1867338402), UINT32_C(1867338402)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_uint32x4_t r = simde_vdupq_n_u32(test_vec[i].a);
    simde_neon_assert_uint32x4(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_vdupq_n_u64(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    uint64_t a;
    simde_uint64x2_t r;
  } test_vec[8] = {
    { UINT64_C(3848393335905724000),
      simde_x_vloadq_u64(UINT64_C(3848393335905724000), UINT64_C(3848393335905724000)) },
    { UINT64_C(7521514816403184111),
      simde_x_vloadq_u64(UINT64_C(7521514816403184111), UINT64_C(7521514816403184111)) },
    { UINT64_C(10503742284511346378),
      simde_x_vloadq_u64(UINT64_C(10503742284511346378), UINT64_C(10503742284511346378)) },
    { UINT64_C(3888914191608226801),
      simde_x_vloadq_u64(UINT64_C(3888914191608226801), UINT64_C(3888914191608226801)) },
    { UINT64_C(10404224794072508643),
      simde_x_vloadq_u64(UINT64_C(10404224794072508643), UINT64_C(10404224794072508643)) },
    { UINT64_C(6148912474229806797),
      simde_x_vloadq_u64(UINT64_C(6148912474229806797), UINT64_C(6148912474229806797)) },
    { UINT64_C(6257259334766132716),
      simde_x_vloadq_u64(UINT64_C(6257259334766132716), UINT64_C(6257259334766132716)) },
    { UINT64_C(6904870949189420238),
      simde_x_vloadq_u64(UINT64_C(6904870949189420238), UINT64_C(6904870949189420238)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_uint64x2_t r = simde_vdupq_n_u64(test_vec[i].a);
    simde_neon_assert_uint64x2(r, ==, test_vec[i].r);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_vdupq_n_f32(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde_float32 a;
    simde_float32x4_t r;
  } test_vec[8] = {
    { SIMDE_FLOAT32_C(  202.87),
      simde_x_vloadq_f32(SIMDE_FLOAT32_C(  202.87), SIMDE_FLOAT32_C(  202.87),
                         SIMDE_FLOAT32_C(  202.87), SIMDE_FLOAT32_C(  202.87)) },
    { SIMDE_FLOAT32_C(  673.43),
      simde_x_vloadq_f32(SIMDE_FLOAT32_C(  673.43), SIMDE_FLOAT32_C(  673.43),
                         SIMDE_FLOAT32_C(  673.43), SIMDE_FLOAT32_C(  673.43)) },
    { SIMDE_FLOAT32_C( -450.12),
      simde_x_vloadq_f32(SIMDE_FLOAT32_C( -450.12), SIMDE_FLOAT32_C( -450.12),
                         SIMDE_FLOAT32_C( -450.12), SIMDE_FLOAT32_C( -450.12)) },
    { SIMDE_FLOAT32_C(   35.07),
      simde_x_vloadq_f32(SIMDE_FLOAT32_C(   35.07), SIMDE_FLOAT32_C(   35.07),
                         SIMDE_FLOAT32_C(   35.07), SIMDE_FLOAT32_C(   35.07)) },
    { SIMDE_FLOAT32_C(  403.71),
      simde_x_vloadq_f32(SIMDE_FLOAT32_C(  403.71), SIMDE_FLOAT32_C(  403.71),
                         SIMDE_FLOAT32_C(  403.71), SIMDE_FLOAT32_C(  403.71)) },
    { SIMDE_FLOAT32_C(  332.31),
      simde_x_vloadq_f32(SIMDE_FLOAT32_C(  332.31), SIMDE_FLOAT32_C(  332.31),
                         SIMDE_FLOAT32_C(  332.31), SIMDE_FLOAT32_C(  332.31)) },
    { SIMDE_FLOAT32_C( -965.58),
      simde_x_vloadq_f32(SIMDE_FLOAT32_C( -965.58), SIMDE_FLOAT32_C( -965.58),
                         SIMDE_FLOAT32_C( -965.58), SIMDE_FLOAT32_C( -965.58)) },
    { SIMDE_FLOAT32_C( -646.22),
      simde_x_vloadq_f32(SIMDE_FLOAT32_C( -646.22), SIMDE_FLOAT32_C( -646.22),
                         SIMDE_FLOAT32_C( -646.22), SIMDE_FLOAT32_C( -646.22)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_float32x4_t r = simde_vdupq_n_f32(test_vec[i].a);
    simde_neon_assert_float32x4_equal(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

static MunitResult
test_simde_vdupq_n_f64(const MunitParameter params[], void* data) {
  (void) params;
  (void) data;

  const struct {
    simde_float64 a;
    simde_float64x2_t r;
  } test_vec[8] = {
    { SIMDE_FLOAT64_C(  384.02),
      simde_x_vloadq_f64(SIMDE_FLOAT64_C(  384.02), SIMDE_FLOAT64_C(  384.02)) },
    { SIMDE_FLOAT64_C(  -82.35),
      simde_x_vloadq_f64(SIMDE_FLOAT64_C(  -82.35), SIMDE_FLOAT64_C(  -82.35)) },
    { SIMDE_FLOAT64_C( -747.51),
      simde_x_vloadq_f64(SIMDE_FLOAT64_C( -747.51), SIMDE_FLOAT64_C( -747.51)) },
    { SIMDE_FLOAT64_C(  819.29),
      simde_x_vloadq_f64(SIMDE_FLOAT64_C(  819.29), SIMDE_FLOAT64_C(  819.29)) },
    { SIMDE_FLOAT64_C( -252.78),
      simde_x_vloadq_f64(SIMDE_FLOAT64_C( -252.78), SIMDE_FLOAT64_C( -252.78)) },
    { SIMDE_FLOAT64_C( -146.98),
      simde_x_vloadq_f64(SIMDE_FLOAT64_C( -146.98), SIMDE_FLOAT64_C( -146.98)) },
    { SIMDE_FLOAT64_C(  148.38),
      simde_x_vloadq_f64(SIMDE_FLOAT64_C(  148.38), SIMDE_FLOAT64_C(  148.38)) },
    { SIMDE_FLOAT64_C(  401.85),
      simde_x_vloadq_f64(SIMDE_FLOAT64_C(  401.85), SIMDE_FLOAT64_C(  401.85)) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_float64x2_t r = simde_vdupq_n_f64(test_vec[i].a);
    simde_neon_assert_float64x2_equal(r, test_vec[i].r, 1);
  }

  return MUNIT_OK;
}

#endif /* defined(SIMDE_NEON_NATIVE) || defined(SIMDE_NO_NATIVE) || defined(SIMDE_ALWAYS_BUILD_NATIVE_TESTS) */

HEDLEY_DIAGNOSTIC_PUSH
HEDLEY_DIAGNOSTIC_DISABLE_CAST_QUAL

static MunitTest test_suite_tests[] = {
#if defined(SIMDE_NEON_NATIVE) || defined(SIMDE_NO_NATIVE) || defined(SIMDE_ALWAYS_BUILD_NATIVE_TESTS)
  SIMDE_TESTS_NEON_DEFINE_TEST(n_s8),
  SIMDE_TESTS_NEON_DEFINE_TEST(n_s16),
  SIMDE_TESTS_NEON_DEFINE_TEST(n_s32),
  SIMDE_TESTS_NEON_DEFINE_TEST(n_s64),
  SIMDE_TESTS_NEON_DEFINE_TEST(n_u8),
  SIMDE_TESTS_NEON_DEFINE_TEST(n_u16),
  SIMDE_TESTS_NEON_DEFINE_TEST(n_u32),
  SIMDE_TESTS_NEON_DEFINE_TEST(n_u64),
  SIMDE_TESTS_NEON_DEFINE_TEST(n_f32),
  SIMDE_TESTS_NEON_DEFINE_TEST(n_f64),

  SIMDE_TESTS_NEON_DEFINE_TEST_FULL(q, n_s8),
  SIMDE_TESTS_NEON_DEFINE_TEST_FULL(q, n_s16),
  SIMDE_TESTS_NEON_DEFINE_TEST_FULL(q, n_s32),
  SIMDE_TESTS_NEON_DEFINE_TEST_FULL(q, n_s64),
  SIMDE_TESTS_NEON_DEFINE_TEST_FULL(q, n_u8),
  SIMDE_TESTS_NEON_DEFINE_TEST_FULL(q, n_u16),
  SIMDE_TESTS_NEON_DEFINE_TEST_FULL(q, n_u32),
  SIMDE_TESTS_NEON_DEFINE_TEST_FULL(q, n_u64),
  SIMDE_TESTS_NEON_DEFINE_TEST_FULL(q, n_f32),
  SIMDE_TESTS_NEON_DEFINE_TEST_FULL(q, n_f64),
#endif /* defined(SIMDE_NEON_NATIVE) || defined(SIMDE_NO_NATIVE) || defined(SIMDE_ALWAYS_BUILD_NATIVE_TESTS) */

  { NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL }
};

HEDLEY_C_DECL MunitSuite* SIMDE_TESTS_GENERATE_SYMBOL(SIMDE_TESTS_CURRENT_NEON_OP)(void) {
  static MunitSuite suite = { (char*) "/v" HEDLEY_STRINGIFY(SIMDE_TESTS_CURRENT_NEON_OP), test_suite_tests, NULL, 1, MUNIT_SUITE_OPTION_NONE };

  return &suite;
}

HEDLEY_DIAGNOSTIC_POP
