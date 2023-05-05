#if !defined(SIMDE_TEST_X86_TEST_AVX_H)
#define SIMDE_TEST_X86_TEST_AVX_H

#include "test-x86.h"
#include "test-sse2.h"
#include "../../simde/x86/avx.h"

HEDLEY_DIAGNOSTIC_PUSH
SIMDE_DISABLE_UNWANTED_DIAGNOSTICS

SIMDE_TEST_X86_GENERATE_FLOAT_TYPE_FUNCS_(__m256, 32, 8, simde_mm256_storeu_ps)
SIMDE_TEST_X86_GENERATE_FLOAT_TYPE_FUNCS_(__m256d, 64, 4, simde_mm256_storeu_pd)
SIMDE_TEST_X86_GENERATE_INT_TYPE_FUNCS_(__m256i, 8, 32, simde_mm256_storeu_si256)
SIMDE_TEST_X86_GENERATE_INT_TYPE_FUNCS_(__m256i, 16, 16, simde_mm256_storeu_si256)
SIMDE_TEST_X86_GENERATE_INT_TYPE_FUNCS_(__m256i, 32, 8, simde_mm256_storeu_si256)
SIMDE_TEST_X86_GENERATE_INT_TYPE_FUNCS_(__m256i, 64, 4, simde_mm256_storeu_si256)
SIMDE_TEST_X86_GENERATE_UINT_TYPE_FUNCS_(__m256i, 8, 32, simde_mm256_storeu_si256)
SIMDE_TEST_X86_GENERATE_UINT_TYPE_FUNCS_(__m256i, 16, 16, simde_mm256_storeu_si256)
SIMDE_TEST_X86_GENERATE_UINT_TYPE_FUNCS_(__m256i, 32, 8, simde_mm256_storeu_si256)
SIMDE_TEST_X86_GENERATE_UINT_TYPE_FUNCS_(__m256i, 64, 4, simde_mm256_storeu_si256)

#define simde_test_x86_assert_equal_f32x8(a, b, precision) do { if (simde_test_x86_assert_equal_f32x8_(a, b, simde_test_f32_precision_to_slop(precision), __FILE__, __LINE__, #a, #b)) { return 1; } } while (0)
#define simde_test_x86_assert_equal_f64x4(a, b, precision) do { if (simde_test_x86_assert_equal_f64x4_(a, b, simde_test_f64_precision_to_slop(precision), __FILE__, __LINE__, #a, #b)) { return 1; } } while (0)
#define simde_test_x86_assert_equal_i8x32(a, b) do { if (simde_test_x86_assert_equal_i8x32_(a, b, __FILE__, __LINE__, #a, #b)) { return 1; } } while (0)
#define simde_test_x86_assert_equal_i16x16(a, b) do { if (simde_test_x86_assert_equal_i16x16_(a, b, __FILE__, __LINE__, #a, #b)) { return 1; } } while (0)
#define simde_test_x86_assert_equal_i32x8(a, b) do { if (simde_test_x86_assert_equal_i32x8_(a, b, __FILE__, __LINE__, #a, #b)) { return 1; } } while (0)
#define simde_test_x86_assert_equal_i64x4(a, b) do { if (simde_test_x86_assert_equal_i64x4_(a, b, __FILE__, __LINE__, #a, #b)) { return 1; } } while (0)
#define simde_test_x86_assert_equal_u8x32(a, b) do { if (simde_test_x86_assert_equal_u8x32_(a, b, __FILE__, __LINE__, #a, #b)) { return 1; } } while (0)
#define simde_test_x86_assert_equal_u16x16(a, b) do { if (simde_test_x86_assert_equal_u16x16_(a, b, __FILE__, __LINE__, #a, #b)) { return 1; } } while (0)
#define simde_test_x86_assert_equal_u32x8(a, b) do { if (simde_test_x86_assert_equal_u32x8_(a, b, __FILE__, __LINE__, #a, #b)) { return 1; } } while (0)
#define simde_test_x86_assert_equal_u64x4(a, b) do { if (simde_test_x86_assert_equal_u64x4_(a, b, __FILE__, __LINE__, #a, #b)) { return 1; } } while (0)

/* SIMDE_DISABLE_UNWANTED_DIAGNOSTICS */
HEDLEY_DIAGNOSTIC_POP

HEDLEY_DIAGNOSTIC_PUSH
SIMDE_DIAGNOSTIC_DISABLE_VARIADIC_MACROS_

#define SIMDE_CONSTIFY_256_(func_name, result, default_case, imm, ...) \
  do { \
    switch(imm) { \
      case  0: result = func_name(__VA_ARGS__,  0); break; \
      case  1: result = func_name(__VA_ARGS__,  1); break; \
      case  2: result = func_name(__VA_ARGS__,  2); break; \
      case  3: result = func_name(__VA_ARGS__,  3); break; \
      case  4: result = func_name(__VA_ARGS__,  4); break; \
      case  5: result = func_name(__VA_ARGS__,  5); break; \
      case  6: result = func_name(__VA_ARGS__,  6); break; \
      case  7: result = func_name(__VA_ARGS__,  7); break; \
      case  8: result = func_name(__VA_ARGS__,  8); break; \
      case  9: result = func_name(__VA_ARGS__,  9); break; \
      case 10: result = func_name(__VA_ARGS__, 10); break; \
      case 11: result = func_name(__VA_ARGS__, 11); break; \
      case 12: result = func_name(__VA_ARGS__, 12); break; \
      case 13: result = func_name(__VA_ARGS__, 13); break; \
      case 14: result = func_name(__VA_ARGS__, 14); break; \
      case 15: result = func_name(__VA_ARGS__, 15); break; \
      case 16: result = func_name(__VA_ARGS__, 16); break; \
      case 17: result = func_name(__VA_ARGS__, 17); break; \
      case 18: result = func_name(__VA_ARGS__, 18); break; \
      case 19: result = func_name(__VA_ARGS__, 19); break; \
      case 20: result = func_name(__VA_ARGS__, 20); break; \
      case 21: result = func_name(__VA_ARGS__, 21); break; \
      case 22: result = func_name(__VA_ARGS__, 22); break; \
      case 23: result = func_name(__VA_ARGS__, 23); break; \
      case 24: result = func_name(__VA_ARGS__, 24); break; \
      case 25: result = func_name(__VA_ARGS__, 25); break; \
      case 26: result = func_name(__VA_ARGS__, 26); break; \
      case 27: result = func_name(__VA_ARGS__, 27); break; \
      case 28: result = func_name(__VA_ARGS__, 28); break; \
      case 29: result = func_name(__VA_ARGS__, 29); break; \
      case 30: result = func_name(__VA_ARGS__, 30); break; \
      case 31: result = func_name(__VA_ARGS__, 31); break; \
      case 32: result = func_name(__VA_ARGS__, 32); break; \
      case 33: result = func_name(__VA_ARGS__, 33); break; \
      case 34: result = func_name(__VA_ARGS__, 34); break; \
      case 35: result = func_name(__VA_ARGS__, 35); break; \
      case 36: result = func_name(__VA_ARGS__, 36); break; \
      case 37: result = func_name(__VA_ARGS__, 37); break; \
      case 38: result = func_name(__VA_ARGS__, 38); break; \
      case 39: result = func_name(__VA_ARGS__, 39); break; \
      case 40: result = func_name(__VA_ARGS__, 40); break; \
      case 41: result = func_name(__VA_ARGS__, 41); break; \
      case 42: result = func_name(__VA_ARGS__, 42); break; \
      case 43: result = func_name(__VA_ARGS__, 43); break; \
      case 44: result = func_name(__VA_ARGS__, 44); break; \
      case 45: result = func_name(__VA_ARGS__, 45); break; \
      case 46: result = func_name(__VA_ARGS__, 46); break; \
      case 47: result = func_name(__VA_ARGS__, 47); break; \
      case 48: result = func_name(__VA_ARGS__, 48); break; \
      case 49: result = func_name(__VA_ARGS__, 49); break; \
      case 50: result = func_name(__VA_ARGS__, 50); break; \
      case 51: result = func_name(__VA_ARGS__, 51); break; \
      case 52: result = func_name(__VA_ARGS__, 52); break; \
      case 53: result = func_name(__VA_ARGS__, 53); break; \
      case 54: result = func_name(__VA_ARGS__, 54); break; \
      case 55: result = func_name(__VA_ARGS__, 55); break; \
      case 56: result = func_name(__VA_ARGS__, 56); break; \
      case 57: result = func_name(__VA_ARGS__, 57); break; \
      case 58: result = func_name(__VA_ARGS__, 58); break; \
      case 59: result = func_name(__VA_ARGS__, 59); break; \
      case 60: result = func_name(__VA_ARGS__, 60); break; \
      case 61: result = func_name(__VA_ARGS__, 61); break; \
      case 62: result = func_name(__VA_ARGS__, 62); break; \
      case 63: result = func_name(__VA_ARGS__, 63); break; \
      case 64: result = func_name(__VA_ARGS__, 64); break; \
      case 65: result = func_name(__VA_ARGS__, 65); break; \
      case 66: result = func_name(__VA_ARGS__, 66); break; \
      case 67: result = func_name(__VA_ARGS__, 67); break; \
      case 68: result = func_name(__VA_ARGS__, 68); break; \
      case 69: result = func_name(__VA_ARGS__, 69); break; \
      case 70: result = func_name(__VA_ARGS__, 70); break; \
      case 71: result = func_name(__VA_ARGS__, 71); break; \
      case 72: result = func_name(__VA_ARGS__, 72); break; \
      case 73: result = func_name(__VA_ARGS__, 73); break; \
      case 74: result = func_name(__VA_ARGS__, 74); break; \
      case 75: result = func_name(__VA_ARGS__, 75); break; \
      case 76: result = func_name(__VA_ARGS__, 76); break; \
      case 77: result = func_name(__VA_ARGS__, 77); break; \
      case 78: result = func_name(__VA_ARGS__, 78); break; \
      case 79: result = func_name(__VA_ARGS__, 79); break; \
      case 80: result = func_name(__VA_ARGS__, 80); break; \
      case 81: result = func_name(__VA_ARGS__, 81); break; \
      case 82: result = func_name(__VA_ARGS__, 82); break; \
      case 83: result = func_name(__VA_ARGS__, 83); break; \
      case 84: result = func_name(__VA_ARGS__, 84); break; \
      case 85: result = func_name(__VA_ARGS__, 85); break; \
      case 86: result = func_name(__VA_ARGS__, 86); break; \
      case 87: result = func_name(__VA_ARGS__, 87); break; \
      case 88: result = func_name(__VA_ARGS__, 88); break; \
      case 89: result = func_name(__VA_ARGS__, 89); break; \
      case 90: result = func_name(__VA_ARGS__, 90); break; \
      case 91: result = func_name(__VA_ARGS__, 91); break; \
      case 92: result = func_name(__VA_ARGS__, 92); break; \
      case 93: result = func_name(__VA_ARGS__, 93); break; \
      case 94: result = func_name(__VA_ARGS__, 94); break; \
      case 95: result = func_name(__VA_ARGS__, 95); break; \
      case 96: result = func_name(__VA_ARGS__, 96); break; \
      case 97: result = func_name(__VA_ARGS__, 97); break; \
      case 98: result = func_name(__VA_ARGS__, 98); break; \
      case 99: result = func_name(__VA_ARGS__, 99); break; \
      case 100: result = func_name(__VA_ARGS__, 100); break; \
      case 101: result = func_name(__VA_ARGS__, 101); break; \
      case 102: result = func_name(__VA_ARGS__, 102); break; \
      case 103: result = func_name(__VA_ARGS__, 103); break; \
      case 104: result = func_name(__VA_ARGS__, 104); break; \
      case 105: result = func_name(__VA_ARGS__, 105); break; \
      case 106: result = func_name(__VA_ARGS__, 106); break; \
      case 107: result = func_name(__VA_ARGS__, 107); break; \
      case 108: result = func_name(__VA_ARGS__, 108); break; \
      case 109: result = func_name(__VA_ARGS__, 109); break; \
      case 110: result = func_name(__VA_ARGS__, 110); break; \
      case 111: result = func_name(__VA_ARGS__, 111); break; \
      case 112: result = func_name(__VA_ARGS__, 112); break; \
      case 113: result = func_name(__VA_ARGS__, 113); break; \
      case 114: result = func_name(__VA_ARGS__, 114); break; \
      case 115: result = func_name(__VA_ARGS__, 115); break; \
      case 116: result = func_name(__VA_ARGS__, 116); break; \
      case 117: result = func_name(__VA_ARGS__, 117); break; \
      case 118: result = func_name(__VA_ARGS__, 118); break; \
      case 119: result = func_name(__VA_ARGS__, 119); break; \
      case 120: result = func_name(__VA_ARGS__, 120); break; \
      case 121: result = func_name(__VA_ARGS__, 121); break; \
      case 122: result = func_name(__VA_ARGS__, 122); break; \
      case 123: result = func_name(__VA_ARGS__, 123); break; \
      case 124: result = func_name(__VA_ARGS__, 124); break; \
      case 125: result = func_name(__VA_ARGS__, 125); break; \
      case 126: result = func_name(__VA_ARGS__, 126); break; \
      case 127: result = func_name(__VA_ARGS__, 127); break; \
      case 128: result = func_name(__VA_ARGS__, 128); break; \
      case 129: result = func_name(__VA_ARGS__, 129); break; \
      case 130: result = func_name(__VA_ARGS__, 130); break; \
      case 131: result = func_name(__VA_ARGS__, 131); break; \
      case 132: result = func_name(__VA_ARGS__, 132); break; \
      case 133: result = func_name(__VA_ARGS__, 133); break; \
      case 134: result = func_name(__VA_ARGS__, 134); break; \
      case 135: result = func_name(__VA_ARGS__, 135); break; \
      case 136: result = func_name(__VA_ARGS__, 136); break; \
      case 137: result = func_name(__VA_ARGS__, 137); break; \
      case 138: result = func_name(__VA_ARGS__, 138); break; \
      case 139: result = func_name(__VA_ARGS__, 139); break; \
      case 140: result = func_name(__VA_ARGS__, 140); break; \
      case 141: result = func_name(__VA_ARGS__, 141); break; \
      case 142: result = func_name(__VA_ARGS__, 142); break; \
      case 143: result = func_name(__VA_ARGS__, 143); break; \
      case 144: result = func_name(__VA_ARGS__, 144); break; \
      case 145: result = func_name(__VA_ARGS__, 145); break; \
      case 146: result = func_name(__VA_ARGS__, 146); break; \
      case 147: result = func_name(__VA_ARGS__, 147); break; \
      case 148: result = func_name(__VA_ARGS__, 148); break; \
      case 149: result = func_name(__VA_ARGS__, 149); break; \
      case 150: result = func_name(__VA_ARGS__, 150); break; \
      case 151: result = func_name(__VA_ARGS__, 151); break; \
      case 152: result = func_name(__VA_ARGS__, 152); break; \
      case 153: result = func_name(__VA_ARGS__, 153); break; \
      case 154: result = func_name(__VA_ARGS__, 154); break; \
      case 155: result = func_name(__VA_ARGS__, 155); break; \
      case 156: result = func_name(__VA_ARGS__, 156); break; \
      case 157: result = func_name(__VA_ARGS__, 157); break; \
      case 158: result = func_name(__VA_ARGS__, 158); break; \
      case 159: result = func_name(__VA_ARGS__, 159); break; \
      case 160: result = func_name(__VA_ARGS__, 160); break; \
      case 161: result = func_name(__VA_ARGS__, 161); break; \
      case 162: result = func_name(__VA_ARGS__, 162); break; \
      case 163: result = func_name(__VA_ARGS__, 163); break; \
      case 164: result = func_name(__VA_ARGS__, 164); break; \
      case 165: result = func_name(__VA_ARGS__, 165); break; \
      case 166: result = func_name(__VA_ARGS__, 166); break; \
      case 167: result = func_name(__VA_ARGS__, 167); break; \
      case 168: result = func_name(__VA_ARGS__, 168); break; \
      case 169: result = func_name(__VA_ARGS__, 169); break; \
      case 170: result = func_name(__VA_ARGS__, 170); break; \
      case 171: result = func_name(__VA_ARGS__, 171); break; \
      case 172: result = func_name(__VA_ARGS__, 172); break; \
      case 173: result = func_name(__VA_ARGS__, 173); break; \
      case 174: result = func_name(__VA_ARGS__, 174); break; \
      case 175: result = func_name(__VA_ARGS__, 175); break; \
      case 176: result = func_name(__VA_ARGS__, 176); break; \
      case 177: result = func_name(__VA_ARGS__, 177); break; \
      case 178: result = func_name(__VA_ARGS__, 178); break; \
      case 179: result = func_name(__VA_ARGS__, 179); break; \
      case 180: result = func_name(__VA_ARGS__, 180); break; \
      case 181: result = func_name(__VA_ARGS__, 181); break; \
      case 182: result = func_name(__VA_ARGS__, 182); break; \
      case 183: result = func_name(__VA_ARGS__, 183); break; \
      case 184: result = func_name(__VA_ARGS__, 184); break; \
      case 185: result = func_name(__VA_ARGS__, 185); break; \
      case 186: result = func_name(__VA_ARGS__, 186); break; \
      case 187: result = func_name(__VA_ARGS__, 187); break; \
      case 188: result = func_name(__VA_ARGS__, 188); break; \
      case 189: result = func_name(__VA_ARGS__, 189); break; \
      case 190: result = func_name(__VA_ARGS__, 190); break; \
      case 191: result = func_name(__VA_ARGS__, 191); break; \
      case 192: result = func_name(__VA_ARGS__, 192); break; \
      case 193: result = func_name(__VA_ARGS__, 193); break; \
      case 194: result = func_name(__VA_ARGS__, 194); break; \
      case 195: result = func_name(__VA_ARGS__, 195); break; \
      case 196: result = func_name(__VA_ARGS__, 196); break; \
      case 197: result = func_name(__VA_ARGS__, 197); break; \
      case 198: result = func_name(__VA_ARGS__, 198); break; \
      case 199: result = func_name(__VA_ARGS__, 199); break; \
      case 200: result = func_name(__VA_ARGS__, 200); break; \
      case 201: result = func_name(__VA_ARGS__, 201); break; \
      case 202: result = func_name(__VA_ARGS__, 202); break; \
      case 203: result = func_name(__VA_ARGS__, 203); break; \
      case 204: result = func_name(__VA_ARGS__, 204); break; \
      case 205: result = func_name(__VA_ARGS__, 205); break; \
      case 206: result = func_name(__VA_ARGS__, 206); break; \
      case 207: result = func_name(__VA_ARGS__, 207); break; \
      case 208: result = func_name(__VA_ARGS__, 208); break; \
      case 209: result = func_name(__VA_ARGS__, 209); break; \
      case 210: result = func_name(__VA_ARGS__, 210); break; \
      case 211: result = func_name(__VA_ARGS__, 211); break; \
      case 212: result = func_name(__VA_ARGS__, 212); break; \
      case 213: result = func_name(__VA_ARGS__, 213); break; \
      case 214: result = func_name(__VA_ARGS__, 214); break; \
      case 215: result = func_name(__VA_ARGS__, 215); break; \
      case 216: result = func_name(__VA_ARGS__, 216); break; \
      case 217: result = func_name(__VA_ARGS__, 217); break; \
      case 218: result = func_name(__VA_ARGS__, 218); break; \
      case 219: result = func_name(__VA_ARGS__, 219); break; \
      case 220: result = func_name(__VA_ARGS__, 220); break; \
      case 221: result = func_name(__VA_ARGS__, 221); break; \
      case 222: result = func_name(__VA_ARGS__, 222); break; \
      case 223: result = func_name(__VA_ARGS__, 223); break; \
      case 224: result = func_name(__VA_ARGS__, 224); break; \
      case 225: result = func_name(__VA_ARGS__, 225); break; \
      case 226: result = func_name(__VA_ARGS__, 226); break; \
      case 227: result = func_name(__VA_ARGS__, 227); break; \
      case 228: result = func_name(__VA_ARGS__, 228); break; \
      case 229: result = func_name(__VA_ARGS__, 229); break; \
      case 230: result = func_name(__VA_ARGS__, 230); break; \
      case 231: result = func_name(__VA_ARGS__, 231); break; \
      case 232: result = func_name(__VA_ARGS__, 232); break; \
      case 233: result = func_name(__VA_ARGS__, 233); break; \
      case 234: result = func_name(__VA_ARGS__, 234); break; \
      case 235: result = func_name(__VA_ARGS__, 235); break; \
      case 236: result = func_name(__VA_ARGS__, 236); break; \
      case 237: result = func_name(__VA_ARGS__, 237); break; \
      case 238: result = func_name(__VA_ARGS__, 238); break; \
      case 239: result = func_name(__VA_ARGS__, 239); break; \
      case 240: result = func_name(__VA_ARGS__, 240); break; \
      case 241: result = func_name(__VA_ARGS__, 241); break; \
      case 242: result = func_name(__VA_ARGS__, 242); break; \
      case 243: result = func_name(__VA_ARGS__, 243); break; \
      case 244: result = func_name(__VA_ARGS__, 244); break; \
      case 245: result = func_name(__VA_ARGS__, 245); break; \
      case 246: result = func_name(__VA_ARGS__, 246); break; \
      case 247: result = func_name(__VA_ARGS__, 247); break; \
      case 248: result = func_name(__VA_ARGS__, 248); break; \
      case 249: result = func_name(__VA_ARGS__, 249); break; \
      case 250: result = func_name(__VA_ARGS__, 250); break; \
      case 251: result = func_name(__VA_ARGS__, 251); break; \
      case 252: result = func_name(__VA_ARGS__, 252); break; \
      case 253: result = func_name(__VA_ARGS__, 253); break; \
      case 254: result = func_name(__VA_ARGS__, 254); break; \
      case 255: result = func_name(__VA_ARGS__, 255); break; \
      default: result = default_case; break; \
    } \
  } while (0)

HEDLEY_DIAGNOSTIC_POP


#endif /* !defined(SIMDE_TEST_X86_TEST_AVX_H) */
