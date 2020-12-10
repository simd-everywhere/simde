#!/bin/bash -e

DOCKER="$(command -v podman || command -v docker)"

DOCKER_DIR="$(dirname "${0}")"
VOLUME_OPTIONS=""
CAPABILITIES=""
RELEASE="testing"

if [ "${OSTYPE}" == "linux-gnu" ] && [ "$(basename "${DOCKER}")" = "podman" ]; then
  CAPABILITIES="--cap-add=CAP_SYS_PTRACE";
fi

if [ ! -z "${1}" ]; then
  RELEASE="${1}"
fi

IMAGE_NAME="simde-dev-${RELEASE}"

"${DOCKER}" build --build-arg "release=${RELEASE}" -t "${IMAGE_NAME}" ${CAPABILITIES} -f "${DOCKER_DIR}/Dockerfile" "${DOCKER_DIR}/.."

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
