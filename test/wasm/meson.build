simde_test_wasm_simd128_tests = [
  'abs',
  'add',
  'add_saturate',
  'all_true',
  'and',
  'andnot',
  'any_true',
  'avgr',
  'bitselect',
  'convert',
  'div',
  'eq',
  'extract_lane',
  'ge',
  'gt',
  'load_splat',
  'le',
  'lt',
  'load',
  'make',
  'max',
  'min',
  'mul',
  'narrow',
  'ne',
  'neg',
  'not',
  'or',
  'pmax',
  'pmin',
  'replace_lane',
  'shl',
  'shuffle',
  'shr',
  'splat',
  'sub',
  'sub_saturate',
  'swizzle',
  'trunc_saturate',
  'widen_low',
  'widen_high',
  'xor',
]

simde_test_wasm_simd128_sources = []
simde_test_wasm_simd128_libs = []
foreach name : simde_test_wasm_simd128_tests
  foreach lang : ['c', 'cpp']
    source_file = name + '.c'
    if lang == 'cpp'
      source_file = configure_file(input: name + '.c', output: name + '.cpp', copy: true)
    endif
    simde_test_wasm_simd128_sources += source_file

    foreach emul : ['emul', 'native']
      extra_flags = ['-DSIMDE_TEST_BARE']
      if emul == 'emul'
        extra_flags += '-DSIMDE_NO_NATIVE'
      endif

      x = executable(name + '-' + emul +  '-' + lang, source_file,
          c_args: simde_c_args + simde_c_defs + simde_native_c_flags + extra_flags,
          cpp_args: simde_c_args + simde_c_defs + simde_native_c_flags + extra_flags,
          include_directories: simde_include_dir,
          dependencies: simde_deps)

      test('wasm_simd/' + name + '/' + emul + '/' + lang, x,
          protocol: 'tap',
          # Emscripten tests must be run from builddir
          workdir: meson.current_build_dir())
    endforeach
  endforeach
endforeach
