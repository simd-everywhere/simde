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
    {  INT16_C( 30656),
      -INT16_C( 19466),
       INT16_C( 18374),
       INT16_C( 19741) },
    { -INT16_C(  8457),
       INT16_C( 26747),
      -INT16_C(  7839),
      -INT16_C( 14856) },
    {  INT16_C( 13346),
       INT16_C(  1479),
      -INT16_C( 28487),
       INT16_C( 12060) },
    {  INT16_C( 26813),
      -INT16_C( 23836),
       INT16_C( 30182),
       INT16_C(  4858) },
    { -INT16_C(   312),
      -INT16_C( 23307),
       INT16_C( 24956),
      -INT16_C( 18063) },
    {  INT16_C( 15471),
       INT16_C( 26072),
      -INT16_C( 24849),
      -INT16_C(  4300) },
    { -INT16_C(  6227),
       INT16_C( 10365),
      -INT16_C(  8625),
      -INT16_C(  8955) },
    {  INT16_C( 28937),
      -INT16_C( 12270),
      -INT16_C( 13193),
             INT16_MAX },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    int16_t a = test_vec[i].a;
    int16_t b = test_vec[i].b;
    int16_t c = test_vec[i].c;
    int16_t r;

    r = simde_vqrdmlahh_s16(a, b, c);

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
    
    r = simde_vqrdmlahh_s16(a, b, c);

    simde_test_codegen_write_i16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_i16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i16(2, c, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vqrdmlahh_s32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int32_t a;
    int32_t b;
    int32_t c;
    int32_t r;
  } test_vec[] = {
    {  INT32_C(  1251206131),
       INT32_C(  1068782168),
      -INT32_C(  1771955267),
       INT32_C(   369320863) },
    { -INT32_C(   185862299),
       INT32_C(  2037134812),
      -INT32_C(  1514592853),
      -INT32_C(  1622627524) },
    {  INT32_C(   919836184),
      -INT32_C(   165931773),
       INT32_C(  1346416888),
       INT32_C(   815801240) },
    { -INT32_C(  1081084670),
       INT32_C(  1968566544),
      -INT32_C(   999734808),
      -INT32_C(  1997526803) },
    {  INT32_C(   557766262),
       INT32_C(   331806715),
      -INT32_C(  1857447282),
       INT32_C(   270772933) },
    { -INT32_C(  1484298833),
       INT32_C(   402180117),
      -INT32_C(   841513027),
      -INT32_C(  1641897150) },
    {  INT32_C(  1631792249),
      -INT32_C(   484004755),
       INT32_C(  2097505410),
       INT32_C(  1159051703) },
    { -INT32_C(   376386725),
       INT32_C(   343595365),
       INT32_C(  1421607487),
      -INT32_C(   148930863) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    int32_t a = test_vec[i].a;
    int32_t b = test_vec[i].b;
    int32_t c = test_vec[i].c;
    int32_t r;

    r = simde_vqrdmlahs_s32(a, b, c);

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
    
    r = simde_vqrdmlahs_s32(a, b, c);

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
    { { -INT16_C(  8017),  INT16_C( 21852), -INT16_C( 31403),  INT16_C( 23989) },
      { -INT16_C( 28592),  INT16_C(  7035), -INT16_C( 27036),  INT16_C( 24029) },
      { -INT16_C( 24847),  INT16_C( 22362),  INT16_C( 23626),  INT16_C( 12326) },
      {  INT16_C( 13663),  INT16_C( 26653),        INT16_MIN,        INT16_MAX } },
    { {  INT16_C( 19644), -INT16_C(  5987),  INT16_C( 27055),  INT16_C( 24240) },
      {  INT16_C(  3145), -INT16_C( 24653),  INT16_C( 26769), -INT16_C(  7684) },
      {  INT16_C( 30712),  INT16_C( 24061), -INT16_C(  9714), -INT16_C(    70) },
      {  INT16_C( 22592), -INT16_C( 24089),  INT16_C( 19119),  INT16_C( 24256) } },
    { {  INT16_C(  5496), -INT16_C( 15530),  INT16_C( 31857),  INT16_C( 12019) },
      { -INT16_C( 28472),  INT16_C( 30486), -INT16_C( 14599),  INT16_C( 17365) },
      { -INT16_C( 30510),  INT16_C( 25570), -INT16_C(  8464), -INT16_C(  5819) },
      {  INT16_C( 32006),  INT16_C(  8259),        INT16_MAX,  INT16_C(  8935) } },
    { {  INT16_C( 16982),  INT16_C( 25670),  INT16_C(    28), -INT16_C( 27549) },
      { -INT16_C( 18155), -INT16_C( 30889),  INT16_C( 19254), -INT16_C(   331) },
      { -INT16_C( 13349), -INT16_C( 10890),  INT16_C( 19346),  INT16_C( 25624) },
      {  INT16_C( 24378),        INT16_MAX,  INT16_C( 11395), -INT16_C( 27808) } },
    { { -INT16_C(  1324), -INT16_C( 15160),  INT16_C(  3544),  INT16_C( 11949) },
      { -INT16_C(  3249),  INT16_C( 27538), -INT16_C(  2572),  INT16_C(  2559) },
      {  INT16_C( 22447), -INT16_C(  6768),  INT16_C( 17826),  INT16_C( 32227) },
      { -INT16_C(  3550), -INT16_C( 20848),  INT16_C(  2145),  INT16_C( 14466) } },
    { {  INT16_C( 22801), -INT16_C( 23726),  INT16_C( 27301),  INT16_C( 30983) },
      { -INT16_C( 12444),  INT16_C( 15677), -INT16_C(  5156),  INT16_C( 11115) },
      { -INT16_C(   290), -INT16_C( 11626), -INT16_C( 26893), -INT16_C( 23844) },
      {  INT16_C( 22911), -INT16_C( 29288),  INT16_C( 31533),  INT16_C( 22895) } },
    { {  INT16_C( 27885), -INT16_C( 28793),  INT16_C( 27570), -INT16_C( 15604) },
      {  INT16_C( 24516),  INT16_C( 26982),  INT16_C( 28105),  INT16_C( 12002) },
      {  INT16_C(  8253),  INT16_C(  6507), -INT16_C( 10741), -INT16_C(  5819) },
      {        INT16_MAX, -INT16_C( 23435),  INT16_C( 18357), -INT16_C( 17735) } },
    { { -INT16_C(  9260), -INT16_C( 14148), -INT16_C( 26511),  INT16_C( 24170) },
      { -INT16_C(  3580), -INT16_C( 18707), -INT16_C(  1443),  INT16_C(  8569) },
      { -INT16_C(  8359),  INT16_C(  8843),  INT16_C( 27981), -INT16_C( 30128) },
      { -INT16_C(  8347), -INT16_C( 19196), -INT16_C( 27743),  INT16_C( 16291) } },
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
    { { -INT32_C(    37212184),  INT32_C(  1279192937) },
      {  INT32_C(  1067723269),  INT32_C(  1460253124) },
      { -INT32_C(   220182439),  INT32_C(   253140152) },
      { -INT32_C(   146686318),  INT32_C(  1451324025) } },
    { { -INT32_C(  1905971062),  INT32_C(  1885950856) },
      { -INT32_C(   345165438),  INT32_C(   624405280) },
      { -INT32_C(  1704665898), -INT32_C(   403607923) },
      { -INT32_C(  1631979802),  INT32_C(  1768597265) } },
    { {  INT32_C(  1859768758), -INT32_C(   125964434) },
      { -INT32_C(  1467555040), -INT32_C(  1206325194) },
      {  INT32_C(  1118012705),  INT32_C(   107469360) },
      {  INT32_C(  1095737245), -INT32_C(   186334159) } },
    { {  INT32_C(  1151388854), -INT32_C(   265579974) },
      { -INT32_C(   782367645),  INT32_C(   348838900) },
      { -INT32_C(   188985154),  INT32_C(  1655493696) },
      {  INT32_C(  1220239609),  INT32_C(     3339699) } },
    { { -INT32_C(  1985720487), -INT32_C(   527430870) },
      {  INT32_C(   287584471),  INT32_C(   637620162) },
      {  INT32_C(  1224171348), -INT32_C(   111361733) },
      { -INT32_C(  1821783188), -INT32_C(   560495842) } },
    { {  INT32_C(  1391335442),  INT32_C(  1169464044) },
      {  INT32_C(   349067498),  INT32_C(  1005870692) },
      {  INT32_C(  1364007311), -INT32_C(  1133031832) },
      {  INT32_C(  1613051039),  INT32_C(   638757552) } },
    { { -INT32_C(   385585234),  INT32_C(  1122132016) },
      {  INT32_C(  1687539832),  INT32_C(  1437157739) },
      {  INT32_C(   107575458),  INT32_C(  1698782678) },
      { -INT32_C(   301050076),              INT32_MAX } },
    { { -INT32_C(   541618570), -INT32_C(  1952764195) },
      { -INT32_C(   831217507),  INT32_C(  2031113728) },
      { -INT32_C(  1830968025), -INT32_C(  1847097361) },
      {  INT32_C(   167086560),              INT32_MIN } },
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
    { {  INT16_C( 17403), -INT16_C( 16448),  INT16_C( 10315),  INT16_C(  3945), -INT16_C( 11297),  INT16_C( 27818),  INT16_C( 16611),  INT16_C(  6124) },
      { -INT16_C(  7037),  INT16_C( 22575),  INT16_C( 21339),  INT16_C( 31844), -INT16_C(  2247),  INT16_C(  6153), -INT16_C( 31266), -INT16_C(  9965) },
      { -INT16_C( 11320),  INT16_C(  5017),  INT16_C(   763), -INT16_C(  9694), -INT16_C( 12842), -INT16_C( 18106),  INT16_C( 12813), -INT16_C( 28464) },
      {  INT16_C( 19834), -INT16_C( 12992),  INT16_C( 10812), -INT16_C(  5476), -INT16_C( 10416),  INT16_C( 24418),  INT16_C(  4385),  INT16_C( 14780) } },
    { { -INT16_C(   234),  INT16_C( 29160),  INT16_C( 19538), -INT16_C( 29715), -INT16_C(  2493),  INT16_C(  8611), -INT16_C( 18821),  INT16_C( 17403) },
      { -INT16_C( 27511), -INT16_C( 31658),  INT16_C( 31126),  INT16_C( 27743), -INT16_C( 23226),  INT16_C( 21286), -INT16_C(  2344), -INT16_C(  4381) },
      { -INT16_C( 13322),  INT16_C( 18528),  INT16_C( 19735),  INT16_C( 23252),  INT16_C( 30532), -INT16_C( 16516),  INT16_C( 30510), -INT16_C( 18685) },
      {  INT16_C( 10951),  INT16_C( 11260),        INT16_MAX, -INT16_C( 10029), -INT16_C( 24134), -INT16_C(  2118), -INT16_C( 21003),  INT16_C( 19901) } },
    { {  INT16_C( 22795), -INT16_C( 24260), -INT16_C( 25646),  INT16_C(  6158),  INT16_C( 13376),  INT16_C(  6251),  INT16_C( 20010),  INT16_C(  8199) },
      {  INT16_C( 26393),  INT16_C( 12393),  INT16_C( 15796), -INT16_C(  1909),  INT16_C(  1972), -INT16_C(  7496), -INT16_C( 17538), -INT16_C( 30310) },
      { -INT16_C( 10732), -INT16_C(  6358),  INT16_C( 14449), -INT16_C( 19969),  INT16_C( 27500), -INT16_C( 26678), -INT16_C( 11847), -INT16_C( 11337) },
      {  INT16_C( 14151), -INT16_C( 26665), -INT16_C( 18681),  INT16_C(  7321),  INT16_C( 15031),  INT16_C( 12354),  INT16_C( 26351),  INT16_C( 18686) } },
    { {  INT16_C(  8248), -INT16_C(  5117), -INT16_C( 29091),  INT16_C(  4837), -INT16_C( 25195),  INT16_C(  5108), -INT16_C( 29096),  INT16_C( 27804) },
      { -INT16_C( 14492), -INT16_C( 10925),  INT16_C( 21503),  INT16_C( 27783),  INT16_C( 20926),  INT16_C( 30467), -INT16_C( 17886),  INT16_C( 23114) },
      {  INT16_C( 20187),  INT16_C( 14406),  INT16_C( 11228),  INT16_C( 29258),  INT16_C( 16328),  INT16_C(  8325),  INT16_C(  8909),  INT16_C( 12941) },
      { -INT16_C(   680), -INT16_C(  9920), -INT16_C( 21723),  INT16_C( 29644), -INT16_C( 14768),  INT16_C( 12848),        INT16_MIN,        INT16_MAX } },
    { { -INT16_C(  7959), -INT16_C(  6137), -INT16_C( 29133), -INT16_C(  3756),  INT16_C( 22495),  INT16_C(   361), -INT16_C( 19694), -INT16_C(  4773) },
      { -INT16_C( 24063), -INT16_C(  8667),  INT16_C( 28877), -INT16_C( 27056), -INT16_C( 10833),  INT16_C( 31926),  INT16_C( 17399), -INT16_C(  8018) },
      { -INT16_C( 18908),  INT16_C( 22473),  INT16_C(  7492),  INT16_C(  9289), -INT16_C( 19851), -INT16_C( 30939), -INT16_C( 32411),  INT16_C( 26484) },
      {  INT16_C(  5926), -INT16_C( 12081), -INT16_C( 22531), -INT16_C( 11426),  INT16_C( 29058), -INT16_C( 29783),        INT16_MIN, -INT16_C( 11253) } },
    { { -INT16_C( 26333), -INT16_C(  4027), -INT16_C( 27383), -INT16_C( 18298),  INT16_C( 15722),  INT16_C( 25141), -INT16_C(  7296), -INT16_C( 23486) },
      {  INT16_C(  2969), -INT16_C(  8452),  INT16_C( 17705), -INT16_C( 25086),  INT16_C( 10231),  INT16_C( 23589), -INT16_C( 26200), -INT16_C( 13373) },
      {  INT16_C(  2098),  INT16_C( 15548),  INT16_C( 17053),  INT16_C(  2292),  INT16_C( 10623),  INT16_C(   106), -INT16_C( 21491), -INT16_C( 22876) },
      { -INT16_C( 26143), -INT16_C(  8037), -INT16_C( 18169), -INT16_C( 20053),  INT16_C( 19039),  INT16_C( 25217),  INT16_C(  9887), -INT16_C( 14150) } },
    { { -INT16_C( 24392), -INT16_C(  7804), -INT16_C( 31003), -INT16_C(  9089), -INT16_C( 23378),  INT16_C( 22073), -INT16_C(   963),  INT16_C( 28450) },
      { -INT16_C(  8699), -INT16_C( 23893), -INT16_C( 24544), -INT16_C( 24406),  INT16_C(  5321), -INT16_C( 10592),  INT16_C( 17601),  INT16_C( 31101) },
      {  INT16_C(   485), -INT16_C( 13734), -INT16_C(  9848),  INT16_C( 13991), -INT16_C(  8067), -INT16_C( 17780), -INT16_C( 20772), -INT16_C(  7895) },
      { -INT16_C( 24521),  INT16_C(  2210), -INT16_C( 23627), -INT16_C( 19510), -INT16_C( 24688),  INT16_C( 27820), -INT16_C( 12120),  INT16_C( 20957) } },
    { { -INT16_C( 10868), -INT16_C( 21116),  INT16_C( 11893),  INT16_C( 15949), -INT16_C(  4797),  INT16_C(  1045), -INT16_C( 28111),  INT16_C(  5757) },
      { -INT16_C( 10349),  INT16_C(  7137), -INT16_C( 30544),  INT16_C( 11601), -INT16_C(  8600),  INT16_C( 17639),  INT16_C(  4236),  INT16_C(  6438) },
      { -INT16_C( 21787),  INT16_C( 23238),  INT16_C(  5080),  INT16_C(  7065), -INT16_C( 20992),  INT16_C( 12575), -INT16_C( 25536), -INT16_C( 11448) },
      { -INT16_C(  3987), -INT16_C( 16055),  INT16_C(  7158),  INT16_C( 18450),  INT16_C(   712),  INT16_C(  7814), -INT16_C( 31412),  INT16_C(  3508) } },
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
    { { -INT32_C(  2037743945), -INT32_C(  1441556118), -INT32_C(   640087943),  INT32_C(  2023424865) },
      {  INT32_C(  1849891103), -INT32_C(  1831901942), -INT32_C(  1321204163), -INT32_C(   130060992) },
      {  INT32_C(  1434372843), -INT32_C(   587165341), -INT32_C(    88680039), -INT32_C(    59616803) },
      { -INT32_C(   802142657), -INT32_C(   940677180), -INT32_C(   585529001),  INT32_C(  2027035519) } },
    { {  INT32_C(  1969927530),  INT32_C(  1476868634), -INT32_C(  2130098368), -INT32_C(  1602664268) },
      {  INT32_C(  1995831058),  INT32_C(   559150472), -INT32_C(  1407514161), -INT32_C(   978809510) },
      {  INT32_C(  1564087106), -INT32_C(  1917501107),  INT32_C(  1024376456),  INT32_C(   433948422) },
      {              INT32_MAX,  INT32_C(   977599804),              INT32_MIN, -INT32_C(  1800455223) } },
    { {  INT32_C(   110088830), -INT32_C(  1758993720),  INT32_C(  1162035947),  INT32_C(   302705615) },
      {  INT32_C(  1265583358),  INT32_C(   249111685), -INT32_C(   397678622), -INT32_C(   318691217) },
      { -INT32_C(  1024159494),  INT32_C(  1566120818),  INT32_C(   765697118), -INT32_C(  2042647160) },
      { -INT32_C(   493482337), -INT32_C(  1577321093),  INT32_C(  1020241445),  INT32_C(   605838870) } },
    { {  INT32_C(  2010296050), -INT32_C(  1266308142),  INT32_C(    27119762), -INT32_C(   202400008) },
      { -INT32_C(  1581915345),  INT32_C(  1560219646),  INT32_C(   864723627),  INT32_C(  1102760271) },
      {  INT32_C(  1253674104), -INT32_C(   906019273),  INT32_C(   130784271),  INT32_C(  1778039354) },
      {  INT32_C(  1086793650), -INT32_C(  1924561848),  INT32_C(    79782444),  INT32_C(   710645901) } },
    { { -INT32_C(  1693732707),  INT32_C(  1794640575), -INT32_C(    73497940), -INT32_C(  1019389877) },
      {  INT32_C(   453965540),  INT32_C(  1139019060), -INT32_C(   481579095),  INT32_C(   105727337) },
      { -INT32_C(  1264428811),  INT32_C(   236952162),  INT32_C(  1728691484), -INT32_C(   114604523) },
      { -INT32_C(  1961025596),  INT32_C(  1920319310), -INT32_C(   461161744), -INT32_C(  1025032216) } },
    { {  INT32_C(  1897150780), -INT32_C(   273352634),  INT32_C(   299040680),  INT32_C(   974659397) },
      { -INT32_C(   638600585),  INT32_C(  1894190676), -INT32_C(   522718773),  INT32_C(  1960378935) },
      { -INT32_C(  2115637957), -INT32_C(  1922000411), -INT32_C(   559987815), -INT32_C(   635914398) },
      {              INT32_MAX, -INT32_C(  1968655535),  INT32_C(   435347256),  INT32_C(   394150581) } },
    { { -INT32_C(   978122895), -INT32_C(   533357803), -INT32_C(  1010824052),  INT32_C(  1245157647) },
      {  INT32_C(  1825315974),  INT32_C(  1341734070), -INT32_C(   500328321), -INT32_C(  1061403313) },
      {  INT32_C(  1652911949), -INT32_C(  1773946358), -INT32_C(   698743865),  INT32_C(   589336989) },
      {  INT32_C(   426817528), -INT32_C(  1641708160), -INT32_C(   848028240),  INT32_C(   953875228) } },
    { {  INT32_C(  1687153838), -INT32_C(  1464628951),  INT32_C(  1904926753),  INT32_C(  1915831845) },
      { -INT32_C(  1059735626),  INT32_C(   945231985), -INT32_C(  1206996709), -INT32_C(   254005438) },
      {  INT32_C(  1146383131),  INT32_C(   384632820),  INT32_C(   226981863),  INT32_C(  1954527422) },
      {  INT32_C(  1121439149), -INT32_C(  1295329760),  INT32_C(  1777351224),  INT32_C(  1684649366) } },
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
SIMDE_TEST_FUNC_LIST_ENTRY(vqrdmlahh_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vqrdmlah_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vqrdmlah_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vqrdmlahq_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vqrdmlahq_s32)
SIMDE_TEST_FUNC_LIST_END

#include "test-neon-footer.h"