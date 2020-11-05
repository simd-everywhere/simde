#define SIMDE_TEST_ARM_NEON_INSN subw

#include "test-neon.h"
#include "../../../simde/arm/neon/subw.h"

static int
test_simde_vsubw_s8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int16_t a[8];
    int8_t b[8];
    int16_t r[8];
  } test_vec[] = {
    { {  INT16_C(  6820),  INT16_C( 27304),  INT16_C( 25938),  INT16_C(   515), -INT16_C( 18451),  INT16_C( 12057),  INT16_C( 26265), -INT16_C(  7182) },
      {  INT8_C(   5), -INT8_C(   1),  INT8_C(  74), -INT8_C(  78), -INT8_C(  49), -INT8_C(  82), -INT8_C(  53),  INT8_C(  15) },
      {  INT16_C(  6815),  INT16_C( 27305),  INT16_C( 25864),  INT16_C(   593), -INT16_C( 18402),  INT16_C( 12139),  INT16_C( 26318), -INT16_C(  7197) } },
    { {  INT16_C( 21054),  INT16_C( 20717),  INT16_C(  5564),  INT16_C( 24729),  INT16_C( 16687), -INT16_C( 32053), -INT16_C( 12633), -INT16_C( 27516) },
      { -INT8_C( 123), -INT8_C(  98), -INT8_C(  61),  INT8_C(  30),  INT8_C(   4), -INT8_C(  74),  INT8_C(   2),  INT8_C(  10) },
      {  INT16_C( 21177),  INT16_C( 20815),  INT16_C(  5625),  INT16_C( 24699),  INT16_C( 16683), -INT16_C( 31979), -INT16_C( 12635), -INT16_C( 27526) } },
    { {  INT16_C( 19637), -INT16_C( 31556), -INT16_C( 30726),  INT16_C( 14483), -INT16_C( 32550), -INT16_C( 27000),  INT16_C(  8854), -INT16_C( 14858) },
      {  INT8_C(  99), -INT8_C(  63),  INT8_C(  71),  INT8_C(  10), -INT8_C( 112), -INT8_C(  52), -INT8_C(  97),  INT8_C(  21) },
      {  INT16_C( 19538), -INT16_C( 31493), -INT16_C( 30797),  INT16_C( 14473), -INT16_C( 32438), -INT16_C( 26948),  INT16_C(  8951), -INT16_C( 14879) } },
    { {  INT16_C( 25194),  INT16_C( 28212),  INT16_C( 13848), -INT16_C( 12936),  INT16_C( 13442),  INT16_C( 31825), -INT16_C(  6724), -INT16_C( 26956) },
      {  INT8_C( 101),  INT8_C(  60),  INT8_C(  44), -INT8_C(   5),  INT8_C(  94),  INT8_C(  34), -INT8_C(  63), -INT8_C(  62) },
      {  INT16_C( 25093),  INT16_C( 28152),  INT16_C( 13804), -INT16_C( 12931),  INT16_C( 13348),  INT16_C( 31791), -INT16_C(  6661), -INT16_C( 26894) } },
    { {  INT16_C(  2276),  INT16_C( 29900),  INT16_C( 27604),  INT16_C( 16009), -INT16_C( 16946), -INT16_C(  6483),  INT16_C(  9715),  INT16_C( 30132) },
      {  INT8_C(  90),  INT8_C(   5), -INT8_C(  15),  INT8_C(  22), -INT8_C(  22), -INT8_C(  91), -INT8_C(  84),  INT8_C(  80) },
      {  INT16_C(  2186),  INT16_C( 29895),  INT16_C( 27619),  INT16_C( 15987), -INT16_C( 16924), -INT16_C(  6392),  INT16_C(  9799),  INT16_C( 30052) } },
    { { -INT16_C( 10014),  INT16_C( 16459),  INT16_C(  3322), -INT16_C(  8702), -INT16_C( 12523), -INT16_C(  5806), -INT16_C(  9158),  INT16_C(  2088) },
      { -INT8_C( 103), -INT8_C(  43), -INT8_C(  17), -INT8_C( 115), -INT8_C(   6), -INT8_C(  93),  INT8_C(   2),  INT8_C(  84) },
      { -INT16_C(  9911),  INT16_C( 16502),  INT16_C(  3339), -INT16_C(  8587), -INT16_C( 12517), -INT16_C(  5713), -INT16_C(  9160),  INT16_C(  2004) } },
    { { -INT16_C(  2904), -INT16_C( 27798),  INT16_C(  5785),  INT16_C( 31715),  INT16_C( 12014), -INT16_C(  5700), -INT16_C( 16837),  INT16_C( 20679) },
      { -INT8_C( 115),  INT8_C(  26),  INT8_C(  57), -INT8_C(  56), -INT8_C(  10),  INT8_C(  97), -INT8_C(  48), -INT8_C( 113) },
      { -INT16_C(  2789), -INT16_C( 27824),  INT16_C(  5728),  INT16_C( 31771),  INT16_C( 12024), -INT16_C(  5797), -INT16_C( 16789),  INT16_C( 20792) } },
    { { -INT16_C( 16586),  INT16_C( 12572),  INT16_C(  8034),  INT16_C(  2949), -INT16_C(  4077), -INT16_C( 21346), -INT16_C( 32506), -INT16_C(  2776) },
      { -INT8_C(  81), -INT8_C(  28), -INT8_C(  34), -INT8_C(  22), -INT8_C(  94), -INT8_C(  91),  INT8_C(  58),  INT8_C(  48) },
      { -INT16_C( 16505),  INT16_C( 12600),  INT16_C(  8068),  INT16_C(  2971), -INT16_C(  3983), -INT16_C( 21255), -INT16_C( 32564), -INT16_C(  2824) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x8_t a = simde_vld1q_s16(test_vec[i].a);
    simde_int8x8_t b = simde_vld1_s8(test_vec[i].b);
    simde_int16x8_t r = simde_vsubw_s8(a, b);

    simde_test_arm_neon_assert_equal_i16x8(r, simde_vld1q_s16(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int16x8_t a = simde_test_arm_neon_random_i16x8();
    simde_int8x8_t b = simde_test_arm_neon_random_i8x8();
    simde_int16x8_t r = simde_vsubw_s8(a, b);

    simde_test_arm_neon_write_i16x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i8x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i16x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vsubw_s16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int32_t a[4];
    int16_t b[4];
    int32_t r[4];
  } test_vec[] = {
    { { -INT32_C(  1242008385),  INT32_C(   205899989), -INT32_C(   365076088), -INT32_C(  1812610432) },
      { -INT16_C( 27726), -INT16_C( 18112),  INT16_C( 26644), -INT16_C( 15186) },
      { -INT32_C(  1241980659),  INT32_C(   205918101), -INT32_C(   365102732), -INT32_C(  1812595246) } },
    { { -INT32_C(   290550708), -INT32_C(   249632463),  INT32_C(   849745501),  INT32_C(  1732176863) },
      {  INT16_C( 31565), -INT16_C( 12975),  INT16_C( 18238), -INT16_C(  3999) },
      { -INT32_C(   290582273), -INT32_C(   249619488),  INT32_C(   849727263),  INT32_C(  1732180862) } },
    { { -INT32_C(   274095654),  INT32_C(  1437816585),  INT32_C(   356737507), -INT32_C(  1492753846) },
      { -INT16_C( 21384),  INT16_C( 22490),  INT16_C(  6296), -INT16_C(  6722) },
      { -INT32_C(   274074270),  INT32_C(  1437794095),  INT32_C(   356731211), -INT32_C(  1492747124) } },
    { { -INT32_C(   760082284),  INT32_C(   834802519), -INT32_C(  1121948492), -INT32_C(  1491938365) },
      {  INT16_C( 22069),  INT16_C( 32700), -INT16_C( 15688),  INT16_C( 12327) },
      { -INT32_C(   760104353),  INT32_C(   834769819), -INT32_C(  1121932804), -INT32_C(  1491950692) } },
    { {  INT32_C(   109576558), -INT32_C(  1377090023), -INT32_C(  1384145322),  INT32_C(  1725907633) },
      { -INT16_C(    82),  INT16_C( 28963),  INT16_C( 14035),  INT16_C(  2072) },
      {  INT32_C(   109576640), -INT32_C(  1377118986), -INT32_C(  1384159357),  INT32_C(  1725905561) } },
    { {  INT32_C(  1149752460),  INT32_C(    91532950), -INT32_C(   921961297), -INT32_C(  1720256701) },
      { -INT16_C(  2411),  INT16_C( 17991),  INT16_C(  9784), -INT16_C(  6484) },
      {  INT32_C(  1149754871),  INT32_C(    91514959), -INT32_C(   921971081), -INT32_C(  1720250217) } },
    { { -INT32_C(   128462811), -INT32_C(  1845465082), -INT32_C(   606697404), -INT32_C(   421508554) },
      { -INT16_C(  5305), -INT16_C( 30033),  INT16_C(  9698),  INT16_C( 30499) },
      { -INT32_C(   128457506), -INT32_C(  1845435049), -INT32_C(   606707102), -INT32_C(   421539053) } },
    { {  INT32_C(  1404987931), -INT32_C(  1237751152),  INT32_C(  1085182266),  INT32_C(  1171435265) },
      { -INT16_C( 22473),  INT16_C( 27936),  INT16_C(   243),  INT16_C( 14931) },
      {  INT32_C(  1405010404), -INT32_C(  1237779088),  INT32_C(  1085182023),  INT32_C(  1171420334) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x4_t a = simde_vld1q_s32(test_vec[i].a);
    simde_int16x4_t b = simde_vld1_s16(test_vec[i].b);
    simde_int32x4_t r = simde_vsubw_s16(a, b);

    simde_test_arm_neon_assert_equal_i32x4(r, simde_vld1q_s32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int32x4_t a = simde_test_arm_neon_random_i32x4();
    simde_int16x4_t b = simde_test_arm_neon_random_i16x4();
    simde_int32x4_t r = simde_vsubw_s16(a, b);

    simde_test_arm_neon_write_i32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i16x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vsubw_s32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int64_t a[2];
    int32_t b[2];
    int64_t r[2];
  } test_vec[] = {
    { {  INT64_C( 4847816211364578028), -INT64_C( 6225997310173182894) },
      {  INT32_C(  1659455329),  INT32_C(   766033142) },
      {  INT64_C( 4847816209705122699), -INT64_C( 6225997310939216036) } },
    { { -INT64_C( 5363243132695951260), -INT64_C( 8116391164187027984) },
      {  INT32_C(  1014100941),  INT32_C(   635767491) },
      { -INT64_C( 5363243133710052201), -INT64_C( 8116391164822795475) } },
    { { -INT64_C( 1192275730394263983), -INT64_C( 1335641659382821128) },
      {  INT32_C(  1778776365), -INT32_C(  1862704701) },
      { -INT64_C( 1192275732173040348), -INT64_C( 1335641657520116427) } },
    { { -INT64_C( 4161975364135130284), -INT64_C( 1370921726416927616) },
      { -INT32_C(  1934802801),  INT32_C(  1165566744) },
      { -INT64_C( 4161975362200327483), -INT64_C( 1370921727582494360) } },
    { {  INT64_C( 3778706870654500380),  INT64_C( 7948723524930911252) },
      {  INT32_C(  1115184206),  INT32_C(  1831760605) },
      {  INT64_C( 3778706869539316174),  INT64_C( 7948723523099150647) } },
    { {  INT64_C( 1877846008289418162),  INT64_C( 9008723632334749680) },
      { -INT32_C(  1811459674),  INT32_C(   688019163) },
      {  INT64_C( 1877846010100877836),  INT64_C( 9008723631646730517) } },
    { { -INT64_C( 6918204206961951821),  INT64_C( 6452664756106557044) },
      { -INT32_C(  1591114184), -INT32_C(  1759629584) },
      { -INT64_C( 6918204205370837637),  INT64_C( 6452664757866186628) } },
    { {  INT64_C( 3423912728348796288), -INT64_C(  273103808043683927) },
      {  INT32_C(   477011635),  INT32_C(  1316354582) },
      {  INT64_C( 3423912727871784653), -INT64_C(  273103809360038509) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int64x2_t a = simde_vld1q_s64(test_vec[i].a);
    simde_int32x2_t b = simde_vld1_s32(test_vec[i].b);
    simde_int64x2_t r = simde_vsubw_s32(a, b);

    simde_test_arm_neon_assert_equal_i64x2(r, simde_vld1q_s64(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int64x2_t a = simde_test_arm_neon_random_i64x2();
    simde_int32x2_t b = simde_test_arm_neon_random_i32x2();
    simde_int64x2_t r = simde_vsubw_s32(a, b);

    simde_test_arm_neon_write_i64x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i32x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vsubw_u8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint16_t a[8];
    uint8_t b[8];
    uint16_t r[8];
  } test_vec[] = {
    { { UINT16_C(40577), UINT16_C(29167), UINT16_C( 3789), UINT16_C(19720), UINT16_C(13363), UINT16_C(44968), UINT16_C(11362), UINT16_C( 3038) },
      { UINT8_C( 27), UINT8_C(158), UINT8_C(161), UINT8_C(163), UINT8_C( 91), UINT8_C(214), UINT8_C(159), UINT8_C( 14) },
      { UINT16_C(40550), UINT16_C(29009), UINT16_C( 3628), UINT16_C(19557), UINT16_C(13272), UINT16_C(44754), UINT16_C(11203), UINT16_C( 3024) } },
    { { UINT16_C( 3444), UINT16_C(35370), UINT16_C(40711), UINT16_C(35033), UINT16_C(51262), UINT16_C( 3066), UINT16_C(  726), UINT16_C( 2648) },
      { UINT8_C( 54), UINT8_C(  0), UINT8_C(185), UINT8_C(152), UINT8_C( 44), UINT8_C(152), UINT8_C(163), UINT8_C( 71) },
      { UINT16_C( 3390), UINT16_C(35370), UINT16_C(40526), UINT16_C(34881), UINT16_C(51218), UINT16_C( 2914), UINT16_C(  563), UINT16_C( 2577) } },
    { { UINT16_C(17462), UINT16_C(37354), UINT16_C(35098), UINT16_C(36511), UINT16_C(51862), UINT16_C(40217), UINT16_C(62057), UINT16_C(42790) },
      { UINT8_C(186), UINT8_C( 32), UINT8_C(178), UINT8_C(145), UINT8_C( 34), UINT8_C( 10), UINT8_C(155), UINT8_C( 89) },
      { UINT16_C(17276), UINT16_C(37322), UINT16_C(34920), UINT16_C(36366), UINT16_C(51828), UINT16_C(40207), UINT16_C(61902), UINT16_C(42701) } },
    { { UINT16_C(21514), UINT16_C(14065), UINT16_C(38380), UINT16_C( 8829), UINT16_C(26585), UINT16_C(62643), UINT16_C(21488), UINT16_C(34434) },
      { UINT8_C( 29), UINT8_C(155), UINT8_C( 36), UINT8_C(134), UINT8_C(141), UINT8_C( 74), UINT8_C( 46), UINT8_C( 72) },
      { UINT16_C(21485), UINT16_C(13910), UINT16_C(38344), UINT16_C( 8695), UINT16_C(26444), UINT16_C(62569), UINT16_C(21442), UINT16_C(34362) } },
    { { UINT16_C(57450), UINT16_C(36057), UINT16_C(29931), UINT16_C(62949), UINT16_C(55240), UINT16_C(46380), UINT16_C(43372), UINT16_C(17879) },
      { UINT8_C( 17), UINT8_C(139), UINT8_C( 57), UINT8_C(  1), UINT8_C(222), UINT8_C(188), UINT8_C(136), UINT8_C(251) },
      { UINT16_C(57433), UINT16_C(35918), UINT16_C(29874), UINT16_C(62948), UINT16_C(55018), UINT16_C(46192), UINT16_C(43236), UINT16_C(17628) } },
    { { UINT16_C(44119), UINT16_C(58753), UINT16_C(45046), UINT16_C(24621), UINT16_C( 1680), UINT16_C(31724), UINT16_C(53882), UINT16_C(17008) },
      { UINT8_C(169), UINT8_C(156), UINT8_C(247), UINT8_C( 21), UINT8_C( 70), UINT8_C(207), UINT8_C( 90), UINT8_C( 87) },
      { UINT16_C(43950), UINT16_C(58597), UINT16_C(44799), UINT16_C(24600), UINT16_C( 1610), UINT16_C(31517), UINT16_C(53792), UINT16_C(16921) } },
    { { UINT16_C(37978), UINT16_C(14424), UINT16_C(57424), UINT16_C(42803), UINT16_C(46220), UINT16_C(33420), UINT16_C(47460), UINT16_C(62690) },
      { UINT8_C(191), UINT8_C(207), UINT8_C(111), UINT8_C( 57), UINT8_C(161), UINT8_C(223), UINT8_C(124), UINT8_C( 74) },
      { UINT16_C(37787), UINT16_C(14217), UINT16_C(57313), UINT16_C(42746), UINT16_C(46059), UINT16_C(33197), UINT16_C(47336), UINT16_C(62616) } },
    { { UINT16_C(29564), UINT16_C(49759), UINT16_C(47426), UINT16_C(39961), UINT16_C(29005), UINT16_C(40404), UINT16_C( 1874), UINT16_C(56901) },
      { UINT8_C(188), UINT8_C(209), UINT8_C( 97), UINT8_C( 32), UINT8_C(139), UINT8_C( 67), UINT8_C( 20), UINT8_C( 74) },
      { UINT16_C(29376), UINT16_C(49550), UINT16_C(47329), UINT16_C(39929), UINT16_C(28866), UINT16_C(40337), UINT16_C( 1854), UINT16_C(56827) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint16x8_t a = simde_vld1q_u16(test_vec[i].a);
    simde_uint8x8_t b = simde_vld1_u8(test_vec[i].b);
    simde_uint16x8_t r = simde_vsubw_u8(a, b);

    simde_test_arm_neon_assert_equal_u16x8(r, simde_vld1q_u16(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint16x8_t a = simde_test_arm_neon_random_u16x8();
    simde_uint8x8_t b = simde_test_arm_neon_random_u8x8();
    simde_uint16x8_t r = simde_vsubw_u8(a, b);

    simde_test_arm_neon_write_u16x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u8x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u16x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vsubw_u16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint32_t a[4];
    uint16_t b[4];
    uint32_t r[4];
  } test_vec[] = {
    { { UINT32_C(3011805970), UINT32_C(3741122658), UINT32_C(3063962739), UINT32_C(1666365718) },
      { UINT16_C(10027), UINT16_C(32001), UINT16_C(17966), UINT16_C(59995) },
      { UINT32_C(3011795943), UINT32_C(3741090657), UINT32_C(3063944773), UINT32_C(1666305723) } },
    { { UINT32_C(2718612503), UINT32_C( 317529600), UINT32_C(  80114081), UINT32_C(3840066417) },
      { UINT16_C(33568), UINT16_C(13978), UINT16_C(60732), UINT16_C(26521) },
      { UINT32_C(2718578935), UINT32_C( 317515622), UINT32_C(  80053349), UINT32_C(3840039896) } },
    { { UINT32_C(1122277908), UINT32_C(4163715296), UINT32_C(4237965308), UINT32_C(4144990038) },
      { UINT16_C(54776), UINT16_C(27131), UINT16_C(56984), UINT16_C(47182) },
      { UINT32_C(1122223132), UINT32_C(4163688165), UINT32_C(4237908324), UINT32_C(4144942856) } },
    { { UINT32_C(2649679969), UINT32_C(3909454037), UINT32_C(  53274914), UINT32_C( 654006569) },
      { UINT16_C(38288), UINT16_C(58914), UINT16_C(12573), UINT16_C( 5598) },
      { UINT32_C(2649641681), UINT32_C(3909395123), UINT32_C(  53262341), UINT32_C( 654000971) } },
    { { UINT32_C(2675955974), UINT32_C( 408407479), UINT32_C(2343978677), UINT32_C(4034182094) },
      { UINT16_C(41124), UINT16_C(52979), UINT16_C(61177), UINT16_C(35572) },
      { UINT32_C(2675914850), UINT32_C( 408354500), UINT32_C(2343917500), UINT32_C(4034146522) } },
    { { UINT32_C(2708477572), UINT32_C(1320570440), UINT32_C(3756864808), UINT32_C(3103278338) },
      { UINT16_C(44683), UINT16_C(22851), UINT16_C(46953), UINT16_C( 3401) },
      { UINT32_C(2708432889), UINT32_C(1320547589), UINT32_C(3756817855), UINT32_C(3103274937) } },
    { { UINT32_C(1373322584), UINT32_C(2950418219), UINT32_C( 777014502), UINT32_C(3262908314) },
      { UINT16_C(27196), UINT16_C(16290), UINT16_C(39599), UINT16_C(15095) },
      { UINT32_C(1373295388), UINT32_C(2950401929), UINT32_C( 776974903), UINT32_C(3262893219) } },
    { { UINT32_C(2979215944), UINT32_C(1237245169), UINT32_C(1167825433), UINT32_C(1341421161) },
      { UINT16_C(17858), UINT16_C(23933), UINT16_C(64076), UINT16_C(34847) },
      { UINT32_C(2979198086), UINT32_C(1237221236), UINT32_C(1167761357), UINT32_C(1341386314) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint32x4_t a = simde_vld1q_u32(test_vec[i].a);
    simde_uint16x4_t b = simde_vld1_u16(test_vec[i].b);
    simde_uint32x4_t r = simde_vsubw_u16(a, b);
    simde_test_arm_neon_assert_equal_u32x4(r, simde_vld1q_u32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint32x4_t a = simde_test_arm_neon_random_u32x4();
    simde_uint16x4_t b = simde_test_arm_neon_random_u16x4();
    simde_uint32x4_t r = simde_vsubw_u16(a, b);

    simde_test_arm_neon_write_u32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u16x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vsubw_u32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint64_t a[2];
    uint32_t b[2];
    uint64_t r[2];
  } test_vec[] = {
    { { UINT64_C(11767270699772133732), UINT64_C(15434702050035032312) },
      { UINT32_C( 370921133), UINT32_C( 124129093) },
      { UINT64_C(11767270699401212599), UINT64_C(15434702049910903219) } },
    { { UINT64_C( 4695430173924057940), UINT64_C(12052936278448336965) },
      { UINT32_C(1049729409), UINT32_C(1494533548) },
      { UINT64_C( 4695430172874328531), UINT64_C(12052936276953803417) } },
    { { UINT64_C(10655751184254447507), UINT64_C( 1069706928083649721) },
      { UINT32_C(4239338573), UINT32_C(1336144846) },
      { UINT64_C(10655751180015108934), UINT64_C( 1069706926747504875) } },
    { { UINT64_C(10201112727033558412), UINT64_C(10349912778846110160) },
      { UINT32_C(1395053962), UINT32_C(2137128498) },
      { UINT64_C(10201112725638504450), UINT64_C(10349912776708981662) } },
    { { UINT64_C(10396592742187339818), UINT64_C( 5177831665045132627) },
      { UINT32_C( 827736411), UINT32_C( 297924743) },
      { UINT64_C(10396592741359603407), UINT64_C( 5177831664747207884) } },
    { { UINT64_C( 1116828819955967950), UINT64_C( 7811863096301517525) },
      { UINT32_C(2629382437), UINT32_C(3873739915) },
      { UINT64_C( 1116828817326585513), UINT64_C( 7811863092427777610) } },
    { { UINT64_C(  103258656087751381), UINT64_C( 7905084639033807552) },
      { UINT32_C(2454109306), UINT32_C( 855551756) },
      { UINT64_C(  103258653633642075), UINT64_C( 7905084638178255796) } },
    { { UINT64_C( 2473516661669279969), UINT64_C(  297778827730250733) },
      { UINT32_C(1470702271), UINT32_C( 482631074) },
      { UINT64_C( 2473516660198577698), UINT64_C(  297778827247619659) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint64x2_t a = simde_vld1q_u64(test_vec[i].a);
    simde_uint32x2_t b = simde_vld1_u32(test_vec[i].b);
    simde_uint64x2_t r = simde_vsubw_u32(a, b);
    simde_test_arm_neon_assert_equal_u64x2(r, simde_vld1q_u64(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint64x2_t a = simde_test_arm_neon_random_u64x2();
    simde_uint32x2_t b = simde_test_arm_neon_random_u32x2();
    simde_uint64x2_t r = simde_vsubw_u32(a, b);

    simde_test_arm_neon_write_u64x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u32x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(vsubw_s8)
SIMDE_TEST_FUNC_LIST_ENTRY(vsubw_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vsubw_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vsubw_u8)
SIMDE_TEST_FUNC_LIST_ENTRY(vsubw_u16)
SIMDE_TEST_FUNC_LIST_ENTRY(vsubw_u32)
SIMDE_TEST_FUNC_LIST_END

#include "test-neon-footer.h"
