#!/bin/sh

if [ ! -e "/opt/simde/test/iig.xml" ]; then
  curl -s "https://software.intel.com/sites/landingpage/IntrinsicsGuide/files/data-$(curl -s 'https://software.intel.com/sites/landingpage/IntrinsicsGuide/' | grep -Po '(?<=intrinsicsguide.min.js\?)([0-9\.]+)')).xml" > /opt/simde/test/iig.xml;
fi
