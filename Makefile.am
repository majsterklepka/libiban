prefix = @prefix@
PACKAGE = @PACKAGE@
VERSION = @VERSION@
libdir = @libdir@/$(PACKAGE)-$(VERSION)
LIB_VERSION = @LIB_VERSION@

ACLOCAL_AMFLAGS = -I m4

lib_LTLIBRARIES = libiban.la
libiban_la_SOURCES = iban.c iban.h
libiban_la_LDFLAGS = $(GMP_LIBS) -version-info $(LIB_VERSION)  

