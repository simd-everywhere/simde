#!/bin/sh

URL="$(curl -sL 'https://www.intel.com/content/www/us/en/download/684897/intel-software-development-emulator.html' | \
    grep -oP '(?<=data\-direct\-path=")(https://[^\"]+)/sde-external-([0-9\.\-]+)-lin.tar.xz' | head -n1)"
echo "${URL}"
if [ ! -e "$1" ]; then
  mkdir -p "$1"
fi
curl -sL "${URL}" | \
  tar --strip-components 1 -JxC "$1"
