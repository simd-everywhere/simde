munit_deps = []
munit_defs = []
if cc.get_id() == 'pgi'
  munit_deps += dependency('openmp')
endif
if cc.has_function('clock_gettime')
  librt_dep = cc.find_library('rt', required: false)
  if not librt_dep.found()
    munit_defs += '-DPSNIP_CLOCK_NO_LIBRT'
  endif
  munit_deps += librt_dep
endif
munit = static_library('munit', 'munit/munit.c', dependencies: munit_deps)

simde_c_defs = []
simde_cxx_defs = []
simde_c_args = []
simde_cxx_args = []
simde_deps = []

c_openmp_simd = false
cxx_openmp_simd = false
foreach omp_arg : ['-fopenmp-simd', '-qopenmp-simd']
  if (not c_openmp_simd) and cc.has_argument(omp_arg)
    simde_c_args += omp_arg
    simde_c_defs += '-DSIMDE_ENABLE_OPENMP'
    c_openmp_simd = true
  endif

  if (not cxx_openmp_simd) and cxx.has_argument(omp_arg)
    simde_cxx_args += omp_arg
    simde_cxx_defs += '-DSIMDE_ENABLE_OPENMP'
    cxx_openmp_simd = true
  endif
endforeach

simde_native_c_flags = []
# if cc.has_argument('-march=native+simd')
#   simde_native_c_flags += '-march=native+simd'
# elif cc.has_argument('-march=native')
#   simde_native_c_flags += '-march=native'
# endif

simde_native_cxx_flags = []
# if cxx.has_argument('-march=native+simd')
#   simde_native_cxx_flags += '-march=native+simd'
# elif cxx.has_argument('-march=native')
#   simde_native_cxx_flags += '-march=native'
# endif

if not c_openmp_simd
  simde_deps += dependency('openmp', required: false)
endif

simde_include_dir = include_directories('..')

subdir('x86')
subdir('arm')

executable('run-tests', 'run-tests.c',
           link_with: [munit, simde_tests_x86, simde_tests_arm],
           dependencies: simde_deps,
           c_args: simde_c_args + simde_c_defs + simde_native_c_flags,
           cpp_args: simde_cxx_args + simde_cxx_defs + simde_native_cxx_flags)
