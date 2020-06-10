simde_test_arm_neon_sources = [
  'add.c',
  'and.c',
  'dup_n.c',
  'eor.c',
  'get_high.c',
  'get_lane.c',
  'get_low.c',
  'min.c',
  'mla.c',
  'mul.c',
  'mull.c',
  'orr.c',
  'padd.c',
  'pmin.c',
  'shl_n.c',
  'shr_n.c',
  'sub.c',
  'uzp1.c',
  'uzp2.c',
]

foreach src : simde_test_arm_neon_sources
  simde_test_arm_neon_sources += configure_file(input: src, output: src + 'pp', copy: true)
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
