#define SIMDE_TEST_ARM_NEON_INSN addw_high

#include "test-neon.h"
#include "../../../simde/arm/neon/addw_high.h"

static int
test_simde_vaddw_high_s8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int16_t a[8];
    int8_t b[16];
    int16_t r[8];
  } test_vec[] = {
    { {  INT16_C( 23541),  INT16_C( 10181), -INT16_C( 30920),  INT16_C( 29810), -INT16_C( 14369),  INT16_C(  8626), -INT16_C(  8621),  INT16_C( 19588) },
      {  INT8_C( 120), -INT8_C(  90), -INT8_C(  45), -INT8_C(  11),  INT8_C( 119), -INT8_C(   3),  INT8_C(   3),  INT8_C(  41),
        -INT8_C(   7), -INT8_C(   7),  INT8_C(   1), -INT8_C( 118),  INT8_C(  56),  INT8_C(  21),  INT8_C(   0),  INT8_C(  45) },
      {  INT16_C( 23534),  INT16_C( 10174), -INT16_C( 30919),  INT16_C( 29692), -INT16_C( 14313),  INT16_C(  8647), -INT16_C(  8621),  INT16_C( 19633) } },
    { { -INT16_C( 14992), -INT16_C( 22187), -INT16_C( 14516),  INT16_C( 11037), -INT16_C( 12401), -INT16_C(  7604), -INT16_C( 11858),  INT16_C(  9774) },
      {  INT8_C( 119),  INT8_C(   1),  INT8_C(  27), -INT8_C(  18), -INT8_C(   1),  INT8_C(  31),  INT8_C(  24), -INT8_C(   8),
         INT8_C(  24),  INT8_C(  25), -INT8_C( 126),  INT8_C(  80),  INT8_C(  46), -INT8_C( 126),  INT8_C( 126), -INT8_C(  97) },
      { -INT16_C( 14968), -INT16_C( 22162), -INT16_C( 14642),  INT16_C( 11117), -INT16_C( 12355), -INT16_C(  7730), -INT16_C( 11732),  INT16_C(  9677) } },
    { { -INT16_C( 11449), -INT16_C( 27832),  INT16_C( 26010),  INT16_C( 10687),  INT16_C(  2869), -INT16_C(  7412),  INT16_C( 15068),  INT16_C( 21257) },
      {  INT8_C(  60),  INT8_C(  36),  INT8_C(  66),  INT8_C(  59),  INT8_C(  67),  INT8_C(  90),  INT8_C(  51),  INT8_C(  92),
         INT8_C( 115), -INT8_C(  75), -INT8_C(  84), -INT8_C(  94),  INT8_C(  55),  INT8_C(  42),  INT8_C(  65),  INT8_C( 126) },
      { -INT16_C( 11334), -INT16_C( 27907),  INT16_C( 25926),  INT16_C( 10593),  INT16_C(  2924), -INT16_C(  7370),  INT16_C( 15133),  INT16_C( 21383) } },
    { { -INT16_C( 30211), -INT16_C( 26607), -INT16_C( 12050),  INT16_C(  9153), -INT16_C( 12836), -INT16_C( 18426),  INT16_C(  3848),  INT16_C( 17420) },
      {  INT8_C(  52),  INT8_C(  78),      INT8_MAX,  INT8_C( 119), -INT8_C(  88), -INT8_C(  78), -INT8_C(  45),  INT8_C(  27),
         INT8_C( 103),      INT8_MIN, -INT8_C(  67), -INT8_C(  98), -INT8_C(  86), -INT8_C(   2),  INT8_C(  28), -INT8_C(  88) },
      { -INT16_C( 30108), -INT16_C( 26735), -INT16_C( 12117),  INT16_C(  9055), -INT16_C( 12922), -INT16_C( 18428),  INT16_C(  3876),  INT16_C( 17332) } },
    { {  INT16_C( 11655),  INT16_C( 30272),  INT16_C(   510), -INT16_C(  9575), -INT16_C( 24369), -INT16_C( 10350), -INT16_C( 24913), -INT16_C(  7397) },
      { -INT8_C(  20), -INT8_C( 102),  INT8_C(  91), -INT8_C( 108),  INT8_C(  76),  INT8_C(  46), -INT8_C(  80), -INT8_C(  77),
        -INT8_C(  82),  INT8_C( 109),  INT8_C(  81),  INT8_C(  89),  INT8_C( 108),  INT8_C( 109),  INT8_C(   1), -INT8_C(  13) },
      {  INT16_C( 11573),  INT16_C( 30381),  INT16_C(   591), -INT16_C(  9486), -INT16_C( 24261), -INT16_C( 10241), -INT16_C( 24912), -INT16_C(  7410) } },
    { {  INT16_C( 16794), -INT16_C( 26519),  INT16_C(   834),  INT16_C(  4466),  INT16_C(  1443),  INT16_C( 21224),  INT16_C(   931), -INT16_C( 28618) },
      { -INT8_C(  99), -INT8_C( 111),  INT8_C(  36), -INT8_C(  23), -INT8_C(  65), -INT8_C(  44), -INT8_C( 100),  INT8_C( 110),
         INT8_C(  66), -INT8_C(  19), -INT8_C(  57), -INT8_C(  82),  INT8_C(  90), -INT8_C(  56), -INT8_C(  95), -INT8_C(  11) },
      {  INT16_C( 16860), -INT16_C( 26538),  INT16_C(   777),  INT16_C(  4384),  INT16_C(  1533),  INT16_C( 21168),  INT16_C(   836), -INT16_C( 28629) } },
    { {  INT16_C(  2825),  INT16_C( 19341),  INT16_C(    14), -INT16_C( 20131),  INT16_C( 17669), -INT16_C( 22525),  INT16_C( 14665), -INT16_C(  6600) },
      { -INT8_C(  54),  INT8_C(  93), -INT8_C(  48), -INT8_C( 118),  INT8_C(  49),  INT8_C( 108), -INT8_C(   8),  INT8_C( 115),
         INT8_C(  90), -INT8_C(  65),  INT8_C(  33), -INT8_C(  76), -INT8_C( 121), -INT8_C(  61), -INT8_C(  87), -INT8_C( 112) },
      {  INT16_C(  2915),  INT16_C( 19276),  INT16_C(    47), -INT16_C( 20207),  INT16_C( 17548), -INT16_C( 22586),  INT16_C( 14578), -INT16_C(  6712) } },
    { {  INT16_C( 14286), -INT16_C(  8997),  INT16_C( 14391),  INT16_C( 15501), -INT16_C( 28546), -INT16_C( 14364),  INT16_C(  7626), -INT16_C( 27475) },
      {  INT8_C( 122),  INT8_C( 125),  INT8_C(  30), -INT8_C(  85), -INT8_C(  22),  INT8_C(  22),  INT8_C(  31),  INT8_C(  68),
        -INT8_C(  43),  INT8_C(  64), -INT8_C(   8),  INT8_C(  92),  INT8_C(   3), -INT8_C(  94), -INT8_C(  20), -INT8_C(  47) },
      {  INT16_C( 14243), -INT16_C(  8933),  INT16_C( 14383),  INT16_C( 15593), -INT16_C( 28543), -INT16_C( 14458),  INT16_C(  7606), -INT16_C( 27522) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x8_t a = simde_vld1q_s16(test_vec[i].a);
    simde_int8x16_t b = simde_vld1q_s8(test_vec[i].b);
    simde_int16x8_t r = simde_vaddw_high_s8(a, b);

    simde_test_arm_neon_assert_equal_i16x8(r, simde_vld1q_s16(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int16x8_t a = simde_test_arm_neon_random_i16x8();
    simde_int8x16_t b = simde_test_arm_neon_random_i8x16();
    simde_int16x8_t r = simde_vaddw_high_s8(a, b);

    simde_test_arm_neon_write_i16x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i8x16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i16x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vaddw_high_s16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int32_t a[4];
    int16_t b[8];
    int32_t r[4];
  } test_vec[] = {
    { {  INT32_C(  2039093453),  INT32_C(   519935452), -INT32_C(   433741944), -INT32_C(   762657082) },
      {  INT16_C( 22083), -INT16_C( 32736), -INT16_C( 31413), -INT16_C( 20010),  INT16_C( 27699),  INT16_C( 24145),  INT16_C( 28574),  INT16_C( 27522) },
      {  INT32_C(  2039121152),  INT32_C(   519959597), -INT32_C(   433713370), -INT32_C(   762629560) } },
    { {  INT32_C(  1675890055),  INT32_C(   713154978),  INT32_C(  1175496320), -INT32_C(  1340564883) },
      {  INT16_C( 14832),  INT16_C( 15152),  INT16_C(  1726), -INT16_C(  3348),  INT16_C( 15986),  INT16_C(  4432), -INT16_C( 11347),  INT16_C( 13436) },
      {  INT32_C(  1675906041),  INT32_C(   713159410),  INT32_C(  1175484973), -INT32_C(  1340551447) } },
    { { -INT32_C(  2104008224), -INT32_C(  1012066238),  INT32_C(   722058686),  INT32_C(  1222320728) },
      {  INT16_C(  2907),  INT16_C(  6532),  INT16_C( 28689), -INT16_C( 31733),  INT16_C( 23726),  INT16_C( 23445),  INT16_C(  4399),  INT16_C(  3983) },
      { -INT32_C(  2103984498), -INT32_C(  1012042793),  INT32_C(   722063085),  INT32_C(  1222324711) } },
    { { -INT32_C(  1248778638), -INT32_C(    42451394),  INT32_C(  1411940860), -INT32_C(    23329629) },
      {  INT16_C(  8207),  INT16_C(  8472),  INT16_C(  9105),  INT16_C( 16293),  INT16_C( 14975), -INT16_C( 20837),  INT16_C( 10827), -INT16_C( 16707) },
      { -INT32_C(  1248763663), -INT32_C(    42472231),  INT32_C(  1411951687), -INT32_C(    23346336) } },
    { { -INT32_C(  1888268463), -INT32_C(  1987253363),  INT32_C(   282965356), -INT32_C(   938575175) },
      {  INT16_C(  9882),  INT16_C( 11241), -INT16_C( 29110), -INT16_C( 13973),  INT16_C(  1736),  INT16_C(  5240),  INT16_C( 13616), -INT16_C( 32302) },
      { -INT32_C(  1888266727), -INT32_C(  1987248123),  INT32_C(   282978972), -INT32_C(   938607477) } },
    { {  INT32_C(   303121796), -INT32_C(  1667523280),  INT32_C(   195852626), -INT32_C(  1915438093) },
      { -INT16_C( 16927),  INT16_C( 11193),  INT16_C(  9292),  INT16_C(  5365),  INT16_C( 27946),  INT16_C( 23080), -INT16_C(  1374),  INT16_C( 10204) },
      {  INT32_C(   303149742), -INT32_C(  1667500200),  INT32_C(   195851252), -INT32_C(  1915427889) } },
    { {  INT32_C(  1866067263), -INT32_C(   586361718),  INT32_C(  1088993357),  INT32_C(  1439612019) },
      { -INT16_C( 30854), -INT16_C( 14720),  INT16_C( 30123), -INT16_C( 10790),  INT16_C(   994), -INT16_C( 31441),  INT16_C(  3069),  INT16_C( 15788) },
      {  INT32_C(  1866068257), -INT32_C(   586393159),  INT32_C(  1088996426),  INT32_C(  1439627807) } },
    { { -INT32_C(  2085820936),  INT32_C(   123779257), -INT32_C(   465090447),  INT32_C(  2134447365) },
      { -INT16_C( 17764),  INT16_C( 18245),  INT16_C(  7983),  INT16_C(  4636),  INT16_C( 19490),  INT16_C(  8343),  INT16_C( 17239),  INT16_C( 20573) },
      { -INT32_C(  2085801446),  INT32_C(   123787600), -INT32_C(   465073208),  INT32_C(  2134467938) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x4_t a = simde_vld1q_s32(test_vec[i].a);
    simde_int16x8_t b = simde_vld1q_s16(test_vec[i].b);
    simde_int32x4_t r = simde_vaddw_high_s16(a, b);

    simde_test_arm_neon_assert_equal_i32x4(r, simde_vld1q_s32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int32x4_t a = simde_test_arm_neon_random_i32x4();
    simde_int16x8_t b = simde_test_arm_neon_random_i16x8();
    simde_int32x4_t r = simde_vaddw_high_s16(a, b);

    simde_test_arm_neon_write_i32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i16x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vaddw_high_s32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int64_t a[2];
    int32_t b[4];
    int64_t r[2];
  } test_vec[] = {
    { { -INT64_C( 5849238384416326824),  INT64_C( 1277337534084417282) },
      {  INT32_C(   718341893),  INT32_C(  1336516965), -INT32_C(  1497986143), -INT32_C(  1836582855) },
      { -INT64_C( 5849238385914312967),  INT64_C( 1277337532247834427) } },
    { {  INT64_C( 2688498497482969075), -INT64_C( 5167571939423768705) },
      { -INT32_C(  2048779745),  INT32_C(  1574210491),  INT32_C(  1342409238),  INT32_C(  1977780866) },
      {  INT64_C( 2688498498825378313), -INT64_C( 5167571937445987839) } },
    { {  INT64_C( 9052628869669357145),  INT64_C( 4071532346031210517) },
      { -INT32_C(   742563305),  INT32_C(    70291949), -INT32_C(  1655426277),  INT32_C(   370292413) },
      {  INT64_C( 9052628868013930868),  INT64_C( 4071532346401502930) } },
    { { -INT64_C( 6757876032032593732),  INT64_C(  109470578694089779) },
      {  INT32_C(   986988876), -INT32_C(   314702638), -INT32_C(   192245193), -INT32_C(  2079679288) },
      { -INT64_C( 6757876032224838925),  INT64_C(  109470576614410491) } },
    { {  INT64_C(  284983309224615108), -INT64_C( 7688256677085225374) },
      { -INT32_C(   422633196),  INT32_C(  1557335333),  INT32_C(  1733320095), -INT32_C(  1108583687) },
      {  INT64_C(  284983310957935203), -INT64_C( 7688256678193809061) } },
    { {  INT64_C(  344528265312873462), -INT64_C(  126208633337800863) },
      { -INT32_C(   471593026), -INT32_C(  1136675044),  INT32_C(   220434196), -INT32_C(   540405783) },
      {  INT64_C(  344528265533307658), -INT64_C(  126208633878206646) } },
    { {  INT64_C( 4386626828125919546), -INT64_C( 8400015066188599164) },
      {  INT32_C(  1366184501),  INT32_C(   504212745),  INT32_C(   623587644),  INT32_C(  2063922752) },
      {  INT64_C( 4386626828749507190), -INT64_C( 8400015064124676412) } },
    { { -INT64_C( 7284793306056775473),  INT64_C( 2936196268991040871) },
      { -INT32_C(   763744824),  INT32_C(   384862170), -INT32_C(   113566792), -INT32_C(   529252591) },
      { -INT64_C( 7284793306170342265),  INT64_C( 2936196268461788280) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int64x2_t a = simde_vld1q_s64(test_vec[i].a);
    simde_int32x4_t b = simde_vld1q_s32(test_vec[i].b);
    simde_int64x2_t r = simde_vaddw_high_s32(a, b);

    simde_test_arm_neon_assert_equal_i64x2(r, simde_vld1q_s64(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int64x2_t a = simde_test_arm_neon_random_i64x2();
    simde_int32x4_t b = simde_test_arm_neon_random_i32x4();
    simde_int64x2_t r = simde_vaddw_high_s32(a, b);

    simde_test_arm_neon_write_i64x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vaddw_high_u8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint16_t a[8];
    uint8_t b[16];
    uint16_t r[8];
  } test_vec[] = {
    { { UINT16_C(52199), UINT16_C(64907), UINT16_C(29186), UINT16_C(27031), UINT16_C(41023), UINT16_C(13213), UINT16_C(23574), UINT16_C(57179) },
      { UINT8_C(137), UINT8_C(213), UINT8_C(177), UINT8_C( 99), UINT8_C( 93), UINT8_C(161), UINT8_C(121), UINT8_C( 21),
        UINT8_C(188), UINT8_C(180), UINT8_C( 14), UINT8_C(206), UINT8_C(243), UINT8_C(130), UINT8_C(174), UINT8_C(218) },
      { UINT16_C(52387), UINT16_C(65087), UINT16_C(29200), UINT16_C(27237), UINT16_C(41266), UINT16_C(13343), UINT16_C(23748), UINT16_C(57397) } },
    { { UINT16_C(14669), UINT16_C(20439), UINT16_C(28331), UINT16_C(60344), UINT16_C(21774), UINT16_C( 9502), UINT16_C(31153), UINT16_C(14852) },
      { UINT8_C( 79), UINT8_C(181), UINT8_C(157), UINT8_C(172), UINT8_C( 86), UINT8_C( 22), UINT8_C(193), UINT8_C( 18),
        UINT8_C(202), UINT8_C(208), UINT8_C(224), UINT8_C(189), UINT8_C( 82), UINT8_C(143), UINT8_C(152), UINT8_C(160) },
      { UINT16_C(14871), UINT16_C(20647), UINT16_C(28555), UINT16_C(60533), UINT16_C(21856), UINT16_C( 9645), UINT16_C(31305), UINT16_C(15012) } },
    { { UINT16_C(28616), UINT16_C(29935), UINT16_C(43230), UINT16_C(60511), UINT16_C(32253), UINT16_C(44817), UINT16_C( 5622), UINT16_C(17897) },
      { UINT8_C(202), UINT8_C(135), UINT8_C(241), UINT8_C( 32), UINT8_C(157), UINT8_C(179), UINT8_C( 51), UINT8_C(104),
        UINT8_C(131), UINT8_C( 19), UINT8_C( 37), UINT8_C(213), UINT8_C(162), UINT8_C(189), UINT8_C(117), UINT8_C(107) },
      { UINT16_C(28747), UINT16_C(29954), UINT16_C(43267), UINT16_C(60724), UINT16_C(32415), UINT16_C(45006), UINT16_C( 5739), UINT16_C(18004) } },
    { { UINT16_C(25901), UINT16_C( 3039), UINT16_C(15885), UINT16_C( 2807), UINT16_C( 2491), UINT16_C(45497), UINT16_C(41758), UINT16_C(59895) },
      { UINT8_C( 42), UINT8_C(232), UINT8_C(  9), UINT8_C(199), UINT8_C(155), UINT8_C( 60), UINT8_C( 47), UINT8_C( 30),
        UINT8_C( 80), UINT8_C( 85), UINT8_C(244), UINT8_C(242), UINT8_C( 18), UINT8_C(105), UINT8_C( 93), UINT8_C( 63) },
      { UINT16_C(25981), UINT16_C( 3124), UINT16_C(16129), UINT16_C( 3049), UINT16_C( 2509), UINT16_C(45602), UINT16_C(41851), UINT16_C(59958) } },
    { { UINT16_C(15566), UINT16_C(56138), UINT16_C(17018), UINT16_C(13798), UINT16_C(40779), UINT16_C(27111), UINT16_C(56898), UINT16_C(27730) },
      { UINT8_C(198), UINT8_C( 92), UINT8_C( 52), UINT8_C( 98), UINT8_C(152), UINT8_C( 99), UINT8_C(128), UINT8_C(232),
        UINT8_C(184), UINT8_C(116), UINT8_C(219), UINT8_C(203), UINT8_C(222), UINT8_C( 56), UINT8_C( 10), UINT8_C(172) },
      { UINT16_C(15750), UINT16_C(56254), UINT16_C(17237), UINT16_C(14001), UINT16_C(41001), UINT16_C(27167), UINT16_C(56908), UINT16_C(27902) } },
    { { UINT16_C(21877), UINT16_C(61320), UINT16_C(28311), UINT16_C(57893), UINT16_C( 3085), UINT16_C(20555), UINT16_C(40682), UINT16_C(45244) },
      { UINT8_C(250), UINT8_C(240), UINT8_C( 18), UINT8_C(146), UINT8_C( 84), UINT8_C(147), UINT8_C(123), UINT8_C( 12),
        UINT8_C(  7), UINT8_C( 86), UINT8_C(215), UINT8_C(229), UINT8_C(142), UINT8_C(226), UINT8_C(146), UINT8_C(  3) },
      { UINT16_C(21884), UINT16_C(61406), UINT16_C(28526), UINT16_C(58122), UINT16_C( 3227), UINT16_C(20781), UINT16_C(40828), UINT16_C(45247) } },
    { { UINT16_C( 6711), UINT16_C(52979), UINT16_C( 6280), UINT16_C(38320), UINT16_C(64292), UINT16_C( 3813), UINT16_C(41625), UINT16_C(37822) },
      { UINT8_C(146), UINT8_C(209), UINT8_C( 38), UINT8_C(230), UINT8_C(100), UINT8_C(161), UINT8_C(243), UINT8_C(107),
        UINT8_C(247), UINT8_C(202), UINT8_C( 81), UINT8_C(133), UINT8_C(172), UINT8_C(227), UINT8_C(137), UINT8_C(227) },
      { UINT16_C( 6958), UINT16_C(53181), UINT16_C( 6361), UINT16_C(38453), UINT16_C(64464), UINT16_C( 4040), UINT16_C(41762), UINT16_C(38049) } },
    { { UINT16_C(31997), UINT16_C(34225), UINT16_C(24980), UINT16_C(47130), UINT16_C(   93), UINT16_C(63174), UINT16_C(33954), UINT16_C(13450) },
      { UINT8_C( 85), UINT8_C(176), UINT8_C( 27), UINT8_C(185), UINT8_C( 81), UINT8_C( 14), UINT8_C( 37), UINT8_C( 72),
        UINT8_C(216), UINT8_C(118), UINT8_C(205), UINT8_C(133), UINT8_C( 89), UINT8_C( 86), UINT8_C(104), UINT8_C( 86) },
      { UINT16_C(32213), UINT16_C(34343), UINT16_C(25185), UINT16_C(47263), UINT16_C(  182), UINT16_C(63260), UINT16_C(34058), UINT16_C(13536) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint16x8_t a = simde_vld1q_u16(test_vec[i].a);
    simde_uint8x16_t b = simde_vld1q_u8(test_vec[i].b);
    simde_uint16x8_t r = simde_vaddw_high_u8(a, b);

    simde_test_arm_neon_assert_equal_u16x8(r, simde_vld1q_u16(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint16x8_t a = simde_test_arm_neon_random_u16x8();
    simde_uint8x16_t b = simde_test_arm_neon_random_u8x16();
    simde_uint16x8_t r = simde_vaddw_high_u8(a, b);

    simde_test_arm_neon_write_u16x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u8x16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u16x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vaddw_high_u16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint32_t a[4];
    uint16_t b[8];
    uint32_t r[4];
  } test_vec[] = {
    { { UINT32_C(1725635282), UINT32_C(3625907579), UINT32_C(2546984181), UINT32_C(3201063273) },
      { UINT16_C(59145), UINT16_C(23160), UINT16_C(40437), UINT16_C(52642), UINT16_C(28435), UINT16_C(27730), UINT16_C(48070), UINT16_C(39106) },
      { UINT32_C(1725663717), UINT32_C(3625935309), UINT32_C(2547032251), UINT32_C(3201102379) } },
    { { UINT32_C(1358929365), UINT32_C(2284395922), UINT32_C(1797257218), UINT32_C(1512696657) },
      { UINT16_C(41426), UINT16_C(51124), UINT16_C(22078), UINT16_C(20885), UINT16_C(59333), UINT16_C(35773), UINT16_C(32674), UINT16_C(30500) },
      { UINT32_C(1358988698), UINT32_C(2284431695), UINT32_C(1797289892), UINT32_C(1512727157) } },
    { { UINT32_C(2949128988), UINT32_C(1110962496), UINT32_C( 984438505), UINT32_C( 345298754) },
      { UINT16_C(18552), UINT16_C(47068), UINT16_C(29086), UINT16_C(25352), UINT16_C(50776), UINT16_C(64495), UINT16_C( 4933), UINT16_C(25202) },
      { UINT32_C(2949179764), UINT32_C(1111026991), UINT32_C( 984443438), UINT32_C( 345323956) } },
    { { UINT32_C(1980840502), UINT32_C( 347686955), UINT32_C(3763234462), UINT32_C(3069567549) },
      { UINT16_C(53546), UINT16_C(51309), UINT16_C(30018), UINT16_C(39468), UINT16_C( 6971), UINT16_C(33173), UINT16_C( 2094), UINT16_C(25827) },
      { UINT32_C(1980847473), UINT32_C( 347720128), UINT32_C(3763236556), UINT32_C(3069593376) } },
    { { UINT32_C(1859843138), UINT32_C(3665990460), UINT32_C( 935055866), UINT32_C(3740119219) },
      { UINT16_C(23169), UINT16_C(50086), UINT16_C(53968), UINT16_C( 2909), UINT16_C(62445), UINT16_C( 7052), UINT16_C(28667), UINT16_C(15743) },
      { UINT32_C(1859905583), UINT32_C(3665997512), UINT32_C( 935084533), UINT32_C(3740134962) } },
    { { UINT32_C(2678807139), UINT32_C(3883544301), UINT32_C(2988389887), UINT32_C(1720716517) },
      { UINT16_C(14183), UINT16_C(14121), UINT16_C(34313), UINT16_C(63298), UINT16_C(53113), UINT16_C(29714), UINT16_C(37438), UINT16_C(41650) },
      { UINT32_C(2678860252), UINT32_C(3883574015), UINT32_C(2988427325), UINT32_C(1720758167) } },
    { { UINT32_C(3644939756), UINT32_C(2327952267), UINT32_C(3577602288), UINT32_C(1396428268) },
      { UINT16_C(25604), UINT16_C( 3722), UINT16_C(52715), UINT16_C(25605), UINT16_C( 6044), UINT16_C(56025), UINT16_C(35753), UINT16_C(38268) },
      { UINT32_C(3644945800), UINT32_C(2328008292), UINT32_C(3577638041), UINT32_C(1396466536) } },
    { { UINT32_C(1953480424), UINT32_C(1795043449), UINT32_C(4232002320), UINT32_C( 223378185) },
      { UINT16_C(56031), UINT16_C(51739), UINT16_C( 8359), UINT16_C(17199), UINT16_C( 2104), UINT16_C(57630), UINT16_C(39571), UINT16_C(31607) },
      { UINT32_C(1953482528), UINT32_C(1795101079), UINT32_C(4232041891), UINT32_C( 223409792) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint32x4_t a = simde_vld1q_u32(test_vec[i].a);
    simde_uint16x8_t b = simde_vld1q_u16(test_vec[i].b);
    simde_uint32x4_t r = simde_vaddw_high_u16(a, b);
    simde_test_arm_neon_assert_equal_u32x4(r, simde_vld1q_u32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint32x4_t a = simde_test_arm_neon_random_u32x4();
    simde_uint16x8_t b = simde_test_arm_neon_random_u16x8();
    simde_uint32x4_t r = simde_vaddw_high_u16(a, b);

    simde_test_arm_neon_write_u32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u16x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vaddw_high_u32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint64_t a[2];
    uint32_t b[4];
    uint64_t r[2];
  } test_vec[] = {
    { { UINT64_C( 2755338853839529560), UINT64_C(15438465924354702121) },
      { UINT32_C(4104149837), UINT32_C(3023622012), UINT32_C(1788171991), UINT32_C(1239813360) },
      { UINT64_C( 2755338855627701551), UINT64_C(15438465925594515481) } },
    { { UINT64_C(17090694131083892210), UINT64_C( 1197781320401375698) },
      { UINT32_C( 923090875), UINT32_C(3874176271), UINT32_C(2203156627), UINT32_C(2144089997) },
      { UINT64_C(17090694133287048837), UINT64_C( 1197781322545465695) } },
    { { UINT64_C( 1278378250145949452), UINT64_C(17860002049292950535) },
      { UINT32_C(3341738168), UINT32_C(2964199709), UINT32_C( 641007513), UINT32_C(1118175286) },
      { UINT64_C( 1278378250786956965), UINT64_C(17860002050411125821) } },
    { { UINT64_C(17021301895468297960), UINT64_C( 4890788845655101868) },
      { UINT32_C(2416577907), UINT32_C(3208755238), UINT32_C(3991303607), UINT32_C(1563462773) },
      { UINT64_C(17021301899459601567), UINT64_C( 4890788847218564641) } },
    { { UINT64_C(13729992102635651770), UINT64_C( 5159583470156399053) },
      { UINT32_C(3101140370), UINT32_C( 360126557), UINT32_C(  50486669), UINT32_C(2740990697) },
      { UINT64_C(13729992102686138439), UINT64_C( 5159583472897389750) } },
    { { UINT64_C( 7873924513363321973), UINT64_C(  155760600566524686) },
      { UINT32_C(1639579652), UINT32_C(2792763673), UINT32_C(2024372623), UINT32_C( 538708651) },
      { UINT64_C( 7873924515387694596), UINT64_C(  155760601105233337) } },
    { { UINT64_C( 4106135152804454126), UINT64_C( 2542637266243338455) },
      { UINT32_C(1568932676), UINT32_C(3288595253), UINT32_C( 524070260), UINT32_C(2772457655) },
      { UINT64_C( 4106135153328524386), UINT64_C( 2542637269015796110) } },
    { { UINT64_C(12328938046261356470), UINT64_C(13488628841000940783) },
      { UINT32_C(1964553792), UINT32_C( 624499889), UINT32_C(2151970249), UINT32_C(2217051342) },
      { UINT64_C(12328938048413326719), UINT64_C(13488628843217992125) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint64x2_t a = simde_vld1q_u64(test_vec[i].a);
    simde_uint32x4_t b = simde_vld1q_u32(test_vec[i].b);
    simde_uint64x2_t r = simde_vaddw_high_u32(a, b);
    simde_test_arm_neon_assert_equal_u64x2(r, simde_vld1q_u64(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint64x2_t a = simde_test_arm_neon_random_u64x2();
    simde_uint32x4_t b = simde_test_arm_neon_random_u32x4();
    simde_uint64x2_t r = simde_vaddw_high_u32(a, b);

    simde_test_arm_neon_write_u64x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(vaddw_high_s8)
SIMDE_TEST_FUNC_LIST_ENTRY(vaddw_high_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vaddw_high_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vaddw_high_u8)
SIMDE_TEST_FUNC_LIST_ENTRY(vaddw_high_u16)
SIMDE_TEST_FUNC_LIST_ENTRY(vaddw_high_u32)
SIMDE_TEST_FUNC_LIST_END

#include "test-neon-footer.h"
