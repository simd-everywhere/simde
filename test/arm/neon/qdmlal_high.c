#define SIMDE_TEST_ARM_NEON_INSN qdmlal_high

#include "test-neon.h"
#include "../../../simde/arm/neon/qdmlal_high.h"

static int
test_simde_vqdmlal_high_s16 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    int32_t a[4];
    int16_t b[8];
    int16_t c[8];
    int32_t r[4];
  } test_vec[] = {
     { {  -INT32_C(   4008683), -INT32_C(   5028178), -INT32_C(   8962997),  INT32_C(   2551757) },
       {   INT16_C(      5202), -INT16_C(      4550), -INT16_C(      5993), -INT16_C(      4270),
          -INT16_C(      1887),  INT16_C(      3575),  INT16_C(      5768), -INT16_C(       307) },
       {   INT16_C(      6131), -INT16_C(      5050), -INT16_C(       190), -INT16_C(      7932),
           INT16_C(      8515),  INT16_C(      8459), -INT16_C(      6993), -INT16_C(      9367) },
       {  -INT32_C(  36144293),  INT32_C(  55453672), -INT32_C(  89634245),  INT32_C(   8303095) } },
     { {  -INT32_C(   2170289), -INT32_C(    281565),  INT32_C(   3343964), -INT32_C(   2785758) },
       {   INT16_C(      4163),  INT16_C(      8019),  INT16_C(      3543),  INT16_C(        72),
           INT16_C(      4500), -INT16_C(      4727),  INT16_C(      1520), -INT16_C(      9563) },
       {   INT16_C(      8885), -INT16_C(      6877), -INT16_C(       685), -INT16_C(      5459),
           INT16_C(      5251),  INT16_C(      2695),  INT16_C(      5168), -INT16_C(       338) },
       {   INT32_C(  45088711), -INT32_C(  25760095),  INT32_C(  19054684),  INT32_C(   3678830) } },
     { {  -INT32_C(   4553302),  INT32_C(   3125108), -INT32_C(   2065657), -INT32_C(   8992153) },
       {   INT16_C(      3431), -INT16_C(      7556), -INT16_C(      6557), -INT16_C(      6673),
          -INT16_C(      5314),  INT16_C(      5325),  INT16_C(      6866), -INT16_C(      2847) },
       {  -INT16_C(      3580),  INT16_C(      1547), -INT16_C(      6342),  INT16_C(      7251),
           INT16_C(      2064),  INT16_C(      9316), -INT16_C(      6342), -INT16_C(      6417) },
       {  -INT32_C(  26489494),  INT32_C( 102340508), -INT32_C(  89154001),  INT32_C(  27546245) } },
     { {  -INT32_C(    484890), -INT32_C(   2201981),  INT32_C(   3679408),  INT32_C(   1853540) },
       {   INT16_C(      3856),  INT16_C(      7814), -INT16_C(      1769),  INT16_C(      1436),
           INT16_C(      3444), -INT16_C(      9841), -INT16_C(      3411),  INT16_C(      8367) },
       {   INT16_C(      1142),  INT16_C(      2589),  INT16_C(      1678),  INT16_C(      1142),
          -INT16_C(      5847),  INT16_C(      6564),  INT16_C(      7556),  INT16_C(      3693) },
       {  -INT32_C(  40759026), -INT32_C( 131394629), -INT32_C(  47867624),  INT32_C(  63652202) } },
     { {   INT32_C(   2121238),  INT32_C(   9877268), -INT32_C(   1143534), -INT32_C(   9498808) },
       {   INT16_C(      5303), -INT16_C(      1950), -INT16_C(      9312),  INT16_C(      5725),
          -INT16_C(      6481), -INT16_C(       780),  INT16_C(      5191), -INT16_C(       563) },
       {   INT16_C(      8677), -INT16_C(      6810), -INT16_C(      8755), -INT16_C(      8531),
           INT16_C(       820),  INT16_C(      2131),  INT16_C(      5933),  INT16_C(      2473) },
       {  -INT32_C(   8507602),  INT32_C(   6552908),  INT32_C(  60452872), -INT32_C(  12283406) } },
     { {  -INT32_C(   3147561),  INT32_C(   5096455), -INT32_C(   7864011), -INT32_C(   8639771) },
       {  -INT16_C(      6393), -INT16_C(      6974),  INT16_C(      1116), -INT16_C(      9693),
           INT16_C(      9938), -INT16_C(      8485),  INT16_C(      9800),  INT16_C(      2177) },
       {   INT16_C(       369),  INT16_C(      3864), -INT16_C(      1403),  INT16_C(      8739),
           INT16_C(      9358),  INT16_C(      4743), -INT16_C(      9043),  INT16_C(      9839) },
       {   INT32_C( 182852047), -INT32_C(  75392255), -INT32_C( 185106811),  INT32_C(  34199235) } },
     { {   INT32_C(   2379833),  INT32_C(   4584653), -INT32_C(   2621237),  INT32_C(    775961) },
       {   INT16_C(      5859),  INT16_C(      3035), -INT16_C(      5242), -INT16_C(      5764),
           INT16_C(      6220),  INT16_C(      7190), -INT16_C(      6485), -INT16_C(      4729) },
       {   INT16_C(      3318), -INT16_C(      2580), -INT16_C(      7939),  INT16_C(      6236),
           INT16_C(      1562), -INT16_C(      4136),  INT16_C(      2163), -INT16_C(      4317) },
       {   INT32_C(  21811113), -INT32_C(  54891027), -INT32_C(  30675347),  INT32_C(  41606147) } },
     { {   INT32_C(   6237148), -INT32_C(   9768512), -INT32_C(   6859928),  INT32_C(   5368290) },
       {  -INT16_C(      9903), -INT16_C(      7336),  INT16_C(      1785),  INT16_C(      5751),
          -INT16_C(      7034),  INT16_C(      5612),  INT16_C(      5698), -INT16_C(      5535) },
       {  -INT16_C(      9269), -INT16_C(      5310),  INT16_C(      5746),  INT16_C(      4013),
           INT16_C(      5760),  INT16_C(      4110),  INT16_C(      8914), -INT16_C(       764) },
       {  -INT32_C(  74794532),  INT32_C(  36362128),  INT32_C(  94724016),  INT32_C(  13825770) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x4_t a = simde_vld1q_s32(test_vec[i].a);
    simde_int16x8_t b = simde_vld1q_s16(test_vec[i].b);
    simde_int16x8_t c = simde_vld1q_s16(test_vec[i].c);
    simde_int32x4_t r = simde_vqdmlal_high_s16(a, b, c);

    simde_test_arm_neon_assert_equal_i32x4(r, simde_vld1q_s32(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vqdmlal_high_s32 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    int64_t a[2];
    int32_t b[4];
    int32_t c[4];
    int64_t r[2];
  } test_vec[] = {
     { {   INT64_C(     795560267),  INT64_C(     507739276) },
       {  -INT32_C(        988690),  INT32_C(        908701), -INT32_C(        284474),  INT32_C(        671690) },
       {   INT32_C(        117297),  INT32_C(        669124), -INT32_C(        739630), -INT32_C(        612370) },
       {   INT64_C(  421606569507), -INT64_C(  822137871324) } },
     { {  -INT64_C(     199701311), -INT64_C(     239264910) },
       {   INT32_C(        660536),  INT32_C(        137005), -INT32_C(        440186), -INT32_C(        152398) },
       {  -INT32_C(        263430),  INT32_C(        859419),  INT32_C(        961341),  INT32_C(        663492) },
       {  -INT64_C(  846537400163), -INT64_C(  202468972542) } },
     { {   INT64_C(     564059206), -INT64_C(     412362369) },
       {  -INT32_C(        654124),  INT32_C(        670018),  INT32_C(        286862), -INT32_C(        574625) },
       {   INT32_C(          7787),  INT32_C(        752510), -INT32_C(        240056),  INT32_C(        577510) },
       {  -INT64_C(  137161829338), -INT64_C(  664115729869) } },
     { {  -INT64_C(     167642734),  INT64_C(     893273420) },
       {  -INT32_C(        169982), -INT32_C(        374407), -INT32_C(         45505), -INT32_C(        362726) },
       {   INT32_C(        241070),  INT32_C(        122131),  INT32_C(        491343),  INT32_C(        110512) },
       {  -INT64_C(   44884769164), -INT64_C(   79277878004) } },
     { {   INT64_C(     227912254),  INT64_C(       7129424) },
       {  -INT32_C(        292729),  INT32_C(        461415),  INT32_C(        188811),  INT32_C(        891933) },
       {  -INT32_C(         15187),  INT32_C(        143937), -INT32_C(        197341),  INT32_C(        607886) },
       {  -INT64_C(   74292390848),  INT64_C( 1084394296700) } },
     { {  -INT64_C(     237091799), -INT64_C(     400804847) },
       {  -INT32_C(        918731), -INT32_C(        765967),  INT32_C(        862619),  INT32_C(        190016) },
       {   INT32_C(        123092), -INT32_C(        647395),  INT32_C(        880966),  INT32_C(        285303) },
       {   INT64_C( 1519638928109),  INT64_C(  108023464849) } },
     { {  -INT64_C(      64349374), -INT64_C(     521177021) },
       {  -INT32_C(        901925), -INT32_C(        429371),  INT32_C(        953612), -INT32_C(        755979) },
       {  -INT32_C(        408089), -INT32_C(        658015), -INT32_C(         94549),  INT32_C(        666792) },
       {  -INT64_C(  180390471350), -INT64_C( 1008682675757) } },
     { {   INT64_C(     185193827), -INT64_C(       1569354) },
       {  -INT32_C(        759050), -INT32_C(        437291),  INT32_C(        207575), -INT32_C(        177006) },
       {  -INT32_C(        262650),  INT32_C(        912777),  INT32_C(        556302), -INT32_C(         41245) },
       {   INT64_C(  231133969127),  INT64_C(   14599655586) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int64x2_t a = simde_vld1q_s64(test_vec[i].a);
    simde_int32x4_t b = simde_vld1q_s32(test_vec[i].b);
    simde_int32x4_t c = simde_vld1q_s32(test_vec[i].c);
    simde_int64x2_t r = simde_vqdmlal_high_s32(a, b, c);

    simde_test_arm_neon_assert_equal_i64x2(r, simde_vld1q_s64(test_vec[i].r));
  }

  return 0;
}


SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(vqdmlal_high_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vqdmlal_high_s32)
SIMDE_TEST_FUNC_LIST_END

#include "test-neon-footer.h"
