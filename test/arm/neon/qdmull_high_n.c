#define SIMDE_TEST_ARM_NEON_INSN qdmull_high_n

#include "test-neon.h"
#include "../../../simde/arm/neon/qdmull_high_n.h"

static int
test_simde_vqdmull_high_n_s16 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    int16_t a[8];
    int16_t b;
    int32_t r[4];
  } test_vec[] = {
     { {  -INT16_C(  6855),  INT16_C(  7703), -INT16_C(  7197), -INT16_C(  5339),
          -INT16_C(  1011), -INT16_C(  1303), -INT16_C(  6813), -INT16_C(  7254) },
          -INT16_C(   678),
       {   INT32_C(   1370916),  INT32_C(   1766868),  INT32_C(   9238428),  INT32_C(   9836424) } },
     { {  -INT16_C(  1960),  INT16_C(  1926),  INT16_C(  1231),  INT16_C(  5811),
          -INT16_C(  6109),  INT16_C(  2635),  INT16_C(  4629),  INT16_C(  8723) },
           INT16_C(  4639),
       {  -INT32_C(  56679302),  INT32_C(  24447530),  INT32_C(  42947862),  INT32_C(  80931994) } },
     { {  -INT16_C(  9194),  INT16_C(   393),  INT16_C(  4109), -INT16_C(  9430),
           INT16_C(  9440),  INT16_C(  9260), -INT16_C(  5474),  INT16_C(  7193) },
           INT16_C(  8124),
       {   INT32_C( 153381120),  INT32_C( 150456480), -INT32_C(  88941552),  INT32_C( 116871864) } },
     { {  -INT16_C(  2722), -INT16_C(  4769),  INT16_C(  3664),  INT16_C(  4842),
           INT16_C(  9709), -INT16_C(   952),  INT16_C(  2081),  INT16_C(  2443) },
           INT16_C(  4321),
       {   INT32_C(  83905178), -INT32_C(   8227184),  INT32_C(  17984002),  INT32_C(  21112406) } },
     { {  -INT16_C(   549),  INT16_C(  2071), -INT16_C(  2943), -INT16_C(  6513),
           INT16_C(  5234),  INT16_C(  8269),  INT16_C(  8331), -INT16_C(  3593) },
           INT16_C(  3622),
       {   INT32_C(  37915096),  INT32_C(  59900636),  INT32_C(  60349764), -INT32_C(  26027692) } },
     { {   INT16_C(  1637),  INT16_C(  6005),  INT16_C(  7757), -INT16_C(  5037),
          -INT16_C(  7412),  INT16_C(  9954),  INT16_C(  9621),  INT16_C(   539) },
           INT16_C(  1643),
       {  -INT32_C(  24355832),  INT32_C(  32708844),  INT32_C(  31614606),  INT32_C(   1771154) } },
     { {  -INT16_C(  1042), -INT16_C(  8045), -INT16_C(  7997),  INT16_C(  7058),
           INT16_C(  3904), -INT16_C(  6847),  INT16_C(  7139),  INT16_C(   168) },
           INT16_C(  4556),
       {   INT32_C(  35573248), -INT32_C(  62389864),  INT32_C(  65050568),  INT32_C(   1530816) } },
     { {  -INT16_C(  3460), -INT16_C(  7482), -INT16_C(  2179), -INT16_C(  7154),
          -INT16_C(  6641),  INT16_C(  7931), -INT16_C(  9615),  INT16_C(  6387) },
          -INT16_C(  8323),
       {   INT32_C( 110546086), -INT32_C( 132019426),  INT32_C( 160051290), -INT32_C( 106318002) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x8_t a = simde_vld1q_s16(test_vec[i].a);
    int16_t b = test_vec[i].b;
    simde_int32x4_t r = simde_vqdmull_high_n_s16(a, b);

    simde_test_arm_neon_assert_equal_i32x4(r, simde_vld1q_s32(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vqdmull_high_n_s32 (SIMDE_MUNIT_TEST_ARGS) {
  static const struct {
    int32_t a[4];
    int32_t b;
    int64_t r[2];
  } test_vec[] = {
     { {  -INT32_C(  362613), -INT32_C(  267565), -INT32_C(  843693),  INT32_C(  671042) },
          -INT32_C(   81635),
       {   INT64_C(  137749756110), -INT64_C(  109561027340) } },
     { {   INT32_C(  908361), -INT32_C(  481342), -INT32_C(  749809), -INT32_C(  656516) },
           INT32_C(  208325),
       {  -INT64_C(  312407919850), -INT64_C(  273537391400) } },
     { {  -INT32_C(  776382),  INT32_C(  217778), -INT32_C(  876767),  INT32_C(  470808) },
           INT32_C(  537187),
       {  -INT64_C(  941975668858),  INT64_C(  505823874192) } },
     { {   INT32_C(  339294), -INT32_C(   67580),  INT32_C(  598076), -INT32_C(  845644) },
          -INT32_C(  215512),
       {  -INT64_C(  257785109824),  INT64_C(  364492859456) } },
     { {  -INT32_C(  703782),  INT32_C(  666922),  INT32_C(  481702),  INT32_C(  138725) },
           INT32_C(  750892),
       {   INT64_C(  723412356368),  INT64_C(  208334985400) } },
     { {   INT32_C(  793067), -INT32_C(  102694), -INT32_C(  479920),  INT32_C(  869866) },
           INT32_C(  963867),
       {  -INT64_C(  925158101280),  INT64_C( 1676870263644) } },
     { {   INT32_C(  203238),  INT32_C(  788885),  INT32_C(  260866),  INT32_C(  677937) },
          -INT32_C(  242772),
       {  -INT64_C(  126661921104), -INT64_C(  329168242728) } },
     { {   INT32_C(  559982),  INT32_C(  968419), -INT32_C(   38196),  INT32_C(  286789) },
          -INT32_C(  650315),
       {   INT64_C(   49678863480), -INT64_C(  373006377070) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x4_t a = simde_vld1q_s32(test_vec[i].a);
    int32_t b = test_vec[i].b;
    simde_int64x2_t r = simde_vqdmull_high_n_s32(a, b);

    simde_test_arm_neon_assert_equal_i64x2(r, simde_vld1q_s64(test_vec[i].r));
  }

  return 0;
}


SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(vqdmull_high_n_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vqdmull_high_n_s32)
SIMDE_TEST_FUNC_LIST_END

#include "test-neon-footer.h"
