#!/bin/sh

if [ "x$1" != "x" ]; then
  OUTFILE="$1"
else
  OUTFILE="iig.xml"
fi

if [ ! -e "${OUTFILE}" ]; then
  IIG_VERSION="$(curl -s https://software.intel.com/sites/landingpage/IntrinsicsGuide/ | grep -Po '(?<=intrinsicsguide.min.js\?)([0-9\.]+)')"
  curl -s "https://software.intel.com/sites/landingpage/IntrinsicsGuide/files/data-${IIG_VERSION}.xml" > "${OUTFILE}";
fi
