simde_test_arm_neon_tests = [
  'add',
  'addw',
  'and',
  'bsl',
  'cagt',
  'dup_n',
  'eor',
  'get_high',
  'get_lane',
  'get_low',
  'max',
  'min',
  'mla',
  'mul',
  'mull',
  'orr',
  'padd',
  'pmax',
  'pmin',
  'reinterpret',
  'shl',
  'shl_n',
  'shr_n',
  'sub',
  'trn',
  'trn1',
  'trn2',
  'uzp',
  'uzp1',
  'uzp2',
  'zip',
  'zip1',
  'zip2',
]

simde_test_arm_neon_sources = []
foreach name : simde_test_arm_neon_tests
  c_source = name + '.c'
  cpp_source = configure_file(input: name + '.c', output: name + '.cpp', copy: true)
  simde_test_arm_neon_sources += [c_source, cpp_source]
endforeach

simde_tests_arm_neon_emul = static_library('simde-tests-arm-neon-emul', simde_test_arm_neon_sources,
  c_args: simde_c_args + simde_c_defs + simde_native_c_flags + ['-DSIMDE_NO_NATIVE'],
  cpp_args: simde_c_args + simde_c_defs + simde_native_c_flags + ['-DSIMDE_NO_NATIVE'],
  include_directories: simde_include_dir)

simde_tests_arm_neon_native = static_library('simde-tests-arm-neon-native', simde_test_arm_neon_sources,
  c_args: simde_c_args + simde_c_defs + simde_native_c_flags + simde_native_c_flags,
  cpp_args: simde_c_args + simde_c_defs + simde_native_c_flags + simde_native_cxx_flags,
  include_directories: simde_include_dir)

simde_tests_arm_neon = static_library('simde-tests-neon', 'run-tests.c',
  link_with: [simde_tests_arm_neon_emul, simde_tests_arm_neon_native])
