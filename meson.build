project('SIMDe', 'c', 'cpp',
        default_options: ['c_std=c99'],
        license: 'MIT',
        version: '0.5.0')

cc = meson.get_compiler('c')
cxx = meson.get_compiler('cpp')

if not meson.is_subproject() and get_option('tests')
  subdir('test')
endif

install_headers(
  files([
    'simde/hedley.h',
    'simde/check.h',
    'simde/debug-trap.h',
    'simde/simde-arch.h',
    'simde/simde-common.h',

    'simde/x86/avx2.h',
    'simde/x86/avx512f.h',
    'simde/x86/avx512bw.h',
    'simde/x86/avx512vl.h',
    'simde/x86/avx512dq.h',
    'simde/x86/avx512cd.h',
    'simde/x86/fma.h',
    'simde/x86/gfni.h',
    'simde/x86/mmx.h',
    'simde/x86/sse.h',
    'simde/x86/sse2.h',
    'simde/x86/sse3.h',
    'simde/x86/sse4.1.h',
    'simde/x86/sse4.2.h',
    'simde/x86/ssse3.h',
    'simde/x86/svml.h',
    ]),
  subdir: 'simde')

if not meson.is_subproject()
  import('pkgconfig').generate(
    version : meson.project_version(),
    name : 'SIMDe',
    filebase : 'simde',
    description : 'Portable SIMD wrapper library')
endif

simde_dep = declare_dependency(
  include_directories : include_directories('.'),
  version : meson.project_version())
