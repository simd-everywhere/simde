# Packit

This document is to use Packit CI that enables us to test SIMDe on Fedora project's native CPU environments, x86_64, i686, aarch64, ppc64le and s390x as of June 2023. Packit CI can be executed on pull-request and push, and create a RPM package based on the specified RPM spec (recipe) file, then run commands in the `%check` section in the RPM spec file in the environments. We use a minimal RPM spec file only to run tests on the environments.

* The configuration document: https://packit.dev/docs/configuration
* Report issues (bugs or feature suggestions): https://github.com/packit/packit/issues
* Pipeline history: https://dashboard.packit.dev/pipelines

## Motivation and context

We want to keep [Fedora rawhide](https://docs.fedoraproject.org/en-US/releases/rawhide/) cases in the CI. Fedora rawhide is the latest development version of Fedora Linux, not a named release that might go out of support later. Because the gcc and clang new versions are landing on Fedora rawhide earlier than other Linux distributions.

## How to check the CI results

1. Enable Packit CI for your forked simde repository. See the [onboarding guide](https://packit.dev/docs/guide/).
2. When you push branches to your repository, the CI is triggered. Go to the [Pipelines](https://dashboard.packit.dev/pipelines) page to see your pipeline.
3. Do browser-search by "simde".
4. Click a "fedora-\*-\*" button on the Jobs to go to the job detailed page.
5. You can see 3 links below. You can check the Build Logs first, and the SRPM Logs second if it is necessary.
    * **SRPM Logs**: A log of the preparation of the test such as installing the used RPM packages to test. This is a log that the system creates Source RPM (SRPM) from the RPM spec file.
    * **Web URL**: Go to the jobs page in Fedora Copr web system used to run the RPM.
    * **Build Logs**: It includes the testing log and the result. This is a log that the system builds a RPM package from the SRPM. The tests are executed in a part of the processes.

## Customize the CI

* `.packit.yml`
  * You can customize the executed CPU pipelines at the `jobs - targets`, when you see infra issues in the specific CPU pipelines.
* `.packit/ci.sh`
  * You can customize if the CI fails when the tests fail at the "Customized constants" section.
  * You can customize the tests to be executed to save the CI's total running time at the "Customized constants" section.
