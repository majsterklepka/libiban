prefix = @prefix@
PACKAGE = @PACKAGE@
VERSION = @VERSION@
libdir = @libdir@
includedir = @includedir@
datadir = @datadir@
pkgconfigdir = @datadir@/pkgconfig
pkglibdir = $(libdir)/$(PACKAGE)
pkgincludedir = $(includedir)/$(PACKAGE)
LIB_VERSION = @LIB_VERSION@

EXTRA_DIST = libiban.pc

ACLOCAL_AMFLAGS = -I m4 --install

pkglib_LTLIBRARIES = libiban.la
libiban_la_SOURCES = iban.c iban.h
libiban_la_LDFLAGS = $(GMP_LIBS) -version-info $(LIB_VERSION)
pkginclude_HEADERS = iban.h
pkgconfig_DATA = libiban.pc  

