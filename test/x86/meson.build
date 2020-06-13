simde_test_x86_tests = [
  'mmx',
  'sse',
  'sse2',
  'sse3',
  'ssse3',
  'sse4.1',
  'sse4.2',
  'avx',
  'avx2',
  'fma',
  'avx512f',
  'avx512bw',
  'avx512vl',
  'avx512dq',
  'avx512cd',
  'gfni',
  'svml'
]

simde_test_x86_sources = []
simde_test_x86_libs = []
foreach name : simde_test_x86_tests
  c_source = name + '.c'
  cpp_source = configure_file(input: name + '.c', output: name + '.cpp', copy: true)
  simde_test_x86_sources += [c_source, cpp_source]

  test('x86/' + name + '/emul/c', executable(name + '-emul-c', c_source,
      c_args: simde_c_args + simde_c_defs + simde_native_c_flags + ['-DSIMDE_NO_NATIVE', '-DSIMDE_TEST_BARE'],
      include_directories: simde_include_dir,
      dependencies: libm),
    protocol: 'tap')
  test('x86/' + name + '/emul/cpp', executable(name + '-emul-cpp', cpp_source,
      cpp_args: simde_c_args + simde_c_defs + simde_native_c_flags + ['-DSIMDE_NO_NATIVE', '-DSIMDE_TEST_BARE'],
      include_directories: simde_include_dir,
      dependencies: libm),
    protocol: 'tap')
  test('x86/' + name + '/native/c', executable(name + '-native-c', c_source,
      c_args: simde_c_args + simde_c_defs + simde_native_c_flags + ['-DSIMDE_TEST_BARE'],
      include_directories: simde_include_dir,
      dependencies: libm),
    protocol: 'tap')
  test('x86/' + name + '/native/cpp', executable(name + '-native-cpp', cpp_source,
      cpp_args: simde_c_args + simde_c_defs + simde_native_c_flags + ['-DSIMDE_TEST_BARE'],
      include_directories: simde_include_dir,
      dependencies: libm),
    protocol: 'tap')
endforeach
