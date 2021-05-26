#define SIMDE_TEST_X86_AVX512_INSN roundscale

#include <test/x86/avx512/test-avx512.h>
#include <simde/x86/avx512/roundscale.h>
#include <simde/x86/avx512/setzero.h>

static int
test_simde_mm_roundscale_ps (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde_float32 a[4];
    const int32_t imm8;
    const simde_float32 r[4];
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(   184.58), SIMDE_FLOAT32_C(  -477.45), SIMDE_FLOAT32_C(  -816.99), SIMDE_FLOAT32_C(  -969.27) },
       INT32_C(           0),
      { SIMDE_FLOAT32_C(   185.00), SIMDE_FLOAT32_C(  -477.00), SIMDE_FLOAT32_C(  -817.00), SIMDE_FLOAT32_C(  -969.00) } },
    { { SIMDE_FLOAT32_C(  -630.66), SIMDE_FLOAT32_C(  -650.78), SIMDE_FLOAT32_C(   424.73), SIMDE_FLOAT32_C(  -953.66) },
       INT32_C(          16),
      { SIMDE_FLOAT32_C(  -630.50), SIMDE_FLOAT32_C(  -651.00), SIMDE_FLOAT32_C(   424.50), SIMDE_FLOAT32_C(  -953.50) } },
    { {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(    49.10), SIMDE_FLOAT32_C(   398.66), SIMDE_FLOAT32_C(   620.43) },
       INT32_C(          32),
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(    49.00), SIMDE_FLOAT32_C(   398.75), SIMDE_FLOAT32_C(   620.50) } },
    { { SIMDE_FLOAT32_C(   -29.44), SIMDE_FLOAT32_C(  -399.88), SIMDE_FLOAT32_C(    -8.17), SIMDE_FLOAT32_C(  -624.68) },
       INT32_C(          48),
      { SIMDE_FLOAT32_C(   -29.50), SIMDE_FLOAT32_C(  -399.88), SIMDE_FLOAT32_C(    -8.12), SIMDE_FLOAT32_C(  -624.62) } },
    { {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   762.14), SIMDE_FLOAT32_C(   463.35), SIMDE_FLOAT32_C(  -105.13) },
       INT32_C(          64),
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   762.12), SIMDE_FLOAT32_C(   463.38), SIMDE_FLOAT32_C(  -105.12) } },
    { { SIMDE_FLOAT32_C(  -338.82), SIMDE_FLOAT32_C(  -677.32), SIMDE_FLOAT32_C(  -711.13), SIMDE_FLOAT32_C(    39.83) },
       INT32_C(          80),
      { SIMDE_FLOAT32_C(  -338.81), SIMDE_FLOAT32_C(  -677.31), SIMDE_FLOAT32_C(  -711.12), SIMDE_FLOAT32_C(    39.84) } },
    { {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   222.84), SIMDE_FLOAT32_C(   537.98), SIMDE_FLOAT32_C(   127.16) },
       INT32_C(          96),
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   222.84), SIMDE_FLOAT32_C(   537.98), SIMDE_FLOAT32_C(   127.16) } },
    { { SIMDE_FLOAT32_C(  -448.10),     -SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(  -985.10), SIMDE_FLOAT32_C(   -93.24) },
       INT32_C(         112),
      { SIMDE_FLOAT32_C(  -448.10),     -SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(  -985.10), SIMDE_FLOAT32_C(   -93.24) } },
    { { SIMDE_FLOAT32_C(   426.07),      SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(   497.75), SIMDE_FLOAT32_C(  -973.80) },
       INT32_C(         128),
      { SIMDE_FLOAT32_C(   426.07),      SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(   497.75), SIMDE_FLOAT32_C(  -973.80) } },
    { {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   635.20), SIMDE_FLOAT32_C(   314.85), SIMDE_FLOAT32_C(   453.80) },
       INT32_C(         144),
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   635.20), SIMDE_FLOAT32_C(   314.85), SIMDE_FLOAT32_C(   453.80) } },
    { { SIMDE_FLOAT32_C(  -885.03), SIMDE_FLOAT32_C(   407.49), SIMDE_FLOAT32_C(  -605.40), SIMDE_FLOAT32_C(   154.81) },
       INT32_C(         160),
      { SIMDE_FLOAT32_C(  -885.03), SIMDE_FLOAT32_C(   407.49), SIMDE_FLOAT32_C(  -605.40), SIMDE_FLOAT32_C(   154.81) } },
    { { SIMDE_FLOAT32_C(   206.02),      SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(  -547.27), SIMDE_FLOAT32_C(  -666.82) },
       INT32_C(         176),
      { SIMDE_FLOAT32_C(   206.02),      SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(  -547.27), SIMDE_FLOAT32_C(  -666.82) } },
    { { SIMDE_FLOAT32_C(   608.35),      SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(   791.84), SIMDE_FLOAT32_C(  -704.03) },
       INT32_C(         192),
      { SIMDE_FLOAT32_C(   608.35),      SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(   791.84), SIMDE_FLOAT32_C(  -704.03) } },
    { { SIMDE_FLOAT32_C(   413.65), SIMDE_FLOAT32_C(   816.78), SIMDE_FLOAT32_C(   748.24), SIMDE_FLOAT32_C(  -949.28) },
       INT32_C(         208),
      { SIMDE_FLOAT32_C(   413.65), SIMDE_FLOAT32_C(   816.78), SIMDE_FLOAT32_C(   748.24), SIMDE_FLOAT32_C(  -949.28) } },
    { { SIMDE_FLOAT32_C(   599.73), SIMDE_FLOAT32_C(  -390.36), SIMDE_FLOAT32_C(   325.04), SIMDE_FLOAT32_C(   -85.42) },
       INT32_C(         224),
      { SIMDE_FLOAT32_C(   599.73), SIMDE_FLOAT32_C(  -390.36), SIMDE_FLOAT32_C(   325.04), SIMDE_FLOAT32_C(   -85.42) } },
    { { SIMDE_FLOAT32_C(  -590.15),     -SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(  -821.59), SIMDE_FLOAT32_C(   817.34) },
       INT32_C(         240),
      { SIMDE_FLOAT32_C(  -590.15),     -SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(  -821.59), SIMDE_FLOAT32_C(   817.34) } },
    { {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   710.86), SIMDE_FLOAT32_C(   184.82), SIMDE_FLOAT32_C(   -45.89) },
       INT32_C(           1),
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   710.00), SIMDE_FLOAT32_C(   184.00), SIMDE_FLOAT32_C(   -46.00) } },
    { {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   289.03), SIMDE_FLOAT32_C(   879.59), SIMDE_FLOAT32_C(   631.03) },
       INT32_C(          17),
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   289.00), SIMDE_FLOAT32_C(   879.50), SIMDE_FLOAT32_C(   631.00) } },
    { { SIMDE_FLOAT32_C(   950.06), SIMDE_FLOAT32_C(   307.04), SIMDE_FLOAT32_C(    61.64), SIMDE_FLOAT32_C(   766.84) },
       INT32_C(          33),
      { SIMDE_FLOAT32_C(   950.00), SIMDE_FLOAT32_C(   307.00), SIMDE_FLOAT32_C(    61.50), SIMDE_FLOAT32_C(   766.75) } },
    { { SIMDE_FLOAT32_C(   112.35),     -SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(  -344.99), SIMDE_FLOAT32_C(   721.99) },
       INT32_C(          49),
      { SIMDE_FLOAT32_C(   112.25),     -SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(  -345.00), SIMDE_FLOAT32_C(   721.88) } },
    { {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -410.10), SIMDE_FLOAT32_C(   963.84), SIMDE_FLOAT32_C(     8.91) },
       INT32_C(          65),
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -410.12), SIMDE_FLOAT32_C(   963.81), SIMDE_FLOAT32_C(     8.88) } },
    { {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -374.27), SIMDE_FLOAT32_C(     7.92), SIMDE_FLOAT32_C(   -74.18) },
       INT32_C(          81),
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -374.28), SIMDE_FLOAT32_C(     7.91), SIMDE_FLOAT32_C(   -74.19) } },
    { { SIMDE_FLOAT32_C(  -549.43), SIMDE_FLOAT32_C(   419.03), SIMDE_FLOAT32_C(   977.64), SIMDE_FLOAT32_C(  -669.85) },
       INT32_C(          97),
      { SIMDE_FLOAT32_C(  -549.44), SIMDE_FLOAT32_C(   419.02), SIMDE_FLOAT32_C(   977.62), SIMDE_FLOAT32_C(  -669.86) } },
    { { SIMDE_FLOAT32_C(   562.65), SIMDE_FLOAT32_C(   978.14), SIMDE_FLOAT32_C(     0.12), SIMDE_FLOAT32_C(  -130.31) },
       INT32_C(         113),
      { SIMDE_FLOAT32_C(   562.65), SIMDE_FLOAT32_C(   978.13), SIMDE_FLOAT32_C(     0.12), SIMDE_FLOAT32_C(  -130.31) } },
    { {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   924.97), SIMDE_FLOAT32_C(  -847.87), SIMDE_FLOAT32_C(  -776.36) },
       INT32_C(         129),
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   924.97), SIMDE_FLOAT32_C(  -847.87), SIMDE_FLOAT32_C(  -776.36) } },
    { { SIMDE_FLOAT32_C(     5.36),     -SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(   659.56), SIMDE_FLOAT32_C(  -803.07) },
       INT32_C(         145),
      { SIMDE_FLOAT32_C(     5.36),     -SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(   659.56), SIMDE_FLOAT32_C(  -803.07) } },
    { { SIMDE_FLOAT32_C(  -255.70), SIMDE_FLOAT32_C(   -79.54), SIMDE_FLOAT32_C(   -53.15), SIMDE_FLOAT32_C(   370.03) },
       INT32_C(         161),
      { SIMDE_FLOAT32_C(  -255.70), SIMDE_FLOAT32_C(   -79.54), SIMDE_FLOAT32_C(   -53.15), SIMDE_FLOAT32_C(   370.03) } },
    { { SIMDE_FLOAT32_C(   872.67), SIMDE_FLOAT32_C(   -50.13), SIMDE_FLOAT32_C(  -383.01), SIMDE_FLOAT32_C(  -676.76) },
       INT32_C(         177),
      { SIMDE_FLOAT32_C(   872.67), SIMDE_FLOAT32_C(   -50.13), SIMDE_FLOAT32_C(  -383.01), SIMDE_FLOAT32_C(  -676.76) } },
    { { SIMDE_FLOAT32_C(  -405.36),     -SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(   418.96), SIMDE_FLOAT32_C(  -842.72) },
       INT32_C(         193),
      { SIMDE_FLOAT32_C(  -405.36),     -SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(   418.96), SIMDE_FLOAT32_C(  -842.72) } },
    { { SIMDE_FLOAT32_C(   671.31), SIMDE_FLOAT32_C(   186.05), SIMDE_FLOAT32_C(   -48.06), SIMDE_FLOAT32_C(   823.45) },
       INT32_C(         209),
      { SIMDE_FLOAT32_C(   671.31), SIMDE_FLOAT32_C(   186.05), SIMDE_FLOAT32_C(   -48.06), SIMDE_FLOAT32_C(   823.45) } },
    { { SIMDE_FLOAT32_C(   531.93), SIMDE_FLOAT32_C(   697.57), SIMDE_FLOAT32_C(  -584.95), SIMDE_FLOAT32_C(   681.51) },
       INT32_C(         225),
      { SIMDE_FLOAT32_C(   531.93), SIMDE_FLOAT32_C(   697.57), SIMDE_FLOAT32_C(  -584.95), SIMDE_FLOAT32_C(   681.51) } },
    { { SIMDE_FLOAT32_C(  -388.02), SIMDE_FLOAT32_C(  -579.00), SIMDE_FLOAT32_C(   -19.47), SIMDE_FLOAT32_C(   817.83) },
       INT32_C(         241),
      { SIMDE_FLOAT32_C(  -388.02), SIMDE_FLOAT32_C(  -579.00), SIMDE_FLOAT32_C(   -19.47), SIMDE_FLOAT32_C(   817.83) } },
    { {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -235.32), SIMDE_FLOAT32_C(  -464.67), SIMDE_FLOAT32_C(   829.38) },
       INT32_C(           2),
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -235.00), SIMDE_FLOAT32_C(  -464.00), SIMDE_FLOAT32_C(   830.00) } },
    { {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   -39.42), SIMDE_FLOAT32_C(   854.11), SIMDE_FLOAT32_C(    41.00) },
       INT32_C(          18),
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   -39.00), SIMDE_FLOAT32_C(   854.50), SIMDE_FLOAT32_C(    41.00) } },
    { { SIMDE_FLOAT32_C(   198.28), SIMDE_FLOAT32_C(  -754.49), SIMDE_FLOAT32_C(   692.15), SIMDE_FLOAT32_C(  -774.75) },
       INT32_C(          34),
      { SIMDE_FLOAT32_C(   198.50), SIMDE_FLOAT32_C(  -754.25), SIMDE_FLOAT32_C(   692.25), SIMDE_FLOAT32_C(  -774.75) } },
    { { SIMDE_FLOAT32_C(  -121.80), SIMDE_FLOAT32_C(   177.20), SIMDE_FLOAT32_C(   740.27), SIMDE_FLOAT32_C(  -712.11) },
       INT32_C(          50),
      { SIMDE_FLOAT32_C(  -121.75), SIMDE_FLOAT32_C(   177.25), SIMDE_FLOAT32_C(   740.38), SIMDE_FLOAT32_C(  -712.00) } },
    { { SIMDE_FLOAT32_C(   437.85), SIMDE_FLOAT32_C(  -297.06), SIMDE_FLOAT32_C(  -609.36), SIMDE_FLOAT32_C(  -205.02) },
       INT32_C(          66),
      { SIMDE_FLOAT32_C(   437.88), SIMDE_FLOAT32_C(  -297.00), SIMDE_FLOAT32_C(  -609.31), SIMDE_FLOAT32_C(  -205.00) } },
    { { SIMDE_FLOAT32_C(  -188.36), SIMDE_FLOAT32_C(   775.51), SIMDE_FLOAT32_C(   132.74), SIMDE_FLOAT32_C(   976.93) },
       INT32_C(          82),
      { SIMDE_FLOAT32_C(  -188.34), SIMDE_FLOAT32_C(   775.53), SIMDE_FLOAT32_C(   132.75), SIMDE_FLOAT32_C(   976.94) } },
    { {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -487.74), SIMDE_FLOAT32_C(   505.88), SIMDE_FLOAT32_C(  -465.24) },
       INT32_C(          98),
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -487.73), SIMDE_FLOAT32_C(   505.89), SIMDE_FLOAT32_C(  -465.23) } },
    { { SIMDE_FLOAT32_C(   495.34), SIMDE_FLOAT32_C(   851.57), SIMDE_FLOAT32_C(    -6.75), SIMDE_FLOAT32_C(   109.32) },
       INT32_C(         114),
      { SIMDE_FLOAT32_C(   495.34), SIMDE_FLOAT32_C(   851.57), SIMDE_FLOAT32_C(    -6.75), SIMDE_FLOAT32_C(   109.32) } },
    { { SIMDE_FLOAT32_C(  -808.46), SIMDE_FLOAT32_C(   354.82), SIMDE_FLOAT32_C(  -183.20), SIMDE_FLOAT32_C(  -583.21) },
       INT32_C(         130),
      { SIMDE_FLOAT32_C(  -808.46), SIMDE_FLOAT32_C(   354.82), SIMDE_FLOAT32_C(  -183.20), SIMDE_FLOAT32_C(  -583.21) } },
    { { SIMDE_FLOAT32_C(   695.00), SIMDE_FLOAT32_C(   593.99), SIMDE_FLOAT32_C(    11.92), SIMDE_FLOAT32_C(   982.89) },
       INT32_C(         146),
      { SIMDE_FLOAT32_C(   695.00), SIMDE_FLOAT32_C(   593.99), SIMDE_FLOAT32_C(    11.92), SIMDE_FLOAT32_C(   982.89) } },
    { {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -314.18), SIMDE_FLOAT32_C(  -306.25), SIMDE_FLOAT32_C(   244.74) },
       INT32_C(         162),
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -314.18), SIMDE_FLOAT32_C(  -306.25), SIMDE_FLOAT32_C(   244.74) } },
    { { SIMDE_FLOAT32_C(    20.26), SIMDE_FLOAT32_C(   133.48), SIMDE_FLOAT32_C(   482.32), SIMDE_FLOAT32_C(  -303.23) },
       INT32_C(         178),
      { SIMDE_FLOAT32_C(    20.26), SIMDE_FLOAT32_C(   133.48), SIMDE_FLOAT32_C(   482.32), SIMDE_FLOAT32_C(  -303.23) } },
    { {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -797.35), SIMDE_FLOAT32_C(   565.65), SIMDE_FLOAT32_C(   992.05) },
       INT32_C(         194),
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -797.35), SIMDE_FLOAT32_C(   565.65), SIMDE_FLOAT32_C(   992.05) } },
    { { SIMDE_FLOAT32_C(   843.62), SIMDE_FLOAT32_C(   148.16), SIMDE_FLOAT32_C(  -829.69), SIMDE_FLOAT32_C(   -31.74) },
       INT32_C(         210),
      { SIMDE_FLOAT32_C(   843.62), SIMDE_FLOAT32_C(   148.16), SIMDE_FLOAT32_C(  -829.69), SIMDE_FLOAT32_C(   -31.74) } },
    { { SIMDE_FLOAT32_C(   525.13),      SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(   756.48), SIMDE_FLOAT32_C(  -203.22) },
       INT32_C(         226),
      { SIMDE_FLOAT32_C(   525.13),      SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(   756.48), SIMDE_FLOAT32_C(  -203.22) } },
    { { SIMDE_FLOAT32_C(   462.95), SIMDE_FLOAT32_C(   653.59), SIMDE_FLOAT32_C(  -741.53), SIMDE_FLOAT32_C(  -851.23) },
       INT32_C(         242),
      { SIMDE_FLOAT32_C(   462.95), SIMDE_FLOAT32_C(   653.59), SIMDE_FLOAT32_C(  -741.53), SIMDE_FLOAT32_C(  -851.23) } },
    { {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -850.49), SIMDE_FLOAT32_C(   852.73), SIMDE_FLOAT32_C(  -476.53) },
       INT32_C(           3),
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -850.00), SIMDE_FLOAT32_C(   852.00), SIMDE_FLOAT32_C(  -476.00) } },
    { { SIMDE_FLOAT32_C(   220.24), SIMDE_FLOAT32_C(  -686.13), SIMDE_FLOAT32_C(   329.63), SIMDE_FLOAT32_C(   422.89) },
       INT32_C(          19),
      { SIMDE_FLOAT32_C(   220.00), SIMDE_FLOAT32_C(  -686.00), SIMDE_FLOAT32_C(   329.50), SIMDE_FLOAT32_C(   422.50) } },
    { { SIMDE_FLOAT32_C(   321.68), SIMDE_FLOAT32_C(   577.80), SIMDE_FLOAT32_C(   -59.48), SIMDE_FLOAT32_C(   165.30) },
       INT32_C(          35),
      { SIMDE_FLOAT32_C(   321.50), SIMDE_FLOAT32_C(   577.75), SIMDE_FLOAT32_C(   -59.25), SIMDE_FLOAT32_C(   165.25) } },
    { { SIMDE_FLOAT32_C(   110.83), SIMDE_FLOAT32_C(  -866.44), SIMDE_FLOAT32_C(  -934.35), SIMDE_FLOAT32_C(  -364.04) },
       INT32_C(          51),
      { SIMDE_FLOAT32_C(   110.75), SIMDE_FLOAT32_C(  -866.38), SIMDE_FLOAT32_C(  -934.25), SIMDE_FLOAT32_C(  -364.00) } },
    { { SIMDE_FLOAT32_C(   822.13), SIMDE_FLOAT32_C(   432.74), SIMDE_FLOAT32_C(   398.69), SIMDE_FLOAT32_C(   172.60) },
       INT32_C(          67),
      { SIMDE_FLOAT32_C(   822.12), SIMDE_FLOAT32_C(   432.69), SIMDE_FLOAT32_C(   398.69), SIMDE_FLOAT32_C(   172.56) } },
    { { SIMDE_FLOAT32_C(  -138.37),      SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(   499.91), SIMDE_FLOAT32_C(    10.40) },
       INT32_C(          83),
      { SIMDE_FLOAT32_C(  -138.34),      SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(   499.91), SIMDE_FLOAT32_C(    10.38) } },
    { {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   526.59), SIMDE_FLOAT32_C(  -557.11), SIMDE_FLOAT32_C(  -638.70) },
       INT32_C(          99),
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   526.58), SIMDE_FLOAT32_C(  -557.11), SIMDE_FLOAT32_C(  -638.69) } },
    { {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -830.28), SIMDE_FLOAT32_C(  -363.71), SIMDE_FLOAT32_C(    12.61) },
       INT32_C(         115),
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -830.27), SIMDE_FLOAT32_C(  -363.70), SIMDE_FLOAT32_C(    12.61) } },
    { { SIMDE_FLOAT32_C(  -822.09),      SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(  -312.37), SIMDE_FLOAT32_C(  -688.53) },
       INT32_C(         131),
      { SIMDE_FLOAT32_C(  -822.09),      SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(  -312.37), SIMDE_FLOAT32_C(  -688.53) } },
    { { SIMDE_FLOAT32_C(  -638.75),      SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(   628.78), SIMDE_FLOAT32_C(   533.85) },
       INT32_C(         147),
      { SIMDE_FLOAT32_C(  -638.75),      SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(   628.78), SIMDE_FLOAT32_C(   533.85) } },
    { { SIMDE_FLOAT32_C(   497.68), SIMDE_FLOAT32_C(   500.82), SIMDE_FLOAT32_C(   533.57), SIMDE_FLOAT32_C(  -499.20) },
       INT32_C(         163),
      { SIMDE_FLOAT32_C(   497.68), SIMDE_FLOAT32_C(   500.82), SIMDE_FLOAT32_C(   533.57), SIMDE_FLOAT32_C(  -499.20) } },
    { { SIMDE_FLOAT32_C(  -440.17), SIMDE_FLOAT32_C(  -972.62), SIMDE_FLOAT32_C(   103.62), SIMDE_FLOAT32_C(   -78.87) },
       INT32_C(         179),
      { SIMDE_FLOAT32_C(  -440.17), SIMDE_FLOAT32_C(  -972.62), SIMDE_FLOAT32_C(   103.62), SIMDE_FLOAT32_C(   -78.87) } },
    { { SIMDE_FLOAT32_C(   860.38),      SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(   -56.08), SIMDE_FLOAT32_C(  -503.33) },
       INT32_C(         195),
      { SIMDE_FLOAT32_C(   860.38),      SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(   -56.08), SIMDE_FLOAT32_C(  -503.33) } },
    { {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   164.90), SIMDE_FLOAT32_C(  -238.89), SIMDE_FLOAT32_C(  -885.95) },
       INT32_C(         211),
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   164.90), SIMDE_FLOAT32_C(  -238.89), SIMDE_FLOAT32_C(  -885.95) } },
    { { SIMDE_FLOAT32_C(  -655.85), SIMDE_FLOAT32_C(  -934.74), SIMDE_FLOAT32_C(  -158.97), SIMDE_FLOAT32_C(   972.94) },
       INT32_C(         227),
      { SIMDE_FLOAT32_C(  -655.85), SIMDE_FLOAT32_C(  -934.74), SIMDE_FLOAT32_C(  -158.97), SIMDE_FLOAT32_C(   972.94) } },
    { { SIMDE_FLOAT32_C(  -161.19), SIMDE_FLOAT32_C(  -536.65), SIMDE_FLOAT32_C(   959.15), SIMDE_FLOAT32_C(  -663.51) },
       INT32_C(         243),
      { SIMDE_FLOAT32_C(  -161.19), SIMDE_FLOAT32_C(  -536.65), SIMDE_FLOAT32_C(   959.15), SIMDE_FLOAT32_C(  -663.51) } },
    { { SIMDE_FLOAT32_C(   492.72), SIMDE_FLOAT32_C(  -162.72), SIMDE_FLOAT32_C(  -375.10), SIMDE_FLOAT32_C(  -947.45) },
       INT32_C(           4),
      { SIMDE_FLOAT32_C(   493.00), SIMDE_FLOAT32_C(  -163.00), SIMDE_FLOAT32_C(  -375.00), SIMDE_FLOAT32_C(  -947.00) } },
    { { SIMDE_FLOAT32_C(   728.52), SIMDE_FLOAT32_C(   -26.32), SIMDE_FLOAT32_C(   638.87), SIMDE_FLOAT32_C(   588.91) },
       INT32_C(          20),
      { SIMDE_FLOAT32_C(   728.50), SIMDE_FLOAT32_C(   -26.50), SIMDE_FLOAT32_C(   639.00), SIMDE_FLOAT32_C(   589.00) } },
    { {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -914.42), SIMDE_FLOAT32_C(   210.42), SIMDE_FLOAT32_C(   274.23) },
       INT32_C(          36),
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -914.50), SIMDE_FLOAT32_C(   210.50), SIMDE_FLOAT32_C(   274.25) } },
    { { SIMDE_FLOAT32_C(  -560.87),     -SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(   127.05), SIMDE_FLOAT32_C(  -856.85) },
       INT32_C(          52),
      { SIMDE_FLOAT32_C(  -560.88),     -SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(   127.00), SIMDE_FLOAT32_C(  -856.88) } },
    { { SIMDE_FLOAT32_C(   845.91), SIMDE_FLOAT32_C(   444.14), SIMDE_FLOAT32_C(   807.52), SIMDE_FLOAT32_C(  -315.29) },
       INT32_C(          68),
      { SIMDE_FLOAT32_C(   845.94), SIMDE_FLOAT32_C(   444.12), SIMDE_FLOAT32_C(   807.50), SIMDE_FLOAT32_C(  -315.31) } },
    { { SIMDE_FLOAT32_C(   766.67), SIMDE_FLOAT32_C(    21.20), SIMDE_FLOAT32_C(   871.67), SIMDE_FLOAT32_C(   259.40) },
       INT32_C(          84),
      { SIMDE_FLOAT32_C(   766.66), SIMDE_FLOAT32_C(    21.19), SIMDE_FLOAT32_C(   871.66), SIMDE_FLOAT32_C(   259.41) } },
    { {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   311.95), SIMDE_FLOAT32_C(  -276.85), SIMDE_FLOAT32_C(  -774.90) },
       INT32_C(         100),
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   311.95), SIMDE_FLOAT32_C(  -276.84), SIMDE_FLOAT32_C(  -774.91) } },
    { { SIMDE_FLOAT32_C(   814.00), SIMDE_FLOAT32_C(   871.38), SIMDE_FLOAT32_C(   -55.18), SIMDE_FLOAT32_C(   899.58) },
       INT32_C(         116),
      { SIMDE_FLOAT32_C(   814.00), SIMDE_FLOAT32_C(   871.38), SIMDE_FLOAT32_C(   -55.18), SIMDE_FLOAT32_C(   899.58) } },
    { { SIMDE_FLOAT32_C(  -780.95),      SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(  -905.21), SIMDE_FLOAT32_C(  -341.82) },
       INT32_C(         132),
      { SIMDE_FLOAT32_C(  -780.95),      SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(  -905.21), SIMDE_FLOAT32_C(  -341.82) } },
    { { SIMDE_FLOAT32_C(   983.68), SIMDE_FLOAT32_C(  -306.95), SIMDE_FLOAT32_C(     9.74), SIMDE_FLOAT32_C(   829.59) },
       INT32_C(         148),
      { SIMDE_FLOAT32_C(   983.68), SIMDE_FLOAT32_C(  -306.95), SIMDE_FLOAT32_C(     9.74), SIMDE_FLOAT32_C(   829.59) } },
    { { SIMDE_FLOAT32_C(  -182.74),      SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(  -955.30), SIMDE_FLOAT32_C(  -416.07) },
       INT32_C(         164),
      { SIMDE_FLOAT32_C(  -182.74),      SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(  -955.30), SIMDE_FLOAT32_C(  -416.07) } },
    { { SIMDE_FLOAT32_C(   393.98),      SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(   155.28), SIMDE_FLOAT32_C(  -882.87) },
       INT32_C(         180),
      { SIMDE_FLOAT32_C(   393.98),      SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(   155.28), SIMDE_FLOAT32_C(  -882.87) } },
    { { SIMDE_FLOAT32_C(  -547.96), SIMDE_FLOAT32_C(   312.29), SIMDE_FLOAT32_C(   423.96), SIMDE_FLOAT32_C(  -648.38) },
       INT32_C(         196),
      { SIMDE_FLOAT32_C(  -547.96), SIMDE_FLOAT32_C(   312.29), SIMDE_FLOAT32_C(   423.96), SIMDE_FLOAT32_C(  -648.38) } },
    { {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -589.74), SIMDE_FLOAT32_C(  -511.12), SIMDE_FLOAT32_C(  -698.81) },
       INT32_C(         212),
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -589.74), SIMDE_FLOAT32_C(  -511.12), SIMDE_FLOAT32_C(  -698.81) } },
    { { SIMDE_FLOAT32_C(   102.53), SIMDE_FLOAT32_C(   372.75), SIMDE_FLOAT32_C(  -596.22), SIMDE_FLOAT32_C(  -887.73) },
       INT32_C(         228),
      { SIMDE_FLOAT32_C(   102.53), SIMDE_FLOAT32_C(   372.75), SIMDE_FLOAT32_C(  -596.22), SIMDE_FLOAT32_C(  -887.73) } },
    { { SIMDE_FLOAT32_C(  -459.02), SIMDE_FLOAT32_C(   -70.47), SIMDE_FLOAT32_C(   716.63), SIMDE_FLOAT32_C(  -414.33) },
       INT32_C(         244),
      { SIMDE_FLOAT32_C(  -459.02), SIMDE_FLOAT32_C(   -70.47), SIMDE_FLOAT32_C(   716.63), SIMDE_FLOAT32_C(  -414.33) } },
  };

  simde__m128 a, r;

  a = simde_mm_loadu_ps(test_vec[0].a);
  r = simde_mm_roundscale_ps(a, INT32_C(           0));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[0].r), 1);

  a = simde_mm_loadu_ps(test_vec[1].a);
  r = simde_mm_roundscale_ps(a, INT32_C(          16));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[1].r), 1);

  a = simde_mm_loadu_ps(test_vec[2].a);
  r = simde_mm_roundscale_ps(a, INT32_C(          32));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[2].r), 1);

  a = simde_mm_loadu_ps(test_vec[3].a);
  r = simde_mm_roundscale_ps(a, INT32_C(          48));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[3].r), 1);

  a = simde_mm_loadu_ps(test_vec[4].a);
  r = simde_mm_roundscale_ps(a, INT32_C(          64));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[4].r), 1);

  a = simde_mm_loadu_ps(test_vec[5].a);
  r = simde_mm_roundscale_ps(a, INT32_C(          80));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[5].r), 1);

  a = simde_mm_loadu_ps(test_vec[6].a);
  r = simde_mm_roundscale_ps(a, INT32_C(          96));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[6].r), 1);

  a = simde_mm_loadu_ps(test_vec[7].a);
  r = simde_mm_roundscale_ps(a, INT32_C(         112));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[7].r), 1);

  a = simde_mm_loadu_ps(test_vec[8].a);
  r = simde_mm_roundscale_ps(a, INT32_C(         128));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[8].r), 1);

  a = simde_mm_loadu_ps(test_vec[9].a);
  r = simde_mm_roundscale_ps(a, INT32_C(         144));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[9].r), 1);

  a = simde_mm_loadu_ps(test_vec[10].a);
  r = simde_mm_roundscale_ps(a, INT32_C(         160));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[10].r), 1);

  a = simde_mm_loadu_ps(test_vec[11].a);
  r = simde_mm_roundscale_ps(a, INT32_C(         176));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[11].r), 1);

  a = simde_mm_loadu_ps(test_vec[12].a);
  r = simde_mm_roundscale_ps(a, INT32_C(         192));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[12].r), 1);

  a = simde_mm_loadu_ps(test_vec[13].a);
  r = simde_mm_roundscale_ps(a, INT32_C(         208));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[13].r), 1);

  a = simde_mm_loadu_ps(test_vec[14].a);
  r = simde_mm_roundscale_ps(a, INT32_C(         224));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[14].r), 1);

  a = simde_mm_loadu_ps(test_vec[15].a);
  r = simde_mm_roundscale_ps(a, INT32_C(         240));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[15].r), 1);

  a = simde_mm_loadu_ps(test_vec[16].a);
  r = simde_mm_roundscale_ps(a, INT32_C(           1));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[16].r), 1);

  a = simde_mm_loadu_ps(test_vec[17].a);
  r = simde_mm_roundscale_ps(a, INT32_C(          17));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[17].r), 1);

  a = simde_mm_loadu_ps(test_vec[18].a);
  r = simde_mm_roundscale_ps(a, INT32_C(          33));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[18].r), 1);

  a = simde_mm_loadu_ps(test_vec[19].a);
  r = simde_mm_roundscale_ps(a, INT32_C(          49));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[19].r), 1);

  a = simde_mm_loadu_ps(test_vec[20].a);
  r = simde_mm_roundscale_ps(a, INT32_C(          65));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[20].r), 1);

  a = simde_mm_loadu_ps(test_vec[21].a);
  r = simde_mm_roundscale_ps(a, INT32_C(          81));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[21].r), 1);

  a = simde_mm_loadu_ps(test_vec[22].a);
  r = simde_mm_roundscale_ps(a, INT32_C(          97));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[22].r), 1);

  a = simde_mm_loadu_ps(test_vec[23].a);
  r = simde_mm_roundscale_ps(a, INT32_C(         113));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[23].r), 1);

  a = simde_mm_loadu_ps(test_vec[24].a);
  r = simde_mm_roundscale_ps(a, INT32_C(         129));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[24].r), 1);

  a = simde_mm_loadu_ps(test_vec[25].a);
  r = simde_mm_roundscale_ps(a, INT32_C(         145));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[25].r), 1);

  a = simde_mm_loadu_ps(test_vec[26].a);
  r = simde_mm_roundscale_ps(a, INT32_C(         161));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[26].r), 1);

  a = simde_mm_loadu_ps(test_vec[27].a);
  r = simde_mm_roundscale_ps(a, INT32_C(         177));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[27].r), 1);

  a = simde_mm_loadu_ps(test_vec[28].a);
  r = simde_mm_roundscale_ps(a, INT32_C(         193));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[28].r), 1);

  a = simde_mm_loadu_ps(test_vec[29].a);
  r = simde_mm_roundscale_ps(a, INT32_C(         209));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[29].r), 1);

  a = simde_mm_loadu_ps(test_vec[30].a);
  r = simde_mm_roundscale_ps(a, INT32_C(         225));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[30].r), 1);

  a = simde_mm_loadu_ps(test_vec[31].a);
  r = simde_mm_roundscale_ps(a, INT32_C(         241));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[31].r), 1);

  a = simde_mm_loadu_ps(test_vec[32].a);
  r = simde_mm_roundscale_ps(a, INT32_C(           2));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[32].r), 1);

  a = simde_mm_loadu_ps(test_vec[33].a);
  r = simde_mm_roundscale_ps(a, INT32_C(          18));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[33].r), 1);

  a = simde_mm_loadu_ps(test_vec[34].a);
  r = simde_mm_roundscale_ps(a, INT32_C(          34));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[34].r), 1);

  a = simde_mm_loadu_ps(test_vec[35].a);
  r = simde_mm_roundscale_ps(a, INT32_C(          50));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[35].r), 1);

  a = simde_mm_loadu_ps(test_vec[36].a);
  r = simde_mm_roundscale_ps(a, INT32_C(          66));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[36].r), 1);

  a = simde_mm_loadu_ps(test_vec[37].a);
  r = simde_mm_roundscale_ps(a, INT32_C(          82));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[37].r), 1);

  a = simde_mm_loadu_ps(test_vec[38].a);
  r = simde_mm_roundscale_ps(a, INT32_C(          98));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[38].r), 1);

  a = simde_mm_loadu_ps(test_vec[39].a);
  r = simde_mm_roundscale_ps(a, INT32_C(         114));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[39].r), 1);

  a = simde_mm_loadu_ps(test_vec[40].a);
  r = simde_mm_roundscale_ps(a, INT32_C(         130));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[40].r), 1);

  a = simde_mm_loadu_ps(test_vec[41].a);
  r = simde_mm_roundscale_ps(a, INT32_C(         146));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[41].r), 1);

  a = simde_mm_loadu_ps(test_vec[42].a);
  r = simde_mm_roundscale_ps(a, INT32_C(         162));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[42].r), 1);

  a = simde_mm_loadu_ps(test_vec[43].a);
  r = simde_mm_roundscale_ps(a, INT32_C(         178));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[43].r), 1);

  a = simde_mm_loadu_ps(test_vec[44].a);
  r = simde_mm_roundscale_ps(a, INT32_C(         194));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[44].r), 1);

  a = simde_mm_loadu_ps(test_vec[45].a);
  r = simde_mm_roundscale_ps(a, INT32_C(         210));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[45].r), 1);

  a = simde_mm_loadu_ps(test_vec[46].a);
  r = simde_mm_roundscale_ps(a, INT32_C(         226));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[46].r), 1);

  a = simde_mm_loadu_ps(test_vec[47].a);
  r = simde_mm_roundscale_ps(a, INT32_C(         242));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[47].r), 1);

  a = simde_mm_loadu_ps(test_vec[48].a);
  r = simde_mm_roundscale_ps(a, INT32_C(           3));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[48].r), 1);

  a = simde_mm_loadu_ps(test_vec[49].a);
  r = simde_mm_roundscale_ps(a, INT32_C(          19));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[49].r), 1);

  a = simde_mm_loadu_ps(test_vec[50].a);
  r = simde_mm_roundscale_ps(a, INT32_C(          35));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[50].r), 1);

  a = simde_mm_loadu_ps(test_vec[51].a);
  r = simde_mm_roundscale_ps(a, INT32_C(          51));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[51].r), 1);

  a = simde_mm_loadu_ps(test_vec[52].a);
  r = simde_mm_roundscale_ps(a, INT32_C(          67));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[52].r), 1);

  a = simde_mm_loadu_ps(test_vec[53].a);
  r = simde_mm_roundscale_ps(a, INT32_C(          83));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[53].r), 1);

  a = simde_mm_loadu_ps(test_vec[54].a);
  r = simde_mm_roundscale_ps(a, INT32_C(          99));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[54].r), 1);

  a = simde_mm_loadu_ps(test_vec[55].a);
  r = simde_mm_roundscale_ps(a, INT32_C(         115));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[55].r), 1);

  a = simde_mm_loadu_ps(test_vec[56].a);
  r = simde_mm_roundscale_ps(a, INT32_C(         131));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[56].r), 1);

  a = simde_mm_loadu_ps(test_vec[57].a);
  r = simde_mm_roundscale_ps(a, INT32_C(         147));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[57].r), 1);

  a = simde_mm_loadu_ps(test_vec[58].a);
  r = simde_mm_roundscale_ps(a, INT32_C(         163));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[58].r), 1);

  a = simde_mm_loadu_ps(test_vec[59].a);
  r = simde_mm_roundscale_ps(a, INT32_C(         179));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[59].r), 1);

  a = simde_mm_loadu_ps(test_vec[60].a);
  r = simde_mm_roundscale_ps(a, INT32_C(         195));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[60].r), 1);

  a = simde_mm_loadu_ps(test_vec[61].a);
  r = simde_mm_roundscale_ps(a, INT32_C(         211));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[61].r), 1);

  a = simde_mm_loadu_ps(test_vec[62].a);
  r = simde_mm_roundscale_ps(a, INT32_C(         227));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[62].r), 1);

  a = simde_mm_loadu_ps(test_vec[63].a);
  r = simde_mm_roundscale_ps(a, INT32_C(         243));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[63].r), 1);

  a = simde_mm_loadu_ps(test_vec[64].a);
  r = simde_mm_roundscale_ps(a, INT32_C(           4));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[64].r), 1);

  a = simde_mm_loadu_ps(test_vec[65].a);
  r = simde_mm_roundscale_ps(a, INT32_C(          20));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[65].r), 1);

  a = simde_mm_loadu_ps(test_vec[66].a);
  r = simde_mm_roundscale_ps(a, INT32_C(          36));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[66].r), 1);

  a = simde_mm_loadu_ps(test_vec[67].a);
  r = simde_mm_roundscale_ps(a, INT32_C(          52));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[67].r), 1);

  a = simde_mm_loadu_ps(test_vec[68].a);
  r = simde_mm_roundscale_ps(a, INT32_C(          68));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[68].r), 1);

  a = simde_mm_loadu_ps(test_vec[69].a);
  r = simde_mm_roundscale_ps(a, INT32_C(          84));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[69].r), 1);

  a = simde_mm_loadu_ps(test_vec[70].a);
  r = simde_mm_roundscale_ps(a, INT32_C(         100));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[70].r), 1);

  a = simde_mm_loadu_ps(test_vec[71].a);
  r = simde_mm_roundscale_ps(a, INT32_C(         116));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[71].r), 1);

  a = simde_mm_loadu_ps(test_vec[72].a);
  r = simde_mm_roundscale_ps(a, INT32_C(         132));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[72].r), 1);

  a = simde_mm_loadu_ps(test_vec[73].a);
  r = simde_mm_roundscale_ps(a, INT32_C(         148));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[73].r), 1);

  a = simde_mm_loadu_ps(test_vec[74].a);
  r = simde_mm_roundscale_ps(a, INT32_C(         164));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[74].r), 1);

  a = simde_mm_loadu_ps(test_vec[75].a);
  r = simde_mm_roundscale_ps(a, INT32_C(         180));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[75].r), 1);

  a = simde_mm_loadu_ps(test_vec[76].a);
  r = simde_mm_roundscale_ps(a, INT32_C(         196));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[76].r), 1);

  a = simde_mm_loadu_ps(test_vec[77].a);
  r = simde_mm_roundscale_ps(a, INT32_C(         212));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[77].r), 1);

  a = simde_mm_loadu_ps(test_vec[78].a);
  r = simde_mm_roundscale_ps(a, INT32_C(         228));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[78].r), 1);

  a = simde_mm_loadu_ps(test_vec[79].a);
  r = simde_mm_roundscale_ps(a, INT32_C(         244));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[79].r), 1);

  return 0;
#else
  fputc('\n', stdout);
  int round_type[5] = {SIMDE_MM_FROUND_TO_NEAREST_INT, SIMDE_MM_FROUND_TO_NEG_INF, SIMDE_MM_FROUND_TO_POS_INF, SIMDE_MM_FROUND_TO_ZERO, SIMDE_MM_FROUND_CUR_DIRECTION};
  for (int i = 0 ; i < 5 ; i++) {
    for (int j = 0 ; j < 16 ; j++) {
      simde__m128 a = simde_test_x86_random_f32x4(SIMDE_FLOAT32_C(-1000.0), SIMDE_FLOAT32_C(1000.0));
      if((simde_test_codegen_rand() & 1)) {
        if((simde_test_codegen_rand() & 1))
          a = simde_mm_blend_ps(a, simde_mm_set1_ps(SIMDE_MATH_NANF), 1);
        else {
          if((simde_test_codegen_rand() & 1))
            a = simde_mm_blend_ps(a, simde_mm_set1_ps(SIMDE_MATH_INFINITY), 2);
          else
            a = simde_mm_blend_ps(a, simde_mm_set1_ps(-SIMDE_MATH_INFINITY), 2);
        }
      }
      int imm8 = ((j << 4) | round_type[i]) & 255;
      simde__m128 r;
      SIMDE_CONSTIFY_256_(simde_mm_roundscale_ps, r, simde_mm_setzero_ps(), imm8, a);

      simde_test_x86_write_f32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
      simde_test_codegen_write_i32(2, imm8, SIMDE_TEST_VEC_POS_MIDDLE);
      simde_test_x86_write_f32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
    }
  }
  return 1;
#endif
}

static int
test_simde_mm256_roundscale_ps (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde_float32 a[8];
    const int32_t imm8;
    const simde_float32 r[8];
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(   680.63),      SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(   441.98), SIMDE_FLOAT32_C(   661.29),
        SIMDE_FLOAT32_C(    38.40), SIMDE_FLOAT32_C(  -974.53), SIMDE_FLOAT32_C(   579.66), SIMDE_FLOAT32_C(  -989.32) },
       INT32_C(           0),
      { SIMDE_FLOAT32_C(   681.00),      SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(   442.00), SIMDE_FLOAT32_C(   661.00),
        SIMDE_FLOAT32_C(    38.00), SIMDE_FLOAT32_C(  -975.00), SIMDE_FLOAT32_C(   580.00), SIMDE_FLOAT32_C(  -989.00) } },
    { { SIMDE_FLOAT32_C(  -684.35), SIMDE_FLOAT32_C(   -10.18), SIMDE_FLOAT32_C(  -771.27), SIMDE_FLOAT32_C(  -448.98),
        SIMDE_FLOAT32_C(   301.51), SIMDE_FLOAT32_C(   239.71), SIMDE_FLOAT32_C(   730.34), SIMDE_FLOAT32_C(   112.35) },
       INT32_C(          16),
      { SIMDE_FLOAT32_C(  -684.50), SIMDE_FLOAT32_C(   -10.00), SIMDE_FLOAT32_C(  -771.50), SIMDE_FLOAT32_C(  -449.00),
        SIMDE_FLOAT32_C(   301.50), SIMDE_FLOAT32_C(   239.50), SIMDE_FLOAT32_C(   730.50), SIMDE_FLOAT32_C(   112.50) } },
    { { SIMDE_FLOAT32_C(   927.48), SIMDE_FLOAT32_C(  -663.37), SIMDE_FLOAT32_C(  -126.17), SIMDE_FLOAT32_C(   917.27),
        SIMDE_FLOAT32_C(   824.25), SIMDE_FLOAT32_C(  -774.04), SIMDE_FLOAT32_C(   704.40), SIMDE_FLOAT32_C(  -459.07) },
       INT32_C(          32),
      { SIMDE_FLOAT32_C(   927.50), SIMDE_FLOAT32_C(  -663.25), SIMDE_FLOAT32_C(  -126.25), SIMDE_FLOAT32_C(   917.25),
        SIMDE_FLOAT32_C(   824.25), SIMDE_FLOAT32_C(  -774.00), SIMDE_FLOAT32_C(   704.50), SIMDE_FLOAT32_C(  -459.00) } },
    { { SIMDE_FLOAT32_C(  -841.48),      SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(   -22.59), SIMDE_FLOAT32_C(   528.01),
        SIMDE_FLOAT32_C(    -3.94), SIMDE_FLOAT32_C(  -361.30), SIMDE_FLOAT32_C(  -433.59), SIMDE_FLOAT32_C(    21.54) },
       INT32_C(          48),
      { SIMDE_FLOAT32_C(  -841.50),      SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(   -22.62), SIMDE_FLOAT32_C(   528.00),
        SIMDE_FLOAT32_C(    -4.00), SIMDE_FLOAT32_C(  -361.25), SIMDE_FLOAT32_C(  -433.62), SIMDE_FLOAT32_C(    21.50) } },
    { { SIMDE_FLOAT32_C(  -339.97), SIMDE_FLOAT32_C(   658.60), SIMDE_FLOAT32_C(   408.96), SIMDE_FLOAT32_C(   649.85),
        SIMDE_FLOAT32_C(   887.33), SIMDE_FLOAT32_C(   959.98), SIMDE_FLOAT32_C(   -48.64), SIMDE_FLOAT32_C(   127.05) },
       INT32_C(          64),
      { SIMDE_FLOAT32_C(  -340.00), SIMDE_FLOAT32_C(   658.62), SIMDE_FLOAT32_C(   408.94), SIMDE_FLOAT32_C(   649.88),
        SIMDE_FLOAT32_C(   887.31), SIMDE_FLOAT32_C(   960.00), SIMDE_FLOAT32_C(   -48.62), SIMDE_FLOAT32_C(   127.06) } },
    { {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -528.44), SIMDE_FLOAT32_C(   617.81), SIMDE_FLOAT32_C(  -599.66),
        SIMDE_FLOAT32_C(   345.39), SIMDE_FLOAT32_C(   535.08), SIMDE_FLOAT32_C(  -775.41), SIMDE_FLOAT32_C(   571.35) },
       INT32_C(          80),
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -528.44), SIMDE_FLOAT32_C(   617.81), SIMDE_FLOAT32_C(  -599.66),
        SIMDE_FLOAT32_C(   345.38), SIMDE_FLOAT32_C(   535.09), SIMDE_FLOAT32_C(  -775.41), SIMDE_FLOAT32_C(   571.34) } },
    { { SIMDE_FLOAT32_C(  -131.87), SIMDE_FLOAT32_C(   397.99), SIMDE_FLOAT32_C(  -680.39), SIMDE_FLOAT32_C(   845.53),
        SIMDE_FLOAT32_C(   -74.00), SIMDE_FLOAT32_C(   315.67), SIMDE_FLOAT32_C(  -515.77), SIMDE_FLOAT32_C(   492.41) },
       INT32_C(          96),
      { SIMDE_FLOAT32_C(  -131.88), SIMDE_FLOAT32_C(   397.98), SIMDE_FLOAT32_C(  -680.39), SIMDE_FLOAT32_C(   845.53),
        SIMDE_FLOAT32_C(   -74.00), SIMDE_FLOAT32_C(   315.67), SIMDE_FLOAT32_C(  -515.77), SIMDE_FLOAT32_C(   492.41) } },
    { {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -930.49), SIMDE_FLOAT32_C(   430.51), SIMDE_FLOAT32_C(   362.62),
        SIMDE_FLOAT32_C(   728.11), SIMDE_FLOAT32_C(  -160.53), SIMDE_FLOAT32_C(    12.46), SIMDE_FLOAT32_C(   615.44) },
       INT32_C(         112),
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -930.49), SIMDE_FLOAT32_C(   430.51), SIMDE_FLOAT32_C(   362.62),
        SIMDE_FLOAT32_C(   728.11), SIMDE_FLOAT32_C(  -160.53), SIMDE_FLOAT32_C(    12.46), SIMDE_FLOAT32_C(   615.44) } },
    { {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -510.23), SIMDE_FLOAT32_C(  -972.46), SIMDE_FLOAT32_C(   214.05),
        SIMDE_FLOAT32_C(  -892.43), SIMDE_FLOAT32_C(  -572.12), SIMDE_FLOAT32_C(  -440.56), SIMDE_FLOAT32_C(   642.65) },
       INT32_C(         128),
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -510.23), SIMDE_FLOAT32_C(  -972.46), SIMDE_FLOAT32_C(   214.05),
        SIMDE_FLOAT32_C(  -892.43), SIMDE_FLOAT32_C(  -572.12), SIMDE_FLOAT32_C(  -440.56), SIMDE_FLOAT32_C(   642.65) } },
    { { SIMDE_FLOAT32_C(  -117.87), SIMDE_FLOAT32_C(   418.00), SIMDE_FLOAT32_C(    -1.08), SIMDE_FLOAT32_C(  -719.88),
        SIMDE_FLOAT32_C(   737.60), SIMDE_FLOAT32_C(  -155.55), SIMDE_FLOAT32_C(   206.13), SIMDE_FLOAT32_C(    53.27) },
       INT32_C(         144),
      { SIMDE_FLOAT32_C(  -117.87), SIMDE_FLOAT32_C(   418.00), SIMDE_FLOAT32_C(    -1.08), SIMDE_FLOAT32_C(  -719.88),
        SIMDE_FLOAT32_C(   737.60), SIMDE_FLOAT32_C(  -155.55), SIMDE_FLOAT32_C(   206.13), SIMDE_FLOAT32_C(    53.27) } },
    { {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   390.47), SIMDE_FLOAT32_C(  -968.73), SIMDE_FLOAT32_C(  -231.95),
        SIMDE_FLOAT32_C(  -179.02), SIMDE_FLOAT32_C(   393.89), SIMDE_FLOAT32_C(  -503.84), SIMDE_FLOAT32_C(   660.45) },
       INT32_C(         160),
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   390.47), SIMDE_FLOAT32_C(  -968.73), SIMDE_FLOAT32_C(  -231.95),
        SIMDE_FLOAT32_C(  -179.02), SIMDE_FLOAT32_C(   393.89), SIMDE_FLOAT32_C(  -503.84), SIMDE_FLOAT32_C(   660.45) } },
    { { SIMDE_FLOAT32_C(  -540.10), SIMDE_FLOAT32_C(  -629.83), SIMDE_FLOAT32_C(  -145.91), SIMDE_FLOAT32_C(   -50.34),
        SIMDE_FLOAT32_C(  -602.29), SIMDE_FLOAT32_C(  -931.86), SIMDE_FLOAT32_C(    57.24), SIMDE_FLOAT32_C(  -174.41) },
       INT32_C(         176),
      { SIMDE_FLOAT32_C(  -540.10), SIMDE_FLOAT32_C(  -629.83), SIMDE_FLOAT32_C(  -145.91), SIMDE_FLOAT32_C(   -50.34),
        SIMDE_FLOAT32_C(  -602.29), SIMDE_FLOAT32_C(  -931.86), SIMDE_FLOAT32_C(    57.24), SIMDE_FLOAT32_C(  -174.41) } },
    { { SIMDE_FLOAT32_C(  -300.11), SIMDE_FLOAT32_C(   478.06), SIMDE_FLOAT32_C(  -241.63), SIMDE_FLOAT32_C(   582.02),
        SIMDE_FLOAT32_C(  -103.95), SIMDE_FLOAT32_C(   757.29), SIMDE_FLOAT32_C(   862.15), SIMDE_FLOAT32_C(  -366.35) },
       INT32_C(         192),
      { SIMDE_FLOAT32_C(  -300.11), SIMDE_FLOAT32_C(   478.06), SIMDE_FLOAT32_C(  -241.63), SIMDE_FLOAT32_C(   582.02),
        SIMDE_FLOAT32_C(  -103.95), SIMDE_FLOAT32_C(   757.29), SIMDE_FLOAT32_C(   862.15), SIMDE_FLOAT32_C(  -366.35) } },
    { { SIMDE_FLOAT32_C(    68.27), SIMDE_FLOAT32_C(   686.92), SIMDE_FLOAT32_C(   930.42), SIMDE_FLOAT32_C(   766.81),
        SIMDE_FLOAT32_C(    77.39), SIMDE_FLOAT32_C(   961.69), SIMDE_FLOAT32_C(  -465.14), SIMDE_FLOAT32_C(   898.37) },
       INT32_C(         208),
      { SIMDE_FLOAT32_C(    68.27), SIMDE_FLOAT32_C(   686.92), SIMDE_FLOAT32_C(   930.42), SIMDE_FLOAT32_C(   766.81),
        SIMDE_FLOAT32_C(    77.39), SIMDE_FLOAT32_C(   961.69), SIMDE_FLOAT32_C(  -465.14), SIMDE_FLOAT32_C(   898.37) } },
    { { SIMDE_FLOAT32_C(    31.02), SIMDE_FLOAT32_C(   558.82), SIMDE_FLOAT32_C(   761.92), SIMDE_FLOAT32_C(   142.63),
        SIMDE_FLOAT32_C(  -981.28), SIMDE_FLOAT32_C(  -867.91), SIMDE_FLOAT32_C(   996.72), SIMDE_FLOAT32_C(   -31.62) },
       INT32_C(         224),
      { SIMDE_FLOAT32_C(    31.02), SIMDE_FLOAT32_C(   558.82), SIMDE_FLOAT32_C(   761.92), SIMDE_FLOAT32_C(   142.63),
        SIMDE_FLOAT32_C(  -981.28), SIMDE_FLOAT32_C(  -867.91), SIMDE_FLOAT32_C(   996.72), SIMDE_FLOAT32_C(   -31.62) } },
    { { SIMDE_FLOAT32_C(  -935.13),      SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(   355.39), SIMDE_FLOAT32_C(  -307.55),
        SIMDE_FLOAT32_C(  -274.48), SIMDE_FLOAT32_C(  -166.56), SIMDE_FLOAT32_C(   450.82), SIMDE_FLOAT32_C(  -692.46) },
       INT32_C(         240),
      { SIMDE_FLOAT32_C(  -935.13),      SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(   355.39), SIMDE_FLOAT32_C(  -307.55),
        SIMDE_FLOAT32_C(  -274.48), SIMDE_FLOAT32_C(  -166.56), SIMDE_FLOAT32_C(   450.82), SIMDE_FLOAT32_C(  -692.46) } },
    { {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   809.84), SIMDE_FLOAT32_C(   237.96), SIMDE_FLOAT32_C(  -949.93),
        SIMDE_FLOAT32_C(   740.26), SIMDE_FLOAT32_C(     4.77), SIMDE_FLOAT32_C(   127.46), SIMDE_FLOAT32_C(   701.95) },
       INT32_C(           1),
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   809.00), SIMDE_FLOAT32_C(   237.00), SIMDE_FLOAT32_C(  -950.00),
        SIMDE_FLOAT32_C(   740.00), SIMDE_FLOAT32_C(     4.00), SIMDE_FLOAT32_C(   127.00), SIMDE_FLOAT32_C(   701.00) } },
    { { SIMDE_FLOAT32_C(    57.52), SIMDE_FLOAT32_C(  -429.34), SIMDE_FLOAT32_C(  -415.34), SIMDE_FLOAT32_C(  -180.55),
        SIMDE_FLOAT32_C(   713.28), SIMDE_FLOAT32_C(  -396.62), SIMDE_FLOAT32_C(   -48.46), SIMDE_FLOAT32_C(   710.01) },
       INT32_C(          17),
      { SIMDE_FLOAT32_C(    57.50), SIMDE_FLOAT32_C(  -429.50), SIMDE_FLOAT32_C(  -415.50), SIMDE_FLOAT32_C(  -181.00),
        SIMDE_FLOAT32_C(   713.00), SIMDE_FLOAT32_C(  -397.00), SIMDE_FLOAT32_C(   -48.50), SIMDE_FLOAT32_C(   710.00) } },
    { {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   774.87), SIMDE_FLOAT32_C(   597.38), SIMDE_FLOAT32_C(  -163.27),
        SIMDE_FLOAT32_C(  -532.68), SIMDE_FLOAT32_C(  -677.10), SIMDE_FLOAT32_C(   670.17), SIMDE_FLOAT32_C(   918.14) },
       INT32_C(          33),
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   774.75), SIMDE_FLOAT32_C(   597.25), SIMDE_FLOAT32_C(  -163.50),
        SIMDE_FLOAT32_C(  -532.75), SIMDE_FLOAT32_C(  -677.25), SIMDE_FLOAT32_C(   670.00), SIMDE_FLOAT32_C(   918.00) } },
    { { SIMDE_FLOAT32_C(   126.25), SIMDE_FLOAT32_C(  -199.87), SIMDE_FLOAT32_C(   762.81), SIMDE_FLOAT32_C(   -63.91),
        SIMDE_FLOAT32_C(  -961.91), SIMDE_FLOAT32_C(   812.88), SIMDE_FLOAT32_C(  -323.65), SIMDE_FLOAT32_C(    42.86) },
       INT32_C(          49),
      { SIMDE_FLOAT32_C(   126.25), SIMDE_FLOAT32_C(  -199.88), SIMDE_FLOAT32_C(   762.75), SIMDE_FLOAT32_C(   -64.00),
        SIMDE_FLOAT32_C(  -962.00), SIMDE_FLOAT32_C(   812.88), SIMDE_FLOAT32_C(  -323.75), SIMDE_FLOAT32_C(    42.75) } },
    { { SIMDE_FLOAT32_C(  -621.70), SIMDE_FLOAT32_C(  -417.51), SIMDE_FLOAT32_C(   966.17), SIMDE_FLOAT32_C(   435.83),
        SIMDE_FLOAT32_C(   153.15), SIMDE_FLOAT32_C(  -449.17), SIMDE_FLOAT32_C(  -744.73), SIMDE_FLOAT32_C(  -133.57) },
       INT32_C(          65),
      { SIMDE_FLOAT32_C(  -621.75), SIMDE_FLOAT32_C(  -417.56), SIMDE_FLOAT32_C(   966.12), SIMDE_FLOAT32_C(   435.81),
        SIMDE_FLOAT32_C(   153.12), SIMDE_FLOAT32_C(  -449.19), SIMDE_FLOAT32_C(  -744.75), SIMDE_FLOAT32_C(  -133.62) } },
    { {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -423.56), SIMDE_FLOAT32_C(  -274.03), SIMDE_FLOAT32_C(  -311.84),
        SIMDE_FLOAT32_C(  -648.69), SIMDE_FLOAT32_C(  -676.65), SIMDE_FLOAT32_C(   524.89), SIMDE_FLOAT32_C(  -181.37) },
       INT32_C(          81),
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -423.56), SIMDE_FLOAT32_C(  -274.03), SIMDE_FLOAT32_C(  -311.84),
        SIMDE_FLOAT32_C(  -648.72), SIMDE_FLOAT32_C(  -676.66), SIMDE_FLOAT32_C(   524.88), SIMDE_FLOAT32_C(  -181.38) } },
    { {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   276.69), SIMDE_FLOAT32_C(  -405.28), SIMDE_FLOAT32_C(   863.01),
        SIMDE_FLOAT32_C(  -923.18), SIMDE_FLOAT32_C(  -642.46), SIMDE_FLOAT32_C(  -200.90), SIMDE_FLOAT32_C(  -885.09) },
       INT32_C(          97),
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   276.69), SIMDE_FLOAT32_C(  -405.28), SIMDE_FLOAT32_C(   863.00),
        SIMDE_FLOAT32_C(  -923.19), SIMDE_FLOAT32_C(  -642.47), SIMDE_FLOAT32_C(  -200.91), SIMDE_FLOAT32_C(  -885.09) } },
    { { SIMDE_FLOAT32_C(   157.77), SIMDE_FLOAT32_C(   110.75), SIMDE_FLOAT32_C(   853.76), SIMDE_FLOAT32_C(   740.26),
        SIMDE_FLOAT32_C(    76.93), SIMDE_FLOAT32_C(   289.58), SIMDE_FLOAT32_C(  -106.60), SIMDE_FLOAT32_C(   627.76) },
       INT32_C(         113),
      { SIMDE_FLOAT32_C(   157.77), SIMDE_FLOAT32_C(   110.75), SIMDE_FLOAT32_C(   853.76), SIMDE_FLOAT32_C(   740.26),
        SIMDE_FLOAT32_C(    76.93), SIMDE_FLOAT32_C(   289.58), SIMDE_FLOAT32_C(  -106.60), SIMDE_FLOAT32_C(   627.76) } },
    { { SIMDE_FLOAT32_C(   759.84), SIMDE_FLOAT32_C(  -218.03), SIMDE_FLOAT32_C(  -248.33), SIMDE_FLOAT32_C(  -663.72),
        SIMDE_FLOAT32_C(   507.94), SIMDE_FLOAT32_C(   439.83), SIMDE_FLOAT32_C(  -312.42), SIMDE_FLOAT32_C(   831.29) },
       INT32_C(         129),
      { SIMDE_FLOAT32_C(   759.84), SIMDE_FLOAT32_C(  -218.03), SIMDE_FLOAT32_C(  -248.33), SIMDE_FLOAT32_C(  -663.72),
        SIMDE_FLOAT32_C(   507.94), SIMDE_FLOAT32_C(   439.83), SIMDE_FLOAT32_C(  -312.42), SIMDE_FLOAT32_C(   831.29) } },
    { {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -522.46), SIMDE_FLOAT32_C(  -840.22), SIMDE_FLOAT32_C(  -757.02),
        SIMDE_FLOAT32_C(   754.24), SIMDE_FLOAT32_C(  -245.50), SIMDE_FLOAT32_C(  -894.01), SIMDE_FLOAT32_C(   831.06) },
       INT32_C(         145),
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -522.46), SIMDE_FLOAT32_C(  -840.22), SIMDE_FLOAT32_C(  -757.02),
        SIMDE_FLOAT32_C(   754.24), SIMDE_FLOAT32_C(  -245.50), SIMDE_FLOAT32_C(  -894.01), SIMDE_FLOAT32_C(   831.06) } },
    { { SIMDE_FLOAT32_C(   945.97), SIMDE_FLOAT32_C(   282.45), SIMDE_FLOAT32_C(  -619.45), SIMDE_FLOAT32_C(   103.74),
        SIMDE_FLOAT32_C(  -606.79), SIMDE_FLOAT32_C(  -765.70), SIMDE_FLOAT32_C(  -156.01), SIMDE_FLOAT32_C(   470.14) },
       INT32_C(         161),
      { SIMDE_FLOAT32_C(   945.97), SIMDE_FLOAT32_C(   282.45), SIMDE_FLOAT32_C(  -619.45), SIMDE_FLOAT32_C(   103.74),
        SIMDE_FLOAT32_C(  -606.79), SIMDE_FLOAT32_C(  -765.70), SIMDE_FLOAT32_C(  -156.01), SIMDE_FLOAT32_C(   470.14) } },
    { { SIMDE_FLOAT32_C(   737.40), SIMDE_FLOAT32_C(    97.90), SIMDE_FLOAT32_C(    68.75), SIMDE_FLOAT32_C(   497.23),
        SIMDE_FLOAT32_C(   879.86), SIMDE_FLOAT32_C(   820.42), SIMDE_FLOAT32_C(   833.51), SIMDE_FLOAT32_C(   387.80) },
       INT32_C(         177),
      { SIMDE_FLOAT32_C(   737.40), SIMDE_FLOAT32_C(    97.90), SIMDE_FLOAT32_C(    68.75), SIMDE_FLOAT32_C(   497.23),
        SIMDE_FLOAT32_C(   879.86), SIMDE_FLOAT32_C(   820.42), SIMDE_FLOAT32_C(   833.51), SIMDE_FLOAT32_C(   387.80) } },
    { { SIMDE_FLOAT32_C(  -478.91), SIMDE_FLOAT32_C(   219.09), SIMDE_FLOAT32_C(  -775.03), SIMDE_FLOAT32_C(  -972.69),
        SIMDE_FLOAT32_C(   696.63), SIMDE_FLOAT32_C(  -615.25), SIMDE_FLOAT32_C(  -729.71), SIMDE_FLOAT32_C(   450.87) },
       INT32_C(         193),
      { SIMDE_FLOAT32_C(  -478.91), SIMDE_FLOAT32_C(   219.09), SIMDE_FLOAT32_C(  -775.03), SIMDE_FLOAT32_C(  -972.69),
        SIMDE_FLOAT32_C(   696.63), SIMDE_FLOAT32_C(  -615.25), SIMDE_FLOAT32_C(  -729.71), SIMDE_FLOAT32_C(   450.87) } },
    { {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   281.93), SIMDE_FLOAT32_C(  -748.71), SIMDE_FLOAT32_C(   281.37),
        SIMDE_FLOAT32_C(   227.90), SIMDE_FLOAT32_C(   533.74), SIMDE_FLOAT32_C(   661.92), SIMDE_FLOAT32_C(  -668.36) },
       INT32_C(         209),
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   281.93), SIMDE_FLOAT32_C(  -748.71), SIMDE_FLOAT32_C(   281.37),
        SIMDE_FLOAT32_C(   227.90), SIMDE_FLOAT32_C(   533.74), SIMDE_FLOAT32_C(   661.92), SIMDE_FLOAT32_C(  -668.36) } },
    { {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   397.08), SIMDE_FLOAT32_C(   420.11), SIMDE_FLOAT32_C(   -86.97),
        SIMDE_FLOAT32_C(  -505.02), SIMDE_FLOAT32_C(  -511.14), SIMDE_FLOAT32_C(  -589.74), SIMDE_FLOAT32_C(  -625.15) },
       INT32_C(         225),
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   397.08), SIMDE_FLOAT32_C(   420.11), SIMDE_FLOAT32_C(   -86.97),
        SIMDE_FLOAT32_C(  -505.02), SIMDE_FLOAT32_C(  -511.14), SIMDE_FLOAT32_C(  -589.74), SIMDE_FLOAT32_C(  -625.15) } },
    { { SIMDE_FLOAT32_C(   762.65),     -SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(  -235.14), SIMDE_FLOAT32_C(   -18.26),
        SIMDE_FLOAT32_C(   794.49), SIMDE_FLOAT32_C(  -207.83), SIMDE_FLOAT32_C(  -321.63), SIMDE_FLOAT32_C(  -820.76) },
       INT32_C(         241),
      { SIMDE_FLOAT32_C(   762.65),     -SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(  -235.14), SIMDE_FLOAT32_C(   -18.26),
        SIMDE_FLOAT32_C(   794.49), SIMDE_FLOAT32_C(  -207.83), SIMDE_FLOAT32_C(  -321.63), SIMDE_FLOAT32_C(  -820.76) } },
    { { SIMDE_FLOAT32_C(   438.74),      SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(   569.77), SIMDE_FLOAT32_C(  -279.89),
        SIMDE_FLOAT32_C(  -360.93), SIMDE_FLOAT32_C(   103.51), SIMDE_FLOAT32_C(  -617.97), SIMDE_FLOAT32_C(   -29.30) },
       INT32_C(           2),
      { SIMDE_FLOAT32_C(   439.00),      SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(   570.00), SIMDE_FLOAT32_C(  -279.00),
        SIMDE_FLOAT32_C(  -360.00), SIMDE_FLOAT32_C(   104.00), SIMDE_FLOAT32_C(  -617.00), SIMDE_FLOAT32_C(   -29.00) } },
    { {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   698.37), SIMDE_FLOAT32_C(    59.36), SIMDE_FLOAT32_C(   -77.47),
        SIMDE_FLOAT32_C(  -812.77), SIMDE_FLOAT32_C(   469.62), SIMDE_FLOAT32_C(   297.37), SIMDE_FLOAT32_C(  -503.49) },
       INT32_C(          18),
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   698.50), SIMDE_FLOAT32_C(    59.50), SIMDE_FLOAT32_C(   -77.00),
        SIMDE_FLOAT32_C(  -812.50), SIMDE_FLOAT32_C(   470.00), SIMDE_FLOAT32_C(   297.50), SIMDE_FLOAT32_C(  -503.00) } },
    { { SIMDE_FLOAT32_C(  -933.97),     -SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(  -958.24), SIMDE_FLOAT32_C(   860.53),
        SIMDE_FLOAT32_C(   270.43), SIMDE_FLOAT32_C(  -279.88), SIMDE_FLOAT32_C(  -960.23), SIMDE_FLOAT32_C(  -667.11) },
       INT32_C(          34),
      { SIMDE_FLOAT32_C(  -933.75),     -SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(  -958.00), SIMDE_FLOAT32_C(   860.75),
        SIMDE_FLOAT32_C(   270.50), SIMDE_FLOAT32_C(  -279.75), SIMDE_FLOAT32_C(  -960.00), SIMDE_FLOAT32_C(  -667.00) } },
    { { SIMDE_FLOAT32_C(  -739.47),     -SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(  -508.26), SIMDE_FLOAT32_C(  -100.40),
        SIMDE_FLOAT32_C(  -968.46), SIMDE_FLOAT32_C(  -126.23), SIMDE_FLOAT32_C(   870.30), SIMDE_FLOAT32_C(    62.01) },
       INT32_C(          50),
      { SIMDE_FLOAT32_C(  -739.38),     -SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(  -508.25), SIMDE_FLOAT32_C(  -100.38),
        SIMDE_FLOAT32_C(  -968.38), SIMDE_FLOAT32_C(  -126.12), SIMDE_FLOAT32_C(   870.38), SIMDE_FLOAT32_C(    62.12) } },
    { { SIMDE_FLOAT32_C(  -149.60), SIMDE_FLOAT32_C(    75.99), SIMDE_FLOAT32_C(  -587.92), SIMDE_FLOAT32_C(    37.62),
        SIMDE_FLOAT32_C(  -454.39), SIMDE_FLOAT32_C(   709.46), SIMDE_FLOAT32_C(   534.13), SIMDE_FLOAT32_C(  -741.00) },
       INT32_C(          66),
      { SIMDE_FLOAT32_C(  -149.56), SIMDE_FLOAT32_C(    76.00), SIMDE_FLOAT32_C(  -587.88), SIMDE_FLOAT32_C(    37.62),
        SIMDE_FLOAT32_C(  -454.38), SIMDE_FLOAT32_C(   709.50), SIMDE_FLOAT32_C(   534.19), SIMDE_FLOAT32_C(  -741.00) } },
    { {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -262.74), SIMDE_FLOAT32_C(  -188.77), SIMDE_FLOAT32_C(   460.69),
        SIMDE_FLOAT32_C(  -992.31), SIMDE_FLOAT32_C(   531.36), SIMDE_FLOAT32_C(   500.46), SIMDE_FLOAT32_C(  -659.43) },
       INT32_C(          82),
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -262.72), SIMDE_FLOAT32_C(  -188.75), SIMDE_FLOAT32_C(   460.72),
        SIMDE_FLOAT32_C(  -992.28), SIMDE_FLOAT32_C(   531.38), SIMDE_FLOAT32_C(   500.47), SIMDE_FLOAT32_C(  -659.41) } },
    { {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -358.75), SIMDE_FLOAT32_C(   786.75), SIMDE_FLOAT32_C(  -396.06),
        SIMDE_FLOAT32_C(   540.85), SIMDE_FLOAT32_C(   818.29), SIMDE_FLOAT32_C(   477.71), SIMDE_FLOAT32_C(   411.15) },
       INT32_C(          98),
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -358.75), SIMDE_FLOAT32_C(   786.75), SIMDE_FLOAT32_C(  -396.05),
        SIMDE_FLOAT32_C(   540.86), SIMDE_FLOAT32_C(   818.30), SIMDE_FLOAT32_C(   477.72), SIMDE_FLOAT32_C(   411.16) } },
    { { SIMDE_FLOAT32_C(   427.78), SIMDE_FLOAT32_C(  -630.14), SIMDE_FLOAT32_C(   480.13), SIMDE_FLOAT32_C(  -496.23),
        SIMDE_FLOAT32_C(  -218.06), SIMDE_FLOAT32_C(  -482.24), SIMDE_FLOAT32_C(    49.39), SIMDE_FLOAT32_C(  -508.60) },
       INT32_C(         114),
      { SIMDE_FLOAT32_C(   427.78), SIMDE_FLOAT32_C(  -630.13), SIMDE_FLOAT32_C(   480.13), SIMDE_FLOAT32_C(  -496.23),
        SIMDE_FLOAT32_C(  -218.05), SIMDE_FLOAT32_C(  -482.23), SIMDE_FLOAT32_C(    49.39), SIMDE_FLOAT32_C(  -508.59) } },
    { {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   260.88), SIMDE_FLOAT32_C(   652.05), SIMDE_FLOAT32_C(  -954.35),
        SIMDE_FLOAT32_C(  -927.89), SIMDE_FLOAT32_C(   112.74), SIMDE_FLOAT32_C(  -946.67), SIMDE_FLOAT32_C(   603.47) },
       INT32_C(         130),
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   260.88), SIMDE_FLOAT32_C(   652.05), SIMDE_FLOAT32_C(  -954.35),
        SIMDE_FLOAT32_C(  -927.89), SIMDE_FLOAT32_C(   112.74), SIMDE_FLOAT32_C(  -946.67), SIMDE_FLOAT32_C(   603.47) } },
    { { SIMDE_FLOAT32_C(   984.19), SIMDE_FLOAT32_C(   471.92), SIMDE_FLOAT32_C(  -493.89), SIMDE_FLOAT32_C(  -374.56),
        SIMDE_FLOAT32_C(   258.67), SIMDE_FLOAT32_C(   110.05), SIMDE_FLOAT32_C(  -833.71), SIMDE_FLOAT32_C(    76.97) },
       INT32_C(         146),
      { SIMDE_FLOAT32_C(   984.19), SIMDE_FLOAT32_C(   471.92), SIMDE_FLOAT32_C(  -493.89), SIMDE_FLOAT32_C(  -374.56),
        SIMDE_FLOAT32_C(   258.67), SIMDE_FLOAT32_C(   110.05), SIMDE_FLOAT32_C(  -833.71), SIMDE_FLOAT32_C(    76.97) } },
    { { SIMDE_FLOAT32_C(   577.43),      SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(   217.49), SIMDE_FLOAT32_C(     5.21),
        SIMDE_FLOAT32_C(  -672.88), SIMDE_FLOAT32_C(  -302.38), SIMDE_FLOAT32_C(   508.99), SIMDE_FLOAT32_C(   109.06) },
       INT32_C(         162),
      { SIMDE_FLOAT32_C(   577.43),      SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(   217.49), SIMDE_FLOAT32_C(     5.21),
        SIMDE_FLOAT32_C(  -672.88), SIMDE_FLOAT32_C(  -302.38), SIMDE_FLOAT32_C(   508.99), SIMDE_FLOAT32_C(   109.06) } },
    { {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   866.76), SIMDE_FLOAT32_C(  -138.66), SIMDE_FLOAT32_C(   -80.68),
        SIMDE_FLOAT32_C(   912.41), SIMDE_FLOAT32_C(   -66.55), SIMDE_FLOAT32_C(  -967.94), SIMDE_FLOAT32_C(   965.74) },
       INT32_C(         178),
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   866.76), SIMDE_FLOAT32_C(  -138.66), SIMDE_FLOAT32_C(   -80.68),
        SIMDE_FLOAT32_C(   912.41), SIMDE_FLOAT32_C(   -66.55), SIMDE_FLOAT32_C(  -967.94), SIMDE_FLOAT32_C(   965.74) } },
    { { SIMDE_FLOAT32_C(  -640.35),     -SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(  -882.80), SIMDE_FLOAT32_C(  -134.25),
        SIMDE_FLOAT32_C(   146.55), SIMDE_FLOAT32_C(   375.87), SIMDE_FLOAT32_C(   975.80), SIMDE_FLOAT32_C(   312.84) },
       INT32_C(         194),
      { SIMDE_FLOAT32_C(  -640.35),     -SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(  -882.80), SIMDE_FLOAT32_C(  -134.25),
        SIMDE_FLOAT32_C(   146.55), SIMDE_FLOAT32_C(   375.87), SIMDE_FLOAT32_C(   975.80), SIMDE_FLOAT32_C(   312.84) } },
    { {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   781.05), SIMDE_FLOAT32_C(   895.48), SIMDE_FLOAT32_C(  -262.78),
        SIMDE_FLOAT32_C(  -521.33), SIMDE_FLOAT32_C(   404.47), SIMDE_FLOAT32_C(   846.28), SIMDE_FLOAT32_C(   694.05) },
       INT32_C(         210),
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   781.05), SIMDE_FLOAT32_C(   895.48), SIMDE_FLOAT32_C(  -262.78),
        SIMDE_FLOAT32_C(  -521.33), SIMDE_FLOAT32_C(   404.47), SIMDE_FLOAT32_C(   846.28), SIMDE_FLOAT32_C(   694.05) } },
    { {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   829.61), SIMDE_FLOAT32_C(  -691.92), SIMDE_FLOAT32_C(   880.64),
        SIMDE_FLOAT32_C(   742.02), SIMDE_FLOAT32_C(   241.53), SIMDE_FLOAT32_C(   912.71), SIMDE_FLOAT32_C(   707.76) },
       INT32_C(         226),
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   829.61), SIMDE_FLOAT32_C(  -691.92), SIMDE_FLOAT32_C(   880.64),
        SIMDE_FLOAT32_C(   742.02), SIMDE_FLOAT32_C(   241.53), SIMDE_FLOAT32_C(   912.71), SIMDE_FLOAT32_C(   707.76) } },
    { {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -700.45), SIMDE_FLOAT32_C(  -324.83), SIMDE_FLOAT32_C(   -66.85),
        SIMDE_FLOAT32_C(   446.10), SIMDE_FLOAT32_C(  -948.96), SIMDE_FLOAT32_C(   -91.05), SIMDE_FLOAT32_C(  -241.06) },
       INT32_C(         242),
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -700.45), SIMDE_FLOAT32_C(  -324.83), SIMDE_FLOAT32_C(   -66.85),
        SIMDE_FLOAT32_C(   446.10), SIMDE_FLOAT32_C(  -948.96), SIMDE_FLOAT32_C(   -91.05), SIMDE_FLOAT32_C(  -241.06) } },
    { { SIMDE_FLOAT32_C(   649.21), SIMDE_FLOAT32_C(   -86.03), SIMDE_FLOAT32_C(   253.56), SIMDE_FLOAT32_C(   544.69),
        SIMDE_FLOAT32_C(   651.19), SIMDE_FLOAT32_C(   732.23), SIMDE_FLOAT32_C(   -50.84), SIMDE_FLOAT32_C(   497.48) },
       INT32_C(           3),
      { SIMDE_FLOAT32_C(   649.00), SIMDE_FLOAT32_C(   -86.00), SIMDE_FLOAT32_C(   253.00), SIMDE_FLOAT32_C(   544.00),
        SIMDE_FLOAT32_C(   651.00), SIMDE_FLOAT32_C(   732.00), SIMDE_FLOAT32_C(   -50.00), SIMDE_FLOAT32_C(   497.00) } },
    { { SIMDE_FLOAT32_C(   -87.99), SIMDE_FLOAT32_C(   -55.78), SIMDE_FLOAT32_C(  -612.39), SIMDE_FLOAT32_C(  -258.38),
        SIMDE_FLOAT32_C(   252.30), SIMDE_FLOAT32_C(  -731.75), SIMDE_FLOAT32_C(  -516.36), SIMDE_FLOAT32_C(  -506.18) },
       INT32_C(          19),
      { SIMDE_FLOAT32_C(   -87.50), SIMDE_FLOAT32_C(   -55.50), SIMDE_FLOAT32_C(  -612.00), SIMDE_FLOAT32_C(  -258.00),
        SIMDE_FLOAT32_C(   252.00), SIMDE_FLOAT32_C(  -731.50), SIMDE_FLOAT32_C(  -516.00), SIMDE_FLOAT32_C(  -506.00) } },
    { { SIMDE_FLOAT32_C(  -808.61), SIMDE_FLOAT32_C(  -727.73), SIMDE_FLOAT32_C(  -261.07), SIMDE_FLOAT32_C(  -741.21),
        SIMDE_FLOAT32_C(  -428.18), SIMDE_FLOAT32_C(   414.11), SIMDE_FLOAT32_C(   191.95), SIMDE_FLOAT32_C(  -982.08) },
       INT32_C(          35),
      { SIMDE_FLOAT32_C(  -808.50), SIMDE_FLOAT32_C(  -727.50), SIMDE_FLOAT32_C(  -261.00), SIMDE_FLOAT32_C(  -741.00),
        SIMDE_FLOAT32_C(  -428.00), SIMDE_FLOAT32_C(   414.00), SIMDE_FLOAT32_C(   191.75), SIMDE_FLOAT32_C(  -982.00) } },
    { { SIMDE_FLOAT32_C(  -899.10),     -SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(   969.02), SIMDE_FLOAT32_C(   573.41),
        SIMDE_FLOAT32_C(  -573.94), SIMDE_FLOAT32_C(  -117.01), SIMDE_FLOAT32_C(  -173.03), SIMDE_FLOAT32_C(   970.75) },
       INT32_C(          51),
      { SIMDE_FLOAT32_C(  -899.00),     -SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(   969.00), SIMDE_FLOAT32_C(   573.38),
        SIMDE_FLOAT32_C(  -573.88), SIMDE_FLOAT32_C(  -117.00), SIMDE_FLOAT32_C(  -173.00), SIMDE_FLOAT32_C(   970.75) } },
    { { SIMDE_FLOAT32_C(  -968.33),      SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(   831.93), SIMDE_FLOAT32_C(   -24.11),
        SIMDE_FLOAT32_C(  -626.91), SIMDE_FLOAT32_C(  -426.45), SIMDE_FLOAT32_C(  -771.82), SIMDE_FLOAT32_C(  -358.66) },
       INT32_C(          67),
      { SIMDE_FLOAT32_C(  -968.31),      SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(   831.88), SIMDE_FLOAT32_C(   -24.06),
        SIMDE_FLOAT32_C(  -626.88), SIMDE_FLOAT32_C(  -426.44), SIMDE_FLOAT32_C(  -771.81), SIMDE_FLOAT32_C(  -358.62) } },
    { {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(    -5.73), SIMDE_FLOAT32_C(   561.23), SIMDE_FLOAT32_C(   507.37),
        SIMDE_FLOAT32_C(   566.09), SIMDE_FLOAT32_C(   -24.66), SIMDE_FLOAT32_C(  -300.68), SIMDE_FLOAT32_C(   584.01) },
       INT32_C(          83),
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(    -5.72), SIMDE_FLOAT32_C(   561.22), SIMDE_FLOAT32_C(   507.34),
        SIMDE_FLOAT32_C(   566.06), SIMDE_FLOAT32_C(   -24.66), SIMDE_FLOAT32_C(  -300.66), SIMDE_FLOAT32_C(   584.00) } },
    { { SIMDE_FLOAT32_C(  -639.13), SIMDE_FLOAT32_C(  -590.50), SIMDE_FLOAT32_C(  -626.37), SIMDE_FLOAT32_C(  -213.07),
        SIMDE_FLOAT32_C(   292.50), SIMDE_FLOAT32_C(   200.60), SIMDE_FLOAT32_C(  -242.32), SIMDE_FLOAT32_C(   826.69) },
       INT32_C(          99),
      { SIMDE_FLOAT32_C(  -639.12), SIMDE_FLOAT32_C(  -590.50), SIMDE_FLOAT32_C(  -626.36), SIMDE_FLOAT32_C(  -213.06),
        SIMDE_FLOAT32_C(   292.50), SIMDE_FLOAT32_C(   200.59), SIMDE_FLOAT32_C(  -242.31), SIMDE_FLOAT32_C(   826.69) } },
    { { SIMDE_FLOAT32_C(   677.60),     -SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(   745.29), SIMDE_FLOAT32_C(   509.53),
        SIMDE_FLOAT32_C(  -165.76), SIMDE_FLOAT32_C(  -881.62), SIMDE_FLOAT32_C(  -916.92), SIMDE_FLOAT32_C(    62.43) },
       INT32_C(         115),
      { SIMDE_FLOAT32_C(   677.59),     -SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(   745.29), SIMDE_FLOAT32_C(   509.52),
        SIMDE_FLOAT32_C(  -165.76), SIMDE_FLOAT32_C(  -881.62), SIMDE_FLOAT32_C(  -916.91), SIMDE_FLOAT32_C(    62.43) } },
    { {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -611.15), SIMDE_FLOAT32_C(  -221.29), SIMDE_FLOAT32_C(   143.25),
        SIMDE_FLOAT32_C(   896.22), SIMDE_FLOAT32_C(  -655.20), SIMDE_FLOAT32_C(  -881.42), SIMDE_FLOAT32_C(  -404.46) },
       INT32_C(         131),
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -611.15), SIMDE_FLOAT32_C(  -221.29), SIMDE_FLOAT32_C(   143.25),
        SIMDE_FLOAT32_C(   896.22), SIMDE_FLOAT32_C(  -655.20), SIMDE_FLOAT32_C(  -881.42), SIMDE_FLOAT32_C(  -404.46) } },
    { { SIMDE_FLOAT32_C(   395.76), SIMDE_FLOAT32_C(  -710.33), SIMDE_FLOAT32_C(   -31.43), SIMDE_FLOAT32_C(   769.40),
        SIMDE_FLOAT32_C(    76.60), SIMDE_FLOAT32_C(  -738.93), SIMDE_FLOAT32_C(   -30.00), SIMDE_FLOAT32_C(   834.28) },
       INT32_C(         147),
      { SIMDE_FLOAT32_C(   395.76), SIMDE_FLOAT32_C(  -710.33), SIMDE_FLOAT32_C(   -31.43), SIMDE_FLOAT32_C(   769.40),
        SIMDE_FLOAT32_C(    76.60), SIMDE_FLOAT32_C(  -738.93), SIMDE_FLOAT32_C(   -30.00), SIMDE_FLOAT32_C(   834.28) } },
    { {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   511.89), SIMDE_FLOAT32_C(   946.11), SIMDE_FLOAT32_C(  -524.91),
        SIMDE_FLOAT32_C(    21.42), SIMDE_FLOAT32_C(  -219.65), SIMDE_FLOAT32_C(  -406.54), SIMDE_FLOAT32_C(   104.50) },
       INT32_C(         163),
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   511.89), SIMDE_FLOAT32_C(   946.11), SIMDE_FLOAT32_C(  -524.91),
        SIMDE_FLOAT32_C(    21.42), SIMDE_FLOAT32_C(  -219.65), SIMDE_FLOAT32_C(  -406.54), SIMDE_FLOAT32_C(   104.50) } },
    { { SIMDE_FLOAT32_C(  -755.23),     -SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(   -64.80), SIMDE_FLOAT32_C(  -366.38),
        SIMDE_FLOAT32_C(  -594.08), SIMDE_FLOAT32_C(  -921.55), SIMDE_FLOAT32_C(  -470.17), SIMDE_FLOAT32_C(  -249.28) },
       INT32_C(         179),
      { SIMDE_FLOAT32_C(  -755.23),     -SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(   -64.80), SIMDE_FLOAT32_C(  -366.38),
        SIMDE_FLOAT32_C(  -594.08), SIMDE_FLOAT32_C(  -921.55), SIMDE_FLOAT32_C(  -470.17), SIMDE_FLOAT32_C(  -249.28) } },
    { { SIMDE_FLOAT32_C(  -243.91), SIMDE_FLOAT32_C(  -478.87), SIMDE_FLOAT32_C(   -30.80), SIMDE_FLOAT32_C(   724.66),
        SIMDE_FLOAT32_C(  -709.47), SIMDE_FLOAT32_C(  -954.20), SIMDE_FLOAT32_C(   985.72), SIMDE_FLOAT32_C(   260.53) },
       INT32_C(         195),
      { SIMDE_FLOAT32_C(  -243.91), SIMDE_FLOAT32_C(  -478.87), SIMDE_FLOAT32_C(   -30.80), SIMDE_FLOAT32_C(   724.66),
        SIMDE_FLOAT32_C(  -709.47), SIMDE_FLOAT32_C(  -954.20), SIMDE_FLOAT32_C(   985.72), SIMDE_FLOAT32_C(   260.53) } },
    { { SIMDE_FLOAT32_C(  -926.52),      SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(   391.97), SIMDE_FLOAT32_C(  -980.41),
        SIMDE_FLOAT32_C(  -534.59), SIMDE_FLOAT32_C(  -586.61), SIMDE_FLOAT32_C(  -200.06), SIMDE_FLOAT32_C(    58.88) },
       INT32_C(         211),
      { SIMDE_FLOAT32_C(  -926.52),      SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(   391.97), SIMDE_FLOAT32_C(  -980.41),
        SIMDE_FLOAT32_C(  -534.59), SIMDE_FLOAT32_C(  -586.61), SIMDE_FLOAT32_C(  -200.06), SIMDE_FLOAT32_C(    58.88) } },
    { { SIMDE_FLOAT32_C(   762.66),     -SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(   347.26), SIMDE_FLOAT32_C(  -603.73),
        SIMDE_FLOAT32_C(  -324.15), SIMDE_FLOAT32_C(   425.71), SIMDE_FLOAT32_C(   -73.89), SIMDE_FLOAT32_C(   426.56) },
       INT32_C(         227),
      { SIMDE_FLOAT32_C(   762.66),     -SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(   347.26), SIMDE_FLOAT32_C(  -603.73),
        SIMDE_FLOAT32_C(  -324.15), SIMDE_FLOAT32_C(   425.71), SIMDE_FLOAT32_C(   -73.89), SIMDE_FLOAT32_C(   426.56) } },
    { { SIMDE_FLOAT32_C(  -621.18),     -SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(    75.29), SIMDE_FLOAT32_C(  -896.52),
        SIMDE_FLOAT32_C(  -136.85), SIMDE_FLOAT32_C(   121.09), SIMDE_FLOAT32_C(  -910.79), SIMDE_FLOAT32_C(  -876.32) },
       INT32_C(         243),
      { SIMDE_FLOAT32_C(  -621.18),     -SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(    75.29), SIMDE_FLOAT32_C(  -896.52),
        SIMDE_FLOAT32_C(  -136.85), SIMDE_FLOAT32_C(   121.09), SIMDE_FLOAT32_C(  -910.79), SIMDE_FLOAT32_C(  -876.32) } },
    { { SIMDE_FLOAT32_C(  -606.86), SIMDE_FLOAT32_C(  -817.73), SIMDE_FLOAT32_C(  -420.58), SIMDE_FLOAT32_C(  -193.47),
        SIMDE_FLOAT32_C(   -17.79), SIMDE_FLOAT32_C(   638.30), SIMDE_FLOAT32_C(  -675.58), SIMDE_FLOAT32_C(   624.93) },
       INT32_C(           4),
      { SIMDE_FLOAT32_C(  -607.00), SIMDE_FLOAT32_C(  -818.00), SIMDE_FLOAT32_C(  -421.00), SIMDE_FLOAT32_C(  -193.00),
        SIMDE_FLOAT32_C(   -18.00), SIMDE_FLOAT32_C(   638.00), SIMDE_FLOAT32_C(  -676.00), SIMDE_FLOAT32_C(   625.00) } },
    { {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   894.86), SIMDE_FLOAT32_C(   397.62), SIMDE_FLOAT32_C(  -516.64),
        SIMDE_FLOAT32_C(  -429.29), SIMDE_FLOAT32_C(  -176.67), SIMDE_FLOAT32_C(   409.46), SIMDE_FLOAT32_C(   997.28) },
       INT32_C(          20),
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   895.00), SIMDE_FLOAT32_C(   397.50), SIMDE_FLOAT32_C(  -516.50),
        SIMDE_FLOAT32_C(  -429.50), SIMDE_FLOAT32_C(  -176.50), SIMDE_FLOAT32_C(   409.50), SIMDE_FLOAT32_C(   997.50) } },
    { {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -175.11), SIMDE_FLOAT32_C(  -966.44), SIMDE_FLOAT32_C(   178.65),
        SIMDE_FLOAT32_C(   -71.63), SIMDE_FLOAT32_C(  -103.29), SIMDE_FLOAT32_C(  -700.26), SIMDE_FLOAT32_C(    17.58) },
       INT32_C(          36),
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -175.00), SIMDE_FLOAT32_C(  -966.50), SIMDE_FLOAT32_C(   178.75),
        SIMDE_FLOAT32_C(   -71.75), SIMDE_FLOAT32_C(  -103.25), SIMDE_FLOAT32_C(  -700.25), SIMDE_FLOAT32_C(    17.50) } },
    { { SIMDE_FLOAT32_C(   180.26), SIMDE_FLOAT32_C(   134.39), SIMDE_FLOAT32_C(   694.05), SIMDE_FLOAT32_C(   362.54),
        SIMDE_FLOAT32_C(   713.81), SIMDE_FLOAT32_C(  -499.42), SIMDE_FLOAT32_C(  -655.25), SIMDE_FLOAT32_C(   352.11) },
       INT32_C(          52),
      { SIMDE_FLOAT32_C(   180.25), SIMDE_FLOAT32_C(   134.38), SIMDE_FLOAT32_C(   694.00), SIMDE_FLOAT32_C(   362.50),
        SIMDE_FLOAT32_C(   713.75), SIMDE_FLOAT32_C(  -499.38), SIMDE_FLOAT32_C(  -655.25), SIMDE_FLOAT32_C(   352.12) } },
    { {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   402.47), SIMDE_FLOAT32_C(   -87.92), SIMDE_FLOAT32_C(   864.55),
        SIMDE_FLOAT32_C(  -199.91), SIMDE_FLOAT32_C(   395.44), SIMDE_FLOAT32_C(  -564.74), SIMDE_FLOAT32_C(   623.43) },
       INT32_C(          68),
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   402.50), SIMDE_FLOAT32_C(   -87.94), SIMDE_FLOAT32_C(   864.56),
        SIMDE_FLOAT32_C(  -199.94), SIMDE_FLOAT32_C(   395.44), SIMDE_FLOAT32_C(  -564.75), SIMDE_FLOAT32_C(   623.44) } },
    { {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -734.15), SIMDE_FLOAT32_C(  -464.09), SIMDE_FLOAT32_C(  -105.62),
        SIMDE_FLOAT32_C(  -700.59), SIMDE_FLOAT32_C(   714.56), SIMDE_FLOAT32_C(   822.76), SIMDE_FLOAT32_C(   196.12) },
       INT32_C(          84),
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -734.16), SIMDE_FLOAT32_C(  -464.09), SIMDE_FLOAT32_C(  -105.62),
        SIMDE_FLOAT32_C(  -700.59), SIMDE_FLOAT32_C(   714.56), SIMDE_FLOAT32_C(   822.75), SIMDE_FLOAT32_C(   196.12) } },
    { { SIMDE_FLOAT32_C(  -783.49),     -SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(  -979.40), SIMDE_FLOAT32_C(   350.90),
        SIMDE_FLOAT32_C(     9.25), SIMDE_FLOAT32_C(   383.13), SIMDE_FLOAT32_C(    64.71), SIMDE_FLOAT32_C(   509.83) },
       INT32_C(         100),
      { SIMDE_FLOAT32_C(  -783.48),     -SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(  -979.41), SIMDE_FLOAT32_C(   350.91),
        SIMDE_FLOAT32_C(     9.25), SIMDE_FLOAT32_C(   383.12), SIMDE_FLOAT32_C(    64.70), SIMDE_FLOAT32_C(   509.83) } },
    { { SIMDE_FLOAT32_C(   697.57), SIMDE_FLOAT32_C(   819.29), SIMDE_FLOAT32_C(   246.92), SIMDE_FLOAT32_C(   562.12),
        SIMDE_FLOAT32_C(  -380.62), SIMDE_FLOAT32_C(  -357.64), SIMDE_FLOAT32_C(   997.38), SIMDE_FLOAT32_C(  -757.19) },
       INT32_C(         116),
      { SIMDE_FLOAT32_C(   697.57), SIMDE_FLOAT32_C(   819.29), SIMDE_FLOAT32_C(   246.92), SIMDE_FLOAT32_C(   562.12),
        SIMDE_FLOAT32_C(  -380.62), SIMDE_FLOAT32_C(  -357.64), SIMDE_FLOAT32_C(   997.38), SIMDE_FLOAT32_C(  -757.19) } },
    { { SIMDE_FLOAT32_C(  -570.08), SIMDE_FLOAT32_C(  -687.70), SIMDE_FLOAT32_C(   713.11), SIMDE_FLOAT32_C(   -34.18),
        SIMDE_FLOAT32_C(   206.68), SIMDE_FLOAT32_C(  -987.48), SIMDE_FLOAT32_C(  -319.62), SIMDE_FLOAT32_C(    29.44) },
       INT32_C(         132),
      { SIMDE_FLOAT32_C(  -570.08), SIMDE_FLOAT32_C(  -687.70), SIMDE_FLOAT32_C(   713.11), SIMDE_FLOAT32_C(   -34.18),
        SIMDE_FLOAT32_C(   206.68), SIMDE_FLOAT32_C(  -987.48), SIMDE_FLOAT32_C(  -319.62), SIMDE_FLOAT32_C(    29.44) } },
    { { SIMDE_FLOAT32_C(  -305.32), SIMDE_FLOAT32_C(   869.78), SIMDE_FLOAT32_C(   425.14), SIMDE_FLOAT32_C(  -990.12),
        SIMDE_FLOAT32_C(   890.37), SIMDE_FLOAT32_C(  -223.96), SIMDE_FLOAT32_C(    19.13), SIMDE_FLOAT32_C(   273.51) },
       INT32_C(         148),
      { SIMDE_FLOAT32_C(  -305.32), SIMDE_FLOAT32_C(   869.78), SIMDE_FLOAT32_C(   425.14), SIMDE_FLOAT32_C(  -990.12),
        SIMDE_FLOAT32_C(   890.37), SIMDE_FLOAT32_C(  -223.96), SIMDE_FLOAT32_C(    19.13), SIMDE_FLOAT32_C(   273.51) } },
    { {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(     1.39), SIMDE_FLOAT32_C(  -742.43), SIMDE_FLOAT32_C(  -136.20),
        SIMDE_FLOAT32_C(  -301.04), SIMDE_FLOAT32_C(  -923.15), SIMDE_FLOAT32_C(  -889.28), SIMDE_FLOAT32_C(  -738.92) },
       INT32_C(         164),
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(     1.39), SIMDE_FLOAT32_C(  -742.43), SIMDE_FLOAT32_C(  -136.20),
        SIMDE_FLOAT32_C(  -301.04), SIMDE_FLOAT32_C(  -923.15), SIMDE_FLOAT32_C(  -889.28), SIMDE_FLOAT32_C(  -738.92) } },
    { { SIMDE_FLOAT32_C(  -741.54), SIMDE_FLOAT32_C(   -60.96), SIMDE_FLOAT32_C(  -799.67), SIMDE_FLOAT32_C(  -311.62),
        SIMDE_FLOAT32_C(   251.34), SIMDE_FLOAT32_C(   913.44), SIMDE_FLOAT32_C(   654.20), SIMDE_FLOAT32_C(  -541.98) },
       INT32_C(         180),
      { SIMDE_FLOAT32_C(  -741.54), SIMDE_FLOAT32_C(   -60.96), SIMDE_FLOAT32_C(  -799.67), SIMDE_FLOAT32_C(  -311.62),
        SIMDE_FLOAT32_C(   251.34), SIMDE_FLOAT32_C(   913.44), SIMDE_FLOAT32_C(   654.20), SIMDE_FLOAT32_C(  -541.98) } },
    { { SIMDE_FLOAT32_C(  -665.42), SIMDE_FLOAT32_C(   487.46), SIMDE_FLOAT32_C(   134.59), SIMDE_FLOAT32_C(    29.26),
        SIMDE_FLOAT32_C(   357.24), SIMDE_FLOAT32_C(  -440.26), SIMDE_FLOAT32_C(    39.14), SIMDE_FLOAT32_C(   247.61) },
       INT32_C(         196),
      { SIMDE_FLOAT32_C(  -665.42), SIMDE_FLOAT32_C(   487.46), SIMDE_FLOAT32_C(   134.59), SIMDE_FLOAT32_C(    29.26),
        SIMDE_FLOAT32_C(   357.24), SIMDE_FLOAT32_C(  -440.26), SIMDE_FLOAT32_C(    39.14), SIMDE_FLOAT32_C(   247.61) } },
    { { SIMDE_FLOAT32_C(  -941.73),     -SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(   176.53), SIMDE_FLOAT32_C(  -412.77),
        SIMDE_FLOAT32_C(   522.52), SIMDE_FLOAT32_C(   434.09), SIMDE_FLOAT32_C(   451.03), SIMDE_FLOAT32_C(  -778.52) },
       INT32_C(         212),
      { SIMDE_FLOAT32_C(  -941.73),     -SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(   176.53), SIMDE_FLOAT32_C(  -412.77),
        SIMDE_FLOAT32_C(   522.52), SIMDE_FLOAT32_C(   434.09), SIMDE_FLOAT32_C(   451.03), SIMDE_FLOAT32_C(  -778.52) } },
    { { SIMDE_FLOAT32_C(  -792.82), SIMDE_FLOAT32_C(  -685.18), SIMDE_FLOAT32_C(  -258.98), SIMDE_FLOAT32_C(   146.22),
        SIMDE_FLOAT32_C(  -484.85), SIMDE_FLOAT32_C(   429.40), SIMDE_FLOAT32_C(  -602.44), SIMDE_FLOAT32_C(  -571.41) },
       INT32_C(         228),
      { SIMDE_FLOAT32_C(  -792.82), SIMDE_FLOAT32_C(  -685.18), SIMDE_FLOAT32_C(  -258.98), SIMDE_FLOAT32_C(   146.22),
        SIMDE_FLOAT32_C(  -484.85), SIMDE_FLOAT32_C(   429.40), SIMDE_FLOAT32_C(  -602.44), SIMDE_FLOAT32_C(  -571.41) } },
    { { SIMDE_FLOAT32_C(  -144.42), SIMDE_FLOAT32_C(  -645.45), SIMDE_FLOAT32_C(   418.18), SIMDE_FLOAT32_C(  -656.96),
        SIMDE_FLOAT32_C(   489.14), SIMDE_FLOAT32_C(  -552.57), SIMDE_FLOAT32_C(   700.28), SIMDE_FLOAT32_C(  -951.12) },
       INT32_C(         244),
      { SIMDE_FLOAT32_C(  -144.42), SIMDE_FLOAT32_C(  -645.45), SIMDE_FLOAT32_C(   418.18), SIMDE_FLOAT32_C(  -656.96),
        SIMDE_FLOAT32_C(   489.14), SIMDE_FLOAT32_C(  -552.57), SIMDE_FLOAT32_C(   700.28), SIMDE_FLOAT32_C(  -951.12) } },
  };

  simde__m256 a, r;

  a = simde_mm256_loadu_ps(test_vec[0].a);
  r = simde_mm256_roundscale_ps(a, INT32_C(           0));
  simde_test_x86_assert_equal_f32x8(r, simde_mm256_loadu_ps(test_vec[0].r), 1);

  a = simde_mm256_loadu_ps(test_vec[1].a);
  r = simde_mm256_roundscale_ps(a, INT32_C(          16));
  simde_test_x86_assert_equal_f32x8(r, simde_mm256_loadu_ps(test_vec[1].r), 1);

  a = simde_mm256_loadu_ps(test_vec[2].a);
  r = simde_mm256_roundscale_ps(a, INT32_C(          32));
  simde_test_x86_assert_equal_f32x8(r, simde_mm256_loadu_ps(test_vec[2].r), 1);

  a = simde_mm256_loadu_ps(test_vec[3].a);
  r = simde_mm256_roundscale_ps(a, INT32_C(          48));
  simde_test_x86_assert_equal_f32x8(r, simde_mm256_loadu_ps(test_vec[3].r), 1);

  a = simde_mm256_loadu_ps(test_vec[4].a);
  r = simde_mm256_roundscale_ps(a, INT32_C(          64));
  simde_test_x86_assert_equal_f32x8(r, simde_mm256_loadu_ps(test_vec[4].r), 1);

  a = simde_mm256_loadu_ps(test_vec[5].a);
  r = simde_mm256_roundscale_ps(a, INT32_C(          80));
  simde_test_x86_assert_equal_f32x8(r, simde_mm256_loadu_ps(test_vec[5].r), 1);

  a = simde_mm256_loadu_ps(test_vec[6].a);
  r = simde_mm256_roundscale_ps(a, INT32_C(          96));
  simde_test_x86_assert_equal_f32x8(r, simde_mm256_loadu_ps(test_vec[6].r), 1);

  a = simde_mm256_loadu_ps(test_vec[7].a);
  r = simde_mm256_roundscale_ps(a, INT32_C(         112));
  simde_test_x86_assert_equal_f32x8(r, simde_mm256_loadu_ps(test_vec[7].r), 1);

  a = simde_mm256_loadu_ps(test_vec[8].a);
  r = simde_mm256_roundscale_ps(a, INT32_C(         128));
  simde_test_x86_assert_equal_f32x8(r, simde_mm256_loadu_ps(test_vec[8].r), 1);

  a = simde_mm256_loadu_ps(test_vec[9].a);
  r = simde_mm256_roundscale_ps(a, INT32_C(         144));
  simde_test_x86_assert_equal_f32x8(r, simde_mm256_loadu_ps(test_vec[9].r), 1);

  a = simde_mm256_loadu_ps(test_vec[10].a);
  r = simde_mm256_roundscale_ps(a, INT32_C(         160));
  simde_test_x86_assert_equal_f32x8(r, simde_mm256_loadu_ps(test_vec[10].r), 1);

  a = simde_mm256_loadu_ps(test_vec[11].a);
  r = simde_mm256_roundscale_ps(a, INT32_C(         176));
  simde_test_x86_assert_equal_f32x8(r, simde_mm256_loadu_ps(test_vec[11].r), 1);

  a = simde_mm256_loadu_ps(test_vec[12].a);
  r = simde_mm256_roundscale_ps(a, INT32_C(         192));
  simde_test_x86_assert_equal_f32x8(r, simde_mm256_loadu_ps(test_vec[12].r), 1);

  a = simde_mm256_loadu_ps(test_vec[13].a);
  r = simde_mm256_roundscale_ps(a, INT32_C(         208));
  simde_test_x86_assert_equal_f32x8(r, simde_mm256_loadu_ps(test_vec[13].r), 1);

  a = simde_mm256_loadu_ps(test_vec[14].a);
  r = simde_mm256_roundscale_ps(a, INT32_C(         224));
  simde_test_x86_assert_equal_f32x8(r, simde_mm256_loadu_ps(test_vec[14].r), 1);

  a = simde_mm256_loadu_ps(test_vec[15].a);
  r = simde_mm256_roundscale_ps(a, INT32_C(         240));
  simde_test_x86_assert_equal_f32x8(r, simde_mm256_loadu_ps(test_vec[15].r), 1);

  a = simde_mm256_loadu_ps(test_vec[16].a);
  r = simde_mm256_roundscale_ps(a, INT32_C(           1));
  simde_test_x86_assert_equal_f32x8(r, simde_mm256_loadu_ps(test_vec[16].r), 1);

  a = simde_mm256_loadu_ps(test_vec[17].a);
  r = simde_mm256_roundscale_ps(a, INT32_C(          17));
  simde_test_x86_assert_equal_f32x8(r, simde_mm256_loadu_ps(test_vec[17].r), 1);

  a = simde_mm256_loadu_ps(test_vec[18].a);
  r = simde_mm256_roundscale_ps(a, INT32_C(          33));
  simde_test_x86_assert_equal_f32x8(r, simde_mm256_loadu_ps(test_vec[18].r), 1);

  a = simde_mm256_loadu_ps(test_vec[19].a);
  r = simde_mm256_roundscale_ps(a, INT32_C(          49));
  simde_test_x86_assert_equal_f32x8(r, simde_mm256_loadu_ps(test_vec[19].r), 1);

  a = simde_mm256_loadu_ps(test_vec[20].a);
  r = simde_mm256_roundscale_ps(a, INT32_C(          65));
  simde_test_x86_assert_equal_f32x8(r, simde_mm256_loadu_ps(test_vec[20].r), 1);

  a = simde_mm256_loadu_ps(test_vec[21].a);
  r = simde_mm256_roundscale_ps(a, INT32_C(          81));
  simde_test_x86_assert_equal_f32x8(r, simde_mm256_loadu_ps(test_vec[21].r), 1);

  a = simde_mm256_loadu_ps(test_vec[22].a);
  r = simde_mm256_roundscale_ps(a, INT32_C(          97));
  simde_test_x86_assert_equal_f32x8(r, simde_mm256_loadu_ps(test_vec[22].r), 1);

  a = simde_mm256_loadu_ps(test_vec[23].a);
  r = simde_mm256_roundscale_ps(a, INT32_C(         113));
  simde_test_x86_assert_equal_f32x8(r, simde_mm256_loadu_ps(test_vec[23].r), 1);

  a = simde_mm256_loadu_ps(test_vec[24].a);
  r = simde_mm256_roundscale_ps(a, INT32_C(         129));
  simde_test_x86_assert_equal_f32x8(r, simde_mm256_loadu_ps(test_vec[24].r), 1);

  a = simde_mm256_loadu_ps(test_vec[25].a);
  r = simde_mm256_roundscale_ps(a, INT32_C(         145));
  simde_test_x86_assert_equal_f32x8(r, simde_mm256_loadu_ps(test_vec[25].r), 1);

  a = simde_mm256_loadu_ps(test_vec[26].a);
  r = simde_mm256_roundscale_ps(a, INT32_C(         161));
  simde_test_x86_assert_equal_f32x8(r, simde_mm256_loadu_ps(test_vec[26].r), 1);

  a = simde_mm256_loadu_ps(test_vec[27].a);
  r = simde_mm256_roundscale_ps(a, INT32_C(         177));
  simde_test_x86_assert_equal_f32x8(r, simde_mm256_loadu_ps(test_vec[27].r), 1);

  a = simde_mm256_loadu_ps(test_vec[28].a);
  r = simde_mm256_roundscale_ps(a, INT32_C(         193));
  simde_test_x86_assert_equal_f32x8(r, simde_mm256_loadu_ps(test_vec[28].r), 1);

  a = simde_mm256_loadu_ps(test_vec[29].a);
  r = simde_mm256_roundscale_ps(a, INT32_C(         209));
  simde_test_x86_assert_equal_f32x8(r, simde_mm256_loadu_ps(test_vec[29].r), 1);

  a = simde_mm256_loadu_ps(test_vec[30].a);
  r = simde_mm256_roundscale_ps(a, INT32_C(         225));
  simde_test_x86_assert_equal_f32x8(r, simde_mm256_loadu_ps(test_vec[30].r), 1);

  a = simde_mm256_loadu_ps(test_vec[31].a);
  r = simde_mm256_roundscale_ps(a, INT32_C(         241));
  simde_test_x86_assert_equal_f32x8(r, simde_mm256_loadu_ps(test_vec[31].r), 1);

  a = simde_mm256_loadu_ps(test_vec[32].a);
  r = simde_mm256_roundscale_ps(a, INT32_C(           2));
  simde_test_x86_assert_equal_f32x8(r, simde_mm256_loadu_ps(test_vec[32].r), 1);

  a = simde_mm256_loadu_ps(test_vec[33].a);
  r = simde_mm256_roundscale_ps(a, INT32_C(          18));
  simde_test_x86_assert_equal_f32x8(r, simde_mm256_loadu_ps(test_vec[33].r), 1);

  a = simde_mm256_loadu_ps(test_vec[34].a);
  r = simde_mm256_roundscale_ps(a, INT32_C(          34));
  simde_test_x86_assert_equal_f32x8(r, simde_mm256_loadu_ps(test_vec[34].r), 1);

  a = simde_mm256_loadu_ps(test_vec[35].a);
  r = simde_mm256_roundscale_ps(a, INT32_C(          50));
  simde_test_x86_assert_equal_f32x8(r, simde_mm256_loadu_ps(test_vec[35].r), 1);

  a = simde_mm256_loadu_ps(test_vec[36].a);
  r = simde_mm256_roundscale_ps(a, INT32_C(          66));
  simde_test_x86_assert_equal_f32x8(r, simde_mm256_loadu_ps(test_vec[36].r), 1);

  a = simde_mm256_loadu_ps(test_vec[37].a);
  r = simde_mm256_roundscale_ps(a, INT32_C(          82));
  simde_test_x86_assert_equal_f32x8(r, simde_mm256_loadu_ps(test_vec[37].r), 1);

  a = simde_mm256_loadu_ps(test_vec[38].a);
  r = simde_mm256_roundscale_ps(a, INT32_C(          98));
  simde_test_x86_assert_equal_f32x8(r, simde_mm256_loadu_ps(test_vec[38].r), 1);

  a = simde_mm256_loadu_ps(test_vec[39].a);
  r = simde_mm256_roundscale_ps(a, INT32_C(         114));
  simde_test_x86_assert_equal_f32x8(r, simde_mm256_loadu_ps(test_vec[39].r), 1);

  a = simde_mm256_loadu_ps(test_vec[40].a);
  r = simde_mm256_roundscale_ps(a, INT32_C(         130));
  simde_test_x86_assert_equal_f32x8(r, simde_mm256_loadu_ps(test_vec[40].r), 1);

  a = simde_mm256_loadu_ps(test_vec[41].a);
  r = simde_mm256_roundscale_ps(a, INT32_C(         146));
  simde_test_x86_assert_equal_f32x8(r, simde_mm256_loadu_ps(test_vec[41].r), 1);

  a = simde_mm256_loadu_ps(test_vec[42].a);
  r = simde_mm256_roundscale_ps(a, INT32_C(         162));
  simde_test_x86_assert_equal_f32x8(r, simde_mm256_loadu_ps(test_vec[42].r), 1);

  a = simde_mm256_loadu_ps(test_vec[43].a);
  r = simde_mm256_roundscale_ps(a, INT32_C(         178));
  simde_test_x86_assert_equal_f32x8(r, simde_mm256_loadu_ps(test_vec[43].r), 1);

  a = simde_mm256_loadu_ps(test_vec[44].a);
  r = simde_mm256_roundscale_ps(a, INT32_C(         194));
  simde_test_x86_assert_equal_f32x8(r, simde_mm256_loadu_ps(test_vec[44].r), 1);

  a = simde_mm256_loadu_ps(test_vec[45].a);
  r = simde_mm256_roundscale_ps(a, INT32_C(         210));
  simde_test_x86_assert_equal_f32x8(r, simde_mm256_loadu_ps(test_vec[45].r), 1);

  a = simde_mm256_loadu_ps(test_vec[46].a);
  r = simde_mm256_roundscale_ps(a, INT32_C(         226));
  simde_test_x86_assert_equal_f32x8(r, simde_mm256_loadu_ps(test_vec[46].r), 1);

  a = simde_mm256_loadu_ps(test_vec[47].a);
  r = simde_mm256_roundscale_ps(a, INT32_C(         242));
  simde_test_x86_assert_equal_f32x8(r, simde_mm256_loadu_ps(test_vec[47].r), 1);

  a = simde_mm256_loadu_ps(test_vec[48].a);
  r = simde_mm256_roundscale_ps(a, INT32_C(           3));
  simde_test_x86_assert_equal_f32x8(r, simde_mm256_loadu_ps(test_vec[48].r), 1);

  a = simde_mm256_loadu_ps(test_vec[49].a);
  r = simde_mm256_roundscale_ps(a, INT32_C(          19));
  simde_test_x86_assert_equal_f32x8(r, simde_mm256_loadu_ps(test_vec[49].r), 1);

  a = simde_mm256_loadu_ps(test_vec[50].a);
  r = simde_mm256_roundscale_ps(a, INT32_C(          35));
  simde_test_x86_assert_equal_f32x8(r, simde_mm256_loadu_ps(test_vec[50].r), 1);

  a = simde_mm256_loadu_ps(test_vec[51].a);
  r = simde_mm256_roundscale_ps(a, INT32_C(          51));
  simde_test_x86_assert_equal_f32x8(r, simde_mm256_loadu_ps(test_vec[51].r), 1);

  a = simde_mm256_loadu_ps(test_vec[52].a);
  r = simde_mm256_roundscale_ps(a, INT32_C(          67));
  simde_test_x86_assert_equal_f32x8(r, simde_mm256_loadu_ps(test_vec[52].r), 1);

  a = simde_mm256_loadu_ps(test_vec[53].a);
  r = simde_mm256_roundscale_ps(a, INT32_C(          83));
  simde_test_x86_assert_equal_f32x8(r, simde_mm256_loadu_ps(test_vec[53].r), 1);

  a = simde_mm256_loadu_ps(test_vec[54].a);
  r = simde_mm256_roundscale_ps(a, INT32_C(          99));
  simde_test_x86_assert_equal_f32x8(r, simde_mm256_loadu_ps(test_vec[54].r), 1);

  a = simde_mm256_loadu_ps(test_vec[55].a);
  r = simde_mm256_roundscale_ps(a, INT32_C(         115));
  simde_test_x86_assert_equal_f32x8(r, simde_mm256_loadu_ps(test_vec[55].r), 1);

  a = simde_mm256_loadu_ps(test_vec[56].a);
  r = simde_mm256_roundscale_ps(a, INT32_C(         131));
  simde_test_x86_assert_equal_f32x8(r, simde_mm256_loadu_ps(test_vec[56].r), 1);

  a = simde_mm256_loadu_ps(test_vec[57].a);
  r = simde_mm256_roundscale_ps(a, INT32_C(         147));
  simde_test_x86_assert_equal_f32x8(r, simde_mm256_loadu_ps(test_vec[57].r), 1);

  a = simde_mm256_loadu_ps(test_vec[58].a);
  r = simde_mm256_roundscale_ps(a, INT32_C(         163));
  simde_test_x86_assert_equal_f32x8(r, simde_mm256_loadu_ps(test_vec[58].r), 1);

  a = simde_mm256_loadu_ps(test_vec[59].a);
  r = simde_mm256_roundscale_ps(a, INT32_C(         179));
  simde_test_x86_assert_equal_f32x8(r, simde_mm256_loadu_ps(test_vec[59].r), 1);

  a = simde_mm256_loadu_ps(test_vec[60].a);
  r = simde_mm256_roundscale_ps(a, INT32_C(         195));
  simde_test_x86_assert_equal_f32x8(r, simde_mm256_loadu_ps(test_vec[60].r), 1);

  a = simde_mm256_loadu_ps(test_vec[61].a);
  r = simde_mm256_roundscale_ps(a, INT32_C(         211));
  simde_test_x86_assert_equal_f32x8(r, simde_mm256_loadu_ps(test_vec[61].r), 1);

  a = simde_mm256_loadu_ps(test_vec[62].a);
  r = simde_mm256_roundscale_ps(a, INT32_C(         227));
  simde_test_x86_assert_equal_f32x8(r, simde_mm256_loadu_ps(test_vec[62].r), 1);

  a = simde_mm256_loadu_ps(test_vec[63].a);
  r = simde_mm256_roundscale_ps(a, INT32_C(         243));
  simde_test_x86_assert_equal_f32x8(r, simde_mm256_loadu_ps(test_vec[63].r), 1);

  a = simde_mm256_loadu_ps(test_vec[64].a);
  r = simde_mm256_roundscale_ps(a, INT32_C(           4));
  simde_test_x86_assert_equal_f32x8(r, simde_mm256_loadu_ps(test_vec[64].r), 1);

  a = simde_mm256_loadu_ps(test_vec[65].a);
  r = simde_mm256_roundscale_ps(a, INT32_C(          20));
  simde_test_x86_assert_equal_f32x8(r, simde_mm256_loadu_ps(test_vec[65].r), 1);

  a = simde_mm256_loadu_ps(test_vec[66].a);
  r = simde_mm256_roundscale_ps(a, INT32_C(          36));
  simde_test_x86_assert_equal_f32x8(r, simde_mm256_loadu_ps(test_vec[66].r), 1);

  a = simde_mm256_loadu_ps(test_vec[67].a);
  r = simde_mm256_roundscale_ps(a, INT32_C(          52));
  simde_test_x86_assert_equal_f32x8(r, simde_mm256_loadu_ps(test_vec[67].r), 1);

  a = simde_mm256_loadu_ps(test_vec[68].a);
  r = simde_mm256_roundscale_ps(a, INT32_C(          68));
  simde_test_x86_assert_equal_f32x8(r, simde_mm256_loadu_ps(test_vec[68].r), 1);

  a = simde_mm256_loadu_ps(test_vec[69].a);
  r = simde_mm256_roundscale_ps(a, INT32_C(          84));
  simde_test_x86_assert_equal_f32x8(r, simde_mm256_loadu_ps(test_vec[69].r), 1);

  a = simde_mm256_loadu_ps(test_vec[70].a);
  r = simde_mm256_roundscale_ps(a, INT32_C(         100));
  simde_test_x86_assert_equal_f32x8(r, simde_mm256_loadu_ps(test_vec[70].r), 1);

  a = simde_mm256_loadu_ps(test_vec[71].a);
  r = simde_mm256_roundscale_ps(a, INT32_C(         116));
  simde_test_x86_assert_equal_f32x8(r, simde_mm256_loadu_ps(test_vec[71].r), 1);

  a = simde_mm256_loadu_ps(test_vec[72].a);
  r = simde_mm256_roundscale_ps(a, INT32_C(         132));
  simde_test_x86_assert_equal_f32x8(r, simde_mm256_loadu_ps(test_vec[72].r), 1);

  a = simde_mm256_loadu_ps(test_vec[73].a);
  r = simde_mm256_roundscale_ps(a, INT32_C(         148));
  simde_test_x86_assert_equal_f32x8(r, simde_mm256_loadu_ps(test_vec[73].r), 1);

  a = simde_mm256_loadu_ps(test_vec[74].a);
  r = simde_mm256_roundscale_ps(a, INT32_C(         164));
  simde_test_x86_assert_equal_f32x8(r, simde_mm256_loadu_ps(test_vec[74].r), 1);

  a = simde_mm256_loadu_ps(test_vec[75].a);
  r = simde_mm256_roundscale_ps(a, INT32_C(         180));
  simde_test_x86_assert_equal_f32x8(r, simde_mm256_loadu_ps(test_vec[75].r), 1);

  a = simde_mm256_loadu_ps(test_vec[76].a);
  r = simde_mm256_roundscale_ps(a, INT32_C(         196));
  simde_test_x86_assert_equal_f32x8(r, simde_mm256_loadu_ps(test_vec[76].r), 1);

  a = simde_mm256_loadu_ps(test_vec[77].a);
  r = simde_mm256_roundscale_ps(a, INT32_C(         212));
  simde_test_x86_assert_equal_f32x8(r, simde_mm256_loadu_ps(test_vec[77].r), 1);

  a = simde_mm256_loadu_ps(test_vec[78].a);
  r = simde_mm256_roundscale_ps(a, INT32_C(         228));
  simde_test_x86_assert_equal_f32x8(r, simde_mm256_loadu_ps(test_vec[78].r), 1);

  a = simde_mm256_loadu_ps(test_vec[79].a);
  r = simde_mm256_roundscale_ps(a, INT32_C(         244));
  simde_test_x86_assert_equal_f32x8(r, simde_mm256_loadu_ps(test_vec[79].r), 1);

  return 0;
#else
  fputc('\n', stdout);
  int round_type[5] = {SIMDE_MM_FROUND_TO_NEAREST_INT, SIMDE_MM_FROUND_TO_NEG_INF, SIMDE_MM_FROUND_TO_POS_INF, SIMDE_MM_FROUND_TO_ZERO, SIMDE_MM_FROUND_CUR_DIRECTION};
  for (int i = 0 ; i < 5 ; i++) {
    for (int j = 0 ; j < 16 ; j++) {
      simde__m256 a = simde_test_x86_random_f32x8(SIMDE_FLOAT32_C(-1000.0), SIMDE_FLOAT32_C(1000.0));
      if((simde_test_codegen_rand() & 1)) {
        if((simde_test_codegen_rand() & 1))
          a = simde_mm256_blend_ps(a, simde_mm256_set1_ps(SIMDE_MATH_NANF), 1);
        else {
          if((simde_test_codegen_rand() & 1))
            a = simde_mm256_blend_ps(a, simde_mm256_set1_ps(SIMDE_MATH_INFINITY), 2);
          else
            a = simde_mm256_blend_ps(a, simde_mm256_set1_ps(-SIMDE_MATH_INFINITY), 2);
        }
      }
      int imm8 = ((j << 4) | round_type[i]) & 255;
      simde__m256 r;
      SIMDE_CONSTIFY_256_(simde_mm256_roundscale_ps, r, simde_mm256_setzero_ps(), imm8, a);

      simde_test_x86_write_f32x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
      simde_test_codegen_write_i32(2, imm8, SIMDE_TEST_VEC_POS_MIDDLE);
      simde_test_x86_write_f32x8(2, r, SIMDE_TEST_VEC_POS_LAST);
    }
  }
  return 1;
#endif
}

static int
test_simde_mm512_roundscale_ps (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde_float32 a[16];
    const int32_t imm8;
    const simde_float32 r[16];
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(  -239.11),     -SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(   583.11), SIMDE_FLOAT32_C(   -63.62),
        SIMDE_FLOAT32_C(  -542.20), SIMDE_FLOAT32_C(  -943.55), SIMDE_FLOAT32_C(   -44.62), SIMDE_FLOAT32_C(   249.90),
        SIMDE_FLOAT32_C(    -0.52), SIMDE_FLOAT32_C(  -935.78), SIMDE_FLOAT32_C(    55.30), SIMDE_FLOAT32_C(   395.77),
        SIMDE_FLOAT32_C(   796.76), SIMDE_FLOAT32_C(   -21.37), SIMDE_FLOAT32_C(   717.43), SIMDE_FLOAT32_C(  -750.04) },
       INT32_C(           0),
      { SIMDE_FLOAT32_C(  -239.00),     -SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(   583.00), SIMDE_FLOAT32_C(   -64.00),
        SIMDE_FLOAT32_C(  -542.00), SIMDE_FLOAT32_C(  -944.00), SIMDE_FLOAT32_C(   -45.00), SIMDE_FLOAT32_C(   250.00),
        SIMDE_FLOAT32_C(    -1.00), SIMDE_FLOAT32_C(  -936.00), SIMDE_FLOAT32_C(    55.00), SIMDE_FLOAT32_C(   396.00),
        SIMDE_FLOAT32_C(   797.00), SIMDE_FLOAT32_C(   -21.00), SIMDE_FLOAT32_C(   717.00), SIMDE_FLOAT32_C(  -750.00) } },
    { {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -163.71), SIMDE_FLOAT32_C(   660.29), SIMDE_FLOAT32_C(   213.26),
        SIMDE_FLOAT32_C(  -482.31), SIMDE_FLOAT32_C(   945.57), SIMDE_FLOAT32_C(   854.76), SIMDE_FLOAT32_C(  -622.19),
        SIMDE_FLOAT32_C(   -96.60), SIMDE_FLOAT32_C(  -815.85), SIMDE_FLOAT32_C(  -340.65), SIMDE_FLOAT32_C(  -620.08),
        SIMDE_FLOAT32_C(   -54.96), SIMDE_FLOAT32_C(  -327.42), SIMDE_FLOAT32_C(   963.03), SIMDE_FLOAT32_C(   881.42) },
       INT32_C(          16),
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -163.50), SIMDE_FLOAT32_C(   660.50), SIMDE_FLOAT32_C(   213.50),
        SIMDE_FLOAT32_C(  -482.50), SIMDE_FLOAT32_C(   945.50), SIMDE_FLOAT32_C(   855.00), SIMDE_FLOAT32_C(  -622.00),
        SIMDE_FLOAT32_C(   -96.50), SIMDE_FLOAT32_C(  -816.00), SIMDE_FLOAT32_C(  -340.50), SIMDE_FLOAT32_C(  -620.00),
        SIMDE_FLOAT32_C(   -55.00), SIMDE_FLOAT32_C(  -327.50), SIMDE_FLOAT32_C(   963.00), SIMDE_FLOAT32_C(   881.50) } },
    { { SIMDE_FLOAT32_C(  -163.20),      SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(    18.96), SIMDE_FLOAT32_C(   -98.98),
        SIMDE_FLOAT32_C(   435.58), SIMDE_FLOAT32_C(  -585.27), SIMDE_FLOAT32_C(  -302.22), SIMDE_FLOAT32_C(  -585.79),
        SIMDE_FLOAT32_C(  -867.84), SIMDE_FLOAT32_C(   -52.26), SIMDE_FLOAT32_C(  -930.06), SIMDE_FLOAT32_C(  -194.61),
        SIMDE_FLOAT32_C(   242.23), SIMDE_FLOAT32_C(   261.45), SIMDE_FLOAT32_C(   641.68), SIMDE_FLOAT32_C(   -97.48) },
       INT32_C(          32),
      { SIMDE_FLOAT32_C(  -163.25),      SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(    19.00), SIMDE_FLOAT32_C(   -99.00),
        SIMDE_FLOAT32_C(   435.50), SIMDE_FLOAT32_C(  -585.25), SIMDE_FLOAT32_C(  -302.25), SIMDE_FLOAT32_C(  -585.75),
        SIMDE_FLOAT32_C(  -867.75), SIMDE_FLOAT32_C(   -52.25), SIMDE_FLOAT32_C(  -930.00), SIMDE_FLOAT32_C(  -194.50),
        SIMDE_FLOAT32_C(   242.25), SIMDE_FLOAT32_C(   261.50), SIMDE_FLOAT32_C(   641.75), SIMDE_FLOAT32_C(   -97.50) } },
    { { SIMDE_FLOAT32_C(  -670.53), SIMDE_FLOAT32_C(  -462.82), SIMDE_FLOAT32_C(   751.50), SIMDE_FLOAT32_C(  -486.38),
        SIMDE_FLOAT32_C(   196.53), SIMDE_FLOAT32_C(  -868.58), SIMDE_FLOAT32_C(   458.66), SIMDE_FLOAT32_C(   869.11),
        SIMDE_FLOAT32_C(  -905.54), SIMDE_FLOAT32_C(   340.08), SIMDE_FLOAT32_C(    -0.51), SIMDE_FLOAT32_C(  -886.06),
        SIMDE_FLOAT32_C(  -823.11), SIMDE_FLOAT32_C(   379.77), SIMDE_FLOAT32_C(   132.91), SIMDE_FLOAT32_C(    77.91) },
       INT32_C(          48),
      { SIMDE_FLOAT32_C(  -670.50), SIMDE_FLOAT32_C(  -462.88), SIMDE_FLOAT32_C(   751.50), SIMDE_FLOAT32_C(  -486.38),
        SIMDE_FLOAT32_C(   196.50), SIMDE_FLOAT32_C(  -868.62), SIMDE_FLOAT32_C(   458.62), SIMDE_FLOAT32_C(   869.12),
        SIMDE_FLOAT32_C(  -905.50), SIMDE_FLOAT32_C(   340.12), SIMDE_FLOAT32_C(    -0.50), SIMDE_FLOAT32_C(  -886.00),
        SIMDE_FLOAT32_C(  -823.12), SIMDE_FLOAT32_C(   379.75), SIMDE_FLOAT32_C(   132.88), SIMDE_FLOAT32_C(    77.88) } },
    { {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   775.69), SIMDE_FLOAT32_C(   229.57), SIMDE_FLOAT32_C(   679.79),
        SIMDE_FLOAT32_C(  -276.57), SIMDE_FLOAT32_C(   299.51), SIMDE_FLOAT32_C(  -514.82), SIMDE_FLOAT32_C(   965.66),
        SIMDE_FLOAT32_C(  -439.04), SIMDE_FLOAT32_C(  -873.14), SIMDE_FLOAT32_C(  -131.82), SIMDE_FLOAT32_C(    35.67),
        SIMDE_FLOAT32_C(  -713.77), SIMDE_FLOAT32_C(   716.27), SIMDE_FLOAT32_C(   365.14), SIMDE_FLOAT32_C(  -176.59) },
       INT32_C(          64),
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   775.69), SIMDE_FLOAT32_C(   229.56), SIMDE_FLOAT32_C(   679.81),
        SIMDE_FLOAT32_C(  -276.56), SIMDE_FLOAT32_C(   299.50), SIMDE_FLOAT32_C(  -514.81), SIMDE_FLOAT32_C(   965.69),
        SIMDE_FLOAT32_C(  -439.06), SIMDE_FLOAT32_C(  -873.12), SIMDE_FLOAT32_C(  -131.81), SIMDE_FLOAT32_C(    35.69),
        SIMDE_FLOAT32_C(  -713.75), SIMDE_FLOAT32_C(   716.25), SIMDE_FLOAT32_C(   365.12), SIMDE_FLOAT32_C(  -176.56) } },
    { { SIMDE_FLOAT32_C(  -980.06), SIMDE_FLOAT32_C(   599.20), SIMDE_FLOAT32_C(   337.42), SIMDE_FLOAT32_C(   889.05),
        SIMDE_FLOAT32_C(   693.65), SIMDE_FLOAT32_C(  -322.50), SIMDE_FLOAT32_C(  -111.45), SIMDE_FLOAT32_C(   807.60),
        SIMDE_FLOAT32_C(  -145.61), SIMDE_FLOAT32_C(  -731.68), SIMDE_FLOAT32_C(   -59.50), SIMDE_FLOAT32_C(   932.30),
        SIMDE_FLOAT32_C(    83.68), SIMDE_FLOAT32_C(  -511.86), SIMDE_FLOAT32_C(   707.99), SIMDE_FLOAT32_C(  -686.75) },
       INT32_C(          80),
      { SIMDE_FLOAT32_C(  -980.06), SIMDE_FLOAT32_C(   599.19), SIMDE_FLOAT32_C(   337.41), SIMDE_FLOAT32_C(   889.06),
        SIMDE_FLOAT32_C(   693.66), SIMDE_FLOAT32_C(  -322.50), SIMDE_FLOAT32_C(  -111.44), SIMDE_FLOAT32_C(   807.59),
        SIMDE_FLOAT32_C(  -145.62), SIMDE_FLOAT32_C(  -731.69), SIMDE_FLOAT32_C(   -59.50), SIMDE_FLOAT32_C(   932.31),
        SIMDE_FLOAT32_C(    83.69), SIMDE_FLOAT32_C(  -511.88), SIMDE_FLOAT32_C(   708.00), SIMDE_FLOAT32_C(  -686.75) } },
    { {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   612.76), SIMDE_FLOAT32_C(  -346.88), SIMDE_FLOAT32_C(  -602.92),
        SIMDE_FLOAT32_C(  -826.29), SIMDE_FLOAT32_C(  -220.02), SIMDE_FLOAT32_C(   265.26), SIMDE_FLOAT32_C(   209.38),
        SIMDE_FLOAT32_C(    66.21), SIMDE_FLOAT32_C(   -18.47), SIMDE_FLOAT32_C(  -425.48), SIMDE_FLOAT32_C(   889.62),
        SIMDE_FLOAT32_C(  -550.69), SIMDE_FLOAT32_C(  -546.73), SIMDE_FLOAT32_C(   909.56), SIMDE_FLOAT32_C(  -951.50) },
       INT32_C(          96),
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   612.77), SIMDE_FLOAT32_C(  -346.88), SIMDE_FLOAT32_C(  -602.92),
        SIMDE_FLOAT32_C(  -826.30), SIMDE_FLOAT32_C(  -220.02), SIMDE_FLOAT32_C(   265.27), SIMDE_FLOAT32_C(   209.38),
        SIMDE_FLOAT32_C(    66.20), SIMDE_FLOAT32_C(   -18.47), SIMDE_FLOAT32_C(  -425.48), SIMDE_FLOAT32_C(   889.62),
        SIMDE_FLOAT32_C(  -550.69), SIMDE_FLOAT32_C(  -546.73), SIMDE_FLOAT32_C(   909.56), SIMDE_FLOAT32_C(  -951.50) } },
    { { SIMDE_FLOAT32_C(   742.16), SIMDE_FLOAT32_C(  -531.81), SIMDE_FLOAT32_C(  -312.84), SIMDE_FLOAT32_C(   549.76),
        SIMDE_FLOAT32_C(   322.58), SIMDE_FLOAT32_C(   -44.52), SIMDE_FLOAT32_C(  -509.74), SIMDE_FLOAT32_C(   254.88),
        SIMDE_FLOAT32_C(  -960.84), SIMDE_FLOAT32_C(   -21.60), SIMDE_FLOAT32_C(   -37.13), SIMDE_FLOAT32_C(  -647.59),
        SIMDE_FLOAT32_C(   146.33), SIMDE_FLOAT32_C(   394.29), SIMDE_FLOAT32_C(   965.16), SIMDE_FLOAT32_C(   799.45) },
       INT32_C(         112),
      { SIMDE_FLOAT32_C(   742.16), SIMDE_FLOAT32_C(  -531.81), SIMDE_FLOAT32_C(  -312.84), SIMDE_FLOAT32_C(   549.76),
        SIMDE_FLOAT32_C(   322.58), SIMDE_FLOAT32_C(   -44.52), SIMDE_FLOAT32_C(  -509.74), SIMDE_FLOAT32_C(   254.88),
        SIMDE_FLOAT32_C(  -960.84), SIMDE_FLOAT32_C(   -21.60), SIMDE_FLOAT32_C(   -37.13), SIMDE_FLOAT32_C(  -647.59),
        SIMDE_FLOAT32_C(   146.33), SIMDE_FLOAT32_C(   394.29), SIMDE_FLOAT32_C(   965.16), SIMDE_FLOAT32_C(   799.45) } },
    { { SIMDE_FLOAT32_C(  -861.12), SIMDE_FLOAT32_C(  -420.57), SIMDE_FLOAT32_C(    56.62), SIMDE_FLOAT32_C(   348.26),
        SIMDE_FLOAT32_C(   645.63), SIMDE_FLOAT32_C(  -961.85), SIMDE_FLOAT32_C(   922.78), SIMDE_FLOAT32_C(   535.25),
        SIMDE_FLOAT32_C(  -512.54), SIMDE_FLOAT32_C(  -623.95), SIMDE_FLOAT32_C(   444.81), SIMDE_FLOAT32_C(  -464.04),
        SIMDE_FLOAT32_C(  -833.26), SIMDE_FLOAT32_C(   243.42), SIMDE_FLOAT32_C(  -721.88), SIMDE_FLOAT32_C(  -365.07) },
       INT32_C(         128),
      { SIMDE_FLOAT32_C(  -861.12), SIMDE_FLOAT32_C(  -420.57), SIMDE_FLOAT32_C(    56.62), SIMDE_FLOAT32_C(   348.26),
        SIMDE_FLOAT32_C(   645.63), SIMDE_FLOAT32_C(  -961.85), SIMDE_FLOAT32_C(   922.78), SIMDE_FLOAT32_C(   535.25),
        SIMDE_FLOAT32_C(  -512.54), SIMDE_FLOAT32_C(  -623.95), SIMDE_FLOAT32_C(   444.81), SIMDE_FLOAT32_C(  -464.04),
        SIMDE_FLOAT32_C(  -833.26), SIMDE_FLOAT32_C(   243.42), SIMDE_FLOAT32_C(  -721.88), SIMDE_FLOAT32_C(  -365.07) } },
    { { SIMDE_FLOAT32_C(   827.88), SIMDE_FLOAT32_C(   957.50), SIMDE_FLOAT32_C(  -113.94), SIMDE_FLOAT32_C(  -681.86),
        SIMDE_FLOAT32_C(   212.38), SIMDE_FLOAT32_C(   -74.78), SIMDE_FLOAT32_C(   296.54), SIMDE_FLOAT32_C(  -824.75),
        SIMDE_FLOAT32_C(   277.63), SIMDE_FLOAT32_C(  -557.13), SIMDE_FLOAT32_C(   569.53), SIMDE_FLOAT32_C(   242.79),
        SIMDE_FLOAT32_C(  -757.67), SIMDE_FLOAT32_C(   360.90), SIMDE_FLOAT32_C(   381.66), SIMDE_FLOAT32_C(  -178.25) },
       INT32_C(         144),
      { SIMDE_FLOAT32_C(   827.88), SIMDE_FLOAT32_C(   957.50), SIMDE_FLOAT32_C(  -113.94), SIMDE_FLOAT32_C(  -681.86),
        SIMDE_FLOAT32_C(   212.38), SIMDE_FLOAT32_C(   -74.78), SIMDE_FLOAT32_C(   296.54), SIMDE_FLOAT32_C(  -824.75),
        SIMDE_FLOAT32_C(   277.63), SIMDE_FLOAT32_C(  -557.13), SIMDE_FLOAT32_C(   569.53), SIMDE_FLOAT32_C(   242.79),
        SIMDE_FLOAT32_C(  -757.67), SIMDE_FLOAT32_C(   360.90), SIMDE_FLOAT32_C(   381.66), SIMDE_FLOAT32_C(  -178.25) } },
    { { SIMDE_FLOAT32_C(  -270.08),      SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(  -544.32), SIMDE_FLOAT32_C(  -347.30),
        SIMDE_FLOAT32_C(  -997.36), SIMDE_FLOAT32_C(   -56.86), SIMDE_FLOAT32_C(    28.75), SIMDE_FLOAT32_C(   447.45),
        SIMDE_FLOAT32_C(   479.10), SIMDE_FLOAT32_C(   195.49), SIMDE_FLOAT32_C(  -309.13), SIMDE_FLOAT32_C(   757.23),
        SIMDE_FLOAT32_C(   830.41), SIMDE_FLOAT32_C(  -378.54), SIMDE_FLOAT32_C(   585.10), SIMDE_FLOAT32_C(   787.92) },
       INT32_C(         160),
      { SIMDE_FLOAT32_C(  -270.08),      SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(  -544.32), SIMDE_FLOAT32_C(  -347.30),
        SIMDE_FLOAT32_C(  -997.36), SIMDE_FLOAT32_C(   -56.86), SIMDE_FLOAT32_C(    28.75), SIMDE_FLOAT32_C(   447.45),
        SIMDE_FLOAT32_C(   479.10), SIMDE_FLOAT32_C(   195.49), SIMDE_FLOAT32_C(  -309.13), SIMDE_FLOAT32_C(   757.23),
        SIMDE_FLOAT32_C(   830.41), SIMDE_FLOAT32_C(  -378.54), SIMDE_FLOAT32_C(   585.10), SIMDE_FLOAT32_C(   787.92) } },
    { { SIMDE_FLOAT32_C(  -567.26), SIMDE_FLOAT32_C(   199.78), SIMDE_FLOAT32_C(   175.55), SIMDE_FLOAT32_C(   710.37),
        SIMDE_FLOAT32_C(   642.66), SIMDE_FLOAT32_C(  -254.92), SIMDE_FLOAT32_C(   -46.85), SIMDE_FLOAT32_C(   884.98),
        SIMDE_FLOAT32_C(  -894.02), SIMDE_FLOAT32_C(  -665.18), SIMDE_FLOAT32_C(  -293.26), SIMDE_FLOAT32_C(  -476.50),
        SIMDE_FLOAT32_C(    64.74), SIMDE_FLOAT32_C(   174.12), SIMDE_FLOAT32_C(   -20.82), SIMDE_FLOAT32_C(   717.44) },
       INT32_C(         176),
      { SIMDE_FLOAT32_C(  -567.26), SIMDE_FLOAT32_C(   199.78), SIMDE_FLOAT32_C(   175.55), SIMDE_FLOAT32_C(   710.37),
        SIMDE_FLOAT32_C(   642.66), SIMDE_FLOAT32_C(  -254.92), SIMDE_FLOAT32_C(   -46.85), SIMDE_FLOAT32_C(   884.98),
        SIMDE_FLOAT32_C(  -894.02), SIMDE_FLOAT32_C(  -665.18), SIMDE_FLOAT32_C(  -293.26), SIMDE_FLOAT32_C(  -476.50),
        SIMDE_FLOAT32_C(    64.74), SIMDE_FLOAT32_C(   174.12), SIMDE_FLOAT32_C(   -20.82), SIMDE_FLOAT32_C(   717.44) } },
    { { SIMDE_FLOAT32_C(   922.32), SIMDE_FLOAT32_C(  -253.81), SIMDE_FLOAT32_C(  -375.79), SIMDE_FLOAT32_C(   401.42),
        SIMDE_FLOAT32_C(   941.67), SIMDE_FLOAT32_C(   315.09), SIMDE_FLOAT32_C(   158.65), SIMDE_FLOAT32_C(   772.08),
        SIMDE_FLOAT32_C(   936.54), SIMDE_FLOAT32_C(  -256.25), SIMDE_FLOAT32_C(   560.00), SIMDE_FLOAT32_C(   444.06),
        SIMDE_FLOAT32_C(  -353.00), SIMDE_FLOAT32_C(  -439.70), SIMDE_FLOAT32_C(   876.80), SIMDE_FLOAT32_C(   846.78) },
       INT32_C(         192),
      { SIMDE_FLOAT32_C(   922.32), SIMDE_FLOAT32_C(  -253.81), SIMDE_FLOAT32_C(  -375.79), SIMDE_FLOAT32_C(   401.42),
        SIMDE_FLOAT32_C(   941.67), SIMDE_FLOAT32_C(   315.09), SIMDE_FLOAT32_C(   158.65), SIMDE_FLOAT32_C(   772.08),
        SIMDE_FLOAT32_C(   936.54), SIMDE_FLOAT32_C(  -256.25), SIMDE_FLOAT32_C(   560.00), SIMDE_FLOAT32_C(   444.06),
        SIMDE_FLOAT32_C(  -353.00), SIMDE_FLOAT32_C(  -439.70), SIMDE_FLOAT32_C(   876.80), SIMDE_FLOAT32_C(   846.78) } },
    { { SIMDE_FLOAT32_C(   587.16),      SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(  -519.07), SIMDE_FLOAT32_C(  -459.68),
        SIMDE_FLOAT32_C(   374.42), SIMDE_FLOAT32_C(  -413.09), SIMDE_FLOAT32_C(  -124.87), SIMDE_FLOAT32_C(  -918.84),
        SIMDE_FLOAT32_C(   110.41), SIMDE_FLOAT32_C(   939.87), SIMDE_FLOAT32_C(   255.28), SIMDE_FLOAT32_C(  -910.40),
        SIMDE_FLOAT32_C(   657.31), SIMDE_FLOAT32_C(  -567.96), SIMDE_FLOAT32_C(  -988.08), SIMDE_FLOAT32_C(  -596.51) },
       INT32_C(         208),
      { SIMDE_FLOAT32_C(   587.16),      SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(  -519.07), SIMDE_FLOAT32_C(  -459.68),
        SIMDE_FLOAT32_C(   374.42), SIMDE_FLOAT32_C(  -413.09), SIMDE_FLOAT32_C(  -124.87), SIMDE_FLOAT32_C(  -918.84),
        SIMDE_FLOAT32_C(   110.41), SIMDE_FLOAT32_C(   939.87), SIMDE_FLOAT32_C(   255.28), SIMDE_FLOAT32_C(  -910.40),
        SIMDE_FLOAT32_C(   657.31), SIMDE_FLOAT32_C(  -567.96), SIMDE_FLOAT32_C(  -988.08), SIMDE_FLOAT32_C(  -596.51) } },
    { {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -428.01), SIMDE_FLOAT32_C(  -882.75), SIMDE_FLOAT32_C(  -692.12),
        SIMDE_FLOAT32_C(   315.75), SIMDE_FLOAT32_C(   677.25), SIMDE_FLOAT32_C(   751.94), SIMDE_FLOAT32_C(   962.75),
        SIMDE_FLOAT32_C(  -762.45), SIMDE_FLOAT32_C(   628.74), SIMDE_FLOAT32_C(   809.53), SIMDE_FLOAT32_C(   973.39),
        SIMDE_FLOAT32_C(   215.90), SIMDE_FLOAT32_C(   298.97), SIMDE_FLOAT32_C(  -545.68), SIMDE_FLOAT32_C(   756.22) },
       INT32_C(         224),
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -428.01), SIMDE_FLOAT32_C(  -882.75), SIMDE_FLOAT32_C(  -692.12),
        SIMDE_FLOAT32_C(   315.75), SIMDE_FLOAT32_C(   677.25), SIMDE_FLOAT32_C(   751.94), SIMDE_FLOAT32_C(   962.75),
        SIMDE_FLOAT32_C(  -762.45), SIMDE_FLOAT32_C(   628.74), SIMDE_FLOAT32_C(   809.53), SIMDE_FLOAT32_C(   973.39),
        SIMDE_FLOAT32_C(   215.90), SIMDE_FLOAT32_C(   298.97), SIMDE_FLOAT32_C(  -545.68), SIMDE_FLOAT32_C(   756.22) } },
    { { SIMDE_FLOAT32_C(  -368.65), SIMDE_FLOAT32_C(  -245.45), SIMDE_FLOAT32_C(  -848.36), SIMDE_FLOAT32_C(  -428.78),
        SIMDE_FLOAT32_C(  -990.16), SIMDE_FLOAT32_C(  -758.77), SIMDE_FLOAT32_C(  -771.47), SIMDE_FLOAT32_C(  -558.12),
        SIMDE_FLOAT32_C(  -746.85), SIMDE_FLOAT32_C(  -367.97), SIMDE_FLOAT32_C(   498.14), SIMDE_FLOAT32_C(   666.49),
        SIMDE_FLOAT32_C(   -22.81), SIMDE_FLOAT32_C(   869.48), SIMDE_FLOAT32_C(  -761.51), SIMDE_FLOAT32_C(    94.44) },
       INT32_C(         240),
      { SIMDE_FLOAT32_C(  -368.65), SIMDE_FLOAT32_C(  -245.45), SIMDE_FLOAT32_C(  -848.36), SIMDE_FLOAT32_C(  -428.78),
        SIMDE_FLOAT32_C(  -990.16), SIMDE_FLOAT32_C(  -758.77), SIMDE_FLOAT32_C(  -771.47), SIMDE_FLOAT32_C(  -558.12),
        SIMDE_FLOAT32_C(  -746.85), SIMDE_FLOAT32_C(  -367.97), SIMDE_FLOAT32_C(   498.14), SIMDE_FLOAT32_C(   666.49),
        SIMDE_FLOAT32_C(   -22.81), SIMDE_FLOAT32_C(   869.48), SIMDE_FLOAT32_C(  -761.51), SIMDE_FLOAT32_C(    94.44) } },
    { { SIMDE_FLOAT32_C(   554.23), SIMDE_FLOAT32_C(  -228.31), SIMDE_FLOAT32_C(   929.30), SIMDE_FLOAT32_C(   516.98),
        SIMDE_FLOAT32_C(     9.24), SIMDE_FLOAT32_C(   558.04), SIMDE_FLOAT32_C(   326.51), SIMDE_FLOAT32_C(   -17.36),
        SIMDE_FLOAT32_C(  -226.05), SIMDE_FLOAT32_C(  -374.52), SIMDE_FLOAT32_C(   436.96), SIMDE_FLOAT32_C(  -469.84),
        SIMDE_FLOAT32_C(   298.87), SIMDE_FLOAT32_C(  -521.81), SIMDE_FLOAT32_C(   161.51), SIMDE_FLOAT32_C(  -946.58) },
       INT32_C(           1),
      { SIMDE_FLOAT32_C(   554.00), SIMDE_FLOAT32_C(  -229.00), SIMDE_FLOAT32_C(   929.00), SIMDE_FLOAT32_C(   516.00),
        SIMDE_FLOAT32_C(     9.00), SIMDE_FLOAT32_C(   558.00), SIMDE_FLOAT32_C(   326.00), SIMDE_FLOAT32_C(   -18.00),
        SIMDE_FLOAT32_C(  -227.00), SIMDE_FLOAT32_C(  -375.00), SIMDE_FLOAT32_C(   436.00), SIMDE_FLOAT32_C(  -470.00),
        SIMDE_FLOAT32_C(   298.00), SIMDE_FLOAT32_C(  -522.00), SIMDE_FLOAT32_C(   161.00), SIMDE_FLOAT32_C(  -947.00) } },
    { {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -936.74), SIMDE_FLOAT32_C(  -128.94), SIMDE_FLOAT32_C(   961.27),
        SIMDE_FLOAT32_C(  -494.86), SIMDE_FLOAT32_C(   124.21), SIMDE_FLOAT32_C(  -406.70), SIMDE_FLOAT32_C(  -996.73),
        SIMDE_FLOAT32_C(  -209.29), SIMDE_FLOAT32_C(   570.49), SIMDE_FLOAT32_C(   872.75), SIMDE_FLOAT32_C(    29.19),
        SIMDE_FLOAT32_C(  -335.06), SIMDE_FLOAT32_C(  -949.89), SIMDE_FLOAT32_C(  -416.57), SIMDE_FLOAT32_C(   436.63) },
       INT32_C(          17),
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -937.00), SIMDE_FLOAT32_C(  -129.00), SIMDE_FLOAT32_C(   961.00),
        SIMDE_FLOAT32_C(  -495.00), SIMDE_FLOAT32_C(   124.00), SIMDE_FLOAT32_C(  -407.00), SIMDE_FLOAT32_C(  -997.00),
        SIMDE_FLOAT32_C(  -209.50), SIMDE_FLOAT32_C(   570.00), SIMDE_FLOAT32_C(   872.50), SIMDE_FLOAT32_C(    29.00),
        SIMDE_FLOAT32_C(  -335.50), SIMDE_FLOAT32_C(  -950.00), SIMDE_FLOAT32_C(  -417.00), SIMDE_FLOAT32_C(   436.50) } },
    { {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   537.46), SIMDE_FLOAT32_C(   426.92), SIMDE_FLOAT32_C(   428.51),
        SIMDE_FLOAT32_C(  -688.59), SIMDE_FLOAT32_C(  -947.61), SIMDE_FLOAT32_C(  -134.53), SIMDE_FLOAT32_C(  -158.43),
        SIMDE_FLOAT32_C(   351.26), SIMDE_FLOAT32_C(   343.66), SIMDE_FLOAT32_C(  -996.91), SIMDE_FLOAT32_C(   404.69),
        SIMDE_FLOAT32_C(   973.48), SIMDE_FLOAT32_C(   735.82), SIMDE_FLOAT32_C(   467.95), SIMDE_FLOAT32_C(  -155.46) },
       INT32_C(          33),
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   537.25), SIMDE_FLOAT32_C(   426.75), SIMDE_FLOAT32_C(   428.50),
        SIMDE_FLOAT32_C(  -688.75), SIMDE_FLOAT32_C(  -947.75), SIMDE_FLOAT32_C(  -134.75), SIMDE_FLOAT32_C(  -158.50),
        SIMDE_FLOAT32_C(   351.25), SIMDE_FLOAT32_C(   343.50), SIMDE_FLOAT32_C(  -997.00), SIMDE_FLOAT32_C(   404.50),
        SIMDE_FLOAT32_C(   973.25), SIMDE_FLOAT32_C(   735.75), SIMDE_FLOAT32_C(   467.75), SIMDE_FLOAT32_C(  -155.50) } },
    { { SIMDE_FLOAT32_C(   968.76), SIMDE_FLOAT32_C(  -709.61), SIMDE_FLOAT32_C(   976.36), SIMDE_FLOAT32_C(  -240.54),
        SIMDE_FLOAT32_C(   860.89), SIMDE_FLOAT32_C(   849.11), SIMDE_FLOAT32_C(   788.66), SIMDE_FLOAT32_C(  -474.18),
        SIMDE_FLOAT32_C(   899.23), SIMDE_FLOAT32_C(  -627.91), SIMDE_FLOAT32_C(   962.45), SIMDE_FLOAT32_C(   878.64),
        SIMDE_FLOAT32_C(  -527.51), SIMDE_FLOAT32_C(  -591.67), SIMDE_FLOAT32_C(   416.11), SIMDE_FLOAT32_C(   899.41) },
       INT32_C(          49),
      { SIMDE_FLOAT32_C(   968.75), SIMDE_FLOAT32_C(  -709.62), SIMDE_FLOAT32_C(   976.25), SIMDE_FLOAT32_C(  -240.62),
        SIMDE_FLOAT32_C(   860.88), SIMDE_FLOAT32_C(   849.00), SIMDE_FLOAT32_C(   788.62), SIMDE_FLOAT32_C(  -474.25),
        SIMDE_FLOAT32_C(   899.12), SIMDE_FLOAT32_C(  -628.00), SIMDE_FLOAT32_C(   962.38), SIMDE_FLOAT32_C(   878.62),
        SIMDE_FLOAT32_C(  -527.62), SIMDE_FLOAT32_C(  -591.75), SIMDE_FLOAT32_C(   416.00), SIMDE_FLOAT32_C(   899.38) } },
    { { SIMDE_FLOAT32_C(   727.51),      SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(  -297.69), SIMDE_FLOAT32_C(  -430.92),
        SIMDE_FLOAT32_C(   303.06), SIMDE_FLOAT32_C(  -954.03), SIMDE_FLOAT32_C(  -427.83), SIMDE_FLOAT32_C(  -292.25),
        SIMDE_FLOAT32_C(  -980.55), SIMDE_FLOAT32_C(  -692.01), SIMDE_FLOAT32_C(  -824.31), SIMDE_FLOAT32_C(  -136.00),
        SIMDE_FLOAT32_C(  -994.91), SIMDE_FLOAT32_C(  -851.22), SIMDE_FLOAT32_C(  -167.25), SIMDE_FLOAT32_C(  -704.52) },
       INT32_C(          65),
      { SIMDE_FLOAT32_C(   727.50),      SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(  -297.75), SIMDE_FLOAT32_C(  -430.94),
        SIMDE_FLOAT32_C(   303.00), SIMDE_FLOAT32_C(  -954.06), SIMDE_FLOAT32_C(  -427.88), SIMDE_FLOAT32_C(  -292.25),
        SIMDE_FLOAT32_C(  -980.56), SIMDE_FLOAT32_C(  -692.06), SIMDE_FLOAT32_C(  -824.31), SIMDE_FLOAT32_C(  -136.00),
        SIMDE_FLOAT32_C(  -994.94), SIMDE_FLOAT32_C(  -851.25), SIMDE_FLOAT32_C(  -167.25), SIMDE_FLOAT32_C(  -704.56) } },
    { { SIMDE_FLOAT32_C(   974.25), SIMDE_FLOAT32_C(   380.88), SIMDE_FLOAT32_C(  -317.81), SIMDE_FLOAT32_C(   873.47),
        SIMDE_FLOAT32_C(   752.96), SIMDE_FLOAT32_C(  -355.35), SIMDE_FLOAT32_C(   752.12), SIMDE_FLOAT32_C(  -774.55),
        SIMDE_FLOAT32_C(    52.97), SIMDE_FLOAT32_C(   168.23), SIMDE_FLOAT32_C(  -875.14), SIMDE_FLOAT32_C(  -110.19),
        SIMDE_FLOAT32_C(  -104.26), SIMDE_FLOAT32_C(  -923.34), SIMDE_FLOAT32_C(   592.12), SIMDE_FLOAT32_C(   464.82) },
       INT32_C(          81),
      { SIMDE_FLOAT32_C(   974.25), SIMDE_FLOAT32_C(   380.88), SIMDE_FLOAT32_C(  -317.81), SIMDE_FLOAT32_C(   873.47),
        SIMDE_FLOAT32_C(   752.94), SIMDE_FLOAT32_C(  -355.38), SIMDE_FLOAT32_C(   752.09), SIMDE_FLOAT32_C(  -774.56),
        SIMDE_FLOAT32_C(    52.97), SIMDE_FLOAT32_C(   168.22), SIMDE_FLOAT32_C(  -875.16), SIMDE_FLOAT32_C(  -110.22),
        SIMDE_FLOAT32_C(  -104.28), SIMDE_FLOAT32_C(  -923.34), SIMDE_FLOAT32_C(   592.09), SIMDE_FLOAT32_C(   464.81) } },
    { { SIMDE_FLOAT32_C(   638.09), SIMDE_FLOAT32_C(  -963.01), SIMDE_FLOAT32_C(  -912.53), SIMDE_FLOAT32_C(   657.54),
        SIMDE_FLOAT32_C(  -655.02), SIMDE_FLOAT32_C(  -736.83), SIMDE_FLOAT32_C(  -478.47), SIMDE_FLOAT32_C(  -649.93),
        SIMDE_FLOAT32_C(  -588.06), SIMDE_FLOAT32_C(   354.29), SIMDE_FLOAT32_C(  -354.45), SIMDE_FLOAT32_C(  -462.92),
        SIMDE_FLOAT32_C(   -53.50), SIMDE_FLOAT32_C(  -198.08), SIMDE_FLOAT32_C(  -488.67), SIMDE_FLOAT32_C(  -672.62) },
       INT32_C(          97),
      { SIMDE_FLOAT32_C(   638.08), SIMDE_FLOAT32_C(  -963.02), SIMDE_FLOAT32_C(  -912.53), SIMDE_FLOAT32_C(   657.53),
        SIMDE_FLOAT32_C(  -655.03), SIMDE_FLOAT32_C(  -736.84), SIMDE_FLOAT32_C(  -478.48), SIMDE_FLOAT32_C(  -649.94),
        SIMDE_FLOAT32_C(  -588.06), SIMDE_FLOAT32_C(   354.28), SIMDE_FLOAT32_C(  -354.45), SIMDE_FLOAT32_C(  -462.92),
        SIMDE_FLOAT32_C(   -53.50), SIMDE_FLOAT32_C(  -198.09), SIMDE_FLOAT32_C(  -488.67), SIMDE_FLOAT32_C(  -672.62) } },
    { { SIMDE_FLOAT32_C(  -615.20), SIMDE_FLOAT32_C(  -919.66), SIMDE_FLOAT32_C(  -871.24), SIMDE_FLOAT32_C(  -863.08),
        SIMDE_FLOAT32_C(  -694.20), SIMDE_FLOAT32_C(   181.73), SIMDE_FLOAT32_C(   305.15), SIMDE_FLOAT32_C(  -569.34),
        SIMDE_FLOAT32_C(  -928.46), SIMDE_FLOAT32_C(  -799.11), SIMDE_FLOAT32_C(  -492.68), SIMDE_FLOAT32_C(   663.66),
        SIMDE_FLOAT32_C(   665.71), SIMDE_FLOAT32_C(   887.04), SIMDE_FLOAT32_C(   301.75), SIMDE_FLOAT32_C(   702.70) },
       INT32_C(         113),
      { SIMDE_FLOAT32_C(  -615.20), SIMDE_FLOAT32_C(  -919.66), SIMDE_FLOAT32_C(  -871.24), SIMDE_FLOAT32_C(  -863.09),
        SIMDE_FLOAT32_C(  -694.20), SIMDE_FLOAT32_C(   181.73), SIMDE_FLOAT32_C(   305.15), SIMDE_FLOAT32_C(  -569.34),
        SIMDE_FLOAT32_C(  -928.46), SIMDE_FLOAT32_C(  -799.12), SIMDE_FLOAT32_C(  -492.69), SIMDE_FLOAT32_C(   663.66),
        SIMDE_FLOAT32_C(   665.70), SIMDE_FLOAT32_C(   887.04), SIMDE_FLOAT32_C(   301.75), SIMDE_FLOAT32_C(   702.70) } },
    { { SIMDE_FLOAT32_C(   -40.71), SIMDE_FLOAT32_C(  -952.32), SIMDE_FLOAT32_C(  -762.32), SIMDE_FLOAT32_C(   480.82),
        SIMDE_FLOAT32_C(  -602.24), SIMDE_FLOAT32_C(  -350.38), SIMDE_FLOAT32_C(  -164.90), SIMDE_FLOAT32_C(    43.31),
        SIMDE_FLOAT32_C(   186.70), SIMDE_FLOAT32_C(   781.61), SIMDE_FLOAT32_C(   845.23), SIMDE_FLOAT32_C(   698.03),
        SIMDE_FLOAT32_C(  -891.01), SIMDE_FLOAT32_C(   329.34), SIMDE_FLOAT32_C(  -917.16), SIMDE_FLOAT32_C(  -810.67) },
       INT32_C(         129),
      { SIMDE_FLOAT32_C(   -40.71), SIMDE_FLOAT32_C(  -952.32), SIMDE_FLOAT32_C(  -762.32), SIMDE_FLOAT32_C(   480.82),
        SIMDE_FLOAT32_C(  -602.24), SIMDE_FLOAT32_C(  -350.38), SIMDE_FLOAT32_C(  -164.90), SIMDE_FLOAT32_C(    43.31),
        SIMDE_FLOAT32_C(   186.70), SIMDE_FLOAT32_C(   781.61), SIMDE_FLOAT32_C(   845.23), SIMDE_FLOAT32_C(   698.03),
        SIMDE_FLOAT32_C(  -891.01), SIMDE_FLOAT32_C(   329.34), SIMDE_FLOAT32_C(  -917.16), SIMDE_FLOAT32_C(  -810.67) } },
    { { SIMDE_FLOAT32_C(  -780.24), SIMDE_FLOAT32_C(  -504.87), SIMDE_FLOAT32_C(  -360.16), SIMDE_FLOAT32_C(   524.91),
        SIMDE_FLOAT32_C(   -74.22), SIMDE_FLOAT32_C(  -288.62), SIMDE_FLOAT32_C(   725.79), SIMDE_FLOAT32_C(   433.10),
        SIMDE_FLOAT32_C(  -624.96), SIMDE_FLOAT32_C(   391.50), SIMDE_FLOAT32_C(   320.14), SIMDE_FLOAT32_C(   676.79),
        SIMDE_FLOAT32_C(    94.20), SIMDE_FLOAT32_C(   294.65), SIMDE_FLOAT32_C(  -363.93), SIMDE_FLOAT32_C(   141.89) },
       INT32_C(         145),
      { SIMDE_FLOAT32_C(  -780.24), SIMDE_FLOAT32_C(  -504.87), SIMDE_FLOAT32_C(  -360.16), SIMDE_FLOAT32_C(   524.91),
        SIMDE_FLOAT32_C(   -74.22), SIMDE_FLOAT32_C(  -288.62), SIMDE_FLOAT32_C(   725.79), SIMDE_FLOAT32_C(   433.10),
        SIMDE_FLOAT32_C(  -624.96), SIMDE_FLOAT32_C(   391.50), SIMDE_FLOAT32_C(   320.14), SIMDE_FLOAT32_C(   676.79),
        SIMDE_FLOAT32_C(    94.20), SIMDE_FLOAT32_C(   294.65), SIMDE_FLOAT32_C(  -363.93), SIMDE_FLOAT32_C(   141.89) } },
    { { SIMDE_FLOAT32_C(  -883.11),      SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(  -818.05), SIMDE_FLOAT32_C(   -48.01),
        SIMDE_FLOAT32_C(  -417.05), SIMDE_FLOAT32_C(   368.66), SIMDE_FLOAT32_C(  -266.40), SIMDE_FLOAT32_C(  -571.82),
        SIMDE_FLOAT32_C(    66.69), SIMDE_FLOAT32_C(  -157.41), SIMDE_FLOAT32_C(   757.52), SIMDE_FLOAT32_C(   149.52),
        SIMDE_FLOAT32_C(    31.92), SIMDE_FLOAT32_C(   215.63), SIMDE_FLOAT32_C(   369.28), SIMDE_FLOAT32_C(   527.05) },
       INT32_C(         161),
      { SIMDE_FLOAT32_C(  -883.11),      SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(  -818.05), SIMDE_FLOAT32_C(   -48.01),
        SIMDE_FLOAT32_C(  -417.05), SIMDE_FLOAT32_C(   368.66), SIMDE_FLOAT32_C(  -266.40), SIMDE_FLOAT32_C(  -571.82),
        SIMDE_FLOAT32_C(    66.69), SIMDE_FLOAT32_C(  -157.41), SIMDE_FLOAT32_C(   757.52), SIMDE_FLOAT32_C(   149.52),
        SIMDE_FLOAT32_C(    31.92), SIMDE_FLOAT32_C(   215.63), SIMDE_FLOAT32_C(   369.28), SIMDE_FLOAT32_C(   527.05) } },
    { { SIMDE_FLOAT32_C(  -433.16),     -SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(   885.93), SIMDE_FLOAT32_C(   -58.11),
        SIMDE_FLOAT32_C(  -988.52), SIMDE_FLOAT32_C(   206.07), SIMDE_FLOAT32_C(  -381.32), SIMDE_FLOAT32_C(   105.68),
        SIMDE_FLOAT32_C(  -499.27), SIMDE_FLOAT32_C(   254.75), SIMDE_FLOAT32_C(  -752.43), SIMDE_FLOAT32_C(  -966.94),
        SIMDE_FLOAT32_C(   371.64), SIMDE_FLOAT32_C(   787.21), SIMDE_FLOAT32_C(  -784.99), SIMDE_FLOAT32_C(  -676.36) },
       INT32_C(         177),
      { SIMDE_FLOAT32_C(  -433.16),     -SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(   885.93), SIMDE_FLOAT32_C(   -58.11),
        SIMDE_FLOAT32_C(  -988.52), SIMDE_FLOAT32_C(   206.07), SIMDE_FLOAT32_C(  -381.32), SIMDE_FLOAT32_C(   105.68),
        SIMDE_FLOAT32_C(  -499.27), SIMDE_FLOAT32_C(   254.75), SIMDE_FLOAT32_C(  -752.43), SIMDE_FLOAT32_C(  -966.94),
        SIMDE_FLOAT32_C(   371.64), SIMDE_FLOAT32_C(   787.21), SIMDE_FLOAT32_C(  -784.99), SIMDE_FLOAT32_C(  -676.36) } },
    { { SIMDE_FLOAT32_C(  -201.66), SIMDE_FLOAT32_C(  -349.65), SIMDE_FLOAT32_C(   899.83), SIMDE_FLOAT32_C(  -444.13),
        SIMDE_FLOAT32_C(   799.88), SIMDE_FLOAT32_C(   -68.25), SIMDE_FLOAT32_C(   771.50), SIMDE_FLOAT32_C(   169.16),
        SIMDE_FLOAT32_C(  -541.21), SIMDE_FLOAT32_C(   626.96), SIMDE_FLOAT32_C(  -936.65), SIMDE_FLOAT32_C(   -88.38),
        SIMDE_FLOAT32_C(  -806.19), SIMDE_FLOAT32_C(  -316.67), SIMDE_FLOAT32_C(  -202.45), SIMDE_FLOAT32_C(   135.69) },
       INT32_C(         193),
      { SIMDE_FLOAT32_C(  -201.66), SIMDE_FLOAT32_C(  -349.65), SIMDE_FLOAT32_C(   899.83), SIMDE_FLOAT32_C(  -444.13),
        SIMDE_FLOAT32_C(   799.88), SIMDE_FLOAT32_C(   -68.25), SIMDE_FLOAT32_C(   771.50), SIMDE_FLOAT32_C(   169.16),
        SIMDE_FLOAT32_C(  -541.21), SIMDE_FLOAT32_C(   626.96), SIMDE_FLOAT32_C(  -936.65), SIMDE_FLOAT32_C(   -88.38),
        SIMDE_FLOAT32_C(  -806.19), SIMDE_FLOAT32_C(  -316.67), SIMDE_FLOAT32_C(  -202.45), SIMDE_FLOAT32_C(   135.69) } },
    { { SIMDE_FLOAT32_C(  -996.37), SIMDE_FLOAT32_C(   754.37), SIMDE_FLOAT32_C(   800.49), SIMDE_FLOAT32_C(  -495.65),
        SIMDE_FLOAT32_C(     9.12), SIMDE_FLOAT32_C(  -951.94), SIMDE_FLOAT32_C(  -462.59), SIMDE_FLOAT32_C(  -619.24),
        SIMDE_FLOAT32_C(   835.28), SIMDE_FLOAT32_C(  -247.58), SIMDE_FLOAT32_C(  -295.60), SIMDE_FLOAT32_C(  -794.56),
        SIMDE_FLOAT32_C(  -663.91), SIMDE_FLOAT32_C(   761.64), SIMDE_FLOAT32_C(     3.78), SIMDE_FLOAT32_C(   -13.56) },
       INT32_C(         209),
      { SIMDE_FLOAT32_C(  -996.37), SIMDE_FLOAT32_C(   754.37), SIMDE_FLOAT32_C(   800.49), SIMDE_FLOAT32_C(  -495.65),
        SIMDE_FLOAT32_C(     9.12), SIMDE_FLOAT32_C(  -951.94), SIMDE_FLOAT32_C(  -462.59), SIMDE_FLOAT32_C(  -619.24),
        SIMDE_FLOAT32_C(   835.28), SIMDE_FLOAT32_C(  -247.58), SIMDE_FLOAT32_C(  -295.60), SIMDE_FLOAT32_C(  -794.56),
        SIMDE_FLOAT32_C(  -663.91), SIMDE_FLOAT32_C(   761.64), SIMDE_FLOAT32_C(     3.78), SIMDE_FLOAT32_C(   -13.56) } },
    { { SIMDE_FLOAT32_C(   559.65),      SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(  -406.79), SIMDE_FLOAT32_C(   331.15),
        SIMDE_FLOAT32_C(   955.48), SIMDE_FLOAT32_C(    52.00), SIMDE_FLOAT32_C(   -41.89), SIMDE_FLOAT32_C(  -981.18),
        SIMDE_FLOAT32_C(   963.62), SIMDE_FLOAT32_C(   151.92), SIMDE_FLOAT32_C(  -297.85), SIMDE_FLOAT32_C(  -238.82),
        SIMDE_FLOAT32_C(  -712.39), SIMDE_FLOAT32_C(   396.96), SIMDE_FLOAT32_C(  -235.20), SIMDE_FLOAT32_C(  -958.02) },
       INT32_C(         225),
      { SIMDE_FLOAT32_C(   559.65),      SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(  -406.79), SIMDE_FLOAT32_C(   331.15),
        SIMDE_FLOAT32_C(   955.48), SIMDE_FLOAT32_C(    52.00), SIMDE_FLOAT32_C(   -41.89), SIMDE_FLOAT32_C(  -981.18),
        SIMDE_FLOAT32_C(   963.62), SIMDE_FLOAT32_C(   151.92), SIMDE_FLOAT32_C(  -297.85), SIMDE_FLOAT32_C(  -238.82),
        SIMDE_FLOAT32_C(  -712.39), SIMDE_FLOAT32_C(   396.96), SIMDE_FLOAT32_C(  -235.20), SIMDE_FLOAT32_C(  -958.02) } },
    { { SIMDE_FLOAT32_C(   245.51), SIMDE_FLOAT32_C(   806.57), SIMDE_FLOAT32_C(   431.86), SIMDE_FLOAT32_C(    80.78),
        SIMDE_FLOAT32_C(  -441.01), SIMDE_FLOAT32_C(  -863.74), SIMDE_FLOAT32_C(   286.22), SIMDE_FLOAT32_C(  -104.92),
        SIMDE_FLOAT32_C(   897.90), SIMDE_FLOAT32_C(  -710.00), SIMDE_FLOAT32_C(   881.52), SIMDE_FLOAT32_C(   559.36),
        SIMDE_FLOAT32_C(   849.65), SIMDE_FLOAT32_C(  -332.16), SIMDE_FLOAT32_C(  -847.43), SIMDE_FLOAT32_C(   180.80) },
       INT32_C(         241),
      { SIMDE_FLOAT32_C(   245.51), SIMDE_FLOAT32_C(   806.57), SIMDE_FLOAT32_C(   431.86), SIMDE_FLOAT32_C(    80.78),
        SIMDE_FLOAT32_C(  -441.01), SIMDE_FLOAT32_C(  -863.74), SIMDE_FLOAT32_C(   286.22), SIMDE_FLOAT32_C(  -104.92),
        SIMDE_FLOAT32_C(   897.90), SIMDE_FLOAT32_C(  -710.00), SIMDE_FLOAT32_C(   881.52), SIMDE_FLOAT32_C(   559.36),
        SIMDE_FLOAT32_C(   849.65), SIMDE_FLOAT32_C(  -332.16), SIMDE_FLOAT32_C(  -847.43), SIMDE_FLOAT32_C(   180.80) } },
    { { SIMDE_FLOAT32_C(   204.57),     -SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(  -357.86), SIMDE_FLOAT32_C(   168.20),
        SIMDE_FLOAT32_C(   290.83), SIMDE_FLOAT32_C(   344.29), SIMDE_FLOAT32_C(   929.37), SIMDE_FLOAT32_C(   578.44),
        SIMDE_FLOAT32_C(  -258.76), SIMDE_FLOAT32_C(  -305.82), SIMDE_FLOAT32_C(   620.43), SIMDE_FLOAT32_C(   938.69),
        SIMDE_FLOAT32_C(   963.33), SIMDE_FLOAT32_C(  -328.47), SIMDE_FLOAT32_C(   184.20), SIMDE_FLOAT32_C(   769.90) },
       INT32_C(           2),
      { SIMDE_FLOAT32_C(   205.00),     -SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(  -357.00), SIMDE_FLOAT32_C(   169.00),
        SIMDE_FLOAT32_C(   291.00), SIMDE_FLOAT32_C(   345.00), SIMDE_FLOAT32_C(   930.00), SIMDE_FLOAT32_C(   579.00),
        SIMDE_FLOAT32_C(  -258.00), SIMDE_FLOAT32_C(  -305.00), SIMDE_FLOAT32_C(   621.00), SIMDE_FLOAT32_C(   939.00),
        SIMDE_FLOAT32_C(   964.00), SIMDE_FLOAT32_C(  -328.00), SIMDE_FLOAT32_C(   185.00), SIMDE_FLOAT32_C(   770.00) } },
    { { SIMDE_FLOAT32_C(  -760.35), SIMDE_FLOAT32_C(   551.21), SIMDE_FLOAT32_C(   223.96), SIMDE_FLOAT32_C(  -862.45),
        SIMDE_FLOAT32_C(   841.21), SIMDE_FLOAT32_C(   105.48), SIMDE_FLOAT32_C(   696.91), SIMDE_FLOAT32_C(   690.87),
        SIMDE_FLOAT32_C(   773.32), SIMDE_FLOAT32_C(   849.48), SIMDE_FLOAT32_C(  -128.33), SIMDE_FLOAT32_C(  -603.37),
        SIMDE_FLOAT32_C(    54.05), SIMDE_FLOAT32_C(    10.58), SIMDE_FLOAT32_C(    38.77), SIMDE_FLOAT32_C(  -777.76) },
       INT32_C(          18),
      { SIMDE_FLOAT32_C(  -760.00), SIMDE_FLOAT32_C(   551.50), SIMDE_FLOAT32_C(   224.00), SIMDE_FLOAT32_C(  -862.00),
        SIMDE_FLOAT32_C(   841.50), SIMDE_FLOAT32_C(   105.50), SIMDE_FLOAT32_C(   697.00), SIMDE_FLOAT32_C(   691.00),
        SIMDE_FLOAT32_C(   773.50), SIMDE_FLOAT32_C(   849.50), SIMDE_FLOAT32_C(  -128.00), SIMDE_FLOAT32_C(  -603.00),
        SIMDE_FLOAT32_C(    54.50), SIMDE_FLOAT32_C(    11.00), SIMDE_FLOAT32_C(    39.00), SIMDE_FLOAT32_C(  -777.50) } },
    { { SIMDE_FLOAT32_C(  -616.94), SIMDE_FLOAT32_C(  -848.38), SIMDE_FLOAT32_C(   879.86), SIMDE_FLOAT32_C(   124.30),
        SIMDE_FLOAT32_C(  -154.21), SIMDE_FLOAT32_C(   500.29), SIMDE_FLOAT32_C(    62.99), SIMDE_FLOAT32_C(  -190.87),
        SIMDE_FLOAT32_C(  -828.18), SIMDE_FLOAT32_C(  -752.81), SIMDE_FLOAT32_C(  -420.98), SIMDE_FLOAT32_C(  -724.79),
        SIMDE_FLOAT32_C(  -487.82), SIMDE_FLOAT32_C(   -92.10), SIMDE_FLOAT32_C(  -485.14), SIMDE_FLOAT32_C(  -936.62) },
       INT32_C(          34),
      { SIMDE_FLOAT32_C(  -616.75), SIMDE_FLOAT32_C(  -848.25), SIMDE_FLOAT32_C(   880.00), SIMDE_FLOAT32_C(   124.50),
        SIMDE_FLOAT32_C(  -154.00), SIMDE_FLOAT32_C(   500.50), SIMDE_FLOAT32_C(    63.00), SIMDE_FLOAT32_C(  -190.75),
        SIMDE_FLOAT32_C(  -828.00), SIMDE_FLOAT32_C(  -752.75), SIMDE_FLOAT32_C(  -420.75), SIMDE_FLOAT32_C(  -724.75),
        SIMDE_FLOAT32_C(  -487.75), SIMDE_FLOAT32_C(   -92.00), SIMDE_FLOAT32_C(  -485.00), SIMDE_FLOAT32_C(  -936.50) } },
    { { SIMDE_FLOAT32_C(  -347.59), SIMDE_FLOAT32_C(   904.60), SIMDE_FLOAT32_C(   237.34), SIMDE_FLOAT32_C(  -650.69),
        SIMDE_FLOAT32_C(   595.46), SIMDE_FLOAT32_C(    10.66), SIMDE_FLOAT32_C(  -801.21), SIMDE_FLOAT32_C(  -532.87),
        SIMDE_FLOAT32_C(   407.29), SIMDE_FLOAT32_C(   252.84), SIMDE_FLOAT32_C(   477.72), SIMDE_FLOAT32_C(  -553.94),
        SIMDE_FLOAT32_C(   475.08), SIMDE_FLOAT32_C(   779.13), SIMDE_FLOAT32_C(  -170.89), SIMDE_FLOAT32_C(   626.70) },
       INT32_C(          50),
      { SIMDE_FLOAT32_C(  -347.50), SIMDE_FLOAT32_C(   904.62), SIMDE_FLOAT32_C(   237.38), SIMDE_FLOAT32_C(  -650.62),
        SIMDE_FLOAT32_C(   595.50), SIMDE_FLOAT32_C(    10.75), SIMDE_FLOAT32_C(  -801.12), SIMDE_FLOAT32_C(  -532.75),
        SIMDE_FLOAT32_C(   407.38), SIMDE_FLOAT32_C(   252.88), SIMDE_FLOAT32_C(   477.75), SIMDE_FLOAT32_C(  -553.88),
        SIMDE_FLOAT32_C(   475.12), SIMDE_FLOAT32_C(   779.25), SIMDE_FLOAT32_C(  -170.88), SIMDE_FLOAT32_C(   626.75) } },
    { {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -527.51), SIMDE_FLOAT32_C(   159.28), SIMDE_FLOAT32_C(    16.41),
        SIMDE_FLOAT32_C(   281.62), SIMDE_FLOAT32_C(   331.09), SIMDE_FLOAT32_C(   263.60), SIMDE_FLOAT32_C(   860.64),
        SIMDE_FLOAT32_C(   606.30), SIMDE_FLOAT32_C(   775.77), SIMDE_FLOAT32_C(  -231.46), SIMDE_FLOAT32_C(  -878.84),
        SIMDE_FLOAT32_C(   839.16), SIMDE_FLOAT32_C(   -99.59), SIMDE_FLOAT32_C(  -226.43), SIMDE_FLOAT32_C(   743.75) },
       INT32_C(          66),
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -527.50), SIMDE_FLOAT32_C(   159.31), SIMDE_FLOAT32_C(    16.44),
        SIMDE_FLOAT32_C(   281.62), SIMDE_FLOAT32_C(   331.12), SIMDE_FLOAT32_C(   263.62), SIMDE_FLOAT32_C(   860.69),
        SIMDE_FLOAT32_C(   606.31), SIMDE_FLOAT32_C(   775.81), SIMDE_FLOAT32_C(  -231.44), SIMDE_FLOAT32_C(  -878.81),
        SIMDE_FLOAT32_C(   839.19), SIMDE_FLOAT32_C(   -99.56), SIMDE_FLOAT32_C(  -226.38), SIMDE_FLOAT32_C(   743.75) } },
    { { SIMDE_FLOAT32_C(   339.22), SIMDE_FLOAT32_C(   148.40), SIMDE_FLOAT32_C(   321.67), SIMDE_FLOAT32_C(   806.35),
        SIMDE_FLOAT32_C(  -444.31), SIMDE_FLOAT32_C(  -425.49), SIMDE_FLOAT32_C(   284.07), SIMDE_FLOAT32_C(     1.75),
        SIMDE_FLOAT32_C(  -950.41), SIMDE_FLOAT32_C(    63.20), SIMDE_FLOAT32_C(   830.86), SIMDE_FLOAT32_C(   676.28),
        SIMDE_FLOAT32_C(  -277.81), SIMDE_FLOAT32_C(   784.28), SIMDE_FLOAT32_C(  -851.22), SIMDE_FLOAT32_C(   881.47) },
       INT32_C(          82),
      { SIMDE_FLOAT32_C(   339.25), SIMDE_FLOAT32_C(   148.41), SIMDE_FLOAT32_C(   321.69), SIMDE_FLOAT32_C(   806.38),
        SIMDE_FLOAT32_C(  -444.28), SIMDE_FLOAT32_C(  -425.47), SIMDE_FLOAT32_C(   284.09), SIMDE_FLOAT32_C(     1.75),
        SIMDE_FLOAT32_C(  -950.41), SIMDE_FLOAT32_C(    63.22), SIMDE_FLOAT32_C(   830.88), SIMDE_FLOAT32_C(   676.28),
        SIMDE_FLOAT32_C(  -277.78), SIMDE_FLOAT32_C(   784.28), SIMDE_FLOAT32_C(  -851.22), SIMDE_FLOAT32_C(   881.50) } },
    { {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   212.56), SIMDE_FLOAT32_C(  -935.72), SIMDE_FLOAT32_C(   291.04),
        SIMDE_FLOAT32_C(  -181.14), SIMDE_FLOAT32_C(   840.05), SIMDE_FLOAT32_C(  -940.42), SIMDE_FLOAT32_C(   -59.98),
        SIMDE_FLOAT32_C(   679.21), SIMDE_FLOAT32_C(   -40.01), SIMDE_FLOAT32_C(   713.59), SIMDE_FLOAT32_C(   422.96),
        SIMDE_FLOAT32_C(    97.73), SIMDE_FLOAT32_C(  -163.53), SIMDE_FLOAT32_C(  -237.82), SIMDE_FLOAT32_C(  -753.86) },
       INT32_C(          98),
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   212.56), SIMDE_FLOAT32_C(  -935.72), SIMDE_FLOAT32_C(   291.05),
        SIMDE_FLOAT32_C(  -181.12), SIMDE_FLOAT32_C(   840.06), SIMDE_FLOAT32_C(  -940.41), SIMDE_FLOAT32_C(   -59.97),
        SIMDE_FLOAT32_C(   679.22), SIMDE_FLOAT32_C(   -40.00), SIMDE_FLOAT32_C(   713.59), SIMDE_FLOAT32_C(   422.97),
        SIMDE_FLOAT32_C(    97.73), SIMDE_FLOAT32_C(  -163.52), SIMDE_FLOAT32_C(  -237.81), SIMDE_FLOAT32_C(  -753.86) } },
    { { SIMDE_FLOAT32_C(  -198.17), SIMDE_FLOAT32_C(  -267.36), SIMDE_FLOAT32_C(   852.61), SIMDE_FLOAT32_C(   803.57),
        SIMDE_FLOAT32_C(  -217.77), SIMDE_FLOAT32_C(   -84.19), SIMDE_FLOAT32_C(   634.43), SIMDE_FLOAT32_C(  -541.49),
        SIMDE_FLOAT32_C(   638.00), SIMDE_FLOAT32_C(   418.71), SIMDE_FLOAT32_C(  -392.71), SIMDE_FLOAT32_C(   519.47),
        SIMDE_FLOAT32_C(  -780.61), SIMDE_FLOAT32_C(  -962.31), SIMDE_FLOAT32_C(  -267.97), SIMDE_FLOAT32_C(  -716.33) },
       INT32_C(         114),
      { SIMDE_FLOAT32_C(  -198.16), SIMDE_FLOAT32_C(  -267.36), SIMDE_FLOAT32_C(   852.62), SIMDE_FLOAT32_C(   803.57),
        SIMDE_FLOAT32_C(  -217.77), SIMDE_FLOAT32_C(   -84.19), SIMDE_FLOAT32_C(   634.44), SIMDE_FLOAT32_C(  -541.48),
        SIMDE_FLOAT32_C(   638.00), SIMDE_FLOAT32_C(   418.71), SIMDE_FLOAT32_C(  -392.70), SIMDE_FLOAT32_C(   519.48),
        SIMDE_FLOAT32_C(  -780.61), SIMDE_FLOAT32_C(  -962.30), SIMDE_FLOAT32_C(  -267.97), SIMDE_FLOAT32_C(  -716.33) } },
    { { SIMDE_FLOAT32_C(   550.89), SIMDE_FLOAT32_C(  -876.28), SIMDE_FLOAT32_C(   388.30), SIMDE_FLOAT32_C(  -509.09),
        SIMDE_FLOAT32_C(   802.93), SIMDE_FLOAT32_C(  -651.71), SIMDE_FLOAT32_C(  -795.50), SIMDE_FLOAT32_C(   225.90),
        SIMDE_FLOAT32_C(   446.02), SIMDE_FLOAT32_C(    40.97), SIMDE_FLOAT32_C(   988.08), SIMDE_FLOAT32_C(   692.15),
        SIMDE_FLOAT32_C(   199.10), SIMDE_FLOAT32_C(  -443.39), SIMDE_FLOAT32_C(  -506.02), SIMDE_FLOAT32_C(   931.74) },
       INT32_C(         130),
      { SIMDE_FLOAT32_C(   550.89), SIMDE_FLOAT32_C(  -876.28), SIMDE_FLOAT32_C(   388.30), SIMDE_FLOAT32_C(  -509.09),
        SIMDE_FLOAT32_C(   802.93), SIMDE_FLOAT32_C(  -651.71), SIMDE_FLOAT32_C(  -795.50), SIMDE_FLOAT32_C(   225.90),
        SIMDE_FLOAT32_C(   446.02), SIMDE_FLOAT32_C(    40.97), SIMDE_FLOAT32_C(   988.08), SIMDE_FLOAT32_C(   692.15),
        SIMDE_FLOAT32_C(   199.10), SIMDE_FLOAT32_C(  -443.39), SIMDE_FLOAT32_C(  -506.02), SIMDE_FLOAT32_C(   931.74) } },
    { { SIMDE_FLOAT32_C(  -702.45), SIMDE_FLOAT32_C(  -286.03), SIMDE_FLOAT32_C(   325.03), SIMDE_FLOAT32_C(   931.98),
        SIMDE_FLOAT32_C(   172.48), SIMDE_FLOAT32_C(   -36.97), SIMDE_FLOAT32_C(   350.69), SIMDE_FLOAT32_C(   779.77),
        SIMDE_FLOAT32_C(  -517.50), SIMDE_FLOAT32_C(   570.08), SIMDE_FLOAT32_C(   817.46), SIMDE_FLOAT32_C(   214.53),
        SIMDE_FLOAT32_C(   853.75), SIMDE_FLOAT32_C(   146.18), SIMDE_FLOAT32_C(  -234.57), SIMDE_FLOAT32_C(   977.48) },
       INT32_C(         146),
      { SIMDE_FLOAT32_C(  -702.45), SIMDE_FLOAT32_C(  -286.03), SIMDE_FLOAT32_C(   325.03), SIMDE_FLOAT32_C(   931.98),
        SIMDE_FLOAT32_C(   172.48), SIMDE_FLOAT32_C(   -36.97), SIMDE_FLOAT32_C(   350.69), SIMDE_FLOAT32_C(   779.77),
        SIMDE_FLOAT32_C(  -517.50), SIMDE_FLOAT32_C(   570.08), SIMDE_FLOAT32_C(   817.46), SIMDE_FLOAT32_C(   214.53),
        SIMDE_FLOAT32_C(   853.75), SIMDE_FLOAT32_C(   146.18), SIMDE_FLOAT32_C(  -234.57), SIMDE_FLOAT32_C(   977.48) } },
    { {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   780.41), SIMDE_FLOAT32_C(  -117.23), SIMDE_FLOAT32_C(   460.84),
        SIMDE_FLOAT32_C(     6.31), SIMDE_FLOAT32_C(  -671.21), SIMDE_FLOAT32_C(  -498.20), SIMDE_FLOAT32_C(    -5.62),
        SIMDE_FLOAT32_C(  -979.06), SIMDE_FLOAT32_C(   700.91), SIMDE_FLOAT32_C(   551.00), SIMDE_FLOAT32_C(  -485.08),
        SIMDE_FLOAT32_C(   632.65), SIMDE_FLOAT32_C(   960.22), SIMDE_FLOAT32_C(  -187.53), SIMDE_FLOAT32_C(  -653.38) },
       INT32_C(         162),
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   780.41), SIMDE_FLOAT32_C(  -117.23), SIMDE_FLOAT32_C(   460.84),
        SIMDE_FLOAT32_C(     6.31), SIMDE_FLOAT32_C(  -671.21), SIMDE_FLOAT32_C(  -498.20), SIMDE_FLOAT32_C(    -5.62),
        SIMDE_FLOAT32_C(  -979.06), SIMDE_FLOAT32_C(   700.91), SIMDE_FLOAT32_C(   551.00), SIMDE_FLOAT32_C(  -485.08),
        SIMDE_FLOAT32_C(   632.65), SIMDE_FLOAT32_C(   960.22), SIMDE_FLOAT32_C(  -187.53), SIMDE_FLOAT32_C(  -653.38) } },
    { { SIMDE_FLOAT32_C(   519.10),     -SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(  -904.85), SIMDE_FLOAT32_C(   298.88),
        SIMDE_FLOAT32_C(  -269.23), SIMDE_FLOAT32_C(   665.23), SIMDE_FLOAT32_C(   116.34), SIMDE_FLOAT32_C(   945.30),
        SIMDE_FLOAT32_C(   518.99), SIMDE_FLOAT32_C(  -737.48), SIMDE_FLOAT32_C(  -289.27), SIMDE_FLOAT32_C(   496.46),
        SIMDE_FLOAT32_C(  -202.99), SIMDE_FLOAT32_C(   967.07), SIMDE_FLOAT32_C(   276.87), SIMDE_FLOAT32_C(   679.78) },
       INT32_C(         178),
      { SIMDE_FLOAT32_C(   519.10),     -SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(  -904.85), SIMDE_FLOAT32_C(   298.88),
        SIMDE_FLOAT32_C(  -269.23), SIMDE_FLOAT32_C(   665.23), SIMDE_FLOAT32_C(   116.34), SIMDE_FLOAT32_C(   945.30),
        SIMDE_FLOAT32_C(   518.99), SIMDE_FLOAT32_C(  -737.48), SIMDE_FLOAT32_C(  -289.27), SIMDE_FLOAT32_C(   496.46),
        SIMDE_FLOAT32_C(  -202.99), SIMDE_FLOAT32_C(   967.07), SIMDE_FLOAT32_C(   276.87), SIMDE_FLOAT32_C(   679.78) } },
    { { SIMDE_FLOAT32_C(   929.71), SIMDE_FLOAT32_C(   277.56), SIMDE_FLOAT32_C(  -970.49), SIMDE_FLOAT32_C(   630.62),
        SIMDE_FLOAT32_C(  -171.44), SIMDE_FLOAT32_C(  -455.57), SIMDE_FLOAT32_C(   263.26), SIMDE_FLOAT32_C(  -211.22),
        SIMDE_FLOAT32_C(   356.90), SIMDE_FLOAT32_C(   609.88), SIMDE_FLOAT32_C(  -925.98), SIMDE_FLOAT32_C(  -898.64),
        SIMDE_FLOAT32_C(   128.99), SIMDE_FLOAT32_C(  -677.71), SIMDE_FLOAT32_C(  -803.49), SIMDE_FLOAT32_C(  -572.13) },
       INT32_C(         194),
      { SIMDE_FLOAT32_C(   929.71), SIMDE_FLOAT32_C(   277.56), SIMDE_FLOAT32_C(  -970.49), SIMDE_FLOAT32_C(   630.62),
        SIMDE_FLOAT32_C(  -171.44), SIMDE_FLOAT32_C(  -455.57), SIMDE_FLOAT32_C(   263.26), SIMDE_FLOAT32_C(  -211.22),
        SIMDE_FLOAT32_C(   356.90), SIMDE_FLOAT32_C(   609.88), SIMDE_FLOAT32_C(  -925.98), SIMDE_FLOAT32_C(  -898.64),
        SIMDE_FLOAT32_C(   128.99), SIMDE_FLOAT32_C(  -677.71), SIMDE_FLOAT32_C(  -803.49), SIMDE_FLOAT32_C(  -572.13) } },
    { { SIMDE_FLOAT32_C(   861.75), SIMDE_FLOAT32_C(   544.21), SIMDE_FLOAT32_C(    -1.64), SIMDE_FLOAT32_C(   380.73),
        SIMDE_FLOAT32_C(   806.73), SIMDE_FLOAT32_C(   709.09), SIMDE_FLOAT32_C(  -122.80), SIMDE_FLOAT32_C(  -396.26),
        SIMDE_FLOAT32_C(   676.16), SIMDE_FLOAT32_C(  -845.93), SIMDE_FLOAT32_C(  -716.49), SIMDE_FLOAT32_C(   104.06),
        SIMDE_FLOAT32_C(  -562.75), SIMDE_FLOAT32_C(  -707.92), SIMDE_FLOAT32_C(    33.77), SIMDE_FLOAT32_C(   714.82) },
       INT32_C(         210),
      { SIMDE_FLOAT32_C(   861.75), SIMDE_FLOAT32_C(   544.21), SIMDE_FLOAT32_C(    -1.64), SIMDE_FLOAT32_C(   380.73),
        SIMDE_FLOAT32_C(   806.73), SIMDE_FLOAT32_C(   709.09), SIMDE_FLOAT32_C(  -122.80), SIMDE_FLOAT32_C(  -396.26),
        SIMDE_FLOAT32_C(   676.16), SIMDE_FLOAT32_C(  -845.93), SIMDE_FLOAT32_C(  -716.49), SIMDE_FLOAT32_C(   104.06),
        SIMDE_FLOAT32_C(  -562.75), SIMDE_FLOAT32_C(  -707.92), SIMDE_FLOAT32_C(    33.77), SIMDE_FLOAT32_C(   714.82) } },
    { { SIMDE_FLOAT32_C(  -335.61), SIMDE_FLOAT32_C(  -456.62), SIMDE_FLOAT32_C(  -133.99), SIMDE_FLOAT32_C(   927.65),
        SIMDE_FLOAT32_C(   332.15), SIMDE_FLOAT32_C(  -777.08), SIMDE_FLOAT32_C(   537.54), SIMDE_FLOAT32_C(   406.17),
        SIMDE_FLOAT32_C(  -675.72), SIMDE_FLOAT32_C(  -333.47), SIMDE_FLOAT32_C(   728.46), SIMDE_FLOAT32_C(  -479.21),
        SIMDE_FLOAT32_C(    94.39), SIMDE_FLOAT32_C(  -218.48), SIMDE_FLOAT32_C(  -617.46), SIMDE_FLOAT32_C(  -361.40) },
       INT32_C(         226),
      { SIMDE_FLOAT32_C(  -335.61), SIMDE_FLOAT32_C(  -456.62), SIMDE_FLOAT32_C(  -133.99), SIMDE_FLOAT32_C(   927.65),
        SIMDE_FLOAT32_C(   332.15), SIMDE_FLOAT32_C(  -777.08), SIMDE_FLOAT32_C(   537.54), SIMDE_FLOAT32_C(   406.17),
        SIMDE_FLOAT32_C(  -675.72), SIMDE_FLOAT32_C(  -333.47), SIMDE_FLOAT32_C(   728.46), SIMDE_FLOAT32_C(  -479.21),
        SIMDE_FLOAT32_C(    94.39), SIMDE_FLOAT32_C(  -218.48), SIMDE_FLOAT32_C(  -617.46), SIMDE_FLOAT32_C(  -361.40) } },
    { {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -554.67), SIMDE_FLOAT32_C(   488.98), SIMDE_FLOAT32_C(  -359.53),
        SIMDE_FLOAT32_C(    49.07), SIMDE_FLOAT32_C(   165.14), SIMDE_FLOAT32_C(  -205.46), SIMDE_FLOAT32_C(   332.58),
        SIMDE_FLOAT32_C(  -730.80), SIMDE_FLOAT32_C(   231.79), SIMDE_FLOAT32_C(   624.65), SIMDE_FLOAT32_C(   302.97),
        SIMDE_FLOAT32_C(   -53.39), SIMDE_FLOAT32_C(   946.24), SIMDE_FLOAT32_C(   967.36), SIMDE_FLOAT32_C(   489.99) },
       INT32_C(         242),
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -554.67), SIMDE_FLOAT32_C(   488.98), SIMDE_FLOAT32_C(  -359.53),
        SIMDE_FLOAT32_C(    49.07), SIMDE_FLOAT32_C(   165.14), SIMDE_FLOAT32_C(  -205.46), SIMDE_FLOAT32_C(   332.58),
        SIMDE_FLOAT32_C(  -730.80), SIMDE_FLOAT32_C(   231.79), SIMDE_FLOAT32_C(   624.65), SIMDE_FLOAT32_C(   302.97),
        SIMDE_FLOAT32_C(   -53.39), SIMDE_FLOAT32_C(   946.24), SIMDE_FLOAT32_C(   967.36), SIMDE_FLOAT32_C(   489.99) } },
    { { SIMDE_FLOAT32_C(  -177.86),     -SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(   432.55), SIMDE_FLOAT32_C(  -771.68),
        SIMDE_FLOAT32_C(   359.44), SIMDE_FLOAT32_C(  -900.93), SIMDE_FLOAT32_C(   956.78), SIMDE_FLOAT32_C(   880.23),
        SIMDE_FLOAT32_C(   193.47), SIMDE_FLOAT32_C(  -261.69), SIMDE_FLOAT32_C(  -737.23), SIMDE_FLOAT32_C(   832.07),
        SIMDE_FLOAT32_C(  -481.81), SIMDE_FLOAT32_C(  -973.96), SIMDE_FLOAT32_C(  -722.60), SIMDE_FLOAT32_C(  -992.83) },
       INT32_C(           3),
      { SIMDE_FLOAT32_C(  -177.00),     -SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(   432.00), SIMDE_FLOAT32_C(  -771.00),
        SIMDE_FLOAT32_C(   359.00), SIMDE_FLOAT32_C(  -900.00), SIMDE_FLOAT32_C(   956.00), SIMDE_FLOAT32_C(   880.00),
        SIMDE_FLOAT32_C(   193.00), SIMDE_FLOAT32_C(  -261.00), SIMDE_FLOAT32_C(  -737.00), SIMDE_FLOAT32_C(   832.00),
        SIMDE_FLOAT32_C(  -481.00), SIMDE_FLOAT32_C(  -973.00), SIMDE_FLOAT32_C(  -722.00), SIMDE_FLOAT32_C(  -992.00) } },
    { { SIMDE_FLOAT32_C(   461.05), SIMDE_FLOAT32_C(  -340.96), SIMDE_FLOAT32_C(   441.50), SIMDE_FLOAT32_C(  -307.15),
        SIMDE_FLOAT32_C(  -716.30), SIMDE_FLOAT32_C(  -255.53), SIMDE_FLOAT32_C(   639.46), SIMDE_FLOAT32_C(  -770.07),
        SIMDE_FLOAT32_C(  -288.17), SIMDE_FLOAT32_C(   129.45), SIMDE_FLOAT32_C(    42.18), SIMDE_FLOAT32_C(  -393.15),
        SIMDE_FLOAT32_C(   951.59), SIMDE_FLOAT32_C(  -922.65), SIMDE_FLOAT32_C(  -960.61), SIMDE_FLOAT32_C(  -820.09) },
       INT32_C(          19),
      { SIMDE_FLOAT32_C(   461.00), SIMDE_FLOAT32_C(  -340.50), SIMDE_FLOAT32_C(   441.50), SIMDE_FLOAT32_C(  -307.00),
        SIMDE_FLOAT32_C(  -716.00), SIMDE_FLOAT32_C(  -255.50), SIMDE_FLOAT32_C(   639.00), SIMDE_FLOAT32_C(  -770.00),
        SIMDE_FLOAT32_C(  -288.00), SIMDE_FLOAT32_C(   129.00), SIMDE_FLOAT32_C(    42.00), SIMDE_FLOAT32_C(  -393.00),
        SIMDE_FLOAT32_C(   951.50), SIMDE_FLOAT32_C(  -922.50), SIMDE_FLOAT32_C(  -960.50), SIMDE_FLOAT32_C(  -820.00) } },
    { { SIMDE_FLOAT32_C(  -861.53),     -SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(   317.02), SIMDE_FLOAT32_C(   331.93),
        SIMDE_FLOAT32_C(  -125.00), SIMDE_FLOAT32_C(   579.79), SIMDE_FLOAT32_C(   164.00), SIMDE_FLOAT32_C(   393.19),
        SIMDE_FLOAT32_C(   605.84), SIMDE_FLOAT32_C(   441.40), SIMDE_FLOAT32_C(   400.36), SIMDE_FLOAT32_C(  -727.65),
        SIMDE_FLOAT32_C(  -232.14), SIMDE_FLOAT32_C(  -427.33), SIMDE_FLOAT32_C(   733.40), SIMDE_FLOAT32_C(   426.90) },
       INT32_C(          35),
      { SIMDE_FLOAT32_C(  -861.50),     -SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(   317.00), SIMDE_FLOAT32_C(   331.75),
        SIMDE_FLOAT32_C(  -125.00), SIMDE_FLOAT32_C(   579.75), SIMDE_FLOAT32_C(   164.00), SIMDE_FLOAT32_C(   393.00),
        SIMDE_FLOAT32_C(   605.75), SIMDE_FLOAT32_C(   441.25), SIMDE_FLOAT32_C(   400.25), SIMDE_FLOAT32_C(  -727.50),
        SIMDE_FLOAT32_C(  -232.00), SIMDE_FLOAT32_C(  -427.25), SIMDE_FLOAT32_C(   733.25), SIMDE_FLOAT32_C(   426.75) } },
    { { SIMDE_FLOAT32_C(  -241.35), SIMDE_FLOAT32_C(  -934.30), SIMDE_FLOAT32_C(   940.53), SIMDE_FLOAT32_C(   470.48),
        SIMDE_FLOAT32_C(   195.15), SIMDE_FLOAT32_C(   -17.29), SIMDE_FLOAT32_C(  -922.68), SIMDE_FLOAT32_C(   146.74),
        SIMDE_FLOAT32_C(    60.06), SIMDE_FLOAT32_C(  -883.28), SIMDE_FLOAT32_C(   326.65), SIMDE_FLOAT32_C(  -503.15),
        SIMDE_FLOAT32_C(  -744.81), SIMDE_FLOAT32_C(   463.34), SIMDE_FLOAT32_C(   813.88), SIMDE_FLOAT32_C(   587.12) },
       INT32_C(          51),
      { SIMDE_FLOAT32_C(  -241.25), SIMDE_FLOAT32_C(  -934.25), SIMDE_FLOAT32_C(   940.50), SIMDE_FLOAT32_C(   470.38),
        SIMDE_FLOAT32_C(   195.12), SIMDE_FLOAT32_C(   -17.25), SIMDE_FLOAT32_C(  -922.62), SIMDE_FLOAT32_C(   146.62),
        SIMDE_FLOAT32_C(    60.00), SIMDE_FLOAT32_C(  -883.25), SIMDE_FLOAT32_C(   326.62), SIMDE_FLOAT32_C(  -503.12),
        SIMDE_FLOAT32_C(  -744.75), SIMDE_FLOAT32_C(   463.25), SIMDE_FLOAT32_C(   813.88), SIMDE_FLOAT32_C(   587.00) } },
    { { SIMDE_FLOAT32_C(   393.67), SIMDE_FLOAT32_C(  -248.88), SIMDE_FLOAT32_C(   731.52), SIMDE_FLOAT32_C(    -0.49),
        SIMDE_FLOAT32_C(  -807.48), SIMDE_FLOAT32_C(   131.89), SIMDE_FLOAT32_C(   271.86), SIMDE_FLOAT32_C(   -39.62),
        SIMDE_FLOAT32_C(   704.55), SIMDE_FLOAT32_C(     5.26), SIMDE_FLOAT32_C(  -612.72), SIMDE_FLOAT32_C(   718.72),
        SIMDE_FLOAT32_C(   431.50), SIMDE_FLOAT32_C(  -902.12), SIMDE_FLOAT32_C(  -522.63), SIMDE_FLOAT32_C(   497.20) },
       INT32_C(          67),
      { SIMDE_FLOAT32_C(   393.62), SIMDE_FLOAT32_C(  -248.88), SIMDE_FLOAT32_C(   731.50), SIMDE_FLOAT32_C(    -0.44),
        SIMDE_FLOAT32_C(  -807.44), SIMDE_FLOAT32_C(   131.88), SIMDE_FLOAT32_C(   271.81), SIMDE_FLOAT32_C(   -39.56),
        SIMDE_FLOAT32_C(   704.50), SIMDE_FLOAT32_C(     5.25), SIMDE_FLOAT32_C(  -612.69), SIMDE_FLOAT32_C(   718.69),
        SIMDE_FLOAT32_C(   431.50), SIMDE_FLOAT32_C(  -902.06), SIMDE_FLOAT32_C(  -522.62), SIMDE_FLOAT32_C(   497.19) } },
    { { SIMDE_FLOAT32_C(   947.85),      SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(    21.12), SIMDE_FLOAT32_C(  -974.83),
        SIMDE_FLOAT32_C(   839.09), SIMDE_FLOAT32_C(  -918.82), SIMDE_FLOAT32_C(  -858.11), SIMDE_FLOAT32_C(   165.74),
        SIMDE_FLOAT32_C(  -421.96), SIMDE_FLOAT32_C(  -602.92), SIMDE_FLOAT32_C(  -370.92), SIMDE_FLOAT32_C(  -608.09),
        SIMDE_FLOAT32_C(   984.20), SIMDE_FLOAT32_C(   -32.59), SIMDE_FLOAT32_C(   785.58), SIMDE_FLOAT32_C(  -264.68) },
       INT32_C(          83),
      { SIMDE_FLOAT32_C(   947.84),      SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(    21.09), SIMDE_FLOAT32_C(  -974.81),
        SIMDE_FLOAT32_C(   839.06), SIMDE_FLOAT32_C(  -918.81), SIMDE_FLOAT32_C(  -858.09), SIMDE_FLOAT32_C(   165.72),
        SIMDE_FLOAT32_C(  -421.94), SIMDE_FLOAT32_C(  -602.91), SIMDE_FLOAT32_C(  -370.91), SIMDE_FLOAT32_C(  -608.06),
        SIMDE_FLOAT32_C(   984.19), SIMDE_FLOAT32_C(   -32.56), SIMDE_FLOAT32_C(   785.56), SIMDE_FLOAT32_C(  -264.66) } },
    { { SIMDE_FLOAT32_C(   830.82),      SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(   888.22), SIMDE_FLOAT32_C(   535.37),
        SIMDE_FLOAT32_C(    62.20), SIMDE_FLOAT32_C(  -724.50), SIMDE_FLOAT32_C(   254.09), SIMDE_FLOAT32_C(  -506.30),
        SIMDE_FLOAT32_C(  -626.62), SIMDE_FLOAT32_C(   731.46), SIMDE_FLOAT32_C(   990.91), SIMDE_FLOAT32_C(  -588.21),
        SIMDE_FLOAT32_C(   679.31), SIMDE_FLOAT32_C(  -316.74), SIMDE_FLOAT32_C(   432.91), SIMDE_FLOAT32_C(   704.48) },
       INT32_C(          99),
      { SIMDE_FLOAT32_C(   830.81),      SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(   888.22), SIMDE_FLOAT32_C(   535.36),
        SIMDE_FLOAT32_C(    62.19), SIMDE_FLOAT32_C(  -724.50), SIMDE_FLOAT32_C(   254.08), SIMDE_FLOAT32_C(  -506.30),
        SIMDE_FLOAT32_C(  -626.61), SIMDE_FLOAT32_C(   731.45), SIMDE_FLOAT32_C(   990.91), SIMDE_FLOAT32_C(  -588.20),
        SIMDE_FLOAT32_C(   679.30), SIMDE_FLOAT32_C(  -316.73), SIMDE_FLOAT32_C(   432.91), SIMDE_FLOAT32_C(   704.47) } },
    { { SIMDE_FLOAT32_C(   688.09),      SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(  -756.56), SIMDE_FLOAT32_C(  -682.83),
        SIMDE_FLOAT32_C(  -515.96), SIMDE_FLOAT32_C(  -772.36), SIMDE_FLOAT32_C(   284.58), SIMDE_FLOAT32_C(  -730.38),
        SIMDE_FLOAT32_C(   -37.03), SIMDE_FLOAT32_C(   983.52), SIMDE_FLOAT32_C(    54.72), SIMDE_FLOAT32_C(   890.81),
        SIMDE_FLOAT32_C(   814.34), SIMDE_FLOAT32_C(   111.66), SIMDE_FLOAT32_C(   779.03), SIMDE_FLOAT32_C(   349.71) },
       INT32_C(         115),
      { SIMDE_FLOAT32_C(   688.09),      SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(  -756.55), SIMDE_FLOAT32_C(  -682.83),
        SIMDE_FLOAT32_C(  -515.95), SIMDE_FLOAT32_C(  -772.36), SIMDE_FLOAT32_C(   284.58), SIMDE_FLOAT32_C(  -730.38),
        SIMDE_FLOAT32_C(   -37.02), SIMDE_FLOAT32_C(   983.52), SIMDE_FLOAT32_C(    54.72), SIMDE_FLOAT32_C(   890.80),
        SIMDE_FLOAT32_C(   814.34), SIMDE_FLOAT32_C(   111.66), SIMDE_FLOAT32_C(   779.02), SIMDE_FLOAT32_C(   349.70) } },
    { { SIMDE_FLOAT32_C(  -332.43), SIMDE_FLOAT32_C(  -572.08), SIMDE_FLOAT32_C(  -664.74), SIMDE_FLOAT32_C(  -341.53),
        SIMDE_FLOAT32_C(  -160.29), SIMDE_FLOAT32_C(  -985.43), SIMDE_FLOAT32_C(   341.73), SIMDE_FLOAT32_C(  -727.38),
        SIMDE_FLOAT32_C(   719.05), SIMDE_FLOAT32_C(   864.08), SIMDE_FLOAT32_C(   786.71), SIMDE_FLOAT32_C(   565.42),
        SIMDE_FLOAT32_C(   552.17), SIMDE_FLOAT32_C(   878.84), SIMDE_FLOAT32_C(   808.86), SIMDE_FLOAT32_C(   869.34) },
       INT32_C(         131),
      { SIMDE_FLOAT32_C(  -332.43), SIMDE_FLOAT32_C(  -572.08), SIMDE_FLOAT32_C(  -664.74), SIMDE_FLOAT32_C(  -341.53),
        SIMDE_FLOAT32_C(  -160.29), SIMDE_FLOAT32_C(  -985.43), SIMDE_FLOAT32_C(   341.73), SIMDE_FLOAT32_C(  -727.38),
        SIMDE_FLOAT32_C(   719.05), SIMDE_FLOAT32_C(   864.08), SIMDE_FLOAT32_C(   786.71), SIMDE_FLOAT32_C(   565.42),
        SIMDE_FLOAT32_C(   552.17), SIMDE_FLOAT32_C(   878.84), SIMDE_FLOAT32_C(   808.86), SIMDE_FLOAT32_C(   869.34) } },
    { { SIMDE_FLOAT32_C(  -963.49),     -SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(  -367.49), SIMDE_FLOAT32_C(    -0.53),
        SIMDE_FLOAT32_C(   137.44), SIMDE_FLOAT32_C(   687.22), SIMDE_FLOAT32_C(  -109.71), SIMDE_FLOAT32_C(   -48.23),
        SIMDE_FLOAT32_C(  -201.12), SIMDE_FLOAT32_C(  -330.68), SIMDE_FLOAT32_C(  -698.52), SIMDE_FLOAT32_C(   -27.25),
        SIMDE_FLOAT32_C(  -276.14), SIMDE_FLOAT32_C(   -94.71), SIMDE_FLOAT32_C(   640.31), SIMDE_FLOAT32_C(   151.78) },
       INT32_C(         147),
      { SIMDE_FLOAT32_C(  -963.49),     -SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(  -367.49), SIMDE_FLOAT32_C(    -0.53),
        SIMDE_FLOAT32_C(   137.44), SIMDE_FLOAT32_C(   687.22), SIMDE_FLOAT32_C(  -109.71), SIMDE_FLOAT32_C(   -48.23),
        SIMDE_FLOAT32_C(  -201.12), SIMDE_FLOAT32_C(  -330.68), SIMDE_FLOAT32_C(  -698.52), SIMDE_FLOAT32_C(   -27.25),
        SIMDE_FLOAT32_C(  -276.14), SIMDE_FLOAT32_C(   -94.71), SIMDE_FLOAT32_C(   640.31), SIMDE_FLOAT32_C(   151.78) } },
    { { SIMDE_FLOAT32_C(   255.12), SIMDE_FLOAT32_C(   640.51), SIMDE_FLOAT32_C(  -735.90), SIMDE_FLOAT32_C(   -25.83),
        SIMDE_FLOAT32_C(   504.60), SIMDE_FLOAT32_C(  -949.19), SIMDE_FLOAT32_C(  -460.41), SIMDE_FLOAT32_C(    56.77),
        SIMDE_FLOAT32_C(   929.65), SIMDE_FLOAT32_C(  -651.55), SIMDE_FLOAT32_C(   -73.88), SIMDE_FLOAT32_C(  -707.47),
        SIMDE_FLOAT32_C(  -615.04), SIMDE_FLOAT32_C(  -919.96), SIMDE_FLOAT32_C(   -74.97), SIMDE_FLOAT32_C(   384.43) },
       INT32_C(         163),
      { SIMDE_FLOAT32_C(   255.12), SIMDE_FLOAT32_C(   640.51), SIMDE_FLOAT32_C(  -735.90), SIMDE_FLOAT32_C(   -25.83),
        SIMDE_FLOAT32_C(   504.60), SIMDE_FLOAT32_C(  -949.19), SIMDE_FLOAT32_C(  -460.41), SIMDE_FLOAT32_C(    56.77),
        SIMDE_FLOAT32_C(   929.65), SIMDE_FLOAT32_C(  -651.55), SIMDE_FLOAT32_C(   -73.88), SIMDE_FLOAT32_C(  -707.47),
        SIMDE_FLOAT32_C(  -615.04), SIMDE_FLOAT32_C(  -919.96), SIMDE_FLOAT32_C(   -74.97), SIMDE_FLOAT32_C(   384.43) } },
    { { SIMDE_FLOAT32_C(  -387.75), SIMDE_FLOAT32_C(  -725.28), SIMDE_FLOAT32_C(  -830.75), SIMDE_FLOAT32_C(   411.14),
        SIMDE_FLOAT32_C(   -55.96), SIMDE_FLOAT32_C(  -529.27), SIMDE_FLOAT32_C(  -616.12), SIMDE_FLOAT32_C(   667.90),
        SIMDE_FLOAT32_C(   376.02), SIMDE_FLOAT32_C(  -975.81), SIMDE_FLOAT32_C(  -180.33), SIMDE_FLOAT32_C(  -383.43),
        SIMDE_FLOAT32_C(  -677.02), SIMDE_FLOAT32_C(  -188.84), SIMDE_FLOAT32_C(   871.69), SIMDE_FLOAT32_C(   963.49) },
       INT32_C(         179),
      { SIMDE_FLOAT32_C(  -387.75), SIMDE_FLOAT32_C(  -725.28), SIMDE_FLOAT32_C(  -830.75), SIMDE_FLOAT32_C(   411.14),
        SIMDE_FLOAT32_C(   -55.96), SIMDE_FLOAT32_C(  -529.27), SIMDE_FLOAT32_C(  -616.12), SIMDE_FLOAT32_C(   667.90),
        SIMDE_FLOAT32_C(   376.02), SIMDE_FLOAT32_C(  -975.81), SIMDE_FLOAT32_C(  -180.33), SIMDE_FLOAT32_C(  -383.43),
        SIMDE_FLOAT32_C(  -677.02), SIMDE_FLOAT32_C(  -188.84), SIMDE_FLOAT32_C(   871.69), SIMDE_FLOAT32_C(   963.49) } },
    { { SIMDE_FLOAT32_C(  -154.14), SIMDE_FLOAT32_C(   468.09), SIMDE_FLOAT32_C(   126.06), SIMDE_FLOAT32_C(   385.45),
        SIMDE_FLOAT32_C(  -475.14), SIMDE_FLOAT32_C(    55.71), SIMDE_FLOAT32_C(   733.90), SIMDE_FLOAT32_C(   450.97),
        SIMDE_FLOAT32_C(   348.24), SIMDE_FLOAT32_C(  -881.14), SIMDE_FLOAT32_C(   531.01), SIMDE_FLOAT32_C(  -726.72),
        SIMDE_FLOAT32_C(   503.29), SIMDE_FLOAT32_C(  -251.51), SIMDE_FLOAT32_C(  -114.47), SIMDE_FLOAT32_C(   778.01) },
       INT32_C(         195),
      { SIMDE_FLOAT32_C(  -154.14), SIMDE_FLOAT32_C(   468.09), SIMDE_FLOAT32_C(   126.06), SIMDE_FLOAT32_C(   385.45),
        SIMDE_FLOAT32_C(  -475.14), SIMDE_FLOAT32_C(    55.71), SIMDE_FLOAT32_C(   733.90), SIMDE_FLOAT32_C(   450.97),
        SIMDE_FLOAT32_C(   348.24), SIMDE_FLOAT32_C(  -881.14), SIMDE_FLOAT32_C(   531.01), SIMDE_FLOAT32_C(  -726.72),
        SIMDE_FLOAT32_C(   503.29), SIMDE_FLOAT32_C(  -251.51), SIMDE_FLOAT32_C(  -114.47), SIMDE_FLOAT32_C(   778.01) } },
    { { SIMDE_FLOAT32_C(  -703.33),      SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(   388.48), SIMDE_FLOAT32_C(  -319.45),
        SIMDE_FLOAT32_C(  -610.06), SIMDE_FLOAT32_C(  -235.50), SIMDE_FLOAT32_C(  -295.26), SIMDE_FLOAT32_C(   209.61),
        SIMDE_FLOAT32_C(   381.06), SIMDE_FLOAT32_C(    27.72), SIMDE_FLOAT32_C(  -979.23), SIMDE_FLOAT32_C(   252.75),
        SIMDE_FLOAT32_C(    -8.79), SIMDE_FLOAT32_C(    96.02), SIMDE_FLOAT32_C(  -901.38), SIMDE_FLOAT32_C(  -540.71) },
       INT32_C(         211),
      { SIMDE_FLOAT32_C(  -703.33),      SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(   388.48), SIMDE_FLOAT32_C(  -319.45),
        SIMDE_FLOAT32_C(  -610.06), SIMDE_FLOAT32_C(  -235.50), SIMDE_FLOAT32_C(  -295.26), SIMDE_FLOAT32_C(   209.61),
        SIMDE_FLOAT32_C(   381.06), SIMDE_FLOAT32_C(    27.72), SIMDE_FLOAT32_C(  -979.23), SIMDE_FLOAT32_C(   252.75),
        SIMDE_FLOAT32_C(    -8.79), SIMDE_FLOAT32_C(    96.02), SIMDE_FLOAT32_C(  -901.38), SIMDE_FLOAT32_C(  -540.71) } },
    { { SIMDE_FLOAT32_C(   277.80), SIMDE_FLOAT32_C(   217.97), SIMDE_FLOAT32_C(  -564.87), SIMDE_FLOAT32_C(  -373.96),
        SIMDE_FLOAT32_C(   336.83), SIMDE_FLOAT32_C(   966.14), SIMDE_FLOAT32_C(  -100.68), SIMDE_FLOAT32_C(  -159.88),
        SIMDE_FLOAT32_C(  -285.37), SIMDE_FLOAT32_C(   784.85), SIMDE_FLOAT32_C(  -381.87), SIMDE_FLOAT32_C(   632.37),
        SIMDE_FLOAT32_C(  -918.49), SIMDE_FLOAT32_C(   340.17), SIMDE_FLOAT32_C(    20.85), SIMDE_FLOAT32_C(  -237.94) },
       INT32_C(         227),
      { SIMDE_FLOAT32_C(   277.80), SIMDE_FLOAT32_C(   217.97), SIMDE_FLOAT32_C(  -564.87), SIMDE_FLOAT32_C(  -373.96),
        SIMDE_FLOAT32_C(   336.83), SIMDE_FLOAT32_C(   966.14), SIMDE_FLOAT32_C(  -100.68), SIMDE_FLOAT32_C(  -159.88),
        SIMDE_FLOAT32_C(  -285.37), SIMDE_FLOAT32_C(   784.85), SIMDE_FLOAT32_C(  -381.87), SIMDE_FLOAT32_C(   632.37),
        SIMDE_FLOAT32_C(  -918.49), SIMDE_FLOAT32_C(   340.17), SIMDE_FLOAT32_C(    20.85), SIMDE_FLOAT32_C(  -237.94) } },
    { {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   466.81), SIMDE_FLOAT32_C(   -60.28), SIMDE_FLOAT32_C(   166.41),
        SIMDE_FLOAT32_C(  -505.47), SIMDE_FLOAT32_C(   -39.51), SIMDE_FLOAT32_C(  -580.84), SIMDE_FLOAT32_C(   485.73),
        SIMDE_FLOAT32_C(  -943.49), SIMDE_FLOAT32_C(  -482.22), SIMDE_FLOAT32_C(   945.03), SIMDE_FLOAT32_C(  -721.41),
        SIMDE_FLOAT32_C(  -998.15), SIMDE_FLOAT32_C(   -70.82), SIMDE_FLOAT32_C(   556.39), SIMDE_FLOAT32_C(   219.82) },
       INT32_C(         243),
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   466.81), SIMDE_FLOAT32_C(   -60.28), SIMDE_FLOAT32_C(   166.41),
        SIMDE_FLOAT32_C(  -505.47), SIMDE_FLOAT32_C(   -39.51), SIMDE_FLOAT32_C(  -580.84), SIMDE_FLOAT32_C(   485.73),
        SIMDE_FLOAT32_C(  -943.49), SIMDE_FLOAT32_C(  -482.22), SIMDE_FLOAT32_C(   945.03), SIMDE_FLOAT32_C(  -721.41),
        SIMDE_FLOAT32_C(  -998.15), SIMDE_FLOAT32_C(   -70.82), SIMDE_FLOAT32_C(   556.39), SIMDE_FLOAT32_C(   219.82) } },
    { { SIMDE_FLOAT32_C(  -443.36),      SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(    81.75), SIMDE_FLOAT32_C(   396.76),
        SIMDE_FLOAT32_C(  -954.92), SIMDE_FLOAT32_C(  -133.40), SIMDE_FLOAT32_C(  -985.11), SIMDE_FLOAT32_C(   677.45),
        SIMDE_FLOAT32_C(   -51.89), SIMDE_FLOAT32_C(   355.06), SIMDE_FLOAT32_C(  -301.70), SIMDE_FLOAT32_C(   710.17),
        SIMDE_FLOAT32_C(    85.17), SIMDE_FLOAT32_C(  -516.36), SIMDE_FLOAT32_C(   176.98), SIMDE_FLOAT32_C(  -975.12) },
       INT32_C(           4),
      { SIMDE_FLOAT32_C(  -443.00),      SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(    82.00), SIMDE_FLOAT32_C(   397.00),
        SIMDE_FLOAT32_C(  -955.00), SIMDE_FLOAT32_C(  -133.00), SIMDE_FLOAT32_C(  -985.00), SIMDE_FLOAT32_C(   677.00),
        SIMDE_FLOAT32_C(   -52.00), SIMDE_FLOAT32_C(   355.00), SIMDE_FLOAT32_C(  -302.00), SIMDE_FLOAT32_C(   710.00),
        SIMDE_FLOAT32_C(    85.00), SIMDE_FLOAT32_C(  -516.00), SIMDE_FLOAT32_C(   177.00), SIMDE_FLOAT32_C(  -975.00) } },
    { { SIMDE_FLOAT32_C(  -930.79), SIMDE_FLOAT32_C(   157.24), SIMDE_FLOAT32_C(    41.88), SIMDE_FLOAT32_C(  -413.01),
        SIMDE_FLOAT32_C(   102.27), SIMDE_FLOAT32_C(   320.47), SIMDE_FLOAT32_C(  -411.16), SIMDE_FLOAT32_C(  -968.55),
        SIMDE_FLOAT32_C(  -123.14), SIMDE_FLOAT32_C(   808.65), SIMDE_FLOAT32_C(   395.76), SIMDE_FLOAT32_C(    59.29),
        SIMDE_FLOAT32_C(  -634.70), SIMDE_FLOAT32_C(  -273.79), SIMDE_FLOAT32_C(  -858.96), SIMDE_FLOAT32_C(   762.06) },
       INT32_C(          20),
      { SIMDE_FLOAT32_C(  -931.00), SIMDE_FLOAT32_C(   157.00), SIMDE_FLOAT32_C(    42.00), SIMDE_FLOAT32_C(  -413.00),
        SIMDE_FLOAT32_C(   102.50), SIMDE_FLOAT32_C(   320.50), SIMDE_FLOAT32_C(  -411.00), SIMDE_FLOAT32_C(  -968.50),
        SIMDE_FLOAT32_C(  -123.00), SIMDE_FLOAT32_C(   808.50), SIMDE_FLOAT32_C(   396.00), SIMDE_FLOAT32_C(    59.50),
        SIMDE_FLOAT32_C(  -634.50), SIMDE_FLOAT32_C(  -274.00), SIMDE_FLOAT32_C(  -859.00), SIMDE_FLOAT32_C(   762.00) } },
    { { SIMDE_FLOAT32_C(     7.64), SIMDE_FLOAT32_C(   776.95), SIMDE_FLOAT32_C(  -551.26), SIMDE_FLOAT32_C(   955.75),
        SIMDE_FLOAT32_C(   132.00), SIMDE_FLOAT32_C(   147.04), SIMDE_FLOAT32_C(   665.92), SIMDE_FLOAT32_C(  -782.83),
        SIMDE_FLOAT32_C(   630.68), SIMDE_FLOAT32_C(  -157.09), SIMDE_FLOAT32_C(  -757.95), SIMDE_FLOAT32_C(   280.74),
        SIMDE_FLOAT32_C(  -485.59), SIMDE_FLOAT32_C(   227.42), SIMDE_FLOAT32_C(   349.95), SIMDE_FLOAT32_C(   671.66) },
       INT32_C(          36),
      { SIMDE_FLOAT32_C(     7.75), SIMDE_FLOAT32_C(   777.00), SIMDE_FLOAT32_C(  -551.25), SIMDE_FLOAT32_C(   955.75),
        SIMDE_FLOAT32_C(   132.00), SIMDE_FLOAT32_C(   147.00), SIMDE_FLOAT32_C(   666.00), SIMDE_FLOAT32_C(  -782.75),
        SIMDE_FLOAT32_C(   630.75), SIMDE_FLOAT32_C(  -157.00), SIMDE_FLOAT32_C(  -758.00), SIMDE_FLOAT32_C(   280.75),
        SIMDE_FLOAT32_C(  -485.50), SIMDE_FLOAT32_C(   227.50), SIMDE_FLOAT32_C(   350.00), SIMDE_FLOAT32_C(   671.75) } },
    { { SIMDE_FLOAT32_C(   936.94), SIMDE_FLOAT32_C(  -226.08), SIMDE_FLOAT32_C(   589.77), SIMDE_FLOAT32_C(  -474.23),
        SIMDE_FLOAT32_C(  -194.62), SIMDE_FLOAT32_C(  -533.37), SIMDE_FLOAT32_C(  -665.57), SIMDE_FLOAT32_C(  -798.86),
        SIMDE_FLOAT32_C(   525.93), SIMDE_FLOAT32_C(  -300.28), SIMDE_FLOAT32_C(   -72.65), SIMDE_FLOAT32_C(   666.97),
        SIMDE_FLOAT32_C(  -538.22), SIMDE_FLOAT32_C(   698.63), SIMDE_FLOAT32_C(  -325.39), SIMDE_FLOAT32_C(  -761.27) },
       INT32_C(          52),
      { SIMDE_FLOAT32_C(   937.00), SIMDE_FLOAT32_C(  -226.12), SIMDE_FLOAT32_C(   589.75), SIMDE_FLOAT32_C(  -474.25),
        SIMDE_FLOAT32_C(  -194.62), SIMDE_FLOAT32_C(  -533.38), SIMDE_FLOAT32_C(  -665.62), SIMDE_FLOAT32_C(  -798.88),
        SIMDE_FLOAT32_C(   525.88), SIMDE_FLOAT32_C(  -300.25), SIMDE_FLOAT32_C(   -72.62), SIMDE_FLOAT32_C(   667.00),
        SIMDE_FLOAT32_C(  -538.25), SIMDE_FLOAT32_C(   698.62), SIMDE_FLOAT32_C(  -325.38), SIMDE_FLOAT32_C(  -761.25) } },
    { { SIMDE_FLOAT32_C(  -369.64), SIMDE_FLOAT32_C(   370.73), SIMDE_FLOAT32_C(   294.42), SIMDE_FLOAT32_C(  -703.72),
        SIMDE_FLOAT32_C(   587.90), SIMDE_FLOAT32_C(   -74.90), SIMDE_FLOAT32_C(   139.19), SIMDE_FLOAT32_C(   829.95),
        SIMDE_FLOAT32_C(  -794.16), SIMDE_FLOAT32_C(   653.60), SIMDE_FLOAT32_C(    57.38), SIMDE_FLOAT32_C(   555.79),
        SIMDE_FLOAT32_C(   325.26), SIMDE_FLOAT32_C(   326.68), SIMDE_FLOAT32_C(   492.72), SIMDE_FLOAT32_C(  -900.82) },
       INT32_C(          68),
      { SIMDE_FLOAT32_C(  -369.62), SIMDE_FLOAT32_C(   370.75), SIMDE_FLOAT32_C(   294.44), SIMDE_FLOAT32_C(  -703.75),
        SIMDE_FLOAT32_C(   587.88), SIMDE_FLOAT32_C(   -74.88), SIMDE_FLOAT32_C(   139.19), SIMDE_FLOAT32_C(   829.94),
        SIMDE_FLOAT32_C(  -794.19), SIMDE_FLOAT32_C(   653.62), SIMDE_FLOAT32_C(    57.38), SIMDE_FLOAT32_C(   555.81),
        SIMDE_FLOAT32_C(   325.25), SIMDE_FLOAT32_C(   326.69), SIMDE_FLOAT32_C(   492.75), SIMDE_FLOAT32_C(  -900.81) } },
    { { SIMDE_FLOAT32_C(  -981.50), SIMDE_FLOAT32_C(   -95.44), SIMDE_FLOAT32_C(   383.09), SIMDE_FLOAT32_C(  -647.07),
        SIMDE_FLOAT32_C(   105.69), SIMDE_FLOAT32_C(   -90.98), SIMDE_FLOAT32_C(    52.65), SIMDE_FLOAT32_C(  -966.96),
        SIMDE_FLOAT32_C(  -424.01), SIMDE_FLOAT32_C(   514.43), SIMDE_FLOAT32_C(   731.68), SIMDE_FLOAT32_C(   250.60),
        SIMDE_FLOAT32_C(   753.15), SIMDE_FLOAT32_C(   879.05), SIMDE_FLOAT32_C(   880.96), SIMDE_FLOAT32_C(   123.88) },
       INT32_C(          84),
      { SIMDE_FLOAT32_C(  -981.50), SIMDE_FLOAT32_C(   -95.44), SIMDE_FLOAT32_C(   383.09), SIMDE_FLOAT32_C(  -647.06),
        SIMDE_FLOAT32_C(   105.69), SIMDE_FLOAT32_C(   -90.97), SIMDE_FLOAT32_C(    52.66), SIMDE_FLOAT32_C(  -966.97),
        SIMDE_FLOAT32_C(  -424.00), SIMDE_FLOAT32_C(   514.44), SIMDE_FLOAT32_C(   731.69), SIMDE_FLOAT32_C(   250.59),
        SIMDE_FLOAT32_C(   753.16), SIMDE_FLOAT32_C(   879.06), SIMDE_FLOAT32_C(   880.97), SIMDE_FLOAT32_C(   123.88) } },
    { {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -288.22), SIMDE_FLOAT32_C(  -901.43), SIMDE_FLOAT32_C(   316.43),
        SIMDE_FLOAT32_C(  -458.27), SIMDE_FLOAT32_C(  -695.59), SIMDE_FLOAT32_C(   -29.97), SIMDE_FLOAT32_C(   599.11),
        SIMDE_FLOAT32_C(   860.20), SIMDE_FLOAT32_C(  -704.71), SIMDE_FLOAT32_C(   -74.21), SIMDE_FLOAT32_C(   352.92),
        SIMDE_FLOAT32_C(  -605.53), SIMDE_FLOAT32_C(   842.24), SIMDE_FLOAT32_C(   371.42), SIMDE_FLOAT32_C(   299.03) },
       INT32_C(         100),
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -288.22), SIMDE_FLOAT32_C(  -901.44), SIMDE_FLOAT32_C(   316.44),
        SIMDE_FLOAT32_C(  -458.27), SIMDE_FLOAT32_C(  -695.59), SIMDE_FLOAT32_C(   -29.97), SIMDE_FLOAT32_C(   599.11),
        SIMDE_FLOAT32_C(   860.20), SIMDE_FLOAT32_C(  -704.70), SIMDE_FLOAT32_C(   -74.20), SIMDE_FLOAT32_C(   352.92),
        SIMDE_FLOAT32_C(  -605.53), SIMDE_FLOAT32_C(   842.23), SIMDE_FLOAT32_C(   371.42), SIMDE_FLOAT32_C(   299.03) } },
    { {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -865.66), SIMDE_FLOAT32_C(  -223.00), SIMDE_FLOAT32_C(  -562.24),
        SIMDE_FLOAT32_C(  -289.67), SIMDE_FLOAT32_C(  -708.58), SIMDE_FLOAT32_C(  -830.56), SIMDE_FLOAT32_C(   960.93),
        SIMDE_FLOAT32_C(  -955.42), SIMDE_FLOAT32_C(  -951.51), SIMDE_FLOAT32_C(   841.88), SIMDE_FLOAT32_C(   168.46),
        SIMDE_FLOAT32_C(   221.96), SIMDE_FLOAT32_C(  -980.88), SIMDE_FLOAT32_C(   880.24), SIMDE_FLOAT32_C(   320.54) },
       INT32_C(         116),
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -865.66), SIMDE_FLOAT32_C(  -223.00), SIMDE_FLOAT32_C(  -562.24),
        SIMDE_FLOAT32_C(  -289.67), SIMDE_FLOAT32_C(  -708.58), SIMDE_FLOAT32_C(  -830.56), SIMDE_FLOAT32_C(   960.93),
        SIMDE_FLOAT32_C(  -955.42), SIMDE_FLOAT32_C(  -951.51), SIMDE_FLOAT32_C(   841.88), SIMDE_FLOAT32_C(   168.46),
        SIMDE_FLOAT32_C(   221.96), SIMDE_FLOAT32_C(  -980.88), SIMDE_FLOAT32_C(   880.24), SIMDE_FLOAT32_C(   320.54) } },
    { {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -694.42), SIMDE_FLOAT32_C(  -978.91), SIMDE_FLOAT32_C(   485.15),
        SIMDE_FLOAT32_C(  -399.13), SIMDE_FLOAT32_C(   -53.12), SIMDE_FLOAT32_C(  -161.93), SIMDE_FLOAT32_C(    -4.66),
        SIMDE_FLOAT32_C(  -210.88), SIMDE_FLOAT32_C(  -790.51), SIMDE_FLOAT32_C(  -705.63), SIMDE_FLOAT32_C(  -985.55),
        SIMDE_FLOAT32_C(   933.84), SIMDE_FLOAT32_C(  -300.91), SIMDE_FLOAT32_C(  -851.20), SIMDE_FLOAT32_C(  -289.16) },
       INT32_C(         132),
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -694.42), SIMDE_FLOAT32_C(  -978.91), SIMDE_FLOAT32_C(   485.15),
        SIMDE_FLOAT32_C(  -399.13), SIMDE_FLOAT32_C(   -53.12), SIMDE_FLOAT32_C(  -161.93), SIMDE_FLOAT32_C(    -4.66),
        SIMDE_FLOAT32_C(  -210.88), SIMDE_FLOAT32_C(  -790.51), SIMDE_FLOAT32_C(  -705.63), SIMDE_FLOAT32_C(  -985.55),
        SIMDE_FLOAT32_C(   933.84), SIMDE_FLOAT32_C(  -300.91), SIMDE_FLOAT32_C(  -851.20), SIMDE_FLOAT32_C(  -289.16) } },
    { { SIMDE_FLOAT32_C(     2.27), SIMDE_FLOAT32_C(   306.30), SIMDE_FLOAT32_C(  -179.94), SIMDE_FLOAT32_C(    46.84),
        SIMDE_FLOAT32_C(   354.79), SIMDE_FLOAT32_C(  -338.06), SIMDE_FLOAT32_C(  -784.70), SIMDE_FLOAT32_C(  -423.25),
        SIMDE_FLOAT32_C(  -318.93), SIMDE_FLOAT32_C(  -904.45), SIMDE_FLOAT32_C(   897.29), SIMDE_FLOAT32_C(  -983.38),
        SIMDE_FLOAT32_C(  -482.48), SIMDE_FLOAT32_C(   522.24), SIMDE_FLOAT32_C(  -677.80), SIMDE_FLOAT32_C(  -461.39) },
       INT32_C(         148),
      { SIMDE_FLOAT32_C(     2.27), SIMDE_FLOAT32_C(   306.30), SIMDE_FLOAT32_C(  -179.94), SIMDE_FLOAT32_C(    46.84),
        SIMDE_FLOAT32_C(   354.79), SIMDE_FLOAT32_C(  -338.06), SIMDE_FLOAT32_C(  -784.70), SIMDE_FLOAT32_C(  -423.25),
        SIMDE_FLOAT32_C(  -318.93), SIMDE_FLOAT32_C(  -904.45), SIMDE_FLOAT32_C(   897.29), SIMDE_FLOAT32_C(  -983.38),
        SIMDE_FLOAT32_C(  -482.48), SIMDE_FLOAT32_C(   522.24), SIMDE_FLOAT32_C(  -677.80), SIMDE_FLOAT32_C(  -461.39) } },
    { { SIMDE_FLOAT32_C(   -76.93),      SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(   845.45), SIMDE_FLOAT32_C(   918.41),
        SIMDE_FLOAT32_C(  -725.38), SIMDE_FLOAT32_C(  -945.05), SIMDE_FLOAT32_C(  -787.22), SIMDE_FLOAT32_C(  -710.93),
        SIMDE_FLOAT32_C(   988.79), SIMDE_FLOAT32_C(   -88.13), SIMDE_FLOAT32_C(  -562.13), SIMDE_FLOAT32_C(  -300.37),
        SIMDE_FLOAT32_C(  -951.27), SIMDE_FLOAT32_C(   297.00), SIMDE_FLOAT32_C(   701.89), SIMDE_FLOAT32_C(   355.03) },
       INT32_C(         164),
      { SIMDE_FLOAT32_C(   -76.93),      SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(   845.45), SIMDE_FLOAT32_C(   918.41),
        SIMDE_FLOAT32_C(  -725.38), SIMDE_FLOAT32_C(  -945.05), SIMDE_FLOAT32_C(  -787.22), SIMDE_FLOAT32_C(  -710.93),
        SIMDE_FLOAT32_C(   988.79), SIMDE_FLOAT32_C(   -88.13), SIMDE_FLOAT32_C(  -562.13), SIMDE_FLOAT32_C(  -300.37),
        SIMDE_FLOAT32_C(  -951.27), SIMDE_FLOAT32_C(   297.00), SIMDE_FLOAT32_C(   701.89), SIMDE_FLOAT32_C(   355.03) } },
    { { SIMDE_FLOAT32_C(  -221.00),     -SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(   286.57), SIMDE_FLOAT32_C(   460.07),
        SIMDE_FLOAT32_C(    59.59), SIMDE_FLOAT32_C(   183.86), SIMDE_FLOAT32_C(   476.68), SIMDE_FLOAT32_C(   577.11),
        SIMDE_FLOAT32_C(  -293.90), SIMDE_FLOAT32_C(   798.88), SIMDE_FLOAT32_C(  -884.27), SIMDE_FLOAT32_C(   713.48),
        SIMDE_FLOAT32_C(  -278.04), SIMDE_FLOAT32_C(   601.22), SIMDE_FLOAT32_C(   558.93), SIMDE_FLOAT32_C(  -359.63) },
       INT32_C(         180),
      { SIMDE_FLOAT32_C(  -221.00),     -SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(   286.57), SIMDE_FLOAT32_C(   460.07),
        SIMDE_FLOAT32_C(    59.59), SIMDE_FLOAT32_C(   183.86), SIMDE_FLOAT32_C(   476.68), SIMDE_FLOAT32_C(   577.11),
        SIMDE_FLOAT32_C(  -293.90), SIMDE_FLOAT32_C(   798.88), SIMDE_FLOAT32_C(  -884.27), SIMDE_FLOAT32_C(   713.48),
        SIMDE_FLOAT32_C(  -278.04), SIMDE_FLOAT32_C(   601.22), SIMDE_FLOAT32_C(   558.93), SIMDE_FLOAT32_C(  -359.63) } },
    { { SIMDE_FLOAT32_C(  -835.10), SIMDE_FLOAT32_C(   602.67), SIMDE_FLOAT32_C(   765.02), SIMDE_FLOAT32_C(  -397.23),
        SIMDE_FLOAT32_C(  -697.70), SIMDE_FLOAT32_C(   813.75), SIMDE_FLOAT32_C(   899.77), SIMDE_FLOAT32_C(  -995.81),
        SIMDE_FLOAT32_C(   168.78), SIMDE_FLOAT32_C(  -983.18), SIMDE_FLOAT32_C(  -247.07), SIMDE_FLOAT32_C(   878.60),
        SIMDE_FLOAT32_C(  -204.18), SIMDE_FLOAT32_C(   716.97), SIMDE_FLOAT32_C(   165.17), SIMDE_FLOAT32_C(  -744.11) },
       INT32_C(         196),
      { SIMDE_FLOAT32_C(  -835.10), SIMDE_FLOAT32_C(   602.67), SIMDE_FLOAT32_C(   765.02), SIMDE_FLOAT32_C(  -397.23),
        SIMDE_FLOAT32_C(  -697.70), SIMDE_FLOAT32_C(   813.75), SIMDE_FLOAT32_C(   899.77), SIMDE_FLOAT32_C(  -995.81),
        SIMDE_FLOAT32_C(   168.78), SIMDE_FLOAT32_C(  -983.18), SIMDE_FLOAT32_C(  -247.07), SIMDE_FLOAT32_C(   878.60),
        SIMDE_FLOAT32_C(  -204.18), SIMDE_FLOAT32_C(   716.97), SIMDE_FLOAT32_C(   165.17), SIMDE_FLOAT32_C(  -744.11) } },
    { { SIMDE_FLOAT32_C(  -650.97), SIMDE_FLOAT32_C(   732.57), SIMDE_FLOAT32_C(  -646.33), SIMDE_FLOAT32_C(    55.13),
        SIMDE_FLOAT32_C(   531.45), SIMDE_FLOAT32_C(  -530.61), SIMDE_FLOAT32_C(  -231.39), SIMDE_FLOAT32_C(  -746.59),
        SIMDE_FLOAT32_C(  -929.39), SIMDE_FLOAT32_C(  -672.46), SIMDE_FLOAT32_C(  -106.23), SIMDE_FLOAT32_C(   946.45),
        SIMDE_FLOAT32_C(   941.42), SIMDE_FLOAT32_C(   746.92), SIMDE_FLOAT32_C(  -888.65), SIMDE_FLOAT32_C(   544.09) },
       INT32_C(         212),
      { SIMDE_FLOAT32_C(  -650.97), SIMDE_FLOAT32_C(   732.57), SIMDE_FLOAT32_C(  -646.33), SIMDE_FLOAT32_C(    55.13),
        SIMDE_FLOAT32_C(   531.45), SIMDE_FLOAT32_C(  -530.61), SIMDE_FLOAT32_C(  -231.39), SIMDE_FLOAT32_C(  -746.59),
        SIMDE_FLOAT32_C(  -929.39), SIMDE_FLOAT32_C(  -672.46), SIMDE_FLOAT32_C(  -106.23), SIMDE_FLOAT32_C(   946.45),
        SIMDE_FLOAT32_C(   941.42), SIMDE_FLOAT32_C(   746.92), SIMDE_FLOAT32_C(  -888.65), SIMDE_FLOAT32_C(   544.09) } },
    { { SIMDE_FLOAT32_C(  -285.88),     -SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(   325.68), SIMDE_FLOAT32_C(  -386.11),
        SIMDE_FLOAT32_C(   850.57), SIMDE_FLOAT32_C(  -505.54), SIMDE_FLOAT32_C(  -369.29), SIMDE_FLOAT32_C(  -396.50),
        SIMDE_FLOAT32_C(  -626.94), SIMDE_FLOAT32_C(   426.53), SIMDE_FLOAT32_C(  -679.53), SIMDE_FLOAT32_C(   538.23),
        SIMDE_FLOAT32_C(   682.42), SIMDE_FLOAT32_C(    97.02), SIMDE_FLOAT32_C(   887.26), SIMDE_FLOAT32_C(   414.99) },
       INT32_C(         228),
      { SIMDE_FLOAT32_C(  -285.88),     -SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(   325.68), SIMDE_FLOAT32_C(  -386.11),
        SIMDE_FLOAT32_C(   850.57), SIMDE_FLOAT32_C(  -505.54), SIMDE_FLOAT32_C(  -369.29), SIMDE_FLOAT32_C(  -396.50),
        SIMDE_FLOAT32_C(  -626.94), SIMDE_FLOAT32_C(   426.53), SIMDE_FLOAT32_C(  -679.53), SIMDE_FLOAT32_C(   538.23),
        SIMDE_FLOAT32_C(   682.42), SIMDE_FLOAT32_C(    97.02), SIMDE_FLOAT32_C(   887.26), SIMDE_FLOAT32_C(   414.99) } },
    { { SIMDE_FLOAT32_C(   920.08), SIMDE_FLOAT32_C(   711.00), SIMDE_FLOAT32_C(   199.85), SIMDE_FLOAT32_C(   990.70),
        SIMDE_FLOAT32_C(  -961.46), SIMDE_FLOAT32_C(  -906.37), SIMDE_FLOAT32_C(   937.15), SIMDE_FLOAT32_C(   979.97),
        SIMDE_FLOAT32_C(   840.55), SIMDE_FLOAT32_C(  -951.50), SIMDE_FLOAT32_C(   524.06), SIMDE_FLOAT32_C(   352.48),
        SIMDE_FLOAT32_C(  -237.38), SIMDE_FLOAT32_C(   370.44), SIMDE_FLOAT32_C(  -321.83), SIMDE_FLOAT32_C(   376.51) },
       INT32_C(         244),
      { SIMDE_FLOAT32_C(   920.08), SIMDE_FLOAT32_C(   711.00), SIMDE_FLOAT32_C(   199.85), SIMDE_FLOAT32_C(   990.70),
        SIMDE_FLOAT32_C(  -961.46), SIMDE_FLOAT32_C(  -906.37), SIMDE_FLOAT32_C(   937.15), SIMDE_FLOAT32_C(   979.97),
        SIMDE_FLOAT32_C(   840.55), SIMDE_FLOAT32_C(  -951.50), SIMDE_FLOAT32_C(   524.06), SIMDE_FLOAT32_C(   352.48),
        SIMDE_FLOAT32_C(  -237.38), SIMDE_FLOAT32_C(   370.44), SIMDE_FLOAT32_C(  -321.83), SIMDE_FLOAT32_C(   376.51) } },
  };

  simde__m512 a, r;

  a = simde_mm512_loadu_ps(test_vec[0].a);
  r = simde_mm512_roundscale_ps(a, INT32_C(           0));
  simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[0].r), 1);

  a = simde_mm512_loadu_ps(test_vec[1].a);
  r = simde_mm512_roundscale_ps(a, INT32_C(          16));
  simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[1].r), 1);

  a = simde_mm512_loadu_ps(test_vec[2].a);
  r = simde_mm512_roundscale_ps(a, INT32_C(          32));
  simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[2].r), 1);

  a = simde_mm512_loadu_ps(test_vec[3].a);
  r = simde_mm512_roundscale_ps(a, INT32_C(          48));
  simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[3].r), 1);

  a = simde_mm512_loadu_ps(test_vec[4].a);
  r = simde_mm512_roundscale_ps(a, INT32_C(          64));
  simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[4].r), 1);

  a = simde_mm512_loadu_ps(test_vec[5].a);
  r = simde_mm512_roundscale_ps(a, INT32_C(          80));
  simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[5].r), 1);

  a = simde_mm512_loadu_ps(test_vec[6].a);
  r = simde_mm512_roundscale_ps(a, INT32_C(          96));
  simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[6].r), 1);

  a = simde_mm512_loadu_ps(test_vec[7].a);
  r = simde_mm512_roundscale_ps(a, INT32_C(         112));
  simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[7].r), 1);

  a = simde_mm512_loadu_ps(test_vec[8].a);
  r = simde_mm512_roundscale_ps(a, INT32_C(         128));
  simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[8].r), 1);

  a = simde_mm512_loadu_ps(test_vec[9].a);
  r = simde_mm512_roundscale_ps(a, INT32_C(         144));
  simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[9].r), 1);

  a = simde_mm512_loadu_ps(test_vec[10].a);
  r = simde_mm512_roundscale_ps(a, INT32_C(         160));
  simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[10].r), 1);

  a = simde_mm512_loadu_ps(test_vec[11].a);
  r = simde_mm512_roundscale_ps(a, INT32_C(         176));
  simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[11].r), 1);

  a = simde_mm512_loadu_ps(test_vec[12].a);
  r = simde_mm512_roundscale_ps(a, INT32_C(         192));
  simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[12].r), 1);

  a = simde_mm512_loadu_ps(test_vec[13].a);
  r = simde_mm512_roundscale_ps(a, INT32_C(         208));
  simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[13].r), 1);

  a = simde_mm512_loadu_ps(test_vec[14].a);
  r = simde_mm512_roundscale_ps(a, INT32_C(         224));
  simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[14].r), 1);

  a = simde_mm512_loadu_ps(test_vec[15].a);
  r = simde_mm512_roundscale_ps(a, INT32_C(         240));
  simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[15].r), 1);

  a = simde_mm512_loadu_ps(test_vec[16].a);
  r = simde_mm512_roundscale_ps(a, INT32_C(           1));
  simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[16].r), 1);

  a = simde_mm512_loadu_ps(test_vec[17].a);
  r = simde_mm512_roundscale_ps(a, INT32_C(          17));
  simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[17].r), 1);

  a = simde_mm512_loadu_ps(test_vec[18].a);
  r = simde_mm512_roundscale_ps(a, INT32_C(          33));
  simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[18].r), 1);

  a = simde_mm512_loadu_ps(test_vec[19].a);
  r = simde_mm512_roundscale_ps(a, INT32_C(          49));
  simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[19].r), 1);

  a = simde_mm512_loadu_ps(test_vec[20].a);
  r = simde_mm512_roundscale_ps(a, INT32_C(          65));
  simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[20].r), 1);

  a = simde_mm512_loadu_ps(test_vec[21].a);
  r = simde_mm512_roundscale_ps(a, INT32_C(          81));
  simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[21].r), 1);

  a = simde_mm512_loadu_ps(test_vec[22].a);
  r = simde_mm512_roundscale_ps(a, INT32_C(          97));
  simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[22].r), 1);

  a = simde_mm512_loadu_ps(test_vec[23].a);
  r = simde_mm512_roundscale_ps(a, INT32_C(         113));
  simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[23].r), 1);

  a = simde_mm512_loadu_ps(test_vec[24].a);
  r = simde_mm512_roundscale_ps(a, INT32_C(         129));
  simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[24].r), 1);

  a = simde_mm512_loadu_ps(test_vec[25].a);
  r = simde_mm512_roundscale_ps(a, INT32_C(         145));
  simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[25].r), 1);

  a = simde_mm512_loadu_ps(test_vec[26].a);
  r = simde_mm512_roundscale_ps(a, INT32_C(         161));
  simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[26].r), 1);

  a = simde_mm512_loadu_ps(test_vec[27].a);
  r = simde_mm512_roundscale_ps(a, INT32_C(         177));
  simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[27].r), 1);

  a = simde_mm512_loadu_ps(test_vec[28].a);
  r = simde_mm512_roundscale_ps(a, INT32_C(         193));
  simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[28].r), 1);

  a = simde_mm512_loadu_ps(test_vec[29].a);
  r = simde_mm512_roundscale_ps(a, INT32_C(         209));
  simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[29].r), 1);

  a = simde_mm512_loadu_ps(test_vec[30].a);
  r = simde_mm512_roundscale_ps(a, INT32_C(         225));
  simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[30].r), 1);

  a = simde_mm512_loadu_ps(test_vec[31].a);
  r = simde_mm512_roundscale_ps(a, INT32_C(         241));
  simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[31].r), 1);

  a = simde_mm512_loadu_ps(test_vec[32].a);
  r = simde_mm512_roundscale_ps(a, INT32_C(           2));
  simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[32].r), 1);

  a = simde_mm512_loadu_ps(test_vec[33].a);
  r = simde_mm512_roundscale_ps(a, INT32_C(          18));
  simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[33].r), 1);

  a = simde_mm512_loadu_ps(test_vec[34].a);
  r = simde_mm512_roundscale_ps(a, INT32_C(          34));
  simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[34].r), 1);

  a = simde_mm512_loadu_ps(test_vec[35].a);
  r = simde_mm512_roundscale_ps(a, INT32_C(          50));
  simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[35].r), 1);

  a = simde_mm512_loadu_ps(test_vec[36].a);
  r = simde_mm512_roundscale_ps(a, INT32_C(          66));
  simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[36].r), 1);

  a = simde_mm512_loadu_ps(test_vec[37].a);
  r = simde_mm512_roundscale_ps(a, INT32_C(          82));
  simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[37].r), 1);

  a = simde_mm512_loadu_ps(test_vec[38].a);
  r = simde_mm512_roundscale_ps(a, INT32_C(          98));
  simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[38].r), 1);

  a = simde_mm512_loadu_ps(test_vec[39].a);
  r = simde_mm512_roundscale_ps(a, INT32_C(         114));
  simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[39].r), 1);

  a = simde_mm512_loadu_ps(test_vec[40].a);
  r = simde_mm512_roundscale_ps(a, INT32_C(         130));
  simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[40].r), 1);

  a = simde_mm512_loadu_ps(test_vec[41].a);
  r = simde_mm512_roundscale_ps(a, INT32_C(         146));
  simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[41].r), 1);

  a = simde_mm512_loadu_ps(test_vec[42].a);
  r = simde_mm512_roundscale_ps(a, INT32_C(         162));
  simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[42].r), 1);

  a = simde_mm512_loadu_ps(test_vec[43].a);
  r = simde_mm512_roundscale_ps(a, INT32_C(         178));
  simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[43].r), 1);

  a = simde_mm512_loadu_ps(test_vec[44].a);
  r = simde_mm512_roundscale_ps(a, INT32_C(         194));
  simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[44].r), 1);

  a = simde_mm512_loadu_ps(test_vec[45].a);
  r = simde_mm512_roundscale_ps(a, INT32_C(         210));
  simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[45].r), 1);

  a = simde_mm512_loadu_ps(test_vec[46].a);
  r = simde_mm512_roundscale_ps(a, INT32_C(         226));
  simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[46].r), 1);

  a = simde_mm512_loadu_ps(test_vec[47].a);
  r = simde_mm512_roundscale_ps(a, INT32_C(         242));
  simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[47].r), 1);

  a = simde_mm512_loadu_ps(test_vec[48].a);
  r = simde_mm512_roundscale_ps(a, INT32_C(           3));
  simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[48].r), 1);

  a = simde_mm512_loadu_ps(test_vec[49].a);
  r = simde_mm512_roundscale_ps(a, INT32_C(          19));
  simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[49].r), 1);

  a = simde_mm512_loadu_ps(test_vec[50].a);
  r = simde_mm512_roundscale_ps(a, INT32_C(          35));
  simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[50].r), 1);

  a = simde_mm512_loadu_ps(test_vec[51].a);
  r = simde_mm512_roundscale_ps(a, INT32_C(          51));
  simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[51].r), 1);

  a = simde_mm512_loadu_ps(test_vec[52].a);
  r = simde_mm512_roundscale_ps(a, INT32_C(          67));
  simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[52].r), 1);

  a = simde_mm512_loadu_ps(test_vec[53].a);
  r = simde_mm512_roundscale_ps(a, INT32_C(          83));
  simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[53].r), 1);

  a = simde_mm512_loadu_ps(test_vec[54].a);
  r = simde_mm512_roundscale_ps(a, INT32_C(          99));
  simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[54].r), 1);

  a = simde_mm512_loadu_ps(test_vec[55].a);
  r = simde_mm512_roundscale_ps(a, INT32_C(         115));
  simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[55].r), 1);

  a = simde_mm512_loadu_ps(test_vec[56].a);
  r = simde_mm512_roundscale_ps(a, INT32_C(         131));
  simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[56].r), 1);

  a = simde_mm512_loadu_ps(test_vec[57].a);
  r = simde_mm512_roundscale_ps(a, INT32_C(         147));
  simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[57].r), 1);

  a = simde_mm512_loadu_ps(test_vec[58].a);
  r = simde_mm512_roundscale_ps(a, INT32_C(         163));
  simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[58].r), 1);

  a = simde_mm512_loadu_ps(test_vec[59].a);
  r = simde_mm512_roundscale_ps(a, INT32_C(         179));
  simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[59].r), 1);

  a = simde_mm512_loadu_ps(test_vec[60].a);
  r = simde_mm512_roundscale_ps(a, INT32_C(         195));
  simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[60].r), 1);

  a = simde_mm512_loadu_ps(test_vec[61].a);
  r = simde_mm512_roundscale_ps(a, INT32_C(         211));
  simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[61].r), 1);

  a = simde_mm512_loadu_ps(test_vec[62].a);
  r = simde_mm512_roundscale_ps(a, INT32_C(         227));
  simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[62].r), 1);

  a = simde_mm512_loadu_ps(test_vec[63].a);
  r = simde_mm512_roundscale_ps(a, INT32_C(         243));
  simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[63].r), 1);

  a = simde_mm512_loadu_ps(test_vec[64].a);
  r = simde_mm512_roundscale_ps(a, INT32_C(           4));
  simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[64].r), 1);

  a = simde_mm512_loadu_ps(test_vec[65].a);
  r = simde_mm512_roundscale_ps(a, INT32_C(          20));
  simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[65].r), 1);

  a = simde_mm512_loadu_ps(test_vec[66].a);
  r = simde_mm512_roundscale_ps(a, INT32_C(          36));
  simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[66].r), 1);

  a = simde_mm512_loadu_ps(test_vec[67].a);
  r = simde_mm512_roundscale_ps(a, INT32_C(          52));
  simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[67].r), 1);

  a = simde_mm512_loadu_ps(test_vec[68].a);
  r = simde_mm512_roundscale_ps(a, INT32_C(          68));
  simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[68].r), 1);

  a = simde_mm512_loadu_ps(test_vec[69].a);
  r = simde_mm512_roundscale_ps(a, INT32_C(          84));
  simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[69].r), 1);

  a = simde_mm512_loadu_ps(test_vec[70].a);
  r = simde_mm512_roundscale_ps(a, INT32_C(         100));
  simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[70].r), 1);

  a = simde_mm512_loadu_ps(test_vec[71].a);
  r = simde_mm512_roundscale_ps(a, INT32_C(         116));
  simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[71].r), 1);

  a = simde_mm512_loadu_ps(test_vec[72].a);
  r = simde_mm512_roundscale_ps(a, INT32_C(         132));
  simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[72].r), 1);

  a = simde_mm512_loadu_ps(test_vec[73].a);
  r = simde_mm512_roundscale_ps(a, INT32_C(         148));
  simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[73].r), 1);

  a = simde_mm512_loadu_ps(test_vec[74].a);
  r = simde_mm512_roundscale_ps(a, INT32_C(         164));
  simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[74].r), 1);

  a = simde_mm512_loadu_ps(test_vec[75].a);
  r = simde_mm512_roundscale_ps(a, INT32_C(         180));
  simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[75].r), 1);

  a = simde_mm512_loadu_ps(test_vec[76].a);
  r = simde_mm512_roundscale_ps(a, INT32_C(         196));
  simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[76].r), 1);

  a = simde_mm512_loadu_ps(test_vec[77].a);
  r = simde_mm512_roundscale_ps(a, INT32_C(         212));
  simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[77].r), 1);

  a = simde_mm512_loadu_ps(test_vec[78].a);
  r = simde_mm512_roundscale_ps(a, INT32_C(         228));
  simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[78].r), 1);

  a = simde_mm512_loadu_ps(test_vec[79].a);
  r = simde_mm512_roundscale_ps(a, INT32_C(         244));
  simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[79].r), 1);

  return 0;
#else
  fputc('\n', stdout);
  int round_type[5] = {SIMDE_MM_FROUND_TO_NEAREST_INT, SIMDE_MM_FROUND_TO_NEG_INF, SIMDE_MM_FROUND_TO_POS_INF, SIMDE_MM_FROUND_TO_ZERO, SIMDE_MM_FROUND_CUR_DIRECTION};
  for (int i = 0 ; i < 5 ; i++) {
    for (int j = 0 ; j < 16 ; j++) {
      simde__m512 a = simde_test_x86_random_f32x16(SIMDE_FLOAT32_C(-1000.0), SIMDE_FLOAT32_C(1000.0));
      if((simde_test_codegen_rand() & 1)) {
        if((simde_test_codegen_rand() & 1))
          a = simde_mm512_mask_mov_ps(a, 1, simde_mm512_set1_ps(SIMDE_MATH_NANF));
        else {
          if((simde_test_codegen_rand() & 1))
            a = simde_mm512_mask_mov_ps(a, 2, simde_mm512_set1_ps(SIMDE_MATH_INFINITY));
          else
            a = simde_mm512_mask_mov_ps(a, 2, simde_mm512_set1_ps(-SIMDE_MATH_INFINITY));
        }
      }
      int imm8 = ((j << 4) | round_type[i]) & 255;
      simde__m512 r;
      SIMDE_CONSTIFY_256_(simde_mm512_roundscale_ps, r, simde_mm512_setzero_ps(), imm8, a);

      simde_test_x86_write_f32x16(2, a, SIMDE_TEST_VEC_POS_FIRST);
      simde_test_codegen_write_i32(2, imm8, SIMDE_TEST_VEC_POS_MIDDLE);
      simde_test_x86_write_f32x16(2, r, SIMDE_TEST_VEC_POS_LAST);
    }
  }
  return 1;
#endif
}

static int
test_simde_mm_roundscale_pd (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde_float64 a[2];
    const int imm8;
    const simde_float64 r[2];
  } test_vec[] = {
    { { SIMDE_FLOAT64_C(   785.09), SIMDE_FLOAT64_C(  -944.62) },
       INT32_C(           0),
      { SIMDE_FLOAT64_C(   785.00), SIMDE_FLOAT64_C(  -945.00) } },
    { {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   918.83) },
       INT32_C(          16),
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   919.00) } },
    { {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   618.81) },
       INT32_C(          32),
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   618.75) } },
    { { SIMDE_FLOAT64_C(  -164.68),        SIMDE_MATH_INFINITY },
       INT32_C(          48),
      { SIMDE_FLOAT64_C(  -164.62),        SIMDE_MATH_INFINITY } },
    { {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(  -996.38) },
       INT32_C(          64),
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(  -996.38) } },
    { {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(  -175.51) },
       INT32_C(          80),
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(  -175.50) } },
    { { SIMDE_FLOAT64_C(  -402.63), SIMDE_FLOAT64_C(   984.31) },
       INT32_C(          96),
      { SIMDE_FLOAT64_C(  -402.62), SIMDE_FLOAT64_C(   984.31) } },
    { { SIMDE_FLOAT64_C(  -217.00),        SIMDE_MATH_INFINITY },
       INT32_C(         112),
      { SIMDE_FLOAT64_C(  -217.00),        SIMDE_MATH_INFINITY } },
    { { SIMDE_FLOAT64_C(    86.63),       -SIMDE_MATH_INFINITY },
       INT32_C(         128),
      { SIMDE_FLOAT64_C(    86.63),       -SIMDE_MATH_INFINITY } },
    { {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(  -856.07) },
       INT32_C(         144),
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(  -856.07) } },
    { { SIMDE_FLOAT64_C(   795.64), SIMDE_FLOAT64_C(  -688.17) },
       INT32_C(         160),
      { SIMDE_FLOAT64_C(   795.64), SIMDE_FLOAT64_C(  -688.17) } },
    { {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(    64.12) },
       INT32_C(         176),
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(    64.12) } },
    { { SIMDE_FLOAT64_C(    67.73), SIMDE_FLOAT64_C(   167.14) },
       INT32_C(         192),
      { SIMDE_FLOAT64_C(    67.73), SIMDE_FLOAT64_C(   167.14) } },
    { {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   991.63) },
       INT32_C(         208),
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   991.63) } },
    { { SIMDE_FLOAT64_C(  -411.00),       -SIMDE_MATH_INFINITY },
       INT32_C(         224),
      { SIMDE_FLOAT64_C(  -411.00),       -SIMDE_MATH_INFINITY } },
    { {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(  -456.55) },
       INT32_C(         240),
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(  -456.55) } },
    { { SIMDE_FLOAT64_C(  -471.12), SIMDE_FLOAT64_C(  -358.30) },
       INT32_C(           1),
      { SIMDE_FLOAT64_C(  -472.00), SIMDE_FLOAT64_C(  -359.00) } },
    { {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(  -805.94) },
       INT32_C(          17),
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(  -806.00) } },
    { { SIMDE_FLOAT64_C(   979.16),       -SIMDE_MATH_INFINITY },
       INT32_C(          33),
      { SIMDE_FLOAT64_C(   979.00),       -SIMDE_MATH_INFINITY } },
    { {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   130.56) },
       INT32_C(          49),
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   130.50) } },
    { { SIMDE_FLOAT64_C(  -702.31),       -SIMDE_MATH_INFINITY },
       INT32_C(          65),
      { SIMDE_FLOAT64_C(  -702.31),       -SIMDE_MATH_INFINITY } },
    { {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(  -121.68) },
       INT32_C(          81),
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(  -121.69) } },
    { {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   346.29) },
       INT32_C(          97),
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   346.28) } },
    { {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(    41.41) },
       INT32_C(         113),
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(    41.41) } },
    { { SIMDE_FLOAT64_C(  -907.56), SIMDE_FLOAT64_C(   709.24) },
       INT32_C(         129),
      { SIMDE_FLOAT64_C(  -907.56), SIMDE_FLOAT64_C(   709.24) } },
    { { SIMDE_FLOAT64_C(   287.39), SIMDE_FLOAT64_C(   572.34) },
       INT32_C(         145),
      { SIMDE_FLOAT64_C(   287.39), SIMDE_FLOAT64_C(   572.34) } },
    { { SIMDE_FLOAT64_C(  -722.01), SIMDE_FLOAT64_C(   747.27) },
       INT32_C(         161),
      { SIMDE_FLOAT64_C(  -722.01), SIMDE_FLOAT64_C(   747.27) } },
    { {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   -13.68) },
       INT32_C(         177),
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   -13.68) } },
    { { SIMDE_FLOAT64_C(   293.11), SIMDE_FLOAT64_C(   430.09) },
       INT32_C(         193),
      { SIMDE_FLOAT64_C(   293.11), SIMDE_FLOAT64_C(   430.09) } },
    { { SIMDE_FLOAT64_C(    32.05), SIMDE_FLOAT64_C(   719.42) },
       INT32_C(         209),
      { SIMDE_FLOAT64_C(    32.05), SIMDE_FLOAT64_C(   719.42) } },
    { { SIMDE_FLOAT64_C(   141.27),       -SIMDE_MATH_INFINITY },
       INT32_C(         225),
      { SIMDE_FLOAT64_C(   141.27),       -SIMDE_MATH_INFINITY } },
    { {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(  -825.97) },
       INT32_C(         241),
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(  -825.97) } },
    { { SIMDE_FLOAT64_C(   215.44),        SIMDE_MATH_INFINITY },
       INT32_C(           2),
      { SIMDE_FLOAT64_C(   216.00),        SIMDE_MATH_INFINITY } },
    { { SIMDE_FLOAT64_C(   -89.17), SIMDE_FLOAT64_C(  -404.73) },
       INT32_C(          18),
      { SIMDE_FLOAT64_C(   -89.00), SIMDE_FLOAT64_C(  -404.50) } },
    { {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(  -126.74) },
       INT32_C(          34),
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(  -126.50) } },
    { { SIMDE_FLOAT64_C(   722.04), SIMDE_FLOAT64_C(   -20.34) },
       INT32_C(          50),
      { SIMDE_FLOAT64_C(   722.12), SIMDE_FLOAT64_C(   -20.25) } },
    { { SIMDE_FLOAT64_C(  -225.17), SIMDE_FLOAT64_C(  -727.23) },
       INT32_C(          66),
      { SIMDE_FLOAT64_C(  -225.12), SIMDE_FLOAT64_C(  -727.19) } },
    { {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   304.82) },
       INT32_C(          82),
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   304.84) } },
    { { SIMDE_FLOAT64_C(  -553.91), SIMDE_FLOAT64_C(   146.57) },
       INT32_C(          98),
      { SIMDE_FLOAT64_C(  -553.91), SIMDE_FLOAT64_C(   146.58) } },
    { { SIMDE_FLOAT64_C(   624.27), SIMDE_FLOAT64_C(   994.64) },
       INT32_C(         114),
      { SIMDE_FLOAT64_C(   624.27), SIMDE_FLOAT64_C(   994.64) } },
    { { SIMDE_FLOAT64_C(   798.30), SIMDE_FLOAT64_C(   636.47) },
       INT32_C(         130),
      { SIMDE_FLOAT64_C(   798.30), SIMDE_FLOAT64_C(   636.47) } },
    { { SIMDE_FLOAT64_C(    13.74),        SIMDE_MATH_INFINITY },
       INT32_C(         146),
      { SIMDE_FLOAT64_C(    13.74),        SIMDE_MATH_INFINITY } },
    { { SIMDE_FLOAT64_C(  -742.07), SIMDE_FLOAT64_C(   -83.10) },
       INT32_C(         162),
      { SIMDE_FLOAT64_C(  -742.07), SIMDE_FLOAT64_C(   -83.10) } },
    { { SIMDE_FLOAT64_C(  -476.98),       -SIMDE_MATH_INFINITY },
       INT32_C(         178),
      { SIMDE_FLOAT64_C(  -476.98),       -SIMDE_MATH_INFINITY } },
    { { SIMDE_FLOAT64_C(  -506.27),       -SIMDE_MATH_INFINITY },
       INT32_C(         194),
      { SIMDE_FLOAT64_C(  -506.27),       -SIMDE_MATH_INFINITY } },
    { {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(  -928.68) },
       INT32_C(         210),
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(  -928.68) } },
    { {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(  -285.92) },
       INT32_C(         226),
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(  -285.92) } },
    { { SIMDE_FLOAT64_C(  -291.28), SIMDE_FLOAT64_C(   625.24) },
       INT32_C(         242),
      { SIMDE_FLOAT64_C(  -291.28), SIMDE_FLOAT64_C(   625.24) } },
    { { SIMDE_FLOAT64_C(  -654.81), SIMDE_FLOAT64_C(   436.59) },
       INT32_C(           3),
      { SIMDE_FLOAT64_C(  -654.00), SIMDE_FLOAT64_C(   436.00) } },
    { { SIMDE_FLOAT64_C(   -53.86), SIMDE_FLOAT64_C(  -216.31) },
       INT32_C(          19),
      { SIMDE_FLOAT64_C(   -53.50), SIMDE_FLOAT64_C(  -216.00) } },
    { { SIMDE_FLOAT64_C(  -779.18), SIMDE_FLOAT64_C(    41.62) },
       INT32_C(          35),
      { SIMDE_FLOAT64_C(  -779.00), SIMDE_FLOAT64_C(    41.50) } },
    { { SIMDE_FLOAT64_C(   741.56), SIMDE_FLOAT64_C(   564.64) },
       INT32_C(          51),
      { SIMDE_FLOAT64_C(   741.50), SIMDE_FLOAT64_C(   564.62) } },
    { { SIMDE_FLOAT64_C(   255.64), SIMDE_FLOAT64_C(  -645.42) },
       INT32_C(          67),
      { SIMDE_FLOAT64_C(   255.62), SIMDE_FLOAT64_C(  -645.38) } },
    { { SIMDE_FLOAT64_C(   749.37),       -SIMDE_MATH_INFINITY },
       INT32_C(          83),
      { SIMDE_FLOAT64_C(   749.34),       -SIMDE_MATH_INFINITY } },
    { { SIMDE_FLOAT64_C(   136.81),        SIMDE_MATH_INFINITY },
       INT32_C(          99),
      { SIMDE_FLOAT64_C(   136.80),        SIMDE_MATH_INFINITY } },
    { { SIMDE_FLOAT64_C(   844.12), SIMDE_FLOAT64_C(   832.76) },
       INT32_C(         115),
      { SIMDE_FLOAT64_C(   844.12), SIMDE_FLOAT64_C(   832.76) } },
    { { SIMDE_FLOAT64_C(  -447.16), SIMDE_FLOAT64_C(   458.00) },
       INT32_C(         131),
      { SIMDE_FLOAT64_C(  -447.16), SIMDE_FLOAT64_C(   458.00) } },
    { { SIMDE_FLOAT64_C(  -101.97), SIMDE_FLOAT64_C(  -105.41) },
       INT32_C(         147),
      { SIMDE_FLOAT64_C(  -101.97), SIMDE_FLOAT64_C(  -105.41) } },
    { { SIMDE_FLOAT64_C(   844.18), SIMDE_FLOAT64_C(   678.28) },
       INT32_C(         163),
      { SIMDE_FLOAT64_C(   844.18), SIMDE_FLOAT64_C(   678.28) } },
    { { SIMDE_FLOAT64_C(  -935.00), SIMDE_FLOAT64_C(  -280.09) },
       INT32_C(         179),
      { SIMDE_FLOAT64_C(  -935.00), SIMDE_FLOAT64_C(  -280.09) } },
    { { SIMDE_FLOAT64_C(   806.56), SIMDE_FLOAT64_C(  -715.45) },
       INT32_C(         195),
      { SIMDE_FLOAT64_C(   806.56), SIMDE_FLOAT64_C(  -715.45) } },
    { { SIMDE_FLOAT64_C(    62.19), SIMDE_FLOAT64_C(  -360.86) },
       INT32_C(         211),
      { SIMDE_FLOAT64_C(    62.19), SIMDE_FLOAT64_C(  -360.86) } },
    { {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   182.98) },
       INT32_C(         227),
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   182.98) } },
    { { SIMDE_FLOAT64_C(  -254.49), SIMDE_FLOAT64_C(  -997.08) },
       INT32_C(         243),
      { SIMDE_FLOAT64_C(  -254.49), SIMDE_FLOAT64_C(  -997.08) } },
    { {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   667.08) },
       INT32_C(           4),
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   667.00) } },
    { { SIMDE_FLOAT64_C(   499.84), SIMDE_FLOAT64_C(  -734.56) },
       INT32_C(          20),
      { SIMDE_FLOAT64_C(   500.00), SIMDE_FLOAT64_C(  -734.50) } },
    { { SIMDE_FLOAT64_C(   -42.15),        SIMDE_MATH_INFINITY },
       INT32_C(          36),
      { SIMDE_FLOAT64_C(   -42.25),        SIMDE_MATH_INFINITY } },
    { {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   530.72) },
       INT32_C(          52),
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   530.75) } },
    { { SIMDE_FLOAT64_C(  -749.37), SIMDE_FLOAT64_C(  -385.63) },
       INT32_C(          68),
      { SIMDE_FLOAT64_C(  -749.38), SIMDE_FLOAT64_C(  -385.62) } },
    { { SIMDE_FLOAT64_C(  -464.82), SIMDE_FLOAT64_C(  -795.73) },
       INT32_C(          84),
      { SIMDE_FLOAT64_C(  -464.81), SIMDE_FLOAT64_C(  -795.72) } },
    { {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   288.75) },
       INT32_C(         100),
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   288.75) } },
    { {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(  -912.54) },
       INT32_C(         116),
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(  -912.54) } },
    { {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   -21.64) },
       INT32_C(         132),
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   -21.64) } },
    { {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   324.70) },
       INT32_C(         148),
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   324.70) } },
    { {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(  -261.65) },
       INT32_C(         164),
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(  -261.65) } },
    { { SIMDE_FLOAT64_C(  -670.05),       -SIMDE_MATH_INFINITY },
       INT32_C(         180),
      { SIMDE_FLOAT64_C(  -670.05),       -SIMDE_MATH_INFINITY } },
    { { SIMDE_FLOAT64_C(   916.34), SIMDE_FLOAT64_C(   951.18) },
       INT32_C(         196),
      { SIMDE_FLOAT64_C(   916.34), SIMDE_FLOAT64_C(   951.18) } },
    { {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(  -844.55) },
       INT32_C(         212),
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(  -844.55) } },
    { { SIMDE_FLOAT64_C(   444.20), SIMDE_FLOAT64_C(   830.33) },
       INT32_C(         228),
      { SIMDE_FLOAT64_C(   444.20), SIMDE_FLOAT64_C(   830.33) } },
    { {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   917.79) },
       INT32_C(         244),
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   917.79) } },
  };

  simde__m128d a, r;

  a = simde_mm_loadu_pd(test_vec[0].a);
  r = simde_mm_roundscale_pd(a, INT32_C(           0));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[0].r), 1);

  a = simde_mm_loadu_pd(test_vec[1].a);
  r = simde_mm_roundscale_pd(a, INT32_C(          16));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[1].r), 1);

  a = simde_mm_loadu_pd(test_vec[2].a);
  r = simde_mm_roundscale_pd(a, INT32_C(          32));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[2].r), 1);

  a = simde_mm_loadu_pd(test_vec[3].a);
  r = simde_mm_roundscale_pd(a, INT32_C(          48));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[3].r), 1);

  a = simde_mm_loadu_pd(test_vec[4].a);
  r = simde_mm_roundscale_pd(a, INT32_C(          64));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[4].r), 1);

  a = simde_mm_loadu_pd(test_vec[5].a);
  r = simde_mm_roundscale_pd(a, INT32_C(          80));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[5].r), 1);

  a = simde_mm_loadu_pd(test_vec[6].a);
  r = simde_mm_roundscale_pd(a, INT32_C(          96));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[6].r), 1);

  a = simde_mm_loadu_pd(test_vec[7].a);
  r = simde_mm_roundscale_pd(a, INT32_C(         112));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[7].r), 1);

  a = simde_mm_loadu_pd(test_vec[8].a);
  r = simde_mm_roundscale_pd(a, INT32_C(         128));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[8].r), 1);

  a = simde_mm_loadu_pd(test_vec[9].a);
  r = simde_mm_roundscale_pd(a, INT32_C(         144));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[9].r), 1);

  a = simde_mm_loadu_pd(test_vec[10].a);
  r = simde_mm_roundscale_pd(a, INT32_C(         160));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[10].r), 1);

  a = simde_mm_loadu_pd(test_vec[11].a);
  r = simde_mm_roundscale_pd(a, INT32_C(         176));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[11].r), 1);

  a = simde_mm_loadu_pd(test_vec[12].a);
  r = simde_mm_roundscale_pd(a, INT32_C(         192));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[12].r), 1);

  a = simde_mm_loadu_pd(test_vec[13].a);
  r = simde_mm_roundscale_pd(a, INT32_C(         208));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[13].r), 1);

  a = simde_mm_loadu_pd(test_vec[14].a);
  r = simde_mm_roundscale_pd(a, INT32_C(         224));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[14].r), 1);

  a = simde_mm_loadu_pd(test_vec[15].a);
  r = simde_mm_roundscale_pd(a, INT32_C(         240));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[15].r), 1);

  a = simde_mm_loadu_pd(test_vec[16].a);
  r = simde_mm_roundscale_pd(a, INT32_C(           1));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[16].r), 1);

  a = simde_mm_loadu_pd(test_vec[17].a);
  r = simde_mm_roundscale_pd(a, INT32_C(          17));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[17].r), 1);

  a = simde_mm_loadu_pd(test_vec[18].a);
  r = simde_mm_roundscale_pd(a, INT32_C(          33));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[18].r), 1);

  a = simde_mm_loadu_pd(test_vec[19].a);
  r = simde_mm_roundscale_pd(a, INT32_C(          49));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[19].r), 1);

  a = simde_mm_loadu_pd(test_vec[20].a);
  r = simde_mm_roundscale_pd(a, INT32_C(          65));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[20].r), 1);

  a = simde_mm_loadu_pd(test_vec[21].a);
  r = simde_mm_roundscale_pd(a, INT32_C(          81));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[21].r), 1);

  a = simde_mm_loadu_pd(test_vec[22].a);
  r = simde_mm_roundscale_pd(a, INT32_C(          97));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[22].r), 1);

  a = simde_mm_loadu_pd(test_vec[23].a);
  r = simde_mm_roundscale_pd(a, INT32_C(         113));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[23].r), 1);

  a = simde_mm_loadu_pd(test_vec[24].a);
  r = simde_mm_roundscale_pd(a, INT32_C(         129));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[24].r), 1);

  a = simde_mm_loadu_pd(test_vec[25].a);
  r = simde_mm_roundscale_pd(a, INT32_C(         145));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[25].r), 1);

  a = simde_mm_loadu_pd(test_vec[26].a);
  r = simde_mm_roundscale_pd(a, INT32_C(         161));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[26].r), 1);

  a = simde_mm_loadu_pd(test_vec[27].a);
  r = simde_mm_roundscale_pd(a, INT32_C(         177));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[27].r), 1);

  a = simde_mm_loadu_pd(test_vec[28].a);
  r = simde_mm_roundscale_pd(a, INT32_C(         193));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[28].r), 1);

  a = simde_mm_loadu_pd(test_vec[29].a);
  r = simde_mm_roundscale_pd(a, INT32_C(         209));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[29].r), 1);

  a = simde_mm_loadu_pd(test_vec[30].a);
  r = simde_mm_roundscale_pd(a, INT32_C(         225));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[30].r), 1);

  a = simde_mm_loadu_pd(test_vec[31].a);
  r = simde_mm_roundscale_pd(a, INT32_C(         241));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[31].r), 1);

  a = simde_mm_loadu_pd(test_vec[32].a);
  r = simde_mm_roundscale_pd(a, INT32_C(           2));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[32].r), 1);

  a = simde_mm_loadu_pd(test_vec[33].a);
  r = simde_mm_roundscale_pd(a, INT32_C(          18));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[33].r), 1);

  a = simde_mm_loadu_pd(test_vec[34].a);
  r = simde_mm_roundscale_pd(a, INT32_C(          34));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[34].r), 1);

  a = simde_mm_loadu_pd(test_vec[35].a);
  r = simde_mm_roundscale_pd(a, INT32_C(          50));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[35].r), 1);

  a = simde_mm_loadu_pd(test_vec[36].a);
  r = simde_mm_roundscale_pd(a, INT32_C(          66));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[36].r), 1);

  a = simde_mm_loadu_pd(test_vec[37].a);
  r = simde_mm_roundscale_pd(a, INT32_C(          82));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[37].r), 1);

  a = simde_mm_loadu_pd(test_vec[38].a);
  r = simde_mm_roundscale_pd(a, INT32_C(          98));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[38].r), 1);

  a = simde_mm_loadu_pd(test_vec[39].a);
  r = simde_mm_roundscale_pd(a, INT32_C(         114));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[39].r), 1);

  a = simde_mm_loadu_pd(test_vec[40].a);
  r = simde_mm_roundscale_pd(a, INT32_C(         130));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[40].r), 1);

  a = simde_mm_loadu_pd(test_vec[41].a);
  r = simde_mm_roundscale_pd(a, INT32_C(         146));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[41].r), 1);

  a = simde_mm_loadu_pd(test_vec[42].a);
  r = simde_mm_roundscale_pd(a, INT32_C(         162));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[42].r), 1);

  a = simde_mm_loadu_pd(test_vec[43].a);
  r = simde_mm_roundscale_pd(a, INT32_C(         178));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[43].r), 1);

  a = simde_mm_loadu_pd(test_vec[44].a);
  r = simde_mm_roundscale_pd(a, INT32_C(         194));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[44].r), 1);

  a = simde_mm_loadu_pd(test_vec[45].a);
  r = simde_mm_roundscale_pd(a, INT32_C(         210));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[45].r), 1);

  a = simde_mm_loadu_pd(test_vec[46].a);
  r = simde_mm_roundscale_pd(a, INT32_C(         226));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[46].r), 1);

  a = simde_mm_loadu_pd(test_vec[47].a);
  r = simde_mm_roundscale_pd(a, INT32_C(         242));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[47].r), 1);

  a = simde_mm_loadu_pd(test_vec[48].a);
  r = simde_mm_roundscale_pd(a, INT32_C(           3));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[48].r), 1);

  a = simde_mm_loadu_pd(test_vec[49].a);
  r = simde_mm_roundscale_pd(a, INT32_C(          19));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[49].r), 1);

  a = simde_mm_loadu_pd(test_vec[50].a);
  r = simde_mm_roundscale_pd(a, INT32_C(          35));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[50].r), 1);

  a = simde_mm_loadu_pd(test_vec[51].a);
  r = simde_mm_roundscale_pd(a, INT32_C(          51));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[51].r), 1);

  a = simde_mm_loadu_pd(test_vec[52].a);
  r = simde_mm_roundscale_pd(a, INT32_C(          67));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[52].r), 1);

  a = simde_mm_loadu_pd(test_vec[53].a);
  r = simde_mm_roundscale_pd(a, INT32_C(          83));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[53].r), 1);

  a = simde_mm_loadu_pd(test_vec[54].a);
  r = simde_mm_roundscale_pd(a, INT32_C(          99));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[54].r), 1);

  a = simde_mm_loadu_pd(test_vec[55].a);
  r = simde_mm_roundscale_pd(a, INT32_C(         115));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[55].r), 1);

  a = simde_mm_loadu_pd(test_vec[56].a);
  r = simde_mm_roundscale_pd(a, INT32_C(         131));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[56].r), 1);

  a = simde_mm_loadu_pd(test_vec[57].a);
  r = simde_mm_roundscale_pd(a, INT32_C(         147));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[57].r), 1);

  a = simde_mm_loadu_pd(test_vec[58].a);
  r = simde_mm_roundscale_pd(a, INT32_C(         163));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[58].r), 1);

  a = simde_mm_loadu_pd(test_vec[59].a);
  r = simde_mm_roundscale_pd(a, INT32_C(         179));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[59].r), 1);

  a = simde_mm_loadu_pd(test_vec[60].a);
  r = simde_mm_roundscale_pd(a, INT32_C(         195));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[60].r), 1);

  a = simde_mm_loadu_pd(test_vec[61].a);
  r = simde_mm_roundscale_pd(a, INT32_C(         211));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[61].r), 1);

  a = simde_mm_loadu_pd(test_vec[62].a);
  r = simde_mm_roundscale_pd(a, INT32_C(         227));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[62].r), 1);

  a = simde_mm_loadu_pd(test_vec[63].a);
  r = simde_mm_roundscale_pd(a, INT32_C(         243));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[63].r), 1);

  a = simde_mm_loadu_pd(test_vec[64].a);
  r = simde_mm_roundscale_pd(a, INT32_C(           4));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[64].r), 1);

  a = simde_mm_loadu_pd(test_vec[65].a);
  r = simde_mm_roundscale_pd(a, INT32_C(          20));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[65].r), 1);

  a = simde_mm_loadu_pd(test_vec[66].a);
  r = simde_mm_roundscale_pd(a, INT32_C(          36));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[66].r), 1);

  a = simde_mm_loadu_pd(test_vec[67].a);
  r = simde_mm_roundscale_pd(a, INT32_C(          52));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[67].r), 1);

  a = simde_mm_loadu_pd(test_vec[68].a);
  r = simde_mm_roundscale_pd(a, INT32_C(          68));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[68].r), 1);

  a = simde_mm_loadu_pd(test_vec[69].a);
  r = simde_mm_roundscale_pd(a, INT32_C(          84));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[69].r), 1);

  a = simde_mm_loadu_pd(test_vec[70].a);
  r = simde_mm_roundscale_pd(a, INT32_C(         100));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[70].r), 1);

  a = simde_mm_loadu_pd(test_vec[71].a);
  r = simde_mm_roundscale_pd(a, INT32_C(         116));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[71].r), 1);

  a = simde_mm_loadu_pd(test_vec[72].a);
  r = simde_mm_roundscale_pd(a, INT32_C(         132));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[72].r), 1);

  a = simde_mm_loadu_pd(test_vec[73].a);
  r = simde_mm_roundscale_pd(a, INT32_C(         148));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[73].r), 1);

  a = simde_mm_loadu_pd(test_vec[74].a);
  r = simde_mm_roundscale_pd(a, INT32_C(         164));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[74].r), 1);

  a = simde_mm_loadu_pd(test_vec[75].a);
  r = simde_mm_roundscale_pd(a, INT32_C(         180));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[75].r), 1);

  a = simde_mm_loadu_pd(test_vec[76].a);
  r = simde_mm_roundscale_pd(a, INT32_C(         196));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[76].r), 1);

  a = simde_mm_loadu_pd(test_vec[77].a);
  r = simde_mm_roundscale_pd(a, INT32_C(         212));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[77].r), 1);

  a = simde_mm_loadu_pd(test_vec[78].a);
  r = simde_mm_roundscale_pd(a, INT32_C(         228));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[78].r), 1);

  a = simde_mm_loadu_pd(test_vec[79].a);
  r = simde_mm_roundscale_pd(a, INT32_C(         244));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[79].r), 1);

 return 0;
#else
  fputc('\n', stdout);
  int round_type[5] = {SIMDE_MM_FROUND_TO_NEAREST_INT, SIMDE_MM_FROUND_TO_NEG_INF, SIMDE_MM_FROUND_TO_POS_INF, SIMDE_MM_FROUND_TO_ZERO, SIMDE_MM_FROUND_CUR_DIRECTION};
  for (int i = 0 ; i < 5 ; i++) {
    for (int j = 0 ; j < 16 ; j++) {
      simde__m128d a = simde_test_x86_random_f64x2(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
      if((simde_test_codegen_rand() & 1)) {
        if((simde_test_codegen_rand() & 1))
          a = simde_mm_blend_pd(a, simde_mm_set1_pd(SIMDE_MATH_NAN), 1);
        else {
          if((simde_test_codegen_rand() & 1))
            a = simde_mm_blend_pd(a, simde_mm_set1_pd(SIMDE_MATH_INFINITY), 2);
          else
            a = simde_mm_blend_pd(a, simde_mm_set1_pd(-SIMDE_MATH_INFINITY), 2);
        }
      }
      int imm8 = ((j << 4) | round_type[i]) & 255;
      simde__m128d r;
      SIMDE_CONSTIFY_256_(simde_mm_roundscale_pd, r, simde_mm_setzero_pd(), imm8, a);

      simde_test_x86_write_f64x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
      simde_test_codegen_write_i32(2, imm8, SIMDE_TEST_VEC_POS_MIDDLE);
      simde_test_x86_write_f64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
    }
  }
  return 1;
#endif
}

static int
test_simde_mm256_roundscale_pd (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde_float64 a[4];
    const int32_t imm8;
    const simde_float64 r[4];
  } test_vec[] = {
    { { SIMDE_FLOAT64_C(   478.89),       -SIMDE_MATH_INFINITY, SIMDE_FLOAT64_C(  -353.66), SIMDE_FLOAT64_C(   647.32) },
       INT32_C(           0),
      { SIMDE_FLOAT64_C(   479.00),       -SIMDE_MATH_INFINITY, SIMDE_FLOAT64_C(  -354.00), SIMDE_FLOAT64_C(   647.00) } },
    { { SIMDE_FLOAT64_C(  -139.30), SIMDE_FLOAT64_C(  -585.30), SIMDE_FLOAT64_C(  -212.07), SIMDE_FLOAT64_C(  -727.58) },
       INT32_C(          16),
      { SIMDE_FLOAT64_C(  -139.50), SIMDE_FLOAT64_C(  -585.50), SIMDE_FLOAT64_C(  -212.00), SIMDE_FLOAT64_C(  -727.50) } },
    { { SIMDE_FLOAT64_C(  -424.71),       -SIMDE_MATH_INFINITY, SIMDE_FLOAT64_C(   300.82), SIMDE_FLOAT64_C(  -527.06) },
       INT32_C(          32),
      { SIMDE_FLOAT64_C(  -424.75),       -SIMDE_MATH_INFINITY, SIMDE_FLOAT64_C(   300.75), SIMDE_FLOAT64_C(  -527.00) } },
    { { SIMDE_FLOAT64_C(   759.84),        SIMDE_MATH_INFINITY, SIMDE_FLOAT64_C(  -784.82), SIMDE_FLOAT64_C(  -774.55) },
       INT32_C(          48),
      { SIMDE_FLOAT64_C(   759.88),        SIMDE_MATH_INFINITY, SIMDE_FLOAT64_C(  -784.88), SIMDE_FLOAT64_C(  -774.50) } },
    { { SIMDE_FLOAT64_C(    47.82),        SIMDE_MATH_INFINITY, SIMDE_FLOAT64_C(   320.78), SIMDE_FLOAT64_C(  -567.27) },
       INT32_C(          64),
      { SIMDE_FLOAT64_C(    47.81),        SIMDE_MATH_INFINITY, SIMDE_FLOAT64_C(   320.75), SIMDE_FLOAT64_C(  -567.25) } },
    { { SIMDE_FLOAT64_C(  -134.26),        SIMDE_MATH_INFINITY, SIMDE_FLOAT64_C(   -18.89), SIMDE_FLOAT64_C(   416.85) },
       INT32_C(          80),
      { SIMDE_FLOAT64_C(  -134.25),        SIMDE_MATH_INFINITY, SIMDE_FLOAT64_C(   -18.88), SIMDE_FLOAT64_C(   416.84) } },
    { { SIMDE_FLOAT64_C(   249.32), SIMDE_FLOAT64_C(  -885.77), SIMDE_FLOAT64_C(  -611.79), SIMDE_FLOAT64_C(   824.61) },
       INT32_C(          96),
      { SIMDE_FLOAT64_C(   249.31), SIMDE_FLOAT64_C(  -885.77), SIMDE_FLOAT64_C(  -611.80), SIMDE_FLOAT64_C(   824.61) } },
    { { SIMDE_FLOAT64_C(   689.03),       -SIMDE_MATH_INFINITY, SIMDE_FLOAT64_C(   135.80), SIMDE_FLOAT64_C(  -347.14) },
       INT32_C(         112),
      { SIMDE_FLOAT64_C(   689.03),       -SIMDE_MATH_INFINITY, SIMDE_FLOAT64_C(   135.80), SIMDE_FLOAT64_C(  -347.14) } },
    { {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   121.08), SIMDE_FLOAT64_C(   589.13), SIMDE_FLOAT64_C(   907.64) },
       INT32_C(         128),
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   121.08), SIMDE_FLOAT64_C(   589.13), SIMDE_FLOAT64_C(   907.64) } },
    { { SIMDE_FLOAT64_C(   620.07),        SIMDE_MATH_INFINITY, SIMDE_FLOAT64_C(    69.68), SIMDE_FLOAT64_C(   839.47) },
       INT32_C(         144),
      { SIMDE_FLOAT64_C(   620.07),        SIMDE_MATH_INFINITY, SIMDE_FLOAT64_C(    69.68), SIMDE_FLOAT64_C(   839.47) } },
    { {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(  -196.65), SIMDE_FLOAT64_C(  -877.94), SIMDE_FLOAT64_C(  -295.05) },
       INT32_C(         160),
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(  -196.65), SIMDE_FLOAT64_C(  -877.94), SIMDE_FLOAT64_C(  -295.05) } },
    { {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(  -240.61), SIMDE_FLOAT64_C(  -658.18), SIMDE_FLOAT64_C(   778.88) },
       INT32_C(         176),
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(  -240.61), SIMDE_FLOAT64_C(  -658.18), SIMDE_FLOAT64_C(   778.88) } },
    { {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(  -992.29), SIMDE_FLOAT64_C(  -316.30), SIMDE_FLOAT64_C(  -447.51) },
       INT32_C(         192),
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(  -992.29), SIMDE_FLOAT64_C(  -316.30), SIMDE_FLOAT64_C(  -447.51) } },
    { { SIMDE_FLOAT64_C(   243.73), SIMDE_FLOAT64_C(  -975.57), SIMDE_FLOAT64_C(   525.76), SIMDE_FLOAT64_C(   151.37) },
       INT32_C(         208),
      { SIMDE_FLOAT64_C(   243.73), SIMDE_FLOAT64_C(  -975.57), SIMDE_FLOAT64_C(   525.76), SIMDE_FLOAT64_C(   151.37) } },
    { {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(  -228.56), SIMDE_FLOAT64_C(  -302.52), SIMDE_FLOAT64_C(   232.39) },
       INT32_C(         224),
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(  -228.56), SIMDE_FLOAT64_C(  -302.52), SIMDE_FLOAT64_C(   232.39) } },
    { { SIMDE_FLOAT64_C(    54.64),        SIMDE_MATH_INFINITY, SIMDE_FLOAT64_C(  -262.39), SIMDE_FLOAT64_C(   857.99) },
       INT32_C(         240),
      { SIMDE_FLOAT64_C(    54.64),        SIMDE_MATH_INFINITY, SIMDE_FLOAT64_C(  -262.39), SIMDE_FLOAT64_C(   857.99) } },
    { { SIMDE_FLOAT64_C(   391.80),       -SIMDE_MATH_INFINITY, SIMDE_FLOAT64_C(   262.54), SIMDE_FLOAT64_C(   733.62) },
       INT32_C(           1),
      { SIMDE_FLOAT64_C(   391.00),       -SIMDE_MATH_INFINITY, SIMDE_FLOAT64_C(   262.00), SIMDE_FLOAT64_C(   733.00) } },
    { { SIMDE_FLOAT64_C(   252.12), SIMDE_FLOAT64_C(  -857.84), SIMDE_FLOAT64_C(  -551.83), SIMDE_FLOAT64_C(   804.61) },
       INT32_C(          17),
      { SIMDE_FLOAT64_C(   252.00), SIMDE_FLOAT64_C(  -858.00), SIMDE_FLOAT64_C(  -552.00), SIMDE_FLOAT64_C(   804.50) } },
    { {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(    48.34), SIMDE_FLOAT64_C(    69.93), SIMDE_FLOAT64_C(   910.57) },
       INT32_C(          33),
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(    48.25), SIMDE_FLOAT64_C(    69.75), SIMDE_FLOAT64_C(   910.50) } },
    { { SIMDE_FLOAT64_C(  -926.72),       -SIMDE_MATH_INFINITY, SIMDE_FLOAT64_C(   467.98), SIMDE_FLOAT64_C(   305.67) },
       INT32_C(          49),
      { SIMDE_FLOAT64_C(  -926.75),       -SIMDE_MATH_INFINITY, SIMDE_FLOAT64_C(   467.88), SIMDE_FLOAT64_C(   305.62) } },
    { {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(  -300.36), SIMDE_FLOAT64_C(  -781.70), SIMDE_FLOAT64_C(  -663.62) },
       INT32_C(          65),
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(  -300.38), SIMDE_FLOAT64_C(  -781.75), SIMDE_FLOAT64_C(  -663.62) } },
    { {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   539.02), SIMDE_FLOAT64_C(   983.98), SIMDE_FLOAT64_C(   461.80) },
       INT32_C(          81),
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   539.00), SIMDE_FLOAT64_C(   983.97), SIMDE_FLOAT64_C(   461.78) } },
    { { SIMDE_FLOAT64_C(   226.26), SIMDE_FLOAT64_C(   966.84), SIMDE_FLOAT64_C(  -739.41), SIMDE_FLOAT64_C(   674.43) },
       INT32_C(          97),
      { SIMDE_FLOAT64_C(   226.25), SIMDE_FLOAT64_C(   966.83), SIMDE_FLOAT64_C(  -739.42), SIMDE_FLOAT64_C(   674.42) } },
    { { SIMDE_FLOAT64_C(   306.09), SIMDE_FLOAT64_C(  -940.77), SIMDE_FLOAT64_C(  -180.22), SIMDE_FLOAT64_C(  -623.98) },
       INT32_C(         113),
      { SIMDE_FLOAT64_C(   306.09), SIMDE_FLOAT64_C(  -940.77), SIMDE_FLOAT64_C(  -180.23), SIMDE_FLOAT64_C(  -623.98) } },
    { {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   146.52), SIMDE_FLOAT64_C(  -956.93), SIMDE_FLOAT64_C(   990.64) },
       INT32_C(         129),
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   146.52), SIMDE_FLOAT64_C(  -956.93), SIMDE_FLOAT64_C(   990.64) } },
    { { SIMDE_FLOAT64_C(   572.71), SIMDE_FLOAT64_C(  -423.47), SIMDE_FLOAT64_C(   709.06), SIMDE_FLOAT64_C(  -529.10) },
       INT32_C(         145),
      { SIMDE_FLOAT64_C(   572.71), SIMDE_FLOAT64_C(  -423.47), SIMDE_FLOAT64_C(   709.06), SIMDE_FLOAT64_C(  -529.10) } },
    { {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(  -192.72), SIMDE_FLOAT64_C(   418.37), SIMDE_FLOAT64_C(  -351.20) },
       INT32_C(         161),
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(  -192.72), SIMDE_FLOAT64_C(   418.37), SIMDE_FLOAT64_C(  -351.20) } },
    { { SIMDE_FLOAT64_C(  -367.21),       -SIMDE_MATH_INFINITY, SIMDE_FLOAT64_C(   672.09), SIMDE_FLOAT64_C(  -248.78) },
       INT32_C(         177),
      { SIMDE_FLOAT64_C(  -367.21),       -SIMDE_MATH_INFINITY, SIMDE_FLOAT64_C(   672.09), SIMDE_FLOAT64_C(  -248.78) } },
    { { SIMDE_FLOAT64_C(  -102.05),        SIMDE_MATH_INFINITY, SIMDE_FLOAT64_C(  -682.10), SIMDE_FLOAT64_C(   -42.82) },
       INT32_C(         193),
      { SIMDE_FLOAT64_C(  -102.05),        SIMDE_MATH_INFINITY, SIMDE_FLOAT64_C(  -682.10), SIMDE_FLOAT64_C(   -42.82) } },
    { {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   840.45), SIMDE_FLOAT64_C(   -29.95), SIMDE_FLOAT64_C(   240.29) },
       INT32_C(         209),
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   840.45), SIMDE_FLOAT64_C(   -29.95), SIMDE_FLOAT64_C(   240.29) } },
    { { SIMDE_FLOAT64_C(  -187.00), SIMDE_FLOAT64_C(    31.48), SIMDE_FLOAT64_C(  -972.15), SIMDE_FLOAT64_C(   283.90) },
       INT32_C(         225),
      { SIMDE_FLOAT64_C(  -187.00), SIMDE_FLOAT64_C(    31.48), SIMDE_FLOAT64_C(  -972.15), SIMDE_FLOAT64_C(   283.90) } },
    { { SIMDE_FLOAT64_C(   955.21), SIMDE_FLOAT64_C(  -908.82), SIMDE_FLOAT64_C(   726.01), SIMDE_FLOAT64_C(  -395.99) },
       INT32_C(         241),
      { SIMDE_FLOAT64_C(   955.21), SIMDE_FLOAT64_C(  -908.82), SIMDE_FLOAT64_C(   726.01), SIMDE_FLOAT64_C(  -395.99) } },
    { {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   236.80), SIMDE_FLOAT64_C(  -376.09), SIMDE_FLOAT64_C(  -644.51) },
       INT32_C(           2),
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   237.00), SIMDE_FLOAT64_C(  -376.00), SIMDE_FLOAT64_C(  -644.00) } },
    { {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(    -0.17), SIMDE_FLOAT64_C(  -254.61), SIMDE_FLOAT64_C(   404.79) },
       INT32_C(          18),
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(    -0.00), SIMDE_FLOAT64_C(  -254.50), SIMDE_FLOAT64_C(   405.00) } },
    { {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(  -988.34), SIMDE_FLOAT64_C(  -370.46), SIMDE_FLOAT64_C(  -115.40) },
       INT32_C(          34),
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(  -988.25), SIMDE_FLOAT64_C(  -370.25), SIMDE_FLOAT64_C(  -115.25) } },
    { { SIMDE_FLOAT64_C(  -875.10), SIMDE_FLOAT64_C(  -692.94), SIMDE_FLOAT64_C(   918.39), SIMDE_FLOAT64_C(   -62.11) },
       INT32_C(          50),
      { SIMDE_FLOAT64_C(  -875.00), SIMDE_FLOAT64_C(  -692.88), SIMDE_FLOAT64_C(   918.50), SIMDE_FLOAT64_C(   -62.00) } },
    { {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(  -778.21), SIMDE_FLOAT64_C(   646.19), SIMDE_FLOAT64_C(   901.45) },
       INT32_C(          66),
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(  -778.19), SIMDE_FLOAT64_C(   646.25), SIMDE_FLOAT64_C(   901.50) } },
    { {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   -60.39), SIMDE_FLOAT64_C(  -944.41), SIMDE_FLOAT64_C(   742.26) },
       INT32_C(          82),
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   -60.38), SIMDE_FLOAT64_C(  -944.41), SIMDE_FLOAT64_C(   742.28) } },
    { { SIMDE_FLOAT64_C(   730.28),        SIMDE_MATH_INFINITY, SIMDE_FLOAT64_C(  -594.50), SIMDE_FLOAT64_C(  -269.89) },
       INT32_C(          98),
      { SIMDE_FLOAT64_C(   730.28),        SIMDE_MATH_INFINITY, SIMDE_FLOAT64_C(  -594.50), SIMDE_FLOAT64_C(  -269.88) } },
    { {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   445.25), SIMDE_FLOAT64_C(  -940.50), SIMDE_FLOAT64_C(  -511.53) },
       INT32_C(         114),
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   445.25), SIMDE_FLOAT64_C(  -940.50), SIMDE_FLOAT64_C(  -511.52) } },
    { {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(  -545.25), SIMDE_FLOAT64_C(  -781.33), SIMDE_FLOAT64_C(  -993.56) },
       INT32_C(         130),
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(  -545.25), SIMDE_FLOAT64_C(  -781.33), SIMDE_FLOAT64_C(  -993.56) } },
    { { SIMDE_FLOAT64_C(   952.68), SIMDE_FLOAT64_C(   614.43), SIMDE_FLOAT64_C(   203.40), SIMDE_FLOAT64_C(   854.13) },
       INT32_C(         146),
      { SIMDE_FLOAT64_C(   952.68), SIMDE_FLOAT64_C(   614.43), SIMDE_FLOAT64_C(   203.40), SIMDE_FLOAT64_C(   854.13) } },
    { { SIMDE_FLOAT64_C(  -424.40), SIMDE_FLOAT64_C(  -640.41), SIMDE_FLOAT64_C(  -132.99), SIMDE_FLOAT64_C(  -368.81) },
       INT32_C(         162),
      { SIMDE_FLOAT64_C(  -424.40), SIMDE_FLOAT64_C(  -640.41), SIMDE_FLOAT64_C(  -132.99), SIMDE_FLOAT64_C(  -368.81) } },
    { { SIMDE_FLOAT64_C(  -569.47),       -SIMDE_MATH_INFINITY, SIMDE_FLOAT64_C(   832.13), SIMDE_FLOAT64_C(   841.49) },
       INT32_C(         178),
      { SIMDE_FLOAT64_C(  -569.47),       -SIMDE_MATH_INFINITY, SIMDE_FLOAT64_C(   832.13), SIMDE_FLOAT64_C(   841.49) } },
    { { SIMDE_FLOAT64_C(   258.07),       -SIMDE_MATH_INFINITY, SIMDE_FLOAT64_C(   856.76), SIMDE_FLOAT64_C(  -296.68) },
       INT32_C(         194),
      { SIMDE_FLOAT64_C(   258.07),       -SIMDE_MATH_INFINITY, SIMDE_FLOAT64_C(   856.76), SIMDE_FLOAT64_C(  -296.68) } },
    { { SIMDE_FLOAT64_C(  -418.80), SIMDE_FLOAT64_C(  -566.71), SIMDE_FLOAT64_C(   487.92), SIMDE_FLOAT64_C(  -200.13) },
       INT32_C(         210),
      { SIMDE_FLOAT64_C(  -418.80), SIMDE_FLOAT64_C(  -566.71), SIMDE_FLOAT64_C(   487.92), SIMDE_FLOAT64_C(  -200.13) } },
    { { SIMDE_FLOAT64_C(  -119.44),        SIMDE_MATH_INFINITY, SIMDE_FLOAT64_C(  -607.58), SIMDE_FLOAT64_C(  -505.01) },
       INT32_C(         226),
      { SIMDE_FLOAT64_C(  -119.44),        SIMDE_MATH_INFINITY, SIMDE_FLOAT64_C(  -607.58), SIMDE_FLOAT64_C(  -505.01) } },
    { { SIMDE_FLOAT64_C(  -863.93), SIMDE_FLOAT64_C(  -393.86), SIMDE_FLOAT64_C(   289.40), SIMDE_FLOAT64_C(  -232.73) },
       INT32_C(         242),
      { SIMDE_FLOAT64_C(  -863.93), SIMDE_FLOAT64_C(  -393.86), SIMDE_FLOAT64_C(   289.40), SIMDE_FLOAT64_C(  -232.73) } },
    { { SIMDE_FLOAT64_C(   719.93), SIMDE_FLOAT64_C(   809.54), SIMDE_FLOAT64_C(  -459.89), SIMDE_FLOAT64_C(   561.42) },
       INT32_C(           3),
      { SIMDE_FLOAT64_C(   719.00), SIMDE_FLOAT64_C(   809.00), SIMDE_FLOAT64_C(  -459.00), SIMDE_FLOAT64_C(   561.00) } },
    { { SIMDE_FLOAT64_C(   102.35), SIMDE_FLOAT64_C(   559.26), SIMDE_FLOAT64_C(  -484.61), SIMDE_FLOAT64_C(   712.43) },
       INT32_C(          19),
      { SIMDE_FLOAT64_C(   102.00), SIMDE_FLOAT64_C(   559.00), SIMDE_FLOAT64_C(  -484.50), SIMDE_FLOAT64_C(   712.00) } },
    { { SIMDE_FLOAT64_C(   218.71),       -SIMDE_MATH_INFINITY, SIMDE_FLOAT64_C(   761.26), SIMDE_FLOAT64_C(  -748.12) },
       INT32_C(          35),
      { SIMDE_FLOAT64_C(   218.50),       -SIMDE_MATH_INFINITY, SIMDE_FLOAT64_C(   761.25), SIMDE_FLOAT64_C(  -748.00) } },
    { { SIMDE_FLOAT64_C(   763.08),       -SIMDE_MATH_INFINITY, SIMDE_FLOAT64_C(  -379.63), SIMDE_FLOAT64_C(  -879.84) },
       INT32_C(          51),
      { SIMDE_FLOAT64_C(   763.00),       -SIMDE_MATH_INFINITY, SIMDE_FLOAT64_C(  -379.62), SIMDE_FLOAT64_C(  -879.75) } },
    { {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   537.75), SIMDE_FLOAT64_C(   816.71), SIMDE_FLOAT64_C(   879.38) },
       INT32_C(          67),
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   537.75), SIMDE_FLOAT64_C(   816.69), SIMDE_FLOAT64_C(   879.38) } },
    { { SIMDE_FLOAT64_C(  -412.64), SIMDE_FLOAT64_C(  -452.92), SIMDE_FLOAT64_C(  -606.48), SIMDE_FLOAT64_C(   127.47) },
       INT32_C(          83),
      { SIMDE_FLOAT64_C(  -412.62), SIMDE_FLOAT64_C(  -452.91), SIMDE_FLOAT64_C(  -606.47), SIMDE_FLOAT64_C(   127.47) } },
    { { SIMDE_FLOAT64_C(   650.84),       -SIMDE_MATH_INFINITY, SIMDE_FLOAT64_C(   667.76), SIMDE_FLOAT64_C(  -833.77) },
       INT32_C(          99),
      { SIMDE_FLOAT64_C(   650.83),       -SIMDE_MATH_INFINITY, SIMDE_FLOAT64_C(   667.75), SIMDE_FLOAT64_C(  -833.77) } },
    { { SIMDE_FLOAT64_C(  -675.74),        SIMDE_MATH_INFINITY, SIMDE_FLOAT64_C(   636.82), SIMDE_FLOAT64_C(   287.47) },
       INT32_C(         115),
      { SIMDE_FLOAT64_C(  -675.73),        SIMDE_MATH_INFINITY, SIMDE_FLOAT64_C(   636.81), SIMDE_FLOAT64_C(   287.47) } },
    { {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   997.00), SIMDE_FLOAT64_C(   170.71), SIMDE_FLOAT64_C(  -299.44) },
       INT32_C(         131),
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   997.00), SIMDE_FLOAT64_C(   170.71), SIMDE_FLOAT64_C(  -299.44) } },
    { { SIMDE_FLOAT64_C(   973.80),        SIMDE_MATH_INFINITY, SIMDE_FLOAT64_C(  -331.94), SIMDE_FLOAT64_C(   853.18) },
       INT32_C(         147),
      { SIMDE_FLOAT64_C(   973.80),        SIMDE_MATH_INFINITY, SIMDE_FLOAT64_C(  -331.94), SIMDE_FLOAT64_C(   853.18) } },
    { {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   645.56), SIMDE_FLOAT64_C(   568.01), SIMDE_FLOAT64_C(  -867.16) },
       INT32_C(         163),
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   645.56), SIMDE_FLOAT64_C(   568.01), SIMDE_FLOAT64_C(  -867.16) } },
    { { SIMDE_FLOAT64_C(   800.61), SIMDE_FLOAT64_C(   462.62), SIMDE_FLOAT64_C(   740.08), SIMDE_FLOAT64_C(  -115.60) },
       INT32_C(         179),
      { SIMDE_FLOAT64_C(   800.61), SIMDE_FLOAT64_C(   462.62), SIMDE_FLOAT64_C(   740.08), SIMDE_FLOAT64_C(  -115.60) } },
    { { SIMDE_FLOAT64_C(  -935.66),        SIMDE_MATH_INFINITY, SIMDE_FLOAT64_C(  -515.62), SIMDE_FLOAT64_C(   351.80) },
       INT32_C(         195),
      { SIMDE_FLOAT64_C(  -935.66),        SIMDE_MATH_INFINITY, SIMDE_FLOAT64_C(  -515.62), SIMDE_FLOAT64_C(   351.80) } },
    { { SIMDE_FLOAT64_C(  -557.08), SIMDE_FLOAT64_C(   858.00), SIMDE_FLOAT64_C(   573.05), SIMDE_FLOAT64_C(   143.48) },
       INT32_C(         211),
      { SIMDE_FLOAT64_C(  -557.08), SIMDE_FLOAT64_C(   858.00), SIMDE_FLOAT64_C(   573.05), SIMDE_FLOAT64_C(   143.48) } },
    { { SIMDE_FLOAT64_C(  -575.60), SIMDE_FLOAT64_C(   117.28), SIMDE_FLOAT64_C(   620.48), SIMDE_FLOAT64_C(    92.46) },
       INT32_C(         227),
      { SIMDE_FLOAT64_C(  -575.60), SIMDE_FLOAT64_C(   117.28), SIMDE_FLOAT64_C(   620.48), SIMDE_FLOAT64_C(    92.46) } },
    { { SIMDE_FLOAT64_C(    97.75), SIMDE_FLOAT64_C(  -655.51), SIMDE_FLOAT64_C(   411.01), SIMDE_FLOAT64_C(   122.09) },
       INT32_C(         243),
      { SIMDE_FLOAT64_C(    97.75), SIMDE_FLOAT64_C(  -655.51), SIMDE_FLOAT64_C(   411.01), SIMDE_FLOAT64_C(   122.09) } },
    { { SIMDE_FLOAT64_C(   -20.98), SIMDE_FLOAT64_C(   254.94), SIMDE_FLOAT64_C(   286.44), SIMDE_FLOAT64_C(  -223.15) },
       INT32_C(           4),
      { SIMDE_FLOAT64_C(   -21.00), SIMDE_FLOAT64_C(   255.00), SIMDE_FLOAT64_C(   286.00), SIMDE_FLOAT64_C(  -223.00) } },
    { { SIMDE_FLOAT64_C(  -250.94), SIMDE_FLOAT64_C(  -483.07), SIMDE_FLOAT64_C(   939.94), SIMDE_FLOAT64_C(   596.62) },
       INT32_C(          20),
      { SIMDE_FLOAT64_C(  -251.00), SIMDE_FLOAT64_C(  -483.00), SIMDE_FLOAT64_C(   940.00), SIMDE_FLOAT64_C(   596.50) } },
    { { SIMDE_FLOAT64_C(   669.39), SIMDE_FLOAT64_C(  -919.01), SIMDE_FLOAT64_C(   933.07), SIMDE_FLOAT64_C(  -561.56) },
       INT32_C(          36),
      { SIMDE_FLOAT64_C(   669.50), SIMDE_FLOAT64_C(  -919.00), SIMDE_FLOAT64_C(   933.00), SIMDE_FLOAT64_C(  -561.50) } },
    { { SIMDE_FLOAT64_C(  -664.59), SIMDE_FLOAT64_C(  -118.65), SIMDE_FLOAT64_C(   800.00), SIMDE_FLOAT64_C(   908.47) },
       INT32_C(          52),
      { SIMDE_FLOAT64_C(  -664.62), SIMDE_FLOAT64_C(  -118.62), SIMDE_FLOAT64_C(   800.00), SIMDE_FLOAT64_C(   908.50) } },
    { { SIMDE_FLOAT64_C(  -229.64), SIMDE_FLOAT64_C(  -667.13), SIMDE_FLOAT64_C(   142.12), SIMDE_FLOAT64_C(  -609.16) },
       INT32_C(          68),
      { SIMDE_FLOAT64_C(  -229.62), SIMDE_FLOAT64_C(  -667.12), SIMDE_FLOAT64_C(   142.12), SIMDE_FLOAT64_C(  -609.19) } },
    { {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   488.59), SIMDE_FLOAT64_C(   769.82), SIMDE_FLOAT64_C(   523.59) },
       INT32_C(          84),
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   488.59), SIMDE_FLOAT64_C(   769.81), SIMDE_FLOAT64_C(   523.59) } },
    { { SIMDE_FLOAT64_C(  -497.40), SIMDE_FLOAT64_C(   865.61), SIMDE_FLOAT64_C(    46.32), SIMDE_FLOAT64_C(   279.46) },
       INT32_C(         100),
      { SIMDE_FLOAT64_C(  -497.41), SIMDE_FLOAT64_C(   865.61), SIMDE_FLOAT64_C(    46.31), SIMDE_FLOAT64_C(   279.45) } },
    { {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   796.38), SIMDE_FLOAT64_C(  -138.90), SIMDE_FLOAT64_C(   392.00) },
       INT32_C(         116),
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   796.38), SIMDE_FLOAT64_C(  -138.90), SIMDE_FLOAT64_C(   392.00) } },
    { { SIMDE_FLOAT64_C(   472.99),       -SIMDE_MATH_INFINITY, SIMDE_FLOAT64_C(   -31.06), SIMDE_FLOAT64_C(   414.99) },
       INT32_C(         132),
      { SIMDE_FLOAT64_C(   472.99),       -SIMDE_MATH_INFINITY, SIMDE_FLOAT64_C(   -31.06), SIMDE_FLOAT64_C(   414.99) } },
    { {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   875.12), SIMDE_FLOAT64_C(   985.35), SIMDE_FLOAT64_C(  -112.53) },
       INT32_C(         148),
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   875.12), SIMDE_FLOAT64_C(   985.35), SIMDE_FLOAT64_C(  -112.53) } },
    { {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   129.82), SIMDE_FLOAT64_C(   864.78), SIMDE_FLOAT64_C(  -917.38) },
       INT32_C(         164),
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   129.82), SIMDE_FLOAT64_C(   864.78), SIMDE_FLOAT64_C(  -917.38) } },
    { { SIMDE_FLOAT64_C(   842.49),       -SIMDE_MATH_INFINITY, SIMDE_FLOAT64_C(  -658.93), SIMDE_FLOAT64_C(  -111.19) },
       INT32_C(         180),
      { SIMDE_FLOAT64_C(   842.49),       -SIMDE_MATH_INFINITY, SIMDE_FLOAT64_C(  -658.93), SIMDE_FLOAT64_C(  -111.19) } },
    { { SIMDE_FLOAT64_C(  -768.16), SIMDE_FLOAT64_C(  -876.66), SIMDE_FLOAT64_C(  -923.82), SIMDE_FLOAT64_C(  -390.51) },
       INT32_C(         196),
      { SIMDE_FLOAT64_C(  -768.16), SIMDE_FLOAT64_C(  -876.66), SIMDE_FLOAT64_C(  -923.82), SIMDE_FLOAT64_C(  -390.51) } },
    { { SIMDE_FLOAT64_C(   549.18), SIMDE_FLOAT64_C(   -79.79), SIMDE_FLOAT64_C(   622.77), SIMDE_FLOAT64_C(   -35.84) },
       INT32_C(         212),
      { SIMDE_FLOAT64_C(   549.18), SIMDE_FLOAT64_C(   -79.79), SIMDE_FLOAT64_C(   622.77), SIMDE_FLOAT64_C(   -35.84) } },
    { { SIMDE_FLOAT64_C(   473.06), SIMDE_FLOAT64_C(  -820.85), SIMDE_FLOAT64_C(  -879.06), SIMDE_FLOAT64_C(   348.18) },
       INT32_C(         228),
      { SIMDE_FLOAT64_C(   473.06), SIMDE_FLOAT64_C(  -820.85), SIMDE_FLOAT64_C(  -879.06), SIMDE_FLOAT64_C(   348.18) } },
    { {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(  -634.59), SIMDE_FLOAT64_C(  -459.31), SIMDE_FLOAT64_C(   321.20) },
       INT32_C(         244),
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(  -634.59), SIMDE_FLOAT64_C(  -459.31), SIMDE_FLOAT64_C(   321.20) } },
  };

  simde__m256d a, r;

  a = simde_mm256_loadu_pd(test_vec[0].a);
  r = simde_mm256_roundscale_pd(a, INT32_C(           0));
  simde_test_x86_assert_equal_f64x4(r, simde_mm256_loadu_pd(test_vec[0].r), 1);

  a = simde_mm256_loadu_pd(test_vec[1].a);
  r = simde_mm256_roundscale_pd(a, INT32_C(          16));
  simde_test_x86_assert_equal_f64x4(r, simde_mm256_loadu_pd(test_vec[1].r), 1);

  a = simde_mm256_loadu_pd(test_vec[2].a);
  r = simde_mm256_roundscale_pd(a, INT32_C(          32));
  simde_test_x86_assert_equal_f64x4(r, simde_mm256_loadu_pd(test_vec[2].r), 1);

  a = simde_mm256_loadu_pd(test_vec[3].a);
  r = simde_mm256_roundscale_pd(a, INT32_C(          48));
  simde_test_x86_assert_equal_f64x4(r, simde_mm256_loadu_pd(test_vec[3].r), 1);

  a = simde_mm256_loadu_pd(test_vec[4].a);
  r = simde_mm256_roundscale_pd(a, INT32_C(          64));
  simde_test_x86_assert_equal_f64x4(r, simde_mm256_loadu_pd(test_vec[4].r), 1);

  a = simde_mm256_loadu_pd(test_vec[5].a);
  r = simde_mm256_roundscale_pd(a, INT32_C(          80));
  simde_test_x86_assert_equal_f64x4(r, simde_mm256_loadu_pd(test_vec[5].r), 1);

  a = simde_mm256_loadu_pd(test_vec[6].a);
  r = simde_mm256_roundscale_pd(a, INT32_C(          96));
  simde_test_x86_assert_equal_f64x4(r, simde_mm256_loadu_pd(test_vec[6].r), 1);

  a = simde_mm256_loadu_pd(test_vec[7].a);
  r = simde_mm256_roundscale_pd(a, INT32_C(         112));
  simde_test_x86_assert_equal_f64x4(r, simde_mm256_loadu_pd(test_vec[7].r), 1);

  a = simde_mm256_loadu_pd(test_vec[8].a);
  r = simde_mm256_roundscale_pd(a, INT32_C(         128));
  simde_test_x86_assert_equal_f64x4(r, simde_mm256_loadu_pd(test_vec[8].r), 1);

  a = simde_mm256_loadu_pd(test_vec[9].a);
  r = simde_mm256_roundscale_pd(a, INT32_C(         144));
  simde_test_x86_assert_equal_f64x4(r, simde_mm256_loadu_pd(test_vec[9].r), 1);

  a = simde_mm256_loadu_pd(test_vec[10].a);
  r = simde_mm256_roundscale_pd(a, INT32_C(         160));
  simde_test_x86_assert_equal_f64x4(r, simde_mm256_loadu_pd(test_vec[10].r), 1);

  a = simde_mm256_loadu_pd(test_vec[11].a);
  r = simde_mm256_roundscale_pd(a, INT32_C(         176));
  simde_test_x86_assert_equal_f64x4(r, simde_mm256_loadu_pd(test_vec[11].r), 1);

  a = simde_mm256_loadu_pd(test_vec[12].a);
  r = simde_mm256_roundscale_pd(a, INT32_C(         192));
  simde_test_x86_assert_equal_f64x4(r, simde_mm256_loadu_pd(test_vec[12].r), 1);

  a = simde_mm256_loadu_pd(test_vec[13].a);
  r = simde_mm256_roundscale_pd(a, INT32_C(         208));
  simde_test_x86_assert_equal_f64x4(r, simde_mm256_loadu_pd(test_vec[13].r), 1);

  a = simde_mm256_loadu_pd(test_vec[14].a);
  r = simde_mm256_roundscale_pd(a, INT32_C(         224));
  simde_test_x86_assert_equal_f64x4(r, simde_mm256_loadu_pd(test_vec[14].r), 1);

  a = simde_mm256_loadu_pd(test_vec[15].a);
  r = simde_mm256_roundscale_pd(a, INT32_C(         240));
  simde_test_x86_assert_equal_f64x4(r, simde_mm256_loadu_pd(test_vec[15].r), 1);

  a = simde_mm256_loadu_pd(test_vec[16].a);
  r = simde_mm256_roundscale_pd(a, INT32_C(           1));
  simde_test_x86_assert_equal_f64x4(r, simde_mm256_loadu_pd(test_vec[16].r), 1);

  a = simde_mm256_loadu_pd(test_vec[17].a);
  r = simde_mm256_roundscale_pd(a, INT32_C(          17));
  simde_test_x86_assert_equal_f64x4(r, simde_mm256_loadu_pd(test_vec[17].r), 1);

  a = simde_mm256_loadu_pd(test_vec[18].a);
  r = simde_mm256_roundscale_pd(a, INT32_C(          33));
  simde_test_x86_assert_equal_f64x4(r, simde_mm256_loadu_pd(test_vec[18].r), 1);

  a = simde_mm256_loadu_pd(test_vec[19].a);
  r = simde_mm256_roundscale_pd(a, INT32_C(          49));
  simde_test_x86_assert_equal_f64x4(r, simde_mm256_loadu_pd(test_vec[19].r), 1);

  a = simde_mm256_loadu_pd(test_vec[20].a);
  r = simde_mm256_roundscale_pd(a, INT32_C(          65));
  simde_test_x86_assert_equal_f64x4(r, simde_mm256_loadu_pd(test_vec[20].r), 1);

  a = simde_mm256_loadu_pd(test_vec[21].a);
  r = simde_mm256_roundscale_pd(a, INT32_C(          81));
  simde_test_x86_assert_equal_f64x4(r, simde_mm256_loadu_pd(test_vec[21].r), 1);

  a = simde_mm256_loadu_pd(test_vec[22].a);
  r = simde_mm256_roundscale_pd(a, INT32_C(          97));
  simde_test_x86_assert_equal_f64x4(r, simde_mm256_loadu_pd(test_vec[22].r), 1);

  a = simde_mm256_loadu_pd(test_vec[23].a);
  r = simde_mm256_roundscale_pd(a, INT32_C(         113));
  simde_test_x86_assert_equal_f64x4(r, simde_mm256_loadu_pd(test_vec[23].r), 1);

  a = simde_mm256_loadu_pd(test_vec[24].a);
  r = simde_mm256_roundscale_pd(a, INT32_C(         129));
  simde_test_x86_assert_equal_f64x4(r, simde_mm256_loadu_pd(test_vec[24].r), 1);

  a = simde_mm256_loadu_pd(test_vec[25].a);
  r = simde_mm256_roundscale_pd(a, INT32_C(         145));
  simde_test_x86_assert_equal_f64x4(r, simde_mm256_loadu_pd(test_vec[25].r), 1);

  a = simde_mm256_loadu_pd(test_vec[26].a);
  r = simde_mm256_roundscale_pd(a, INT32_C(         161));
  simde_test_x86_assert_equal_f64x4(r, simde_mm256_loadu_pd(test_vec[26].r), 1);

  a = simde_mm256_loadu_pd(test_vec[27].a);
  r = simde_mm256_roundscale_pd(a, INT32_C(         177));
  simde_test_x86_assert_equal_f64x4(r, simde_mm256_loadu_pd(test_vec[27].r), 1);

  a = simde_mm256_loadu_pd(test_vec[28].a);
  r = simde_mm256_roundscale_pd(a, INT32_C(         193));
  simde_test_x86_assert_equal_f64x4(r, simde_mm256_loadu_pd(test_vec[28].r), 1);

  a = simde_mm256_loadu_pd(test_vec[29].a);
  r = simde_mm256_roundscale_pd(a, INT32_C(         209));
  simde_test_x86_assert_equal_f64x4(r, simde_mm256_loadu_pd(test_vec[29].r), 1);

  a = simde_mm256_loadu_pd(test_vec[30].a);
  r = simde_mm256_roundscale_pd(a, INT32_C(         225));
  simde_test_x86_assert_equal_f64x4(r, simde_mm256_loadu_pd(test_vec[30].r), 1);

  a = simde_mm256_loadu_pd(test_vec[31].a);
  r = simde_mm256_roundscale_pd(a, INT32_C(         241));
  simde_test_x86_assert_equal_f64x4(r, simde_mm256_loadu_pd(test_vec[31].r), 1);

  a = simde_mm256_loadu_pd(test_vec[32].a);
  r = simde_mm256_roundscale_pd(a, INT32_C(           2));
  simde_test_x86_assert_equal_f64x4(r, simde_mm256_loadu_pd(test_vec[32].r), 1);

  a = simde_mm256_loadu_pd(test_vec[33].a);
  r = simde_mm256_roundscale_pd(a, INT32_C(          18));
  simde_test_x86_assert_equal_f64x4(r, simde_mm256_loadu_pd(test_vec[33].r), 1);

  a = simde_mm256_loadu_pd(test_vec[34].a);
  r = simde_mm256_roundscale_pd(a, INT32_C(          34));
  simde_test_x86_assert_equal_f64x4(r, simde_mm256_loadu_pd(test_vec[34].r), 1);

  a = simde_mm256_loadu_pd(test_vec[35].a);
  r = simde_mm256_roundscale_pd(a, INT32_C(          50));
  simde_test_x86_assert_equal_f64x4(r, simde_mm256_loadu_pd(test_vec[35].r), 1);

  a = simde_mm256_loadu_pd(test_vec[36].a);
  r = simde_mm256_roundscale_pd(a, INT32_C(          66));
  simde_test_x86_assert_equal_f64x4(r, simde_mm256_loadu_pd(test_vec[36].r), 1);

  a = simde_mm256_loadu_pd(test_vec[37].a);
  r = simde_mm256_roundscale_pd(a, INT32_C(          82));
  simde_test_x86_assert_equal_f64x4(r, simde_mm256_loadu_pd(test_vec[37].r), 1);

  a = simde_mm256_loadu_pd(test_vec[38].a);
  r = simde_mm256_roundscale_pd(a, INT32_C(          98));
  simde_test_x86_assert_equal_f64x4(r, simde_mm256_loadu_pd(test_vec[38].r), 1);

  a = simde_mm256_loadu_pd(test_vec[39].a);
  r = simde_mm256_roundscale_pd(a, INT32_C(         114));
  simde_test_x86_assert_equal_f64x4(r, simde_mm256_loadu_pd(test_vec[39].r), 1);

  a = simde_mm256_loadu_pd(test_vec[40].a);
  r = simde_mm256_roundscale_pd(a, INT32_C(         130));
  simde_test_x86_assert_equal_f64x4(r, simde_mm256_loadu_pd(test_vec[40].r), 1);

  a = simde_mm256_loadu_pd(test_vec[41].a);
  r = simde_mm256_roundscale_pd(a, INT32_C(         146));
  simde_test_x86_assert_equal_f64x4(r, simde_mm256_loadu_pd(test_vec[41].r), 1);

  a = simde_mm256_loadu_pd(test_vec[42].a);
  r = simde_mm256_roundscale_pd(a, INT32_C(         162));
  simde_test_x86_assert_equal_f64x4(r, simde_mm256_loadu_pd(test_vec[42].r), 1);

  a = simde_mm256_loadu_pd(test_vec[43].a);
  r = simde_mm256_roundscale_pd(a, INT32_C(         178));
  simde_test_x86_assert_equal_f64x4(r, simde_mm256_loadu_pd(test_vec[43].r), 1);

  a = simde_mm256_loadu_pd(test_vec[44].a);
  r = simde_mm256_roundscale_pd(a, INT32_C(         194));
  simde_test_x86_assert_equal_f64x4(r, simde_mm256_loadu_pd(test_vec[44].r), 1);

  a = simde_mm256_loadu_pd(test_vec[45].a);
  r = simde_mm256_roundscale_pd(a, INT32_C(         210));
  simde_test_x86_assert_equal_f64x4(r, simde_mm256_loadu_pd(test_vec[45].r), 1);

  a = simde_mm256_loadu_pd(test_vec[46].a);
  r = simde_mm256_roundscale_pd(a, INT32_C(         226));
  simde_test_x86_assert_equal_f64x4(r, simde_mm256_loadu_pd(test_vec[46].r), 1);

  a = simde_mm256_loadu_pd(test_vec[47].a);
  r = simde_mm256_roundscale_pd(a, INT32_C(         242));
  simde_test_x86_assert_equal_f64x4(r, simde_mm256_loadu_pd(test_vec[47].r), 1);

  a = simde_mm256_loadu_pd(test_vec[48].a);
  r = simde_mm256_roundscale_pd(a, INT32_C(           3));
  simde_test_x86_assert_equal_f64x4(r, simde_mm256_loadu_pd(test_vec[48].r), 1);

  a = simde_mm256_loadu_pd(test_vec[49].a);
  r = simde_mm256_roundscale_pd(a, INT32_C(          19));
  simde_test_x86_assert_equal_f64x4(r, simde_mm256_loadu_pd(test_vec[49].r), 1);

  a = simde_mm256_loadu_pd(test_vec[50].a);
  r = simde_mm256_roundscale_pd(a, INT32_C(          35));
  simde_test_x86_assert_equal_f64x4(r, simde_mm256_loadu_pd(test_vec[50].r), 1);

  a = simde_mm256_loadu_pd(test_vec[51].a);
  r = simde_mm256_roundscale_pd(a, INT32_C(          51));
  simde_test_x86_assert_equal_f64x4(r, simde_mm256_loadu_pd(test_vec[51].r), 1);

  a = simde_mm256_loadu_pd(test_vec[52].a);
  r = simde_mm256_roundscale_pd(a, INT32_C(          67));
  simde_test_x86_assert_equal_f64x4(r, simde_mm256_loadu_pd(test_vec[52].r), 1);

  a = simde_mm256_loadu_pd(test_vec[53].a);
  r = simde_mm256_roundscale_pd(a, INT32_C(          83));
  simde_test_x86_assert_equal_f64x4(r, simde_mm256_loadu_pd(test_vec[53].r), 1);

  a = simde_mm256_loadu_pd(test_vec[54].a);
  r = simde_mm256_roundscale_pd(a, INT32_C(          99));
  simde_test_x86_assert_equal_f64x4(r, simde_mm256_loadu_pd(test_vec[54].r), 1);

  a = simde_mm256_loadu_pd(test_vec[55].a);
  r = simde_mm256_roundscale_pd(a, INT32_C(         115));
  simde_test_x86_assert_equal_f64x4(r, simde_mm256_loadu_pd(test_vec[55].r), 1);

  a = simde_mm256_loadu_pd(test_vec[56].a);
  r = simde_mm256_roundscale_pd(a, INT32_C(         131));
  simde_test_x86_assert_equal_f64x4(r, simde_mm256_loadu_pd(test_vec[56].r), 1);

  a = simde_mm256_loadu_pd(test_vec[57].a);
  r = simde_mm256_roundscale_pd(a, INT32_C(         147));
  simde_test_x86_assert_equal_f64x4(r, simde_mm256_loadu_pd(test_vec[57].r), 1);

  a = simde_mm256_loadu_pd(test_vec[58].a);
  r = simde_mm256_roundscale_pd(a, INT32_C(         163));
  simde_test_x86_assert_equal_f64x4(r, simde_mm256_loadu_pd(test_vec[58].r), 1);

  a = simde_mm256_loadu_pd(test_vec[59].a);
  r = simde_mm256_roundscale_pd(a, INT32_C(         179));
  simde_test_x86_assert_equal_f64x4(r, simde_mm256_loadu_pd(test_vec[59].r), 1);

  a = simde_mm256_loadu_pd(test_vec[60].a);
  r = simde_mm256_roundscale_pd(a, INT32_C(         195));
  simde_test_x86_assert_equal_f64x4(r, simde_mm256_loadu_pd(test_vec[60].r), 1);

  a = simde_mm256_loadu_pd(test_vec[61].a);
  r = simde_mm256_roundscale_pd(a, INT32_C(         211));
  simde_test_x86_assert_equal_f64x4(r, simde_mm256_loadu_pd(test_vec[61].r), 1);

  a = simde_mm256_loadu_pd(test_vec[62].a);
  r = simde_mm256_roundscale_pd(a, INT32_C(         227));
  simde_test_x86_assert_equal_f64x4(r, simde_mm256_loadu_pd(test_vec[62].r), 1);

  a = simde_mm256_loadu_pd(test_vec[63].a);
  r = simde_mm256_roundscale_pd(a, INT32_C(         243));
  simde_test_x86_assert_equal_f64x4(r, simde_mm256_loadu_pd(test_vec[63].r), 1);

  a = simde_mm256_loadu_pd(test_vec[64].a);
  r = simde_mm256_roundscale_pd(a, INT32_C(           4));
  simde_test_x86_assert_equal_f64x4(r, simde_mm256_loadu_pd(test_vec[64].r), 1);

  a = simde_mm256_loadu_pd(test_vec[65].a);
  r = simde_mm256_roundscale_pd(a, INT32_C(          20));
  simde_test_x86_assert_equal_f64x4(r, simde_mm256_loadu_pd(test_vec[65].r), 1);

  a = simde_mm256_loadu_pd(test_vec[66].a);
  r = simde_mm256_roundscale_pd(a, INT32_C(          36));
  simde_test_x86_assert_equal_f64x4(r, simde_mm256_loadu_pd(test_vec[66].r), 1);

  a = simde_mm256_loadu_pd(test_vec[67].a);
  r = simde_mm256_roundscale_pd(a, INT32_C(          52));
  simde_test_x86_assert_equal_f64x4(r, simde_mm256_loadu_pd(test_vec[67].r), 1);

  a = simde_mm256_loadu_pd(test_vec[68].a);
  r = simde_mm256_roundscale_pd(a, INT32_C(          68));
  simde_test_x86_assert_equal_f64x4(r, simde_mm256_loadu_pd(test_vec[68].r), 1);

  a = simde_mm256_loadu_pd(test_vec[69].a);
  r = simde_mm256_roundscale_pd(a, INT32_C(          84));
  simde_test_x86_assert_equal_f64x4(r, simde_mm256_loadu_pd(test_vec[69].r), 1);

  a = simde_mm256_loadu_pd(test_vec[70].a);
  r = simde_mm256_roundscale_pd(a, INT32_C(         100));
  simde_test_x86_assert_equal_f64x4(r, simde_mm256_loadu_pd(test_vec[70].r), 1);

  a = simde_mm256_loadu_pd(test_vec[71].a);
  r = simde_mm256_roundscale_pd(a, INT32_C(         116));
  simde_test_x86_assert_equal_f64x4(r, simde_mm256_loadu_pd(test_vec[71].r), 1);

  a = simde_mm256_loadu_pd(test_vec[72].a);
  r = simde_mm256_roundscale_pd(a, INT32_C(         132));
  simde_test_x86_assert_equal_f64x4(r, simde_mm256_loadu_pd(test_vec[72].r), 1);

  a = simde_mm256_loadu_pd(test_vec[73].a);
  r = simde_mm256_roundscale_pd(a, INT32_C(         148));
  simde_test_x86_assert_equal_f64x4(r, simde_mm256_loadu_pd(test_vec[73].r), 1);

  a = simde_mm256_loadu_pd(test_vec[74].a);
  r = simde_mm256_roundscale_pd(a, INT32_C(         164));
  simde_test_x86_assert_equal_f64x4(r, simde_mm256_loadu_pd(test_vec[74].r), 1);

  a = simde_mm256_loadu_pd(test_vec[75].a);
  r = simde_mm256_roundscale_pd(a, INT32_C(         180));
  simde_test_x86_assert_equal_f64x4(r, simde_mm256_loadu_pd(test_vec[75].r), 1);

  a = simde_mm256_loadu_pd(test_vec[76].a);
  r = simde_mm256_roundscale_pd(a, INT32_C(         196));
  simde_test_x86_assert_equal_f64x4(r, simde_mm256_loadu_pd(test_vec[76].r), 1);

  a = simde_mm256_loadu_pd(test_vec[77].a);
  r = simde_mm256_roundscale_pd(a, INT32_C(         212));
  simde_test_x86_assert_equal_f64x4(r, simde_mm256_loadu_pd(test_vec[77].r), 1);

  a = simde_mm256_loadu_pd(test_vec[78].a);
  r = simde_mm256_roundscale_pd(a, INT32_C(         228));
  simde_test_x86_assert_equal_f64x4(r, simde_mm256_loadu_pd(test_vec[78].r), 1);

  a = simde_mm256_loadu_pd(test_vec[79].a);
  r = simde_mm256_roundscale_pd(a, INT32_C(         244));
  simde_test_x86_assert_equal_f64x4(r, simde_mm256_loadu_pd(test_vec[79].r), 1);

  return 0;
#else
  fputc('\n', stdout);
  int round_type[5] = {SIMDE_MM_FROUND_TO_NEAREST_INT, SIMDE_MM_FROUND_TO_NEG_INF, SIMDE_MM_FROUND_TO_POS_INF, SIMDE_MM_FROUND_TO_ZERO, SIMDE_MM_FROUND_CUR_DIRECTION};
  for (int i = 0 ; i < 5 ; i++) {
    for (int j = 0 ; j < 16 ; j++) {
      simde__m256d a = simde_test_x86_random_f64x4(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
      if((simde_test_codegen_rand() & 1)) {
        if((simde_test_codegen_rand() & 1))
          a = simde_mm256_blend_pd(a, simde_mm256_set1_pd(SIMDE_MATH_NAN), 1);
        else {
          if((simde_test_codegen_rand() & 1))
            a = simde_mm256_blend_pd(a, simde_mm256_set1_pd(SIMDE_MATH_INFINITY), 2);
          else
            a = simde_mm256_blend_pd(a, simde_mm256_set1_pd(-SIMDE_MATH_INFINITY), 2);
        }
      }
      int imm8 = ((j << 4) | round_type[i]) & 255;
      simde__m256d r;
      SIMDE_CONSTIFY_256_(simde_mm256_roundscale_pd, r, simde_mm256_setzero_pd(), imm8, a);

      simde_test_x86_write_f64x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
      simde_test_codegen_write_i32(2, imm8, SIMDE_TEST_VEC_POS_MIDDLE);
      simde_test_x86_write_f64x4(2, r, SIMDE_TEST_VEC_POS_LAST);
    }
  }
  return 1;
#endif
}

static int
test_simde_mm512_roundscale_pd (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde_float64 a[8];
    const int32_t imm8;
    const simde_float64 r[8];
  } test_vec[] = {
    { { SIMDE_FLOAT64_C(   646.70), SIMDE_FLOAT64_C(   958.12), SIMDE_FLOAT64_C(  -525.88), SIMDE_FLOAT64_C(    75.95),
        SIMDE_FLOAT64_C(   700.03), SIMDE_FLOAT64_C(  -818.76), SIMDE_FLOAT64_C(  -477.50), SIMDE_FLOAT64_C(  -567.75) },
       INT32_C(           0),
      { SIMDE_FLOAT64_C(   647.00), SIMDE_FLOAT64_C(   958.00), SIMDE_FLOAT64_C(  -526.00), SIMDE_FLOAT64_C(    76.00),
        SIMDE_FLOAT64_C(   700.00), SIMDE_FLOAT64_C(  -819.00), SIMDE_FLOAT64_C(  -478.00), SIMDE_FLOAT64_C(  -568.00) } },
    { {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(  -954.82), SIMDE_FLOAT64_C(   490.74), SIMDE_FLOAT64_C(   590.75),
        SIMDE_FLOAT64_C(   256.04), SIMDE_FLOAT64_C(     2.39), SIMDE_FLOAT64_C(  -125.09), SIMDE_FLOAT64_C(   538.23) },
       INT32_C(          16),
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(  -955.00), SIMDE_FLOAT64_C(   490.50), SIMDE_FLOAT64_C(   591.00),
        SIMDE_FLOAT64_C(   256.00), SIMDE_FLOAT64_C(     2.50), SIMDE_FLOAT64_C(  -125.00), SIMDE_FLOAT64_C(   538.00) } },
    { { SIMDE_FLOAT64_C(   838.29), SIMDE_FLOAT64_C(  -236.77), SIMDE_FLOAT64_C(  -534.48), SIMDE_FLOAT64_C(  -282.31),
        SIMDE_FLOAT64_C(     5.53), SIMDE_FLOAT64_C(    43.17), SIMDE_FLOAT64_C(   489.31), SIMDE_FLOAT64_C(  -307.21) },
       INT32_C(          32),
      { SIMDE_FLOAT64_C(   838.25), SIMDE_FLOAT64_C(  -236.75), SIMDE_FLOAT64_C(  -534.50), SIMDE_FLOAT64_C(  -282.25),
        SIMDE_FLOAT64_C(     5.50), SIMDE_FLOAT64_C(    43.25), SIMDE_FLOAT64_C(   489.25), SIMDE_FLOAT64_C(  -307.25) } },
    { { SIMDE_FLOAT64_C(  -796.64), SIMDE_FLOAT64_C(   103.62), SIMDE_FLOAT64_C(  -723.76), SIMDE_FLOAT64_C(   850.06),
        SIMDE_FLOAT64_C(    61.73), SIMDE_FLOAT64_C(  -249.64), SIMDE_FLOAT64_C(   -73.99), SIMDE_FLOAT64_C(  -238.23) },
       INT32_C(          48),
      { SIMDE_FLOAT64_C(  -796.62), SIMDE_FLOAT64_C(   103.62), SIMDE_FLOAT64_C(  -723.75), SIMDE_FLOAT64_C(   850.00),
        SIMDE_FLOAT64_C(    61.75), SIMDE_FLOAT64_C(  -249.62), SIMDE_FLOAT64_C(   -74.00), SIMDE_FLOAT64_C(  -238.25) } },
    { { SIMDE_FLOAT64_C(   448.51), SIMDE_FLOAT64_C(   194.02), SIMDE_FLOAT64_C(   247.85), SIMDE_FLOAT64_C(  -445.94),
        SIMDE_FLOAT64_C(   239.20), SIMDE_FLOAT64_C(  -261.42), SIMDE_FLOAT64_C(  -855.19), SIMDE_FLOAT64_C(  -504.76) },
       INT32_C(          64),
      { SIMDE_FLOAT64_C(   448.50), SIMDE_FLOAT64_C(   194.00), SIMDE_FLOAT64_C(   247.88), SIMDE_FLOAT64_C(  -445.94),
        SIMDE_FLOAT64_C(   239.19), SIMDE_FLOAT64_C(  -261.44), SIMDE_FLOAT64_C(  -855.19), SIMDE_FLOAT64_C(  -504.75) } },
    { {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(  -966.53), SIMDE_FLOAT64_C(    -6.53), SIMDE_FLOAT64_C(   713.46),
        SIMDE_FLOAT64_C(   871.76), SIMDE_FLOAT64_C(   756.71), SIMDE_FLOAT64_C(  -821.02), SIMDE_FLOAT64_C(  -410.55) },
       INT32_C(          80),
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(  -966.53), SIMDE_FLOAT64_C(    -6.53), SIMDE_FLOAT64_C(   713.47),
        SIMDE_FLOAT64_C(   871.75), SIMDE_FLOAT64_C(   756.72), SIMDE_FLOAT64_C(  -821.03), SIMDE_FLOAT64_C(  -410.56) } },
    { { SIMDE_FLOAT64_C(  -921.24),       -SIMDE_MATH_INFINITY, SIMDE_FLOAT64_C(  -739.11), SIMDE_FLOAT64_C(  -717.88),
        SIMDE_FLOAT64_C(  -441.36), SIMDE_FLOAT64_C(  -462.87), SIMDE_FLOAT64_C(  -867.82), SIMDE_FLOAT64_C(   620.37) },
       INT32_C(          96),
      { SIMDE_FLOAT64_C(  -921.23),       -SIMDE_MATH_INFINITY, SIMDE_FLOAT64_C(  -739.11), SIMDE_FLOAT64_C(  -717.88),
        SIMDE_FLOAT64_C(  -441.36), SIMDE_FLOAT64_C(  -462.88), SIMDE_FLOAT64_C(  -867.81), SIMDE_FLOAT64_C(   620.38) } },
    { { SIMDE_FLOAT64_C(  -780.91), SIMDE_FLOAT64_C(  -493.29), SIMDE_FLOAT64_C(   576.16), SIMDE_FLOAT64_C(   466.93),
        SIMDE_FLOAT64_C(    60.77), SIMDE_FLOAT64_C(  -184.64), SIMDE_FLOAT64_C(  -794.48), SIMDE_FLOAT64_C(   205.58) },
       INT32_C(         112),
      { SIMDE_FLOAT64_C(  -780.91), SIMDE_FLOAT64_C(  -493.29), SIMDE_FLOAT64_C(   576.16), SIMDE_FLOAT64_C(   466.93),
        SIMDE_FLOAT64_C(    60.77), SIMDE_FLOAT64_C(  -184.64), SIMDE_FLOAT64_C(  -794.48), SIMDE_FLOAT64_C(   205.58) } },
    { { SIMDE_FLOAT64_C(   946.49), SIMDE_FLOAT64_C(  -774.70), SIMDE_FLOAT64_C(   344.06), SIMDE_FLOAT64_C(   -60.04),
        SIMDE_FLOAT64_C(   938.76), SIMDE_FLOAT64_C(   215.82), SIMDE_FLOAT64_C(  -303.33), SIMDE_FLOAT64_C(  -882.26) },
       INT32_C(         128),
      { SIMDE_FLOAT64_C(   946.49), SIMDE_FLOAT64_C(  -774.70), SIMDE_FLOAT64_C(   344.06), SIMDE_FLOAT64_C(   -60.04),
        SIMDE_FLOAT64_C(   938.76), SIMDE_FLOAT64_C(   215.82), SIMDE_FLOAT64_C(  -303.33), SIMDE_FLOAT64_C(  -882.26) } },
    { {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   339.89), SIMDE_FLOAT64_C(   884.03), SIMDE_FLOAT64_C(   -86.07),
        SIMDE_FLOAT64_C(   600.78), SIMDE_FLOAT64_C(  -833.84), SIMDE_FLOAT64_C(   472.57), SIMDE_FLOAT64_C(  -862.09) },
       INT32_C(         144),
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   339.89), SIMDE_FLOAT64_C(   884.03), SIMDE_FLOAT64_C(   -86.07),
        SIMDE_FLOAT64_C(   600.78), SIMDE_FLOAT64_C(  -833.84), SIMDE_FLOAT64_C(   472.57), SIMDE_FLOAT64_C(  -862.09) } },
    { {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   356.53), SIMDE_FLOAT64_C(   475.08), SIMDE_FLOAT64_C(   644.49),
        SIMDE_FLOAT64_C(   863.24), SIMDE_FLOAT64_C(    51.24), SIMDE_FLOAT64_C(   111.42), SIMDE_FLOAT64_C(   -75.99) },
       INT32_C(         160),
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   356.53), SIMDE_FLOAT64_C(   475.08), SIMDE_FLOAT64_C(   644.49),
        SIMDE_FLOAT64_C(   863.24), SIMDE_FLOAT64_C(    51.24), SIMDE_FLOAT64_C(   111.42), SIMDE_FLOAT64_C(   -75.99) } },
    { {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   177.19), SIMDE_FLOAT64_C(   263.43), SIMDE_FLOAT64_C(  -645.10),
        SIMDE_FLOAT64_C(  -478.75), SIMDE_FLOAT64_C(  -796.61), SIMDE_FLOAT64_C(  -706.34), SIMDE_FLOAT64_C(   737.08) },
       INT32_C(         176),
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   177.19), SIMDE_FLOAT64_C(   263.43), SIMDE_FLOAT64_C(  -645.10),
        SIMDE_FLOAT64_C(  -478.75), SIMDE_FLOAT64_C(  -796.61), SIMDE_FLOAT64_C(  -706.34), SIMDE_FLOAT64_C(   737.08) } },
    { { SIMDE_FLOAT64_C(   542.35), SIMDE_FLOAT64_C(  -641.04), SIMDE_FLOAT64_C(   751.29), SIMDE_FLOAT64_C(   426.38),
        SIMDE_FLOAT64_C(   272.89), SIMDE_FLOAT64_C(   352.07), SIMDE_FLOAT64_C(   592.54), SIMDE_FLOAT64_C(  -254.53) },
       INT32_C(         192),
      { SIMDE_FLOAT64_C(   542.35), SIMDE_FLOAT64_C(  -641.04), SIMDE_FLOAT64_C(   751.29), SIMDE_FLOAT64_C(   426.38),
        SIMDE_FLOAT64_C(   272.89), SIMDE_FLOAT64_C(   352.07), SIMDE_FLOAT64_C(   592.54), SIMDE_FLOAT64_C(  -254.53) } },
    { { SIMDE_FLOAT64_C(   890.88), SIMDE_FLOAT64_C(   838.41), SIMDE_FLOAT64_C(   -84.62), SIMDE_FLOAT64_C(   247.41),
        SIMDE_FLOAT64_C(   313.49), SIMDE_FLOAT64_C(  -440.13), SIMDE_FLOAT64_C(   110.66), SIMDE_FLOAT64_C(  -635.26) },
       INT32_C(         208),
      { SIMDE_FLOAT64_C(   890.88), SIMDE_FLOAT64_C(   838.41), SIMDE_FLOAT64_C(   -84.62), SIMDE_FLOAT64_C(   247.41),
        SIMDE_FLOAT64_C(   313.49), SIMDE_FLOAT64_C(  -440.13), SIMDE_FLOAT64_C(   110.66), SIMDE_FLOAT64_C(  -635.26) } },
    { { SIMDE_FLOAT64_C(  -965.33), SIMDE_FLOAT64_C(  -768.67), SIMDE_FLOAT64_C(   -11.77), SIMDE_FLOAT64_C(  -835.73),
        SIMDE_FLOAT64_C(   408.53), SIMDE_FLOAT64_C(  -748.34), SIMDE_FLOAT64_C(  -480.84), SIMDE_FLOAT64_C(   929.78) },
       INT32_C(         224),
      { SIMDE_FLOAT64_C(  -965.33), SIMDE_FLOAT64_C(  -768.67), SIMDE_FLOAT64_C(   -11.77), SIMDE_FLOAT64_C(  -835.73),
        SIMDE_FLOAT64_C(   408.53), SIMDE_FLOAT64_C(  -748.34), SIMDE_FLOAT64_C(  -480.84), SIMDE_FLOAT64_C(   929.78) } },
    { { SIMDE_FLOAT64_C(  -187.18), SIMDE_FLOAT64_C(   666.86), SIMDE_FLOAT64_C(   355.11), SIMDE_FLOAT64_C(   224.22),
        SIMDE_FLOAT64_C(   209.21), SIMDE_FLOAT64_C(   714.08), SIMDE_FLOAT64_C(   -24.49), SIMDE_FLOAT64_C(  -364.41) },
       INT32_C(         240),
      { SIMDE_FLOAT64_C(  -187.18), SIMDE_FLOAT64_C(   666.86), SIMDE_FLOAT64_C(   355.11), SIMDE_FLOAT64_C(   224.22),
        SIMDE_FLOAT64_C(   209.21), SIMDE_FLOAT64_C(   714.08), SIMDE_FLOAT64_C(   -24.49), SIMDE_FLOAT64_C(  -364.41) } },
    { { SIMDE_FLOAT64_C(  -672.42), SIMDE_FLOAT64_C(  -771.87), SIMDE_FLOAT64_C(   732.44), SIMDE_FLOAT64_C(   817.56),
        SIMDE_FLOAT64_C(  -880.99), SIMDE_FLOAT64_C(   570.85), SIMDE_FLOAT64_C(  -267.07), SIMDE_FLOAT64_C(   366.42) },
       INT32_C(           1),
      { SIMDE_FLOAT64_C(  -673.00), SIMDE_FLOAT64_C(  -772.00), SIMDE_FLOAT64_C(   732.00), SIMDE_FLOAT64_C(   817.00),
        SIMDE_FLOAT64_C(  -881.00), SIMDE_FLOAT64_C(   570.00), SIMDE_FLOAT64_C(  -268.00), SIMDE_FLOAT64_C(   366.00) } },
    { { SIMDE_FLOAT64_C(   292.80), SIMDE_FLOAT64_C(  -522.92), SIMDE_FLOAT64_C(   249.08), SIMDE_FLOAT64_C(   -35.91),
        SIMDE_FLOAT64_C(  -488.25), SIMDE_FLOAT64_C(   480.41), SIMDE_FLOAT64_C(   952.32), SIMDE_FLOAT64_C(  -323.98) },
       INT32_C(          17),
      { SIMDE_FLOAT64_C(   292.50), SIMDE_FLOAT64_C(  -523.00), SIMDE_FLOAT64_C(   249.00), SIMDE_FLOAT64_C(   -36.00),
        SIMDE_FLOAT64_C(  -488.50), SIMDE_FLOAT64_C(   480.00), SIMDE_FLOAT64_C(   952.00), SIMDE_FLOAT64_C(  -324.00) } },
    { { SIMDE_FLOAT64_C(  -796.02),        SIMDE_MATH_INFINITY, SIMDE_FLOAT64_C(  -181.28), SIMDE_FLOAT64_C(  -340.97),
        SIMDE_FLOAT64_C(  -992.00), SIMDE_FLOAT64_C(  -514.43), SIMDE_FLOAT64_C(  -985.86), SIMDE_FLOAT64_C(   232.23) },
       INT32_C(          33),
      { SIMDE_FLOAT64_C(  -796.25),        SIMDE_MATH_INFINITY, SIMDE_FLOAT64_C(  -181.50), SIMDE_FLOAT64_C(  -341.00),
        SIMDE_FLOAT64_C(  -992.00), SIMDE_FLOAT64_C(  -514.50), SIMDE_FLOAT64_C(  -986.00), SIMDE_FLOAT64_C(   232.00) } },
    { { SIMDE_FLOAT64_C(  -669.63), SIMDE_FLOAT64_C(  -284.81), SIMDE_FLOAT64_C(  -464.69), SIMDE_FLOAT64_C(  -441.51),
        SIMDE_FLOAT64_C(  -552.37), SIMDE_FLOAT64_C(  -647.13), SIMDE_FLOAT64_C(  -322.50), SIMDE_FLOAT64_C(  -981.53) },
       INT32_C(          49),
      { SIMDE_FLOAT64_C(  -669.75), SIMDE_FLOAT64_C(  -284.88), SIMDE_FLOAT64_C(  -464.75), SIMDE_FLOAT64_C(  -441.62),
        SIMDE_FLOAT64_C(  -552.38), SIMDE_FLOAT64_C(  -647.25), SIMDE_FLOAT64_C(  -322.50), SIMDE_FLOAT64_C(  -981.62) } },
    { {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   -97.19), SIMDE_FLOAT64_C(  -621.40), SIMDE_FLOAT64_C(  -479.00),
        SIMDE_FLOAT64_C(  -848.11), SIMDE_FLOAT64_C(   342.69), SIMDE_FLOAT64_C(    32.75), SIMDE_FLOAT64_C(   632.30) },
       INT32_C(          65),
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   -97.25), SIMDE_FLOAT64_C(  -621.44), SIMDE_FLOAT64_C(  -479.00),
        SIMDE_FLOAT64_C(  -848.12), SIMDE_FLOAT64_C(   342.69), SIMDE_FLOAT64_C(    32.75), SIMDE_FLOAT64_C(   632.25) } },
    { { SIMDE_FLOAT64_C(  -478.76),        SIMDE_MATH_INFINITY, SIMDE_FLOAT64_C(   -96.06), SIMDE_FLOAT64_C(   339.95),
        SIMDE_FLOAT64_C(  -841.98), SIMDE_FLOAT64_C(   -88.06), SIMDE_FLOAT64_C(   825.52), SIMDE_FLOAT64_C(  -827.83) },
       INT32_C(          81),
      { SIMDE_FLOAT64_C(  -478.78),        SIMDE_MATH_INFINITY, SIMDE_FLOAT64_C(   -96.06), SIMDE_FLOAT64_C(   339.94),
        SIMDE_FLOAT64_C(  -842.00), SIMDE_FLOAT64_C(   -88.06), SIMDE_FLOAT64_C(   825.50), SIMDE_FLOAT64_C(  -827.84) } },
    { {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   850.67), SIMDE_FLOAT64_C(  -384.42), SIMDE_FLOAT64_C(  -112.78),
        SIMDE_FLOAT64_C(  -590.84), SIMDE_FLOAT64_C(    63.20), SIMDE_FLOAT64_C(   240.09), SIMDE_FLOAT64_C(    86.66) },
       INT32_C(          97),
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   850.66), SIMDE_FLOAT64_C(  -384.42), SIMDE_FLOAT64_C(  -112.78),
        SIMDE_FLOAT64_C(  -590.84), SIMDE_FLOAT64_C(    63.19), SIMDE_FLOAT64_C(   240.08), SIMDE_FLOAT64_C(    86.66) } },
    { { SIMDE_FLOAT64_C(   130.58), SIMDE_FLOAT64_C(   984.49), SIMDE_FLOAT64_C(  -295.51), SIMDE_FLOAT64_C(   651.58),
        SIMDE_FLOAT64_C(  -863.62), SIMDE_FLOAT64_C(  -952.81), SIMDE_FLOAT64_C(  -315.67), SIMDE_FLOAT64_C(   768.68) },
       INT32_C(         113),
      { SIMDE_FLOAT64_C(   130.58), SIMDE_FLOAT64_C(   984.48), SIMDE_FLOAT64_C(  -295.52), SIMDE_FLOAT64_C(   651.58),
        SIMDE_FLOAT64_C(  -863.62), SIMDE_FLOAT64_C(  -952.81), SIMDE_FLOAT64_C(  -315.67), SIMDE_FLOAT64_C(   768.68) } },
    { {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(  -710.09), SIMDE_FLOAT64_C(  -158.80), SIMDE_FLOAT64_C(   297.03),
        SIMDE_FLOAT64_C(   629.87), SIMDE_FLOAT64_C(    -0.78), SIMDE_FLOAT64_C(  -791.02), SIMDE_FLOAT64_C(   455.39) },
       INT32_C(         129),
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(  -710.09), SIMDE_FLOAT64_C(  -158.80), SIMDE_FLOAT64_C(   297.03),
        SIMDE_FLOAT64_C(   629.87), SIMDE_FLOAT64_C(    -0.78), SIMDE_FLOAT64_C(  -791.02), SIMDE_FLOAT64_C(   455.39) } },
    { {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(    71.77), SIMDE_FLOAT64_C(  -294.95), SIMDE_FLOAT64_C(  -173.64),
        SIMDE_FLOAT64_C(   687.35), SIMDE_FLOAT64_C(   592.27), SIMDE_FLOAT64_C(   235.52), SIMDE_FLOAT64_C(  -249.45) },
       INT32_C(         145),
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(    71.77), SIMDE_FLOAT64_C(  -294.95), SIMDE_FLOAT64_C(  -173.64),
        SIMDE_FLOAT64_C(   687.35), SIMDE_FLOAT64_C(   592.27), SIMDE_FLOAT64_C(   235.52), SIMDE_FLOAT64_C(  -249.45) } },
    { { SIMDE_FLOAT64_C(   832.22), SIMDE_FLOAT64_C(   158.25), SIMDE_FLOAT64_C(   452.77), SIMDE_FLOAT64_C(   816.71),
        SIMDE_FLOAT64_C(   862.74), SIMDE_FLOAT64_C(   104.35), SIMDE_FLOAT64_C(   953.08), SIMDE_FLOAT64_C(   909.93) },
       INT32_C(         161),
      { SIMDE_FLOAT64_C(   832.22), SIMDE_FLOAT64_C(   158.25), SIMDE_FLOAT64_C(   452.77), SIMDE_FLOAT64_C(   816.71),
        SIMDE_FLOAT64_C(   862.74), SIMDE_FLOAT64_C(   104.35), SIMDE_FLOAT64_C(   953.08), SIMDE_FLOAT64_C(   909.93) } },
    { { SIMDE_FLOAT64_C(   721.76), SIMDE_FLOAT64_C(   252.13), SIMDE_FLOAT64_C(  -818.23), SIMDE_FLOAT64_C(  -988.32),
        SIMDE_FLOAT64_C(  -906.67), SIMDE_FLOAT64_C(   478.80), SIMDE_FLOAT64_C(   641.54), SIMDE_FLOAT64_C(    92.55) },
       INT32_C(         177),
      { SIMDE_FLOAT64_C(   721.76), SIMDE_FLOAT64_C(   252.13), SIMDE_FLOAT64_C(  -818.23), SIMDE_FLOAT64_C(  -988.32),
        SIMDE_FLOAT64_C(  -906.67), SIMDE_FLOAT64_C(   478.80), SIMDE_FLOAT64_C(   641.54), SIMDE_FLOAT64_C(    92.55) } },
    { { SIMDE_FLOAT64_C(    96.94),       -SIMDE_MATH_INFINITY, SIMDE_FLOAT64_C(  -959.08), SIMDE_FLOAT64_C(  -927.37),
        SIMDE_FLOAT64_C(   335.70), SIMDE_FLOAT64_C(  -254.03), SIMDE_FLOAT64_C(  -101.01), SIMDE_FLOAT64_C(    23.05) },
       INT32_C(         193),
      { SIMDE_FLOAT64_C(    96.94),       -SIMDE_MATH_INFINITY, SIMDE_FLOAT64_C(  -959.08), SIMDE_FLOAT64_C(  -927.37),
        SIMDE_FLOAT64_C(   335.70), SIMDE_FLOAT64_C(  -254.03), SIMDE_FLOAT64_C(  -101.01), SIMDE_FLOAT64_C(    23.05) } },
    { { SIMDE_FLOAT64_C(   170.60), SIMDE_FLOAT64_C(  -543.31), SIMDE_FLOAT64_C(   605.81), SIMDE_FLOAT64_C(  -671.16),
        SIMDE_FLOAT64_C(   909.46), SIMDE_FLOAT64_C(   422.52), SIMDE_FLOAT64_C(  -808.42), SIMDE_FLOAT64_C(    13.80) },
       INT32_C(         209),
      { SIMDE_FLOAT64_C(   170.60), SIMDE_FLOAT64_C(  -543.31), SIMDE_FLOAT64_C(   605.81), SIMDE_FLOAT64_C(  -671.16),
        SIMDE_FLOAT64_C(   909.46), SIMDE_FLOAT64_C(   422.52), SIMDE_FLOAT64_C(  -808.42), SIMDE_FLOAT64_C(    13.80) } },
    { {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(  -197.52), SIMDE_FLOAT64_C(    97.37), SIMDE_FLOAT64_C(   353.65),
        SIMDE_FLOAT64_C(   -15.75), SIMDE_FLOAT64_C(   109.05), SIMDE_FLOAT64_C(   446.97), SIMDE_FLOAT64_C(  -536.95) },
       INT32_C(         225),
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(  -197.52), SIMDE_FLOAT64_C(    97.37), SIMDE_FLOAT64_C(   353.65),
        SIMDE_FLOAT64_C(   -15.75), SIMDE_FLOAT64_C(   109.05), SIMDE_FLOAT64_C(   446.97), SIMDE_FLOAT64_C(  -536.95) } },
    { { SIMDE_FLOAT64_C(  -849.17), SIMDE_FLOAT64_C(   847.53), SIMDE_FLOAT64_C(  -196.55), SIMDE_FLOAT64_C(  -808.25),
        SIMDE_FLOAT64_C(   920.15), SIMDE_FLOAT64_C(  -860.85), SIMDE_FLOAT64_C(   -62.28), SIMDE_FLOAT64_C(  -180.86) },
       INT32_C(         241),
      { SIMDE_FLOAT64_C(  -849.17), SIMDE_FLOAT64_C(   847.53), SIMDE_FLOAT64_C(  -196.55), SIMDE_FLOAT64_C(  -808.25),
        SIMDE_FLOAT64_C(   920.15), SIMDE_FLOAT64_C(  -860.85), SIMDE_FLOAT64_C(   -62.28), SIMDE_FLOAT64_C(  -180.86) } },
    { { SIMDE_FLOAT64_C(   275.96), SIMDE_FLOAT64_C(   -46.36), SIMDE_FLOAT64_C(   -64.20), SIMDE_FLOAT64_C(  -553.44),
        SIMDE_FLOAT64_C(   410.33), SIMDE_FLOAT64_C(  -458.39), SIMDE_FLOAT64_C(  -224.60), SIMDE_FLOAT64_C(   319.79) },
       INT32_C(           2),
      { SIMDE_FLOAT64_C(   276.00), SIMDE_FLOAT64_C(   -46.00), SIMDE_FLOAT64_C(   -64.00), SIMDE_FLOAT64_C(  -553.00),
        SIMDE_FLOAT64_C(   411.00), SIMDE_FLOAT64_C(  -458.00), SIMDE_FLOAT64_C(  -224.00), SIMDE_FLOAT64_C(   320.00) } },
    { {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(  -666.41), SIMDE_FLOAT64_C(   339.73), SIMDE_FLOAT64_C(    68.50),
        SIMDE_FLOAT64_C(   136.07), SIMDE_FLOAT64_C(  -562.90), SIMDE_FLOAT64_C(  -577.86), SIMDE_FLOAT64_C(  -879.68) },
       INT32_C(          18),
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(  -666.00), SIMDE_FLOAT64_C(   340.00), SIMDE_FLOAT64_C(    68.50),
        SIMDE_FLOAT64_C(   136.50), SIMDE_FLOAT64_C(  -562.50), SIMDE_FLOAT64_C(  -577.50), SIMDE_FLOAT64_C(  -879.50) } },
    { { SIMDE_FLOAT64_C(  -416.63),       -SIMDE_MATH_INFINITY, SIMDE_FLOAT64_C(  -591.36), SIMDE_FLOAT64_C(  -265.80),
        SIMDE_FLOAT64_C(  -855.74), SIMDE_FLOAT64_C(   212.09), SIMDE_FLOAT64_C(   -74.05), SIMDE_FLOAT64_C(  -935.58) },
       INT32_C(          34),
      { SIMDE_FLOAT64_C(  -416.50),       -SIMDE_MATH_INFINITY, SIMDE_FLOAT64_C(  -591.25), SIMDE_FLOAT64_C(  -265.75),
        SIMDE_FLOAT64_C(  -855.50), SIMDE_FLOAT64_C(   212.25), SIMDE_FLOAT64_C(   -74.00), SIMDE_FLOAT64_C(  -935.50) } },
    { { SIMDE_FLOAT64_C(  -486.55),        SIMDE_MATH_INFINITY, SIMDE_FLOAT64_C(   837.20), SIMDE_FLOAT64_C(   449.24),
        SIMDE_FLOAT64_C(   586.18), SIMDE_FLOAT64_C(   247.53), SIMDE_FLOAT64_C(   990.85), SIMDE_FLOAT64_C(  -638.42) },
       INT32_C(          50),
      { SIMDE_FLOAT64_C(  -486.50),        SIMDE_MATH_INFINITY, SIMDE_FLOAT64_C(   837.25), SIMDE_FLOAT64_C(   449.25),
        SIMDE_FLOAT64_C(   586.25), SIMDE_FLOAT64_C(   247.62), SIMDE_FLOAT64_C(   990.88), SIMDE_FLOAT64_C(  -638.38) } },
    { { SIMDE_FLOAT64_C(   -99.09),        SIMDE_MATH_INFINITY, SIMDE_FLOAT64_C(  -602.94), SIMDE_FLOAT64_C(  -963.02),
        SIMDE_FLOAT64_C(   731.81), SIMDE_FLOAT64_C(  -180.80), SIMDE_FLOAT64_C(  -842.70), SIMDE_FLOAT64_C(   277.96) },
       INT32_C(          66),
      { SIMDE_FLOAT64_C(   -99.06),        SIMDE_MATH_INFINITY, SIMDE_FLOAT64_C(  -602.94), SIMDE_FLOAT64_C(  -963.00),
        SIMDE_FLOAT64_C(   731.81), SIMDE_FLOAT64_C(  -180.75), SIMDE_FLOAT64_C(  -842.69), SIMDE_FLOAT64_C(   278.00) } },
    { { SIMDE_FLOAT64_C(    96.95), SIMDE_FLOAT64_C(   474.88), SIMDE_FLOAT64_C(   718.96), SIMDE_FLOAT64_C(  -690.96),
        SIMDE_FLOAT64_C(  -599.18), SIMDE_FLOAT64_C(   783.38), SIMDE_FLOAT64_C(   660.29), SIMDE_FLOAT64_C(  -735.52) },
       INT32_C(          82),
      { SIMDE_FLOAT64_C(    96.97), SIMDE_FLOAT64_C(   474.91), SIMDE_FLOAT64_C(   718.97), SIMDE_FLOAT64_C(  -690.94),
        SIMDE_FLOAT64_C(  -599.16), SIMDE_FLOAT64_C(   783.41), SIMDE_FLOAT64_C(   660.31), SIMDE_FLOAT64_C(  -735.50) } },
    { {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   404.11), SIMDE_FLOAT64_C(  -495.87), SIMDE_FLOAT64_C(   622.98),
        SIMDE_FLOAT64_C(    -9.71), SIMDE_FLOAT64_C(   751.66), SIMDE_FLOAT64_C(   613.83), SIMDE_FLOAT64_C(   351.86) },
       INT32_C(          98),
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   404.12), SIMDE_FLOAT64_C(  -495.86), SIMDE_FLOAT64_C(   622.98),
        SIMDE_FLOAT64_C(    -9.70), SIMDE_FLOAT64_C(   751.67), SIMDE_FLOAT64_C(   613.84), SIMDE_FLOAT64_C(   351.88) } },
    { { SIMDE_FLOAT64_C(  -319.58), SIMDE_FLOAT64_C(   219.88), SIMDE_FLOAT64_C(  -136.48), SIMDE_FLOAT64_C(    77.48),
        SIMDE_FLOAT64_C(   256.85), SIMDE_FLOAT64_C(  -404.67), SIMDE_FLOAT64_C(   896.68), SIMDE_FLOAT64_C(   414.16) },
       INT32_C(         114),
      { SIMDE_FLOAT64_C(  -319.58), SIMDE_FLOAT64_C(   219.88), SIMDE_FLOAT64_C(  -136.48), SIMDE_FLOAT64_C(    77.48),
        SIMDE_FLOAT64_C(   256.85), SIMDE_FLOAT64_C(  -404.66), SIMDE_FLOAT64_C(   896.69), SIMDE_FLOAT64_C(   414.16) } },
    { { SIMDE_FLOAT64_C(  -415.00), SIMDE_FLOAT64_C(  -845.17), SIMDE_FLOAT64_C(   447.99), SIMDE_FLOAT64_C(   681.95),
        SIMDE_FLOAT64_C(   629.71), SIMDE_FLOAT64_C(   166.95), SIMDE_FLOAT64_C(   990.99), SIMDE_FLOAT64_C(  -969.47) },
       INT32_C(         130),
      { SIMDE_FLOAT64_C(  -415.00), SIMDE_FLOAT64_C(  -845.17), SIMDE_FLOAT64_C(   447.99), SIMDE_FLOAT64_C(   681.95),
        SIMDE_FLOAT64_C(   629.71), SIMDE_FLOAT64_C(   166.95), SIMDE_FLOAT64_C(   990.99), SIMDE_FLOAT64_C(  -969.47) } },
    { { SIMDE_FLOAT64_C(   651.28), SIMDE_FLOAT64_C(  -704.98), SIMDE_FLOAT64_C(   617.27), SIMDE_FLOAT64_C(   825.02),
        SIMDE_FLOAT64_C(   699.12), SIMDE_FLOAT64_C(  -878.61), SIMDE_FLOAT64_C(   447.99), SIMDE_FLOAT64_C(  -310.59) },
       INT32_C(         146),
      { SIMDE_FLOAT64_C(   651.28), SIMDE_FLOAT64_C(  -704.98), SIMDE_FLOAT64_C(   617.27), SIMDE_FLOAT64_C(   825.02),
        SIMDE_FLOAT64_C(   699.12), SIMDE_FLOAT64_C(  -878.61), SIMDE_FLOAT64_C(   447.99), SIMDE_FLOAT64_C(  -310.59) } },
    { { SIMDE_FLOAT64_C(    61.82), SIMDE_FLOAT64_C(  -958.73), SIMDE_FLOAT64_C(  -807.98), SIMDE_FLOAT64_C(  -369.38),
        SIMDE_FLOAT64_C(  -278.31), SIMDE_FLOAT64_C(   411.89), SIMDE_FLOAT64_C(   494.14), SIMDE_FLOAT64_C(   799.17) },
       INT32_C(         162),
      { SIMDE_FLOAT64_C(    61.82), SIMDE_FLOAT64_C(  -958.73), SIMDE_FLOAT64_C(  -807.98), SIMDE_FLOAT64_C(  -369.38),
        SIMDE_FLOAT64_C(  -278.31), SIMDE_FLOAT64_C(   411.89), SIMDE_FLOAT64_C(   494.14), SIMDE_FLOAT64_C(   799.17) } },
    { { SIMDE_FLOAT64_C(  -910.54), SIMDE_FLOAT64_C(   695.85), SIMDE_FLOAT64_C(  -917.09), SIMDE_FLOAT64_C(   962.76),
        SIMDE_FLOAT64_C(  -719.15), SIMDE_FLOAT64_C(  -762.26), SIMDE_FLOAT64_C(   410.75), SIMDE_FLOAT64_C(   962.80) },
       INT32_C(         178),
      { SIMDE_FLOAT64_C(  -910.54), SIMDE_FLOAT64_C(   695.85), SIMDE_FLOAT64_C(  -917.09), SIMDE_FLOAT64_C(   962.76),
        SIMDE_FLOAT64_C(  -719.15), SIMDE_FLOAT64_C(  -762.26), SIMDE_FLOAT64_C(   410.75), SIMDE_FLOAT64_C(   962.80) } },
    { { SIMDE_FLOAT64_C(  -422.30),        SIMDE_MATH_INFINITY, SIMDE_FLOAT64_C(   897.98), SIMDE_FLOAT64_C(   528.03),
        SIMDE_FLOAT64_C(   605.08), SIMDE_FLOAT64_C(  -807.00), SIMDE_FLOAT64_C(   145.30), SIMDE_FLOAT64_C(   430.09) },
       INT32_C(         194),
      { SIMDE_FLOAT64_C(  -422.30),        SIMDE_MATH_INFINITY, SIMDE_FLOAT64_C(   897.98), SIMDE_FLOAT64_C(   528.03),
        SIMDE_FLOAT64_C(   605.08), SIMDE_FLOAT64_C(  -807.00), SIMDE_FLOAT64_C(   145.30), SIMDE_FLOAT64_C(   430.09) } },
    { {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   139.74), SIMDE_FLOAT64_C(   939.90), SIMDE_FLOAT64_C(  -377.20),
        SIMDE_FLOAT64_C(   331.76), SIMDE_FLOAT64_C(  -429.48), SIMDE_FLOAT64_C(   344.49), SIMDE_FLOAT64_C(  -256.35) },
       INT32_C(         210),
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   139.74), SIMDE_FLOAT64_C(   939.90), SIMDE_FLOAT64_C(  -377.20),
        SIMDE_FLOAT64_C(   331.76), SIMDE_FLOAT64_C(  -429.48), SIMDE_FLOAT64_C(   344.49), SIMDE_FLOAT64_C(  -256.35) } },
    { { SIMDE_FLOAT64_C(   412.40),       -SIMDE_MATH_INFINITY, SIMDE_FLOAT64_C(  -160.48), SIMDE_FLOAT64_C(   495.31),
        SIMDE_FLOAT64_C(  -883.13), SIMDE_FLOAT64_C(   120.37), SIMDE_FLOAT64_C(   733.05), SIMDE_FLOAT64_C(   527.62) },
       INT32_C(         226),
      { SIMDE_FLOAT64_C(   412.40),       -SIMDE_MATH_INFINITY, SIMDE_FLOAT64_C(  -160.48), SIMDE_FLOAT64_C(   495.31),
        SIMDE_FLOAT64_C(  -883.13), SIMDE_FLOAT64_C(   120.37), SIMDE_FLOAT64_C(   733.05), SIMDE_FLOAT64_C(   527.62) } },
    { { SIMDE_FLOAT64_C(    36.97), SIMDE_FLOAT64_C(   498.48), SIMDE_FLOAT64_C(   633.35), SIMDE_FLOAT64_C(  -357.96),
        SIMDE_FLOAT64_C(   691.48), SIMDE_FLOAT64_C(  -221.35), SIMDE_FLOAT64_C(  -927.87), SIMDE_FLOAT64_C(   583.60) },
       INT32_C(         242),
      { SIMDE_FLOAT64_C(    36.97), SIMDE_FLOAT64_C(   498.48), SIMDE_FLOAT64_C(   633.35), SIMDE_FLOAT64_C(  -357.96),
        SIMDE_FLOAT64_C(   691.48), SIMDE_FLOAT64_C(  -221.35), SIMDE_FLOAT64_C(  -927.87), SIMDE_FLOAT64_C(   583.60) } },
    { {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(  -834.88), SIMDE_FLOAT64_C(   185.08), SIMDE_FLOAT64_C(  -109.89),
        SIMDE_FLOAT64_C(  -212.08), SIMDE_FLOAT64_C(  -483.17), SIMDE_FLOAT64_C(   460.63), SIMDE_FLOAT64_C(  -867.59) },
       INT32_C(           3),
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(  -834.00), SIMDE_FLOAT64_C(   185.00), SIMDE_FLOAT64_C(  -109.00),
        SIMDE_FLOAT64_C(  -212.00), SIMDE_FLOAT64_C(  -483.00), SIMDE_FLOAT64_C(   460.00), SIMDE_FLOAT64_C(  -867.00) } },
    { { SIMDE_FLOAT64_C(   276.08), SIMDE_FLOAT64_C(  -327.11), SIMDE_FLOAT64_C(   679.40), SIMDE_FLOAT64_C(  -884.40),
        SIMDE_FLOAT64_C(  -831.81), SIMDE_FLOAT64_C(   796.27), SIMDE_FLOAT64_C(   235.97), SIMDE_FLOAT64_C(   901.24) },
       INT32_C(          19),
      { SIMDE_FLOAT64_C(   276.00), SIMDE_FLOAT64_C(  -327.00), SIMDE_FLOAT64_C(   679.00), SIMDE_FLOAT64_C(  -884.00),
        SIMDE_FLOAT64_C(  -831.50), SIMDE_FLOAT64_C(   796.00), SIMDE_FLOAT64_C(   235.50), SIMDE_FLOAT64_C(   901.00) } },
    { { SIMDE_FLOAT64_C(  -680.86), SIMDE_FLOAT64_C(   501.74), SIMDE_FLOAT64_C(   429.20), SIMDE_FLOAT64_C(   356.10),
        SIMDE_FLOAT64_C(     0.22), SIMDE_FLOAT64_C(    62.55), SIMDE_FLOAT64_C(   998.14), SIMDE_FLOAT64_C(  -308.30) },
       INT32_C(          35),
      { SIMDE_FLOAT64_C(  -680.75), SIMDE_FLOAT64_C(   501.50), SIMDE_FLOAT64_C(   429.00), SIMDE_FLOAT64_C(   356.00),
        SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(    62.50), SIMDE_FLOAT64_C(   998.00), SIMDE_FLOAT64_C(  -308.25) } },
    { { SIMDE_FLOAT64_C(  -929.72), SIMDE_FLOAT64_C(  -724.70), SIMDE_FLOAT64_C(   886.54), SIMDE_FLOAT64_C(    20.49),
        SIMDE_FLOAT64_C(  -559.58), SIMDE_FLOAT64_C(    71.61), SIMDE_FLOAT64_C(   910.60), SIMDE_FLOAT64_C(   228.34) },
       INT32_C(          51),
      { SIMDE_FLOAT64_C(  -929.62), SIMDE_FLOAT64_C(  -724.62), SIMDE_FLOAT64_C(   886.50), SIMDE_FLOAT64_C(    20.38),
        SIMDE_FLOAT64_C(  -559.50), SIMDE_FLOAT64_C(    71.50), SIMDE_FLOAT64_C(   910.50), SIMDE_FLOAT64_C(   228.25) } },
    { { SIMDE_FLOAT64_C(   371.23), SIMDE_FLOAT64_C(   360.76), SIMDE_FLOAT64_C(  -151.06), SIMDE_FLOAT64_C(  -103.49),
        SIMDE_FLOAT64_C(  -363.17), SIMDE_FLOAT64_C(   521.82), SIMDE_FLOAT64_C(  -424.10), SIMDE_FLOAT64_C(  -247.57) },
       INT32_C(          67),
      { SIMDE_FLOAT64_C(   371.19), SIMDE_FLOAT64_C(   360.75), SIMDE_FLOAT64_C(  -151.00), SIMDE_FLOAT64_C(  -103.44),
        SIMDE_FLOAT64_C(  -363.12), SIMDE_FLOAT64_C(   521.81), SIMDE_FLOAT64_C(  -424.06), SIMDE_FLOAT64_C(  -247.56) } },
    { {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   988.40), SIMDE_FLOAT64_C(   591.26), SIMDE_FLOAT64_C(   696.06),
        SIMDE_FLOAT64_C(  -692.47), SIMDE_FLOAT64_C(    93.00), SIMDE_FLOAT64_C(   125.26), SIMDE_FLOAT64_C(   663.64) },
       INT32_C(          83),
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   988.38), SIMDE_FLOAT64_C(   591.25), SIMDE_FLOAT64_C(   696.03),
        SIMDE_FLOAT64_C(  -692.47), SIMDE_FLOAT64_C(    93.00), SIMDE_FLOAT64_C(   125.25), SIMDE_FLOAT64_C(   663.62) } },
    { {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(  -215.08), SIMDE_FLOAT64_C(  -970.99), SIMDE_FLOAT64_C(   732.06),
        SIMDE_FLOAT64_C(    60.22), SIMDE_FLOAT64_C(   915.55), SIMDE_FLOAT64_C(  -247.45), SIMDE_FLOAT64_C(   500.64) },
       INT32_C(          99),
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(  -215.08), SIMDE_FLOAT64_C(  -970.98), SIMDE_FLOAT64_C(   732.05),
        SIMDE_FLOAT64_C(    60.22), SIMDE_FLOAT64_C(   915.55), SIMDE_FLOAT64_C(  -247.44), SIMDE_FLOAT64_C(   500.62) } },
    { { SIMDE_FLOAT64_C(  -271.01), SIMDE_FLOAT64_C(  -424.38), SIMDE_FLOAT64_C(  -965.63), SIMDE_FLOAT64_C(  -910.26),
        SIMDE_FLOAT64_C(   424.55), SIMDE_FLOAT64_C(   -69.12), SIMDE_FLOAT64_C(  -273.42), SIMDE_FLOAT64_C(   -53.63) },
       INT32_C(         115),
      { SIMDE_FLOAT64_C(  -271.01), SIMDE_FLOAT64_C(  -424.38), SIMDE_FLOAT64_C(  -965.62), SIMDE_FLOAT64_C(  -910.26),
        SIMDE_FLOAT64_C(   424.55), SIMDE_FLOAT64_C(   -69.12), SIMDE_FLOAT64_C(  -273.41), SIMDE_FLOAT64_C(   -53.62) } },
    { {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(  -363.61), SIMDE_FLOAT64_C(   878.95), SIMDE_FLOAT64_C(   467.41),
        SIMDE_FLOAT64_C(  -772.35), SIMDE_FLOAT64_C(   575.01), SIMDE_FLOAT64_C(   774.94), SIMDE_FLOAT64_C(   320.65) },
       INT32_C(         131),
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(  -363.61), SIMDE_FLOAT64_C(   878.95), SIMDE_FLOAT64_C(   467.41),
        SIMDE_FLOAT64_C(  -772.35), SIMDE_FLOAT64_C(   575.01), SIMDE_FLOAT64_C(   774.94), SIMDE_FLOAT64_C(   320.65) } },
    { {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(  -111.91), SIMDE_FLOAT64_C(   100.36), SIMDE_FLOAT64_C(  -801.21),
        SIMDE_FLOAT64_C(   -82.90), SIMDE_FLOAT64_C(  -167.58), SIMDE_FLOAT64_C(   259.01), SIMDE_FLOAT64_C(  -167.35) },
       INT32_C(         147),
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(  -111.91), SIMDE_FLOAT64_C(   100.36), SIMDE_FLOAT64_C(  -801.21),
        SIMDE_FLOAT64_C(   -82.90), SIMDE_FLOAT64_C(  -167.58), SIMDE_FLOAT64_C(   259.01), SIMDE_FLOAT64_C(  -167.35) } },
    { {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(  -751.89), SIMDE_FLOAT64_C(   488.64), SIMDE_FLOAT64_C(  -604.56),
        SIMDE_FLOAT64_C(  -717.52), SIMDE_FLOAT64_C(   578.39), SIMDE_FLOAT64_C(   819.99), SIMDE_FLOAT64_C(   213.36) },
       INT32_C(         163),
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(  -751.89), SIMDE_FLOAT64_C(   488.64), SIMDE_FLOAT64_C(  -604.56),
        SIMDE_FLOAT64_C(  -717.52), SIMDE_FLOAT64_C(   578.39), SIMDE_FLOAT64_C(   819.99), SIMDE_FLOAT64_C(   213.36) } },
    { { SIMDE_FLOAT64_C(  -279.86),       -SIMDE_MATH_INFINITY, SIMDE_FLOAT64_C(   402.75), SIMDE_FLOAT64_C(  -400.90),
        SIMDE_FLOAT64_C(   251.38), SIMDE_FLOAT64_C(   630.40), SIMDE_FLOAT64_C(  -825.89), SIMDE_FLOAT64_C(    26.32) },
       INT32_C(         179),
      { SIMDE_FLOAT64_C(  -279.86),       -SIMDE_MATH_INFINITY, SIMDE_FLOAT64_C(   402.75), SIMDE_FLOAT64_C(  -400.90),
        SIMDE_FLOAT64_C(   251.38), SIMDE_FLOAT64_C(   630.40), SIMDE_FLOAT64_C(  -825.89), SIMDE_FLOAT64_C(    26.32) } },
    { { SIMDE_FLOAT64_C(  -635.07), SIMDE_FLOAT64_C(   762.47), SIMDE_FLOAT64_C(   565.26), SIMDE_FLOAT64_C(  -436.28),
        SIMDE_FLOAT64_C(  -320.43), SIMDE_FLOAT64_C(  -602.32), SIMDE_FLOAT64_C(   822.73), SIMDE_FLOAT64_C(   512.22) },
       INT32_C(         195),
      { SIMDE_FLOAT64_C(  -635.07), SIMDE_FLOAT64_C(   762.47), SIMDE_FLOAT64_C(   565.26), SIMDE_FLOAT64_C(  -436.28),
        SIMDE_FLOAT64_C(  -320.43), SIMDE_FLOAT64_C(  -602.32), SIMDE_FLOAT64_C(   822.73), SIMDE_FLOAT64_C(   512.22) } },
    { {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   332.04), SIMDE_FLOAT64_C(  -769.25), SIMDE_FLOAT64_C(  -928.96),
        SIMDE_FLOAT64_C(   727.48), SIMDE_FLOAT64_C(  -486.77), SIMDE_FLOAT64_C(   649.42), SIMDE_FLOAT64_C(   547.47) },
       INT32_C(         211),
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   332.04), SIMDE_FLOAT64_C(  -769.25), SIMDE_FLOAT64_C(  -928.96),
        SIMDE_FLOAT64_C(   727.48), SIMDE_FLOAT64_C(  -486.77), SIMDE_FLOAT64_C(   649.42), SIMDE_FLOAT64_C(   547.47) } },
    { { SIMDE_FLOAT64_C(  -686.17), SIMDE_FLOAT64_C(  -553.27), SIMDE_FLOAT64_C(   738.36), SIMDE_FLOAT64_C(   716.59),
        SIMDE_FLOAT64_C(    45.83), SIMDE_FLOAT64_C(   -10.26), SIMDE_FLOAT64_C(   346.99), SIMDE_FLOAT64_C(   219.94) },
       INT32_C(         227),
      { SIMDE_FLOAT64_C(  -686.17), SIMDE_FLOAT64_C(  -553.27), SIMDE_FLOAT64_C(   738.36), SIMDE_FLOAT64_C(   716.59),
        SIMDE_FLOAT64_C(    45.83), SIMDE_FLOAT64_C(   -10.26), SIMDE_FLOAT64_C(   346.99), SIMDE_FLOAT64_C(   219.94) } },
    { { SIMDE_FLOAT64_C(  -701.96), SIMDE_FLOAT64_C(  -905.68), SIMDE_FLOAT64_C(  -519.04), SIMDE_FLOAT64_C(  -337.03),
        SIMDE_FLOAT64_C(   856.78), SIMDE_FLOAT64_C(  -953.78), SIMDE_FLOAT64_C(   226.69), SIMDE_FLOAT64_C(  -463.65) },
       INT32_C(         243),
      { SIMDE_FLOAT64_C(  -701.96), SIMDE_FLOAT64_C(  -905.68), SIMDE_FLOAT64_C(  -519.04), SIMDE_FLOAT64_C(  -337.03),
        SIMDE_FLOAT64_C(   856.78), SIMDE_FLOAT64_C(  -953.78), SIMDE_FLOAT64_C(   226.69), SIMDE_FLOAT64_C(  -463.65) } },
    { {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(  -951.42), SIMDE_FLOAT64_C(  -573.46), SIMDE_FLOAT64_C(   631.82),
        SIMDE_FLOAT64_C(   380.62), SIMDE_FLOAT64_C(  -342.71), SIMDE_FLOAT64_C(   702.85), SIMDE_FLOAT64_C(   108.10) },
       INT32_C(           4),
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(  -951.00), SIMDE_FLOAT64_C(  -573.00), SIMDE_FLOAT64_C(   632.00),
        SIMDE_FLOAT64_C(   381.00), SIMDE_FLOAT64_C(  -343.00), SIMDE_FLOAT64_C(   703.00), SIMDE_FLOAT64_C(   108.00) } },
    { {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(  -102.88), SIMDE_FLOAT64_C(   306.66), SIMDE_FLOAT64_C(   -30.59),
        SIMDE_FLOAT64_C(   343.85), SIMDE_FLOAT64_C(    45.02), SIMDE_FLOAT64_C(  -314.01), SIMDE_FLOAT64_C(  -610.32) },
       INT32_C(          20),
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(  -103.00), SIMDE_FLOAT64_C(   306.50), SIMDE_FLOAT64_C(   -30.50),
        SIMDE_FLOAT64_C(   344.00), SIMDE_FLOAT64_C(    45.00), SIMDE_FLOAT64_C(  -314.00), SIMDE_FLOAT64_C(  -610.50) } },
    { {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(  -949.17), SIMDE_FLOAT64_C(  -668.97), SIMDE_FLOAT64_C(   703.94),
        SIMDE_FLOAT64_C(  -468.20), SIMDE_FLOAT64_C(    -6.00), SIMDE_FLOAT64_C(   560.72), SIMDE_FLOAT64_C(  -421.98) },
       INT32_C(          36),
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(  -949.25), SIMDE_FLOAT64_C(  -669.00), SIMDE_FLOAT64_C(   704.00),
        SIMDE_FLOAT64_C(  -468.25), SIMDE_FLOAT64_C(    -6.00), SIMDE_FLOAT64_C(   560.75), SIMDE_FLOAT64_C(  -422.00) } },
    { { SIMDE_FLOAT64_C(    21.92),       -SIMDE_MATH_INFINITY, SIMDE_FLOAT64_C(  -854.35), SIMDE_FLOAT64_C(   448.47),
        SIMDE_FLOAT64_C(   -98.07), SIMDE_FLOAT64_C(   526.27), SIMDE_FLOAT64_C(  -894.24), SIMDE_FLOAT64_C(  -395.22) },
       INT32_C(          52),
      { SIMDE_FLOAT64_C(    21.88),       -SIMDE_MATH_INFINITY, SIMDE_FLOAT64_C(  -854.38), SIMDE_FLOAT64_C(   448.50),
        SIMDE_FLOAT64_C(   -98.12), SIMDE_FLOAT64_C(   526.25), SIMDE_FLOAT64_C(  -894.25), SIMDE_FLOAT64_C(  -395.25) } },
    { { SIMDE_FLOAT64_C(   289.95), SIMDE_FLOAT64_C(  -826.60), SIMDE_FLOAT64_C(   263.71), SIMDE_FLOAT64_C(  -740.65),
        SIMDE_FLOAT64_C(   517.26), SIMDE_FLOAT64_C(  -691.26), SIMDE_FLOAT64_C(   -54.66), SIMDE_FLOAT64_C(   906.94) },
       INT32_C(          68),
      { SIMDE_FLOAT64_C(   289.94), SIMDE_FLOAT64_C(  -826.62), SIMDE_FLOAT64_C(   263.69), SIMDE_FLOAT64_C(  -740.62),
        SIMDE_FLOAT64_C(   517.25), SIMDE_FLOAT64_C(  -691.25), SIMDE_FLOAT64_C(   -54.69), SIMDE_FLOAT64_C(   906.94) } },
    { { SIMDE_FLOAT64_C(   -21.67),       -SIMDE_MATH_INFINITY, SIMDE_FLOAT64_C(  -605.66), SIMDE_FLOAT64_C(   309.35),
        SIMDE_FLOAT64_C(   220.50), SIMDE_FLOAT64_C(   -73.87), SIMDE_FLOAT64_C(  -696.65), SIMDE_FLOAT64_C(  -218.78) },
       INT32_C(          84),
      { SIMDE_FLOAT64_C(   -21.66),       -SIMDE_MATH_INFINITY, SIMDE_FLOAT64_C(  -605.66), SIMDE_FLOAT64_C(   309.34),
        SIMDE_FLOAT64_C(   220.50), SIMDE_FLOAT64_C(   -73.88), SIMDE_FLOAT64_C(  -696.66), SIMDE_FLOAT64_C(  -218.78) } },
    { { SIMDE_FLOAT64_C(  -473.92),       -SIMDE_MATH_INFINITY, SIMDE_FLOAT64_C(    23.94), SIMDE_FLOAT64_C(   974.54),
        SIMDE_FLOAT64_C(  -303.92), SIMDE_FLOAT64_C(  -449.78), SIMDE_FLOAT64_C(  -919.70), SIMDE_FLOAT64_C(   300.86) },
       INT32_C(         100),
      { SIMDE_FLOAT64_C(  -473.92),       -SIMDE_MATH_INFINITY, SIMDE_FLOAT64_C(    23.94), SIMDE_FLOAT64_C(   974.55),
        SIMDE_FLOAT64_C(  -303.92), SIMDE_FLOAT64_C(  -449.78), SIMDE_FLOAT64_C(  -919.70), SIMDE_FLOAT64_C(   300.86) } },
    { {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   529.99), SIMDE_FLOAT64_C(  -478.38), SIMDE_FLOAT64_C(  -266.11),
        SIMDE_FLOAT64_C(    47.24), SIMDE_FLOAT64_C(  -169.64), SIMDE_FLOAT64_C(   679.23), SIMDE_FLOAT64_C(   -45.82) },
       INT32_C(         116),
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   529.99), SIMDE_FLOAT64_C(  -478.38), SIMDE_FLOAT64_C(  -266.11),
        SIMDE_FLOAT64_C(    47.24), SIMDE_FLOAT64_C(  -169.64), SIMDE_FLOAT64_C(   679.23), SIMDE_FLOAT64_C(   -45.82) } },
    { {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   568.21), SIMDE_FLOAT64_C(   966.91), SIMDE_FLOAT64_C(   691.24),
        SIMDE_FLOAT64_C(  -505.66), SIMDE_FLOAT64_C(  -729.73), SIMDE_FLOAT64_C(  -527.54), SIMDE_FLOAT64_C(   998.50) },
       INT32_C(         132),
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   568.21), SIMDE_FLOAT64_C(   966.91), SIMDE_FLOAT64_C(   691.24),
        SIMDE_FLOAT64_C(  -505.66), SIMDE_FLOAT64_C(  -729.73), SIMDE_FLOAT64_C(  -527.54), SIMDE_FLOAT64_C(   998.50) } },
    { { SIMDE_FLOAT64_C(  -475.42),        SIMDE_MATH_INFINITY, SIMDE_FLOAT64_C(  -625.30), SIMDE_FLOAT64_C(  -500.88),
        SIMDE_FLOAT64_C(   284.54), SIMDE_FLOAT64_C(   -75.09), SIMDE_FLOAT64_C(  -420.58), SIMDE_FLOAT64_C(  -414.60) },
       INT32_C(         148),
      { SIMDE_FLOAT64_C(  -475.42),        SIMDE_MATH_INFINITY, SIMDE_FLOAT64_C(  -625.30), SIMDE_FLOAT64_C(  -500.88),
        SIMDE_FLOAT64_C(   284.54), SIMDE_FLOAT64_C(   -75.09), SIMDE_FLOAT64_C(  -420.58), SIMDE_FLOAT64_C(  -414.60) } },
    { { SIMDE_FLOAT64_C(  -415.96), SIMDE_FLOAT64_C(   465.99), SIMDE_FLOAT64_C(  -635.07), SIMDE_FLOAT64_C(   317.93),
        SIMDE_FLOAT64_C(  -486.76), SIMDE_FLOAT64_C(   195.29), SIMDE_FLOAT64_C(    -2.84), SIMDE_FLOAT64_C(   467.42) },
       INT32_C(         164),
      { SIMDE_FLOAT64_C(  -415.96), SIMDE_FLOAT64_C(   465.99), SIMDE_FLOAT64_C(  -635.07), SIMDE_FLOAT64_C(   317.93),
        SIMDE_FLOAT64_C(  -486.76), SIMDE_FLOAT64_C(   195.29), SIMDE_FLOAT64_C(    -2.84), SIMDE_FLOAT64_C(   467.42) } },
    { {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   938.17), SIMDE_FLOAT64_C(   937.37), SIMDE_FLOAT64_C(   621.63),
        SIMDE_FLOAT64_C(   629.41), SIMDE_FLOAT64_C(  -568.29), SIMDE_FLOAT64_C(   891.90), SIMDE_FLOAT64_C(  -898.13) },
       INT32_C(         180),
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   938.17), SIMDE_FLOAT64_C(   937.37), SIMDE_FLOAT64_C(   621.63),
        SIMDE_FLOAT64_C(   629.41), SIMDE_FLOAT64_C(  -568.29), SIMDE_FLOAT64_C(   891.90), SIMDE_FLOAT64_C(  -898.13) } },
    { { SIMDE_FLOAT64_C(   452.62), SIMDE_FLOAT64_C(   -45.21), SIMDE_FLOAT64_C(   274.67), SIMDE_FLOAT64_C(   827.32),
        SIMDE_FLOAT64_C(   453.90), SIMDE_FLOAT64_C(  -440.79), SIMDE_FLOAT64_C(  -247.77), SIMDE_FLOAT64_C(  -966.68) },
       INT32_C(         196),
      { SIMDE_FLOAT64_C(   452.62), SIMDE_FLOAT64_C(   -45.21), SIMDE_FLOAT64_C(   274.67), SIMDE_FLOAT64_C(   827.32),
        SIMDE_FLOAT64_C(   453.90), SIMDE_FLOAT64_C(  -440.79), SIMDE_FLOAT64_C(  -247.77), SIMDE_FLOAT64_C(  -966.68) } },
    { {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   969.33), SIMDE_FLOAT64_C(   -12.08), SIMDE_FLOAT64_C(   445.77),
        SIMDE_FLOAT64_C(   435.32), SIMDE_FLOAT64_C(   352.85), SIMDE_FLOAT64_C(  -236.30), SIMDE_FLOAT64_C(   948.56) },
       INT32_C(         212),
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   969.33), SIMDE_FLOAT64_C(   -12.08), SIMDE_FLOAT64_C(   445.77),
        SIMDE_FLOAT64_C(   435.32), SIMDE_FLOAT64_C(   352.85), SIMDE_FLOAT64_C(  -236.30), SIMDE_FLOAT64_C(   948.56) } },
    { { SIMDE_FLOAT64_C(   415.98), SIMDE_FLOAT64_C(   -82.70), SIMDE_FLOAT64_C(   415.58), SIMDE_FLOAT64_C(   354.15),
        SIMDE_FLOAT64_C(  -145.33), SIMDE_FLOAT64_C(    37.21), SIMDE_FLOAT64_C(   -16.44), SIMDE_FLOAT64_C(   286.39) },
       INT32_C(         228),
      { SIMDE_FLOAT64_C(   415.98), SIMDE_FLOAT64_C(   -82.70), SIMDE_FLOAT64_C(   415.58), SIMDE_FLOAT64_C(   354.15),
        SIMDE_FLOAT64_C(  -145.33), SIMDE_FLOAT64_C(    37.21), SIMDE_FLOAT64_C(   -16.44), SIMDE_FLOAT64_C(   286.39) } },
    { { SIMDE_FLOAT64_C(    85.42), SIMDE_FLOAT64_C(   716.60), SIMDE_FLOAT64_C(   615.33), SIMDE_FLOAT64_C(  -461.96),
        SIMDE_FLOAT64_C(  -328.62), SIMDE_FLOAT64_C(  -110.00), SIMDE_FLOAT64_C(  -634.64), SIMDE_FLOAT64_C(  -874.71) },
       INT32_C(         244),
      { SIMDE_FLOAT64_C(    85.42), SIMDE_FLOAT64_C(   716.60), SIMDE_FLOAT64_C(   615.33), SIMDE_FLOAT64_C(  -461.96),
        SIMDE_FLOAT64_C(  -328.62), SIMDE_FLOAT64_C(  -110.00), SIMDE_FLOAT64_C(  -634.64), SIMDE_FLOAT64_C(  -874.71) } },
  };

  simde__m512d a, r;

  a = simde_mm512_loadu_pd(test_vec[0].a);
  r = simde_mm512_roundscale_pd(a, INT32_C(           0));
  simde_test_x86_assert_equal_f64x8(r, simde_mm512_loadu_pd(test_vec[0].r), 1);

  a = simde_mm512_loadu_pd(test_vec[1].a);
  r = simde_mm512_roundscale_pd(a, INT32_C(          16));
  simde_test_x86_assert_equal_f64x8(r, simde_mm512_loadu_pd(test_vec[1].r), 1);

  a = simde_mm512_loadu_pd(test_vec[2].a);
  r = simde_mm512_roundscale_pd(a, INT32_C(          32));
  simde_test_x86_assert_equal_f64x8(r, simde_mm512_loadu_pd(test_vec[2].r), 1);

  a = simde_mm512_loadu_pd(test_vec[3].a);
  r = simde_mm512_roundscale_pd(a, INT32_C(          48));
  simde_test_x86_assert_equal_f64x8(r, simde_mm512_loadu_pd(test_vec[3].r), 1);

  a = simde_mm512_loadu_pd(test_vec[4].a);
  r = simde_mm512_roundscale_pd(a, INT32_C(          64));
  simde_test_x86_assert_equal_f64x8(r, simde_mm512_loadu_pd(test_vec[4].r), 1);

  a = simde_mm512_loadu_pd(test_vec[5].a);
  r = simde_mm512_roundscale_pd(a, INT32_C(          80));
  simde_test_x86_assert_equal_f64x8(r, simde_mm512_loadu_pd(test_vec[5].r), 1);

  a = simde_mm512_loadu_pd(test_vec[6].a);
  r = simde_mm512_roundscale_pd(a, INT32_C(          96));
  simde_test_x86_assert_equal_f64x8(r, simde_mm512_loadu_pd(test_vec[6].r), 1);

  a = simde_mm512_loadu_pd(test_vec[7].a);
  r = simde_mm512_roundscale_pd(a, INT32_C(         112));
  simde_test_x86_assert_equal_f64x8(r, simde_mm512_loadu_pd(test_vec[7].r), 1);

  a = simde_mm512_loadu_pd(test_vec[8].a);
  r = simde_mm512_roundscale_pd(a, INT32_C(         128));
  simde_test_x86_assert_equal_f64x8(r, simde_mm512_loadu_pd(test_vec[8].r), 1);

  a = simde_mm512_loadu_pd(test_vec[9].a);
  r = simde_mm512_roundscale_pd(a, INT32_C(         144));
  simde_test_x86_assert_equal_f64x8(r, simde_mm512_loadu_pd(test_vec[9].r), 1);

  a = simde_mm512_loadu_pd(test_vec[10].a);
  r = simde_mm512_roundscale_pd(a, INT32_C(         160));
  simde_test_x86_assert_equal_f64x8(r, simde_mm512_loadu_pd(test_vec[10].r), 1);

  a = simde_mm512_loadu_pd(test_vec[11].a);
  r = simde_mm512_roundscale_pd(a, INT32_C(         176));
  simde_test_x86_assert_equal_f64x8(r, simde_mm512_loadu_pd(test_vec[11].r), 1);

  a = simde_mm512_loadu_pd(test_vec[12].a);
  r = simde_mm512_roundscale_pd(a, INT32_C(         192));
  simde_test_x86_assert_equal_f64x8(r, simde_mm512_loadu_pd(test_vec[12].r), 1);

  a = simde_mm512_loadu_pd(test_vec[13].a);
  r = simde_mm512_roundscale_pd(a, INT32_C(         208));
  simde_test_x86_assert_equal_f64x8(r, simde_mm512_loadu_pd(test_vec[13].r), 1);

  a = simde_mm512_loadu_pd(test_vec[14].a);
  r = simde_mm512_roundscale_pd(a, INT32_C(         224));
  simde_test_x86_assert_equal_f64x8(r, simde_mm512_loadu_pd(test_vec[14].r), 1);

  a = simde_mm512_loadu_pd(test_vec[15].a);
  r = simde_mm512_roundscale_pd(a, INT32_C(         240));
  simde_test_x86_assert_equal_f64x8(r, simde_mm512_loadu_pd(test_vec[15].r), 1);

  a = simde_mm512_loadu_pd(test_vec[16].a);
  r = simde_mm512_roundscale_pd(a, INT32_C(           1));
  simde_test_x86_assert_equal_f64x8(r, simde_mm512_loadu_pd(test_vec[16].r), 1);

  a = simde_mm512_loadu_pd(test_vec[17].a);
  r = simde_mm512_roundscale_pd(a, INT32_C(          17));
  simde_test_x86_assert_equal_f64x8(r, simde_mm512_loadu_pd(test_vec[17].r), 1);

  a = simde_mm512_loadu_pd(test_vec[18].a);
  r = simde_mm512_roundscale_pd(a, INT32_C(          33));
  simde_test_x86_assert_equal_f64x8(r, simde_mm512_loadu_pd(test_vec[18].r), 1);

  a = simde_mm512_loadu_pd(test_vec[19].a);
  r = simde_mm512_roundscale_pd(a, INT32_C(          49));
  simde_test_x86_assert_equal_f64x8(r, simde_mm512_loadu_pd(test_vec[19].r), 1);

  a = simde_mm512_loadu_pd(test_vec[20].a);
  r = simde_mm512_roundscale_pd(a, INT32_C(          65));
  simde_test_x86_assert_equal_f64x8(r, simde_mm512_loadu_pd(test_vec[20].r), 1);

  a = simde_mm512_loadu_pd(test_vec[21].a);
  r = simde_mm512_roundscale_pd(a, INT32_C(          81));
  simde_test_x86_assert_equal_f64x8(r, simde_mm512_loadu_pd(test_vec[21].r), 1);

  a = simde_mm512_loadu_pd(test_vec[22].a);
  r = simde_mm512_roundscale_pd(a, INT32_C(          97));
  simde_test_x86_assert_equal_f64x8(r, simde_mm512_loadu_pd(test_vec[22].r), 1);

  a = simde_mm512_loadu_pd(test_vec[23].a);
  r = simde_mm512_roundscale_pd(a, INT32_C(         113));
  simde_test_x86_assert_equal_f64x8(r, simde_mm512_loadu_pd(test_vec[23].r), 1);

  a = simde_mm512_loadu_pd(test_vec[24].a);
  r = simde_mm512_roundscale_pd(a, INT32_C(         129));
  simde_test_x86_assert_equal_f64x8(r, simde_mm512_loadu_pd(test_vec[24].r), 1);

  a = simde_mm512_loadu_pd(test_vec[25].a);
  r = simde_mm512_roundscale_pd(a, INT32_C(         145));
  simde_test_x86_assert_equal_f64x8(r, simde_mm512_loadu_pd(test_vec[25].r), 1);

  a = simde_mm512_loadu_pd(test_vec[26].a);
  r = simde_mm512_roundscale_pd(a, INT32_C(         161));
  simde_test_x86_assert_equal_f64x8(r, simde_mm512_loadu_pd(test_vec[26].r), 1);

  a = simde_mm512_loadu_pd(test_vec[27].a);
  r = simde_mm512_roundscale_pd(a, INT32_C(         177));
  simde_test_x86_assert_equal_f64x8(r, simde_mm512_loadu_pd(test_vec[27].r), 1);

  a = simde_mm512_loadu_pd(test_vec[28].a);
  r = simde_mm512_roundscale_pd(a, INT32_C(         193));
  simde_test_x86_assert_equal_f64x8(r, simde_mm512_loadu_pd(test_vec[28].r), 1);

  a = simde_mm512_loadu_pd(test_vec[29].a);
  r = simde_mm512_roundscale_pd(a, INT32_C(         209));
  simde_test_x86_assert_equal_f64x8(r, simde_mm512_loadu_pd(test_vec[29].r), 1);

  a = simde_mm512_loadu_pd(test_vec[30].a);
  r = simde_mm512_roundscale_pd(a, INT32_C(         225));
  simde_test_x86_assert_equal_f64x8(r, simde_mm512_loadu_pd(test_vec[30].r), 1);

  a = simde_mm512_loadu_pd(test_vec[31].a);
  r = simde_mm512_roundscale_pd(a, INT32_C(         241));
  simde_test_x86_assert_equal_f64x8(r, simde_mm512_loadu_pd(test_vec[31].r), 1);

  a = simde_mm512_loadu_pd(test_vec[32].a);
  r = simde_mm512_roundscale_pd(a, INT32_C(           2));
  simde_test_x86_assert_equal_f64x8(r, simde_mm512_loadu_pd(test_vec[32].r), 1);

  a = simde_mm512_loadu_pd(test_vec[33].a);
  r = simde_mm512_roundscale_pd(a, INT32_C(          18));
  simde_test_x86_assert_equal_f64x8(r, simde_mm512_loadu_pd(test_vec[33].r), 1);

  a = simde_mm512_loadu_pd(test_vec[34].a);
  r = simde_mm512_roundscale_pd(a, INT32_C(          34));
  simde_test_x86_assert_equal_f64x8(r, simde_mm512_loadu_pd(test_vec[34].r), 1);

  a = simde_mm512_loadu_pd(test_vec[35].a);
  r = simde_mm512_roundscale_pd(a, INT32_C(          50));
  simde_test_x86_assert_equal_f64x8(r, simde_mm512_loadu_pd(test_vec[35].r), 1);

  a = simde_mm512_loadu_pd(test_vec[36].a);
  r = simde_mm512_roundscale_pd(a, INT32_C(          66));
  simde_test_x86_assert_equal_f64x8(r, simde_mm512_loadu_pd(test_vec[36].r), 1);

  a = simde_mm512_loadu_pd(test_vec[37].a);
  r = simde_mm512_roundscale_pd(a, INT32_C(          82));
  simde_test_x86_assert_equal_f64x8(r, simde_mm512_loadu_pd(test_vec[37].r), 1);

  a = simde_mm512_loadu_pd(test_vec[38].a);
  r = simde_mm512_roundscale_pd(a, INT32_C(          98));
  simde_test_x86_assert_equal_f64x8(r, simde_mm512_loadu_pd(test_vec[38].r), 1);

  a = simde_mm512_loadu_pd(test_vec[39].a);
  r = simde_mm512_roundscale_pd(a, INT32_C(         114));
  simde_test_x86_assert_equal_f64x8(r, simde_mm512_loadu_pd(test_vec[39].r), 1);

  a = simde_mm512_loadu_pd(test_vec[40].a);
  r = simde_mm512_roundscale_pd(a, INT32_C(         130));
  simde_test_x86_assert_equal_f64x8(r, simde_mm512_loadu_pd(test_vec[40].r), 1);

  a = simde_mm512_loadu_pd(test_vec[41].a);
  r = simde_mm512_roundscale_pd(a, INT32_C(         146));
  simde_test_x86_assert_equal_f64x8(r, simde_mm512_loadu_pd(test_vec[41].r), 1);

  a = simde_mm512_loadu_pd(test_vec[42].a);
  r = simde_mm512_roundscale_pd(a, INT32_C(         162));
  simde_test_x86_assert_equal_f64x8(r, simde_mm512_loadu_pd(test_vec[42].r), 1);

  a = simde_mm512_loadu_pd(test_vec[43].a);
  r = simde_mm512_roundscale_pd(a, INT32_C(         178));
  simde_test_x86_assert_equal_f64x8(r, simde_mm512_loadu_pd(test_vec[43].r), 1);

  a = simde_mm512_loadu_pd(test_vec[44].a);
  r = simde_mm512_roundscale_pd(a, INT32_C(         194));
  simde_test_x86_assert_equal_f64x8(r, simde_mm512_loadu_pd(test_vec[44].r), 1);

  a = simde_mm512_loadu_pd(test_vec[45].a);
  r = simde_mm512_roundscale_pd(a, INT32_C(         210));
  simde_test_x86_assert_equal_f64x8(r, simde_mm512_loadu_pd(test_vec[45].r), 1);

  a = simde_mm512_loadu_pd(test_vec[46].a);
  r = simde_mm512_roundscale_pd(a, INT32_C(         226));
  simde_test_x86_assert_equal_f64x8(r, simde_mm512_loadu_pd(test_vec[46].r), 1);

  a = simde_mm512_loadu_pd(test_vec[47].a);
  r = simde_mm512_roundscale_pd(a, INT32_C(         242));
  simde_test_x86_assert_equal_f64x8(r, simde_mm512_loadu_pd(test_vec[47].r), 1);

  a = simde_mm512_loadu_pd(test_vec[48].a);
  r = simde_mm512_roundscale_pd(a, INT32_C(           3));
  simde_test_x86_assert_equal_f64x8(r, simde_mm512_loadu_pd(test_vec[48].r), 1);

  a = simde_mm512_loadu_pd(test_vec[49].a);
  r = simde_mm512_roundscale_pd(a, INT32_C(          19));
  simde_test_x86_assert_equal_f64x8(r, simde_mm512_loadu_pd(test_vec[49].r), 1);

  a = simde_mm512_loadu_pd(test_vec[50].a);
  r = simde_mm512_roundscale_pd(a, INT32_C(          35));
  simde_test_x86_assert_equal_f64x8(r, simde_mm512_loadu_pd(test_vec[50].r), 1);

  a = simde_mm512_loadu_pd(test_vec[51].a);
  r = simde_mm512_roundscale_pd(a, INT32_C(          51));
  simde_test_x86_assert_equal_f64x8(r, simde_mm512_loadu_pd(test_vec[51].r), 1);

  a = simde_mm512_loadu_pd(test_vec[52].a);
  r = simde_mm512_roundscale_pd(a, INT32_C(          67));
  simde_test_x86_assert_equal_f64x8(r, simde_mm512_loadu_pd(test_vec[52].r), 1);

  a = simde_mm512_loadu_pd(test_vec[53].a);
  r = simde_mm512_roundscale_pd(a, INT32_C(          83));
  simde_test_x86_assert_equal_f64x8(r, simde_mm512_loadu_pd(test_vec[53].r), 1);

  a = simde_mm512_loadu_pd(test_vec[54].a);
  r = simde_mm512_roundscale_pd(a, INT32_C(          99));
  simde_test_x86_assert_equal_f64x8(r, simde_mm512_loadu_pd(test_vec[54].r), 1);

  a = simde_mm512_loadu_pd(test_vec[55].a);
  r = simde_mm512_roundscale_pd(a, INT32_C(         115));
  simde_test_x86_assert_equal_f64x8(r, simde_mm512_loadu_pd(test_vec[55].r), 1);

  a = simde_mm512_loadu_pd(test_vec[56].a);
  r = simde_mm512_roundscale_pd(a, INT32_C(         131));
  simde_test_x86_assert_equal_f64x8(r, simde_mm512_loadu_pd(test_vec[56].r), 1);

  a = simde_mm512_loadu_pd(test_vec[57].a);
  r = simde_mm512_roundscale_pd(a, INT32_C(         147));
  simde_test_x86_assert_equal_f64x8(r, simde_mm512_loadu_pd(test_vec[57].r), 1);

  a = simde_mm512_loadu_pd(test_vec[58].a);
  r = simde_mm512_roundscale_pd(a, INT32_C(         163));
  simde_test_x86_assert_equal_f64x8(r, simde_mm512_loadu_pd(test_vec[58].r), 1);

  a = simde_mm512_loadu_pd(test_vec[59].a);
  r = simde_mm512_roundscale_pd(a, INT32_C(         179));
  simde_test_x86_assert_equal_f64x8(r, simde_mm512_loadu_pd(test_vec[59].r), 1);

  a = simde_mm512_loadu_pd(test_vec[60].a);
  r = simde_mm512_roundscale_pd(a, INT32_C(         195));
  simde_test_x86_assert_equal_f64x8(r, simde_mm512_loadu_pd(test_vec[60].r), 1);

  a = simde_mm512_loadu_pd(test_vec[61].a);
  r = simde_mm512_roundscale_pd(a, INT32_C(         211));
  simde_test_x86_assert_equal_f64x8(r, simde_mm512_loadu_pd(test_vec[61].r), 1);

  a = simde_mm512_loadu_pd(test_vec[62].a);
  r = simde_mm512_roundscale_pd(a, INT32_C(         227));
  simde_test_x86_assert_equal_f64x8(r, simde_mm512_loadu_pd(test_vec[62].r), 1);

  a = simde_mm512_loadu_pd(test_vec[63].a);
  r = simde_mm512_roundscale_pd(a, INT32_C(         243));
  simde_test_x86_assert_equal_f64x8(r, simde_mm512_loadu_pd(test_vec[63].r), 1);

  a = simde_mm512_loadu_pd(test_vec[64].a);
  r = simde_mm512_roundscale_pd(a, INT32_C(           4));
  simde_test_x86_assert_equal_f64x8(r, simde_mm512_loadu_pd(test_vec[64].r), 1);

  a = simde_mm512_loadu_pd(test_vec[65].a);
  r = simde_mm512_roundscale_pd(a, INT32_C(          20));
  simde_test_x86_assert_equal_f64x8(r, simde_mm512_loadu_pd(test_vec[65].r), 1);

  a = simde_mm512_loadu_pd(test_vec[66].a);
  r = simde_mm512_roundscale_pd(a, INT32_C(          36));
  simde_test_x86_assert_equal_f64x8(r, simde_mm512_loadu_pd(test_vec[66].r), 1);

  a = simde_mm512_loadu_pd(test_vec[67].a);
  r = simde_mm512_roundscale_pd(a, INT32_C(          52));
  simde_test_x86_assert_equal_f64x8(r, simde_mm512_loadu_pd(test_vec[67].r), 1);

  a = simde_mm512_loadu_pd(test_vec[68].a);
  r = simde_mm512_roundscale_pd(a, INT32_C(          68));
  simde_test_x86_assert_equal_f64x8(r, simde_mm512_loadu_pd(test_vec[68].r), 1);

  a = simde_mm512_loadu_pd(test_vec[69].a);
  r = simde_mm512_roundscale_pd(a, INT32_C(          84));
  simde_test_x86_assert_equal_f64x8(r, simde_mm512_loadu_pd(test_vec[69].r), 1);

  a = simde_mm512_loadu_pd(test_vec[70].a);
  r = simde_mm512_roundscale_pd(a, INT32_C(         100));
  simde_test_x86_assert_equal_f64x8(r, simde_mm512_loadu_pd(test_vec[70].r), 1);

  a = simde_mm512_loadu_pd(test_vec[71].a);
  r = simde_mm512_roundscale_pd(a, INT32_C(         116));
  simde_test_x86_assert_equal_f64x8(r, simde_mm512_loadu_pd(test_vec[71].r), 1);

  a = simde_mm512_loadu_pd(test_vec[72].a);
  r = simde_mm512_roundscale_pd(a, INT32_C(         132));
  simde_test_x86_assert_equal_f64x8(r, simde_mm512_loadu_pd(test_vec[72].r), 1);

  a = simde_mm512_loadu_pd(test_vec[73].a);
  r = simde_mm512_roundscale_pd(a, INT32_C(         148));
  simde_test_x86_assert_equal_f64x8(r, simde_mm512_loadu_pd(test_vec[73].r), 1);

  a = simde_mm512_loadu_pd(test_vec[74].a);
  r = simde_mm512_roundscale_pd(a, INT32_C(         164));
  simde_test_x86_assert_equal_f64x8(r, simde_mm512_loadu_pd(test_vec[74].r), 1);

  a = simde_mm512_loadu_pd(test_vec[75].a);
  r = simde_mm512_roundscale_pd(a, INT32_C(         180));
  simde_test_x86_assert_equal_f64x8(r, simde_mm512_loadu_pd(test_vec[75].r), 1);

  a = simde_mm512_loadu_pd(test_vec[76].a);
  r = simde_mm512_roundscale_pd(a, INT32_C(         196));
  simde_test_x86_assert_equal_f64x8(r, simde_mm512_loadu_pd(test_vec[76].r), 1);

  a = simde_mm512_loadu_pd(test_vec[77].a);
  r = simde_mm512_roundscale_pd(a, INT32_C(         212));
  simde_test_x86_assert_equal_f64x8(r, simde_mm512_loadu_pd(test_vec[77].r), 1);

  a = simde_mm512_loadu_pd(test_vec[78].a);
  r = simde_mm512_roundscale_pd(a, INT32_C(         228));
  simde_test_x86_assert_equal_f64x8(r, simde_mm512_loadu_pd(test_vec[78].r), 1);

  a = simde_mm512_loadu_pd(test_vec[79].a);
  r = simde_mm512_roundscale_pd(a, INT32_C(         244));
  simde_test_x86_assert_equal_f64x8(r, simde_mm512_loadu_pd(test_vec[79].r), 1);

  return 0;
#else
  fputc('\n', stdout);
  int round_type[5] = {SIMDE_MM_FROUND_TO_NEAREST_INT, SIMDE_MM_FROUND_TO_NEG_INF, SIMDE_MM_FROUND_TO_POS_INF, SIMDE_MM_FROUND_TO_ZERO, SIMDE_MM_FROUND_CUR_DIRECTION};
  for (int i = 0 ; i < 5 ; i++) {
    for (int j = 0 ; j < 16 ; j++) {
      simde__m512d a = simde_test_x86_random_f64x8(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
      if((simde_test_codegen_rand() & 1)) {
        if((simde_test_codegen_rand() & 1))
          a = simde_mm512_mask_mov_pd(a, 1, simde_mm512_set1_pd(SIMDE_MATH_NAN));
        else {
          if((simde_test_codegen_rand() & 1))
            a = simde_mm512_mask_mov_pd(a, 2, simde_mm512_set1_pd(SIMDE_MATH_INFINITY));
          else
            a = simde_mm512_mask_mov_pd(a, 2, simde_mm512_set1_pd(-SIMDE_MATH_INFINITY));
        }
      }
      int imm8 = ((j << 4) | round_type[i]) & 255;
      simde__m512d r;
      SIMDE_CONSTIFY_256_(simde_mm512_roundscale_pd, r, simde_mm512_setzero_pd(), imm8, a);

      simde_test_x86_write_f64x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
      simde_test_codegen_write_i32(2, imm8, SIMDE_TEST_VEC_POS_MIDDLE);
      simde_test_x86_write_f64x8(2, r, SIMDE_TEST_VEC_POS_LAST);
    }
  }
  return 1;
#endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_roundscale_ps)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_roundscale_ps)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_roundscale_ps)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_roundscale_pd)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_roundscale_pd)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_roundscale_pd)
SIMDE_TEST_FUNC_LIST_END

#include <test/x86/avx512/test-avx512-footer.h>
