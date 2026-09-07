#include <arm_neon.h>
#include <stdarg.h>
#include <stdio.h>

typedef poly8_t simde_poly8;
typedef poly8_t simde_poly8_t;
typedef poly8x8_t simde_poly8x8_t;
typedef poly16_t simde_poly16_t;
typedef poly16x4_t simde_poly16x4_t;
typedef poly8x16_t simde_poly8x16_t;
typedef poly16x8_t simde_poly16x8_t;
typedef poly16_t simde_poly16;

static simde_poly8x8_t simde_vld1_p8(simde_poly8_t const ptr[]) {
  return vld1_p8(ptr);
}

static simde_poly8x8_t simde_vadd_p8(simde_poly8x8_t a, simde_poly8x8_t b) {
  return vadd_p8((a), (b));
}

static simde_poly16x4_t simde_vld1_p16(simde_poly16_t const ptr[]) {
  return vld1_p16(ptr);
}

static simde_poly16x4_t simde_vadd_p16(simde_poly16x4_t a, simde_poly16x4_t b) {
  return vadd_p16((a), (b));
}

static simde_poly8x16_t simde_vld1q_p8(simde_poly8_t const ptr[]) {
  return vld1q_p8(ptr);
}

static simde_poly8x16_t simde_vaddq_p8(simde_poly8x16_t a, simde_poly8x16_t b) {
  return vaddq_p8((a), (b));
}

static simde_poly16x8_t simde_vld1q_p16(simde_poly16_t const ptr[]) {
  return vld1q_p16(ptr);
}

static simde_poly16x8_t simde_vaddq_p16(simde_poly16x8_t a,
                                        simde_poly16x8_t b) {
  return vaddq_p16((a), (b));
}

static void simde_vst1_p8(simde_poly8_t ptr[], simde_poly8x8_t val) {
  vst1_p8((ptr), (val));
}

static void simde_vst1_p16(simde_poly16_t ptr[], simde_poly16x4_t val) {
  vst1_p16((ptr), (val));
}

static void simde_vst1q_p8(simde_poly8_t ptr[], simde_poly8x16_t val) {
  vst1q_p8((ptr), (val));
}

static void simde_vst1q_p16(simde_poly16_t ptr[], simde_poly16x8_t val) {
  vst1q_p16((ptr), (val));
}

static void simde_test_debug_printf_(const char *format, ...) {
  va_list ap;
  va_start(ap, format);
  vfprintf(stdout, format, ap);
  va_end(ap);
  fflush(stdout);
}

static int simde_assert_equal_vp16_(size_t vec_len, simde_poly16 const a[],
                                    simde_poly16 const b[],
                                    const char *filename, int line,
                                    const char *astr, const char *bstr) {
  for (size_t i = 0; i < vec_len; i++) {
    uint16_t a_ = ((uint16_t)(a[i]));
    uint16_t b_ = ((uint16_t)(b[i]));

    if ((!!(a_ != b_))) {
      simde_test_debug_printf_("%s:%d: assertion failed: %s[%zu] ~= %s[%zu] (%"
                               "hu"
                               " ~= %"
                               "hu"
                               ")\n",
                               filename, line, astr, i, bstr, i, a_, b_);
      return 1;
    }
  }
  return 0;
}

static int simde_assert_equal_vp8_(size_t vec_len, simde_poly8 const a[],
                                   simde_poly8 const b[], const char *filename,
                                   int line, const char *astr,
                                   const char *bstr) {
  for (size_t i = 0; i < vec_len; i++) {
    uint8_t a_ = ((uint8_t)(a[i]));
    uint8_t b_ = ((uint8_t)(b[i]));

    if ((!!(a_ != b_))) {
      simde_test_debug_printf_("%s:%d: assertion failed: %s[%zu] ~= %s[%zu] (%"
                               "hhu"
                               " ~= %"
                               "hhu"
                               ")\n",
                               filename, line, astr, i, bstr, i, a_, b_);
      return 1;
    }
  }
  return 0;
}

static int simde_test_arm_neon_assert_equal_p8x8_(simde_poly8x8_t a,
                                                  simde_poly8x8_t b,
                                                  const char *filename,
                                                  int line, const char *astr,
                                                  const char *bstr) {
  simde_poly8_t a_[sizeof(a) / sizeof(simde_poly8_t)],
      b_[sizeof(b) / sizeof(simde_poly8_t)];
  simde_vst1_p8(a_, a);
  simde_vst1_p8(b_, b);
  return simde_assert_equal_vp8_(8, a_, b_, filename, line, astr, bstr);
}

static int simde_test_arm_neon_assert_equal_p16x4_(simde_poly16x4_t a,
                                                   simde_poly16x4_t b,
                                                   const char *filename,
                                                   int line, const char *astr,
                                                   const char *bstr) {
  simde_poly16_t a_[sizeof(a) / sizeof(simde_poly16_t)],
      b_[sizeof(b) / sizeof(simde_poly16_t)];
  simde_vst1_p16(a_, a);
  simde_vst1_p16(b_, b);
  return simde_assert_equal_vp16_(4, a_, b_, filename, line, astr, bstr);
}

static int test_simde_vadd_p8(void) {

  struct {
    simde_poly8_t a[8];
    simde_poly8_t b[8];
    simde_poly8_t r[8];
  } test_vec[] = {
      {{(((poly8_t)(33))), (((poly8_t)(89))), (((poly8_t)(65))),
        (((poly8_t)(UINT8_MAX))), (((poly8_t)(235))), (((poly8_t)(192))),
        (((poly8_t)(0))), (((poly8_t)(73)))},
       {(((poly8_t)(25))), (((poly8_t)(94))), (((poly8_t)(232))),
        (((poly8_t)(201))), (((poly8_t)(180))), (((poly8_t)(81))),
        (((poly8_t)(101))), (((poly8_t)(20)))},
       {(((poly8_t)(56))), (((poly8_t)(7))), (((poly8_t)(169))),
        (((poly8_t)(54))), (((poly8_t)(95))), (((poly8_t)(145))),
        (((poly8_t)(101))), (((poly8_t)(93)))}},
      {{(((poly8_t)(203))), (((poly8_t)(54))), (((poly8_t)(37))),
        (((poly8_t)(215))), (((poly8_t)(48))), (((poly8_t)(49))),
        (((poly8_t)(215))), (((poly8_t)(125)))},
       {(((poly8_t)(86))), (((poly8_t)(18))), (((poly8_t)(157))),
        (((poly8_t)(162))), (((poly8_t)(142))), (((poly8_t)(137))),
        (((poly8_t)(65))), (((poly8_t)(82)))},
       {(((poly8_t)(157))), (((poly8_t)(36))), (((poly8_t)(184))),
        (((poly8_t)(117))), (((poly8_t)(190))), (((poly8_t)(184))),
        (((poly8_t)(150))), (((poly8_t)(47)))}},
      {{(((poly8_t)(21))), (((poly8_t)(187))), (((poly8_t)(38))),
        (((poly8_t)(44))), (((poly8_t)(244))), (((poly8_t)(227))),
        (((poly8_t)(41))), (((poly8_t)(143)))},
       {(((poly8_t)(26))), (((poly8_t)(49))), (((poly8_t)(21))),
        (((poly8_t)(51))), (((poly8_t)(62))), (((poly8_t)(89))),
        (((poly8_t)(239))), (((poly8_t)(245)))},
       {(((poly8_t)(15))), (((poly8_t)(138))), (((poly8_t)(51))),
        (((poly8_t)(31))), (((poly8_t)(202))), (((poly8_t)(186))),
        (((poly8_t)(198))), (((poly8_t)(122)))}},
      {{(((poly8_t)(220))), (((poly8_t)(69))), (((poly8_t)(146))),
        (((poly8_t)(98))), (((poly8_t)(93))), (((poly8_t)(157))),
        (((poly8_t)(43))), (((poly8_t)(3)))},
       {(((poly8_t)(15))), (((poly8_t)(164))), (((poly8_t)(145))),
        (((poly8_t)(17))), (((poly8_t)(79))), (((poly8_t)(184))),
        (((poly8_t)(183))), (((poly8_t)(248)))},
       {(((poly8_t)(211))), (((poly8_t)(225))), (((poly8_t)(3))),
        (((poly8_t)(115))), (((poly8_t)(18))), (((poly8_t)(37))),
        (((poly8_t)(156))), (((poly8_t)(251)))}},
      {{(((poly8_t)(242))), (((poly8_t)(176))), (((poly8_t)(43))),
        (((poly8_t)(252))), (((poly8_t)(83))), (((poly8_t)(192))),
        (((poly8_t)(10))), (((poly8_t)(94)))},
       {(((poly8_t)(164))), (((poly8_t)(37))), (((poly8_t)(28))),
        (((poly8_t)(125))), (((poly8_t)(83))), (((poly8_t)(113))),
        (((poly8_t)(53))), (((poly8_t)(107)))},
       {(((poly8_t)(86))), (((poly8_t)(149))), (((poly8_t)(55))),
        (((poly8_t)(129))), (((poly8_t)(0))), (((poly8_t)(177))),
        (((poly8_t)(63))), (((poly8_t)(53)))}},
      {{(((poly8_t)(160))), (((poly8_t)(56))), (((poly8_t)(3))),
        (((poly8_t)(140))), (((poly8_t)(203))), (((poly8_t)(118))),
        (((poly8_t)(12))), (((poly8_t)(161)))},
       {(((poly8_t)(143))), (((poly8_t)(147))), (((poly8_t)(86))),
        (((poly8_t)(58))), (((poly8_t)(18))), (((poly8_t)(43))),
        (((poly8_t)(207))), (((poly8_t)(59)))},
       {(((poly8_t)(47))), (((poly8_t)(171))), (((poly8_t)(85))),
        (((poly8_t)(182))), (((poly8_t)(217))), (((poly8_t)(93))),
        (((poly8_t)(195))), (((poly8_t)(154)))}},
      {{(((poly8_t)(254))), (((poly8_t)(216))), (((poly8_t)(73))),
        (((poly8_t)(92))), (((poly8_t)(97))), (((poly8_t)(150))),
        (((poly8_t)(94))), (((poly8_t)(23)))},
       {(((poly8_t)(163))), (((poly8_t)(109))), (((poly8_t)(74))),
        (((poly8_t)(17))), (((poly8_t)(191))), (((poly8_t)(61))),
        (((poly8_t)(103))), (((poly8_t)(222)))},
       {(((poly8_t)(93))), (((poly8_t)(181))), (((poly8_t)(3))),
        (((poly8_t)(77))), (((poly8_t)(222))), (((poly8_t)(171))),
        (((poly8_t)(57))), (((poly8_t)(201)))}},
      {{(((poly8_t)(123))), (((poly8_t)(246))), (((poly8_t)(196))),
        (((poly8_t)(141))), (((poly8_t)(19))), (((poly8_t)(187))),
        (((poly8_t)(73))), (((poly8_t)(60)))},
       {(((poly8_t)(198))), (((poly8_t)(47))), (((poly8_t)(111))),
        (((poly8_t)(219))), (((poly8_t)(25))), (((poly8_t)(76))),
        (((poly8_t)(209))), (((poly8_t)(241)))},
       {(((poly8_t)(189))), (((poly8_t)(217))), (((poly8_t)(171))),
        (((poly8_t)(86))), (((poly8_t)(10))), (((poly8_t)(247))),
        (((poly8_t)(152))), (((poly8_t)(205)))}},
  };

  for (size_t i = 0; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_poly8x8_t a = simde_vld1_p8(test_vec[i].a);
    simde_poly8x8_t b = simde_vld1_p8(test_vec[i].b);
    simde_poly8x8_t r = simde_vadd_p8(a, b);

    do {
      if (simde_test_arm_neon_assert_equal_p8x8_(
              r, simde_vld1_p8(test_vec[i].r), "../test/arm/neon/add.c", 98,
              "r", "simde_vld1_p8(test_vec[i].r)")) {
        return 1;
      }
    } while (0);
  }

  return 0;
}

static int simde_test_arm_neon_assert_equal_p8x16_(simde_poly8x16_t a,
                                                   simde_poly8x16_t b,
                                                   const char *filename,
                                                   int line, const char *astr,
                                                   const char *bstr) {
  simde_poly8_t a_[sizeof(a) / sizeof(simde_poly8_t)],
      b_[sizeof(b) / sizeof(simde_poly8_t)];
  simde_vst1q_p8(a_, a);
  simde_vst1q_p8(b_, b);
  return simde_assert_equal_vp8_(16, a_, b_, filename, line, astr, bstr);
}

static int simde_test_arm_neon_assert_equal_p16x8_(simde_poly16x8_t a,
                                                   simde_poly16x8_t b,
                                                   const char *filename,
                                                   int line, const char *astr,
                                                   const char *bstr) {
  simde_poly16_t a_[sizeof(a) / sizeof(simde_poly16_t)],
      b_[sizeof(b) / sizeof(simde_poly16_t)];
  simde_vst1q_p16(a_, a);
  simde_vst1q_p16(b_, b);
  return simde_assert_equal_vp16_(8, a_, b_, filename, line, astr, bstr);
}

static int test_simde_vadd_p16(void) {

  struct {
    simde_poly16_t a[4];
    simde_poly16_t b[4];
    simde_poly16_t r[4];
  } test_vec[] = {
      {{(((poly16_t)(44848))), (((poly16_t)(25263))), (((poly16_t)(56185))),
        (((poly16_t)(46842)))},
       {(((poly16_t)(44027))), (((poly16_t)(18055))), (((poly16_t)(46799))),
        (((poly16_t)(11694)))},
       {(((poly16_t)(1227))), (((poly16_t)(9256))), (((poly16_t)(28086))),
        (((poly16_t)(39764)))}},
      {{(((poly16_t)(8719))), (((poly16_t)(48304))), (((poly16_t)(50563))),
        (((poly16_t)(33590)))},
       {(((poly16_t)(60253))), (((poly16_t)(9950))), (((poly16_t)(7334))),
        (((poly16_t)(1265)))},
       {(((poly16_t)(51538))), (((poly16_t)(39534))), (((poly16_t)(55589))),
        (((poly16_t)(34759)))}},
      {{(((poly16_t)(2519))), (((poly16_t)(32880))), (((poly16_t)(38511))),
        (((poly16_t)(13749)))},
       {(((poly16_t)(5160))), (((poly16_t)(5666))), (((poly16_t)(41636))),
        (((poly16_t)(48481)))},
       {(((poly16_t)(7679))), (((poly16_t)(38482))), (((poly16_t)(13515))),
        (((poly16_t)(35028)))}},
      {{(((poly16_t)(50014))), (((poly16_t)(24511))), (((poly16_t)(50497))),
        (((poly16_t)(7370)))},
       {(((poly16_t)(38152))), (((poly16_t)(23612))), (((poly16_t)(5758))),
        (((poly16_t)(53290)))},
       {(((poly16_t)(22102))), (((poly16_t)(899))), (((poly16_t)(54079))),
        (((poly16_t)(52448)))}},
      {{(((poly16_t)(18670))), (((poly16_t)(22782))), (((poly16_t)(17120))),
        (((poly16_t)(154)))},
       {(((poly16_t)(22181))), (((poly16_t)(26233))), (((poly16_t)(26407))),
        (((poly16_t)(43106)))},
       {(((poly16_t)(7755))), (((poly16_t)(16007))), (((poly16_t)(9671))),
        (((poly16_t)(43256)))}},
      {{(((poly16_t)(59179))), (((poly16_t)(13001))), (((poly16_t)(20645))),
        (((poly16_t)(16746)))},
       {(((poly16_t)(51036))), (((poly16_t)(1807))), (((poly16_t)(20983))),
        (((poly16_t)(12864)))},
       {(((poly16_t)(8311))), (((poly16_t)(13766))), (((poly16_t)(338))),
        (((poly16_t)(29482)))}},
      {{(((poly16_t)(31092))), (((poly16_t)(3280))), (((poly16_t)(57691))),
        (((poly16_t)(47474)))},
       {(((poly16_t)(10673))), (((poly16_t)(45266))), (((poly16_t)(22429))),
        (((poly16_t)(982)))},
       {(((poly16_t)(20677))), (((poly16_t)(48130))), (((poly16_t)(46790))),
        (((poly16_t)(47780)))}},
      {{(((poly16_t)(4312))), (((poly16_t)(27352))), (((poly16_t)(38240))),
        (((poly16_t)(43915)))},
       {(((poly16_t)(33894))), (((poly16_t)(36255))), (((poly16_t)(63975))),
        (((poly16_t)(29690)))},
       {(((poly16_t)(38078))), (((poly16_t)(59207))), (((poly16_t)(27783))),
        (((poly16_t)(55409)))}},
  };

  for (size_t i = 0; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_poly16x4_t a = simde_vld1_p16(test_vec[i].a);
    simde_poly16x4_t b = simde_vld1_p16(test_vec[i].b);
    simde_poly16x4_t r = simde_vadd_p16(a, b);

    do {
      if (simde_test_arm_neon_assert_equal_p16x4_(
              r, simde_vld1_p16(test_vec[i].r), "../test/arm/neon/add.c", 157,
              "r", "simde_vld1_p16(test_vec[i].r)")) {
        return 1;
      }
    } while (0);
  }

  return 0;
}

static int test_simde_vaddq_p8(void) {

  struct {
    simde_poly8_t a[16];
    simde_poly8_t b[16];
    simde_poly8_t r[16];
  } test_vec[] = {
      {{(((poly8_t)(183))), (((poly8_t)(135))), (((poly8_t)(110))),
        (((poly8_t)(124))), (((poly8_t)(225))), (((poly8_t)(5))),
        (((poly8_t)(160))), (((poly8_t)(204))), (((poly8_t)(245))),
        (((poly8_t)(117))), (((poly8_t)(197))), (((poly8_t)(253))),
        (((poly8_t)(126))), (((poly8_t)(228))), (((poly8_t)(66))),
        (((poly8_t)(129)))},
       {(((poly8_t)(114))), (((poly8_t)(189))), (((poly8_t)(15))),
        (((poly8_t)(245))), (((poly8_t)(224))), (((poly8_t)(15))),
        (((poly8_t)(78))), (((poly8_t)(192))), (((poly8_t)(225))),
        (((poly8_t)(118))), (((poly8_t)(151))), (((poly8_t)(125))),
        (((poly8_t)(89))), (((poly8_t)(102))), (((poly8_t)(211))),
        (((poly8_t)(139)))},
       {(((poly8_t)(197))), (((poly8_t)(58))), (((poly8_t)(97))),
        (((poly8_t)(137))), (((poly8_t)(1))), (((poly8_t)(10))),
        (((poly8_t)(238))), (((poly8_t)(12))), (((poly8_t)(20))),
        (((poly8_t)(3))), (((poly8_t)(82))), (((poly8_t)(128))),
        (((poly8_t)(39))), (((poly8_t)(130))), (((poly8_t)(145))),
        (((poly8_t)(10)))}},
      {{(((poly8_t)(134))), (((poly8_t)(58))), (((poly8_t)(144))),
        (((poly8_t)(25))), (((poly8_t)(2))), (((poly8_t)(121))),
        (((poly8_t)(33))), (((poly8_t)(156))), (((poly8_t)(174))),
        (((poly8_t)(122))), (((poly8_t)(136))), (((poly8_t)(115))),
        (((poly8_t)(193))), (((poly8_t)(100))), (((poly8_t)(111))),
        (((poly8_t)(242)))},
       {(((poly8_t)(119))), (((poly8_t)(31))), (((poly8_t)(72))),
        (((poly8_t)(61))), (((poly8_t)(214))), (((poly8_t)(42))),
        (((poly8_t)(121))), (((poly8_t)(230))), (((poly8_t)(81))),
        (((poly8_t)(108))), (((poly8_t)(95))), (((poly8_t)(51))),
        (((poly8_t)(169))), (((poly8_t)(238))), (((poly8_t)(74))),
        (((poly8_t)(2)))},
       {(((poly8_t)(241))), (((poly8_t)(37))), (((poly8_t)(216))),
        (((poly8_t)(36))), (((poly8_t)(212))), (((poly8_t)(83))),
        (((poly8_t)(88))), (((poly8_t)(122))), (((poly8_t)(UINT8_MAX))),
        (((poly8_t)(22))), (((poly8_t)(215))), (((poly8_t)(64))),
        (((poly8_t)(104))), (((poly8_t)(138))), (((poly8_t)(37))),
        (((poly8_t)(240)))}},
      {{(((poly8_t)(226))), (((poly8_t)(177))), (((poly8_t)(249))),
        (((poly8_t)(120))), (((poly8_t)(247))), (((poly8_t)(21))),
        (((poly8_t)(122))), (((poly8_t)(178))), (((poly8_t)(88))),
        (((poly8_t)(123))), (((poly8_t)(170))), (((poly8_t)(163))),
        (((poly8_t)(52))), (((poly8_t)(202))), (((poly8_t)(64))),
        (((poly8_t)(89)))},
       {(((poly8_t)(150))), (((poly8_t)(155))), (((poly8_t)(150))),
        (((poly8_t)(164))), (((poly8_t)(195))), (((poly8_t)(220))),
        (((poly8_t)(131))), (((poly8_t)(166))), (((poly8_t)(103))),
        (((poly8_t)(60))), (((poly8_t)(53))), (((poly8_t)(207))),
        (((poly8_t)(154))), (((poly8_t)(86))), (((poly8_t)(136))),
        (((poly8_t)(165)))},
       {(((poly8_t)(116))), (((poly8_t)(42))), (((poly8_t)(111))),
        (((poly8_t)(220))), (((poly8_t)(52))), (((poly8_t)(201))),
        (((poly8_t)(249))), (((poly8_t)(20))), (((poly8_t)(63))),
        (((poly8_t)(71))), (((poly8_t)(159))), (((poly8_t)(108))),
        (((poly8_t)(174))), (((poly8_t)(156))), (((poly8_t)(200))),
        (((poly8_t)(252)))}},
      {{(((poly8_t)(152))), (((poly8_t)(82))), (((poly8_t)(253))),
        (((poly8_t)(41))), (((poly8_t)(184))), (((poly8_t)(68))),
        (((poly8_t)(145))), (((poly8_t)(63))), (((poly8_t)(227))),
        (((poly8_t)(104))), (((poly8_t)(58))), (((poly8_t)(82))),
        (((poly8_t)(151))), (((poly8_t)(47))), (((poly8_t)(253))),
        (((poly8_t)(159)))},
       {(((poly8_t)(139))), (((poly8_t)(114))), (((poly8_t)(164))),
        (((poly8_t)(224))), (((poly8_t)(14))), (((poly8_t)(94))),
        (((poly8_t)(190))), (((poly8_t)(125))), (((poly8_t)(56))),
        (((poly8_t)(102))), (((poly8_t)(251))), (((poly8_t)(198))),
        (((poly8_t)(206))), (((poly8_t)(147))), (((poly8_t)(232))),
        (((poly8_t)(30)))},
       {(((poly8_t)(19))), (((poly8_t)(32))), (((poly8_t)(89))),
        (((poly8_t)(201))), (((poly8_t)(182))), (((poly8_t)(26))),
        (((poly8_t)(47))), (((poly8_t)(66))), (((poly8_t)(219))),
        (((poly8_t)(14))), (((poly8_t)(193))), (((poly8_t)(148))),
        (((poly8_t)(89))), (((poly8_t)(188))), (((poly8_t)(21))),
        (((poly8_t)(129)))}},
      {{(((poly8_t)(76))), (((poly8_t)(14))), (((poly8_t)(145))),
        (((poly8_t)(56))), (((poly8_t)(227))), (((poly8_t)(143))),
        (((poly8_t)(170))), (((poly8_t)(207))), (((poly8_t)(100))),
        (((poly8_t)(181))), (((poly8_t)(157))), (((poly8_t)(196))),
        (((poly8_t)(243))), (((poly8_t)(196))), (((poly8_t)(232))),
        (((poly8_t)(24)))},
       {(((poly8_t)(17))), (((poly8_t)(179))), (((poly8_t)(80))),
        (((poly8_t)(20))), (((poly8_t)(75))), (((poly8_t)(83))),
        (((poly8_t)(86))), (((poly8_t)(177))), (((poly8_t)(156))),
        (((poly8_t)(204))), (((poly8_t)(101))), (((poly8_t)(83))),
        (((poly8_t)(253))), (((poly8_t)(159))), (((poly8_t)(207))),
        (((poly8_t)(194)))},
       {(((poly8_t)(93))), (((poly8_t)(189))), (((poly8_t)(193))),
        (((poly8_t)(44))), (((poly8_t)(168))), (((poly8_t)(220))),
        (((poly8_t)(252))), (((poly8_t)(126))), (((poly8_t)(248))),
        (((poly8_t)(121))), (((poly8_t)(248))), (((poly8_t)(151))),
        (((poly8_t)(14))), (((poly8_t)(91))), (((poly8_t)(39))),
        (((poly8_t)(218)))}},
      {{(((poly8_t)(67))), (((poly8_t)(237))), (((poly8_t)(135))),
        (((poly8_t)(108))), (((poly8_t)(113))), (((poly8_t)(245))),
        (((poly8_t)(81))), (((poly8_t)(167))), (((poly8_t)(51))),
        (((poly8_t)(62))), (((poly8_t)(120))), (((poly8_t)(93))),
        (((poly8_t)(209))), (((poly8_t)(219))), (((poly8_t)(165))),
        (((poly8_t)(180)))},
       {(((poly8_t)(126))), (((poly8_t)(180))), (((poly8_t)(202))),
        (((poly8_t)(28))), (((poly8_t)(150))), (((poly8_t)(60))),
        (((poly8_t)(141))), (((poly8_t)(131))), (((poly8_t)(219))),
        (((poly8_t)(8))), (((poly8_t)(187))), (((poly8_t)(217))),
        (((poly8_t)(139))), (((poly8_t)(209))), (((poly8_t)(210))),
        (((poly8_t)(129)))},
       {(((poly8_t)(61))), (((poly8_t)(89))), (((poly8_t)(77))),
        (((poly8_t)(112))), (((poly8_t)(231))), (((poly8_t)(201))),
        (((poly8_t)(220))), (((poly8_t)(36))), (((poly8_t)(232))),
        (((poly8_t)(54))), (((poly8_t)(195))), (((poly8_t)(132))),
        (((poly8_t)(90))), (((poly8_t)(10))), (((poly8_t)(119))),
        (((poly8_t)(53)))}},
      {{(((poly8_t)(107))), (((poly8_t)(204))), (((poly8_t)(116))),
        (((poly8_t)(184))), (((poly8_t)(201))), (((poly8_t)(38))),
        (((poly8_t)(48))), (((poly8_t)(21))), (((poly8_t)(249))),
        (((poly8_t)(40))), (((poly8_t)(15))), (((poly8_t)(40))),
        (((poly8_t)(194))), (((poly8_t)(98))), (((poly8_t)(66))),
        (((poly8_t)(87)))},
       {(((poly8_t)(116))), (((poly8_t)(160))), (((poly8_t)(184))),
        (((poly8_t)(140))), (((poly8_t)(245))), (((poly8_t)(116))),
        (((poly8_t)(248))), (((poly8_t)(28))), (((poly8_t)(229))),
        (((poly8_t)(103))), (((poly8_t)(171))), (((poly8_t)(21))),
        (((poly8_t)(155))), (((poly8_t)(8))), (((poly8_t)(20))),
        (((poly8_t)(78)))},
       {(((poly8_t)(31))), (((poly8_t)(108))), (((poly8_t)(204))),
        (((poly8_t)(52))), (((poly8_t)(60))), (((poly8_t)(82))),
        (((poly8_t)(200))), (((poly8_t)(9))), (((poly8_t)(28))),
        (((poly8_t)(79))), (((poly8_t)(164))), (((poly8_t)(61))),
        (((poly8_t)(89))), (((poly8_t)(106))), (((poly8_t)(86))),
        (((poly8_t)(25)))}},
      {{(((poly8_t)(232))), (((poly8_t)(223))), (((poly8_t)(159))),
        (((poly8_t)(209))), (((poly8_t)(5))), (((poly8_t)(217))),
        (((poly8_t)(123))), (((poly8_t)(236))), (((poly8_t)(111))),
        (((poly8_t)(90))), (((poly8_t)(147))), (((poly8_t)(137))),
        (((poly8_t)(213))), (((poly8_t)(252))), (((poly8_t)(94))),
        (((poly8_t)(55)))},
       {(((poly8_t)(104))), (((poly8_t)(232))), (((poly8_t)(62))),
        (((poly8_t)(153))), (((poly8_t)(211))), (((poly8_t)(147))),
        (((poly8_t)(128))), (((poly8_t)(39))), (((poly8_t)(118))),
        (((poly8_t)(183))), (((poly8_t)(196))), (((poly8_t)(140))),
        (((poly8_t)(213))), (((poly8_t)(180))), (((poly8_t)(247))),
        (((poly8_t)(120)))},
       {(((poly8_t)(128))), (((poly8_t)(55))), (((poly8_t)(161))),
        (((poly8_t)(72))), (((poly8_t)(214))), (((poly8_t)(74))),
        (((poly8_t)(251))), (((poly8_t)(203))), (((poly8_t)(25))),
        (((poly8_t)(237))), (((poly8_t)(87))), (((poly8_t)(5))),
        (((poly8_t)(0))), (((poly8_t)(72))), (((poly8_t)(169))),
        (((poly8_t)(79)))}},
  };

  for (size_t i = 0; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_poly8x16_t a = simde_vld1q_p8(test_vec[i].a);
    simde_poly8x16_t b = simde_vld1q_p8(test_vec[i].b);
    simde_poly8x16_t r = simde_vaddq_p8(a, b);

    do {
      if (simde_test_arm_neon_assert_equal_p8x16_(
              r, simde_vld1q_p8(test_vec[i].r), "../test/arm/neon/add.c", 288,
              "r", "simde_vld1q_p8(test_vec[i].r)")) {
        return 1;
      }
    } while (0);
  }

  return 0;
}

static int test_simde_vaddq_p16(void) {

  struct {
    simde_poly16_t a[8];
    simde_poly16_t b[8];
    simde_poly16_t r[8];
  } test_vec[] = {
      {{(((poly16_t)(17947))), (((poly16_t)(59627))), (((poly16_t)(13747))),
        (((poly16_t)(60214))), (((poly16_t)(25527))), (((poly16_t)(22465))),
        (((poly16_t)(31008))), (((poly16_t)(55276)))},
       {(((poly16_t)(12643))), (((poly16_t)(57634))), (((poly16_t)(10112))),
        (((poly16_t)(31417))), (((poly16_t)(43720))), (((poly16_t)(57721))),
        (((poly16_t)(6164))), (((poly16_t)(3722)))},
       {(((poly16_t)(30584))), (((poly16_t)(2505))), (((poly16_t)(4659))),
        (((poly16_t)(37263))), (((poly16_t)(51583))), (((poly16_t)(46776))),
        (((poly16_t)(24884))), (((poly16_t)(55654)))}},
      {{(((poly16_t)(25610))), (((poly16_t)(33945))), (((poly16_t)(65012))),
        (((poly16_t)(27880))), (((poly16_t)(48429))), (((poly16_t)(44309))),
        (((poly16_t)(7727))), (((poly16_t)(18394)))},
       {(((poly16_t)(4010))), (((poly16_t)(19605))), (((poly16_t)(646))),
        (((poly16_t)(6945))), (((poly16_t)(24159))), (((poly16_t)(5559))),
        (((poly16_t)(15091))), (((poly16_t)(4641)))},
       {(((poly16_t)(27552))), (((poly16_t)(51212))), (((poly16_t)(65394))),
        (((poly16_t)(30665))), (((poly16_t)(58226))), (((poly16_t)(47266))),
        (((poly16_t)(9436))), (((poly16_t)(22011)))}},
      {{(((poly16_t)(60692))), (((poly16_t)(33785))), (((poly16_t)(19384))),
        (((poly16_t)(14821))), (((poly16_t)(40380))), (((poly16_t)(19087))),
        (((poly16_t)(8114))), (((poly16_t)(36709)))},
       {(((poly16_t)(36514))), (((poly16_t)(33408))), (((poly16_t)(63224))),
        (((poly16_t)(29645))), (((poly16_t)(15041))), (((poly16_t)(36757))),
        (((poly16_t)(42027))), (((poly16_t)(36016)))},
       {(((poly16_t)(25526))), (((poly16_t)(377))), (((poly16_t)(48448))),
        (((poly16_t)(18984))), (((poly16_t)(42877))), (((poly16_t)(50458))),
        (((poly16_t)(48025))), (((poly16_t)(981)))}},
      {{(((poly16_t)(18141))), (((poly16_t)(45065))), (((poly16_t)(60606))),
        (((poly16_t)(11849))), (((poly16_t)(46718))), (((poly16_t)(3530))),
        (((poly16_t)(42939))), (((poly16_t)(55698)))},
       {(((poly16_t)(44681))), (((poly16_t)(12139))), (((poly16_t)(52114))),
        (((poly16_t)(21680))), (((poly16_t)(44059))), (((poly16_t)(27972))),
        (((poly16_t)(7574))), (((poly16_t)(15409)))},
       {(((poly16_t)(59476))), (((poly16_t)(40802))), (((poly16_t)(10028))),
        (((poly16_t)(31481))), (((poly16_t)(6757))), (((poly16_t)(24718))),
        (((poly16_t)(47661))), (((poly16_t)(58787)))}},
      {{(((poly16_t)(57331))), (((poly16_t)(62493))), (((poly16_t)(2414))),
        (((poly16_t)(51609))), (((poly16_t)(56885))), (((poly16_t)(15440))),
        (((poly16_t)(30921))), (((poly16_t)(57628)))},
       {(((poly16_t)(55460))), (((poly16_t)(62933))), (((poly16_t)(30562))),
        (((poly16_t)(64038))), (((poly16_t)(17558))), (((poly16_t)(4700))),
        (((poly16_t)(4199))), (((poly16_t)(48364)))},
       {(((poly16_t)(1879))), (((poly16_t)(456))), (((poly16_t)(32268))),
        (((poly16_t)(13247))), (((poly16_t)(39587))), (((poly16_t)(11788))),
        (((poly16_t)(26798))), (((poly16_t)(24048)))}},
      {{(((poly16_t)(1786))), (((poly16_t)(24136))), (((poly16_t)(32584))),
        (((poly16_t)(43856))), (((poly16_t)(38344))), (((poly16_t)(50712))),
        (((poly16_t)(34231))), (((poly16_t)(25688)))},
       {(((poly16_t)(49017))), (((poly16_t)(9948))), (((poly16_t)(18165))),
        (((poly16_t)(13402))), (((poly16_t)(58881))), (((poly16_t)(3005))),
        (((poly16_t)(11265))), (((poly16_t)(52715)))},
       {(((poly16_t)(47491))), (((poly16_t)(30868))), (((poly16_t)(14781))),
        (((poly16_t)(40714))), (((poly16_t)(29641))), (((poly16_t)(52645))),
        (((poly16_t)(43446))), (((poly16_t)(43443)))}},
      {{(((poly16_t)(36514))), (((poly16_t)(40641))), (((poly16_t)(48435))),
        (((poly16_t)(64823))), (((poly16_t)(28799))), (((poly16_t)(23113))),
        (((poly16_t)(15829))), (((poly16_t)(57863)))},
       {(((poly16_t)(57839))), (((poly16_t)(56275))), (((poly16_t)(27049))),
        (((poly16_t)(15419))), (((poly16_t)(6369))), (((poly16_t)(64017))),
        (((poly16_t)(14409))), (((poly16_t)(65103)))},
       {(((poly16_t)(28493))), (((poly16_t)(17682))), (((poly16_t)(54426))),
        (((poly16_t)(49420))), (((poly16_t)(26782))), (((poly16_t)(41048))),
        (((poly16_t)(1436))), (((poly16_t)(7240)))}},
      {{(((poly16_t)(37116))), (((poly16_t)(54232))), (((poly16_t)(8172))),
        (((poly16_t)(65515))), (((poly16_t)(19328))), (((poly16_t)(45577))),
        (((poly16_t)(49944))), (((poly16_t)(63864)))},
       {(((poly16_t)(31664))), (((poly16_t)(53471))), (((poly16_t)(46798))),
        (((poly16_t)(32140))), (((poly16_t)(22511))), (((poly16_t)(18434))),
        (((poly16_t)(35100))), (((poly16_t)(22561)))},
       {(((poly16_t)(60236))), (((poly16_t)(775))), (((poly16_t)(43298))),
        (((poly16_t)(33383))), (((poly16_t)(7279))), (((poly16_t)(64011))),
        (((poly16_t)(18948))), (((poly16_t)(41305)))}},
  };

  for (size_t i = 0; i < (sizeof(test_vec) / sizeof(test_vec[0])); i++) {
    simde_poly16x8_t a = simde_vld1q_p16(test_vec[i].a);
    simde_poly16x8_t b = simde_vld1q_p16(test_vec[i].b);
    simde_poly16x8_t r = simde_vaddq_p16(a, b);

    do {
      if (simde_test_arm_neon_assert_equal_p16x8_(
              r, simde_vld1q_p16(test_vec[i].r), "../test/arm/neon/add.c", 371,
              "r", "simde_vld1q_p16(test_vec[i].r)")) {
        return 1;
      }
    } while (0);
  }

  return 0;
}

static const struct {
  int (*func)(void);
  const char *name;
} test_suite_tests[] = {
    {test_simde_vadd_p8, "vadd_p8"},
    {test_simde_vadd_p16, "vadd_p16"},
    {test_simde_vaddq_p8, "vaddq_p8"},
    {test_simde_vaddq_p16, "vaddq_p16"},
};

int main(void) {
  int retval = 0;

  fprintf(stdout, "1..%zu\n",
          (sizeof(test_suite_tests) / sizeof(test_suite_tests[0])));
  for (size_t i = 0;
       i < (sizeof(test_suite_tests) / sizeof(test_suite_tests[0])); i++) {
    int res = test_suite_tests[i].func();
    if (res != 0) {
      retval = 1;
      fprintf(stdout,
              "not ok %zu "
              "add"
              "/%s\n",
              i + 1, test_suite_tests[i].name);
    } else {
      fprintf(stdout,
              "ok %zu "
              "add"
              "/%s\n",
              i + 1, test_suite_tests[i].name);
    }
  }

  return retval;
}
