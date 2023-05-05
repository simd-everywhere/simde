#define SIMDE_TEST_ARM_NEON_INSN bsl

#include "test-neon.h"
#include "../../../simde/arm/neon/bsl.h"

static int
test_simde_vbsl_f16 (SIMDE_MUNIT_TEST_ARGS) {
  #if 1
    struct {
      uint16_t a[4];
      simde_float16 b[4];
      simde_float16 c[4];
      simde_float16 r[4];
    } test_vec[] = {
    #if !defined(SIMDE_FAST_MATH)
    { { UINT16_C(18704), UINT16_C(47545), UINT16_C( 6410), UINT16_C(57433) },
      { SIMDE_FLOAT16_VALUE(  -614.50), SIMDE_FLOAT16_VALUE(  -671.50), SIMDE_FLOAT16_VALUE(  -876.00), SIMDE_FLOAT16_VALUE(   515.00) },
      { SIMDE_FLOAT16_VALUE(  -446.00), SIMDE_FLOAT16_VALUE(   385.00), SIMDE_FLOAT16_VALUE(  -263.00), SIMDE_FLOAT16_VALUE(  -438.00) },
      { SIMDE_FLOAT16_VALUE(  -110.50), SIMDE_FLOAT16_VALUE( -1853.00), SIMDE_FLOAT16_VALUE(    -4.11),            SIMDE_NANHF } },
    #endif
      { { UINT16_C(62834), UINT16_C( 2915), UINT16_C(15044), UINT16_C(55669) },
      { SIMDE_FLOAT16_VALUE(   430.50), SIMDE_FLOAT16_VALUE(  -815.50), SIMDE_FLOAT16_VALUE(  -364.00), SIMDE_FLOAT16_VALUE(  -185.75) },
      { SIMDE_FLOAT16_VALUE(  -861.50), SIMDE_FLOAT16_VALUE(   384.50), SIMDE_FLOAT16_VALUE(   249.50), SIMDE_FLOAT16_VALUE(  -701.50) },
      { SIMDE_FLOAT16_VALUE(   107.69), SIMDE_FLOAT16_VALUE(   100.19), SIMDE_FLOAT16_VALUE(   177.00), SIMDE_FLOAT16_VALUE(-43456.00) } },
    { { UINT16_C(51556), UINT16_C(12796), UINT16_C(49577), UINT16_C(41056) },
      { SIMDE_FLOAT16_VALUE(  -689.50), SIMDE_FLOAT16_VALUE(  -776.00), SIMDE_FLOAT16_VALUE(   144.75), SIMDE_FLOAT16_VALUE(  -410.75) },
      { SIMDE_FLOAT16_VALUE(   129.50), SIMDE_FLOAT16_VALUE(  -774.50), SIMDE_FLOAT16_VALUE(   261.25), SIMDE_FLOAT16_VALUE(   222.25) },
      { SIMDE_FLOAT16_VALUE(   -43.25), SIMDE_FLOAT16_VALUE(  -776.50), SIMDE_FLOAT16_VALUE(   293.00), SIMDE_FLOAT16_VALUE(  -222.25) } },
    { { UINT16_C( 6398), UINT16_C(50024), UINT16_C(56659), UINT16_C(39836) },
      { SIMDE_FLOAT16_VALUE(   910.00), SIMDE_FLOAT16_VALUE(   941.00), SIMDE_FLOAT16_VALUE(  -945.00), SIMDE_FLOAT16_VALUE(  -951.50) },
      { SIMDE_FLOAT16_VALUE(   325.50), SIMDE_FLOAT16_VALUE(   304.50), SIMDE_FLOAT16_VALUE(  -653.00), SIMDE_FLOAT16_VALUE(  -645.50) },
      { SIMDE_FLOAT16_VALUE(     5.11), SIMDE_FLOAT16_VALUE(   498.50), SIMDE_FLOAT16_VALUE(  -677.00), SIMDE_FLOAT16_VALUE(  -903.50) } },
    { { UINT16_C(26238), UINT16_C(53664), UINT16_C(15427), UINT16_C(34924) },
      { SIMDE_FLOAT16_VALUE(  -877.00), SIMDE_FLOAT16_VALUE(  -613.50), SIMDE_FLOAT16_VALUE(   868.50), SIMDE_FLOAT16_VALUE(   448.50) },
      { SIMDE_FLOAT16_VALUE(   691.00), SIMDE_FLOAT16_VALUE(  -784.50), SIMDE_FLOAT16_VALUE(   803.00), SIMDE_FLOAT16_VALUE(   -89.88) },
      { SIMDE_FLOAT16_VALUE(   941.00), SIMDE_FLOAT16_VALUE(  -832.50), SIMDE_FLOAT16_VALUE(   802.50), SIMDE_FLOAT16_VALUE(   356.50) } },
    { { UINT16_C(22596), UINT16_C(20143), UINT16_C( 2161), UINT16_C(10030) },
      { SIMDE_FLOAT16_VALUE(   377.50), SIMDE_FLOAT16_VALUE(  -730.00), SIMDE_FLOAT16_VALUE(   624.00), SIMDE_FLOAT16_VALUE(   931.50) },
      { SIMDE_FLOAT16_VALUE(   655.50), SIMDE_FLOAT16_VALUE(  -638.50), SIMDE_FLOAT16_VALUE(  -506.50), SIMDE_FLOAT16_VALUE(   -63.97) },
      { SIMDE_FLOAT16_VALUE( 44000.00), SIMDE_FLOAT16_VALUE(  -634.00), SIMDE_FLOAT16_VALUE(  -126.62), SIMDE_FLOAT16_VALUE(-16056.00) } },
    { { UINT16_C(15150), UINT16_C(29075), UINT16_C(65400), UINT16_C(27641) },
      { SIMDE_FLOAT16_VALUE(  -255.00), SIMDE_FLOAT16_VALUE(  -855.00), SIMDE_FLOAT16_VALUE(   123.38), SIMDE_FLOAT16_VALUE(  -564.00) },
      { SIMDE_FLOAT16_VALUE(  -639.50), SIMDE_FLOAT16_VALUE(   -73.75), SIMDE_FLOAT16_VALUE(   346.25), SIMDE_FLOAT16_VALUE(   748.00) },
      { SIMDE_FLOAT16_VALUE(  -255.12), SIMDE_FLOAT16_VALUE( -1166.00), SIMDE_FLOAT16_VALUE(   115.06), SIMDE_FLOAT16_VALUE(   564.00) } },
    { { UINT16_C( 9849), UINT16_C(59957), UINT16_C(25647), UINT16_C( 3346) },
      { SIMDE_FLOAT16_VALUE(  -224.12), SIMDE_FLOAT16_VALUE(   947.00), SIMDE_FLOAT16_VALUE(   569.00), SIMDE_FLOAT16_VALUE(  -569.00) },
      { SIMDE_FLOAT16_VALUE(  -691.50), SIMDE_FLOAT16_VALUE(  -937.50), SIMDE_FLOAT16_VALUE(   367.25), SIMDE_FLOAT16_VALUE(  -145.50) },
      { SIMDE_FLOAT16_VALUE(    -3.51), SIMDE_FLOAT16_VALUE(   947.00), SIMDE_FLOAT16_VALUE( 46656.00), SIMDE_FLOAT16_VALUE(   -36.94) } }
    };

    for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
      simde_uint16x4_t a = simde_vld1_u16(test_vec[i].a);
      simde_float16x4_t b = simde_vld1_f16(test_vec[i].b);
      simde_float16x4_t c = simde_vld1_f16(test_vec[i].c);
      simde_float16x4_t r = simde_vbsl_f16(a, b, c);

      simde_test_arm_neon_assert_equal_f16x4(r, simde_vld1_f16(test_vec[i].r), 1);
    }

    return 0;
  #else
    fputc('\n', stdout);
    for (int i = 0 ; i < 8 ; i++) {
      simde_uint16x4_t a = simde_test_arm_neon_random_u16x4();
      simde_float16x4_t b = simde_test_arm_neon_random_f16x4(-1000.0f, 1000.0f);
      simde_float16x4_t c = simde_test_arm_neon_random_f16x4(-1000.0f, 1000.0f);
      simde_float16x4_t r = simde_vbsl_f16(a, b, c);

      simde_test_arm_neon_write_u16x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
      simde_test_arm_neon_write_f16x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
      simde_test_arm_neon_write_f16x4(2, c, SIMDE_TEST_VEC_POS_MIDDLE);
      simde_test_arm_neon_write_f16x4(2, r, SIMDE_TEST_VEC_POS_LAST);
    }
    return 1;
  #endif
}

static int
test_simde_vbsl_f32 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    uint32_t a[2];
    simde_float32 b[2];
    simde_float32 c[2];
    simde_float32 r[2];
  } test_vec[] = {
    { { UINT32_C(2674418426), UINT32_C(3777353220) },
      { SIMDE_FLOAT32_C(   405.65), SIMDE_FLOAT32_C(   927.47) },
      { SIMDE_FLOAT32_C(   560.08), SIMDE_FLOAT32_C(   314.53) },
      { SIMDE_FLOAT32_C(   204.28), SIMDE_FLOAT32_C(    94.92) } },
    { { UINT32_C(2013377052), UINT32_C(3455611233) },
      { SIMDE_FLOAT32_C(  -536.59), SIMDE_FLOAT32_C(   460.49) },
      { SIMDE_FLOAT32_C(   342.29), SIMDE_FLOAT32_C(   371.78) },
      { SIMDE_FLOAT32_C(   340.29), SIMDE_FLOAT32_C(   451.40) } },
    { { UINT32_C(3025790568), UINT32_C(2349671826) },
      { SIMDE_FLOAT32_C(   788.79), SIMDE_FLOAT32_C(  -926.62) },
      { SIMDE_FLOAT32_C(  -581.67), SIMDE_FLOAT32_C(   594.40) },
      { SIMDE_FLOAT32_C(   772.66), SIMDE_FLOAT32_C(  -598.96) } },
    { { UINT32_C(3060552012), UINT32_C(4153264603) },
      { SIMDE_FLOAT32_C(  -460.00), SIMDE_FLOAT32_C(  -480.26) },
      { SIMDE_FLOAT32_C(  -404.52), SIMDE_FLOAT32_C(   864.59) },
      { SIMDE_FLOAT32_C(  -460.02), SIMDE_FLOAT32_C(  -416.29) } },
    { { UINT32_C(1772709632), UINT32_C(1083407319) },
      { SIMDE_FLOAT32_C(  -513.91), SIMDE_FLOAT32_C(  -140.44) },
      { SIMDE_FLOAT32_C(   -53.49), SIMDE_FLOAT32_C(   -77.23) },
      { SIMDE_FLOAT32_C(   -53.24), SIMDE_FLOAT32_C(   -34.11) } },
    { { UINT32_C(2558525713), UINT32_C(3273960567) },
      { SIMDE_FLOAT32_C(  -353.14), SIMDE_FLOAT32_C(  -890.91) },
      { SIMDE_FLOAT32_C(   522.94), SIMDE_FLOAT32_C(   387.01) },
      { SIMDE_FLOAT32_C( -1045.91), SIMDE_FLOAT32_C(    -6.18) } },
    { { UINT32_C(3587114586), UINT32_C(2494709396) },
      { SIMDE_FLOAT32_C(  -250.58), SIMDE_FLOAT32_C(   789.87) },
      { SIMDE_FLOAT32_C(  -999.31), SIMDE_FLOAT32_C(   725.63) },
      { SIMDE_FLOAT32_C(   -15.68), SIMDE_FLOAT32_C(   533.86) } },
    { { UINT32_C( 951947479), UINT32_C(2368516476) },
      { SIMDE_FLOAT32_C(  -889.18), SIMDE_FLOAT32_C(   581.78) },
      { SIMDE_FLOAT32_C(   860.56), SIMDE_FLOAT32_C(   106.82) },
      { SIMDE_FLOAT32_C(   888.55), SIMDE_FLOAT32_C( 26777.97) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint32x2_t a = simde_vld1_u32(test_vec[i].a);
    simde_float32x2_t b = simde_vld1_f32(test_vec[i].b);
    simde_float32x2_t c = simde_vld1_f32(test_vec[i].c);
    simde_float32x2_t r = simde_vbsl_f32(a, b, c);

    simde_test_arm_neon_assert_equal_f32x2(r, simde_vld1_f32(test_vec[i].r), 1);
  }

  return 0;
}

static int
test_simde_vbsl_f64 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    uint64_t a[1];
    simde_float64 b[1];
    simde_float64 c[1];
    simde_float64 r[1];
  } test_vec[] = {
    { { UINT64_C(11051150815757923623) },
      { SIMDE_FLOAT64_C(  -588.66) },
      { SIMDE_FLOAT64_C(  -849.95) },
      { SIMDE_FLOAT64_C(  -577.69) } },
    { { UINT64_C( 3459855493406248467) },
      { SIMDE_FLOAT64_C(  -254.41) },
      { SIMDE_FLOAT64_C(  -342.68) },
      { SIMDE_FLOAT64_C(  -380.68) } },
    { { UINT64_C( 8499033952931220346) },
      { SIMDE_FLOAT64_C(   598.37) },
      { SIMDE_FLOAT64_C(  -678.68) },
      { SIMDE_FLOAT64_C(  -758.93) } },
    { { UINT64_C( 4453775121523365047) },
      { SIMDE_FLOAT64_C(  -983.29) },
      { SIMDE_FLOAT64_C(  -133.31) },
      { SIMDE_FLOAT64_C( -3932.65) } },
    { { UINT64_C( 2741489458384578945) },
      { SIMDE_FLOAT64_C(  -672.98) },
      { SIMDE_FLOAT64_C(  -225.94) },
      { SIMDE_FLOAT64_C(  -168.19) } },
    { { UINT64_C(  649913727035663599) },
      { SIMDE_FLOAT64_C(   665.07) },
      { SIMDE_FLOAT64_C(  -836.34) },
      { SIMDE_FLOAT64_C(  -984.34) } },
    { { UINT64_C( 3156572937688261107) },
      { SIMDE_FLOAT64_C(  -862.48) },
      { SIMDE_FLOAT64_C(   875.24) },
      { SIMDE_FLOAT64_C(   879.50) } },
    { { UINT64_C( 6490021655321781721) },
      { SIMDE_FLOAT64_C(  -306.99) },
      { SIMDE_FLOAT64_C(   894.38) },
      { SIMDE_FLOAT64_C(  1784.82) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint64x1_t a = simde_vld1_u64(test_vec[i].a);
    simde_float64x1_t b = simde_vld1_f64(test_vec[i].b);
    simde_float64x1_t c = simde_vld1_f64(test_vec[i].c);
    simde_float64x1_t r = simde_vbsl_f64(a, b, c);

    simde_test_arm_neon_assert_equal_f64x1(r, simde_vld1_f64(test_vec[i].r), 1);
  }

  return 0;
}

static int
test_simde_vbsl_s8 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    uint8_t a[8];
    int8_t b[8];
    int8_t c[8];
    int8_t r[8];
  } test_vec[] = {
    { { UINT8_C(121), UINT8_C( 28), UINT8_C( 45), UINT8_C(151), UINT8_C(120), UINT8_C(  7), UINT8_C( 82), UINT8_C( 78) },
      {  INT8_C( 121), -INT8_C(  36), -INT8_C(  63),  INT8_C( 101),  INT8_C(  97), -INT8_C(  69),  INT8_C(  84),  INT8_C(  14) },
      { -INT8_C(  55),  INT8_C(  67), -INT8_C(  91),  INT8_C(  27), -INT8_C( 125), -INT8_C(  19), -INT8_C(  21), -INT8_C(  34) },
      { -INT8_C(   7),  INT8_C(  95), -INT8_C( 127),  INT8_C(  13), -INT8_C(  29), -INT8_C(  21), -INT8_C(   7), -INT8_C(  98) } },
    { { UINT8_C(174), UINT8_C( 64), UINT8_C(203), UINT8_C( 94), UINT8_C(160), UINT8_C(  0), UINT8_C(116), UINT8_C( 25) },
      {  INT8_C(  28), -INT8_C(  95), -INT8_C(  79), -INT8_C( 108), -INT8_C(  88),  INT8_C(   3), -INT8_C(  30),  INT8_C(  34) },
      { -INT8_C(  33), -INT8_C(  92), -INT8_C( 121),  INT8_C(  64),  INT8_C(  95), -INT8_C(  37),  INT8_C(  79),  INT8_C(  40) },
      {  INT8_C(  93), -INT8_C(  92), -INT8_C( 123),  INT8_C(  20), -INT8_C(   1), -INT8_C(  37),  INT8_C( 107),  INT8_C(  32) } },
    { { UINT8_C( 30), UINT8_C(244), UINT8_C( 67), UINT8_C(161), UINT8_C(226), UINT8_C( 47), UINT8_C(127), UINT8_C(144) },
      {  INT8_C( 111),  INT8_C(  74), -INT8_C(  17),  INT8_C(  15),  INT8_C(  75),  INT8_C(  99),  INT8_C(  41),  INT8_C( 103) },
      {  INT8_C(   5), -INT8_C(  38), -INT8_C(   4), -INT8_C(  83), -INT8_C(  35), -INT8_C(  34), -INT8_C(  49), -INT8_C(  68) },
      {  INT8_C(  15),  INT8_C(  74), -INT8_C(   1),  INT8_C(  13),  INT8_C(  95), -INT8_C(  13), -INT8_C(  87),  INT8_C(  44) } },
    { { UINT8_C(130), UINT8_C( 86), UINT8_C(252), UINT8_C(225), UINT8_C( 49), UINT8_C( 75), UINT8_C( 10), UINT8_C( 79) },
      {  INT8_C(  64),  INT8_C(  77), -INT8_C(  15),  INT8_C(  34),  INT8_C( 124),  INT8_C( 112), -INT8_C(  78), -INT8_C(  20) },
      { -INT8_C(  69), -INT8_C(  95), -INT8_C(   5),  INT8_C(   6),  INT8_C(   5),  INT8_C(  36),  INT8_C( 109),  INT8_C(  10) },
      {  INT8_C(  57), -INT8_C(  27), -INT8_C(  13),  INT8_C(  38),  INT8_C(  52),  INT8_C( 100),  INT8_C( 103),  INT8_C(  76) } },
    { { UINT8_C(254), UINT8_C(105), UINT8_C(183), UINT8_C(219), UINT8_C( 72), UINT8_C(135), UINT8_C(151), UINT8_C(202) },
      { -INT8_C(  35), -INT8_C( 108), -INT8_C(  84),  INT8_C(  15), -INT8_C(  33), -INT8_C(  74),  INT8_C(  94),  INT8_C(  31) },
      {  INT8_C(   3),  INT8_C(  79),  INT8_C(  65),      INT8_MIN, -INT8_C(  64), -INT8_C(  12),  INT8_C( 108),  INT8_C( 123) },
      { -INT8_C(  35),  INT8_C(   6), -INT8_C(  28),  INT8_C(  11), -INT8_C(  56), -INT8_C(  10),  INT8_C( 126),  INT8_C(  59) } },
    { { UINT8_C(149), UINT8_C(103), UINT8_C(129), UINT8_C(154), UINT8_C(140), UINT8_C(238), UINT8_C(164), UINT8_C(138) },
      {  INT8_C(  88),  INT8_C(  92),  INT8_C( 102), -INT8_C(  96), -INT8_C(  29), -INT8_C(   3),  INT8_C( 106), -INT8_C(  64) },
      { -INT8_C( 111),  INT8_C(  22), -INT8_C(  49),  INT8_C( 113), -INT8_C(  52),  INT8_C(  46), -INT8_C( 112), -INT8_C(  48) },
      {  INT8_C(  16),  INT8_C(  84),  INT8_C(  78), -INT8_C(  31), -INT8_C(  64), -INT8_C(  20),  INT8_C(  48), -INT8_C(  48) } },
    { { UINT8_C(125), UINT8_C(210), UINT8_C( 80), UINT8_C( 61), UINT8_C(198), UINT8_C(188), UINT8_C(184), UINT8_C( 91) },
      {  INT8_C(  35),  INT8_C(  57), -INT8_C(  10), -INT8_C(  81),  INT8_C(  40), -INT8_C( 102),  INT8_C(  58),      INT8_MIN },
      { -INT8_C(  10), -INT8_C(  96),  INT8_C(  32), -INT8_C(  39), -INT8_C(  99), -INT8_C( 118), -INT8_C( 102),  INT8_C(  47) },
      { -INT8_C(  93),  INT8_C(  48),  INT8_C( 112), -INT8_C(  19),  INT8_C(  25), -INT8_C( 102),  INT8_C(  58),  INT8_C(  36) } },
    { { UINT8_C(161), UINT8_C(105), UINT8_C(160), UINT8_C(109), UINT8_C(151), UINT8_C( 48), UINT8_C( 61), UINT8_C( 21) },
      {  INT8_C(   2), -INT8_C( 115),  INT8_C(  82), -INT8_C(  56),  INT8_C(  73),  INT8_C(  11),  INT8_C(  36),  INT8_C( 109) },
      {  INT8_C(  68),  INT8_C(  26),  INT8_C(  28),  INT8_C( 108), -INT8_C(  76),  INT8_C(  86), -INT8_C(  20), -INT8_C(  85) },
      {  INT8_C(  68),  INT8_C(  27),  INT8_C(  28),  INT8_C(  72),  INT8_C(  33),  INT8_C(  70), -INT8_C(  28), -INT8_C(  81) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint8x8_t a = simde_vld1_u8(test_vec[i].a);
    simde_int8x8_t b = simde_vld1_s8(test_vec[i].b);
    simde_int8x8_t c = simde_vld1_s8(test_vec[i].c);
    simde_int8x8_t r = simde_vbsl_s8(a, b, c);

    simde_test_arm_neon_assert_equal_i8x8(r, simde_vld1_s8(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vbsl_s16 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    uint16_t a[4];
    int16_t b[4];
    int16_t c[4];
    int16_t r[4];
  } test_vec[] = {
    { { UINT16_C(24105), UINT16_C(62072), UINT16_C(14929), UINT16_C(19853) },
      {  INT16_C( 18703),  INT16_C(  2059), -INT16_C( 29657), -INT16_C( 14313) },
      {  INT16_C(  1857), -INT16_C( 14232), -INT16_C( 10103), -INT16_C(  1165) },
      {  INT16_C( 18761),  INT16_C(  2056), -INT16_C( 14199), -INT16_C(  1417) } },
    { { UINT16_C(64683), UINT16_C(25681), UINT16_C(27627), UINT16_C( 5351) },
      {  INT16_C( 24521),  INT16_C(  6662), -INT16_C( 27751), -INT16_C( 22169) },
      {  INT16_C( 29404),  INT16_C(   945), -INT16_C( 14082),  INT16_C( 16332) },
      {  INT16_C( 24285),  INT16_C(   928), -INT16_C( 31843),  INT16_C( 11119) } },
    { { UINT16_C(13519), UINT16_C(22791), UINT16_C(31245), UINT16_C(47188) },
      { -INT16_C( 23178),  INT16_C( 24860),  INT16_C(   784), -INT16_C(  9610) },
      {  INT16_C( 31843), -INT16_C(   780),  INT16_C( 23568), -INT16_C(  4955) },
      {  INT16_C( 27750), -INT16_C(  6668),  INT16_C(  1552), -INT16_C(  8971) } },
    { { UINT16_C(22222), UINT16_C(52720), UINT16_C(48158), UINT16_C(60940) },
      {  INT16_C(  5360), -INT16_C(   697), -INT16_C( 25714),  INT16_C(  1462) },
      { -INT16_C( 11712),  INT16_C( 20582), -INT16_C(  9002),  INT16_C( 14634) },
      { -INT16_C( 27456), -INT16_C(  8890), -INT16_C( 10034),  INT16_C(  5414) } },
    { { UINT16_C( 8025), UINT16_C(26933), UINT16_C(56187), UINT16_C(18773) },
      {  INT16_C( 17713),  INT16_C( 20502),  INT16_C(  8961), -INT16_C(  3522) },
      { -INT16_C( 31433), -INT16_C( 14865), -INT16_C( 23264),  INT16_C( 24778) },
      { -INT16_C( 31433), -INT16_C( 15138),  INT16_C(  9985),  INT16_C( 24734) } },
    { { UINT16_C(12664), UINT16_C(20144), UINT16_C(56077), UINT16_C(26247) },
      { -INT16_C( 17158),  INT16_C( 30159),  INT16_C(  9623), -INT16_C( 13890) },
      { -INT16_C( 10902),  INT16_C( 27673),  INT16_C( 22520),  INT16_C( 12126) },
      { -INT16_C(  2950),  INT16_C( 25737),  INT16_C(  1525),  INT16_C( 18910) } },
    { { UINT16_C(19932), UINT16_C(64756), UINT16_C(49139), UINT16_C(27484) },
      {  INT16_C(  3312), -INT16_C(   583),  INT16_C( 16615), -INT16_C(  7836) },
      {  INT16_C( 13308), -INT16_C( 27562),  INT16_C(  5464), -INT16_C( 15523) },
      {  INT16_C( 16112), -INT16_C(   846),  INT16_C(   235), -INT16_C(  7867) } },
    { { UINT16_C(30442), UINT16_C(57903), UINT16_C(36301), UINT16_C(43281) },
      {  INT16_C(  1498), -INT16_C( 12891),  INT16_C(   452), -INT16_C( 19400) },
      { -INT16_C(  3827), -INT16_C(  2638),  INT16_C(  5681),  INT16_C( 11990) },
      { -INT16_C( 31281), -INT16_C( 10827),  INT16_C(  5108), -INT16_C( 22826) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint16x4_t a = simde_vld1_u16(test_vec[i].a);
    simde_int16x4_t b = simde_vld1_s16(test_vec[i].b);
    simde_int16x4_t c = simde_vld1_s16(test_vec[i].c);
    simde_int16x4_t r = simde_vbsl_s16(a, b, c);

    simde_test_arm_neon_assert_equal_i16x4(r, simde_vld1_s16(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vbsl_s32 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    uint32_t a[2];
    int32_t b[2];
    int32_t c[2];
    int32_t r[2];
  } test_vec[] = {
    { { UINT32_C(1530270266), UINT32_C(1664922840) },
      {  INT32_C(   283414752), -INT32_C(   644297687) },
      { -INT32_C(   890719696), -INT32_C(  1368609695) },
      { -INT32_C(  1863536608), -INT32_C(   849834967) } },
    { { UINT32_C(1917411085), UINT32_C(1617853222) },
      {  INT32_C(  1723638925),  INT32_C(   969537625) },
      { -INT32_C(  1320571512), -INT32_C(  1433738630) },
      { -INT32_C(   485972851), -INT32_C(  1429669800) } },
    { { UINT32_C(4118049428), UINT32_C( 732225822) },
      {  INT32_C(  1721625920), -INT32_C(   154727320) },
      {  INT32_C(   157057968),  INT32_C(    54666619) },
      {  INT32_C(  1813831968),  INT32_C(   583402601) } },
    { { UINT32_C(1303678163), UINT32_C(  49757806) },
      { -INT32_C(   822580048), -INT32_C(  1913021363) },
      { -INT32_C(   218916983),  INT32_C(  1407761059) },
      { -INT32_C(    17621096),  INT32_C(  1375313101) } },
    { { UINT32_C(3093120061), UINT32_C(1018929001) },
      { -INT32_C(  1719046357),  INT32_C(  1570537901) },
      {  INT32_C(   975934701), -INT32_C(  1178131152) },
      { -INT32_C(  1708403479), -INT32_C(  1646485191) } },
    { { UINT32_C(1605089980), UINT32_C(2998047605) },
      {  INT32_C(  1097535447), -INT32_C(   629332305) },
      {  INT32_C(  1131677590),  INT32_C(  1973489800) },
      {  INT32_C(  1098846102), -INT32_C(   684653907) } },
    { { UINT32_C(3568290980), UINT32_C(2911729393) },
      { -INT32_C(  1525925584), -INT32_C(  1537687604) },
      {  INT32_C(  2112209870),  INT32_C(  2136498921) },
      { -INT32_C(  1387525270), -INT32_C(   161990968) } },
    { { UINT32_C(4056140905), UINT32_C(2154194140) },
      {  INT32_C(   575935792), -INT32_C(  1127226997) },
      { -INT32_C(   413017062),  INT32_C(  1770764699) },
      {  INT32_C(   643830834), -INT32_C(   372246133) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint32x2_t a = simde_vld1_u32(test_vec[i].a);
    simde_int32x2_t b = simde_vld1_s32(test_vec[i].b);
    simde_int32x2_t c = simde_vld1_s32(test_vec[i].c);
    simde_int32x2_t r = simde_vbsl_s32(a, b, c);

    simde_test_arm_neon_assert_equal_i32x2(r, simde_vld1_s32(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vbsl_s64 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    uint64_t a[1];
    int64_t b[1];
    int64_t c[1];
    int64_t r[1];
  } test_vec[] = {
    { { UINT64_C( 9620680368057188459) },
      { -INT64_C( 3689875764262471268) },
      { -INT64_C( 9004170336378258797) },
      { -INT64_C( 8751963524792583528) } },
    { { UINT64_C( 5744368692421788381) },
      {  INT64_C( 8786609585886222232) },
      {  INT64_C( 4656177399195942727) },
      {  INT64_C( 5311442486467149722) } },
    { { UINT64_C( 5609318480735350411) },
      {  INT64_C( 3855942873821709648) },
      { -INT64_C( 2036313555189412250) },
      { -INT64_C( 6366524597640117148) } },
    { { UINT64_C(11473855825243865935) },
      {  INT64_C( 2071316957582556929) },
      { -INT64_C( 8420935098164046512) },
      {  INT64_C( 2034157141122684689) } },
    { { UINT64_C(11574685700528718370) },
      { -INT64_C( 6034023422833698929) },
      {  INT64_C( 5854639938047128918) },
      { -INT64_C( 1072183263522621610) } },
    { { UINT64_C( 9701142154830647537) },
      { -INT64_C( 8496632253797601501) },
      { -INT64_C( 2336401143595421380) },
      { -INT64_C( 2660659904217079507) } },
    { { UINT64_C( 9148854339857723556) },
      { -INT64_C( 4918997769423407406) },
      {  INT64_C( 2461575523855237284) },
      {  INT64_C( 4232264231970418816) } },
    { { UINT64_C( 7665017462878459639) },
      {  INT64_C( 8527291724535390796) },
      { -INT64_C( 4283090230389707972) },
      { -INT64_C( 1812869665887753396) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint64x1_t a = simde_vld1_u64(test_vec[i].a);
    simde_int64x1_t b = simde_vld1_s64(test_vec[i].b);
    simde_int64x1_t c = simde_vld1_s64(test_vec[i].c);
    simde_int64x1_t r = simde_vbsl_s64(a, b, c);

    simde_test_arm_neon_assert_equal_i64x1(r, simde_vld1_s64(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vbsl_u8 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    uint8_t a[8];
    uint8_t b[8];
    uint8_t c[8];
    uint8_t r[8];
  } test_vec[] = {
    { { UINT8_C(180), UINT8_C(  0), UINT8_C(193), UINT8_C( 74), UINT8_C( 97), UINT8_C(212), UINT8_C( 25), UINT8_C(176) },
      { UINT8_C(139), UINT8_C(110), UINT8_C( 75), UINT8_C( 82), UINT8_C( 56), UINT8_C(156), UINT8_C(198), UINT8_C( 81) },
      { UINT8_C(226), UINT8_C(123), UINT8_C(246), UINT8_C( 96), UINT8_C(177), UINT8_C( 52), UINT8_C(179), UINT8_C( 94) },
      { UINT8_C(194), UINT8_C(123), UINT8_C(119), UINT8_C( 98), UINT8_C(176), UINT8_C(180), UINT8_C(162), UINT8_C( 94) } },
    { { UINT8_C(197), UINT8_C(122), UINT8_C(231), UINT8_C(180), UINT8_C(179), UINT8_C(166), UINT8_C( 87), UINT8_C(103) },
      { UINT8_C(166), UINT8_C( 24), UINT8_C(178), UINT8_C(  8), UINT8_C(236), UINT8_C(203), UINT8_C(184), UINT8_C(119) },
      { UINT8_C( 57), UINT8_C(  3), UINT8_C(201), UINT8_C(114), UINT8_C(159), UINT8_C(143), UINT8_C(195), UINT8_C(130) },
      { UINT8_C(188), UINT8_C( 25), UINT8_C(170), UINT8_C( 66), UINT8_C(172), UINT8_C(139), UINT8_C(144), UINT8_C(231) } },
    { { UINT8_C( 11), UINT8_C(186), UINT8_C(226), UINT8_C(188), UINT8_C(238), UINT8_C(149), UINT8_C( 27), UINT8_C(180) },
      { UINT8_C( 15), UINT8_C(  2), UINT8_C(104), UINT8_C(195), UINT8_C(168), UINT8_C(191), UINT8_C( 42), UINT8_C( 79) },
      { UINT8_C(216), UINT8_C(220), UINT8_C( 87), UINT8_C(196), UINT8_C(168), UINT8_C( 15), UINT8_C( 60), UINT8_C(225) },
      { UINT8_C(219), UINT8_C( 70), UINT8_C(117), UINT8_C(192), UINT8_C(168), UINT8_C(159), UINT8_C( 46), UINT8_C( 69) } },
    { { UINT8_C( 18), UINT8_C(  5), UINT8_C( 83), UINT8_C(178), UINT8_C(149), UINT8_C( 23), UINT8_C( 52), UINT8_C(160) },
      { UINT8_C(209), UINT8_C( 22), UINT8_C( 92), UINT8_C(191), UINT8_C(172), UINT8_C(119), UINT8_C(115), UINT8_C(187) },
      { UINT8_C(122), UINT8_C(219), UINT8_C(126), UINT8_C( 34), UINT8_C(155), UINT8_C(169), UINT8_C(113), UINT8_C(115) },
      { UINT8_C(120), UINT8_C(222), UINT8_C(124), UINT8_C(178), UINT8_C(142), UINT8_C(191), UINT8_C(113), UINT8_C(243) } },
    { { UINT8_C(133), UINT8_C(200), UINT8_C( 55), UINT8_C( 45), UINT8_C(215), UINT8_C(115), UINT8_C( 15), UINT8_C(234) },
      { UINT8_C(121), UINT8_C( 98), UINT8_C(156), UINT8_C( 14), UINT8_C(121), UINT8_C(208), UINT8_C(174), UINT8_C( 74) },
      { UINT8_C(230), UINT8_C( 10), UINT8_C( 10), UINT8_C(146), UINT8_C(130), UINT8_C(125), UINT8_C( 78), UINT8_C(252) },
      { UINT8_C( 99), UINT8_C( 66), UINT8_C( 28), UINT8_C(158), UINT8_C( 81), UINT8_C( 92), UINT8_C( 78), UINT8_C( 94) } },
    { { UINT8_C( 89), UINT8_C(204), UINT8_C( 30), UINT8_C(244), UINT8_C(117), UINT8_C(144), UINT8_C(103), UINT8_C(251) },
      { UINT8_C( 88), UINT8_C(158), UINT8_C( 40), UINT8_C( 48), UINT8_C( 18), UINT8_C( 55), UINT8_C( 26), UINT8_C(139) },
      { UINT8_C(154), UINT8_C(182), UINT8_C(153), UINT8_C( 19), UINT8_C(134), UINT8_C( 71), UINT8_C( 94), UINT8_C(108) },
      { UINT8_C(218), UINT8_C(190), UINT8_C(137), UINT8_C( 51), UINT8_C(146), UINT8_C( 87), UINT8_C( 26), UINT8_C(143) } },
    { { UINT8_C( 81), UINT8_C(104),    UINT8_MAX, UINT8_C(211), UINT8_C(229), UINT8_C( 77), UINT8_C(207), UINT8_C( 62) },
      { UINT8_C( 25), UINT8_C(238), UINT8_C( 50), UINT8_C(143), UINT8_C(126), UINT8_C(153), UINT8_C(138), UINT8_C(214) },
      { UINT8_C( 56), UINT8_C(178), UINT8_C(  6), UINT8_C( 74), UINT8_C(234), UINT8_C( 32), UINT8_C(213), UINT8_C(132) },
      { UINT8_C( 57), UINT8_C(250), UINT8_C( 50), UINT8_C(139), UINT8_C(110), UINT8_C( 41), UINT8_C(154), UINT8_C(150) } },
    { { UINT8_C(214), UINT8_C(110), UINT8_C(151), UINT8_C( 92), UINT8_C(181), UINT8_C(245), UINT8_C(201), UINT8_C(  6) },
      { UINT8_C( 93), UINT8_C(200), UINT8_C(218), UINT8_C( 67), UINT8_C( 21), UINT8_C(169), UINT8_C(129), UINT8_C( 46) },
      { UINT8_C(151), UINT8_C(180), UINT8_C(189), UINT8_C( 21), UINT8_C( 77), UINT8_C( 71), UINT8_C(236), UINT8_C(133) },
      { UINT8_C( 85), UINT8_C(216), UINT8_C(186), UINT8_C( 65), UINT8_C( 93), UINT8_C(163), UINT8_C(165), UINT8_C(135) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint8x8_t a = simde_vld1_u8(test_vec[i].a);
    simde_uint8x8_t b = simde_vld1_u8(test_vec[i].b);
    simde_uint8x8_t c = simde_vld1_u8(test_vec[i].c);
    simde_uint8x8_t r = simde_vbsl_u8(a, b, c);

    simde_test_arm_neon_assert_equal_u8x8(r, simde_vld1_u8(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vbsl_u16 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    uint16_t a[4];
    uint16_t b[4];
    uint16_t c[4];
    uint16_t r[4];
  } test_vec[] = {
    { { UINT16_C(53761), UINT16_C(11743), UINT16_C(59878), UINT16_C(59435) },
      { UINT16_C(57726), UINT16_C(48484), UINT16_C(45929), UINT16_C(50279) },
      { UINT16_C(17564), UINT16_C(43054), UINT16_C( 9881), UINT16_C(30175) },
      { UINT16_C(50332), UINT16_C(44388), UINT16_C(42873), UINT16_C(54775) } },
    { { UINT16_C(13387), UINT16_C(12838), UINT16_C(50137), UINT16_C(56103) },
      { UINT16_C( 1941), UINT16_C(31752), UINT16_C(13296), UINT16_C(28516) },
      { UINT16_C(51220), UINT16_C(32300), UINT16_C(38011), UINT16_C( 5954) },
      { UINT16_C(52245), UINT16_C(31752), UINT16_C( 6130), UINT16_C(20324) } },
    { { UINT16_C(29144), UINT16_C(29375), UINT16_C(40599), UINT16_C(58343) },
      { UINT16_C( 3539), UINT16_C(44053), UINT16_C(15568), UINT16_C(25991) },
      { UINT16_C(36675), UINT16_C(13537), UINT16_C(17859), UINT16_C(55203) },
      { UINT16_C(36819), UINT16_C( 9301), UINT16_C(24016), UINT16_C(30087) } },
    { { UINT16_C(53005), UINT16_C(34901), UINT16_C(39011), UINT16_C(15520) },
      { UINT16_C(24329), UINT16_C(41134), UINT16_C(38398), UINT16_C(53635) },
      { UINT16_C(39074), UINT16_C(29309), UINT16_C( 1493), UINT16_C( 6359) },
      { UINT16_C(24491), UINT16_C(61996), UINT16_C(38390), UINT16_C( 4311) } },
    { { UINT16_C(47508), UINT16_C(22348), UINT16_C(61438), UINT16_C( 3119) },
      { UINT16_C(33983), UINT16_C( 8852), UINT16_C(13340), UINT16_C( 9566) },
      { UINT16_C( 3220), UINT16_C(37574), UINT16_C(18849), UINT16_C(17251) },
      { UINT16_C(33940), UINT16_C(33414), UINT16_C( 9245), UINT16_C(18254) } },
    { { UINT16_C(57570), UINT16_C(47029), UINT16_C(36325), UINT16_C(31439) },
      { UINT16_C( 7238), UINT16_C(17617), UINT16_C(   11), UINT16_C(51792) },
      { UINT16_C(58757), UINT16_C(41453), UINT16_C(19225), UINT16_C(44487) },
      { UINT16_C( 1351), UINT16_C( 1241), UINT16_C(16921), UINT16_C(53056) } },
    { { UINT16_C(36184), UINT16_C(63807), UINT16_C(41686), UINT16_C(47165) },
      { UINT16_C(62083), UINT16_C(26735), UINT16_C(16255), UINT16_C(50658) },
      { UINT16_C(46171), UINT16_C(26122), UINT16_C(23220), UINT16_C(14641) },
      { UINT16_C(45059), UINT16_C(28207), UINT16_C(31350), UINT16_C(33056) } },
    { { UINT16_C( 7743), UINT16_C(23003), UINT16_C(41577), UINT16_C(49414) },
      { UINT16_C(17967), UINT16_C( 1467), UINT16_C(63720), UINT16_C(27582) },
      { UINT16_C(11754), UINT16_C(27348), UINT16_C(46700), UINT16_C(50991) },
      { UINT16_C(10223), UINT16_C( 9119), UINT16_C(46188), UINT16_C(18223) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint16x4_t a = simde_vld1_u16(test_vec[i].a);
    simde_uint16x4_t b = simde_vld1_u16(test_vec[i].b);
    simde_uint16x4_t c = simde_vld1_u16(test_vec[i].c);
    simde_uint16x4_t r = simde_vbsl_u16(a, b, c);
    simde_test_arm_neon_assert_equal_u16x4(r, simde_vld1_u16(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vbsl_u32 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    uint32_t a[2];
    uint32_t b[2];
    uint32_t c[2];
    uint32_t r[2];
  } test_vec[] = {
    { { UINT32_C( 432062503), UINT32_C(1205184263) },
      { UINT32_C( 818040885), UINT32_C(3381211908) },
      { UINT32_C( 956542168), UINT32_C(2355800916) },
      { UINT32_C( 818113789), UINT32_C(3383438164) } },
    { { UINT32_C(4190297053), UINT32_C(3328249247) },
      { UINT32_C(3588170190), UINT32_C(4246582472) },
      { UINT32_C( 154001156), UINT32_C(3956455187) },
      { UINT32_C(3522102732), UINT32_C(3985880712) } },
    { { UINT32_C(3072644451), UINT32_C(1564708480) },
      { UINT32_C( 139921001), UINT32_C(3788421139) },
      { UINT32_C(2729946585), UINT32_C(1704973409) },
      { UINT32_C(   9907449), UINT32_C(1641994337) } },
    { { UINT32_C(3329150387), UINT32_C(3887153284) },
      { UINT32_C(2510214421), UINT32_C(3438535011) },
      { UINT32_C(4224994023), UINT32_C(3688669698) },
      { UINT32_C(3181299541), UINT32_C(3707625986) } },
    { { UINT32_C(2961019727), UINT32_C( 454434151) },
      { UINT32_C(1860273386), UINT32_C(3663041477) },
      { UINT32_C(3429954408), UINT32_C(3164103636) },
      { UINT32_C(1818353770), UINT32_C(3197924309) } },
    { { UINT32_C(2948033965), UINT32_C(1602917135) },
      { UINT32_C(2383349799), UINT32_C( 262743333) },
      { UINT32_C(1870498730), UINT32_C(2252984862) },
      { UINT32_C(3461319207), UINT32_C(2412331285) } },
    { { UINT32_C(2572335557), UINT32_C(3377851164) },
      { UINT32_C(1735920728), UINT32_C(3351643040) },
      { UINT32_C( 810931723), UINT32_C(2772434939) },
      { UINT32_C( 559238730), UINT32_C(3849197539) } },
    { { UINT32_C(2819931274), UINT32_C(1395547790) },
      { UINT32_C( 887914775), UINT32_C(3304931948) },
      { UINT32_C(3995825742), UINT32_C(2226516601) },
      { UINT32_C(1714405958), UINT32_C(3300778621) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint32x2_t a = simde_vld1_u32(test_vec[i].a);
    simde_uint32x2_t b = simde_vld1_u32(test_vec[i].b);
    simde_uint32x2_t c = simde_vld1_u32(test_vec[i].c);
    simde_uint32x2_t r = simde_vbsl_u32(a, b, c);
    simde_test_arm_neon_assert_equal_u32x2(r, simde_vld1_u32(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vbsl_u64 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    uint64_t a[1];
    uint64_t b[1];
    uint64_t c[1];
    uint64_t r[1];
  } test_vec[] = {
    { { UINT64_C(14528356940023175243) },
      { UINT64_C(17194180434942818272) },
      { UINT64_C( 7586136997276299551) },
      { UINT64_C(16779928735372194132) } },
    { { UINT64_C(11436712391308833254) },
      { UINT64_C(15593945675035042037) },
      { UINT64_C( 4879995600925107401) },
      { UINT64_C(15647882750434305261) } },
    { { UINT64_C( 1746683290664817516) },
      { UINT64_C(15409676213281850088) },
      { UINT64_C(12167280193671793930) },
      { UINT64_C(12743685970628677226) } },
    { { UINT64_C( 2118711289033487872) },
      { UINT64_C(17747046816302536447) },
      { UINT64_C(17394041849491144112) },
      { UINT64_C(17600678980047904688) } },
    { { UINT64_C(13016193149737162778) },
      { UINT64_C( 4617103595531670853) },
      { UINT64_C(16274244551423624150) },
      { UINT64_C( 4709427112947291076) } },
    { { UINT64_C( 3625913475667069816) },
      { UINT64_C( 6347486207960368557) },
      { UINT64_C(  316203249634832354) },
      { UINT64_C( 1455477651332326826) } },
    { { UINT64_C(  682226695321212261) },
      { UINT64_C( 7644783113438554061) },
      { UINT64_C(17468022663372620542) },
      { UINT64_C(18023304074852354015) } },
    { { UINT64_C( 9152573495301290449) },
      { UINT64_C( 8928540943956962382) },
      { UINT64_C(  619938784361861236) },
      { UINT64_C( 8906446650004007012) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint64x1_t a = simde_vld1_u64(test_vec[i].a);
    simde_uint64x1_t b = simde_vld1_u64(test_vec[i].b);
    simde_uint64x1_t c = simde_vld1_u64(test_vec[i].c);
    simde_uint64x1_t r = simde_vbsl_u64(a, b, c);
    simde_test_arm_neon_assert_equal_u64x1(r, simde_vld1_u64(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vbslq_f16 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    uint16_t a[8];
    simde_float16 b[8];
    simde_float16 c[8];
    simde_float16 r[8];
  } test_vec[] = {
    { { UINT16_C(37688), UINT16_C(35401), UINT16_C(27742), UINT16_C(58401), UINT16_C(50272), UINT16_C(49953), UINT16_C(15249), UINT16_C(43869) },
      { SIMDE_FLOAT16_VALUE(  -660.00), SIMDE_FLOAT16_VALUE(  -281.00), SIMDE_FLOAT16_VALUE(  -589.00), SIMDE_FLOAT16_VALUE(  -492.25),
        SIMDE_FLOAT16_VALUE(   484.00), SIMDE_FLOAT16_VALUE(   115.50), SIMDE_FLOAT16_VALUE(    18.55), SIMDE_FLOAT16_VALUE(  -919.50) },
      { SIMDE_FLOAT16_VALUE(   971.00), SIMDE_FLOAT16_VALUE(   210.25), SIMDE_FLOAT16_VALUE(   343.25), SIMDE_FLOAT16_VALUE(    28.61),
        SIMDE_FLOAT16_VALUE(  -981.50), SIMDE_FLOAT16_VALUE(    37.84), SIMDE_FLOAT16_VALUE(   972.00), SIMDE_FLOAT16_VALUE(   958.00) },
      { SIMDE_FLOAT16_VALUE(  -727.00), SIMDE_FLOAT16_VALUE(  -154.25), SIMDE_FLOAT16_VALUE( 10456.00), SIMDE_FLOAT16_VALUE(   -28.61),
        SIMDE_FLOAT16_VALUE(  1931.00), SIMDE_FLOAT16_VALUE(    61.81), SIMDE_FLOAT16_VALUE(     9.07), SIMDE_FLOAT16_VALUE(  -918.50) } },
    { { UINT16_C(27765), UINT16_C(54208), UINT16_C(57817), UINT16_C(14775), UINT16_C(55462), UINT16_C(14332), UINT16_C(23059), UINT16_C(57315) },
      { SIMDE_FLOAT16_VALUE(  -799.50), SIMDE_FLOAT16_VALUE(   964.50), SIMDE_FLOAT16_VALUE(  -361.25), SIMDE_FLOAT16_VALUE(   684.50),
        SIMDE_FLOAT16_VALUE(    80.12), SIMDE_FLOAT16_VALUE(   657.00), SIMDE_FLOAT16_VALUE(   764.50), SIMDE_FLOAT16_VALUE(    51.31) },
      { SIMDE_FLOAT16_VALUE(  -132.62), SIMDE_FLOAT16_VALUE(   108.00), SIMDE_FLOAT16_VALUE(  -920.00), SIMDE_FLOAT16_VALUE(  -114.00),
        SIMDE_FLOAT16_VALUE(  -854.00), SIMDE_FLOAT16_VALUE(  -948.00), SIMDE_FLOAT16_VALUE(  -156.00), SIMDE_FLOAT16_VALUE(  -337.50) },
      { SIMDE_FLOAT16_VALUE( -8616.00), SIMDE_FLOAT16_VALUE(     7.50), SIMDE_FLOAT16_VALUE(    -3.81), SIMDE_FLOAT16_VALUE( -1809.00),
        SIMDE_FLOAT16_VALUE( 12368.00), SIMDE_FLOAT16_VALUE(  -656.00), SIMDE_FLOAT16_VALUE(    -2.47), SIMDE_FLOAT16_VALUE(    51.19) } },
    { { UINT16_C(19268), UINT16_C( 7523), UINT16_C( 6701), UINT16_C(54103), UINT16_C(21490), UINT16_C( 1290), UINT16_C(60845), UINT16_C(22756) },
      { SIMDE_FLOAT16_VALUE(   546.50), SIMDE_FLOAT16_VALUE(   662.50), SIMDE_FLOAT16_VALUE(  -687.50), SIMDE_FLOAT16_VALUE(  -373.25),
        SIMDE_FLOAT16_VALUE(   319.75), SIMDE_FLOAT16_VALUE(  -923.00), SIMDE_FLOAT16_VALUE(   678.00), SIMDE_FLOAT16_VALUE(  -812.50) },
      { SIMDE_FLOAT16_VALUE(   185.00), SIMDE_FLOAT16_VALUE(   758.00), SIMDE_FLOAT16_VALUE(    73.25), SIMDE_FLOAT16_VALUE(   330.75),
        SIMDE_FLOAT16_VALUE(   810.50), SIMDE_FLOAT16_VALUE(   917.50), SIMDE_FLOAT16_VALUE(   993.50), SIMDE_FLOAT16_VALUE(   301.25) },
      { SIMDE_FLOAT16_VALUE(    38.38), SIMDE_FLOAT16_VALUE(   726.50), SIMDE_FLOAT16_VALUE(     4.61), SIMDE_FLOAT16_VALUE(  -351.25),
        SIMDE_FLOAT16_VALUE( 10168.00), SIMDE_FLOAT16_VALUE(   913.50), SIMDE_FLOAT16_VALUE(   935.00), SIMDE_FLOAT16_VALUE(     4.32) } },
    { { UINT16_C(39569), UINT16_C(48865), UINT16_C(14516), UINT16_C(42641), UINT16_C(40075), UINT16_C(14763), UINT16_C(36745), UINT16_C( 3217) },
      { SIMDE_FLOAT16_VALUE(   720.50), SIMDE_FLOAT16_VALUE(  -893.50), SIMDE_FLOAT16_VALUE(   726.50), SIMDE_FLOAT16_VALUE(    40.28),
        SIMDE_FLOAT16_VALUE(  -816.50), SIMDE_FLOAT16_VALUE(   404.75), SIMDE_FLOAT16_VALUE(   227.50), SIMDE_FLOAT16_VALUE(   368.25) },
      { SIMDE_FLOAT16_VALUE(   163.00), SIMDE_FLOAT16_VALUE(  -699.00), SIMDE_FLOAT16_VALUE(  -300.75), SIMDE_FLOAT16_VALUE(   -26.78),
        SIMDE_FLOAT16_VALUE(  -782.00), SIMDE_FLOAT16_VALUE(  -307.50), SIMDE_FLOAT16_VALUE(  -725.50), SIMDE_FLOAT16_VALUE(   478.25) },
      { SIMDE_FLOAT16_VALUE(     2.77), SIMDE_FLOAT16_VALUE( -1019.50), SIMDE_FLOAT16_VALUE( -1191.00), SIMDE_FLOAT16_VALUE(     8.27),
        SIMDE_FLOAT16_VALUE(  -778.50), SIMDE_FLOAT16_VALUE(  -273.75), SIMDE_FLOAT16_VALUE(  3668.00), SIMDE_FLOAT16_VALUE(   506.25) } },
    { { UINT16_C(26640), UINT16_C(50419), UINT16_C(33952), UINT16_C(11114), UINT16_C( 5408), UINT16_C(43620), UINT16_C(62885), UINT16_C(55222) },
      { SIMDE_FLOAT16_VALUE(   612.00), SIMDE_FLOAT16_VALUE(   866.50), SIMDE_FLOAT16_VALUE(  -682.00), SIMDE_FLOAT16_VALUE(   795.50),
        SIMDE_FLOAT16_VALUE(   271.25), SIMDE_FLOAT16_VALUE(   545.50), SIMDE_FLOAT16_VALUE(   163.75), SIMDE_FLOAT16_VALUE(  -566.00) },
      { SIMDE_FLOAT16_VALUE(   846.00), SIMDE_FLOAT16_VALUE(   863.00), SIMDE_FLOAT16_VALUE(   407.50), SIMDE_FLOAT16_VALUE(  -936.00),
        SIMDE_FLOAT16_VALUE(  -444.75), SIMDE_FLOAT16_VALUE(   682.00), SIMDE_FLOAT16_VALUE(   542.50), SIMDE_FLOAT16_VALUE(   842.00) },
      { SIMDE_FLOAT16_VALUE(   838.00), SIMDE_FLOAT16_VALUE(   870.50), SIMDE_FLOAT16_VALUE(  -203.75), SIMDE_FLOAT16_VALUE(  -793.00),
        SIMDE_FLOAT16_VALUE(  -444.75), SIMDE_FLOAT16_VALUE(   680.00), SIMDE_FLOAT16_VALUE(    40.88), SIMDE_FLOAT16_VALUE(  -530.00) } },
    { { UINT16_C(57334), UINT16_C(38623), UINT16_C(19043), UINT16_C(33986), UINT16_C( 9823), UINT16_C( 1070), UINT16_C(58396), UINT16_C(52187) },
      { SIMDE_FLOAT16_VALUE(   164.62), SIMDE_FLOAT16_VALUE(   284.50), SIMDE_FLOAT16_VALUE(  -327.00), SIMDE_FLOAT16_VALUE(  -564.00),
        SIMDE_FLOAT16_VALUE(  -170.12), SIMDE_FLOAT16_VALUE(   836.50), SIMDE_FLOAT16_VALUE(  -130.00), SIMDE_FLOAT16_VALUE(  -324.00) },
      { SIMDE_FLOAT16_VALUE(   699.50), SIMDE_FLOAT16_VALUE(  -722.50), SIMDE_FLOAT16_VALUE(  -259.75), SIMDE_FLOAT16_VALUE(  -745.00),
        SIMDE_FLOAT16_VALUE(   959.00), SIMDE_FLOAT16_VALUE(  -717.00), SIMDE_FLOAT16_VALUE(  -903.50), SIMDE_FLOAT16_VALUE(   656.00) },
      { SIMDE_FLOAT16_VALUE( 42144.00), SIMDE_FLOAT16_VALUE( 22304.00), SIMDE_FLOAT16_VALUE(  -259.00), SIMDE_FLOAT16_VALUE(  -680.00),
        SIMDE_FLOAT16_VALUE(     2.72), SIMDE_FLOAT16_VALUE(  -716.00), SIMDE_FLOAT16_VALUE(    -3.54), SIMDE_FLOAT16_VALUE( -2656.00) } },
    { { UINT16_C(30015), UINT16_C(41645), UINT16_C(28607), UINT16_C( 7718), UINT16_C(21653), UINT16_C(45347), UINT16_C(65081), UINT16_C(32637) },
      { SIMDE_FLOAT16_VALUE(   -32.66), SIMDE_FLOAT16_VALUE(   785.00), SIMDE_FLOAT16_VALUE(  -794.00), SIMDE_FLOAT16_VALUE(   797.00),
        SIMDE_FLOAT16_VALUE(   621.50), SIMDE_FLOAT16_VALUE(    75.69), SIMDE_FLOAT16_VALUE(  -526.50), SIMDE_FLOAT16_VALUE(   321.00) },
      { SIMDE_FLOAT16_VALUE(   353.00), SIMDE_FLOAT16_VALUE(   213.62), SIMDE_FLOAT16_VALUE(   576.00), SIMDE_FLOAT16_VALUE(   312.25),
        SIMDE_FLOAT16_VALUE(   496.50), SIMDE_FLOAT16_VALUE(   672.50), SIMDE_FLOAT16_VALUE(   -31.95), SIMDE_FLOAT16_VALUE(  -105.12) },
      { SIMDE_FLOAT16_VALUE(   146.62), SIMDE_FLOAT16_VALUE( 50176.00), SIMDE_FLOAT16_VALUE(   794.00), SIMDE_FLOAT16_VALUE(     3.44),
        SIMDE_FLOAT16_VALUE(    15.65), SIMDE_FLOAT16_VALUE(    35.09), SIMDE_FLOAT16_VALUE(  -750.50), SIMDE_FLOAT16_VALUE(  -353.50) } },
    { { UINT16_C(50389), UINT16_C(37897), UINT16_C(12083), UINT16_C(51635), UINT16_C(54916), UINT16_C(48506), UINT16_C(63444), UINT16_C(49980) },
      { SIMDE_FLOAT16_VALUE(   434.25), SIMDE_FLOAT16_VALUE(   -38.09), SIMDE_FLOAT16_VALUE(    23.38), SIMDE_FLOAT16_VALUE(    55.78),
        SIMDE_FLOAT16_VALUE(  -962.50), SIMDE_FLOAT16_VALUE(   496.75), SIMDE_FLOAT16_VALUE(  -623.00), SIMDE_FLOAT16_VALUE(   390.50) },
      { SIMDE_FLOAT16_VALUE(  -289.75), SIMDE_FLOAT16_VALUE(   953.00), SIMDE_FLOAT16_VALUE(  -297.25), SIMDE_FLOAT16_VALUE(  -793.50),
        SIMDE_FLOAT16_VALUE(   625.50), SIMDE_FLOAT16_VALUE(   671.00), SIMDE_FLOAT16_VALUE(   101.56), SIMDE_FLOAT16_VALUE(   561.50) },
      { SIMDE_FLOAT16_VALUE(   304.75), SIMDE_FLOAT16_VALUE(-15256.00), SIMDE_FLOAT16_VALUE(  -357.00), SIMDE_FLOAT16_VALUE(   856.50),
        SIMDE_FLOAT16_VALUE(  -883.50), SIMDE_FLOAT16_VALUE(   337.50), SIMDE_FLOAT16_VALUE(  -622.50), SIMDE_FLOAT16_VALUE(   813.50) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint16x8_t a = simde_vld1q_u16(test_vec[i].a);
    simde_float16x8_t b = simde_vld1q_f16(test_vec[i].b);
    simde_float16x8_t c = simde_vld1q_f16(test_vec[i].c);
    simde_float16x8_t r = simde_vbslq_f16(a, b, c);
    simde_test_arm_neon_assert_equal_f16x8(r, simde_vld1q_f16(test_vec[i].r), 1);
  }

  return 0;
}

static int
test_simde_vbslq_f32 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    uint32_t a[4];
    simde_float32 b[4];
    simde_float32 c[4];
    simde_float32 r[4];
  } test_vec[] = {
    { { UINT32_C(2050512422), UINT32_C(1891785275), UINT32_C(3601774981), UINT32_C( 108127079) },
      { SIMDE_FLOAT32_C(   726.27), SIMDE_FLOAT32_C(  -285.01), SIMDE_FLOAT32_C(   100.31), SIMDE_FLOAT32_C(  -361.34) },
      { SIMDE_FLOAT32_C(   922.89), SIMDE_FLOAT32_C(   266.21), SIMDE_FLOAT32_C(   203.26), SIMDE_FLOAT32_C(   423.67) },
      { SIMDE_FLOAT32_C(   986.89), SIMDE_FLOAT32_C(   270.01), SIMDE_FLOAT32_C(   403.71), SIMDE_FLOAT32_C(   357.43) } },
    { { UINT32_C(3614509257), UINT32_C( 280160490), UINT32_C(2039147070), UINT32_C(3404352837) },
      { SIMDE_FLOAT32_C(   -48.71), SIMDE_FLOAT32_C(   -96.93), SIMDE_FLOAT32_C(   765.30), SIMDE_FLOAT32_C(  -365.42) },
      { SIMDE_FLOAT32_C(    51.72), SIMDE_FLOAT32_C(   310.81), SIMDE_FLOAT32_C(   707.75), SIMDE_FLOAT32_C(  -222.02) },
      { SIMDE_FLOAT32_C(   -51.72), SIMDE_FLOAT32_C(   275.62), SIMDE_FLOAT32_C(   745.28), SIMDE_FLOAT32_C(  -364.04) } },
    { { UINT32_C(1311624492), UINT32_C(2429832391), UINT32_C(1046955348), UINT32_C(1800345901) },
      { SIMDE_FLOAT32_C(   173.43), SIMDE_FLOAT32_C(   396.70), SIMDE_FLOAT32_C(  -158.88), SIMDE_FLOAT32_C(   270.13) },
      { SIMDE_FLOAT32_C(   511.35), SIMDE_FLOAT32_C(  -236.38), SIMDE_FLOAT32_C(  -423.74), SIMDE_FLOAT32_C(  -537.35) },
      { SIMDE_FLOAT32_C(   510.85), SIMDE_FLOAT32_C(   472.82), SIMDE_FLOAT32_C(  -301.72), SIMDE_FLOAT32_C(-34646.40) } },
    { { UINT32_C(3818566759), UINT32_C(4063432390), UINT32_C(2722128091), UINT32_C(   3347628) },
      { SIMDE_FLOAT32_C(   968.99), SIMDE_FLOAT32_C(   614.68), SIMDE_FLOAT32_C(  -913.19), SIMDE_FLOAT32_C(   634.92) },
      { SIMDE_FLOAT32_C(   -20.17), SIMDE_FLOAT32_C(  -778.48), SIMDE_FLOAT32_C(   528.43), SIMDE_FLOAT32_C(  -846.74) },
      { SIMDE_FLOAT32_C(     2.80), SIMDE_FLOAT32_C(   838.42), SIMDE_FLOAT32_C(  -785.42), SIMDE_FLOAT32_C(  -842.94) } },
    { { UINT32_C(2382485607), UINT32_C( 247141543), UINT32_C(2415023561), UINT32_C(1065493860) },
      { SIMDE_FLOAT32_C(   927.69), SIMDE_FLOAT32_C(   298.66), SIMDE_FLOAT32_C(  -205.27), SIMDE_FLOAT32_C(   460.63) },
      { SIMDE_FLOAT32_C(  -702.09), SIMDE_FLOAT32_C(  -280.47), SIMDE_FLOAT32_C(   122.07), SIMDE_FLOAT32_C(  -733.10) },
      { SIMDE_FLOAT32_C(   703.21), SIMDE_FLOAT32_C(  -298.47), SIMDE_FLOAT32_C(  -196.40), SIMDE_FLOAT32_C(  -366.52) } },
    { { UINT32_C(1673032367), UINT32_C(1729866496), UINT32_C( 720706691), UINT32_C(4198084657) },
      { SIMDE_FLOAT32_C(  -540.17), SIMDE_FLOAT32_C(   251.09), SIMDE_FLOAT32_C(   225.13), SIMDE_FLOAT32_C(   954.24) },
      { SIMDE_FLOAT32_C(  -734.26), SIMDE_FLOAT32_C(  -103.09), SIMDE_FLOAT32_C(    61.68), SIMDE_FLOAT32_C(  -806.57) },
      { SIMDE_FLOAT32_C(  -542.04), SIMDE_FLOAT32_C(  -446.06), SIMDE_FLOAT32_C(    56.91), SIMDE_FLOAT32_C(   930.07) } },
    { { UINT32_C(2768866254), UINT32_C(1356217504), UINT32_C(2931003054), UINT32_C(3172323130) },
      { SIMDE_FLOAT32_C(  -417.88), SIMDE_FLOAT32_C(  -357.81), SIMDE_FLOAT32_C(  -174.77), SIMDE_FLOAT32_C(   472.44) },
      { SIMDE_FLOAT32_C(  -587.42), SIMDE_FLOAT32_C(  -441.94), SIMDE_FLOAT32_C(  -296.02), SIMDE_FLOAT32_C(  -127.59) },
      { SIMDE_FLOAT32_C(    -9.18), SIMDE_FLOAT32_C(  -309.79), SIMDE_FLOAT32_C(  -166.52), SIMDE_FLOAT32_C(   476.31) } },
    { { UINT32_C(2620104780), UINT32_C(2037634475), UINT32_C(  18775136), UINT32_C(1716647096) },
      { SIMDE_FLOAT32_C(   -62.34), SIMDE_FLOAT32_C(   454.95), SIMDE_FLOAT32_C(  -901.11), SIMDE_FLOAT32_C(    30.12) },
      { SIMDE_FLOAT32_C(   146.40), SIMDE_FLOAT32_C(  -437.09), SIMDE_FLOAT32_C(   -77.62), SIMDE_FLOAT32_C(   728.52) },
      { SIMDE_FLOAT32_C(  -185.27), SIMDE_FLOAT32_C(  -470.72), SIMDE_FLOAT32_C(   -64.63), SIMDE_FLOAT32_C(     3.86) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint32x4_t a = simde_vld1q_u32(test_vec[i].a);
    simde_float32x4_t b = simde_vld1q_f32(test_vec[i].b);
    simde_float32x4_t c = simde_vld1q_f32(test_vec[i].c);
    simde_float32x4_t r = simde_vbslq_f32(a, b, c);
    simde_test_arm_neon_assert_equal_f32x4(r, simde_vld1q_f32(test_vec[i].r), 1);
  }

  return 0;
}

static int
test_simde_vbslq_f64 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    uint64_t a[2];
    simde_float64 b[2];
    simde_float64 c[2];
    simde_float64 r[2];
  } test_vec[] = {
    { { UINT64_C(13764238683935597897), UINT64_C(16898862026458326254) },
      { SIMDE_FLOAT64_C(  -774.89), SIMDE_FLOAT64_C(  -747.47) },
      { SIMDE_FLOAT64_C(  -332.23), SIMDE_FLOAT64_C(   521.67) },
      { SIMDE_FLOAT64_C(  -266.47), SIMDE_FLOAT64_C(  -651.66) } },
    { { UINT64_C(13223275955338830799), UINT64_C( 7046989072648393554) },
      { SIMDE_FLOAT64_C(   994.41), SIMDE_FLOAT64_C(   822.45) },
      { SIMDE_FLOAT64_C(  -294.88), SIMDE_FLOAT64_C(  -105.01) },
      { SIMDE_FLOAT64_C( 75509.48), SIMDE_FLOAT64_C( -1640.90) } },
    { { UINT64_C(11175800480316490419), UINT64_C( 9412372685746910188) },
      { SIMDE_FLOAT64_C(   757.22), SIMDE_FLOAT64_C(  -233.80) },
      { SIMDE_FLOAT64_C(   -54.26), SIMDE_FLOAT64_C(   966.12) },
      { SIMDE_FLOAT64_C(    38.32), SIMDE_FLOAT64_C(    -3.65) } },
    { { UINT64_C(13983593746892684661), UINT64_C(  316639219210923907) },
      { SIMDE_FLOAT64_C(  -380.48), SIMDE_FLOAT64_C(   397.51) },
      { SIMDE_FLOAT64_C(   -87.86), SIMDE_FLOAT64_C(   -48.58) },
      { SIMDE_FLOAT64_C(   -95.11), SIMDE_FLOAT64_C(  -198.32) } },
    { { UINT64_C(11225398681450588207), UINT64_C(16926446589552624066) },
      { SIMDE_FLOAT64_C(   635.25), SIMDE_FLOAT64_C(   381.12) },
      { SIMDE_FLOAT64_C(  -832.41), SIMDE_FLOAT64_C(  -124.32) },
      { SIMDE_FLOAT64_C(   592.41), SIMDE_FLOAT64_C(   509.34) } },
    { { UINT64_C(18076222544372871973), UINT64_C( 4870150017706326817) },
      { SIMDE_FLOAT64_C(  -197.71), SIMDE_FLOAT64_C(  -523.67) },
      { SIMDE_FLOAT64_C(   628.41), SIMDE_FLOAT64_C(   -93.61) },
      { SIMDE_FLOAT64_C(   -49.31), SIMDE_FLOAT64_C( -8890.06) } },
    { { UINT64_C( 2218233479757940575), UINT64_C(14533229422664185268) },
      { SIMDE_FLOAT64_C(   537.41), SIMDE_FLOAT64_C(   -64.67) },
      { SIMDE_FLOAT64_C(  -883.30), SIMDE_FLOAT64_C(  -802.50) },
      { SIMDE_FLOAT64_C(  -625.43), SIMDE_FLOAT64_C(    -6.30) } },
    { { UINT64_C( 2444631349764358662), UINT64_C( 3147906818953694066) },
      { SIMDE_FLOAT64_C(   483.18), SIMDE_FLOAT64_C(   409.15) },
      { SIMDE_FLOAT64_C(  -524.40), SIMDE_FLOAT64_C(   755.41) },
      { SIMDE_FLOAT64_C(  -227.58), SIMDE_FLOAT64_C(    12.79) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint64x2_t a = simde_vld1q_u64(test_vec[i].a);
    simde_float64x2_t b = simde_vld1q_f64(test_vec[i].b);
    simde_float64x2_t c = simde_vld1q_f64(test_vec[i].c);
    simde_float64x2_t r = simde_vbslq_f64(a, b, c);

    simde_test_arm_neon_assert_equal_f64x2(r, simde_vld1q_f64(test_vec[i].r), 1);
  }

  return 0;
}

static int
test_simde_vbslq_s8 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    uint8_t a[16];
    int8_t b[16];
    int8_t c[16];
    int8_t r[16];
  } test_vec[] = {
    { { UINT8_C(136), UINT8_C(230), UINT8_C( 97), UINT8_C(  0), UINT8_C( 20), UINT8_C( 50), UINT8_C(138), UINT8_C(231),
           UINT8_MAX, UINT8_C( 18), UINT8_C(190), UINT8_C(185), UINT8_C(181), UINT8_C( 25), UINT8_C( 53), UINT8_C(  6) },
      {  INT8_C(  60), -INT8_C(  30),  INT8_C(  93), -INT8_C(  89), -INT8_C(   3),  INT8_C( 121),  INT8_C(  83), -INT8_C( 123),
         INT8_C( 102), -INT8_C( 115), -INT8_C(  97), -INT8_C(  39), -INT8_C( 104),  INT8_C(  82), -INT8_C(  24),  INT8_C(  32) },
      {  INT8_C(  56),  INT8_C(  73),  INT8_C(  32),  INT8_C(  76),  INT8_C( 123), -INT8_C(  85),  INT8_C(  51),  INT8_C( 122),
        -INT8_C(  67), -INT8_C(  15),  INT8_C(  51),  INT8_C( 114),  INT8_C(  11),  INT8_C( 104),  INT8_C( 120),  INT8_C(  71) },
      {  INT8_C(  56), -INT8_C(  21),  INT8_C(  65),  INT8_C(  76),      INT8_MAX, -INT8_C(  71),  INT8_C(  51), -INT8_C(  99),
         INT8_C( 102), -INT8_C(  31), -INT8_C(  97), -INT8_C(  37), -INT8_C( 102),  INT8_C( 112),  INT8_C( 104),  INT8_C(  65) } },
    { { UINT8_C( 74), UINT8_C(214), UINT8_C(238), UINT8_C( 71), UINT8_C( 79), UINT8_C( 65), UINT8_C(204), UINT8_C(181),
        UINT8_C(207), UINT8_C(107), UINT8_C(142), UINT8_C(103), UINT8_C(189), UINT8_C(118), UINT8_C(136), UINT8_C(245) },
      { -INT8_C(  65), -INT8_C(  88),  INT8_C(  65),  INT8_C(  58),  INT8_C(  83),  INT8_C( 117), -INT8_C(  76),  INT8_C(  17),
         INT8_C( 102), -INT8_C(  25), -INT8_C( 125),  INT8_C( 113),  INT8_C(  79), -INT8_C(   4), -INT8_C(  72), -INT8_C( 103) },
      { -INT8_C(  46), -INT8_C(  90), -INT8_C(  32),  INT8_C(  33), -INT8_C(  24), -INT8_C(  84), -INT8_C(  42), -INT8_C(  73),
         INT8_C(  23),  INT8_C( 100),  INT8_C(  30), -INT8_C(  44), -INT8_C(  37), -INT8_C(  90), -INT8_C(  55), -INT8_C( 102) },
      { -INT8_C( 102), -INT8_C(  96),  INT8_C(  64),  INT8_C(  34), -INT8_C(  29), -INT8_C(  19), -INT8_C( 106),  INT8_C(  19),
         INT8_C(  86),  INT8_C( 103), -INT8_C( 110), -INT8_C(  15),  INT8_C(  79), -INT8_C(  12), -INT8_C(  55), -INT8_C( 101) } },
    { { UINT8_C( 79), UINT8_C( 11), UINT8_C(213), UINT8_C(162), UINT8_C(128), UINT8_C(137), UINT8_C(179), UINT8_C(230),
        UINT8_C(113), UINT8_C( 55), UINT8_C( 88), UINT8_C(192), UINT8_C( 51), UINT8_C( 16), UINT8_C( 90), UINT8_C(  5) },
      { -INT8_C(  73),  INT8_C(  58),  INT8_C(  38), -INT8_C(  97), -INT8_C(  25), -INT8_C(   4),  INT8_C(  86), -INT8_C(   2),
         INT8_C(  96),  INT8_C( 116), -INT8_C(  45),  INT8_C(  59),  INT8_C(  27), -INT8_C( 100), -INT8_C(  42),  INT8_C( 106) },
      { -INT8_C(  89), -INT8_C(  85),  INT8_C(  12),  INT8_C(  39),  INT8_C(  52), -INT8_C(  64),  INT8_C(  14), -INT8_C(  91),
        -INT8_C(   9),  INT8_C( 102),  INT8_C( 102),  INT8_C(  42),  INT8_C( 118), -INT8_C(  64),  INT8_C(  47),  INT8_C(  45) },
      { -INT8_C(  89), -INT8_C(  86),  INT8_C(  12), -INT8_C( 121), -INT8_C(  76), -INT8_C(  56),  INT8_C(  30), -INT8_C(  25),
        -INT8_C(  26),  INT8_C( 116),  INT8_C( 118),  INT8_C(  42),  INT8_C(  87), -INT8_C(  48),  INT8_C( 119),  INT8_C(  40) } },
    { { UINT8_C(250), UINT8_C( 85), UINT8_C(204), UINT8_C(225), UINT8_C( 81), UINT8_C( 34), UINT8_C(224), UINT8_C(177),
        UINT8_C(151), UINT8_C(179), UINT8_C(237), UINT8_C(178), UINT8_C( 79), UINT8_C(195), UINT8_C( 28), UINT8_C(247) },
      {  INT8_C( 110),  INT8_C(  40),  INT8_C(  30), -INT8_C(  94), -INT8_C(  24),  INT8_C(  44),  INT8_C(  72), -INT8_C(  33),
        -INT8_C( 110), -INT8_C(  82),  INT8_C(   9),  INT8_C(   9),  INT8_C( 110),  INT8_C(  56),  INT8_C(  54),  INT8_C( 104) },
      { -INT8_C( 115),  INT8_C(   3),  INT8_C(  74), -INT8_C(  34),  INT8_C(  37),  INT8_C(  42), -INT8_C( 112), -INT8_C(  68),
        -INT8_C(  35),  INT8_C( 125),  INT8_C( 110),  INT8_C(  44),  INT8_C(  64), -INT8_C( 118),  INT8_C(  35), -INT8_C(  82) },
      {  INT8_C( 111),  INT8_C(   2),  INT8_C(  14), -INT8_C(  66),  INT8_C( 100),  INT8_C(  40),  INT8_C(  80), -INT8_C(  99),
        -INT8_C(  38), -INT8_C(  18),  INT8_C(  11),  INT8_C(  12),  INT8_C(  78),  INT8_C(   8),  INT8_C(  55),  INT8_C( 104) } },
    { { UINT8_C(179), UINT8_C( 66), UINT8_C( 80), UINT8_C(155), UINT8_C(110), UINT8_C(152), UINT8_C(123), UINT8_C(  1),
        UINT8_C( 70), UINT8_C(132), UINT8_C( 10), UINT8_C(180), UINT8_C(189), UINT8_C( 64), UINT8_C( 29), UINT8_C( 74) },
      {  INT8_C(  67),  INT8_C( 103),  INT8_C(  41),  INT8_C( 105), -INT8_C( 111), -INT8_C(  71),  INT8_C(  37),  INT8_C( 110),
         INT8_C(  54), -INT8_C( 108), -INT8_C( 102),  INT8_C( 118),  INT8_C(  30), -INT8_C(  66),  INT8_C(  36), -INT8_C(  47) },
      {  INT8_C(   0),  INT8_C( 116),  INT8_C( 109),  INT8_C( 110),  INT8_C(  13), -INT8_C(  24),  INT8_C( 111),  INT8_C(  83),
         INT8_C( 108),  INT8_C( 121),  INT8_C(   8),  INT8_C(  41), -INT8_C(  70),  INT8_C(  37),  INT8_C( 116), -INT8_C(   3) },
      {  INT8_C(   3),  INT8_C( 118),  INT8_C(  45),  INT8_C( 109),  INT8_C(   1), -INT8_C(   8),  INT8_C(  37),  INT8_C(  82),
         INT8_C(  46), -INT8_C(   3),  INT8_C(  10),  INT8_C(  61),  INT8_C(  30),  INT8_C(  37),  INT8_C( 100), -INT8_C(  11) } },
    { { UINT8_C(140), UINT8_C(157), UINT8_C(102), UINT8_C( 29), UINT8_C( 86), UINT8_C(140), UINT8_C(139), UINT8_C(140),
        UINT8_C( 32), UINT8_C( 37), UINT8_C(  2), UINT8_C( 62), UINT8_C(227), UINT8_C( 38), UINT8_C( 16), UINT8_C(227) },
      { -INT8_C( 102),  INT8_C( 125),  INT8_C(  82), -INT8_C(  89),  INT8_C( 101), -INT8_C(  63), -INT8_C(   5), -INT8_C(  47),
         INT8_C(  59),  INT8_C(   3), -INT8_C(   5), -INT8_C(  11),  INT8_C(  40),  INT8_C( 111), -INT8_C(  14), -INT8_C(  76) },
      {  INT8_C(  12),  INT8_C(  89), -INT8_C(  47),  INT8_C(  98), -INT8_C(  27),  INT8_C(  92), -INT8_C(  18),  INT8_C(   5),
        -INT8_C( 127), -INT8_C(  16),  INT8_C(  67),  INT8_C( 101),  INT8_C(  22),  INT8_C(  83),  INT8_C(  72), -INT8_C(  80) },
      { -INT8_C( 120),  INT8_C(  93), -INT8_C(  45),  INT8_C( 103), -INT8_C(  27), -INT8_C(  48), -INT8_C(  17), -INT8_C( 127),
        -INT8_C(  95), -INT8_C(  47),  INT8_C(  67),  INT8_C( 117),  INT8_C(  52),  INT8_C( 119),  INT8_C(  88), -INT8_C(  80) } },
    { { UINT8_C(208), UINT8_C(154), UINT8_C( 88), UINT8_C( 53), UINT8_C( 92), UINT8_C( 83), UINT8_C(  7), UINT8_C(151),
        UINT8_C( 86), UINT8_C(  2), UINT8_C(140), UINT8_C(126), UINT8_C(113), UINT8_C(126), UINT8_C( 50), UINT8_C(125) },
      { -INT8_C(  41),  INT8_C(   3), -INT8_C(  33), -INT8_C(  68),  INT8_C(  95), -INT8_C(  51), -INT8_C(  63), -INT8_C(  32),
        -INT8_C(  67),  INT8_C(   5),  INT8_C(  69), -INT8_C(  45),  INT8_C(  88), -INT8_C( 114), -INT8_C( 125),  INT8_C(  41) },
      {  INT8_C(  40), -INT8_C(  37),  INT8_C(  94), -INT8_C( 124),  INT8_C(  46),  INT8_C( 101),  INT8_C(  27), -INT8_C( 124),
         INT8_C( 103), -INT8_C(  89),  INT8_C(   2), -INT8_C(  40),  INT8_C(  38),  INT8_C(  52),  INT8_C(  85), -INT8_C(   3) },
      { -INT8_C(   8),  INT8_C(  67),  INT8_C(  94), -INT8_C(  76),  INT8_C( 126),  INT8_C( 101),  INT8_C(  25),      INT8_MIN,
         INT8_C(  53), -INT8_C(  91),  INT8_C(   6), -INT8_C(  46),  INT8_C(  86),  INT8_C(  14),  INT8_C(  71), -INT8_C(  87) } },
    { { UINT8_C( 55), UINT8_C( 52), UINT8_C(186), UINT8_C(150), UINT8_C(  1), UINT8_C(123), UINT8_C(119), UINT8_C(190),
        UINT8_C(128), UINT8_C(188), UINT8_C(145), UINT8_C(217), UINT8_C( 74), UINT8_C( 21), UINT8_C(  2), UINT8_C(115) },
      { -INT8_C(  16),  INT8_C(  96), -INT8_C(   9),  INT8_C(  31), -INT8_C(  58),  INT8_C(  19), -INT8_C(  93),  INT8_C(  45),
        -INT8_C(  70), -INT8_C(  90),  INT8_C(   6), -INT8_C(  32), -INT8_C(  38),  INT8_C(  91), -INT8_C(  34),  INT8_C(  18) },
      { -INT8_C( 112), -INT8_C( 104), -INT8_C(  88), -INT8_C( 111),  INT8_C(  19),  INT8_C(  31),  INT8_C(  80), -INT8_C( 108),
        -INT8_C(  36), -INT8_C(  31),  INT8_C( 109),  INT8_C(  38), -INT8_C(  10),  INT8_C( 111), -INT8_C( 103), -INT8_C(  25) },
      { -INT8_C(  80), -INT8_C(  88), -INT8_C(  78),  INT8_C(  23),  INT8_C(  18),  INT8_C(  23),  INT8_C(  35),  INT8_C(  44),
        -INT8_C(  36), -INT8_C(  27),  INT8_C( 108), -INT8_C(  26), -INT8_C(   2),  INT8_C( 123), -INT8_C( 101), -INT8_C( 106) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint8x16_t a = simde_vld1q_u8(test_vec[i].a);
    simde_int8x16_t b = simde_vld1q_s8(test_vec[i].b);
    simde_int8x16_t c = simde_vld1q_s8(test_vec[i].c);
    simde_int8x16_t r = simde_vbslq_s8(a, b, c);

    simde_test_arm_neon_assert_equal_i8x16(r, simde_vld1q_s8(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vbslq_s16 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    uint16_t a[8];
    int16_t b[8];
    int16_t c[8];
    int16_t r[8];
  } test_vec[] = {
    { { UINT16_C(29959), UINT16_C( 5999), UINT16_C(39015), UINT16_C(20558), UINT16_C(58240), UINT16_C(60934), UINT16_C(14982), UINT16_C(23147) },
      {  INT16_C( 25631),  INT16_C( 21395), -INT16_C( 29489), -INT16_C(  5080),  INT16_C( 13097), -INT16_C( 13303), -INT16_C( 17379),  INT16_C(  9417) },
      {  INT16_C( 14385), -INT16_C( 26564), -INT16_C( 30000),  INT16_C( 20712), -INT16_C(  4498), -INT16_C(  3010), -INT16_C( 21976),  INT16_C( 18254) },
      {  INT16_C( 27703), -INT16_C( 25837), -INT16_C( 29993),  INT16_C( 16552),  INT16_C( 12142), -INT16_C(  9160), -INT16_C( 18388),  INT16_C(  1357) } },
    { { UINT16_C(57870), UINT16_C(56730), UINT16_C(49774), UINT16_C(38857), UINT16_C(54005), UINT16_C( 4707), UINT16_C(11407), UINT16_C(49207) },
      {  INT16_C( 29540),  INT16_C( 13657),  INT16_C( 16893),  INT16_C( 27525), -INT16_C( 15312),  INT16_C( 22623), -INT16_C( 20882),  INT16_C( 31904) },
      {  INT16_C( 14992), -INT16_C(   422),  INT16_C(  9213), -INT16_C(  3434), -INT16_C(  1546), -INT16_C( 31483),  INT16_C( 15398), -INT16_C( 30139) },
      {  INT16_C( 31380),  INT16_C( 14168),  INT16_C( 25085),  INT16_C( 25495), -INT16_C(  5838), -INT16_C( 27321),  INT16_C( 15406),  INT16_C( 19040) } },
    { { UINT16_C(40623), UINT16_C(44223), UINT16_C(17888), UINT16_C( 4120), UINT16_C(30473), UINT16_C(30568), UINT16_C( 2085), UINT16_C(46579) },
      {  INT16_C( 19779),  INT16_C( 16564),  INT16_C( 19057),  INT16_C( 26418),  INT16_C( 14147),  INT16_C( 27116),  INT16_C( 12659),  INT16_C(  8948) },
      { -INT16_C( 19504), -INT16_C( 20273), -INT16_C(  6152),  INT16_C(   448),  INT16_C( 10334), -INT16_C( 31624),  INT16_C( 27697),  INT16_C( 29753) },
      {  INT16_C( 11603),  INT16_C(  4340), -INT16_C(  7560),  INT16_C(   464),  INT16_C( 16215), -INT16_C(  7816),  INT16_C( 25649),  INT16_C( 24824) } },
    { { UINT16_C(60857), UINT16_C(10932), UINT16_C(58935), UINT16_C(31633), UINT16_C(32030), UINT16_C(37348), UINT16_C(55471), UINT16_C(32692) },
      { -INT16_C( 31860), -INT16_C( 31697), -INT16_C(  4246), -INT16_C( 14202), -INT16_C(   489),  INT16_C( 18508), -INT16_C( 31126),  INT16_C(  9404) },
      {  INT16_C( 28787), -INT16_C( 21682), -INT16_C(  8105),  INT16_C( 29990),  INT16_C(  2653),  INT16_C(  3078), -INT16_C( 17693),  INT16_C( 28555) },
      { -INT16_C( 28214), -INT16_C( 32402), -INT16_C(  6558),  INT16_C( 19622),  INT16_C( 32343),  INT16_C(  3142), -INT16_C( 23958),  INT16_C(  9407) } },
    { { UINT16_C(47677), UINT16_C(42995), UINT16_C(31145), UINT16_C(49520), UINT16_C(48248), UINT16_C(57865), UINT16_C(50754), UINT16_C(46598) },
      {  INT16_C( 21814), -INT16_C( 29343), -INT16_C( 30923), -INT16_C( 28158),  INT16_C(  2449),  INT16_C( 29855),  INT16_C( 10947),  INT16_C(   483) },
      { -INT16_C( 10267), -INT16_C( 29016),  INT16_C(  6224), -INT16_C( 14257),  INT16_C( 22997),  INT16_C(  6059), -INT16_C( 20193),  INT16_C( 21965) },
      {  INT16_C( 22004), -INT16_C( 29335),  INT16_C(   369), -INT16_C( 30705),  INT16_C( 18837),  INT16_C( 30123),  INT16_C( 13151),  INT16_C( 16843) } },
    { { UINT16_C(11782), UINT16_C(15331), UINT16_C(58805), UINT16_C(18382), UINT16_C(28142), UINT16_C(45755), UINT16_C(40855), UINT16_C(31923) },
      {  INT16_C( 23414), -INT16_C( 14837),  INT16_C( 23156),  INT16_C( 18831),  INT16_C( 15027), -INT16_C( 11680),  INT16_C( 12011), -INT16_C(  3544) },
      {  INT16_C(  2908),  INT16_C(  4653), -INT16_C(  1040), -INT16_C(  8359),  INT16_C(  5224),  INT16_C(   145),  INT16_C( 17587),  INT16_C( 10620) },
      {  INT16_C(  2910),  INT16_C(   527),  INT16_C( 23156), -INT16_C(  9825),  INT16_C( 14498), -INT16_C( 28128),  INT16_C( 20131),  INT16_C( 29036) } },
    { { UINT16_C(34719), UINT16_C( 5104), UINT16_C(32738), UINT16_C(38236), UINT16_C(48569), UINT16_C(42088), UINT16_C(37099), UINT16_C(18326) },
      { -INT16_C( 15205), -INT16_C( 29863), -INT16_C( 19777),  INT16_C( 10346), -INT16_C(  1081),  INT16_C( 31272), -INT16_C( 23489), -INT16_C(  8284) },
      { -INT16_C( 27604),  INT16_C(  3826),  INT16_C( 20243), -INT16_C( 13149),  INT16_C(  2828), -INT16_C(  2192),  INT16_C(  1947),  INT16_C( 13886) },
      { -INT16_C( 27461),  INT16_C(  3922),  INT16_C( 12979),  INT16_C( 18667), -INT16_C( 17531),  INT16_C( 29496), -INT16_C( 30917),  INT16_C( 30636) } },
    { { UINT16_C(39115), UINT16_C(35522), UINT16_C(11338), UINT16_C( 4530), UINT16_C(55848), UINT16_C(26508), UINT16_C(12415), UINT16_C(43846) },
      {  INT16_C( 14788), -INT16_C( 10311),  INT16_C( 23688), -INT16_C( 27485),  INT16_C(  4968),  INT16_C(   907), -INT16_C( 14054), -INT16_C(  6854) },
      { -INT16_C(   927), -INT16_C( 21392),  INT16_C(  8744),  INT16_C( 20669),  INT16_C( 18941),  INT16_C( 31928), -INT16_C(   391),  INT16_C( 15655) },
      {  INT16_C( 31968), -INT16_C( 22864),  INT16_C(  3624),  INT16_C( 20655),  INT16_C(  5117),  INT16_C(  7096), -INT16_C( 12774), -INT16_C( 19165) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint16x8_t a = simde_vld1q_u16(test_vec[i].a);
    simde_int16x8_t b = simde_vld1q_s16(test_vec[i].b);
    simde_int16x8_t c = simde_vld1q_s16(test_vec[i].c);
    simde_int16x8_t r = simde_vbslq_s16(a, b, c);

    simde_test_arm_neon_assert_equal_i16x8(r, simde_vld1q_s16(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vbslq_s32 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    uint32_t a[4];
    int32_t b[4];
    int32_t c[4];
    int32_t r[4];
  } test_vec[] = {
    { { UINT32_C( 166371924), UINT32_C(3163181267), UINT32_C( 825615355), UINT32_C(4176949107) },
      { -INT32_C(    45381750),  INT32_C(   849081286), -INT32_C(  1238516410),  INT32_C(  1893146651) },
      { -INT32_C(  1787182654),  INT32_C(   206636049),  INT32_C(  1514047463),  INT32_C(  1079129526) },
      { -INT32_C(  1654930558),  INT32_C(   819680450),  INT32_C(  2049942854),  INT32_C(  1893150871) } },
    { { UINT32_C(2185076156), UINT32_C(3619018896), UINT32_C(2978865814), UINT32_C(3290522626) },
      {  INT32_C(   928619301), -INT32_C(  2042385505), -INT32_C(   387940046),  INT32_C(  1932014518) },
      {  INT32_C(  1643472336), -INT32_C(   751261123), -INT32_C(  1887058547),  INT32_C(  1330947626) },
      {  INT32_C(  1675229540), -INT32_C(  2046186819), -INT32_C(  1367309029),  INT32_C(  1265934890) } },
    { { UINT32_C(3766922561), UINT32_C(2321992280), UINT32_C(  41043787), UINT32_C(1249221242) },
      {  INT32_C(  1034644223), -INT32_C(  1575951595), -INT32_C(   751725143),  INT32_C(  2099414332) },
      { -INT32_C(  1956730573), -INT32_C(  1105804173), -INT32_C(  2050979829),  INT32_C(   584070435) },
      {  INT32_C(   735717491), -INT32_C(  1240414669), -INT32_C(  2018472695),  INT32_C(  1755358521) } },
    { { UINT32_C(3042933664), UINT32_C( 139948127), UINT32_C(1104906245), UINT32_C(1103101198) },
      {  INT32_C(   432807334), -INT32_C(   304553247), -INT32_C(  1905092501),  INT32_C(  1857045198) },
      {  INT32_C(   488837310), -INT32_C(  2061141376),  INT32_C(   281477122), -INT32_C(  1538160899) },
      {  INT32_C(   426514878), -INT32_C(  1922012479),  INT32_C(   274106371), -INT32_C(   454016257) } },
    { { UINT32_C(2226986659), UINT32_C(1802605824), UINT32_C(4244235310), UINT32_C(3832195622) },
      {  INT32_C(   973180346),  INT32_C(   163522055),  INT32_C(   605718054), -INT32_C(  1345819892) },
      { -INT32_C(  1976269431),  INT32_C(  1240835355), -INT32_C(  1337593975),  INT32_C(  1402253209) },
      {  INT32_C(   167873962),  INT32_C(   162866203),  INT32_C(   605851559), -INT32_C(  1210306659) } },
    { { UINT32_C(1133352508), UINT32_C(3813428412), UINT32_C(3741804243), UINT32_C(1536151506) },
      {  INT32_C(  1877328724), -INT32_C(   222766232),  INT32_C(  1671626186), -INT32_C(   390711636) },
      { -INT32_C(  1993653300),  INT32_C(  1651275919), -INT32_C(  1337822242), -INT32_C(  1777544894) },
      { -INT32_C(   878197804), -INT32_C(   500664277),  INT32_C(  1665299918), -INT32_C(   863627648) } },
    { { UINT32_C(4228313492), UINT32_C(2532228812), UINT32_C(1761185980), UINT32_C(2471604167) },
      { -INT32_C(  2112062222), -INT32_C(   739997452),  INT32_C(  1032005371), -INT32_C(  1949003785) },
      {  INT32_C(  1300814465),  INT32_C(  1424258712), -INT32_C(   826417913),  INT32_C(  2137067149) },
      { -INT32_C(  2121500015), -INT32_C(   756758316), -INT32_C(  1366995525), -INT32_C(   277835825) } },
    { { UINT32_C(2130804362), UINT32_C(  38987270), UINT32_C(  71292172), UINT32_C(3868136293) },
      { -INT32_C(  2043471891), -INT32_C(  1780869234), -INT32_C(  2107402251),  INT32_C(   805422245) },
      {  INT32_C(  1236206402), -INT32_C(   179633687),  INT32_C(  1006209750), -INT32_C(  1960736354) },
      {  INT32_C(   112138184), -INT32_C(   178583569),  INT32_C(  1004773334),  INT32_C(   690063551) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint32x4_t a = simde_vld1q_u32(test_vec[i].a);
    simde_int32x4_t b = simde_vld1q_s32(test_vec[i].b);
    simde_int32x4_t c = simde_vld1q_s32(test_vec[i].c);
    simde_int32x4_t r = simde_vbslq_s32(a, b, c);
    simde_test_arm_neon_assert_equal_i32x4(r, simde_vld1q_s32(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vbslq_s64 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    uint64_t a[2];
    int64_t b[2];
    int64_t c[2];
    int64_t r[2];
  } test_vec[] = {
    { { UINT64_C( 7795818849416578166), UINT64_C(14966646166231909917) },
      { -INT64_C( 1068368472424484962),  INT64_C(   91235875088826701) },
      {  INT64_C( 8539869812187597094), -INT64_C( 8218959441254434116) },
      {  INT64_C( 8260715013321461014),  INT64_C(   91306241623177389) } },
    { { UINT64_C(10037573859184794066), UINT64_C(  445386730649992609) },
      {  INT64_C( 2823088921630323806),  INT64_C( 1357614561922374746) },
      { -INT64_C( 8225057344842806511), -INT64_C( 7107550753161811081) },
      {  INT64_C(  549080619647078995), -INT64_C( 7253403027809575338) } },
    { { UINT64_C( 8299431632794057116), UINT64_C(13668588338187957598) },
      {  INT64_C( 5645798521896181471), -INT64_C( 7516787075213618222) },
      { -INT64_C( 2087194652701817989),  INT64_C( 4083130274454553920) },
      { -INT64_C( 4464813712291849473), -INT64_C( 7662274460797005486) } },
    { { UINT64_C( 8031428440031016527), UINT64_C(10881312548301380208) },
      { -INT64_C( 6153267932422234317), -INT64_C( 7094786458336682760) },
      {  INT64_C( 6558431740862697207), -INT64_C( 1655133656428673708) },
      {  INT64_C( 4184182062128864947), -INT64_C(  213981810549875340) } },
    { { UINT64_C( 6880441842545013607), UINT64_C( 5495863055540556633) },
      { -INT64_C( 7489797051327116856),  INT64_C(  290781913680499819) },
      {  INT64_C( 4686086571514309443), -INT64_C( 4898175920371025562) },
      {  INT64_C( 1732874077065414976), -INT64_C( 5475509944796465041) } },
    { { UINT64_C( 4040712711685793591), UINT64_C( 7994841704351406930) },
      { -INT64_C( 9136079489626224371), -INT64_C( 8824449092932591655) },
      { -INT64_C( 3949916946509531094), -INT64_C(  664091926299375826) },
      { -INT64_C( 4522140434435614451), -INT64_C( 7743434016418128004) } },
    { { UINT64_C(15713377964977283188), UINT64_C(13336337789699444033) },
      {  INT64_C( 6154414252077618217),  INT64_C( 4559745962363265127) },
      { -INT64_C( 7623221616342781352),  INT64_C( 3852329258121026349) },
      {  INT64_C( 6063184672427610664),  INT64_C( 4424286953917616749) } },
    { { UINT64_C( 7910921318392145485), UINT64_C( 5289483196180560221) },
      {  INT64_C( 4909441564937500471), -INT64_C( 3678465080099256654) },
      {  INT64_C( 7066158834674354333),  INT64_C(  701986301675294339) },
      {  INT64_C( 5048841978297511573),  INT64_C( 5257376916863960722) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint64x2_t a = simde_vld1q_u64(test_vec[i].a);
    simde_int64x2_t b = simde_vld1q_s64(test_vec[i].b);
    simde_int64x2_t c = simde_vld1q_s64(test_vec[i].c);
    simde_int64x2_t r = simde_vbslq_s64(a, b, c);
    simde_test_arm_neon_assert_equal_i64x2(r, simde_vld1q_s64(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vbslq_u8 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    uint8_t a[16];
    uint8_t b[16];
    uint8_t c[16];
    uint8_t r[16];
  } test_vec[] = {
    { { UINT8_C(167), UINT8_C(219), UINT8_C(174), UINT8_C(  9), UINT8_C( 98), UINT8_C(152), UINT8_C(237), UINT8_C(192),
        UINT8_C(158), UINT8_C( 47), UINT8_C( 49), UINT8_C( 36), UINT8_C(247), UINT8_C(160), UINT8_C( 91), UINT8_C( 79) },
      { UINT8_C(128), UINT8_C(172), UINT8_C(173), UINT8_C(235), UINT8_C(222), UINT8_C(206), UINT8_C(217), UINT8_C(159),
        UINT8_C( 71), UINT8_C(212), UINT8_C(238), UINT8_C(215), UINT8_C(120), UINT8_C(220), UINT8_C(145), UINT8_C( 32) },
      { UINT8_C(184), UINT8_C( 63), UINT8_C( 41), UINT8_C( 26), UINT8_C(216), UINT8_C( 22), UINT8_C(218), UINT8_C(118),
        UINT8_C( 69), UINT8_C( 12), UINT8_C(154), UINT8_C( 60), UINT8_C(172), UINT8_C(245), UINT8_C(139), UINT8_C( 45) },
      { UINT8_C(152), UINT8_C(172), UINT8_C(173), UINT8_C( 27), UINT8_C(218), UINT8_C(142), UINT8_C(219), UINT8_C(182),
        UINT8_C( 71), UINT8_C(  4), UINT8_C(170), UINT8_C( 28), UINT8_C(120), UINT8_C(213), UINT8_C(145), UINT8_C( 32) } },
    { { UINT8_C(161), UINT8_C( 57), UINT8_C( 24), UINT8_C(128), UINT8_C(  7), UINT8_C(241), UINT8_C( 31), UINT8_C( 79),
        UINT8_C(198), UINT8_C( 13), UINT8_C( 38), UINT8_C( 62), UINT8_C(234), UINT8_C(183), UINT8_C( 94), UINT8_C(162) },
      { UINT8_C(246), UINT8_C(135), UINT8_C(188), UINT8_C(206), UINT8_C(158), UINT8_C(150), UINT8_C( 68), UINT8_C(227),
        UINT8_C(162), UINT8_C(222), UINT8_C( 32), UINT8_C( 79), UINT8_C(212), UINT8_C(171), UINT8_C(124), UINT8_C(117) },
      { UINT8_C(228), UINT8_C(148), UINT8_C(245), UINT8_C(236), UINT8_C(134), UINT8_C( 21), UINT8_C( 59), UINT8_C( 76),
        UINT8_C( 34), UINT8_C( 97), UINT8_C(138), UINT8_C( 12), UINT8_C( 24), UINT8_C(233), UINT8_C(174), UINT8_C( 14) },
      { UINT8_C(228), UINT8_C(133), UINT8_C(253), UINT8_C(236), UINT8_C(134), UINT8_C(148), UINT8_C( 36), UINT8_C( 67),
        UINT8_C(162), UINT8_C(108), UINT8_C(168), UINT8_C( 14), UINT8_C(208), UINT8_C(235), UINT8_C(252), UINT8_C( 44) } },
    { { UINT8_C(112), UINT8_C(106), UINT8_C(221), UINT8_C( 14), UINT8_C(  1), UINT8_C( 33), UINT8_C(242), UINT8_C(163),
        UINT8_C(  0), UINT8_C( 18), UINT8_C(242), UINT8_C(212), UINT8_C(189), UINT8_C(110), UINT8_C( 73), UINT8_C(162) },
      { UINT8_C(  3), UINT8_C( 63), UINT8_C(142), UINT8_C(137), UINT8_C( 84), UINT8_C(201), UINT8_C(213), UINT8_C(118),
        UINT8_C( 42), UINT8_C( 95), UINT8_C(131), UINT8_C( 66), UINT8_C( 72), UINT8_C( 49), UINT8_C( 80), UINT8_C(185) },
      { UINT8_C(156), UINT8_C( 45), UINT8_C(199), UINT8_C(157), UINT8_C( 79), UINT8_C(185), UINT8_C( 64), UINT8_C( 79),
        UINT8_C(203), UINT8_C( 51), UINT8_C( 35), UINT8_C(137), UINT8_C(161), UINT8_C(108), UINT8_C( 43), UINT8_C(164) },
      { UINT8_C(140), UINT8_C( 47), UINT8_C(142), UINT8_C(153), UINT8_C( 78), UINT8_C(153), UINT8_C(208), UINT8_C(110),
        UINT8_C(203), UINT8_C( 51), UINT8_C(131), UINT8_C( 73), UINT8_C(  8), UINT8_C( 32), UINT8_C( 98), UINT8_C(164) } },
    { { UINT8_C(171), UINT8_C(185), UINT8_C( 45),    UINT8_MAX, UINT8_C(130), UINT8_C(  2), UINT8_C(118), UINT8_C(172),
        UINT8_C( 98), UINT8_C(249), UINT8_C(238), UINT8_C(170), UINT8_C( 42), UINT8_C( 62), UINT8_C( 99), UINT8_C(198) },
      { UINT8_C(108), UINT8_C( 43), UINT8_C( 99), UINT8_C(187), UINT8_C(228), UINT8_C(164), UINT8_C( 10), UINT8_C(176),
        UINT8_C(215), UINT8_C( 45), UINT8_C( 57), UINT8_C(120), UINT8_C(153), UINT8_C(100), UINT8_C( 29), UINT8_C( 69) },
      { UINT8_C( 29), UINT8_C( 74), UINT8_C( 68), UINT8_C(159), UINT8_C( 77), UINT8_C(186), UINT8_C( 75), UINT8_C(175),
        UINT8_C(179), UINT8_C( 57), UINT8_C( 89), UINT8_C(222), UINT8_C(119), UINT8_C(189), UINT8_C(164), UINT8_C(227) },
      { UINT8_C( 60), UINT8_C(107), UINT8_C( 97), UINT8_C(187), UINT8_C(205), UINT8_C(184), UINT8_C( 11), UINT8_C(163),
        UINT8_C(211), UINT8_C( 41), UINT8_C( 57), UINT8_C(124), UINT8_C( 93), UINT8_C(165), UINT8_C(133), UINT8_C(101) } },
    { { UINT8_C(232), UINT8_C(  8), UINT8_C(158), UINT8_C(204), UINT8_C(172), UINT8_C(168), UINT8_C(124), UINT8_C(131),
        UINT8_C(213), UINT8_C(181), UINT8_C(251), UINT8_C(111), UINT8_C( 25), UINT8_C( 24), UINT8_C(180), UINT8_C( 54) },
      { UINT8_C( 99), UINT8_C(248), UINT8_C(213), UINT8_C(176), UINT8_C(179), UINT8_C( 32), UINT8_C( 95), UINT8_C(102),
        UINT8_C( 89), UINT8_C(184), UINT8_C( 68), UINT8_C(209), UINT8_C(117), UINT8_C(233), UINT8_C(180), UINT8_C( 93) },
      { UINT8_C(241), UINT8_C( 83), UINT8_C( 42), UINT8_C(157), UINT8_C(251), UINT8_C(166), UINT8_C( 32), UINT8_C(209),
        UINT8_C( 92), UINT8_C( 27), UINT8_C( 64), UINT8_C(117), UINT8_C( 52), UINT8_C(244), UINT8_C(172), UINT8_C(151) },
      { UINT8_C(113), UINT8_C( 91), UINT8_C(180), UINT8_C(145), UINT8_C(243), UINT8_C( 38), UINT8_C( 92), UINT8_C( 82),
        UINT8_C( 89), UINT8_C(186), UINT8_C( 64), UINT8_C( 81), UINT8_C( 53), UINT8_C(236), UINT8_C(188), UINT8_C(149) } },
    { { UINT8_C(236), UINT8_C(129), UINT8_C( 71), UINT8_C(159), UINT8_C(162), UINT8_C(166), UINT8_C(  6), UINT8_C(251),
        UINT8_C( 94), UINT8_C( 74), UINT8_C(204), UINT8_C(212), UINT8_C( 51), UINT8_C(129), UINT8_C( 49), UINT8_C( 36) },
      { UINT8_C(212), UINT8_C( 91), UINT8_C(193), UINT8_C(207), UINT8_C(  2), UINT8_C(225), UINT8_C(160), UINT8_C( 94),
        UINT8_C(253), UINT8_C(224), UINT8_C(211), UINT8_C( 49), UINT8_C(212), UINT8_C(127), UINT8_C(200), UINT8_C(193) },
      { UINT8_C(  1), UINT8_C( 15), UINT8_C( 96), UINT8_C(163), UINT8_C(181), UINT8_C(102), UINT8_C(158), UINT8_C( 19),
        UINT8_C(177), UINT8_C(107), UINT8_C(231), UINT8_C(228), UINT8_C(236), UINT8_C( 25), UINT8_C(  9), UINT8_C(192) },
      { UINT8_C(197), UINT8_C( 15), UINT8_C( 97), UINT8_C(175), UINT8_C( 23), UINT8_C(224), UINT8_C(152), UINT8_C( 90),
        UINT8_C(253), UINT8_C( 97), UINT8_C(227), UINT8_C( 48), UINT8_C(220), UINT8_C( 25), UINT8_C(  8), UINT8_C(192) } },
    { { UINT8_C(116), UINT8_C(202), UINT8_C(143), UINT8_C(118), UINT8_C(172), UINT8_C( 48), UINT8_C(212), UINT8_C(169),
        UINT8_C( 16), UINT8_C(168), UINT8_C(218), UINT8_C(229), UINT8_C( 39), UINT8_C(162), UINT8_C(166), UINT8_C( 40) },
      { UINT8_C(177), UINT8_C(  6), UINT8_C(203), UINT8_C(102), UINT8_C(109), UINT8_C(106), UINT8_C(121), UINT8_C( 30),
        UINT8_C(213), UINT8_C( 97), UINT8_C(  2), UINT8_C(193), UINT8_C(122), UINT8_C( 11), UINT8_C(129), UINT8_C(238) },
      { UINT8_C(214), UINT8_C( 16), UINT8_C(101), UINT8_C(130), UINT8_C( 64), UINT8_C( 57), UINT8_C( 43), UINT8_C( 81),
        UINT8_C(225), UINT8_C(  5), UINT8_C( 54), UINT8_C(  9), UINT8_C(167), UINT8_C(220), UINT8_C( 49), UINT8_C( 88) },
      { UINT8_C(178), UINT8_C( 18), UINT8_C(235), UINT8_C(230), UINT8_C(108), UINT8_C( 41), UINT8_C(123), UINT8_C( 88),
        UINT8_C(241), UINT8_C( 37), UINT8_C( 38), UINT8_C(201), UINT8_C(162), UINT8_C( 94), UINT8_C(145), UINT8_C(120) } },
    { { UINT8_C(226), UINT8_C(253), UINT8_C(190), UINT8_C( 79), UINT8_C(103), UINT8_C( 55), UINT8_C(109), UINT8_C( 60),
        UINT8_C(152), UINT8_C(112), UINT8_C(253), UINT8_C( 18), UINT8_C(123), UINT8_C(126), UINT8_C(  1), UINT8_C( 81) },
      { UINT8_C(142), UINT8_C(102), UINT8_C(211), UINT8_C(207), UINT8_C(159), UINT8_C(254), UINT8_C( 32), UINT8_C(129),
        UINT8_C(  3), UINT8_C( 86), UINT8_C(138), UINT8_C(170), UINT8_C( 50), UINT8_C(187), UINT8_C(  2), UINT8_C( 20) },
      { UINT8_C(184), UINT8_C(192), UINT8_C(100), UINT8_C( 31), UINT8_C(248), UINT8_C(209), UINT8_C( 91), UINT8_C(144),
        UINT8_C( 65), UINT8_C( 88), UINT8_C(163), UINT8_C(189), UINT8_C(214), UINT8_C(164), UINT8_C( 14), UINT8_C(101) },
      { UINT8_C(154), UINT8_C(100), UINT8_C(210), UINT8_C( 95), UINT8_C(159), UINT8_C(246), UINT8_C( 50), UINT8_C(128),
        UINT8_C( 65), UINT8_C( 88), UINT8_C(138), UINT8_C(175), UINT8_C(182), UINT8_C(186), UINT8_C( 14), UINT8_C( 52) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint8x16_t a = simde_vld1q_u8(test_vec[i].a);
    simde_uint8x16_t b = simde_vld1q_u8(test_vec[i].b);
    simde_uint8x16_t c = simde_vld1q_u8(test_vec[i].c);
    simde_uint8x16_t r = simde_vbslq_u8(a, b, c);

    simde_test_arm_neon_assert_equal_u8x16(r, simde_vld1q_u8(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vbslq_u16 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    uint16_t a[8];
    uint16_t b[8];
    uint16_t c[8];
    uint16_t r[8];
  } test_vec[] = {
    { { UINT16_C(46061), UINT16_C(22274), UINT16_C(54714), UINT16_C(34948), UINT16_C(27294), UINT16_C(41079), UINT16_C(30227), UINT16_C(13653) },
      { UINT16_C(23669), UINT16_C( 7091), UINT16_C(40486), UINT16_C( 9309), UINT16_C(42650), UINT16_C(59973), UINT16_C(25501), UINT16_C(35358) },
      { UINT16_C( 8214), UINT16_C(53473), UINT16_C(26358), UINT16_C(37976), UINT16_C(53200), UINT16_C(58420), UINT16_C(35398), UINT16_C(47897) },
      { UINT16_C( 4215), UINT16_C(37859), UINT16_C(46694), UINT16_C( 5212), UINT16_C(42970), UINT16_C(58437), UINT16_C(59989), UINT16_C(35356) } },
    { { UINT16_C(52454), UINT16_C( 3542), UINT16_C(13163), UINT16_C( 1329), UINT16_C(30425), UINT16_C(30447), UINT16_C( 3802), UINT16_C(61440) },
      { UINT16_C(57902), UINT16_C( 9409), UINT16_C( 6472), UINT16_C( 6328), UINT16_C(60905), UINT16_C(12284), UINT16_C( 5495), UINT16_C(24042) },
      { UINT16_C(49378), UINT16_C(19818), UINT16_C(40180), UINT16_C(52562), UINT16_C(16914), UINT16_C(60484), UINT16_C(17488), UINT16_C(32477) },
      { UINT16_C(49190), UINT16_C(17640), UINT16_C(40412), UINT16_C(51314), UINT16_C(25803), UINT16_C(44780), UINT16_C(17490), UINT16_C(24285) } },
    { { UINT16_C(40486), UINT16_C(28323), UINT16_C(23479), UINT16_C(41095), UINT16_C(33608), UINT16_C(49103), UINT16_C(47513), UINT16_C(31517) },
      { UINT16_C(34682), UINT16_C(28360), UINT16_C( 6691), UINT16_C(13883), UINT16_C(32604), UINT16_C(44066), UINT16_C(65476), UINT16_C(59947) },
      { UINT16_C(52893), UINT16_C(21849), UINT16_C(57385), UINT16_C(29429), UINT16_C(50531), UINT16_C(64561), UINT16_C(20094), UINT16_C(63607) },
      { UINT16_C(50875), UINT16_C(32728), UINT16_C(47659), UINT16_C(29299), UINT16_C(18283), UINT16_C(60466), UINT16_C(65510), UINT16_C(60011) } },
    { { UINT16_C(16342), UINT16_C(63846), UINT16_C(41562), UINT16_C(46639), UINT16_C(21025), UINT16_C(58723), UINT16_C(36433), UINT16_C(61392) },
      { UINT16_C(10588), UINT16_C(34116), UINT16_C(14601), UINT16_C(27895), UINT16_C(10750), UINT16_C(32105), UINT16_C(57463), UINT16_C(19829) },
      { UINT16_C(56352), UINT16_C(31303), UINT16_C(30334), UINT16_C(40752), UINT16_C(37832), UINT16_C( 6789), UINT16_C(21793), UINT16_C(32009) },
      { UINT16_C(59764), UINT16_C(33605), UINT16_C(29740), UINT16_C(11575), UINT16_C(33256), UINT16_C(32741), UINT16_C(53617), UINT16_C(23897) } },
    { { UINT16_C(19838), UINT16_C(34563), UINT16_C(64134), UINT16_C(34291), UINT16_C(23587), UINT16_C(39682), UINT16_C(30525), UINT16_C(24040) },
      { UINT16_C(12115), UINT16_C(53719), UINT16_C( 1958), UINT16_C(28273), UINT16_C(63131), UINT16_C(48264), UINT16_C(37195), UINT16_C(51514) },
      { UINT16_C(15838), UINT16_C(25936), UINT16_C(17207), UINT16_C(23530), UINT16_C(60576), UINT16_C(56822), UINT16_C(56931), UINT16_C(46906) },
      { UINT16_C(15826), UINT16_C(57683), UINT16_C(  951), UINT16_C(24185), UINT16_C(62595), UINT16_C(56564), UINT16_C(39243), UINT16_C(60218) } },
    { { UINT16_C( 4366), UINT16_C(46216), UINT16_C(63768), UINT16_C(45858), UINT16_C(44015), UINT16_C(14960), UINT16_C(43580), UINT16_C( 6915) },
      { UINT16_C(21479), UINT16_C( 7808), UINT16_C(27287), UINT16_C(14201), UINT16_C(28502), UINT16_C(47380), UINT16_C(20046), UINT16_C(23664) },
      { UINT16_C(63839), UINT16_C(30480), UINT16_C(13042), UINT16_C(57899), UINT16_C(39901), UINT16_C( 6684), UINT16_C( 8261), UINT16_C(11317) },
      { UINT16_C(63831), UINT16_C(22416), UINT16_C(27378), UINT16_C(29481), UINT16_C(15190), UINT16_C(14364), UINT16_C( 2637), UINT16_C(15412) } },
    { { UINT16_C(46451), UINT16_C( 2634), UINT16_C(50207), UINT16_C(30017), UINT16_C(21811), UINT16_C(33070), UINT16_C(40867), UINT16_C(  733) },
      { UINT16_C(60824), UINT16_C(35450), UINT16_C(42272), UINT16_C(64876), UINT16_C(35136), UINT16_C(34071), UINT16_C(19625), UINT16_C( 7345) },
      { UINT16_C(64257), UINT16_C( 8231), UINT16_C(26815), UINT16_C(62357), UINT16_C(50366), UINT16_C(24948), UINT16_C(21091), UINT16_C(64356) },
      { UINT16_C(61200), UINT16_C(10863), UINT16_C(44192), UINT16_C(63444), UINT16_C(33164), UINT16_C(57686), UINT16_C(19681), UINT16_C(63921) } },
    { { UINT16_C(56895), UINT16_C(24453), UINT16_C(62083), UINT16_C(50013), UINT16_C(29819), UINT16_C( 9288), UINT16_C(63937), UINT16_C(49728) },
      { UINT16_C(26612), UINT16_C(46307), UINT16_C(30928), UINT16_C(36519), UINT16_C( 6972), UINT16_C(40943), UINT16_C(21357), UINT16_C(44442) },
      { UINT16_C( 8241), UINT16_C(46092), UINT16_C(26898), UINT16_C(36215), UINT16_C(49118), UINT16_C(40881), UINT16_C(61880), UINT16_C(44385) },
      { UINT16_C(26164), UINT16_C(46217), UINT16_C(31120), UINT16_C(36391), UINT16_C(39868), UINT16_C(40953), UINT16_C(20857), UINT16_C(44321) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint16x8_t a = simde_vld1q_u16(test_vec[i].a);
    simde_uint16x8_t b = simde_vld1q_u16(test_vec[i].b);
    simde_uint16x8_t c = simde_vld1q_u16(test_vec[i].c);
    simde_uint16x8_t r = simde_vbslq_u16(a, b, c);
    simde_test_arm_neon_assert_equal_u16x8(r, simde_vld1q_u16(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vbslq_u32 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    uint32_t a[4];
    uint32_t b[4];
    uint32_t c[4];
    uint32_t r[4];
  } test_vec[] = {
    { { UINT32_C(2860368209), UINT32_C( 846600018), UINT32_C(1097333921), UINT32_C(3276145535) },
      { UINT32_C( 238363688), UINT32_C(4256380213), UINT32_C(2983547187), UINT32_C(1925569056) },
      { UINT32_C(3994829467), UINT32_C(4213215834), UINT32_C( 222070926), UINT32_C(3033629323) },
      { UINT32_C(1312096906), UINT32_C(4180841752), UINT32_C( 224219183), UINT32_C(1993704096) } },
    { { UINT32_C(3703703206), UINT32_C(1859745339), UINT32_C(3894390471), UINT32_C( 609936776) },
      { UINT32_C(2165470759), UINT32_C(2541498888), UINT32_C(1185200314), UINT32_C(3791287611) },
      { UINT32_C(3082665084), UINT32_C(4196832818), UINT32_C(3454158149), UINT32_C(1391541290) },
      { UINT32_C(2738863742), UINT32_C(2524885512), UINT32_C(1172629890), UINT32_C(1929084202) } },
    { { UINT32_C(3134391218), UINT32_C(4031860790), UINT32_C(1127675400), UINT32_C(3877974123) },
      { UINT32_C( 530572013), UINT32_C(3189359993), UINT32_C( 898366218), UINT32_C(3917970743) },
      { UINT32_C(3064224384), UINT32_C(3014129066), UINT32_C(1475796459), UINT32_C(4215151374) },
      { UINT32_C( 515332768), UINT32_C(3015173560), UINT32_C( 365100011), UINT32_C(4179573543) } },
    { { UINT32_C(1998249470), UINT32_C(2905945250), UINT32_C(1742913583), UINT32_C(3192940861) },
      { UINT32_C(1853158595), UINT32_C(3575716842), UINT32_C( 120330233), UINT32_C( 822242099) },
      { UINT32_C(3953663048), UINT32_C(2157501776), UINT32_C(3689380509), UINT32_C(2795059171) },
      { UINT32_C(4004566210), UINT32_C(2242501106), UINT32_C(2670017209), UINT32_C( 814317555) } },
    { { UINT32_C( 370412844), UINT32_C( 585839913), UINT32_C(2150176845), UINT32_C(3417385859) },
      { UINT32_C(2562087239), UINT32_C(3541585462), UINT32_C(2880372680), UINT32_C(1649559350) },
      { UINT32_C(2121819733), UINT32_C(3919602844), UINT32_C(4285122940), UINT32_C(1003100916) },
      { UINT32_C(2021419861), UINT32_C(3406316724), UINT32_C(4285061496), UINT32_C(1918505846) } },
    { { UINT32_C(2849210739), UINT32_C(2558323663), UINT32_C( 558050282), UINT32_C(3347289458) },
      { UINT32_C(2554723580), UINT32_C(3699500384), UINT32_C(2732321454), UINT32_C(2011079940) },
      { UINT32_C(4129337638), UINT32_C(2274270365), UINT32_C( 984142279), UINT32_C(1661021287) },
      { UINT32_C(3730944116), UINT32_C(2676159824), UINT32_C( 988543663), UINT32_C(1736617221) } },
    { { UINT32_C(2298169128), UINT32_C(3680795692), UINT32_C(1786593126), UINT32_C( 199318500) },
      { UINT32_C(2852192525), UINT32_C(1697746845), UINT32_C(3349142112), UINT32_C( 774545414) },
      { UINT32_C( 347481575), UINT32_C( 133110433), UINT32_C(1030843481), UINT32_C(3578286792) },
      { UINT32_C(2617582031), UINT32_C(1168838285), UINT32_C(1461541497), UINT32_C(3727163404) } },
    { { UINT32_C(4051650899), UINT32_C( 961982680), UINT32_C(2415981962), UINT32_C(2109614997) },
      { UINT32_C(4069618768), UINT32_C(3891888270), UINT32_C(3022351340), UINT32_C( 294219197) },
      { UINT32_C(2399275191), UINT32_C(1137203385), UINT32_C(3805595981), UINT32_C(1147114228) },
      { UINT32_C(4262543604), UINT32_C(1675151529), UINT32_C(4074006989), UINT32_C( 298433013) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint32x4_t a = simde_vld1q_u32(test_vec[i].a);
    simde_uint32x4_t b = simde_vld1q_u32(test_vec[i].b);
    simde_uint32x4_t c = simde_vld1q_u32(test_vec[i].c);
    simde_uint32x4_t r = simde_vbslq_u32(a, b, c);

    simde_test_arm_neon_assert_equal_u32x4(r, simde_vld1q_u32(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vbslq_u64 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    uint64_t a[2];
    uint64_t b[2];
    uint64_t c[2];
    uint64_t r[2];
  } test_vec[] = {
    { { UINT64_C( 3591810382812026283), UINT64_C(16405937380248416137) },
      { UINT64_C(11295520154613915977), UINT64_C( 2687092596342288586) },
      { UINT64_C(10466732805528575117), UINT64_C( 2792016118067119293) },
      { UINT64_C(10430880479856511245), UINT64_C( 2673514040022294716) } },
    { { UINT64_C( 5815810152152417884), UINT64_C( 5402170822885590360) },
      { UINT64_C( 8670164562858372537), UINT64_C( 8710828213637800160) },
      { UINT64_C( 5453936056050125530), UINT64_C(15677897956199875467) },
      { UINT64_C( 6561900733515582618), UINT64_C(15700414826102440643) } },
    { { UINT64_C( 7617817368925498755), UINT64_C(18041148664896162764) },
      { UINT64_C(13857868751251894291), UINT64_C(  560307298380639949) },
      { UINT64_C( 1764562557693419657), UINT64_C(13844451922523693832) },
      { UINT64_C( 5789685480717017099), UINT64_C(  172929698024237772) } },
    { { UINT64_C( 5928170346728815439), UINT64_C( 8291133416724713093) },
      { UINT64_C( 6541763587432928869), UINT64_C( 8580099633672538534) },
      { UINT64_C( 8500334219694430239), UINT64_C(11667858224492459662) },
      { UINT64_C( 8643326235096633941), UINT64_C(17581080137045276814) } },
    { { UINT64_C( 1986681675388777189), UINT64_C(15457621344735073509) },
      { UINT64_C( 5745874869769961561), UINT64_C(12720051885852540072) },
      { UINT64_C(15832257110833879334), UINT64_C(18310349266614756749) },
      { UINT64_C(14678763632229583171), UINT64_C(13303612972326073768) } },
    { { UINT64_C(12825130274157729517), UINT64_C(11365708282709001280) },
      { UINT64_C(12305505563839144948), UINT64_C(  556487138878663957) },
      { UINT64_C( 4997501370106183841), UINT64_C(   38856792151748725) },
      { UINT64_C(16485058153964208868), UINT64_C(  412376349718983733) } },
    { { UINT64_C(14444644566615901103), UINT64_C( 1188453801116525660) },
      { UINT64_C( 6522642610181976892), UINT64_C(10452805128511018500) },
      { UINT64_C(  365304665020889493), UINT64_C(  915913873276310582) },
      { UINT64_C( 5549935201716288316), UINT64_C( 2058095493828826150) } },
    { { UINT64_C( 9758687427988123438), UINT64_C( 2025395558509098408) },
      { UINT64_C( 9245176770987391135), UINT64_C(17431423991996139787) },
      { UINT64_C(12705905830843921738), UINT64_C( 3515717642809502503) },
      { UINT64_C(12708439114211752014), UINT64_C( 3515291040853510927) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint64x2_t a = simde_vld1q_u64(test_vec[i].a);
    simde_uint64x2_t b = simde_vld1q_u64(test_vec[i].b);
    simde_uint64x2_t c = simde_vld1q_u64(test_vec[i].c);
    simde_uint64x2_t r = simde_vbslq_u64(a, b, c);
    simde_test_arm_neon_assert_equal_u64x2(r, simde_vld1q_u64(test_vec[i].r));
  }

  return 0;
}

SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(vbsl_f16)
SIMDE_TEST_FUNC_LIST_ENTRY(vbsl_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vbsl_f64)
SIMDE_TEST_FUNC_LIST_ENTRY(vbsl_s8)
SIMDE_TEST_FUNC_LIST_ENTRY(vbsl_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vbsl_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vbsl_s64)
SIMDE_TEST_FUNC_LIST_ENTRY(vbsl_u8)
SIMDE_TEST_FUNC_LIST_ENTRY(vbsl_u16)
SIMDE_TEST_FUNC_LIST_ENTRY(vbsl_u32)
SIMDE_TEST_FUNC_LIST_ENTRY(vbsl_u64)

SIMDE_TEST_FUNC_LIST_ENTRY(vbslq_f16)
SIMDE_TEST_FUNC_LIST_ENTRY(vbslq_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vbslq_f64)
SIMDE_TEST_FUNC_LIST_ENTRY(vbslq_s8)
SIMDE_TEST_FUNC_LIST_ENTRY(vbslq_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vbslq_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vbslq_s64)
SIMDE_TEST_FUNC_LIST_ENTRY(vbslq_u8)
SIMDE_TEST_FUNC_LIST_ENTRY(vbslq_u16)
SIMDE_TEST_FUNC_LIST_ENTRY(vbslq_u32)
SIMDE_TEST_FUNC_LIST_ENTRY(vbslq_u64)
SIMDE_TEST_FUNC_LIST_END

#include "test-neon-footer.h"
