#define SIMDE_TEST_ARM_NEON_INSN qrdmlah

#include "test-neon.h"
#include "../../../simde/arm/neon/qrdmlah.h"

static int
test_simde_vqrdmlahh_s16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int16_t a;
    int16_t b;
    int16_t c;
    int16_t r;
  } test_vec[] = {
    {   -INT16_C(   13345),
         INT16_C(   16373),
        -INT16_C(   21381),
        -INT16_C(   24028) },
    {   -INT16_C(   19789),
        -INT16_C(   15717),
         INT16_C(   18188),
        -INT16_C(   28513) },
    {   -INT16_C(   28102),
         INT16_C(    7819),
         INT16_C(    8111),
        -INT16_C(   26167) },
    {   -INT16_C(    3585),
         INT16_C(   12894),
         INT16_C(   29921),
         INT16_C(    8189) },
    {   -INT16_C(   31832),
         INT16_C(   23240),
         INT16_C(    2062),
        -INT16_C(   30370) },
    {    INT16_C(    2283),
         INT16_C(   14215),
        -INT16_C(    4760),
         INT16_C(     218) },
    {    INT16_C(    4246),
        -INT16_C(   20899),
         INT16_C(   23218),
        -INT16_C(   10562) },
    {   -INT16_C(   20594),
         INT16_C(   10356),
        -INT16_C(   28772),
        -INT16_C(   29687) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    int16_t a = test_vec[i].a;
    int16_t b = test_vec[i].b;
    int16_t c = test_vec[i].c;
    int16_t r = simde_vqrdmlahh_s16(a, b, c);

    simde_assert_equal_i16(r, test_vec[i].r);
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int16_t a = simde_test_codegen_random_i16();
    simde_int16_t b = simde_test_codegen_random_i16();
    simde_int16_t c = simde_test_codegen_random_i16();
    simde_int16_t r = simde_vqrdmlahh_s16(a, b, c);

    simde_test_codegen_write_i16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_i16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i16(2, c, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vqrdmlahs_s32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int32_t a;
    int32_t b;
    int32_t c;
    int32_t r;
  } test_vec[] = {
    {   -INT32_C(  1586532556),
        -INT32_C(   602443854),
         INT32_C(  1038563649),
        -INT32_C(  1877885781) },
    {   -INT32_C(   379774146),
         INT32_C(   148562387),
        -INT32_C(  1192397806),
        -INT32_C(   462263931) },
    {    INT32_C(  1251361204),
         INT32_C(   287135564),
        -INT32_C(   452611732),
         INT32_C(  1190843432) },
    {    INT32_C(   714073929),
         INT32_C(  2136502533),
         INT32_C(  1120344741),
         INT32_C(  1828689809) },
    {   -INT32_C(   810368086),
         INT32_C(  1027156967),
         INT32_C(   590115016),
        -INT32_C(   528111804) },
    {    INT32_C(  1186414374),
        -INT32_C(   197101995),
         INT32_C(   630884759),
         INT32_C(  1128510024) },
    {    INT32_C(   452201570),
        -INT32_C(   304910789),
        -INT32_C(   116470007),
         INT32_C(   468738581) },
    {   -INT32_C(    67835597),
         INT32_C(  1430399729),
        -INT32_C(  1500228799),
        -INT32_C(  1067110665) },
    {    INT32_C(  2147483646),
         INT32_MIN,
         INT32_MAX,
        -INT32_C(           1) },
    {    INT32_C(  2147483646),
         INT32_MIN,
         INT32_MIN,
         INT32_MAX },
    {    INT32_C(  2147483646),
         INT32_MIN,
        -INT32_C(  2147483647),
         INT32_MAX },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    int32_t a = test_vec[i].a;
    int32_t b = test_vec[i].b;
    int32_t c = test_vec[i].c;
    int32_t r = simde_vqrdmlahs_s32(a, b, c);

    simde_assert_equal_i32(r, test_vec[i].r);
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int32_t a = simde_test_codegen_random_i32();
    simde_int32_t b = simde_test_codegen_random_i32();
    simde_int32_t c = simde_test_codegen_random_i32();
    simde_int32_t r = simde_vqrdmlahs_s32(a, b, c);

    simde_test_codegen_write_i32(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_i32(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, c, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vqrdmlah_s16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int16_t a[4];
    int16_t b[4];
    int16_t c[4];
    int16_t r[4];
  } test_vec[] = {
    { {  INT16_C(   13139),  INT16_C(   20695), -INT16_C(   31201), -INT16_C(    7985) },
      {  INT16_C(   11558),  INT16_C(   18298),  INT16_C(     326),  INT16_C(   26952) },
      { -INT16_C(   27674),  INT16_C(   19956), -INT16_C(   29184),  INT16_C(   28329) },
      {  INT16_C(    3378),  INT16_C(   31839), -INT16_C(   31491),  INT16_C(   15316) } },
    { {  INT16_C(   13296),  INT16_C(   24465), -INT16_C(   11737),  INT16_C(   22935) },
      {  INT16_C(   25964), -INT16_C(   23916),  INT16_C(    8278), -INT16_C(   15310) },
      {  INT16_C(   16877), -INT16_C(   10593), -INT16_C(    4717), -INT16_C(   11475) },
      {  INT16_C(   26669),  INT16_C(   32196), -INT16_C(   12929),  INT16_C(   28296) } },
    { {  INT16_C(   11939),  INT16_C(   10704),  INT16_C(   20268),  INT16_C(    7426) },
      {  INT16_C(   32563),  INT16_C(   31409),  INT16_C(   22724), -INT16_C(   13081) },
      {  INT16_C(   12421),  INT16_C(    5577), -INT16_C(   14739), -INT16_C(    9862) },
      {  INT16_C(   24282),  INT16_C(   16050),  INT16_C(   10047),  INT16_C(   11363) } },
    { { -INT16_C(    3311), -INT16_C(   24491),  INT16_C(   31529),  INT16_C(    9074) },
      { -INT16_C(   14549),  INT16_C(   22567),  INT16_C(   31836), -INT16_C(   20254) },
      { -INT16_C(   28562),  INT16_C(   24596),  INT16_C(   15960), -INT16_C(   17254) },
      {  INT16_C(    9371), -INT16_C(    7552),          INT16_MAX,  INT16_C(   19739) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x4_t a = simde_vld1_s16(test_vec[i].a);
    simde_int16x4_t b = simde_vld1_s16(test_vec[i].b);
    simde_int16x4_t c = simde_vld1_s16(test_vec[i].c);
    simde_int16x4_t r = simde_vqrdmlah_s16(a, b, c);

    simde_test_arm_neon_assert_equal_i16x4(r, simde_vld1_s16(test_vec[i].r));
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int16x4_t a = simde_test_arm_neon_random_i16x4();
    simde_int16x4_t b = simde_test_arm_neon_random_i16x4();
    simde_int16x4_t c = simde_test_arm_neon_random_i16x4();
    simde_int16x4_t r = simde_vqrdmlah_s16(a, b, c);

    simde_test_arm_neon_write_i16x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i16x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i16x4(2, c, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i16x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vqrdmlah_s32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int32_t a[2];
    int32_t b[2];
    int32_t c[2];
    int32_t r[2];
  } test_vec[] = {
    { { -INT32_C(  1589243271), -INT32_C(   629013450) },
      {  INT32_C(  1872805162),  INT32_C(  1977655419) },
      {  INT32_C(  1265769624),  INT32_C(  1073458364) },
      { -INT32_C(   485374616),  INT32_C(   359553216) } },
    { {  INT32_C(   550951169), -INT32_C(  1948890100) },
      {  INT32_C(  1656736768),  INT32_C(  2029379432) },
      { -INT32_C(   511891251), -INT32_C(   587876938) },
      {  INT32_C(   156038240),              INT32_MIN } },
    { { -INT32_C(   750566385),  INT32_C(  1474308514) },
      {  INT32_C(  1779226894), -INT32_C(   901654666) },
      { -INT32_C(   326203697),  INT32_C(  2131814938) },
      { -INT32_C(  1020831721),  INT32_C(   579232601) } },
    { { -INT32_C(   741495511), -INT32_C(   692651895) },
      {  INT32_C(  2002140936),  INT32_C(  1843538183) },
      {  INT32_C(  1895608514),  INT32_C(  1617637729) },
      {  INT32_C(  1025817320),  INT32_C(   696032448) } },
    { { -INT32_C(  1642493156), -INT32_C(  1354567839) },
      {  INT32_C(   330485595),  INT32_C(  1242551220) },
      {  INT32_C(   904786419), -INT32_C(   971831356) },
      { -INT32_C(  1503251640), -INT32_C(  1916877237) } },
    { {  INT32_C(  1564360544),  INT32_C(  1281613922) },
      { -INT32_C(   597890985),  INT32_C(   556055752) },
      { -INT32_C(  1227210044),  INT32_C(   876256867) },
      {  INT32_C(  1906033843),  INT32_C(  1508506300) } },
    { { -INT32_C(   919697688),  INT32_C(  1979003210) },
      {  INT32_C(   393801111), -INT32_C(  1464734310) },
      {  INT32_C(  1793870022),  INT32_C(  1885646717) },
      { -INT32_C(   590741513),  INT32_C(   692860032) } },
    { {  INT32_C(   525357175),  INT32_C(   660264585) },
      {  INT32_C(  1948383946),  INT32_C(  1946053711) },
      { -INT32_C(   563839893),  INT32_C(   421305442) },
      {  INT32_C(    13792583),  INT32_C(  1042052367) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x2_t a = simde_vld1_s32(test_vec[i].a);
    simde_int32x2_t b = simde_vld1_s32(test_vec[i].b);
    simde_int32x2_t c = simde_vld1_s32(test_vec[i].c);
    simde_int32x2_t r = simde_vqrdmlah_s32(a, b, c);

    simde_test_arm_neon_assert_equal_i32x2(r, simde_vld1_s32(test_vec[i].r));
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int32x2_t a = simde_test_arm_neon_random_i32x2();
    simde_int32x2_t b = simde_test_arm_neon_random_i32x2();
    simde_int32x2_t c = simde_test_arm_neon_random_i32x2();
    simde_int32x2_t r = simde_vqrdmlah_s32(a, b, c);

    simde_test_arm_neon_write_i32x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i32x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i32x2(2, c, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i32x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vqrdmlahq_s16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int16_t a[8];
    int16_t b[8];
    int16_t c[8];
    int16_t r[8];
  } test_vec[] = {
    { {  INT16_C(   19116), -INT16_C(   15169), -INT16_C(   25078), -INT16_C(    2993),
         INT16_C(   20224),  INT16_C(    3602),  INT16_C(   27566),  INT16_C(   32140) },
      {  INT16_C(    5789),  INT16_C(   21877),  INT16_C(    7747), -INT16_C(   27100),
        -INT16_C(    1024),  INT16_C(   30258),  INT16_C(   26799),  INT16_C(    2389) },
      {  INT16_C(   27754), -INT16_C(    3470),  INT16_C(   11498), -INT16_C(   32061),
         INT16_C(    7029), -INT16_C(   22064), -INT16_C(   22805), -INT16_C(    4014) },
      {  INT16_C(   24019), -INT16_C(   17486), -INT16_C(   22360),  INT16_C(   23522),
         INT16_C(   20004), -INT16_C(   16772),  INT16_C(    8915),  INT16_C(   31847) } },
    { { -INT16_C(   10523),  INT16_C(   13006), -INT16_C(   19715), -INT16_C(   19840),
        -INT16_C(   24770),  INT16_C(   26472), -INT16_C(   12155),  INT16_C(   30566) },
      { -INT16_C(   18546),  INT16_C(    4166),  INT16_C(    8720),  INT16_C(   29551),
         INT16_C(    9970), -INT16_C(   26780), -INT16_C(   15459),  INT16_C(   19039) },
      {  INT16_C(    9850),  INT16_C(   20952),  INT16_C(    7459), -INT16_C(   17112),
        -INT16_C(   32284), -INT16_C(    4862), -INT16_C(   26837),  INT16_C(    1120) },
      { -INT16_C(   16098),  INT16_C(   15670), -INT16_C(   17730),          INT16_MIN,
                 INT16_MIN,  INT16_C(   30446),  INT16_C(     506),  INT16_C(   31217) } },
    { { -INT16_C(   23906), -INT16_C(    6272),  INT16_C(    2718),  INT16_C(   20857),
        -INT16_C(    4805), -INT16_C(   10530), -INT16_C(   28135), -INT16_C(    9298) },
      { -INT16_C(    4557),  INT16_C(   22989), -INT16_C(    7190), -INT16_C(   11557),
         INT16_C(    8653),  INT16_C(   27730),  INT16_C(    8786),  INT16_C(   13067) },
      {  INT16_C(   10559),  INT16_C(    2193), -INT16_C(   21306),  INT16_C(   27486),
         INT16_C(   13960), -INT16_C(   25019), -INT16_C(    1639),  INT16_C(   11074) },
      { -INT16_C(   25374), -INT16_C(    4733),  INT16_C(    7393),  INT16_C(   11163),
        -INT16_C(    1119), -INT16_C(   31702), -INT16_C(   28574), -INT16_C(    4882) } },
    { {  INT16_C(   24993),  INT16_C(    4973), -INT16_C(   18994), -INT16_C(    1316),
         INT16_C(   26040), -INT16_C(   29376), -INT16_C(   11901),  INT16_C(   30841) },
      { -INT16_C(   19152), -INT16_C(   30244),  INT16_C(   13556), -INT16_C(   11948),
         INT16_C(   10738), -INT16_C(   10087),  INT16_C(    6408), -INT16_C(   17195) },
      { -INT16_C(    8076), -INT16_C(   30413),  INT16_C(   18212),  INT16_C(   26139),
        -INT16_C(    7433), -INT16_C(    4443), -INT16_C(    6919),  INT16_C(      61) },
      {  INT16_C(   29713),          INT16_MAX, -INT16_C(   11460), -INT16_C(   10847),
         INT16_C(   23604), -INT16_C(   28008), -INT16_C(   13254),  INT16_C(   30809) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x8_t a = simde_vld1q_s16(test_vec[i].a);
    simde_int16x8_t b = simde_vld1q_s16(test_vec[i].b);
    simde_int16x8_t c = simde_vld1q_s16(test_vec[i].c);
    simde_int16x8_t r = simde_vqrdmlahq_s16(a, b, c);

    simde_test_arm_neon_assert_equal_i16x8(r, simde_vld1q_s16(test_vec[i].r));
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int16x8_t a = simde_test_arm_neon_random_i16x8();
    simde_int16x8_t b = simde_test_arm_neon_random_i16x8();
    simde_int16x8_t c = simde_test_arm_neon_random_i16x8();
    simde_int16x8_t r = simde_vqrdmlahq_s16(a, b, c);

    simde_test_arm_neon_write_i16x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i16x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i16x8(2, c, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i16x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vqrdmlahq_s32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int32_t a[4];
    int32_t b[4];
    int32_t c[4];
    int32_t r[4];
  } test_vec[] = {
    { { -INT32_C(   926902108),  INT32_C(  1687744536),  INT32_C(   960768044), -INT32_C(  1303705284) },
      {  INT32_C(  1161328816),  INT32_C(  1980112746), -INT32_C(  1961950655), -INT32_C(   686932123) },
      { -INT32_C(   381479347), -INT32_C(  1863725647),  INT32_C(  2089843236),  INT32_C(  1311564213) },
      { -INT32_C(  1133200749), -INT32_C(    30725783), -INT32_C(   948522073), -INT32_C(  1723245424) } },
    { {  INT32_C(   110994591),  INT32_C(  2029793604),  INT32_C(  1283271454),  INT32_C(   624247811) },
      {  INT32_C(  2006545195),  INT32_C(  2009786253), -INT32_C(   688093424),  INT32_C(  1928250380) },
      { -INT32_C(   302150985),  INT32_C(   311374798), -INT32_C(  1190297629),  INT32_C(    99960909) },
      { -INT32_C(   171326351),              INT32_MAX,  INT32_C(  1664664799),  INT32_C(   714003866) } },
    { { -INT32_C(   871382603), -INT32_C(  1798281670), -INT32_C(   614507206),  INT32_C(   706771544) },
      {  INT32_C(  1960614490), -INT32_C(  1493829740),  INT32_C(    24389225), -INT32_C(   267853418) },
      { -INT32_C(  1508289958), -INT32_C(  1204510688), -INT32_C(  1421231743),  INT32_C(  1112983800) },
      {              INT32_MIN, -INT32_C(   960401535), -INT32_C(   630648302),  INT32_C(   567950224) } },
    { {  INT32_C(  1626647102),  INT32_C(   415487043), -INT32_C(   116824112), -INT32_C(   168212464) },
      {  INT32_C(   424579690),  INT32_C(   221950347), -INT32_C(  1182728826), -INT32_C(  1857216443) },
      {  INT32_C(  1075147684),  INT32_C(  1217104295),  INT32_C(   747981916), -INT32_C(  1423823712) },
      {  INT32_C(  1839214900),  INT32_C(   541279256), -INT32_C(   528775921),  INT32_C(  1063158407) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x4_t a = simde_vld1q_s32(test_vec[i].a);
    simde_int32x4_t b = simde_vld1q_s32(test_vec[i].b);
    simde_int32x4_t c = simde_vld1q_s32(test_vec[i].c);
    simde_int32x4_t r = simde_vqrdmlahq_s32(a, b, c);

    simde_test_arm_neon_assert_equal_i32x4(r, simde_vld1q_s32(test_vec[i].r));
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int32x4_t a = simde_test_arm_neon_random_i32x4();
    simde_int32x4_t b = simde_test_arm_neon_random_i32x4();
    simde_int32x4_t c = simde_test_arm_neon_random_i32x4();
    simde_int32x4_t r = simde_vqrdmlahq_s32(a, b, c);

    simde_test_arm_neon_write_i32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i32x4(2, c, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(vqrdmlahh_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vqrdmlahs_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vqrdmlah_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vqrdmlah_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vqrdmlahq_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vqrdmlahq_s32)
SIMDE_TEST_FUNC_LIST_END

#include "test-neon-footer.h"
