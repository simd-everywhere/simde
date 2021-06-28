#define SIMDE_TEST_X86_AVX512_INSN conflict

#include <test/x86/avx512/test-avx512.h>
#include <simde/x86/avx512/conflict.h>

static int
test_simde_mm_conflict_epi32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int32_t a[4];
    const int32_t r[4];
  } test_vec[] = {
    { {  INT32_C(  1541612005),  INT32_C(           0), -INT32_C(   452408368), -INT32_C(  1876308071) },
      {  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0) } },
    { {  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0) },
      {  INT32_C(           0),  INT32_C(           1),  INT32_C(           3),  INT32_C(           7) } },
    { {  INT32_C(           0),  INT32_C(  2003804893), -INT32_C(  1362424684),  INT32_C(    42207387) },
      {  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0) } },
    { { -INT32_C(  1122030031),  INT32_C(           0),  INT32_C(   519959946),  INT32_C(   652835466) },
      {  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0) } },
    { {  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0) },
      {  INT32_C(           0),  INT32_C(           1),  INT32_C(           3),  INT32_C(           7) } },
    { {  INT32_C(   434925335),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0) },
      {  INT32_C(           0),  INT32_C(           0),  INT32_C(           2),  INT32_C(           6) } },
    { {  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(   191370707) },
      {  INT32_C(           0),  INT32_C(           1),  INT32_C(           3),  INT32_C(           0) } },
    { { -INT32_C(   910903619), -INT32_C(   789467214),  INT32_C(   552321512), -INT32_C(   150677719) },
      {  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i a = simde_x_mm_loadu_epi32(test_vec[i].a);
    simde__m128i r = simde_mm_conflict_epi32(a);
    simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    int a_[4] = {0, 0, 0, 0};
    for (int j = 0 ; j < 4 ; j++) {
      if (simde_test_codegen_random_i32() & 1) {
        a_[j] = simde_test_codegen_random_i32();
      }
    }
    simde__m128i a = simde_mm_set_epi32(a_[3], a_[2], a_[1], a_[0]);
    simde__m128i r = simde_mm_conflict_epi32(a);

    simde_test_x86_write_i32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_mask_conflict_epi32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int32_t src[4];
    const simde__mmask8 k;
    const int32_t a[4];
    const int32_t r[4];
  } test_vec[] = {
    { {  INT32_C(  1507529528), -INT32_C(    33431240), -INT32_C(  1024943785),  INT32_C(  1889556928) },
      UINT8_C(  1),
      {  INT32_C(  1913762415),  INT32_C(   887273249),  INT32_C(           0), -INT32_C(  1399419565) },
      {  INT32_C(           0), -INT32_C(    33431240), -INT32_C(  1024943785),  INT32_C(  1889556928) } },
    { { -INT32_C(  1683093715),  INT32_C(  1288955869), -INT32_C(   541137510),  INT32_C(     9020639) },
      UINT8_C( 91),
      {  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0) },
      {  INT32_C(           0),  INT32_C(           1), -INT32_C(   541137510),  INT32_C(           7) } },
    { { -INT32_C(  1573485894),  INT32_C(   993821270), -INT32_C(   451273920),  INT32_C(   289413797) },
      UINT8_C( 79),
      {  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0) },
      {  INT32_C(           0),  INT32_C(           1),  INT32_C(           3),  INT32_C(           7) } },
    { { -INT32_C(  1086929091),  INT32_C(   520122627), -INT32_C(  1497045621),  INT32_C(  1425397029) },
      UINT8_C(142),
      {  INT32_C(   390367136),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0) },
      { -INT32_C(  1086929091),  INT32_C(           0),  INT32_C(           2),  INT32_C(           6) } },
    { {  INT32_C(   478789175),  INT32_C(  1463889794),  INT32_C(   199595300),  INT32_C(   452006521) },
      UINT8_C(153),
      { -INT32_C(    71825498), -INT32_C(  1293056524),  INT32_C(           0),  INT32_C(           0) },
      {  INT32_C(           0),  INT32_C(  1463889794),  INT32_C(   199595300),  INT32_C(           4) } },
    { { -INT32_C(  2074514062), -INT32_C(  1826786466),  INT32_C(  1249372836),  INT32_C(  1883647985) },
      UINT8_C(132),
      {  INT32_C(   476064275),  INT32_C(  1818118143),  INT32_C(           0),  INT32_C(    64619476) },
      { -INT32_C(  2074514062), -INT32_C(  1826786466),  INT32_C(           0),  INT32_C(  1883647985) } },
    { {  INT32_C(   377965385), -INT32_C(  2056650895), -INT32_C(  1985885910),  INT32_C(  1718945895) },
      UINT8_C( 79),
      { -INT32_C(   105642852),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0) },
      {  INT32_C(           0),  INT32_C(           0),  INT32_C(           2),  INT32_C(           6) } },
    { {  INT32_C(  1367456136),  INT32_C(  1673005915),  INT32_C(  1421024896), -INT32_C(  1945525264) },
      UINT8_C(167),
      {  INT32_C(           0),  INT32_C(           0), -INT32_C(  2066558261),  INT32_C(           0) },
      {  INT32_C(           0),  INT32_C(           1),  INT32_C(           0), -INT32_C(  1945525264) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i src = simde_x_mm_loadu_epi32(test_vec[i].src);
    simde__m128i a = simde_x_mm_loadu_epi32(test_vec[i].a);
    simde__m128i r = simde_mm_mask_conflict_epi32(src, test_vec[i].k, a);
    simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m128i src = simde_test_x86_random_i32x4();
    simde__mmask8 k = simde_test_x86_random_mmask8();
    int a_[4] = {0, 0, 0, 0};
    for (int j = 0 ; j < 4 ; j++) {
      if (simde_test_codegen_random_i32() & 1) {
        a_[j] = simde_test_codegen_random_i32();
      }
    }
    simde__m128i a = simde_mm_set_epi32(a_[3], a_[2], a_[1], a_[0]);
    simde__m128i r = simde_mm_mask_conflict_epi32(src, k, a);

    simde_test_x86_write_i32x4(2, src, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x4(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_maskz_conflict_epi32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask8 k;
    const int32_t a[4];
    const int32_t r[4];
  } test_vec[] = {
    { UINT8_C(220),
      {  INT32_C(  1033497395),  INT32_C(           0), -INT32_C(  1057852630),  INT32_C(           0) },
      {  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           2) } },
    { UINT8_C( 15),
      {  INT32_C(           0), -INT32_C(   158980086),  INT32_C(   363162558), -INT32_C(  1709375651) },
      {  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0) } },
    { UINT8_C(139),
      { -INT32_C(   345666852),  INT32_C(    44559422),  INT32_C(           0),  INT32_C(   337030932) },
      {  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0) } },
    { UINT8_C(204),
      {  INT32_C(           0),  INT32_C(           0),  INT32_C(    66479895),  INT32_C(           0) },
      {  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           3) } },
    { UINT8_C(184),
      {  INT32_C(           0),  INT32_C(  1434722230),  INT32_C(           0),  INT32_C(  1011554773) },
      {  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0) } },
    { UINT8_C( 15),
      {  INT32_C(           0), -INT32_C(   255692466),  INT32_C(           0), -INT32_C(   536212084) },
      {  INT32_C(           0),  INT32_C(           0),  INT32_C(           1),  INT32_C(           0) } },
    { UINT8_C(111),
      {  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(  1702584828) },
      {  INT32_C(           0),  INT32_C(           1),  INT32_C(           3),  INT32_C(           0) } },
    { UINT8_C( 69),
      { -INT32_C(  1272918358),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0) },
      {  INT32_C(           0),  INT32_C(           0),  INT32_C(           2),  INT32_C(           0) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i a = simde_x_mm_loadu_epi32(test_vec[i].a);
    simde__m128i r = simde_mm_maskz_conflict_epi32(test_vec[i].k, a);
    simde_test_x86_assert_equal_i32x4(r, simde_x_mm_loadu_epi32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__mmask8 k = simde_test_x86_random_mmask8();
    int a_[4] = {0, 0, 0, 0};
    for (int j = 0 ; j < 4 ; j++) {
      if (simde_test_codegen_random_i32() & 1) {
        a_[j] = simde_test_codegen_random_i32();
      }
    }
    simde__m128i a = simde_mm_set_epi32(a_[3], a_[2], a_[1], a_[0]);
    simde__m128i r = simde_mm_maskz_conflict_epi32(k, a);

    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i32x4(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm256_conflict_epi32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int32_t a[8];
    const int32_t r[8];
  } test_vec[] = {
    { {  INT32_C(  1783908185),  INT32_C(           0), -INT32_C(   809233339),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(   496956901) },
      {  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           2),  INT32_C(          10),  INT32_C(          26),  INT32_C(          58),  INT32_C(           0) } },
    { {  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(  1276162016),  INT32_C(           0),  INT32_C(  1192614399),  INT32_C(   712258449),  INT32_C(           0) },
      {  INT32_C(           0),  INT32_C(           1),  INT32_C(           3),  INT32_C(           0),  INT32_C(           7),  INT32_C(           0),  INT32_C(           0),  INT32_C(          23) } },
    { {  INT32_C(           0),  INT32_C(           0), -INT32_C(   945300024),  INT32_C(           0),  INT32_C(  1349025047),  INT32_C(           0), -INT32_C(   132605285),  INT32_C(           0) },
      {  INT32_C(           0),  INT32_C(           1),  INT32_C(           0),  INT32_C(           3),  INT32_C(           0),  INT32_C(          11),  INT32_C(           0),  INT32_C(          43) } },
    { {  INT32_C(           0),  INT32_C(           0),  INT32_C(   744039596), -INT32_C(  1937083407),  INT32_C(  2108813601), -INT32_C(  1370310980),  INT32_C(  1404964914),  INT32_C(           0) },
      {  INT32_C(           0),  INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           3) } },
    { { -INT32_C(   892867415), -INT32_C(   440870872),  INT32_C(           0),  INT32_C(  1151255130), -INT32_C(   937720033), -INT32_C(  2076910757),  INT32_C(   280296695),  INT32_C(           0) },
      {  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           4) } },
    { {  INT32_C(   853017619),  INT32_C(           0),  INT32_C(           0),  INT32_C(  1750933105),  INT32_C(           0), -INT32_C(   514923058), -INT32_C(   260764134),  INT32_C(           0) },
      {  INT32_C(           0),  INT32_C(           0),  INT32_C(           2),  INT32_C(           0),  INT32_C(           6),  INT32_C(           0),  INT32_C(           0),  INT32_C(          22) } },
    { {  INT32_C(           0),  INT32_C(           0),  INT32_C(  1067282801),  INT32_C(           0), -INT32_C(   568448446),  INT32_C(           0),  INT32_C(   320739460),  INT32_C(  1466239488) },
      {  INT32_C(           0),  INT32_C(           1),  INT32_C(           0),  INT32_C(           3),  INT32_C(           0),  INT32_C(          11),  INT32_C(           0),  INT32_C(           0) } },
    { {  INT32_C(           0),  INT32_C(           0), -INT32_C(  1398686316),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(   405145249) },
      {  INT32_C(           0),  INT32_C(           1),  INT32_C(           0),  INT32_C(           3),  INT32_C(          11),  INT32_C(          27),  INT32_C(          59),  INT32_C(           0) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m256i a = simde_x_mm256_loadu_epi32(test_vec[i].a);
    simde__m256i r = simde_mm256_conflict_epi32(a);
    simde_test_x86_assert_equal_i32x8(r, simde_x_mm256_loadu_epi32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    int a_[8] = {0, 0, 0, 0, 0, 0, 0, 0};
    for (int j = 0 ; j < 8 ; j++) {
      if (simde_test_codegen_random_i32() & 1) {
        a_[j] = simde_test_codegen_random_i32();
      }
    }
    simde__m256i a = simde_mm256_set_epi32(a_[7], a_[6], a_[5], a_[4], a_[3], a_[2], a_[1], a_[0]);
    simde__m256i r = simde_mm256_conflict_epi32(a);

    simde_test_x86_write_i32x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i32x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm256_mask_conflict_epi32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int32_t src[8];
    const simde__mmask8 k;
    const int32_t a[8];
    const int32_t r[8];
  } test_vec[] = {
    { { -INT32_C(   276824230),  INT32_C(  2140872892),  INT32_C(  1707431094), -INT32_C(  1832378580), -INT32_C(  1225174298), -INT32_C(  1266829504), -INT32_C(  1361032180), -INT32_C(  1379531182) },
      UINT8_C(  6),
      {  INT32_C(           0),  INT32_C(   649560583),  INT32_C(           0), -INT32_C(  1945661120), -INT32_C(  1031959428),  INT32_C(           0),  INT32_C(   313500359),  INT32_C(           0) },
      { -INT32_C(   276824230),  INT32_C(           0),  INT32_C(           1), -INT32_C(  1832378580), -INT32_C(  1225174298), -INT32_C(  1266829504), -INT32_C(  1361032180), -INT32_C(  1379531182) } },
    { { -INT32_C(  1104508034), -INT32_C(  1924451812),  INT32_C(  1661283047), -INT32_C(   567967050),  INT32_C(  1144868546),  INT32_C(  1540106131), -INT32_C(  1251116087), -INT32_C(  1243276489) },
      UINT8_C(167),
      { -INT32_C(   383168065),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(  2002673755),  INT32_C(  1184293255),  INT32_C(           0),  INT32_C(           0) },
      {  INT32_C(           0),  INT32_C(           0),  INT32_C(           2), -INT32_C(   567967050),  INT32_C(  1144868546),  INT32_C(           0), -INT32_C(  1251116087),  INT32_C(          78) } },
    { {  INT32_C(   100596811), -INT32_C(  2031644197), -INT32_C(   609381760),  INT32_C(   944901106), -INT32_C(  1500680161), -INT32_C(  2064833710),  INT32_C(   789388515),  INT32_C(   908947179) },
      UINT8_C(106),
      { -INT32_C(  1254307037), -INT32_C(   610017430),  INT32_C(           0),  INT32_C(   742302398), -INT32_C(   726213711),  INT32_C(  1973694475),  INT32_C(           0),  INT32_C(           0) },
      {  INT32_C(   100596811),  INT32_C(           0), -INT32_C(   609381760),  INT32_C(           0), -INT32_C(  1500680161),  INT32_C(           0),  INT32_C(           4),  INT32_C(   908947179) } },
    { { -INT32_C(   316899537), -INT32_C(   266708191), -INT32_C(  2115325744),  INT32_C(   861249932), -INT32_C(  1621893484),  INT32_C(   504690446), -INT32_C(   778345153),  INT32_C(   295348194) },
      UINT8_C( 39),
      { -INT32_C(   907921127), -INT32_C(  1772582728),  INT32_C(  1897054988),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0) },
      {  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(   861249932), -INT32_C(  1621893484),  INT32_C(          24), -INT32_C(   778345153),  INT32_C(   295348194) } },
    { {  INT32_C(    14347812), -INT32_C(   221020186), -INT32_C(  1604065982),  INT32_C(  1218819785),  INT32_C(  2138952219), -INT32_C(   167983801),  INT32_C(  2076591086),  INT32_C(    62872799) },
      UINT8_C( 75),
      {  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(   402566868), -INT32_C(   753075911), -INT32_C(   158382224),  INT32_C(           0) },
      {  INT32_C(           0),  INT32_C(           1), -INT32_C(  1604065982),  INT32_C(           7),  INT32_C(  2138952219), -INT32_C(   167983801),  INT32_C(           0),  INT32_C(    62872799) } },
    { {  INT32_C(   760581090),  INT32_C(   909971042),  INT32_C(   843922621), -INT32_C(   301775947),  INT32_C(   985735229), -INT32_C(   569528979),  INT32_C(   919903732), -INT32_C(  1810298958) },
      UINT8_C(146),
      {  INT32_C(           0), -INT32_C(  1125028999),  INT32_C(  1325151137), -INT32_C(  1232045649),  INT32_C(           0),  INT32_C(           0), -INT32_C(  1851846110),  INT32_C(           0) },
      {  INT32_C(   760581090),  INT32_C(           0),  INT32_C(   843922621), -INT32_C(   301775947),  INT32_C(           1), -INT32_C(   569528979),  INT32_C(   919903732),  INT32_C(          49) } },
    { {  INT32_C(   232856780), -INT32_C(  1494539017),  INT32_C(   811367326), -INT32_C(  2043566689),  INT32_C(  1298968291), -INT32_C(  2043703964), -INT32_C(  1843933536),  INT32_C(   858077031) },
      UINT8_C( 84),
      {  INT32_C(           0), -INT32_C(   213518003),  INT32_C(           0),  INT32_C(   560317267),  INT32_C(   577157916), -INT32_C(   255060318),  INT32_C(           0),  INT32_C(   819613917) },
      {  INT32_C(   232856780), -INT32_C(  1494539017),  INT32_C(           1), -INT32_C(  2043566689),  INT32_C(           0), -INT32_C(  2043703964),  INT32_C(           5),  INT32_C(   858077031) } },
    { { -INT32_C(   296665325),  INT32_C(  1375853110), -INT32_C(  1854642283), -INT32_C(  1145585127), -INT32_C(   391412520),  INT32_C(  1931710102),  INT32_C(   629683784), -INT32_C(  1722457466) },
      UINT8_C(161),
      {  INT32_C(           0),  INT32_C(  1611245470),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(  1427615711),  INT32_C(    58172581) },
      {  INT32_C(           0),  INT32_C(  1375853110), -INT32_C(  1854642283), -INT32_C(  1145585127), -INT32_C(   391412520),  INT32_C(          29),  INT32_C(   629683784),  INT32_C(           0) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m256i src = simde_x_mm256_loadu_epi32(test_vec[i].src);
    simde__m256i a = simde_x_mm256_loadu_epi32(test_vec[i].a);
    simde__m256i r = simde_mm256_mask_conflict_epi32(src, test_vec[i].k, a);
    simde_test_x86_assert_equal_i32x8(r, simde_x_mm256_loadu_epi32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m256i src = simde_test_x86_random_i32x8();
    simde__mmask8 k = simde_test_x86_random_mmask8();
    int a_[8] = {0, 0, 0, 0, 0, 0, 0, 0};
    for (int j = 0 ; j < 8 ; j++) {
      if (simde_test_codegen_random_i32() & 1) {
        a_[j] = simde_test_codegen_random_i32();
      }
    }
    simde__m256i a = simde_mm256_set_epi32(a_[7], a_[6], a_[5], a_[4], a_[3], a_[2], a_[1], a_[0]);
    simde__m256i r = simde_mm256_mask_conflict_epi32(src, k, a);

    simde_test_x86_write_i32x8(2, src, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x8(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm256_maskz_conflict_epi32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask8 k;
    const int32_t a[8];
    const int32_t r[8];
  } test_vec[] = {
    { UINT8_C(105),
      {  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(  1581954062),  INT32_C(           0),  INT32_C(   396182375),  INT32_C(  1892875600),  INT32_C(           0) },
      {  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0) } },
    { UINT8_C( 39),
      { -INT32_C(  2103798643),  INT32_C(           0),  INT32_C(           0), -INT32_C(  1096062783),  INT32_C(           0),  INT32_C(           0),  INT32_C(   666434235), -INT32_C(   228899569) },
      {  INT32_C(           0),  INT32_C(           0),  INT32_C(           2),  INT32_C(           0),  INT32_C(           0),  INT32_C(          22),  INT32_C(           0),  INT32_C(           0) } },
    { UINT8_C( 31),
      {  INT32_C(   333291512), -INT32_C(  1023898214),  INT32_C(           0),  INT32_C(  1841346856),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(  1328202556) },
      {  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           4),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0) } },
    { UINT8_C(107),
      {  INT32_C(  1696596908), -INT32_C(  2022258406),  INT32_C(           0),  INT32_C(           0),  INT32_C(  1098130926),  INT32_C(           0),  INT32_C(    16992487),  INT32_C(  1650007016) },
      {  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           4),  INT32_C(           0),  INT32_C(          12),  INT32_C(           0),  INT32_C(           0) } },
    { UINT8_C(163),
      { -INT32_C(  1369015672),  INT32_C(           0), -INT32_C(   366867550), -INT32_C(   965621589),  INT32_C(  1895357159),  INT32_C(           0), -INT32_C(    31230372),  INT32_C(   320463720) },
      {  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           2),  INT32_C(           0),  INT32_C(           0) } },
    { UINT8_C(171),
      {  INT32_C(   491146563),  INT32_C(  1571533780), -INT32_C(    39667785), -INT32_C(   684885684),  INT32_C(           0),  INT32_C(           0), -INT32_C(  2107253545),  INT32_C(           0) },
      {  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(          16),  INT32_C(           0),  INT32_C(          48) } },
    { UINT8_C(213),
      {  INT32_C(    63305354),  INT32_C(  1348725715), -INT32_C(    73888993),  INT32_C(           0),  INT32_C(  1098602423), -INT32_C(  1349674276), -INT32_C(    18644001),  INT32_C(           0) },
      {  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           8) } },
    { UINT8_C(149),
      {  INT32_C(  1219515889),  INT32_C(           0),  INT32_C(           0),  INT32_C(   509769627), -INT32_C(  1066652581), -INT32_C(   478975725),  INT32_C(           0),  INT32_C(   388412796) },
      {  INT32_C(           0),  INT32_C(           0),  INT32_C(           2),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m256i a = simde_x_mm256_loadu_epi32(test_vec[i].a);
    simde__m256i r = simde_mm256_maskz_conflict_epi32(test_vec[i].k, a);
    simde_test_x86_assert_equal_i32x8(r, simde_x_mm256_loadu_epi32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__mmask8 k = simde_test_x86_random_mmask8();
    int a_[8] = {0, 0, 0, 0, 0, 0, 0, 0};
    for (int j = 0 ; j < 8 ; j++) {
      if (simde_test_codegen_random_i32() & 1) {
        a_[j] = simde_test_codegen_random_i32();
      }
    }
    simde__m256i a = simde_mm256_set_epi32(a_[7], a_[6], a_[5], a_[4], a_[3], a_[2], a_[1], a_[0]);
    simde__m256i r = simde_mm256_maskz_conflict_epi32(k, a);

    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i32x8(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm512_conflict_epi32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int32_t a[16];
    const int32_t r[16];
  } test_vec[] = {
    { {  INT32_C(           0), -INT32_C(   385495818),  INT32_C(           0), -INT32_C(  1108884329), -INT32_C(  1527088295),  INT32_C(  1653780076),  INT32_C(           0), -INT32_C(  1646264058),
        -INT32_C(  1520392885),  INT32_C(           0), -INT32_C(   612358048),  INT32_C(           0),  INT32_C(           0),  INT32_C(  2086171953), -INT32_C(  1002739181),  INT32_C(           0) },
      {  INT32_C(           0),  INT32_C(           0),  INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           5),  INT32_C(           0),
         INT32_C(           0),  INT32_C(          69),  INT32_C(           0),  INT32_C(         581),  INT32_C(        2629),  INT32_C(           0),  INT32_C(           0),  INT32_C(        6725) } },
    { {  INT32_C(           0),  INT32_C(  1378060176),  INT32_C(           0),  INT32_C(           0),  INT32_C(  1187071530),  INT32_C(           0),  INT32_C(  2094582507), -INT32_C(   295459014),
         INT32_C(           0),  INT32_C(   624000781),  INT32_C(           0),  INT32_C(           0),  INT32_C(  1734559277), -INT32_C(  1987702072), -INT32_C(   452155965),  INT32_C(           0) },
      {  INT32_C(           0),  INT32_C(           0),  INT32_C(           1),  INT32_C(           5),  INT32_C(           0),  INT32_C(          13),  INT32_C(           0),  INT32_C(           0),
         INT32_C(          45),  INT32_C(           0),  INT32_C(         301),  INT32_C(        1325),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(        3373) } },
    { { -INT32_C(  1002823785),  INT32_C(   722960483),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(  1046036697), -INT32_C(  1737709819),
         INT32_C(   399267657),  INT32_C(           0),  INT32_C(   662785614),  INT32_C(  1705899616),  INT32_C(           0),  INT32_C(   261936728),  INT32_C(           0), -INT32_C(  1893364992) },
      {  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           4),  INT32_C(          12),  INT32_C(          28),  INT32_C(           0),  INT32_C(           0),
         INT32_C(           0),  INT32_C(          60),  INT32_C(           0),  INT32_C(           0),  INT32_C(         572),  INT32_C(           0),  INT32_C(        4668),  INT32_C(           0) } },
    { {  INT32_C(           0), -INT32_C(    33412669),  INT32_C(           0), -INT32_C(   366019782),  INT32_C(   675024066), -INT32_C(  1556604192),  INT32_C(   720380999),  INT32_C(           0),
         INT32_C(           0), -INT32_C(   225700773), -INT32_C(   674282348), -INT32_C(   672057963),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(   902063009) },
      {  INT32_C(           0),  INT32_C(           0),  INT32_C(           1),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           5),
         INT32_C(         133),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(         389),  INT32_C(        4485),  INT32_C(       12677),  INT32_C(           0) } },
    { { -INT32_C(  1695788539), -INT32_C(  1602894326),  INT32_C(  1559261455),  INT32_C(           0),  INT32_C(  1383627597),  INT32_C(  1284791874),  INT32_C(           0),  INT32_C(           0),
         INT32_C(           0),  INT32_C(  1214674171), -INT32_C(  2062383293), -INT32_C(  1850753616),  INT32_C(           0),  INT32_C(   176129551),  INT32_C(           0),  INT32_C(           0) },
      {  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           8),  INT32_C(          72),
         INT32_C(         200),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(         456),  INT32_C(           0),  INT32_C(        4552),  INT32_C(       20936) } },
    { {  INT32_C(   275012959),  INT32_C(           0), -INT32_C(    27275025),  INT32_C(           0), -INT32_C(  1114512824), -INT32_C(  1794474885), -INT32_C(  1116307507),  INT32_C(  2062992565),
        -INT32_C(  1373268973),  INT32_C(           0),  INT32_C(   751497823), -INT32_C(   882465514), -INT32_C(  1578153586),  INT32_C(   180156753),  INT32_C(           0),  INT32_C(  1940070749) },
      {  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           2),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),
         INT32_C(           0),  INT32_C(          10),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(         522),  INT32_C(           0) } },
    { {  INT32_C(           0),  INT32_C(           0),  INT32_C(   221963707),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(   388915942),
         INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(   759083174), -INT32_C(  1981251259),  INT32_C(           0),  INT32_C(           0) },
      {  INT32_C(           0),  INT32_C(           1),  INT32_C(           0),  INT32_C(           3),  INT32_C(          11),  INT32_C(          27),  INT32_C(          59),  INT32_C(           0),
         INT32_C(         123),  INT32_C(         379),  INT32_C(         891),  INT32_C(        1915),  INT32_C(           0),  INT32_C(           0),  INT32_C(        3963),  INT32_C(       20347) } },
    { {  INT32_C(  2103339362),  INT32_C(           0),  INT32_C(           0), -INT32_C(  1681951565), -INT32_C(  1706807329),  INT32_C(           0),  INT32_C(  1090300825),  INT32_C(  1662802096),
         INT32_C(           0),  INT32_C(           0), -INT32_C(  1192721725), -INT32_C(  1398931273),  INT32_C(           0),  INT32_C(           0),  INT32_C(  1555184735), -INT32_C(  1729198637) },
      {  INT32_C(           0),  INT32_C(           0),  INT32_C(           2),  INT32_C(           0),  INT32_C(           0),  INT32_C(           6),  INT32_C(           0),  INT32_C(           0),
         INT32_C(          38),  INT32_C(         294),  INT32_C(           0),  INT32_C(           0),  INT32_C(         806),  INT32_C(        4902),  INT32_C(           0),  INT32_C(           0) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m512i a = simde_mm512_loadu_epi32(test_vec[i].a);
    simde__m512i r = simde_mm512_conflict_epi32(a);
    simde_test_x86_assert_equal_i32x16(r, simde_mm512_loadu_epi32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    int a_[16] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    for (int j = 0 ; j < 16 ; j++) {
      if (simde_test_codegen_random_i32() & 1) {
        a_[j] = simde_test_codegen_random_i32();
      }
    }
    simde__m512i a = simde_mm512_set_epi32(a_[15], a_[14], a_[13], a_[12], a_[11], a_[10], a_[9], a_[8], a_[7], a_[6], a_[5], a_[4], a_[3], a_[2], a_[1], a_[0]);
    simde__m512i r = simde_mm512_conflict_epi32(a);

    simde_test_x86_write_i32x16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i32x16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm512_mask_conflict_epi32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int32_t src[16];
    const simde__mmask16 k;
    const int32_t a[16];
    const int32_t r[16];
  } test_vec[] = {
    { {  INT32_C(  1224143505),  INT32_C(  1911854578), -INT32_C(  1029667073), -INT32_C(  1118817740),  INT32_C(   577477315),  INT32_C(  1233001942),  INT32_C(  1098849390),  INT32_C(   853110177),
         INT32_C(  1383780192),  INT32_C(  1690529380),  INT32_C(   673604596),  INT32_C(  1508275862), -INT32_C(   428060400), -INT32_C(   584058257), -INT32_C(  1205948906),  INT32_C(  2095773468) },
      UINT16_C(26054),
      {  INT32_C(           0), -INT32_C(   701789200),  INT32_C(  1381734178),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(  1608313466),
         INT32_C(           0), -INT32_C(  1214145651), -INT32_C(   189315719),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(   533221549),  INT32_C(           0) },
      {  INT32_C(  1224143505),  INT32_C(           0),  INT32_C(           0), -INT32_C(  1118817740),  INT32_C(   577477315),  INT32_C(  1233001942),  INT32_C(          57),  INT32_C(           0),
         INT32_C(         121),  INT32_C(  1690529380),  INT32_C(           0),  INT32_C(  1508275862), -INT32_C(   428060400),  INT32_C(        6521),  INT32_C(           0),  INT32_C(  2095773468) } },
    { {  INT32_C(  2068931586),  INT32_C(  1013909673),  INT32_C(  1474522552), -INT32_C(   814772183), -INT32_C(  1499732199),  INT32_C(  1909370654), -INT32_C(  1471019682), -INT32_C(   542446883),
        -INT32_C(   144966834), -INT32_C(  1137456636),  INT32_C(  1611863863), -INT32_C(  1053850713), -INT32_C(  2006463894), -INT32_C(   654690694),  INT32_C(   427904059), -INT32_C(  2064110794) },
      UINT16_C(21286),
      { -INT32_C(    87665177),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(  1763614496),
         INT32_C(           0),  INT32_C(           0), -INT32_C(  2032413082),  INT32_C(           0),  INT32_C(  1984280726),  INT32_C(           0),  INT32_C(           0),  INT32_C(   979476692) },
      {  INT32_C(  2068931586),  INT32_C(           0),  INT32_C(           2), -INT32_C(   814772183), -INT32_C(  1499732199),  INT32_C(          30), -INT32_C(  1471019682), -INT32_C(   542446883),
         INT32_C(         126),  INT32_C(         382),  INT32_C(  1611863863), -INT32_C(  1053850713),  INT32_C(           0), -INT32_C(   654690694),  INT32_C(       11134), -INT32_C(  2064110794) } },
    { {  INT32_C(   952122486),  INT32_C(   627728582),  INT32_C(    42240108),  INT32_C(  1484376384),  INT32_C(  1933542895), -INT32_C(  1052892659),  INT32_C(  1808449175), -INT32_C(   710595745),
         INT32_C(   772695655),  INT32_C(   844331206),  INT32_C(  1077204736), -INT32_C(  1885753952),  INT32_C(  1073993779), -INT32_C(  1862188550),  INT32_C(  1593691135),  INT32_C(  1580507894) },
      UINT16_C(16904),
      {  INT32_C(           0),  INT32_C(           0), -INT32_C(   362015257),  INT32_C(           0),  INT32_C(           0),  INT32_C(    67084407),  INT32_C(           0),  INT32_C(           0),
        -INT32_C(   222137956), -INT32_C(  1580962792),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0) },
      {  INT32_C(   952122486),  INT32_C(   627728582),  INT32_C(    42240108),  INT32_C(           3),  INT32_C(  1933542895), -INT32_C(  1052892659),  INT32_C(  1808449175), -INT32_C(   710595745),
         INT32_C(   772695655),  INT32_C(           0),  INT32_C(  1077204736), -INT32_C(  1885753952),  INT32_C(  1073993779), -INT32_C(  1862188550),  INT32_C(       15579),  INT32_C(  1580507894) } },
    { {  INT32_C(   269999096), -INT32_C(   827204536),  INT32_C(   885722936), -INT32_C(  2103522196),  INT32_C(   772634800), -INT32_C(   107083531),  INT32_C(  2023351816), -INT32_C(   390059024),
         INT32_C(  1341708295), -INT32_C(   333600332),  INT32_C(   606136504),  INT32_C(  1705492149),  INT32_C(   747942966), -INT32_C(   987417923),  INT32_C(   138264344), -INT32_C(   235798806) },
      UINT16_C(59862),
      {  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(  1952760243), -INT32_C(  1205772425),  INT32_C(  1895127808),  INT32_C(           0),
         INT32_C(           0),  INT32_C(  1471349520), -INT32_C(  2068205157), -INT32_C(  2133469142),  INT32_C(           0), -INT32_C(   978130251),  INT32_C(  1048095906),  INT32_C(   690530047) },
      {  INT32_C(   269999096),  INT32_C(           1),  INT32_C(           3), -INT32_C(  2103522196),  INT32_C(           0), -INT32_C(   107083531),  INT32_C(           0),  INT32_C(          15),
         INT32_C(         143), -INT32_C(   333600332),  INT32_C(   606136504),  INT32_C(           0),  INT32_C(   747942966),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0) } },
    { { -INT32_C(  1599406466),  INT32_C(   160948570),  INT32_C(  2039683524), -INT32_C(   264288765),  INT32_C(  1315396780),  INT32_C(  1720508168),  INT32_C(   271142672),  INT32_C(  1933136373),
        -INT32_C(  1441471665), -INT32_C(  1984713787), -INT32_C(   956086332),  INT32_C(   968311437), -INT32_C(  1501093986),  INT32_C(   252450046),  INT32_C(  1478440291), -INT32_C(   691316601) },
      UINT16_C(57148),
      {  INT32_C(           0),  INT32_C(           0), -INT32_C(   924029631),  INT32_C(           0),  INT32_C(  1668406679),  INT32_C(   946392494),  INT32_C(   754882027), -INT32_C(   835202604),
         INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(  1236559174), -INT32_C(  1963878279),  INT32_C(   883834159),  INT32_C(           0) },
      { -INT32_C(  1599406466),  INT32_C(   160948570),  INT32_C(           0),  INT32_C(           3),  INT32_C(           0),  INT32_C(           0),  INT32_C(   271142672),  INT32_C(  1933136373),
         INT32_C(          11),  INT32_C(         267),  INT32_C(         779),  INT32_C(        1803),  INT32_C(           0),  INT32_C(   252450046),  INT32_C(           0),  INT32_C(        3851) } },
    { {  INT32_C(  1474023866), -INT32_C(   908115326), -INT32_C(   166554713), -INT32_C(  1256623301),  INT32_C(   809437963),  INT32_C(   314601955),  INT32_C(   944139950),  INT32_C(   685583726),
        -INT32_C(  2122336002), -INT32_C(  1588961542),  INT32_C(   764894449), -INT32_C(   622677553), -INT32_C(  1626660420),  INT32_C(  1085393810), -INT32_C(  1468467142),  INT32_C(   600921637) },
      UINT16_C(20494),
      {  INT32_C(           0),  INT32_C(           0),  INT32_C(    13676533),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),
         INT32_C(   765225016),  INT32_C(  1902442959),  INT32_C(           0),  INT32_C(           0), -INT32_C(  1741131655),  INT32_C(           0),  INT32_C(  1553015181),  INT32_C(           0) },
      {  INT32_C(  1474023866),  INT32_C(           1),  INT32_C(           0),  INT32_C(           3),  INT32_C(   809437963),  INT32_C(   314601955),  INT32_C(   944139950),  INT32_C(   685583726),
        -INT32_C(  2122336002), -INT32_C(  1588961542),  INT32_C(   764894449), -INT32_C(   622677553),  INT32_C(           0),  INT32_C(  1085393810),  INT32_C(           0),  INT32_C(   600921637) } },
    { { -INT32_C(   893035950), -INT32_C(   712773288),  INT32_C(  1708794092),  INT32_C(   519967632), -INT32_C(   689667136),  INT32_C(   822270116),  INT32_C(   344888570), -INT32_C(   601006966),
         INT32_C(   245822390), -INT32_C(   790418972), -INT32_C(   650789303), -INT32_C(  1846070319),  INT32_C(  1516756150), -INT32_C(  1366529356), -INT32_C(  2000479490),  INT32_C(   744812662) },
      UINT16_C( 2787),
      { -INT32_C(   841187945), -INT32_C(  1507150017),  INT32_C(  1354174093),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(   421758472),
        -INT32_C(   666669502),  INT32_C(           0), -INT32_C(   954712559),  INT32_C(           0),  INT32_C(           0),  INT32_C(   554734303), -INT32_C(  2121020200),  INT32_C(           0) },
      {  INT32_C(           0),  INT32_C(           0),  INT32_C(  1708794092),  INT32_C(   519967632), -INT32_C(   689667136),  INT32_C(          24),  INT32_C(          56),  INT32_C(           0),
         INT32_C(   245822390),  INT32_C(         120), -INT32_C(   650789303),  INT32_C(         632),  INT32_C(  1516756150), -INT32_C(  1366529356), -INT32_C(  2000479490),  INT32_C(   744812662) } },
    { {  INT32_C(   729624156),  INT32_C(  1362580119),  INT32_C(   974372739),  INT32_C(  1247276907), -INT32_C(  2106890367), -INT32_C(  1826659141), -INT32_C(   720063951),  INT32_C(   764095184),
        -INT32_C(   262666152), -INT32_C(   582906022), -INT32_C(  1189653170), -INT32_C(   989630652), -INT32_C(  1857524010),  INT32_C(    69494739), -INT32_C(   354863078), -INT32_C(  1156094878) },
      UINT16_C(28524),
      { -INT32_C(  1153348189),  INT32_C(           0), -INT32_C(  1225110638),  INT32_C(   378360319),  INT32_C(           0),  INT32_C(           0), -INT32_C(  1226684053), -INT32_C(   174963802),
         INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(  1031542890) },
      {  INT32_C(   729624156),  INT32_C(  1362580119),  INT32_C(           0),  INT32_C(           0), -INT32_C(  2106890367),  INT32_C(          18),  INT32_C(           0),  INT32_C(   764095184),
         INT32_C(          50),  INT32_C(         306),  INT32_C(         818),  INT32_C(        1842), -INT32_C(  1857524010),  INT32_C(        7986),  INT32_C(       16178), -INT32_C(  1156094878) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m512i src = simde_mm512_loadu_epi32(test_vec[i].src);
    simde__m512i a = simde_mm512_loadu_epi32(test_vec[i].a);
    simde__m512i r = simde_mm512_mask_conflict_epi32(src, test_vec[i].k, a);
    simde_test_x86_assert_equal_i32x16(r, simde_mm512_loadu_epi32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m512i src = simde_test_x86_random_i32x16();
    simde__mmask16 k = simde_test_x86_random_mmask16();
    int a_[16] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    for (int j = 0 ; j < 16 ; j++) {
      if (simde_test_codegen_random_i32() & 1) {
        a_[j] = simde_test_codegen_random_i32();
      }
    }
    simde__m512i a = simde_mm512_set_epi32(a_[15], a_[14], a_[13], a_[12], a_[11], a_[10], a_[9], a_[8], a_[7], a_[6], a_[5], a_[4], a_[3], a_[2], a_[1], a_[0]);
    simde__m512i r = simde_mm512_mask_conflict_epi32(src, k, a);

    simde_test_x86_write_i32x16(2, src, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_mmask16(2, k, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x16(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm512_maskz_conflict_epi32 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask16 k;
    const int32_t a[16];
    const int32_t r[16];
  } test_vec[] = {
    { UINT16_C(60100),
      {  INT32_C(           0),  INT32_C(           0), -INT32_C(   641419368),  INT32_C(   527708198),  INT32_C(           0),  INT32_C(   921344613),  INT32_C(  2085574116),  INT32_C(           0),
         INT32_C(  1048198888),  INT32_C(           0),  INT32_C(  1464424807),  INT32_C(           0),  INT32_C(  2092688711), -INT32_C(   524004669),  INT32_C(           0),  INT32_C(   291573217) },
      {  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(          19),
         INT32_C(           0),  INT32_C(         147),  INT32_C(           0),  INT32_C(         659),  INT32_C(           0),  INT32_C(           0),  INT32_C(        2707),  INT32_C(           0) } },
    { UINT16_C(18215),
      {  INT32_C(           0),  INT32_C(   391395647),  INT32_C(   257519095),  INT32_C(           0), -INT32_C(  1347479415),  INT32_C(   764412654), -INT32_C(   209736196),  INT32_C(           0),
        -INT32_C(  1690039278),  INT32_C(           0), -INT32_C(   298178893),  INT32_C(           0),  INT32_C(           0), -INT32_C(  1443717993),  INT32_C(           0),  INT32_C(           0) },
      {  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),
         INT32_C(           0),  INT32_C(         137),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(        6793),  INT32_C(           0) } },
    { UINT16_C(13888),
      {  INT32_C(           0),  INT32_C(           0),  INT32_C(    56915331), -INT32_C(   390903644),  INT32_C(  2129377319),  INT32_C(           0),  INT32_C(           0), -INT32_C(  1914509822),
        -INT32_C(   546455862),  INT32_C(           0),  INT32_C(           0), -INT32_C(   879742609), -INT32_C(   649097992),  INT32_C(           0),  INT32_C(  1333218481),  INT32_C(           0) },
      {  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(          35),  INT32_C(           0),
         INT32_C(           0),  INT32_C(          99),  INT32_C(         611),  INT32_C(           0),  INT32_C(           0),  INT32_C(        1635),  INT32_C(           0),  INT32_C(           0) } },
    { UINT16_C(28937),
      { -INT32_C(   307469757), -INT32_C(   590575490),  INT32_C(   241457815), -INT32_C(   843788348),  INT32_C(           0),  INT32_C(   894432183), -INT32_C(  1762280705),  INT32_C(           0),
         INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(   231837966), -INT32_C(  1440921824), -INT32_C(   546499630),  INT32_C(           0) },
      {  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),
         INT32_C(         144),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0) } },
    { UINT16_C(18433),
      {  INT32_C(  1099253872),  INT32_C(  1295984688),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0), -INT32_C(   504134004),  INT32_C(           0),
        -INT32_C(   406897142), -INT32_C(  1487342067),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(   280357893),  INT32_C(           0),  INT32_C(           0) },
      {  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),
         INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(        1212),  INT32_C(           0),  INT32_C(           0),  INT32_C(        7356),  INT32_C(           0) } },
    { UINT16_C(37918),
      { -INT32_C(  2010080552),  INT32_C(           0),  INT32_C(  1040502408),  INT32_C(           0),  INT32_C(           0), -INT32_C(   836658187), -INT32_C(  1109622594),  INT32_C(           0),
         INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(  1661021486),  INT32_C(           0),  INT32_C(  1458687715),  INT32_C(           0),  INT32_C(   749435886) },
      {  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           2),  INT32_C(          10),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),
         INT32_C(           0),  INT32_C(           0),  INT32_C(         922),  INT32_C(           0),  INT32_C(        1946),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0) } },
    { UINT16_C(46863),
      {  INT32_C(    79127457), -INT32_C(  1620629842),  INT32_C(           0),  INT32_C(           0),  INT32_C(  1745541129), -INT32_C(   239435951),  INT32_C(           0),  INT32_C(           0),
         INT32_C(    51294812),  INT32_C(           0), -INT32_C(  1602500018),  INT32_C(           0),  INT32_C(   234385420),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0) },
      {  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           4),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),
         INT32_C(           0),  INT32_C(         204),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(        2764),  INT32_C(           0),  INT32_C(       27340) } },
    { UINT16_C(39298),
      {  INT32_C(    31108720),  INT32_C(           0),  INT32_C(    85587766),  INT32_C(   481138309),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),
         INT32_C(   720604266),  INT32_C(  1723163499),  INT32_C(           0), -INT32_C(  1541704204), -INT32_C(   509006217),  INT32_C(           0), -INT32_C(  1237181660),  INT32_C(           0) },
      {  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(         114),
         INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(           0),  INT32_C(        9458) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m512i a = simde_mm512_loadu_epi32(test_vec[i].a);
    simde__m512i r = simde_mm512_maskz_conflict_epi32(test_vec[i].k, a);
    simde_test_x86_assert_equal_i32x16(r, simde_mm512_loadu_epi32(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__mmask16 k = simde_test_x86_random_mmask16();
    int a_[16] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    for (int j = 0 ; j < 16 ; j++) {
      if (simde_test_codegen_random_i32() & 1) {
        a_[j] = simde_test_codegen_random_i32();
      }
    }
    simde__m512i a = simde_mm512_set_epi32(a_[15], a_[14], a_[13], a_[12], a_[11], a_[10], a_[9], a_[8], a_[7], a_[6], a_[5], a_[4], a_[3], a_[2], a_[1], a_[0]);
    simde__m512i r = simde_mm512_maskz_conflict_epi32(k, a);

    simde_test_x86_write_mmask16(2, k, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i32x16(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_conflict_epi64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int64_t a[2];
    const int64_t r[2];
  } test_vec[] = {
    { {  INT64_C(                   0),  INT64_C( 2341007921621013083) },
      {  INT64_C(                   0),  INT64_C(                   0) } },
    { {  INT64_C(                   0), -INT64_C( 7849144572637312277) },
      {  INT64_C(                   0),  INT64_C(                   0) } },
    { {  INT64_C(                   0),  INT64_C(                   0) },
      {  INT64_C(                   0),  INT64_C(                   1) } },
    { {  INT64_C(                   0),  INT64_C( 6921836318467056300) },
      {  INT64_C(                   0),  INT64_C(                   0) } },
    { { -INT64_C( 4117226113883408240),  INT64_C(                   0) },
      {  INT64_C(                   0),  INT64_C(                   0) } },
    { {  INT64_C(                   0),  INT64_C( 7340605217039335433) },
      {  INT64_C(                   0),  INT64_C(                   0) } },
    { {  INT64_C(                   0), -INT64_C( 4731194751189145722) },
      {  INT64_C(                   0),  INT64_C(                   0) } },
    { { -INT64_C( 1330508716959391998),  INT64_C(                   0) },
      {  INT64_C(                   0),  INT64_C(                   0) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i a = simde_x_mm_loadu_epi64(test_vec[i].a);
    simde__m128i r = simde_mm_conflict_epi64(a);
    simde_test_x86_assert_equal_i64x2(r, simde_x_mm_loadu_epi64(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    int64_t a_[2] = {0, 0};
    for (int j = 0 ; j < 2 ; j++) {
      if (simde_test_codegen_random_i32() & 1) {
        a_[j] = simde_test_codegen_random_i64();
      }
    }
    simde__m128i a = simde_mm_set_epi64x(a_[1], a_[0]);
    simde__m128i r = simde_mm_conflict_epi64(a);

    simde_test_x86_write_i64x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_mask_conflict_epi64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int64_t src[2];
    const simde__mmask8 k;
    const int64_t a[2];
    const int64_t r[2];
  } test_vec[] = {
    { { -INT64_C( 8515662571150301011), -INT64_C( 4962486945375715342) },
      UINT8_C( 16),
      {  INT64_C( 1109870840878472491), -INT64_C(  527463242536507534) },
      { -INT64_C( 8515662571150301011), -INT64_C( 4962486945375715342) } },
    { { -INT64_C( 3227921832210198160),  INT64_C(  766372126026581558) },
      UINT8_C(192),
      {  INT64_C(                   0), -INT64_C( 1534900806569546960) },
      { -INT64_C( 3227921832210198160),  INT64_C(  766372126026581558) } },
    { {  INT64_C( 5955428914655188817), -INT64_C( 5478699688184707197) },
      UINT8_C(216),
      {  INT64_C(                   0),  INT64_C(                   0) },
      {  INT64_C( 5955428914655188817), -INT64_C( 5478699688184707197) } },
    { { -INT64_C( 5052460565224280159), -INT64_C(  100179841163964118) },
      UINT8_C(204),
      { -INT64_C( 4816145625661807525),  INT64_C(                   0) },
      { -INT64_C( 5052460565224280159), -INT64_C(  100179841163964118) } },
    { {  INT64_C( 2507754926396731286),  INT64_C( 6267910633608046361) },
      UINT8_C(191),
      { -INT64_C( 4527883103506717439), -INT64_C( 5769678707608650881) },
      {  INT64_C(                   0),  INT64_C(                   0) } },
    { { -INT64_C( 6779174072867414763),  INT64_C( 8739668467760498090) },
      UINT8_C( 68),
      {  INT64_C(                   0),  INT64_C(                   0) },
      { -INT64_C( 6779174072867414763),  INT64_C( 8739668467760498090) } },
    { { -INT64_C( 5526192074978383810),  INT64_C( 7812459370516413240) },
      UINT8_C(250),
      {  INT64_C(                   0),  INT64_C(                   0) },
      { -INT64_C( 5526192074978383810),  INT64_C(                   1) } },
    { { -INT64_C( 6500266578739976154), -INT64_C( 3459628370185485121) },
      UINT8_C(187),
      {  INT64_C( 8163231344449496226),  INT64_C(                   0) },
      {  INT64_C(                   0),  INT64_C(                   0) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i src = simde_x_mm_loadu_epi64(test_vec[i].src);
    simde__m128i a = simde_x_mm_loadu_epi64(test_vec[i].a);
    simde__m128i r = simde_mm_mask_conflict_epi64(src, test_vec[i].k, a);
    simde_test_x86_assert_equal_i64x2(r, simde_x_mm_loadu_epi64(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m128i src = simde_test_x86_random_i64x2();
    simde__mmask8 k = simde_test_x86_random_mmask8();
    int64_t a_[2] = {0, 0};
    for (int j = 0 ; j < 2 ; j++) {
      if (simde_test_codegen_random_i32() & 1) {
        a_[j] = simde_test_codegen_random_i64();
      }
    }
    simde__m128i a = simde_mm_set_epi64x(a_[1], a_[0]);
    simde__m128i r = simde_mm_mask_conflict_epi64(src, k, a);

    simde_test_x86_write_i64x2(2, src, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i64x2(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_maskz_conflict_epi64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask8 k;
    const int64_t a[2];
    const int64_t r[2];
  } test_vec[] = {
    { UINT8_C(112),
      {  INT64_C(                   0),  INT64_C( 5410547278398441053) },
      {  INT64_C(                   0),  INT64_C(                   0) } },
    { UINT8_C( 74),
      {  INT64_C( 2307409299784996391),  INT64_C(                   0) },
      {  INT64_C(                   0),  INT64_C(                   0) } },
    { UINT8_C( 79),
      {  INT64_C(                   0), -INT64_C( 4903220643010936418) },
      {  INT64_C(                   0),  INT64_C(                   0) } },
    { UINT8_C(176),
      { -INT64_C( 5490365755102703789),  INT64_C(                   0) },
      {  INT64_C(                   0),  INT64_C(                   0) } },
    { UINT8_C(  6),
      { -INT64_C( 7813528065472402859),  INT64_C(                   0) },
      {  INT64_C(                   0),  INT64_C(                   0) } },
    { UINT8_C(  8),
      {  INT64_C( 6843807296398083599), -INT64_C( 7001616544980213684) },
      {  INT64_C(                   0),  INT64_C(                   0) } },
    { UINT8_C(210),
      {  INT64_C(                   0),  INT64_C(                   0) },
      {  INT64_C(                   0),  INT64_C(                   1) } },
    { UINT8_C(114),
      {  INT64_C(                   0),  INT64_C(                   0) },
      {  INT64_C(                   0),  INT64_C(                   1) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m128i a = simde_x_mm_loadu_epi64(test_vec[i].a);
    simde__m128i r = simde_mm_maskz_conflict_epi64(test_vec[i].k, a);
    simde_test_x86_assert_equal_i64x2(r, simde_x_mm_loadu_epi64(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__mmask8 k = simde_test_x86_random_mmask8();
    int64_t a_[2] = {0, 0};
    for (int j = 0 ; j < 2 ; j++) {
      if (simde_test_codegen_random_i32() & 1) {
        a_[j] = simde_test_codegen_random_i64();
      }
    }
    simde__m128i a = simde_mm_set_epi64x(a_[1], a_[0]);
    simde__m128i r = simde_mm_maskz_conflict_epi64(k, a);

    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i64x2(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm256_conflict_epi64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int64_t a[4];
    const int64_t r[4];
  } test_vec[] = {
    { { -INT64_C( 1881100853304466377), -INT64_C( 7637397671760699320),  INT64_C(                   0),  INT64_C(                   0) },
      {  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   4) } },
    { {  INT64_C( 7445937369894918579),  INT64_C( 7318164109459323056), -INT64_C( 6701647688477728635),  INT64_C(                   0) },
      {  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0) } },
    { { -INT64_C( 6133648499527305416),  INT64_C(                   0),  INT64_C(                   0),  INT64_C( 2319379599542456954) },
      {  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   2),  INT64_C(                   0) } },
    { {  INT64_C(                   0),  INT64_C( 6410557342866178066),  INT64_C(                   0),  INT64_C( 2522365040368847980) },
      {  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   1),  INT64_C(                   0) } },
    { { -INT64_C( 1429077057600128058),  INT64_C(                   0),  INT64_C(                   0), -INT64_C(  975255855980037456) },
      {  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   2),  INT64_C(                   0) } },
    { {  INT64_C(                   0),  INT64_C(                   0),  INT64_C( 7387510341675580086), -INT64_C( 2101400818327689747) },
      {  INT64_C(                   0),  INT64_C(                   1),  INT64_C(                   0),  INT64_C(                   0) } },
    { {  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0) },
      {  INT64_C(                   0),  INT64_C(                   1),  INT64_C(                   3),  INT64_C(                   7) } },
    { {  INT64_C(                   0),  INT64_C(                   0), -INT64_C( 3555344385964218994), -INT64_C( 3514380205183235110) },
      {  INT64_C(                   0),  INT64_C(                   1),  INT64_C(                   0),  INT64_C(                   0) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m256i a = simde_x_mm256_loadu_epi64(test_vec[i].a);
    simde__m256i r = simde_mm256_conflict_epi64(a);
    simde_test_x86_assert_equal_i64x4(r, simde_x_mm256_loadu_epi64(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    int64_t a_[4] = {0, 0, 0, 0};
    for (int j = 0 ; j < 4 ; j++) {
      if (simde_test_codegen_random_i32() & 1) {
        a_[j] = simde_test_codegen_random_i64();
      }
    }
    simde__m256i a = simde_mm256_set_epi64x(a_[3], a_[2], a_[1], a_[0]);
    simde__m256i r = simde_mm256_conflict_epi64(a);

    simde_test_x86_write_i64x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i64x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm256_mask_conflict_epi64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int64_t src[4];
    const simde__mmask8 k;
    const int64_t a[4];
    const int64_t r[4];
  } test_vec[] = {
    { {  INT64_C( 1323780799918772981),  INT64_C( 8214856355603607102),  INT64_C( 7701890457902557673), -INT64_C( 6572601578586159833) },
      UINT8_C(127),
      { -INT64_C( 3028253151251779146),  INT64_C(                   0), -INT64_C( 4593837287268212662),  INT64_C(                   0) },
      {  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   2) } },
    { {  INT64_C( 6599672924608683322), -INT64_C( 6495335276985938118),  INT64_C(  302125667517829463), -INT64_C( 8171496389679484730) },
      UINT8_C( 96),
      {  INT64_C( 7610617708369037845),  INT64_C(                   0),  INT64_C( 4708316864195099283),  INT64_C(                   0) },
      {  INT64_C( 6599672924608683322), -INT64_C( 6495335276985938118),  INT64_C(  302125667517829463), -INT64_C( 8171496389679484730) } },
    { {  INT64_C( 6205287228532887652),  INT64_C( 3525334441696148467),  INT64_C( 1907576655245632226),  INT64_C( 2006069643346432352) },
      UINT8_C(141),
      { -INT64_C(  113569112543871310), -INT64_C( 6859602565656455846),  INT64_C(                   0),  INT64_C(                   0) },
      {  INT64_C(                   0),  INT64_C( 3525334441696148467),  INT64_C(                   0),  INT64_C(                   4) } },
    { {  INT64_C( 6207509329690695942), -INT64_C( 8553685693084954107), -INT64_C( 1299073235832865911), -INT64_C( 4145068948417654826) },
      UINT8_C(219),
      {  INT64_C(                   0),  INT64_C(                   0), -INT64_C( 6438331194724913692),  INT64_C( 5998866959594896804) },
      {  INT64_C(                   0),  INT64_C(                   1), -INT64_C( 1299073235832865911),  INT64_C(                   0) } },
    { {  INT64_C( 6456635728015193024), -INT64_C( 3462980127000166868), -INT64_C( 3486081691712841864),  INT64_C( 1890233501898512688) },
      UINT8_C(104),
      { -INT64_C( 5907741220495704552), -INT64_C( 4581006726736705208), -INT64_C( 3713088475838270066),  INT64_C(                   0) },
      {  INT64_C( 6456635728015193024), -INT64_C( 3462980127000166868), -INT64_C( 3486081691712841864),  INT64_C(                   0) } },
    { {  INT64_C(  131081275729241695),  INT64_C( 3612636765434478778),  INT64_C( 2865954519879663100), -INT64_C( 9191328825253610144) },
      UINT8_C(189),
      {  INT64_C(                   0),  INT64_C(                   0),  INT64_C( 1485313942075625452),  INT64_C(                   0) },
      {  INT64_C(                   0),  INT64_C( 3612636765434478778),  INT64_C(                   0),  INT64_C(                   3) } },
    { {  INT64_C( 8452000280857872567), -INT64_C( 1219480187790245162), -INT64_C( 6239553114462146477),  INT64_C( 9160094903093233037) },
      UINT8_C( 57),
      {  INT64_C(                   0), -INT64_C( 4600914580500808375), -INT64_C( 2766338648851486003),  INT64_C(                   0) },
      {  INT64_C(                   0), -INT64_C( 1219480187790245162), -INT64_C( 6239553114462146477),  INT64_C(                   1) } },
    { {  INT64_C( 3935160828184479016), -INT64_C( 4157614973963865604),  INT64_C( 2248638130988944788),  INT64_C( 1234561247420665793) },
      UINT8_C(207),
      {  INT64_C( 3050101309598724654),  INT64_C( 2494593232016776985), -INT64_C( 2427403156277879394), -INT64_C( 8758385900293434872) },
      {  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m256i src = simde_x_mm256_loadu_epi64(test_vec[i].src);
    simde__m256i a = simde_x_mm256_loadu_epi64(test_vec[i].a);
    simde__m256i r = simde_mm256_mask_conflict_epi64(src, test_vec[i].k, a);
    simde_test_x86_assert_equal_i64x4(r, simde_x_mm256_loadu_epi64(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m256i src = simde_test_x86_random_i64x4();
    simde__mmask8 k = simde_test_x86_random_mmask8();
    int64_t a_[4] = {0, 0, 0, 0};
    for (int j = 0 ; j < 4 ; j++) {
      if (simde_test_codegen_random_i32() & 1) {
        a_[j] = simde_test_codegen_random_i64();
      }
    }
    simde__m256i a = simde_mm256_set_epi64x(a_[3], a_[2], a_[1], a_[0]);
    simde__m256i r = simde_mm256_mask_conflict_epi64(src, k, a);

    simde_test_x86_write_i64x4(2, src, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i64x4(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i64x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm256_maskz_conflict_epi64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask8 k;
    const int64_t a[4];
    const int64_t r[4];
  } test_vec[] = {
    { UINT8_C( 21),
      { -INT64_C( 5396830128527013119),  INT64_C(                   0),  INT64_C(                   0), -INT64_C( 2124142135249631366) },
      {  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   2),  INT64_C(                   0) } },
    { UINT8_C(234),
      {  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),  INT64_C( 1661340696011898706) },
      {  INT64_C(                   0),  INT64_C(                   1),  INT64_C(                   0),  INT64_C(                   0) } },
    { UINT8_C( 69),
      {  INT64_C(                   0),  INT64_C(                   0), -INT64_C( 3643166154680454786),  INT64_C( 4690916567895291023) },
      {  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0) } },
    { UINT8_C(141),
      {  INT64_C(                   0),  INT64_C(                   0), -INT64_C( 5330373170939074606),  INT64_C( 1821580927114680639) },
      {  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0) } },
    { UINT8_C(211),
      {  INT64_C(                   0), -INT64_C(  643806654591378478),  INT64_C(                   0),  INT64_C(                   0) },
      {  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0) } },
    { UINT8_C(162),
      {  INT64_C(                   0), -INT64_C( 4570496776341404913),  INT64_C( 2138790666990516956),  INT64_C(                   0) },
      {  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0) } },
    { UINT8_C( 44),
      {  INT64_C(                   0),  INT64_C(                   0), -INT64_C( 1874423327719233707),  INT64_C(                   0) },
      {  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   3) } },
    { UINT8_C( 77),
      { -INT64_C( 5636416646530183566),  INT64_C(                   0),  INT64_C(                   0), -INT64_C( 2553046125730306139) },
      {  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   2),  INT64_C(                   0) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m256i a = simde_x_mm256_loadu_epi64(test_vec[i].a);
    simde__m256i r = simde_mm256_maskz_conflict_epi64(test_vec[i].k, a);
    simde_test_x86_assert_equal_i64x4(r, simde_x_mm256_loadu_epi64(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__mmask8 k = simde_test_x86_random_mmask8();
    int64_t a_[4] = {0, 0, 0, 0};
    for (int j = 0 ; j < 4 ; j++) {
      if (simde_test_codegen_random_i32() & 1) {
        a_[j] = simde_test_codegen_random_i64();
      }
    }
    simde__m256i a = simde_mm256_set_epi64x(a_[3], a_[2], a_[1], a_[0]);
    simde__m256i r = simde_mm256_maskz_conflict_epi64(k, a);

    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i64x4(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i64x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm512_conflict_epi64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int64_t a[8];
    const int64_t r[8];
  } test_vec[] = {
    { {  INT64_C(                   0),  INT64_C(                   0), -INT64_C( 7497565022394391999),  INT64_C(                   0),
         INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0), -INT64_C(   87751293783390328) },
      {  INT64_C(                   0),  INT64_C(                   1),  INT64_C(                   0),  INT64_C(                   3),
         INT64_C(                  11),  INT64_C(                  27),  INT64_C(                  59),  INT64_C(                   0) } },
    { { -INT64_C( 4416400807271131144), -INT64_C( 8702202428582350973), -INT64_C( 3665767551595570706),  INT64_C( 3120217908119792326),
         INT64_C(                   0), -INT64_C( 5560253540170742674),  INT64_C( 5088244726441293043),  INT64_C( 2428458019163075589) },
      {  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),
         INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0) } },
    { {  INT64_C( 4580001719591654841), -INT64_C( 8864640426514606741),  INT64_C( 6368020187815471296), -INT64_C(  458354997623507266),
         INT64_C(                   0), -INT64_C( 1173766803760846893), -INT64_C( 5619147477028966812),  INT64_C(                   0) },
      {  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),
         INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                  16) } },
    { {  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),
         INT64_C(                   0), -INT64_C( 3892292639627620339),  INT64_C(                   0),  INT64_C(                   0) },
      {  INT64_C(                   0),  INT64_C(                   1),  INT64_C(                   3),  INT64_C(                   7),
         INT64_C(                  15),  INT64_C(                   0),  INT64_C(                  31),  INT64_C(                  95) } },
    { {  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0), -INT64_C( 2623396613995437738),
        -INT64_C( 5931025346414100455),  INT64_C( 6233423888371514045), -INT64_C( 6205935477913306582), -INT64_C( 3477725513476969526) },
      {  INT64_C(                   0),  INT64_C(                   1),  INT64_C(                   3),  INT64_C(                   0),
         INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0) } },
    { { -INT64_C( 1462377121330271968), -INT64_C( 3435326198185787450),  INT64_C(                   0), -INT64_C( 6553993222642304424),
         INT64_C(                   0), -INT64_C( 3205255462013182290), -INT64_C( 8850199294872901795),  INT64_C(                   0) },
      {  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),
         INT64_C(                   4),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                  20) } },
    { {  INT64_C(                   0),  INT64_C( 8145411473574456852), -INT64_C( 1086172763263673913),  INT64_C(                   0),
         INT64_C(                   0),  INT64_C( 5858284190830960199),  INT64_C(  639382143174019151),  INT64_C(                   0) },
      {  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   1),
         INT64_C(                   9),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                  25) } },
    { {  INT64_C(                   0),  INT64_C(                   0), -INT64_C( 6432139347996057062),  INT64_C( 3961491692207371492),
         INT64_C( 2404050321804475052), -INT64_C( 6678173319146543440),  INT64_C( 8775525339489837836),  INT64_C(                   0) },
      {  INT64_C(                   0),  INT64_C(                   1),  INT64_C(                   0),  INT64_C(                   0),
         INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   3) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m512i a = simde_mm512_loadu_epi64(test_vec[i].a);
    simde__m512i r = simde_mm512_conflict_epi64(a);
    simde_test_x86_assert_equal_i64x8(r, simde_mm512_loadu_epi64(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    int64_t a_[8] = {0, 0, 0, 0, 0, 0, 0, 0};
    for (int j = 0 ; j < 8 ; j++) {
      if (simde_test_codegen_random_i32() & 1) {
        a_[j] = simde_test_codegen_random_i64();
      }
    }
    simde__m512i a = simde_mm512_set_epi64(a_[7], a_[6], a_[5], a_[4], a_[3], a_[2], a_[1], a_[0]);
    simde__m512i r = simde_mm512_conflict_epi64(a);

    simde_test_x86_write_i64x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i64x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm512_mask_conflict_epi64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const int64_t src[8];
    const simde__mmask8 k;
    const int64_t a[8];
    const int64_t r[8];
  } test_vec[] = {
    { { -INT64_C( 8004450281803701759), -INT64_C( 2358885586359766560),  INT64_C( 6758530371725585550), -INT64_C( 5808486082700471283),
        -INT64_C( 8201226794784181058), -INT64_C( 8718280613784818923), -INT64_C( 7869216241559116067),  INT64_C( 8925760336230326401) },
      UINT8_C(224),
      { -INT64_C( 4851235192120009400),  INT64_C( 8270143633359898454),  INT64_C(                   0),  INT64_C( 4377417409718768835),
         INT64_C(                   0),  INT64_C(  494549663257057689),  INT64_C(                   0),  INT64_C(                   0) },
      { -INT64_C( 8004450281803701759), -INT64_C( 2358885586359766560),  INT64_C( 6758530371725585550), -INT64_C( 5808486082700471283),
        -INT64_C( 8201226794784181058),  INT64_C(                   0),  INT64_C(                  20),  INT64_C(                  84) } },
    { {  INT64_C( 3725957433508746631), -INT64_C( 2863505139328504403),  INT64_C( 7851216133939231650), -INT64_C( 7253573776305987286),
        -INT64_C( 3912000680829396489), -INT64_C(  968739766179297674),  INT64_C( 1997864237302665684),  INT64_C(  281000040501799735) },
      UINT8_C( 42),
      {  INT64_C(                   0),  INT64_C( 5571239146754797092), -INT64_C( 6679051199318960040),  INT64_C(                   0),
         INT64_C(                   0), -INT64_C( 3472253414748789241),  INT64_C(                   0),  INT64_C(                   0) },
      {  INT64_C( 3725957433508746631),  INT64_C(                   0),  INT64_C( 7851216133939231650),  INT64_C(                   1),
        -INT64_C( 3912000680829396489),  INT64_C(                   0),  INT64_C( 1997864237302665684),  INT64_C(  281000040501799735) } },
    { { -INT64_C( 3963684511818146629),  INT64_C(   45793526983417659),  INT64_C( 3049311299252216983),  INT64_C( 1405546777032317794),
         INT64_C( 4816020384848796957), -INT64_C(  520094968239443760),  INT64_C(  164322700460379301),  INT64_C( 1806591050019142566) },
      UINT8_C( 41),
      {  INT64_C( 5840480494038708987), -INT64_C( 3031127770118548610),  INT64_C(  935258957327756031),  INT64_C( 5280891446911092047),
         INT64_C( 7943383748177854929),  INT64_C(                   0),  INT64_C(                   0),  INT64_C( 7866499766268615959) },
      {  INT64_C(                   0),  INT64_C(   45793526983417659),  INT64_C( 3049311299252216983),  INT64_C(                   0),
         INT64_C( 4816020384848796957),  INT64_C(                   0),  INT64_C(  164322700460379301),  INT64_C( 1806591050019142566) } },
    { { -INT64_C( 6005240870681920009),  INT64_C( 2068152398636574122), -INT64_C( 5285944347920347654),  INT64_C( 2968931202214971114),
         INT64_C( 5722838883384855424),  INT64_C(  883313634849424768),  INT64_C( 8344000813616921462), -INT64_C( 6270580612907047778) },
      UINT8_C(247),
      {  INT64_C(                   0),  INT64_C( 7710011308500397408),  INT64_C(                   0),  INT64_C(                   0),
         INT64_C(                   0), -INT64_C( 1611614076295799174),  INT64_C(                   0),  INT64_C(                   0) },
      {  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   1),  INT64_C( 2968931202214971114),
         INT64_C(                  13),  INT64_C(                   0),  INT64_C(                  29),  INT64_C(                  93) } },
    { {  INT64_C( 7037946181349956999), -INT64_C( 6592867249966803265), -INT64_C( 2990792279256473844), -INT64_C( 1491744378751290978),
        -INT64_C( 8591463152014394720), -INT64_C( 6133422625777373165),  INT64_C(  121243576024682899),  INT64_C( 7565605130110863023) },
      UINT8_C(103),
      {  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),
         INT64_C( 4829770671925409208),  INT64_C(                   0),  INT64_C(                   0),  INT64_C( 4339019177392728678) },
      {  INT64_C(                   0),  INT64_C(                   1),  INT64_C(                   3), -INT64_C( 1491744378751290978),
        -INT64_C( 8591463152014394720),  INT64_C(                  15),  INT64_C(                  47),  INT64_C( 7565605130110863023) } },
    { {  INT64_C( 8523900810059574100), -INT64_C(  385792518719450940),  INT64_C( 4127636829593930812),  INT64_C(   29650170046013753),
         INT64_C( 7734746164067347777), -INT64_C( 5737412806295744346), -INT64_C( 5929333655779597143),  INT64_C( 7913743929543677223) },
      UINT8_C(241),
      { -INT64_C( 7554151780366679130),  INT64_C(                   0),  INT64_C(                   0), -INT64_C( 3677221067376289342),
        -INT64_C( 4529291780057801326),  INT64_C( 7916571314050679330),  INT64_C(                   0),  INT64_C(                   0) },
      {  INT64_C(                   0), -INT64_C(  385792518719450940),  INT64_C( 4127636829593930812),  INT64_C(   29650170046013753),
         INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   6),  INT64_C(                  70) } },
    { {  INT64_C( 2241328063016870650), -INT64_C( 4250438573618086268), -INT64_C( 4376873920778073045),  INT64_C( 1955468380783294090),
        -INT64_C( 5874450751762702502), -INT64_C( 1339036101364000511), -INT64_C( 8722339997585062699), -INT64_C( 6919948752685626181) },
      UINT8_C(199),
      {  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),
         INT64_C( 7312678105833650474),  INT64_C( 2617497099894464020), -INT64_C( 5198250674417608868),  INT64_C(                   0) },
      {  INT64_C(                   0),  INT64_C(                   1),  INT64_C(                   3),  INT64_C( 1955468380783294090),
        -INT64_C( 5874450751762702502), -INT64_C( 1339036101364000511),  INT64_C(                   0),  INT64_C(                  15) } },
    { { -INT64_C( 7424917890333709901),  INT64_C( 4495844768640649346), -INT64_C( 7257032866449606829), -INT64_C( 5649975744536631823),
        -INT64_C( 5348822583142395991), -INT64_C( 6111004985091824141), -INT64_C( 1604790035442687984), -INT64_C(  758779241630397240) },
      UINT8_C( 21),
      {  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),  INT64_C( 4654171370207803690),
         INT64_C(                   0),  INT64_C( 3483858936344101284), -INT64_C( 8987518750506559923),  INT64_C( 8543706527777574968) },
      {  INT64_C(                   0),  INT64_C( 4495844768640649346),  INT64_C(                   3), -INT64_C( 5649975744536631823),
         INT64_C(                   7), -INT64_C( 6111004985091824141), -INT64_C( 1604790035442687984), -INT64_C(  758779241630397240) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m512i src = simde_mm512_loadu_epi64(test_vec[i].src);
    simde__m512i a = simde_mm512_loadu_epi64(test_vec[i].a);
    simde__m512i r = simde_mm512_mask_conflict_epi64(src, test_vec[i].k, a);
    simde_test_x86_assert_equal_i64x8(r, simde_mm512_loadu_epi64(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m512i src = simde_test_x86_random_i64x8();
    simde__mmask8 k = simde_test_x86_random_mmask8();
    int64_t a_[8] = {0, 0, 0, 0, 0, 0, 0, 0};
    for (int j = 0 ; j < 8 ; j++) {
      if (simde_test_codegen_random_i32() & 1) {
        a_[j] = simde_test_codegen_random_i64();
      }
    }
    simde__m512i a = simde_mm512_set_epi64(a_[7], a_[6], a_[5], a_[4], a_[3], a_[2], a_[1], a_[0]);
    simde__m512i r = simde_mm512_mask_conflict_epi64(src, k, a);

    simde_test_x86_write_i64x8(2, src, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i64x8(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i64x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm512_maskz_conflict_epi64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask8 k;
    const int64_t a[8];
    const int64_t r[8];
  } test_vec[] = {
    { UINT8_C(153),
      {  INT64_C( 6496669528191797340),  INT64_C(                   0),  INT64_C(                   0), -INT64_C( 8989033576090368688),
         INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),  INT64_C( 7640117189293320405) },
      {  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),
         INT64_C(                   6),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0) } },
    { UINT8_C( 43),
      {  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),
         INT64_C( 1788895461460460176),  INT64_C( 2669616747517183311), -INT64_C( 3403750170618208059), -INT64_C( 1594975098064904999) },
      {  INT64_C(                   0),  INT64_C(                   1),  INT64_C(                   0),  INT64_C(                   7),
         INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0) } },
    { UINT8_C(135),
      {  INT64_C(                   0), -INT64_C( 2798173087777732983), -INT64_C(  614394500983540348),  INT64_C(                   0),
         INT64_C( 3871309865686370630), -INT64_C( 4160426301326025505), -INT64_C( 3345812186597540833),  INT64_C(                   0) },
      {  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),
         INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   9) } },
    { UINT8_C(236),
      {  INT64_C(                   0),  INT64_C(                   0),  INT64_C( 1341813025980422595),  INT64_C( 7741262319364894525),
         INT64_C(  837258620385675150),  INT64_C( 1300461486745594432),  INT64_C(                   0),  INT64_C(                   0) },
      {  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),
         INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   3),  INT64_C(                  67) } },
    { UINT8_C(231),
      { -INT64_C( 4731074758935973079), -INT64_C(  854992282558726051),  INT64_C(                   0),  INT64_C(                   0),
         INT64_C( 3507803616912208989), -INT64_C( 6868814517624692308),  INT64_C( 7516093309985530139),  INT64_C(                   0) },
      {  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),
         INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                  12) } },
    { UINT8_C(104),
      {  INT64_C(                   0), -INT64_C( 3695608368578226232),  INT64_C(                   0),  INT64_C(                   0),
         INT64_C(                   0),  INT64_C(  156711445954912668),  INT64_C(                   0), -INT64_C( 5891643615301251065) },
      {  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   5),
         INT64_C(                   0),  INT64_C(                   0),  INT64_C(                  29),  INT64_C(                   0) } },
    { UINT8_C(254),
      {  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),
         INT64_C(                   0),  INT64_C( 7346967826571006793), -INT64_C(  926816706527333389),  INT64_C(                   0) },
      {  INT64_C(                   0),  INT64_C(                   1),  INT64_C(                   3),  INT64_C(                   7),
         INT64_C(                  15),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                  31) } },
    { UINT8_C( 97),
      {  INT64_C(  390199467221867528), -INT64_C( 4684178512770634899),  INT64_C( 5357914949512097493),  INT64_C( 1008178083743584494),
         INT64_C(                   0),  INT64_C(                   0), -INT64_C( 1394034039261148645),  INT64_C(                   0) },
      {  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),  INT64_C(                   0),
         INT64_C(                   0),  INT64_C(                  16),  INT64_C(                   0),  INT64_C(                   0) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m512i a = simde_mm512_loadu_epi64(test_vec[i].a);
    simde__m512i r = simde_mm512_maskz_conflict_epi64(test_vec[i].k, a);
    simde_test_x86_assert_equal_i64x8(r, simde_mm512_loadu_epi64(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__mmask8 k = simde_test_x86_random_mmask8();
    int64_t a_[8] = {0, 0, 0, 0, 0, 0, 0, 0};
    for (int j = 0 ; j < 8 ; j++) {
      if (simde_test_codegen_random_i32() & 1) {
        a_[j] = simde_test_codegen_random_i64();
      }
    }
    simde__m512i a = simde_mm512_set_epi64(a_[7], a_[6], a_[5], a_[4], a_[3], a_[2], a_[1], a_[0]);
    simde__m512i r = simde_mm512_maskz_conflict_epi64(k, a);

    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_i64x8(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i64x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_conflict_epi32)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_mask_conflict_epi32)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_maskz_conflict_epi32)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_conflict_epi32)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_mask_conflict_epi32)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_maskz_conflict_epi32)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_conflict_epi32)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_mask_conflict_epi32)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_maskz_conflict_epi32)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_conflict_epi64)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_mask_conflict_epi64)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_maskz_conflict_epi64)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_conflict_epi64)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_mask_conflict_epi64)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_maskz_conflict_epi64)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_conflict_epi64)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_mask_conflict_epi64)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_maskz_conflict_epi64)
SIMDE_TEST_FUNC_LIST_END

#include <test/x86/avx512/test-avx512-footer.h>
