simde_test_arm_neon_sources = [
  'vadd.c',
  'vdup_n.c',
  'vmul.c',
  'vsub.c'
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

simde_tests_arm_neon = static_library('simde-tests-neon', 'test-neon.c',
  link_with: [simde_tests_arm_neon_emul, simde_tests_arm_neon_native])
