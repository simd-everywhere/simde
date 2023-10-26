#!/bin/bash

# Some CI workers support different ISA extensions on x86. We want to
# run the tests if the extension is supported, but skip them if it
# isn't.  Currently this only works on x86.

INTEL_TARGET=${INTEL_TARGET:-tgl}

if [ -z "${SDE_PATH}" ]; then
  SDE_PATH="/opt/intel/sde"
fi

if [ ! -d "${SDE_PATH}" ]; then
  mkdir -p "${SDE_PATH}"
fi

if [ -e /lib/ld-linux-x86-64.so.2 ]; then
  LD=/lib/ld-linux-x86-64.so.2
else
  LD=/lib64/ld-linux-x86-64.so.2
fi

NATIVE_SUPPORT=1
for FLAG in $CFLAGS; do
  if echo "$FLAG" | grep -q '\-march=x86-64$' ; then
    if grep -qP " x86_64 \(supported" <(${LD} --help) ; then
      continue
    else
      NATIVE_SUPPORT=0
      continue
    fi
  elif echo "$FLAG" | grep -q '\-march=x86-64-v[234]$'; then
    if grep -qP " ${FLAG:7} \(supported" <(${LD} --help) ; then
      continue
    else
      NATIVE_SUPPORT=0
      continue
    fi
  fi
  echo "$FLAG" | grep -qP '^\-m[0-9a-zA-Z\.-]+$' || continue
  case "${FLAG:2}" in
    # sse3 doesn't show up in /proc/cpuinfo (?!?!)
    "avx512bf16")
      grep -qP " avx512_bf16 " /proc/cpuinfo || NATIVE_SUPPORT=0
      ;;
    "avx512bitalg")
      grep -qP " avx512_bitalg " /proc/cpuinfo || NATIVE_SUPPORT=0
      ;;
    "avx512vbmi2")
      grep -qP " avx512_vbmi2 " /proc/cpuinfo || NATIVE_SUPPORT=0
      ;;
    "avx512vnni")
      grep -qP " avx512_vnni " /proc/cpuinfo || NATIVE_SUPPORT=0
      ;;
    "sse3")
      ;;
    *)
      grep -qP " ${FLAG:2} " /proc/cpuinfo || NATIVE_SUPPORT=0
      ;;
  esac
done

COMMAND="$1"
shift

case "$COMMAND" in
  "try" | "sde" | "query")
    ;;
  *)
    echo "Unknown command ($COMMAND)" >&2
    exit 1
    ;;
esac

if [ "$COMMAND" = "query" ]; then
  test $NATIVE_SUPPORT -eq 1
  exit $?
elif [ $NATIVE_SUPPORT -eq 1 ]; then
  "$@"
  exit $?
elif [ "$COMMAND" = "sde" ]; then
  (
    flock 9
    if [ ! -e "${SDE_PATH}/sde64" ]; then
      "$(dirname "$0")"/download-sde.sh "${SDE_PATH}"
    fi
  ) 9>/tmp/sde-download.lock
  "${SDE_PATH}/sde64" "-${INTEL_TARGET}" -- "$@"
  exit $?
else
  echo "Flags not supported, skipping"
fi
