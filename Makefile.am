prefix = @prefix@
libdir = @libdir@
includedir = @includedir@
datadir = @datadir@

pkgconfigdir = ${datadir}/pkgconfig

ACLOCAL_AMFLAGS = -I m4 --install

SUBDIRS = doc 

pkglib_LTLIBRARIES = libiban.la
libiban_la_SOURCES = iban.c iban.h
libiban_la_LDFLAGS = -version-info @LIB_VERSION@
pkginclude_HEADERS = iban.h
pkgconfig_DATA = libiban.pc  

CLEANFILES =  libiban.pc libiban.pc.in libiban-uninstalled.pc libiban-uninstalled.sh
