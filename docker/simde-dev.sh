#!/bin/bash -e

# See documentation in README.md

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

# (Re)build image
# We only do this if the current image is older than a week (if jq is installed)
BUILD_IMAGE=auto
command -v jq >/dev/null
if [ 0 = $? ]; then
  BUILD_CUTOFF_TIME="$(expr $(date +%s) - \( 60 \* 60 \* 24 \* 7 \))"
  CURRENT_IMAGE_CREATED="$(${DOCKER} images "${IMAGE_NAME}" --format json | jq '.[].Created')"

  if [ -z "${CURRENT_IMAGE_CREATED}" ]; then
    BUILD_IMAGE=y
  elif [ ${CURRENT_IMAGE_CREATED} -lt ${BUILD_CUTOFF_TIME} ]; then
    BUILD_IMAGE=y
  else
    BUILD_IMAGE=n
  fi
else
  BUILD_IMAGE=y
fi

if [ "${BUILD_IMAGE}" = "y" ]; then
  "${DOCKER}" build --build-arg "release=${RELEASE}" -t "${IMAGE_NAME}" ${CAPABILITIES} -f "${DOCKER_DIR}/Dockerfile" "${DOCKER_DIR}/.."
fi

if [ "$(basename "${DOCKER}")" = "podman" ]; then
  VOLUME_OPTIONS=":z";
elif [ "${OSTYPE}" == "darwin" ]; then
  VOLUME_OPTIONS=":delegated"
fi

if [ "${OSTYPE}" == "darwin" ]; then
  if [ -z "${PERSISTENT_BUILD_DIR}" ]; then
    PERSISTENT_BUILD_ARGS="";
  else
    PERSISTENT_BUILD_DIR="$(realpath "${PERSISTENT_BUILD_DIR}")"
    PERSISTENT_BUILD_ARGS="--mount type=bind,source=\"${PERSISTENT_BUILD_DIR}\",target=/opt/simde"
  fi
  "${DOCKER}" run --mount type=bind,source="$(realpath "${DOCKER_DIR}/..")",target=/usr/local/src/simde ${PERSISTENT_BUILD_ARGS} ${CAPABILITIES} --rm -it "${IMAGE_NAME}" /bin/bash
else
  if [ -z "${PERSISTENT_BUILD_DIR}" ]; then
    PERSISTENT_BUILD_ARGS="";
  else
    PERSISTENT_BUILD_DIR="$(realpath "${PERSISTENT_BUILD_DIR}")"
    PERSISTENT_BUILD_ARGS="-v \"${PERSISTENT_BUILD_DIR}\":/opt/simde${VOLUME_OPTIONS}"
  fi
  "${DOCKER}" run -v "$(realpath "${DOCKER_DIR}/..")":/usr/local/src/simde${VOLUME_OPTIONS} ${PERSISTENT_BUILD_ARGS} ${CAPABILITIES} --rm -it "${IMAGE_NAME}" /bin/bash
fi
