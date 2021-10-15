#!/bin/sh

if [ "x$1" != "x" ]; then
  OUTFILE="$1"
else
  OUTFILE="iig.xml"
fi

if [ ! -e "${OUTFILE}" ]; then
  IIG_VERSION="$(curl -s https://www.intel.com/content/www/us/en/docs/intrinsics-guide/index.html | grep -Po '(?<=style.min.css\?)([0-9.\-]+)')"
  curl -s "https://www.intel.com/content/dam/develop/public/us/en/include/intrinsics-guide/data-${IIG_VERSION}.xml" > "${OUTFILE}";
fi
