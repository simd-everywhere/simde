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
foreach name : simde_test_x86_tests
  c_source = name + '.c'
  cpp_source = configure_file(input: name + '.c', output: name + '.cpp', copy: true)
  simde_test_x86_sources += [c_source, cpp_source]
endforeach

simde_tests_x86_emul = static_library('simde-tests-x86-emul', simde_test_x86_sources,
  c_args: simde_c_args + simde_c_defs + simde_native_c_flags + ['-DSIMDE_NO_NATIVE'],
  cpp_args: simde_cxx_args + simde_cxx_defs + simde_native_cxx_flags + ['-DSIMDE_NO_NATIVE'],
  include_directories: simde_include_dir)

simde_tests_x86_native = static_library('simde-tests-x86-native', simde_test_x86_sources,
  c_args: simde_c_args + simde_c_defs + simde_native_c_flags,
  cpp_args: simde_cxx_args + simde_cxx_defs + simde_native_cxx_flags,
  include_directories: simde_include_dir)

simde_tests_x86 = static_library('simde-tests-x86', 'run-tests.c',
  link_with: [simde_tests_x86_emul, simde_tests_x86_native])
