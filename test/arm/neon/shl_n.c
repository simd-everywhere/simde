#define SIMDE_TEST_ARM_NEON_INSN shl_n

#include "test-neon.h"
#include "../../../simde/arm/neon/shl_n.h"

static int
test_simde_vshl_n_s8 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    int8_t a[8];
    int8_t r1[8];
    int8_t r3[8];
    int8_t r5[8];
    int8_t r6[8];
    int8_t r7[8];
  } test_vec[] = {
    { { -INT8_C( 125),  INT8_C( 122), -INT8_C(   9),  INT8_C(  63),  INT8_C(  82),  INT8_C(  28),  INT8_C( 109),  INT8_C(   1) },
      {  INT8_C(   6), -INT8_C(  12), -INT8_C(  18),  INT8_C( 126), -INT8_C(  92),  INT8_C(  56), -INT8_C(  38),  INT8_C(   2) },
      {  INT8_C(  24), -INT8_C(  48), -INT8_C(  72), -INT8_C(   8), -INT8_C( 112), -INT8_C(  32),  INT8_C( 104),  INT8_C(   8) },
      {  INT8_C(  96),  INT8_C(  64), -INT8_C(  32), -INT8_C(  32),  INT8_C(  64),      INT8_MIN, -INT8_C(  96),  INT8_C(  32) },
      { -INT8_C(  64),      INT8_MIN, -INT8_C(  64), -INT8_C(  64),      INT8_MIN,  INT8_C(   0),  INT8_C(  64),  INT8_C(  64) },
      {      INT8_MIN,  INT8_C(   0),      INT8_MIN,      INT8_MIN,  INT8_C(   0),  INT8_C(   0),      INT8_MIN,      INT8_MIN } },
    { { -INT8_C(  58),  INT8_C(  26),  INT8_C(  83),  INT8_C( 124), -INT8_C(  27),  INT8_C(  84), -INT8_C(   4), -INT8_C(  94) },
      { -INT8_C( 116),  INT8_C(  52), -INT8_C(  90), -INT8_C(   8), -INT8_C(  54), -INT8_C(  88), -INT8_C(   8),  INT8_C(  68) },
      {  INT8_C(  48), -INT8_C(  48), -INT8_C( 104), -INT8_C(  32),  INT8_C(  40), -INT8_C(  96), -INT8_C(  32),  INT8_C(  16) },
      { -INT8_C(  64),  INT8_C(  64),  INT8_C(  96),      INT8_MIN, -INT8_C(  96),      INT8_MIN,      INT8_MIN,  INT8_C(  64) },
      {      INT8_MIN,      INT8_MIN, -INT8_C(  64),  INT8_C(   0),  INT8_C(  64),  INT8_C(   0),  INT8_C(   0),      INT8_MIN },
      {  INT8_C(   0),  INT8_C(   0),      INT8_MIN,  INT8_C(   0),      INT8_MIN,  INT8_C(   0),  INT8_C(   0),  INT8_C(   0) } },
    { { -INT8_C(  67),  INT8_C(  73),  INT8_C(  79),  INT8_C( 101),  INT8_C( 112), -INT8_C(  36), -INT8_C(  81),  INT8_C(  33) },
      {  INT8_C( 122), -INT8_C( 110), -INT8_C(  98), -INT8_C(  54), -INT8_C(  32), -INT8_C(  72),  INT8_C(  94),  INT8_C(  66) },
      { -INT8_C(  24),  INT8_C(  72),  INT8_C( 120),  INT8_C(  40),      INT8_MIN, -INT8_C(  32),  INT8_C( 120),  INT8_C(   8) },
      { -INT8_C(  96),  INT8_C(  32), -INT8_C(  32), -INT8_C(  96),  INT8_C(   0),      INT8_MIN, -INT8_C(  32),  INT8_C(  32) },
      {  INT8_C(  64),  INT8_C(  64), -INT8_C(  64),  INT8_C(  64),  INT8_C(   0),  INT8_C(   0), -INT8_C(  64),  INT8_C(  64) },
      {      INT8_MIN,      INT8_MIN,      INT8_MIN,      INT8_MIN,  INT8_C(   0),  INT8_C(   0),      INT8_MIN,      INT8_MIN } },
    { { -INT8_C(  17),  INT8_C(   6), -INT8_C(   9),  INT8_C( 126),  INT8_C(   7), -INT8_C(  51), -INT8_C(  80), -INT8_C( 118) },
      { -INT8_C(  34),  INT8_C(  12), -INT8_C(  18), -INT8_C(   4),  INT8_C(  14), -INT8_C( 102),  INT8_C(  96),  INT8_C(  20) },
      {  INT8_C( 120),  INT8_C(  48), -INT8_C(  72), -INT8_C(  16),  INT8_C(  56),  INT8_C( 104),      INT8_MIN,  INT8_C(  80) },
      { -INT8_C(  32), -INT8_C(  64), -INT8_C(  32), -INT8_C(  64), -INT8_C(  32), -INT8_C(  96),  INT8_C(   0),  INT8_C(  64) },
      { -INT8_C(  64),      INT8_MIN, -INT8_C(  64),      INT8_MIN, -INT8_C(  64),  INT8_C(  64),  INT8_C(   0),      INT8_MIN },
      {      INT8_MIN,  INT8_C(   0),      INT8_MIN,  INT8_C(   0),      INT8_MIN,      INT8_MIN,  INT8_C(   0),  INT8_C(   0) } },
    { {  INT8_C(  71), -INT8_C(  89), -INT8_C(  55), -INT8_C( 102), -INT8_C(  60),  INT8_C(  54), -INT8_C( 101), -INT8_C( 118) },
      { -INT8_C( 114),  INT8_C(  78), -INT8_C( 110),  INT8_C(  52), -INT8_C( 120),  INT8_C( 108),  INT8_C(  54),  INT8_C(  20) },
      {  INT8_C(  56),  INT8_C(  56),  INT8_C(  72), -INT8_C(  48),  INT8_C(  32), -INT8_C(  80), -INT8_C(  40),  INT8_C(  80) },
      { -INT8_C(  32), -INT8_C(  32),  INT8_C(  32),  INT8_C(  64),      INT8_MIN, -INT8_C(  64),  INT8_C(  96),  INT8_C(  64) },
      { -INT8_C(  64), -INT8_C(  64),  INT8_C(  64),      INT8_MIN,  INT8_C(   0),      INT8_MIN, -INT8_C(  64),      INT8_MIN },
      {      INT8_MIN,      INT8_MIN,      INT8_MIN,  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),      INT8_MIN,  INT8_C(   0) } },
    { {  INT8_C(  80), -INT8_C(  17),  INT8_C(   6),  INT8_C(  53),  INT8_C(  67),  INT8_C(   3), -INT8_C(  40),  INT8_C(   0) },
      { -INT8_C(  96), -INT8_C(  34),  INT8_C(  12),  INT8_C( 106), -INT8_C( 122),  INT8_C(   6), -INT8_C(  80),  INT8_C(   0) },
      {      INT8_MIN,  INT8_C( 120),  INT8_C(  48), -INT8_C(  88),  INT8_C(  24),  INT8_C(  24), -INT8_C(  64),  INT8_C(   0) },
      {  INT8_C(   0), -INT8_C(  32), -INT8_C(  64), -INT8_C(  96),  INT8_C(  96),  INT8_C(  96),  INT8_C(   0),  INT8_C(   0) },
      {  INT8_C(   0), -INT8_C(  64),      INT8_MIN,  INT8_C(  64), -INT8_C(  64), -INT8_C(  64),  INT8_C(   0),  INT8_C(   0) },
      {  INT8_C(   0),      INT8_MIN,  INT8_C(   0),      INT8_MIN,      INT8_MIN,      INT8_MIN,  INT8_C(   0),  INT8_C(   0) } },
    { {  INT8_C(  76),  INT8_C(  39),  INT8_C( 101), -INT8_C(  68),  INT8_C(   3),  INT8_C(  20), -INT8_C(  35), -INT8_C(  14) },
      { -INT8_C( 104),  INT8_C(  78), -INT8_C(  54),  INT8_C( 120),  INT8_C(   6),  INT8_C(  40), -INT8_C(  70), -INT8_C(  28) },
      {  INT8_C(  96),  INT8_C(  56),  INT8_C(  40), -INT8_C(  32),  INT8_C(  24), -INT8_C(  96), -INT8_C(  24), -INT8_C( 112) },
      {      INT8_MIN, -INT8_C(  32), -INT8_C(  96),      INT8_MIN,  INT8_C(  96),      INT8_MIN, -INT8_C(  96),  INT8_C(  64) },
      {  INT8_C(   0), -INT8_C(  64),  INT8_C(  64),  INT8_C(   0), -INT8_C(  64),  INT8_C(   0),  INT8_C(  64),      INT8_MIN },
      {  INT8_C(   0),      INT8_MIN,      INT8_MIN,  INT8_C(   0),      INT8_MIN,  INT8_C(   0),      INT8_MIN,  INT8_C(   0) } },
    { {  INT8_C(  26), -INT8_C(  44),  INT8_C( 112),  INT8_C(  33), -INT8_C(  94),  INT8_C(  33), -INT8_C(  85), -INT8_C(  23) },
      {  INT8_C(  52), -INT8_C(  88), -INT8_C(  32),  INT8_C(  66),  INT8_C(  68),  INT8_C(  66),  INT8_C(  86), -INT8_C(  46) },
      { -INT8_C(  48), -INT8_C(  96),      INT8_MIN,  INT8_C(   8),  INT8_C(  16),  INT8_C(   8),  INT8_C(  88),  INT8_C(  72) },
      {  INT8_C(  64),      INT8_MIN,  INT8_C(   0),  INT8_C(  32),  INT8_C(  64),  INT8_C(  32),  INT8_C(  96),  INT8_C(  32) },
      {      INT8_MIN,  INT8_C(   0),  INT8_C(   0),  INT8_C(  64),      INT8_MIN,  INT8_C(  64), -INT8_C(  64),  INT8_C(  64) },
      {  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),      INT8_MIN,  INT8_C(   0),      INT8_MIN,      INT8_MIN,      INT8_MIN } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int8x8_t a = simde_vld1_s8(test_vec[i].a);

    simde_int8x8_t r1 = simde_vshl_n_s8(a, 1);
    simde_int8x8_t r3 = simde_vshl_n_s8(a, 3);
    simde_int8x8_t r5 = simde_vshl_n_s8(a, 5);
    simde_int8x8_t r6 = simde_vshl_n_s8(a, 6);
    simde_int8x8_t r7 = simde_vshl_n_s8(a, 7);

    simde_test_arm_neon_assert_equal_i8x8(r1, simde_vld1_s8(test_vec[i].r1));
    simde_test_arm_neon_assert_equal_i8x8(r3, simde_vld1_s8(test_vec[i].r3));
    simde_test_arm_neon_assert_equal_i8x8(r5, simde_vld1_s8(test_vec[i].r5));
    simde_test_arm_neon_assert_equal_i8x8(r6, simde_vld1_s8(test_vec[i].r6));
    simde_test_arm_neon_assert_equal_i8x8(r7, simde_vld1_s8(test_vec[i].r7));
  }

  return 0;
}

static int
test_simde_vshl_n_s16 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    int16_t a[4];
    int16_t r3[4];
    int16_t r6[4];
    int16_t r10[4];
    int16_t r13[4];
    int16_t r15[4];
  } test_vec[] = {
    { {  INT16_C( 18668),  INT16_C( 18204), -INT16_C(  3037), -INT16_C( 20293) },
      {  INT16_C( 18272),  INT16_C( 14560), -INT16_C( 24296), -INT16_C( 31272) },
      {  INT16_C( 15104), -INT16_C( 14592),  INT16_C(  2240),  INT16_C( 11968) },
      { -INT16_C( 20480),  INT16_C( 28672), -INT16_C( 29696), -INT16_C(  5120) },
      {       INT16_MIN,       INT16_MIN,  INT16_C( 24576),  INT16_C( 24576) },
      {  INT16_C(     0),  INT16_C(     0),       INT16_MIN,       INT16_MIN } },
    { {  INT16_C( 27569),  INT16_C(  5736), -INT16_C( 20588), -INT16_C( 30218) },
      {  INT16_C( 23944), -INT16_C( 19648),  INT16_C( 31904),  INT16_C( 20400) },
      { -INT16_C(  5056), -INT16_C( 26112), -INT16_C(  6912),  INT16_C( 32128) },
      { -INT16_C( 15360), -INT16_C( 24576),  INT16_C( 20480), -INT16_C( 10240) },
      {  INT16_C(  8192),  INT16_C(     0),       INT16_MIN, -INT16_C( 16384) },
      {       INT16_MIN,  INT16_C(     0),  INT16_C(     0),  INT16_C(     0) } },
    { { -INT16_C(  9118),  INT16_C( 22490),  INT16_C( 22818),  INT16_C( 31244) },
      { -INT16_C(  7408), -INT16_C( 16688), -INT16_C( 14064), -INT16_C( 12192) },
      {  INT16_C(  6272), -INT16_C(  2432),  INT16_C( 18560), -INT16_C( 32000) },
      { -INT16_C( 30720),  INT16_C( 26624), -INT16_C( 30720),  INT16_C( 12288) },
      {  INT16_C( 16384),  INT16_C( 16384),  INT16_C( 16384),       INT16_MIN },
      {  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0) } },
    { { -INT16_C( 18368),  INT16_C( 10674), -INT16_C( 29712), -INT16_C(  9127) },
      { -INT16_C( 15872),  INT16_C( 19856),  INT16_C( 24448), -INT16_C(  7480) },
      {  INT16_C(  4096),  INT16_C( 27776), -INT16_C(  1024),  INT16_C(  5696) },
      {  INT16_C(     0), -INT16_C( 14336), -INT16_C( 16384),  INT16_C( 25600) },
      {  INT16_C(     0),  INT16_C( 16384),  INT16_C(     0),  INT16_C(  8192) },
      {  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),       INT16_MIN } },
    { {  INT16_C( 30163), -INT16_C(  2525), -INT16_C(  8343),  INT16_C(  7079) },
      { -INT16_C( 20840), -INT16_C( 20200), -INT16_C(  1208), -INT16_C(  8904) },
      {  INT16_C( 29888), -INT16_C( 30528), -INT16_C(  9664), -INT16_C(  5696) },
      {  INT16_C( 19456), -INT16_C( 29696), -INT16_C( 23552), -INT16_C( 25600) },
      {  INT16_C( 24576),  INT16_C( 24576),  INT16_C(  8192), -INT16_C(  8192) },
      {       INT16_MIN,       INT16_MIN,       INT16_MIN,       INT16_MIN } },
    { {  INT16_C(  3914), -INT16_C(  8399),  INT16_C( 10174),  INT16_C(  8296) },
      {  INT16_C( 31312), -INT16_C(  1656),  INT16_C( 15856),  INT16_C(   832) },
      { -INT16_C( 11648), -INT16_C( 13248), -INT16_C(  4224),  INT16_C(  6656) },
      {  INT16_C( 10240), -INT16_C( 15360), -INT16_C(  2048), -INT16_C( 24576) },
      {  INT16_C( 16384),  INT16_C(  8192), -INT16_C( 16384),  INT16_C(     0) },
      {  INT16_C(     0),       INT16_MIN,  INT16_C(     0),  INT16_C(     0) } },
    { {  INT16_C( 16900),  INT16_C(  9848), -INT16_C( 31589), -INT16_C(  9312) },
      {  INT16_C(  4128),  INT16_C( 13248),  INT16_C(  9432), -INT16_C(  8960) },
      { -INT16_C( 32512), -INT16_C( 25088),  INT16_C(  9920), -INT16_C(  6144) },
      {  INT16_C(  4096), -INT16_C(  8192),  INT16_C( 27648),       INT16_MIN },
      {       INT16_MIN,  INT16_C(     0),  INT16_C( 24576),  INT16_C(     0) },
      {  INT16_C(     0),  INT16_C(     0),       INT16_MIN,  INT16_C(     0) } },
    { {  INT16_C( 21052),  INT16_C( 11268),  INT16_C( 24029), -INT16_C( 20471) },
      { -INT16_C( 28192),  INT16_C( 24608), -INT16_C(  4376), -INT16_C( 32696) },
      { -INT16_C( 28928),  INT16_C(   256),  INT16_C( 30528),  INT16_C(   576) },
      { -INT16_C(  4096),  INT16_C(  4096),  INT16_C( 29696),  INT16_C(  9216) },
      {       INT16_MIN,       INT16_MIN, -INT16_C( 24576),  INT16_C(  8192) },
      {  INT16_C(     0),  INT16_C(     0),       INT16_MIN,       INT16_MIN } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x4_t a = simde_vld1_s16(test_vec[i].a);

    simde_int16x4_t r3 = simde_vshl_n_s16(a, 3);
    simde_int16x4_t r6 = simde_vshl_n_s16(a, 6);
    simde_int16x4_t r10 = simde_vshl_n_s16(a, 10);
    simde_int16x4_t r13 = simde_vshl_n_s16(a, 13);
    simde_int16x4_t r15 = simde_vshl_n_s16(a, 15);

    simde_test_arm_neon_assert_equal_i16x4(r3, simde_vld1_s16(test_vec[i].r3));
    simde_test_arm_neon_assert_equal_i16x4(r6, simde_vld1_s16(test_vec[i].r6));
    simde_test_arm_neon_assert_equal_i16x4(r10, simde_vld1_s16(test_vec[i].r10));
    simde_test_arm_neon_assert_equal_i16x4(r13, simde_vld1_s16(test_vec[i].r13));
    simde_test_arm_neon_assert_equal_i16x4(r15, simde_vld1_s16(test_vec[i].r15));
  }

  return 0;
}

static int
test_simde_vshl_n_s32 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    int32_t a[2];
    int32_t r6[2];
    int32_t r13[2];
    int32_t r19[2];
    int32_t r26[2];
    int32_t r31[2];
  } test_vec[] = {
    { { -INT32_C(   635750729),  INT32_C(  1289635738) },
      { -INT32_C(  2033340992),  INT32_C(   932308608) },
      {  INT32_C(  1725358080), -INT32_C(   923582464) },
      { -INT32_C(  1246232576),  INT32_C(  1020264448) },
      { -INT32_C(   603979776),  INT32_C(  1744830464) },
      {            INT32_MIN,  INT32_C(           0) } },
    { { -INT32_C(  1230867210),  INT32_C(  1451555070) },
      { -INT32_C(  1466090112), -INT32_C(  1589756032) },
      {  INT32_C(  1319026688), -INT32_C(  1625309184) },
      { -INT32_C(  1481637888), -INT32_C(   940572672) },
      { -INT32_C(   671088640), -INT32_C(   134217728) },
      {  INT32_C(           0),  INT32_C(           0) } },
    { {  INT32_C(  1859799447),  INT32_C(  1800629968) },
      { -INT32_C(  1231919680), -INT32_C(   723799040) },
      {  INT32_C(  1228070912),  INT32_C(  1843003392) },
      {  INT32_C(  1287127040),  INT32_C(  1988100096) },
      {  INT32_C(  1543503872),  INT32_C(  1073741824) },
      {            INT32_MIN,  INT32_C(           0) } },
    { { -INT32_C(  1341981360), -INT32_C(  2026618416) },
      {  INT32_C(    12538880), -INT32_C(   854559744) },
      {  INT32_C(  1604976640), -INT32_C(  2009464832) },
      { -INT32_C(   360710144),  INT32_C(   243269632) },
      {  INT32_C(  1073741824),  INT32_C(  1073741824) },
      {  INT32_C(           0),  INT32_C(           0) } },
    { {  INT32_C(   308367223), -INT32_C(  1939980394) },
      { -INT32_C(  1739334208),  INT32_C(   395306368) },
      {  INT32_C(   703520768), -INT32_C(   940392448) },
      {  INT32_C(  2075656192), -INT32_C(    55574528) },
      { -INT32_C(   603979776),  INT32_C(  1476395008) },
      {            INT32_MIN,  INT32_C(           0) } },
    { { -INT32_C(  1304297292), -INT32_C(  1878472711) },
      { -INT32_C(  1870648064),  INT32_C(    36830784) },
      {  INT32_C(  1075216384),  INT32_C(   419373056) },
      {  INT32_C(    94371840),  INT32_C(  1070071808) },
      { -INT32_C(   805306368), -INT32_C(   469762048) },
      {  INT32_C(           0),            INT32_MIN } },
    { { -INT32_C(   503389424), -INT32_C(  1572056495) },
      {  INT32_C(  2142815232), -INT32_C(  1827367872) },
      { -INT32_C(   597557248), -INT32_C(  1974853632) },
      {  INT32_C(   411041792), -INT32_C(  1836580864) },
      {  INT32_C(  1073741824),  INT32_C(  1140850688) },
      {  INT32_C(           0),            INT32_MIN } },
    { {  INT32_C(   525487695),  INT32_C(   128419471) },
      { -INT32_C(   728525888), -INT32_C(   371088448) },
      {  INT32_C(  1237966848), -INT32_C(   254681088) },
      {  INT32_C(  1920466944),  INT32_C(   880279552) },
      {  INT32_C(  1006632960),  INT32_C(  1006632960) },
      {            INT32_MIN,            INT32_MIN } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x2_t a = simde_vld1_s32(test_vec[i].a);

    simde_int32x2_t r6 = simde_vshl_n_s32(a, 6);
    simde_int32x2_t r13 = simde_vshl_n_s32(a, 13);
    simde_int32x2_t r19 = simde_vshl_n_s32(a, 19);
    simde_int32x2_t r26 = simde_vshl_n_s32(a, 26);
    simde_int32x2_t r31 = simde_vshl_n_s32(a, 31);

    simde_test_arm_neon_assert_equal_i32x2(r6, simde_vld1_s32(test_vec[i].r6));
    simde_test_arm_neon_assert_equal_i32x2(r13, simde_vld1_s32(test_vec[i].r13));
    simde_test_arm_neon_assert_equal_i32x2(r19, simde_vld1_s32(test_vec[i].r19));
    simde_test_arm_neon_assert_equal_i32x2(r26, simde_vld1_s32(test_vec[i].r26));
    simde_test_arm_neon_assert_equal_i32x2(r31, simde_vld1_s32(test_vec[i].r31));
  }

  return 0;
}

static int
test_simde_vshl_n_s64 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    int64_t a[1];
    int64_t r13[1];
    int64_t r26[1];
    int64_t r39[1];
    int64_t r52[1];
    int64_t r63[1];
  } test_vec[] = {
    { { -INT64_C( 8607823705097870458) },
      {  INT64_C( 6610801629861036032) },
      { -INT64_C( 3953648589636370432) },
      {  INT64_C( 4193347132826058752) },
      {  INT64_C( 4062246863888187392) },
      {  INT64_C(                   0) } },
    { { -INT64_C( 1048272605653827765) },
      {  INT64_C( 8733552832494002176) },
      {  INT64_C( 8791285945224658944) },
      {  INT64_C( 2125599518316560384) },
      { -INT64_C(  815151532554059776) },
      {                     INT64_MIN } },
    { { -INT64_C(  484364469342631954) },
      { -INT64_C( 1863757007287369728) },
      {  INT64_C( 6006689333375926272) },
      { -INT64_C( 9114169641495691264) },
      {  INT64_C( 9142307243562106880) },
      {  INT64_C(                   0) } },
    { {  INT64_C( 4956995058058425785) },
      {  INT64_C( 6419809379900923904) },
      { -INT64_C(  588913997563035648) },
      {  INT64_C( 8663479275514494976) },
      {  INT64_C( 6597773454097776640) },
      {                     INT64_MIN } },
    { {  INT64_C( 7396623743718276651) },
      { -INT64_C( 4412573595754733568) },
      {  INT64_C( 7815488047943778304) },
      { -INT64_C( 4170591090421792768) },
      { -INT64_C( 2112188225236762624) },
      {                     INT64_MIN } },
    { { -INT64_C( 7519505417405800427) },
      { -INT64_C( 6109917272124252160) },
      { -INT64_C( 6425621267860160512) },
      {  INT64_C( 8318160056625397760) },
      {  INT64_C(   94575592174780416) },
      {                     INT64_MIN } },
    { { -INT64_C( 7751056859285444256) },
      { -INT64_C( 2964689558082682880) },
      {  INT64_C( 7625085262141325312) },
      {  INT64_C( 4023033881195184128) },
      { -INT64_C( 7638104968020361216) },
      {  INT64_C(                   0) } },
    { {  INT64_C( 5849140343110917675) },
      { -INT64_C( 8483412732777504768) },
      { -INT64_C( 7232181249438121984) },
      {  INT64_C( 4913169357984497664) },
      { -INT64_C( 2112188225236762624) },
      {                     INT64_MIN } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int64x1_t a = simde_vld1_s64(test_vec[i].a);

    simde_int64x1_t r13 = simde_vshl_n_s64(a, 13);
    simde_int64x1_t r26 = simde_vshl_n_s64(a, 26);
    simde_int64x1_t r39 = simde_vshl_n_s64(a, 39);
    simde_int64x1_t r52 = simde_vshl_n_s64(a, 52);
    simde_int64x1_t r63 = simde_vshl_n_s64(a, 63);

    simde_test_arm_neon_assert_equal_i64x1(r13, simde_vld1_s64(test_vec[i].r13));
    simde_test_arm_neon_assert_equal_i64x1(r26, simde_vld1_s64(test_vec[i].r26));
    simde_test_arm_neon_assert_equal_i64x1(r39, simde_vld1_s64(test_vec[i].r39));
    simde_test_arm_neon_assert_equal_i64x1(r52, simde_vld1_s64(test_vec[i].r52));
    simde_test_arm_neon_assert_equal_i64x1(r63, simde_vld1_s64(test_vec[i].r63));
  }

  return 0;
}

static int
test_simde_vshl_n_u8 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    uint8_t a[8];
    uint8_t r1[8];
    uint8_t r3[8];
    uint8_t r5[8];
    uint8_t r6[8];
    uint8_t r7[8];
  } test_vec[] = {
    { { UINT8_C(132), UINT8_C(230), UINT8_C(170), UINT8_C(137), UINT8_C(  6), UINT8_C(148), UINT8_C( 45), UINT8_C( 13) },
      { UINT8_C(  8), UINT8_C(204), UINT8_C( 84), UINT8_C( 18), UINT8_C( 12), UINT8_C( 40), UINT8_C( 90), UINT8_C( 26) },
      { UINT8_C( 32), UINT8_C( 48), UINT8_C( 80), UINT8_C( 72), UINT8_C( 48), UINT8_C(160), UINT8_C(104), UINT8_C(104) },
      { UINT8_C(128), UINT8_C(192), UINT8_C( 64), UINT8_C( 32), UINT8_C(192), UINT8_C(128), UINT8_C(160), UINT8_C(160) },
      { UINT8_C(  0), UINT8_C(128), UINT8_C(128), UINT8_C( 64), UINT8_C(128), UINT8_C(  0), UINT8_C( 64), UINT8_C( 64) },
      { UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(128), UINT8_C(  0), UINT8_C(  0), UINT8_C(128), UINT8_C(128) } },
    { { UINT8_C( 64), UINT8_C( 29), UINT8_C( 42), UINT8_C( 83), UINT8_C(183), UINT8_C(157), UINT8_C(126), UINT8_C( 88) },
      { UINT8_C(128), UINT8_C( 58), UINT8_C( 84), UINT8_C(166), UINT8_C(110), UINT8_C( 58), UINT8_C(252), UINT8_C(176) },
      { UINT8_C(  0), UINT8_C(232), UINT8_C( 80), UINT8_C(152), UINT8_C(184), UINT8_C(232), UINT8_C(240), UINT8_C(192) },
      { UINT8_C(  0), UINT8_C(160), UINT8_C( 64), UINT8_C( 96), UINT8_C(224), UINT8_C(160), UINT8_C(192), UINT8_C(  0) },
      { UINT8_C(  0), UINT8_C( 64), UINT8_C(128), UINT8_C(192), UINT8_C(192), UINT8_C( 64), UINT8_C(128), UINT8_C(  0) },
      { UINT8_C(  0), UINT8_C(128), UINT8_C(  0), UINT8_C(128), UINT8_C(128), UINT8_C(128), UINT8_C(  0), UINT8_C(  0) } },
    { { UINT8_C(251), UINT8_C(190), UINT8_C( 95), UINT8_C(143), UINT8_C(141), UINT8_C( 17), UINT8_C( 26), UINT8_C(234) },
      { UINT8_C(246), UINT8_C(124), UINT8_C(190), UINT8_C( 30), UINT8_C( 26), UINT8_C( 34), UINT8_C( 52), UINT8_C(212) },
      { UINT8_C(216), UINT8_C(240), UINT8_C(248), UINT8_C(120), UINT8_C(104), UINT8_C(136), UINT8_C(208), UINT8_C( 80) },
      { UINT8_C( 96), UINT8_C(192), UINT8_C(224), UINT8_C(224), UINT8_C(160), UINT8_C( 32), UINT8_C( 64), UINT8_C( 64) },
      { UINT8_C(192), UINT8_C(128), UINT8_C(192), UINT8_C(192), UINT8_C( 64), UINT8_C( 64), UINT8_C(128), UINT8_C(128) },
      { UINT8_C(128), UINT8_C(  0), UINT8_C(128), UINT8_C(128), UINT8_C(128), UINT8_C(128), UINT8_C(  0), UINT8_C(  0) } },
    { { UINT8_C(  6), UINT8_C( 50), UINT8_C(  2), UINT8_C( 36), UINT8_C(  3), UINT8_C(123), UINT8_C(190), UINT8_C(136) },
      { UINT8_C( 12), UINT8_C(100), UINT8_C(  4), UINT8_C( 72), UINT8_C(  6), UINT8_C(246), UINT8_C(124), UINT8_C( 16) },
      { UINT8_C( 48), UINT8_C(144), UINT8_C( 16), UINT8_C( 32), UINT8_C( 24), UINT8_C(216), UINT8_C(240), UINT8_C( 64) },
      { UINT8_C(192), UINT8_C( 64), UINT8_C( 64), UINT8_C(128), UINT8_C( 96), UINT8_C( 96), UINT8_C(192), UINT8_C(  0) },
      { UINT8_C(128), UINT8_C(128), UINT8_C(128), UINT8_C(  0), UINT8_C(192), UINT8_C(192), UINT8_C(128), UINT8_C(  0) },
      { UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(128), UINT8_C(128), UINT8_C(  0), UINT8_C(  0) } },
    { { UINT8_C( 97), UINT8_C(104), UINT8_C( 17), UINT8_C(104), UINT8_C(252), UINT8_C( 62), UINT8_C(117), UINT8_C( 60) },
      { UINT8_C(194), UINT8_C(208), UINT8_C( 34), UINT8_C(208), UINT8_C(248), UINT8_C(124), UINT8_C(234), UINT8_C(120) },
      { UINT8_C(  8), UINT8_C( 64), UINT8_C(136), UINT8_C( 64), UINT8_C(224), UINT8_C(240), UINT8_C(168), UINT8_C(224) },
      { UINT8_C( 32), UINT8_C(  0), UINT8_C( 32), UINT8_C(  0), UINT8_C(128), UINT8_C(192), UINT8_C(160), UINT8_C(128) },
      { UINT8_C( 64), UINT8_C(  0), UINT8_C( 64), UINT8_C(  0), UINT8_C(  0), UINT8_C(128), UINT8_C( 64), UINT8_C(  0) },
      { UINT8_C(128), UINT8_C(  0), UINT8_C(128), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(128), UINT8_C(  0) } },
    { { UINT8_C( 91), UINT8_C(160), UINT8_C(144), UINT8_C( 18), UINT8_C( 61), UINT8_C( 14), UINT8_C(106), UINT8_C( 57) },
      { UINT8_C(182), UINT8_C( 64), UINT8_C( 32), UINT8_C( 36), UINT8_C(122), UINT8_C( 28), UINT8_C(212), UINT8_C(114) },
      { UINT8_C(216), UINT8_C(  0), UINT8_C(128), UINT8_C(144), UINT8_C(232), UINT8_C(112), UINT8_C( 80), UINT8_C(200) },
      { UINT8_C( 96), UINT8_C(  0), UINT8_C(  0), UINT8_C( 64), UINT8_C(160), UINT8_C(192), UINT8_C( 64), UINT8_C( 32) },
      { UINT8_C(192), UINT8_C(  0), UINT8_C(  0), UINT8_C(128), UINT8_C( 64), UINT8_C(128), UINT8_C(128), UINT8_C( 64) },
      { UINT8_C(128), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(128), UINT8_C(  0), UINT8_C(  0), UINT8_C(128) } },
    { { UINT8_C(204), UINT8_C(201), UINT8_C(200), UINT8_C( 90), UINT8_C(219), UINT8_C(226), UINT8_C( 68), UINT8_C(225) },
      { UINT8_C(152), UINT8_C(146), UINT8_C(144), UINT8_C(180), UINT8_C(182), UINT8_C(196), UINT8_C(136), UINT8_C(194) },
      { UINT8_C( 96), UINT8_C( 72), UINT8_C( 64), UINT8_C(208), UINT8_C(216), UINT8_C( 16), UINT8_C( 32), UINT8_C(  8) },
      { UINT8_C(128), UINT8_C( 32), UINT8_C(  0), UINT8_C( 64), UINT8_C( 96), UINT8_C( 64), UINT8_C(128), UINT8_C( 32) },
      { UINT8_C(  0), UINT8_C( 64), UINT8_C(  0), UINT8_C(128), UINT8_C(192), UINT8_C(128), UINT8_C(  0), UINT8_C( 64) },
      { UINT8_C(  0), UINT8_C(128), UINT8_C(  0), UINT8_C(  0), UINT8_C(128), UINT8_C(  0), UINT8_C(  0), UINT8_C(128) } },
    { { UINT8_C( 20), UINT8_C( 70), UINT8_C(  5), UINT8_C( 23), UINT8_C(194), UINT8_C(195), UINT8_C(159), UINT8_C( 35) },
      { UINT8_C( 40), UINT8_C(140), UINT8_C( 10), UINT8_C( 46), UINT8_C(132), UINT8_C(134), UINT8_C( 62), UINT8_C( 70) },
      { UINT8_C(160), UINT8_C( 48), UINT8_C( 40), UINT8_C(184), UINT8_C( 16), UINT8_C( 24), UINT8_C(248), UINT8_C( 24) },
      { UINT8_C(128), UINT8_C(192), UINT8_C(160), UINT8_C(224), UINT8_C( 64), UINT8_C( 96), UINT8_C(224), UINT8_C( 96) },
      { UINT8_C(  0), UINT8_C(128), UINT8_C( 64), UINT8_C(192), UINT8_C(128), UINT8_C(192), UINT8_C(192), UINT8_C(192) },
      { UINT8_C(  0), UINT8_C(  0), UINT8_C(128), UINT8_C(128), UINT8_C(  0), UINT8_C(128), UINT8_C(128), UINT8_C(128) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint8x8_t a = simde_vld1_u8(test_vec[i].a);

    simde_uint8x8_t r1 = simde_vshl_n_u8(a, 1);
    simde_uint8x8_t r3 = simde_vshl_n_u8(a, 3);
    simde_uint8x8_t r5 = simde_vshl_n_u8(a, 5);
    simde_uint8x8_t r6 = simde_vshl_n_u8(a, 6);
    simde_uint8x8_t r7 = simde_vshl_n_u8(a, 7);

    simde_test_arm_neon_assert_equal_u8x8(r1, simde_vld1_u8(test_vec[i].r1));
    simde_test_arm_neon_assert_equal_u8x8(r3, simde_vld1_u8(test_vec[i].r3));
    simde_test_arm_neon_assert_equal_u8x8(r5, simde_vld1_u8(test_vec[i].r5));
    simde_test_arm_neon_assert_equal_u8x8(r6, simde_vld1_u8(test_vec[i].r6));
    simde_test_arm_neon_assert_equal_u8x8(r7, simde_vld1_u8(test_vec[i].r7));
  }

  return 0;
}

static int
test_simde_vshl_n_u16 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    uint16_t a[4];
    uint16_t r3[4];
    uint16_t r6[4];
    uint16_t r10[4];
    uint16_t r13[4];
    uint16_t r15[4];
  } test_vec[] = {
    { { UINT16_C(12081), UINT16_C(51160), UINT16_C(44606), UINT16_C(13550) },
      { UINT16_C(31112), UINT16_C(16064), UINT16_C(29168), UINT16_C(42864) },
      { UINT16_C(52288), UINT16_C(62976), UINT16_C(36736), UINT16_C(15232) },
      { UINT16_C(50176), UINT16_C(24576), UINT16_C(63488), UINT16_C(47104) },
      { UINT16_C( 8192), UINT16_C(    0), UINT16_C(49152), UINT16_C(49152) },
      { UINT16_C(32768), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0) } },
    { { UINT16_C(47809), UINT16_C(24193), UINT16_C(31527), UINT16_C(28814) },
      { UINT16_C(54792), UINT16_C(62472), UINT16_C(55608), UINT16_C(33904) },
      { UINT16_C(45120), UINT16_C(41024), UINT16_C(51648), UINT16_C( 9088) },
      { UINT16_C( 1024), UINT16_C( 1024), UINT16_C(39936), UINT16_C(14336) },
      { UINT16_C( 8192), UINT16_C( 8192), UINT16_C(57344), UINT16_C(49152) },
      { UINT16_C(32768), UINT16_C(32768), UINT16_C(32768), UINT16_C(    0) } },
    { { UINT16_C(53303), UINT16_C(53033), UINT16_C(  960), UINT16_C(31544) },
      { UINT16_C(33208), UINT16_C(31048), UINT16_C( 7680), UINT16_C(55744) },
      { UINT16_C( 3520), UINT16_C(51776), UINT16_C(61440), UINT16_C(52736) },
      { UINT16_C(56320), UINT16_C(41984), UINT16_C(    0), UINT16_C(57344) },
      { UINT16_C(57344), UINT16_C( 8192), UINT16_C(    0), UINT16_C(    0) },
      { UINT16_C(32768), UINT16_C(32768), UINT16_C(    0), UINT16_C(    0) } },
    { { UINT16_C(64480), UINT16_C(18150), UINT16_C(24610), UINT16_C(21645) },
      { UINT16_C(57088), UINT16_C(14128), UINT16_C(  272), UINT16_C(42088) },
      { UINT16_C(63488), UINT16_C(47488), UINT16_C( 2176), UINT16_C( 9024) },
      { UINT16_C(32768), UINT16_C(38912), UINT16_C(34816), UINT16_C(13312) },
      { UINT16_C(    0), UINT16_C(49152), UINT16_C(16384), UINT16_C(40960) },
      { UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(32768) } },
    { { UINT16_C(25999), UINT16_C(52507), UINT16_C( 2323), UINT16_C(54273) },
      { UINT16_C(11384), UINT16_C(26840), UINT16_C(18584), UINT16_C(40968) },
      { UINT16_C(25536), UINT16_C(18112), UINT16_C(17600), UINT16_C(   64) },
      { UINT16_C(15360), UINT16_C(27648), UINT16_C(19456), UINT16_C( 1024) },
      { UINT16_C(57344), UINT16_C(24576), UINT16_C(24576), UINT16_C( 8192) },
      { UINT16_C(32768), UINT16_C(32768), UINT16_C(32768), UINT16_C(32768) } },
    { { UINT16_C(33731), UINT16_C(60211), UINT16_C(49662), UINT16_C(13659) },
      { UINT16_C( 7704), UINT16_C(22936), UINT16_C( 4080), UINT16_C(43736) },
      { UINT16_C(61632), UINT16_C(52416), UINT16_C(32640), UINT16_C(22208) },
      { UINT16_C( 3072), UINT16_C(52224), UINT16_C(63488), UINT16_C(27648) },
      { UINT16_C(24576), UINT16_C(24576), UINT16_C(49152), UINT16_C(24576) },
      { UINT16_C(32768), UINT16_C(32768), UINT16_C(    0), UINT16_C(32768) } },
    { { UINT16_C(34193), UINT16_C(20740), UINT16_C(15496), UINT16_C(26829) },
      { UINT16_C(11400), UINT16_C(34848), UINT16_C(58432), UINT16_C(18024) },
      { UINT16_C(25664), UINT16_C(16640), UINT16_C( 8704), UINT16_C(13120) },
      { UINT16_C(17408), UINT16_C( 4096), UINT16_C( 8192), UINT16_C(13312) },
      { UINT16_C( 8192), UINT16_C(32768), UINT16_C(    0), UINT16_C(40960) },
      { UINT16_C(32768), UINT16_C(    0), UINT16_C(    0), UINT16_C(32768) } },
    { { UINT16_C(45880), UINT16_C(23215), UINT16_C(15379), UINT16_C(41646) },
      { UINT16_C(39360), UINT16_C(54648), UINT16_C(57496), UINT16_C( 5488) },
      { UINT16_C(52736), UINT16_C(43968), UINT16_C( 1216), UINT16_C(43904) },
      { UINT16_C(57344), UINT16_C(48128), UINT16_C(19456), UINT16_C(47104) },
      { UINT16_C(    0), UINT16_C(57344), UINT16_C(24576), UINT16_C(49152) },
      { UINT16_C(    0), UINT16_C(32768), UINT16_C(32768), UINT16_C(    0) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint16x4_t a = simde_vld1_u16(test_vec[i].a);

    simde_uint16x4_t r3 = simde_vshl_n_u16(a, 3);
    simde_uint16x4_t r6 = simde_vshl_n_u16(a, 6);
    simde_uint16x4_t r10 = simde_vshl_n_u16(a, 10);
    simde_uint16x4_t r13 = simde_vshl_n_u16(a, 13);
    simde_uint16x4_t r15 = simde_vshl_n_u16(a, 15);

    simde_test_arm_neon_assert_equal_u16x4(r3, simde_vld1_u16(test_vec[i].r3));
    simde_test_arm_neon_assert_equal_u16x4(r6, simde_vld1_u16(test_vec[i].r6));
    simde_test_arm_neon_assert_equal_u16x4(r10, simde_vld1_u16(test_vec[i].r10));
    simde_test_arm_neon_assert_equal_u16x4(r13, simde_vld1_u16(test_vec[i].r13));
    simde_test_arm_neon_assert_equal_u16x4(r15, simde_vld1_u16(test_vec[i].r15));
  }

  return 0;
}

static int
test_simde_vshl_n_u32 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    uint32_t a[2];
    uint32_t r6[2];
    uint32_t r13[2];
    uint32_t r19[2];
    uint32_t r26[2];
    uint32_t r31[2];
  } test_vec[] = {
    { { UINT32_C(2997814030), UINT32_C(3814135967) },
      { UINT32_C(2881536896), UINT32_C(3586533312) },
      { UINT32_C(3764502528), UINT32_C(3809730560) },
      { UINT32_C( 409993216), UINT32_C(3304587264) },
      { UINT32_C( 939524096), UINT32_C(2080374784) },
      { UINT32_C(         0), UINT32_C(2147483648) } },
    { { UINT32_C( 787617874), UINT32_C(2139507274) },
      { UINT32_C(3162903680), UINT32_C(3784479360) },
      { UINT32_C(1124745216), UINT32_C(3377020928) },
      { UINT32_C(3264217088), UINT32_C(1380974592) },
      { UINT32_C(1207959552), UINT32_C( 671088640) },
      { UINT32_C(         0), UINT32_C(         0) } },
    { { UINT32_C( 843447853), UINT32_C( 839632241) },
      { UINT32_C(2441055040), UINT32_C(2196855872) },
      { UINT32_C(3217399808), UINT32_C(2024677376) },
      { UINT32_C(4050124800), UINT32_C( 730333184) },
      { UINT32_C(3019898880), UINT32_C(3288334336) },
      { UINT32_C(2147483648), UINT32_C(2147483648) } },
    { { UINT32_C( 654285750), UINT32_C(3336382136) },
      { UINT32_C(3219582336), UINT32_C(3075059200) },
      { UINT32_C(4084645888), UINT32_C(2765553664) },
      { UINT32_C(3719299072), UINT32_C( 901775360) },
      { UINT32_C(3623878656), UINT32_C(3758096384) },
      { UINT32_C(         0), UINT32_C(         0) } },
    { { UINT32_C(3363408937), UINT32_C(4138455204) },
      { UINT32_C( 509807168), UINT32_C(2868128000) },
      { UINT32_C( 830808064), UINT32_C(2048163840) },
      { UINT32_C(1632108544), UINT32_C(2233466880) },
      { UINT32_C(2751463424), UINT32_C(2415919104) },
      { UINT32_C(2147483648), UINT32_C(         0) } },
    { { UINT32_C( 841260776), UINT32_C( 364030952) },
      { UINT32_C(2301082112), UINT32_C(1823144448) },
      { UINT32_C(2480734208), UINT32_C(1434255360) },
      { UINT32_C(4148166656), UINT32_C(1598029824) },
      { UINT32_C(2684354560), UINT32_C(2684354560) },
      { UINT32_C(         0), UINT32_C(         0) } },
    { { UINT32_C( 440924073), UINT32_C(1934381756) },
      { UINT32_C(2449336896), UINT32_C(3541348096) },
      { UINT32_C(4277477376), UINT32_C(2320990208) },
      { UINT32_C(3175612416), UINT32_C(2514485248) },
      { UINT32_C(2751463424), UINT32_C(4026531840) },
      { UINT32_C(2147483648), UINT32_C(         0) } },
    { { UINT32_C(2778287341), UINT32_C(2624353906) },
      { UINT32_C(1716730688), UINT32_C( 454925440) },
      { UINT32_C( 698195968), UINT32_C(2395881472) },
      { UINT32_C(1734868992), UINT32_C(3012558848) },
      { UINT32_C(3019898880), UINT32_C(3355443200) },
      { UINT32_C(2147483648), UINT32_C(         0) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint32x2_t a = simde_vld1_u32(test_vec[i].a);

    simde_uint32x2_t r6 = simde_vshl_n_u32(a, 6);
    simde_uint32x2_t r13 = simde_vshl_n_u32(a, 13);
    simde_uint32x2_t r19 = simde_vshl_n_u32(a, 19);
    simde_uint32x2_t r26 = simde_vshl_n_u32(a, 26);
    simde_uint32x2_t r31 = simde_vshl_n_u32(a, 31);

    simde_test_arm_neon_assert_equal_u32x2(r6, simde_vld1_u32(test_vec[i].r6));
    simde_test_arm_neon_assert_equal_u32x2(r13, simde_vld1_u32(test_vec[i].r13));
    simde_test_arm_neon_assert_equal_u32x2(r19, simde_vld1_u32(test_vec[i].r19));
    simde_test_arm_neon_assert_equal_u32x2(r26, simde_vld1_u32(test_vec[i].r26));
    simde_test_arm_neon_assert_equal_u32x2(r31, simde_vld1_u32(test_vec[i].r31));
  }

  return 0;
}

static int
test_simde_vshl_n_u64 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    uint64_t a[1];
    uint64_t r13[1];
    uint64_t r26[1];
    uint64_t r39[1];
    uint64_t r52[1];
    uint64_t r63[1];
  } test_vec[] = {
    { { UINT64_C(10695459920550031284) },
      { UINT64_C(13620063099195654144) },
      { UINT64_C( 9648750815430574080) },
      { UINT64_C(16715068235543740416) },
      { UINT64_C(18104470502029393920) },
      { UINT64_C(                   0) } },
    { { UINT64_C( 3462228061674520113) },
      { UINT64_C( 9926639946087931904) },
      { UINT64_C( 5786561440634634240) },
      { UINT64_C(13825796319085592576) },
      { UINT64_C(16361577446237011968) },
      { UINT64_C( 9223372036854775808) } },
    { { UINT64_C(16074483975084028448) },
      { UINT64_C( 9313525749581611008) },
      { UINT64_C(  669451709851893760) },
      { UINT64_C( 5465417214976851968) },
      { UINT64_C( 2449958197289549824) },
      { UINT64_C(                   0) } },
    { { UINT64_C( 7661638601150101201) },
      { UINT64_C( 8320081861734440960) },
      { UINT64_C(15838003045456674816) },
      { UINT64_C( 8969877981803577344) },
      { UINT64_C( 7858781349761515520) },
      { UINT64_C( 9223372036854775808) } },
    { { UINT64_C( 4341277672083759754) },
      { UINT64_C(16870859671853940736) },
      { UINT64_C( 3075831595521802240) },
      { UINT64_C(17406769901065994240) },
      { UINT64_C( 2927339757790822400) },
      { UINT64_C(                   0) } },
    { { UINT64_C( 3266055366270500623) },
      { UINT64_C( 7746653609091260416) },
      { UINT64_C( 3786752114747768832) },
      { UINT64_C(12096536107966005248) },
      { UINT64_C(17361376563513262080) },
      { UINT64_C( 9223372036854775808) } },
    { { UINT64_C(14335121394201783054) },
      { UINT64_C( 1341688066001190912) },
      { UINT64_C(15295912824572739584) },
      { UINT64_C(13832110264608096256) },
      { UINT64_C(12745186945458503680) },
      { UINT64_C(                   0) } },
    { { UINT64_C( 1056952299709655178) },
      { UINT64_C( 7030268651715510272) },
      { UINT64_C( 1225796732240003072) },
      { UINT64_C( 6698054412109086720) },
      { UINT64_C( 9844868785431904256) },
      { UINT64_C(                   0) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint64x1_t a = simde_vld1_u64(test_vec[i].a);

    simde_uint64x1_t r13 = simde_vshl_n_u64(a, 13);
    simde_uint64x1_t r26 = simde_vshl_n_u64(a, 26);
    simde_uint64x1_t r39 = simde_vshl_n_u64(a, 39);
    simde_uint64x1_t r52 = simde_vshl_n_u64(a, 52);
    simde_uint64x1_t r63 = simde_vshl_n_u64(a, 63);

    simde_test_arm_neon_assert_equal_u64x1(r13, simde_vld1_u64(test_vec[i].r13));
    simde_test_arm_neon_assert_equal_u64x1(r26, simde_vld1_u64(test_vec[i].r26));
    simde_test_arm_neon_assert_equal_u64x1(r39, simde_vld1_u64(test_vec[i].r39));
    simde_test_arm_neon_assert_equal_u64x1(r52, simde_vld1_u64(test_vec[i].r52));
    simde_test_arm_neon_assert_equal_u64x1(r63, simde_vld1_u64(test_vec[i].r63));
  }

  return 0;
}

static int
test_simde_vshlq_n_s8 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    int8_t a[16];
    int8_t r1[16];
    int8_t r3[16];
    int8_t r5[16];
    int8_t r6[16];
    int8_t r7[16];
  } test_vec[] = {
    { {  INT8_C( 122), -INT8_C( 111),  INT8_C(  30),  INT8_C(  69), -INT8_C(  48), -INT8_C(  44), -INT8_C(  67),  INT8_C(  98),
        -INT8_C( 116),  INT8_C( 119), -INT8_C( 109), -INT8_C(  89),  INT8_C(  71), -INT8_C( 122),  INT8_C(  32),  INT8_C(  41) },
      { -INT8_C(  12),  INT8_C(  34),  INT8_C(  60), -INT8_C( 118), -INT8_C(  96), -INT8_C(  88),  INT8_C( 122), -INT8_C(  60),
         INT8_C(  24), -INT8_C(  18),  INT8_C(  38),  INT8_C(  78), -INT8_C( 114),  INT8_C(  12),  INT8_C(  64),  INT8_C(  82) },
      { -INT8_C(  48), -INT8_C( 120), -INT8_C(  16),  INT8_C(  40),      INT8_MIN, -INT8_C(  96), -INT8_C(  24),  INT8_C(  16),
         INT8_C(  96), -INT8_C(  72), -INT8_C( 104),  INT8_C(  56),  INT8_C(  56),  INT8_C(  48),  INT8_C(   0),  INT8_C(  72) },
      {  INT8_C(  64),  INT8_C(  32), -INT8_C(  64), -INT8_C(  96),  INT8_C(   0),      INT8_MIN, -INT8_C(  96),  INT8_C(  64),
             INT8_MIN, -INT8_C(  32),  INT8_C(  96), -INT8_C(  32), -INT8_C(  32), -INT8_C(  64),  INT8_C(   0),  INT8_C(  32) },
      {      INT8_MIN,  INT8_C(  64),      INT8_MIN,  INT8_C(  64),  INT8_C(   0),  INT8_C(   0),  INT8_C(  64),      INT8_MIN,
         INT8_C(   0), -INT8_C(  64), -INT8_C(  64), -INT8_C(  64), -INT8_C(  64),      INT8_MIN,  INT8_C(   0),  INT8_C(  64) },
      {  INT8_C(   0),      INT8_MIN,  INT8_C(   0),      INT8_MIN,  INT8_C(   0),  INT8_C(   0),      INT8_MIN,  INT8_C(   0),
         INT8_C(   0),      INT8_MIN,      INT8_MIN,      INT8_MIN,      INT8_MIN,  INT8_C(   0),  INT8_C(   0),      INT8_MIN } },
    { {  INT8_C( 100), -INT8_C(  96),  INT8_C(  79), -INT8_C(  90),  INT8_C(  47),  INT8_C(  78), -INT8_C(  14), -INT8_C(  62),
        -INT8_C( 112),  INT8_C(  52),  INT8_C(   8), -INT8_C( 107), -INT8_C(  10),  INT8_C(  96),  INT8_C(  94),  INT8_C( 113) },
      { -INT8_C(  56),  INT8_C(  64), -INT8_C(  98),  INT8_C(  76),  INT8_C(  94), -INT8_C( 100), -INT8_C(  28), -INT8_C( 124),
         INT8_C(  32),  INT8_C( 104),  INT8_C(  16),  INT8_C(  42), -INT8_C(  20), -INT8_C(  64), -INT8_C(  68), -INT8_C(  30) },
      {  INT8_C(  32),  INT8_C(   0),  INT8_C( 120),  INT8_C(  48),  INT8_C( 120),  INT8_C( 112), -INT8_C( 112),  INT8_C(  16),
             INT8_MIN, -INT8_C(  96),  INT8_C(  64), -INT8_C(  88), -INT8_C(  80),  INT8_C(   0), -INT8_C(  16), -INT8_C( 120) },
      {      INT8_MIN,  INT8_C(   0), -INT8_C(  32), -INT8_C(  64), -INT8_C(  32), -INT8_C(  64),  INT8_C(  64),  INT8_C(  64),
         INT8_C(   0),      INT8_MIN,  INT8_C(   0), -INT8_C(  96), -INT8_C(  64),  INT8_C(   0), -INT8_C(  64),  INT8_C(  32) },
      {  INT8_C(   0),  INT8_C(   0), -INT8_C(  64),      INT8_MIN, -INT8_C(  64),      INT8_MIN,      INT8_MIN,      INT8_MIN,
         INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(  64),      INT8_MIN,  INT8_C(   0),      INT8_MIN,  INT8_C(  64) },
      {  INT8_C(   0),  INT8_C(   0),      INT8_MIN,  INT8_C(   0),      INT8_MIN,  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
         INT8_C(   0),  INT8_C(   0),  INT8_C(   0),      INT8_MIN,  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),      INT8_MIN } },
    { { -INT8_C(  15),  INT8_C( 124), -INT8_C(  74), -INT8_C(  63),  INT8_C(  80),  INT8_C( 115),  INT8_C(  36), -INT8_C(  35),
        -INT8_C(  21), -INT8_C(  73), -INT8_C( 124),  INT8_C(  50),  INT8_C(  62), -INT8_C(  92),  INT8_C(  92), -INT8_C(  94) },
      { -INT8_C(  30), -INT8_C(   8),  INT8_C( 108), -INT8_C( 126), -INT8_C(  96), -INT8_C(  26),  INT8_C(  72), -INT8_C(  70),
        -INT8_C(  42),  INT8_C( 110),  INT8_C(   8),  INT8_C( 100),  INT8_C( 124),  INT8_C(  72), -INT8_C(  72),  INT8_C(  68) },
      { -INT8_C( 120), -INT8_C(  32), -INT8_C(  80),  INT8_C(   8),      INT8_MIN, -INT8_C( 104),  INT8_C(  32), -INT8_C(  24),
         INT8_C(  88), -INT8_C(  72),  INT8_C(  32), -INT8_C( 112), -INT8_C(  16),  INT8_C(  32), -INT8_C(  32),  INT8_C(  16) },
      {  INT8_C(  32),      INT8_MIN, -INT8_C(  64),  INT8_C(  32),  INT8_C(   0),  INT8_C(  96),      INT8_MIN, -INT8_C(  96),
         INT8_C(  96), -INT8_C(  32),      INT8_MIN,  INT8_C(  64), -INT8_C(  64),      INT8_MIN,      INT8_MIN,  INT8_C(  64) },
      {  INT8_C(  64),  INT8_C(   0),      INT8_MIN,  INT8_C(  64),  INT8_C(   0), -INT8_C(  64),  INT8_C(   0),  INT8_C(  64),
        -INT8_C(  64), -INT8_C(  64),  INT8_C(   0),      INT8_MIN,      INT8_MIN,  INT8_C(   0),  INT8_C(   0),      INT8_MIN },
      {      INT8_MIN,  INT8_C(   0),  INT8_C(   0),      INT8_MIN,  INT8_C(   0),      INT8_MIN,  INT8_C(   0),      INT8_MIN,
             INT8_MIN,      INT8_MIN,  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0) } },
    { {  INT8_C(  68), -INT8_C(  85),  INT8_C(  72),  INT8_C( 116), -INT8_C(   7),  INT8_C(  59),  INT8_C(  54), -INT8_C( 119),
         INT8_C( 111),  INT8_C(  62),  INT8_C(  31),  INT8_C( 101), -INT8_C(  98),  INT8_C( 125), -INT8_C(  42), -INT8_C( 112) },
      { -INT8_C( 120),  INT8_C(  86), -INT8_C( 112), -INT8_C(  24), -INT8_C(  14),  INT8_C( 118),  INT8_C( 108),  INT8_C(  18),
        -INT8_C(  34),  INT8_C( 124),  INT8_C(  62), -INT8_C(  54),  INT8_C(  60), -INT8_C(   6), -INT8_C(  84),  INT8_C(  32) },
      {  INT8_C(  32),  INT8_C(  88),  INT8_C(  64), -INT8_C(  96), -INT8_C(  56), -INT8_C(  40), -INT8_C(  80),  INT8_C(  72),
         INT8_C( 120), -INT8_C(  16), -INT8_C(   8),  INT8_C(  40), -INT8_C(  16), -INT8_C(  24), -INT8_C(  80),      INT8_MIN },
      {      INT8_MIN,  INT8_C(  96),  INT8_C(   0),      INT8_MIN,  INT8_C(  32),  INT8_C(  96), -INT8_C(  64),  INT8_C(  32),
        -INT8_C(  32), -INT8_C(  64), -INT8_C(  32), -INT8_C(  96), -INT8_C(  64), -INT8_C(  96), -INT8_C(  64),  INT8_C(   0) },
      {  INT8_C(   0), -INT8_C(  64),  INT8_C(   0),  INT8_C(   0),  INT8_C(  64), -INT8_C(  64),      INT8_MIN,  INT8_C(  64),
        -INT8_C(  64),      INT8_MIN, -INT8_C(  64),  INT8_C(  64),      INT8_MIN,  INT8_C(  64),      INT8_MIN,  INT8_C(   0) },
      {  INT8_C(   0),      INT8_MIN,  INT8_C(   0),  INT8_C(   0),      INT8_MIN,      INT8_MIN,  INT8_C(   0),      INT8_MIN,
             INT8_MIN,  INT8_C(   0),      INT8_MIN,      INT8_MIN,  INT8_C(   0),      INT8_MIN,  INT8_C(   0),  INT8_C(   0) } },
    { { -INT8_C(   7), -INT8_C( 115),  INT8_C(  81),  INT8_C(  73),  INT8_C(   0),  INT8_C( 117),  INT8_C(  38), -INT8_C(  21),
         INT8_C(  45), -INT8_C(  85),  INT8_C(  30),  INT8_C( 107),  INT8_C(  79),  INT8_C( 122),  INT8_C(  13), -INT8_C( 108) },
      { -INT8_C(  14),  INT8_C(  26), -INT8_C(  94), -INT8_C( 110),  INT8_C(   0), -INT8_C(  22),  INT8_C(  76), -INT8_C(  42),
         INT8_C(  90),  INT8_C(  86),  INT8_C(  60), -INT8_C(  42), -INT8_C(  98), -INT8_C(  12),  INT8_C(  26),  INT8_C(  40) },
      { -INT8_C(  56),  INT8_C( 104), -INT8_C( 120),  INT8_C(  72),  INT8_C(   0), -INT8_C(  88),  INT8_C(  48),  INT8_C(  88),
         INT8_C( 104),  INT8_C(  88), -INT8_C(  16),  INT8_C(  88),  INT8_C( 120), -INT8_C(  48),  INT8_C( 104), -INT8_C(  96) },
      {  INT8_C(  32), -INT8_C(  96),  INT8_C(  32),  INT8_C(  32),  INT8_C(   0), -INT8_C(  96), -INT8_C(  64),  INT8_C(  96),
        -INT8_C(  96),  INT8_C(  96), -INT8_C(  64),  INT8_C(  96), -INT8_C(  32),  INT8_C(  64), -INT8_C(  96),      INT8_MIN },
      {  INT8_C(  64),  INT8_C(  64),  INT8_C(  64),  INT8_C(  64),  INT8_C(   0),  INT8_C(  64),      INT8_MIN, -INT8_C(  64),
         INT8_C(  64), -INT8_C(  64),      INT8_MIN, -INT8_C(  64), -INT8_C(  64),      INT8_MIN,  INT8_C(  64),  INT8_C(   0) },
      {      INT8_MIN,      INT8_MIN,      INT8_MIN,      INT8_MIN,  INT8_C(   0),      INT8_MIN,  INT8_C(   0),      INT8_MIN,
             INT8_MIN,      INT8_MIN,  INT8_C(   0),      INT8_MIN,      INT8_MIN,  INT8_C(   0),      INT8_MIN,  INT8_C(   0) } },
    { {  INT8_C(  37),  INT8_C(  86),  INT8_C(   8),  INT8_C(  30), -INT8_C( 111),  INT8_C(  62), -INT8_C(  88),  INT8_C(   0),
         INT8_C( 125), -INT8_C(  57),  INT8_C( 101),  INT8_C(  27),  INT8_C(  68),  INT8_C(  60), -INT8_C(  85),  INT8_C(  61) },
      {  INT8_C(  74), -INT8_C(  84),  INT8_C(  16),  INT8_C(  60),  INT8_C(  34),  INT8_C( 124),  INT8_C(  80),  INT8_C(   0),
        -INT8_C(   6), -INT8_C( 114), -INT8_C(  54),  INT8_C(  54), -INT8_C( 120),  INT8_C( 120),  INT8_C(  86),  INT8_C( 122) },
      {  INT8_C(  40), -INT8_C(  80),  INT8_C(  64), -INT8_C(  16), -INT8_C( 120), -INT8_C(  16),  INT8_C(  64),  INT8_C(   0),
        -INT8_C(  24),  INT8_C(  56),  INT8_C(  40), -INT8_C(  40),  INT8_C(  32), -INT8_C(  32),  INT8_C(  88), -INT8_C(  24) },
      { -INT8_C(  96), -INT8_C(  64),  INT8_C(   0), -INT8_C(  64),  INT8_C(  32), -INT8_C(  64),  INT8_C(   0),  INT8_C(   0),
        -INT8_C(  96), -INT8_C(  32), -INT8_C(  96),  INT8_C(  96),      INT8_MIN,      INT8_MIN,  INT8_C(  96), -INT8_C(  96) },
      {  INT8_C(  64),      INT8_MIN,  INT8_C(   0),      INT8_MIN,  INT8_C(  64),      INT8_MIN,  INT8_C(   0),  INT8_C(   0),
         INT8_C(  64), -INT8_C(  64),  INT8_C(  64), -INT8_C(  64),  INT8_C(   0),  INT8_C(   0), -INT8_C(  64),  INT8_C(  64) },
      {      INT8_MIN,  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),      INT8_MIN,  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
             INT8_MIN,      INT8_MIN,      INT8_MIN,      INT8_MIN,  INT8_C(   0),  INT8_C(   0),      INT8_MIN,      INT8_MIN } },
    { { -INT8_C(  55), -INT8_C(   3), -INT8_C( 122), -INT8_C(  55),  INT8_C( 114), -INT8_C(  83), -INT8_C(  75), -INT8_C(  97),
         INT8_C(  88), -INT8_C(  45),  INT8_C(  10), -INT8_C(  89),  INT8_C(  77),  INT8_C(  24),  INT8_C(  59),  INT8_C( 114) },
      { -INT8_C( 110), -INT8_C(   6),  INT8_C(  12), -INT8_C( 110), -INT8_C(  28),  INT8_C(  90),  INT8_C( 106),  INT8_C(  62),
        -INT8_C(  80), -INT8_C(  90),  INT8_C(  20),  INT8_C(  78), -INT8_C( 102),  INT8_C(  48),  INT8_C( 118), -INT8_C(  28) },
      {  INT8_C(  72), -INT8_C(  24),  INT8_C(  48),  INT8_C(  72), -INT8_C( 112),  INT8_C( 104), -INT8_C(  88), -INT8_C(   8),
        -INT8_C(  64), -INT8_C( 104),  INT8_C(  80),  INT8_C(  56),  INT8_C( 104), -INT8_C(  64), -INT8_C(  40), -INT8_C( 112) },
      {  INT8_C(  32), -INT8_C(  96), -INT8_C(  64),  INT8_C(  32),  INT8_C(  64), -INT8_C(  96), -INT8_C(  96), -INT8_C(  32),
         INT8_C(   0),  INT8_C(  96),  INT8_C(  64), -INT8_C(  32), -INT8_C(  96),  INT8_C(   0),  INT8_C(  96),  INT8_C(  64) },
      {  INT8_C(  64),  INT8_C(  64),      INT8_MIN,  INT8_C(  64),      INT8_MIN,  INT8_C(  64),  INT8_C(  64), -INT8_C(  64),
         INT8_C(   0), -INT8_C(  64),      INT8_MIN, -INT8_C(  64),  INT8_C(  64),  INT8_C(   0), -INT8_C(  64),      INT8_MIN },
      {      INT8_MIN,      INT8_MIN,  INT8_C(   0),      INT8_MIN,  INT8_C(   0),      INT8_MIN,      INT8_MIN,      INT8_MIN,
         INT8_C(   0),      INT8_MIN,  INT8_C(   0),      INT8_MIN,      INT8_MIN,  INT8_C(   0),      INT8_MIN,  INT8_C(   0) } },
    { {  INT8_C( 110),  INT8_C(  67), -INT8_C( 112), -INT8_C(   1), -INT8_C( 126),  INT8_C(  56), -INT8_C(   1), -INT8_C(   1),
        -INT8_C(   1),  INT8_C( 100),  INT8_C(  26),  INT8_C(  67), -INT8_C(  96), -INT8_C(  58),      INT8_MIN,  INT8_C( 105) },
      { -INT8_C(  36), -INT8_C( 122),  INT8_C(  32), -INT8_C(   2),  INT8_C(   4),  INT8_C( 112), -INT8_C(   2), -INT8_C(   2),
        -INT8_C(   2), -INT8_C(  56),  INT8_C(  52), -INT8_C( 122),  INT8_C(  64), -INT8_C( 116),  INT8_C(   0), -INT8_C(  46) },
      {  INT8_C( 112),  INT8_C(  24),      INT8_MIN, -INT8_C(   8),  INT8_C(  16), -INT8_C(  64), -INT8_C(   8), -INT8_C(   8),
        -INT8_C(   8),  INT8_C(  32), -INT8_C(  48),  INT8_C(  24),  INT8_C(   0),  INT8_C(  48),  INT8_C(   0),  INT8_C(  72) },
      { -INT8_C(  64),  INT8_C(  96),  INT8_C(   0), -INT8_C(  32),  INT8_C(  64),  INT8_C(   0), -INT8_C(  32), -INT8_C(  32),
        -INT8_C(  32),      INT8_MIN,  INT8_C(  64),  INT8_C(  96),  INT8_C(   0), -INT8_C(  64),  INT8_C(   0),  INT8_C(  32) },
      {      INT8_MIN, -INT8_C(  64),  INT8_C(   0), -INT8_C(  64),      INT8_MIN,  INT8_C(   0), -INT8_C(  64), -INT8_C(  64),
        -INT8_C(  64),  INT8_C(   0),      INT8_MIN, -INT8_C(  64),  INT8_C(   0),      INT8_MIN,  INT8_C(   0),  INT8_C(  64) },
      {  INT8_C(   0),      INT8_MIN,  INT8_C(   0),      INT8_MIN,  INT8_C(   0),  INT8_C(   0),      INT8_MIN,      INT8_MIN,
             INT8_MIN,  INT8_C(   0),  INT8_C(   0),      INT8_MIN,  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),      INT8_MIN } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int8x16_t a = simde_vld1q_s8(test_vec[i].a);

    simde_int8x16_t r1 = simde_vshlq_n_s8(a, 1);
    simde_int8x16_t r3 = simde_vshlq_n_s8(a, 3);
    simde_int8x16_t r5 = simde_vshlq_n_s8(a, 5);
    simde_int8x16_t r6 = simde_vshlq_n_s8(a, 6);
    simde_int8x16_t r7 = simde_vshlq_n_s8(a, 7);

    simde_test_arm_neon_assert_equal_i8x16(r1, simde_vld1q_s8(test_vec[i].r1));
    simde_test_arm_neon_assert_equal_i8x16(r3, simde_vld1q_s8(test_vec[i].r3));
    simde_test_arm_neon_assert_equal_i8x16(r5, simde_vld1q_s8(test_vec[i].r5));
    simde_test_arm_neon_assert_equal_i8x16(r6, simde_vld1q_s8(test_vec[i].r6));
    simde_test_arm_neon_assert_equal_i8x16(r7, simde_vld1q_s8(test_vec[i].r7));
  }

  return 0;
}

static int
test_simde_vshlq_n_s16 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    int16_t a[8];
    int16_t r3[8];
    int16_t r6[8];
    int16_t r10[8];
    int16_t r13[8];
    int16_t r15[8];
  } test_vec[] = {
    { {  INT16_C( 15177),  INT16_C( 24595), -INT16_C( 14772), -INT16_C(  6844),  INT16_C( 20381),  INT16_C(  7805), -INT16_C( 16411), -INT16_C(  7709) },
      { -INT16_C(  9656),  INT16_C(   152),  INT16_C( 12896),  INT16_C( 10784),  INT16_C( 31976), -INT16_C(  3096), -INT16_C(   216),  INT16_C(  3864) },
      { -INT16_C( 11712),  INT16_C(  1216), -INT16_C( 27904),  INT16_C( 20736), -INT16_C(  6336), -INT16_C( 24768), -INT16_C(  1728),  INT16_C( 30912) },
      {  INT16_C(  9216),  INT16_C( 19456),  INT16_C( 12288),  INT16_C(  4096),  INT16_C( 29696), -INT16_C(  3072), -INT16_C( 27648), -INT16_C( 29696) },
      {  INT16_C(  8192),  INT16_C( 24576),       INT16_MIN,       INT16_MIN, -INT16_C( 24576), -INT16_C( 24576), -INT16_C( 24576),  INT16_C( 24576) },
      {       INT16_MIN,       INT16_MIN,  INT16_C(     0),  INT16_C(     0),       INT16_MIN,       INT16_MIN,       INT16_MIN,       INT16_MIN } },
    { {  INT16_C( 13395),  INT16_C( 32618), -INT16_C(  6463), -INT16_C( 11506),  INT16_C( 27627), -INT16_C(  6770),  INT16_C(  1102), -INT16_C( 26764) },
      { -INT16_C( 23912), -INT16_C(  1200),  INT16_C( 13832), -INT16_C( 26512),  INT16_C( 24408),  INT16_C( 11376),  INT16_C(  8816), -INT16_C( 17504) },
      {  INT16_C(  5312), -INT16_C(  9600), -INT16_C( 20416), -INT16_C( 15488), -INT16_C(  1344),  INT16_C( 25472),  INT16_C(  4992), -INT16_C(  8960) },
      {  INT16_C( 19456), -INT16_C( 22528),  INT16_C(  1024),  INT16_C( 14336), -INT16_C( 21504),  INT16_C( 14336),  INT16_C( 14336), -INT16_C( 12288) },
      {  INT16_C( 24576),  INT16_C( 16384),  INT16_C(  8192), -INT16_C( 16384),  INT16_C( 24576), -INT16_C( 16384), -INT16_C( 16384),       INT16_MIN },
      {       INT16_MIN,  INT16_C(     0),       INT16_MIN,  INT16_C(     0),       INT16_MIN,  INT16_C(     0),  INT16_C(     0),  INT16_C(     0) } },
    { { -INT16_C( 30912), -INT16_C( 29449),  INT16_C( 15438), -INT16_C(  5263), -INT16_C(  4213),  INT16_C( 28681), -INT16_C(  4946),  INT16_C(   337) },
      {  INT16_C( 14848),  INT16_C( 26552), -INT16_C(  7568),  INT16_C( 23432),  INT16_C( 31832), -INT16_C( 32696),  INT16_C( 25968),  INT16_C(  2696) },
      { -INT16_C( 12288),  INT16_C( 15808),  INT16_C(  4992), -INT16_C(  9152), -INT16_C(  7488),  INT16_C(   576),  INT16_C( 11136),  INT16_C( 21568) },
      {  INT16_C(     0), -INT16_C(  9216),  INT16_C( 14336), -INT16_C( 15360),  INT16_C( 11264),  INT16_C(  9216), -INT16_C( 18432),  INT16_C( 17408) },
      {  INT16_C(     0), -INT16_C(  8192), -INT16_C( 16384),  INT16_C(  8192),  INT16_C( 24576),  INT16_C(  8192), -INT16_C( 16384),  INT16_C(  8192) },
      {  INT16_C(     0),       INT16_MIN,  INT16_C(     0),       INT16_MIN,       INT16_MIN,       INT16_MIN,  INT16_C(     0),       INT16_MIN } },
    { { -INT16_C( 17631), -INT16_C(  7552), -INT16_C( 28766), -INT16_C( 29258),  INT16_C( 17658),  INT16_C( 18547), -INT16_C(  6327), -INT16_C( 30240) },
      { -INT16_C(  9976),  INT16_C(  5120),  INT16_C( 32016),  INT16_C( 28080),  INT16_C( 10192),  INT16_C( 17304),  INT16_C( 14920),  INT16_C( 20224) },
      { -INT16_C( 14272), -INT16_C( 24576), -INT16_C(  6016),  INT16_C( 28032),  INT16_C( 16000),  INT16_C(  7360), -INT16_C( 11712),  INT16_C( 30720) },
      { -INT16_C( 31744),  INT16_C(     0), -INT16_C( 30720), -INT16_C( 10240), -INT16_C(  6144), -INT16_C( 13312),  INT16_C(  9216),       INT16_MIN },
      {  INT16_C(  8192),  INT16_C(     0),  INT16_C( 16384), -INT16_C( 16384),  INT16_C( 16384),  INT16_C( 24576),  INT16_C(  8192),  INT16_C(     0) },
      {       INT16_MIN,  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),       INT16_MIN,       INT16_MIN,  INT16_C(     0) } },
    { { -INT16_C( 10386), -INT16_C( 17387), -INT16_C( 31213), -INT16_C( 24921), -INT16_C( 20363),  INT16_C(  8974),  INT16_C( 24733), -INT16_C( 16859) },
      { -INT16_C( 17552), -INT16_C(  8024),  INT16_C( 12440), -INT16_C(  2760), -INT16_C( 31832),  INT16_C(  6256),  INT16_C(  1256), -INT16_C(  3800) },
      { -INT16_C(  9344),  INT16_C(  1344), -INT16_C( 31552), -INT16_C( 22080),  INT16_C(  7488), -INT16_C( 15488),  INT16_C( 10048), -INT16_C( 30400) },
      { -INT16_C( 18432),  INT16_C( 21504),  INT16_C( 19456), -INT16_C( 25600), -INT16_C( 11264),  INT16_C( 14336),  INT16_C( 29696), -INT16_C( 27648) },
      { -INT16_C( 16384), -INT16_C( 24576),  INT16_C( 24576), -INT16_C(  8192), -INT16_C( 24576), -INT16_C( 16384), -INT16_C( 24576), -INT16_C( 24576) },
      {  INT16_C(     0),       INT16_MIN,       INT16_MIN,       INT16_MIN,       INT16_MIN,  INT16_C(     0),       INT16_MIN,       INT16_MIN } },
    { { -INT16_C( 23269), -INT16_C( 16992),  INT16_C( 22068),  INT16_C( 11851), -INT16_C( 16741), -INT16_C(  7049),  INT16_C( 22437),  INT16_C(  4973) },
      {  INT16_C( 10456), -INT16_C(  4864), -INT16_C( 20064),  INT16_C( 29272), -INT16_C(  2856),  INT16_C(  9144), -INT16_C( 17112), -INT16_C( 25752) },
      {  INT16_C( 18112),  INT16_C( 26624), -INT16_C( 29440), -INT16_C( 27968), -INT16_C( 22848),  INT16_C(  7616), -INT16_C(  5824), -INT16_C(  9408) },
      {  INT16_C( 27648),       INT16_MIN, -INT16_C( 12288),  INT16_C( 11264),  INT16_C( 27648), -INT16_C(  9216), -INT16_C( 27648), -INT16_C( 19456) },
      {  INT16_C( 24576),  INT16_C(     0),       INT16_MIN,  INT16_C( 24576),  INT16_C( 24576), -INT16_C(  8192), -INT16_C( 24576), -INT16_C( 24576) },
      {       INT16_MIN,  INT16_C(     0),  INT16_C(     0),       INT16_MIN,       INT16_MIN,       INT16_MIN,       INT16_MIN,       INT16_MIN } },
    { { -INT16_C( 32210),  INT16_C( 17104),  INT16_C( 30472),  INT16_C( 32480), -INT16_C(  4312), -INT16_C( 14943), -INT16_C( 14769),  INT16_C( 27267) },
      {  INT16_C(  4464),  INT16_C(  5760), -INT16_C( 18368), -INT16_C(  2304),  INT16_C( 31040),  INT16_C( 11528),  INT16_C( 12920),  INT16_C( 21528) },
      { -INT16_C( 29824), -INT16_C( 19456), -INT16_C( 15872), -INT16_C( 18432), -INT16_C( 13824),  INT16_C( 26688), -INT16_C( 27712), -INT16_C( 24384) },
      { -INT16_C( 18432),  INT16_C( 16384),  INT16_C(  8192),       INT16_MIN, -INT16_C( 24576), -INT16_C( 31744),  INT16_C( 15360),  INT16_C(  3072) },
      { -INT16_C( 16384),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(  8192), -INT16_C(  8192),  INT16_C( 24576) },
      {  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),       INT16_MIN,       INT16_MIN,       INT16_MIN } },
    { {  INT16_C(  9068), -INT16_C( 24536),  INT16_C( 29562),  INT16_C(  5583),  INT16_C( 17969), -INT16_C( 10503),  INT16_C( 26269), -INT16_C( 13335) },
      {  INT16_C(  7008),  INT16_C(   320), -INT16_C( 25648), -INT16_C( 20872),  INT16_C( 12680), -INT16_C( 18488),  INT16_C( 13544),  INT16_C( 24392) },
      { -INT16_C(  9472),  INT16_C(  2560), -INT16_C(  8576),  INT16_C( 29632), -INT16_C( 29632), -INT16_C( 16832), -INT16_C( 22720), -INT16_C(  1472) },
      { -INT16_C( 20480), -INT16_C( 24576), -INT16_C(  6144),  INT16_C( 15360), -INT16_C( 15360), -INT16_C(  7168),  INT16_C( 29696), -INT16_C( 23552) },
      {       INT16_MIN,  INT16_C(     0),  INT16_C( 16384), -INT16_C(  8192),  INT16_C(  8192),  INT16_C(  8192), -INT16_C( 24576),  INT16_C(  8192) },
      {  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),       INT16_MIN,       INT16_MIN,       INT16_MIN,       INT16_MIN,       INT16_MIN } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x8_t a = simde_vld1q_s16(test_vec[i].a);

    simde_int16x8_t r3 = simde_vshlq_n_s16(a, 3);
    simde_int16x8_t r6 = simde_vshlq_n_s16(a, 6);
    simde_int16x8_t r10 = simde_vshlq_n_s16(a, 10);
    simde_int16x8_t r13 = simde_vshlq_n_s16(a, 13);
    simde_int16x8_t r15 = simde_vshlq_n_s16(a, 15);

    simde_test_arm_neon_assert_equal_i16x8(r3, simde_vld1q_s16(test_vec[i].r3));
    simde_test_arm_neon_assert_equal_i16x8(r6, simde_vld1q_s16(test_vec[i].r6));
    simde_test_arm_neon_assert_equal_i16x8(r10, simde_vld1q_s16(test_vec[i].r10));
    simde_test_arm_neon_assert_equal_i16x8(r13, simde_vld1q_s16(test_vec[i].r13));
    simde_test_arm_neon_assert_equal_i16x8(r15, simde_vld1q_s16(test_vec[i].r15));
  }

  return 0;
}

static int
test_simde_vshlq_n_s32 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    int32_t a[4];
    int32_t r6[4];
    int32_t r13[4];
    int32_t r19[4];
    int32_t r26[4];
    int32_t r31[4];
  } test_vec[] = {
    { { -INT32_C(   625232409), -INT32_C(  1671477481), -INT32_C(  1663805479),  INT32_C(   344789064) },
      { -INT32_C(  1360168512),  INT32_C(   399623616),  INT32_C(   890631744),  INT32_C(   591663616) },
      {  INT32_C(  1992089600), -INT32_C(   387784704), -INT32_C(  1963253760), -INT32_C(  1576468480) },
      { -INT32_C(  1355284480),  INT32_C(   951582720), -INT32_C(  1094189056), -INT32_C(  2109734912) },
      { -INT32_C(  1677721600),  INT32_C(  1543503872),  INT32_C(  1677721600),  INT32_C(   536870912) },
      {            INT32_MIN,            INT32_MIN,            INT32_MIN,  INT32_C(           0) } },
    { {  INT32_C(   563748864),  INT32_C(  1054148742),  INT32_C(  1642772687),  INT32_C(   746101317) },
      {  INT32_C(  1720188928), -INT32_C(  1253957248),  INT32_C(  2058236864),  INT32_C(   505844032) },
      {  INT32_C(  1140850688), -INT32_C(  1592737792),  INT32_C(  1461313536),  INT32_C(   323526656) },
      {  INT32_C(           0),  INT32_C(  1143996416), -INT32_C(   965214208), -INT32_C(   769130496) },
      {  INT32_C(           0),  INT32_C(   402653184),  INT32_C(  1006632960),  INT32_C(   335544320) },
      {  INT32_C(           0),  INT32_C(           0),            INT32_MIN,            INT32_MIN } },
    { {  INT32_C(  1711682383),  INT32_C(  1392665978),  INT32_C(    99604413), -INT32_C(   417760025) },
      { -INT32_C(  2121477184), -INT32_C(  1063690624),  INT32_C(  2079715136), -INT32_C(   966837824) },
      { -INT32_C(   966139904),  INT32_C(  1286553600), -INT32_C(    84434944),  INT32_C(   798810112) },
      { -INT32_C(  1703411712),  INT32_C(   735051776), -INT32_C(  1108869120), -INT32_C(   415760384) },
      {  INT32_C(  1006632960), -INT32_C(   402653184), -INT32_C(   201326592), -INT32_C(  1677721600) },
      {            INT32_MIN,  INT32_C(           0),            INT32_MIN,            INT32_MIN } },
    { {  INT32_C(   587772828), -INT32_C(  1956520516), -INT32_C(   622048363),  INT32_C(   872834277) },
      { -INT32_C(  1037244672), -INT32_C(   663261440), -INT32_C(  1156389568),  INT32_C(    26818880) },
      {  INT32_C(   376668160),  INT32_C(  1001881600), -INT32_C(  1988976640), -INT32_C(   862150656) },
      { -INT32_C(  1663041536), -INT32_C(   304087040),  INT32_C(  1554513920),  INT32_C(   656932864) },
      {  INT32_C(  1879048192), -INT32_C(   268435456),  INT32_C(  1409286144), -INT32_C(  1811939328) },
      {  INT32_C(           0),  INT32_C(           0),            INT32_MIN,            INT32_MIN } },
    { {  INT32_C(   295308695),  INT32_C(   795122802),  INT32_C(  1513378675),  INT32_C(  1816219088) },
      {  INT32_C(  1719887296), -INT32_C(   651748224), -INT32_C(  1928012608),  INT32_C(   273904640) },
      {  INT32_C(  1102241792), -INT32_C(  1819394048), -INT32_C(  1972477952),  INT32_C(   700055552) },
      {  INT32_C(  1823997952), -INT32_C(   477102080), -INT32_C(  1684537344),  INT32_C(  1853882368) },
      {  INT32_C(  1543503872), -INT32_C(   939524096), -INT32_C(   872415232),  INT32_C(  1073741824) },
      {            INT32_MIN,  INT32_C(           0),            INT32_MIN,  INT32_C(           0) } },
    { { -INT32_C(  1114683135), -INT32_C(  1152847834),  INT32_C(   546649147),  INT32_C(   794074264) },
      {  INT32_C(  1674723392), -INT32_C(   767817344),  INT32_C(   625807040), -INT32_C(   718854656) },
      { -INT32_C(   383770624),  INT32_C(   503627776), -INT32_C(  1501077504), -INT32_C(  1819082752) },
      {  INT32_C(  1208483840), -INT32_C(  2127560704), -INT32_C(  1579679744), -INT32_C(   457179136) },
      {  INT32_C(    67108864), -INT32_C(  1744830464), -INT32_C(   335544320),  INT32_C(  1610612736) },
      {            INT32_MIN,  INT32_C(           0),            INT32_MIN,  INT32_C(           0) } },
    { {  INT32_C(   457240233), -INT32_C(    28597109), -INT32_C(   950435849), -INT32_C(   835413299) },
      { -INT32_C(   801396160), -INT32_C(  1830214976), -INT32_C(   698352192), -INT32_C(  1926843584) },
      {  INT32_C(   500506624),  INT32_C(  1955684352),  INT32_C(   805232640), -INT32_C(  1822842880) },
      {  INT32_C(  1967652864),  INT32_C(   609746944), -INT32_C(     4718592), -INT32_C(   697827328) },
      { -INT32_C(  1543503872),  INT32_C(   738197504), -INT32_C(   603979776),  INT32_C(   872415232) },
      {            INT32_MIN,            INT32_MIN,            INT32_MIN,            INT32_MIN } },
    { {  INT32_C(   176931812), -INT32_C(   272182348), -INT32_C(  1626318073), -INT32_C(  1597086473) },
      { -INT32_C(  1561265920), -INT32_C(   239801088), -INT32_C(  1005141568),  INT32_C(   865680832) },
      {  INT32_C(  2021425152), -INT32_C(   629768192),  INT32_C(   190898176), -INT32_C(   862003200) },
      {  INT32_C(   522190848), -INT32_C(  1650458624), -INT32_C(   667418624),  INT32_C(   666370048) },
      { -INT32_C(  1879048192), -INT32_C(   805306368),  INT32_C(   469762048), -INT32_C(   603979776) },
      {  INT32_C(           0),  INT32_C(           0),            INT32_MIN,            INT32_MIN } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x4_t a = simde_vld1q_s32(test_vec[i].a);

    simde_int32x4_t r6 = simde_vshlq_n_s32(a, 6);
    simde_int32x4_t r13 = simde_vshlq_n_s32(a, 13);
    simde_int32x4_t r19 = simde_vshlq_n_s32(a, 19);
    simde_int32x4_t r26 = simde_vshlq_n_s32(a, 26);
    simde_int32x4_t r31 = simde_vshlq_n_s32(a, 31);

    simde_test_arm_neon_assert_equal_i32x4(r6, simde_vld1q_s32(test_vec[i].r6));
    simde_test_arm_neon_assert_equal_i32x4(r13, simde_vld1q_s32(test_vec[i].r13));
    simde_test_arm_neon_assert_equal_i32x4(r19, simde_vld1q_s32(test_vec[i].r19));
    simde_test_arm_neon_assert_equal_i32x4(r26, simde_vld1q_s32(test_vec[i].r26));
    simde_test_arm_neon_assert_equal_i32x4(r31, simde_vld1q_s32(test_vec[i].r31));
  }

  return 0;
}

static int
test_simde_vshlq_n_s64 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    int64_t a[2];
    int64_t r13[2];
    int64_t r26[2];
    int64_t r39[2];
    int64_t r52[2];
    int64_t r63[2];
  } test_vec[] = {
    { { -INT64_C( 3916933561112073211), -INT64_C( 4395184176717254386) },
      { -INT64_C( 8631788449193484288),  INT64_C( 2695656213296824320) },
      { -INT64_C( 5240941264311943168),  INT64_C( 2063043097251545088) },
      { -INT64_C( 8217377721311821824),  INT64_C( 3231481166708080640) },
      { -INT64_C( 4589168020290535424),  INT64_C( 1215971899390033920) },
      {                     INT64_MIN,  INT64_C(                   0) } },
    { { -INT64_C( 5027807624829575335),  INT64_C( 4868113288224494141) },
      {  INT64_C( 3779453989547614208), -INT64_C( 2276630224994590720) },
      {  INT64_C( 7650526689427980288), -INT64_C(  496544635330494464) },
      { -INT64_C( 8921722671041871872),  INT64_C( 9036787662400258048) },
      { -INT64_C(  752101137770872832),  INT64_C( 2580562586483294208) },
      {                     INT64_MIN,                     INT64_MIN } },
    { { -INT64_C(  475489388565583121),  INT64_C( 4860549388740706153) },
      { -INT64_C( 2946071576541536256), -INT64_C( 8899862575057133568) },
      { -INT64_C( 5877106616171495424), -INT64_C( 6141635567890202624) },
      {  INT64_C(  744632705039204352), -INT64_C( 8007483150592638976) },
      { -INT64_C( 5841168716699533312), -INT64_C(  680043543732944896) },
      {                     INT64_MIN,                     INT64_MIN } },
    { {  INT64_C( 6761600824558648450), -INT64_C( 4297785532867161638) },
      { -INT64_C( 4538498565335400448),  INT64_C( 7375351463745896448) },
      { -INT64_C( 9190938702853963776),  INT64_C( 5792349607602159616) },
      {  INT64_C( 7439455102718443520),  INT64_C( 5902227895924817920) },
      { -INT64_C( 4026218066869223424),  INT64_C( 2134706223373615104) },
      {  INT64_C(                   0),  INT64_C(                   0) } },
    { { -INT64_C( 7943850393553834020), -INT64_C( 8668384723283549563) },
      {  INT64_C( 4090668054289809408),  INT64_C( 8557030642935701504) },
      { -INT64_C( 6981281188136615936),  INT64_C( 1567546832970579968) },
      { -INT64_C( 5748864715547738112),  INT64_C( 2409780393143173120) },
      { -INT64_C(  162129586585337856),  INT64_C( 2904821759653969920) },
      {  INT64_C(                   0),                     INT64_MIN } },
    { {  INT64_C( 7255433734221234739),  INT64_C( 7054000982656373579) },
      {  INT64_C( 1103745248179675136), -INT64_C( 7273133011012853760) },
      {  INT64_C( 2976476970218422272),  INT64_C( 1477731864553717760) },
      { -INT64_C( 3296325414711984128),  INT64_C( 4515322070590029824) },
      {  INT64_C( 2535526590209589248),  INT64_C( 3796534485873328128) },
      {                     INT64_MIN,                     INT64_MIN } },
    { { -INT64_C( 8070194296929106872),  INT64_C( 3195784395642389196) },
      {  INT64_C( 2099079731789496320),  INT64_C( 3935928508598550528) },
      {  INT64_C( 3295686122251747328), -INT64_C( 1782298404970299392) },
      { -INT64_C( 7772610424469454848), -INT64_C( 9213971212437291008) },
      {  INT64_C( 4935945191598063616),  INT64_C( 3224577333197275136) },
      {  INT64_C(                   0),  INT64_C(                   0) } },
    { { -INT64_C( 4385327945774793418), -INT64_C( 4438078105841327742) },
      { -INT64_C( 8795820274610683904),  INT64_C( 1796726229369372672) },
      { -INT64_C( 2377337701213929472), -INT64_C( 1720499826321260544) },
      {  INT64_C( 4611293492776271872), -INT64_C( 1022104909668941824) },
      { -INT64_C( 3215570133942534144),  INT64_C( 1738389456165011456) },
      {  INT64_C(                   0),  INT64_C(                   0) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int64x2_t a = simde_vld1q_s64(test_vec[i].a);

    simde_int64x2_t r13 = simde_vshlq_n_s64(a, 13);
    simde_int64x2_t r26 = simde_vshlq_n_s64(a, 26);
    simde_int64x2_t r39 = simde_vshlq_n_s64(a, 39);
    simde_int64x2_t r52 = simde_vshlq_n_s64(a, 52);
    simde_int64x2_t r63 = simde_vshlq_n_s64(a, 63);

    simde_test_arm_neon_assert_equal_i64x2(r13, simde_vld1q_s64(test_vec[i].r13));
    simde_test_arm_neon_assert_equal_i64x2(r26, simde_vld1q_s64(test_vec[i].r26));
    simde_test_arm_neon_assert_equal_i64x2(r39, simde_vld1q_s64(test_vec[i].r39));
    simde_test_arm_neon_assert_equal_i64x2(r52, simde_vld1q_s64(test_vec[i].r52));
    simde_test_arm_neon_assert_equal_i64x2(r63, simde_vld1q_s64(test_vec[i].r63));
  }

  return 0;
}

static int
test_simde_vshlq_n_u8 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    uint8_t a[16];
    uint8_t r1[16];
    uint8_t r3[16];
    uint8_t r5[16];
    uint8_t r6[16];
    uint8_t r7[16];
  } test_vec[] = {
    { { UINT8_C( 23), UINT8_C( 50), UINT8_C(143), UINT8_C(105), UINT8_C(115), UINT8_C( 68), UINT8_C(175), UINT8_C( 96),
        UINT8_C(181), UINT8_C(142), UINT8_C(239), UINT8_C(220), UINT8_C( 83), UINT8_C(110), UINT8_C(136), UINT8_C( 92) },
      { UINT8_C( 46), UINT8_C(100), UINT8_C( 30), UINT8_C(210), UINT8_C(230), UINT8_C(136), UINT8_C( 94), UINT8_C(192),
        UINT8_C(106), UINT8_C( 28), UINT8_C(222), UINT8_C(184), UINT8_C(166), UINT8_C(220), UINT8_C( 16), UINT8_C(184) },
      { UINT8_C(184), UINT8_C(144), UINT8_C(120), UINT8_C( 72), UINT8_C(152), UINT8_C( 32), UINT8_C(120), UINT8_C(  0),
        UINT8_C(168), UINT8_C(112), UINT8_C(120), UINT8_C(224), UINT8_C(152), UINT8_C(112), UINT8_C( 64), UINT8_C(224) },
      { UINT8_C(224), UINT8_C( 64), UINT8_C(224), UINT8_C( 32), UINT8_C( 96), UINT8_C(128), UINT8_C(224), UINT8_C(  0),
        UINT8_C(160), UINT8_C(192), UINT8_C(224), UINT8_C(128), UINT8_C( 96), UINT8_C(192), UINT8_C(  0), UINT8_C(128) },
      { UINT8_C(192), UINT8_C(128), UINT8_C(192), UINT8_C( 64), UINT8_C(192), UINT8_C(  0), UINT8_C(192), UINT8_C(  0),
        UINT8_C( 64), UINT8_C(128), UINT8_C(192), UINT8_C(  0), UINT8_C(192), UINT8_C(128), UINT8_C(  0), UINT8_C(  0) },
      { UINT8_C(128), UINT8_C(  0), UINT8_C(128), UINT8_C(128), UINT8_C(128), UINT8_C(  0), UINT8_C(128), UINT8_C(  0),
        UINT8_C(128), UINT8_C(  0), UINT8_C(128), UINT8_C(  0), UINT8_C(128), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0) } },
    { { UINT8_C( 21), UINT8_C(  4), UINT8_C( 13), UINT8_C(229), UINT8_C(186), UINT8_C( 69), UINT8_C(150), UINT8_C(162),
        UINT8_C(189), UINT8_C(194), UINT8_C(194), UINT8_C( 36), UINT8_C(186), UINT8_C( 97), UINT8_C(180), UINT8_C(210) },
      { UINT8_C( 42), UINT8_C(  8), UINT8_C( 26), UINT8_C(202), UINT8_C(116), UINT8_C(138), UINT8_C( 44), UINT8_C( 68),
        UINT8_C(122), UINT8_C(132), UINT8_C(132), UINT8_C( 72), UINT8_C(116), UINT8_C(194), UINT8_C(104), UINT8_C(164) },
      { UINT8_C(168), UINT8_C( 32), UINT8_C(104), UINT8_C( 40), UINT8_C(208), UINT8_C( 40), UINT8_C(176), UINT8_C( 16),
        UINT8_C(232), UINT8_C( 16), UINT8_C( 16), UINT8_C( 32), UINT8_C(208), UINT8_C(  8), UINT8_C(160), UINT8_C(144) },
      { UINT8_C(160), UINT8_C(128), UINT8_C(160), UINT8_C(160), UINT8_C( 64), UINT8_C(160), UINT8_C(192), UINT8_C( 64),
        UINT8_C(160), UINT8_C( 64), UINT8_C( 64), UINT8_C(128), UINT8_C( 64), UINT8_C( 32), UINT8_C(128), UINT8_C( 64) },
      { UINT8_C( 64), UINT8_C(  0), UINT8_C( 64), UINT8_C( 64), UINT8_C(128), UINT8_C( 64), UINT8_C(128), UINT8_C(128),
        UINT8_C( 64), UINT8_C(128), UINT8_C(128), UINT8_C(  0), UINT8_C(128), UINT8_C( 64), UINT8_C(  0), UINT8_C(128) },
      { UINT8_C(128), UINT8_C(  0), UINT8_C(128), UINT8_C(128), UINT8_C(  0), UINT8_C(128), UINT8_C(  0), UINT8_C(  0),
        UINT8_C(128), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(128), UINT8_C(  0), UINT8_C(  0) } },
    { { UINT8_C(147), UINT8_C( 67), UINT8_C( 59), UINT8_C(  7), UINT8_C(135), UINT8_C(234), UINT8_C(103), UINT8_C( 61),
        UINT8_C(120), UINT8_C( 86), UINT8_C( 25), UINT8_C(203), UINT8_C(196), UINT8_C(161), UINT8_C( 39), UINT8_C(217) },
      { UINT8_C( 38), UINT8_C(134), UINT8_C(118), UINT8_C( 14), UINT8_C( 14), UINT8_C(212), UINT8_C(206), UINT8_C(122),
        UINT8_C(240), UINT8_C(172), UINT8_C( 50), UINT8_C(150), UINT8_C(136), UINT8_C( 66), UINT8_C( 78), UINT8_C(178) },
      { UINT8_C(152), UINT8_C( 24), UINT8_C(216), UINT8_C( 56), UINT8_C( 56), UINT8_C( 80), UINT8_C( 56), UINT8_C(232),
        UINT8_C(192), UINT8_C(176), UINT8_C(200), UINT8_C( 88), UINT8_C( 32), UINT8_C(  8), UINT8_C( 56), UINT8_C(200) },
      { UINT8_C( 96), UINT8_C( 96), UINT8_C( 96), UINT8_C(224), UINT8_C(224), UINT8_C( 64), UINT8_C(224), UINT8_C(160),
        UINT8_C(  0), UINT8_C(192), UINT8_C( 32), UINT8_C( 96), UINT8_C(128), UINT8_C( 32), UINT8_C(224), UINT8_C( 32) },
      { UINT8_C(192), UINT8_C(192), UINT8_C(192), UINT8_C(192), UINT8_C(192), UINT8_C(128), UINT8_C(192), UINT8_C( 64),
        UINT8_C(  0), UINT8_C(128), UINT8_C( 64), UINT8_C(192), UINT8_C(  0), UINT8_C( 64), UINT8_C(192), UINT8_C( 64) },
      { UINT8_C(128), UINT8_C(128), UINT8_C(128), UINT8_C(128), UINT8_C(128), UINT8_C(  0), UINT8_C(128), UINT8_C(128),
        UINT8_C(  0), UINT8_C(  0), UINT8_C(128), UINT8_C(128), UINT8_C(  0), UINT8_C(128), UINT8_C(128), UINT8_C(128) } },
    { { UINT8_C(165), UINT8_C( 53), UINT8_C(190), UINT8_C( 95), UINT8_C(122), UINT8_C( 85), UINT8_C(  1), UINT8_C( 56),
        UINT8_C( 23), UINT8_C(196), UINT8_C( 92), UINT8_C(209), UINT8_C( 37), UINT8_C( 16), UINT8_C(163), UINT8_C(185) },
      { UINT8_C( 74), UINT8_C(106), UINT8_C(124), UINT8_C(190), UINT8_C(244), UINT8_C(170), UINT8_C(  2), UINT8_C(112),
        UINT8_C( 46), UINT8_C(136), UINT8_C(184), UINT8_C(162), UINT8_C( 74), UINT8_C( 32), UINT8_C( 70), UINT8_C(114) },
      { UINT8_C( 40), UINT8_C(168), UINT8_C(240), UINT8_C(248), UINT8_C(208), UINT8_C(168), UINT8_C(  8), UINT8_C(192),
        UINT8_C(184), UINT8_C( 32), UINT8_C(224), UINT8_C(136), UINT8_C( 40), UINT8_C(128), UINT8_C( 24), UINT8_C(200) },
      { UINT8_C(160), UINT8_C(160), UINT8_C(192), UINT8_C(224), UINT8_C( 64), UINT8_C(160), UINT8_C( 32), UINT8_C(  0),
        UINT8_C(224), UINT8_C(128), UINT8_C(128), UINT8_C( 32), UINT8_C(160), UINT8_C(  0), UINT8_C( 96), UINT8_C( 32) },
      { UINT8_C( 64), UINT8_C( 64), UINT8_C(128), UINT8_C(192), UINT8_C(128), UINT8_C( 64), UINT8_C( 64), UINT8_C(  0),
        UINT8_C(192), UINT8_C(  0), UINT8_C(  0), UINT8_C( 64), UINT8_C( 64), UINT8_C(  0), UINT8_C(192), UINT8_C( 64) },
      { UINT8_C(128), UINT8_C(128), UINT8_C(  0), UINT8_C(128), UINT8_C(  0), UINT8_C(128), UINT8_C(128), UINT8_C(  0),
        UINT8_C(128), UINT8_C(  0), UINT8_C(  0), UINT8_C(128), UINT8_C(128), UINT8_C(  0), UINT8_C(128), UINT8_C(128) } },
    { { UINT8_C( 84), UINT8_C(222), UINT8_C(192), UINT8_C(219), UINT8_C(200), UINT8_C( 39), UINT8_C( 24), UINT8_C( 65),
        UINT8_C(126), UINT8_C( 49), UINT8_C( 12), UINT8_C( 66), UINT8_C(210), UINT8_C( 52), UINT8_C( 28), UINT8_C(119) },
      { UINT8_C(168), UINT8_C(188), UINT8_C(128), UINT8_C(182), UINT8_C(144), UINT8_C( 78), UINT8_C( 48), UINT8_C(130),
        UINT8_C(252), UINT8_C( 98), UINT8_C( 24), UINT8_C(132), UINT8_C(164), UINT8_C(104), UINT8_C( 56), UINT8_C(238) },
      { UINT8_C(160), UINT8_C(240), UINT8_C(  0), UINT8_C(216), UINT8_C( 64), UINT8_C( 56), UINT8_C(192), UINT8_C(  8),
        UINT8_C(240), UINT8_C(136), UINT8_C( 96), UINT8_C( 16), UINT8_C(144), UINT8_C(160), UINT8_C(224), UINT8_C(184) },
      { UINT8_C(128), UINT8_C(192), UINT8_C(  0), UINT8_C( 96), UINT8_C(  0), UINT8_C(224), UINT8_C(  0), UINT8_C( 32),
        UINT8_C(192), UINT8_C( 32), UINT8_C(128), UINT8_C( 64), UINT8_C( 64), UINT8_C(128), UINT8_C(128), UINT8_C(224) },
      { UINT8_C(  0), UINT8_C(128), UINT8_C(  0), UINT8_C(192), UINT8_C(  0), UINT8_C(192), UINT8_C(  0), UINT8_C( 64),
        UINT8_C(128), UINT8_C( 64), UINT8_C(  0), UINT8_C(128), UINT8_C(128), UINT8_C(  0), UINT8_C(  0), UINT8_C(192) },
      { UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(128), UINT8_C(  0), UINT8_C(128), UINT8_C(  0), UINT8_C(128),
        UINT8_C(  0), UINT8_C(128), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(128) } },
    { { UINT8_C(105), UINT8_C(218), UINT8_C(214), UINT8_C(227), UINT8_C( 47), UINT8_C(216), UINT8_C( 27), UINT8_C( 70),
        UINT8_C(156), UINT8_C(120), UINT8_C( 24), UINT8_C(193), UINT8_C(136), UINT8_C(187), UINT8_C(122), UINT8_C(220) },
      { UINT8_C(210), UINT8_C(180), UINT8_C(172), UINT8_C(198), UINT8_C( 94), UINT8_C(176), UINT8_C( 54), UINT8_C(140),
        UINT8_C( 56), UINT8_C(240), UINT8_C( 48), UINT8_C(130), UINT8_C( 16), UINT8_C(118), UINT8_C(244), UINT8_C(184) },
      { UINT8_C( 72), UINT8_C(208), UINT8_C(176), UINT8_C( 24), UINT8_C(120), UINT8_C(192), UINT8_C(216), UINT8_C( 48),
        UINT8_C(224), UINT8_C(192), UINT8_C(192), UINT8_C(  8), UINT8_C( 64), UINT8_C(216), UINT8_C(208), UINT8_C(224) },
      { UINT8_C( 32), UINT8_C( 64), UINT8_C(192), UINT8_C( 96), UINT8_C(224), UINT8_C(  0), UINT8_C( 96), UINT8_C(192),
        UINT8_C(128), UINT8_C(  0), UINT8_C(  0), UINT8_C( 32), UINT8_C(  0), UINT8_C( 96), UINT8_C( 64), UINT8_C(128) },
      { UINT8_C( 64), UINT8_C(128), UINT8_C(128), UINT8_C(192), UINT8_C(192), UINT8_C(  0), UINT8_C(192), UINT8_C(128),
        UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C( 64), UINT8_C(  0), UINT8_C(192), UINT8_C(128), UINT8_C(  0) },
      { UINT8_C(128), UINT8_C(  0), UINT8_C(  0), UINT8_C(128), UINT8_C(128), UINT8_C(  0), UINT8_C(128), UINT8_C(  0),
        UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(128), UINT8_C(  0), UINT8_C(128), UINT8_C(  0), UINT8_C(  0) } },
    { { UINT8_C(154), UINT8_C( 58), UINT8_C(184), UINT8_C( 98), UINT8_C( 98), UINT8_C(208), UINT8_C(163), UINT8_C(224),
        UINT8_C(  2), UINT8_C(176), UINT8_C( 34), UINT8_C(212), UINT8_C(228), UINT8_C( 62), UINT8_C( 76), UINT8_C( 77) },
      { UINT8_C( 52), UINT8_C(116), UINT8_C(112), UINT8_C(196), UINT8_C(196), UINT8_C(160), UINT8_C( 70), UINT8_C(192),
        UINT8_C(  4), UINT8_C( 96), UINT8_C( 68), UINT8_C(168), UINT8_C(200), UINT8_C(124), UINT8_C(152), UINT8_C(154) },
      { UINT8_C(208), UINT8_C(208), UINT8_C(192), UINT8_C( 16), UINT8_C( 16), UINT8_C(128), UINT8_C( 24), UINT8_C(  0),
        UINT8_C( 16), UINT8_C(128), UINT8_C( 16), UINT8_C(160), UINT8_C( 32), UINT8_C(240), UINT8_C( 96), UINT8_C(104) },
      { UINT8_C( 64), UINT8_C( 64), UINT8_C(  0), UINT8_C( 64), UINT8_C( 64), UINT8_C(  0), UINT8_C( 96), UINT8_C(  0),
        UINT8_C( 64), UINT8_C(  0), UINT8_C( 64), UINT8_C(128), UINT8_C(128), UINT8_C(192), UINT8_C(128), UINT8_C(160) },
      { UINT8_C(128), UINT8_C(128), UINT8_C(  0), UINT8_C(128), UINT8_C(128), UINT8_C(  0), UINT8_C(192), UINT8_C(  0),
        UINT8_C(128), UINT8_C(  0), UINT8_C(128), UINT8_C(  0), UINT8_C(  0), UINT8_C(128), UINT8_C(  0), UINT8_C( 64) },
      { UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(128), UINT8_C(  0),
        UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(128) } },
    { { UINT8_C( 25), UINT8_C( 34), UINT8_C( 48), UINT8_C( 72), UINT8_C(250), UINT8_C( 76), UINT8_C(143), UINT8_C(150),
        UINT8_C(196), UINT8_C(167), UINT8_C( 88), UINT8_C( 76), UINT8_C( 98), UINT8_C(210), UINT8_C( 41), UINT8_C(252) },
      { UINT8_C( 50), UINT8_C( 68), UINT8_C( 96), UINT8_C(144), UINT8_C(244), UINT8_C(152), UINT8_C( 30), UINT8_C( 44),
        UINT8_C(136), UINT8_C( 78), UINT8_C(176), UINT8_C(152), UINT8_C(196), UINT8_C(164), UINT8_C( 82), UINT8_C(248) },
      { UINT8_C(200), UINT8_C( 16), UINT8_C(128), UINT8_C( 64), UINT8_C(208), UINT8_C( 96), UINT8_C(120), UINT8_C(176),
        UINT8_C( 32), UINT8_C( 56), UINT8_C(192), UINT8_C( 96), UINT8_C( 16), UINT8_C(144), UINT8_C( 72), UINT8_C(224) },
      { UINT8_C( 32), UINT8_C( 64), UINT8_C(  0), UINT8_C(  0), UINT8_C( 64), UINT8_C(128), UINT8_C(224), UINT8_C(192),
        UINT8_C(128), UINT8_C(224), UINT8_C(  0), UINT8_C(128), UINT8_C( 64), UINT8_C( 64), UINT8_C( 32), UINT8_C(128) },
      { UINT8_C( 64), UINT8_C(128), UINT8_C(  0), UINT8_C(  0), UINT8_C(128), UINT8_C(  0), UINT8_C(192), UINT8_C(128),
        UINT8_C(  0), UINT8_C(192), UINT8_C(  0), UINT8_C(  0), UINT8_C(128), UINT8_C(128), UINT8_C( 64), UINT8_C(  0) },
      { UINT8_C(128), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(128), UINT8_C(  0),
        UINT8_C(  0), UINT8_C(128), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(128), UINT8_C(  0) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint8x16_t a = simde_vld1q_u8(test_vec[i].a);

    simde_uint8x16_t r1 = simde_vshlq_n_u8(a, 1);
    simde_uint8x16_t r3 = simde_vshlq_n_u8(a, 3);
    simde_uint8x16_t r5 = simde_vshlq_n_u8(a, 5);
    simde_uint8x16_t r6 = simde_vshlq_n_u8(a, 6);
    simde_uint8x16_t r7 = simde_vshlq_n_u8(a, 7);

    simde_test_arm_neon_assert_equal_u8x16(r1, simde_vld1q_u8(test_vec[i].r1));
    simde_test_arm_neon_assert_equal_u8x16(r3, simde_vld1q_u8(test_vec[i].r3));
    simde_test_arm_neon_assert_equal_u8x16(r5, simde_vld1q_u8(test_vec[i].r5));
    simde_test_arm_neon_assert_equal_u8x16(r6, simde_vld1q_u8(test_vec[i].r6));
    simde_test_arm_neon_assert_equal_u8x16(r7, simde_vld1q_u8(test_vec[i].r7));
  }

  return 0;
}

static int
test_simde_vshlq_n_u16 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    uint16_t a[8];
    uint16_t r3[8];
    uint16_t r6[8];
    uint16_t r10[8];
    uint16_t r13[8];
    uint16_t r15[8];
  } test_vec[] = {
    { { UINT16_C(26792), UINT16_C(21973), UINT16_C(45271), UINT16_C(  606), UINT16_C(50076), UINT16_C( 1066), UINT16_C(38310), UINT16_C(50221) },
      { UINT16_C(17728), UINT16_C(44712), UINT16_C(34488), UINT16_C( 4848), UINT16_C( 7392), UINT16_C( 8528), UINT16_C(44336), UINT16_C( 8552) },
      { UINT16_C(10752), UINT16_C(30016), UINT16_C(13760), UINT16_C(38784), UINT16_C(59136), UINT16_C( 2688), UINT16_C(27008), UINT16_C( 2880) },
      { UINT16_C(40960), UINT16_C(21504), UINT16_C(23552), UINT16_C(30720), UINT16_C(28672), UINT16_C(43008), UINT16_C(38912), UINT16_C(46080) },
      { UINT16_C(    0), UINT16_C(40960), UINT16_C(57344), UINT16_C(49152), UINT16_C(32768), UINT16_C(16384), UINT16_C(49152), UINT16_C(40960) },
      { UINT16_C(    0), UINT16_C(32768), UINT16_C(32768), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(32768) } },
    { { UINT16_C(31245), UINT16_C(30511), UINT16_C(48494), UINT16_C(60175), UINT16_C(39412), UINT16_C(16395), UINT16_C(18323), UINT16_C(15357) },
      { UINT16_C(53352), UINT16_C(47480), UINT16_C(60272), UINT16_C(22648), UINT16_C(53152), UINT16_C(   88), UINT16_C(15512), UINT16_C(57320) },
      { UINT16_C(33600), UINT16_C(52160), UINT16_C(23424), UINT16_C(50112), UINT16_C(32000), UINT16_C(  704), UINT16_C(58560), UINT16_C(65344) },
      { UINT16_C(13312), UINT16_C(48128), UINT16_C(47104), UINT16_C(15360), UINT16_C(53248), UINT16_C(11264), UINT16_C(19456), UINT16_C(62464) },
      { UINT16_C(40960), UINT16_C(57344), UINT16_C(49152), UINT16_C(57344), UINT16_C(32768), UINT16_C(24576), UINT16_C(24576), UINT16_C(40960) },
      { UINT16_C(32768), UINT16_C(32768), UINT16_C(    0), UINT16_C(32768), UINT16_C(    0), UINT16_C(32768), UINT16_C(32768), UINT16_C(32768) } },
    { { UINT16_C(53935), UINT16_C(34449), UINT16_C(61314), UINT16_C( 7817), UINT16_C(46003), UINT16_C(22818), UINT16_C(20552), UINT16_C(22046) },
      { UINT16_C(38264), UINT16_C(13448), UINT16_C(31760), UINT16_C(62536), UINT16_C(40344), UINT16_C(51472), UINT16_C(33344), UINT16_C(45296) },
      { UINT16_C(43968), UINT16_C(42048), UINT16_C(57472), UINT16_C(41536), UINT16_C(60608), UINT16_C(18560), UINT16_C( 4608), UINT16_C(34688) },
      { UINT16_C(48128), UINT16_C(17408), UINT16_C( 2048), UINT16_C( 9216), UINT16_C(52224), UINT16_C(34816), UINT16_C( 8192), UINT16_C(30720) },
      { UINT16_C(57344), UINT16_C( 8192), UINT16_C(16384), UINT16_C( 8192), UINT16_C(24576), UINT16_C(16384), UINT16_C(    0), UINT16_C(49152) },
      { UINT16_C(32768), UINT16_C(32768), UINT16_C(    0), UINT16_C(32768), UINT16_C(32768), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0) } },
    { { UINT16_C(19914), UINT16_C(14541), UINT16_C(56587), UINT16_C(65315), UINT16_C(11894), UINT16_C( 2368), UINT16_C(15733), UINT16_C( 9541) },
      { UINT16_C(28240), UINT16_C(50792), UINT16_C(59480), UINT16_C(63768), UINT16_C(29616), UINT16_C(18944), UINT16_C(60328), UINT16_C(10792) },
      { UINT16_C(29312), UINT16_C(13120), UINT16_C(17088), UINT16_C(51392), UINT16_C(40320), UINT16_C(20480), UINT16_C(23872), UINT16_C(20800) },
      { UINT16_C(10240), UINT16_C(13312), UINT16_C(11264), UINT16_C(35840), UINT16_C(55296), UINT16_C(    0), UINT16_C(54272), UINT16_C( 5120) },
      { UINT16_C(16384), UINT16_C(40960), UINT16_C(24576), UINT16_C(24576), UINT16_C(49152), UINT16_C(    0), UINT16_C(40960), UINT16_C(40960) },
      { UINT16_C(    0), UINT16_C(32768), UINT16_C(32768), UINT16_C(32768), UINT16_C(    0), UINT16_C(    0), UINT16_C(32768), UINT16_C(32768) } },
    { { UINT16_C(54799), UINT16_C(37291), UINT16_C(13509), UINT16_C(30896), UINT16_C(53991), UINT16_C(12498), UINT16_C(61474), UINT16_C(60806) },
      { UINT16_C(45176), UINT16_C(36184), UINT16_C(42536), UINT16_C(50560), UINT16_C(38712), UINT16_C(34448), UINT16_C(33040), UINT16_C(27696) },
      { UINT16_C(33728), UINT16_C(27328), UINT16_C(12608), UINT16_C(11264), UINT16_C(47552), UINT16_C(13440), UINT16_C( 2176), UINT16_C(24960) },
      { UINT16_C(15360), UINT16_C(44032), UINT16_C( 5120), UINT16_C(49152), UINT16_C(39936), UINT16_C(18432), UINT16_C(34816), UINT16_C( 6144) },
      { UINT16_C(57344), UINT16_C(24576), UINT16_C(40960), UINT16_C(    0), UINT16_C(57344), UINT16_C(16384), UINT16_C(16384), UINT16_C(49152) },
      { UINT16_C(32768), UINT16_C(32768), UINT16_C(32768), UINT16_C(    0), UINT16_C(32768), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0) } },
    { { UINT16_C(21309), UINT16_C(18469), UINT16_C(18736), UINT16_C(42824), UINT16_C(34935), UINT16_C(60848), UINT16_C(62917), UINT16_C(54290) },
      { UINT16_C(39400), UINT16_C(16680), UINT16_C(18816), UINT16_C(14912), UINT16_C(17336), UINT16_C(28032), UINT16_C(44584), UINT16_C(41104) },
      { UINT16_C(53056), UINT16_C( 2368), UINT16_C(19456), UINT16_C(53760), UINT16_C( 7616), UINT16_C(27648), UINT16_C(28992), UINT16_C( 1152) },
      { UINT16_C(62464), UINT16_C(37888), UINT16_C(49152), UINT16_C( 8192), UINT16_C(56320), UINT16_C(49152), UINT16_C( 5120), UINT16_C(18432) },
      { UINT16_C(40960), UINT16_C(40960), UINT16_C(    0), UINT16_C(    0), UINT16_C(57344), UINT16_C(    0), UINT16_C(40960), UINT16_C(16384) },
      { UINT16_C(32768), UINT16_C(32768), UINT16_C(    0), UINT16_C(    0), UINT16_C(32768), UINT16_C(    0), UINT16_C(32768), UINT16_C(    0) } },
    { { UINT16_C(48587), UINT16_C(37221), UINT16_C( 5618), UINT16_C(55561), UINT16_C(56296), UINT16_C( 2569), UINT16_C(36811), UINT16_C( 2551) },
      { UINT16_C(61016), UINT16_C(35624), UINT16_C(44944), UINT16_C(51272), UINT16_C(57152), UINT16_C(20552), UINT16_C(32344), UINT16_C(20408) },
      { UINT16_C(29376), UINT16_C(22848), UINT16_C(31872), UINT16_C(16960), UINT16_C(64000), UINT16_C(33344), UINT16_C(62144), UINT16_C(32192) },
      { UINT16_C(11264), UINT16_C(37888), UINT16_C(51200), UINT16_C( 9216), UINT16_C(40960), UINT16_C( 9216), UINT16_C(11264), UINT16_C(56320) },
      { UINT16_C(24576), UINT16_C(40960), UINT16_C(16384), UINT16_C( 8192), UINT16_C(    0), UINT16_C( 8192), UINT16_C(24576), UINT16_C(57344) },
      { UINT16_C(32768), UINT16_C(32768), UINT16_C(    0), UINT16_C(32768), UINT16_C(    0), UINT16_C(32768), UINT16_C(32768), UINT16_C(32768) } },
    { { UINT16_C( 7651), UINT16_C( 4945), UINT16_C(39270), UINT16_C(56762), UINT16_C(27425), UINT16_C(59082), UINT16_C(56416), UINT16_C(11450) },
      { UINT16_C(61208), UINT16_C(39560), UINT16_C(52016), UINT16_C(60880), UINT16_C(22792), UINT16_C(13904), UINT16_C(58112), UINT16_C(26064) },
      { UINT16_C(30912), UINT16_C(54336), UINT16_C(22912), UINT16_C(28288), UINT16_C(51264), UINT16_C(45696), UINT16_C( 6144), UINT16_C(11904) },
      { UINT16_C(35840), UINT16_C(17408), UINT16_C(38912), UINT16_C(59392), UINT16_C(33792), UINT16_C(10240), UINT16_C(32768), UINT16_C(59392) },
      { UINT16_C(24576), UINT16_C( 8192), UINT16_C(49152), UINT16_C(16384), UINT16_C( 8192), UINT16_C(16384), UINT16_C(    0), UINT16_C(16384) },
      { UINT16_C(32768), UINT16_C(32768), UINT16_C(    0), UINT16_C(    0), UINT16_C(32768), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint16x8_t a = simde_vld1q_u16(test_vec[i].a);

    simde_uint16x8_t r3 = simde_vshlq_n_u16(a, 3);
    simde_uint16x8_t r6 = simde_vshlq_n_u16(a, 6);
    simde_uint16x8_t r10 = simde_vshlq_n_u16(a, 10);
    simde_uint16x8_t r13 = simde_vshlq_n_u16(a, 13);
    simde_uint16x8_t r15 = simde_vshlq_n_u16(a, 15);

    simde_test_arm_neon_assert_equal_u16x8(r3, simde_vld1q_u16(test_vec[i].r3));
    simde_test_arm_neon_assert_equal_u16x8(r6, simde_vld1q_u16(test_vec[i].r6));
    simde_test_arm_neon_assert_equal_u16x8(r10, simde_vld1q_u16(test_vec[i].r10));
    simde_test_arm_neon_assert_equal_u16x8(r13, simde_vld1q_u16(test_vec[i].r13));
    simde_test_arm_neon_assert_equal_u16x8(r15, simde_vld1q_u16(test_vec[i].r15));
  }

  return 0;
}

static int
test_simde_vshlq_n_u32 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    uint32_t a[4];
    uint32_t r6[4];
    uint32_t r13[4];
    uint32_t r19[4];
    uint32_t r26[4];
    uint32_t r31[4];
  } test_vec[] = {
    { { UINT32_C( 354535181), UINT32_C( 492657404), UINT32_C(2730110454), UINT32_C( 949699748) },
      { UINT32_C(1215415104), UINT32_C(1465302784), UINT32_C(2928377216), UINT32_C( 651241728) },
      { UINT32_C( 954310656), UINT32_C(2875162624), UINT32_C(1170128896), UINT32_C(1754562560) },
      { UINT32_C( 946339840), UINT32_C(3621781504), UINT32_C(1873805312), UINT32_C( 622854144) },
      { UINT32_C( 872415232), UINT32_C(4026531840), UINT32_C(3623878656), UINT32_C(2415919104) },
      { UINT32_C(2147483648), UINT32_C(         0), UINT32_C(         0), UINT32_C(         0) } },
    { { UINT32_C( 408290964), UINT32_C( 736719627), UINT32_C(1309181443), UINT32_C(3275223222) },
      { UINT32_C( 360817920), UINT32_C(4200383168), UINT32_C(2183233728), UINT32_C(3455856000) },
      { UINT32_C(3235020800), UINT32_C( 778133504), UINT32_C( 281042944), UINT32_C(4262903808) },
      { UINT32_C( 882900992), UINT32_C(2555904000), UINT32_C( 806879232), UINT32_C(2242904064) },
      { UINT32_C(1342177280), UINT32_C( 738197504), UINT32_C( 201326592), UINT32_C(3623878656) },
      { UINT32_C(         0), UINT32_C(2147483648), UINT32_C(2147483648), UINT32_C(         0) } },
    { { UINT32_C(3034142904), UINT32_C(2832283314), UINT32_C( 139103075), UINT32_C(1681974992) },
      { UINT32_C( 911617536), UINT32_C( 877505664), UINT32_C( 312662208), UINT32_C( 272217088) },
      { UINT32_C( 722927616), UINT32_C( 651575296), UINT32_C(1366056960), UINT32_C( 484048896) },
      { UINT32_C(3317694464), UINT32_C(3046113280), UINT32_C(1528299520), UINT32_C( 914358272) },
      { UINT32_C(3758096384), UINT32_C(3355443200), UINT32_C(2348810240), UINT32_C(1073741824) },
      { UINT32_C(         0), UINT32_C(         0), UINT32_C(2147483648), UINT32_C(         0) } },
    { { UINT32_C(4168980204), UINT32_C( 220423690), UINT32_C(2723884012), UINT32_C(3563426332) },
      { UINT32_C( 526760704), UINT32_C(1222214272), UINT32_C(2529884928), UINT32_C( 426018560) },
      { UINT32_C(3000860672), UINT32_C(1824604160), UINT32_C(1702723584), UINT32_C(2990768128) },
      { UINT32_C(3076521984), UINT32_C( 810549248), UINT32_C(1600126976), UINT32_C(2430599168) },
      { UINT32_C(2952790016), UINT32_C( 671088640), UINT32_C(2952790016), UINT32_C(1879048192) },
      { UINT32_C(         0), UINT32_C(         0), UINT32_C(         0), UINT32_C(         0) } },
    { { UINT32_C(2642951915), UINT32_C(3628489077), UINT32_C(3051393253), UINT32_C(1662591094) },
      { UINT32_C(1645198016), UINT32_C( 295066944), UINT32_C(2015639872), UINT32_C(3326614912) },
      { UINT32_C( 131948544), UINT32_C(3408830464), UINT32_C( 303865856), UINT32_C( 604946432) },
      { UINT32_C(4149739520), UINT32_C(3416784896), UINT32_C(2267545600), UINT32_C(  61865984) },
      { UINT32_C(2885681152), UINT32_C(3556769792), UINT32_C(2483027968), UINT32_C(3623878656) },
      { UINT32_C(2147483648), UINT32_C(2147483648), UINT32_C(2147483648), UINT32_C(         0) } },
    { { UINT32_C(3244005047), UINT32_C(3905847036), UINT32_C(3314166185), UINT32_C(2795106491) },
      { UINT32_C(1457892800), UINT32_C( 866107136), UINT32_C(1653238336), UINT32_C(2793156288) },
      { UINT32_C(1926684672), UINT32_C(3487531008), UINT32_C(1161109504), UINT32_C(1041719296) },
      { UINT32_C(3048734720), UINT32_C(4158652416), UINT32_C(1296564224), UINT32_C(2245525504) },
      { UINT32_C(3690987520), UINT32_C(4026531840), UINT32_C(2751463424), UINT32_C(3959422976) },
      { UINT32_C(2147483648), UINT32_C(         0), UINT32_C(2147483648), UINT32_C(2147483648) } },
    { { UINT32_C(2739151150), UINT32_C(1618774651), UINT32_C(2434096154), UINT32_C( 888417917) },
      { UINT32_C(3506981760), UINT32_C( 522362560), UINT32_C(1163331200), UINT32_C(1024171840) },
      { UINT32_C(2217066496), UINT32_C(2437898240), UINT32_C(2877505536), UINT32_C(2244976640) },
      { UINT32_C( 158334976), UINT32_C(1406664704), UINT32_C(3771727872), UINT32_C(1944584192) },
      { UINT32_C(3087007744), UINT32_C(3959422976), UINT32_C(1744830464), UINT32_C(4093640704) },
      { UINT32_C(         0), UINT32_C(2147483648), UINT32_C(         0), UINT32_C(2147483648) } },
    { { UINT32_C(3254079429), UINT32_C(1990902733), UINT32_C(2805740780), UINT32_C(1397675300) },
      { UINT32_C(2102653248), UINT32_C(2863723328), UINT32_C(3473750784), UINT32_C(3551873280) },
      { UINT32_C(2851643392), UINT32_C(1484365824), UINT32_C(2258468864), UINT32_C(3668213760) },
      { UINT32_C(2116550656), UINT32_C( 510132224), UINT32_C(2808086528), UINT32_C(2837446656) },
      { UINT32_C( 335544320), UINT32_C( 872415232), UINT32_C(2952790016), UINT32_C(2415919104) },
      { UINT32_C(2147483648), UINT32_C(2147483648), UINT32_C(         0), UINT32_C(         0) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint32x4_t a = simde_vld1q_u32(test_vec[i].a);

    simde_uint32x4_t r6 = simde_vshlq_n_u32(a, 6);
    simde_uint32x4_t r13 = simde_vshlq_n_u32(a, 13);
    simde_uint32x4_t r19 = simde_vshlq_n_u32(a, 19);
    simde_uint32x4_t r26 = simde_vshlq_n_u32(a, 26);
    simde_uint32x4_t r31 = simde_vshlq_n_u32(a, 31);

    simde_test_arm_neon_assert_equal_u32x4(r6, simde_vld1q_u32(test_vec[i].r6));
    simde_test_arm_neon_assert_equal_u32x4(r13, simde_vld1q_u32(test_vec[i].r13));
    simde_test_arm_neon_assert_equal_u32x4(r19, simde_vld1q_u32(test_vec[i].r19));
    simde_test_arm_neon_assert_equal_u32x4(r26, simde_vld1q_u32(test_vec[i].r26));
    simde_test_arm_neon_assert_equal_u32x4(r31, simde_vld1q_u32(test_vec[i].r31));
  }

  return 0;
}

static int
test_simde_vshlq_n_u64 (SIMDE_MUNIT_TEST_ARGS) {
  struct {
    uint64_t a[2];
    uint64_t r13[2];
    uint64_t r26[2];
    uint64_t r39[2];
    uint64_t r52[2];
    uint64_t r63[2];
  } test_vec[] = {
    { { UINT64_C(13917611607917708200), UINT64_C(17112162255472035057) },
      { UINT64_C(12195916536836587520), UINT64_C( 6024980708028456960) },
      { UINT64_C( 1382366554393411584), UINT64_C(11601562996068843520) },
      { UINT64_C(16492696406872555520), UINT64_C( 2378596044356190208) },
      { UINT64_C( 4215369251218784256), UINT64_C( 5697053528623677440) },
      { UINT64_C(                   0), UINT64_C( 9223372036854775808) } },
    { { UINT64_C( 8092300662856394291), UINT64_C(10892570253513852943) },
      { UINT64_C(12975573281163075584), UINT64_C( 5034432252382142464) },
      { UINT64_C( 5756966573478772736), UINT64_C(13596006773663203328) },
      { UINT64_C(11192317536492322816), UINT64_C(15493516864398557184) },
      { UINT64_C( 7147212608636977152), UINT64_C( 9290926031265333248) },
      { UINT64_C( 9223372036854775808), UINT64_C( 9223372036854775808) } },
    { { UINT64_C( 3366027571197309937), UINT64_C(14439360183432903052) },
      { UINT64_C(15062217126292889600), UINT64_C( 6715622056696840192) },
      { UINT64_C(17858333621870395392), UINT64_C( 6185060658631933952) },
      { UINT64_C(12788525845534736384), UINT64_C(13257689106374197248) },
      { UINT64_C( 4544132024016830464), UINT64_C(11006797489293492224) },
      { UINT64_C( 9223372036854775808), UINT64_C(                   0) } },
    { { UINT64_C( 5157481632533420175), UINT64_C( 6961892599648108823) },
      { UINT64_C( 7045604918904872960), UINT64_C(12938244481083432960) },
      { UINT64_C(16180033105241833472), UINT64_C(13554085574108774400) },
      { UINT64_C( 6975028537971441664), UINT64_C( 4116443441288708096) },
      { UINT64_C( 9867386783568756736), UINT64_C( 1256504296036368384) },
      { UINT64_C( 9223372036854775808), UINT64_C( 9223372036854775808) } },
    { { UINT64_C( 1511815881612918927), UINT64_C(16312859544596867589) },
      { UINT64_C( 7030428713922715648), UINT64_C( 6731319385547382784) },
      { UINT64_C( 2537026333666443264), UINT64_C( 5650370086309986304) },
      { UINT64_C(12285898398548099072), UINT64_C( 4950866114142797824) },
      { UINT64_C(  644014746713980928), UINT64_C(11551733044205322240) },
      { UINT64_C( 9223372036854775808), UINT64_C( 9223372036854775808) } },
    { { UINT64_C( 5261216133352334211), UINT64_C(11648819999460521433) },
      { UINT64_C( 8288408236809281536), UINT64_C( 2126342281081069568) },
      { UINT64_C(14622084690484396032), UINT64_C( 5269561034305175552) },
      { UINT64_C( 9408513852053651456), UINT64_C( 2862860547647340544) },
      { UINT64_C( 4048736065006075904), UINT64_C( 6741888642173632512) },
      { UINT64_C( 9223372036854775808), UINT64_C( 9223372036854775808) } },
    { { UINT64_C( 1047484977181031916), UINT64_C( 9298256467379884756) },
      { UINT64_C( 3260938792071954432), UINT64_C( 4710700429277298688) },
      { UINT64_C( 2725165922019966976), UINT64_C(17916058512958423040) },
      { UINT64_C( 3998903999012012032), UINT64_C( 6055487722208886784) },
      { UINT64_C(16050829071948447744), UINT64_C( 3260606130216239104) },
      { UINT64_C(                   0), UINT64_C(                   0) } },
    { { UINT64_C( 9271012395537207086), UINT64_C(15089716154388248757) },
      { UINT64_C( 2888192778576445440), UINT64_C( 3322698820828438528) },
      { UINT64_C(11349339602595872768), UINT64_C(10601231504979787776) },
      { UINT64_C( 2199892969249570816), UINT64_C(16464133843562004480) },
      { UINT64_C(17500988151961747456), UINT64_C(10038523569408835584) },
      { UINT64_C(                   0), UINT64_C( 9223372036854775808) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint64x2_t a = simde_vld1q_u64(test_vec[i].a);

    simde_uint64x2_t r13 = simde_vshlq_n_u64(a, 13);
    simde_uint64x2_t r26 = simde_vshlq_n_u64(a, 26);
    simde_uint64x2_t r39 = simde_vshlq_n_u64(a, 39);
    simde_uint64x2_t r52 = simde_vshlq_n_u64(a, 52);
    simde_uint64x2_t r63 = simde_vshlq_n_u64(a, 63);

    simde_test_arm_neon_assert_equal_u64x2(r13, simde_vld1q_u64(test_vec[i].r13));
    simde_test_arm_neon_assert_equal_u64x2(r26, simde_vld1q_u64(test_vec[i].r26));
    simde_test_arm_neon_assert_equal_u64x2(r39, simde_vld1q_u64(test_vec[i].r39));
    simde_test_arm_neon_assert_equal_u64x2(r52, simde_vld1q_u64(test_vec[i].r52));
    simde_test_arm_neon_assert_equal_u64x2(r63, simde_vld1q_u64(test_vec[i].r63));
  }

  return 0;
}

SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(vshl_n_s8)
SIMDE_TEST_FUNC_LIST_ENTRY(vshl_n_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vshl_n_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vshl_n_s64)
SIMDE_TEST_FUNC_LIST_ENTRY(vshl_n_u8)
SIMDE_TEST_FUNC_LIST_ENTRY(vshl_n_u16)
SIMDE_TEST_FUNC_LIST_ENTRY(vshl_n_u32)
SIMDE_TEST_FUNC_LIST_ENTRY(vshl_n_u64)

SIMDE_TEST_FUNC_LIST_ENTRY(vshlq_n_s8)
SIMDE_TEST_FUNC_LIST_ENTRY(vshlq_n_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vshlq_n_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vshlq_n_s64)
SIMDE_TEST_FUNC_LIST_ENTRY(vshlq_n_u8)
SIMDE_TEST_FUNC_LIST_ENTRY(vshlq_n_u16)
SIMDE_TEST_FUNC_LIST_ENTRY(vshlq_n_u32)
SIMDE_TEST_FUNC_LIST_ENTRY(vshlq_n_u64)
SIMDE_TEST_FUNC_LIST_END

#include "test-neon-footer.h"
