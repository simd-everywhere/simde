#define SIMDE_TEST_ARM_NEON_INSN mlal_lane

#include "test-neon.h"
#include "../../../simde/arm/neon/mlal_lane.h"

static int
test_simde_vmlal_lane_s16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int32_t a[4];
    int16_t b[4];
    int16_t v[4];
    int32_t r[4];
  } test_vec[] = {
    { {  INT32_C(  1713556006), -INT32_C(  1279835680), -INT32_C(  1616050025),  INT32_C(   627846655) },
      { -INT16_C(  7644), -INT16_C(  2716),  INT16_C( 26640), -INT16_C(  1801) },
      {  INT16_C( 16841), -INT16_C( 26034), -INT16_C( 22960),  INT16_C( 30371) },
       // INT32_C(     0),
      {  INT32_C(  1584823402), -INT32_C(  1325575836), -INT32_C(  1167405785),  INT32_C(   597516014) } },
    { {  INT32_C(   105962693), -INT32_C(  1667365997), -INT32_C(   560251472), -INT32_C(  1945976662) },
      { -INT16_C(  2267), -INT16_C( 29284), -INT16_C( 27410),  INT16_C( 12119) },
      { -INT16_C(  3613), -INT16_C( 30336), -INT16_C(  2412),  INT16_C( 23033) },
       // INT32_C(     3),
      {  INT32_C(    53746882),  INT32_C(  1953102927), -INT32_C(  1191586002), -INT32_C(  1666839735) } },
    { {  INT32_C(  1281777737),  INT32_C(  1006371582),  INT32_C(  1592122013), -INT32_C(   729582883) },
      {  INT16_C(  4110), -INT16_C( 23613), -INT16_C(  3481),  INT16_C( 22662) },
      {  INT16_C(  3954),  INT16_C( 27116),  INT16_C( 17928),  INT16_C( 20796) },
       // INT32_C(     2),
      {  INT32_C(  1355461817),  INT32_C(   583037718),  INT32_C(  1529714645), -INT32_C(   323298547) } },
    { { -INT32_C(  1515938398),  INT32_C(  1950539673),  INT32_C(   928096453),  INT32_C(   876946723) },
      { -INT16_C(  5912), -INT16_C(  9317), -INT16_C(  2962),  INT16_C( 32077) },
      { -INT16_C( 18720),  INT16_C(  9861), -INT16_C( 10510), -INT16_C( 27188) },
       // INT32_C(     3),
      { -INT32_C(  1355202942), -INT32_C(  2091117027),  INT32_C(  1008627309),  INT32_C(     4837247) } },
    { {  INT32_C(  1343044208),  INT32_C(   487948668), -INT32_C(   146780974),  INT32_C(  2061530257) },
      { -INT16_C( 17648),  INT16_C(  1256),  INT16_C( 26120), -INT16_C( 16412) },
      {  INT16_C(  3051), -INT16_C( 15695),  INT16_C( 18135),  INT16_C( 18485) },
       // INT32_C(     0),
      {  INT32_C(  1289200160),  INT32_C(   491780724), -INT32_C(    67088854),  INT32_C(  2011457245) } },
    { { -INT32_C(  1006790590), -INT32_C(   107668819), -INT32_C(   813003430),  INT32_C(   685704301) },
      { -INT16_C(  7187),  INT16_C( 21296), -INT16_C(  4153), -INT16_C( 11714) },
      {  INT16_C(   161), -INT16_C(  6230), -INT16_C(  3530),  INT16_C( 30824) },
       // INT32_C(     2),
      { -INT32_C(   981420480), -INT32_C(   182843699), -INT32_C(   798343340),  INT32_C(   727054721) } },
    { {  INT32_C(  2134326373),  INT32_C(  1591292113), -INT32_C(  1077172038),  INT32_C(  1789719431) },
      { -INT16_C(   220),  INT16_C(  4914),  INT16_C(  1085),  INT16_C( 16052) },
      { -INT16_C( 25426), -INT16_C( 24460), -INT16_C(  5116),  INT16_C( 26922) },
       // INT32_C(     0),
      {  INT32_C(  2139920093),  INT32_C(  1466348749), -INT32_C(  1104759248),  INT32_C(  1381581279) } },
    { { -INT32_C(  1845827487),  INT32_C(  1783388353),  INT32_C(   401672996), -INT32_C(  1237623625) },
      {  INT16_C( 20366), -INT16_C( 27917),  INT16_C( 12547), -INT16_C( 24767) },
      { -INT16_C(  7771), -INT16_C( 27997),  INT16_C(  3084),  INT16_C( 28090) },
       // INT32_C(     0),
      { -INT32_C(  2004091673),  INT32_C(  2000331360),  INT32_C(   304170259), -INT32_C(  1045159268) } }
  };

    simde_int32x4_t a, r;
    simde_int16x4_t b, v;

    a = simde_vld1q_s32(test_vec[0].a);
    b = simde_vld1_s16(test_vec[0].b);
    v = simde_vld1_s16(test_vec[0].v);
    r = simde_vmlal_lane_s16(a, b, v, 0);
    simde_test_arm_neon_assert_equal_i32x4(r, simde_vld1q_s32(test_vec[0].r));

    a = simde_vld1q_s32(test_vec[1].a);
    b = simde_vld1_s16(test_vec[1].b);
    v = simde_vld1_s16(test_vec[1].v);
    r = simde_vmlal_lane_s16(a, b, v, 3);
    simde_test_arm_neon_assert_equal_i32x4(r, simde_vld1q_s32(test_vec[1].r));

    a = simde_vld1q_s32(test_vec[2].a);
    b = simde_vld1_s16(test_vec[2].b);
    v = simde_vld1_s16(test_vec[2].v);
    r = simde_vmlal_lane_s16(a, b, v, 2);
    simde_test_arm_neon_assert_equal_i32x4(r, simde_vld1q_s32(test_vec[2].r));

    a = simde_vld1q_s32(test_vec[3].a);
    b = simde_vld1_s16(test_vec[3].b);
    v = simde_vld1_s16(test_vec[3].v);
    r = simde_vmlal_lane_s16(a, b, v, 3);
    simde_test_arm_neon_assert_equal_i32x4(r, simde_vld1q_s32(test_vec[3].r));

    a = simde_vld1q_s32(test_vec[4].a);
    b = simde_vld1_s16(test_vec[4].b);
    v = simde_vld1_s16(test_vec[4].v);
    r = simde_vmlal_lane_s16(a, b, v, 0);
    simde_test_arm_neon_assert_equal_i32x4(r, simde_vld1q_s32(test_vec[4].r));

    a = simde_vld1q_s32(test_vec[5].a);
    b = simde_vld1_s16(test_vec[5].b);
    v = simde_vld1_s16(test_vec[5].v);
    r = simde_vmlal_lane_s16(a, b, v, 2);
    simde_test_arm_neon_assert_equal_i32x4(r, simde_vld1q_s32(test_vec[5].r));

    a = simde_vld1q_s32(test_vec[6].a);
    b = simde_vld1_s16(test_vec[6].b);
    v = simde_vld1_s16(test_vec[6].v);
    r = simde_vmlal_lane_s16(a, b, v, 0);
    simde_test_arm_neon_assert_equal_i32x4(r, simde_vld1q_s32(test_vec[6].r));

    a = simde_vld1q_s32(test_vec[7].a);
    b = simde_vld1_s16(test_vec[7].b);
    v = simde_vld1_s16(test_vec[7].v);
    r = simde_vmlal_lane_s16(a, b, v, 0);
    simde_test_arm_neon_assert_equal_i32x4(r, simde_vld1q_s32(test_vec[7].r));

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int32x4_t a = simde_test_arm_neon_random_i32x4();
    simde_int16x4_t b = simde_test_arm_neon_random_i16x4();
    simde_int16x4_t v = simde_test_arm_neon_random_i16x4();
    int8_t lane = simde_test_codegen_random_i8() & 3;
    simde_int32x4_t r;

    SIMDE_CONSTIFY_4_(simde_vmlal_lane_s16, r, (HEDLEY_UNREACHABLE(), simde_vdupq_n_s32(0)), lane, a, b, v);

    simde_test_arm_neon_write_i32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i16x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i16x4(2, v, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i16(2, lane, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vmlal_lane_s32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int64_t a[2];
    int32_t b[2];
    int32_t v[2];
    int64_t r[2];
  } test_vec[] = {
    { {  INT64_C( 6820692299433209120), -INT64_C(  268302382627525992) },
      { -INT32_C(   686465627), -INT32_C(  1495459457) },
      {  INT32_C(   729996818),  INT32_C(  1484120119) },
       // INT32_C(           1),
      {  INT64_C( 5801894851400559507), -INT64_C( 2487743849910041375) } },
    { { -INT64_C( 6342425908547185301),  INT64_C( 3366171135238376005) },
      {  INT32_C(   967675423),  INT32_C(  1246450796) },
      { -INT32_C(  1216186410),  INT32_C(  1459935980) },
       // INT32_C(           1),
      { -INT64_C( 4929681741547765761),  INT64_C( 5185909499618416085) } },
    { {  INT64_C( 4559705184618199764), -INT64_C( 7022170582530697118) },
      {  INT32_C(  1057670635), -INT32_C(  2028645360) },
      { -INT32_C(  1334522666), -INT32_C(  1524577327) },
       // INT32_C(           1),
      {  INT64_C( 2947204515063507119), -INT64_C( 3929343862150944398) } },
    { {  INT64_C( 5080757388982265548),  INT64_C( 4589717203906326153) },
      {  INT32_C(  1381036285), -INT32_C(   769075450) },
      {  INT32_C(   396613963), -INT32_C(   979613447) },
       // INT32_C(           1),
      {  INT64_C( 3727875673401341153),  INT64_C( 5343113856483902303) } },
    { {  INT64_C( 6258070984341644759),  INT64_C( 4785374020945092728) },
      {  INT32_C(   927513440), -INT32_C(  1132258589) },
      {  INT32_C(   112564926),  INT32_C(   234191670) },
       // INT32_C(           0),
      {  INT64_C( 6362476466079250199),  INT64_C( 4657921416661443314) } },
    { { -INT64_C( 2923928832391487790), -INT64_C(  261653797159708434) },
      { -INT32_C(   840984909), -INT32_C(  1282696167) },
      { -INT32_C(   857107887),  INT32_C(  1496184711) },
       // INT32_C(           1),
      { -INT64_C( 4182197595419014089), -INT64_C( 2180804191083411171) } },
    { { -INT64_C( 7925943118840705291), -INT64_C(  816330900629159795) },
      {  INT32_C(  1259174063), -INT32_C(  1768112124) },
      { -INT32_C(  1591907926), -INT32_C(  1946781802) },
       // INT32_C(           1),
      {  INT64_C( 8069463803470044799),  INT64_C( 2625797606269607653) } },
    { { -INT64_C( 6957196521381060990), -INT64_C( 8114094449258239003) },
      { -INT32_C(  1064063232), -INT32_C(  1268111029) },
      { -INT32_C(  1119220922), -INT32_C(  2071800575) },
       // INT32_C(           1),
      { -INT64_C( 4752669705487102590), -INT64_C( 5486821290212197328) } }
  };

    simde_int64x2_t a, r;
    simde_int32x2_t b, v;

    a = simde_vld1q_s64(test_vec[0].a);
    b = simde_vld1_s32(test_vec[0].b);
    v = simde_vld1_s32(test_vec[0].v);
    r = simde_vmlal_lane_s32(a, b, v, 1);
    simde_test_arm_neon_assert_equal_i64x2(r, simde_vld1q_s64(test_vec[0].r));

    a = simde_vld1q_s64(test_vec[1].a);
    b = simde_vld1_s32(test_vec[1].b);
    v = simde_vld1_s32(test_vec[1].v);
    r = simde_vmlal_lane_s32(a, b, v, 1);
    simde_test_arm_neon_assert_equal_i64x2(r, simde_vld1q_s64(test_vec[1].r));

    a = simde_vld1q_s64(test_vec[2].a);
    b = simde_vld1_s32(test_vec[2].b);
    v = simde_vld1_s32(test_vec[2].v);
    r = simde_vmlal_lane_s32(a, b, v, 1);
    simde_test_arm_neon_assert_equal_i64x2(r, simde_vld1q_s64(test_vec[2].r));

    a = simde_vld1q_s64(test_vec[3].a);
    b = simde_vld1_s32(test_vec[3].b);
    v = simde_vld1_s32(test_vec[3].v);
    r = simde_vmlal_lane_s32(a, b, v, 1);
    simde_test_arm_neon_assert_equal_i64x2(r, simde_vld1q_s64(test_vec[3].r));

    a = simde_vld1q_s64(test_vec[4].a);
    b = simde_vld1_s32(test_vec[4].b);
    v = simde_vld1_s32(test_vec[4].v);
    r = simde_vmlal_lane_s32(a, b, v, 0);
    simde_test_arm_neon_assert_equal_i64x2(r, simde_vld1q_s64(test_vec[4].r));

    a = simde_vld1q_s64(test_vec[5].a);
    b = simde_vld1_s32(test_vec[5].b);
    v = simde_vld1_s32(test_vec[5].v);
    r = simde_vmlal_lane_s32(a, b, v, 1);
    simde_test_arm_neon_assert_equal_i64x2(r, simde_vld1q_s64(test_vec[5].r));

    a = simde_vld1q_s64(test_vec[6].a);
    b = simde_vld1_s32(test_vec[6].b);
    v = simde_vld1_s32(test_vec[6].v);
    r = simde_vmlal_lane_s32(a, b, v, 1);
    simde_test_arm_neon_assert_equal_i64x2(r, simde_vld1q_s64(test_vec[6].r));

    a = simde_vld1q_s64(test_vec[7].a);
    b = simde_vld1_s32(test_vec[7].b);
    v = simde_vld1_s32(test_vec[7].v);
    r = simde_vmlal_lane_s32(a, b, v, 1);
    simde_test_arm_neon_assert_equal_i64x2(r, simde_vld1q_s64(test_vec[7].r));

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int64x2_t a = simde_test_arm_neon_random_i64x2();
    simde_int32x2_t b = simde_test_arm_neon_random_i32x2();
    simde_int32x2_t v = simde_test_arm_neon_random_i32x2();
    int8_t lane = simde_test_codegen_random_i8() & 1;
    simde_int64x2_t r;

    SIMDE_CONSTIFY_2_(simde_vmlal_lane_s32, r, (HEDLEY_UNREACHABLE(), simde_vdupq_n_s64(0)), lane, a, b, v);

    simde_test_arm_neon_write_i64x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i32x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i32x2(2, v, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, lane, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vmlal_lane_u16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint32_t a[4];
    uint16_t b[4];
    uint16_t v[4];
    uint32_t r[4];
  } test_vec[] = {
    { { UINT32_C(3470163751), UINT32_C(2499121873), UINT32_C(2690159663), UINT32_C(3794688708) },
      { UINT16_C(25277), UINT16_C( 3796), UINT16_C( 5917), UINT16_C(33585) },
      { UINT16_C(29697), UINT16_C(14074), UINT16_C(24676), UINT16_C(35653) },
      // INT32_C(    0),
      { UINT32_C(4220814820), UINT32_C(2611851685), UINT32_C(2865876812), UINT32_C( 497095157) } },
    { { UINT32_C(2914081051), UINT32_C(3822929486), UINT32_C(4171726238), UINT32_C( 230001323) },
      { UINT16_C(50270), UINT16_C(30250), UINT16_C(44533), UINT16_C(27255) },
      { UINT16_C(44456), UINT16_C( 2254), UINT16_C(23026), UINT16_C( 3560) },
      // INT32_C(    3),
      { UINT32_C(3093042251), UINT32_C(3930619486), UINT32_C(  35296422), UINT32_C( 327029123) } },
    { { UINT32_C(3758209946), UINT32_C( 360637592), UINT32_C( 381777804), UINT32_C(4034186796) },
      { UINT16_C(60153), UINT16_C(42726), UINT16_C(20577), UINT16_C( 3662) },
      { UINT16_C(22302), UINT16_C(30464), UINT16_C( 3647), UINT16_C(55594) },
      // INT32_C(    1),
      { UINT32_C(1295743642), UINT32_C(1662242456), UINT32_C(1008635532), UINT32_C(4145745964) } },
    { { UINT32_C( 274839852), UINT32_C(2946266680), UINT32_C( 115061303), UINT32_C( 301976615) },
      { UINT16_C(42418), UINT16_C(  627), UINT16_C(33268), UINT16_C(19232) },
      { UINT16_C(38786), UINT16_C(37002), UINT16_C(25794), UINT16_C(61017) },
      // INT32_C(    1),
      { UINT32_C(1844390688), UINT32_C(2969466934), UINT32_C(1346043839), UINT32_C(1013599079) } },
    { { UINT32_C( 810942138), UINT32_C(1298662555), UINT32_C(2893311712), UINT32_C( 308184685) },
      { UINT16_C(24825), UINT16_C(31238), UINT16_C(20864), UINT16_C( 6140) },
      { UINT16_C(36060), UINT16_C(16601), UINT16_C(51173), UINT16_C(40797) },
      // INT32_C(    2),
      { UINT32_C(2081311863), UINT32_C(2897204729), UINT32_C(3960985184), UINT32_C( 622386905) } },
    { { UINT32_C(3076640947), UINT32_C(2794958392), UINT32_C(2836611875), UINT32_C(  27403681) },
      { UINT16_C( 7212), UINT16_C(32129), UINT16_C(39193), UINT16_C(42329) },
      { UINT16_C(39282), UINT16_C(14987), UINT16_C(10999), UINT16_C(43520) },
      // INT32_C(    2),
      { UINT32_C(3155965735), UINT32_C(3148345263), UINT32_C(3267695682), UINT32_C( 492980352) } },
    { { UINT32_C( 254959969), UINT32_C(1009965305), UINT32_C( 299817963), UINT32_C(2587746173) },
      { UINT16_C(47713), UINT16_C(64179), UINT16_C(22548), UINT16_C(44396) },
      { UINT16_C(42723), UINT16_C( 3748), UINT16_C(20134), UINT16_C( 1800) },
      // INT32_C(    0),
      { UINT32_C(2293402468), UINT32_C(3751884722), UINT32_C(1263136167), UINT32_C( 189509185) } },
    { { UINT32_C( 329848635), UINT32_C( 637527369), UINT32_C(2745307331), UINT32_C( 117718093) },
      { UINT16_C(65263), UINT16_C(18459), UINT16_C(51562), UINT16_C( 4395) },
      { UINT16_C(14701), UINT16_C(48311), UINT16_C(48962), UINT16_C(32108) },
      // INT32_C(    2),
      { UINT32_C(3525255641), UINT32_C(1541316927), UINT32_C( 974918679), UINT32_C( 332906083) } }
  };

    simde_uint32x4_t a, r;
    simde_uint16x4_t b, v;

    a = simde_vld1q_u32(test_vec[0].a);
    b = simde_vld1_u16(test_vec[0].b);
    v = simde_vld1_u16(test_vec[0].v);
    r = simde_vmlal_lane_u16(a, b, v, 0);
    simde_test_arm_neon_assert_equal_u32x4(r, simde_vld1q_u32(test_vec[0].r));

    a = simde_vld1q_u32(test_vec[1].a);
    b = simde_vld1_u16(test_vec[1].b);
    v = simde_vld1_u16(test_vec[1].v);
    r = simde_vmlal_lane_u16(a, b, v, 3);
    simde_test_arm_neon_assert_equal_u32x4(r, simde_vld1q_u32(test_vec[1].r));

    a = simde_vld1q_u32(test_vec[2].a);
    b = simde_vld1_u16(test_vec[2].b);
    v = simde_vld1_u16(test_vec[2].v);
    r = simde_vmlal_lane_u16(a, b, v, 1);
    simde_test_arm_neon_assert_equal_u32x4(r, simde_vld1q_u32(test_vec[2].r));

    a = simde_vld1q_u32(test_vec[3].a);
    b = simde_vld1_u16(test_vec[3].b);
    v = simde_vld1_u16(test_vec[3].v);
    r = simde_vmlal_lane_u16(a, b, v, 1);
    simde_test_arm_neon_assert_equal_u32x4(r, simde_vld1q_u32(test_vec[3].r));

    a = simde_vld1q_u32(test_vec[4].a);
    b = simde_vld1_u16(test_vec[4].b);
    v = simde_vld1_u16(test_vec[4].v);
    r = simde_vmlal_lane_u16(a, b, v, 2);
    simde_test_arm_neon_assert_equal_u32x4(r, simde_vld1q_u32(test_vec[4].r));

    a = simde_vld1q_u32(test_vec[5].a);
    b = simde_vld1_u16(test_vec[5].b);
    v = simde_vld1_u16(test_vec[5].v);
    r = simde_vmlal_lane_u16(a, b, v, 2);
    simde_test_arm_neon_assert_equal_u32x4(r, simde_vld1q_u32(test_vec[5].r));

    a = simde_vld1q_u32(test_vec[6].a);
    b = simde_vld1_u16(test_vec[6].b);
    v = simde_vld1_u16(test_vec[6].v);
    r = simde_vmlal_lane_u16(a, b, v, 0);
    simde_test_arm_neon_assert_equal_u32x4(r, simde_vld1q_u32(test_vec[6].r));

    a = simde_vld1q_u32(test_vec[7].a);
    b = simde_vld1_u16(test_vec[7].b);
    v = simde_vld1_u16(test_vec[7].v);
    r = simde_vmlal_lane_u16(a, b, v, 2);
    simde_test_arm_neon_assert_equal_u32x4(r, simde_vld1q_u32(test_vec[7].r));

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint32x4_t a = simde_test_arm_neon_random_u32x4();
    simde_uint16x4_t b = simde_test_arm_neon_random_u16x4();
    simde_uint16x4_t v = simde_test_arm_neon_random_u16x4();
    uint8_t lane = simde_test_codegen_random_u8() & 3;
    simde_uint32x4_t r;

    SIMDE_CONSTIFY_4_(simde_vmlal_lane_u16, r, (HEDLEY_UNREACHABLE(), simde_vdupq_n_u32(0)), lane, a, b, v);

    simde_test_arm_neon_write_u32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u16x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u16x4(2, v, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, lane, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vmlal_lane_u32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint64_t a[2];
    uint32_t b[2];
    uint32_t v[2];
    uint64_t r[2];
  } test_vec[] = {
    { { UINT64_C(11510713082772951061), UINT64_C( 7139318549543936487) },
      { UINT32_C(3637336847), UINT32_C(3225869958) },
      { UINT32_C(1426195094), UINT32_C(2200665966) },
      // UINT32_C(         1),
      { UINT64_C( 1068532415134048647), UINT64_C(14238380776856385915) } },
    { { UINT64_C(11274267142702202186), UINT64_C(  517461697611536683) },
      { UINT32_C( 277743410), UINT32_C(1336299085) },
      { UINT32_C(3485334352), UINT32_C(1910390822) },
      // UINT32_C(         1),
      { UINT64_C(11804865604037185206), UINT64_C( 3070315205042534553) } },
    { { UINT64_C( 1146048967398195325), UINT64_C( 4264279054518847127) },
      { UINT32_C(2676506193), UINT32_C(3773814756) },
      { UINT32_C(3557211796), UINT32_C( 445806493) },
      // UINT32_C(         1),
      { UINT64_C( 2339252806792306474), UINT64_C( 5946670176122857835) } },
    { { UINT64_C(14103019746877101707), UINT64_C( 2219768705602597817) },
      { UINT32_C(2466475452), UINT32_C( 455664477) },
      { UINT32_C(1639513321), UINT32_C( 433640334) },
      // UINT32_C(         1),
      { UINT64_C(15172582985685182675), UINT64_C( 2417363201600813135) } },
    { { UINT64_C(11852395537186110150), UINT64_C( 3752241511803516962) },
      { UINT32_C(2308023718), UINT32_C(3396578509) },
      { UINT32_C( 945345637), UINT32_C(1927377580) },
      // UINT32_C(         0),
      { UINT64_C(14034275689089928516), UINT64_C( 6963182186014632195) } },
    { { UINT64_C(12291804087893964104), UINT64_C(11750354311105801159) },
      { UINT32_C(3799030325), UINT32_C(3779541517) },
      { UINT32_C(  93224851), UINT32_C(2846949472) },
      // UINT32_C(         0),
      { UINT64_C(12645968123886570679), UINT64_C(12102701505876440126) } },
    { { UINT64_C(11337690778754817102), UINT64_C( 7916270224253043202) },
      { UINT32_C(3900423854), UINT32_C(2222676997) },
      { UINT32_C(3957620970), UINT32_C(2149682481) },
      // UINT32_C(         1),
      { UINT64_C( 1275619532463567260), UINT64_C(12694320025625632759) } },
    { { UINT64_C( 3070602174109782024), UINT64_C(15888253215997510290) },
      { UINT32_C(1122068197), UINT32_C(1647076834) },
      { UINT32_C(3616806730), UINT32_C(1098978360) },
      // UINT32_C(         0),
      { UINT64_C( 7128905980538347834), UINT64_C( 3398667720326251494) } }
  };

    simde_uint64x2_t a, r;
    simde_uint32x2_t b, v;

    a = simde_vld1q_u64(test_vec[0].a);
    b = simde_vld1_u32(test_vec[0].b);
    v = simde_vld1_u32(test_vec[0].v);
    r = simde_vmlal_lane_u32(a, b, v, 1);
    simde_test_arm_neon_assert_equal_u64x2(r, simde_vld1q_u64(test_vec[0].r));

    a = simde_vld1q_u64(test_vec[1].a);
    b = simde_vld1_u32(test_vec[1].b);
    v = simde_vld1_u32(test_vec[1].v);
    r = simde_vmlal_lane_u32(a, b, v, 1);
    simde_test_arm_neon_assert_equal_u64x2(r, simde_vld1q_u64(test_vec[1].r));

    a = simde_vld1q_u64(test_vec[2].a);
    b = simde_vld1_u32(test_vec[2].b);
    v = simde_vld1_u32(test_vec[2].v);
    r = simde_vmlal_lane_u32(a, b, v, 1);
    simde_test_arm_neon_assert_equal_u64x2(r, simde_vld1q_u64(test_vec[2].r));

    a = simde_vld1q_u64(test_vec[3].a);
    b = simde_vld1_u32(test_vec[3].b);
    v = simde_vld1_u32(test_vec[3].v);
    r = simde_vmlal_lane_u32(a, b, v, 1);
    simde_test_arm_neon_assert_equal_u64x2(r, simde_vld1q_u64(test_vec[3].r));

    a = simde_vld1q_u64(test_vec[4].a);
    b = simde_vld1_u32(test_vec[4].b);
    v = simde_vld1_u32(test_vec[4].v);
    r = simde_vmlal_lane_u32(a, b, v, 0);
    simde_test_arm_neon_assert_equal_u64x2(r, simde_vld1q_u64(test_vec[4].r));

    a = simde_vld1q_u64(test_vec[5].a);
    b = simde_vld1_u32(test_vec[5].b);
    v = simde_vld1_u32(test_vec[5].v);
    r = simde_vmlal_lane_u32(a, b, v, 0);
    simde_test_arm_neon_assert_equal_u64x2(r, simde_vld1q_u64(test_vec[5].r));

    a = simde_vld1q_u64(test_vec[6].a);
    b = simde_vld1_u32(test_vec[6].b);
    v = simde_vld1_u32(test_vec[6].v);
    r = simde_vmlal_lane_u32(a, b, v, 1);
    simde_test_arm_neon_assert_equal_u64x2(r, simde_vld1q_u64(test_vec[6].r));

    a = simde_vld1q_u64(test_vec[7].a);
    b = simde_vld1_u32(test_vec[7].b);
    v = simde_vld1_u32(test_vec[7].v);
    r = simde_vmlal_lane_u32(a, b, v, 0);
    simde_test_arm_neon_assert_equal_u64x2(r, simde_vld1q_u64(test_vec[7].r));

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint64x2_t a = simde_test_arm_neon_random_u64x2();
    simde_uint32x2_t b = simde_test_arm_neon_random_u32x2();
    simde_uint32x2_t v = simde_test_arm_neon_random_u32x2();
    uint8_t lane = simde_test_codegen_random_u8() & 1;
    simde_uint64x2_t r;

    SIMDE_CONSTIFY_2_(simde_vmlal_lane_u32, r, (HEDLEY_UNREACHABLE(), simde_vdupq_n_u64(0)), lane, a, b, v);

    simde_test_arm_neon_write_u64x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u32x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x2(2, v, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, lane, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vmlal_laneq_s16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int32_t a[4];
    int16_t b[4];
    int16_t v[8];
    int32_t r[4];
  } test_vec[] = {
    { {  INT32_C(   913196349), -INT32_C(    45695265),  INT32_C(  1914359766), -INT32_C(  1085973607) },
      {  INT16_C( 17251),  INT16_C( 17944),  INT16_C( 21996), -INT16_C( 23174) },
      {  INT16_C( 19471),  INT16_C(   263),  INT16_C(  4751), -INT16_C( 13270), -INT16_C( 26537),  INT16_C( 14083),  INT16_C( 18774),  INT16_C( 11572) },
       // INT32_C(           0),
      {  INT32_C(  1249090570),  INT32_C(   303692359), -INT32_C(  1952323414), -INT32_C(  1537194561) } },
    { { -INT32_C(  1447911602),  INT32_C(   655192548), -INT32_C(   569093239),  INT32_C(   451852750) },
      { -INT16_C(  4160), -INT16_C( 11351),  INT16_C( 30233), -INT16_C( 20182) },
      {  INT16_C( 24953), -INT16_C( 15864),  INT16_C( 13717), -INT16_C(  6950), -INT16_C( 29484), -INT16_C( 18035), -INT16_C( 25859), -INT16_C( 30752) },
       // INT32_C(           6),
      { -INT32_C(  1340338162),  INT32_C(   948718057), -INT32_C(  1350888386),  INT32_C(   973739088) } },
    { { -INT32_C(  1380162060),  INT32_C(  1131337299), -INT32_C(   161726080), -INT32_C(   848359829) },
      {  INT16_C( 12566),  INT16_C( 19298),  INT16_C( 17931), -INT16_C( 26593) },
      { -INT16_C( 10028),  INT16_C( 28309),  INT16_C(  7353), -INT16_C( 21156),  INT16_C(  6274), -INT16_C( 10917), -INT16_C( 13841),  INT16_C( 28440) },
       // INT32_C(           2),
      { -INT32_C(  1287764262),  INT32_C(  1273235493), -INT32_C(    29879437), -INT32_C(  1043898158) } },
    { { -INT32_C(  2089458315),  INT32_C(    93930196), -INT32_C(   351214427), -INT32_C(   591419389) },
      {  INT16_C( 11838),  INT16_C( 23189),  INT16_C( 17034), -INT16_C( 23588) },
      { -INT16_C( 19811),  INT16_C( 26258),  INT16_C(   458),  INT16_C( 16240), -INT16_C(  6554),  INT16_C( 15042),  INT16_C( 23336), -INT16_C( 12993) },
       // INT32_C(           7),
      {  INT32_C(  2051697847), -INT32_C(   207364481), -INT32_C(   572537189), -INT32_C(   284940505) } },
    { { -INT32_C(   129779377), -INT32_C(  1506402440), -INT32_C(   164523852),  INT32_C(   529847405) },
      { -INT16_C(  1434),  INT16_C( 26601),  INT16_C( 10603),  INT16_C( 20941) },
      {  INT16_C(  2027),  INT16_C( 18297),  INT16_C( 18246), -INT16_C( 27258), -INT16_C( 14080),  INT16_C( 30861), -INT16_C( 15384), -INT16_C( 25569) },
       // INT32_C(           4),
      { -INT32_C(   109588657), -INT32_C(  1880944520), -INT32_C(   313814092),  INT32_C(   234998125) } },
    { {  INT32_C(   616665936),  INT32_C(   562749479), -INT32_C(   225644087), -INT32_C(   975249986) },
      {  INT16_C(  9559), -INT16_C( 25077), -INT16_C( 24405),  INT16_C( 30110) },
      {  INT16_C(  5678), -INT16_C(  3747), -INT16_C(  1483), -INT16_C( 31419),  INT16_C(  1677), -INT16_C( 19287),  INT16_C( 13286), -INT16_C( 20267) },
       // INT32_C(           4),
      {  INT32_C(   632696379),  INT32_C(   520695350), -INT32_C(   266571272), -INT32_C(   924755516) } },
    { {  INT32_C(  1071817314), -INT32_C(  1516853376),  INT32_C(  1397830834), -INT32_C(   377370926) },
      {  INT16_C( 29219),  INT16_C(  7454), -INT16_C( 23368), -INT16_C( 16726) },
      {  INT16_C( 24141), -INT16_C( 32347),  INT16_C( 21812), -INT16_C( 26971), -INT16_C( 30473),  INT16_C( 30933),  INT16_C( 27695), -INT16_C(  7651) },
       // INT32_C(           0),
      {  INT32_C(  1777193193), -INT32_C(  1336906362),  INT32_C(   833703946), -INT32_C(   781153292) } },
    { {  INT32_C(   879965550),  INT32_C(   676879542),  INT32_C(   518026618),  INT32_C(  2121047840) },
      { -INT16_C(  4796), -INT16_C( 26190),  INT16_C( 18578),  INT16_C(  6800) },
      {  INT16_C(  2078), -INT16_C( 30134),  INT16_C( 11302), -INT16_C( 27606), -INT16_C( 25247),  INT16_C(  6089),  INT16_C(  8697),  INT16_C( 29759) },
       // INT32_C(           6),
      {  INT32_C(   838254738),  INT32_C(   449105112),  INT32_C(   679599484), -INT32_C(  2114779856) } }
  };

    simde_int32x4_t a, r;
    simde_int16x4_t b;
    simde_int16x8_t v;

    a = simde_vld1q_s32(test_vec[0].a);
    b = simde_vld1_s16(test_vec[0].b);
    v = simde_vld1q_s16(test_vec[0].v);
    r = simde_vmlal_laneq_s16(a, b, v, 0);
    simde_test_arm_neon_assert_equal_i32x4(r, simde_vld1q_s32(test_vec[0].r));

    a = simde_vld1q_s32(test_vec[1].a);
    b = simde_vld1_s16(test_vec[1].b);
    v = simde_vld1q_s16(test_vec[1].v);
    r = simde_vmlal_laneq_s16(a, b, v, 6);
    simde_test_arm_neon_assert_equal_i32x4(r, simde_vld1q_s32(test_vec[1].r));

    a = simde_vld1q_s32(test_vec[2].a);
    b = simde_vld1_s16(test_vec[2].b);
    v = simde_vld1q_s16(test_vec[2].v);
    r = simde_vmlal_laneq_s16(a, b, v, 2);
    simde_test_arm_neon_assert_equal_i32x4(r, simde_vld1q_s32(test_vec[2].r));

    a = simde_vld1q_s32(test_vec[3].a);
    b = simde_vld1_s16(test_vec[3].b);
    v = simde_vld1q_s16(test_vec[3].v);
    r = simde_vmlal_laneq_s16(a, b, v, 7);
    simde_test_arm_neon_assert_equal_i32x4(r, simde_vld1q_s32(test_vec[3].r));

    a = simde_vld1q_s32(test_vec[4].a);
    b = simde_vld1_s16(test_vec[4].b);
    v = simde_vld1q_s16(test_vec[4].v);
    r = simde_vmlal_laneq_s16(a, b, v, 4);
    simde_test_arm_neon_assert_equal_i32x4(r, simde_vld1q_s32(test_vec[4].r));

    a = simde_vld1q_s32(test_vec[5].a);
    b = simde_vld1_s16(test_vec[5].b);
    v = simde_vld1q_s16(test_vec[5].v);
    r = simde_vmlal_laneq_s16(a, b, v, 4);
    simde_test_arm_neon_assert_equal_i32x4(r, simde_vld1q_s32(test_vec[5].r));

    a = simde_vld1q_s32(test_vec[6].a);
    b = simde_vld1_s16(test_vec[6].b);
    v = simde_vld1q_s16(test_vec[6].v);
    r = simde_vmlal_laneq_s16(a, b, v, 0);
    simde_test_arm_neon_assert_equal_i32x4(r, simde_vld1q_s32(test_vec[6].r));

    a = simde_vld1q_s32(test_vec[7].a);
    b = simde_vld1_s16(test_vec[7].b);
    v = simde_vld1q_s16(test_vec[7].v);
    r = simde_vmlal_laneq_s16(a, b, v, 6);
    simde_test_arm_neon_assert_equal_i32x4(r, simde_vld1q_s32(test_vec[7].r));

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int32x4_t a = simde_test_arm_neon_random_i32x4();
    simde_int16x4_t b = simde_test_arm_neon_random_i16x4();
    simde_int16x8_t v = simde_test_arm_neon_random_i16x8();
    int8_t lane = simde_test_codegen_random_i8() & 7;
    simde_int32x4_t r;

    SIMDE_CONSTIFY_8_(simde_vmlal_laneq_s16, r, (HEDLEY_UNREACHABLE(), simde_vdupq_n_s32(0)), lane, a, b, v);

    simde_test_arm_neon_write_i32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i16x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i16x8(2, v, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, lane, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vmlal_laneq_s32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int64_t a[2];
    int32_t b[2];
    int32_t v[4];
    int64_t r[2];
  } test_vec[] = {
    { { -INT64_C( 1512305681611976160),  INT64_C( 3841174847753198823) },
      {  INT32_C(   240900322), -INT32_C(  1603277054) },
      { -INT32_C(   644249928), -INT32_C(   428864058), -INT32_C(  1633343840),  INT32_C(  1133160539) },
       // INT32_C(           0),
      { -INT64_C( 1667505696715652976),  INT64_C( 4874085974356750935) } },
    { { -INT64_C( 7384876712918486264), -INT64_C( 8671616202984156928) },
      { -INT32_C(   498236715),  INT32_C(   411186162) },
      { -INT32_C(  2139872808), -INT32_C(  1278953557), -INT32_C(   346868438), -INT32_C(   612051238) },
       // INT32_C(           0),
      { -INT64_C( 6318713514542740544),  INT64_C( 8895241783635711792) } },
    { { -INT64_C(  778858357289530593), -INT64_C( 5311432168668982722) },
      {  INT32_C(   727829108), -INT32_C(  1001057137) },
      {  INT32_C(  1050558567), -INT32_C(   475629116), -INT32_C(  1203892412),  INT32_C(  1034776319) },
       // INT32_C(           1),
      { -INT64_C( 1125035072526639121), -INT64_C( 4835300247532181830) } },
    { { -INT64_C( 4392754589202993259), -INT64_C( 3915855097236409299) },
      {  INT32_C(   781051573), -INT32_C(  1686933364) },
      {  INT32_C(   496708527),  INT32_C(  1839126744), -INT32_C(  2147306361), -INT32_C(  1388049536) },
       // INT32_C(           3),
      { -INT64_C( 5476892862697713387), -INT64_C( 1574308024073290195) } },
    { {  INT64_C( 9034943883100352150),  INT64_C( 3332282209004064798) },
      {  INT32_C(   419912512), -INT32_C(  1365216006) },
      { -INT32_C(  2110840457), -INT32_C(    71115675),  INT32_C(  1655212747),  INT32_C(   987695644) },
       // INT32_C(           3),
      { -INT64_C( 8997054431645701738),  INT64_C( 1983864306758786934) } },
    { {  INT64_C( 7192192562291984873), -INT64_C( 6143178682457528108) },
      {  INT32_C(   386875962), -INT32_C(  1897788924) },
      { -INT32_C(  1112914765),  INT32_C(   223929635), -INT32_C(  1231226962), -INT32_C(  1743164476) },
       // INT32_C(           0),
      {  INT64_C( 6761632591958605943), -INT64_C( 4031101368084465248) } },
    { { -INT64_C( 2108661402072915850), -INT64_C(  480912411761126506) },
      {  INT32_C(    68948255),  INT32_C(  1622288745) },
      {  INT32_C(   824469701), -INT32_C(   142230399),  INT32_C(  1031365277),  INT32_C(  2132751849) },
       // INT32_C(           0),
      { -INT64_C( 2051815654888594095),  INT64_C(  856615504764688739) } },
    { { -INT64_C( 8892156857163112699), -INT64_C( 5205793588810769198) },
      {  INT32_C(   792326770), -INT32_C(   640929673) },
      { -INT32_C(   557708887),  INT32_C(   770064680), -INT32_C(   727276703),  INT32_C(   743980889) },
       // INT32_C(           3),
      { -INT64_C( 8302680882440014169), -INT64_C( 5682633016715788495) } }
  };

    simde_int64x2_t a, r;
    simde_int32x2_t b;
    simde_int32x4_t v;

    a = simde_vld1q_s64(test_vec[0].a);
    b = simde_vld1_s32(test_vec[0].b);
    v = simde_vld1q_s32(test_vec[0].v);
    r = simde_vmlal_laneq_s32(a, b, v, 0);
    simde_test_arm_neon_assert_equal_i64x2(r, simde_vld1q_s64(test_vec[0].r));

    a = simde_vld1q_s64(test_vec[1].a);
    b = simde_vld1_s32(test_vec[1].b);
    v = simde_vld1q_s32(test_vec[1].v);
    r = simde_vmlal_laneq_s32(a, b, v, 0);
    simde_test_arm_neon_assert_equal_i64x2(r, simde_vld1q_s64(test_vec[1].r));

    a = simde_vld1q_s64(test_vec[2].a);
    b = simde_vld1_s32(test_vec[2].b);
    v = simde_vld1q_s32(test_vec[2].v);
    r = simde_vmlal_laneq_s32(a, b, v, 1);
    simde_test_arm_neon_assert_equal_i64x2(r, simde_vld1q_s64(test_vec[2].r));

    a = simde_vld1q_s64(test_vec[3].a);
    b = simde_vld1_s32(test_vec[3].b);
    v = simde_vld1q_s32(test_vec[3].v);
    r = simde_vmlal_laneq_s32(a, b, v, 3);
    simde_test_arm_neon_assert_equal_i64x2(r, simde_vld1q_s64(test_vec[3].r));

    a = simde_vld1q_s64(test_vec[4].a);
    b = simde_vld1_s32(test_vec[4].b);
    v = simde_vld1q_s32(test_vec[4].v);
    r = simde_vmlal_laneq_s32(a, b, v, 3);
    simde_test_arm_neon_assert_equal_i64x2(r, simde_vld1q_s64(test_vec[4].r));

    a = simde_vld1q_s64(test_vec[5].a);
    b = simde_vld1_s32(test_vec[5].b);
    v = simde_vld1q_s32(test_vec[5].v);
    r = simde_vmlal_laneq_s32(a, b, v, 0);
    simde_test_arm_neon_assert_equal_i64x2(r, simde_vld1q_s64(test_vec[5].r));

    a = simde_vld1q_s64(test_vec[6].a);
    b = simde_vld1_s32(test_vec[6].b);
    v = simde_vld1q_s32(test_vec[6].v);
    r = simde_vmlal_laneq_s32(a, b, v, 0);
    simde_test_arm_neon_assert_equal_i64x2(r, simde_vld1q_s64(test_vec[6].r));

    a = simde_vld1q_s64(test_vec[7].a);
    b = simde_vld1_s32(test_vec[7].b);
    v = simde_vld1q_s32(test_vec[7].v);
    r = simde_vmlal_laneq_s32(a, b, v, 3);
    simde_test_arm_neon_assert_equal_i64x2(r, simde_vld1q_s64(test_vec[7].r));

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int64x2_t a = simde_test_arm_neon_random_i64x2();
    simde_int32x2_t b = simde_test_arm_neon_random_i32x2();
    simde_int32x4_t v = simde_test_arm_neon_random_i32x4();
    int8_t lane = simde_test_codegen_random_i8() & 3;
    simde_int64x2_t r;

    SIMDE_CONSTIFY_4_(simde_vmlal_laneq_s32, r, (HEDLEY_UNREACHABLE(), simde_vdupq_n_s64(0)), lane, a, b, v);

    simde_test_arm_neon_write_i64x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i32x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i32x4(2, v, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, lane, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vmlal_laneq_u16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint32_t a[4];
    uint16_t b[4];
    uint16_t v[8];
    uint32_t r[4];
  } test_vec[] = {
    { { UINT32_C(2469013573), UINT32_C(3691438825), UINT32_C(1263744283), UINT32_C( 183840001) },
      { UINT16_C(54255), UINT16_C(12594), UINT16_C(24506), UINT16_C(23954) },
      { UINT16_C(26117), UINT16_C(17591), UINT16_C(58302), UINT16_C(  800), UINT16_C(18955), UINT16_C(62615), UINT16_C(40236), UINT16_C(18384) },
      // INT32_C(         2),
      { UINT32_C(1337221287), UINT32_C( 130726917), UINT32_C(2692493095), UINT32_C(1580406109) } },
    { { UINT32_C(1372820260), UINT32_C(1530977672), UINT32_C(1846898959), UINT32_C(1769173763) },
      { UINT16_C(47146), UINT16_C( 3367), UINT16_C(11224), UINT16_C( 8728) },
      { UINT16_C( 3266), UINT16_C(24399), UINT16_C(38621), UINT16_C(  305), UINT16_C( 1065), UINT16_C(45394), UINT16_C(37601), UINT16_C(61453) },
      // INT32_C(         4),
      { UINT32_C(1423030750), UINT32_C(1534563527), UINT32_C(1858852519), UINT32_C(1778469083) } },
    { { UINT32_C(2500288034), UINT32_C(2311025105), UINT32_C(3277966488), UINT32_C(4052059364) },
      { UINT16_C(58579), UINT16_C(27086), UINT16_C(53013), UINT16_C( 6547) },
      { UINT16_C(17441), UINT16_C(46074), UINT16_C(59985), UINT16_C(29879), UINT16_C(48968), UINT16_C( 6665), UINT16_C(51504), UINT16_C(51363) },
      // INT32_C(         5),
      { UINT32_C(2890717069), UINT32_C(2491553295), UINT32_C(3631298133), UINT32_C(4095695119) } },
    { { UINT32_C(2306509829), UINT32_C(4133251857), UINT32_C( 134989113), UINT32_C(2636719448) },
      { UINT16_C(56351), UINT16_C( 2798), UINT16_C(25236), UINT16_C(21330) },
      { UINT16_C(27756), UINT16_C(13699), UINT16_C(19216), UINT16_C( 5578), UINT16_C(17623), UINT16_C(59806), UINT16_C(64175), UINT16_C(59615) },
      // INT32_C(         7),
      { UINT32_C(1370907398), UINT32_C(   5087331), UINT32_C(1639433253), UINT32_C(3908307398) } },
    { { UINT32_C( 253292778), UINT32_C(4130321689), UINT32_C( 109722019), UINT32_C(4168277387) },
      { UINT16_C(42848), UINT16_C(43784), UINT16_C( 7537), UINT16_C(46723) },
      { UINT16_C(27835), UINT16_C(46437), UINT16_C(20043), UINT16_C(13684), UINT16_C(35902), UINT16_C(22597), UINT16_C(29761), UINT16_C(58702) },
      // INT32_C(         5),
      { UINT32_C(1221529034), UINT32_C( 824741441), UINT32_C( 280035608), UINT32_C( 929109722) } },
    { { UINT32_C(3040406488), UINT32_C(  68497501), UINT32_C(1433780280), UINT32_C(2937072451) },
      { UINT16_C(50577), UINT16_C(57338), UINT16_C(12346), UINT16_C(50717) },
      { UINT16_C(30069), UINT16_C(59656), UINT16_C(60867), UINT16_C(39830), UINT16_C(52952), UINT16_C(13648), UINT16_C(26111), UINT16_C(14137) },
      // INT32_C(         6),
      { UINT32_C(  66055239), UINT32_C(1565650019), UINT32_C(1756146686), UINT32_C(4261344038) } },
    { { UINT32_C(3664350638), UINT32_C(1667963293), UINT32_C(1134381587), UINT32_C(3719848807) },
      { UINT16_C(41323), UINT16_C(22688), UINT16_C(15415), UINT16_C( 1584) },
      { UINT16_C(25996), UINT16_C(61957), UINT16_C(15518), UINT16_C(19736), UINT16_C(33225), UINT16_C(26407), UINT16_C(37530), UINT16_C(44746) },
      // INT32_C(         4),
      { UINT32_C( 742340017), UINT32_C(2421772093), UINT32_C(1646544962), UINT32_C(3772477207) } },
    { { UINT32_C(3393450343), UINT32_C(1261838506), UINT32_C(4253257409), UINT32_C( 612993471) },
      { UINT16_C(31630), UINT16_C(51907), UINT16_C( 4243), UINT16_C( 5524) },
      { UINT16_C(64311), UINT16_C(51631), UINT16_C(24005), UINT16_C(11429), UINT16_C(59471), UINT16_C(63990), UINT16_C(11273), UINT16_C(51780) },
      // INT32_C(         3),
      { UINT32_C(3754949613), UINT32_C(1855083609), UINT32_C(   6783360), UINT32_C( 676127267) } }
  };

    simde_uint32x4_t a, r;
    simde_uint16x4_t b;
    simde_uint16x8_t v;

    a = simde_vld1q_u32(test_vec[0].a);
    b = simde_vld1_u16(test_vec[0].b);
    v = simde_vld1q_u16(test_vec[0].v);
    r = simde_vmlal_laneq_u16(a, b, v, 2);
    simde_test_arm_neon_assert_equal_u32x4(r, simde_vld1q_u32(test_vec[0].r));

    a = simde_vld1q_u32(test_vec[1].a);
    b = simde_vld1_u16(test_vec[1].b);
    v = simde_vld1q_u16(test_vec[1].v);
    r = simde_vmlal_laneq_u16(a, b, v, 4);
    simde_test_arm_neon_assert_equal_u32x4(r, simde_vld1q_u32(test_vec[1].r));

    a = simde_vld1q_u32(test_vec[2].a);
    b = simde_vld1_u16(test_vec[2].b);
    v = simde_vld1q_u16(test_vec[2].v);
    r = simde_vmlal_laneq_u16(a, b, v, 5);
    simde_test_arm_neon_assert_equal_u32x4(r, simde_vld1q_u32(test_vec[2].r));

    a = simde_vld1q_u32(test_vec[3].a);
    b = simde_vld1_u16(test_vec[3].b);
    v = simde_vld1q_u16(test_vec[3].v);
    r = simde_vmlal_laneq_u16(a, b, v, 7);
    simde_test_arm_neon_assert_equal_u32x4(r, simde_vld1q_u32(test_vec[3].r));

    a = simde_vld1q_u32(test_vec[4].a);
    b = simde_vld1_u16(test_vec[4].b);
    v = simde_vld1q_u16(test_vec[4].v);
    r = simde_vmlal_laneq_u16(a, b, v, 5);
    simde_test_arm_neon_assert_equal_u32x4(r, simde_vld1q_u32(test_vec[4].r));

    a = simde_vld1q_u32(test_vec[5].a);
    b = simde_vld1_u16(test_vec[5].b);
    v = simde_vld1q_u16(test_vec[5].v);
    r = simde_vmlal_laneq_u16(a, b, v, 6);
    simde_test_arm_neon_assert_equal_u32x4(r, simde_vld1q_u32(test_vec[5].r));

    a = simde_vld1q_u32(test_vec[6].a);
    b = simde_vld1_u16(test_vec[6].b);
    v = simde_vld1q_u16(test_vec[6].v);
    r = simde_vmlal_laneq_u16(a, b, v, 4);
    simde_test_arm_neon_assert_equal_u32x4(r, simde_vld1q_u32(test_vec[6].r));

    a = simde_vld1q_u32(test_vec[7].a);
    b = simde_vld1_u16(test_vec[7].b);
    v = simde_vld1q_u16(test_vec[7].v);
    r = simde_vmlal_laneq_u16(a, b, v, 3);
    simde_test_arm_neon_assert_equal_u32x4(r, simde_vld1q_u32(test_vec[7].r));

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint32x4_t a = simde_test_arm_neon_random_u32x4();
    simde_uint16x4_t b = simde_test_arm_neon_random_u16x4();
    simde_uint16x8_t v = simde_test_arm_neon_random_u16x8();
    uint8_t lane = simde_test_codegen_random_u8() & 7;
    simde_uint32x4_t r;

    SIMDE_CONSTIFY_8_(simde_vmlal_laneq_u16, r, (HEDLEY_UNREACHABLE(), simde_vdupq_n_u32(0)), lane, a, b, v);

    simde_test_arm_neon_write_u32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u16x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u16x8(2, v, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, lane, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vmlal_laneq_u32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint64_t a[2];
    uint32_t b[2];
    uint32_t v[4];
    uint64_t r[2];
  } test_vec[] = {
    { { UINT64_C(14762410696351860679), UINT64_C( 4082640869455276385) },
      { UINT32_C(2180870436), UINT32_C(4291832086) },
      { UINT32_C(1275644191), UINT32_C(3574059534), UINT32_C(3911614873), UINT32_C(2176123935) },
      // INT32_C(         1),
      { UINT64_C( 4110227396846845887), UINT64_C(  975160181041132693) } },
    { { UINT64_C(  913424350855229973), UINT64_C(14512888279023693599) },
      { UINT32_C(4241994794), UINT32_C(1016442043) },
      { UINT32_C(3613097682), UINT32_C(1233443892), UINT32_C(1792176079), UINT32_C(2977333393) },
      // INT32_C(         3),
      { UINT64_C(13543257103963586015), UINT64_C(17539175115696735498) } },
    { { UINT64_C( 1577798506107566489), UINT64_C(17711826614688473422) },
      { UINT32_C(1143579752), UINT32_C(2551411241) },
      { UINT32_C(3291053380), UINT32_C(2373180148), UINT32_C( 893985492), UINT32_C(3897241241) },
      // INT32_C(         0),
      { UINT64_C( 5341380514226728249), UINT64_C( 7661913129441966386) } },
    { { UINT64_C( 6165563886394598171), UINT64_C( 7303456406777025700) },
      { UINT32_C( 442048319), UINT32_C(3052332947) },
      { UINT32_C(1582179120), UINT32_C(2322478702), UINT32_C(3400725785), UINT32_C( 354370160) },
      // INT32_C(         2),
      { UINT64_C( 7668849003033803586), UINT64_C(17683603764044964095) } },
    { { UINT64_C(12029788084368190365), UINT64_C( 2221663276464934077) },
      { UINT32_C(1938567996), UINT32_C(2525763233) },
      { UINT32_C( 168253128), UINT32_C( 304159861), UINT32_C(3469025095), UINT32_C(1098168451) },
      // INT32_C(         0),
      { UINT64_C(12355958213535881853), UINT64_C( 2646630841004576901) } },
    { { UINT64_C(17138410700528412077), UINT64_C( 3262899537534929513) },
      { UINT32_C(1218663212), UINT32_C(2475668852) },
      { UINT32_C( 857169275), UINT32_C(2130139345), UINT32_C(4145657405), UINT32_C(4259639699) },
      // INT32_C(         3),
      { UINT64_C( 3882732824364913649), UINT64_C(13808356861091885061) } },
    { { UINT64_C( 1784622569749642611), UINT64_C(17947724792652893411) },
      { UINT32_C(2412398135), UINT32_C(4107028798) },
      { UINT32_C(1401472098), UINT32_C( 462390696), UINT32_C(3350438146), UINT32_C(3303045089) },
      // INT32_C(         3),
      { UINT64_C( 9752882382274151626), UINT64_C(13066682020558814817) } },
    { { UINT64_C(13241454201065659756), UINT64_C(16397299613393310434) },
      { UINT32_C(4136362353), UINT32_C( 318285680) },
      { UINT32_C(3539189850), UINT32_C( 206944416), UINT32_C(2241426453), UINT32_C(1866226828) },
      // INT32_C(         3),
      { UINT64_C( 2514100520853914424), UINT64_C(16991292888377533474) } }
  };

    simde_uint64x2_t a, r;
    simde_uint32x2_t b;
    simde_uint32x4_t v;

    a = simde_vld1q_u64(test_vec[0].a);
    b = simde_vld1_u32(test_vec[0].b);
    v = simde_vld1q_u32(test_vec[0].v);
    r = simde_vmlal_laneq_u32(a, b, v, 1);
    simde_test_arm_neon_assert_equal_u64x2(r, simde_vld1q_u64(test_vec[0].r));

    a = simde_vld1q_u64(test_vec[1].a);
    b = simde_vld1_u32(test_vec[1].b);
    v = simde_vld1q_u32(test_vec[1].v);
    r = simde_vmlal_laneq_u32(a, b, v, 3);
    simde_test_arm_neon_assert_equal_u64x2(r, simde_vld1q_u64(test_vec[1].r));

    a = simde_vld1q_u64(test_vec[2].a);
    b = simde_vld1_u32(test_vec[2].b);
    v = simde_vld1q_u32(test_vec[2].v);
    r = simde_vmlal_laneq_u32(a, b, v, 0);
    simde_test_arm_neon_assert_equal_u64x2(r, simde_vld1q_u64(test_vec[2].r));

    a = simde_vld1q_u64(test_vec[3].a);
    b = simde_vld1_u32(test_vec[3].b);
    v = simde_vld1q_u32(test_vec[3].v);
    r = simde_vmlal_laneq_u32(a, b, v, 2);
    simde_test_arm_neon_assert_equal_u64x2(r, simde_vld1q_u64(test_vec[3].r));

    a = simde_vld1q_u64(test_vec[4].a);
    b = simde_vld1_u32(test_vec[4].b);
    v = simde_vld1q_u32(test_vec[4].v);
    r = simde_vmlal_laneq_u32(a, b, v, 0);
    simde_test_arm_neon_assert_equal_u64x2(r, simde_vld1q_u64(test_vec[4].r));

    a = simde_vld1q_u64(test_vec[5].a);
    b = simde_vld1_u32(test_vec[5].b);
    v = simde_vld1q_u32(test_vec[5].v);
    r = simde_vmlal_laneq_u32(a, b, v, 3);
    simde_test_arm_neon_assert_equal_u64x2(r, simde_vld1q_u64(test_vec[5].r));

    a = simde_vld1q_u64(test_vec[6].a);
    b = simde_vld1_u32(test_vec[6].b);
    v = simde_vld1q_u32(test_vec[6].v);
    r = simde_vmlal_laneq_u32(a, b, v, 3);
    simde_test_arm_neon_assert_equal_u64x2(r, simde_vld1q_u64(test_vec[6].r));

    a = simde_vld1q_u64(test_vec[7].a);
    b = simde_vld1_u32(test_vec[7].b);
    v = simde_vld1q_u32(test_vec[7].v);
    r = simde_vmlal_laneq_u32(a, b, v, 3);
    simde_test_arm_neon_assert_equal_u64x2(r, simde_vld1q_u64(test_vec[7].r));

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint64x2_t a = simde_test_arm_neon_random_u64x2();
    simde_uint32x2_t b = simde_test_arm_neon_random_u32x2();
    simde_uint32x4_t v = simde_test_arm_neon_random_u32x4();
    uint8_t lane = simde_test_codegen_random_u8() & 3;
    simde_uint64x2_t r;

    SIMDE_CONSTIFY_4_(simde_vmlal_laneq_u32, r, (HEDLEY_UNREACHABLE(), simde_vdupq_n_u64(0)), lane, a, b, v);

    simde_test_arm_neon_write_u64x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u32x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x4(2, v, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, lane, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(vmlal_lane_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vmlal_lane_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vmlal_lane_u16)
SIMDE_TEST_FUNC_LIST_ENTRY(vmlal_lane_u32)
SIMDE_TEST_FUNC_LIST_ENTRY(vmlal_laneq_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vmlal_laneq_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vmlal_laneq_u16)
SIMDE_TEST_FUNC_LIST_ENTRY(vmlal_laneq_u32)
SIMDE_TEST_FUNC_LIST_END

#include "test-neon-footer.h"
