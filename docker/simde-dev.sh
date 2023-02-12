#!/bin/bash -e

# See documentation in README.md

DOCKER="$(command -v podman || command -v docker)"

DOCKER_DIR="$(dirname "${0}")"
VOLUME_OPTIONS=""
CAPABILITIES=""
RELEASE="testing"
PROMPT=n

if [ "x$QEMU_GIT" == 'x' ]; then
  QEMU_GIT=n
fi

if [ "${OSTYPE}" == "linux-gnu" ] && [ "$(basename "${DOCKER}")" = "podman" ]; then
  CAPABILITIES="--cap-add=CAP_SYS_PTRACE";
fi

if [ ! -z "${1}" ]; then
  RELEASE="${1}"
fi

IMAGE_NAME="simde-dev-${RELEASE}${SUFFIX}"

# (Re)build image
# We only do this if the current image is older than a week, but ou can
# use BUILD_IMAGE=y/n to force the image to build or not build.
if [ -z "${BUILD_IMAGE}" ]; then
  BUILD_CUTOFF_TIME="$(expr $(date +%s) - \( 60 \* 60 \* 24 \* 7 \))"
  DATE="$(${DOCKER} images "${IMAGE_NAME}" --format '{{ .CreatedAt }}' | awk '{ print $1 " " $2 }')"

  if [ "$(uname)" == "Darwin" ]; then
    CURRENT_IMAGE_CREATED="$(date -jf "%Y-%m-%d %H:%M:%S" "$DATE" +%s)"
  else
    CURRENT_IMAGE_CREATED="$(date +"%s" -d "$DATE")"
  fi

  if [[ -z "${CURRENT_IMAGE_CREATED}" || -z "${DATE}" ]]; then
    BUILD_IMAGE=y
    PROMPT=y
  elif [ ${CURRENT_IMAGE_CREATED} -lt ${BUILD_CUTOFF_TIME} ]; then
    BUILD_IMAGE=y
    PROMPT=y
  else
    BUILD_IMAGE=n
  fi
fi

if [ "${PROMPT}" == "y" ]; then
  read -p "Image older than a week, Rebuild? [Y/n]: " BUILD_IMAGE
  BUILD_IMAGE=${BUILD_IMAGE:-y}
fi

if [ "${BUILD_IMAGE}" != "n" ]; then
  "${DOCKER}" rmi -f "${IMAGE_NAME}" 2>/dev/null || true
  "${DOCKER}" build --build-arg "RELEASE=${RELEASE}" --build-arg "QEMU_GIT=${QEMU_GIT}" -t "${IMAGE_NAME}" ${CAPABILITIES} -f "${DOCKER_DIR}/Dockerfile${SUFFIX}" "${DOCKER_DIR}/.."
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
    PERSISTENT_BUILD_DIR=$(realpath "${PERSISTENT_BUILD_DIR}")
    PERSISTENT_BUILD_ARGS=-v\ "${PERSISTENT_BUILD_DIR}:/opt/simde${VOLUME_OPTIONS}"
  fi
  "${DOCKER}" run -v "$(realpath "${DOCKER_DIR}/..")":/usr/local/src/simde${VOLUME_OPTIONS} ${PERSISTENT_BUILD_ARGS} ${CAPABILITIES} --rm -it "${IMAGE_NAME}" /bin/bash
fi
