# -*- Python -*-
# Drone CI Starlark configuration file.
# https://docs.drone.io/pipeline/scripting/starlark/
# Run `drone starlark convert --stdout` to verify `.drone.star`.
def get_default_job():
  return {
    "kind": "pipeline",
    "type": "docker",
    "name": "",
    "platform": {
      "os": "linux",
    },
    "steps": [
      {
        "name": "test",
        "image": "ubuntu:bionic",
        "environment": {},
        "commands": [
        ]
      }
    ],
    "custom": {
      "before_install": [
        "uname -m",
        "cat /proc/cpuinfo",
      ],
      "before_script": [
        "git submodule --quiet update --init --recursive",
      ],
      "script": [
        "mkdir -p build",
        "cd build",
        'CFLAGS="$ARCH_FLAGS" CXXFLAGS="$ARCH_FLAGS" meson ..',
        "ninja -v",
        "./test/run-tests",
      ]
    }
  }

def get_jobs():
  job_clang9_armv7 = {
    "name": "clang-9 armv7",
    "platform": {
      "arch": "arm",
    },
    "steps": [
      {
        "environment": {
          "CC": "clang-9",
          "CXX": "clang++-9",
          "ARCH_FLAGS": "-march=armv7a -mfpu=neon",
        }
      }
    ],
    "custom": {
      "install": [
        "apt-get -yq update",
        "apt-get -yq install clang-9 ninja-build git-core python3-pip",
        "pip3 install meson",
      ]
    }
  }

  job_clang9_armv8 = {
    "name": "clang-9 armv8",
    "platform": {
      "arch": "arm",
    },
    "steps": [
      {
        "environment": {
          "CC": "clang-9",
          "CXX": "clang++-9",
          "ARCH_FLAGS": "-march=armv8a -mfpu=neon",
        }
      }
    ],
    "custom": {
      "install": [
        "apt-get -yq update",
        "apt-get -yq install clang-9 ninja-build git-core python3-pip",
        "pip3 install meson",
      ]
    }
  }

  job_gcc8_armv7 = {
    "name": "gcc-8 armv7",
    "platform": {
      "arch": "arm",
    },
    "steps": [
      {
        "environment": {
          "CC": "gcc-8",
          "CXX": "g++-8",
          "ARCH_FLAGS": "-march=armv7-a -mfpu=neon",
        }
      }
    ],
    "custom": {
      "install": [
        "apt-get -yq update",
        "apt-get -yq install gcc-8 g++-8 ninja-build git-core python3-pip",
        "pip3 install meson",
      ]
    }
  }

  job_gcc8_armv8 = {
    "name": "gcc-8 armv8",
    "platform": {
      "arch": "arm",
    },
    "steps": [
      {
        "environment": {
          "CC": "gcc-8",
          "CXX": "g++-8",
          "ARCH_FLAGS": "-march=armv8-a -mfpu=neon",
        }
      }
    ],
    "custom": {
      "install": [
        "apt-get -yq update",
        "apt-get -yq install gcc-8 g++-8 ninja-build git-core python3-pip",
        "pip3 install meson",
      ]
    }
  }

  job_clang7_armv7 = {
    "name": "clang-7 armv7",
    "platform": {
      "arch": "arm",
    },
    "steps": [
      {
        "environment": {
          "CC": "clang-7",
          "CXX": "clang++-7",
          "ARCH_FLAGS": "-march=armv7a -mfpu=neon",
        }
      }
    ],
    "custom": {
      "install": [
        "apt-get -yq update",
        "apt-get -yq install clang-7 ninja-build git-core python3-pip",
        "pip3 install meson",
      ]
    }
  }

  job_clang7_armv8 = {
    "name": "clang-7 armv8",
    "platform": {
      "arch": "arm",
    },
    "steps": [
      {
        "environment": {
          "CC": "clang-7",
          "CXX": "clang++-7",
          "ARCH_FLAGS": "-march=armv8a -mfpu=neon",
        }
      }
    ],
    "custom": {
      "install": [
        "apt-get -yq update",
        "apt-get -yq install clang-7 ninja-build git-core python3-pip",
        "pip3 install meson",
      ]
    }
  }

  job_gcc7_armv7 = {
    "name": "gcc-7 armv7",
    "platform": {
      "arch": "arm",
    },
    "steps": [
      {
        "environment": {
          "CC": "gcc-7",
          "CXX": "g++-7",
          "ARCH_FLAGS": "-march=armv7-a -mfpu=neon",
        }
      }
    ],
    "custom": {
      "install": [
        "apt-get -yq update",
        "apt-get -yq install gcc-7 g++-7 ninja-build git-core python3-pip",
        "pip3 install meson",
      ]
    }
  }

  job_gcc7_armv8 = {
    "name": "gcc-7 armv8",
    "platform": {
      "arch": "arm",
    },
    "steps": [
      {
        "environment": {
          "CC": "gcc-7",
          "CXX": "g++-7",
          "ARCH_FLAGS": "-march=armv8-a -mfpu=neon",
        }
      }
    ],
    "custom": {
      "install": [
        "apt-get -yq update",
        "apt-get -yq install gcc-7 g++-7 ninja-build git-core python3-pip",
        "pip3 install meson",
      ]
    }
  }

  job_fedora = {
    "name": "fedora",
    "steps": [
      {
        "image": "fedora:latest",
        "environment": {
          "CC": "gcc",
          "CXX": "g++",
          "ARCH_FLAGS": "-march=native",
        }
      }
    ],
    "custom": {
      "install": [
        "dnf install -y gcc gcc-c++ ninja-build git-core python3-pip",
        "pip3 install meson",
      ]
    }
  }

  job_fedora_clang_arm64_flags = {
    "name": "fedora clang arm64 flags",
    "platform": {
      "arch": "arm64",
    },
    "steps": [
      {
        "image": "fedora:rawhide",
        "environment": {
          "CC": "clang",
          "CXX": "clang++",
        },
        "failure": "ignore"
      }
    ],
    "custom": {
      "install": [
        "dnf install -y clang ninja-build git-core python3-pip",
        "pip3 install meson",
      ],
      "script": [
        "mkdir -p build",
        "cd build",
        # optflags RPM macro works with gcc.
        # Some flags and specs are not available with clang.
        # https://lists.fedoraproject.org/archives/list/packaging@lists.fedoraproject.org/message/W5UFLUADNB4VF3OBUBSNAPOQL6XBCP74/
        "ARCH_FLAGS=$(rpm -E '%{optflags}' | sed -e 's| -fstack-clash-protection||' -e 's| -specs=[^ ]*||g')",
        'CFLAGS="$ARCH_FLAGS" CXXFLAGS="$ARCH_FLAGS" meson ..',
        "ninja -v",
        "./test/run-tests",
      ]
    }
  }

  return [
    job_clang9_armv7,
    job_clang9_armv8,
    job_gcc8_armv7,
    job_gcc8_armv8,
    job_clang7_armv7,
    job_clang7_armv8,
    job_gcc7_armv7,
    job_gcc7_armv8,
    # job_fedora,
    job_fedora_clang_arm64_flags,
  ]

def main(ctx):
  merged_jobs = []
  for job in get_jobs():
    out = get_default_job()

    # Merge the each elements in the dict.
    for key, value in job.items():
      if type(value) == "list":
        for index, item in enumerate(value):
          out[key][index].update(item)
      elif type(value) == "dict":
        out[key].update(value)
      else:
        out[key] = value

    # Create commands list from custom elements.
    out["steps"][0]["commands"].extend(out["custom"]["before_install"])
    out["steps"][0]["commands"].extend(out["custom"]["install"])
    out["steps"][0]["commands"].extend(out["custom"]["before_script"])
    out["steps"][0]["commands"].extend(out["custom"]["script"])

    # Remove unused custom element.
    out.pop("custom", None)

    merged_jobs.append(out)

  return merged_jobs
