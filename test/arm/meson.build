subdir('neon')

simde_tests_arm = static_library('simde-tests-arm', 'run-tests.c',
  c_args: simde_c_args + simde_c_defs + simde_native_c_flags + ['-DSIMDE_NO_NATIVE'],
  cpp_args: simde_cxx_args + simde_cxx_defs + simde_native_cxx_flags + ['-DSIMDE_NO_NATIVE'],
  link_with: [simde_tests_arm_neon])
