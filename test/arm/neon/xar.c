#define SIMDE_TEST_ARM_NEON_INSN xar

#include "test-neon.h"
#include "../../../simde/arm/neon/xar.h"

static int
test_simde_vxarq_u64 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint64_t a[2];
    uint64_t b[2];
    const int d;
    uint64_t r[2];
  } test_vec[] = {
    { { UINT64_C(11727356041142892509), UINT64_C(17687812626270358532) },
      { UINT64_C(15071373037556800713), UINT64_C( 3710394713844993379) },
       INT32_C(          17),
      { UINT64_C(13081331615364366097), UINT64_C( 2356476641225865946) } },
    { { UINT64_C(14404416964460043335), UINT64_C( 7376251297218715007) },
      { UINT64_C(12163217993651160570), UINT64_C(16750145550587480422) },
       INT32_C(          43),
      { UINT64_C( 6296822807383631189), UINT64_C(13480343382885778745) } },
    { { UINT64_C(17384248020153211513), UINT64_C( 8524908529194606326) },
      { UINT64_C(  376887728410598397), UINT64_C(15853834398038142577) },
       INT32_C(           4),
      { UINT64_C( 5712740816037457944), UINT64_C( 8837376196510192392) } },
    { { UINT64_C(15542763117282072266), UINT64_C( 9289917897353527435) },
      { UINT64_C( 4043233927736141412), UINT64_C( 8468432693713248661) },
       INT32_C(           0),
      { UINT64_C(17270899268175081646), UINT64_C(17683808010555105566) } },
    { { UINT64_C(  304514043241818149), UINT64_C( 2413658150160049476) },
      { UINT64_C( 7486230234637376381), UINT64_C(13261995422464633176) },
       INT32_C(           6),
      { UINT64_C( 7029968236293343693), UINT64_C( 8243219472161530160) } },
    { { UINT64_C( 1395670340514259313), UINT64_C( 3820052463817645428) },
      { UINT64_C(16405901303992870908), UINT64_C(14008168814611249546) },
       INT32_C(          37),
      { UINT64_C(13766327808639342740), UINT64_C( 4876689383102293105) } },
    { { UINT64_C( 3250952092453426872), UINT64_C( 6382162557798588480) },
      { UINT64_C( 5298158368030670455), UINT64_C(17576286262301289946) },
       INT32_C(          26),
      { UINT64_C(10464733691901464779), UINT64_C(15741038006655454416) } },
    { { UINT64_C( 7249279570232949789), UINT64_C( 6923994607331912604) },
      { UINT64_C(14206804631696809167), UINT64_C(11142142412447028024) },
       INT32_C(          19),
      { UINT64_C( 6060248840644779666), UINT64_C(12039422898904142016) } }
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint64x2_t a = simde_vld1q_u64(test_vec[i].a);
    simde_uint64x2_t b = simde_vld1q_u64(test_vec[i].b);
    simde_uint64x2_t r = simde_vxarq_u64(a, b, test_vec[i].d);
    simde_test_arm_neon_assert_equal_u64x2(r, simde_vld1q_u64(test_vec[i].r));
  }

  return 0;
#else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint64x2_t a = simde_test_arm_neon_random_u64x2();
    simde_uint64x2_t b = simde_test_arm_neon_random_u64x2();
    const int d = abs(simde_test_codegen_random_i32() % 64);
    simde_uint64x2_t r = simde_vxarq_u64(a, b, d);

    simde_test_arm_neon_write_u64x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_u64x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, d, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_u64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(vxarq_u64)
SIMDE_TEST_FUNC_LIST_END

#include "test-neon-footer.h"
