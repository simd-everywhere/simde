
#include "test/test.h"
#define SIMDE_TEST_ARM_NEON_INSN str
#include "test-neon.h"
#include "../../../simde/arm/neon/str.h"

#if !defined(SIMDE_BUG_INTEL_857088)

static int
test_simde_vstrq_p128 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    simde_poly64_t r[2];
    simde_poly64_t a[2];
  } test_vec[] = {
    { {  UINT64_C(18063461473973690368),  UINT64_C( 6968107849150213120) },
      {  UINT64_C(18063461473973690368),  UINT64_C( 6968107849150213120) } },
    { {  UINT64_C( 2317609581117667840),  UINT64_C( 3982300596093788160) },
      {  UINT64_C( 2317609581117667840),  UINT64_C( 3982300596093788160) } },
    { {  UINT64_C( 6403764795962060800),  UINT64_C( 2957619287321174016) },
      {  UINT64_C( 6403764795962060800),  UINT64_C( 2957619287321174016) } },
    { {  UINT64_C(15541412450205114368),  UINT64_C(  741679771958285696) },
      {  UINT64_C(15541412450205114368),  UINT64_C(  741679771958285696) } },
    { {  UINT64_C(15936415768508803072),  UINT64_C(  825134017355212032) },
      {  UINT64_C(15936415768508803072),  UINT64_C(  825134017355212032) } },
    { {  UINT64_C(11001807986090885120),  UINT64_C( 9746970149597376512) },
      {  UINT64_C(11001807986090885120),  UINT64_C( 9746970149597376512) } },
    { {  UINT64_C( 6913976258399734784),  UINT64_C(10244914412362354688) },
      {  UINT64_C( 6913976258399734784),  UINT64_C(10244914412362354688) } },
    { {  UINT64_C(14437372387103264768),  UINT64_C( 9534803291530612736) },
      {  UINT64_C(14437372387103264768),  UINT64_C( 9534803291530612736) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_poly128_t r_ = test_vec[i].r[0];
    r_ = r_ << 64;
    r_ = r_ | test_vec[i].r[1];
    simde_poly128_t a_;
    simde_vstrq_p128(&a_, r_);
    simde_poly128_t a = test_vec[i].a[0];
    a = a << 64;
    a = a | test_vec[i].a[1];

    simde_assert_equal_i(0, simde_memcmp(&a_, &a, sizeof(a)));
  }

  return 0;
}

#endif /* !defined(SIMDE_BUG_INTEL_857088) */

SIMDE_TEST_FUNC_LIST_BEGIN
#if !defined(SIMDE_BUG_INTEL_857088)
SIMDE_TEST_FUNC_LIST_ENTRY(vstrq_p128)
#endif /* !defined(SIMDE_BUG_INTEL_857088) */
SIMDE_TEST_FUNC_LIST_END

#include "test-neon-footer.h"
