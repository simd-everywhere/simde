#define SIMDE_TEST_ARM_NEON_INSN padal

#include "test-neon.h"
#include "../../../simde/arm/neon/padal.h"

static int
test_simde_vpadal_s8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int16_t a[4];
    int8_t b[8];
    int16_t r[4];
  } test_vec[] = {
    { { -INT16_C( 30161),  INT16_C( 28803),  INT16_C(  7944), -INT16_C( 11953) },
      {  INT8_C(  24), -INT8_C( 114),  INT8_C(  75),  INT8_C(  41), -INT8_C(  47), -INT8_C( 102),  INT8_C(  58),  INT8_C(  60) },
      { -INT16_C( 30251),  INT16_C( 28919),  INT16_C(  7795), -INT16_C( 11835) } },
    { {  INT16_C( 20613), -INT16_C(  1419), -INT16_C( 15592), -INT16_C( 26460) },
      {  INT8_C(  99), -INT8_C(  24),  INT8_C( 126),  INT8_C( 100), -INT8_C(  26),  INT8_C(  88),  INT8_C(  13),  INT8_C(  22) },
      {  INT16_C( 20688), -INT16_C(  1193), -INT16_C( 15530), -INT16_C( 26425) } },
    { { -INT16_C( 28446), -INT16_C(  5242), -INT16_C( 10833), -INT16_C( 14404) },
      {  INT8_C( 100),  INT8_C(   7), -INT8_C(  16),  INT8_C(  53), -INT8_C(  95),  INT8_C(  43),  INT8_C( 114),  INT8_C(  38) },
      { -INT16_C( 28339), -INT16_C(  5205), -INT16_C( 10885), -INT16_C( 14252) } },
    { { -INT16_C(  6277), -INT16_C( 27872), -INT16_C( 14934),  INT16_C(  3371) },
      { -INT8_C(  83), -INT8_C(  87),  INT8_C( 113), -INT8_C( 109),  INT8_C(   2),  INT8_C( 126), -INT8_C(  87), -INT8_C(  28) },
      { -INT16_C(  6447), -INT16_C( 27868), -INT16_C( 14806),  INT16_C(  3256) } },
    { {  INT16_C( 12302), -INT16_C( 16945), -INT16_C( 29947),  INT16_C( 27012) },
      { -INT8_C( 109),  INT8_C( 116), -INT8_C(  97),  INT8_C(  52), -INT8_C(  97),  INT8_C(  17),  INT8_C(  91),  INT8_C(  26) },
      {  INT16_C( 12309), -INT16_C( 16990), -INT16_C( 30027),  INT16_C( 27129) } },
    { {  INT16_C( 31736), -INT16_C( 23890), -INT16_C(  9920), -INT16_C(  4689) },
      { -INT8_C( 125),  INT8_C(  32), -INT8_C( 127), -INT8_C( 123), -INT8_C(  98),  INT8_C(  42),  INT8_C( 105), -INT8_C(  84) },
      {  INT16_C( 31643), -INT16_C( 24140), -INT16_C(  9976), -INT16_C(  4668) } },
    { {  INT16_C( 14682),  INT16_C( 24681), -INT16_C(  4668),  INT16_C( 22473) },
      {  INT8_C(  97),  INT8_C( 104), -INT8_C( 116),  INT8_C(   1),  INT8_C( 121), -INT8_C(  25),  INT8_C(  27),  INT8_C( 113) },
      {  INT16_C( 14883),  INT16_C( 24566), -INT16_C(  4572),  INT16_C( 22613) } },
    { { -INT16_C( 13982), -INT16_C( 23789), -INT16_C( 15709),  INT16_C(  9872) },
      { -INT8_C(  30),  INT8_C(  17), -INT8_C(  85),      INT8_MIN,  INT8_C(  60),  INT8_C(  20),  INT8_C(  44), -INT8_C( 106) },
      { -INT16_C( 13995), -INT16_C( 24002), -INT16_C( 15629),  INT16_C(  9810) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x4_t a = simde_vld1_s16(test_vec[i].a);
    simde_int8x8_t b = simde_vld1_s8(test_vec[i].b);
    simde_int16x4_t r = simde_vpadal_s8(a, b);

    simde_test_arm_neon_assert_equal_i16x4(r, simde_vld1_s16(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int16x4_t a = simde_test_arm_neon_random_i16x4();
    simde_int8x8_t b = simde_test_arm_neon_random_i8x8();
    simde_int16x4_t r = simde_vpadal_s8(a, b);

    simde_test_arm_neon_write_i16x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i8x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i16x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vpadal_s16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int32_t a[2];
    int16_t b[4];
    int32_t r[2];
  } test_vec[] = {
    { {  INT32_C(   504749832),  INT32_C(  1960423893) },
      {  INT16_C( 27165), -INT16_C(  2076), -INT16_C( 28050), -INT16_C( 17483) },
      {  INT32_C(   504774921),  INT32_C(  1960378360) } },
    { { -INT32_C(   866204476),  INT32_C(   326389811) },
      { -INT16_C(   654),  INT16_C( 31863), -INT16_C( 19755), -INT16_C(  8779) },
      { -INT32_C(   866173267),  INT32_C(   326361277) } },
    { {  INT32_C(  1727843217), -INT32_C(  1713711748) },
      { -INT16_C( 16577), -INT16_C( 21104),  INT16_C( 17745),  INT16_C(  5480) },
      {  INT32_C(  1727805536), -INT32_C(  1713688523) } },
    { {  INT32_C(  1038206730), -INT32_C(  1991224041) },
      { -INT16_C( 14254),  INT16_C(  9990), -INT16_C( 17542),  INT16_C(  3077) },
      {  INT32_C(  1038202466), -INT32_C(  1991238506) } },
    { {  INT32_C(    57803142),  INT32_C(   362565078) },
      {  INT16_C( 11532),  INT16_C( 24002),  INT16_C( 10866),  INT16_C( 31859) },
      {  INT32_C(    57838676),  INT32_C(   362607803) } },
    { {  INT32_C(   146363633), -INT32_C(    57537878) },
      { -INT16_C( 26414),  INT16_C( 19492),  INT16_C( 10579), -INT16_C(  9640) },
      {  INT32_C(   146356711), -INT32_C(    57536939) } },
    { {  INT32_C(    14535466),  INT32_C(   605387032) },
      { -INT16_C( 10330),  INT16_C(  6529), -INT16_C(  3071), -INT16_C(  3179) },
      {  INT32_C(    14531665),  INT32_C(   605380782) } },
    { { -INT32_C(   201633975),  INT32_C(   737119577) },
      {  INT16_C(  4901),  INT16_C( 31095), -INT16_C( 12228),  INT16_C( 26195) },
      { -INT32_C(   201597979),  INT32_C(   737133544) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x2_t a = simde_vld1_s32(test_vec[i].a);
    simde_int16x4_t b = simde_vld1_s16(test_vec[i].b);
    simde_int32x2_t r = simde_vpadal_s16(a, b);

    simde_test_arm_neon_assert_equal_i32x2(r, simde_vld1_s32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int32x2_t a = simde_test_arm_neon_random_i32x2();
    simde_int16x4_t b = simde_test_arm_neon_random_i16x4();
    simde_int32x2_t r = simde_vpadal_s16(a, b);

    simde_test_arm_neon_write_i32x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i16x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i32x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vpadal_s32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int64_t a[1];
    int32_t b[2];
    int64_t r[1];
  } test_vec[] = {
    { {  INT64_C( 4306996531119136319) },
      { -INT32_C(   712300919), -INT32_C(  1254531556) },
      {  INT64_C( 4306996529152303844) } },
    { { -INT64_C( 1142215973302328584) },
      { -INT32_C(   666473390), -INT32_C(  1794099370) },
      { -INT64_C( 1142215975762901344) } },
    { {  INT64_C( 5843113515927421525) },
      {  INT32_C(   724017423), -INT32_C(   136290049) },
      {  INT64_C( 5843113516515148899) } },
    { { -INT64_C( 4282400485266855678) },
      { -INT32_C(  1633888184),  INT32_C(  1681107983) },
      { -INT64_C( 4282400485219635879) } },
    { {  INT64_C( 5551061743561561839) },
      { -INT32_C(   176672522), -INT32_C(  1830004336) },
      {  INT64_C( 5551061741554884981) } },
    { { -INT64_C( 4181093637499411774) },
      { -INT32_C(  1402759779),  INT32_C(   823170626) },
      { -INT64_C( 4181093638079000927) } },
    { { -INT64_C( 7315831907249795092) },
      { -INT32_C(  1315966687),  INT32_C(   205749066) },
      { -INT64_C( 7315831908360012713) } },
    { { -INT64_C( 2783160537737758947) },
      {  INT32_C(   293979343),  INT32_C(  1195545946) },
      { -INT64_C( 2783160536248233658) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int64x1_t a = simde_vld1_s64(test_vec[i].a);
    simde_int32x2_t b = simde_vld1_s32(test_vec[i].b);
    simde_int64x1_t r = simde_vpadal_s32(a, b);

    simde_test_arm_neon_assert_equal_i64x1(r, simde_vld1_s64(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int64x1_t a = simde_test_arm_neon_random_i64x1();
    simde_int32x2_t b = simde_test_arm_neon_random_i32x2();
    simde_int64x1_t r = simde_vpadal_s32(a, b);

    simde_test_arm_neon_write_i64x1(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i32x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i64x1(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vpadal_u8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint16_t a[4];
    uint8_t b[8];
    uint16_t r[4];
  } test_vec[] = {
    { { UINT16_C(33837), UINT16_C(14344), UINT16_C(  212), UINT16_C(49109) },
      { UINT8_C( 82), UINT8_C(248), UINT8_C(222), UINT8_C( 54), UINT8_C(170), UINT8_C(254), UINT8_C(232), UINT8_C(178) },
      { UINT16_C(34167), UINT16_C(14620), UINT16_C(  636), UINT16_C(49519) } },
    { { UINT16_C(29181), UINT16_C(26461), UINT16_C(17709), UINT16_C( 6904) },
      { UINT8_C(124), UINT8_C(109), UINT8_C( 96), UINT8_C( 12), UINT8_C( 85), UINT8_C(144), UINT8_C( 43), UINT8_C(131) },
      { UINT16_C(29414), UINT16_C(26569), UINT16_C(17938), UINT16_C( 7078) } },
    { { UINT16_C(13076), UINT16_C(59835), UINT16_C(37171), UINT16_C(34216) },
      { UINT8_C(137), UINT8_C(134), UINT8_C(188), UINT8_C( 51), UINT8_C(133), UINT8_C(164), UINT8_C(229), UINT8_C(130) },
      { UINT16_C(13347), UINT16_C(60074), UINT16_C(37468), UINT16_C(34575) } },
    { { UINT16_C(17173), UINT16_C(17129), UINT16_C(57992), UINT16_C( 1116) },
      { UINT8_C( 79), UINT8_C(189), UINT8_C( 16), UINT8_C(165), UINT8_C( 77), UINT8_C( 60), UINT8_C( 40), UINT8_C( 98) },
      { UINT16_C(17441), UINT16_C(17310), UINT16_C(58129), UINT16_C( 1254) } },
    { { UINT16_C(58223), UINT16_C(41803), UINT16_C(62324), UINT16_C(65064) },
      { UINT8_C(122), UINT8_C(228), UINT8_C( 49),    UINT8_MAX, UINT8_C(137), UINT8_C( 23), UINT8_C(129), UINT8_C(158) },
      { UINT16_C(58573), UINT16_C(42107), UINT16_C(62484), UINT16_C(65351) } },
    { { UINT16_C(27226), UINT16_C(58081), UINT16_C(15692), UINT16_C(40167) },
      { UINT8_C(250), UINT8_C(247), UINT8_C( 65), UINT8_C( 72), UINT8_C( 51), UINT8_C(105), UINT8_C(170), UINT8_C(163) },
      { UINT16_C(27723), UINT16_C(58218), UINT16_C(15848), UINT16_C(40500) } },
    { { UINT16_C(62796), UINT16_C(49478), UINT16_C(28392), UINT16_C(25279) },
      { UINT8_C( 83), UINT8_C(240), UINT8_C( 97), UINT8_C(220), UINT8_C(  7), UINT8_C(226), UINT8_C(122), UINT8_C( 97) },
      { UINT16_C(63119), UINT16_C(49795), UINT16_C(28625), UINT16_C(25498) } },
    { { UINT16_C(23373), UINT16_C(39236), UINT16_C(11161), UINT16_C(37685) },
      { UINT8_C( 34), UINT8_C(118), UINT8_C(219), UINT8_C( 86), UINT8_C(223), UINT8_C(133), UINT8_C(249), UINT8_C( 44) },
      { UINT16_C(23525), UINT16_C(39541), UINT16_C(11517), UINT16_C(37978) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint16x4_t a = simde_vld1_u16(test_vec[i].a);
    simde_uint8x8_t b = simde_vld1_u8(test_vec[i].b);
    simde_uint16x4_t r = simde_vpadal_u8(a, b);

    simde_test_arm_neon_assert_equal_u16x4(r, simde_vld1_u16(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint16x4_t a = simde_test_arm_neon_random_u16x4();
    simde_uint8x8_t b = simde_test_arm_neon_random_u8x8();
    simde_uint16x4_t r = simde_vpadal_u8(a, b);

    simde_test_arm_neon_write_u16x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u8x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u16x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vpadal_u16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint32_t a[2];
    uint16_t b[4];
    uint32_t r[2];
  } test_vec[] = {
    { { UINT32_C(3031144186), UINT32_C(1298847721) },
      { UINT16_C(62939), UINT16_C(26118), UINT16_C(36198), UINT16_C( 1343) },
      { UINT32_C(3031233243), UINT32_C(1298885262) } },
    { { UINT32_C(1473052482), UINT32_C( 282556598) },
      { UINT16_C(63441), UINT16_C(33634), UINT16_C(36908), UINT16_C( 9772) },
      { UINT32_C(1473149557), UINT32_C( 282603278) } },
    { { UINT32_C( 266000166), UINT32_C(2304591022) },
      { UINT16_C(25401), UINT16_C(40944), UINT16_C(12273), UINT16_C(13220) },
      { UINT32_C( 266066511), UINT32_C(2304616515) } },
    { { UINT32_C(3851055406), UINT32_C(3136643817) },
      { UINT16_C(22617), UINT16_C(34110), UINT16_C(27368), UINT16_C( 3755) },
      { UINT32_C(3851112133), UINT32_C(3136674940) } },
    { { UINT32_C(4011689281), UINT32_C(  58227402) },
      { UINT16_C(26846), UINT16_C(53155), UINT16_C(18328), UINT16_C(50690) },
      { UINT32_C(4011769282), UINT32_C(  58296420) } },
    { { UINT32_C(2729151672), UINT32_C(1214030318) },
      { UINT16_C(39673), UINT16_C(57805), UINT16_C(30980), UINT16_C(17903) },
      { UINT32_C(2729249150), UINT32_C(1214079201) } },
    { { UINT32_C(3358854398), UINT32_C(1707912583) },
      { UINT16_C(28437), UINT16_C(44340), UINT16_C(14006), UINT16_C(28532) },
      { UINT32_C(3358927175), UINT32_C(1707955121) } },
    { { UINT32_C(2970689474), UINT32_C(3120131520) },
      { UINT16_C(50696), UINT16_C( 3226), UINT16_C(35135), UINT16_C(15954) },
      { UINT32_C(2970743396), UINT32_C(3120182609) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint32x2_t a = simde_vld1_u32(test_vec[i].a);
    simde_uint16x4_t b = simde_vld1_u16(test_vec[i].b);
    simde_uint32x2_t r = simde_vpadal_u16(a, b);
    simde_test_arm_neon_assert_equal_u32x2(r, simde_vld1_u32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint32x2_t a = simde_test_arm_neon_random_u32x2();
    simde_uint16x4_t b = simde_test_arm_neon_random_u16x4();
    simde_uint32x2_t r = simde_vpadal_u16(a, b);

    simde_test_arm_neon_write_u32x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u16x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vpadal_u32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint64_t a[1];
    uint32_t b[2];
    uint64_t r[1];
  } test_vec[] = {
    { { UINT64_C(16268155908237277759) },
      { UINT32_C( 875055710), UINT32_C(2229076956) },
      { UINT64_C(16268155911341410425) } },
    { { UINT64_C(14643826491213206399) },
      { UINT32_C(3716771902), UINT32_C( 554289377) },
      { UINT64_C(14643826495484267678) } },
    { { UINT64_C(12249248146022871426) },
      { UINT32_C( 954017628), UINT32_C(2847717930) },
      { UINT64_C(12249248149824606984) } },
    { { UINT64_C( 9580111084831634317) },
      { UINT32_C(3059842260), UINT32_C(3336006468) },
      { UINT64_C( 9580111091227483045) } },
    { { UINT64_C(10632965974969755036) },
      { UINT32_C( 868969481), UINT32_C(3017574182) },
      { UINT64_C(10632965978856298699) } },
    { { UINT64_C( 4631334754029602683) },
      { UINT32_C(2415306571), UINT32_C(2924924178) },
      { UINT64_C( 4631334759369833432) } },
    { { UINT64_C( 2647030380067305970) },
      { UINT32_C(3075966864), UINT32_C(2305438734) },
      { UINT64_C( 2647030385448711568) } },
    { { UINT64_C( 6910650571603723835) },
      { UINT32_C(1240456503), UINT32_C(2633450922) },
      { UINT64_C( 6910650575477631260) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint64x1_t a = simde_vld1_u64(test_vec[i].a);
    simde_uint32x2_t b = simde_vld1_u32(test_vec[i].b);
    simde_uint64x1_t r = simde_vpadal_u32(a, b);
    simde_test_arm_neon_assert_equal_u64x1(r, simde_vld1_u64(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint64x1_t a = simde_test_arm_neon_random_u64x1();
    simde_uint32x2_t b = simde_test_arm_neon_random_u32x2();
    simde_uint64x1_t r = simde_vpadal_u32(a, b);

    simde_test_arm_neon_write_u64x1(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u32x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u64x1(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vpadalq_s8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int16_t a[8];
    int8_t b[16];
    int16_t r[8];
  } test_vec[] = {
    { {  INT16_C( 21409), -INT16_C(  5093), -INT16_C( 30886), -INT16_C( 17820),  INT16_C(   488),  INT16_C(  5692), -INT16_C( 31806),  INT16_C( 26370) },
      { -INT8_C(  93), -INT8_C(  54),  INT8_C( 113), -INT8_C(  74), -INT8_C(  61),  INT8_C(  35), -INT8_C(  32),  INT8_C(  16),
        -INT8_C(  37), -INT8_C( 100),  INT8_C(  22), -INT8_C( 102),  INT8_C(   8),  INT8_C(   8),  INT8_C(  36), -INT8_C(  86) },
      {  INT16_C( 21262), -INT16_C(  5054), -INT16_C( 30912), -INT16_C( 17836),  INT16_C(   351),  INT16_C(  5612), -INT16_C( 31790),  INT16_C( 26320) } },
    { {  INT16_C( 16220), -INT16_C( 18794), -INT16_C(  1082), -INT16_C( 20624), -INT16_C( 21252), -INT16_C( 16699), -INT16_C( 14544), -INT16_C( 11483) },
      { -INT8_C( 110), -INT8_C( 106), -INT8_C( 119),  INT8_C(  85), -INT8_C(  71),  INT8_C( 106),  INT8_C( 101), -INT8_C( 108),
         INT8_C(   6),  INT8_C( 123),  INT8_C(  47),  INT8_C(  14), -INT8_C( 124),  INT8_C(  83), -INT8_C(  72), -INT8_C(  32) },
      {  INT16_C( 16004), -INT16_C( 18828), -INT16_C(  1047), -INT16_C( 20631), -INT16_C( 21123), -INT16_C( 16638), -INT16_C( 14585), -INT16_C( 11587) } },
    { {  INT16_C( 20371),  INT16_C( 22934),  INT16_C(  1610),  INT16_C( 17928), -INT16_C( 12878), -INT16_C(  7676),  INT16_C( 10645),  INT16_C( 10165) },
      { -INT8_C(  65),  INT8_C(  63),  INT8_C( 124),  INT8_C( 120), -INT8_C(  87), -INT8_C(  31),  INT8_C(  13), -INT8_C(  81),
         INT8_C(  93),  INT8_C(  60), -INT8_C(  67), -INT8_C(  31), -INT8_C( 113),  INT8_C( 118), -INT8_C(  63),  INT8_C(  34) },
      {  INT16_C( 20369),  INT16_C( 23178),  INT16_C(  1492),  INT16_C( 17860), -INT16_C( 12725), -INT16_C(  7774),  INT16_C( 10650),  INT16_C( 10136) } },
    { {  INT16_C( 22469),  INT16_C(  3964), -INT16_C( 31651),  INT16_C(  3925),  INT16_C( 22866), -INT16_C(  6158), -INT16_C( 22654),  INT16_C( 16654) },
      { -INT8_C(  26), -INT8_C( 118), -INT8_C(  71), -INT8_C( 113),  INT8_C( 107), -INT8_C(  58),  INT8_C(  62), -INT8_C(  56),
         INT8_C(   2), -INT8_C(   4), -INT8_C(  87), -INT8_C( 110),  INT8_C( 114),  INT8_C( 106), -INT8_C(  76),  INT8_C(  55) },
      {  INT16_C( 22325),  INT16_C(  3780), -INT16_C( 31602),  INT16_C(  3931),  INT16_C( 22864), -INT16_C(  6355), -INT16_C( 22434),  INT16_C( 16633) } },
    { {  INT16_C( 12481),  INT16_C(  7750), -INT16_C( 25675),  INT16_C(  1838),  INT16_C(  8436),  INT16_C( 30446), -INT16_C(   825), -INT16_C( 20809) },
      { -INT8_C( 122),  INT8_C( 112),  INT8_C(  61), -INT8_C(  15),  INT8_C(  55),  INT8_C( 124), -INT8_C(  70),  INT8_C(  57),
         INT8_C( 120),  INT8_C(  99), -INT8_C(  53), -INT8_C(  22), -INT8_C(  50),      INT8_MIN,  INT8_C(  33), -INT8_C( 113) },
      {  INT16_C( 12471),  INT16_C(  7796), -INT16_C( 25496),  INT16_C(  1825),  INT16_C(  8655),  INT16_C( 30371), -INT16_C(  1003), -INT16_C( 20889) } },
    { {  INT16_C( 26544),  INT16_C( 26030), -INT16_C(  9214), -INT16_C(  2452),  INT16_C( 23292), -INT16_C( 15508),  INT16_C(  9046), -INT16_C(  9103) },
      { -INT8_C( 109), -INT8_C(  81), -INT8_C(  50), -INT8_C(  54),  INT8_C(  43), -INT8_C( 120),  INT8_C(   4), -INT8_C(  93),
        -INT8_C(  21), -INT8_C(  49), -INT8_C( 115), -INT8_C(  71),  INT8_C(  79), -INT8_C(  82),  INT8_C(  73),  INT8_C(   0) },
      {  INT16_C( 26354),  INT16_C( 25926), -INT16_C(  9291), -INT16_C(  2541),  INT16_C( 23222), -INT16_C( 15694),  INT16_C(  9043), -INT16_C(  9030) } },
    { { -INT16_C(  2283),  INT16_C(  5989), -INT16_C( 11565), -INT16_C( 12531),  INT16_C( 31020), -INT16_C( 31854),  INT16_C(  1180),  INT16_C( 12127) },
      { -INT8_C(  77),  INT8_C(  45), -INT8_C(   6), -INT8_C(  34), -INT8_C(  75), -INT8_C(   2), -INT8_C( 127), -INT8_C(  95),
        -INT8_C(  51),  INT8_C(  14),  INT8_C(  90),  INT8_C(  29), -INT8_C(  68), -INT8_C(  93),  INT8_C(  29), -INT8_C(  47) },
      { -INT16_C(  2315),  INT16_C(  5949), -INT16_C( 11642), -INT16_C( 12753),  INT16_C( 30983), -INT16_C( 31735),  INT16_C(  1019),  INT16_C( 12109) } },
    { { -INT16_C( 32102),  INT16_C( 28136), -INT16_C(  2732), -INT16_C( 32452), -INT16_C( 12434),  INT16_C(  2564),  INT16_C( 25555), -INT16_C( 31175) },
      { -INT8_C( 111),  INT8_C(  51),  INT8_C( 100),  INT8_C(  70),  INT8_C(  49), -INT8_C(  27), -INT8_C(  25), -INT8_C(   1),
        -INT8_C(  13),  INT8_C(  66),  INT8_C(  28), -INT8_C(  81), -INT8_C(  27),  INT8_C(  57),      INT8_MIN,      INT8_MIN },
      { -INT16_C( 32162),  INT16_C( 28306), -INT16_C(  2710), -INT16_C( 32478), -INT16_C( 12381),  INT16_C(  2511),  INT16_C( 25585), -INT16_C( 31431) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x8_t a = simde_vld1q_s16(test_vec[i].a);
    simde_int8x16_t b = simde_vld1q_s8(test_vec[i].b);
    simde_int16x8_t r = simde_vpadalq_s8(a, b);

    simde_test_arm_neon_assert_equal_i16x8(r, simde_vld1q_s16(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int16x8_t a = simde_test_arm_neon_random_i16x8();
    simde_int8x16_t b = simde_test_arm_neon_random_i8x16();
    simde_int16x8_t r = simde_vpadalq_s8(a, b);

    simde_test_arm_neon_write_i16x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i8x16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i16x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vpadalq_s16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int32_t a[4];
    int16_t b[8];
    int32_t r[4];
  } test_vec[] = {
    { { -INT32_C(   408029165),  INT32_C(   562585106),  INT32_C(  1007709111), -INT32_C(   179631329) },
      {  INT16_C( 22791), -INT16_C( 17866), -INT16_C( 27083), -INT16_C(  8697), -INT16_C( 22514), -INT16_C(  2564),  INT16_C( 18719),  INT16_C( 13052) },
      { -INT32_C(   408024240),  INT32_C(   562549326),  INT32_C(  1007684033), -INT32_C(   179599558) } },
    { {  INT32_C(  1394190657), -INT32_C(  1082875641),  INT32_C(   754680844), -INT32_C(  1759426928) },
      {  INT16_C( 22431), -INT16_C( 10927),  INT16_C( 23021), -INT16_C(  1101), -INT16_C( 20479),  INT16_C(  8433), -INT16_C(  4615),  INT16_C( 14930) },
      {  INT32_C(  1394202161), -INT32_C(  1082853721),  INT32_C(   754668798), -INT32_C(  1759416613) } },
    { { -INT32_C(  1651676266),  INT32_C(   425460237),  INT32_C(   373643398),  INT32_C(  1051551390) },
      { -INT16_C(    66), -INT16_C( 21741), -INT16_C( 14760),  INT16_C( 22951), -INT16_C( 26506),  INT16_C( 28537), -INT16_C( 13435),  INT16_C(  7081) },
      { -INT32_C(  1651698073),  INT32_C(   425468428),  INT32_C(   373645429),  INT32_C(  1051545036) } },
    { {  INT32_C(  1136146230), -INT32_C(  1084418759),  INT32_C(   198615661), -INT32_C(   951483639) },
      {  INT16_C( 23682), -INT16_C(  9614),  INT16_C(  6435), -INT16_C( 26317), -INT16_C( 21327),  INT16_C( 13833), -INT16_C( 19849), -INT16_C( 20911) },
      {  INT32_C(  1136160298), -INT32_C(  1084438641),  INT32_C(   198608167), -INT32_C(   951524399) } },
    { {  INT32_C(   586222313), -INT32_C(  1931325921), -INT32_C(    90720015), -INT32_C(  1094590149) },
      {  INT16_C( 13117),  INT16_C( 24728), -INT16_C( 13235), -INT16_C(   262),  INT16_C(   888), -INT16_C(  4043), -INT16_C( 31051), -INT16_C( 24674) },
      {  INT32_C(   586260158), -INT32_C(  1931339418), -INT32_C(    90723170), -INT32_C(  1094645874) } },
    { { -INT32_C(  1346269296), -INT32_C(   818175010), -INT32_C(  1748380837), -INT32_C(   246052172) },
      { -INT16_C(  4675),  INT16_C(  2642),  INT16_C( 19641),  INT16_C( 12809),  INT16_C( 15951),  INT16_C(  1058), -INT16_C( 16188),  INT16_C( 21923) },
      { -INT32_C(  1346271329), -INT32_C(   818142560), -INT32_C(  1748363828), -INT32_C(   246046437) } },
    { {  INT32_C(   755262799),  INT32_C(  1694253064), -INT32_C(   939801325),  INT32_C(   230182991) },
      {  INT16_C(  2621), -INT16_C(  2281),  INT16_C(  8278), -INT16_C( 23255),  INT16_C( 19294),  INT16_C(  9130),  INT16_C( 19723),  INT16_C( 23160) },
      {  INT32_C(   755263139),  INT32_C(  1694238087), -INT32_C(   939772901),  INT32_C(   230225874) } },
    { { -INT32_C(  1148683086), -INT32_C(   820017988), -INT32_C(  1718216118), -INT32_C(  1482272918) },
      { -INT16_C( 16807), -INT16_C( 20322), -INT16_C( 14370),  INT16_C( 15701), -INT16_C(   238),  INT16_C(  7520), -INT16_C( 10163), -INT16_C(   136) },
      { -INT32_C(  1148720215), -INT32_C(   820016657), -INT32_C(  1718208836), -INT32_C(  1482283217) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x4_t a = simde_vld1q_s32(test_vec[i].a);
    simde_int16x8_t b = simde_vld1q_s16(test_vec[i].b);
    simde_int32x4_t r = simde_vpadalq_s16(a, b);

    simde_test_arm_neon_assert_equal_i32x4(r, simde_vld1q_s32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int32x4_t a = simde_test_arm_neon_random_i32x4();
    simde_int16x8_t b = simde_test_arm_neon_random_i16x8();
    simde_int32x4_t r = simde_vpadalq_s16(a, b);

    simde_test_arm_neon_write_i32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i16x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vpadalq_s32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int64_t a[2];
    int32_t b[4];
    int64_t r[2];
  } test_vec[] = {
    { {  INT64_C( 8358831643597162478), -INT64_C( 4127542501836088642) },
      { -INT32_C(  1695082653),  INT32_C(   482778832), -INT32_C(   270956823), -INT32_C(  1466047046) },
      {  INT64_C( 8358831642384858657), -INT64_C( 4127542503573092511) } },
    { { -INT64_C( 3695083590524238804), -INT64_C( 2538875182963854584) },
      {  INT32_C(    24558385),  INT32_C(  1125989722),  INT32_C(  2100492227),  INT32_C(   153473244) },
      { -INT64_C( 3695083589373690697), -INT64_C( 2538875180709889113) } },
    { {  INT64_C(  517356502106542676), -INT64_C( 2536429654596284297) },
      { -INT32_C(   539147643),  INT32_C(  1109588863), -INT32_C(   826321422),  INT32_C(  2044191781) },
      {  INT64_C(  517356502676983896), -INT64_C( 2536429653378413938) } },
    { { -INT64_C( 6882334586154834826), -INT64_C( 3305540639557385319) },
      {  INT32_C(   515046814), -INT32_C(   362752776),  INT32_C(  1320755241),  INT32_C(  2076741636) },
      { -INT64_C( 6882334586002540788), -INT64_C( 3305540636159888442) } },
    { {  INT64_C( 5079337647775785908),  INT64_C(  509375601867099633) },
      { -INT32_C(  1608137816), -INT32_C(  1047820649), -INT32_C(  1441839962), -INT32_C(  1994008620) },
      {  INT64_C( 5079337645119827443),  INT64_C(  509375598431251051) } },
    { {  INT64_C( 8534008504961603195),  INT64_C( 5431559555495885296) },
      {  INT32_C(   552371849), -INT32_C(  1293846772), -INT32_C(  1889734213),  INT32_C(  1125679816) },
      {  INT64_C( 8534008504220128272),  INT64_C( 5431559554731830899) } },
    { {  INT64_C( 5878563524265606808), -INT64_C( 7439371473419351597) },
      { -INT32_C(  1648841071), -INT32_C(   531654107),  INT32_C(  1399827339), -INT32_C(   963147731) },
      {  INT64_C( 5878563522085111630), -INT64_C( 7439371472982671989) } },
    { { -INT64_C( 5784460457844473338),  INT64_C(   29247489515611328) },
      { -INT32_C(  1147330410),  INT32_C(  1167846586), -INT32_C(   979891561), -INT32_C(  1718931566) },
      { -INT64_C( 5784460457823957162),  INT64_C(   29247486816788201) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int64x2_t a = simde_vld1q_s64(test_vec[i].a);
    simde_int32x4_t b = simde_vld1q_s32(test_vec[i].b);
    simde_int64x2_t r = simde_vpadalq_s32(a, b);
    simde_test_arm_neon_assert_equal_i64x2(r, simde_vld1q_s64(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int64x2_t a = simde_test_arm_neon_random_i64x2();
    simde_int32x4_t b = simde_test_arm_neon_random_i32x4();
    simde_int64x2_t r = simde_vpadalq_s32(a, b);

    simde_test_arm_neon_write_i64x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vpadalq_u8 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint16_t a[8];
    uint8_t b[16];
    uint16_t r[8];
  } test_vec[] = {
    { { UINT16_C(62196), UINT16_C(63140), UINT16_C( 6425), UINT16_C(55467), UINT16_C(34429), UINT16_C(59966), UINT16_C(34679), UINT16_C(58442) },
      { UINT8_C(140), UINT8_C(113), UINT8_C(171), UINT8_C(189), UINT8_C( 42), UINT8_C( 80), UINT8_C( 89), UINT8_C(103),
        UINT8_C(177), UINT8_C(142), UINT8_C( 67), UINT8_C(228), UINT8_C(125), UINT8_C( 11), UINT8_C( 27), UINT8_C(114) },
      { UINT16_C(62449), UINT16_C(63500), UINT16_C( 6547), UINT16_C(55659), UINT16_C(34748), UINT16_C(60261), UINT16_C(34815), UINT16_C(58583) } },
    { { UINT16_C(49406), UINT16_C( 5992), UINT16_C( 5337), UINT16_C(22255), UINT16_C(11674), UINT16_C( 4673), UINT16_C(35764), UINT16_C(16886) },
      { UINT8_C(252), UINT8_C(161), UINT8_C(254), UINT8_C( 39), UINT8_C(242), UINT8_C( 87), UINT8_C(142), UINT8_C(163),
        UINT8_C(230), UINT8_C(210), UINT8_C(135), UINT8_C( 99), UINT8_C(221), UINT8_C(163), UINT8_C(213), UINT8_C(219) },
      { UINT16_C(49819), UINT16_C( 6285), UINT16_C( 5666), UINT16_C(22560), UINT16_C(12114), UINT16_C( 4907), UINT16_C(36148), UINT16_C(17318) } },
    { { UINT16_C(15971), UINT16_C(15603), UINT16_C(57938), UINT16_C(60563), UINT16_C(54288), UINT16_C(50430), UINT16_C(62559), UINT16_C(23301) },
      { UINT8_C(150), UINT8_C(  3), UINT8_C(130), UINT8_C(136), UINT8_C( 91), UINT8_C( 17), UINT8_C( 43), UINT8_C( 65),
        UINT8_C(227), UINT8_C(178), UINT8_C(164), UINT8_C(192), UINT8_C( 85), UINT8_C(122), UINT8_C(156), UINT8_C(184) },
      { UINT16_C(16124), UINT16_C(15869), UINT16_C(58046), UINT16_C(60671), UINT16_C(54693), UINT16_C(50786), UINT16_C(62766), UINT16_C(23641) } },
    { { UINT16_C(36792), UINT16_C( 2805), UINT16_C(34929), UINT16_C(33270), UINT16_C(62812), UINT16_C(47942), UINT16_C(19433), UINT16_C(32534) },
      { UINT8_C( 79), UINT8_C(153), UINT8_C(  7), UINT8_C(170), UINT8_C(170), UINT8_C( 50), UINT8_C(235), UINT8_C(141),
        UINT8_C(229), UINT8_C(143), UINT8_C( 77), UINT8_C( 58), UINT8_C(  9), UINT8_C(233), UINT8_C(243), UINT8_C(193) },
      { UINT16_C(37024), UINT16_C( 2982), UINT16_C(35149), UINT16_C(33646), UINT16_C(63184), UINT16_C(48077), UINT16_C(19675), UINT16_C(32970) } },
    { { UINT16_C(59512), UINT16_C(60107), UINT16_C(49776), UINT16_C(52331), UINT16_C(45495), UINT16_C(41095), UINT16_C(40445), UINT16_C(19488) },
      { UINT8_C( 54), UINT8_C( 39), UINT8_C(246), UINT8_C(224), UINT8_C( 90), UINT8_C(225), UINT8_C(109), UINT8_C( 63),
        UINT8_C(112), UINT8_C(187), UINT8_C(121), UINT8_C(122), UINT8_C(164), UINT8_C(108), UINT8_C( 59), UINT8_C( 29) },
      { UINT16_C(59605), UINT16_C(60577), UINT16_C(50091), UINT16_C(52503), UINT16_C(45794), UINT16_C(41338), UINT16_C(40717), UINT16_C(19576) } },
    { { UINT16_C( 1876), UINT16_C(50183), UINT16_C(29385), UINT16_C(32912), UINT16_C( 5924), UINT16_C( 8480), UINT16_C(16565), UINT16_C(60269) },
      { UINT8_C(104), UINT8_C( 99), UINT8_C(204), UINT8_C(194), UINT8_C( 68), UINT8_C( 57), UINT8_C(  1), UINT8_C(180),
        UINT8_C(244), UINT8_C(122), UINT8_C( 46), UINT8_C(153), UINT8_C(231), UINT8_C(106), UINT8_C(182), UINT8_C( 59) },
      { UINT16_C( 2079), UINT16_C(50581), UINT16_C(29510), UINT16_C(33093), UINT16_C( 6290), UINT16_C( 8679), UINT16_C(16902), UINT16_C(60510) } },
    { { UINT16_C(48497), UINT16_C(14848), UINT16_C(36911), UINT16_C(21434), UINT16_C(55976), UINT16_C(23924), UINT16_C(57627), UINT16_C(33608) },
      { UINT8_C( 68), UINT8_C( 20), UINT8_C( 69), UINT8_C(136), UINT8_C( 78), UINT8_C( 70), UINT8_C( 61), UINT8_C( 66),
        UINT8_C(192), UINT8_C(107), UINT8_C(219), UINT8_C(167), UINT8_C(213), UINT8_C(145), UINT8_C(227), UINT8_C( 70) },
      { UINT16_C(48585), UINT16_C(15053), UINT16_C(37059), UINT16_C(21561), UINT16_C(56275), UINT16_C(24310), UINT16_C(57985), UINT16_C(33905) } },
    { { UINT16_C(58190), UINT16_C(32384), UINT16_C(14963), UINT16_C( 7121), UINT16_C(17941), UINT16_C(12408), UINT16_C(49447), UINT16_C(27827) },
      { UINT8_C(213), UINT8_C(248), UINT8_C(244), UINT8_C( 35), UINT8_C( 62), UINT8_C( 49), UINT8_C(102), UINT8_C(254),
        UINT8_C(157), UINT8_C( 65), UINT8_C(166), UINT8_C(114), UINT8_C(211), UINT8_C(137), UINT8_C(185), UINT8_C( 33) },
      { UINT16_C(58651), UINT16_C(32663), UINT16_C(15074), UINT16_C( 7477), UINT16_C(18163), UINT16_C(12688), UINT16_C(49795), UINT16_C(28045) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint16x8_t a = simde_vld1q_u16(test_vec[i].a);
    simde_uint8x16_t b = simde_vld1q_u8(test_vec[i].b);
    simde_uint16x8_t r = simde_vpadalq_u8(a, b);

    simde_test_arm_neon_assert_equal_u16x8(r, simde_vld1q_u16(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint16x8_t a = simde_test_arm_neon_random_u16x8();
    simde_uint8x16_t b = simde_test_arm_neon_random_u8x16();
    simde_uint16x8_t r = simde_vpadalq_u8(a, b);

    simde_test_arm_neon_write_u16x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u8x16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u16x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vpadalq_u16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint32_t a[4];
    uint16_t b[8];
    uint32_t r[4];
  } test_vec[] = {
    { { UINT32_C(3624145319), UINT32_C(1377518211), UINT32_C(3012138328), UINT32_C(2898950110) },
      { UINT16_C(46785), UINT16_C(45446), UINT16_C(16731), UINT16_C(63885), UINT16_C(37154), UINT16_C(54076), UINT16_C(44856), UINT16_C(57089) },
      { UINT32_C(3624237550), UINT32_C(1377598827), UINT32_C(3012229558), UINT32_C(2899052055) } },
    { { UINT32_C(1152845248), UINT32_C(2694238792), UINT32_C(1179852648), UINT32_C(1475485078) },
      { UINT16_C(31188), UINT16_C(12040), UINT16_C(38330), UINT16_C(56360), UINT16_C(25894), UINT16_C(24240), UINT16_C(45332), UINT16_C(54333) },
      { UINT32_C(1152888476), UINT32_C(2694333482), UINT32_C(1179902782), UINT32_C(1475584743) } },
    { { UINT32_C(4263048630), UINT32_C( 798994119), UINT32_C(1668739789), UINT32_C(3837487120) },
      { UINT16_C(50145), UINT16_C(39955), UINT16_C(15449), UINT16_C(32632), UINT16_C(10401), UINT16_C(46558), UINT16_C( 7129), UINT16_C(37001) },
      { UINT32_C(4263138730), UINT32_C( 799042200), UINT32_C(1668796748), UINT32_C(3837531250) } },
    { { UINT32_C(3633226256), UINT32_C( 503786832), UINT32_C( 813792544), UINT32_C(3339992294) },
      { UINT16_C( 9984), UINT16_C(22883), UINT16_C(56419), UINT16_C( 1240), UINT16_C(46596), UINT16_C(57017), UINT16_C(17362), UINT16_C(57966) },
      { UINT32_C(3633259123), UINT32_C( 503844491), UINT32_C( 813896157), UINT32_C(3340067622) } },
    { { UINT32_C( 901446885), UINT32_C(1247003178), UINT32_C( 628806975), UINT32_C( 300781073) },
      { UINT16_C(20661), UINT16_C( 6506), UINT16_C(17196), UINT16_C(12573), UINT16_C(55289), UINT16_C(51983), UINT16_C(32026), UINT16_C(65454) },
      { UINT32_C( 901474052), UINT32_C(1247032947), UINT32_C( 628914247), UINT32_C( 300878553) } },
    { { UINT32_C(2738120825), UINT32_C(1793951786), UINT32_C(1854891869), UINT32_C(2877324533) },
      { UINT16_C(60109), UINT16_C(63940), UINT16_C(57645), UINT16_C(10026), UINT16_C(14776), UINT16_C(54002), UINT16_C(41142), UINT16_C(12497) },
      { UINT32_C(2738244874), UINT32_C(1794019457), UINT32_C(1854960647), UINT32_C(2877378172) } },
    { { UINT32_C( 869467657), UINT32_C(3952984462), UINT32_C( 509160744), UINT32_C(1992939945) },
      { UINT16_C(36292), UINT16_C(61808), UINT16_C(39534), UINT16_C(10008), UINT16_C( 3028), UINT16_C(35577), UINT16_C(52139), UINT16_C(46266) },
      { UINT32_C( 869565757), UINT32_C(3953034004), UINT32_C( 509199349), UINT32_C(1993038350) } },
    { { UINT32_C(1609076433), UINT32_C(2001372495), UINT32_C(1553310642), UINT32_C(1104305789) },
      { UINT16_C(17131), UINT16_C(23090), UINT16_C(19421), UINT16_C(45441), UINT16_C(31318), UINT16_C(  315), UINT16_C(63045), UINT16_C( 5814) },
      { UINT32_C(1609116654), UINT32_C(2001437357), UINT32_C(1553342275), UINT32_C(1104374648) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint32x4_t a = simde_vld1q_u32(test_vec[i].a);
    simde_uint16x8_t b = simde_vld1q_u16(test_vec[i].b);
    simde_uint32x4_t r = simde_vpadalq_u16(a, b);
    simde_test_arm_neon_assert_equal_u32x4(r, simde_vld1q_u32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint32x4_t a = simde_test_arm_neon_random_u32x4();
    simde_uint16x8_t b = simde_test_arm_neon_random_u16x8();
    simde_uint32x4_t r = simde_vpadalq_u16(a, b);

    simde_test_arm_neon_write_u32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u16x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vpadalq_u32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint64_t a[2];
    uint32_t b[4];
    uint64_t r[2];
  } test_vec[] = {
    { { UINT64_C( 6651368149195880995), UINT64_C(16555414622728810358) },
      { UINT32_C(3603103992), UINT32_C(4097160130), UINT32_C(  53538364), UINT32_C(4025022924) },
      { UINT64_C( 6651368156896145117), UINT64_C(16555414626807371646) } },
    { { UINT64_C(17395039739962856179), UINT64_C( 1319346996561212807) },
      { UINT32_C( 115872323), UINT32_C(  33168837), UINT32_C(3607440139), UINT32_C( 398912804) },
      { UINT64_C(17395039740111897339), UINT64_C( 1319347000567565750) } },
    { { UINT64_C( 3416976098987217151), UINT64_C( 8370758154985271038) },
      { UINT32_C(3212448762), UINT32_C(1019311408), UINT32_C(3289630368), UINT32_C(3000752819) },
      { UINT64_C( 3416976103218977321), UINT64_C( 8370758161275654225) } },
    { { UINT64_C( 9566376262250659306), UINT64_C( 4408117228946086790) },
      { UINT32_C( 184395482), UINT32_C(3141975579), UINT32_C( 931093124), UINT32_C( 518609716) },
      { UINT64_C( 9566376265577030367), UINT64_C( 4408117230395789630) } },
    { { UINT64_C( 3847046805425559128), UINT64_C(11623818981066735823) },
      { UINT32_C(3685436863), UINT32_C(2409034251), UINT32_C(2160465484), UINT32_C(3382620273) },
      { UINT64_C( 3847046811520030242), UINT64_C(11623818986609821580) } },
    { { UINT64_C(10640612582520017094), UINT64_C( 8103373972678547468) },
      { UINT32_C(1347100484), UINT32_C(1574953489), UINT32_C(1776133880), UINT32_C( 473070678) },
      { UINT64_C(10640612585442071067), UINT64_C( 8103373974927752026) } },
    { { UINT64_C(17519915040173644748), UINT64_C(  429595417324735189) },
      { UINT32_C(1800749657), UINT32_C( 482882852), UINT32_C( 830842587), UINT32_C(3998070562) },
      { UINT64_C(17519915042457277257), UINT64_C(  429595422153648338) } },
    { { UINT64_C(17396456604294897554), UINT64_C(14281598779226796651) },
      { UINT32_C(3560015792), UINT32_C(2549152188), UINT32_C(3251139999), UINT32_C(3215922732) },
      { UINT64_C(17396456610404065534), UINT64_C(14281598785693859382) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint64x2_t a = simde_vld1q_u64(test_vec[i].a);
    simde_uint32x4_t b = simde_vld1q_u32(test_vec[i].b);
    simde_uint64x2_t r = simde_vpadalq_u32(a, b);

    simde_test_arm_neon_assert_equal_u64x2(r, simde_vld1q_u64(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint64x2_t a = simde_test_arm_neon_random_u64x2();
    simde_uint32x4_t b = simde_test_arm_neon_random_u32x4();
    simde_uint64x2_t r = simde_vpadalq_u32(a, b);

    simde_test_arm_neon_write_u64x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(vpadal_s8)
SIMDE_TEST_FUNC_LIST_ENTRY(vpadal_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vpadal_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vpadal_u8)
SIMDE_TEST_FUNC_LIST_ENTRY(vpadal_u16)
SIMDE_TEST_FUNC_LIST_ENTRY(vpadal_u32)

SIMDE_TEST_FUNC_LIST_ENTRY(vpadalq_s8)
SIMDE_TEST_FUNC_LIST_ENTRY(vpadalq_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vpadalq_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vpadalq_u8)
SIMDE_TEST_FUNC_LIST_ENTRY(vpadalq_u16)
SIMDE_TEST_FUNC_LIST_ENTRY(vpadalq_u32)
SIMDE_TEST_FUNC_LIST_END

#include "test-neon-footer.h"
