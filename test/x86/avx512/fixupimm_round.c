#define SIMDE_TEST_X86_AVX512_INSN fixupimm_round

#include <test/x86/avx512/test-avx512.h>
#include <simde/x86/avx512/fixupimm_round.h>
#include <simde/x86/avx512/setzero.h>

#if !defined(SIMDE_FAST_MATH)
static int
test_simde_mm512_fixupimm_round_ps (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde_float32 a[16];
    const simde_float32 b[16];
    const int32_t c[16];
    const int imm8;
    const int sae;
    const simde_float32 r[16];
  } test_vec[] = {
    { {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -725.22),            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -972.31),
        SIMDE_FLOAT32_C(   236.80), SIMDE_FLOAT32_C(   603.87), SIMDE_FLOAT32_C(    26.44), SIMDE_FLOAT32_C(  -468.11),
        SIMDE_FLOAT32_C(   -84.87), SIMDE_FLOAT32_C(  -396.42), SIMDE_FLOAT32_C(  -972.94), SIMDE_FLOAT32_C(   575.74),
        SIMDE_FLOAT32_C(    47.76), SIMDE_FLOAT32_C(  -513.89), SIMDE_FLOAT32_C(   538.82), SIMDE_FLOAT32_C(  -530.17) },
      { SIMDE_FLOAT32_C(  -748.26),            SIMDE_MATH_NANF,            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   -96.43),
        SIMDE_FLOAT32_C(  -920.70), SIMDE_FLOAT32_C(  -285.54), SIMDE_FLOAT32_C(   865.76), SIMDE_FLOAT32_C(   937.33),
        SIMDE_FLOAT32_C(   905.64), SIMDE_FLOAT32_C(   346.68), SIMDE_FLOAT32_C(  -771.84), SIMDE_FLOAT32_C(   672.63),
        SIMDE_FLOAT32_C(   636.24), SIMDE_FLOAT32_C(  -763.35), SIMDE_FLOAT32_C(  -549.46), SIMDE_FLOAT32_C(  -522.48) },
      {  INT32_C(   968187140), -INT32_C(   766540851),  INT32_C(  1919636378),  INT32_C(   378562414),  INT32_C(   496715296), -INT32_C(    91824163),  INT32_C(  1192870380), -INT32_C(   476994081),
        -INT32_C(   820230398),  INT32_C(  1688300490),  INT32_C(   769002687), -INT32_C(  1807456397), -INT32_C(  1968054355), -INT32_C(  1417398337), -INT32_C(   655188231),  INT32_C(  1169916995) },
       INT32_C(         203),
       INT32_C(           8),
      { SIMDE_FLOAT32_C(    -1.00), SIMDE_FLOAT32_C(     1.57), SIMDE_FLOAT32_C(     1.00),     -SIMDE_MATH_INFINITYF,
        SIMDE_FLOAT32_C(     1.57), SIMDE_FLOAT32_C(     1.00),     -SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(340282346638528859811704183484516925440.00),
        SIMDE_FLOAT32_C(    90.00),      SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(     1.57), SIMDE_FLOAT32_C(    -1.00),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.50), SIMDE_FLOAT32_C(     0.00),      SIMDE_MATH_INFINITYF } },
    { { SIMDE_FLOAT32_C(  -488.57), SIMDE_FLOAT32_C(  -629.31), SIMDE_FLOAT32_C(  -494.79), SIMDE_FLOAT32_C(   748.23),
        SIMDE_FLOAT32_C(   974.56), SIMDE_FLOAT32_C(   531.65), SIMDE_FLOAT32_C(  -719.88), SIMDE_FLOAT32_C(  -110.32),
        SIMDE_FLOAT32_C(  -864.77), SIMDE_FLOAT32_C(  -692.82), SIMDE_FLOAT32_C(  -534.58), SIMDE_FLOAT32_C(   182.99),
        SIMDE_FLOAT32_C(  -206.71), SIMDE_FLOAT32_C(  -995.76), SIMDE_FLOAT32_C(   652.82), SIMDE_FLOAT32_C(    45.04) },
      { SIMDE_FLOAT32_C(   665.90), SIMDE_FLOAT32_C(   643.76), SIMDE_FLOAT32_C(   948.60), SIMDE_FLOAT32_C(   745.20),
        SIMDE_FLOAT32_C(  -641.78), SIMDE_FLOAT32_C(   814.36), SIMDE_FLOAT32_C(   682.53), SIMDE_FLOAT32_C(  -736.14),
        SIMDE_FLOAT32_C(   161.04), SIMDE_FLOAT32_C(   910.69), SIMDE_FLOAT32_C(   936.49), SIMDE_FLOAT32_C(  -202.72),
        SIMDE_FLOAT32_C(  -852.66), SIMDE_FLOAT32_C(  -612.97), SIMDE_FLOAT32_C(   274.80), SIMDE_FLOAT32_C(  -341.23) },
      { -INT32_C(  1056769355),  INT32_C(   926232784),  INT32_C(  1407568244), -INT32_C(  1307414662), -INT32_C(  1834238220),  INT32_C(   886408112),  INT32_C(   385817150), -INT32_C(   480602834),
         INT32_C(  1604607119),  INT32_C(     9951628),  INT32_C(   492076194), -INT32_C(   540055829), -INT32_C(   713983452),  INT32_C(   990463741), -INT32_C(  1907226272),  INT32_C(   762424478) },
       INT32_C(           8),
       INT32_C(           8),
      { SIMDE_FLOAT32_C(    90.00),            SIMDE_MATH_NANF,      SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(     0.50),
                   SIMDE_MATH_NANF,            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   682.53),            SIMDE_MATH_NANF,
             SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(  -692.82), SIMDE_FLOAT32_C(   936.49), SIMDE_FLOAT32_C(-340282346638528859811704183484516925440.00),
             SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(     0.50), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     1.57) } },
    { { SIMDE_FLOAT32_C(  -242.28), SIMDE_FLOAT32_C(   780.00), SIMDE_FLOAT32_C(  -593.00), SIMDE_FLOAT32_C(  -267.73),
        SIMDE_FLOAT32_C(   311.65), SIMDE_FLOAT32_C(  -312.88), SIMDE_FLOAT32_C(   621.96), SIMDE_FLOAT32_C(   446.88),
        SIMDE_FLOAT32_C(    -5.69), SIMDE_FLOAT32_C(  -912.62), SIMDE_FLOAT32_C(  -370.13), SIMDE_FLOAT32_C(   787.60),
        SIMDE_FLOAT32_C(  -908.37), SIMDE_FLOAT32_C(  -717.31), SIMDE_FLOAT32_C(  -167.37), SIMDE_FLOAT32_C(   757.53) },
      { SIMDE_FLOAT32_C(   926.45), SIMDE_FLOAT32_C(  -218.77), SIMDE_FLOAT32_C(   502.73), SIMDE_FLOAT32_C(  -715.33),
        SIMDE_FLOAT32_C(  -404.41), SIMDE_FLOAT32_C(   185.27), SIMDE_FLOAT32_C(  -451.47), SIMDE_FLOAT32_C(   756.63),
        SIMDE_FLOAT32_C(    95.96), SIMDE_FLOAT32_C(  -514.97), SIMDE_FLOAT32_C(  -446.09), SIMDE_FLOAT32_C(   243.29),
        SIMDE_FLOAT32_C(  -127.94), SIMDE_FLOAT32_C(   828.70), SIMDE_FLOAT32_C(   902.06), SIMDE_FLOAT32_C(   629.78) },
      { -INT32_C(  1617783517),  INT32_C(  1351331817), -INT32_C(   126588290),  INT32_C(   586500572),  INT32_C(  1552101459),  INT32_C(   788140418), -INT32_C(  1724438653), -INT32_C(   678900557),
         INT32_C(  1266031201),  INT32_C(  1201340873),  INT32_C(  1212092268), -INT32_C(  1402325927), -INT32_C(   418845339), -INT32_C(  2112486657), -INT32_C(   602190551),  INT32_C(  2058593049) },
       INT32_C(         190),
       INT32_C(           8),
      { SIMDE_FLOAT32_C(    -1.00), SIMDE_FLOAT32_C(   780.00), SIMDE_FLOAT32_C(-340282346638528859811704183484516925440.00),            SIMDE_MATH_NANF,
        SIMDE_FLOAT32_C(    90.00),            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(    -1.00), SIMDE_FLOAT32_C(     1.57),
            -SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(    -0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     1.00),
        SIMDE_FLOAT32_C(    -0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     1.57), SIMDE_FLOAT32_C(    -0.00) } },
    { { SIMDE_FLOAT32_C(   608.70), SIMDE_FLOAT32_C(  -690.94), SIMDE_FLOAT32_C(  -637.94), SIMDE_FLOAT32_C(   -79.65),
        SIMDE_FLOAT32_C(    -3.82), SIMDE_FLOAT32_C(   984.02), SIMDE_FLOAT32_C(  -632.76), SIMDE_FLOAT32_C(   990.49),
        SIMDE_FLOAT32_C(  -928.60), SIMDE_FLOAT32_C(    -2.89), SIMDE_FLOAT32_C(   778.08), SIMDE_FLOAT32_C(  -836.97),
        SIMDE_FLOAT32_C(   279.80), SIMDE_FLOAT32_C(  -389.29), SIMDE_FLOAT32_C(   920.56), SIMDE_FLOAT32_C(   206.25) },
      { SIMDE_FLOAT32_C(   391.95), SIMDE_FLOAT32_C(   423.29), SIMDE_FLOAT32_C(   490.93), SIMDE_FLOAT32_C(   987.54),
        SIMDE_FLOAT32_C(  -391.44), SIMDE_FLOAT32_C(  -960.54), SIMDE_FLOAT32_C(   744.17), SIMDE_FLOAT32_C(   704.51),
        SIMDE_FLOAT32_C(  -475.51), SIMDE_FLOAT32_C(  -701.92), SIMDE_FLOAT32_C(   -52.19), SIMDE_FLOAT32_C(   396.55),
        SIMDE_FLOAT32_C(  -873.22), SIMDE_FLOAT32_C(  -150.13), SIMDE_FLOAT32_C(    26.33), SIMDE_FLOAT32_C(   735.48) },
      {  INT32_C(  1888997216),  INT32_C(  1137303310),  INT32_C(   933786954),  INT32_C(  2134282109), -INT32_C(   223823707),  INT32_C(  1997243603),  INT32_C(  1647674936), -INT32_C(  1399997365),
        -INT32_C(  1709431413),  INT32_C(  1323164932), -INT32_C(   679049894), -INT32_C(  1168720876),  INT32_C(  1219296885), -INT32_C(  1161840510), -INT32_C(  1994591170),  INT32_C(  1010150065) },
       INT32_C(         207),
       INT32_C(           4),
      { SIMDE_FLOAT32_C(    -0.00),     -SIMDE_MATH_INFINITYF,            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(    -0.00),
                   SIMDE_MATH_NANF, SIMDE_FLOAT32_C(    -0.00),      SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(     1.00),
        SIMDE_FLOAT32_C(     1.00), SIMDE_FLOAT32_C(340282346638528859811704183484516925440.00), SIMDE_FLOAT32_C(    -0.00), SIMDE_FLOAT32_C(     0.50),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     1.00), SIMDE_FLOAT32_C(     0.00),            SIMDE_MATH_NANF } },
    { { SIMDE_FLOAT32_C(   158.93), SIMDE_FLOAT32_C(   388.39), SIMDE_FLOAT32_C(  -344.17), SIMDE_FLOAT32_C(  -844.89),
        SIMDE_FLOAT32_C(   372.41), SIMDE_FLOAT32_C(    23.07), SIMDE_FLOAT32_C(  -854.40), SIMDE_FLOAT32_C(   443.80),
        SIMDE_FLOAT32_C(  -979.82), SIMDE_FLOAT32_C(   923.68), SIMDE_FLOAT32_C(   606.83), SIMDE_FLOAT32_C(   299.98),
        SIMDE_FLOAT32_C(  -465.60), SIMDE_FLOAT32_C(   527.39), SIMDE_FLOAT32_C(  -493.77), SIMDE_FLOAT32_C(   926.34) },
      { SIMDE_FLOAT32_C(   -49.32), SIMDE_FLOAT32_C(   997.16), SIMDE_FLOAT32_C(   913.89), SIMDE_FLOAT32_C(   559.23),
        SIMDE_FLOAT32_C(  -963.38), SIMDE_FLOAT32_C(   658.06), SIMDE_FLOAT32_C(   263.74), SIMDE_FLOAT32_C(  -438.89),
        SIMDE_FLOAT32_C(   956.14), SIMDE_FLOAT32_C(  -788.45), SIMDE_FLOAT32_C(   957.66), SIMDE_FLOAT32_C(  -917.08),
        SIMDE_FLOAT32_C(    61.42), SIMDE_FLOAT32_C(   -16.01), SIMDE_FLOAT32_C(   818.40), SIMDE_FLOAT32_C(  -779.65) },
      {  INT32_C(   948970163),  INT32_C(  1682794408), -INT32_C(  1143404611),  INT32_C(  1799234227), -INT32_C(   693503775), -INT32_C(  1081658603), -INT32_C(  1165048984),  INT32_C(  1307599258),
         INT32_C(   730235267), -INT32_C(  1500458008), -INT32_C(  1922995750),  INT32_C(  1845075851), -INT32_C(  1388076392),  INT32_C(  1047317205),  INT32_C(   670628493), -INT32_C(   545920933) },
       INT32_C(         105),
       INT32_C(           4),
      { SIMDE_FLOAT32_C(     0.00),      SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(     0.50),      SIMDE_MATH_INFINITYF,
            -SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(     0.50), SIMDE_FLOAT32_C(     0.50), SIMDE_FLOAT32_C(     1.57),
                   SIMDE_MATH_NANF,     -SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     1.57),
        SIMDE_FLOAT32_C(     1.00), SIMDE_FLOAT32_C(340282346638528859811704183484516925440.00),            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(-340282346638528859811704183484516925440.00) } },
    { { SIMDE_FLOAT32_C(  -627.62), SIMDE_FLOAT32_C(  -525.77), SIMDE_FLOAT32_C(  -624.54), SIMDE_FLOAT32_C(   744.79),
        SIMDE_FLOAT32_C(   497.30), SIMDE_FLOAT32_C(  -478.94), SIMDE_FLOAT32_C(   188.59), SIMDE_FLOAT32_C(   517.48),
        SIMDE_FLOAT32_C(  -555.26), SIMDE_FLOAT32_C(  -204.58), SIMDE_FLOAT32_C(  -182.54), SIMDE_FLOAT32_C(   -20.86),
        SIMDE_FLOAT32_C(  -677.19), SIMDE_FLOAT32_C(   323.69), SIMDE_FLOAT32_C(   -94.52), SIMDE_FLOAT32_C(   273.49) },
      { SIMDE_FLOAT32_C(   320.84), SIMDE_FLOAT32_C(  -180.63), SIMDE_FLOAT32_C(  -167.28), SIMDE_FLOAT32_C(   357.46),
        SIMDE_FLOAT32_C(  -522.58), SIMDE_FLOAT32_C(  -903.54), SIMDE_FLOAT32_C(   918.56), SIMDE_FLOAT32_C(  -566.44),
        SIMDE_FLOAT32_C(  -691.99), SIMDE_FLOAT32_C(   876.22), SIMDE_FLOAT32_C(  -483.53), SIMDE_FLOAT32_C(   369.44),
        SIMDE_FLOAT32_C(  -139.79), SIMDE_FLOAT32_C(  -665.13), SIMDE_FLOAT32_C(   589.78), SIMDE_FLOAT32_C(   232.59) },
      {  INT32_C(    78182554), -INT32_C(   108055207), -INT32_C(   778961874),  INT32_C(   161889855), -INT32_C(  1533549398), -INT32_C(   973095204),  INT32_C(   774823475), -INT32_C(  2080603927),
        -INT32_C(   762862472),  INT32_C(   147527642),  INT32_C(  1406753811),  INT32_C(  1146912922),  INT32_C(  1105785700), -INT32_C(   452532302), -INT32_C(  1357630266),  INT32_C(   758255797) },
       INT32_C(         181),
       INT32_C(           8),
      { SIMDE_FLOAT32_C(  -627.62), SIMDE_FLOAT32_C(    -1.00), SIMDE_FLOAT32_C(  -167.28), SIMDE_FLOAT32_C(   744.79),
            -SIMDE_MATH_INFINITYF,      SIMDE_MATH_INFINITYF,            SIMDE_MATH_NANF,            SIMDE_MATH_NANF,
                   SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -204.58),            SIMDE_MATH_NANF,     -SIMDE_MATH_INFINITYF,
        SIMDE_FLOAT32_C(  -139.79),      SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(     1.00),            SIMDE_MATH_NANF } },
    { { SIMDE_FLOAT32_C(  -190.89), SIMDE_FLOAT32_C(   965.24), SIMDE_FLOAT32_C(   -22.62), SIMDE_FLOAT32_C(  -693.59),
        SIMDE_FLOAT32_C(  -513.70), SIMDE_FLOAT32_C(  -834.03), SIMDE_FLOAT32_C(   823.89), SIMDE_FLOAT32_C(   -68.96),
        SIMDE_FLOAT32_C(   -38.61), SIMDE_FLOAT32_C(  -358.65), SIMDE_FLOAT32_C(   910.18), SIMDE_FLOAT32_C(   284.20),
        SIMDE_FLOAT32_C(   965.03), SIMDE_FLOAT32_C(  -184.34), SIMDE_FLOAT32_C(  -442.32), SIMDE_FLOAT32_C(   285.88) },
      { SIMDE_FLOAT32_C(   635.02), SIMDE_FLOAT32_C(   390.40), SIMDE_FLOAT32_C(  -356.66), SIMDE_FLOAT32_C(  -887.55),
        SIMDE_FLOAT32_C(   486.87), SIMDE_FLOAT32_C(  -438.10), SIMDE_FLOAT32_C(  -453.99), SIMDE_FLOAT32_C(   794.88),
        SIMDE_FLOAT32_C(  -561.88), SIMDE_FLOAT32_C(    62.48), SIMDE_FLOAT32_C(   164.32), SIMDE_FLOAT32_C(   298.34),
        SIMDE_FLOAT32_C(   397.35), SIMDE_FLOAT32_C(  -245.90), SIMDE_FLOAT32_C(  -469.07), SIMDE_FLOAT32_C(  -793.54) },
      {  INT32_C(   652515274), -INT32_C(   239061135), -INT32_C(  2024471404), -INT32_C(   734423316), -INT32_C(   778428516),  INT32_C(  1132874035),  INT32_C(   905491323),  INT32_C(  2097579955),
        -INT32_C(  1868240097), -INT32_C(  1233034206),  INT32_C(  1430181481),  INT32_C(   153712493), -INT32_C(   908409962), -INT32_C(  2012389364), -INT32_C(   943913708), -INT32_C(  1404779379) },
       INT32_C(         175),
       INT32_C(           8),
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(-340282346638528859811704183484516925440.00), SIMDE_FLOAT32_C(    -0.00),     -SIMDE_MATH_INFINITYF,
        SIMDE_FLOAT32_C(     1.57),            SIMDE_MATH_NANF,      SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(    -0.00),
        SIMDE_FLOAT32_C(   -38.61), SIMDE_FLOAT32_C(     0.50),      SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(   284.20),
        SIMDE_FLOAT32_C(    90.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(    -0.00), SIMDE_FLOAT32_C(    90.00) } },
    { { SIMDE_FLOAT32_C(  -280.66), SIMDE_FLOAT32_C(   508.31), SIMDE_FLOAT32_C(  -487.13), SIMDE_FLOAT32_C(   205.65),
        SIMDE_FLOAT32_C(   674.28), SIMDE_FLOAT32_C(  -663.24), SIMDE_FLOAT32_C(  -863.31), SIMDE_FLOAT32_C(  -364.33),
        SIMDE_FLOAT32_C(   -21.89), SIMDE_FLOAT32_C(  -953.13), SIMDE_FLOAT32_C(   919.87), SIMDE_FLOAT32_C(   -56.86),
        SIMDE_FLOAT32_C(  -137.47), SIMDE_FLOAT32_C(  -522.45), SIMDE_FLOAT32_C(  -770.98), SIMDE_FLOAT32_C(  -502.45) },
      { SIMDE_FLOAT32_C(   867.95), SIMDE_FLOAT32_C(  -127.64), SIMDE_FLOAT32_C(  -390.00), SIMDE_FLOAT32_C(   354.82),
        SIMDE_FLOAT32_C(   434.26), SIMDE_FLOAT32_C(   156.00), SIMDE_FLOAT32_C(   149.70), SIMDE_FLOAT32_C(   872.38),
        SIMDE_FLOAT32_C(  -781.52), SIMDE_FLOAT32_C(  -685.98), SIMDE_FLOAT32_C(   170.72), SIMDE_FLOAT32_C(   615.83),
        SIMDE_FLOAT32_C(    68.12), SIMDE_FLOAT32_C(   701.65), SIMDE_FLOAT32_C(   822.29), SIMDE_FLOAT32_C(   787.46) },
      { -INT32_C(  1816753987),  INT32_C(  1023413190), -INT32_C(   120321483),  INT32_C(  1157996004), -INT32_C(  1336308310),  INT32_C(   238886986),  INT32_C(  1304291684), -INT32_C(   493187291),
        -INT32_C(   579514345), -INT32_C(  1877313957),  INT32_C(  1686761088),  INT32_C(   917081740),  INT32_C(  1709572635), -INT32_C(  2022431966),  INT32_C(   835989772), -INT32_C(   686592320) },
       INT32_C(         190),
       INT32_C(           8),
      { SIMDE_FLOAT32_C(    -1.00), SIMDE_FLOAT32_C(     1.57), SIMDE_FLOAT32_C(     0.00),     -SIMDE_MATH_INFINITYF,
        SIMDE_FLOAT32_C(     0.50), SIMDE_FLOAT32_C(  -663.24),     -SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(340282346638528859811704183484516925440.00),
        SIMDE_FLOAT32_C(     1.57), SIMDE_FLOAT32_C(  -953.13),      SIMDE_MATH_INFINITYF,            SIMDE_MATH_NANF,
             SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(     0.00),            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(     1.57) } },
  };

  simde__m512 a, b, r;
  simde__m512i c;

  a = simde_mm512_loadu_ps(test_vec[0].a);
  b = simde_mm512_loadu_ps(test_vec[0].b);
  c = simde_mm512_loadu_epi32(test_vec[0].c);
  r = simde_mm512_fixupimm_round_ps(a, b, c, INT32_C(         203), INT32_C(           8));
  simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[0].r), 1);

  a = simde_mm512_loadu_ps(test_vec[1].a);
  b = simde_mm512_loadu_ps(test_vec[1].b);
  c = simde_mm512_loadu_epi32(test_vec[1].c);
  r = simde_mm512_fixupimm_round_ps(a, b, c, INT32_C(           8), INT32_C(           8));
  simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[1].r), 1);

  a = simde_mm512_loadu_ps(test_vec[2].a);
  b = simde_mm512_loadu_ps(test_vec[2].b);
  c = simde_mm512_loadu_epi32(test_vec[2].c);
  r = simde_mm512_fixupimm_round_ps(a, b, c, INT32_C(         190), INT32_C(           8));
  simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[2].r), 1);

  a = simde_mm512_loadu_ps(test_vec[3].a);
  b = simde_mm512_loadu_ps(test_vec[3].b);
  c = simde_mm512_loadu_epi32(test_vec[3].c);
  r = simde_mm512_fixupimm_round_ps(a, b, c, INT32_C(         207), INT32_C(           4));
  simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[3].r), 1);

  a = simde_mm512_loadu_ps(test_vec[4].a);
  b = simde_mm512_loadu_ps(test_vec[4].b);
  c = simde_mm512_loadu_epi32(test_vec[4].c);
  r = simde_mm512_fixupimm_round_ps(a, b, c, INT32_C(         105), INT32_C(           4));
  simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[4].r), 1);

  a = simde_mm512_loadu_ps(test_vec[5].a);
  b = simde_mm512_loadu_ps(test_vec[5].b);
  c = simde_mm512_loadu_epi32(test_vec[5].c);
  r = simde_mm512_fixupimm_round_ps(a, b, c, INT32_C(         181), INT32_C(           8));
  simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[5].r), 1);

  a = simde_mm512_loadu_ps(test_vec[6].a);
  b = simde_mm512_loadu_ps(test_vec[6].b);
  c = simde_mm512_loadu_epi32(test_vec[6].c);
  r = simde_mm512_fixupimm_round_ps(a, b, c, INT32_C(         175), INT32_C(           8));
  simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[6].r), 1);

  a = simde_mm512_loadu_ps(test_vec[7].a);
  b = simde_mm512_loadu_ps(test_vec[7].b);
  c = simde_mm512_loadu_epi32(test_vec[7].c);
  r = simde_mm512_fixupimm_round_ps(a, b, c, INT32_C(         190), INT32_C(           8));
  simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[7].r), 1);

  return 0;
#else
  fputc('\n', stdout);
  simde_float32 values[8 * 2 * sizeof(simde__m512)];
  simde_test_x86_random_f32x16_full(8, 2, values, -1000.0f, 1000.0f, SIMDE_TEST_VEC_FLOAT_NAN);

  for (size_t i = 0 ; i < 8 ; i++) {
    simde__m512 a = simde_test_x86_random_extract_f32x16(i, 2, 0, values);
    simde__m512 b = simde_test_x86_random_extract_f32x16(i, 2, 1, values);
    simde__m512i c = simde_test_x86_random_i32x16();
    int32_t imm8 = simde_test_codegen_random_i32() & 255;
    int32_t sae = simde_test_codegen_rand() & 1 ? SIMDE_MM_FROUND_NO_EXC : SIMDE_MM_FROUND_CUR_DIRECTION;
    simde__m512 r;
    SIMDE_CONSTIFY_256_NEW(simde_mm512_fixupimm_round_ps, r, simde_mm512_setzero_ps(), imm8, sae, a, b, c);

    simde_test_x86_write_f32x16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_f32x16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x16(2, c, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, imm8, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, sae, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f32x16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}
#endif

static int
test_simde_mm512_mask_fixupimm_round_ps (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde_float32 a[16];
    const simde__mmask16 k;
    const simde_float32 b[16];
    const int32_t c[16];
    const int imm8;
    const int sae;
    const simde_float32 r[16];
  } test_vec[] = {
    { {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   717.49),            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   949.63),
        SIMDE_FLOAT32_C(  -127.43), SIMDE_FLOAT32_C(    98.90), SIMDE_FLOAT32_C(   851.71), SIMDE_FLOAT32_C(  -425.50),
        SIMDE_FLOAT32_C(  -862.77), SIMDE_FLOAT32_C(   555.31), SIMDE_FLOAT32_C(  -957.24), SIMDE_FLOAT32_C(   524.65),
        SIMDE_FLOAT32_C(   510.73), SIMDE_FLOAT32_C(   470.26), SIMDE_FLOAT32_C(   216.49), SIMDE_FLOAT32_C(  -220.53) },
      UINT16_C(34923),
      { SIMDE_FLOAT32_C(  -799.00),            SIMDE_MATH_NANF,            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -641.87),
        SIMDE_FLOAT32_C(  -158.49), SIMDE_FLOAT32_C(  -348.69), SIMDE_FLOAT32_C(  -156.78), SIMDE_FLOAT32_C(  -715.61),
        SIMDE_FLOAT32_C(  -479.20), SIMDE_FLOAT32_C(   469.73), SIMDE_FLOAT32_C(  -462.15), SIMDE_FLOAT32_C(  -822.56),
        SIMDE_FLOAT32_C(   345.36), SIMDE_FLOAT32_C(  -722.77), SIMDE_FLOAT32_C(   958.22), SIMDE_FLOAT32_C(   408.69) },
      { -INT32_C(   418002665),  INT32_C(  1912938350),  INT32_C(     1859954), -INT32_C(  2029836534),  INT32_C(  1594346097), -INT32_C(  1388315549),  INT32_C(  1770789115), -INT32_C(  1175259230),
         INT32_C(   782239680), -INT32_C(  1734236634),  INT32_C(   295222535),  INT32_C(  1452841957), -INT32_C(   910844059), -INT32_C(  1753811812), -INT32_C(  1358953972), -INT32_C(  1184304391) },
       INT32_C(         249),
       INT32_C(           8),
      { SIMDE_FLOAT32_C(    -0.00), SIMDE_FLOAT32_C(340282346638528859811704183484516925440.00),            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(    -0.00),
        SIMDE_FLOAT32_C(  -127.43), SIMDE_FLOAT32_C(     1.57), SIMDE_FLOAT32_C(    -1.00), SIMDE_FLOAT32_C(  -425.50),
        SIMDE_FLOAT32_C(  -862.77), SIMDE_FLOAT32_C(   555.31), SIMDE_FLOAT32_C(  -957.24),     -SIMDE_MATH_INFINITYF,
        SIMDE_FLOAT32_C(   510.73), SIMDE_FLOAT32_C(   470.26), SIMDE_FLOAT32_C(   216.49), SIMDE_FLOAT32_C(     0.50) } },
    { { SIMDE_FLOAT32_C(   994.71), SIMDE_FLOAT32_C(  -679.53), SIMDE_FLOAT32_C(   358.32), SIMDE_FLOAT32_C(  -132.71),
        SIMDE_FLOAT32_C(   419.37), SIMDE_FLOAT32_C(   210.03), SIMDE_FLOAT32_C(   441.78), SIMDE_FLOAT32_C(   556.60),
        SIMDE_FLOAT32_C(  -234.66), SIMDE_FLOAT32_C(   484.55), SIMDE_FLOAT32_C(    81.25), SIMDE_FLOAT32_C(  -723.93),
        SIMDE_FLOAT32_C(   -45.19), SIMDE_FLOAT32_C(  -702.26), SIMDE_FLOAT32_C(    55.54), SIMDE_FLOAT32_C(   155.81) },
      UINT16_C(46984),
      { SIMDE_FLOAT32_C(  -343.03), SIMDE_FLOAT32_C(   206.89), SIMDE_FLOAT32_C(   513.93), SIMDE_FLOAT32_C(   498.47),
        SIMDE_FLOAT32_C(   858.20), SIMDE_FLOAT32_C(  -642.85), SIMDE_FLOAT32_C(   782.87), SIMDE_FLOAT32_C(  -621.01),
        SIMDE_FLOAT32_C(   826.88), SIMDE_FLOAT32_C(  -679.28), SIMDE_FLOAT32_C(  -443.56), SIMDE_FLOAT32_C(   172.25),
        SIMDE_FLOAT32_C(  -402.06), SIMDE_FLOAT32_C(  -485.34), SIMDE_FLOAT32_C(  -419.07), SIMDE_FLOAT32_C(  -407.35) },
      { -INT32_C(   951105866), -INT32_C(  2124420309),  INT32_C(   423034704),  INT32_C(   848243355), -INT32_C(   449670858),  INT32_C(  1129194890),  INT32_C(  1043027742), -INT32_C(  1124748538),
         INT32_C(   612582905), -INT32_C(  2136612304),  INT32_C(  2090523617),  INT32_C(  1018046725),  INT32_C(  1159848379),  INT32_C(   612986630), -INT32_C(   865946426),  INT32_C(  1636325479) },
       INT32_C(         157),
       INT32_C(           4),
      { SIMDE_FLOAT32_C(   994.71), SIMDE_FLOAT32_C(  -679.53), SIMDE_FLOAT32_C(   358.32),            SIMDE_MATH_NANF,
        SIMDE_FLOAT32_C(   419.37), SIMDE_FLOAT32_C(   210.03), SIMDE_FLOAT32_C(   441.78), SIMDE_FLOAT32_C(    90.00),
                   SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   484.55), SIMDE_FLOAT32_C(    90.00), SIMDE_FLOAT32_C(  -723.93),
             SIMDE_MATH_INFINITYF,     -SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(    55.54), SIMDE_FLOAT32_C(  -407.35) } },
    { { SIMDE_FLOAT32_C(  -164.88), SIMDE_FLOAT32_C(   939.25), SIMDE_FLOAT32_C(   459.94), SIMDE_FLOAT32_C(  -745.51),
        SIMDE_FLOAT32_C(   149.28), SIMDE_FLOAT32_C(   -98.28), SIMDE_FLOAT32_C(   811.09), SIMDE_FLOAT32_C(   914.62),
        SIMDE_FLOAT32_C(  -613.73), SIMDE_FLOAT32_C(  -107.65), SIMDE_FLOAT32_C(  -809.31), SIMDE_FLOAT32_C(   341.07),
        SIMDE_FLOAT32_C(   190.09), SIMDE_FLOAT32_C(   246.23), SIMDE_FLOAT32_C(  -503.12), SIMDE_FLOAT32_C(   847.05) },
      UINT16_C(19755),
      { SIMDE_FLOAT32_C(  -546.89), SIMDE_FLOAT32_C(  -989.19), SIMDE_FLOAT32_C(   345.53), SIMDE_FLOAT32_C(  -688.69),
        SIMDE_FLOAT32_C(  -632.04), SIMDE_FLOAT32_C(   128.39), SIMDE_FLOAT32_C(  -309.70), SIMDE_FLOAT32_C(  -805.15),
        SIMDE_FLOAT32_C(   449.11), SIMDE_FLOAT32_C(   246.74), SIMDE_FLOAT32_C(   367.09), SIMDE_FLOAT32_C(  -952.95),
        SIMDE_FLOAT32_C(   761.40), SIMDE_FLOAT32_C(   948.02), SIMDE_FLOAT32_C(  -360.30), SIMDE_FLOAT32_C(  -403.48) },
      {  INT32_C(  1290208975),  INT32_C(  1224347916),  INT32_C(   292150220),  INT32_C(   110811617),  INT32_C(  1818775199),  INT32_C(   401916086),  INT32_C(   714866781), -INT32_C(  1116157970),
        -INT32_C(   636919858),  INT32_C(  1008862320), -INT32_C(  1051816993),  INT32_C(    80210020), -INT32_C(   311414985),  INT32_C(  1292133616),  INT32_C(  1383637092),  INT32_C(   907079784) },
       INT32_C(          79),
       INT32_C(           8),
      { SIMDE_FLOAT32_C(    90.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   459.94),     -SIMDE_MATH_INFINITYF,
        SIMDE_FLOAT32_C(   149.28), SIMDE_FLOAT32_C(   128.39), SIMDE_FLOAT32_C(   811.09), SIMDE_FLOAT32_C(   914.62),
        SIMDE_FLOAT32_C(     1.57), SIMDE_FLOAT32_C(  -107.65), SIMDE_FLOAT32_C(    90.00),     -SIMDE_MATH_INFINITYF,
        SIMDE_FLOAT32_C(   190.09), SIMDE_FLOAT32_C(   246.23),            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   847.05) } },
    { { SIMDE_FLOAT32_C(   887.27), SIMDE_FLOAT32_C(  -900.36), SIMDE_FLOAT32_C(  -148.99), SIMDE_FLOAT32_C(    36.55),
        SIMDE_FLOAT32_C(     1.36), SIMDE_FLOAT32_C(  -337.89), SIMDE_FLOAT32_C(   -48.83), SIMDE_FLOAT32_C(   387.63),
        SIMDE_FLOAT32_C(   554.45), SIMDE_FLOAT32_C(   141.86), SIMDE_FLOAT32_C(  -271.30), SIMDE_FLOAT32_C(  -255.46),
        SIMDE_FLOAT32_C(  -611.92), SIMDE_FLOAT32_C(   225.58), SIMDE_FLOAT32_C(  -408.41), SIMDE_FLOAT32_C(  -158.80) },
      UINT16_C(64562),
      { SIMDE_FLOAT32_C(   236.40), SIMDE_FLOAT32_C(   937.12), SIMDE_FLOAT32_C(   152.51), SIMDE_FLOAT32_C(   604.36),
        SIMDE_FLOAT32_C(    65.51), SIMDE_FLOAT32_C(   842.81), SIMDE_FLOAT32_C(   799.21), SIMDE_FLOAT32_C(  -485.38),
        SIMDE_FLOAT32_C(    89.55), SIMDE_FLOAT32_C(   166.30), SIMDE_FLOAT32_C(  -438.33), SIMDE_FLOAT32_C(  -149.05),
        SIMDE_FLOAT32_C(   114.32), SIMDE_FLOAT32_C(   201.37), SIMDE_FLOAT32_C(   447.47), SIMDE_FLOAT32_C(     1.59) },
      { -INT32_C(  1102397955),  INT32_C(   646263586),  INT32_C(  1469494378), -INT32_C(   228853084), -INT32_C(  1318388897), -INT32_C(  1715381661),  INT32_C(  1772739497), -INT32_C(   177808392),
        -INT32_C(  1145851751),  INT32_C(  1306605795), -INT32_C(  1851492371), -INT32_C(   796655759),  INT32_C(  1585638907), -INT32_C(   235388089),  INT32_C(   391815454),  INT32_C(   369934461) },
       INT32_C(         113),
       INT32_C(           4),
      { SIMDE_FLOAT32_C(   887.27),            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -148.99), SIMDE_FLOAT32_C(    36.55),
        SIMDE_FLOAT32_C(     0.50), SIMDE_FLOAT32_C(    -1.00), SIMDE_FLOAT32_C(   -48.83), SIMDE_FLOAT32_C(   387.63),
        SIMDE_FLOAT32_C(   554.45), SIMDE_FLOAT32_C(   141.86), SIMDE_FLOAT32_C(  -438.33), SIMDE_FLOAT32_C(  -255.46),
             SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(-340282346638528859811704183484516925440.00), SIMDE_FLOAT32_C(   447.47), SIMDE_FLOAT32_C(     1.59) } },
    { { SIMDE_FLOAT32_C(   301.01), SIMDE_FLOAT32_C(  -701.52), SIMDE_FLOAT32_C(  -961.85), SIMDE_FLOAT32_C(  -697.62),
        SIMDE_FLOAT32_C(   -39.41), SIMDE_FLOAT32_C(   -10.69), SIMDE_FLOAT32_C(   690.01), SIMDE_FLOAT32_C(  -484.96),
        SIMDE_FLOAT32_C(  -868.83), SIMDE_FLOAT32_C(  -581.29), SIMDE_FLOAT32_C(   259.58), SIMDE_FLOAT32_C(  -480.75),
        SIMDE_FLOAT32_C(   644.30), SIMDE_FLOAT32_C(   851.17), SIMDE_FLOAT32_C(   360.45), SIMDE_FLOAT32_C(  -119.31) },
      UINT16_C(41650),
      { SIMDE_FLOAT32_C(   788.29), SIMDE_FLOAT32_C(  -487.04), SIMDE_FLOAT32_C(  -514.95), SIMDE_FLOAT32_C(  -146.20),
        SIMDE_FLOAT32_C(  -644.24), SIMDE_FLOAT32_C(  -715.74), SIMDE_FLOAT32_C(   368.41), SIMDE_FLOAT32_C(   445.31),
        SIMDE_FLOAT32_C(   450.56), SIMDE_FLOAT32_C(   930.08), SIMDE_FLOAT32_C(  -703.74), SIMDE_FLOAT32_C(  -435.12),
        SIMDE_FLOAT32_C(   131.45), SIMDE_FLOAT32_C(   743.73), SIMDE_FLOAT32_C(   566.47), SIMDE_FLOAT32_C(  -567.54) },
      {  INT32_C(  2001086949),  INT32_C(  1811564186), -INT32_C(  1611798463),  INT32_C(   546779183),  INT32_C(  1719351631), -INT32_C(   864928842),  INT32_C(    27079340),  INT32_C(   279138091),
         INT32_C(   310897016),  INT32_C(  1887273519), -INT32_C(  1726977430), -INT32_C(   356866149), -INT32_C(  1773128224),  INT32_C(   493011568),  INT32_C(   538902517), -INT32_C(   969883314) },
       INT32_C(         170),
       INT32_C(           4),
      { SIMDE_FLOAT32_C(   301.01), SIMDE_FLOAT32_C(     0.50), SIMDE_FLOAT32_C(  -961.85), SIMDE_FLOAT32_C(  -697.62),
            -SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(    90.00), SIMDE_FLOAT32_C(   690.01), SIMDE_FLOAT32_C(   445.31),
        SIMDE_FLOAT32_C(  -868.83), SIMDE_FLOAT32_C(    -0.00), SIMDE_FLOAT32_C(   259.58), SIMDE_FLOAT32_C(  -480.75),
        SIMDE_FLOAT32_C(   644.30), SIMDE_FLOAT32_C(   743.73), SIMDE_FLOAT32_C(   360.45),     -SIMDE_MATH_INFINITYF } },
    { { SIMDE_FLOAT32_C(  -957.79), SIMDE_FLOAT32_C(   604.62), SIMDE_FLOAT32_C(  -265.16), SIMDE_FLOAT32_C(     2.81),
        SIMDE_FLOAT32_C(  -406.07), SIMDE_FLOAT32_C(  -575.15), SIMDE_FLOAT32_C(   517.85), SIMDE_FLOAT32_C(  -274.90),
        SIMDE_FLOAT32_C(  -156.44), SIMDE_FLOAT32_C(  -222.57), SIMDE_FLOAT32_C(   244.36), SIMDE_FLOAT32_C(  -512.14),
        SIMDE_FLOAT32_C(  -371.40), SIMDE_FLOAT32_C(  -395.19), SIMDE_FLOAT32_C(   368.55), SIMDE_FLOAT32_C(  -583.11) },
      UINT16_C(19030),
      { SIMDE_FLOAT32_C(   117.76), SIMDE_FLOAT32_C(   853.60), SIMDE_FLOAT32_C(   270.69), SIMDE_FLOAT32_C(   473.53),
        SIMDE_FLOAT32_C(  -862.14), SIMDE_FLOAT32_C(  -360.90), SIMDE_FLOAT32_C(   -81.16), SIMDE_FLOAT32_C(   588.42),
        SIMDE_FLOAT32_C(  -430.82), SIMDE_FLOAT32_C(   215.10), SIMDE_FLOAT32_C(  -846.71), SIMDE_FLOAT32_C(   700.63),
        SIMDE_FLOAT32_C(   -41.16), SIMDE_FLOAT32_C(   719.77), SIMDE_FLOAT32_C(  -866.91), SIMDE_FLOAT32_C(     1.05) },
      {  INT32_C(  1029357988),  INT32_C(  1190593116),  INT32_C(  2039885026), -INT32_C(  1160030051),  INT32_C(  1842928461), -INT32_C(   258041559),  INT32_C(   499734083),  INT32_C(   879239056),
         INT32_C(  1014088416), -INT32_C(  1484625468),  INT32_C(   840964245), -INT32_C(  1091765391),  INT32_C(     2933974), -INT32_C(  1578055075), -INT32_C(  1329678048), -INT32_C(  1176230184) },
       INT32_C(         233),
       INT32_C(           4),
      { SIMDE_FLOAT32_C(  -957.79),     -SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(    -0.00), SIMDE_FLOAT32_C(     2.81),
        SIMDE_FLOAT32_C(     1.57), SIMDE_FLOAT32_C(  -575.15), SIMDE_FLOAT32_C(     1.57), SIMDE_FLOAT32_C(  -274.90),
        SIMDE_FLOAT32_C(  -156.44), SIMDE_FLOAT32_C(     1.00), SIMDE_FLOAT32_C(   244.36), SIMDE_FLOAT32_C(     0.50),
        SIMDE_FLOAT32_C(  -371.40), SIMDE_FLOAT32_C(  -395.19), SIMDE_FLOAT32_C(   368.55), SIMDE_FLOAT32_C(  -583.11) } },
    { { SIMDE_FLOAT32_C(   324.39), SIMDE_FLOAT32_C(  -132.07), SIMDE_FLOAT32_C(  -996.14), SIMDE_FLOAT32_C(   918.32),
        SIMDE_FLOAT32_C(   292.78), SIMDE_FLOAT32_C(   521.70), SIMDE_FLOAT32_C(  -356.58), SIMDE_FLOAT32_C(  -863.65),
        SIMDE_FLOAT32_C(  -700.87), SIMDE_FLOAT32_C(   887.78), SIMDE_FLOAT32_C(  -375.80), SIMDE_FLOAT32_C(   -72.27),
        SIMDE_FLOAT32_C(  -507.42), SIMDE_FLOAT32_C(   992.75), SIMDE_FLOAT32_C(   344.62), SIMDE_FLOAT32_C(   610.35) },
      UINT16_C(21624),
      { SIMDE_FLOAT32_C(   846.36), SIMDE_FLOAT32_C(  -384.69), SIMDE_FLOAT32_C(    83.88), SIMDE_FLOAT32_C(   984.22),
        SIMDE_FLOAT32_C(   254.41), SIMDE_FLOAT32_C(  -997.28), SIMDE_FLOAT32_C(   572.63), SIMDE_FLOAT32_C(   823.58),
        SIMDE_FLOAT32_C(   217.83), SIMDE_FLOAT32_C(   725.93), SIMDE_FLOAT32_C(   524.21), SIMDE_FLOAT32_C(  -823.34),
        SIMDE_FLOAT32_C(   445.70), SIMDE_FLOAT32_C(   657.31), SIMDE_FLOAT32_C(   177.71), SIMDE_FLOAT32_C(  -229.92) },
      { -INT32_C(  2039181228), -INT32_C(  1066176511),  INT32_C(  1189885766),  INT32_C(   909555349), -INT32_C(  2030768170), -INT32_C(  2123752504), -INT32_C(  1317617916), -INT32_C(   771297666),
        -INT32_C(  2141685121),  INT32_C(   826330090), -INT32_C(  1737020413), -INT32_C(  1194414366),  INT32_C(  1698611869), -INT32_C(   504977187), -INT32_C(   426549912), -INT32_C(   893871797) },
       INT32_C(          19),
       INT32_C(           4),
      { SIMDE_FLOAT32_C(   324.39), SIMDE_FLOAT32_C(  -132.07), SIMDE_FLOAT32_C(  -996.14),            SIMDE_MATH_NANF,
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(  -997.28), SIMDE_FLOAT32_C(     0.50), SIMDE_FLOAT32_C(  -863.65),
        SIMDE_FLOAT32_C(  -700.87), SIMDE_FLOAT32_C(   887.78), SIMDE_FLOAT32_C(    -1.00), SIMDE_FLOAT32_C(   -72.27),
             SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(   992.75), SIMDE_FLOAT32_C(340282346638528859811704183484516925440.00), SIMDE_FLOAT32_C(   610.35) } },
    { { SIMDE_FLOAT32_C(  -474.76), SIMDE_FLOAT32_C(   181.57), SIMDE_FLOAT32_C(  -311.60), SIMDE_FLOAT32_C(   818.03),
        SIMDE_FLOAT32_C(  -296.73), SIMDE_FLOAT32_C(   331.82), SIMDE_FLOAT32_C(   954.37), SIMDE_FLOAT32_C(     2.40),
        SIMDE_FLOAT32_C(   219.59), SIMDE_FLOAT32_C(  -421.42), SIMDE_FLOAT32_C(   930.13), SIMDE_FLOAT32_C(   712.18),
        SIMDE_FLOAT32_C(  -428.67), SIMDE_FLOAT32_C(   274.75), SIMDE_FLOAT32_C(   322.53), SIMDE_FLOAT32_C(  -582.31) },
      UINT16_C(12171),
      { SIMDE_FLOAT32_C(   890.06), SIMDE_FLOAT32_C(  -593.59), SIMDE_FLOAT32_C(  -598.10), SIMDE_FLOAT32_C(   144.47),
        SIMDE_FLOAT32_C(  -590.87), SIMDE_FLOAT32_C(   974.54), SIMDE_FLOAT32_C(   -31.95), SIMDE_FLOAT32_C(   626.95),
        SIMDE_FLOAT32_C(   700.46), SIMDE_FLOAT32_C(  -507.74), SIMDE_FLOAT32_C(   803.61), SIMDE_FLOAT32_C(   146.16),
        SIMDE_FLOAT32_C(  -850.43), SIMDE_FLOAT32_C(   -18.68), SIMDE_FLOAT32_C(   916.24), SIMDE_FLOAT32_C(  -325.19) },
      {  INT32_C(  2007415007),  INT32_C(  1397052570),  INT32_C(  1469122546), -INT32_C(   969000219), -INT32_C(  2007393374), -INT32_C(  1321143578),  INT32_C(    83644422),  INT32_C(   187926316),
        -INT32_C(   628958913),  INT32_C(   539871022), -INT32_C(  1267220785), -INT32_C(  1703234056),  INT32_C(   925029456), -INT32_C(   857185594), -INT32_C(   539958093), -INT32_C(  1410661525) },
       INT32_C(         221),
       INT32_C(           8),
      { SIMDE_FLOAT32_C(    -0.00),            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -311.60), SIMDE_FLOAT32_C(    90.00),
        SIMDE_FLOAT32_C(  -296.73), SIMDE_FLOAT32_C(   331.82), SIMDE_FLOAT32_C(   954.37), SIMDE_FLOAT32_C(     2.40),
        SIMDE_FLOAT32_C(     1.57), SIMDE_FLOAT32_C(  -421.42), SIMDE_FLOAT32_C(     0.50), SIMDE_FLOAT32_C(    -1.00),
        SIMDE_FLOAT32_C(  -428.67), SIMDE_FLOAT32_C(    90.00), SIMDE_FLOAT32_C(   322.53), SIMDE_FLOAT32_C(  -582.31) } },
  };

  simde__m512 a, b, r;
  simde__m512i c;

  #if !defined(SIMDE_FAST_MATH)
  a = simde_mm512_loadu_ps(test_vec[0].a);
  b = simde_mm512_loadu_ps(test_vec[0].b);
  c = simde_mm512_loadu_epi32(test_vec[0].c);
  r = simde_mm512_mask_fixupimm_round_ps(a, test_vec[0].k, b, c, INT32_C(         249), INT32_C(           8));
  simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[0].r), 1);

  a = simde_mm512_loadu_ps(test_vec[1].a);
  b = simde_mm512_loadu_ps(test_vec[1].b);
  c = simde_mm512_loadu_epi32(test_vec[1].c);
  r = simde_mm512_mask_fixupimm_round_ps(a, test_vec[1].k, b, c, INT32_C(         157), INT32_C(           4));
  simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[1].r), 1);

  a = simde_mm512_loadu_ps(test_vec[2].a);
  b = simde_mm512_loadu_ps(test_vec[2].b);
  c = simde_mm512_loadu_epi32(test_vec[2].c);
  r = simde_mm512_mask_fixupimm_round_ps(a, test_vec[2].k, b, c, INT32_C(          79), INT32_C(           8));
  simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[2].r), 1);

  a = simde_mm512_loadu_ps(test_vec[3].a);
  b = simde_mm512_loadu_ps(test_vec[3].b);
  c = simde_mm512_loadu_epi32(test_vec[3].c);
  r = simde_mm512_mask_fixupimm_round_ps(a, test_vec[3].k, b, c, INT32_C(         113), INT32_C(           4));
  simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[3].r), 1);
  #endif

  a = simde_mm512_loadu_ps(test_vec[4].a);
  b = simde_mm512_loadu_ps(test_vec[4].b);
  c = simde_mm512_loadu_epi32(test_vec[4].c);
  r = simde_mm512_mask_fixupimm_round_ps(a, test_vec[4].k, b, c, INT32_C(         170), INT32_C(           4));
  simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[4].r), 1);

  a = simde_mm512_loadu_ps(test_vec[5].a);
  b = simde_mm512_loadu_ps(test_vec[5].b);
  c = simde_mm512_loadu_epi32(test_vec[5].c);
  r = simde_mm512_mask_fixupimm_round_ps(a, test_vec[5].k, b, c, INT32_C(         233), INT32_C(           4));
  simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[5].r), 1);

  #if !defined(SIMDE_FAST_MATH)
  a = simde_mm512_loadu_ps(test_vec[6].a);
  b = simde_mm512_loadu_ps(test_vec[6].b);
  c = simde_mm512_loadu_epi32(test_vec[6].c);
  r = simde_mm512_mask_fixupimm_round_ps(a, test_vec[6].k, b, c, INT32_C(          19), INT32_C(           4));
  simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[6].r), 1);

  a = simde_mm512_loadu_ps(test_vec[7].a);
  b = simde_mm512_loadu_ps(test_vec[7].b);
  c = simde_mm512_loadu_epi32(test_vec[7].c);
  r = simde_mm512_mask_fixupimm_round_ps(a, test_vec[7].k, b, c, INT32_C(         221), INT32_C(           8));
  simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[7].r), 1);
  #endif

  return 0;
#else
  fputc('\n', stdout);
  simde_float32 values[8 * 2 * sizeof(simde__m512)];
  simde_test_x86_random_f32x16_full(8, 2, values, -1000.0f, 1000.0f, SIMDE_TEST_VEC_FLOAT_NAN);

  for (size_t i = 0 ; i < 8 ; i++) {
    simde__m512 a = simde_test_x86_random_extract_f32x16(i, 2, 0, values);
    simde__mmask16 k = simde_test_x86_random_mmask16();
    simde__m512 b = simde_test_x86_random_extract_f32x16(i, 2, 1, values);
    simde__m512i c = simde_test_x86_random_i32x16();
    int32_t imm8 = simde_test_codegen_random_i32() & 255;
    int32_t sae = simde_test_codegen_rand() & 1 ? SIMDE_MM_FROUND_NO_EXC : SIMDE_MM_FROUND_CUR_DIRECTION;
    simde__m512 r;
    SIMDE_CONSTIFY_256_NEW(simde_mm512_mask_fixupimm_round_ps, r, simde_mm512_setzero_ps(), imm8, sae, a, k, b, c);

    simde_test_x86_write_f32x16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_mmask16(2, k, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f32x16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x16(2, c, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, imm8, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, sae, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f32x16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  fprintf(stderr, "-------------------------\n------------------------\n----------------------\n");
  return 1;
#endif
}

static int
test_simde_mm512_maskz_fixupimm_round_ps (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask16 k;
    const simde_float32 a[16];
    const simde_float32 b[16];
    const int32_t c[16];
    const int imm8;
    const int sae;
    const simde_float32 r[16];
  } test_vec[] = {
    { UINT16_C(58968),
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   750.06),            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   588.42),
        SIMDE_FLOAT32_C(  -180.88), SIMDE_FLOAT32_C(   317.29), SIMDE_FLOAT32_C(   395.27), SIMDE_FLOAT32_C(    57.07),
        SIMDE_FLOAT32_C(  -754.03), SIMDE_FLOAT32_C(   703.53), SIMDE_FLOAT32_C(   331.42), SIMDE_FLOAT32_C(   588.99),
        SIMDE_FLOAT32_C(  -937.18), SIMDE_FLOAT32_C(  -230.83), SIMDE_FLOAT32_C(  -868.54), SIMDE_FLOAT32_C(  -129.11) },
      { SIMDE_FLOAT32_C(  -220.13),            SIMDE_MATH_NANF,            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   552.45),
        SIMDE_FLOAT32_C(  -129.00), SIMDE_FLOAT32_C(   695.59), SIMDE_FLOAT32_C(  -879.64), SIMDE_FLOAT32_C(  -883.58),
        SIMDE_FLOAT32_C(   333.46), SIMDE_FLOAT32_C(   282.67), SIMDE_FLOAT32_C(  -744.96), SIMDE_FLOAT32_C(  -433.69),
        SIMDE_FLOAT32_C(  -220.29), SIMDE_FLOAT32_C(   928.69), SIMDE_FLOAT32_C(  -477.71), SIMDE_FLOAT32_C(   703.28) },
      { -INT32_C(  1049963273),  INT32_C(   871681320),  INT32_C(   677254200),  INT32_C(  1238148996), -INT32_C(   700097088),  INT32_C(  1626042968), -INT32_C(  1095245291), -INT32_C(   542830616),
         INT32_C(   211816420),  INT32_C(   356488413),  INT32_C(   759013033),  INT32_C(    91687493), -INT32_C(  1076118425),  INT32_C(  1142933038), -INT32_C(  1862084951), -INT32_C(   898521114) },
       INT32_C(         183),
       INT32_C(           4),
      { SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),     -SIMDE_MATH_INFINITYF,
            -SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(340282346638528859811704183484516925440.00), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   282.67), SIMDE_FLOAT32_C(     1.57), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(     0.00),     -SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(  -477.71), SIMDE_FLOAT32_C(    90.00) } },
    { UINT16_C(43286),
      { SIMDE_FLOAT32_C(   678.75), SIMDE_FLOAT32_C(   692.46), SIMDE_FLOAT32_C(   291.70), SIMDE_FLOAT32_C(  -502.13),
        SIMDE_FLOAT32_C(     9.75), SIMDE_FLOAT32_C(  -313.03), SIMDE_FLOAT32_C(   554.94), SIMDE_FLOAT32_C(   255.73),
        SIMDE_FLOAT32_C(  -609.50), SIMDE_FLOAT32_C(  -113.64), SIMDE_FLOAT32_C(  -155.28), SIMDE_FLOAT32_C(  -546.67),
        SIMDE_FLOAT32_C(   655.53), SIMDE_FLOAT32_C(   -23.82), SIMDE_FLOAT32_C(   324.21), SIMDE_FLOAT32_C(  -564.60) },
      { SIMDE_FLOAT32_C(   808.60), SIMDE_FLOAT32_C(   791.22), SIMDE_FLOAT32_C(   987.85), SIMDE_FLOAT32_C(  -320.40),
        SIMDE_FLOAT32_C(   486.81), SIMDE_FLOAT32_C(  -891.80), SIMDE_FLOAT32_C(  -203.98), SIMDE_FLOAT32_C(  -179.73),
        SIMDE_FLOAT32_C(   390.88), SIMDE_FLOAT32_C(    51.06), SIMDE_FLOAT32_C(   386.58), SIMDE_FLOAT32_C(  -829.41),
        SIMDE_FLOAT32_C(   -20.26), SIMDE_FLOAT32_C(   908.86), SIMDE_FLOAT32_C(   873.87), SIMDE_FLOAT32_C(  -341.51) },
      {  INT32_C(  2095559759), -INT32_C(    17567239),  INT32_C(   400142424),  INT32_C(   574071006), -INT32_C(   635105975), -INT32_C(  1119105805),  INT32_C(   395599235),  INT32_C(  1388423683),
         INT32_C(  1473161310), -INT32_C(   246037863),  INT32_C(  1342713458),  INT32_C(   393428942),  INT32_C(  1089640525), -INT32_C(   385991324), -INT32_C(  1644195174), -INT32_C(  1695563716) },
       INT32_C(         104),
       INT32_C(           4),
      { SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(-340282346638528859811704183484516925440.00), SIMDE_FLOAT32_C(   987.85), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(     1.57), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
             SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(    -0.00),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(340282346638528859811704183484516925440.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     1.00) } },
    { UINT16_C(62022),
      { SIMDE_FLOAT32_C(   601.33), SIMDE_FLOAT32_C(   165.57), SIMDE_FLOAT32_C(   156.36), SIMDE_FLOAT32_C(  -388.92),
        SIMDE_FLOAT32_C(   852.54), SIMDE_FLOAT32_C(  -288.70), SIMDE_FLOAT32_C(   866.81), SIMDE_FLOAT32_C(  -756.95),
        SIMDE_FLOAT32_C(   597.66), SIMDE_FLOAT32_C(  -288.47), SIMDE_FLOAT32_C(  -303.62), SIMDE_FLOAT32_C(   253.19),
        SIMDE_FLOAT32_C(   687.70), SIMDE_FLOAT32_C(  -979.41), SIMDE_FLOAT32_C(   688.59), SIMDE_FLOAT32_C(   496.30) },
      { SIMDE_FLOAT32_C(   811.81), SIMDE_FLOAT32_C(   676.44), SIMDE_FLOAT32_C(  -824.10), SIMDE_FLOAT32_C(   298.62),
        SIMDE_FLOAT32_C(   784.65), SIMDE_FLOAT32_C(   -28.08), SIMDE_FLOAT32_C(  -881.11), SIMDE_FLOAT32_C(   175.52),
        SIMDE_FLOAT32_C(  -977.02), SIMDE_FLOAT32_C(   505.47), SIMDE_FLOAT32_C(   346.11), SIMDE_FLOAT32_C(     2.72),
        SIMDE_FLOAT32_C(   414.33), SIMDE_FLOAT32_C(   219.98), SIMDE_FLOAT32_C(   661.21), SIMDE_FLOAT32_C(    15.66) },
      {  INT32_C(  1123775730),  INT32_C(  1521826371), -INT32_C(   934523513), -INT32_C(  1698264398), -INT32_C(  1030137820),  INT32_C(   783374996), -INT32_C(  1004572734), -INT32_C(   508140049),
         INT32_C(   472166873),  INT32_C(  1937234412), -INT32_C(   650394841),  INT32_C(  1920139597), -INT32_C(   315356071),  INT32_C(   689694054),  INT32_C(  1156397653),  INT32_C(  2032575391) },
       INT32_C(          85),
       INT32_C(           8),
      { SIMDE_FLOAT32_C(     0.00),      SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),     -SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(    -0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(340282346638528859811704183484516925440.00),            SIMDE_MATH_NANF,     -SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(    -0.00) } },
    { UINT16_C(46092),
      { SIMDE_FLOAT32_C(  -614.45), SIMDE_FLOAT32_C(  -182.43), SIMDE_FLOAT32_C(   626.74), SIMDE_FLOAT32_C(  -761.91),
        SIMDE_FLOAT32_C(   528.87), SIMDE_FLOAT32_C(   493.54), SIMDE_FLOAT32_C(  -518.86), SIMDE_FLOAT32_C(   126.53),
        SIMDE_FLOAT32_C(  -794.93), SIMDE_FLOAT32_C(   177.52), SIMDE_FLOAT32_C(  -620.27), SIMDE_FLOAT32_C(   892.78),
        SIMDE_FLOAT32_C(   198.11), SIMDE_FLOAT32_C(  -931.68), SIMDE_FLOAT32_C(   389.08), SIMDE_FLOAT32_C(     9.92) },
      { SIMDE_FLOAT32_C(   744.76), SIMDE_FLOAT32_C(   564.98), SIMDE_FLOAT32_C(  -691.46), SIMDE_FLOAT32_C(   529.41),
        SIMDE_FLOAT32_C(  -463.10), SIMDE_FLOAT32_C(  -572.57), SIMDE_FLOAT32_C(  -295.07), SIMDE_FLOAT32_C(  -440.12),
        SIMDE_FLOAT32_C(   932.90), SIMDE_FLOAT32_C(  -948.96), SIMDE_FLOAT32_C(   562.60), SIMDE_FLOAT32_C(   347.23),
        SIMDE_FLOAT32_C(   271.02), SIMDE_FLOAT32_C(   223.82), SIMDE_FLOAT32_C(  -637.11), SIMDE_FLOAT32_C(   656.56) },
      {  INT32_C(   602984522), -INT32_C(  1885933283),  INT32_C(   952345419),  INT32_C(   844409097),  INT32_C(  1109364478), -INT32_C(  1486306514),  INT32_C(  1497149976),  INT32_C(   537741782),
         INT32_C(   910490905),  INT32_C(   986110703), -INT32_C(  2022536835),  INT32_C(   817481266), -INT32_C(  2089559723), -INT32_C(  1272259684),  INT32_C(  1678599822), -INT32_C(   930866513) },
       INT32_C(          24),
       INT32_C(           8),
      { SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),            SIMDE_MATH_NANF,
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.50), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(    90.00) } },
    { UINT16_C(16837),
      { SIMDE_FLOAT32_C(  -958.61), SIMDE_FLOAT32_C(   989.63), SIMDE_FLOAT32_C(   894.66), SIMDE_FLOAT32_C(   570.26),
        SIMDE_FLOAT32_C(   483.18), SIMDE_FLOAT32_C(  -624.20), SIMDE_FLOAT32_C(  -303.20), SIMDE_FLOAT32_C(   688.25),
        SIMDE_FLOAT32_C(   553.32), SIMDE_FLOAT32_C(    76.52), SIMDE_FLOAT32_C(   581.03), SIMDE_FLOAT32_C(  -248.57),
        SIMDE_FLOAT32_C(   144.84), SIMDE_FLOAT32_C(   -29.90), SIMDE_FLOAT32_C(   761.35), SIMDE_FLOAT32_C(  -110.40) },
      { SIMDE_FLOAT32_C(  -464.91), SIMDE_FLOAT32_C(  -930.11), SIMDE_FLOAT32_C(  -580.99), SIMDE_FLOAT32_C(    71.99),
        SIMDE_FLOAT32_C(  -502.68), SIMDE_FLOAT32_C(   123.94), SIMDE_FLOAT32_C(   631.87), SIMDE_FLOAT32_C(  -569.77),
        SIMDE_FLOAT32_C(   174.97), SIMDE_FLOAT32_C(   194.47), SIMDE_FLOAT32_C(   777.46), SIMDE_FLOAT32_C(  -554.01),
        SIMDE_FLOAT32_C(  -581.71), SIMDE_FLOAT32_C(  -859.65), SIMDE_FLOAT32_C(  -897.45), SIMDE_FLOAT32_C(  -540.32) },
      { -INT32_C(  1481421280), -INT32_C(  1319011711),  INT32_C(  1378106063), -INT32_C(  1971584810), -INT32_C(   224927090),  INT32_C(  1517728146), -INT32_C(   799457335),  INT32_C(    34676450),
        -INT32_C(   290798227),  INT32_C(   245304127),  INT32_C(   459326533),  INT32_C(  1386601668),  INT32_C(  1346649278), -INT32_C(  1213482259), -INT32_C(   611908359), -INT32_C(  1864459997) },
       INT32_C(          94),
       INT32_C(           8),
      { SIMDE_FLOAT32_C(    -0.00), SIMDE_FLOAT32_C(     0.00),            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     1.57),            SIMDE_MATH_NANF,
        SIMDE_FLOAT32_C(340282346638528859811704183484516925440.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.50), SIMDE_FLOAT32_C(     0.00) } },
    { UINT16_C(43805),
      { SIMDE_FLOAT32_C(  -870.01), SIMDE_FLOAT32_C(   997.21), SIMDE_FLOAT32_C(  -970.06), SIMDE_FLOAT32_C(   613.16),
        SIMDE_FLOAT32_C(  -626.99), SIMDE_FLOAT32_C(  -273.26), SIMDE_FLOAT32_C(   301.41), SIMDE_FLOAT32_C(   926.33),
        SIMDE_FLOAT32_C(   803.26), SIMDE_FLOAT32_C(  -117.56), SIMDE_FLOAT32_C(  -322.25), SIMDE_FLOAT32_C(   -51.89),
        SIMDE_FLOAT32_C(   852.54), SIMDE_FLOAT32_C(  -560.90), SIMDE_FLOAT32_C(   837.71), SIMDE_FLOAT32_C(  -612.37) },
      { SIMDE_FLOAT32_C(  -491.01), SIMDE_FLOAT32_C(  -743.29), SIMDE_FLOAT32_C(   459.62), SIMDE_FLOAT32_C(     6.31),
        SIMDE_FLOAT32_C(   380.65), SIMDE_FLOAT32_C(    91.49), SIMDE_FLOAT32_C(   436.54), SIMDE_FLOAT32_C(  -444.38),
        SIMDE_FLOAT32_C(  -714.04), SIMDE_FLOAT32_C(   214.00), SIMDE_FLOAT32_C(     1.62), SIMDE_FLOAT32_C(  -295.76),
        SIMDE_FLOAT32_C(   354.35), SIMDE_FLOAT32_C(   104.17), SIMDE_FLOAT32_C(   163.92), SIMDE_FLOAT32_C(   484.34) },
      { -INT32_C(   217325096), -INT32_C(   140974171), -INT32_C(   163851099),  INT32_C(  2023880385), -INT32_C(   889149969),  INT32_C(  1487509960), -INT32_C(  1797901833), -INT32_C(  1673530172),
         INT32_C(  2072988373), -INT32_C(   697161935), -INT32_C(  1127436549), -INT32_C(  1825215068), -INT32_C(   614583021), -INT32_C(   986445874), -INT32_C(    61273544), -INT32_C(   728196866) },
       INT32_C(         226),
       INT32_C(           4),
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(-340282346638528859811704183484516925440.00), SIMDE_FLOAT32_C(    -0.00),
        SIMDE_FLOAT32_C(    90.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(     0.50), SIMDE_FLOAT32_C(     1.57), SIMDE_FLOAT32_C(     0.00),            SIMDE_MATH_NANF,
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(    90.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     1.57) } },
    { UINT16_C(59841),
      { SIMDE_FLOAT32_C(   101.38), SIMDE_FLOAT32_C(   193.86), SIMDE_FLOAT32_C(    97.50), SIMDE_FLOAT32_C(   474.39),
        SIMDE_FLOAT32_C(   920.60), SIMDE_FLOAT32_C(  -601.08), SIMDE_FLOAT32_C(   400.72), SIMDE_FLOAT32_C(   723.86),
        SIMDE_FLOAT32_C(   281.36), SIMDE_FLOAT32_C(  -921.53), SIMDE_FLOAT32_C(  -328.03), SIMDE_FLOAT32_C(   133.90),
        SIMDE_FLOAT32_C(  -482.43), SIMDE_FLOAT32_C(  -490.32), SIMDE_FLOAT32_C(   521.53), SIMDE_FLOAT32_C(    26.56) },
      { SIMDE_FLOAT32_C(  -233.61), SIMDE_FLOAT32_C(   -18.85), SIMDE_FLOAT32_C(  -967.12), SIMDE_FLOAT32_C(  -852.96),
        SIMDE_FLOAT32_C(  -927.36), SIMDE_FLOAT32_C(   469.42), SIMDE_FLOAT32_C(  -297.34), SIMDE_FLOAT32_C(  -641.41),
        SIMDE_FLOAT32_C(  -316.58), SIMDE_FLOAT32_C(   704.28), SIMDE_FLOAT32_C(    62.83), SIMDE_FLOAT32_C(  -962.23),
        SIMDE_FLOAT32_C(  -191.55), SIMDE_FLOAT32_C(  -773.25), SIMDE_FLOAT32_C(   522.11), SIMDE_FLOAT32_C(   909.83) },
      {  INT32_C(   112619337), -INT32_C(  1489296621),  INT32_C(   302346294),  INT32_C(    54922558),  INT32_C(  1113346117),  INT32_C(   601551951), -INT32_C(   378404138), -INT32_C(  1697500336),
        -INT32_C(  1230993245), -INT32_C(   497165396), -INT32_C(  1980472501), -INT32_C(  1249101200), -INT32_C(   621287285), -INT32_C(  1291988260),  INT32_C(   614166484),  INT32_C(  1170107810) },
       INT32_C(         246),
       INT32_C(           8),
      {     -SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(    -1.00), SIMDE_FLOAT32_C(     1.00),
            -SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),      SIMDE_MATH_INFINITYF,
        SIMDE_FLOAT32_C(     0.00),            SIMDE_MATH_NANF,            SIMDE_MATH_NANF,     -SIMDE_MATH_INFINITYF } },
    { UINT16_C(33881),
      { SIMDE_FLOAT32_C(   420.61), SIMDE_FLOAT32_C(  -380.39), SIMDE_FLOAT32_C(   384.22), SIMDE_FLOAT32_C(   341.22),
        SIMDE_FLOAT32_C(    18.53), SIMDE_FLOAT32_C(  -215.06), SIMDE_FLOAT32_C(    65.08), SIMDE_FLOAT32_C(  -700.11),
        SIMDE_FLOAT32_C(  -136.59), SIMDE_FLOAT32_C(   737.05), SIMDE_FLOAT32_C(   433.80), SIMDE_FLOAT32_C(   380.99),
        SIMDE_FLOAT32_C(  -753.27), SIMDE_FLOAT32_C(   -44.67), SIMDE_FLOAT32_C(  -592.45), SIMDE_FLOAT32_C(    13.12) },
      { SIMDE_FLOAT32_C(   936.48), SIMDE_FLOAT32_C(  -559.57), SIMDE_FLOAT32_C(   160.16), SIMDE_FLOAT32_C(  -990.88),
        SIMDE_FLOAT32_C(   909.85), SIMDE_FLOAT32_C(   862.82), SIMDE_FLOAT32_C(  -632.29), SIMDE_FLOAT32_C(  -406.74),
        SIMDE_FLOAT32_C(   567.10), SIMDE_FLOAT32_C(   430.54), SIMDE_FLOAT32_C(  -368.97), SIMDE_FLOAT32_C(  -624.45),
        SIMDE_FLOAT32_C(   657.29), SIMDE_FLOAT32_C(  -846.86), SIMDE_FLOAT32_C(  -714.62), SIMDE_FLOAT32_C(    77.91) },
      {  INT32_C(   226081924), -INT32_C(   493243604),  INT32_C(   416907582),  INT32_C(   253078365), -INT32_C(  1532328833),  INT32_C(  1818368039), -INT32_C(  1335312114),  INT32_C(  2134164218),
        -INT32_C(  1416843906), -INT32_C(  1618139551),  INT32_C(    95970983), -INT32_C(  1860907758),  INT32_C(  2033565522), -INT32_C(   437937961),  INT32_C(  1402293849), -INT32_C(  1898788592) },
       INT32_C(         119),
       INT32_C(           8),
      { SIMDE_FLOAT32_C(   420.61), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(-340282346638528859811704183484516925440.00),
        SIMDE_FLOAT32_C(     1.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(    65.08), SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00),      SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(     0.00),
        SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(     0.00) } },
  };

  simde__m512 a, b, r;
  simde__m512i c;

  a = simde_mm512_loadu_ps(test_vec[0].a);
  b = simde_mm512_loadu_ps(test_vec[0].b);
  c = simde_mm512_loadu_epi32(test_vec[0].c);
  r = simde_mm512_maskz_fixupimm_round_ps(test_vec[0].k, a, b, c, INT32_C(         183), INT32_C(           4));
  simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[0].r), 1);

  a = simde_mm512_loadu_ps(test_vec[1].a);
  b = simde_mm512_loadu_ps(test_vec[1].b);
  c = simde_mm512_loadu_epi32(test_vec[1].c);
  r = simde_mm512_maskz_fixupimm_round_ps(test_vec[1].k, a, b, c, INT32_C(         104), INT32_C(           4));
  simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[1].r), 1);

  #if !defined(SIMDE_FAST_MATH)
  a = simde_mm512_loadu_ps(test_vec[2].a);
  b = simde_mm512_loadu_ps(test_vec[2].b);
  c = simde_mm512_loadu_epi32(test_vec[2].c);
  r = simde_mm512_maskz_fixupimm_round_ps(test_vec[2].k, a, b, c, INT32_C(          85), INT32_C(           8));
  simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[2].r), 1);

  a = simde_mm512_loadu_ps(test_vec[3].a);
  b = simde_mm512_loadu_ps(test_vec[3].b);
  c = simde_mm512_loadu_epi32(test_vec[3].c);
  r = simde_mm512_maskz_fixupimm_round_ps(test_vec[3].k, a, b, c, INT32_C(          24), INT32_C(           8));
  simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[3].r), 1);

  a = simde_mm512_loadu_ps(test_vec[4].a);
  b = simde_mm512_loadu_ps(test_vec[4].b);
  c = simde_mm512_loadu_epi32(test_vec[4].c);
  r = simde_mm512_maskz_fixupimm_round_ps(test_vec[4].k, a, b, c, INT32_C(          94), INT32_C(           8));
  simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[4].r), 1);

  a = simde_mm512_loadu_ps(test_vec[5].a);
  b = simde_mm512_loadu_ps(test_vec[5].b);
  c = simde_mm512_loadu_epi32(test_vec[5].c);
  r = simde_mm512_maskz_fixupimm_round_ps(test_vec[5].k, a, b, c, INT32_C(         226), INT32_C(           4));
  simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[5].r), 1);

  a = simde_mm512_loadu_ps(test_vec[6].a);
  b = simde_mm512_loadu_ps(test_vec[6].b);
  c = simde_mm512_loadu_epi32(test_vec[6].c);
  r = simde_mm512_maskz_fixupimm_round_ps(test_vec[6].k, a, b, c, INT32_C(         246), INT32_C(           8));
  simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[6].r), 1);
  #endif

  a = simde_mm512_loadu_ps(test_vec[7].a);
  b = simde_mm512_loadu_ps(test_vec[7].b);
  c = simde_mm512_loadu_epi32(test_vec[7].c);
  r = simde_mm512_maskz_fixupimm_round_ps(test_vec[7].k, a, b, c, INT32_C(         119), INT32_C(           8));
  simde_test_x86_assert_equal_f32x16(r, simde_mm512_loadu_ps(test_vec[7].r), 1);

  return 0;
#else
  fputc('\n', stdout);
  simde_float32 values[8 * 2 * sizeof(simde__m512)];
  simde_test_x86_random_f32x16_full(8, 2, values, -1000.0f, 1000.0f, SIMDE_TEST_VEC_FLOAT_NAN);

  for (size_t i = 0 ; i < 8 ; i++) {
    simde__mmask16 k = simde_test_x86_random_mmask16();
    simde__m512 a = simde_test_x86_random_extract_f32x16(i, 2, 0, values);
    simde__m512 b = simde_test_x86_random_extract_f32x16(i, 2, 1, values);
    simde__m512i c = simde_test_x86_random_i32x16();
    int32_t imm8 = simde_test_codegen_random_i32() & 255;
    int32_t sae = simde_test_codegen_rand() & 1 ? SIMDE_MM_FROUND_NO_EXC : SIMDE_MM_FROUND_CUR_DIRECTION;
    simde__m512 r;
    SIMDE_CONSTIFY_256_NEW(simde_mm512_maskz_fixupimm_round_ps, r, simde_mm512_setzero_ps(), imm8, sae, k, a, b, c);

    simde_test_x86_write_mmask16(2, k, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_f32x16(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f32x16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x16(2, c, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, imm8, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, sae, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f32x16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  fprintf(stderr, "-------------------------\n------------------------\n----------------------\n");
  return 1;
#endif
}

static int
test_simde_mm512_fixupimm_round_pd (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde_float64 a[8];
    const simde_float64 b[8];
    const int64_t c[8];
    const int imm8;
    const int sae;
    const simde_float64 r[8];
  } test_vec[] = {
    { { SIMDE_FLOAT64_C(   396.57), SIMDE_FLOAT64_C(  -372.12), SIMDE_FLOAT64_C(   818.53), SIMDE_FLOAT64_C(  -141.92),
        SIMDE_FLOAT64_C(  -448.49), SIMDE_FLOAT64_C(  -343.61), SIMDE_FLOAT64_C(  -844.43), SIMDE_FLOAT64_C(   759.12) },
      { SIMDE_FLOAT64_C(   378.41), SIMDE_FLOAT64_C(   141.84), SIMDE_FLOAT64_C(   796.31), SIMDE_FLOAT64_C(   268.49),
        SIMDE_FLOAT64_C(   953.07), SIMDE_FLOAT64_C(  -566.68), SIMDE_FLOAT64_C(  -304.40), SIMDE_FLOAT64_C(   978.22) },
      { -INT64_C( 7968095395795426675), -INT64_C( 4010061006190228465), -INT64_C(  208651453885577713),  INT64_C( 7541819480488314648),
        -INT64_C( 8425353659227383538), -INT64_C( 1479507400353286675), -INT64_C( 8044917156261085247), -INT64_C(  828328191158977987) },
       INT32_C(           8),
       INT32_C(           4),
      {       -SIMDE_MATH_INFINITY, SIMDE_FLOAT64_C(     1.57), SIMDE_FLOAT64_C(     0.50), SIMDE_FLOAT64_C(-179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.00),
        SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(-179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.00), SIMDE_FLOAT64_C(     1.57), SIMDE_FLOAT64_C(   978.22) } },
    { { SIMDE_FLOAT64_C(  -600.14), SIMDE_FLOAT64_C(  -153.93), SIMDE_FLOAT64_C(  -818.29), SIMDE_FLOAT64_C(  -456.16),
        SIMDE_FLOAT64_C(  -588.07), SIMDE_FLOAT64_C(  -308.93), SIMDE_FLOAT64_C(  -116.14), SIMDE_FLOAT64_C(   572.90) },
      { SIMDE_FLOAT64_C(   416.75), SIMDE_FLOAT64_C(  -952.21), SIMDE_FLOAT64_C(  -852.48), SIMDE_FLOAT64_C(   216.83),
        SIMDE_FLOAT64_C(  -412.85), SIMDE_FLOAT64_C(  -207.84), SIMDE_FLOAT64_C(  -753.11), SIMDE_FLOAT64_C(  -738.96) },
      { -INT64_C( 1691261391516388442),  INT64_C( 8970737190664436719),  INT64_C( 2460468119575708550),  INT64_C(  402773509627777820),
         INT64_C( 5315422228964568099), -INT64_C( 5758154306311178840),  INT64_C(  327018846016278960), -INT64_C( 1493759357831882783) },
       INT32_C(           5),
       INT32_C(           8),
      { SIMDE_FLOAT64_C(     1.00),       -SIMDE_MATH_INFINITY, SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(    -0.00),
        SIMDE_FLOAT64_C(    90.00), SIMDE_FLOAT64_C(     1.00), SIMDE_FLOAT64_C(    -0.00), SIMDE_FLOAT64_C(   572.90) } },
    { { SIMDE_FLOAT64_C(   550.22), SIMDE_FLOAT64_C(  -934.99), SIMDE_FLOAT64_C(   328.61), SIMDE_FLOAT64_C(   252.74),
        SIMDE_FLOAT64_C(   537.53), SIMDE_FLOAT64_C(   935.83), SIMDE_FLOAT64_C(  -404.91), SIMDE_FLOAT64_C(   355.80) },
      { SIMDE_FLOAT64_C(   642.03), SIMDE_FLOAT64_C(  -576.67), SIMDE_FLOAT64_C(   701.53), SIMDE_FLOAT64_C(    -8.93),
        SIMDE_FLOAT64_C(   149.39), SIMDE_FLOAT64_C(   265.79), SIMDE_FLOAT64_C(  -133.20), SIMDE_FLOAT64_C(  -653.83) },
      { -INT64_C( 8555797571368129115), -INT64_C( 9008906835447566600), -INT64_C( 9172937362542184297),  INT64_C( 2927737244389304138),
        -INT64_C( 4660970769111313322),  INT64_C( 7245900155468242710), -INT64_C( 3826434057922457261),  INT64_C( 2799122205149586989) },
       INT32_C(         142),
       INT32_C(           4),
      { SIMDE_FLOAT64_C(    -0.00),             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(     1.00), SIMDE_FLOAT64_C(-179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.00),
        SIMDE_FLOAT64_C(    90.00), SIMDE_FLOAT64_C(   935.83),        SIMDE_MATH_INFINITY, SIMDE_FLOAT64_C(   355.80) } },
    { { SIMDE_FLOAT64_C(   566.18), SIMDE_FLOAT64_C(   725.12), SIMDE_FLOAT64_C(   650.97), SIMDE_FLOAT64_C(   665.97),
        SIMDE_FLOAT64_C(  -495.48), SIMDE_FLOAT64_C(  -887.62), SIMDE_FLOAT64_C(   498.15), SIMDE_FLOAT64_C(   123.96) },
      { SIMDE_FLOAT64_C(  -288.41), SIMDE_FLOAT64_C(   127.73), SIMDE_FLOAT64_C(   -87.94), SIMDE_FLOAT64_C(  -298.66),
        SIMDE_FLOAT64_C(  -907.76), SIMDE_FLOAT64_C(   804.63), SIMDE_FLOAT64_C(  -323.27), SIMDE_FLOAT64_C(   747.49) },
      {  INT64_C(   82478246986559214),  INT64_C( 8484469678701235165), -INT64_C( 3243018622757422856), -INT64_C( 7327044696793439543),
        -INT64_C( 8623526139732711990), -INT64_C( 4679907658644135329), -INT64_C( 2060277968073285672), -INT64_C( 8911393606580986098) },
       INT32_C(           3),
       INT32_C(           8),
      {        SIMDE_MATH_INFINITY,        SIMDE_MATH_INFINITY, SIMDE_FLOAT64_C(179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.00), SIMDE_FLOAT64_C(     1.00),
        SIMDE_FLOAT64_C(  -907.76), SIMDE_FLOAT64_C(    -1.00),       -SIMDE_MATH_INFINITY, SIMDE_FLOAT64_C(     0.50) } },
    { { SIMDE_FLOAT64_C(   280.76), SIMDE_FLOAT64_C(   378.34), SIMDE_FLOAT64_C(  -130.75), SIMDE_FLOAT64_C(  -610.40),
        SIMDE_FLOAT64_C(   956.51), SIMDE_FLOAT64_C(  -705.21), SIMDE_FLOAT64_C(   627.65), SIMDE_FLOAT64_C(  -889.42) },
      { SIMDE_FLOAT64_C(  -256.92), SIMDE_FLOAT64_C(  -279.98), SIMDE_FLOAT64_C(   491.50), SIMDE_FLOAT64_C(   880.08),
        SIMDE_FLOAT64_C(  -828.76), SIMDE_FLOAT64_C(  -788.33), SIMDE_FLOAT64_C(   203.96), SIMDE_FLOAT64_C(   105.27) },
      {  INT64_C( 7198779726217541774),  INT64_C( 7719754988379335816), -INT64_C( 8999800471842006966),  INT64_C( 6793279613163186907),
         INT64_C( 9003667574278045835), -INT64_C( 5148624352265676321),  INT64_C( 2804393790953685569), -INT64_C( 8714667603328407072) },
       INT32_C(           7),
       INT32_C(           8),
      { SIMDE_FLOAT64_C(     1.57), SIMDE_FLOAT64_C(     0.50),        SIMDE_MATH_INFINITY, SIMDE_FLOAT64_C(     1.57),
        SIMDE_FLOAT64_C(   956.51), SIMDE_FLOAT64_C(  -788.33),        SIMDE_MATH_INFINITY, SIMDE_FLOAT64_C(     0.50) } },
    { { SIMDE_FLOAT64_C(  -460.14), SIMDE_FLOAT64_C(   186.05), SIMDE_FLOAT64_C(   171.62), SIMDE_FLOAT64_C(   254.80),
        SIMDE_FLOAT64_C(  -383.32), SIMDE_FLOAT64_C(   838.05), SIMDE_FLOAT64_C(   805.13), SIMDE_FLOAT64_C(   716.93) },
      { SIMDE_FLOAT64_C(   621.16), SIMDE_FLOAT64_C(   569.20), SIMDE_FLOAT64_C(   356.05), SIMDE_FLOAT64_C(   -89.44),
        SIMDE_FLOAT64_C(  -496.48), SIMDE_FLOAT64_C(   828.84), SIMDE_FLOAT64_C(   333.90), SIMDE_FLOAT64_C(  -281.32) },
      {  INT64_C( 6206640949288439484), -INT64_C( 3737327154453697926), -INT64_C( 5281594141347672113), -INT64_C( 6193230221650289524),
        -INT64_C( 5860042712802080697),  INT64_C( 3470838669206817180), -INT64_C( 1673244096296297740), -INT64_C( 7339416782524245618) },
       INT32_C(         239),
       INT32_C(           4),
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   569.20), SIMDE_FLOAT64_C(     0.00),             SIMDE_MATH_NAN,
              -SIMDE_MATH_INFINITY,        SIMDE_MATH_INFINITY, SIMDE_FLOAT64_C(   333.90), SIMDE_FLOAT64_C(     0.50) } },
    { { SIMDE_FLOAT64_C(   872.13), SIMDE_FLOAT64_C(   877.47), SIMDE_FLOAT64_C(    49.75), SIMDE_FLOAT64_C(  -669.06),
        SIMDE_FLOAT64_C(  -421.54), SIMDE_FLOAT64_C(   -55.79), SIMDE_FLOAT64_C(   658.78), SIMDE_FLOAT64_C(   647.08) },
      { SIMDE_FLOAT64_C(  -337.83), SIMDE_FLOAT64_C(    41.72), SIMDE_FLOAT64_C(  -745.03), SIMDE_FLOAT64_C(   458.45),
        SIMDE_FLOAT64_C(    96.43), SIMDE_FLOAT64_C(  -759.84), SIMDE_FLOAT64_C(   138.15), SIMDE_FLOAT64_C(   539.84) },
      { -INT64_C( 1319148123310412986), -INT64_C( 2777314434654385258), -INT64_C( 1738803029764736816),  INT64_C( 1233160340092374208),
         INT64_C( 1904496545415304123),  INT64_C( 1910118099934661229),  INT64_C( 5320261381801312531), -INT64_C( 1187511915115502679) },
       INT32_C(          47),
       INT32_C(           4),
      { SIMDE_FLOAT64_C(-179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.00), SIMDE_FLOAT64_C(     0.00),       -SIMDE_MATH_INFINITY, SIMDE_FLOAT64_C(     0.50),
        SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(    -1.00), SIMDE_FLOAT64_C(179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.00), SIMDE_FLOAT64_C(    -0.00) } },
    { { SIMDE_FLOAT64_C(  -573.47), SIMDE_FLOAT64_C(   763.99), SIMDE_FLOAT64_C(   935.88), SIMDE_FLOAT64_C(  -109.60),
        SIMDE_FLOAT64_C(   -21.59), SIMDE_FLOAT64_C(  -162.53), SIMDE_FLOAT64_C(   823.86), SIMDE_FLOAT64_C(   385.61) },
      { SIMDE_FLOAT64_C(  -389.31), SIMDE_FLOAT64_C(   104.39), SIMDE_FLOAT64_C(  -964.64), SIMDE_FLOAT64_C(   586.47),
        SIMDE_FLOAT64_C(   310.45), SIMDE_FLOAT64_C(   871.87), SIMDE_FLOAT64_C(   423.59), SIMDE_FLOAT64_C(  -910.88) },
      { -INT64_C( 7080355148247956891), -INT64_C(  353673183669408757),  INT64_C( 8453986334756084302), -INT64_C( 1613592119628925915),
         INT64_C( 4611456445470387680), -INT64_C( 7209041115402416932), -INT64_C( 3085334421648303631), -INT64_C( 7921371383508544604) },
       INT32_C(          79),
       INT32_C(           8),
      { SIMDE_FLOAT64_C(    -1.00), SIMDE_FLOAT64_C(   763.99),             SIMDE_MATH_NAN,             SIMDE_MATH_NAN,
               SIMDE_MATH_INFINITY, SIMDE_FLOAT64_C(-179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.00), SIMDE_FLOAT64_C(     0.50), SIMDE_FLOAT64_C(     0.00) } },
  };

  simde__m512d a, b, r;
  simde__m512i c;

  a = simde_mm512_loadu_pd(test_vec[0].a);
  b = simde_mm512_loadu_pd(test_vec[0].b);
  c = simde_mm512_loadu_epi64(test_vec[0].c);
  r = simde_mm512_fixupimm_round_pd(a, b, c, INT32_C(           8), INT32_C(           4));
  simde_test_x86_assert_equal_f64x8(r, simde_mm512_loadu_pd(test_vec[0].r), 1);

  #if !defined(SIMDE_FAST_MATH)
  a = simde_mm512_loadu_pd(test_vec[1].a);
  b = simde_mm512_loadu_pd(test_vec[1].b);
  c = simde_mm512_loadu_epi64(test_vec[1].c);
  r = simde_mm512_fixupimm_round_pd(a, b, c, INT32_C(           5), INT32_C(           8));
  simde_test_x86_assert_equal_f64x8(r, simde_mm512_loadu_pd(test_vec[1].r), 1);

  a = simde_mm512_loadu_pd(test_vec[2].a);
  b = simde_mm512_loadu_pd(test_vec[2].b);
  c = simde_mm512_loadu_epi64(test_vec[2].c);
  r = simde_mm512_fixupimm_round_pd(a, b, c, INT32_C(         142), INT32_C(           4));
  simde_test_x86_assert_equal_f64x8(r, simde_mm512_loadu_pd(test_vec[2].r), 1);
  #endif

  a = simde_mm512_loadu_pd(test_vec[3].a);
  b = simde_mm512_loadu_pd(test_vec[3].b);
  c = simde_mm512_loadu_epi64(test_vec[3].c);
  r = simde_mm512_fixupimm_round_pd(a, b, c, INT32_C(           3), INT32_C(           8));
  simde_test_x86_assert_equal_f64x8(r, simde_mm512_loadu_pd(test_vec[3].r), 1);

  a = simde_mm512_loadu_pd(test_vec[4].a);
  b = simde_mm512_loadu_pd(test_vec[4].b);
  c = simde_mm512_loadu_epi64(test_vec[4].c);
  r = simde_mm512_fixupimm_round_pd(a, b, c, INT32_C(           7), INT32_C(           8));
  simde_test_x86_assert_equal_f64x8(r, simde_mm512_loadu_pd(test_vec[4].r), 1);

  #if !defined(SIMDE_FAST_MATH)
  a = simde_mm512_loadu_pd(test_vec[5].a);
  b = simde_mm512_loadu_pd(test_vec[5].b);
  c = simde_mm512_loadu_epi64(test_vec[5].c);
  r = simde_mm512_fixupimm_round_pd(a, b, c, INT32_C(         239), INT32_C(           4));
  simde_test_x86_assert_equal_f64x8(r, simde_mm512_loadu_pd(test_vec[5].r), 1);
  #endif

  a = simde_mm512_loadu_pd(test_vec[6].a);
  b = simde_mm512_loadu_pd(test_vec[6].b);
  c = simde_mm512_loadu_epi64(test_vec[6].c);
  r = simde_mm512_fixupimm_round_pd(a, b, c, INT32_C(          47), INT32_C(           4));
  simde_test_x86_assert_equal_f64x8(r, simde_mm512_loadu_pd(test_vec[6].r), 1);

  #if !defined(SIMDE_FAST_MATH)
  a = simde_mm512_loadu_pd(test_vec[7].a);
  b = simde_mm512_loadu_pd(test_vec[7].b);
  c = simde_mm512_loadu_epi64(test_vec[7].c);
  r = simde_mm512_fixupimm_round_pd(a, b, c, INT32_C(          79), INT32_C(           8));
  simde_test_x86_assert_equal_f64x8(r, simde_mm512_loadu_pd(test_vec[7].r), 1);
  #endif

  return 0;
#else
  fputc('\n', stdout);
  simde_float64 values[8 * 2 * sizeof(simde__m512d)];
  simde_test_x86_random_f64x8_full(8, 2, values, -1000.0, 1000.0, SIMDE_TEST_VEC_FLOAT_NAN);

  for (size_t i = 0 ; i < 8 ; i++) {
    simde__m512d a = simde_test_x86_random_f64x8(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
    simde__m512d b = simde_test_x86_random_f64x8(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
    simde__m512i c = simde_test_x86_random_i64x8();
    int32_t imm8 = simde_test_codegen_random_i32() & 255;
    int32_t sae = simde_test_codegen_rand() & 1 ? SIMDE_MM_FROUND_NO_EXC : SIMDE_MM_FROUND_CUR_DIRECTION;
    simde__m512d r;
    SIMDE_CONSTIFY_256_NEW(simde_mm512_fixupimm_round_pd, r, simde_mm512_setzero_pd(), imm8, sae, a, b, c);

    simde_test_x86_write_f64x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_f64x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i64x8(2, c, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, imm8, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, sae, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f64x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm512_mask_fixupimm_round_pd (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde_float64 a[8];
    const simde__mmask8 k;
    const simde_float64 b[8];
    const int64_t c[8];
    const int imm8;
    const int sae;
    const simde_float64 r[8];
  } test_vec[] = {
    { {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   449.69),             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(  -958.94),
        SIMDE_FLOAT64_C(   574.51), SIMDE_FLOAT64_C(  -911.71), SIMDE_FLOAT64_C(  -811.80), SIMDE_FLOAT64_C(  -558.40) },
      UINT8_C(103),
      { SIMDE_FLOAT64_C(  -435.21),             SIMDE_MATH_NAN,             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(  -269.79),
        SIMDE_FLOAT64_C(  -150.39), SIMDE_FLOAT64_C(    47.71), SIMDE_FLOAT64_C(  -591.58), SIMDE_FLOAT64_C(   727.90) },
      { -INT64_C( 3091491664709224112), -INT64_C( 2065458207807749348),  INT64_C(  326670077314333435),  INT64_C( 8427241112902148172),
        -INT64_C( 3740408062606909556),  INT64_C( 5350606551697935274),  INT64_C( 3377471996440367654),  INT64_C( 1686788877068204240) },
       INT32_C(         140),
       INT32_C(           8),
      { SIMDE_FLOAT64_C(     1.00), SIMDE_FLOAT64_C(    90.00), SIMDE_FLOAT64_C(     0.50), SIMDE_FLOAT64_C(  -958.94),
        SIMDE_FLOAT64_C(   574.51),        SIMDE_MATH_INFINITY, SIMDE_FLOAT64_C(     1.00), SIMDE_FLOAT64_C(  -558.40) } },
    { { SIMDE_FLOAT64_C(  -765.11), SIMDE_FLOAT64_C(  -296.20), SIMDE_FLOAT64_C(  -198.19), SIMDE_FLOAT64_C(   134.85),
        SIMDE_FLOAT64_C(   -73.18), SIMDE_FLOAT64_C(   943.22), SIMDE_FLOAT64_C(   171.18), SIMDE_FLOAT64_C(   166.58) },
      UINT8_C(112),
      { SIMDE_FLOAT64_C(  -290.59), SIMDE_FLOAT64_C(   507.66), SIMDE_FLOAT64_C(   118.45), SIMDE_FLOAT64_C(   650.48),
        SIMDE_FLOAT64_C(  -952.25), SIMDE_FLOAT64_C(   151.79), SIMDE_FLOAT64_C(  -245.18), SIMDE_FLOAT64_C(   973.91) },
      {  INT64_C( 7352419024409184007), -INT64_C( 1716545415744508075),  INT64_C( 6427037927806729674),  INT64_C(   21723020579028356),
         INT64_C( 7457932473349769459), -INT64_C( 7131571148983879659), -INT64_C( 2821414643683956594),  INT64_C(  578714837185849359) },
       INT32_C(          10),
       INT32_C(           8),
      { SIMDE_FLOAT64_C(  -765.11), SIMDE_FLOAT64_C(  -296.20), SIMDE_FLOAT64_C(  -198.19), SIMDE_FLOAT64_C(   134.85),
        SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(   151.79), SIMDE_FLOAT64_C(-179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.00), SIMDE_FLOAT64_C(   166.58) } },
    { { SIMDE_FLOAT64_C(  -398.52), SIMDE_FLOAT64_C(   165.13), SIMDE_FLOAT64_C(  -985.03), SIMDE_FLOAT64_C(  -824.01),
        SIMDE_FLOAT64_C(   253.42), SIMDE_FLOAT64_C(  -796.83), SIMDE_FLOAT64_C(  -382.41), SIMDE_FLOAT64_C(   818.21) },
      UINT8_C(159),
      { SIMDE_FLOAT64_C(  -665.26), SIMDE_FLOAT64_C(  -395.57), SIMDE_FLOAT64_C(  -451.58), SIMDE_FLOAT64_C(   184.35),
        SIMDE_FLOAT64_C(   652.15), SIMDE_FLOAT64_C(   -43.16), SIMDE_FLOAT64_C(   -87.75), SIMDE_FLOAT64_C(   887.04) },
      {  INT64_C(  394817028681621636),  INT64_C( 7042577070977517896), -INT64_C( 2534860471647220710),  INT64_C( 9089826430547778917),
        -INT64_C( 1121147094247670420), -INT64_C( 4984332913989755413), -INT64_C( 2264364501207212573),  INT64_C( 5526634587299927097) },
       INT32_C(         137),
       INT32_C(           8),
      { SIMDE_FLOAT64_C(    -1.00), SIMDE_FLOAT64_C(     1.00), SIMDE_FLOAT64_C(  -985.03), SIMDE_FLOAT64_C(     0.00),
               SIMDE_MATH_INFINITY, SIMDE_FLOAT64_C(  -796.83), SIMDE_FLOAT64_C(  -382.41),             SIMDE_MATH_NAN } },
    { { SIMDE_FLOAT64_C(   660.64), SIMDE_FLOAT64_C(   714.07), SIMDE_FLOAT64_C(    21.89), SIMDE_FLOAT64_C(  -412.54),
        SIMDE_FLOAT64_C(   657.29), SIMDE_FLOAT64_C(  -806.94), SIMDE_FLOAT64_C(   754.03), SIMDE_FLOAT64_C(  -633.30) },
      UINT8_C( 38),
      { SIMDE_FLOAT64_C(   700.72), SIMDE_FLOAT64_C(  -127.51), SIMDE_FLOAT64_C(  -982.82), SIMDE_FLOAT64_C(   748.46),
        SIMDE_FLOAT64_C(  -975.72), SIMDE_FLOAT64_C(  -228.00), SIMDE_FLOAT64_C(   722.38), SIMDE_FLOAT64_C(  -374.24) },
      {  INT64_C( 3356065018864264737), -INT64_C( 4556297925171579171), -INT64_C( 2046054589159637593),  INT64_C( 8439174320566838080),
        -INT64_C( 6744275938660212258),  INT64_C( 2443147247396434938),  INT64_C( 3449697872154459083), -INT64_C( 5569189314603590676) },
       INT32_C(         228),
       INT32_C(           4),
      { SIMDE_FLOAT64_C(   660.64), SIMDE_FLOAT64_C(    -0.00), SIMDE_FLOAT64_C(179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.00), SIMDE_FLOAT64_C(  -412.54),
        SIMDE_FLOAT64_C(   657.29), SIMDE_FLOAT64_C(    -0.00), SIMDE_FLOAT64_C(   754.03), SIMDE_FLOAT64_C(  -633.30) } },
    { { SIMDE_FLOAT64_C(   937.13), SIMDE_FLOAT64_C(   737.34), SIMDE_FLOAT64_C(  -198.25), SIMDE_FLOAT64_C(   190.56),
        SIMDE_FLOAT64_C(   940.51), SIMDE_FLOAT64_C(   419.34), SIMDE_FLOAT64_C(     8.77), SIMDE_FLOAT64_C(  -724.74) },
      UINT8_C( 81),
      { SIMDE_FLOAT64_C(  -976.23), SIMDE_FLOAT64_C(   557.19), SIMDE_FLOAT64_C(   459.61), SIMDE_FLOAT64_C(   675.92),
        SIMDE_FLOAT64_C(  -485.97), SIMDE_FLOAT64_C(  -628.14), SIMDE_FLOAT64_C(   562.95), SIMDE_FLOAT64_C(  -825.33) },
      {  INT64_C( 3828480033123739210), -INT64_C( 4064181004444504928),  INT64_C( 8987345126160565584), -INT64_C( 8042215876484424408),
        -INT64_C( 8648875116389439114), -INT64_C( 7231953843027236110), -INT64_C( 1965879806825249419), -INT64_C( 6900540290189763737) },
       INT32_C(         196),
       INT32_C(           4),
      {       -SIMDE_MATH_INFINITY, SIMDE_FLOAT64_C(   737.34), SIMDE_FLOAT64_C(  -198.25), SIMDE_FLOAT64_C(   190.56),
              -SIMDE_MATH_INFINITY, SIMDE_FLOAT64_C(   419.34),             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(  -724.74) } },
    { { SIMDE_FLOAT64_C(  -914.07), SIMDE_FLOAT64_C(  -415.16), SIMDE_FLOAT64_C(  -237.87), SIMDE_FLOAT64_C(   743.21),
        SIMDE_FLOAT64_C(  -222.10), SIMDE_FLOAT64_C(  -483.84), SIMDE_FLOAT64_C(  -890.09), SIMDE_FLOAT64_C(  -521.38) },
      UINT8_C( 94),
      { SIMDE_FLOAT64_C(   388.65), SIMDE_FLOAT64_C(  -872.90), SIMDE_FLOAT64_C(  -772.92), SIMDE_FLOAT64_C(   412.93),
        SIMDE_FLOAT64_C(  -100.91), SIMDE_FLOAT64_C(   949.46), SIMDE_FLOAT64_C(  -961.31), SIMDE_FLOAT64_C(  -163.77) },
      { -INT64_C( 7747647170277795789), -INT64_C( 2068958539738910610), -INT64_C( 7364537277613166471),  INT64_C( 8019750113754386569),
         INT64_C( 1621142655427335416),  INT64_C( 7382490425616324708), -INT64_C( 6735517960454655601),  INT64_C( 1791829159103709234) },
       INT32_C(         175),
       INT32_C(           4),
      { SIMDE_FLOAT64_C(  -914.07), SIMDE_FLOAT64_C(-179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.00), SIMDE_FLOAT64_C(  -237.87), SIMDE_FLOAT64_C(179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.00),
        SIMDE_FLOAT64_C(     1.00), SIMDE_FLOAT64_C(  -483.84), SIMDE_FLOAT64_C(    90.00), SIMDE_FLOAT64_C(  -521.38) } },
    { { SIMDE_FLOAT64_C(   686.80), SIMDE_FLOAT64_C(  -159.56), SIMDE_FLOAT64_C(  -973.22), SIMDE_FLOAT64_C(   627.31),
        SIMDE_FLOAT64_C(  -740.23), SIMDE_FLOAT64_C(    35.55), SIMDE_FLOAT64_C(   902.57), SIMDE_FLOAT64_C(  -716.46) },
      UINT8_C(129),
      { SIMDE_FLOAT64_C(  -407.25), SIMDE_FLOAT64_C(   362.18), SIMDE_FLOAT64_C(   959.46), SIMDE_FLOAT64_C(   106.78),
        SIMDE_FLOAT64_C(   734.04), SIMDE_FLOAT64_C(   522.41), SIMDE_FLOAT64_C(   281.45), SIMDE_FLOAT64_C(   819.96) },
      { -INT64_C( 5484883793420832659), -INT64_C( 2042665705498447570),  INT64_C( 2597525053820360864),  INT64_C( 9214161506851863387),
        -INT64_C( 5770127615918425608),  INT64_C( 8004403754381332692), -INT64_C( 2837923639068772046), -INT64_C( 2812192438465685401) },
       INT32_C(         207),
       INT32_C(           4),
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(  -159.56), SIMDE_FLOAT64_C(  -973.22), SIMDE_FLOAT64_C(   627.31),
        SIMDE_FLOAT64_C(  -740.23), SIMDE_FLOAT64_C(    35.55), SIMDE_FLOAT64_C(   902.57), SIMDE_FLOAT64_C(    -0.00) } },
    { { SIMDE_FLOAT64_C(  -892.75), SIMDE_FLOAT64_C(  -956.42), SIMDE_FLOAT64_C(   563.18), SIMDE_FLOAT64_C(  -114.85),
        SIMDE_FLOAT64_C(  -440.26), SIMDE_FLOAT64_C(   673.09), SIMDE_FLOAT64_C(   363.77), SIMDE_FLOAT64_C(   948.39) },
      UINT8_C(252),
      { SIMDE_FLOAT64_C(   800.19), SIMDE_FLOAT64_C(   590.85), SIMDE_FLOAT64_C(   361.32), SIMDE_FLOAT64_C(  -300.72),
        SIMDE_FLOAT64_C(   540.31), SIMDE_FLOAT64_C(   400.01), SIMDE_FLOAT64_C(   535.51), SIMDE_FLOAT64_C(   227.12) },
      { -INT64_C(  428796453657398273),  INT64_C( 6149015173420236554),  INT64_C( 3446323774883740808), -INT64_C( 1030610788686323035),
         INT64_C( 2673924434332778299), -INT64_C( 8720053002828820753),  INT64_C( 6721086668545518305), -INT64_C( 5431686974176759622) },
       INT32_C(          69),
       INT32_C(           8),
      { SIMDE_FLOAT64_C(  -892.75), SIMDE_FLOAT64_C(  -956.42), SIMDE_FLOAT64_C(     0.50),       -SIMDE_MATH_INFINITY,
                    SIMDE_MATH_NAN, SIMDE_FLOAT64_C(     1.00), SIMDE_FLOAT64_C(   535.51), SIMDE_FLOAT64_C(     1.00) } },
  };

  simde__m512d a, b, r;
  simde__m512i c;

  #if !defined(SIMDE_FAST_MATH)
  a = simde_mm512_loadu_pd(test_vec[0].a);
  b = simde_mm512_loadu_pd(test_vec[0].b);
  c = simde_mm512_loadu_epi64(test_vec[0].c);
  r = simde_mm512_mask_fixupimm_round_pd(a, test_vec[0].k, b, c, INT32_C(         140), INT32_C(           8));
  simde_test_x86_assert_equal_f64x8(r, simde_mm512_loadu_pd(test_vec[0].r), 1);
  #endif

  a = simde_mm512_loadu_pd(test_vec[1].a);
  b = simde_mm512_loadu_pd(test_vec[1].b);
  c = simde_mm512_loadu_epi64(test_vec[1].c);
  r = simde_mm512_mask_fixupimm_round_pd(a, test_vec[1].k, b, c, INT32_C(          10), INT32_C(           8));
  simde_test_x86_assert_equal_f64x8(r, simde_mm512_loadu_pd(test_vec[1].r), 1);

  #if !defined(SIMDE_FAST_MATH)
  a = simde_mm512_loadu_pd(test_vec[2].a);
  b = simde_mm512_loadu_pd(test_vec[2].b);
  c = simde_mm512_loadu_epi64(test_vec[2].c);
  r = simde_mm512_mask_fixupimm_round_pd(a, test_vec[2].k, b, c, INT32_C(         137), INT32_C(           8));
  simde_test_x86_assert_equal_f64x8(r, simde_mm512_loadu_pd(test_vec[2].r), 1);
  #endif

  a = simde_mm512_loadu_pd(test_vec[3].a);
  b = simde_mm512_loadu_pd(test_vec[3].b);
  c = simde_mm512_loadu_epi64(test_vec[3].c);
  r = simde_mm512_mask_fixupimm_round_pd(a, test_vec[3].k, b, c, INT32_C(         228), INT32_C(           4));
  simde_test_x86_assert_equal_f64x8(r, simde_mm512_loadu_pd(test_vec[3].r), 1);

  #if !defined(SIMDE_FAST_MATH)
  a = simde_mm512_loadu_pd(test_vec[4].a);
  b = simde_mm512_loadu_pd(test_vec[4].b);
  c = simde_mm512_loadu_epi64(test_vec[4].c);
  r = simde_mm512_mask_fixupimm_round_pd(a, test_vec[4].k, b, c, INT32_C(         196), INT32_C(           4));
  simde_test_x86_assert_equal_f64x8(r, simde_mm512_loadu_pd(test_vec[4].r), 1);
  #endif

  a = simde_mm512_loadu_pd(test_vec[5].a);
  b = simde_mm512_loadu_pd(test_vec[5].b);
  c = simde_mm512_loadu_epi64(test_vec[5].c);
  r = simde_mm512_mask_fixupimm_round_pd(a, test_vec[5].k, b, c, INT32_C(         175), INT32_C(           4));
  simde_test_x86_assert_equal_f64x8(r, simde_mm512_loadu_pd(test_vec[5].r), 1);

  #if !defined(SIMDE_FAST_MATH)
  a = simde_mm512_loadu_pd(test_vec[6].a);
  b = simde_mm512_loadu_pd(test_vec[6].b);
  c = simde_mm512_loadu_epi64(test_vec[6].c);
  r = simde_mm512_mask_fixupimm_round_pd(a, test_vec[6].k, b, c, INT32_C(         207), INT32_C(           4));
  simde_test_x86_assert_equal_f64x8(r, simde_mm512_loadu_pd(test_vec[6].r), 1);

  a = simde_mm512_loadu_pd(test_vec[7].a);
  b = simde_mm512_loadu_pd(test_vec[7].b);
  c = simde_mm512_loadu_epi64(test_vec[7].c);
  r = simde_mm512_mask_fixupimm_round_pd(a, test_vec[7].k, b, c, INT32_C(          69), INT32_C(           8));
  simde_test_x86_assert_equal_f64x8(r, simde_mm512_loadu_pd(test_vec[7].r), 1);
  #endif

  return 0;
#else
  fputc('\n', stdout);
  simde_float64 values[8 * 2 * sizeof(simde__m512d)];
  simde_test_x86_random_f64x8_full(8, 2, values, -1000.0, 1000.0, SIMDE_TEST_VEC_FLOAT_NAN);

  for (size_t i = 0 ; i < 8 ; i++) {
    simde__m512d a = simde_test_x86_random_extract_f64x8(i, 2, 0, values);
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m512d b = simde_test_x86_random_extract_f64x8(i, 2, 1, values);
    simde__m512i c = simde_test_x86_random_i64x8();
    int32_t imm8 = simde_test_codegen_random_i32() & 255;
    int32_t sae = simde_test_codegen_rand() & 1 ? SIMDE_MM_FROUND_NO_EXC : SIMDE_MM_FROUND_CUR_DIRECTION;
    simde__m512d r;
    SIMDE_CONSTIFY_256_NEW(simde_mm512_mask_fixupimm_round_pd, r, simde_mm512_setzero_pd(), imm8, sae, a, k, b, c);

    simde_test_x86_write_f64x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f64x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i64x8(2, c, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, imm8, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, sae, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f64x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm512_maskz_fixupimm_round_pd (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask8 k;
    const simde_float64 a[8];
    const simde_float64 b[8];
    const int64_t c[8];
    const int imm8;
    const int sae;
    const simde_float64 r[8];
  } test_vec[] = {
    { UINT8_C(110),
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(  -413.76),             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   584.12),
        SIMDE_FLOAT64_C(  -725.33), SIMDE_FLOAT64_C(  -298.11), SIMDE_FLOAT64_C(  -907.92), SIMDE_FLOAT64_C(   785.36) },
      { SIMDE_FLOAT64_C(  -183.16),             SIMDE_MATH_NAN,             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   -97.02),
        SIMDE_FLOAT64_C(  -849.62), SIMDE_FLOAT64_C(   487.32), SIMDE_FLOAT64_C(   947.20), SIMDE_FLOAT64_C(    17.87) },
      {  INT64_C( 3077269692546566682),  INT64_C( 3779625075164806554), -INT64_C( 8081995546433646526),  INT64_C( 1536048508374505365),
        -INT64_C( 2084322984624152211), -INT64_C( 7157244168448152196), -INT64_C( 4298021534023928596),  INT64_C( 6396229586927470772) },
       INT32_C(         154),
       INT32_C(           4),
      { SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     1.00),             SIMDE_MATH_NAN,             SIMDE_MATH_NAN,
        SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(    -0.00), SIMDE_FLOAT64_C(    90.00), SIMDE_FLOAT64_C(     0.00) } },
    { UINT8_C( 83),
      { SIMDE_FLOAT64_C(  -890.57), SIMDE_FLOAT64_C(  -218.08), SIMDE_FLOAT64_C(   383.97), SIMDE_FLOAT64_C(   343.07),
        SIMDE_FLOAT64_C(  -339.77), SIMDE_FLOAT64_C(   496.28), SIMDE_FLOAT64_C(    -3.73), SIMDE_FLOAT64_C(  -614.47) },
      { SIMDE_FLOAT64_C(    51.45), SIMDE_FLOAT64_C(   631.11), SIMDE_FLOAT64_C(  -579.19), SIMDE_FLOAT64_C(  -448.65),
        SIMDE_FLOAT64_C(   196.16), SIMDE_FLOAT64_C(   875.22), SIMDE_FLOAT64_C(  -444.72), SIMDE_FLOAT64_C(  -753.93) },
      { -INT64_C( 5905316412531832121),  INT64_C( 2204814126618966454), -INT64_C( 4650298687117439530), -INT64_C( 4918251900231675863),
         INT64_C( 5771212948264157030), -INT64_C( 2138606142991042192),  INT64_C( 3687839005881153650),  INT64_C( 4365777867147967207) },
       INT32_C(         218),
       INT32_C(           4),
      { SIMDE_FLOAT64_C(     0.50),             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00),
               SIMDE_MATH_INFINITY, SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.00), SIMDE_FLOAT64_C(     0.00) } },
    { UINT8_C(187),
      { SIMDE_FLOAT64_C(  -538.54), SIMDE_FLOAT64_C(   258.01), SIMDE_FLOAT64_C(   830.19), SIMDE_FLOAT64_C(  -263.88),
        SIMDE_FLOAT64_C(   959.91), SIMDE_FLOAT64_C(   922.26), SIMDE_FLOAT64_C(  -478.52), SIMDE_FLOAT64_C(  -223.26) },
      { SIMDE_FLOAT64_C(   984.23), SIMDE_FLOAT64_C(  -425.15), SIMDE_FLOAT64_C(   679.72), SIMDE_FLOAT64_C(  -865.39),
        SIMDE_FLOAT64_C(  -937.83), SIMDE_FLOAT64_C(   626.92), SIMDE_FLOAT64_C(   152.48), SIMDE_FLOAT64_C(  -828.40) },
      {  INT64_C( 8103875811640469956), -INT64_C( 8945923102313224030),  INT64_C( 3593402579574243557), -INT64_C( 1085180403365267312),
         INT64_C(  585951073928324499),  INT64_C( 6951837621371455903), -INT64_C( 2634674728066615389), -INT64_C( 2335679027541401223) },
       INT32_C(         165),
       INT32_C(           4),
      {        SIMDE_MATH_INFINITY,             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(     0.00),       -SIMDE_MATH_INFINITY,
        SIMDE_FLOAT64_C(  -937.83), SIMDE_FLOAT64_C(-179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.00), SIMDE_FLOAT64_C(     0.00),       -SIMDE_MATH_INFINITY } },
    { UINT8_C(177),
      { SIMDE_FLOAT64_C(  -591.16), SIMDE_FLOAT64_C(  -463.55), SIMDE_FLOAT64_C(   514.67), SIMDE_FLOAT64_C(    69.07),
        SIMDE_FLOAT64_C(  -967.27), SIMDE_FLOAT64_C(  -489.06), SIMDE_FLOAT64_C(   454.60), SIMDE_FLOAT64_C(    84.18) },
      { SIMDE_FLOAT64_C(  -857.95), SIMDE_FLOAT64_C(   875.42), SIMDE_FLOAT64_C(   635.53), SIMDE_FLOAT64_C(   338.21),
        SIMDE_FLOAT64_C(   750.64), SIMDE_FLOAT64_C(  -809.19), SIMDE_FLOAT64_C(   584.28), SIMDE_FLOAT64_C(  -787.91) },
      { -INT64_C( 7133431174780998126),  INT64_C( 5979620192514581591), -INT64_C( 5635059649407126340), -INT64_C( 8187236827589480161),
         INT64_C( 2956239125619661893),  INT64_C( 4072483850564115279), -INT64_C( 2981716414898604077), -INT64_C( 8986116949339199679) },
       INT32_C(         194),
       INT32_C(           8),
      { SIMDE_FLOAT64_C(     1.57), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00),
               SIMDE_MATH_INFINITY,             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(    90.00) } },
    { UINT8_C(242),
      { SIMDE_FLOAT64_C(   448.82), SIMDE_FLOAT64_C(   414.47), SIMDE_FLOAT64_C(   -51.78), SIMDE_FLOAT64_C(   408.72),
        SIMDE_FLOAT64_C(   336.73), SIMDE_FLOAT64_C(   469.70), SIMDE_FLOAT64_C(  -814.53), SIMDE_FLOAT64_C(   320.96) },
      { SIMDE_FLOAT64_C(  -955.45), SIMDE_FLOAT64_C(   865.19), SIMDE_FLOAT64_C(   455.57), SIMDE_FLOAT64_C(  -893.28),
        SIMDE_FLOAT64_C(   492.11), SIMDE_FLOAT64_C(  -391.96), SIMDE_FLOAT64_C(  -721.69), SIMDE_FLOAT64_C(   900.95) },
      { -INT64_C( 6449143524669591362), -INT64_C( 2371473677438004414),  INT64_C( 6779962613230360491),  INT64_C( 3289585334132922823),
        -INT64_C( 9174167525589568283),  INT64_C( 5495478556060732451),  INT64_C( 6243277222719539763), -INT64_C( 3384261688146921363) },
       INT32_C(         227),
       INT32_C(           8),
      { SIMDE_FLOAT64_C(     0.00),       -SIMDE_MATH_INFINITY, SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00),
        SIMDE_FLOAT64_C(   336.73),       -SIMDE_MATH_INFINITY,       -SIMDE_MATH_INFINITY, SIMDE_FLOAT64_C(     1.57) } },
    { UINT8_C(135),
      { SIMDE_FLOAT64_C(   144.50), SIMDE_FLOAT64_C(   792.98), SIMDE_FLOAT64_C(   -29.98), SIMDE_FLOAT64_C(   177.22),
        SIMDE_FLOAT64_C(  -696.08), SIMDE_FLOAT64_C(  -575.37), SIMDE_FLOAT64_C(  -738.60), SIMDE_FLOAT64_C(  -554.02) },
      { SIMDE_FLOAT64_C(  -699.96), SIMDE_FLOAT64_C(   896.93), SIMDE_FLOAT64_C(   784.19), SIMDE_FLOAT64_C(  -949.32),
        SIMDE_FLOAT64_C(  -912.27), SIMDE_FLOAT64_C(   368.47), SIMDE_FLOAT64_C(  -737.22), SIMDE_FLOAT64_C(   536.55) },
      { -INT64_C( 1061736057234306399),  INT64_C( 7012327536071505472), -INT64_C( 6784313744314221280),  INT64_C( 9184845007431449623),
        -INT64_C(  141534917352240535),  INT64_C( 3368423202643199137),  INT64_C( 8503131857160247752), -INT64_C( 8985844429119554835) },
       INT32_C(         169),
       INT32_C(           4),
      { SIMDE_FLOAT64_C(    -0.00), SIMDE_FLOAT64_C(     0.50),             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(     0.00),
        SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(    90.00) } },
    { UINT8_C(163),
      { SIMDE_FLOAT64_C(  -217.06), SIMDE_FLOAT64_C(   210.99), SIMDE_FLOAT64_C(   -54.73), SIMDE_FLOAT64_C(  -880.33),
        SIMDE_FLOAT64_C(  -319.31), SIMDE_FLOAT64_C(   130.74), SIMDE_FLOAT64_C(   440.63), SIMDE_FLOAT64_C(  -274.76) },
      { SIMDE_FLOAT64_C(    -4.07), SIMDE_FLOAT64_C(  -103.81), SIMDE_FLOAT64_C(  -168.04), SIMDE_FLOAT64_C(  -511.96),
        SIMDE_FLOAT64_C(   504.24), SIMDE_FLOAT64_C(   110.28), SIMDE_FLOAT64_C(  -611.01), SIMDE_FLOAT64_C(  -351.27) },
      {  INT64_C( 1958210809270697318),  INT64_C( 6246091724296614949), -INT64_C( 5598139918811358455), -INT64_C( 4239505320169899796),
         INT64_C( 3365334653998600766), -INT64_C( 8813164609433507834),  INT64_C( 6272745079596974580),  INT64_C( 8097762618462105916) },
       INT32_C(          27),
       INT32_C(           4),
      { SIMDE_FLOAT64_C(    -4.07), SIMDE_FLOAT64_C(     1.57), SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(     0.00),
        SIMDE_FLOAT64_C(     0.00),        SIMDE_MATH_INFINITY, SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(    90.00) } },
    { UINT8_C(190),
      { SIMDE_FLOAT64_C(   -96.74), SIMDE_FLOAT64_C(   359.01), SIMDE_FLOAT64_C(   825.96), SIMDE_FLOAT64_C(   207.18),
        SIMDE_FLOAT64_C(   783.64), SIMDE_FLOAT64_C(  -912.64), SIMDE_FLOAT64_C(   653.16), SIMDE_FLOAT64_C(  -916.32) },
      { SIMDE_FLOAT64_C(   984.28), SIMDE_FLOAT64_C(   437.35), SIMDE_FLOAT64_C(  -865.63), SIMDE_FLOAT64_C(  -927.99),
        SIMDE_FLOAT64_C(  -194.18), SIMDE_FLOAT64_C(  -602.86), SIMDE_FLOAT64_C(   608.57), SIMDE_FLOAT64_C(   588.75) },
      {  INT64_C( 7878522793235997010), -INT64_C( 5484864661059908953),  INT64_C( 1951984678309535023), -INT64_C( 6408977045583089337),
         INT64_C( 9099517377118516510), -INT64_C( 4783109162989341372),  INT64_C( 7056543696481370905),  INT64_C( 3174685955444527122) },
       INT32_C(         117),
       INT32_C(           4),
      { SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(    -1.00), SIMDE_FLOAT64_C(     1.57), SIMDE_FLOAT64_C(   207.18),
        SIMDE_FLOAT64_C(     1.00), SIMDE_FLOAT64_C(     1.00), SIMDE_FLOAT64_C(     0.00),        SIMDE_MATH_INFINITY } },
  };

  simde__m512d a, b, r;
  simde__m512i c;

  #if !defined(SIMDE_FAST_MATH)
  a = simde_mm512_loadu_pd(test_vec[0].a);
  b = simde_mm512_loadu_pd(test_vec[0].b);
  c = simde_mm512_loadu_epi64(test_vec[0].c);
  r = simde_mm512_maskz_fixupimm_round_pd(test_vec[0].k, a, b, c, INT32_C(         154), INT32_C(           4));
  simde_test_x86_assert_equal_f64x8(r, simde_mm512_loadu_pd(test_vec[0].r), 1);

  a = simde_mm512_loadu_pd(test_vec[1].a);
  b = simde_mm512_loadu_pd(test_vec[1].b);
  c = simde_mm512_loadu_epi64(test_vec[1].c);
  r = simde_mm512_maskz_fixupimm_round_pd(test_vec[1].k, a, b, c, INT32_C(         218), INT32_C(           4));
  simde_test_x86_assert_equal_f64x8(r, simde_mm512_loadu_pd(test_vec[1].r), 1);

  a = simde_mm512_loadu_pd(test_vec[2].a);
  b = simde_mm512_loadu_pd(test_vec[2].b);
  c = simde_mm512_loadu_epi64(test_vec[2].c);
  r = simde_mm512_maskz_fixupimm_round_pd(test_vec[2].k, a, b, c, INT32_C(         165), INT32_C(           4));
  simde_test_x86_assert_equal_f64x8(r, simde_mm512_loadu_pd(test_vec[2].r), 1);

  a = simde_mm512_loadu_pd(test_vec[3].a);
  b = simde_mm512_loadu_pd(test_vec[3].b);
  c = simde_mm512_loadu_epi64(test_vec[3].c);
  r = simde_mm512_maskz_fixupimm_round_pd(test_vec[3].k, a, b, c, INT32_C(         194), INT32_C(           8));
  simde_test_x86_assert_equal_f64x8(r, simde_mm512_loadu_pd(test_vec[3].r), 1);
  #endif

  a = simde_mm512_loadu_pd(test_vec[4].a);
  b = simde_mm512_loadu_pd(test_vec[4].b);
  c = simde_mm512_loadu_epi64(test_vec[4].c);
  r = simde_mm512_maskz_fixupimm_round_pd(test_vec[4].k, a, b, c, INT32_C(         227), INT32_C(           8));
  simde_test_x86_assert_equal_f64x8(r, simde_mm512_loadu_pd(test_vec[4].r), 1);

  #if !defined(SIMDE_FAST_MATH)
  a = simde_mm512_loadu_pd(test_vec[5].a);
  b = simde_mm512_loadu_pd(test_vec[5].b);
  c = simde_mm512_loadu_epi64(test_vec[5].c);
  r = simde_mm512_maskz_fixupimm_round_pd(test_vec[5].k, a, b, c, INT32_C(         169), INT32_C(           4));
  simde_test_x86_assert_equal_f64x8(r, simde_mm512_loadu_pd(test_vec[5].r), 1);
  #endif

  a = simde_mm512_loadu_pd(test_vec[6].a);
  b = simde_mm512_loadu_pd(test_vec[6].b);
  c = simde_mm512_loadu_epi64(test_vec[6].c);
  r = simde_mm512_maskz_fixupimm_round_pd(test_vec[6].k, a, b, c, INT32_C(          27), INT32_C(           4));
  simde_test_x86_assert_equal_f64x8(r, simde_mm512_loadu_pd(test_vec[6].r), 1);

  a = simde_mm512_loadu_pd(test_vec[7].a);
  b = simde_mm512_loadu_pd(test_vec[7].b);
  c = simde_mm512_loadu_epi64(test_vec[7].c);
  r = simde_mm512_maskz_fixupimm_round_pd(test_vec[7].k, a, b, c, INT32_C(         117), INT32_C(           4));
  simde_test_x86_assert_equal_f64x8(r, simde_mm512_loadu_pd(test_vec[7].r), 1);

  return 0;
#else
  fputc('\n', stdout);
  simde_float64 values[8 * 2 * sizeof(simde__m512d)];
  simde_test_x86_random_f64x8_full(8, 2, values, -1000.0, 1000.0, SIMDE_TEST_VEC_FLOAT_NAN);

  for (size_t i = 0 ; i < 8 ; i++) {
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m512d a = simde_test_x86_random_extract_f64x8(i, 2, 0, values);
    simde__m512d b = simde_test_x86_random_extract_f64x8(i, 2, 1, values);
    simde__m512i c = simde_test_x86_random_i64x8();
    int32_t imm8 = simde_test_codegen_random_i32() & 255;
    int32_t sae = simde_test_codegen_rand() & 1 ? SIMDE_MM_FROUND_NO_EXC : SIMDE_MM_FROUND_CUR_DIRECTION;
    simde__m512d r;
    SIMDE_CONSTIFY_256_NEW(simde_mm512_maskz_fixupimm_round_pd, r, simde_mm512_setzero_pd(), imm8, sae, k, a, b, c);

    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_f64x8(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f64x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i64x8(2, c, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, imm8, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, sae, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f64x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_fixupimm_round_ss (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde_float32 a[4];
    const simde_float32 b[4];
    const int32_t c[4];
    const int imm8;
    const int sae;
    const simde_float32 r[4];
  } test_vec[] = {
    { {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   484.93),            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   618.19) },
      { SIMDE_FLOAT32_C(  -891.03),            SIMDE_MATH_NANF,            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -775.92) },
      { -INT32_C(   915358689), -INT32_C(  1968983990), -INT32_C(   342607311), -INT32_C(   789356136) },
       INT32_C(          90),
       INT32_C(           8),
      { SIMDE_FLOAT32_C(    -1.00),            SIMDE_MATH_NANF,            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -775.92) } },
    { { SIMDE_FLOAT32_C(   443.37), SIMDE_FLOAT32_C(  -980.89), SIMDE_FLOAT32_C(   660.39), SIMDE_FLOAT32_C(  -269.52) },
      { SIMDE_FLOAT32_C(   110.75), SIMDE_FLOAT32_C(   728.41), SIMDE_FLOAT32_C(  -163.77), SIMDE_FLOAT32_C(   722.66) },
      { -INT32_C(  1165806033), -INT32_C(  1673248677),  INT32_C(    45850437), -INT32_C(  1085504241) },
       INT32_C(          40),
       INT32_C(           8),
      { SIMDE_FLOAT32_C(     0.50), SIMDE_FLOAT32_C(   728.41), SIMDE_FLOAT32_C(  -163.77), SIMDE_FLOAT32_C(   722.66) } },
    { { SIMDE_FLOAT32_C(  -743.62), SIMDE_FLOAT32_C(   272.76), SIMDE_FLOAT32_C(   742.68), SIMDE_FLOAT32_C(   419.71) },
      { SIMDE_FLOAT32_C(  -453.13), SIMDE_FLOAT32_C(   780.52), SIMDE_FLOAT32_C(   968.73), SIMDE_FLOAT32_C(  -710.86) },
      { -INT32_C(   808649764), -INT32_C(  2098125109), -INT32_C(  1045321589),  INT32_C(  1797090347) },
       INT32_C(         176),
       INT32_C(           4),
      { SIMDE_FLOAT32_C(-340282346638528859811704183484516925440.00), SIMDE_FLOAT32_C(   780.52), SIMDE_FLOAT32_C(   968.73), SIMDE_FLOAT32_C(  -710.86) } },
    { { SIMDE_FLOAT32_C(   481.89), SIMDE_FLOAT32_C(  -947.24), SIMDE_FLOAT32_C(   549.50), SIMDE_FLOAT32_C(  -760.98) },
      { SIMDE_FLOAT32_C(   468.48), SIMDE_FLOAT32_C(    65.76), SIMDE_FLOAT32_C(   496.25), SIMDE_FLOAT32_C(  -826.51) },
      { -INT32_C(      434509),  INT32_C(   248914205),  INT32_C(  2146058628),  INT32_C(   877312270) },
       INT32_C(         171),
       INT32_C(           4),
      { SIMDE_FLOAT32_C(-340282346638528859811704183484516925440.00), SIMDE_FLOAT32_C(    65.76), SIMDE_FLOAT32_C(   496.25), SIMDE_FLOAT32_C(  -826.51) } },
    { { SIMDE_FLOAT32_C(  -449.32), SIMDE_FLOAT32_C(   657.95), SIMDE_FLOAT32_C(   791.68), SIMDE_FLOAT32_C(  -340.35) },
      { SIMDE_FLOAT32_C(  -616.66), SIMDE_FLOAT32_C(  -731.37), SIMDE_FLOAT32_C(  -116.27), SIMDE_FLOAT32_C(   826.71) },
      { -INT32_C(  1628799103), -INT32_C(  1688757526),  INT32_C(  1213123562), -INT32_C(   429502779) },
       INT32_C(          36),
       INT32_C(           4),
      { SIMDE_FLOAT32_C(340282346638528859811704183484516925440.00), SIMDE_FLOAT32_C(  -731.37), SIMDE_FLOAT32_C(  -116.27), SIMDE_FLOAT32_C(   826.71) } },
    { { SIMDE_FLOAT32_C(  -712.26), SIMDE_FLOAT32_C(  -455.88), SIMDE_FLOAT32_C(  -442.81), SIMDE_FLOAT32_C(   398.50) },
      { SIMDE_FLOAT32_C(  -727.47), SIMDE_FLOAT32_C(   393.42), SIMDE_FLOAT32_C(   121.16), SIMDE_FLOAT32_C(  -471.09) },
      {  INT32_C(   857175273),  INT32_C(  1744880296), -INT32_C(  1779859946),  INT32_C(    41912168) },
       INT32_C(         222),
       INT32_C(           8),
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   393.42), SIMDE_FLOAT32_C(   121.16), SIMDE_FLOAT32_C(  -471.09) } },
    { { SIMDE_FLOAT32_C(  -333.82), SIMDE_FLOAT32_C(  -136.16), SIMDE_FLOAT32_C(   948.62), SIMDE_FLOAT32_C(   213.05) },
      { SIMDE_FLOAT32_C(  -355.63), SIMDE_FLOAT32_C(   917.35), SIMDE_FLOAT32_C(   502.19), SIMDE_FLOAT32_C(  -873.74) },
      { -INT32_C(  1682477515), -INT32_C(  1089479595), -INT32_C(  1230410430),  INT32_C(  1197399172) },
       INT32_C(         220),
       INT32_C(           8),
      { SIMDE_FLOAT32_C(     0.50), SIMDE_FLOAT32_C(   917.35), SIMDE_FLOAT32_C(   502.19), SIMDE_FLOAT32_C(  -873.74) } },
    { { SIMDE_FLOAT32_C(   970.11), SIMDE_FLOAT32_C(    51.69), SIMDE_FLOAT32_C(  -634.73), SIMDE_FLOAT32_C(   438.59) },
      { SIMDE_FLOAT32_C(  -882.56), SIMDE_FLOAT32_C(   861.52), SIMDE_FLOAT32_C(   612.08), SIMDE_FLOAT32_C(  -331.87) },
      {  INT32_C(  1899414258), -INT32_C(  1316219707),  INT32_C(   753333950), -INT32_C(  1988001363) },
       INT32_C(         144),
       INT32_C(           4),
      { SIMDE_FLOAT32_C(  -882.56), SIMDE_FLOAT32_C(   861.52), SIMDE_FLOAT32_C(   612.08), SIMDE_FLOAT32_C(  -331.87) } },
  };

  simde__m128 a, b, r;
  simde__m128i c;

  #if !defined(SIMDE_FAST_MATH)
  a = simde_mm_loadu_ps(test_vec[0].a);
  b = simde_mm_loadu_ps(test_vec[0].b);
  c = simde_x_mm_loadu_epi32(test_vec[0].c);
  r = simde_mm_fixupimm_round_ss(a, b, c, INT32_C(          90), INT32_C(           8));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[0].r), 1);
  #endif

  a = simde_mm_loadu_ps(test_vec[1].a);
  b = simde_mm_loadu_ps(test_vec[1].b);
  c = simde_x_mm_loadu_epi32(test_vec[1].c);
  r = simde_mm_fixupimm_round_ss(a, b, c, INT32_C(          40), INT32_C(           8));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[1].r), 1);

  a = simde_mm_loadu_ps(test_vec[2].a);
  b = simde_mm_loadu_ps(test_vec[2].b);
  c = simde_x_mm_loadu_epi32(test_vec[2].c);
  r = simde_mm_fixupimm_round_ss(a, b, c, INT32_C(         176), INT32_C(           4));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[2].r), 1);

  a = simde_mm_loadu_ps(test_vec[3].a);
  b = simde_mm_loadu_ps(test_vec[3].b);
  c = simde_x_mm_loadu_epi32(test_vec[3].c);
  r = simde_mm_fixupimm_round_ss(a, b, c, INT32_C(         171), INT32_C(           4));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[3].r), 1);

  a = simde_mm_loadu_ps(test_vec[4].a);
  b = simde_mm_loadu_ps(test_vec[4].b);
  c = simde_x_mm_loadu_epi32(test_vec[4].c);
  r = simde_mm_fixupimm_round_ss(a, b, c, INT32_C(          36), INT32_C(           4));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[4].r), 1);

  #if !defined(SIMDE_FAST_MATH)
  a = simde_mm_loadu_ps(test_vec[5].a);
  b = simde_mm_loadu_ps(test_vec[5].b);
  c = simde_x_mm_loadu_epi32(test_vec[5].c);
  r = simde_mm_fixupimm_round_ss(a, b, c, INT32_C(         222), INT32_C(           8));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[5].r), 1);
  #endif

  a = simde_mm_loadu_ps(test_vec[6].a);
  b = simde_mm_loadu_ps(test_vec[6].b);
  c = simde_x_mm_loadu_epi32(test_vec[6].c);
  r = simde_mm_fixupimm_round_ss(a, b, c, INT32_C(         220), INT32_C(           8));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[6].r), 1);

  a = simde_mm_loadu_ps(test_vec[7].a);
  b = simde_mm_loadu_ps(test_vec[7].b);
  c = simde_x_mm_loadu_epi32(test_vec[7].c);
  r = simde_mm_fixupimm_round_ss(a, b, c, INT32_C(         144), INT32_C(           4));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[7].r), 1);

  return 0;
#else
  fputc('\n', stdout);
  simde_float32 values[8 * 2 * sizeof(simde__m128)];
  simde_test_x86_random_f32x4_full(8, 2, values, -1000.0f, 1000.0f, SIMDE_TEST_VEC_FLOAT_NAN);

  for (size_t i = 0 ; i < 8 ; i++) {
    simde__m128 a = simde_test_x86_random_extract_f32x4(i, 2, 0, values);
    simde__m128 b = simde_test_x86_random_extract_f32x4(i, 2, 1, values);
    simde__m128i c = simde_test_x86_random_i32x4();
    int32_t imm8 = simde_test_codegen_random_i32() & 255;
    int32_t sae = simde_test_codegen_rand() & 1 ? SIMDE_MM_FROUND_NO_EXC : SIMDE_MM_FROUND_CUR_DIRECTION;
    simde__m128 r;
    SIMDE_CONSTIFY_256_NEW(simde_mm_fixupimm_round_ss, r, simde_mm_setzero_ps(), imm8, sae, a, b, c);

    simde_test_x86_write_f32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_f32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x4(2, c, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, imm8, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, sae, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_mask_fixupimm_round_ss (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde_float32 a[4];
    const simde__mmask8 k;
    const simde_float32 b[4];
    const int32_t c[4];
    const int imm8;
    const int sae;
    const simde_float32 r[4];
  } test_vec[] = {
    { {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -558.97),            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -941.38) },
      UINT8_C( 22),
      { SIMDE_FLOAT32_C(  -236.70),            SIMDE_MATH_NANF,            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   -20.79) },
      { -INT32_C(  2101913748), -INT32_C(  1427155211), -INT32_C(  1712723787),  INT32_C(  2075410050) },
       INT32_C(         159),
       INT32_C(           8),
      {            SIMDE_MATH_NANF,            SIMDE_MATH_NANF,            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   -20.79) } },
    { { SIMDE_FLOAT32_C(  -181.10), SIMDE_FLOAT32_C(  -469.17), SIMDE_FLOAT32_C(  -288.79), SIMDE_FLOAT32_C(   828.86) },
      UINT8_C(145),
      { SIMDE_FLOAT32_C(  -385.23), SIMDE_FLOAT32_C(  -485.60), SIMDE_FLOAT32_C(   234.17), SIMDE_FLOAT32_C(  -548.14) },
      { -INT32_C(  2089761257), -INT32_C(   662730504),  INT32_C(  1429203870),  INT32_C(  1571562606) },
       INT32_C(         207),
       INT32_C(           8),
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -485.60), SIMDE_FLOAT32_C(   234.17), SIMDE_FLOAT32_C(  -548.14) } },
    { { SIMDE_FLOAT32_C(  -679.64), SIMDE_FLOAT32_C(   555.14), SIMDE_FLOAT32_C(  -225.16), SIMDE_FLOAT32_C(   284.74) },
      UINT8_C(199),
      { SIMDE_FLOAT32_C(   208.40), SIMDE_FLOAT32_C(   525.38), SIMDE_FLOAT32_C(   307.21), SIMDE_FLOAT32_C(   -55.02) },
      { -INT32_C(  1774014473),  INT32_C(  1548763546),  INT32_C(  1126328530),  INT32_C(  1808472811) },
       INT32_C(         242),
       INT32_C(           4),
      { SIMDE_FLOAT32_C(    -1.00), SIMDE_FLOAT32_C(   525.38), SIMDE_FLOAT32_C(   307.21), SIMDE_FLOAT32_C(   -55.02) } },
    { { SIMDE_FLOAT32_C(   346.88), SIMDE_FLOAT32_C(  -488.37), SIMDE_FLOAT32_C(    44.08), SIMDE_FLOAT32_C(   364.14) },
      UINT8_C(196),
      { SIMDE_FLOAT32_C(  -915.27), SIMDE_FLOAT32_C(   534.98), SIMDE_FLOAT32_C(  -356.97), SIMDE_FLOAT32_C(   594.70) },
      {  INT32_C(   354511430), -INT32_C(   942774580),  INT32_C(  1870054701), -INT32_C(  1397682085) },
       INT32_C(         108),
       INT32_C(           4),
      { SIMDE_FLOAT32_C(   346.88), SIMDE_FLOAT32_C(   534.98), SIMDE_FLOAT32_C(  -356.97), SIMDE_FLOAT32_C(   594.70) } },
    { { SIMDE_FLOAT32_C(   976.01), SIMDE_FLOAT32_C(   996.55), SIMDE_FLOAT32_C(   653.32), SIMDE_FLOAT32_C(  -260.69) },
         UINT8_MAX,
      { SIMDE_FLOAT32_C(   350.24), SIMDE_FLOAT32_C(  -433.84), SIMDE_FLOAT32_C(   718.52), SIMDE_FLOAT32_C(  -830.86) },
      { -INT32_C(  1670737495), -INT32_C(  1178680838), -INT32_C(  1490877307), -INT32_C(   401740006) },
       INT32_C(         182),
       INT32_C(           4),
      { SIMDE_FLOAT32_C(    -1.00), SIMDE_FLOAT32_C(  -433.84), SIMDE_FLOAT32_C(   718.52), SIMDE_FLOAT32_C(  -830.86) } },
    { { SIMDE_FLOAT32_C(    96.99), SIMDE_FLOAT32_C(  -570.27), SIMDE_FLOAT32_C(   998.00), SIMDE_FLOAT32_C(   711.76) },
      UINT8_C(  8),
      { SIMDE_FLOAT32_C(   -55.87), SIMDE_FLOAT32_C(   232.17), SIMDE_FLOAT32_C(  -836.38), SIMDE_FLOAT32_C(   264.49) },
      { -INT32_C(  1447797955), -INT32_C(  1523005217),  INT32_C(   842523336),  INT32_C(  1022570878) },
       INT32_C(         234),
       INT32_C(           4),
      { SIMDE_FLOAT32_C(    96.99), SIMDE_FLOAT32_C(   232.17), SIMDE_FLOAT32_C(  -836.38), SIMDE_FLOAT32_C(   264.49) } },
    { { SIMDE_FLOAT32_C(  -212.69), SIMDE_FLOAT32_C(   -61.54), SIMDE_FLOAT32_C(  -450.77), SIMDE_FLOAT32_C(   995.71) },
      UINT8_C( 90),
      { SIMDE_FLOAT32_C(  -536.16), SIMDE_FLOAT32_C(   856.44), SIMDE_FLOAT32_C(   -59.31), SIMDE_FLOAT32_C(   810.73) },
      { -INT32_C(  1270731267),  INT32_C(   333508456), -INT32_C(  1402069512), -INT32_C(     9089593) },
       INT32_C(         243),
       INT32_C(           8),
      { SIMDE_FLOAT32_C(  -212.69), SIMDE_FLOAT32_C(   856.44), SIMDE_FLOAT32_C(   -59.31), SIMDE_FLOAT32_C(   810.73) } },
    { { SIMDE_FLOAT32_C(  -631.93), SIMDE_FLOAT32_C(   984.78), SIMDE_FLOAT32_C(   174.87), SIMDE_FLOAT32_C(  -547.19) },
      UINT8_C( 95),
      { SIMDE_FLOAT32_C(   519.76), SIMDE_FLOAT32_C(   817.90), SIMDE_FLOAT32_C(  -952.49), SIMDE_FLOAT32_C(   495.77) },
      {  INT32_C(  1184588635), -INT32_C(    61547300),  INT32_C(  2032750902), -INT32_C(   429354491) },
       INT32_C(         165),
       INT32_C(           8),
      {     -SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(   817.90), SIMDE_FLOAT32_C(  -952.49), SIMDE_FLOAT32_C(   495.77) } },
  };

  simde__m128 a, b, r;
  simde__m128i c;

  #if !defined(SIMDE_FAST_MATH)
  a = simde_mm_loadu_ps(test_vec[0].a);
  b = simde_mm_loadu_ps(test_vec[0].b);
  c = simde_x_mm_loadu_epi32(test_vec[0].c);
  r = simde_mm_mask_fixupimm_round_ss(a, test_vec[0].k, b, c, INT32_C(         159), INT32_C(           8));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[0].r), 1);

  a = simde_mm_loadu_ps(test_vec[1].a);
  b = simde_mm_loadu_ps(test_vec[1].b);
  c = simde_x_mm_loadu_epi32(test_vec[1].c);
  r = simde_mm_mask_fixupimm_round_ss(a, test_vec[1].k, b, c, INT32_C(         207), INT32_C(           8));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[1].r), 1);
  #endif

  a = simde_mm_loadu_ps(test_vec[2].a);
  b = simde_mm_loadu_ps(test_vec[2].b);
  c = simde_x_mm_loadu_epi32(test_vec[2].c);
  r = simde_mm_mask_fixupimm_round_ss(a, test_vec[2].k, b, c, INT32_C(         242), INT32_C(           4));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[2].r), 1);

  a = simde_mm_loadu_ps(test_vec[3].a);
  b = simde_mm_loadu_ps(test_vec[3].b);
  c = simde_x_mm_loadu_epi32(test_vec[3].c);
  r = simde_mm_mask_fixupimm_round_ss(a, test_vec[3].k, b, c, INT32_C(         108), INT32_C(           4));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[3].r), 1);

  a = simde_mm_loadu_ps(test_vec[4].a);
  b = simde_mm_loadu_ps(test_vec[4].b);
  c = simde_x_mm_loadu_epi32(test_vec[4].c);
  r = simde_mm_mask_fixupimm_round_ss(a, test_vec[4].k, b, c, INT32_C(         182), INT32_C(           4));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[4].r), 1);

  a = simde_mm_loadu_ps(test_vec[5].a);
  b = simde_mm_loadu_ps(test_vec[5].b);
  c = simde_x_mm_loadu_epi32(test_vec[5].c);
  r = simde_mm_mask_fixupimm_round_ss(a, test_vec[5].k, b, c, INT32_C(         234), INT32_C(           4));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[5].r), 1);

  a = simde_mm_loadu_ps(test_vec[6].a);
  b = simde_mm_loadu_ps(test_vec[6].b);
  c = simde_x_mm_loadu_epi32(test_vec[6].c);
  r = simde_mm_mask_fixupimm_round_ss(a, test_vec[6].k, b, c, INT32_C(         243), INT32_C(           8));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[6].r), 1);

  a = simde_mm_loadu_ps(test_vec[7].a);
  b = simde_mm_loadu_ps(test_vec[7].b);
  c = simde_x_mm_loadu_epi32(test_vec[7].c);
  r = simde_mm_mask_fixupimm_round_ss(a, test_vec[7].k, b, c, INT32_C(         165), INT32_C(           8));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[7].r), 1);

  return 0;
#else
  fputc('\n', stdout);
  simde_float32 values[8 * 2 * sizeof(simde__m128)];
  simde_test_x86_random_f32x4_full(8, 2, values, -1000.0f, 1000.0f, SIMDE_TEST_VEC_FLOAT_NAN);

  for (size_t i = 0 ; i < 8 ; i++) {
    simde__m128 a = simde_test_x86_random_extract_f32x4(i, 2, 0, values);
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m128 b = simde_test_x86_random_extract_f32x4(i, 2, 1, values);
    simde__m128i c = simde_test_x86_random_i32x4();
    int32_t imm8 = simde_test_codegen_random_i32() & 255;
    int32_t sae = simde_test_codegen_rand() & 1 ? SIMDE_MM_FROUND_NO_EXC : SIMDE_MM_FROUND_CUR_DIRECTION;
    simde__m128 r;
    SIMDE_CONSTIFY_256_NEW(simde_mm_mask_fixupimm_round_ss, r, simde_mm_setzero_ps(), imm8, sae, a, k, b, c);

    simde_test_x86_write_f32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x4(2, c, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, imm8, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, sae, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_maskz_fixupimm_round_ss (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask8 k;
    const simde_float32 a[4];
    const simde_float32 b[4];
    const int32_t c[4];
    const int imm8;
    const int sae;
    const simde_float32 r[4];
  } test_vec[] = {
    { UINT8_C( 58),
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   307.29),            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -876.38) },
      { SIMDE_FLOAT32_C(  -551.78),            SIMDE_MATH_NANF,            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -145.35) },
      {  INT32_C(   746786872),  INT32_C(   187431713),  INT32_C(  2048184324), -INT32_C(   648375816) },
       INT32_C(         211),
       INT32_C(           8),
      { SIMDE_FLOAT32_C(     0.00),            SIMDE_MATH_NANF,            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(  -145.35) } },
    { UINT8_C(154),
      { SIMDE_FLOAT32_C(   264.77), SIMDE_FLOAT32_C(  -225.89), SIMDE_FLOAT32_C(  -925.52), SIMDE_FLOAT32_C(   548.42) },
      { SIMDE_FLOAT32_C(   631.74), SIMDE_FLOAT32_C(   196.86), SIMDE_FLOAT32_C(  -431.88), SIMDE_FLOAT32_C(   393.44) },
      {  INT32_C(   239257501), -INT32_C(  2046954745), -INT32_C(  1315621587), -INT32_C(  1934838175) },
       INT32_C(         193),
       INT32_C(           4),
      { SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   196.86), SIMDE_FLOAT32_C(  -431.88), SIMDE_FLOAT32_C(   393.44) } },
    { UINT8_C( 85),
      { SIMDE_FLOAT32_C(  -389.63), SIMDE_FLOAT32_C(  -191.75), SIMDE_FLOAT32_C(    71.86), SIMDE_FLOAT32_C(    93.04) },
      { SIMDE_FLOAT32_C(  -406.32), SIMDE_FLOAT32_C(   719.70), SIMDE_FLOAT32_C(   466.37), SIMDE_FLOAT32_C(   602.75) },
      {  INT32_C(   992970087), -INT32_C(  1206183086), -INT32_C(   125847371), -INT32_C(  1007974714) },
       INT32_C(          11),
       INT32_C(           8),
      { SIMDE_FLOAT32_C(     0.50), SIMDE_FLOAT32_C(   719.70), SIMDE_FLOAT32_C(   466.37), SIMDE_FLOAT32_C(   602.75) } },
    { UINT8_C( 90),
      { SIMDE_FLOAT32_C(  -790.82), SIMDE_FLOAT32_C(   600.66), SIMDE_FLOAT32_C(  -441.92), SIMDE_FLOAT32_C(  -847.40) },
      { SIMDE_FLOAT32_C(  -232.61), SIMDE_FLOAT32_C(   558.96), SIMDE_FLOAT32_C(   820.52), SIMDE_FLOAT32_C(  -720.70) },
      {  INT32_C(   434599255),  INT32_C(  1357857829), -INT32_C(   925542759), -INT32_C(  1394333807) },
       INT32_C(         223),
       INT32_C(           8),
      { SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   558.96), SIMDE_FLOAT32_C(   820.52), SIMDE_FLOAT32_C(  -720.70) } },
    { UINT8_C( 42),
      { SIMDE_FLOAT32_C(  -133.75), SIMDE_FLOAT32_C(   425.70), SIMDE_FLOAT32_C(  -597.08), SIMDE_FLOAT32_C(   314.47) },
      { SIMDE_FLOAT32_C(  -774.51), SIMDE_FLOAT32_C(    63.45), SIMDE_FLOAT32_C(  -830.88), SIMDE_FLOAT32_C(   490.27) },
      { -INT32_C(   236028699),  INT32_C(  1586685845),  INT32_C(   685041985), -INT32_C(   244516606) },
       INT32_C(          73),
       INT32_C(           4),
      { SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(    63.45), SIMDE_FLOAT32_C(  -830.88), SIMDE_FLOAT32_C(   490.27) } },
    { UINT8_C(217),
      { SIMDE_FLOAT32_C(   837.56), SIMDE_FLOAT32_C(  -756.40), SIMDE_FLOAT32_C(    38.68), SIMDE_FLOAT32_C(   469.30) },
      { SIMDE_FLOAT32_C(   440.46), SIMDE_FLOAT32_C(   606.81), SIMDE_FLOAT32_C(  -137.25), SIMDE_FLOAT32_C(  -949.17) },
      {  INT32_C(   629584454), -INT32_C(   578491828),  INT32_C(    56257045), -INT32_C(   303370405) },
       INT32_C(          77),
       INT32_C(           4),
      {            SIMDE_MATH_NANF, SIMDE_FLOAT32_C(   606.81), SIMDE_FLOAT32_C(  -137.25), SIMDE_FLOAT32_C(  -949.17) } },
    { UINT8_C(217),
      { SIMDE_FLOAT32_C(  -584.94), SIMDE_FLOAT32_C(   934.60), SIMDE_FLOAT32_C(   143.87), SIMDE_FLOAT32_C(     8.73) },
      { SIMDE_FLOAT32_C(   654.30), SIMDE_FLOAT32_C(  -389.76), SIMDE_FLOAT32_C(  -388.51), SIMDE_FLOAT32_C(   863.48) },
      {  INT32_C(  1691009051), -INT32_C(  1786572090),  INT32_C(  1917307372),  INT32_C(  1935447022) },
       INT32_C(         113),
       INT32_C(           4),
      {      SIMDE_MATH_INFINITYF, SIMDE_FLOAT32_C(  -389.76), SIMDE_FLOAT32_C(  -388.51), SIMDE_FLOAT32_C(   863.48) } },
    { UINT8_C( 56),
      { SIMDE_FLOAT32_C(  -789.10), SIMDE_FLOAT32_C(   169.57), SIMDE_FLOAT32_C(  -983.92), SIMDE_FLOAT32_C(   -21.71) },
      { SIMDE_FLOAT32_C(  -271.47), SIMDE_FLOAT32_C(   836.60), SIMDE_FLOAT32_C(   257.59), SIMDE_FLOAT32_C(   594.78) },
      {  INT32_C(   119889594), -INT32_C(   567673974), -INT32_C(  1617017644),  INT32_C(   733046184) },
       INT32_C(         250),
       INT32_C(           8),
      { SIMDE_FLOAT32_C(     0.00), SIMDE_FLOAT32_C(   836.60), SIMDE_FLOAT32_C(   257.59), SIMDE_FLOAT32_C(   594.78) } },
  };

  simde__m128 a, b, r;
  simde__m128i c;

  #if !defined(SIMDE_FAST_MATH)
  a = simde_mm_loadu_ps(test_vec[0].a);
  b = simde_mm_loadu_ps(test_vec[0].b);
  c = simde_x_mm_loadu_epi32(test_vec[0].c);
  r = simde_mm_maskz_fixupimm_round_ss(test_vec[0].k, a, b, c, INT32_C(         211), INT32_C(           8));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[0].r), 1);
  #endif

  a = simde_mm_loadu_ps(test_vec[1].a);
  b = simde_mm_loadu_ps(test_vec[1].b);
  c = simde_x_mm_loadu_epi32(test_vec[1].c);
  r = simde_mm_maskz_fixupimm_round_ss(test_vec[1].k, a, b, c, INT32_C(         193), INT32_C(           4));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[1].r), 1);

  a = simde_mm_loadu_ps(test_vec[2].a);
  b = simde_mm_loadu_ps(test_vec[2].b);
  c = simde_x_mm_loadu_epi32(test_vec[2].c);
  r = simde_mm_maskz_fixupimm_round_ss(test_vec[2].k, a, b, c, INT32_C(          11), INT32_C(           8));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[2].r), 1);

  a = simde_mm_loadu_ps(test_vec[3].a);
  b = simde_mm_loadu_ps(test_vec[3].b);
  c = simde_x_mm_loadu_epi32(test_vec[3].c);
  r = simde_mm_maskz_fixupimm_round_ss(test_vec[3].k, a, b, c, INT32_C(         223), INT32_C(           8));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[3].r), 1);

  a = simde_mm_loadu_ps(test_vec[4].a);
  b = simde_mm_loadu_ps(test_vec[4].b);
  c = simde_x_mm_loadu_epi32(test_vec[4].c);
  r = simde_mm_maskz_fixupimm_round_ss(test_vec[4].k, a, b, c, INT32_C(          73), INT32_C(           4));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[4].r), 1);

  #if !defined(SIMDE_FAST_MATH)
  a = simde_mm_loadu_ps(test_vec[5].a);
  b = simde_mm_loadu_ps(test_vec[5].b);
  c = simde_x_mm_loadu_epi32(test_vec[5].c);
  r = simde_mm_maskz_fixupimm_round_ss(test_vec[5].k, a, b, c, INT32_C(          77), INT32_C(           4));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[5].r), 1);
  #endif

  a = simde_mm_loadu_ps(test_vec[6].a);
  b = simde_mm_loadu_ps(test_vec[6].b);
  c = simde_x_mm_loadu_epi32(test_vec[6].c);
  r = simde_mm_maskz_fixupimm_round_ss(test_vec[6].k, a, b, c, INT32_C(         113), INT32_C(           4));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[6].r), 1);

  a = simde_mm_loadu_ps(test_vec[7].a);
  b = simde_mm_loadu_ps(test_vec[7].b);
  c = simde_x_mm_loadu_epi32(test_vec[7].c);
  r = simde_mm_maskz_fixupimm_round_ss(test_vec[7].k, a, b, c, INT32_C(         250), INT32_C(           8));
  simde_test_x86_assert_equal_f32x4(r, simde_mm_loadu_ps(test_vec[7].r), 1);

  return 0;
#else
  fputc('\n', stdout);
  simde_float32 values[8 * 2 * sizeof(simde__m128)];
  simde_test_x86_random_f32x4_full(8, 2, values, -1000.0f, 1000.0f, SIMDE_TEST_VEC_FLOAT_NAN);

  for (size_t i = 0 ; i < 8 ; i++) {
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m128 a = simde_test_x86_random_extract_f32x4(i, 2, 0, values);
    simde__m128 b = simde_test_x86_random_extract_f32x4(i, 2, 1, values);
    simde__m128i c = simde_test_x86_random_i32x4();
    int32_t imm8 = simde_test_codegen_random_i32() & 255;
    int32_t sae = simde_test_codegen_rand() & 1 ? SIMDE_MM_FROUND_NO_EXC : SIMDE_MM_FROUND_CUR_DIRECTION;
    simde__m128 r;
    SIMDE_CONSTIFY_256_NEW(simde_mm_maskz_fixupimm_round_ss, r, simde_mm_setzero_ps(), imm8, sae, k, a, b, c);

    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_f32x4(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x4(2, c, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, imm8, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, sae, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_fixupimm_round_sd (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde_float64 a[2];
    const simde_float64 b[2];
    const int64_t c[2];
    const int imm8;
    const int sae;
    const simde_float64 r[2];
  } test_vec[] = {
    { { SIMDE_FLOAT64_C(  -953.69), SIMDE_FLOAT64_C(   256.71) },
      { SIMDE_FLOAT64_C(   809.19), SIMDE_FLOAT64_C(   836.44) },
      {  INT64_C( 3280897190386030812),  INT64_C( 5860799335009507841) },
       INT32_C(          67),
       INT32_C(           4),
      { SIMDE_FLOAT64_C(    -1.00), SIMDE_FLOAT64_C(   836.44) } },
    { { SIMDE_FLOAT64_C(   913.50), SIMDE_FLOAT64_C(  -849.84) },
      { SIMDE_FLOAT64_C(  -810.34), SIMDE_FLOAT64_C(  -668.11) },
      {  INT64_C( 4739883477528554924),  INT64_C( 4760879747932446971) },
       INT32_C(          32),
       INT32_C(           4),
      { SIMDE_FLOAT64_C(     1.00), SIMDE_FLOAT64_C(  -668.11) } },
    { { SIMDE_FLOAT64_C(  -763.75), SIMDE_FLOAT64_C(  -588.42) },
      { SIMDE_FLOAT64_C(  -713.58), SIMDE_FLOAT64_C(  -405.59) },
      { -INT64_C( 6254926502031689123),  INT64_C( 4921258895878462942) },
       INT32_C(         175),
       INT32_C(           4),
      {       -SIMDE_MATH_INFINITY, SIMDE_FLOAT64_C(  -405.59) } },
    { { SIMDE_FLOAT64_C(   304.21), SIMDE_FLOAT64_C(   507.99) },
      { SIMDE_FLOAT64_C(  -588.46), SIMDE_FLOAT64_C(  -208.13) },
      {  INT64_C( 2825227760063473335),  INT64_C(  746274746142014323) },
       INT32_C(         222),
       INT32_C(           8),
      { SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(  -208.13) } },
    { { SIMDE_FLOAT64_C(   -39.31), SIMDE_FLOAT64_C(  -161.31) },
      { SIMDE_FLOAT64_C(  -595.73), SIMDE_FLOAT64_C(  -204.23) },
      { -INT64_C( 6365151145013362151),  INT64_C( 8233843147673010840) },
       INT32_C(          32),
       INT32_C(           4),
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(  -204.23) } },
    { { SIMDE_FLOAT64_C(   224.13), SIMDE_FLOAT64_C(  -927.98) },
      { SIMDE_FLOAT64_C(  -547.78), SIMDE_FLOAT64_C(   777.79) },
      { -INT64_C( 3137625675804197125), -INT64_C( 7800167410701080648) },
       INT32_C(         146),
       INT32_C(           4),
      { SIMDE_FLOAT64_C(     0.50), SIMDE_FLOAT64_C(   777.79) } },
    { { SIMDE_FLOAT64_C(  -356.62), SIMDE_FLOAT64_C(   -26.60) },
      { SIMDE_FLOAT64_C(  -695.32), SIMDE_FLOAT64_C(  -318.09) },
      {  INT64_C( 4170577878658233243),  INT64_C( 1660455729788304233) },
       INT32_C(         181),
       INT32_C(           4),
      {        SIMDE_MATH_INFINITY, SIMDE_FLOAT64_C(  -318.09) } },
    { { SIMDE_FLOAT64_C(    60.59), SIMDE_FLOAT64_C(   998.85) },
      { SIMDE_FLOAT64_C(  -448.50), SIMDE_FLOAT64_C(   -69.04) },
      { -INT64_C( 6314926335164457582),  INT64_C( 6750152718740046181) },
       INT32_C(         168),
       INT32_C(           4),
      { SIMDE_FLOAT64_C(  -448.50), SIMDE_FLOAT64_C(   -69.04) } },
  };

  simde__m128d a, b, r;
  simde__m128i c;

  a = simde_mm_loadu_pd(test_vec[0].a);
  b = simde_mm_loadu_pd(test_vec[0].b);
  c = simde_x_mm_loadu_epi64(test_vec[0].c);
  r = simde_mm_fixupimm_round_sd(a, b, c, INT32_C(          67), INT32_C(           4));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[0].r), 1);

  a = simde_mm_loadu_pd(test_vec[1].a);
  b = simde_mm_loadu_pd(test_vec[1].b);
  c = simde_x_mm_loadu_epi64(test_vec[1].c);
  r = simde_mm_fixupimm_round_sd(a, b, c, INT32_C(          32), INT32_C(           4));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[1].r), 1);

  a = simde_mm_loadu_pd(test_vec[2].a);
  b = simde_mm_loadu_pd(test_vec[2].b);
  c = simde_x_mm_loadu_epi64(test_vec[2].c);
  r = simde_mm_fixupimm_round_sd(a, b, c, INT32_C(         175), INT32_C(           4));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[2].r), 1);

  a = simde_mm_loadu_pd(test_vec[3].a);
  b = simde_mm_loadu_pd(test_vec[3].b);
  c = simde_x_mm_loadu_epi64(test_vec[3].c);
  r = simde_mm_fixupimm_round_sd(a, b, c, INT32_C(         222), INT32_C(           8));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[3].r), 1);

  #if !defined(SIMDE_FAST_MATH)
  a = simde_mm_loadu_pd(test_vec[4].a);
  b = simde_mm_loadu_pd(test_vec[4].b);
  c = simde_x_mm_loadu_epi64(test_vec[4].c);
  r = simde_mm_fixupimm_round_sd(a, b, c, INT32_C(          32), INT32_C(           4));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[4].r), 1);
  #endif

  a = simde_mm_loadu_pd(test_vec[5].a);
  b = simde_mm_loadu_pd(test_vec[5].b);
  c = simde_x_mm_loadu_epi64(test_vec[5].c);
  r = simde_mm_fixupimm_round_sd(a, b, c, INT32_C(         146), INT32_C(           4));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[5].r), 1);

  a = simde_mm_loadu_pd(test_vec[6].a);
  b = simde_mm_loadu_pd(test_vec[6].b);
  c = simde_x_mm_loadu_epi64(test_vec[6].c);
  r = simde_mm_fixupimm_round_sd(a, b, c, INT32_C(         181), INT32_C(           4));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[6].r), 1);

  a = simde_mm_loadu_pd(test_vec[7].a);
  b = simde_mm_loadu_pd(test_vec[7].b);
  c = simde_x_mm_loadu_epi64(test_vec[7].c);
  r = simde_mm_fixupimm_round_sd(a, b, c, INT32_C(         168), INT32_C(           4));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[7].r), 1);

  return 0;
#else
  fputc('\n', stdout);
  simde_float64 values[8 * 2 * sizeof(simde__m128d)];
  simde_test_x86_random_f64x2_full(8, 2, values, -1000.0f, 1000.0f, SIMDE_TEST_VEC_FLOAT_NAN);

  for (size_t i = 0 ; i < 8 ; i++) {
    simde__m128d a = simde_test_x86_random_f64x2(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
    simde__m128d b = simde_test_x86_random_f64x2(SIMDE_FLOAT64_C(-1000.0), SIMDE_FLOAT64_C(1000.0));
    simde__m128i c = simde_test_x86_random_i64x2();
    int32_t imm8 = simde_test_codegen_random_i32() & 255;
    int32_t sae = simde_test_codegen_rand() & 1 ? SIMDE_MM_FROUND_NO_EXC : SIMDE_MM_FROUND_CUR_DIRECTION;
    simde__m128d r;
    SIMDE_CONSTIFY_256_NEW(simde_mm_fixupimm_round_sd, r, simde_mm_setzero_pd(), imm8, sae, a, b, c);

    simde_test_x86_write_f64x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_f64x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i64x2(2, c, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, imm8, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, sae, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_mask_fixupimm_round_sd (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde_float64 a[2];
    const simde__mmask8 k;
    const simde_float64 b[2];
    const int64_t c[2];
    const int imm8;
    const int sae;
    const simde_float64 r[2];
  } test_vec[] = {
    { {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   404.73) },
      UINT8_C( 32),
      { SIMDE_FLOAT64_C(   932.69),             SIMDE_MATH_NAN },
      { -INT64_C(   51085584167345319),  INT64_C( 2661215540945904134) },
       INT32_C(         163),
       INT32_C(           8),
      {             SIMDE_MATH_NAN,             SIMDE_MATH_NAN } },
    { {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(  -504.38) },
      UINT8_C( 49),
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(  -242.90) },
      {  INT64_C( 4625955115680741900),  INT64_C( 7269392653037636562) },
       INT32_C(          17),
       INT32_C(           8),
      { SIMDE_FLOAT64_C(    90.00), SIMDE_FLOAT64_C(  -242.90) } },
    { { SIMDE_FLOAT64_C(    47.12), SIMDE_FLOAT64_C(   322.15) },
      UINT8_C( 54),
      { SIMDE_FLOAT64_C(  -426.81), SIMDE_FLOAT64_C(   260.13) },
      { -INT64_C( 3669492556995353489),  INT64_C( 7658286746966695816) },
       INT32_C(         243),
       INT32_C(           4),
      { SIMDE_FLOAT64_C(    47.12), SIMDE_FLOAT64_C(   260.13) } },
    { { SIMDE_FLOAT64_C(  -103.51), SIMDE_FLOAT64_C(   362.68) },
      UINT8_C( 16),
      { SIMDE_FLOAT64_C(   777.81), SIMDE_FLOAT64_C(   152.75) },
      {  INT64_C( 8872436809921223721), -INT64_C( 5394584877202960272) },
       INT32_C(          98),
       INT32_C(           8),
      { SIMDE_FLOAT64_C(  -103.51), SIMDE_FLOAT64_C(   152.75) } },
    { { SIMDE_FLOAT64_C(  -912.26), SIMDE_FLOAT64_C(   431.56) },
      UINT8_C( 13),
      { SIMDE_FLOAT64_C(   315.05), SIMDE_FLOAT64_C(  -179.60) },
      {  INT64_C( 1812819379976898077), -INT64_C( 5896131593818975619) },
       INT32_C(          54),
       INT32_C(           8),
      { SIMDE_FLOAT64_C(   315.05), SIMDE_FLOAT64_C(  -179.60) } },
    { { SIMDE_FLOAT64_C(  -326.42), SIMDE_FLOAT64_C(   161.18) },
      UINT8_C(224),
      { SIMDE_FLOAT64_C(  -594.41), SIMDE_FLOAT64_C(   617.36) },
      {  INT64_C( 8302220109294176618), -INT64_C( 8188782830068083338) },
       INT32_C(         178),
       INT32_C(           4),
      { SIMDE_FLOAT64_C(  -326.42), SIMDE_FLOAT64_C(   617.36) } },
    { { SIMDE_FLOAT64_C(   429.63), SIMDE_FLOAT64_C(  -473.06) },
      UINT8_C(109),
      { SIMDE_FLOAT64_C(  -219.37), SIMDE_FLOAT64_C(   654.64) },
      { -INT64_C(  364693081483905308),  INT64_C( 6861435413895338553) },
       INT32_C(          42),
       INT32_C(           4),
      { SIMDE_FLOAT64_C(     1.00), SIMDE_FLOAT64_C(   654.64) } },
    { { SIMDE_FLOAT64_C(  -880.66), SIMDE_FLOAT64_C(  -859.45) },
      UINT8_C( 26),
      { SIMDE_FLOAT64_C(   470.45), SIMDE_FLOAT64_C(  -123.09) },
      { -INT64_C( 7234881268756186947), -INT64_C( 8760867323632255754) },
       INT32_C(          31),
       INT32_C(           8),
      { SIMDE_FLOAT64_C(  -880.66), SIMDE_FLOAT64_C(  -123.09) } },
  };

  simde__m128d a, b, r;
  simde__m128i c;

  #if !defined(SIMDE_FAST_MATH)
  a = simde_mm_loadu_pd(test_vec[0].a);
  b = simde_mm_loadu_pd(test_vec[0].b);
  c = simde_x_mm_loadu_epi64(test_vec[0].c);
  r = simde_mm_mask_fixupimm_round_sd(a, test_vec[0].k, b, c, INT32_C(         163), INT32_C(           8));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[0].r), 1);

  a = simde_mm_loadu_pd(test_vec[1].a);
  b = simde_mm_loadu_pd(test_vec[1].b);
  c = simde_x_mm_loadu_epi64(test_vec[1].c);
  r = simde_mm_mask_fixupimm_round_sd(a, test_vec[1].k, b, c, INT32_C(          17), INT32_C(           8));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[1].r), 1);
  #endif

  a = simde_mm_loadu_pd(test_vec[2].a);
  b = simde_mm_loadu_pd(test_vec[2].b);
  c = simde_x_mm_loadu_epi64(test_vec[2].c);
  r = simde_mm_mask_fixupimm_round_sd(a, test_vec[2].k, b, c, INT32_C(         243), INT32_C(           4));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[2].r), 1);

  a = simde_mm_loadu_pd(test_vec[3].a);
  b = simde_mm_loadu_pd(test_vec[3].b);
  c = simde_x_mm_loadu_epi64(test_vec[3].c);
  r = simde_mm_mask_fixupimm_round_sd(a, test_vec[3].k, b, c, INT32_C(          98), INT32_C(           8));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[3].r), 1);

  a = simde_mm_loadu_pd(test_vec[4].a);
  b = simde_mm_loadu_pd(test_vec[4].b);
  c = simde_x_mm_loadu_epi64(test_vec[4].c);
  r = simde_mm_mask_fixupimm_round_sd(a, test_vec[4].k, b, c, INT32_C(          54), INT32_C(           8));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[4].r), 1);

  a = simde_mm_loadu_pd(test_vec[5].a);
  b = simde_mm_loadu_pd(test_vec[5].b);
  c = simde_x_mm_loadu_epi64(test_vec[5].c);
  r = simde_mm_mask_fixupimm_round_sd(a, test_vec[5].k, b, c, INT32_C(         178), INT32_C(           4));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[5].r), 1);

  a = simde_mm_loadu_pd(test_vec[6].a);
  b = simde_mm_loadu_pd(test_vec[6].b);
  c = simde_x_mm_loadu_epi64(test_vec[6].c);
  r = simde_mm_mask_fixupimm_round_sd(a, test_vec[6].k, b, c, INT32_C(          42), INT32_C(           4));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[6].r), 1);

  a = simde_mm_loadu_pd(test_vec[7].a);
  b = simde_mm_loadu_pd(test_vec[7].b);
  c = simde_x_mm_loadu_epi64(test_vec[7].c);
  r = simde_mm_mask_fixupimm_round_sd(a, test_vec[7].k, b, c, INT32_C(          31), INT32_C(           8));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[7].r), 1);

  return 0;
#else
  fputc('\n', stdout);
  simde_float64 values[8 * 2 * sizeof(simde__m128d)];
  simde_test_x86_random_f64x2_full(8, 2, values, -1000.0, 1000.0, SIMDE_TEST_VEC_FLOAT_NAN);

  for (size_t i = 0 ; i < 8 ; i++) {
    simde__m128d a = simde_test_x86_random_extract_f64x2(i, 2, 0, values);
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m128d b = simde_test_x86_random_extract_f64x2(i, 2, 1, values);
    simde__m128i c = simde_test_x86_random_i64x2();
    int32_t imm8 = simde_test_codegen_random_i32() & 255;
    int32_t sae = simde_test_codegen_rand() & 1 ? SIMDE_MM_FROUND_NO_EXC : SIMDE_MM_FROUND_CUR_DIRECTION;
    simde__m128d r;
    SIMDE_CONSTIFY_256_NEW(simde_mm_mask_fixupimm_round_sd, r, simde_mm_setzero_pd(), imm8, sae, a, k, b, c);

    simde_test_x86_write_f64x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f64x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i64x2(2, c, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, imm8, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, sae, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_mm_maskz_fixupimm_round_sd (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    const simde__mmask8 k;
    const simde_float64 a[2];
    const simde_float64 b[2];
    const int64_t c[2];
    const int imm8;
    const int sae;
    const simde_float64 r[2];
  } test_vec[] = {
    { UINT8_C( 48),
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(  -177.10) },
      { SIMDE_FLOAT64_C(   528.84),             SIMDE_MATH_NAN },
      { -INT64_C( 6201633210150594401), -INT64_C(  573665116826378555) },
       INT32_C(          75),
       INT32_C(           4),
      { SIMDE_FLOAT64_C(     0.00),             SIMDE_MATH_NAN } },
    { UINT8_C(247),
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(  -228.85) },
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(  -796.90) },
      {  INT64_C( 5983593281465449366), -INT64_C( 7979780809577224146) },
       INT32_C(         200),
       INT32_C(           8),
      {        SIMDE_MATH_INFINITY, SIMDE_FLOAT64_C(  -796.90) } },
    { UINT8_C( 12),
      { SIMDE_FLOAT64_C(   953.39), SIMDE_FLOAT64_C(  -594.87) },
      { SIMDE_FLOAT64_C(   759.29), SIMDE_FLOAT64_C(  -333.77) },
      {  INT64_C( 1460268679395913021), -INT64_C(  501602774970017310) },
       INT32_C(          70),
       INT32_C(           4),
      { SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(  -333.77) } },
    { UINT8_C( 67),
      { SIMDE_FLOAT64_C(  -196.84), SIMDE_FLOAT64_C(   130.21) },
      { SIMDE_FLOAT64_C(  -305.90), SIMDE_FLOAT64_C(  -321.71) },
      {  INT64_C(  587512381103693072),  INT64_C( 3476593014681723983) },
       INT32_C(         106),
       INT32_C(           4),
      { SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(  -321.71) } },
    { UINT8_C(249),
      { SIMDE_FLOAT64_C(  -703.20), SIMDE_FLOAT64_C(   263.96) },
      { SIMDE_FLOAT64_C(    92.63), SIMDE_FLOAT64_C(  -639.53) },
      { -INT64_C( 8780730181033511444),  INT64_C( 3814065157984957655) },
       INT32_C(          81),
       INT32_C(           4),
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(  -639.53) } },
    { UINT8_C(134),
      { SIMDE_FLOAT64_C(  -499.89), SIMDE_FLOAT64_C(  -179.42) },
      { SIMDE_FLOAT64_C(   710.44), SIMDE_FLOAT64_C(  -137.29) },
      {  INT64_C( 2216264640608260444),  INT64_C(  306455746345938362) },
       INT32_C(          69),
       INT32_C(           4),
      { SIMDE_FLOAT64_C(     0.00), SIMDE_FLOAT64_C(  -137.29) } },
    { UINT8_C( 69),
      { SIMDE_FLOAT64_C(   696.58), SIMDE_FLOAT64_C(   275.21) },
      { SIMDE_FLOAT64_C(  -998.14), SIMDE_FLOAT64_C(   248.06) },
      { -INT64_C( 9166773650349969295), -INT64_C( 5976202023298587239) },
       INT32_C(          97),
       INT32_C(           4),
      {             SIMDE_MATH_NAN, SIMDE_FLOAT64_C(   248.06) } },
    { UINT8_C( 59),
      { SIMDE_FLOAT64_C(   678.73), SIMDE_FLOAT64_C(   700.41) },
      { SIMDE_FLOAT64_C(   774.71), SIMDE_FLOAT64_C(  -293.18) },
      { -INT64_C( 7934929338711951501), -INT64_C( 2429077280845114435) },
       INT32_C(         175),
       INT32_C(           4),
      { SIMDE_FLOAT64_C(     0.50), SIMDE_FLOAT64_C(  -293.18) } },
  };

  simde__m128d a, b, r;
  simde__m128i c;

  #if !defined(SIMDE_FAST_MATH)
  a = simde_mm_loadu_pd(test_vec[0].a);
  b = simde_mm_loadu_pd(test_vec[0].b);
  c = simde_x_mm_loadu_epi64(test_vec[0].c);
  r = simde_mm_maskz_fixupimm_round_sd(test_vec[0].k, a, b, c, INT32_C(          75), INT32_C(           4));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[0].r), 1);

  a = simde_mm_loadu_pd(test_vec[1].a);
  b = simde_mm_loadu_pd(test_vec[1].b);
  c = simde_x_mm_loadu_epi64(test_vec[1].c);
  r = simde_mm_maskz_fixupimm_round_sd(test_vec[1].k, a, b, c, INT32_C(         200), INT32_C(           8));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[1].r), 1);
  #endif

  a = simde_mm_loadu_pd(test_vec[2].a);
  b = simde_mm_loadu_pd(test_vec[2].b);
  c = simde_x_mm_loadu_epi64(test_vec[2].c);
  r = simde_mm_maskz_fixupimm_round_sd(test_vec[2].k, a, b, c, INT32_C(          70), INT32_C(           4));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[2].r), 1);

  a = simde_mm_loadu_pd(test_vec[3].a);
  b = simde_mm_loadu_pd(test_vec[3].b);
  c = simde_x_mm_loadu_epi64(test_vec[3].c);
  r = simde_mm_maskz_fixupimm_round_sd(test_vec[3].k, a, b, c, INT32_C(         106), INT32_C(           4));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[3].r), 1);

  #if !defined(SIMDE_FAST_MATH)
  a = simde_mm_loadu_pd(test_vec[4].a);
  b = simde_mm_loadu_pd(test_vec[4].b);
  c = simde_x_mm_loadu_epi64(test_vec[4].c);
  r = simde_mm_maskz_fixupimm_round_sd(test_vec[4].k, a, b, c, INT32_C(          81), INT32_C(           4));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[4].r), 1);
  #endif

  a = simde_mm_loadu_pd(test_vec[5].a);
  b = simde_mm_loadu_pd(test_vec[5].b);
  c = simde_x_mm_loadu_epi64(test_vec[5].c);
  r = simde_mm_maskz_fixupimm_round_sd(test_vec[5].k, a, b, c, INT32_C(          69), INT32_C(           4));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[5].r), 1);

  #if !defined(SIMDE_FAST_MATH)
  a = simde_mm_loadu_pd(test_vec[6].a);
  b = simde_mm_loadu_pd(test_vec[6].b);
  c = simde_x_mm_loadu_epi64(test_vec[6].c);
  r = simde_mm_maskz_fixupimm_round_sd(test_vec[6].k, a, b, c, INT32_C(          97), INT32_C(           4));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[6].r), 1);
  #endif

  a = simde_mm_loadu_pd(test_vec[7].a);
  b = simde_mm_loadu_pd(test_vec[7].b);
  c = simde_x_mm_loadu_epi64(test_vec[7].c);
  r = simde_mm_maskz_fixupimm_round_sd(test_vec[7].k, a, b, c, INT32_C(         175), INT32_C(           4));
  simde_test_x86_assert_equal_f64x2(r, simde_mm_loadu_pd(test_vec[7].r), 1);

  return 0;
#else
  fputc('\n', stdout);
  simde_float64 values[8 * 2 * sizeof(simde__m128d)];
  simde_test_x86_random_f64x2_full(8, 2, values, -1000.0, 1000.0, SIMDE_TEST_VEC_FLOAT_NAN);

  for (size_t i = 0 ; i < 8 ; i++) {
    simde__mmask8 k = simde_test_x86_random_mmask8();
    simde__m128d a = simde_test_x86_random_extract_f64x2(i, 2, 0, values);
    simde__m128d b = simde_test_x86_random_extract_f64x2(i, 2, 1, values);
    simde__m128i c = simde_test_x86_random_i64x2();
    int32_t imm8 = simde_test_codegen_random_i32() & 255;
    int32_t sae = simde_test_codegen_rand() & 1 ? SIMDE_MM_FROUND_NO_EXC : SIMDE_MM_FROUND_CUR_DIRECTION;
    simde__m128d r;
    SIMDE_CONSTIFY_256_NEW(simde_mm_maskz_fixupimm_round_sd, r, simde_mm_setzero_pd(), imm8, sae, k, a, b, c);

    simde_test_x86_write_mmask8(2, k, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_f64x2(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f64x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i64x2(2, c, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, imm8, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_codegen_write_i32(2, sae, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_f64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
  #if !defined(SIMDE_FAST_MATH)
    SIMDE_TEST_FUNC_LIST_ENTRY(mm512_fixupimm_round_ps)
  #endif
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_mask_fixupimm_round_ps)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_maskz_fixupimm_round_ps)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_fixupimm_round_pd)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_mask_fixupimm_round_pd)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_maskz_fixupimm_round_pd)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_fixupimm_round_ss)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_mask_fixupimm_round_ss)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_maskz_fixupimm_round_ss)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_fixupimm_round_sd)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_mask_fixupimm_round_sd)
  SIMDE_TEST_FUNC_LIST_ENTRY(mm_maskz_fixupimm_round_sd)
SIMDE_TEST_FUNC_LIST_END

#include <test/x86/avx512/test-avx512-footer.h>
