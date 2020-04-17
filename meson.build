project('SIMDe', 'c', 'cpp',
        default_options: ['c_std=c99'],
        license: 'MIT',
        version: '0.5.0')

cc = meson.get_compiler('c')
cxx = meson.get_compiler('cpp')

subdir('test')

install_headers(
    [
		'simde/hedley.h',
		'simde/check.h',
		'simde/debug-trap.h',
		'simde/simde-arch.h',
		'simde/simde-common.h',

		'simde/x86/avx2.h',
		'simde/x86/avx512bw.h',
		'simde/x86/avx512vl.h',
		'simde/x86/avx512f.h',
		'simde/x86/fma.h',
		'simde/x86/mmx.h',
		'simde/x86/sse.h',
		'simde/x86/sse2.h',
		'simde/x86/sse3.h',
		'simde/x86/sse4.1.h',
		'simde/x86/sse4.2.h',
		'simde/x86/ssse3.h',
		'simde/x86/svml.h',
    ],
    subdir: 'simde')
