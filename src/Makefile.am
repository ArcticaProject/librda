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
	$(rda_headers)			\
	rda.c				\
	rda_x2go.h			\
	rda_x2go.c			\
	$(NULL)

librda_la_CFLAGS =			\
	$(LIBRDA_CFLAGS)		\
	$(NULL)

librda_la_LIBADD =			\
	$(LIBRDA_LIBS)			\
	$(NULL)

pkgconfig_DATA = rda.pc
pkgconfigdir = $(libdir)/pkgconfig
