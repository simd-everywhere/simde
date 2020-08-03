#!/bin/sh -e

DOCKER="$(command -v podman || command -v docker)"

DOCKER_DIR="$(dirname "${0}")"

if [ "$(basename "${DOCKER}")" = "podman" ]; then
  PODMAN_RELABEL=":z"
fi

if [ "${OSTYPE}" = "linux-gnu" ]; then
  CAPABILITIES="--cap-add=CAP_SYS_PTRACE";
else
  CAPABILITIES="";
fi

IMAGE_NAME="simde-dev"

if [ -z "${1}" ]; then
  DOCKERFILE="${DOCKER_DIR}/Dockerfile"
  IMAGE_NAME="simde-testing"
else
  if [ -e "$1" ]; then
    DOCKERFILE="${1}";
  elif [ -e "${DOCKER_DIR}/Dockerfile-${1}" ]; then
    DOCKERFILE="${DOCKER_DIR}/Dockerfile-${1}"
    IMAGE_NAME="simde-${1}"
  else
    echo "Unable to find Dockerfile for ${1}" >&2
    exit 1
  fi
fi

echo "Using $(realpath "${DOCKERFILE}")"

"${DOCKER}" build -t "${IMAGE_NAME}" --cap-add=CAP_SYS_PTRACE -f "${DOCKERFILE}" "${DOCKER_DIR}/.."
"${DOCKER}" run -v "$(realpath "${DOCKER_DIR}/..")":/usr/local/src/simde${PODMAN_RELABEL} ${CAPABILITIES} --rm -it "${IMAGE_NAME}" /bin/bash
