#define SIMDE_TEST_ARM_NEON_INSN qrdmlsh

#include "test-neon.h"
#include "../../../simde/arm/neon/qrdmlsh.h"

static int
test_simde_vqrdmlshh_s16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int16_t a;
    int16_t b;
    int16_t c;
    int16_t r;
  } test_vec[] = {
    { -INT16_C(  4762),
      -INT16_C( 12912),
      -INT16_C( 24871),
      -INT16_C( 14562) },
    { -INT16_C( 23120),
      -INT16_C(  8732),
       INT16_C(  2674),
      -INT16_C( 22407) },
    {  INT16_C( 18627),
       INT16_C( 20248),
      -INT16_C( 30680),
             INT16_MAX },
    {  INT16_C(  6721),
      -INT16_C(  1158),
      -INT16_C( 12995),
       INT16_C(  6262) },
    {  INT16_C( 11210),
       INT16_C( 15844),
      -INT16_C(  7884),
       INT16_C( 15022) },
    { -INT16_C( 25985),
       INT16_C(  4046),
      -INT16_C( 22424),
      -INT16_C( 23216) },
    {  INT16_C(  6318),
      -INT16_C( 28083),
      -INT16_C( 16139),
      -INT16_C(  7514) },
    { -INT16_C( 18276),
      -INT16_C( 19192),
       INT16_C( 12552),
      -INT16_C( 10924) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    int16_t a = test_vec[i].a;
    int16_t b = test_vec[i].b;
    int16_t c = test_vec[i].c;
    int16_t r;

    r = simde_vqrdmlshh_s16(a, b, c);

    simde_assert_equal_i16(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    int16_t a = simde_test_codegen_random_i16();
    int16_t b = simde_test_codegen_random_i16();
    int16_t c = simde_test_codegen_random_i16();
    int16_t r;
    
    r = simde_vqrdmlshh_s16(a, b, c);

    simde_test_codegen_write_i16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_i16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i16(2, c, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vqrdmlshh_s32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int32_t a;
    int32_t b;
    int32_t c;
    int32_t r;
  } test_vec[] = {
    {  INT32_C(   117785660),
       INT32_C(   790454664),
      -INT32_C(   513974284),
       INT32_C(   306971440) },
    { -INT32_C(  1040318372),
       INT32_C(   557790548),
      -INT32_C(   189730628),
      -INT32_C(   991037461) },
    {  INT32_C(  1023116168),
       INT32_C(    33294533),
      -INT32_C(   737672628),
       INT32_C(  1034553026) },
    {  INT32_C(  1459889507),
      -INT32_C(   516398716),
      -INT32_C(  1247660447),
       INT32_C(  1159868478) },
    {  INT32_C(   685171052),
       INT32_C(  1495042001),
      -INT32_C(   812312822),
       INT32_C(  1250689578) },
    {  INT32_C(  1825608224),
      -INT32_C(   146679660),
      -INT32_C(  2108799491),
       INT32_C(  1681570809) },
    {  INT32_C(   123963046),
       INT32_C(   683476412),
      -INT32_C(  1219390490),
       INT32_C(   512056635) },
    {  INT32_C(   621833498),
      -INT32_C(  1510693499),
      -INT32_C(   888027849),
      -INT32_C(     2868767) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    int32_t a = test_vec[i].a;
    int32_t b = test_vec[i].b;
    int32_t c = test_vec[i].c;
    int32_t r;

    r = simde_vqrdmlshs_s32(a, b, c);

    simde_assert_equal_i32(r, test_vec[i].r);
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    int32_t a = simde_test_codegen_random_i32();
    int32_t b = simde_test_codegen_random_i32();
    int32_t c = simde_test_codegen_random_i32();
    int32_t r;
    
    r = simde_vqrdmlshs_s32(a, b, c);

    simde_test_codegen_write_i32(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_i32(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, c, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vqrdmlsh_s16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int16_t a[4];
    int16_t b[4];
    int16_t c[4];
    int16_t r[4];
  } test_vec[] = {
    { {  INT16_C( 21149), -INT16_C( 25662),  INT16_C(  4247),  INT16_C( 15645) },
      { -INT16_C( 32618),  INT16_C( 21317),  INT16_C(   645),  INT16_C( 27515) },
      { -INT16_C( 13163), -INT16_C( 20446),  INT16_C( 12858), -INT16_C( 16427) },
      {  INT16_C(  8046), -INT16_C( 12361),  INT16_C(  3994),  INT16_C( 29439) } },
    { { -INT16_C( 13865),  INT16_C(  3940),  INT16_C( 30094),  INT16_C( 11482) },
      { -INT16_C( 25144),  INT16_C( 24519), -INT16_C(  6995),  INT16_C( 17565) },
      { -INT16_C(  7580), -INT16_C(  5737),  INT16_C(  4836),  INT16_C( 31060) },
      { -INT16_C( 19681),  INT16_C(  8233),  INT16_C( 31126), -INT16_C(  5167) } },
    { {  INT16_C( 30431),  INT16_C(  6441), -INT16_C(   344),  INT16_C( 32728) },
      {  INT16_C( 15560),  INT16_C( 22158),  INT16_C( 27057),  INT16_C( 31106) },
      {  INT16_C( 18694), -INT16_C( 19495),  INT16_C( 30253), -INT16_C( 28169) },
      {  INT16_C( 21554),  INT16_C( 19624), -INT16_C( 25324),        INT16_MAX } },
    { { -INT16_C( 29096),  INT16_C( 15482), -INT16_C( 12639), -INT16_C( 32587) },
      { -INT16_C(  8380), -INT16_C(  4967),  INT16_C( 29149), -INT16_C( 23188) },
      { -INT16_C(  1363),  INT16_C( 24316),  INT16_C( 32355),  INT16_C( 27096) },
      { -INT16_C( 29445),  INT16_C( 19168),        INT16_MIN, -INT16_C( 13413) } },
    { { -INT16_C( 20024), -INT16_C(  2787),  INT16_C(  5159),  INT16_C( 32647) },
      {  INT16_C(   419),  INT16_C( 17595),  INT16_C( 28880),  INT16_C(  5316) },
      {  INT16_C( 23887),  INT16_C( 11521),  INT16_C( 28110),  INT16_C( 31698) },
      { -INT16_C( 20329), -INT16_C(  8973), -INT16_C( 19616),  INT16_C( 27505) } },
    { { -INT16_C( 12697), -INT16_C( 13351), -INT16_C( 20147),  INT16_C(  5428) },
      {  INT16_C( 20834), -INT16_C( 30454), -INT16_C( 28314),  INT16_C(  2312) },
      { -INT16_C( 15469),  INT16_C( 25421),  INT16_C(  4404), -INT16_C( 31881) },
      { -INT16_C(  2862),  INT16_C( 10275), -INT16_C( 16342),  INT16_C(  7677) } },
    { {  INT16_C( 30830),  INT16_C( 15536), -INT16_C( 31771),  INT16_C( 19895) },
      { -INT16_C( 28591), -INT16_C( 25064),  INT16_C( 19522), -INT16_C( 23373) },
      { -INT16_C( 16738),  INT16_C(  1070),  INT16_C( 13903), -INT16_C(  7667) },
      {  INT16_C( 16226),  INT16_C( 16354),        INT16_MIN,  INT16_C( 14426) } },
    { {  INT16_C( 23290),  INT16_C( 11845), -INT16_C( 17045), -INT16_C(  9807) },
      {  INT16_C( 25141),  INT16_C(  6933), -INT16_C( 13083),  INT16_C( 13928) },
      { -INT16_C( 32676), -INT16_C( 24875), -INT16_C( 30516),  INT16_C( 27203) },
      {        INT16_MAX,  INT16_C( 17108), -INT16_C( 29229), -INT16_C( 21370) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x4_t a = simde_vld1_s16(test_vec[i].a);
    simde_int16x4_t b = simde_vld1_s16(test_vec[i].b);
    simde_int16x4_t c = simde_vld1_s16(test_vec[i].c);
    simde_int16x4_t r = simde_vqrdmlsh_s16(a, b, c);

    simde_test_arm_neon_assert_equal_i16x4(r, simde_vld1_s16(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int16x4_t a = simde_test_arm_neon_random_i16x4();
    simde_int16x4_t b = simde_test_arm_neon_random_i16x4();
    simde_int16x4_t c = simde_test_arm_neon_random_i16x4();
    simde_int16x4_t r = simde_vqrdmlsh_s16(a, b, c);

    simde_test_arm_neon_write_i16x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i16x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i16x4(2, c, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i16x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vqrdmlsh_s32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int32_t a[2];
    int32_t b[2];
    int32_t c[2];
    int32_t r[2];
  } test_vec[] = {
    { { -INT32_C(  1771146938), -INT32_C(  1585939545) },
      {  INT32_C(  1087356629), -INT32_C(  1340505733) },
      { -INT32_C(   926208285),  INT32_C(  1476277242) },
      { -INT32_C(  1302170739), -INT32_C(   664415366) } },
    { { -INT32_C(  2131373133), -INT32_C(  1561708452) },
      {  INT32_C(  1362647465), -INT32_C(  1426935340) },
      { -INT32_C(   353713553),  INT32_C(   647627843) },
      { -INT32_C(  1906930504), -INT32_C(  1131380120) } },
    { {  INT32_C(   770598450),  INT32_C(  1300556953) },
      {  INT32_C(   483228096),  INT32_C(  1539225522) },
      { -INT32_C(   441649392),  INT32_C(   395288488) },
      {  INT32_C(   869978669),  INT32_C(  1017230870) } },
    { { -INT32_C(  1543407263), -INT32_C(  1328899203) },
      { -INT32_C(  1679968255),  INT32_C(  1692950948) },
      { -INT32_C(  1937721894),  INT32_C(  2112372588) },
      {              INT32_MIN,              INT32_MIN } },
    { { -INT32_C(   563964874), -INT32_C(  1795821261) },
      { -INT32_C(   398920086), -INT32_C(  1818754415) },
      {  INT32_C(  1596880314), -INT32_C(  1329391914) },
      { -INT32_C(   267325767),              INT32_MIN } },
    { {  INT32_C(   926762187), -INT32_C(  1179376253) },
      { -INT32_C(   308865351),  INT32_C(  1921092615) },
      {  INT32_C(   324713090),  INT32_C(  2007429820) },
      {  INT32_C(   973464579),              INT32_MIN } },
    { {  INT32_C(  1037489255), -INT32_C(  1242719766) },
      {  INT32_C(  1626155741),  INT32_C(   152674639) },
      { -INT32_C(  1074351944), -INT32_C(  1104054468) },
      {  INT32_C(  1851029131), -INT32_C(  1164227379) } },
    { { -INT32_C(   288191695), -INT32_C(   463112067) },
      {  INT32_C(   924924749), -INT32_C(  1293086764) },
      { -INT32_C(  1995253191),  INT32_C(   865217659) },
      {  INT32_C(   571167145),  INT32_C(    57870481) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x2_t a = simde_vld1_s32(test_vec[i].a);
    simde_int32x2_t b = simde_vld1_s32(test_vec[i].b);
    simde_int32x2_t c = simde_vld1_s32(test_vec[i].c);
    simde_int32x2_t r = simde_vqrdmlsh_s32(a, b, c);

    simde_test_arm_neon_assert_equal_i32x2(r, simde_vld1_s32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int32x2_t a = simde_test_arm_neon_random_i32x2();
    simde_int32x2_t b = simde_test_arm_neon_random_i32x2();
    simde_int32x2_t c = simde_test_arm_neon_random_i32x2();
    simde_int32x2_t r = simde_vqrdmlsh_s32(a, b, c);

    simde_test_arm_neon_write_i32x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i32x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i32x2(2, c, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i32x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vqrdmlshq_s16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int16_t a[8];
    int16_t b[8];
    int16_t c[8];
    int16_t r[8];
  } test_vec[] = {
    { { -INT16_C( 30500),  INT16_C(  6643),  INT16_C(  9471),  INT16_C( 12759), -INT16_C( 22096),  INT16_C( 11551), -INT16_C( 31710),  INT16_C( 28434) },
      {  INT16_C( 13247), -INT16_C( 27738), -INT16_C( 27838),  INT16_C( 31813),  INT16_C( 22637), -INT16_C(  5883), -INT16_C( 26748),  INT16_C( 24604) },
      {  INT16_C(  3871),  INT16_C(  7801),  INT16_C( 20788), -INT16_C(  7089),  INT16_C( 28410),  INT16_C(  7185),  INT16_C(  9202), -INT16_C( 20085) },
      { -INT16_C( 32065),  INT16_C( 13247),  INT16_C( 27131),  INT16_C( 19641),        INT16_MIN,  INT16_C( 12841), -INT16_C( 24199),        INT16_MAX } },
    { {  INT16_C( 12887), -INT16_C( 26299), -INT16_C( 30011),  INT16_C( 13077),  INT16_C(  6882),  INT16_C( 26140),  INT16_C( 14513), -INT16_C( 12089) },
      {  INT16_C( 16456),  INT16_C( 31983),  INT16_C( 16017), -INT16_C( 29600),  INT16_C( 29101), -INT16_C( 24664),  INT16_C( 13461), -INT16_C(  5039) },
      { -INT16_C( 27034),  INT16_C( 11141), -INT16_C( 25824),  INT16_C(   862),  INT16_C( 31413),  INT16_C( 26473),  INT16_C( 12467), -INT16_C(  1225) },
      {  INT16_C( 26463),        INT16_MIN, -INT16_C( 17388),  INT16_C( 13856), -INT16_C( 21016),        INT16_MAX,  INT16_C(  9392), -INT16_C( 12277) } },
    { {  INT16_C(  9841),  INT16_C(   631), -INT16_C( 10395),  INT16_C(  4750),  INT16_C( 14152), -INT16_C(  8783),  INT16_C(   619), -INT16_C( 11831) },
      {  INT16_C( 20376), -INT16_C( 17924),  INT16_C( 23530), -INT16_C( 24644),  INT16_C(  9685), -INT16_C( 30714),  INT16_C( 15958), -INT16_C( 14461) },
      { -INT16_C(  1436), -INT16_C( 13879),  INT16_C( 22737),  INT16_C(  6875), -INT16_C( 29297), -INT16_C(  1289), -INT16_C( 15985),  INT16_C( 10443) },
      {  INT16_C( 10734), -INT16_C(  6961), -INT16_C( 26722),  INT16_C(  9921),  INT16_C( 22811), -INT16_C(  9991),  INT16_C(  8404), -INT16_C(  7222) } },
    { { -INT16_C( 14576), -INT16_C(  1311), -INT16_C( 25310), -INT16_C(  1895), -INT16_C( 24382),  INT16_C(  6272),  INT16_C(  1246),  INT16_C( 17119) },
      { -INT16_C( 22018), -INT16_C( 12276), -INT16_C(  6399), -INT16_C( 28438), -INT16_C(  7820),  INT16_C(  1162),  INT16_C( 21922), -INT16_C( 19924) },
      {  INT16_C(  3356),  INT16_C( 16300),  INT16_C( 18090),  INT16_C( 27703), -INT16_C( 18458), -INT16_C( 15227),  INT16_C( 25787), -INT16_C( 17914) },
      { -INT16_C( 12321),  INT16_C(  4796), -INT16_C( 21777),  INT16_C( 22147), -INT16_C( 28787),  INT16_C(  6812), -INT16_C( 16006),  INT16_C(  6227) } },
    { {  INT16_C(  4621),  INT16_C(  3722),  INT16_C( 29946),  INT16_C( 28318),  INT16_C( 10325), -INT16_C(  1934), -INT16_C( 24963), -INT16_C( 25942) },
      {  INT16_C( 22443),  INT16_C( 21977),  INT16_C(  4253), -INT16_C( 31806),  INT16_C( 18375), -INT16_C( 31929),  INT16_C( 19883), -INT16_C( 18115) },
      { -INT16_C( 14496),  INT16_C( 23239),  INT16_C( 26171), -INT16_C( 28472),  INT16_C( 15246),  INT16_C(  3208),  INT16_C( 13273), -INT16_C( 31322) },
      {  INT16_C( 14549), -INT16_C( 11864),  INT16_C( 26549),  INT16_C(   682),  INT16_C(  1776),  INT16_C(  1192),        INT16_MIN,        INT16_MIN } },
    { {  INT16_C( 32650),  INT16_C( 10202), -INT16_C( 25457),  INT16_C( 22186), -INT16_C(  3613), -INT16_C( 28711),  INT16_C(  5694), -INT16_C( 25016) },
      {  INT16_C(  4061),  INT16_C(  6392), -INT16_C( 16011),  INT16_C(  1193),  INT16_C( 12796), -INT16_C( 10992), -INT16_C( 18844), -INT16_C(  4518) },
      {  INT16_C( 13621), -INT16_C( 15339), -INT16_C( 16431), -INT16_C( 19174), -INT16_C(  2896), -INT16_C(  4284), -INT16_C( 29686), -INT16_C(  6003) },
      {  INT16_C( 30962),  INT16_C( 13194),        INT16_MIN,  INT16_C( 22884), -INT16_C(  2482), -INT16_C( 30148), -INT16_C( 11378), -INT16_C( 25844) } },
    { { -INT16_C( 31077),  INT16_C(  4352), -INT16_C( 22201),  INT16_C( 17173),  INT16_C(  9691),  INT16_C( 16152),  INT16_C( 29659),  INT16_C(  4142) },
      {  INT16_C( 17320),  INT16_C( 31188), -INT16_C(  4605), -INT16_C( 19666),  INT16_C( 29410), -INT16_C(  4702),  INT16_C( 12542), -INT16_C( 25899) },
      { -INT16_C( 10826), -INT16_C(   597), -INT16_C( 16257),  INT16_C( 23104),  INT16_C( 22757), -INT16_C( 16231), -INT16_C( 14389),  INT16_C( 29648) },
      { -INT16_C( 25355),  INT16_C(  4920), -INT16_C( 24486),  INT16_C( 31039), -INT16_C( 10734),  INT16_C( 13823),        INT16_MAX,  INT16_C( 27575) } },
    { { -INT16_C( 23541),  INT16_C(  3821),  INT16_C(  7058),  INT16_C( 30145),  INT16_C( 25742), -INT16_C( 29598),  INT16_C( 14228),  INT16_C( 18982) },
      { -INT16_C( 12020), -INT16_C( 29881), -INT16_C( 30831),  INT16_C( 30437),  INT16_C( 32735), -INT16_C( 21706),  INT16_C(  1606),  INT16_C( 20766) },
      {  INT16_C(  2986),  INT16_C( 15711),  INT16_C(  8487), -INT16_C( 19022),  INT16_C(  5253),  INT16_C(  6465),  INT16_C( 26699),  INT16_C( 22371) },
      { -INT16_C( 22446),  INT16_C( 18148),  INT16_C( 15043),        INT16_MAX,  INT16_C( 20494), -INT16_C( 25315),  INT16_C( 12919),  INT16_C(  4805) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x8_t a = simde_vld1q_s16(test_vec[i].a);
    simde_int16x8_t b = simde_vld1q_s16(test_vec[i].b);
    simde_int16x8_t c = simde_vld1q_s16(test_vec[i].c);
    simde_int16x8_t r = simde_vqrdmlshq_s16(a, b, c);

    simde_test_arm_neon_assert_equal_i16x8(r, simde_vld1q_s16(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int16x8_t a = simde_test_arm_neon_random_i16x8();
    simde_int16x8_t b = simde_test_arm_neon_random_i16x8();
    simde_int16x8_t c = simde_test_arm_neon_random_i16x8();
    simde_int16x8_t r = simde_vqrdmlshq_s16(a, b, c);

    simde_test_arm_neon_write_i16x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i16x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i16x8(2, c, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i16x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vqrdmlshq_s32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int32_t a[4];
    int32_t b[4];
    int32_t c[4];
    int32_t r[4];
  } test_vec[] = {
    { { -INT32_C(   874272199),  INT32_C(   272746545), -INT32_C(  1900316601),  INT32_C(   702536318) },
      {  INT32_C(   208027621), -INT32_C(   440330144),  INT32_C(  2013135660), -INT32_C(  1529978517) },
      {  INT32_C(  1013952779), -INT32_C(  1051938438), -INT32_C(  1487992791), -INT32_C(   942657566) },
      { -INT32_C(   972494220),  INT32_C(    57052142), -INT32_C(   505413617),  INT32_C(    30938271) } },
    { { -INT32_C(   824953234),  INT32_C(  2058589518),  INT32_C(    66171288),  INT32_C(   497598482) },
      { -INT32_C(   346482831), -INT32_C(   240278072), -INT32_C(  1885733715), -INT32_C(  1722324693) },
      { -INT32_C(   295228512),  INT32_C(  1500060352), -INT32_C(   581150005), -INT32_C(  1929772006) },
      { -INT32_C(   872586477),              INT32_MAX, -INT32_C(   444144196), -INT32_C(  1050117134) } },
    { { -INT32_C(   461941988), -INT32_C(  1495915271),  INT32_C(  1278635809),  INT32_C(  2028375512) },
      {  INT32_C(  2020036024),  INT32_C(   869388392),  INT32_C(  1158753834),  INT32_C(  1322322738) },
      {  INT32_C(  1479755871), -INT32_C(  1895954067),  INT32_C(  1356477560),  INT32_C(  2043265217) },
      { -INT32_C(  1853878159), -INT32_C(   728356245),  INT32_C(   546698420),  INT32_C(   770225743) } },
    { {  INT32_C(  1995583502),  INT32_C(   715768576),  INT32_C(   611302129),  INT32_C(   628244678) },
      { -INT32_C(   159537783),  INT32_C(   646216622),  INT32_C(  1903648432),  INT32_C(   770392095) },
      {  INT32_C(  1889787248), -INT32_C(  1835381600), -INT32_C(   843707897), -INT32_C(   739104694) },
      {  INT32_C(  2135976873),  INT32_C(  1268068054),  INT32_C(  1359211533),  INT32_C(   893392408) } },
    { {  INT32_C(  2093576142), -INT32_C(  1700573718), -INT32_C(   888399188), -INT32_C(   889653414) },
      {  INT32_C(  1949998036), -INT32_C(   301542169),  INT32_C(   700169438), -INT32_C(  1275286043) },
      {  INT32_C(   120571420), -INT32_C(  1079913965),  INT32_C(  1183493612),  INT32_C(  2014347940) },
      {  INT32_C(  1984092639), -INT32_C(  1852211473), -INT32_C(  1274267578),  INT32_C(   306569810) } },
    { {  INT32_C(    99437085), -INT32_C(    34344161), -INT32_C(  1792626768),  INT32_C(  2034770780) },
      { -INT32_C(    58689559),  INT32_C(   918298954),  INT32_C(  1937589967), -INT32_C(   420704823) },
      { -INT32_C(   135538216),  INT32_C(  2096422860), -INT32_C(   367977586),  INT32_C(   660822334) },
      {  INT32_C(    95732899), -INT32_C(   930808691), -INT32_C(  1460615076),              INT32_MAX } },
    { {  INT32_C(   455336913), -INT32_C(   732831995), -INT32_C(   280506842),  INT32_C(   886387548) },
      { -INT32_C(   651443956),  INT32_C(   777330592),  INT32_C(  2014865210), -INT32_C(  1851818816) },
      {  INT32_C(  1689043807), -INT32_C(   935788894),  INT32_C(   683114700), -INT32_C(  1067676237) },
      {  INT32_C(   967712120), -INT32_C(   394101902), -INT32_C(   921435608), -INT32_C(    34291381) } },
    { { -INT32_C(   291928242), -INT32_C(   518197593),  INT32_C(   375010389),  INT32_C(   279443888) },
      {  INT32_C(  1601459388),  INT32_C(   505916754), -INT32_C(   532160723), -INT32_C(  1163877524) },
      { -INT32_C(   760727253),  INT32_C(  2108933160), -INT32_C(  1449980424), -INT32_C(  1011270905) },
      {  INT32_C(   275374704), -INT32_C(  1015032398),  INT32_C(    15695601), -INT32_C(   268637341) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x4_t a = simde_vld1q_s32(test_vec[i].a);
    simde_int32x4_t b = simde_vld1q_s32(test_vec[i].b);
    simde_int32x4_t c = simde_vld1q_s32(test_vec[i].c);
    simde_int32x4_t r = simde_vqrdmlshq_s32(a, b, c);

    simde_test_arm_neon_assert_equal_i32x4(r, simde_vld1q_s32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int32x4_t a = simde_test_arm_neon_random_i32x4();
    simde_int32x4_t b = simde_test_arm_neon_random_i32x4();
    simde_int32x4_t c = simde_test_arm_neon_random_i32x4();
    simde_int32x4_t r = simde_vqrdmlshq_s32(a, b, c);

    simde_test_arm_neon_write_i32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i32x4(2, c, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(vqrdmlshh_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vqrdmlshh_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vqrdmlsh_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vqrdmlsh_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vqrdmlshq_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vqrdmlshq_s32)
SIMDE_TEST_FUNC_LIST_END

#include "test-neon-footer.h"
