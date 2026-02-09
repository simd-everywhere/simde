fs = import('fs')

simde_test_common_tests = [
  'common'
]

simde_test_common_sources = []
foreach name : simde_test_common_tests
  foreach lang : ['c', 'cpp']
    source_file = name + '.c'
    if lang == 'cpp'
      source_file = fs.copyfile(name + '.c', name + '.cpp')
    endif
    simde_test_common_sources += source_file

    extra_flags = ['-DSIMDE_TEST_BARE']

    x = executable(name + '-' + lang, source_file,
        c_args: simde_c_args + simde_c_defs + simde_native_c_flags + extra_flags,
        cpp_args: simde_c_args + simde_c_defs + simde_native_c_flags + extra_flags,
        include_directories: simde_include_dir,
        dependencies: simde_deps)

    test('common/' + name + '/' + lang, x,
        protocol: 'tap',
        # Emscripten tests must be run from builddir
        workdir: meson.current_build_dir())
  endforeach
endforeach
