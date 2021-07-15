#define SIMDE_TEST_X86_AVX512_INSN shldv

#include <test/x86/avx512/test-avx512.h>
#include <simde/x86/avx512/shldv.h>

static int
test_simde_mm_shldv_epi32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int32_t a[4];
    const int32_t b[4];
    const int32_t c[4];
    const int32_t r[4];
  } test_vec[] = {
    { { -INT32_C(  1406714453),  INT32_C(  1468213792), -INT32_C(  1399156962),  INT32_C(  1073995188) },
      { -INT32_C(  1176851836), -INT32_C(  1981218022),  INT32_C(   866914973),  INT32_C(  1536447664) },
      { -INT32_C(  1308116079),  INT32_C(    50957029), -INT32_C(   827350246),  INT32_C(    68137600) },
      {  INT32_C(  2069328821), -INT32_C(   261798895),  INT32_C(  2026811466),  INT32_C(  1073995188) } },
    { {  INT32_C(  1992157532), -INT32_C(  1979668499),  INT32_C(  1790815417), -INT32_C(  1849339648) },
      { -INT32_C(   247214836),  INT32_C(  1911835991),  INT32_C(  1900061680), -INT32_C(  1300934826) },
      {  INT32_C(   623457080), -INT32_C(  1817171494), -INT32_C(   704811563), -INT32_C(   882457665) },
      {  INT32_C(  1559315405), -INT32_C(  1245195979), -INT32_C(  1758582764),  INT32_C(  1497016235) } },
    { { -INT32_C(   407000432), -INT32_C(   413552137), -INT32_C(  1420256939),  INT32_C(   543018728) },
      { -INT32_C(   616135167), -INT32_C(  2073102673),  INT32_C(   576285795), -INT32_C(  1074872273) },
      {  INT32_C(  1638312810), -INT32_C(  1320616100), -INT32_C(  2141412968),  INT32_C(  1889647215) },
      { -INT32_C(   156613779),  INT32_C(  2017914730),  INT32_C(  1428314476), -INT32_C(   411803657) } },
    { { -INT32_C(   263461056),  INT32_C(  1081391581),  INT32_C(  1415826981), -INT32_C(   132951666) },
      {  INT32_C(  1482275580),  INT32_C(  1376428473), -INT32_C(  1311611326),  INT32_C(  1629582112) },
      {  INT32_C(   928083034),  INT32_C(  1266205990),  INT32_C(   564190099),  INT32_C(   672772908) },
      {  INT32_C(    23160555),  INT32_C(   489584468),  INT32_C(  1898811027),  INT32_C(   890824210) } },
    { {  INT32_C(   662729325),  INT32_C(  1450805780),  INT32_C(   285756401),  INT32_C(   426912191) },
      { -INT32_C(  1135492202),  INT32_C(   470272393), -INT32_C(   801200220), -INT32_C(   923248805) },
      { -INT32_C(   554731318), -INT32_C(   197892093),  INT32_C(  1929723060), -INT32_C(    57903002) },
      {  INT32_C(    29996785), -INT32_C(  1278455648), -INT32_C(  1088617494),  INT32_C(  1552576498) } },
    { { -INT32_C(   994517701),  INT32_C(  1256308646), -INT32_C(  1038475417),  INT32_C(  1082790518) },
      { -INT32_C(  1910605173), -INT32_C(  1769843742), -INT32_C(   183924849),  INT32_C(  1005688575) },
      {  INT32_C(   452962675), -INT32_C(   798695319),  INT32_C(  1989312511),  INT32_C(   481696913) },
      { -INT32_C(   371429133), -INT32_C(  1015067347), -INT32_C(    91962425),  INT32_C(   619476963) } },
    { {  INT32_C(  2041238934), -INT32_C(  1223742424), -INT32_C(  1280501324),  INT32_C(   586063535) },
      { -INT32_C(  1321406904), -INT32_C(   830365234), -INT32_C(  1320938720), -INT32_C(   959514065) },
      { -INT32_C(   146835249),  INT32_C(  1504661157),  INT32_C(   369908839),  INT32_C(  1111096314) },
      {  INT32_C(  1791711390), -INT32_C(   505051879), -INT32_C(   695412136), -INT32_C(  1088734232) } },
    { { -INT32_C(  1208781335),  INT32_C(   914715670), -INT32_C(  1209480825), -INT32_C(  1820477756) },
      { -INT32_C(   745817042),  INT32_C(  1915501066), -INT32_C(  1870120554),  INT32_C(   500416820) },
      {  INT32_C(  1305790007), -INT32_C(  1031513541), -INT32_C(   411472861),  INT32_C(  1350301218) },
      { -INT32_C(   186006050), -INT32_C(  1282317872), -INT32_C(  1085912004),  INT32_C(  1308023568) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i a = simde_x_mm_loadu_epi32(test_vec[i].a);
    simde__m128i b = simde_x_mm_loadu_epi32(test_vec[i].b);
    simde__m128i c = simde_x_mm_loadu_epi32(test_vec[i].c);
    simde__m128i r = simde_mm_shldv_epi32(a, b, c);
    simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m128i a = simde_test_x86_random_i32x4();
    simde__m128i b = simde_test_x86_random_i32x4();
    simde__m128i c = simde_test_x86_random_i32x4();
    simde__m128i r = simde_mm_shldv_epi32(a, b, c);

    simde_test_x86_write_i32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x4(2, c, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_shldv_epi32)
SIMDE_TEST_FUNC_LIST_END

#include <test/x86/avx512/test-avx512-footer.h>
