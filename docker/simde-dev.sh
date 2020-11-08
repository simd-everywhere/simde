#!/bin/bash -e

DOCKER="$(command -v podman || command -v docker)"

DOCKER_DIR="$(dirname "${0}")"

VOLUME_OPTIONS=""
CAPABILITIES=""

if [ "${OSTYPE}" == "linux-gnu" ] && [ "$(basename "${DOCKER}")" = "podman" ]; then
  CAPABILITIES="--cap-add=CAP_SYS_PTRACE";
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

"${DOCKER}" build -t "${IMAGE_NAME}" ${CAPABILITIES} -f "${DOCKERFILE}" "${DOCKER_DIR}/.."

if [ "$(basename "${DOCKER}")" = "podman" ]; then
  VOLUME_OPTIONS=":z";
elif [ "${OSTYPE}" == "darwin" ]; then
  VOLUME_OPTIONS=":delegated"
fi

if [ "${OSTYPE}" == "darwin" ]; then
  "${DOCKER}" run --mount type=bind,source="$(realpath "${DOCKER_DIR}/..")",target=/usr/local/src/simde ${CAPABILITIES} --rm -it "${IMAGE_NAME}" /bin/bash
else
  "${DOCKER}" run -v "$(realpath "${DOCKER_DIR}/..")":/usr/local/src/simde${VOLUME_OPTIONS} ${CAPABILITIES} --rm -it "${IMAGE_NAME}" /bin/bash
fi
