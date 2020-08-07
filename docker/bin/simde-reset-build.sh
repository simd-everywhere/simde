#!/bin/bash

function configure {
  if [ -e "/opt/simde/${1}" ]; then
    rm -rf "/opt/simde/${1}";
  fi
  if [ -e "/usr/local/share/meson/cross/simde/${1}.cross" ]; then
    meson --cross-file="/usr/local/share/meson/cross/simde/${1}.cross" "/opt/simde/${1}" "/usr/local/src/simde"
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
