require recipes-devtools/cmake/cmake.inc

LICENSE = "BSD-3-Clause"
LIC_FILES_CHKSUM = " \
    file://Copyright.txt;md5=c721f56fce89ba2eadc2fdd8ba1f4d83 \
    file://Source/cmake.h;endline=2;md5=a5f70e1fef8614734eae0d62b4f5891b \
"

inherit debian-package
require recipes-debian/sources/cmake-latest.inc

DEBIAN_UNPACK_DIR = "${WORKDIR}/cmake-${PV}"

FILESPATH_append = ":${COREBASE}/meta/recipes-devtools/cmake/cmake"
SRC_URI += " \
    file://0002-cmake-Prevent-the-detection-of-Qt5.patch \
    file://0003-cmake-support-OpenEmbedded-Qt4-tool-binary-names.patch \
    file://0004-Fail-silently-if-system-Qt-installation-is-broken.patch \
"

# This is specific to the npm package that installs cmake, so isn't
# relevant to OpenEmbedded
CVE_CHECK_WHITELIST += "CVE-2016-10642"
