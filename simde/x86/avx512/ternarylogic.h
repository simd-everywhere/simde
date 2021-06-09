#if !defined(SIMDE_X86_AVX512_TERNARYLOGIC_H)
#define SIMDE_X86_AVX512_TERNARYLOGIC_H

#include "types.h"
#include "movm.h"

HEDLEY_DIAGNOSTIC_PUSH
SIMDE_DISABLE_UNWANTED_DIAGNOSTICS
SIMDE_BEGIN_DECLS_

SIMDE_FUNCTION_ATTRIBUTES
uint_fast32_t
simde_x_ternarylogic_0x00_impl_(uint_fast32_t a, uint_fast32_t b, uint_fast32_t c) {
  HEDLEY_STATIC_CAST(void, a);
  HEDLEY_STATIC_CAST(void, b);
  HEDLEY_STATIC_CAST(void, c);
  const uint_fast32_t c0 = 0;
  return c0;
}

SIMDE_FUNCTION_ATTRIBUTES
uint_fast32_t
simde_x_ternarylogic_0x01_impl_(uint_fast32_t a, uint_fast32_t b, uint_fast32_t c) {
  const uint_fast32_t t0 = b | c;
  const uint_fast32_t t1 = a | t0;
  const uint_fast32_t t2 = ~t1;
  return t2;
}

SIMDE_FUNCTION_ATTRIBUTES
uint_fast32_t
simde_x_ternarylogic_0x02_impl_(uint_fast32_t a, uint_fast32_t b, uint_fast32_t c) {
  const uint_fast32_t t0 = b | a;
  const uint_fast32_t t1 = ~t0;
  const uint_fast32_t t2 = c & t1;
  return t2;
}

SIMDE_FUNCTION_ATTRIBUTES
uint_fast32_t
simde_x_ternarylogic_0x03_impl_(uint_fast32_t a, uint_fast32_t b, uint_fast32_t c) {
  HEDLEY_STATIC_CAST(void, c);
  const uint_fast32_t t0 = b | a;
  const uint_fast32_t t1 = ~t0;
  return t1;
}

SIMDE_FUNCTION_ATTRIBUTES
uint_fast32_t
simde_x_ternarylogic_0x04_impl_(uint_fast32_t a, uint_fast32_t b, uint_fast32_t c) {
  const uint_fast32_t t0 = a | c;
  const uint_fast32_t t1 = ~t0;
  const uint_fast32_t t2 = b & t1;
  return t2;
}

SIMDE_FUNCTION_ATTRIBUTES
uint_fast32_t
simde_x_ternarylogic_0x05_impl_(uint_fast32_t a, uint_fast32_t b, uint_fast32_t c) {
  HEDLEY_STATIC_CAST(void, b);
  const uint_fast32_t t0 = c | a;
  const uint_fast32_t t1 = ~t0;
  return t1;
}

SIMDE_FUNCTION_ATTRIBUTES
uint_fast32_t
simde_x_ternarylogic_0x06_impl_(uint_fast32_t a, uint_fast32_t b, uint_fast32_t c) {
  const uint_fast32_t t0 = ~a;
  const uint_fast32_t t1 = b ^ c;
  const uint_fast32_t t2 = t0 & t1;
  return t2;
}

SIMDE_FUNCTION_ATTRIBUTES
uint_fast32_t
simde_x_ternarylogic_0x07_impl_(uint_fast32_t a, uint_fast32_t b, uint_fast32_t c) {
  const uint_fast32_t t0 = b & c;
  const uint_fast32_t t1 = a | t0;
  const uint_fast32_t t2 = ~t1;
  return t2;
}

SIMDE_FUNCTION_ATTRIBUTES
uint_fast32_t
simde_x_ternarylogic_0x08_impl_(uint_fast32_t a, uint_fast32_t b, uint_fast32_t c) {
  const uint_fast32_t t0 = ~a;
  const uint_fast32_t t1 = t0 & b;
  const uint_fast32_t t2 = t1 & c;
  return t2;
}

SIMDE_FUNCTION_ATTRIBUTES
uint_fast32_t
simde_x_ternarylogic_0x09_impl_(uint_fast32_t a, uint_fast32_t b, uint_fast32_t c) {
  const uint_fast32_t t0 = b ^ c;
  const uint_fast32_t t1 = a | t0;
  const uint_fast32_t t2 = ~t1;
  return t2;
}

SIMDE_FUNCTION_ATTRIBUTES
uint_fast32_t
simde_x_ternarylogic_0x0a_impl_(uint_fast32_t a, uint_fast32_t b, uint_fast32_t c) {
  HEDLEY_STATIC_CAST(void, b);
  const uint_fast32_t t0 = ~a;
  const uint_fast32_t t1 = c & t0;
  return t1;
}

SIMDE_FUNCTION_ATTRIBUTES
uint_fast32_t
simde_x_ternarylogic_0x0b_impl_(uint_fast32_t a, uint_fast32_t b, uint_fast32_t c) {
  const uint_fast32_t t0 = ~a;
  const uint_fast32_t t1 = ~b;
  const uint_fast32_t t2 = t1 | c;
  const uint_fast32_t t3 = t0 & t2;
  return t3;
}

SIMDE_FUNCTION_ATTRIBUTES
uint_fast32_t
simde_x_ternarylogic_0x0c_impl_(uint_fast32_t a, uint_fast32_t b, uint_fast32_t c) {
  HEDLEY_STATIC_CAST(void, c);
  const uint_fast32_t t0 = ~a;
  const uint_fast32_t t1 = b & t0;
  return t1;
}

SIMDE_FUNCTION_ATTRIBUTES
uint_fast32_t
simde_x_ternarylogic_0x0d_impl_(uint_fast32_t a, uint_fast32_t b, uint_fast32_t c) {
  const uint_fast32_t t0 = ~a;
  const uint_fast32_t t1 = ~c;
  const uint_fast32_t t2 = t1 | b;
  const uint_fast32_t t3 = t0 & t2;
  return t3;
}

SIMDE_FUNCTION_ATTRIBUTES
uint_fast32_t
simde_x_ternarylogic_0x0e_impl_(uint_fast32_t a, uint_fast32_t b, uint_fast32_t c) {
  const uint_fast32_t t0 = ~a;
  const uint_fast32_t t1 = b | c;
  const uint_fast32_t t2 = t0 & t1;
  return t2;
}

SIMDE_FUNCTION_ATTRIBUTES
uint_fast32_t
simde_x_ternarylogic_0x0f_impl_(uint_fast32_t a, uint_fast32_t b, uint_fast32_t c) {
  HEDLEY_STATIC_CAST(void, b);
  HEDLEY_STATIC_CAST(void, c);
  const uint_fast32_t t0 = ~a;
  return t0;
}

SIMDE_FUNCTION_ATTRIBUTES
uint_fast32_t
simde_x_ternarylogic_0x10_impl_(uint_fast32_t a, uint_fast32_t b, uint_fast32_t c) {
  const uint_fast32_t t0 = b | c;
  const uint_fast32_t t1 = ~t0;
  const uint_fast32_t t2 = a & t1;
  return t2;
}

SIMDE_FUNCTION_ATTRIBUTES
uint_fast32_t
simde_x_ternarylogic_0x11_impl_(uint_fast32_t a, uint_fast32_t b, uint_fast32_t c) {
  HEDLEY_STATIC_CAST(void, a);
  const uint_fast32_t t0 = c | b;
  const uint_fast32_t t1 = ~t0;
  return t1;
}

SIMDE_FUNCTION_ATTRIBUTES
uint_fast32_t
simde_x_ternarylogic_0x12_impl_(uint_fast32_t a, uint_fast32_t b, uint_fast32_t c) {
  const uint_fast32_t t0 = ~b;
  const uint_fast32_t t1 = a ^ c;
  const uint_fast32_t t2 = t0 & t1;
  return t2;
}

SIMDE_FUNCTION_ATTRIBUTES
uint_fast32_t
simde_x_ternarylogic_0x13_impl_(uint_fast32_t a, uint_fast32_t b, uint_fast32_t c) {
  const uint_fast32_t t0 = a & c;
  const uint_fast32_t t1 = b | t0;
  const uint_fast32_t t2 = ~t1;
  return t2;
}

SIMDE_FUNCTION_ATTRIBUTES
uint_fast32_t
simde_x_ternarylogic_0x14_impl_(uint_fast32_t a, uint_fast32_t b, uint_fast32_t c) {
  const uint_fast32_t t0 = ~c;
  const uint_fast32_t t1 = a ^ b;
  const uint_fast32_t t2 = t0 & t1;
  return t2;
}

SIMDE_FUNCTION_ATTRIBUTES
uint_fast32_t
simde_x_ternarylogic_0x15_impl_(uint_fast32_t a, uint_fast32_t b, uint_fast32_t c) {
  const uint_fast32_t t0 = b & a;
  const uint_fast32_t t1 = c | t0;
  const uint_fast32_t t2 = ~t1;
  return t2;
}

SIMDE_FUNCTION_ATTRIBUTES
uint_fast32_t
simde_x_ternarylogic_0x16_impl_(uint_fast32_t a, uint_fast32_t b, uint_fast32_t c) {
  const uint_fast32_t t0 = b | c;
  const uint_fast32_t t1 = ~t0;
  const uint_fast32_t t2 = a & t1;
  const uint_fast32_t t3 = ~a;
  const uint_fast32_t t4 = b ^ c;
  const uint_fast32_t t5 = t3 & t4;
  const uint_fast32_t t6 = t2 | t5;
  return t6;
}

SIMDE_FUNCTION_ATTRIBUTES
uint_fast32_t
simde_x_ternarylogic_0x17_impl_(uint_fast32_t a, uint_fast32_t b, uint_fast32_t c) {
  const uint_fast32_t t0 = b | c;
  const uint_fast32_t t1 = b & c;
  const uint_fast32_t t2 = (a & t0) | (~a & t1);
  const uint_fast32_t t3 = ~t2;
  return t3;
}

SIMDE_FUNCTION_ATTRIBUTES
uint_fast32_t
simde_x_ternarylogic_0x18_impl_(uint_fast32_t a, uint_fast32_t b, uint_fast32_t c) {
  const uint_fast32_t t0 = a ^ b;
  const uint_fast32_t t1 = a ^ c;
  const uint_fast32_t t2 = t0 & t1;
  return t2;
}

SIMDE_FUNCTION_ATTRIBUTES
uint_fast32_t
simde_x_ternarylogic_0x19_impl_(uint_fast32_t a, uint_fast32_t b, uint_fast32_t c) {
  const uint_fast32_t t0 = b ^ c;
  const uint_fast32_t t1 = b & c;
  const uint_fast32_t t2 = a & t1;
  const uint_fast32_t t3 = t0 ^ t2;
  const uint_fast32_t t4 = ~t3;
  return t4;
}

SIMDE_FUNCTION_ATTRIBUTES
uint_fast32_t
simde_x_ternarylogic_0x1a_impl_(uint_fast32_t a, uint_fast32_t b, uint_fast32_t c) {
  const uint_fast32_t t0 = a & b;
  const uint_fast32_t t1 = ~t0;
  const uint_fast32_t t2 = a ^ c;
  const uint_fast32_t t3 = t1 & t2;
  return t3;
}

SIMDE_FUNCTION_ATTRIBUTES
uint_fast32_t
simde_x_ternarylogic_0x1b_impl_(uint_fast32_t a, uint_fast32_t b, uint_fast32_t c) {
  const uint_fast32_t t0 = a & c;
  const uint_fast32_t t1 = ~b;
  const uint_fast32_t t2 = t1 | c;
  const uint_fast32_t t3 = t0 ^ t2;
  return t3;
}

SIMDE_FUNCTION_ATTRIBUTES
uint_fast32_t
simde_x_ternarylogic_0x1c_impl_(uint_fast32_t a, uint_fast32_t b, uint_fast32_t c) {
  const uint_fast32_t t0 = a & c;
  const uint_fast32_t t1 = ~t0;
  const uint_fast32_t t2 = a ^ b;
  const uint_fast32_t t3 = t1 & t2;
  return t3;
}

SIMDE_FUNCTION_ATTRIBUTES
uint_fast32_t
simde_x_ternarylogic_0x1d_impl_(uint_fast32_t a, uint_fast32_t b, uint_fast32_t c) {
  const uint_fast32_t t0 = a & b;
  const uint_fast32_t t1 = ~c;
  const uint_fast32_t t2 = t1 | b;
  const uint_fast32_t t3 = t0 ^ t2;
  return t3;
}

SIMDE_FUNCTION_ATTRIBUTES
uint_fast32_t
simde_x_ternarylogic_0x1e_impl_(uint_fast32_t a, uint_fast32_t b, uint_fast32_t c) {
  const uint_fast32_t t0 = b | c;
  const uint_fast32_t t1 = a ^ t0;
  return t1;
}

SIMDE_FUNCTION_ATTRIBUTES
uint_fast32_t
simde_x_ternarylogic_0x1f_impl_(uint_fast32_t a, uint_fast32_t b, uint_fast32_t c) {
  const uint_fast32_t t0 = b | c;
  const uint_fast32_t t1 = a & t0;
  const uint_fast32_t t2 = ~t1;
  return t2;
}

SIMDE_FUNCTION_ATTRIBUTES
uint_fast32_t
simde_x_ternarylogic_0x20_impl_(uint_fast32_t a, uint_fast32_t b, uint_fast32_t c) {
  const uint_fast32_t t0 = ~b;
  const uint_fast32_t t1 = t0 & a;
  const uint_fast32_t t2 = t1 & c;
  return t2;
}

SIMDE_FUNCTION_ATTRIBUTES
uint_fast32_t
simde_x_ternarylogic_0x21_impl_(uint_fast32_t a, uint_fast32_t b, uint_fast32_t c) {
  const uint_fast32_t t0 = a ^ c;
  const uint_fast32_t t1 = b | t0;
  const uint_fast32_t t2 = ~t1;
  return t2;
}

SIMDE_FUNCTION_ATTRIBUTES
uint_fast32_t
simde_x_ternarylogic_0x22_impl_(uint_fast32_t a, uint_fast32_t b, uint_fast32_t c) {
  HEDLEY_STATIC_CAST(void, a);
  const uint_fast32_t t0 = ~b;
  const uint_fast32_t t1 = c & t0;
  return t1;
}

SIMDE_FUNCTION_ATTRIBUTES
uint_fast32_t
simde_x_ternarylogic_0x23_impl_(uint_fast32_t a, uint_fast32_t b, uint_fast32_t c) {
  const uint_fast32_t t0 = ~b;
  const uint_fast32_t t1 = ~a;
  const uint_fast32_t t2 = t1 | c;
  const uint_fast32_t t3 = t0 & t2;
  return t3;
}

SIMDE_FUNCTION_ATTRIBUTES
uint_fast32_t
simde_x_ternarylogic_0x24_impl_(uint_fast32_t a, uint_fast32_t b, uint_fast32_t c) {
  const uint_fast32_t t0 = a ^ b;
  const uint_fast32_t t1 = b ^ c;
  const uint_fast32_t t2 = t0 & t1;
  return t2;
}

SIMDE_FUNCTION_ATTRIBUTES
uint_fast32_t
simde_x_ternarylogic_0x25_impl_(uint_fast32_t a, uint_fast32_t b, uint_fast32_t c) {
  const uint_fast32_t t0 = a & b;
  const uint_fast32_t t1 = ~t0;
  const uint_fast32_t t2 = ~c;
  const uint_fast32_t t3 = a ^ t2;
  const uint_fast32_t t4 = t1 & t3;
  return t4;
}

SIMDE_FUNCTION_ATTRIBUTES
uint_fast32_t
simde_x_ternarylogic_0x26_impl_(uint_fast32_t a, uint_fast32_t b, uint_fast32_t c) {
  const uint_fast32_t t0 = a & b;
  const uint_fast32_t t1 = ~t0;
  const uint_fast32_t t2 = b ^ c;
  const uint_fast32_t t3 = t1 & t2;
  return t3;
}

SIMDE_FUNCTION_ATTRIBUTES
uint_fast32_t
simde_x_ternarylogic_0x27_impl_(uint_fast32_t a, uint_fast32_t b, uint_fast32_t c) {
  const uint_fast32_t t0 = b & c;
  const uint_fast32_t t1 = ~a;
  const uint_fast32_t t2 = t1 | c;
  const uint_fast32_t t3 = t0 ^ t2;
  return t3;
}

SIMDE_FUNCTION_ATTRIBUTES
uint_fast32_t
simde_x_ternarylogic_0x28_impl_(uint_fast32_t a, uint_fast32_t b, uint_fast32_t c) {
  const uint_fast32_t t0 = b ^ a;
  const uint_fast32_t t1 = c & t0;
  return t1;
}

SIMDE_FUNCTION_ATTRIBUTES
uint_fast32_t
simde_x_ternarylogic_0x29_impl_(uint_fast32_t a, uint_fast32_t b, uint_fast32_t c) {
  const uint_fast32_t t0 = ~a;
  const uint_fast32_t t1 = t0 | c;
  const uint_fast32_t t2 = ~a;
  const uint_fast32_t t3 = b ^ c;
  const uint_fast32_t t4 = t2 ^ t3;
  const uint_fast32_t t5 = t1 & t4;
  return t5;
}

SIMDE_FUNCTION_ATTRIBUTES
uint_fast32_t
simde_x_ternarylogic_0x2a_impl_(uint_fast32_t a, uint_fast32_t b, uint_fast32_t c) {
  const uint_fast32_t t0 = b & a;
  const uint_fast32_t t1 = ~t0;
  const uint_fast32_t t2 = c & t1;
  return t2;
}

SIMDE_FUNCTION_ATTRIBUTES
uint_fast32_t
simde_x_ternarylogic_0x2b_impl_(uint_fast32_t a, uint_fast32_t b, uint_fast32_t c) {
  const uint_fast32_t t0 = b & a;
  const uint_fast32_t t1 = ~t0;
  const uint_fast32_t t2 = c & t1;
  const uint_fast32_t t3 = ~c;
  const uint_fast32_t t4 = b | a;
  const uint_fast32_t t5 = ~t4;
  const uint_fast32_t t6 = t3 & t5;
  const uint_fast32_t t7 = t2 | t6;
  return t7;
}

SIMDE_FUNCTION_ATTRIBUTES
uint_fast32_t
simde_x_ternarylogic_0x2c_impl_(uint_fast32_t a, uint_fast32_t b, uint_fast32_t c) {
  const uint_fast32_t t0 = b | c;
  const uint_fast32_t t1 = a ^ b;
  const uint_fast32_t t2 = t0 & t1;
  return t2;
}

SIMDE_FUNCTION_ATTRIBUTES
uint_fast32_t
simde_x_ternarylogic_0x2d_impl_(uint_fast32_t a, uint_fast32_t b, uint_fast32_t c) {
  const uint_fast32_t t0 = ~c;
  const uint_fast32_t t1 = b | t0;
  const uint_fast32_t t2 = a ^ t1;
  return t2;
}

SIMDE_FUNCTION_ATTRIBUTES
uint_fast32_t
simde_x_ternarylogic_0x2e_impl_(uint_fast32_t a, uint_fast32_t b, uint_fast32_t c) {
  const uint_fast32_t t0 = b | c;
  const uint_fast32_t t1 = a & b;
  const uint_fast32_t t2 = t0 ^ t1;
  return t2;
}

SIMDE_FUNCTION_ATTRIBUTES
uint_fast32_t
simde_x_ternarylogic_0x2f_impl_(uint_fast32_t a, uint_fast32_t b, uint_fast32_t c) {
  const uint_fast32_t t0 = ~a;
  const uint_fast32_t t1 = ~b;
  const uint_fast32_t t2 = t1 & c;
  const uint_fast32_t t3 = t0 | t2;
  return t3;
}

SIMDE_FUNCTION_ATTRIBUTES
uint_fast32_t
simde_x_ternarylogic_0x30_impl_(uint_fast32_t a, uint_fast32_t b, uint_fast32_t c) {
  HEDLEY_STATIC_CAST(void, c);
  const uint_fast32_t t0 = ~b;
  const uint_fast32_t t1 = a & t0;
  return t1;
}

SIMDE_FUNCTION_ATTRIBUTES
uint_fast32_t
simde_x_ternarylogic_0x31_impl_(uint_fast32_t a, uint_fast32_t b, uint_fast32_t c) {
  const uint_fast32_t t0 = ~b;
  const uint_fast32_t t1 = ~c;
  const uint_fast32_t t2 = t1 | a;
  const uint_fast32_t t3 = t0 & t2;
  return t3;
}

SIMDE_FUNCTION_ATTRIBUTES
uint_fast32_t
simde_x_ternarylogic_0x32_impl_(uint_fast32_t a, uint_fast32_t b, uint_fast32_t c) {
  const uint_fast32_t t0 = ~b;
  const uint_fast32_t t1 = a | c;
  const uint_fast32_t t2 = t0 & t1;
  return t2;
}

SIMDE_FUNCTION_ATTRIBUTES
uint_fast32_t
simde_x_ternarylogic_0x33_impl_(uint_fast32_t a, uint_fast32_t b, uint_fast32_t c) {
  HEDLEY_STATIC_CAST(void, a);
  HEDLEY_STATIC_CAST(void, c);
  const uint_fast32_t t0 = ~b;
  return t0;
}

SIMDE_FUNCTION_ATTRIBUTES
uint_fast32_t
simde_x_ternarylogic_0x34_impl_(uint_fast32_t a, uint_fast32_t b, uint_fast32_t c) {
  const uint_fast32_t t0 = b & c;
  const uint_fast32_t t1 = ~t0;
  const uint_fast32_t t2 = a ^ b;
  const uint_fast32_t t3 = t1 & t2;
  return t3;
}

SIMDE_FUNCTION_ATTRIBUTES
uint_fast32_t
simde_x_ternarylogic_0x35_impl_(uint_fast32_t a, uint_fast32_t b, uint_fast32_t c) {
  const uint_fast32_t t0 = a & b;
  const uint_fast32_t t1 = ~c;
  const uint_fast32_t t2 = t1 | a;
  const uint_fast32_t t3 = t0 ^ t2;
  return t3;
}

SIMDE_FUNCTION_ATTRIBUTES
uint_fast32_t
simde_x_ternarylogic_0x36_impl_(uint_fast32_t a, uint_fast32_t b, uint_fast32_t c) {
  const uint_fast32_t t0 = a | c;
  const uint_fast32_t t1 = b ^ t0;
  return t1;
}

SIMDE_FUNCTION_ATTRIBUTES
uint_fast32_t
simde_x_ternarylogic_0x37_impl_(uint_fast32_t a, uint_fast32_t b, uint_fast32_t c) {
  const uint_fast32_t t0 = a | c;
  const uint_fast32_t t1 = b & t0;
  const uint_fast32_t t2 = ~t1;
  return t2;
}

SIMDE_FUNCTION_ATTRIBUTES
uint_fast32_t
simde_x_ternarylogic_0x38_impl_(uint_fast32_t a, uint_fast32_t b, uint_fast32_t c) {
  const uint_fast32_t t0 = a | c;
  const uint_fast32_t t1 = a ^ b;
  const uint_fast32_t t2 = t0 & t1;
  return t2;
}

SIMDE_FUNCTION_ATTRIBUTES
uint_fast32_t
simde_x_ternarylogic_0x39_impl_(uint_fast32_t a, uint_fast32_t b, uint_fast32_t c) {
  const uint_fast32_t t0 = ~c;
  const uint_fast32_t t1 = t0 | a;
  const uint_fast32_t t2 = b ^ t1;
  return t2;
}

SIMDE_FUNCTION_ATTRIBUTES
uint_fast32_t
simde_x_ternarylogic_0x3a_impl_(uint_fast32_t a, uint_fast32_t b, uint_fast32_t c) {
  const uint_fast32_t t0 = ~b;
  const uint_fast32_t t1 = a & t0;
  const uint_fast32_t t2 = ~a;
  const uint_fast32_t t3 = t2 & c;
  const uint_fast32_t t4 = t1 | t3;
  return t4;
}

SIMDE_FUNCTION_ATTRIBUTES
uint_fast32_t
simde_x_ternarylogic_0x3b_impl_(uint_fast32_t a, uint_fast32_t b, uint_fast32_t c) {
  const uint_fast32_t t0 = ~b;
  const uint_fast32_t t1 = ~a;
  const uint_fast32_t t2 = t1 & c;
  const uint_fast32_t t3 = t0 | t2;
  return t3;
}

SIMDE_FUNCTION_ATTRIBUTES
uint_fast32_t
simde_x_ternarylogic_0x3c_impl_(uint_fast32_t a, uint_fast32_t b, uint_fast32_t c) {
  HEDLEY_STATIC_CAST(void, c);
  const uint_fast32_t t0 = b ^ a;
  return t0;
}

SIMDE_FUNCTION_ATTRIBUTES
uint_fast32_t
simde_x_ternarylogic_0x3d_impl_(uint_fast32_t a, uint_fast32_t b, uint_fast32_t c) {
  const uint_fast32_t t0 = a ^ b;
  const uint_fast32_t t1 = a | c;
  const uint_fast32_t t2 = ~t1;
  const uint_fast32_t t3 = t0 | t2;
  return t3;
}

SIMDE_FUNCTION_ATTRIBUTES
uint_fast32_t
simde_x_ternarylogic_0x3e_impl_(uint_fast32_t a, uint_fast32_t b, uint_fast32_t c) {
  const uint_fast32_t t0 = ~a;
  const uint_fast32_t t1 = t0 & c;
  const uint_fast32_t t2 = a ^ b;
  const uint_fast32_t t3 = t1 | t2;
  return t3;
}

SIMDE_FUNCTION_ATTRIBUTES
uint_fast32_t
simde_x_ternarylogic_0x3f_impl_(uint_fast32_t a, uint_fast32_t b, uint_fast32_t c) {
  HEDLEY_STATIC_CAST(void, c);
  const uint_fast32_t t0 = b & a;
  const uint_fast32_t t1 = ~t0;
  return t1;
}

SIMDE_FUNCTION_ATTRIBUTES
uint_fast32_t
simde_x_ternarylogic_0x40_impl_(uint_fast32_t a, uint_fast32_t b, uint_fast32_t c) {
  const uint_fast32_t t0 = ~c;
  const uint_fast32_t t1 = t0 & a;
  const uint_fast32_t t2 = t1 & b;
  return t2;
}

SIMDE_FUNCTION_ATTRIBUTES
uint_fast32_t
simde_x_ternarylogic_0x41_impl_(uint_fast32_t a, uint_fast32_t b, uint_fast32_t c) {
  const uint_fast32_t t0 = b ^ a;
  const uint_fast32_t t1 = c | t0;
  const uint_fast32_t t2 = ~t1;
  return t2;
}

SIMDE_FUNCTION_ATTRIBUTES
uint_fast32_t
simde_x_ternarylogic_0x42_impl_(uint_fast32_t a, uint_fast32_t b, uint_fast32_t c) {
  const uint_fast32_t t0 = a ^ c;
  const uint_fast32_t t1 = b ^ c;
  const uint_fast32_t t2 = t0 & t1;
  return t2;
}

SIMDE_FUNCTION_ATTRIBUTES
uint_fast32_t
simde_x_ternarylogic_0x43_impl_(uint_fast32_t a, uint_fast32_t b, uint_fast32_t c) {
  const uint_fast32_t t0 = a & c;
  const uint_fast32_t t1 = ~t0;
  const uint_fast32_t t2 = ~b;
  const uint_fast32_t t3 = a ^ t2;
  const uint_fast32_t t4 = t1 & t3;
  return t4;
}

SIMDE_FUNCTION_ATTRIBUTES
uint_fast32_t
simde_x_ternarylogic_0x44_impl_(uint_fast32_t a, uint_fast32_t b, uint_fast32_t c) {
  HEDLEY_STATIC_CAST(void, a);
  const uint_fast32_t t0 = ~c;
  const uint_fast32_t t1 = b & t0;
  return t1;
}

SIMDE_FUNCTION_ATTRIBUTES
uint_fast32_t
simde_x_ternarylogic_0x45_impl_(uint_fast32_t a, uint_fast32_t b, uint_fast32_t c) {
  const uint_fast32_t t0 = ~c;
  const uint_fast32_t t1 = ~a;
  const uint_fast32_t t2 = t1 | b;
  const uint_fast32_t t3 = t0 & t2;
  return t3;
}

SIMDE_FUNCTION_ATTRIBUTES
uint_fast32_t
simde_x_ternarylogic_0x46_impl_(uint_fast32_t a, uint_fast32_t b, uint_fast32_t c) {
  const uint_fast32_t t0 = a & c;
  const uint_fast32_t t1 = ~t0;
  const uint_fast32_t t2 = b ^ c;
  const uint_fast32_t t3 = t1 & t2;
  return t3;
}

SIMDE_FUNCTION_ATTRIBUTES
uint_fast32_t
simde_x_ternarylogic_0x47_impl_(uint_fast32_t a, uint_fast32_t b, uint_fast32_t c) {
  const uint_fast32_t t0 = b & c;
  const uint_fast32_t t1 = ~a;
  const uint_fast32_t t2 = t1 | b;
  const uint_fast32_t t3 = t0 ^ t2;
  return t3;
}

SIMDE_FUNCTION_ATTRIBUTES
uint_fast32_t
simde_x_ternarylogic_0x48_impl_(uint_fast32_t a, uint_fast32_t b, uint_fast32_t c) {
  const uint_fast32_t t0 = a ^ c;
  const uint_fast32_t t1 = b & t0;
  return t1;
}

SIMDE_FUNCTION_ATTRIBUTES
uint_fast32_t
simde_x_ternarylogic_0x49_impl_(uint_fast32_t a, uint_fast32_t b, uint_fast32_t c) {
  const uint_fast32_t t0 = ~a;
  const uint_fast32_t t1 = t0 | b;
  const uint_fast32_t t2 = ~a;
  const uint_fast32_t t3 = b ^ c;
  const uint_fast32_t t4 = t2 ^ t3;
  const uint_fast32_t t5 = t1 & t4;
  return t5;
}

SIMDE_FUNCTION_ATTRIBUTES
uint_fast32_t
simde_x_ternarylogic_0x4a_impl_(uint_fast32_t a, uint_fast32_t b, uint_fast32_t c) {
  const uint_fast32_t t0 = b | c;
  const uint_fast32_t t1 = a ^ c;
  const uint_fast32_t t2 = t0 & t1;
  return t2;
}

SIMDE_FUNCTION_ATTRIBUTES
uint_fast32_t
simde_x_ternarylogic_0x4b_impl_(uint_fast32_t a, uint_fast32_t b, uint_fast32_t c) {
  const uint_fast32_t t0 = ~b;
  const uint_fast32_t t1 = t0 | c;
  const uint_fast32_t t2 = a ^ t1;
  return t2;
}

SIMDE_FUNCTION_ATTRIBUTES
uint_fast32_t
simde_x_ternarylogic_0x4c_impl_(uint_fast32_t a, uint_fast32_t b, uint_fast32_t c) {
  const uint_fast32_t t0 = a & c;
  const uint_fast32_t t1 = ~t0;
  const uint_fast32_t t2 = b & t1;
  return t2;
}

SIMDE_FUNCTION_ATTRIBUTES
uint_fast32_t
simde_x_ternarylogic_0x4d_impl_(uint_fast32_t a, uint_fast32_t b, uint_fast32_t c) {
  const uint_fast32_t t0 = a & c;
  const uint_fast32_t t1 = ~t0;
  const uint_fast32_t t2 = b & t1;
  const uint_fast32_t t3 = ~b;
  const uint_fast32_t t4 = a | c;
  const uint_fast32_t t5 = ~t4;
  const uint_fast32_t t6 = t3 & t5;
  const uint_fast32_t t7 = t2 | t6;
  return t7;
}

SIMDE_FUNCTION_ATTRIBUTES
uint_fast32_t
simde_x_ternarylogic_0x4e_impl_(uint_fast32_t a, uint_fast32_t b, uint_fast32_t c) {
  const uint_fast32_t t0 = ~a;
  const uint_fast32_t t1 = c & t0;
  const uint_fast32_t t2 = ~c;
  const uint_fast32_t t3 = t2 & b;
  const uint_fast32_t t4 = t1 | t3;
  return t4;
}

SIMDE_FUNCTION_ATTRIBUTES
uint_fast32_t
simde_x_ternarylogic_0x4f_impl_(uint_fast32_t a, uint_fast32_t b, uint_fast32_t c) {
  const uint_fast32_t t0 = ~a;
  const uint_fast32_t t1 = ~c;
  const uint_fast32_t t2 = b & t1;
  const uint_fast32_t t3 = t0 | t2;
  return t3;
}

SIMDE_FUNCTION_ATTRIBUTES
uint_fast32_t
simde_x_ternarylogic_0x50_impl_(uint_fast32_t a, uint_fast32_t b, uint_fast32_t c) {
  HEDLEY_STATIC_CAST(void, b);
  const uint_fast32_t t0 = ~c;
  const uint_fast32_t t1 = a & t0;
  return t1;
}

SIMDE_FUNCTION_ATTRIBUTES
uint_fast32_t
simde_x_ternarylogic_0x51_impl_(uint_fast32_t a, uint_fast32_t b, uint_fast32_t c) {
  const uint_fast32_t t0 = ~c;
  const uint_fast32_t t1 = ~b;
  const uint_fast32_t t2 = t1 | a;
  const uint_fast32_t t3 = t0 & t2;
  return t3;
}

SIMDE_FUNCTION_ATTRIBUTES
uint_fast32_t
simde_x_ternarylogic_0x52_impl_(uint_fast32_t a, uint_fast32_t b, uint_fast32_t c) {
  const uint_fast32_t t0 = b & c;
  const uint_fast32_t t1 = ~t0;
  const uint_fast32_t t2 = a ^ c;
  const uint_fast32_t t3 = t1 & t2;
  return t3;
}

SIMDE_FUNCTION_ATTRIBUTES
uint_fast32_t
simde_x_ternarylogic_0x53_impl_(uint_fast32_t a, uint_fast32_t b, uint_fast32_t c) {
  const uint_fast32_t t0 = a & c;
  const uint_fast32_t t1 = ~b;
  const uint_fast32_t t2 = t1 | a;
  const uint_fast32_t t3 = t0 ^ t2;
  return t3;
}

SIMDE_FUNCTION_ATTRIBUTES
uint_fast32_t
simde_x_ternarylogic_0x54_impl_(uint_fast32_t a, uint_fast32_t b, uint_fast32_t c) {
  const uint_fast32_t t0 = ~c;
  const uint_fast32_t t1 = a | b;
  const uint_fast32_t t2 = t0 & t1;
  return t2;
}

SIMDE_FUNCTION_ATTRIBUTES
uint_fast32_t
simde_x_ternarylogic_0x55_impl_(uint_fast32_t a, uint_fast32_t b, uint_fast32_t c) {
  HEDLEY_STATIC_CAST(void, a);
  HEDLEY_STATIC_CAST(void, b);
  const uint_fast32_t t0 = ~c;
  return t0;
}

SIMDE_FUNCTION_ATTRIBUTES
uint_fast32_t
simde_x_ternarylogic_0x56_impl_(uint_fast32_t a, uint_fast32_t b, uint_fast32_t c) {
  const uint_fast32_t t0 = b | a;
  const uint_fast32_t t1 = c ^ t0;
  return t1;
}

SIMDE_FUNCTION_ATTRIBUTES
uint_fast32_t
simde_x_ternarylogic_0x57_impl_(uint_fast32_t a, uint_fast32_t b, uint_fast32_t c) {
  const uint_fast32_t t0 = b | a;
  const uint_fast32_t t1 = c & t0;
  const uint_fast32_t t2 = ~t1;
  return t2;
}

SIMDE_FUNCTION_ATTRIBUTES
uint_fast32_t
simde_x_ternarylogic_0x58_impl_(uint_fast32_t a, uint_fast32_t b, uint_fast32_t c) {
  const uint_fast32_t t0 = a | b;
  const uint_fast32_t t1 = a ^ c;
  const uint_fast32_t t2 = t0 & t1;
  return t2;
}

SIMDE_FUNCTION_ATTRIBUTES
uint_fast32_t
simde_x_ternarylogic_0x59_impl_(uint_fast32_t a, uint_fast32_t b, uint_fast32_t c) {
  const uint_fast32_t t0 = ~b;
  const uint_fast32_t t1 = t0 | a;
  const uint_fast32_t t2 = c ^ t1;
  return t2;
}

SIMDE_FUNCTION_ATTRIBUTES
uint_fast32_t
simde_x_ternarylogic_0x5a_impl_(uint_fast32_t a, uint_fast32_t b, uint_fast32_t c) {
  HEDLEY_STATIC_CAST(void, b);
  const uint_fast32_t t0 = c ^ a;
  return t0;
}

SIMDE_FUNCTION_ATTRIBUTES
uint_fast32_t
simde_x_ternarylogic_0x5b_impl_(uint_fast32_t a, uint_fast32_t b, uint_fast32_t c) {
  const uint_fast32_t t0 = a | b;
  const uint_fast32_t t1 = ~t0;
  const uint_fast32_t t2 = a ^ c;
  const uint_fast32_t t3 = t1 | t2;
  return t3;
}

SIMDE_FUNCTION_ATTRIBUTES
uint_fast32_t
simde_x_ternarylogic_0x5c_impl_(uint_fast32_t a, uint_fast32_t b, uint_fast32_t c) {
  const uint_fast32_t t0 = ~c;
  const uint_fast32_t t1 = a & t0;
  const uint_fast32_t t2 = ~a;
  const uint_fast32_t t3 = t2 & b;
  const uint_fast32_t t4 = t1 | t3;
  return t4;
}

SIMDE_FUNCTION_ATTRIBUTES
uint_fast32_t
simde_x_ternarylogic_0x5d_impl_(uint_fast32_t a, uint_fast32_t b, uint_fast32_t c) {
  const uint_fast32_t t0 = ~c;
  const uint_fast32_t t1 = ~a;
  const uint_fast32_t t2 = t1 & b;
  const uint_fast32_t t3 = t0 | t2;
  return t3;
}

SIMDE_FUNCTION_ATTRIBUTES
uint_fast32_t
simde_x_ternarylogic_0x5e_impl_(uint_fast32_t a, uint_fast32_t b, uint_fast32_t c) {
  const uint_fast32_t t0 = ~c;
  const uint_fast32_t t1 = t0 & b;
  const uint_fast32_t t2 = a ^ c;
  const uint_fast32_t t3 = t1 | t2;
  return t3;
}

SIMDE_FUNCTION_ATTRIBUTES
uint_fast32_t
simde_x_ternarylogic_0x5f_impl_(uint_fast32_t a, uint_fast32_t b, uint_fast32_t c) {
  HEDLEY_STATIC_CAST(void, b);
  const uint_fast32_t t0 = c & a;
  const uint_fast32_t t1 = ~t0;
  return t1;
}

SIMDE_FUNCTION_ATTRIBUTES
uint_fast32_t
simde_x_ternarylogic_0x60_impl_(uint_fast32_t a, uint_fast32_t b, uint_fast32_t c) {
  const uint_fast32_t t0 = b ^ c;
  const uint_fast32_t t1 = a & t0;
  return t1;
}

SIMDE_FUNCTION_ATTRIBUTES
uint_fast32_t
simde_x_ternarylogic_0x61_impl_(uint_fast32_t a, uint_fast32_t b, uint_fast32_t c) {
  const uint_fast32_t t0 = ~b;
  const uint_fast32_t t1 = t0 | a;
  const uint_fast32_t t2 = ~b;
  const uint_fast32_t t3 = a ^ c;
  const uint_fast32_t t4 = t2 ^ t3;
  const uint_fast32_t t5 = t1 & t4;
  return t5;
}

SIMDE_FUNCTION_ATTRIBUTES
uint_fast32_t
simde_x_ternarylogic_0x62_impl_(uint_fast32_t a, uint_fast32_t b, uint_fast32_t c) {
  const uint_fast32_t t0 = a | c;
  const uint_fast32_t t1 = b ^ c;
  const uint_fast32_t t2 = t0 & t1;
  return t2;
}

SIMDE_FUNCTION_ATTRIBUTES
uint_fast32_t
simde_x_ternarylogic_0x63_impl_(uint_fast32_t a, uint_fast32_t b, uint_fast32_t c) {
  const uint_fast32_t t0 = ~a;
  const uint_fast32_t t1 = t0 | c;
  const uint_fast32_t t2 = b ^ t1;
  return t2;
}

SIMDE_FUNCTION_ATTRIBUTES
uint_fast32_t
simde_x_ternarylogic_0x64_impl_(uint_fast32_t a, uint_fast32_t b, uint_fast32_t c) {
  const uint_fast32_t t0 = a | b;
  const uint_fast32_t t1 = b ^ c;
  const uint_fast32_t t2 = t0 & t1;
  return t2;
}

SIMDE_FUNCTION_ATTRIBUTES
uint_fast32_t
simde_x_ternarylogic_0x65_impl_(uint_fast32_t a, uint_fast32_t b, uint_fast32_t c) {
  const uint_fast32_t t0 = ~a;
  const uint_fast32_t t1 = t0 | b;
  const uint_fast32_t t2 = c ^ t1;
  return t2;
}

SIMDE_FUNCTION_ATTRIBUTES
uint_fast32_t
simde_x_ternarylogic_0x66_impl_(uint_fast32_t a, uint_fast32_t b, uint_fast32_t c) {
  HEDLEY_STATIC_CAST(void, a);
  const uint_fast32_t t0 = c ^ b;
  return t0;
}

SIMDE_FUNCTION_ATTRIBUTES
uint_fast32_t
simde_x_ternarylogic_0x67_impl_(uint_fast32_t a, uint_fast32_t b, uint_fast32_t c) {
  const uint_fast32_t t0 = b ^ c;
  const uint_fast32_t t1 = a | b;
  const uint_fast32_t t2 = ~t1;
  const uint_fast32_t t3 = t0 | t2;
  return t3;
}

SIMDE_FUNCTION_ATTRIBUTES
uint_fast32_t
simde_x_ternarylogic_0x68_impl_(uint_fast32_t a, uint_fast32_t b, uint_fast32_t c) {
  const uint_fast32_t t0 = b ^ c;
  const uint_fast32_t t1 = a & t0;
  const uint_fast32_t t2 = ~a;
  const uint_fast32_t t3 = b & c;
  const uint_fast32_t t4 = t2 & t3;
  const uint_fast32_t t5 = t1 | t4;
  return t5;
}

SIMDE_FUNCTION_ATTRIBUTES
uint_fast32_t
simde_x_ternarylogic_0x69_impl_(uint_fast32_t a, uint_fast32_t b, uint_fast32_t c) {
  const uint_fast32_t t0 = b ^ c;
  const uint_fast32_t t1 = a ^ t0;
  const uint_fast32_t t2 = ~t1;
  return t2;
}

SIMDE_FUNCTION_ATTRIBUTES
uint_fast32_t
simde_x_ternarylogic_0x6a_impl_(uint_fast32_t a, uint_fast32_t b, uint_fast32_t c) {
  const uint_fast32_t t0 = b & a;
  const uint_fast32_t t1 = c ^ t0;
  return t1;
}

SIMDE_FUNCTION_ATTRIBUTES
uint_fast32_t
simde_x_ternarylogic_0x6b_impl_(uint_fast32_t a, uint_fast32_t b, uint_fast32_t c) {
  const uint_fast32_t t0 = ~a;
  const uint_fast32_t t1 = t0 & c;
  const uint_fast32_t c1 = ~HEDLEY_STATIC_CAST(uint_fast32_t, 0);
  const uint_fast32_t t2 = a ^ c1;
  const uint_fast32_t t3 = b ^ c;
  const uint_fast32_t t4 = t2 ^ t3;
  const uint_fast32_t t5 = t1 | t4;
  return t5;
}

SIMDE_FUNCTION_ATTRIBUTES
uint_fast32_t
simde_x_ternarylogic_0x6c_impl_(uint_fast32_t a, uint_fast32_t b, uint_fast32_t c) {
  const uint_fast32_t t0 = a & c;
  const uint_fast32_t t1 = b ^ t0;
  return t1;
}

SIMDE_FUNCTION_ATTRIBUTES
uint_fast32_t
simde_x_ternarylogic_0x6d_impl_(uint_fast32_t a, uint_fast32_t b, uint_fast32_t c) {
  const uint_fast32_t t0 = ~a;
  const uint_fast32_t t1 = t0 & b;
  const uint_fast32_t c1 = ~HEDLEY_STATIC_CAST(uint_fast32_t, 0);
  const uint_fast32_t t2 = a ^ c1;
  const uint_fast32_t t3 = b ^ c;
  const uint_fast32_t t4 = t2 ^ t3;
  const uint_fast32_t t5 = t1 | t4;
  return t5;
}

SIMDE_FUNCTION_ATTRIBUTES
uint_fast32_t
simde_x_ternarylogic_0x6e_impl_(uint_fast32_t a, uint_fast32_t b, uint_fast32_t c) {
  const uint_fast32_t t0 = ~a;
  const uint_fast32_t t1 = t0 & b;
  const uint_fast32_t t2 = b ^ c;
  const uint_fast32_t t3 = t1 | t2;
  return t3;
}

SIMDE_FUNCTION_ATTRIBUTES
uint_fast32_t
simde_x_ternarylogic_0x6f_impl_(uint_fast32_t a, uint_fast32_t b, uint_fast32_t c) {
  const uint_fast32_t t0 = ~a;
  const uint_fast32_t t1 = b ^ c;
  const uint_fast32_t t2 = t0 | t1;
  return t2;
}

SIMDE_FUNCTION_ATTRIBUTES
uint_fast32_t
simde_x_ternarylogic_0x70_impl_(uint_fast32_t a, uint_fast32_t b, uint_fast32_t c) {
  const uint_fast32_t t0 = b & c;
  const uint_fast32_t t1 = ~t0;
  const uint_fast32_t t2 = a & t1;
  return t2;
}

SIMDE_FUNCTION_ATTRIBUTES
uint_fast32_t
simde_x_ternarylogic_0x71_impl_(uint_fast32_t a, uint_fast32_t b, uint_fast32_t c) {
  const uint_fast32_t t0 = b | c;
  const uint_fast32_t t1 = ~t0;
  const uint_fast32_t t2 = b ^ c;
  const uint_fast32_t t3 = a & t2;
  const uint_fast32_t t4 = t1 | t3;
  return t4;
}

SIMDE_FUNCTION_ATTRIBUTES
uint_fast32_t
simde_x_ternarylogic_0x72_impl_(uint_fast32_t a, uint_fast32_t b, uint_fast32_t c) {
  const uint_fast32_t t0 = ~b;
  const uint_fast32_t t1 = c & t0;
  const uint_fast32_t t2 = ~c;
  const uint_fast32_t t3 = t2 & a;
  const uint_fast32_t t4 = t1 | t3;
  return t4;
}

SIMDE_FUNCTION_ATTRIBUTES
uint_fast32_t
simde_x_ternarylogic_0x73_impl_(uint_fast32_t a, uint_fast32_t b, uint_fast32_t c) {
  const uint_fast32_t t0 = ~b;
  const uint_fast32_t t1 = ~c;
  const uint_fast32_t t2 = a & t1;
  const uint_fast32_t t3 = t0 | t2;
  return t3;
}

SIMDE_FUNCTION_ATTRIBUTES
uint_fast32_t
simde_x_ternarylogic_0x74_impl_(uint_fast32_t a, uint_fast32_t b, uint_fast32_t c) {
  const uint_fast32_t t0 = ~c;
  const uint_fast32_t t1 = b & t0;
  const uint_fast32_t t2 = ~b;
  const uint_fast32_t t3 = t2 & a;
  const uint_fast32_t t4 = t1 | t3;
  return t4;
}

SIMDE_FUNCTION_ATTRIBUTES
uint_fast32_t
simde_x_ternarylogic_0x75_impl_(uint_fast32_t a, uint_fast32_t b, uint_fast32_t c) {
  const uint_fast32_t t0 = ~c;
  const uint_fast32_t t1 = ~b;
  const uint_fast32_t t2 = a & t1;
  const uint_fast32_t t3 = t0 | t2;
  return t3;
}

SIMDE_FUNCTION_ATTRIBUTES
uint_fast32_t
simde_x_ternarylogic_0x76_impl_(uint_fast32_t a, uint_fast32_t b, uint_fast32_t c) {
  const uint_fast32_t t0 = ~b;
  const uint_fast32_t t1 = t0 & a;
  const uint_fast32_t t2 = b ^ c;
  const uint_fast32_t t3 = t1 | t2;
  return t3;
}

SIMDE_FUNCTION_ATTRIBUTES
uint_fast32_t
simde_x_ternarylogic_0x77_impl_(uint_fast32_t a, uint_fast32_t b, uint_fast32_t c) {
  HEDLEY_STATIC_CAST(void, a);
  const uint_fast32_t t0 = c & b;
  const uint_fast32_t t1 = ~t0;
  return t1;
}

SIMDE_FUNCTION_ATTRIBUTES
uint_fast32_t
simde_x_ternarylogic_0x78_impl_(uint_fast32_t a, uint_fast32_t b, uint_fast32_t c) {
  const uint_fast32_t t0 = b & c;
  const uint_fast32_t t1 = a ^ t0;
  return t1;
}

SIMDE_FUNCTION_ATTRIBUTES
uint_fast32_t
simde_x_ternarylogic_0x79_impl_(uint_fast32_t a, uint_fast32_t b, uint_fast32_t c) {
  const uint_fast32_t t0 = ~b;
  const uint_fast32_t t1 = t0 & a;
  const uint_fast32_t c1 = ~HEDLEY_STATIC_CAST(uint_fast32_t, 0);
  const uint_fast32_t t2 = b ^ c1;
  const uint_fast32_t t3 = a ^ c;
  const uint_fast32_t t4 = t2 ^ t3;
  const uint_fast32_t t5 = t1 | t4;
  return t5;
}

SIMDE_FUNCTION_ATTRIBUTES
uint_fast32_t
simde_x_ternarylogic_0x7a_impl_(uint_fast32_t a, uint_fast32_t b, uint_fast32_t c) {
  const uint_fast32_t t0 = ~b;
  const uint_fast32_t t1 = t0 & a;
  const uint_fast32_t t2 = a ^ c;
  const uint_fast32_t t3 = t1 | t2;
  return t3;
}

SIMDE_FUNCTION_ATTRIBUTES
uint_fast32_t
simde_x_ternarylogic_0x7b_impl_(uint_fast32_t a, uint_fast32_t b, uint_fast32_t c) {
  const uint_fast32_t t0 = ~b;
  const uint_fast32_t t1 = a ^ c;
  const uint_fast32_t t2 = t0 | t1;
  return t2;
}

SIMDE_FUNCTION_ATTRIBUTES
uint_fast32_t
simde_x_ternarylogic_0x7c_impl_(uint_fast32_t a, uint_fast32_t b, uint_fast32_t c) {
  const uint_fast32_t t0 = ~c;
  const uint_fast32_t t1 = t0 & a;
  const uint_fast32_t t2 = a ^ b;
  const uint_fast32_t t3 = t1 | t2;
  return t3;
}

SIMDE_FUNCTION_ATTRIBUTES
uint_fast32_t
simde_x_ternarylogic_0x7d_impl_(uint_fast32_t a, uint_fast32_t b, uint_fast32_t c) {
  const uint_fast32_t t0 = ~c;
  const uint_fast32_t t1 = a ^ b;
  const uint_fast32_t t2 = t0 | t1;
  return t2;
}

SIMDE_FUNCTION_ATTRIBUTES
uint_fast32_t
simde_x_ternarylogic_0x7e_impl_(uint_fast32_t a, uint_fast32_t b, uint_fast32_t c) {
  const uint_fast32_t t0 = a ^ b;
  const uint_fast32_t t1 = a ^ c;
  const uint_fast32_t t2 = t0 | t1;
  return t2;
}

SIMDE_FUNCTION_ATTRIBUTES
uint_fast32_t
simde_x_ternarylogic_0x7f_impl_(uint_fast32_t a, uint_fast32_t b, uint_fast32_t c) {
  const uint_fast32_t t0 = a & b;
  const uint_fast32_t t1 = t0 & c;
  const uint_fast32_t c1 = ~HEDLEY_STATIC_CAST(uint_fast32_t, 0);
  const uint_fast32_t t2 = t1 ^ c1;
  return t2;
}

SIMDE_FUNCTION_ATTRIBUTES
uint_fast32_t
simde_x_ternarylogic_0x80_impl_(uint_fast32_t a, uint_fast32_t b, uint_fast32_t c) {
  const uint_fast32_t t0 = b & c;
  const uint_fast32_t t1 = a & t0;
  return t1;
}

SIMDE_FUNCTION_ATTRIBUTES
uint_fast32_t
simde_x_ternarylogic_0x81_impl_(uint_fast32_t a, uint_fast32_t b, uint_fast32_t c) {
  const uint_fast32_t t0 = a ^ c;
  const uint_fast32_t t1 = ~t0;
  const uint_fast32_t t2 = ~b;
  const uint_fast32_t t3 = a ^ t2;
  const uint_fast32_t t4 = t1 & t3;
  return t4;
}

SIMDE_FUNCTION_ATTRIBUTES
uint_fast32_t
simde_x_ternarylogic_0x82_impl_(uint_fast32_t a, uint_fast32_t b, uint_fast32_t c) {
  const uint_fast32_t t0 = b ^ a;
  const uint_fast32_t t1 = ~t0;
  const uint_fast32_t t2 = c & t1;
  return t2;
}

SIMDE_FUNCTION_ATTRIBUTES
uint_fast32_t
simde_x_ternarylogic_0x83_impl_(uint_fast32_t a, uint_fast32_t b, uint_fast32_t c) {
  const uint_fast32_t t0 = a ^ b;
  const uint_fast32_t t1 = ~t0;
  const uint_fast32_t t2 = ~a;
  const uint_fast32_t t3 = t2 | c;
  const uint_fast32_t t4 = t1 & t3;
  return t4;
}

SIMDE_FUNCTION_ATTRIBUTES
uint_fast32_t
simde_x_ternarylogic_0x84_impl_(uint_fast32_t a, uint_fast32_t b, uint_fast32_t c) {
  const uint_fast32_t t0 = a ^ c;
  const uint_fast32_t t1 = ~t0;
  const uint_fast32_t t2 = b & t1;
  return t2;
}

SIMDE_FUNCTION_ATTRIBUTES
uint_fast32_t
simde_x_ternarylogic_0x85_impl_(uint_fast32_t a, uint_fast32_t b, uint_fast32_t c) {
  const uint_fast32_t t0 = a ^ c;
  const uint_fast32_t t1 = ~t0;
  const uint_fast32_t t2 = ~c;
  const uint_fast32_t t3 = t2 | b;
  const uint_fast32_t t4 = t1 & t3;
  return t4;
}

SIMDE_FUNCTION_ATTRIBUTES
uint_fast32_t
simde_x_ternarylogic_0x86_impl_(uint_fast32_t a, uint_fast32_t b, uint_fast32_t c) {
  const uint_fast32_t t0 = b | c;
  const uint_fast32_t t1 = a ^ b;
  const uint_fast32_t t2 = c ^ t1;
  const uint_fast32_t t3 = t0 & t2;
  return t3;
}

SIMDE_FUNCTION_ATTRIBUTES
uint_fast32_t
simde_x_ternarylogic_0x87_impl_(uint_fast32_t a, uint_fast32_t b, uint_fast32_t c) {
  const uint_fast32_t t0 = b & c;
  const uint_fast32_t t1 = a ^ t0;
  const uint_fast32_t t2 = ~t1;
  return t2;
}

SIMDE_FUNCTION_ATTRIBUTES
uint_fast32_t
simde_x_ternarylogic_0x88_impl_(uint_fast32_t a, uint_fast32_t b, uint_fast32_t c) {
  HEDLEY_STATIC_CAST(void, a);
  const uint_fast32_t t0 = c & b;
  return t0;
}

SIMDE_FUNCTION_ATTRIBUTES
uint_fast32_t
simde_x_ternarylogic_0x89_impl_(uint_fast32_t a, uint_fast32_t b, uint_fast32_t c) {
  const uint_fast32_t t0 = b ^ c;
  const uint_fast32_t t1 = ~t0;
  const uint_fast32_t t2 = ~a;
  const uint_fast32_t t3 = t2 | b;
  const uint_fast32_t t4 = t1 & t3;
  return t4;
}

SIMDE_FUNCTION_ATTRIBUTES
uint_fast32_t
simde_x_ternarylogic_0x8a_impl_(uint_fast32_t a, uint_fast32_t b, uint_fast32_t c) {
  const uint_fast32_t t0 = ~a;
  const uint_fast32_t t1 = t0 | b;
  const uint_fast32_t t2 = c & t1;
  return t2;
}

SIMDE_FUNCTION_ATTRIBUTES
uint_fast32_t
simde_x_ternarylogic_0x8b_impl_(uint_fast32_t a, uint_fast32_t b, uint_fast32_t c) {
  const uint_fast32_t t0 = ~a;
  const uint_fast32_t t1 = t0 | b;
  const uint_fast32_t t2 = ~b;
  const uint_fast32_t t3 = t2 | c;
  const uint_fast32_t t4 = t1 & t3;
  return t4;
}

SIMDE_FUNCTION_ATTRIBUTES
uint_fast32_t
simde_x_ternarylogic_0x8c_impl_(uint_fast32_t a, uint_fast32_t b, uint_fast32_t c) {
  const uint_fast32_t t0 = ~a;
  const uint_fast32_t t1 = t0 | c;
  const uint_fast32_t t2 = b & t1;
  return t2;
}

SIMDE_FUNCTION_ATTRIBUTES
uint_fast32_t
simde_x_ternarylogic_0x8d_impl_(uint_fast32_t a, uint_fast32_t b, uint_fast32_t c) {
  const uint_fast32_t t0 = ~c;
  const uint_fast32_t t1 = t0 | b;
  const uint_fast32_t t2 = ~a;
  const uint_fast32_t t3 = t2 | c;
  const uint_fast32_t t4 = t1 & t3;
  return t4;
}

SIMDE_FUNCTION_ATTRIBUTES
uint_fast32_t
simde_x_ternarylogic_0x8e_impl_(uint_fast32_t a, uint_fast32_t b, uint_fast32_t c) {
  const uint_fast32_t t0 = b & c;
  const uint_fast32_t t1 = ~a;
  const uint_fast32_t t2 = b ^ c;
  const uint_fast32_t t3 = t1 & t2;
  const uint_fast32_t t4 = t0 | t3;
  return t4;
}

SIMDE_FUNCTION_ATTRIBUTES
uint_fast32_t
simde_x_ternarylogic_0x8f_impl_(uint_fast32_t a, uint_fast32_t b, uint_fast32_t c) {
  const uint_fast32_t t0 = ~a;
  const uint_fast32_t t1 = b & c;
  const uint_fast32_t t2 = t0 | t1;
  return t2;
}

SIMDE_FUNCTION_ATTRIBUTES
uint_fast32_t
simde_x_ternarylogic_0x90_impl_(uint_fast32_t a, uint_fast32_t b, uint_fast32_t c) {
  const uint_fast32_t t0 = b ^ c;
  const uint_fast32_t t1 = ~t0;
  const uint_fast32_t t2 = a & t1;
  return t2;
}

SIMDE_FUNCTION_ATTRIBUTES
uint_fast32_t
simde_x_ternarylogic_0x91_impl_(uint_fast32_t a, uint_fast32_t b, uint_fast32_t c) {
  const uint_fast32_t t0 = b ^ c;
  const uint_fast32_t t1 = ~t0;
  const uint_fast32_t t2 = ~b;
  const uint_fast32_t t3 = t2 | a;
  const uint_fast32_t t4 = t1 & t3;
  return t4;
}

SIMDE_FUNCTION_ATTRIBUTES
uint_fast32_t
simde_x_ternarylogic_0x92_impl_(uint_fast32_t a, uint_fast32_t b, uint_fast32_t c) {
  const uint_fast32_t t0 = a | c;
  const uint_fast32_t t1 = a ^ b;
  const uint_fast32_t t2 = c ^ t1;
  const uint_fast32_t t3 = t0 & t2;
  return t3;
}

SIMDE_FUNCTION_ATTRIBUTES
uint_fast32_t
simde_x_ternarylogic_0x93_impl_(uint_fast32_t a, uint_fast32_t b, uint_fast32_t c) {
  const uint_fast32_t t0 = a & c;
  const uint_fast32_t t1 = b ^ t0;
  const uint_fast32_t t2 = ~t1;
  return t2;
}

SIMDE_FUNCTION_ATTRIBUTES
uint_fast32_t
simde_x_ternarylogic_0x94_impl_(uint_fast32_t a, uint_fast32_t b, uint_fast32_t c) {
  const uint_fast32_t t0 = a | b;
  const uint_fast32_t t1 = a ^ c;
  const uint_fast32_t t2 = b ^ t1;
  const uint_fast32_t t3 = t0 & t2;
  return t3;
}

SIMDE_FUNCTION_ATTRIBUTES
uint_fast32_t
simde_x_ternarylogic_0x95_impl_(uint_fast32_t a, uint_fast32_t b, uint_fast32_t c) {
  const uint_fast32_t t0 = b & a;
  const uint_fast32_t t1 = c ^ t0;
  const uint_fast32_t t2 = ~t1;
  return t2;
}

SIMDE_FUNCTION_ATTRIBUTES
uint_fast32_t
simde_x_ternarylogic_0x96_impl_(uint_fast32_t a, uint_fast32_t b, uint_fast32_t c) {
  const uint_fast32_t t0 = b ^ c;
  const uint_fast32_t t1 = a ^ t0;
  return t1;
}

SIMDE_FUNCTION_ATTRIBUTES
uint_fast32_t
simde_x_ternarylogic_0x97_impl_(uint_fast32_t a, uint_fast32_t b, uint_fast32_t c) {
  const uint_fast32_t t0 = ~b;
  const uint_fast32_t t1 = t0 | a;
  const uint_fast32_t t2 = t1 ^ a;
  const uint_fast32_t t3 = b ^ c;
  const uint_fast32_t t4 = a ^ t3;
  const uint_fast32_t t5 = t2 | t4;
  return t5;
}

SIMDE_FUNCTION_ATTRIBUTES
uint_fast32_t
simde_x_ternarylogic_0x98_impl_(uint_fast32_t a, uint_fast32_t b, uint_fast32_t c) {
  const uint_fast32_t t0 = b ^ c;
  const uint_fast32_t t1 = ~t0;
  const uint_fast32_t t2 = a | b;
  const uint_fast32_t t3 = t1 & t2;
  return t3;
}

SIMDE_FUNCTION_ATTRIBUTES
uint_fast32_t
simde_x_ternarylogic_0x99_impl_(uint_fast32_t a, uint_fast32_t b, uint_fast32_t c) {
  HEDLEY_STATIC_CAST(void, a);
  const uint_fast32_t t0 = c ^ b;
  const uint_fast32_t t1 = ~t0;
  return t1;
}

SIMDE_FUNCTION_ATTRIBUTES
uint_fast32_t
simde_x_ternarylogic_0x9a_impl_(uint_fast32_t a, uint_fast32_t b, uint_fast32_t c) {
  const uint_fast32_t t0 = ~b;
  const uint_fast32_t t1 = t0 & a;
  const uint_fast32_t t2 = t1 ^ c;
  return t2;
}

SIMDE_FUNCTION_ATTRIBUTES
uint_fast32_t
simde_x_ternarylogic_0x9b_impl_(uint_fast32_t a, uint_fast32_t b, uint_fast32_t c) {
  const uint_fast32_t t0 = b ^ c;
  const uint_fast32_t t1 = ~t0;
  const uint_fast32_t t2 = ~a;
  const uint_fast32_t t3 = t2 & c;
  const uint_fast32_t t4 = t1 | t3;
  return t4;
}

SIMDE_FUNCTION_ATTRIBUTES
uint_fast32_t
simde_x_ternarylogic_0x9c_impl_(uint_fast32_t a, uint_fast32_t b, uint_fast32_t c) {
  const uint_fast32_t t0 = ~c;
  const uint_fast32_t t1 = t0 & a;
  const uint_fast32_t t2 = t1 ^ b;
  return t2;
}

SIMDE_FUNCTION_ATTRIBUTES
uint_fast32_t
simde_x_ternarylogic_0x9d_impl_(uint_fast32_t a, uint_fast32_t b, uint_fast32_t c) {
  const uint_fast32_t t0 = b ^ c;
  const uint_fast32_t t1 = ~t0;
  const uint_fast32_t t2 = ~a;
  const uint_fast32_t t3 = t2 & b;
  const uint_fast32_t t4 = t1 | t3;
  return t4;
}

SIMDE_FUNCTION_ATTRIBUTES
uint_fast32_t
simde_x_ternarylogic_0x9e_impl_(uint_fast32_t a, uint_fast32_t b, uint_fast32_t c) {
  const uint_fast32_t t0 = b & c;
  const uint_fast32_t t1 = a ^ b;
  const uint_fast32_t t2 = c ^ t1;
  const uint_fast32_t t3 = t0 | t2;
  return t3;
}

SIMDE_FUNCTION_ATTRIBUTES
uint_fast32_t
simde_x_ternarylogic_0x9f_impl_(uint_fast32_t a, uint_fast32_t b, uint_fast32_t c) {
  const uint_fast32_t t0 = b ^ c;
  const uint_fast32_t t1 = a & t0;
  const uint_fast32_t t2 = ~t1;
  return t2;
}

SIMDE_FUNCTION_ATTRIBUTES
uint_fast32_t
simde_x_ternarylogic_0xa0_impl_(uint_fast32_t a, uint_fast32_t b, uint_fast32_t c) {
  HEDLEY_STATIC_CAST(void, b);
  const uint_fast32_t t0 = c & a;
  return t0;
}

SIMDE_FUNCTION_ATTRIBUTES
uint_fast32_t
simde_x_ternarylogic_0xa1_impl_(uint_fast32_t a, uint_fast32_t b, uint_fast32_t c) {
  const uint_fast32_t t0 = a ^ c;
  const uint_fast32_t t1 = ~t0;
  const uint_fast32_t t2 = ~b;
  const uint_fast32_t t3 = t2 | a;
  const uint_fast32_t t4 = t1 & t3;
  return t4;
}

SIMDE_FUNCTION_ATTRIBUTES
uint_fast32_t
simde_x_ternarylogic_0xa2_impl_(uint_fast32_t a, uint_fast32_t b, uint_fast32_t c) {
  const uint_fast32_t t0 = ~b;
  const uint_fast32_t t1 = a | t0;
  const uint_fast32_t t2 = c & t1;
  return t2;
}

SIMDE_FUNCTION_ATTRIBUTES
uint_fast32_t
simde_x_ternarylogic_0xa3_impl_(uint_fast32_t a, uint_fast32_t b, uint_fast32_t c) {
  const uint_fast32_t t0 = ~b;
  const uint_fast32_t t1 = t0 | a;
  const uint_fast32_t t2 = ~a;
  const uint_fast32_t t3 = t2 | c;
  const uint_fast32_t t4 = t1 & t3;
  return t4;
}

SIMDE_FUNCTION_ATTRIBUTES
uint_fast32_t
simde_x_ternarylogic_0xa4_impl_(uint_fast32_t a, uint_fast32_t b, uint_fast32_t c) {
  const uint_fast32_t t0 = a ^ c;
  const uint_fast32_t t1 = ~t0;
  const uint_fast32_t t2 = a | b;
  const uint_fast32_t t3 = t1 & t2;
  return t3;
}

SIMDE_FUNCTION_ATTRIBUTES
uint_fast32_t
simde_x_ternarylogic_0xa5_impl_(uint_fast32_t a, uint_fast32_t b, uint_fast32_t c) {
  HEDLEY_STATIC_CAST(void, b);
  const uint_fast32_t t0 = c ^ a;
  const uint_fast32_t t1 = ~t0;
  return t1;
}

SIMDE_FUNCTION_ATTRIBUTES
uint_fast32_t
simde_x_ternarylogic_0xa6_impl_(uint_fast32_t a, uint_fast32_t b, uint_fast32_t c) {
  const uint_fast32_t t0 = ~a;
  const uint_fast32_t t1 = t0 & b;
  const uint_fast32_t t2 = t1 ^ c;
  return t2;
}

SIMDE_FUNCTION_ATTRIBUTES
uint_fast32_t
simde_x_ternarylogic_0xa7_impl_(uint_fast32_t a, uint_fast32_t b, uint_fast32_t c) {
  const uint_fast32_t t0 = a ^ c;
  const uint_fast32_t t1 = ~t0;
  const uint_fast32_t t2 = ~b;
  const uint_fast32_t t3 = t2 & c;
  const uint_fast32_t t4 = t1 | t3;
  return t4;
}

SIMDE_FUNCTION_ATTRIBUTES
uint_fast32_t
simde_x_ternarylogic_0xa8_impl_(uint_fast32_t a, uint_fast32_t b, uint_fast32_t c) {
  const uint_fast32_t t0 = a | b;
  const uint_fast32_t t1 = c & t0;
  return t1;
}

SIMDE_FUNCTION_ATTRIBUTES
uint_fast32_t
simde_x_ternarylogic_0xa9_impl_(uint_fast32_t a, uint_fast32_t b, uint_fast32_t c) {
  const uint_fast32_t t0 = b | a;
  const uint_fast32_t t1 = c ^ t0;
  const uint_fast32_t t2 = ~t1;
  return t2;
}

SIMDE_FUNCTION_ATTRIBUTES
uint_fast32_t
simde_x_ternarylogic_0xaa_impl_(uint_fast32_t a, uint_fast32_t b, uint_fast32_t c) {
  HEDLEY_STATIC_CAST(void, a);
  HEDLEY_STATIC_CAST(void, b);
  return c;
}

SIMDE_FUNCTION_ATTRIBUTES
uint_fast32_t
simde_x_ternarylogic_0xab_impl_(uint_fast32_t a, uint_fast32_t b, uint_fast32_t c) {
  const uint_fast32_t t0 = b | a;
  const uint_fast32_t t1 = ~t0;
  const uint_fast32_t t2 = c | t1;
  return t2;
}

SIMDE_FUNCTION_ATTRIBUTES
uint_fast32_t
simde_x_ternarylogic_0xac_impl_(uint_fast32_t a, uint_fast32_t b, uint_fast32_t c) {
  const uint_fast32_t t0 = a & c;
  const uint_fast32_t t1 = ~a;
  const uint_fast32_t t2 = t1 & b;
  const uint_fast32_t t3 = t0 | t2;
  return t3;
}

SIMDE_FUNCTION_ATTRIBUTES
uint_fast32_t
simde_x_ternarylogic_0xad_impl_(uint_fast32_t a, uint_fast32_t b, uint_fast32_t c) {
  const uint_fast32_t t0 = a ^ c;
  const uint_fast32_t t1 = ~t0;
  const uint_fast32_t t2 = b & c;
  const uint_fast32_t t3 = t1 | t2;
  return t3;
}

SIMDE_FUNCTION_ATTRIBUTES
uint_fast32_t
simde_x_ternarylogic_0xae_impl_(uint_fast32_t a, uint_fast32_t b, uint_fast32_t c) {
  const uint_fast32_t t0 = ~a;
  const uint_fast32_t t1 = t0 & b;
  const uint_fast32_t t2 = t1 | c;
  return t2;
}

SIMDE_FUNCTION_ATTRIBUTES
uint_fast32_t
simde_x_ternarylogic_0xaf_impl_(uint_fast32_t a, uint_fast32_t b, uint_fast32_t c) {
  HEDLEY_STATIC_CAST(void, b);
  const uint_fast32_t t0 = ~a;
  const uint_fast32_t t1 = c | t0;
  return t1;
}

SIMDE_FUNCTION_ATTRIBUTES
uint_fast32_t
simde_x_ternarylogic_0xb0_impl_(uint_fast32_t a, uint_fast32_t b, uint_fast32_t c) {
  const uint_fast32_t t0 = ~b;
  const uint_fast32_t t1 = t0 | c;
  const uint_fast32_t t2 = a & t1;
  return t2;
}

SIMDE_FUNCTION_ATTRIBUTES
uint_fast32_t
simde_x_ternarylogic_0xb1_impl_(uint_fast32_t a, uint_fast32_t b, uint_fast32_t c) {
  const uint_fast32_t t0 = ~c;
  const uint_fast32_t t1 = t0 | a;
  const uint_fast32_t t2 = ~b;
  const uint_fast32_t t3 = t2 | c;
  const uint_fast32_t t4 = t1 & t3;
  return t4;
}

SIMDE_FUNCTION_ATTRIBUTES
uint_fast32_t
simde_x_ternarylogic_0xb2_impl_(uint_fast32_t a, uint_fast32_t b, uint_fast32_t c) {
  const uint_fast32_t t0 = a & c;
  const uint_fast32_t t1 = b & t0;
  const uint_fast32_t t2 = ~b;
  const uint_fast32_t t3 = a | c;
  const uint_fast32_t t4 = t2 & t3;
  const uint_fast32_t t5 = t1 | t4;
  return t5;
}

SIMDE_FUNCTION_ATTRIBUTES
uint_fast32_t
simde_x_ternarylogic_0xb3_impl_(uint_fast32_t a, uint_fast32_t b, uint_fast32_t c) {
  const uint_fast32_t t0 = ~b;
  const uint_fast32_t t1 = a & c;
  const uint_fast32_t t2 = t0 | t1;
  return t2;
}

SIMDE_FUNCTION_ATTRIBUTES
uint_fast32_t
simde_x_ternarylogic_0xb4_impl_(uint_fast32_t a, uint_fast32_t b, uint_fast32_t c) {
  const uint_fast32_t t0 = ~c;
  const uint_fast32_t t1 = t0 & b;
  const uint_fast32_t t2 = t1 ^ a;
  return t2;
}

SIMDE_FUNCTION_ATTRIBUTES
uint_fast32_t
simde_x_ternarylogic_0xb5_impl_(uint_fast32_t a, uint_fast32_t b, uint_fast32_t c) {
  const uint_fast32_t t0 = a ^ c;
  const uint_fast32_t t1 = ~t0;
  const uint_fast32_t t2 = ~b;
  const uint_fast32_t t3 = t2 & a;
  const uint_fast32_t t4 = t1 | t3;
  return t4;
}

SIMDE_FUNCTION_ATTRIBUTES
uint_fast32_t
simde_x_ternarylogic_0xb6_impl_(uint_fast32_t a, uint_fast32_t b, uint_fast32_t c) {
  const uint_fast32_t t0 = a & c;
  const uint_fast32_t t1 = a ^ b;
  const uint_fast32_t t2 = c ^ t1;
  const uint_fast32_t t3 = t0 | t2;
  return t3;
}

SIMDE_FUNCTION_ATTRIBUTES
uint_fast32_t
simde_x_ternarylogic_0xb7_impl_(uint_fast32_t a, uint_fast32_t b, uint_fast32_t c) {
  const uint_fast32_t t0 = a ^ c;
  const uint_fast32_t t1 = b & t0;
  const uint_fast32_t t2 = ~t1;
  return t2;
}

SIMDE_FUNCTION_ATTRIBUTES
uint_fast32_t
simde_x_ternarylogic_0xb8_impl_(uint_fast32_t a, uint_fast32_t b, uint_fast32_t c) {
  const uint_fast32_t t0 = b & c;
  const uint_fast32_t t1 = ~b;
  const uint_fast32_t t2 = t1 & a;
  const uint_fast32_t t3 = t0 | t2;
  return t3;
}

SIMDE_FUNCTION_ATTRIBUTES
uint_fast32_t
simde_x_ternarylogic_0xb9_impl_(uint_fast32_t a, uint_fast32_t b, uint_fast32_t c) {
  const uint_fast32_t t0 = b ^ c;
  const uint_fast32_t t1 = ~t0;
  const uint_fast32_t t2 = a & c;
  const uint_fast32_t t3 = t1 | t2;
  return t3;
}

SIMDE_FUNCTION_ATTRIBUTES
uint_fast32_t
simde_x_ternarylogic_0xba_impl_(uint_fast32_t a, uint_fast32_t b, uint_fast32_t c) {
  const uint_fast32_t t0 = ~b;
  const uint_fast32_t t1 = t0 & a;
  const uint_fast32_t t2 = t1 | c;
  return t2;
}

SIMDE_FUNCTION_ATTRIBUTES
uint_fast32_t
simde_x_ternarylogic_0xbb_impl_(uint_fast32_t a, uint_fast32_t b, uint_fast32_t c) {
  HEDLEY_STATIC_CAST(void, a);
  const uint_fast32_t t0 = ~b;
  const uint_fast32_t t1 = c | t0;
  return t1;
}

SIMDE_FUNCTION_ATTRIBUTES
uint_fast32_t
simde_x_ternarylogic_0xbc_impl_(uint_fast32_t a, uint_fast32_t b, uint_fast32_t c) {
  const uint_fast32_t t0 = a & c;
  const uint_fast32_t t1 = a ^ b;
  const uint_fast32_t t2 = t0 | t1;
  return t2;
}

SIMDE_FUNCTION_ATTRIBUTES
uint_fast32_t
simde_x_ternarylogic_0xbd_impl_(uint_fast32_t a, uint_fast32_t b, uint_fast32_t c) {
  const uint_fast32_t t0 = a ^ c;
  const uint_fast32_t t1 = ~t0;
  const uint_fast32_t t2 = a ^ b;
  const uint_fast32_t t3 = t1 | t2;
  return t3;
}

SIMDE_FUNCTION_ATTRIBUTES
uint_fast32_t
simde_x_ternarylogic_0xbe_impl_(uint_fast32_t a, uint_fast32_t b, uint_fast32_t c) {
  const uint_fast32_t t0 = b ^ a;
  const uint_fast32_t t1 = c | t0;
  return t1;
}

SIMDE_FUNCTION_ATTRIBUTES
uint_fast32_t
simde_x_ternarylogic_0xbf_impl_(uint_fast32_t a, uint_fast32_t b, uint_fast32_t c) {
  const uint_fast32_t t0 = b & a;
  const uint_fast32_t t1 = ~t0;
  const uint_fast32_t t2 = c | t1;
  return t2;
}

SIMDE_FUNCTION_ATTRIBUTES
uint_fast32_t
simde_x_ternarylogic_0xc0_impl_(uint_fast32_t a, uint_fast32_t b, uint_fast32_t c) {
  HEDLEY_STATIC_CAST(void, c);
  const uint_fast32_t t0 = b & a;
  return t0;
}

SIMDE_FUNCTION_ATTRIBUTES
uint_fast32_t
simde_x_ternarylogic_0xc1_impl_(uint_fast32_t a, uint_fast32_t b, uint_fast32_t c) {
  const uint_fast32_t t0 = a ^ b;
  const uint_fast32_t t1 = ~t0;
  const uint_fast32_t t2 = ~c;
  const uint_fast32_t t3 = t2 | a;
  const uint_fast32_t t4 = t1 & t3;
  return t4;
}

SIMDE_FUNCTION_ATTRIBUTES
uint_fast32_t
simde_x_ternarylogic_0xc2_impl_(uint_fast32_t a, uint_fast32_t b, uint_fast32_t c) {
  const uint_fast32_t t0 = a ^ b;
  const uint_fast32_t t1 = ~t0;
  const uint_fast32_t t2 = a | c;
  const uint_fast32_t t3 = t1 & t2;
  return t3;
}

SIMDE_FUNCTION_ATTRIBUTES
uint_fast32_t
simde_x_ternarylogic_0xc3_impl_(uint_fast32_t a, uint_fast32_t b, uint_fast32_t c) {
  HEDLEY_STATIC_CAST(void, c);
  const uint_fast32_t t0 = b ^ a;
  const uint_fast32_t t1 = ~t0;
  return t1;
}

SIMDE_FUNCTION_ATTRIBUTES
uint_fast32_t
simde_x_ternarylogic_0xc4_impl_(uint_fast32_t a, uint_fast32_t b, uint_fast32_t c) {
  const uint_fast32_t t0 = ~c;
  const uint_fast32_t t1 = t0 | a;
  const uint_fast32_t t2 = b & t1;
  return t2;
}

SIMDE_FUNCTION_ATTRIBUTES
uint_fast32_t
simde_x_ternarylogic_0xc5_impl_(uint_fast32_t a, uint_fast32_t b, uint_fast32_t c) {
  const uint_fast32_t t0 = ~c;
  const uint_fast32_t t1 = t0 | a;
  const uint_fast32_t t2 = ~a;
  const uint_fast32_t t3 = t2 | b;
  const uint_fast32_t t4 = t1 & t3;
  return t4;
}

SIMDE_FUNCTION_ATTRIBUTES
uint_fast32_t
simde_x_ternarylogic_0xc6_impl_(uint_fast32_t a, uint_fast32_t b, uint_fast32_t c) {
  const uint_fast32_t t0 = ~a;
  const uint_fast32_t t1 = t0 & c;
  const uint_fast32_t t2 = t1 ^ b;
  return t2;
}

SIMDE_FUNCTION_ATTRIBUTES
uint_fast32_t
simde_x_ternarylogic_0xc7_impl_(uint_fast32_t a, uint_fast32_t b, uint_fast32_t c) {
  const uint_fast32_t t0 = a ^ b;
  const uint_fast32_t t1 = ~t0;
  const uint_fast32_t t2 = ~c;
  const uint_fast32_t t3 = t2 & b;
  const uint_fast32_t t4 = t1 | t3;
  return t4;
}

SIMDE_FUNCTION_ATTRIBUTES
uint_fast32_t
simde_x_ternarylogic_0xc8_impl_(uint_fast32_t a, uint_fast32_t b, uint_fast32_t c) {
  const uint_fast32_t t0 = a | c;
  const uint_fast32_t t1 = b & t0;
  return t1;
}

SIMDE_FUNCTION_ATTRIBUTES
uint_fast32_t
simde_x_ternarylogic_0xc9_impl_(uint_fast32_t a, uint_fast32_t b, uint_fast32_t c) {
  const uint_fast32_t t0 = a | c;
  const uint_fast32_t t1 = b ^ t0;
  const uint_fast32_t t2 = ~t1;
  return t2;
}

SIMDE_FUNCTION_ATTRIBUTES
uint_fast32_t
simde_x_ternarylogic_0xca_impl_(uint_fast32_t a, uint_fast32_t b, uint_fast32_t c) {
  const uint_fast32_t t0 = a & b;
  const uint_fast32_t t1 = ~a;
  const uint_fast32_t t2 = t1 & c;
  const uint_fast32_t t3 = t0 | t2;
  return t3;
}

SIMDE_FUNCTION_ATTRIBUTES
uint_fast32_t
simde_x_ternarylogic_0xcb_impl_(uint_fast32_t a, uint_fast32_t b, uint_fast32_t c) {
  const uint_fast32_t t0 = a ^ b;
  const uint_fast32_t t1 = ~t0;
  const uint_fast32_t t2 = b & c;
  const uint_fast32_t t3 = t1 | t2;
  return t3;
}

SIMDE_FUNCTION_ATTRIBUTES
uint_fast32_t
simde_x_ternarylogic_0xcc_impl_(uint_fast32_t a, uint_fast32_t b, uint_fast32_t c) {
  HEDLEY_STATIC_CAST(void, a);
  HEDLEY_STATIC_CAST(void, c);
  return b;
}

SIMDE_FUNCTION_ATTRIBUTES
uint_fast32_t
simde_x_ternarylogic_0xcd_impl_(uint_fast32_t a, uint_fast32_t b, uint_fast32_t c) {
  const uint_fast32_t t0 = a | c;
  const uint_fast32_t t1 = ~t0;
  const uint_fast32_t t2 = b | t1;
  return t2;
}

SIMDE_FUNCTION_ATTRIBUTES
uint_fast32_t
simde_x_ternarylogic_0xce_impl_(uint_fast32_t a, uint_fast32_t b, uint_fast32_t c) {
  const uint_fast32_t t0 = ~a;
  const uint_fast32_t t1 = t0 & c;
  const uint_fast32_t t2 = t1 | b;
  return t2;
}

SIMDE_FUNCTION_ATTRIBUTES
uint_fast32_t
simde_x_ternarylogic_0xcf_impl_(uint_fast32_t a, uint_fast32_t b, uint_fast32_t c) {
  HEDLEY_STATIC_CAST(void, c);
  const uint_fast32_t t0 = ~a;
  const uint_fast32_t t1 = b | t0;
  return t1;
}

SIMDE_FUNCTION_ATTRIBUTES
uint_fast32_t
simde_x_ternarylogic_0xd0_impl_(uint_fast32_t a, uint_fast32_t b, uint_fast32_t c) {
  const uint_fast32_t t0 = ~c;
  const uint_fast32_t t1 = b | t0;
  const uint_fast32_t t2 = a & t1;
  return t2;
}

SIMDE_FUNCTION_ATTRIBUTES
uint_fast32_t
simde_x_ternarylogic_0xd1_impl_(uint_fast32_t a, uint_fast32_t b, uint_fast32_t c) {
  const uint_fast32_t t0 = b | c;
  const uint_fast32_t t1 = ~t0;
  const uint_fast32_t t2 = a & b;
  const uint_fast32_t t3 = t1 | t2;
  return t3;
}

SIMDE_FUNCTION_ATTRIBUTES
uint_fast32_t
simde_x_ternarylogic_0xd2_impl_(uint_fast32_t a, uint_fast32_t b, uint_fast32_t c) {
  const uint_fast32_t t0 = ~b;
  const uint_fast32_t t1 = t0 & c;
  const uint_fast32_t t2 = t1 ^ a;
  return t2;
}

SIMDE_FUNCTION_ATTRIBUTES
uint_fast32_t
simde_x_ternarylogic_0xd3_impl_(uint_fast32_t a, uint_fast32_t b, uint_fast32_t c) {
  const uint_fast32_t t0 = a ^ b;
  const uint_fast32_t t1 = ~t0;
  const uint_fast32_t t2 = ~c;
  const uint_fast32_t t3 = t2 & a;
  const uint_fast32_t t4 = t1 | t3;
  return t4;
}

SIMDE_FUNCTION_ATTRIBUTES
uint_fast32_t
simde_x_ternarylogic_0xd4_impl_(uint_fast32_t a, uint_fast32_t b, uint_fast32_t c) {
  const uint_fast32_t t0 = ~c;
  const uint_fast32_t t1 = b & t0;
  const uint_fast32_t t2 = b ^ c;
  const uint_fast32_t t3 = ~t2;
  const uint_fast32_t t4 = a & t3;
  const uint_fast32_t t5 = t1 | t4;
  return t5;
}

SIMDE_FUNCTION_ATTRIBUTES
uint_fast32_t
simde_x_ternarylogic_0xd5_impl_(uint_fast32_t a, uint_fast32_t b, uint_fast32_t c) {
  const uint_fast32_t t0 = ~c;
  const uint_fast32_t t1 = a & b;
  const uint_fast32_t t2 = t0 | t1;
  return t2;
}

SIMDE_FUNCTION_ATTRIBUTES
uint_fast32_t
simde_x_ternarylogic_0xd6_impl_(uint_fast32_t a, uint_fast32_t b, uint_fast32_t c) {
  const uint_fast32_t t0 = a & b;
  const uint_fast32_t t1 = a ^ c;
  const uint_fast32_t t2 = b ^ t1;
  const uint_fast32_t t3 = t0 | t2;
  return t3;
}

SIMDE_FUNCTION_ATTRIBUTES
uint_fast32_t
simde_x_ternarylogic_0xd7_impl_(uint_fast32_t a, uint_fast32_t b, uint_fast32_t c) {
  const uint_fast32_t t0 = b ^ a;
  const uint_fast32_t t1 = c & t0;
  const uint_fast32_t t2 = ~t1;
  return t2;
}

SIMDE_FUNCTION_ATTRIBUTES
uint_fast32_t
simde_x_ternarylogic_0xd8_impl_(uint_fast32_t a, uint_fast32_t b, uint_fast32_t c) {
  const uint_fast32_t t0 = c & b;
  const uint_fast32_t t1 = ~c;
  const uint_fast32_t t2 = t1 & a;
  const uint_fast32_t t3 = t0 | t2;
  return t3;
}

SIMDE_FUNCTION_ATTRIBUTES
uint_fast32_t
simde_x_ternarylogic_0xd9_impl_(uint_fast32_t a, uint_fast32_t b, uint_fast32_t c) {
  const uint_fast32_t t0 = b ^ c;
  const uint_fast32_t t1 = ~t0;
  const uint_fast32_t t2 = a & b;
  const uint_fast32_t t3 = t1 | t2;
  return t3;
}

SIMDE_FUNCTION_ATTRIBUTES
uint_fast32_t
simde_x_ternarylogic_0xda_impl_(uint_fast32_t a, uint_fast32_t b, uint_fast32_t c) {
  const uint_fast32_t t0 = a & b;
  const uint_fast32_t t1 = a ^ c;
  const uint_fast32_t t2 = t0 | t1;
  return t2;
}

SIMDE_FUNCTION_ATTRIBUTES
uint_fast32_t
simde_x_ternarylogic_0xdb_impl_(uint_fast32_t a, uint_fast32_t b, uint_fast32_t c) {
  const uint_fast32_t t0 = a ^ b;
  const uint_fast32_t t1 = ~t0;
  const uint_fast32_t t2 = a ^ c;
  const uint_fast32_t t3 = t1 | t2;
  return t3;
}

SIMDE_FUNCTION_ATTRIBUTES
uint_fast32_t
simde_x_ternarylogic_0xdc_impl_(uint_fast32_t a, uint_fast32_t b, uint_fast32_t c) {
  const uint_fast32_t t0 = ~c;
  const uint_fast32_t t1 = t0 & a;
  const uint_fast32_t t2 = t1 | b;
  return t2;
}

SIMDE_FUNCTION_ATTRIBUTES
uint_fast32_t
simde_x_ternarylogic_0xdd_impl_(uint_fast32_t a, uint_fast32_t b, uint_fast32_t c) {
  HEDLEY_STATIC_CAST(void, a);
  const uint_fast32_t t0 = ~c;
  const uint_fast32_t t1 = b | t0;
  return t1;
}

SIMDE_FUNCTION_ATTRIBUTES
uint_fast32_t
simde_x_ternarylogic_0xde_impl_(uint_fast32_t a, uint_fast32_t b, uint_fast32_t c) {
  const uint_fast32_t t0 = a ^ c;
  const uint_fast32_t t1 = b | t0;
  return t1;
}

SIMDE_FUNCTION_ATTRIBUTES
uint_fast32_t
simde_x_ternarylogic_0xdf_impl_(uint_fast32_t a, uint_fast32_t b, uint_fast32_t c) {
  const uint_fast32_t t0 = a & c;
  const uint_fast32_t t1 = ~t0;
  const uint_fast32_t t2 = b | t1;
  return t2;
}

SIMDE_FUNCTION_ATTRIBUTES
uint_fast32_t
simde_x_ternarylogic_0xe0_impl_(uint_fast32_t a, uint_fast32_t b, uint_fast32_t c) {
  const uint_fast32_t t0 = b | c;
  const uint_fast32_t t1 = a & t0;
  return t1;
}

SIMDE_FUNCTION_ATTRIBUTES
uint_fast32_t
simde_x_ternarylogic_0xe1_impl_(uint_fast32_t a, uint_fast32_t b, uint_fast32_t c) {
  const uint_fast32_t t0 = b | c;
  const uint_fast32_t t1 = a ^ t0;
  const uint_fast32_t t2 = ~t1;
  return t2;
}

SIMDE_FUNCTION_ATTRIBUTES
uint_fast32_t
simde_x_ternarylogic_0xe2_impl_(uint_fast32_t a, uint_fast32_t b, uint_fast32_t c) {
  const uint_fast32_t t0 = b & a;
  const uint_fast32_t t1 = ~b;
  const uint_fast32_t t2 = t1 & c;
  const uint_fast32_t t3 = t0 | t2;
  return t3;
}

SIMDE_FUNCTION_ATTRIBUTES
uint_fast32_t
simde_x_ternarylogic_0xe3_impl_(uint_fast32_t a, uint_fast32_t b, uint_fast32_t c) {
  const uint_fast32_t t0 = a ^ b;
  const uint_fast32_t t1 = ~t0;
  const uint_fast32_t t2 = a & c;
  const uint_fast32_t t3 = t1 | t2;
  return t3;
}

SIMDE_FUNCTION_ATTRIBUTES
uint_fast32_t
simde_x_ternarylogic_0xe4_impl_(uint_fast32_t a, uint_fast32_t b, uint_fast32_t c) {
  const uint_fast32_t t0 = c & a;
  const uint_fast32_t t1 = ~c;
  const uint_fast32_t t2 = t1 & b;
  const uint_fast32_t t3 = t0 | t2;
  return t3;
}

SIMDE_FUNCTION_ATTRIBUTES
uint_fast32_t
simde_x_ternarylogic_0xe5_impl_(uint_fast32_t a, uint_fast32_t b, uint_fast32_t c) {
  const uint_fast32_t t0 = a ^ c;
  const uint_fast32_t t1 = ~t0;
  const uint_fast32_t t2 = a & b;
  const uint_fast32_t t3 = t1 | t2;
  return t3;
}

SIMDE_FUNCTION_ATTRIBUTES
uint_fast32_t
simde_x_ternarylogic_0xe6_impl_(uint_fast32_t a, uint_fast32_t b, uint_fast32_t c) {
  const uint_fast32_t t0 = a & b;
  const uint_fast32_t t1 = b ^ c;
  const uint_fast32_t t2 = t0 | t1;
  return t2;
}

SIMDE_FUNCTION_ATTRIBUTES
uint_fast32_t
simde_x_ternarylogic_0xe7_impl_(uint_fast32_t a, uint_fast32_t b, uint_fast32_t c) {
  const uint_fast32_t t0 = b ^ c;
  const uint_fast32_t t1 = ~a;
  const uint_fast32_t t2 = t1 ^ c;
  const uint_fast32_t t3 = t0 | t2;
  return t3;
}

SIMDE_FUNCTION_ATTRIBUTES
uint_fast32_t
simde_x_ternarylogic_0xe8_impl_(uint_fast32_t a, uint_fast32_t b, uint_fast32_t c) {
  const uint_fast32_t t0 = b & c;
  const uint_fast32_t t1 = b ^ c;
  const uint_fast32_t t2 = a & t1;
  const uint_fast32_t t3 = t0 | t2;
  return t3;
}

SIMDE_FUNCTION_ATTRIBUTES
uint_fast32_t
simde_x_ternarylogic_0xe9_impl_(uint_fast32_t a, uint_fast32_t b, uint_fast32_t c) {
  const uint_fast32_t t0 = ~a;
  const uint_fast32_t t1 = b ^ c;
  const uint_fast32_t t2 = t0 ^ t1;
  const uint_fast32_t t3 = a & b;
  const uint_fast32_t t4 = t2 | t3;
  return t4;
}

SIMDE_FUNCTION_ATTRIBUTES
uint_fast32_t
simde_x_ternarylogic_0xea_impl_(uint_fast32_t a, uint_fast32_t b, uint_fast32_t c) {
  const uint_fast32_t t0 = b & a;
  const uint_fast32_t t1 = c | t0;
  return t1;
}

SIMDE_FUNCTION_ATTRIBUTES
uint_fast32_t
simde_x_ternarylogic_0xeb_impl_(uint_fast32_t a, uint_fast32_t b, uint_fast32_t c) {
  const uint_fast32_t t0 = b ^ a;
  const uint_fast32_t t1 = ~t0;
  const uint_fast32_t t2 = c | t1;
  return t2;
}

SIMDE_FUNCTION_ATTRIBUTES
uint_fast32_t
simde_x_ternarylogic_0xec_impl_(uint_fast32_t a, uint_fast32_t b, uint_fast32_t c) {
  const uint_fast32_t t0 = a & c;
  const uint_fast32_t t1 = b | t0;
  return t1;
}

SIMDE_FUNCTION_ATTRIBUTES
uint_fast32_t
simde_x_ternarylogic_0xed_impl_(uint_fast32_t a, uint_fast32_t b, uint_fast32_t c) {
  const uint_fast32_t t0 = a ^ c;
  const uint_fast32_t t1 = ~t0;
  const uint_fast32_t t2 = b | t1;
  return t2;
}

SIMDE_FUNCTION_ATTRIBUTES
uint_fast32_t
simde_x_ternarylogic_0xee_impl_(uint_fast32_t a, uint_fast32_t b, uint_fast32_t c) {
  HEDLEY_STATIC_CAST(void, a);
  const uint_fast32_t t0 = c | b;
  return t0;
}

SIMDE_FUNCTION_ATTRIBUTES
uint_fast32_t
simde_x_ternarylogic_0xef_impl_(uint_fast32_t a, uint_fast32_t b, uint_fast32_t c) {
  const uint_fast32_t t0 = ~a;
  const uint_fast32_t t1 = b | c;
  const uint_fast32_t t2 = t0 | t1;
  return t2;
}

SIMDE_FUNCTION_ATTRIBUTES
uint_fast32_t
simde_x_ternarylogic_0xf0_impl_(uint_fast32_t a, uint_fast32_t b, uint_fast32_t c) {
  HEDLEY_STATIC_CAST(void, b);
  HEDLEY_STATIC_CAST(void, c);
  return a;
}

SIMDE_FUNCTION_ATTRIBUTES
uint_fast32_t
simde_x_ternarylogic_0xf1_impl_(uint_fast32_t a, uint_fast32_t b, uint_fast32_t c) {
  const uint_fast32_t t0 = b | c;
  const uint_fast32_t t1 = ~t0;
  const uint_fast32_t t2 = a | t1;
  return t2;
}

SIMDE_FUNCTION_ATTRIBUTES
uint_fast32_t
simde_x_ternarylogic_0xf2_impl_(uint_fast32_t a, uint_fast32_t b, uint_fast32_t c) {
  const uint_fast32_t t0 = ~b;
  const uint_fast32_t t1 = t0 & c;
  const uint_fast32_t t2 = t1 | a;
  return t2;
}

SIMDE_FUNCTION_ATTRIBUTES
uint_fast32_t
simde_x_ternarylogic_0xf3_impl_(uint_fast32_t a, uint_fast32_t b, uint_fast32_t c) {
  HEDLEY_STATIC_CAST(void, c);
  const uint_fast32_t t0 = ~b;
  const uint_fast32_t t1 = a | t0;
  return t1;
}

SIMDE_FUNCTION_ATTRIBUTES
uint_fast32_t
simde_x_ternarylogic_0xf4_impl_(uint_fast32_t a, uint_fast32_t b, uint_fast32_t c) {
  const uint_fast32_t t0 = ~c;
  const uint_fast32_t t1 = t0 & b;
  const uint_fast32_t t2 = t1 | a;
  return t2;
}

SIMDE_FUNCTION_ATTRIBUTES
uint_fast32_t
simde_x_ternarylogic_0xf5_impl_(uint_fast32_t a, uint_fast32_t b, uint_fast32_t c) {
  HEDLEY_STATIC_CAST(void, b);
  const uint_fast32_t t0 = ~c;
  const uint_fast32_t t1 = a | t0;
  return t1;
}

SIMDE_FUNCTION_ATTRIBUTES
uint_fast32_t
simde_x_ternarylogic_0xf6_impl_(uint_fast32_t a, uint_fast32_t b, uint_fast32_t c) {
  const uint_fast32_t t0 = b ^ c;
  const uint_fast32_t t1 = a | t0;
  return t1;
}

SIMDE_FUNCTION_ATTRIBUTES
uint_fast32_t
simde_x_ternarylogic_0xf7_impl_(uint_fast32_t a, uint_fast32_t b, uint_fast32_t c) {
  const uint_fast32_t t0 = b & c;
  const uint_fast32_t t1 = ~t0;
  const uint_fast32_t t2 = a | t1;
  return t2;
}

SIMDE_FUNCTION_ATTRIBUTES
uint_fast32_t
simde_x_ternarylogic_0xf8_impl_(uint_fast32_t a, uint_fast32_t b, uint_fast32_t c) {
  const uint_fast32_t t0 = b & c;
  const uint_fast32_t t1 = a | t0;
  return t1;
}

SIMDE_FUNCTION_ATTRIBUTES
uint_fast32_t
simde_x_ternarylogic_0xf9_impl_(uint_fast32_t a, uint_fast32_t b, uint_fast32_t c) {
  const uint_fast32_t t0 = b ^ c;
  const uint_fast32_t t1 = ~t0;
  const uint_fast32_t t2 = a | t1;
  return t2;
}

SIMDE_FUNCTION_ATTRIBUTES
uint_fast32_t
simde_x_ternarylogic_0xfa_impl_(uint_fast32_t a, uint_fast32_t b, uint_fast32_t c) {
  HEDLEY_STATIC_CAST(void, b);
  const uint_fast32_t t0 = c | a;
  return t0;
}

SIMDE_FUNCTION_ATTRIBUTES
uint_fast32_t
simde_x_ternarylogic_0xfb_impl_(uint_fast32_t a, uint_fast32_t b, uint_fast32_t c) {
  const uint_fast32_t t0 = ~b;
  const uint_fast32_t t1 = t0 | c;
  const uint_fast32_t t2 = a | t1;
  return t2;
}

SIMDE_FUNCTION_ATTRIBUTES
uint_fast32_t
simde_x_ternarylogic_0xfc_impl_(uint_fast32_t a, uint_fast32_t b, uint_fast32_t c) {
  HEDLEY_STATIC_CAST(void, c);
  const uint_fast32_t t0 = b | a;
  return t0;
}

SIMDE_FUNCTION_ATTRIBUTES
uint_fast32_t
simde_x_ternarylogic_0xfd_impl_(uint_fast32_t a, uint_fast32_t b, uint_fast32_t c) {
  const uint_fast32_t t0 = ~c;
  const uint_fast32_t t1 = a | b;
  const uint_fast32_t t2 = t0 | t1;
  return t2;
}

SIMDE_FUNCTION_ATTRIBUTES
uint_fast32_t
simde_x_ternarylogic_0xfe_impl_(uint_fast32_t a, uint_fast32_t b, uint_fast32_t c) {
  const uint_fast32_t t0 = b | c;
  const uint_fast32_t t1 = a | t0;
  return t1;
}

SIMDE_FUNCTION_ATTRIBUTES
uint_fast32_t
simde_x_ternarylogic_0xff_impl_(uint_fast32_t a, uint_fast32_t b, uint_fast32_t c) {
  HEDLEY_STATIC_CAST(void, a);
  HEDLEY_STATIC_CAST(void, b);
  HEDLEY_STATIC_CAST(void, c);
  const uint_fast32_t c1 = ~HEDLEY_STATIC_CAST(uint_fast32_t, 0);
  return c1;
}

#if defined(SIMDE_X86_AVX512VL_NATIVE) && defined(SIMDE_X86_AVX512F_NATIVE)
  #define simde_mm_ternarylogic_epi32(a, b, c, imm8) _mm_ternarylogic_epi32(a, b, c, imm8)
#else
  SIMDE_HUGE_FUNCTION_ATTRIBUTES
  simde__m128i
  simde_mm_ternarylogic_epi32(simde__m128i a, simde__m128i b, simde__m128i c, int imm8)
      SIMDE_REQUIRE_CONSTANT_RANGE(imm8, 0, 255) {
    simde__m128i_private
      r_,
      a_ = simde__m128i_to_private(a),
      b_ = simde__m128i_to_private(b),
      c_ = simde__m128i_to_private(c);

  #if defined(SIMDE_TERNARYLOGIC_COMPRESSION)
    switch((imm8 ^ (HEDLEY_STATIC_CAST(int8_t, imm8) >> 7)) & 127) {
  #else
    switch(imm8 & 255) {
  #endif
      case 0:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32f) / sizeof(r_.u32f[0])) ; i++) {
          r_.u32f[i] = simde_x_ternarylogic_0x00_impl_(a_.u32f[i], b_.u32f[i], c_.u32f[i]);
        }
        break;
      case 1:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32f) / sizeof(r_.u32f[0])) ; i++) {
          r_.u32f[i] = simde_x_ternarylogic_0x01_impl_(a_.u32f[i], b_.u32f[i], c_.u32f[i]);
        }
        break;
      case 2:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32f) / sizeof(r_.u32f[0])) ; i++) {
          r_.u32f[i] = simde_x_ternarylogic_0x02_impl_(a_.u32f[i], b_.u32f[i], c_.u32f[i]);
        }
        break;
      case 3:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32f) / sizeof(r_.u32f[0])) ; i++) {
          r_.u32f[i] = simde_x_ternarylogic_0x03_impl_(a_.u32f[i], b_.u32f[i], c_.u32f[i]);
        }
        break;
      case 4:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32f) / sizeof(r_.u32f[0])) ; i++) {
          r_.u32f[i] = simde_x_ternarylogic_0x04_impl_(a_.u32f[i], b_.u32f[i], c_.u32f[i]);
        }
        break;
      case 5:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32f) / sizeof(r_.u32f[0])) ; i++) {
          r_.u32f[i] = simde_x_ternarylogic_0x05_impl_(a_.u32f[i], b_.u32f[i], c_.u32f[i]);
        }
        break;
      case 6:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32f) / sizeof(r_.u32f[0])) ; i++) {
          r_.u32f[i] = simde_x_ternarylogic_0x06_impl_(a_.u32f[i], b_.u32f[i], c_.u32f[i]);
        }
        break;
      case 7:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32f) / sizeof(r_.u32f[0])) ; i++) {
          r_.u32f[i] = simde_x_ternarylogic_0x07_impl_(a_.u32f[i], b_.u32f[i], c_.u32f[i]);
        }
        break;
      case 8:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32f) / sizeof(r_.u32f[0])) ; i++) {
          r_.u32f[i] = simde_x_ternarylogic_0x08_impl_(a_.u32f[i], b_.u32f[i], c_.u32f[i]);
        }
        break;
      case 9:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32f) / sizeof(r_.u32f[0])) ; i++) {
          r_.u32f[i] = simde_x_ternarylogic_0x09_impl_(a_.u32f[i], b_.u32f[i], c_.u32f[i]);
        }
        break;
      case 10:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32f) / sizeof(r_.u32f[0])) ; i++) {
          r_.u32f[i] = simde_x_ternarylogic_0x0a_impl_(a_.u32f[i], b_.u32f[i], c_.u32f[i]);
        }
        break;
      case 11:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32f) / sizeof(r_.u32f[0])) ; i++) {
          r_.u32f[i] = simde_x_ternarylogic_0x0b_impl_(a_.u32f[i], b_.u32f[i], c_.u32f[i]);
        }
        break;
      case 12:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32f) / sizeof(r_.u32f[0])) ; i++) {
          r_.u32f[i] = simde_x_ternarylogic_0x0c_impl_(a_.u32f[i], b_.u32f[i], c_.u32f[i]);
        }
        break;
      case 13:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32f) / sizeof(r_.u32f[0])) ; i++) {
          r_.u32f[i] = simde_x_ternarylogic_0x0d_impl_(a_.u32f[i], b_.u32f[i], c_.u32f[i]);
        }
        break;
      case 14:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32f) / sizeof(r_.u32f[0])) ; i++) {
          r_.u32f[i] = simde_x_ternarylogic_0x0e_impl_(a_.u32f[i], b_.u32f[i], c_.u32f[i]);
        }
        break;
      case 15:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32f) / sizeof(r_.u32f[0])) ; i++) {
          r_.u32f[i] = simde_x_ternarylogic_0x0f_impl_(a_.u32f[i], b_.u32f[i], c_.u32f[i]);
        }
        break;
      case 16:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32f) / sizeof(r_.u32f[0])) ; i++) {
          r_.u32f[i] = simde_x_ternarylogic_0x10_impl_(a_.u32f[i], b_.u32f[i], c_.u32f[i]);
        }
        break;
      case 17:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32f) / sizeof(r_.u32f[0])) ; i++) {
          r_.u32f[i] = simde_x_ternarylogic_0x11_impl_(a_.u32f[i], b_.u32f[i], c_.u32f[i]);
        }
        break;
      case 18:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32f) / sizeof(r_.u32f[0])) ; i++) {
          r_.u32f[i] = simde_x_ternarylogic_0x12_impl_(a_.u32f[i], b_.u32f[i], c_.u32f[i]);
        }
        break;
      case 19:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32f) / sizeof(r_.u32f[0])) ; i++) {
          r_.u32f[i] = simde_x_ternarylogic_0x13_impl_(a_.u32f[i], b_.u32f[i], c_.u32f[i]);
        }
        break;
      case 20:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32f) / sizeof(r_.u32f[0])) ; i++) {
          r_.u32f[i] = simde_x_ternarylogic_0x14_impl_(a_.u32f[i], b_.u32f[i], c_.u32f[i]);
        }
        break;
      case 21:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32f) / sizeof(r_.u32f[0])) ; i++) {
          r_.u32f[i] = simde_x_ternarylogic_0x15_impl_(a_.u32f[i], b_.u32f[i], c_.u32f[i]);
        }
        break;
      case 22:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32f) / sizeof(r_.u32f[0])) ; i++) {
          r_.u32f[i] = simde_x_ternarylogic_0x16_impl_(a_.u32f[i], b_.u32f[i], c_.u32f[i]);
        }
        break;
      case 23:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32f) / sizeof(r_.u32f[0])) ; i++) {
          r_.u32f[i] = simde_x_ternarylogic_0x17_impl_(a_.u32f[i], b_.u32f[i], c_.u32f[i]);
        }
        break;
      case 24:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32f) / sizeof(r_.u32f[0])) ; i++) {
          r_.u32f[i] = simde_x_ternarylogic_0x18_impl_(a_.u32f[i], b_.u32f[i], c_.u32f[i]);
        }
        break;
      case 25:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32f) / sizeof(r_.u32f[0])) ; i++) {
          r_.u32f[i] = simde_x_ternarylogic_0x19_impl_(a_.u32f[i], b_.u32f[i], c_.u32f[i]);
        }
        break;
      case 26:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32f) / sizeof(r_.u32f[0])) ; i++) {
          r_.u32f[i] = simde_x_ternarylogic_0x1a_impl_(a_.u32f[i], b_.u32f[i], c_.u32f[i]);
        }
        break;
      case 27:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32f) / sizeof(r_.u32f[0])) ; i++) {
          r_.u32f[i] = simde_x_ternarylogic_0x1b_impl_(a_.u32f[i], b_.u32f[i], c_.u32f[i]);
        }
        break;
      case 28:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32f) / sizeof(r_.u32f[0])) ; i++) {
          r_.u32f[i] = simde_x_ternarylogic_0x1c_impl_(a_.u32f[i], b_.u32f[i], c_.u32f[i]);
        }
        break;
      case 29:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32f) / sizeof(r_.u32f[0])) ; i++) {
          r_.u32f[i] = simde_x_ternarylogic_0x1d_impl_(a_.u32f[i], b_.u32f[i], c_.u32f[i]);
        }
        break;
      case 30:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32f) / sizeof(r_.u32f[0])) ; i++) {
          r_.u32f[i] = simde_x_ternarylogic_0x1e_impl_(a_.u32f[i], b_.u32f[i], c_.u32f[i]);
        }
        break;
      case 31:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32f) / sizeof(r_.u32f[0])) ; i++) {
          r_.u32f[i] = simde_x_ternarylogic_0x1f_impl_(a_.u32f[i], b_.u32f[i], c_.u32f[i]);
        }
        break;
      case 32:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32f) / sizeof(r_.u32f[0])) ; i++) {
          r_.u32f[i] = simde_x_ternarylogic_0x20_impl_(a_.u32f[i], b_.u32f[i], c_.u32f[i]);
        }
        break;
      case 33:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32f) / sizeof(r_.u32f[0])) ; i++) {
          r_.u32f[i] = simde_x_ternarylogic_0x21_impl_(a_.u32f[i], b_.u32f[i], c_.u32f[i]);
        }
        break;
      case 34:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32f) / sizeof(r_.u32f[0])) ; i++) {
          r_.u32f[i] = simde_x_ternarylogic_0x22_impl_(a_.u32f[i], b_.u32f[i], c_.u32f[i]);
        }
        break;
      case 35:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32f) / sizeof(r_.u32f[0])) ; i++) {
          r_.u32f[i] = simde_x_ternarylogic_0x23_impl_(a_.u32f[i], b_.u32f[i], c_.u32f[i]);
        }
        break;
      case 36:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32f) / sizeof(r_.u32f[0])) ; i++) {
          r_.u32f[i] = simde_x_ternarylogic_0x24_impl_(a_.u32f[i], b_.u32f[i], c_.u32f[i]);
        }
        break;
      case 37:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32f) / sizeof(r_.u32f[0])) ; i++) {
          r_.u32f[i] = simde_x_ternarylogic_0x25_impl_(a_.u32f[i], b_.u32f[i], c_.u32f[i]);
        }
        break;
      case 38:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32f) / sizeof(r_.u32f[0])) ; i++) {
          r_.u32f[i] = simde_x_ternarylogic_0x26_impl_(a_.u32f[i], b_.u32f[i], c_.u32f[i]);
        }
        break;
      case 39:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32f) / sizeof(r_.u32f[0])) ; i++) {
          r_.u32f[i] = simde_x_ternarylogic_0x27_impl_(a_.u32f[i], b_.u32f[i], c_.u32f[i]);
        }
        break;
      case 40:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32f) / sizeof(r_.u32f[0])) ; i++) {
          r_.u32f[i] = simde_x_ternarylogic_0x28_impl_(a_.u32f[i], b_.u32f[i], c_.u32f[i]);
        }
        break;
      case 41:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32f) / sizeof(r_.u32f[0])) ; i++) {
          r_.u32f[i] = simde_x_ternarylogic_0x29_impl_(a_.u32f[i], b_.u32f[i], c_.u32f[i]);
        }
        break;
      case 42:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32f) / sizeof(r_.u32f[0])) ; i++) {
          r_.u32f[i] = simde_x_ternarylogic_0x2a_impl_(a_.u32f[i], b_.u32f[i], c_.u32f[i]);
        }
        break;
      case 43:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32f) / sizeof(r_.u32f[0])) ; i++) {
          r_.u32f[i] = simde_x_ternarylogic_0x2b_impl_(a_.u32f[i], b_.u32f[i], c_.u32f[i]);
        }
        break;
      case 44:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32f) / sizeof(r_.u32f[0])) ; i++) {
          r_.u32f[i] = simde_x_ternarylogic_0x2c_impl_(a_.u32f[i], b_.u32f[i], c_.u32f[i]);
        }
        break;
      case 45:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32f) / sizeof(r_.u32f[0])) ; i++) {
          r_.u32f[i] = simde_x_ternarylogic_0x2d_impl_(a_.u32f[i], b_.u32f[i], c_.u32f[i]);
        }
        break;
      case 46:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32f) / sizeof(r_.u32f[0])) ; i++) {
          r_.u32f[i] = simde_x_ternarylogic_0x2e_impl_(a_.u32f[i], b_.u32f[i], c_.u32f[i]);
        }
        break;
      case 47:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32f) / sizeof(r_.u32f[0])) ; i++) {
          r_.u32f[i] = simde_x_ternarylogic_0x2f_impl_(a_.u32f[i], b_.u32f[i], c_.u32f[i]);
        }
        break;
      case 48:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32f) / sizeof(r_.u32f[0])) ; i++) {
          r_.u32f[i] = simde_x_ternarylogic_0x30_impl_(a_.u32f[i], b_.u32f[i], c_.u32f[i]);
        }
        break;
      case 49:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32f) / sizeof(r_.u32f[0])) ; i++) {
          r_.u32f[i] = simde_x_ternarylogic_0x31_impl_(a_.u32f[i], b_.u32f[i], c_.u32f[i]);
        }
        break;
      case 50:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32f) / sizeof(r_.u32f[0])) ; i++) {
          r_.u32f[i] = simde_x_ternarylogic_0x32_impl_(a_.u32f[i], b_.u32f[i], c_.u32f[i]);
        }
        break;
      case 51:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32f) / sizeof(r_.u32f[0])) ; i++) {
          r_.u32f[i] = simde_x_ternarylogic_0x33_impl_(a_.u32f[i], b_.u32f[i], c_.u32f[i]);
        }
        break;
      case 52:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32f) / sizeof(r_.u32f[0])) ; i++) {
          r_.u32f[i] = simde_x_ternarylogic_0x34_impl_(a_.u32f[i], b_.u32f[i], c_.u32f[i]);
        }
        break;
      case 53:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32f) / sizeof(r_.u32f[0])) ; i++) {
          r_.u32f[i] = simde_x_ternarylogic_0x35_impl_(a_.u32f[i], b_.u32f[i], c_.u32f[i]);
        }
        break;
      case 54:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32f) / sizeof(r_.u32f[0])) ; i++) {
          r_.u32f[i] = simde_x_ternarylogic_0x36_impl_(a_.u32f[i], b_.u32f[i], c_.u32f[i]);
        }
        break;
      case 55:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32f) / sizeof(r_.u32f[0])) ; i++) {
          r_.u32f[i] = simde_x_ternarylogic_0x37_impl_(a_.u32f[i], b_.u32f[i], c_.u32f[i]);
        }
        break;
      case 56:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32f) / sizeof(r_.u32f[0])) ; i++) {
          r_.u32f[i] = simde_x_ternarylogic_0x38_impl_(a_.u32f[i], b_.u32f[i], c_.u32f[i]);
        }
        break;
      case 57:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32f) / sizeof(r_.u32f[0])) ; i++) {
          r_.u32f[i] = simde_x_ternarylogic_0x39_impl_(a_.u32f[i], b_.u32f[i], c_.u32f[i]);
        }
        break;
      case 58:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32f) / sizeof(r_.u32f[0])) ; i++) {
          r_.u32f[i] = simde_x_ternarylogic_0x3a_impl_(a_.u32f[i], b_.u32f[i], c_.u32f[i]);
        }
        break;
      case 59:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32f) / sizeof(r_.u32f[0])) ; i++) {
          r_.u32f[i] = simde_x_ternarylogic_0x3b_impl_(a_.u32f[i], b_.u32f[i], c_.u32f[i]);
        }
        break;
      case 60:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32f) / sizeof(r_.u32f[0])) ; i++) {
          r_.u32f[i] = simde_x_ternarylogic_0x3c_impl_(a_.u32f[i], b_.u32f[i], c_.u32f[i]);
        }
        break;
      case 61:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32f) / sizeof(r_.u32f[0])) ; i++) {
          r_.u32f[i] = simde_x_ternarylogic_0x3d_impl_(a_.u32f[i], b_.u32f[i], c_.u32f[i]);
        }
        break;
      case 62:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32f) / sizeof(r_.u32f[0])) ; i++) {
          r_.u32f[i] = simde_x_ternarylogic_0x3e_impl_(a_.u32f[i], b_.u32f[i], c_.u32f[i]);
        }
        break;
      case 63:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32f) / sizeof(r_.u32f[0])) ; i++) {
          r_.u32f[i] = simde_x_ternarylogic_0x3f_impl_(a_.u32f[i], b_.u32f[i], c_.u32f[i]);
        }
        break;
      case 64:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32f) / sizeof(r_.u32f[0])) ; i++) {
          r_.u32f[i] = simde_x_ternarylogic_0x40_impl_(a_.u32f[i], b_.u32f[i], c_.u32f[i]);
        }
        break;
      case 65:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32f) / sizeof(r_.u32f[0])) ; i++) {
          r_.u32f[i] = simde_x_ternarylogic_0x41_impl_(a_.u32f[i], b_.u32f[i], c_.u32f[i]);
        }
        break;
      case 66:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32f) / sizeof(r_.u32f[0])) ; i++) {
          r_.u32f[i] = simde_x_ternarylogic_0x42_impl_(a_.u32f[i], b_.u32f[i], c_.u32f[i]);
        }
        break;
      case 67:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32f) / sizeof(r_.u32f[0])) ; i++) {
          r_.u32f[i] = simde_x_ternarylogic_0x43_impl_(a_.u32f[i], b_.u32f[i], c_.u32f[i]);
        }
        break;
      case 68:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32f) / sizeof(r_.u32f[0])) ; i++) {
          r_.u32f[i] = simde_x_ternarylogic_0x44_impl_(a_.u32f[i], b_.u32f[i], c_.u32f[i]);
        }
        break;
      case 69:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32f) / sizeof(r_.u32f[0])) ; i++) {
          r_.u32f[i] = simde_x_ternarylogic_0x45_impl_(a_.u32f[i], b_.u32f[i], c_.u32f[i]);
        }
        break;
      case 70:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32f) / sizeof(r_.u32f[0])) ; i++) {
          r_.u32f[i] = simde_x_ternarylogic_0x46_impl_(a_.u32f[i], b_.u32f[i], c_.u32f[i]);
        }
        break;
      case 71:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32f) / sizeof(r_.u32f[0])) ; i++) {
          r_.u32f[i] = simde_x_ternarylogic_0x47_impl_(a_.u32f[i], b_.u32f[i], c_.u32f[i]);
        }
        break;
      case 72:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32f) / sizeof(r_.u32f[0])) ; i++) {
          r_.u32f[i] = simde_x_ternarylogic_0x48_impl_(a_.u32f[i], b_.u32f[i], c_.u32f[i]);
        }
        break;
      case 73:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32f) / sizeof(r_.u32f[0])) ; i++) {
          r_.u32f[i] = simde_x_ternarylogic_0x49_impl_(a_.u32f[i], b_.u32f[i], c_.u32f[i]);
        }
        break;
      case 74:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32f) / sizeof(r_.u32f[0])) ; i++) {
          r_.u32f[i] = simde_x_ternarylogic_0x4a_impl_(a_.u32f[i], b_.u32f[i], c_.u32f[i]);
        }
        break;
      case 75:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32f) / sizeof(r_.u32f[0])) ; i++) {
          r_.u32f[i] = simde_x_ternarylogic_0x4b_impl_(a_.u32f[i], b_.u32f[i], c_.u32f[i]);
        }
        break;
      case 76:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32f) / sizeof(r_.u32f[0])) ; i++) {
          r_.u32f[i] = simde_x_ternarylogic_0x4c_impl_(a_.u32f[i], b_.u32f[i], c_.u32f[i]);
        }
        break;
      case 77:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32f) / sizeof(r_.u32f[0])) ; i++) {
          r_.u32f[i] = simde_x_ternarylogic_0x4d_impl_(a_.u32f[i], b_.u32f[i], c_.u32f[i]);
        }
        break;
      case 78:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32f) / sizeof(r_.u32f[0])) ; i++) {
          r_.u32f[i] = simde_x_ternarylogic_0x4e_impl_(a_.u32f[i], b_.u32f[i], c_.u32f[i]);
        }
        break;
      case 79:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32f) / sizeof(r_.u32f[0])) ; i++) {
          r_.u32f[i] = simde_x_ternarylogic_0x4f_impl_(a_.u32f[i], b_.u32f[i], c_.u32f[i]);
        }
        break;
      case 80:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32f) / sizeof(r_.u32f[0])) ; i++) {
          r_.u32f[i] = simde_x_ternarylogic_0x50_impl_(a_.u32f[i], b_.u32f[i], c_.u32f[i]);
        }
        break;
      case 81:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32f) / sizeof(r_.u32f[0])) ; i++) {
          r_.u32f[i] = simde_x_ternarylogic_0x51_impl_(a_.u32f[i], b_.u32f[i], c_.u32f[i]);
        }
        break;
      case 82:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32f) / sizeof(r_.u32f[0])) ; i++) {
          r_.u32f[i] = simde_x_ternarylogic_0x52_impl_(a_.u32f[i], b_.u32f[i], c_.u32f[i]);
        }
        break;
      case 83:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32f) / sizeof(r_.u32f[0])) ; i++) {
          r_.u32f[i] = simde_x_ternarylogic_0x53_impl_(a_.u32f[i], b_.u32f[i], c_.u32f[i]);
        }
        break;
      case 84:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32f) / sizeof(r_.u32f[0])) ; i++) {
          r_.u32f[i] = simde_x_ternarylogic_0x54_impl_(a_.u32f[i], b_.u32f[i], c_.u32f[i]);
        }
        break;
      case 85:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32f) / sizeof(r_.u32f[0])) ; i++) {
          r_.u32f[i] = simde_x_ternarylogic_0x55_impl_(a_.u32f[i], b_.u32f[i], c_.u32f[i]);
        }
        break;
      case 86:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32f) / sizeof(r_.u32f[0])) ; i++) {
          r_.u32f[i] = simde_x_ternarylogic_0x56_impl_(a_.u32f[i], b_.u32f[i], c_.u32f[i]);
        }
        break;
      case 87:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32f) / sizeof(r_.u32f[0])) ; i++) {
          r_.u32f[i] = simde_x_ternarylogic_0x57_impl_(a_.u32f[i], b_.u32f[i], c_.u32f[i]);
        }
        break;
      case 88:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32f) / sizeof(r_.u32f[0])) ; i++) {
          r_.u32f[i] = simde_x_ternarylogic_0x58_impl_(a_.u32f[i], b_.u32f[i], c_.u32f[i]);
        }
        break;
      case 89:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32f) / sizeof(r_.u32f[0])) ; i++) {
          r_.u32f[i] = simde_x_ternarylogic_0x59_impl_(a_.u32f[i], b_.u32f[i], c_.u32f[i]);
        }
        break;
      case 90:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32f) / sizeof(r_.u32f[0])) ; i++) {
          r_.u32f[i] = simde_x_ternarylogic_0x5a_impl_(a_.u32f[i], b_.u32f[i], c_.u32f[i]);
        }
        break;
      case 91:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32f) / sizeof(r_.u32f[0])) ; i++) {
          r_.u32f[i] = simde_x_ternarylogic_0x5b_impl_(a_.u32f[i], b_.u32f[i], c_.u32f[i]);
        }
        break;
      case 92:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32f) / sizeof(r_.u32f[0])) ; i++) {
          r_.u32f[i] = simde_x_ternarylogic_0x5c_impl_(a_.u32f[i], b_.u32f[i], c_.u32f[i]);
        }
        break;
      case 93:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32f) / sizeof(r_.u32f[0])) ; i++) {
          r_.u32f[i] = simde_x_ternarylogic_0x5d_impl_(a_.u32f[i], b_.u32f[i], c_.u32f[i]);
        }
        break;
      case 94:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32f) / sizeof(r_.u32f[0])) ; i++) {
          r_.u32f[i] = simde_x_ternarylogic_0x5e_impl_(a_.u32f[i], b_.u32f[i], c_.u32f[i]);
        }
        break;
      case 95:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32f) / sizeof(r_.u32f[0])) ; i++) {
          r_.u32f[i] = simde_x_ternarylogic_0x5f_impl_(a_.u32f[i], b_.u32f[i], c_.u32f[i]);
        }
        break;
      case 96:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32f) / sizeof(r_.u32f[0])) ; i++) {
          r_.u32f[i] = simde_x_ternarylogic_0x60_impl_(a_.u32f[i], b_.u32f[i], c_.u32f[i]);
        }
        break;
      case 97:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32f) / sizeof(r_.u32f[0])) ; i++) {
          r_.u32f[i] = simde_x_ternarylogic_0x61_impl_(a_.u32f[i], b_.u32f[i], c_.u32f[i]);
        }
        break;
      case 98:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32f) / sizeof(r_.u32f[0])) ; i++) {
          r_.u32f[i] = simde_x_ternarylogic_0x62_impl_(a_.u32f[i], b_.u32f[i], c_.u32f[i]);
        }
        break;
      case 99:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32f) / sizeof(r_.u32f[0])) ; i++) {
          r_.u32f[i] = simde_x_ternarylogic_0x63_impl_(a_.u32f[i], b_.u32f[i], c_.u32f[i]);
        }
        break;
      case 100:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32f) / sizeof(r_.u32f[0])) ; i++) {
          r_.u32f[i] = simde_x_ternarylogic_0x64_impl_(a_.u32f[i], b_.u32f[i], c_.u32f[i]);
        }
        break;
      case 101:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32f) / sizeof(r_.u32f[0])) ; i++) {
          r_.u32f[i] = simde_x_ternarylogic_0x65_impl_(a_.u32f[i], b_.u32f[i], c_.u32f[i]);
        }
        break;
      case 102:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32f) / sizeof(r_.u32f[0])) ; i++) {
          r_.u32f[i] = simde_x_ternarylogic_0x66_impl_(a_.u32f[i], b_.u32f[i], c_.u32f[i]);
        }
        break;
      case 103:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32f) / sizeof(r_.u32f[0])) ; i++) {
          r_.u32f[i] = simde_x_ternarylogic_0x67_impl_(a_.u32f[i], b_.u32f[i], c_.u32f[i]);
        }
        break;
      case 104:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32f) / sizeof(r_.u32f[0])) ; i++) {
          r_.u32f[i] = simde_x_ternarylogic_0x68_impl_(a_.u32f[i], b_.u32f[i], c_.u32f[i]);
        }
        break;
      case 105:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32f) / sizeof(r_.u32f[0])) ; i++) {
          r_.u32f[i] = simde_x_ternarylogic_0x69_impl_(a_.u32f[i], b_.u32f[i], c_.u32f[i]);
        }
        break;
      case 106:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32f) / sizeof(r_.u32f[0])) ; i++) {
          r_.u32f[i] = simde_x_ternarylogic_0x6a_impl_(a_.u32f[i], b_.u32f[i], c_.u32f[i]);
        }
        break;
      case 107:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32f) / sizeof(r_.u32f[0])) ; i++) {
          r_.u32f[i] = simde_x_ternarylogic_0x6b_impl_(a_.u32f[i], b_.u32f[i], c_.u32f[i]);
        }
        break;
      case 108:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32f) / sizeof(r_.u32f[0])) ; i++) {
          r_.u32f[i] = simde_x_ternarylogic_0x6c_impl_(a_.u32f[i], b_.u32f[i], c_.u32f[i]);
        }
        break;
      case 109:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32f) / sizeof(r_.u32f[0])) ; i++) {
          r_.u32f[i] = simde_x_ternarylogic_0x6d_impl_(a_.u32f[i], b_.u32f[i], c_.u32f[i]);
        }
        break;
      case 110:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32f) / sizeof(r_.u32f[0])) ; i++) {
          r_.u32f[i] = simde_x_ternarylogic_0x6e_impl_(a_.u32f[i], b_.u32f[i], c_.u32f[i]);
        }
        break;
      case 111:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32f) / sizeof(r_.u32f[0])) ; i++) {
          r_.u32f[i] = simde_x_ternarylogic_0x6f_impl_(a_.u32f[i], b_.u32f[i], c_.u32f[i]);
        }
        break;
      case 112:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32f) / sizeof(r_.u32f[0])) ; i++) {
          r_.u32f[i] = simde_x_ternarylogic_0x70_impl_(a_.u32f[i], b_.u32f[i], c_.u32f[i]);
        }
        break;
      case 113:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32f) / sizeof(r_.u32f[0])) ; i++) {
          r_.u32f[i] = simde_x_ternarylogic_0x71_impl_(a_.u32f[i], b_.u32f[i], c_.u32f[i]);
        }
        break;
      case 114:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32f) / sizeof(r_.u32f[0])) ; i++) {
          r_.u32f[i] = simde_x_ternarylogic_0x72_impl_(a_.u32f[i], b_.u32f[i], c_.u32f[i]);
        }
        break;
      case 115:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32f) / sizeof(r_.u32f[0])) ; i++) {
          r_.u32f[i] = simde_x_ternarylogic_0x73_impl_(a_.u32f[i], b_.u32f[i], c_.u32f[i]);
        }
        break;
      case 116:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32f) / sizeof(r_.u32f[0])) ; i++) {
          r_.u32f[i] = simde_x_ternarylogic_0x74_impl_(a_.u32f[i], b_.u32f[i], c_.u32f[i]);
        }
        break;
      case 117:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32f) / sizeof(r_.u32f[0])) ; i++) {
          r_.u32f[i] = simde_x_ternarylogic_0x75_impl_(a_.u32f[i], b_.u32f[i], c_.u32f[i]);
        }
        break;
      case 118:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32f) / sizeof(r_.u32f[0])) ; i++) {
          r_.u32f[i] = simde_x_ternarylogic_0x76_impl_(a_.u32f[i], b_.u32f[i], c_.u32f[i]);
        }
        break;
      case 119:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32f) / sizeof(r_.u32f[0])) ; i++) {
          r_.u32f[i] = simde_x_ternarylogic_0x77_impl_(a_.u32f[i], b_.u32f[i], c_.u32f[i]);
        }
        break;
      case 120:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32f) / sizeof(r_.u32f[0])) ; i++) {
          r_.u32f[i] = simde_x_ternarylogic_0x78_impl_(a_.u32f[i], b_.u32f[i], c_.u32f[i]);
        }
        break;
      case 121:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32f) / sizeof(r_.u32f[0])) ; i++) {
          r_.u32f[i] = simde_x_ternarylogic_0x79_impl_(a_.u32f[i], b_.u32f[i], c_.u32f[i]);
        }
        break;
      case 122:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32f) / sizeof(r_.u32f[0])) ; i++) {
          r_.u32f[i] = simde_x_ternarylogic_0x7a_impl_(a_.u32f[i], b_.u32f[i], c_.u32f[i]);
        }
        break;
      case 123:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32f) / sizeof(r_.u32f[0])) ; i++) {
          r_.u32f[i] = simde_x_ternarylogic_0x7b_impl_(a_.u32f[i], b_.u32f[i], c_.u32f[i]);
        }
        break;
      case 124:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32f) / sizeof(r_.u32f[0])) ; i++) {
          r_.u32f[i] = simde_x_ternarylogic_0x7c_impl_(a_.u32f[i], b_.u32f[i], c_.u32f[i]);
        }
        break;
      case 125:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32f) / sizeof(r_.u32f[0])) ; i++) {
          r_.u32f[i] = simde_x_ternarylogic_0x7d_impl_(a_.u32f[i], b_.u32f[i], c_.u32f[i]);
        }
        break;
      case 126:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32f) / sizeof(r_.u32f[0])) ; i++) {
          r_.u32f[i] = simde_x_ternarylogic_0x7e_impl_(a_.u32f[i], b_.u32f[i], c_.u32f[i]);
        }
        break;
      case 127:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32f) / sizeof(r_.u32f[0])) ; i++) {
          r_.u32f[i] = simde_x_ternarylogic_0x7f_impl_(a_.u32f[i], b_.u32f[i], c_.u32f[i]);
        }
        break;
    #if !defined(SIMDE_TERNARYLOGIC_COMPRESSION)
      case 128:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32f) / sizeof(r_.u32f[0])) ; i++) {
          r_.u32f[i] = simde_x_ternarylogic_0x80_impl_(a_.u32f[i], b_.u32f[i], c_.u32f[i]);
        }
        break;
      case 129:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32f) / sizeof(r_.u32f[0])) ; i++) {
          r_.u32f[i] = simde_x_ternarylogic_0x81_impl_(a_.u32f[i], b_.u32f[i], c_.u32f[i]);
        }
        break;
      case 130:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32f) / sizeof(r_.u32f[0])) ; i++) {
          r_.u32f[i] = simde_x_ternarylogic_0x82_impl_(a_.u32f[i], b_.u32f[i], c_.u32f[i]);
        }
        break;
      case 131:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32f) / sizeof(r_.u32f[0])) ; i++) {
          r_.u32f[i] = simde_x_ternarylogic_0x83_impl_(a_.u32f[i], b_.u32f[i], c_.u32f[i]);
        }
        break;
      case 132:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32f) / sizeof(r_.u32f[0])) ; i++) {
          r_.u32f[i] = simde_x_ternarylogic_0x84_impl_(a_.u32f[i], b_.u32f[i], c_.u32f[i]);
        }
        break;
      case 133:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32f) / sizeof(r_.u32f[0])) ; i++) {
          r_.u32f[i] = simde_x_ternarylogic_0x85_impl_(a_.u32f[i], b_.u32f[i], c_.u32f[i]);
        }
        break;
      case 134:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32f) / sizeof(r_.u32f[0])) ; i++) {
          r_.u32f[i] = simde_x_ternarylogic_0x86_impl_(a_.u32f[i], b_.u32f[i], c_.u32f[i]);
        }
        break;
      case 135:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32f) / sizeof(r_.u32f[0])) ; i++) {
          r_.u32f[i] = simde_x_ternarylogic_0x87_impl_(a_.u32f[i], b_.u32f[i], c_.u32f[i]);
        }
        break;
      case 136:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32f) / sizeof(r_.u32f[0])) ; i++) {
          r_.u32f[i] = simde_x_ternarylogic_0x88_impl_(a_.u32f[i], b_.u32f[i], c_.u32f[i]);
        }
        break;
      case 137:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32f) / sizeof(r_.u32f[0])) ; i++) {
          r_.u32f[i] = simde_x_ternarylogic_0x89_impl_(a_.u32f[i], b_.u32f[i], c_.u32f[i]);
        }
        break;
      case 138:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32f) / sizeof(r_.u32f[0])) ; i++) {
          r_.u32f[i] = simde_x_ternarylogic_0x8a_impl_(a_.u32f[i], b_.u32f[i], c_.u32f[i]);
        }
        break;
      case 139:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32f) / sizeof(r_.u32f[0])) ; i++) {
          r_.u32f[i] = simde_x_ternarylogic_0x8b_impl_(a_.u32f[i], b_.u32f[i], c_.u32f[i]);
        }
        break;
      case 140:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32f) / sizeof(r_.u32f[0])) ; i++) {
          r_.u32f[i] = simde_x_ternarylogic_0x8c_impl_(a_.u32f[i], b_.u32f[i], c_.u32f[i]);
        }
        break;
      case 141:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32f) / sizeof(r_.u32f[0])) ; i++) {
          r_.u32f[i] = simde_x_ternarylogic_0x8d_impl_(a_.u32f[i], b_.u32f[i], c_.u32f[i]);
        }
        break;
      case 142:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32f) / sizeof(r_.u32f[0])) ; i++) {
          r_.u32f[i] = simde_x_ternarylogic_0x8e_impl_(a_.u32f[i], b_.u32f[i], c_.u32f[i]);
        }
        break;
      case 143:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32f) / sizeof(r_.u32f[0])) ; i++) {
          r_.u32f[i] = simde_x_ternarylogic_0x8f_impl_(a_.u32f[i], b_.u32f[i], c_.u32f[i]);
        }
        break;
      case 144:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32f) / sizeof(r_.u32f[0])) ; i++) {
          r_.u32f[i] = simde_x_ternarylogic_0x90_impl_(a_.u32f[i], b_.u32f[i], c_.u32f[i]);
        }
        break;
      case 145:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32f) / sizeof(r_.u32f[0])) ; i++) {
          r_.u32f[i] = simde_x_ternarylogic_0x91_impl_(a_.u32f[i], b_.u32f[i], c_.u32f[i]);
        }
        break;
      case 146:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32f) / sizeof(r_.u32f[0])) ; i++) {
          r_.u32f[i] = simde_x_ternarylogic_0x92_impl_(a_.u32f[i], b_.u32f[i], c_.u32f[i]);
        }
        break;
      case 147:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32f) / sizeof(r_.u32f[0])) ; i++) {
          r_.u32f[i] = simde_x_ternarylogic_0x93_impl_(a_.u32f[i], b_.u32f[i], c_.u32f[i]);
        }
        break;
      case 148:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32f) / sizeof(r_.u32f[0])) ; i++) {
          r_.u32f[i] = simde_x_ternarylogic_0x94_impl_(a_.u32f[i], b_.u32f[i], c_.u32f[i]);
        }
        break;
      case 149:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32f) / sizeof(r_.u32f[0])) ; i++) {
          r_.u32f[i] = simde_x_ternarylogic_0x95_impl_(a_.u32f[i], b_.u32f[i], c_.u32f[i]);
        }
        break;
      case 150:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32f) / sizeof(r_.u32f[0])) ; i++) {
          r_.u32f[i] = simde_x_ternarylogic_0x96_impl_(a_.u32f[i], b_.u32f[i], c_.u32f[i]);
        }
        break;
      case 151:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32f) / sizeof(r_.u32f[0])) ; i++) {
          r_.u32f[i] = simde_x_ternarylogic_0x97_impl_(a_.u32f[i], b_.u32f[i], c_.u32f[i]);
        }
        break;
      case 152:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32f) / sizeof(r_.u32f[0])) ; i++) {
          r_.u32f[i] = simde_x_ternarylogic_0x98_impl_(a_.u32f[i], b_.u32f[i], c_.u32f[i]);
        }
        break;
      case 153:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32f) / sizeof(r_.u32f[0])) ; i++) {
          r_.u32f[i] = simde_x_ternarylogic_0x99_impl_(a_.u32f[i], b_.u32f[i], c_.u32f[i]);
        }
        break;
      case 154:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32f) / sizeof(r_.u32f[0])) ; i++) {
          r_.u32f[i] = simde_x_ternarylogic_0x9a_impl_(a_.u32f[i], b_.u32f[i], c_.u32f[i]);
        }
        break;
      case 155:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32f) / sizeof(r_.u32f[0])) ; i++) {
          r_.u32f[i] = simde_x_ternarylogic_0x9b_impl_(a_.u32f[i], b_.u32f[i], c_.u32f[i]);
        }
        break;
      case 156:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32f) / sizeof(r_.u32f[0])) ; i++) {
          r_.u32f[i] = simde_x_ternarylogic_0x9c_impl_(a_.u32f[i], b_.u32f[i], c_.u32f[i]);
        }
        break;
      case 157:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32f) / sizeof(r_.u32f[0])) ; i++) {
          r_.u32f[i] = simde_x_ternarylogic_0x9d_impl_(a_.u32f[i], b_.u32f[i], c_.u32f[i]);
        }
        break;
      case 158:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32f) / sizeof(r_.u32f[0])) ; i++) {
          r_.u32f[i] = simde_x_ternarylogic_0x9e_impl_(a_.u32f[i], b_.u32f[i], c_.u32f[i]);
        }
        break;
      case 159:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32f) / sizeof(r_.u32f[0])) ; i++) {
          r_.u32f[i] = simde_x_ternarylogic_0x9f_impl_(a_.u32f[i], b_.u32f[i], c_.u32f[i]);
        }
        break;
      case 160:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32f) / sizeof(r_.u32f[0])) ; i++) {
          r_.u32f[i] = simde_x_ternarylogic_0xa0_impl_(a_.u32f[i], b_.u32f[i], c_.u32f[i]);
        }
        break;
      case 161:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32f) / sizeof(r_.u32f[0])) ; i++) {
          r_.u32f[i] = simde_x_ternarylogic_0xa1_impl_(a_.u32f[i], b_.u32f[i], c_.u32f[i]);
        }
        break;
      case 162:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32f) / sizeof(r_.u32f[0])) ; i++) {
          r_.u32f[i] = simde_x_ternarylogic_0xa2_impl_(a_.u32f[i], b_.u32f[i], c_.u32f[i]);
        }
        break;
      case 163:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32f) / sizeof(r_.u32f[0])) ; i++) {
          r_.u32f[i] = simde_x_ternarylogic_0xa3_impl_(a_.u32f[i], b_.u32f[i], c_.u32f[i]);
        }
        break;
      case 164:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32f) / sizeof(r_.u32f[0])) ; i++) {
          r_.u32f[i] = simde_x_ternarylogic_0xa4_impl_(a_.u32f[i], b_.u32f[i], c_.u32f[i]);
        }
        break;
      case 165:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32f) / sizeof(r_.u32f[0])) ; i++) {
          r_.u32f[i] = simde_x_ternarylogic_0xa5_impl_(a_.u32f[i], b_.u32f[i], c_.u32f[i]);
        }
        break;
      case 166:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32f) / sizeof(r_.u32f[0])) ; i++) {
          r_.u32f[i] = simde_x_ternarylogic_0xa6_impl_(a_.u32f[i], b_.u32f[i], c_.u32f[i]);
        }
        break;
      case 167:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32f) / sizeof(r_.u32f[0])) ; i++) {
          r_.u32f[i] = simde_x_ternarylogic_0xa7_impl_(a_.u32f[i], b_.u32f[i], c_.u32f[i]);
        }
        break;
      case 168:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32f) / sizeof(r_.u32f[0])) ; i++) {
          r_.u32f[i] = simde_x_ternarylogic_0xa8_impl_(a_.u32f[i], b_.u32f[i], c_.u32f[i]);
        }
        break;
      case 169:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32f) / sizeof(r_.u32f[0])) ; i++) {
          r_.u32f[i] = simde_x_ternarylogic_0xa9_impl_(a_.u32f[i], b_.u32f[i], c_.u32f[i]);
        }
        break;
      case 170:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32f) / sizeof(r_.u32f[0])) ; i++) {
          r_.u32f[i] = simde_x_ternarylogic_0xaa_impl_(a_.u32f[i], b_.u32f[i], c_.u32f[i]);
        }
        break;
      case 171:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32f) / sizeof(r_.u32f[0])) ; i++) {
          r_.u32f[i] = simde_x_ternarylogic_0xab_impl_(a_.u32f[i], b_.u32f[i], c_.u32f[i]);
        }
        break;
      case 172:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32f) / sizeof(r_.u32f[0])) ; i++) {
          r_.u32f[i] = simde_x_ternarylogic_0xac_impl_(a_.u32f[i], b_.u32f[i], c_.u32f[i]);
        }
        break;
      case 173:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32f) / sizeof(r_.u32f[0])) ; i++) {
          r_.u32f[i] = simde_x_ternarylogic_0xad_impl_(a_.u32f[i], b_.u32f[i], c_.u32f[i]);
        }
        break;
      case 174:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32f) / sizeof(r_.u32f[0])) ; i++) {
          r_.u32f[i] = simde_x_ternarylogic_0xae_impl_(a_.u32f[i], b_.u32f[i], c_.u32f[i]);
        }
        break;
      case 175:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32f) / sizeof(r_.u32f[0])) ; i++) {
          r_.u32f[i] = simde_x_ternarylogic_0xaf_impl_(a_.u32f[i], b_.u32f[i], c_.u32f[i]);
        }
        break;
      case 176:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32f) / sizeof(r_.u32f[0])) ; i++) {
          r_.u32f[i] = simde_x_ternarylogic_0xb0_impl_(a_.u32f[i], b_.u32f[i], c_.u32f[i]);
        }
        break;
      case 177:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32f) / sizeof(r_.u32f[0])) ; i++) {
          r_.u32f[i] = simde_x_ternarylogic_0xb1_impl_(a_.u32f[i], b_.u32f[i], c_.u32f[i]);
        }
        break;
      case 178:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32f) / sizeof(r_.u32f[0])) ; i++) {
          r_.u32f[i] = simde_x_ternarylogic_0xb2_impl_(a_.u32f[i], b_.u32f[i], c_.u32f[i]);
        }
        break;
      case 179:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32f) / sizeof(r_.u32f[0])) ; i++) {
          r_.u32f[i] = simde_x_ternarylogic_0xb3_impl_(a_.u32f[i], b_.u32f[i], c_.u32f[i]);
        }
        break;
      case 180:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32f) / sizeof(r_.u32f[0])) ; i++) {
          r_.u32f[i] = simde_x_ternarylogic_0xb4_impl_(a_.u32f[i], b_.u32f[i], c_.u32f[i]);
        }
        break;
      case 181:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32f) / sizeof(r_.u32f[0])) ; i++) {
          r_.u32f[i] = simde_x_ternarylogic_0xb5_impl_(a_.u32f[i], b_.u32f[i], c_.u32f[i]);
        }
        break;
      case 182:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32f) / sizeof(r_.u32f[0])) ; i++) {
          r_.u32f[i] = simde_x_ternarylogic_0xb6_impl_(a_.u32f[i], b_.u32f[i], c_.u32f[i]);
        }
        break;
      case 183:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32f) / sizeof(r_.u32f[0])) ; i++) {
          r_.u32f[i] = simde_x_ternarylogic_0xb7_impl_(a_.u32f[i], b_.u32f[i], c_.u32f[i]);
        }
        break;
      case 184:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32f) / sizeof(r_.u32f[0])) ; i++) {
          r_.u32f[i] = simde_x_ternarylogic_0xb8_impl_(a_.u32f[i], b_.u32f[i], c_.u32f[i]);
        }
        break;
      case 185:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32f) / sizeof(r_.u32f[0])) ; i++) {
          r_.u32f[i] = simde_x_ternarylogic_0xb9_impl_(a_.u32f[i], b_.u32f[i], c_.u32f[i]);
        }
        break;
      case 186:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32f) / sizeof(r_.u32f[0])) ; i++) {
          r_.u32f[i] = simde_x_ternarylogic_0xba_impl_(a_.u32f[i], b_.u32f[i], c_.u32f[i]);
        }
        break;
      case 187:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32f) / sizeof(r_.u32f[0])) ; i++) {
          r_.u32f[i] = simde_x_ternarylogic_0xbb_impl_(a_.u32f[i], b_.u32f[i], c_.u32f[i]);
        }
        break;
      case 188:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32f) / sizeof(r_.u32f[0])) ; i++) {
          r_.u32f[i] = simde_x_ternarylogic_0xbc_impl_(a_.u32f[i], b_.u32f[i], c_.u32f[i]);
        }
        break;
      case 189:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32f) / sizeof(r_.u32f[0])) ; i++) {
          r_.u32f[i] = simde_x_ternarylogic_0xbd_impl_(a_.u32f[i], b_.u32f[i], c_.u32f[i]);
        }
        break;
      case 190:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32f) / sizeof(r_.u32f[0])) ; i++) {
          r_.u32f[i] = simde_x_ternarylogic_0xbe_impl_(a_.u32f[i], b_.u32f[i], c_.u32f[i]);
        }
        break;
      case 191:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32f) / sizeof(r_.u32f[0])) ; i++) {
          r_.u32f[i] = simde_x_ternarylogic_0xbf_impl_(a_.u32f[i], b_.u32f[i], c_.u32f[i]);
        }
        break;
      case 192:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32f) / sizeof(r_.u32f[0])) ; i++) {
          r_.u32f[i] = simde_x_ternarylogic_0xc0_impl_(a_.u32f[i], b_.u32f[i], c_.u32f[i]);
        }
        break;
      case 193:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32f) / sizeof(r_.u32f[0])) ; i++) {
          r_.u32f[i] = simde_x_ternarylogic_0xc1_impl_(a_.u32f[i], b_.u32f[i], c_.u32f[i]);
        }
        break;
      case 194:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32f) / sizeof(r_.u32f[0])) ; i++) {
          r_.u32f[i] = simde_x_ternarylogic_0xc2_impl_(a_.u32f[i], b_.u32f[i], c_.u32f[i]);
        }
        break;
      case 195:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32f) / sizeof(r_.u32f[0])) ; i++) {
          r_.u32f[i] = simde_x_ternarylogic_0xc3_impl_(a_.u32f[i], b_.u32f[i], c_.u32f[i]);
        }
        break;
      case 196:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32f) / sizeof(r_.u32f[0])) ; i++) {
          r_.u32f[i] = simde_x_ternarylogic_0xc4_impl_(a_.u32f[i], b_.u32f[i], c_.u32f[i]);
        }
        break;
      case 197:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32f) / sizeof(r_.u32f[0])) ; i++) {
          r_.u32f[i] = simde_x_ternarylogic_0xc5_impl_(a_.u32f[i], b_.u32f[i], c_.u32f[i]);
        }
        break;
      case 198:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32f) / sizeof(r_.u32f[0])) ; i++) {
          r_.u32f[i] = simde_x_ternarylogic_0xc6_impl_(a_.u32f[i], b_.u32f[i], c_.u32f[i]);
        }
        break;
      case 199:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32f) / sizeof(r_.u32f[0])) ; i++) {
          r_.u32f[i] = simde_x_ternarylogic_0xc7_impl_(a_.u32f[i], b_.u32f[i], c_.u32f[i]);
        }
        break;
      case 200:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32f) / sizeof(r_.u32f[0])) ; i++) {
          r_.u32f[i] = simde_x_ternarylogic_0xc8_impl_(a_.u32f[i], b_.u32f[i], c_.u32f[i]);
        }
        break;
      case 201:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32f) / sizeof(r_.u32f[0])) ; i++) {
          r_.u32f[i] = simde_x_ternarylogic_0xc9_impl_(a_.u32f[i], b_.u32f[i], c_.u32f[i]);
        }
        break;
      case 202:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32f) / sizeof(r_.u32f[0])) ; i++) {
          r_.u32f[i] = simde_x_ternarylogic_0xca_impl_(a_.u32f[i], b_.u32f[i], c_.u32f[i]);
        }
        break;
      case 203:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32f) / sizeof(r_.u32f[0])) ; i++) {
          r_.u32f[i] = simde_x_ternarylogic_0xcb_impl_(a_.u32f[i], b_.u32f[i], c_.u32f[i]);
        }
        break;
      case 204:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32f) / sizeof(r_.u32f[0])) ; i++) {
          r_.u32f[i] = simde_x_ternarylogic_0xcc_impl_(a_.u32f[i], b_.u32f[i], c_.u32f[i]);
        }
        break;
      case 205:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32f) / sizeof(r_.u32f[0])) ; i++) {
          r_.u32f[i] = simde_x_ternarylogic_0xcd_impl_(a_.u32f[i], b_.u32f[i], c_.u32f[i]);
        }
        break;
      case 206:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32f) / sizeof(r_.u32f[0])) ; i++) {
          r_.u32f[i] = simde_x_ternarylogic_0xce_impl_(a_.u32f[i], b_.u32f[i], c_.u32f[i]);
        }
        break;
      case 207:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32f) / sizeof(r_.u32f[0])) ; i++) {
          r_.u32f[i] = simde_x_ternarylogic_0xcf_impl_(a_.u32f[i], b_.u32f[i], c_.u32f[i]);
        }
        break;
      case 208:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32f) / sizeof(r_.u32f[0])) ; i++) {
          r_.u32f[i] = simde_x_ternarylogic_0xd0_impl_(a_.u32f[i], b_.u32f[i], c_.u32f[i]);
        }
        break;
      case 209:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32f) / sizeof(r_.u32f[0])) ; i++) {
          r_.u32f[i] = simde_x_ternarylogic_0xd1_impl_(a_.u32f[i], b_.u32f[i], c_.u32f[i]);
        }
        break;
      case 210:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32f) / sizeof(r_.u32f[0])) ; i++) {
          r_.u32f[i] = simde_x_ternarylogic_0xd2_impl_(a_.u32f[i], b_.u32f[i], c_.u32f[i]);
        }
        break;
      case 211:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32f) / sizeof(r_.u32f[0])) ; i++) {
          r_.u32f[i] = simde_x_ternarylogic_0xd3_impl_(a_.u32f[i], b_.u32f[i], c_.u32f[i]);
        }
        break;
      case 212:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32f) / sizeof(r_.u32f[0])) ; i++) {
          r_.u32f[i] = simde_x_ternarylogic_0xd4_impl_(a_.u32f[i], b_.u32f[i], c_.u32f[i]);
        }
        break;
      case 213:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32f) / sizeof(r_.u32f[0])) ; i++) {
          r_.u32f[i] = simde_x_ternarylogic_0xd5_impl_(a_.u32f[i], b_.u32f[i], c_.u32f[i]);
        }
        break;
      case 214:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32f) / sizeof(r_.u32f[0])) ; i++) {
          r_.u32f[i] = simde_x_ternarylogic_0xd6_impl_(a_.u32f[i], b_.u32f[i], c_.u32f[i]);
        }
        break;
      case 215:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32f) / sizeof(r_.u32f[0])) ; i++) {
          r_.u32f[i] = simde_x_ternarylogic_0xd7_impl_(a_.u32f[i], b_.u32f[i], c_.u32f[i]);
        }
        break;
      case 216:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32f) / sizeof(r_.u32f[0])) ; i++) {
          r_.u32f[i] = simde_x_ternarylogic_0xd8_impl_(a_.u32f[i], b_.u32f[i], c_.u32f[i]);
        }
        break;
      case 217:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32f) / sizeof(r_.u32f[0])) ; i++) {
          r_.u32f[i] = simde_x_ternarylogic_0xd9_impl_(a_.u32f[i], b_.u32f[i], c_.u32f[i]);
        }
        break;
      case 218:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32f) / sizeof(r_.u32f[0])) ; i++) {
          r_.u32f[i] = simde_x_ternarylogic_0xda_impl_(a_.u32f[i], b_.u32f[i], c_.u32f[i]);
        }
        break;
      case 219:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32f) / sizeof(r_.u32f[0])) ; i++) {
          r_.u32f[i] = simde_x_ternarylogic_0xdb_impl_(a_.u32f[i], b_.u32f[i], c_.u32f[i]);
        }
        break;
      case 220:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32f) / sizeof(r_.u32f[0])) ; i++) {
          r_.u32f[i] = simde_x_ternarylogic_0xdc_impl_(a_.u32f[i], b_.u32f[i], c_.u32f[i]);
        }
        break;
      case 221:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32f) / sizeof(r_.u32f[0])) ; i++) {
          r_.u32f[i] = simde_x_ternarylogic_0xdd_impl_(a_.u32f[i], b_.u32f[i], c_.u32f[i]);
        }
        break;
      case 222:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32f) / sizeof(r_.u32f[0])) ; i++) {
          r_.u32f[i] = simde_x_ternarylogic_0xde_impl_(a_.u32f[i], b_.u32f[i], c_.u32f[i]);
        }
        break;
      case 223:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32f) / sizeof(r_.u32f[0])) ; i++) {
          r_.u32f[i] = simde_x_ternarylogic_0xdf_impl_(a_.u32f[i], b_.u32f[i], c_.u32f[i]);
        }
        break;
      case 224:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32f) / sizeof(r_.u32f[0])) ; i++) {
          r_.u32f[i] = simde_x_ternarylogic_0xe0_impl_(a_.u32f[i], b_.u32f[i], c_.u32f[i]);
        }
        break;
      case 225:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32f) / sizeof(r_.u32f[0])) ; i++) {
          r_.u32f[i] = simde_x_ternarylogic_0xe1_impl_(a_.u32f[i], b_.u32f[i], c_.u32f[i]);
        }
        break;
      case 226:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32f) / sizeof(r_.u32f[0])) ; i++) {
          r_.u32f[i] = simde_x_ternarylogic_0xe2_impl_(a_.u32f[i], b_.u32f[i], c_.u32f[i]);
        }
        break;
      case 227:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32f) / sizeof(r_.u32f[0])) ; i++) {
          r_.u32f[i] = simde_x_ternarylogic_0xe3_impl_(a_.u32f[i], b_.u32f[i], c_.u32f[i]);
        }
        break;
      case 228:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32f) / sizeof(r_.u32f[0])) ; i++) {
          r_.u32f[i] = simde_x_ternarylogic_0xe4_impl_(a_.u32f[i], b_.u32f[i], c_.u32f[i]);
        }
        break;
      case 229:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32f) / sizeof(r_.u32f[0])) ; i++) {
          r_.u32f[i] = simde_x_ternarylogic_0xe5_impl_(a_.u32f[i], b_.u32f[i], c_.u32f[i]);
        }
        break;
      case 230:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32f) / sizeof(r_.u32f[0])) ; i++) {
          r_.u32f[i] = simde_x_ternarylogic_0xe6_impl_(a_.u32f[i], b_.u32f[i], c_.u32f[i]);
        }
        break;
      case 231:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32f) / sizeof(r_.u32f[0])) ; i++) {
          r_.u32f[i] = simde_x_ternarylogic_0xe7_impl_(a_.u32f[i], b_.u32f[i], c_.u32f[i]);
        }
        break;
      case 232:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32f) / sizeof(r_.u32f[0])) ; i++) {
          r_.u32f[i] = simde_x_ternarylogic_0xe8_impl_(a_.u32f[i], b_.u32f[i], c_.u32f[i]);
        }
        break;
      case 233:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32f) / sizeof(r_.u32f[0])) ; i++) {
          r_.u32f[i] = simde_x_ternarylogic_0xe9_impl_(a_.u32f[i], b_.u32f[i], c_.u32f[i]);
        }
        break;
      case 234:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32f) / sizeof(r_.u32f[0])) ; i++) {
          r_.u32f[i] = simde_x_ternarylogic_0xea_impl_(a_.u32f[i], b_.u32f[i], c_.u32f[i]);
        }
        break;
      case 235:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32f) / sizeof(r_.u32f[0])) ; i++) {
          r_.u32f[i] = simde_x_ternarylogic_0xeb_impl_(a_.u32f[i], b_.u32f[i], c_.u32f[i]);
        }
        break;
      case 236:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32f) / sizeof(r_.u32f[0])) ; i++) {
          r_.u32f[i] = simde_x_ternarylogic_0xec_impl_(a_.u32f[i], b_.u32f[i], c_.u32f[i]);
        }
        break;
      case 237:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32f) / sizeof(r_.u32f[0])) ; i++) {
          r_.u32f[i] = simde_x_ternarylogic_0xed_impl_(a_.u32f[i], b_.u32f[i], c_.u32f[i]);
        }
        break;
      case 238:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32f) / sizeof(r_.u32f[0])) ; i++) {
          r_.u32f[i] = simde_x_ternarylogic_0xee_impl_(a_.u32f[i], b_.u32f[i], c_.u32f[i]);
        }
        break;
      case 239:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32f) / sizeof(r_.u32f[0])) ; i++) {
          r_.u32f[i] = simde_x_ternarylogic_0xef_impl_(a_.u32f[i], b_.u32f[i], c_.u32f[i]);
        }
        break;
      case 240:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32f) / sizeof(r_.u32f[0])) ; i++) {
          r_.u32f[i] = simde_x_ternarylogic_0xf0_impl_(a_.u32f[i], b_.u32f[i], c_.u32f[i]);
        }
        break;
      case 241:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32f) / sizeof(r_.u32f[0])) ; i++) {
          r_.u32f[i] = simde_x_ternarylogic_0xf1_impl_(a_.u32f[i], b_.u32f[i], c_.u32f[i]);
        }
        break;
      case 242:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32f) / sizeof(r_.u32f[0])) ; i++) {
          r_.u32f[i] = simde_x_ternarylogic_0xf2_impl_(a_.u32f[i], b_.u32f[i], c_.u32f[i]);
        }
        break;
      case 243:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32f) / sizeof(r_.u32f[0])) ; i++) {
          r_.u32f[i] = simde_x_ternarylogic_0xf3_impl_(a_.u32f[i], b_.u32f[i], c_.u32f[i]);
        }
        break;
      case 244:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32f) / sizeof(r_.u32f[0])) ; i++) {
          r_.u32f[i] = simde_x_ternarylogic_0xf4_impl_(a_.u32f[i], b_.u32f[i], c_.u32f[i]);
        }
        break;
      case 245:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32f) / sizeof(r_.u32f[0])) ; i++) {
          r_.u32f[i] = simde_x_ternarylogic_0xf5_impl_(a_.u32f[i], b_.u32f[i], c_.u32f[i]);
        }
        break;
      case 246:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32f) / sizeof(r_.u32f[0])) ; i++) {
          r_.u32f[i] = simde_x_ternarylogic_0xf6_impl_(a_.u32f[i], b_.u32f[i], c_.u32f[i]);
        }
        break;
      case 247:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32f) / sizeof(r_.u32f[0])) ; i++) {
          r_.u32f[i] = simde_x_ternarylogic_0xf7_impl_(a_.u32f[i], b_.u32f[i], c_.u32f[i]);
        }
        break;
      case 248:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32f) / sizeof(r_.u32f[0])) ; i++) {
          r_.u32f[i] = simde_x_ternarylogic_0xf8_impl_(a_.u32f[i], b_.u32f[i], c_.u32f[i]);
        }
        break;
      case 249:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32f) / sizeof(r_.u32f[0])) ; i++) {
          r_.u32f[i] = simde_x_ternarylogic_0xf9_impl_(a_.u32f[i], b_.u32f[i], c_.u32f[i]);
        }
        break;
      case 250:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32f) / sizeof(r_.u32f[0])) ; i++) {
          r_.u32f[i] = simde_x_ternarylogic_0xfa_impl_(a_.u32f[i], b_.u32f[i], c_.u32f[i]);
        }
        break;
      case 251:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32f) / sizeof(r_.u32f[0])) ; i++) {
          r_.u32f[i] = simde_x_ternarylogic_0xfb_impl_(a_.u32f[i], b_.u32f[i], c_.u32f[i]);
        }
        break;
      case 252:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32f) / sizeof(r_.u32f[0])) ; i++) {
          r_.u32f[i] = simde_x_ternarylogic_0xfc_impl_(a_.u32f[i], b_.u32f[i], c_.u32f[i]);
        }
        break;
      case 253:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32f) / sizeof(r_.u32f[0])) ; i++) {
          r_.u32f[i] = simde_x_ternarylogic_0xfd_impl_(a_.u32f[i], b_.u32f[i], c_.u32f[i]);
        }
        break;
      case 254:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32f) / sizeof(r_.u32f[0])) ; i++) {
          r_.u32f[i] = simde_x_ternarylogic_0xfe_impl_(a_.u32f[i], b_.u32f[i], c_.u32f[i]);
        }
        break;
      case 255:
        SIMDE_VECTORIZE
        for(size_t i = 0 ; i < (sizeof(r_.u32f) / sizeof(r_.u32f[0])) ; i++) {
          r_.u32f[i] = simde_x_ternarylogic_0xff_impl_(a_.u32f[i], b_.u32f[i], c_.u32f[i]);
        }
        break;
    #endif
    }

  #if defined(SIMDE_TERNARYLOGIC_COMPRESSION)
    r_ = simde__m128i_to_private(simde_mm_xor_si128(simde__m128i_from_private(r_), simde_mm_movm_epi32(HEDLEY_STATIC_CAST(uint8_t, (HEDLEY_STATIC_CAST(int8_t, imm8) >> 7)))));
  #endif

    return simde__m128i_from_private(r_);
  }
#endif
#if defined(SIMDE_X86_AVX512VL_ENABLE_NATIVE_ALIASES) && defined(SIMDE_X86_AVX512F_ENABLE_NATIVE_ALIASES)
  #undef _mm_ternarylogic_epi32
  #define _mm_ternarylogic_epi32(a, b, c, imm8) simde_mm_ternarylogic_epi32(a, b, c, imm8)
#endif


SIMDE_END_DECLS_
HEDLEY_DIAGNOSTIC_POP

#endif /* !defined(SIMDE_X86_AVX512_TERNARYLOGIC_H) */
