# Dockerfile for SIMDe development

ARG RELEASE=testing
FROM debian:${RELEASE}-slim

ARG DEBIAN_FRONTEND=noninteractive
ARG QEMU_GIT=n
ARG ARCHS="arm64 armel armhf i386 mips64el ppc64el s390x"

RUN \
  apt-get update -y && \
  apt-get upgrade -y && \
  apt-get install -y netselect-apt && \
  if netselect-apt -n ${release}; then \
    mv sources.list /etc/apt/sources.list; \
  fi

COPY docker/bin /tmp/simde-bin
RUN \
  for script in simde-reset-build.sh; do \
    ln -s /usr/local/src/simde/docker/bin/"${script}" /usr/bin/"${script}"; \
  done

# Common packages
RUN \
  apt-get update -y && \
  apt-get upgrade -y && \
  apt-get install -yq --no-install-recommends \
    git build-essential \
    ccache cmake ninja-build \
    '^clang-[0-9\.]+$' \
    '^llvm-[0-9\.]+$' \
    '^g(cc|\+\+)-[0-9\.]+$' \
    gdb valgrind \
    binfmt-support qemu-user-static \
    creduce screen htop parallel nano rsync strace \
    npm libsleef-dev \
    pipx wget

# Meson on stable is too old, and we want to make sure we keep 0.55
# working for a while.
RUN pipx install meson==0.55.0

# GCC cross-compilers
RUN \
  apt-get update -y && \
  apt-get upgrade -y && \
  apt-get install -y apt-file && \
  apt-file update
RUN \
  PACKAGES_TO_INSTALL=""; \
  for ARCH in ${ARCHS}; do \
    PACKAGES_TO_INSTALL="${PACKAGES_TO_INSTALL} libc6-${ARCH}-cross libstdc++-[0-9]*-dev-${ARCH}-cross"; \
    PACKAGES_TO_INSTALL="${PACKAGES_TO_INSTALL} $(apt-file search -x "/usr/bin/$(/tmp/simde-bin/arch2gcc.sh ${ARCH})-(ar|g(cc|\+\+)-[0-9\.]+)" | awk -F: '{ print $1}')"; \
  done; \
  echo ${PACKAGES_TO_INSTALL} ; \
  apt-get install -yq ${PACKAGES_TO_INSTALL}

ENV PATH="/usr/lib/ccache:$PATH:/root/.local/bin"

# ICC
RUN \
  apt-get update -y && \
  apt-get upgrade -y && \
  apt-get install -yq curl gpg && \
  wget -O- https://apt.repos.intel.com/intel-gpg-keys/GPG-PUB-KEY-INTEL-SW-PRODUCTS.PUB \
   | gpg --dearmor > /usr/share/keyrings/oneapi-archive-keyring.gpg && \
  echo "deb [signed-by=/usr/share/keyrings/oneapi-archive-keyring.gpg] https://apt.repos.intel.com/oneapi all main" > /etc/apt/sources.list.d/oneAPI.list && \
  apt-get update && \
  apt-get install -yq --no-install-recommends intel-oneapi-compiler-dpcpp-cpp-and-cpp-classic intel-oneapi-compiler-dpcpp-cpp && \
  for exe in icc icpc icx icpx; do \
    printf '#!/bin/bash\nARGS="$@"\nsource /opt/intel/oneapi/compiler/latest/env/vars.sh >/dev/null\n%s ${ARGS}\n' "${exe}" > /usr/bin/"${exe}" && \
    chmod 0755 /usr/bin/"${exe}" ; \
  done

# # xlc -- Install fails.
# # Once IBM releases a version for Ubuntu Focal (20.04) I hope I can
# # get this working.
# RUN \
#   curl -s 'https://public.dhe.ibm.com/software/server/POWER/Linux/xl-compiler/eval/ppc64le/ubuntu/public.gpg' | apt-key add - && \
#   echo "deb [arch=ppc64el] https://public.dhe.ibm.com/software/server/POWER/Linux/xl-compiler/eval/ppc64le/ubuntu/ bionic main" > /etc/apt/sources.list.d/xlc.list && \
#   apt-get update && \
#   XLC_VERSION="$(apt-cache search '^xlc\.[0-9]+\.[0-9]+\.[0-9]+$' | awk '{ print substr($1, 5) }')" && \
#   apt-get install "xlc.${XLC_VERSION}:ppc64el" "xlc-license-community.${XLC_VERSION}:ppc64el" && \
#   /opt/ibm/xlC/${XLC_VERSION}/bin/xlc_configure <<< 1 >/dev/null

# Intel SDE
COPY test/download-sde.sh /tmp/simde-bin/download-sde.sh
RUN \
  "/tmp/simde-bin/download-sde.sh" "/opt/intel/sde" && \
  for executable in sde sde64; do \
    ln -s "/opt/intel/sde/${executable}" "/usr/bin/${executable}"; \
  done

# Emscripten
RUN \
  git clone https://github.com/emscripten-core/emsdk.git /opt/emsdk && \
  cd /opt/emsdk && ./emsdk install tot && ./emsdk activate tot && \
  ln -s /opt/emsdk/upstream/bin/wasm-ld /usr/bin/wasm-ld && \
  npm install jsvu -g && jsvu --os=linux64 --engines=v8 && ln -s "/root/.jsvu/v8" "/usr/bin/v8"

# Meson cross files
RUN \
  mkdir -p "/usr/local/share/meson/cross" && ln -s /usr/local/src/simde/docker/cross-files /usr/local/share/meson/cross/simde

# Install QEMU git (necessary for MIPS)
RUN \
  if [ ${QEMU_GIT} = "y" ]; then \
    apt-get install -y pkg-config libglib2.0-dev libpixman-1-dev && \
    git clone https://gitlab.com/qemu-project/qemu.git /usr/local/src/qemu && \
    mkdir -p /usr/local/src/qemu/build && cd /usr/local/src/qemu/build && \
    ../configure --prefix=/opt/qemu && \
    make -j$(nproc) && \
    make install; \
    rm -rf /usr/local/src/qemu; \
  fi

RUN mkdir -p /opt/simde
WORKDIR /opt/simde
ENV CCACHE_DIR=/opt/simde/.ccache CCACHE_COMPRESS=1
