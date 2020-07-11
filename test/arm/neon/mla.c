#define SIMDE_TEST_ARM_NEON_INSN mla

#include "test-neon.h"
#include "../../../simde/arm/neon/mla.h"

static int
test_simde_vmla_f32 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    simde_float32 a[2];
    simde_float32 b[2];
    simde_float32 c[2];
    simde_float32 r[2];
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(316.661133), SIMDE_FLOAT32_C(532.098022) },
      { SIMDE_FLOAT32_C(620.658325), SIMDE_FLOAT32_C(-997.429260) },
      { SIMDE_FLOAT32_C(-285.241272), SIMDE_FLOAT32_C(-34.532288) },
      { SIMDE_FLOAT32_C(-176720.718750), SIMDE_FLOAT32_C(34975.613281) } },
    { { SIMDE_FLOAT32_C(471.026245), SIMDE_FLOAT32_C(750.918213) },
      { SIMDE_FLOAT32_C(-25.710571), SIMDE_FLOAT32_C(227.714966) },
      { SIMDE_FLOAT32_C(-713.672607), SIMDE_FLOAT32_C(-277.196289) },
      { SIMDE_FLOAT32_C(18819.955078), SIMDE_FLOAT32_C(-62370.824219) } },
    { { SIMDE_FLOAT32_C(194.214355), SIMDE_FLOAT32_C(-492.961609) },
      { SIMDE_FLOAT32_C(-13.566528), SIMDE_FLOAT32_C(253.638428) },
      { SIMDE_FLOAT32_C(459.621704), SIMDE_FLOAT32_C(-547.513184) },
      { SIMDE_FLOAT32_C(-6041.256348), SIMDE_FLOAT32_C(-139363.359375) } },
    { { SIMDE_FLOAT32_C(572.033813), SIMDE_FLOAT32_C(-487.424255) },
      { SIMDE_FLOAT32_C(876.644287), SIMDE_FLOAT32_C(-464.728149) },
      { SIMDE_FLOAT32_C(-627.000244), SIMDE_FLOAT32_C(-604.188477) },
      { SIMDE_FLOAT32_C(-549084.125000), SIMDE_FLOAT32_C(280295.968750) } },
    { { SIMDE_FLOAT32_C(-380.228882), SIMDE_FLOAT32_C(-880.954773) },
      { SIMDE_FLOAT32_C(-273.911987), SIMDE_FLOAT32_C(-60.760437) },
      { SIMDE_FLOAT32_C(460.995361), SIMDE_FLOAT32_C(-993.405762) },
      { SIMDE_FLOAT32_C(-126652.382812), SIMDE_FLOAT32_C(59478.816406) } },
    { { SIMDE_FLOAT32_C(-200.876343), SIMDE_FLOAT32_C(-222.343384) },
      { SIMDE_FLOAT32_C(538.692261), SIMDE_FLOAT32_C(-580.218018) },
      { SIMDE_FLOAT32_C(-219.772644), SIMDE_FLOAT32_C(-746.548950) },
      { SIMDE_FLOAT32_C(-118590.695312), SIMDE_FLOAT32_C(432938.812500) } },
    { { SIMDE_FLOAT32_C(385.249634), SIMDE_FLOAT32_C(-748.746277) },
      { SIMDE_FLOAT32_C(-995.630615), SIMDE_FLOAT32_C(-640.460815) },
      { SIMDE_FLOAT32_C(478.968628), SIMDE_FLOAT32_C(-709.303223) },
      { SIMDE_FLOAT32_C(-476490.593750), SIMDE_FLOAT32_C(453532.156250) } },
    { { SIMDE_FLOAT32_C(82.342896), SIMDE_FLOAT32_C(-326.816833) },
      { SIMDE_FLOAT32_C(-202.264832), SIMDE_FLOAT32_C(-931.223450) },
      { SIMDE_FLOAT32_C(926.821655), SIMDE_FLOAT32_C(-742.643005) },
      { SIMDE_FLOAT32_C(-187381.078125), SIMDE_FLOAT32_C(691239.750000) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x2_t a, b, c, r;

    a = simde_vld1_f32(test_vec[i].a);
    b = simde_vld1_f32(test_vec[i].b);
    c = simde_vld1_f32(test_vec[i].c);
    r = simde_vmla_f32(a, b, c);

    simde_test_arm_neon_assert_equal_f32x2(r, simde_vld1_f32(test_vec[i].r), 1);
  }

  return 0;
}

static int
test_simde_vmla_f64 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    simde_float64 a[1];
    simde_float64 b[1];
    simde_float64 c[1];
    simde_float64 r[1];
  } test_vec[] = {
    { { SIMDE_FLOAT64_C(  -737.86) },
      { SIMDE_FLOAT64_C(    54.24) },
      { SIMDE_FLOAT64_C(   214.25) },
      { SIMDE_FLOAT64_C( 10883.06) } },
    { { SIMDE_FLOAT64_C(  -556.90) },
      { SIMDE_FLOAT64_C(   -78.19) },
      { SIMDE_FLOAT64_C(  -607.99) },
      { SIMDE_FLOAT64_C( 46981.84) } },
    { { SIMDE_FLOAT64_C(   487.07) },
      { SIMDE_FLOAT64_C(   470.32) },
      { SIMDE_FLOAT64_C(   -82.83) },
      { SIMDE_FLOAT64_C(-38469.54) } },
    { { SIMDE_FLOAT64_C(   174.25) },
      { SIMDE_FLOAT64_C(  -952.32) },
      { SIMDE_FLOAT64_C(   119.45) },
      { SIMDE_FLOAT64_C(-113580.37) } },
    { { SIMDE_FLOAT64_C(  -537.41) },
      { SIMDE_FLOAT64_C(   278.36) },
      { SIMDE_FLOAT64_C(   723.14) },
      { SIMDE_FLOAT64_C(200755.84) } },
    { { SIMDE_FLOAT64_C(   217.52) },
      { SIMDE_FLOAT64_C(   318.77) },
      { SIMDE_FLOAT64_C(  -673.30) },
      { SIMDE_FLOAT64_C(-214410.32) } },
    { { SIMDE_FLOAT64_C(  -927.68) },
      { SIMDE_FLOAT64_C(  -114.09) },
      { SIMDE_FLOAT64_C(   770.14) },
      { SIMDE_FLOAT64_C(-88792.95) } },
    { { SIMDE_FLOAT64_C(  -953.39) },
      { SIMDE_FLOAT64_C(  -237.19) },
      { SIMDE_FLOAT64_C(   341.63) },
      { SIMDE_FLOAT64_C(-81984.61) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float64x1_t a = simde_vld1_f64(test_vec[i].a);
    simde_float64x1_t b = simde_vld1_f64(test_vec[i].b);
    simde_float64x1_t c = simde_vld1_f64(test_vec[i].c);
    simde_float64x1_t r = simde_vmla_f64(a, b, c);

    simde_test_arm_neon_assert_equal_f64x1(r, simde_vld1_f64(test_vec[i].r), 1);
  }

  return 0;
}

static int
test_simde_vmla_s8 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    int8_t a[8];
    int8_t b[8];
    int8_t c[8];
    int8_t r[8];
  } test_vec[] = {
    { { -INT8_C(  97), -INT8_C(  50), -INT8_C(  94), -INT8_C(  28),  INT8_C( 126), -INT8_C(  17), -INT8_C(  96),  INT8_C(  91) },
      { -INT8_C( 103), -INT8_C(  58),  INT8_C( 111), -INT8_C(  40),  INT8_C(  71),  INT8_C(  77),  INT8_C(  29), -INT8_C(  87) },
      { -INT8_C( 124),  INT8_C( 119), -INT8_C( 122),  INT8_C(  94), -INT8_C(  88),  INT8_C(   3), -INT8_C(  29), -INT8_C(  35) },
      { -INT8_C( 125), -INT8_C(  40), -INT8_C(  68),  INT8_C(  52),  INT8_C(  22), -INT8_C(  42),  INT8_C(  87),  INT8_C(  64) } },
    { {  INT8_C(  18),  INT8_C(  99),  INT8_C(  76),  INT8_C(  75),  INT8_C(  95), -INT8_C( 107),  INT8_C( 108), -INT8_C(   2) },
      {  INT8_C( 100),  INT8_C(  14), -INT8_C(  30), -INT8_C(  30), -INT8_C(   3), -INT8_C( 125),  INT8_C(  61), -INT8_C( 105) },
      {  INT8_C(  73), -INT8_C(  84),  INT8_C( 111), -INT8_C( 112), -INT8_C(   6), -INT8_C( 116),  INT8_C(  58),  INT8_C( 126) },
      { -INT8_C( 106), -INT8_C(  53),  INT8_C(  74),  INT8_C( 107),  INT8_C( 113),  INT8_C(  57),  INT8_C(  62),  INT8_C(  80) } },
    { {  INT8_C(   4), -INT8_C(  64), -INT8_C(  36), -INT8_C(  84), -INT8_C(  61), -INT8_C(  65), -INT8_C( 119), -INT8_C(  42) },
      {  INT8_C(  35), -INT8_C(  43),  INT8_C(  33), -INT8_C( 126),  INT8_C( 107), -INT8_C( 114),      INT8_MIN, -INT8_C(  49) },
      { -INT8_C( 100),  INT8_C(  99), -INT8_C(  79), -INT8_C( 102), -INT8_C(  26), -INT8_C(  17),  INT8_C(  49),  INT8_C(  47) },
      {  INT8_C(  88),  INT8_C(  31), -INT8_C(  83), -INT8_C(  32), -INT8_C(  27),  INT8_C(  81),  INT8_C(   9), -INT8_C(  41) } },
    { { -INT8_C( 101), -INT8_C(  96), -INT8_C(  65), -INT8_C( 107),  INT8_C(  45), -INT8_C(   7),  INT8_C(  19),  INT8_C(  49) },
      { -INT8_C(  70), -INT8_C(  16), -INT8_C(  35),  INT8_C( 125), -INT8_C(  81),  INT8_C( 102),  INT8_C(  83), -INT8_C(  46) },
      {  INT8_C(  59),  INT8_C( 117),  INT8_C(  84), -INT8_C(  90),  INT8_C(   3), -INT8_C(  43),  INT8_C( 117), -INT8_C(  97) },
      {  INT8_C( 121),  INT8_C(  80),  INT8_C(  67), -INT8_C(  93),  INT8_C(  58), -INT8_C(  41),  INT8_C(   2), -INT8_C(  97) } },
    { {  INT8_C(  56),  INT8_C(  39),  INT8_C(  57),  INT8_C(  30),  INT8_C(  22),  INT8_C( 106),  INT8_C(  77), -INT8_C(  79) },
      {  INT8_C(  11),  INT8_C(  12),  INT8_C(  71),  INT8_C(  56),  INT8_C(   6),  INT8_C(  90),  INT8_C( 105), -INT8_C(  64) },
      {  INT8_C(  74),  INT8_C(  70),  INT8_C(  61), -INT8_C(   6), -INT8_C(  84), -INT8_C( 111), -INT8_C(  52), -INT8_C(  25) },
      {  INT8_C( 102),  INT8_C( 111),  INT8_C(  36), -INT8_C(  50),  INT8_C(  30),  INT8_C( 100), -INT8_C(   7), -INT8_C(  15) } },
    { {  INT8_C(   6),  INT8_C(  33), -INT8_C( 114),  INT8_C(   9), -INT8_C(  10),  INT8_C(   3), -INT8_C(  88),  INT8_C(  46) },
      {  INT8_C(  42), -INT8_C(  30),  INT8_C(  76),  INT8_C(  64),  INT8_C(  76), -INT8_C( 103), -INT8_C(  14),  INT8_C(  87) },
      { -INT8_C(  91),  INT8_C(  57), -INT8_C( 113), -INT8_C(  85), -INT8_C( 109), -INT8_C(   8),  INT8_C( 107), -INT8_C(  34) },
      {  INT8_C(  24),  INT8_C( 115),  INT8_C(   2), -INT8_C(  55), -INT8_C( 102),  INT8_C(  59), -INT8_C(  50), -INT8_C(  96) } },
    { {  INT8_C(  62), -INT8_C(  87), -INT8_C(  40), -INT8_C(  22),  INT8_C(  58), -INT8_C(  92), -INT8_C(  46),  INT8_C(  64) },
      { -INT8_C(  59),  INT8_C(  96),  INT8_C(  73), -INT8_C(  69),  INT8_C(  99), -INT8_C(  15), -INT8_C(  23), -INT8_C( 114) },
      { -INT8_C(  45),  INT8_C(  53), -INT8_C(  50),  INT8_C(  32), -INT8_C(  50), -INT8_C(  64),  INT8_C( 119),  INT8_C( 116) },
      { -INT8_C(  99), -INT8_C( 119), -INT8_C( 106),  INT8_C(  74), -INT8_C(  28),  INT8_C( 100),  INT8_C(  33), -INT8_C( 104) } },
    { { -INT8_C(   7),  INT8_C(   7),  INT8_C(  31), -INT8_C( 115), -INT8_C(   1), -INT8_C( 117),  INT8_C( 107),  INT8_C(  62) },
      {  INT8_C(  52),  INT8_C(  67),  INT8_C(  40),  INT8_C( 110), -INT8_C(  25), -INT8_C(   6), -INT8_C(  82), -INT8_C(  83) },
      {  INT8_C(  90), -INT8_C(   9),  INT8_C( 104), -INT8_C(  66), -INT8_C(  24),  INT8_C(  82),  INT8_C(  76), -INT8_C(  68) },
      {  INT8_C(  65), -INT8_C(  84),  INT8_C(  95),  INT8_C(  49),  INT8_C(  87), -INT8_C(  97),  INT8_C(  19),  INT8_C(  74) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int8x8_t a = simde_vld1_s8(test_vec[i].a);
    simde_int8x8_t b = simde_vld1_s8(test_vec[i].b);
    simde_int8x8_t c = simde_vld1_s8(test_vec[i].c);
    simde_int8x8_t r = simde_vmla_s8(a, b, c);

    simde_test_arm_neon_assert_equal_i8x8(r, simde_vld1_s8(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vmla_s16 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    int16_t a[4];
    int16_t b[4];
    int16_t c[4];
    int16_t r[4];
  } test_vec[] = {
    { {  INT16_C( 23455), -INT16_C( 11689), -INT16_C( 22552),  INT16_C( 11017) },
      { -INT16_C(  5730),  INT16_C( 14488), -INT16_C(  6817), -INT16_C( 24086) },
      { -INT16_C( 21930),  INT16_C( 24130),  INT16_C(  6050), -INT16_C( 26539) },
      { -INT16_C( 15693),  INT16_C( 14727),  INT16_C( 22278), -INT16_C(  8773) } },
    { { -INT16_C(  1714),  INT16_C(  5586), -INT16_C(  5200),  INT16_C( 20237) },
      {  INT16_C( 25670),  INT16_C( 12065),  INT16_C( 11020), -INT16_C( 21926) },
      { -INT16_C(  3564),  INT16_C( 29922), -INT16_C( 12841),  INT16_C( 11541) },
      { -INT16_C(  1338), -INT16_C( 23308), -INT16_C( 20796),  INT16_C(  6767) } },
    { {  INT16_C( 22647),  INT16_C(  6539), -INT16_C(  8081), -INT16_C( 16719) },
      { -INT16_C( 31526), -INT16_C( 29997), -INT16_C(  8081), -INT16_C( 18982) },
      { -INT16_C(  1212),  INT16_C( 20708),  INT16_C( 15910),  INT16_C( 15355) },
      {  INT16_C( 24671), -INT16_C( 21129),  INT16_C(  4841),  INT16_C( 18799) } },
    { { -INT16_C(  8911),  INT16_C(  2223), -INT16_C( 15190),  INT16_C(  8502) },
      { -INT16_C( 16100), -INT16_C( 29638), -INT16_C(  4958),  INT16_C( 31818) },
      {  INT16_C(  7536), -INT16_C(  8442), -INT16_C(  7939),  INT16_C( 16788) },
      { -INT16_C( 31375), -INT16_C( 10229),  INT16_C( 24772), -INT16_C( 14850) } },
    { {  INT16_C( 31196),  INT16_C(   658), -INT16_C( 29257), -INT16_C(  6083) },
      { -INT16_C(  5014),  INT16_C(  5617),  INT16_C( 10161), -INT16_C( 13002) },
      {  INT16_C( 29160), -INT16_C( 30119), -INT16_C( 23715), -INT16_C( 13050) },
      { -INT16_C( 31764), -INT16_C( 29349), -INT16_C( 21500), -INT16_C(  2687) } },
    { {  INT16_C(  3520), -INT16_C( 16980),  INT16_C( 16621), -INT16_C( 13825) },
      { -INT16_C( 28231),  INT16_C( 29132),  INT16_C(  2334), -INT16_C( 30631) },
      {  INT16_C( 19190), -INT16_C( 22627), -INT16_C( 11151),  INT16_C( 23156) },
      { -INT16_C( 28794), -INT16_C( 25656),  INT16_C(  7979), -INT16_C(  9133) } },
    { { -INT16_C( 12731), -INT16_C( 23836), -INT16_C(  5263),  INT16_C( 12911) },
      {  INT16_C(  7160), -INT16_C(  6673), -INT16_C(  4517),  INT16_C(  5551) },
      {  INT16_C( 31615), -INT16_C( 25210), -INT16_C(  8316),  INT16_C( 31270) },
      { -INT16_C( 10675), -INT16_C( 28418),  INT16_C(  5981), -INT16_C( 12183) } },
    { { -INT16_C( 15574), -INT16_C( 25823), -INT16_C( 26985), -INT16_C(  8971) },
      { -INT16_C(  9628), -INT16_C( 10882), -INT16_C(  4667), -INT16_C( 17145) },
      { -INT16_C(  2296),  INT16_C( 25762),  INT16_C( 20965),  INT16_C( 25977) },
      {  INT16_C(  4682), -INT16_C(  4899), -INT16_C( 25392), -INT16_C(  1980) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x4_t a = simde_vld1_s16(test_vec[i].a);
    simde_int16x4_t b = simde_vld1_s16(test_vec[i].b);
    simde_int16x4_t c = simde_vld1_s16(test_vec[i].c);
    simde_int16x4_t r = simde_vmla_s16(a, b, c);

    simde_test_arm_neon_assert_equal_i16x4(r, simde_vld1_s16(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vmla_s32 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    int32_t a[2];
    int32_t b[2];
    int32_t c[2];
    int32_t r[2];
  } test_vec[] = {
    { { -INT32_C(  1360280946), -INT32_C(  1150468689) },
      {  INT32_C(    44236099), -INT32_C(  1372656593) },
      {  INT32_C(    30169474), -INT32_C(   449840714) },
      { -INT32_C(  1004492396), -INT32_C(  1675370983) } },
    { { -INT32_C(    37762479), -INT32_C(   902980548) },
      {  INT32_C(   242751582), -INT32_C(  1714821803) },
      {  INT32_C(   312175587), -INT32_C(   624899752) },
      {  INT32_C(  1633071019), -INT32_C(  1906037132) } },
    { { -INT32_C(   656700382), -INT32_C(   675411066) },
      {  INT32_C(   315915733),  INT32_C(  2027684377) },
      {  INT32_C(  1887851802),  INT32_C(   487149370) },
      {  INT32_C(  1572211908),  INT32_C(   102579248) } },
    { {  INT32_C(   305112250), -INT32_C(  1863520146) },
      {  INT32_C(    40487036), -INT32_C(  1462097965) },
      { -INT32_C(  1111839068), -INT32_C(   885680208) },
      { -INT32_C(  1169138646), -INT32_C(   468400514) } },
    { {  INT32_C(   641448940), -INT32_C(   985381878) },
      {  INT32_C(  1456960488), -INT32_C(   521681821) },
      {  INT32_C(  1608667276),  INT32_C(   453491831) },
      {  INT32_C(  1662492364),  INT32_C(  1424900623) } },
    { {  INT32_C(   467190379),  INT32_C(  1172704857) },
      { -INT32_C(   731176503),  INT32_C(  1318694757) },
      { -INT32_C(  2036043741), -INT32_C(  1067021516) },
      { -INT32_C(   536194842),  INT32_C(  1368884701) } },
    { {  INT32_C(  1377782235),  INT32_C(  1886201605) },
      {  INT32_C(  1116489449),  INT32_C(   495415892) },
      { -INT32_C(   101584236), -INT32_C(   985167198) },
      { -INT32_C(   929461617),  INT32_C(  2098251821) } },
    { {  INT32_C(   793505019),  INT32_C(  1408283255) },
      {  INT32_C(    10817531),  INT32_C(   527504182) },
      { -INT32_C(  1386087079),  INT32_C(    63629423) },
      {  INT32_C(   915704382),  INT32_C(   972879585) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x2_t a = simde_vld1_s32(test_vec[i].a);
    simde_int32x2_t b = simde_vld1_s32(test_vec[i].b);
    simde_int32x2_t c = simde_vld1_s32(test_vec[i].c);
    simde_int32x2_t r = simde_vmla_s32(a, b, c);

    simde_test_arm_neon_assert_equal_i32x2(r, simde_vld1_s32(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vmla_u8 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    uint8_t a[16];
    uint8_t b[16];
    uint8_t c[16];
    uint8_t r[16];
  } test_vec[] = {
    { { UINT8_C( 99), UINT8_C( 82), UINT8_C(243), UINT8_C(181), UINT8_C(230), UINT8_C(106), UINT8_C(221), UINT8_C(140) },
      { UINT8_C(211), UINT8_C(191), UINT8_C(194), UINT8_C(123), UINT8_C( 58), UINT8_C(224), UINT8_C(253), UINT8_C(107) },
      { UINT8_C(179), UINT8_C(200), UINT8_C(167), UINT8_C(104), UINT8_C( 33), UINT8_C(216), UINT8_C(117), UINT8_C(211) },
      { UINT8_C(236), UINT8_C(138), UINT8_C(129), UINT8_C(173), UINT8_C( 96), UINT8_C(106), UINT8_C(126), UINT8_C(189) } },
    { { UINT8_C( 77), UINT8_C(143), UINT8_C(122), UINT8_C( 34), UINT8_C( 94), UINT8_C( 20), UINT8_C(148), UINT8_C(194) },
      { UINT8_C(102), UINT8_C(135), UINT8_C(119), UINT8_C( 76), UINT8_C(241), UINT8_C( 84), UINT8_C(216), UINT8_C(197) },
      { UINT8_C( 19), UINT8_C(154), UINT8_C( 64), UINT8_C( 77), UINT8_C(122), UINT8_C( 61), UINT8_C(184), UINT8_C( 45) },
      { UINT8_C(223), UINT8_C(197), UINT8_C( 58), UINT8_C(254), UINT8_C( 56), UINT8_C( 24), UINT8_C(212), UINT8_C( 99) } },
    { { UINT8_C(  5), UINT8_C( 96), UINT8_C(149), UINT8_C( 38), UINT8_C( 56), UINT8_C( 10), UINT8_C(249), UINT8_C(133) },
      { UINT8_C(154), UINT8_C(115), UINT8_C(167), UINT8_C(248), UINT8_C(135), UINT8_C( 59), UINT8_C(186), UINT8_C(237) },
      { UINT8_C(194), UINT8_C( 49), UINT8_C( 57), UINT8_C(180), UINT8_C(133), UINT8_C( 17), UINT8_C(121), UINT8_C(153) },
      { UINT8_C(185), UINT8_C( 99), UINT8_C(196), UINT8_C(134), UINT8_C( 91), UINT8_C(245), UINT8_C(227), UINT8_C( 42) } },
    { { UINT8_C(171), UINT8_C(185), UINT8_C(230), UINT8_C( 38), UINT8_C(246), UINT8_C(159), UINT8_C( 83), UINT8_C(251) },
      {    UINT8_MAX, UINT8_C(233), UINT8_C( 33), UINT8_C( 55), UINT8_C(243), UINT8_C( 27), UINT8_C(188), UINT8_C(141) },
      { UINT8_C(142), UINT8_C( 99), UINT8_C(134), UINT8_C( 22), UINT8_C(159), UINT8_C( 64), UINT8_C(  3), UINT8_C( 97) },
      { UINT8_C( 29), UINT8_C(212), UINT8_C( 44), UINT8_C(224), UINT8_C(227), UINT8_C( 95), UINT8_C(135), UINT8_C(104) } },
    { { UINT8_C(114), UINT8_C( 61), UINT8_C( 21), UINT8_C(247), UINT8_C( 78), UINT8_C(142), UINT8_C(144), UINT8_C(250) },
      { UINT8_C( 71), UINT8_C(119), UINT8_C( 32), UINT8_C( 61), UINT8_C( 22), UINT8_C(115), UINT8_C( 56), UINT8_C( 21) },
      { UINT8_C( 92), UINT8_C( 90), UINT8_C( 76), UINT8_C( 80), UINT8_C(117), UINT8_C(  8), UINT8_C(221), UINT8_C(  3) },
      { UINT8_C(246), UINT8_C( 19), UINT8_C(149), UINT8_C(  7), UINT8_C( 92), UINT8_C( 38), UINT8_C(232), UINT8_C( 57) } },
    { { UINT8_C(107), UINT8_C( 99), UINT8_C( 25), UINT8_C( 10), UINT8_C(164), UINT8_C( 29), UINT8_C(108), UINT8_C( 22) },
      { UINT8_C( 90), UINT8_C(129), UINT8_C( 13), UINT8_C(168), UINT8_C( 16), UINT8_C(158), UINT8_C(162), UINT8_C( 87) },
      { UINT8_C( 21), UINT8_C(194), UINT8_C(149), UINT8_C( 43), UINT8_C( 54), UINT8_C(205), UINT8_C( 64), UINT8_C(146) },
      { UINT8_C(205), UINT8_C( 37), UINT8_C(170), UINT8_C( 66), UINT8_C(  4), UINT8_C(163), UINT8_C(236), UINT8_C(180) } },
    { { UINT8_C( 39), UINT8_C(140), UINT8_C(226), UINT8_C(156), UINT8_C(148), UINT8_C(192), UINT8_C(160),    UINT8_MAX },
      { UINT8_C( 35), UINT8_C(185), UINT8_C( 10), UINT8_C(199), UINT8_C(214), UINT8_C(118), UINT8_C(221), UINT8_C( 48) },
      { UINT8_C(247), UINT8_C(235), UINT8_C(217), UINT8_C(  7), UINT8_C(137), UINT8_C(123), UINT8_C( 95), UINT8_C(158) },
      { UINT8_C(236), UINT8_C( 95), UINT8_C( 92), UINT8_C( 13), UINT8_C( 26), UINT8_C(114), UINT8_C(163), UINT8_C(159) } },
    { { UINT8_C( 62), UINT8_C(244), UINT8_C(201), UINT8_C(116), UINT8_C(193), UINT8_C(  9), UINT8_C(  6), UINT8_C(233) },
      { UINT8_C(149), UINT8_C(233), UINT8_C(133), UINT8_C( 41), UINT8_C(169), UINT8_C( 37), UINT8_C( 40), UINT8_C(204) },
      { UINT8_C(223), UINT8_C( 50), UINT8_C(148), UINT8_C(181), UINT8_C(168), UINT8_C(113), UINT8_C(230), UINT8_C(160) },
      { UINT8_C(  9), UINT8_C(118), UINT8_C(173), UINT8_C(113), UINT8_C(169), UINT8_C( 94), UINT8_C(246), UINT8_C(105) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint8x8_t a = simde_vld1_u8(test_vec[i].a);
    simde_uint8x8_t b = simde_vld1_u8(test_vec[i].b);
    simde_uint8x8_t c = simde_vld1_u8(test_vec[i].c);
    simde_uint8x8_t r = simde_vmla_u8(a, b, c);

    simde_test_arm_neon_assert_equal_u8x8(r, simde_vld1_u8(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vmla_u16 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    uint16_t a[4];
    uint16_t b[4];
    uint16_t c[4];
    uint16_t r[4];
  } test_vec[] = {
    { { UINT16_C(33884), UINT16_C(33998), UINT16_C(54257), UINT16_C( 4534) },
      { UINT16_C(   87), UINT16_C(11697), UINT16_C(54623), UINT16_C(61277) },
      { UINT16_C(41847), UINT16_C(64502), UINT16_C(55349), UINT16_C(33687) },
      { UINT16_C( 4557), UINT16_C(63460), UINT16_C(10396), UINT16_C(55441) } },
    { { UINT16_C(47710), UINT16_C( 1621), UINT16_C(61515), UINT16_C(43253) },
      { UINT16_C(50037), UINT16_C(26156), UINT16_C(58262), UINT16_C(61048) },
      { UINT16_C(10723), UINT16_C(16923), UINT16_C(30974), UINT16_C(30001) },
      { UINT16_C(51229), UINT16_C( 9465), UINT16_C( 3871), UINT16_C( 9709) } },
    { { UINT16_C(10011), UINT16_C(20849), UINT16_C( 2303), UINT16_C(24276) },
      { UINT16_C(10946), UINT16_C( 3684), UINT16_C(22810), UINT16_C(36790) },
      { UINT16_C(57885), UINT16_C(46070), UINT16_C(28357), UINT16_C(43169) },
      { UINT16_C(17173), UINT16_C( 4489), UINT16_C(50689), UINT16_C(12362) } },
    { { UINT16_C(48279), UINT16_C(38378), UINT16_C( 6965), UINT16_C(20491) },
      { UINT16_C(31810), UINT16_C(17057), UINT16_C(30340), UINT16_C(18336) },
      { UINT16_C( 1184), UINT16_C(47701), UINT16_C( 2910), UINT16_C(31562) },
      { UINT16_C(28119), UINT16_C(44895), UINT16_C(19373), UINT16_C(58443) } },
    { { UINT16_C(16621), UINT16_C(45870), UINT16_C(53422), UINT16_C(17755) },
      { UINT16_C(18060), UINT16_C(49626), UINT16_C(58721), UINT16_C(42002) },
      { UINT16_C(45921), UINT16_C(59110), UINT16_C(34345), UINT16_C(51501) },
      { UINT16_C(57337), UINT16_C(47370), UINT16_C(21303), UINT16_C(16005) } },
    { { UINT16_C(33418), UINT16_C(59524), UINT16_C(52877), UINT16_C(31331) },
      { UINT16_C(37390), UINT16_C(48173), UINT16_C(35170), UINT16_C(60929) },
      { UINT16_C(56271), UINT16_C(12464), UINT16_C(49857), UINT16_C( 8916) },
      { UINT16_C(38364), UINT16_C(46964), UINT16_C(42351), UINT16_C(46391) } },
    { { UINT16_C(47733), UINT16_C(40712), UINT16_C(13632), UINT16_C(52072) },
      { UINT16_C(60599), UINT16_C(17587), UINT16_C( 6074), UINT16_C(51391) },
      { UINT16_C(60585), UINT16_C( 2948), UINT16_C(34165), UINT16_C(17657) },
      { UINT16_C(45892), UINT16_C(48212), UINT16_C(44866), UINT16_C(51503) } },
    { { UINT16_C(43361), UINT16_C( 8821), UINT16_C(18795), UINT16_C(57668) },
      { UINT16_C(19716), UINT16_C(17536), UINT16_C(59522), UINT16_C(14863) },
      { UINT16_C(50133), UINT16_C(36734), UINT16_C(15834), UINT16_C(33624) },
      { UINT16_C(51637), UINT16_C(22901), UINT16_C(16927), UINT16_C(33644) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint16x4_t a = simde_vld1_u16(test_vec[i].a);
    simde_uint16x4_t b = simde_vld1_u16(test_vec[i].b);
    simde_uint16x4_t c = simde_vld1_u16(test_vec[i].c);
    simde_uint16x4_t r = simde_vmla_u16(a, b, c);
    simde_test_arm_neon_assert_equal_u16x4(r, simde_vld1_u16(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vmla_u32 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    uint32_t a[2];
    uint32_t b[2];
    uint32_t c[2];
    uint32_t r[2];
  } test_vec[] = {
    { { UINT32_C(3833350932), UINT32_C(3771528631) },
      { UINT32_C(1108988095), UINT32_C(2937766969) },
      { UINT32_C( 780880486), UINT32_C(1841350699) },
      { UINT32_C(1523690798), UINT32_C(2740482890) } },
    { { UINT32_C(1330709669), UINT32_C(2095324776) },
      { UINT32_C( 543252585), UINT32_C( 352333142) },
      { UINT32_C( 928455165), UINT32_C(1155953373) },
      { UINT32_C( 614894954), UINT32_C(1165987238) } },
    { { UINT32_C(3883037116), UINT32_C(3730125369) },
      { UINT32_C(2653791798), UINT32_C( 756748740) },
      { UINT32_C(3360521330), UINT32_C(2799521193) },
      { UINT32_C(2726731208), UINT32_C( 935321757) } },
    { { UINT32_C(1155347559), UINT32_C(1669907366) },
      { UINT32_C(1850407732), UINT32_C(1682743085) },
      { UINT32_C( 167934534), UINT32_C(4248313227) },
      { UINT32_C( 662482079), UINT32_C(3523430933) } },
    { { UINT32_C(1120241049), UINT32_C( 988390099) },
      { UINT32_C(2105460439), UINT32_C(3202353034) },
      { UINT32_C( 791423746), UINT32_C( 278100426) },
      { UINT32_C( 790442055), UINT32_C(2944257975) } },
    { { UINT32_C(2115737331), UINT32_C(1299993523) },
      { UINT32_C(2878292440), UINT32_C(3152378084) },
      { UINT32_C(3375916095), UINT32_C(1837570411) },
      { UINT32_C(2874485531), UINT32_C( 326115071) } },
    { { UINT32_C( 245150788), UINT32_C( 538914861) },
      { UINT32_C(2040412870), UINT32_C(1707481741) },
      { UINT32_C(1074878044), UINT32_C( 234616526) },
      { UINT32_C(1381914476), UINT32_C(2487946147) } },
    { { UINT32_C(3319149402), UINT32_C(2419220044) },
      { UINT32_C(1067437842), UINT32_C(3311386367) },
      { UINT32_C(2235497976), UINT32_C(1961493784) },
      { UINT32_C(3634861770), UINT32_C( 285032756) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint32x2_t a = simde_vld1_u32(test_vec[i].a);
    simde_uint32x2_t b = simde_vld1_u32(test_vec[i].b);
    simde_uint32x2_t c = simde_vld1_u32(test_vec[i].c);
    simde_uint32x2_t r = simde_vmla_u32(a, b, c);
    simde_test_arm_neon_assert_equal_u32x2(r, simde_vld1_u32(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vmlaq_f32 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    simde_float32 a[4];
    simde_float32 b[4];
    simde_float32 c[4];
    simde_float32 r[4];
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(145.140869), SIMDE_FLOAT32_C(86.372559), SIMDE_FLOAT32_C(588.548218), SIMDE_FLOAT32_C(215.169800) },
      { SIMDE_FLOAT32_C(440.652344), SIMDE_FLOAT32_C(-714.658264), SIMDE_FLOAT32_C(-845.502808), SIMDE_FLOAT32_C(657.962158) },
      { SIMDE_FLOAT32_C(752.153320), SIMDE_FLOAT32_C(738.940552), SIMDE_FLOAT32_C(-56.434509), SIMDE_FLOAT32_C(-510.827606) },
      { SIMDE_FLOAT32_C(331583.281250), SIMDE_FLOAT32_C(-528003.625000), SIMDE_FLOAT32_C(48304.082031), SIMDE_FLOAT32_C(-335890.062500) } },
    { { SIMDE_FLOAT32_C(204.974365), SIMDE_FLOAT32_C(-576.728638), SIMDE_FLOAT32_C(89.728027), SIMDE_FLOAT32_C(612.498413) },
      { SIMDE_FLOAT32_C(-581.968323), SIMDE_FLOAT32_C(434.484985), SIMDE_FLOAT32_C(-203.843140), SIMDE_FLOAT32_C(812.033081) },
      { SIMDE_FLOAT32_C(-54.438843), SIMDE_FLOAT32_C(-360.203674), SIMDE_FLOAT32_C(-623.818970), SIMDE_FLOAT32_C(-160.126221) },
      { SIMDE_FLOAT32_C(31886.656250), SIMDE_FLOAT32_C(-157079.828125), SIMDE_FLOAT32_C(127250.945312), SIMDE_FLOAT32_C(-129415.289062) } },
    { { SIMDE_FLOAT32_C(-430.798706), SIMDE_FLOAT32_C(612.035400), SIMDE_FLOAT32_C(-285.161377), SIMDE_FLOAT32_C(-857.128662) },
      { SIMDE_FLOAT32_C(-202.940674), SIMDE_FLOAT32_C(-256.752319), SIMDE_FLOAT32_C(574.135498), SIMDE_FLOAT32_C(942.200195) },
      { SIMDE_FLOAT32_C(829.620117), SIMDE_FLOAT32_C(162.683838), SIMDE_FLOAT32_C(157.370117), SIMDE_FLOAT32_C(270.272583) },
      { SIMDE_FLOAT32_C(-168794.468750), SIMDE_FLOAT32_C(-41157.417969), SIMDE_FLOAT32_C(90066.609375), SIMDE_FLOAT32_C(253793.750000) } },
    { { SIMDE_FLOAT32_C(448.025513), SIMDE_FLOAT32_C(311.867310), SIMDE_FLOAT32_C(-71.765259), SIMDE_FLOAT32_C(200.178955) },
      { SIMDE_FLOAT32_C(50.807861), SIMDE_FLOAT32_C(871.800171), SIMDE_FLOAT32_C(689.351196), SIMDE_FLOAT32_C(-744.217712) },
      { SIMDE_FLOAT32_C(-704.928345), SIMDE_FLOAT32_C(-220.920593), SIMDE_FLOAT32_C(868.280640), SIMDE_FLOAT32_C(-286.896667) },
      { SIMDE_FLOAT32_C(-35367.875000), SIMDE_FLOAT32_C(-192286.734375), SIMDE_FLOAT32_C(598478.562500), SIMDE_FLOAT32_C(213713.750000) } },
    { { SIMDE_FLOAT32_C(-786.435486), SIMDE_FLOAT32_C(-335.562378), SIMDE_FLOAT32_C(-474.863464), SIMDE_FLOAT32_C(159.125610) },
      { SIMDE_FLOAT32_C(304.234009), SIMDE_FLOAT32_C(-98.682495), SIMDE_FLOAT32_C(998.999390), SIMDE_FLOAT32_C(873.435303) },
      { SIMDE_FLOAT32_C(-486.647034), SIMDE_FLOAT32_C(-286.161804), SIMDE_FLOAT32_C(-983.693298), SIMDE_FLOAT32_C(310.412231) },
      { SIMDE_FLOAT32_C(-148841.015625), SIMDE_FLOAT32_C(27903.597656), SIMDE_FLOAT32_C(-983183.875000), SIMDE_FLOAT32_C(271284.125000) } },
    { { SIMDE_FLOAT32_C(457.085815), SIMDE_FLOAT32_C(590.442139), SIMDE_FLOAT32_C(252.612549), SIMDE_FLOAT32_C(286.706055) },
      { SIMDE_FLOAT32_C(-246.873962), SIMDE_FLOAT32_C(-590.017212), SIMDE_FLOAT32_C(-443.021301), SIMDE_FLOAT32_C(-798.848389) },
      { SIMDE_FLOAT32_C(721.850098), SIMDE_FLOAT32_C(485.213501), SIMDE_FLOAT32_C(401.330566), SIMDE_FLOAT32_C(-227.341858) },
      { SIMDE_FLOAT32_C(-177748.921875), SIMDE_FLOAT32_C(-285693.875000), SIMDE_FLOAT32_C(-177545.375000), SIMDE_FLOAT32_C(181898.375000) } },
    { { SIMDE_FLOAT32_C(357.013794), SIMDE_FLOAT32_C(90.682007), SIMDE_FLOAT32_C(28.440430), SIMDE_FLOAT32_C(652.085327) },
      { SIMDE_FLOAT32_C(869.761353), SIMDE_FLOAT32_C(-103.278809), SIMDE_FLOAT32_C(-634.811157), SIMDE_FLOAT32_C(-916.674072) },
      { SIMDE_FLOAT32_C(561.158813), SIMDE_FLOAT32_C(-109.674683), SIMDE_FLOAT32_C(242.451660), SIMDE_FLOAT32_C(-134.607117) },
      { SIMDE_FLOAT32_C(488431.250000), SIMDE_FLOAT32_C(11417.751953), SIMDE_FLOAT32_C(-153882.578125), SIMDE_FLOAT32_C(124042.937500) } },
    { { SIMDE_FLOAT32_C(791.642822), SIMDE_FLOAT32_C(241.451050), SIMDE_FLOAT32_C(-261.171753), SIMDE_FLOAT32_C(-695.004150) },
      { SIMDE_FLOAT32_C(955.289307), SIMDE_FLOAT32_C(-244.864990), SIMDE_FLOAT32_C(615.408081), SIMDE_FLOAT32_C(412.375122) },
      { SIMDE_FLOAT32_C(-654.422729), SIMDE_FLOAT32_C(-131.979187), SIMDE_FLOAT32_C(-300.918701), SIMDE_FLOAT32_C(98.703369) },
      { SIMDE_FLOAT32_C(-624371.437500), SIMDE_FLOAT32_C(32558.533203), SIMDE_FLOAT32_C(-185448.968750), SIMDE_FLOAT32_C(40007.808594) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x4_t a = simde_vld1q_f32(test_vec[i].a);
    simde_float32x4_t b = simde_vld1q_f32(test_vec[i].b);
    simde_float32x4_t c = simde_vld1q_f32(test_vec[i].c);
    simde_float32x4_t r = simde_vmlaq_f32(a, b, c);
    simde_test_arm_neon_assert_equal_f32x4(r, simde_vld1q_f32(test_vec[i].r), 1);
  }

  return 0;
}

static int
test_simde_vmlaq_f64 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    simde_float64 a[2];
    simde_float64 b[2];
    simde_float64 c[2];
    simde_float64 r[2];
  } test_vec[] = {
    { { SIMDE_FLOAT64_C(137.836326), SIMDE_FLOAT64_C(180.498224) },
      { SIMDE_FLOAT64_C(70.815405), SIMDE_FLOAT64_C(-388.999976) },
      { SIMDE_FLOAT64_C(-611.056813), SIMDE_FLOAT64_C(-662.416708) },
      { SIMDE_FLOAT64_C(-43134.399584), SIMDE_FLOAT64_C(257860.581526) } },
    { { SIMDE_FLOAT64_C(-410.709663), SIMDE_FLOAT64_C(-321.801186) },
      { SIMDE_FLOAT64_C(20.311225), SIMDE_FLOAT64_C(-337.649517) },
      { SIMDE_FLOAT64_C(-755.163089), SIMDE_FLOAT64_C(32.799101) },
      { SIMDE_FLOAT64_C(-15748.996891), SIMDE_FLOAT64_C(-11396.401804) } },
    { { SIMDE_FLOAT64_C(-790.783079), SIMDE_FLOAT64_C(351.759081) },
      { SIMDE_FLOAT64_C(914.436994), SIMDE_FLOAT64_C(117.928983) },
      { SIMDE_FLOAT64_C(-166.522701), SIMDE_FLOAT64_C(878.769813) },
      { SIMDE_FLOAT64_C(-153065.301121), SIMDE_FLOAT64_C(103984.189630) } },
    { { SIMDE_FLOAT64_C(-131.289381), SIMDE_FLOAT64_C(-355.855969) },
      { SIMDE_FLOAT64_C(31.078331), SIMDE_FLOAT64_C(58.849271) },
      { SIMDE_FLOAT64_C(-20.792446), SIMDE_FLOAT64_C(-30.490121) },
      { SIMDE_FLOAT64_C(-777.483883), SIMDE_FLOAT64_C(-2150.177382) } },
    { { SIMDE_FLOAT64_C(869.063754), SIMDE_FLOAT64_C(516.089691) },
      { SIMDE_FLOAT64_C(-998.833277), SIMDE_FLOAT64_C(424.541474) },
      { SIMDE_FLOAT64_C(263.351169), SIMDE_FLOAT64_C(168.341670) },
      { SIMDE_FLOAT64_C(-262174.847521), SIMDE_FLOAT64_C(71984.110331) } },
    { { SIMDE_FLOAT64_C(546.778995), SIMDE_FLOAT64_C(-598.812505) },
      { SIMDE_FLOAT64_C(-651.160107), SIMDE_FLOAT64_C(-382.405600) },
      { SIMDE_FLOAT64_C(12.187520), SIMDE_FLOAT64_C(-262.216919) },
      { SIMDE_FLOAT64_C(-7389.247558), SIMDE_FLOAT64_C(99674.405701) } },
    { { SIMDE_FLOAT64_C(-44.822308), SIMDE_FLOAT64_C(601.477857) },
      { SIMDE_FLOAT64_C(415.981895), SIMDE_FLOAT64_C(975.488918) },
      { SIMDE_FLOAT64_C(-736.171662), SIMDE_FLOAT64_C(660.818807) },
      { SIMDE_FLOAT64_C(-306278.905223), SIMDE_FLOAT64_C(645222.900518) } },
    { { SIMDE_FLOAT64_C(8.288018), SIMDE_FLOAT64_C(-526.954741) },
      { SIMDE_FLOAT64_C(12.577887), SIMDE_FLOAT64_C(-77.274989) },
      { SIMDE_FLOAT64_C(590.974242), SIMDE_FLOAT64_C(846.055186) },
      { SIMDE_FLOAT64_C(7441.495354), SIMDE_FLOAT64_C(-65905.859876) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float64x2_t a = simde_vld1q_f64(test_vec[i].a);
    simde_float64x2_t b = simde_vld1q_f64(test_vec[i].b);
    simde_float64x2_t c = simde_vld1q_f64(test_vec[i].c);
    simde_float64x2_t r = simde_vmlaq_f64(a, b, c);

    simde_test_arm_neon_assert_equal_f64x2(r, simde_vld1q_f64(test_vec[i].r), 1);
  }

  return 0;
}

static int
test_simde_vmlaq_s8 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    int8_t a[16];
    int8_t b[16];
    int8_t c[16];
    int8_t r[16];
  } test_vec[] = {
    { { -INT8_C( 119),  INT8_C(  54), -INT8_C(  42),  INT8_C(   7), -INT8_C(  21), -INT8_C(  83), -INT8_C(  69),  INT8_C( 123),
        -INT8_C(  21), -INT8_C(  32),  INT8_C(   5), -INT8_C(  52), -INT8_C(  83), -INT8_C(  31),  INT8_C(  59),  INT8_C(  78) },
      {  INT8_C(  53),  INT8_C(  26), -INT8_C( 101),  INT8_C(  21),  INT8_C(   9),  INT8_C(  41), -INT8_C(  27), -INT8_C(  91),
        -INT8_C(  79),  INT8_C(  55),  INT8_C(  62),  INT8_C(  89),  INT8_C(  47), -INT8_C( 123),  INT8_C(  15), -INT8_C(  71) },
      { -INT8_C(  69), -INT8_C(  27), -INT8_C(  64), -INT8_C(  89), -INT8_C( 110),  INT8_C( 123),  INT8_C(  34),  INT8_C( 126),
         INT8_C(  91),  INT8_C(  40),  INT8_C(  74),  INT8_C(   9),  INT8_C(   9), -INT8_C( 123),  INT8_C(  87),  INT8_C(  62) },
      {  INT8_C(  64),  INT8_C( 120),  INT8_C(  22), -INT8_C(  70),  INT8_C(  13),  INT8_C(  96),  INT8_C(  37), -INT8_C(  79),
        -INT8_C(  42),  INT8_C( 120), -INT8_C(  15), -INT8_C(  19),  INT8_C(  84), -INT8_C(   6),  INT8_C(  84),  INT8_C(  28) } },
    { { -INT8_C(  96), -INT8_C(  13),  INT8_C(  83), -INT8_C(  87),  INT8_C(  28),  INT8_C(  56),  INT8_C(  78), -INT8_C(  51),
         INT8_C( 112), -INT8_C( 116),  INT8_C(  39), -INT8_C(  97),  INT8_C(  17),  INT8_C(  54),  INT8_C(  88), -INT8_C(  51) },
      {  INT8_C(  28),  INT8_C(  24),  INT8_C( 116), -INT8_C(  82), -INT8_C( 109), -INT8_C( 106),  INT8_C(  44), -INT8_C(  17),
        -INT8_C(  66),  INT8_C( 118), -INT8_C(   8), -INT8_C(  57), -INT8_C(   4),  INT8_C(  79),  INT8_C(   5), -INT8_C( 100) },
      {  INT8_C(  66),  INT8_C(  88),  INT8_C(  69),  INT8_C(  94), -INT8_C( 111), -INT8_C( 109),  INT8_C(  44),  INT8_C(   1),
         INT8_C(  31),  INT8_C(  83), -INT8_C(  96),  INT8_C(  48), -INT8_C( 119), -INT8_C(   7), -INT8_C(   3), -INT8_C(  91) },
      { -INT8_C(  40),  INT8_C(  51), -INT8_C( 105), -INT8_C( 115),  INT8_C(  95),  INT8_C(  90), -INT8_C(  34), -INT8_C(  68),
         INT8_C( 114), -INT8_C(  50),  INT8_C(  39), -INT8_C(  17), -INT8_C(  19),  INT8_C(  13),  INT8_C(  73),  INT8_C(  89) } },
    { {  INT8_C(  17),  INT8_C( 113),  INT8_C(  84), -INT8_C(  91),  INT8_C(   8),      INT8_MIN, -INT8_C( 108), -INT8_C(  58),
        -INT8_C(   9), -INT8_C( 116), -INT8_C( 114), -INT8_C(  13), -INT8_C(  37), -INT8_C( 109), -INT8_C( 113),  INT8_C(  30) },
      { -INT8_C(  20), -INT8_C(  44),  INT8_C( 124),  INT8_C( 125),  INT8_C( 103), -INT8_C(  88),  INT8_C( 126), -INT8_C( 122),
        -INT8_C(   5),  INT8_C(  30), -INT8_C(  74), -INT8_C( 123),  INT8_C(  23), -INT8_C(  76),  INT8_C(  42),  INT8_C(  41) },
      {  INT8_C(  37),  INT8_C( 126), -INT8_C(  50),  INT8_C(  45), -INT8_C(   1),  INT8_C(  98), -INT8_C(  12), -INT8_C(  10),
        -INT8_C(  18), -INT8_C( 126), -INT8_C(  23), -INT8_C(  55),  INT8_C(  21),  INT8_C( 120), -INT8_C(  25),  INT8_C(   1) },
      {  INT8_C(  45), -INT8_C(  55),  INT8_C(  28), -INT8_C(  98), -INT8_C(  95), -INT8_C(  48), -INT8_C(  84), -INT8_C( 118),
         INT8_C(  81), -INT8_C(  56),  INT8_C(  52),  INT8_C(  96), -INT8_C(  66), -INT8_C(  13),  INT8_C( 117),  INT8_C(  71) } },
    { {  INT8_C(  76),  INT8_C( 100),  INT8_C( 126), -INT8_C(  77),  INT8_C(  12), -INT8_C(   4),  INT8_C(  57),  INT8_C(   8),
         INT8_C(  27), -INT8_C(  17), -INT8_C( 115),  INT8_C(  50), -INT8_C(  93), -INT8_C(  73),  INT8_C(  91), -INT8_C(  55) },
      {  INT8_C(  54),  INT8_C(  41), -INT8_C(  10),  INT8_C(  53), -INT8_C( 117), -INT8_C(  22),  INT8_C(  43),  INT8_C( 121),
         INT8_C( 108),  INT8_C(  20),  INT8_C(  67), -INT8_C( 126), -INT8_C( 116),  INT8_C(  42), -INT8_C( 125), -INT8_C(  40) },
      { -INT8_C( 114),  INT8_C(   2), -INT8_C( 117), -INT8_C( 101), -INT8_C(   2), -INT8_C(  60), -INT8_C(  93),  INT8_C(  25),
        -INT8_C(  77),  INT8_C(  48),  INT8_C(  76),  INT8_C(  87), -INT8_C(  25), -INT8_C(  89),  INT8_C(  32),  INT8_C(  29) },
      {  INT8_C(  64), -INT8_C(  74),  INT8_C(  16), -INT8_C(  54), -INT8_C(  10),  INT8_C(  36), -INT8_C( 102), -INT8_C(  39),
        -INT8_C(  97), -INT8_C(  81),  INT8_C( 113),  INT8_C(  96), -INT8_C(   9),  INT8_C(  29), -INT8_C(  69),  INT8_C(  65) } },
    { { -INT8_C(  47),  INT8_C(  22),  INT8_C(  82),  INT8_C(  92),  INT8_C(   1),  INT8_C( 125), -INT8_C(  42),  INT8_C( 109),
        -INT8_C( 111),  INT8_C(  25), -INT8_C(  17),  INT8_C(  29),  INT8_C(  67),  INT8_C( 115), -INT8_C(  11), -INT8_C(  46) },
      {  INT8_C( 117),      INT8_MIN,  INT8_C( 109),  INT8_C( 115),  INT8_C(  68),  INT8_C(  16), -INT8_C( 115), -INT8_C(   8),
         INT8_C(  64), -INT8_C(  39),  INT8_C(  79),  INT8_C(  39),      INT8_MIN,  INT8_C( 111),  INT8_C(  69),  INT8_C(  81) },
      { -INT8_C( 123), -INT8_C( 105), -INT8_C(  82), -INT8_C( 122),  INT8_C(  21), -INT8_C( 124), -INT8_C(  12), -INT8_C(  90),
        -INT8_C(  99), -INT8_C(  29), -INT8_C(  60), -INT8_C(  32),  INT8_C(  86), -INT8_C(  71), -INT8_C(  78), -INT8_C(  53) },
      { -INT8_C( 102), -INT8_C( 106),  INT8_C( 104), -INT8_C( 114), -INT8_C( 107), -INT8_C(  67),  INT8_C(  58),  INT8_C(  61),
        -INT8_C(  47), -INT8_C( 124),  INT8_C( 107),  INT8_C(  61),  INT8_C(  67), -INT8_C(  86), -INT8_C(  17),  INT8_C(  13) } },
    { {  INT8_C(  58),  INT8_C(  31),  INT8_C(  63),  INT8_C( 126),  INT8_C(  47), -INT8_C(  52),  INT8_C( 118),  INT8_C( 111),
        -INT8_C(  91), -INT8_C(  59), -INT8_C( 105),  INT8_C(  37),  INT8_C(  52), -INT8_C(  36),  INT8_C( 119), -INT8_C(  70) },
      {  INT8_C( 115),  INT8_C(  37),  INT8_C(  64), -INT8_C( 120), -INT8_C(  87),  INT8_C(  52),  INT8_C(  47),  INT8_C(  70),
         INT8_C(  24), -INT8_C(  13),  INT8_C(  38),  INT8_C( 110), -INT8_C(  84), -INT8_C(  39),  INT8_C(  58), -INT8_C(  26) },
      { -INT8_C(   8),  INT8_C( 121),  INT8_C( 101),  INT8_C(  40),  INT8_C(  69), -INT8_C(  37), -INT8_C( 105), -INT8_C(  22),
        -INT8_C(  95),  INT8_C(  46),  INT8_C(  15), -INT8_C(  43),  INT8_C(  10), -INT8_C( 122), -INT8_C( 113),  INT8_C( 126) },
      { -INT8_C(  94), -INT8_C( 100),      INT8_MAX, -INT8_C(  66), -INT8_C(  68),  INT8_C(  72),  INT8_C(  47),  INT8_C( 107),
        -INT8_C(  67),  INT8_C( 111), -INT8_C(  47), -INT8_C(  85), -INT8_C(  20),  INT8_C( 114), -INT8_C(  35), -INT8_C(  18) } },
    { { -INT8_C(  85), -INT8_C(  48),  INT8_C(   6),  INT8_C(  84),  INT8_C(   4),  INT8_C(  53), -INT8_C( 102),  INT8_C(  28),
         INT8_C(  40), -INT8_C(  63), -INT8_C( 117), -INT8_C(  43), -INT8_C( 102), -INT8_C(  59), -INT8_C(  69), -INT8_C( 110) },
      {  INT8_C(  62),  INT8_C(  32), -INT8_C(  70), -INT8_C( 125), -INT8_C(   4),  INT8_C(  82),  INT8_C( 109), -INT8_C(  99),
             INT8_MIN,  INT8_C( 124),  INT8_C( 114), -INT8_C( 117),  INT8_C(   3),  INT8_C(   2),  INT8_C(   9), -INT8_C(  82) },
      { -INT8_C(  46),  INT8_C(  15),  INT8_C(   3), -INT8_C(  42),  INT8_C(  69), -INT8_C(  99), -INT8_C(  13),  INT8_C( 109),
         INT8_C(  94),  INT8_C( 126),  INT8_C(  66), -INT8_C(   8),  INT8_C(  67), -INT8_C(   2), -INT8_C( 117), -INT8_C( 127) },
      { -INT8_C( 121), -INT8_C(  80),  INT8_C(  52), -INT8_C(  42), -INT8_C(  16),      INT8_MAX,  INT8_C(  17), -INT8_C(  11),
         INT8_C(  40), -INT8_C(  55), -INT8_C(  17),  INT8_C( 125),  INT8_C(  99), -INT8_C(  63), -INT8_C(  98),  INT8_C(  64) } },
    { {  INT8_C(  30),  INT8_C(  69),  INT8_C(   4),  INT8_C(  26), -INT8_C( 105),  INT8_C( 113), -INT8_C(  73),  INT8_C(  24),
        -INT8_C(  19),  INT8_C(  42), -INT8_C(  93), -INT8_C(  16),  INT8_C(  44), -INT8_C(  84), -INT8_C(  97), -INT8_C(   2) },
      { -INT8_C(  69), -INT8_C(  94), -INT8_C(  44),  INT8_C(   0),  INT8_C(  63), -INT8_C(  57),  INT8_C( 110), -INT8_C(  98),
         INT8_C(  69), -INT8_C(  80), -INT8_C( 106), -INT8_C( 120), -INT8_C(  82),  INT8_C(  33),  INT8_C(   9), -INT8_C(  51) },
      {  INT8_C( 103),  INT8_C(  13), -INT8_C(  25), -INT8_C(   2),  INT8_C( 126), -INT8_C(  97),  INT8_C(  22),  INT8_C( 108),
        -INT8_C(  55), -INT8_C(  71),  INT8_C(  92), -INT8_C(  11),  INT8_C( 101), -INT8_C(   5), -INT8_C(  13),  INT8_C(  33) },
      {  INT8_C(  91),      INT8_MAX,  INT8_C(  80),  INT8_C(  26), -INT8_C( 103),  INT8_C(  10),  INT8_C(  43), -INT8_C(  64),
         INT8_C(  26),  INT8_C(  90), -INT8_C( 117),  INT8_C(  24), -INT8_C(  46),  INT8_C(   7),  INT8_C(  42),  INT8_C( 107) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int8x16_t a = simde_vld1q_s8(test_vec[i].a);
    simde_int8x16_t b = simde_vld1q_s8(test_vec[i].b);
    simde_int8x16_t c = simde_vld1q_s8(test_vec[i].c);
    simde_int8x16_t r = simde_vmlaq_s8(a, b, c);

    simde_test_arm_neon_assert_equal_i8x16(r, simde_vld1q_s8(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vmlaq_s16 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    int16_t a[8];
    int16_t b[8];
    int16_t c[8];
    int16_t r[8];
  } test_vec[] = {
    { {  INT16_C( 11663), -INT16_C( 12561), -INT16_C(  6544),  INT16_C( 27850),  INT16_C( 31437), -INT16_C( 27894),  INT16_C(  9795),  INT16_C(  8816) },
      { -INT16_C( 10231),  INT16_C(  3711),  INT16_C( 27259), -INT16_C( 27438),  INT16_C( 30269),  INT16_C( 21709),  INT16_C( 31469),  INT16_C( 31823) },
      {  INT16_C( 16039),  INT16_C(  5962),  INT16_C(  5156), -INT16_C(  3709), -INT16_C( 29298), -INT16_C( 11899), -INT16_C(  2637), -INT16_C( 17164) },
      {  INT16_C( 18798),  INT16_C( 26789),  INT16_C( 31676),  INT16_C( 17984), -INT16_C( 22109), -INT16_C(   373), -INT16_C(  5382), -INT16_C( 24132) } },
    { {  INT16_C( 29645),  INT16_C( 18635), -INT16_C( 25123),  INT16_C(  6876), -INT16_C( 22252),  INT16_C(   366), -INT16_C( 17117), -INT16_C( 13699) },
      { -INT16_C( 14341),  INT16_C(  8161),  INT16_C( 25819),  INT16_C( 27152), -INT16_C( 27150), -INT16_C( 23237),  INT16_C( 12170),  INT16_C( 22626) },
      {  INT16_C( 11682),  INT16_C( 32672),  INT16_C( 32202), -INT16_C(  8551),  INT16_C(  1830),  INT16_C( 19167),  INT16_C( 23748), -INT16_C( 16620) },
      {  INT16_C(  8099), -INT16_C( 11157),  INT16_C(  8619),  INT16_C( 24172), -INT16_C( 30464), -INT16_C(   557), -INT16_C( 17717), -INT16_C( 12251) } },
    { { -INT16_C(  2525), -INT16_C(    34), -INT16_C(  4262),  INT16_C( 19561), -INT16_C( 23420),  INT16_C(  4082),  INT16_C( 21716),  INT16_C( 30311) },
      {  INT16_C(  1921),  INT16_C( 19446), -INT16_C( 28796), -INT16_C( 21718),  INT16_C(  2455),  INT16_C( 23541),  INT16_C(  2406), -INT16_C( 30437) },
      { -INT16_C(  1537),  INT16_C( 23176), -INT16_C(  3608),  INT16_C( 28070), -INT16_C( 26474),  INT16_C( 27260), -INT16_C(  7188),  INT16_C( 28128) },
      { -INT16_C(  5982), -INT16_C( 10610),  INT16_C( 17146),  INT16_C( 11173), -INT16_C(  5378),  INT16_C(  3230),  INT16_C( 28892), -INT16_C(  4857) } },
    { { -INT16_C( 10518),  INT16_C( 28601), -INT16_C(  7322), -INT16_C(   742),  INT16_C(  4076),  INT16_C( 21080),  INT16_C( 29464),  INT16_C(  6364) },
      {  INT16_C( 25709),  INT16_C( 21874),  INT16_C(  6230), -INT16_C(  4926),  INT16_C( 16049), -INT16_C( 25258),  INT16_C( 13857),  INT16_C(  3083) },
      { -INT16_C( 15347),  INT16_C( 29563), -INT16_C( 27225), -INT16_C( 27792), -INT16_C( 14172), -INT16_C( 17178), -INT16_C( 15812), -INT16_C( 22060) },
      {  INT16_C( 25715), -INT16_C( 19585), -INT16_C( 11904), -INT16_C(  2054), -INT16_C( 32432), -INT16_C( 10852),  INT16_C(  9428),  INT16_C( 21752) } },
    { {  INT16_C( 17958),  INT16_C( 31998), -INT16_C( 16033),  INT16_C(  4200), -INT16_C( 16641),  INT16_C(  8621), -INT16_C( 18187),  INT16_C(   557) },
      { -INT16_C( 22404),  INT16_C(  9077), -INT16_C(  6851), -INT16_C(  7753), -INT16_C( 25171), -INT16_C(  5731),  INT16_C( 29279), -INT16_C( 31342) },
      { -INT16_C( 28232),  INT16_C(  5890),  INT16_C( 27218),  INT16_C( 20775), -INT16_C( 10967),  INT16_C(  7794), -INT16_C( 24691),  INT16_C(  2592) },
      { -INT16_C( 25786),  INT16_C( 18152),  INT16_C( 28905),  INT16_C( 23113), -INT16_C(  3916), -INT16_C( 28777), -INT16_C( 18360),  INT16_C( 26733) } },
    { { -INT16_C( 27321), -INT16_C( 31699), -INT16_C(  7046),  INT16_C( 10085),  INT16_C(   897), -INT16_C(  8175), -INT16_C( 23691),  INT16_C( 11622) },
      {  INT16_C( 26676), -INT16_C( 31163),  INT16_C( 27858), -INT16_C(  1064),  INT16_C( 19009), -INT16_C( 12519),  INT16_C( 14826),  INT16_C( 12761) },
      {  INT16_C(  1742),  INT16_C( 18614),  INT16_C(  7147),  INT16_C( 27760), -INT16_C( 32482), -INT16_C( 27827), -INT16_C( 19676),  INT16_C( 22977) },
      { -INT16_C( 22753),  INT16_C( 24891), -INT16_C(  4288),  INT16_C( 30181),  INT16_C( 30751), -INT16_C( 31338),  INT16_C( 26205),  INT16_C( 13055) } },
    { {  INT16_C(  1563), -INT16_C(  4641), -INT16_C( 18574), -INT16_C( 19223),  INT16_C(   514), -INT16_C(  4989),  INT16_C( 23612),  INT16_C(  2589) },
      { -INT16_C( 11422),  INT16_C( 19795), -INT16_C( 15377),  INT16_C(  3514),  INT16_C(  1860),  INT16_C( 26785),  INT16_C( 25274), -INT16_C( 10815) },
      { -INT16_C( 24216), -INT16_C(  9534), -INT16_C( 21672),  INT16_C( 23182),  INT16_C(  4526), -INT16_C(  5562),  INT16_C( 25709), -INT16_C( 12044) },
      { -INT16_C( 30741),  INT16_C( 13509), -INT16_C( 18790), -INT16_C( 18923),  INT16_C( 30266), -INT16_C( 19831),  INT16_C(  3438), -INT16_C( 27119) } },
    { {  INT16_C( 18231),  INT16_C(  9757), -INT16_C( 10486),  INT16_C( 20020), -INT16_C( 10786), -INT16_C( 26441),  INT16_C( 30775), -INT16_C( 24723) },
      {  INT16_C( 12313),  INT16_C( 29305),  INT16_C(  2267), -INT16_C( 30260),  INT16_C(  4889), -INT16_C( 30861),  INT16_C( 26743), -INT16_C( 20905) },
      {  INT16_C( 29871), -INT16_C( 17707),  INT16_C(  2380),  INT16_C( 10760), -INT16_C( 16418),  INT16_C(  5571),  INT16_C( 12344),  INT16_C( 20916) },
      {  INT16_C( 31822),  INT16_C( 20170),  INT16_C( 11022),  INT16_C(  5268),  INT16_C(  3212),  INT16_C( 13392), -INT16_C( 24001), -INT16_C( 17511) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x8_t a = simde_vld1q_s16(test_vec[i].a);
    simde_int16x8_t b = simde_vld1q_s16(test_vec[i].b);
    simde_int16x8_t c = simde_vld1q_s16(test_vec[i].c);
    simde_int16x8_t r = simde_vmlaq_s16(a, b, c);

    simde_test_arm_neon_assert_equal_i16x8(r, simde_vld1q_s16(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vmlaq_s32 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    int32_t a[4];
    int32_t b[4];
    int32_t c[4];
    int32_t r[4];
  } test_vec[] = {
    { {  INT32_C(   710046150), -INT32_C(   241640202), -INT32_C(  1703216902), -INT32_C(  1791793692) },
      {  INT32_C(   934905717),  INT32_C(    54536198), -INT32_C(   808807169),  INT32_C(  1335743881) },
      {  INT32_C(  1031401287), -INT32_C(   969993524), -INT32_C(   278812406), -INT32_C(  2088463346) },
      { -INT32_C(  1148568007),  INT32_C(   144911806), -INT32_C(    94363152),  INT32_C(  1693206370) } },
    { {  INT32_C(   582696476),  INT32_C(  1713830758),  INT32_C(   406188175),  INT32_C(   208130757) },
      { -INT32_C(  1907695166), -INT32_C(    44795405),  INT32_C(   837596450),  INT32_C(  1723101514) },
      {  INT32_C(   361263023), -INT32_C(   109334934),  INT32_C(  1678881182),  INT32_C(  1164999043) },
      { -INT32_C(  1193365574), -INT32_C(  1463442428), -INT32_C(   523485813),  INT32_C(  1722402211) } },
    { {  INT32_C(  1305721434),  INT32_C(  1447700531),  INT32_C(   663173085),  INT32_C(  1468873640) },
      {  INT32_C(   359405227),  INT32_C(  1661987012),  INT32_C(   482812057), -INT32_C(   211667047) },
      {  INT32_C(   624965106),  INT32_C(   997952349),  INT32_C(  1784808130), -INT32_C(   373166018) },
      {  INT32_C(  1349684992), -INT32_C(   123722905),  INT32_C(  1497439695), -INT32_C(  1999691082) } },
    { { -INT32_C(   889311994), -INT32_C(  1372779243), -INT32_C(   942934994),  INT32_C(   515583276) },
      { -INT32_C(  1069286558),  INT32_C(  1224458118), -INT32_C(     5087807),  INT32_C(  1407742797) },
      { -INT32_C(  1239488607),  INT32_C(   577063924),  INT32_C(  1827287104), -INT32_C(  1081432739) },
      {  INT32_C(   789623720),  INT32_C(  1528421069),  INT32_C(  1147245678),  INT32_C(   117420325) } },
    { {  INT32_C(   662687136),  INT32_C(  1315928716),  INT32_C(   625812184),  INT32_C(   913913493) },
      {  INT32_C(   300783389),  INT32_C(   573854434), -INT32_C(   544334206),  INT32_C(  1671305411) },
      {  INT32_C(  1921654502),  INT32_C(  1891695256), -INT32_C(  1315566052),  INT32_C(  1642598212) },
      {  INT32_C(  2051864494), -INT32_C(  1074699076),  INT32_C(   548377872),  INT32_C(  1134770017) } },
    { { -INT32_C(  2005740122), -INT32_C(  1448368601), -INT32_C(  2021115452),  INT32_C(   954934866) },
      { -INT32_C(   576031420), -INT32_C(  1957860497), -INT32_C(  1120017543), -INT32_C(  1742854670) },
      {  INT32_C(   555847930), -INT32_C(    70595529),  INT32_C(  1468224005), -INT32_C(  1114673544) },
      { -INT32_C(   995911154), -INT32_C(   478138624), -INT32_C(  1836749535),  INT32_C(  1468591042) } },
    { {  INT32_C(  1402616547),  INT32_C(   517924773), -INT32_C(  1109713973),  INT32_C(   978778432) },
      { -INT32_C(  1067747447),  INT32_C(  1220289859), -INT32_C(   257933449), -INT32_C(  1867698259) },
      {  INT32_C(   249775977), -INT32_C(   114507218),  INT32_C(   515311581), -INT32_C(  1973940992) },
      {  INT32_C(   331366676),  INT32_C(  1466851247),  INT32_C(   704587398), -INT32_C(  1422212544) } },
    { { -INT32_C(   951405436),  INT32_C(  1359939289), -INT32_C(   230576315),  INT32_C(  1216605919) },
      {  INT32_C(  1666672181),  INT32_C(   106791720), -INT32_C(  1960569717), -INT32_C(  1525318623) },
      {  INT32_C(   174874672), -INT32_C(  1403290778),  INT32_C(   178166827), -INT32_C(  1085136502) },
      {  INT32_C(  1583201908),  INT32_C(  1200455881),  INT32_C(  1772082846),  INT32_C(  1823152553) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x4_t a = simde_vld1q_s32(test_vec[i].a);
    simde_int32x4_t b = simde_vld1q_s32(test_vec[i].b);
    simde_int32x4_t c = simde_vld1q_s32(test_vec[i].c);
    simde_int32x4_t r = simde_vmlaq_s32(a, b, c);
    simde_test_arm_neon_assert_equal_i32x4(r, simde_vld1q_s32(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vmlaq_u8 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    uint8_t a[16];
    uint8_t b[16];
    uint8_t c[16];
    uint8_t r[16];
  } test_vec[] = {
    { { UINT8_C(  2), UINT8_C( 10), UINT8_C(124), UINT8_C(234), UINT8_C( 83), UINT8_C(137), UINT8_C( 86), UINT8_C( 16),
        UINT8_C( 13), UINT8_C( 45), UINT8_C(130), UINT8_C(164), UINT8_C(239), UINT8_C(  2), UINT8_C(135), UINT8_C(180) },
      { UINT8_C(153), UINT8_C(251), UINT8_C(146), UINT8_C(239), UINT8_C( 13), UINT8_C(152), UINT8_C(238), UINT8_C( 33),
        UINT8_C(186), UINT8_C(155), UINT8_C(198), UINT8_C(106), UINT8_C(253), UINT8_C(193),    UINT8_MAX, UINT8_C(  0) },
      { UINT8_C(204), UINT8_C(123), UINT8_C(234), UINT8_C( 31), UINT8_C(  4), UINT8_C( 64), UINT8_C( 47), UINT8_C( 17),
        UINT8_C(109), UINT8_C(177), UINT8_C(181), UINT8_C( 92), UINT8_C(179), UINT8_C( 60), UINT8_C( 16), UINT8_C( 77) },
      { UINT8_C(238), UINT8_C(163), UINT8_C(240), UINT8_C(219), UINT8_C(135), UINT8_C(137), UINT8_C(  8), UINT8_C( 65),
        UINT8_C( 63), UINT8_C( 88), UINT8_C(128), UINT8_C(188), UINT8_C(214), UINT8_C( 62), UINT8_C(119), UINT8_C(180) } },
    { { UINT8_C( 55), UINT8_C(162), UINT8_C( 60), UINT8_C( 68), UINT8_C( 59), UINT8_C( 42), UINT8_C(102), UINT8_C(245),
        UINT8_C(197), UINT8_C( 44), UINT8_C( 96), UINT8_C(195), UINT8_C(238), UINT8_C( 95), UINT8_C(195), UINT8_C(186) },
      { UINT8_C(218), UINT8_C(173), UINT8_C(217), UINT8_C(223), UINT8_C(237), UINT8_C(  8), UINT8_C(240), UINT8_C( 90),
        UINT8_C(185), UINT8_C(166), UINT8_C(183), UINT8_C(108), UINT8_C(226), UINT8_C(199), UINT8_C(185), UINT8_C( 26) },
      { UINT8_C(106), UINT8_C(245), UINT8_C( 94), UINT8_C(165), UINT8_C( 31), UINT8_C(196), UINT8_C(154), UINT8_C(229),
        UINT8_C(241), UINT8_C(250), UINT8_C(168), UINT8_C(223), UINT8_C( 89), UINT8_C(107), UINT8_C(153), UINT8_C( 52) },
      { UINT8_C(123), UINT8_C( 51), UINT8_C(234),    UINT8_MAX, UINT8_C(238), UINT8_C( 74), UINT8_C(198), UINT8_C(119),
        UINT8_C(238), UINT8_C( 72), UINT8_C(120), UINT8_C(215), UINT8_C(128), UINT8_C(140), UINT8_C( 84), UINT8_C(  2) } },
    { { UINT8_C( 24), UINT8_C(114), UINT8_C( 19), UINT8_C(  5), UINT8_C(122), UINT8_C(  3), UINT8_C( 95), UINT8_C( 51),
        UINT8_C(169), UINT8_C( 22), UINT8_C(159), UINT8_C(140), UINT8_C(222), UINT8_C( 89), UINT8_C(166), UINT8_C( 72) },
      { UINT8_C( 78), UINT8_C(  4), UINT8_C(237), UINT8_C(110), UINT8_C(201), UINT8_C(135), UINT8_C( 83), UINT8_C(186),
        UINT8_C(130), UINT8_C(251), UINT8_C(153), UINT8_C(219), UINT8_C(102), UINT8_C( 50), UINT8_C( 15), UINT8_C(126) },
      { UINT8_C(164), UINT8_C( 34), UINT8_C(131), UINT8_C( 30), UINT8_C( 38), UINT8_C(226), UINT8_C( 81), UINT8_C(207),
        UINT8_C(249), UINT8_C(240), UINT8_C( 91), UINT8_C(215), UINT8_C( 73), UINT8_C(  1), UINT8_C( 31), UINT8_C(152) },
      { UINT8_C( 16), UINT8_C(250), UINT8_C( 90), UINT8_C(233), UINT8_C( 80), UINT8_C( 49), UINT8_C(162), UINT8_C(153),
        UINT8_C( 27), UINT8_C(102), UINT8_C(  2), UINT8_C(121), UINT8_C(244), UINT8_C(139), UINT8_C(119), UINT8_C( 24) } },
    { { UINT8_C(  6), UINT8_C( 12), UINT8_C(  6), UINT8_C(207), UINT8_C(147), UINT8_C( 89), UINT8_C(137), UINT8_C( 21),
        UINT8_C( 84), UINT8_C( 34), UINT8_C(241), UINT8_C(186), UINT8_C( 84), UINT8_C(  0), UINT8_C( 56), UINT8_C(248) },
      { UINT8_C( 35), UINT8_C(187), UINT8_C( 22), UINT8_C( 73), UINT8_C(157), UINT8_C(103), UINT8_C( 24), UINT8_C(150),
        UINT8_C( 87), UINT8_C(116), UINT8_C(109), UINT8_C(161), UINT8_C(117), UINT8_C(140), UINT8_C( 57), UINT8_C(123) },
      { UINT8_C(152), UINT8_C( 63), UINT8_C( 74), UINT8_C( 44), UINT8_C(152), UINT8_C(211), UINT8_C( 65), UINT8_C(236),
        UINT8_C(245), UINT8_C( 50), UINT8_C(166), UINT8_C( 73), UINT8_C( 51), UINT8_C(222), UINT8_C( 65), UINT8_C( 86) },
      { UINT8_C(206), UINT8_C( 17), UINT8_C( 98), UINT8_C( 91), UINT8_C(203), UINT8_C( 62), UINT8_C(161), UINT8_C( 93),
        UINT8_C(151), UINT8_C(202), UINT8_C(159), UINT8_C(163), UINT8_C(163), UINT8_C(104), UINT8_C(177), UINT8_C( 74) } },
    { { UINT8_C(153), UINT8_C( 87), UINT8_C(159), UINT8_C( 54), UINT8_C(190), UINT8_C(183), UINT8_C(205), UINT8_C( 22),
        UINT8_C( 43), UINT8_C( 58), UINT8_C(183), UINT8_C(161), UINT8_C(199), UINT8_C(240), UINT8_C( 28), UINT8_C( 95) },
      { UINT8_C( 47), UINT8_C(103), UINT8_C(139), UINT8_C(199), UINT8_C( 58), UINT8_C(205), UINT8_C(179), UINT8_C( 48),
           UINT8_MAX, UINT8_C( 89), UINT8_C(121), UINT8_C( 50), UINT8_C( 55), UINT8_C(187), UINT8_C(136), UINT8_C(208) },
      { UINT8_C( 18), UINT8_C( 39), UINT8_C(  6), UINT8_C(209), UINT8_C(223), UINT8_C(211), UINT8_C(231), UINT8_C( 10),
        UINT8_C( 14), UINT8_C(158), UINT8_C(171), UINT8_C(213), UINT8_C(142), UINT8_C(200), UINT8_C( 52), UINT8_C(189) },
      { UINT8_C(231), UINT8_C(  8), UINT8_C(225), UINT8_C(173), UINT8_C( 68), UINT8_C(174), UINT8_C( 82), UINT8_C(246),
        UINT8_C( 29), UINT8_C( 40), UINT8_C(138), UINT8_C( 59), UINT8_C( 73), UINT8_C(  8), UINT8_C(188), UINT8_C(239) } },
    { { UINT8_C( 47), UINT8_C(192), UINT8_C(132), UINT8_C(105), UINT8_C(141), UINT8_C( 55), UINT8_C(153), UINT8_C(140),
        UINT8_C(144), UINT8_C( 19), UINT8_C(191), UINT8_C(199), UINT8_C(206), UINT8_C( 71), UINT8_C(151), UINT8_C(224) },
      { UINT8_C(111), UINT8_C(157), UINT8_C(177), UINT8_C( 78), UINT8_C(113), UINT8_C(152), UINT8_C( 88), UINT8_C(127),
        UINT8_C( 54), UINT8_C(  4), UINT8_C( 84), UINT8_C(196), UINT8_C(204), UINT8_C(136), UINT8_C(129), UINT8_C(251) },
      { UINT8_C( 72), UINT8_C(  5), UINT8_C(100), UINT8_C(213), UINT8_C( 60), UINT8_C(254), UINT8_C( 98), UINT8_C(204),
        UINT8_C( 17), UINT8_C( 33), UINT8_C(147), UINT8_C(223), UINT8_C(104), UINT8_C( 42), UINT8_C(191), UINT8_C(215) },
      { UINT8_C(103), UINT8_C(209), UINT8_C(168), UINT8_C( 79), UINT8_C(  9), UINT8_C(  7), UINT8_C( 73), UINT8_C(192),
        UINT8_C( 38), UINT8_C(151), UINT8_C(251), UINT8_C(131), UINT8_C(174), UINT8_C(151), UINT8_C(214), UINT8_C(173) } },
    { { UINT8_C(200), UINT8_C(113), UINT8_C( 37), UINT8_C( 57), UINT8_C(  9), UINT8_C(126), UINT8_C(184), UINT8_C( 64),
        UINT8_C(130), UINT8_C( 12), UINT8_C(  4), UINT8_C( 78), UINT8_C(148), UINT8_C(134), UINT8_C( 73), UINT8_C(221) },
      { UINT8_C(139), UINT8_C(173), UINT8_C(178), UINT8_C(200), UINT8_C(171), UINT8_C( 20), UINT8_C(148), UINT8_C(188),
        UINT8_C( 53), UINT8_C( 40), UINT8_C(155), UINT8_C(158), UINT8_C( 82), UINT8_C( 91), UINT8_C(117), UINT8_C( 26) },
      { UINT8_C(204), UINT8_C(155), UINT8_C( 83), UINT8_C(213), UINT8_C( 25), UINT8_C( 11), UINT8_C( 21), UINT8_C(155),
        UINT8_C( 23), UINT8_C( 26), UINT8_C(233), UINT8_C(172), UINT8_C(160), UINT8_C( 50), UINT8_C(137), UINT8_C( 43) },
      { UINT8_C(140), UINT8_C( 48), UINT8_C(219), UINT8_C(161), UINT8_C(188), UINT8_C( 90), UINT8_C(220), UINT8_C( 20),
        UINT8_C( 69), UINT8_C( 28), UINT8_C( 23), UINT8_C(118), UINT8_C(212), UINT8_C( 76), UINT8_C(230), UINT8_C( 59) } },
    { { UINT8_C(223), UINT8_C( 59), UINT8_C(243), UINT8_C(139), UINT8_C( 80), UINT8_C(136), UINT8_C( 71), UINT8_C(133),
        UINT8_C(176), UINT8_C(227), UINT8_C( 35), UINT8_C(  2), UINT8_C( 62), UINT8_C(153), UINT8_C( 29), UINT8_C( 10) },
      { UINT8_C( 52), UINT8_C(112), UINT8_C(223), UINT8_C( 77), UINT8_C(124), UINT8_C(245), UINT8_C(232), UINT8_C(147),
        UINT8_C( 15), UINT8_C(209), UINT8_C( 63), UINT8_C(175), UINT8_C(  3), UINT8_C(200), UINT8_C(218), UINT8_C(226) },
      { UINT8_C(  4), UINT8_C(206), UINT8_C(109), UINT8_C( 84), UINT8_C( 86), UINT8_C(181), UINT8_C(217), UINT8_C(  6),
        UINT8_C(152), UINT8_C(253), UINT8_C(  8), UINT8_C(214), UINT8_C(150), UINT8_C( 37), UINT8_C(224), UINT8_C(202) },
      { UINT8_C(175), UINT8_C( 91), UINT8_C(230), UINT8_C(207), UINT8_C(248), UINT8_C(193), UINT8_C(239), UINT8_C(247),
        UINT8_C(152), UINT8_C(112), UINT8_C( 27), UINT8_C( 76), UINT8_C(  0), UINT8_C(129), UINT8_C(221), UINT8_C( 94) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint8x16_t a = simde_vld1q_u8(test_vec[i].a);
    simde_uint8x16_t b = simde_vld1q_u8(test_vec[i].b);
    simde_uint8x16_t c = simde_vld1q_u8(test_vec[i].c);
    simde_uint8x16_t r = simde_vmlaq_u8(a, b, c);

    simde_test_arm_neon_assert_equal_u8x16(r, simde_vld1q_u8(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vmlaq_u16 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    uint16_t a[8];
    uint16_t b[8];
    uint16_t c[8];
    uint16_t r[8];
  } test_vec[] = {
    { { UINT16_C( 9265), UINT16_C(42133), UINT16_C(42540), UINT16_C(31120), UINT16_C(27981), UINT16_C(34441), UINT16_C(19055), UINT16_C(23368) },
      { UINT16_C(63347), UINT16_C(35030), UINT16_C(52357), UINT16_C(48858), UINT16_C(54042), UINT16_C(36395), UINT16_C(41964), UINT16_C( 7515) },
      { UINT16_C(61640), UINT16_C(62658), UINT16_C(21143), UINT16_C(58477), UINT16_C(63168), UINT16_C(12138), UINT16_C(45632), UINT16_C(45962) },
      { UINT16_C(17929), UINT16_C(20161), UINT16_C(58015), UINT16_C(58466), UINT16_C(48333), UINT16_C(18775), UINT16_C(23919), UINT16_C(53078) } },
    { { UINT16_C(24745), UINT16_C(11835), UINT16_C( 5421), UINT16_C(18412), UINT16_C( 6120), UINT16_C(54741), UINT16_C(12475), UINT16_C(33778) },
      { UINT16_C(46112), UINT16_C(46967), UINT16_C(58631), UINT16_C(51099), UINT16_C( 1499), UINT16_C( 7414), UINT16_C(32951), UINT16_C(25039) },
      { UINT16_C( 3041), UINT16_C( 3727), UINT16_C(31776), UINT16_C( 2389), UINT16_C(10899), UINT16_C(20190), UINT16_C(53338), UINT16_C(31441) },
      { UINT16_C( 4297), UINT16_C(11188), UINT16_C( 6669), UINT16_C(  355), UINT16_C(25257), UINT16_C(59177), UINT16_C( 8465), UINT16_C( 1009) } },
    { { UINT16_C(18821), UINT16_C(35890), UINT16_C(52526), UINT16_C( 2387), UINT16_C(18899), UINT16_C(35365), UINT16_C(62921), UINT16_C(43755) },
      { UINT16_C(31488), UINT16_C( 8376), UINT16_C( 3575), UINT16_C(35369), UINT16_C( 1847), UINT16_C(37337), UINT16_C(43736), UINT16_C(23820) },
      { UINT16_C(16115), UINT16_C( 8681), UINT16_C(15371), UINT16_C(56875), UINT16_C(20613), UINT16_C(20073), UINT16_C(21573), UINT16_C(17913) },
      { UINT16_C( 2693), UINT16_C( 2986), UINT16_C(19147), UINT16_C(52278), UINT16_C(14694), UINT16_C(31270), UINT16_C(57857), UINT16_C(26519) } },
    { { UINT16_C(45519), UINT16_C(50790), UINT16_C(36799), UINT16_C(63057), UINT16_C(10903), UINT16_C(28552), UINT16_C(38100), UINT16_C(51404) },
      { UINT16_C(46546), UINT16_C(56809), UINT16_C( 5361), UINT16_C(30396), UINT16_C( 9573), UINT16_C(43716), UINT16_C(48505), UINT16_C(18928) },
      { UINT16_C(22127), UINT16_C(11791), UINT16_C(24805), UINT16_C(31780), UINT16_C(44170), UINT16_C(24555), UINT16_C(46912), UINT16_C( 4647) },
      { UINT16_C( 5085), UINT16_C(42253), UINT16_C(43860), UINT16_C(47297), UINT16_C(12041), UINT16_C(60788), UINT16_C(29204), UINT16_C(60508) } },
    { { UINT16_C( 4204), UINT16_C(24048), UINT16_C(44069), UINT16_C(35539), UINT16_C(39121), UINT16_C(18996), UINT16_C( 9301), UINT16_C(50323) },
      { UINT16_C(41850), UINT16_C(24818), UINT16_C( 5891), UINT16_C(36572), UINT16_C(51395), UINT16_C( 1261), UINT16_C( 5247), UINT16_C(60438) },
      { UINT16_C( 1572), UINT16_C(18761), UINT16_C( 7602), UINT16_C(33747), UINT16_C( 2229), UINT16_C( 2766), UINT16_C(24876), UINT16_C(42959) },
      { UINT16_C(59796), UINT16_C( 1266), UINT16_C(  827), UINT16_C(56871), UINT16_C(41648), UINT16_C(33514), UINT16_C(51497), UINT16_C( 1117) } },
    { { UINT16_C(49412), UINT16_C( 2055), UINT16_C(58328), UINT16_C(40086), UINT16_C(33707), UINT16_C(11168), UINT16_C(46743), UINT16_C(47895) },
      { UINT16_C(24765), UINT16_C(28421), UINT16_C(55421), UINT16_C(13043), UINT16_C(49632), UINT16_C( 3389), UINT16_C( 3106), UINT16_C(10164) },
      { UINT16_C(48077), UINT16_C(42543), UINT16_C(50590), UINT16_C(19010), UINT16_C(57928), UINT16_C(57205), UINT16_C(35992), UINT16_C(21914) },
      { UINT16_C(18269), UINT16_C(42994), UINT16_C(45566), UINT16_C(64828), UINT16_C(51883), UINT16_C(23425), UINT16_C(33479), UINT16_C(24927) } },
    { { UINT16_C(40940), UINT16_C(27333), UINT16_C(47224), UINT16_C(22684), UINT16_C(55673), UINT16_C(39781), UINT16_C( 6629), UINT16_C(46018) },
      { UINT16_C(61908), UINT16_C(29529), UINT16_C(39862), UINT16_C(65213), UINT16_C(12925), UINT16_C( 5597), UINT16_C(30910), UINT16_C(43627) },
      { UINT16_C(12311), UINT16_C(36628), UINT16_C(45544), UINT16_C(25064), UINT16_C(19850), UINT16_C(28924), UINT16_C(48999), UINT16_C(15139) },
      { UINT16_C( 6648), UINT16_C( 9401), UINT16_C(43880), UINT16_C(53476), UINT16_C(43483), UINT16_C(53489), UINT16_C(28759), UINT16_C(43363) } },
    { { UINT16_C(31920), UINT16_C(26542), UINT16_C(27415), UINT16_C(37989), UINT16_C(17309), UINT16_C(23465), UINT16_C( 5307), UINT16_C(53766) },
      { UINT16_C( 6724), UINT16_C(11362), UINT16_C(19147), UINT16_C(22157), UINT16_C(35479), UINT16_C(65222), UINT16_C(59721), UINT16_C(63802) },
      { UINT16_C(59493), UINT16_C(31840), UINT16_C(50772), UINT16_C(61712), UINT16_C(47369), UINT16_C(50253), UINT16_C(21454), UINT16_C( 4758) },
      { UINT16_C(31108), UINT16_C(33902), UINT16_C(63411), UINT16_C(47669), UINT16_C(16876), UINT16_C(38199), UINT16_C(30841), UINT16_C(60930) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint16x8_t a = simde_vld1q_u16(test_vec[i].a);
    simde_uint16x8_t b = simde_vld1q_u16(test_vec[i].b);
    simde_uint16x8_t c = simde_vld1q_u16(test_vec[i].c);
    simde_uint16x8_t r = simde_vmlaq_u16(a, b, c);
    simde_test_arm_neon_assert_equal_u16x8(r, simde_vld1q_u16(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vmlaq_u32 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    uint32_t a[4];
    uint32_t b[4];
    uint32_t c[4];
    uint32_t r[4];
  } test_vec[] = {
    { { UINT32_C(1060715319), UINT32_C(2706085937), UINT32_C(4105014023), UINT32_C(3284141172) },
      { UINT32_C(4288173704), UINT32_C(3432566778), UINT32_C(4076060134), UINT32_C(1353036057) },
      { UINT32_C( 512810732), UINT32_C(2126502774), UINT32_C(3681709158), UINT32_C(4187894385) },
      { UINT32_C(2536698007), UINT32_C(3777778541), UINT32_C(3897834667), UINT32_C(1474826877) } },
    { { UINT32_C(2214147720), UINT32_C(3947860229), UINT32_C(1742553678), UINT32_C(3753411315) },
      { UINT32_C(3623700577), UINT32_C(2320874787), UINT32_C(2590361385), UINT32_C(2190738425) },
      { UINT32_C(1040551225), UINT32_C(1831425054), UINT32_C(2312373910), UINT32_C(3932720265) },
      { UINT32_C(  69255457), UINT32_C(1963341599), UINT32_C( 555674196), UINT32_C(3930246964) } },
    { { UINT32_C(4173424340), UINT32_C(1283594019), UINT32_C(3639076830), UINT32_C( 593132522) },
      { UINT32_C( 643915528), UINT32_C(1234406067), UINT32_C( 433219728), UINT32_C(3372432116) },
      { UINT32_C(3284256160), UINT32_C(3121628124), UINT32_C( 345175850), UINT32_C(2050485362) },
      { UINT32_C(2697327572), UINT32_C(3721011703), UINT32_C(4201643902), UINT32_C(2475666578) } },
    { { UINT32_C(4271937611), UINT32_C(2991010850), UINT32_C(2429295004), UINT32_C(4099526484) },
      { UINT32_C(1891113620), UINT32_C(2267793501), UINT32_C( 832290239), UINT32_C(4121678506) },
      { UINT32_C(2364820330), UINT32_C( 457128831), UINT32_C(2846624597), UINT32_C(1872561626) },
      { UINT32_C(3753178515), UINT32_C(4128246085), UINT32_C(1308446471), UINT32_C(1812629016) } },
    { { UINT32_C(2111788320), UINT32_C(3691317789), UINT32_C(1913495752), UINT32_C(3714562163) },
      { UINT32_C(2204785412), UINT32_C(3969886615), UINT32_C(2392148916), UINT32_C(1895641680) },
      { UINT32_C(2783894920), UINT32_C(2944594919), UINT32_C( 102862739), UINT32_C(1290045768) },
      { UINT32_C(1353327424), UINT32_C(1170171486), UINT32_C(2974131492), UINT32_C(3016404723) } },
    { { UINT32_C(2077183716), UINT32_C(2875682551), UINT32_C( 171572409), UINT32_C(3078240047) },
      { UINT32_C(4217137172), UINT32_C(4021018203), UINT32_C(3069561966), UINT32_C( 973265237) },
      { UINT32_C( 515232039), UINT32_C(4190707008), UINT32_C(1208156953), UINT32_C(1325366842) },
      { UINT32_C( 637500912), UINT32_C( 654464183), UINT32_C( 518667639), UINT32_C(2764196465) } },
    { { UINT32_C(1112104166), UINT32_C(2821846074), UINT32_C( 375269057), UINT32_C( 659578880) },
      { UINT32_C(1917191730), UINT32_C(1013649187), UINT32_C(1283813138), UINT32_C(3550119149) },
      { UINT32_C( 454419680), UINT32_C(2579711704), UINT32_C(1840259693), UINT32_C(3029598338) },
      { UINT32_C(1697468582), UINT32_C(1532185538), UINT32_C(1783551339), UINT32_C( 416014426) } },
    { { UINT32_C( 690412038), UINT32_C(4234580714), UINT32_C(3997821697), UINT32_C(1354883951) },
      { UINT32_C(2691422151), UINT32_C(2319003165), UINT32_C(3556239696), UINT32_C(4035415274) },
      { UINT32_C(1343925862), UINT32_C(1095598144), UINT32_C(3660551787), UINT32_C(1093333113) },
      { UINT32_C(2063471952), UINT32_C(1568250410), UINT32_C(3209514865), UINT32_C(2639453705) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint32x4_t a = simde_vld1q_u32(test_vec[i].a);
    simde_uint32x4_t b = simde_vld1q_u32(test_vec[i].b);
    simde_uint32x4_t c = simde_vld1q_u32(test_vec[i].c);
    simde_uint32x4_t r = simde_vmlaq_u32(a, b, c);

    simde_test_arm_neon_assert_equal_u32x4(r, simde_vld1q_u32(test_vec[i].r));
  }

  return 0;
}

SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(vmla_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vmla_f64)
SIMDE_TEST_FUNC_LIST_ENTRY(vmla_s8)
SIMDE_TEST_FUNC_LIST_ENTRY(vmla_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vmla_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vmla_u8)
SIMDE_TEST_FUNC_LIST_ENTRY(vmla_u16)
SIMDE_TEST_FUNC_LIST_ENTRY(vmla_u32)

SIMDE_TEST_FUNC_LIST_ENTRY(vmlaq_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vmlaq_f64)
SIMDE_TEST_FUNC_LIST_ENTRY(vmlaq_s8)
SIMDE_TEST_FUNC_LIST_ENTRY(vmlaq_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vmlaq_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vmlaq_u8)
SIMDE_TEST_FUNC_LIST_ENTRY(vmlaq_u16)
SIMDE_TEST_FUNC_LIST_ENTRY(vmlaq_u32)
SIMDE_TEST_FUNC_LIST_END

#include "test-neon-footer.h"
