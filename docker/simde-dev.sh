#!/bin/sh -e

DOCKER="$(command -v podman || command -v docker)"

DOCKER_DIR="$(dirname "${0}")"

if [ "$(basename "${DOCKER}")" = "podman" ]; then
  PODMAN_RELABEL=":z"
fi

if [ $# = 0 ]; then
  CMD="/bin/bash"
else
  CMD="$@"
fi

"${DOCKER}" build -t 'simde-dev' --cap-add=CAP_SYS_PTRACE -f "${DOCKER_DIR}/Dockerfile" "${DOCKER_DIR}/.."
"${DOCKER}" run -v "$(realpath "${DOCKER_DIR}/..")":/usr/local/src/simde${PODMAN_RELABEL} --cap-add=CAP_SYS_PTRACE --rm -it simde-dev ${CMD}
