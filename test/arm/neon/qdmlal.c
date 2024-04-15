#define SIMDE_TEST_ARM_NEON_INSN qdmlal

#include "test-neon.h"
#include "../../../simde/arm/neon/qdmlal.h"

static int
test_simde_vqdmlalh_s16 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    int32_t a[1];
    int16_t b[1];
    int16_t c[1];
    int32_t r[1];
  } test_vec[] = {
     { {  -INT32_C(   6191349) },
       {   INT16_C(      8935) },
       {  -INT16_C(       976) },
       {  -INT32_C(  23632469) } },
     { {  -INT32_C(   8133285) },
       {   INT16_C(      6661) },
       {   INT16_C(       904) },
       {   INT32_C(   3909803) } },
     { {  -INT32_C(   6622410) },
       {  -INT16_C(      9110) },
       {  -INT16_C(      9860) },
       {   INT32_C( 173026790) } },
     { {   INT32_C(   2865485) },
       {   INT16_C(       139) },
       {  -INT16_C(      8277) },
       {   INT32_C(    564479) } },
     { {  -INT32_C(   2994139) },
       {   INT16_C(      4971) },
       {   INT16_C(      7745) },
       {   INT32_C(  74006651) } },
     { {   INT32_C(   1073049) },
       {  -INT16_C(      3760) },
       {   INT16_C(      9171) },
       {  -INT32_C(  67892871) } },
     { {   INT32_C(   4306165) },
       {  -INT16_C(      3518) },
       {   INT16_C(      2822) },
       {  -INT32_C(  15549427) } },
     { {   INT32_C(   2683498) },
       {   INT16_C(      6764) },
       {  -INT16_C(       707) },
       {  -INT32_C(   6880798) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    int32_t r = simde_vqdmlalh_s16(test_vec[i].a[0], test_vec[i].b[0], test_vec[i].c[0]);

    simde_assert_equal_i32(r, test_vec[i].r[0]);
  }

  return 0;
}

static int
test_simde_vqdmlals_s32 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    int64_t a[1];
    int32_t b[1];
    int32_t c[1];
    int64_t r[1];
  } test_vec[] = {
     { {   INT64_C(      994701330) },
       {  -INT32_C(        8142695) },
       {  -INT32_C(        6476313) },
       {   INT64_C(105470277668400) } },
     { {  -INT64_C(      250315414) },
       {  -INT32_C(        7860762) },
       {  -INT32_C(        6684612) },
       {   INT64_C(105092037673274) } },
     { {  -INT64_C(      388043893) },
       {  -INT32_C(        5044219) },
       {   INT32_C(         105388) },
       {  -INT64_C(  1063588347837) } },
     { {   INT64_C(      756231599) },
       {   INT32_C(        6764338) },
       {   INT32_C(        8602282) },
       {   INT64_C(116378242270231) } },
     { {   INT64_C(      653109401) },
       {   INT32_C(        4179167) },
       {  -INT32_C(         486101) },
       {  -INT64_C(  4062341406333) } },
     { {  -INT64_C(      274319077) },
       {  -INT32_C(        6189685) },
       {   INT32_C(        9485006) },
       {  -INT64_C(117418673045297) } },
     { {   INT64_C(      789989051) },
       {   INT32_C(        4846033) },
       {  -INT32_C(        6660847) },
       {  -INT64_C( 64556578750851) } },
     { {  -INT64_C(      835469905) },
       {   INT32_C(        2995714) },
       {  -INT32_C(        3814223) },
       {  -INT64_C( 22853477950349) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    int64_t r = simde_vqdmlals_s32(test_vec[i].a[0], test_vec[i].b[0], test_vec[i].c[0]);

    simde_assert_equal_i64(r, test_vec[i].r[0]);
  }

  return 0;
}

static int
test_simde_vqdmlal_s16 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    int32_t a[4];
    int16_t b[4];
    int16_t c[4];
    int32_t r[4];
  } test_vec[] = {
     { {   INT32_C(     47994), -INT32_C(     20778),  INT32_C(     33097), -INT32_C(     10928) },
       {  -INT16_C(      2031), -INT16_C(      4604), -INT16_C(      7758),  INT16_C(      1292) },
       {  -INT16_C(       268), -INT16_C(      6686),  INT16_C(      8116), -INT16_C(       337) },
       {   INT32_C(   1136610),  INT32_C(  61543910), -INT32_C( 125894759), -INT32_C(    881736) } },
     { {  -INT32_C(     78165), -INT32_C(     27105),  INT32_C(      1998), -INT32_C(     94511) },
       {  -INT16_C(      4801), -INT16_C(      5450), -INT16_C(      9223),  INT16_C(      3371) },
       {  -INT16_C(      8233), -INT16_C(      4388),  INT16_C(      9382), -INT16_C(       258) },
       {   INT32_C(  78975101),  INT32_C(  47802095), -INT32_C( 173058374), -INT32_C(   1833947) } },
     { {  -INT32_C(     43334), -INT32_C(     41712),  INT32_C(     44640), -INT32_C(     92818) },
       {   INT16_C(      4906), -INT16_C(      4840), -INT16_C(       749), -INT16_C(      6353) },
       {  -INT16_C(      3678),  INT16_C(      1558),  INT16_C(      9974), -INT16_C(      6944) },
       {  -INT32_C(  36131870), -INT32_C(  15123152), -INT32_C(  14896412),  INT32_C(  88137646) } },
     { {  -INT32_C(     22346),  INT32_C(     40130),  INT32_C(     89898), -INT32_C(      1442) },
       {   INT16_C(       832),  INT16_C(      1545),  INT16_C(      7545), -INT16_C(        37) },
       {  -INT16_C(      3717),  INT16_C(      8015),  INT16_C(      1913), -INT16_C(      4544) },
       {  -INT32_C(   6207434),  INT32_C(  24806480),  INT32_C(  28957068),  INT32_C(    334814) } },
     { {   INT32_C(     25579), -INT32_C(     44904),  INT32_C(     98978), -INT32_C(     37785) },
       {  -INT16_C(      5427), -INT16_C(      9421),  INT16_C(      4768),  INT16_C(       287) },
       {  -INT16_C(      3431), -INT16_C(      5785),  INT16_C(      5695),  INT16_C(      5829) },
       {   INT32_C(  37265653),  INT32_C( 108956066),  INT32_C(  54406498),  INT32_C(   3308061) } },
     { {   INT32_C(     97923),  INT32_C(     92399),  INT32_C(     89588), -INT32_C(     79825) },
       {   INT16_C(      9641),  INT16_C(      7675), -INT16_C(      7751),  INT16_C(      7520) },
       {   INT16_C(      4626),  INT16_C(      5458), -INT16_C(      7529), -INT16_C(      9852) },
       {   INT32_C(  89296455),  INT32_C(  83872699),  INT32_C( 116804146), -INT32_C( 148253905) } },
     { {   INT32_C(     98862), -INT32_C(      1896),  INT32_C(     65060),  INT32_C(     36938) },
       {  -INT16_C(      2865), -INT16_C(      9424), -INT16_C(      8867), -INT16_C(      3713) },
       {  -INT16_C(      9160), -INT16_C(      7328), -INT16_C(       708),  INT16_C(      2633) },
       {   INT32_C(  52585662),  INT32_C( 138116248),  INT32_C(  12620732), -INT32_C(  19515720) } },
     { {   INT32_C(     78126),  INT32_C(      7840),  INT32_C(     80240), -INT32_C(     68184) },
       {   INT16_C(      8642), -INT16_C(       579),  INT16_C(      2963),  INT16_C(      9252) },
       {  -INT16_C(      7314), -INT16_C(      5230),  INT16_C(      8688),  INT16_C(      5749) },
       {  -INT32_C( 126337050),  INT32_C(   6064180),  INT32_C(  51565328),  INT32_C( 106311312) } },
     { {  -INT32_C(        16), -INT32_C(        15), -INT32_C(        14), -INT32_C(        13) },
       {             INT16_MIN,            INT16_MIN,            INT16_MIN,            INT16_MIN },
       {             INT16_MIN,            INT16_MIN,            INT16_MIN,            INT16_MIN },
       {   INT32_C(2147483631),  INT32_C(2147483632),  INT32_C(2147483633),  INT32_C(2147483634) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x4_t a = simde_vld1q_s32(test_vec[i].a);
    simde_int16x4_t b = simde_vld1_s16(test_vec[i].b);
    simde_int16x4_t c = simde_vld1_s16(test_vec[i].c);
    simde_int32x4_t r = simde_vqdmlal_s16(a, b, c);

    simde_test_arm_neon_assert_equal_i32x4(r, simde_vld1q_s32(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vqdmlal_s32 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    int64_t a[2];
    int32_t b[2];
    int32_t c[2];
    int64_t r[2];
  } test_vec[] = {
     { {   INT64_C(      845205397),  INT64_C(       71618730) },
       {  -INT32_C(        8506110), -INT32_C(        5997969) },
       {  -INT32_C(         755191),  INT32_C(        8695866) },
       {   INT64_C( 12848320639417), -INT64_C(104314997773578) } },
     { {  -INT64_C(      459781408),  INT64_C(       49282602) },
       {   INT32_C(        3947837), -INT32_C(        8389725) },
       {  -INT32_C(        5582373), -INT32_C(        8467379) },
       {  -INT64_C( 44077057135810),  INT64_C(142078011844152) } },
     { {  -INT64_C(      798562048),  INT64_C(        6909560) },
       {   INT32_C(        5205898),  INT32_C(        5769494) },
       {   INT32_C(        2380672),  INT32_C(        9432366) },
       {   INT64_C( 24786272644864),  INT64_C(108839964995168) } },
     { {  -INT64_C(      972557647), -INT64_C(      839281959) },
       {   INT32_C(         545324), -INT32_C(        3103272) },
       {  -INT32_C(        8512777), -INT32_C(        2636705) },
       {  -INT64_C(  9285415767143),  INT64_C( 16363986315561) } },
     { {  -INT64_C(      928911634),  INT64_C(      842482216) },
       {  -INT32_C(        5349220),  INT32_C(        7281630) },
       {   INT32_C(        3418587),  INT32_C(        9455476) },
       {  -INT64_C( 36574476815914),  INT64_C(137703397893976) } },
     { {  -INT64_C(      647837823), -INT64_C(      637410506) },
       {  -INT32_C(        2946260), -INT32_C(         534877) },
       {  -INT32_C(        7636201), -INT32_C(        6715356) },
       {   INT64_C( 44995819278697),  INT64_C(  7183141531918) } },
     { {  -INT64_C(      841474483),  INT64_C(      164819968) },
       {   INT32_C(        2974160), -INT32_C(        9291319) },
       {   INT32_C(        2611225),  INT32_C(        3255629) },
       {   INT64_C( 15531560417517), -INT64_C( 60498010349334) } },
     { {   INT64_C(      641627970),  INT64_C(      735920203) },
       {  -INT32_C(        8397045),  INT32_C(        6142639) },
       {  -INT32_C(        6977990), -INT32_C(        5600341) },
       {   INT64_C(117189633707070), -INT64_C( 68801010159595) } },
     { {  -INT64_C(             16), -INT64_C(             15) },
       {                  INT32_MIN,                 INT32_MIN },
       {                  INT32_MIN,                 INT32_MIN },
       {INT64_C(9223372036854775791), INT64_C(9223372036854775792) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int64x2_t a = simde_vld1q_s64(test_vec[i].a);
    simde_int32x2_t b = simde_vld1_s32(test_vec[i].b);
    simde_int32x2_t c = simde_vld1_s32(test_vec[i].c);
    simde_int64x2_t r = simde_vqdmlal_s32(a, b, c);

    simde_test_arm_neon_assert_equal_i64x2(r, simde_vld1q_s64(test_vec[i].r));
  }

  return 0;
}


SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(vqdmlalh_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vqdmlals_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vqdmlal_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vqdmlal_s32)
SIMDE_TEST_FUNC_LIST_END

#include "test-neon-footer.h"
