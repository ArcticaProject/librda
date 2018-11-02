NULL =

lib_LTLIBRARIES = librda.la

CLEANFILES =
DISTCLEANFILES =

rda_headers =				\
	rda.h				\
	$(NULL)

librdaincludedir = $(includedir)/rda
librdainclude_HEADERS =			\
	$(rda_headers)			\
	$(NULL)

librda_la_SOURCES =			\
	rda.c				\
	rda_x2go.c			\
	rda_ogon.c			\
	$(NULL)

librda_la_CFLAGS =			\
	$(LIBRDA_CFLAGS)		\
	$(NULL)

librda_la_LIBADD =			\
	$(LIBRDA_LIBS)			\
	$(NULL)

pkgconfig_DATA = rda.pc
pkgconfigdir = $(libdir)/pkgconfig

-include $(INTROSPECTION_MAKEFILE)
INTROSPECTION_GIRS = rda-1.0.gir
INTROSPECTION_SCANNER_ARGS = --add-include-path=$(srcdir) --warn-all
INTROSPECTION_COMPILER_ARGS = --includedir=$(srcdir)

if HAVE_INTROSPECTION
introspection_sources = $(librdainclude_HEADERS)	\
	$(librda_la_SOURCES)				\
	$(NULL)

rda-1.0.gir: librda.la
rda_1_0_gir_INCLUDES = GObject-2.0 GLib-2.0
rda_1_0_gir_CFLAGS = $(librda_la_CFLAGS)
rda_1_0_gir_LIBS = librda.la
rda_1_0_gir_FILES = $(introspection_sources)

girdir = $(datadir)/gir-1.0
gir_DATA = $(INTROSPECTION_GIRS)

typelibdir = $(libdir)/girepository-1.0
typelib_DATA = $(INTROSPECTION_GIRS:.gir=.typelib)

CLEANFILES += $(gir_DATA) $(typelib_DATA)
endif
