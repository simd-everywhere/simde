#define SIMDE_TEST_ARM_NEON_INSN ldr

#include "test-neon.h"
#include "../../../simde/arm/neon/ldr.h"

#if !defined(SIMDE_BUG_INTEL_857088)

static int
test_simde_vldrq_p128 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    simde_poly64_t a[2];
    simde_poly64_t r[2];
  } test_vec[] = {
    { {  UINT64_C( 7993925060922534912),  UINT64_C( 1126874438221124864) },
      {  UINT64_C( 7993925060922534912),  UINT64_C( 1126874438221124864) } },
    { {  UINT64_C( 7420716492656699392),  UINT64_C( 2511378975180449792) },
      {  UINT64_C( 7420716492656699392),  UINT64_C( 2511378975180449792) } },
    { {  UINT64_C( 9382034419008290816),  UINT64_C(  791181551234675072) },
      {  UINT64_C( 9382034419008290816),  UINT64_C(  791181551234675072) } },
    { {  UINT64_C( 1116395920684244736),  UINT64_C(16821514221494388736) },
      {  UINT64_C( 1116395920684244736),  UINT64_C(16821514221494388736) } },
    { {  UINT64_C( 4657531591432121344),  UINT64_C(  115277878636437328) },
      {  UINT64_C( 4657531591432121344),  UINT64_C(  115277878636437328) } },
    { {  UINT64_C(16310039023111145472),  UINT64_C( 4336263812191954432) },
      {  UINT64_C(16310039023111145472),  UINT64_C( 4336263812191954432) } },
    { {  UINT64_C( 1661321939236384512),  UINT64_C(16371475289719662592) },
      {  UINT64_C( 1661321939236384512),  UINT64_C(16371475289719662592) } },
    { {  UINT64_C( 2564185550551722496),  UINT64_C( 8118003407507670016) },
      {  UINT64_C( 2564185550551722496),  UINT64_C( 8118003407507670016) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_poly128_t a = test_vec[i].a[0];
    a = a << 64;
    a = a | test_vec[i].a[1];
    simde_poly128_t r = simde_vldrq_p128(&a);
    simde_poly128_t mask = (simde_poly128_t)0xFFFFFFFFFFFFFFFFull;
    simde_poly64_t top_r = (simde_poly64_t)((r >> 64) & mask);
    simde_poly64_t bottom_r = (simde_poly64_t)(r & mask);

    simde_assert_equal_p64(top_r, test_vec[i].r[0]);
    simde_assert_equal_p64(bottom_r, test_vec[i].r[1]);
  }

  return 0;
}

#endif /* !defined(SIMDE_BUG_INTEL_857088) */

SIMDE_TEST_FUNC_LIST_BEGIN
#if !defined(SIMDE_BUG_INTEL_857088)
SIMDE_TEST_FUNC_LIST_ENTRY(vldrq_p128)
#endif /* !defined(SIMDE_BUG_INTEL_857088) */
SIMDE_TEST_FUNC_LIST_END

#include "test-neon-footer.h"
