#define SIMDE_TEST_ARM_NEON_INSN shl

#include <test/arm/neon/test-neon.h>
#include <simde/arm/neon/shl.h>

static int
test_simde_vshl_n_s8 (void) {
  struct {
    int8_t a[8];
    int8_t r1[8];
    int8_t r3[8];
    int8_t r5[8];
    int8_t r6[8];
    int8_t r8[8];
  } test_vec[] = {
    { { -INT8_C(  31), -INT8_C( 123),  INT8_C(  83),      INT8_MAX,  INT8_C(  62),  INT8_C(  27), -INT8_C(  48), -INT8_C( 104) },
      { -INT8_C(  62),  INT8_C(  10), -INT8_C(  90), -INT8_C(   2),  INT8_C( 124),  INT8_C(  54), -INT8_C(  96),  INT8_C(  48) },
      {  INT8_C(   8),  INT8_C(  40), -INT8_C( 104), -INT8_C(   8), -INT8_C(  16), -INT8_C(  40),      INT8_MIN, -INT8_C(  64) },
      {  INT8_C(  32), -INT8_C(  96),  INT8_C(  96), -INT8_C(  32), -INT8_C(  64),  INT8_C(  96),  INT8_C(   0),  INT8_C(   0) },
      {  INT8_C(  64),  INT8_C(  64), -INT8_C(  64), -INT8_C(  64),      INT8_MIN, -INT8_C(  64),  INT8_C(   0),  INT8_C(   0) },
      {  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0) } },
    { { -INT8_C( 124), -INT8_C(  51),  INT8_C(   7),  INT8_C(  58),  INT8_C(  62), -INT8_C(   3), -INT8_C(  37), -INT8_C(  95) },
      {  INT8_C(   8), -INT8_C( 102),  INT8_C(  14),  INT8_C( 116),  INT8_C( 124), -INT8_C(   6), -INT8_C(  74),  INT8_C(  66) },
      {  INT8_C(  32),  INT8_C( 104),  INT8_C(  56), -INT8_C(  48), -INT8_C(  16), -INT8_C(  24), -INT8_C(  40),  INT8_C(   8) },
      {      INT8_MIN, -INT8_C(  96), -INT8_C(  32),  INT8_C(  64), -INT8_C(  64), -INT8_C(  96),  INT8_C(  96),  INT8_C(  32) },
      {  INT8_C(   0),  INT8_C(  64), -INT8_C(  64),      INT8_MIN,      INT8_MIN,  INT8_C(  64), -INT8_C(  64),  INT8_C(  64) },
      {  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0) } },
    { {  INT8_C( 122),      INT8_MAX, -INT8_C( 122),  INT8_C(  32),  INT8_C( 119), -INT8_C(  85), -INT8_C( 102), -INT8_C(   4) },
      { -INT8_C(  12), -INT8_C(   2),  INT8_C(  12),  INT8_C(  64), -INT8_C(  18),  INT8_C(  86),  INT8_C(  52), -INT8_C(   8) },
      { -INT8_C(  48), -INT8_C(   8),  INT8_C(  48),  INT8_C(   0), -INT8_C(  72),  INT8_C(  88), -INT8_C(  48), -INT8_C(  32) },
      {  INT8_C(  64), -INT8_C(  32), -INT8_C(  64),  INT8_C(   0), -INT8_C(  32),  INT8_C(  96),  INT8_C(  64),      INT8_MIN },
      {      INT8_MIN, -INT8_C(  64),      INT8_MIN,  INT8_C(   0), -INT8_C(  64), -INT8_C(  64),      INT8_MIN,  INT8_C(   0) },
      {  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0) } },
    { {  INT8_C(  39),  INT8_C( 103), -INT8_C(  57),  INT8_C( 118), -INT8_C( 109), -INT8_C(  49),  INT8_C(  13),  INT8_C( 117) },
      {  INT8_C(  78), -INT8_C(  50), -INT8_C( 114), -INT8_C(  20),  INT8_C(  38), -INT8_C(  98),  INT8_C(  26), -INT8_C(  22) },
      {  INT8_C(  56),  INT8_C(  56),  INT8_C(  56), -INT8_C(  80), -INT8_C( 104),  INT8_C( 120),  INT8_C( 104), -INT8_C(  88) },
      { -INT8_C(  32), -INT8_C(  32), -INT8_C(  32), -INT8_C(  64),  INT8_C(  96), -INT8_C(  32), -INT8_C(  96), -INT8_C(  96) },
      { -INT8_C(  64), -INT8_C(  64), -INT8_C(  64),      INT8_MIN, -INT8_C(  64), -INT8_C(  64),  INT8_C(  64),  INT8_C(  64) },
      {  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0) } },
    { {  INT8_C(  84),  INT8_C(  96), -INT8_C(  12), -INT8_C( 110),  INT8_C( 123), -INT8_C(  59),  INT8_C(  42),  INT8_C(   0) },
      { -INT8_C(  88), -INT8_C(  64), -INT8_C(  24),  INT8_C(  36), -INT8_C(  10), -INT8_C( 118),  INT8_C(  84),  INT8_C(   0) },
      { -INT8_C(  96),  INT8_C(   0), -INT8_C(  96), -INT8_C( 112), -INT8_C(  40),  INT8_C(  40),  INT8_C(  80),  INT8_C(   0) },
      {      INT8_MIN,  INT8_C(   0),      INT8_MIN,  INT8_C(  64),  INT8_C(  96), -INT8_C(  96),  INT8_C(  64),  INT8_C(   0) },
      {  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),      INT8_MIN, -INT8_C(  64),  INT8_C(  64),      INT8_MIN,  INT8_C(   0) },
      {  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0) } },
    { { -INT8_C( 110),  INT8_C(  50),  INT8_C(  58), -INT8_C(  48),  INT8_C(  47),  INT8_C(  21),  INT8_C( 114), -INT8_C(  87) },
      {  INT8_C(  36),  INT8_C( 100),  INT8_C( 116), -INT8_C(  96),  INT8_C(  94),  INT8_C(  42), -INT8_C(  28),  INT8_C(  82) },
      { -INT8_C( 112), -INT8_C( 112), -INT8_C(  48),      INT8_MIN,  INT8_C( 120), -INT8_C(  88), -INT8_C( 112),  INT8_C(  72) },
      {  INT8_C(  64),  INT8_C(  64),  INT8_C(  64),  INT8_C(   0), -INT8_C(  32), -INT8_C(  96),  INT8_C(  64),  INT8_C(  32) },
      {      INT8_MIN,      INT8_MIN,      INT8_MIN,  INT8_C(   0), -INT8_C(  64),  INT8_C(  64),      INT8_MIN,  INT8_C(  64) },
      {  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0) } },
    { { -INT8_C( 107), -INT8_C(   8), -INT8_C(  55),  INT8_C(  12), -INT8_C(  93),  INT8_C(  99),  INT8_C(   8), -INT8_C(  54) },
      {  INT8_C(  42), -INT8_C(  16), -INT8_C( 110),  INT8_C(  24),  INT8_C(  70), -INT8_C(  58),  INT8_C(  16), -INT8_C( 108) },
      { -INT8_C(  88), -INT8_C(  64),  INT8_C(  72),  INT8_C(  96),  INT8_C(  24),  INT8_C(  24),  INT8_C(  64),  INT8_C(  80) },
      { -INT8_C(  96),  INT8_C(   0),  INT8_C(  32),      INT8_MIN,  INT8_C(  96),  INT8_C(  96),  INT8_C(   0),  INT8_C(  64) },
      {  INT8_C(  64),  INT8_C(   0),  INT8_C(  64),  INT8_C(   0), -INT8_C(  64), -INT8_C(  64),  INT8_C(   0),      INT8_MIN },
      {  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0) } },
    { { -INT8_C(  54), -INT8_C(  49),  INT8_C(  65),  INT8_C(  94), -INT8_C(  97),  INT8_C(  78), -INT8_C(  45), -INT8_C(  13) },
      { -INT8_C( 108), -INT8_C(  98), -INT8_C( 126), -INT8_C(  68),  INT8_C(  62), -INT8_C( 100), -INT8_C(  90), -INT8_C(  26) },
      {  INT8_C(  80),  INT8_C( 120),  INT8_C(   8), -INT8_C(  16), -INT8_C(   8),  INT8_C( 112), -INT8_C( 104), -INT8_C( 104) },
      {  INT8_C(  64), -INT8_C(  32),  INT8_C(  32), -INT8_C(  64), -INT8_C(  32), -INT8_C(  64),  INT8_C(  96),  INT8_C(  96) },
      {      INT8_MIN, -INT8_C(  64),  INT8_C(  64),      INT8_MIN, -INT8_C(  64),      INT8_MIN, -INT8_C(  64), -INT8_C(  64) },
      {  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int8x8_t a = simde_vld1_s8(test_vec[i].a);

    simde_int8x8_t r1 = simde_vshl_n_s8(a, 1);
    simde_int8x8_t r3 = simde_vshl_n_s8(a, 3);
    simde_int8x8_t r5 = simde_vshl_n_s8(a, 5);
    simde_int8x8_t r6 = simde_vshl_n_s8(a, 6);
    simde_int8x8_t r8 = simde_vshl_n_s8(a, 8);

    simde_test_arm_neon_assert_equal_i8x8(r1, simde_vld1_s8(test_vec[i].r1));
    simde_test_arm_neon_assert_equal_i8x8(r3, simde_vld1_s8(test_vec[i].r3));
    simde_test_arm_neon_assert_equal_i8x8(r5, simde_vld1_s8(test_vec[i].r5));
    simde_test_arm_neon_assert_equal_i8x8(r6, simde_vld1_s8(test_vec[i].r6));
    simde_test_arm_neon_assert_equal_i8x8(r8, simde_vld1_s8(test_vec[i].r8));
  }

  return 0;
}

static int
test_simde_vshl_n_s16 (void) {
  struct {
    int16_t a[4];
    int16_t r3[4];
    int16_t r6[4];
    int16_t r10[4];
    int16_t r13[4];
    int16_t r16[4];
  } test_vec[] = {
    { {  INT16_C( 19587),  INT16_C( 22202),  INT16_C( 21741),  INT16_C( 15319) },
      {  INT16_C( 25624), -INT16_C( 18992), -INT16_C( 22680), -INT16_C(  8520) },
      {  INT16_C(  8384), -INT16_C( 20864),  INT16_C( 15168), -INT16_C(  2624) },
      {  INT16_C(  3072), -INT16_C(  6144), -INT16_C( 19456),  INT16_C( 23552) },
      {  INT16_C( 24576),  INT16_C( 16384), -INT16_C( 24576), -INT16_C(  8192) },
      {  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0) } },
    { {  INT16_C(  2935),  INT16_C( 25420), -INT16_C( 11877),  INT16_C(  4215) },
      {  INT16_C( 23480),  INT16_C(  6752), -INT16_C( 29480), -INT16_C( 31816) },
      { -INT16_C(  8768), -INT16_C( 11520),  INT16_C( 26304),  INT16_C(  7616) },
      { -INT16_C(  9216),  INT16_C( 12288),  INT16_C( 27648), -INT16_C(  9216) },
      { -INT16_C(  8192),       INT16_MIN,  INT16_C( 24576), -INT16_C(  8192) },
      {  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0) } },
    { { -INT16_C( 16615),  INT16_C( 22493),  INT16_C( 24551), -INT16_C(   432) },
      { -INT16_C(  1848), -INT16_C( 16664), -INT16_C(   200), -INT16_C(  3456) },
      { -INT16_C( 14784), -INT16_C(  2240), -INT16_C(  1600), -INT16_C( 27648) },
      {  INT16_C( 25600),  INT16_C( 29696), -INT16_C( 25600),  INT16_C( 16384) },
      {  INT16_C(  8192), -INT16_C( 24576), -INT16_C(  8192),  INT16_C(     0) },
      {  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0) } },
    { {  INT16_C( 12169), -INT16_C(   872),  INT16_C( 25801),  INT16_C( 19625) },
      {  INT16_C( 31816), -INT16_C(  6976),  INT16_C(  9800),  INT16_C( 25928) },
      { -INT16_C(  7616),  INT16_C(  9728),  INT16_C( 12864),  INT16_C( 10816) },
      {  INT16_C(  9216),  INT16_C( 24576),  INT16_C(  9216), -INT16_C( 23552) },
      {  INT16_C(  8192),  INT16_C(     0),  INT16_C(  8192),  INT16_C(  8192) },
      {  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0) } },
    { {  INT16_C( 25777), -INT16_C( 24926),  INT16_C( 31160),  INT16_C( 12249) },
      {  INT16_C(  9608), -INT16_C(  2800), -INT16_C( 12864),  INT16_C( 32456) },
      {  INT16_C( 11328), -INT16_C( 22400),  INT16_C( 28160), -INT16_C(  2496) },
      { -INT16_C( 15360), -INT16_C( 30720), -INT16_C(  8192),  INT16_C( 25600) },
      {  INT16_C(  8192),  INT16_C( 16384),  INT16_C(     0),  INT16_C(  8192) },
      {  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0) } },
    { {  INT16_C(  9604),  INT16_C(  8083),  INT16_C(  2807),  INT16_C(  4143) },
      {  INT16_C( 11296), -INT16_C(   872),  INT16_C( 22456), -INT16_C( 32392) },
      {  INT16_C( 24832), -INT16_C(  6976), -INT16_C( 16960),  INT16_C(  3008) },
      {  INT16_C(  4096),  INT16_C( 19456), -INT16_C(  9216), -INT16_C( 17408) },
      {       INT16_MIN,  INT16_C( 24576), -INT16_C(  8192), -INT16_C(  8192) },
      {  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0) } },
    { {  INT16_C(  3530), -INT16_C( 20121), -INT16_C( 18580), -INT16_C(  2641) },
      {  INT16_C( 28240), -INT16_C( 29896), -INT16_C( 17568), -INT16_C( 21128) },
      {  INT16_C( 29312),  INT16_C( 22976), -INT16_C(  9472),  INT16_C( 27584) },
      {  INT16_C( 10240), -INT16_C( 25600), -INT16_C( 20480), -INT16_C( 17408) },
      {  INT16_C( 16384), -INT16_C(  8192),       INT16_MIN, -INT16_C(  8192) },
      {  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0) } },
    { {  INT16_C( 18406), -INT16_C( 20495), -INT16_C( 25685),  INT16_C( 23803) },
      {  INT16_C( 16176),  INT16_C( 32648), -INT16_C(  8872), -INT16_C(  6184) },
      { -INT16_C(  1664), -INT16_C(   960), -INT16_C(  5440),  INT16_C( 16064) },
      { -INT16_C( 26624), -INT16_C( 15360), -INT16_C( 21504), -INT16_C(  5120) },
      { -INT16_C( 16384),  INT16_C(  8192),  INT16_C( 24576),  INT16_C( 24576) },
      {  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x4_t a = simde_vld1_s16(test_vec[i].a);

    simde_int16x4_t r3 = simde_vshl_n_s16(a, 3);
    simde_int16x4_t r6 = simde_vshl_n_s16(a, 6);
    simde_int16x4_t r10 = simde_vshl_n_s16(a, 10);
    simde_int16x4_t r13 = simde_vshl_n_s16(a, 13);
    simde_int16x4_t r16 = simde_vshl_n_s16(a, 16);

    simde_test_arm_neon_assert_equal_i16x4(r3, simde_vld1_s16(test_vec[i].r3));
    simde_test_arm_neon_assert_equal_i16x4(r6, simde_vld1_s16(test_vec[i].r6));
    simde_test_arm_neon_assert_equal_i16x4(r10, simde_vld1_s16(test_vec[i].r10));
    simde_test_arm_neon_assert_equal_i16x4(r13, simde_vld1_s16(test_vec[i].r13));
    simde_test_arm_neon_assert_equal_i16x4(r16, simde_vld1_s16(test_vec[i].r16));
  }

  return 0;
}

static int
test_simde_vshl_n_s32 (void) {
  struct {
    int32_t a[2];
    int32_t r6[2];
    int32_t r13[2];
    int32_t r19[2];
    int32_t r26[2];
    int32_t r32[2];
  } test_vec[] = {
    { {  INT32_C(    66388437), -INT32_C(   997872981) },
      { -INT32_C(    46107328),  INT32_C(   560638656) },
      { -INT32_C(  1606770688), -INT32_C(  1252696064) },
      {  INT32_C(   245891072),  INT32_C(  1431830528) },
      {  INT32_C(  1409286144), -INT32_C(  1409286144) },
      {  INT32_C(           0),  INT32_C(           0) } },
    { { -INT32_C(   909353500),  INT32_C(  1473130333) },
      {  INT32_C(  1930918144), -INT32_C(   208939200) },
      { -INT32_C(  1950580736), -INT32_C(   974413824) },
      { -INT32_C(   283115520),  INT32_C(  2062024704) },
      { -INT32_C(  1879048192),  INT32_C(  1946157056) },
      {  INT32_C(           0),  INT32_C(           0) } },
    { { -INT32_C(   411335898),  INT32_C(   762947181) },
      { -INT32_C(   555693696),  INT32_C(  1583979328) },
      {  INT32_C(  1885650944),  INT32_C(   885891072) },
      {  INT32_C(   422576128),  INT32_C(   862453760) },
      { -INT32_C(  1744830464), -INT32_C(  1275068416) },
      {  INT32_C(           0),  INT32_C(           0) } },
    { { -INT32_C(    17936351),  INT32_C(  1545531527) },
      { -INT32_C(  1147926464),  INT32_C(   129769920) },
      { -INT32_C(   905699328), -INT32_C(   569319424) },
      { -INT32_C(  2130182144), -INT32_C(  2076704768) },
      { -INT32_C(  2080374784),  INT32_C(   469762048) },
      {  INT32_C(           0),  INT32_C(           0) } },
    { { -INT32_C(  1671425039), -INT32_C(  1570708035) },
      {  INT32_C(   402979904), -INT32_C(  1741066432) },
      {  INT32_C(    41820160),  INT32_C(   481796096) },
      { -INT32_C(  1618477056),  INT32_C(   770179072) },
      { -INT32_C(  1006632960), -INT32_C(   201326592) },
      {  INT32_C(           0),  INT32_C(           0) } },
    { { -INT32_C(  1603589054), -INT32_C(  2097726884) },
      {  INT32_C(   449515648), -INT32_C(  1110534400) },
      {  INT32_C(  1703428096), -INT32_C(   414482432) },
      {  INT32_C(  1645215744), -INT32_C(   757071872) },
      {  INT32_C(   134217728),  INT32_C(  1879048192) },
      {  INT32_C(           0),  INT32_C(           0) } },
    { {  INT32_C(   728330941),  INT32_C(   978903832) },
      { -INT32_C(   631460032), -INT32_C(  1774664192) },
      {  INT32_C(   777494528),  INT32_C(   476250112) },
      { -INT32_C(  1779957760),  INT32_C(   415236096) },
      { -INT32_C(   201326592),  INT32_C(  1610612736) },
      {  INT32_C(           0),  INT32_C(           0) } },
    { { -INT32_C(  1153939917),  INT32_C(   655840822) },
      { -INT32_C(   837710656), -INT32_C(   975860352) },
      {  INT32_C(   147218432), -INT32_C(   356073472) },
      {  INT32_C(   832045056), -INT32_C(  1313865728) },
      { -INT32_C(   872415232), -INT32_C(   671088640) },
      {  INT32_C(           0),  INT32_C(           0) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x2_t a = simde_vld1_s32(test_vec[i].a);

    simde_int32x2_t r6 = simde_vshl_n_s32(a, 6);
    simde_int32x2_t r13 = simde_vshl_n_s32(a, 13);
    simde_int32x2_t r19 = simde_vshl_n_s32(a, 19);
    simde_int32x2_t r26 = simde_vshl_n_s32(a, 26);
    simde_int32x2_t r32 = simde_vshl_n_s32(a, 32);

    simde_test_arm_neon_assert_equal_i32x2(r6, simde_vld1_s32(test_vec[i].r6));
    simde_test_arm_neon_assert_equal_i32x2(r13, simde_vld1_s32(test_vec[i].r13));
    simde_test_arm_neon_assert_equal_i32x2(r19, simde_vld1_s32(test_vec[i].r19));
    simde_test_arm_neon_assert_equal_i32x2(r26, simde_vld1_s32(test_vec[i].r26));
    simde_test_arm_neon_assert_equal_i32x2(r32, simde_vld1_s32(test_vec[i].r32));
  }

  return 0;
}

static int
test_simde_vshl_n_s64 (void) {
  struct {
    int64_t a[1];
    int64_t r13[1];
    int64_t r26[1];
    int64_t r39[1];
    int64_t r52[1];
    int64_t r64[1];
  } test_vec[] = {
    { { -INT64_C( 3577949327508187091) },
      {  INT64_C( 1315442177408868352) },
      {  INT64_C( 3203778287071395840) },
      { -INT64_C( 4365089199817228288) },
      { -INT64_C( 9020710053623103488) },
      { -INT64_C( 3577949327508187091) } },
    { { -INT64_C( 8101431072389674989) },
      {  INT64_C( 4461832190749204480) },
      {  INT64_C( 8329296598861348864) },
      { -INT64_C(  908590779461533696) },
      { -INT64_C( 9137803643934736384) },
      { -INT64_C( 8101431072389674989) } },
    { {  INT64_C( 8086440410904812075) },
      {  INT64_C( 1861877441220665344) },
      { -INT64_C( 2957350478108688384) },
      { -INT64_C( 6040147885733969920) },
      { -INT64_C( 6723874243664150528) },
      {  INT64_C( 8086440410904812075) } },
    { { -INT64_C( 7006487826370312177) },
      {  INT64_C( 9119283758527275008) },
      { -INT64_C( 4140948668247179264) },
      {  INT64_C(  910861270972891136) },
      { -INT64_C( 9155818042444218368) },
      { -INT64_C( 7006487826370312177) } },
    { { -INT64_C( 1106456294216480052) },
      { -INT64_C( 6738622030014742528) },
      {  INT64_C( 8313342731917197312) },
      { -INT64_C( 2475460269984186368) },
      { -INT64_C( 5998794703657500672) },
      { -INT64_C( 1106456294216480052) } },
    { { -INT64_C( 6429057263627563812) },
      { -INT64_C( 1382773196232884224) },
      { -INT64_C( 1377162282122870784) },
      {  INT64_C( 7693957959688126464) },
      { -INT64_C( 3620894100405878784) },
      { -INT64_C( 6429057263627563812) } },
    { { -INT64_C(  150980614002892607) },
      { -INT64_C(  901336973156278272) },
      { -INT64_C( 5054854612410957824) },
      {  INT64_C( 3571460607376883712) },
      {  INT64_C(  869194728082505728) },
      { -INT64_C(  150980614002892607) } },
    { { -INT64_C( 4543459173020532509) },
      {  INT64_C( 5511995361672847360) },
      { -INT64_C( 3363489617016782848) },
      {  INT64_C( 5728703520585023488) },
      {  INT64_C( 1022317115413102592) },
      { -INT64_C( 4543459173020532509) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int64x1_t a = simde_vld1_s64(test_vec[i].a);

    simde_int64x1_t r13 = simde_vshl_n_s64(a, 13);
    simde_int64x1_t r26 = simde_vshl_n_s64(a, 26);
    simde_int64x1_t r39 = simde_vshl_n_s64(a, 39);
    simde_int64x1_t r52 = simde_vshl_n_s64(a, 52);
    simde_int64x1_t r64 = simde_vshl_n_s64(a, 64);

    simde_test_arm_neon_assert_equal_i64x1(r13, simde_vld1_s64(test_vec[i].r13));
    simde_test_arm_neon_assert_equal_i64x1(r26, simde_vld1_s64(test_vec[i].r26));
    simde_test_arm_neon_assert_equal_i64x1(r39, simde_vld1_s64(test_vec[i].r39));
    simde_test_arm_neon_assert_equal_i64x1(r52, simde_vld1_s64(test_vec[i].r52));
    simde_test_arm_neon_assert_equal_i64x1(r64, simde_vld1_s64(test_vec[i].r64));
  }

  return 0;
}

static int
test_simde_vshl_n_u8 (void) {
  struct {
    uint8_t a[8];
    uint8_t r1[8];
    uint8_t r3[8];
    uint8_t r5[8];
    uint8_t r6[8];
    uint8_t r8[8];
  } test_vec[] = {
    { { UINT8_C(198), UINT8_C( 13), UINT8_C(183), UINT8_C( 66), UINT8_C( 52), UINT8_C(210), UINT8_C(105), UINT8_C(103) },
      { UINT8_C(140), UINT8_C( 26), UINT8_C(110), UINT8_C(132), UINT8_C(104), UINT8_C(164), UINT8_C(210), UINT8_C(206) },
      { UINT8_C( 48), UINT8_C(104), UINT8_C(184), UINT8_C( 16), UINT8_C(160), UINT8_C(144), UINT8_C( 72), UINT8_C( 56) },
      { UINT8_C(192), UINT8_C(160), UINT8_C(224), UINT8_C( 64), UINT8_C(128), UINT8_C( 64), UINT8_C( 32), UINT8_C(224) },
      { UINT8_C(128), UINT8_C( 64), UINT8_C(192), UINT8_C(128), UINT8_C(  0), UINT8_C(128), UINT8_C( 64), UINT8_C(192) },
      { UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0) } },
    { { UINT8_C(136), UINT8_C( 58), UINT8_C( 52), UINT8_C( 25), UINT8_C( 30), UINT8_C(191), UINT8_C( 51), UINT8_C(246) },
      { UINT8_C( 16), UINT8_C(116), UINT8_C(104), UINT8_C( 50), UINT8_C( 60), UINT8_C(126), UINT8_C(102), UINT8_C(236) },
      { UINT8_C( 64), UINT8_C(208), UINT8_C(160), UINT8_C(200), UINT8_C(240), UINT8_C(248), UINT8_C(152), UINT8_C(176) },
      { UINT8_C(  0), UINT8_C( 64), UINT8_C(128), UINT8_C( 32), UINT8_C(192), UINT8_C(224), UINT8_C( 96), UINT8_C(192) },
      { UINT8_C(  0), UINT8_C(128), UINT8_C(  0), UINT8_C( 64), UINT8_C(128), UINT8_C(192), UINT8_C(192), UINT8_C(128) },
      { UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0) } },
    { { UINT8_C( 12), UINT8_C(246), UINT8_C(206), UINT8_C(178), UINT8_C( 27), UINT8_C( 62), UINT8_C(112), UINT8_C(209) },
      { UINT8_C( 24), UINT8_C(236), UINT8_C(156), UINT8_C(100), UINT8_C( 54), UINT8_C(124), UINT8_C(224), UINT8_C(162) },
      { UINT8_C( 96), UINT8_C(176), UINT8_C(112), UINT8_C(144), UINT8_C(216), UINT8_C(240), UINT8_C(128), UINT8_C(136) },
      { UINT8_C(128), UINT8_C(192), UINT8_C(192), UINT8_C( 64), UINT8_C( 96), UINT8_C(192), UINT8_C(  0), UINT8_C( 32) },
      { UINT8_C(  0), UINT8_C(128), UINT8_C(128), UINT8_C(128), UINT8_C(192), UINT8_C(128), UINT8_C(  0), UINT8_C( 64) },
      { UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0) } },
    { { UINT8_C(237), UINT8_C(  0), UINT8_C(205), UINT8_C( 29), UINT8_C( 88), UINT8_C( 69), UINT8_C(153), UINT8_C( 30) },
      { UINT8_C(218), UINT8_C(  0), UINT8_C(154), UINT8_C( 58), UINT8_C(176), UINT8_C(138), UINT8_C( 50), UINT8_C( 60) },
      { UINT8_C(104), UINT8_C(  0), UINT8_C(104), UINT8_C(232), UINT8_C(192), UINT8_C( 40), UINT8_C(200), UINT8_C(240) },
      { UINT8_C(160), UINT8_C(  0), UINT8_C(160), UINT8_C(160), UINT8_C(  0), UINT8_C(160), UINT8_C( 32), UINT8_C(192) },
      { UINT8_C( 64), UINT8_C(  0), UINT8_C( 64), UINT8_C( 64), UINT8_C(  0), UINT8_C( 64), UINT8_C( 64), UINT8_C(128) },
      { UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0) } },
    { { UINT8_C( 82), UINT8_C( 81), UINT8_C( 97), UINT8_C(134), UINT8_C( 35), UINT8_C(202), UINT8_C(238), UINT8_C(172) },
      { UINT8_C(164), UINT8_C(162), UINT8_C(194), UINT8_C( 12), UINT8_C( 70), UINT8_C(148), UINT8_C(220), UINT8_C( 88) },
      { UINT8_C(144), UINT8_C(136), UINT8_C(  8), UINT8_C( 48), UINT8_C( 24), UINT8_C( 80), UINT8_C(112), UINT8_C( 96) },
      { UINT8_C( 64), UINT8_C( 32), UINT8_C( 32), UINT8_C(192), UINT8_C( 96), UINT8_C( 64), UINT8_C(192), UINT8_C(128) },
      { UINT8_C(128), UINT8_C( 64), UINT8_C( 64), UINT8_C(128), UINT8_C(192), UINT8_C(128), UINT8_C(128), UINT8_C(  0) },
      { UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0) } },
    { { UINT8_C(  4), UINT8_C( 34), UINT8_C(197), UINT8_C( 34), UINT8_C(225), UINT8_C(249), UINT8_C( 24), UINT8_C(237) },
      { UINT8_C(  8), UINT8_C( 68), UINT8_C(138), UINT8_C( 68), UINT8_C(194), UINT8_C(242), UINT8_C( 48), UINT8_C(218) },
      { UINT8_C( 32), UINT8_C( 16), UINT8_C( 40), UINT8_C( 16), UINT8_C(  8), UINT8_C(200), UINT8_C(192), UINT8_C(104) },
      { UINT8_C(128), UINT8_C( 64), UINT8_C(160), UINT8_C( 64), UINT8_C( 32), UINT8_C( 32), UINT8_C(  0), UINT8_C(160) },
      { UINT8_C(  0), UINT8_C(128), UINT8_C( 64), UINT8_C(128), UINT8_C( 64), UINT8_C( 64), UINT8_C(  0), UINT8_C( 64) },
      { UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0) } },
    { { UINT8_C(239), UINT8_C(230), UINT8_C(160), UINT8_C( 11), UINT8_C( 37), UINT8_C( 16), UINT8_C(220), UINT8_C( 18) },
      { UINT8_C(222), UINT8_C(204), UINT8_C( 64), UINT8_C( 22), UINT8_C( 74), UINT8_C( 32), UINT8_C(184), UINT8_C( 36) },
      { UINT8_C(120), UINT8_C( 48), UINT8_C(  0), UINT8_C( 88), UINT8_C( 40), UINT8_C(128), UINT8_C(224), UINT8_C(144) },
      { UINT8_C(224), UINT8_C(192), UINT8_C(  0), UINT8_C( 96), UINT8_C(160), UINT8_C(  0), UINT8_C(128), UINT8_C( 64) },
      { UINT8_C(192), UINT8_C(128), UINT8_C(  0), UINT8_C(192), UINT8_C( 64), UINT8_C(  0), UINT8_C(  0), UINT8_C(128) },
      { UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0) } },
    { { UINT8_C( 16), UINT8_C(169), UINT8_C( 47), UINT8_C(105), UINT8_C(238), UINT8_C(201), UINT8_C(135), UINT8_C( 64) },
      { UINT8_C( 32), UINT8_C( 82), UINT8_C( 94), UINT8_C(210), UINT8_C(220), UINT8_C(146), UINT8_C( 14), UINT8_C(128) },
      { UINT8_C(128), UINT8_C( 72), UINT8_C(120), UINT8_C( 72), UINT8_C(112), UINT8_C( 72), UINT8_C( 56), UINT8_C(  0) },
      { UINT8_C(  0), UINT8_C( 32), UINT8_C(224), UINT8_C( 32), UINT8_C(192), UINT8_C( 32), UINT8_C(224), UINT8_C(  0) },
      { UINT8_C(  0), UINT8_C( 64), UINT8_C(192), UINT8_C( 64), UINT8_C(128), UINT8_C( 64), UINT8_C(192), UINT8_C(  0) },
      { UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint8x8_t a = simde_vld1_u8(test_vec[i].a);

    simde_uint8x8_t r1 = simde_vshl_n_u8(a, 1);
    simde_uint8x8_t r3 = simde_vshl_n_u8(a, 3);
    simde_uint8x8_t r5 = simde_vshl_n_u8(a, 5);
    simde_uint8x8_t r6 = simde_vshl_n_u8(a, 6);
    simde_uint8x8_t r8 = simde_vshl_n_u8(a, 8);

    simde_test_arm_neon_assert_equal_u8x8(r1, simde_vld1_u8(test_vec[i].r1));
    simde_test_arm_neon_assert_equal_u8x8(r3, simde_vld1_u8(test_vec[i].r3));
    simde_test_arm_neon_assert_equal_u8x8(r5, simde_vld1_u8(test_vec[i].r5));
    simde_test_arm_neon_assert_equal_u8x8(r6, simde_vld1_u8(test_vec[i].r6));
    simde_test_arm_neon_assert_equal_u8x8(r8, simde_vld1_u8(test_vec[i].r8));
  }

  return 0;
}

static int
test_simde_vshl_n_u16 (void) {
  struct {
    uint16_t a[4];
    uint16_t r3[4];
    uint16_t r6[4];
    uint16_t r10[4];
    uint16_t r13[4];
    uint16_t r16[4];
  } test_vec[] = {
    { { UINT16_C(13956), UINT16_C( 7631), UINT16_C( 6427), UINT16_C(26545) },
      { UINT16_C(46112), UINT16_C(61048), UINT16_C(51416), UINT16_C(15752) },
      { UINT16_C(41216), UINT16_C(29632), UINT16_C(18112), UINT16_C(60480) },
      { UINT16_C( 4096), UINT16_C(15360), UINT16_C(27648), UINT16_C(50176) },
      { UINT16_C(32768), UINT16_C(57344), UINT16_C(24576), UINT16_C( 8192) },
      { UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0) } },
    { { UINT16_C(65364), UINT16_C(53801), UINT16_C(42117), UINT16_C(61061) },
      { UINT16_C(64160), UINT16_C(37192), UINT16_C( 9256), UINT16_C(29736) },
      { UINT16_C(54528), UINT16_C(35392), UINT16_C( 8512), UINT16_C(41280) },
      { UINT16_C(20480), UINT16_C(41984), UINT16_C( 5120), UINT16_C( 5120) },
      { UINT16_C(32768), UINT16_C( 8192), UINT16_C(40960), UINT16_C(40960) },
      { UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0) } },
    { { UINT16_C(56748), UINT16_C(54790), UINT16_C(52466), UINT16_C(59296) },
      { UINT16_C(60768), UINT16_C(45104), UINT16_C(26512), UINT16_C(15616) },
      { UINT16_C(27392), UINT16_C(33152), UINT16_C(15488), UINT16_C(59392) },
      { UINT16_C(45056), UINT16_C( 6144), UINT16_C(51200), UINT16_C(32768) },
      { UINT16_C(32768), UINT16_C(49152), UINT16_C(16384), UINT16_C(    0) },
      { UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0) } },
    { { UINT16_C(42745), UINT16_C(46102), UINT16_C(38048), UINT16_C( 9266) },
      { UINT16_C(14280), UINT16_C(41136), UINT16_C(42240), UINT16_C( 8592) },
      { UINT16_C(48704), UINT16_C( 1408), UINT16_C(10240), UINT16_C( 3200) },
      { UINT16_C(58368), UINT16_C(22528), UINT16_C(32768), UINT16_C(51200) },
      { UINT16_C( 8192), UINT16_C(49152), UINT16_C(    0), UINT16_C(16384) },
      { UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0) } },
    { { UINT16_C(  714), UINT16_C(58946), UINT16_C(62235), UINT16_C(28493) },
      { UINT16_C( 5712), UINT16_C(12816), UINT16_C(39128), UINT16_C(31336) },
      { UINT16_C(45696), UINT16_C(36992), UINT16_C(50880), UINT16_C(54080) },
      { UINT16_C(10240), UINT16_C( 2048), UINT16_C(27648), UINT16_C(13312) },
      { UINT16_C(16384), UINT16_C(16384), UINT16_C(24576), UINT16_C(40960) },
      { UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0) } },
    { { UINT16_C(30451), UINT16_C(30785), UINT16_C(50715), UINT16_C(51047) },
      { UINT16_C(47000), UINT16_C(49672), UINT16_C(12504), UINT16_C(15160) },
      { UINT16_C(48320), UINT16_C( 4160), UINT16_C(34496), UINT16_C(55744) },
      { UINT16_C(52224), UINT16_C( 1024), UINT16_C(27648), UINT16_C(39936) },
      { UINT16_C(24576), UINT16_C( 8192), UINT16_C(24576), UINT16_C(57344) },
      { UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0) } },
    { { UINT16_C(28067), UINT16_C(38557), UINT16_C(15673), UINT16_C(12925) },
      { UINT16_C(27928), UINT16_C(46312), UINT16_C(59848), UINT16_C(37864) },
      { UINT16_C(26816), UINT16_C(42816), UINT16_C(20032), UINT16_C(40768) },
      { UINT16_C(35840), UINT16_C(29696), UINT16_C(58368), UINT16_C(62464) },
      { UINT16_C(24576), UINT16_C(40960), UINT16_C( 8192), UINT16_C(40960) },
      { UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0) } },
    { { UINT16_C(37860), UINT16_C(34023), UINT16_C( 6439), UINT16_C(62121) },
      { UINT16_C(40736), UINT16_C(10040), UINT16_C(51512), UINT16_C(38216) },
      { UINT16_C(63744), UINT16_C(14784), UINT16_C(18880), UINT16_C(43584) },
      { UINT16_C(36864), UINT16_C(39936), UINT16_C(39936), UINT16_C(41984) },
      { UINT16_C(32768), UINT16_C(57344), UINT16_C(57344), UINT16_C( 8192) },
      { UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint16x4_t a = simde_vld1_u16(test_vec[i].a);

    simde_uint16x4_t r3 = simde_vshl_n_u16(a, 3);
    simde_uint16x4_t r6 = simde_vshl_n_u16(a, 6);
    simde_uint16x4_t r10 = simde_vshl_n_u16(a, 10);
    simde_uint16x4_t r13 = simde_vshl_n_u16(a, 13);
    simde_uint16x4_t r16 = simde_vshl_n_u16(a, 16);

    simde_test_arm_neon_assert_equal_u16x4(r3, simde_vld1_u16(test_vec[i].r3));
    simde_test_arm_neon_assert_equal_u16x4(r6, simde_vld1_u16(test_vec[i].r6));
    simde_test_arm_neon_assert_equal_u16x4(r10, simde_vld1_u16(test_vec[i].r10));
    simde_test_arm_neon_assert_equal_u16x4(r13, simde_vld1_u16(test_vec[i].r13));
    simde_test_arm_neon_assert_equal_u16x4(r16, simde_vld1_u16(test_vec[i].r16));
  }

  return 0;
}

static int
test_simde_vshl_n_u32 (void) {
  struct {
    uint32_t a[2];
    uint32_t r6[2];
    uint32_t r13[2];
    uint32_t r19[2];
    uint32_t r26[2];
    uint32_t r32[2];
  } test_vec[] = {
    { { UINT32_C(1882795026), UINT32_C( 182225763) },
      { UINT32_C( 239797376), UINT32_C(3072514240) },
      { UINT32_C( 629293056), UINT32_C(2439798784) },
      { UINT32_C(1620049920), UINT32_C(1528299520) },
      { UINT32_C(1207959552), UINT32_C(2348810240) },
      { UINT32_C(         0), UINT32_C(         0) } },
    { { UINT32_C( 583658353), UINT32_C( 677310552) },
      { UINT32_C(2994396224), UINT32_C( 398202368) },
      { UINT32_C(1030627328), UINT32_C(3725262848) },
      { UINT32_C(1535639552), UINT32_C(2193620992) },
      { UINT32_C(3288334336), UINT32_C(1610612736) },
      { UINT32_C(         0), UINT32_C(         0) } },
    { { UINT32_C(2844834767), UINT32_C(2813336583) },
      { UINT32_C(1680798656), UINT32_C(3959882176) },
      { UINT32_C( 393863168), UINT32_C(  58777600) },
      { UINT32_C(3732406272), UINT32_C(3761766400) },
      { UINT32_C(1006632960), UINT32_C( 469762048) },
      { UINT32_C(         0), UINT32_C(         0) } },
    { { UINT32_C( 230011791), UINT32_C(3578803138) },
      { UINT32_C(1835852736), UINT32_C(1410134144) },
      { UINT32_C(3060916224), UINT32_C( 108544000) },
      { UINT32_C(2625110016), UINT32_C(2651848704) },
      { UINT32_C(1006632960), UINT32_C( 134217728) },
      { UINT32_C(         0), UINT32_C(         0) } },
    { { UINT32_C(3259337055), UINT32_C(2261524757) },
      { UINT32_C(2439141312), UINT32_C(3003663680) },
      { UINT32_C(2972442624), UINT32_C(2216861696) },
      { UINT32_C(1257766912), UINT32_C( 145227776) },
      { UINT32_C(2080374784), UINT32_C(1409286144) },
      { UINT32_C(         0), UINT32_C(         0) } },
    { { UINT32_C(1705547020), UINT32_C(1418528389) },
      { UINT32_C(1780826880), UINT32_C( 591503680) },
      { UINT32_C( 312573952), UINT32_C(2698027008) },
      { UINT32_C(2824863744), UINT32_C( 875036672) },
      { UINT32_C( 805306368), UINT32_C( 335544320) },
      { UINT32_C(         0), UINT32_C(         0) } },
    { { UINT32_C(3372031425), UINT32_C(3379539258) },
      { UINT32_C(1061646400), UINT32_C(1542147712) },
      { UINT32_C(2746753024), UINT32_C(4121378816) },
      { UINT32_C(3993501696), UINT32_C(1775239168) },
      { UINT32_C(  67108864), UINT32_C(3892314112) },
      { UINT32_C(         0), UINT32_C(         0) } },
    { { UINT32_C( 601236577), UINT32_C(3069716055) },
      { UINT32_C(4119402560), UINT32_C(3188299200) },
      { UINT32_C(3297517568), UINT32_C(  80404480) },
      { UINT32_C( 587726848), UINT32_C( 850919424) },
      { UINT32_C(2214592512), UINT32_C(1543503872) },
      { UINT32_C(         0), UINT32_C(         0) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint32x2_t a = simde_vld1_u32(test_vec[i].a);

    simde_uint32x2_t r6 = simde_vshl_n_u32(a, 6);
    simde_uint32x2_t r13 = simde_vshl_n_u32(a, 13);
    simde_uint32x2_t r19 = simde_vshl_n_u32(a, 19);
    simde_uint32x2_t r26 = simde_vshl_n_u32(a, 26);
    simde_uint32x2_t r32 = simde_vshl_n_u32(a, 32);

    simde_test_arm_neon_assert_equal_u32x2(r6, simde_vld1_u32(test_vec[i].r6));
    simde_test_arm_neon_assert_equal_u32x2(r13, simde_vld1_u32(test_vec[i].r13));
    simde_test_arm_neon_assert_equal_u32x2(r19, simde_vld1_u32(test_vec[i].r19));
    simde_test_arm_neon_assert_equal_u32x2(r26, simde_vld1_u32(test_vec[i].r26));
    simde_test_arm_neon_assert_equal_u32x2(r32, simde_vld1_u32(test_vec[i].r32));
  }

  return 0;
}

static int
test_simde_vshl_n_u64 (void) {
  struct {
    uint64_t a[1];
    uint64_t r13[1];
    uint64_t r26[1];
    uint64_t r39[1];
    uint64_t r52[1];
    uint64_t r64[1];
  } test_vec[] = {
    { { UINT64_C( 1353650336340954147) },
      { UINT64_C( 2610367005655851008) },
      { UINT64_C( 4350128903361134592) },
      { UINT64_C(15593170001270407168) },
      { UINT64_C(13992684042240131072) },
      { UINT64_C( 1353650336340954147) } },
    { { UINT64_C( 5537143454703954199) },
      { UINT64_C(18182247756714926080) },
      { UINT64_C( 9961971877754699776) },
      { UINT64_C(   77840475444215808) },
      { UINT64_C(10479876332891144192) },
      { UINT64_C( 5537143454703954199) } },
    { { UINT64_C(12676471166372670626) },
      { UINT64_C( 8929404013851721728) },
      { UINT64_C( 8337429214932238336) },
      { UINT64_C(10373567852136366080) },
      { UINT64_C(14564641194916184064) },
      { UINT64_C(12676471166372670626) } },
    { { UINT64_C(10203805911031257495) },
      { UINT64_C( 7380625190083026944) },
      { UINT64_C(12101227613956079616) },
      { UINT64_C(  453961413073829888) },
      { UINT64_C(11056337085194567680) },
      { UINT64_C(10203805911031257495) } },
    { { UINT64_C( 9575054596873931775) },
      { UINT64_C( 3291456178235629568) },
      { UINT64_C(12915920416622510080) },
      { UINT64_C(15142790247324057600) },
      { UINT64_C(13830554455654793216) },
      { UINT64_C( 9575054596873931775) } },
    { { UINT64_C( 7459627590091072406) },
      { UINT64_C(13652845900030197760) },
      { UINT64_C( 1504294146368602112) },
      { UINT64_C(  752605813608022016) },
      { UINT64_C( 4134304457926115328) },
      { UINT64_C( 7459627590091072406) } },
    { { UINT64_C( 2009239316006741207) },
      { UINT64_C( 5192762978303926272) },
      { UINT64_C(  922484291537993728) },
      { UINT64_C(12272990132038008832) },
      { UINT64_C( 5579959938312044544) },
      { UINT64_C( 2009239316006741207) } },
    { { UINT64_C( 2436643254336745177) },
      { UINT64_C( 1604451772881641472) },
      { UINT64_C( 9587142965206188032) },
      { UINT64_C(10085649187531128832) },
      { UINT64_C(17118182183635255296) },
      { UINT64_C( 2436643254336745177) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint64x1_t a = simde_vld1_u64(test_vec[i].a);

    simde_uint64x1_t r13 = simde_vshl_n_u64(a, 13);
    simde_uint64x1_t r26 = simde_vshl_n_u64(a, 26);
    simde_uint64x1_t r39 = simde_vshl_n_u64(a, 39);
    simde_uint64x1_t r52 = simde_vshl_n_u64(a, 52);
    simde_uint64x1_t r64 = simde_vshl_n_u64(a, 64);

    simde_test_arm_neon_assert_equal_u64x1(r13, simde_vld1_u64(test_vec[i].r13));
    simde_test_arm_neon_assert_equal_u64x1(r26, simde_vld1_u64(test_vec[i].r26));
    simde_test_arm_neon_assert_equal_u64x1(r39, simde_vld1_u64(test_vec[i].r39));
    simde_test_arm_neon_assert_equal_u64x1(r52, simde_vld1_u64(test_vec[i].r52));
    simde_test_arm_neon_assert_equal_u64x1(r64, simde_vld1_u64(test_vec[i].r64));
  }

  return 0;
}

static int
test_simde_vshlq_n_s8 (void) {
  struct {
    int8_t a[16];
    int8_t r1[16];
    int8_t r3[16];
    int8_t r5[16];
    int8_t r6[16];
    int8_t r8[16];
  } test_vec[] = {
    { { -INT8_C( 105),  INT8_C( 108),  INT8_C(  55), -INT8_C(  88),  INT8_C(  43), -INT8_C(  11),  INT8_C(  78),  INT8_C( 123),
        -INT8_C( 112), -INT8_C( 104), -INT8_C(  48),  INT8_C(  46),  INT8_C( 104),  INT8_C(   4),  INT8_C(  42),  INT8_C(   8) },
      {  INT8_C(  46), -INT8_C(  40),  INT8_C( 110),  INT8_C(  80),  INT8_C(  86), -INT8_C(  22), -INT8_C( 100), -INT8_C(  10),
         INT8_C(  32),  INT8_C(  48), -INT8_C(  96),  INT8_C(  92), -INT8_C(  48),  INT8_C(   8),  INT8_C(  84),  INT8_C(  16) },
      { -INT8_C(  72),  INT8_C(  96), -INT8_C(  72),  INT8_C(  64),  INT8_C(  88), -INT8_C(  88),  INT8_C( 112), -INT8_C(  40),
             INT8_MIN, -INT8_C(  64),      INT8_MIN,  INT8_C( 112),  INT8_C(  64),  INT8_C(  32),  INT8_C(  80),  INT8_C(  64) },
      { -INT8_C(  32),      INT8_MIN, -INT8_C(  32),  INT8_C(   0),  INT8_C(  96), -INT8_C(  96), -INT8_C(  64),  INT8_C(  96),
         INT8_C(   0),  INT8_C(   0),  INT8_C(   0), -INT8_C(  64),  INT8_C(   0),      INT8_MIN,  INT8_C(  64),  INT8_C(   0) },
      { -INT8_C(  64),  INT8_C(   0), -INT8_C(  64),  INT8_C(   0), -INT8_C(  64),  INT8_C(  64),      INT8_MIN, -INT8_C(  64),
         INT8_C(   0),  INT8_C(   0),  INT8_C(   0),      INT8_MIN,  INT8_C(   0),  INT8_C(   0),      INT8_MIN,  INT8_C(   0) },
      {  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
         INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0) } },
    { {  INT8_C( 119), -INT8_C(  23), -INT8_C(  86), -INT8_C(   8),  INT8_C( 112),  INT8_C(  98), -INT8_C(  84),  INT8_C( 107),
        -INT8_C(  89),  INT8_C( 107),  INT8_C(   2),  INT8_C(  48), -INT8_C(   9),  INT8_C(  18), -INT8_C(  77), -INT8_C( 113) },
      { -INT8_C(  18), -INT8_C(  46),  INT8_C(  84), -INT8_C(  16), -INT8_C(  32), -INT8_C(  60),  INT8_C(  88), -INT8_C(  42),
         INT8_C(  78), -INT8_C(  42),  INT8_C(   4),  INT8_C(  96), -INT8_C(  18),  INT8_C(  36),  INT8_C( 102),  INT8_C(  30) },
      { -INT8_C(  72),  INT8_C(  72),  INT8_C(  80), -INT8_C(  64),      INT8_MIN,  INT8_C(  16),  INT8_C(  96),  INT8_C(  88),
         INT8_C(  56),  INT8_C(  88),  INT8_C(  16),      INT8_MIN, -INT8_C(  72), -INT8_C( 112), -INT8_C( 104),  INT8_C( 120) },
      { -INT8_C(  32),  INT8_C(  32),  INT8_C(  64),  INT8_C(   0),  INT8_C(   0),  INT8_C(  64),      INT8_MIN,  INT8_C(  96),
        -INT8_C(  32),  INT8_C(  96),  INT8_C(  64),  INT8_C(   0), -INT8_C(  32),  INT8_C(  64),  INT8_C(  96), -INT8_C(  32) },
      { -INT8_C(  64),  INT8_C(  64),      INT8_MIN,  INT8_C(   0),  INT8_C(   0),      INT8_MIN,  INT8_C(   0), -INT8_C(  64),
        -INT8_C(  64), -INT8_C(  64),      INT8_MIN,  INT8_C(   0), -INT8_C(  64),      INT8_MIN, -INT8_C(  64), -INT8_C(  64) },
      {  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
         INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0) } },
    { {  INT8_C( 126), -INT8_C(  22),  INT8_C(  55), -INT8_C(  86), -INT8_C(  33), -INT8_C( 122),  INT8_C(  37),  INT8_C( 111),
         INT8_C(  30), -INT8_C(  11), -INT8_C(  99), -INT8_C( 122), -INT8_C(   7), -INT8_C(  57), -INT8_C( 114),  INT8_C( 112) },
      { -INT8_C(   4), -INT8_C(  44),  INT8_C( 110),  INT8_C(  84), -INT8_C(  66),  INT8_C(  12),  INT8_C(  74), -INT8_C(  34),
         INT8_C(  60), -INT8_C(  22),  INT8_C(  58),  INT8_C(  12), -INT8_C(  14), -INT8_C( 114),  INT8_C(  28), -INT8_C(  32) },
      { -INT8_C(  16),  INT8_C(  80), -INT8_C(  72),  INT8_C(  80), -INT8_C(   8),  INT8_C(  48),  INT8_C(  40),  INT8_C( 120),
        -INT8_C(  16), -INT8_C(  88), -INT8_C(  24),  INT8_C(  48), -INT8_C(  56),  INT8_C(  56),  INT8_C( 112),      INT8_MIN },
      { -INT8_C(  64),  INT8_C(  64), -INT8_C(  32),  INT8_C(  64), -INT8_C(  32), -INT8_C(  64), -INT8_C(  96), -INT8_C(  32),
        -INT8_C(  64), -INT8_C(  96), -INT8_C(  96), -INT8_C(  64),  INT8_C(  32), -INT8_C(  32), -INT8_C(  64),  INT8_C(   0) },
      {      INT8_MIN,      INT8_MIN, -INT8_C(  64),      INT8_MIN, -INT8_C(  64),      INT8_MIN,  INT8_C(  64), -INT8_C(  64),
             INT8_MIN,  INT8_C(  64),  INT8_C(  64),      INT8_MIN,  INT8_C(  64), -INT8_C(  64),      INT8_MIN,  INT8_C(   0) },
      {  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
         INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0) } },
    { { -INT8_C(  80),  INT8_C(  56),  INT8_C( 104),  INT8_C(  33), -INT8_C( 102),  INT8_C(  20), -INT8_C( 116),  INT8_C(  66),
             INT8_MAX, -INT8_C( 114),  INT8_C( 114),  INT8_C( 119), -INT8_C(  96),  INT8_C(  37),  INT8_C(   6),  INT8_C(  30) },
      {  INT8_C(  96),  INT8_C( 112), -INT8_C(  48),  INT8_C(  66),  INT8_C(  52),  INT8_C(  40),  INT8_C(  24), -INT8_C( 124),
        -INT8_C(   2),  INT8_C(  28), -INT8_C(  28), -INT8_C(  18),  INT8_C(  64),  INT8_C(  74),  INT8_C(  12),  INT8_C(  60) },
      {      INT8_MIN, -INT8_C(  64),  INT8_C(  64),  INT8_C(   8), -INT8_C(  48), -INT8_C(  96),  INT8_C(  96),  INT8_C(  16),
        -INT8_C(   8),  INT8_C( 112), -INT8_C( 112), -INT8_C(  72),  INT8_C(   0),  INT8_C(  40),  INT8_C(  48), -INT8_C(  16) },
      {  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(  32),  INT8_C(  64),      INT8_MIN,      INT8_MIN,  INT8_C(  64),
        -INT8_C(  32), -INT8_C(  64),  INT8_C(  64), -INT8_C(  32),  INT8_C(   0), -INT8_C(  96), -INT8_C(  64), -INT8_C(  64) },
      {  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(  64),      INT8_MIN,  INT8_C(   0),  INT8_C(   0),      INT8_MIN,
        -INT8_C(  64),      INT8_MIN,      INT8_MIN, -INT8_C(  64),  INT8_C(   0),  INT8_C(  64),      INT8_MIN,      INT8_MIN },
      {  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
         INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0) } },
    { {  INT8_C(  15),  INT8_C(  61), -INT8_C(  56), -INT8_C(  18), -INT8_C(  61), -INT8_C(  19),  INT8_C(  93), -INT8_C(  30),
        -INT8_C(  30), -INT8_C(   6),  INT8_C( 104), -INT8_C(  37), -INT8_C(  63), -INT8_C(   9),  INT8_C(  75),  INT8_C( 114) },
      {  INT8_C(  30),  INT8_C( 122), -INT8_C( 112), -INT8_C(  36), -INT8_C( 122), -INT8_C(  38), -INT8_C(  70), -INT8_C(  60),
        -INT8_C(  60), -INT8_C(  12), -INT8_C(  48), -INT8_C(  74), -INT8_C( 126), -INT8_C(  18), -INT8_C( 106), -INT8_C(  28) },
      {  INT8_C( 120), -INT8_C(  24),  INT8_C(  64),  INT8_C( 112),  INT8_C(  24),  INT8_C( 104), -INT8_C(  24),  INT8_C(  16),
         INT8_C(  16), -INT8_C(  48),  INT8_C(  64), -INT8_C(  40),  INT8_C(   8), -INT8_C(  72),  INT8_C(  88), -INT8_C( 112) },
      { -INT8_C(  32), -INT8_C(  96),  INT8_C(   0), -INT8_C(  64),  INT8_C(  96), -INT8_C(  96), -INT8_C(  96),  INT8_C(  64),
         INT8_C(  64),  INT8_C(  64),  INT8_C(   0),  INT8_C(  96),  INT8_C(  32), -INT8_C(  32),  INT8_C(  96),  INT8_C(  64) },
      { -INT8_C(  64),  INT8_C(  64),  INT8_C(   0),      INT8_MIN, -INT8_C(  64),  INT8_C(  64),  INT8_C(  64),      INT8_MIN,
             INT8_MIN,      INT8_MIN,  INT8_C(   0), -INT8_C(  64),  INT8_C(  64), -INT8_C(  64), -INT8_C(  64),      INT8_MIN },
      {  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
         INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0) } },
    { {  INT8_C(  47), -INT8_C(  77), -INT8_C( 109), -INT8_C(  54), -INT8_C(  56),  INT8_C(  31),  INT8_C(  12),  INT8_C(  71),
        -INT8_C(  83),  INT8_C( 126), -INT8_C(  66),  INT8_C(  77), -INT8_C(  92), -INT8_C(  60),  INT8_C( 107), -INT8_C(  77) },
      {  INT8_C(  94),  INT8_C( 102),  INT8_C(  38), -INT8_C( 108), -INT8_C( 112),  INT8_C(  62),  INT8_C(  24), -INT8_C( 114),
         INT8_C(  90), -INT8_C(   4),  INT8_C( 124), -INT8_C( 102),  INT8_C(  72), -INT8_C( 120), -INT8_C(  42),  INT8_C( 102) },
      {  INT8_C( 120), -INT8_C( 104), -INT8_C( 104),  INT8_C(  80),  INT8_C(  64), -INT8_C(   8),  INT8_C(  96),  INT8_C(  56),
         INT8_C( 104), -INT8_C(  16), -INT8_C(  16),  INT8_C( 104),  INT8_C(  32),  INT8_C(  32),  INT8_C(  88), -INT8_C( 104) },
      { -INT8_C(  32),  INT8_C(  96),  INT8_C(  96),  INT8_C(  64),  INT8_C(   0), -INT8_C(  32),      INT8_MIN, -INT8_C(  32),
        -INT8_C(  96), -INT8_C(  64), -INT8_C(  64), -INT8_C(  96),      INT8_MIN,      INT8_MIN,  INT8_C(  96),  INT8_C(  96) },
      { -INT8_C(  64), -INT8_C(  64), -INT8_C(  64),      INT8_MIN,  INT8_C(   0), -INT8_C(  64),  INT8_C(   0), -INT8_C(  64),
         INT8_C(  64),      INT8_MIN,      INT8_MIN,  INT8_C(  64),  INT8_C(   0),  INT8_C(   0), -INT8_C(  64), -INT8_C(  64) },
      {  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
         INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0) } },
    { {  INT8_C(   2),  INT8_C(  52), -INT8_C(  94), -INT8_C(  59),  INT8_C(  33), -INT8_C(   1), -INT8_C(  89),  INT8_C(   4),
        -INT8_C(   6),  INT8_C(  16), -INT8_C(  33), -INT8_C(  69),  INT8_C(   7),  INT8_C(  43),  INT8_C(  45),  INT8_C(  54) },
      {  INT8_C(   4),  INT8_C( 104),  INT8_C(  68), -INT8_C( 118),  INT8_C(  66), -INT8_C(   2),  INT8_C(  78),  INT8_C(   8),
        -INT8_C(  12),  INT8_C(  32), -INT8_C(  66),  INT8_C( 118),  INT8_C(  14),  INT8_C(  86),  INT8_C(  90),  INT8_C( 108) },
      {  INT8_C(  16), -INT8_C(  96),  INT8_C(  16),  INT8_C(  40),  INT8_C(   8), -INT8_C(   8),  INT8_C(  56),  INT8_C(  32),
        -INT8_C(  48),      INT8_MIN, -INT8_C(   8), -INT8_C(  40),  INT8_C(  56),  INT8_C(  88),  INT8_C( 104), -INT8_C(  80) },
      {  INT8_C(  64),      INT8_MIN,  INT8_C(  64), -INT8_C(  96),  INT8_C(  32), -INT8_C(  32), -INT8_C(  32),      INT8_MIN,
         INT8_C(  64),  INT8_C(   0), -INT8_C(  32),  INT8_C(  96), -INT8_C(  32),  INT8_C(  96), -INT8_C(  96), -INT8_C(  64) },
      {      INT8_MIN,  INT8_C(   0),      INT8_MIN,  INT8_C(  64),  INT8_C(  64), -INT8_C(  64), -INT8_C(  64),  INT8_C(   0),
             INT8_MIN,  INT8_C(   0), -INT8_C(  64), -INT8_C(  64), -INT8_C(  64), -INT8_C(  64),  INT8_C(  64),      INT8_MIN },
      {  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
         INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0) } },
    { { -INT8_C(  34), -INT8_C(  64),  INT8_C(   0), -INT8_C(  90), -INT8_C(  33),  INT8_C(  12), -INT8_C(  18), -INT8_C( 116),
        -INT8_C( 117), -INT8_C(  84), -INT8_C(  39),  INT8_C(  47),  INT8_C( 113),  INT8_C(  69), -INT8_C(  30),  INT8_C( 115) },
      { -INT8_C(  68),      INT8_MIN,  INT8_C(   0),  INT8_C(  76), -INT8_C(  66),  INT8_C(  24), -INT8_C(  36),  INT8_C(  24),
         INT8_C(  22),  INT8_C(  88), -INT8_C(  78),  INT8_C(  94), -INT8_C(  30), -INT8_C( 118), -INT8_C(  60), -INT8_C(  26) },
      { -INT8_C(  16),  INT8_C(   0),  INT8_C(   0),  INT8_C(  48), -INT8_C(   8),  INT8_C(  96),  INT8_C( 112),  INT8_C(  96),
         INT8_C(  88),  INT8_C(  96), -INT8_C(  56),  INT8_C( 120), -INT8_C( 120),  INT8_C(  40),  INT8_C(  16), -INT8_C( 104) },
      { -INT8_C(  64),  INT8_C(   0),  INT8_C(   0), -INT8_C(  64), -INT8_C(  32),      INT8_MIN, -INT8_C(  64),      INT8_MIN,
         INT8_C(  96),      INT8_MIN,  INT8_C(  32), -INT8_C(  32),  INT8_C(  32), -INT8_C(  96),  INT8_C(  64),  INT8_C(  96) },
      {      INT8_MIN,  INT8_C(   0),  INT8_C(   0),      INT8_MIN, -INT8_C(  64),  INT8_C(   0),      INT8_MIN,  INT8_C(   0),
        -INT8_C(  64),  INT8_C(   0),  INT8_C(  64), -INT8_C(  64),  INT8_C(  64),  INT8_C(  64),      INT8_MIN, -INT8_C(  64) },
      {  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),
         INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0),  INT8_C(   0) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int8x16_t a = simde_vld1q_s8(test_vec[i].a);

    simde_int8x16_t r1 = simde_vshlq_n_s8(a, 1);
    simde_int8x16_t r3 = simde_vshlq_n_s8(a, 3);
    simde_int8x16_t r5 = simde_vshlq_n_s8(a, 5);
    simde_int8x16_t r6 = simde_vshlq_n_s8(a, 6);
    simde_int8x16_t r8 = simde_vshlq_n_s8(a, 8);

    simde_test_arm_neon_assert_equal_i8x16(r1, simde_vld1q_s8(test_vec[i].r1));
    simde_test_arm_neon_assert_equal_i8x16(r3, simde_vld1q_s8(test_vec[i].r3));
    simde_test_arm_neon_assert_equal_i8x16(r5, simde_vld1q_s8(test_vec[i].r5));
    simde_test_arm_neon_assert_equal_i8x16(r6, simde_vld1q_s8(test_vec[i].r6));
    simde_test_arm_neon_assert_equal_i8x16(r8, simde_vld1q_s8(test_vec[i].r8));
  }

  return 0;
}

static int
test_simde_vshlq_n_s16 (void) {
  struct {
    int16_t a[8];
    int16_t r3[8];
    int16_t r6[8];
    int16_t r10[8];
    int16_t r13[8];
    int16_t r16[8];
  } test_vec[] = {
    { { -INT16_C( 10443), -INT16_C( 14051), -INT16_C( 16944), -INT16_C(   309),  INT16_C( 14084), -INT16_C( 14877), -INT16_C(  3419), -INT16_C( 17378) },
      { -INT16_C( 18008),  INT16_C( 18664), -INT16_C(  4480), -INT16_C(  2472), -INT16_C( 18400),  INT16_C( 12056), -INT16_C( 27352), -INT16_C(  7952) },
      { -INT16_C( 12992),  INT16_C( 18240),  INT16_C( 29696), -INT16_C( 19776), -INT16_C( 16128),  INT16_C( 30912), -INT16_C( 22208),  INT16_C(  1920) },
      { -INT16_C( 11264),  INT16_C( 29696),  INT16_C( 16384),  INT16_C( 11264),  INT16_C(  4096), -INT16_C( 29696), -INT16_C( 27648),  INT16_C( 30720) },
      { -INT16_C( 24576), -INT16_C( 24576),  INT16_C(     0),  INT16_C( 24576),       INT16_MIN,  INT16_C( 24576), -INT16_C( 24576), -INT16_C( 16384) },
      {  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0) } },
    { { -INT16_C( 27537),  INT16_C( 16235),  INT16_C(  4697),  INT16_C( 12693),  INT16_C( 13707), -INT16_C( 26396),  INT16_C(  1753),  INT16_C(  3651) },
      { -INT16_C( 23688), -INT16_C(  1192), -INT16_C( 27960), -INT16_C( 29528), -INT16_C( 21416), -INT16_C( 14560),  INT16_C( 14024),  INT16_C( 29208) },
      {  INT16_C(  7104), -INT16_C(  9536), -INT16_C( 27072),  INT16_C( 25920),  INT16_C( 25280),  INT16_C( 14592), -INT16_C( 18880), -INT16_C( 28480) },
      { -INT16_C( 17408), -INT16_C( 21504),  INT16_C( 25600),  INT16_C( 21504),  INT16_C( 11264), -INT16_C( 28672),  INT16_C( 25600),  INT16_C(  3072) },
      { -INT16_C(  8192),  INT16_C( 24576),  INT16_C(  8192), -INT16_C( 24576),  INT16_C( 24576),       INT16_MIN,  INT16_C(  8192),  INT16_C( 24576) },
      {  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0) } },
    { {  INT16_C( 24797), -INT16_C( 20777), -INT16_C( 24035),  INT16_C(  8620), -INT16_C( 28711),  INT16_C( 32487),  INT16_C(  1409), -INT16_C(  4038) },
      {  INT16_C(  1768),  INT16_C( 30392),  INT16_C(  4328),  INT16_C(  3424),  INT16_C( 32456), -INT16_C(  2248),  INT16_C( 11272), -INT16_C( 32304) },
      {  INT16_C( 14144), -INT16_C( 19008), -INT16_C( 30912),  INT16_C( 27392), -INT16_C(  2496), -INT16_C( 17984),  INT16_C( 24640),  INT16_C(  3712) },
      {  INT16_C( 29696),  INT16_C( 23552),  INT16_C( 29696), -INT16_C( 20480),  INT16_C( 25600), -INT16_C( 25600),  INT16_C(  1024), -INT16_C(  6144) },
      { -INT16_C( 24576), -INT16_C(  8192), -INT16_C( 24576),       INT16_MIN,  INT16_C(  8192), -INT16_C(  8192),  INT16_C(  8192),  INT16_C( 16384) },
      {  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0) } },
    { { -INT16_C( 22887), -INT16_C(  3536), -INT16_C( 14920),  INT16_C( 17187),  INT16_C(  2042), -INT16_C( 11301),  INT16_C(  7694), -INT16_C(  5151) },
      {  INT16_C( 13512), -INT16_C( 28288),  INT16_C( 11712),  INT16_C(  6424),  INT16_C( 16336), -INT16_C( 24872), -INT16_C(  3984),  INT16_C( 24328) },
      { -INT16_C( 22976), -INT16_C( 29696),  INT16_C( 28160), -INT16_C( 14144), -INT16_C(   384), -INT16_C(  2368), -INT16_C( 31872), -INT16_C(  1984) },
      {  INT16_C( 25600), -INT16_C( 16384), -INT16_C(  8192), -INT16_C( 29696), -INT16_C(  6144),  INT16_C( 27648),  INT16_C( 14336), -INT16_C( 31744) },
      {  INT16_C(  8192),  INT16_C(     0),  INT16_C(     0),  INT16_C( 24576),  INT16_C( 16384),  INT16_C( 24576), -INT16_C( 16384),  INT16_C(  8192) },
      {  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0) } },
    { { -INT16_C( 18049), -INT16_C( 25447),  INT16_C( 18011),  INT16_C( 13758), -INT16_C( 23083),  INT16_C( 22451), -INT16_C(  4438),  INT16_C( 17223) },
      { -INT16_C( 13320), -INT16_C(  6968),  INT16_C( 13016), -INT16_C( 21008),  INT16_C( 11944), -INT16_C( 17000),  INT16_C( 30032),  INT16_C(  6712) },
      {  INT16_C( 24512),  INT16_C(  9792), -INT16_C( 26944),  INT16_C( 28544),  INT16_C( 30016), -INT16_C(  4928), -INT16_C( 21888), -INT16_C( 11840) },
      { -INT16_C(  1024),  INT16_C( 25600),  INT16_C( 27648), -INT16_C(  2048),  INT16_C( 21504), -INT16_C( 13312), -INT16_C( 22528),  INT16_C(  7168) },
      { -INT16_C(  8192),  INT16_C(  8192),  INT16_C( 24576), -INT16_C( 16384), -INT16_C( 24576),  INT16_C( 24576),  INT16_C( 16384), -INT16_C(  8192) },
      {  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0) } },
    { {  INT16_C( 30612),  INT16_C( 19509),  INT16_C( 22588),  INT16_C( 14223),  INT16_C( 27488),  INT16_C( 28170), -INT16_C(  4983),  INT16_C(  2137) },
      { -INT16_C( 17248),  INT16_C( 25000), -INT16_C( 15904), -INT16_C( 17288),  INT16_C( 23296),  INT16_C( 28752),  INT16_C( 25672),  INT16_C( 17096) },
      { -INT16_C(  6912),  INT16_C(  3392),  INT16_C(  3840), -INT16_C(  7232), -INT16_C( 10240), -INT16_C( 32128),  INT16_C(  8768),  INT16_C(  5696) },
      {  INT16_C( 20480), -INT16_C( 11264), -INT16_C(  4096),  INT16_C( 15360),       INT16_MIN,  INT16_C( 10240),  INT16_C(  9216),  INT16_C( 25600) },
      {       INT16_MIN, -INT16_C( 24576),       INT16_MIN, -INT16_C(  8192),  INT16_C(     0),  INT16_C( 16384),  INT16_C(  8192),  INT16_C(  8192) },
      {  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0) } },
    { { -INT16_C(  3163),  INT16_C(   165),  INT16_C( 25401),  INT16_C(  3637), -INT16_C(  5880), -INT16_C( 19867), -INT16_C( 21033),  INT16_C( 27637) },
      { -INT16_C( 25304),  INT16_C(  1320),  INT16_C(  6600),  INT16_C( 29096),  INT16_C( 18496), -INT16_C( 27864),  INT16_C( 28344),  INT16_C( 24488) },
      { -INT16_C(  5824),  INT16_C( 10560), -INT16_C( 12736), -INT16_C( 29376),  INT16_C( 16896), -INT16_C( 26304),  INT16_C( 30144), -INT16_C(   704) },
      { -INT16_C( 27648), -INT16_C( 27648), -INT16_C(  7168), -INT16_C( 11264),  INT16_C(  8192), -INT16_C( 27648),  INT16_C( 23552), -INT16_C( 11264) },
      { -INT16_C( 24576), -INT16_C( 24576),  INT16_C(  8192), -INT16_C( 24576),  INT16_C(     0), -INT16_C( 24576), -INT16_C(  8192), -INT16_C( 24576) },
      {  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0) } },
    { {  INT16_C( 10788),  INT16_C( 25015),  INT16_C( 18050), -INT16_C(  7528), -INT16_C( 23887),  INT16_C( 15184), -INT16_C( 21874),  INT16_C( 13123) },
      {  INT16_C( 20768),  INT16_C(  3512),  INT16_C( 13328),  INT16_C(  5312),  INT16_C(  5512), -INT16_C(  9600),  INT16_C( 21616), -INT16_C( 26088) },
      { -INT16_C( 30464),  INT16_C( 28096), -INT16_C( 24448), -INT16_C( 23040), -INT16_C( 21440), -INT16_C( 11264), -INT16_C( 23680), -INT16_C( 12096) },
      { -INT16_C( 28672), -INT16_C(  9216),  INT16_C(  2048),  INT16_C( 24576), -INT16_C( 15360),  INT16_C( 16384),  INT16_C( 14336),  INT16_C(  3072) },
      {       INT16_MIN, -INT16_C(  8192),  INT16_C( 16384),  INT16_C(     0),  INT16_C(  8192),  INT16_C(     0), -INT16_C( 16384),  INT16_C( 24576) },
      {  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0),  INT16_C(     0) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x8_t a = simde_vld1q_s16(test_vec[i].a);

    simde_int16x8_t r3 = simde_vshlq_n_s16(a, 3);
    simde_int16x8_t r6 = simde_vshlq_n_s16(a, 6);
    simde_int16x8_t r10 = simde_vshlq_n_s16(a, 10);
    simde_int16x8_t r13 = simde_vshlq_n_s16(a, 13);
    simde_int16x8_t r16 = simde_vshlq_n_s16(a, 16);

    simde_test_arm_neon_assert_equal_i16x8(r3, simde_vld1q_s16(test_vec[i].r3));
    simde_test_arm_neon_assert_equal_i16x8(r6, simde_vld1q_s16(test_vec[i].r6));
    simde_test_arm_neon_assert_equal_i16x8(r10, simde_vld1q_s16(test_vec[i].r10));
    simde_test_arm_neon_assert_equal_i16x8(r13, simde_vld1q_s16(test_vec[i].r13));
    simde_test_arm_neon_assert_equal_i16x8(r16, simde_vld1q_s16(test_vec[i].r16));
  }

  return 0;
}

static int
test_simde_vshlq_n_s32 (void) {
  struct {
    int32_t a[4];
    int32_t r6[4];
    int32_t r13[4];
    int32_t r19[4];
    int32_t r26[4];
    int32_t r32[4];
  } test_vec[] = {
    { { -INT32_C(   535484099),  INT32_C(  1554649754), -INT32_C(  2006094790),  INT32_C(  1196239003) },
      {  INT32_C(    88756032),  INT32_C(   713336448),  INT32_C(   458952320), -INT32_C(   750115136) },
      { -INT32_C(  1524129792),  INT32_C(  1112752128), -INT32_C(  1383645184), -INT32_C(  1525456896) },
      {  INT32_C(  1239941120), -INT32_C(  1798307840),  INT32_C(  1641021440),  INT32_C(  1155006464) },
      { -INT32_C(   201326592),  INT32_C(  1744830464), -INT32_C(   402653184),  INT32_C(  1811939328) },
      {  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0) } },
    { {  INT32_C(  1658837670),  INT32_C(   612686973),  INT32_C(   210337908), -INT32_C(  1183214981) },
      { -INT32_C(  1208571520),  INT32_C(   557260608),  INT32_C(   576724224),  INT32_C(  1583652544) },
      { -INT32_C(    78331904), -INT32_C(  1685086208),  INT32_C(   806256640),  INT32_C(   844062720) },
      { -INT32_C(   718274560), -INT32_C(   471334912),  INT32_C(    60817408), -INT32_C(  1814560768) },
      { -INT32_C(  1744830464), -INT32_C(   201326592), -INT32_C(   805306368), -INT32_C(   335544320) },
      {  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0) } },
    { {  INT32_C(  1436126907), -INT32_C(   625851232),  INT32_C(  1281499056), -INT32_C(   309088441) },
      {  INT32_C(  1717808832), -INT32_C(  1399773184),  INT32_C(   411560960),  INT32_C(  1693176256) },
      {  INT32_C(   836198400),  INT32_C(  1217658880),  INT32_C(  1140195328),  INT32_C(  1978195968) },
      {  INT32_C(  1977090048),  INT32_C(   620756992), -INT32_C(    41943040),  INT32_C(  2050490368) },
      { -INT32_C(   335544320),            INT32_MIN, -INT32_C(  1073741824),  INT32_C(   469762048) },
      {  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0) } },
    { {  INT32_C(   105869961), -INT32_C(  1037314994), -INT32_C(   808537004),  INT32_C(    25708358) },
      { -INT32_C(  1814257088), -INT32_C(  1963650176), -INT32_C(   206760704),  INT32_C(  1645334912) },
      { -INT32_C(   296673280),  INT32_C(  2055847936), -INT32_C(   695566336),  INT32_C(   149471232) },
      { -INT32_C(  1807220736), -INT32_C(  1569718272), -INT32_C(  1566572544),  INT32_C(   976224256) },
      {  INT32_C(   603979776),  INT32_C(   939524096),  INT32_C(  1342177280),  INT32_C(   402653184) },
      {  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0) } },
    { {  INT32_C(  1968644821),  INT32_C(   374278502),  INT32_C(  1868739112), -INT32_C(   346229407) },
      {  INT32_C(  1439216960), -INT32_C(  1815979648), -INT32_C(   659781120), -INT32_C(   683845568) },
      { -INT32_C(   463822848), -INT32_C(   517160960),  INT32_C(  1447362560), -INT32_C(  1632886784) },
      {  INT32_C(   380108800),  INT32_C(  1261436928), -INT32_C(  1858076672), -INT32_C(  1425539072) },
      {  INT32_C(  1409286144), -INT32_C(  1744830464), -INT32_C(  1610612736), -INT32_C(  2080374784) },
      {  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0) } },
    { { -INT32_C(  1242452889), -INT32_C(   730391424),  INT32_C(   379799248),  INT32_C(  1662528653) },
      {  INT32_C(  2087393728),  INT32_C(   499589120), -INT32_C(  1462651904), -INT32_C(   972348608) },
      {  INT32_C(   898424832), -INT32_C(   477102080),  INT32_C(  1759117312),  INT32_C(    93429760) },
      {  INT32_C(  1664614400), -INT32_C(   469762048),  INT32_C(   914358272),  INT32_C(  1684537344) },
      { -INT32_C(  1677721600),  INT32_C(           0),  INT32_C(  1073741824),  INT32_C(   872415232) },
      {  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0) } },
    { { -INT32_C(  1260884146), -INT32_C(  1597364104),  INT32_C(   990850522), -INT32_C(  1977193694) },
      {  INT32_C(   907793280),  INT32_C(   847912448), -INT32_C(  1010076032), -INT32_C(  1986344832) },
      {  INT32_C(   233422848),  INT32_C(  1158610944), -INT32_C(   440713216), -INT32_C(   849068032) },
      {  INT32_C(  2054160384),  INT32_C(  1136656384),  INT32_C(  1859125248),  INT32_C(  1494220800) },
      {  INT32_C(   939524096), -INT32_C(   536870912),  INT32_C(  1744830464), -INT32_C(  2013265920) },
      {  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0) } },
    { { -INT32_C(  1757472745),  INT32_C(    90945332), -INT32_C(  1977937923), -INT32_C(  1980943557) },
      { -INT32_C(   809105984),  INT32_C(  1525533952), -INT32_C(  2033975488),  INT32_C(  2068631232) },
      { -INT32_C(   486350848),  INT32_C(  1994817536),  INT32_C(  1644142592), -INT32_C(  1503174656) },
      { -INT32_C(  1061683200), -INT32_C(  1180696576),  INT32_C(  2145910784), -INT32_C(  1713897472) },
      {  INT32_C(  1543503872), -INT32_C(   805306368), -INT32_C(   201326592), -INT32_C(   335544320) },
      {  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x4_t a = simde_vld1q_s32(test_vec[i].a);

    simde_int32x4_t r6 = simde_vshlq_n_s32(a, 6);
    simde_int32x4_t r13 = simde_vshlq_n_s32(a, 13);
    simde_int32x4_t r19 = simde_vshlq_n_s32(a, 19);
    simde_int32x4_t r26 = simde_vshlq_n_s32(a, 26);
    simde_int32x4_t r32 = simde_vshlq_n_s32(a, 32);

    simde_test_arm_neon_assert_equal_i32x4(r6, simde_vld1q_s32(test_vec[i].r6));
    simde_test_arm_neon_assert_equal_i32x4(r13, simde_vld1q_s32(test_vec[i].r13));
    simde_test_arm_neon_assert_equal_i32x4(r19, simde_vld1q_s32(test_vec[i].r19));
    simde_test_arm_neon_assert_equal_i32x4(r26, simde_vld1q_s32(test_vec[i].r26));
    simde_test_arm_neon_assert_equal_i32x4(r32, simde_vld1q_s32(test_vec[i].r32));
  }

  return 0;
}

static int
test_simde_vshlq_n_s64 (void) {
  struct {
    int64_t a[2];
    int64_t r13[2];
    int64_t r26[2];
    int64_t r39[2];
    int64_t r52[2];
    int64_t r64[2];
  } test_vec[] = {
    { {  INT64_C( 1807687227586121472),  INT64_C( 1109993886957461019) },
      { -INT64_C( 4161722803262849024), -INT64_C( 1174906383288279040) },
      { -INT64_C( 3250156114007818240),  INT64_C( 4367314578804047872) },
      { -INT64_C( 6627187589164040192),  INT64_C( 8804270639939584000) },
      { -INT64_C( 1152921504606846976), -INT64_C( 2184245819274690560) },
      {  INT64_C(                   0),  INT64_C(                   0) } },
    { {  INT64_C( 1606586614777140783), -INT64_C(  143235591053203982) },
      {  INT64_C( 8629023699426992128),  INT64_C( 7205658809564282880) },
      {  INT64_C( 1038855250917720064), -INT64_C(  824067919959818240) },
      {  INT64_C( 6353197537859469312),  INT64_C(  743930666864869376) },
      {  INT64_C( 7129198210127495168),  INT64_C( 6854478632857894912) },
      {  INT64_C(                   0),  INT64_C(                   0) } },
    { { -INT64_C( 7477156818981532882), -INT64_C( 2537455486953967573) },
      {  INT64_C( 8768407692703547392),  INT64_C( 2645221943762313216) },
      { -INT64_C(  825604397533757440), -INT64_C( 5266123307853283328) },
      {  INT64_C( 6603850454864494592),  INT64_C( 6852250472544206848) },
      { -INT64_C( 5557441940175192064),  INT64_C(  193654783976931328) },
      {  INT64_C(                   0),  INT64_C(                   0) } },
    { {  INT64_C( 2996513571190765948), -INT64_C(  620843877505586842) },
      { -INT64_C( 5177186912658554880),  INT64_C( 5348319818068836352) },
      { -INT64_C( 2450563040622411776),  INT64_C( 2418774559722307584) },
      { -INT64_C( 4954876582805110784),  INT64_C( 2798058081085292544) },
      { -INT64_C( 7512004178453987328), -INT64_C( 7611083370256138240) },
      {  INT64_C(                   0),  INT64_C(                   0) } },
    { {  INT64_C( 1274894616274475420),  INT64_C( 1229084216353582981) },
      {  INT64_C( 3079550800896425984), -INT64_C( 3264363876863401984) },
      { -INT64_C( 7465731891144949760),  INT64_C( 6110027613860790272) },
      { -INT64_C( 8319047912264826880),  INT64_C( 7329540773580374016) },
      { -INT64_C( 7367888990378131456), -INT64_C(  553942754166571008) },
      {  INT64_C(                   0),  INT64_C(                   0) } },
    { { -INT64_C( 6021553193009249266), -INT64_C( 6156858233579323954) },
      { -INT64_C( 1970104032428965888), -INT64_C( 3584351959907713024) },
      {  INT64_C( 1808830837769109504),  INT64_C( 4205309781621080064) },
      {  INT64_C( 5206731815775109120), -INT64_C( 8620198649554534400) },
      {  INT64_C( 4674736413210574848), -INT64_C( 2531022990582218752) },
      {  INT64_C(                   0),  INT64_C(                   0) } },
    { { -INT64_C( 9114592968743540853), -INT64_C( 1041525706045829403) },
      {  INT64_C( 5674410429178273792),  INT64_C( 8663922200087928832) },
      { -INT64_C( 1024829919651168256), -INT64_C( 8220532514041626624) },
      { -INT64_C( 2138148244524367872),  INT64_C( 6460258084567646208) },
      {  INT64_C( 8696450880452427776), -INT64_C( 1274518694545850368) },
      {  INT64_C(                   0),  INT64_C(                   0) } },
    { {  INT64_C( 1024752810898955078),  INT64_C( 5124027356216117604) },
      {  INT64_C( 1506473346394013696), -INT64_C( 8757409640504066048) },
      {  INT64_C(  157868348070166528), -INT64_C( 1312072352862830592) },
      {  INT64_C( 1985422231135584256),  INT64_C( 5955080320360382464) },
      { -INT64_C( 5449355549118300160), -INT64_C( 7620090569510879232) },
      {  INT64_C(                   0),  INT64_C(                   0) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int64x2_t a = simde_vld1q_s64(test_vec[i].a);

    simde_int64x2_t r13 = simde_vshlq_n_s64(a, 13);
    simde_int64x2_t r26 = simde_vshlq_n_s64(a, 26);
    simde_int64x2_t r39 = simde_vshlq_n_s64(a, 39);
    simde_int64x2_t r52 = simde_vshlq_n_s64(a, 52);
    simde_int64x2_t r64 = simde_vshlq_n_s64(a, 64);

    simde_test_arm_neon_assert_equal_i64x2(r13, simde_vld1q_s64(test_vec[i].r13));
    simde_test_arm_neon_assert_equal_i64x2(r26, simde_vld1q_s64(test_vec[i].r26));
    simde_test_arm_neon_assert_equal_i64x2(r39, simde_vld1q_s64(test_vec[i].r39));
    simde_test_arm_neon_assert_equal_i64x2(r52, simde_vld1q_s64(test_vec[i].r52));
    simde_test_arm_neon_assert_equal_i64x2(r64, simde_vld1q_s64(test_vec[i].r64));
  }

  return 0;
}

static int
test_simde_vshlq_n_u8 (void) {
  struct {
    uint8_t a[16];
    uint8_t r1[16];
    uint8_t r3[16];
    uint8_t r5[16];
    uint8_t r6[16];
    uint8_t r8[16];
  } test_vec[] = {
    { { UINT8_C(152), UINT8_C(166), UINT8_C(185), UINT8_C(108), UINT8_C( 48), UINT8_C( 22), UINT8_C( 73), UINT8_C( 35),
        UINT8_C(141), UINT8_C( 17), UINT8_C(210), UINT8_C( 83), UINT8_C( 98), UINT8_C(115), UINT8_C(131), UINT8_C( 31) },
      { UINT8_C( 48), UINT8_C( 76), UINT8_C(114), UINT8_C(216), UINT8_C( 96), UINT8_C( 44), UINT8_C(146), UINT8_C( 70),
        UINT8_C( 26), UINT8_C( 34), UINT8_C(164), UINT8_C(166), UINT8_C(196), UINT8_C(230), UINT8_C(  6), UINT8_C( 62) },
      { UINT8_C(192), UINT8_C( 48), UINT8_C(200), UINT8_C( 96), UINT8_C(128), UINT8_C(176), UINT8_C( 72), UINT8_C( 24),
        UINT8_C(104), UINT8_C(136), UINT8_C(144), UINT8_C(152), UINT8_C( 16), UINT8_C(152), UINT8_C( 24), UINT8_C(248) },
      { UINT8_C(  0), UINT8_C(192), UINT8_C( 32), UINT8_C(128), UINT8_C(  0), UINT8_C(192), UINT8_C( 32), UINT8_C( 96),
        UINT8_C(160), UINT8_C( 32), UINT8_C( 64), UINT8_C( 96), UINT8_C( 64), UINT8_C( 96), UINT8_C( 96), UINT8_C(224) },
      { UINT8_C(  0), UINT8_C(128), UINT8_C( 64), UINT8_C(  0), UINT8_C(  0), UINT8_C(128), UINT8_C( 64), UINT8_C(192),
        UINT8_C( 64), UINT8_C( 64), UINT8_C(128), UINT8_C(192), UINT8_C(128), UINT8_C(192), UINT8_C(192), UINT8_C(192) },
      { UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),
        UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0) } },
    { { UINT8_C(199), UINT8_C( 23), UINT8_C(175), UINT8_C(103), UINT8_C( 26), UINT8_C( 33), UINT8_C( 44), UINT8_C(132),
        UINT8_C(133), UINT8_C(182), UINT8_C(178), UINT8_C( 22), UINT8_C(116), UINT8_C(220), UINT8_C( 50), UINT8_C( 12) },
      { UINT8_C(142), UINT8_C( 46), UINT8_C( 94), UINT8_C(206), UINT8_C( 52), UINT8_C( 66), UINT8_C( 88), UINT8_C(  8),
        UINT8_C( 10), UINT8_C(108), UINT8_C(100), UINT8_C( 44), UINT8_C(232), UINT8_C(184), UINT8_C(100), UINT8_C( 24) },
      { UINT8_C( 56), UINT8_C(184), UINT8_C(120), UINT8_C( 56), UINT8_C(208), UINT8_C(  8), UINT8_C( 96), UINT8_C( 32),
        UINT8_C( 40), UINT8_C(176), UINT8_C(144), UINT8_C(176), UINT8_C(160), UINT8_C(224), UINT8_C(144), UINT8_C( 96) },
      { UINT8_C(224), UINT8_C(224), UINT8_C(224), UINT8_C(224), UINT8_C( 64), UINT8_C( 32), UINT8_C(128), UINT8_C(128),
        UINT8_C(160), UINT8_C(192), UINT8_C( 64), UINT8_C(192), UINT8_C(128), UINT8_C(128), UINT8_C( 64), UINT8_C(128) },
      { UINT8_C(192), UINT8_C(192), UINT8_C(192), UINT8_C(192), UINT8_C(128), UINT8_C( 64), UINT8_C(  0), UINT8_C(  0),
        UINT8_C( 64), UINT8_C(128), UINT8_C(128), UINT8_C(128), UINT8_C(  0), UINT8_C(  0), UINT8_C(128), UINT8_C(  0) },
      { UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),
        UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0) } },
    { { UINT8_C(130), UINT8_C(235), UINT8_C(120), UINT8_C(178), UINT8_C(  2), UINT8_C(193), UINT8_C(213), UINT8_C(143),
        UINT8_C(211), UINT8_C(167), UINT8_C(226), UINT8_C( 53), UINT8_C( 27), UINT8_C(102), UINT8_C( 85), UINT8_C(226) },
      { UINT8_C(  4), UINT8_C(214), UINT8_C(240), UINT8_C(100), UINT8_C(  4), UINT8_C(130), UINT8_C(170), UINT8_C( 30),
        UINT8_C(166), UINT8_C( 78), UINT8_C(196), UINT8_C(106), UINT8_C( 54), UINT8_C(204), UINT8_C(170), UINT8_C(196) },
      { UINT8_C( 16), UINT8_C( 88), UINT8_C(192), UINT8_C(144), UINT8_C( 16), UINT8_C(  8), UINT8_C(168), UINT8_C(120),
        UINT8_C(152), UINT8_C( 56), UINT8_C( 16), UINT8_C(168), UINT8_C(216), UINT8_C( 48), UINT8_C(168), UINT8_C( 16) },
      { UINT8_C( 64), UINT8_C( 96), UINT8_C(  0), UINT8_C( 64), UINT8_C( 64), UINT8_C( 32), UINT8_C(160), UINT8_C(224),
        UINT8_C( 96), UINT8_C(224), UINT8_C( 64), UINT8_C(160), UINT8_C( 96), UINT8_C(192), UINT8_C(160), UINT8_C( 64) },
      { UINT8_C(128), UINT8_C(192), UINT8_C(  0), UINT8_C(128), UINT8_C(128), UINT8_C( 64), UINT8_C( 64), UINT8_C(192),
        UINT8_C(192), UINT8_C(192), UINT8_C(128), UINT8_C( 64), UINT8_C(192), UINT8_C(128), UINT8_C( 64), UINT8_C(128) },
      { UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),
        UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0) } },
    { { UINT8_C(125), UINT8_C(  4), UINT8_C( 74), UINT8_C(152), UINT8_C( 37), UINT8_C(118), UINT8_C( 28), UINT8_C(171),
        UINT8_C( 44), UINT8_C(206), UINT8_C(193), UINT8_C(160), UINT8_C(170), UINT8_C(243), UINT8_C(173), UINT8_C( 44) },
      { UINT8_C(250), UINT8_C(  8), UINT8_C(148), UINT8_C( 48), UINT8_C( 74), UINT8_C(236), UINT8_C( 56), UINT8_C( 86),
        UINT8_C( 88), UINT8_C(156), UINT8_C(130), UINT8_C( 64), UINT8_C( 84), UINT8_C(230), UINT8_C( 90), UINT8_C( 88) },
      { UINT8_C(232), UINT8_C( 32), UINT8_C( 80), UINT8_C(192), UINT8_C( 40), UINT8_C(176), UINT8_C(224), UINT8_C( 88),
        UINT8_C( 96), UINT8_C(112), UINT8_C(  8), UINT8_C(  0), UINT8_C( 80), UINT8_C(152), UINT8_C(104), UINT8_C( 96) },
      { UINT8_C(160), UINT8_C(128), UINT8_C( 64), UINT8_C(  0), UINT8_C(160), UINT8_C(192), UINT8_C(128), UINT8_C( 96),
        UINT8_C(128), UINT8_C(192), UINT8_C( 32), UINT8_C(  0), UINT8_C( 64), UINT8_C( 96), UINT8_C(160), UINT8_C(128) },
      { UINT8_C( 64), UINT8_C(  0), UINT8_C(128), UINT8_C(  0), UINT8_C( 64), UINT8_C(128), UINT8_C(  0), UINT8_C(192),
        UINT8_C(  0), UINT8_C(128), UINT8_C( 64), UINT8_C(  0), UINT8_C(128), UINT8_C(192), UINT8_C( 64), UINT8_C(  0) },
      { UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),
        UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0) } },
    { { UINT8_C(223), UINT8_C( 37), UINT8_C(222), UINT8_C(225), UINT8_C(231), UINT8_C(180), UINT8_C(112), UINT8_C(186),
        UINT8_C( 91), UINT8_C( 82), UINT8_C(239), UINT8_C(118), UINT8_C(184), UINT8_C( 68), UINT8_C( 89), UINT8_C( 54) },
      { UINT8_C(190), UINT8_C( 74), UINT8_C(188), UINT8_C(194), UINT8_C(206), UINT8_C(104), UINT8_C(224), UINT8_C(116),
        UINT8_C(182), UINT8_C(164), UINT8_C(222), UINT8_C(236), UINT8_C(112), UINT8_C(136), UINT8_C(178), UINT8_C(108) },
      { UINT8_C(248), UINT8_C( 40), UINT8_C(240), UINT8_C(  8), UINT8_C( 56), UINT8_C(160), UINT8_C(128), UINT8_C(208),
        UINT8_C(216), UINT8_C(144), UINT8_C(120), UINT8_C(176), UINT8_C(192), UINT8_C( 32), UINT8_C(200), UINT8_C(176) },
      { UINT8_C(224), UINT8_C(160), UINT8_C(192), UINT8_C( 32), UINT8_C(224), UINT8_C(128), UINT8_C(  0), UINT8_C( 64),
        UINT8_C( 96), UINT8_C( 64), UINT8_C(224), UINT8_C(192), UINT8_C(  0), UINT8_C(128), UINT8_C( 32), UINT8_C(192) },
      { UINT8_C(192), UINT8_C( 64), UINT8_C(128), UINT8_C( 64), UINT8_C(192), UINT8_C(  0), UINT8_C(  0), UINT8_C(128),
        UINT8_C(192), UINT8_C(128), UINT8_C(192), UINT8_C(128), UINT8_C(  0), UINT8_C(  0), UINT8_C( 64), UINT8_C(128) },
      { UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),
        UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0) } },
    { { UINT8_C( 72), UINT8_C(163), UINT8_C(206), UINT8_C(110), UINT8_C( 25), UINT8_C(234), UINT8_C( 25), UINT8_C( 69),
        UINT8_C(185), UINT8_C(218), UINT8_C(230), UINT8_C( 99), UINT8_C(205), UINT8_C(147), UINT8_C(144), UINT8_C(172) },
      { UINT8_C(144), UINT8_C( 70), UINT8_C(156), UINT8_C(220), UINT8_C( 50), UINT8_C(212), UINT8_C( 50), UINT8_C(138),
        UINT8_C(114), UINT8_C(180), UINT8_C(204), UINT8_C(198), UINT8_C(154), UINT8_C( 38), UINT8_C( 32), UINT8_C( 88) },
      { UINT8_C( 64), UINT8_C( 24), UINT8_C(112), UINT8_C(112), UINT8_C(200), UINT8_C( 80), UINT8_C(200), UINT8_C( 40),
        UINT8_C(200), UINT8_C(208), UINT8_C( 48), UINT8_C( 24), UINT8_C(104), UINT8_C(152), UINT8_C(128), UINT8_C( 96) },
      { UINT8_C(  0), UINT8_C( 96), UINT8_C(192), UINT8_C(192), UINT8_C( 32), UINT8_C( 64), UINT8_C( 32), UINT8_C(160),
        UINT8_C( 32), UINT8_C( 64), UINT8_C(192), UINT8_C( 96), UINT8_C(160), UINT8_C( 96), UINT8_C(  0), UINT8_C(128) },
      { UINT8_C(  0), UINT8_C(192), UINT8_C(128), UINT8_C(128), UINT8_C( 64), UINT8_C(128), UINT8_C( 64), UINT8_C( 64),
        UINT8_C( 64), UINT8_C(128), UINT8_C(128), UINT8_C(192), UINT8_C( 64), UINT8_C(192), UINT8_C(  0), UINT8_C(  0) },
      { UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),
        UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0) } },
    { { UINT8_C(184), UINT8_C(110), UINT8_C(141), UINT8_C(159), UINT8_C( 34), UINT8_C(253), UINT8_C( 89), UINT8_C(126),
        UINT8_C( 80), UINT8_C( 73), UINT8_C(244), UINT8_C(  8), UINT8_C(141), UINT8_C( 77), UINT8_C( 62), UINT8_C(214) },
      { UINT8_C(112), UINT8_C(220), UINT8_C( 26), UINT8_C( 62), UINT8_C( 68), UINT8_C(250), UINT8_C(178), UINT8_C(252),
        UINT8_C(160), UINT8_C(146), UINT8_C(232), UINT8_C( 16), UINT8_C( 26), UINT8_C(154), UINT8_C(124), UINT8_C(172) },
      { UINT8_C(192), UINT8_C(112), UINT8_C(104), UINT8_C(248), UINT8_C( 16), UINT8_C(232), UINT8_C(200), UINT8_C(240),
        UINT8_C(128), UINT8_C( 72), UINT8_C(160), UINT8_C( 64), UINT8_C(104), UINT8_C(104), UINT8_C(240), UINT8_C(176) },
      { UINT8_C(  0), UINT8_C(192), UINT8_C(160), UINT8_C(224), UINT8_C( 64), UINT8_C(160), UINT8_C( 32), UINT8_C(192),
        UINT8_C(  0), UINT8_C( 32), UINT8_C(128), UINT8_C(  0), UINT8_C(160), UINT8_C(160), UINT8_C(192), UINT8_C(192) },
      { UINT8_C(  0), UINT8_C(128), UINT8_C( 64), UINT8_C(192), UINT8_C(128), UINT8_C( 64), UINT8_C( 64), UINT8_C(128),
        UINT8_C(  0), UINT8_C( 64), UINT8_C(  0), UINT8_C(  0), UINT8_C( 64), UINT8_C( 64), UINT8_C(128), UINT8_C(128) },
      { UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),
        UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0) } },
    { { UINT8_C(240), UINT8_C( 12), UINT8_C( 68), UINT8_C(  9), UINT8_C(247), UINT8_C( 93), UINT8_C( 79), UINT8_C(176),
        UINT8_C( 55), UINT8_C( 53), UINT8_C( 19), UINT8_C(  4), UINT8_C(200), UINT8_C(163), UINT8_C(177), UINT8_C(128) },
      { UINT8_C(224), UINT8_C( 24), UINT8_C(136), UINT8_C( 18), UINT8_C(238), UINT8_C(186), UINT8_C(158), UINT8_C( 96),
        UINT8_C(110), UINT8_C(106), UINT8_C( 38), UINT8_C(  8), UINT8_C(144), UINT8_C( 70), UINT8_C( 98), UINT8_C(  0) },
      { UINT8_C(128), UINT8_C( 96), UINT8_C( 32), UINT8_C( 72), UINT8_C(184), UINT8_C(232), UINT8_C(120), UINT8_C(128),
        UINT8_C(184), UINT8_C(168), UINT8_C(152), UINT8_C( 32), UINT8_C( 64), UINT8_C( 24), UINT8_C(136), UINT8_C(  0) },
      { UINT8_C(  0), UINT8_C(128), UINT8_C(128), UINT8_C( 32), UINT8_C(224), UINT8_C(160), UINT8_C(224), UINT8_C(  0),
        UINT8_C(224), UINT8_C(160), UINT8_C( 96), UINT8_C(128), UINT8_C(  0), UINT8_C( 96), UINT8_C( 32), UINT8_C(  0) },
      { UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C( 64), UINT8_C(192), UINT8_C( 64), UINT8_C(192), UINT8_C(  0),
        UINT8_C(192), UINT8_C( 64), UINT8_C(192), UINT8_C(  0), UINT8_C(  0), UINT8_C(192), UINT8_C( 64), UINT8_C(  0) },
      { UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0),
        UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0), UINT8_C(  0) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint8x16_t a = simde_vld1q_u8(test_vec[i].a);

    simde_uint8x16_t r1 = simde_vshlq_n_u8(a, 1);
    simde_uint8x16_t r3 = simde_vshlq_n_u8(a, 3);
    simde_uint8x16_t r5 = simde_vshlq_n_u8(a, 5);
    simde_uint8x16_t r6 = simde_vshlq_n_u8(a, 6);
    simde_uint8x16_t r8 = simde_vshlq_n_u8(a, 8);

    simde_test_arm_neon_assert_equal_u8x16(r1, simde_vld1q_u8(test_vec[i].r1));
    simde_test_arm_neon_assert_equal_u8x16(r3, simde_vld1q_u8(test_vec[i].r3));
    simde_test_arm_neon_assert_equal_u8x16(r5, simde_vld1q_u8(test_vec[i].r5));
    simde_test_arm_neon_assert_equal_u8x16(r6, simde_vld1q_u8(test_vec[i].r6));
    simde_test_arm_neon_assert_equal_u8x16(r8, simde_vld1q_u8(test_vec[i].r8));
  }

  return 0;
}

static int
test_simde_vshlq_n_u16 (void) {
  struct {
    uint16_t a[8];
    uint16_t r3[8];
    uint16_t r6[8];
    uint16_t r10[8];
    uint16_t r13[8];
    uint16_t r16[8];
  } test_vec[] = {
    { { UINT16_C(31119), UINT16_C(56823), UINT16_C(17762), UINT16_C(47673), UINT16_C(16603), UINT16_C(54631), UINT16_C(23212), UINT16_C(62270) },
      { UINT16_C(52344), UINT16_C(61368), UINT16_C(11024), UINT16_C(53704), UINT16_C( 1752), UINT16_C(43832), UINT16_C(54624), UINT16_C(39408) },
      { UINT16_C(25536), UINT16_C(32192), UINT16_C(22656), UINT16_C(36416), UINT16_C(14016), UINT16_C(22976), UINT16_C(43776), UINT16_C(53120) },
      { UINT16_C(15360), UINT16_C(56320), UINT16_C(34816), UINT16_C(58368), UINT16_C(27648), UINT16_C(39936), UINT16_C(45056), UINT16_C(63488) },
      { UINT16_C(57344), UINT16_C(57344), UINT16_C(16384), UINT16_C( 8192), UINT16_C(24576), UINT16_C(57344), UINT16_C(32768), UINT16_C(49152) },
      { UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0) } },
    { { UINT16_C( 2976), UINT16_C(14074), UINT16_C(28055), UINT16_C(48567), UINT16_C(45563), UINT16_C(10055), UINT16_C(10218), UINT16_C(30977) },
      { UINT16_C(23808), UINT16_C(47056), UINT16_C(27832), UINT16_C(60856), UINT16_C(36824), UINT16_C(14904), UINT16_C(16208), UINT16_C(51208) },
      { UINT16_C(59392), UINT16_C(48768), UINT16_C(26048), UINT16_C(28096), UINT16_C(32448), UINT16_C(53696), UINT16_C(64128), UINT16_C(16448) },
      { UINT16_C(32768), UINT16_C(59392), UINT16_C(23552), UINT16_C(56320), UINT16_C(60416), UINT16_C( 7168), UINT16_C(43008), UINT16_C( 1024) },
      { UINT16_C(    0), UINT16_C(16384), UINT16_C(57344), UINT16_C(57344), UINT16_C(24576), UINT16_C(57344), UINT16_C(16384), UINT16_C( 8192) },
      { UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0) } },
    { { UINT16_C(63904), UINT16_C(  598), UINT16_C(36670), UINT16_C( 6589), UINT16_C( 9423), UINT16_C(31726), UINT16_C(11390), UINT16_C( 7790) },
      { UINT16_C(52480), UINT16_C( 4784), UINT16_C(31216), UINT16_C(52712), UINT16_C( 9848), UINT16_C(57200), UINT16_C(25584), UINT16_C(62320) },
      { UINT16_C(26624), UINT16_C(38272), UINT16_C(53120), UINT16_C(28480), UINT16_C(13248), UINT16_C(64384), UINT16_C( 8064), UINT16_C(39808) },
      { UINT16_C(32768), UINT16_C(22528), UINT16_C(63488), UINT16_C(62464), UINT16_C(15360), UINT16_C(47104), UINT16_C(63488), UINT16_C(47104) },
      { UINT16_C(    0), UINT16_C(49152), UINT16_C(49152), UINT16_C(40960), UINT16_C(57344), UINT16_C(49152), UINT16_C(49152), UINT16_C(49152) },
      { UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0) } },
    { { UINT16_C(26680), UINT16_C(53077), UINT16_C( 3285), UINT16_C(53644), UINT16_C(54461), UINT16_C(43000), UINT16_C(63995), UINT16_C(39712) },
      { UINT16_C(16832), UINT16_C(31400), UINT16_C(26280), UINT16_C(35936), UINT16_C(42472), UINT16_C(16320), UINT16_C(53208), UINT16_C(55552) },
      { UINT16_C( 3584), UINT16_C(54592), UINT16_C(13632), UINT16_C(25344), UINT16_C(12096), UINT16_C(65024), UINT16_C(32448), UINT16_C(51200) },
      { UINT16_C(57344), UINT16_C(21504), UINT16_C(21504), UINT16_C(12288), UINT16_C(62464), UINT16_C(57344), UINT16_C(60416), UINT16_C(32768) },
      { UINT16_C(    0), UINT16_C(40960), UINT16_C(40960), UINT16_C(32768), UINT16_C(40960), UINT16_C(    0), UINT16_C(24576), UINT16_C(    0) },
      { UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0) } },
    { { UINT16_C(30450), UINT16_C(12446), UINT16_C(23301), UINT16_C(54345), UINT16_C(14463), UINT16_C(64848), UINT16_C(48740), UINT16_C(39963) },
      { UINT16_C(46992), UINT16_C(34032), UINT16_C(55336), UINT16_C(41544), UINT16_C(50168), UINT16_C(60032), UINT16_C(62240), UINT16_C(57560) },
      { UINT16_C(48256), UINT16_C(10112), UINT16_C(49472), UINT16_C( 4672), UINT16_C( 8128), UINT16_C(21504), UINT16_C(39168), UINT16_C( 1728) },
      { UINT16_C(51200), UINT16_C(30720), UINT16_C( 5120), UINT16_C( 9216), UINT16_C(64512), UINT16_C(16384), UINT16_C(36864), UINT16_C(27648) },
      { UINT16_C(16384), UINT16_C(49152), UINT16_C(40960), UINT16_C( 8192), UINT16_C(57344), UINT16_C(    0), UINT16_C(32768), UINT16_C(24576) },
      { UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0) } },
    { { UINT16_C(28711), UINT16_C(64620), UINT16_C(63612), UINT16_C(15053), UINT16_C(50636), UINT16_C(51169), UINT16_C(  703), UINT16_C(45411) },
      { UINT16_C(33080), UINT16_C(58208), UINT16_C(50144), UINT16_C(54888), UINT16_C(11872), UINT16_C(16136), UINT16_C( 5624), UINT16_C(35608) },
      { UINT16_C( 2496), UINT16_C( 6912), UINT16_C( 7936), UINT16_C(45888), UINT16_C(29440), UINT16_C(63552), UINT16_C(44992), UINT16_C(22720) },
      { UINT16_C(39936), UINT16_C(45056), UINT16_C(61440), UINT16_C(13312), UINT16_C(12288), UINT16_C(33792), UINT16_C(64512), UINT16_C(35840) },
      { UINT16_C(57344), UINT16_C(32768), UINT16_C(32768), UINT16_C(40960), UINT16_C(32768), UINT16_C( 8192), UINT16_C(57344), UINT16_C(24576) },
      { UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0) } },
    { { UINT16_C(  376), UINT16_C(32482), UINT16_C(11100), UINT16_C(56146), UINT16_C(41571), UINT16_C(51416), UINT16_C(62305), UINT16_C(34916) },
      { UINT16_C( 3008), UINT16_C(63248), UINT16_C(23264), UINT16_C(55952), UINT16_C( 4888), UINT16_C(18112), UINT16_C(39688), UINT16_C(17184) },
      { UINT16_C(24064), UINT16_C(47232), UINT16_C(55040), UINT16_C(54400), UINT16_C(39104), UINT16_C(13824), UINT16_C(55360), UINT16_C( 6400) },
      { UINT16_C(57344), UINT16_C(34816), UINT16_C(28672), UINT16_C(18432), UINT16_C(35840), UINT16_C(24576), UINT16_C(33792), UINT16_C(36864) },
      { UINT16_C(    0), UINT16_C(16384), UINT16_C(32768), UINT16_C(16384), UINT16_C(24576), UINT16_C(    0), UINT16_C( 8192), UINT16_C(32768) },
      { UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0) } },
    { { UINT16_C(53348), UINT16_C(57476), UINT16_C(21193), UINT16_C(38170), UINT16_C(64535), UINT16_C(54877), UINT16_C(49406), UINT16_C(30344) },
      { UINT16_C(33568), UINT16_C( 1056), UINT16_C(38472), UINT16_C(43216), UINT16_C(57528), UINT16_C(45800), UINT16_C( 2032), UINT16_C(46144) },
      { UINT16_C( 6400), UINT16_C( 8448), UINT16_C(45632), UINT16_C(18048), UINT16_C( 1472), UINT16_C(38720), UINT16_C(16256), UINT16_C(41472) },
      { UINT16_C(36864), UINT16_C( 4096), UINT16_C( 9216), UINT16_C(26624), UINT16_C(23552), UINT16_C(29696), UINT16_C(63488), UINT16_C( 8192) },
      { UINT16_C(32768), UINT16_C(32768), UINT16_C( 8192), UINT16_C(16384), UINT16_C(57344), UINT16_C(40960), UINT16_C(49152), UINT16_C(    0) },
      { UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0), UINT16_C(    0) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint16x8_t a = simde_vld1q_u16(test_vec[i].a);

    simde_uint16x8_t r3 = simde_vshlq_n_u16(a, 3);
    simde_uint16x8_t r6 = simde_vshlq_n_u16(a, 6);
    simde_uint16x8_t r10 = simde_vshlq_n_u16(a, 10);
    simde_uint16x8_t r13 = simde_vshlq_n_u16(a, 13);
    simde_uint16x8_t r16 = simde_vshlq_n_u16(a, 16);

    simde_test_arm_neon_assert_equal_u16x8(r3, simde_vld1q_u16(test_vec[i].r3));
    simde_test_arm_neon_assert_equal_u16x8(r6, simde_vld1q_u16(test_vec[i].r6));
    simde_test_arm_neon_assert_equal_u16x8(r10, simde_vld1q_u16(test_vec[i].r10));
    simde_test_arm_neon_assert_equal_u16x8(r13, simde_vld1q_u16(test_vec[i].r13));
    simde_test_arm_neon_assert_equal_u16x8(r16, simde_vld1q_u16(test_vec[i].r16));
  }

  return 0;
}

static int
test_simde_vshlq_n_u32 (void) {
  struct {
    uint32_t a[4];
    uint32_t r6[4];
    uint32_t r13[4];
    uint32_t r19[4];
    uint32_t r26[4];
    uint32_t r32[4];
  } test_vec[] = {
    { { UINT32_C(1152799704), UINT32_C(1106462679), UINT32_C(4176448650), UINT32_C( 959514349) },
      { UINT32_C( 764737024), UINT32_C(2094134720), UINT32_C(1004741248), UINT32_C(1279376192) },
      { UINT32_C(3397058560), UINT32_C(1761271808), UINT32_C(4052828160), UINT32_C( 551395328) },
      { UINT32_C(2663383040), UINT32_C(1052246016), UINT32_C(1682964480), UINT32_C( 929562624) },
      { UINT32_C(1610612736), UINT32_C(1543503872), UINT32_C( 671088640), UINT32_C(3019898880) },
      { UINT32_C(         0), UINT32_C(         0), UINT32_C(         0), UINT32_C(         0) } },
    { { UINT32_C(3148773944), UINT32_C(2326470416), UINT32_C(4028313234), UINT32_C(1325332086) },
      { UINT32_C(3953036800), UINT32_C(2865218560), UINT32_C( 114009216), UINT32_C(3216874880) },
      { UINT32_C(3477536768), UINT32_C(1675755520), UINT32_C(1708277760), UINT32_C(3738091520) },
      { UINT32_C(3519021056), UINT32_C(4169138176), UINT32_C(1955594240), UINT32_C(3014656000) },
      { UINT32_C(3758096384), UINT32_C(1073741824), UINT32_C(1207959552), UINT32_C(3623878656) },
      { UINT32_C(         0), UINT32_C(         0), UINT32_C(         0), UINT32_C(         0) } },
    { { UINT32_C( 546485321), UINT32_C(2254538492), UINT32_C(   8343826), UINT32_C(2419699799) },
      { UINT32_C( 615322176), UINT32_C(2556542720), UINT32_C( 534004864), UINT32_C( 241964480) },
      { UINT32_C(1451827200), UINT32_C( 819953664), UINT32_C(3928113152), UINT32_C( 906682368) },
      { UINT32_C(2722627584), UINT32_C( 937426944), UINT32_C(2291138560), UINT32_C(2193096704) },
      { UINT32_C( 603979776), UINT32_C(4026531840), UINT32_C(1207959552), UINT32_C(1543503872) },
      { UINT32_C(         0), UINT32_C(         0), UINT32_C(         0), UINT32_C(         0) } },
    { { UINT32_C( 994830122), UINT32_C(2563110406), UINT32_C(2609439012), UINT32_C( 552175575) },
      { UINT32_C(3539585664), UINT32_C( 830308736), UINT32_C(3795339520), UINT32_C( 979498432) },
      { UINT32_C(2095398912), UINT32_C(3200303104), UINT32_C( 472154112), UINT32_C( 821747712) },
      { UINT32_C( 961544192), UINT32_C(2955935744), UINT32_C( 153092096), UINT32_C(1052246016) },
      { UINT32_C(2818572288), UINT32_C( 402653184), UINT32_C(2415919104), UINT32_C(1543503872) },
      { UINT32_C(         0), UINT32_C(         0), UINT32_C(         0), UINT32_C(         0) } },
    { { UINT32_C( 926972987), UINT32_C( 348037634), UINT32_C(1242840563), UINT32_C( 416959981) },
      { UINT32_C(3491696320), UINT32_C( 799572096), UINT32_C(2232384704), UINT32_C( 915635008) },
      { UINT32_C( 260530176), UINT32_C(3560980480), UINT32_C(2277400576), UINT32_C(1237164032) },
      { UINT32_C(3789029376), UINT32_C( 269484032), UINT32_C(4019716096), UINT32_C(1869086720) },
      { UINT32_C(3959422976), UINT32_C( 134217728), UINT32_C(3422552064), UINT32_C(3019898880) },
      { UINT32_C(         0), UINT32_C(         0), UINT32_C(         0), UINT32_C(         0) } },
    { { UINT32_C( 995305013), UINT32_C(1104418844), UINT32_C(3504102649), UINT32_C( 535872995) },
      { UINT32_C(3569978688), UINT32_C(1963329280), UINT32_C( 924270144), UINT32_C(4231100608) },
      { UINT32_C(1690738688), UINT32_C(2198044672), UINT32_C(2342461440), UINT32_C( 414998528) },
      { UINT32_C( 833093632), UINT32_C(3235905536), UINT32_C(3888644096), UINT32_C( 790102016) },
      { UINT32_C(3556769792), UINT32_C(1879048192), UINT32_C(3825205248), UINT32_C(2348810240) },
      { UINT32_C(         0), UINT32_C(         0), UINT32_C(         0), UINT32_C(         0) } },
    { { UINT32_C(1129722177), UINT32_C(3327661267), UINT32_C(1058040913), UINT32_C(4015516602) },
      { UINT32_C(3582742592), UINT32_C(2516923584), UINT32_C(3290108992), UINT32_C(3589992064) },
      { UINT32_C(3324518400), UINT32_C(  43671552), UINT32_C( 227155968), UINT32_C(4252450816) },
      { UINT32_C(2315780096), UINT32_C(2794979328), UINT32_C(1653080064), UINT32_C(1573912576) },
      { UINT32_C(  67108864), UINT32_C(1275068416), UINT32_C(1140850688), UINT32_C(3892314112) },
      { UINT32_C(         0), UINT32_C(         0), UINT32_C(         0), UINT32_C(         0) } },
    { { UINT32_C( 757770769), UINT32_C(3161390786), UINT32_C(1049381467), UINT32_C(1365081360) },
      { UINT32_C(1252688960), UINT32_C( 465547392), UINT32_C(2735904448), UINT32_C(1465861120) },
      { UINT32_C(1430396928), UINT32_C(3755491328), UINT32_C(2303418368), UINT32_C(2946629632) },
      { UINT32_C(1351090176), UINT32_C(4128243712), UINT32_C(1389887488), UINT32_C(3900702720) },
      { UINT32_C(1140850688), UINT32_C( 134217728), UINT32_C(1811939328), UINT32_C(1073741824) },
      { UINT32_C(         0), UINT32_C(         0), UINT32_C(         0), UINT32_C(         0) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint32x4_t a = simde_vld1q_u32(test_vec[i].a);

    simde_uint32x4_t r6 = simde_vshlq_n_u32(a, 6);
    simde_uint32x4_t r13 = simde_vshlq_n_u32(a, 13);
    simde_uint32x4_t r19 = simde_vshlq_n_u32(a, 19);
    simde_uint32x4_t r26 = simde_vshlq_n_u32(a, 26);
    simde_uint32x4_t r32 = simde_vshlq_n_u32(a, 32);

    simde_test_arm_neon_assert_equal_u32x4(r6, simde_vld1q_u32(test_vec[i].r6));
    simde_test_arm_neon_assert_equal_u32x4(r13, simde_vld1q_u32(test_vec[i].r13));
    simde_test_arm_neon_assert_equal_u32x4(r19, simde_vld1q_u32(test_vec[i].r19));
    simde_test_arm_neon_assert_equal_u32x4(r26, simde_vld1q_u32(test_vec[i].r26));
    simde_test_arm_neon_assert_equal_u32x4(r32, simde_vld1q_u32(test_vec[i].r32));
  }

  return 0;
}

static int
test_simde_vshlq_n_u64 (void) {
  struct {
    uint64_t a[2];
    uint64_t r13[2];
    uint64_t r26[2];
    uint64_t r39[2];
    uint64_t r52[2];
    uint64_t r64[2];
  } test_vec[] = {
    { { UINT64_C( 9407941332980007171), UINT64_C(16462699564673448784) },
      { UINT64_C(17805403887421644800), UINT64_C(16735654988070125568) },
      { UINT64_C( 3463254936689573888), UINT64_C( 2283706461081042944) },
      { UINT64_C(18338800069408456704), UINT64_C( 3124838434418458624) },
      { UINT64_C( 1166432303488958464), UINT64_C(13042424520864956416) },
      { UINT64_C(                   0), UINT64_C(                   0) } },
    { { UINT64_C( 7037174398374696171), UINT64_C( 4550191687457356740) },
      { UINT64_C( 2457441143162232832), UINT64_C(12747274757372149760) },
      { UINT64_C( 5960060367890546688), UINT64_C(17103355196588687360) },
      { UINT64_C(14729714723884892160), UINT64_C( 7664530630482329600) },
      { UINT64_C( 5670031930859454464), UINT64_C(13564842077639933952) },
      { UINT64_C(                   0), UINT64_C(                   0) } },
    { { UINT64_C( 3087167904760865417), UINT64_C( 6591455040015576461) },
      { UINT64_C(18040094818923782144), UINT64_C( 3579784059744788480) },
      { UINT64_C( 7589982136405327872), UINT64_C(13714684304829710336) },
      { UINT64_C(11606133031256981504), UINT64_C(10022416273817731072) },
      { UINT64_C( 2922836158163451904), UINT64_C(15622987107348250624) },
      { UINT64_C(                   0), UINT64_C(                   0) } },
    { { UINT64_C(16543886512350564705), UINT64_C( 8999988604457216876) },
      { UINT64_C(17736343705459892224), UINT64_C(14717329170152390656) },
      { UINT64_C( 9571310591008571392), UINT64_C(14888040196464443392) },
      { UINT64_C( 9514048276622475264), UINT64_C(11400218142874533888) },
      { UINT64_C( 1589770668461785088), UINT64_C(13168525310431330304) },
      { UINT64_C(                   0), UINT64_C(                   0) } },
    { { UINT64_C( 9838017708578384259), UINT64_C(10205040393215385301) },
      { UINT64_C(17662954710802391040), UINT64_C(17493503242458013696) },
      { UINT64_C(17111220789174075392), UINT64_C(12470597640251244544) },
      { UINT64_C(16759232868852432896), UINT64_C( 1067188734698455040) },
      { UINT64_C(10966265092647157760), UINT64_C(17100167785125773312) },
      { UINT64_C(                   0), UINT64_C(                   0) } },
    { { UINT64_C(14172644790235211688), UINT64_C(14930649154105174981) },
      { UINT64_C(16945665752645828608), UINT64_C( 9964661735266230272) },
      { UINT64_C( 7144691010252046336), UINT64_C( 3666409136192487424) },
      { UINT64_C(16236554178065858560), UINT64_C( 3924291689706946560) },
      { UINT64_C( 8827055269646172160), UINT64_C(13569345677267304448) },
      { UINT64_C(                   0), UINT64_C(                   0) } },
    { { UINT64_C( 9439460901585159547), UINT64_C( 6560168728313863249) },
      { UINT64_C(17759292868896186368), UINT64_C( 5536735631243878400) },
      { UINT64_C(13103416724034682880), UINT64_C(14841357971773980672) },
      { UINT64_C( 1586038376241299456), UINT64_C(16361059026504515584) },
      { UINT64_C( 6318550277200805888), UINT64_C(14199849625099173888) },
      { UINT64_C(                   0), UINT64_C(                   0) } },
    { { UINT64_C(16945588709810818061), UINT64_C( 7267076869644850878) },
      { UINT64_C( 6513556105845645312), UINT64_C( 4250590269895327744) },
      { UINT64_C(11067757919503122432), UINT64_C(11829423892600979456) },
      { UINT64_C( 1325754287132770304), UINT64_C( 5893908990949064704) },
      { UINT64_C(13893604850437980160), UINT64_C( 7773212956841476096) },
      { UINT64_C(                   0), UINT64_C(                   0) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint64x2_t a = simde_vld1q_u64(test_vec[i].a);

    simde_uint64x2_t r13 = simde_vshlq_n_u64(a, 13);
    simde_uint64x2_t r26 = simde_vshlq_n_u64(a, 26);
    simde_uint64x2_t r39 = simde_vshlq_n_u64(a, 39);
    simde_uint64x2_t r52 = simde_vshlq_n_u64(a, 52);
    simde_uint64x2_t r64 = simde_vshlq_n_u64(a, 64);

    simde_test_arm_neon_assert_equal_u64x2(r13, simde_vld1q_u64(test_vec[i].r13));
    simde_test_arm_neon_assert_equal_u64x2(r26, simde_vld1q_u64(test_vec[i].r26));
    simde_test_arm_neon_assert_equal_u64x2(r39, simde_vld1q_u64(test_vec[i].r39));
    simde_test_arm_neon_assert_equal_u64x2(r52, simde_vld1q_u64(test_vec[i].r52));
    simde_test_arm_neon_assert_equal_u64x2(r64, simde_vld1q_u64(test_vec[i].r64));
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

#include <test/arm/neon/test-neon-footer.h>
