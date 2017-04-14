# This is basically supposed to be the CMake equivalent of
# https://git.gnome.org/browse/gnome-common/tree/macros2/gnome-compiler-flags.m4

include (AddCompilerFlags)

if (MSVC)
  set (EXTRA_WARNING_FLAGS
    /W4
    /analyze)
else ()
  set (EXTRA_WARNING_FLAGS
    -Wall
    -Wcast-align
    -Wclobbered
    -Wempty-body
    -Werror=format=2
    -Werror=format-security
    -Werror=implicit-function-declaration
    -Werror=init-self
    -Werror=missing-include-dirs
    -Werror=missing-prototypes
    -Werror=pointer-arith
    -Wextra
    -Wformat-nonliteral
    -Wformat-security
    -Wignored-qualifiers
    -Winit-self
    -Winvalid-pch
    -Wlogical-op
    -Wmissing-declarations
    -Wmissing-format-attribute
    -Wmissing-include-dirs
    -Wmissing-noreturn
    -Wmissing-parameter-type
    -Wmissing-prototypes
    -Wnested-externs
    -Wno-missing-field-initializers
    -Wno-strict-aliasing
    -Wno-uninitialized
    -Wno-unused-parameter
    -Wold-style-definition
    -Woverride-init
    -Wpacked
    -Wpointer-arith
    -Wredundant-decls
    -Wreturn-type
    -Wshadow
    -Wsign-compare
    -Wstrict-prototypes
    -Wswitch-enum
    -Wsync-nand
    -Wtype-limits
    -Wundef
    -Wuninitialized
    -WUnsafe-loop-optimizations
    -Wwrite-strings
    -Wsuggest-attribute=format)
endif ()

mark_as_advanced (EXTRA_WARNING_FLAGS)

function (target_add_extra_warning_flags target)
  target_add_compiler_flags (${target} ${EXTRA_WARNING_FLAGS})
endfunction (target_add_extra_warning_flags)

function (source_file_add_extra_warning_flags file)
  source_file_add_compiler_flags (${file} ${EXTRA_WARNING_FLAGS})
endfunction (source_file_add_extra_warning_flags)
