#define SIMDE_TEST_ARM_NEON_INSN shll_high_n

#include "test-neon.h"
#include "../../../simde/arm/neon/shll_high_n.h"
#include "../../../simde/arm/neon/dup_n.h"

static int
test_simde_vshll_high_n_s8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int8_t a[16];
    int16_t r1[8];
    int16_t r3[8];
    int16_t r5[8];
    int16_t r6[8];
    int16_t r7[8];
  } test_vec[] = {
    { { -INT8_C(    4), -INT8_C(   24), -INT8_C(   76), -INT8_C(   83),
        -INT8_C(   46), -INT8_C(   76), -INT8_C(   23),  INT8_C(  105),
         INT8_C(  122),  INT8_C(   30), -INT8_C(   79), -INT8_C(  100),
        -INT8_C(  120), -INT8_C(   73), -INT8_C(   44), -INT8_C(  112) },
      {  INT16_C(  244),  INT16_C(   60), -INT16_C(  158), -INT16_C(  200),
        -INT16_C(  240), -INT16_C(  146), -INT16_C(   88), -INT16_C(  224) },
      {  INT16_C(  976),  INT16_C(  240), -INT16_C(  632), -INT16_C(  800),
        -INT16_C(  960), -INT16_C(  584), -INT16_C(  352), -INT16_C(  896) },
      {  INT16_C( 3904),  INT16_C(  960), -INT16_C( 2528), -INT16_C( 3200),
        -INT16_C( 3840), -INT16_C( 2336), -INT16_C( 1408), -INT16_C( 3584) },
      {  INT16_C( 7808),  INT16_C( 1920), -INT16_C( 5056), -INT16_C( 6400),
        -INT16_C( 7680), -INT16_C( 4672), -INT16_C( 2816), -INT16_C( 7168) },
      {  INT16_C(15616),  INT16_C( 3840), -INT16_C(10112), -INT16_C(12800),
        -INT16_C(15360), -INT16_C( 9344), -INT16_C( 5632), -INT16_C(14336) } },
    { {  INT8_C(   97), -INT8_C(   78), -INT8_C(  118), -INT8_C(   67),
        -INT8_C(   94), -INT8_C(   12), -INT8_C(   10),  INT8_C(   10),
        -INT8_C(   18),  INT8_C(  103),  INT8_C(   97), -INT8_C(   54),
         INT8_C(   31), -INT8_C(   65),  INT8_C(  111),  INT8_C(   15) },
      { -INT16_C(   36),  INT16_C(  206),  INT16_C(  194), -INT16_C(  108),
         INT16_C(   62), -INT16_C(  130),  INT16_C(  222),  INT16_C(   30) },
      { -INT16_C(  144),  INT16_C(  824),  INT16_C(  776), -INT16_C(  432),
         INT16_C(  248), -INT16_C(  520),  INT16_C(  888),  INT16_C(  120) },
      { -INT16_C(  576),  INT16_C( 3296),  INT16_C( 3104), -INT16_C( 1728),
         INT16_C(  992), -INT16_C( 2080),  INT16_C( 3552),  INT16_C(  480) },
      { -INT16_C( 1152),  INT16_C( 6592),  INT16_C( 6208), -INT16_C( 3456),
         INT16_C( 1984), -INT16_C( 4160),  INT16_C( 7104),  INT16_C(  960) },
      { -INT16_C( 2304),  INT16_C(13184),  INT16_C(12416), -INT16_C( 6912),
         INT16_C( 3968), -INT16_C( 8320),  INT16_C(14208),  INT16_C( 1920) } },
    { { -INT8_C(   50),  INT8_C(  101),  INT8_C(   16), -INT8_C(  110),
        -INT8_C(   88),  INT8_C(   25), -INT8_C(  101), -INT8_C(   74),
        -INT8_C(   18), -INT8_C(  108), -INT8_C(   68), -INT8_C(   57),
         INT8_C(   46), -INT8_C(   40),  INT8_C(   93), -INT8_C(   48) },
      { -INT16_C(   36), -INT16_C(  216), -INT16_C(  136), -INT16_C(  114),
         INT16_C(   92), -INT16_C(   80),  INT16_C(  186), -INT16_C(   96) },
      { -INT16_C(  144), -INT16_C(  864), -INT16_C(  544), -INT16_C(  456),
         INT16_C(  368), -INT16_C(  320),  INT16_C(  744), -INT16_C(  384) },
      { -INT16_C(  576), -INT16_C( 3456), -INT16_C( 2176), -INT16_C( 1824),
         INT16_C( 1472), -INT16_C( 1280),  INT16_C( 2976), -INT16_C( 1536) },
      { -INT16_C( 1152), -INT16_C( 6912), -INT16_C( 4352), -INT16_C( 3648),
         INT16_C( 2944), -INT16_C( 2560),  INT16_C( 5952), -INT16_C( 3072) },
      { -INT16_C( 2304), -INT16_C(13824), -INT16_C( 8704), -INT16_C( 7296),
         INT16_C( 5888), -INT16_C( 5120),  INT16_C(11904), -INT16_C( 6144) } },
    { { -INT8_C(   93), -INT8_C(   40), -INT8_C(   98),  INT8_C(   90),
         INT8_C(   55),  INT8_C(    1),  INT8_C(   78), -INT8_C(   93),
         INT8_C(   69),  INT8_C(    4), -INT8_C(   91),  INT8_C(   65),
        -INT8_C(   75), -INT8_C(  117), -INT8_C(  115),  INT8_C(   30) },
      {  INT16_C(  138),  INT16_C(    8), -INT16_C(  182),  INT16_C(  130),
        -INT16_C(  150), -INT16_C(  234), -INT16_C(  230),  INT16_C(   60) },
      {  INT16_C(  552),  INT16_C(   32), -INT16_C(  728),  INT16_C(  520),
        -INT16_C(  600), -INT16_C(  936), -INT16_C(  920),  INT16_C(  240) },
      {  INT16_C( 2208),  INT16_C(  128), -INT16_C( 2912),  INT16_C( 2080),
        -INT16_C( 2400), -INT16_C( 3744), -INT16_C( 3680),  INT16_C(  960) },
      {  INT16_C( 4416),  INT16_C(  256), -INT16_C( 5824),  INT16_C( 4160),
        -INT16_C( 4800), -INT16_C( 7488), -INT16_C( 7360),  INT16_C( 1920) },
      {  INT16_C( 8832),  INT16_C(  512), -INT16_C(11648),  INT16_C( 8320),
        -INT16_C( 9600), -INT16_C(14976), -INT16_C(14720),  INT16_C( 3840) } },
    { { -INT8_C(  126), -INT8_C(   90), -INT8_C(   98),  INT8_C(   12),
        -INT8_C(   75),  INT8_C(   75), -INT8_C(   35),  INT8_C(   13),
        -INT8_C(   52), -INT8_C(   72),  INT8_C(  103),  INT8_C(  119),
        -INT8_C(  105), -INT8_C(   49), -INT8_C(  103), -INT8_C(   91) },
      { -INT16_C(  104), -INT16_C(  144),  INT16_C(  206),  INT16_C(  238),
        -INT16_C(  210), -INT16_C(   98), -INT16_C(  206), -INT16_C(  182) },
      { -INT16_C(  416), -INT16_C(  576),  INT16_C(  824),  INT16_C(  952),
        -INT16_C(  840), -INT16_C(  392), -INT16_C(  824), -INT16_C(  728) },
      { -INT16_C( 1664), -INT16_C( 2304),  INT16_C( 3296),  INT16_C( 3808),
        -INT16_C( 3360), -INT16_C( 1568), -INT16_C( 3296), -INT16_C( 2912) },
      { -INT16_C( 3328), -INT16_C( 4608),  INT16_C( 6592),  INT16_C( 7616),
        -INT16_C( 6720), -INT16_C( 3136), -INT16_C( 6592), -INT16_C( 5824) },
      { -INT16_C( 6656), -INT16_C( 9216),  INT16_C(13184),  INT16_C(15232),
        -INT16_C(13440), -INT16_C( 6272), -INT16_C(13184), -INT16_C(11648) } },
    { { -INT8_C(  111),  INT8_C(  115), -INT8_C(  121), -INT8_C(   99),
        -INT8_C(   85), -INT8_C(   36),  INT8_C(  105),  INT8_C(   61),
         INT8_C(   68), -INT8_C(  125),  INT8_C(    7), -INT8_C(   49),
        -INT8_C(   32),  INT8_C(   27), -INT8_C(   96), -INT8_C(   39) },
      {  INT16_C(  136), -INT16_C(  250),  INT16_C(   14), -INT16_C(   98),
        -INT16_C(   64),  INT16_C(   54), -INT16_C(  192), -INT16_C(   78) },
      {  INT16_C(  544), -INT16_C( 1000),  INT16_C(   56), -INT16_C(  392),
        -INT16_C(  256),  INT16_C(  216), -INT16_C(  768), -INT16_C(  312) },
      {  INT16_C( 2176), -INT16_C( 4000),  INT16_C(  224), -INT16_C( 1568),
        -INT16_C( 1024),  INT16_C(  864), -INT16_C( 3072), -INT16_C( 1248) },
      {  INT16_C( 4352), -INT16_C( 8000),  INT16_C(  448), -INT16_C( 3136),
        -INT16_C( 2048),  INT16_C( 1728), -INT16_C( 6144), -INT16_C( 2496) },
      {  INT16_C( 8704), -INT16_C(16000),  INT16_C(  896), -INT16_C( 6272),
        -INT16_C( 4096),  INT16_C( 3456), -INT16_C(12288), -INT16_C( 4992) } },
    { {  INT8_C(   30),  INT8_C(   55),  INT8_C(   69),  INT8_C(   40),
         INT8_C(   15), -INT8_C(  120), -INT8_C(  101), -INT8_C(   48),
         INT8_C(   84),  INT8_C(   63),  INT8_C(   71),  INT8_C(   54),
        -INT8_C(    2),  INT8_C(   58),  INT8_C(   50), -INT8_C(   34) },
      {  INT16_C(  168),  INT16_C(  126),  INT16_C(  142),  INT16_C(  108),
        -INT16_C(    4),  INT16_C(  116),  INT16_C(  100), -INT16_C(   68) },
      {  INT16_C(  672),  INT16_C(  504),  INT16_C(  568),  INT16_C(  432),
        -INT16_C(   16),  INT16_C(  464),  INT16_C(  400), -INT16_C(  272) },
      {  INT16_C( 2688),  INT16_C( 2016),  INT16_C( 2272),  INT16_C( 1728),
        -INT16_C(   64),  INT16_C( 1856),  INT16_C( 1600), -INT16_C( 1088) },
      {  INT16_C( 5376),  INT16_C( 4032),  INT16_C( 4544),  INT16_C( 3456),
        -INT16_C(  128),  INT16_C( 3712),  INT16_C( 3200), -INT16_C( 2176) },
      {  INT16_C(10752),  INT16_C( 8064),  INT16_C( 9088),  INT16_C( 6912),
        -INT16_C(  256),  INT16_C( 7424),  INT16_C( 6400), -INT16_C( 4352) } },
    { {  INT8_C(   28),  INT8_C(   74), -INT8_C(  122),  INT8_C(  121),
         INT8_C(  115), -INT8_C(   48),  INT8_C(  115),  INT8_C(   86),
        -INT8_C(   21),  INT8_C(  104),  INT8_C(    1),  INT8_C(   21),
         INT8_C(  119), -INT8_C(    6), -INT8_C(   76), -INT8_C(  106) },
      { -INT16_C(   42),  INT16_C(  208),  INT16_C(    2),  INT16_C(   42),
         INT16_C(  238), -INT16_C(   12), -INT16_C(  152), -INT16_C(  212) },
      { -INT16_C(  168),  INT16_C(  832),  INT16_C(    8),  INT16_C(  168),
         INT16_C(  952), -INT16_C(   48), -INT16_C(  608), -INT16_C(  848) },
      { -INT16_C(  672),  INT16_C( 3328),  INT16_C(   32),  INT16_C(  672),
         INT16_C( 3808), -INT16_C(  192), -INT16_C( 2432), -INT16_C( 3392) },
      { -INT16_C( 1344),  INT16_C( 6656),  INT16_C(   64),  INT16_C( 1344),
         INT16_C( 7616), -INT16_C(  384), -INT16_C( 4864), -INT16_C( 6784) },
      { -INT16_C( 2688),  INT16_C(13312),  INT16_C(  128),  INT16_C( 2688),
         INT16_C(15232), -INT16_C(  768), -INT16_C( 9728), -INT16_C(13568) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int8x16_t a = simde_vld1q_s8(test_vec[i].a);
    simde_int16x8_t r1 = simde_vshll_high_n_s8(a, 1);
    simde_int16x8_t r3 = simde_vshll_high_n_s8(a, 3);
    simde_int16x8_t r5 = simde_vshll_high_n_s8(a, 5);
    simde_int16x8_t r6 = simde_vshll_high_n_s8(a, 6);
    simde_int16x8_t r7 = simde_vshll_high_n_s8(a, 7);

    simde_test_arm_neon_assert_equal_i16x8(r1, simde_vld1q_s16(test_vec[i].r1));
    simde_test_arm_neon_assert_equal_i16x8(r3, simde_vld1q_s16(test_vec[i].r3));
    simde_test_arm_neon_assert_equal_i16x8(r5, simde_vld1q_s16(test_vec[i].r5));
    simde_test_arm_neon_assert_equal_i16x8(r6, simde_vld1q_s16(test_vec[i].r6));
    simde_test_arm_neon_assert_equal_i16x8(r7, simde_vld1q_s16(test_vec[i].r7));
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int8x16_t a = simde_test_arm_neon_random_i8x16();
    simde_int16x8_t r1 = simde_vshll_high_n_s8(a, 1);
    simde_int16x8_t r3 = simde_vshll_high_n_s8(a, 3);
    simde_int16x8_t r5 = simde_vshll_high_n_s8(a, 5);
    simde_int16x8_t r6 = simde_vshll_high_n_s8(a, 6);
    simde_int16x8_t r7 = simde_vshll_high_n_s8(a, 7);

    simde_test_arm_neon_write_i8x16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i16x8(2, r1, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i16x8(2, r3, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i16x8(2, r5, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i16x8(2, r6, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i16x8(2, r7, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vshll_high_n_s16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int16_t a[8];
    int32_t r3[4];
    int32_t r6[4];
    int32_t r10[4];
    int32_t r13[4];
    int32_t r15[4];
  } test_vec[] = {
    { { -INT16_C(     28252),  INT16_C(     30826), -INT16_C(     14629), -INT16_C(     15341),
        -INT16_C(     21110),  INT16_C(     29286),  INT16_C(     31948),  INT16_C(     25186) },
      { -INT32_C(    168880),  INT32_C(    234288),  INT32_C(    255584),  INT32_C(    201488) },
      { -INT32_C(   1351040),  INT32_C(   1874304),  INT32_C(   2044672),  INT32_C(   1611904) },
      { -INT32_C(  21616640),  INT32_C(  29988864),  INT32_C(  32714752),  INT32_C(  25790464) },
      { -INT32_C( 172933120),  INT32_C( 239910912),  INT32_C( 261718016),  INT32_C( 206323712) },
      { -INT32_C( 691732480),  INT32_C( 959643648),  INT32_C(1046872064),  INT32_C( 825294848) } },
    { { -INT16_C(     11492), -INT16_C(      6951),  INT16_C(     30321),  INT16_C(     18299),
        -INT16_C(      3360),  INT16_C(     29557), -INT16_C(      7564),  INT16_C(     31785) },
      { -INT32_C(     26880),  INT32_C(    236456), -INT32_C(     60512),  INT32_C(    254280) },
      { -INT32_C(    215040),  INT32_C(   1891648), -INT32_C(    484096),  INT32_C(   2034240) },
      { -INT32_C(   3440640),  INT32_C(  30266368), -INT32_C(   7745536),  INT32_C(  32547840) },
      { -INT32_C(  27525120),  INT32_C( 242130944), -INT32_C(  61964288),  INT32_C( 260382720) },
      { -INT32_C( 110100480),  INT32_C( 968523776), -INT32_C( 247857152),  INT32_C(1041530880) } },
    { { -INT16_C(     24724), -INT16_C(      1040),  INT16_C(     25683),  INT16_C(      8624),
         INT16_C(     14997),  INT16_C(     12943), -INT16_C(     15127),  INT16_C(      2130) },
      {  INT32_C(    119976),  INT32_C(    103544), -INT32_C(    121016),  INT32_C(     17040) },
      {  INT32_C(    959808),  INT32_C(    828352), -INT32_C(    968128),  INT32_C(    136320) },
      {  INT32_C(  15356928),  INT32_C(  13253632), -INT32_C(  15490048),  INT32_C(   2181120) },
      {  INT32_C( 122855424),  INT32_C( 106029056), -INT32_C( 123920384),  INT32_C(  17448960) },
      {  INT32_C( 491421696),  INT32_C( 424116224), -INT32_C( 495681536),  INT32_C(  69795840) } },
    { {  INT16_C(      7406), -INT16_C(     29256),  INT16_C(     10503), -INT16_C(      7372),
        -INT16_C(     10246), -INT16_C(      2028),  INT16_C(      2327), -INT16_C(     24523) },
      { -INT32_C(     81968), -INT32_C(     16224),  INT32_C(     18616), -INT32_C(    196184) },
      { -INT32_C(    655744), -INT32_C(    129792),  INT32_C(    148928), -INT32_C(   1569472) },
      { -INT32_C(  10491904), -INT32_C(   2076672),  INT32_C(   2382848), -INT32_C(  25111552) },
      { -INT32_C(  83935232), -INT32_C(  16613376),  INT32_C(  19062784), -INT32_C( 200892416) },
      { -INT32_C( 335740928), -INT32_C(  66453504),  INT32_C(  76251136), -INT32_C( 803569664) } },
    { {  INT16_C(     13913),  INT16_C(      7181), -INT16_C(     29410), -INT16_C(     28785),
        -INT16_C(     10612),  INT16_C(     24705),  INT16_C(     15016), -INT16_C(      3492) },
      { -INT32_C(     84896),  INT32_C(    197640),  INT32_C(    120128), -INT32_C(     27936) },
      { -INT32_C(    679168),  INT32_C(   1581120),  INT32_C(    961024), -INT32_C(    223488) },
      { -INT32_C(  10866688),  INT32_C(  25297920),  INT32_C(  15376384), -INT32_C(   3575808) },
      { -INT32_C(  86933504),  INT32_C( 202383360),  INT32_C( 123011072), -INT32_C(  28606464) },
      { -INT32_C( 347734016),  INT32_C( 809533440),  INT32_C( 492044288), -INT32_C( 114425856) } },
    { { -INT16_C(     16521), -INT16_C(     10548), -INT16_C(     27724),  INT16_C(     18369),
         INT16_C(      8234),  INT16_C(     31227),  INT16_C(     32695),  INT16_C(     27583) },
      {  INT32_C(     65872),  INT32_C(    249816),  INT32_C(    261560),  INT32_C(    220664) },
      {  INT32_C(    526976),  INT32_C(   1998528),  INT32_C(   2092480),  INT32_C(   1765312) },
      {  INT32_C(   8431616),  INT32_C(  31976448),  INT32_C(  33479680),  INT32_C(  28244992) },
      {  INT32_C(  67452928),  INT32_C( 255811584),  INT32_C( 267837440),  INT32_C( 225959936) },
      {  INT32_C( 269811712),  INT32_C(1023246336),  INT32_C(1071349760),  INT32_C( 903839744) } },
    { { -INT16_C(      7755), -INT16_C(     19833),  INT16_C(     13140),  INT16_C(      7387),
         INT16_C(     14132),  INT16_C(     11641), -INT16_C(      6693), -INT16_C(     25905) },
      {  INT32_C(    113056),  INT32_C(     93128), -INT32_C(     53544), -INT32_C(    207240) },
      {  INT32_C(    904448),  INT32_C(    745024), -INT32_C(    428352), -INT32_C(   1657920) },
      {  INT32_C(  14471168),  INT32_C(  11920384), -INT32_C(   6853632), -INT32_C(  26526720) },
      {  INT32_C( 115769344),  INT32_C(  95363072), -INT32_C(  54829056), -INT32_C( 212213760) },
      {  INT32_C( 463077376),  INT32_C( 381452288), -INT32_C( 219316224), -INT32_C( 848855040) } },
    { {  INT16_C(     29489),  INT16_C(      8162),  INT16_C(      4422), -INT16_C(     12819),
        -INT16_C(      8593), -INT16_C(     15934), -INT16_C(      1072), -INT16_C(      3190) },
      { -INT32_C(     68744), -INT32_C(    127472), -INT32_C(      8576), -INT32_C(     25520) },
      { -INT32_C(    549952), -INT32_C(   1019776), -INT32_C(     68608), -INT32_C(    204160) },
      { -INT32_C(   8799232), -INT32_C(  16316416), -INT32_C(   1097728), -INT32_C(   3266560) },
      { -INT32_C(  70393856), -INT32_C( 130531328), -INT32_C(   8781824), -INT32_C(  26132480) },
      { -INT32_C( 281575424), -INT32_C( 522125312), -INT32_C(  35127296), -INT32_C( 104529920) } },
  };

  for (size_t i = 1 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x8_t a = simde_vld1q_s16(test_vec[i].a);
    simde_int32x4_t r3 = simde_vshll_high_n_s16(a, 3);
    simde_int32x4_t r6 = simde_vshll_high_n_s16(a, 6);
    simde_int32x4_t r10 = simde_vshll_high_n_s16(a, 10);
    simde_int32x4_t r13 = simde_vshll_high_n_s16(a, 13);
    simde_int32x4_t r15 = simde_vshll_high_n_s16(a, 15);

    simde_test_arm_neon_assert_equal_i32x4(r3, simde_vld1q_s32(test_vec[i].r3));
    simde_test_arm_neon_assert_equal_i32x4(r6, simde_vld1q_s32(test_vec[i].r6));
    simde_test_arm_neon_assert_equal_i32x4(r10, simde_vld1q_s32(test_vec[i].r10));
    simde_test_arm_neon_assert_equal_i32x4(r13, simde_vld1q_s32(test_vec[i].r13));
    simde_test_arm_neon_assert_equal_i32x4(r15, simde_vld1q_s32(test_vec[i].r15));
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int16x8_t a = simde_test_arm_neon_random_i16x8();
    simde_int32x4_t r3 = simde_vshll_high_n_s16(a, 3);
    simde_int32x4_t r6 = simde_vshll_high_n_s16(a, 6);
    simde_int32x4_t r10 = simde_vshll_high_n_s16(a, 10);
    simde_int32x4_t r13 = simde_vshll_high_n_s16(a, 13);
    simde_int32x4_t r15 = simde_vshll_high_n_s16(a, 15);

    simde_test_arm_neon_write_i16x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i32x4(2, r3, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i32x4(2, r6, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i32x4(2, r10, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i32x4(2, r13, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i32x4(2, r15, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vshll_high_n_s32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int32_t a[4];
    int64_t r6[2];
    int64_t r13[2];
    int64_t r19[2];
    int64_t r26[2];
    int64_t r31[2];
  } test_vec[] = {
    { {  INT32_C(          1916672935),  INT32_C(          1078422529),  INT32_C(          2001365512), -INT32_C(           196431013) },
      {  INT64_C(        128087392768), -INT64_C(         12571584832) },
      {  INT64_C(      16395186274304), -INT64_C(       1609162858496) },
      {  INT64_C(    1049291921555456), -INT64_C(     102986422943744) },
      {  INT64_C(  134309365959098368), -INT64_C(   13182262136799232) },
      {  INT64_C( 4297899710691147776), -INT64_C(  421832388377575424) } },
    { { -INT32_C(           432423885), -INT32_C(           327412723), -INT32_C(           959266434), -INT32_C(          1398854253) },
      { -INT64_C(         61393051776), -INT64_C(         89526672192) },
      { -INT64_C(       7858310627328), -INT64_C(      11459414040576) },
      { -INT64_C(     502931880148992), -INT64_C(     733402498596864) },
      { -INT64_C(   64375280659070976), -INT64_C(   93875519820398592) },
      { -INT64_C( 2060008981090271232), -INT64_C( 3004016634252754944) } },
    { { -INT32_C(           719198291), -INT32_C(           943252342), -INT32_C(           175019184), -INT32_C(          1681411827) },
      { -INT64_C(         11201227776), -INT64_C(        107610356928) },
      { -INT64_C(       1433757155328), -INT64_C(      13774125686784) },
      { -INT64_C(      91760457940992), -INT64_C(     881544043954176) },
      { -INT64_C(   11745338616446976), -INT64_C(  112837637626134528) },
      { -INT64_C(  375850835726303232), -INT64_C( 3610804404036304896) } },
    { {  INT32_C(          1939682074),  INT32_C(            96005202),  INT32_C(          1431835596),  INT32_C(          1989011755) },
      {  INT64_C(         91637478144),  INT64_C(        127296752320) },
      {  INT64_C(      11729597202432),  INT64_C(      16293984296960) },
      {  INT64_C(     750694220955648),  INT64_C(    1042814995005440) },
      {  INT64_C(   96088860282322944),  INT64_C(  133480319360696320) },
      {  INT64_C( 3074843529034334208),  INT64_C( 4271370219542282240) } },
    { { -INT32_C(          1582513916),  INT32_C(          1310337245), -INT32_C(          1218614413),  INT32_C(          1923554564) },
      { -INT64_C(         77991322432),  INT64_C(        123107492096) },
      { -INT64_C(       9982889271296),  INT64_C(      15757758988288) },
      { -INT64_C(     638904913362944),  INT64_C(    1008496575250432) },
      { -INT64_C(   81779828910456832),  INT64_C(  129087561632055296) },
      { -INT64_C( 2616954525134618624),  INT64_C( 4130801972225769472) } },
    { { -INT32_C(           443346506), -INT32_C(          1391094271), -INT32_C(          1364584621),  INT32_C(           914259840) },
      { -INT64_C(         87333415744),  INT64_C(         58512629760) },
      { -INT64_C(      11178677215232),  INT64_C(       7489616609280) },
      { -INT64_C(     715435341774848),  INT64_C(     479335462993920) },
      { -INT64_C(   91575723747180544),  INT64_C(   61354939263221760) },
      { -INT64_C( 2930423159909777408),  INT64_C( 1963358056423096320) } },
    { { -INT32_C(          1099927976),  INT32_C(           693695898),  INT32_C(           269814730), -INT32_C(          1269146620) },
      {  INT64_C(         17268142720), -INT64_C(         81225383680) },
      {  INT64_C(       2210322268160), -INT64_C(      10396849111040) },
      {  INT64_C(     141460625162240), -INT64_C(     665398343106560) },
      {  INT64_C(   18106960020766720), -INT64_C(   85170987917639680) },
      {  INT64_C(  579422720664535040), -INT64_C( 2725471613364469760) } },
    { { -INT32_C(           152605622),  INT32_C(          1736221089),  INT32_C(           179066507),  INT32_C(           635269448) },
      {  INT64_C(         11460256448),  INT64_C(         40657244672) },
      {  INT64_C(       1466912825344),  INT64_C(       5204127318016) },
      {  INT64_C(      93882420822016),  INT64_C(     333064148353024) },
      {  INT64_C(   12016949865218048),  INT64_C(   42632210989187072) },
      {  INT64_C(  384542395686977536),  INT64_C( 1364230751653986304) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x4_t a = simde_vld1q_s32(test_vec[i].a);
    simde_int64x2_t r6 = simde_vshll_high_n_s32(a, 6);
    simde_int64x2_t r13 = simde_vshll_high_n_s32(a, 13);
    simde_int64x2_t r19 = simde_vshll_high_n_s32(a, 19);
    simde_int64x2_t r26 = simde_vshll_high_n_s32(a, 26);
    simde_int64x2_t r31 = simde_vshll_high_n_s32(a, 31);

    simde_test_arm_neon_assert_equal_i64x2(r6, simde_vld1q_s64(test_vec[i].r6));
    simde_test_arm_neon_assert_equal_i64x2(r13, simde_vld1q_s64(test_vec[i].r13));
    simde_test_arm_neon_assert_equal_i64x2(r19, simde_vld1q_s64(test_vec[i].r19));
    simde_test_arm_neon_assert_equal_i64x2(r26, simde_vld1q_s64(test_vec[i].r26));
    simde_test_arm_neon_assert_equal_i64x2(r31, simde_vld1q_s64(test_vec[i].r31));
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int32x4_t a = simde_test_arm_neon_random_i32x4();
    simde_int64x2_t r6 = simde_vshll_high_n_s32(a, 6);
    simde_int64x2_t r13 = simde_vshll_high_n_s32(a, 13);
    simde_int64x2_t r19 = simde_vshll_high_n_s32(a, 19);
    simde_int64x2_t r26 = simde_vshll_high_n_s32(a, 26);
    simde_int64x2_t r31 = simde_vshll_high_n_s32(a, 31);

    simde_test_arm_neon_write_i32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i64x2(2, r6, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i64x2(2, r13, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i64x2(2, r19, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i64x2(2, r26, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i64x2(2, r31, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vshll_high_n_u8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint8_t a[16];
    uint16_t r1[8];
    uint16_t r3[8];
    uint16_t r5[8];
    uint16_t r6[8];
    uint16_t r7[8];
  } test_vec[] = {
    { {  UINT8_C(      71),  UINT8_C(      74),  UINT8_C(       7),  UINT8_C(     233),
         UINT8_C(     131),  UINT8_C(      38),  UINT8_C(     243),  UINT8_C(     184),
         UINT8_C(      95),  UINT8_C(      99),  UINT8_C(      75),  UINT8_C(      46),
         UINT8_C(      91),  UINT8_C(     250),  UINT8_C(     123),  UINT8_C(      45) },
      {  UINT16_C(     190),  UINT16_C(     198),  UINT16_C(     150),  UINT16_C(      92),
         UINT16_C(     182),  UINT16_C(     500),  UINT16_C(     246),  UINT16_C(      90) },
      {  UINT16_C(     760),  UINT16_C(     792),  UINT16_C(     600),  UINT16_C(     368),
         UINT16_C(     728),  UINT16_C(    2000),  UINT16_C(     984),  UINT16_C(     360) },
      {  UINT16_C(    3040),  UINT16_C(    3168),  UINT16_C(    2400),  UINT16_C(    1472),
         UINT16_C(    2912),  UINT16_C(    8000),  UINT16_C(    3936),  UINT16_C(    1440) },
      {  UINT16_C(    6080),  UINT16_C(    6336),  UINT16_C(    4800),  UINT16_C(    2944),
         UINT16_C(    5824),  UINT16_C(   16000),  UINT16_C(    7872),  UINT16_C(    2880) },
      {  UINT16_C(   12160),  UINT16_C(   12672),  UINT16_C(    9600),  UINT16_C(    5888),
         UINT16_C(   11648),  UINT16_C(   32000),  UINT16_C(   15744),  UINT16_C(    5760) } },
    { {  UINT8_C(     170),  UINT8_C(      89),  UINT8_C(     195),  UINT8_C(      58),
         UINT8_C(       5),  UINT8_C(     142),  UINT8_C(     170),  UINT8_C(      37),
         UINT8_C(     241),  UINT8_C(     165),  UINT8_C(     126),  UINT8_C(     229),
         UINT8_C(     106),  UINT8_C(      63),  UINT8_C(     153),  UINT8_C(      54) },
      {  UINT16_C(     482),  UINT16_C(     330),  UINT16_C(     252),  UINT16_C(     458),
         UINT16_C(     212),  UINT16_C(     126),  UINT16_C(     306),  UINT16_C(     108) },
      {  UINT16_C(    1928),  UINT16_C(    1320),  UINT16_C(    1008),  UINT16_C(    1832),
         UINT16_C(     848),  UINT16_C(     504),  UINT16_C(    1224),  UINT16_C(     432) },
      {  UINT16_C(    7712),  UINT16_C(    5280),  UINT16_C(    4032),  UINT16_C(    7328),
         UINT16_C(    3392),  UINT16_C(    2016),  UINT16_C(    4896),  UINT16_C(    1728) },
      {  UINT16_C(   15424),  UINT16_C(   10560),  UINT16_C(    8064),  UINT16_C(   14656),
         UINT16_C(    6784),  UINT16_C(    4032),  UINT16_C(    9792),  UINT16_C(    3456) },
      {  UINT16_C(   30848),  UINT16_C(   21120),  UINT16_C(   16128),  UINT16_C(   29312),
         UINT16_C(   13568),  UINT16_C(    8064),  UINT16_C(   19584),  UINT16_C(    6912) } },
    { {  UINT8_C(      47),  UINT8_C(      62),  UINT8_C(      83),  UINT8_C(      54),
         UINT8_C(     132),  UINT8_C(     202),  UINT8_C(      60),  UINT8_C(      71),
         UINT8_C(     225),  UINT8_C(     244),  UINT8_C(     253),  UINT8_C(     159),
         UINT8_C(     182),  UINT8_C(     168),  UINT8_C(      70),  UINT8_C(      32) },
      {  UINT16_C(     450),  UINT16_C(     488),  UINT16_C(     506),  UINT16_C(     318),
         UINT16_C(     364),  UINT16_C(     336),  UINT16_C(     140),  UINT16_C(      64) },
      {  UINT16_C(    1800),  UINT16_C(    1952),  UINT16_C(    2024),  UINT16_C(    1272),
         UINT16_C(    1456),  UINT16_C(    1344),  UINT16_C(     560),  UINT16_C(     256) },
      {  UINT16_C(    7200),  UINT16_C(    7808),  UINT16_C(    8096),  UINT16_C(    5088),
         UINT16_C(    5824),  UINT16_C(    5376),  UINT16_C(    2240),  UINT16_C(    1024) },
      {  UINT16_C(   14400),  UINT16_C(   15616),  UINT16_C(   16192),  UINT16_C(   10176),
         UINT16_C(   11648),  UINT16_C(   10752),  UINT16_C(    4480),  UINT16_C(    2048) },
      {  UINT16_C(   28800),  UINT16_C(   31232),  UINT16_C(   32384),  UINT16_C(   20352),
         UINT16_C(   23296),  UINT16_C(   21504),  UINT16_C(    8960),  UINT16_C(    4096) } },
    { {  UINT8_C(     102),  UINT8_C(      40),  UINT8_C(     169),  UINT8_C(     120),
         UINT8_C(     150),  UINT8_C(     246),  UINT8_C(     124),  UINT8_C(     127),
         UINT8_C(     187),  UINT8_C(     214),  UINT8_C(     232),  UINT8_C(     186),
         UINT8_C(       3),  UINT8_C(     109),  UINT8_C(      12),  UINT8_C(     219) },
      {  UINT16_C(     374),  UINT16_C(     428),  UINT16_C(     464),  UINT16_C(     372),
         UINT16_C(       6),  UINT16_C(     218),  UINT16_C(      24),  UINT16_C(     438) },
      {  UINT16_C(    1496),  UINT16_C(    1712),  UINT16_C(    1856),  UINT16_C(    1488),
         UINT16_C(      24),  UINT16_C(     872),  UINT16_C(      96),  UINT16_C(    1752) },
      {  UINT16_C(    5984),  UINT16_C(    6848),  UINT16_C(    7424),  UINT16_C(    5952),
         UINT16_C(      96),  UINT16_C(    3488),  UINT16_C(     384),  UINT16_C(    7008) },
      {  UINT16_C(   11968),  UINT16_C(   13696),  UINT16_C(   14848),  UINT16_C(   11904),
         UINT16_C(     192),  UINT16_C(    6976),  UINT16_C(     768),  UINT16_C(   14016) },
      {  UINT16_C(   23936),  UINT16_C(   27392),  UINT16_C(   29696),  UINT16_C(   23808),
         UINT16_C(     384),  UINT16_C(   13952),  UINT16_C(    1536),  UINT16_C(   28032) } },
    { {  UINT8_C(     202),  UINT8_C(      56),  UINT8_C(      62),  UINT8_C(      49),
         UINT8_C(     213),  UINT8_C(     138),  UINT8_C(     137),  UINT8_C(     141),
         UINT8_C(     188),  UINT8_C(     186),  UINT8_C(      48),  UINT8_C(     234),
         UINT8_C(     142),  UINT8_C(      80),  UINT8_C(     210),  UINT8_C(      16) },
      {  UINT16_C(     376),  UINT16_C(     372),  UINT16_C(      96),  UINT16_C(     468),
         UINT16_C(     284),  UINT16_C(     160),  UINT16_C(     420),  UINT16_C(      32) },
      {  UINT16_C(    1504),  UINT16_C(    1488),  UINT16_C(     384),  UINT16_C(    1872),
         UINT16_C(    1136),  UINT16_C(     640),  UINT16_C(    1680),  UINT16_C(     128) },
      {  UINT16_C(    6016),  UINT16_C(    5952),  UINT16_C(    1536),  UINT16_C(    7488),
         UINT16_C(    4544),  UINT16_C(    2560),  UINT16_C(    6720),  UINT16_C(     512) },
      {  UINT16_C(   12032),  UINT16_C(   11904),  UINT16_C(    3072),  UINT16_C(   14976),
         UINT16_C(    9088),  UINT16_C(    5120),  UINT16_C(   13440),  UINT16_C(    1024) },
      {  UINT16_C(   24064),  UINT16_C(   23808),  UINT16_C(    6144),  UINT16_C(   29952),
         UINT16_C(   18176),  UINT16_C(   10240),  UINT16_C(   26880),  UINT16_C(    2048) } },
    { {  UINT8_C(      54),  UINT8_C(      98),  UINT8_C(      26),  UINT8_C(     219),
         UINT8_C(     170),  UINT8_C(     238),  UINT8_C(      79),  UINT8_C(     214),
         UINT8_C(     206),  UINT8_C(     253),  UINT8_C(      15),  UINT8_C(      83),
         UINT8_C(     232),  UINT8_C(     198),  UINT8_C(     122),  UINT8_C(     184) },
      {  UINT16_C(     412),  UINT16_C(     506),  UINT16_C(      30),  UINT16_C(     166),
         UINT16_C(     464),  UINT16_C(     396),  UINT16_C(     244),  UINT16_C(     368) },
      {  UINT16_C(    1648),  UINT16_C(    2024),  UINT16_C(     120),  UINT16_C(     664),
         UINT16_C(    1856),  UINT16_C(    1584),  UINT16_C(     976),  UINT16_C(    1472) },
      {  UINT16_C(    6592),  UINT16_C(    8096),  UINT16_C(     480),  UINT16_C(    2656),
         UINT16_C(    7424),  UINT16_C(    6336),  UINT16_C(    3904),  UINT16_C(    5888) },
      {  UINT16_C(   13184),  UINT16_C(   16192),  UINT16_C(     960),  UINT16_C(    5312),
         UINT16_C(   14848),  UINT16_C(   12672),  UINT16_C(    7808),  UINT16_C(   11776) },
      {  UINT16_C(   26368),  UINT16_C(   32384),  UINT16_C(    1920),  UINT16_C(   10624),
         UINT16_C(   29696),  UINT16_C(   25344),  UINT16_C(   15616),  UINT16_C(   23552) } },
    { {  UINT8_C(     154),  UINT8_C(     225),  UINT8_C(     119),  UINT8_C(     174),
         UINT8_C(      56),  UINT8_C(     221),  UINT8_C(     144),  UINT8_C(      93),
         UINT8_C(     193),  UINT8_C(      36),  UINT8_C(     113),  UINT8_C(     197),
         UINT8_C(     118),  UINT8_C(      45),  UINT8_C(     130),  UINT8_C(     103) },
      {  UINT16_C(     386),  UINT16_C(      72),  UINT16_C(     226),  UINT16_C(     394),
         UINT16_C(     236),  UINT16_C(      90),  UINT16_C(     260),  UINT16_C(     206) },
      {  UINT16_C(    1544),  UINT16_C(     288),  UINT16_C(     904),  UINT16_C(    1576),
         UINT16_C(     944),  UINT16_C(     360),  UINT16_C(    1040),  UINT16_C(     824) },
      {  UINT16_C(    6176),  UINT16_C(    1152),  UINT16_C(    3616),  UINT16_C(    6304),
         UINT16_C(    3776),  UINT16_C(    1440),  UINT16_C(    4160),  UINT16_C(    3296) },
      {  UINT16_C(   12352),  UINT16_C(    2304),  UINT16_C(    7232),  UINT16_C(   12608),
         UINT16_C(    7552),  UINT16_C(    2880),  UINT16_C(    8320),  UINT16_C(    6592) },
      {  UINT16_C(   24704),  UINT16_C(    4608),  UINT16_C(   14464),  UINT16_C(   25216),
         UINT16_C(   15104),  UINT16_C(    5760),  UINT16_C(   16640),  UINT16_C(   13184) } },
    { {  UINT8_C(     115),  UINT8_C(      51),  UINT8_C(      79),  UINT8_C(     176),
         UINT8_C(     197),  UINT8_C(     167),  UINT8_C(      55),  UINT8_C(     104),
         UINT8_C(     151),  UINT8_C(      46),  UINT8_C(     150),  UINT8_C(     212),
         UINT8_C(     137),  UINT8_C(     239),  UINT8_C(     156),  UINT8_C(      85) },
      {  UINT16_C(     302),  UINT16_C(      92),  UINT16_C(     300),  UINT16_C(     424),
         UINT16_C(     274),  UINT16_C(     478),  UINT16_C(     312),  UINT16_C(     170) },
      {  UINT16_C(    1208),  UINT16_C(     368),  UINT16_C(    1200),  UINT16_C(    1696),
         UINT16_C(    1096),  UINT16_C(    1912),  UINT16_C(    1248),  UINT16_C(     680) },
      {  UINT16_C(    4832),  UINT16_C(    1472),  UINT16_C(    4800),  UINT16_C(    6784),
         UINT16_C(    4384),  UINT16_C(    7648),  UINT16_C(    4992),  UINT16_C(    2720) },
      {  UINT16_C(    9664),  UINT16_C(    2944),  UINT16_C(    9600),  UINT16_C(   13568),
         UINT16_C(    8768),  UINT16_C(   15296),  UINT16_C(    9984),  UINT16_C(    5440) },
      {  UINT16_C(   19328),  UINT16_C(    5888),  UINT16_C(   19200),  UINT16_C(   27136),
         UINT16_C(   17536),  UINT16_C(   30592),  UINT16_C(   19968),  UINT16_C(   10880) } },
  };

  for (size_t i = 1 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint8x16_t a = simde_vld1q_u8(test_vec[i].a);
    simde_uint16x8_t r1 = simde_vshll_high_n_u8(a, 1);
    simde_uint16x8_t r3 = simde_vshll_high_n_u8(a, 3);
    simde_uint16x8_t r5 = simde_vshll_high_n_u8(a, 5);
    simde_uint16x8_t r6 = simde_vshll_high_n_u8(a, 6);
    simde_uint16x8_t r7 = simde_vshll_high_n_u8(a, 7);

    simde_test_arm_neon_assert_equal_u16x8(r1, simde_vld1q_u16(test_vec[i].r1));
    simde_test_arm_neon_assert_equal_u16x8(r3, simde_vld1q_u16(test_vec[i].r3));
    simde_test_arm_neon_assert_equal_u16x8(r5, simde_vld1q_u16(test_vec[i].r5));
    simde_test_arm_neon_assert_equal_u16x8(r6, simde_vld1q_u16(test_vec[i].r6));
    simde_test_arm_neon_assert_equal_u16x8(r7, simde_vld1q_u16(test_vec[i].r7));
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint8x16_t a = simde_test_arm_neon_random_u8x16();
    simde_uint16x8_t r1 = simde_vshll_high_n_u8(a, 1);
    simde_uint16x8_t r3 = simde_vshll_high_n_u8(a, 3);
    simde_uint16x8_t r5 = simde_vshll_high_n_u8(a, 5);
    simde_uint16x8_t r6 = simde_vshll_high_n_u8(a, 6);
    simde_uint16x8_t r7 = simde_vshll_high_n_u8(a, 7);

    simde_test_arm_neon_write_u8x16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u16x8(2, r1, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u16x8(2, r3, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u16x8(2, r5, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u16x8(2, r6, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u16x8(2, r7, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vshll_high_n_u16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint16_t a[8];
    uint32_t r3[4];
    uint32_t r6[4];
    uint32_t r10[4];
    uint32_t r13[4];
    uint32_t r15[4];
  } test_vec[] = {
    { {  UINT16_C(       22180),  UINT16_C(        8853),  UINT16_C(       26431),  UINT16_C(       34927),
         UINT16_C(       20862),  UINT16_C(       44107),  UINT16_C(       35865),  UINT16_C(       17804) },
      {  UINT32_C(      166896),  UINT32_C(      352856),  UINT32_C(      286920),  UINT32_C(      142432) },
      {  UINT32_C(     1335168),  UINT32_C(     2822848),  UINT32_C(     2295360),  UINT32_C(     1139456) },
      {  UINT32_C(    21362688),  UINT32_C(    45165568),  UINT32_C(    36725760),  UINT32_C(    18231296) },
      {  UINT32_C(   170901504),  UINT32_C(   361324544),  UINT32_C(   293806080),  UINT32_C(   145850368) },
      {  UINT32_C(   683606016),  UINT32_C(  1445298176),  UINT32_C(  1175224320),  UINT32_C(   583401472) } },
    { {  UINT16_C(       29810),  UINT16_C(       22204),  UINT16_C(       61493),  UINT16_C(       15830),
         UINT16_C(       56647),  UINT16_C(       35239),  UINT16_C(       15014),  UINT16_C(       13950) },
      {  UINT32_C(      453176),  UINT32_C(      281912),  UINT32_C(      120112),  UINT32_C(      111600) },
      {  UINT32_C(     3625408),  UINT32_C(     2255296),  UINT32_C(      960896),  UINT32_C(      892800) },
      {  UINT32_C(    58006528),  UINT32_C(    36084736),  UINT32_C(    15374336),  UINT32_C(    14284800) },
      {  UINT32_C(   464052224),  UINT32_C(   288677888),  UINT32_C(   122994688),  UINT32_C(   114278400) },
      {  UINT32_C(  1856208896),  UINT32_C(  1154711552),  UINT32_C(   491978752),  UINT32_C(   457113600) } },
    { {  UINT16_C(       42449),  UINT16_C(       31769),  UINT16_C(       16676),  UINT16_C(       41723),
         UINT16_C(       41781),  UINT16_C(       22209),  UINT16_C(       63795),  UINT16_C(       32736) },
      {  UINT32_C(      334248),  UINT32_C(      177672),  UINT32_C(      510360),  UINT32_C(      261888) },
      {  UINT32_C(     2673984),  UINT32_C(     1421376),  UINT32_C(     4082880),  UINT32_C(     2095104) },
      {  UINT32_C(    42783744),  UINT32_C(    22742016),  UINT32_C(    65326080),  UINT32_C(    33521664) },
      {  UINT32_C(   342269952),  UINT32_C(   181936128),  UINT32_C(   522608640),  UINT32_C(   268173312) },
      {  UINT32_C(  1369079808),  UINT32_C(   727744512),  UINT32_C(  2090434560),  UINT32_C(  1072693248) } },
    { {  UINT16_C(       21203),  UINT16_C(       22177),  UINT16_C(       45749),  UINT16_C(       33513),
         UINT16_C(        4052),  UINT16_C(       34841),  UINT16_C(       34678),  UINT16_C(       19128) },
      {  UINT32_C(       32416),  UINT32_C(      278728),  UINT32_C(      277424),  UINT32_C(      153024) },
      {  UINT32_C(      259328),  UINT32_C(     2229824),  UINT32_C(     2219392),  UINT32_C(     1224192) },
      {  UINT32_C(     4149248),  UINT32_C(    35677184),  UINT32_C(    35510272),  UINT32_C(    19587072) },
      {  UINT32_C(    33193984),  UINT32_C(   285417472),  UINT32_C(   284082176),  UINT32_C(   156696576) },
      {  UINT32_C(   132775936),  UINT32_C(  1141669888),  UINT32_C(  1136328704),  UINT32_C(   626786304) } },
    { {  UINT16_C(        1525),  UINT16_C(       47600),  UINT16_C(       46203),  UINT16_C(       49979),
         UINT16_C(       44860),  UINT16_C(       43632),  UINT16_C(       18669),  UINT16_C(       15875) },
      {  UINT32_C(      358880),  UINT32_C(      349056),  UINT32_C(      149352),  UINT32_C(      127000) },
      {  UINT32_C(     2871040),  UINT32_C(     2792448),  UINT32_C(     1194816),  UINT32_C(     1016000) },
      {  UINT32_C(    45936640),  UINT32_C(    44679168),  UINT32_C(    19117056),  UINT32_C(    16256000) },
      {  UINT32_C(   367493120),  UINT32_C(   357433344),  UINT32_C(   152936448),  UINT32_C(   130048000) },
      {  UINT32_C(  1469972480),  UINT32_C(  1429733376),  UINT32_C(   611745792),  UINT32_C(   520192000) } },
    { {  UINT16_C(       16761),  UINT16_C(        1555),  UINT16_C(       48346),  UINT16_C(       39284),
         UINT16_C(       33085),  UINT16_C(       28890),  UINT16_C(       21145),  UINT16_C(       29113) },
      {  UINT32_C(      264680),  UINT32_C(      231120),  UINT32_C(      169160),  UINT32_C(      232904) },
      {  UINT32_C(     2117440),  UINT32_C(     1848960),  UINT32_C(     1353280),  UINT32_C(     1863232) },
      {  UINT32_C(    33879040),  UINT32_C(    29583360),  UINT32_C(    21652480),  UINT32_C(    29811712) },
      {  UINT32_C(   271032320),  UINT32_C(   236666880),  UINT32_C(   173219840),  UINT32_C(   238493696) },
      {  UINT32_C(  1084129280),  UINT32_C(   946667520),  UINT32_C(   692879360),  UINT32_C(   953974784) } },
    { {  UINT16_C(       43066),  UINT16_C(       50108),  UINT16_C(       59709),  UINT16_C(       20038),
         UINT16_C(       47024),  UINT16_C(       10441),  UINT16_C(       12340),  UINT16_C(       18991) },
      {  UINT32_C(      376192),  UINT32_C(       83528),  UINT32_C(       98720),  UINT32_C(      151928) },
      {  UINT32_C(     3009536),  UINT32_C(      668224),  UINT32_C(      789760),  UINT32_C(     1215424) },
      {  UINT32_C(    48152576),  UINT32_C(    10691584),  UINT32_C(    12636160),  UINT32_C(    19446784) },
      {  UINT32_C(   385220608),  UINT32_C(    85532672),  UINT32_C(   101089280),  UINT32_C(   155574272) },
      {  UINT32_C(  1540882432),  UINT32_C(   342130688),  UINT32_C(   404357120),  UINT32_C(   622297088) } },
    { {  UINT16_C(       63057),  UINT16_C(       38930),  UINT16_C(       48977),  UINT16_C(       21551),
         UINT16_C(       36776),  UINT16_C(       45423),  UINT16_C(       24737),  UINT16_C(       30602) },
      {  UINT32_C(      294208),  UINT32_C(      363384),  UINT32_C(      197896),  UINT32_C(      244816) },
      {  UINT32_C(     2353664),  UINT32_C(     2907072),  UINT32_C(     1583168),  UINT32_C(     1958528) },
      {  UINT32_C(    37658624),  UINT32_C(    46513152),  UINT32_C(    25330688),  UINT32_C(    31336448) },
      {  UINT32_C(   301268992),  UINT32_C(   372105216),  UINT32_C(   202645504),  UINT32_C(   250691584) },
      {  UINT32_C(  1205075968),  UINT32_C(  1488420864),  UINT32_C(   810582016),  UINT32_C(  1002766336) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint16x8_t a = simde_vld1q_u16(test_vec[i].a);
    simde_uint32x4_t r3 = simde_vshll_high_n_u16(a, 3);
    simde_uint32x4_t r6 = simde_vshll_high_n_u16(a, 6);
    simde_uint32x4_t r10 = simde_vshll_high_n_u16(a, 10);
    simde_uint32x4_t r13 = simde_vshll_high_n_u16(a, 13);
    simde_uint32x4_t r15 = simde_vshll_high_n_u16(a, 15);

    simde_test_arm_neon_assert_equal_u32x4(r3, simde_vld1q_u32(test_vec[i].r3));
    simde_test_arm_neon_assert_equal_u32x4(r6, simde_vld1q_u32(test_vec[i].r6));
    simde_test_arm_neon_assert_equal_u32x4(r10, simde_vld1q_u32(test_vec[i].r10));
    simde_test_arm_neon_assert_equal_u32x4(r13, simde_vld1q_u32(test_vec[i].r13));
    simde_test_arm_neon_assert_equal_u32x4(r15, simde_vld1q_u32(test_vec[i].r15));
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint16x8_t a = simde_test_arm_neon_random_u16x8();
    simde_uint32x4_t r3 = simde_vshll_high_n_u16(a, 3);
    simde_uint32x4_t r6 = simde_vshll_high_n_u16(a, 6);
    simde_uint32x4_t r10 = simde_vshll_high_n_u16(a, 10);
    simde_uint32x4_t r13 = simde_vshll_high_n_u16(a, 13);
    simde_uint32x4_t r15 = simde_vshll_high_n_u16(a, 15);

    simde_test_arm_neon_write_u16x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u32x4(2, r3, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x4(2, r6, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x4(2, r10, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x4(2, r13, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x4(2, r15, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vshll_high_n_u32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint32_t a[4];
    uint64_t r6[2];
    uint64_t r13[2];
    uint64_t r19[2];
    uint64_t r26[2];
    uint64_t r31[2];
  } test_vec[] = {
    { {  UINT32_C(           919671253),  UINT32_C(          3858102866),  UINT32_C(          3920514400),  UINT32_C(          3370398723) },
      {  UINT64_C(        250912921600),  UINT64_C(        215705518272) },
      {  UINT64_C(      32116853964800),  UINT64_C(      27610306338816) },
      {  UINT64_C(    2055478653747200),  UINT64_C(    1767059605684224) },
      {  UINT64_C(  263101267679641600),  UINT64_C(  226183629527580672) },
      {  UINT64_C( 8419240565748531200),  UINT64_C( 7237876144882581504) } },
    { {  UINT32_C(          1494126417),  UINT32_C(          2089119004),  UINT32_C(          3082049261),  UINT32_C(          4196924770) },
      {  UINT64_C(        197251152704),  UINT64_C(        268603185280) },
      {  UINT64_C(      25248147546112),  UINT64_C(      34381207715840) },
      {  UINT64_C(    1615881442951168),  UINT64_C(    2200397293813760) },
      {  UINT64_C(  206832824697749504),  UINT64_C(  281650853608161280) },
      {  UINT64_C( 6618650390327984128),  UINT64_C( 9012827315461160960) } },
    { {  UINT32_C(          1061932609),  UINT32_C(          3019469384),  UINT32_C(           118604827),  UINT32_C(          2898400474) },
      {  UINT64_C(          7590708928),  UINT64_C(        185497630336) },
      {  UINT64_C(        971610742784),  UINT64_C(      23743696683008) },
      {  UINT64_C(      62183087538176),  UINT64_C(    1519596587712512) },
      {  UINT64_C(    7959435204886528),  UINT64_C(  194508363227201536) },
      {  UINT64_C(  254701926556368896),  UINT64_C( 6224267623270449152) } },
    { {  UINT32_C(          1126515365),  UINT32_C(          1326892419),  UINT32_C(          3901872564),  UINT32_C(          2484685396) },
      {  UINT64_C(        249719844096),  UINT64_C(        159019865344) },
      {  UINT64_C(      31964140044288),  UINT64_C(      20354542764032) },
      {  UINT64_C(    2045704962834432),  UINT64_C(    1302690736898048) },
      {  UINT64_C(  261850235242807296),  UINT64_C(  166744414322950144) },
      {  UINT64_C( 8379207527769833472),  UINT64_C( 5335821258334404608) } },
    { {  UINT32_C(          3231319799),  UINT32_C(          2513114367),  UINT32_C(          2407990444),  UINT32_C(           208000084) },
      {  UINT64_C(        154111388416),  UINT64_C(         13312005376) },
      {  UINT64_C(      19726257717248),  UINT64_C(       1703936688128) },
      {  UINT64_C(    1262480493903872),  UINT64_C(     109051948040192) },
      {  UINT64_C(  161597503219695616),  UINT64_C(   13958649349144576) },
      {  UINT64_C( 5171120103030259712),  UINT64_C(  446676779172626432) } },
    { {  UINT32_C(           640998312),  UINT32_C(           304953724),  UINT32_C(          2431254521),  UINT32_C(          3200055674) },
      {  UINT64_C(        155600289344),  UINT64_C(        204803563136) },
      {  UINT64_C(      19916837036032),  UINT64_C(      26214856081408) },
      {  UINT64_C(    1274677570306048),  UINT64_C(    1677750789210112) },
      {  UINT64_C(  163158728999174144),  UINT64_C(  214752101018894336) },
      {  UINT64_C( 5221079327973572608),  UINT64_C( 6872067232604618752) } },
    { {  UINT32_C(          4266993947),  UINT32_C(          3588491520),  UINT32_C(          2754733804),  UINT32_C(          4252867085) },
      {  UINT64_C(        176302963456),  UINT64_C(        272183493440) },
      {  UINT64_C(      22566779322368),  UINT64_C(      34839487160320) },
      {  UINT64_C(    1444273876631552),  UINT64_C(    2229727178260480) },
      {  UINT64_C(  184867056208838656),  UINT64_C(  285405078817341440) },
      {  UINT64_C( 5915745798682836992),  UINT64_C( 9132962522154926080) } },
    { {  UINT32_C(          1423141951),  UINT32_C(          2008556811),  UINT32_C(          2479572208),  UINT32_C(          3919478405) },
      {  UINT64_C(        158692621312),  UINT64_C(        250846617920) },
      {  UINT64_C(      20312655527936),  UINT64_C(      32108367093760) },
      {  UINT64_C(    1300009953787904),  UINT64_C(    2054935494000640) },
      {  UINT64_C(  166401274084851712),  UINT64_C(  263031743232081920) },
      {  UINT64_C( 5324840770715254784),  UINT64_C( 8417015783426621440) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint32x4_t a = simde_vld1q_u32(test_vec[i].a);
    simde_uint64x2_t r6 = simde_vshll_high_n_u32(a, 6);
    simde_uint64x2_t r13 = simde_vshll_high_n_u32(a, 13);
    simde_uint64x2_t r19 = simde_vshll_high_n_u32(a, 19);
    simde_uint64x2_t r26 = simde_vshll_high_n_u32(a, 26);
    simde_uint64x2_t r31 = simde_vshll_high_n_u32(a, 31);

    simde_test_arm_neon_assert_equal_u64x2(r6, simde_vld1q_u64(test_vec[i].r6));
    simde_test_arm_neon_assert_equal_u64x2(r13, simde_vld1q_u64(test_vec[i].r13));
    simde_test_arm_neon_assert_equal_u64x2(r19, simde_vld1q_u64(test_vec[i].r19));
    simde_test_arm_neon_assert_equal_u64x2(r26, simde_vld1q_u64(test_vec[i].r26));
    simde_test_arm_neon_assert_equal_u64x2(r31, simde_vld1q_u64(test_vec[i].r31));
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint32x4_t a = simde_test_arm_neon_random_u32x4();
    simde_uint64x2_t r6 = simde_vshll_high_n_u32(a, 6);
    simde_uint64x2_t r13 = simde_vshll_high_n_u32(a, 13);
    simde_uint64x2_t r19 = simde_vshll_high_n_u32(a, 19);
    simde_uint64x2_t r26 = simde_vshll_high_n_u32(a, 26);
    simde_uint64x2_t r31 = simde_vshll_high_n_u32(a, 31);

    simde_test_arm_neon_write_u32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u64x2(2, r6, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u64x2(2, r13, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u64x2(2, r19, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u64x2(2, r26, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u64x2(2, r31, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(vshll_high_n_s8)
SIMDE_TEST_FUNC_LIST_ENTRY(vshll_high_n_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vshll_high_n_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vshll_high_n_u8)
SIMDE_TEST_FUNC_LIST_ENTRY(vshll_high_n_u16)
SIMDE_TEST_FUNC_LIST_ENTRY(vshll_high_n_u32)
SIMDE_TEST_FUNC_LIST_END

#include "test-neon-footer.h"
