#define SIMDE_TEST_ARM_NEON_INSN qdmulh_lane

#include "test-neon.h"
#include "../../../simde/arm/neon/qdmulh_lane.h"

static int
test_simde_vqdmulh_lane_s16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int16_t a[4];
    int16_t v[4];
    int16_t r0[4];
    int16_t r1[4];
    int16_t r2[4];
    int16_t r3[4];
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
    int32_t a[2];
    int32_t v[2];
    int32_t r0[2];
    int32_t r1[2];
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
    int16_t v[4];
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
    int32_t a[4];
    int32_t v[2];
    int32_t r0[4];
    int32_t r1[4];
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

static int
test_simde_vqdmulh_laneq_s16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int16_t a[4];
    int16_t v[8];
    int16_t r0[4];
    int16_t r1[4];
    int16_t r2[4];
    int16_t r3[4];
    int16_t r4[4];
    int16_t r5[4];
    int16_t r6[4];
    int16_t r7[4];
  } test_vec[] = {
    { {  INT16_C( 24128), -INT16_C(  9548), -INT16_C(  8217), -INT16_C(  6234) },
      { -INT16_C( 31527), -INT16_C( 18378),  INT16_C(  8147), -INT16_C( 25984),  INT16_C( 28935), -INT16_C( 13307), -INT16_C(  6743), -INT16_C( 25077) },
      { -INT16_C( 23215),  INT16_C(  9186),  INT16_C(  7905),  INT16_C(  5997) },
      { -INT16_C( 13533),  INT16_C(  5355),  INT16_C(  4608),  INT16_C(  3496) },
      {  INT16_C(  5998), -INT16_C(  2374), -INT16_C(  2043), -INT16_C(  1550) },
      { -INT16_C( 19133),  INT16_C(  7571),  INT16_C(  6515),  INT16_C(  4943) },
      {  INT16_C( 21305), -INT16_C(  8432), -INT16_C(  7256), -INT16_C(  5505) },
      { -INT16_C(  9799),  INT16_C(  3877),  INT16_C(  3336),  INT16_C(  2531) },
      { -INT16_C(  4966),  INT16_C(  1964),  INT16_C(  1690),  INT16_C(  1282) },
      { -INT16_C( 18465),  INT16_C(  7306),  INT16_C(  6288),  INT16_C(  4770) } },
    { {  INT16_C( 14352),  INT16_C(  7311),  INT16_C( 25420), -INT16_C( 29465) },
      { -INT16_C( 25407), -INT16_C( 22426),  INT16_C(  3195),  INT16_C( 21647), -INT16_C( 14959),  INT16_C( 25612), -INT16_C( 29468), -INT16_C(  5122) },
      { -INT16_C( 11128), -INT16_C(  5669), -INT16_C( 19710),  INT16_C( 22845) },
      { -INT16_C(  9823), -INT16_C(  5004), -INT16_C( 17398),  INT16_C( 20165) },
      {  INT16_C(  1399),  INT16_C(   712),  INT16_C(  2478), -INT16_C(  2873) },
      {  INT16_C(  9481),  INT16_C(  4829),  INT16_C( 16792), -INT16_C( 19465) },
      { -INT16_C(  6552), -INT16_C(  3338), -INT16_C( 11605),  INT16_C( 13451) },
      {  INT16_C( 11217),  INT16_C(  5714),  INT16_C( 19868), -INT16_C( 23031) },
      { -INT16_C( 12907), -INT16_C(  6575), -INT16_C( 22861),  INT16_C( 26497) },
      { -INT16_C(  2244), -INT16_C(  1143), -INT16_C(  3974),  INT16_C(  4605) } },
    { {  INT16_C(  1021), -INT16_C( 22600), -INT16_C( 15383), -INT16_C(  1723) },
      { -INT16_C( 10757),  INT16_C( 18454), -INT16_C(   712), -INT16_C(  1580),  INT16_C( 15257),  INT16_C(  5281),  INT16_C( 12359), -INT16_C( 10135) },
      { -INT16_C(   336),  INT16_C(  7419),  INT16_C(  5049),  INT16_C(   565) },
      {  INT16_C(   574), -INT16_C( 12728), -INT16_C(  8664), -INT16_C(   971) },
      { -INT16_C(    23),  INT16_C(   491),  INT16_C(   334),  INT16_C(    37) },
      { -INT16_C(    50),  INT16_C(  1089),  INT16_C(   741),  INT16_C(    83) },
      {  INT16_C(   475), -INT16_C( 10523), -INT16_C(  7163), -INT16_C(   803) },
      {  INT16_C(   164), -INT16_C(  3643), -INT16_C(  2480), -INT16_C(   278) },
      {  INT16_C(   385), -INT16_C(  8524), -INT16_C(  5802), -INT16_C(   650) },
      { -INT16_C(   316),  INT16_C(  6990),  INT16_C(  4757),  INT16_C(   532) } },
    { {  INT16_C( 30198), -INT16_C(  9668),  INT16_C( 15106), -INT16_C(    58) },
      {  INT16_C( 32318),  INT16_C( 10150), -INT16_C(  5055),  INT16_C( 15393),  INT16_C( 14273), -INT16_C(  1660),  INT16_C( 22836), -INT16_C( 12558) },
      {  INT16_C( 29783), -INT16_C(  9536),  INT16_C( 14898), -INT16_C(    58) },
      {  INT16_C(  9353), -INT16_C(  2995),  INT16_C(  4679), -INT16_C(    18) },
      { -INT16_C(  4659),  INT16_C(  1491), -INT16_C(  2331),  INT16_C(     8) },
      {  INT16_C( 14185), -INT16_C(  4542),  INT16_C(  7096), -INT16_C(    28) },
      {  INT16_C( 13153), -INT16_C(  4212),  INT16_C(  6579), -INT16_C(    26) },
      { -INT16_C(  1530),  INT16_C(   489), -INT16_C(   766),  INT16_C(     2) },
      {  INT16_C( 21044), -INT16_C(  6738),  INT16_C( 10527), -INT16_C(    41) },
      { -INT16_C( 11574),  INT16_C(  3705), -INT16_C(  5790),  INT16_C(    22) } },
    { { -INT16_C( 27756), -INT16_C(  9246),  INT16_C( 19395), -INT16_C( 17996) },
      { -INT16_C(  3903), -INT16_C( 15468),  INT16_C( 23083),  INT16_C( 27330),  INT16_C( 27096),  INT16_C(  6545), -INT16_C( 19883),  INT16_C(  5717) },
      {  INT16_C(  3306),  INT16_C(  1101), -INT16_C(  2311),  INT16_C(  2143) },
      {  INT16_C( 13102),  INT16_C(  4364), -INT16_C(  9156),  INT16_C(  8494) },
      { -INT16_C( 19553), -INT16_C(  6514),  INT16_C( 13662), -INT16_C( 12678) },
      { -INT16_C( 23150), -INT16_C(  7712),  INT16_C( 16176), -INT16_C( 15010) },
      { -INT16_C( 22952), -INT16_C(  7646),  INT16_C( 16037), -INT16_C( 14881) },
      { -INT16_C(  5544), -INT16_C(  1847),  INT16_C(  3873), -INT16_C(  3595) },
      {  INT16_C( 16841),  INT16_C(  5610), -INT16_C( 11769),  INT16_C( 10919) },
      { -INT16_C(  4843), -INT16_C(  1614),  INT16_C(  3383), -INT16_C(  3140) } },
    { { -INT16_C(  9495),  INT16_C(  7695),  INT16_C(   307), -INT16_C( 14356) },
      { -INT16_C( 12652),  INT16_C( 22434),  INT16_C( 22042), -INT16_C(  9455), -INT16_C( 23225),  INT16_C( 29342),  INT16_C( 24831), -INT16_C( 10276) },
      {  INT16_C(  3666), -INT16_C(  2972), -INT16_C(   119),  INT16_C(  5542) },
      { -INT16_C(  6501),  INT16_C(  5268),  INT16_C(   210), -INT16_C(  9829) },
      { -INT16_C(  6387),  INT16_C(  5176),  INT16_C(   206), -INT16_C(  9657) },
      {  INT16_C(  2739), -INT16_C(  2221), -INT16_C(    89),  INT16_C(  4142) },
      {  INT16_C(  6729), -INT16_C(  5454), -INT16_C(   218),  INT16_C( 10175) },
      { -INT16_C(  8503),  INT16_C(  6890),  INT16_C(   274), -INT16_C( 12856) },
      { -INT16_C(  7196),  INT16_C(  5831),  INT16_C(   232), -INT16_C( 10879) },
      {  INT16_C(  2977), -INT16_C(  2414), -INT16_C(    97),  INT16_C(  4502) } },
    { {  INT16_C( 28361),  INT16_C(  7920),  INT16_C( 17696),  INT16_C(  2612) },
      {  INT16_C( 17183),  INT16_C( 21032),  INT16_C(  5188), -INT16_C( 10215), -INT16_C( 17182), -INT16_C(   976),  INT16_C( 16658),  INT16_C( 22999) },
      {  INT16_C( 14872),  INT16_C(  4153),  INT16_C(  9279),  INT16_C(  1369) },
      {  INT16_C( 18203),  INT16_C(  5083),  INT16_C( 11358),  INT16_C(  1676) },
      {  INT16_C(  4490),  INT16_C(  1253),  INT16_C(  2801),  INT16_C(   413) },
      { -INT16_C(  8842), -INT16_C(  2469), -INT16_C(  5517), -INT16_C(   815) },
      { -INT16_C( 14872), -INT16_C(  4153), -INT16_C(  9279), -INT16_C(  1370) },
      { -INT16_C(   845), -INT16_C(   236), -INT16_C(   528), -INT16_C(    78) },
      {  INT16_C( 14417),  INT16_C(  4026),  INT16_C(  8995),  INT16_C(  1327) },
      {  INT16_C( 19905),  INT16_C(  5558),  INT16_C( 12420),  INT16_C(  1833) } },
    { {  INT16_C( 30182), -INT16_C(  6708), -INT16_C( 22314), -INT16_C( 24644) },
      { -INT16_C( 21482),  INT16_C( 14270), -INT16_C(  3343),  INT16_C(  4417),  INT16_C( 26934),  INT16_C( 31331),  INT16_C( 32125),  INT16_C( 24403) },
      { -INT16_C( 19787),  INT16_C(  4397),  INT16_C( 14628),  INT16_C( 16156) },
      {  INT16_C( 13143), -INT16_C(  2922), -INT16_C(  9718), -INT16_C( 10733) },
      { -INT16_C(  3080),  INT16_C(   684),  INT16_C(  2276),  INT16_C(  2514) },
      {  INT16_C(  4068), -INT16_C(   905), -INT16_C(  3008), -INT16_C(  3322) },
      {  INT16_C( 24808), -INT16_C(  5514), -INT16_C( 18342), -INT16_C( 20257) },
      {  INT16_C( 28858), -INT16_C(  6414), -INT16_C( 21336), -INT16_C( 23564) },
      {  INT16_C( 29589), -INT16_C(  6577), -INT16_C( 21877), -INT16_C( 24161) },
      {  INT16_C( 22477), -INT16_C(  4996), -INT16_C( 16618), -INT16_C( 18353) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x4_t a = simde_vld1_s16(test_vec[i].a);
    simde_int16x8_t v = simde_vld1q_s16(test_vec[i].v);
    simde_int16x4_t r0 = simde_vqdmulh_laneq_s16(a, v, 0);
    simde_int16x4_t r1 = simde_vqdmulh_laneq_s16(a, v, 1);
    simde_int16x4_t r2 = simde_vqdmulh_laneq_s16(a, v, 2);
    simde_int16x4_t r3 = simde_vqdmulh_laneq_s16(a, v, 3);
    simde_int16x4_t r4 = simde_vqdmulh_laneq_s16(a, v, 4);
    simde_int16x4_t r5 = simde_vqdmulh_laneq_s16(a, v, 5);
    simde_int16x4_t r6 = simde_vqdmulh_laneq_s16(a, v, 6);
    simde_int16x4_t r7 = simde_vqdmulh_laneq_s16(a, v, 7);

    simde_test_arm_neon_assert_equal_i16x4(r0, simde_vld1_s16(test_vec[i].r0));
    simde_test_arm_neon_assert_equal_i16x4(r1, simde_vld1_s16(test_vec[i].r1));
    simde_test_arm_neon_assert_equal_i16x4(r2, simde_vld1_s16(test_vec[i].r2));
    simde_test_arm_neon_assert_equal_i16x4(r3, simde_vld1_s16(test_vec[i].r3));
    simde_test_arm_neon_assert_equal_i16x4(r4, simde_vld1_s16(test_vec[i].r4));
    simde_test_arm_neon_assert_equal_i16x4(r5, simde_vld1_s16(test_vec[i].r5));
    simde_test_arm_neon_assert_equal_i16x4(r6, simde_vld1_s16(test_vec[i].r6));
    simde_test_arm_neon_assert_equal_i16x4(r7, simde_vld1_s16(test_vec[i].r7));
  }

  return 0;
#else
  for (int i = 0 ; i < 8 ; i++) {
    simde_int16x4_t a = simde_test_arm_neon_random_i16x4();
    simde_int16x8_t v = simde_test_arm_neon_random_i16x8();
    simde_int16x4_t r0 = simde_vqdmulh_laneq_s16(a, v, 0);
    simde_int16x4_t r1 = simde_vqdmulh_laneq_s16(a, v, 1);
    simde_int16x4_t r2 = simde_vqdmulh_laneq_s16(a, v, 2);
    simde_int16x4_t r3 = simde_vqdmulh_laneq_s16(a, v, 3);
    simde_int16x4_t r4 = simde_vqdmulh_laneq_s16(a, v, 4);
    simde_int16x4_t r5 = simde_vqdmulh_laneq_s16(a, v, 5);
    simde_int16x4_t r6 = simde_vqdmulh_laneq_s16(a, v, 6);
    simde_int16x4_t r7 = simde_vqdmulh_laneq_s16(a, v, 7);

    simde_test_arm_neon_write_i16x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i16x8(2, v, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i16x4(2, r0, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i16x4(2, r1, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i16x4(2, r2, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i16x4(2, r3, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i16x4(2, r4, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i16x4(2, r5, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i16x4(2, r6, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i16x4(2, r7, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vqdmulh_laneq_s32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int32_t a[2];
    int32_t v[4];
    int32_t r0[2];
    int32_t r1[2];
    int32_t r2[2];
    int32_t r3[2];
  } test_vec[] = {
    { {  INT32_C(   173535428),  INT32_C(    40345299) },
      { -INT32_C(   875020824),  INT32_C(  1870905286),  INT32_C(   116509953),  INT32_C(   775821787) },
      { -INT32_C(    70709323), -INT32_C(    16439230) },
      {  INT32_C(   151185481),  INT32_C(    35149153) },
      {  INT32_C(     9415021),  INT32_C(     2188900) },
      {  INT32_C(    62693173),  INT32_C(    14575553) } },
    { {  INT32_C(   228944750), -INT32_C(  1070592773) },
      { -INT32_C(   808810500),  INT32_C(   231813413),  INT32_C(   903457135),  INT32_C(  1789156457) },
      { -INT32_C(    86227860),  INT32_C(   403219217) },
      {  INT32_C(    24713791), -INT32_C(   115566778) },
      {  INT32_C(    96318203), -INT32_C(   450403746) },
      {  INT32_C(   190743234), -INT32_C(   891954626) } },
    { {  INT32_C(    74552617),  INT32_C(   473149358) },
      {  INT32_C(   371841051), -INT32_C(   522823196),  INT32_C(   112173280),  INT32_C(  1091797202) },
      {  INT32_C(    12908933),  INT32_C(    81926749) },
      { -INT32_C(    18150470), -INT32_C(   115192244) },
      {  INT32_C(     3894237),  INT32_C(    24714840) },
      {  INT32_C(    37903123),  INT32_C(   240552772) } },
    { { -INT32_C(  1820922838),  INT32_C(  1929189960) },
      {  INT32_C(  1584819888),  INT32_C(   964405534),  INT32_C(  1716495490), -INT32_C(   565762306) },
      { -INT32_C(  1343821515),  INT32_C(  1423721488) },
      { -INT32_C(   817751541),  INT32_C(   866372824) },
      { -INT32_C(  1455473639),  INT32_C(  1542012144) },
      {  INT32_C(   479728683), -INT32_C(   508252048) } },
    { { -INT32_C(  1729825082), -INT32_C(  1579550601) },
      {  INT32_C(   758403044),  INT32_C(   446640490), -INT32_C(  1099426400),  INT32_C(  1106768831) },
      { -INT32_C(   610903189), -INT32_C(   557832413) },
      { -INT32_C(   359774531), -INT32_C(   328519966) },
      {  INT32_C(   885601789),  INT32_C(   808667219) },
      { -INT32_C(   891516211), -INT32_C(   814067839) } },
    { { -INT32_C(  1767422312),  INT32_C(   863301228) },
      {  INT32_C(  1556830693),  INT32_C(   905815377),  INT32_C(  1583493620),  INT32_C(    41419106) },
      { -INT32_C(  1281303029),  INT32_C(   625855219) },
      { -INT32_C(   745504307),  INT32_C(   364143181) },
      { -INT32_C(  1303247156),  INT32_C(   636573874) },
      { -INT32_C(    34088759),  INT32_C(    16650727) } },
    { { -INT32_C(   691998441),  INT32_C(  2081929188) },
      {  INT32_C(  1779613438), -INT32_C(  1835169875),  INT32_C(   837708256),  INT32_C(    40299278) },
      { -INT32_C(   573457091),  INT32_C(  1725288648) },
      {  INT32_C(   591359423), -INT32_C(  1779149160) },
      { -INT32_C(   269940499),  INT32_C(   812136227) },
      { -INT32_C(    12985914),  INT32_C(    39069095) } },
    { {  INT32_C(  2120337692), -INT32_C(   511583798) },
      { -INT32_C(  1346944566), -INT32_C(   148123911),  INT32_C(   979451533), -INT32_C(  1513291835) },
      { -INT32_C(  1329918082),  INT32_C(   320875559) },
      { -INT32_C(   146251504),  INT32_C(    35286784) },
      {  INT32_C(   967070461), -INT32_C(   233329617) },
      { -INT32_C(  1494162585),  INT32_C(   360503599) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x2_t a = simde_vld1_s32(test_vec[i].a);
    simde_int32x4_t v = simde_vld1q_s32(test_vec[i].v);
    simde_int32x2_t r0 = simde_vqdmulh_laneq_s32(a, v, 0);
    simde_int32x2_t r1 = simde_vqdmulh_laneq_s32(a, v, 1);
    simde_int32x2_t r2 = simde_vqdmulh_laneq_s32(a, v, 2);
    simde_int32x2_t r3 = simde_vqdmulh_laneq_s32(a, v, 3);

    simde_test_arm_neon_assert_equal_i32x2(r0, simde_vld1_s32(test_vec[i].r0));
    simde_test_arm_neon_assert_equal_i32x2(r1, simde_vld1_s32(test_vec[i].r1));
    simde_test_arm_neon_assert_equal_i32x2(r2, simde_vld1_s32(test_vec[i].r2));
    simde_test_arm_neon_assert_equal_i32x2(r3, simde_vld1_s32(test_vec[i].r3));
  }

  return 0;
#else
  for (int i = 0 ; i < 8 ; i++) {
    simde_int32x2_t a = simde_test_arm_neon_random_i32x2();
    simde_int32x4_t v = simde_test_arm_neon_random_i32x4();
    simde_int32x2_t r0 = simde_vqdmulh_laneq_s32(a, v, 0);
    simde_int32x2_t r1 = simde_vqdmulh_laneq_s32(a, v, 1);
    simde_int32x2_t r2 = simde_vqdmulh_laneq_s32(a, v, 2);
    simde_int32x2_t r3 = simde_vqdmulh_laneq_s32(a, v, 3);

    simde_test_arm_neon_write_i32x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i32x4(2, v, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i32x2(2, r0, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i32x2(2, r1, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i32x2(2, r2, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i32x2(2, r3, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vqdmulhq_laneq_s16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int16_t a[8];
    int16_t v[8];
    int16_t r0[8];
    int16_t r1[8];
    int16_t r2[8];
    int16_t r3[8];
    int16_t r4[8];
    int16_t r5[8];
    int16_t r6[8];
    int16_t r7[8];
  } test_vec[] = {
    { { -INT16_C(   197),  INT16_C( 30436), -INT16_C( 23931), -INT16_C( 18989) },
      { -INT16_C( 12140), -INT16_C( 24226), -INT16_C(  2986), -INT16_C( 13706),  INT16_C(  9592), -INT16_C( 13367),  INT16_C( 12707), -INT16_C(  6713) },
      {  INT16_C(    72), -INT16_C( 11277),  INT16_C(  8866),  INT16_C(  7035) },
      {  INT16_C(   145), -INT16_C( 22502),  INT16_C( 17692),  INT16_C( 14038) },
      {  INT16_C(    17), -INT16_C(  2774),  INT16_C(  2180),  INT16_C(  1730) },
      {  INT16_C(    82), -INT16_C( 12731),  INT16_C( 10009),  INT16_C(  7942) },
      { -INT16_C(    58),  INT16_C(  8909), -INT16_C(  7006), -INT16_C(  5559) },
      {  INT16_C(    80), -INT16_C( 12416),  INT16_C(  9762),  INT16_C(  7746) },
      { -INT16_C(    77),  INT16_C( 11802), -INT16_C(  9281), -INT16_C(  7364) },
      {  INT16_C(    40), -INT16_C(  6236),  INT16_C(  4902),  INT16_C(  3890) } },
    { { -INT16_C( 23905), -INT16_C( 24868),  INT16_C( 10213),  INT16_C(  8276) },
      {  INT16_C( 14374), -INT16_C( 21609),  INT16_C( 27354),  INT16_C( 28256), -INT16_C( 16837), -INT16_C( 28400), -INT16_C( 31054),  INT16_C( 10843) },
      { -INT16_C( 10487), -INT16_C( 10909),  INT16_C(  4480),  INT16_C(  3630) },
      {  INT16_C( 15764),  INT16_C( 16399), -INT16_C(  6736), -INT16_C(  5458) },
      { -INT16_C( 19956), -INT16_C( 20760),  INT16_C(  8525),  INT16_C(  6908) },
      { -INT16_C( 20614), -INT16_C( 21444),  INT16_C(  8806),  INT16_C(  7136) },
      {  INT16_C( 12282),  INT16_C( 12777), -INT16_C(  5248), -INT16_C(  4253) },
      {  INT16_C( 20718),  INT16_C( 21553), -INT16_C(  8852), -INT16_C(  7173) },
      {  INT16_C( 22654),  INT16_C( 23567), -INT16_C(  9679), -INT16_C(  7844) },
      { -INT16_C(  7911), -INT16_C(  8229),  INT16_C(  3379),  INT16_C(  2738) } },
    { {  INT16_C(  9387),  INT16_C( 20213), -INT16_C( 17067), -INT16_C(  3021) },
      {  INT16_C(  3935),  INT16_C( 17554), -INT16_C(  6602),  INT16_C( 23909), -INT16_C(   993), -INT16_C(  1784),  INT16_C( 26982), -INT16_C( 24216) },
      {  INT16_C(  1127),  INT16_C(  2427), -INT16_C(  2050), -INT16_C(   363) },
      {  INT16_C(  5028),  INT16_C( 10828), -INT16_C(  9143), -INT16_C(  1619) },
      { -INT16_C(  1892), -INT16_C(  4073),  INT16_C(  3438),  INT16_C(   608) },
      {  INT16_C(  6849),  INT16_C( 14748), -INT16_C( 12453), -INT16_C(  2205) },
      { -INT16_C(   285), -INT16_C(   613),  INT16_C(   517),  INT16_C(    91) },
      { -INT16_C(   512), -INT16_C(  1101),  INT16_C(   929),  INT16_C(   164) },
      {  INT16_C(  7729),  INT16_C( 16643), -INT16_C( 14054), -INT16_C(  2488) },
      { -INT16_C(  6938), -INT16_C( 14938),  INT16_C( 12612),  INT16_C(  2232) } },
    { {  INT16_C( 30759), -INT16_C(  9677), -INT16_C( 28930), -INT16_C( 22012) },
      { -INT16_C(  1357),  INT16_C(  2296),  INT16_C( 11447),  INT16_C(  5885), -INT16_C( 28869),  INT16_C( 29275), -INT16_C( 16266), -INT16_C( 27185) },
      { -INT16_C(  1274),  INT16_C(   400),  INT16_C(  1198),  INT16_C(   911) },
      {  INT16_C(  2155), -INT16_C(   679), -INT16_C(  2028), -INT16_C(  1543) },
      {  INT16_C( 10745), -INT16_C(  3381), -INT16_C( 10107), -INT16_C(  7690) },
      {  INT16_C(  5524), -INT16_C(  1738), -INT16_C(  5196), -INT16_C(  3954) },
      { -INT16_C( 27100),  INT16_C(  8525),  INT16_C( 25487),  INT16_C( 19392) },
      {  INT16_C( 27480), -INT16_C(  8646), -INT16_C( 25847), -INT16_C( 19666) },
      { -INT16_C( 15269),  INT16_C(  4803),  INT16_C( 14360),  INT16_C( 10926) },
      { -INT16_C( 25519),  INT16_C(  8028),  INT16_C( 24000),  INT16_C( 18261) } },
    { { -INT16_C( 10308),  INT16_C(  8846), -INT16_C(  2496),  INT16_C( 26820) },
      { -INT16_C(  2194),  INT16_C( 27970),  INT16_C( 18053),  INT16_C( 14359),  INT16_C(  3904), -INT16_C(  2239),  INT16_C( 15931),  INT16_C( 30478) },
      {  INT16_C(   690), -INT16_C(   593),  INT16_C(   167), -INT16_C(  1796) },
      { -INT16_C(  8799),  INT16_C(  7550), -INT16_C(  2131),  INT16_C( 22892) },
      { -INT16_C(  5680),  INT16_C(  4873), -INT16_C(  1376),  INT16_C( 14776) },
      { -INT16_C(  4517),  INT16_C(  3876), -INT16_C(  1094),  INT16_C( 11752) },
      { -INT16_C(  1229),  INT16_C(  1053), -INT16_C(   298),  INT16_C(  3195) },
      {  INT16_C(   704), -INT16_C(   605),  INT16_C(   170), -INT16_C(  1833) },
      { -INT16_C(  5012),  INT16_C(  4300), -INT16_C(  1214),  INT16_C( 13039) },
      { -INT16_C(  9588),  INT16_C(  8227), -INT16_C(  2322),  INT16_C( 24945) } },
    { {  INT16_C( 27085),  INT16_C( 17385), -INT16_C( 18391), -INT16_C(  6696) },
      {  INT16_C( 26511), -INT16_C( 12281), -INT16_C( 13475), -INT16_C( 13256),  INT16_C( 31426),  INT16_C( 18489),  INT16_C( 20672),  INT16_C(   384) },
      {  INT16_C( 21913),  INT16_C( 14065), -INT16_C( 14880), -INT16_C(  5418) },
      { -INT16_C( 10152), -INT16_C(  6516),  INT16_C(  6892),  INT16_C(  2509) },
      { -INT16_C( 11139), -INT16_C(  7150),  INT16_C(  7562),  INT16_C(  2753) },
      { -INT16_C( 10957), -INT16_C(  7033),  INT16_C(  7439),  INT16_C(  2708) },
      {  INT16_C( 25975),  INT16_C( 16673), -INT16_C( 17638), -INT16_C(  6422) },
      {  INT16_C( 15282),  INT16_C(  9809), -INT16_C( 10377), -INT16_C(  3779) },
      {  INT16_C( 17086),  INT16_C( 10967), -INT16_C( 11603), -INT16_C(  4225) },
      {  INT16_C(   317),  INT16_C(   203), -INT16_C(   216), -INT16_C(    79) } },
    { { -INT16_C( 16033), -INT16_C( 25608),  INT16_C(  1791), -INT16_C( 13038) },
      { -INT16_C(  1169), -INT16_C( 26608), -INT16_C(  5709),  INT16_C( 17021), -INT16_C( 31408), -INT16_C( 21230),  INT16_C( 19024),  INT16_C(  4985) },
      {  INT16_C(   571),  INT16_C(   913), -INT16_C(    64),  INT16_C(   465) },
      {  INT16_C( 13018),  INT16_C( 20793), -INT16_C(  1455),  INT16_C( 10587) },
      {  INT16_C(  2793),  INT16_C(  4461), -INT16_C(   313),  INT16_C(  2271) },
      { -INT16_C(  8329), -INT16_C( 13302),  INT16_C(   930), -INT16_C(  6773) },
      {  INT16_C( 15367),  INT16_C( 24545), -INT16_C(  1717),  INT16_C( 12496) },
      {  INT16_C( 10387),  INT16_C( 16591), -INT16_C(  1161),  INT16_C(  8447) },
      { -INT16_C(  9309), -INT16_C( 14868),  INT16_C(  1039), -INT16_C(  7570) },
      { -INT16_C(  2440), -INT16_C(  3896),  INT16_C(   272), -INT16_C(  1984) } },
    { { -INT16_C( 19772), -INT16_C( 31397), -INT16_C(  9470),  INT16_C( 25222) },
      {  INT16_C( 32413), -INT16_C( 25347),  INT16_C(  3973), -INT16_C(  2967),  INT16_C( 31242), -INT16_C( 17011),  INT16_C(  2659), -INT16_C( 19457) },
      { -INT16_C( 19558), -INT16_C( 31057), -INT16_C(  9368),  INT16_C( 24948) },
      {  INT16_C( 15294),  INT16_C( 24286),  INT16_C(  7325), -INT16_C( 19510) },
      { -INT16_C(  2398), -INT16_C(  3807), -INT16_C(  1149),  INT16_C(  3058) },
      {  INT16_C(  1790),  INT16_C(  2842),  INT16_C(   857), -INT16_C(  2284) },
      { -INT16_C( 18852), -INT16_C( 29935), -INT16_C(  9029),  INT16_C( 24047) },
      {  INT16_C( 10264),  INT16_C( 16299),  INT16_C(  4916), -INT16_C( 13094) },
      { -INT16_C(  1605), -INT16_C(  2548), -INT16_C(   769),  INT16_C(  2046) },
      {  INT16_C( 11740),  INT16_C( 18642),  INT16_C(  5623), -INT16_C( 14977) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x8_t a = simde_vld1q_s16(test_vec[i].a);
    simde_int16x8_t v = simde_vld1q_s16(test_vec[i].v);
    simde_int16x8_t r0 = simde_vqdmulhq_laneq_s16(a, v, 0);
    simde_int16x8_t r1 = simde_vqdmulhq_laneq_s16(a, v, 1);
    simde_int16x8_t r2 = simde_vqdmulhq_laneq_s16(a, v, 2);
    simde_int16x8_t r3 = simde_vqdmulhq_laneq_s16(a, v, 3);
    simde_int16x8_t r4 = simde_vqdmulhq_laneq_s16(a, v, 4);
    simde_int16x8_t r5 = simde_vqdmulhq_laneq_s16(a, v, 5);
    simde_int16x8_t r6 = simde_vqdmulhq_laneq_s16(a, v, 6);
    simde_int16x8_t r7 = simde_vqdmulhq_laneq_s16(a, v, 7);

    simde_test_arm_neon_assert_equal_i16x8(r0, simde_vld1q_s16(test_vec[i].r0));
    simde_test_arm_neon_assert_equal_i16x8(r1, simde_vld1q_s16(test_vec[i].r1));
    simde_test_arm_neon_assert_equal_i16x8(r2, simde_vld1q_s16(test_vec[i].r2));
    simde_test_arm_neon_assert_equal_i16x8(r3, simde_vld1q_s16(test_vec[i].r3));
    simde_test_arm_neon_assert_equal_i16x8(r4, simde_vld1q_s16(test_vec[i].r4));
    simde_test_arm_neon_assert_equal_i16x8(r5, simde_vld1q_s16(test_vec[i].r5));
    simde_test_arm_neon_assert_equal_i16x8(r6, simde_vld1q_s16(test_vec[i].r6));
    simde_test_arm_neon_assert_equal_i16x8(r7, simde_vld1q_s16(test_vec[i].r7));
  }

  return 0;
#else
  for (int i = 0 ; i < 8 ; i++) {
    simde_int16x4_t a = simde_test_arm_neon_random_i16x4();
    simde_int16x8_t v = simde_test_arm_neon_random_i16x8();
    simde_int16x4_t r0 = simde_vqdmulh_laneq_s16(a, v, 0);
    simde_int16x4_t r1 = simde_vqdmulh_laneq_s16(a, v, 1);
    simde_int16x4_t r2 = simde_vqdmulh_laneq_s16(a, v, 2);
    simde_int16x4_t r3 = simde_vqdmulh_laneq_s16(a, v, 3);
    simde_int16x4_t r4 = simde_vqdmulh_laneq_s16(a, v, 4);
    simde_int16x4_t r5 = simde_vqdmulh_laneq_s16(a, v, 5);
    simde_int16x4_t r6 = simde_vqdmulh_laneq_s16(a, v, 6);
    simde_int16x4_t r7 = simde_vqdmulh_laneq_s16(a, v, 7);

    simde_test_arm_neon_write_i16x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i16x8(2, v, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i16x4(2, r0, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i16x4(2, r1, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i16x4(2, r2, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i16x4(2, r3, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i16x4(2, r4, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i16x4(2, r5, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i16x4(2, r6, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i16x4(2, r7, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vqdmulhq_laneq_s32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int32_t a[4];
    int32_t v[4];
    int32_t r0[4];
    int32_t r1[4];
    int32_t r2[4];
    int32_t r3[4];
  } test_vec[] = {
    { { -INT32_C(  1986752993), -INT32_C(  1047013051), -INT32_C(   517251415), -INT32_C(   732920763) },
      { -INT32_C(   463352318), -INT32_C(  2053973935), -INT32_C(   977564601),  INT32_C(  1501699898) },
      {  INT32_C(   428672230),  INT32_C(   225909018),  INT32_C(   111604874),  INT32_C(   158138822) },
      {  INT32_C(  1900242112),  INT32_C(  1001422068),  INT32_C(   494728295),  INT32_C(   701006568) },
      {  INT32_C(   904397758),  INT32_C(   476614989),  INT32_C(   235460080),  INT32_C(   333635785) },
      { -INT32_C(  1389303602), -INT32_C(   732158959), -INT32_C(   361705384), -INT32_C(   512519402) } },
    { { -INT32_C(   220064083), -INT32_C(  1716225552),  INT32_C(   494591960),  INT32_C(  1710344803) },
      { -INT32_C(   364227687),  INT32_C(  1936710699), -INT32_C(  1556600216), -INT32_C(   151209143) },
      {  INT32_C(    37324350),  INT32_C(   291083409), -INT32_C(    83886127), -INT32_C(   290085996) },
      { -INT32_C(   198465057), -INT32_C(  1547780069),  INT32_C(   446048351),  INT32_C(  1542476508) },
      {  INT32_C(   159513111),  INT32_C(  1244003449), -INT32_C(   358504221), -INT32_C(  1239740798) },
      {  INT32_C(    15495205),  INT32_C(   120843292), -INT32_C(    34825330), -INT32_C(   120429216) } },
    { { -INT32_C(  1041702959),  INT32_C(   811244632), -INT32_C(   548547205),  INT32_C(   943996831) },
      { -INT32_C(  1121808750), -INT32_C(   751791765),  INT32_C(    74869179), -INT32_C(   168135900) },
      {  INT32_C(   544167819), -INT32_C(   423780329),  INT32_C(   286551683), -INT32_C(   493127809) },
      {  INT32_C(   364679706), -INT32_C(   284000782),  INT32_C(   192035581), -INT32_C(   330474714) },
      { -INT32_C(    36317597),  INT32_C(    28282971), -INT32_C(    19124374),  INT32_C(    32911201) },
      {  INT32_C(    81559486), -INT32_C(    63515896),  INT32_C(    42948163), -INT32_C(    73909647) } },
    { { -INT32_C(  1430789294), -INT32_C(    69529217), -INT32_C(  2032523034), -INT32_C(   104980889) },
      {  INT32_C(   414704045),  INT32_C(   787212146),  INT32_C(  1949459024),  INT32_C(   661269973) },
      { -INT32_C(   276302038), -INT32_C(    13426900), -INT32_C(   392503815), -INT32_C(    20273030) },
      { -INT32_C(   524490472), -INT32_C(    25487619), -INT32_C(   745070549), -INT32_C(    38483288) },
      { -INT32_C(  1298852778), -INT32_C(    63117761), -INT32_C(  1845099205), -INT32_C(    95300350) },
      { -INT32_C(   440579839), -INT32_C(    21409981), -INT32_C(   625870401), -INT32_C(    32326538) } },
    { { -INT32_C(  1882119920),  INT32_C(   428518450),  INT32_C(  1017078997),  INT32_C(   808869251) },
      { -INT32_C(  1320620738),  INT32_C(   635384788),  INT32_C(  1788416405),  INT32_C(  1318126398) },
      {  INT32_C(  1157432141), -INT32_C(   263522543), -INT32_C(   625464887), -INT32_C(   497423815) },
      { -INT32_C(   556870535),  INT32_C(   126787510),  INT32_C(   300927331),  INT32_C(   239323460) },
      { -INT32_C(  1567422479),  INT32_C(   356868573),  INT32_C(   847019610),  INT32_C(   673623307) },
      { -INT32_C(  1155246027),  INT32_C(   263024811),  INT32_C(   624283531),  INT32_C(   496484298) } },
    { {  INT32_C(  1474192164), -INT32_C(   462395377),  INT32_C(  1344344013), -INT32_C(  1417652372) },
      {  INT32_C(   408733764), -INT32_C(  1858257925), -INT32_C(  1946429620), -INT32_C(     2519590) },
      {  INT32_C(   280585192), -INT32_C(    88008402),  INT32_C(   255871000), -INT32_C(   269823890) },
      { -INT32_C(  1275646162),  INT32_C(   400119402), -INT32_C(  1163286118),  INT32_C(  1226721217) },
      { -INT32_C(  1336173757),  INT32_C(   419104498), -INT32_C(  1218482390),  INT32_C(  1284927394) },
      { -INT32_C(     1729634),  INT32_C(      542517), -INT32_C(     1577286),  INT32_C(     1663296) } },
    { { -INT32_C(    11094032), -INT32_C(   303774176),  INT32_C(  1094518229), -INT32_C(  1595097764) },
      { -INT32_C(  2135406459), -INT32_C(   804129149), -INT32_C(  1487204915), -INT32_C(  1968819046) },
      {  INT32_C(    11031640),  INT32_C(   302065786), -INT32_C(  1088362791),  INT32_C(  1586127126) },
      {  INT32_C(     4154180),  INT32_C(   113748791), -INT32_C(   409844338),  INT32_C(   597287252) },
      {  INT32_C(     7682991),  INT32_C(   210373870), -INT32_C(   757990820),  INT32_C(  1104659044) },
      {  INT32_C(    10171039),  INT32_C(   278501018), -INT32_C(  1003457390),  INT32_C(  1462390114) } },
    { {  INT32_C(   210369772), -INT32_C(  1745261118), -INT32_C(   824625550),  INT32_C(  2020525555) },
      { -INT32_C(  1846008050), -INT32_C(   362739171), -INT32_C(  1315849193), -INT32_C(   583321359) },
      { -INT32_C(   180836904),  INT32_C(  1500251737),  INT32_C(   708860067), -INT32_C(  1736873035) },
      { -INT32_C(    35534314),  INT32_C(   294798319),  INT32_C(   139290461), -INT32_C(   341294224) },
      { -INT32_C(   128901981),  INT32_C(  1069391348),  INT32_C(   505281083), -INT32_C(  1238056888) },
      { -INT32_C(    57142778),  INT32_C(   474065582),  INT32_C(   223993182), -INT32_C(   548835710) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x4_t a = simde_vld1q_s32(test_vec[i].a);
    simde_int32x4_t v = simde_vld1q_s32(test_vec[i].v);
    simde_int32x4_t r0 = simde_vqdmulhq_laneq_s32(a, v, 0);
    simde_int32x4_t r1 = simde_vqdmulhq_laneq_s32(a, v, 1);
    simde_int32x4_t r2 = simde_vqdmulhq_laneq_s32(a, v, 2);
    simde_int32x4_t r3 = simde_vqdmulhq_laneq_s32(a, v, 3);

    simde_test_arm_neon_assert_equal_i32x4(r0, simde_vld1q_s32(test_vec[i].r0));
    simde_test_arm_neon_assert_equal_i32x4(r1, simde_vld1q_s32(test_vec[i].r1));
    simde_test_arm_neon_assert_equal_i32x4(r2, simde_vld1q_s32(test_vec[i].r2));
    simde_test_arm_neon_assert_equal_i32x4(r3, simde_vld1q_s32(test_vec[i].r3));
  }

  return 0;
#else
  for (int i = 0 ; i < 8 ; i++) {
    simde_int32x4_t a = simde_test_arm_neon_random_i32x4();
    simde_int32x4_t v = simde_test_arm_neon_random_i32x4();
    simde_int32x4_t r0 = simde_vqdmulhq_laneq_s32(a, v, 0);
    simde_int32x4_t r1 = simde_vqdmulhq_laneq_s32(a, v, 1);
    simde_int32x4_t r2 = simde_vqdmulhq_laneq_s32(a, v, 2);
    simde_int32x4_t r3 = simde_vqdmulhq_laneq_s32(a, v, 3);

    simde_test_arm_neon_write_i32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i32x4(2, v, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i32x4(2, r0, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i32x4(2, r1, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i32x4(2, r2, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i32x4(2, r3, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vqdmulhs_lane_s32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int32_t a;
    int32_t v[2];
    int32_t r0;
    int32_t r1;
  } test_vec[] = {
    { -INT32_C(   256109187),
      { -INT32_C(  2079352100), -INT32_C(    56652986) },
       INT32_C(   247983809),
       INT32_C(     6756442) },
    {  INT32_C(   836292532),
      { -INT32_C(  2026864126), -INT32_C(  1060307586) },
      -INT32_C(   789319786),
      -INT32_C(   412914584) },
    { -INT32_C(   679721957),
      {  INT32_C(   602749862),  INT32_C(   756328785) },
      -INT32_C(   190782508),
      -INT32_C(   239393340) },
    { -INT32_C(  1968102589),
      {  INT32_C(  1652969902),  INT32_C(   596860448) },
      -INT32_C(  1514895980),
      -INT32_C(   547004209) },
    {  INT32_C(  1605027041),
      { -INT32_C(   585140543),  INT32_C(  1639226298) },
      -INT32_C(   437333433),
       INT32_C(  1225156027) },
    {  INT32_C(   679780823),
      { -INT32_C(  1906993077),  INT32_C(  1779959483) },
      -INT32_C(   603654107),
       INT32_C(   563441925) },
    {  INT32_C(  2026676055),
      { -INT32_C(   560242435), -INT32_C(   448969436) },
      -INT32_C(   528725762),
      -INT32_C(   423712473) },
    {  INT32_C(  1992449467),
      { -INT32_C(   807962888),  INT32_C(  1677155096) },
      -INT32_C(   749633287),
       INT32_C(  1556075539) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    int32_t a = test_vec[i].a;
    simde_int32x2_t v = simde_vld1_s32(test_vec[i].v);
    int32_t r0 = simde_vqdmulhs_lane_s32(a, v, 0);
    int32_t r1 = simde_vqdmulhs_lane_s32(a, v, 1);

    simde_assert_equal_i32(r0, test_vec[i].r0);
    simde_assert_equal_i32(r1, test_vec[i].r1);
  }

  return 0;
#else
  for (int i = 0 ; i < 8 ; i++) {
    int32_t a = simde_test_codegen_random_i32();
    simde_int32x2_t v = simde_test_arm_neon_random_i32x2();
    int32_t r0 = simde_vqdmulhs_lane_s32(a, v, 0);
    int32_t r1 = simde_vqdmulhs_lane_s32(a, v, 1);

    simde_test_codegen_write_i32(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i32x2(2, v, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, r0, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, r1, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vqdmulhs_laneq_s32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int32_t a;
    int32_t v[4];
    int32_t r0;
    int32_t r1;
  } test_vec[] = {
    {  INT32_C(   260488474),
      {  INT32_C(   148924676),  INT32_C(  2090401921),  INT32_C(   509829879),  INT32_C(   679888641) },
       INT32_C(    18064473),
       INT32_C(   253564494) },
    { -INT32_C(  1921550066),
      { -INT32_C(  1542903888),  INT32_C(   576591624), -INT32_C(   651041579), -INT32_C(   807333555) },
       INT32_C(  1380577249),
      -INT32_C(   515929272) },
    {  INT32_C(   139164177),
      { -INT32_C(   567824419),  INT32_C(    84323830), -INT32_C(   695042778), -INT32_C(  1401250908) },
      -INT32_C(    36796936),
       INT32_C(     5464468) },
    { -INT32_C(  1999709773),
      {  INT32_C(   190906557),  INT32_C(   601506321), -INT32_C(  1725225540), -INT32_C(   881372460) },
      -INT32_C(   177769786),
      -INT32_C(   560115124) },
    {  INT32_C(   651197696),
      { -INT32_C(  1610784005), -INT32_C(  1320388610),  INT32_C(   238623312),  INT32_C(   739875354) },
      -INT32_C(   488450208),
      -INT32_C(   400391417) },
    { -INT32_C(  1739590692),
      { -INT32_C(   315459048), -INT32_C(   843535923),  INT32_C(   586385447), -INT32_C(   389943062) },
       INT32_C(   255540769),
       INT32_C(   683314744) },
    { -INT32_C(  1197929112),
      {  INT32_C(  1120326184),  INT32_C(  1215225708), -INT32_C(   337527342),  INT32_C(    98046776) },
      -INT32_C(   624950673),
      -INT32_C(   677888400) },
    { -INT32_C(   472739652),
      {  INT32_C(    33932568),  INT32_C(   518768566), -INT32_C(    53050156), -INT32_C(  1019241129) },
      -INT32_C(     7469799),
      -INT32_C(   114199925) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    int32_t a = test_vec[i].a;
    simde_int32x4_t v = simde_vld1q_s32(test_vec[i].v);
    int32_t r0 = simde_vqdmulhs_laneq_s32(a, v, 0);
    int32_t r1 = simde_vqdmulhs_laneq_s32(a, v, 1);

    simde_assert_equal_i32(r0, test_vec[i].r0);
    simde_assert_equal_i32(r1, test_vec[i].r1);
  }

  return 0;
#else
  for (int i = 0 ; i < 8 ; i++) {
    int32_t a = simde_test_codegen_random_i32();
    simde_int32x4_t v = simde_test_arm_neon_random_i32x4();
    int32_t r0 = simde_vqdmulhs_laneq_s32(a, v, 0);
    int32_t r1 = simde_vqdmulhs_laneq_s32(a, v, 1);

    simde_test_codegen_write_i32(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i32x4(2, v, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, r0, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, r1, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(vqdmulh_lane_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vqdmulh_lane_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vqdmulhq_lane_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vqdmulhq_lane_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vqdmulh_laneq_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vqdmulh_laneq_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vqdmulhq_laneq_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vqdmulhq_laneq_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vqdmulhs_lane_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vqdmulhs_laneq_s32)
SIMDE_TEST_FUNC_LIST_END

#include "test-neon-footer.h"
