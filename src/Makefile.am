-include $(INTROSPECTION_MAKEFILE)

AM_CPPFLAGS = -DLOCALEDIR=\"$(localedir)\" -DDEFAULT_TEXT_DOMAIN=\"libbytesize\"
LDADD = $(LIBINTL)

lib_LTLIBRARIES = libbytesize.la
libbytesize_la_CFLAGS = $(GLIB_CFLAGS) $(GOBJECT_CFLAGS) -Wall -Wextra -Werror -Wno-overflow
libbytesize_la_LIBADD = $(GLIB_LIBS) $(GOBJECT_LIBS) -lgmp
libbytesize_la_LDFLAGS = -version-info 0:0:0
libbytesize_la_SOURCES = bs_size.c bs_size.h gettext.h

noinst_dist_SOURCES = gettext.h

if HAVE_INTROSPECTION
GIHEADERS = ${srcdir}/bs_size.h
GISOURCES = ${srcdir}/bs_size.c
endif

ByteSize-1.0.gir: libbytesize.la

ByteSize_1_0_gir_FILES = $(GIHEADERS) $(GISOURCES)
ByteSize_1_0_gir_LIBS = libbytesize.la
ByteSize_1_0_gir_INCLUDES = GObject-2.0
ByteSize_1_0_gir_LDFLAGS = -lgmp
ByteSize_1_0_gir_SCANNERFLAGS = --warn-error --warn-all --identifier-prefix=BS --symbol-prefix=bs
ByteSize_1_0_gir_EXPORT_PACKAGES = bytesize

INTROSPECTION_GIRS = ByteSize-1.0.gir

typelibdir = $(libdir)/girepository-1.0
typelib_DATA = $(INTROSPECTION_GIRS:.gir=.typelib)

girdir = $(datadir)/gir-1.0
gir_DATA = $(INTROSPECTION_GIRS)

libincludedir = $(includedir)/bytesize
libinclude_HEADERS = bs_size.h

pkgconfigdir = $(libdir)/pkgconfig
pkgconfig_DATA = ${builddir}/bytesize.pc

SUBDIRS = python
CLEANFILES = $(INTROSPECTION_GIRS) $(typelib_DATA)
MAINTAINERCLEANFILES = Makefile.in
