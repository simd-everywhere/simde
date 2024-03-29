# Disable the automatically set build flags to the environment variables such
# as CC, CFLAGS, and etc.
# See <https://src.fedoraproject.org/rpms/redhat-rpm-config/blob/rawhide/f/macros>.
%undefine _auto_set_build_flags

Name: simde
Version: 1
Release: 1%{?dist}
Summary: Dummy
License: MIT
URL: https://github.com/simd-everywhere/simde
# This value is magically replaced with the archive tar.gz file created by
# `git archive` in the process of the CI.
# Set the existing file `README.md` in case of creating SRPM from this RPM spec
# file on local for testing purpose.
Source0: README.md
# A path to the CI script.
Source1: ci.sh

# List up the needed RPM package names to test here.
# clang, clang++
BuildRequires: clang
BuildRequires: gcc
# g++
BuildRequires: gcc-c++
# ninja
BuildRequires: ninja-build
# pip and setuptools are needed to install and use meson PyPI package.
BuildRequires: python3-devel
BuildRequires: python3-pip
BuildRequires: python3-setuptools
# The GNU time (/bin/time) is used for testing. Use this GNU time rather than
# the embedded time function in bash.
# https://www.gnu.org/software/time/
BuildRequires: time

# RPM package description.
%description

# The bash commands to prepare are executed.
%prep
# Print the replaced value of the Source0.
echo "Source0: %{SOURCE0}"
# Create a dummy file for a valid RPM spec file.
touch dummy.txt

# The bash commands to test are executed.
%check
# Check the directory structure in the tar.gz file.
tar tzvf "%{SOURCE0}" > source_files.txt
head -2 source_files.txt
# Check if the submodule munit is included.
grep munit source_files.txt
# Extract the source archive file.
tar xzf "%{SOURCE0}"

pushd simde-*
# Set the flags used to build the actual RPM package.
# These can be used in the CI testing script.
%global toolchain clang
export CI_CLANG_RPM_CFLAGS="%{build_cflags}"
export CI_CLANG_RPM_CXXFLAGS="%{build_cxxflags}"
export CI_CLANG_RPM_LDFLAGS="%{build_ldflags}"
%global toolchain gcc
export CI_GCC_RPM_CFLAGS="%{build_cflags}"
export CI_GCC_RPM_CXXFLAGS="%{build_cxxflags}"
export CI_GCC_RPM_LDFLAGS="%{build_ldflags}"

echo "Running the CI script %{SOURCE1}."
/bin/time -f '=> [%E]' "%{SOURCE1}"
popd

# Files included in the built RPM package.
%files
%doc dummy.txt

# Changelog entries for the RPM package.
%changelog
* Fri Jun 02 2023 Dummy Dummy <dummy@dummy.com> - 1-1
- Dummy.
