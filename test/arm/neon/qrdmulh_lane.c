#include "simde/simde-constify.h"
#include "test/test.h"
#define SIMDE_TEST_ARM_NEON_INSN qrdmulh_lane

#include "test-neon.h"
#include "../../../simde/arm/neon/qrdmulh_lane.h"

static int
test_simde_vqrdmulh_lane_s16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int16_t  a[4];
    int16_t  v[4];
    int16_t r0[4];
    int16_t r1[4];
    int16_t r2[4];
    int16_t r3[4];
  } test_vec[] = {
    { { -INT16_C( 15292),  INT16_C(  4838),  INT16_C(  1822),  INT16_C( 29848) },
      { -INT16_C( 31307), -INT16_C(    66),  INT16_C(   824), -INT16_C( 13165) },
      {  INT16_C( 14610), -INT16_C(  4622), -INT16_C(  1741), -INT16_C( 28517) },
      {  INT16_C(    31), -INT16_C(    10), -INT16_C(     4), -INT16_C(    60) },
      { -INT16_C(   385),  INT16_C(   122),  INT16_C(    46),  INT16_C(   751) },
      {  INT16_C(  6144), -INT16_C(  1944), -INT16_C(   732), -INT16_C( 11992) } },
    { {  INT16_C( 19705),  INT16_C(  9914),  INT16_C(  6190),  INT16_C(  6573) },
      { -INT16_C(  2608),  INT16_C( 27875), -INT16_C( 12624), -INT16_C(  2573) },
      { -INT16_C(  1568), -INT16_C(   789), -INT16_C(   493), -INT16_C(   523) },
      {  INT16_C( 16763),  INT16_C(  8434),  INT16_C(  5266),  INT16_C(  5592) },
      { -INT16_C(  7591), -INT16_C(  3819), -INT16_C(  2385), -INT16_C(  2532) },
      { -INT16_C(  1547), -INT16_C(   778), -INT16_C(   486), -INT16_C(   516) } },
    { { -INT16_C(  9581), -INT16_C( 20217), -INT16_C( 24607), -INT16_C( 27099) },
      { -INT16_C(  7388),  INT16_C( 23701),  INT16_C( 10726), -INT16_C(  8408) },
      {  INT16_C(  2160),  INT16_C(  4558),  INT16_C(  5548),  INT16_C(  6110) },
      { -INT16_C(  6930), -INT16_C( 14623), -INT16_C( 17798), -INT16_C( 19601) },
      { -INT16_C(  3136), -INT16_C(  6618), -INT16_C(  8055), -INT16_C(  8870) },
      {  INT16_C(  2458),  INT16_C(  5188),  INT16_C(  6314),  INT16_C(  6953) } },
    { { -INT16_C(  7307), -INT16_C( 23546), -INT16_C( 19461), -INT16_C( 13379) },
      { -INT16_C( 24408),  INT16_C( 22840),  INT16_C( 11119),  INT16_C(   590) },
      {  INT16_C(  5443),  INT16_C( 17539),  INT16_C( 14496),  INT16_C(  9966) },
      { -INT16_C(  5093), -INT16_C( 16412), -INT16_C( 13565), -INT16_C(  9325) },
      { -INT16_C(  2479), -INT16_C(  7990), -INT16_C(  6604), -INT16_C(  4540) },
      { -INT16_C(   132), -INT16_C(   424), -INT16_C(   350), -INT16_C(   241) } },
    { {  INT16_C( 21765), -INT16_C(  6477), -INT16_C(  9740),  INT16_C(  6269) },
      {  INT16_C(  4796), -INT16_C( 23692), -INT16_C( 25541), -INT16_C( 20094) },
      {  INT16_C(  3186), -INT16_C(   948), -INT16_C(  1426),  INT16_C(   918) },
      { -INT16_C( 15737),  INT16_C(  4683),  INT16_C(  7042), -INT16_C(  4533) },
      { -INT16_C( 16965),  INT16_C(  5048),  INT16_C(  7592), -INT16_C(  4886) },
      { -INT16_C( 13347),  INT16_C(  3972),  INT16_C(  5973), -INT16_C(  3844) } },
    { { -INT16_C( 30593),  INT16_C( 31317),  INT16_C(  4668), -INT16_C(  7098) },
      {  INT16_C( 32434),  INT16_C(  8509), -INT16_C( 29783), -INT16_C( 20701) },
      { -INT16_C( 30281),  INT16_C( 30998),  INT16_C(  4620), -INT16_C(  7026) },
      { -INT16_C(  7944),  INT16_C(  8132),  INT16_C(  1212), -INT16_C(  1843) },
      {  INT16_C( 27806), -INT16_C( 28464), -INT16_C(  4243),  INT16_C(  6451) },
      {  INT16_C( 19327), -INT16_C( 19784), -INT16_C(  2949),  INT16_C(  4484) } },
    { { -INT16_C( 10272), -INT16_C( 11115),  INT16_C(  4784),  INT16_C( 27884) },
      {  INT16_C( 24613),  INT16_C( 24591), -INT16_C( 27907),  INT16_C( 31761) },
      { -INT16_C(  7716), -INT16_C(  8349),  INT16_C(  3593),  INT16_C( 20944) },
      { -INT16_C(  7709), -INT16_C(  8341),  INT16_C(  3590),  INT16_C( 20926) },
      {  INT16_C(  8748),  INT16_C(  9466), -INT16_C(  4074), -INT16_C( 23748) },
      { -INT16_C(  9956), -INT16_C( 10773),  INT16_C(  4637),  INT16_C( 27027) } },
    { {  INT16_C( 26138),  INT16_C( 22263),  INT16_C( 15736),  INT16_C( 11067) },
      {  INT16_C( 30907),  INT16_C( 25676),  INT16_C( 28676), -INT16_C(  7149) },
      {  INT16_C( 24654),  INT16_C( 20999),  INT16_C( 14842),  INT16_C( 10438) },
      {  INT16_C( 20481),  INT16_C( 17445),  INT16_C( 12330),  INT16_C(  8672) },
      {  INT16_C( 22874),  INT16_C( 19483),  INT16_C( 13771),  INT16_C(  9685) },
      { -INT16_C(  5703), -INT16_C(  4857), -INT16_C(  3433), -INT16_C(  2414) } }
  };

  simde_int16x4_t a, v, r;

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    a = simde_vld1_s16(test_vec[i].a);
    v = simde_vld1_s16(test_vec[i].v);

    r = simde_vqrdmulh_lane_s16(a, v, 0);
    simde_test_arm_neon_assert_equal_i16x4(r, simde_vld1_s16(test_vec[i].r0));

    r = simde_vqrdmulh_lane_s16(a, v, 1);
    simde_test_arm_neon_assert_equal_i16x4(r, simde_vld1_s16(test_vec[i].r1));

    r = simde_vqrdmulh_lane_s16(a, v, 2);
    simde_test_arm_neon_assert_equal_i16x4(r, simde_vld1_s16(test_vec[i].r2));

    r = simde_vqrdmulh_lane_s16(a, v, 3);
    simde_test_arm_neon_assert_equal_i16x4(r, simde_vld1_s16(test_vec[i].r3));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int16x4_t a = simde_test_arm_neon_random_i16x4();
    simde_int16x4_t v = simde_test_arm_neon_random_i16x4();
    simde_int16x4_t r;

    simde_test_arm_neon_write_i16x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i16x4(2, v, SIMDE_TEST_VEC_POS_MIDDLE);

    for (int j = 0 ; j < 4 ; j++) {
      SIMDE_CONSTIFY_4_(simde_vqrdmulh_lane_s16, r, (HEDLEY_UNREACHABLE(), simde_vdup_n_s16(0)), j, a, v);
      simde_test_arm_neon_write_i16x4(2, r, (j == 3) ? SIMDE_TEST_VEC_POS_LAST : SIMDE_TEST_VEC_POS_MIDDLE);
    }
  }
  return 1;
#endif
}

static int
test_simde_vqrdmulh_lane_s32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int32_t  a[2];
    int32_t  v[2];
    int32_t r0[2];
    int32_t r1[2];
  } test_vec[] = {
    { { -INT32_C(   705831767),  INT32_C(   760452672) },
      {  INT32_C(   489325157),  INT32_C(   735130326) },
      { -INT32_C(   160830673),  INT32_C(   173276580) },
      { -INT32_C(   241621554),  INT32_C(   260319477) } },
    { {  INT32_C(  1401708025),  INT32_C(  1470911321) },
      { -INT32_C(  1673994852),  INT32_C(   225095780) },
      { -INT32_C(  1092651867), -INT32_C(  1146596847) },
      {  INT32_C(   146924779),  INT32_C(   154178558) } },
    { { -INT32_C(   857581684),  INT32_C(  1408906733) },
      { -INT32_C(  1922030409),  INT32_C(  1354252631) },
      {  INT32_C(   767548603), -INT32_C(  1260992877) },
      { -INT32_C(   540810754),  INT32_C(   888489024) } },
    { { -INT32_C(   123517538),  INT32_C(   877612952) },
      { -INT32_C(  1848539347), -INT32_C(   996197577) },
      {  INT32_C(   106323058), -INT32_C(   755443272) },
      {  INT32_C(    57298631), -INT32_C(   407116439) } },
    { { -INT32_C(  2138013294),  INT32_C(  1859357367) },
      {  INT32_C(   117195695),  INT32_C(   592884869) },
      { -INT32_C(   116678865),  INT32_C(   101471636) },
      { -INT32_C(   590270260),  INT32_C(   513337948) } },
    { { -INT32_C(  1843660295),  INT32_C(  1992714825) },
      {  INT32_C(   688363505),  INT32_C(  1710073554) },
      { -INT32_C(   590974680),  INT32_C(   638753251) },
      { -INT32_C(  1468134445),  INT32_C(  1586828811) } },
    { { -INT32_C(   538608344), -INT32_C(  1219643384) },
      { -INT32_C(  2135078405), -INT32_C(   140241922) },
      {  INT32_C(   535496997),  INT32_C(  1212597942) },
      {  INT32_C(    35173944),  INT32_C(    79649097) } },
    { {  INT32_C(  1435090700),  INT32_C(   466309162) },
      { -INT32_C(  1169894425), -INT32_C(  1591791239) },
      { -INT32_C(   781800882), -INT32_C(   254033361) },
      { -INT32_C(  1063740255), -INT32_C(   345644932) } }
  };

  simde_int32x2_t a, v, r;

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    a = simde_vld1_s32(test_vec[i].a);
    v = simde_vld1_s32(test_vec[i].v);

    r = simde_vqrdmulh_lane_s32(a, v, 0);
    simde_test_arm_neon_assert_equal_i32x2(r, simde_vld1_s32(test_vec[i].r0));

    r = simde_vqrdmulh_lane_s32(a, v, 1);
    simde_test_arm_neon_assert_equal_i32x2(r, simde_vld1_s32(test_vec[i].r1));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int32x2_t a = simde_test_arm_neon_random_i32x2();
    simde_int32x2_t v = simde_test_arm_neon_random_i32x2();
    simde_int32x2_t r;

    simde_test_arm_neon_write_i32x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i32x2(2, v, SIMDE_TEST_VEC_POS_MIDDLE);

    for (int j = 0 ; j < 2 ; j++) {
      SIMDE_CONSTIFY_2_(simde_vqrdmulh_lane_s32, r, (HEDLEY_UNREACHABLE(), simde_vdup_n_s32(0)), j, a, v);
      simde_test_arm_neon_write_i32x2(2, r, (j == 1) ? SIMDE_TEST_VEC_POS_LAST : SIMDE_TEST_VEC_POS_MIDDLE);
    }
  }
  return 1;
#endif
}

static int
test_simde_vqrdmulhq_lane_s16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int16_t  a[8];
    int16_t  v[4];
    int16_t r0[8];
    int16_t r1[8];
    int16_t r2[8];
    int16_t r3[8];
  } test_vec[] = {
    { {  INT16_C( 13798), -INT16_C( 18092), -INT16_C( 30439), -INT16_C( 21522),  INT16_C( 20254), -INT16_C( 11066),  INT16_C( 16104), -INT16_C(  2630) },
      {  INT16_C( 26077),  INT16_C( 10105), -INT16_C(  6471),  INT16_C( 23800) },
      {  INT16_C( 10981), -INT16_C( 14398), -INT16_C( 24224), -INT16_C( 17127),  INT16_C( 16118), -INT16_C(  8806),  INT16_C( 12816), -INT16_C(  2093) },
      {  INT16_C(  4255), -INT16_C(  5579), -INT16_C(  9387), -INT16_C(  6637),  INT16_C(  6246), -INT16_C(  3413),  INT16_C(  4966), -INT16_C(   811) },
      { -INT16_C(  2725),  INT16_C(  3573),  INT16_C(  6011),  INT16_C(  4250), -INT16_C(  4000),  INT16_C(  2185), -INT16_C(  3180),  INT16_C(   519) },
      {  INT16_C( 10022), -INT16_C( 13141), -INT16_C( 22108), -INT16_C( 15632),  INT16_C( 14711), -INT16_C(  8037),  INT16_C( 11697), -INT16_C(  1910) } },
    { { -INT16_C(  8605),  INT16_C( 24205), -INT16_C(  6794),  INT16_C( 23589),  INT16_C( 31258),  INT16_C( 13078),  INT16_C(  1027),  INT16_C(  8670) },
      { -INT16_C( 23213),  INT16_C( 15350), -INT16_C( 20253), -INT16_C( 16335) },
      {  INT16_C(  6096), -INT16_C( 17147),  INT16_C(  4813), -INT16_C( 16711), -INT16_C( 22143), -INT16_C(  9265), -INT16_C(   728), -INT16_C(  6142) },
      { -INT16_C(  4031),  INT16_C( 11339), -INT16_C(  3183),  INT16_C( 11050),  INT16_C( 14643),  INT16_C(  6126),  INT16_C(   481),  INT16_C(  4061) },
      {  INT16_C(  5319), -INT16_C( 14960),  INT16_C(  4199), -INT16_C( 14580), -INT16_C( 19320), -INT16_C(  8083), -INT16_C(   635), -INT16_C(  5359) },
      {  INT16_C(  4290), -INT16_C( 12066),  INT16_C(  3387), -INT16_C( 11759), -INT16_C( 15582), -INT16_C(  6519), -INT16_C(   512), -INT16_C(  4322) } },
    { { -INT16_C( 21995), -INT16_C( 12569), -INT16_C(  8303), -INT16_C(  3029), -INT16_C( 18243),  INT16_C( 13138),  INT16_C( 30877), -INT16_C( 18544) },
      { -INT16_C( 22798), -INT16_C(  2582), -INT16_C( 13910), -INT16_C(   746) },
      {  INT16_C( 15303),  INT16_C(  8745),  INT16_C(  5777),  INT16_C(  2107),  INT16_C( 12692), -INT16_C(  9141), -INT16_C( 21482),  INT16_C( 12902) },
      {  INT16_C(  1733),  INT16_C(   990),  INT16_C(   654),  INT16_C(   239),  INT16_C(  1437), -INT16_C(  1035), -INT16_C(  2433),  INT16_C(  1461) },
      {  INT16_C(  9337),  INT16_C(  5336),  INT16_C(  3525),  INT16_C(  1286),  INT16_C(  7744), -INT16_C(  5577), -INT16_C( 13107),  INT16_C(  7872) },
      {  INT16_C(   501),  INT16_C(   286),  INT16_C(   189),  INT16_C(    69),  INT16_C(   415), -INT16_C(   299), -INT16_C(   703),  INT16_C(   422) } },
    { {  INT16_C(  3182),  INT16_C( 20793),  INT16_C( 27324), -INT16_C( 12015), -INT16_C(  2028), -INT16_C( 23136), -INT16_C( 13353), -INT16_C( 27494) },
      { -INT16_C(  4989),  INT16_C(  8648),  INT16_C( 22628),  INT16_C( 22232) },
      { -INT16_C(   484), -INT16_C(  3166), -INT16_C(  4160),  INT16_C(  1829),  INT16_C(   309),  INT16_C(  3523),  INT16_C(  2033),  INT16_C(  4186) },
      {  INT16_C(   840),  INT16_C(  5488),  INT16_C(  7211), -INT16_C(  3171), -INT16_C(   535), -INT16_C(  6106), -INT16_C(  3524), -INT16_C(  7256) },
      {  INT16_C(  2197),  INT16_C( 14359),  INT16_C( 18869), -INT16_C(  8297), -INT16_C(  1400), -INT16_C( 15977), -INT16_C(  9221), -INT16_C( 18986) },
      {  INT16_C(  2159),  INT16_C( 14107),  INT16_C( 18538), -INT16_C(  8152), -INT16_C(  1376), -INT16_C( 15697), -INT16_C(  9060), -INT16_C( 18654) } },
    { { -INT16_C( 15362), -INT16_C( 22453),  INT16_C( 25228), -INT16_C(  1371), -INT16_C(  8594),  INT16_C( 11083),  INT16_C( 23624),  INT16_C( 24060) },
      { -INT16_C( 25516),  INT16_C( 11010), -INT16_C( 25497), -INT16_C(  5185) },
      {  INT16_C( 11962),  INT16_C( 17484), -INT16_C( 19645),  INT16_C(  1068),  INT16_C(  6692), -INT16_C(  8630), -INT16_C( 18396), -INT16_C( 18735) },
      { -INT16_C(  5162), -INT16_C(  7544),  INT16_C(  8477), -INT16_C(   461), -INT16_C(  2888),  INT16_C(  3724),  INT16_C(  7938),  INT16_C(  8084) },
      {  INT16_C( 11953),  INT16_C( 17471), -INT16_C( 19630),  INT16_C(  1067),  INT16_C(  6687), -INT16_C(  8624), -INT16_C( 18382), -INT16_C( 18721) },
      {  INT16_C(  2431),  INT16_C(  3553), -INT16_C(  3992),  INT16_C(   217),  INT16_C(  1360), -INT16_C(  1754), -INT16_C(  3738), -INT16_C(  3807) } },
    { { -INT16_C( 30839), -INT16_C(  4852), -INT16_C(  6945), -INT16_C(  8892), -INT16_C( 28761),  INT16_C( 13189),  INT16_C( 11249),  INT16_C( 24621) },
      {  INT16_C( 30729),  INT16_C( 21131), -INT16_C( 30764),  INT16_C( 10415) },
      { -INT16_C( 28920), -INT16_C(  4550), -INT16_C(  6513), -INT16_C(  8339), -INT16_C( 26971),  INT16_C( 12368),  INT16_C( 10549),  INT16_C( 23089) },
      { -INT16_C( 19887), -INT16_C(  3129), -INT16_C(  4479), -INT16_C(  5734), -INT16_C( 18547),  INT16_C(  8505),  INT16_C(  7254),  INT16_C( 15877) },
      {  INT16_C( 28953),  INT16_C(  4555),  INT16_C(  6520),  INT16_C(  8348),  INT16_C( 27002), -INT16_C( 12382), -INT16_C( 10561), -INT16_C( 23115) },
      { -INT16_C(  9802), -INT16_C(  1542), -INT16_C(  2207), -INT16_C(  2826), -INT16_C(  9141),  INT16_C(  4192),  INT16_C(  3575),  INT16_C(  7826) } },
    { { -INT16_C( 20188), -INT16_C( 29869),  INT16_C(  4942), -INT16_C( 10378), -INT16_C( 32102),  INT16_C( 31428),  INT16_C(  2151),  INT16_C(  3671) },
      { -INT16_C(  8808), -INT16_C( 30398),  INT16_C( 28424),  INT16_C(  4585) },
      {  INT16_C(  5427),  INT16_C(  8029), -INT16_C(  1328),  INT16_C(  2790),  INT16_C(  8629), -INT16_C(  8448), -INT16_C(   578), -INT16_C(   987) },
      {  INT16_C( 18728),  INT16_C( 27709), -INT16_C(  4585),  INT16_C(  9627),  INT16_C( 29780), -INT16_C( 29155), -INT16_C(  1995), -INT16_C(  3405) },
      { -INT16_C( 17512), -INT16_C( 25909),  INT16_C(  4287), -INT16_C(  9002), -INT16_C( 27846),  INT16_C( 27262),  INT16_C(  1866),  INT16_C(  3184) },
      { -INT16_C(  2825), -INT16_C(  4179),  INT16_C(   691), -INT16_C(  1452), -INT16_C(  4492),  INT16_C(  4398),  INT16_C(   301),  INT16_C(   514) } },
    { {  INT16_C( 29928), -INT16_C( 17309),  INT16_C(  4860),  INT16_C(  8421),  INT16_C( 14532),  INT16_C(  4779),  INT16_C(  8779), -INT16_C(  6423) },
      { -INT16_C( 21084),  INT16_C(  2912), -INT16_C( 18506),  INT16_C( 19994) },
      { -INT16_C( 19257),  INT16_C( 11137), -INT16_C(  3127), -INT16_C(  5418), -INT16_C(  9350), -INT16_C(  3075), -INT16_C(  5649),  INT16_C(  4133) },
      {  INT16_C(  2660), -INT16_C(  1538),  INT16_C(   432),  INT16_C(   748),  INT16_C(  1291),  INT16_C(   425),  INT16_C(   780), -INT16_C(   571) },
      { -INT16_C( 16902),  INT16_C(  9775), -INT16_C(  2745), -INT16_C(  4756), -INT16_C(  8207), -INT16_C(  2699), -INT16_C(  4958),  INT16_C(  3627) },
      {  INT16_C( 18261), -INT16_C( 10561),  INT16_C(  2965),  INT16_C(  5138),  INT16_C(  8867),  INT16_C(  2916),  INT16_C(  5357), -INT16_C(  3919) } }
  };

  simde_int16x8_t a, r;
  simde_int16x4_t v;

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    a = simde_vld1q_s16(test_vec[i].a);
    v = simde_vld1_s16(test_vec[i].v);

    r = simde_vqrdmulhq_lane_s16(a, v, 0);
    simde_test_arm_neon_assert_equal_i16x8(r, simde_vld1q_s16(test_vec[i].r0));

    r = simde_vqrdmulhq_lane_s16(a, v, 1);
    simde_test_arm_neon_assert_equal_i16x8(r, simde_vld1q_s16(test_vec[i].r1));

    r = simde_vqrdmulhq_lane_s16(a, v, 2);
    simde_test_arm_neon_assert_equal_i16x8(r, simde_vld1q_s16(test_vec[i].r2));

    r = simde_vqrdmulhq_lane_s16(a, v, 3);
    simde_test_arm_neon_assert_equal_i16x8(r, simde_vld1q_s16(test_vec[i].r3));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int16x8_t a = simde_test_arm_neon_random_i16x8();
    simde_int16x4_t v = simde_test_arm_neon_random_i16x4();
    simde_int16x8_t r;

    simde_test_arm_neon_write_i16x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i16x4(2, v, SIMDE_TEST_VEC_POS_MIDDLE);

    for (int j = 0 ; j < 4 ; j++) {
      SIMDE_CONSTIFY_4_(simde_vqrdmulhq_lane_s16, r, (HEDLEY_UNREACHABLE(), simde_vdupq_n_s16(0)), j, a, v);
      simde_test_arm_neon_write_i16x8(2, r, (j == 3) ? SIMDE_TEST_VEC_POS_LAST : SIMDE_TEST_VEC_POS_MIDDLE);
    }
  }
  return 1;
#endif
}

static int
test_simde_vqrdmulhq_lane_s32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int32_t  a[4];
    int32_t  v[2];
    int32_t r0[4];
    int32_t r1[4];
  } test_vec[] = {
    { {  INT32_C(  1600396871), -INT32_C(   763116834),  INT32_C(  1528235916), -INT32_C(   900750755) },
      { -INT32_C(  1357358971),  INT32_C(  1426552166) },
      { -INT32_C(  1011562091),  INT32_C(   482342895), -INT32_C(   965951351),  INT32_C(   569337103) },
      {  INT32_C(  1063127826), -INT32_C(   506930972),  INT32_C(  1015192017), -INT32_C(   598359825) } },
    { {  INT32_C(  1120382474), -INT32_C(   670597744),  INT32_C(  2050452636), -INT32_C(  1169311186) },
      {  INT32_C(   521561282), -INT32_C(  1930861306) },
      {  INT32_C(   272108298), -INT32_C(   162868676),  INT32_C(   497995273), -INT32_C(   283991658) },
      { -INT32_C(  1007366538),  INT32_C(   602952780), -INT32_C(  1843618068),  INT32_C(  1051359681) } },
    { {  INT32_C(   591069629), -INT32_C(  2122759305), -INT32_C(  2101133071),  INT32_C(  1499122621) },
      {  INT32_C(  1708429623),  INT32_C(   220143947) },
      {  INT32_C(   470225170), -INT32_C(  1688760183), -INT32_C(  1671555443),  INT32_C(  1192626308) },
      {  INT32_C(    60592033), -INT32_C(   217609392), -INT32_C(   215392433),  INT32_C(   153678828) } },
    { { -INT32_C(  1960036987),  INT32_C(  1461130906), -INT32_C(  1904520425), -INT32_C(  2028931946) },
      { -INT32_C(   251014348), -INT32_C(   716479586) },
      {  INT32_C(   229104146), -INT32_C(   170788179),  INT32_C(   222614944),  INT32_C(   237157116) },
      {  INT32_C(   653940481), -INT32_C(   487487049),  INT32_C(   635418112),  INT32_C(   676926375) } },
    { {  INT32_C(  1077551092), -INT32_C(   984786368),  INT32_C(   709917327), -INT32_C(  1484691312) },
      {  INT32_C(  1362558139),  INT32_C(   618153712) },
      {  INT32_C(   683696014), -INT32_C(   624837671),  INT32_C(   450435854), -INT32_C(   942022647) },
      {  INT32_C(   310173355), -INT32_C(   283471005),  INT32_C(   204349882), -INT32_C(   427368770) } },
    { { -INT32_C(  1206459879),  INT32_C(   982344005), -INT32_C(  1065695104), -INT32_C(  1316632798) },
      { -INT32_C(   774122175), -INT32_C(   126264003) },
      {  INT32_C(   434903123), -INT32_C(   354114118),  INT32_C(   384160416),  INT32_C(   474618117) },
      {  INT32_C(    70935327), -INT32_C(    57758152),  INT32_C(    62658884),  INT32_C(    77413082) } },
    { {  INT32_C(  1246343001),  INT32_C(   242098933),  INT32_C(  1237746692),  INT32_C(  1703105765) },
      {  INT32_C(  1042677020),  INT32_C(   116370117) },
      {  INT32_C(   605142306),  INT32_C(   117547342),  INT32_C(   600968503),  INT32_C(   826916305) },
      {  INT32_C(    67538154),  INT32_C(    13119113),  INT32_C(    67072328),  INT32_C(    92289698) } },
    { { -INT32_C(  1109865600), -INT32_C(  2118758104), -INT32_C(   171180288),  INT32_C(   620968481) },
      { -INT32_C(  1536177474),  INT32_C(   973730334) },
      {  INT32_C(   793929460),  INT32_C(  1515628990),  INT32_C(   122451830), -INT32_C(   444202587) },
      { -INT32_C(   503244717), -INT32_C(   960705353), -INT32_C(    77618025),  INT32_C(   281564820) } }
  };

  simde_int32x4_t a, r;
  simde_int32x2_t v;

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    a = simde_vld1q_s32(test_vec[i].a);
    v = simde_vld1_s32(test_vec[i].v);

    r = simde_vqrdmulhq_lane_s32(a, v, 0);
    simde_test_arm_neon_assert_equal_i32x4(r, simde_vld1q_s32(test_vec[i].r0));

    r = simde_vqrdmulhq_lane_s32(a, v, 1);
    simde_test_arm_neon_assert_equal_i32x4(r, simde_vld1q_s32(test_vec[i].r1));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int32x4_t a = simde_test_arm_neon_random_i32x4();
    simde_int32x2_t v = simde_test_arm_neon_random_i32x2();
    simde_int32x4_t r;

    simde_test_arm_neon_write_i32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i32x2(2, v, SIMDE_TEST_VEC_POS_MIDDLE);

    for (int j = 0 ; j < 2 ; j++) {
      SIMDE_CONSTIFY_2_(simde_vqrdmulhq_lane_s32, r, (HEDLEY_UNREACHABLE(), simde_vdupq_n_s32(0)), j, a, v);
      simde_test_arm_neon_write_i32x4(2, r, (j == 1) ? SIMDE_TEST_VEC_POS_LAST : SIMDE_TEST_VEC_POS_MIDDLE);
    }
  }
  return 1;
#endif
}

static int
test_simde_vqrdmulh_laneq_s16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int16_t  a[4];
    int16_t  v[8];
    int16_t r0[4];
    int16_t r1[4];
    int16_t r2[4];
    int16_t r3[4];
    int16_t r4[4];
    int16_t r5[4];
    int16_t r6[4];
    int16_t r7[4];
  } test_vec[] = {
    { {  INT16_C( 14979),  INT16_C(  7136), -INT16_C( 27253), -INT16_C( 24738) },
      { -INT16_C(  2344),  INT16_C( 22290),  INT16_C( 16087),  INT16_C( 23818),  INT16_C( 20590),  INT16_C( 13198),  INT16_C( 30584),  INT16_C( 27956) },
      { -INT16_C(  1071), -INT16_C(   510),  INT16_C(  1949),  INT16_C(  1770) },
      {  INT16_C( 10189),  INT16_C(  4854), -INT16_C( 18538), -INT16_C( 16828) },
      {  INT16_C(  7354),  INT16_C(  3503), -INT16_C( 13379), -INT16_C( 12145) },
      {  INT16_C( 10888),  INT16_C(  5187), -INT16_C( 19809), -INT16_C( 17981) },
      {  INT16_C(  9412),  INT16_C(  4484), -INT16_C( 17125), -INT16_C( 15544) },
      {  INT16_C(  6033),  INT16_C(  2874), -INT16_C( 10977), -INT16_C(  9964) },
      {  INT16_C( 13981),  INT16_C(  6660), -INT16_C( 25437), -INT16_C( 23089) },
      {  INT16_C( 12779),  INT16_C(  6088), -INT16_C( 23251), -INT16_C( 21105) } },
    { { -INT16_C(  5235),  INT16_C( 20317),  INT16_C( 14308),  INT16_C( 26453) },
      {  INT16_C( 13681), -INT16_C(   894), -INT16_C(  7734), -INT16_C( 23909), -INT16_C( 21033), -INT16_C( 20743),  INT16_C(  1003),  INT16_C( 23052) },
      { -INT16_C(  2186),  INT16_C(  8483),  INT16_C(  5974),  INT16_C( 11044) },
      {  INT16_C(   143), -INT16_C(   554), -INT16_C(   390), -INT16_C(   722) },
      {  INT16_C(  1236), -INT16_C(  4795), -INT16_C(  3377), -INT16_C(  6244) },
      {  INT16_C(  3820), -INT16_C( 14824), -INT16_C( 10440), -INT16_C( 19301) },
      {  INT16_C(  3360), -INT16_C( 13041), -INT16_C(  9184), -INT16_C( 16980) },
      {  INT16_C(  3314), -INT16_C( 12861), -INT16_C(  9057), -INT16_C( 16745) },
      { -INT16_C(   160),  INT16_C(   622),  INT16_C(   438),  INT16_C(   810) },
      { -INT16_C(  3683),  INT16_C( 14293),  INT16_C( 10066),  INT16_C( 18609) } },
    { { -INT16_C( 26029), -INT16_C( 13171), -INT16_C( 16111), -INT16_C( 24775) },
      { -INT16_C( 26963), -INT16_C( 28178),  INT16_C( 17357),  INT16_C( 16376),  INT16_C( 31352),  INT16_C( 16955), -INT16_C( 10405),  INT16_C( 13285) },
      {  INT16_C( 21418),  INT16_C( 10838),  INT16_C( 13257),  INT16_C( 20386) },
      {  INT16_C( 22383),  INT16_C( 11326),  INT16_C( 13854),  INT16_C( 21305) },
      { -INT16_C( 13787), -INT16_C(  6977), -INT16_C(  8534), -INT16_C( 13123) },
      { -INT16_C( 13008), -INT16_C(  6582), -INT16_C(  8052), -INT16_C( 12381) },
      { -INT16_C( 24904), -INT16_C( 12602), -INT16_C( 15415), -INT16_C( 23704) },
      { -INT16_C( 13468), -INT16_C(  6815), -INT16_C(  8336), -INT16_C( 12819) },
      {  INT16_C(  8265),  INT16_C(  4182),  INT16_C(  5116),  INT16_C(  7867) },
      { -INT16_C( 10553), -INT16_C(  5340), -INT16_C(  6532), -INT16_C( 10044) } },
    { { -INT16_C(  8572),  INT16_C( 28897), -INT16_C(  4638),  INT16_C( 13770) },
      {  INT16_C( 22408), -INT16_C( 26367),  INT16_C( 15128), -INT16_C( 15048),  INT16_C( 10193), -INT16_C( 24746),  INT16_C( 20074), -INT16_C(  7202) },
      { -INT16_C(  5862),  INT16_C( 19761), -INT16_C(  3172),  INT16_C(  9416) },
      {  INT16_C(  6898), -INT16_C( 23252),  INT16_C(  3732), -INT16_C( 11080) },
      { -INT16_C(  3957),  INT16_C( 13341), -INT16_C(  2141),  INT16_C(  6357) },
      {  INT16_C(  3937), -INT16_C( 13270),  INT16_C(  2130), -INT16_C(  6324) },
      { -INT16_C(  2666),  INT16_C(  8989), -INT16_C(  1443),  INT16_C(  4283) },
      {  INT16_C(  6473), -INT16_C( 21823),  INT16_C(  3503), -INT16_C( 10399) },
      { -INT16_C(  5251),  INT16_C( 17703), -INT16_C(  2841),  INT16_C(  8436) },
      {  INT16_C(  1884), -INT16_C(  6351),  INT16_C(  1019), -INT16_C(  3026) } },
    { {  INT16_C(  6601),  INT16_C(  9253),  INT16_C(  2800),  INT16_C( 30039) },
      {  INT16_C( 14825), -INT16_C( 13339), -INT16_C( 20698), -INT16_C( 20992),  INT16_C(   518),  INT16_C(  7752), -INT16_C( 32707),  INT16_C(  3812) },
      {  INT16_C(  2986),  INT16_C(  4186),  INT16_C(  1267),  INT16_C( 13590) },
      { -INT16_C(  2687), -INT16_C(  3767), -INT16_C(  1140), -INT16_C( 12228) },
      { -INT16_C(  4170), -INT16_C(  5845), -INT16_C(  1769), -INT16_C( 18974) },
      { -INT16_C(  4229), -INT16_C(  5928), -INT16_C(  1794), -INT16_C( 19244) },
      {  INT16_C(   104),  INT16_C(   146),  INT16_C(    44),  INT16_C(   475) },
      {  INT16_C(  1562),  INT16_C(  2189),  INT16_C(   662),  INT16_C(  7106) },
      { -INT16_C(  6589), -INT16_C(  9236), -INT16_C(  2795), -INT16_C( 29983) },
      {  INT16_C(   768),  INT16_C(  1076),  INT16_C(   326),  INT16_C(  3495) } },
    { {  INT16_C( 15015),  INT16_C(  4781), -INT16_C( 29815),  INT16_C( 21237) },
      {  INT16_C(  6821), -INT16_C( 27274), -INT16_C( 12763),  INT16_C(  3594), -INT16_C(  4345),  INT16_C( 11737), -INT16_C(  9826), -INT16_C( 23332) },
      {  INT16_C(  3126),  INT16_C(   995), -INT16_C(  6206),  INT16_C(  4421) },
      { -INT16_C( 12498), -INT16_C(  3979),  INT16_C( 24816), -INT16_C( 17676) },
      { -INT16_C(  5848), -INT16_C(  1862),  INT16_C( 11613), -INT16_C(  8272) },
      {  INT16_C(  1647),  INT16_C(   524), -INT16_C(  3270),  INT16_C(  2329) },
      { -INT16_C(  1991), -INT16_C(   634),  INT16_C(  3953), -INT16_C(  2816) },
      {  INT16_C(  5378),  INT16_C(  1712), -INT16_C( 10679),  INT16_C(  7607) },
      { -INT16_C(  4502), -INT16_C(  1434),  INT16_C(  8940), -INT16_C(  6368) },
      { -INT16_C( 10691), -INT16_C(  3404),  INT16_C( 21229), -INT16_C( 15122) } },
    { {  INT16_C(  9435),  INT16_C(  6339), -INT16_C( 22620),  INT16_C( 19495) },
      { -INT16_C( 11039),  INT16_C( 27230),  INT16_C( 21344),  INT16_C(  1468),  INT16_C( 13165), -INT16_C( 28006), -INT16_C( 23295),  INT16_C(  2208) },
      { -INT16_C(  3178), -INT16_C(  2136),  INT16_C(  7620), -INT16_C(  6568) },
      {  INT16_C(  7840),  INT16_C(  5268), -INT16_C( 18797),  INT16_C( 16200) },
      {  INT16_C(  6146),  INT16_C(  4129), -INT16_C( 14734),  INT16_C( 12698) },
      {  INT16_C(   423),  INT16_C(   284), -INT16_C(  1013),  INT16_C(   873) },
      {  INT16_C(  3791),  INT16_C(  2547), -INT16_C(  9088),  INT16_C(  7832) },
      { -INT16_C(  8064), -INT16_C(  5418),  INT16_C( 19333), -INT16_C( 16662) },
      { -INT16_C(  6707), -INT16_C(  4506),  INT16_C( 16081), -INT16_C( 13859) },
      {  INT16_C(   636),  INT16_C(   427), -INT16_C(  1524),  INT16_C(  1314) } },
    { {  INT16_C( 31124),  INT16_C( 13109),  INT16_C(  4435),  INT16_C( 11991) },
      { -INT16_C( 26059), -INT16_C(  9657),  INT16_C( 28225),  INT16_C(  8998), -INT16_C( 31678), -INT16_C( 23923),  INT16_C( 19159),  INT16_C( 17575) },
      { -INT16_C( 24752), -INT16_C( 10425), -INT16_C(  3527), -INT16_C(  9536) },
      { -INT16_C(  9172), -INT16_C(  3863), -INT16_C(  1307), -INT16_C(  3534) },
      {  INT16_C( 26809),  INT16_C( 11292),  INT16_C(  3820),  INT16_C( 10329) },
      {  INT16_C(  8547),  INT16_C(  3600),  INT16_C(  1218),  INT16_C(  3293) },
      { -INT16_C( 30089), -INT16_C( 12673), -INT16_C(  4287), -INT16_C( 11592) },
      { -INT16_C( 22723), -INT16_C(  9571), -INT16_C(  3238), -INT16_C(  8754) },
      {  INT16_C( 18198),  INT16_C(  7665),  INT16_C(  2593),  INT16_C(  7011) },
      {  INT16_C( 16693),  INT16_C(  7031),  INT16_C(  2379),  INT16_C(  6431) } }
  };

  simde_int16x4_t a, r;
  simde_int16x8_t v;

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    a = simde_vld1_s16(test_vec[i].a);
    v = simde_vld1q_s16(test_vec[i].v);

    r = simde_vqrdmulh_laneq_s16(a, v, 0);
    simde_test_arm_neon_assert_equal_i16x4(r, simde_vld1_s16(test_vec[i].r0));

    r = simde_vqrdmulh_laneq_s16(a, v, 1);
    simde_test_arm_neon_assert_equal_i16x4(r, simde_vld1_s16(test_vec[i].r1));

    r = simde_vqrdmulh_laneq_s16(a, v, 2);
    simde_test_arm_neon_assert_equal_i16x4(r, simde_vld1_s16(test_vec[i].r2));

    r = simde_vqrdmulh_laneq_s16(a, v, 3);
    simde_test_arm_neon_assert_equal_i16x4(r, simde_vld1_s16(test_vec[i].r3));

    r = simde_vqrdmulh_laneq_s16(a, v, 4);
    simde_test_arm_neon_assert_equal_i16x4(r, simde_vld1_s16(test_vec[i].r4));

    r = simde_vqrdmulh_laneq_s16(a, v, 5);
    simde_test_arm_neon_assert_equal_i16x4(r, simde_vld1_s16(test_vec[i].r5));

    r = simde_vqrdmulh_laneq_s16(a, v, 6);
    simde_test_arm_neon_assert_equal_i16x4(r, simde_vld1_s16(test_vec[i].r6));

    r = simde_vqrdmulh_laneq_s16(a, v, 7);
    simde_test_arm_neon_assert_equal_i16x4(r, simde_vld1_s16(test_vec[i].r7));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int16x4_t a = simde_test_arm_neon_random_i16x4();
    simde_int16x8_t v = simde_test_arm_neon_random_i16x8();
    simde_int16x4_t r;

    simde_test_arm_neon_write_i16x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i16x8(2, v, SIMDE_TEST_VEC_POS_MIDDLE);

    for (int j = 0 ; j < 8 ; j++) {
      SIMDE_CONSTIFY_8_(simde_vqrdmulh_laneq_s16, r, (HEDLEY_UNREACHABLE(), simde_vdup_n_s16(0)), j, a, v);
      simde_test_arm_neon_write_i16x4(2, r, (j == 7) ? SIMDE_TEST_VEC_POS_LAST : SIMDE_TEST_VEC_POS_MIDDLE);
    }
  }
  return 1;
#endif
}

static int
test_simde_vqrdmulh_laneq_s32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int32_t  a[2];
    int32_t  v[4];
    int32_t r0[2];
    int32_t r1[2];
    int32_t r2[2];
    int32_t r3[2];
  } test_vec[] = {
    { { -INT32_C(  1333187498),  INT32_C(  2130802340) },
      { -INT32_C(  1677229020), -INT32_C(  1408291141),  INT32_C(  2068609063),  INT32_C(  1429203284) },
      {  INT32_C(  1041246932), -INT32_C(  1664200574) },
      {  INT32_C(   874286584), -INT32_C(  1397351762) },
      { -INT32_C(  1284221067),  INT32_C(  2052540440) },
      { -INT32_C(   887269131),  INT32_C(  1418101462) } },
    { { -INT32_C(   120244588), -INT32_C(  1833189061) },
      { -INT32_C(  1841150738), -INT32_C(   569228102), -INT32_C(  2089084472),  INT32_C(  1848609351) },
      {  INT32_C(   103092013),  INT32_C(  1571689450) },
      {  INT32_C(    31872931),  INT32_C(   485918824) },
      {  INT32_C(   116974628),  INT32_C(  1783336886) },
      { -INT32_C(   103509645), -INT32_C(  1578056459) } },
    { {  INT32_C(  1458207490), -INT32_C(   123004572) },
      { -INT32_C(  1947172529),  INT32_C(   807250754), -INT32_C(  1430036497),  INT32_C(  1804129699) },
      { -INT32_C(  1322190075),  INT32_C(   111531058) },
      {  INT32_C(   548148107), -INT32_C(    46238086) },
      { -INT32_C(   971038794),  INT32_C(    81910299) },
      {  INT32_C(  1225059591), -INT32_C(   103337784) } },
    { {  INT32_C(   904791022), -INT32_C(  1885135475) },
      { -INT32_C(    52064872), -INT32_C(   151678553),  INT32_C(  1417798930), -INT32_C(  2138726767) },
      { -INT32_C(    21936292),  INT32_C(    45704347) },
      { -INT32_C(    63906141),  INT32_C(   133148684) },
      {  INT32_C(   597355768), -INT32_C(  1244592974) },
      { -INT32_C(   901101519),  INT32_C(  1877448382) } },
    { { -INT32_C(  1591064322),  INT32_C(   185447197) },
      {  INT32_C(  1145109430), -INT32_C(  1311513831),  INT32_C(   414103921),  INT32_C(  1544463178) },
      { -INT32_C(   848408210),  INT32_C(    98886590) },
      {  INT32_C(   971696742), -INT32_C(   113256538) },
      { -INT32_C(   306808378),  INT32_C(    35760184) },
      { -INT32_C(  1144288228),  INT32_C(   133373014) } },
    { {  INT32_C(   431001736),  INT32_C(   748303662) },
      { -INT32_C(  1697725315),  INT32_C(   782621559), -INT32_C(   277682730),  INT32_C(   983647689) },
      { -INT32_C(   340734868), -INT32_C(   591582651) },
      {  INT32_C(   157072791),  INT32_C(   272709214) },
      { -INT32_C(    55731153), -INT32_C(    96760226) },
      {  INT32_C(   197418901),  INT32_C(   342757985) } },
    { {  INT32_C(  1213353982),  INT32_C(  2057593074) },
      {  INT32_C(   529815024),  INT32_C(   139144842),  INT32_C(  1789008370), -INT32_C(   879212300) },
      {  INT32_C(   299351834),  INT32_C(   507637730) },
      {  INT32_C(    78618502),  INT32_C(   133320439) },
      {  INT32_C(  1010811156),  INT32_C(  1714123055) },
      { -INT32_C(   496765480), -INT32_C(   842409739) } },
    { { -INT32_C(   155579859),  INT32_C(  1311791951) },
      { -INT32_C(  1667857750), -INT32_C(   753452061),  INT32_C(   452111248), -INT32_C(   886948135) },
      {  INT32_C(   120832153), -INT32_C(  1018812122) },
      {  INT32_C(    54585731), -INT32_C(   460246740) },
      { -INT32_C(    32754338),  INT32_C(   276172485) },
      {  INT32_C(    64257190), -INT32_C(   541792914) } }
  };

  simde_int32x2_t a, r;
  simde_int32x4_t v;

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    a = simde_vld1_s32(test_vec[i].a);
    v = simde_vld1q_s32(test_vec[i].v);

    r = simde_vqrdmulh_laneq_s32(a, v, 0);
    simde_test_arm_neon_assert_equal_i32x2(r, simde_vld1_s32(test_vec[i].r0));

    r = simde_vqrdmulh_laneq_s32(a, v, 1);
    simde_test_arm_neon_assert_equal_i32x2(r, simde_vld1_s32(test_vec[i].r1));

    r = simde_vqrdmulh_laneq_s32(a, v, 2);
    simde_test_arm_neon_assert_equal_i32x2(r, simde_vld1_s32(test_vec[i].r2));

    r = simde_vqrdmulh_laneq_s32(a, v, 3);
    simde_test_arm_neon_assert_equal_i32x2(r, simde_vld1_s32(test_vec[i].r3));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int32x2_t a = simde_test_arm_neon_random_i32x2();
    simde_int32x4_t v = simde_test_arm_neon_random_i32x4();
    simde_int32x2_t r;

    simde_test_arm_neon_write_i32x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i32x4(2, v, SIMDE_TEST_VEC_POS_MIDDLE);

    for (int j = 0 ; j < 4 ; j++) {
      SIMDE_CONSTIFY_4_(simde_vqrdmulh_laneq_s32, r, (HEDLEY_UNREACHABLE(), simde_vdup_n_s32(0)), j, a, v);
      simde_test_arm_neon_write_i32x2(2, r, (j == 3) ? SIMDE_TEST_VEC_POS_LAST : SIMDE_TEST_VEC_POS_MIDDLE);
    }
  }
  return 1;
#endif
}

static int
test_simde_vqrdmulhq_laneq_s16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int16_t  a[8];
    int16_t  v[8];
    int16_t r0[8];
    int16_t r1[8];
    int16_t r2[8];
    int16_t r3[8];
    int16_t r4[8];
    int16_t r5[8];
    int16_t r6[8];
    int16_t r7[8];
  } test_vec[] = {
    { {  INT16_C( 23782), -INT16_C( 16953),  INT16_C(  8865), -INT16_C(  4628), -INT16_C( 31572), -INT16_C( 23834),  INT16_C(   837), -INT16_C(  4146) },
      {  INT16_C( 20271),  INT16_C(  7328), -INT16_C( 19850), -INT16_C( 27782),  INT16_C( 31896),  INT16_C( 30243), -INT16_C( 15110), -INT16_C(  7878) },
      {  INT16_C( 14712), -INT16_C( 10487),  INT16_C(  5484), -INT16_C(  2863), -INT16_C( 19531), -INT16_C( 14744),  INT16_C(   518), -INT16_C(  2565) },
      {  INT16_C(  5318), -INT16_C(  3791),  INT16_C(  1983), -INT16_C(  1035), -INT16_C(  7061), -INT16_C(  5330),  INT16_C(   187), -INT16_C(   927) },
      { -INT16_C( 14407),  INT16_C( 10270), -INT16_C(  5370),  INT16_C(  2804),  INT16_C( 19125),  INT16_C( 14438), -INT16_C(   507),  INT16_C(  2512) },
      { -INT16_C( 20163),  INT16_C( 14373), -INT16_C(  7516),  INT16_C(  3924),  INT16_C( 26768),  INT16_C( 20207), -INT16_C(   710),  INT16_C(  3515) },
      {  INT16_C( 23149), -INT16_C( 16502),  INT16_C(  8629), -INT16_C(  4505), -INT16_C( 30732), -INT16_C( 23200),  INT16_C(   815), -INT16_C(  4036) },
      {  INT16_C( 21949), -INT16_C( 15647),  INT16_C(  8182), -INT16_C(  4271), -INT16_C( 29139), -INT16_C( 21997),  INT16_C(   773), -INT16_C(  3827) },
      { -INT16_C( 10966),  INT16_C(  7817), -INT16_C(  4088),  INT16_C(  2134),  INT16_C( 14558),  INT16_C( 10990), -INT16_C(   386),  INT16_C(  1912) },
      { -INT16_C(  5718),  INT16_C(  4076), -INT16_C(  2131),  INT16_C(  1113),  INT16_C(  7590),  INT16_C(  5730), -INT16_C(   201),  INT16_C(   997) } },
    { {  INT16_C(   288), -INT16_C( 15970), -INT16_C( 29917), -INT16_C( 12114), -INT16_C( 27633),  INT16_C( 21618),  INT16_C( 16536), -INT16_C( 14525) },
      { -INT16_C(  7280),  INT16_C(  1763),  INT16_C( 23958),  INT16_C( 11929), -INT16_C( 16935), -INT16_C( 11356), -INT16_C(  8575), -INT16_C( 24140) },
      { -INT16_C(    64),  INT16_C(  3548),  INT16_C(  6647),  INT16_C(  2691),  INT16_C(  6139), -INT16_C(  4803), -INT16_C(  3674),  INT16_C(  3227) },
      {  INT16_C(    15), -INT16_C(   859), -INT16_C(  1610), -INT16_C(   652), -INT16_C(  1487),  INT16_C(  1163),  INT16_C(   890), -INT16_C(   781) },
      {  INT16_C(   211), -INT16_C( 11676), -INT16_C( 21874), -INT16_C(  8857), -INT16_C( 20204),  INT16_C( 15806),  INT16_C( 12090), -INT16_C( 10620) },
      {  INT16_C(   105), -INT16_C(  5814), -INT16_C( 10891), -INT16_C(  4410), -INT16_C( 10060),  INT16_C(  7870),  INT16_C(  6020), -INT16_C(  5288) },
      { -INT16_C(   149),  INT16_C(  8254),  INT16_C( 15462),  INT16_C(  6261),  INT16_C( 14281), -INT16_C( 11173), -INT16_C(  8546),  INT16_C(  7507) },
      { -INT16_C(   100),  INT16_C(  5535),  INT16_C( 10368),  INT16_C(  4198),  INT16_C(  9576), -INT16_C(  7492), -INT16_C(  5731),  INT16_C(  5034) },
      { -INT16_C(    75),  INT16_C(  4179),  INT16_C(  7829),  INT16_C(  3170),  INT16_C(  7231), -INT16_C(  5657), -INT16_C(  4327),  INT16_C(  3801) },
      { -INT16_C(   212),  INT16_C( 11765),  INT16_C( 22040),  INT16_C(  8924),  INT16_C( 20357), -INT16_C( 15926), -INT16_C( 12182),  INT16_C( 10700) } },
    { {  INT16_C( 21471),  INT16_C(   866),  INT16_C(  4574), -INT16_C(  4653),  INT16_C( 17829),  INT16_C( 15682), -INT16_C( 31354),  INT16_C(  5636) },
      { -INT16_C(  6295), -INT16_C(   228), -INT16_C( 18876),  INT16_C(  7469), -INT16_C( 11917), -INT16_C(  2831), -INT16_C( 23121), -INT16_C( 29035) },
      { -INT16_C(  4125), -INT16_C(   166), -INT16_C(   879),  INT16_C(   894), -INT16_C(  3425), -INT16_C(  3013),  INT16_C(  6023), -INT16_C(  1083) },
      { -INT16_C(   149), -INT16_C(     6), -INT16_C(    32),  INT16_C(    32), -INT16_C(   124), -INT16_C(   109),  INT16_C(   218), -INT16_C(    39) },
      { -INT16_C( 12368), -INT16_C(   499), -INT16_C(  2635),  INT16_C(  2680), -INT16_C( 10270), -INT16_C(  9034),  INT16_C( 18061), -INT16_C(  3247) },
      {  INT16_C(  4894),  INT16_C(   197),  INT16_C(  1043), -INT16_C(  1061),  INT16_C(  4064),  INT16_C(  3574), -INT16_C(  7147),  INT16_C(  1285) },
      { -INT16_C(  7809), -INT16_C(   315), -INT16_C(  1663),  INT16_C(  1692), -INT16_C(  6484), -INT16_C(  5703),  INT16_C( 11403), -INT16_C(  2050) },
      { -INT16_C(  1855), -INT16_C(    75), -INT16_C(   395),  INT16_C(   402), -INT16_C(  1540), -INT16_C(  1355),  INT16_C(  2709), -INT16_C(   487) },
      { -INT16_C( 15150), -INT16_C(   611), -INT16_C(  3227),  INT16_C(  3283), -INT16_C( 12580), -INT16_C( 11065),  INT16_C( 22123), -INT16_C(  3977) },
      { -INT16_C( 19025), -INT16_C(   767), -INT16_C(  4053),  INT16_C(  4123), -INT16_C( 15798), -INT16_C( 13895),  INT16_C( 27782), -INT16_C(  4994) } },
    { { -INT16_C(  2056), -INT16_C( 10607),  INT16_C( 25608), -INT16_C( 20796),  INT16_C(  1706),  INT16_C( 12523), -INT16_C(  3957), -INT16_C(  3002) },
      {  INT16_C( 25303),  INT16_C(  7411),  INT16_C(  8216), -INT16_C( 29895),  INT16_C( 10993), -INT16_C( 24449),  INT16_C(  5328), -INT16_C( 14289) },
      { -INT16_C(  1588), -INT16_C(  8191),  INT16_C( 19774), -INT16_C( 16058),  INT16_C(  1317),  INT16_C(  9670), -INT16_C(  3056), -INT16_C(  2318) },
      { -INT16_C(   465), -INT16_C(  2399),  INT16_C(  5792), -INT16_C(  4703),  INT16_C(   386),  INT16_C(  2832), -INT16_C(   895), -INT16_C(   679) },
      { -INT16_C(   516), -INT16_C(  2660),  INT16_C(  6421), -INT16_C(  5214),  INT16_C(   428),  INT16_C(  3140), -INT16_C(   992), -INT16_C(   753) },
      {  INT16_C(  1876),  INT16_C(  9677), -INT16_C( 23363),  INT16_C( 18973), -INT16_C(  1556), -INT16_C( 11425),  INT16_C(  3610),  INT16_C(  2739) },
      { -INT16_C(   690), -INT16_C(  3558),  INT16_C(  8591), -INT16_C(  6977),  INT16_C(   572),  INT16_C(  4201), -INT16_C(  1327), -INT16_C(  1007) },
      {  INT16_C(  1534),  INT16_C(  7914), -INT16_C( 19107),  INT16_C( 15516), -INT16_C(  1273), -INT16_C(  9344),  INT16_C(  2952),  INT16_C(  2240) },
      { -INT16_C(   334), -INT16_C(  1725),  INT16_C(  4164), -INT16_C(  3381),  INT16_C(   277),  INT16_C(  2036), -INT16_C(   643), -INT16_C(   488) },
      {  INT16_C(   897),  INT16_C(  4625), -INT16_C( 11167),  INT16_C(  9068), -INT16_C(   744), -INT16_C(  5461),  INT16_C(  1726),  INT16_C(  1309) } },
    { { -INT16_C( 16372),  INT16_C(  5279),  INT16_C( 25381), -INT16_C( 12350), -INT16_C( 20887), -INT16_C(  2817),  INT16_C( 17822),  INT16_C( 30185) },
      { -INT16_C(  9049), -INT16_C( 16239), -INT16_C( 13315), -INT16_C(  4533), -INT16_C( 13323), -INT16_C( 14961), -INT16_C( 16673), -INT16_C(  5234) },
      {  INT16_C(  4521), -INT16_C(  1458), -INT16_C(  7009),  INT16_C(  3410),  INT16_C(  5768),  INT16_C(   778), -INT16_C(  4922), -INT16_C(  8336) },
      {  INT16_C(  8114), -INT16_C(  2616), -INT16_C( 12578),  INT16_C(  6120),  INT16_C( 10351),  INT16_C(  1396), -INT16_C(  8832), -INT16_C( 14959) },
      {  INT16_C(  6653), -INT16_C(  2145), -INT16_C( 10313),  INT16_C(  5018),  INT16_C(  8487),  INT16_C(  1145), -INT16_C(  7242), -INT16_C( 12265) },
      {  INT16_C(  2265), -INT16_C(   730), -INT16_C(  3511),  INT16_C(  1708),  INT16_C(  2889),  INT16_C(   390), -INT16_C(  2465), -INT16_C(  4176) },
      {  INT16_C(  6657), -INT16_C(  2146), -INT16_C( 10320),  INT16_C(  5021),  INT16_C(  8492),  INT16_C(  1145), -INT16_C(  7246), -INT16_C( 12273) },
      {  INT16_C(  7475), -INT16_C(  2410), -INT16_C( 11588),  INT16_C(  5639),  INT16_C(  9536),  INT16_C(  1286), -INT16_C(  8137), -INT16_C( 13782) },
      {  INT16_C(  8330), -INT16_C(  2686), -INT16_C( 12914),  INT16_C(  6284),  INT16_C( 10628),  INT16_C(  1433), -INT16_C(  9068), -INT16_C( 15359) },
      {  INT16_C(  2615), -INT16_C(   843), -INT16_C(  4054),  INT16_C(  1973),  INT16_C(  3336),  INT16_C(   450), -INT16_C(  2847), -INT16_C(  4821) } },
    { {  INT16_C( 11646), -INT16_C( 23808), -INT16_C( 15728), -INT16_C(  1678),  INT16_C( 29040),  INT16_C(  3821), -INT16_C( 10570),  INT16_C( 24196) },
      {  INT16_C(  5555), -INT16_C( 20450),  INT16_C( 27104), -INT16_C( 10594),  INT16_C( 11572),  INT16_C(  5275),  INT16_C( 10731),  INT16_C( 27391) },
      {  INT16_C(  1974), -INT16_C(  4036), -INT16_C(  2666), -INT16_C(   284),  INT16_C(  4923),  INT16_C(   648), -INT16_C(  1792),  INT16_C(  4102) },
      { -INT16_C(  7268),  INT16_C( 14858),  INT16_C(  9816),  INT16_C(  1047), -INT16_C( 18123), -INT16_C(  2385),  INT16_C(  6597), -INT16_C( 15100) },
      {  INT16_C(  9633), -INT16_C( 19693), -INT16_C( 13009), -INT16_C(  1388),  INT16_C( 24020),  INT16_C(  3161), -INT16_C(  8743),  INT16_C( 20014) },
      { -INT16_C(  3765),  INT16_C(  7697),  INT16_C(  5085),  INT16_C(   543), -INT16_C(  9389), -INT16_C(  1235),  INT16_C(  3417), -INT16_C(  7823) },
      {  INT16_C(  4113), -INT16_C(  8408), -INT16_C(  5554), -INT16_C(   593),  INT16_C( 10255),  INT16_C(  1349), -INT16_C(  3733),  INT16_C(  8545) },
      {  INT16_C(  1875), -INT16_C(  3833), -INT16_C(  2532), -INT16_C(   270),  INT16_C(  4675),  INT16_C(   615), -INT16_C(  1702),  INT16_C(  3895) },
      {  INT16_C(  3814), -INT16_C(  7797), -INT16_C(  5151), -INT16_C(   550),  INT16_C(  9510),  INT16_C(  1251), -INT16_C(  3462),  INT16_C(  7924) },
      {  INT16_C(  9735), -INT16_C( 19901), -INT16_C( 13147), -INT16_C(  1403),  INT16_C( 24275),  INT16_C(  3194), -INT16_C(  8836),  INT16_C( 20226) } },
    { { -INT16_C(   170), -INT16_C(  6643), -INT16_C( 32574),  INT16_C( 13023), -INT16_C( 12815), -INT16_C( 22463), -INT16_C( 14941),  INT16_C( 22022) },
      {  INT16_C(  9434), -INT16_C( 17658), -INT16_C( 23155), -INT16_C( 15727),  INT16_C( 11474), -INT16_C( 16682), -INT16_C( 10922), -INT16_C( 21464) },
      { -INT16_C(    49), -INT16_C(  1913), -INT16_C(  9378),  INT16_C(  3749), -INT16_C(  3689), -INT16_C(  6467), -INT16_C(  4302),  INT16_C(  6340) },
      {  INT16_C(    92),  INT16_C(  3580),  INT16_C( 17553), -INT16_C(  7018),  INT16_C(  6906),  INT16_C( 12105),  INT16_C(  8051), -INT16_C( 11867) },
      {  INT16_C(   120),  INT16_C(  4694),  INT16_C( 23018), -INT16_C(  9203),  INT16_C(  9056),  INT16_C( 15873),  INT16_C( 10558), -INT16_C( 15562) },
      {  INT16_C(    82),  INT16_C(  3188),  INT16_C( 15634), -INT16_C(  6250),  INT16_C(  6151),  INT16_C( 10781),  INT16_C(  7171), -INT16_C( 10569) },
      { -INT16_C(    60), -INT16_C(  2326), -INT16_C( 11406),  INT16_C(  4560), -INT16_C(  4487), -INT16_C(  7866), -INT16_C(  5232),  INT16_C(  7711) },
      {  INT16_C(    87),  INT16_C(  3382),  INT16_C( 16583), -INT16_C(  6630),  INT16_C(  6524),  INT16_C( 11436),  INT16_C(  7606), -INT16_C( 11211) },
      {  INT16_C(    57),  INT16_C(  2214),  INT16_C( 10857), -INT16_C(  4341),  INT16_C(  4271),  INT16_C(  7487),  INT16_C(  4980), -INT16_C(  7340) },
      {  INT16_C(   111),  INT16_C(  4351),  INT16_C( 21337), -INT16_C(  8530),  INT16_C(  8394),  INT16_C( 14714),  INT16_C(  9787), -INT16_C( 14425) } },
    { {  INT16_C( 13781), -INT16_C( 26733),  INT16_C( 29365), -INT16_C( 22583),  INT16_C(  2623), -INT16_C(  7345),  INT16_C( 21967), -INT16_C( 21959) },
      {  INT16_C( 16505),  INT16_C(  1637), -INT16_C(  2331), -INT16_C( 18488), -INT16_C( 25054),  INT16_C( 30837), -INT16_C( 25228),  INT16_C( 18725) },
      {  INT16_C(  6941), -INT16_C( 13465),  INT16_C( 14791), -INT16_C( 11375),  INT16_C(  1321), -INT16_C(  3700),  INT16_C( 11065), -INT16_C( 11061) },
      {  INT16_C(   688), -INT16_C(  1336),  INT16_C(  1467), -INT16_C(  1128),  INT16_C(   131), -INT16_C(   367),  INT16_C(  1097), -INT16_C(  1097) },
      { -INT16_C(   980),  INT16_C(  1902), -INT16_C(  2089),  INT16_C(  1606), -INT16_C(   187),  INT16_C(   522), -INT16_C(  1563),  INT16_C(  1562) },
      { -INT16_C(  7775),  INT16_C( 15083), -INT16_C( 16568),  INT16_C( 12742), -INT16_C(  1480),  INT16_C(  4144), -INT16_C( 12394),  INT16_C( 12389) },
      { -INT16_C( 10537),  INT16_C( 20440), -INT16_C( 22452),  INT16_C( 17267), -INT16_C(  2006),  INT16_C(  5616), -INT16_C( 16796),  INT16_C( 16790) },
      {  INT16_C( 12969), -INT16_C( 25158),  INT16_C( 27635), -INT16_C( 21252),  INT16_C(  2468), -INT16_C(  6912),  INT16_C( 20672), -INT16_C( 20665) },
      { -INT16_C( 10610),  INT16_C( 20582), -INT16_C( 22608),  INT16_C( 17387), -INT16_C(  2019),  INT16_C(  5655), -INT16_C( 16912),  INT16_C( 16906) },
      {  INT16_C(  7875), -INT16_C( 15276),  INT16_C( 16780), -INT16_C( 12905),  INT16_C(  1499), -INT16_C(  4197),  INT16_C( 12553), -INT16_C( 12548) } }
  };

  simde_int16x8_t a, v, r;

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    a = simde_vld1q_s16(test_vec[i].a);
    v = simde_vld1q_s16(test_vec[i].v);

    r = simde_vqrdmulhq_laneq_s16(a, v, 0);
    simde_test_arm_neon_assert_equal_i16x8(r, simde_vld1q_s16(test_vec[i].r0));

    r = simde_vqrdmulhq_laneq_s16(a, v, 1);
    simde_test_arm_neon_assert_equal_i16x8(r, simde_vld1q_s16(test_vec[i].r1));

    r = simde_vqrdmulhq_laneq_s16(a, v, 2);
    simde_test_arm_neon_assert_equal_i16x8(r, simde_vld1q_s16(test_vec[i].r2));

    r = simde_vqrdmulhq_laneq_s16(a, v, 3);
    simde_test_arm_neon_assert_equal_i16x8(r, simde_vld1q_s16(test_vec[i].r3));

    r = simde_vqrdmulhq_laneq_s16(a, v, 4);
    simde_test_arm_neon_assert_equal_i16x8(r, simde_vld1q_s16(test_vec[i].r4));

    r = simde_vqrdmulhq_laneq_s16(a, v, 5);
    simde_test_arm_neon_assert_equal_i16x8(r, simde_vld1q_s16(test_vec[i].r5));

    r = simde_vqrdmulhq_laneq_s16(a, v, 6);
    simde_test_arm_neon_assert_equal_i16x8(r, simde_vld1q_s16(test_vec[i].r6));

    r = simde_vqrdmulhq_laneq_s16(a, v, 7);
    simde_test_arm_neon_assert_equal_i16x8(r, simde_vld1q_s16(test_vec[i].r7));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int16x8_t a = simde_test_arm_neon_random_i16x8();
    simde_int16x8_t v = simde_test_arm_neon_random_i16x8();
    simde_int16x8_t r;

    simde_test_arm_neon_write_i16x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i16x8(2, v, SIMDE_TEST_VEC_POS_MIDDLE);

    for (int j = 0 ; j < 8 ; j++) {
      SIMDE_CONSTIFY_8_(simde_vqrdmulhq_laneq_s16, r, (HEDLEY_UNREACHABLE(), simde_vdupq_n_s16(0)), j, a, v);
      simde_test_arm_neon_write_i16x8(2, r, (j == 7) ? SIMDE_TEST_VEC_POS_LAST : SIMDE_TEST_VEC_POS_MIDDLE);
    }
  }
  return 1;
#endif
}

static int
test_simde_vqrdmulhq_laneq_s32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int32_t  a[4];
    int32_t  v[4];
    int32_t r0[4];
    int32_t r1[4];
    int32_t r2[4];
    int32_t r3[4];
  } test_vec[] = {
    { {  INT32_C(   315573881), -INT32_C(   688066828),  INT32_C(  1226357315), -INT32_C(   754213182) },
      { -INT32_C(   586633041),  INT32_C(   377170036), -INT32_C(    94128825), -INT32_C(  1504767187) },
      { -INT32_C(    86206042),  INT32_C(   187960796), -INT32_C(   335006845),  INT32_C(   206030147) },
      {  INT32_C(    55425340), -INT32_C(   120847575),  INT32_C(   215389408), -INT32_C(   132465089) },
      { -INT32_C(    13832282),  INT32_C(    30159448), -INT32_C(    53753878),  INT32_C(    33058785) },
      { -INT32_C(   221126350),  INT32_C(   482136563), -INT32_C(   859323073),  INT32_C(   528486095) } },
    { {  INT32_C(  1320689241),  INT32_C(  1344582924),  INT32_C(   848903279), -INT32_C(  1996118822) },
      { -INT32_C(   916058795),  INT32_C(  2095112501), -INT32_C(  1015659626), -INT32_C(  1335245226) },
      { -INT32_C(   563370527), -INT32_C(   573562930), -INT32_C(   362119318),  INT32_C(   851490629) },
      {  INT32_C(  1288481308),  INT32_C(  1311792290),  INT32_C(   828200892), -INT32_C(  1947439042) },
      { -INT32_C(   624624426), -INT32_C(   635925024), -INT32_C(   401491666),  INT32_C(   944071122) },
      { -INT32_C(   821167605), -INT32_C(   836024028), -INT32_C(   527824299),  INT32_C(  1241130814) } },
    { { -INT32_C(   235003164),  INT32_C(  1178673879),  INT32_C(   947444318), -INT32_C(   742293890) },
      { -INT32_C(  1046665333), -INT32_C(  1640137464),  INT32_C(   392279232),  INT32_C(  1590151802) },
      {  INT32_C(   114538551), -INT32_C(   574475661), -INT32_C(   461776332),  INT32_C(   361787752) },
      {  INT32_C(   179483319), -INT32_C(   900210434), -INT32_C(   723609198),  INT32_C(   566925862) },
      { -INT32_C(    42927852),  INT32_C(   215307476),  INT32_C(   173068945), -INT32_C(   135594270) },
      { -INT32_C(   174013295),  INT32_C(   872775164),  INT32_C(   701556117), -INT32_C(   549647942) } },
    { { -INT32_C(  1018182164),  INT32_C(  1158320359), -INT32_C(   377650582), -INT32_C(  1933820416) },
      {  INT32_C(  1833785701), -INT32_C(  1760851242), -INT32_C(  1196528578),  INT32_C(   588739894) },
      { -INT32_C(   869449178),  INT32_C(   989116408), -INT32_C(   322484522), -INT32_C(  1651333751) },
      {  INT32_C(   834868908), -INT32_C(   949776658),  INT32_C(   309658468),  INT32_C(  1585655884) },
      {  INT32_C(   567307722), -INT32_C(   645389507),  INT32_C(   210418233),  INT32_C(  1077480331) },
      { -INT32_C(   279138079),  INT32_C(   317557438), -INT32_C(   103534182), -INT32_C(   530163397) } },
    { {  INT32_C(   568747578),  INT32_C(  1634136311),  INT32_C(  1934287731), -INT32_C(  2030106847) },
      {  INT32_C(   938691680),  INT32_C(   365887191), -INT32_C(  1597080470),  INT32_C(   734258673) },
      {  INT32_C(   248606605),  INT32_C(   714301206),  INT32_C(   845501106), -INT32_C(   887384828) },
      {  INT32_C(    96902928),  INT32_C(   278423328),  INT32_C(   329562977), -INT32_C(   345888590) },
      { -INT32_C(   422976748), -INT32_C(  1215304801), -INT32_C(  1438526976),  INT32_C(  1509787514) },
      {  INT32_C(   194463805),  INT32_C(   558737088),  INT32_C(   661363612), -INT32_C(   694125686) } },
    { {  INT32_C(  1112320587),  INT32_C(   228897434), -INT32_C(  1232998763),  INT32_C(  1446805749) },
      { -INT32_C(  1534251059), -INT32_C(  1749460179), -INT32_C(   935884841), -INT32_C(  1191969940) },
      { -INT32_C(   794687792), -INT32_C(   163533786),  INT32_C(   880905268), -INT32_C(  1033657814) },
      { -INT32_C(   906158506), -INT32_C(   186472640),  INT32_C(  1004469691), -INT32_C(  1178648809) },
      { -INT32_C(   484755251), -INT32_C(    99754724),  INT32_C(   537347445), -INT32_C(   630525671) },
      { -INT32_C(   617398277), -INT32_C(   127050495),  INT32_C(   684381212), -INT32_C(   803055690) } },
    { {  INT32_C(  1073364901), -INT32_C(  2041733391), -INT32_C(  2109944179),  INT32_C(   467171406) },
      { -INT32_C(   725654105), -INT32_C(  1754564160),  INT32_C(  1834983936),  INT32_C(  1109742237) },
      { -INT32_C(   362699687),  INT32_C(   689920139),  INT32_C(   712969180), -INT32_C(   157861434) },
      { -INT32_C(   876974122),  INT32_C(  1668162752),  INT32_C(  1723893190), -INT32_C(   381694271) },
      {  INT32_C(   917169894), -INT32_C(  1744622353), -INT32_C(  1802907174),  INT32_C(   399189082) },
      {  INT32_C(   554676338), -INT32_C(  1055094311), -INT32_C(  1090343191),  INT32_C(   241417364) } },
    { { -INT32_C(  2105401455),  INT32_C(  1258868670), -INT32_C(   338869091),  INT32_C(  1661445820) },
      { -INT32_C(   868760053),  INT32_C(  1080271423), -INT32_C(   491928763), -INT32_C(  1490693611) },
      {  INT32_C(   851735789), -INT32_C(   509272708),  INT32_C(   137088787), -INT32_C(   672134458) },
      { -INT32_C(  1059102372),  INT32_C(   633262028), -INT32_C(   170464905),  INT32_C(   835774671) },
      {  INT32_C(   482288903), -INT32_C(   288371792),  INT32_C(    77625482), -INT32_C(   380591018) },
      {  INT32_C(  1461481907), -INT32_C(   873854143),  INT32_C(   235228794), -INT32_C(  1153306416) } }
  };

  simde_int32x4_t a, v, r;

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    a = simde_vld1q_s32(test_vec[i].a);
    v = simde_vld1q_s32(test_vec[i].v);

    r = simde_vqrdmulhq_laneq_s32(a, v, 0);
    simde_test_arm_neon_assert_equal_i32x4(r, simde_vld1q_s32(test_vec[i].r0));

    r = simde_vqrdmulhq_laneq_s32(a, v, 1);
    simde_test_arm_neon_assert_equal_i32x4(r, simde_vld1q_s32(test_vec[i].r1));

    r = simde_vqrdmulhq_laneq_s32(a, v, 2);
    simde_test_arm_neon_assert_equal_i32x4(r, simde_vld1q_s32(test_vec[i].r2));

    r = simde_vqrdmulhq_laneq_s32(a, v, 3);
    simde_test_arm_neon_assert_equal_i32x4(r, simde_vld1q_s32(test_vec[i].r3));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int32x4_t a = simde_test_arm_neon_random_i32x4();
    simde_int32x4_t v = simde_test_arm_neon_random_i32x4();
    simde_int32x4_t r;

    simde_test_arm_neon_write_i32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i32x4(2, v, SIMDE_TEST_VEC_POS_MIDDLE);

    for (int j = 0 ; j < 4 ; j++) {
      SIMDE_CONSTIFY_4_(simde_vqrdmulhq_laneq_s32, r, (HEDLEY_UNREACHABLE(), simde_vdupq_n_s32(0)), j, a, v);
      simde_test_arm_neon_write_i32x4(2, r, (j == 3) ? SIMDE_TEST_VEC_POS_LAST : SIMDE_TEST_VEC_POS_MIDDLE);
    }
  }
  return 1;
#endif
}

static int
test_simde_vqrdmulhs_lane_s32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int32_t  a;
    int32_t  v[2];
    int32_t r0;
    int32_t r1;
  } test_vec[] = {
    {  INT32_C(  2085236885),
      { -INT32_C(   624170380),  INT32_C(   192382979) },
      -INT32_C(   606078235),
       INT32_C(   186806584) },
    {  INT32_C(  1008290250),
      {  INT32_C(  1824521079), -INT32_C(  1933697853) },
       INT32_C(   856652304),
      -INT32_C(   907913172) },
    { -INT32_C(     1979197),
      { -INT32_C(  1305326563), -INT32_C(   248546180) },
       INT32_C(     1203035),
       INT32_C(      229069) },
    {  INT32_C(  1774975590),
      {  INT32_C(  1299530627),  INT32_C(    76123788) },
       INT32_C(  1074110689),
       INT32_C(    62919159) },
    {  INT32_C(  1282427017),
      {  INT32_C(   685256549),  INT32_C(   405322235) },
       INT32_C(   409219187),
       INT32_C(   242048961) },
    { -INT32_C(  2100602363),
      {  INT32_C(  1014233814),  INT32_C(  2007383796) },
      -INT32_C(   992092279),
      -INT32_C(  1963561003) },
    {  INT32_C(   247798657),
      {  INT32_C(   840060585), -INT32_C(    58817897) },
       INT32_C(    96934794),
      -INT32_C(     6787011) },
    { -INT32_C(  1406904655),
      {  INT32_C(   348474383),  INT32_C(  2090242214) },
      -INT32_C(   228299867),
      -INT32_C(  1369403443) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x2_t v = simde_vld1_s32(test_vec[i].v);

    int32_t r = simde_vqrdmulhs_lane_s32(test_vec[i].a, v, 0);
    simde_assert_equal_i32(r, test_vec[i].r0);

    r = simde_vqrdmulhs_lane_s32(test_vec[i].a, v, 1);
    simde_assert_equal_i32(r, test_vec[i].r1);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    int32_t a = simde_test_codegen_random_i32();
    simde_int32x2_t v = simde_test_arm_neon_random_i32x2();
    int32_t r0 = simde_vqrdmulhs_lane_s32(a, v, 0);
    int32_t r1 = simde_vqrdmulhs_lane_s32(a, v, 1);

    simde_test_codegen_write_i32(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i32x2(2, v, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, r0, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, r1, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vqrdmulhs_laneq_s32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int32_t  a;
    int32_t  v[4];
    int32_t r0;
    int32_t r1;
    int32_t r2;
    int32_t r3;
  } test_vec[] = {
    {  INT32_C(   451100002),
      { -INT32_C(  1132178826),  INT32_C(   811989606), -INT32_C(  2076899410),  INT32_C(   298280412) },
      -INT32_C(   237825266),
       INT32_C(   170566380),
      -INT32_C(   436273091),
       INT32_C(    62656726) },
    {  INT32_C(  1199826043),
      { -INT32_C(  1194911690), -INT32_C(  1463719354),  INT32_C(   499295399),  INT32_C(  1574586103) },
      -INT32_C(   667612145),
      -INT32_C(   817798358),
       INT32_C(   278962600),
       INT32_C(   879741001) },
    { -INT32_C(   275955904),
      {  INT32_C(   594788934), -INT32_C(  1556858328),  INT32_C(  1441445663),  INT32_C(   353284559) },
      -INT32_C(    76431557),
       INT32_C(   200059380),
      -INT32_C(   185228624),
      -INT32_C(    45397766) },
    { -INT32_C(  1010905316),
      {  INT32_C(  1809940596),  INT32_C(   130595783),  INT32_C(  1089885690),  INT32_C(  1080256792) },
      -INT32_C(   852010478),
      -INT32_C(    61476590),
      -INT32_C(   513052213),
      -INT32_C(   508519511) },
    { -INT32_C(  1008494684),
      {  INT32_C(   488164686), -INT32_C(  1707923842),  INT32_C(  1784607222),  INT32_C(   953499505) },
      -INT32_C(   229250403),
       INT32_C(   802069956),
      -INT32_C(   838081770),
      -INT32_C(   447779513) },
    { -INT32_C(   197091846),
      {  INT32_C(   171194098),  INT32_C(  1145739424),  INT32_C(  2114399535),  INT32_C(  2040209402) },
      -INT32_C(    15711859),
      -INT32_C(   105153722),
      -INT32_C(   194055451),
      -INT32_C(   187246426) },
    {  INT32_C(  1007930950),
      {  INT32_C(   832991679), -INT32_C(  1435927632),  INT32_C(   178170136), -INT32_C(  2146053152) },
       INT32_C(   390968329),
      -INT32_C(   673958986),
       INT32_C(    83624942),
      -INT32_C(  1007259540) },
    { -INT32_C(  1698406549),
      { -INT32_C(  2028418163),  INT32_C(   805352682),  INT32_C(  1114379394),  INT32_C(   913511045) },
       INT32_C(  1604239779),
      -INT32_C(   636939085),
      -INT32_C(   881342804),
      -INT32_C(   722479607) }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x4_t v = simde_vld1q_s32(test_vec[i].v);

    int32_t r = simde_vqrdmulhs_laneq_s32(test_vec[i].a, v, 0);
    simde_assert_equal_i32(r, test_vec[i].r0);
    r = simde_vqrdmulhs_laneq_s32(test_vec[i].a, v, 1);
    simde_assert_equal_i32(r, test_vec[i].r1);
    r = simde_vqrdmulhs_laneq_s32(test_vec[i].a, v, 2);
    simde_assert_equal_i32(r, test_vec[i].r2);
    r = simde_vqrdmulhs_laneq_s32(test_vec[i].a, v, 3);
    simde_assert_equal_i32(r, test_vec[i].r3);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    int32_t a = simde_test_codegen_random_i32();
    simde_int32x4_t v = simde_test_arm_neon_random_i32x4();
    int32_t r0 = simde_vqrdmulhs_laneq_s32(a, v, 0);
    int32_t r1 = simde_vqrdmulhs_laneq_s32(a, v, 1);
    int32_t r2 = simde_vqrdmulhs_laneq_s32(a, v, 2);
    int32_t r3 = simde_vqrdmulhs_laneq_s32(a, v, 3);

    simde_test_codegen_write_i32(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i32x4(2, v, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, r0, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, r1, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, r2, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, r3, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(vqrdmulh_lane_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vqrdmulh_lane_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vqrdmulhq_lane_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vqrdmulhq_lane_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vqrdmulh_laneq_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vqrdmulh_laneq_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vqrdmulhq_laneq_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vqrdmulhq_laneq_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vqrdmulhs_lane_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vqrdmulhs_laneq_s32)
SIMDE_TEST_FUNC_LIST_END

#include "test-neon-footer.h"
