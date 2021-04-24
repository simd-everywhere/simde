#!/bin/bash

# Some CI workers support different ISA extensions on x86. We want to
# run the tests if the extension is supported, but skip them if it
# isn't.  Currently this only works on x86.

echo "WD: $PWD" > ~/wd.txt

if [ -z "${SDE_PATH}" ]; then
  SDE_PATH="/opt/intel/sde"
fi

if [ ! -d "${SDE_PATH}" ]; then
  mkdir -p "${SDE_PATH}"
fi

NATIVE_SUPPORT=1
for FLAG in $CFLAGS; do
  echo $FLAG | grep -qP '^\-m[0-9a-zA-V\.]+$' || continue
  grep -qP " ${FLAG:2} " /proc/cpuinfo || NATIVE_SUPPORT=0
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

if [ $COMMAND = 'query' ]; then
  test $NATIVE_SUPPORT -eq 1
  exit $?
elif [ $NATIVE_SUPPORT -eq 1 ]; then
  $@
  exit $?
elif [ "$COMMAND" = "sde" ]; then
  if [ ! -e "${SDE_PATH}/sde64" ]; then
    "$(dirname "$0")"/download-sde.sh "${SDE_PATH}"
  fi
  "${SDE_PATH}/sde64" -- $@
  exit $?
else
  echo "Flags not supported, skipping"
fi
