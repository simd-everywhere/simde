#define SIMDE_TEST_ARM_NEON_INSN rsubhn_high

#include "test-neon.h"
#include "../../../simde/arm/neon/rsubhn_high.h"

static int
test_simde_vrsubhn_high_s16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int8_t r_[8];
    int16_t a[8];
    int16_t b[8];
    int8_t r[16];
  } test_vec[] = {
    { { -INT8_C(     57),  INT8_C(     26),  INT8_C(    118), -INT8_C(    106),  INT8_C(     22),  INT8_C(    120),  INT8_C(      9),  INT8_C(    108)  },
      {  INT16_C(  13311), -INT16_C(  31040), -INT16_C(  24932), -INT16_C(   4106),  INT16_C(   2488),  INT16_C(  18411), -INT16_C(   9260),  INT16_C(  15452)  },
      { -INT16_C(  30683), -INT16_C(  28493),  INT16_C(   4281), -INT16_C(  14327), -INT16_C(  13218), -INT16_C(   6794), -INT16_C(   3631), -INT16_C(  15368)  },
      { -INT8_C(     57),  INT8_C(     26),  INT8_C(    118), -INT8_C(    106),  INT8_C(     22),  INT8_C(    120),  INT8_C(      9),  INT8_C(    108), -INT8_C(     84), -INT8_C(     10), -INT8_C(    114),  INT8_C(     40),  INT8_C(     61),  INT8_C(     98), -INT8_C(     22),  INT8_C(    120)  } },
    { {  INT8_C(    124),  INT8_C(     84), -INT8_C(    124), -INT8_C(     66),  INT8_C(     49),  INT8_C(     64), -INT8_C(     55),  INT8_C(    120)  },
      { -INT16_C(  28562), -INT16_C(  19703), -INT16_C(   2719),  INT16_C(  16071), -INT16_C(  24879),  INT16_C(  26327),  INT16_C(  26938), -INT16_C(  13405)  },
      { -INT16_C(  19547),  INT16_C(  30137),  INT16_C(  27207),  INT16_C(  21507), -INT16_C(  31778), -INT16_C(  13807),  INT16_C(   4738), -INT16_C(  24177)  },
      {  INT8_C(    124),  INT8_C(     84), -INT8_C(    124), -INT8_C(     66),  INT8_C(     49),  INT8_C(     64), -INT8_C(     55),  INT8_C(    120), -INT8_C(     35),  INT8_C(     61), -INT8_C(    117), -INT8_C(     21),  INT8_C(     27), -INT8_C(     99),  INT8_C(     87),  INT8_C(     42)  } },
    { { -INT8_C(    109), -INT8_C(     29), -INT8_C(     17), -INT8_C(     36), -INT8_C(     56),  INT8_C(     90), -INT8_C(     19), -INT8_C(     55)  },
      {  INT16_C(    741),  INT16_C(    711), -INT16_C(   1724),  INT16_C(   7729),  INT16_C(   6281), -INT16_C(  13445),  INT16_C(  22116),  INT16_C(  26179)  },
      {  INT16_C(   6527),  INT16_C(  29841), -INT16_C(   5864),  INT16_C(  18441), -INT16_C(  24112), -INT16_C(  30497), -INT16_C(   6294),  INT16_C(   7786)  },
      { -INT8_C(    109), -INT8_C(     29), -INT8_C(     17), -INT8_C(     36), -INT8_C(     56),  INT8_C(     90), -INT8_C(     19), -INT8_C(     55), -INT8_C(     23), -INT8_C(    114),  INT8_C(     16), -INT8_C(     42),  INT8_C(    119),  INT8_C(     67),  INT8_C(    111),  INT8_C(     72)  } },
    { { -INT8_C(     16), -INT8_C(     42), -INT8_C(     32), -INT8_C(     55), -INT8_C(     66), -INT8_C(    104), -INT8_C(     62),  INT8_C(    124)  },
      {  INT16_C(  23253),  INT16_C(  16023), -INT16_C(   2725), -INT16_C(   2569), -INT16_C(  30790), -INT16_C(  17177), -INT16_C(  30309), -INT16_C(  17320)  },
      {  INT16_C(   7831),  INT16_C(  18555), -INT16_C(  29330),  INT16_C(  29911),  INT16_C(  13510),  INT16_C(   1110),  INT16_C(   2441), -INT16_C(   5602)  },
      { -INT8_C(     16), -INT8_C(     42), -INT8_C(     32), -INT8_C(     55), -INT8_C(     66), -INT8_C(    104), -INT8_C(     62),  INT8_C(    124),  INT8_C(     60), -INT8_C(     10),  INT8_C(    104), -INT8_C(    127),  INT8_C(     83), -INT8_C(     71),       INT8_MIN, -INT8_C(     46)  } },
    { { -INT8_C(     55), -INT8_C(     23),  INT8_C(     91),  INT8_C(     57),  INT8_C(     44),  INT8_C(      3),  INT8_C(     51),  INT8_C(    118)  },
      {  INT16_C(  17257),  INT16_C(  32178), -INT16_C(  24596),  INT16_C(  10324),  INT16_C(     87),  INT16_C(  27239), -INT16_C(  13293),  INT16_C(  15079)  },
      { -INT16_C(  25504), -INT16_C(  20474), -INT16_C(  30939),  INT16_C(  10568),  INT16_C(   5089), -INT16_C(  12537),  INT16_C(   7486), -INT16_C(  28349)  },
      { -INT8_C(     55), -INT8_C(     23),  INT8_C(     91),  INT8_C(     57),  INT8_C(     44),  INT8_C(      3),  INT8_C(     51),  INT8_C(    118), -INT8_C(     89), -INT8_C(     50),  INT8_C(     25), -INT8_C(      1), -INT8_C(     20), -INT8_C(    101), -INT8_C(     81), -INT8_C(     86)  } },
    { { -INT8_C(      5), -INT8_C(     77),  INT8_C(    112), -INT8_C(     74), -INT8_C(     14), -INT8_C(     82), -INT8_C(      2), -INT8_C(     87)  },
      { -INT16_C(  19745), -INT16_C(  16782), -INT16_C(    587), -INT16_C(  16737),  INT16_C(  30127),  INT16_C(  11759),  INT16_C(  19794),  INT16_C(  24265)  },
      {  INT16_C(  24307), -INT16_C(  30221), -INT16_C(  25200),  INT16_C(  17173), -INT16_C(  31429), -INT16_C(  11979),  INT16_C(  24480),  INT16_C(  22617)  },
      { -INT8_C(      5), -INT8_C(     77),  INT8_C(    112), -INT8_C(     74), -INT8_C(     14), -INT8_C(     82), -INT8_C(      2), -INT8_C(     87),  INT8_C(     84),  INT8_C(     52),  INT8_C(     96),  INT8_C(    124), -INT8_C(     16),  INT8_C(     93), -INT8_C(     18),  INT8_C(      6)  } },
    { { -INT8_C(    124), -INT8_C(     54),  INT8_C(     16), -INT8_C(     78), -INT8_C(    127), -INT8_C(      7),  INT8_C(     33), -INT8_C(     61)  },
      { -INT16_C(  30078),  INT16_C(   8645), -INT16_C(    573),  INT16_C(  13811), -INT16_C(   7119),  INT16_C(  14999),  INT16_C(  20134), -INT16_C(  20511)  },
      {  INT16_C(  32370), -INT16_C(  26330), -INT16_C(  16041),  INT16_C(   7697),  INT16_C(  28606),  INT16_C(  30738),  INT16_C(  30774),  INT16_C(   3914)  },
      { -INT8_C(    124), -INT8_C(     54),  INT8_C(     16), -INT8_C(     78), -INT8_C(    127), -INT8_C(      7),  INT8_C(     33), -INT8_C(     61),  INT8_C(     12), -INT8_C(    119),  INT8_C(     60),  INT8_C(     24),  INT8_C(    116), -INT8_C(     61), -INT8_C(     42), -INT8_C(     95)  } },
    { {  INT8_C(     80),  INT8_C(     56),  INT8_C(    100), -INT8_C(     66), -INT8_C(     31),  INT8_C(     37), -INT8_C(     33),  INT8_C(     74)  },
      { -INT16_C(  14553),  INT16_C(   5150),  INT16_C(  28351), -INT16_C(    684),  INT16_C(  26568), -INT16_C(  31096),  INT16_C(   4472),  INT16_C(  13012)  },
      {  INT16_C(  32286), -INT16_C(  10540), -INT16_C(   5164),  INT16_C(   6273),  INT16_C(  22632),  INT16_C(  17748),  INT16_C(  18038), -INT16_C(  21733)  },
      {  INT8_C(     80),  INT8_C(     56),  INT8_C(    100), -INT8_C(     66), -INT8_C(     31),  INT8_C(     37), -INT8_C(     33),  INT8_C(     74),  INT8_C(     73),  INT8_C(     61), -INT8_C(    125), -INT8_C(     27),  INT8_C(     15),  INT8_C(     65), -INT8_C(     53), -INT8_C(    120)  } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int8x8_t r_ = simde_vld1_s8(test_vec[i].r_);
    simde_int16x8_t a = simde_vld1q_s16(test_vec[i].a);
    simde_int16x8_t b = simde_vld1q_s16(test_vec[i].b);
    simde_int8x16_t r = simde_vrsubhn_high_s16(r_, a, b);

    simde_test_arm_neon_assert_equal_i8x16(r, simde_vld1q_s8(test_vec[i].r));
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int8x8_t r_ = simde_test_arm_neon_random_i8x8();
    simde_int16x8_t a = simde_test_arm_neon_random_i16x8();
    simde_int16x8_t b = simde_test_arm_neon_random_i16x8();
    simde_int8x16_t r = simde_vrsubhn_high_s16(r_, a, b);

    simde_test_arm_neon_write_i8x8(2, r_, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i16x8(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i16x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i8x16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vrsubhn_high_s32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int16_t r_[4];
    int32_t a[4];
    int32_t b[4];
    int16_t r[8];
  } test_vec[] = {
    { { -INT16_C(     12977), -INT16_C(      2227), -INT16_C(     27768),  INT16_C(     17924)  },
      { -INT32_C(1395181711), -INT32_C(1240879307), -INT32_C( 637043430), -INT32_C( 687732233)  },
      { -INT32_C( 514460743), -INT32_C( 645485430), -INT32_C( 941798700),  INT32_C(1426294115)  },
      { -INT16_C(     12977), -INT16_C(      2227), -INT16_C(     27768),  INT16_C(     17924), -INT16_C(     13439), -INT16_C(      9085),  INT16_C(      4650), -INT16_C(     32257)  } },
    { { -INT16_C(     30965), -INT16_C(     14140), -INT16_C(      1197),  INT16_C(     25568)  },
      { -INT32_C( 475098007),  INT32_C(1756822291), -INT32_C(1668735740),  INT32_C(1597884770)  },
      { -INT32_C(1092539856), -INT32_C(1644754626), -INT32_C( 452915460), -INT32_C( 267100233)  },
      { -INT16_C(     30965), -INT16_C(     14140), -INT16_C(      1197),  INT16_C(     25568),  INT16_C(      9421), -INT16_C(     13632), -INT16_C(     18552),  INT16_C(     28457)  } },
    { { -INT16_C(      3586), -INT16_C(     25062),  INT16_C(      2878), -INT16_C(     22179)  },
      { -INT32_C(1144008554), -INT32_C( 383576581),  INT32_C(2119783921),  INT32_C(1440612031)  },
      {  INT32_C(1818261921),  INT32_C( 254868399),  INT32_C(2027737229),  INT32_C( 557924416)  },
      { -INT16_C(      3586), -INT16_C(     25062),  INT16_C(      2878), -INT16_C(     22179),  INT16_C(     20335), -INT16_C(      9742),  INT16_C(      1405),  INT16_C(     13469)  } },
    { {  INT16_C(      2568),  INT16_C(     19580),  INT16_C(      7584),  INT16_C(     15845)  },
      { -INT32_C(2058569671), -INT32_C(1945659170), -INT32_C(1893664429), -INT32_C( 686544847)  },
      {  INT32_C(1348487948), -INT32_C(1225141222),  INT32_C( 722877109),  INT32_C( 940184532)  },
      {  INT16_C(      2568),  INT16_C(     19580),  INT16_C(      7584),  INT16_C(     15845),  INT16_C(     13548), -INT16_C(     10994),  INT16_C(     25611), -INT16_C(     24822)  } },
    { {  INT16_C(     30154), -INT16_C(     31961), -INT16_C(      2317), -INT16_C(     15814)  },
      {  INT32_C( 661319774), -INT32_C(1184345804),  INT32_C( 907491779), -INT32_C(1143902803)  },
      {  INT32_C( 546102851),  INT32_C(1867663720),  INT32_C(1122486484),  INT32_C( 279341413)  },
      {  INT16_C(     30154), -INT16_C(     31961), -INT16_C(      2317), -INT16_C(     15814),  INT16_C(      1758),  INT16_C(     18966), -INT16_C(      3281), -INT16_C(     21717)  } },
    { {  INT16_C(     13545),  INT16_C(     25683), -INT16_C(     22237), -INT16_C(      1651)  },
      {  INT32_C(1179105308),  INT32_C(1257466709),  INT32_C(1971469630),  INT32_C( 965297803)  },
      { -INT32_C( 922124931), -INT32_C(1349774106), -INT32_C(1713687644),  INT32_C(1629767843)  },
      {  INT16_C(     13545),  INT16_C(     25683), -INT16_C(     22237), -INT16_C(      1651),  INT16_C(     32062), -INT16_C(     25753), -INT16_C(      9305), -INT16_C(     10139)  } },
    { {  INT16_C(     16119), -INT16_C(      7381),  INT16_C(     32043), -INT16_C(     21273)  },
      {  INT32_C(1112362391), -INT32_C( 222232724),  INT32_C(1047777903), -INT32_C( 913499513)  },
      {  INT32_C(1767981731), -INT32_C(1115257806),  INT32_C( 915094923), -INT32_C(2015328243)  },
      {  INT16_C(     16119), -INT16_C(      7381),  INT16_C(     32043), -INT16_C(     21273), -INT16_C(     10004),  INT16_C(     13626),  INT16_C(      2025),  INT16_C(     16813)  } },
    { { -INT16_C(     32566),  INT16_C(      5160),  INT16_C(     17899), -INT16_C(     15831)  },
      { -INT32_C(1954975313), -INT32_C(1920435371),  INT32_C(1003706891),  INT32_C( 541402975)  },
      {  INT32_C(1674438238), -INT32_C(1098473480), -INT32_C( 634716656), -INT32_C( 851524412)  },
      { -INT16_C(     32566),  INT16_C(      5160),  INT16_C(     17899), -INT16_C(     15831),  INT16_C(     10156), -INT16_C(     12542),  INT16_C(     25000),  INT16_C(     21254)  } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x4_t r_ = simde_vld1_s16(test_vec[i].r_);
    simde_int32x4_t a = simde_vld1q_s32(test_vec[i].a);
    simde_int32x4_t b = simde_vld1q_s32(test_vec[i].b);
    simde_int16x8_t r = simde_vrsubhn_high_s32(r_, a, b);

    simde_test_arm_neon_assert_equal_i16x8(r, simde_vld1q_s16(test_vec[i].r));
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int16x4_t r_ = simde_test_arm_neon_random_i16x4();
    simde_int32x4_t a = simde_test_arm_neon_random_i32x4();
    simde_int32x4_t b = simde_test_arm_neon_random_i32x4();
    simde_int16x8_t r = simde_vrsubhn_high_s32(r_, a, b);

    simde_test_arm_neon_write_i16x4(2, r_, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i32x4(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i16x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vrsubhn_high_s64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int32_t r_[2];
    int64_t a[2];
    int64_t b[2];
    int32_t r[4];
  } test_vec[] = {
    { { -INT32_C(           634794411),  INT32_C(          1900921601)  },
      { -INT64_C( 4981114222538011063),  INT64_C( 6718889980534685553)  },
      { -INT64_C( 9134035082168866882), -INT64_C( 8643474357928897387)  },
      { -INT32_C(           634794411),  INT32_C(          1900921601),  INT32_C(           966927237), -INT32_C(           718138119)  } },
    { { -INT32_C(          1252566501),  INT32_C(           408004355)  },
      {  INT64_C( 1961598702296295413),  INT64_C( 1789265077301493858)  },
      { -INT64_C( 1992937627710137491), -INT64_C( 6606323933163750076)  },
      { -INT32_C(          1252566501),  INT32_C(           408004355),  INT32_C(           920737239),  INT32_C(          1954750393)  } },
    { { -INT32_C(          1461648077), -INT32_C(           456589213)  },
      { -INT64_C( 3805107682072796996), -INT64_C( 3551263502935852693)  },
      {  INT64_C( 2017632390811172449), -INT64_C(  811730804735164581)  },
      { -INT32_C(          1461648077), -INT32_C(           456589213), -INT32_C(          1355712319), -INT32_C(           637847161)  } },
    { {  INT32_C(          1747874793),  INT32_C(          2140696208)  },
      {  INT64_C(  937152159973332462), -INT64_C( 7415891501218868528)  },
      { -INT64_C( 6013839813684367117), -INT64_C( 5801899480449452360)  },
      {  INT32_C(          1747874793),  INT32_C(          2140696208),  INT32_C(          1618403935), -INT32_C(           375786801)  } },
    { { -INT32_C(          1743771151),  INT32_C(          2117269274)  },
      {  INT64_C(  565523750854915567),  INT64_C( 6277698001984965823)  },
      { -INT64_C( 7182780127885909828),  INT64_C( 1628218994207521522)  },
      { -INT32_C(          1743771151),  INT32_C(          2117269274),  INT32_C(          1804042579),  INT32_C(          1082541190)  } },
    { {  INT32_C(           769461152), -INT32_C(          1065585759)  },
      { -INT64_C( 8263077630275804176),  INT64_C( 8146965252929535167)  },
      {  INT64_C( 6693203158242440733), -INT64_C( 5722247609551143928)  },
      {  INT32_C(           769461152), -INT32_C(          1065585759),  INT32_C(           812686813), -INT32_C(          1065789538)  } },
    { { -INT32_C(           779973276), -INT32_C(            89996234)  },
      {  INT64_C( 4328069067460272340),  INT64_C( 8960946558766265296)  },
      { -INT64_C( 5126182062046763683), -INT64_C( 6499324058686156033)  },
      { -INT32_C(           779973276), -INT32_C(            89996234), -INT32_C(          2093727920), -INT32_C(           695342537)  } },
    { {  INT32_C(          1374451854),  INT32_C(          1634665168)  },
      {  INT64_C(  933833112004457496),  INT64_C( 3781945808152128338)  },
      {  INT64_C( 3556891504846685220),  INT64_C( 7834410733044719669)  },
      {  INT32_C(          1374451854),  INT32_C(          1634665168), -INT32_C(           610728374), -INT32_C(           943538017)  } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x2_t r_ = simde_vld1_s32(test_vec[i].r_);
    simde_int64x2_t a = simde_vld1q_s64(test_vec[i].a);
    simde_int64x2_t b = simde_vld1q_s64(test_vec[i].b);
    simde_int32x4_t r = simde_vrsubhn_high_s64(r_, a, b);

    simde_test_arm_neon_assert_equal_i32x4(r, simde_vld1q_s32(test_vec[i].r));
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int32x2_t r_ = simde_test_arm_neon_random_i32x2();
    simde_int64x2_t a = simde_test_arm_neon_random_i64x2();
    simde_int64x2_t b = simde_test_arm_neon_random_i64x2();
    simde_int32x4_t r = simde_vrsubhn_high_s64(r_, a, b);

    simde_test_arm_neon_write_i32x2(2, r_, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i64x2(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i64x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vrsubhn_high_u16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint8_t r_[8];
    uint16_t a[8];
    uint16_t b[8];
    uint8_t r[16];
  } test_vec[] = {
    { {  UINT8_C(  199),  UINT8_C(  208),  UINT8_C(  108),  UINT8_C(   25),  UINT8_C(   23),  UINT8_C(  206),  UINT8_C(  220),  UINT8_C(  146)  },
      {  UINT16_C(20331),  UINT16_C(63359),  UINT16_C(61138),  UINT16_C(22627),  UINT16_C(27341),  UINT16_C(46940),  UINT16_C(59425),  UINT16_C(62036)  },
      {  UINT16_C(23567),  UINT16_C(23177),  UINT16_C(44534),  UINT16_C(26849),  UINT16_C(19009),  UINT16_C(31005),  UINT16_C(31592),  UINT16_C(62268)  },
      {  UINT8_C(  199),  UINT8_C(  208),  UINT8_C(  108),  UINT8_C(   25),  UINT8_C(   23),  UINT8_C(  206),  UINT8_C(  220),  UINT8_C(  146),  UINT8_C(  243),  UINT8_C(  157),  UINT8_C(   65),  UINT8_C(  240),  UINT8_C(   33),  UINT8_C(   62),  UINT8_C(  109),    UINT8_MAX  } },
    { {  UINT8_C(  124),  UINT8_C(  248),  UINT8_C(  130),  UINT8_C(  219),  UINT8_C(  227),  UINT8_C(   29),  UINT8_C(  126),  UINT8_C(  216)  },
      {  UINT16_C( 3413),  UINT16_C(58604),  UINT16_C(30450),  UINT16_C(19146),  UINT16_C(17020),  UINT16_C(33098),  UINT16_C(35964),  UINT16_C(43515)  },
      {  UINT16_C(60215),  UINT16_C(10159),  UINT16_C(57097),  UINT16_C( 3673),  UINT16_C(11038),  UINT16_C(27128),  UINT16_C(41205),  UINT16_C( 1394)  },
      {  UINT8_C(  124),  UINT8_C(  248),  UINT8_C(  130),  UINT8_C(  219),  UINT8_C(  227),  UINT8_C(   29),  UINT8_C(  126),  UINT8_C(  216),  UINT8_C(   34),  UINT8_C(  189),  UINT8_C(  152),  UINT8_C(   60),  UINT8_C(   23),  UINT8_C(   23),  UINT8_C(  236),  UINT8_C(  165)  } },
    { {  UINT8_C(  203),  UINT8_C(  165),  UINT8_C(  122),  UINT8_C(  152),  UINT8_C(   11),  UINT8_C(  126),  UINT8_C(   17),  UINT8_C(  127)  },
      {  UINT16_C(25287),  UINT16_C(41941),  UINT16_C(65006),  UINT16_C(31570),  UINT16_C(13092),  UINT16_C(56629),  UINT16_C(38097),  UINT16_C(32785)  },
      {  UINT16_C(64937),  UINT16_C(60072),  UINT16_C(19706),  UINT16_C(51741),  UINT16_C(48358),  UINT16_C(32600),  UINT16_C(27603),  UINT16_C(11365)  },
      {  UINT8_C(  203),  UINT8_C(  165),  UINT8_C(  122),  UINT8_C(  152),  UINT8_C(   11),  UINT8_C(  126),  UINT8_C(   17),  UINT8_C(  127),  UINT8_C(  101),  UINT8_C(  185),  UINT8_C(  177),  UINT8_C(  177),  UINT8_C(  118),  UINT8_C(   94),  UINT8_C(   41),  UINT8_C(   84)  } },
    { {  UINT8_C(   18),  UINT8_C(  254),  UINT8_C(  215),  UINT8_C(   80),  UINT8_C(  143),  UINT8_C(  172),  UINT8_C(   69),  UINT8_C(   82)  },
      {  UINT16_C(10014),  UINT16_C(42189),  UINT16_C(29852),  UINT16_C( 9439),  UINT16_C(39633),  UINT16_C(55336),  UINT16_C(44596),  UINT16_C(37844)  },
      {  UINT16_C(61820),  UINT16_C(52531),  UINT16_C(15789),  UINT16_C(65214),  UINT16_C(47820),  UINT16_C(60501),  UINT16_C(63187),  UINT16_C(26072)  },
      {  UINT8_C(   18),  UINT8_C(  254),  UINT8_C(  215),  UINT8_C(   80),  UINT8_C(  143),  UINT8_C(  172),  UINT8_C(   69),  UINT8_C(   82),  UINT8_C(   54),  UINT8_C(  216),  UINT8_C(   55),  UINT8_C(   38),  UINT8_C(  224),  UINT8_C(  236),  UINT8_C(  183),  UINT8_C(   46)  } },
    { {  UINT8_C(   68),  UINT8_C(   57),  UINT8_C(  239),  UINT8_C(  197),  UINT8_C(  110),  UINT8_C(  115),  UINT8_C(  180),  UINT8_C(  123)  },
      {  UINT16_C(46221),  UINT16_C( 6188),  UINT16_C(62049),  UINT16_C(56738),  UINT16_C(42307),  UINT16_C(60741),  UINT16_C(14810),  UINT16_C( 2302)  },
      {  UINT16_C(24062),  UINT16_C(63486),  UINT16_C(19483),  UINT16_C(35985),  UINT16_C(61603),  UINT16_C(28995),  UINT16_C(38454),  UINT16_C(46727)  },
      {  UINT8_C(   68),  UINT8_C(   57),  UINT8_C(  239),  UINT8_C(  197),  UINT8_C(  110),  UINT8_C(  115),  UINT8_C(  180),  UINT8_C(  123),  UINT8_C(   87),  UINT8_C(   32),  UINT8_C(  166),  UINT8_C(   81),  UINT8_C(  181),  UINT8_C(  124),  UINT8_C(  164),  UINT8_C(   82)  } },
    { {  UINT8_C(  106),  UINT8_C(  175),  UINT8_C(   92),  UINT8_C(  116),  UINT8_C(   88),  UINT8_C(   72),  UINT8_C(  185),  UINT8_C(  179)  },
      {  UINT16_C(12059),  UINT16_C(64175),  UINT16_C(62948),  UINT16_C(45417),  UINT16_C(10359),  UINT16_C(22978),  UINT16_C(40265),  UINT16_C(15140)  },
      {  UINT16_C( 5905),  UINT16_C(21144),  UINT16_C(12969),  UINT16_C(37068),  UINT16_C(46022),  UINT16_C(33245),  UINT16_C(46817),  UINT16_C(41344)  },
      {  UINT8_C(  106),  UINT8_C(  175),  UINT8_C(   92),  UINT8_C(  116),  UINT8_C(   88),  UINT8_C(   72),  UINT8_C(  185),  UINT8_C(  179),  UINT8_C(   24),  UINT8_C(  168),  UINT8_C(  195),  UINT8_C(   33),  UINT8_C(  117),  UINT8_C(  216),  UINT8_C(  230),  UINT8_C(  154)  } },
    { {  UINT8_C(   95),  UINT8_C(   48),  UINT8_C(  246),  UINT8_C(   49),  UINT8_C(  184),  UINT8_C(  192),  UINT8_C(   82),  UINT8_C(  247)  },
      {  UINT16_C( 9636),  UINT16_C(60462),  UINT16_C(55485),  UINT16_C(38214),  UINT16_C(40221),  UINT16_C(42243),  UINT16_C(63986),  UINT16_C(29866)  },
      {  UINT16_C(20853),  UINT16_C(39462),  UINT16_C(47200),  UINT16_C(55659),  UINT16_C( 3178),  UINT16_C(11400),  UINT16_C(14681),  UINT16_C(21092)  },
      {  UINT8_C(   95),  UINT8_C(   48),  UINT8_C(  246),  UINT8_C(   49),  UINT8_C(  184),  UINT8_C(  192),  UINT8_C(   82),  UINT8_C(  247),  UINT8_C(  212),  UINT8_C(   82),  UINT8_C(   32),  UINT8_C(  188),  UINT8_C(  145),  UINT8_C(  120),  UINT8_C(  193),  UINT8_C(   34)  } },
    { {  UINT8_C(   20),  UINT8_C(  220),  UINT8_C(   10),  UINT8_C(   32),  UINT8_C(  231),  UINT8_C(  213),  UINT8_C(   17),  UINT8_C(  207)  },
      {  UINT16_C(21531),  UINT16_C(19493),  UINT16_C( 5660),  UINT16_C(23767),  UINT16_C(40695),  UINT16_C(19505),  UINT16_C(47924),  UINT16_C(53622)  },
      {  UINT16_C(60692),  UINT16_C(20628),  UINT16_C( 1724),  UINT16_C(24276),  UINT16_C(44233),  UINT16_C(14776),  UINT16_C(51369),  UINT16_C(30125)  },
      {  UINT8_C(   20),  UINT8_C(  220),  UINT8_C(   10),  UINT8_C(   32),  UINT8_C(  231),  UINT8_C(  213),  UINT8_C(   17),  UINT8_C(  207),  UINT8_C(  103),  UINT8_C(  252),  UINT8_C(   15),  UINT8_C(  254),  UINT8_C(  242),  UINT8_C(   18),  UINT8_C(  243),  UINT8_C(   92)  } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint8x8_t r_ = simde_vld1_u8(test_vec[i].r_);
    simde_uint16x8_t a = simde_vld1q_u16(test_vec[i].a);
    simde_uint16x8_t b = simde_vld1q_u16(test_vec[i].b);
    simde_uint8x16_t r = simde_vrsubhn_high_u16(r_, a, b);

    simde_test_arm_neon_assert_equal_u8x16(r, simde_vld1q_u8(test_vec[i].r));
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint8x8_t r_ = simde_test_arm_neon_random_u8x8();
    simde_uint16x8_t a = simde_test_arm_neon_random_u16x8();
    simde_uint16x8_t b = simde_test_arm_neon_random_u16x8();
    simde_uint8x16_t r = simde_vrsubhn_high_u16(r_, a, b);

    simde_test_arm_neon_write_u8x8(2, r_, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u16x8(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u16x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u8x16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vrsubhn_high_u32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint16_t r_[4];
    uint32_t a[4];
    uint32_t b[4];
    uint16_t r[8];
  } test_vec[] = {
    { {  UINT16_C(     41269),  UINT16_C(     50638),  UINT16_C(     61698),  UINT16_C(      7807)  },
      {  UINT32_C(1741988329),  UINT32_C(1606087118),  UINT32_C( 700475097),  UINT32_C(3688868886)  },
      {  UINT32_C(2806349967),  UINT32_C(1854800487),  UINT32_C(  21704828),  UINT32_C(3997988195)  },
      {  UINT16_C(     41269),  UINT16_C(     50638),  UINT16_C(     61698),  UINT16_C(      7807),  UINT16_C(     49295),  UINT16_C(     61741),  UINT16_C(     10357),  UINT16_C(     60819)  } },
    { {  UINT16_C(     34253),  UINT16_C(     44792),  UINT16_C(      7455),  UINT16_C(     26942)  },
      {  UINT32_C(4283611204),  UINT32_C(4280106541),  UINT32_C(2458782660),  UINT32_C(1830661178)  },
      {  UINT32_C(3706562521),  UINT32_C(2205941448),  UINT32_C(2302945884),  UINT32_C(4150772654)  },
      {  UINT16_C(     34253),  UINT16_C(     44792),  UINT16_C(      7455),  UINT16_C(     26942),  UINT16_C(      8805),  UINT16_C(     31649),  UINT16_C(      2378),  UINT16_C(     30134)  } },
    { {  UINT16_C(     11864),  UINT16_C(      1970),  UINT16_C(      6478),  UINT16_C(     21710)  },
      {  UINT32_C(2673192528),  UINT32_C(1952095768),  UINT32_C(3214859988),  UINT32_C( 343408403)  },
      {  UINT32_C(2243488234),  UINT32_C( 883441011),  UINT32_C(2409138063),  UINT32_C(1276108507)  },
      {  UINT16_C(     11864),  UINT16_C(      1970),  UINT16_C(      6478),  UINT16_C(     21710),  UINT16_C(      6557),  UINT16_C(     16306),  UINT16_C(     12294),  UINT16_C(     51304)  } },
    { {  UINT16_C(     50706),  UINT16_C(     37166),  UINT16_C(     14410),  UINT16_C(     64394)  },
      {  UINT32_C(1360680546),  UINT32_C(2100403524),  UINT32_C(1682447994),  UINT32_C(1336618539)  },
      {  UINT32_C( 973421663),  UINT32_C(3133116068),  UINT32_C(1237858822),  UINT32_C( 382114510)  },
      {  UINT16_C(     50706),  UINT16_C(     37166),  UINT16_C(     14410),  UINT16_C(     64394),  UINT16_C(      5909),  UINT16_C(     49778),  UINT16_C(      6784),  UINT16_C(     14565)  } },
    { {  UINT16_C(     28785),  UINT16_C(     52939),  UINT16_C(      4039),  UINT16_C(     58633)  },
      {  UINT32_C(3940626557),  UINT32_C( 638609814),  UINT32_C(1551602896),  UINT32_C(3076801985)  },
      {  UINT32_C(3455587449),  UINT32_C(1587525949),  UINT32_C(1767754029),  UINT32_C( 941250066)  },
      {  UINT16_C(     28785),  UINT16_C(     52939),  UINT16_C(      4039),  UINT16_C(     58633),  UINT16_C(      7401),  UINT16_C(     51057),  UINT16_C(     62238),  UINT16_C(     32586)  } },
    { {  UINT16_C(     19790),  UINT16_C(     48601),  UINT16_C(     34521),  UINT16_C(     53777)  },
      {  UINT32_C(3399780476),  UINT32_C(3128390483),  UINT32_C(2661794473),  UINT32_C(2711758066)  },
      {  UINT32_C(1783301814),  UINT32_C(2700865479),  UINT32_C(1792320211),  UINT32_C(1346550133)  },
      {  UINT16_C(     19790),  UINT16_C(     48601),  UINT16_C(     34521),  UINT16_C(     53777),  UINT16_C(     24666),  UINT16_C(      6524),  UINT16_C(     13267),  UINT16_C(     20831)  } },
    { {  UINT16_C(     30913),  UINT16_C(     40483),  UINT16_C(     13733),  UINT16_C(     11348)  },
      {  UINT32_C(3982828149),  UINT32_C(2078910112),  UINT32_C( 826117185),  UINT32_C(1511393051)  },
      {  UINT32_C(3523586226),  UINT32_C(2698734480),  UINT32_C(2154583641),  UINT32_C( 757340238)  },
      {  UINT16_C(     30913),  UINT16_C(     40483),  UINT16_C(     13733),  UINT16_C(     11348),  UINT16_C(      7007),  UINT16_C(     56078),  UINT16_C(     45265),  UINT16_C(     11506)  } },
    { {  UINT16_C(     24786),  UINT16_C(      6944),  UINT16_C(     14496),  UINT16_C(     43106)  },
      {  UINT32_C(2903731845),  UINT32_C( 303656794),  UINT32_C(3826239729),  UINT32_C( 525402713)  },
      {  UINT32_C(2544300481),  UINT32_C( 361837913),  UINT32_C( 649429955),  UINT32_C(3783680799)  },
      {  UINT16_C(     24786),  UINT16_C(      6944),  UINT16_C(     14496),  UINT16_C(     43106),  UINT16_C(      5484),  UINT16_C(     64648),  UINT16_C(     48474),  UINT16_C(     15819)  } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint16x4_t r_ = simde_vld1_u16(test_vec[i].r_);
    simde_uint32x4_t a = simde_vld1q_u32(test_vec[i].a);
    simde_uint32x4_t b = simde_vld1q_u32(test_vec[i].b);
    simde_uint16x8_t r = simde_vrsubhn_high_u32(r_, a, b);

    simde_test_arm_neon_assert_equal_u16x8(r, simde_vld1q_u16(test_vec[i].r));
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint16x4_t r_ = simde_test_arm_neon_random_u16x4();
    simde_uint32x4_t a = simde_test_arm_neon_random_u32x4();
    simde_uint32x4_t b = simde_test_arm_neon_random_u32x4();
    simde_uint16x8_t r = simde_vrsubhn_high_u32(r_, a, b);

    simde_test_arm_neon_write_u16x4(2, r_, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u32x4(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u16x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vrsubhn_high_u64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint32_t r_[2];
    uint64_t a[2];
    uint64_t b[2];
    uint32_t r[4];
  } test_vec[] = {
    { {  UINT32_C(          1871412901),  UINT32_C(          3393036411)  },
      {  UINT64_C(17731709460066361324),  UINT64_C(11218132822946835667)  },
      {  UINT64_C( 3438642190895232954),  UINT64_C(16745057506486448806)  },
      {  UINT32_C(          1871412901),  UINT32_C(          3393036411),  UINT32_C(          3327864052),  UINT32_C(          3008129865)  } },
    { {  UINT32_C(          3345833697),  UINT32_C(          2892487010)  },
      {  UINT64_C(15016907265298523829),  UINT64_C( 3408669964119177856)  },
      {  UINT64_C( 5786146879377488931),  UINT64_C(14643760497357938360)  },
      {  UINT32_C(          3345833697),  UINT32_C(          2892487010),  UINT32_C(          2149203882),  UINT32_C(          1679093936)  } },
    { {  UINT32_C(          3628723145),  UINT32_C(           897897657)  },
      {  UINT64_C(11792583140865019933),  UINT64_C(16941015192646112791)  },
      {  UINT64_C(17692816430312995448),  UINT64_C(16603442786833374610)  },
      {  UINT32_C(          3628723145),  UINT32_C(           897897657),  UINT32_C(          2921212182),  UINT32_C(            78597201)  } },
    { {  UINT32_C(          1542968199),  UINT32_C(          2506479180)  },
      {  UINT64_C( 9048986537022657802),  UINT64_C( 9932019547326549171)  },
      {  UINT64_C(10268029266140439713),  UINT64_C( 1637355560458647743)  },
      {  UINT32_C(          1542968199),  UINT32_C(          2506479180),  UINT32_C(          4011136793),  UINT32_C(          1931251955)  } },
    { {  UINT32_C(           513868505),  UINT32_C(           585247018)  },
      {  UINT64_C(11618880053111078913),  UINT64_C(14007978403554808354)  },
      {  UINT64_C( 2066260072343106377),  UINT64_C(17486312152245205426)  },
      {  UINT32_C(           513868505),  UINT32_C(           585247018),  UINT32_C(          2224142659),  UINT32_C(          3485104610)  } },
    { {  UINT32_C(           105946740),  UINT32_C(          3581109170)  },
      {  UINT64_C( 8517730612630495290),  UINT64_C(15091637072261973633)  },
      {  UINT64_C( 8273527098162170189),  UINT64_C( 6864551697442672809)  },
      {  UINT32_C(           105946740),  UINT32_C(          3581109170),  UINT32_C(            56858061),  UINT32_C(          1915517583)  } },
    { {  UINT32_C(          2072729636),  UINT32_C(          1142462021)  },
      {  UINT64_C( 6174206732082916876),  UINT64_C( 6872713127752786924)  },
      {  UINT64_C( 4337958157275197741),  UINT64_C(13402179920841493563)  },
      {  UINT32_C(          2072729636),  UINT32_C(          1142462021),  UINT32_C(           427534938),  UINT32_C(          2774707340)  } },
    { {  UINT32_C(          3616339027),  UINT32_C(          3569404306)  },
      {  UINT64_C( 1432544248088139574),  UINT64_C( 3578587937909353029)  },
      {  UINT64_C( 8328472411672646838),  UINT64_C( 5318579539293040351)  },
      {  UINT32_C(          3616339027),  UINT32_C(          3569404306),  UINT32_C(          2689383903),  UINT32_C(          3889843931)  } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint32x2_t r_ = simde_vld1_u32(test_vec[i].r_);
    simde_uint64x2_t a = simde_vld1q_u64(test_vec[i].a);
    simde_uint64x2_t b = simde_vld1q_u64(test_vec[i].b);
    simde_uint32x4_t r = simde_vrsubhn_high_u64(r_, a, b);

    simde_test_arm_neon_assert_equal_u32x4(r, simde_vld1q_u32(test_vec[i].r));
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint32x2_t r_ = simde_test_arm_neon_random_u32x2();
    simde_uint64x2_t a = simde_test_arm_neon_random_u64x2();
    simde_uint64x2_t b = simde_test_arm_neon_random_u64x2();
    simde_uint32x4_t r = simde_vrsubhn_high_u64(r_, a, b);

    simde_test_arm_neon_write_u32x2(2, r_, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u64x2(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u64x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}


SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(vrsubhn_high_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vrsubhn_high_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vrsubhn_high_s64)

SIMDE_TEST_FUNC_LIST_ENTRY(vrsubhn_high_u16)
SIMDE_TEST_FUNC_LIST_ENTRY(vrsubhn_high_u32)
SIMDE_TEST_FUNC_LIST_ENTRY(vrsubhn_high_u64)
SIMDE_TEST_FUNC_LIST_END

#include "test-neon-footer.h"
