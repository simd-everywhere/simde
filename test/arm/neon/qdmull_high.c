#define SIMDE_TEST_ARM_NEON_INSN qdmull_high

#include "test-neon.h"
#include "../../../simde/arm/neon/qdmull_high.h"

static int
test_simde_vqdmull_high_s16 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    int16_t a[8];
    int16_t b[8];
    int32_t r[4];
  } test_vec[] = {
     { {   INT16_C(        3128), -INT16_C(        4196), -INT16_C(        5822),  INT16_C(        1127),
           INT16_C(        1638),  INT16_C(        9086),  INT16_C(        5866), -INT16_C(        1995) },
       {   INT16_C(        9725),  INT16_C(        4058),  INT16_C(        2522), -INT16_C(        7272),
           INT16_C(         716),  INT16_C(        9606),  INT16_C(        3845),  INT16_C(        2733) },
       {   INT32_C(     2345616),  INT32_C(   174560232),  INT32_C(    45109540), -INT32_C(    10904670) } },
     { {  -INT16_C(        6463),  INT16_C(        1731),  INT16_C(        3381), -INT16_C(        8558),
          -INT16_C(        3430), -INT16_C(        6657),  INT16_C(        5967), -INT16_C(        7104) },
       {  -INT16_C(        4185),  INT16_C(        9571),  INT16_C(        2575),  INT16_C(        8825),
           INT16_C(        7910), -INT16_C(        8648), -INT16_C(        6456),  INT16_C(        9583) },
       {  -INT32_C(    54262600),  INT32_C(   115139472), -INT32_C(    77045904), -INT32_C(   136155264) } },
     { {  -INT16_C(        9875),  INT16_C(        1134), -INT16_C(         450), -INT16_C(        4418),
          -INT16_C(        5943), -INT16_C(         189),  INT16_C(          25),  INT16_C(        2387) },
       {  -INT16_C(        8269), -INT16_C(        2330),  INT16_C(        6715),  INT16_C(        3434),
          -INT16_C(        5281),  INT16_C(        1448), -INT16_C(          63),  INT16_C(        4354) },
       {   INT32_C(    62769966), -INT32_C(      547344), -INT32_C(        3150),  INT32_C(    20785996) } },
     { {  -INT16_C(        9360),  INT16_C(        1022),  INT16_C(        7051), -INT16_C(        7920),
           INT16_C(        7496),  INT16_C(        6263), -INT16_C(        1973), -INT16_C(        7869) },
       {  -INT16_C(        4642),  INT16_C(        6027), -INT16_C(         208), -INT16_C(        6090),
          -INT16_C(        9820),  INT16_C(        8085), -INT16_C(        5509),  INT16_C(        6497) },
       {  -INT32_C(   147221440),  INT32_C(   101272710),  INT32_C(    21738514), -INT32_C(   102249786) } },
     { {   INT16_C(        5511), -INT16_C(        1109), -INT16_C(        1140),  INT16_C(        1241),
          -INT16_C(        1839), -INT16_C(        5927),  INT16_C(        4021),  INT16_C(        7688) },
       {  -INT16_C(        3740),  INT16_C(        8276), -INT16_C(        4572), -INT16_C(        6446),
          -INT16_C(        6557), -INT16_C(         315), -INT16_C(        5737),  INT16_C(        4260) },
       {   INT32_C(    24116646),  INT32_C(     3734010), -INT32_C(    46136954),  INT32_C(    65501760) } },
     { {  -INT16_C(        9524),  INT16_C(        7658),  INT16_C(        6677),  INT16_C(        8903),
          -INT16_C(        7844), -INT16_C(        9541), -INT16_C(        8500), -INT16_C(        6550) },
       {   INT16_C(        4616), -INT16_C(        2398), -INT16_C(        7077), -INT16_C(        4078),
           INT16_C(        6803),  INT16_C(        1009), -INT16_C(        3462), -INT16_C(        2642) },
       {  -INT32_C(   106725464), -INT32_C(    19253738),  INT32_C(    58854000),  INT32_C(    34610200) } },
     { {   INT16_C(        5127), -INT16_C(         743), -INT16_C(        1622), -INT16_C(        6599),
          -INT16_C(         243),  INT16_C(        2148), -INT16_C(        6632), -INT16_C(        4335) },
       {  -INT16_C(         642), -INT16_C(         425),  INT16_C(         645),  INT16_C(        8310),
           INT16_C(        5285), -INT16_C(        8239),  INT16_C(        4776),  INT16_C(        2652) },
       {  -INT32_C(     2568510), -INT32_C(    35394744), -INT32_C(    63348864), -INT32_C(    22992840) } },
     { {   INT16_C(        7091), -INT16_C(        2728),  INT16_C(        3504), -INT16_C(        4623),
           INT16_C(        4344),  INT16_C(        3021), -INT16_C(        4493),  INT16_C(        9085) },
       {   INT16_C(        1712), -INT16_C(        3276), -INT16_C(        2887), -INT16_C(        9017),
          -INT16_C(        7837), -INT16_C(        7316), -INT16_C(        4421), -INT16_C(        1137) },
       {  -INT32_C(    68087856), -INT32_C(    44203272),  INT32_C(    39727106), -INT32_C(    20659290) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x8_t a = simde_vld1q_s16(test_vec[i].a);
    simde_int16x8_t b = simde_vld1q_s16(test_vec[i].b);
    simde_int32x4_t r = simde_vqdmull_high_s16(a, b);

    simde_test_arm_neon_assert_equal_i32x4(r, simde_vld1q_s32(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vqdmull_high_s32 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    int32_t a[4];
    int32_t b[4];
    int64_t r[2];
  } test_vec[] = {
     { {   INT32_C(         6170653), -INT32_C(         5146428), -INT32_C(         7147572),  INT32_C(         9293542) },
       {   INT32_C(         4434909),  INT32_C(         9504219), -INT32_C(         4790785), -INT32_C(         9993686) },
       {   INT64_C(  68484961448040), -INT64_C( 185753481151624) } },
     { {  -INT32_C(         8799211), -INT32_C(         6025890),  INT32_C(         5844051), -INT32_C(         6103853) },
       {  -INT32_C(          281199), -INT32_C(         5197963),  INT32_C(         8779227),  INT32_C(         8600897) },
       {   INT64_C( 102612500657154), -INT64_C( 104997221912282) } },
     { {  -INT32_C(         4311465),  INT32_C(         2252047),  INT32_C(         9518225),  INT32_C(         4004059) },
       {  -INT32_C(         9587310), -INT32_C(         8088276),  INT32_C(         8731969),  INT32_C(         2971007) },
       {   INT64_C( 166225691270050),  INT64_C(  23792174634826) } },
     { {   INT32_C(         3888828),  INT32_C(         6869826), -INT32_C(         3770734), -INT32_C(         9612939) },
       {   INT32_C(         9919934), -INT32_C(         7244274),  INT32_C(         7805998), -INT32_C(         2397312) },
       {  -INT64_C(  58868684125064),  INT64_C(  46090428039936) } },
     { {  -INT32_C(         6348860),  INT32_C(         6128394),  INT32_C(         2500134), -INT32_C(         9234729) },
       {  -INT32_C(         9455599),  INT32_C(         3241977), -INT32_C(         4792881),  INT32_C(         8209567) },
       {  -INT64_C(  23965689492108), -INT64_C( 151626252904686) } },
     { {   INT32_C(         1511352), -INT32_C(         7794834),  INT32_C(         6466748),  INT32_C(         2417772) },
       {   INT32_C(          845133),  INT32_C(         1594456),  INT32_C(         9682949), -INT32_C(         6201105) },
       {   INT64_C( 125234382159704), -INT64_C(  29985716076120) } },
     { {  -INT32_C(         7276163),  INT32_C(         5549728), -INT32_C(         6831820),  INT32_C(          992115) },
       {   INT32_C(         9199122), -INT32_C(         4143289), -INT32_C(         2419222), -INT32_C(         7236938) },
       {   INT64_C(  33055378488080), -INT64_C(  14359749487740) } },
     { {  -INT32_C(         5422339),  INT32_C(         6658363), -INT32_C(         9978291),  INT32_C(         4140966) },
       {   INT32_C(         7413089), -INT32_C(         7374139),  INT32_C(         2222880), -INT32_C(         7849937) },
       {  -INT64_C(  44361086996160), -INT64_C(  65012644438284) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x4_t a = simde_vld1q_s32(test_vec[i].a);
    simde_int32x4_t b = simde_vld1q_s32(test_vec[i].b);
    simde_int64x2_t r = simde_vqdmull_high_s32(a, b);

    simde_test_arm_neon_assert_equal_i64x2(r, simde_vld1q_s64(test_vec[i].r));
  }

  return 0;
}


SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(vqdmull_high_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vqdmull_high_s32)
SIMDE_TEST_FUNC_LIST_END

#include "test-neon-footer.h"
