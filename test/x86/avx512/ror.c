#define SIMDE_TEST_X86_AVX512_INSN ror

#include <test/x86/avx512/test-avx512.h>
#include <simde/x86/avx512/ror.h>

static int
test_simde_mm_ror_epi32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int32_t a[4];
    int imm8;
    const int32_t r[4];
  } test_vec[] = {
    { { -INT32_C(   151286297),  INT32_C(   644597991),  INT32_C(   746973119), -INT32_C(  2023297337) },
       INT32_C(          92),
      {  INT32_C(  1874386559),  INT32_C(  1723633266), -INT32_C(   933331982),  INT32_C(  1986980984) } },
    { { -INT32_C(  1723844743), -INT32_C(   766494864),  INT32_C(   320937772), -INT32_C(  1828119380) },
       INT32_C(         228),
      { -INT32_C(  1718353033),  INT32_C(   220529527), -INT32_C(  1053683214), -INT32_C(   919563830) } },
    { {  INT32_C(   584007515), -INT32_C(  1985333971),  INT32_C(   321118361), -INT32_C(  2018745321) },
       INT32_C(         155),
      {  INT32_C(  1508371300),  INT32_C(   893822385),  INT32_C(  1685852962), -INT32_C(   175340816) } },
    { { -INT32_C(   925140197),  INT32_C(  2069620119), -INT32_C(  1256319655), -INT32_C(  2099778220) },
       INT32_C(          34),
      { -INT32_C(   231285050), -INT32_C(   556336795),  INT32_C(  1833403734),  INT32_C(   548797269) } },
    { {  INT32_C(  2026778465),  INT32_C(   771783315), -INT32_C(  1829348746),  INT32_C(  1817891541) },
       INT32_C(         183),
      { -INT32_C(  1671511311),  INT32_C(    16066140), -INT32_C(   323687131), -INT32_C(  1247434024) } },
    { {  INT32_C(   533005771),  INT32_C(   346136050), -INT32_C(  2133873378),  INT32_C(  1878564572) },
       INT32_C(          24),
      { -INT32_C(   989476065), -INT32_C(  1583484396), -INT32_C(   810738048), -INT32_C(   123806609) } },
    { {  INT32_C(   656512082),  INT32_C(   496204646), -INT32_C(    80905680),  INT32_C(  1897657215) },
       INT32_C(         144),
      { -INT32_C(  1806555359),  INT32_C(  2070289811),  INT32_C(  2050030381), -INT32_C(   209751781) } },
    { {  INT32_C(  1160664425),  INT32_C(   196356083),  INT32_C(  1922716191),  INT32_C(  1285143526) },
       INT32_C(          54),
      { -INT32_C(  1185569516), -INT32_C(   794833874),  INT32_C(  1766358474),  INT32_C(  1726978354) } },
    { {  INT32_C(  1522272412),  INT32_C(  1666506757), -INT32_C(   651374200), -INT32_C(  1932676407) },
       INT32_C(          20),
      { -INT32_C(  1064712789),  INT32_C(  1308644917), -INT32_C(   854028910), -INT32_C(   617834292) } },
    { {  INT32_C(   964124584),  INT32_C(   447048996),  INT32_C(   135647340), -INT32_C(   563883559) },
       INT32_C(          18),
      { -INT32_C(   672526755),  INT32_C(  1531512489),  INT32_C(  1947927045), -INT32_C(   193562728) } },
    { {  INT32_C(  1377070729),  INT32_C(   350150944), -INT32_C(  1221073393),  INT32_C(  1777380933) },
       INT32_C(          27),
      {  INT32_C(  1116590378), -INT32_C(  1680071678), -INT32_C(   419642890),  INT32_C(  1041615021) } },
    { {  INT32_C(  1066440806),  INT32_C(   471724906),  INT32_C(   861298602), -INT32_C(   309957939) },
       INT32_C(          11),
      {  INT32_C(   214430227),  INT32_C(  1833141182), -INT32_C(   179934517),  INT32_C(  1505603789) } },
    { { -INT32_C(  1877854134),  INT32_C(    49873638), -INT32_C(     7766632),  INT32_C(  2134776085) },
       INT32_C(          12),
      { -INT32_C(  2069298909),  INT32_C(   778055568), -INT32_C(   644876137), -INT32_C(  1856506911) } },
    { { -INT32_C(  1997868357), -INT32_C(  1468698532),  INT32_C(   520255189), -INT32_C(  1783688017) },
       INT32_C(          23),
      { -INT32_C(   706382063), -INT32_C(   354371248),  INT32_C(    82684478),  INT32_C(  1579769643) } },
  };

  simde__m128i a, r;

  #if !(defined(HEDLEY_MSVC_VERSION) && defined(SIMDE_X86_AVX512F_NATIVE) && defined(SIMDE_X86_AVX512VL_NATIVE))
  a = simde_x_mm_loadu_epi32(test_vec[0].a);
  r = simde_mm_ror_epi32(a, INT32_C(          92));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[0].r));

  a = simde_x_mm_loadu_epi32(test_vec[1].a);
  r = simde_mm_ror_epi32(a, INT32_C(         228));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[1].r));

  a = simde_x_mm_loadu_epi32(test_vec[2].a);
  r = simde_mm_ror_epi32(a, INT32_C(         155));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[2].r));

  a = simde_x_mm_loadu_epi32(test_vec[3].a);
  r = simde_mm_ror_epi32(a, INT32_C(          34));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[3].r));

  a = simde_x_mm_loadu_epi32(test_vec[4].a);
  r = simde_mm_ror_epi32(a, INT32_C(         183));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[4].r));
  #endif

  a = simde_x_mm_loadu_epi32(test_vec[5].a);
  r = simde_mm_ror_epi32(a, INT32_C(          24));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[5].r));

  #if !(defined(HEDLEY_MSVC_VERSION) && defined(SIMDE_X86_AVX512F_NATIVE) && defined(SIMDE_X86_AVX512VL_NATIVE))
  a = simde_x_mm_loadu_epi32(test_vec[6].a);
  r = simde_mm_ror_epi32(a, INT32_C(         144));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[6].r));

  a = simde_x_mm_loadu_epi32(test_vec[7].a);
  r = simde_mm_ror_epi32(a, INT32_C(          54));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[7].r));
  #endif

  a = simde_x_mm_loadu_epi32(test_vec[8].a);
  r = simde_mm_ror_epi32(a, INT32_C(          20));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[8].r));

  a = simde_x_mm_loadu_epi32(test_vec[9].a);
  r = simde_mm_ror_epi32(a, INT32_C(          18));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[9].r));

  a = simde_x_mm_loadu_epi32(test_vec[10].a);
  r = simde_mm_ror_epi32(a, INT32_C(          27));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[10].r));

  a = simde_x_mm_loadu_epi32(test_vec[11].a);
  r = simde_mm_ror_epi32(a, INT32_C(          11));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[11].r));

  a = simde_x_mm_loadu_epi32(test_vec[12].a);
  r = simde_mm_ror_epi32(a, INT32_C(          12));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[12].r));

  a = simde_x_mm_loadu_epi32(test_vec[13].a);
  r = simde_mm_ror_epi32(a, INT32_C(          23));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[13].r));

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m128i a = simde_test_x86_random_i32x4();
    int imm8 = simde_test_codegen_random_i32() & 31;
    simde__m128i r;
    SIMDE_CONSTIFY_256_(simde_mm_ror_epi32, r, simde_mm_setzero_si128(), imm8, a);

    simde_test_x86_write_i32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_i32(2, imm8, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_mask_ror_epi32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int32_t src[4];
    const simde__mmask8 k;
    const int32_t a[4];
    int imm8;
    const int32_t r[4];
  } test_vec[] = {
    { { -INT32_C(  1061360089), -INT32_C(   437364155),  INT32_C(   318613920),  INT32_C(  1795275722) },
      UINT8_C(251),
      {  INT32_C(   384384489),  INT32_C(  1119560614),  INT32_C(  2097975324),  INT32_C(   799342144) },
       INT32_C(         186),
      { -INT32_C(  1169196475), -INT32_C(  1362564720),  INT32_C(   318613920), -INT32_C(   381710325) } },
    { { -INT32_C(    55223981),  INT32_C(   315017046), -INT32_C(  1307758135),  INT32_C(   348780142) },
      UINT8_C( 25),
      {  INT32_C(   339040132),  INT32_C(  1633006179), -INT32_C(  1138981801),  INT32_C(  1359950072) },
       INT32_C(         229),
      {  INT32_C(   547465916),  INT32_C(   315017046), -INT32_C(  1307758135), -INT32_C(  1031243385) } },
    { {  INT32_C(    41335505), -INT32_C(  1099945785),  INT32_C(  1993836017),  INT32_C(  1066012124) },
      UINT8_C(191),
      {  INT32_C(  1662427615), -INT32_C(   312749379), -INT32_C(   321671711),  INT32_C(   264077397) },
       INT32_C(         246),
      {  INT32_C(  1518828940),  INT32_C(  1867184053),  INT32_C(  1320650675), -INT32_C(   167685058) } },
    { { -INT32_C(  1257204688),  INT32_C(  2039580268), -INT32_C(   264712176),  INT32_C(   777211761) },
      UINT8_C( 33),
      {  INT32_C(  1543707823),  INT32_C(  1873932271),  INT32_C(  1818607789),  INT32_C(   731677590) },
       INT32_C(         147),
      {  INT32_C(  1670769536),  INT32_C(  2039580268), -INT32_C(   264712176),  INT32_C(   777211761) } },
    { { -INT32_C(  1289088798), -INT32_C(  1759241656),  INT32_C(   481907565),  INT32_C(  1584970863) },
      UINT8_C(171),
      { -INT32_C(   380056279), -INT32_C(  1249852110), -INT32_C(  1287017631),  INT32_C(  1385521730) },
       INT32_C(         140),
      { -INT32_C(   761358964),  INT32_C(  1395349516),  INT32_C(   481907565),  INT32_C(   606415190) } },
    { { -INT32_C(  1072418195), -INT32_C(  1490079509), -INT32_C(   766341719), -INT32_C(  1933792422) },
      UINT8_C(112),
      { -INT32_C(   405716676), -INT32_C(   316046198),  INT32_C(  1652128538),  INT32_C(  1204756501) },
       INT32_C(          52),
      { -INT32_C(  1072418195), -INT32_C(  1490079509), -INT32_C(   766341719), -INT32_C(  1933792422) } },
    { {  INT32_C(  1259198910), -INT32_C(   676995028), -INT32_C(   666422884), -INT32_C(    37808013) },
      UINT8_C(157),
      {  INT32_C(  1672997608), -INT32_C(  2072503964),  INT32_C(  2025373929), -INT32_C(   868803342) },
       INT32_C(          42),
      { -INT32_C(  1172771334), -INT32_C(   676995028),  INT32_C(   979250736),  INT32_C(  1018367431) } },
    { {  INT32_C(  1504104232),  INT32_C(   785153558),  INT32_C(   634112573),  INT32_C(   411599540) },
      UINT8_C(156),
      { -INT32_C(  1064985600),  INT32_C(  1907621204), -INT32_C(  1214546124),  INT32_C(  1189062007) },
       INT32_C(          75),
      {  INT32_C(  1504104232),  INT32_C(   785153558), -INT32_C(   426314897), -INT32_C(  1360471052) } },
    { {  INT32_C(  1628697625),  INT32_C(   889626588),  INT32_C(   392385440),  INT32_C(   121549219) },
      UINT8_C(174),
      {  INT32_C(  1297384186), -INT32_C(  2050875220), -INT32_C(   364154585),  INT32_C(  1526946407) },
       INT32_C(          13),
      {  INT32_C(  1628697625),  INT32_C(    90451473), -INT32_C(  1992338853), -INT32_C(   751118310) } },
    { { -INT32_C(  1095996053), -INT32_C(  2124299056), -INT32_C(    64002046), -INT32_C(  1756789782) },
      UINT8_C(163),
      {  INT32_C(  2093685771), -INT32_C(  1025264280),  INT32_C(   472923832), -INT32_C(   477676426) },
       INT32_C(           9),
      {  INT32_C(    96363918), -INT32_C(  1268682278), -INT32_C(    64002046), -INT32_C(  1756789782) } },
    { {  INT32_C(   279917991), -INT32_C(   386225308),  INT32_C(     9146868),  INT32_C(   377247406) },
      UINT8_C( 11),
      { -INT32_C(  1631332256),  INT32_C(  1158995976), -INT32_C(  1389430937), -INT32_C(   531244117) },
       INT32_C(          10),
      {  INT32_C(   405254390),  INT32_C(    34686264),  INT32_C(     9146868), -INT32_C(   352840330) } },
    { { -INT32_C(   248959905),  INT32_C(   245311928),  INT32_C(   102413734), -INT32_C(  1767580275) },
      UINT8_C(189),
      { -INT32_C(  1339696199), -INT32_C(   463744503), -INT32_C(  1938932953), -INT32_C(  1393777792) },
       INT32_C(          12),
      { -INT32_C(  1147469219),  INT32_C(   245311928), -INT32_C(  1300707613),  INT32_C(   940232394) } },
    { {  INT32_C(   832336764),  INT32_C(  1790878349), -INT32_C(    14134202),  INT32_C(   951078191) },
      UINT8_C( 31),
      {  INT32_C(  1195842571),  INT32_C(   768070538), -INT32_C(  1661307969),  INT32_C(  1259925720) },
       INT32_C(          12),
      { -INT32_C(  1061915535),  INT32_C(   950197373),  INT32_C(  1006227367),  INT32_C(   226800015) } },
    { {  INT32_C(  1551122952), -INT32_C(  1215531926),  INT32_C(   802669604),  INT32_C(  1802903265) },
      UINT8_C(241),
      { -INT32_C(  1313760963), -INT32_C(  2088153709), -INT32_C(  1357917082), -INT32_C(   289981012) },
       INT32_C(          17),
      { -INT32_C(   862005032), -INT32_C(  1215531926),  INT32_C(   802669604),  INT32_C(  1802903265) } },
    { {  INT32_C(  1682509984),  INT32_C(    88439271),  INT32_C(   771207663), -INT32_C(   572610486) },
      UINT8_C(245),
      {  INT32_C(   995844199), -INT32_C(  1394144401), -INT32_C(   698493502),  INT32_C(  1064731438) },
       INT32_C(          12),
      {  INT32_C(   108246454),  INT32_C(    88439271),  INT32_C(  1546479069), -INT32_C(   572610486) } },
    { { -INT32_C(   785044448), -INT32_C(   887397853), -INT32_C(  1480525760), -INT32_C(   941482920) },
      UINT8_C( 39),
      { -INT32_C(  1628867639),  INT32_C(  1422770385),  INT32_C(   287312950),  INT32_C(  1580361266) },
       INT32_C(          27),
      { -INT32_C(   584156877), -INT32_C(  1715987926),  INT32_C(   604079810), -INT32_C(   941482920) } },
  };

  simde__m128i src, a, r;

  #if !(defined(HEDLEY_MSVC_VERSION) && defined(SIMDE_X86_AVX512F_NATIVE) && defined(SIMDE_X86_AVX512VL_NATIVE))
  src = simde_x_mm_loadu_epi32(test_vec[0].src);
  a = simde_x_mm_loadu_epi32(test_vec[0].a);
  r = simde_mm_mask_ror_epi32(src, test_vec[0].k, a, INT32_C(         186));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[0].r));

  src = simde_x_mm_loadu_epi32(test_vec[1].src);
  a = simde_x_mm_loadu_epi32(test_vec[1].a);
  r = simde_mm_mask_ror_epi32(src, test_vec[1].k, a, INT32_C(         229));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[1].r));

  src = simde_x_mm_loadu_epi32(test_vec[2].src);
  a = simde_x_mm_loadu_epi32(test_vec[2].a);
  r = simde_mm_mask_ror_epi32(src, test_vec[2].k, a, INT32_C(         246));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[2].r));

  src = simde_x_mm_loadu_epi32(test_vec[3].src);
  a = simde_x_mm_loadu_epi32(test_vec[3].a);
  r = simde_mm_mask_ror_epi32(src, test_vec[3].k, a, INT32_C(         147));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[3].r));

  src = simde_x_mm_loadu_epi32(test_vec[4].src);
  a = simde_x_mm_loadu_epi32(test_vec[4].a);
  r = simde_mm_mask_ror_epi32(src, test_vec[4].k, a, INT32_C(         140));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[4].r));

  src = simde_x_mm_loadu_epi32(test_vec[5].src);
  a = simde_x_mm_loadu_epi32(test_vec[5].a);
  r = simde_mm_mask_ror_epi32(src, test_vec[5].k, a, INT32_C(          52));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[5].r));

  src = simde_x_mm_loadu_epi32(test_vec[6].src);
  a = simde_x_mm_loadu_epi32(test_vec[6].a);
  r = simde_mm_mask_ror_epi32(src, test_vec[6].k, a, INT32_C(          42));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[6].r));

  src = simde_x_mm_loadu_epi32(test_vec[7].src);
  a = simde_x_mm_loadu_epi32(test_vec[7].a);
  r = simde_mm_mask_ror_epi32(src, test_vec[7].k, a, INT32_C(          75));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[7].r));
  #endif

  src = simde_x_mm_loadu_epi32(test_vec[8].src);
  a = simde_x_mm_loadu_epi32(test_vec[8].a);
  r = simde_mm_mask_ror_epi32(src, test_vec[8].k, a, INT32_C(          13));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[8].r));

  src = simde_x_mm_loadu_epi32(test_vec[9].src);
  a = simde_x_mm_loadu_epi32(test_vec[9].a);
  r = simde_mm_mask_ror_epi32(src, test_vec[9].k, a, INT32_C(           9));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[9].r));

  src = simde_x_mm_loadu_epi32(test_vec[10].src);
  a = simde_x_mm_loadu_epi32(test_vec[10].a);
  r = simde_mm_mask_ror_epi32(src, test_vec[10].k, a, INT32_C(          10));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[10].r));

  src = simde_x_mm_loadu_epi32(test_vec[11].src);
  a = simde_x_mm_loadu_epi32(test_vec[11].a);
  r = simde_mm_mask_ror_epi32(src, test_vec[11].k, a, INT32_C(          12));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[11].r));

  src = simde_x_mm_loadu_epi32(test_vec[12].src);
  a = simde_x_mm_loadu_epi32(test_vec[12].a);
  r = simde_mm_mask_ror_epi32(src, test_vec[12].k, a, INT32_C(          12));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[12].r));

  src = simde_x_mm_loadu_epi32(test_vec[13].src);
  a = simde_x_mm_loadu_epi32(test_vec[13].a);
  r = simde_mm_mask_ror_epi32(src, test_vec[13].k, a, INT32_C(          17));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[13].r));

  src = simde_x_mm_loadu_epi32(test_vec[14].src);
  a = simde_x_mm_loadu_epi32(test_vec[14].a);
  r = simde_mm_mask_ror_epi32(src, test_vec[14].k, a, INT32_C(          12));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[14].r));

  src = simde_x_mm_loadu_epi32(test_vec[15].src);
  a = simde_x_mm_loadu_epi32(test_vec[15].a);
  r = simde_mm_mask_ror_epi32(src, test_vec[15].k, a, INT32_C(          27));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[15].r));

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m128i src = simde_test_x86_random_i32x4();
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m128i a = simde_test_x86_random_i32x4();
    int imm8 = simde_test_codegen_random_i32() & 31;
    simde__m128i r;
    SIMDE_CONSTIFY_256_(simde_mm_mask_ror_epi32, r, simde_mm_setzero_si128(), imm8, src, k, a);

    simde_test_x86_write_i32x4(2, src, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x4(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, imm8, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_maskz_ror_epi32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask8 k;
    const int32_t a[4];
    int imm8;
    const int32_t r[4];
  } test_vec[] = {
    { UINT8_C(  5),
      {  INT32_C(  1456408202), -INT32_C(  1277656277),  INT32_C(   951284892), -INT32_C(   141724423) },
       INT32_C(          39),
      {  INT32_C(   346922509),  INT32_C(           0),  INT32_C(   946956009),  INT32_C(           0) } },
    { UINT8_C(153),
      { -INT32_C(  1052893726), -INT32_C(  1074099869),  INT32_C(  1481244498),  INT32_C(  1367580622) },
       INT32_C(         120),
      {  INT32_C(  1042145985),  INT32_C(           0),  INT32_C(           0), -INT32_C(  2086678959) } },
    { UINT8_C(233),
      { -INT32_C(  1285691866),  INT32_C(   145851613),  INT32_C(  1206602282),  INT32_C(   296397960) },
       INT32_C(         166),
      { -INT32_C(  1697810536),  INT32_C(           0),  INT32_C(           0),  INT32_C(   541502130) } },
    { UINT8_C(179),
      {  INT32_C(  1045590971), -INT32_C(  1300968763), -INT32_C(  1646764617),  INT32_C(  1064995771) },
       INT32_C(          60),
      { -INT32_C(   450413645),  INT32_C(   659336283),  INT32_C(           0),  INT32_C(           0) } },
    { UINT8_C(109),
      {  INT32_C(  1545211569), -INT32_C(  2100969441), -INT32_C(   650282906), -INT32_C(  1784775733) },
       INT32_C(         239),
      {  INT32_C(   493008948),  INT32_C(           0), -INT32_C(   254954886), -INT32_C(   141087940) } },
    { UINT8_C( 41),
      {  INT32_C(  1672808681), -INT32_C(  1310265017), -INT32_C(  2040310920),  INT32_C(   782679917) },
       INT32_C(         132),
      { -INT32_C(  1774497650),  INT32_C(           0),  INT32_C(           0), -INT32_C(   756388874) } },
    { UINT8_C(102),
      {  INT32_C(   216123501), -INT32_C(  1436692131),  INT32_C(   647202334),  INT32_C(   762181435) },
       INT32_C(         221),
      {  INT32_C(           0),  INT32_C(  1391364845),  INT32_C(   882651377),  INT32_C(           0) } },
    { UINT8_C(130),
      { -INT32_C(   784228821),  INT32_C(  1627047372), -INT32_C(  1966251838),  INT32_C(   317249857) },
       INT32_C(          54),
      {  INT32_C(           0), -INT32_C(   350801533),  INT32_C(           0),  INT32_C(           0) } },
    { UINT8_C( 31),
      {  INT32_C(   219626828), -INT32_C(   970362652), -INT32_C(  1416671177), -INT32_C(   109302471) },
       INT32_C(          26),
      {  INT32_C(  1171215107), -INT32_C(  1973667535), -INT32_C(   472642070),  INT32_C(  1594576510) } },
    { UINT8_C(240),
      {  INT32_C(  1935030593),  INT32_C(   427291031),  INT32_C(   728078062),  INT32_C(   487551661) },
       INT32_C(          27),
      {  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0) } },
    { UINT8_C(100),
      {  INT32_C(  2089952512),  INT32_C(  1313639454), -INT32_C(   862962541), -INT32_C(  2073885805) },
       INT32_C(          26),
      {  INT32_C(           0),  INT32_C(           0),  INT32_C(   604972275),  INT32_C(           0) } },
    { UINT8_C(226),
      { -INT32_C(  1370177890),  INT32_C(   813953243),  INT32_C(     3205339),  INT32_C(   102739066) },
       INT32_C(          24),
      {  INT32_C(           0), -INT32_C(  2081367248),  INT32_C(           0),  INT32_C(           0) } },
    { UINT8_C(253),
      { -INT32_C(   922630043), -INT32_C(  1085965492),  INT32_C(  1247684492),  INT32_C(  1814367356) },
       INT32_C(          15),
      { -INT32_C(  1865707005),  INT32_C(           0),  INT32_C(  1327011004),  INT32_C(   418961482) } },
    { UINT8_C(134),
      {  INT32_C(  1731457352), -INT32_C(  1848366088),  INT32_C(   687329888),  INT32_C(  1316339923) },
       INT32_C(           5),
      {  INT32_C(           0), -INT32_C(   997285537),  INT32_C(    21479059),  INT32_C(           0) } },
    { UINT8_C(146),
      {  INT32_C(  1251911972),  INT32_C(  1554001429), -INT32_C(  1750849883), -INT32_C(  2054223015) },
       INT32_C(           0),
      {  INT32_C(           0),  INT32_C(  1554001429),  INT32_C(           0),  INT32_C(           0) } },
    { UINT8_C( 23),
      { -INT32_C(  2083027698), -INT32_C(  1363681837), -INT32_C(  1278064118),  INT32_C(   382213352) },
       INT32_C(          28),
      {  INT32_C(  1031295208), -INT32_C(   344072902),  INT32_C(  1025810603),  INT32_C(           0) } },
  };

  simde__m128i a, r;

  #if !(defined(HEDLEY_MSVC_VERSION) && defined(SIMDE_X86_AVX512F_NATIVE) && defined(SIMDE_X86_AVX512VL_NATIVE))
  a = simde_x_mm_loadu_epi32(test_vec[0].a);
  r = simde_mm_maskz_ror_epi32(test_vec[0].k, a, INT32_C(          39));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[0].r));

  a = simde_x_mm_loadu_epi32(test_vec[1].a);
  r = simde_mm_maskz_ror_epi32(test_vec[1].k, a, INT32_C(         120));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[1].r));

  a = simde_x_mm_loadu_epi32(test_vec[2].a);
  r = simde_mm_maskz_ror_epi32(test_vec[2].k, a, INT32_C(         166));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[2].r));

  a = simde_x_mm_loadu_epi32(test_vec[3].a);
  r = simde_mm_maskz_ror_epi32(test_vec[3].k, a, INT32_C(          60));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[3].r));

  a = simde_x_mm_loadu_epi32(test_vec[4].a);
  r = simde_mm_maskz_ror_epi32(test_vec[4].k, a, INT32_C(         239));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[4].r));

  a = simde_x_mm_loadu_epi32(test_vec[5].a);
  r = simde_mm_maskz_ror_epi32(test_vec[5].k, a, INT32_C(         132));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[5].r));

  a = simde_x_mm_loadu_epi32(test_vec[6].a);
  r = simde_mm_maskz_ror_epi32(test_vec[6].k, a, INT32_C(         221));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[6].r));

  a = simde_x_mm_loadu_epi32(test_vec[7].a);
  r = simde_mm_maskz_ror_epi32(test_vec[7].k, a, INT32_C(          54));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[7].r));
  #endif

  a = simde_x_mm_loadu_epi32(test_vec[8].a);
  r = simde_mm_maskz_ror_epi32(test_vec[8].k, a, INT32_C(          26));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[8].r));

  a = simde_x_mm_loadu_epi32(test_vec[9].a);
  r = simde_mm_maskz_ror_epi32(test_vec[9].k, a, INT32_C(          27));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[9].r));

  a = simde_x_mm_loadu_epi32(test_vec[10].a);
  r = simde_mm_maskz_ror_epi32(test_vec[10].k, a, INT32_C(          26));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[10].r));

  a = simde_x_mm_loadu_epi32(test_vec[11].a);
  r = simde_mm_maskz_ror_epi32(test_vec[11].k, a, INT32_C(          24));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[11].r));

  a = simde_x_mm_loadu_epi32(test_vec[12].a);
  r = simde_mm_maskz_ror_epi32(test_vec[12].k, a, INT32_C(          15));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[12].r));

  a = simde_x_mm_loadu_epi32(test_vec[13].a);
  r = simde_mm_maskz_ror_epi32(test_vec[13].k, a, INT32_C(           5));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[13].r));

  a = simde_x_mm_loadu_epi32(test_vec[14].a);
  r = simde_mm_maskz_ror_epi32(test_vec[14].k, a, INT32_C(           0));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[14].r));

  a = simde_x_mm_loadu_epi32(test_vec[15].a);
  r = simde_mm_maskz_ror_epi32(test_vec[15].k, a, INT32_C(          28));
  simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[15].r));

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m128i a = simde_test_x86_random_i32x4();
    int imm8 = simde_test_codegen_random_i32() & 31;
    simde__m128i r;
    SIMDE_CONSTIFY_256_(simde_mm_maskz_ror_epi32, r, simde_mm_setzero_si128(), imm8, k, a);

    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i32x4(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, imm8, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm256_ror_epi32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int32_t a[8];
    int imm8;
    const int32_t r[8];
  } test_vec[] = {
    { {  INT32_C(  1725778856),  INT32_C(  2135231872), -INT32_C(   682203291),  INT32_C(  1033824673), -INT32_C(  1930435379), -INT32_C(  2016110467), -INT32_C(   984243507), -INT32_C(   265232056) },
       INT32_C(          44),
      { -INT32_C(  1165595180), -INT32_C(   670567344),  INT32_C(  1985836390), -INT32_C(  1709975058),  INT32_C(  1289277182), -INT32_C(  2015855287),  INT32_C(   752637274),  INT32_C(   344916750) } },
    { {  INT32_C(  2133629722), -INT32_C(  1537768957),  INT32_C(   971109740),  INT32_C(  1472582105),  INT32_C(   937335145), -INT32_C(  2080623813),  INT32_C(  1081289748),  INT32_C(  1424869689) },
       INT32_C(         101),
      { -INT32_C(   738630440),  INT32_C(   488815632),  INT32_C(  1640959915), -INT32_C(   893505906),  INT32_C(  1237251275), -INT32_C(   601890407), -INT32_C(  1576822432), -INT32_C(   894996919) } },
    { {  INT32_C(   135015068), -INT32_C(   113119712),  INT32_C(   676333247), -INT32_C(   614519137),  INT32_C(  1969118305), -INT32_C(  1028205944),  INT32_C(     1483675),  INT32_C(  1500047805) },
       INT32_C(          20),
      { -INT32_C(  1029062528),  INT32_C(   518131604),  INT32_C(     7074437), -INT32_C(   219546187), -INT32_C(   440002731),  INT32_C(  1831373867),  INT32_C(  1782165505), -INT32_C(  1902389866) } },
    { {  INT32_C(   573416035),  INT32_C(  1196064424),  INT32_C(   237152940), -INT32_C(  1903984378), -INT32_C(   296732333), -INT32_C(  1695586595),  INT32_C(  1693669200),  INT32_C(   798512332) },
       INT32_C(         246),
      { -INT32_C(  1232499576),  INT32_C(   704291101), -INT32_C(  1968525256),  INT32_C(   235149882),  INT32_C(  1088769977), -INT32_C(  1113885077), -INT32_C(   849526381),  INT32_C(  1632841918) } },
    { { -INT32_C(   253387709),  INT32_C(  1291716678), -INT32_C(   589659767), -INT32_C(  1731580997), -INT32_C(   516769391), -INT32_C(   582671087),  INT32_C(  1863179641), -INT32_C(   435331421) },
       INT32_C(         250),
      {  INT32_C(   963055868),  INT32_C(  1065488787),  INT32_C(   916480631),  INT32_C(   847965926),  INT32_C(  1286497400),  INT32_C(  1363756151), -INT32_C(  1015587237), -INT32_C(  2091407111) } },
    { { -INT32_C(  2087922438),  INT32_C(   291465046),  INT32_C(   598289042), -INT32_C(   200942621),  INT32_C(  2043824640), -INT32_C(   873930968),  INT32_C(   951186749), -INT32_C(   495417113) },
       INT32_C(          92),
      {  INT32_C(   952979368),  INT32_C(   368473441),  INT32_C(   982690082),  INT32_C(  1079885375), -INT32_C(  1658544121), -INT32_C(  1097993588), -INT32_C(  1960881197),  INT32_C(   663260798) } },
    { { -INT32_C(    20724372), -INT32_C(   769561361),  INT32_C(  1204233799), -INT32_C(  1715431055), -INT32_C(  1251694472), -INT32_C(  2048060003), -INT32_C(    93886819), -INT32_C(   676541333) },
       INT32_C(         145),
      { -INT32_C(   491356319), -INT32_C(  1233655536), -INT32_C(  1826380829),  INT32_C(  1287179488),  INT32_C(  1413241522), -INT32_C(  1966161162), -INT32_C(  1286669005),  INT32_C(  1714809814) } },
    { {  INT32_C(   609482460), -INT32_C(  1905583587),  INT32_C(   723987635),  INT32_C(  1927318484),  INT32_C(  1056427680), -INT32_C(  1623695820), -INT32_C(  1133059030),  INT32_C(   826035028) },
       INT32_C(          65),
      {  INT32_C(   304741230), -INT32_C(   952791794), -INT32_C(  1785489831),  INT32_C(   963659242),  INT32_C(   528213840),  INT32_C(  1335635738),  INT32_C(  1580954133),  INT32_C(   413017514) } },
    { { -INT32_C(   734243895),  INT32_C(    45400546), -INT32_C(  1256560985), -INT32_C(  1086787093), -INT32_C(   663883826),  INT32_C(   579551033),  INT32_C(   406344540),  INT32_C(  1107031160) },
       INT32_C(           7),
      { -INT32_C(  1817675609), -INT32_C(  1006278269),  INT32_C(  1332360397), -INT32_C(   679579165), -INT32_C(  1649353761),  INT32_C(  1917130366), -INT32_C(  1204784986), -INT32_C(   259786776) } },
    { { -INT32_C(  1607677191),  INT32_C(   475350576),  INT32_C(   115051831), -INT32_C(  1226946435), -INT32_C(   472356217),  INT32_C(   905712061),  INT32_C(  1299642117),  INT32_C(   695634991) },
       INT32_C(          22),
      { -INT32_C(  1288968576),  INT32_C(  1427685489),  INT32_C(  1848957979),  INT32_C(  2032269019),  INT32_C(  1638539151), -INT32_C(   263785257), -INT32_C(   606333643), -INT32_C(   634340187) } },
    { {  INT32_C(   547495912),  INT32_C(   690388396),  INT32_C(  1306526917),  INT32_C(   741390446), -INT32_C(   815715127),  INT32_C(  1394399268), -INT32_C(  1166241180),  INT32_C(   490751541) },
       INT32_C(           5),
      {  INT32_C(  1090851071),  INT32_C(  1632187373),  INT32_C(   711917606),  INT32_C(  1902216643),  INT32_C(  1316686182),  INT32_C(   580445889),  INT32_C(   634643603), -INT32_C(  1461059023) } },
    { {  INT32_C(   641426272), -INT32_C(   697099416), -INT32_C(  1660771373), -INT32_C(   194222896), -INT32_C(  1605924804),  INT32_C(  1331348506),  INT32_C(  1869453834), -INT32_C(   561993091) },
       INT32_C(          14),
      { -INT32_C(  1920952083),  INT32_C(  1839421900), -INT32_C(  1890683894), -INT32_C(  1824271951),  INT32_C(   552763678),  INT32_C(   275332459),  INT32_C(  1747566006), -INT32_C(  1443399166) } },
    { { -INT32_C(  1437829162), -INT32_C(   364425446), -INT32_C(   270617677),  INT32_C(  1435444795), -INT32_C(   190453270),  INT32_C(    23270019), -INT32_C(   891296836),  INT32_C(  1967186847) },
       INT32_C(          26),
      { -INT32_C(  1826753110), -INT32_C(  1848392006), -INT32_C(   139662085),  INT32_C(  1674153685),  INT32_C(   695892669),  INT32_C(  1489281216), -INT32_C(  1208422606),  INT32_C(  1345906653) } },
    { { -INT32_C(  1889573156),  INT32_C(  1417559321),  INT32_C(  1302990179),  INT32_C(  2034323446),  INT32_C(   494576737),  INT32_C(   669538696), -INT32_C(  1768150980), -INT32_C(  1861501771) },
       INT32_C(           2),
      {  INT32_C(   601348535),  INT32_C(  1428131654), -INT32_C(   747994280), -INT32_C(  1638902787),  INT32_C(  1197386008),  INT32_C(   167384674),  INT32_C(   631704079),  INT32_C(  1682108205) } },
    { {  INT32_C(   194027175), -INT32_C(  1588053333), -INT32_C(   367289719), -INT32_C(   972516034),  INT32_C(   737013999), -INT32_C(   826111464),  INT32_C(  1751108934), -INT32_C(   559644617) },
       INT32_C(          30),
      {  INT32_C(   776108700), -INT32_C(  2057246034), -INT32_C(  1469158873),  INT32_C(   404903163), -INT32_C(  1346911300),  INT32_C(   990521443), -INT32_C(  1585498855),  INT32_C(  2056388831) } },
  };

  simde__m256i a, r;

  #if !(defined(HEDLEY_MSVC_VERSION) && defined(SIMDE_X86_AVX512F_NATIVE) && defined(SIMDE_X86_AVX512VL_NATIVE))
  a = simde_x_mm256_loadu_epi32(test_vec[0].a);
  r = simde_mm256_ror_epi32(a, INT32_C(          44));
  simde_test_x86_assert_equal_i32x8(r, simde_x_mm256_loadu_epi32(test_vec[0].r));

  a = simde_x_mm256_loadu_epi32(test_vec[1].a);
  r = simde_mm256_ror_epi32(a, INT32_C(         101));
  simde_test_x86_assert_equal_i32x8(r, simde_x_mm256_loadu_epi32(test_vec[1].r));
  #endif

  a = simde_x_mm256_loadu_epi32(test_vec[2].a);
  r = simde_mm256_ror_epi32(a, INT32_C(          20));
  simde_test_x86_assert_equal_i32x8(r, simde_x_mm256_loadu_epi32(test_vec[2].r));

  #if !(defined(HEDLEY_MSVC_VERSION) && defined(SIMDE_X86_AVX512F_NATIVE) && defined(SIMDE_X86_AVX512VL_NATIVE))
  a = simde_x_mm256_loadu_epi32(test_vec[3].a);
  r = simde_mm256_ror_epi32(a, INT32_C(         246));
  simde_test_x86_assert_equal_i32x8(r, simde_x_mm256_loadu_epi32(test_vec[3].r));

  a = simde_x_mm256_loadu_epi32(test_vec[4].a);
  r = simde_mm256_ror_epi32(a, INT32_C(         250));
  simde_test_x86_assert_equal_i32x8(r, simde_x_mm256_loadu_epi32(test_vec[4].r));

  a = simde_x_mm256_loadu_epi32(test_vec[5].a);
  r = simde_mm256_ror_epi32(a, INT32_C(          92));
  simde_test_x86_assert_equal_i32x8(r, simde_x_mm256_loadu_epi32(test_vec[5].r));

  a = simde_x_mm256_loadu_epi32(test_vec[6].a);
  r = simde_mm256_ror_epi32(a, INT32_C(         145));
  simde_test_x86_assert_equal_i32x8(r, simde_x_mm256_loadu_epi32(test_vec[6].r));

  a = simde_x_mm256_loadu_epi32(test_vec[7].a);
  r = simde_mm256_ror_epi32(a, INT32_C(          65));
  simde_test_x86_assert_equal_i32x8(r, simde_x_mm256_loadu_epi32(test_vec[7].r));
  #endif

  a = simde_x_mm256_loadu_epi32(test_vec[8].a);
  r = simde_mm256_ror_epi32(a, INT32_C(           7));
  simde_test_x86_assert_equal_i32x8(r, simde_x_mm256_loadu_epi32(test_vec[8].r));

  a = simde_x_mm256_loadu_epi32(test_vec[9].a);
  r = simde_mm256_ror_epi32(a, INT32_C(          22));
  simde_test_x86_assert_equal_i32x8(r, simde_x_mm256_loadu_epi32(test_vec[9].r));

  a = simde_x_mm256_loadu_epi32(test_vec[10].a);
  r = simde_mm256_ror_epi32(a, INT32_C(           5));
  simde_test_x86_assert_equal_i32x8(r, simde_x_mm256_loadu_epi32(test_vec[10].r));

  a = simde_x_mm256_loadu_epi32(test_vec[11].a);
  r = simde_mm256_ror_epi32(a, INT32_C(          14));
  simde_test_x86_assert_equal_i32x8(r, simde_x_mm256_loadu_epi32(test_vec[11].r));

  a = simde_x_mm256_loadu_epi32(test_vec[12].a);
  r = simde_mm256_ror_epi32(a, INT32_C(          26));
  simde_test_x86_assert_equal_i32x8(r, simde_x_mm256_loadu_epi32(test_vec[12].r));

  a = simde_x_mm256_loadu_epi32(test_vec[13].a);
  r = simde_mm256_ror_epi32(a, INT32_C(           2));
  simde_test_x86_assert_equal_i32x8(r, simde_x_mm256_loadu_epi32(test_vec[13].r));

  a = simde_x_mm256_loadu_epi32(test_vec[14].a);
  r = simde_mm256_ror_epi32(a, INT32_C(          30));
  simde_test_x86_assert_equal_i32x8(r, simde_x_mm256_loadu_epi32(test_vec[14].r));

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m256i a = simde_test_x86_random_i32x8();
    int imm8 = simde_test_codegen_random_i32() & 31;
    simde__m256i r;
    SIMDE_CONSTIFY_256_(simde_mm256_ror_epi32, r, simde_mm256_setzero_si256(), imm8, a);

    simde_test_x86_write_i32x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_i32(2, imm8, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm256_mask_ror_epi32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int32_t src[8];
    const simde__mmask8 k;
    const int32_t a[8];
    int imm8;
    const int32_t r[8];
  } test_vec[] = {
    { {  INT32_C(  1613829334),  INT32_C(  2060176722), -INT32_C(   896733883),  INT32_C(   700077999),  INT32_C(   505116243),  INT32_C(   964940670),  INT32_C(   855528140),  INT32_C(   404126530) },
      UINT8_C(143),
      {  INT32_C(   367098183),  INT32_C(   828005188),  INT32_C(  1071654119),  INT32_C(  1435634398), -INT32_C(   120344539), -INT32_C(  2033972172), -INT32_C(  2033649910),  INT32_C(  1427497229) },
       INT32_C(          90),
      {  INT32_C(  2019447237),  INT32_C(  1452724492), -INT32_C(   133613105),  INT32_C(  1686288277),  INT32_C(   505116243),  INT32_C(   964940670),  INT32_C(   855528140),  INT32_C(  1165509461) } },
    { {  INT32_C(   986694738), -INT32_C(   965103384), -INT32_C(   551875654), -INT32_C(   270995781),  INT32_C(    91593978), -INT32_C(  1584709997),  INT32_C(  2046205983), -INT32_C(   367566697) },
      UINT8_C( 36),
      { -INT32_C(  1777589018), -INT32_C(  1471098211), -INT32_C(   597479186), -INT32_C(  1529392376),  INT32_C(   104389832),  INT32_C(   119920999),  INT32_C(   798990031), -INT32_C(  1672246859) },
       INT32_C(         173),
      {  INT32_C(   986694738), -INT32_C(   965103384), -INT32_C(  2022251751), -INT32_C(   270995781),  INT32_C(    91593978), -INT32_C(   885507794),  INT32_C(  2046205983), -INT32_C(   367566697) } },
    { {  INT32_C(   535986993), -INT32_C(  1141090893),  INT32_C(  1902105512),  INT32_C(   376936367),  INT32_C(  1058905456), -INT32_C(   244401093), -INT32_C(   225590971),  INT32_C(  1379712800) },
      UINT8_C( 66),
      { -INT32_C(  2064289490),  INT32_C(  1076670573), -INT32_C(  1477468912), -INT32_C(  1307048683), -INT32_C(   538093789), -INT32_C(  2027561274),  INT32_C(   732436331), -INT32_C(  2106721708) },
       INT32_C(         107),
      {  INT32_C(   535986993),  INT32_C(   229115286),  INT32_C(  1902105512),  INT32_C(   376936367),  INT32_C(  1058905456), -INT32_C(   244401093), -INT32_C(   312118014),  INT32_C(  1379712800) } },
    { {  INT32_C(   588854035), -INT32_C(   439678512),  INT32_C(   832037646),  INT32_C(     1148218), -INT32_C(   813156765), -INT32_C(  1577439155), -INT32_C(  1792776406), -INT32_C(   563205430) },
      UINT8_C( 93),
      { -INT32_C(  1859255928), -INT32_C(  1348529204),  INT32_C(   820695467),  INT32_C(   412347106), -INT32_C(  1570413966), -INT32_C(   993261732),  INT32_C(  1435394603),  INT32_C(  1488153808) },
       INT32_C(         110),
      {  INT32_C(   102909112), -INT32_C(   439678512),  INT32_C(  1185727403), -INT32_C(  1417125297), -INT32_C(  1983215211), -INT32_C(  1577439155), -INT32_C(  2001906119), -INT32_C(   563205430) } },
    { { -INT32_C(  1612019212),  INT32_C(  1020253274),  INT32_C(   827614142),  INT32_C(   584300997), -INT32_C(   337207104), -INT32_C(   767462398),  INT32_C(  1328280801), -INT32_C(   913763115) },
      UINT8_C(157),
      {  INT32_C(  1207396723), -INT32_C(  1694092488),  INT32_C(  1096890247), -INT32_C(  1442741494), -INT32_C(   575869591),  INT32_C(   582909742), -INT32_C(  1091105366),  INT32_C(   173850775) },
       INT32_C(          41),
      { -INT32_C(  1180435532),  INT32_C(  1020253274), -INT32_C(  1012879205), -INT32_C(  2058026815), -INT32_C(  1259415946), -INT32_C(   767462398),  INT32_C(  1328280801),  INT32_C(  1267019360) } },
    { {  INT32_C(   251484295), -INT32_C(  1722851697),  INT32_C(  1245991393),  INT32_C(  1814622270),  INT32_C(   428795503), -INT32_C(  1948744204),  INT32_C(  1872049221),  INT32_C(   248637319) },
      UINT8_C( 63),
      {  INT32_C(   768482766), -INT32_C(  1123129236), -INT32_C(  1661249108),  INT32_C(  1728866177),  INT32_C(  2052793845),  INT32_C(   834725629),  INT32_C(  1673080700), -INT32_C(   828127488) },
       INT32_C(         228),
      { -INT32_C(   488840740), -INT32_C(   875501946), -INT32_C(   909134438),  INT32_C(   376489592),  INT32_C(  1470476895), -INT32_C(   753136017),  INT32_C(  1872049221),  INT32_C(   248637319) } },
    { { -INT32_C(  2062677287), -INT32_C(   467531165),  INT32_C(  1732980337),  INT32_C(  1373742931),  INT32_C(   159555981), -INT32_C(   798147632), -INT32_C(   409006077),  INT32_C(  1530436225) },
      UINT8_C(164),
      {  INT32_C(  1359470663),  INT32_C(   818080514), -INT32_C(   561764041), -INT32_C(  1402219253), -INT32_C(  1820494505), -INT32_C(   225030686), -INT32_C(  2022474260), -INT32_C(    47460682) },
       INT32_C(         175),
      { -INT32_C(  2062677287), -INT32_C(   467531165),  INT32_C(  1383054600),  INT32_C(  1373742931),  INT32_C(   159555981), -INT32_C(  1681529556), -INT32_C(   409006077), -INT32_C(  1653736873) } },
    { {  INT32_C(  1440878622),  INT32_C(  1160996410), -INT32_C(  1829658821), -INT32_C(   165319148), -INT32_C(  1461142596), -INT32_C(   282109127), -INT32_C(   638821590), -INT32_C(  1400227186) },
      UINT8_C( 74),
      { -INT32_C(   763100564), -INT32_C(   737294027),  INT32_C(   703111355), -INT32_C(  2115641659),  INT32_C(   582651590),  INT32_C(   407677373), -INT32_C(   811194987),  INT32_C(   471421871) },
       INT32_C(          85),
      {  INT32_C(  1440878622),  INT32_C(  1850322592), -INT32_C(  1829658821),  INT32_C(   787885071), -INT32_C(  1461142596), -INT32_C(   282109127),  INT32_C(   825011837), -INT32_C(  1400227186) } },
    { { -INT32_C(  1728238468), -INT32_C(   207364584),  INT32_C(    99080620), -INT32_C(  1750881838),  INT32_C(  1821682379),  INT32_C(   908881750),  INT32_C(   981906995),  INT32_C(   672976812) },
      UINT8_C(252),
      { -INT32_C(   149635047),  INT32_C(  1017382755), -INT32_C(  1743869457), -INT32_C(   144464308), -INT32_C(  1454518214), -INT32_C(  1277393924), -INT32_C(   648079862),  INT32_C(  1289062195) },
       INT32_C(           7),
      { -INT32_C(  1728238468), -INT32_C(   207364584), -INT32_C(   550494893), -INT32_C(  1712404660),  INT32_C(  1968348064), -INT32_C(   110642937),  INT32_C(   364035628),  INT32_C(  1721346830) } },
    { { -INT32_C(   521737999), -INT32_C(   579275375), -INT32_C(   707470181), -INT32_C(  1468128852), -INT32_C(  1352967515), -INT32_C(  1534543247), -INT32_C(  1997513151),  INT32_C(   942814279) },
      UINT8_C( 28),
      {  INT32_C(   246224921),  INT32_C(  1839827857), -INT32_C(  2129035681),  INT32_C(  1445380604), -INT32_C(   674769635), -INT32_C(  1155962019), -INT32_C(  1878810276), -INT32_C(   307414060) },
       INT32_C(          20),
      { -INT32_C(   521737999), -INT32_C(   579275375), -INT32_C(  1746536431),  INT32_C(  1814021474),  INT32_C(  2102517116), -INT32_C(  1534543247), -INT32_C(  1997513151),  INT32_C(   942814279) } },
    { {  INT32_C(  1163044069),  INT32_C(   516320034),  INT32_C(  1232399404),  INT32_C(   505494721),  INT32_C(    64633511), -INT32_C(  1349198373),  INT32_C(  1822179608), -INT32_C(  2125359205) },
      UINT8_C( 59),
      {  INT32_C(   241026723),  INT32_C(  2017164172),  INT32_C(   741967088), -INT32_C(   539797595),  INT32_C(   247191345), -INT32_C(  1406702997), -INT32_C(  1639476473), -INT32_C(  1998927643) },
       INT32_C(          14),
      {  INT32_C(   445397367), -INT32_C(   298721043),  INT32_C(  1232399404),  INT32_C(  1586986829),  INT32_C(  1556364015), -INT32_C(  1448169315),  INT32_C(  1822179608), -INT32_C(  2125359205) } },
    { { -INT32_C(  1550658893), -INT32_C(    53490858),  INT32_C(  1423680035), -INT32_C(   463235463),  INT32_C(   143690241),  INT32_C(    44488733),  INT32_C(   797671584),  INT32_C(  1799955128) },
      UINT8_C(244),
      { -INT32_C(  1488318756),  INT32_C(  2143962845), -INT32_C(  1191633118),  INT32_C(   213507458),  INT32_C(  1177141614), -INT32_C(   387568536), -INT32_C(   643820105),  INT32_C(  1003293535) },
       INT32_C(          25),
      { -INT32_C(  1550658893), -INT32_C(    53490858),  INT32_C(  2089783644), -INT32_C(   463235463),  INT32_C(   350271267),  INT32_C(  1930835060), -INT32_C(   804594708), -INT32_C(   427446371) } },
    { { -INT32_C(  2139706018),  INT32_C(  1312321484), -INT32_C(  1168444852),  INT32_C(   453018547),  INT32_C(  1711597487),  INT32_C(  1530897660), -INT32_C(   912913232), -INT32_C(  2101315292) },
      UINT8_C( 38),
      { -INT32_C(  1510866378),  INT32_C(   754008122),  INT32_C(   501263514), -INT32_C(  1815217236), -INT32_C(  1534053377),  INT32_C(  2136271731), -INT32_C(    73196158),  INT32_C(   320939485) },
       INT32_C(           7),
      { -INT32_C(  2139706018),  INT32_C(  1952047744),  INT32_C(   876331353),  INT32_C(   453018547),  INT32_C(  1711597487), -INT32_C(   419517994), -INT32_C(   912913232), -INT32_C(  2101315292) } },
    { { -INT32_C(   309417389),  INT32_C(    34238038),  INT32_C(  1771493226),  INT32_C(  2114790923), -INT32_C(  1812111087),  INT32_C(  1552851327), -INT32_C(   294604858),  INT32_C(   357574850) },
      UINT8_C(210),
      {  INT32_C(  1294467806), -INT32_C(   457757939), -INT32_C(   403758911), -INT32_C(  1879544530),  INT32_C(   202280043), -INT32_C(   892179686),  INT32_C(    59556059), -INT32_C(   271146480) },
       INT32_C(           4),
      { -INT32_C(   309417389), -INT32_C(   565480784),  INT32_C(  1771493226),  INT32_C(  2114790923), -INT32_C(  1329534778),  INT32_C(  1552851327), -INT32_C(  1338455027),  INT32_C(   251488801) } },
    { { -INT32_C(   359206103),  INT32_C(  1104250131),  INT32_C(  1590807283),  INT32_C(  1886052182),  INT32_C(   624573514),  INT32_C(   220841981),  INT32_C(   234684265),  INT32_C(   666843389) },
      UINT8_C( 43),
      { -INT32_C(   633401003), -INT32_C(  1379041053),  INT32_C(   822291281), -INT32_C(   763661419),  INT32_C(  1976541614), -INT32_C(   908141366),  INT32_C(   298249177), -INT32_C(    12718678) },
       INT32_C(          31),
      { -INT32_C(  1266802005),  INT32_C(  1536885191),  INT32_C(  1590807283), -INT32_C(  1527322837),  INT32_C(   624573514), -INT32_C(  1816282731),  INT32_C(   234684265),  INT32_C(   666843389) } },
  };

  simde__m256i src, a, r;

  #if !(defined(HEDLEY_MSVC_VERSION) && defined(SIMDE_X86_AVX512F_NATIVE) && defined(SIMDE_X86_AVX512VL_NATIVE))
  src = simde_x_mm256_loadu_epi32(test_vec[0].src);
  a = simde_x_mm256_loadu_epi32(test_vec[0].a);
  r = simde_mm256_mask_ror_epi32(src, test_vec[0].k, a, INT32_C(          90));
  simde_test_x86_assert_equal_i32x8(r, simde_x_mm256_loadu_epi32(test_vec[0].r));

  src = simde_x_mm256_loadu_epi32(test_vec[1].src);
  a = simde_x_mm256_loadu_epi32(test_vec[1].a);
  r = simde_mm256_mask_ror_epi32(src, test_vec[1].k, a, INT32_C(         173));
  simde_test_x86_assert_equal_i32x8(r, simde_x_mm256_loadu_epi32(test_vec[1].r));

  src = simde_x_mm256_loadu_epi32(test_vec[2].src);
  a = simde_x_mm256_loadu_epi32(test_vec[2].a);
  r = simde_mm256_mask_ror_epi32(src, test_vec[2].k, a, INT32_C(         107));
  simde_test_x86_assert_equal_i32x8(r, simde_x_mm256_loadu_epi32(test_vec[2].r));

  src = simde_x_mm256_loadu_epi32(test_vec[3].src);
  a = simde_x_mm256_loadu_epi32(test_vec[3].a);
  r = simde_mm256_mask_ror_epi32(src, test_vec[3].k, a, INT32_C(         110));
  simde_test_x86_assert_equal_i32x8(r, simde_x_mm256_loadu_epi32(test_vec[3].r));

  src = simde_x_mm256_loadu_epi32(test_vec[4].src);
  a = simde_x_mm256_loadu_epi32(test_vec[4].a);
  r = simde_mm256_mask_ror_epi32(src, test_vec[4].k, a, INT32_C(          41));
  simde_test_x86_assert_equal_i32x8(r, simde_x_mm256_loadu_epi32(test_vec[4].r));

  src = simde_x_mm256_loadu_epi32(test_vec[5].src);
  a = simde_x_mm256_loadu_epi32(test_vec[5].a);
  r = simde_mm256_mask_ror_epi32(src, test_vec[5].k, a, INT32_C(         228));
  simde_test_x86_assert_equal_i32x8(r, simde_x_mm256_loadu_epi32(test_vec[5].r));

  src = simde_x_mm256_loadu_epi32(test_vec[6].src);
  a = simde_x_mm256_loadu_epi32(test_vec[6].a);
  r = simde_mm256_mask_ror_epi32(src, test_vec[6].k, a, INT32_C(         175));
  simde_test_x86_assert_equal_i32x8(r, simde_x_mm256_loadu_epi32(test_vec[6].r));

  src = simde_x_mm256_loadu_epi32(test_vec[7].src);
  a = simde_x_mm256_loadu_epi32(test_vec[7].a);
  r = simde_mm256_mask_ror_epi32(src, test_vec[7].k, a, INT32_C(          85));
  simde_test_x86_assert_equal_i32x8(r, simde_x_mm256_loadu_epi32(test_vec[7].r));
  #endif

  src = simde_x_mm256_loadu_epi32(test_vec[8].src);
  a = simde_x_mm256_loadu_epi32(test_vec[8].a);
  r = simde_mm256_mask_ror_epi32(src, test_vec[8].k, a, INT32_C(           7));
  simde_test_x86_assert_equal_i32x8(r, simde_x_mm256_loadu_epi32(test_vec[8].r));

  src = simde_x_mm256_loadu_epi32(test_vec[9].src);
  a = simde_x_mm256_loadu_epi32(test_vec[9].a);
  r = simde_mm256_mask_ror_epi32(src, test_vec[9].k, a, INT32_C(          20));
  simde_test_x86_assert_equal_i32x8(r, simde_x_mm256_loadu_epi32(test_vec[9].r));

  src = simde_x_mm256_loadu_epi32(test_vec[10].src);
  a = simde_x_mm256_loadu_epi32(test_vec[10].a);
  r = simde_mm256_mask_ror_epi32(src, test_vec[10].k, a, INT32_C(          14));
  simde_test_x86_assert_equal_i32x8(r, simde_x_mm256_loadu_epi32(test_vec[10].r));

  src = simde_x_mm256_loadu_epi32(test_vec[11].src);
  a = simde_x_mm256_loadu_epi32(test_vec[11].a);
  r = simde_mm256_mask_ror_epi32(src, test_vec[11].k, a, INT32_C(          25));
  simde_test_x86_assert_equal_i32x8(r, simde_x_mm256_loadu_epi32(test_vec[11].r));

  src = simde_x_mm256_loadu_epi32(test_vec[12].src);
  a = simde_x_mm256_loadu_epi32(test_vec[12].a);
  r = simde_mm256_mask_ror_epi32(src, test_vec[12].k, a, INT32_C(           7));
  simde_test_x86_assert_equal_i32x8(r, simde_x_mm256_loadu_epi32(test_vec[12].r));

  src = simde_x_mm256_loadu_epi32(test_vec[13].src);
  a = simde_x_mm256_loadu_epi32(test_vec[13].a);
  r = simde_mm256_mask_ror_epi32(src, test_vec[13].k, a, INT32_C(           4));
  simde_test_x86_assert_equal_i32x8(r, simde_x_mm256_loadu_epi32(test_vec[13].r));

  src = simde_x_mm256_loadu_epi32(test_vec[14].src);
  a = simde_x_mm256_loadu_epi32(test_vec[14].a);
  r = simde_mm256_mask_ror_epi32(src, test_vec[14].k, a, INT32_C(          31));
  simde_test_x86_assert_equal_i32x8(r, simde_x_mm256_loadu_epi32(test_vec[14].r));

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m256i src = simde_test_x86_random_i32x8();
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m256i a = simde_test_x86_random_i32x8();
    int imm8 = simde_test_codegen_random_i32() & 31;
    simde__m256i r;
    SIMDE_CONSTIFY_256_(simde_mm256_mask_ror_epi32, r, simde_mm256_setzero_si256(), imm8, src, k, a);

    simde_test_x86_write_i32x8(2, src, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x8(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, imm8, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm256_maskz_ror_epi32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask8 k;
    const int32_t a[8];
    int imm8;
    const int32_t r[8];
  } test_vec[] = {
    { UINT8_C(103),
      { -INT32_C(  1675468804),  INT32_C(   643910727), -INT32_C(  1074994639),  INT32_C(  1165823644),  INT32_C(  2145031514), -INT32_C(  1892701892),  INT32_C(  1642351555),  INT32_C(   902327865) },
       INT32_C(         205),
      { -INT32_C(     1777390),  INT32_C(  1647915786),  INT32_C(   294518631),  INT32_C(           0),  INT32_C(           0),  INT32_C(  1239710077),  INT32_C(  1578831650),  INT32_C(           0) } },
    { UINT8_C( 55),
      {  INT32_C(   359152435),  INT32_C(   917645351),  INT32_C(   982579109),  INT32_C(  2071335122), -INT32_C(  1975646913),  INT32_C(  1489215465),  INT32_C(  1394997608), -INT32_C(    41272630) },
       INT32_C(         117),
      {  INT32_C(  1104779435), -INT32_C(  1857996363), -INT32_C(  2017646124),  INT32_C(           0), -INT32_C(   265683887),  INT32_C(   486492870),  INT32_C(           0),  INT32_C(           0) } },
    { UINT8_C( 26),
      { -INT32_C(  1128279099),  INT32_C(  1938750051),  INT32_C(  1991379568), -INT32_C(   396411832), -INT32_C(   112150784),  INT32_C(   398697437),  INT32_C(   529383725), -INT32_C(  1724241196) },
       INT32_C(         253),
      {  INT32_C(           0), -INT32_C(  1669868773),  INT32_C(           0),  INT32_C(  1123672647), -INT32_C(   897206265),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0) } },
    { UINT8_C(243),
      { -INT32_C(   295381788), -INT32_C(  1019815290), -INT32_C(   238870983),  INT32_C(   298761326),  INT32_C(  1077863807), -INT32_C(  1676386702), -INT32_C(  1852199528), -INT32_C(   410650109) },
       INT32_C(         206),
      {  INT32_C(  1402190227),  INT32_C(  1780157659),  INT32_C(           0),  INT32_C(           0), -INT32_C(  1778581253),  INT32_C(  2043310161), -INT32_C(  1235073434), -INT32_C(   401629673) } },
    { UINT8_C(195),
      {  INT32_C(   721164043), -INT32_C(  1768362534), -INT32_C(  1592350021),  INT32_C(  1175672552),  INT32_C(   417247339),  INT32_C(  1125871689), -INT32_C(   569310475), -INT32_C(   475961641) },
       INT32_C(         125),
      {  INT32_C(  1474345049), -INT32_C(  1261998380),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(   259516498),  INT32_C(   487274175) } },
    { UINT8_C(139),
      {  INT32_C(  1330048677),  INT32_C(  1530455812), -INT32_C(  1413054725), -INT32_C(   839590307), -INT32_C(    54380294), -INT32_C(  1345019831), -INT32_C(   567429311),  INT32_C(  1768523204) },
       INT32_C(         115),
      { -INT32_C(   573265432),  INT32_C(   484477799),  INT32_C(           0), -INT32_C(  1681147458),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(   817401133) } },
    { UINT8_C(151),
      {  INT32_C(  1871893489),  INT32_C(  2009873817),  INT32_C(  1785829682), -INT32_C(    72126885), -INT32_C(   113482942),  INT32_C(   364714896),  INT32_C(   881337988), -INT32_C(   791936801) },
       INT32_C(         211),
      {  INT32_C(  1518218738), -INT32_C(  2018300167),  INT32_C(   858148174),  INT32_C(           0), -INT32_C(  1939316953),  INT32_C(           0),  INT32_C(           0), -INT32_C(  2145650151) } },
    { UINT8_C(156),
      { -INT32_C(  1496390644), -INT32_C(  1023330219),  INT32_C(  1309015531),  INT32_C(  1423900217), -INT32_C(   489032773),  INT32_C(  2093026684),  INT32_C(   944804569), -INT32_C(   556483374) },
       INT32_C(         160),
      {  INT32_C(           0),  INT32_C(           0),  INT32_C(  1309015531),  INT32_C(  1423900217), -INT32_C(   489032773),  INT32_C(           0),  INT32_C(           0), -INT32_C(   556483374) } },
    { UINT8_C(212),
      { -INT32_C(  1201167334), -INT32_C(   612498291), -INT32_C(   916960633),  INT32_C(  1692191241),  INT32_C(  1432091679), -INT32_C(   716257115), -INT32_C(   841442734), -INT32_C(   442421301) },
       INT32_C(          19),
      {  INT32_C(           0),  INT32_C(           0),  INT32_C(   156301611),  INT32_C(           0),  INT32_C(  2139351723),  INT32_C(           0),  INT32_C(   323639739),  INT32_C(   637107380) } },
    { UINT8_C( 13),
      {  INT32_C(  1721056027),  INT32_C(  1584357012),  INT32_C(   914215738), -INT32_C(   153300434), -INT32_C(  1152863967), -INT32_C(  1199171959), -INT32_C(  1064604489),  INT32_C(   634317577) },
       INT32_C(           7),
      {  INT32_C(   919415414),  INT32_C(           0),  INT32_C(  1953299366),  INT32_C(  1575860644),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0) } },
    { UINT8_C(193),
      { -INT32_C(   839116294),  INT32_C(  1778070167), -INT32_C(  1081413362),  INT32_C(  1330202169),  INT32_C(   939983308),  INT32_C(  2017642381), -INT32_C(   123770987), -INT32_C(   323331342) },
       INT32_C(          20),
      { -INT32_C(  1046500129),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(   159817847), -INT32_C(  1515245877) } },
    { UINT8_C(232),
      { -INT32_C(  1510509388),  INT32_C(  1172223743),  INT32_C(    17903359), -INT32_C(    57783755), -INT32_C(   208533876),  INT32_C(    15043238), -INT32_C(    93007548),  INT32_C(  1055096714) },
       INT32_C(          20),
      {  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(   459055160),  INT32_C(           0),  INT32_C(  1487560718),  INT32_C(  1293176743),  INT32_C(   939041774) } },
    { UINT8_C(144),
      { -INT32_C(   275760959), -INT32_C(  1826320055),  INT32_C(   622797087),  INT32_C(  1036718771), -INT32_C(   930951945), -INT32_C(  1068336064),  INT32_C(   968134751),  INT32_C(   902473587) },
       INT32_C(          31),
      {  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(  1861903889),  INT32_C(           0),  INT32_C(           0),  INT32_C(  1804947174) } },
    { UINT8_C(235),
      {  INT32_C(  1779088457), -INT32_C(   300077093), -INT32_C(   941270277),  INT32_C(  1493675740), -INT32_C(  1850161408),  INT32_C(   570749563),  INT32_C(   369179068), -INT32_C(  1493095842) },
       INT32_C(           6),
      {  INT32_C(   631778033),  INT32_C(  1874359487),  INT32_C(           0),  INT32_C(  1902386875),  INT32_C(           0), -INT32_C(   326626359), -INT32_C(   262667034),  INT32_C(  2057045161) } },
    { UINT8_C( 58),
      { -INT32_C(  2009747666),  INT32_C(  1130757269), -INT32_C(   884752892),  INT32_C(  1749537910),  INT32_C(   304376281), -INT32_C(  1787807125),  INT32_C(  1182471995),  INT32_C(  1451310120) },
       INT32_C(          12),
      {  INT32_C(           0), -INT32_C(   917227937),  INT32_C(           0),  INT32_C(  1197900925), -INT32_C(  1651432890), -INT32_C(  1497803005),  INT32_C(           0),  INT32_C(           0) } },
    { UINT8_C(179),
      {  INT32_C(    45597764), -INT32_C(   596082169),  INT32_C(   867557833),  INT32_C(  1084147461),  INT32_C(  1333474104), -INT32_C(   361184594), -INT32_C(   103363005), -INT32_C(   240363603) },
       INT32_C(          27),
      {  INT32_C(  1459128448), -INT32_C(  1894760197),  INT32_C(           0),  INT32_C(           0), -INT32_C(   278501623),  INT32_C(  1326994909),  INT32_C(           0),  INT32_C(   898299326) } },
  };

  simde__m256i a, r;

  #if !(defined(HEDLEY_MSVC_VERSION) && defined(SIMDE_X86_AVX512F_NATIVE) && defined(SIMDE_X86_AVX512VL_NATIVE))
  a = simde_x_mm256_loadu_epi32(test_vec[0].a);
  r = simde_mm256_maskz_ror_epi32(test_vec[0].k, a, INT32_C(         205));
  simde_test_x86_assert_equal_i32x8(r, simde_x_mm256_loadu_epi32(test_vec[0].r));

  a = simde_x_mm256_loadu_epi32(test_vec[1].a);
  r = simde_mm256_maskz_ror_epi32(test_vec[1].k, a, INT32_C(         117));
  simde_test_x86_assert_equal_i32x8(r, simde_x_mm256_loadu_epi32(test_vec[1].r));

  a = simde_x_mm256_loadu_epi32(test_vec[2].a);
  r = simde_mm256_maskz_ror_epi32(test_vec[2].k, a, INT32_C(         253));
  simde_test_x86_assert_equal_i32x8(r, simde_x_mm256_loadu_epi32(test_vec[2].r));

  a = simde_x_mm256_loadu_epi32(test_vec[3].a);
  r = simde_mm256_maskz_ror_epi32(test_vec[3].k, a, INT32_C(         206));
  simde_test_x86_assert_equal_i32x8(r, simde_x_mm256_loadu_epi32(test_vec[3].r));

  a = simde_x_mm256_loadu_epi32(test_vec[4].a);
  r = simde_mm256_maskz_ror_epi32(test_vec[4].k, a, INT32_C(         125));
  simde_test_x86_assert_equal_i32x8(r, simde_x_mm256_loadu_epi32(test_vec[4].r));

  a = simde_x_mm256_loadu_epi32(test_vec[5].a);
  r = simde_mm256_maskz_ror_epi32(test_vec[5].k, a, INT32_C(         115));
  simde_test_x86_assert_equal_i32x8(r, simde_x_mm256_loadu_epi32(test_vec[5].r));

  a = simde_x_mm256_loadu_epi32(test_vec[6].a);
  r = simde_mm256_maskz_ror_epi32(test_vec[6].k, a, INT32_C(         211));
  simde_test_x86_assert_equal_i32x8(r, simde_x_mm256_loadu_epi32(test_vec[6].r));

  a = simde_x_mm256_loadu_epi32(test_vec[7].a);
  r = simde_mm256_maskz_ror_epi32(test_vec[7].k, a, INT32_C(         160));
  simde_test_x86_assert_equal_i32x8(r, simde_x_mm256_loadu_epi32(test_vec[7].r));
  #endif

  a = simde_x_mm256_loadu_epi32(test_vec[8].a);
  r = simde_mm256_maskz_ror_epi32(test_vec[8].k, a, INT32_C(          19));
  simde_test_x86_assert_equal_i32x8(r, simde_x_mm256_loadu_epi32(test_vec[8].r));

  a = simde_x_mm256_loadu_epi32(test_vec[9].a);
  r = simde_mm256_maskz_ror_epi32(test_vec[9].k, a, INT32_C(           7));
  simde_test_x86_assert_equal_i32x8(r, simde_x_mm256_loadu_epi32(test_vec[9].r));

  a = simde_x_mm256_loadu_epi32(test_vec[10].a);
  r = simde_mm256_maskz_ror_epi32(test_vec[10].k, a, INT32_C(          20));
  simde_test_x86_assert_equal_i32x8(r, simde_x_mm256_loadu_epi32(test_vec[10].r));

  a = simde_x_mm256_loadu_epi32(test_vec[11].a);
  r = simde_mm256_maskz_ror_epi32(test_vec[11].k, a, INT32_C(          20));
  simde_test_x86_assert_equal_i32x8(r, simde_x_mm256_loadu_epi32(test_vec[11].r));

  a = simde_x_mm256_loadu_epi32(test_vec[12].a);
  r = simde_mm256_maskz_ror_epi32(test_vec[12].k, a, INT32_C(          31));
  simde_test_x86_assert_equal_i32x8(r, simde_x_mm256_loadu_epi32(test_vec[12].r));

  a = simde_x_mm256_loadu_epi32(test_vec[13].a);
  r = simde_mm256_maskz_ror_epi32(test_vec[13].k, a, INT32_C(           6));
  simde_test_x86_assert_equal_i32x8(r, simde_x_mm256_loadu_epi32(test_vec[13].r));

  a = simde_x_mm256_loadu_epi32(test_vec[14].a);
  r = simde_mm256_maskz_ror_epi32(test_vec[14].k, a, INT32_C(          12));
  simde_test_x86_assert_equal_i32x8(r, simde_x_mm256_loadu_epi32(test_vec[14].r));

  a = simde_x_mm256_loadu_epi32(test_vec[15].a);
  r = simde_mm256_maskz_ror_epi32(test_vec[15].k, a, INT32_C(          27));
  simde_test_x86_assert_equal_i32x8(r, simde_x_mm256_loadu_epi32(test_vec[15].r));

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m256i a = simde_test_x86_random_i32x8();
    int imm8 = simde_test_codegen_random_i32() & 31;
    simde__m256i r;
    SIMDE_CONSTIFY_256_(simde_mm256_maskz_ror_epi32, r, simde_mm256_setzero_si256(), imm8, k, a);

    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i32x8(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, imm8, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm512_ror_epi32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int32_t a[16];
    int imm8;
    const int32_t r[16];
  } test_vec[] = {
    { {  INT32_C(   280861125), -INT32_C(   429048913),  INT32_C(   456615782), -INT32_C(  1125330313), -INT32_C(  1798475067),  INT32_C(  1908198400), -INT32_C(    92208755), -INT32_C(    66921161),
         INT32_C(   621658230),  INT32_C(  1628142331),  INT32_C(  1501315810), -INT32_C(   636131051), -INT32_C(   613489957),  INT32_C(  1011690158),  INT32_C(  1664536107),  INT32_C(   559888811) },
       INT32_C(         249),
      {  INT32_C(  1590485640),  INT32_C(   916314099), -INT32_C(  1682722035),  INT32_C(  1986608094),  INT32_C(  1723425482), -INT32_C(   563740616),  INT32_C(  1082181373),  INT32_C(    24026110),
        -INT32_C(  2032125166), -INT32_C(  2051179088), -INT32_C(  1105104596),  INT32_C(   179604205), -INT32_C(  1217303059),  INT32_C(   647321374), -INT32_C(  1687743055), -INT32_C(  1348676208) } },
    { { -INT32_C(   917155097), -INT32_C(  1440558699),  INT32_C(   377763642), -INT32_C(   923667943),  INT32_C(  1208237596), -INT32_C(  1196738035),  INT32_C(  1826228851),  INT32_C(  1583358327),
         INT32_C(   136820083), -INT32_C(  1045280377), -INT32_C(  1713949056),  INT32_C(  1164036392),  INT32_C(   344810759),  INT32_C(   332216480), -INT32_C(  1182750910),  INT32_C(   991420616) },
       INT32_C(         150),
      {  INT32_C(  1431019301), -INT32_C(  1958324568),  INT32_C(   282912858), -INT32_C(   943167709),  INT32_C(   284717344), -INT32_C(  1394067742),  INT32_C(  1747570099), -INT32_C(  2138710663),
        -INT32_C(  1630155744), -INT32_C(   920248570),  INT32_C(  1557791335), -INT32_C(  2027642603),  INT32_C(   898899026),  INT32_C(   887259215),  INT32_C(    43846374),  INT32_C(  1602429164) } },
    { {  INT32_C(   132052615),  INT32_C(  1436661293), -INT32_C(  2036727169),  INT32_C(   144385896), -INT32_C(  1575262113), -INT32_C(   681862385),  INT32_C(   303199100),  INT32_C(   959403697),
         INT32_C(  2051018061),  INT32_C(  1120920003),  INT32_C(  1288268516), -INT32_C(   246127471), -INT32_C(   611094580), -INT32_C(  2018316789),  INT32_C(   328844385),  INT32_C(  1749862427) },
       INT32_C(         213),
      { -INT32_C(   139184066),  INT32_C(   229730989), -INT32_C(   803996620), -INT32_C(   650428348), -INT32_C(   616366832), -INT32_C(   589791558), -INT32_C(  1818500976),  INT32_C(  2058717641),
         INT32_C(     6974418),  INT32_C(  2131630614),  INT32_C(  1264001638), -INT32_C(  1557885046), -INT32_C(  1686214948), -INT32_C(  1754244035), -INT32_C(   836564836),  INT32_C(  1715526466) } },
    { {  INT32_C(  1390129518), -INT32_C(  1382112229), -INT32_C(   727780856),  INT32_C(  1823420769), -INT32_C(  2114756321),  INT32_C(  1100254246),  INT32_C(   715776084), -INT32_C(   624718996),
         INT32_C(  1479319100),  INT32_C(  1258670659),  INT32_C(   505455548), -INT32_C(   209006636),  INT32_C(  1467252273),  INT32_C(  1603799050),  INT32_C(  1435058664),  INT32_C(   137317580) },
       INT32_C(         234),
      {  INT32_C(  1536472812),  INT32_C(   116090793), -INT32_C(  2110445636),  INT32_C(  1482369996),  INT32_C(  1205894360),  INT32_C(   160458019),  INT32_C(   353020536), -INT32_C(   617172766),
        -INT32_C(  1894380761), -INT32_C(  1865236110), -INT32_C(   284719064), -INT32_C(   180559181), -INT32_C(  1940529889),  INT32_C(    43509250),  INT32_C(  2048221776),  INT32_C(   855772115) } },
    { { -INT32_C(   478583514), -INT32_C(   603875064), -INT32_C(  1714386072),  INT32_C(   351290377),  INT32_C(   896763981), -INT32_C(  1786053431),  INT32_C(   849263176),  INT32_C(  1012989462),
         INT32_C(  1814026596), -INT32_C(   632741774), -INT32_C(  1250682452), -INT32_C(  1429642147), -INT32_C(  1226818323), -INT32_C(  2142475720),  INT32_C(   984869412),  INT32_C(  1282872296) },
       INT32_C(         236),
      {  INT32_C(  1382954902), -INT32_C(  1869758439), -INT32_C(  1232495352),  INT32_C(  1083264772), -INT32_C(  2066524360), -INT32_C(   862365521), -INT32_C(  1534907925), -INT32_C(   513554929),
        -INT32_C(  1773747715),  INT32_C(   120431762), -INT32_C(  1697949887),  INT32_C(  1171958934), -INT32_C(   824480253), -INT32_C(  1551366970), -INT32_C(  1572623554),  INT32_C(  1048889201) } },
    { {  INT32_C(  1664615095),  INT32_C(  2014882843), -INT32_C(    31202799),  INT32_C(  1471415070), -INT32_C(  1831403411), -INT32_C(   741569814), -INT32_C(  1994439779), -INT32_C(  1847076646),
        -INT32_C(   168550182), -INT32_C(   579990324),  INT32_C(   232493550),  INT32_C(    23367828),  INT32_C(  2073246608),  INT32_C(  1666080966),  INT32_C(  2112712099),  INT32_C(   537842758) },
       INT32_C(         244),
      { -INT32_C(  2144635341), -INT32_C(  1967016063),  INT32_C(  1042358242),  INT32_C(  1077011835),  INT32_C(  1879497005), -INT32_C(   928076484), -INT32_C(   197535599),  INT32_C(  2106435870),
         INT32_C(  1108193119), -INT32_C(   523448874), -INT32_C(  1189158691),  INT32_C(  1225342998),  INT32_C(   867764153), -INT32_C(   435395020), -INT32_C(   690341922), -INT32_C(   314285568) } },
    { { -INT32_C(    39943153), -INT32_C(  1458931179), -INT32_C(  1700106742),  INT32_C(  1880440490),  INT32_C(  1104372638),  INT32_C(   398442705), -INT32_C(  1992831595), -INT32_C(   548778544),
        -INT32_C(   421729839),  INT32_C(  1838147427), -INT32_C(    16303531),  INT32_C(   376380792),  INT32_C(  1364673408), -INT32_C(  1738009085), -INT32_C(  1272799004), -INT32_C(  1080857363) },
       INT32_C(          85),
      { -INT32_C(   199196692),  INT32_C(  1406184776),  INT32_C(  1399870677), -INT32_C(  1443540096), -INT32_C(  1692601842), -INT32_C(    33126211), -INT32_C(  1100174263),  INT32_C(  1382975226),
        -INT32_C(   414281930),  INT32_C(  2134580076),  INT32_C(   970108920),  INT32_C(  2028716211), -INT32_C(  1172569462),  INT32_C(  1085283523),  INT32_C(   352789921), -INT32_C(  1687720452) } },
    { { -INT32_C(  1406847658), -INT32_C(   408212113), -INT32_C(   889382070),  INT32_C(  1629246558),  INT32_C(  1341817963),  INT32_C(   302193700), -INT32_C(   556689784),  INT32_C(  1553364485),
         INT32_C(   436780203),  INT32_C(   855749609),  INT32_C(   754843342), -INT32_C(  1097983661), -INT32_C(  1039300450),  INT32_C(   752095396), -INT32_C(  1425365594), -INT32_C(   955801316) },
       INT32_C(          93),
      {  INT32_C(  1630120629),  INT32_C(  1029270399),  INT32_C(  1474878038),  INT32_C(   149070579),  INT32_C(  2144609114), -INT32_C(  1877417696), -INT32_C(   158550970), -INT32_C(   457986006),
        -INT32_C(   800725672), -INT32_C(  1743937719),  INT32_C(  1743779441), -INT32_C(   193934691),  INT32_C(   275530998),  INT32_C(  1721795873),  INT32_C(  1481977141),  INT32_C(   943524070) } },
    { { -INT32_C(  1342214938),  INT32_C(  1390589005), -INT32_C(  1282244485),  INT32_C(  1627590323),  INT32_C(   323779536), -INT32_C(   150199735), -INT32_C(  1779910278),  INT32_C(    45669404),
        -INT32_C(  1783449784), -INT32_C(   404253589), -INT32_C(   929400299),  INT32_C(  1479187848),  INT32_C(  1651209752),  INT32_C(   307853208),  INT32_C(  1302872368),  INT32_C(  1699700765) },
       INT32_C(          24),
      { -INT32_C(     9640273), -INT32_C(   491500206), -INT32_C(  1837073485),  INT32_C(    51295073),  INT32_C(  1283182611),  INT32_C(   203573751), -INT32_C(   390497643), -INT32_C(  1193534462),
        -INT32_C(  1296611179), -INT32_C(   409703449), -INT32_C(  1703275064),  INT32_C(   714967128),  INT32_C(  1802901602),  INT32_C(  1501009938), -INT32_C(  1472122803),  INT32_C(  1331699045) } },
    { { -INT32_C(  1419058538), -INT32_C(   462224036), -INT32_C(  1153655390), -INT32_C(  1407342829),  INT32_C(  1337882142), -INT32_C(   711170377), -INT32_C(   549786681), -INT32_C(  2090715667),
         INT32_C(  1932446999),  INT32_C(  1951900114),  INT32_C(  1378849599),  INT32_C(  1493060666),  INT32_C(  2057813442), -INT32_C(   363904221),  INT32_C(   482969903), -INT32_C(   710988610) },
       INT32_C(          25),
      { -INT32_C(  1250866347),  INT32_C(   964865650), -INT32_C(  1639001763),  INT32_C(   248744406), -INT32_C(   549777625), -INT32_C(   835494934), -INT32_C(  1653218321), -INT32_C(  1323632959),
        -INT32_C(  1754887239),  INT32_C(   735111482),  INT32_C(   399089577),  INT32_C(  2133204268),  INT32_C(  1407115581),  INT32_C(   664900085),  INT32_C(  1690605454), -INT32_C(   812228758) } },
    { { -INT32_C(  1388339346),  INT32_C(  1811967794),  INT32_C(  2126905019), -INT32_C(   537367365), -INT32_C(   540457040), -INT32_C(  1879338032), -INT32_C(  1201366337), -INT32_C(   712790681),
         INT32_C(  2139341388), -INT32_C(   303332559),  INT32_C(  1030467713), -INT32_C(   853777635),  INT32_C(  2058151338),  INT32_C(   923379576), -INT32_C(  1460703679),  INT32_C(  1736274459) },
       INT32_C(          21),
      { -INT32_C(    50629271),  INT32_C(    58299232),  INT32_C(   804641782), -INT32_C(  1016733953),  INT32_C(  1245546238), -INT32_C(   593591169),  INT32_C(   618003907),  INT32_C(   493567660),
         INT32_C(   504521724),  INT32_C(  1545178991),  INT32_C(  1568934379), -INT32_C(   484905368),  INT32_C(  1731023829),  INT32_C(  1295761848),  INT32_C(  2071072071), -INT32_C(   342828229) } },
    { {  INT32_C(    89379459), -INT32_C(  1623015806), -INT32_C(   882090463), -INT32_C(  1136256957),  INT32_C(    15945663), -INT32_C(   660020291), -INT32_C(  1975507371), -INT32_C(  1427036634),
         INT32_C(  2075084024),  INT32_C(   605745411), -INT32_C(  1829730481),  INT32_C(  1598961311),  INT32_C(  1130316421),  INT32_C(  2048591909),  INT32_C(  1409637166),  INT32_C(  2063529602) },
       INT32_C(          26),
      {  INT32_C(  1425318081), -INT32_C(   793796441), -INT32_C(   619214734),  INT32_C(   293998831),  INT32_C(  1020522432),  INT32_C(   708374390), -INT32_C(  1878420126), -INT32_C(  1136031318),
        -INT32_C(   338608610),  INT32_C(   113000649), -INT32_C(  1138633756), -INT32_C(   745691177), -INT32_C(   674193072), -INT32_C(  2034103970),  INT32_C(    22465429), -INT32_C(  1078091618) } },
    { { -INT32_C(   312340322),  INT32_C(   914379415),  INT32_C(   227921544),  INT32_C(   894498064),  INT32_C(   732982525),  INT32_C(  1233106375), -INT32_C(   440107349), -INT32_C(   903628501),
         INT32_C(  1622640073),  INT32_C(  1603745751),  INT32_C(   376187910),  INT32_C(   508345633), -INT32_C(   263586775),  INT32_C(  1547356593),  INT32_C(  1916927559), -INT32_C(  2126748489) },
       INT32_C(           9),
      {  INT32_C(  1333178632),  INT32_C(  1268465705),  INT32_C(  1141295847), -INT32_C(  2011518854),  INT32_C(  2123749430), -INT32_C(   475742246),  INT32_C(  1441980991), -INT32_C(  1780149796),
        -INT32_C(   458204222), -INT32_C(   340800613),  INT32_C(    51066390), -INT32_C(  1869666722),  INT32_C(   351806718), -INT32_C(   659677852),  INT32_C(   599335167),  INT32_C(  1539350066) } },
    { {  INT32_C(   824145963), -INT32_C(   968323931),  INT32_C(  1927648329),  INT32_C(  1096953488),  INT32_C(  1050516727),  INT32_C(  1387388570),  INT32_C(   752086339),  INT32_C(   233682145),
        -INT32_C(   767685587), -INT32_C(   510097768), -INT32_C(  1437369062), -INT32_C(  1544833364), -INT32_C(   303921070), -INT32_C(  1438674073),  INT32_C(  1658196608), -INT32_C(   210779194) },
       INT32_C(          16),
      {  INT32_C(  2016096543), -INT32_C(  1935292856), -INT32_C(  1807125787),  INT32_C(   781205858), -INT32_C(  1661518179), -INT32_C(   560311631), -INT32_C(   314364717), -INT32_C(  1260319251),
         INT32_C(   204329534), -INT32_C(  2036801128),  INT32_C(  2098899539), -INT32_C(  1230199829), -INT32_C(  2007831070), -INT32_C(  1821922753),  INT32_C(   310403798), -INT32_C(  1010371729) } },
    { {  INT32_C(  1313496628), -INT32_C(  2013684261), -INT32_C(  1507072941), -INT32_C(   728560275),  INT32_C(   545182368), -INT32_C(  1434299164), -INT32_C(   392236776), -INT32_C(   749706337),
        -INT32_C(  1658742079), -INT32_C(  1960568264),  INT32_C(  1815171071), -INT32_C(    62864292),  INT32_C(  2048769686),  INT32_C(   707108626),  INT32_C(   806536081), -INT32_C(   402431194) },
       INT32_C(          29),
      {  INT32_C(  1918038434),  INT32_C(  1070395100),  INT32_C(   828318365), -INT32_C(  1533514898),  INT32_C(    66491649),  INT32_C(  1410508581),  INT32_C(  1157073095), -INT32_C(  1702683394),
        -INT32_C(   385034740),  INT32_C(  1495323076),  INT32_C(  1636466683), -INT32_C(   502914329), -INT32_C(   789711693),  INT32_C(  1361901713), -INT32_C(  2137645943),  INT32_C(  1075517751) } },
    { {  INT32_C(  1052879167),  INT32_C(  1437266681),  INT32_C(  1297279671), -INT32_C(  1161269336), -INT32_C(  1612321522), -INT32_C(   691013712),  INT32_C(  1488900698),  INT32_C(   915227639),
        -INT32_C(   428585235), -INT32_C(   130343359), -INT32_C(  1337619192),  INT32_C(   191499772), -INT32_C(  1431678982), -INT32_C(  1585350073),  INT32_C(  1140408140),  INT32_C(  1887012739) },
       INT32_C(          21),
      {  INT32_C(   222951926),  INT32_C(  1469565613), -INT32_C(  1755989398),  INT32_C(  1132283350),  INT32_C(   795374847),  INT32_C(  2143127222), -INT32_C(   158149947),  INT32_C(  1780464052),
        -INT32_C(  1569231053), -INT32_C(   655224895),  INT32_C(   745031042),  INT32_C(  1349509211),  INT32_C(  1384109397),  INT32_C(   198327564), -INT32_C(   906337761), -INT32_C(   868476029) } },
  };

  simde__m512i a, r;

  #if !(defined(HEDLEY_MSVC_VERSION) && defined(SIMDE_X86_AVX512F_NATIVE) && defined(SIMDE_X86_AVX512VL_NATIVE))
  a = simde_mm512_loadu_epi32(test_vec[0].a);
  r = simde_mm512_ror_epi32(a, INT32_C(         249));
  simde_test_x86_assert_equal_i32x16(r, simde_mm512_loadu_epi32(test_vec[0].r));

  a = simde_mm512_loadu_epi32(test_vec[1].a);
  r = simde_mm512_ror_epi32(a, INT32_C(         150));
  simde_test_x86_assert_equal_i32x16(r, simde_mm512_loadu_epi32(test_vec[1].r));

  a = simde_mm512_loadu_epi32(test_vec[2].a);
  r = simde_mm512_ror_epi32(a, INT32_C(         213));
  simde_test_x86_assert_equal_i32x16(r, simde_mm512_loadu_epi32(test_vec[2].r));

  a = simde_mm512_loadu_epi32(test_vec[3].a);
  r = simde_mm512_ror_epi32(a, INT32_C(         234));
  simde_test_x86_assert_equal_i32x16(r, simde_mm512_loadu_epi32(test_vec[3].r));

  a = simde_mm512_loadu_epi32(test_vec[4].a);
  r = simde_mm512_ror_epi32(a, INT32_C(         236));
  simde_test_x86_assert_equal_i32x16(r, simde_mm512_loadu_epi32(test_vec[4].r));

  a = simde_mm512_loadu_epi32(test_vec[5].a);
  r = simde_mm512_ror_epi32(a, INT32_C(         244));
  simde_test_x86_assert_equal_i32x16(r, simde_mm512_loadu_epi32(test_vec[5].r));

  a = simde_mm512_loadu_epi32(test_vec[6].a);
  r = simde_mm512_ror_epi32(a, INT32_C(          85));
  simde_test_x86_assert_equal_i32x16(r, simde_mm512_loadu_epi32(test_vec[6].r));

  a = simde_mm512_loadu_epi32(test_vec[7].a);
  r = simde_mm512_ror_epi32(a, INT32_C(          93));
  simde_test_x86_assert_equal_i32x16(r, simde_mm512_loadu_epi32(test_vec[7].r));
  #endif

  a = simde_mm512_loadu_epi32(test_vec[8].a);
  r = simde_mm512_ror_epi32(a, INT32_C(          24));
  simde_test_x86_assert_equal_i32x16(r, simde_mm512_loadu_epi32(test_vec[8].r));

  a = simde_mm512_loadu_epi32(test_vec[9].a);
  r = simde_mm512_ror_epi32(a, INT32_C(          25));
  simde_test_x86_assert_equal_i32x16(r, simde_mm512_loadu_epi32(test_vec[9].r));

  a = simde_mm512_loadu_epi32(test_vec[10].a);
  r = simde_mm512_ror_epi32(a, INT32_C(          21));
  simde_test_x86_assert_equal_i32x16(r, simde_mm512_loadu_epi32(test_vec[10].r));

  a = simde_mm512_loadu_epi32(test_vec[11].a);
  r = simde_mm512_ror_epi32(a, INT32_C(          26));
  simde_test_x86_assert_equal_i32x16(r, simde_mm512_loadu_epi32(test_vec[11].r));

  a = simde_mm512_loadu_epi32(test_vec[12].a);
  r = simde_mm512_ror_epi32(a, INT32_C(           9));
  simde_test_x86_assert_equal_i32x16(r, simde_mm512_loadu_epi32(test_vec[12].r));

  a = simde_mm512_loadu_epi32(test_vec[13].a);
  r = simde_mm512_ror_epi32(a, INT32_C(          16));
  simde_test_x86_assert_equal_i32x16(r, simde_mm512_loadu_epi32(test_vec[13].r));

  a = simde_mm512_loadu_epi32(test_vec[14].a);
  r = simde_mm512_ror_epi32(a, INT32_C(          29));
  simde_test_x86_assert_equal_i32x16(r, simde_mm512_loadu_epi32(test_vec[14].r));

  a = simde_mm512_loadu_epi32(test_vec[15].a);
  r = simde_mm512_ror_epi32(a, INT32_C(          21));
  simde_test_x86_assert_equal_i32x16(r, simde_mm512_loadu_epi32(test_vec[15].r));

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m512i a = simde_test_x86_random_i32x16();
    int imm8 = simde_test_codegen_random_i32() & 31;
    simde__m512i r;
    SIMDE_CONSTIFY_256_(simde_mm512_ror_epi32, r, simde_mm512_setzero_si512(), imm8, a);

    simde_test_x86_write_i32x16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_i32(2, imm8, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm512_mask_ror_epi32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int32_t src[16];
    const simde__mmask16 k;
    const int32_t a[16];
    int imm8;
    const int32_t r[16];
  } test_vec[] = {
    { {  INT32_C(   685770063),  INT32_C(  1475105933),  INT32_C(   402711521),  INT32_C(  1047173561),  INT32_C(  1481139352), -INT32_C(   265577236), -INT32_C(   400161937), -INT32_C(  1004727179),
        -INT32_C(  1494418151),  INT32_C(   872274257),  INT32_C(  1984691644),  INT32_C(   783594902),  INT32_C(   109509914),  INT32_C(   150385305),  INT32_C(   737222069),  INT32_C(  1257180721) },
      UINT16_C(56332),
      { -INT32_C(   306881040), -INT32_C(   588549744), -INT32_C(  1668185625),  INT32_C(   916040624), -INT32_C(  1461177679),  INT32_C(   734371386), -INT32_C(  1204095287),  INT32_C(   815023680),
         INT32_C(   874334627), -INT32_C(  1576007493),  INT32_C(   977183114), -INT32_C(    26159283),  INT32_C(  1151752457), -INT32_C(  1066439689), -INT32_C(  1585927839), -INT32_C(  1815015953) },
       INT32_C(          86),
      {  INT32_C(   685770063),  INT32_C(  1475105933),  INT32_C(  1174904434),  INT32_C(  1722728666),  INT32_C(  1481139352), -INT32_C(   265577236), -INT32_C(   400161937), -INT32_C(  1004727179),
        -INT32_C(  1494418151),  INT32_C(   872274257), -INT32_C(    91871000), -INT32_C(  1017300999), -INT32_C(  1721490158),  INT32_C(   150385305), -INT32_C(   492468603),  INT32_C(  1144503887) } },
    { { -INT32_C(  2118854665), -INT32_C(   977538440), -INT32_C(   742118198),  INT32_C(  2081909381),  INT32_C(   926713814),  INT32_C(   551138352),  INT32_C(   414427841), -INT32_C(  1859552615),
        -INT32_C(   921510575), -INT32_C(  1701851440),  INT32_C(  2137871354), -INT32_C(  1812232771),  INT32_C(  1019950860), -INT32_C(  1386437397), -INT32_C(   389738674), -INT32_C(   629543287) },
      UINT16_C(35788),
      {  INT32_C(   861510820), -INT32_C(  1551477962), -INT32_C(   852999214), -INT32_C(  1576782633), -INT32_C(   850988943),  INT32_C(  1658688669), -INT32_C(   179280260), -INT32_C(   444523455),
        -INT32_C(   300361032),  INT32_C(     9608750), -INT32_C(  1194411295),  INT32_C(  1616564975),  INT32_C(  1596825794), -INT32_C(  1312749003), -INT32_C(  1297673615), -INT32_C(   409524178) },
       INT32_C(           2),
      { -INT32_C(  2118854665), -INT32_C(   977538440), -INT32_C(  1286991628), -INT32_C(   394195659),  INT32_C(   926713814),  INT32_C(   551138352),  INT32_C(  1028921759),  INT32_C(  2036352784),
         INT32_C(   998651566), -INT32_C(  2145081461),  INT32_C(  2137871354), -INT32_C(   669600581),  INT32_C(  1019950860), -INT32_C(  1386437397), -INT32_C(   389738674), -INT32_C(  1176122869) } },
    { {  INT32_C(   774989645),  INT32_C(   300416802), -INT32_C(  1804516911),  INT32_C(   401841890),  INT32_C(   449361321), -INT32_C(   171151417), -INT32_C(  1696832617),  INT32_C(  1607119378),
         INT32_C(   999160601), -INT32_C(   867404550), -INT32_C(  1738490442),  INT32_C(    95376220), -INT32_C(   820021496),  INT32_C(  2126900199),  INT32_C(  1612226894),  INT32_C(  1841292115) },
      UINT16_C(19678),
      { -INT32_C(   171845208),  INT32_C(    95582117), -INT32_C(  1101525489),  INT32_C(   842359059), -INT32_C(   182641616), -INT32_C(  1281922149), -INT32_C(  1969820981),  INT32_C(    14120279),
        -INT32_C(   202008498),  INT32_C(   519612175), -INT32_C(   908308298), -INT32_C(   486796879), -INT32_C(   908650194),  INT32_C(  1350332037), -INT32_C(  1327819943), -INT32_C(   693063032) },
       INT32_C(          74),
      {  INT32_C(   774989645), -INT32_C(   381588323), -INT32_C(  2081450493),  INT32_C(  1154256216),  INT32_C(   205342535), -INT32_C(   171151417), -INT32_C(  1293769286),  INT32_C(  1438660061),
         INT32_C(   999160601), -INT32_C(   867404550),  INT32_C(   766670612),  INT32_C(  1819852548), -INT32_C(   820021496),  INT32_C(  2126900199), -INT32_C(   697551164),  INT32_C(  1841292115) } },
    { {  INT32_C(    58179917), -INT32_C(  1010019567), -INT32_C(  1834629020),  INT32_C(  1734048994),  INT32_C(  1152899307),  INT32_C(  1945408235), -INT32_C(  1907776188), -INT32_C(  1746464182),
        -INT32_C(   459645229),  INT32_C(   380069809),  INT32_C(   296242223), -INT32_C(  1267202871), -INT32_C(   940035876),  INT32_C(   121302210), -INT32_C(   594181231),  INT32_C(  1752399253) },
      UINT16_C( 3803),
      { -INT32_C(   193622708),  INT32_C(  1262527651),  INT32_C(   776931766), -INT32_C(  1252119619),  INT32_C(   748823026), -INT32_C(  1112591576), -INT32_C(  2093333489), -INT32_C(   107931988),
         INT32_C(  1189938851),  INT32_C(  1620127146), -INT32_C(   191897289), -INT32_C(     5575412),  INT32_C(   908807182), -INT32_C(  1879778433), -INT32_C(   871223777), -INT32_C(   406478012) },
       INT32_C(         169),
      { -INT32_C(  1501939002),  INT32_C(  1369808978), -INT32_C(  1834629020), -INT32_C(   556093675), -INT32_C(   115977968),  INT32_C(  1945408235),  INT32_C(   130129186),  INT32_C(  1451018379),
        -INT32_C(   459645229), -INT32_C(   718255978), -INT32_C(  1678096400), -INT32_C(  2038442634), -INT32_C(   940035876),  INT32_C(   121302210), -INT32_C(   594181231),  INT32_C(  1752399253) } },
    { {  INT32_C(   380944351), -INT32_C(  1408547936),  INT32_C(  1068217648), -INT32_C(  2139760895), -INT32_C(   787519054), -INT32_C(   593682024),  INT32_C(  1841586884), -INT32_C(   188616428),
         INT32_C(  1342862768), -INT32_C(   386067016), -INT32_C(   886593334),  INT32_C(   827104639), -INT32_C(  1643947258),  INT32_C(  1098621053),  INT32_C(   397360899), -INT32_C(   519344080) },
      UINT16_C( 5861),
      {  INT32_C(   774610225), -INT32_C(  1378355579),  INT32_C(   222975681), -INT32_C(  1956032376),  INT32_C(  1781262063), -INT32_C(   693555673),  INT32_C(  1363597638), -INT32_C(   328782918),
         INT32_C(  1310364616),  INT32_C(  1258025353), -INT32_C(   799521464), -INT32_C(  2074361451), -INT32_C(   823228761), -INT32_C(    73033803),  INT32_C(   726461297), -INT32_C(   552094697) },
       INT32_C(          71),
      {  INT32_C(  1650218810), -INT32_C(  1408547936), -INT32_C(  2112187219), -INT32_C(  2139760895), -INT32_C(   787519054),  INT32_C(  1336758876), -INT32_C(  1935503950),  INT32_C(  1977142871),
         INT32_C(  1342862768),  INT32_C(   311818211), -INT32_C(  1851740022),  INT32_C(   827104639),  INT32_C(  1335745805),  INT32_C(  1098621053),  INT32_C(   397360899), -INT32_C(   519344080) } },
    { {  INT32_C(  1796876323),  INT32_C(    54227565), -INT32_C(   628648397), -INT32_C(   760646115),  INT32_C(  2127384077),  INT32_C(  1353324857),  INT32_C(   338739661),  INT32_C(   400842227),
        -INT32_C(   209518714), -INT32_C(  1510556047),  INT32_C(  1904180820),  INT32_C(    21178612), -INT32_C(  1333784458), -INT32_C(   150984150), -INT32_C(   552849173),  INT32_C(   351727758) },
      UINT16_C(30959),
      { -INT32_C(    29990649), -INT32_C(  2055435514),  INT32_C(  1085174012), -INT32_C(   246406031), -INT32_C(   719619372),  INT32_C(  2114258802), -INT32_C(   596732954), -INT32_C(  1353425241),
        -INT32_C(   978482241),  INT32_C(   306850070),  INT32_C(   173209753), -INT32_C(   235101411), -INT32_C(  1882843363),  INT32_C(    68013086),  INT32_C(   132152415), -INT32_C(  1716111910) },
       INT32_C(         192),
      { -INT32_C(    29990649), -INT32_C(  2055435514),  INT32_C(  1085174012), -INT32_C(   246406031),  INT32_C(  2127384077),  INT32_C(  2114258802), -INT32_C(   596732954), -INT32_C(  1353425241),
        -INT32_C(   209518714), -INT32_C(  1510556047),  INT32_C(  1904180820), -INT32_C(   235101411), -INT32_C(  1882843363),  INT32_C(    68013086),  INT32_C(   132152415),  INT32_C(   351727758) } },
    { {  INT32_C(   636004492), -INT32_C(  1104200799), -INT32_C(    72406050),  INT32_C(  1636529731), -INT32_C(  1587111870), -INT32_C(   290961900),  INT32_C(   998727291),  INT32_C(  1293018561),
         INT32_C(   796064398),  INT32_C(   334340661),  INT32_C(   269393101),  INT32_C(  1416796434),  INT32_C(  1190582322), -INT32_C(  1707762146), -INT32_C(  1093288707),  INT32_C(   806152098) },
      UINT16_C(32481),
      {  INT32_C(  1277171295),  INT32_C(   938012201),  INT32_C(  1892809726),  INT32_C(  1162347343),  INT32_C(  2128897865), -INT32_C(   700718847), -INT32_C(  1413620321),  INT32_C(  1814732301),
        -INT32_C(   575124812),  INT32_C(   924164152), -INT32_C(   341317989),  INT32_C(   842068201),  INT32_C(  1488000087), -INT32_C(  1792086795), -INT32_C(   700388151),  INT32_C(  1061317258) },
       INT32_C(         181),
      {  INT32_C(    11729505), -INT32_C(  1104200799), -INT32_C(    72406050),  INT32_C(  1636529731), -INT32_C(  1587111870), -INT32_C(   553120079), -INT32_C(   286458531),  INT32_C(  1425042273),
         INT32_C(   796064398), -INT32_C(  1392393800),  INT32_C(  1060429661), -INT32_C(  2021176943), -INT32_C(  2002601275),  INT32_C(  2003283113),  INT32_C(   124145330),  INT32_C(   806152098) } },
    { {  INT32_C(   908341658),  INT32_C(     2214935),  INT32_C(   322130364),  INT32_C(  1533797478), -INT32_C(  1712285232),  INT32_C(   275722629),  INT32_C(  1347400091),  INT32_C(  1161718699),
        -INT32_C(  1266982243), -INT32_C(   357196754),  INT32_C(  1425926382), -INT32_C(  1666225972), -INT32_C(  2026528766),  INT32_C(  1821877457),  INT32_C(    12445269), -INT32_C(   280626350) },
      UINT16_C(49501),
      {  INT32_C(  1482525859),  INT32_C(  1950370678),  INT32_C(  1339821215), -INT32_C(   571482456), -INT32_C(    41828250), -INT32_C(   370878932),  INT32_C(   484718294), -INT32_C(   925023707),
         INT32_C(  1143028430),  INT32_C(   632840582),  INT32_C(   376739182), -INT32_C(   638295181),  INT32_C(  1356297507),  INT32_C(   574208844),  INT32_C(   373169905),  INT32_C(   786307936) },
       INT32_C(          86),
      {  INT32_C(  1983024481),  INT32_C(     2214935),  INT32_C(  1882357055), -INT32_C(  1082481801),  INT32_C(   117545974),  INT32_C(   275722629), -INT32_C(  1864673165),  INT32_C(  1161718699),
        -INT32_C(  2064959216), -INT32_C(   357196754),  INT32_C(  1425926382), -INT32_C(  1666225972), -INT32_C(  2026528766),  INT32_C(  1821877457), -INT32_C(   126106536),  INT32_C(  2020442299) } },
    { {  INT32_C(   319721739),  INT32_C(   465785887),  INT32_C(  1546006113), -INT32_C(  1006186115), -INT32_C(  1754888373),  INT32_C(  1255890887), -INT32_C(  1128639258),  INT32_C(  1305612354),
        -INT32_C(  1067327071), -INT32_C(  1763957707), -INT32_C(   789446062),  INT32_C(   513079763),  INT32_C(  1203174016),  INT32_C(  1083281754),  INT32_C(   670845925), -INT32_C(    42610853) },
      UINT16_C(54960),
      { -INT32_C(  1711610435),  INT32_C(  1855737211), -INT32_C(  1318621411),  INT32_C(  1152182158), -INT32_C(  1059781073),  INT32_C(  1124907590),  INT32_C(  1460824034),  INT32_C(   573424228),
         INT32_C(   582690727), -INT32_C(  1852811404),  INT32_C(  1430517703),  INT32_C(   244969439),  INT32_C(  1003384565),  INT32_C(   176085544), -INT32_C(  1503555518), -INT32_C(   104296878) },
       INT32_C(          22),
      {  INT32_C(   319721739),  INT32_C(   465785887),  INT32_C(  1546006113), -INT32_C(  1006186115),  INT32_C(  1410907907),  INT32_C(   854137100), -INT32_C(  1128639258), -INT32_C(  1224109944),
        -INT32_C(  1067327071),  INT32_C(  1096667718),  INT32_C(   266280277),  INT32_C(   513079763),  INT32_C(   968611055),  INT32_C(  1083281754), -INT32_C(  2042557799),  INT32_C(   574180327) } },
    { { -INT32_C(  1564693285), -INT32_C(  2080899164), -INT32_C(   476999442),  INT32_C(   656302078),  INT32_C(  2083626298), -INT32_C(  2145217747), -INT32_C(   679875807),  INT32_C(  1241683311),
        -INT32_C(   420626878), -INT32_C(  1419123523),  INT32_C(  1938750069), -INT32_C(  1818579879),  INT32_C(  1997524041), -INT32_C(  2131283361), -INT32_C(  1940361187),  INT32_C(  1222007302) },
      UINT16_C(49944),
      { -INT32_C(  1750543058),  INT32_C(   244391296),  INT32_C(   733670032), -INT32_C(  1913191298),  INT32_C(  1925142139),  INT32_C(   786619606),  INT32_C(  1065937000),  INT32_C(  1577230384),
        -INT32_C(   168449419),  INT32_C(  1476626119), -INT32_C(   276578703),  INT32_C(  1031568066), -INT32_C(  1498465072), -INT32_C(  2116710120), -INT32_C(  1430233734),  INT32_C(  1930019582) },
       INT32_C(          13),
      { -INT32_C(  1564693285), -INT32_C(  2080899164), -INT32_C(   476999442),  INT32_C(   603221944), -INT32_C(  1277454854), -INT32_C(  2145217747), -INT32_C(   679875807),  INT32_C(  1241683311),
         INT32_C(  1404022701),  INT32_C(   909819932),  INT32_C(  1938750069), -INT32_C(  1818579879),  INT32_C(  1997524041), -INT32_C(  2131283361), -INT32_C(   338340350),  INT32_C(   401840206) } },
    { { -INT32_C(   158569339), -INT32_C(   320532694),  INT32_C(  1495884169), -INT32_C(  1241458531), -INT32_C(   466102934),  INT32_C(   814675762),  INT32_C(   648320953),  INT32_C(   458952086),
        -INT32_C(  1542330503), -INT32_C(  2137983241), -INT32_C(   170214825), -INT32_C(    55846254), -INT32_C(   505355601), -INT32_C(  1844285479), -INT32_C(  1665550842),  INT32_C(  1018631363) },
      UINT16_C(51451),
      {  INT32_C(  1908339424),  INT32_C(  1294669427), -INT32_C(  1238909685), -INT32_C(  1701259590), -INT32_C(   922127945), -INT32_C(  1132523517),  INT32_C(  1691370156),  INT32_C(  1596771455),
         INT32_C(   835775422),  INT32_C(   209648385),  INT32_C(  1942136249),  INT32_C(   856513147), -INT32_C(   822339637), -INT32_C(   745833433),  INT32_C(  1027038142), -INT32_C(   425892825) },
       INT32_C(          15),
      { -INT32_C(   440343683),  INT32_C(   753310294),  INT32_C(  1495884169), -INT32_C(  1384827599), -INT32_C(   479227374),  INT32_C(   537360638), -INT32_C(  2057778784), -INT32_C(  1728135591),
        -INT32_C(  1542330503), -INT32_C(  2137983241), -INT32_C(   170214825), -INT32_C(  1258920422), -INT32_C(   505355601), -INT32_C(  1844285479), -INT32_C(  1216578962), -INT32_C(   934294214) } },
    { {  INT32_C(   576493161), -INT32_C(  1214964165),  INT32_C(  1139450488), -INT32_C(   535697735),  INT32_C(   565484642),  INT32_C(   526314488), -INT32_C(  1643775153), -INT32_C(   756146839),
        -INT32_C(   285979981), -INT32_C(   526022296), -INT32_C(   450654421), -INT32_C(   658164362), -INT32_C(   906397231), -INT32_C(  1259775899), -INT32_C(  1135350189), -INT32_C(  1097973493) },
      UINT16_C(33420),
      {  INT32_C(  1376515245), -INT32_C(   119392299), -INT32_C(   517122020),  INT32_C(   710672176), -INT32_C(  1316831032), -INT32_C(   945760908),  INT32_C(   537504658),  INT32_C(   396596586),
         INT32_C(  1583984265),  INT32_C(    22498277), -INT32_C(   723286877),  INT32_C(  1291730563),  INT32_C(  1929216254), -INT32_C(   415589035), -INT32_C(  1291304119),  INT32_C(  1640672216) },
       INT32_C(          25),
      {  INT32_C(   576493161), -INT32_C(  1214964165), -INT32_C(  1767109008),  INT32_C(   771725333),  INT32_C(   565484642),  INT32_C(   526314488), -INT32_C(  1643775153), -INT32_C(   775244533),
        -INT32_C(   285979981), -INT32_C(  1415187840), -INT32_C(   450654421), -INT32_C(   658164362), -INT32_C(   906397231), -INT32_C(  1259775899), -INT32_C(  1135350189), -INT32_C(   447353808) } },
    { {  INT32_C(   574625663),  INT32_C(   536224667),  INT32_C(  1600910433), -INT32_C(   892180364),  INT32_C(  1337003014),  INT32_C(   654489935), -INT32_C(  1098331036),  INT32_C(  2130528511),
        -INT32_C(    73319073), -INT32_C(  1038444703),  INT32_C(     2262412), -INT32_C(   204802835),  INT32_C(  1329757184), -INT32_C(  1703525323),  INT32_C(   274267664), -INT32_C(  1500621497) },
      UINT16_C(12178),
      { -INT32_C(  1144523871), -INT32_C(   666872906),  INT32_C(   516697683),  INT32_C(  1687866401), -INT32_C(  1851207909), -INT32_C(  1047545495),  INT32_C(  1461114569),  INT32_C(   512207229),
         INT32_C(  1390038684), -INT32_C(   198567263),  INT32_C(  1779627592), -INT32_C(   573657918), -INT32_C(   445745540), -INT32_C(   123208145),  INT32_C(  1364245972),  INT32_C(    57726822) },
       INT32_C(           5),
      {  INT32_C(   574625663), -INT32_C(  1228799331),  INT32_C(  1600910433), -INT32_C(   892180364), -INT32_C(   594721160),  INT32_C(   654489935), -INT32_C(  1098331036), -INT32_C(   386646709),
        -INT32_C(   493432204),  INT32_C(   262230229),  INT32_C(  1129355186),  INT32_C(   384726374),  INT32_C(  1329757184),  INT32_C(  2143633393),  INT32_C(   274267664), -INT32_C(  1500621497) } },
    { { -INT32_C(  1380286364),  INT32_C(   957861238), -INT32_C(   183048839), -INT32_C(  1948547749),  INT32_C(  1468236419), -INT32_C(  1498819777), -INT32_C(   811001430), -INT32_C(   946471325),
        -INT32_C(   176926594), -INT32_C(  1775334627), -INT32_C(   863222672),  INT32_C(  1280796617),  INT32_C(   681892585),  INT32_C(  1489915310), -INT32_C(   920094874), -INT32_C(   191840906) },
      UINT16_C( 1293),
      {  INT32_C(   395324137),  INT32_C(  1297875393),  INT32_C(   615785933),  INT32_C(   385785202), -INT32_C(  1805407035),  INT32_C(   755747077),  INT32_C(   585793938),  INT32_C(  1596455030),
        -INT32_C(   478693342), -INT32_C(  2043620423),  INT32_C(  1789584632),  INT32_C(  1199614081),  INT32_C(  1524360021),  INT32_C(  1049093804), -INT32_C(   564039320), -INT32_C(  1942124439) },
       INT32_C(           0),
      {  INT32_C(   395324137),  INT32_C(   957861238),  INT32_C(   615785933),  INT32_C(   385785202),  INT32_C(  1468236419), -INT32_C(  1498819777), -INT32_C(   811001430), -INT32_C(   946471325),
        -INT32_C(   478693342), -INT32_C(  1775334627),  INT32_C(  1789584632),  INT32_C(  1280796617),  INT32_C(   681892585),  INT32_C(  1489915310), -INT32_C(   920094874), -INT32_C(   191840906) } },
    { { -INT32_C(  2139119481),  INT32_C(   116009348),  INT32_C(   659385298), -INT32_C(    75421618),  INT32_C(  1983449102), -INT32_C(   480994695),  INT32_C(  1668256291), -INT32_C(   832709050),
         INT32_C(    55499902), -INT32_C(   670484474), -INT32_C(   218147165), -INT32_C(  1930592130),  INT32_C(    16983688), -INT32_C(   454797375),  INT32_C(   809980905), -INT32_C(  1325489102) },
      UINT16_C(19585),
      { -INT32_C(  1132165197),  INT32_C(  1578248287),  INT32_C(   132026394),  INT32_C(   539846173),  INT32_C(  1282928231),  INT32_C(   446652882), -INT32_C(  1883319919),  INT32_C(   903561090),
         INT32_C(   636641222), -INT32_C(  1585249145), -INT32_C(  1297587819),  INT32_C(   802346695), -INT32_C(  1753527868),  INT32_C(  1001462442),  INT32_C(  1858760684),  INT32_C(  1973659055) },
       INT32_C(           5),
      { -INT32_C(  1645992899),  INT32_C(   116009348),  INT32_C(   659385298), -INT32_C(    75421618),  INT32_C(  1983449102), -INT32_C(   480994695),  INT32_C(  1668256291),  INT32_C(   296671740),
         INT32_C(    55499902), -INT32_C(   670484474), -INT32_C(  1382726900),  INT32_C(   964597430),  INT32_C(    16983688), -INT32_C(   454797375),  INT32_C(  1668699007), -INT32_C(  1325489102) } },
  };

  simde__m512i src, a, r;

  #if !(defined(HEDLEY_MSVC_VERSION) && defined(SIMDE_X86_AVX512F_NATIVE) && defined(SIMDE_X86_AVX512VL_NATIVE))
  src = simde_mm512_loadu_epi32(test_vec[0].src);
  a = simde_mm512_loadu_epi32(test_vec[0].a);
  r = simde_mm512_mask_ror_epi32(src, test_vec[0].k, a, INT32_C(          86));
  simde_test_x86_assert_equal_i32x16(r, simde_mm512_loadu_epi32(test_vec[0].r));
  #endif

  src = simde_mm512_loadu_epi32(test_vec[1].src);
  a = simde_mm512_loadu_epi32(test_vec[1].a);
  r = simde_mm512_mask_ror_epi32(src, test_vec[1].k, a, INT32_C(           2));
  simde_test_x86_assert_equal_i32x16(r, simde_mm512_loadu_epi32(test_vec[1].r));

  #if !(defined(HEDLEY_MSVC_VERSION) && defined(SIMDE_X86_AVX512F_NATIVE) && defined(SIMDE_X86_AVX512VL_NATIVE))
  src = simde_mm512_loadu_epi32(test_vec[2].src);
  a = simde_mm512_loadu_epi32(test_vec[2].a);
  r = simde_mm512_mask_ror_epi32(src, test_vec[2].k, a, INT32_C(          74));
  simde_test_x86_assert_equal_i32x16(r, simde_mm512_loadu_epi32(test_vec[2].r));

  src = simde_mm512_loadu_epi32(test_vec[3].src);
  a = simde_mm512_loadu_epi32(test_vec[3].a);
  r = simde_mm512_mask_ror_epi32(src, test_vec[3].k, a, INT32_C(         169));
  simde_test_x86_assert_equal_i32x16(r, simde_mm512_loadu_epi32(test_vec[3].r));

  src = simde_mm512_loadu_epi32(test_vec[4].src);
  a = simde_mm512_loadu_epi32(test_vec[4].a);
  r = simde_mm512_mask_ror_epi32(src, test_vec[4].k, a, INT32_C(          71));
  simde_test_x86_assert_equal_i32x16(r, simde_mm512_loadu_epi32(test_vec[4].r));

  src = simde_mm512_loadu_epi32(test_vec[5].src);
  a = simde_mm512_loadu_epi32(test_vec[5].a);
  r = simde_mm512_mask_ror_epi32(src, test_vec[5].k, a, INT32_C(         192));
  simde_test_x86_assert_equal_i32x16(r, simde_mm512_loadu_epi32(test_vec[5].r));

  src = simde_mm512_loadu_epi32(test_vec[6].src);
  a = simde_mm512_loadu_epi32(test_vec[6].a);
  r = simde_mm512_mask_ror_epi32(src, test_vec[6].k, a, INT32_C(         181));
  simde_test_x86_assert_equal_i32x16(r, simde_mm512_loadu_epi32(test_vec[6].r));

  src = simde_mm512_loadu_epi32(test_vec[7].src);
  a = simde_mm512_loadu_epi32(test_vec[7].a);
  r = simde_mm512_mask_ror_epi32(src, test_vec[7].k, a, INT32_C(          86));
  simde_test_x86_assert_equal_i32x16(r, simde_mm512_loadu_epi32(test_vec[7].r));
  #endif

  src = simde_mm512_loadu_epi32(test_vec[8].src);
  a = simde_mm512_loadu_epi32(test_vec[8].a);
  r = simde_mm512_mask_ror_epi32(src, test_vec[8].k, a, INT32_C(          22));
  simde_test_x86_assert_equal_i32x16(r, simde_mm512_loadu_epi32(test_vec[8].r));

  src = simde_mm512_loadu_epi32(test_vec[9].src);
  a = simde_mm512_loadu_epi32(test_vec[9].a);
  r = simde_mm512_mask_ror_epi32(src, test_vec[9].k, a, INT32_C(          13));
  simde_test_x86_assert_equal_i32x16(r, simde_mm512_loadu_epi32(test_vec[9].r));

  src = simde_mm512_loadu_epi32(test_vec[10].src);
  a = simde_mm512_loadu_epi32(test_vec[10].a);
  r = simde_mm512_mask_ror_epi32(src, test_vec[10].k, a, INT32_C(         15));
  simde_test_x86_assert_equal_i32x16(r, simde_mm512_loadu_epi32(test_vec[10].r));

  src = simde_mm512_loadu_epi32(test_vec[11].src);
  a = simde_mm512_loadu_epi32(test_vec[11].a);
  r = simde_mm512_mask_ror_epi32(src, test_vec[11].k, a, INT32_C(         25));
  simde_test_x86_assert_equal_i32x16(r, simde_mm512_loadu_epi32(test_vec[11].r));

  src = simde_mm512_loadu_epi32(test_vec[12].src);
  a = simde_mm512_loadu_epi32(test_vec[12].a);
  r = simde_mm512_mask_ror_epi32(src, test_vec[12].k, a, INT32_C(           5));
  simde_test_x86_assert_equal_i32x16(r, simde_mm512_loadu_epi32(test_vec[12].r));

  src = simde_mm512_loadu_epi32(test_vec[13].src);
  a = simde_mm512_loadu_epi32(test_vec[13].a);
  r = simde_mm512_mask_ror_epi32(src, test_vec[13].k, a, INT32_C(           0));
  simde_test_x86_assert_equal_i32x16(r, simde_mm512_loadu_epi32(test_vec[13].r));

  src = simde_mm512_loadu_epi32(test_vec[14].src);
  a = simde_mm512_loadu_epi32(test_vec[14].a);
  r = simde_mm512_mask_ror_epi32(src, test_vec[14].k, a, INT32_C(           5));
  simde_test_x86_assert_equal_i32x16(r, simde_mm512_loadu_epi32(test_vec[14].r));

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m512i src = simde_test_x86_random_i32x16();
    simde__mmask16 k = simde_test_x86_random_mmask16();
    simde__m512i a = simde_test_x86_random_i32x16();
    int imm8 = simde_test_codegen_random_i32() & 31;
    simde__m512i r;
    SIMDE_CONSTIFY_256_(simde_mm512_mask_ror_epi32, r, simde_mm512_setzero_si512(), imm8, src, k, a);

    simde_test_x86_write_i32x16(2, src, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_mmask16(2, k, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x16(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, imm8, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm512_maskz_ror_epi32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask16 k;
    const int32_t a[16];
    int imm8;
    const int32_t r[16];
  } test_vec[] = {
    { UINT16_C(11105),
      {  INT32_C(  1992347393), -INT32_C(   640076827), -INT32_C(   464519923), -INT32_C(  2036360371), -INT32_C(    56323907), -INT32_C(  2078866266), -INT32_C(  1518047950),  INT32_C(  1271981385),
        -INT32_C(  1715367756), -INT32_C(   797730109), -INT32_C(   457915753),  INT32_C(   443241309), -INT32_C(  1995042845),  INT32_C(  1175334420), -INT32_C(   437546341),  INT32_C(   724614007) },
       INT32_C(          75),
      { -INT32_C(   533800935),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(  1798274336), -INT32_C(  1504399219),  INT32_C(           0),
         INT32_C(   378746930),  INT32_C(  1484394099),  INT32_C(           0),  INT32_C(  1805864298),  INT32_C(           0), -INT32_C(  1031224891),  INT32_C(           0),  INT32_C(           0) } },
    { UINT16_C(14219),
      { -INT32_C(  1795611681),  INT32_C(  1927763463), -INT32_C(  2021471375),  INT32_C(  1656067668), -INT32_C(   923512356),  INT32_C(  1719888694),  INT32_C(  1532481430), -INT32_C(  1114447138),
         INT32_C(   223448069),  INT32_C(  1400846818),  INT32_C(  1490747652),  INT32_C(  1958449303),  INT32_C(   389853153), -INT32_C(  1317159141),  INT32_C(  1812780174), -INT32_C(  1138057289) },
       INT32_C(          43),
      {  INT32_C(  2079498020), -INT32_C(  1058120470),  INT32_C(           0), -INT32_C(   896772430),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(  1540862556),
        -INT32_C(  2136888783),  INT32_C(  1011511271),  INT32_C(   545987424),  INT32_C(           0), -INT32_C(    64821355), -INT32_C(   478793801),  INT32_C(           0),  INT32_C(           0) } },
    { UINT16_C(18868),
      {  INT32_C(  1011529825), -INT32_C(   858988015), -INT32_C(  1837388202),  INT32_C(  1129420485),  INT32_C(  1410850888),  INT32_C(  1995689548),  INT32_C(  1425153675), -INT32_C(  1919048148),
         INT32_C(  1892280415),  INT32_C(   540841418),  INT32_C(   162707267), -INT32_C(  1773403314),  INT32_C(   820667363), -INT32_C(  1113137614),  INT32_C(   672241916), -INT32_C(  1632260289) },
       INT32_C(         151),
      {  INT32_C(           0),  INT32_C(           0), -INT32_C(   144921308),  INT32_C(           0),  INT32_C(   801149096), -INT32_C(   409167635),  INT32_C(           0),  INT32_C(   994859291),
        -INT32_C(  1815036191),  INT32_C(           0),  INT32_C(           0), -INT32_C(  1744397012),  INT32_C(           0),  INT32_C(           0),  INT32_C(   590477392),  INT32_C(           0) } },
    { UINT16_C(18964),
      {  INT32_C(   855725953), -INT32_C(  1405726880), -INT32_C(   804250907), -INT32_C(   257015222),  INT32_C(   277457663), -INT32_C(  2000697133),  INT32_C(  1946637926),  INT32_C(   951983031),
        -INT32_C(   747913358), -INT32_C(   192962033),  INT32_C(   113545148), -INT32_C(   789155119), -INT32_C(   253657315), -INT32_C(  1384603577), -INT32_C(  1373536265),  INT32_C(   233299866) },
       INT32_C(         159),
      {  INT32_C(           0),  INT32_C(           0), -INT32_C(  1608501813),  INT32_C(           0),  INT32_C(   554915326),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),
         INT32_C(           0), -INT32_C(   385924065),  INT32_C(           0), -INT32_C(  1578310237),  INT32_C(           0),  INT32_C(           0),  INT32_C(  1547894767),  INT32_C(           0) } },
    { UINT16_C(24564),
      {  INT32_C(  1743761570), -INT32_C(  1378238282),  INT32_C(  1915549329),  INT32_C(  1595045094),  INT32_C(  1138624801), -INT32_C(  1625130568),  INT32_C(  1727119750),  INT32_C(   314959471),
         INT32_C(  1299821718),  INT32_C(   117068405),  INT32_C(   796403273), -INT32_C(  1131509094),  INT32_C(  1291808148),  INT32_C(  1827348966),  INT32_C(  1389550819),  INT32_C(  1499764674) },
       INT32_C(          76),
      {  INT32_C(           0),  INT32_C(           0),  INT32_C(  1763123919),  INT32_C(           0), -INT32_C(  1844167200), -INT32_C(  1685458393),  INT32_C(   409366300),  INT32_C(  1727081566),
         INT32_C(  1231345563),  INT32_C(   659582885),  INT32_C(  1687353218), -INT32_C(  1448359704), -INT32_C(   649801738),  INT32_C(           0), -INT32_C(   835375827),  INT32_C(           0) } },
    { UINT16_C(41008),
      {  INT32_C(  1069971911),  INT32_C(   935944616),  INT32_C(   480533789), -INT32_C(  1807906135), -INT32_C(   932110090), -INT32_C(   681626765),  INT32_C(   850766732),  INT32_C(   869459308),
         INT32_C(   108173662),  INT32_C(   389889274),  INT32_C(  1127473561),  INT32_C(  1641508971),  INT32_C(    69814417),  INT32_C(   148605308), -INT32_C(  1589931980), -INT32_C(   741077643) },
       INT32_C(         166),
      {  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(   618543997), -INT32_C(   815956787),  INT32_C(           0),  INT32_C(           0),
         INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(   266113499),  INT32_C(           0), -INT32_C(   682667979) } },
    { UINT16_C( 6019),
      { -INT32_C(   352772937),  INT32_C(   928736351), -INT32_C(   276828986), -INT32_C(   881263632),  INT32_C(  1063038212),  INT32_C(   575459662),  INT32_C(  2137650085),  INT32_C(  1268182163),
         INT32_C(  1748340489), -INT32_C(  1163947788),  INT32_C(  1823022972),  INT32_C(   506995226),  INT32_C(   492672207),  INT32_C(   171944549),  INT32_C(   814328221), -INT32_C(  1636097899) },
       INT32_C(         175),
      {  INT32_C(   963630578), -INT32_C(   927043914),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(   651782355),
         INT32_C(   504549483),  INT32_C(   568948031),  INT32_C(  1056495954),  INT32_C(           0),  INT32_C(   698235579),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0) } },
    { UINT16_C(42561),
      {  INT32_C(   130399837),  INT32_C(  1646911530),  INT32_C(  1559689470),  INT32_C(  1409702933), -INT32_C(   251813018),  INT32_C(  1326486483),  INT32_C(   939573041), -INT32_C(  1059110557),
         INT32_C(   717726975), -INT32_C(  2087915388), -INT32_C(    35683352),  INT32_C(  1163060703),  INT32_C(  1530220424),  INT32_C(   346703330),  INT32_C(  1749854725), -INT32_C(   349688852) },
       INT32_C(         208),
      { -INT32_C(  1101199419),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(  1087293440),  INT32_C(           0),
         INT32_C(           0), -INT32_C(   259751028), -INT32_C(  2081882657),  INT32_C(           0),  INT32_C(           0),  INT32_C(  1172444330),  INT32_C(           0),  INT32_C(   736946984) } },
    { UINT16_C(15800),
      {  INT32_C(  1112733097), -INT32_C(   450654650),  INT32_C(   326204642), -INT32_C(   231238450), -INT32_C(    89831274), -INT32_C(   962021814),  INT32_C(  1695732701),  INT32_C(  1386400425),
         INT32_C(   110425279),  INT32_C(  1709947011),  INT32_C(    58219572), -INT32_C(  2030718992),  INT32_C(  1115724792),  INT32_C(   772286545), -INT32_C(  1517020421), -INT32_C(  1527302428) },
       INT32_C(          11),
      {  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(  1713486094),  INT32_C(   316626089), -INT32_C(   916925162),  INT32_C(           0),  INT32_C(  1428837465),
        -INT32_C(  1746873698),  INT32_C(           0), -INT32_C(  2038403317), -INT32_C(    32448843),  INT32_C(  2131251219),  INT32_C(   170246405),  INT32_C(           0),  INT32_C(           0) } },
    { UINT16_C(38212),
      { -INT32_C(  1947109357),  INT32_C(  1899749755), -INT32_C(   401853593),  INT32_C(  2115001717),  INT32_C(   546835596), -INT32_C(  1470726735), -INT32_C(   885751519),  INT32_C(  1113618479),
         INT32_C(  1825460721), -INT32_C(  1713567438), -INT32_C(  1316886212), -INT32_C(   751857081),  INT32_C(  1341376670),  INT32_C(  1727482181), -INT32_C(    97440565), -INT32_C(  1791127132) },
       INT32_C(           2),
      {  INT32_C(           0),  INT32_C(           0), -INT32_C(   100463399),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(  1926045768),  INT32_C(           0),
         INT32_C(  1530107004),  INT32_C(           0),  INT32_C(   744520271),  INT32_C(           0), -INT32_C(  1812139481),  INT32_C(           0),  INT32_C(           0),  INT32_C(   625960041) } },
    { UINT16_C(57108),
      {  INT32_C(   801722541),  INT32_C(   834736129), -INT32_C(   688300061), -INT32_C(  1524678994), -INT32_C(   707663196),  INT32_C(   577140453),  INT32_C(   221071371),  INT32_C(   166543708),
        -INT32_C(  1841777007), -INT32_C(  1446774330),  INT32_C(   109034584), -INT32_C(  1632854278),  INT32_C(  1853062537), -INT32_C(     7284237),  INT32_C(  2097986849), -INT32_C(  1886914050) },
       INT32_C(          15),
      {  INT32_C(           0),  INT32_C(           0), -INT32_C(  1077432846),  INT32_C(           0), -INT32_C(   716592221),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),
         INT32_C(  1831019633), -INT32_C(   208841849),  INT32_C(  2024803583),  INT32_C(  1039482201), -INT32_C(    82649882),  INT32_C(           0),  INT32_C(  2051209753), -INT32_C(   201515249) } },
    { UINT16_C(58809),
      { -INT32_C(  1650388706), -INT32_C(  1002660840), -INT32_C(  1371421382), -INT32_C(  1014549197),  INT32_C(  1082173748), -INT32_C(  1388675546),  INT32_C(   778955021),  INT32_C(  2098407007),
         INT32_C(  1327215927), -INT32_C(  1961666735),  INT32_C(  1329157404), -INT32_C(  1106067062), -INT32_C(  1862364566),  INT32_C(   490616848), -INT32_C(  2125747422),  INT32_C(   150888401) },
       INT32_C(          20),
      {  INT32_C(   286386650),  INT32_C(           0),  INT32_C(           0),  INT32_C(  1934834744),  INT32_C(   177423368), -INT32_C(  1478333741),  INT32_C(           0),  INT32_C(   845543377),
        -INT32_C(  1152158479),  INT32_C(           0), -INT32_C(  1789803277),  INT32_C(           0),  INT32_C(           0), -INT32_C(   478084653), -INT32_C(  1162729452), -INT32_C(   436399985) } },
    { UINT16_C(27504),
      {  INT32_C(   717262064), -INT32_C(   303346981),  INT32_C(   125785352),  INT32_C(   591368165), -INT32_C(   120692308), -INT32_C(   514351134),  INT32_C(    16411560), -INT32_C(  1066701872),
        -INT32_C(   739627785),  INT32_C(  2143343990),  INT32_C(   277233706),  INT32_C(  2083767759),  INT32_C(   158597671),  INT32_C(  1240124321),  INT32_C(   105506102),  INT32_C(  1204204880) },
       INT32_C(           1),
      {  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(  2087137494),  INT32_C(  1890308081),  INT32_C(     8205780),  INT32_C(           0),
        -INT32_C(   369813893),  INT32_C(  1071671995),  INT32_C(           0), -INT32_C(  1105599769),  INT32_C(           0), -INT32_C(  1527421488),  INT32_C(    52753051),  INT32_C(           0) } },
    { UINT16_C(56198),
      {  INT32_C(  1545318870), -INT32_C(   199038271), -INT32_C(   621393562),  INT32_C(  1034262610),  INT32_C(   723704801), -INT32_C(  1461685535), -INT32_C(   732315207), -INT32_C(   273686760),
         INT32_C(  1363921552),  INT32_C(   457600436),  INT32_C(   167066806), -INT32_C(  1236886572),  INT32_C(  1491167350), -INT32_C(  1828666918), -INT32_C(  1704502910), -INT32_C(   913762760) },
       INT32_C(           0),
      {  INT32_C(           0), -INT32_C(   199038271), -INT32_C(   621393562),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(   273686760),
         INT32_C(  1363921552),  INT32_C(   457600436),  INT32_C(           0), -INT32_C(  1236886572),  INT32_C(  1491167350),  INT32_C(           0), -INT32_C(  1704502910), -INT32_C(   913762760) } },
    { UINT16_C(24642),
      { -INT32_C(  1516373584),  INT32_C(  1212182786),  INT32_C(   145798951),  INT32_C(   264866319), -INT32_C(  2056762595),  INT32_C(  1872470246), -INT32_C(  2075886487), -INT32_C(  1041987823),
        -INT32_C(  2107211392),  INT32_C(   449488883),  INT32_C(  1831041630),  INT32_C(   561835012),  INT32_C(   514253880), -INT32_C(   292732284), -INT32_C(   814558530), -INT32_C(   644852135) },
       INT32_C(          24),
      {  INT32_C(           0),  INT32_C(  1081147976),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(  1149004164),  INT32_C(           0),
         INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(  1925020434),  INT32_C(  1926414031),  INT32_C(           0) } },
    { UINT16_C( 9629),
      {  INT32_C(   144702437), -INT32_C(   453663896),  INT32_C(  1808281028), -INT32_C(   659731125), -INT32_C(  1381340357), -INT32_C(   905772230),  INT32_C(   935386076), -INT32_C(  1940103514),
        -INT32_C(  1030423719),  INT32_C(  1671858590),  INT32_C(    30306230), -INT32_C(   136676420),  INT32_C(   547652838),  INT32_C(  1693099912),  INT32_C(   698133123),  INT32_C(  1656092680) },
       INT32_C(          20),
      { -INT32_C(     4304759),  INT32_C(           0), -INT32_C(  2099493188), -INT32_C(   724255350), -INT32_C(  1498170662),  INT32_C(           0),  INT32_C(           0), -INT32_C(   974493499),
         INT32_C(  1337302057),  INT32_C(           0), -INT32_C(   419733476),  INT32_C(           0),  INT32_C(           0), -INT32_C(  1434941874),  INT32_C(           0),  INT32_C(           0) } },
  };

  simde__m512i a, r;

  #if !(defined(HEDLEY_MSVC_VERSION) && defined(SIMDE_X86_AVX512F_NATIVE) && defined(SIMDE_X86_AVX512VL_NATIVE))
  a = simde_mm512_loadu_epi32(test_vec[0].a);
  r = simde_mm512_maskz_ror_epi32(test_vec[0].k, a, INT32_C(          75));
  simde_test_x86_assert_equal_i32x16(r, simde_mm512_loadu_epi32(test_vec[0].r));

  a = simde_mm512_loadu_epi32(test_vec[1].a);
  r = simde_mm512_maskz_ror_epi32(test_vec[1].k, a, INT32_C(          43));
  simde_test_x86_assert_equal_i32x16(r, simde_mm512_loadu_epi32(test_vec[1].r));

  a = simde_mm512_loadu_epi32(test_vec[2].a);
  r = simde_mm512_maskz_ror_epi32(test_vec[2].k, a, INT32_C(         151));
  simde_test_x86_assert_equal_i32x16(r, simde_mm512_loadu_epi32(test_vec[2].r));

  a = simde_mm512_loadu_epi32(test_vec[3].a);
  r = simde_mm512_maskz_ror_epi32(test_vec[3].k, a, INT32_C(         159));
  simde_test_x86_assert_equal_i32x16(r, simde_mm512_loadu_epi32(test_vec[3].r));

  a = simde_mm512_loadu_epi32(test_vec[4].a);
  r = simde_mm512_maskz_ror_epi32(test_vec[4].k, a, INT32_C(          76));
  simde_test_x86_assert_equal_i32x16(r, simde_mm512_loadu_epi32(test_vec[4].r));

  a = simde_mm512_loadu_epi32(test_vec[5].a);
  r = simde_mm512_maskz_ror_epi32(test_vec[5].k, a, INT32_C(         166));
  simde_test_x86_assert_equal_i32x16(r, simde_mm512_loadu_epi32(test_vec[5].r));

  a = simde_mm512_loadu_epi32(test_vec[6].a);
  r = simde_mm512_maskz_ror_epi32(test_vec[6].k, a, INT32_C(         175));
  simde_test_x86_assert_equal_i32x16(r, simde_mm512_loadu_epi32(test_vec[6].r));

  a = simde_mm512_loadu_epi32(test_vec[7].a);
  r = simde_mm512_maskz_ror_epi32(test_vec[7].k, a, INT32_C(         208));
  simde_test_x86_assert_equal_i32x16(r, simde_mm512_loadu_epi32(test_vec[7].r));
  #endif

  a = simde_mm512_loadu_epi32(test_vec[8].a);
  r = simde_mm512_maskz_ror_epi32(test_vec[8].k, a, INT32_C(          11));
  simde_test_x86_assert_equal_i32x16(r, simde_mm512_loadu_epi32(test_vec[8].r));

  a = simde_mm512_loadu_epi32(test_vec[9].a);
  r = simde_mm512_maskz_ror_epi32(test_vec[9].k, a, INT32_C(           2));
  simde_test_x86_assert_equal_i32x16(r, simde_mm512_loadu_epi32(test_vec[9].r));

  a = simde_mm512_loadu_epi32(test_vec[10].a);
  r = simde_mm512_maskz_ror_epi32(test_vec[10].k, a, INT32_C(          15));
  simde_test_x86_assert_equal_i32x16(r, simde_mm512_loadu_epi32(test_vec[10].r));

  a = simde_mm512_loadu_epi32(test_vec[11].a);
  r = simde_mm512_maskz_ror_epi32(test_vec[11].k, a, INT32_C(          20));
  simde_test_x86_assert_equal_i32x16(r, simde_mm512_loadu_epi32(test_vec[11].r));

  a = simde_mm512_loadu_epi32(test_vec[12].a);
  r = simde_mm512_maskz_ror_epi32(test_vec[12].k, a, INT32_C(           1));
  simde_test_x86_assert_equal_i32x16(r, simde_mm512_loadu_epi32(test_vec[12].r));

  a = simde_mm512_loadu_epi32(test_vec[13].a);
  r = simde_mm512_maskz_ror_epi32(test_vec[13].k, a, INT32_C(           0));
  simde_test_x86_assert_equal_i32x16(r, simde_mm512_loadu_epi32(test_vec[13].r));

  a = simde_mm512_loadu_epi32(test_vec[14].a);
  r = simde_mm512_maskz_ror_epi32(test_vec[14].k, a, INT32_C(          24));
  simde_test_x86_assert_equal_i32x16(r, simde_mm512_loadu_epi32(test_vec[14].r));

  a = simde_mm512_loadu_epi32(test_vec[15].a);
  r = simde_mm512_maskz_ror_epi32(test_vec[15].k, a, INT32_C(          20));
  simde_test_x86_assert_equal_i32x16(r, simde_mm512_loadu_epi32(test_vec[15].r));

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__mmask16 k = simde_test_x86_random_mmask16();
    simde__m512i a = simde_test_x86_random_i32x16();
    int imm8 = simde_test_codegen_random_i32() & 31;
    simde__m512i r;
    SIMDE_CONSTIFY_256_(simde_mm512_maskz_ror_epi32, r, simde_mm512_setzero_si512(), imm8, k, a);

    simde_test_x86_write_mmask16(2, k, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i32x16(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, imm8, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_ror_epi64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int64_t a[2];
    int imm8;
    const int64_t r[2];
  } test_vec[] = {
    { { -INT64_C( 2884578317211713642), -INT64_C(   47767976167316367) },
       INT32_C(          70),
      {  INT64_C( 6584227115282937086), -INT64_C( 4035971640751578735) } },
    { { -INT64_C(  357916128627934935),  INT64_C( 2464041659046532833) },
       INT32_C(         243),
      {  INT64_C(  983381999775727457),  INT64_C( 4691254270947501126) } },
    { {  INT64_C( 8418660568361198222), -INT64_C( 6025201124708923692) },
       INT32_C(         156),
      {  INT64_C( 6637787874690429677), -INT64_C( 2950863487915329537) } },
    { { -INT64_C( 2308050915166919936),  INT64_C(  194785996209123921) },
       INT32_C(          28),
      {  INT64_C( 6871982918093405885), -INT64_C(  846917453547025075) } },
    { { -INT64_C( 5585783953426618801), -INT64_C( 1040572278075546695) },
       INT32_C(          76),
      {  INT64_C( 7276453281045216990),  INT64_C( 4296179998545126146) } },
    { {  INT64_C( 3769566868574835833), -INT64_C( 4334413731470194758) },
       INT32_C(          96),
      {  INT64_C( 5655417742871769368),  INT64_C(  730928644504490413) } },
    { {  INT64_C( 1688678110927824503),  INT64_C( 7832376936192360427) },
       INT32_C(          98),
      { -INT64_C( 2344922273370351374), -INT64_C( 2797491854689661868) } },
    { {  INT64_C( 3979775616834061770),  INT64_C( 2470546929609716052) },
       INT32_C(         136),
      { -INT64_C( 3875564079544850491),  INT64_C( 6062488473129734577) } },
    { { -INT64_C(  753293860742509869),  INT64_C( 8233865354056328510) },
       INT32_C(          56),
      { -INT64_C( 8375787612987010059),  INT64_C( 4940706235531214450) } },
    { {  INT64_C( 6864500045184791257),  INT64_C( 7728712640564914148) },
       INT32_C(          42),
      { -INT64_C( 7279935633419153178), -INT64_C( 3698022255639736199) } },
    { {  INT64_C( 1625327629434178866),  INT64_C( 4772608166658663808) },
       INT32_C(          15),
      { -INT64_C( 7321677493134673894), -INT64_C( 3818906835567594590) } },
    { {  INT64_C( 2630995510230225894),  INT64_C( 1173217605231437049) },
       INT32_C(          45),
      {  INT64_C( 7192467805532398617), -INT64_C( 2769326265331056064) } },
    { { -INT64_C(  263879852585126084),  INT64_C(  359754204105930496) },
       INT32_C(           7),
      {  INT64_C( 8788964911278886894),  INT64_C(    2810579719577582) } },
    { { -INT64_C( 4708314048361646490),  INT64_C( 8276476771024293516) },
       INT32_C(          53),
      {  INT64_C( 5019979505443485173), -INT64_C( 2333376681324813418) } },
    { { -INT64_C(   20166448993493719),  INT64_C( 7627879609794552284) },
       INT32_C(          33),
      {  INT64_C( 6462188917177986396), -INT64_C( 6800452006425274869) } },
  };

  simde__m128i a, r;

  #if !(defined(HEDLEY_MSVC_VERSION) && defined(SIMDE_X86_AVX512F_NATIVE) && defined(SIMDE_X86_AVX512VL_NATIVE))
  a = simde_x_mm_loadu_epi64(test_vec[0].a);
  r = simde_mm_ror_epi64(a, INT32_C(          70));
  simde_test_x86_assert_equal_i64x2(r, simde_x_mm_loadu_epi64(test_vec[0].r));

  a = simde_x_mm_loadu_epi64(test_vec[1].a);
  r = simde_mm_ror_epi64(a, INT32_C(         243));
  simde_test_x86_assert_equal_i64x2(r, simde_x_mm_loadu_epi64(test_vec[1].r));

  a = simde_x_mm_loadu_epi64(test_vec[2].a);
  r = simde_mm_ror_epi64(a, INT32_C(         156));
  simde_test_x86_assert_equal_i64x2(r, simde_x_mm_loadu_epi64(test_vec[2].r));
  #endif

  a = simde_x_mm_loadu_epi64(test_vec[3].a);
  r = simde_mm_ror_epi64(a, INT32_C(          28));
  simde_test_x86_assert_equal_i64x2(r, simde_x_mm_loadu_epi64(test_vec[3].r));

  #if !(defined(HEDLEY_MSVC_VERSION) && defined(SIMDE_X86_AVX512F_NATIVE) && defined(SIMDE_X86_AVX512VL_NATIVE))
  a = simde_x_mm_loadu_epi64(test_vec[4].a);
  r = simde_mm_ror_epi64(a, INT32_C(          76));
  simde_test_x86_assert_equal_i64x2(r, simde_x_mm_loadu_epi64(test_vec[4].r));

  a = simde_x_mm_loadu_epi64(test_vec[5].a);
  r = simde_mm_ror_epi64(a, INT32_C(          96));
  simde_test_x86_assert_equal_i64x2(r, simde_x_mm_loadu_epi64(test_vec[5].r));

  a = simde_x_mm_loadu_epi64(test_vec[6].a);
  r = simde_mm_ror_epi64(a, INT32_C(          98));
  simde_test_x86_assert_equal_i64x2(r, simde_x_mm_loadu_epi64(test_vec[6].r));

  a = simde_x_mm_loadu_epi64(test_vec[7].a);
  r = simde_mm_ror_epi64(a, INT32_C(         136));
  simde_test_x86_assert_equal_i64x2(r, simde_x_mm_loadu_epi64(test_vec[7].r));
  #endif

  a = simde_x_mm_loadu_epi64(test_vec[8].a);
  r = simde_mm_ror_epi64(a, INT32_C(          56));
  simde_test_x86_assert_equal_i64x2(r, simde_x_mm_loadu_epi64(test_vec[8].r));

  a = simde_x_mm_loadu_epi64(test_vec[9].a);
  r = simde_mm_ror_epi64(a, INT32_C(          42));
  simde_test_x86_assert_equal_i64x2(r, simde_x_mm_loadu_epi64(test_vec[9].r));

  a = simde_x_mm_loadu_epi64(test_vec[10].a);
  r = simde_mm_ror_epi64(a, INT32_C(          15));
  simde_test_x86_assert_equal_i64x2(r, simde_x_mm_loadu_epi64(test_vec[10].r));

  a = simde_x_mm_loadu_epi64(test_vec[11].a);
  r = simde_mm_ror_epi64(a, INT32_C(          45));
  simde_test_x86_assert_equal_i64x2(r, simde_x_mm_loadu_epi64(test_vec[11].r));

  a = simde_x_mm_loadu_epi64(test_vec[12].a);
  r = simde_mm_ror_epi64(a, INT32_C(           7));
  simde_test_x86_assert_equal_i64x2(r, simde_x_mm_loadu_epi64(test_vec[12].r));

  a = simde_x_mm_loadu_epi64(test_vec[13].a);
  r = simde_mm_ror_epi64(a, INT32_C(          53));
  simde_test_x86_assert_equal_i64x2(r, simde_x_mm_loadu_epi64(test_vec[13].r));

  a = simde_x_mm_loadu_epi64(test_vec[14].a);
  r = simde_mm_ror_epi64(a, INT32_C(          33));
  simde_test_x86_assert_equal_i64x2(r, simde_x_mm_loadu_epi64(test_vec[14].r));

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m128i a = simde_test_x86_random_i64x2();
    int imm8 = simde_test_codegen_random_i32() & 63;
    simde__m128i r;
    SIMDE_CONSTIFY_256_(simde_mm_ror_epi64, r, simde_mm_setzero_si128(), imm8, a);

    simde_test_x86_write_i64x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_i32(2, imm8, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_mask_ror_epi64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int64_t src[2];
    const simde__mmask8 k;
    const int64_t a[2];
    int imm8;
    const int64_t r[2];
  } test_vec[] = {
    { { -INT64_C( 7123719541745197503),  INT64_C( 8112336163936061488) },
      UINT8_C(138),
      {  INT64_C( 8248910000334030197),  INT64_C( 8985562645947011855) },
       INT32_C(         229),
      { -INT64_C( 7123719541745197503), -INT64_C(  894660961491379956) } },
    { { -INT64_C( 5817770145014355271),  INT64_C( 7636781676403209140) },
      UINT8_C( 80),
      { -INT64_C( 5915528085559583883), -INT64_C( 7217882962135456891) },
       INT32_C(         120),
      { -INT64_C( 5817770145014355271),  INT64_C( 7636781676403209140) } },
    { { -INT64_C( 5709027878984996199), -INT64_C( 7624770044190249104) },
      UINT8_C( 50),
      { -INT64_C( 4455797442482846954),  INT64_C( 7680557391095186599) },
       INT32_C(          30),
      { -INT64_C( 5709027878984996199), -INT64_C(  798524040550856445) } },
    { { -INT64_C( 2314310898702581848), -INT64_C( 7950883336336869351) },
      UINT8_C(156),
      {  INT64_C( 6977835653807690705), -INT64_C( 8187242788836917034) },
       INT32_C(          22),
      { -INT64_C( 2314310898702581848), -INT64_C( 7950883336336869351) } },
    { { -INT64_C( 4085529028761883367), -INT64_C( 4658789982358216976) },
      UINT8_C(231),
      { -INT64_C( 5657234030266015698),  INT64_C(  444106048253987800) },
       INT32_C(         226),
      { -INT64_C( 2616723274761019929),  INT64_C( 4913993399025693190) } },
    { { -INT64_C( 3019701827334845432), -INT64_C( 7579139295915616459) },
      UINT8_C(243),
      { -INT64_C( 2849693280201128113),  INT64_C( 5388526712205768964) },
       INT32_C(         255),
      { -INT64_C( 5699386560402256225), -INT64_C( 7669690649298013688) } },
    { { -INT64_C( 8461291668802285371), -INT64_C( 9156019869039384250) },
      UINT8_C( 35),
      { -INT64_C(  694989124286326685),  INT64_C( 7935855046254044334) },
       INT32_C(         228),
      {  INT64_C( 3297327096638320241), -INT64_C( 1887172848911246047) } },
    { { -INT64_C( 3753412174662465968), -INT64_C( 3214983263052469981) },
      UINT8_C(252),
      { -INT64_C( 7890579499276055875),  INT64_C( 8013539165703957800) },
       INT32_C(         109),
      { -INT64_C( 3753412174662465968), -INT64_C( 3214983263052469981) } },
    { { -INT64_C( 7370032796199842761),  INT64_C( 8741833992653168614) },
      UINT8_C(203),
      {  INT64_C( 8316029094970897883), -INT64_C( 8168089353384708585) },
       INT32_C(          37),
      {  INT64_C( 3935140772191093699),  INT64_C( 1400291489211558128) } },
    { {  INT64_C( 2323338324618403756), -INT64_C( 3231762172125333384) },
      UINT8_C(242),
      {  INT64_C( 4559743028705183375), -INT64_C(  235334400481110501) },
       INT32_C(          27),
      {  INT64_C( 2323338324618403756), -INT64_C(  244668276968418431) } },
    { {  INT64_C( 7470010454576398981), -INT64_C( 1960927570864538123) },
      UINT8_C(217),
      { -INT64_C(  827813474519997680),  INT64_C( 7101280922817757119) },
       INT32_C(          12),
      {  INT64_C( 3535123604586786626), -INT64_C( 1960927570864538123) } },
    { {  INT64_C( 8409790683964029044), -INT64_C( 4371797060726449827) },
      UINT8_C( 69),
      {  INT64_C( 6392309392695736279),  INT64_C( 2438065232621607319) },
       INT32_C(          15),
      {  INT64_C( 8047564661958945803), -INT64_C( 4371797060726449827) } },
    { {  INT64_C( 3877650905021065083), -INT64_C( 3265250143708146558) },
      UINT8_C(139),
      { -INT64_C( 8149117503312549275), -INT64_C( 2045829141741368999) },
       INT32_C(           1),
      { -INT64_C( 4074558751656274638), -INT64_C( 1022914570870684500) } },
    { {  INT64_C(  603353192149880192),  INT64_C( 3034782228553085241) },
      UINT8_C( 58),
      { -INT64_C( 3005111423302649851),  INT64_C( 1404286385411075918) },
       INT32_C(          57),
      {  INT64_C(  603353192149880192), -INT64_C( 4718783404477798647) } },
  };

  simde__m128i src, a, r;

  #if !(defined(HEDLEY_MSVC_VERSION) && defined(SIMDE_X86_AVX512F_NATIVE) && defined(SIMDE_X86_AVX512VL_NATIVE))
  src = simde_x_mm_loadu_epi64(test_vec[0].src);
  a = simde_x_mm_loadu_epi64(test_vec[0].a);
  r = simde_mm_mask_ror_epi64(src, test_vec[0].k, a, INT32_C(         229));
  simde_test_x86_assert_equal_i64x2(r, simde_x_mm_loadu_epi64(test_vec[0].r));

  src = simde_x_mm_loadu_epi64(test_vec[1].src);
  a = simde_x_mm_loadu_epi64(test_vec[1].a);
  r = simde_mm_mask_ror_epi64(src, test_vec[1].k, a, INT32_C(         120));
  simde_test_x86_assert_equal_i64x2(r, simde_x_mm_loadu_epi64(test_vec[1].r));
  #endif

  src = simde_x_mm_loadu_epi64(test_vec[2].src);
  a = simde_x_mm_loadu_epi64(test_vec[2].a);
  r = simde_mm_mask_ror_epi64(src, test_vec[2].k, a, INT32_C(          30));
  simde_test_x86_assert_equal_i64x2(r, simde_x_mm_loadu_epi64(test_vec[2].r));

  src = simde_x_mm_loadu_epi64(test_vec[3].src);
  a = simde_x_mm_loadu_epi64(test_vec[3].a);
  r = simde_mm_mask_ror_epi64(src, test_vec[3].k, a, INT32_C(          22));
  simde_test_x86_assert_equal_i64x2(r, simde_x_mm_loadu_epi64(test_vec[3].r));

  #if !(defined(HEDLEY_MSVC_VERSION) && defined(SIMDE_X86_AVX512F_NATIVE) && defined(SIMDE_X86_AVX512VL_NATIVE))
  src = simde_x_mm_loadu_epi64(test_vec[4].src);
  a = simde_x_mm_loadu_epi64(test_vec[4].a);
  r = simde_mm_mask_ror_epi64(src, test_vec[4].k, a, INT32_C(         226));
  simde_test_x86_assert_equal_i64x2(r, simde_x_mm_loadu_epi64(test_vec[4].r));

  src = simde_x_mm_loadu_epi64(test_vec[5].src);
  a = simde_x_mm_loadu_epi64(test_vec[5].a);
  r = simde_mm_mask_ror_epi64(src, test_vec[5].k, a, INT32_C(         255));
  simde_test_x86_assert_equal_i64x2(r, simde_x_mm_loadu_epi64(test_vec[5].r));

  src = simde_x_mm_loadu_epi64(test_vec[6].src);
  a = simde_x_mm_loadu_epi64(test_vec[6].a);
  r = simde_mm_mask_ror_epi64(src, test_vec[6].k, a, INT32_C(         228));
  simde_test_x86_assert_equal_i64x2(r, simde_x_mm_loadu_epi64(test_vec[6].r));

  src = simde_x_mm_loadu_epi64(test_vec[7].src);
  a = simde_x_mm_loadu_epi64(test_vec[7].a);
  r = simde_mm_mask_ror_epi64(src, test_vec[7].k, a, INT32_C(         109));
  simde_test_x86_assert_equal_i64x2(r, simde_x_mm_loadu_epi64(test_vec[7].r));
  #endif

  src = simde_x_mm_loadu_epi64(test_vec[8].src);
  a = simde_x_mm_loadu_epi64(test_vec[8].a);
  r = simde_mm_mask_ror_epi64(src, test_vec[8].k, a, INT32_C(          37));
  simde_test_x86_assert_equal_i64x2(r, simde_x_mm_loadu_epi64(test_vec[8].r));

  src = simde_x_mm_loadu_epi64(test_vec[9].src);
  a = simde_x_mm_loadu_epi64(test_vec[9].a);
  r = simde_mm_mask_ror_epi64(src, test_vec[9].k, a, INT32_C(          27));
  simde_test_x86_assert_equal_i64x2(r, simde_x_mm_loadu_epi64(test_vec[9].r));

  src = simde_x_mm_loadu_epi64(test_vec[10].src);
  a = simde_x_mm_loadu_epi64(test_vec[10].a);
  r = simde_mm_mask_ror_epi64(src, test_vec[10].k, a, INT32_C(          12));
  simde_test_x86_assert_equal_i64x2(r, simde_x_mm_loadu_epi64(test_vec[10].r));

  src = simde_x_mm_loadu_epi64(test_vec[11].src);
  a = simde_x_mm_loadu_epi64(test_vec[11].a);
  r = simde_mm_mask_ror_epi64(src, test_vec[11].k, a, INT32_C(          15));
  simde_test_x86_assert_equal_i64x2(r, simde_x_mm_loadu_epi64(test_vec[11].r));

  src = simde_x_mm_loadu_epi64(test_vec[12].src);
  a = simde_x_mm_loadu_epi64(test_vec[12].a);
  r = simde_mm_mask_ror_epi64(src, test_vec[12].k, a, INT32_C(           1));
  simde_test_x86_assert_equal_i64x2(r, simde_x_mm_loadu_epi64(test_vec[12].r));

  src = simde_x_mm_loadu_epi64(test_vec[13].src);
  a = simde_x_mm_loadu_epi64(test_vec[13].a);
  r = simde_mm_mask_ror_epi64(src, test_vec[13].k, a, INT32_C(          57));
  simde_test_x86_assert_equal_i64x2(r, simde_x_mm_loadu_epi64(test_vec[13].r));

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m128i src = simde_test_x86_random_i64x2();
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m128i a = simde_test_x86_random_i64x2();
    int imm8 = simde_test_codegen_random_i32() & 63;
    simde__m128i r;
    SIMDE_CONSTIFY_256_(simde_mm_mask_ror_epi64, r, simde_mm_setzero_si128(), imm8, src, k, a);

    simde_test_x86_write_i64x2(2, src, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i64x2(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, imm8, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_maskz_ror_epi64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask8 k;
    const int64_t a[2];
    int imm8;
    const int64_t r[2];
  } test_vec[] = {
    { UINT8_C(151),
      { -INT64_C( 5998299602728401731),  INT64_C( 8007623786619321750) },
       INT32_C(          74),
      {  INT64_C( 3416878002345787505),  INT64_C( 7321665739953805935) } },
    { UINT8_C( 41),
      {  INT64_C(  243024031576007036), -INT64_C( 5038282267311343866) },
       INT32_C(          45),
      {  INT64_C( 2922149809703885563),  INT64_C(                   0) } },
    { UINT8_C( 42),
      {  INT64_C( 6522127895131149232),  INT64_C(  660490533752777848) },
       INT32_C(         232),
      {  INT64_C(                   0), -INT64_C( 6622024641323390328) } },
    { UINT8_C(239),
      { -INT64_C( 2112036965357725734),  INT64_C( 1191874799745555060) },
       INT32_C(         230),
      {  INT64_C( 5169410402908029478),  INT64_C( 4836385967680137615) } },
    { UINT8_C(188),
      {  INT64_C( 5762967325695555233), -INT64_C( 3642258414992955125) },
       INT32_C(         201),
      {  INT64_C(                   0),  INT64_C(                   0) } },
    { UINT8_C(232),
      {  INT64_C(  826464972804158217), -INT64_C( 6541063418992053053) },
       INT32_C(         115),
      {  INT64_C(                   0),  INT64_C(                   0) } },
    { UINT8_C(178),
      { -INT64_C( 5810324743939972973), -INT64_C( 4382199723873253832) },
       INT32_C(         196),
      {  INT64_C(                   0), -INT64_C( 8344338014990007197) } },
    { UINT8_C(231),
      { -INT64_C( 4016697293789957504),  INT64_C( 6070399023227663407) },
       INT32_C(         193),
      {  INT64_C( 7215023389959797056), -INT64_C( 6188172525240944105) } },
    { UINT8_C(229),
      { -INT64_C( 6026412500717854352),  INT64_C( 4644477514396527529) },
       INT32_C(          24),
      { -INT64_C( 4818446240697957752),  INT64_C(                   0) } },
    { UINT8_C( 25),
      {  INT64_C(  482413197098182319),  INT64_C( 3773734272338663034) },
       INT32_C(          28),
      { -INT64_C(    2697168945282062),  INT64_C(                   0) } },
    { UINT8_C(238),
      { -INT64_C( 4331470835376260614), -INT64_C( 2558429433531532071) },
       INT32_C(          18),
      {  INT64_C(                   0), -INT64_C( 4668412985868349476) } },
    { UINT8_C(251),
      {  INT64_C( 5645638652558720241),  INT64_C( 4382204432264743069) },
       INT32_C(          26),
      { -INT64_C(  103797936704086957), -INT64_C( 7921225573459956315) } },
    { UINT8_C(  5),
      { -INT64_C( 4298412689427361195), -INT64_C( 6661099495071788063) },
       INT32_C(          31),
      { -INT64_C( 6247296788941639459),  INT64_C(                   0) } },
    { UINT8_C( 38),
      { -INT64_C( 5820208066592940585), -INT64_C( 2445777967360164083) },
       INT32_C(          49),
      {  INT64_C(                   0),  INT64_C( 7850565810145128199) } },
    { UINT8_C(137),
      { -INT64_C( 5239114123608927523), -INT64_C( 4284270912119869292) },
       INT32_C(          48),
      { -INT64_C( 1335760878789871798),  INT64_C(                   0) } },
  };

  simde__m128i a, r;

  #if !(defined(HEDLEY_MSVC_VERSION) && defined(SIMDE_X86_AVX512F_NATIVE) && defined(SIMDE_X86_AVX512VL_NATIVE))
  a = simde_x_mm_loadu_epi64(test_vec[0].a);
  r = simde_mm_maskz_ror_epi64(test_vec[0].k, a, INT32_C(          74));
  simde_test_x86_assert_equal_i64x2(r, simde_x_mm_loadu_epi64(test_vec[0].r));
  #endif

  a = simde_x_mm_loadu_epi64(test_vec[1].a);
  r = simde_mm_maskz_ror_epi64(test_vec[1].k, a, INT32_C(          45));
  simde_test_x86_assert_equal_i64x2(r, simde_x_mm_loadu_epi64(test_vec[1].r));

  #if !(defined(HEDLEY_MSVC_VERSION) && defined(SIMDE_X86_AVX512F_NATIVE) && defined(SIMDE_X86_AVX512VL_NATIVE))
  a = simde_x_mm_loadu_epi64(test_vec[2].a);
  r = simde_mm_maskz_ror_epi64(test_vec[2].k, a, INT32_C(         232));
  simde_test_x86_assert_equal_i64x2(r, simde_x_mm_loadu_epi64(test_vec[2].r));

  a = simde_x_mm_loadu_epi64(test_vec[3].a);
  r = simde_mm_maskz_ror_epi64(test_vec[3].k, a, INT32_C(         230));
  simde_test_x86_assert_equal_i64x2(r, simde_x_mm_loadu_epi64(test_vec[3].r));

  a = simde_x_mm_loadu_epi64(test_vec[4].a);
  r = simde_mm_maskz_ror_epi64(test_vec[4].k, a, INT32_C(         201));
  simde_test_x86_assert_equal_i64x2(r, simde_x_mm_loadu_epi64(test_vec[4].r));

  a = simde_x_mm_loadu_epi64(test_vec[5].a);
  r = simde_mm_maskz_ror_epi64(test_vec[5].k, a, INT32_C(         115));
  simde_test_x86_assert_equal_i64x2(r, simde_x_mm_loadu_epi64(test_vec[5].r));

  a = simde_x_mm_loadu_epi64(test_vec[6].a);
  r = simde_mm_maskz_ror_epi64(test_vec[6].k, a, INT32_C(         196));
  simde_test_x86_assert_equal_i64x2(r, simde_x_mm_loadu_epi64(test_vec[6].r));

  a = simde_x_mm_loadu_epi64(test_vec[7].a);
  r = simde_mm_maskz_ror_epi64(test_vec[7].k, a, INT32_C(         193));
  simde_test_x86_assert_equal_i64x2(r, simde_x_mm_loadu_epi64(test_vec[7].r));
  #endif

  a = simde_x_mm_loadu_epi64(test_vec[8].a);
  r = simde_mm_maskz_ror_epi64(test_vec[8].k, a, INT32_C(          24));
  simde_test_x86_assert_equal_i64x2(r, simde_x_mm_loadu_epi64(test_vec[8].r));

  a = simde_x_mm_loadu_epi64(test_vec[9].a);
  r = simde_mm_maskz_ror_epi64(test_vec[9].k, a, INT32_C(          28));
  simde_test_x86_assert_equal_i64x2(r, simde_x_mm_loadu_epi64(test_vec[9].r));

  a = simde_x_mm_loadu_epi64(test_vec[10].a);
  r = simde_mm_maskz_ror_epi64(test_vec[10].k, a, INT32_C(          18));
  simde_test_x86_assert_equal_i64x2(r, simde_x_mm_loadu_epi64(test_vec[10].r));

  a = simde_x_mm_loadu_epi64(test_vec[11].a);
  r = simde_mm_maskz_ror_epi64(test_vec[11].k, a, INT32_C(          26));
  simde_test_x86_assert_equal_i64x2(r, simde_x_mm_loadu_epi64(test_vec[11].r));

  a = simde_x_mm_loadu_epi64(test_vec[12].a);
  r = simde_mm_maskz_ror_epi64(test_vec[12].k, a, INT32_C(          31));
  simde_test_x86_assert_equal_i64x2(r, simde_x_mm_loadu_epi64(test_vec[12].r));

  a = simde_x_mm_loadu_epi64(test_vec[13].a);
  r = simde_mm_maskz_ror_epi64(test_vec[13].k, a, INT32_C(          49));
  simde_test_x86_assert_equal_i64x2(r, simde_x_mm_loadu_epi64(test_vec[13].r));

  a = simde_x_mm_loadu_epi64(test_vec[14].a);
  r = simde_mm_maskz_ror_epi64(test_vec[14].k, a, INT32_C(          48));
  simde_test_x86_assert_equal_i64x2(r, simde_x_mm_loadu_epi64(test_vec[14].r));

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m128i a = simde_test_x86_random_i64x2();
    int imm8 = simde_test_codegen_random_i32() & 63;
    simde__m128i r;
    SIMDE_CONSTIFY_256_(simde_mm_maskz_ror_epi64, r, simde_mm_setzero_si128(), imm8, k, a);

    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i64x2(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, imm8, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm256_ror_epi64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int64_t a[4];
    int imm8;
    const int64_t r[4];
  } test_vec[] = {
    { {  INT64_C( 8316432796531310573),  INT64_C( 3114171450179211526), -INT64_C( 7404013480429108188),  INT64_C( 8474335822978487738) },
       INT32_C(          34),
      {  INT64_C( 4245223171019143652), -INT64_C( 3718262170613583717), -INT64_C( 1246246912763368899),  INT64_C(  936754695138359522) } },
    { { -INT64_C( 8403226401437201879),  INT64_C( 6079726858255374464),  INT64_C( 4332161252868333360),  INT64_C( 2568481131036063952) },
       INT32_C(         221),
      {  INT64_C( 8734257915718660321),  INT64_C( 3293472743118093037),  INT64_C( 6299684315004890535), -INT64_C( 7091543780382695465) } },
    { { -INT64_C( 6219687362595343222),  INT64_C( 7123827847226855362), -INT64_C( 5864723882168091687), -INT64_C( 7549682185975807389) },
       INT32_C(         216),
      { -INT64_C( 8884323703501140982), -INT64_C(  139679333556179214), -INT64_C( 6990754652592491607), -INT64_C( 3368020070153056959) } },
    { {  INT64_C( 1058289153311920634),  INT64_C( 4195683073489144760),  INT64_C( 2739517993660241759), -INT64_C(  586768683632804130) },
       INT32_C(         177),
      { -INT64_C( 1859882848941701289),  INT64_C(  559370735007309085),  INT64_C( 6668953588123800322), -INT64_C( 5728900474372916243) } },
    { {  INT64_C( 8484660675151422326), -INT64_C( 1530493995158865248),  INT64_C(  208799479385605712), -INT64_C( 2165476696747491282) },
       INT32_C(          17),
      {  INT64_C( 3583522661327116048), -INT64_C(  193525723231092777),  INT64_C( 7144962401836898056),  INT64_C( 6924127168317714557) } },
    { { -INT64_C( 7330976421101908061), -INT64_C( 3370499242022664774),  INT64_C( 5292237397244976739),  INT64_C( 1840910628519830395) },
       INT32_C(           9),
      { -INT64_C( 3328967639067149721), -INT64_C( 2492570000640589310),  INT64_C( 3577187306043926927), -INT64_C( 4788234474950879951) } },
    { {  INT64_C( 8208356391051370532),  INT64_C( 2339925953704240004), -INT64_C( 4257145958419469597), -INT64_C( 7158125842036590642) },
       INT32_C(         218),
      { -INT64_C( 7266547980843603593), -INT64_C( 3420236492004028295), -INT64_C( 2685630881558359145), -INT64_C(  622073274212377035) } },
    { { -INT64_C( 4003360836999355387),  INT64_C( 2561514463130413642),  INT64_C( 7461836691467630823),  INT64_C( 5933912852560820223) },
       INT32_C(         226),
      { -INT64_C( 2108712662771938015),  INT64_C( 5438794269783692533), -INT64_C( 1316777075979095749),  INT64_C( 3909350975224569747) } },
  };

  simde__m256i a, r;

  a = simde_x_mm256_loadu_epi64(test_vec[0].a);
  r = simde_mm256_ror_epi64(a, INT32_C(          34));
  simde_test_x86_assert_equal_i64x4(r, simde_x_mm256_loadu_epi64(test_vec[0].r));

  #if !(defined(HEDLEY_MSVC_VERSION) && defined(SIMDE_X86_AVX512F_NATIVE) && defined(SIMDE_X86_AVX512VL_NATIVE))
  a = simde_x_mm256_loadu_epi64(test_vec[1].a);
  r = simde_mm256_ror_epi64(a, INT32_C(         221));
  simde_test_x86_assert_equal_i64x4(r, simde_x_mm256_loadu_epi64(test_vec[1].r));

  a = simde_x_mm256_loadu_epi64(test_vec[2].a);
  r = simde_mm256_ror_epi64(a, INT32_C(         216));
  simde_test_x86_assert_equal_i64x4(r, simde_x_mm256_loadu_epi64(test_vec[2].r));

  a = simde_x_mm256_loadu_epi64(test_vec[3].a);
  r = simde_mm256_ror_epi64(a, INT32_C(         177));
  simde_test_x86_assert_equal_i64x4(r, simde_x_mm256_loadu_epi64(test_vec[3].r));
  #endif

  a = simde_x_mm256_loadu_epi64(test_vec[4].a);
  r = simde_mm256_ror_epi64(a, INT32_C(          17));
  simde_test_x86_assert_equal_i64x4(r, simde_x_mm256_loadu_epi64(test_vec[4].r));

  a = simde_x_mm256_loadu_epi64(test_vec[5].a);
  r = simde_mm256_ror_epi64(a, INT32_C(           9));
  simde_test_x86_assert_equal_i64x4(r, simde_x_mm256_loadu_epi64(test_vec[5].r));

  #if !(defined(HEDLEY_MSVC_VERSION) && defined(SIMDE_X86_AVX512F_NATIVE) && defined(SIMDE_X86_AVX512VL_NATIVE))
  a = simde_x_mm256_loadu_epi64(test_vec[6].a);
  r = simde_mm256_ror_epi64(a, INT32_C(         218));
  simde_test_x86_assert_equal_i64x4(r, simde_x_mm256_loadu_epi64(test_vec[6].r));

  a = simde_x_mm256_loadu_epi64(test_vec[7].a);
  r = simde_mm256_ror_epi64(a, INT32_C(         226));
  simde_test_x86_assert_equal_i64x4(r, simde_x_mm256_loadu_epi64(test_vec[7].r));
  #endif

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m256i a = simde_test_x86_random_i64x4();
    int imm8 = simde_test_codegen_random_i32() & 255;
    simde__m256i r;
    SIMDE_CONSTIFY_256_(simde_mm256_ror_epi64, r, simde_mm256_setzero_si256(), imm8, a);

    simde_test_x86_write_i64x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_i32(2, imm8, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i64x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm256_mask_ror_epi64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int64_t src[4];
    const simde__mmask8 k;
    const int64_t a[4];
    int imm8;
    const int64_t r[4];
  } test_vec[] = {
    { {  INT64_C( 7324308230959727268), -INT64_C( 3254755208070472554),  INT64_C(  363713535815559536), -INT64_C( 7887855811761012912) },
      UINT8_C(182),
      {  INT64_C( 5700610390862155099), -INT64_C( 7929006158735469379), -INT64_C( 6321048737135551285),  INT64_C( 8503967193641685914) },
       INT32_C(         118),
      {  INT64_C( 7324308230959727268), -INT64_C( 2734914112917932473),  INT64_C( 2053263045248102049), -INT64_C( 7887855811761012912) } },
    { {  INT64_C( 1451962470757832931),  INT64_C( 7110551290553703658), -INT64_C( 6645166217155119905), -INT64_C( 1177385585709757495) },
      UINT8_C( 47),
      { -INT64_C( 3336198972881793183),  INT64_C(  843840088034666774), -INT64_C( 4584603992225272074), -INT64_C( 6154525916806733744) },
       INT32_C(          74),
      { -INT64_C( 2849532971307608349),  INT64_C( 5008826848221962906), -INT64_C( 4778292757348883253),  INT64_C( 1453156000052409128) } },
    { { -INT64_C( 6391351620125317279),  INT64_C( 2726161222955303495),  INT64_C( 2248336175106700667),  INT64_C( 2068627475986565484) },
      UINT8_C(100),
      { -INT64_C( 2078238734058941562),  INT64_C( 8146511703993247310), -INT64_C( 3009136766498645473),  INT64_C( 3446007608107987760) },
       INT32_C(          64),
      { -INT64_C( 6391351620125317279),  INT64_C( 2726161222955303495), -INT64_C( 3009136766498645473),  INT64_C( 2068627475986565484) } },
    { { -INT64_C( 2719020101364533149),  INT64_C( 4270136120572597074),  INT64_C( 1988236371706347513), -INT64_C( 7660242322259809713) },
      UINT8_C(147),
      { -INT64_C( 2440374253465221450),  INT64_C( 6116810603467871064),  INT64_C( 1029884663017442648),  INT64_C( 4763354351144065581) },
       INT32_C(          27),
      { -INT64_C( 1852995007284145799),  INT64_C( 4715949453128293053),  INT64_C( 1988236371706347513), -INT64_C( 7660242322259809713) } },
    { { -INT64_C( 7161971595051519143),  INT64_C( 3470507900088188886), -INT64_C( 2859927266324941926),  INT64_C( 1087105522116225364) },
      UINT8_C( 95),
      { -INT64_C( 2737692302147927910), -INT64_C( 3817197228118364236), -INT64_C( 8743192093279072554), -INT64_C( 3920582288735463413) },
       INT32_C(          11),
      {  INT64_C( 1394779120665445592), -INT64_C(  677403809939616571), -INT64_C( 2679407315422371047),  INT64_C(  106172044236220291) } },
    { {  INT64_C( 8980362530425795712), -INT64_C( 7896392940656220353),  INT64_C( 6526935404700504913),  INT64_C( 7571420591411112864) },
      UINT8_C( 11),
      { -INT64_C( 1928759728390824364), -INT64_C( 3628233639753789197), -INT64_C( 4397110176642432507),  INT64_C( 1051332924687492726) },
       INT32_C(         179),
      {  INT64_C( 8459976191452552359), -INT64_C( 4785274116953441868),  INT64_C( 6526935404700504913), -INT64_C( 2110163382420192814) } },
    { {  INT64_C( 5888792509787096690), -INT64_C(  541250674246131938), -INT64_C( 2923568300288149654),  INT64_C( 4404785191024133243) },
      UINT8_C( 54),
      { -INT64_C( 4952238458588585225),  INT64_C( 6826918164121282876),  INT64_C( 1203115358085226192), -INT64_C(  621751834572496839) },
       INT32_C(         186),
      {  INT64_C( 5888792509787096690), -INT64_C( 5799095265267134697),  INT64_C( 3212406622616269828),  INT64_C( 4404785191024133243) } },
    { { -INT64_C( 5271200784471464375),  INT64_C( 4614377854066791939), -INT64_C( 7186008205916324892),  INT64_C( 1807268160199763267) },
      UINT8_C( 26),
      {  INT64_C(  997443378531180262),  INT64_C( 8010359693233007285),  INT64_C( 3621641278670456787),  INT64_C( 4254243953412554811) },
       INT32_C(         186),
      { -INT64_C( 5271200784471464375), -INT64_C( 3845813696954978981), -INT64_C( 7186008205916324892), -INT64_C( 4429548087239766322) } },
    { { -INT64_C( 6700432202313441699), -INT64_C( 4896543876537142503), -INT64_C( 6578069956268695995), -INT64_C(  469524878748496515) },
      UINT8_C(199),
      {  INT64_C( 4855113010633542911),  INT64_C( 6122442442828213174), -INT64_C( 8091504246235722696),  INT64_C( 8349432315208530223) },
       INT32_C(          48),
      { -INT64_C( 3202262536187591840),  INT64_C( 5257585933321393399),  INT64_C( 3729605624157736885), -INT64_C(  469524878748496515) } },
    { { -INT64_C(  267103231878685981),  INT64_C( 1281238151810073431), -INT64_C( 1631767110967329774),  INT64_C( 3233890512924326640) },
      UINT8_C( 49),
      {  INT64_C( 6109751994521994852), -INT64_C( 7028232112949732732),  INT64_C( 5553498074125678677), -INT64_C(  602985837074402727) },
       INT32_C(           9),
      {  INT64_C( 3614812811260697571),  INT64_C( 1281238151810073431), -INT64_C( 1631767110967329774),  INT64_C( 3233890512924326640) } },
    { { -INT64_C( 5695766483407260405),  INT64_C( 3944416753732184647),  INT64_C( 1452438924764106335), -INT64_C( 5980649869590869540) },
      UINT8_C(171),
      { -INT64_C( 7221263404634587665), -INT64_C( 1082284335245138887), -INT64_C( 6526413106905500809), -INT64_C( 4416918721817816175) },
       INT32_C(          48),
      { -INT64_C( 1499275113790465080), -INT64_C(  855231212196073222),  INT64_C( 1452438924764106335), -INT64_C(  877348402116836685) } },
    { { -INT64_C( 7877152608195113767),  INT64_C( 4015226640631244976), -INT64_C( 3741889887367059848), -INT64_C( 8311162544399137514) },
      UINT8_C(221),
      { -INT64_C(  787883311856967771),  INT64_C( 1643120004865013858), -INT64_C( 5792513224682252444),  INT64_C( 3465783294537425769) },
       INT32_C(          14),
      {  INT64_C( 9121992956657893690),  INT64_C( 4015226640631244976),  INT64_C( 6742660995130726463), -INT64_C( 8240249883556254325) } },
    { { -INT64_C( 3891917284254375610), -INT64_C( 8316759132549887063), -INT64_C( 7030227787495821109),  INT64_C( 3888119329560889484) },
      UINT8_C(  0),
      { -INT64_C( 6444190526419116602),  INT64_C( 7151105096465030786),  INT64_C( 7582115506676986127),  INT64_C( 1099595505305343203) },
       INT32_C(          42),
      { -INT64_C( 3891917284254375610), -INT64_C( 8316759132549887063), -INT64_C( 7030227787495821109),  INT64_C( 3888119329560889484) } },
    { {  INT64_C( 6463284654621034686),  INT64_C( 4811025694530006792), -INT64_C( 7247133673425994169), -INT64_C( 8557223245006524273) },
      UINT8_C( 42),
      {  INT64_C( 7810554005357120041),  INT64_C( 4530356520273935461),  INT64_C( 2903463281841670842), -INT64_C( 6078877072674831145) },
       INT32_C(           7),
      {  INT64_C( 6463284654621034686), -INT64_C( 3855716667733468424), -INT64_C( 7247133673425994169), -INT64_C( 5812098750164506999) } },
  };

  simde__m256i src, a, r;

  #if !(defined(HEDLEY_MSVC_VERSION) && defined(SIMDE_X86_AVX512F_NATIVE) && defined(SIMDE_X86_AVX512VL_NATIVE))
  src = simde_x_mm256_loadu_epi64(test_vec[0].src);
  a = simde_x_mm256_loadu_epi64(test_vec[0].a);
  r = simde_mm256_mask_ror_epi64(src, test_vec[0].k, a, INT32_C(         118));
  simde_test_x86_assert_equal_i64x4(r, simde_x_mm256_loadu_epi64(test_vec[0].r));

  src = simde_x_mm256_loadu_epi64(test_vec[1].src);
  a = simde_x_mm256_loadu_epi64(test_vec[1].a);
  r = simde_mm256_mask_ror_epi64(src, test_vec[1].k, a, INT32_C(          74));
  simde_test_x86_assert_equal_i64x4(r, simde_x_mm256_loadu_epi64(test_vec[1].r));

  src = simde_x_mm256_loadu_epi64(test_vec[2].src);
  a = simde_x_mm256_loadu_epi64(test_vec[2].a);
  r = simde_mm256_mask_ror_epi64(src, test_vec[2].k, a, INT32_C(          64));
  simde_test_x86_assert_equal_i64x4(r, simde_x_mm256_loadu_epi64(test_vec[2].r));
  #endif

  src = simde_x_mm256_loadu_epi64(test_vec[3].src);
  a = simde_x_mm256_loadu_epi64(test_vec[3].a);
  r = simde_mm256_mask_ror_epi64(src, test_vec[3].k, a, INT32_C(          27));
  simde_test_x86_assert_equal_i64x4(r, simde_x_mm256_loadu_epi64(test_vec[3].r));

  src = simde_x_mm256_loadu_epi64(test_vec[4].src);
  a = simde_x_mm256_loadu_epi64(test_vec[4].a);
  r = simde_mm256_mask_ror_epi64(src, test_vec[4].k, a, INT32_C(          11));
  simde_test_x86_assert_equal_i64x4(r, simde_x_mm256_loadu_epi64(test_vec[4].r));

  #if !(defined(HEDLEY_MSVC_VERSION) && defined(SIMDE_X86_AVX512F_NATIVE) && defined(SIMDE_X86_AVX512VL_NATIVE))
  src = simde_x_mm256_loadu_epi64(test_vec[5].src);
  a = simde_x_mm256_loadu_epi64(test_vec[5].a);
  r = simde_mm256_mask_ror_epi64(src, test_vec[5].k, a, INT32_C(         179));
  simde_test_x86_assert_equal_i64x4(r, simde_x_mm256_loadu_epi64(test_vec[5].r));

  src = simde_x_mm256_loadu_epi64(test_vec[6].src);
  a = simde_x_mm256_loadu_epi64(test_vec[6].a);
  r = simde_mm256_mask_ror_epi64(src, test_vec[6].k, a, INT32_C(         186));
  simde_test_x86_assert_equal_i64x4(r, simde_x_mm256_loadu_epi64(test_vec[6].r));

  src = simde_x_mm256_loadu_epi64(test_vec[7].src);
  a = simde_x_mm256_loadu_epi64(test_vec[7].a);
  r = simde_mm256_mask_ror_epi64(src, test_vec[7].k, a, INT32_C(         186));
  simde_test_x86_assert_equal_i64x4(r, simde_x_mm256_loadu_epi64(test_vec[7].r));
  #endif

  src = simde_x_mm256_loadu_epi64(test_vec[8].src);
  a = simde_x_mm256_loadu_epi64(test_vec[8].a);
  r = simde_mm256_mask_ror_epi64(src, test_vec[8].k, a, INT32_C(          48));
  simde_test_x86_assert_equal_i64x4(r, simde_x_mm256_loadu_epi64(test_vec[8].r));

  src = simde_x_mm256_loadu_epi64(test_vec[9].src);
  a = simde_x_mm256_loadu_epi64(test_vec[9].a);
  r = simde_mm256_mask_ror_epi64(src, test_vec[9].k, a, INT32_C(           9));
  simde_test_x86_assert_equal_i64x4(r, simde_x_mm256_loadu_epi64(test_vec[9].r));

  src = simde_x_mm256_loadu_epi64(test_vec[10].src);
  a = simde_x_mm256_loadu_epi64(test_vec[10].a);
  r = simde_mm256_mask_ror_epi64(src, test_vec[10].k, a, INT32_C(          48));
  simde_test_x86_assert_equal_i64x4(r, simde_x_mm256_loadu_epi64(test_vec[10].r));

  src = simde_x_mm256_loadu_epi64(test_vec[11].src);
  a = simde_x_mm256_loadu_epi64(test_vec[11].a);
  r = simde_mm256_mask_ror_epi64(src, test_vec[11].k, a, INT32_C(          14));
  simde_test_x86_assert_equal_i64x4(r, simde_x_mm256_loadu_epi64(test_vec[11].r));

  src = simde_x_mm256_loadu_epi64(test_vec[12].src);
  a = simde_x_mm256_loadu_epi64(test_vec[12].a);
  r = simde_mm256_mask_ror_epi64(src, test_vec[12].k, a, INT32_C(          42));
  simde_test_x86_assert_equal_i64x4(r, simde_x_mm256_loadu_epi64(test_vec[12].r));

  src = simde_x_mm256_loadu_epi64(test_vec[13].src);
  a = simde_x_mm256_loadu_epi64(test_vec[13].a);
  r = simde_mm256_mask_ror_epi64(src, test_vec[13].k, a, INT32_C(           7));
  simde_test_x86_assert_equal_i64x4(r, simde_x_mm256_loadu_epi64(test_vec[13].r));

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m256i src = simde_test_x86_random_i64x4();
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m256i a = simde_test_x86_random_i64x4();
    int imm8 = simde_test_codegen_random_i32() & 63;
    simde__m256i r;
    SIMDE_CONSTIFY_256_(simde_mm256_mask_ror_epi64, r, simde_mm256_setzero_si256(), imm8, src, k, a);

    simde_test_x86_write_i64x4(2, src, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i64x4(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, imm8, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i64x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm256_maskz_ror_epi64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask8 k;
    const int64_t a[4];
    int imm8;
    const int64_t r[4];
  } test_vec[] = {
    { UINT8_C(149),
      {  INT64_C(  307249185248985062),  INT64_C( 7318305126296892091), -INT64_C( 2328483313613749991), -INT64_C( 2367543231390225766) },
       INT32_C(          10),
      { -INT64_C(  468074313214061873),  INT64_C(                   0),  INT64_C( 5077786470187968560),  INT64_C(                   0) } },
    { UINT8_C(  0),
      {  INT64_C( 4549406829678661810), -INT64_C( 5129402990970960052),  INT64_C( 1532877857902211170),  INT64_C( 5004533360230409220) },
       INT32_C(          60),
      {  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0) } },
    { UINT8_C(235),
      { -INT64_C( 1117943577298082611),  INT64_C( 7426328612230542357), -INT64_C( 1109328874918173469),  INT64_C( 6299641471099068498) },
       INT32_C(         182),
      { -INT64_C( 1076090583244392511),  INT64_C( 4501940555740108188),  INT64_C(                   0), -INT64_C( 5527559392896923299) } },
    { UINT8_C(232),
      { -INT64_C( 3034368180861672408), -INT64_C( 7693625121353151791),  INT64_C( 3081984248176388955), -INT64_C( 1053326876029739563) },
       INT32_C(         185),
      {  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0), -INT64_C( 5698631615839802632) } },
    { UINT8_C( 33),
      {  INT64_C( 4553958902696494386),  INT64_C( 1704284457921070883), -INT64_C( 8826943455676804966), -INT64_C(  988770190374309177) },
       INT32_C(         244),
      {  INT64_C( 3357406924484322291),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0) } },
    { UINT8_C( 35),
      {  INT64_C( 2312762559776141729), -INT64_C( 9097990207420289220), -INT64_C( 5754071446866869261),  INT64_C( 2887958034165012662) },
       INT32_C(         200),
      { -INT64_C( 6836437204854028367),  INT64_C( 4359974212065868591),  INT64_C(                   0),  INT64_C(                   0) } },
    { UINT8_C(240),
      {  INT64_C( 7058611693276640425),  INT64_C( 3295431783303378678),  INT64_C( 2701829991517350879), -INT64_C( 2219428850194077976) },
       INT32_C(          53),
      {  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0) } },
    { UINT8_C(153),
      { -INT64_C( 7789598041680411217), -INT64_C( 3819498924663500156),  INT64_C( 1353038193828701159),  INT64_C( 1234385843813590824) },
       INT32_C(         240),
      { -INT64_C( 3901763729298058267),  INT64_C(                   0),  INT64_C(                   0),  INT64_C( 7737896951104409889) } },
    { UINT8_C(172),
      { -INT64_C( 7912129165770286159), -INT64_C( 1372895198118519323), -INT64_C( 2897183031733683290), -INT64_C( 1868126101319161942) },
       INT32_C(          49),
      {  INT64_C(                   0),  INT64_C(                   0), -INT64_C( 7948580539981403163), -INT64_C( 8459251458006224119) } },
    { UINT8_C(205),
      {  INT64_C(   86990620315497665),  INT64_C( 9141066287834145535),  INT64_C(  360446230241260387),  INT64_C( 4018574772986635939) },
       INT32_C(          12),
      {  INT64_C( 5480901984454306595),  INT64_C(                   0),  INT64_C( 3904708876498150027),  INT64_C( 7652596864259158894) } },
    { UINT8_C(132),
      { -INT64_C( 3600349490801569909),  INT64_C( 4574526577897998296), -INT64_C( 8189556542859476741),  INT64_C( 8185618762097659806) },
       INT32_C(          55),
      {  INT64_C(                   0),  INT64_C(                   0), -INT64_C( 5642045211983874276),  INT64_C(                   0) } },
    { UINT8_C( 25),
      { -INT64_C( 1703066628575347929),  INT64_C( 6354233271251082488),  INT64_C( 9120364662292397085),  INT64_C( 5321321967363883940) },
       INT32_C(          30),
      { -INT64_C( 4915981772875499598),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(   59688711656605835) } },
    { UINT8_C( 71),
      {  INT64_C( 6588686638786785876), -INT64_C( 3965658350976645147), -INT64_C( 3612400739287272008),  INT64_C( 8221168419998476037) },
       INT32_C(          40),
      { -INT64_C( 7570199463481086025), -INT64_C( 4782407429830150362), -INT64_C( 6143916538772726228),  INT64_C(                   0) } },
  };

  simde__m256i a, r;

  a = simde_x_mm256_loadu_epi64(test_vec[0].a);
  r = simde_mm256_maskz_ror_epi64(test_vec[0].k, a, INT32_C(          10));
  simde_test_x86_assert_equal_i64x4(r, simde_x_mm256_loadu_epi64(test_vec[0].r));

  a = simde_x_mm256_loadu_epi64(test_vec[1].a);
  r = simde_mm256_maskz_ror_epi64(test_vec[1].k, a, INT32_C(          60));
  simde_test_x86_assert_equal_i64x4(r, simde_x_mm256_loadu_epi64(test_vec[1].r));

  #if !(defined(HEDLEY_MSVC_VERSION) && defined(SIMDE_X86_AVX512F_NATIVE) && defined(SIMDE_X86_AVX512VL_NATIVE))
  a = simde_x_mm256_loadu_epi64(test_vec[2].a);
  r = simde_mm256_maskz_ror_epi64(test_vec[2].k, a, INT32_C(         182));
  simde_test_x86_assert_equal_i64x4(r, simde_x_mm256_loadu_epi64(test_vec[2].r));

  a = simde_x_mm256_loadu_epi64(test_vec[3].a);
  r = simde_mm256_maskz_ror_epi64(test_vec[3].k, a, INT32_C(         185));
  simde_test_x86_assert_equal_i64x4(r, simde_x_mm256_loadu_epi64(test_vec[3].r));

  a = simde_x_mm256_loadu_epi64(test_vec[4].a);
  r = simde_mm256_maskz_ror_epi64(test_vec[4].k, a, INT32_C(         244));
  simde_test_x86_assert_equal_i64x4(r, simde_x_mm256_loadu_epi64(test_vec[4].r));

  a = simde_x_mm256_loadu_epi64(test_vec[5].a);
  r = simde_mm256_maskz_ror_epi64(test_vec[5].k, a, INT32_C(         200));
  simde_test_x86_assert_equal_i64x4(r, simde_x_mm256_loadu_epi64(test_vec[5].r));
  #endif

  a = simde_x_mm256_loadu_epi64(test_vec[6].a);
  r = simde_mm256_maskz_ror_epi64(test_vec[6].k, a, INT32_C(          53));
  simde_test_x86_assert_equal_i64x4(r, simde_x_mm256_loadu_epi64(test_vec[6].r));

  #if !(defined(HEDLEY_MSVC_VERSION) && defined(SIMDE_X86_AVX512F_NATIVE) && defined(SIMDE_X86_AVX512VL_NATIVE))
  a = simde_x_mm256_loadu_epi64(test_vec[7].a);
  r = simde_mm256_maskz_ror_epi64(test_vec[7].k, a, INT32_C(         240));
  simde_test_x86_assert_equal_i64x4(r, simde_x_mm256_loadu_epi64(test_vec[7].r));
  #endif

  a = simde_x_mm256_loadu_epi64(test_vec[8].a);
  r = simde_mm256_maskz_ror_epi64(test_vec[8].k, a, INT32_C(          49));
  simde_test_x86_assert_equal_i64x4(r, simde_x_mm256_loadu_epi64(test_vec[8].r));

  a = simde_x_mm256_loadu_epi64(test_vec[9].a);
  r = simde_mm256_maskz_ror_epi64(test_vec[9].k, a, INT32_C(          12));
  simde_test_x86_assert_equal_i64x4(r, simde_x_mm256_loadu_epi64(test_vec[9].r));

  a = simde_x_mm256_loadu_epi64(test_vec[10].a);
  r = simde_mm256_maskz_ror_epi64(test_vec[10].k, a, INT32_C(          55));
  simde_test_x86_assert_equal_i64x4(r, simde_x_mm256_loadu_epi64(test_vec[10].r));

  a = simde_x_mm256_loadu_epi64(test_vec[11].a);
  r = simde_mm256_maskz_ror_epi64(test_vec[11].k, a, INT32_C(          30));
  simde_test_x86_assert_equal_i64x4(r, simde_x_mm256_loadu_epi64(test_vec[11].r));

  a = simde_x_mm256_loadu_epi64(test_vec[12].a);
  r = simde_mm256_maskz_ror_epi64(test_vec[12].k, a, INT32_C(          40));
  simde_test_x86_assert_equal_i64x4(r, simde_x_mm256_loadu_epi64(test_vec[12].r));

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m256i a = simde_test_x86_random_i64x4();
    int imm8 = simde_test_codegen_random_i32() & 63;
    simde__m256i r;
    SIMDE_CONSTIFY_256_(simde_mm256_maskz_ror_epi64, r, simde_mm256_setzero_si256(), imm8, k, a);

    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i64x4(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, imm8, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i64x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm512_ror_epi64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int64_t a[8];
    int imm8;
    const int64_t r[8];
  } test_vec[] = {
    { {  INT64_C( 7283046034800192151),  INT64_C( 6659433415371822896),  INT64_C( 7835529447074791257),  INT64_C( 3355990513387712462),
         INT64_C( 7725446030597728265),  INT64_C( 4154657381518921956), -INT64_C( 2540453440295621939), -INT64_C( 5443229434222883665) },
       INT32_C(         107),
      {  INT64_C( 8719358815766356562), -INT64_C( 1364850915302208159), -INT64_C( 8029636454815787092), -INT64_C(  942798484681665957),
        -INT64_C( 8684585685385124151), -INT64_C( 2591368062296443639), -INT64_C( 2176830346279282737),  INT64_C( 8460229850646875832) } },
    { {  INT64_C( 7794592465969855739), -INT64_C( 8330981470027459518), -INT64_C( 7431613464870051609), -INT64_C(  256755748622740899),
        -INT64_C( 5150139449314868850),  INT64_C( 9071985320329227739),  INT64_C( 5102843262252830538),  INT64_C( 9097411912887377218) },
       INT32_C(           0),
      {  INT64_C( 7794592465969855739), -INT64_C( 8330981470027459518), -INT64_C( 7431613464870051609), -INT64_C(  256755748622740899),
        -INT64_C( 5150139449314868850),  INT64_C( 9071985320329227739),  INT64_C( 5102843262252830538),  INT64_C( 9097411912887377218) } },
    { { -INT64_C( 2064630709511970781),  INT64_C( 8548241718449815071),  INT64_C( 9145346906400846180),  INT64_C( 7692593767680584267),
         INT64_C(  281406686787923637),  INT64_C( 2306986207326586624), -INT64_C( 2770362976349732480), -INT64_C( 3202933317382665764) },
       INT32_C(         212),
      { -INT64_C( 3314017976032366606),  INT64_C(  279776686902924966), -INT64_C( 2948089815640774021), -INT64_C( 4421208083895393089),
        -INT64_C( 6995409366889381834), -INT64_C( 3139006740163741482),  INT64_C( 8941912010306146556),  INT64_C( 5232563985937719842) } },
    { { -INT64_C( 4520443021439025481), -INT64_C( 7509849093907068872), -INT64_C(  335354494433864615), -INT64_C( 7996520631794408326),
         INT64_C( 2461935084728009060),  INT64_C(  969860188189952981), -INT64_C(  805974480961477129), -INT64_C( 6203066074061955201) },
       INT32_C(           9),
      {  INT64_C( 6620469661213122015),  INT64_C( 2038973756069408932),  INT64_C( 3241936742459815978),  INT64_C( 4415923828973594610),
        -INT64_C( 5615683867996019616), -INT64_C( 1547344013635392123), -INT64_C(  289804545059839630), -INT64_C( 4623801381853290161) } },
    { { -INT64_C(  255876934799049282),  INT64_C( 5142912645653456788),  INT64_C( 1422712857710768102), -INT64_C( 7439155095784347451),
         INT64_C( 6796106429534886156), -INT64_C( 8387591856591382139),  INT64_C( 1610791480860923000), -INT64_C(  952326714084223146) },
       INT32_C(         128),
      { -INT64_C(  255876934799049282),  INT64_C( 5142912645653456788),  INT64_C( 1422712857710768102), -INT64_C( 7439155095784347451),
         INT64_C( 6796106429534886156), -INT64_C( 8387591856591382139),  INT64_C( 1610791480860923000), -INT64_C(  952326714084223146) } },
    { { -INT64_C( 7680163555111757934),  INT64_C( 3070066092293489884), -INT64_C(  917567685972134210), -INT64_C( 7739388675034378803),
        -INT64_C( 5672258623574883646),  INT64_C( 4043565585588906266),  INT64_C( 5807270239100755351),  INT64_C( 7652520285397941406) },
       INT32_C(         120),
      {  INT64_C( 7679745778311991957), -INT64_C( 7273075542377309142),  INT64_C( 4910345349357813491), -INT64_C( 7481884921878950508),
         INT64_C( 5194574187884364465),  INT64_C( 2135121783025113656), -INT64_C( 7525088760680310960),  INT64_C( 3690321248660528746) } },
    { {  INT64_C( 5188995379244197366),  INT64_C(  135051356380602532), -INT64_C( 7305983243112581539), -INT64_C( 6563677948090200540),
        -INT64_C( 8098113234047539322),  INT64_C( 5140765418826964440), -INT64_C( 4923035176713148383),  INT64_C( 6484692885174792620) },
       INT32_C(          41),
      { -INT64_C( 1799048194195979903),  INT64_C( 4548002375041871846),  INT64_C( 8754338772575669751), -INT64_C( 2932403665659333488),
         INT64_C( 8478829439210737372),  INT64_C( 8406924793938684885), -INT64_C( 3780313029768522002), -INT64_C( 1644609528858345696) } },
    { {  INT64_C( 5879852182599322474),  INT64_C( 3480679538186842393),  INT64_C( 9204870195610188728), -INT64_C( 2755492207764390779),
        -INT64_C( 1330049717327075631), -INT64_C( 5300325551579913305),  INT64_C( 2782056480815930736), -INT64_C( 3828455537417817194) },
       INT32_C(         253),
      { -INT64_C( 8301414760334075054), -INT64_C( 9048051841924364087), -INT64_C(  148014729956696637), -INT64_C( 3597193588405574610),
         INT64_C( 7806346335092946575), -INT64_C( 5509116265220203203),  INT64_C( 3809707772817894273),  INT64_C( 6265843848076565686) } },
    { { -INT64_C( 3372436975054137683),  INT64_C( 8763843988365494453),  INT64_C( 6058810398572482995), -INT64_C( 8664179280511928477),
        -INT64_C( 6107404507649326084), -INT64_C( 3021357749001996821),  INT64_C(  528552436549708813), -INT64_C( 4493698782383694270) },
       INT32_C(          48),
      { -INT64_C( 5588850033829228238),  INT64_C( 7902886574154938783),  INT64_C( 4032094248147047445), -INT64_C( 6423994776036341822),
         INT64_C( 2591098043616766782), -INT64_C(  350551396536560111), -INT64_C( 3772888704821164203),  INT64_C( 3225734475203920291) } },
    { {  INT64_C( 4916080463766908087),  INT64_C( 6590966066042260072), -INT64_C( 5766071059474101093), -INT64_C( 1671224476648301063),
        -INT64_C( 5444355742565212405), -INT64_C(  567276133231719410),  INT64_C( 5190627609755943533),  INT64_C( 2487815583592183917) },
       INT32_C(          30),
      { -INT64_C( 8628418748524153718), -INT64_C( 3140933491804388643),  INT64_C( 8758149351599715247), -INT64_C( 6502503075209905979),
        -INT64_C( 5320021994278286032),  INT64_C( 1489055660527224179),  INT64_C( 7159045231191736637),  INT64_C( 8846725208566529118) } },
    { { -INT64_C( 6222134871874092845), -INT64_C( 7426304627573668310), -INT64_C( 8695728017241999289), -INT64_C( 4964663437009758192),
         INT64_C( 3147526861246789817),  INT64_C( 1003093006410272522),  INT64_C( 7828121863623658411), -INT64_C(  103594586150318869) },
       INT32_C(          45),
      {  INT64_C( 5361265967556807988), -INT64_C( 5022431615770114173), -INT64_C( 8393118678769714540), -INT64_C( 4088286259531360049),
         INT64_C( 1731683447871200626), -INT64_C( 7047396630356529315), -INT64_C( 7286580043808283368), -INT64_C( 6183830577458711425) } },
    { { -INT64_C( 3977702109958458769), -INT64_C( 2389274489543870704),  INT64_C(  822231041338735274), -INT64_C( 7712399911302858725),
         INT64_C(   38521324381770431), -INT64_C( 6921306996490871151),  INT64_C( 9214258618012351757), -INT64_C( 5453858093323982697) },
       INT32_C(          19),
      {  INT64_C( 6218900548580552499), -INT64_C( 5268617986877401222),  INT64_C( 8022390248255836873),  INT64_C( 4540598876572520737),
        -INT64_C( 5595757647906334719), -INT64_C( 8371571589929590121), -INT64_C( 6367614901461149082),  INT64_C( 2095007849248634753) } },
    { {  INT64_C( 5826883156342734135),  INT64_C( 8192932888638967762),  INT64_C( 8077480235629580996), -INT64_C(  211781583724320519),
        -INT64_C( 6538202107600268393),  INT64_C( 2157285074746487666), -INT64_C( 3191765869261102647),  INT64_C(  701276705597217017) },
       INT32_C(           2),
      { -INT64_C( 3154965229341704371), -INT64_C( 7175138814695033868),  INT64_C( 2019370058907395249),  INT64_C( 9170426640923695678),
        -INT64_C( 1634550526900067099), -INT64_C( 8684050768168153892),  INT64_C( 8425430569539500146),  INT64_C( 4787005194826692158) } },
  };

  simde__m512i a, r;

  #if !(defined(HEDLEY_MSVC_VERSION) && defined(SIMDE_X86_AVX512F_NATIVE) && defined(SIMDE_X86_AVX512VL_NATIVE))
  a = simde_mm512_loadu_epi64(test_vec[0].a);
  r = simde_mm512_ror_epi64(a, INT32_C(         107));
  simde_test_x86_assert_equal_i64x8(r, simde_mm512_loadu_epi64(test_vec[0].r));
  #endif

  a = simde_mm512_loadu_epi64(test_vec[1].a);
  r = simde_mm512_ror_epi64(a, INT32_C(           0));
  simde_test_x86_assert_equal_i64x8(r, simde_mm512_loadu_epi64(test_vec[1].r));

  #if !(defined(HEDLEY_MSVC_VERSION) && defined(SIMDE_X86_AVX512F_NATIVE) && defined(SIMDE_X86_AVX512VL_NATIVE))
  a = simde_mm512_loadu_epi64(test_vec[2].a);
  r = simde_mm512_ror_epi64(a, INT32_C(         212));
  simde_test_x86_assert_equal_i64x8(r, simde_mm512_loadu_epi64(test_vec[2].r));
  #endif

  a = simde_mm512_loadu_epi64(test_vec[3].a);
  r = simde_mm512_ror_epi64(a, INT32_C(           9));
  simde_test_x86_assert_equal_i64x8(r, simde_mm512_loadu_epi64(test_vec[3].r));

  #if !(defined(HEDLEY_MSVC_VERSION) && defined(SIMDE_X86_AVX512F_NATIVE) && defined(SIMDE_X86_AVX512VL_NATIVE))
  a = simde_mm512_loadu_epi64(test_vec[4].a);
  r = simde_mm512_ror_epi64(a, INT32_C(         128));
  simde_test_x86_assert_equal_i64x8(r, simde_mm512_loadu_epi64(test_vec[4].r));

  a = simde_mm512_loadu_epi64(test_vec[5].a);
  r = simde_mm512_ror_epi64(a, INT32_C(         120));
  simde_test_x86_assert_equal_i64x8(r, simde_mm512_loadu_epi64(test_vec[5].r));
  #endif

  a = simde_mm512_loadu_epi64(test_vec[6].a);
  r = simde_mm512_ror_epi64(a, INT32_C(          41));
  simde_test_x86_assert_equal_i64x8(r, simde_mm512_loadu_epi64(test_vec[6].r));

  #if !(defined(HEDLEY_MSVC_VERSION) && defined(SIMDE_X86_AVX512F_NATIVE) && defined(SIMDE_X86_AVX512VL_NATIVE))
  a = simde_mm512_loadu_epi64(test_vec[7].a);
  r = simde_mm512_ror_epi64(a, INT32_C(         253));
  simde_test_x86_assert_equal_i64x8(r, simde_mm512_loadu_epi64(test_vec[7].r));
  #endif

  a = simde_mm512_loadu_epi64(test_vec[8].a);
  r = simde_mm512_ror_epi64(a, INT32_C(          48));
  simde_test_x86_assert_equal_i64x8(r, simde_mm512_loadu_epi64(test_vec[8].r));

  a = simde_mm512_loadu_epi64(test_vec[9].a);
  r = simde_mm512_ror_epi64(a, INT32_C(          30));
  simde_test_x86_assert_equal_i64x8(r, simde_mm512_loadu_epi64(test_vec[9].r));

  a = simde_mm512_loadu_epi64(test_vec[10].a);
  r = simde_mm512_ror_epi64(a, INT32_C(          45));
  simde_test_x86_assert_equal_i64x8(r, simde_mm512_loadu_epi64(test_vec[10].r));

  a = simde_mm512_loadu_epi64(test_vec[11].a);
  r = simde_mm512_ror_epi64(a, INT32_C(          19));
  simde_test_x86_assert_equal_i64x8(r, simde_mm512_loadu_epi64(test_vec[11].r));

  a = simde_mm512_loadu_epi64(test_vec[12].a);
  r = simde_mm512_ror_epi64(a, INT32_C(           2));
  simde_test_x86_assert_equal_i64x8(r, simde_mm512_loadu_epi64(test_vec[12].r));

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m512i a = simde_test_x86_random_i64x8();
    int imm8 = simde_test_codegen_random_i32() & 63;
    simde__m512i r;
    SIMDE_CONSTIFY_256_(simde_mm512_ror_epi64, r, simde_mm512_setzero_si512(), imm8, a);

    simde_test_x86_write_i64x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_i32(2, imm8, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i64x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm512_mask_ror_epi64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int64_t src[8];
    const simde__mmask8 k;
    const int64_t a[8];
    int imm8;
    const int64_t r[8];
  } test_vec[] = {
    { { -INT64_C( 1004901167955797611),  INT64_C( 7900936511854171090), -INT64_C( 7674560527853253732), -INT64_C( 3200479067780157271),
        -INT64_C( 1882749749768735690),  INT64_C( 4235652618043185781), -INT64_C(  140664553506284901), -INT64_C( 4376309658254315726) },
      UINT8_C(109),
      {  INT64_C( 7633431560326262872), -INT64_C( 1479079457619228209), -INT64_C( 1406742676056772603), -INT64_C( 8680621013517866270),
         INT64_C( 4388177764964960493),  INT64_C( 3618242272893267001), -INT64_C( 7534816066145716348),  INT64_C( 1266701321721014238) },
       INT32_C(          66),
      {  INT64_C( 1908357890081565718),  INT64_C( 7900936511854171090),  INT64_C( 8871686367840582657), -INT64_C( 6781841271806854472),
        -INT64_C( 1882749749768735690),  INT64_C( 5516246586650704654),  INT64_C( 2727982001890958817), -INT64_C( 4376309658254315726) } },
    { { -INT64_C( 8284083031276555387),  INT64_C( 7827319611027570842),  INT64_C( 1880735482988727853), -INT64_C( 4043184346471092751),
         INT64_C( 7933248886649769516),  INT64_C( 4607794922048575695), -INT64_C( 7040704372437944773),  INT64_C( 6564757522208618001) },
      UINT8_C(131),
      { -INT64_C( 2882929387150776673),  INT64_C( 7834899366663455571), -INT64_C( 5987615733417645198), -INT64_C(  810588197483758967),
         INT64_C( 3598975190532495388),  INT64_C( 8468574905593617315), -INT64_C( 2289742484415471785),  INT64_C( 7473405044333548653) },
       INT32_C(         246),
      { -INT64_C(  640640648867053729), -INT64_C( 1396720600276447822),  INT64_C( 1880735482988727853), -INT64_C( 4043184346471092751),
         INT64_C( 7933248886649769516),  INT64_C( 4607794922048575695), -INT64_C( 7040704372437944773), -INT64_C( 2632025191910099554) } },
    { {  INT64_C( 5959870139225961976),  INT64_C( 3604871860095236898), -INT64_C( 6956602004280819642), -INT64_C(  227562605835310323),
        -INT64_C( 5431254760317985538), -INT64_C( 4497348373804849015), -INT64_C( 1915460474662246283), -INT64_C(  642113720739598315) },
      UINT8_C(157),
      {  INT64_C( 5658461662562174382),  INT64_C( 3007430939036477970),  INT64_C( 7061336291929065470), -INT64_C( 2581316655764531248),
         INT64_C( 6038304835790986648),  INT64_C( 2158163340983702857), -INT64_C( 6039321753907956259),  INT64_C( 8441270575224883995) },
       INT32_C(         199),
      {  INT64_C( 6673505383228137099),  INT64_C( 3604871860095236898), -INT64_C(  233063686371015921), -INT64_C( 6793580375938386385),
         INT64_C( 3505938770350158011), -INT64_C( 4497348373804849015), -INT64_C( 1915460474662246283),  INT64_C( 3957057504417052950) } },
    { {  INT64_C( 8318136780676906844),  INT64_C( 3744628015797199435), -INT64_C( 7998642859288877157),  INT64_C( 9103456147515712646),
        -INT64_C( 1116731470000181064),  INT64_C( 4863625537112314356),  INT64_C(  106953326808686392),  INT64_C( 3656539688636678174) },
      UINT8_C( 83),
      { -INT64_C( 3357459088199368735), -INT64_C( 7905016693851049214),  INT64_C( 3660879703424448183), -INT64_C( 5957455484525277604),
         INT64_C( 3795839812966042140), -INT64_C( 7349711986851633605),  INT64_C( 8623576467307695561),  INT64_C( 5954541795692402728) },
       INT32_C(          18),
      {  INT64_C( 1150797634591513854),  INT64_C( 7836444302611629278), -INT64_C( 7998642859288877157),  INT64_C( 9103456147515712646),
         INT64_C( 1335050294518396680),  INT64_C( 4863625537112314356), -INT64_C( 4363321823890841902),  INT64_C( 3656539688636678174) } },
    { { -INT64_C( 1876662928116425910),  INT64_C( 2204735227543221588), -INT64_C( 3170238789736643100), -INT64_C( 5752128727900838956),
        -INT64_C( 5037229564796426960),  INT64_C( 5134227146291058719), -INT64_C( 5320908533467392586), -INT64_C( 3166653259484147976) },
      UINT8_C(110),
      { -INT64_C( 5292416626219219389), -INT64_C( 4211320918794195097),  INT64_C( 6341732423489217205), -INT64_C( 5750586079334080519),
        -INT64_C(  167850801033771306), -INT64_C( 2661518363643755173),  INT64_C(  911951519696664133),  INT64_C( 5360409953415701318) },
       INT32_C(           6),
      { -INT64_C( 1876662928116425910), -INT64_C( 6983330916997241155), -INT64_C( 3071444568551810166), -INT64_C( 1819235164399865473),
        -INT64_C( 5037229564796426960),  INT64_C( 8028864307815995157),  INT64_C( 1455401123253819097), -INT64_C( 3166653259484147976) } },
    { { -INT64_C( 3038401772879549906), -INT64_C( 5880410720122640944),  INT64_C( 2555382326087060604), -INT64_C( 8418445560583955830),
         INT64_C(  151972509797172374), -INT64_C( 2442784565021389617), -INT64_C( 1704023815578594168),  INT64_C(  782118300463712242) },
      UINT8_C(104),
      {  INT64_C( 4011189305658134768),  INT64_C(  267813743102596531),  INT64_C( 1162291857026313752),  INT64_C( 4309538347933790402),
        -INT64_C( 5295741665979045666), -INT64_C( 6267149684789929260),  INT64_C( 8423132844776777611), -INT64_C( 3102793266180233110) },
       INT32_C(          17),
      { -INT64_C( 3038401772879549906), -INT64_C( 5880410720122640944),  INT64_C( 2555382326087060604),  INT64_C( 4062561218033201986),
         INT64_C(  151972509797172374), -INT64_C( 8256694043899559438),  INT64_C( 3730592867238341228),  INT64_C(  782118300463712242) } },
    { {  INT64_C( 5376647841362714565), -INT64_C( 4851279451134909619), -INT64_C( 1160509263606411067), -INT64_C( 6784141925835024717),
        -INT64_C( 6808078880411507583),  INT64_C(  595079068420503419),  INT64_C( 3503269981493686966), -INT64_C( 4219365680439074061) },
      UINT8_C(113),
      { -INT64_C(  432231749644779604),  INT64_C( 4232334475221894881),  INT64_C( 7822443635520531325),  INT64_C( 8870533046041927131),
         INT64_C( 3023041563287674998), -INT64_C(  897645182828203641),  INT64_C(  274186487565467991),  INT64_C( 7764988563823558521) },
       INT32_C(         167),
      {  INT64_C(  507655510874652879), -INT64_C( 4851279451134909619), -INT64_C( 1160509263606411067), -INT64_C( 6784141925835024717),
        -INT64_C( 7930274065735751680), -INT64_C( 1396575054876699176),  INT64_C( 5819524292060617782), -INT64_C( 4219365680439074061) } },
    { {  INT64_C(   43145430222526915), -INT64_C( 8291830169586162892),  INT64_C( 3412668837807569820), -INT64_C( 6585950535829217533),
         INT64_C( 3450752354938172249), -INT64_C(  964712232074422613),  INT64_C( 7839751456097250402), -INT64_C( 4608956586506360957) },
      UINT8_C(101),
      {  INT64_C( 6641559883313357815),  INT64_C(  311775146110237513),  INT64_C( 2563632014656663724), -INT64_C(  574127581590521615),
         INT64_C( 4670131621796014317), -INT64_C( 3190372459720113698), -INT64_C( 1057089169804548491),  INT64_C( 1542654569875824239) },
       INT32_C(           4),
      {  INT64_C( 8485548024955013695), -INT64_C( 8291830169586162892), -INT64_C( 4451459017511346422), -INT64_C( 6585950535829217533),
         INT64_C( 3450752354938172249), -INT64_C( 1352319783339354083),  INT64_C( 6851460954528297575), -INT64_C( 4608956586506360957) } },
  };

  simde__m512i src, a, r;

  #if !(defined(HEDLEY_MSVC_VERSION) && defined(SIMDE_X86_AVX512F_NATIVE) && defined(SIMDE_X86_AVX512VL_NATIVE))
  src = simde_mm512_loadu_epi64(test_vec[0].src);
  a = simde_mm512_loadu_epi64(test_vec[0].a);
  r = simde_mm512_mask_ror_epi64(src, test_vec[0].k, a, INT32_C(          66));
  simde_test_x86_assert_equal_i64x8(r, simde_mm512_loadu_epi64(test_vec[0].r));

  src = simde_mm512_loadu_epi64(test_vec[1].src);
  a = simde_mm512_loadu_epi64(test_vec[1].a);
  r = simde_mm512_mask_ror_epi64(src, test_vec[1].k, a, INT32_C(         246));
  simde_test_x86_assert_equal_i64x8(r, simde_mm512_loadu_epi64(test_vec[1].r));

  src = simde_mm512_loadu_epi64(test_vec[2].src);
  a = simde_mm512_loadu_epi64(test_vec[2].a);
  r = simde_mm512_mask_ror_epi64(src, test_vec[2].k, a, INT32_C(         199));
  simde_test_x86_assert_equal_i64x8(r, simde_mm512_loadu_epi64(test_vec[2].r));
  #endif

  src = simde_mm512_loadu_epi64(test_vec[3].src);
  a = simde_mm512_loadu_epi64(test_vec[3].a);
  r = simde_mm512_mask_ror_epi64(src, test_vec[3].k, a, INT32_C(          18));
  simde_test_x86_assert_equal_i64x8(r, simde_mm512_loadu_epi64(test_vec[3].r));

  src = simde_mm512_loadu_epi64(test_vec[4].src);
  a = simde_mm512_loadu_epi64(test_vec[4].a);
  r = simde_mm512_mask_ror_epi64(src, test_vec[4].k, a, INT32_C(           6));
  simde_test_x86_assert_equal_i64x8(r, simde_mm512_loadu_epi64(test_vec[4].r));

  src = simde_mm512_loadu_epi64(test_vec[5].src);
  a = simde_mm512_loadu_epi64(test_vec[5].a);
  r = simde_mm512_mask_ror_epi64(src, test_vec[5].k, a, INT32_C(          17));
  simde_test_x86_assert_equal_i64x8(r, simde_mm512_loadu_epi64(test_vec[5].r));

  #if !(defined(HEDLEY_MSVC_VERSION) && defined(SIMDE_X86_AVX512F_NATIVE) && defined(SIMDE_X86_AVX512VL_NATIVE))
  src = simde_mm512_loadu_epi64(test_vec[6].src);
  a = simde_mm512_loadu_epi64(test_vec[6].a);
  r = simde_mm512_mask_ror_epi64(src, test_vec[6].k, a, INT32_C(         167));
  simde_test_x86_assert_equal_i64x8(r, simde_mm512_loadu_epi64(test_vec[6].r));
  #endif

  src = simde_mm512_loadu_epi64(test_vec[7].src);
  a = simde_mm512_loadu_epi64(test_vec[7].a);
  r = simde_mm512_mask_ror_epi64(src, test_vec[7].k, a, INT32_C(           4));
  simde_test_x86_assert_equal_i64x8(r, simde_mm512_loadu_epi64(test_vec[7].r));

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m512i src = simde_test_x86_random_i64x8();
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m512i a = simde_test_x86_random_i64x8();
    int imm8 = simde_test_codegen_random_i32() & 255;
    simde__m512i r;
    SIMDE_CONSTIFY_256_(simde_mm512_mask_ror_epi64, r, simde_mm512_setzero_si512(), imm8, src, k, a);

    simde_test_x86_write_i64x8(2, src, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i64x8(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, imm8, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i64x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm512_maskz_ror_epi64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask8 k;
    const int64_t a[8];
    int imm8;
    const int64_t r[8];
  } test_vec[] = {
    { UINT8_C(131),
      { -INT64_C(  937004436920648873),  INT64_C( 3240226364223640272),  INT64_C( 1797511831877314796), -INT64_C( 1812672945657739404),
         INT64_C( 2427929828641356114), -INT64_C( 7173935481676621681), -INT64_C( 8319459024598331913),  INT64_C( 1212798429372196703) },
       INT32_C(         242),
      { -INT64_C( 4189625181564175169), -INT64_C( 1860692695967331523),  INT64_C(                   0),  INT64_C(                   0),
         INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),  INT64_C( 3346099448883692597) } },
    { UINT8_C( 80),
      { -INT64_C( 8409868137056410495), -INT64_C( 6431996453987358826), -INT64_C( 2097001593885603712),  INT64_C( 5164530108615488968),
         INT64_C( 5153010442026716284),  INT64_C( 8792900016297149714), -INT64_C( 3964426616764822545),  INT64_C( 7244268597057671291) },
       INT32_C(          91),
      {  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),
         INT64_C( 2031562725232309823),  INT64_C(                   0),  INT64_C( 3756422073131524067),  INT64_C(                   0) } },
    { UINT8_C(148),
      { -INT64_C( 1811002029155855137),  INT64_C( 9158332595888805901), -INT64_C( 3196645323783282454),  INT64_C( 4882248772487088068),
         INT64_C( 8985814233780873359),  INT64_C( 7122633543080315231), -INT64_C( 3214515635449179251),  INT64_C( 6660473985861456583) },
       INT32_C(          42),
      {  INT64_C(                   0),  INT64_C(                   0),  INT64_C(   67201017803237583),  INT64_C(                   0),
        -INT64_C( 7209266733614420735),  INT64_C(                   0),  INT64_C(                   0),  INT64_C( 8307663726473321392) } },
    { UINT8_C(157),
      {  INT64_C( 6403930290304849630),  INT64_C( 2093739927654449452), -INT64_C( 6685576185979280935), -INT64_C( 7155825366336170882),
         INT64_C( 3350646246170930556), -INT64_C( 5503331835462130652),  INT64_C( 1342730836845167646),  INT64_C( 5928101425982107626) },
       INT32_C(         133),
      { -INT64_C(  952798683034820426),  INT64_C(                   0), -INT64_C( 3667688769632393458), -INT64_C(  800080295001428829),
        -INT64_C( 2201135314020852373),  INT64_C(                   0),  INT64_C(                   0),  INT64_C( 5949860692596175743) } },
    { UINT8_C( 42),
      {  INT64_C( 2321836386674521849),  INT64_C( 6884383192896170865), -INT64_C( 7338912725880693536), -INT64_C( 1393960899741452235),
         INT64_C( 4135011200185071197), -INT64_C( 4623585077309235091),  INT64_C( 4950077279361244757), -INT64_C( 2914841086729858387) },
       INT32_C(          93),
      {  INT64_C(                   0), -INT64_C( 5622924957251932081),  INT64_C(                   0), -INT64_C( 2232728031183683693),
         INT64_C(                   0), -INT64_C( 5657361785948352781),  INT64_C(                   0),  INT64_C(                   0) } },
    { UINT8_C( 88),
      {  INT64_C( 5114184329098255994), -INT64_C(  270863834022168560), -INT64_C( 6219389441448181404),  INT64_C( 1874671309678872534),
         INT64_C( 1467098173703309705),  INT64_C( 1057078908593305575),  INT64_C( 8496873711331529984), -INT64_C( 6470224487003328132) },
       INT32_C(         238),
      {  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0), -INT64_C( 5873063237803022320),
        -INT64_C( 5183545490022313616),  INT64_C(                   0), -INT64_C( 2991228988342282325),  INT64_C(                   0) } },
    { UINT8_C(153),
      { -INT64_C( 4054877627444361703),  INT64_C(  273884009346877913), -INT64_C( 8646741530725367053),  INT64_C( 8994647656180917968),
         INT64_C( 6592504056274244462),  INT64_C( 4621070681395315728),  INT64_C(  758333423032246426), -INT64_C( 3194714162818843445) },
       INT32_C(         108),
      { -INT64_C( 1981293563335640158),  INT64_C(                   0),  INT64_C(                   0), -INT64_C( 8776487173277364938),
         INT64_C( 8659129904788781012),  INT64_C(                   0),  INT64_C(                   0), -INT64_C( 8767694424428954975) } },
    { UINT8_C(125),
      {  INT64_C( 3141731139078408455),  INT64_C( 2425121318069721548),  INT64_C( 1128744301647147336),  INT64_C( 1114756390779059652),
         INT64_C( 9129346962957207218), -INT64_C( 9085008150181284147), -INT64_C( 5239813980791842749), -INT64_C( 2376728330755718163) },
       INT32_C(          48),
      { -INT64_C( 6065420103438619751),  INT64_C(                   0),  INT64_C( 1942817172145835946),  INT64_C( 7568294206628958072),
        -INT64_C(  814722332064842063), -INT64_C( 7982407231149866517),  INT64_C( 8138631002806531912),  INT64_C(                   0) } },
    { UINT8_C( 75),
      {  INT64_C(   74189908091298523),  INT64_C( 3501240852354303305), -INT64_C( 6916353479653350672),  INT64_C( 4788346094237866014),
         INT64_C(  240757562911237889), -INT64_C( 2626205606100336036),  INT64_C( 1243406860383667833), -INT64_C( 8108258827780297009) },
       INT32_C(          20),
      {  INT64_C( 3903970036799586523), -INT64_C( 6893723460879510566),  INT64_C(                   0), -INT64_C( 3061915414507916662),
         INT64_C(                   0),  INT64_C(                   0),  INT64_C( 4352607080356461063),  INT64_C(                   0) } },
    { UINT8_C( 32),
      { -INT64_C( 6185173111890210243), -INT64_C( 1215755878957644698),  INT64_C( 1838021070750167557),  INT64_C( 3700127065348903279),
         INT64_C( 1624845844806293007),  INT64_C( 8721330028677410976),  INT64_C( 3178396457580152725), -INT64_C( 7698411501649589761) },
       INT32_C(          21),
      {  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),
         INT64_C(                   0),  INT64_C( 2127110557656654018),  INT64_C(                   0),  INT64_C(                   0) } },
    { UINT8_C( 55),
      {  INT64_C(   83581153240963588), -INT64_C(  253160289928306184), -INT64_C( 3656096001380603469),  INT64_C( 6119449954477070105),
        -INT64_C( 5935689652747320319), -INT64_C( 9089132873202714926), -INT64_C( 2202682668062222446),  INT64_C( 8789482176981160279) },
       INT32_C(           7),
      {  INT64_C(  577113730063118516), -INT64_C( 1010784131296055997),  INT64_C( 7465426529933719379),  INT64_C(                   0),
         INT64_C(  241857800739623304), -INT64_C( 6556192313985410451),  INT64_C(                   0),  INT64_C(                   0) } },
    { UINT8_C( 52),
      {  INT64_C(   53452860578769592), -INT64_C(  260306643666649149),  INT64_C( 6839835180020221090),  INT64_C( 3903392163956090356),
        -INT64_C( 2565958768300576436), -INT64_C( 3631350272938740191), -INT64_C( 2713650879931552482), -INT64_C( 1493791416301519471) },
       INT32_C(          46),
      {  INT64_C(                   0),  INT64_C(                   0), -INT64_C( 1770533347579561041),  INT64_C(                   0),
        -INT64_C( 8619453641218887281),  INT64_C( 7541974528302724715),  INT64_C(                   0),  INT64_C(                   0) } },
    { UINT8_C( 76),
      {  INT64_C( 8345745814054576817),  INT64_C(  898903397285142437),  INT64_C( 2413836104464421859),  INT64_C( 7612656463656217328),
        -INT64_C( 4267754252986674248), -INT64_C( 4147868156253808765), -INT64_C( 6311471929359987677),  INT64_C(  554126713102121359) },
       INT32_C(          58),
      {  INT64_C(                   0),  INT64_C(                   0),  INT64_C( 6911558096046586056),  INT64_C( 7594667757549567002),
         INT64_C(                   0),  INT64_C(                   0),  INT64_C( 1894166142570924266),  INT64_C(                   0) } },
    { UINT8_C(166),
      { -INT64_C( 4442363480625275873), -INT64_C( 1530892074031439876),  INT64_C( 1269945182790969751),  INT64_C( 2295045805897918065),
        -INT64_C( 8289174665804053952), -INT64_C( 6863954181844772082),  INT64_C( 7582812693626632383), -INT64_C( 1489436202848483787) },
       INT32_C(          56),
      {  INT64_C(                   0), -INT64_C( 4526745404148024086), -INT64_C( 6935426532283672815),  INT64_C(                   0),
         INT64_C(                   0), -INT64_C( 4731583549854249312),  INT64_C(                   0),  INT64_C( 6085957618688734699) } },
  };

  simde__m512i a, r;

  #if !(defined(HEDLEY_MSVC_VERSION) && defined(SIMDE_X86_AVX512F_NATIVE) && defined(SIMDE_X86_AVX512VL_NATIVE))
  a = simde_mm512_loadu_epi64(test_vec[0].a);
  r = simde_mm512_maskz_ror_epi64(test_vec[0].k, a, INT32_C(         242));
  simde_test_x86_assert_equal_i64x8(r, simde_mm512_loadu_epi64(test_vec[0].r));

  a = simde_mm512_loadu_epi64(test_vec[1].a);
  r = simde_mm512_maskz_ror_epi64(test_vec[1].k, a, INT32_C(          91));
  simde_test_x86_assert_equal_i64x8(r, simde_mm512_loadu_epi64(test_vec[1].r));
  #endif

  a = simde_mm512_loadu_epi64(test_vec[2].a);
  r = simde_mm512_maskz_ror_epi64(test_vec[2].k, a, INT32_C(          42));
  simde_test_x86_assert_equal_i64x8(r, simde_mm512_loadu_epi64(test_vec[2].r));

  #if !(defined(HEDLEY_MSVC_VERSION) && defined(SIMDE_X86_AVX512F_NATIVE) && defined(SIMDE_X86_AVX512VL_NATIVE))
  a = simde_mm512_loadu_epi64(test_vec[3].a);
  r = simde_mm512_maskz_ror_epi64(test_vec[3].k, a, INT32_C(         133));
  simde_test_x86_assert_equal_i64x8(r, simde_mm512_loadu_epi64(test_vec[3].r));

  a = simde_mm512_loadu_epi64(test_vec[4].a);
  r = simde_mm512_maskz_ror_epi64(test_vec[4].k, a, INT32_C(          93));
  simde_test_x86_assert_equal_i64x8(r, simde_mm512_loadu_epi64(test_vec[4].r));

  a = simde_mm512_loadu_epi64(test_vec[5].a);
  r = simde_mm512_maskz_ror_epi64(test_vec[5].k, a, INT32_C(         238));
  simde_test_x86_assert_equal_i64x8(r, simde_mm512_loadu_epi64(test_vec[5].r));

  a = simde_mm512_loadu_epi64(test_vec[6].a);
  r = simde_mm512_maskz_ror_epi64(test_vec[6].k, a, INT32_C(         108));
  simde_test_x86_assert_equal_i64x8(r, simde_mm512_loadu_epi64(test_vec[6].r));
  #endif

  a = simde_mm512_loadu_epi64(test_vec[7].a);
  r = simde_mm512_maskz_ror_epi64(test_vec[7].k, a, INT32_C(          48));
  simde_test_x86_assert_equal_i64x8(r, simde_mm512_loadu_epi64(test_vec[7].r));

  a = simde_mm512_loadu_epi64(test_vec[8].a);
  r = simde_mm512_maskz_ror_epi64(test_vec[8].k, a, INT32_C(          20));
  simde_test_x86_assert_equal_i64x8(r, simde_mm512_loadu_epi64(test_vec[8].r));

  a = simde_mm512_loadu_epi64(test_vec[9].a);
  r = simde_mm512_maskz_ror_epi64(test_vec[9].k, a, INT32_C(          21));
  simde_test_x86_assert_equal_i64x8(r, simde_mm512_loadu_epi64(test_vec[9].r));

  a = simde_mm512_loadu_epi64(test_vec[10].a);
  r = simde_mm512_maskz_ror_epi64(test_vec[10].k, a, INT32_C(           7));
  simde_test_x86_assert_equal_i64x8(r, simde_mm512_loadu_epi64(test_vec[10].r));

  a = simde_mm512_loadu_epi64(test_vec[11].a);
  r = simde_mm512_maskz_ror_epi64(test_vec[11].k, a, INT32_C(          46));
  simde_test_x86_assert_equal_i64x8(r, simde_mm512_loadu_epi64(test_vec[11].r));

  a = simde_mm512_loadu_epi64(test_vec[12].a);
  r = simde_mm512_maskz_ror_epi64(test_vec[12].k, a, INT32_C(          58));
  simde_test_x86_assert_equal_i64x8(r, simde_mm512_loadu_epi64(test_vec[12].r));

  a = simde_mm512_loadu_epi64(test_vec[13].a);
  r = simde_mm512_maskz_ror_epi64(test_vec[13].k, a, INT32_C(          56));
  simde_test_x86_assert_equal_i64x8(r, simde_mm512_loadu_epi64(test_vec[13].r));

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m512i a = simde_test_x86_random_i64x8();
    int imm8 = simde_test_codegen_random_i32() & 63;
    simde__m512i r;
    SIMDE_CONSTIFY_256_(simde_mm512_maskz_ror_epi64, r, simde_mm512_setzero_si512(), imm8, k, a);

    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i64x8(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, imm8, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i64x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_ror_epi32)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_mask_ror_epi32)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_maskz_ror_epi32)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_ror_epi32)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_mask_ror_epi32)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_maskz_ror_epi32)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_ror_epi32)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_mask_ror_epi32)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_maskz_ror_epi32)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_ror_epi64)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_mask_ror_epi64)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_maskz_ror_epi64)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_ror_epi64)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_mask_ror_epi64)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_maskz_ror_epi64)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_ror_epi64)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_mask_ror_epi64)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_maskz_ror_epi64)
SIMDE_TEST_FUNC_LIST_END

#include <test/x86/avx512/test-avx512-footer.h>
