#define SIMDE_TEST_ARM_NEON_INSN subw_high

#include "test-neon.h"
#include "../../../simde/arm/neon/subw_high.h"

static int
test_simde_vsubw_high_s8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int16_t a[8];
    int8_t b[16];
    int16_t r[8];
  } test_vec[] = {
    { { -INT16_C(  8634),  INT16_C(  8369),  INT16_C( 24454), -INT16_C( 16207), -INT16_C( 12454), -INT16_C( 19437),  INT16_C( 30243), -INT16_C(  2979) },
      {  INT8_C(  49),  INT8_C(  50),  INT8_C(  31), -INT8_C( 122),  INT8_C(  92), -INT8_C(  76), -INT8_C(  99), -INT8_C(  69),
         INT8_C( 107), -INT8_C(  98), -INT8_C(  15),  INT8_C(  98),  INT8_C(  45),  INT8_C( 125),  INT8_C( 117),  INT8_C( 115) },
      { -INT16_C(  8741),  INT16_C(  8467),  INT16_C( 24469), -INT16_C( 16305), -INT16_C( 12499), -INT16_C( 19562),  INT16_C( 30126), -INT16_C(  3094) } },
    { {  INT16_C(  9820), -INT16_C(  7532),  INT16_C( 17798), -INT16_C(  8029), -INT16_C( 18924),  INT16_C( 14484), -INT16_C(  3796),  INT16_C( 23852) },
      {  INT8_C(  36),  INT8_C(  75), -INT8_C(  29),      INT8_MIN, -INT8_C(   1), -INT8_C( 127),  INT8_C(  59),  INT8_C( 106),
         INT8_C(  31),  INT8_C(  44), -INT8_C(  52),  INT8_C(  77), -INT8_C(  86),  INT8_C(  66), -INT8_C(  64),  INT8_C(   6) },
      {  INT16_C(  9789), -INT16_C(  7576),  INT16_C( 17850), -INT16_C(  8106), -INT16_C( 18838),  INT16_C( 14418), -INT16_C(  3732),  INT16_C( 23846) } },
    { {  INT16_C( 21608), -INT16_C(  4376), -INT16_C( 29799), -INT16_C( 20785),  INT16_C( 25410),  INT16_C( 28390),  INT16_C(  4693),  INT16_C( 31180) },
      {  INT8_C(  93), -INT8_C(  81), -INT8_C(   7),  INT8_C(  92),  INT8_C(  48),  INT8_C(  52), -INT8_C(  57),  INT8_C(  80),
         INT8_C(  97), -INT8_C( 109), -INT8_C(  99),  INT8_C(  11), -INT8_C(  43),  INT8_C(  93),  INT8_C(  17),  INT8_C(  62) },
      {  INT16_C( 21511), -INT16_C(  4267), -INT16_C( 29700), -INT16_C( 20796),  INT16_C( 25453),  INT16_C( 28297),  INT16_C(  4676),  INT16_C( 31118) } },
    { { -INT16_C(  1614),  INT16_C( 19244), -INT16_C(  1147), -INT16_C( 14343), -INT16_C(  8353), -INT16_C( 19403),  INT16_C(   497),  INT16_C( 20013) },
      { -INT8_C(  79),  INT8_C(  38), -INT8_C(  85), -INT8_C(  31),  INT8_C(  90),  INT8_C( 114),  INT8_C(  49), -INT8_C(  69),
         INT8_C(   5), -INT8_C(  50), -INT8_C(  58), -INT8_C(  37),  INT8_C(  44), -INT8_C(  41),  INT8_C(  25), -INT8_C(  34) },
      { -INT16_C(  1619),  INT16_C( 19294), -INT16_C(  1089), -INT16_C( 14306), -INT16_C(  8397), -INT16_C( 19362),  INT16_C(   472),  INT16_C( 20047) } },
    { {  INT16_C( 17873),  INT16_C( 22057),  INT16_C(  9025), -INT16_C( 24547),  INT16_C( 20994), -INT16_C(  2988), -INT16_C( 32428),  INT16_C(  1346) },
      { -INT8_C(  89), -INT8_C(  19), -INT8_C(  26),  INT8_C(   1),  INT8_C(  95),  INT8_C(  24), -INT8_C(  67),  INT8_C( 101),
        -INT8_C(  26), -INT8_C( 125),  INT8_C(  64),  INT8_C(  18),  INT8_C(  91),  INT8_C(  89), -INT8_C(  16),  INT8_C(  44) },
      {  INT16_C( 17899),  INT16_C( 22182),  INT16_C(  8961), -INT16_C( 24565),  INT16_C( 20903), -INT16_C(  3077), -INT16_C( 32412),  INT16_C(  1302) } },
    { {  INT16_C(  6814), -INT16_C(  8318), -INT16_C( 24771),  INT16_C( 16255), -INT16_C( 11279),  INT16_C( 17715),  INT16_C( 30292), -INT16_C(  1206) },
      {  INT8_C(  99),  INT8_C(  49), -INT8_C(   3), -INT8_C(  61),  INT8_C(  73), -INT8_C(  70),  INT8_C(  40),  INT8_C(  47),
         INT8_C(  61),  INT8_C( 104),  INT8_C(  66), -INT8_C( 104), -INT8_C(  63),  INT8_C(  50), -INT8_C(  60),  INT8_C(  95) },
      {  INT16_C(  6753), -INT16_C(  8422), -INT16_C( 24837),  INT16_C( 16359), -INT16_C( 11216),  INT16_C( 17665),  INT16_C( 30352), -INT16_C(  1301) } },
    { {  INT16_C( 17996), -INT16_C( 30401), -INT16_C( 16667), -INT16_C( 10295), -INT16_C(   878), -INT16_C(  6628),  INT16_C( 26482), -INT16_C( 10526) },
      { -INT8_C( 104), -INT8_C(  33), -INT8_C( 103), -INT8_C(  31), -INT8_C( 103), -INT8_C(  63),  INT8_C(  16), -INT8_C(  42),
         INT8_C(  41),  INT8_C(  82),  INT8_C( 111), -INT8_C(  22), -INT8_C( 123),  INT8_C(  51),  INT8_C(  73), -INT8_C(  47) },
      {  INT16_C( 17955), -INT16_C( 30483), -INT16_C( 16778), -INT16_C( 10273), -INT16_C(   755), -INT16_C(  6679),  INT16_C( 26409), -INT16_C( 10479) } },
    { { -INT16_C( 30598),  INT16_C( 24411),  INT16_C(  9287), -INT16_C(  9930),  INT16_C( 21280), -INT16_C( 27713), -INT16_C( 24134),  INT16_C( 21097) },
      {      INT8_MIN,  INT8_C(   2),  INT8_C(  51),  INT8_C(  25), -INT8_C(  61),  INT8_C(  67), -INT8_C(  16), -INT8_C(  20),
        -INT8_C( 106),  INT8_C(  95), -INT8_C(  42),  INT8_C(  27), -INT8_C( 110),  INT8_C(  31), -INT8_C(  20),  INT8_C(  12) },
      { -INT16_C( 30492),  INT16_C( 24316),  INT16_C(  9329), -INT16_C(  9957),  INT16_C( 21390), -INT16_C( 27744), -INT16_C( 24114),  INT16_C( 21085) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x8_t a = simde_vld1q_s16(test_vec[i].a);
    simde_int8x16_t b = simde_vld1q_s8(test_vec[i].b);
    simde_int16x8_t r = simde_vsubw_high_s8(a, b);

    simde_test_arm_neon_assert_equal_i16x8(r, simde_vld1q_s16(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int16x8_t a = simde_test_arm_neon_random_i16x8();
    simde_int8x16_t b = simde_test_arm_neon_random_i8x16();
    simde_int16x8_t r = simde_vsubw_high_s8(a, b);

    simde_test_arm_neon_write_i16x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i8x16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i16x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vsubw_high_s16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int32_t a[4];
    int16_t b[8];
    int32_t r[4];
  } test_vec[] = {
    { { -INT32_C(   278116440), -INT32_C(  1933008277), -INT32_C(  1356888075), -INT32_C(  1459517399) },
      {  INT16_C( 13450),  INT16_C( 19907), -INT16_C( 19592),  INT16_C(  3641),  INT16_C(  3858), -INT16_C( 23511),  INT16_C(  5422), -INT16_C( 10575) },
      { -INT32_C(   278120298), -INT32_C(  1932984766), -INT32_C(  1356893497), -INT32_C(  1459506824) } },
    { { -INT32_C(   926605987), -INT32_C(  1252749889),  INT32_C(  1046770453), -INT32_C(  2048432389) },
      { -INT16_C( 21862),  INT16_C(  4818),  INT16_C(  2909),  INT16_C( 28448),  INT16_C( 18714),  INT16_C( 18708), -INT16_C( 15009), -INT16_C( 17377) },
      { -INT32_C(   926624701), -INT32_C(  1252768597),  INT32_C(  1046785462), -INT32_C(  2048415012) } },
    { { -INT32_C(  1585125918), -INT32_C(  2024351374),  INT32_C(  1220918092), -INT32_C(  1144148703) },
      { -INT16_C( 24489), -INT16_C( 18994), -INT16_C(  4437), -INT16_C( 14812),  INT16_C( 14392), -INT16_C( 26865),  INT16_C( 12029), -INT16_C(  8365) },
      { -INT32_C(  1585140310), -INT32_C(  2024324509),  INT32_C(  1220906063), -INT32_C(  1144140338) } },
    { { -INT32_C(  2038311149), -INT32_C(    49424464), -INT32_C(  1287269486), -INT32_C(   680586624) },
      {  INT16_C( 15794),  INT16_C( 24204), -INT16_C( 20181),  INT16_C( 25380),  INT16_C( 13289), -INT16_C(  6150),  INT16_C( 19809),  INT16_C( 30150) },
      { -INT32_C(  2038324438), -INT32_C(    49418314), -INT32_C(  1287289295), -INT32_C(   680616774) } },
    { { -INT32_C(   704952539), -INT32_C(  1311635425),  INT32_C(  1533351899), -INT32_C(   600583126) },
      { -INT16_C( 16623),  INT16_C( 15418),  INT16_C( 24176),  INT16_C( 23200), -INT16_C( 25967), -INT16_C(  3263),  INT16_C(  2024),  INT16_C(  3432) },
      { -INT32_C(   704926572), -INT32_C(  1311632162),  INT32_C(  1533349875), -INT32_C(   600586558) } },
    { {  INT32_C(  1860330319),  INT32_C(  1193260395), -INT32_C(   157121332),  INT32_C(  1775490392) },
      {  INT16_C(  3477),  INT16_C(  1446),  INT16_C( 18028), -INT16_C(   673), -INT16_C( 24352), -INT16_C( 14096),  INT16_C( 22696), -INT16_C(  2091) },
      {  INT32_C(  1860354671),  INT32_C(  1193274491), -INT32_C(   157144028),  INT32_C(  1775492483) } },
    { {  INT32_C(   660977851),  INT32_C(   963544173),  INT32_C(  1630539785),  INT32_C(  2076902374) },
      {  INT16_C( 28944),  INT16_C( 31872), -INT16_C(  8009), -INT16_C( 26758),  INT16_C( 27264),  INT16_C( 10336),  INT16_C( 13763),  INT16_C( 32287) },
      {  INT32_C(   660950587),  INT32_C(   963533837),  INT32_C(  1630526022),  INT32_C(  2076870087) } },
    { {  INT32_C(  1520796909),  INT32_C(   311694089),  INT32_C(   175359012), -INT32_C(   679133497) },
      {  INT16_C(  1455),  INT16_C( 26196), -INT16_C( 12571),  INT16_C( 26366),  INT16_C( 24120), -INT16_C(  1138), -INT16_C( 20845), -INT16_C( 32390) },
      {  INT32_C(  1520772789),  INT32_C(   311695227),  INT32_C(   175379857), -INT32_C(   679101107) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x4_t a = simde_vld1q_s32(test_vec[i].a);
    simde_int16x8_t b = simde_vld1q_s16(test_vec[i].b);
    simde_int32x4_t r = simde_vsubw_high_s16(a, b);

    simde_test_arm_neon_assert_equal_i32x4(r, simde_vld1q_s32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int32x4_t a = simde_test_arm_neon_random_i32x4();
    simde_int16x8_t b = simde_test_arm_neon_random_i16x8();
    simde_int32x4_t r = simde_vsubw_high_s16(a, b);

    simde_test_arm_neon_write_i32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i16x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vsubw_high_s32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int64_t a[2];
    int32_t b[4];
    int64_t r[2];
  } test_vec[] = {
    { {  INT64_C( 6290806520344682290), -INT64_C( 5777301384871165645) },
      { -INT32_C(   787142933),  INT32_C(   741807092),  INT32_C(    86558065), -INT32_C(  1501126029) },
      {  INT64_C( 6290806520258124225), -INT64_C( 5777301383370039616) } },
    { {  INT64_C(  309393578208092609),  INT64_C( 9123960324121144560) },
      { -INT32_C(   347097865),  INT32_C(   957843143), -INT32_C(  1086439605), -INT32_C(  1553611551) },
      {  INT64_C(  309393579294532214),  INT64_C( 9123960325674756111) } },
    { {  INT64_C( 7348717312772884005), -INT64_C( 4422266780297856369) },
      {  INT32_C(  1873670055), -INT32_C(  1062681483), -INT32_C(   444602876), -INT32_C(   813112150) },
      {  INT64_C( 7348717313217486881), -INT64_C( 4422266779484744219) } },
    { { -INT64_C( 7924434272985407445), -INT64_C(  700217045811962949) },
      { -INT32_C(  1201277629), -INT32_C(  1116140103), -INT32_C(  1650198285),  INT32_C(   141306845) },
      { -INT64_C( 7924434271335209160), -INT64_C(  700217045953269794) } },
    { { -INT64_C( 5845198481330261429),  INT64_C( 3264684125834220809) },
      {  INT32_C(   736539505), -INT32_C(  1276616768),  INT32_C(   877693783),  INT32_C(    37534903) },
      { -INT64_C( 5845198482207955212),  INT64_C( 3264684125796685906) } },
    { { -INT64_C( 7092832327393221137), -INT64_C( 5485591867381398073) },
      { -INT32_C(  1226914314),  INT32_C(  2070529828),  INT32_C(   162576722),  INT32_C(  1678568565) },
      { -INT64_C( 7092832327555797859), -INT64_C( 5485591869059966638) } },
    { {  INT64_C( 6197754147606322641),  INT64_C( 3500395575433033629) },
      { -INT32_C(   790203988), -INT32_C(  1957998792),  INT32_C(  2106915592), -INT32_C(  1176330008) },
      {  INT64_C( 6197754145499407049),  INT64_C( 3500395576609363637) } },
    { { -INT64_C( 6997714204985775619),  INT64_C( 9115586715782671127) },
      { -INT32_C(  1152489598), -INT32_C(  1102669386),  INT32_C(  2101140117),  INT32_C(  2016812667) },
      { -INT64_C( 6997714207086915736),  INT64_C( 9115586713765858460) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int64x2_t a = simde_vld1q_s64(test_vec[i].a);
    simde_int32x4_t b = simde_vld1q_s32(test_vec[i].b);
    simde_int64x2_t r = simde_vsubw_high_s32(a, b);

    simde_test_arm_neon_assert_equal_i64x2(r, simde_vld1q_s64(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int64x2_t a = simde_test_arm_neon_random_i64x2();
    simde_int32x4_t b = simde_test_arm_neon_random_i32x4();
    simde_int64x2_t r = simde_vsubw_high_s32(a, b);

    simde_test_arm_neon_write_i64x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vsubw_high_u8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint16_t a[8];
    uint8_t b[16];
    uint16_t r[8];
  } test_vec[] = {
    { { UINT16_C(21831), UINT16_C(18437), UINT16_C(59509), UINT16_C(36326), UINT16_C(25811), UINT16_C(42462), UINT16_C(24693), UINT16_C(63523) },
      { UINT8_C(199), UINT8_C(113), UINT8_C(179), UINT8_C(126), UINT8_C( 10), UINT8_C(249), UINT8_C( 60), UINT8_C(159),
        UINT8_C(211), UINT8_C(120), UINT8_C( 28), UINT8_C( 78), UINT8_C(150), UINT8_C( 83), UINT8_C(199), UINT8_C(221) },
      { UINT16_C(21620), UINT16_C(18317), UINT16_C(59481), UINT16_C(36248), UINT16_C(25661), UINT16_C(42379), UINT16_C(24494), UINT16_C(63302) } },
    { { UINT16_C(52392), UINT16_C( 7461), UINT16_C( 3252), UINT16_C(34730), UINT16_C(35184), UINT16_C(58924), UINT16_C(20457), UINT16_C(45278) },
      { UINT8_C(192), UINT8_C(145), UINT8_C( 46), UINT8_C(202), UINT8_C(138), UINT8_C(107), UINT8_C(106), UINT8_C( 93),
        UINT8_C(227), UINT8_C(134), UINT8_C(172), UINT8_C(122), UINT8_C(217), UINT8_C(115), UINT8_C( 87), UINT8_C(129) },
      { UINT16_C(52165), UINT16_C( 7327), UINT16_C( 3080), UINT16_C(34608), UINT16_C(34967), UINT16_C(58809), UINT16_C(20370), UINT16_C(45149) } },
    { { UINT16_C(32063), UINT16_C(62367), UINT16_C(18825), UINT16_C(63866), UINT16_C(42706), UINT16_C(48095), UINT16_C(48629), UINT16_C(46444) },
      { UINT8_C( 78), UINT8_C(154), UINT8_C(127), UINT8_C(216), UINT8_C(  5), UINT8_C(233), UINT8_C( 54), UINT8_C(233),
        UINT8_C(112), UINT8_C(226), UINT8_C( 99), UINT8_C( 73), UINT8_C( 85), UINT8_C(186), UINT8_C(203), UINT8_C(148) },
      { UINT16_C(31951), UINT16_C(62141), UINT16_C(18726), UINT16_C(63793), UINT16_C(42621), UINT16_C(47909), UINT16_C(48426), UINT16_C(46296) } },
    { { UINT16_C(27191), UINT16_C(49287), UINT16_C(  435), UINT16_C(34490), UINT16_C(39335), UINT16_C(40001), UINT16_C(44375), UINT16_C(42321) },
      { UINT8_C( 72), UINT8_C(208), UINT8_C(126), UINT8_C( 77), UINT8_C(186), UINT8_C(180), UINT8_C( 54), UINT8_C( 42),
        UINT8_C(150), UINT8_C(153), UINT8_C(115), UINT8_C(235), UINT8_C( 84), UINT8_C( 62), UINT8_C(127), UINT8_C(139) },
      { UINT16_C(27041), UINT16_C(49134), UINT16_C(  320), UINT16_C(34255), UINT16_C(39251), UINT16_C(39939), UINT16_C(44248), UINT16_C(42182) } },
    { { UINT16_C( 1704), UINT16_C(23628), UINT16_C( 1543), UINT16_C(44770), UINT16_C( 9119), UINT16_C(63050), UINT16_C(39889), UINT16_C( 6556) },
      { UINT8_C(107), UINT8_C( 26), UINT8_C(102), UINT8_C( 37), UINT8_C(206), UINT8_C(157), UINT8_C( 79), UINT8_C(100),
        UINT8_C( 54), UINT8_C(195), UINT8_C( 79), UINT8_C(138), UINT8_C(  1), UINT8_C(206), UINT8_C( 22), UINT8_C(170) },
      { UINT16_C( 1650), UINT16_C(23433), UINT16_C( 1464), UINT16_C(44632), UINT16_C( 9118), UINT16_C(62844), UINT16_C(39867), UINT16_C( 6386) } },
    { { UINT16_C(25300), UINT16_C(56070), UINT16_C(59496), UINT16_C( 1929), UINT16_C(54027), UINT16_C(56574), UINT16_C(39534), UINT16_C(55797) },
      { UINT8_C(180), UINT8_C( 92),    UINT8_MAX, UINT8_C(130), UINT8_C(249), UINT8_C( 78), UINT8_C(230), UINT8_C( 47),
        UINT8_C( 17), UINT8_C( 53), UINT8_C(186), UINT8_C( 19), UINT8_C(  3), UINT8_C(208), UINT8_C(189), UINT8_C(215) },
      { UINT16_C(25283), UINT16_C(56017), UINT16_C(59310), UINT16_C( 1910), UINT16_C(54024), UINT16_C(56366), UINT16_C(39345), UINT16_C(55582) } },
    { { UINT16_C(49970), UINT16_C(39602), UINT16_C(15275), UINT16_C(46753), UINT16_C(40718), UINT16_C(31891), UINT16_C(34873), UINT16_C(60757) },
      { UINT8_C(228), UINT8_C( 84), UINT8_C(111), UINT8_C(221), UINT8_C(163), UINT8_C( 85), UINT8_C( 13), UINT8_C(180),
        UINT8_C(138), UINT8_C(199), UINT8_C(199), UINT8_C(141), UINT8_C(151), UINT8_C(132), UINT8_C(100), UINT8_C(201) },
      { UINT16_C(49832), UINT16_C(39403), UINT16_C(15076), UINT16_C(46612), UINT16_C(40567), UINT16_C(31759), UINT16_C(34773), UINT16_C(60556) } },
    { { UINT16_C( 5703), UINT16_C(62051), UINT16_C( 1105), UINT16_C(24489), UINT16_C(15524), UINT16_C(56795), UINT16_C(12740), UINT16_C(43467) },
      { UINT8_C(133), UINT8_C( 58), UINT8_C(134), UINT8_C( 40), UINT8_C(144), UINT8_C(147), UINT8_C(221), UINT8_C( 26),
        UINT8_C( 90), UINT8_C(164), UINT8_C(168), UINT8_C(241), UINT8_C( 41), UINT8_C( 12), UINT8_C(186), UINT8_C(112) },
      { UINT16_C( 5613), UINT16_C(61887), UINT16_C(  937), UINT16_C(24248), UINT16_C(15483), UINT16_C(56783), UINT16_C(12554), UINT16_C(43355) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint16x8_t a = simde_vld1q_u16(test_vec[i].a);
    simde_uint8x16_t b = simde_vld1q_u8(test_vec[i].b);
    simde_uint16x8_t r = simde_vsubw_high_u8(a, b);

    simde_test_arm_neon_assert_equal_u16x8(r, simde_vld1q_u16(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint16x8_t a = simde_test_arm_neon_random_u16x8();
    simde_uint8x16_t b = simde_test_arm_neon_random_u8x16();
    simde_uint16x8_t r = simde_vsubw_high_u8(a, b);

    simde_test_arm_neon_write_u16x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u8x16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u16x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vsubw_high_u16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint32_t a[4];
    uint16_t b[8];
    uint32_t r[4];
  } test_vec[] = {
    { { UINT32_C(1952652579), UINT32_C(3335785506), UINT32_C( 212053832), UINT32_C(1723166432) },
      { UINT16_C(15529), UINT16_C(14734), UINT16_C(27599), UINT16_C(10835), UINT16_C(64272), UINT16_C(14619), UINT16_C(54792), UINT16_C(11177) },
      { UINT32_C(1952588307), UINT32_C(3335770887), UINT32_C( 211999040), UINT32_C(1723155255) } },
    { { UINT32_C( 362745075), UINT32_C(1624994584), UINT32_C(  57507619), UINT32_C(2523472621) },
      { UINT16_C(63582), UINT16_C(11983), UINT16_C( 9059), UINT16_C(29528), UINT16_C(29470), UINT16_C( 9900), UINT16_C(22089), UINT16_C(15697) },
      { UINT32_C( 362715605), UINT32_C(1624984684), UINT32_C(  57485530), UINT32_C(2523456924) } },
    { { UINT32_C(2069033314), UINT32_C(2279288420), UINT32_C(2592819373), UINT32_C(3375494251) },
      { UINT16_C(  236), UINT16_C(20727), UINT16_C(20259), UINT16_C(17091), UINT16_C(28867), UINT16_C( 3176), UINT16_C(47814), UINT16_C(10313) },
      { UINT32_C(2069004447), UINT32_C(2279285244), UINT32_C(2592771559), UINT32_C(3375483938) } },
    { { UINT32_C( 262380715), UINT32_C(2006417354), UINT32_C( 839983815), UINT32_C(  66863638) },
      { UINT16_C(62275), UINT16_C(26195), UINT16_C( 5699), UINT16_C( 1704), UINT16_C( 4486), UINT16_C(19474), UINT16_C(23755), UINT16_C(30325) },
      { UINT32_C( 262376229), UINT32_C(2006397880), UINT32_C( 839960060), UINT32_C(  66833313) } },
    { { UINT32_C(3263502584), UINT32_C(1597578391), UINT32_C(1435585086), UINT32_C(3495464333) },
      { UINT16_C(43905), UINT16_C(50230), UINT16_C(57281), UINT16_C(18634), UINT16_C(56560), UINT16_C(48020), UINT16_C( 2360), UINT16_C(12337) },
      { UINT32_C(3263446024), UINT32_C(1597530371), UINT32_C(1435582726), UINT32_C(3495451996) } },
    { { UINT32_C(3119691298), UINT32_C( 286796755), UINT32_C(  57059958), UINT32_C(3100884535) },
      { UINT16_C( 2409), UINT16_C(11132), UINT16_C(18152), UINT16_C(55411), UINT16_C( 1827), UINT16_C(23443), UINT16_C(50193), UINT16_C(13196) },
      { UINT32_C(3119689471), UINT32_C( 286773312), UINT32_C(  57009765), UINT32_C(3100871339) } },
    { { UINT32_C(1324121723), UINT32_C( 543098282), UINT32_C(3861104303), UINT32_C(4003460740) },
      { UINT16_C( 7167), UINT16_C(59417), UINT16_C(35938), UINT16_C(34240), UINT16_C(21651), UINT16_C(42208), UINT16_C(27672), UINT16_C(37847) },
      { UINT32_C(1324100072), UINT32_C( 543056074), UINT32_C(3861076631), UINT32_C(4003422893) } },
    { { UINT32_C(2514601195), UINT32_C(2025144777), UINT32_C(2338248711), UINT32_C(3447324110) },
      { UINT16_C(37401), UINT16_C(31669), UINT16_C(30238), UINT16_C(45568), UINT16_C(57546), UINT16_C(57942), UINT16_C(11853), UINT16_C(14454) },
      { UINT32_C(2514543649), UINT32_C(2025086835), UINT32_C(2338236858), UINT32_C(3447309656) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint32x4_t a = simde_vld1q_u32(test_vec[i].a);
    simde_uint16x8_t b = simde_vld1q_u16(test_vec[i].b);
    simde_uint32x4_t r = simde_vsubw_high_u16(a, b);
    simde_test_arm_neon_assert_equal_u32x4(r, simde_vld1q_u32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint32x4_t a = simde_test_arm_neon_random_u32x4();
    simde_uint16x8_t b = simde_test_arm_neon_random_u16x8();
    simde_uint32x4_t r = simde_vsubw_high_u16(a, b);

    simde_test_arm_neon_write_u32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u16x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vsubw_high_u32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint64_t a[2];
    uint32_t b[4];
    uint64_t r[2];
  } test_vec[] = {
    { { UINT64_C(11471656268340221938), UINT64_C(12174818102427226458) },
      { UINT32_C(1428400951), UINT32_C(3943113505), UINT32_C(1355636227), UINT32_C(2122859404) },
      { UINT64_C(11471656266984585711), UINT64_C(12174818100304367054) } },
    { { UINT64_C( 3590332999477581211), UINT64_C(15651222164577320701) },
      { UINT32_C( 456087546), UINT32_C(2114336378), UINT32_C( 550425492), UINT32_C(2996721431) },
      { UINT64_C( 3590332998927155719), UINT64_C(15651222161580599270) } },
    { { UINT64_C( 4734893183381919660), UINT64_C( 6355144628429983670) },
      { UINT32_C(3564331353), UINT32_C( 743602584), UINT32_C(1665998924), UINT32_C( 605416311) },
      { UINT64_C( 4734893181715920736), UINT64_C( 6355144627824567359) } },
    { { UINT64_C( 7658192714859084739), UINT64_C( 8080290163990926700) },
      { UINT32_C(4014249303), UINT32_C(1528534542), UINT32_C( 784230583), UINT32_C( 391304276) },
      { UINT64_C( 7658192714074854156), UINT64_C( 8080290163599622424) } },
    { { UINT64_C(14189827956752120527), UINT64_C(18158990497204383610) },
      { UINT32_C(1441482311), UINT32_C(2477786844), UINT32_C(3284299631), UINT32_C( 316281923) },
      { UINT64_C(14189827953467820896), UINT64_C(18158990496888101687) } },
    { { UINT64_C(15432570781989926671), UINT64_C(12957253519079356976) },
      { UINT32_C(2332605615), UINT32_C( 840939971), UINT32_C(1811276072), UINT32_C(  75354101) },
      { UINT64_C(15432570780178650599), UINT64_C(12957253519004002875) } },
    { { UINT64_C(14121484760512139718), UINT64_C( 8750611494977691985) },
      { UINT32_C(3909384486), UINT32_C(1511727922), UINT32_C(4207218692), UINT32_C(2801681119) },
      { UINT64_C(14121484756304921026), UINT64_C( 8750611492176010866) } },
    { { UINT64_C( 5956505295596907091), UINT64_C(15160946671494381859) },
      { UINT32_C( 733703161), UINT32_C(2475022222), UINT32_C(3347925735), UINT32_C(3765275532) },
      { UINT64_C( 5956505292248981356), UINT64_C(15160946667729106327) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint64x2_t a = simde_vld1q_u64(test_vec[i].a);
    simde_uint32x4_t b = simde_vld1q_u32(test_vec[i].b);
    simde_uint64x2_t r = simde_vsubw_high_u32(a, b);
    simde_test_arm_neon_assert_equal_u64x2(r, simde_vld1q_u64(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint64x2_t a = simde_test_arm_neon_random_u64x2();
    simde_uint32x4_t b = simde_test_arm_neon_random_u32x4();
    simde_uint64x2_t r = simde_vsubw_high_u32(a, b);

    simde_test_arm_neon_write_u64x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(vsubw_high_s8)
SIMDE_TEST_FUNC_LIST_ENTRY(vsubw_high_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vsubw_high_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vsubw_high_u8)
SIMDE_TEST_FUNC_LIST_ENTRY(vsubw_high_u16)
SIMDE_TEST_FUNC_LIST_ENTRY(vsubw_high_u32)
SIMDE_TEST_FUNC_LIST_END

#include "test-neon-footer.h"
