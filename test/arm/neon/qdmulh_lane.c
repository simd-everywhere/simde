#define SIMDE_TEST_ARM_NEON_INSN qdmulh_lane

#include "test-neon.h"
#include "../../../simde/arm/neon/qdmulh_lane.h"

static int
test_simde_vqdmulh_lane_s16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int16_t a[8];
    int16_t v[8];
    int16_t r0[8];
    int16_t r1[8];
    int16_t r2[8];
    int16_t r3[8];
  } test_vec[] = {
    { { -INT16_C( 14783), -INT16_C( 28059),  INT16_C( 30585),  INT16_C( 30679) },
      { -INT16_C(  4151), -INT16_C( 25540), -INT16_C( 20962),  INT16_C( 16692) },
      {  INT16_C(  1872),  INT16_C(  3554), -INT16_C(  3875), -INT16_C(  3887) },
      {  INT16_C( 11522),  INT16_C( 21869), -INT16_C( 23839), -INT16_C( 23912) },
      {  INT16_C(  9456),  INT16_C( 17949), -INT16_C( 19566), -INT16_C( 19626) },
      { -INT16_C(  7531), -INT16_C( 14294),  INT16_C( 15579),  INT16_C( 15627) } },
    { {  INT16_C( 28381), -INT16_C( 26183),  INT16_C( 16290),  INT16_C( 11688) },
      { -INT16_C( 17231),  INT16_C(  9194), -INT16_C( 22625), -INT16_C(  7961) },
      { -INT16_C( 14925),  INT16_C( 13768), -INT16_C(  8567), -INT16_C(  6147) },
      {  INT16_C(  7963), -INT16_C(  7347),  INT16_C(  4570),  INT16_C(  3279) },
      { -INT16_C( 19596),  INT16_C( 18078), -INT16_C( 11248), -INT16_C(  8071) },
      { -INT16_C(  6896),  INT16_C(  6361), -INT16_C(  3958), -INT16_C(  2840) } },
    { {  INT16_C( 19566), -INT16_C(  6286),  INT16_C( 18883), -INT16_C( 29601) },
      { -INT16_C( 25799),  INT16_C( 22313),  INT16_C( 23881),  INT16_C(  9881) },
      { -INT16_C( 15405),  INT16_C(  4949), -INT16_C( 14868),  INT16_C( 23305) },
      {  INT16_C( 13323), -INT16_C(  4281),  INT16_C( 12858), -INT16_C( 20157) },
      {  INT16_C( 14259), -INT16_C(  4582),  INT16_C( 13761), -INT16_C( 21573) },
      {  INT16_C(  5900), -INT16_C(  1896),  INT16_C(  5694), -INT16_C(  8927) } },
    { {  INT16_C( 21195),  INT16_C( 28096),  INT16_C( 26769),  INT16_C( 17051) },
      { -INT16_C( 31451), -INT16_C( 15258),  INT16_C( 19757), -INT16_C( 25692) },
      { -INT16_C( 20344), -INT16_C( 26967), -INT16_C( 25694), -INT16_C( 16366) },
      { -INT16_C(  9870), -INT16_C( 13083), -INT16_C( 12465), -INT16_C(  7940) },
      {  INT16_C( 12779),  INT16_C( 16940),  INT16_C( 16139),  INT16_C( 10280) },
      { -INT16_C( 16619), -INT16_C( 22029), -INT16_C( 20989), -INT16_C( 13369) } },
    { {  INT16_C(  6041),  INT16_C( 23682), -INT16_C(  7840), -INT16_C( 26135) },
      {  INT16_C(  4733), -INT16_C( 14607), -INT16_C( 30097),  INT16_C( 15341) },
      {  INT16_C(   872),  INT16_C(  3420), -INT16_C(  1133), -INT16_C(  3775) },
      { -INT16_C(  2693), -INT16_C( 10557),  INT16_C(  3494),  INT16_C( 11650) },
      { -INT16_C(  5549), -INT16_C( 21752),  INT16_C(  7200),  INT16_C( 24004) },
      {  INT16_C(  2828),  INT16_C( 11087), -INT16_C(  3671), -INT16_C( 12236) } },
    { { -INT16_C( 21028),  INT16_C( 28328),  INT16_C( 17173),  INT16_C( 15024) },
      {  INT16_C(  5833), -INT16_C(  2306), -INT16_C( 23709), -INT16_C(   879) },
      { -INT16_C(  3744),  INT16_C(  5042),  INT16_C(  3056),  INT16_C(  2674) },
      {  INT16_C(  1479), -INT16_C(  1994), -INT16_C(  1209), -INT16_C(  1058) },
      {  INT16_C( 15214), -INT16_C( 20497), -INT16_C( 12426), -INT16_C( 10871) },
      {  INT16_C(   564), -INT16_C(   760), -INT16_C(   461), -INT16_C(   404) } },
    { {  INT16_C(  5050),  INT16_C(  6745),  INT16_C( 17141),  INT16_C( 29364) },
      { -INT16_C( 23212), -INT16_C( 15560),  INT16_C(  9519),  INT16_C(  3070) },
      { -INT16_C(  3578), -INT16_C(  4778), -INT16_C( 12143), -INT16_C( 20801) },
      { -INT16_C(  2399), -INT16_C(  3203), -INT16_C(  8140), -INT16_C( 13944) },
      {  INT16_C(  1467),  INT16_C(  1959),  INT16_C(  4979),  INT16_C(  8530) },
      {  INT16_C(   473),  INT16_C(   631),  INT16_C(  1605),  INT16_C(  2751) } },
    { { -INT16_C( 22574), -INT16_C(  6023),  INT16_C( 10986), -INT16_C( 19678) },
      {  INT16_C(  8512), -INT16_C( 23383),  INT16_C( 15044),  INT16_C( 32416) },
      { -INT16_C(  5864), -INT16_C(  1565),  INT16_C(  2853), -INT16_C(  5112) },
      {  INT16_C( 16108),  INT16_C(  4297), -INT16_C(  7840),  INT16_C( 14042) },
      { -INT16_C( 10364), -INT16_C(  2766),  INT16_C(  5043), -INT16_C(  9035) },
      { -INT16_C( 22332), -INT16_C(  5959),  INT16_C( 10867), -INT16_C( 19467) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x4_t a = simde_vld1_s16(test_vec[i].a);
    simde_int16x4_t v = simde_vld1_s16(test_vec[i].v);
    simde_int16x4_t r0 = simde_vqdmulh_lane_s16(a, v, 0);
    simde_int16x4_t r1 = simde_vqdmulh_lane_s16(a, v, 1);
    simde_int16x4_t r2 = simde_vqdmulh_lane_s16(a, v, 2);
    simde_int16x4_t r3 = simde_vqdmulh_lane_s16(a, v, 3);

    simde_test_arm_neon_assert_equal_i16x4(r0, simde_vld1_s16(test_vec[i].r0));
    simde_test_arm_neon_assert_equal_i16x4(r1, simde_vld1_s16(test_vec[i].r1));
    simde_test_arm_neon_assert_equal_i16x4(r2, simde_vld1_s16(test_vec[i].r2));
    simde_test_arm_neon_assert_equal_i16x4(r3, simde_vld1_s16(test_vec[i].r3));
  }

  return 0;
#else
  for (int i = 0 ; i < 8 ; i++) {
    simde_int16x4_t a = simde_test_arm_neon_random_i16x4();
    simde_int16x4_t v = simde_test_arm_neon_random_i16x4();
    simde_int16x4_t r0 = simde_vqdmulh_lane_s16(a, v, 0);
    simde_int16x4_t r1 = simde_vqdmulh_lane_s16(a, v, 1);
    simde_int16x4_t r2 = simde_vqdmulh_lane_s16(a, v, 2);
    simde_int16x4_t r3 = simde_vqdmulh_lane_s16(a, v, 3);

    simde_test_arm_neon_write_i16x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i16x4(2, v, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i16x4(2, r0, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i16x4(2, r1, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i16x4(2, r2, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i16x4(2, r3, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vqdmulh_lane_s32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int32_t a[8];
    int32_t v[8];
    int32_t r0[8];
    int32_t r1[8];
  } test_vec[] = {
    { {  INT32_C(  1134098766), -INT32_C(  1883943877) },
      {  INT32_C(   542371313), -INT32_C(   450080493) },
      {  INT32_C(   286429485), -INT32_C(   475811360) },
      { -INT32_C(   237690160),  INT32_C(   394846493) } },
    { { -INT32_C(   473061896),  INT32_C(   278327503) },
      { -INT32_C(   709607407), -INT32_C(   934062982) },
      {  INT32_C(   156317011), -INT32_C(    91969622) },
      {  INT32_C(   205761569), -INT32_C(   121060488) } },
    { { -INT32_C(  1995707570),  INT32_C(   689553464) },
      { -INT32_C(  1052087122), -INT32_C(  1230604611) },
      {  INT32_C(   977729555), -INT32_C(   337823443) },
      {  INT32_C(  1143630099), -INT32_C(   395145115) } },
    { { -INT32_C(   342264805),  INT32_C(  1979395940) },
      { -INT32_C(   364204177),  INT32_C(  1370660099) },
      {  INT32_C(    58046668), -INT32_C(   335697211) },
      { -INT32_C(   218455080),  INT32_C(  1263375876) } },
    { { -INT32_C(  1059340664),  INT32_C(   753595518) },
      {  INT32_C(   502084704), -INT32_C(   975989590) },
      { -INT32_C(   247675341),  INT32_C(   176191694) },
      {  INT32_C(   481449747), -INT32_C(   342494520) } },
    { {  INT32_C(  1823501320),  INT32_C(   199338908) },
      {  INT32_C(  1593125722),  INT32_C(  1353689288) },
      {  INT32_C(  1352777172),  INT32_C(   147880959) },
      {  INT32_C(  1149463562),  INT32_C(   125655412) } },
    { { -INT32_C(   468612506), -INT32_C(   569246850) },
      { -INT32_C(   637731281), -INT32_C(  1700868206) },
      {  INT32_C(   139162341),  INT32_C(   169047397) },
      {  INT32_C(   371154450),  INT32_C(   450859716) } },
    { { -INT32_C(   670675140),  INT32_C(  1440999418) },
      { -INT32_C(   625747694), -INT32_C(   416587135) },
      {  INT32_C(   195425666), -INT32_C(   419887744) },
      {  INT32_C(   130103265), -INT32_C(   279537318) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x2_t a = simde_vld1_s32(test_vec[i].a);
    simde_int32x2_t v = simde_vld1_s32(test_vec[i].v);
    simde_int32x2_t r0 = simde_vqdmulh_lane_s32(a, v, 0);
    simde_int32x2_t r1 = simde_vqdmulh_lane_s32(a, v, 1);

    simde_test_arm_neon_assert_equal_i32x2(r0, simde_vld1_s32(test_vec[i].r0));
    simde_test_arm_neon_assert_equal_i32x2(r1, simde_vld1_s32(test_vec[i].r1));
  }

  return 0;
#else
  for (int i = 0 ; i < 8 ; i++) {
    simde_int32x2_t a = simde_test_arm_neon_random_i32x2();
    simde_int32x2_t v = simde_test_arm_neon_random_i32x2();
    simde_int32x2_t r0 = simde_vqdmulh_lane_s32(a, v, 0);
    simde_int32x2_t r1 = simde_vqdmulh_lane_s32(a, v, 1);

    simde_test_arm_neon_write_i32x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i32x2(2, v, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i32x2(2, r0, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i32x2(2, r1, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vqdmulhq_lane_s16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int16_t a[8];
    int16_t v[8];
    int16_t r0[8];
    int16_t r1[8];
    int16_t r2[8];
    int16_t r3[8];
  } test_vec[] = {
    { { -INT16_C( 31657),  INT16_C(  6527), -INT16_C( 24358),  INT16_C( 16842),  INT16_C(  4390),  INT16_C(  2405), -INT16_C( 13433),  INT16_C(  7827) },
      {  INT16_C( 27684), -INT16_C( 22104),  INT16_C( 32119), -INT16_C( 32502) },
      { -INT16_C( 26746),  INT16_C(  5514), -INT16_C( 20579),  INT16_C( 14228),  INT16_C(  3708),  INT16_C(  2031), -INT16_C( 11349),  INT16_C(  6612) },
      {  INT16_C( 21354), -INT16_C(  4403),  INT16_C( 16430), -INT16_C( 11361), -INT16_C(  2962), -INT16_C(  1623),  INT16_C(  9061), -INT16_C(  5280) },
      { -INT16_C( 31031),  INT16_C(  6397), -INT16_C( 23876),  INT16_C( 16508),  INT16_C(  4303),  INT16_C(  2357), -INT16_C( 13167),  INT16_C(  7671) },
      {  INT16_C( 31400), -INT16_C(  6475),  INT16_C( 24160), -INT16_C( 16706), -INT16_C(  4355), -INT16_C(  2386),  INT16_C( 13323), -INT16_C(  7764) } },
    { {  INT16_C(  5524), -INT16_C( 14692), -INT16_C(  9334), -INT16_C(  7836), -INT16_C(  7329),  INT16_C( 14843), -INT16_C( 14973), -INT16_C( 22149) },
      { -INT16_C(  7978),  INT16_C( 23987),  INT16_C( 18091), -INT16_C( 12420) },
      { -INT16_C(  1345),  INT16_C(  3577),  INT16_C(  2272),  INT16_C(  1907),  INT16_C(  1784), -INT16_C(  3614),  INT16_C(  3645),  INT16_C(  5392) },
      {  INT16_C(  4043), -INT16_C( 10755), -INT16_C(  6833), -INT16_C(  5737), -INT16_C(  5366),  INT16_C( 10865), -INT16_C( 10961), -INT16_C( 16214) },
      {  INT16_C(  3049), -INT16_C(  8112), -INT16_C(  5154), -INT16_C(  4327), -INT16_C(  4047),  INT16_C(  8194), -INT16_C(  8267), -INT16_C( 12229) },
      { -INT16_C(  2094),  INT16_C(  5568),  INT16_C(  3537),  INT16_C(  2970),  INT16_C(  2777), -INT16_C(  5626),  INT16_C(  5675),  INT16_C(  8395) } },
    { {  INT16_C(  9394),  INT16_C( 10616), -INT16_C( 31838),  INT16_C( 13994),  INT16_C( 18328),  INT16_C(  8956),  INT16_C( 24866), -INT16_C( 32252) },
      { -INT16_C(   188), -INT16_C( 14149),  INT16_C( 14020), -INT16_C( 25999) },
      { -INT16_C(    54), -INT16_C(    61),  INT16_C(   182), -INT16_C(    81), -INT16_C(   106), -INT16_C(    52), -INT16_C(   143),  INT16_C(   185) },
      { -INT16_C(  4057), -INT16_C(  4584),  INT16_C( 13747), -INT16_C(  6043), -INT16_C(  7914), -INT16_C(  3868), -INT16_C( 10737),  INT16_C( 13926) },
      {  INT16_C(  4019),  INT16_C(  4542), -INT16_C( 13623),  INT16_C(  5987),  INT16_C(  7841),  INT16_C(  3831),  INT16_C( 10639), -INT16_C( 13800) },
      { -INT16_C(  7454), -INT16_C(  8424),  INT16_C( 25261), -INT16_C( 11104), -INT16_C( 14542), -INT16_C(  7106), -INT16_C( 19730),  INT16_C( 25589) } },
    { {  INT16_C(  9239), -INT16_C( 15625),  INT16_C( 29547),  INT16_C(  7570),  INT16_C(  2712),  INT16_C( 14919), -INT16_C(  3699),  INT16_C(  9840) },
      {  INT16_C( 27704),  INT16_C( 23368),  INT16_C( 19661),  INT16_C(  4829) },
      {  INT16_C(  7811), -INT16_C( 13211),  INT16_C( 24980),  INT16_C(  6400),  INT16_C(  2292),  INT16_C( 12613), -INT16_C(  3128),  INT16_C(  8319) },
      {  INT16_C(  6588), -INT16_C( 11143),  INT16_C( 21070),  INT16_C(  5398),  INT16_C(  1934),  INT16_C( 10639), -INT16_C(  2638),  INT16_C(  7017) },
      {  INT16_C(  5543), -INT16_C(  9376),  INT16_C( 17728),  INT16_C(  4542),  INT16_C(  1627),  INT16_C(  8951), -INT16_C(  2220),  INT16_C(  5904) },
      {  INT16_C(  1361), -INT16_C(  2303),  INT16_C(  4354),  INT16_C(  1115),  INT16_C(   399),  INT16_C(  2198), -INT16_C(   546),  INT16_C(  1450) } },
    { { -INT16_C( 26549),  INT16_C(  4058),  INT16_C( 19407), -INT16_C(  6487), -INT16_C( 24208), -INT16_C(  9304),  INT16_C( 14868), -INT16_C( 21256) },
      {  INT16_C( 16197), -INT16_C( 11546),  INT16_C( 22065),  INT16_C( 27128) },
      { -INT16_C( 13123),  INT16_C(  2005),  INT16_C(  9592), -INT16_C(  3207), -INT16_C( 11966), -INT16_C(  4599),  INT16_C(  7349), -INT16_C( 10507) },
      {  INT16_C(  9354), -INT16_C(  1430), -INT16_C(  6839),  INT16_C(  2285),  INT16_C(  8529),  INT16_C(  3278), -INT16_C(  5239),  INT16_C(  7489) },
      { -INT16_C( 17878),  INT16_C(  2732),  INT16_C( 13068), -INT16_C(  4369), -INT16_C( 16301), -INT16_C(  6266),  INT16_C( 10011), -INT16_C( 14314) },
      { -INT16_C( 21980),  INT16_C(  3359),  INT16_C( 16066), -INT16_C(  5371), -INT16_C( 20042), -INT16_C(  7703),  INT16_C( 12308), -INT16_C( 17598) } },
    { {  INT16_C( 16835), -INT16_C( 28476), -INT16_C( 24179), -INT16_C(  9822),  INT16_C( 31802),  INT16_C(  2536), -INT16_C( 27960),  INT16_C( 14575) },
      { -INT16_C( 26829),  INT16_C( 18195),  INT16_C(  3026),  INT16_C(  6132) },
      { -INT16_C( 13784),  INT16_C( 23314),  INT16_C( 19796),  INT16_C(  8041), -INT16_C( 26039), -INT16_C(  2077),  INT16_C( 22892), -INT16_C( 11934) },
      {  INT16_C(  9347), -INT16_C( 15812), -INT16_C( 13426), -INT16_C(  5454),  INT16_C( 17658),  INT16_C(  1408), -INT16_C( 15526),  INT16_C(  8093) },
      {  INT16_C(  1554), -INT16_C(  2630), -INT16_C(  2233), -INT16_C(   908),  INT16_C(  2936),  INT16_C(   234), -INT16_C(  2582),  INT16_C(  1345) },
      {  INT16_C(  3150), -INT16_C(  5329), -INT16_C(  4525), -INT16_C(  1839),  INT16_C(  5951),  INT16_C(   474), -INT16_C(  5233),  INT16_C(  2727) } },
    { { -INT16_C(  9653),  INT16_C( 31977), -INT16_C(  7631), -INT16_C(  2843), -INT16_C( 21981), -INT16_C( 20348),  INT16_C( 10059), -INT16_C( 31351) },
      {  INT16_C( 29347),  INT16_C( 27534),  INT16_C( 32004),  INT16_C( 14243) },
      { -INT16_C(  8646),  INT16_C( 28638), -INT16_C(  6835), -INT16_C(  2547), -INT16_C( 19687), -INT16_C( 18224),  INT16_C(  9008), -INT16_C( 28078) },
      { -INT16_C(  8112),  INT16_C( 26869), -INT16_C(  6413), -INT16_C(  2389), -INT16_C( 18470), -INT16_C( 17098),  INT16_C(  8452), -INT16_C( 26344) },
      { -INT16_C(  9428),  INT16_C( 31231), -INT16_C(  7454), -INT16_C(  2777), -INT16_C( 21469), -INT16_C( 19874),  INT16_C(  9824), -INT16_C( 30621) },
      { -INT16_C(  4196),  INT16_C( 13899), -INT16_C(  3317), -INT16_C(  1236), -INT16_C(  9555), -INT16_C(  8845),  INT16_C(  4372), -INT16_C( 13628) } },
    { { -INT16_C( 18923), -INT16_C(  6274),  INT16_C( 29378),  INT16_C(  3582), -INT16_C(  6323),  INT16_C( 32393),  INT16_C( 28361), -INT16_C(  5006) },
      { -INT16_C(  2536),  INT16_C( 25757),  INT16_C(  9757), -INT16_C( 15895) },
      {  INT16_C(  1464),  INT16_C(   485), -INT16_C(  2274), -INT16_C(   278),  INT16_C(   489), -INT16_C(  2507), -INT16_C(  2195),  INT16_C(   387) },
      { -INT16_C( 14875), -INT16_C(  4932),  INT16_C( 23092),  INT16_C(  2815), -INT16_C(  4971),  INT16_C( 25462),  INT16_C( 22292), -INT16_C(  3935) },
      { -INT16_C(  5635), -INT16_C(  1869),  INT16_C(  8747),  INT16_C(  1066), -INT16_C(  1883),  INT16_C(  9645),  INT16_C(  8444), -INT16_C(  1491) },
      {  INT16_C(  9179),  INT16_C(  3043), -INT16_C( 14251), -INT16_C(  1738),  INT16_C(  3067), -INT16_C( 15714), -INT16_C( 13758),  INT16_C(  2428) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x8_t a = simde_vld1q_s16(test_vec[i].a);
    simde_int16x4_t v = simde_vld1_s16(test_vec[i].v);
    simde_int16x8_t r0 = simde_vqdmulhq_lane_s16(a, v, 0);
    simde_int16x8_t r1 = simde_vqdmulhq_lane_s16(a, v, 1);
    simde_int16x8_t r2 = simde_vqdmulhq_lane_s16(a, v, 2);
    simde_int16x8_t r3 = simde_vqdmulhq_lane_s16(a, v, 3);

    simde_test_arm_neon_assert_equal_i16x8(r0, simde_vld1q_s16(test_vec[i].r0));
    simde_test_arm_neon_assert_equal_i16x8(r1, simde_vld1q_s16(test_vec[i].r1));
    simde_test_arm_neon_assert_equal_i16x8(r2, simde_vld1q_s16(test_vec[i].r2));
    simde_test_arm_neon_assert_equal_i16x8(r3, simde_vld1q_s16(test_vec[i].r3));
  }

  return 0;
#else
  for (int i = 0 ; i < 8 ; i++) {
    simde_int16x8_t a = simde_test_arm_neon_random_i16x8();
    simde_int16x4_t v = simde_test_arm_neon_random_i16x4();
    simde_int16x8_t r0 = simde_vqdmulhq_lane_s16(a, v, 0);
    simde_int16x8_t r1 = simde_vqdmulhq_lane_s16(a, v, 1);
    simde_int16x8_t r2 = simde_vqdmulhq_lane_s16(a, v, 2);
    simde_int16x8_t r3 = simde_vqdmulhq_lane_s16(a, v, 3);

    simde_test_arm_neon_write_i16x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i16x4(2, v, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i16x8(2, r0, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i16x8(2, r1, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i16x8(2, r2, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i16x8(2, r3, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vqdmulhq_lane_s32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int32_t a[8];
    int32_t v[8];
    int32_t r0[8];
    int32_t r1[8];
  } test_vec[] = {
    { {  INT32_C(  1728625907),  INT32_C(  2060939560),  INT32_C(  1077597424), -INT32_C(  1435187407) },
      { -INT32_C(  1387879050), -INT32_C(   979296759) },
      { -INT32_C(  1117179022), -INT32_C(  1331947204), -INT32_C(   696431329),  INT32_C(   927535134) },
      { -INT32_C(   788289006), -INT32_C(   939830873), -INT32_C(   491406613),  INT32_C(   654475007) } },
    { { -INT32_C(   834703783), -INT32_C(   309735943), -INT32_C(  1303080566), -INT32_C(   215209213) },
      {  INT32_C(   825452287), -INT32_C(  1545885907) },
      { -INT32_C(   320844421), -INT32_C(   119056666), -INT32_C(   500879639), -INT32_C(    82722371) },
      {  INT32_C(   600869215),  INT32_C(   222966274),  INT32_C(   938034561),  INT32_C(   154920336) } },
    { {  INT32_C(  1448091980), -INT32_C(  1726222016),  INT32_C(  1499945823), -INT32_C(  1303973592) },
      { -INT32_C(  2057004414), -INT32_C(   981954106) },
      { -INT32_C(  1387079989),  INT32_C(  1653491662), -INT32_C(  1436749091),  INT32_C(  1249033694) },
      { -INT32_C(   662151662),  INT32_C(   789328849), -INT32_C(   685862247),  INT32_C(   596252373) } },
    { {  INT32_C(   636922871), -INT32_C(  1614229166),  INT32_C(   871700979),  INT32_C(  1791758346) },
      { -INT32_C(  1799146645), -INT32_C(  1488582364) },
      { -INT32_C(   533609487),  INT32_C(  1352389803), -INT32_C(   730304929), -INT32_C(  1501122498) },
      { -INT32_C(   441499126),  INT32_C(  1118943592), -INT32_C(   604241483), -INT32_C(  1242002414) } },
    { {  INT32_C(  1764535203),  INT32_C(   858760508), -INT32_C(  1554504368), -INT32_C(   364764681) },
      {  INT32_C(  1142765370), -INT32_C(  1280382649) },
      {  INT32_C(   938982574),  INT32_C(   456982184), -INT32_C(   827216432), -INT32_C(   194106459) },
      { -INT32_C(  1052059354), -INT32_C(   512014169),  INT32_C(   926833795),  INT32_C(   217481687) } },
    { {  INT32_C(  1095201052),  INT32_C(   518557050),  INT32_C(  1955009592),  INT32_C(   178828985) },
      { -INT32_C(   743636772),  INT32_C(  1539174177) },
      { -INT32_C(   379249349), -INT32_C(   179567417), -INT32_C(   676986307), -INT32_C(    61925412) },
      {  INT32_C(   784967643),  INT32_C(   371667379),  INT32_C(  1401221509),  INT32_C(   128172783) } },
    { {  INT32_C(  1839258150), -INT32_C(   551530813),  INT32_C(   975202240),  INT32_C(   760744181) },
      { -INT32_C(   693968867),  INT32_C(  1927301782) },
      { -INT32_C(   594364431),  INT32_C(   178229628), -INT32_C(   315140930), -INT32_C(   245837857) },
      {  INT32_C(  1650678697), -INT32_C(   494982265),  INT32_C(   875214587),  INT32_C(   682744949) } },
    { {  INT32_C(  1816497482), -INT32_C(  1564016004), -INT32_C(  1626314788),  INT32_C(  1988047030) },
      { -INT32_C(  1917804648), -INT32_C(   977663576) },
      { -INT32_C(  1622218320),  INT32_C(  1396740396),  INT32_C(  1452376162), -INT32_C(  1775420194) },
      { -INT32_C(   826978788),  INT32_C(   712034050),  INT32_C(   740396199), -INT32_C(   905078449) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x4_t a = simde_vld1q_s32(test_vec[i].a);
    simde_int32x2_t v = simde_vld1_s32(test_vec[i].v);
    simde_int32x4_t r0 = simde_vqdmulhq_lane_s32(a, v, 0);
    simde_int32x4_t r1 = simde_vqdmulhq_lane_s32(a, v, 1);

    simde_test_arm_neon_assert_equal_i32x4(r0, simde_vld1q_s32(test_vec[i].r0));
    simde_test_arm_neon_assert_equal_i32x4(r1, simde_vld1q_s32(test_vec[i].r1));
  }

  return 0;
#else
  for (int i = 0 ; i < 8 ; i++) {
    simde_int32x4_t a = simde_test_arm_neon_random_i32x4();
    simde_int32x2_t v = simde_test_arm_neon_random_i32x2();
    simde_int32x4_t r0 = simde_vqdmulhq_lane_s32(a, v, 0);
    simde_int32x4_t r1 = simde_vqdmulhq_lane_s32(a, v, 1);

    simde_test_arm_neon_write_i32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i32x2(2, v, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i32x4(2, r0, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i32x4(2, r1, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(vqdmulh_lane_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vqdmulh_lane_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vqdmulhq_lane_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vqdmulhq_lane_s32)
SIMDE_TEST_FUNC_LIST_END

#include "test-neon-footer.h"
