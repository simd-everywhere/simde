#define SIMDE_TEST_ARM_NEON_INSN qdmull

#include "test-neon.h"
#include "../../../simde/arm/neon/qdmull.h"

static int
test_simde_vqdmull_s16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int16_t a[4];
    int16_t b[4];
    int32_t r[4];
  } test_vec[] = {
    { {  INT16_C( 31681),  INT16_C( 13027), -INT16_C( 13937), -INT16_C( 20674) },
      {  INT16_C( 10302), -INT16_C( 18422),  INT16_C(  4806), -INT16_C( 12487) },
      {  INT32_C(   652755324), -INT32_C(   479966788), -INT32_C(   133962444),  INT32_C(   516312476) } },
    { { -INT16_C( 13071),  INT16_C( 28436),  INT16_C(  8073), -INT16_C( 13812) },
      { -INT16_C(  4168),  INT16_C(  8843),  INT16_C( 11236), -INT16_C( 23047) },
      {  INT32_C(   108959856),  INT32_C(   502919096),  INT32_C(   181416456),  INT32_C(   636650328) } },
    { { -INT16_C(  8794),  INT16_C( 14039),  INT16_C(  5542), -INT16_C(  6939) },
      { -INT16_C(  4291),  INT16_C(   925), -INT16_C( 10750), -INT16_C(  3117) },
      {  INT32_C(    75470108),  INT32_C(    25972150), -INT32_C(   119153000),  INT32_C(    43257726) } },
    { { -INT16_C(  6238),  INT16_C( 11106),  INT16_C( 28167), -INT16_C( 16394) },
      { -INT16_C( 32418),  INT16_C( 17122), -INT16_C(  9299),  INT16_C( 21479) },
      {  INT32_C(   404446968),  INT32_C(   380313864), -INT32_C(   523849866), -INT32_C(   704253452) } },
    { { -INT16_C( 16712),  INT16_C( 24457),  INT16_C( 28627),  INT16_C(  4419) },
      { -INT16_C(  8098),  INT16_C( 24596), -INT16_C(  6217),  INT16_C( 22868) },
      {  INT32_C(   270667552),  INT32_C(  1203088744), -INT32_C(   355948118),  INT32_C(   202107384) } },
    { { -INT16_C( 18737), -INT16_C( 10619),  INT16_C( 31525), -INT16_C( 31851) },
      {  INT16_C( 30716), -INT16_C( 22075), -INT16_C( 21421),  INT16_C(  3069) },
      { -INT32_C(  1151051384),  INT32_C(   468828850), -INT32_C(  1350594050), -INT32_C(   195501438) } },
    { { -INT16_C( 31126),  INT16_C( 15722), -INT16_C( 20747),  INT16_C( 21582) },
      {  INT16_C( 25486),  INT16_C( 17844),  INT16_C(  2122),  INT16_C(  6559) },
      { -INT32_C(  1586554472),  INT32_C(   561086736), -INT32_C(    88050268),  INT32_C(   283112676) } },
    { {  INT16_C(  9407), -INT16_C(  6929), -INT16_C( 31329), -INT16_C( 25753) },
      {  INT16_C( 11516),  INT16_C( 20293),  INT16_C( 17112),  INT16_C( 16987) },
      {  INT32_C(   216662024), -INT32_C(   281220394), -INT32_C(  1072203696), -INT32_C(   874932422) } },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x4_t a = simde_vld1_s16(test_vec[i].a);
    simde_int16x4_t b = simde_vld1_s16(test_vec[i].b);
    simde_int32x4_t r = simde_vqdmull_s16(a, b);

    simde_test_arm_neon_assert_equal_i32x4(r, simde_vld1q_s32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int16x4_t a = simde_test_arm_neon_random_i16x4();
    simde_int16x4_t b = simde_test_arm_neon_random_i16x4();
    simde_int32x4_t r = simde_vqdmull_s16(a, b);

    simde_test_arm_neon_write_i16x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i16x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vqdmull_s32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int32_t a[2];
    int32_t b[2];
    int64_t r[2];
  } test_vec[] = {
    { {  INT32_C(  1793774140),  INT32_C(  2047372376) },
      { -INT32_C(   988507864), -INT32_C(   890762382) },
      { -INT64_C( 3546319687259673920), -INT64_C( 3647444588973519264) } },
    { {  INT32_C(   437091211), -INT32_C(  1030744986) },
      {  INT32_C(  2088454865), -INT32_C(  1587752347) },
      {  INT64_C( 1825690532123383030),  INT64_C( 3273135541359964284) } },
    { { -INT32_C(    66369884), -INT32_C(   613018702) },
      {  INT32_C(   396397476),  INT32_C(   568428694) },
      { -INT64_C(   52617709000025568), -INT64_C(  696914840350870376) } },
    { {  INT32_C(  1782377988), -INT32_C(   735196157) },
      {  INT32_C(  2085660694),  INT32_C(   505261434) },
      {  INT64_C( 7434871422844807344), -INT64_C(  742932529114218276) } },
    { { -INT32_C(  1508234765), -INT32_C(   511602372) },
      { -INT32_C(  1292361444), -INT32_C(  1361782358) },
      {  INT64_C( 3898368917572801320),  INT64_C( 1393382169001106352) } },
    { { -INT32_C(   887615288), -INT32_C(   224442916) },
      {  INT32_C(  1735323885), -INT32_C(  1870295907) },
      { -INT64_C( 3080600019915107760),  INT64_C(  839549334299889624) } },
    { { -INT32_C(   248078155),  INT32_C(  1305655089) },
      { -INT32_C(  2080388391),  INT32_C(  1815204772) },
      {  INT64_C( 1032197827445397210),  INT64_C( 4740062696277769416) } },
    { { -INT32_C(  1086895645),  INT32_C(  2092095119) },
      {  INT32_C(  1675894982),  INT32_C(  1643407788) },
      { -INT64_C( 3643045914826306780),  INT64_C( 6876330823602773544) } },

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x2_t a = simde_vld1_s32(test_vec[i].a);
    simde_int32x2_t b = simde_vld1_s32(test_vec[i].b);
    simde_int64x2_t r = simde_vqdmull_s32(a, b);

    simde_test_arm_neon_assert_equal_i64x2(r, simde_vld1q_s64(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int32x2_t a = simde_test_arm_neon_random_i32x2();
    simde_int32x2_t b = simde_test_arm_neon_random_i32x2();
    simde_int64x2_t r = simde_vqdmull_s32(a, b);

    simde_test_arm_neon_write_i32x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i32x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}


SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(vqdmull_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vqdmull_s32)
SIMDE_TEST_FUNC_LIST_END

#include "test-neon-footer.h"
