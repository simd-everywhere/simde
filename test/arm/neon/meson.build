simde_test_arm_neon_sources = []
foreach name : simde_neon_families
  if (name != 'ld1') and (name != 'st1') and (name != 'ld3') and (name != 'ld4')
    c_source = name + '.c'
    cpp_source = configure_file(input: name + '.c', output: name + '.cpp', copy: true)
    simde_test_arm_neon_sources += [c_source, cpp_source]

    test('arm/neon/' + name + '/emul/c', executable(name + '-emul-c', c_source,
        c_args: simde_c_args + simde_c_defs + simde_native_c_flags + ['-DSIMDE_NO_NATIVE', '-DSIMDE_TEST_BARE'],
        include_directories: simde_include_dir,
        dependencies: simde_deps),
      protocol: 'tap')
    test('arm/neon/' + name + '/emul/cpp', executable(name + '-emul-cpp', cpp_source,
        cpp_args: simde_c_args + simde_c_defs + simde_native_c_flags + ['-DSIMDE_NO_NATIVE', '-DSIMDE_TEST_BARE'],
        include_directories: simde_include_dir,
        dependencies: simde_deps),
      protocol: 'tap')
    test('arm/neon/' + name + '/native/c', executable(name + '-native-c', c_source,
        c_args: simde_c_args + simde_c_defs + simde_native_c_flags + ['-DSIMDE_TEST_BARE'],
        include_directories: simde_include_dir,
        dependencies: simde_deps),
      protocol: 'tap')
    test('arm/neon/' + name + '/native/cpp', executable(name + '-native-cpp', cpp_source,
        cpp_args: simde_c_args + simde_c_defs + simde_native_c_flags + ['-DSIMDE_TEST_BARE'],
        include_directories: simde_include_dir,
        dependencies: simde_deps),
      protocol: 'tap')
  endif
endforeach
