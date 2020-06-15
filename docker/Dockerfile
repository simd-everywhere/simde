# Dockerfile for SIMDe development

FROM debian:testing-slim

RUN \
  apt-get update -y && \
  apt-get upgrade -y && \
  apt-get install -y curl gpg && \
  curl -s "https://apt.repos.intel.com/intel-gpg-keys/GPG-PUB-KEY-INTEL-SW-PRODUCTS-2023.PUB" | apt-key add - && \
  echo "deb [arch=amd64] https://apt.repos.intel.com/oneapi all main" > /etc/apt/sources.list.d/oneAPI.list && \
  for arch in armhf arm64 ppc64el s390x; do \
    dpkg --add-architecture "$arch"; \
  done && \
  apt-get update -y

RUN \
  apt-get install -y \
    git build-essential \
    meson cmake \
    clang-8 clang-9 clang-10 \
    gcc-10 g++-10 gcc-9 g++-9 gcc-8 g++-8 \
    intel-oneapi-icc \
    qemu binfmt-support qemu-user-static \
    creduce screen htop parallel nano rsync strace \
    npm && \
  for arch in `dpkg --print-foreign-architectures`; do \
    echo libc6:"${arch}" libstdc++-8-dev:"${arch}" libstdc++-9-dev:"${arch}" libstdc++-10-dev:"${arch}"; \
  done | xargs apt-get install -y && \
  for arch in arm-linux-gnueabihf aarch64-linux-gnu powerpc64le-linux-gnu s390x-linux-gnu; do \
    echo gcc-10-${arch} g++-10-${arch} gcc-9-${arch} g++-9-${arch}; \
  done | xargs apt-get install -y

# Install emscripten
RUN git clone https://github.com/emscripten-core/emsdk.git /opt/emsdk
WORKDIR /opt/emsdk
RUN ./emsdk update-tags && ./emsdk install tot && ./emsdk activate tot
# https://github.com/mesonbuild/meson/issues/6847
RUN ln -s /opt/emsdk/upstream/bin/wasm-ld /usr/bin/wasm-ld

# And v8
RUN npm install jsvu -g && jsvu --os=linux64 --engines=v8 && ln -s "/root/.jsvu/v8" "/usr/bin/v8"

# xlc -- Install fails.
# RUN \
#   curl -s 'https://public.dhe.ibm.com/software/server/POWER/Linux/xl-compiler/eval/ppc64le/ubuntu/public.gpg' | apt-key add - && \
#   echo "deb [arch=ppc64el] https://public.dhe.ibm.com/software/server/POWER/Linux/xl-compiler/eval/ppc64le/ubuntu/ bionic main" > /etc/apt/sources.list.d/xlc.list && \
#   apt-get update && \
#   XLC_VERSION="$(apt-cache search '^xlc\.[0-9]+\.[0-9]+\.[0-9]+$' | awk '{ print substr($1, 5) }')" && \
#   apt-get install "xlc.${XLC_VERSION}:ppc64el" "xlc-license-community.${XLC_VERSION}:ppc64el" && \
#   /opt/ibm/xlC/${XLC_VERSION}/bin/xlc_configure <<< 1 >/dev/null

# Wrappers for ICC
RUN \
    for exe in icc icpc; do \
      printf '#!/bin/bash\nsource /opt/intel/inteloneapi/setvars.sh >/dev/null\n%s $@\n' "${exe}" > /usr/bin/"${exe}" && \
      chmod 0755 /usr/bin/"${exe}" ; \
    done

# Install Intel SDE
COPY test/download-sde.sh /usr/local/bin/download-sde.sh
RUN \
  "/usr/local/bin/download-sde.sh" "/opt/intel/sde" && \
  for executable in sde sde64; do \
    ln -s "/opt/intel/sde/${executable}" "/usr/bin/${executable}"; \
  done

# Copy Meson cross files
# COPY docker/cross-files/ /usr/local/share/meson/cross/simde
RUN mkdir -p "/usr/local/share/meson/cross" && ln -s /usr/local/src/simde/docker/cross-files /usr/local/share/meson/cross/simde

# Copy helper scripts
RUN \
  for script in simde-reset-build.sh; do \
    ln -s /usr/local/src/simde/docker/bin/"${script}" /usr/bin/"${script}"; \
  done

RUN mkdir -p /opt/simde
WORKDIR /opt/simde
