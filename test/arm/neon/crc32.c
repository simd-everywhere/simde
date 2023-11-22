#define SIMDE_TEST_ARM_NEON_INSN crc32

#include "test-neon.h"
#include "../../../simde/arm/neon/crc32.h"

static int
test_simde___crc32b(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint32_t a;
    uint8_t b;
    uint32_t r;
  } test_vec[] = {
    {    UINT32_C(  3153495819),
         UINT8_C(   180),
         UINT32_C(  1533368474) },
    {    UINT32_C(  3359452836),
         UINT8_C(    30),
         UINT32_C(   729573308) },
    {    UINT32_C(  4014489982),
         UINT8_C(   254),
         UINT32_C(  3981953889) },
    {    UINT32_C(   492506225),
         UINT8_C(    73),
         UINT32_C(   673178514) },
    {    UINT32_C(  4043408415),
         UINT8_C(   205),
         UINT32_C(  1747759740) },
    {    UINT32_C(  3873975223),
         UINT8_C(    63),
         UINT32_C(  3817202489) },
    {    UINT32_C(  3363644870),
         UINT8_C(    37),
         UINT32_C(   969658087) },
    {    UINT32_C(  2123914224),
         UINT8_C(   221),
         UINT32_C(  1168229422) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    uint32_t a = test_vec[i].a;
    uint8_t b = test_vec[i].b;
    uint32_t r = simde___crc32b(a, b);

    simde_assert_equal_u32(r, test_vec[i].r);
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint32_t a = simde_test_codegen_random_u32();
    simde_uint8_t b = simde_test_codegen_random_u8();
    simde_uint32_t r = simde___crc32b(a, b);

    simde_test_codegen_write_u32(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_u8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_u32(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde___crc32h(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint32_t a;
    uint16_t b;
    uint32_t r;
  } test_vec[] = {
    {    UINT32_C(   264970151),
         UINT16_C(    3768),
         UINT32_C(  2817139111) },
    {    UINT32_C(   892162006),
         UINT16_C(   21362),
         UINT32_C(  3731493007) },
    {    UINT32_C(  3641722167),
         UINT16_C(    5123),
         UINT32_C(  2806401925) },
    {    UINT32_C(  3964107322),
         UINT16_C(   64414),
         UINT32_C(  1356080668) },
    {    UINT32_C(  3309730558),
         UINT16_C(   27840),
         UINT32_C(  3037817706) },
    {    UINT32_C(   787120121),
         UINT16_C(   19126),
         UINT32_C(   559069443) },
    {    UINT32_C(   410652792),
         UINT16_C(   59000),
         UINT32_C(  1423855443) },
    {    UINT32_C(  1363715216),
         UINT16_C(   54410),
         UINT32_C(  3760773807) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    uint32_t a = test_vec[i].a;
    uint16_t b = test_vec[i].b;
    uint32_t r = simde___crc32h(a, b);

    simde_assert_equal_u32(r, test_vec[i].r);
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint32_t a = simde_test_codegen_random_u32();
    simde_uint16_t b = simde_test_codegen_random_u16();
    simde_uint32_t r = simde___crc32h(a, b);

    simde_test_codegen_write_u32(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_u16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_u32(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde___crc32w(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint32_t a;
    uint32_t b;
    uint32_t r;
  } test_vec[] = {
    {    UINT32_C(  1896308035),
         UINT32_C(  3030051700),
         UINT32_C(  2211348690) },
    {    UINT32_C(  2243158054),
         UINT32_C(  1114986530),
         UINT32_C(  3700367140) },
    {    UINT32_C(  1833109319),
         UINT32_C(  2554286432),
         UINT32_C(   462026220) },
    {    UINT32_C(  2852802285),
         UINT32_C(  1925391820),
         UINT32_C(  3460094587) },
    {    UINT32_C(  2928668571),
         UINT32_C(  3371259104),
         UINT32_C(  1616422521) },
    {    UINT32_C(   861406319),
         UINT32_C(   159143459),
         UINT32_C(  2300454223) },
    {    UINT32_C(   776769607),
         UINT32_C(  3271408350),
         UINT32_C(  2716884146) },
    {    UINT32_C(  2760839911),
         UINT32_C(  3169252468),
         UINT32_C(  2781457120) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    uint32_t a = test_vec[i].a;
    uint32_t b = test_vec[i].b;
    uint32_t r = simde___crc32w(a, b);

    simde_assert_equal_u32(r, test_vec[i].r);
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint32_t a = simde_test_codegen_random_u32();
    simde_uint32_t b = simde_test_codegen_random_u32();
    simde_uint32_t r = simde___crc32w(a, b);

    simde_test_codegen_write_u32(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_u32(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_u32(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde___crc32d(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint32_t a;
    uint64_t b;
    uint32_t r;
  } test_vec[] = {
    {    UINT32_C(  3255761882),
         UINT64_C(10657997303375335424),
         UINT32_C(  2591534569) },
    {    UINT32_C(  2628805908),
         UINT64_C(18311154191066296320),
         UINT32_C(  4004152018) },
    {    UINT32_C(  1017504540),
         UINT64_C(13466350054111825920),
         UINT32_C(  2702169441) },
    {    UINT32_C(  2928837669),
         UINT64_C( 1341134430787507712),
         UINT32_C(  1960841616) },
    {    UINT32_C(  3384216630),
         UINT64_C( 9691660399174090752),
         UINT32_C(    67935203) },
    {    UINT32_C(  3437103122),
         UINT64_C(18000456012487385088),
         UINT32_C(  1253033588) },
    {    UINT32_C(  1035989368),
         UINT64_C(17730710245866688512),
         UINT32_C(   691054827) },
    {    UINT32_C(  1622305324),
         UINT64_C( 6392644927518521344),
         UINT32_C(   641777179) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    uint32_t a = test_vec[i].a;
    uint64_t b = test_vec[i].b;
    uint32_t r = simde___crc32d(a, b);

    simde_assert_equal_u32(r, test_vec[i].r);
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint32_t a = simde_test_codegen_random_u32();
    simde_uint64_t b = simde_test_codegen_random_u64();
    simde_uint32_t r = simde___crc32d(a, b);

    simde_test_codegen_write_u32(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_u64(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_u32(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde___crc32cb(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint32_t a;
    uint8_t b;
    uint32_t r;
  } test_vec[] = {
    {    UINT32_C(  4187017617),
         UINT8_C(   213),
         UINT32_C(  2249726578) },
    {    UINT32_C(  2822416313),
         UINT8_C(    19),
         UINT32_C(  3372328761) },
    {    UINT32_C(  1743715926),
         UINT8_C(   213),
         UINT32_C(  2445354610) },
    {    UINT32_C(   952671078),
         UINT8_C(    69),
         UINT32_C(   869643697) },
    {    UINT32_C(  2606794088),
         UINT8_C(   128),
         UINT32_C(  1769115728) },
    {    UINT32_C(   806232336),
         UINT8_C(   122),
         UINT32_C(   169129339) },
    {    UINT32_C(  4277672495),
         UINT8_C(   252),
         UINT32_C(  3229477445) },
    {    UINT32_C(  4144236202),
         UINT8_C(    85),
         UINT32_C(  2911524695) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    uint32_t a = test_vec[i].a;
    uint8_t b = test_vec[i].b;
    uint32_t r = simde___crc32cb(a, b);

    simde_assert_equal_u32(r, test_vec[i].r);
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint32_t a = simde_test_codegen_random_u32();
    simde_uint8_t b = simde_test_codegen_random_u8();
    simde_uint32_t r = simde___crc32cb(a, b);

    simde_test_codegen_write_u32(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_u8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_u32(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde___crc32ch(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint32_t a;
    uint16_t b;
    uint32_t r;
  } test_vec[] = {
    {    UINT32_C(   236626040),
         UINT16_C(     311),
         UINT32_C(  1213133894) },
    {    UINT32_C(  1488276255),
         UINT16_C(   24289),
         UINT32_C(  2515416882) },
    {    UINT32_C(  3981318354),
         UINT16_C(   16375),
         UINT32_C(  3604225490) },
    {    UINT32_C(  2317314224),
         UINT16_C(    1581),
         UINT32_C(  3380909873) },
    {    UINT32_C(  2886652079),
         UINT16_C(   50511),
         UINT32_C(  1592828034) },
    {    UINT32_C(  2343125129),
         UINT16_C(   20956),
         UINT32_C(  2144272875) },
    {    UINT32_C(   740789534),
         UINT16_C(   53554),
         UINT32_C(  2960357442) },
    {    UINT32_C(   816825152),
         UINT16_C(   54143),
         UINT32_C(  3077173182) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    uint32_t a = test_vec[i].a;
    uint16_t b = test_vec[i].b;
    uint32_t r = simde___crc32ch(a, b);

    simde_assert_equal_u32(r, test_vec[i].r);
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint32_t a = simde_test_codegen_random_u32();
    simde_uint16_t b = simde_test_codegen_random_u16();
    simde_uint32_t r = simde___crc32ch(a, b);

    simde_test_codegen_write_u32(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_u16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_u32(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde___crc32cw(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint32_t a;
    uint32_t b;
    uint32_t r;
  } test_vec[] = {
    {    UINT32_C(   735735106),
         UINT32_C(  3233557569),
         UINT32_C(  2481777803) },
    {    UINT32_C(  4008732556),
         UINT32_C(  1015451528),
         UINT32_C(   168499025) },
    {    UINT32_C(  2471609556),
         UINT32_C(  1969214295),
         UINT32_C(    94012573) },
    {    UINT32_C(   108510218),
         UINT32_C(  1541950952),
         UINT32_C(   617862445) },
    {    UINT32_C(  3216183162),
         UINT32_C(  1301818222),
         UINT32_C(   703678561) },
    {    UINT32_C(  2155126225),
         UINT32_C(     5279748),
         UINT32_C(   104598953) },
    {    UINT32_C(  1646234016),
         UINT32_C(  1098943829),
         UINT32_C(  4016861328) },
    {    UINT32_C(  4022858730),
         UINT32_C(  4193563717),
         UINT32_C(  2600630453) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    uint32_t a = test_vec[i].a;
    uint32_t b = test_vec[i].b;
    uint32_t r = simde___crc32cw(a, b);

    simde_assert_equal_u32(r, test_vec[i].r);
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint32_t a = simde_test_codegen_random_u32();
    simde_uint32_t b = simde_test_codegen_random_u32();
    simde_uint32_t r = simde___crc32cw(a, b);

    simde_test_codegen_write_u32(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_u32(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_u32(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde___crc32cd(SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint32_t a;
    uint64_t b;
    uint32_t r;
  } test_vec[] = {
    {    UINT32_C(   130615537),
         UINT64_C( 2399774243191130112),
         UINT32_C(   290060477) },
    {    UINT32_C(  1658097419),
         UINT64_C(16993923690639568896),
         UINT32_C(  4084280299) },
    {    UINT32_C(  1251504070),
         UINT64_C( 4814969100102691840),
         UINT32_C(   459953442) },
    {    UINT32_C(  1644397280),
         UINT64_C( 7438431165034001408),
         UINT32_C(  3909693679) },
    {    UINT32_C(   637721053),
         UINT64_C(14691445376122664960),
         UINT32_C(  3000285721) },
    {    UINT32_C(   679940956),
         UINT64_C(13921761239777609728),
         UINT32_C(  1896978250) },
    {    UINT32_C(  3835130870),
         UINT64_C(14131537471582904320),
         UINT32_C(  2911869597) },
    {    UINT32_C(  2096059529),
         UINT64_C(16418279593694640128),
         UINT32_C(  2764088284) },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    uint32_t a = test_vec[i].a;
    uint64_t b = test_vec[i].b;
    uint32_t r = simde___crc32cd(a, b);

    simde_assert_equal_u32(r, test_vec[i].r);
  }

  return 0;

#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint32_t a = simde_test_codegen_random_u32();
    simde_uint64_t b = simde_test_codegen_random_u64();
    simde_uint32_t r = simde___crc32cd(a, b);

    simde_test_codegen_write_u32(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_u64(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_u32(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(__crc32b)
SIMDE_TEST_FUNC_LIST_ENTRY(__crc32h)
SIMDE_TEST_FUNC_LIST_ENTRY(__crc32w)
SIMDE_TEST_FUNC_LIST_ENTRY(__crc32d)

SIMDE_TEST_FUNC_LIST_ENTRY(__crc32cb)
SIMDE_TEST_FUNC_LIST_ENTRY(__crc32ch)
SIMDE_TEST_FUNC_LIST_ENTRY(__crc32cw)
SIMDE_TEST_FUNC_LIST_ENTRY(__crc32cd)
SIMDE_TEST_FUNC_LIST_END

#include "test-neon-footer.h"
