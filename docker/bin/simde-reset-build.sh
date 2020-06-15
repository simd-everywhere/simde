#!/bin/bash

CLANG_CFLAGS='-Weverything -Wno-newline-eof -Werror'
CLANG_CXXFLAGS='-Weverything -Wno-c++98-compat-pedantic -Wno-newline-eof -Werror'

function configure {
  if [ -e "/opt/simde/${1}" ]; then
    rm -rf "/opt/simde/${1}";
  fi
  if [ -e "/usr/local/share/meson/cross/simde/${1}.cross" ]; then
    meson --cross-file="/usr/local/share/meson/cross/simde/${1}.cross" "/opt/simde/${1}" "/usr/local/src/simde"
  else
    case "${1}" in
      "aarch64-clang-10")
        CFLAGS="--target=aarch64-linux-gnu -march=armv8-a+simd -isystem=/usr/aarch64-linux-gnu/include ${CLANG_CFLAGS} ${CFLAGS}" \
        CXXFLAGS="--target=aarch64-linux-gnu -march=armv8-a+simd -isystem=/usr/aarch64-linux-gnu/include ${CLANG_CXXFLAGS} ${CXXFLAGS}" \
        cmake -S "/usr/local/src/simde/test" -B "/opt/simde/${1}" -DCMAKE_CROSSCOMPILING_EMULATOR="qemu-aarch64-static" -DCMAKE_C_COMPILER='clang-10' -DCMAKE_CXX_COMPILER='clang++-10' -G Ninja
        ;;
      "emscripten")
        /opt/emsdk/upstream/emscripten/emcmake cmake -DCMAKE_{C,CXX}_FLAGS='-Weverything -Werror -O2' -S "/usr/local/src/simde/test" -B "/opt/simde/${1}" -G Ninja
        ;;
    esac
  fi
}

if [ $# -gt 0 ]; then
  while [ $# -ge 1 ]; do
    configure "$1"

    shift
  done
else
  for cross in /usr/local/share/meson/cross/simde/*.cross; do
    target="$(basename "$cross" .cross)"
    if [ ! -e "/opt/simde/${target}" ]; then
      configure "$(basename "${target}" .cross)"
    fi
  done
  for target in "aarch64-clang-10" "emscripten"; do
    if [ ! -e "/opt/simde/${target}" ]; then
      configure "$(basename "${target}" .cross)"
    fi
  done
fi
