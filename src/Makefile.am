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
	$(if WITH_X2GO_AWARENESS, rda_x2go.c) \
	$(if WITH_OGON_AWARENESS, rda_ogon.c) \
	$(NULL)

librda_la_CFLAGS =			\
	$(LIBRDA_CFLAGS)		\
	$(NULL)

librda_la_LIBADD =			\
	$(LIBRDA_LIBS)			\
	$(NULL)

pkgconfig_DATA = rda.pc
pkgconfigdir = $(libdir)/pkgconfig
