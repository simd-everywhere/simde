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
    {   -INT16_C(   30997),
         INT16_C(    5759),
         INT16_C(   30317),
                 INT16_MIN },
    {    INT16_C(   13109),
         INT16_C(   31342),
         INT16_C(    3385),
         INT16_C(    9871) },
    {    INT16_C(    2043),
         INT16_C(   10749),
         INT16_C(   17846),
        -INT16_C(    3811) },
    {    INT16_C(   21129),
         INT16_C(    1079),
         INT16_C(   17531),
         INT16_C(   20552) },
    {    INT16_C(    2916),
        -INT16_C(    5751),
        -INT16_C(    2805),
         INT16_C(    2424) },
    {   -INT16_C(     600),
        -INT16_C(   29732),
         INT16_C(   21466),
         INT16_C(   18877) },
    {   -INT16_C(    8483),
         INT16_C(   30392),
        -INT16_C(   30331),
         INT16_C(   19649) },
    {   -INT16_C(   18732),
         INT16_C(   17458),
        -INT16_C(    8776),
        -INT16_C(   14056) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    int16_t a = test_vec[i].a;
    int16_t b = test_vec[i].b;
    int16_t c = test_vec[i].c;
    int16_t r = simde_vqrdmlshh_s16(a, b, c);

    simde_assert_equal_i16(r, test_vec[i].r);
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int16_t a = simde_test_codegen_random_i16();
    simde_int16_t b = simde_test_codegen_random_i16();
    simde_int16_t c = simde_test_codegen_random_i16();
    simde_int16_t r = simde_vqrdmlshh_s16(a, b, c);

    simde_test_codegen_write_i16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_i16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i16(2, c, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vqrdmlshs_s32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int32_t a;
    int32_t b;
    int32_t c;
    int32_t r;
  } test_vec[] = {
    {    INT32_C(  1167881245),
         INT32_C(   520249064),
        -INT32_C(  1560212143),
         INT32_C(  1545858003) },
    {    INT32_C(   525424326),
        -INT32_C(  1609094637),
         INT32_C(  1955971625),
         INT32_C(  1991020329) },
    {   -INT32_C(   788871995),
        -INT32_C(  1541192896),
         INT32_C(   378326414),
        -INT32_C(   517357014) },
    {   -INT32_C(   112912660),
         INT32_C(   663819849),
         INT32_C(   412471906),
        -INT32_C(   240413998) },
    {   -INT32_C(  1519565011),
        -INT32_C(  2120046715),
        -INT32_C(  1393316874),
                     INT32_MIN },
    {    INT32_C(   412847960),
         INT32_C(  1883513173),
         INT32_C(   682319071),
        -INT32_C(   185599884) },
    {   -INT32_C(  1561124907),
         INT32_C(   326151919),
        -INT32_C(   741247099),
        -INT32_C(  1448547024) },
    {   -INT32_C(  2076091214),
         INT32_C(   619426745),
         INT32_C(  2110830135),
                     INT32_MIN },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    int32_t a = test_vec[i].a;
    int32_t b = test_vec[i].b;
    int32_t c = test_vec[i].c;
    int32_t r = simde_vqrdmlshs_s32(a, b, c);

    simde_assert_equal_i32(r, test_vec[i].r);
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int32_t a = simde_test_codegen_random_i32();
    simde_int32_t b = simde_test_codegen_random_i32();
    simde_int32_t c = simde_test_codegen_random_i32();
    simde_int32_t r = simde_vqrdmlshs_s32(a, b, c);

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
    { { -INT16_C(   25508), -INT16_C(   18180),  INT16_C(   23659),  INT16_C(    9711) },
      {  INT16_C(   32212),  INT16_C(   19121), -INT16_C(    2075), -INT16_C(    4107) },
      {  INT16_C(   30998),  INT16_C(   14473),  INT16_C(    6630),  INT16_C(   16240) },
      {          INT16_MIN, -INT16_C(   26625),  INT16_C(   24079),  INT16_C(   11746) } },
    { {  INT16_C(   15899),  INT16_C(    5288), -INT16_C(   20623),  INT16_C(    1228) },
      { -INT16_C(   26462), -INT16_C(    7753),  INT16_C(   10182), -INT16_C(    8950) },
      {  INT16_C(    3134),  INT16_C(    7960), -INT16_C(   19543), -INT16_C(   16718) },
      {  INT16_C(   18430),  INT16_C(    7171), -INT16_C(   14550), -INT16_C(    3338) } },
    { {  INT16_C(       7),  INT16_C(    1234),  INT16_C(    4679), -INT16_C(    9604) },
      {  INT16_C(   18022),  INT16_C(   31656), -INT16_C(   25238),  INT16_C(   16501) },
      {  INT16_C(   28966),  INT16_C(   27413),  INT16_C(   29400),  INT16_C(   13190) },
      { -INT16_C(   15924), -INT16_C(   25249),  INT16_C(   27323), -INT16_C(   16246) } },
    { { -INT16_C(   31501), -INT16_C(    9442), -INT16_C(   13273), -INT16_C(   13079) },
      {  INT16_C(   30941),  INT16_C(   26647),  INT16_C(   29974), -INT16_C(   23413) },
      { -INT16_C(    3873),  INT16_C(   19416),  INT16_C(   27473),  INT16_C(   21846) },
      { -INT16_C(   27844), -INT16_C(   25231),          INT16_MIN,  INT16_C(    2530) } },
    { { -INT16_C(   23440),  INT16_C(   17980), -INT16_C(    8498),  INT16_C(   19306) },
      { -INT16_C(    9529),  INT16_C(   18804),  INT16_C(     653),  INT16_C(   31143) },
      {  INT16_C(   32590), -INT16_C(   17166), -INT16_C(   29940),  INT16_C(   21167) },
      { -INT16_C(   13963),  INT16_C(   27831), -INT16_C(    7901), -INT16_C(     811) } },
    { {  INT16_C(   24716),  INT16_C(   22957),  INT16_C(    3916),  INT16_C(   10944) },
      {  INT16_C(   19643),  INT16_C(   18752),  INT16_C(   17757),  INT16_C(   21237) },
      {  INT16_C(     576), -INT16_C(   20121), -INT16_C(    6897),  INT16_C(    7351) },
      {  INT16_C(   24371),          INT16_MAX,  INT16_C(    7653),  INT16_C(    6180) } },
    { {  INT16_C(    4294), -INT16_C(   27343),  INT16_C(   12548), -INT16_C(    1125) },
      { -INT16_C(    2245), -INT16_C(   26996),  INT16_C(   10972), -INT16_C(   25991) },
      {  INT16_C(   31325), -INT16_C(   25910), -INT16_C(   24820), -INT16_C(   31211) },
      {  INT16_C(    6440),          INT16_MIN,  INT16_C(   20859), -INT16_C(   25881) } },
    { { -INT16_C(   21847), -INT16_C(   11070),  INT16_C(   18467),  INT16_C(   16313) },
      {  INT16_C(   16087),  INT16_C(   30596),  INT16_C(    8085), -INT16_C(   30998) },
      {  INT16_C(   18394), -INT16_C(    2588), -INT16_C(   30373),  INT16_C(   16877) },
      { -INT16_C(   30877), -INT16_C(    8654),  INT16_C(   25961),  INT16_C(   32278) } },
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
    { { -INT32_C(   586920024), -INT32_C(   146918906) },
      { -INT32_C(  2042332209), -INT32_C(  1330543988) },
      {  INT32_C(  1483346573),  INT32_C(  1788651147) },
      {  INT32_C(   823794552),  INT32_C(   961298627) } },
    { { -INT32_C(   818106413), -INT32_C(  1328696251) },
      { -INT32_C(   164316533),  INT32_C(   476642248) },
      { -INT32_C(  1744239165),  INT32_C(  1362171942) },
      { -INT32_C(   951568352), -INT32_C(  1631035548) } },
    { { -INT32_C(   998549728), -INT32_C(   103072271) },
      {  INT32_C(  1620577428),  INT32_C(  2006935962) },
      {  INT32_C(   298135022), -INT32_C(  1702190793) },
      { -INT32_C(  1223534392),  INT32_C(  1487714192) } },
    { {  INT32_C(  1604704800), -INT32_C(   820232492) },
      { -INT32_C(   612121146),  INT32_C(  2026058008) },
      { -INT32_C(    13830622),  INT32_C(   926638099) },
      {  INT32_C(  1600762504), -INT32_C(  1694475489) } },
    { { -INT32_C(  1678801209),  INT32_C(   920296562) },
      { -INT32_C(  1874321972),  INT32_C(   638260106) },
      { -INT32_C(   943983351), -INT32_C(   446950301) },
      {              INT32_MIN,  INT32_C(  1053136012) } },
    { { -INT32_C(  1490265344),  INT32_C(  1384810858) },
      {  INT32_C(   166447839),  INT32_C(  1691837946) },
      {  INT32_C(  1068185226),  INT32_C(    40595813) },
      { -INT32_C(  1573058581),  INT32_C(  1352828525) } },
    { { -INT32_C(  1871767631),  INT32_C(   717115816) },
      {  INT32_C(   955641248), -INT32_C(  1420742809) },
      {  INT32_C(  1572038020), -INT32_C(   263163960) },
      {              INT32_MIN,  INT32_C(   543010507) } },
    { {  INT32_C(   996947134), -INT32_C(  2066924399) },
      {  INT32_C(   657864031),  INT32_C(   527828654) },
      { -INT32_C(  1277171916), -INT32_C(   810076353) },
      {  INT32_C(  1388198292), -INT32_C(  1867816242) } },
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
    { { -INT16_C(    5588), -INT16_C(   10143),  INT16_C(   26556),  INT16_C(   30199),
         INT16_C(   29411),  INT16_C(    7423),  INT16_C(   21844),  INT16_C(   15290) },
      {  INT16_C(    8827), -INT16_C(   30147),  INT16_C(   10571), -INT16_C(   11844),
        -INT16_C(    5485),  INT16_C(   11199),  INT16_C(   11428),  INT16_C(    8508) },
      { -INT16_C(   14939), -INT16_C(   31894),  INT16_C(   32241),  INT16_C(   17375),
        -INT16_C(     423), -INT16_C(   11740), -INT16_C(   26713),  INT16_C(   24510) },
      { -INT16_C(    1564),          INT16_MIN,  INT16_C(   16155),          INT16_MAX,
         INT16_C(   29340),  INT16_C(   11435),  INT16_C(   31160),  INT16_C(    8926) } },
    { { -INT16_C(    1640),  INT16_C(    1772), -INT16_C(   32020), -INT16_C(   29912),
         INT16_C(    6665), -INT16_C(   21915), -INT16_C(   12726),  INT16_C(   30525) },
      { -INT16_C(   16853),  INT16_C(   17753),  INT16_C(    8363),  INT16_C(   29631),
         INT16_C(   19735), -INT16_C(   26029),  INT16_C(    2252),  INT16_C(   25693) },
      { -INT16_C(    6504),  INT16_C(   10827), -INT16_C(     539), -INT16_C(    1898),
        -INT16_C(   27900), -INT16_C(   16185),  INT16_C(    6950),  INT16_C(    8082) },
      { -INT16_C(    4985), -INT16_C(    4094), -INT16_C(   31882), -INT16_C(   28196),
         INT16_C(   23468),          INT16_MIN, -INT16_C(   13204),  INT16_C(   24188) } },
    { { -INT16_C(   15325), -INT16_C(    4280),  INT16_C(   12538),  INT16_C(   20373),
         INT16_C(     621), -INT16_C(    3439),  INT16_C(   17531),  INT16_C(      26) },
      {  INT16_C(   20908), -INT16_C(   31978), -INT16_C(   28652), -INT16_C(   16650),
        -INT16_C(    4357),  INT16_C(   11740), -INT16_C(   29434),  INT16_C(     291) },
      { -INT16_C(    1181),  INT16_C(    5150),  INT16_C(   20515),  INT16_C(    1800),
         INT16_C(    4541), -INT16_C(   22517), -INT16_C(     903), -INT16_C(   17345) },
      { -INT16_C(   14571),  INT16_C(     746),  INT16_C(   30476),  INT16_C(   21288),
         INT16_C(    1225),  INT16_C(    4628),  INT16_C(   16720),  INT16_C(     180) } },
    { {  INT16_C(   29671), -INT16_C(   12848),  INT16_C(    9735),  INT16_C(    4514),
         INT16_C(   17407),  INT16_C(   10227), -INT16_C(   25013),  INT16_C(   23661) },
      {  INT16_C(   19758),  INT16_C(   30485), -INT16_C(    8337),  INT16_C(   14383),
        -INT16_C(   20207),  INT16_C(   21483),  INT16_C(   28058),  INT16_C(   12903) },
      { -INT16_C(   27436),  INT16_C(    3199), -INT16_C(    7429),  INT16_C(   14176),
        -INT16_C(   16247), -INT16_C(    8968),  INT16_C(   31298), -INT16_C(     586) },
      {          INT16_MAX, -INT16_C(   15824),  INT16_C(    7845), -INT16_C(    1708),
         INT16_C(    7388),  INT16_C(   16107),          INT16_MIN,  INT16_C(   23892) } },
    { {  INT16_C(   16246),  INT16_C(    6882), -INT16_C(   10639), -INT16_C(    3294),
         INT16_C(   24091),  INT16_C(     178), -INT16_C(   14184),  INT16_C(   28110) },
      { -INT16_C(   28616),  INT16_C(   10657),  INT16_C(   10996), -INT16_C(   10779),
        -INT16_C(   17496), -INT16_C(    6056),  INT16_C(   18340),  INT16_C(   32448) },
      { -INT16_C(   18932),  INT16_C(   20938), -INT16_C(   15020), -INT16_C(    1283),
         INT16_C(   31048),  INT16_C(    3099),  INT16_C(   26366),  INT16_C(     167) },
      { -INT16_C(     287),  INT16_C(      72), -INT16_C(    5599), -INT16_C(    3716),
                 INT16_MAX,  INT16_C(     751), -INT16_C(   28941),  INT16_C(   27945) } },
    { { -INT16_C(   25831), -INT16_C(    2307),  INT16_C(    8036),  INT16_C(   25992),
         INT16_C(   25106),  INT16_C(   12293),  INT16_C(   11461),  INT16_C(   15388) },
      { -INT16_C(   18091), -INT16_C(   21849), -INT16_C(   29585),  INT16_C(    7672),
        -INT16_C(    2284), -INT16_C(   30471), -INT16_C(    8626),  INT16_C(   32600) },
      {  INT16_C(   10235), -INT16_C(    1022),  INT16_C(   29590),  INT16_C(   17037),
        -INT16_C(    3269), -INT16_C(   29084), -INT16_C(   14638),  INT16_C(    9058) },
      { -INT16_C(   20180), -INT16_C(    2988),          INT16_MAX,  INT16_C(   22003),
         INT16_C(   24878), -INT16_C(   14752),  INT16_C(    7608),  INT16_C(    6376) } },
    { {  INT16_C(   12106), -INT16_C(   11469), -INT16_C(   32235),  INT16_C(    6131),
         INT16_C(   31443), -INT16_C(   20248), -INT16_C(   25510),  INT16_C(   31204) },
      {  INT16_C(   15763), -INT16_C(   26181),  INT16_C(     761), -INT16_C(    8539),
         INT16_C(   14116),  INT16_C(   17006), -INT16_C(   17206),  INT16_C(   29849) },
      {  INT16_C(    9739), -INT16_C(   20589), -INT16_C(   12185),  INT16_C(    8784),
         INT16_C(   29686),  INT16_C(   18844),  INT16_C(   15101),  INT16_C(   18236) },
      {  INT16_C(    7421), -INT16_C(   27919), -INT16_C(   31952),  INT16_C(    8420),
         INT16_C(   18655), -INT16_C(   30028), -INT16_C(   17581),  INT16_C(   14592) } },
    { { -INT16_C(   22735),  INT16_C(   16633), -INT16_C(   20217),  INT16_C(   10462),
         INT16_C(    9548), -INT16_C(   27853),  INT16_C(   21353), -INT16_C(   16823) },
      {  INT16_C(   26280), -INT16_C(    5172), -INT16_C(   26968), -INT16_C(   27972),
         INT16_C(    8021),  INT16_C(    4286),  INT16_C(     590),  INT16_C(   18995) },
      { -INT16_C(   24214),  INT16_C(   19873),  INT16_C(   20885),  INT16_C(     118),
        -INT16_C(   10748), -INT16_C(   20692),  INT16_C(   16258),  INT16_C(   12104) },
      { -INT16_C(    3315),  INT16_C(   19770), -INT16_C(    3029),  INT16_C(   10563),
         INT16_C(   12179), -INT16_C(   25147),  INT16_C(   21060), -INT16_C(   23839) } },
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
    { { -INT32_C(   808762407), -INT32_C(   889900028),  INT32_C(  1831998425), -INT32_C(   343391661) },
      { -INT32_C(    51813152), -INT32_C(   682234393), -INT32_C(  1339913589), -INT32_C(  1756403637) },
      {  INT32_C(  1776880068), -INT32_C(  1504456119),  INT32_C(  2034807297),  INT32_C(   425642594) },
      { -INT32_C(   765890948), -INT32_C(  1367850912),              INT32_MAX,  INT32_C(     4736811) } },
    { {  INT32_C(   629437778), -INT32_C(    81234772), -INT32_C(  1049915897), -INT32_C(  1521437003) },
      { -INT32_C(  2058899969),  INT32_C(  1656918813),  INT32_C(   504560957), -INT32_C(   683263963) },
      { -INT32_C(   789675411),  INT32_C(   157444629),  INT32_C(  1230824515),  INT32_C(  1670573360) },
      { -INT32_C(   127663530), -INT32_C(   202713214), -INT32_C(  1339103661), -INT32_C(   989911384) } },
    { {  INT32_C(   391194947),  INT32_C(  1874232334),  INT32_C(   932250422), -INT32_C(  1677225244) },
      {  INT32_C(  1861799357), -INT32_C(   245271491),  INT32_C(   220249162), -INT32_C(  2050802683) },
      { -INT32_C(  1808781294), -INT32_C(  1335203140), -INT32_C(  1325843395),  INT32_C(  1685749104) },
      {  INT32_C(  1959350240),  INT32_C(  1721734193),  INT32_C(  1068230920), -INT32_C(    67369547) } },
    { {  INT32_C(   996124857),  INT32_C(  2121860454),  INT32_C(  1194798664), -INT32_C(   104915640) },
      { -INT32_C(  1841791822),  INT32_C(  2088175352), -INT32_C(   921601161), -INT32_C(  1571578535) },
      { -INT32_C(     8917314), -INT32_C(  1924117624), -INT32_C(  1205190083), -INT32_C(   287306876) },
      {  INT32_C(   988476912),              INT32_MAX,  INT32_C(   677586540), -INT32_C(   315173501) } },
    { {  INT32_C(   805377838), -INT32_C(  1183403423),  INT32_C(   107311150),  INT32_C(  1321915953) },
      {  INT32_C(  1443444536), -INT32_C(   619637370),  INT32_C(   385385810), -INT32_C(  1009635009) },
      { -INT32_C(   172391450),  INT32_C(    80481502), -INT32_C(  1960599346), -INT32_C(   833303061) },
      {  INT32_C(   921251827), -INT32_C(  1160181199),  INT32_C(   459158843),  INT32_C(   930140237) } },
    { {  INT32_C(   500140230),  INT32_C(  1801713418),  INT32_C(   954865796), -INT32_C(  1310790671) },
      { -INT32_C(   215244824),  INT32_C(  1484131867), -INT32_C(   695471957), -INT32_C(   245821740) },
      {  INT32_C(  1717730617),  INT32_C(  2084752068), -INT32_C(  1376465190),  INT32_C(    78952456) },
      {  INT32_C(   672310400),  INT32_C(   360935519),  INT32_C(   509091533), -INT32_C(  1301753010) } },
    { {  INT32_C(  1068265242),  INT32_C(   684620013),  INT32_C(  1467811292), -INT32_C(   707897664) },
      { -INT32_C(  1617237531),  INT32_C(   619415126), -INT32_C(   440028928),  INT32_C(  2043356454) },
      { -INT32_C(   350295392),  INT32_C(  1847693735), -INT32_C(   585539703),  INT32_C(  1792738250) },
      {  INT32_C(   804463068),  INT32_C(   151675583),  INT32_C(  1347831609),              INT32_MIN } },
    { { -INT32_C(  1939553575), -INT32_C(   344792595),  INT32_C(  1156793014), -INT32_C(  1438003461) },
      { -INT32_C(   418206922),  INT32_C(   276993021),  INT32_C(   741154794), -INT32_C(   186056632) },
      { -INT32_C(  1768877063),  INT32_C(   660562085),  INT32_C(   198307008), -INT32_C(  1907317857) },
      {              INT32_MIN, -INT32_C(   429995147),  INT32_C(  1088351892), -INT32_C(  1603252280) } },
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
SIMDE_TEST_FUNC_LIST_ENTRY(vqrdmlshs_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vqrdmlsh_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vqrdmlsh_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vqrdmlshq_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vqrdmlshq_s32)
SIMDE_TEST_FUNC_LIST_END

#include "test-neon-footer.h"
