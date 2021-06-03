#include "simde/simde-constify.h"
#define SIMDE_TEST_ARM_NEON_INSN mull_lane

#include "test-neon.h"
#include "../../../simde/arm/neon/mull_lane.h"

static int
test_simde_vmull_lane_s16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int16_t a[4];
    int16_t v[4];
    int32_t r[4];
  } test_vec[] = {
    { { -INT16_C( 19302),  INT16_C( 23700),  INT16_C( 20915), -INT16_C( 16468) },
      {  INT16_C( 26981), -INT16_C( 20315),  INT16_C( 27895),  INT16_C( 26979) },
       // INT16_C(     2),
      { -INT32_C(   538429290),  INT32_C(   661111500),  INT32_C(   583423925), -INT32_C(   459374860) } },
    { {  INT16_C(  3588), -INT16_C( 30622),  INT16_C( 22155),  INT16_C( 21540) },
      { -INT16_C( 24576),  INT16_C(  1075), -INT16_C(   729), -INT16_C(  9314) },
       // INT16_C(     1),
      {  INT32_C(     3857100), -INT32_C(    32918650),  INT32_C(    23816625),  INT32_C(    23155500) } },
    { { -INT16_C( 28933), -INT16_C( 22558),  INT16_C( 18510), -INT16_C(  3312) },
      {  INT16_C(  2040),  INT16_C( 23391), -INT16_C( 26256),  INT16_C( 32607) },
       // INT16_C(     3),
      { -INT32_C(   943418331), -INT32_C(   735548706),  INT32_C(   603555570), -INT32_C(   107994384) } },
    { {  INT16_C(  2792),  INT16_C(  3153),  INT16_C( 20830), -INT16_C( 28244) },
      { -INT16_C( 11178), -INT16_C(  2930),  INT16_C(  8111),  INT16_C( 16111) },
       // INT16_C(     2),
      {  INT32_C(    22645912),  INT32_C(    25573983),  INT32_C(   168952130), -INT32_C(   229087084) } },
    { { -INT16_C( 29546), -INT16_C( 22966),  INT16_C( 17023), -INT16_C(  8530) },
      {  INT16_C(  7837), -INT16_C(   649),  INT16_C( 29341), -INT16_C( 22555) },
       // INT16_C(     3),
      {  INT32_C(   666410030),  INT32_C(   517998130), -INT32_C(   383953765),  INT32_C(   192394150) } },
    { {  INT16_C(  1521), -INT16_C( 25324),  INT16_C( 27286),  INT16_C(  9329) },
      {  INT16_C(  8543),  INT16_C( 20036),  INT16_C( 18015), -INT16_C(  5147) },
       // INT16_C(     0),
      {  INT32_C(    12993903), -INT32_C(   216342932),  INT32_C(   233104298),  INT32_C(    79697647) } },
    { {  INT16_C( 27275),  INT16_C( 14802),  INT16_C( 28488), -INT16_C( 16552) },
      { -INT16_C(  2708),  INT16_C( 20785), -INT16_C(  2915), -INT16_C( 23998) },
       // INT16_C(     0),
      { -INT32_C(    73860700), -INT32_C(    40083816), -INT32_C(    77145504),  INT32_C(    44822816) } },
    { {  INT16_C( 14816),  INT16_C( 20851), -INT16_C( 11683), -INT16_C( 24206) },
      { -INT16_C( 12000),  INT16_C(  1511),  INT16_C( 30652),  INT16_C(  9873) },
       // INT16_C(     1),
      {  INT32_C(    22386976),  INT32_C(    31505861), -INT32_C(    17653013), -INT32_C(    36575266) } }
  };

    simde_int16x4_t a, v;
    simde_int32x4_t r;

    a = simde_vld1_s16(test_vec[0].a);
    v = simde_vld1_s16(test_vec[0].v);
    r = simde_vmull_lane_s16(a, v, 2);
    simde_test_arm_neon_assert_equal_i32x4(r, simde_vld1q_s32(test_vec[0].r));

    a = simde_vld1_s16(test_vec[1].a);
    v = simde_vld1_s16(test_vec[1].v);
    r = simde_vmull_lane_s16(a, v, 1);
    simde_test_arm_neon_assert_equal_i32x4(r, simde_vld1q_s32(test_vec[1].r));

    a = simde_vld1_s16(test_vec[2].a);
    v = simde_vld1_s16(test_vec[2].v);
    r = simde_vmull_lane_s16(a, v, 3);
    simde_test_arm_neon_assert_equal_i32x4(r, simde_vld1q_s32(test_vec[2].r));

    a = simde_vld1_s16(test_vec[3].a);
    v = simde_vld1_s16(test_vec[3].v);
    r = simde_vmull_lane_s16(a, v, 2);
    simde_test_arm_neon_assert_equal_i32x4(r, simde_vld1q_s32(test_vec[3].r));

    a = simde_vld1_s16(test_vec[4].a);
    v = simde_vld1_s16(test_vec[4].v);
    r = simde_vmull_lane_s16(a, v, 3);
    simde_test_arm_neon_assert_equal_i32x4(r, simde_vld1q_s32(test_vec[4].r));

    a = simde_vld1_s16(test_vec[5].a);
    v = simde_vld1_s16(test_vec[5].v);
    r = simde_vmull_lane_s16(a, v, 0);
    simde_test_arm_neon_assert_equal_i32x4(r, simde_vld1q_s32(test_vec[5].r));

    a = simde_vld1_s16(test_vec[6].a);
    v = simde_vld1_s16(test_vec[6].v);
    r = simde_vmull_lane_s16(a, v, 0);
    simde_test_arm_neon_assert_equal_i32x4(r, simde_vld1q_s32(test_vec[6].r));

    a = simde_vld1_s16(test_vec[7].a);
    v = simde_vld1_s16(test_vec[7].v);
    r = simde_vmull_lane_s16(a, v, 1);
    simde_test_arm_neon_assert_equal_i32x4(r, simde_vld1q_s32(test_vec[7].r));

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int16x4_t a = simde_test_arm_neon_random_i16x4();
    simde_int16x4_t v = simde_test_arm_neon_random_i16x4();
    int8_t lane = simde_test_codegen_random_i8() & 3;
    simde_int32x4_t r;

    SIMDE_CONSTIFY_4_(simde_vmull_lane_s16, r, (HEDLEY_UNREACHABLE(), simde_vdupq_n_s32(0)), lane, a, v);

    simde_test_arm_neon_write_i16x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i16x4(2, v, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i16(2, lane, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vmull_lane_s32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int32_t a[2];
    int32_t v[2];
    int64_t r[2];
  } test_vec[] = {
    { { -INT32_C(  1723491516),  INT32_C(  1860950372) },
      { -INT32_C(  1972860455), -INT32_C(   187256664) },
       // INT32_C(           0),
      {  INT64_C( 3400208256444399780), -INT64_C( 3671395397636339260) } },
    { {  INT32_C(  1662070563),  INT32_C(  2044653177) },
      {  INT32_C(  1119092714),  INT32_C(  2122816739) },
       // INT32_C(           1),
      {  INT64_C( 3528271212535554057),  INT64_C( 4340423989585129803) } },
    { {  INT32_C(   196796960), -INT32_C(  1198222256) },
      { -INT32_C(   177652450),  INT32_C(  1612250929) },
       // INT32_C(           1),
      {  INT64_C(  317286081584375840), -INT64_C( 1931834945384475824) } },
    { {  INT32_C(  1509939579),  INT32_C(   106490450) },
      { -INT32_C(  1281213652), -INT32_C(  1680571207) },
       // INT32_C(           0),
      { -INT64_C( 1934555202309932508), -INT64_C(  136437018347623400) } },
    { {  INT32_C(  1959979999),  INT32_C(   229765540) },
      { -INT32_C(    32709914),  INT32_C(   460922178) },
       // INT32_C(           1),
      {  INT64_C(  903398249975517822),  INT64_C(  105904033126146120) } },
    { {  INT32_C(   721907411),  INT32_C(   375862132) },
      { -INT32_C(  1147526937), -INT32_C(  1483023940) },
       // INT32_C(           1),
      { -INT64_C( 1070605972976419340), -INT64_C(  557412539895440080) } },
    { { -INT32_C(  1080276210),  INT32_C(  1705083480) },
      { -INT32_C(    92085376),  INT32_C(  1842192383) },
       // INT32_C(           0),
      {  INT64_C(   99477640981704960), -INT64_C(  157013253367188480) } },
    { {  INT32_C(  1608180216), -INT32_C(  1837055497) },
      {  INT32_C(   376126588),  INT32_C(   790959843) },
       // INT32_C(           1),
      {  INT64_C( 1272005971163066088), -INT64_C( 1453037127489406971) } }
  };

    simde_int32x2_t a, v;
    simde_int64x2_t r;

    a = simde_vld1_s32(test_vec[0].a);
    v = simde_vld1_s32(test_vec[0].v);
    r = simde_vmull_lane_s32(a, v, 0);
    simde_test_arm_neon_assert_equal_i64x2(r, simde_vld1q_s64(test_vec[0].r));

    a = simde_vld1_s32(test_vec[1].a);
    v = simde_vld1_s32(test_vec[1].v);
    r = simde_vmull_lane_s32(a, v, 1);
    simde_test_arm_neon_assert_equal_i64x2(r, simde_vld1q_s64(test_vec[1].r));

    a = simde_vld1_s32(test_vec[2].a);
    v = simde_vld1_s32(test_vec[2].v);
    r = simde_vmull_lane_s32(a, v, 1);
    simde_test_arm_neon_assert_equal_i64x2(r, simde_vld1q_s64(test_vec[2].r));

    a = simde_vld1_s32(test_vec[3].a);
    v = simde_vld1_s32(test_vec[3].v);
    r = simde_vmull_lane_s32(a, v, 0);
    simde_test_arm_neon_assert_equal_i64x2(r, simde_vld1q_s64(test_vec[3].r));

    a = simde_vld1_s32(test_vec[4].a);
    v = simde_vld1_s32(test_vec[4].v);
    r = simde_vmull_lane_s32(a, v, 1);
    simde_test_arm_neon_assert_equal_i64x2(r, simde_vld1q_s64(test_vec[4].r));

    a = simde_vld1_s32(test_vec[5].a);
    v = simde_vld1_s32(test_vec[5].v);
    r = simde_vmull_lane_s32(a, v, 1);
    simde_test_arm_neon_assert_equal_i64x2(r, simde_vld1q_s64(test_vec[5].r));

    a = simde_vld1_s32(test_vec[6].a);
    v = simde_vld1_s32(test_vec[6].v);
    r = simde_vmull_lane_s32(a, v, 0);
    simde_test_arm_neon_assert_equal_i64x2(r, simde_vld1q_s64(test_vec[6].r));

    a = simde_vld1_s32(test_vec[7].a);
    v = simde_vld1_s32(test_vec[7].v);
    r = simde_vmull_lane_s32(a, v, 1);
    simde_test_arm_neon_assert_equal_i64x2(r, simde_vld1q_s64(test_vec[7].r));

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int32x2_t a = simde_test_arm_neon_random_i32x2();
    simde_int32x2_t v = simde_test_arm_neon_random_i32x2();
    int8_t lane = simde_test_codegen_random_i8() & 1;
    simde_int64x2_t r;

    SIMDE_CONSTIFY_2_(simde_vmull_lane_s32, r, (HEDLEY_UNREACHABLE(), simde_vdupq_n_s64(0)), lane, a, v);

    simde_test_arm_neon_write_i32x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i32x2(2, v, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, lane, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vmull_lane_u16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint16_t a[4];
    uint16_t v[4];
    uint32_t r[4];
  } test_vec[] = {
    { { UINT16_C(34788), UINT16_C(34357), UINT16_C(46828), UINT16_C(28521) },
      { UINT16_C(26800), UINT16_C(32014), UINT16_C(46549), UINT16_C(46709) },
       // INT32_C(           3),
      { UINT32_C(1624912692), UINT32_C(1604781113), UINT32_C(2187289052), UINT32_C(1332187389) } },
    { { UINT16_C(44757), UINT16_C(21840), UINT16_C(52288), UINT16_C(43921) },
      { UINT16_C(29922), UINT16_C( 1985), UINT16_C(29859), UINT16_C(11244) },
       // INT32_C(           2),
      { UINT32_C(1336399263), UINT32_C( 652120560), UINT32_C(1561267392), UINT32_C(1311437139) } },
    { { UINT16_C( 6002), UINT16_C(56160), UINT16_C( 4230), UINT16_C(38212) },
      { UINT16_C( 6541), UINT16_C(  586), UINT16_C(55760), UINT16_C(32471) },
       // INT32_C(           1),
      { UINT32_C(   3517172), UINT32_C(  32909760), UINT32_C(   2478780), UINT32_C(  22392232) } },
    { { UINT16_C(48684), UINT16_C(48629), UINT16_C(55145), UINT16_C(10802) },
      { UINT16_C(54751), UINT16_C(52127), UINT16_C(18688), UINT16_C( 6205) },
       // INT32_C(           1),
      { UINT32_C(2537750868), UINT32_C(2534883883), UINT32_C(2874543415), UINT32_C( 563075854) } },
    { { UINT16_C(40472), UINT16_C(23737), UINT16_C(17971), UINT16_C(32118) },
      { UINT16_C(17992), UINT16_C( 8278), UINT16_C(32708), UINT16_C(33356) },
       // INT32_C(           0),
      { UINT32_C( 728172224), UINT32_C( 427076104), UINT32_C( 323334232), UINT32_C( 577867056) } },
    { { UINT16_C(60170), UINT16_C(15436), UINT16_C(11029), UINT16_C(46097) },
      { UINT16_C( 4854), UINT16_C(13309), UINT16_C(42538), UINT16_C(51275) },
       // INT32_C(           3),
      { UINT32_C(3085216750), UINT32_C( 791480900), UINT32_C( 565511975), UINT32_C(2363623675) } },
    { { UINT16_C(64680), UINT16_C( 7845), UINT16_C(61049), UINT16_C(53348) },
      { UINT16_C(10254), UINT16_C(23119), UINT16_C(50346), UINT16_C(38244) },
       // INT32_C(           0),
      { UINT32_C( 663228720), UINT32_C(  80442630), UINT32_C( 625996446), UINT32_C( 547030392) } },
    { { UINT16_C(43680), UINT16_C(45627), UINT16_C(12639), UINT16_C(23748) },
      { UINT16_C(61028), UINT16_C(44803), UINT16_C(25270), UINT16_C(45655) },
       // INT32_C(           0),
      { UINT32_C(2665703040), UINT32_C(2784524556), UINT32_C( 771332892), UINT32_C(1449292944) } }
  };

    simde_uint16x4_t a, v;
    simde_uint32x4_t r;

    a = simde_vld1_u16(test_vec[0].a);
    v = simde_vld1_u16(test_vec[0].v);
    r = simde_vmull_lane_u16(a, v, 3);
    simde_test_arm_neon_assert_equal_u32x4(r, simde_vld1q_u32(test_vec[0].r));

    a = simde_vld1_u16(test_vec[1].a);
    v = simde_vld1_u16(test_vec[1].v);
    r = simde_vmull_lane_u16(a, v, 2);
    simde_test_arm_neon_assert_equal_u32x4(r, simde_vld1q_u32(test_vec[1].r));

    a = simde_vld1_u16(test_vec[2].a);
    v = simde_vld1_u16(test_vec[2].v);
    r = simde_vmull_lane_u16(a, v, 1);
    simde_test_arm_neon_assert_equal_u32x4(r, simde_vld1q_u32(test_vec[2].r));

    a = simde_vld1_u16(test_vec[3].a);
    v = simde_vld1_u16(test_vec[3].v);
    r = simde_vmull_lane_u16(a, v, 1);
    simde_test_arm_neon_assert_equal_u32x4(r, simde_vld1q_u32(test_vec[3].r));

    a = simde_vld1_u16(test_vec[4].a);
    v = simde_vld1_u16(test_vec[4].v);
    r = simde_vmull_lane_u16(a, v, 0);
    simde_test_arm_neon_assert_equal_u32x4(r, simde_vld1q_u32(test_vec[4].r));

    a = simde_vld1_u16(test_vec[5].a);
    v = simde_vld1_u16(test_vec[5].v);
    r = simde_vmull_lane_u16(a, v, 3);
    simde_test_arm_neon_assert_equal_u32x4(r, simde_vld1q_u32(test_vec[5].r));

    a = simde_vld1_u16(test_vec[6].a);
    v = simde_vld1_u16(test_vec[6].v);
    r = simde_vmull_lane_u16(a, v, 0);
    simde_test_arm_neon_assert_equal_u32x4(r, simde_vld1q_u32(test_vec[6].r));

    a = simde_vld1_u16(test_vec[7].a);
    v = simde_vld1_u16(test_vec[7].v);
    r = simde_vmull_lane_u16(a, v, 0);
    simde_test_arm_neon_assert_equal_u32x4(r, simde_vld1q_u32(test_vec[7].r));

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint16x4_t a = simde_test_arm_neon_random_u16x4();
    simde_uint16x4_t v = simde_test_arm_neon_random_u16x4();
    uint8_t lane = simde_test_codegen_random_u8() & 3;
    simde_uint32x4_t r;

    SIMDE_CONSTIFY_4_(simde_vmull_lane_u16, r, (HEDLEY_UNREACHABLE(), simde_vdupq_n_u32(0)), lane, a, v);

    simde_test_arm_neon_write_u16x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u16x4(2, v, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, lane, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vmull_lane_u32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint32_t a[2];
    uint32_t v[2];
    uint64_t r[2];
  } test_vec[] = {
    { { UINT32_C(3656789109), UINT32_C(1258358012) },
      { UINT32_C(3272584030), UINT32_C(3949141824) },
       // INT32_C(           0),
      { UINT64_C(11967149639191329270), UINT64_C( 4118082334093748360) } },
    { { UINT32_C(3649784341), UINT32_C(2848452518) },
      { UINT32_C(4128013983), UINT32_C(1550586928) },
       // INT32_C(           0),
      { UINT64_C(15066360794582440203), UINT64_C(11758451824215559194) } },
    { { UINT32_C(1192122437), UINT32_C(3019009188) },
      { UINT32_C(2480091951), UINT32_C(1755852062) },
       // INT32_C(           1),
      { UINT64_C( 2093190639162915094), UINT64_C( 5300933507946745656) } },
    { { UINT32_C(1235750530), UINT32_C(3301394360) },
      { UINT32_C(2866346046), UINT32_C(2918179412) },
       // INT32_C(           0),
      { UINT64_C( 3542088645507904380), UINT64_C( 9462938670072700560) } },
    { { UINT32_C( 693915958), UINT32_C(3613166596) },
      { UINT32_C(3339024927), UINT32_C(4031364834) },
       // INT32_C(           0),
      { UINT64_C( 2317002681005085066), UINT64_C(12064453329447738492) } },
    { { UINT32_C(1521395859), UINT32_C(1146285164) },
      { UINT32_C(2233902998), UINT32_C(2780567124) },
       // INT32_C(           1),
      { UINT64_C( 4230343308125139516), UINT64_C( 3187322841747348336) } },
    { { UINT32_C(1107274213), UINT32_C(2260409985) },
      { UINT32_C( 793026021), UINT32_C( 918727309) },
       // INT32_C(           0),
      { UINT64_C(  878097263291296473), UINT64_C( 1792563936233219685) } },
    { { UINT32_C(1866768924), UINT32_C( 219601639) },
      { UINT32_C( 472148576), UINT32_C(3087111951) },
       // INT32_C(           0),
      { UINT64_C(  881392289187652224), UINT64_C(  103684601141116064) } }
  };

    simde_uint32x2_t a, v;
    simde_uint64x2_t r;

    a = simde_vld1_u32(test_vec[0].a);
    v = simde_vld1_u32(test_vec[0].v);
    r = simde_vmull_lane_u32(a, v, 0);
    simde_test_arm_neon_assert_equal_u64x2(r, simde_vld1q_u64(test_vec[0].r));

    a = simde_vld1_u32(test_vec[1].a);
    v = simde_vld1_u32(test_vec[1].v);
    r = simde_vmull_lane_u32(a, v, 0);
    simde_test_arm_neon_assert_equal_u64x2(r, simde_vld1q_u64(test_vec[1].r));

    a = simde_vld1_u32(test_vec[2].a);
    v = simde_vld1_u32(test_vec[2].v);
    r = simde_vmull_lane_u32(a, v, 1);
    simde_test_arm_neon_assert_equal_u64x2(r, simde_vld1q_u64(test_vec[2].r));

    a = simde_vld1_u32(test_vec[3].a);
    v = simde_vld1_u32(test_vec[3].v);
    r = simde_vmull_lane_u32(a, v, 0);
    simde_test_arm_neon_assert_equal_u64x2(r, simde_vld1q_u64(test_vec[3].r));

    a = simde_vld1_u32(test_vec[4].a);
    v = simde_vld1_u32(test_vec[4].v);
    r = simde_vmull_lane_u32(a, v, 0);
    simde_test_arm_neon_assert_equal_u64x2(r, simde_vld1q_u64(test_vec[4].r));

    a = simde_vld1_u32(test_vec[5].a);
    v = simde_vld1_u32(test_vec[5].v);
    r = simde_vmull_lane_u32(a, v, 1);
    simde_test_arm_neon_assert_equal_u64x2(r, simde_vld1q_u64(test_vec[5].r));

    a = simde_vld1_u32(test_vec[6].a);
    v = simde_vld1_u32(test_vec[6].v);
    r = simde_vmull_lane_u32(a, v, 0);
    simde_test_arm_neon_assert_equal_u64x2(r, simde_vld1q_u64(test_vec[6].r));

    a = simde_vld1_u32(test_vec[7].a);
    v = simde_vld1_u32(test_vec[7].v);
    r = simde_vmull_lane_u32(a, v, 0);
    simde_test_arm_neon_assert_equal_u64x2(r, simde_vld1q_u64(test_vec[7].r));

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint32x2_t a = simde_test_arm_neon_random_u32x2();
    simde_uint32x2_t v = simde_test_arm_neon_random_u32x2();
    uint8_t lane = simde_test_codegen_random_u8() & 1;
    simde_uint64x2_t r;

    SIMDE_CONSTIFY_2_(simde_vmull_lane_u32, r, (HEDLEY_UNREACHABLE(), simde_vdupq_n_u64(0)), lane, a, v);

    simde_test_arm_neon_write_u32x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u32x2(2, v, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, lane, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vmull_laneq_s16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int16_t a[4];
    int16_t v[8];
    int32_t r[4];
  } test_vec[] = {
    { { -INT16_C( 30879), -INT16_C(  3119), -INT16_C( 16871),  INT16_C( 22089) },
      { -INT16_C(  4460), -INT16_C( 23607), -INT16_C(  7282), -INT16_C(  8599), -INT16_C(  7250), -INT16_C( 12724),  INT16_C( 29358),  INT16_C( 31299) },
       // INT32_C(           0),
      {  INT32_C(   137720340),  INT32_C(    13910740),  INT32_C(    75244660), -INT32_C(    98516940) } },
    { { -INT16_C( 30247),  INT16_C(  6013), -INT16_C(  8993),  INT16_C( 26232) },
      {  INT16_C( 27565),  INT16_C( 27519), -INT16_C( 10827), -INT16_C( 23808), -INT16_C( 23650), -INT16_C( 32463),  INT16_C(  3852), -INT16_C(  4049) },
       // INT32_C(           3),
      {  INT32_C(   720120576), -INT32_C(   143157504),  INT32_C(   214105344), -INT32_C(   624531456) } },
    { { -INT16_C( 24834),  INT16_C( 16845), -INT16_C( 23272), -INT16_C( 24294) },
      {  INT16_C( 12579), -INT16_C(   128), -INT16_C(  6487),  INT16_C(  5548),  INT16_C(  6245),  INT16_C( 15050),  INT16_C( 27928), -INT16_C( 17448) },
       // INT32_C(           6),
      { -INT32_C(   693563952),  INT32_C(   470447160), -INT32_C(   649940416), -INT32_C(   678482832) } },
    { { -INT16_C( 14503), -INT16_C( 30547),  INT16_C(  2231),  INT16_C( 21894) },
      { -INT16_C( 14379),  INT16_C( 31341),  INT16_C(  3810),  INT16_C(  5021), -INT16_C( 25458),  INT16_C( 29885), -INT16_C( 11703),  INT16_C( 25049) },
       // INT32_C(           4),
      {  INT32_C(   369217374),  INT32_C(   777665526), -INT32_C(    56796798), -INT32_C(   557377452) } },
    { {  INT16_C( 30995), -INT16_C(  5367), -INT16_C( 22732), -INT16_C(  1212) },
      { -INT16_C( 12972),  INT16_C( 23731),  INT16_C(  2131),  INT16_C(  6961), -INT16_C( 21642), -INT16_C( 31491),  INT16_C(  4169), -INT16_C(  6893) },
       // INT32_C(           5),
      { -INT32_C(   976063545),  INT32_C(   169012197),  INT32_C(   715853412),  INT32_C(    38167092) } },
    { {  INT16_C( 11911),  INT16_C( 24991),  INT16_C( 15247),  INT16_C(  2164) },
      {  INT16_C( 24644), -INT16_C(  5316),  INT16_C( 14500),  INT16_C( 28991), -INT16_C( 25621), -INT16_C(  3131), -INT16_C(  7988),  INT16_C( 30825) },
       // INT32_C(           5),
      { -INT32_C(    37293341), -INT32_C(    78246821), -INT32_C(    47738357), -INT32_C(     6775484) } },
    { { -INT16_C( 15890),  INT16_C(   493), -INT16_C( 17498), -INT16_C( 10872) },
      { -INT16_C(  5798), -INT16_C( 27036),  INT16_C( 27998), -INT16_C( 16678), -INT16_C( 14679), -INT16_C(  7838), -INT16_C( 11259), -INT16_C( 24116) },
       // INT32_C(           1),
      {  INT32_C(   429602040), -INT32_C(    13328748),  INT32_C(   473075928),  INT32_C(   293935392) } },
    { {  INT16_C( 28096),  INT16_C( 10617),  INT16_C( 22245), -INT16_C( 23017) },
      {  INT16_C(  6211), -INT16_C(   435),  INT16_C(  8865), -INT16_C( 30119), -INT16_C(  4218), -INT16_C(  3096), -INT16_C( 22839), -INT16_C( 28771) },
       // INT32_C(           1),
      { -INT32_C(    12221760), -INT32_C(     4618395), -INT32_C(     9676575),  INT32_C(    10012395) } }
  };

  simde_int16x4_t a;
  simde_int16x8_t v;
  simde_int32x4_t r;

  a = simde_vld1_s16(test_vec[0].a);
  v = simde_vld1q_s16(test_vec[0].v);
  r = simde_vmull_laneq_s16(a, v, 0);
  simde_test_arm_neon_assert_equal_i32x4(r, simde_vld1q_s32(test_vec[0].r));

  a = simde_vld1_s16(test_vec[1].a);
  v = simde_vld1q_s16(test_vec[1].v);
  r = simde_vmull_laneq_s16(a, v, 3);
  simde_test_arm_neon_assert_equal_i32x4(r, simde_vld1q_s32(test_vec[1].r));

  a = simde_vld1_s16(test_vec[2].a);
  v = simde_vld1q_s16(test_vec[2].v);
  r = simde_vmull_laneq_s16(a, v, 6);
  simde_test_arm_neon_assert_equal_i32x4(r, simde_vld1q_s32(test_vec[2].r));

  a = simde_vld1_s16(test_vec[3].a);
  v = simde_vld1q_s16(test_vec[3].v);
  r = simde_vmull_laneq_s16(a, v, 4);
  simde_test_arm_neon_assert_equal_i32x4(r, simde_vld1q_s32(test_vec[3].r));

  a = simde_vld1_s16(test_vec[4].a);
  v = simde_vld1q_s16(test_vec[4].v);
  r = simde_vmull_laneq_s16(a, v, 5);
  simde_test_arm_neon_assert_equal_i32x4(r, simde_vld1q_s32(test_vec[4].r));

  a = simde_vld1_s16(test_vec[5].a);
  v = simde_vld1q_s16(test_vec[5].v);
  r = simde_vmull_laneq_s16(a, v, 5);
  simde_test_arm_neon_assert_equal_i32x4(r, simde_vld1q_s32(test_vec[5].r));

  a = simde_vld1_s16(test_vec[6].a);
  v = simde_vld1q_s16(test_vec[6].v);
  r = simde_vmull_laneq_s16(a, v, 1);
  simde_test_arm_neon_assert_equal_i32x4(r, simde_vld1q_s32(test_vec[6].r));

  a = simde_vld1_s16(test_vec[7].a);
  v = simde_vld1q_s16(test_vec[7].v);
  r = simde_vmull_laneq_s16(a, v, 1);
  simde_test_arm_neon_assert_equal_i32x4(r, simde_vld1q_s32(test_vec[7].r));

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int16x4_t a = simde_test_arm_neon_random_i16x4();
    simde_int16x8_t v = simde_test_arm_neon_random_i16x8();
    int8_t lane = simde_test_codegen_random_i8() & 7;
    simde_int32x4_t r;

    SIMDE_CONSTIFY_8_(simde_vmull_laneq_s16, r, (HEDLEY_UNREACHABLE(), simde_vdupq_n_s32(0)), lane, a, v);

    simde_test_arm_neon_write_i16x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i16x8(2, v, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, lane, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vmull_laneq_s32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int32_t a[2];
    int32_t v[4];
    int64_t r[2];
  } test_vec[] = {
    { {  INT32_C(  1272812926), -INT32_C(  1559529930) },
      {  INT32_C(  1166619887),  INT32_C(  1686646604), -INT32_C(  1643804804), -INT32_C(   819621664) },
       // INT32_C(           0),
      {  INT64_C( 1484888871902259362), -INT64_C( 1819378630709717910) } },
    { { -INT32_C(  1256220648), -INT32_C(  1120655320) },
      {  INT32_C(  2079555333), -INT32_C(  1100310902),  INT32_C(  1326100255), -INT32_C(  1093963977) },
       // INT32_C(           0),
      { -INT64_C( 2612380347973115784), -INT64_C( 2330464747160821560) } },
    { { -INT32_C(  1895522710),  INT32_C(   111639917) },
      { -INT32_C(  1003594340),  INT32_C(   281668497),  INT32_C(  1956267230),  INT32_C(  1570003118) },
       // INT32_C(           3),
      { -INT64_C( 2975976564939809780),  INT64_C(  175275017783261206) } },
    { { -INT32_C(  1361931037), -INT32_C(   250067373) },
      { -INT32_C(   933255349), -INT32_C(  1402706609),  INT32_C(  2117937299),  INT32_C(   895241713) },
       // INT32_C(           3),
      { -INT64_C( 1219257474551746381), -INT64_C(  223870743369929949) } },
    { {  INT32_C(  1681908688), -INT32_C(   733502912) },
      { -INT32_C(  1155008908), -INT32_C(  1241114354), -INT32_C(   586822024),  INT32_C(  1517334834) },
       // INT32_C(           2),
      { -INT64_C(  986981060475344512),  INT64_C(  430435663429733888) } },
    { {  INT32_C(  1245400046),  INT32_C(  1662657152) },
      {  INT32_C(    77823841), -INT32_C(  1132955706), -INT32_C(  1194642529),  INT32_C(   120619321) },
       // INT32_C(           2),
      { -INT64_C( 1487807860570156334), -INT64_C( 1986280944925217408) } },
    { {  INT32_C(  2100771085), -INT32_C(   563403373) },
      { -INT32_C(  2107722400),  INT32_C(  1323549135), -INT32_C(   602544284), -INT32_C(  1820602016) },
       // INT32_C(           0),
      { -INT64_C( 4427842273126804000),  INT64_C( 1187497909507655200) } },
    { {  INT32_C(  1662897459),  INT32_C(   242262996) },
      { -INT32_C(     6165030),  INT32_C(   224362584), -INT32_C(  1596136994), -INT32_C(  1409012795) },
       // INT32_C(           0),
      { -INT64_C(   10251812721658770), -INT64_C(    1493558638229880) } }
  };

    simde_int32x2_t a;
    simde_int32x4_t v;
    simde_int64x2_t r;

    a = simde_vld1_s32(test_vec[0].a);
    v = simde_vld1q_s32(test_vec[0].v);
    r = simde_vmull_laneq_s32(a, v, 0);
    simde_test_arm_neon_assert_equal_i64x2(r, simde_vld1q_s64(test_vec[0].r));

    a = simde_vld1_s32(test_vec[1].a);
    v = simde_vld1q_s32(test_vec[1].v);
    r = simde_vmull_laneq_s32(a, v, 0);
    simde_test_arm_neon_assert_equal_i64x2(r, simde_vld1q_s64(test_vec[1].r));

    a = simde_vld1_s32(test_vec[2].a);
    v = simde_vld1q_s32(test_vec[2].v);
    r = simde_vmull_laneq_s32(a, v, 3);
    simde_test_arm_neon_assert_equal_i64x2(r, simde_vld1q_s64(test_vec[2].r));

    a = simde_vld1_s32(test_vec[3].a);
    v = simde_vld1q_s32(test_vec[3].v);
    r = simde_vmull_laneq_s32(a, v, 3);
    simde_test_arm_neon_assert_equal_i64x2(r, simde_vld1q_s64(test_vec[3].r));

    a = simde_vld1_s32(test_vec[4].a);
    v = simde_vld1q_s32(test_vec[4].v);
    r = simde_vmull_laneq_s32(a, v, 2);
    simde_test_arm_neon_assert_equal_i64x2(r, simde_vld1q_s64(test_vec[4].r));

    a = simde_vld1_s32(test_vec[5].a);
    v = simde_vld1q_s32(test_vec[5].v);
    r = simde_vmull_laneq_s32(a, v, 2);
    simde_test_arm_neon_assert_equal_i64x2(r, simde_vld1q_s64(test_vec[5].r));

    a = simde_vld1_s32(test_vec[6].a);
    v = simde_vld1q_s32(test_vec[6].v);
    r = simde_vmull_laneq_s32(a, v, 0);
    simde_test_arm_neon_assert_equal_i64x2(r, simde_vld1q_s64(test_vec[6].r));

    a = simde_vld1_s32(test_vec[7].a);
    v = simde_vld1q_s32(test_vec[7].v);
    r = simde_vmull_laneq_s32(a, v, 0);
    simde_test_arm_neon_assert_equal_i64x2(r, simde_vld1q_s64(test_vec[7].r));

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int32x2_t a = simde_test_arm_neon_random_i32x2();
    simde_int32x4_t v = simde_test_arm_neon_random_i32x4();
    int8_t lane = simde_test_codegen_random_i8() & 3;
    simde_int64x2_t r;

    SIMDE_CONSTIFY_4_(simde_vmull_laneq_s32, r, (HEDLEY_UNREACHABLE(), simde_vdupq_n_s64(0)), lane, a, v);

    simde_test_arm_neon_write_i32x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i32x4(2, v, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, lane, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vmull_laneq_u16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint16_t a[4];
    uint16_t v[8];
    uint32_t r[4];
  } test_vec[] = {
    { { UINT16_C( 3296), UINT16_C(23313), UINT16_C(44704), UINT16_C(28046) },
      { UINT16_C(61899), UINT16_C(28481), UINT16_C(20321), UINT16_C(20041), UINT16_C(18929), UINT16_C(29094), UINT16_C(45992), UINT16_C(35407) },
       // INT32_C(           0),
      { UINT32_C( 204019104), UINT32_C(1443051387), UINT32_C(2767132896), UINT32_C(1736019354) } },
    { { UINT16_C(20463), UINT16_C(62651), UINT16_C(64507), UINT16_C( 2260) },
      { UINT16_C(12300), UINT16_C(47784), UINT16_C( 5566), UINT16_C(45190), UINT16_C(62806), UINT16_C(42513), UINT16_C(24638), UINT16_C(34711) },
       // INT32_C(           6),
      { UINT32_C( 504167394), UINT32_C(1543595338), UINT32_C(1589323466), UINT32_C(  55681880) } },
    { { UINT16_C(12296), UINT16_C(22458), UINT16_C(19130), UINT16_C( 2375) },
      { UINT16_C(15109), UINT16_C(    4), UINT16_C( 3087), UINT16_C(16140), UINT16_C(51124), UINT16_C(51710), UINT16_C(44621), UINT16_C(16928) },
       // INT32_C(           7),
      { UINT32_C( 208146688), UINT32_C( 380169024), UINT32_C( 323832640), UINT32_C(  40204000) } },
    { { UINT16_C(32966), UINT16_C(23839), UINT16_C( 9736), UINT16_C(14437) },
      { UINT16_C(48352), UINT16_C(10994), UINT16_C(64259), UINT16_C(15919), UINT16_C(12287), UINT16_C( 3150), UINT16_C(36155), UINT16_C(  704) },
       // INT32_C(           3),
      { UINT32_C( 524785754), UINT32_C( 379493041), UINT32_C( 154987384), UINT32_C( 229822603) } },
    { { UINT16_C(20362), UINT16_C(43577), UINT16_C(63889), UINT16_C( 4720) },
      { UINT16_C(52504), UINT16_C(15898), UINT16_C(21042), UINT16_C(60958), UINT16_C(18500), UINT16_C(16370), UINT16_C(12407), UINT16_C(42558) },
       // INT32_C(           6),
      { UINT32_C( 252631334), UINT32_C( 540659839), UINT32_C( 792670823), UINT32_C(  58561040) } },
    { { UINT16_C(57930), UINT16_C( 2828), UINT16_C(38884), UINT16_C(13461) },
      { UINT16_C(16337), UINT16_C(51909), UINT16_C(55215), UINT16_C(31970), UINT16_C( 8689), UINT16_C(17326), UINT16_C(39999), UINT16_C(34951) },
       // INT32_C(           6),
      { UINT32_C(2317142070), UINT32_C( 113117172), UINT32_C(1555321116), UINT32_C( 538426539) } },
    { { UINT16_C(65478), UINT16_C( 1471), UINT16_C(15782), UINT16_C(34895) },
      { UINT16_C(23113), UINT16_C(57708), UINT16_C(41199), UINT16_C(11954), UINT16_C(31846), UINT16_C(15837), UINT16_C(22878), UINT16_C(32559) },
       // INT32_C(           7),
      { UINT32_C(2131898202), UINT32_C(  47894289), UINT32_C( 513846138), UINT32_C(1136146305) } },
    { { UINT16_C(49010), UINT16_C(64164), UINT16_C(12871), UINT16_C(18112) },
      { UINT16_C(50673), UINT16_C(12268), UINT16_C(29717), UINT16_C(28536), UINT16_C(23009), UINT16_C(33119), UINT16_C(36107), UINT16_C(34791) },
       // INT32_C(           3),
      { UINT32_C(1398549360), UINT32_C(1830983904), UINT32_C( 367286856), UINT32_C( 516844032) } }
  };

    simde_uint16x4_t a;
    simde_uint16x8_t v;
    simde_uint32x4_t r;

    a = simde_vld1_u16(test_vec[0].a);
    v = simde_vld1q_u16(test_vec[0].v);
    r = simde_vmull_laneq_u16(a, v, 0);
    simde_test_arm_neon_assert_equal_u32x4(r, simde_vld1q_u32(test_vec[0].r));

    a = simde_vld1_u16(test_vec[1].a);
    v = simde_vld1q_u16(test_vec[1].v);
    r = simde_vmull_laneq_u16(a, v, 6);
    simde_test_arm_neon_assert_equal_u32x4(r, simde_vld1q_u32(test_vec[1].r));

    a = simde_vld1_u16(test_vec[2].a);
    v = simde_vld1q_u16(test_vec[2].v);
    r = simde_vmull_laneq_u16(a, v, 7);
    simde_test_arm_neon_assert_equal_u32x4(r, simde_vld1q_u32(test_vec[2].r));

    a = simde_vld1_u16(test_vec[3].a);
    v = simde_vld1q_u16(test_vec[3].v);
    r = simde_vmull_laneq_u16(a, v, 3);
    simde_test_arm_neon_assert_equal_u32x4(r, simde_vld1q_u32(test_vec[3].r));

    a = simde_vld1_u16(test_vec[4].a);
    v = simde_vld1q_u16(test_vec[4].v);
    r = simde_vmull_laneq_u16(a, v, 6);
    simde_test_arm_neon_assert_equal_u32x4(r, simde_vld1q_u32(test_vec[4].r));

    a = simde_vld1_u16(test_vec[5].a);
    v = simde_vld1q_u16(test_vec[5].v);
    r = simde_vmull_laneq_u16(a, v, 6);
    simde_test_arm_neon_assert_equal_u32x4(r, simde_vld1q_u32(test_vec[5].r));

    a = simde_vld1_u16(test_vec[6].a);
    v = simde_vld1q_u16(test_vec[6].v);
    r = simde_vmull_laneq_u16(a, v, 7);
    simde_test_arm_neon_assert_equal_u32x4(r, simde_vld1q_u32(test_vec[6].r));

    a = simde_vld1_u16(test_vec[7].a);
    v = simde_vld1q_u16(test_vec[7].v);
    r = simde_vmull_laneq_u16(a, v, 3);
    simde_test_arm_neon_assert_equal_u32x4(r, simde_vld1q_u32(test_vec[7].r));

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint16x4_t a = simde_test_arm_neon_random_u16x4();
    simde_uint16x8_t v = simde_test_arm_neon_random_u16x8();
    uint8_t lane = simde_test_codegen_random_u8() & 7;
    simde_uint32x4_t r;

    SIMDE_CONSTIFY_8_(simde_vmull_laneq_u16, r, (HEDLEY_UNREACHABLE(), simde_vdupq_n_u32(0)), lane, a, v);

    simde_test_arm_neon_write_u16x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u16x8(2, v, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, lane, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vmull_laneq_u32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint32_t a[2];
    uint32_t v[4];
    uint64_t r[2];
  } test_vec[] = {
    { { UINT32_C(1422190117), UINT32_C( 617008229) },
      { UINT32_C(2724970608), UINT32_C(1184150145), UINT32_C( 324780958), UINT32_C(2515847995) },
       // INT32_C(           2),
      { UINT64_C(  461900268657392086), UINT64_C(  200392523708503382) } },
    { { UINT32_C(1572315253), UINT32_C( 243409448) },
      { UINT32_C(3010713319), UINT32_C(1562613916), UINT32_C(3051275523), UINT32_C( 475276377) },
       // INT32_C(           0),
      { UINT64_C( 4733790473873954707), UINT64_C(  732836067064037912) } },
    { { UINT32_C(1531664487), UINT32_C(2379249133) },
      { UINT32_C(1337273644), UINT32_C(2234958767), UINT32_C(3475171639), UINT32_C(3520233228) },
       // INT32_C(           1),
      { UINT64_C( 3423206973323207529), UINT64_C( 5317523708675499011) } },
    { { UINT32_C(3699452808), UINT32_C(2671968583) },
      { UINT32_C(3247218252), UINT32_C(2632850030), UINT32_C(2471181775), UINT32_C(1556795763) },
       // INT32_C(           3),
      { UINT64_C( 5759292456912852504), UINT64_C( 4159709368883513829) } },
    { { UINT32_C(1802659993), UINT32_C(1693699897) },
      { UINT32_C(1387056976), UINT32_C(2963163922), UINT32_C(4062142680), UINT32_C(2344729422) },
       // INT32_C(           2),
      { UINT64_C( 7322662095093801240), UINT64_C( 6880050638715303960) } },
    { { UINT32_C( 517471828), UINT32_C(3266824794) },
      { UINT32_C( 201007932), UINT32_C(3864813590), UINT32_C(1475915276), UINT32_C(2888804684) },
       // INT32_C(           0),
      { UINT64_C(  104015942014539696), UINT64_C(  656657696048266008) } },
    { { UINT32_C(3817077281), UINT32_C(2201454981) },
      { UINT32_C( 735925857), UINT32_C( 812162829), UINT32_C(4215763867), UINT32_C(2097622479) },
       // INT32_C(           1),
      { UINT64_C( 3100088283048587949), UINT64_C( 1787939905285101249) } },
    { { UINT32_C(2395916894), UINT32_C(1907332726) },
      { UINT32_C(2750845465), UINT32_C( 537164490), UINT32_C(4146933591), UINT32_C( 194141847) },
       // INT32_C(           1),
      { UINT64_C( 1287001476447894060), UINT64_C( 1024551411022099740) } }
  };

    simde_uint32x2_t a;
    simde_uint32x4_t v;
    simde_uint64x2_t r;

    a = simde_vld1_u32(test_vec[0].a);
    v = simde_vld1q_u32(test_vec[0].v);
    r = simde_vmull_laneq_u32(a, v, 2);
    simde_test_arm_neon_assert_equal_u64x2(r, simde_vld1q_u64(test_vec[0].r));

    a = simde_vld1_u32(test_vec[1].a);
    v = simde_vld1q_u32(test_vec[1].v);
    r = simde_vmull_laneq_u32(a, v, 0);
    simde_test_arm_neon_assert_equal_u64x2(r, simde_vld1q_u64(test_vec[1].r));

    a = simde_vld1_u32(test_vec[2].a);
    v = simde_vld1q_u32(test_vec[2].v);
    r = simde_vmull_laneq_u32(a, v, 1);
    simde_test_arm_neon_assert_equal_u64x2(r, simde_vld1q_u64(test_vec[2].r));

    a = simde_vld1_u32(test_vec[3].a);
    v = simde_vld1q_u32(test_vec[3].v);
    r = simde_vmull_laneq_u32(a, v, 3);
    simde_test_arm_neon_assert_equal_u64x2(r, simde_vld1q_u64(test_vec[3].r));

    a = simde_vld1_u32(test_vec[4].a);
    v = simde_vld1q_u32(test_vec[4].v);
    r = simde_vmull_laneq_u32(a, v, 2);
    simde_test_arm_neon_assert_equal_u64x2(r, simde_vld1q_u64(test_vec[4].r));

    a = simde_vld1_u32(test_vec[5].a);
    v = simde_vld1q_u32(test_vec[5].v);
    r = simde_vmull_laneq_u32(a, v, 0);
    simde_test_arm_neon_assert_equal_u64x2(r, simde_vld1q_u64(test_vec[5].r));

    a = simde_vld1_u32(test_vec[6].a);
    v = simde_vld1q_u32(test_vec[6].v);
    r = simde_vmull_laneq_u32(a, v, 1);
    simde_test_arm_neon_assert_equal_u64x2(r, simde_vld1q_u64(test_vec[6].r));

    a = simde_vld1_u32(test_vec[7].a);
    v = simde_vld1q_u32(test_vec[7].v);
    r = simde_vmull_laneq_u32(a, v, 1);
    simde_test_arm_neon_assert_equal_u64x2(r, simde_vld1q_u64(test_vec[7].r));

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint32x2_t a = simde_test_arm_neon_random_u32x2();
    simde_uint32x4_t v = simde_test_arm_neon_random_u32x4();
    uint8_t lane = simde_test_codegen_random_u8() & 3;
    simde_uint64x2_t r;

    SIMDE_CONSTIFY_4_(simde_vmull_laneq_u32, r, (HEDLEY_UNREACHABLE(), simde_vdupq_n_u64(0)), lane, a, v);

    simde_test_arm_neon_write_u32x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u32x4(2, v, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, lane, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(vmull_lane_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vmull_lane_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vmull_lane_u16)
SIMDE_TEST_FUNC_LIST_ENTRY(vmull_lane_u32)
SIMDE_TEST_FUNC_LIST_ENTRY(vmull_laneq_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vmull_laneq_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vmull_laneq_u16)
SIMDE_TEST_FUNC_LIST_ENTRY(vmull_laneq_u32)
SIMDE_TEST_FUNC_LIST_END

#include "test-neon-footer.h"
