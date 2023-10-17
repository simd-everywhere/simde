#define SIMDE_TEST_ARM_NEON_INSN qdmlsl_high_lane

#include "test-neon.h"
#include "../../../simde/arm/neon/qdmlsl_high_lane.h"

static int
test_simde_vqdmlsl_high_lane_s16 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    int32_t a[4];
    int16_t b[8];
    int16_t v[4];
    int8_t lane;
    int32_t r[4];
  } test_vec[] = {
     { {   INT32_C( 701766005), -INT32_C( 532299217), -INT32_C( 692528001), -INT32_C( 718067011) },
       {   INT16_C(      5655), -INT16_C(      7895), -INT16_C(      2651),  INT16_C(      6636),
          -INT16_C(      1285), -INT16_C(      2290), -INT16_C(      6574), -INT16_C(      3871) },
       {   INT16_C(      7190), -INT16_C(      9951), -INT16_C(      4444),  INT16_C(      9020)},
           INT8_C(         0),
       {   INT32_C( 720244305), -INT32_C( 499369017), -INT32_C( 597993881), -INT32_C( 662402031) } },
     { {  -INT32_C( 999286111),  INT32_C( 448217377), -INT32_C( 977134270), -INT32_C( 615754924) },
       {   INT16_C(      9385),  INT16_C(      6468),  INT16_C(      1459),  INT16_C(      1745),
          -INT16_C(      5037), -INT16_C(      1963),  INT16_C(      1155), -INT16_C(      4707) },
       {  -INT16_C(       154),  INT16_C(      1256), -INT16_C(      6295),  INT16_C(      8502)},
           INT8_C(         2),
       {  -INT32_C(1062701941),  INT32_C( 423503207), -INT32_C( 962592820), -INT32_C( 675016054) } },
     { {  -INT32_C( 166972908), -INT32_C( 688547594), -INT32_C( 958428321), -INT32_C( 172358765) },
       {   INT16_C(      3599), -INT16_C(      4294),  INT16_C(      4651), -INT16_C(      4778),
          -INT16_C(      3374), -INT16_C(      1032), -INT16_C(       469),  INT16_C(      5690) },
       {   INT16_C(      5429), -INT16_C(      7133),  INT16_C(      4223), -INT16_C(      2009)},
           INT8_C(         2),
       {  -INT32_C( 138476104), -INT32_C( 679831322), -INT32_C( 954467147), -INT32_C( 220416505) } },
     { {  -INT32_C(  25288675),  INT32_C( 236811221),  INT32_C( 833326174), -INT32_C( 591405948) },
       {  -INT16_C(      6115), -INT16_C(       476),  INT16_C(      6029), -INT16_C(      7903),
           INT16_C(      3519), -INT16_C(      7182), -INT16_C(       346), -INT16_C(      2174) },
       {   INT16_C(      1767), -INT16_C(      8420),  INT16_C(      7315),  INT16_C(       904)},
           INT8_C(         2),
       {  -INT32_C(  76771645),  INT32_C( 341883881),  INT32_C( 838388154), -INT32_C( 559600328) } },
     { {  -INT32_C( 855336629),  INT32_C( 906845897), -INT32_C( 251633756),  INT32_C(   8482797) },
       {  -INT16_C(      2575), -INT16_C(      3957), -INT16_C(      5600), -INT16_C(      8026),
          -INT16_C(      8582),  INT16_C(      4016),  INT16_C(      8578),  INT16_C(      1477) },
       {  -INT16_C(      3356), -INT16_C(      6870),  INT16_C(      2621), -INT16_C(      4607)},
           INT8_C(         2),
       {  -INT32_C( 810349785),  INT32_C( 885794025), -INT32_C( 296599632),  INT32_C(    740363) } },
     { {   INT32_C( 847514568), -INT32_C( 318708549),  INT32_C( 900685617), -INT32_C( 505950930) },
       {  -INT16_C(      9272),  INT16_C(      4269), -INT16_C(      9927),  INT16_C(      2036),
          -INT16_C(      6639),  INT16_C(      2316), -INT16_C(      9188),  INT16_C(      7193) },
       {   INT16_C(      2164),  INT16_C(      7350), -INT16_C(       626),  INT16_C(      5339)},
           INT8_C(         3),
       {   INT32_C( 918405810), -INT32_C( 343438797),  INT32_C( 998795081), -INT32_C( 582757784) } },
     { {   INT32_C( 804918704), -INT32_C( 524071003), -INT32_C( 986920723),  INT32_C( 956365470) },
       {  -INT16_C(      9578), -INT16_C(      3266),  INT16_C(      9986),  INT16_C(      1944),
          -INT16_C(      2569), -INT16_C(      7603),  INT16_C(      5080),  INT16_C(      9340) },
       {  -INT16_C(      6408),  INT16_C(      6393), -INT16_C(      7501), -INT16_C(      8185)},
           INT8_C(         1),
       {   INT32_C( 837765938), -INT32_C( 426859045), -INT32_C(1051873603),  INT32_C( 836944230) } },
     { {  -INT32_C( 413669468), -INT32_C(  82188184), -INT32_C( 781850974),  INT32_C( 570418568) },
       {   INT16_C(      4896),  INT16_C(      8573),  INT16_C(      6139),  INT16_C(       691),
          -INT16_C(      6651), -INT16_C(      3345),  INT16_C(      3473), -INT16_C(      9775) },
       {  -INT16_C(       870), -INT16_C(      4925), -INT16_C(      9268), -INT16_C(      2864)},
           INT8_C(         0),
       {  -INT32_C( 425242208), -INT32_C(  88008484), -INT32_C( 775807954),  INT32_C( 553410068) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x4_t a = simde_vld1q_s32(test_vec[i].a);
    simde_int16x8_t b = simde_vld1q_s16(test_vec[i].b);
    simde_int16x4_t v = simde_vld1_s16(test_vec[i].v);
    simde_int32x4_t r;
    SIMDE_CONSTIFY_4_(simde_vqdmlsl_high_lane_s16, r, (HEDLEY_UNREACHABLE(), r), test_vec[i].lane, a, b, v);

    simde_test_arm_neon_assert_equal_i32x4(r, simde_vld1q_s32(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vqdmlsl_high_laneq_s16 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    int32_t a[4];
    int16_t b[8];
    int16_t v[8];
    int8_t lane;
    int32_t r[4];
  } test_vec[] = {
     { {  -INT32_C( 872780517), -INT32_C(  29391408),  INT32_C(  45946525), -INT32_C( 832013542) },
       {  -INT16_C(      6241),  INT16_C(      4618), -INT16_C(      2647), -INT16_C(       962),
          -INT16_C(      6662),  INT16_C(      8291),  INT16_C(      9815), -INT16_C(      8604) },
       {   INT16_C(      2109),  INT16_C(      5858),  INT16_C(      7276), -INT16_C(      9607),
          -INT16_C(      1930),  INT16_C(      8982), -INT16_C(      9729),  INT16_C(      7886)},
           INT8_C(         3),
       {  -INT32_C(1000784185),  INT32_C( 129911866),  INT32_C( 234531935), -INT32_C( 997330798) } },
     { {  -INT32_C( 965454540),  INT32_C( 656372837), -INT32_C( 660432140),  INT32_C( 439902238) },
       {  -INT16_C(      8190),  INT16_C(      9341),  INT16_C(       684),  INT16_C(      5555),
          -INT16_C(      4936), -INT16_C(      7543),  INT16_C(       994), -INT16_C(      3774) },
       {  -INT16_C(       564), -INT16_C(      8121), -INT16_C(      5137), -INT16_C(      9349),
          -INT16_C(       116),  INT16_C(      4315), -INT16_C(      4968), -INT16_C(      3655)},
           INT8_C(         7),
       {  -INT32_C(1001536700),  INT32_C( 601233507), -INT32_C( 653166000),  INT32_C( 412314298) } },
     { {  -INT32_C( 907415859),  INT32_C( 509071204),  INT32_C( 710920080),  INT32_C( 225257492) },
       {   INT16_C(      8228), -INT16_C(      7737),  INT16_C(      4393),  INT16_C(      2491),
          -INT16_C(      1466), -INT16_C(      8359),  INT16_C(      9611), -INT16_C(      8865) },
       {   INT16_C(      3460), -INT16_C(      9079),  INT16_C(      7019),  INT16_C(      8362),
          -INT16_C(      8490), -INT16_C(      5629),  INT16_C(      7713),  INT16_C(      2152)},
           INT8_C(         7),
       {  -INT32_C( 901106195),  INT32_C( 545048340),  INT32_C( 669554336),  INT32_C( 263412452) } },
     { {  -INT32_C( 764998060),  INT32_C( 455574662),  INT32_C( 610461886), -INT32_C( 371876860) },
       {  -INT16_C(      3285), -INT16_C(      6882), -INT16_C(      9633),  INT16_C(      1704),
           INT16_C(      6596),  INT16_C(      4573), -INT16_C(      6582), -INT16_C(      6057) },
       {  -INT16_C(      1845), -INT16_C(      3438), -INT16_C(      8109), -INT16_C(      4210),
          -INT16_C(      9654), -INT16_C(      4565), -INT16_C(      6427), -INT16_C(      2142)},
           INT8_C(         1),
       {  -INT32_C( 719643964),  INT32_C( 487018610),  INT32_C( 565204054), -INT32_C( 413524792) } },
     { {  -INT32_C( 587174221),  INT32_C(  56513196), -INT32_C( 442232801), -INT32_C( 572018074) },
       {   INT16_C(      6729),  INT16_C(      1327), -INT16_C(      6140),  INT16_C(      6552),
          -INT16_C(       519), -INT16_C(      2872),  INT16_C(      7615), -INT16_C(      5938) },
       {   INT16_C(      8850),  INT16_C(      3637),  INT16_C(      1171),  INT16_C(      4708),
          -INT16_C(      4234),  INT16_C(       249), -INT16_C(      4600),  INT16_C(      9135)},
           INT8_C(         2),
       {  -INT32_C( 585958723),  INT32_C(  63239420), -INT32_C( 460067131), -INT32_C( 558111278) } },
     { {  -INT32_C( 811954240),  INT32_C( 760955593),  INT32_C( 368199597),  INT32_C( 748371992) },
       {   INT16_C(      8111), -INT16_C(      5698), -INT16_C(      3905), -INT16_C(      7403),
          -INT16_C(      8976),  INT16_C(      2047),  INT16_C(      8951),  INT16_C(      6885) },
       {   INT16_C(      8865),  INT16_C(       389),  INT16_C(      9139), -INT16_C(      4946),
          -INT16_C(      8242),  INT16_C(      9625), -INT16_C(      3018), -INT16_C(      8395)},
           INT8_C(         7),
       {  -INT32_C( 962661280),  INT32_C( 795324723),  INT32_C( 518486887),  INT32_C( 863971142) } },
     { {   INT32_C( 666989284),  INT32_C( 215517931), -INT32_C( 860315495),  INT32_C( 563015594) },
       {  -INT16_C(      1132),  INT16_C(      1616),  INT16_C(      1479),  INT16_C(      6440),
           INT16_C(      1118), -INT16_C(      1105),  INT16_C(      2256),  INT16_C(      7406) },
       {  -INT16_C(      4130),  INT16_C(      7931), -INT16_C(      8746), -INT16_C(      7137),
          -INT16_C(      7158), -INT16_C(      3725), -INT16_C(      8565), -INT16_C(      8470)},
           INT8_C(         4),
       {   INT32_C( 682994572),  INT32_C( 199698751), -INT32_C( 828018599),  INT32_C( 669039890) } },
     { {   INT32_C( 307095870), -INT32_C( 837445993), -INT32_C( 866521360), -INT32_C(  74057105) },
       {   INT16_C(      4322), -INT16_C(      8839),  INT16_C(      4483), -INT16_C(      9545),
           INT16_C(      9300),  INT16_C(      1882), -INT16_C(      2439),  INT16_C(      4037) },
       {   INT16_C(         3), -INT16_C(      2248),  INT16_C(      1570), -INT16_C(       404),
          -INT16_C(       662), -INT16_C(      7109), -INT16_C(      7322),  INT16_C(      4903)},
           INT8_C(         5),
       {   INT32_C( 439323270), -INT32_C( 810687717), -INT32_C( 901199062), -INT32_C(  16659039) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x4_t a = simde_vld1q_s32(test_vec[i].a);
    simde_int16x8_t b = simde_vld1q_s16(test_vec[i].b);
    simde_int16x8_t v = simde_vld1q_s16(test_vec[i].v);
    simde_int32x4_t r;
    SIMDE_CONSTIFY_8_(simde_vqdmlsl_high_laneq_s16, r, (HEDLEY_UNREACHABLE(), r), test_vec[i].lane, a, b, v);

    simde_test_arm_neon_assert_equal_i32x4(r, simde_vld1q_s32(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vqdmlsl_high_laneq_s32 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    int64_t a[2];
    int32_t b[4];
    int32_t v[4];
    int8_t lane;
    int64_t r[2];
  } test_vec[] = {
     { {   INT64_C(  790453197700),  INT64_C(  961966501875) },
       {  -INT32_C(        242762),  INT32_C(        150897), -INT32_C(        329656),  INT32_C(        660855) },
       {   INT32_C(        395325),  INT32_C(        901629),  INT32_C(        925388),  INT32_C(        858125)},
           INT8_C(             3),
       {   INT64_C( 1356225307700), -INT64_C(  172225891875) } },
     { {   INT64_C(  849068137006),  INT64_C(  549844025749) },
       {  -INT32_C(        246423), -INT32_C(        830627),  INT32_C(        769223),  INT32_C(        785424) },
       {  -INT32_C(        831951),  INT32_C(        945136),  INT32_C(        341523), -INT32_C(        325349)},
           INT8_C(             2),
       {   INT64_C(  323653443748),  INT64_C(   13363304245) } },
     { {  -INT64_C(  277194980408),  INT64_C(  942116532917) },
       {  -INT32_C(        817506),  INT32_C(        354593), -INT32_C(        665530),  INT32_C(        564673) },
       {  -INT32_C(        621727), -INT32_C(        543692),  INT32_C(        238057), -INT32_C(        232370)},
           INT8_C(             3),
       {  -INT64_C(  586493392608),  INT64_C( 1204542662937) } },
     { {   INT64_C(  604790769746),  INT64_C(  204872498322) },
       {  -INT32_C(        983351),  INT32_C(        745045),  INT32_C(        414096), -INT32_C(        956641) },
       {  -INT32_C(        873296), -INT32_C(        180336),  INT32_C(        394178), -INT32_C(        507014)},
           INT8_C(             1),
       {   INT64_C(  754143602258), -INT64_C(  140161124430) } },
     { {   INT64_C(  553446037926), -INT64_C(  431114272015) },
       {   INT32_C(        960473),  INT32_C(        562842), -INT32_C(        219505),  INT32_C(        667766) },
       {  -INT32_C(        138937), -INT32_C(        552203), -INT32_C(        523153),  INT32_C(        246820)},
           INT8_C(             1),
       {   INT64_C(  311023398896),  INT64_C(  306370504981) } },
     { {   INT64_C(  541441643880),  INT64_C(  713931659611) },
       {   INT32_C(        987082),  INT32_C(        822929),  INT32_C(        919119),  INT32_C(        971988) },
       {  -INT32_C(        609984), -INT32_C(        925110),  INT32_C(        821157),  INT32_C(        173498)},
           INT8_C(             3),
       {   INT64_C(  222511027356),  INT64_C(  376655711563) } },
     { {   INT64_C(  816569519115),  INT64_C(  970025023207) },
       {   INT32_C(        303874), -INT32_C(        715866), -INT32_C(        487220),  INT32_C(         61968) },
       {   INT32_C(         89628),  INT32_C(        361735),  INT32_C(        443557), -INT32_C(        149088)},
           INT8_C(             0),
       {   INT64_C(  903906627435),  INT64_C(  958916887399) } },
     { {   INT64_C(  771564280879), -INT64_C(  493898875902) },
       {  -INT32_C(        659961),  INT32_C(        859353), -INT32_C(        225375), -INT32_C(        564812) },
       {  -INT32_C(        515031),  INT32_C(        410037), -INT32_C(        630721), -INT32_C(        183181)},
           INT8_C(             2),
       {   INT64_C(  487266790129), -INT64_C( 1206376454806) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int64x2_t a = simde_vld1q_s64(test_vec[i].a);
    simde_int32x4_t b = simde_vld1q_s32(test_vec[i].b);
    simde_int32x4_t v = simde_vld1q_s32(test_vec[i].v);
    simde_int64x2_t r;
    SIMDE_CONSTIFY_4_(simde_vqdmlsl_high_laneq_s32, r, (HEDLEY_UNREACHABLE(), r), test_vec[i].lane, a, b, v);

    simde_test_arm_neon_assert_equal_i64x2(r, simde_vld1q_s64(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vqdmlsl_high_lane_s32 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    int64_t a[2];
    int32_t b[4];
    int32_t v[2];
    int8_t lane;
    int64_t r[2];
  } test_vec[] = {
     { {  -INT64_C(  446900198398), -INT64_C(  329881688649) },
       {   INT32_C(        974292), -INT32_C(        655559),  INT32_C(        171874),  INT32_C(        238794) },
       {   INT32_C(         13385), -INT32_C(        765431)},
           INT8_C(             0),
       {  -INT64_C(  451501265378), -INT64_C(  336274204029) } },
     { {  -INT64_C(  140891827426),  INT64_C(  381859766505) },
       {   INT32_C(        740832), -INT32_C(        598547),  INT32_C(        834175),  INT32_C(         79386) },
       {  -INT32_C(        193689), -INT32_C(        869124)},
           INT8_C(             1),
       {   INT64_C( 1309111197974),  INT64_C(  519852322233) } },
     { {  -INT64_C(   53296665764), -INT64_C(  704121513624) },
       {   INT32_C(          9898), -INT32_C(        171625),  INT32_C(        725625),  INT32_C(        204408) },
       {  -INT32_C(        229616), -INT32_C(        351235)},
           INT8_C(             0),
       {   INT64_C(  279933554236), -INT64_C(  610250818968) } },
     { {  -INT64_C(  116940462675),  INT64_C(  381748739822) },
       {   INT32_C(        593056), -INT32_C(         54191),  INT32_C(        428212), -INT32_C(        261544) },
       {  -INT32_C(        116854),  INT32_C(         13856)},
           INT8_C(             1),
       {  -INT64_C(  128807073619),  INT64_C(  388996647150) } },
     { {   INT64_C(  222385528219),  INT64_C(   43492618314) },
       {  -INT32_C(        383545),  INT32_C(         34688), -INT32_C(        843697), -INT32_C(         28956) },
       {   INT32_C(        305790), -INT32_C(        708575)},
           INT8_C(             1),
       {  -INT64_C(  973259675331),  INT64_C(    2457622914) } },
     { {   INT64_C(  886360405211),  INT64_C(  227244724453) },
       {  -INT32_C(        857821), -INT32_C(        985197), -INT32_C(        228703), -INT32_C(        790608) },
       {  -INT32_C(         42516),  INT32_C(        379665)},
           INT8_C(             1),
       {   INT64_C( 1060021454201),  INT64_C(  827577097093) } },
     { {   INT64_C(  513652570910),  INT64_C(    6598367959) },
       {  -INT32_C(        178555), -INT32_C(        468729),  INT32_C(        810266), -INT32_C(        620168) },
       {   INT32_C(        540665), -INT32_C(        177714)},
           INT8_C(             0),
       {  -INT64_C(  362512362870),  INT64_C(  677204631399) } },
     { {   INT64_C(  493154627538), -INT64_C(  534064624380) },
       {   INT32_C(        801415), -INT32_C(        734570),  INT32_C(        494571),  INT32_C(        423838) },
       {   INT32_C(        310134),  INT32_C(        105922)},
           INT8_C(             1),
       {   INT64_C(  388382728614), -INT64_C(  623852161652) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int64x2_t a = simde_vld1q_s64(test_vec[i].a);
    simde_int32x4_t b = simde_vld1q_s32(test_vec[i].b);
    simde_int32x2_t v = simde_vld1_s32(test_vec[i].v);
    simde_int64x2_t r;
    SIMDE_CONSTIFY_2_(simde_vqdmlsl_high_lane_s32, r, (HEDLEY_UNREACHABLE(), r), test_vec[i].lane, a, b, v);

    simde_test_arm_neon_assert_equal_i64x2(r, simde_vld1q_s64(test_vec[i].r));
  }

  return 0;
}


SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(vqdmlsl_high_lane_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vqdmlsl_high_lane_s32)

SIMDE_TEST_FUNC_LIST_ENTRY(vqdmlsl_high_laneq_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vqdmlsl_high_laneq_s32)
SIMDE_TEST_FUNC_LIST_END

#include "test-neon-footer.h"
