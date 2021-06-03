#define SIMDE_TEST_ARM_NEON_INSN subhn

#include "test-neon.h"
#include "../../../simde/arm/neon/subhn.h"

static int
test_simde_vsubhn_s16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int16_t a[8];
    int16_t b[8];
    int8_t r[8];
  } test_vec[] = {
    { { -INT16_C( 13481),  INT16_C( 21295),  INT16_C(  9887),  INT16_C( 13474), -INT16_C(  5272), -INT16_C( 31502),  INT16_C( 27519),  INT16_C( 29883) },
      { -INT16_C(  9967),  INT16_C( 25824), -INT16_C( 15689),  INT16_C( 19378),  INT16_C(  7903),  INT16_C( 23080),  INT16_C( 23790),  INT16_C( 17891) },
      { -INT8_C(  14), -INT8_C(  18),  INT8_C(  99), -INT8_C(  24), -INT8_C(  52),  INT8_C(  42),  INT8_C(  14),  INT8_C(  46) } },
    { {  INT16_C(  4904), -INT16_C( 14440),  INT16_C( 14905), -INT16_C( 24068), -INT16_C(  4571), -INT16_C( 23258), -INT16_C(  7847),  INT16_C( 27161) },
      { -INT16_C(  1606),  INT16_C( 29135), -INT16_C( 32325), -INT16_C( 25667), -INT16_C(  6753), -INT16_C( 29195), -INT16_C(  9919),  INT16_C( 27090) },
      {  INT8_C(  25),  INT8_C(  85), -INT8_C(  72),  INT8_C(   6),  INT8_C(   8),  INT8_C(  23),  INT8_C(   8),  INT8_C(   0) } },
    { {  INT16_C( 27372),  INT16_C(  9521),  INT16_C( 11684), -INT16_C( 13625), -INT16_C(  4837),  INT16_C( 29807), -INT16_C( 30514), -INT16_C( 30242) },
      { -INT16_C( 21119),  INT16_C( 15866), -INT16_C( 18642), -INT16_C( 12840), -INT16_C( 12900), -INT16_C(  8614),  INT16_C( 11430), -INT16_C( 28089) },
      { -INT8_C(  67), -INT8_C(  25),  INT8_C( 118), -INT8_C(   4),  INT8_C(  31), -INT8_C( 106),  INT8_C(  92), -INT8_C(   9) } },
    { {  INT16_C( 30870),  INT16_C( 15288),  INT16_C( 32677), -INT16_C( 16379),  INT16_C( 29804),  INT16_C( 14900),  INT16_C(  5116),  INT16_C( 32195) },
      { -INT16_C( 16704), -INT16_C(  4166), -INT16_C( 28043),  INT16_C(  4796),  INT16_C(  5984),  INT16_C(  1776),  INT16_C( 14147), -INT16_C(  9575) },
      { -INT8_C(  71),  INT8_C(  75), -INT8_C(  19), -INT8_C(  83),  INT8_C(  93),  INT8_C(  51), -INT8_C(  36), -INT8_C(  93) } },
    { {  INT16_C( 20912),  INT16_C( 21781),  INT16_C(  6864),  INT16_C( 15382),  INT16_C( 19086), -INT16_C( 30090),  INT16_C( 14941),  INT16_C(  7687) },
      { -INT16_C( 15624),  INT16_C( 27917), -INT16_C( 13996), -INT16_C( 19329),  INT16_C( 28640),  INT16_C(  9403),  INT16_C( 21671),  INT16_C( 22526) },
      { -INT8_C( 114), -INT8_C(  24),  INT8_C(  81), -INT8_C( 121), -INT8_C(  38),  INT8_C( 101), -INT8_C(  27), -INT8_C(  58) } },
    { {  INT16_C(  5029),  INT16_C( 30124), -INT16_C( 15827), -INT16_C( 17487),  INT16_C(  9997),  INT16_C( 27205),  INT16_C( 19553),  INT16_C( 22920) },
      { -INT16_C( 27378),  INT16_C( 25543),  INT16_C( 18015),  INT16_C( 16151), -INT16_C( 11594),  INT16_C( 23907),  INT16_C( 24870), -INT16_C( 13388) },
      {  INT8_C( 126),  INT8_C(  17),  INT8_C( 123),  INT8_C( 124),  INT8_C(  84),  INT8_C(  12), -INT8_C(  21), -INT8_C( 115) } },
    { {  INT16_C( 24692), -INT16_C( 24256), -INT16_C(  3805),  INT16_C( 12380), -INT16_C( 24295),  INT16_C( 31386),  INT16_C(  9198), -INT16_C(   812) },
      { -INT16_C( 25672),  INT16_C(  5983),  INT16_C( 30689), -INT16_C( 26793), -INT16_C( 17847),  INT16_C( 28916), -INT16_C( 22500), -INT16_C( 28613) },
      { -INT8_C(  60), -INT8_C( 119),  INT8_C( 121), -INT8_C( 103), -INT8_C(  26),  INT8_C(   9),  INT8_C( 123),  INT8_C( 108) } },
    { {  INT16_C( 31753),  INT16_C( 11314), -INT16_C( 29075), -INT16_C( 31140), -INT16_C(  2512),  INT16_C(  7681), -INT16_C( 10983), -INT16_C( 11750) },
      {  INT16_C( 31344),  INT16_C( 20969),  INT16_C( 16625),  INT16_C( 15081), -INT16_C(  8709),  INT16_C(  6058), -INT16_C(  6522), -INT16_C( 28761) },
      {  INT8_C(   1), -INT8_C(  38),  INT8_C(  77),  INT8_C(  75),  INT8_C(  24),  INT8_C(   6), -INT8_C(  18),  INT8_C(  66) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x8_t a = simde_vld1q_s16(test_vec[i].a);
    simde_int16x8_t b = simde_vld1q_s16(test_vec[i].b);
    simde_int8x8_t r = simde_vsubhn_s16(a, b);

    simde_test_arm_neon_assert_equal_i8x8(r, simde_vld1_s8(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int16x8_t a = simde_test_arm_neon_random_i16x8();
    simde_int16x8_t b = simde_test_arm_neon_random_i16x8();
    simde_int8x8_t r = simde_vsubhn_s16(a, b);

    simde_test_arm_neon_write_i16x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i16x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i8x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vsubhn_s32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int32_t a[4];
    int32_t b[4];
    int16_t r[4];
  } test_vec[] = {
    { { -INT32_C(   809772702), -INT32_C(  1739188376),  INT32_C(   666261261), -INT32_C(  1661349844) },
      {  INT32_C(  1005445706),  INT32_C(   511104547),  INT32_C(   976560308),  INT32_C(  1758059526) },
      { -INT16_C( 27699),  INT16_C( 31199), -INT16_C(  4735),  INT16_C( 13359) } },
    { {  INT32_C(   507020470), -INT32_C(  1464430949),  INT32_C(   298806501), -INT32_C(  2018654148) },
      { -INT32_C(   826107221),  INT32_C(   636237937),  INT32_C(  1600069977), -INT32_C(  1278727939) },
      {  INT16_C( 20341), -INT16_C( 32054), -INT16_C( 19856), -INT16_C( 11291) } },
    { {  INT32_C(  1204879532),  INT32_C(  1945077646),  INT32_C(   814006259),  INT32_C(   850866567) },
      {  INT32_C(  1006664139),  INT32_C(   190966962),  INT32_C(   191545357), -INT32_C(  1799474456) },
      {  INT16_C(  3024),  INT16_C( 26765),  INT16_C(  9497), -INT16_C( 25096) } },
    { { -INT32_C(  1059352526),  INT32_C(   187943703),  INT32_C(   289126282), -INT32_C(  1270549784) },
      {  INT32_C(   502285419),  INT32_C(  1042829873), -INT32_C(    79064302), -INT32_C(   124843835) },
      { -INT16_C( 23829), -INT16_C( 13045),  INT16_C(  5618), -INT16_C( 17483) } },
    { { -INT32_C(  1346868328), -INT32_C(  1061491658), -INT32_C(  1932397149),  INT32_C(  1396708839) },
      { -INT32_C(  1955581862), -INT32_C(  1781950078), -INT32_C(   242216148), -INT32_C(  1276567781) },
      {  INT16_C(  9288),  INT16_C( 10993), -INT16_C( 25791), -INT16_C( 24746) } },
    { { -INT32_C(  1067277686),  INT32_C(   830479758), -INT32_C(    88255982), -INT32_C(  1051853465) },
      { -INT32_C(  1337148114), -INT32_C(  2109401514),  INT32_C(  1148507433),  INT32_C(  2146917877) },
      {  INT16_C(  4117), -INT16_C( 20677), -INT16_C( 18872),  INT16_C( 16726) } },
    { { -INT32_C(  1925162497), -INT32_C(  1983922058),  INT32_C(  2055437330), -INT32_C(  1472475014) },
      { -INT32_C(   463959923), -INT32_C(   949576034),  INT32_C(  1745607283),  INT32_C(   937951800) },
      { -INT16_C( 22297), -INT16_C( 15783),  INT16_C(  4727),  INT16_C( 28755) } },
    { { -INT32_C(   758831013), -INT32_C(    77888280),  INT32_C(  2054544896),  INT32_C(   992129198) },
      { -INT32_C(   702579912), -INT32_C(  1935833575), -INT32_C(  1728731040),  INT32_C(   114351530) },
      { -INT16_C(   859),  INT16_C( 28349), -INT16_C(  7808),  INT16_C( 13393) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x4_t a = simde_vld1q_s32(test_vec[i].a);
    simde_int32x4_t b = simde_vld1q_s32(test_vec[i].b);
    simde_int16x4_t r = simde_vsubhn_s32(a, b);

    simde_test_arm_neon_assert_equal_i16x4(r, simde_vld1_s16(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int32x4_t a = simde_test_arm_neon_random_i32x4();
    simde_int32x4_t b = simde_test_arm_neon_random_i32x4();
    simde_int16x4_t r = simde_vsubhn_s32(a, b);

    simde_test_arm_neon_write_i32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i16x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vsubhn_s64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int64_t a[2];
    int64_t b[2];
    int32_t r[2];
  } test_vec[] = {
    { {  INT64_C( 1866798232002663685),  INT64_C( 5114600501292588305) },
      {  INT64_C(   60722317593745969), -INT64_C( 5903258511754015645) },
      {  INT32_C(   420509817), -INT32_C(  1729672091) } },
    { {  INT64_C( 3400362983444704254), -INT64_C( 6037381531927919391) },
      {  INT64_C( 8116557511432557315), -INT64_C( 6633360637152052070) },
      { -INT32_C(  1098074608),  INT32_C(   138762198) } },
    { { -INT64_C(  951408439694029699), -INT64_C( 6496697952187074129) },
      {  INT64_C( 3956672429422071402),  INT64_C( 8462662791654368808) },
      { -INT32_C(  1142751628),  INT32_C(   811969705) } },
    { { -INT64_C( 4109012293049635594),  INT64_C( 6691725563988662933) },
      {  INT64_C( 4208821733342586262),  INT64_C( 4724409372594725155) },
      { -INT32_C(  1936646651),  INT32_C(   458051495) } },
    { {  INT64_C( 1261924324584497573), -INT64_C( 3284770938833767396) },
      {  INT64_C( 2276407967807192907), -INT64_C( 4694497830063333555) },
      { -INT32_C(   236202880),  INT32_C(   328227619) } },
    { {  INT64_C( 9221961792555197036), -INT64_C( 5368299098035371151) },
      {  INT64_C( 4346723435185079095), -INT64_C( 4242762100036563640) },
      {  INT32_C(  1135104884), -INT32_C(   262059504) } },
    { {  INT64_C(  627031235711900112),  INT64_C( 8001547679042978028) },
      {  INT64_C( 1073252844802547128),  INT64_C( 4008640620539066754) },
      { -INT32_C(   103894065),  INT32_C(   929671120) } },
    { { -INT64_C( 1890352989438587098),  INT64_C( 7423698755720542814) },
      {  INT64_C( 2321593088768714851),  INT64_C( 6362350637505291693) },
      { -INT32_C(   980670117),  INT32_C(   247114365) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int64x2_t a = simde_vld1q_s64(test_vec[i].a);
    simde_int64x2_t b = simde_vld1q_s64(test_vec[i].b);
    simde_int32x2_t r = simde_vsubhn_s64(a, b);

    simde_test_arm_neon_assert_equal_i32x2(r, simde_vld1_s32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int64x2_t a = simde_test_arm_neon_random_i64x2();
    simde_int64x2_t b = simde_test_arm_neon_random_i64x2();
    simde_int32x2_t r = simde_vsubhn_s64(a, b);

    simde_test_arm_neon_write_i64x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i64x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i32x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vsubhn_u16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint16_t a[8];
    uint16_t b[8];
    uint8_t r[8];
  } test_vec[] = {
    { { UINT16_C(46572), UINT16_C(58389), UINT16_C(55763), UINT16_C(12745), UINT16_C( 1107), UINT16_C(  711), UINT16_C(52554), UINT16_C(44394) },
      { UINT16_C(31094), UINT16_C( 5078), UINT16_C( 3437), UINT16_C( 6707), UINT16_C(12211), UINT16_C(58670), UINT16_C(31179), UINT16_C(46910) },
      { UINT8_C( 60), UINT8_C(208), UINT8_C(204), UINT8_C( 23), UINT8_C(212), UINT8_C( 29), UINT8_C( 83), UINT8_C(246) } },
    { { UINT16_C(21295), UINT16_C(  668), UINT16_C(25900), UINT16_C(32819), UINT16_C(64106), UINT16_C(46210), UINT16_C(60616), UINT16_C(15970) },
      { UINT16_C(14438), UINT16_C(54097), UINT16_C(34118), UINT16_C(63982), UINT16_C( 7348), UINT16_C(32734), UINT16_C( 7318), UINT16_C(50487) },
      { UINT8_C( 26), UINT8_C( 47), UINT8_C(223), UINT8_C(134), UINT8_C(221), UINT8_C( 52), UINT8_C(208), UINT8_C(121) } },
    { { UINT16_C(54127), UINT16_C(40135), UINT16_C(64056), UINT16_C(41500), UINT16_C(40692), UINT16_C(48215), UINT16_C(47499), UINT16_C(61946) },
      { UINT16_C(19697), UINT16_C(14276), UINT16_C(45777), UINT16_C(34096), UINT16_C( 4047), UINT16_C(25860), UINT16_C(15147), UINT16_C(39722) },
      { UINT8_C(134), UINT8_C(101), UINT8_C( 71), UINT8_C( 28), UINT8_C(143), UINT8_C( 87), UINT8_C(126), UINT8_C( 86) } },
    { { UINT16_C(61710), UINT16_C(18231), UINT16_C(21483), UINT16_C(57321), UINT16_C(16625), UINT16_C(31900), UINT16_C(38649), UINT16_C(60269) },
      { UINT16_C(13026), UINT16_C(45858), UINT16_C(21476), UINT16_C(45880), UINT16_C(15714), UINT16_C(36120), UINT16_C(17016), UINT16_C(34600) },
      { UINT8_C(190), UINT8_C(148), UINT8_C(  0), UINT8_C( 44), UINT8_C(  3), UINT8_C(239), UINT8_C( 84), UINT8_C(100) } },
    { { UINT16_C(24371), UINT16_C( 7886), UINT16_C(47026), UINT16_C(42238), UINT16_C(39672), UINT16_C(61728), UINT16_C(36400), UINT16_C( 5084) },
      { UINT16_C(65472), UINT16_C(42182), UINT16_C(65362), UINT16_C(46168), UINT16_C(28732), UINT16_C(46145), UINT16_C(27315), UINT16_C(58939) },
      { UINT8_C( 95), UINT8_C(122), UINT8_C(184), UINT8_C(240), UINT8_C( 42), UINT8_C( 60), UINT8_C( 35), UINT8_C( 45) } },
    { { UINT16_C( 2505), UINT16_C(31749), UINT16_C(  961), UINT16_C(47392), UINT16_C(16541), UINT16_C(52650), UINT16_C(34766), UINT16_C(36576) },
      { UINT16_C(42886), UINT16_C(55347), UINT16_C(35750), UINT16_C(57996), UINT16_C(52731), UINT16_C(44694), UINT16_C(53815), UINT16_C(  405) },
      { UINT8_C( 98), UINT8_C(163), UINT8_C(120), UINT8_C(214), UINT8_C(114), UINT8_C( 31), UINT8_C(181), UINT8_C(141) } },
    { { UINT16_C(39643), UINT16_C(40061), UINT16_C(40349), UINT16_C(14933), UINT16_C(  221), UINT16_C(44039), UINT16_C(59527), UINT16_C( 3386) },
      { UINT16_C(28047), UINT16_C(13797), UINT16_C(29176), UINT16_C(62487), UINT16_C(44350), UINT16_C(30370), UINT16_C(14207), UINT16_C(23415) },
      { UINT8_C( 45), UINT8_C(102), UINT8_C( 43), UINT8_C( 70), UINT8_C( 83), UINT8_C( 53), UINT8_C(177), UINT8_C(177) } },
    { { UINT16_C(62673), UINT16_C(28407), UINT16_C(19857), UINT16_C(28328), UINT16_C(45133), UINT16_C(54298), UINT16_C(21912), UINT16_C(10209) },
      { UINT16_C(50882), UINT16_C(47964), UINT16_C(29495), UINT16_C(30127), UINT16_C(20768), UINT16_C(41195), UINT16_C(25225), UINT16_C(23291) },
      { UINT8_C( 46), UINT8_C(179), UINT8_C(218), UINT8_C(248), UINT8_C( 95), UINT8_C( 51), UINT8_C(243), UINT8_C(204) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint16x8_t a = simde_vld1q_u16(test_vec[i].a);
    simde_uint16x8_t b = simde_vld1q_u16(test_vec[i].b);
    simde_uint8x8_t r = simde_vsubhn_u16(a, b);

    simde_test_arm_neon_assert_equal_u8x8(r, simde_vld1_u8(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint16x8_t a = simde_test_arm_neon_random_u16x8();
    simde_uint16x8_t b = simde_test_arm_neon_random_u16x8();
    simde_uint8x8_t r = simde_vsubhn_u16(a, b);

    simde_test_arm_neon_write_u16x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u16x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u8x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vsubhn_u32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint32_t a[4];
    uint32_t b[4];
    uint16_t r[4];
  } test_vec[] = {
    { { UINT32_C(3888771670), UINT32_C(2354475327), UINT32_C(3110105121), UINT32_C(2296398277) },
      { UINT32_C(1044593671), UINT32_C(3501519535), UINT32_C(3429932867), UINT32_C(1478978306) },
      { UINT16_C(43398), UINT16_C(48033), UINT16_C(60655), UINT16_C(12472) } },
    { { UINT32_C(2638278749), UINT32_C(2200540769), UINT32_C(3426519558), UINT32_C(3545505227) },
      { UINT32_C( 152147801), UINT32_C(3436823945), UINT32_C(1738099045), UINT32_C( 297779380) },
      { UINT16_C(37935), UINT16_C(46671), UINT16_C(25763), UINT16_C(49556) } },
    { { UINT32_C( 296681392), UINT32_C(2627000469), UINT32_C( 761844066), UINT32_C(1191230702) },
      { UINT32_C(3696235091), UINT32_C(1017653719), UINT32_C( 648233330), UINT32_C(2973262593) },
      { UINT16_C(13662), UINT16_C(24556), UINT16_C( 1733), UINT16_C(38344) } },
    { { UINT32_C(4173588066), UINT32_C( 546592702), UINT32_C( 374275112), UINT32_C( 190729912) },
      { UINT32_C( 954707552), UINT32_C(1249152984), UINT32_C(3530627281), UINT32_C(3716458875) },
      { UINT16_C(49116), UINT16_C(54815), UINT16_C(17373), UINT16_C(11737) } },
    { { UINT32_C(1322600335), UINT32_C(3345901982), UINT32_C( 501070949), UINT32_C(1797798667) },
      { UINT32_C(3265466346), UINT32_C(1879840927), UINT32_C(2873261360), UINT32_C(3062416934) },
      { UINT16_C(35890), UINT16_C(22370), UINT16_C(29339), UINT16_C(46239) } },
    { { UINT32_C(2885967373), UINT32_C( 762540743), UINT32_C( 977948719), UINT32_C(1990554508) },
      { UINT32_C( 557336962), UINT32_C(2442216545), UINT32_C(3896300738), UINT32_C(2828977306) },
      { UINT16_C(35532), UINT16_C(39906), UINT16_C(21005), UINT16_C(52742) } },
    { { UINT32_C(3931415074), UINT32_C(1142408981), UINT32_C(2742968599), UINT32_C(1461265364) },
      { UINT32_C(3447214444), UINT32_C(1482558102), UINT32_C(2017499870), UINT32_C(2166415199) },
      { UINT16_C( 7388), UINT16_C(60345), UINT16_C(11069), UINT16_C(54776) } },
    { { UINT32_C(2523624577), UINT32_C(1406829115), UINT32_C(3103152356), UINT32_C(3893301372) },
      { UINT32_C(4155934817), UINT32_C(1884230802), UINT32_C( 250122415), UINT32_C(4035905903) },
      { UINT16_C(40628), UINT16_C(58251), UINT16_C(43533), UINT16_C(63360) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint32x4_t a = simde_vld1q_u32(test_vec[i].a);
    simde_uint32x4_t b = simde_vld1q_u32(test_vec[i].b);
    simde_uint16x4_t r = simde_vsubhn_u32(a, b);

    simde_test_arm_neon_assert_equal_u16x4(r, simde_vld1_u16(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint32x4_t a = simde_test_arm_neon_random_u32x4();
    simde_uint32x4_t b = simde_test_arm_neon_random_u32x4();
    simde_uint16x4_t r = simde_vsubhn_u32(a, b);

    simde_test_arm_neon_write_u32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u16x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vsubhn_u64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint64_t a[2];
    uint64_t b[2];
    uint32_t r[2];
  } test_vec[] = {
    { { UINT64_C( 6993071514011040637), UINT64_C( 8367170315894784698) },
      { UINT64_C(11003344925129168049), UINT64_C( 2497867929247718475) },
      { UINT32_C(3361252756), UINT32_C(1366553452) } },
    { { UINT64_C( 5552911487050920240), UINT64_C(  319932955634117098) },
      { UINT64_C(16354817199376489590), UINT64_C(  242990773675269527) },
      { UINT32_C(1779952636), UINT32_C(  17914497) } },
    { { UINT64_C(  889672178863258232), UINT64_C(17456367205171649514) },
      { UINT64_C( 2075676218296994133), UINT64_C( 2935142651308632805) },
      { UINT32_C(4018829212), UINT32_C(3380986059) } },
    { { UINT64_C( 1594427289522892018), UINT64_C(17858344424238688614) },
      { UINT64_C( 6179133781801379614), UINT64_C(14120131535093700891) },
      { UINT32_C(3227507132), UINT32_C( 870370513) } },
    { { UINT64_C( 1835208822484379444), UINT64_C( 9131842503198951969) },
      { UINT64_C( 7619493871451479545), UINT64_C(14307700251630619386) },
      { UINT32_C(2948208484), UINT32_C(3089869004) } },
    { { UINT64_C( 9303766536129308496), UINT64_C(16449116077159618920) },
      { UINT64_C( 4851514011181475740), UINT64_C(  229295120112912853) },
      { UINT32_C(1036620821), UINT32_C(3776471353) } },
    { { UINT64_C( 6621738355380344069), UINT64_C(14199120825657010749) },
      { UINT64_C( 4133465960498617041), UINT64_C( 1100231851942964366) },
      { UINT32_C( 579346063), UINT32_C(3049822750) } },
    { { UINT64_C(12354035057205463588), UINT64_C(15020315095954855555) },
      { UINT64_C(13175360044896231994), UINT64_C( 7840269184942963124) },
      { UINT32_C(4103737670), UINT32_C(1671734710) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint64x2_t a = simde_vld1q_u64(test_vec[i].a);
    simde_uint64x2_t b = simde_vld1q_u64(test_vec[i].b);
    simde_uint32x2_t r = simde_vsubhn_u64(a, b);

    simde_test_arm_neon_assert_equal_u32x2(r, simde_vld1_u32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint64x2_t a = simde_test_arm_neon_random_u64x2();
    simde_uint64x2_t b = simde_test_arm_neon_random_u64x2();
    simde_uint32x2_t r = simde_vsubhn_u64(a, b);

    simde_test_arm_neon_write_u64x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u64x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(vsubhn_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vsubhn_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vsubhn_s64)

SIMDE_TEST_FUNC_LIST_ENTRY(vsubhn_u16)
SIMDE_TEST_FUNC_LIST_ENTRY(vsubhn_u32)
SIMDE_TEST_FUNC_LIST_ENTRY(vsubhn_u64)
SIMDE_TEST_FUNC_LIST_END

#include "test-neon-footer.h"
