NULL =

lib_LTLIBRARIES = librda.la

CLEANFILES =
DISTCLEANFILES =
EXTRA_DIST =
BUILT_SOURCES =

st_file = rda_supported_technologies.h

$(st_file): $(st_file).in
	cp $< $@
	for tech in $(SUPPORTED_TECHNOLOGIES); do sed -r -e "s|// \@WITH_REMOTE_AWARENESS_($$tech)\@\s+.*|#define WITH_REMOTE_AWARENESS_\1|" -i $@; done

CLEANFILES += $(st_file)
EXTRA_DIST += $(st_file).in
BUILT_SOURCES += $(st_file)

librdaincludedir = $(includedir)/rda
librdainclude_HEADERS =			\
	rda_supported_technologies.h	\
	rda_ogon.h			\
	rda_x2go.h			\
	rda.h				\
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
rda_1_0_gir_CFLAGS = $(librda_la_CFLAGS) -I$(srcdir)
rda_1_0_gir_LIBS = librda.la
rda_1_0_gir_FILES = $(introspection_sources)

girdir = $(datadir)/gir-1.0
gir_DATA = $(INTROSPECTION_GIRS)

typelibdir = $(libdir)/girepository-1.0
typelib_DATA = $(INTROSPECTION_GIRS:.gir=.typelib)

CLEANFILES += $(gir_DATA) $(typelib_DATA)
endif
