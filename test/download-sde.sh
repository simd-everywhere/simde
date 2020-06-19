#!/bin/sh

FRAGMENT="$(curl -sL 'https://software.intel.com/content/www/us/en/develop/articles/pre-release-license-agreement-for-intel-software-development-emulator-accept-end-user-license-agreement-and-download.html' | \
    grep -oP '/content/dam/develop/external/us/en/documents/sde-external-([0-9\.\-]+)-lin.tar.bz2' | head -n1)"
if [ ! -e "$1" ]; then
  mkdir -p "$1"
fi
curl -sL "https://software.intel.com${FRAGMENT}" | \
  tar --strip-components 1 -jxC "$1"
