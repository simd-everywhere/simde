#!/bin/bash

if [ $# = 0 ]; then
  for crossfile in /usr/local/share/meson/cross/simde/*.cross; do
    basename "$crossfile" .cross
  done | xargs "$0"
else
  while [ $# -gt 0 ]; do
    ninja -C /opt/simde-build/"$1" test || exit 1
    shift
  done
fi
