NULL =

RDA_LIB = -lrda

DISTCLEANFILES =

bin_PROGRAMS = rdacheck

rdacheck_SOURCES = \
	rdacheck.c

rdacheck_CFLAGS =			\
	-Wall -Werror			\
	$(LIBRDA_CFLAGS)		\
	-I$(top_srcdir)/src/		\
	-DBUILD_DIR="\"$(builddir)\""	\
	$(NULL)

rdacheck_LDADD =			\
	$(RDA_LIB)			\
	$(LIBRDA_LIBS)			\
	-L$(top_builddir)/src/.libs	\
	$(NULL)
