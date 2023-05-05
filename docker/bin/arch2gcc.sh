#!/bin/sh

case "${1}" in
  "alpha")
    echo "alpha-linux-gnu"
    ;;
  "amd64")
    echo "x86_64-linux-gnu"
    ;;
  "arm64")
    echo "aarch64-linux-gnu"
    ;;
  "armhf")
    echo "arm-linux-gnueabihf"
    ;;
  "armel")
    echo "arm-linux-gnueabi"
    ;;
  "hppa")
    echo "hppa-linux-gnu"
    ;;
  "hppa64")
    echo "hppa64-linux-gnu"
    ;;
  "i386")
    echo "i686-linux-gnu"
    ;;
  "m68k")
    echo "m68k-linux-gnu"
    ;;
  "mips64el")
    echo "mips64el-linux-gnuabi64"
    ;;
  "mipsel")
    echo "mips64-linux-gnuabi64"
    ;;
  "ppc")
    echo "powerpc-linux-gnu"
    ;;
  "ppc64")
    echo "powerpc64-linux-gnu"
    ;;
  "ppc64el")
    echo "powerpc64le-linux-gnu"
    ;;
  "riscv64")
    echo "riscv64-linux-gnu"
    ;;
  "s390x")
    echo "s390x-linux-gnu"
    ;;
  "sh4")
    echo "sh4-linux-gnu"
    ;;
  "sparc64")
    echo "sparc64-linux-gnu"
    ;;
  "x32")
    echo "x86_64-linux-gnux32"
    ;;
  *)
    echo "Unknown architecture: ${1}" >&2
    exit 1
    ;;
esac
