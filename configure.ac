#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.69])
AC_INIT([libiban], [2.0.1], [starywandal@onet.pl])
AC_CONFIG_SRCDIR([iban.h])
AC_CONFIG_HEADERS([config.h])
AM_INIT_AUTOMAKE([-Wall foreign])
AM_PROG_AR
AC_CONFIG_MACRO_DIR([m4])
AC_ENABLE_SHARED
AC_DISABLE_STATIC
LT_INIT

# Checks for programs.
AC_PROG_CC
AC_PROG_INSTALL
AC_PROG_LN_S

#defining library version
LIB_VERSION=2:1:0
AC_SUBST(LIB_VERSION)
AC_DEFINE_UNQUOTED([LIB_VERSION],[$LIB_VERSION],[number library version])


# Checks for libraries.
AC_LANG(C)
AC_CHECK_LIB([gmp],[main],[HAVE_GMP=1, GMP_LIBS="$GMP_LIBS -lgmp"], [gmp not instaled!])
AC_SUBST(GMP_LIBS)
AC_DEFINE_UNQUOTED([GMP_LIBS],[$GMP_LIBS],[link to gmp library])

# Checks for header files.
AC_CHECK_HEADERS([stdlib.h string.h])

# Checks for typedefs, structures, and compiler characteristics.

# Checks for library functions.
AC_FUNC_MALLOC

AC_CONFIG_FILES([Makefile])
AC_OUTPUT
