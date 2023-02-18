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

  #if !defined(SIMDE_FAST_MATH)
  a = simde_mm_loadu_ps(test_vec[2].a);
  r = simde_mm_roundscale_ps(a, INT32_C(          32));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[2].r), 1);
  #endif

  a = simde_mm_loadu_ps(test_vec[3].a);
  r = simde_mm_roundscale_ps(a, INT32_C(          48));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[3].r), 1);

  #if !defined(SIMDE_FAST_MATH)
  a = simde_mm_loadu_ps(test_vec[4].a);
  r = simde_mm_roundscale_ps(a, INT32_C(          64));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[4].r), 1);
  #endif

  a = simde_mm_loadu_ps(test_vec[5].a);
  r = simde_mm_roundscale_ps(a, INT32_C(          80));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[5].r), 1);

  #if !defined(SIMDE_FAST_MATH)
  a = simde_mm_loadu_ps(test_vec[6].a);
  r = simde_mm_roundscale_ps(a, INT32_C(          96));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[6].r), 1);
  #endif

  a = simde_mm_loadu_ps(test_vec[7].a);
  r = simde_mm_roundscale_ps(a, INT32_C(         112));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[7].r), 1);

  a = simde_mm_loadu_ps(test_vec[8].a);
  r = simde_mm_roundscale_ps(a, INT32_C(         128));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[8].r), 1);

  #if !defined(SIMDE_FAST_MATH)
  a = simde_mm_loadu_ps(test_vec[9].a);
  r = simde_mm_roundscale_ps(a, INT32_C(         144));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[9].r), 1);
  #endif

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

  #if !defined(SIMDE_FAST_MATH)
  a = simde_mm_loadu_ps(test_vec[16].a);
  r = simde_mm_roundscale_ps(a, INT32_C(           1));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[16].r), 1);

  a = simde_mm_loadu_ps(test_vec[17].a);
  r = simde_mm_roundscale_ps(a, INT32_C(          17));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[17].r), 1);
  #endif

  a = simde_mm_loadu_ps(test_vec[18].a);
  r = simde_mm_roundscale_ps(a, INT32_C(          33));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[18].r), 1);

  a = simde_mm_loadu_ps(test_vec[19].a);
  r = simde_mm_roundscale_ps(a, INT32_C(          49));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[19].r), 1);

  #if !defined(SIMDE_FAST_MATH)
  a = simde_mm_loadu_ps(test_vec[20].a);
  r = simde_mm_roundscale_ps(a, INT32_C(          65));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[20].r), 1);

  a = simde_mm_loadu_ps(test_vec[21].a);
  r = simde_mm_roundscale_ps(a, INT32_C(          81));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[21].r), 1);
  #endif

  a = simde_mm_loadu_ps(test_vec[22].a);
  r = simde_mm_roundscale_ps(a, INT32_C(          97));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[22].r), 1);

  a = simde_mm_loadu_ps(test_vec[23].a);
  r = simde_mm_roundscale_ps(a, INT32_C(         113));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[23].r), 1);

  #if !defined(SIMDE_FAST_MATH)
  a = simde_mm_loadu_ps(test_vec[24].a);
  r = simde_mm_roundscale_ps(a, INT32_C(         129));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[24].r), 1);
  #endif

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

  #if !defined(SIMDE_FAST_MATH)
  a = simde_mm_loadu_ps(test_vec[32].a);
  r = simde_mm_roundscale_ps(a, INT32_C(           2));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[32].r), 1);

  a = simde_mm_loadu_ps(test_vec[33].a);
  r = simde_mm_roundscale_ps(a, INT32_C(          18));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[33].r), 1);
  #endif

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

  #if !defined(SIMDE_FAST_MATH)
  a = simde_mm_loadu_ps(test_vec[38].a);
  r = simde_mm_roundscale_ps(a, INT32_C(          98));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[38].r), 1);
  #endif

  a = simde_mm_loadu_ps(test_vec[39].a);
  r = simde_mm_roundscale_ps(a, INT32_C(         114));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[39].r), 1);

  a = simde_mm_loadu_ps(test_vec[40].a);
  r = simde_mm_roundscale_ps(a, INT32_C(         130));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[40].r), 1);

  a = simde_mm_loadu_ps(test_vec[41].a);
  r = simde_mm_roundscale_ps(a, INT32_C(         146));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[41].r), 1);

  #if !defined(SIMDE_FAST_MATH)
  a = simde_mm_loadu_ps(test_vec[42].a);
  r = simde_mm_roundscale_ps(a, INT32_C(         162));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[42].r), 1);
  #endif

  a = simde_mm_loadu_ps(test_vec[43].a);
  r = simde_mm_roundscale_ps(a, INT32_C(         178));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[43].r), 1);

  #if !defined(SIMDE_FAST_MATH)
  a = simde_mm_loadu_ps(test_vec[44].a);
  r = simde_mm_roundscale_ps(a, INT32_C(         194));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[44].r), 1);
  #endif

  a = simde_mm_loadu_ps(test_vec[45].a);
  r = simde_mm_roundscale_ps(a, INT32_C(         210));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[45].r), 1);

  a = simde_mm_loadu_ps(test_vec[46].a);
  r = simde_mm_roundscale_ps(a, INT32_C(         226));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[46].r), 1);

  a = simde_mm_loadu_ps(test_vec[47].a);
  r = simde_mm_roundscale_ps(a, INT32_C(         242));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[47].r), 1);

  #if !defined(SIMDE_FAST_MATH)
  a = simde_mm_loadu_ps(test_vec[48].a);
  r = simde_mm_roundscale_ps(a, INT32_C(           3));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[48].r), 1);
  #endif

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

  #if !defined(SIMDE_FAST_MATH)
  a = simde_mm_loadu_ps(test_vec[54].a);
  r = simde_mm_roundscale_ps(a, INT32_C(          99));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[54].r), 1);

  a = simde_mm_loadu_ps(test_vec[55].a);
  r = simde_mm_roundscale_ps(a, INT32_C(         115));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[55].r), 1);
  #endif

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

  #if !defined(SIMDE_FAST_MATH)
  a = simde_mm_loadu_ps(test_vec[61].a);
  r = simde_mm_roundscale_ps(a, INT32_C(         211));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[61].r), 1);
  #endif

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

  #if !defined(SIMDE_FAST_MATH)
  a = simde_mm_loadu_ps(test_vec[66].a);
  r = simde_mm_roundscale_ps(a, INT32_C(          36));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[66].r), 1);
  #endif

  a = simde_mm_loadu_ps(test_vec[67].a);
  r = simde_mm_roundscale_ps(a, INT32_C(          52));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[67].r), 1);

  a = simde_mm_loadu_ps(test_vec[68].a);
  r = simde_mm_roundscale_ps(a, INT32_C(          68));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[68].r), 1);

  a = simde_mm_loadu_ps(test_vec[69].a);
  r = simde_mm_roundscale_ps(a, INT32_C(          84));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[69].r), 1);

  #if !defined(SIMDE_FAST_MATH)
  a = simde_mm_loadu_ps(test_vec[70].a);
  r = simde_mm_roundscale_ps(a, INT32_C(         100));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[70].r), 1);
  #endif

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

  #if !defined(SIMDE_FAST_MATH)
  a = simde_mm_loadu_ps(test_vec[77].a);
  r = simde_mm_roundscale_ps(a, INT32_C(         212));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[77].r), 1);
  #endif

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
test_simde_mm_mask_roundscale_ps (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde_float32 src[4];
    const simde__mmask8 k;
    const simde_float32 a[4];
    const int32_t imm8;
    const simde_float32 r[4];
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(  -316.31), SIMDE_FLOAT32_C(   649.73), SIMDE_FLOAT32_C(   200.80), SIMDE_FLOAT32_C(   -79.92) },
      UINT8_C(161),
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   963.57), SIMDE_FLOAT32_C(  -663.71), SIMDE_FLOAT32_C(  -906.90) },
       INT32_C(         112),
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   649.73), SIMDE_FLOAT32_C(   200.80), SIMDE_FLOAT32_C(   -79.92) } },
    { { SIMDE_FLOAT32_C(  -584.01), SIMDE_FLOAT32_C(  -683.67), SIMDE_FLOAT32_C(   359.10), SIMDE_FLOAT32_C(   539.12) },
      UINT8_C( 84),
      { SIMDE_FLOAT32_C(  -642.45), SIMDE_FLOAT32_C(   980.52), SIMDE_FLOAT32_C(   709.42), SIMDE_FLOAT32_C(  -815.38) },
       INT32_C(          49),
      { SIMDE_FLOAT32_C(  -584.01), SIMDE_FLOAT32_C(  -683.67), SIMDE_FLOAT32_C(   709.38), SIMDE_FLOAT32_C(   539.12) } },
    { { SIMDE_FLOAT32_C(  -716.00), SIMDE_FLOAT32_C(  -111.36), SIMDE_FLOAT32_C(  -489.38), SIMDE_FLOAT32_C(   896.66) },
      UINT8_C(244),
      { SIMDE_FLOAT32_C(   -57.08), SIMDE_FLOAT32_C(  -626.52), SIMDE_FLOAT32_C(  -249.57), SIMDE_FLOAT32_C(   626.60) },
       INT32_C(          18),
      { SIMDE_FLOAT32_C(  -716.00), SIMDE_FLOAT32_C(  -111.36), SIMDE_FLOAT32_C(  -249.50), SIMDE_FLOAT32_C(   896.66) } },
    { { SIMDE_FLOAT32_C(  -453.32), SIMDE_FLOAT32_C(   134.70), SIMDE_FLOAT32_C(   315.58), SIMDE_FLOAT32_C(  -489.75) },
      UINT8_C(109),
      { SIMDE_FLOAT32_C(   408.68), SIMDE_FLOAT32_C(   792.03), SIMDE_FLOAT32_C(   887.75), SIMDE_FLOAT32_C(   573.55) },
       INT32_C(           3),
      { SIMDE_FLOAT32_C(   408.00), SIMDE_FLOAT32_C(   134.70), SIMDE_FLOAT32_C(   887.00), SIMDE_FLOAT32_C(   573.00) } },
    { { SIMDE_FLOAT32_C(   -67.35), SIMDE_FLOAT32_C(   747.13), SIMDE_FLOAT32_C(  -632.66), SIMDE_FLOAT32_C(   290.20) },
      UINT8_C(224),
      { SIMDE_FLOAT32_C(  -923.24),     -SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(   963.50), SIMDE_FLOAT32_C(  -799.60) },
       INT32_C(         148),
      { SIMDE_FLOAT32_C(   -67.35), SIMDE_FLOAT32_C(   747.13), SIMDE_FLOAT32_C(  -632.66), SIMDE_FLOAT32_C(   290.20) } },
    { { SIMDE_FLOAT32_C(  -984.94), SIMDE_FLOAT32_C(   653.94), SIMDE_FLOAT32_C(  -971.04), SIMDE_FLOAT32_C(  -234.51) },
      UINT8_C(123),
      { SIMDE_FLOAT32_C(  -947.82),     -SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(   827.23), SIMDE_FLOAT32_C(   186.88) },
       INT32_C(          64),
      { SIMDE_FLOAT32_C(  -947.81),     -SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(  -971.04), SIMDE_FLOAT32_C(   186.88) } },
    { { SIMDE_FLOAT32_C(  -870.49), SIMDE_FLOAT32_C(  -454.38), SIMDE_FLOAT32_C(    14.54), SIMDE_FLOAT32_C(  -662.48) },
      UINT8_C( 52),
      { SIMDE_FLOAT32_C(   947.19),      SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(   117.04), SIMDE_FLOAT32_C(   237.39) },
       INT32_C(          65),
      { SIMDE_FLOAT32_C(  -870.49), SIMDE_FLOAT32_C(  -454.38), SIMDE_FLOAT32_C(   117.00), SIMDE_FLOAT32_C(  -662.48) } },
    { { SIMDE_FLOAT32_C(   394.20), SIMDE_FLOAT32_C(  -528.97), SIMDE_FLOAT32_C(  -372.06), SIMDE_FLOAT32_C(  -894.77) },
      UINT8_C( 34),
      { SIMDE_FLOAT32_C(  -357.00),      SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(  -844.53), SIMDE_FLOAT32_C(   408.49) },
       INT32_C(          34),
      { SIMDE_FLOAT32_C(   394.20),      SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(  -372.06), SIMDE_FLOAT32_C(  -894.77) } },
  };

  simde__m128 src, a, r;

  #if !defined(SIMDE_FAST_MATH)
  src = simde_mm_loadu_ps(test_vec[0].src);
  a = simde_mm_loadu_ps(test_vec[0].a);
  r = simde_mm_mask_roundscale_ps(src, test_vec[0].k, a, INT32_C(         112));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[0].r), 1);
  #endif

  src = simde_mm_loadu_ps(test_vec[1].src);
  a = simde_mm_loadu_ps(test_vec[1].a);
  r = simde_mm_mask_roundscale_ps(src, test_vec[1].k, a, INT32_C(          49));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[1].r), 1);

  src = simde_mm_loadu_ps(test_vec[2].src);
  a = simde_mm_loadu_ps(test_vec[2].a);
  r = simde_mm_mask_roundscale_ps(src, test_vec[2].k, a, INT32_C(          18));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[2].r), 1);

  src = simde_mm_loadu_ps(test_vec[3].src);
  a = simde_mm_loadu_ps(test_vec[3].a);
  r = simde_mm_mask_roundscale_ps(src, test_vec[3].k, a, INT32_C(           3));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[3].r), 1);

  src = simde_mm_loadu_ps(test_vec[4].src);
  a = simde_mm_loadu_ps(test_vec[4].a);
  r = simde_mm_mask_roundscale_ps(src, test_vec[4].k, a, INT32_C(         148));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[4].r), 1);

  src = simde_mm_loadu_ps(test_vec[5].src);
  a = simde_mm_loadu_ps(test_vec[5].a);
  r = simde_mm_mask_roundscale_ps(src, test_vec[5].k, a, INT32_C(          64));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[5].r), 1);

  src = simde_mm_loadu_ps(test_vec[6].src);
  a = simde_mm_loadu_ps(test_vec[6].a);
  r = simde_mm_mask_roundscale_ps(src, test_vec[6].k, a, INT32_C(          65));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[6].r), 1);

  src = simde_mm_loadu_ps(test_vec[7].src);
  a = simde_mm_loadu_ps(test_vec[7].a);
  r = simde_mm_mask_roundscale_ps(src, test_vec[7].k, a, INT32_C(          34));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[7].r), 1);

  return 0;
#else
  fputc('\n', stdout);
  int round_type[5] = {SIMDE_MM_FROUND_TO_NEAREST_INT, SIMDE_MM_FROUND_TO_NEG_INF, SIMDE_MM_FROUND_TO_POS_INF, SIMDE_MM_FROUND_TO_ZERO, SIMDE_MM_FROUND_CUR_DIRECTION};
  for (int i = 0 ; i < 8 ; i++) {
    simde__m128 src = simde_test_x86_random_f32x4(SIMDE_FLOAT32_C(-1000.0), SIMDE_FLOAT32_C(1000.0));
    simde__mmask8 k = simde_test_x86_random_mmask8();
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
    int imm8 = (((simde_test_codegen_rand() & 15) << 4) | round_type[i % 5]) & 255;
    simde__m128 r;
    SIMDE_CONSTIFY_256_(simde_mm_mask_roundscale_ps, r, simde_mm_setzero_ps(), imm8, src, k, a);

    simde_test_x86_write_f32x4(2, src, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f32x4(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, imm8, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_maskz_roundscale_ps (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask8 k;
    const simde_float32 a[4];
    const int32_t imm8;
    const simde_float32 r[4];
  } test_vec[] = {
    { UINT8_C(155),
      { SIMDE_FLOAT32_C(  -842.49), SIMDE_FLOAT32_C(   204.44), SIMDE_FLOAT32_C(  -947.60), SIMDE_FLOAT32_C(   598.50) },
       INT32_C(         176),
      { SIMDE_FLOAT32_C(  -842.49), SIMDE_FLOAT32_C(   204.44), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   598.50) } },
    { UINT8_C(208),
      { SIMDE_FLOAT32_C(   671.48), SIMDE_FLOAT32_C(   347.71), SIMDE_FLOAT32_C(  -439.78), SIMDE_FLOAT32_C(   756.13) },
       INT32_C(         161),
      { SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00) } },
    { UINT8_C(139),
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -490.18), SIMDE_FLOAT32_C(   344.22), SIMDE_FLOAT32_C(    52.75) },
       INT32_C(          82),
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -490.16), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(    52.75) } },
    { UINT8_C( 73),
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   -82.84), SIMDE_FLOAT32_C(   262.82), SIMDE_FLOAT32_C(  -976.36) },
       INT32_C(         195),
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -976.36) } },
    { UINT8_C(175),
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -693.64), SIMDE_FLOAT32_C(  -971.72), SIMDE_FLOAT32_C(   -82.61) },
       INT32_C(          52),
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -693.62), SIMDE_FLOAT32_C(  -971.75), SIMDE_FLOAT32_C(   -82.62) } },
    { UINT8_C( 93),
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -136.88), SIMDE_FLOAT32_C(    78.11), SIMDE_FLOAT32_C(  -210.16) },
       INT32_C(          16),
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(    78.00), SIMDE_FLOAT32_C(  -210.00) } },
    { UINT8_C(240),
      { SIMDE_FLOAT32_C(   385.54), SIMDE_FLOAT32_C(   702.48), SIMDE_FLOAT32_C(  -960.83), SIMDE_FLOAT32_C(  -633.62) },
       INT32_C(         225),
      { SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00) } },
    { UINT8_C(112),
      { SIMDE_FLOAT32_C(  -710.21),      SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(  -263.45), SIMDE_FLOAT32_C(  -686.56) },
       INT32_C(         226),
      { SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00) } },
  };

  simde__m128 a, r;

  a = simde_mm_loadu_ps(test_vec[0].a);
  r = simde_mm_maskz_roundscale_ps(test_vec[0].k, a, INT32_C(         176));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[0].r), 1);

  a = simde_mm_loadu_ps(test_vec[1].a);
  r = simde_mm_maskz_roundscale_ps(test_vec[1].k, a, INT32_C(         161));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[1].r), 1);

  #if !defined(SIMDE_FAST_MATH)
  a = simde_mm_loadu_ps(test_vec[2].a);
  r = simde_mm_maskz_roundscale_ps(test_vec[2].k, a, INT32_C(          82));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[2].r), 1);

  a = simde_mm_loadu_ps(test_vec[3].a);
  r = simde_mm_maskz_roundscale_ps(test_vec[3].k, a, INT32_C(         195));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[3].r), 1);

  a = simde_mm_loadu_ps(test_vec[4].a);
  r = simde_mm_maskz_roundscale_ps(test_vec[4].k, a, INT32_C(          52));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[4].r), 1);

  a = simde_mm_loadu_ps(test_vec[5].a);
  r = simde_mm_maskz_roundscale_ps(test_vec[5].k, a, INT32_C(          16));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[5].r), 1);
  #endif

  a = simde_mm_loadu_ps(test_vec[6].a);
  r = simde_mm_maskz_roundscale_ps(test_vec[6].k, a, INT32_C(         225));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[6].r), 1);

  a = simde_mm_loadu_ps(test_vec[7].a);
  r = simde_mm_maskz_roundscale_ps(test_vec[7].k, a, INT32_C(         226));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[7].r), 1);

  return 0;
#else
  fputc('\n', stdout);
  int round_type[5] = {SIMDE_MM_FROUND_TO_NEAREST_INT, SIMDE_MM_FROUND_TO_NEG_INF, SIMDE_MM_FROUND_TO_POS_INF, SIMDE_MM_FROUND_TO_ZERO, SIMDE_MM_FROUND_CUR_DIRECTION};
  for (int i = 0 ; i < 8 ; i++) {
    simde__mmask8 k = simde_test_x86_random_mmask8();
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
    int imm8 = ((simde_test_codegen_rand() & 15) << 4 | round_type[i % 5]) & 255;
    simde__m128 r;
    SIMDE_CONSTIFY_256_(simde_mm_maskz_roundscale_ps, r, simde_mm_setzero_ps(), imm8, k, a);

    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_f32x4(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, imm8, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
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

  #if !defined(SIMDE_FAST_MATH)
  a = simde_mm256_loadu_ps(test_vec[5].a);
  r = simde_mm256_roundscale_ps(a, INT32_C(          80));
  simde_test_x86_assert_equal_f32x8(r, simde_mm256_loadu_ps(test_vec[5].r), 1);
  #endif

  a = simde_mm256_loadu_ps(test_vec[6].a);
  r = simde_mm256_roundscale_ps(a, INT32_C(          96));
  simde_test_x86_assert_equal_f32x8(r, simde_mm256_loadu_ps(test_vec[6].r), 1);

  #if !defined(SIMDE_FAST_MATH)
  a = simde_mm256_loadu_ps(test_vec[7].a);
  r = simde_mm256_roundscale_ps(a, INT32_C(         112));
  simde_test_x86_assert_equal_f32x8(r, simde_mm256_loadu_ps(test_vec[7].r), 1);

  a = simde_mm256_loadu_ps(test_vec[8].a);
  r = simde_mm256_roundscale_ps(a, INT32_C(         128));
  simde_test_x86_assert_equal_f32x8(r, simde_mm256_loadu_ps(test_vec[8].r), 1);
  #endif

  a = simde_mm256_loadu_ps(test_vec[9].a);
  r = simde_mm256_roundscale_ps(a, INT32_C(         144));
  simde_test_x86_assert_equal_f32x8(r, simde_mm256_loadu_ps(test_vec[9].r), 1);

  #if !defined(SIMDE_FAST_MATH)
  a = simde_mm256_loadu_ps(test_vec[10].a);
  r = simde_mm256_roundscale_ps(a, INT32_C(         160));
  simde_test_x86_assert_equal_f32x8(r, simde_mm256_loadu_ps(test_vec[10].r), 1);
  #endif

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

  #if !defined(SIMDE_FAST_MATH)
  a = simde_mm256_loadu_ps(test_vec[16].a);
  r = simde_mm256_roundscale_ps(a, INT32_C(           1));
  simde_test_x86_assert_equal_f32x8(r, simde_mm256_loadu_ps(test_vec[16].r), 1);
  #endif

  a = simde_mm256_loadu_ps(test_vec[17].a);
  r = simde_mm256_roundscale_ps(a, INT32_C(          17));
  simde_test_x86_assert_equal_f32x8(r, simde_mm256_loadu_ps(test_vec[17].r), 1);

  #if !defined(SIMDE_FAST_MATH)
  a = simde_mm256_loadu_ps(test_vec[18].a);
  r = simde_mm256_roundscale_ps(a, INT32_C(          33));
  simde_test_x86_assert_equal_f32x8(r, simde_mm256_loadu_ps(test_vec[18].r), 1);
  #endif

  a = simde_mm256_loadu_ps(test_vec[19].a);
  r = simde_mm256_roundscale_ps(a, INT32_C(          49));
  simde_test_x86_assert_equal_f32x8(r, simde_mm256_loadu_ps(test_vec[19].r), 1);

  a = simde_mm256_loadu_ps(test_vec[20].a);
  r = simde_mm256_roundscale_ps(a, INT32_C(          65));
  simde_test_x86_assert_equal_f32x8(r, simde_mm256_loadu_ps(test_vec[20].r), 1);

  #if !defined(SIMDE_FAST_MATH)
  a = simde_mm256_loadu_ps(test_vec[21].a);
  r = simde_mm256_roundscale_ps(a, INT32_C(          81));
  simde_test_x86_assert_equal_f32x8(r, simde_mm256_loadu_ps(test_vec[21].r), 1);

  a = simde_mm256_loadu_ps(test_vec[22].a);
  r = simde_mm256_roundscale_ps(a, INT32_C(          97));
  simde_test_x86_assert_equal_f32x8(r, simde_mm256_loadu_ps(test_vec[22].r), 1);
  #endif

  a = simde_mm256_loadu_ps(test_vec[23].a);
  r = simde_mm256_roundscale_ps(a, INT32_C(         113));
  simde_test_x86_assert_equal_f32x8(r, simde_mm256_loadu_ps(test_vec[23].r), 1);

  a = simde_mm256_loadu_ps(test_vec[24].a);
  r = simde_mm256_roundscale_ps(a, INT32_C(         129));
  simde_test_x86_assert_equal_f32x8(r, simde_mm256_loadu_ps(test_vec[24].r), 1);

  #if !defined(SIMDE_FAST_MATH)
  a = simde_mm256_loadu_ps(test_vec[25].a);
  r = simde_mm256_roundscale_ps(a, INT32_C(         145));
  simde_test_x86_assert_equal_f32x8(r, simde_mm256_loadu_ps(test_vec[25].r), 1);
  #endif

  a = simde_mm256_loadu_ps(test_vec[26].a);
  r = simde_mm256_roundscale_ps(a, INT32_C(         161));
  simde_test_x86_assert_equal_f32x8(r, simde_mm256_loadu_ps(test_vec[26].r), 1);

  a = simde_mm256_loadu_ps(test_vec[27].a);
  r = simde_mm256_roundscale_ps(a, INT32_C(         177));
  simde_test_x86_assert_equal_f32x8(r, simde_mm256_loadu_ps(test_vec[27].r), 1);

  a = simde_mm256_loadu_ps(test_vec[28].a);
  r = simde_mm256_roundscale_ps(a, INT32_C(         193));
  simde_test_x86_assert_equal_f32x8(r, simde_mm256_loadu_ps(test_vec[28].r), 1);

  #if !defined(SIMDE_FAST_MATH)
  a = simde_mm256_loadu_ps(test_vec[29].a);
  r = simde_mm256_roundscale_ps(a, INT32_C(         209));
  simde_test_x86_assert_equal_f32x8(r, simde_mm256_loadu_ps(test_vec[29].r), 1);

  a = simde_mm256_loadu_ps(test_vec[30].a);
  r = simde_mm256_roundscale_ps(a, INT32_C(         225));
  simde_test_x86_assert_equal_f32x8(r, simde_mm256_loadu_ps(test_vec[30].r), 1);
  #endif

  a = simde_mm256_loadu_ps(test_vec[31].a);
  r = simde_mm256_roundscale_ps(a, INT32_C(         241));
  simde_test_x86_assert_equal_f32x8(r, simde_mm256_loadu_ps(test_vec[31].r), 1);

  a = simde_mm256_loadu_ps(test_vec[32].a);
  r = simde_mm256_roundscale_ps(a, INT32_C(           2));
  simde_test_x86_assert_equal_f32x8(r, simde_mm256_loadu_ps(test_vec[32].r), 1);

  #if !defined(SIMDE_FAST_MATH)
  a = simde_mm256_loadu_ps(test_vec[33].a);
  r = simde_mm256_roundscale_ps(a, INT32_C(          18));
  simde_test_x86_assert_equal_f32x8(r, simde_mm256_loadu_ps(test_vec[33].r), 1);
  #endif

  a = simde_mm256_loadu_ps(test_vec[34].a);
  r = simde_mm256_roundscale_ps(a, INT32_C(          34));
  simde_test_x86_assert_equal_f32x8(r, simde_mm256_loadu_ps(test_vec[34].r), 1);

  a = simde_mm256_loadu_ps(test_vec[35].a);
  r = simde_mm256_roundscale_ps(a, INT32_C(          50));
  simde_test_x86_assert_equal_f32x8(r, simde_mm256_loadu_ps(test_vec[35].r), 1);

  a = simde_mm256_loadu_ps(test_vec[36].a);
  r = simde_mm256_roundscale_ps(a, INT32_C(          66));
  simde_test_x86_assert_equal_f32x8(r, simde_mm256_loadu_ps(test_vec[36].r), 1);

  #if !defined(SIMDE_FAST_MATH)
  a = simde_mm256_loadu_ps(test_vec[37].a);
  r = simde_mm256_roundscale_ps(a, INT32_C(          82));
  simde_test_x86_assert_equal_f32x8(r, simde_mm256_loadu_ps(test_vec[37].r), 1);

  a = simde_mm256_loadu_ps(test_vec[38].a);
  r = simde_mm256_roundscale_ps(a, INT32_C(          98));
  simde_test_x86_assert_equal_f32x8(r, simde_mm256_loadu_ps(test_vec[38].r), 1);
  #endif

  a = simde_mm256_loadu_ps(test_vec[39].a);
  r = simde_mm256_roundscale_ps(a, INT32_C(         114));
  simde_test_x86_assert_equal_f32x8(r, simde_mm256_loadu_ps(test_vec[39].r), 1);

  #if !defined(SIMDE_FAST_MATH)
  a = simde_mm256_loadu_ps(test_vec[40].a);
  r = simde_mm256_roundscale_ps(a, INT32_C(         130));
  simde_test_x86_assert_equal_f32x8(r, simde_mm256_loadu_ps(test_vec[40].r), 1);
  #endif

  a = simde_mm256_loadu_ps(test_vec[41].a);
  r = simde_mm256_roundscale_ps(a, INT32_C(         146));
  simde_test_x86_assert_equal_f32x8(r, simde_mm256_loadu_ps(test_vec[41].r), 1);

  a = simde_mm256_loadu_ps(test_vec[42].a);
  r = simde_mm256_roundscale_ps(a, INT32_C(         162));
  simde_test_x86_assert_equal_f32x8(r, simde_mm256_loadu_ps(test_vec[42].r), 1);

  #if !defined(SIMDE_FAST_MATH)
  a = simde_mm256_loadu_ps(test_vec[43].a);
  r = simde_mm256_roundscale_ps(a, INT32_C(         178));
  simde_test_x86_assert_equal_f32x8(r, simde_mm256_loadu_ps(test_vec[43].r), 1);
  #endif

  a = simde_mm256_loadu_ps(test_vec[44].a);
  r = simde_mm256_roundscale_ps(a, INT32_C(         194));
  simde_test_x86_assert_equal_f32x8(r, simde_mm256_loadu_ps(test_vec[44].r), 1);

  #if !defined(SIMDE_FAST_MATH)
  a = simde_mm256_loadu_ps(test_vec[45].a);
  r = simde_mm256_roundscale_ps(a, INT32_C(         210));
  simde_test_x86_assert_equal_f32x8(r, simde_mm256_loadu_ps(test_vec[45].r), 1);

  a = simde_mm256_loadu_ps(test_vec[46].a);
  r = simde_mm256_roundscale_ps(a, INT32_C(         226));
  simde_test_x86_assert_equal_f32x8(r, simde_mm256_loadu_ps(test_vec[46].r), 1);

  a = simde_mm256_loadu_ps(test_vec[47].a);
  r = simde_mm256_roundscale_ps(a, INT32_C(         242));
  simde_test_x86_assert_equal_f32x8(r, simde_mm256_loadu_ps(test_vec[47].r), 1);
  #endif

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

  #if !defined(SIMDE_FAST_MATH)
  a = simde_mm256_loadu_ps(test_vec[53].a);
  r = simde_mm256_roundscale_ps(a, INT32_C(          83));
  simde_test_x86_assert_equal_f32x8(r, simde_mm256_loadu_ps(test_vec[53].r), 1);
  #endif

  a = simde_mm256_loadu_ps(test_vec[54].a);
  r = simde_mm256_roundscale_ps(a, INT32_C(          99));
  simde_test_x86_assert_equal_f32x8(r, simde_mm256_loadu_ps(test_vec[54].r), 1);

  a = simde_mm256_loadu_ps(test_vec[55].a);
  r = simde_mm256_roundscale_ps(a, INT32_C(         115));
  simde_test_x86_assert_equal_f32x8(r, simde_mm256_loadu_ps(test_vec[55].r), 1);

  #if !defined(SIMDE_FAST_MATH)
  a = simde_mm256_loadu_ps(test_vec[56].a);
  r = simde_mm256_roundscale_ps(a, INT32_C(         131));
  simde_test_x86_assert_equal_f32x8(r, simde_mm256_loadu_ps(test_vec[56].r), 1);
  #endif

  a = simde_mm256_loadu_ps(test_vec[57].a);
  r = simde_mm256_roundscale_ps(a, INT32_C(         147));
  simde_test_x86_assert_equal_f32x8(r, simde_mm256_loadu_ps(test_vec[57].r), 1);

  #if !defined(SIMDE_FAST_MATH)
  a = simde_mm256_loadu_ps(test_vec[58].a);
  r = simde_mm256_roundscale_ps(a, INT32_C(         163));
  simde_test_x86_assert_equal_f32x8(r, simde_mm256_loadu_ps(test_vec[58].r), 1);
  #endif

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

  #if !defined(SIMDE_FAST_MATH)
  a = simde_mm256_loadu_ps(test_vec[65].a);
  r = simde_mm256_roundscale_ps(a, INT32_C(          20));
  simde_test_x86_assert_equal_f32x8(r, simde_mm256_loadu_ps(test_vec[65].r), 1);

  a = simde_mm256_loadu_ps(test_vec[66].a);
  r = simde_mm256_roundscale_ps(a, INT32_C(          36));
  simde_test_x86_assert_equal_f32x8(r, simde_mm256_loadu_ps(test_vec[66].r), 1);
  #endif

  a = simde_mm256_loadu_ps(test_vec[67].a);
  r = simde_mm256_roundscale_ps(a, INT32_C(          52));
  simde_test_x86_assert_equal_f32x8(r, simde_mm256_loadu_ps(test_vec[67].r), 1);

  #if !defined(SIMDE_FAST_MATH)
  a = simde_mm256_loadu_ps(test_vec[68].a);
  r = simde_mm256_roundscale_ps(a, INT32_C(          68));
  simde_test_x86_assert_equal_f32x8(r, simde_mm256_loadu_ps(test_vec[68].r), 1);

  a = simde_mm256_loadu_ps(test_vec[69].a);
  r = simde_mm256_roundscale_ps(a, INT32_C(          84));
  simde_test_x86_assert_equal_f32x8(r, simde_mm256_loadu_ps(test_vec[69].r), 1);
  #endif

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

  #if !defined(SIMDE_FAST_MATH)
  a = simde_mm256_loadu_ps(test_vec[74].a);
  r = simde_mm256_roundscale_ps(a, INT32_C(         164));
  simde_test_x86_assert_equal_f32x8(r, simde_mm256_loadu_ps(test_vec[74].r), 1);
  #endif

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
test_simde_mm256_mask_roundscale_ps (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde_float32 src[8];
    const simde__mmask8 k;
    const simde_float32 a[8];
    const int32_t imm8;
    const simde_float32 r[8];
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(  -382.29), SIMDE_FLOAT32_C(   330.96), SIMDE_FLOAT32_C(  -644.44), SIMDE_FLOAT32_C(  -895.86),
        SIMDE_FLOAT32_C(  -385.41), SIMDE_FLOAT32_C(    71.12), SIMDE_FLOAT32_C(  -739.06), SIMDE_FLOAT32_C(  -344.61) },
      UINT8_C(122),
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -792.25), SIMDE_FLOAT32_C(  -224.49), SIMDE_FLOAT32_C(  -501.18),
        SIMDE_FLOAT32_C(  -757.05), SIMDE_FLOAT32_C(  -370.84), SIMDE_FLOAT32_C(   682.90), SIMDE_FLOAT32_C(  -710.21) },
       INT32_C(         128),
      { SIMDE_FLOAT32_C(  -382.29), SIMDE_FLOAT32_C(  -792.25), SIMDE_FLOAT32_C(  -644.44), SIMDE_FLOAT32_C(  -501.18),
        SIMDE_FLOAT32_C(  -757.05), SIMDE_FLOAT32_C(  -370.84), SIMDE_FLOAT32_C(   682.90), SIMDE_FLOAT32_C(  -344.61) } },
    { { SIMDE_FLOAT32_C(   148.79), SIMDE_FLOAT32_C(   905.05), SIMDE_FLOAT32_C(  -276.16), SIMDE_FLOAT32_C(   916.96),
        SIMDE_FLOAT32_C(  -272.05), SIMDE_FLOAT32_C(   859.28), SIMDE_FLOAT32_C(  -998.23), SIMDE_FLOAT32_C(  -263.23) },
      UINT8_C( 53),
      { SIMDE_FLOAT32_C(   936.67),      SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(   162.47), SIMDE_FLOAT32_C(   267.63),
        SIMDE_FLOAT32_C(  -153.82), SIMDE_FLOAT32_C(   266.61), SIMDE_FLOAT32_C(   882.21), SIMDE_FLOAT32_C(   917.30) },
       INT32_C(         161),
      { SIMDE_FLOAT32_C(   936.67), SIMDE_FLOAT32_C(   905.05), SIMDE_FLOAT32_C(   162.47), SIMDE_FLOAT32_C(   916.96),
        SIMDE_FLOAT32_C(  -153.82), SIMDE_FLOAT32_C(   266.61), SIMDE_FLOAT32_C(  -998.23), SIMDE_FLOAT32_C(  -263.23) } },
    { { SIMDE_FLOAT32_C(  -254.64), SIMDE_FLOAT32_C(   772.87), SIMDE_FLOAT32_C(   717.70), SIMDE_FLOAT32_C(   -11.69),
        SIMDE_FLOAT32_C(  -597.96), SIMDE_FLOAT32_C(   400.60), SIMDE_FLOAT32_C(   278.10), SIMDE_FLOAT32_C(   809.76) },
      UINT8_C(221),
      { SIMDE_FLOAT32_C(    79.41), SIMDE_FLOAT32_C(   -41.45), SIMDE_FLOAT32_C(  -916.66), SIMDE_FLOAT32_C(   803.25),
        SIMDE_FLOAT32_C(  -124.49), SIMDE_FLOAT32_C(  -188.71), SIMDE_FLOAT32_C(   662.53), SIMDE_FLOAT32_C(  -122.72) },
       INT32_C(         130),
      { SIMDE_FLOAT32_C(    79.41), SIMDE_FLOAT32_C(   772.87), SIMDE_FLOAT32_C(  -916.66), SIMDE_FLOAT32_C(   803.25),
        SIMDE_FLOAT32_C(  -124.49), SIMDE_FLOAT32_C(   400.60), SIMDE_FLOAT32_C(   662.53), SIMDE_FLOAT32_C(  -122.72) } },
    { { SIMDE_FLOAT32_C(  -186.05), SIMDE_FLOAT32_C(  -961.32), SIMDE_FLOAT32_C(   369.76), SIMDE_FLOAT32_C(  -918.43),
        SIMDE_FLOAT32_C(  -115.14), SIMDE_FLOAT32_C(  -363.64), SIMDE_FLOAT32_C(   963.79), SIMDE_FLOAT32_C(  -197.84) },
      UINT8_C(146),
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   799.52), SIMDE_FLOAT32_C(   382.78), SIMDE_FLOAT32_C(   246.75),
        SIMDE_FLOAT32_C(   572.39), SIMDE_FLOAT32_C(   100.49), SIMDE_FLOAT32_C(  -764.95), SIMDE_FLOAT32_C(   974.43) },
       INT32_C(         227),
      { SIMDE_FLOAT32_C(  -186.05), SIMDE_FLOAT32_C(   799.52), SIMDE_FLOAT32_C(   369.76), SIMDE_FLOAT32_C(  -918.43),
        SIMDE_FLOAT32_C(   572.39), SIMDE_FLOAT32_C(  -363.64), SIMDE_FLOAT32_C(   963.79), SIMDE_FLOAT32_C(   974.43) } },
    { { SIMDE_FLOAT32_C(  -320.62), SIMDE_FLOAT32_C(  -407.44), SIMDE_FLOAT32_C(  -257.26), SIMDE_FLOAT32_C(  -237.28),
        SIMDE_FLOAT32_C(  -604.19), SIMDE_FLOAT32_C(   618.25), SIMDE_FLOAT32_C(   574.00), SIMDE_FLOAT32_C(  -941.65) },
      UINT8_C(240),
      { SIMDE_FLOAT32_C(   122.06), SIMDE_FLOAT32_C(  -734.36), SIMDE_FLOAT32_C(   309.48), SIMDE_FLOAT32_C(   160.74),
        SIMDE_FLOAT32_C(   635.39), SIMDE_FLOAT32_C(   391.06), SIMDE_FLOAT32_C(  -954.40), SIMDE_FLOAT32_C(  -728.25) },
       INT32_C(         164),
      { SIMDE_FLOAT32_C(  -320.62), SIMDE_FLOAT32_C(  -407.44), SIMDE_FLOAT32_C(  -257.26), SIMDE_FLOAT32_C(  -237.28),
        SIMDE_FLOAT32_C(   635.39), SIMDE_FLOAT32_C(   391.06), SIMDE_FLOAT32_C(  -954.40), SIMDE_FLOAT32_C(  -728.25) } },
    { { SIMDE_FLOAT32_C(  -564.34), SIMDE_FLOAT32_C(   856.23), SIMDE_FLOAT32_C(  -352.72), SIMDE_FLOAT32_C(   818.44),
        SIMDE_FLOAT32_C(   102.98), SIMDE_FLOAT32_C(  -780.33), SIMDE_FLOAT32_C(   -81.07), SIMDE_FLOAT32_C(   338.03) },
      UINT8_C(186),
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -148.82), SIMDE_FLOAT32_C(   978.30), SIMDE_FLOAT32_C(  -900.61),
        SIMDE_FLOAT32_C(   443.74), SIMDE_FLOAT32_C(  -278.96), SIMDE_FLOAT32_C(  -137.89), SIMDE_FLOAT32_C(   839.56) },
       INT32_C(         240),
      { SIMDE_FLOAT32_C(  -564.34), SIMDE_FLOAT32_C(  -148.82), SIMDE_FLOAT32_C(  -352.72), SIMDE_FLOAT32_C(  -900.61),
        SIMDE_FLOAT32_C(   443.74), SIMDE_FLOAT32_C(  -278.96), SIMDE_FLOAT32_C(   -81.07), SIMDE_FLOAT32_C(   839.56) } },
    { { SIMDE_FLOAT32_C(  -165.18), SIMDE_FLOAT32_C(   558.18), SIMDE_FLOAT32_C(  -836.46), SIMDE_FLOAT32_C(  -855.69),
        SIMDE_FLOAT32_C(  -281.08), SIMDE_FLOAT32_C(   798.94), SIMDE_FLOAT32_C(   535.36), SIMDE_FLOAT32_C(  -235.48) },
      UINT8_C(245),
      { SIMDE_FLOAT32_C(  -109.79), SIMDE_FLOAT32_C(   612.29), SIMDE_FLOAT32_C(  -493.65), SIMDE_FLOAT32_C(  -253.56),
        SIMDE_FLOAT32_C(  -740.43), SIMDE_FLOAT32_C(  -675.21), SIMDE_FLOAT32_C(   849.42), SIMDE_FLOAT32_C(  -520.76) },
       INT32_C(         161),
      { SIMDE_FLOAT32_C(  -109.79), SIMDE_FLOAT32_C(   558.18), SIMDE_FLOAT32_C(  -493.65), SIMDE_FLOAT32_C(  -855.69),
        SIMDE_FLOAT32_C(  -740.43), SIMDE_FLOAT32_C(  -675.21), SIMDE_FLOAT32_C(   849.42), SIMDE_FLOAT32_C(  -520.76) } },
    { { SIMDE_FLOAT32_C(  -326.65), SIMDE_FLOAT32_C(  -336.27), SIMDE_FLOAT32_C(  -961.37), SIMDE_FLOAT32_C(  -348.35),
        SIMDE_FLOAT32_C(  -236.87), SIMDE_FLOAT32_C(   482.37), SIMDE_FLOAT32_C(   372.69), SIMDE_FLOAT32_C(   625.24) },
      UINT8_C( 34),
      { SIMDE_FLOAT32_C(   711.98),     -SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(   219.84), SIMDE_FLOAT32_C(  -453.20),
        SIMDE_FLOAT32_C(   619.54), SIMDE_FLOAT32_C(   383.38), SIMDE_FLOAT32_C(  -308.89), SIMDE_FLOAT32_C(  -661.54) },
       INT32_C(           2),
      { SIMDE_FLOAT32_C(  -326.65),     -SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(  -961.37), SIMDE_FLOAT32_C(  -348.35),
        SIMDE_FLOAT32_C(  -236.87), SIMDE_FLOAT32_C(   384.00), SIMDE_FLOAT32_C(   372.69), SIMDE_FLOAT32_C(   625.24) } },
  };

  simde__m256 src, a, r;

  src = simde_mm256_loadu_ps(test_vec[0].src);
  a = simde_mm256_loadu_ps(test_vec[0].a);
  r = simde_mm256_mask_roundscale_ps(src, test_vec[0].k, a, INT32_C(         128));
  simde_test_x86_assert_equal_f32x8(r, simde_mm256_loadu_ps(test_vec[0].r), 1);

  src = simde_mm256_loadu_ps(test_vec[1].src);
  a = simde_mm256_loadu_ps(test_vec[1].a);
  r = simde_mm256_mask_roundscale_ps(src, test_vec[1].k, a, INT32_C(         161));
  simde_test_x86_assert_equal_f32x8(r, simde_mm256_loadu_ps(test_vec[1].r), 1);

  src = simde_mm256_loadu_ps(test_vec[2].src);
  a = simde_mm256_loadu_ps(test_vec[2].a);
  r = simde_mm256_mask_roundscale_ps(src, test_vec[2].k, a, INT32_C(         130));
  simde_test_x86_assert_equal_f32x8(r, simde_mm256_loadu_ps(test_vec[2].r), 1);

  src = simde_mm256_loadu_ps(test_vec[3].src);
  a = simde_mm256_loadu_ps(test_vec[3].a);
  r = simde_mm256_mask_roundscale_ps(src, test_vec[3].k, a, INT32_C(         227));
  simde_test_x86_assert_equal_f32x8(r, simde_mm256_loadu_ps(test_vec[3].r), 1);

  src = simde_mm256_loadu_ps(test_vec[4].src);
  a = simde_mm256_loadu_ps(test_vec[4].a);
  r = simde_mm256_mask_roundscale_ps(src, test_vec[4].k, a, INT32_C(         164));
  simde_test_x86_assert_equal_f32x8(r, simde_mm256_loadu_ps(test_vec[4].r), 1);

  src = simde_mm256_loadu_ps(test_vec[5].src);
  a = simde_mm256_loadu_ps(test_vec[5].a);
  r = simde_mm256_mask_roundscale_ps(src, test_vec[5].k, a, INT32_C(         240));
  simde_test_x86_assert_equal_f32x8(r, simde_mm256_loadu_ps(test_vec[5].r), 1);

  src = simde_mm256_loadu_ps(test_vec[6].src);
  a = simde_mm256_loadu_ps(test_vec[6].a);
  r = simde_mm256_mask_roundscale_ps(src, test_vec[6].k, a, INT32_C(         161));
  simde_test_x86_assert_equal_f32x8(r, simde_mm256_loadu_ps(test_vec[6].r), 1);

  src = simde_mm256_loadu_ps(test_vec[7].src);
  a = simde_mm256_loadu_ps(test_vec[7].a);
  r = simde_mm256_mask_roundscale_ps(src, test_vec[7].k, a, INT32_C(           2));
  simde_test_x86_assert_equal_f32x8(r, simde_mm256_loadu_ps(test_vec[7].r), 1);

  return 0;
#else
  fputc('\n', stdout);
  int round_type[5] = {SIMDE_MM_FROUND_TO_NEAREST_INT, SIMDE_MM_FROUND_TO_NEG_INF, SIMDE_MM_FROUND_TO_POS_INF, SIMDE_MM_FROUND_TO_ZERO, SIMDE_MM_FROUND_CUR_DIRECTION};
  for (int i = 0 ; i < 8 ; i++) {
    simde__m256 src = simde_test_x86_random_f32x8(SIMDE_FLOAT32_C(-1000.0), SIMDE_FLOAT32_C(1000.0));
    simde__mmask8 k = simde_test_x86_random_mmask8();
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
    int imm8 = (((simde_test_codegen_rand() & 15) << 4) | round_type[i % 5]) & 255;
    simde__m256 r;
    SIMDE_CONSTIFY_256_(simde_mm256_mask_roundscale_ps, r, simde_mm256_setzero_ps(), imm8, src, k, a);

    simde_test_x86_write_f32x8(2, src, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f32x8(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, imm8, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f32x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm256_maskz_roundscale_ps (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask8 k;
    const simde_float32 a[8];
    const int32_t imm8;
    const simde_float32 r[8];
  } test_vec[] = {
    { UINT8_C(253),
      { SIMDE_FLOAT32_C(  -284.73), SIMDE_FLOAT32_C(   759.36), SIMDE_FLOAT32_C(   863.12), SIMDE_FLOAT32_C(   -25.16),
        SIMDE_FLOAT32_C(  -915.85), SIMDE_FLOAT32_C(   712.53), SIMDE_FLOAT32_C(   454.09), SIMDE_FLOAT32_C(   327.86) },
       INT32_C(           0),
      { SIMDE_FLOAT32_C(  -285.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   863.00), SIMDE_FLOAT32_C(   -25.00),
        SIMDE_FLOAT32_C(  -916.00), SIMDE_FLOAT32_C(   713.00), SIMDE_FLOAT32_C(   454.00), SIMDE_FLOAT32_C(   328.00) } },
    { UINT8_C(211),
      { SIMDE_FLOAT32_C(   -61.39), SIMDE_FLOAT32_C(  -220.92), SIMDE_FLOAT32_C(  -245.28), SIMDE_FLOAT32_C(  -579.01),
        SIMDE_FLOAT32_C(  -848.23), SIMDE_FLOAT32_C(  -620.04), SIMDE_FLOAT32_C(   742.92), SIMDE_FLOAT32_C(   863.75) },
       INT32_C(          65),
      { SIMDE_FLOAT32_C(   -61.44), SIMDE_FLOAT32_C(  -220.94), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(  -848.25), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   742.88), SIMDE_FLOAT32_C(   863.75) } },
    { UINT8_C( 80),
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -653.86), SIMDE_FLOAT32_C(   101.66), SIMDE_FLOAT32_C(  -600.69),
        SIMDE_FLOAT32_C(   528.46), SIMDE_FLOAT32_C(   328.14), SIMDE_FLOAT32_C(   502.30), SIMDE_FLOAT32_C(  -218.53) },
       INT32_C(         162),
      { SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(   528.46), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   502.30), SIMDE_FLOAT32_C(     0.00) } },
    { UINT8_C( 86),
      { SIMDE_FLOAT32_C(   192.41), SIMDE_FLOAT32_C(  -375.03), SIMDE_FLOAT32_C(  -979.53), SIMDE_FLOAT32_C(  -353.51),
        SIMDE_FLOAT32_C(   952.83), SIMDE_FLOAT32_C(   -79.55), SIMDE_FLOAT32_C(  -226.07), SIMDE_FLOAT32_C(   944.43) },
       INT32_C(           3),
      { SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -375.00), SIMDE_FLOAT32_C(  -979.00), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(   952.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -226.00), SIMDE_FLOAT32_C(     0.00) } },
    { UINT8_C( 65),
      { SIMDE_FLOAT32_C(  -719.95), SIMDE_FLOAT32_C(   704.78), SIMDE_FLOAT32_C(    79.10), SIMDE_FLOAT32_C(  -977.03),
        SIMDE_FLOAT32_C(   568.53), SIMDE_FLOAT32_C(   520.42), SIMDE_FLOAT32_C(   -14.27), SIMDE_FLOAT32_C(   979.08) },
       INT32_C(         244),
      { SIMDE_FLOAT32_C(  -719.95), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   -14.27), SIMDE_FLOAT32_C(     0.00) } },
    { UINT8_C(149),
      { SIMDE_FLOAT32_C(   980.58),     -SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(  -591.12), SIMDE_FLOAT32_C(   482.88),
        SIMDE_FLOAT32_C(   641.81), SIMDE_FLOAT32_C(  -146.31), SIMDE_FLOAT32_C(   700.45), SIMDE_FLOAT32_C(  -817.37) },
       INT32_C(          32),
      { SIMDE_FLOAT32_C(   980.50), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -591.00), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(   641.75), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -817.25) } },
    { UINT8_C( 12),
      { SIMDE_FLOAT32_C(  -239.56), SIMDE_FLOAT32_C(  -897.46), SIMDE_FLOAT32_C(  -686.72), SIMDE_FLOAT32_C(  -295.14),
        SIMDE_FLOAT32_C(   961.60), SIMDE_FLOAT32_C(   866.29), SIMDE_FLOAT32_C(   404.01), SIMDE_FLOAT32_C(  -758.35) },
       INT32_C(         241),
      { SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -686.72), SIMDE_FLOAT32_C(  -295.14),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00) } },
    { UINT8_C(176),
      { SIMDE_FLOAT32_C(   139.60),     -SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(   250.35), SIMDE_FLOAT32_C(   118.68),
        SIMDE_FLOAT32_C(   584.80), SIMDE_FLOAT32_C(  -417.77), SIMDE_FLOAT32_C(  -800.58), SIMDE_FLOAT32_C(   565.38) },
       INT32_C(          18),
      { SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(   585.00), SIMDE_FLOAT32_C(  -417.50), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   565.50) } },
  };

  simde__m256 a, r;

  a = simde_mm256_loadu_ps(test_vec[0].a);
  r = simde_mm256_maskz_roundscale_ps(test_vec[0].k, a, INT32_C(           0));
  simde_test_x86_assert_equal_f32x8(r, simde_mm256_loadu_ps(test_vec[0].r), 1);

  a = simde_mm256_loadu_ps(test_vec[1].a);
  r = simde_mm256_maskz_roundscale_ps(test_vec[1].k, a, INT32_C(          65));
  simde_test_x86_assert_equal_f32x8(r, simde_mm256_loadu_ps(test_vec[1].r), 1);

  a = simde_mm256_loadu_ps(test_vec[2].a);
  r = simde_mm256_maskz_roundscale_ps(test_vec[2].k, a, INT32_C(         162));
  simde_test_x86_assert_equal_f32x8(r, simde_mm256_loadu_ps(test_vec[2].r), 1);

  a = simde_mm256_loadu_ps(test_vec[3].a);
  r = simde_mm256_maskz_roundscale_ps(test_vec[3].k, a, INT32_C(           3));
  simde_test_x86_assert_equal_f32x8(r, simde_mm256_loadu_ps(test_vec[3].r), 1);

  a = simde_mm256_loadu_ps(test_vec[4].a);
  r = simde_mm256_maskz_roundscale_ps(test_vec[4].k, a, INT32_C(         244));
  simde_test_x86_assert_equal_f32x8(r, simde_mm256_loadu_ps(test_vec[4].r), 1);

  a = simde_mm256_loadu_ps(test_vec[5].a);
  r = simde_mm256_maskz_roundscale_ps(test_vec[5].k, a, INT32_C(          32));
  simde_test_x86_assert_equal_f32x8(r, simde_mm256_loadu_ps(test_vec[5].r), 1);

  a = simde_mm256_loadu_ps(test_vec[6].a);
  r = simde_mm256_maskz_roundscale_ps(test_vec[6].k, a, INT32_C(         241));
  simde_test_x86_assert_equal_f32x8(r, simde_mm256_loadu_ps(test_vec[6].r), 1);

  a = simde_mm256_loadu_ps(test_vec[7].a);
  r = simde_mm256_maskz_roundscale_ps(test_vec[7].k, a, INT32_C(          18));
  simde_test_x86_assert_equal_f32x8(r, simde_mm256_loadu_ps(test_vec[7].r), 1);

  return 0;
#else
  fputc('\n', stdout);
  int round_type[5] = {SIMDE_MM_FROUND_TO_NEAREST_INT, SIMDE_MM_FROUND_TO_NEG_INF, SIMDE_MM_FROUND_TO_POS_INF, SIMDE_MM_FROUND_TO_ZERO, SIMDE_MM_FROUND_CUR_DIRECTION};
  for (int i = 0 ; i < 8 ; i++) {
    simde__mmask8 k = simde_test_x86_random_mmask8();
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
    int imm8 = (((simde_test_codegen_rand() & 15) << 4) | round_type[i % 5]) & 255;
    simde__m256 r;
    SIMDE_CONSTIFY_256_(simde_mm256_maskz_roundscale_ps, r, simde_mm256_setzero_ps(), imm8, k, a);

    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_f32x8(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, imm8, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f32x8(2, r, SIMDE_TEST_VEC_POS_LAST);
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
    { {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -423.81), SIMDE_FLOAT32_C(  -634.18), SIMDE_FLOAT32_C(   554.60),
        SIMDE_FLOAT32_C(   173.43), SIMDE_FLOAT32_C(  -344.33), SIMDE_FLOAT32_C(  -362.67), SIMDE_FLOAT32_C(   218.91),
        SIMDE_FLOAT32_C(   598.01), SIMDE_FLOAT32_C(  -225.45), SIMDE_FLOAT32_C(   616.45), SIMDE_FLOAT32_C(  -416.23),
        SIMDE_FLOAT32_C(   663.74), SIMDE_FLOAT32_C(  -752.24), SIMDE_FLOAT32_C(  -575.44), SIMDE_FLOAT32_C(   644.36) },
       INT32_C(          64),
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -423.81), SIMDE_FLOAT32_C(  -634.19), SIMDE_FLOAT32_C(   554.62),
        SIMDE_FLOAT32_C(   173.44), SIMDE_FLOAT32_C(  -344.31), SIMDE_FLOAT32_C(  -362.69), SIMDE_FLOAT32_C(   218.94),
        SIMDE_FLOAT32_C(   598.00), SIMDE_FLOAT32_C(  -225.44), SIMDE_FLOAT32_C(   616.44), SIMDE_FLOAT32_C(  -416.25),
        SIMDE_FLOAT32_C(   663.75), SIMDE_FLOAT32_C(  -752.25), SIMDE_FLOAT32_C(  -575.44), SIMDE_FLOAT32_C(   644.38) } },
    { {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -162.62), SIMDE_FLOAT32_C(  -235.77), SIMDE_FLOAT32_C(  -694.67),
        SIMDE_FLOAT32_C(  -373.82), SIMDE_FLOAT32_C(   410.37), SIMDE_FLOAT32_C(  -543.77), SIMDE_FLOAT32_C(   -52.66),
        SIMDE_FLOAT32_C(   243.41), SIMDE_FLOAT32_C(   -55.65), SIMDE_FLOAT32_C(  -148.17), SIMDE_FLOAT32_C(   380.17),
        SIMDE_FLOAT32_C(   696.43), SIMDE_FLOAT32_C(   428.02), SIMDE_FLOAT32_C(   745.99), SIMDE_FLOAT32_C(   251.03) },
       INT32_C(           1),
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -163.00), SIMDE_FLOAT32_C(  -236.00), SIMDE_FLOAT32_C(  -695.00),
        SIMDE_FLOAT32_C(  -374.00), SIMDE_FLOAT32_C(   410.00), SIMDE_FLOAT32_C(  -544.00), SIMDE_FLOAT32_C(   -53.00),
        SIMDE_FLOAT32_C(   243.00), SIMDE_FLOAT32_C(   -56.00), SIMDE_FLOAT32_C(  -149.00), SIMDE_FLOAT32_C(   380.00),
        SIMDE_FLOAT32_C(   696.00), SIMDE_FLOAT32_C(   428.00), SIMDE_FLOAT32_C(   745.00), SIMDE_FLOAT32_C(   251.00) } },
    { { SIMDE_FLOAT32_C(   820.36),     -SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(  -337.09), SIMDE_FLOAT32_C(   436.80),
        SIMDE_FLOAT32_C(  -416.55), SIMDE_FLOAT32_C(  -673.34), SIMDE_FLOAT32_C(   684.56), SIMDE_FLOAT32_C(     8.00),
        SIMDE_FLOAT32_C(   971.02), SIMDE_FLOAT32_C(  -601.46), SIMDE_FLOAT32_C(  -889.67), SIMDE_FLOAT32_C(  -791.40),
        SIMDE_FLOAT32_C(  -347.68), SIMDE_FLOAT32_C(   -52.29), SIMDE_FLOAT32_C(   -27.17), SIMDE_FLOAT32_C(   -42.36) },
       INT32_C(          98),
      { SIMDE_FLOAT32_C(   820.38),     -SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(  -337.08), SIMDE_FLOAT32_C(   436.81),
        SIMDE_FLOAT32_C(  -416.55), SIMDE_FLOAT32_C(  -673.33), SIMDE_FLOAT32_C(   684.56), SIMDE_FLOAT32_C(     8.00),
        SIMDE_FLOAT32_C(   971.03), SIMDE_FLOAT32_C(  -601.45), SIMDE_FLOAT32_C(  -889.66), SIMDE_FLOAT32_C(  -791.39),
        SIMDE_FLOAT32_C(  -347.67), SIMDE_FLOAT32_C(   -52.28), SIMDE_FLOAT32_C(   -27.16), SIMDE_FLOAT32_C(   -42.36) } },
    { { SIMDE_FLOAT32_C(   626.60), SIMDE_FLOAT32_C(  -641.77), SIMDE_FLOAT32_C(   373.06), SIMDE_FLOAT32_C(     6.77),
        SIMDE_FLOAT32_C(  -945.34), SIMDE_FLOAT32_C(  -198.92), SIMDE_FLOAT32_C(  -247.24), SIMDE_FLOAT32_C(   305.69),
        SIMDE_FLOAT32_C(   402.52), SIMDE_FLOAT32_C(   154.42), SIMDE_FLOAT32_C(   194.06), SIMDE_FLOAT32_C(   222.88),
        SIMDE_FLOAT32_C(   154.10), SIMDE_FLOAT32_C(   856.97), SIMDE_FLOAT32_C(  -340.32), SIMDE_FLOAT32_C(   737.54) },
       INT32_C(         243),
      { SIMDE_FLOAT32_C(   626.60), SIMDE_FLOAT32_C(  -641.77), SIMDE_FLOAT32_C(   373.06), SIMDE_FLOAT32_C(     6.77),
        SIMDE_FLOAT32_C(  -945.34), SIMDE_FLOAT32_C(  -198.92), SIMDE_FLOAT32_C(  -247.24), SIMDE_FLOAT32_C(   305.69),
        SIMDE_FLOAT32_C(   402.52), SIMDE_FLOAT32_C(   154.42), SIMDE_FLOAT32_C(   194.06), SIMDE_FLOAT32_C(   222.88),
        SIMDE_FLOAT32_C(   154.10), SIMDE_FLOAT32_C(   856.97), SIMDE_FLOAT32_C(  -340.32), SIMDE_FLOAT32_C(   737.54) } },
    { { SIMDE_FLOAT32_C(  -254.45), SIMDE_FLOAT32_C(  -845.35), SIMDE_FLOAT32_C(  -257.22), SIMDE_FLOAT32_C(  -144.12),
        SIMDE_FLOAT32_C(  -636.75), SIMDE_FLOAT32_C(   395.10), SIMDE_FLOAT32_C(   803.59), SIMDE_FLOAT32_C(   336.08),
        SIMDE_FLOAT32_C(  -647.26), SIMDE_FLOAT32_C(   377.48), SIMDE_FLOAT32_C(   719.28), SIMDE_FLOAT32_C(   766.61),
        SIMDE_FLOAT32_C(   898.72), SIMDE_FLOAT32_C(   345.88), SIMDE_FLOAT32_C(  -875.16), SIMDE_FLOAT32_C(   271.78) },
       INT32_C(         116),
      { SIMDE_FLOAT32_C(  -254.45), SIMDE_FLOAT32_C(  -845.35), SIMDE_FLOAT32_C(  -257.22), SIMDE_FLOAT32_C(  -144.12),
        SIMDE_FLOAT32_C(  -636.75), SIMDE_FLOAT32_C(   395.10), SIMDE_FLOAT32_C(   803.59), SIMDE_FLOAT32_C(   336.08),
        SIMDE_FLOAT32_C(  -647.26), SIMDE_FLOAT32_C(   377.48), SIMDE_FLOAT32_C(   719.28), SIMDE_FLOAT32_C(   766.61),
        SIMDE_FLOAT32_C(   898.72), SIMDE_FLOAT32_C(   345.88), SIMDE_FLOAT32_C(  -875.16), SIMDE_FLOAT32_C(   271.78) } },
    { { SIMDE_FLOAT32_C(  -927.14),      SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(   485.19), SIMDE_FLOAT32_C(   475.38),
        SIMDE_FLOAT32_C(  -740.16), SIMDE_FLOAT32_C(  -320.75), SIMDE_FLOAT32_C(  -301.74), SIMDE_FLOAT32_C(   413.93),
        SIMDE_FLOAT32_C(  -463.77), SIMDE_FLOAT32_C(   357.95), SIMDE_FLOAT32_C(   151.48), SIMDE_FLOAT32_C(  -280.14),
        SIMDE_FLOAT32_C(   702.19), SIMDE_FLOAT32_C(   897.02), SIMDE_FLOAT32_C(  -125.49), SIMDE_FLOAT32_C(  -555.02) },
       INT32_C(          64),
      { SIMDE_FLOAT32_C(  -927.12),      SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(   485.19), SIMDE_FLOAT32_C(   475.38),
        SIMDE_FLOAT32_C(  -740.19), SIMDE_FLOAT32_C(  -320.75), SIMDE_FLOAT32_C(  -301.75), SIMDE_FLOAT32_C(   413.94),
        SIMDE_FLOAT32_C(  -463.75), SIMDE_FLOAT32_C(   357.94), SIMDE_FLOAT32_C(   151.50), SIMDE_FLOAT32_C(  -280.12),
        SIMDE_FLOAT32_C(   702.19), SIMDE_FLOAT32_C(   897.00), SIMDE_FLOAT32_C(  -125.50), SIMDE_FLOAT32_C(  -555.00) } },
    { { SIMDE_FLOAT32_C(  -426.16),      SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(   933.98), SIMDE_FLOAT32_C(  -706.88),
        SIMDE_FLOAT32_C(   959.43), SIMDE_FLOAT32_C(   832.70), SIMDE_FLOAT32_C(   639.00), SIMDE_FLOAT32_C(  -915.73),
        SIMDE_FLOAT32_C(   104.47), SIMDE_FLOAT32_C(   991.65), SIMDE_FLOAT32_C(  -736.23), SIMDE_FLOAT32_C(   177.33),
        SIMDE_FLOAT32_C(    97.07), SIMDE_FLOAT32_C(   748.97), SIMDE_FLOAT32_C(  -347.29), SIMDE_FLOAT32_C(   356.91) },
       INT32_C(         225),
      { SIMDE_FLOAT32_C(  -426.16),      SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(   933.98), SIMDE_FLOAT32_C(  -706.88),
        SIMDE_FLOAT32_C(   959.43), SIMDE_FLOAT32_C(   832.70), SIMDE_FLOAT32_C(   639.00), SIMDE_FLOAT32_C(  -915.73),
        SIMDE_FLOAT32_C(   104.47), SIMDE_FLOAT32_C(   991.65), SIMDE_FLOAT32_C(  -736.23), SIMDE_FLOAT32_C(   177.33),
        SIMDE_FLOAT32_C(    97.07), SIMDE_FLOAT32_C(   748.97), SIMDE_FLOAT32_C(  -347.29), SIMDE_FLOAT32_C(   356.91) } },
    { { SIMDE_FLOAT32_C(  -291.08), SIMDE_FLOAT32_C(   922.32), SIMDE_FLOAT32_C(   684.31), SIMDE_FLOAT32_C(  -588.88),
        SIMDE_FLOAT32_C(   819.34), SIMDE_FLOAT32_C(  -441.18), SIMDE_FLOAT32_C(  -143.90), SIMDE_FLOAT32_C(  -427.75),
        SIMDE_FLOAT32_C(   796.58), SIMDE_FLOAT32_C(  -303.83), SIMDE_FLOAT32_C(   128.74), SIMDE_FLOAT32_C(  -629.58),
        SIMDE_FLOAT32_C(  -111.01), SIMDE_FLOAT32_C(    62.72), SIMDE_FLOAT32_C(  -336.46), SIMDE_FLOAT32_C(  -151.57) },
       INT32_C(          98),
      { SIMDE_FLOAT32_C(  -291.08), SIMDE_FLOAT32_C(   922.33), SIMDE_FLOAT32_C(   684.31), SIMDE_FLOAT32_C(  -588.88),
        SIMDE_FLOAT32_C(   819.34), SIMDE_FLOAT32_C(  -441.17), SIMDE_FLOAT32_C(  -143.89), SIMDE_FLOAT32_C(  -427.75),
        SIMDE_FLOAT32_C(   796.59), SIMDE_FLOAT32_C(  -303.83), SIMDE_FLOAT32_C(   128.75), SIMDE_FLOAT32_C(  -629.58),
        SIMDE_FLOAT32_C(  -111.00), SIMDE_FLOAT32_C(    62.73), SIMDE_FLOAT32_C(  -336.45), SIMDE_FLOAT32_C(  -151.56) } },
  };

  simde__m512 a, r;

  #if !defined(SIMDE_FAST_MATH)
  a = simde_mm512_loadu_ps(test_vec[0].a);
  r = simde_mm512_roundscale_ps(a, INT32_C(          64));
  simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[0].r), 1);

  a = simde_mm512_loadu_ps(test_vec[1].a);
  r = simde_mm512_roundscale_ps(a, INT32_C(           1));
  simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[1].r), 1);
  #endif

  a = simde_mm512_loadu_ps(test_vec[2].a);
  r = simde_mm512_roundscale_ps(a, INT32_C(          98));
  simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[2].r), 1);

  a = simde_mm512_loadu_ps(test_vec[3].a);
  r = simde_mm512_roundscale_ps(a, INT32_C(         243));
  simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[3].r), 1);

  a = simde_mm512_loadu_ps(test_vec[4].a);
  r = simde_mm512_roundscale_ps(a, INT32_C(         116));
  simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[4].r), 1);

  a = simde_mm512_loadu_ps(test_vec[5].a);
  r = simde_mm512_roundscale_ps(a, INT32_C(          64));
  simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[5].r), 1);

  a = simde_mm512_loadu_ps(test_vec[6].a);
  r = simde_mm512_roundscale_ps(a, INT32_C(         225));
  simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[6].r), 1);

  a = simde_mm512_loadu_ps(test_vec[7].a);
  r = simde_mm512_roundscale_ps(a, INT32_C(          98));
  simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[7].r), 1);

  return 0;
#else
  fputc('\n', stdout);
  int round_type[5] = {SIMDE_MM_FROUND_TO_NEAREST_INT, SIMDE_MM_FROUND_TO_NEG_INF, SIMDE_MM_FROUND_TO_POS_INF, SIMDE_MM_FROUND_TO_ZERO, SIMDE_MM_FROUND_CUR_DIRECTION};
  for (int i = 0 ; i < 8 ; i++) {
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
    int imm8 = (((simde_test_codegen_rand() & 15) << 4) | round_type[i % 5]) & 255;
    simde__m512 r;
    SIMDE_CONSTIFY_256_(simde_mm512_roundscale_ps, r, simde_mm512_setzero_ps(), imm8, a);

    simde_test_x86_write_f32x16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_i32(2, imm8, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f32x16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm512_mask_roundscale_ps (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde_float32 src[16];
    const simde__mmask8 k;
    const simde_float32 a[16];
    const int32_t imm8;
    const simde_float32 r[16];
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(  -368.58), SIMDE_FLOAT32_C(   671.26), SIMDE_FLOAT32_C(   276.81), SIMDE_FLOAT32_C(   341.78),
        SIMDE_FLOAT32_C(   140.72), SIMDE_FLOAT32_C(   547.75), SIMDE_FLOAT32_C(   178.73), SIMDE_FLOAT32_C(   861.61),
        SIMDE_FLOAT32_C(    56.36), SIMDE_FLOAT32_C(  -214.56), SIMDE_FLOAT32_C(   152.99), SIMDE_FLOAT32_C(   284.00),
        SIMDE_FLOAT32_C(  -923.24), SIMDE_FLOAT32_C(  -638.78), SIMDE_FLOAT32_C(    48.36), SIMDE_FLOAT32_C(   907.10) },
      UINT8_C(140),
      { SIMDE_FLOAT32_C(  -196.81),      SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(  -866.78), SIMDE_FLOAT32_C(   796.60),
        SIMDE_FLOAT32_C(   299.16), SIMDE_FLOAT32_C(  -670.80), SIMDE_FLOAT32_C(  -931.45), SIMDE_FLOAT32_C(   327.80),
        SIMDE_FLOAT32_C(  -798.64), SIMDE_FLOAT32_C(  -170.99), SIMDE_FLOAT32_C(    72.32), SIMDE_FLOAT32_C(  -553.91),
        SIMDE_FLOAT32_C(   620.12), SIMDE_FLOAT32_C(   439.08), SIMDE_FLOAT32_C(    77.51), SIMDE_FLOAT32_C(   291.38) },
       INT32_C(          16),
      { SIMDE_FLOAT32_C(  -368.58), SIMDE_FLOAT32_C(   671.26), SIMDE_FLOAT32_C(  -867.00), SIMDE_FLOAT32_C(   796.50),
        SIMDE_FLOAT32_C(   140.72), SIMDE_FLOAT32_C(   547.75), SIMDE_FLOAT32_C(   178.73), SIMDE_FLOAT32_C(   328.00),
        SIMDE_FLOAT32_C(    56.36), SIMDE_FLOAT32_C(  -214.56), SIMDE_FLOAT32_C(   152.99), SIMDE_FLOAT32_C(   284.00),
        SIMDE_FLOAT32_C(  -923.24), SIMDE_FLOAT32_C(  -638.78), SIMDE_FLOAT32_C(    48.36), SIMDE_FLOAT32_C(   907.10) } },
    { { SIMDE_FLOAT32_C(   598.02), SIMDE_FLOAT32_C(  -706.29), SIMDE_FLOAT32_C(   320.00), SIMDE_FLOAT32_C(  -616.54),
        SIMDE_FLOAT32_C(   446.70), SIMDE_FLOAT32_C(  -396.00), SIMDE_FLOAT32_C(  -539.78), SIMDE_FLOAT32_C(   807.92),
        SIMDE_FLOAT32_C(   652.36), SIMDE_FLOAT32_C(  -632.67), SIMDE_FLOAT32_C(   781.30), SIMDE_FLOAT32_C(  -544.45),
        SIMDE_FLOAT32_C(  -180.13), SIMDE_FLOAT32_C(   914.53), SIMDE_FLOAT32_C(  -747.85), SIMDE_FLOAT32_C(  -880.97) },
      UINT8_C(192),
      { SIMDE_FLOAT32_C(  -679.30), SIMDE_FLOAT32_C(   446.83), SIMDE_FLOAT32_C(  -554.92), SIMDE_FLOAT32_C(   149.71),
        SIMDE_FLOAT32_C(  -480.86), SIMDE_FLOAT32_C(  -108.82), SIMDE_FLOAT32_C(  -230.17), SIMDE_FLOAT32_C(   958.22),
        SIMDE_FLOAT32_C(   968.69), SIMDE_FLOAT32_C(  -938.79), SIMDE_FLOAT32_C(  -325.89), SIMDE_FLOAT32_C(  -612.02),
        SIMDE_FLOAT32_C(  -506.69), SIMDE_FLOAT32_C(   -62.25), SIMDE_FLOAT32_C(   985.99), SIMDE_FLOAT32_C(  -212.98) },
       INT32_C(          33),
      { SIMDE_FLOAT32_C(   598.02), SIMDE_FLOAT32_C(  -706.29), SIMDE_FLOAT32_C(   320.00), SIMDE_FLOAT32_C(  -616.54),
        SIMDE_FLOAT32_C(   446.70), SIMDE_FLOAT32_C(  -396.00), SIMDE_FLOAT32_C(  -230.25), SIMDE_FLOAT32_C(   958.00),
        SIMDE_FLOAT32_C(   652.36), SIMDE_FLOAT32_C(  -632.67), SIMDE_FLOAT32_C(   781.30), SIMDE_FLOAT32_C(  -544.45),
        SIMDE_FLOAT32_C(  -180.13), SIMDE_FLOAT32_C(   914.53), SIMDE_FLOAT32_C(  -747.85), SIMDE_FLOAT32_C(  -880.97) } },
    { { SIMDE_FLOAT32_C(  -766.27), SIMDE_FLOAT32_C(  -138.25), SIMDE_FLOAT32_C(  -170.32), SIMDE_FLOAT32_C(  -958.35),
        SIMDE_FLOAT32_C(  -485.89), SIMDE_FLOAT32_C(   197.00), SIMDE_FLOAT32_C(   822.95), SIMDE_FLOAT32_C(   -30.33),
        SIMDE_FLOAT32_C(  -983.13), SIMDE_FLOAT32_C(   737.48), SIMDE_FLOAT32_C(   221.82), SIMDE_FLOAT32_C(  -864.10),
        SIMDE_FLOAT32_C(   981.21), SIMDE_FLOAT32_C(   542.52), SIMDE_FLOAT32_C(   582.73), SIMDE_FLOAT32_C(  -573.71) },
      UINT8_C(151),
      { SIMDE_FLOAT32_C(  -898.13),      SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(   462.06), SIMDE_FLOAT32_C(  -939.91),
        SIMDE_FLOAT32_C(   286.15), SIMDE_FLOAT32_C(   523.26), SIMDE_FLOAT32_C(  -265.80), SIMDE_FLOAT32_C(   674.13),
        SIMDE_FLOAT32_C(  -983.43), SIMDE_FLOAT32_C(   671.95), SIMDE_FLOAT32_C(   660.12), SIMDE_FLOAT32_C(  -196.40),
        SIMDE_FLOAT32_C(   929.70), SIMDE_FLOAT32_C(  -970.42), SIMDE_FLOAT32_C(    37.32), SIMDE_FLOAT32_C(  -208.54) },
       INT32_C(          82),
      { SIMDE_FLOAT32_C(  -898.12),      SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(   462.06), SIMDE_FLOAT32_C(  -958.35),
        SIMDE_FLOAT32_C(   286.16), SIMDE_FLOAT32_C(   197.00), SIMDE_FLOAT32_C(   822.95), SIMDE_FLOAT32_C(   674.16),
        SIMDE_FLOAT32_C(  -983.13), SIMDE_FLOAT32_C(   737.48), SIMDE_FLOAT32_C(   221.82), SIMDE_FLOAT32_C(  -864.10),
        SIMDE_FLOAT32_C(   981.21), SIMDE_FLOAT32_C(   542.52), SIMDE_FLOAT32_C(   582.73), SIMDE_FLOAT32_C(  -573.71) } },
    { { SIMDE_FLOAT32_C(   -98.07), SIMDE_FLOAT32_C(  -724.76), SIMDE_FLOAT32_C(  -926.87), SIMDE_FLOAT32_C(  -360.59),
        SIMDE_FLOAT32_C(   497.06), SIMDE_FLOAT32_C(  -790.97), SIMDE_FLOAT32_C(  -379.38), SIMDE_FLOAT32_C(    39.58),
        SIMDE_FLOAT32_C(   791.75), SIMDE_FLOAT32_C(    46.91), SIMDE_FLOAT32_C(   731.81), SIMDE_FLOAT32_C(   893.62),
        SIMDE_FLOAT32_C(  -635.63), SIMDE_FLOAT32_C(   193.87), SIMDE_FLOAT32_C(   953.71), SIMDE_FLOAT32_C(   650.53) },
      UINT8_C(118),
      { SIMDE_FLOAT32_C(  -312.08), SIMDE_FLOAT32_C(   324.66), SIMDE_FLOAT32_C(  -266.29), SIMDE_FLOAT32_C(  -640.13),
        SIMDE_FLOAT32_C(   -15.22), SIMDE_FLOAT32_C(   537.31), SIMDE_FLOAT32_C(  -710.43), SIMDE_FLOAT32_C(    14.36),
        SIMDE_FLOAT32_C(  -425.37), SIMDE_FLOAT32_C(    81.03), SIMDE_FLOAT32_C(   873.61), SIMDE_FLOAT32_C(   653.60),
        SIMDE_FLOAT32_C(  -613.39), SIMDE_FLOAT32_C(   929.87), SIMDE_FLOAT32_C(  -444.47), SIMDE_FLOAT32_C(  -338.15) },
       INT32_C(         211),
      { SIMDE_FLOAT32_C(   -98.07), SIMDE_FLOAT32_C(   324.66), SIMDE_FLOAT32_C(  -266.29), SIMDE_FLOAT32_C(  -360.59),
        SIMDE_FLOAT32_C(   -15.22), SIMDE_FLOAT32_C(   537.31), SIMDE_FLOAT32_C(  -710.43), SIMDE_FLOAT32_C(    39.58),
        SIMDE_FLOAT32_C(   791.75), SIMDE_FLOAT32_C(    46.91), SIMDE_FLOAT32_C(   731.81), SIMDE_FLOAT32_C(   893.62),
        SIMDE_FLOAT32_C(  -635.63), SIMDE_FLOAT32_C(   193.87), SIMDE_FLOAT32_C(   953.71), SIMDE_FLOAT32_C(   650.53) } },
    { { SIMDE_FLOAT32_C(  -841.09), SIMDE_FLOAT32_C(  -787.98), SIMDE_FLOAT32_C(   815.55), SIMDE_FLOAT32_C(   198.50),
        SIMDE_FLOAT32_C(  -996.22), SIMDE_FLOAT32_C(  -137.54), SIMDE_FLOAT32_C(   -69.69), SIMDE_FLOAT32_C(   897.40),
        SIMDE_FLOAT32_C(   226.83), SIMDE_FLOAT32_C(  -875.82), SIMDE_FLOAT32_C(   851.11), SIMDE_FLOAT32_C(  -122.64),
        SIMDE_FLOAT32_C(  -158.69), SIMDE_FLOAT32_C(  -460.97), SIMDE_FLOAT32_C(  -797.98), SIMDE_FLOAT32_C(   575.02) },
      UINT8_C( 79),
      { SIMDE_FLOAT32_C(   186.80), SIMDE_FLOAT32_C(   112.33), SIMDE_FLOAT32_C(   188.47), SIMDE_FLOAT32_C(  -798.85),
        SIMDE_FLOAT32_C(   686.96), SIMDE_FLOAT32_C(  -730.49), SIMDE_FLOAT32_C(  -925.24), SIMDE_FLOAT32_C(   340.56),
        SIMDE_FLOAT32_C(  -343.89), SIMDE_FLOAT32_C(  -995.37), SIMDE_FLOAT32_C(   896.09), SIMDE_FLOAT32_C(   317.96),
        SIMDE_FLOAT32_C(  -992.38), SIMDE_FLOAT32_C(    91.03), SIMDE_FLOAT32_C(   476.88), SIMDE_FLOAT32_C(  -780.35) },
       INT32_C(          84),
      { SIMDE_FLOAT32_C(   186.81), SIMDE_FLOAT32_C(   112.34), SIMDE_FLOAT32_C(   188.47), SIMDE_FLOAT32_C(  -798.84),
        SIMDE_FLOAT32_C(  -996.22), SIMDE_FLOAT32_C(  -137.54), SIMDE_FLOAT32_C(  -925.25), SIMDE_FLOAT32_C(   897.40),
        SIMDE_FLOAT32_C(   226.83), SIMDE_FLOAT32_C(  -875.82), SIMDE_FLOAT32_C(   851.11), SIMDE_FLOAT32_C(  -122.64),
        SIMDE_FLOAT32_C(  -158.69), SIMDE_FLOAT32_C(  -460.97), SIMDE_FLOAT32_C(  -797.98), SIMDE_FLOAT32_C(   575.02) } },
    { { SIMDE_FLOAT32_C(  -776.58), SIMDE_FLOAT32_C(   769.03), SIMDE_FLOAT32_C(   605.68), SIMDE_FLOAT32_C(  -879.18),
        SIMDE_FLOAT32_C(    -4.13), SIMDE_FLOAT32_C(   729.87), SIMDE_FLOAT32_C(   971.94), SIMDE_FLOAT32_C(   873.22),
        SIMDE_FLOAT32_C(  -428.82), SIMDE_FLOAT32_C(  -489.03), SIMDE_FLOAT32_C(  -924.76), SIMDE_FLOAT32_C(  -853.80),
        SIMDE_FLOAT32_C(   409.86), SIMDE_FLOAT32_C(   262.04), SIMDE_FLOAT32_C(   258.53), SIMDE_FLOAT32_C(  -401.66) },
      UINT8_C( 76),
      { SIMDE_FLOAT32_C(   -54.51), SIMDE_FLOAT32_C(  -132.16), SIMDE_FLOAT32_C(   537.95), SIMDE_FLOAT32_C(  -713.94),
        SIMDE_FLOAT32_C(   523.96), SIMDE_FLOAT32_C(   542.57), SIMDE_FLOAT32_C(  -817.85), SIMDE_FLOAT32_C(  -158.08),
        SIMDE_FLOAT32_C(   550.19), SIMDE_FLOAT32_C(   273.18), SIMDE_FLOAT32_C(  -681.20), SIMDE_FLOAT32_C(   769.84),
        SIMDE_FLOAT32_C(  -820.25), SIMDE_FLOAT32_C(    -5.83), SIMDE_FLOAT32_C(   993.26), SIMDE_FLOAT32_C(   948.79) },
       INT32_C(         144),
      { SIMDE_FLOAT32_C(  -776.58), SIMDE_FLOAT32_C(   769.03), SIMDE_FLOAT32_C(   537.95), SIMDE_FLOAT32_C(  -713.94),
        SIMDE_FLOAT32_C(    -4.13), SIMDE_FLOAT32_C(   729.87), SIMDE_FLOAT32_C(  -817.85), SIMDE_FLOAT32_C(   873.22),
        SIMDE_FLOAT32_C(  -428.82), SIMDE_FLOAT32_C(  -489.03), SIMDE_FLOAT32_C(  -924.76), SIMDE_FLOAT32_C(  -853.80),
        SIMDE_FLOAT32_C(   409.86), SIMDE_FLOAT32_C(   262.04), SIMDE_FLOAT32_C(   258.53), SIMDE_FLOAT32_C(  -401.66) } },
    { { SIMDE_FLOAT32_C(   -55.35), SIMDE_FLOAT32_C(  -670.28), SIMDE_FLOAT32_C(  -913.98), SIMDE_FLOAT32_C(  -182.13),
        SIMDE_FLOAT32_C(   -99.10), SIMDE_FLOAT32_C(  -403.01), SIMDE_FLOAT32_C(  -106.89), SIMDE_FLOAT32_C(    47.11),
        SIMDE_FLOAT32_C(  -993.15), SIMDE_FLOAT32_C(  -844.85), SIMDE_FLOAT32_C(  -694.36), SIMDE_FLOAT32_C(  -394.81),
        SIMDE_FLOAT32_C(   618.34), SIMDE_FLOAT32_C(   251.14), SIMDE_FLOAT32_C(   473.03), SIMDE_FLOAT32_C(   156.28) },
      UINT8_C( 92),
      { SIMDE_FLOAT32_C(    -3.01),     -SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(   719.34), SIMDE_FLOAT32_C(   838.91),
        SIMDE_FLOAT32_C(  -750.95), SIMDE_FLOAT32_C(    -7.48), SIMDE_FLOAT32_C(  -842.29), SIMDE_FLOAT32_C(  -981.11),
        SIMDE_FLOAT32_C(   172.27), SIMDE_FLOAT32_C(   151.88), SIMDE_FLOAT32_C(  -987.85), SIMDE_FLOAT32_C(   121.05),
        SIMDE_FLOAT32_C(   751.73), SIMDE_FLOAT32_C(  -873.77), SIMDE_FLOAT32_C(  -934.29), SIMDE_FLOAT32_C(  -918.54) },
       INT32_C(          17),
      { SIMDE_FLOAT32_C(   -55.35), SIMDE_FLOAT32_C(  -670.28), SIMDE_FLOAT32_C(   719.00), SIMDE_FLOAT32_C(   838.50),
        SIMDE_FLOAT32_C(  -751.00), SIMDE_FLOAT32_C(  -403.01), SIMDE_FLOAT32_C(  -842.50), SIMDE_FLOAT32_C(    47.11),
        SIMDE_FLOAT32_C(  -993.15), SIMDE_FLOAT32_C(  -844.85), SIMDE_FLOAT32_C(  -694.36), SIMDE_FLOAT32_C(  -394.81),
        SIMDE_FLOAT32_C(   618.34), SIMDE_FLOAT32_C(   251.14), SIMDE_FLOAT32_C(   473.03), SIMDE_FLOAT32_C(   156.28) } },
    { { SIMDE_FLOAT32_C(   776.69), SIMDE_FLOAT32_C(  -970.53), SIMDE_FLOAT32_C(  -183.90), SIMDE_FLOAT32_C(   931.85),
        SIMDE_FLOAT32_C(  -664.89), SIMDE_FLOAT32_C(   421.29), SIMDE_FLOAT32_C(   550.18), SIMDE_FLOAT32_C(   586.24),
        SIMDE_FLOAT32_C(  -105.68), SIMDE_FLOAT32_C(  -293.53), SIMDE_FLOAT32_C(   123.44), SIMDE_FLOAT32_C(   891.31),
        SIMDE_FLOAT32_C(   405.32), SIMDE_FLOAT32_C(  -157.22), SIMDE_FLOAT32_C(   730.22), SIMDE_FLOAT32_C(   654.37) },
      UINT8_C(159),
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   673.25), SIMDE_FLOAT32_C(     7.57), SIMDE_FLOAT32_C(    39.80),
        SIMDE_FLOAT32_C(   685.40), SIMDE_FLOAT32_C(  -871.38), SIMDE_FLOAT32_C(  -208.47), SIMDE_FLOAT32_C(   811.64),
        SIMDE_FLOAT32_C(  -805.67), SIMDE_FLOAT32_C(  -127.01), SIMDE_FLOAT32_C(  -976.11), SIMDE_FLOAT32_C(    77.91),
        SIMDE_FLOAT32_C(   855.35), SIMDE_FLOAT32_C(  -166.86), SIMDE_FLOAT32_C(  -145.40), SIMDE_FLOAT32_C(   884.81) },
       INT32_C(         242),
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   673.25), SIMDE_FLOAT32_C(     7.57), SIMDE_FLOAT32_C(    39.80),
        SIMDE_FLOAT32_C(   685.40), SIMDE_FLOAT32_C(   421.29), SIMDE_FLOAT32_C(   550.18), SIMDE_FLOAT32_C(   811.64),
        SIMDE_FLOAT32_C(  -105.68), SIMDE_FLOAT32_C(  -293.53), SIMDE_FLOAT32_C(   123.44), SIMDE_FLOAT32_C(   891.31),
        SIMDE_FLOAT32_C(   405.32), SIMDE_FLOAT32_C(  -157.22), SIMDE_FLOAT32_C(   730.22), SIMDE_FLOAT32_C(   654.37) } },
  };

  simde__m512 src, a, r;

  src = simde_mm512_loadu_ps(test_vec[0].src);
  a = simde_mm512_loadu_ps(test_vec[0].a);
  r = simde_mm512_mask_roundscale_ps(src, test_vec[0].k, a, INT32_C(          16));
  simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[0].r), 1);

  src = simde_mm512_loadu_ps(test_vec[1].src);
  a = simde_mm512_loadu_ps(test_vec[1].a);
  r = simde_mm512_mask_roundscale_ps(src, test_vec[1].k, a, INT32_C(          33));
  simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[1].r), 1);

  src = simde_mm512_loadu_ps(test_vec[2].src);
  a = simde_mm512_loadu_ps(test_vec[2].a);
  r = simde_mm512_mask_roundscale_ps(src, test_vec[2].k, a, INT32_C(          82));
  simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[2].r), 1);

  src = simde_mm512_loadu_ps(test_vec[3].src);
  a = simde_mm512_loadu_ps(test_vec[3].a);
  r = simde_mm512_mask_roundscale_ps(src, test_vec[3].k, a, INT32_C(         211));
  simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[3].r), 1);

  src = simde_mm512_loadu_ps(test_vec[4].src);
  a = simde_mm512_loadu_ps(test_vec[4].a);
  r = simde_mm512_mask_roundscale_ps(src, test_vec[4].k, a, INT32_C(          84));
  simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[4].r), 1);

  src = simde_mm512_loadu_ps(test_vec[5].src);
  a = simde_mm512_loadu_ps(test_vec[5].a);
  r = simde_mm512_mask_roundscale_ps(src, test_vec[5].k, a, INT32_C(         144));
  simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[5].r), 1);

  src = simde_mm512_loadu_ps(test_vec[6].src);
  a = simde_mm512_loadu_ps(test_vec[6].a);
  r = simde_mm512_mask_roundscale_ps(src, test_vec[6].k, a, INT32_C(          17));
  simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[6].r), 1);

  #if !defined(SIMDE_FAST_MATH)
  src = simde_mm512_loadu_ps(test_vec[7].src);
  a = simde_mm512_loadu_ps(test_vec[7].a);
  r = simde_mm512_mask_roundscale_ps(src, test_vec[7].k, a, INT32_C(         242));
  simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[7].r), 1);
  #endif

  return 0;
#else
  fputc('\n', stdout);
  int round_type[5] = {SIMDE_MM_FROUND_TO_NEAREST_INT, SIMDE_MM_FROUND_TO_NEG_INF, SIMDE_MM_FROUND_TO_POS_INF, SIMDE_MM_FROUND_TO_ZERO, SIMDE_MM_FROUND_CUR_DIRECTION};
  for (int i = 0 ; i < 8 ; i++) {
    simde__m512 src = simde_test_x86_random_f32x16(SIMDE_FLOAT32_C(-1000.0), SIMDE_FLOAT32_C(1000.0));
    simde__mmask8 k = simde_test_x86_random_mmask8();
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
    int imm8 = (((simde_test_codegen_rand() & 15) << 4) | round_type[i % 5]) & 255;
    simde__m512 r;
    SIMDE_CONSTIFY_256_(simde_mm512_mask_roundscale_ps, r, simde_mm512_setzero_ps(), imm8, src, k, a);

    simde_test_x86_write_f32x16(2, src, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f32x16(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, imm8, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f32x16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm512_maskz_roundscale_ps (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask8 k;
    const simde_float32 a[16];
    const int32_t imm8;
    const simde_float32 r[16];
  } test_vec[] = {
    { UINT8_C(234),
      { SIMDE_FLOAT32_C(   -13.26), SIMDE_FLOAT32_C(   198.00), SIMDE_FLOAT32_C(  -516.28), SIMDE_FLOAT32_C(  -586.06),
        SIMDE_FLOAT32_C(  -522.32), SIMDE_FLOAT32_C(  -834.30), SIMDE_FLOAT32_C(  -963.78), SIMDE_FLOAT32_C(   129.47),
        SIMDE_FLOAT32_C(   364.21), SIMDE_FLOAT32_C(   -20.29), SIMDE_FLOAT32_C(   293.22), SIMDE_FLOAT32_C(  -223.95),
        SIMDE_FLOAT32_C(  -730.48), SIMDE_FLOAT32_C(  -697.92), SIMDE_FLOAT32_C(   411.90), SIMDE_FLOAT32_C(  -489.41) },
       INT32_C(         208),
      { SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   198.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -586.06),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -834.30), SIMDE_FLOAT32_C(  -963.78), SIMDE_FLOAT32_C(   129.47),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00) } },
    { UINT8_C( 69),
      { SIMDE_FLOAT32_C(   771.32), SIMDE_FLOAT32_C(   547.03), SIMDE_FLOAT32_C(  -839.90), SIMDE_FLOAT32_C(  -855.36),
        SIMDE_FLOAT32_C(  -639.47), SIMDE_FLOAT32_C(  -711.44), SIMDE_FLOAT32_C(   257.81), SIMDE_FLOAT32_C(  -622.92),
        SIMDE_FLOAT32_C(    48.32), SIMDE_FLOAT32_C(    61.28), SIMDE_FLOAT32_C(  -328.47), SIMDE_FLOAT32_C(   892.68),
        SIMDE_FLOAT32_C(  -951.98), SIMDE_FLOAT32_C(   869.52), SIMDE_FLOAT32_C(  -623.59), SIMDE_FLOAT32_C(  -538.04) },
       INT32_C(         241),
      { SIMDE_FLOAT32_C(   771.32), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -839.90), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   257.81), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00) } },
    { UINT8_C(219),
      { SIMDE_FLOAT32_C(   476.68),      SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(   477.90), SIMDE_FLOAT32_C(  -230.10),
        SIMDE_FLOAT32_C(  -317.64), SIMDE_FLOAT32_C(   747.41), SIMDE_FLOAT32_C(    71.98), SIMDE_FLOAT32_C(  -905.73),
        SIMDE_FLOAT32_C(  -741.99), SIMDE_FLOAT32_C(  -985.21), SIMDE_FLOAT32_C(  -171.21), SIMDE_FLOAT32_C(   842.79),
        SIMDE_FLOAT32_C(   786.11), SIMDE_FLOAT32_C(  -624.19), SIMDE_FLOAT32_C(  -997.11), SIMDE_FLOAT32_C(   930.75) },
       INT32_C(         114),
      { SIMDE_FLOAT32_C(   476.69),      SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -230.09),
        SIMDE_FLOAT32_C(  -317.63), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(    71.98), SIMDE_FLOAT32_C(  -905.73),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00) } },
    { UINT8_C(247),
      { SIMDE_FLOAT32_C(  -750.15),      SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(   232.46), SIMDE_FLOAT32_C(  -702.13),
        SIMDE_FLOAT32_C(   654.48), SIMDE_FLOAT32_C(   608.87), SIMDE_FLOAT32_C(  -240.17), SIMDE_FLOAT32_C(  -998.32),
        SIMDE_FLOAT32_C(  -849.02), SIMDE_FLOAT32_C(   258.02), SIMDE_FLOAT32_C(   478.36), SIMDE_FLOAT32_C(  -942.70),
        SIMDE_FLOAT32_C(  -264.09), SIMDE_FLOAT32_C(  -751.74), SIMDE_FLOAT32_C(  -260.33), SIMDE_FLOAT32_C(  -516.68) },
       INT32_C(          99),
      { SIMDE_FLOAT32_C(  -750.14),      SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(   232.45), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(   654.47), SIMDE_FLOAT32_C(   608.86), SIMDE_FLOAT32_C(  -240.16), SIMDE_FLOAT32_C(  -998.31),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00) } },
    { UINT8_C(148),
      { SIMDE_FLOAT32_C(  -415.88), SIMDE_FLOAT32_C(   121.14), SIMDE_FLOAT32_C(  -961.46), SIMDE_FLOAT32_C(  -412.98),
        SIMDE_FLOAT32_C(    51.89), SIMDE_FLOAT32_C(  -225.11), SIMDE_FLOAT32_C(  -121.53), SIMDE_FLOAT32_C(  -759.54),
        SIMDE_FLOAT32_C(   888.31), SIMDE_FLOAT32_C(  -781.75), SIMDE_FLOAT32_C(  -509.69), SIMDE_FLOAT32_C(   673.26),
        SIMDE_FLOAT32_C(   450.72), SIMDE_FLOAT32_C(  -211.82), SIMDE_FLOAT32_C(   327.74), SIMDE_FLOAT32_C(    59.59) },
       INT32_C(         116),
      { SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -961.46), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(    51.89), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -759.54),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00) } },
    { UINT8_C(  6),
      { SIMDE_FLOAT32_C(  -193.97), SIMDE_FLOAT32_C(  -192.22), SIMDE_FLOAT32_C(   267.87), SIMDE_FLOAT32_C(   541.94),
        SIMDE_FLOAT32_C(    56.04), SIMDE_FLOAT32_C(  -992.46), SIMDE_FLOAT32_C(  -974.74), SIMDE_FLOAT32_C(  -623.72),
        SIMDE_FLOAT32_C(  -158.53), SIMDE_FLOAT32_C(  -233.41), SIMDE_FLOAT32_C(   711.32), SIMDE_FLOAT32_C(  -495.81),
        SIMDE_FLOAT32_C(   350.72), SIMDE_FLOAT32_C(  -167.54), SIMDE_FLOAT32_C(  -457.27), SIMDE_FLOAT32_C(   937.73) },
       INT32_C(         128),
      { SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -192.22), SIMDE_FLOAT32_C(   267.87), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00) } },
    { UINT8_C( 28),
      { SIMDE_FLOAT32_C(  -875.18),     -SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(    34.45), SIMDE_FLOAT32_C(  -384.88),
        SIMDE_FLOAT32_C(  -120.81), SIMDE_FLOAT32_C(  -514.83), SIMDE_FLOAT32_C(   403.30), SIMDE_FLOAT32_C(  -793.07),
        SIMDE_FLOAT32_C(   544.76), SIMDE_FLOAT32_C(   -48.68), SIMDE_FLOAT32_C(   536.35), SIMDE_FLOAT32_C(  -244.67),
        SIMDE_FLOAT32_C(   757.35), SIMDE_FLOAT32_C(  -655.86), SIMDE_FLOAT32_C(  -976.80), SIMDE_FLOAT32_C(   299.28) },
       INT32_C(          97),
      { SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(    34.44), SIMDE_FLOAT32_C(  -384.89),
        SIMDE_FLOAT32_C(  -120.81), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00) } },
    { UINT8_C( 38),
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   487.78), SIMDE_FLOAT32_C(   376.40), SIMDE_FLOAT32_C(   441.86),
        SIMDE_FLOAT32_C(  -679.76), SIMDE_FLOAT32_C(   919.14), SIMDE_FLOAT32_C(   379.59), SIMDE_FLOAT32_C(  -795.40),
        SIMDE_FLOAT32_C(   236.75), SIMDE_FLOAT32_C(  -804.21), SIMDE_FLOAT32_C(  -670.58), SIMDE_FLOAT32_C(  -557.32),
        SIMDE_FLOAT32_C(   230.25), SIMDE_FLOAT32_C(   -55.46), SIMDE_FLOAT32_C(   321.87), SIMDE_FLOAT32_C(   715.42) },
       INT32_C(         146),
      { SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   487.78), SIMDE_FLOAT32_C(   376.40), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   919.14), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00) } },
  };

  simde__m512 a, r;

  a = simde_mm512_loadu_ps(test_vec[0].a);
  r = simde_mm512_maskz_roundscale_ps(test_vec[0].k, a, INT32_C(         208));
  simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[0].r), 1);

  a = simde_mm512_loadu_ps(test_vec[1].a);
  r = simde_mm512_maskz_roundscale_ps(test_vec[1].k, a, INT32_C(         241));
  simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[1].r), 1);

  a = simde_mm512_loadu_ps(test_vec[2].a);
  r = simde_mm512_maskz_roundscale_ps(test_vec[2].k, a, INT32_C(         114));
  simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[2].r), 1);

  a = simde_mm512_loadu_ps(test_vec[3].a);
  r = simde_mm512_maskz_roundscale_ps(test_vec[3].k, a, INT32_C(          99));
  simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[3].r), 1);

  a = simde_mm512_loadu_ps(test_vec[4].a);
  r = simde_mm512_maskz_roundscale_ps(test_vec[4].k, a, INT32_C(         116));
  simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[4].r), 1);

  a = simde_mm512_loadu_ps(test_vec[5].a);
  r = simde_mm512_maskz_roundscale_ps(test_vec[5].k, a, INT32_C(         128));
  simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[5].r), 1);

  a = simde_mm512_loadu_ps(test_vec[6].a);
  r = simde_mm512_maskz_roundscale_ps(test_vec[6].k, a, INT32_C(          97));
  simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[6].r), 1);

  a = simde_mm512_loadu_ps(test_vec[7].a);
  r = simde_mm512_maskz_roundscale_ps(test_vec[7].k, a, INT32_C(         146));
  simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[7].r), 1);

  return 0;
#else
  fputc('\n', stdout);
  int round_type[5] = {SIMDE_MM_FROUND_TO_NEAREST_INT, SIMDE_MM_FROUND_TO_NEG_INF, SIMDE_MM_FROUND_TO_POS_INF, SIMDE_MM_FROUND_TO_ZERO, SIMDE_MM_FROUND_CUR_DIRECTION};
  for (int i = 0 ; i < 8 ; i++) {
    simde__mmask8 k = simde_test_x86_random_mmask8();
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
    int imm8 = (((simde_test_codegen_rand() & 15) << 4) | round_type[i % 5]) & 255;
    simde__m512 r;
    SIMDE_CONSTIFY_256_(simde_mm512_maskz_roundscale_ps, r, simde_mm512_setzero_ps(), imm8, k, a);

    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_f32x16(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, imm8, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f32x16(2, r, SIMDE_TEST_VEC_POS_LAST);
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

  #if !defined(SIMDE_FAST_MATH)
  a = simde_mm_loadu_pd(test_vec[1].a);
  r = simde_mm_roundscale_pd(a, INT32_C(          16));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[1].r), 1);

  a = simde_mm_loadu_pd(test_vec[2].a);
  r = simde_mm_roundscale_pd(a, INT32_C(          32));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[2].r), 1);
  #endif

  a = simde_mm_loadu_pd(test_vec[3].a);
  r = simde_mm_roundscale_pd(a, INT32_C(          48));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[3].r), 1);

  #if !defined(SIMDE_FAST_MATH)
  a = simde_mm_loadu_pd(test_vec[4].a);
  r = simde_mm_roundscale_pd(a, INT32_C(          64));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[4].r), 1);

  a = simde_mm_loadu_pd(test_vec[5].a);
  r = simde_mm_roundscale_pd(a, INT32_C(          80));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[5].r), 1);
  #endif

  a = simde_mm_loadu_pd(test_vec[6].a);
  r = simde_mm_roundscale_pd(a, INT32_C(          96));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[6].r), 1);

  a = simde_mm_loadu_pd(test_vec[7].a);
  r = simde_mm_roundscale_pd(a, INT32_C(         112));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[7].r), 1);

  a = simde_mm_loadu_pd(test_vec[8].a);
  r = simde_mm_roundscale_pd(a, INT32_C(         128));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[8].r), 1);

  #if !defined(SIMDE_FAST_MATH)
  a = simde_mm_loadu_pd(test_vec[9].a);
  r = simde_mm_roundscale_pd(a, INT32_C(         144));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[9].r), 1);
  #endif

  a = simde_mm_loadu_pd(test_vec[10].a);
  r = simde_mm_roundscale_pd(a, INT32_C(         160));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[10].r), 1);

  #if !defined(SIMDE_FAST_MATH)
  a = simde_mm_loadu_pd(test_vec[11].a);
  r = simde_mm_roundscale_pd(a, INT32_C(         176));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[11].r), 1);
  #endif

  a = simde_mm_loadu_pd(test_vec[12].a);
  r = simde_mm_roundscale_pd(a, INT32_C(         192));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[12].r), 1);

  #if !defined(SIMDE_FAST_MATH)
  a = simde_mm_loadu_pd(test_vec[13].a);
  r = simde_mm_roundscale_pd(a, INT32_C(         208));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[13].r), 1);
  #endif

  a = simde_mm_loadu_pd(test_vec[14].a);
  r = simde_mm_roundscale_pd(a, INT32_C(         224));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[14].r), 1);

  #if !defined(SIMDE_FAST_MATH)
  a = simde_mm_loadu_pd(test_vec[15].a);
  r = simde_mm_roundscale_pd(a, INT32_C(         240));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[15].r), 1);
  #endif

  a = simde_mm_loadu_pd(test_vec[16].a);
  r = simde_mm_roundscale_pd(a, INT32_C(           1));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[16].r), 1);

  #if !defined(SIMDE_FAST_MATH)
  a = simde_mm_loadu_pd(test_vec[17].a);
  r = simde_mm_roundscale_pd(a, INT32_C(          17));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[17].r), 1);
  #endif

  a = simde_mm_loadu_pd(test_vec[18].a);
  r = simde_mm_roundscale_pd(a, INT32_C(          33));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[18].r), 1);

  #if !defined(SIMDE_FAST_MATH)
  a = simde_mm_loadu_pd(test_vec[19].a);
  r = simde_mm_roundscale_pd(a, INT32_C(          49));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[19].r), 1);
  #endif

  a = simde_mm_loadu_pd(test_vec[20].a);
  r = simde_mm_roundscale_pd(a, INT32_C(          65));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[20].r), 1);

  #if !defined(SIMDE_FAST_MATH)
  a = simde_mm_loadu_pd(test_vec[21].a);
  r = simde_mm_roundscale_pd(a, INT32_C(          81));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[21].r), 1);

  a = simde_mm_loadu_pd(test_vec[22].a);
  r = simde_mm_roundscale_pd(a, INT32_C(          97));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[22].r), 1);

  a = simde_mm_loadu_pd(test_vec[23].a);
  r = simde_mm_roundscale_pd(a, INT32_C(         113));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[23].r), 1);
  #endif

  a = simde_mm_loadu_pd(test_vec[24].a);
  r = simde_mm_roundscale_pd(a, INT32_C(         129));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[24].r), 1);

  a = simde_mm_loadu_pd(test_vec[25].a);
  r = simde_mm_roundscale_pd(a, INT32_C(         145));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[25].r), 1);

  a = simde_mm_loadu_pd(test_vec[26].a);
  r = simde_mm_roundscale_pd(a, INT32_C(         161));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[26].r), 1);

  #if !defined(SIMDE_FAST_MATH)
  a = simde_mm_loadu_pd(test_vec[27].a);
  r = simde_mm_roundscale_pd(a, INT32_C(         177));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[27].r), 1);
  #endif

  a = simde_mm_loadu_pd(test_vec[28].a);
  r = simde_mm_roundscale_pd(a, INT32_C(         193));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[28].r), 1);

  a = simde_mm_loadu_pd(test_vec[29].a);
  r = simde_mm_roundscale_pd(a, INT32_C(         209));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[29].r), 1);

  a = simde_mm_loadu_pd(test_vec[30].a);
  r = simde_mm_roundscale_pd(a, INT32_C(         225));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[30].r), 1);

  #if !defined(SIMDE_FAST_MATH)
  a = simde_mm_loadu_pd(test_vec[31].a);
  r = simde_mm_roundscale_pd(a, INT32_C(         241));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[31].r), 1);
  #endif

  a = simde_mm_loadu_pd(test_vec[32].a);
  r = simde_mm_roundscale_pd(a, INT32_C(           2));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[32].r), 1);

  a = simde_mm_loadu_pd(test_vec[33].a);
  r = simde_mm_roundscale_pd(a, INT32_C(          18));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[33].r), 1);

  #if !defined(SIMDE_FAST_MATH)
  a = simde_mm_loadu_pd(test_vec[34].a);
  r = simde_mm_roundscale_pd(a, INT32_C(          34));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[34].r), 1);
  #endif

  a = simde_mm_loadu_pd(test_vec[35].a);
  r = simde_mm_roundscale_pd(a, INT32_C(          50));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[35].r), 1);

  a = simde_mm_loadu_pd(test_vec[36].a);
  r = simde_mm_roundscale_pd(a, INT32_C(          66));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[36].r), 1);

  #if !defined(SIMDE_FAST_MATH)
  a = simde_mm_loadu_pd(test_vec[37].a);
  r = simde_mm_roundscale_pd(a, INT32_C(          82));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[37].r), 1);
  #endif

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

  #if !defined(SIMDE_FAST_MATH)
  a = simde_mm_loadu_pd(test_vec[45].a);
  r = simde_mm_roundscale_pd(a, INT32_C(         210));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[45].r), 1);

  a = simde_mm_loadu_pd(test_vec[46].a);
  r = simde_mm_roundscale_pd(a, INT32_C(         226));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[46].r), 1);
  #endif

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

  #if !defined(SIMDE_FAST_MATH)
  a = simde_mm_loadu_pd(test_vec[62].a);
  r = simde_mm_roundscale_pd(a, INT32_C(         227));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[62].r), 1);
  #endif

  a = simde_mm_loadu_pd(test_vec[63].a);
  r = simde_mm_roundscale_pd(a, INT32_C(         243));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[63].r), 1);

  #if !defined(SIMDE_FAST_MATH)
  a = simde_mm_loadu_pd(test_vec[64].a);
  r = simde_mm_roundscale_pd(a, INT32_C(           4));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[64].r), 1);
  #endif

  a = simde_mm_loadu_pd(test_vec[65].a);
  r = simde_mm_roundscale_pd(a, INT32_C(          20));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[65].r), 1);

  a = simde_mm_loadu_pd(test_vec[66].a);
  r = simde_mm_roundscale_pd(a, INT32_C(          36));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[66].r), 1);

  #if !defined(SIMDE_FAST_MATH)
  a = simde_mm_loadu_pd(test_vec[67].a);
  r = simde_mm_roundscale_pd(a, INT32_C(          52));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[67].r), 1);
  #endif

  a = simde_mm_loadu_pd(test_vec[68].a);
  r = simde_mm_roundscale_pd(a, INT32_C(          68));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[68].r), 1);

  a = simde_mm_loadu_pd(test_vec[69].a);
  r = simde_mm_roundscale_pd(a, INT32_C(          84));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[69].r), 1);

  #if !defined(SIMDE_FAST_MATH)
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
  #endif

  a = simde_mm_loadu_pd(test_vec[75].a);
  r = simde_mm_roundscale_pd(a, INT32_C(         180));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[75].r), 1);

  a = simde_mm_loadu_pd(test_vec[76].a);
  r = simde_mm_roundscale_pd(a, INT32_C(         196));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[76].r), 1);

  #if !defined(SIMDE_FAST_MATH)
  a = simde_mm_loadu_pd(test_vec[77].a);
  r = simde_mm_roundscale_pd(a, INT32_C(         212));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[77].r), 1);
  #endif

  a = simde_mm_loadu_pd(test_vec[78].a);
  r = simde_mm_roundscale_pd(a, INT32_C(         228));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[78].r), 1);

  #if !defined(SIMDE_FAST_MATH)
  a = simde_mm_loadu_pd(test_vec[79].a);
  r = simde_mm_roundscale_pd(a, INT32_C(         244));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[79].r), 1);
  #endif

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
test_simde_mm_mask_roundscale_pd (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde_float64 src[2];
    const simde__mmask8 k;
    const simde_float64 a[2];
    const int imm8;
    const simde_float64 r[2];
  } test_vec[] = {
    { { SIMDE_FLOAT64_C(    70.53), SIMDE_FLOAT64_C(  -663.37) },
      UINT8_C(228),
      { SIMDE_FLOAT64_C(   964.85), SIMDE_FLOAT64_C(    43.10) },
       INT32_C(         160),
      { SIMDE_FLOAT64_C(    70.53), SIMDE_FLOAT64_C(  -663.37) } },
    { { SIMDE_FLOAT64_C(  -551.58), SIMDE_FLOAT64_C(   772.38) },
      UINT8_C(206),
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   607.68) },
       INT32_C(         209),
      { SIMDE_FLOAT64_C(  -551.58), SIMDE_FLOAT64_C(   607.68) } },
    { { SIMDE_FLOAT64_C(  -485.89), SIMDE_FLOAT64_C(   461.44) },
      UINT8_C(234),
      { SIMDE_FLOAT64_C(   305.64),        SIMDE_MATH_INFINITY },
       INT32_C(         210),
      { SIMDE_FLOAT64_C(  -485.89),        SIMDE_MATH_INFINITY } },
    { { SIMDE_FLOAT64_C(  -966.02), SIMDE_FLOAT64_C(  -869.88) },
      UINT8_C( 76),
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   779.36) },
       INT32_C(         227),
      { SIMDE_FLOAT64_C(  -966.02), SIMDE_FLOAT64_C(  -869.88) } },
    { { SIMDE_FLOAT64_C(   993.79), SIMDE_FLOAT64_C(   944.88) },
      UINT8_C(110),
      { SIMDE_FLOAT64_C(    36.89), SIMDE_FLOAT64_C(  -125.52) },
       INT32_C(         212),
      { SIMDE_FLOAT64_C(   993.79), SIMDE_FLOAT64_C(  -125.52) } },
    { { SIMDE_FLOAT64_C(  -353.14), SIMDE_FLOAT64_C(  -742.71) },
      UINT8_C(176),
      { SIMDE_FLOAT64_C(  -745.46), SIMDE_FLOAT64_C(   731.60) },
       INT32_C(         224),
      { SIMDE_FLOAT64_C(  -353.14), SIMDE_FLOAT64_C(  -742.71) } },
    { { SIMDE_FLOAT64_C(  -754.30), SIMDE_FLOAT64_C(  -174.41) },
      UINT8_C(233),
      { SIMDE_FLOAT64_C(   551.34), SIMDE_FLOAT64_C(  -901.33) },
       INT32_C(         113),
      { SIMDE_FLOAT64_C(   551.34), SIMDE_FLOAT64_C(  -174.41) } },
    { { SIMDE_FLOAT64_C(   395.65), SIMDE_FLOAT64_C(  -432.03) },
      UINT8_C(122),
      { SIMDE_FLOAT64_C(   525.76), SIMDE_FLOAT64_C(   438.68) },
       INT32_C(          82),
      { SIMDE_FLOAT64_C(   395.65), SIMDE_FLOAT64_C(   438.69) } },
  };

  simde__m128d src, a, r;

  src = simde_mm_loadu_pd(test_vec[0].src);
  a = simde_mm_loadu_pd(test_vec[0].a);
  r = simde_mm_mask_roundscale_pd(src, test_vec[0].k, a, INT32_C(         160));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[0].r), 1);

  src = simde_mm_loadu_pd(test_vec[1].src);
  a = simde_mm_loadu_pd(test_vec[1].a);
  r = simde_mm_mask_roundscale_pd(src, test_vec[1].k, a, INT32_C(         209));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[1].r), 1);

  src = simde_mm_loadu_pd(test_vec[2].src);
  a = simde_mm_loadu_pd(test_vec[2].a);
  r = simde_mm_mask_roundscale_pd(src, test_vec[2].k, a, INT32_C(         210));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[2].r), 1);

  src = simde_mm_loadu_pd(test_vec[3].src);
  a = simde_mm_loadu_pd(test_vec[3].a);
  r = simde_mm_mask_roundscale_pd(src, test_vec[3].k, a, INT32_C(         227));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[3].r), 1);

  src = simde_mm_loadu_pd(test_vec[4].src);
  a = simde_mm_loadu_pd(test_vec[4].a);
  r = simde_mm_mask_roundscale_pd(src, test_vec[4].k, a, INT32_C(         212));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[4].r), 1);

  src = simde_mm_loadu_pd(test_vec[5].src);
  a = simde_mm_loadu_pd(test_vec[5].a);
  r = simde_mm_mask_roundscale_pd(src, test_vec[5].k, a, INT32_C(         224));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[5].r), 1);

  src = simde_mm_loadu_pd(test_vec[6].src);
  a = simde_mm_loadu_pd(test_vec[6].a);
  r = simde_mm_mask_roundscale_pd(src, test_vec[6].k, a, INT32_C(         113));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[6].r), 1);

  src = simde_mm_loadu_pd(test_vec[7].src);
  a = simde_mm_loadu_pd(test_vec[7].a);
  r = simde_mm_mask_roundscale_pd(src, test_vec[7].k, a, INT32_C(          82));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[7].r), 1);

 return 0;
#else
  fputc('\n', stdout);
  int round_type[5] = {SIMDE_MM_FROUND_TO_NEAREST_INT, SIMDE_MM_FROUND_TO_NEG_INF, SIMDE_MM_FROUND_TO_POS_INF, SIMDE_MM_FROUND_TO_ZERO, SIMDE_MM_FROUND_CUR_DIRECTION};
  for (int i = 0 ; i < 8 ; i++) {
      simde__m128d src = simde_test_x86_random_f64x2(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
      simde__mmask8 k = simde_test_x86_random_mmask8();
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
      int imm8 = (((simde_test_codegen_rand() & 15) << 4) | round_type[i % 5]) & 255;
      simde__m128d r;
      SIMDE_CONSTIFY_256_(simde_mm_mask_roundscale_pd, r, simde_mm_setzero_pd(), imm8, src, k, a);

      simde_test_x86_write_f64x2(2, src, SIMDE_TEST_VEC_POS_FIRST);
      simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_MIDDLE);
      simde_test_x86_write_f64x2(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
      simde_test_codegen_write_i32(2, imm8, SIMDE_TEST_VEC_POS_MIDDLE);
      simde_test_x86_write_f64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_maskz_roundscale_pd (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask8 k;
    const simde_float64 a[2];
    const int imm8;
    const simde_float64 r[2];
  } test_vec[] = {
    { UINT8_C(129),
      { SIMDE_FLOAT64_C(   821.47), SIMDE_FLOAT64_C(  -844.99) },
       INT32_C(          96),
      { SIMDE_FLOAT64_C(   821.47), SIMDE_FLOAT64_C(     0.00) } },
    { UINT8_C( 81),
      { SIMDE_FLOAT64_C(  -873.46), SIMDE_FLOAT64_C(  -359.17) },
       INT32_C(         193),
      { SIMDE_FLOAT64_C(  -873.46), SIMDE_FLOAT64_C(     0.00) } },
    { UINT8_C( 63),
      { SIMDE_FLOAT64_C(   897.95),       -SIMDE_MATH_INFINITY },
       INT32_C(         242),
      { SIMDE_FLOAT64_C(   897.95),       -SIMDE_MATH_INFINITY } },
    { UINT8_C( 76),
      { SIMDE_FLOAT64_C(   389.69),       -SIMDE_MATH_INFINITY },
       INT32_C(          99),
      { SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00) } },
    { UINT8_C(139),
      { SIMDE_FLOAT64_C(   145.51), SIMDE_FLOAT64_C(   -79.48) },
       INT32_C(         180),
      { SIMDE_FLOAT64_C(   145.51), SIMDE_FLOAT64_C(   -79.48) } },
    { UINT8_C(233),
      { SIMDE_FLOAT64_C(   714.89), SIMDE_FLOAT64_C(   680.04) },
       INT32_C(         128),
      { SIMDE_FLOAT64_C(   714.89), SIMDE_FLOAT64_C(     0.00) } },
    { UINT8_C(171),
      { SIMDE_FLOAT64_C(  -808.91), SIMDE_FLOAT64_C(  -160.34) },
       INT32_C(         241),
      { SIMDE_FLOAT64_C(  -808.91), SIMDE_FLOAT64_C(  -160.34) } },
    { UINT8_C( 19),
      { SIMDE_FLOAT64_C(  -491.94), SIMDE_FLOAT64_C(  -880.40) },
       INT32_C(          34),
      { SIMDE_FLOAT64_C(  -491.75), SIMDE_FLOAT64_C(  -880.25) } },
  };

  simde__m128d a, r;

  a = simde_mm_loadu_pd(test_vec[0].a);
  r = simde_mm_maskz_roundscale_pd(test_vec[0].k, a, INT32_C(          96));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[0].r), 1);

  a = simde_mm_loadu_pd(test_vec[1].a);
  r = simde_mm_maskz_roundscale_pd(test_vec[1].k, a, INT32_C(         193));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[1].r), 1);

  a = simde_mm_loadu_pd(test_vec[2].a);
  r = simde_mm_maskz_roundscale_pd(test_vec[2].k, a, INT32_C(         242));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[2].r), 1);

  a = simde_mm_loadu_pd(test_vec[3].a);
  r = simde_mm_maskz_roundscale_pd(test_vec[3].k, a, INT32_C(          99));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[3].r), 1);

  a = simde_mm_loadu_pd(test_vec[4].a);
  r = simde_mm_maskz_roundscale_pd(test_vec[4].k, a, INT32_C(         180));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[4].r), 1);

  a = simde_mm_loadu_pd(test_vec[5].a);
  r = simde_mm_maskz_roundscale_pd(test_vec[5].k, a, INT32_C(         128));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[5].r), 1);

  a = simde_mm_loadu_pd(test_vec[6].a);
  r = simde_mm_maskz_roundscale_pd(test_vec[6].k, a, INT32_C(         241));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[6].r), 1);

  a = simde_mm_loadu_pd(test_vec[7].a);
  r = simde_mm_maskz_roundscale_pd(test_vec[7].k, a, INT32_C(          34));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[7].r), 1);

 return 0;
#else
  fputc('\n', stdout);
  int round_type[5] = {SIMDE_MM_FROUND_TO_NEAREST_INT, SIMDE_MM_FROUND_TO_NEG_INF, SIMDE_MM_FROUND_TO_POS_INF, SIMDE_MM_FROUND_TO_ZERO, SIMDE_MM_FROUND_CUR_DIRECTION};
  for (int i = 0 ; i < 8 ; i++) {
    simde__mmask8 k = simde_test_x86_random_mmask8();
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
    int imm8 = (((simde_test_codegen_rand() & 15) << 4) | round_type[i % 5]) & 255;
    simde__m128d r;
    SIMDE_CONSTIFY_256_(simde_mm_maskz_roundscale_pd, r, simde_mm_setzero_pd(), imm8, k, a);

    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_f64x2(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, imm8, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
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

  #if !defined(SIMDE_FAST_MATH)
  a = simde_mm256_loadu_pd(test_vec[8].a);
  r = simde_mm256_roundscale_pd(a, INT32_C(         128));
  simde_test_x86_assert_equal_f64x4(r, simde_mm256_loadu_pd(test_vec[8].r), 1);
  #endif

  a = simde_mm256_loadu_pd(test_vec[9].a);
  r = simde_mm256_roundscale_pd(a, INT32_C(         144));
  simde_test_x86_assert_equal_f64x4(r, simde_mm256_loadu_pd(test_vec[9].r), 1);

  #if !defined(SIMDE_FAST_MATH)
  a = simde_mm256_loadu_pd(test_vec[10].a);
  r = simde_mm256_roundscale_pd(a, INT32_C(         160));
  simde_test_x86_assert_equal_f64x4(r, simde_mm256_loadu_pd(test_vec[10].r), 1);

  a = simde_mm256_loadu_pd(test_vec[11].a);
  r = simde_mm256_roundscale_pd(a, INT32_C(         176));
  simde_test_x86_assert_equal_f64x4(r, simde_mm256_loadu_pd(test_vec[11].r), 1);

  a = simde_mm256_loadu_pd(test_vec[12].a);
  r = simde_mm256_roundscale_pd(a, INT32_C(         192));
  simde_test_x86_assert_equal_f64x4(r, simde_mm256_loadu_pd(test_vec[12].r), 1);
  #endif

  a = simde_mm256_loadu_pd(test_vec[13].a);
  r = simde_mm256_roundscale_pd(a, INT32_C(         208));
  simde_test_x86_assert_equal_f64x4(r, simde_mm256_loadu_pd(test_vec[13].r), 1);

  #if !defined(SIMDE_FAST_MATH)
  a = simde_mm256_loadu_pd(test_vec[14].a);
  r = simde_mm256_roundscale_pd(a, INT32_C(         224));
  simde_test_x86_assert_equal_f64x4(r, simde_mm256_loadu_pd(test_vec[14].r), 1);
  #endif

  a = simde_mm256_loadu_pd(test_vec[15].a);
  r = simde_mm256_roundscale_pd(a, INT32_C(         240));
  simde_test_x86_assert_equal_f64x4(r, simde_mm256_loadu_pd(test_vec[15].r), 1);

  a = simde_mm256_loadu_pd(test_vec[16].a);
  r = simde_mm256_roundscale_pd(a, INT32_C(           1));
  simde_test_x86_assert_equal_f64x4(r, simde_mm256_loadu_pd(test_vec[16].r), 1);

  a = simde_mm256_loadu_pd(test_vec[17].a);
  r = simde_mm256_roundscale_pd(a, INT32_C(          17));
  simde_test_x86_assert_equal_f64x4(r, simde_mm256_loadu_pd(test_vec[17].r), 1);

  #if !defined(SIMDE_FAST_MATH)
  a = simde_mm256_loadu_pd(test_vec[18].a);
  r = simde_mm256_roundscale_pd(a, INT32_C(          33));
  simde_test_x86_assert_equal_f64x4(r, simde_mm256_loadu_pd(test_vec[18].r), 1);
  #endif

  a = simde_mm256_loadu_pd(test_vec[19].a);
  r = simde_mm256_roundscale_pd(a, INT32_C(          49));
  simde_test_x86_assert_equal_f64x4(r, simde_mm256_loadu_pd(test_vec[19].r), 1);

  #if !defined(SIMDE_FAST_MATH)
  a = simde_mm256_loadu_pd(test_vec[20].a);
  r = simde_mm256_roundscale_pd(a, INT32_C(          65));
  simde_test_x86_assert_equal_f64x4(r, simde_mm256_loadu_pd(test_vec[20].r), 1);

  a = simde_mm256_loadu_pd(test_vec[21].a);
  r = simde_mm256_roundscale_pd(a, INT32_C(          81));
  simde_test_x86_assert_equal_f64x4(r, simde_mm256_loadu_pd(test_vec[21].r), 1);
  #endif

  a = simde_mm256_loadu_pd(test_vec[22].a);
  r = simde_mm256_roundscale_pd(a, INT32_C(          97));
  simde_test_x86_assert_equal_f64x4(r, simde_mm256_loadu_pd(test_vec[22].r), 1);

  a = simde_mm256_loadu_pd(test_vec[23].a);
  r = simde_mm256_roundscale_pd(a, INT32_C(         113));
  simde_test_x86_assert_equal_f64x4(r, simde_mm256_loadu_pd(test_vec[23].r), 1);

  #if !defined(SIMDE_FAST_MATH)
  a = simde_mm256_loadu_pd(test_vec[24].a);
  r = simde_mm256_roundscale_pd(a, INT32_C(         129));
  simde_test_x86_assert_equal_f64x4(r, simde_mm256_loadu_pd(test_vec[24].r), 1);
  #endif

  a = simde_mm256_loadu_pd(test_vec[25].a);
  r = simde_mm256_roundscale_pd(a, INT32_C(         145));
  simde_test_x86_assert_equal_f64x4(r, simde_mm256_loadu_pd(test_vec[25].r), 1);

  #if !defined(SIMDE_FAST_MATH)
  a = simde_mm256_loadu_pd(test_vec[26].a);
  r = simde_mm256_roundscale_pd(a, INT32_C(         161));
  simde_test_x86_assert_equal_f64x4(r, simde_mm256_loadu_pd(test_vec[26].r), 1);
  #endif

  a = simde_mm256_loadu_pd(test_vec[27].a);
  r = simde_mm256_roundscale_pd(a, INT32_C(         177));
  simde_test_x86_assert_equal_f64x4(r, simde_mm256_loadu_pd(test_vec[27].r), 1);

  a = simde_mm256_loadu_pd(test_vec[28].a);
  r = simde_mm256_roundscale_pd(a, INT32_C(         193));
  simde_test_x86_assert_equal_f64x4(r, simde_mm256_loadu_pd(test_vec[28].r), 1);

  #if !defined(SIMDE_FAST_MATH)
  a = simde_mm256_loadu_pd(test_vec[29].a);
  r = simde_mm256_roundscale_pd(a, INT32_C(         209));
  simde_test_x86_assert_equal_f64x4(r, simde_mm256_loadu_pd(test_vec[29].r), 1);
  #endif

  a = simde_mm256_loadu_pd(test_vec[30].a);
  r = simde_mm256_roundscale_pd(a, INT32_C(         225));
  simde_test_x86_assert_equal_f64x4(r, simde_mm256_loadu_pd(test_vec[30].r), 1);

  a = simde_mm256_loadu_pd(test_vec[31].a);
  r = simde_mm256_roundscale_pd(a, INT32_C(         241));
  simde_test_x86_assert_equal_f64x4(r, simde_mm256_loadu_pd(test_vec[31].r), 1);

  #if !defined(SIMDE_FAST_MATH)
  a = simde_mm256_loadu_pd(test_vec[32].a);
  r = simde_mm256_roundscale_pd(a, INT32_C(           2));
  simde_test_x86_assert_equal_f64x4(r, simde_mm256_loadu_pd(test_vec[32].r), 1);

  a = simde_mm256_loadu_pd(test_vec[33].a);
  r = simde_mm256_roundscale_pd(a, INT32_C(          18));
  simde_test_x86_assert_equal_f64x4(r, simde_mm256_loadu_pd(test_vec[33].r), 1);

  a = simde_mm256_loadu_pd(test_vec[34].a);
  r = simde_mm256_roundscale_pd(a, INT32_C(          34));
  simde_test_x86_assert_equal_f64x4(r, simde_mm256_loadu_pd(test_vec[34].r), 1);
  #endif

  a = simde_mm256_loadu_pd(test_vec[35].a);
  r = simde_mm256_roundscale_pd(a, INT32_C(          50));
  simde_test_x86_assert_equal_f64x4(r, simde_mm256_loadu_pd(test_vec[35].r), 1);

  #if !defined(SIMDE_FAST_MATH)
  a = simde_mm256_loadu_pd(test_vec[36].a);
  r = simde_mm256_roundscale_pd(a, INT32_C(          66));
  simde_test_x86_assert_equal_f64x4(r, simde_mm256_loadu_pd(test_vec[36].r), 1);

  a = simde_mm256_loadu_pd(test_vec[37].a);
  r = simde_mm256_roundscale_pd(a, INT32_C(          82));
  simde_test_x86_assert_equal_f64x4(r, simde_mm256_loadu_pd(test_vec[37].r), 1);
  #endif

  a = simde_mm256_loadu_pd(test_vec[38].a);
  r = simde_mm256_roundscale_pd(a, INT32_C(          98));
  simde_test_x86_assert_equal_f64x4(r, simde_mm256_loadu_pd(test_vec[38].r), 1);

  #if !defined(SIMDE_FAST_MATH)
  a = simde_mm256_loadu_pd(test_vec[39].a);
  r = simde_mm256_roundscale_pd(a, INT32_C(         114));
  simde_test_x86_assert_equal_f64x4(r, simde_mm256_loadu_pd(test_vec[39].r), 1);

  a = simde_mm256_loadu_pd(test_vec[40].a);
  r = simde_mm256_roundscale_pd(a, INT32_C(         130));
  simde_test_x86_assert_equal_f64x4(r, simde_mm256_loadu_pd(test_vec[40].r), 1);
  #endif

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

  #if !defined(SIMDE_FAST_MATH)
  a = simde_mm256_loadu_pd(test_vec[52].a);
  r = simde_mm256_roundscale_pd(a, INT32_C(          67));
  simde_test_x86_assert_equal_f64x4(r, simde_mm256_loadu_pd(test_vec[52].r), 1);
  #endif

  a = simde_mm256_loadu_pd(test_vec[53].a);
  r = simde_mm256_roundscale_pd(a, INT32_C(          83));
  simde_test_x86_assert_equal_f64x4(r, simde_mm256_loadu_pd(test_vec[53].r), 1);

  a = simde_mm256_loadu_pd(test_vec[54].a);
  r = simde_mm256_roundscale_pd(a, INT32_C(          99));
  simde_test_x86_assert_equal_f64x4(r, simde_mm256_loadu_pd(test_vec[54].r), 1);

  a = simde_mm256_loadu_pd(test_vec[55].a);
  r = simde_mm256_roundscale_pd(a, INT32_C(         115));
  simde_test_x86_assert_equal_f64x4(r, simde_mm256_loadu_pd(test_vec[55].r), 1);

  #if !defined(SIMDE_FAST_MATH)
  a = simde_mm256_loadu_pd(test_vec[56].a);
  r = simde_mm256_roundscale_pd(a, INT32_C(         131));
  simde_test_x86_assert_equal_f64x4(r, simde_mm256_loadu_pd(test_vec[56].r), 1);
  #endif

  a = simde_mm256_loadu_pd(test_vec[57].a);
  r = simde_mm256_roundscale_pd(a, INT32_C(         147));
  simde_test_x86_assert_equal_f64x4(r, simde_mm256_loadu_pd(test_vec[57].r), 1);

  #if !defined(SIMDE_FAST_MATH)
  a = simde_mm256_loadu_pd(test_vec[58].a);
  r = simde_mm256_roundscale_pd(a, INT32_C(         163));
  simde_test_x86_assert_equal_f64x4(r, simde_mm256_loadu_pd(test_vec[58].r), 1);
  #endif

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

  #if !defined(SIMDE_FAST_MATH)
  a = simde_mm256_loadu_pd(test_vec[69].a);
  r = simde_mm256_roundscale_pd(a, INT32_C(          84));
  simde_test_x86_assert_equal_f64x4(r, simde_mm256_loadu_pd(test_vec[69].r), 1);
  #endif

  a = simde_mm256_loadu_pd(test_vec[70].a);
  r = simde_mm256_roundscale_pd(a, INT32_C(         100));
  simde_test_x86_assert_equal_f64x4(r, simde_mm256_loadu_pd(test_vec[70].r), 1);

  #if !defined(SIMDE_FAST_MATH)
  a = simde_mm256_loadu_pd(test_vec[71].a);
  r = simde_mm256_roundscale_pd(a, INT32_C(         116));
  simde_test_x86_assert_equal_f64x4(r, simde_mm256_loadu_pd(test_vec[71].r), 1);
  #endif

  a = simde_mm256_loadu_pd(test_vec[72].a);
  r = simde_mm256_roundscale_pd(a, INT32_C(         132));
  simde_test_x86_assert_equal_f64x4(r, simde_mm256_loadu_pd(test_vec[72].r), 1);

  #if !defined(SIMDE_FAST_MATH)
  a = simde_mm256_loadu_pd(test_vec[73].a);
  r = simde_mm256_roundscale_pd(a, INT32_C(         148));
  simde_test_x86_assert_equal_f64x4(r, simde_mm256_loadu_pd(test_vec[73].r), 1);

  a = simde_mm256_loadu_pd(test_vec[74].a);
  r = simde_mm256_roundscale_pd(a, INT32_C(         164));
  simde_test_x86_assert_equal_f64x4(r, simde_mm256_loadu_pd(test_vec[74].r), 1);
  #endif

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

  #if !defined(SIMDE_FAST_MATH)
  a = simde_mm256_loadu_pd(test_vec[79].a);
  r = simde_mm256_roundscale_pd(a, INT32_C(         244));
  simde_test_x86_assert_equal_f64x4(r, simde_mm256_loadu_pd(test_vec[79].r), 1);
  #endif

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
test_simde_mm256_mask_roundscale_pd (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde_float64 src[4];
    const simde__mmask8 k;
    const simde_float64 a[4];
    const int32_t imm8;
    const simde_float64 r[4];
  } test_vec[] = {
    { { SIMDE_FLOAT64_C(   926.29), SIMDE_FLOAT64_C(   909.09), SIMDE_FLOAT64_C(   774.77), SIMDE_FLOAT64_C(   372.04) },
      UINT8_C(125),
      { SIMDE_FLOAT64_C(   458.74), SIMDE_FLOAT64_C(  -735.76), SIMDE_FLOAT64_C(   634.56), SIMDE_FLOAT64_C(   216.61) },
       INT32_C(          32),
      { SIMDE_FLOAT64_C(   458.75), SIMDE_FLOAT64_C(   909.09), SIMDE_FLOAT64_C(   634.50), SIMDE_FLOAT64_C(   216.50) } },
    { { SIMDE_FLOAT64_C(   808.28), SIMDE_FLOAT64_C(  -973.92), SIMDE_FLOAT64_C(   364.29), SIMDE_FLOAT64_C(   260.83) },
      UINT8_C( 21),
      { SIMDE_FLOAT64_C(   685.29), SIMDE_FLOAT64_C(  -217.73), SIMDE_FLOAT64_C(   979.97), SIMDE_FLOAT64_C(   463.75) },
       INT32_C(          81),
      { SIMDE_FLOAT64_C(   685.28), SIMDE_FLOAT64_C(  -973.92), SIMDE_FLOAT64_C(   979.97), SIMDE_FLOAT64_C(   260.83) } },
    { { SIMDE_FLOAT64_C(   526.14), SIMDE_FLOAT64_C(   931.62), SIMDE_FLOAT64_C(   993.03), SIMDE_FLOAT64_C(   390.55) },
      UINT8_C( 90),
      { SIMDE_FLOAT64_C(  -182.65),        SIMDE_MATH_INFINITY, SIMDE_FLOAT64_C(   177.32), SIMDE_FLOAT64_C(  -823.86) },
       INT32_C(          18),
      { SIMDE_FLOAT64_C(   526.14),        SIMDE_MATH_INFINITY, SIMDE_FLOAT64_C(   993.03), SIMDE_FLOAT64_C(  -823.50) } },
    { { SIMDE_FLOAT64_C(    34.50), SIMDE_FLOAT64_C(   409.65), SIMDE_FLOAT64_C(  -471.60), SIMDE_FLOAT64_C(  -330.93) },
      UINT8_C(230),
      { SIMDE_FLOAT64_C(  -757.14), SIMDE_FLOAT64_C(  -817.96), SIMDE_FLOAT64_C(  -565.47), SIMDE_FLOAT64_C(  -731.06) },
       INT32_C(         163),
      { SIMDE_FLOAT64_C(    34.50), SIMDE_FLOAT64_C(  -817.96), SIMDE_FLOAT64_C(  -565.47), SIMDE_FLOAT64_C(  -330.93) } },
    { { SIMDE_FLOAT64_C(  -509.07), SIMDE_FLOAT64_C(   231.61), SIMDE_FLOAT64_C(  -522.37), SIMDE_FLOAT64_C(  -529.09) },
      UINT8_C( 55),
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   -49.42), SIMDE_FLOAT64_C(  -778.50), SIMDE_FLOAT64_C(   394.59) },
       INT32_C(          84),
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   -49.41), SIMDE_FLOAT64_C(  -778.50), SIMDE_FLOAT64_C(  -529.09) } },
    { { SIMDE_FLOAT64_C(   760.96), SIMDE_FLOAT64_C(  -422.11), SIMDE_FLOAT64_C(  -513.55), SIMDE_FLOAT64_C(   937.10) },
      UINT8_C( 63),
      { SIMDE_FLOAT64_C(   572.86), SIMDE_FLOAT64_C(   888.00), SIMDE_FLOAT64_C(   734.18), SIMDE_FLOAT64_C(  -392.63) },
       INT32_C(          80),
      { SIMDE_FLOAT64_C(   572.88), SIMDE_FLOAT64_C(   888.00), SIMDE_FLOAT64_C(   734.19), SIMDE_FLOAT64_C(  -392.62) } },
    { { SIMDE_FLOAT64_C(   276.43), SIMDE_FLOAT64_C(   923.91), SIMDE_FLOAT64_C(  -494.56), SIMDE_FLOAT64_C(   458.47) },
      UINT8_C(252),
      { SIMDE_FLOAT64_C(  -225.62),        SIMDE_MATH_INFINITY, SIMDE_FLOAT64_C(  -946.20), SIMDE_FLOAT64_C(   265.31) },
       INT32_C(          65),
      { SIMDE_FLOAT64_C(   276.43), SIMDE_FLOAT64_C(   923.91), SIMDE_FLOAT64_C(  -946.25), SIMDE_FLOAT64_C(   265.25) } },
    { { SIMDE_FLOAT64_C(   994.40), SIMDE_FLOAT64_C(  -313.20), SIMDE_FLOAT64_C(   153.28), SIMDE_FLOAT64_C(   388.99) },
      UINT8_C(122),
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(  -301.89), SIMDE_FLOAT64_C(   391.38), SIMDE_FLOAT64_C(   343.23) },
       INT32_C(         178),
      { SIMDE_FLOAT64_C(   994.40), SIMDE_FLOAT64_C(  -301.89), SIMDE_FLOAT64_C(   153.28), SIMDE_FLOAT64_C(   343.23) } },
  };

  simde__m256d src, a, r;

  src = simde_mm256_loadu_pd(test_vec[0].src);
  a = simde_mm256_loadu_pd(test_vec[0].a);
  r = simde_mm256_mask_roundscale_pd(src, test_vec[0].k, a, INT32_C(          32));
  simde_test_x86_assert_equal_f64x4(r, simde_mm256_loadu_pd(test_vec[0].r), 1);

  src = simde_mm256_loadu_pd(test_vec[1].src);
  a = simde_mm256_loadu_pd(test_vec[1].a);
  r = simde_mm256_mask_roundscale_pd(src, test_vec[1].k, a, INT32_C(          81));
  simde_test_x86_assert_equal_f64x4(r, simde_mm256_loadu_pd(test_vec[1].r), 1);

  src = simde_mm256_loadu_pd(test_vec[2].src);
  a = simde_mm256_loadu_pd(test_vec[2].a);
  r = simde_mm256_mask_roundscale_pd(src, test_vec[2].k, a, INT32_C(          18));
  simde_test_x86_assert_equal_f64x4(r, simde_mm256_loadu_pd(test_vec[2].r), 1);

  src = simde_mm256_loadu_pd(test_vec[3].src);
  a = simde_mm256_loadu_pd(test_vec[3].a);
  r = simde_mm256_mask_roundscale_pd(src, test_vec[3].k, a, INT32_C(         163));
  simde_test_x86_assert_equal_f64x4(r, simde_mm256_loadu_pd(test_vec[3].r), 1);

  #if !defined(SIMDE_FAST_MATH)
  src = simde_mm256_loadu_pd(test_vec[4].src);
  a = simde_mm256_loadu_pd(test_vec[4].a);
  r = simde_mm256_mask_roundscale_pd(src, test_vec[4].k, a, INT32_C(          84));
  simde_test_x86_assert_equal_f64x4(r, simde_mm256_loadu_pd(test_vec[4].r), 1);
  #endif

  src = simde_mm256_loadu_pd(test_vec[5].src);
  a = simde_mm256_loadu_pd(test_vec[5].a);
  r = simde_mm256_mask_roundscale_pd(src, test_vec[5].k, a, INT32_C(          80));
  simde_test_x86_assert_equal_f64x4(r, simde_mm256_loadu_pd(test_vec[5].r), 1);

  src = simde_mm256_loadu_pd(test_vec[6].src);
  a = simde_mm256_loadu_pd(test_vec[6].a);
  r = simde_mm256_mask_roundscale_pd(src, test_vec[6].k, a, INT32_C(          65));
  simde_test_x86_assert_equal_f64x4(r, simde_mm256_loadu_pd(test_vec[6].r), 1);

  src = simde_mm256_loadu_pd(test_vec[7].src);
  a = simde_mm256_loadu_pd(test_vec[7].a);
  r = simde_mm256_mask_roundscale_pd(src, test_vec[7].k, a, INT32_C(         178));
  simde_test_x86_assert_equal_f64x4(r, simde_mm256_loadu_pd(test_vec[7].r), 1);

  return 0;
#else
  fputc('\n', stdout);
  int round_type[5] = {SIMDE_MM_FROUND_TO_NEAREST_INT, SIMDE_MM_FROUND_TO_NEG_INF, SIMDE_MM_FROUND_TO_POS_INF, SIMDE_MM_FROUND_TO_ZERO, SIMDE_MM_FROUND_CUR_DIRECTION};
  for (int i = 0 ; i < 8 ; i++) {
    simde__m256d src = simde_test_x86_random_f64x4(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
    simde__mmask8 k = simde_test_x86_random_mmask8();
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
    int imm8 = (((simde_test_codegen_rand() & 15) << 4) | round_type[i % 5]) & 255;
    simde__m256d r;
    SIMDE_CONSTIFY_256_(simde_mm256_mask_roundscale_pd, r, simde_mm256_setzero_pd(), imm8, src, k, a);

    simde_test_x86_write_f64x4(2, src, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f64x4(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, imm8, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f64x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm256_maskz_roundscale_pd (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask8 k;
    const simde_float64 a[4];
    const int32_t imm8;
    const simde_float64 r[4];
  } test_vec[] = {
    { UINT8_C(131),
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(  -452.58), SIMDE_FLOAT64_C(   364.79), SIMDE_FLOAT64_C(  -485.87) },
       INT32_C(         144),
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(  -452.58), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00) } },
    { UINT8_C(237),
      { SIMDE_FLOAT64_C(  -900.30), SIMDE_FLOAT64_C(  -203.53), SIMDE_FLOAT64_C(  -910.18), SIMDE_FLOAT64_C(   104.50) },
       INT32_C(         161),
      { SIMDE_FLOAT64_C(  -900.30), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(  -910.18), SIMDE_FLOAT64_C(   104.50) } },
    { UINT8_C(139),
      { SIMDE_FLOAT64_C(   381.69), SIMDE_FLOAT64_C(    91.35), SIMDE_FLOAT64_C(  -727.30), SIMDE_FLOAT64_C(   376.09) },
       INT32_C(         146),
      { SIMDE_FLOAT64_C(   381.69), SIMDE_FLOAT64_C(    91.35), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(   376.09) } },
    { UINT8_C(120),
      { SIMDE_FLOAT64_C(   408.57), SIMDE_FLOAT64_C(  -808.69), SIMDE_FLOAT64_C(   463.20), SIMDE_FLOAT64_C(  -200.06) },
       INT32_C(         211),
      { SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(  -200.06) } },
    { UINT8_C(226),
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   405.18), SIMDE_FLOAT64_C(   344.89), SIMDE_FLOAT64_C(  -104.81) },
       INT32_C(          68),
      { SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(   405.19), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00) } },
    { UINT8_C(234),
      { SIMDE_FLOAT64_C(  -702.95), SIMDE_FLOAT64_C(    20.62), SIMDE_FLOAT64_C(   510.88), SIMDE_FLOAT64_C(    93.52) },
       INT32_C(          32),
      { SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(    20.50), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(    93.50) } },
    { UINT8_C(113),
      { SIMDE_FLOAT64_C(  -534.43), SIMDE_FLOAT64_C(   956.30), SIMDE_FLOAT64_C(   325.48), SIMDE_FLOAT64_C(   556.92) },
       INT32_C(         209),
      { SIMDE_FLOAT64_C(  -534.43), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00) } },
    { UINT8_C(169),
      { SIMDE_FLOAT64_C(   654.97), SIMDE_FLOAT64_C(   466.66), SIMDE_FLOAT64_C(  -256.36), SIMDE_FLOAT64_C(   846.28) },
       INT32_C(          50),
      { SIMDE_FLOAT64_C(   655.00), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(   846.38) } },
  };

  simde__m256d a, r;

  #if !defined(SIMDE_FAST_MATH)
  a = simde_mm256_loadu_pd(test_vec[0].a);
  r = simde_mm256_maskz_roundscale_pd(test_vec[0].k, a, INT32_C(         144));
  simde_test_x86_assert_equal_f64x4(r, simde_mm256_loadu_pd(test_vec[0].r), 1);
  #endif

  a = simde_mm256_loadu_pd(test_vec[1].a);
  r = simde_mm256_maskz_roundscale_pd(test_vec[1].k, a, INT32_C(         161));
  simde_test_x86_assert_equal_f64x4(r, simde_mm256_loadu_pd(test_vec[1].r), 1);

  a = simde_mm256_loadu_pd(test_vec[2].a);
  r = simde_mm256_maskz_roundscale_pd(test_vec[2].k, a, INT32_C(         146));
  simde_test_x86_assert_equal_f64x4(r, simde_mm256_loadu_pd(test_vec[2].r), 1);

  a = simde_mm256_loadu_pd(test_vec[3].a);
  r = simde_mm256_maskz_roundscale_pd(test_vec[3].k, a, INT32_C(         211));
  simde_test_x86_assert_equal_f64x4(r, simde_mm256_loadu_pd(test_vec[3].r), 1);

  a = simde_mm256_loadu_pd(test_vec[4].a);
  r = simde_mm256_maskz_roundscale_pd(test_vec[4].k, a, INT32_C(          68));
  simde_test_x86_assert_equal_f64x4(r, simde_mm256_loadu_pd(test_vec[4].r), 1);

  a = simde_mm256_loadu_pd(test_vec[5].a);
  r = simde_mm256_maskz_roundscale_pd(test_vec[5].k, a, INT32_C(          32));
  simde_test_x86_assert_equal_f64x4(r, simde_mm256_loadu_pd(test_vec[5].r), 1);

  a = simde_mm256_loadu_pd(test_vec[6].a);
  r = simde_mm256_maskz_roundscale_pd(test_vec[6].k, a, INT32_C(         209));
  simde_test_x86_assert_equal_f64x4(r, simde_mm256_loadu_pd(test_vec[6].r), 1);

  a = simde_mm256_loadu_pd(test_vec[7].a);
  r = simde_mm256_maskz_roundscale_pd(test_vec[7].k, a, INT32_C(          50));
  simde_test_x86_assert_equal_f64x4(r, simde_mm256_loadu_pd(test_vec[7].r), 1);

  return 0;
#else
  fputc('\n', stdout);
  int round_type[5] = {SIMDE_MM_FROUND_TO_NEAREST_INT, SIMDE_MM_FROUND_TO_NEG_INF, SIMDE_MM_FROUND_TO_POS_INF, SIMDE_MM_FROUND_TO_ZERO, SIMDE_MM_FROUND_CUR_DIRECTION};
  for (int i = 0 ; i < 8 ; i++) {
    simde__mmask8 k = simde_test_x86_random_mmask8();
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
    int imm8 = (((simde_test_codegen_rand() & 15) << 4) | round_type[i % 5]) & 255;
    simde__m256d r;
    SIMDE_CONSTIFY_256_(simde_mm256_maskz_roundscale_pd, r, simde_mm256_setzero_pd(), imm8, k, a);

    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_f64x4(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, imm8, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f64x4(2, r, SIMDE_TEST_VEC_POS_LAST);
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
    { { SIMDE_FLOAT64_C(   -67.30),        SIMDE_MATH_INFINITY, SIMDE_FLOAT64_C(  -705.81), SIMDE_FLOAT64_C(   196.47),
        SIMDE_FLOAT64_C(   177.22), SIMDE_FLOAT64_C(   391.26), SIMDE_FLOAT64_C(   -54.56), SIMDE_FLOAT64_C(   829.93) },
       INT32_C(         224),
      { SIMDE_FLOAT64_C(   -67.30),        SIMDE_MATH_INFINITY, SIMDE_FLOAT64_C(  -705.81), SIMDE_FLOAT64_C(   196.47),
        SIMDE_FLOAT64_C(   177.22), SIMDE_FLOAT64_C(   391.26), SIMDE_FLOAT64_C(   -54.56), SIMDE_FLOAT64_C(   829.93) } },
    { {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   889.83), SIMDE_FLOAT64_C(   441.33), SIMDE_FLOAT64_C(  -977.58),
        SIMDE_FLOAT64_C(  -699.06), SIMDE_FLOAT64_C(   260.67), SIMDE_FLOAT64_C(  -418.77), SIMDE_FLOAT64_C(   157.04) },
       INT32_C(         129),
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   889.83), SIMDE_FLOAT64_C(   441.33), SIMDE_FLOAT64_C(  -977.58),
        SIMDE_FLOAT64_C(  -699.06), SIMDE_FLOAT64_C(   260.67), SIMDE_FLOAT64_C(  -418.77), SIMDE_FLOAT64_C(   157.04) } },
    { { SIMDE_FLOAT64_C(   -38.35),        SIMDE_MATH_INFINITY, SIMDE_FLOAT64_C(  -257.79), SIMDE_FLOAT64_C(  -975.63),
        SIMDE_FLOAT64_C(   411.77), SIMDE_FLOAT64_C(   590.64), SIMDE_FLOAT64_C(   -80.22), SIMDE_FLOAT64_C(   714.31) },
       INT32_C(          82),
      { SIMDE_FLOAT64_C(   -38.34),        SIMDE_MATH_INFINITY, SIMDE_FLOAT64_C(  -257.78), SIMDE_FLOAT64_C(  -975.62),
        SIMDE_FLOAT64_C(   411.78), SIMDE_FLOAT64_C(   590.66), SIMDE_FLOAT64_C(   -80.22), SIMDE_FLOAT64_C(   714.31) } },
    { { SIMDE_FLOAT64_C(  -903.12), SIMDE_FLOAT64_C(   399.77), SIMDE_FLOAT64_C(  -334.76), SIMDE_FLOAT64_C(   926.81),
        SIMDE_FLOAT64_C(  -852.06), SIMDE_FLOAT64_C(  -961.10), SIMDE_FLOAT64_C(   107.72), SIMDE_FLOAT64_C(   666.94) },
       INT32_C(          51),
      { SIMDE_FLOAT64_C(  -903.00), SIMDE_FLOAT64_C(   399.75), SIMDE_FLOAT64_C(  -334.75), SIMDE_FLOAT64_C(   926.75),
        SIMDE_FLOAT64_C(  -852.00), SIMDE_FLOAT64_C(  -961.00), SIMDE_FLOAT64_C(   107.62), SIMDE_FLOAT64_C(   666.88) } },
    { { SIMDE_FLOAT64_C(   108.27), SIMDE_FLOAT64_C(  -600.58), SIMDE_FLOAT64_C(   298.49), SIMDE_FLOAT64_C(  -631.06),
        SIMDE_FLOAT64_C(   -19.34), SIMDE_FLOAT64_C(  -544.47), SIMDE_FLOAT64_C(  -798.15), SIMDE_FLOAT64_C(   358.47) },
       INT32_C(          68),
      { SIMDE_FLOAT64_C(   108.25), SIMDE_FLOAT64_C(  -600.56), SIMDE_FLOAT64_C(   298.50), SIMDE_FLOAT64_C(  -631.06),
        SIMDE_FLOAT64_C(   -19.31), SIMDE_FLOAT64_C(  -544.50), SIMDE_FLOAT64_C(  -798.12), SIMDE_FLOAT64_C(   358.50) } },
    { { SIMDE_FLOAT64_C(  -893.30), SIMDE_FLOAT64_C(    50.96), SIMDE_FLOAT64_C(   187.87), SIMDE_FLOAT64_C(   518.48),
        SIMDE_FLOAT64_C(  -358.41), SIMDE_FLOAT64_C(  -892.35), SIMDE_FLOAT64_C(   232.79), SIMDE_FLOAT64_C(   164.93) },
       INT32_C(         224),
      { SIMDE_FLOAT64_C(  -893.30), SIMDE_FLOAT64_C(    50.96), SIMDE_FLOAT64_C(   187.87), SIMDE_FLOAT64_C(   518.48),
        SIMDE_FLOAT64_C(  -358.41), SIMDE_FLOAT64_C(  -892.35), SIMDE_FLOAT64_C(   232.79), SIMDE_FLOAT64_C(   164.93) } },
    { { SIMDE_FLOAT64_C(  -115.27), SIMDE_FLOAT64_C(   124.20), SIMDE_FLOAT64_C(  -358.93), SIMDE_FLOAT64_C(   549.98),
        SIMDE_FLOAT64_C(    51.01), SIMDE_FLOAT64_C(  -211.00), SIMDE_FLOAT64_C(   588.88), SIMDE_FLOAT64_C(  -841.27) },
       INT32_C(         241),
      { SIMDE_FLOAT64_C(  -115.27), SIMDE_FLOAT64_C(   124.20), SIMDE_FLOAT64_C(  -358.93), SIMDE_FLOAT64_C(   549.98),
        SIMDE_FLOAT64_C(    51.01), SIMDE_FLOAT64_C(  -211.00), SIMDE_FLOAT64_C(   588.88), SIMDE_FLOAT64_C(  -841.27) } },
    { { SIMDE_FLOAT64_C(   156.28), SIMDE_FLOAT64_C(   564.22), SIMDE_FLOAT64_C(  -634.69), SIMDE_FLOAT64_C(  -545.23),
        SIMDE_FLOAT64_C(   933.16), SIMDE_FLOAT64_C(   345.96), SIMDE_FLOAT64_C(   -89.70), SIMDE_FLOAT64_C(  -864.99) },
       INT32_C(         162),
      { SIMDE_FLOAT64_C(   156.28), SIMDE_FLOAT64_C(   564.22), SIMDE_FLOAT64_C(  -634.69), SIMDE_FLOAT64_C(  -545.23),
        SIMDE_FLOAT64_C(   933.16), SIMDE_FLOAT64_C(   345.96), SIMDE_FLOAT64_C(   -89.70), SIMDE_FLOAT64_C(  -864.99) } },
  };

  simde__m512d a, r;

  a = simde_mm512_loadu_pd(test_vec[0].a);
  r = simde_mm512_roundscale_pd(a, INT32_C(         224));
  simde_test_x86_assert_equal_f64x8(r, simde_mm512_loadu_pd(test_vec[0].r), 1);

  #if !defined(SIMDE_FAST_MATH)
  a = simde_mm512_loadu_pd(test_vec[1].a);
  r = simde_mm512_roundscale_pd(a, INT32_C(         129));
  simde_test_x86_assert_equal_f64x8(r, simde_mm512_loadu_pd(test_vec[1].r), 1);
  #endif

  a = simde_mm512_loadu_pd(test_vec[2].a);
  r = simde_mm512_roundscale_pd(a, INT32_C(          82));
  simde_test_x86_assert_equal_f64x8(r, simde_mm512_loadu_pd(test_vec[2].r), 1);

  a = simde_mm512_loadu_pd(test_vec[3].a);
  r = simde_mm512_roundscale_pd(a, INT32_C(          51));
  simde_test_x86_assert_equal_f64x8(r, simde_mm512_loadu_pd(test_vec[3].r), 1);

  a = simde_mm512_loadu_pd(test_vec[4].a);
  r = simde_mm512_roundscale_pd(a, INT32_C(          68));
  simde_test_x86_assert_equal_f64x8(r, simde_mm512_loadu_pd(test_vec[4].r), 1);

  a = simde_mm512_loadu_pd(test_vec[5].a);
  r = simde_mm512_roundscale_pd(a, INT32_C(         224));
  simde_test_x86_assert_equal_f64x8(r, simde_mm512_loadu_pd(test_vec[5].r), 1);

  a = simde_mm512_loadu_pd(test_vec[6].a);
  r = simde_mm512_roundscale_pd(a, INT32_C(         241));
  simde_test_x86_assert_equal_f64x8(r, simde_mm512_loadu_pd(test_vec[6].r), 1);

  a = simde_mm512_loadu_pd(test_vec[7].a);
  r = simde_mm512_roundscale_pd(a, INT32_C(         162));
  simde_test_x86_assert_equal_f64x8(r, simde_mm512_loadu_pd(test_vec[7].r), 1);

  return 0;
#else
  fputc('\n', stdout);
  int round_type[5] = {SIMDE_MM_FROUND_TO_NEAREST_INT, SIMDE_MM_FROUND_TO_NEG_INF, SIMDE_MM_FROUND_TO_POS_INF, SIMDE_MM_FROUND_TO_ZERO, SIMDE_MM_FROUND_CUR_DIRECTION};
  for (int i = 0 ; i < 8 ; i++) {
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
    int imm8 = (((simde_test_codegen_rand() & 15) << 4) | round_type[i % 5]) & 255;
    simde__m512d r;
    SIMDE_CONSTIFY_256_(simde_mm512_roundscale_pd, r, simde_mm512_setzero_pd(), imm8, a);

    simde_test_x86_write_f64x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_codegen_write_i32(2, imm8, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f64x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm512_mask_roundscale_pd (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde_float64 src[8];
    const simde__mmask8 k;
    const simde_float64 a[8];
    const int32_t imm8;
    const simde_float64 r[8];
  } test_vec[] = {
    { { SIMDE_FLOAT64_C(  -157.27), SIMDE_FLOAT64_C(   107.68), SIMDE_FLOAT64_C(   630.83), SIMDE_FLOAT64_C(  -905.04),
        SIMDE_FLOAT64_C(  -496.50), SIMDE_FLOAT64_C(   850.05), SIMDE_FLOAT64_C(  -847.15), SIMDE_FLOAT64_C(  -488.99) },
      UINT8_C( 82),
      { SIMDE_FLOAT64_C(    92.08),        SIMDE_MATH_INFINITY, SIMDE_FLOAT64_C(   673.37), SIMDE_FLOAT64_C(  -818.01),
        SIMDE_FLOAT64_C(  -755.51), SIMDE_FLOAT64_C(  -570.18), SIMDE_FLOAT64_C(  -127.51), SIMDE_FLOAT64_C(    50.84) },
       INT32_C(         192),
      { SIMDE_FLOAT64_C(  -157.27),        SIMDE_MATH_INFINITY, SIMDE_FLOAT64_C(   630.83), SIMDE_FLOAT64_C(  -905.04),
        SIMDE_FLOAT64_C(  -755.51), SIMDE_FLOAT64_C(   850.05), SIMDE_FLOAT64_C(  -127.51), SIMDE_FLOAT64_C(  -488.99) } },
    { { SIMDE_FLOAT64_C(  -447.85), SIMDE_FLOAT64_C(  -701.14), SIMDE_FLOAT64_C(   316.16), SIMDE_FLOAT64_C(   117.46),
        SIMDE_FLOAT64_C(   360.05), SIMDE_FLOAT64_C(   -16.49), SIMDE_FLOAT64_C(   900.84), SIMDE_FLOAT64_C(  -215.65) },
      UINT8_C(133),
      { SIMDE_FLOAT64_C(   239.19), SIMDE_FLOAT64_C(   627.08), SIMDE_FLOAT64_C(   817.84), SIMDE_FLOAT64_C(  -129.99),
        SIMDE_FLOAT64_C(   722.04), SIMDE_FLOAT64_C(  -678.66), SIMDE_FLOAT64_C(  -279.94), SIMDE_FLOAT64_C(   874.89) },
       INT32_C(          81),
      { SIMDE_FLOAT64_C(   239.19), SIMDE_FLOAT64_C(  -701.14), SIMDE_FLOAT64_C(   817.81), SIMDE_FLOAT64_C(   117.46),
        SIMDE_FLOAT64_C(   360.05), SIMDE_FLOAT64_C(   -16.49), SIMDE_FLOAT64_C(   900.84), SIMDE_FLOAT64_C(   874.88) } },
    { { SIMDE_FLOAT64_C(   -33.03), SIMDE_FLOAT64_C(  -990.49), SIMDE_FLOAT64_C(  -243.90), SIMDE_FLOAT64_C(   148.97),
        SIMDE_FLOAT64_C(  -746.00), SIMDE_FLOAT64_C(   185.92), SIMDE_FLOAT64_C(  -978.54), SIMDE_FLOAT64_C(   304.84) },
      UINT8_C(135),
      { SIMDE_FLOAT64_C(   255.00), SIMDE_FLOAT64_C(   685.58), SIMDE_FLOAT64_C(  -123.66), SIMDE_FLOAT64_C(   807.15),
        SIMDE_FLOAT64_C(   984.44), SIMDE_FLOAT64_C(  -807.49), SIMDE_FLOAT64_C(   -75.38), SIMDE_FLOAT64_C(   344.49) },
       INT32_C(         242),
      { SIMDE_FLOAT64_C(   255.00), SIMDE_FLOAT64_C(   685.58), SIMDE_FLOAT64_C(  -123.66), SIMDE_FLOAT64_C(   148.97),
        SIMDE_FLOAT64_C(  -746.00), SIMDE_FLOAT64_C(   185.92), SIMDE_FLOAT64_C(  -978.54), SIMDE_FLOAT64_C(   344.49) } },
    { { SIMDE_FLOAT64_C(  -871.16), SIMDE_FLOAT64_C(   886.18), SIMDE_FLOAT64_C(  -935.35), SIMDE_FLOAT64_C(   755.92),
        SIMDE_FLOAT64_C(   704.02), SIMDE_FLOAT64_C(   -65.34), SIMDE_FLOAT64_C(   477.96), SIMDE_FLOAT64_C(  -974.64) },
      UINT8_C( 57),
      { SIMDE_FLOAT64_C(   352.85), SIMDE_FLOAT64_C(  -142.29), SIMDE_FLOAT64_C(  -262.55), SIMDE_FLOAT64_C(  -680.18),
        SIMDE_FLOAT64_C(  -132.78), SIMDE_FLOAT64_C(   493.55), SIMDE_FLOAT64_C(   468.79), SIMDE_FLOAT64_C(   121.22) },
       INT32_C(          99),
      { SIMDE_FLOAT64_C(   352.84), SIMDE_FLOAT64_C(   886.18), SIMDE_FLOAT64_C(  -935.35), SIMDE_FLOAT64_C(  -680.17),
        SIMDE_FLOAT64_C(  -132.77), SIMDE_FLOAT64_C(   493.55), SIMDE_FLOAT64_C(   477.96), SIMDE_FLOAT64_C(  -974.64) } },
    { { SIMDE_FLOAT64_C(  -573.94), SIMDE_FLOAT64_C(   992.80), SIMDE_FLOAT64_C(  -254.75), SIMDE_FLOAT64_C(  -888.36),
        SIMDE_FLOAT64_C(  -130.86), SIMDE_FLOAT64_C(  -447.59), SIMDE_FLOAT64_C(  -903.92), SIMDE_FLOAT64_C(    61.65) },
      UINT8_C(208),
      { SIMDE_FLOAT64_C(   440.58), SIMDE_FLOAT64_C(  -762.33), SIMDE_FLOAT64_C(  -697.52), SIMDE_FLOAT64_C(   569.41),
        SIMDE_FLOAT64_C(  -876.15), SIMDE_FLOAT64_C(  -632.88), SIMDE_FLOAT64_C(   325.33), SIMDE_FLOAT64_C(   827.87) },
       INT32_C(           4),
      { SIMDE_FLOAT64_C(  -573.94), SIMDE_FLOAT64_C(   992.80), SIMDE_FLOAT64_C(  -254.75), SIMDE_FLOAT64_C(  -888.36),
        SIMDE_FLOAT64_C(  -876.00), SIMDE_FLOAT64_C(  -447.59), SIMDE_FLOAT64_C(   325.00), SIMDE_FLOAT64_C(   828.00) } },
    { { SIMDE_FLOAT64_C(   853.23), SIMDE_FLOAT64_C(   -43.49), SIMDE_FLOAT64_C(  -843.86), SIMDE_FLOAT64_C(  -289.06),
        SIMDE_FLOAT64_C(   693.96), SIMDE_FLOAT64_C(  -524.04), SIMDE_FLOAT64_C(   578.16), SIMDE_FLOAT64_C(   187.50) },
      UINT8_C( 25),
      { SIMDE_FLOAT64_C(  -300.62),        SIMDE_MATH_INFINITY, SIMDE_FLOAT64_C(   435.01), SIMDE_FLOAT64_C(   125.44),
        SIMDE_FLOAT64_C(   859.76), SIMDE_FLOAT64_C(  -819.74), SIMDE_FLOAT64_C(   237.08), SIMDE_FLOAT64_C(  -271.10) },
       INT32_C(         192),
      { SIMDE_FLOAT64_C(  -300.62), SIMDE_FLOAT64_C(   -43.49), SIMDE_FLOAT64_C(  -843.86), SIMDE_FLOAT64_C(   125.44),
        SIMDE_FLOAT64_C(   859.76), SIMDE_FLOAT64_C(  -524.04), SIMDE_FLOAT64_C(   578.16), SIMDE_FLOAT64_C(   187.50) } },
    { { SIMDE_FLOAT64_C(  -226.26), SIMDE_FLOAT64_C(  -971.78), SIMDE_FLOAT64_C(  -487.83), SIMDE_FLOAT64_C(  -656.85),
        SIMDE_FLOAT64_C(  -847.93), SIMDE_FLOAT64_C(  -120.71), SIMDE_FLOAT64_C(   668.48), SIMDE_FLOAT64_C(   979.94) },
      UINT8_C( 89),
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   833.17), SIMDE_FLOAT64_C(   137.58), SIMDE_FLOAT64_C(  -372.09),
        SIMDE_FLOAT64_C(  -455.89), SIMDE_FLOAT64_C(  -168.46), SIMDE_FLOAT64_C(   103.87), SIMDE_FLOAT64_C(  -877.73) },
       INT32_C(         177),
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(  -971.78), SIMDE_FLOAT64_C(  -487.83), SIMDE_FLOAT64_C(  -372.09),
        SIMDE_FLOAT64_C(  -455.89), SIMDE_FLOAT64_C(  -120.71), SIMDE_FLOAT64_C(   103.87), SIMDE_FLOAT64_C(   979.94) } },
    { { SIMDE_FLOAT64_C(   886.00), SIMDE_FLOAT64_C(  -516.36), SIMDE_FLOAT64_C(   947.10), SIMDE_FLOAT64_C(   745.77),
        SIMDE_FLOAT64_C(  -336.10), SIMDE_FLOAT64_C(   184.18), SIMDE_FLOAT64_C(  -525.33), SIMDE_FLOAT64_C(   396.56) },
      UINT8_C(254),
      { SIMDE_FLOAT64_C(  -734.78), SIMDE_FLOAT64_C(   606.25), SIMDE_FLOAT64_C(   291.08), SIMDE_FLOAT64_C(  -706.55),
        SIMDE_FLOAT64_C(  -881.59), SIMDE_FLOAT64_C(   634.23), SIMDE_FLOAT64_C(  -554.48), SIMDE_FLOAT64_C(    -2.30) },
       INT32_C(         178),
      { SIMDE_FLOAT64_C(   886.00), SIMDE_FLOAT64_C(   606.25), SIMDE_FLOAT64_C(   291.08), SIMDE_FLOAT64_C(  -706.55),
        SIMDE_FLOAT64_C(  -881.59), SIMDE_FLOAT64_C(   634.23), SIMDE_FLOAT64_C(  -554.48), SIMDE_FLOAT64_C(    -2.30) } },
  };

  simde__m512d src, a, r;

  src = simde_mm512_loadu_pd(test_vec[0].src);
  a = simde_mm512_loadu_pd(test_vec[0].a);
  r = simde_mm512_mask_roundscale_pd(src, test_vec[0].k, a, INT32_C(         192));
  simde_test_x86_assert_equal_f64x8(r, simde_mm512_loadu_pd(test_vec[0].r), 1);

  src = simde_mm512_loadu_pd(test_vec[1].src);
  a = simde_mm512_loadu_pd(test_vec[1].a);
  r = simde_mm512_mask_roundscale_pd(src, test_vec[1].k, a, INT32_C(          81));
  simde_test_x86_assert_equal_f64x8(r, simde_mm512_loadu_pd(test_vec[1].r), 1);

  src = simde_mm512_loadu_pd(test_vec[2].src);
  a = simde_mm512_loadu_pd(test_vec[2].a);
  r = simde_mm512_mask_roundscale_pd(src, test_vec[2].k, a, INT32_C(         242));
  simde_test_x86_assert_equal_f64x8(r, simde_mm512_loadu_pd(test_vec[2].r), 1);

  src = simde_mm512_loadu_pd(test_vec[3].src);
  a = simde_mm512_loadu_pd(test_vec[3].a);
  r = simde_mm512_mask_roundscale_pd(src, test_vec[3].k, a, INT32_C(          99));
  simde_test_x86_assert_equal_f64x8(r, simde_mm512_loadu_pd(test_vec[3].r), 1);

  src = simde_mm512_loadu_pd(test_vec[4].src);
  a = simde_mm512_loadu_pd(test_vec[4].a);
  r = simde_mm512_mask_roundscale_pd(src, test_vec[4].k, a, INT32_C(           4));
  simde_test_x86_assert_equal_f64x8(r, simde_mm512_loadu_pd(test_vec[4].r), 1);

  src = simde_mm512_loadu_pd(test_vec[5].src);
  a = simde_mm512_loadu_pd(test_vec[5].a);
  r = simde_mm512_mask_roundscale_pd(src, test_vec[5].k, a, INT32_C(         192));
  simde_test_x86_assert_equal_f64x8(r, simde_mm512_loadu_pd(test_vec[5].r), 1);

  #if !defined(SIMDE_FAST_MATH)
  src = simde_mm512_loadu_pd(test_vec[6].src);
  a = simde_mm512_loadu_pd(test_vec[6].a);
  r = simde_mm512_mask_roundscale_pd(src, test_vec[6].k, a, INT32_C(         177));
  simde_test_x86_assert_equal_f64x8(r, simde_mm512_loadu_pd(test_vec[6].r), 1);
  #endif

  src = simde_mm512_loadu_pd(test_vec[7].src);
  a = simde_mm512_loadu_pd(test_vec[7].a);
  r = simde_mm512_mask_roundscale_pd(src, test_vec[7].k, a, INT32_C(         178));
  simde_test_x86_assert_equal_f64x8(r, simde_mm512_loadu_pd(test_vec[7].r), 1);

  return 0;
#else
  fputc('\n', stdout);
  int round_type[5] = {SIMDE_MM_FROUND_TO_NEAREST_INT, SIMDE_MM_FROUND_TO_NEG_INF, SIMDE_MM_FROUND_TO_POS_INF, SIMDE_MM_FROUND_TO_ZERO, SIMDE_MM_FROUND_CUR_DIRECTION};
  for (int i = 0 ; i < 8 ; i++) {
    simde__m512d src = simde_test_x86_random_f64x8(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
    simde__mmask8 k = simde_test_x86_random_mmask8();
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
    int imm8 = (((simde_test_codegen_rand() & 15) << 4) | round_type[i % 5]) & 255;
    simde__m512d r;
    SIMDE_CONSTIFY_256_(simde_mm512_mask_roundscale_pd, r, simde_mm512_setzero_pd(), imm8, src, k, a);

    simde_test_x86_write_f64x8(2, src, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f64x8(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, imm8, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f64x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm512_maskz_roundscale_pd (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask8 k;
    const simde_float64 a[8];
    const int32_t imm8;
    const simde_float64 r[8];
  } test_vec[] = {
    { UINT8_C(216),
      { SIMDE_FLOAT64_C(   774.48), SIMDE_FLOAT64_C(  -741.37), SIMDE_FLOAT64_C(  -683.64), SIMDE_FLOAT64_C(  -597.61),
        SIMDE_FLOAT64_C(  -197.26), SIMDE_FLOAT64_C(   147.89), SIMDE_FLOAT64_C(   506.26), SIMDE_FLOAT64_C(   -74.98) },
       INT32_C(         160),
      { SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(  -597.61),
        SIMDE_FLOAT64_C(  -197.26), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(   506.26), SIMDE_FLOAT64_C(   -74.98) } },
    { UINT8_C(243),
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(    38.53), SIMDE_FLOAT64_C(   693.77), SIMDE_FLOAT64_C(  -201.30),
        SIMDE_FLOAT64_C(   702.42), SIMDE_FLOAT64_C(  -122.05), SIMDE_FLOAT64_C(   273.37), SIMDE_FLOAT64_C(    98.98) },
       INT32_C(         145),
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(    38.53), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00),
        SIMDE_FLOAT64_C(   702.42), SIMDE_FLOAT64_C(  -122.05), SIMDE_FLOAT64_C(   273.37), SIMDE_FLOAT64_C(    98.98) } },
    { UINT8_C( 32),
      { SIMDE_FLOAT64_C(   832.04), SIMDE_FLOAT64_C(  -176.36), SIMDE_FLOAT64_C(  -679.40), SIMDE_FLOAT64_C(  -722.44),
        SIMDE_FLOAT64_C(   821.34), SIMDE_FLOAT64_C(   623.31), SIMDE_FLOAT64_C(  -296.98), SIMDE_FLOAT64_C(     0.12) },
       INT32_C(         242),
      { SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00),
        SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(   623.31), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00) } },
    { UINT8_C( 37),
      { SIMDE_FLOAT64_C(   800.18), SIMDE_FLOAT64_C(   764.40), SIMDE_FLOAT64_C(  -535.63), SIMDE_FLOAT64_C(   306.44),
        SIMDE_FLOAT64_C(  -310.58), SIMDE_FLOAT64_C(   631.30), SIMDE_FLOAT64_C(   861.33), SIMDE_FLOAT64_C(  -563.91) },
       INT32_C(          67),
      { SIMDE_FLOAT64_C(   800.12), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(  -535.62), SIMDE_FLOAT64_C(     0.00),
        SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(   631.25), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00) } },
    { UINT8_C(113),
      { SIMDE_FLOAT64_C(   482.93),       -SIMDE_MATH_INFINITY, SIMDE_FLOAT64_C(     7.81), SIMDE_FLOAT64_C(  -243.70),
        SIMDE_FLOAT64_C(   701.26), SIMDE_FLOAT64_C(  -596.90), SIMDE_FLOAT64_C(  -705.10), SIMDE_FLOAT64_C(  -593.51) },
       INT32_C(         164),
      { SIMDE_FLOAT64_C(   482.93), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00),
        SIMDE_FLOAT64_C(   701.26), SIMDE_FLOAT64_C(  -596.90), SIMDE_FLOAT64_C(  -705.10), SIMDE_FLOAT64_C(     0.00) } },
    { UINT8_C(137),
      { SIMDE_FLOAT64_C(    51.46),       -SIMDE_MATH_INFINITY, SIMDE_FLOAT64_C(   107.51), SIMDE_FLOAT64_C(  -948.42),
        SIMDE_FLOAT64_C(  -568.82), SIMDE_FLOAT64_C(  -930.83), SIMDE_FLOAT64_C(   368.05), SIMDE_FLOAT64_C(  -768.64) },
       INT32_C(          64),
      { SIMDE_FLOAT64_C(    51.44), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(  -948.44),
        SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(  -768.62) } },
    { UINT8_C(245),
      { SIMDE_FLOAT64_C(   399.14), SIMDE_FLOAT64_C(   -40.92), SIMDE_FLOAT64_C(  -852.05), SIMDE_FLOAT64_C(  -701.01),
        SIMDE_FLOAT64_C(    88.94), SIMDE_FLOAT64_C(   630.88), SIMDE_FLOAT64_C(   -98.73), SIMDE_FLOAT64_C(  -903.25) },
       INT32_C(         225),
      { SIMDE_FLOAT64_C(   399.14), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(  -852.05), SIMDE_FLOAT64_C(     0.00),
        SIMDE_FLOAT64_C(    88.94), SIMDE_FLOAT64_C(   630.88), SIMDE_FLOAT64_C(   -98.73), SIMDE_FLOAT64_C(  -903.25) } },
    { UINT8_C( 71),
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(     9.01), SIMDE_FLOAT64_C(   589.32), SIMDE_FLOAT64_C(  -190.99),
        SIMDE_FLOAT64_C(  -760.86), SIMDE_FLOAT64_C(    -0.61), SIMDE_FLOAT64_C(   213.50), SIMDE_FLOAT64_C(   290.60) },
       INT32_C(         210),
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(     9.01), SIMDE_FLOAT64_C(   589.32), SIMDE_FLOAT64_C(     0.00),
        SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(   213.50), SIMDE_FLOAT64_C(     0.00) } },
  };

  simde__m512d a, r;

  a = simde_mm512_loadu_pd(test_vec[0].a);
  r = simde_mm512_maskz_roundscale_pd(test_vec[0].k, a, INT32_C(         160));
  simde_test_x86_assert_equal_f64x8(r, simde_mm512_loadu_pd(test_vec[0].r), 1);

  #if !defined(SIMDE_FAST_MATH)
  a = simde_mm512_loadu_pd(test_vec[1].a);
  r = simde_mm512_maskz_roundscale_pd(test_vec[1].k, a, INT32_C(         145));
  simde_test_x86_assert_equal_f64x8(r, simde_mm512_loadu_pd(test_vec[1].r), 1);
  #endif

  a = simde_mm512_loadu_pd(test_vec[2].a);
  r = simde_mm512_maskz_roundscale_pd(test_vec[2].k, a, INT32_C(         242));
  simde_test_x86_assert_equal_f64x8(r, simde_mm512_loadu_pd(test_vec[2].r), 1);

  a = simde_mm512_loadu_pd(test_vec[3].a);
  r = simde_mm512_maskz_roundscale_pd(test_vec[3].k, a, INT32_C(          67));
  simde_test_x86_assert_equal_f64x8(r, simde_mm512_loadu_pd(test_vec[3].r), 1);

  a = simde_mm512_loadu_pd(test_vec[4].a);
  r = simde_mm512_maskz_roundscale_pd(test_vec[4].k, a, INT32_C(         164));
  simde_test_x86_assert_equal_f64x8(r, simde_mm512_loadu_pd(test_vec[4].r), 1);

  a = simde_mm512_loadu_pd(test_vec[5].a);
  r = simde_mm512_maskz_roundscale_pd(test_vec[5].k, a, INT32_C(          64));
  simde_test_x86_assert_equal_f64x8(r, simde_mm512_loadu_pd(test_vec[5].r), 1);

  a = simde_mm512_loadu_pd(test_vec[6].a);
  r = simde_mm512_maskz_roundscale_pd(test_vec[6].k, a, INT32_C(         225));
  simde_test_x86_assert_equal_f64x8(r, simde_mm512_loadu_pd(test_vec[6].r), 1);

  #if !defined(SIMDE_FAST_MATH)
  a = simde_mm512_loadu_pd(test_vec[7].a);
  r = simde_mm512_maskz_roundscale_pd(test_vec[7].k, a, INT32_C(         210));
  simde_test_x86_assert_equal_f64x8(r, simde_mm512_loadu_pd(test_vec[7].r), 1);
  #endif

  return 0;
#else
  fputc('\n', stdout);
  int round_type[5] = {SIMDE_MM_FROUND_TO_NEAREST_INT, SIMDE_MM_FROUND_TO_NEG_INF, SIMDE_MM_FROUND_TO_POS_INF, SIMDE_MM_FROUND_TO_ZERO, SIMDE_MM_FROUND_CUR_DIRECTION};
  for (int i = 0 ; i < 8 ; i++) {
    simde__mmask8 k = simde_test_x86_random_mmask8();
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
    int imm8 = (((simde_test_codegen_rand() & 15) << 4) | round_type[i % 5]) & 255;
    simde__m512d r;
    SIMDE_CONSTIFY_256_(simde_mm512_maskz_roundscale_pd, r, simde_mm512_setzero_pd(), imm8, k, a);

    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_f64x8(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, imm8, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f64x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_roundscale_ss (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde_float32 a[4];
    const simde_float32 b[4];
    const int32_t imm8;
    const simde_float32 r[4];
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(   822.63), SIMDE_FLOAT32_C(   440.98), SIMDE_FLOAT32_C(    -7.85), SIMDE_FLOAT32_C(   646.73) },
      { SIMDE_FLOAT32_C(   446.35), SIMDE_FLOAT32_C(  -293.17), SIMDE_FLOAT32_C(   587.62), SIMDE_FLOAT32_C(   860.34) },
       INT32_C(           0),
      { SIMDE_FLOAT32_C(   446.00), SIMDE_FLOAT32_C(   440.98), SIMDE_FLOAT32_C(    -7.85), SIMDE_FLOAT32_C(   646.73) } },
    { { SIMDE_FLOAT32_C(    14.68), SIMDE_FLOAT32_C(   115.83), SIMDE_FLOAT32_C(   -68.33), SIMDE_FLOAT32_C(   366.87) },
      { SIMDE_FLOAT32_C(  -324.24), SIMDE_FLOAT32_C(  -488.69), SIMDE_FLOAT32_C(   -87.18), SIMDE_FLOAT32_C(  -980.26) },
       INT32_C(          16),
      { SIMDE_FLOAT32_C(  -324.00), SIMDE_FLOAT32_C(   115.83), SIMDE_FLOAT32_C(   -68.33), SIMDE_FLOAT32_C(   366.87) } },
    { { SIMDE_FLOAT32_C(   673.86), SIMDE_FLOAT32_C(   884.60), SIMDE_FLOAT32_C(   702.77), SIMDE_FLOAT32_C(  -321.62) },
      { SIMDE_FLOAT32_C(  -887.81), SIMDE_FLOAT32_C(   897.13), SIMDE_FLOAT32_C(   967.53), SIMDE_FLOAT32_C(  -824.56) },
       INT32_C(          32),
      { SIMDE_FLOAT32_C(  -887.75), SIMDE_FLOAT32_C(   884.60), SIMDE_FLOAT32_C(   702.77), SIMDE_FLOAT32_C(  -321.62) } },
    { { SIMDE_FLOAT32_C(  -444.99), SIMDE_FLOAT32_C(   531.19), SIMDE_FLOAT32_C(  -158.59), SIMDE_FLOAT32_C(   -20.00) },
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -717.61), SIMDE_FLOAT32_C(   972.15), SIMDE_FLOAT32_C(     0.55) },
       INT32_C(          48),
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   531.19), SIMDE_FLOAT32_C(  -158.59), SIMDE_FLOAT32_C(   -20.00) } },
    { { SIMDE_FLOAT32_C(  -411.83), SIMDE_FLOAT32_C(   589.09), SIMDE_FLOAT32_C(   577.76), SIMDE_FLOAT32_C(   602.85) },
      { SIMDE_FLOAT32_C(  -295.09), SIMDE_FLOAT32_C(  -490.58), SIMDE_FLOAT32_C(   -30.29), SIMDE_FLOAT32_C(   380.68) },
       INT32_C(          64),
      { SIMDE_FLOAT32_C(  -295.06), SIMDE_FLOAT32_C(   589.09), SIMDE_FLOAT32_C(   577.76), SIMDE_FLOAT32_C(   602.85) } },
    { { SIMDE_FLOAT32_C(   882.54), SIMDE_FLOAT32_C(   400.42), SIMDE_FLOAT32_C(  -726.72), SIMDE_FLOAT32_C(   556.40) },
      {      SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(   976.05), SIMDE_FLOAT32_C(  -765.22), SIMDE_FLOAT32_C(   397.20) },
       INT32_C(          80),
      {      SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(   400.42), SIMDE_FLOAT32_C(  -726.72), SIMDE_FLOAT32_C(   556.40) } },
    { { SIMDE_FLOAT32_C(  -105.81), SIMDE_FLOAT32_C(  -242.69), SIMDE_FLOAT32_C(   103.84), SIMDE_FLOAT32_C(   735.60) },
      {     -SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(  -542.34), SIMDE_FLOAT32_C(  -982.01), SIMDE_FLOAT32_C(   709.46) },
       INT32_C(          96),
      {     -SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(  -242.69), SIMDE_FLOAT32_C(   103.84), SIMDE_FLOAT32_C(   735.60) } },
    { { SIMDE_FLOAT32_C(  -953.62), SIMDE_FLOAT32_C(   335.83), SIMDE_FLOAT32_C(   966.20), SIMDE_FLOAT32_C(   649.22) },
      { SIMDE_FLOAT32_C(  -959.26), SIMDE_FLOAT32_C(  -524.38), SIMDE_FLOAT32_C(  -381.06), SIMDE_FLOAT32_C(   421.42) },
       INT32_C(         112),
      { SIMDE_FLOAT32_C(  -959.26), SIMDE_FLOAT32_C(   335.83), SIMDE_FLOAT32_C(   966.20), SIMDE_FLOAT32_C(   649.22) } },
    { { SIMDE_FLOAT32_C(  -498.52), SIMDE_FLOAT32_C(  -178.17), SIMDE_FLOAT32_C(   769.63), SIMDE_FLOAT32_C(  -942.12) },
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   745.68), SIMDE_FLOAT32_C(  -707.34), SIMDE_FLOAT32_C(   504.05) },
       INT32_C(         128),
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -178.17), SIMDE_FLOAT32_C(   769.63), SIMDE_FLOAT32_C(  -942.12) } },
    { { SIMDE_FLOAT32_C(    76.70), SIMDE_FLOAT32_C(  -486.95), SIMDE_FLOAT32_C(   252.28), SIMDE_FLOAT32_C(  -819.47) },
      { SIMDE_FLOAT32_C(  -751.35), SIMDE_FLOAT32_C(   -10.40), SIMDE_FLOAT32_C(  -361.81), SIMDE_FLOAT32_C(  -733.36) },
       INT32_C(         144),
      { SIMDE_FLOAT32_C(  -751.35), SIMDE_FLOAT32_C(  -486.95), SIMDE_FLOAT32_C(   252.28), SIMDE_FLOAT32_C(  -819.47) } },
    { { SIMDE_FLOAT32_C(  -903.60), SIMDE_FLOAT32_C(  -986.62), SIMDE_FLOAT32_C(    87.50), SIMDE_FLOAT32_C(  -857.23) },
      { SIMDE_FLOAT32_C(   349.21), SIMDE_FLOAT32_C(    53.70), SIMDE_FLOAT32_C(   792.00), SIMDE_FLOAT32_C(   389.95) },
       INT32_C(         160),
      { SIMDE_FLOAT32_C(   349.21), SIMDE_FLOAT32_C(  -986.62), SIMDE_FLOAT32_C(    87.50), SIMDE_FLOAT32_C(  -857.23) } },
    { { SIMDE_FLOAT32_C(  -589.06), SIMDE_FLOAT32_C(  -188.63), SIMDE_FLOAT32_C(    25.67), SIMDE_FLOAT32_C(   -87.58) },
      { SIMDE_FLOAT32_C(   633.20), SIMDE_FLOAT32_C(  -204.71), SIMDE_FLOAT32_C(   -29.71), SIMDE_FLOAT32_C(   740.05) },
       INT32_C(         176),
      { SIMDE_FLOAT32_C(   633.20), SIMDE_FLOAT32_C(  -188.63), SIMDE_FLOAT32_C(    25.67), SIMDE_FLOAT32_C(   -87.58) } },
    { { SIMDE_FLOAT32_C(   262.95), SIMDE_FLOAT32_C(   244.10), SIMDE_FLOAT32_C(  -840.17), SIMDE_FLOAT32_C(   757.92) },
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -327.12), SIMDE_FLOAT32_C(    10.20), SIMDE_FLOAT32_C(  -498.67) },
       INT32_C(         192),
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   244.10), SIMDE_FLOAT32_C(  -840.17), SIMDE_FLOAT32_C(   757.92) } },
    { { SIMDE_FLOAT32_C(   139.52), SIMDE_FLOAT32_C(   188.17), SIMDE_FLOAT32_C(  -301.15), SIMDE_FLOAT32_C(   235.91) },
      { SIMDE_FLOAT32_C(   201.55), SIMDE_FLOAT32_C(   786.35), SIMDE_FLOAT32_C(   378.69), SIMDE_FLOAT32_C(  -449.24) },
       INT32_C(         208),
      { SIMDE_FLOAT32_C(   201.55), SIMDE_FLOAT32_C(   188.17), SIMDE_FLOAT32_C(  -301.15), SIMDE_FLOAT32_C(   235.91) } },
    { { SIMDE_FLOAT32_C(   170.69), SIMDE_FLOAT32_C(   940.71), SIMDE_FLOAT32_C(  -630.64), SIMDE_FLOAT32_C(   581.62) },
      { SIMDE_FLOAT32_C(  -247.93), SIMDE_FLOAT32_C(   395.03), SIMDE_FLOAT32_C(  -505.96), SIMDE_FLOAT32_C(  -614.73) },
       INT32_C(         224),
      { SIMDE_FLOAT32_C(  -247.93), SIMDE_FLOAT32_C(   940.71), SIMDE_FLOAT32_C(  -630.64), SIMDE_FLOAT32_C(   581.62) } },
    { { SIMDE_FLOAT32_C(   464.33), SIMDE_FLOAT32_C(  -874.68), SIMDE_FLOAT32_C(  -268.70), SIMDE_FLOAT32_C(  -272.72) },
      { SIMDE_FLOAT32_C(   369.41), SIMDE_FLOAT32_C(  -108.87), SIMDE_FLOAT32_C(  -514.80), SIMDE_FLOAT32_C(   690.21) },
       INT32_C(         240),
      { SIMDE_FLOAT32_C(   369.41), SIMDE_FLOAT32_C(  -874.68), SIMDE_FLOAT32_C(  -268.70), SIMDE_FLOAT32_C(  -272.72) } },
    { { SIMDE_FLOAT32_C(   495.39), SIMDE_FLOAT32_C(  -808.46), SIMDE_FLOAT32_C(  -514.46), SIMDE_FLOAT32_C(   495.19) },
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   673.71), SIMDE_FLOAT32_C(  -805.96), SIMDE_FLOAT32_C(  -433.04) },
       INT32_C(           1),
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -808.46), SIMDE_FLOAT32_C(  -514.46), SIMDE_FLOAT32_C(   495.19) } },
    { { SIMDE_FLOAT32_C(   945.65), SIMDE_FLOAT32_C(   426.02), SIMDE_FLOAT32_C(  -179.56), SIMDE_FLOAT32_C(   116.34) },
      {      SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(   189.80), SIMDE_FLOAT32_C(  -302.04), SIMDE_FLOAT32_C(  -881.20) },
       INT32_C(          17),
      {      SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(   426.02), SIMDE_FLOAT32_C(  -179.56), SIMDE_FLOAT32_C(   116.34) } },
    { { SIMDE_FLOAT32_C(  -224.85), SIMDE_FLOAT32_C(  -343.67), SIMDE_FLOAT32_C(  -370.62), SIMDE_FLOAT32_C(   506.44) },
      { SIMDE_FLOAT32_C(   383.61), SIMDE_FLOAT32_C(   998.80), SIMDE_FLOAT32_C(  -602.43), SIMDE_FLOAT32_C(   868.80) },
       INT32_C(          33),
      { SIMDE_FLOAT32_C(   383.50), SIMDE_FLOAT32_C(  -343.67), SIMDE_FLOAT32_C(  -370.62), SIMDE_FLOAT32_C(   506.44) } },
    { { SIMDE_FLOAT32_C(   961.58), SIMDE_FLOAT32_C(   364.20), SIMDE_FLOAT32_C(   880.54), SIMDE_FLOAT32_C(  -552.88) },
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   211.59), SIMDE_FLOAT32_C(  -879.17), SIMDE_FLOAT32_C(    53.42) },
       INT32_C(          49),
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   364.20), SIMDE_FLOAT32_C(   880.54), SIMDE_FLOAT32_C(  -552.88) } },
    { { SIMDE_FLOAT32_C(    33.81), SIMDE_FLOAT32_C(   724.21), SIMDE_FLOAT32_C(  -577.89), SIMDE_FLOAT32_C(   854.25) },
      {      SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(   788.83), SIMDE_FLOAT32_C(    44.04), SIMDE_FLOAT32_C(   538.50) },
       INT32_C(          65),
      {      SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(   724.21), SIMDE_FLOAT32_C(  -577.89), SIMDE_FLOAT32_C(   854.25) } },
    { { SIMDE_FLOAT32_C(  -588.30), SIMDE_FLOAT32_C(  -595.98), SIMDE_FLOAT32_C(   386.83), SIMDE_FLOAT32_C(    41.08) },
      { SIMDE_FLOAT32_C(   910.46), SIMDE_FLOAT32_C(  -229.56), SIMDE_FLOAT32_C(    39.88), SIMDE_FLOAT32_C(  -691.97) },
       INT32_C(          81),
      { SIMDE_FLOAT32_C(   910.44), SIMDE_FLOAT32_C(  -595.98), SIMDE_FLOAT32_C(   386.83), SIMDE_FLOAT32_C(    41.08) } },
    { { SIMDE_FLOAT32_C(  -271.12), SIMDE_FLOAT32_C(  -730.39), SIMDE_FLOAT32_C(  -996.56), SIMDE_FLOAT32_C(  -390.58) },
      {     -SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(  -137.18), SIMDE_FLOAT32_C(   821.01), SIMDE_FLOAT32_C(  -162.44) },
       INT32_C(          97),
      {     -SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(  -730.39), SIMDE_FLOAT32_C(  -996.56), SIMDE_FLOAT32_C(  -390.58) } },
    { { SIMDE_FLOAT32_C(   -49.95), SIMDE_FLOAT32_C(   323.78), SIMDE_FLOAT32_C(  -744.24), SIMDE_FLOAT32_C(  -195.70) },
      { SIMDE_FLOAT32_C(  -835.68), SIMDE_FLOAT32_C(  -955.41), SIMDE_FLOAT32_C(   848.34), SIMDE_FLOAT32_C(   702.82) },
       INT32_C(         113),
      { SIMDE_FLOAT32_C(  -835.69), SIMDE_FLOAT32_C(   323.78), SIMDE_FLOAT32_C(  -744.24), SIMDE_FLOAT32_C(  -195.70) } },
    { { SIMDE_FLOAT32_C(   477.21), SIMDE_FLOAT32_C(  -566.68), SIMDE_FLOAT32_C(  -636.08), SIMDE_FLOAT32_C(   881.23) },
      { SIMDE_FLOAT32_C(   820.15), SIMDE_FLOAT32_C(   405.00), SIMDE_FLOAT32_C(   791.69), SIMDE_FLOAT32_C(  -409.41) },
       INT32_C(         129),
      { SIMDE_FLOAT32_C(   820.15), SIMDE_FLOAT32_C(  -566.68), SIMDE_FLOAT32_C(  -636.08), SIMDE_FLOAT32_C(   881.23) } },
    { { SIMDE_FLOAT32_C(  -900.28), SIMDE_FLOAT32_C(   229.83), SIMDE_FLOAT32_C(   173.76), SIMDE_FLOAT32_C(  -630.67) },
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   783.18), SIMDE_FLOAT32_C(    86.06), SIMDE_FLOAT32_C(  -903.91) },
       INT32_C(         145),
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   229.83), SIMDE_FLOAT32_C(   173.76), SIMDE_FLOAT32_C(  -630.67) } },
    { { SIMDE_FLOAT32_C(  -987.67), SIMDE_FLOAT32_C(   203.76), SIMDE_FLOAT32_C(   757.27), SIMDE_FLOAT32_C(   -37.61) },
      {      SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(  -986.97), SIMDE_FLOAT32_C(   766.68), SIMDE_FLOAT32_C(  -308.15) },
       INT32_C(         161),
      {      SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(   203.76), SIMDE_FLOAT32_C(   757.27), SIMDE_FLOAT32_C(   -37.61) } },
    { { SIMDE_FLOAT32_C(  -990.16), SIMDE_FLOAT32_C(    92.24), SIMDE_FLOAT32_C(  -172.00), SIMDE_FLOAT32_C(  -626.25) },
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -351.85), SIMDE_FLOAT32_C(   778.75), SIMDE_FLOAT32_C(  -234.84) },
       INT32_C(         177),
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(    92.24), SIMDE_FLOAT32_C(  -172.00), SIMDE_FLOAT32_C(  -626.25) } },
    { { SIMDE_FLOAT32_C(  -135.13), SIMDE_FLOAT32_C(  -531.43), SIMDE_FLOAT32_C(   397.38), SIMDE_FLOAT32_C(   234.20) },
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   180.56), SIMDE_FLOAT32_C(  -679.74), SIMDE_FLOAT32_C(   797.93) },
       INT32_C(         193),
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -531.43), SIMDE_FLOAT32_C(   397.38), SIMDE_FLOAT32_C(   234.20) } },
    { { SIMDE_FLOAT32_C(   810.27), SIMDE_FLOAT32_C(   988.51), SIMDE_FLOAT32_C(  -998.85), SIMDE_FLOAT32_C(  -227.35) },
      {     -SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(  -985.82), SIMDE_FLOAT32_C(  -460.66), SIMDE_FLOAT32_C(   207.90) },
       INT32_C(         209),
      {     -SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(   988.51), SIMDE_FLOAT32_C(  -998.85), SIMDE_FLOAT32_C(  -227.35) } },
    { { SIMDE_FLOAT32_C(  -918.36), SIMDE_FLOAT32_C(   246.61), SIMDE_FLOAT32_C(  -569.43), SIMDE_FLOAT32_C(  -544.61) },
      { SIMDE_FLOAT32_C(  -779.92), SIMDE_FLOAT32_C(    78.72), SIMDE_FLOAT32_C(  -765.86), SIMDE_FLOAT32_C(   -14.77) },
       INT32_C(         225),
      { SIMDE_FLOAT32_C(  -779.92), SIMDE_FLOAT32_C(   246.61), SIMDE_FLOAT32_C(  -569.43), SIMDE_FLOAT32_C(  -544.61) } },
    { { SIMDE_FLOAT32_C(  -542.23), SIMDE_FLOAT32_C(   850.11), SIMDE_FLOAT32_C(  -213.97), SIMDE_FLOAT32_C(   855.15) },
      { SIMDE_FLOAT32_C(    84.31), SIMDE_FLOAT32_C(  -512.14), SIMDE_FLOAT32_C(    35.71), SIMDE_FLOAT32_C(   404.57) },
       INT32_C(         241),
      { SIMDE_FLOAT32_C(    84.31), SIMDE_FLOAT32_C(   850.11), SIMDE_FLOAT32_C(  -213.97), SIMDE_FLOAT32_C(   855.15) } },
    { { SIMDE_FLOAT32_C(   820.46), SIMDE_FLOAT32_C(   648.45), SIMDE_FLOAT32_C(  -903.94), SIMDE_FLOAT32_C(   808.97) },
      { SIMDE_FLOAT32_C(   649.61), SIMDE_FLOAT32_C(  -131.28), SIMDE_FLOAT32_C(  -674.98), SIMDE_FLOAT32_C(   663.79) },
       INT32_C(           2),
      { SIMDE_FLOAT32_C(   650.00), SIMDE_FLOAT32_C(   648.45), SIMDE_FLOAT32_C(  -903.94), SIMDE_FLOAT32_C(   808.97) } },
    { { SIMDE_FLOAT32_C(   532.92), SIMDE_FLOAT32_C(   735.59), SIMDE_FLOAT32_C(   562.42), SIMDE_FLOAT32_C(   135.50) },
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -190.97), SIMDE_FLOAT32_C(   566.07), SIMDE_FLOAT32_C(  -727.38) },
       INT32_C(          18),
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   735.59), SIMDE_FLOAT32_C(   562.42), SIMDE_FLOAT32_C(   135.50) } },
    { { SIMDE_FLOAT32_C(  -493.23), SIMDE_FLOAT32_C(  -985.67), SIMDE_FLOAT32_C(   -37.75), SIMDE_FLOAT32_C(   -35.47) },
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   748.28), SIMDE_FLOAT32_C(  -180.32), SIMDE_FLOAT32_C(   -51.25) },
       INT32_C(          34),
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -985.67), SIMDE_FLOAT32_C(   -37.75), SIMDE_FLOAT32_C(   -35.47) } },
    { { SIMDE_FLOAT32_C(  -646.68), SIMDE_FLOAT32_C(  -478.07), SIMDE_FLOAT32_C(   675.84), SIMDE_FLOAT32_C(  -998.23) },
      { SIMDE_FLOAT32_C(  -382.00), SIMDE_FLOAT32_C(   484.81), SIMDE_FLOAT32_C(   651.37), SIMDE_FLOAT32_C(   486.71) },
       INT32_C(          50),
      { SIMDE_FLOAT32_C(  -382.00), SIMDE_FLOAT32_C(  -478.07), SIMDE_FLOAT32_C(   675.84), SIMDE_FLOAT32_C(  -998.23) } },
    { { SIMDE_FLOAT32_C(   315.16), SIMDE_FLOAT32_C(  -105.23), SIMDE_FLOAT32_C(   342.75), SIMDE_FLOAT32_C(    50.75) },
      { SIMDE_FLOAT32_C(  -542.82), SIMDE_FLOAT32_C(  -521.75), SIMDE_FLOAT32_C(  -132.02), SIMDE_FLOAT32_C(   266.21) },
       INT32_C(          66),
      { SIMDE_FLOAT32_C(  -542.81), SIMDE_FLOAT32_C(  -105.23), SIMDE_FLOAT32_C(   342.75), SIMDE_FLOAT32_C(    50.75) } },
    { { SIMDE_FLOAT32_C(   140.61), SIMDE_FLOAT32_C(  -704.69), SIMDE_FLOAT32_C(  -310.89), SIMDE_FLOAT32_C(   647.37) },
      {      SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(   651.36), SIMDE_FLOAT32_C(  -388.09), SIMDE_FLOAT32_C(  -825.91) },
       INT32_C(          82),
      {      SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(  -704.69), SIMDE_FLOAT32_C(  -310.89), SIMDE_FLOAT32_C(   647.37) } },
    { { SIMDE_FLOAT32_C(   635.78), SIMDE_FLOAT32_C(   286.97), SIMDE_FLOAT32_C(   476.15), SIMDE_FLOAT32_C(  -842.29) },
      { SIMDE_FLOAT32_C(   -37.18), SIMDE_FLOAT32_C(   477.92), SIMDE_FLOAT32_C(  -224.29), SIMDE_FLOAT32_C(  -552.37) },
       INT32_C(          98),
      { SIMDE_FLOAT32_C(   -37.17), SIMDE_FLOAT32_C(   286.97), SIMDE_FLOAT32_C(   476.15), SIMDE_FLOAT32_C(  -842.29) } },
    { { SIMDE_FLOAT32_C(  -737.58), SIMDE_FLOAT32_C(  -742.54), SIMDE_FLOAT32_C(  -555.54), SIMDE_FLOAT32_C(   157.18) },
      { SIMDE_FLOAT32_C(   600.21), SIMDE_FLOAT32_C(   495.21), SIMDE_FLOAT32_C(   614.37), SIMDE_FLOAT32_C(  -921.55) },
       INT32_C(         114),
      { SIMDE_FLOAT32_C(   600.21), SIMDE_FLOAT32_C(  -742.54), SIMDE_FLOAT32_C(  -555.54), SIMDE_FLOAT32_C(   157.18) } },
    { { SIMDE_FLOAT32_C(  -119.42), SIMDE_FLOAT32_C(  -877.23), SIMDE_FLOAT32_C(   503.80), SIMDE_FLOAT32_C(   175.89) },
      {     -SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(   151.17), SIMDE_FLOAT32_C(   485.54), SIMDE_FLOAT32_C(  -536.76) },
       INT32_C(         130),
      {     -SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(  -877.23), SIMDE_FLOAT32_C(   503.80), SIMDE_FLOAT32_C(   175.89) } },
    { { SIMDE_FLOAT32_C(   194.66), SIMDE_FLOAT32_C(  -217.55), SIMDE_FLOAT32_C(   498.65), SIMDE_FLOAT32_C(  -518.36) },
      { SIMDE_FLOAT32_C(  -741.39), SIMDE_FLOAT32_C(   656.36), SIMDE_FLOAT32_C(   444.45), SIMDE_FLOAT32_C(   736.52) },
       INT32_C(         146),
      { SIMDE_FLOAT32_C(  -741.39), SIMDE_FLOAT32_C(  -217.55), SIMDE_FLOAT32_C(   498.65), SIMDE_FLOAT32_C(  -518.36) } },
    { { SIMDE_FLOAT32_C(   892.08), SIMDE_FLOAT32_C(  -134.18), SIMDE_FLOAT32_C(  -305.51), SIMDE_FLOAT32_C(  -850.46) },
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   851.67), SIMDE_FLOAT32_C(   749.75), SIMDE_FLOAT32_C(  -194.51) },
       INT32_C(         162),
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -134.18), SIMDE_FLOAT32_C(  -305.51), SIMDE_FLOAT32_C(  -850.46) } },
    { { SIMDE_FLOAT32_C(   168.68), SIMDE_FLOAT32_C(  -653.38), SIMDE_FLOAT32_C(   950.97), SIMDE_FLOAT32_C(  -327.52) },
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -237.14), SIMDE_FLOAT32_C(   823.66), SIMDE_FLOAT32_C(     8.05) },
       INT32_C(         178),
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -653.38), SIMDE_FLOAT32_C(   950.97), SIMDE_FLOAT32_C(  -327.52) } },
    { { SIMDE_FLOAT32_C(  -332.33), SIMDE_FLOAT32_C(    88.98), SIMDE_FLOAT32_C(  -218.60), SIMDE_FLOAT32_C(   450.13) },
      {     -SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(   263.04), SIMDE_FLOAT32_C(   708.73), SIMDE_FLOAT32_C(  -756.01) },
       INT32_C(         194),
      {     -SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(    88.98), SIMDE_FLOAT32_C(  -218.60), SIMDE_FLOAT32_C(   450.13) } },
    { { SIMDE_FLOAT32_C(  -400.43), SIMDE_FLOAT32_C(  -688.92), SIMDE_FLOAT32_C(   370.55), SIMDE_FLOAT32_C(  -250.89) },
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   222.23), SIMDE_FLOAT32_C(  -501.14), SIMDE_FLOAT32_C(  -573.16) },
       INT32_C(         210),
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -688.92), SIMDE_FLOAT32_C(   370.55), SIMDE_FLOAT32_C(  -250.89) } },
    { { SIMDE_FLOAT32_C(   595.53), SIMDE_FLOAT32_C(    34.89), SIMDE_FLOAT32_C(  -721.97), SIMDE_FLOAT32_C(  -731.99) },
      { SIMDE_FLOAT32_C(  -442.59), SIMDE_FLOAT32_C(    40.89), SIMDE_FLOAT32_C(  -908.33), SIMDE_FLOAT32_C(   565.46) },
       INT32_C(         226),
      { SIMDE_FLOAT32_C(  -442.59), SIMDE_FLOAT32_C(    34.89), SIMDE_FLOAT32_C(  -721.97), SIMDE_FLOAT32_C(  -731.99) } },
    { { SIMDE_FLOAT32_C(   678.40), SIMDE_FLOAT32_C(  -766.87), SIMDE_FLOAT32_C(   355.96), SIMDE_FLOAT32_C(  -540.20) },
      { SIMDE_FLOAT32_C(   683.26), SIMDE_FLOAT32_C(   943.59), SIMDE_FLOAT32_C(   722.84), SIMDE_FLOAT32_C(   391.99) },
       INT32_C(         242),
      { SIMDE_FLOAT32_C(   683.26), SIMDE_FLOAT32_C(  -766.87), SIMDE_FLOAT32_C(   355.96), SIMDE_FLOAT32_C(  -540.20) } },
    { { SIMDE_FLOAT32_C(  -569.67), SIMDE_FLOAT32_C(  -162.75), SIMDE_FLOAT32_C(  -136.35), SIMDE_FLOAT32_C(    29.90) },
      { SIMDE_FLOAT32_C(   148.32), SIMDE_FLOAT32_C(  -765.79), SIMDE_FLOAT32_C(   779.01), SIMDE_FLOAT32_C(  -230.32) },
       INT32_C(           3),
      { SIMDE_FLOAT32_C(   148.00), SIMDE_FLOAT32_C(  -162.75), SIMDE_FLOAT32_C(  -136.35), SIMDE_FLOAT32_C(    29.90) } },
    { { SIMDE_FLOAT32_C(  -722.13), SIMDE_FLOAT32_C(   196.52), SIMDE_FLOAT32_C(  -855.30), SIMDE_FLOAT32_C(  -395.08) },
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   179.60), SIMDE_FLOAT32_C(  -117.04), SIMDE_FLOAT32_C(    60.06) },
       INT32_C(          19),
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   196.52), SIMDE_FLOAT32_C(  -855.30), SIMDE_FLOAT32_C(  -395.08) } },
    { { SIMDE_FLOAT32_C(   151.73), SIMDE_FLOAT32_C(   302.46), SIMDE_FLOAT32_C(  -809.17), SIMDE_FLOAT32_C(  -169.87) },
      {      SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(   546.80), SIMDE_FLOAT32_C(   289.94), SIMDE_FLOAT32_C(   218.85) },
       INT32_C(          35),
      {      SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(   302.46), SIMDE_FLOAT32_C(  -809.17), SIMDE_FLOAT32_C(  -169.87) } },
    { { SIMDE_FLOAT32_C(   677.98), SIMDE_FLOAT32_C(   443.10), SIMDE_FLOAT32_C(   448.09), SIMDE_FLOAT32_C(  -458.37) },
      { SIMDE_FLOAT32_C(  -527.00), SIMDE_FLOAT32_C(  -403.59), SIMDE_FLOAT32_C(  -224.16), SIMDE_FLOAT32_C(  -748.00) },
       INT32_C(          51),
      { SIMDE_FLOAT32_C(  -527.00), SIMDE_FLOAT32_C(   443.10), SIMDE_FLOAT32_C(   448.09), SIMDE_FLOAT32_C(  -458.37) } },
    { { SIMDE_FLOAT32_C(  -767.73), SIMDE_FLOAT32_C(  -470.13), SIMDE_FLOAT32_C(  -437.39), SIMDE_FLOAT32_C(  -623.03) },
      { SIMDE_FLOAT32_C(   134.79), SIMDE_FLOAT32_C(   354.66), SIMDE_FLOAT32_C(   556.57), SIMDE_FLOAT32_C(  -982.25) },
       INT32_C(          67),
      { SIMDE_FLOAT32_C(   134.75), SIMDE_FLOAT32_C(  -470.13), SIMDE_FLOAT32_C(  -437.39), SIMDE_FLOAT32_C(  -623.03) } },
    { { SIMDE_FLOAT32_C(   293.57), SIMDE_FLOAT32_C(   941.60), SIMDE_FLOAT32_C(   566.45), SIMDE_FLOAT32_C(  -403.97) },
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -603.41), SIMDE_FLOAT32_C(  -868.37), SIMDE_FLOAT32_C(   679.23) },
       INT32_C(          83),
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   941.60), SIMDE_FLOAT32_C(   566.45), SIMDE_FLOAT32_C(  -403.97) } },
    { { SIMDE_FLOAT32_C(   169.62), SIMDE_FLOAT32_C(  -300.70), SIMDE_FLOAT32_C(   961.31), SIMDE_FLOAT32_C(  -152.40) },
      { SIMDE_FLOAT32_C(  -857.60), SIMDE_FLOAT32_C(   409.40), SIMDE_FLOAT32_C(   389.23), SIMDE_FLOAT32_C(  -384.61) },
       INT32_C(          99),
      { SIMDE_FLOAT32_C(  -857.59), SIMDE_FLOAT32_C(  -300.70), SIMDE_FLOAT32_C(   961.31), SIMDE_FLOAT32_C(  -152.40) } },
    { { SIMDE_FLOAT32_C(  -834.93), SIMDE_FLOAT32_C(  -132.61), SIMDE_FLOAT32_C(   371.90), SIMDE_FLOAT32_C(  -602.66) },
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   934.51), SIMDE_FLOAT32_C(  -225.69), SIMDE_FLOAT32_C(  -467.95) },
       INT32_C(         115),
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -132.61), SIMDE_FLOAT32_C(   371.90), SIMDE_FLOAT32_C(  -602.66) } },
    { { SIMDE_FLOAT32_C(  -450.20), SIMDE_FLOAT32_C(   703.89), SIMDE_FLOAT32_C(   624.45), SIMDE_FLOAT32_C(  -508.60) },
      {     -SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(  -779.51), SIMDE_FLOAT32_C(  -376.17), SIMDE_FLOAT32_C(   666.94) },
       INT32_C(         131),
      {     -SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(   703.89), SIMDE_FLOAT32_C(   624.45), SIMDE_FLOAT32_C(  -508.60) } },
    { { SIMDE_FLOAT32_C(   702.59), SIMDE_FLOAT32_C(   472.68), SIMDE_FLOAT32_C(  -947.24), SIMDE_FLOAT32_C(   663.90) },
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -804.85), SIMDE_FLOAT32_C(    73.30), SIMDE_FLOAT32_C(   709.52) },
       INT32_C(         147),
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   472.68), SIMDE_FLOAT32_C(  -947.24), SIMDE_FLOAT32_C(   663.90) } },
    { { SIMDE_FLOAT32_C(   874.59), SIMDE_FLOAT32_C(   677.94), SIMDE_FLOAT32_C(  -548.99), SIMDE_FLOAT32_C(  -728.07) },
      {      SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(  -614.48), SIMDE_FLOAT32_C(    46.24), SIMDE_FLOAT32_C(   607.25) },
       INT32_C(         163),
      {      SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(   677.94), SIMDE_FLOAT32_C(  -548.99), SIMDE_FLOAT32_C(  -728.07) } },
    { { SIMDE_FLOAT32_C(   378.59), SIMDE_FLOAT32_C(     1.58), SIMDE_FLOAT32_C(  -351.54), SIMDE_FLOAT32_C(  -351.06) },
      { SIMDE_FLOAT32_C(   222.07), SIMDE_FLOAT32_C(   272.29), SIMDE_FLOAT32_C(  -684.12), SIMDE_FLOAT32_C(   574.18) },
       INT32_C(         179),
      { SIMDE_FLOAT32_C(   222.07), SIMDE_FLOAT32_C(     1.58), SIMDE_FLOAT32_C(  -351.54), SIMDE_FLOAT32_C(  -351.06) } },
    { { SIMDE_FLOAT32_C(   669.34), SIMDE_FLOAT32_C(   276.77), SIMDE_FLOAT32_C(    48.04), SIMDE_FLOAT32_C(   722.09) },
      { SIMDE_FLOAT32_C(   -59.33), SIMDE_FLOAT32_C(   368.32), SIMDE_FLOAT32_C(   917.25), SIMDE_FLOAT32_C(  -986.02) },
       INT32_C(         195),
      { SIMDE_FLOAT32_C(   -59.33), SIMDE_FLOAT32_C(   276.77), SIMDE_FLOAT32_C(    48.04), SIMDE_FLOAT32_C(   722.09) } },
    { { SIMDE_FLOAT32_C(  -272.21), SIMDE_FLOAT32_C(    93.09), SIMDE_FLOAT32_C(   -47.57), SIMDE_FLOAT32_C(  -594.27) },
      { SIMDE_FLOAT32_C(   544.11), SIMDE_FLOAT32_C(   224.35), SIMDE_FLOAT32_C(   480.93), SIMDE_FLOAT32_C(   929.63) },
       INT32_C(         211),
      { SIMDE_FLOAT32_C(   544.11), SIMDE_FLOAT32_C(    93.09), SIMDE_FLOAT32_C(   -47.57), SIMDE_FLOAT32_C(  -594.27) } },
    { { SIMDE_FLOAT32_C(    88.18), SIMDE_FLOAT32_C(   604.33), SIMDE_FLOAT32_C(   647.72), SIMDE_FLOAT32_C(   245.24) },
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -350.71), SIMDE_FLOAT32_C(   893.70), SIMDE_FLOAT32_C(   631.86) },
       INT32_C(         227),
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   604.33), SIMDE_FLOAT32_C(   647.72), SIMDE_FLOAT32_C(   245.24) } },
    { { SIMDE_FLOAT32_C(   947.73), SIMDE_FLOAT32_C(   445.54), SIMDE_FLOAT32_C(  -258.65), SIMDE_FLOAT32_C(   617.07) },
      { SIMDE_FLOAT32_C(  -277.69), SIMDE_FLOAT32_C(   789.38), SIMDE_FLOAT32_C(   339.16), SIMDE_FLOAT32_C(   662.98) },
       INT32_C(         243),
      { SIMDE_FLOAT32_C(  -277.69), SIMDE_FLOAT32_C(   445.54), SIMDE_FLOAT32_C(  -258.65), SIMDE_FLOAT32_C(   617.07) } },
    { { SIMDE_FLOAT32_C(   256.41), SIMDE_FLOAT32_C(   676.96), SIMDE_FLOAT32_C(  -764.46), SIMDE_FLOAT32_C(   984.20) },
      { SIMDE_FLOAT32_C(  -229.94), SIMDE_FLOAT32_C(   187.97), SIMDE_FLOAT32_C(  -610.07), SIMDE_FLOAT32_C(  -685.83) },
       INT32_C(           4),
      { SIMDE_FLOAT32_C(  -230.00), SIMDE_FLOAT32_C(   676.96), SIMDE_FLOAT32_C(  -764.46), SIMDE_FLOAT32_C(   984.20) } },
    { { SIMDE_FLOAT32_C(   870.86), SIMDE_FLOAT32_C(  -756.20), SIMDE_FLOAT32_C(  -317.08), SIMDE_FLOAT32_C(   -40.96) },
      {     -SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(  -669.37), SIMDE_FLOAT32_C(  -795.72), SIMDE_FLOAT32_C(  -168.95) },
       INT32_C(          20),
      {     -SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(  -756.20), SIMDE_FLOAT32_C(  -317.08), SIMDE_FLOAT32_C(   -40.96) } },
    { { SIMDE_FLOAT32_C(  -148.72), SIMDE_FLOAT32_C(   263.97), SIMDE_FLOAT32_C(  -589.36), SIMDE_FLOAT32_C(  -703.18) },
      { SIMDE_FLOAT32_C(  -994.68), SIMDE_FLOAT32_C(  -972.29), SIMDE_FLOAT32_C(    19.13), SIMDE_FLOAT32_C(   794.70) },
       INT32_C(          36),
      { SIMDE_FLOAT32_C(  -994.75), SIMDE_FLOAT32_C(   263.97), SIMDE_FLOAT32_C(  -589.36), SIMDE_FLOAT32_C(  -703.18) } },
    { { SIMDE_FLOAT32_C(  -317.88), SIMDE_FLOAT32_C(   -47.60), SIMDE_FLOAT32_C(  -376.72), SIMDE_FLOAT32_C(  -640.92) },
      { SIMDE_FLOAT32_C(   187.95), SIMDE_FLOAT32_C(  -392.52), SIMDE_FLOAT32_C(   129.14), SIMDE_FLOAT32_C(  -624.08) },
       INT32_C(          52),
      { SIMDE_FLOAT32_C(   188.00), SIMDE_FLOAT32_C(   -47.60), SIMDE_FLOAT32_C(  -376.72), SIMDE_FLOAT32_C(  -640.92) } },
    { { SIMDE_FLOAT32_C(   443.31), SIMDE_FLOAT32_C(  -211.76), SIMDE_FLOAT32_C(  -131.74), SIMDE_FLOAT32_C(   687.10) },
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   827.30), SIMDE_FLOAT32_C(   535.23), SIMDE_FLOAT32_C(   801.79) },
       INT32_C(          68),
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -211.76), SIMDE_FLOAT32_C(  -131.74), SIMDE_FLOAT32_C(   687.10) } },
    { { SIMDE_FLOAT32_C(  -218.29), SIMDE_FLOAT32_C(  -870.44), SIMDE_FLOAT32_C(  -170.82), SIMDE_FLOAT32_C(   633.00) },
      {     -SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(   239.82), SIMDE_FLOAT32_C(   929.82), SIMDE_FLOAT32_C(   398.84) },
       INT32_C(          84),
      {     -SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(  -870.44), SIMDE_FLOAT32_C(  -170.82), SIMDE_FLOAT32_C(   633.00) } },
    { { SIMDE_FLOAT32_C(  -365.60), SIMDE_FLOAT32_C(   631.08), SIMDE_FLOAT32_C(  -854.05), SIMDE_FLOAT32_C(   257.67) },
      {     -SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(   333.90), SIMDE_FLOAT32_C(   865.15), SIMDE_FLOAT32_C(   119.30) },
       INT32_C(         100),
      {     -SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(   631.08), SIMDE_FLOAT32_C(  -854.05), SIMDE_FLOAT32_C(   257.67) } },
    { { SIMDE_FLOAT32_C(  -501.95), SIMDE_FLOAT32_C(   730.83), SIMDE_FLOAT32_C(  -750.29), SIMDE_FLOAT32_C(   969.21) },
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   784.94), SIMDE_FLOAT32_C(   771.00), SIMDE_FLOAT32_C(   589.71) },
       INT32_C(         116),
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   730.83), SIMDE_FLOAT32_C(  -750.29), SIMDE_FLOAT32_C(   969.21) } },
    { { SIMDE_FLOAT32_C(   719.27), SIMDE_FLOAT32_C(   -19.60), SIMDE_FLOAT32_C(  -814.29), SIMDE_FLOAT32_C(   112.80) },
      { SIMDE_FLOAT32_C(  -779.77), SIMDE_FLOAT32_C(  -884.47), SIMDE_FLOAT32_C(  -488.36), SIMDE_FLOAT32_C(   487.75) },
       INT32_C(         132),
      { SIMDE_FLOAT32_C(  -779.77), SIMDE_FLOAT32_C(   -19.60), SIMDE_FLOAT32_C(  -814.29), SIMDE_FLOAT32_C(   112.80) } },
    { { SIMDE_FLOAT32_C(   705.18), SIMDE_FLOAT32_C(  -877.85), SIMDE_FLOAT32_C(  -304.44), SIMDE_FLOAT32_C(   851.13) },
      { SIMDE_FLOAT32_C(   379.82), SIMDE_FLOAT32_C(  -314.28), SIMDE_FLOAT32_C(   185.03), SIMDE_FLOAT32_C(   244.98) },
       INT32_C(         148),
      { SIMDE_FLOAT32_C(   379.82), SIMDE_FLOAT32_C(  -877.85), SIMDE_FLOAT32_C(  -304.44), SIMDE_FLOAT32_C(   851.13) } },
    { { SIMDE_FLOAT32_C(  -105.16), SIMDE_FLOAT32_C(  -892.46), SIMDE_FLOAT32_C(  -632.37), SIMDE_FLOAT32_C(   392.89) },
      {      SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(  -382.66), SIMDE_FLOAT32_C(   362.10), SIMDE_FLOAT32_C(   396.50) },
       INT32_C(         164),
      {      SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(  -892.46), SIMDE_FLOAT32_C(  -632.37), SIMDE_FLOAT32_C(   392.89) } },
    { { SIMDE_FLOAT32_C(  -446.50), SIMDE_FLOAT32_C(   685.81), SIMDE_FLOAT32_C(  -294.53), SIMDE_FLOAT32_C(   533.91) },
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   818.27), SIMDE_FLOAT32_C(   754.13), SIMDE_FLOAT32_C(   987.04) },
       INT32_C(         180),
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   685.81), SIMDE_FLOAT32_C(  -294.53), SIMDE_FLOAT32_C(   533.91) } },
    { { SIMDE_FLOAT32_C(    51.52), SIMDE_FLOAT32_C(  -964.91), SIMDE_FLOAT32_C(   364.03), SIMDE_FLOAT32_C(   747.08) },
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -256.14), SIMDE_FLOAT32_C(  -567.20), SIMDE_FLOAT32_C(    71.25) },
       INT32_C(         196),
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -964.91), SIMDE_FLOAT32_C(   364.03), SIMDE_FLOAT32_C(   747.08) } },
    { { SIMDE_FLOAT32_C(   966.09), SIMDE_FLOAT32_C(  -903.63), SIMDE_FLOAT32_C(  -394.56), SIMDE_FLOAT32_C(   358.98) },
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   222.78), SIMDE_FLOAT32_C(  -278.91), SIMDE_FLOAT32_C(   331.23) },
       INT32_C(         212),
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -903.63), SIMDE_FLOAT32_C(  -394.56), SIMDE_FLOAT32_C(   358.98) } },
    { { SIMDE_FLOAT32_C(  -682.56), SIMDE_FLOAT32_C(  -821.44), SIMDE_FLOAT32_C(   539.99), SIMDE_FLOAT32_C(    22.92) },
      { SIMDE_FLOAT32_C(   712.47), SIMDE_FLOAT32_C(   411.50), SIMDE_FLOAT32_C(  -158.81), SIMDE_FLOAT32_C(   466.60) },
       INT32_C(         228),
      { SIMDE_FLOAT32_C(   712.47), SIMDE_FLOAT32_C(  -821.44), SIMDE_FLOAT32_C(   539.99), SIMDE_FLOAT32_C(    22.92) } },
    { { SIMDE_FLOAT32_C(   171.10), SIMDE_FLOAT32_C(  -291.52), SIMDE_FLOAT32_C(  -549.93), SIMDE_FLOAT32_C(   206.19) },
      { SIMDE_FLOAT32_C(  -927.48), SIMDE_FLOAT32_C(  -802.85), SIMDE_FLOAT32_C(    92.41), SIMDE_FLOAT32_C(  -183.62) },
       INT32_C(         244),
      { SIMDE_FLOAT32_C(  -927.48), SIMDE_FLOAT32_C(  -291.52), SIMDE_FLOAT32_C(  -549.93), SIMDE_FLOAT32_C(   206.19) } },
  };

  simde__m128 a, b, r;

  a = simde_mm_loadu_ps(test_vec[0].a);
  b = simde_mm_loadu_ps(test_vec[0].b);
  r = simde_mm_roundscale_ss(a, b, INT32_C(           0));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[0].r), 1);

  a = simde_mm_loadu_ps(test_vec[1].a);
  b = simde_mm_loadu_ps(test_vec[1].b);
  r = simde_mm_roundscale_ss(a, b, INT32_C(          16));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[1].r), 1);

  a = simde_mm_loadu_ps(test_vec[2].a);
  b = simde_mm_loadu_ps(test_vec[2].b);
  r = simde_mm_roundscale_ss(a, b, INT32_C(          32));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[2].r), 1);

  #if !defined(SIMDE_FAST_MATH)
  a = simde_mm_loadu_ps(test_vec[3].a);
  b = simde_mm_loadu_ps(test_vec[3].b);
  r = simde_mm_roundscale_ss(a, b, INT32_C(          48));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[3].r), 1);
  #endif

  a = simde_mm_loadu_ps(test_vec[4].a);
  b = simde_mm_loadu_ps(test_vec[4].b);
  r = simde_mm_roundscale_ss(a, b, INT32_C(          64));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[4].r), 1);

  a = simde_mm_loadu_ps(test_vec[5].a);
  b = simde_mm_loadu_ps(test_vec[5].b);
  r = simde_mm_roundscale_ss(a, b, INT32_C(          80));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[5].r), 1);

  a = simde_mm_loadu_ps(test_vec[6].a);
  b = simde_mm_loadu_ps(test_vec[6].b);
  r = simde_mm_roundscale_ss(a, b, INT32_C(          96));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[6].r), 1);

  a = simde_mm_loadu_ps(test_vec[7].a);
  b = simde_mm_loadu_ps(test_vec[7].b);
  r = simde_mm_roundscale_ss(a, b, INT32_C(         112));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[7].r), 1);

  #if !defined(SIMDE_FAST_MATH)
  a = simde_mm_loadu_ps(test_vec[8].a);
  b = simde_mm_loadu_ps(test_vec[8].b);
  r = simde_mm_roundscale_ss(a, b, INT32_C(         128));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[8].r), 1);
  #endif

  a = simde_mm_loadu_ps(test_vec[9].a);
  b = simde_mm_loadu_ps(test_vec[9].b);
  r = simde_mm_roundscale_ss(a, b, INT32_C(         144));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[9].r), 1);

  a = simde_mm_loadu_ps(test_vec[10].a);
  b = simde_mm_loadu_ps(test_vec[10].b);
  r = simde_mm_roundscale_ss(a, b, INT32_C(         160));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[10].r), 1);

  a = simde_mm_loadu_ps(test_vec[11].a);
  b = simde_mm_loadu_ps(test_vec[11].b);
  r = simde_mm_roundscale_ss(a, b, INT32_C(         176));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[11].r), 1);

  #if !defined(SIMDE_FAST_MATH)
  a = simde_mm_loadu_ps(test_vec[12].a);
  b = simde_mm_loadu_ps(test_vec[12].b);
  r = simde_mm_roundscale_ss(a, b, INT32_C(         192));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[12].r), 1);
  #endif

  a = simde_mm_loadu_ps(test_vec[13].a);
  b = simde_mm_loadu_ps(test_vec[13].b);
  r = simde_mm_roundscale_ss(a, b, INT32_C(         208));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[13].r), 1);

  a = simde_mm_loadu_ps(test_vec[14].a);
  b = simde_mm_loadu_ps(test_vec[14].b);
  r = simde_mm_roundscale_ss(a, b, INT32_C(         224));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[14].r), 1);

  a = simde_mm_loadu_ps(test_vec[15].a);
  b = simde_mm_loadu_ps(test_vec[15].b);
  r = simde_mm_roundscale_ss(a, b, INT32_C(         240));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[15].r), 1);

  #if !defined(SIMDE_FAST_MATH)
  a = simde_mm_loadu_ps(test_vec[16].a);
  b = simde_mm_loadu_ps(test_vec[16].b);
  r = simde_mm_roundscale_ss(a, b, INT32_C(           1));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[16].r), 1);
  #endif

  a = simde_mm_loadu_ps(test_vec[17].a);
  b = simde_mm_loadu_ps(test_vec[17].b);
  r = simde_mm_roundscale_ss(a, b, INT32_C(          17));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[17].r), 1);

  a = simde_mm_loadu_ps(test_vec[18].a);
  b = simde_mm_loadu_ps(test_vec[18].b);
  r = simde_mm_roundscale_ss(a, b, INT32_C(          33));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[18].r), 1);

  #if !defined(SIMDE_FAST_MATH)
  a = simde_mm_loadu_ps(test_vec[19].a);
  b = simde_mm_loadu_ps(test_vec[19].b);
  r = simde_mm_roundscale_ss(a, b, INT32_C(          49));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[19].r), 1);
  #endif

  a = simde_mm_loadu_ps(test_vec[20].a);
  b = simde_mm_loadu_ps(test_vec[20].b);
  r = simde_mm_roundscale_ss(a, b, INT32_C(          65));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[20].r), 1);

  a = simde_mm_loadu_ps(test_vec[21].a);
  b = simde_mm_loadu_ps(test_vec[21].b);
  r = simde_mm_roundscale_ss(a, b, INT32_C(          81));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[21].r), 1);

  a = simde_mm_loadu_ps(test_vec[22].a);
  b = simde_mm_loadu_ps(test_vec[22].b);
  r = simde_mm_roundscale_ss(a, b, INT32_C(          97));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[22].r), 1);

  a = simde_mm_loadu_ps(test_vec[23].a);
  b = simde_mm_loadu_ps(test_vec[23].b);
  r = simde_mm_roundscale_ss(a, b, INT32_C(         113));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[23].r), 1);

  a = simde_mm_loadu_ps(test_vec[24].a);
  b = simde_mm_loadu_ps(test_vec[24].b);
  r = simde_mm_roundscale_ss(a, b, INT32_C(         129));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[24].r), 1);

  #if !defined(SIMDE_FAST_MATH)
  a = simde_mm_loadu_ps(test_vec[25].a);
  b = simde_mm_loadu_ps(test_vec[25].b);
  r = simde_mm_roundscale_ss(a, b, INT32_C(         145));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[25].r), 1);
  #endif

  a = simde_mm_loadu_ps(test_vec[26].a);
  b = simde_mm_loadu_ps(test_vec[26].b);
  r = simde_mm_roundscale_ss(a, b, INT32_C(         161));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[26].r), 1);

  #if !defined(SIMDE_FAST_MATH)
  a = simde_mm_loadu_ps(test_vec[27].a);
  b = simde_mm_loadu_ps(test_vec[27].b);
  r = simde_mm_roundscale_ss(a, b, INT32_C(         177));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[27].r), 1);

  a = simde_mm_loadu_ps(test_vec[28].a);
  b = simde_mm_loadu_ps(test_vec[28].b);
  r = simde_mm_roundscale_ss(a, b, INT32_C(         193));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[28].r), 1);
  #endif

  a = simde_mm_loadu_ps(test_vec[29].a);
  b = simde_mm_loadu_ps(test_vec[29].b);
  r = simde_mm_roundscale_ss(a, b, INT32_C(         209));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[29].r), 1);

  a = simde_mm_loadu_ps(test_vec[30].a);
  b = simde_mm_loadu_ps(test_vec[30].b);
  r = simde_mm_roundscale_ss(a, b, INT32_C(         225));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[30].r), 1);

  a = simde_mm_loadu_ps(test_vec[31].a);
  b = simde_mm_loadu_ps(test_vec[31].b);
  r = simde_mm_roundscale_ss(a, b, INT32_C(         241));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[31].r), 1);

  a = simde_mm_loadu_ps(test_vec[32].a);
  b = simde_mm_loadu_ps(test_vec[32].b);
  r = simde_mm_roundscale_ss(a, b, INT32_C(           2));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[32].r), 1);

  #if !defined(SIMDE_FAST_MATH)
  a = simde_mm_loadu_ps(test_vec[33].a);
  b = simde_mm_loadu_ps(test_vec[33].b);
  r = simde_mm_roundscale_ss(a, b, INT32_C(          18));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[33].r), 1);

  a = simde_mm_loadu_ps(test_vec[34].a);
  b = simde_mm_loadu_ps(test_vec[34].b);
  r = simde_mm_roundscale_ss(a, b, INT32_C(          34));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[34].r), 1);
  #endif

  a = simde_mm_loadu_ps(test_vec[35].a);
  b = simde_mm_loadu_ps(test_vec[35].b);
  r = simde_mm_roundscale_ss(a, b, INT32_C(          50));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[35].r), 1);

  a = simde_mm_loadu_ps(test_vec[36].a);
  b = simde_mm_loadu_ps(test_vec[36].b);
  r = simde_mm_roundscale_ss(a, b, INT32_C(          66));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[36].r), 1);

  a = simde_mm_loadu_ps(test_vec[37].a);
  b = simde_mm_loadu_ps(test_vec[37].b);
  r = simde_mm_roundscale_ss(a, b, INT32_C(          82));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[37].r), 1);

  a = simde_mm_loadu_ps(test_vec[38].a);
  b = simde_mm_loadu_ps(test_vec[38].b);
  r = simde_mm_roundscale_ss(a, b, INT32_C(          98));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[38].r), 1);

  a = simde_mm_loadu_ps(test_vec[39].a);
  b = simde_mm_loadu_ps(test_vec[39].b);
  r = simde_mm_roundscale_ss(a, b, INT32_C(         114));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[39].r), 1);

  a = simde_mm_loadu_ps(test_vec[40].a);
  b = simde_mm_loadu_ps(test_vec[40].b);
  r = simde_mm_roundscale_ss(a, b, INT32_C(         130));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[40].r), 1);

  a = simde_mm_loadu_ps(test_vec[41].a);
  b = simde_mm_loadu_ps(test_vec[41].b);
  r = simde_mm_roundscale_ss(a, b, INT32_C(         146));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[41].r), 1);

  #if !defined(SIMDE_FAST_MATH)
  a = simde_mm_loadu_ps(test_vec[42].a);
  b = simde_mm_loadu_ps(test_vec[42].b);
  r = simde_mm_roundscale_ss(a, b, INT32_C(         162));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[42].r), 1);

  a = simde_mm_loadu_ps(test_vec[43].a);
  b = simde_mm_loadu_ps(test_vec[43].b);
  r = simde_mm_roundscale_ss(a, b, INT32_C(         178));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[43].r), 1);
  #endif

  a = simde_mm_loadu_ps(test_vec[44].a);
  b = simde_mm_loadu_ps(test_vec[44].b);
  r = simde_mm_roundscale_ss(a, b, INT32_C(         194));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[44].r), 1);

  #if !defined(SIMDE_FAST_MATH)
  a = simde_mm_loadu_ps(test_vec[45].a);
  b = simde_mm_loadu_ps(test_vec[45].b);
  r = simde_mm_roundscale_ss(a, b, INT32_C(         210));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[45].r), 1);
  #endif

  a = simde_mm_loadu_ps(test_vec[46].a);
  b = simde_mm_loadu_ps(test_vec[46].b);
  r = simde_mm_roundscale_ss(a, b, INT32_C(         226));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[46].r), 1);

  a = simde_mm_loadu_ps(test_vec[47].a);
  b = simde_mm_loadu_ps(test_vec[47].b);
  r = simde_mm_roundscale_ss(a, b, INT32_C(         242));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[47].r), 1);

  a = simde_mm_loadu_ps(test_vec[48].a);
  b = simde_mm_loadu_ps(test_vec[48].b);
  r = simde_mm_roundscale_ss(a, b, INT32_C(           3));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[48].r), 1);

  #if !defined(SIMDE_FAST_MATH)
  a = simde_mm_loadu_ps(test_vec[49].a);
  b = simde_mm_loadu_ps(test_vec[49].b);
  r = simde_mm_roundscale_ss(a, b, INT32_C(          19));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[49].r), 1);
  #endif

  a = simde_mm_loadu_ps(test_vec[50].a);
  b = simde_mm_loadu_ps(test_vec[50].b);
  r = simde_mm_roundscale_ss(a, b, INT32_C(          35));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[50].r), 1);

  a = simde_mm_loadu_ps(test_vec[51].a);
  b = simde_mm_loadu_ps(test_vec[51].b);
  r = simde_mm_roundscale_ss(a, b, INT32_C(          51));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[51].r), 1);

  a = simde_mm_loadu_ps(test_vec[52].a);
  b = simde_mm_loadu_ps(test_vec[52].b);
  r = simde_mm_roundscale_ss(a, b, INT32_C(          67));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[52].r), 1);

  #if !defined(SIMDE_FAST_MATH)
  a = simde_mm_loadu_ps(test_vec[53].a);
  b = simde_mm_loadu_ps(test_vec[53].b);
  r = simde_mm_roundscale_ss(a, b, INT32_C(          83));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[53].r), 1);
  #endif

  a = simde_mm_loadu_ps(test_vec[54].a);
  b = simde_mm_loadu_ps(test_vec[54].b);
  r = simde_mm_roundscale_ss(a, b, INT32_C(          99));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[54].r), 1);

  #if !defined(SIMDE_FAST_MATH)
  a = simde_mm_loadu_ps(test_vec[55].a);
  b = simde_mm_loadu_ps(test_vec[55].b);
  r = simde_mm_roundscale_ss(a, b, INT32_C(         115));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[55].r), 1);
  #endif

  a = simde_mm_loadu_ps(test_vec[56].a);
  b = simde_mm_loadu_ps(test_vec[56].b);
  r = simde_mm_roundscale_ss(a, b, INT32_C(         131));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[56].r), 1);

  #if !defined(SIMDE_FAST_MATH)
  a = simde_mm_loadu_ps(test_vec[57].a);
  b = simde_mm_loadu_ps(test_vec[57].b);
  r = simde_mm_roundscale_ss(a, b, INT32_C(         147));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[57].r), 1);
  #endif

  a = simde_mm_loadu_ps(test_vec[58].a);
  b = simde_mm_loadu_ps(test_vec[58].b);
  r = simde_mm_roundscale_ss(a, b, INT32_C(         163));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[58].r), 1);

  a = simde_mm_loadu_ps(test_vec[59].a);
  b = simde_mm_loadu_ps(test_vec[59].b);
  r = simde_mm_roundscale_ss(a, b, INT32_C(         179));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[59].r), 1);

  a = simde_mm_loadu_ps(test_vec[60].a);
  b = simde_mm_loadu_ps(test_vec[60].b);
  r = simde_mm_roundscale_ss(a, b, INT32_C(         195));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[60].r), 1);

  a = simde_mm_loadu_ps(test_vec[61].a);
  b = simde_mm_loadu_ps(test_vec[61].b);
  r = simde_mm_roundscale_ss(a, b, INT32_C(         211));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[61].r), 1);

  #if !defined(SIMDE_FAST_MATH)
  a = simde_mm_loadu_ps(test_vec[62].a);
  b = simde_mm_loadu_ps(test_vec[62].b);
  r = simde_mm_roundscale_ss(a, b, INT32_C(         227));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[62].r), 1);
  #endif

  a = simde_mm_loadu_ps(test_vec[63].a);
  b = simde_mm_loadu_ps(test_vec[63].b);
  r = simde_mm_roundscale_ss(a, b, INT32_C(         243));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[63].r), 1);

  a = simde_mm_loadu_ps(test_vec[64].a);
  b = simde_mm_loadu_ps(test_vec[64].b);
  r = simde_mm_roundscale_ss(a, b, INT32_C(           4));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[64].r), 1);

  a = simde_mm_loadu_ps(test_vec[65].a);
  b = simde_mm_loadu_ps(test_vec[65].b);
  r = simde_mm_roundscale_ss(a, b, INT32_C(          20));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[65].r), 1);

  a = simde_mm_loadu_ps(test_vec[66].a);
  b = simde_mm_loadu_ps(test_vec[66].b);
  r = simde_mm_roundscale_ss(a, b, INT32_C(          36));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[66].r), 1);

  a = simde_mm_loadu_ps(test_vec[67].a);
  b = simde_mm_loadu_ps(test_vec[67].b);
  r = simde_mm_roundscale_ss(a, b, INT32_C(          52));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[67].r), 1);

  #if !defined(SIMDE_FAST_MATH)
  a = simde_mm_loadu_ps(test_vec[68].a);
  b = simde_mm_loadu_ps(test_vec[68].b);
  r = simde_mm_roundscale_ss(a, b, INT32_C(          68));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[68].r), 1);
  #endif

  a = simde_mm_loadu_ps(test_vec[69].a);
  b = simde_mm_loadu_ps(test_vec[69].b);
  r = simde_mm_roundscale_ss(a, b, INT32_C(          84));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[69].r), 1);

  a = simde_mm_loadu_ps(test_vec[70].a);
  b = simde_mm_loadu_ps(test_vec[70].b);
  r = simde_mm_roundscale_ss(a, b, INT32_C(         100));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[70].r), 1);

  #if !defined(SIMDE_FAST_MATH)
  a = simde_mm_loadu_ps(test_vec[71].a);
  b = simde_mm_loadu_ps(test_vec[71].b);
  r = simde_mm_roundscale_ss(a, b, INT32_C(         116));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[71].r), 1);
  #endif

  a = simde_mm_loadu_ps(test_vec[72].a);
  b = simde_mm_loadu_ps(test_vec[72].b);
  r = simde_mm_roundscale_ss(a, b, INT32_C(         132));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[72].r), 1);

  a = simde_mm_loadu_ps(test_vec[73].a);
  b = simde_mm_loadu_ps(test_vec[73].b);
  r = simde_mm_roundscale_ss(a, b, INT32_C(         148));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[73].r), 1);

  a = simde_mm_loadu_ps(test_vec[74].a);
  b = simde_mm_loadu_ps(test_vec[74].b);
  r = simde_mm_roundscale_ss(a, b, INT32_C(         164));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[74].r), 1);

  #if !defined(SIMDE_FAST_MATH)
  a = simde_mm_loadu_ps(test_vec[75].a);
  b = simde_mm_loadu_ps(test_vec[75].b);
  r = simde_mm_roundscale_ss(a, b, INT32_C(         180));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[75].r), 1);

  a = simde_mm_loadu_ps(test_vec[76].a);
  b = simde_mm_loadu_ps(test_vec[76].b);
  r = simde_mm_roundscale_ss(a, b, INT32_C(         196));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[76].r), 1);

  a = simde_mm_loadu_ps(test_vec[77].a);
  b = simde_mm_loadu_ps(test_vec[77].b);
  r = simde_mm_roundscale_ss(a, b, INT32_C(         212));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[77].r), 1);
  #endif

  a = simde_mm_loadu_ps(test_vec[78].a);
  b = simde_mm_loadu_ps(test_vec[78].b);
  r = simde_mm_roundscale_ss(a, b, INT32_C(         228));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[78].r), 1);

  a = simde_mm_loadu_ps(test_vec[79].a);
  b = simde_mm_loadu_ps(test_vec[79].b);
  r = simde_mm_roundscale_ss(a, b, INT32_C(         244));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[79].r), 1);

  return 0;
#else
  fputc('\n', stdout);
  int round_type[5] = {SIMDE_MM_FROUND_TO_NEAREST_INT, SIMDE_MM_FROUND_TO_NEG_INF, SIMDE_MM_FROUND_TO_POS_INF, SIMDE_MM_FROUND_TO_ZERO, SIMDE_MM_FROUND_CUR_DIRECTION};
  for (int i = 0 ; i < 5 ; i++) {
    for (int j = 0 ; j < 16 ; j++) {
      simde__m128 a = simde_test_x86_random_f32x4(SIMDE_FLOAT32_C(-1000.0), SIMDE_FLOAT32_C(1000.0));
      simde__m128 b = simde_test_x86_random_f32x4(SIMDE_FLOAT32_C(-1000.0), SIMDE_FLOAT32_C(1000.0));
      if((simde_test_codegen_rand() & 1)) {
        if((simde_test_codegen_rand() & 1))
          b = simde_mm_mask_mov_ps(b, 1, simde_mm_set1_ps(SIMDE_MATH_NAN));
        else {
          if((simde_test_codegen_rand() & 1))
            b = simde_mm_mask_mov_ps(b, 1, simde_mm_set1_ps(SIMDE_MATH_INFINITY));
          else
            b = simde_mm_mask_mov_ps(b, 1, simde_mm_set1_ps(-SIMDE_MATH_INFINITY));
        }
      }
      int imm8 = ((j << 4) | round_type[i]) & 255;
      simde__m128 r;
      SIMDE_CONSTIFY_256_(simde_mm_roundscale_ss, r, simde_mm_setzero_ps(), imm8, a, b);

      simde_test_x86_write_f32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
      simde_test_x86_write_f32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
      simde_test_codegen_write_i32(2, imm8, SIMDE_TEST_VEC_POS_MIDDLE);
      simde_test_x86_write_f32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
    }
  }
  return 1;
#endif
}

static int
test_simde_mm_mask_roundscale_ss (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde_float32 src[4];
    const simde__mmask8 k;
    const simde_float32 a[4];
    const simde_float32 b[4];
    const int32_t imm8;
    const simde_float32 r[4];
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(  -866.00), SIMDE_FLOAT32_C(  -361.57), SIMDE_FLOAT32_C(  -516.74), SIMDE_FLOAT32_C(  -299.17) },
      UINT8_C(118),
      { SIMDE_FLOAT32_C(  -454.59), SIMDE_FLOAT32_C(   290.73), SIMDE_FLOAT32_C(   910.53), SIMDE_FLOAT32_C(    91.54) },
      { SIMDE_FLOAT32_C(   463.34), SIMDE_FLOAT32_C(   465.84), SIMDE_FLOAT32_C(  -211.43), SIMDE_FLOAT32_C(   429.04) },
       INT32_C(          96),
      { SIMDE_FLOAT32_C(  -866.00), SIMDE_FLOAT32_C(   290.73), SIMDE_FLOAT32_C(   910.53), SIMDE_FLOAT32_C(    91.54) } },
    { { SIMDE_FLOAT32_C(   762.35), SIMDE_FLOAT32_C(   -43.33), SIMDE_FLOAT32_C(  -810.77), SIMDE_FLOAT32_C(  -340.20) },
      UINT8_C(132),
      { SIMDE_FLOAT32_C(   433.68), SIMDE_FLOAT32_C(  -841.73), SIMDE_FLOAT32_C(  -334.46), SIMDE_FLOAT32_C(  -927.21) },
      { SIMDE_FLOAT32_C(   555.23), SIMDE_FLOAT32_C(   678.38), SIMDE_FLOAT32_C(   943.43), SIMDE_FLOAT32_C(  -947.24) },
       INT32_C(          17),
      { SIMDE_FLOAT32_C(   762.35), SIMDE_FLOAT32_C(  -841.73), SIMDE_FLOAT32_C(  -334.46), SIMDE_FLOAT32_C(  -927.21) } },
    { { SIMDE_FLOAT32_C(   523.07), SIMDE_FLOAT32_C(  -723.81), SIMDE_FLOAT32_C(   581.28), SIMDE_FLOAT32_C(  -993.68) },
      UINT8_C(145),
      { SIMDE_FLOAT32_C(  -438.97), SIMDE_FLOAT32_C(  -448.27), SIMDE_FLOAT32_C(  -732.25), SIMDE_FLOAT32_C(  -528.44) },
      { SIMDE_FLOAT32_C(   643.27), SIMDE_FLOAT32_C(   731.10), SIMDE_FLOAT32_C(   937.40), SIMDE_FLOAT32_C(  -568.16) },
       INT32_C(         130),
      { SIMDE_FLOAT32_C(   643.27), SIMDE_FLOAT32_C(  -448.27), SIMDE_FLOAT32_C(  -732.25), SIMDE_FLOAT32_C(  -528.44) } },
    { { SIMDE_FLOAT32_C(  -341.66), SIMDE_FLOAT32_C(   -77.52), SIMDE_FLOAT32_C(  -879.37), SIMDE_FLOAT32_C(  -152.44) },
      UINT8_C(247),
      { SIMDE_FLOAT32_C(   701.96), SIMDE_FLOAT32_C(  -718.75), SIMDE_FLOAT32_C(   740.54), SIMDE_FLOAT32_C(  -632.50) },
      { SIMDE_FLOAT32_C(  -645.96), SIMDE_FLOAT32_C(   295.77), SIMDE_FLOAT32_C(  -954.12), SIMDE_FLOAT32_C(  -702.53) },
       INT32_C(         227),
      { SIMDE_FLOAT32_C(  -645.96), SIMDE_FLOAT32_C(  -718.75), SIMDE_FLOAT32_C(   740.54), SIMDE_FLOAT32_C(  -632.50) } },
    { { SIMDE_FLOAT32_C(   240.32), SIMDE_FLOAT32_C(  -128.41), SIMDE_FLOAT32_C(  -535.73), SIMDE_FLOAT32_C(  -178.40) },
      UINT8_C( 78),
      { SIMDE_FLOAT32_C(   441.29), SIMDE_FLOAT32_C(   382.63), SIMDE_FLOAT32_C(   429.65), SIMDE_FLOAT32_C(   709.04) },
      { SIMDE_FLOAT32_C(   854.19), SIMDE_FLOAT32_C(    72.92), SIMDE_FLOAT32_C(   440.14), SIMDE_FLOAT32_C(   791.59) },
       INT32_C(         100),
      { SIMDE_FLOAT32_C(   240.32), SIMDE_FLOAT32_C(   382.63), SIMDE_FLOAT32_C(   429.65), SIMDE_FLOAT32_C(   709.04) } },
    { { SIMDE_FLOAT32_C(   -44.45), SIMDE_FLOAT32_C(  -836.91), SIMDE_FLOAT32_C(   522.76), SIMDE_FLOAT32_C(    76.18) },
      UINT8_C(115),
      { SIMDE_FLOAT32_C(   105.03), SIMDE_FLOAT32_C(  -221.86), SIMDE_FLOAT32_C(   291.90), SIMDE_FLOAT32_C(  -154.42) },
      { SIMDE_FLOAT32_C(   145.64), SIMDE_FLOAT32_C(   645.93), SIMDE_FLOAT32_C(  -858.66), SIMDE_FLOAT32_C(   191.53) },
       INT32_C(          48),
      { SIMDE_FLOAT32_C(   145.62), SIMDE_FLOAT32_C(  -221.86), SIMDE_FLOAT32_C(   291.90), SIMDE_FLOAT32_C(  -154.42) } },
    { { SIMDE_FLOAT32_C(   379.60), SIMDE_FLOAT32_C(   183.72), SIMDE_FLOAT32_C(  -638.53), SIMDE_FLOAT32_C(   843.87) },
      UINT8_C( 95),
      { SIMDE_FLOAT32_C(   239.38), SIMDE_FLOAT32_C(   285.16), SIMDE_FLOAT32_C(   387.96), SIMDE_FLOAT32_C(  -330.97) },
      { SIMDE_FLOAT32_C(    -5.80), SIMDE_FLOAT32_C(   242.15), SIMDE_FLOAT32_C(   741.95), SIMDE_FLOAT32_C(  -565.66) },
       INT32_C(          49),
      { SIMDE_FLOAT32_C(    -5.88), SIMDE_FLOAT32_C(   285.16), SIMDE_FLOAT32_C(   387.96), SIMDE_FLOAT32_C(  -330.97) } },
    { { SIMDE_FLOAT32_C(    34.62), SIMDE_FLOAT32_C(   989.29), SIMDE_FLOAT32_C(   409.79), SIMDE_FLOAT32_C(  -442.63) },
      UINT8_C(135),
      { SIMDE_FLOAT32_C(  -579.56), SIMDE_FLOAT32_C(   662.41), SIMDE_FLOAT32_C(   843.61), SIMDE_FLOAT32_C(   712.34) },
      { SIMDE_FLOAT32_C(  -492.02), SIMDE_FLOAT32_C(   -10.75), SIMDE_FLOAT32_C(   358.27), SIMDE_FLOAT32_C(  -350.67) },
       INT32_C(         194),
      { SIMDE_FLOAT32_C(  -492.02), SIMDE_FLOAT32_C(   662.41), SIMDE_FLOAT32_C(   843.61), SIMDE_FLOAT32_C(   712.34) } },
  };

  simde__m128 src, a, b, r;

  src = simde_mm_loadu_ps(test_vec[0].src);
  a = simde_mm_loadu_ps(test_vec[0].a);
  b = simde_mm_loadu_ps(test_vec[0].b);
  r = simde_mm_mask_roundscale_ss(src, test_vec[0].k, a, b, INT32_C(          96));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[0].r), 1);

  src = simde_mm_loadu_ps(test_vec[1].src);
  a = simde_mm_loadu_ps(test_vec[1].a);
  b = simde_mm_loadu_ps(test_vec[1].b);
  r = simde_mm_mask_roundscale_ss(src, test_vec[1].k, a, b, INT32_C(          17));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[1].r), 1);

  src = simde_mm_loadu_ps(test_vec[2].src);
  a = simde_mm_loadu_ps(test_vec[2].a);
  b = simde_mm_loadu_ps(test_vec[2].b);
  r = simde_mm_mask_roundscale_ss(src, test_vec[2].k, a, b, INT32_C(         130));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[2].r), 1);

  src = simde_mm_loadu_ps(test_vec[3].src);
  a = simde_mm_loadu_ps(test_vec[3].a);
  b = simde_mm_loadu_ps(test_vec[3].b);
  r = simde_mm_mask_roundscale_ss(src, test_vec[3].k, a, b, INT32_C(         227));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[3].r), 1);

  src = simde_mm_loadu_ps(test_vec[4].src);
  a = simde_mm_loadu_ps(test_vec[4].a);
  b = simde_mm_loadu_ps(test_vec[4].b);
  r = simde_mm_mask_roundscale_ss(src, test_vec[4].k, a, b, INT32_C(         100));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[4].r), 1);

  src = simde_mm_loadu_ps(test_vec[5].src);
  a = simde_mm_loadu_ps(test_vec[5].a);
  b = simde_mm_loadu_ps(test_vec[5].b);
  r = simde_mm_mask_roundscale_ss(src, test_vec[5].k, a, b, INT32_C(          48));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[5].r), 1);

  src = simde_mm_loadu_ps(test_vec[6].src);
  a = simde_mm_loadu_ps(test_vec[6].a);
  b = simde_mm_loadu_ps(test_vec[6].b);
  r = simde_mm_mask_roundscale_ss(src, test_vec[6].k, a, b, INT32_C(          49));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[6].r), 1);

  src = simde_mm_loadu_ps(test_vec[7].src);
  a = simde_mm_loadu_ps(test_vec[7].a);
  b = simde_mm_loadu_ps(test_vec[7].b);
  r = simde_mm_mask_roundscale_ss(src, test_vec[7].k, a, b, INT32_C(         194));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[7].r), 1);

  return 0;
#else
  fputc('\n', stdout);
  int round_type[5] = {SIMDE_MM_FROUND_TO_NEAREST_INT, SIMDE_MM_FROUND_TO_NEG_INF, SIMDE_MM_FROUND_TO_POS_INF, SIMDE_MM_FROUND_TO_ZERO, SIMDE_MM_FROUND_CUR_DIRECTION};
  for (int i = 0 ; i < 8 ; i++) {
    simde__m128 src = simde_test_x86_random_f32x4(SIMDE_FLOAT32_C(-1000.0), SIMDE_FLOAT32_C(1000.0));
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m128 a = simde_test_x86_random_f32x4(SIMDE_FLOAT32_C(-1000.0), SIMDE_FLOAT32_C(1000.0));
    simde__m128 b = simde_test_x86_random_f32x4(SIMDE_FLOAT32_C(-1000.0), SIMDE_FLOAT32_C(1000.0));
    if((simde_test_codegen_rand() & 1)) {
      if((simde_test_codegen_rand() & 1))
        b = simde_mm_mask_mov_ps(b, 1, simde_mm_set1_ps(SIMDE_MATH_NAN));
      else {
        if((simde_test_codegen_rand() & 1))
          b = simde_mm_mask_mov_ps(b, 1, simde_mm_set1_ps(SIMDE_MATH_INFINITY));
        else
          b = simde_mm_mask_mov_ps(b, 1, simde_mm_set1_ps(-SIMDE_MATH_INFINITY));
      }
    }
    int imm8 = (((simde_test_codegen_rand() & 15) << 4) | round_type[i % 5]) & 255;
    simde__m128 r;
    SIMDE_CONSTIFY_256_(simde_mm_mask_roundscale_ss, r, simde_mm_setzero_ps(), imm8, src, k, a, b);

    simde_test_x86_write_f32x4(2, src, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f32x4(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, imm8, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_maskz_roundscale_ss (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask8 k;
    const simde_float32 a[4];
    const simde_float32 b[4];
    const int32_t imm8;
    const simde_float32 r[4];
  } test_vec[] = {
    { UINT8_C(150),
      { SIMDE_FLOAT32_C(   560.38), SIMDE_FLOAT32_C(  -514.60), SIMDE_FLOAT32_C(  -499.34), SIMDE_FLOAT32_C(   404.24) },
      {     -SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(   740.05), SIMDE_FLOAT32_C(  -310.60), SIMDE_FLOAT32_C(   878.68) },
       INT32_C(         224),
      { SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -514.60), SIMDE_FLOAT32_C(  -499.34), SIMDE_FLOAT32_C(   404.24) } },
    { UINT8_C(137),
      { SIMDE_FLOAT32_C(  -845.43), SIMDE_FLOAT32_C(   397.73), SIMDE_FLOAT32_C(   152.56), SIMDE_FLOAT32_C(  -856.14) },
      { SIMDE_FLOAT32_C(  -192.48), SIMDE_FLOAT32_C(   709.93), SIMDE_FLOAT32_C(   209.33), SIMDE_FLOAT32_C(   227.96) },
       INT32_C(         129),
      { SIMDE_FLOAT32_C(  -192.48), SIMDE_FLOAT32_C(   397.73), SIMDE_FLOAT32_C(   152.56), SIMDE_FLOAT32_C(  -856.14) } },
    { UINT8_C( 20),
      { SIMDE_FLOAT32_C(   880.32), SIMDE_FLOAT32_C(  -957.81), SIMDE_FLOAT32_C(  -701.42), SIMDE_FLOAT32_C(  -470.36) },
      { SIMDE_FLOAT32_C(  -777.04), SIMDE_FLOAT32_C(   600.26), SIMDE_FLOAT32_C(  -331.16), SIMDE_FLOAT32_C(   783.34) },
       INT32_C(          50),
      { SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -957.81), SIMDE_FLOAT32_C(  -701.42), SIMDE_FLOAT32_C(  -470.36) } },
    { UINT8_C( 12),
      { SIMDE_FLOAT32_C(  -423.61), SIMDE_FLOAT32_C(   -90.45), SIMDE_FLOAT32_C(   876.98), SIMDE_FLOAT32_C(  -544.93) },
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   560.58), SIMDE_FLOAT32_C(   575.90), SIMDE_FLOAT32_C(   469.65) },
       INT32_C(          99),
      { SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   -90.45), SIMDE_FLOAT32_C(   876.98), SIMDE_FLOAT32_C(  -544.93) } },
    { UINT8_C( 12),
      { SIMDE_FLOAT32_C(   874.33), SIMDE_FLOAT32_C(   674.90), SIMDE_FLOAT32_C(  -458.99), SIMDE_FLOAT32_C(    83.66) },
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   913.35), SIMDE_FLOAT32_C(  -863.41), SIMDE_FLOAT32_C(   843.16) },
       INT32_C(         116),
      { SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   674.90), SIMDE_FLOAT32_C(  -458.99), SIMDE_FLOAT32_C(    83.66) } },
    { UINT8_C( 25),
      { SIMDE_FLOAT32_C(  -598.26), SIMDE_FLOAT32_C(   741.99), SIMDE_FLOAT32_C(    -7.85), SIMDE_FLOAT32_C(  -814.92) },
      { SIMDE_FLOAT32_C(   827.65), SIMDE_FLOAT32_C(  -838.35), SIMDE_FLOAT32_C(   372.66), SIMDE_FLOAT32_C(  -595.96) },
       INT32_C(          96),
      { SIMDE_FLOAT32_C(   827.66), SIMDE_FLOAT32_C(   741.99), SIMDE_FLOAT32_C(    -7.85), SIMDE_FLOAT32_C(  -814.92) } },
    { UINT8_C(213),
      { SIMDE_FLOAT32_C(  -610.18), SIMDE_FLOAT32_C(  -189.78), SIMDE_FLOAT32_C(  -564.99), SIMDE_FLOAT32_C(   859.47) },
      { SIMDE_FLOAT32_C(  -511.25), SIMDE_FLOAT32_C(  -834.52), SIMDE_FLOAT32_C(  -273.15), SIMDE_FLOAT32_C(   319.83) },
       INT32_C(          65),
      { SIMDE_FLOAT32_C(  -511.25), SIMDE_FLOAT32_C(  -189.78), SIMDE_FLOAT32_C(  -564.99), SIMDE_FLOAT32_C(   859.47) } },
    { UINT8_C(140),
      { SIMDE_FLOAT32_C(   123.48), SIMDE_FLOAT32_C(   304.61), SIMDE_FLOAT32_C(   774.19), SIMDE_FLOAT32_C(   260.07) },
      { SIMDE_FLOAT32_C(   147.77), SIMDE_FLOAT32_C(   567.85), SIMDE_FLOAT32_C(   438.85), SIMDE_FLOAT32_C(   289.51) },
       INT32_C(         114),
      { SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   304.61), SIMDE_FLOAT32_C(   774.19), SIMDE_FLOAT32_C(   260.07) } },
  };

  simde__m128 a, b, r;

  a = simde_mm_loadu_ps(test_vec[0].a);
  b = simde_mm_loadu_ps(test_vec[0].b);
  r = simde_mm_maskz_roundscale_ss(test_vec[0].k, a, b, INT32_C(         224));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[0].r), 1);

  a = simde_mm_loadu_ps(test_vec[1].a);
  b = simde_mm_loadu_ps(test_vec[1].b);
  r = simde_mm_maskz_roundscale_ss(test_vec[1].k, a, b, INT32_C(         129));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[1].r), 1);

  a = simde_mm_loadu_ps(test_vec[2].a);
  b = simde_mm_loadu_ps(test_vec[2].b);
  r = simde_mm_maskz_roundscale_ss(test_vec[2].k, a, b, INT32_C(          50));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[2].r), 1);

  a = simde_mm_loadu_ps(test_vec[3].a);
  b = simde_mm_loadu_ps(test_vec[3].b);
  r = simde_mm_maskz_roundscale_ss(test_vec[3].k, a, b, INT32_C(          99));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[3].r), 1);

  a = simde_mm_loadu_ps(test_vec[4].a);
  b = simde_mm_loadu_ps(test_vec[4].b);
  r = simde_mm_maskz_roundscale_ss(test_vec[4].k, a, b, INT32_C(         116));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[4].r), 1);

  a = simde_mm_loadu_ps(test_vec[5].a);
  b = simde_mm_loadu_ps(test_vec[5].b);
  r = simde_mm_maskz_roundscale_ss(test_vec[5].k, a, b, INT32_C(          96));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[5].r), 1);

  a = simde_mm_loadu_ps(test_vec[6].a);
  b = simde_mm_loadu_ps(test_vec[6].b);
  r = simde_mm_maskz_roundscale_ss(test_vec[6].k, a, b, INT32_C(          65));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[6].r), 1);

  a = simde_mm_loadu_ps(test_vec[7].a);
  b = simde_mm_loadu_ps(test_vec[7].b);
  r = simde_mm_maskz_roundscale_ss(test_vec[7].k, a, b, INT32_C(         114));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[7].r), 1);

  return 0;
#else
  fputc('\n', stdout);
  int round_type[5] = {SIMDE_MM_FROUND_TO_NEAREST_INT, SIMDE_MM_FROUND_TO_NEG_INF, SIMDE_MM_FROUND_TO_POS_INF, SIMDE_MM_FROUND_TO_ZERO, SIMDE_MM_FROUND_CUR_DIRECTION};
  for (int i = 0 ; i < 8 ; i++) {
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m128 a = simde_test_x86_random_f32x4(SIMDE_FLOAT32_C(-1000.0), SIMDE_FLOAT32_C(1000.0));
    simde__m128 b = simde_test_x86_random_f32x4(SIMDE_FLOAT32_C(-1000.0), SIMDE_FLOAT32_C(1000.0));
    if((simde_test_codegen_rand() & 1)) {
      if((simde_test_codegen_rand() & 1))
        b = simde_mm_mask_mov_ps(b, 1, simde_mm_set1_ps(SIMDE_MATH_NAN));
      else {
        if((simde_test_codegen_rand() & 1))
          b = simde_mm_mask_mov_ps(b, 1, simde_mm_set1_ps(SIMDE_MATH_INFINITY));
        else
          b = simde_mm_mask_mov_ps(b, 1, simde_mm_set1_ps(-SIMDE_MATH_INFINITY));
      }
    }
    int imm8 = (((simde_test_codegen_rand() & 15) << 4) | round_type[i % 5]) & 255;
    simde__m128 r;
    SIMDE_CONSTIFY_256_(simde_mm_maskz_roundscale_ss, r, simde_mm_setzero_ps(), imm8, k, a, b);

    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_f32x4(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, imm8, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_roundscale_sd (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde_float64 a[2];
    const simde_float64 b[2];
    const int32_t imm8;
    const simde_float64 r[2];
  } test_vec[] = {
    { { SIMDE_FLOAT64_C(   538.74), SIMDE_FLOAT64_C(    64.09) },
      { SIMDE_FLOAT64_C(   791.27), SIMDE_FLOAT64_C(  -766.95) },
       INT32_C(           0),
      { SIMDE_FLOAT64_C(   791.00), SIMDE_FLOAT64_C(    64.09) } },
    { { SIMDE_FLOAT64_C(  -678.97), SIMDE_FLOAT64_C(    39.26) },
      { SIMDE_FLOAT64_C(  -965.12), SIMDE_FLOAT64_C(   198.74) },
       INT32_C(          16),
      { SIMDE_FLOAT64_C(  -965.00), SIMDE_FLOAT64_C(    39.26) } },
    { { SIMDE_FLOAT64_C(   569.29), SIMDE_FLOAT64_C(   -63.11) },
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   227.96) },
       INT32_C(          32),
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   -63.11) } },
    { { SIMDE_FLOAT64_C(   570.63), SIMDE_FLOAT64_C(  -299.33) },
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   106.40) },
       INT32_C(          48),
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(  -299.33) } },
    { { SIMDE_FLOAT64_C(   206.46), SIMDE_FLOAT64_C(  -483.51) },
      { SIMDE_FLOAT64_C(  -173.23), SIMDE_FLOAT64_C(   300.40) },
       INT32_C(          64),
      { SIMDE_FLOAT64_C(  -173.25), SIMDE_FLOAT64_C(  -483.51) } },
    { { SIMDE_FLOAT64_C(   -29.64), SIMDE_FLOAT64_C(    87.23) },
      { SIMDE_FLOAT64_C(    38.91), SIMDE_FLOAT64_C(  -744.22) },
       INT32_C(          80),
      { SIMDE_FLOAT64_C(    38.91), SIMDE_FLOAT64_C(    87.23) } },
    { { SIMDE_FLOAT64_C(  -897.00), SIMDE_FLOAT64_C(  -952.95) },
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(  -896.36) },
       INT32_C(          96),
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(  -952.95) } },
    { { SIMDE_FLOAT64_C(  -861.49), SIMDE_FLOAT64_C(   566.82) },
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   707.81) },
       INT32_C(         112),
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   566.82) } },
    { { SIMDE_FLOAT64_C(   -64.23), SIMDE_FLOAT64_C(   759.82) },
      {        SIMDE_MATH_INFINITY, SIMDE_FLOAT64_C(  -493.60) },
       INT32_C(         128),
      {        SIMDE_MATH_INFINITY, SIMDE_FLOAT64_C(   759.82) } },
    { { SIMDE_FLOAT64_C(   -48.69), SIMDE_FLOAT64_C(  -284.86) },
      { SIMDE_FLOAT64_C(  -180.74), SIMDE_FLOAT64_C(   467.80) },
       INT32_C(         144),
      { SIMDE_FLOAT64_C(  -180.74), SIMDE_FLOAT64_C(  -284.86) } },
    { { SIMDE_FLOAT64_C(  -880.34), SIMDE_FLOAT64_C(  -225.76) },
      { SIMDE_FLOAT64_C(  -487.74), SIMDE_FLOAT64_C(   206.89) },
       INT32_C(         160),
      { SIMDE_FLOAT64_C(  -487.74), SIMDE_FLOAT64_C(  -225.76) } },
    { { SIMDE_FLOAT64_C(  -231.96), SIMDE_FLOAT64_C(   832.86) },
      { SIMDE_FLOAT64_C(   916.15), SIMDE_FLOAT64_C(  -184.91) },
       INT32_C(         176),
      { SIMDE_FLOAT64_C(   916.15), SIMDE_FLOAT64_C(   832.86) } },
    { { SIMDE_FLOAT64_C(  -980.22), SIMDE_FLOAT64_C(   183.17) },
      { SIMDE_FLOAT64_C(  -409.84), SIMDE_FLOAT64_C(  -841.70) },
       INT32_C(         192),
      { SIMDE_FLOAT64_C(  -409.84), SIMDE_FLOAT64_C(   183.17) } },
    { { SIMDE_FLOAT64_C(   300.74), SIMDE_FLOAT64_C(   866.11) },
      { SIMDE_FLOAT64_C(   253.70), SIMDE_FLOAT64_C(  -117.14) },
       INT32_C(         208),
      { SIMDE_FLOAT64_C(   253.70), SIMDE_FLOAT64_C(   866.11) } },
    { { SIMDE_FLOAT64_C(    13.51), SIMDE_FLOAT64_C(  -600.29) },
      { SIMDE_FLOAT64_C(   308.28), SIMDE_FLOAT64_C(   474.00) },
       INT32_C(         224),
      { SIMDE_FLOAT64_C(   308.28), SIMDE_FLOAT64_C(  -600.29) } },
    { { SIMDE_FLOAT64_C(   -78.92), SIMDE_FLOAT64_C(  -574.69) },
      { SIMDE_FLOAT64_C(   327.13), SIMDE_FLOAT64_C(   740.34) },
       INT32_C(         240),
      { SIMDE_FLOAT64_C(   327.13), SIMDE_FLOAT64_C(  -574.69) } },
    { { SIMDE_FLOAT64_C(  -130.97), SIMDE_FLOAT64_C(   860.00) },
      { SIMDE_FLOAT64_C(  -332.65), SIMDE_FLOAT64_C(   381.30) },
       INT32_C(           1),
      { SIMDE_FLOAT64_C(  -333.00), SIMDE_FLOAT64_C(   860.00) } },
    { { SIMDE_FLOAT64_C(  -519.50), SIMDE_FLOAT64_C(  -850.66) },
      {        SIMDE_MATH_INFINITY, SIMDE_FLOAT64_C(  -603.35) },
       INT32_C(          17),
      {        SIMDE_MATH_INFINITY, SIMDE_FLOAT64_C(  -850.66) } },
    { { SIMDE_FLOAT64_C(  -852.40), SIMDE_FLOAT64_C(  -818.22) },
      { SIMDE_FLOAT64_C(  -425.27), SIMDE_FLOAT64_C(  -102.41) },
       INT32_C(          33),
      { SIMDE_FLOAT64_C(  -425.50), SIMDE_FLOAT64_C(  -818.22) } },
    { { SIMDE_FLOAT64_C(  -559.16), SIMDE_FLOAT64_C(  -848.72) },
      {        SIMDE_MATH_INFINITY, SIMDE_FLOAT64_C(   242.72) },
       INT32_C(          49),
      {        SIMDE_MATH_INFINITY, SIMDE_FLOAT64_C(  -848.72) } },
    { { SIMDE_FLOAT64_C(  -361.20), SIMDE_FLOAT64_C(   377.06) },
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(    64.10) },
       INT32_C(          65),
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   377.06) } },
    { { SIMDE_FLOAT64_C(   -42.79), SIMDE_FLOAT64_C(   573.22) },
      { SIMDE_FLOAT64_C(    72.42), SIMDE_FLOAT64_C(   624.56) },
       INT32_C(          81),
      { SIMDE_FLOAT64_C(    72.41), SIMDE_FLOAT64_C(   573.22) } },
    { { SIMDE_FLOAT64_C(  -860.70), SIMDE_FLOAT64_C(  -894.95) },
      { SIMDE_FLOAT64_C(   103.87), SIMDE_FLOAT64_C(    39.04) },
       INT32_C(          97),
      { SIMDE_FLOAT64_C(   103.86), SIMDE_FLOAT64_C(  -894.95) } },
    { { SIMDE_FLOAT64_C(  -931.70), SIMDE_FLOAT64_C(  -369.34) },
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(  -784.10) },
       INT32_C(         113),
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(  -369.34) } },
    { { SIMDE_FLOAT64_C(   113.49), SIMDE_FLOAT64_C(  -705.05) },
      { SIMDE_FLOAT64_C(   933.70), SIMDE_FLOAT64_C(   264.77) },
       INT32_C(         129),
      { SIMDE_FLOAT64_C(   933.70), SIMDE_FLOAT64_C(  -705.05) } },
    { { SIMDE_FLOAT64_C(   176.42), SIMDE_FLOAT64_C(  -570.43) },
      {        SIMDE_MATH_INFINITY, SIMDE_FLOAT64_C(   727.42) },
       INT32_C(         145),
      {        SIMDE_MATH_INFINITY, SIMDE_FLOAT64_C(  -570.43) } },
    { { SIMDE_FLOAT64_C(  -867.53), SIMDE_FLOAT64_C(   506.64) },
      {        SIMDE_MATH_INFINITY, SIMDE_FLOAT64_C(    89.68) },
       INT32_C(         161),
      {        SIMDE_MATH_INFINITY, SIMDE_FLOAT64_C(   506.64) } },
    { { SIMDE_FLOAT64_C(  -965.61), SIMDE_FLOAT64_C(   623.64) },
      { SIMDE_FLOAT64_C(  -180.71), SIMDE_FLOAT64_C(   138.25) },
       INT32_C(         177),
      { SIMDE_FLOAT64_C(  -180.71), SIMDE_FLOAT64_C(   623.64) } },
    { { SIMDE_FLOAT64_C(   320.99), SIMDE_FLOAT64_C(   206.55) },
      {       -SIMDE_MATH_INFINITY, SIMDE_FLOAT64_C(  -760.88) },
       INT32_C(         193),
      {       -SIMDE_MATH_INFINITY, SIMDE_FLOAT64_C(   206.55) } },
    { { SIMDE_FLOAT64_C(  -464.06), SIMDE_FLOAT64_C(  -599.26) },
      { SIMDE_FLOAT64_C(   665.68), SIMDE_FLOAT64_C(   800.71) },
       INT32_C(         209),
      { SIMDE_FLOAT64_C(   665.68), SIMDE_FLOAT64_C(  -599.26) } },
    { { SIMDE_FLOAT64_C(  -157.90), SIMDE_FLOAT64_C(  -769.73) },
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(  -430.48) },
       INT32_C(         225),
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(  -769.73) } },
    { { SIMDE_FLOAT64_C(   769.01), SIMDE_FLOAT64_C(   431.10) },
      { SIMDE_FLOAT64_C(  -204.44), SIMDE_FLOAT64_C(  -819.06) },
       INT32_C(         241),
      { SIMDE_FLOAT64_C(  -204.44), SIMDE_FLOAT64_C(   431.10) } },
    { { SIMDE_FLOAT64_C(   875.43), SIMDE_FLOAT64_C(   665.28) },
      { SIMDE_FLOAT64_C(   235.01), SIMDE_FLOAT64_C(   909.82) },
       INT32_C(           2),
      { SIMDE_FLOAT64_C(   236.00), SIMDE_FLOAT64_C(   665.28) } },
    { { SIMDE_FLOAT64_C(  -945.70), SIMDE_FLOAT64_C(    48.07) },
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   375.29) },
       INT32_C(          18),
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(    48.07) } },
    { { SIMDE_FLOAT64_C(   614.41), SIMDE_FLOAT64_C(   677.07) },
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   346.40) },
       INT32_C(          34),
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   677.07) } },
    { { SIMDE_FLOAT64_C(    12.08), SIMDE_FLOAT64_C(  -986.28) },
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   854.18) },
       INT32_C(          50),
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(  -986.28) } },
    { { SIMDE_FLOAT64_C(  -576.30), SIMDE_FLOAT64_C(   542.63) },
      {        SIMDE_MATH_INFINITY, SIMDE_FLOAT64_C(  -807.29) },
       INT32_C(          66),
      {        SIMDE_MATH_INFINITY, SIMDE_FLOAT64_C(   542.63) } },
    { { SIMDE_FLOAT64_C(   494.51), SIMDE_FLOAT64_C(   258.93) },
      {        SIMDE_MATH_INFINITY, SIMDE_FLOAT64_C(  -270.47) },
       INT32_C(          82),
      {        SIMDE_MATH_INFINITY, SIMDE_FLOAT64_C(   258.93) } },
    { { SIMDE_FLOAT64_C(  -783.18), SIMDE_FLOAT64_C(   279.46) },
      { SIMDE_FLOAT64_C(  -840.88), SIMDE_FLOAT64_C(  -528.57) },
       INT32_C(          98),
      { SIMDE_FLOAT64_C(  -840.88), SIMDE_FLOAT64_C(   279.46) } },
    { { SIMDE_FLOAT64_C(   773.53), SIMDE_FLOAT64_C(  -851.50) },
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   119.93) },
       INT32_C(         114),
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(  -851.50) } },
    { { SIMDE_FLOAT64_C(  -867.99), SIMDE_FLOAT64_C(  -624.77) },
      { SIMDE_FLOAT64_C(  -560.77), SIMDE_FLOAT64_C(   986.19) },
       INT32_C(         130),
      { SIMDE_FLOAT64_C(  -560.77), SIMDE_FLOAT64_C(  -624.77) } },
    { { SIMDE_FLOAT64_C(   738.25), SIMDE_FLOAT64_C(  -590.11) },
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(  -673.81) },
       INT32_C(         146),
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(  -590.11) } },
    { { SIMDE_FLOAT64_C(   709.69), SIMDE_FLOAT64_C(   -23.76) },
      { SIMDE_FLOAT64_C(  -369.90), SIMDE_FLOAT64_C(   -31.38) },
       INT32_C(         162),
      { SIMDE_FLOAT64_C(  -369.90), SIMDE_FLOAT64_C(   -23.76) } },
    { { SIMDE_FLOAT64_C(   359.63), SIMDE_FLOAT64_C(  -862.63) },
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(  -856.54) },
       INT32_C(         178),
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(  -862.63) } },
    { { SIMDE_FLOAT64_C(  -697.42), SIMDE_FLOAT64_C(  -174.38) },
      { SIMDE_FLOAT64_C(  -853.10), SIMDE_FLOAT64_C(  -923.89) },
       INT32_C(         194),
      { SIMDE_FLOAT64_C(  -853.10), SIMDE_FLOAT64_C(  -174.38) } },
    { { SIMDE_FLOAT64_C(  -977.92), SIMDE_FLOAT64_C(   196.04) },
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   648.75) },
       INT32_C(         210),
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   196.04) } },
    { { SIMDE_FLOAT64_C(  -912.03), SIMDE_FLOAT64_C(   314.24) },
      { SIMDE_FLOAT64_C(  -669.90), SIMDE_FLOAT64_C(   826.22) },
       INT32_C(         226),
      { SIMDE_FLOAT64_C(  -669.90), SIMDE_FLOAT64_C(   314.24) } },
    { { SIMDE_FLOAT64_C(  -508.05), SIMDE_FLOAT64_C(  -847.60) },
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   627.54) },
       INT32_C(         242),
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(  -847.60) } },
    { { SIMDE_FLOAT64_C(  -742.35), SIMDE_FLOAT64_C(  -169.29) },
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   617.27) },
       INT32_C(           3),
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(  -169.29) } },
    { { SIMDE_FLOAT64_C(   760.73), SIMDE_FLOAT64_C(   322.27) },
      { SIMDE_FLOAT64_C(  -716.36), SIMDE_FLOAT64_C(  -936.69) },
       INT32_C(          19),
      { SIMDE_FLOAT64_C(  -716.00), SIMDE_FLOAT64_C(   322.27) } },
    { { SIMDE_FLOAT64_C(  -569.46), SIMDE_FLOAT64_C(  -860.58) },
      { SIMDE_FLOAT64_C(   122.02), SIMDE_FLOAT64_C(  -547.38) },
       INT32_C(          35),
      { SIMDE_FLOAT64_C(   122.00), SIMDE_FLOAT64_C(  -860.58) } },
    { { SIMDE_FLOAT64_C(  -542.33), SIMDE_FLOAT64_C(  -898.63) },
      {       -SIMDE_MATH_INFINITY, SIMDE_FLOAT64_C(  -831.46) },
       INT32_C(          51),
      {       -SIMDE_MATH_INFINITY, SIMDE_FLOAT64_C(  -898.63) } },
    { { SIMDE_FLOAT64_C(  -984.44), SIMDE_FLOAT64_C(   701.89) },
      {        SIMDE_MATH_INFINITY, SIMDE_FLOAT64_C(  -832.04) },
       INT32_C(          67),
      {        SIMDE_MATH_INFINITY, SIMDE_FLOAT64_C(   701.89) } },
    { { SIMDE_FLOAT64_C(   331.58), SIMDE_FLOAT64_C(  -124.22) },
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   649.72) },
       INT32_C(          83),
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(  -124.22) } },
    { { SIMDE_FLOAT64_C(  -689.12), SIMDE_FLOAT64_C(  -746.21) },
      {       -SIMDE_MATH_INFINITY, SIMDE_FLOAT64_C(  -405.49) },
       INT32_C(          99),
      {       -SIMDE_MATH_INFINITY, SIMDE_FLOAT64_C(  -746.21) } },
    { { SIMDE_FLOAT64_C(  -543.48), SIMDE_FLOAT64_C(  -578.95) },
      { SIMDE_FLOAT64_C(   477.68), SIMDE_FLOAT64_C(   791.98) },
       INT32_C(         115),
      { SIMDE_FLOAT64_C(   477.68), SIMDE_FLOAT64_C(  -578.95) } },
    { { SIMDE_FLOAT64_C(   579.04), SIMDE_FLOAT64_C(  -544.50) },
      { SIMDE_FLOAT64_C(    47.25), SIMDE_FLOAT64_C(   768.38) },
       INT32_C(         131),
      { SIMDE_FLOAT64_C(    47.25), SIMDE_FLOAT64_C(  -544.50) } },
    { { SIMDE_FLOAT64_C(   545.89), SIMDE_FLOAT64_C(   783.94) },
      { SIMDE_FLOAT64_C(  -864.86), SIMDE_FLOAT64_C(  -463.52) },
       INT32_C(         147),
      { SIMDE_FLOAT64_C(  -864.86), SIMDE_FLOAT64_C(   783.94) } },
    { { SIMDE_FLOAT64_C(  -836.24), SIMDE_FLOAT64_C(   154.62) },
      { SIMDE_FLOAT64_C(   981.95), SIMDE_FLOAT64_C(   495.34) },
       INT32_C(         163),
      { SIMDE_FLOAT64_C(   981.95), SIMDE_FLOAT64_C(   154.62) } },
    { { SIMDE_FLOAT64_C(  -157.28), SIMDE_FLOAT64_C(   145.06) },
      {        SIMDE_MATH_INFINITY, SIMDE_FLOAT64_C(  -328.43) },
       INT32_C(         179),
      {        SIMDE_MATH_INFINITY, SIMDE_FLOAT64_C(   145.06) } },
    { { SIMDE_FLOAT64_C(  -949.55), SIMDE_FLOAT64_C(    94.34) },
      {       -SIMDE_MATH_INFINITY, SIMDE_FLOAT64_C(    75.50) },
       INT32_C(         195),
      {       -SIMDE_MATH_INFINITY, SIMDE_FLOAT64_C(    94.34) } },
    { { SIMDE_FLOAT64_C(   342.83), SIMDE_FLOAT64_C(  -578.52) },
      {       -SIMDE_MATH_INFINITY, SIMDE_FLOAT64_C(   798.33) },
       INT32_C(         211),
      {       -SIMDE_MATH_INFINITY, SIMDE_FLOAT64_C(  -578.52) } },
    { { SIMDE_FLOAT64_C(    14.63), SIMDE_FLOAT64_C(   684.54) },
      { SIMDE_FLOAT64_C(  -633.27), SIMDE_FLOAT64_C(   551.11) },
       INT32_C(         227),
      { SIMDE_FLOAT64_C(  -633.27), SIMDE_FLOAT64_C(   684.54) } },
    { { SIMDE_FLOAT64_C(  -469.52), SIMDE_FLOAT64_C(  -294.27) },
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(  -974.18) },
       INT32_C(         243),
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(  -294.27) } },
    { { SIMDE_FLOAT64_C(   170.88), SIMDE_FLOAT64_C(   259.59) },
      {        SIMDE_MATH_INFINITY, SIMDE_FLOAT64_C(  -373.19) },
       INT32_C(           4),
      {        SIMDE_MATH_INFINITY, SIMDE_FLOAT64_C(   259.59) } },
    { { SIMDE_FLOAT64_C(   131.17), SIMDE_FLOAT64_C(  -922.90) },
      { SIMDE_FLOAT64_C(   752.76), SIMDE_FLOAT64_C(  -317.98) },
       INT32_C(          20),
      { SIMDE_FLOAT64_C(   753.00), SIMDE_FLOAT64_C(  -922.90) } },
    { { SIMDE_FLOAT64_C(  -694.06), SIMDE_FLOAT64_C(  -975.15) },
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(  -561.84) },
       INT32_C(          36),
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(  -975.15) } },
    { { SIMDE_FLOAT64_C(  -661.24), SIMDE_FLOAT64_C(  -945.24) },
      {       -SIMDE_MATH_INFINITY, SIMDE_FLOAT64_C(  -976.70) },
       INT32_C(          52),
      {       -SIMDE_MATH_INFINITY, SIMDE_FLOAT64_C(  -945.24) } },
    { { SIMDE_FLOAT64_C(   -48.03), SIMDE_FLOAT64_C(  -218.45) },
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   -22.20) },
       INT32_C(          68),
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(  -218.45) } },
    { { SIMDE_FLOAT64_C(  -851.32), SIMDE_FLOAT64_C(  -222.73) },
      { SIMDE_FLOAT64_C(  -128.10), SIMDE_FLOAT64_C(  -224.51) },
       INT32_C(          84),
      { SIMDE_FLOAT64_C(  -128.09), SIMDE_FLOAT64_C(  -222.73) } },
    { { SIMDE_FLOAT64_C(   827.27), SIMDE_FLOAT64_C(   452.75) },
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   904.37) },
       INT32_C(         100),
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   452.75) } },
    { { SIMDE_FLOAT64_C(   524.24), SIMDE_FLOAT64_C(   511.46) },
      { SIMDE_FLOAT64_C(  -347.86), SIMDE_FLOAT64_C(   565.59) },
       INT32_C(         116),
      { SIMDE_FLOAT64_C(  -347.86), SIMDE_FLOAT64_C(   511.46) } },
    { { SIMDE_FLOAT64_C(  -524.67), SIMDE_FLOAT64_C(    75.67) },
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(  -469.91) },
       INT32_C(         132),
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(    75.67) } },
    { { SIMDE_FLOAT64_C(   -48.42), SIMDE_FLOAT64_C(   676.20) },
      { SIMDE_FLOAT64_C(   971.42), SIMDE_FLOAT64_C(   903.55) },
       INT32_C(         148),
      { SIMDE_FLOAT64_C(   971.42), SIMDE_FLOAT64_C(   676.20) } },
    { { SIMDE_FLOAT64_C(   249.54), SIMDE_FLOAT64_C(  -118.65) },
      { SIMDE_FLOAT64_C(   975.42), SIMDE_FLOAT64_C(   -11.24) },
       INT32_C(         164),
      { SIMDE_FLOAT64_C(   975.42), SIMDE_FLOAT64_C(  -118.65) } },
    { { SIMDE_FLOAT64_C(  -247.31), SIMDE_FLOAT64_C(   860.66) },
      {        SIMDE_MATH_INFINITY, SIMDE_FLOAT64_C(   566.79) },
       INT32_C(         180),
      {        SIMDE_MATH_INFINITY, SIMDE_FLOAT64_C(   860.66) } },
    { { SIMDE_FLOAT64_C(   592.31), SIMDE_FLOAT64_C(  -536.22) },
      { SIMDE_FLOAT64_C(  -860.66), SIMDE_FLOAT64_C(   116.54) },
       INT32_C(         196),
      { SIMDE_FLOAT64_C(  -860.66), SIMDE_FLOAT64_C(  -536.22) } },
    { { SIMDE_FLOAT64_C(  -208.51), SIMDE_FLOAT64_C(  -317.87) },
      { SIMDE_FLOAT64_C(   924.86), SIMDE_FLOAT64_C(   266.81) },
       INT32_C(         212),
      { SIMDE_FLOAT64_C(   924.86), SIMDE_FLOAT64_C(  -317.87) } },
    { { SIMDE_FLOAT64_C(  -786.75), SIMDE_FLOAT64_C(   796.90) },
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(  -475.07) },
       INT32_C(         228),
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   796.90) } },
    { { SIMDE_FLOAT64_C(  -503.65), SIMDE_FLOAT64_C(  -347.96) },
      { SIMDE_FLOAT64_C(   492.13), SIMDE_FLOAT64_C(   745.89) },
       INT32_C(         244),
      { SIMDE_FLOAT64_C(   492.13), SIMDE_FLOAT64_C(  -347.96) } },
  };

  simde__m128d a, b, r;

  a = simde_mm_loadu_pd(test_vec[0].a);
  b = simde_mm_loadu_pd(test_vec[0].b);
  r = simde_mm_roundscale_sd(a, b, INT32_C(           0));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[0].r), 1);

  a = simde_mm_loadu_pd(test_vec[1].a);
  b = simde_mm_loadu_pd(test_vec[1].b);
  r = simde_mm_roundscale_sd(a, b, INT32_C(          16));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[1].r), 1);

  #if !defined(SIMDE_FAST_MATH)
  a = simde_mm_loadu_pd(test_vec[2].a);
  b = simde_mm_loadu_pd(test_vec[2].b);
  r = simde_mm_roundscale_sd(a, b, INT32_C(          32));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[2].r), 1);

  a = simde_mm_loadu_pd(test_vec[3].a);
  b = simde_mm_loadu_pd(test_vec[3].b);
  r = simde_mm_roundscale_sd(a, b, INT32_C(          48));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[3].r), 1);
  #endif

  a = simde_mm_loadu_pd(test_vec[4].a);
  b = simde_mm_loadu_pd(test_vec[4].b);
  r = simde_mm_roundscale_sd(a, b, INT32_C(          64));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[4].r), 1);

  a = simde_mm_loadu_pd(test_vec[5].a);
  b = simde_mm_loadu_pd(test_vec[5].b);
  r = simde_mm_roundscale_sd(a, b, INT32_C(          80));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[5].r), 1);

  #if !defined(SIMDE_FAST_MATH)
  a = simde_mm_loadu_pd(test_vec[6].a);
  b = simde_mm_loadu_pd(test_vec[6].b);
  r = simde_mm_roundscale_sd(a, b, INT32_C(          96));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[6].r), 1);

  a = simde_mm_loadu_pd(test_vec[7].a);
  b = simde_mm_loadu_pd(test_vec[7].b);
  r = simde_mm_roundscale_sd(a, b, INT32_C(         112));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[7].r), 1);
  #endif

  a = simde_mm_loadu_pd(test_vec[8].a);
  b = simde_mm_loadu_pd(test_vec[8].b);
  r = simde_mm_roundscale_sd(a, b, INT32_C(         128));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[8].r), 1);

  a = simde_mm_loadu_pd(test_vec[9].a);
  b = simde_mm_loadu_pd(test_vec[9].b);
  r = simde_mm_roundscale_sd(a, b, INT32_C(         144));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[9].r), 1);

  a = simde_mm_loadu_pd(test_vec[10].a);
  b = simde_mm_loadu_pd(test_vec[10].b);
  r = simde_mm_roundscale_sd(a, b, INT32_C(         160));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[10].r), 1);

  a = simde_mm_loadu_pd(test_vec[11].a);
  b = simde_mm_loadu_pd(test_vec[11].b);
  r = simde_mm_roundscale_sd(a, b, INT32_C(         176));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[11].r), 1);

  a = simde_mm_loadu_pd(test_vec[12].a);
  b = simde_mm_loadu_pd(test_vec[12].b);
  r = simde_mm_roundscale_sd(a, b, INT32_C(         192));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[12].r), 1);

  a = simde_mm_loadu_pd(test_vec[13].a);
  b = simde_mm_loadu_pd(test_vec[13].b);
  r = simde_mm_roundscale_sd(a, b, INT32_C(         208));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[13].r), 1);

  a = simde_mm_loadu_pd(test_vec[14].a);
  b = simde_mm_loadu_pd(test_vec[14].b);
  r = simde_mm_roundscale_sd(a, b, INT32_C(         224));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[14].r), 1);

  a = simde_mm_loadu_pd(test_vec[15].a);
  b = simde_mm_loadu_pd(test_vec[15].b);
  r = simde_mm_roundscale_sd(a, b, INT32_C(         240));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[15].r), 1);

  a = simde_mm_loadu_pd(test_vec[16].a);
  b = simde_mm_loadu_pd(test_vec[16].b);
  r = simde_mm_roundscale_sd(a, b, INT32_C(           1));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[16].r), 1);

  a = simde_mm_loadu_pd(test_vec[17].a);
  b = simde_mm_loadu_pd(test_vec[17].b);
  r = simde_mm_roundscale_sd(a, b, INT32_C(          17));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[17].r), 1);

  a = simde_mm_loadu_pd(test_vec[18].a);
  b = simde_mm_loadu_pd(test_vec[18].b);
  r = simde_mm_roundscale_sd(a, b, INT32_C(          33));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[18].r), 1);

  a = simde_mm_loadu_pd(test_vec[19].a);
  b = simde_mm_loadu_pd(test_vec[19].b);
  r = simde_mm_roundscale_sd(a, b, INT32_C(          49));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[19].r), 1);

  #if !defined(SIMDE_FAST_MATH)
  a = simde_mm_loadu_pd(test_vec[20].a);
  b = simde_mm_loadu_pd(test_vec[20].b);
  r = simde_mm_roundscale_sd(a, b, INT32_C(          65));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[20].r), 1);
  #endif

  a = simde_mm_loadu_pd(test_vec[21].a);
  b = simde_mm_loadu_pd(test_vec[21].b);
  r = simde_mm_roundscale_sd(a, b, INT32_C(          81));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[21].r), 1);

  a = simde_mm_loadu_pd(test_vec[22].a);
  b = simde_mm_loadu_pd(test_vec[22].b);
  r = simde_mm_roundscale_sd(a, b, INT32_C(          97));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[22].r), 1);

  #if !defined(SIMDE_FAST_MATH)
  a = simde_mm_loadu_pd(test_vec[23].a);
  b = simde_mm_loadu_pd(test_vec[23].b);
  r = simde_mm_roundscale_sd(a, b, INT32_C(         113));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[23].r), 1);
  #endif

  a = simde_mm_loadu_pd(test_vec[24].a);
  b = simde_mm_loadu_pd(test_vec[24].b);
  r = simde_mm_roundscale_sd(a, b, INT32_C(         129));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[24].r), 1);

  a = simde_mm_loadu_pd(test_vec[25].a);
  b = simde_mm_loadu_pd(test_vec[25].b);
  r = simde_mm_roundscale_sd(a, b, INT32_C(         145));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[25].r), 1);

  a = simde_mm_loadu_pd(test_vec[26].a);
  b = simde_mm_loadu_pd(test_vec[26].b);
  r = simde_mm_roundscale_sd(a, b, INT32_C(         161));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[26].r), 1);

  a = simde_mm_loadu_pd(test_vec[27].a);
  b = simde_mm_loadu_pd(test_vec[27].b);
  r = simde_mm_roundscale_sd(a, b, INT32_C(         177));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[27].r), 1);

  a = simde_mm_loadu_pd(test_vec[28].a);
  b = simde_mm_loadu_pd(test_vec[28].b);
  r = simde_mm_roundscale_sd(a, b, INT32_C(         193));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[28].r), 1);

  a = simde_mm_loadu_pd(test_vec[29].a);
  b = simde_mm_loadu_pd(test_vec[29].b);
  r = simde_mm_roundscale_sd(a, b, INT32_C(         209));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[29].r), 1);

  #if !defined(SIMDE_FAST_MATH)
  a = simde_mm_loadu_pd(test_vec[30].a);
  b = simde_mm_loadu_pd(test_vec[30].b);
  r = simde_mm_roundscale_sd(a, b, INT32_C(         225));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[30].r), 1);
  #endif

  a = simde_mm_loadu_pd(test_vec[31].a);
  b = simde_mm_loadu_pd(test_vec[31].b);
  r = simde_mm_roundscale_sd(a, b, INT32_C(         241));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[31].r), 1);

  a = simde_mm_loadu_pd(test_vec[32].a);
  b = simde_mm_loadu_pd(test_vec[32].b);
  r = simde_mm_roundscale_sd(a, b, INT32_C(           2));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[32].r), 1);

  #if !defined(SIMDE_FAST_MATH)
  a = simde_mm_loadu_pd(test_vec[33].a);
  b = simde_mm_loadu_pd(test_vec[33].b);
  r = simde_mm_roundscale_sd(a, b, INT32_C(          18));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[33].r), 1);

  a = simde_mm_loadu_pd(test_vec[34].a);
  b = simde_mm_loadu_pd(test_vec[34].b);
  r = simde_mm_roundscale_sd(a, b, INT32_C(          34));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[34].r), 1);

  a = simde_mm_loadu_pd(test_vec[35].a);
  b = simde_mm_loadu_pd(test_vec[35].b);
  r = simde_mm_roundscale_sd(a, b, INT32_C(          50));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[35].r), 1);
  #endif

  a = simde_mm_loadu_pd(test_vec[36].a);
  b = simde_mm_loadu_pd(test_vec[36].b);
  r = simde_mm_roundscale_sd(a, b, INT32_C(          66));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[36].r), 1);

  a = simde_mm_loadu_pd(test_vec[37].a);
  b = simde_mm_loadu_pd(test_vec[37].b);
  r = simde_mm_roundscale_sd(a, b, INT32_C(          82));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[37].r), 1);

  a = simde_mm_loadu_pd(test_vec[38].a);
  b = simde_mm_loadu_pd(test_vec[38].b);
  r = simde_mm_roundscale_sd(a, b, INT32_C(          98));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[38].r), 1);

  #if !defined(SIMDE_FAST_MATH)
  a = simde_mm_loadu_pd(test_vec[39].a);
  b = simde_mm_loadu_pd(test_vec[39].b);
  r = simde_mm_roundscale_sd(a, b, INT32_C(         114));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[39].r), 1);
  #endif

  a = simde_mm_loadu_pd(test_vec[40].a);
  b = simde_mm_loadu_pd(test_vec[40].b);
  r = simde_mm_roundscale_sd(a, b, INT32_C(         130));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[40].r), 1);

  #if !defined(SIMDE_FAST_MATH)
  a = simde_mm_loadu_pd(test_vec[41].a);
  b = simde_mm_loadu_pd(test_vec[41].b);
  r = simde_mm_roundscale_sd(a, b, INT32_C(         146));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[41].r), 1);
  #endif

  a = simde_mm_loadu_pd(test_vec[42].a);
  b = simde_mm_loadu_pd(test_vec[42].b);
  r = simde_mm_roundscale_sd(a, b, INT32_C(         162));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[42].r), 1);

  #if !defined(SIMDE_FAST_MATH)
  a = simde_mm_loadu_pd(test_vec[43].a);
  b = simde_mm_loadu_pd(test_vec[43].b);
  r = simde_mm_roundscale_sd(a, b, INT32_C(         178));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[43].r), 1);
  #endif

  a = simde_mm_loadu_pd(test_vec[44].a);
  b = simde_mm_loadu_pd(test_vec[44].b);
  r = simde_mm_roundscale_sd(a, b, INT32_C(         194));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[44].r), 1);

  #if !defined(SIMDE_FAST_MATH)
  a = simde_mm_loadu_pd(test_vec[45].a);
  b = simde_mm_loadu_pd(test_vec[45].b);
  r = simde_mm_roundscale_sd(a, b, INT32_C(         210));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[45].r), 1);
  #endif

  a = simde_mm_loadu_pd(test_vec[46].a);
  b = simde_mm_loadu_pd(test_vec[46].b);
  r = simde_mm_roundscale_sd(a, b, INT32_C(         226));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[46].r), 1);

  #if !defined(SIMDE_FAST_MATH)
  a = simde_mm_loadu_pd(test_vec[47].a);
  b = simde_mm_loadu_pd(test_vec[47].b);
  r = simde_mm_roundscale_sd(a, b, INT32_C(         242));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[47].r), 1);

  a = simde_mm_loadu_pd(test_vec[48].a);
  b = simde_mm_loadu_pd(test_vec[48].b);
  r = simde_mm_roundscale_sd(a, b, INT32_C(           3));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[48].r), 1);
  #endif

  a = simde_mm_loadu_pd(test_vec[49].a);
  b = simde_mm_loadu_pd(test_vec[49].b);
  r = simde_mm_roundscale_sd(a, b, INT32_C(          19));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[49].r), 1);

  a = simde_mm_loadu_pd(test_vec[50].a);
  b = simde_mm_loadu_pd(test_vec[50].b);
  r = simde_mm_roundscale_sd(a, b, INT32_C(          35));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[50].r), 1);

  a = simde_mm_loadu_pd(test_vec[51].a);
  b = simde_mm_loadu_pd(test_vec[51].b);
  r = simde_mm_roundscale_sd(a, b, INT32_C(          51));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[51].r), 1);

  a = simde_mm_loadu_pd(test_vec[52].a);
  b = simde_mm_loadu_pd(test_vec[52].b);
  r = simde_mm_roundscale_sd(a, b, INT32_C(          67));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[52].r), 1);

  #if !defined(SIMDE_FAST_MATH)
  a = simde_mm_loadu_pd(test_vec[53].a);
  b = simde_mm_loadu_pd(test_vec[53].b);
  r = simde_mm_roundscale_sd(a, b, INT32_C(          83));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[53].r), 1);
  #endif

  a = simde_mm_loadu_pd(test_vec[54].a);
  b = simde_mm_loadu_pd(test_vec[54].b);
  r = simde_mm_roundscale_sd(a, b, INT32_C(          99));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[54].r), 1);

  a = simde_mm_loadu_pd(test_vec[55].a);
  b = simde_mm_loadu_pd(test_vec[55].b);
  r = simde_mm_roundscale_sd(a, b, INT32_C(         115));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[55].r), 1);

  a = simde_mm_loadu_pd(test_vec[56].a);
  b = simde_mm_loadu_pd(test_vec[56].b);
  r = simde_mm_roundscale_sd(a, b, INT32_C(         131));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[56].r), 1);

  a = simde_mm_loadu_pd(test_vec[57].a);
  b = simde_mm_loadu_pd(test_vec[57].b);
  r = simde_mm_roundscale_sd(a, b, INT32_C(         147));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[57].r), 1);

  a = simde_mm_loadu_pd(test_vec[58].a);
  b = simde_mm_loadu_pd(test_vec[58].b);
  r = simde_mm_roundscale_sd(a, b, INT32_C(         163));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[58].r), 1);

  a = simde_mm_loadu_pd(test_vec[59].a);
  b = simde_mm_loadu_pd(test_vec[59].b);
  r = simde_mm_roundscale_sd(a, b, INT32_C(         179));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[59].r), 1);

  a = simde_mm_loadu_pd(test_vec[60].a);
  b = simde_mm_loadu_pd(test_vec[60].b);
  r = simde_mm_roundscale_sd(a, b, INT32_C(         195));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[60].r), 1);

  a = simde_mm_loadu_pd(test_vec[61].a);
  b = simde_mm_loadu_pd(test_vec[61].b);
  r = simde_mm_roundscale_sd(a, b, INT32_C(         211));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[61].r), 1);

  a = simde_mm_loadu_pd(test_vec[62].a);
  b = simde_mm_loadu_pd(test_vec[62].b);
  r = simde_mm_roundscale_sd(a, b, INT32_C(         227));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[62].r), 1);

  #if !defined(SIMDE_FAST_MATH)
  a = simde_mm_loadu_pd(test_vec[63].a);
  b = simde_mm_loadu_pd(test_vec[63].b);
  r = simde_mm_roundscale_sd(a, b, INT32_C(         243));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[63].r), 1);
  #endif

  a = simde_mm_loadu_pd(test_vec[64].a);
  b = simde_mm_loadu_pd(test_vec[64].b);
  r = simde_mm_roundscale_sd(a, b, INT32_C(           4));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[64].r), 1);

  a = simde_mm_loadu_pd(test_vec[65].a);
  b = simde_mm_loadu_pd(test_vec[65].b);
  r = simde_mm_roundscale_sd(a, b, INT32_C(          20));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[65].r), 1);

  #if !defined(SIMDE_FAST_MATH)
  a = simde_mm_loadu_pd(test_vec[66].a);
  b = simde_mm_loadu_pd(test_vec[66].b);
  r = simde_mm_roundscale_sd(a, b, INT32_C(          36));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[66].r), 1);
  #endif

  a = simde_mm_loadu_pd(test_vec[67].a);
  b = simde_mm_loadu_pd(test_vec[67].b);
  r = simde_mm_roundscale_sd(a, b, INT32_C(          52));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[67].r), 1);

  #if !defined(SIMDE_FAST_MATH)
  a = simde_mm_loadu_pd(test_vec[68].a);
  b = simde_mm_loadu_pd(test_vec[68].b);
  r = simde_mm_roundscale_sd(a, b, INT32_C(          68));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[68].r), 1);
  #endif

  a = simde_mm_loadu_pd(test_vec[69].a);
  b = simde_mm_loadu_pd(test_vec[69].b);
  r = simde_mm_roundscale_sd(a, b, INT32_C(          84));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[69].r), 1);

  #if !defined(SIMDE_FAST_MATH)
  a = simde_mm_loadu_pd(test_vec[70].a);
  b = simde_mm_loadu_pd(test_vec[70].b);
  r = simde_mm_roundscale_sd(a, b, INT32_C(         100));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[70].r), 1);
  #endif

  a = simde_mm_loadu_pd(test_vec[71].a);
  b = simde_mm_loadu_pd(test_vec[71].b);
  r = simde_mm_roundscale_sd(a, b, INT32_C(         116));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[71].r), 1);

  #if !defined(SIMDE_FAST_MATH)
  a = simde_mm_loadu_pd(test_vec[72].a);
  b = simde_mm_loadu_pd(test_vec[72].b);
  r = simde_mm_roundscale_sd(a, b, INT32_C(         132));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[72].r), 1);
  #endif

  a = simde_mm_loadu_pd(test_vec[73].a);
  b = simde_mm_loadu_pd(test_vec[73].b);
  r = simde_mm_roundscale_sd(a, b, INT32_C(         148));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[73].r), 1);

  a = simde_mm_loadu_pd(test_vec[74].a);
  b = simde_mm_loadu_pd(test_vec[74].b);
  r = simde_mm_roundscale_sd(a, b, INT32_C(         164));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[74].r), 1);

  a = simde_mm_loadu_pd(test_vec[75].a);
  b = simde_mm_loadu_pd(test_vec[75].b);
  r = simde_mm_roundscale_sd(a, b, INT32_C(         180));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[75].r), 1);

  a = simde_mm_loadu_pd(test_vec[76].a);
  b = simde_mm_loadu_pd(test_vec[76].b);
  r = simde_mm_roundscale_sd(a, b, INT32_C(         196));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[76].r), 1);

  a = simde_mm_loadu_pd(test_vec[77].a);
  b = simde_mm_loadu_pd(test_vec[77].b);
  r = simde_mm_roundscale_sd(a, b, INT32_C(         212));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[77].r), 1);

  #if !defined(SIMDE_FAST_MATH)
  a = simde_mm_loadu_pd(test_vec[78].a);
  b = simde_mm_loadu_pd(test_vec[78].b);
  r = simde_mm_roundscale_sd(a, b, INT32_C(         228));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[78].r), 1);
  #endif

  a = simde_mm_loadu_pd(test_vec[79].a);
  b = simde_mm_loadu_pd(test_vec[79].b);
  r = simde_mm_roundscale_sd(a, b, INT32_C(         244));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[79].r), 1);

  return 0;
#else
  fputc('\n', stdout);
  int round_type[5] = {SIMDE_MM_FROUND_TO_NEAREST_INT, SIMDE_MM_FROUND_TO_NEG_INF, SIMDE_MM_FROUND_TO_POS_INF, SIMDE_MM_FROUND_TO_ZERO, SIMDE_MM_FROUND_CUR_DIRECTION};
  for (int i = 0 ; i < 5 ; i++) {
    for (int j = 0 ; j < 16 ; j++) {
      simde__m128d a = simde_test_x86_random_f64x2(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
      simde__m128d b = simde_test_x86_random_f64x2(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
      if((simde_test_codegen_rand() & 1)) {
        if((simde_test_codegen_rand() & 1))
          b = simde_mm_mask_mov_pd(b, 1, simde_mm_set1_pd(SIMDE_MATH_NAN));
        else {
          if((simde_test_codegen_rand() & 1))
            b = simde_mm_mask_mov_pd(b, 1, simde_mm_set1_pd(SIMDE_MATH_INFINITY));
          else
            b = simde_mm_mask_mov_pd(b, 1, simde_mm_set1_pd(-SIMDE_MATH_INFINITY));
        }
      }
      int imm8 = ((j << 4) | round_type[i]) & 255;
      simde__m128d r;
      SIMDE_CONSTIFY_256_(simde_mm_roundscale_sd, r, simde_mm_setzero_pd(), imm8, a, b);

      simde_test_x86_write_f64x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
      simde_test_x86_write_f64x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
      simde_test_codegen_write_i32(2, imm8, SIMDE_TEST_VEC_POS_MIDDLE);
      simde_test_x86_write_f64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
    }
  }
  return 1;
#endif
}

static int
test_simde_mm_mask_roundscale_sd (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde_float64 src[2];
    const simde__mmask8 k;
    const simde_float64 a[2];
    const simde_float64 b[2];
    const int32_t imm8;
    const simde_float64 r[2];
  } test_vec[] = {
    { { SIMDE_FLOAT64_C(  -152.89), SIMDE_FLOAT64_C(   255.35) },
      UINT8_C(242),
      { SIMDE_FLOAT64_C(   575.09), SIMDE_FLOAT64_C(   308.20) },
      {        SIMDE_MATH_INFINITY, SIMDE_FLOAT64_C(  -284.87) },
       INT32_C(         224),
      { SIMDE_FLOAT64_C(  -152.89), SIMDE_FLOAT64_C(   308.20) } },
    { { SIMDE_FLOAT64_C(  -592.52), SIMDE_FLOAT64_C(   699.67) },
      UINT8_C(134),
      { SIMDE_FLOAT64_C(   489.75), SIMDE_FLOAT64_C(   904.42) },
      { SIMDE_FLOAT64_C(  -814.03), SIMDE_FLOAT64_C(  -202.13) },
       INT32_C(         177),
      { SIMDE_FLOAT64_C(  -592.52), SIMDE_FLOAT64_C(   904.42) } },
    { { SIMDE_FLOAT64_C(   531.17), SIMDE_FLOAT64_C(   420.57) },
      UINT8_C(140),
      { SIMDE_FLOAT64_C(  -721.46), SIMDE_FLOAT64_C(   -85.09) },
      { SIMDE_FLOAT64_C(  -540.17), SIMDE_FLOAT64_C(   877.77) },
       INT32_C(          98),
      { SIMDE_FLOAT64_C(   531.17), SIMDE_FLOAT64_C(   -85.09) } },
    { { SIMDE_FLOAT64_C(  -178.78), SIMDE_FLOAT64_C(  -745.00) },
      UINT8_C( 67),
      { SIMDE_FLOAT64_C(  -923.43), SIMDE_FLOAT64_C(   247.60) },
      {        SIMDE_MATH_INFINITY, SIMDE_FLOAT64_C(   384.78) },
       INT32_C(         179),
      {        SIMDE_MATH_INFINITY, SIMDE_FLOAT64_C(   247.60) } },
    { { SIMDE_FLOAT64_C(   840.86), SIMDE_FLOAT64_C(  -204.15) },
      UINT8_C( 77),
      { SIMDE_FLOAT64_C(   540.53), SIMDE_FLOAT64_C(   -50.72) },
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   444.96) },
       INT32_C(         132),
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   -50.72) } },
    { { SIMDE_FLOAT64_C(    49.85), SIMDE_FLOAT64_C(   550.73) },
      UINT8_C( 67),
      { SIMDE_FLOAT64_C(  -882.69), SIMDE_FLOAT64_C(   829.28) },
      {        SIMDE_MATH_INFINITY, SIMDE_FLOAT64_C(  -422.86) },
       INT32_C(         176),
      {        SIMDE_MATH_INFINITY, SIMDE_FLOAT64_C(   829.28) } },
    { { SIMDE_FLOAT64_C(   530.79), SIMDE_FLOAT64_C(   309.38) },
      UINT8_C( 29),
      { SIMDE_FLOAT64_C(  -221.61), SIMDE_FLOAT64_C(  -325.85) },
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   843.82) },
       INT32_C(         225),
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(  -325.85) } },
    { { SIMDE_FLOAT64_C(  -405.09), SIMDE_FLOAT64_C(  -883.54) },
      UINT8_C(139),
      { SIMDE_FLOAT64_C(  -864.56), SIMDE_FLOAT64_C(    65.73) },
      { SIMDE_FLOAT64_C(  -878.07), SIMDE_FLOAT64_C(   580.40) },
       INT32_C(          82),
      { SIMDE_FLOAT64_C(  -878.06), SIMDE_FLOAT64_C(    65.73) } },
  };

  simde__m128d src, a, b, r;

  src = simde_mm_loadu_pd(test_vec[0].src);
  a = simde_mm_loadu_pd(test_vec[0].a);
  b = simde_mm_loadu_pd(test_vec[0].b);
  r = simde_mm_mask_roundscale_sd(src, test_vec[0].k, a, b, INT32_C(         224));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[0].r), 1);

  src = simde_mm_loadu_pd(test_vec[1].src);
  a = simde_mm_loadu_pd(test_vec[1].a);
  b = simde_mm_loadu_pd(test_vec[1].b);
  r = simde_mm_mask_roundscale_sd(src, test_vec[1].k, a, b, INT32_C(         177));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[1].r), 1);

  src = simde_mm_loadu_pd(test_vec[2].src);
  a = simde_mm_loadu_pd(test_vec[2].a);
  b = simde_mm_loadu_pd(test_vec[2].b);
  r = simde_mm_mask_roundscale_sd(src, test_vec[2].k, a, b, INT32_C(          98));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[2].r), 1);

  src = simde_mm_loadu_pd(test_vec[3].src);
  a = simde_mm_loadu_pd(test_vec[3].a);
  b = simde_mm_loadu_pd(test_vec[3].b);
  r = simde_mm_mask_roundscale_sd(src, test_vec[3].k, a, b, INT32_C(         179));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[3].r), 1);

  #if !defined(SIMDE_FAST_MATH)
  src = simde_mm_loadu_pd(test_vec[4].src);
  a = simde_mm_loadu_pd(test_vec[4].a);
  b = simde_mm_loadu_pd(test_vec[4].b);
  r = simde_mm_mask_roundscale_sd(src, test_vec[4].k, a, b, INT32_C(         132));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[4].r), 1);
  #endif

  src = simde_mm_loadu_pd(test_vec[5].src);
  a = simde_mm_loadu_pd(test_vec[5].a);
  b = simde_mm_loadu_pd(test_vec[5].b);
  r = simde_mm_mask_roundscale_sd(src, test_vec[5].k, a, b, INT32_C(         176));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[5].r), 1);

  #if !defined(SIMDE_FAST_MATH)
  src = simde_mm_loadu_pd(test_vec[6].src);
  a = simde_mm_loadu_pd(test_vec[6].a);
  b = simde_mm_loadu_pd(test_vec[6].b);
  r = simde_mm_mask_roundscale_sd(src, test_vec[6].k, a, b, INT32_C(         225));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[6].r), 1);
  #endif

  src = simde_mm_loadu_pd(test_vec[7].src);
  a = simde_mm_loadu_pd(test_vec[7].a);
  b = simde_mm_loadu_pd(test_vec[7].b);
  r = simde_mm_mask_roundscale_sd(src, test_vec[7].k, a, b, INT32_C(          82));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[7].r), 1);

  return 0;
#else
  fputc('\n', stdout);
  int round_type[5] = {SIMDE_MM_FROUND_TO_NEAREST_INT, SIMDE_MM_FROUND_TO_NEG_INF, SIMDE_MM_FROUND_TO_POS_INF, SIMDE_MM_FROUND_TO_ZERO, SIMDE_MM_FROUND_CUR_DIRECTION};
  for (int i = 0 ; i < 8 ; i++) {
    simde__m128d src = simde_test_x86_random_f64x2(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m128d a = simde_test_x86_random_f64x2(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
    simde__m128d b = simde_test_x86_random_f64x2(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
    if((simde_test_codegen_rand() & 1)) {
      if((simde_test_codegen_rand() & 1))
        b = simde_mm_mask_mov_pd(b, 1, simde_mm_set1_pd(SIMDE_MATH_NAN));
      else {
        if((simde_test_codegen_rand() & 1))
          b = simde_mm_mask_mov_pd(b, 1, simde_mm_set1_pd(SIMDE_MATH_INFINITY));
        else
          b = simde_mm_mask_mov_pd(b, 1, simde_mm_set1_pd(-SIMDE_MATH_INFINITY));
      }
    }
    int imm8 = (((simde_test_codegen_rand() & 15) << 4) | round_type[i % 5]) & 255;
    simde__m128d r;
    SIMDE_CONSTIFY_256_(simde_mm_mask_roundscale_sd, r, simde_mm_setzero_pd(), imm8, src, k, a, b);

    simde_test_x86_write_f64x2(2, src, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f64x2(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f64x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, imm8, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_maskz_roundscale_sd (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask8 k;
    const simde_float64 a[2];
    const simde_float64 b[2];
    const int32_t imm8;
    const simde_float64 r[2];
  } test_vec[] = {
    { UINT8_C(231),
      { SIMDE_FLOAT64_C(   679.03), SIMDE_FLOAT64_C(   330.13) },
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   170.83) },
       INT32_C(          48),
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   330.13) } },
    { UINT8_C(227),
      { SIMDE_FLOAT64_C(  -640.76), SIMDE_FLOAT64_C(  -486.00) },
      {        SIMDE_MATH_INFINITY, SIMDE_FLOAT64_C(  -204.74) },
       INT32_C(         209),
      {        SIMDE_MATH_INFINITY, SIMDE_FLOAT64_C(  -486.00) } },
    { UINT8_C(219),
      { SIMDE_FLOAT64_C(   264.61), SIMDE_FLOAT64_C(  -297.73) },
      { SIMDE_FLOAT64_C(   370.03), SIMDE_FLOAT64_C(   192.79) },
       INT32_C(         162),
      { SIMDE_FLOAT64_C(   370.03), SIMDE_FLOAT64_C(  -297.73) } },
    { UINT8_C(225),
      { SIMDE_FLOAT64_C(  -946.41), SIMDE_FLOAT64_C(  -365.05) },
      { SIMDE_FLOAT64_C(  -822.97), SIMDE_FLOAT64_C(   822.58) },
       INT32_C(           3),
      { SIMDE_FLOAT64_C(  -822.00), SIMDE_FLOAT64_C(  -365.05) } },
    { UINT8_C( 14),
      { SIMDE_FLOAT64_C(   101.90), SIMDE_FLOAT64_C(  -335.55) },
      {       -SIMDE_MATH_INFINITY, SIMDE_FLOAT64_C(  -727.27) },
       INT32_C(          68),
      { SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(  -335.55) } },
    { UINT8_C(201),
      { SIMDE_FLOAT64_C(   337.11), SIMDE_FLOAT64_C(  -368.49) },
      { SIMDE_FLOAT64_C(   497.71), SIMDE_FLOAT64_C(  -156.35) },
       INT32_C(          32),
      { SIMDE_FLOAT64_C(   497.75), SIMDE_FLOAT64_C(  -368.49) } },
    { UINT8_C(128),
      { SIMDE_FLOAT64_C(   229.27), SIMDE_FLOAT64_C(   805.61) },
      { SIMDE_FLOAT64_C(   385.54), SIMDE_FLOAT64_C(  -400.70) },
       INT32_C(          97),
      { SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(   805.61) } },
    { UINT8_C(193),
      { SIMDE_FLOAT64_C(   -90.84), SIMDE_FLOAT64_C(  -911.13) },
      { SIMDE_FLOAT64_C(   474.67), SIMDE_FLOAT64_C(    86.19) },
       INT32_C(           2),
      { SIMDE_FLOAT64_C(   475.00), SIMDE_FLOAT64_C(  -911.13) } },
  };

  simde__m128d a, b, r;

  #if !defined(SIMDE_FAST_MATH)
  a = simde_mm_loadu_pd(test_vec[0].a);
  b = simde_mm_loadu_pd(test_vec[0].b);
  r = simde_mm_maskz_roundscale_sd(test_vec[0].k, a, b, INT32_C(          48));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[0].r), 1);
  #endif

  a = simde_mm_loadu_pd(test_vec[1].a);
  b = simde_mm_loadu_pd(test_vec[1].b);
  r = simde_mm_maskz_roundscale_sd(test_vec[1].k, a, b, INT32_C(         209));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[1].r), 1);

  a = simde_mm_loadu_pd(test_vec[2].a);
  b = simde_mm_loadu_pd(test_vec[2].b);
  r = simde_mm_maskz_roundscale_sd(test_vec[2].k, a, b, INT32_C(         162));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[2].r), 1);

  a = simde_mm_loadu_pd(test_vec[3].a);
  b = simde_mm_loadu_pd(test_vec[3].b);
  r = simde_mm_maskz_roundscale_sd(test_vec[3].k, a, b, INT32_C(           3));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[3].r), 1);

  a = simde_mm_loadu_pd(test_vec[4].a);
  b = simde_mm_loadu_pd(test_vec[4].b);
  r = simde_mm_maskz_roundscale_sd(test_vec[4].k, a, b, INT32_C(          68));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[4].r), 1);

  a = simde_mm_loadu_pd(test_vec[5].a);
  b = simde_mm_loadu_pd(test_vec[5].b);
  r = simde_mm_maskz_roundscale_sd(test_vec[5].k, a, b, INT32_C(          32));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[5].r), 1);

  a = simde_mm_loadu_pd(test_vec[6].a);
  b = simde_mm_loadu_pd(test_vec[6].b);
  r = simde_mm_maskz_roundscale_sd(test_vec[6].k, a, b, INT32_C(          97));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[6].r), 1);

  a = simde_mm_loadu_pd(test_vec[7].a);
  b = simde_mm_loadu_pd(test_vec[7].b);
  r = simde_mm_maskz_roundscale_sd(test_vec[7].k, a, b, INT32_C(           2));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[7].r), 1);

  return 0;
#else
  fputc('\n', stdout);
  int round_type[5] = {SIMDE_MM_FROUND_TO_NEAREST_INT, SIMDE_MM_FROUND_TO_NEG_INF, SIMDE_MM_FROUND_TO_POS_INF, SIMDE_MM_FROUND_TO_ZERO, SIMDE_MM_FROUND_CUR_DIRECTION};
  for (int i = 0 ; i < 8 ; i++) {
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m128d a = simde_test_x86_random_f64x2(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
    simde__m128d b = simde_test_x86_random_f64x2(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
    if((simde_test_codegen_rand() & 1)) {
      if((simde_test_codegen_rand() & 1))
        b = simde_mm_mask_mov_pd(b, 1, simde_mm_set1_pd(SIMDE_MATH_NAN));
      else {
        if((simde_test_codegen_rand() & 1))
          b = simde_mm_mask_mov_pd(b, 1, simde_mm_set1_pd(SIMDE_MATH_INFINITY));
        else
          b = simde_mm_mask_mov_pd(b, 1, simde_mm_set1_pd(-SIMDE_MATH_INFINITY));
      }
    }
    int imm8 = (((simde_test_codegen_rand() & 15) << 4) | round_type[i % 5]) & 255;
    simde__m128d r;
    SIMDE_CONSTIFY_256_(simde_mm_maskz_roundscale_sd, r, simde_mm_setzero_pd(), imm8, k, a, b);

    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_f64x2(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f64x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, imm8, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_roundscale_ps)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_mask_roundscale_ps)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_maskz_roundscale_ps)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_roundscale_ps)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_mask_roundscale_ps)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_maskz_roundscale_ps)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_roundscale_ps)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_mask_roundscale_ps)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_maskz_roundscale_ps)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_roundscale_pd)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_mask_roundscale_pd)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_maskz_roundscale_pd)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_roundscale_pd)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_mask_roundscale_pd)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm256_maskz_roundscale_pd)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_roundscale_pd)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_mask_roundscale_pd)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_maskz_roundscale_pd)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_roundscale_ss)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_mask_roundscale_ss)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_maskz_roundscale_ss)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_roundscale_sd)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_mask_roundscale_sd)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_maskz_roundscale_sd)
SIMDE_TEST_FUNC_LIST_END

#include <test/x86/avx512/test-avx512-footer.h>
