simde_test_arm_neon_sources = []
foreach name : simde_neon_families
  if (name != 'ld3') and (name != 'ld4') and (name != 'st1') and (name != 'ld1')
    foreach lang : ['c', 'cpp']
      source_file = name + '.c'
      if lang == 'cpp'
        source_file = configure_file(input: name + '.c', output: name + '.cpp', copy: true)
      endif
      simde_test_arm_neon_sources += source_file

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

        test('arm/neon/' + name + '/' + emul + '/' + lang, x,
            protocol: 'tap',
            # Emscripten tests must be run from builddir
            workdir: meson.current_build_dir())
      endforeach
    endforeach
  endif
endforeach
