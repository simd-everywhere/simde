#define SIMDE_TEST_ARM_NEON_INSN qdmlsl_high

#include "test-neon.h"
#include "../../../simde/arm/neon/qdmlsl_high.h"

static int
test_simde_vqdmlsl_high_s16 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    int32_t a[4];
    int16_t b[8];
    int16_t c[8];
    int32_t r[4];
  } test_vec[] = {
     { {  -INT32_C( 747885390),  INT32_C( 423110881), -INT32_C( 937077694), -INT32_C( 483181547) },
       {   INT16_C(      3292),  INT16_C(      8866), -INT16_C(      1582),  INT16_C(      8444),
           INT16_C(       223),  INT16_C(      6504),  INT16_C(      8252), -INT16_C(      5956) },
       {   INT16_C(       733), -INT16_C(      7182), -INT16_C(      9403), -INT16_C(      2116),
          -INT16_C(      6042), -INT16_C(      2530), -INT16_C(      7860),  INT16_C(      1453)},
       {  -INT32_C( 745190658),  INT32_C( 456021121), -INT32_C( 807356254), -INT32_C( 465873411) } },
     { {   INT32_C(  70925407),  INT32_C( 626232695), -INT32_C( 252554284),  INT32_C( 431103080) },
       {   INT16_C(      7119),  INT16_C(      5510), -INT16_C(      8082),  INT16_C(      5127),
          -INT16_C(      9975),  INT16_C(      2746),  INT16_C(      1268),  INT16_C(      2762) },
       {   INT16_C(       649), -INT16_C(      8763), -INT16_C(      4572),  INT16_C(      6117),
           INT16_C(      8432),  INT16_C(      4649),  INT16_C(      4030), -INT16_C(      2755)},
       {   INT32_C( 239143807),  INT32_C( 600700387), -INT32_C( 262774364),  INT32_C( 446321700) } },
     { {  -INT32_C( 536689326), -INT32_C( 139523788), -INT32_C( 125270464),  INT32_C( 873332710) },
       {  -INT16_C(      8122), -INT16_C(      7639),  INT16_C(      8362), -INT16_C(      1175),
           INT16_C(       447), -INT16_C(      8891), -INT16_C(      7641), -INT16_C(      1787) },
       {  -INT16_C(      6426),  INT16_C(      4090), -INT16_C(      5831), -INT16_C(      5382),
           INT16_C(      1335),  INT16_C(      3725),  INT16_C(      6097), -INT16_C(      3746)},
       {  -INT32_C( 537882816), -INT32_C(  73285838), -INT32_C(  32096110),  INT32_C( 859944506) } },
     { {   INT32_C( 901033376), -INT32_C( 849542112),  INT32_C( 141308212), -INT32_C( 801097465) },
       {   INT16_C(      8881), -INT16_C(      8697),  INT16_C(      8608), -INT16_C(      8131),
           INT16_C(      8520), -INT16_C(       663), -INT16_C(      1900), -INT16_C(       210) },
       {  -INT16_C(      9769),  INT16_C(      6187), -INT16_C(      6074), -INT16_C(      5166),
          -INT16_C(        17),  INT16_C(      9183),  INT16_C(        43),  INT16_C(      8961)},
       {   INT32_C( 901323056), -INT32_C( 837365454),  INT32_C( 141471612), -INT32_C( 797333845) } },
     { {  -INT32_C( 744968491),  INT32_C( 963308292), -INT32_C( 201343108), -INT32_C( 536196437) },
       {   INT16_C(      9912),  INT16_C(      6082), -INT16_C(      1482),  INT16_C(      5248),
           INT16_C(      8622), -INT16_C(      2872), -INT16_C(      5619),  INT16_C(      3797) },
       {   INT16_C(      3860),  INT16_C(      9854),  INT16_C(      1259),  INT16_C(      2424),
           INT16_C(      5041), -INT16_C(      9041), -INT16_C(      5325),  INT16_C(      2802)},
       {  -INT32_C( 831895495),  INT32_C( 911376788), -INT32_C( 261185458), -INT32_C( 557474825) } },
     { {  -INT32_C( 147095240), -INT32_C( 382346379), -INT32_C( 200297616),  INT32_C( 248079928) },
       {   INT16_C(      5753),  INT16_C(      1550),  INT16_C(      6057),  INT16_C(      8103),
          -INT16_C(      3757), -INT16_C(       588), -INT16_C(      6897),  INT16_C(      2868) },
       {  -INT16_C(      6337), -INT16_C(      2298), -INT16_C(      9346), -INT16_C(      1545),
          -INT16_C(      1912),  INT16_C(      4849), -INT16_C(      5850), -INT16_C(      4585)},
       {  -INT32_C( 161462008), -INT32_C( 376643955), -INT32_C( 280992516),  INT32_C( 274379488) } },
     { {   INT32_C( 847470746),  INT32_C( 739890236),  INT32_C( 605341917),  INT32_C( 394630673) },
       {   INT16_C(      7092), -INT16_C(       221), -INT16_C(      1527),  INT16_C(       652),
           INT16_C(      2190), -INT16_C(      4343), -INT16_C(        16),  INT16_C(      9776) },
       {  -INT16_C(      7960), -INT16_C(      2053), -INT16_C(      3342), -INT16_C(      8317),
           INT16_C(      9714),  INT16_C(      6319),  INT16_C(      2207), -INT16_C(      6524)},
       {   INT32_C( 804923426),  INT32_C( 794777070),  INT32_C( 605412541),  INT32_C( 522187921) } },
     { {  -INT32_C( 351695750), -INT32_C( 251638833), -INT32_C( 901741340), -INT32_C( 143936069) },
       {   INT16_C(      6687),  INT16_C(      8399),  INT16_C(      7245), -INT16_C(      4786),
          -INT16_C(      1077), -INT16_C(      3605), -INT16_C(      9048),  INT16_C(      5699) },
       {  -INT16_C(      4202), -INT16_C(      2749),  INT16_C(      5485),  INT16_C(      6722),
           INT16_C(      2934),  INT16_C(      6380),  INT16_C(      6638), -INT16_C(      8437)},
       {  -INT32_C( 345375914), -INT32_C( 205639033), -INT32_C( 781620092), -INT32_C(  47771143) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x4_t a = simde_vld1q_s32(test_vec[i].a);
    simde_int16x8_t b = simde_vld1q_s16(test_vec[i].b);
    simde_int16x8_t c = simde_vld1q_s16(test_vec[i].c);
    simde_int32x4_t r = simde_vqdmlsl_high_s16(a, b, c);

    simde_test_arm_neon_assert_equal_i32x4(r, simde_vld1q_s32(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vqdmlsl_high_s32 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    int64_t a[2];
    int32_t b[4];
    int32_t c[4];
    int64_t r[2];
  } test_vec[] = {
     { {   INT64_C(  253531438173), -INT64_C(  977771259694) },
       {   INT32_C(        986427), -INT32_C(        362413), -INT32_C(        849434), -INT32_C(        890362) },
       {  -INT32_C(         70267),  INT32_C(        699087),  INT32_C(        816843), -INT32_C(        995287)},
       {   INT64_C( 1641239871897), -INT64_C( 2750102707482) } },
     { {   INT64_C(  477194517593), -INT64_C(  330738868250) },
       {  -INT32_C(        402288),  INT32_C(        441145),  INT32_C(        243046), -INT32_C(        391873) },
       {  -INT32_C(        738110),  INT32_C(         85130), -INT32_C(        533651),  INT32_C(        381814)},
       {   INT64_C(  736597999485), -INT64_C(   31493673006) } },
     { {   INT64_C(  681338659209), -INT64_C(  933208547020) },
       {  -INT32_C(        718590),  INT32_C(         65023),  INT32_C(        152877), -INT32_C(         72901) },
       {  -INT32_C(          9606), -INT32_C(         60987), -INT32_C(        717749), -INT32_C(        625166)},
       {   INT64_C(  900793286955), -INT64_C( 1024359000152) } },
     { {   INT64_C(  972110347760),  INT64_C(  806873393212) },
       {  -INT32_C(        388297),  INT32_C(        455037), -INT32_C(        476932),  INT32_C(        132689) },
       {  -INT32_C(        870554),  INT32_C(        287811), -INT32_C(        989866), -INT32_C(        996621)},
       {   INT64_C(   27912805536),  INT64_C( 1071354680950) } },
     { {   INT64_C(  744227908851),  INT64_C(  217341748577) },
       {   INT32_C(        875192), -INT32_C(        451221), -INT32_C(        525998), -INT32_C(        403587) },
       {  -INT32_C(        261659),  INT32_C(        128275), -INT32_C(        618743),  INT32_C(        205123)},
       {   INT64_C(   93312747823),  INT64_C(  382911700979) } },
     { {  -INT64_C(   66370325823), -INT64_C(  749746646109) },
       {  -INT32_C(        636526),  INT32_C(        370816), -INT32_C(        800610),  INT32_C(        351071) },
       {  -INT32_C(        793821),  INT32_C(        254667),  INT32_C(        481345),  INT32_C(        224270)},
       {   INT64_C(  704368915077), -INT64_C(  907216032449) } },
     { {  -INT64_C(  246022628638), -INT64_C(  485535234684) },
       {   INT32_C(        417350), -INT32_C(        297899),  INT32_C(        120115), -INT32_C(        523418) },
       {   INT32_C(        402583), -INT32_C(        423284),  INT32_C(        751713), -INT32_C(        207976)},
       {  -INT64_C(  426606642628), -INT64_C(  703251998620) } },
     { {  -INT64_C(  737734691398),  INT64_C(  257791861690) },
       {  -INT32_C(          3312),  INT32_C(        750732),  INT32_C(        965480), -INT32_C(        996117) },
       {   INT32_C(        256052),  INT32_C(        522416),  INT32_C(        150123), -INT32_C(        381846)},
       {  -INT64_C( 1027616199478), -INT64_C(  502934722274) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int64x2_t a = simde_vld1q_s64(test_vec[i].a);
    simde_int32x4_t b = simde_vld1q_s32(test_vec[i].b);
    simde_int32x4_t c = simde_vld1q_s32(test_vec[i].c);
    simde_int64x2_t r = simde_vqdmlsl_high_s32(a, b, c);

    simde_test_arm_neon_assert_equal_i64x2(r, simde_vld1q_s64(test_vec[i].r));
  }

  return 0;
}


SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(vqdmlsl_high_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vqdmlsl_high_s32)
SIMDE_TEST_FUNC_LIST_END

#include "test-neon-footer.h"
