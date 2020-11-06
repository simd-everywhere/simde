#define SIMDE_TEST_ARM_NEON_INSN mlsl_n

#include "test-neon.h"
#include "../../../simde/arm/neon/mlsl_n.h"

static int
test_simde_vmlsl_n_s16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int32_t a[8];
    int16_t b[8];
    int16_t c;
    int32_t r[8];
  } test_vec[] = {
    { {  INT32_C(    97116604),  INT32_C(  1553793811),  INT32_C(  2023811647),  INT32_C(   156946984) },
      { -INT16_C( 29600),  INT16_C( 21469), -INT16_C( 25494),  INT16_C( 24076) },
       INT16_C( 30465),
      {  INT32_C(   998880604),  INT32_C(   899740726), -INT32_C(  1494480939), -INT32_C(   576528356) } },
    { { -INT32_C(  1677353418),  INT32_C(   779993701),  INT32_C(  1680970183), -INT32_C(  1924238867) },
      {  INT16_C( 30441),  INT16_C( 17503), -INT16_C( 16257),  INT16_C( 23760) },
       INT16_C( 14867),
      { -INT32_C(  2129919765),  INT32_C(   519776600),  INT32_C(  1922663002),  INT32_C(  2017488509) } },
    { { -INT32_C(    90693384), -INT32_C(  1667707241), -INT32_C(   413205142),  INT32_C(  1551377707) },
      {  INT16_C( 25993), -INT16_C( 10291), -INT16_C( 18446),  INT16_C( 21069) },
      -INT16_C( 12805),
      {  INT32_C(   242146981), -INT32_C(  1799483496), -INT32_C(   649406172),  INT32_C(  1821166252) } },
    { {  INT32_C(   623495954), -INT32_C(  1656413691), -INT32_C(  1267999716), -INT32_C(   676211335) },
      { -INT16_C(  9028),  INT16_C( 13821), -INT16_C( 31176),  INT16_C(  1690) },
      -INT16_C( 29346),
      {  INT32_C(   358560266), -INT32_C(  1250822625),  INT32_C(  2112076684), -INT32_C(   626616595) } },
    { { -INT32_C(  1193301059), -INT32_C(  1568411272),  INT32_C(  1556383766), -INT32_C(  1875320795) },
      { -INT16_C( 20076),  INT16_C( 17765),  INT16_C(  8585), -INT16_C( 31199) },
       INT16_C( 22870),
      { -INT32_C(   734162939), -INT32_C(  1974696822),  INT32_C(  1360044816), -INT32_C(  1161799665) } },
    { {  INT32_C(  1784672524),  INT32_C(  1561730174),  INT32_C(  1464766164), -INT32_C(   186686416) },
      {  INT16_C(  1216), -INT16_C(  1580),  INT16_C( 26772), -INT16_C(  1622) },
       INT16_C( 13229),
      {  INT32_C(  1768586060),  INT32_C(  1582631994),  INT32_C(  1110599376), -INT32_C(   165228978) } },
    { {  INT32_C(  1908002331), -INT32_C(  2023569880),  INT32_C(  1185210416), -INT32_C(  1948944323) },
      {  INT16_C(  1488), -INT16_C( 20496), -INT16_C( 20230), -INT16_C( 12620) },
       INT16_C( 18601),
      {  INT32_C(  1880324043), -INT32_C(  1642323784),  INT32_C(  1561508646), -INT32_C(  1714199703) } },
    { { -INT32_C(   465415113),  INT32_C(  1102273927),  INT32_C(   822598606),  INT32_C(   101791586) },
      {  INT16_C( 20350),  INT16_C( 21375),  INT16_C( 20442), -INT16_C( 13736) },
       INT16_C( 21246),
      { -INT32_C(   897771213),  INT32_C(   648140677),  INT32_C(   388287874),  INT32_C(   393626642) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x4_t a = simde_vld1q_s32(test_vec[i].a);
    simde_int16x4_t b = simde_vld1_s16(test_vec[i].b);
    simde_int32x4_t r = simde_vmlsl_n_s16(a, b, test_vec[i].c);

    simde_test_arm_neon_assert_equal_i32x4(r, simde_vld1q_s32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int32x4_t a = simde_test_arm_neon_random_i32x4();
    simde_int16x4_t b = simde_test_arm_neon_random_i16x4();
    int16_t c = simde_test_codegen_random_i16();
    simde_int32x4_t r = simde_vmlsl_n_s16(a, b, c);

    simde_test_arm_neon_write_i32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i16x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i16(2, c, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vmlsl_n_s32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int64_t a[8];
    int32_t b[8];
    int32_t c;
    int64_t r[8];
  } test_vec[] = {
    { { -INT64_C( 2346229598510318991),  INT64_C( 3796772103095528739) },
      { -INT32_C(  1681176134), -INT32_C(  2129879360) },
       INT32_C(  1543559106),
      {  INT64_C(  248765131915257213),  INT64_C( 7084366783904980899) } },
    { {  INT64_C( 5445455234151003318),  INT64_C( 5502634789337432744) },
      { -INT32_C(   595587551),  INT32_C(   410471511) },
      -INT32_C(  1399225366),
      {  INT64_C( 4612094025117984652),  INT64_C( 6076976939548980770) } },
    { { -INT64_C(  272498232800011942), -INT64_C(  324978474139268855) },
      { -INT32_C(   599270725),  INT32_C(  1085851880) },
      -INT32_C(    27774956),
      { -INT64_C(  289142950818975042), -INT64_C(  294818985949751575) } },
    { { -INT64_C( 2945720800232410701), -INT64_C( 1490380179026717033) },
      {  INT32_C(  1223151245), -INT32_C(  1859899735) },
       INT32_C(   181526006),
      { -INT64_C( 3167754560471188171), -INT64_C( 1152760008571708623) } },
    { { -INT64_C( 6571118978326320883),  INT64_C( 7105642565012876645) },
      { -INT32_C(   129045141),  INT32_C(  1698706876) },
       INT32_C(  1526097251),
      { -INT64_C( 6374183543391313492),  INT64_C( 4513250671294478769) } },
    { {  INT64_C(  869034136292345922),  INT64_C( 1044884366166122015) },
      { -INT32_C(   395305860), -INT32_C(   958349814) },
       INT32_C(  1462444531),
      {  INT64_C( 1447147029321597582),  INT64_C( 2446417810435289249) } },
    { { -INT64_C( 2659632961100373626), -INT64_C( 3519960012574742910) },
      {  INT32_C(  1088268228), -INT32_C(   852996413) },
       INT32_C(     9636108),
      { -INT64_C( 2670119631278350250), -INT64_C( 3511740447015462306) } },
    { { -INT64_C( 3929380913756520918), -INT64_C( 5025300621991571683) },
      { -INT32_C(   410425309), -INT32_C(   752392433) },
      -INT32_C(  1046458187),
      { -INT64_C( 4358873838511575701), -INT64_C( 5812647843341270654) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int64x2_t a = simde_vld1q_s64(test_vec[i].a);
    simde_int32x2_t b = simde_vld1_s32(test_vec[i].b);
    simde_int64x2_t r = simde_vmlsl_n_s32(a, b, test_vec[i].c);

    simde_test_arm_neon_assert_equal_i64x2(r, simde_vld1q_s64(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int64x2_t a = simde_test_arm_neon_random_i64x2();
    simde_int32x2_t b = simde_test_arm_neon_random_i32x2();
    int32_t c = simde_test_codegen_random_i32();
    simde_int64x2_t r = simde_vmlsl_n_s32(a, b, c);

    simde_test_arm_neon_write_i64x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i32x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, c, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vmlsl_n_u16 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint32_t a[8];
    uint16_t b[8];
    uint16_t c;
    uint32_t r[8];
  } test_vec[] = {
    { { UINT32_C(2210477145), UINT32_C(3526564082), UINT32_C(1050454816), UINT32_C(4024320058) },
      { UINT16_C( 8396), UINT16_C(61353), UINT16_C(13192), UINT16_C(39126) },
      UINT16_C(64922),
      { UINT32_C(1665392033), UINT32_C(3838371912), UINT32_C( 194003792), UINT32_C(1484181886) } },
    { { UINT32_C( 189615979), UINT32_C(3527386640), UINT32_C(1558852137), UINT32_C(2684816132) },
      { UINT16_C(16713), UINT16_C(10209), UINT16_C(44337), UINT16_C(55879) },
      UINT16_C(53148),
      { UINT32_C(3596320751), UINT32_C(2984798708), UINT32_C(3497396557), UINT32_C(4009926336) } },
    { { UINT32_C(2808574477), UINT32_C(3187069551), UINT32_C( 493029342), UINT32_C(3276770777) },
      { UINT16_C(21737), UINT16_C(61902), UINT16_C( 6132), UINT16_C(54578) },
      UINT16_C(25406),
      { UINT32_C(2256324255), UINT32_C(1614387339), UINT32_C( 337239750), UINT32_C(1890162109) } },
    { { UINT32_C( 507413890), UINT32_C(3163573077), UINT32_C(3918463219), UINT32_C( 552627645) },
      { UINT16_C(51594), UINT16_C(55981), UINT16_C(38797), UINT16_C(23342) },
      UINT16_C( 8840),
      { UINT32_C(  51322930), UINT32_C(2668701037), UINT32_C(3575497739), UINT32_C( 346284365) } },
    { { UINT32_C(2985867891), UINT32_C(1547139614), UINT32_C( 698846361), UINT32_C(3609827912) },
      { UINT16_C(59012), UINT16_C(29764), UINT16_C(52999), UINT16_C(46142) },
      UINT16_C(52137),
      { UINT32_C(4204126543), UINT32_C(4290301242), UINT32_C(2230604794), UINT32_C(1204122458) } },
    { { UINT32_C(3542538059), UINT32_C(4052654585), UINT32_C(2188160075), UINT32_C(2936931592) },
      { UINT16_C(22062), UINT16_C(22602), UINT16_C(52782), UINT16_C(29246) },
      UINT16_C(17730),
      { UINT32_C(3151378799), UINT32_C(3651921125), UINT32_C(1252335215), UINT32_C(2418400012) } },
    { { UINT32_C(3942285377), UINT32_C(1925268811), UINT32_C(2802563865), UINT32_C( 408114860) },
      { UINT16_C(23512), UINT16_C(58909), UINT16_C(19466), UINT16_C(21565) },
      UINT16_C(27556),
      { UINT32_C(3294388705), UINT32_C( 301972407), UINT32_C(2266158769), UINT32_C(4108837016) } },
    { { UINT32_C(1709040162), UINT32_C( 585441064), UINT32_C(3412537609), UINT32_C(2928050339) },
      { UINT16_C(12839), UINT16_C(31237), UINT16_C(56651), UINT16_C(26837) },
      UINT16_C(57540),
      { UINT32_C( 970284102), UINT32_C(3083031380), UINT32_C( 152839069), UINT32_C(1383849359) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint32x4_t a = simde_vld1q_u32(test_vec[i].a);
    simde_uint16x4_t b = simde_vld1_u16(test_vec[i].b);
    simde_uint32x4_t r = simde_vmlsl_n_u16(a, b, test_vec[i].c);

    simde_test_arm_neon_assert_equal_u32x4(r, simde_vld1q_u32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint32x4_t a = simde_test_arm_neon_random_u32x4();
    simde_uint16x4_t b = simde_test_arm_neon_random_u16x4();
    uint16_t c = simde_test_codegen_random_u16();
    simde_uint32x4_t r = simde_vmlsl_n_u16(a, b, c);

    simde_test_arm_neon_write_u32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u16x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_u16(2, c, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vmlsl_n_u32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint64_t a[8];
    uint32_t b[8];
    uint32_t c;
    uint64_t r[8];
  } test_vec[] = {
    { { UINT64_C( 5276907511242555828), UINT64_C(17064827856324420540) },
      { UINT32_C(3278730557), UINT32_C( 703960100) },
      UINT32_C(3825614863),
      { UINT64_C(11180491234320638753), UINT64_C(14371747634805454240) } },
    { { UINT64_C( 4014670769694231209), UINT64_C(15685449624397672784) },
      { UINT32_C(2563080283), UINT32_C( 425407221) },
      UINT32_C(3594670535),
      { UINT64_C(13247985671264221420), UINT64_C(14156250821692739549) } },
    { { UINT64_C(16111767387484342673), UINT64_C(10652305318833704568) },
      { UINT32_C(3698098561), UINT32_C(4151652609) },
      UINT32_C( 722522212),
      { UINT64_C(13439809034996605741), UINT64_C( 7652644092323453460) } },
    { { UINT64_C(12676994807810315041), UINT64_C( 1331558968493770042) },
      { UINT32_C(3181727292), UINT32_C(3516535248) },
      UINT32_C(2814906179),
      { UINT64_C( 3720730993666577773), UINT64_C( 9879586243936824266) } },
    { { UINT64_C(14462416489356122591), UINT64_C(18049026699570946446) },
      { UINT32_C(3876452011), UINT32_C( 346403396) },
      UINT32_C( 132530116),
      { UINT64_C(13948669854669859315), UINT64_C(18003117817316272510) } },
    { { UINT64_C(12911398499793153614), UINT64_C(12369967078570713683) },
      { UINT32_C(2762286841), UINT32_C(1619767836) },
      UINT32_C( 695545957),
      { UINT64_C(10990101055461301777), UINT64_C(11243344108962274631) } },
    { { UINT64_C(10514741888436689775), UINT64_C( 9264679574992853342) },
      { UINT32_C(2888514995), UINT32_C(2136002659) },
      UINT32_C(3906984835),
      { UINT64_C(17676101681011140566), UINT64_C(  919349578760177077) } },
    { { UINT64_C(13346771192628990988), UINT64_C( 4120387103836742687) },
      { UINT32_C(  28950606), UINT32_C(1622009085) },
      UINT32_C( 954203573),
      { UINT64_C(13319146420943275750), UINT64_C( 2572660239491281982) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint64x2_t a = simde_vld1q_u64(test_vec[i].a);
    simde_uint32x2_t b = simde_vld1_u32(test_vec[i].b);
    simde_uint64x2_t r = simde_vmlsl_n_u32(a, b, test_vec[i].c);

    simde_test_arm_neon_assert_equal_u64x2(r, simde_vld1q_u64(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint64x2_t a = simde_test_arm_neon_random_u64x2();
    simde_uint32x2_t b = simde_test_arm_neon_random_u32x2();
    uint32_t c = simde_test_codegen_random_u32();
    simde_uint64x2_t r = simde_vmlsl_n_u32(a, b, c);

    simde_test_arm_neon_write_u64x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u32x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_u32(2, c, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(vmlsl_n_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vmlsl_n_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vmlsl_n_u16)
SIMDE_TEST_FUNC_LIST_ENTRY(vmlsl_n_u32)
SIMDE_TEST_FUNC_LIST_END

#include "test-neon-footer.h"
