#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

# Release version
m4_define([package_version_major],[2])
m4_define([package_version_minor],[0])
m4_define([package_version_micro],[1])

AC_PREREQ([2.69])
AC_INIT([Libiban], [package_version_major.package_version_minor.package_version_micro], [starywandal@onet.pl], [], [http://github.com/majsterklepka/libiban.git])
AC_CONFIG_SRCDIR([iban.h])
AC_CONFIG_HEADERS([config.h])
AC_CONFIG_AUX_DIR([doc])
AM_INIT_AUTOMAKE([-Wall foreign])
AM_PROG_AR
AC_CONFIG_MACRO_DIR([m4])

LT_INIT(disable-static)

AC_CANONICAL_BUILD


# Checks for programs.
AC_PROG_CC
AC_PROG_INSTALL
AC_PROG_LN_S
PKG_PROG_PKG_CONFIG
PKG_INSTALLDIR

#defining library version
AC_SUBST([LIB_VERSION], [package_version_major:package_version_micro:package_version_minor])

# Checks for libraries.
AC_LANG(C)
AC_CHECK_LIB([gmp],[main],[HAVE_GMP=1, GMP_LIBS="-lgmp $GMP_LIBS"], [gmp not instaled!])

# Checks for header files.
AC_CHECK_HEADERS([stdlib.h string.h error.h errno.h])

# Checks for typedefs, structures, and compiler characteristics.

# Checks for library functions.
AC_FUNC_MALLOC

# linker support
LDFLAGS="-L/usr/lib"
LDFLAGS="-Wl,-rpath -Wl,${libdir}/$PACKAGE $LDFLAGS"
CFLAGS="-I${includedir}/$PACKAGE"
LIBS="${GMP_LIBS}"

AC_DEFINE_UNQUOTED([BUILD], [$build], [build host])

# support for pkg-config config file
PACKAGE_LIBS="-liban"
PACKAGE_SUMMARY="$PACKAGE_NAME - library for validate IBAN number"
PACKAGE_CFLAGS=$CFLAGS
PACKAGE_LDFLAGS=$LDFLAGS
PACKAGE_NAME=$PACKAGE
AX_CREATE_PKGCONFIG_INFO 


AC_CONFIG_FILES([Makefile doc/Makefile])
AC_OUTPUT


