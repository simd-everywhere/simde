#define SIMDE_TEST_ARM_NEON_INSN sm3

#include "test-neon.h"
#include "../../../simde/arm/neon/sm3.h"
#include "../../../simde/arm/neon/dup_n.h"

static int
test_simde_vsm3ss1q_u32(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint32_t a[4];
    uint32_t b[4];
    uint32_t c[4];
    uint32_t r[4];
  } test_vec[] = {
    { {  UINT32_C(  2467160086),  UINT32_C(  2937401564),  UINT32_C(  3646601807),  UINT32_C(  3568630537) },
      {  UINT32_C(  2715035934),  UINT32_C(  2347582019),  UINT32_C(   527895956),  UINT32_C(  1638258305) },
      {  UINT32_C(  3114055003),  UINT32_C(  2920650759),  UINT32_C(  2634414216),  UINT32_C(  2879056597) },
      {  UINT32_C(           0),  UINT32_C(           0),  UINT32_C(           0),  UINT32_C(  2024755374) } },
    { {  UINT32_C(  1835934806),  UINT32_C(   872880966),  UINT32_C(  2338226846),  UINT32_C(  1794229268) },
      {  UINT32_C(   903794420),  UINT32_C(  2214921052),  UINT32_C(  4015207373),  UINT32_C(  1054688102) },
      {  UINT32_C(  1730767990),  UINT32_C(  2956790966),  UINT32_C(  2892555238),  UINT32_C(  2655704746) },
      {  UINT32_C(           0),  UINT32_C(           0),  UINT32_C(           0),  UINT32_C(  3031457788) } },
    { {  UINT32_C(  2600844233),  UINT32_C(   276317252),  UINT32_C(   630183936),  UINT32_C(  3884690759) },
      {  UINT32_C(  2651029784),  UINT32_C(  1494912358),  UINT32_C(  3645136412),  UINT32_C(   320432631) },
      {  UINT32_C(  3477620588),  UINT32_C(  2543094308),  UINT32_C(  3052706378),  UINT32_C(  2510386944) },
      {  UINT32_C(           0),  UINT32_C(           0),  UINT32_C(           0),  UINT32_C(  3350181809) } },
    { {  UINT32_C(  3903716374),  UINT32_C(  4213089290),  UINT32_C(  3111671400),  UINT32_C(  4210087046) },
      {  UINT32_C(   556790022),  UINT32_C(  1574525370),  UINT32_C(  2339226086),  UINT32_C(  1325513568) },
      {  UINT32_C(   849047984),  UINT32_C(   633761746),  UINT32_C(   297085722),  UINT32_C(   733553507) },
      {  UINT32_C(           0),  UINT32_C(           0),  UINT32_C(           0),  UINT32_C(    27736388) } },
    { {  UINT32_C(  1755191752),  UINT32_C(  3845212904),  UINT32_C(   212082875),  UINT32_C(  1076295032) },
      {  UINT32_C(  3353412083),  UINT32_C(  3922241042),  UINT32_C(  3817864679),  UINT32_C(  3772677066) },
      {  UINT32_C(  1128811710),  UINT32_C(  3396126059),  UINT32_C(   993011920),  UINT32_C(  3226097544) },
      {  UINT32_C(           0),  UINT32_C(           0),  UINT32_C(           0),  UINT32_C(  1076603400) } },
    { {  UINT32_C(  3638242519),  UINT32_C(  1797534915),  UINT32_C(  3792087455),  UINT32_C(   285800597) },
      {  UINT32_C(  1119415381),  UINT32_C(  3591722451),  UINT32_C(  2906409473),  UINT32_C(  1761295318) },
      {  UINT32_C(  1959579359),  UINT32_C(  2670896345),  UINT32_C(  3026681710),  UINT32_C(  1143819860) },
      {  UINT32_C(           0),  UINT32_C(           0),  UINT32_C(           0),  UINT32_C(  1491967262) } },
    { {  UINT32_C(  3916412577),  UINT32_C(  2031496481),  UINT32_C(  1963382577),  UINT32_C(   808163931) },
      {  UINT32_C(   118693776),  UINT32_C(  3905223906),  UINT32_C(  1872365469),  UINT32_C(     1280805) },
      {  UINT32_C(  1358728303),  UINT32_C(  3422479302),  UINT32_C(  4038699177),  UINT32_C(  1580125947) },
      {  UINT32_C(           0),  UINT32_C(           0),  UINT32_C(           0),  UINT32_C(  4094071051) } },
    { {  UINT32_C(  3295307601),  UINT32_C(   822354544),  UINT32_C(  2871318211),  UINT32_C(    25008038) },
      {  UINT32_C(  1032553310),  UINT32_C(  2733396299),  UINT32_C(  1473378675),  UINT32_C(  3234995783) },
      {  UINT32_C(  3969116792),  UINT32_C(  2664511226),  UINT32_C(  3431891407),  UINT32_C(  1781961050) },
      {  UINT32_C(           0),  UINT32_C(           0),  UINT32_C(           0),  UINT32_C(  1099422722) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint32x4_t a = simde_vld1q_u32(test_vec[i].a);
    simde_uint32x4_t b = simde_vld1q_u32(test_vec[i].b);
    simde_uint32x4_t c = simde_vld1q_u32(test_vec[i].c);
    simde_uint32x4_t r = simde_vsm3ss1q_u32(a, b, c);

    simde_test_arm_neon_assert_equal_u32x4(r, simde_vld1q_u32(test_vec[i].r));
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint32x4_t a = simde_test_arm_neon_random_u32x4();
    simde_uint32x4_t b = simde_test_arm_neon_random_u32x4();
    simde_uint32x4_t c = simde_test_arm_neon_random_u32x4();
    simde_uint32x4_t r = simde_vsm3ss1q_u32(a, b, c);

    simde_test_arm_neon_write_u32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x4(2, c, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vsm3tt1aq_u32(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint32_t a[4];
    uint32_t b[4];
    uint32_t c[4];
    int8_t imm2;
    uint32_t r[4];
  } test_vec[] = {
    { {  UINT32_C(  3435439798),  UINT32_C(  2725712570),  UINT32_C(  2327972803),  UINT32_C(  1377174980) },
      {  UINT32_C(  2653010253),  UINT32_C(  3457249407),  UINT32_C(   867411765),  UINT32_C(   886340882) },
      {  UINT32_C(  3981270505),  UINT32_C(  2234965346),  UINT32_C(   115521580),  UINT32_C(  1420996373) },
         INT8_C(     0),
      {  UINT32_C(  2725712570),  UINT32_C(  2216134421),  UINT32_C(  1377174980),  UINT32_C(  2302499215) } },
    { {  UINT32_C(  3091973830),  UINT32_C(  3428695133),  UINT32_C(  3294209094),  UINT32_C(   743192516) },
      {  UINT32_C(  1403188864),  UINT32_C(  3675649413),  UINT32_C(  2124784156),  UINT32_C(   779153587) },
      {  UINT32_C(  4148515954),  UINT32_C(  1400284468),  UINT32_C(  2052968180),  UINT32_C(  3543065172) },
         INT8_C(     3),
      {  UINT32_C(  3428695133),  UINT32_C(  3007876488),  UINT32_C(   743192516),  UINT32_C(  2630847344) } },
    { {  UINT32_C(  1343682152),  UINT32_C(   860483614),  UINT32_C(   781971942),  UINT32_C(  3657693800) },
      {  UINT32_C(  2343871207),  UINT32_C(  3798782186),  UINT32_C(  4194515665),  UINT32_C(  4070372224) },
      {  UINT32_C(  1518214166),  UINT32_C(   123736051),  UINT32_C(  3248206112),  UINT32_C(   263500338) },
         INT8_C(     3),
      {  UINT32_C(   860483614),  UINT32_C(   937675869),  UINT32_C(  3657693800),  UINT32_C(  4107805258) } },
    { {  UINT32_C(   702570973),  UINT32_C(  3671622150),  UINT32_C(  3423074365),  UINT32_C(  2728730727) },
      {  UINT32_C(  2653999274),  UINT32_C(  2755154833),  UINT32_C(  1801305088),  UINT32_C(  2578388496) },
      {  UINT32_C(  3911750703),  UINT32_C(   276845132),  UINT32_C(  2133990400),  UINT32_C(   790152254) },
         INT8_C(     2),
      {  UINT32_C(  3671622150),  UINT32_C(   267418520),  UINT32_C(  2728730727),  UINT32_C(   691422323) } },
    { {  UINT32_C(  3413622373),  UINT32_C(  3638119595),  UINT32_C(  1053302539),  UINT32_C(  2377552845) },
      {  UINT32_C(  2659865692),  UINT32_C(   591903453),  UINT32_C(  2566930488),  UINT32_C(  4084081383) },
      {  UINT32_C(  1407824945),  UINT32_C(   166167791),  UINT32_C(   166108415),  UINT32_C(  3965901194) },
         INT8_C(     3),
      {  UINT32_C(  3638119595),  UINT32_C(  2419988093),  UINT32_C(  2377552845),  UINT32_C(  3184874136) } },
    { {  UINT32_C(  1591213727),  UINT32_C(  3444919225),  UINT32_C(  4043141622),  UINT32_C(  2441499467) },
      {  UINT32_C(  1862959605),  UINT32_C(   681013981),  UINT32_C(  4179279218),  UINT32_C(  3825345159) },
      {  UINT32_C(  1107827447),  UINT32_C(  3715863536),  UINT32_C(  1782394393),  UINT32_C(   353628072) },
         INT8_C(     1),
      {  UINT32_C(  3444919225),  UINT32_C(  4209241569),  UINT32_C(  2441499467),  UINT32_C(  1773705010) } },
    { {  UINT32_C(  2498975294),  UINT32_C(  1063254476),  UINT32_C(  4148169278),  UINT32_C(  1362153630) },
      {  UINT32_C(  2027220820),  UINT32_C(   370138164),  UINT32_C(  1822776715),  UINT32_C(   235473403) },
      {  UINT32_C(  2388369321),  UINT32_C(  1470816294),  UINT32_C(  2112607005),  UINT32_C(  3219522443) },
         INT8_C(     0),
      {  UINT32_C(  1063254476),  UINT32_C(  2148826606),  UINT32_C(  1362153630),  UINT32_C(  3212772923) } },
    { {  UINT32_C(   564047958),  UINT32_C(  2827494743),  UINT32_C(  3426688152),  UINT32_C(  2764896778) },
      {  UINT32_C(  1191472462),  UINT32_C(  2321862044),  UINT32_C(  1370840113),  UINT32_C(  4193233315) },
      {  UINT32_C(  1634777041),  UINT32_C(  2662069130),  UINT32_C(  1155817663),  UINT32_C(  4191122541) },
         INT8_C(     0),
      {  UINT32_C(  2827494743),  UINT32_C(  2117677464),  UINT32_C(  2764896778),  UINT32_C(  2044342235) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint32x4_t a = simde_vld1q_u32(test_vec[i].a);
    simde_uint32x4_t b = simde_vld1q_u32(test_vec[i].b);
    simde_uint32x4_t c = simde_vld1q_u32(test_vec[i].c);
    simde_uint32x4_t r;
    SIMDE_CONSTIFY_4_(simde_vsm3tt1aq_u32, r, (HEDLEY_UNREACHABLE(), simde_vdupq_n_u32(UINT32_C(0))), test_vec[i].imm2, a, b, c);

    simde_test_arm_neon_assert_equal_u32x4(r, simde_vld1q_u32(test_vec[i].r));
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint32x4_t a = simde_test_arm_neon_random_u32x4();
    simde_uint32x4_t b = simde_test_arm_neon_random_u32x4();
    simde_uint32x4_t c = simde_test_arm_neon_random_u32x4();
    simde_int8_t imm2 = simde_test_codegen_random_i8();
    simde_uint32x4_t r = simde_vsm3tt1aq_u32(a, b, c, imm2);

    simde_test_arm_neon_write_u32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x4(2, c, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i8(2, imm2, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vsm3tt1bq_u32(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint32_t a[4];
    uint32_t b[4];
    uint32_t c[4];
    int8_t imm2;
    uint32_t r[4];
  } test_vec[] = {
    { {  UINT32_C(  1463473557),  UINT32_C(  2457222993),  UINT32_C(  1551945301),  UINT32_C(  3521537372) },
      {  UINT32_C(   332443221),  UINT32_C(  3430895446),  UINT32_C(  2720387155),  UINT32_C(  2375959725) },
      {  UINT32_C(   576089365),  UINT32_C(  3181234393),  UINT32_C(  4074984990),  UINT32_C(  3540668565) },
         INT8_C(     1),
      {  UINT32_C(  2457222993),  UINT32_C(    27044537),  UINT32_C(  3521537372),  UINT32_C(  3515520886) } },
    { {  UINT32_C(  1989453739),  UINT32_C(   512736216),  UINT32_C(  1488152698),  UINT32_C(   818264995) },
      {  UINT32_C(   185443477),  UINT32_C(  1772638157),  UINT32_C(  2397536108),  UINT32_C(   727825017) },
      {  UINT32_C(  1365222968),  UINT32_C(  2973270409),  UINT32_C(  1045708383),  UINT32_C(  1646052757) },
         INT8_C(     1),
      {  UINT32_C(   512736216),  UINT32_C(  1724970161),  UINT32_C(   818264995),  UINT32_C(  2972741283) } },
    { {  UINT32_C(  1068929635),  UINT32_C(  2807182787),  UINT32_C(  3773036078),  UINT32_C(  3311627134) },
      {  UINT32_C(   716574731),  UINT32_C(  2937533595),  UINT32_C(   403942098),  UINT32_C(  2439289760) },
      {  UINT32_C(  1272755446),  UINT32_C(   800026713),  UINT32_C(  4094756202),  UINT32_C(  2715997830) },
         INT8_C(     3),
      {  UINT32_C(  2807182787),  UINT32_C(  3354156481),  UINT32_C(  3311627134),  UINT32_C(  1859147853) } },
    { {  UINT32_C(  3732164554),  UINT32_C(  2470668978),  UINT32_C(   118835764),  UINT32_C(  1011332226) },
      {  UINT32_C(   208780216),  UINT32_C(   644834969),  UINT32_C(  3632827614),  UINT32_C(  3738309122) },
      {  UINT32_C(  1187132290),  UINT32_C(   602035011),  UINT32_C(  4186393511),  UINT32_C(  2685264704) },
         INT8_C(     1),
      {  UINT32_C(  2470668978),  UINT32_C(   714369038),  UINT32_C(  1011332226),  UINT32_C(  3208134533) } },
    { {  UINT32_C(  4292326561),  UINT32_C(  2592816541),  UINT32_C(   664576161),  UINT32_C(  1290766669) },
      {  UINT32_C(   805262738),  UINT32_C(  4163215469),  UINT32_C(  3802566038),  UINT32_C(  1954738491) },
      {  UINT32_C(   743814560),  UINT32_C(  2841324419),  UINT32_C(  1944140036),  UINT32_C(  1546309760) },
         INT8_C(     2),
      {  UINT32_C(  2592816541),  UINT32_C(   960578127),  UINT32_C(  1290766669),  UINT32_C(   241089831) } },
    { {  UINT32_C(  4045484238),  UINT32_C(   125586284),  UINT32_C(  2127542944),  UINT32_C(    34830764) },
      {  UINT32_C(   486197888),  UINT32_C(  2410100934),  UINT32_C(  1723778386),  UINT32_C(  3562800703) },
      {  UINT32_C(   360417813),  UINT32_C(    34803765),  UINT32_C(   984350836),  UINT32_C(  3653203809) },
         INT8_C(     3),
      {  UINT32_C(   125586284),  UINT32_C(  2675261693),  UINT32_C(    34830764),  UINT32_C(  3037129209) } },
    { {  UINT32_C(   636938698),  UINT32_C(  4078147522),  UINT32_C(  3961131690),  UINT32_C(   991733666) },
      {  UINT32_C(   852867804),  UINT32_C(  2739803610),  UINT32_C(  2906482642),  UINT32_C(    46285564) },
      {  UINT32_C(  3398887630),  UINT32_C(  2849990306),  UINT32_C(  2257447656),  UINT32_C(  3889208184) },
         INT8_C(     0),
      {  UINT32_C(  4078147522),  UINT32_C(   874862040),  UINT32_C(   991733666),  UINT32_C(  3026242439) } },
    { {  UINT32_C(   957570899),  UINT32_C(  1264892819),  UINT32_C(  2076135238),  UINT32_C(  2206157449) },
      {  UINT32_C(  2478562835),  UINT32_C(  4095018559),  UINT32_C(  1725499653),  UINT32_C(  2217392642) },
      {  UINT32_C(   324748777),  UINT32_C(  2792026650),  UINT32_C(  2764636797),  UINT32_C(  2575680016) },
         INT8_C(     2),
      {  UINT32_C(  1264892819),  UINT32_C(  2124319991),  UINT32_C(  2206157449),  UINT32_C(  2581450632) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint32x4_t a = simde_vld1q_u32(test_vec[i].a);
    simde_uint32x4_t b = simde_vld1q_u32(test_vec[i].b);
    simde_uint32x4_t c = simde_vld1q_u32(test_vec[i].c);
    simde_uint32x4_t r;
    SIMDE_CONSTIFY_4_(simde_vsm3tt1bq_u32, r, (HEDLEY_UNREACHABLE(), simde_vdupq_n_u32(UINT32_C(0))), test_vec[i].imm2, a, b, c);

    simde_test_arm_neon_assert_equal_u32x4(r, simde_vld1q_u32(test_vec[i].r));
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint32x4_t a = simde_test_arm_neon_random_u32x4();
    simde_uint32x4_t b = simde_test_arm_neon_random_u32x4();
    simde_uint32x4_t c = simde_test_arm_neon_random_u32x4();
    simde_int8_t imm2 = simde_test_codegen_random_i8();
    simde_uint32x4_t r = simde_vsm3tt1bq_u32(SIMDE_MUNIT_TEST_ARGS)(a, b, c, imm2);

    simde_test_arm_neon_write_u32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x4(2, c, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i8(2, imm2, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vsm3tt2aq_u32(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint32_t a[4];
    uint32_t b[4];
    uint32_t c[4];
    int8_t imm2;
    uint32_t r[4];
  } test_vec[] = {
    { {  UINT32_C(  1933898032),  UINT32_C(  3966303365),  UINT32_C(  1496659246),  UINT32_C(  1428939853) },
      {  UINT32_C(    79630859),  UINT32_C(  3621793602),  UINT32_C(  3352785975),  UINT32_C(  3937629792) },
      {  UINT32_C(  4152851181),  UINT32_C(  1086982762),  UINT32_C(   804101723),  UINT32_C(  2797194367) },
         INT8_C(     3),
      {  UINT32_C(  3966303365),  UINT32_C(  2842872233),  UINT32_C(  1428939853),  UINT32_C(  1979727983) } },
    { {  UINT32_C(  1955194533),  UINT32_C(  2008219165),  UINT32_C(  1554155055),  UINT32_C(  3360001891) },
      {  UINT32_C(  1285705438),  UINT32_C(  2686868345),  UINT32_C(  2154532425),  UINT32_C(  3003687853) },
      {  UINT32_C(  1054037484),  UINT32_C(  2334135289),  UINT32_C(  1212465639),  UINT32_C(   482884546) },
         INT8_C(     1),
      {  UINT32_C(  2008219165),  UINT32_C(   830137620),  UINT32_C(  3360001891),  UINT32_C(  2887418017) } },
    { {  UINT32_C(  2398473520),  UINT32_C(  1527092732),  UINT32_C(   714683605),  UINT32_C(   974375900) },
      {  UINT32_C(   708211166),  UINT32_C(  1416263468),  UINT32_C(   509448755),  UINT32_C(  1217922524) },
      {  UINT32_C(   355589990),  UINT32_C(  3475720705),  UINT32_C(  2782356414),  UINT32_C(  1136816297) },
         INT8_C(     3),
      {  UINT32_C(  1527092732),  UINT32_C(  2796115145),  UINT32_C(   974375900),  UINT32_C(  2228631512) } },
    { {  UINT32_C(  2711606642),  UINT32_C(   670354033),  UINT32_C(  2303517232),  UINT32_C(   795494843) },
      {  UINT32_C(  2143401161),  UINT32_C(  1025291187),  UINT32_C(  3332766479),  UINT32_C(  4181453469) },
      {  UINT32_C(  2698195460),  UINT32_C(  3499509872),  UINT32_C(  2161354492),  UINT32_C(  3057073627) },
         INT8_C(     0),
      {  UINT32_C(   670354033),  UINT32_C(   293882471),  UINT32_C(   795494843),  UINT32_C(   389166196) } },
    { {  UINT32_C(  1794007042),  UINT32_C(  1708396165),  UINT32_C(  3133726287),  UINT32_C(  1963435185) },
      {  UINT32_C(  3683899908),  UINT32_C(  2304564546),  UINT32_C(  2279453732),  UINT32_C(  3543424982) },
      {  UINT32_C(  1828598226),  UINT32_C(  2654722788),  UINT32_C(  2157773132),  UINT32_C(  2139016705) },
         INT8_C(     3),
      {  UINT32_C(  1708396165),  UINT32_C(  4068333126),  UINT32_C(  1963435185),  UINT32_C(   420570593) } },
    { {  UINT32_C(  2532020590),  UINT32_C(   813344361),  UINT32_C(  2623388325),  UINT32_C(   105694361) },
      {  UINT32_C(  1273504213),  UINT32_C(   949587222),  UINT32_C(  2428025097),  UINT32_C(  1794258850) },
      {  UINT32_C(   754818040),  UINT32_C(  2312453316),  UINT32_C(  2277542453),  UINT32_C(  3233585864) },
         INT8_C(     2),
      {  UINT32_C(   813344361),  UINT32_C(  3576488685),  UINT32_C(   105694361),  UINT32_C(  2003400678) } },
    { {  UINT32_C(  1760572777),  UINT32_C(  1758069305),  UINT32_C(  2428951556),  UINT32_C(   363815822) },
      {  UINT32_C(  1782785222),  UINT32_C(  2354315727),  UINT32_C(  3476432341),  UINT32_C(   405225649) },
      {  UINT32_C(  2943912654),  UINT32_C(  1837686997),  UINT32_C(  3915360821),  UINT32_C(  1396292072) },
         INT8_C(     1),
      {  UINT32_C(  1758069305),  UINT32_C(  3760490038),  UINT32_C(   363815822),  UINT32_C(  2099833234) } },
    { {  UINT32_C(  3034257454),  UINT32_C(  1921205753),  UINT32_C(   685287472),  UINT32_C(  2836168580) },
      {  UINT32_C(  1089579218),  UINT32_C(  2035391846),  UINT32_C(    46812989),  UINT32_C(  3512584282) },
      {  UINT32_C(  2932098262),  UINT32_C(  2661906010),  UINT32_C(   800959976),  UINT32_C(  1993474595) },
         INT8_C(     1),
      {  UINT32_C(  1921205753),  UINT32_C(  1098991301),  UINT32_C(  2836168580),  UINT32_C(  3115681644) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint32x4_t a = simde_vld1q_u32(test_vec[i].a);
    simde_uint32x4_t b = simde_vld1q_u32(test_vec[i].b);
    simde_uint32x4_t c = simde_vld1q_u32(test_vec[i].c);
    simde_uint32x4_t r;
    SIMDE_CONSTIFY_4_(simde_vsm3tt2aq_u32, r, (HEDLEY_UNREACHABLE(), simde_vdupq_n_u32(UINT32_C(0))), test_vec[i].imm2, a, b, c);

    simde_test_arm_neon_assert_equal_u32x4(r, simde_vld1q_u32(test_vec[i].r));
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint32x4_t a = simde_test_arm_neon_random_u32x4();
    simde_uint32x4_t b = simde_test_arm_neon_random_u32x4();
    simde_uint32x4_t c = simde_test_arm_neon_random_u32x4();
    simde_int8_t imm2 = simde_test_codegen_random_i8();
    simde_uint32x4_t r = simde_vsm3tt2aq_u32(SIMDE_MUNIT_TEST_ARGS)(a, b, c, imm2);

    simde_test_arm_neon_write_u32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x4(2, c, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i8(2, imm2, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vsm3tt2bq_u32(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint32_t a[4];
    uint32_t b[4];
    uint32_t c[4];
    int8_t imm2;
    uint32_t r[4];
  } test_vec[] = {
    { {  UINT32_C(  4094606764),  UINT32_C(  2929278612),  UINT32_C(  3209385054),  UINT32_C(  2117614009) },
      {  UINT32_C(  1422708782),  UINT32_C(  1751622858),  UINT32_C(  2388456917),  UINT32_C(    48362771) },
      {  UINT32_C(  2396740808),  UINT32_C(  1885786825),  UINT32_C(  2287271072),  UINT32_C(  3461761994) },
         INT8_C(     3),
      {  UINT32_C(  2929278612),  UINT32_C(  2734029402),  UINT32_C(  2117614009),  UINT32_C(   179460098) } },
    { {  UINT32_C(  3215619088),  UINT32_C(   384435287),  UINT32_C(  3662230670),  UINT32_C(  3779893980) },
      {  UINT32_C(   581927001),  UINT32_C(  3113604090),  UINT32_C(  1968737110),  UINT32_C(  2565970316) },
      {  UINT32_C(  3940111015),  UINT32_C(  3161413654),  UINT32_C(  1734199227),  UINT32_C(  2219430198) },
         INT8_C(     0),
      {  UINT32_C(   384435287),  UINT32_C(  2759250505),  UINT32_C(  3779893980),  UINT32_C(  1293083736) } },
    { {  UINT32_C(  2937254009),  UINT32_C(  1818370243),  UINT32_C(  1387602498),  UINT32_C(  1282106161) },
      {  UINT32_C(  1754609950),  UINT32_C(  3016929266),  UINT32_C(  4259928878),  UINT32_C(   410039022) },
      {  UINT32_C(   684597152),  UINT32_C(  3120243830),  UINT32_C(   514339949),  UINT32_C(  3656247519) },
         INT8_C(     2),
      {  UINT32_C(  1818370243),  UINT32_C(   303207849),  UINT32_C(  1282106161),  UINT32_C(   714431107) } },
    { {  UINT32_C(  3098855563),  UINT32_C(  2766446702),  UINT32_C(   916322379),  UINT32_C(    23506051) },
      {  UINT32_C(  3402253445),  UINT32_C(  2875885178),  UINT32_C(  4115962182),  UINT32_C(  3733735345) },
      {  UINT32_C(  3361269932),  UINT32_C(  1887864118),  UINT32_C(  3640667997),  UINT32_C(  2054377148) },
         INT8_C(     1),
      {  UINT32_C(  2766446702),  UINT32_C(  3260658927),  UINT32_C(    23506051),  UINT32_C(  1341433377) } },
    { {  UINT32_C(  3053242841),  UINT32_C(  1021893094),  UINT32_C(  2806152334),  UINT32_C(  1255761077) },
      {  UINT32_C(  2486525652),  UINT32_C(   122633061),  UINT32_C(  1170567808),  UINT32_C(  3985079891) },
      {  UINT32_C(  2867573393),  UINT32_C(  1200008626),  UINT32_C(  1057842848),  UINT32_C(  4103139306) },
         INT8_C(     2),
      {  UINT32_C(  1021893094),  UINT32_C(  3832887827),  UINT32_C(  1255761077),  UINT32_C(  2760882502) } },
    { {  UINT32_C(   701201299),  UINT32_C(   553767706),  UINT32_C(  3881835218),  UINT32_C(   298476366) },
      {  UINT32_C(   535803690),  UINT32_C(   372924884),  UINT32_C(  2835510627),  UINT32_C(  1398745923) },
      {  UINT32_C(  4064074664),  UINT32_C(   220951108),  UINT32_C(  1158204292),  UINT32_C(   272833929) },
         INT8_C(     1),
      {  UINT32_C(   553767706),  UINT32_C(  3600235264),  UINT32_C(   298476366),  UINT32_C(  3524797716) } },
    { {  UINT32_C(   736745498),  UINT32_C(   437878321),  UINT32_C(  3947350637),  UINT32_C(  3425133579) },
      {  UINT32_C(  3007863579),  UINT32_C(  2379499913),  UINT32_C(  1102008462),  UINT32_C(  1778348452) },
      {  UINT32_C(  2877123473),  UINT32_C(  1088429594),  UINT32_C(  3936032408),  UINT32_C(   480101296) },
         INT8_C(     1),
      {  UINT32_C(   437878321),  UINT32_C(  1399806526),  UINT32_C(  3425133579),  UINT32_C(  3847192737) } },
    { {  UINT32_C(  1335290636),  UINT32_C(  2912444970),  UINT32_C(  2264367015),  UINT32_C(  4207286204) },
      {  UINT32_C(  3247907552),  UINT32_C(   600834620),  UINT32_C(  3805747562),  UINT32_C(  1533482407) },
      {  UINT32_C(  2101354772),  UINT32_C(   145366039),  UINT32_C(  4035674258),  UINT32_C(  2133981285) },
         INT8_C(     3),
      {  UINT32_C(  2912444970),  UINT32_C(  4248582075),  UINT32_C(  4207286204),  UINT32_C(  1334995398) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint32x4_t a = simde_vld1q_u32(test_vec[i].a);
    simde_uint32x4_t b = simde_vld1q_u32(test_vec[i].b);
    simde_uint32x4_t c = simde_vld1q_u32(test_vec[i].c);
    simde_uint32x4_t r;
    SIMDE_CONSTIFY_4_(simde_vsm3tt2bq_u32, r, (HEDLEY_UNREACHABLE(), simde_vdupq_n_u32(UINT32_C(0))), test_vec[i].imm2, a, b, c);

    simde_test_arm_neon_assert_equal_u32x4(r, simde_vld1q_u32(test_vec[i].r));
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint32x4_t a = simde_test_arm_neon_random_u32x4();
    simde_uint32x4_t b = simde_test_arm_neon_random_u32x4();
    simde_uint32x4_t c = simde_test_arm_neon_random_u32x4();
    simde_int8_t imm2 = simde_test_codegen_random_i8();
    simde_uint32x4_t r = simde_vsm3tt2bq_u32(SIMDE_MUNIT_TEST_ARGS)(a, b, c, imm2);

    simde_test_arm_neon_write_u32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x4(2, c, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i8(2, imm2, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vsm3partw1q_u32(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint32_t a[4];
    uint32_t b[4];
    uint32_t c[4];
    uint32_t r[4];
  } test_vec[] = {
    { {  UINT32_C(  2943077473),  UINT32_C(  1613759458),  UINT32_C(   119589728),  UINT32_C(  1917378713) },
      {  UINT32_C(  3854172322),  UINT32_C(   844094794),  UINT32_C(  2580926185),  UINT32_C(  1411591183) },
      {  UINT32_C(  2033556844),  UINT32_C(  3707457751),  UINT32_C(  2730419433),  UINT32_C(  1421013055) },
      {  UINT32_C(  2895384306),  UINT32_C(  1549834869),  UINT32_C(  1500621298),  UINT32_C(    40633112) } },
    { {  UINT32_C(  2759889967),  UINT32_C(  2112749211),  UINT32_C(  2437885110),  UINT32_C(  4090633421) },
      {  UINT32_C(  4142953023),  UINT32_C(  1171870907),  UINT32_C(  3069094978),  UINT32_C(  1124702896) },
      {  UINT32_C(  1848517232),  UINT32_C(  1192057724),  UINT32_C(  3446425153),  UINT32_C(  3453554446) },
      {  UINT32_C(  1450859795),  UINT32_C(  1985137466),  UINT32_C(  3749356920),  UINT32_C(   683494271) } },
    { {  UINT32_C(  1860518553),  UINT32_C(  1937270540),  UINT32_C(  3237162170),  UINT32_C(  1827696923) },
      {  UINT32_C(   658267168),  UINT32_C(  3302268070),  UINT32_C(   141000390),  UINT32_C(   534889940) },
      {  UINT32_C(  3505008629),  UINT32_C(   748020405),  UINT32_C(  2577653833),  UINT32_C(  2674835400) },
      {  UINT32_C(    86381942),  UINT32_C(  3784724644),  UINT32_C(  2086563453),  UINT32_C(   213409746) } },
    { {  UINT32_C(  4277458396),  UINT32_C(  4131997696),  UINT32_C(  2355715839),  UINT32_C(  2364041488) },
      {  UINT32_C(  3637421310),  UINT32_C(   217579910),  UINT32_C(  3696158072),  UINT32_C(  3047564028) },
      {  UINT32_C(  1579950247),  UINT32_C(  2442369272),  UINT32_C(  2014592432),  UINT32_C(  1498223075) },
      {  UINT32_C(    54980564),  UINT32_C(  2564633346),  UINT32_C(  1135251521),  UINT32_C(  1277476664) } },
    { {  UINT32_C(   561755364),  UINT32_C(  2528565600),  UINT32_C(   827910661),  UINT32_C(  2461105193) },
      {  UINT32_C(  2279923195),  UINT32_C(  1889322783),  UINT32_C(  3717566806),  UINT32_C(  4289058055) },
      {  UINT32_C(   753479978),  UINT32_C(  2144117817),  UINT32_C(   455946721),  UINT32_C(   171538698) },
      {  UINT32_C(  1661300051),  UINT32_C(  3281076685),  UINT32_C(  1221063252),  UINT32_C(    25603070) } },
    { {  UINT32_C(  3821070602),  UINT32_C(  4083554902),  UINT32_C(  1644086583),  UINT32_C(  2574016329) },
      {  UINT32_C(  1775350850),  UINT32_C(  3124947399),  UINT32_C(   536742928),  UINT32_C(  3352730484) },
      {  UINT32_C(  3292058646),  UINT32_C(  4145007219),  UINT32_C(  2177066660),  UINT32_C(   621476265) },
      {  UINT32_C(  1543013640),  UINT32_C(   464778514),  UINT32_C(  4261687525),  UINT32_C(  2286975146) } },
    { {  UINT32_C(  1983890788),  UINT32_C(  1309619334),  UINT32_C(  3597639676),  UINT32_C(  3370139002) },
      {  UINT32_C(   743079533),  UINT32_C(  3270008931),  UINT32_C(  1769635327),  UINT32_C(   277184433) },
      {  UINT32_C(  2708703527),  UINT32_C(  2517067909),  UINT32_C(  2666888863),  UINT32_C(  2347128373) },
      {  UINT32_C(  1397038249),  UINT32_C(  2986268166),  UINT32_C(  4290603620),  UINT32_C(   388913284) } },
    { {  UINT32_C(  1858232319),  UINT32_C(  3175565694),  UINT32_C(   396176997),  UINT32_C(  4261658375) },
      {  UINT32_C(  2329745975),  UINT32_C(   571260520),  UINT32_C(  3182245906),  UINT32_C(  2918387558) },
      {  UINT32_C(  1577836053),  UINT32_C(   854523245),  UINT32_C(  2641151024),  UINT32_C(  3676448713) },
      {  UINT32_C(   725304581),  UINT32_C(  4059918037),  UINT32_C(   930827633),  UINT32_C(   502588503) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint32x4_t a = simde_vld1q_u32(test_vec[i].a);
    simde_uint32x4_t b = simde_vld1q_u32(test_vec[i].b);
    simde_uint32x4_t c = simde_vld1q_u32(test_vec[i].c);
    simde_uint32x4_t r = simde_vsm3partw1q_u32(a, b, c);

    simde_test_arm_neon_assert_equal_u32x4(r, simde_vld1q_u32(test_vec[i].r));
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint32x4_t a = simde_test_arm_neon_random_u32x4();
    simde_uint32x4_t b = simde_test_arm_neon_random_u32x4();
    simde_uint32x4_t c = simde_test_arm_neon_random_u32x4();
    simde_uint32x4_t r = simde_vsm3partw1q_u32(SIMDE_MUNIT_TEST_ARGS)(a, b, c);

    simde_test_arm_neon_write_u32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x4(2, c, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vsm3partw2q_u32(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint32_t a[4];
    uint32_t b[4];
    uint32_t c[4];
    uint32_t r[4];
  } test_vec[] = {
    { {  UINT32_C(  3870421994),  UINT32_C(  3380964908),  UINT32_C(  3934733586),  UINT32_C(  1730741311) },
      {  UINT32_C(   186876800),  UINT32_C(  3421989335),  UINT32_C(   672739078),  UINT32_C(  1546945055) },
      {  UINT32_C(  1232482142),  UINT32_C(  3057967675),  UINT32_C(  3277604703),  UINT32_C(  2938853479) },
      {  UINT32_C(  1451614030),  UINT32_C(   537074208),  UINT32_C(  1824376309),  UINT32_C(  2581975016) } },
    { {  UINT32_C(  4112077229),  UINT32_C(  1756807725),  UINT32_C(  1680028097),  UINT32_C(  4252461402) },
      {  UINT32_C(   879236876),  UINT32_C(  2209612574),  UINT32_C(  1266297428),  UINT32_C(    70473363) },
      {  UINT32_C(  4092760278),  UINT32_C(  2511567452),  UINT32_C(  1058302540),  UINT32_C(  1961794152) },
      {  UINT32_C(   943271384),  UINT32_C(   851439481),  UINT32_C(  2775334282),  UINT32_C(  2338647821) } },
    { {  UINT32_C(  3528388927),  UINT32_C(   948360482),  UINT32_C(  3673324383),  UINT32_C(  1447000153) },
      {  UINT32_C(  1008549562),  UINT32_C(  1873061678),  UINT32_C(  4121600082),  UINT32_C(  1269457682) },
      {  UINT32_C(   453676127),  UINT32_C(    98083816),  UINT32_C(   577485520),  UINT32_C(  3525985784) },
      {  UINT32_C(  1796595720),  UINT32_C(  3144910350),  UINT32_C(   444969756),  UINT32_C(   952021548) } },
    { {  UINT32_C(  3641549566),  UINT32_C(  2080492448),  UINT32_C(  3057941089),  UINT32_C(  3911161287) },
      {  UINT32_C(  2180399502),  UINT32_C(  4229381825),  UINT32_C(   929797744),  UINT32_C(  2561213752) },
      {  UINT32_C(  2151848537),  UINT32_C(   206097078),  UINT32_C(  3856884986),  UINT32_C(  4275829998) },
      {  UINT32_C(  2042023856),  UINT32_C(  2759044711),  UINT32_C(  1889374563),  UINT32_C(   739917606) } },
    { {  UINT32_C(   600711038),  UINT32_C(  1246906207),  UINT32_C(  2320831267),  UINT32_C(  3250449363) },
      {  UINT32_C(   782598403),  UINT32_C(  3827415798),  UINT32_C(  1642732299),  UINT32_C(  1798882663) },
      {  UINT32_C(  3979661568),  UINT32_C(   716679746),  UINT32_C(  2035020601),  UINT32_C(   184135942) },
      {  UINT32_C(  2533563915),  UINT32_C(  4121353404),  UINT32_C(  1313248404),  UINT32_C(   143944423) } },
    { {  UINT32_C(  3073419870),  UINT32_C(   162122875),  UINT32_C(  3431067846),  UINT32_C(  3705270300) },
      {  UINT32_C(  3664601820),  UINT32_C(   772310247),  UINT32_C(  1424713529),  UINT32_C(   264362320) },
      {  UINT32_C(   443418843),  UINT32_C(  3806756248),  UINT32_C(  2232433123),  UINT32_C(  2822827703) },
      {  UINT32_C(  1515824399),  UINT32_C(  1419740397),  UINT32_C(   276194877),  UINT32_C(  1440617347) } },
    { {  UINT32_C(  3153233956),  UINT32_C(   920192978),  UINT32_C(  1846382428),  UINT32_C(  2738206724) },
      {  UINT32_C(  2860426196),  UINT32_C(  1456127280),  UINT32_C(   929690588),  UINT32_C(  3524375571) },
      {  UINT32_C(  2323095386),  UINT32_C(   834158713),  UINT32_C(  2013179353),  UINT32_C(  1277921605) },
      {  UINT32_C(   709068469),  UINT32_C(  3157493370),  UINT32_C(  2788331579),  UINT32_C(  3951526313) } },
    { {  UINT32_C(  2162700136),  UINT32_C(   205762082),  UINT32_C(  1197099455),  UINT32_C(  1846173952) },
      {  UINT32_C(  2220649137),  UINT32_C(  3890237801),  UINT32_C(  4196717335),  UINT32_C(  3024021538) },
      {  UINT32_C(  2375894234),  UINT32_C(  2612633069),  UINT32_C(  3706675443),  UINT32_C(  3731831777) },
      {  UINT32_C(  3390449823),  UINT32_C(   929892742),  UINT32_C(  3402556230),  UINT32_C(  2204934301) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint32x4_t a = simde_vld1q_u32(test_vec[i].a);
    simde_uint32x4_t b = simde_vld1q_u32(test_vec[i].b);
    simde_uint32x4_t c = simde_vld1q_u32(test_vec[i].c);
    simde_uint32x4_t r = simde_vsm3partw2q_u32(a, b, c);

    simde_test_arm_neon_assert_equal_u32x4(r, simde_vld1q_u32(test_vec[i].r));
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint32x4_t a = simde_test_arm_neon_random_u32x4();
    simde_uint32x4_t b = simde_test_arm_neon_random_u32x4();
    simde_uint32x4_t c = simde_test_arm_neon_random_u32x4();
    simde_uint32x4_t r = simde_vsm3partw2q_u32(SIMDE_MUNIT_TEST_ARGS)(a, b, c);

    simde_test_arm_neon_write_u32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x4(2, c, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(vsm3ss1q_u32)
SIMDE_TEST_FUNC_LIST_ENTRY(vsm3tt1aq_u32)
SIMDE_TEST_FUNC_LIST_ENTRY(vsm3tt1bq_u32)
SIMDE_TEST_FUNC_LIST_ENTRY(vsm3tt2aq_u32)
SIMDE_TEST_FUNC_LIST_ENTRY(vsm3tt2bq_u32)
SIMDE_TEST_FUNC_LIST_ENTRY(vsm3partw1q_u32)
SIMDE_TEST_FUNC_LIST_ENTRY(vsm3partw2q_u32)
SIMDE_TEST_FUNC_LIST_END

#include "test-neon-footer.h"
