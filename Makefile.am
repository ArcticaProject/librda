NULL =

SUBDIRS = data src util po

ACLOCAL_AMFLAGS = -I m4 ${ACLOCAL_FLAGS}

if WANT_TESTS

SUBDIRS +=				\
        tests				\
        $(NULL)

tests: librda

endif

DISTCHECK_CONFIGURE_FLAGS =		\
    --enable-x2go			\
    --enable-ogon			\
    --disable-silent-rules		\
    --enable-introspection		\
    $(NULL)

MAINTAINERCLEANFILES = \
	$(srcdir)/aclocal.m4 \
	$(srcdir)/config.guess \
	$(srcdir)/config.h.in \
	$(srcdir)/config.sub \
	$(srcdir)/depcomp \
	$(srcdir)/install-sh \
	$(srcdir)/ltmain.sh \
	$(srcdir)/missing \
	$(srcdir)/mkinstalldirs \
	`find "$(srcdir)" -type f -name Makefile.in -print` \
	$(srcdir)/configure \
	$(srcdir)/gtk-doc.make \
	$(srcdir)/m4/gtk-doc.m4 \
	$(srcdir)/m4/intltool.m4
