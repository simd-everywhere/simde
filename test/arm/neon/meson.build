simde_test_arm_neon_sources = []
foreach name : simde_neon_families
  if (name != 'ld1') and (name != 'st1')
    c_source = name + '.c'
    cpp_source = configure_file(input: name + '.c', output: name + '.cpp', copy: true)
    simde_test_arm_neon_sources += [c_source, cpp_source]
  endif
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
