project('SIMDe', 'c', 'cpp',
        default_options: ['c_std=c99'],
        license: 'MIT',
        version: '0.5.0')

cc = meson.get_compiler('c')
cxx = meson.get_compiler('cpp')

simde_neon_families = [
  'abs',
  'add',
  'addl',
  'addl_high',
  'addw',
  'and',
  'bsl',
  'cagt',
  'ceq',
  'ceqz',
  'cge',
  'cgez',
  'cgt',
  'cgtz',
  'cle',
  'clez',
  'clt',
  'cltz',
  'cvt',
  'combine',
  'dot',
  'dot_lane',
  'dup_n',
  'eor',
  'ext',
  'get_high',
  'get_lane',
  'get_low',
  'ld1',
  'max',
  'min',
  'mla',
  'mla_n',
  'mlal',
  'mlal_high',
  'movl',
  'movl_high',
  'movn',
  'mul',
  'mul_n',
  'mull',
  'mull_n',
  'mvn',
  'neg',
  'orr',
  'padal',
  'padd',
  'paddl',
  'pmax',
  'pmin',
  'qadd',
  'qdmulh',
  'qdmull',
  'qrdmulh',
  'qrdmulh_n',
  'qmovn',
  'qmovn_high',
  'qtbl',
  'qtbx',
  'reinterpret',
  'rev64',
  'rhadd',
  'rshl',
  'rshr_n',
  'rsra_n',
  'shl',
  'shl_n',
  'shr_n',
  'sra_n',
  'st1',
  'st1_lane',
  'sub',
  'tbl',
  'tbx',
  'trn1',
  'trn2',
  'trn',
  'tst',
  'uzp1',
  'uzp2',
  'uzp',
  'zip1',
  'zip2',
  'zip',
]

if not meson.is_subproject() and get_option('tests')
  subdir('test')
endif

simde_neon_family_headers = ['simde/arm/neon/types.h']
foreach neon_family : simde_neon_families
  simde_neon_family_headers += 'simde/arm/neon/' + neon_family + '.h'
endforeach

if not meson.is_subproject()
  install_headers(
    files([
      'simde/check.h',
      'simde/debug-trap.h',
      'simde/hedley.h',
      'simde/simde-arch.h',
      'simde/simde-common.h',
      'simde/simde-constify.h',
      'simde/simde-detect-clang.h',
      'simde/simde-diagnostic.h',
      'simde/simde-features.h',
      'simde/simde-math.h',
      ]),
    subdir: 'simde')

  install_headers(
    files([
      'simde/x86/avx2.h',
      'simde/x86/avx512bw.h',
      'simde/x86/avx512cd.h',
      'simde/x86/avx512dq.h',
      'simde/x86/avx512f.h',
      'simde/x86/avx512vl.h',
      'simde/x86/avx.h',
      'simde/x86/fma.h',
      'simde/x86/gfni.h',
      'simde/x86/mmx.h',
      'simde/x86/sse2.h',
      'simde/x86/sse3.h',
      'simde/x86/sse4.1.h',
      'simde/x86/sse4.2.h',
      'simde/x86/sse.h',
      'simde/x86/ssse3.h',
      'simde/x86/svml.h',
      ]),
    subdir: 'simde/x86')

  install_headers(
    files([
      'simde/arm/neon.h',
      ]),
    subdir: 'simde/arm')

  install_headers(
    files(simde_neon_family_headers),
    subdir: 'simde/arm/neon')

  import('pkgconfig').generate(
    version : meson.project_version(),
    name : 'SIMDe',
    filebase : 'simde',
    description : 'Portable SIMD wrapper library')
endif

simde_dep = declare_dependency(
  include_directories : include_directories('.'),
  version : meson.project_version())
