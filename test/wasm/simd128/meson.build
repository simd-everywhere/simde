fs = import('fs')

simde_test_wasm_simd128_tests = [
  'abs',
  'add',
  'add_sat',
  'all_true',
  'and',
  'andnot',
  'any_true',
  'avgr',
  'bitmask',
  'bitselect',
  'ceil',
  'const',
  'convert',
  'demote',
  'div',
  'dot',
  'eq',
  'extract_lane',
  'extadd_pairwise',
  'extmul_high',
  'extmul_low',
  'floor',
  'ge',
  'gt',
  'load_splat',
  'le',
  'lt',
  'load',
  'load_zero',
  'load_lane',
  'make',
  'max',
  'min',
  'mul',
  'narrow',
  'ne',
  'nearest',
  'neg',
  'not',
  'or',
  'pmax',
  'pmin',
  'popcnt',
  'promote',
  'q15mulr_sat',
  'replace_lane',
  'shl',
  'shuffle',
  'shr',
  'splat',
  'sqrt',
  'store_lane',
  'sub',
  'sub_sat',
  'swizzle',
  'trunc_sat',
  'trunc',
  'extend_low',
  'extend_high',
  'xor',
]

# Exercise the scalar fallbacks separately from compiler vector extensions.
simde_test_wasm_simd128_scalar_tests = [
  'abs', 'add', 'convert', 'demote', 'dot', 'mul', 'neg', 'promote',
  'shl', 'sub', 'trunc_sat',
]
simde_test_wasm_simd128_scalar_c_args = cc.get_supported_arguments('-Werror=float-conversion')
simde_test_wasm_simd128_scalar_cpp_args = cxx.get_supported_arguments('-Werror=float-conversion')

simde_test_wasm_simd128_sources = []
simde_test_wasm_simd128_libs = []
foreach name : simde_test_wasm_simd128_tests
  foreach lang : ['c', 'cpp']
    source_file = name + '.c'
    if lang == 'cpp'
      source_file = fs.copyfile(name + '.c', name + '.cpp')
    endif
    simde_test_wasm_simd128_sources += source_file

    foreach emul : ['emul', 'native', 'scalar']
      if emul == 'scalar' and name not in simde_test_wasm_simd128_scalar_tests
        continue
      endif

      extra_flags = ['-DSIMDE_TEST_BARE']
      if emul != 'native'
        extra_flags += '-DSIMDE_NO_NATIVE'
      endif
      if emul == 'scalar'
        extra_flags += '-DSIMDE_NO_VECTOR'
        if lang == 'c'
          extra_flags += simde_test_wasm_simd128_scalar_c_args
        else
          extra_flags += simde_test_wasm_simd128_scalar_cpp_args
        endif
      endif

      x = executable(name + '-' + emul +  '-' + lang, source_file,
          c_args: simde_c_args + simde_c_defs + simde_native_c_flags + extra_flags,
          cpp_args: simde_c_args + simde_c_defs + simde_native_c_flags + extra_flags,
          include_directories: simde_include_dir,
          dependencies: simde_deps)

      test('wasm_simd128/' + name + '/' + emul + '/' + lang, x,
          protocol: 'tap',
          # Emscripten tests must be run from builddir
          workdir: meson.current_build_dir())
    endforeach
  endforeach
endforeach
