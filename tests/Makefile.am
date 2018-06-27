NULL =

RDA_LIB = -lrda

TESTS =
DISTCLEANFILES =
XFAIL_TESTS =

check_PROGRAMS =

#############################
# Test Loader
#############################

check_PROGRAMS += test-x2go

test_x2go_SOURCES = \
	test-x2go.c

test_x2go_CFLAGS =			\
	-Wall -Werror			\
	$(LIBRDA_CFLAGS)		\
	$(LIBRDA_TESTS_CFLAGS)		\
	-I$(top_srcdir)			\
	-DBUILD_DIR="\"$(builddir)\""	\
	$(NULL)


test_x2go_LDADD =			\
	$(LIBRDA_LIBS)			\
	$(LIBRDA_TESTS_LIBS)		\
	-L$(top_builddir)/src/.libs	\
	$(NULL)

TESTS += test-x2go
