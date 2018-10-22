AC_INIT([librda],
        [0.0.1],
        [https://github.com/ArcticaProject/librda/issues],
        [librda],
        [https://github.com/ArcticaProject/librda])

AC_PREREQ([2.64])

AC_CONFIG_SRCDIR([src])

AM_INIT_AUTOMAKE([1.9 foreign no-dist-gzip dist-xz tar-ustar check-news])
m4_ifdef([AM_SILENT_RULES], [AM_SILENT_RULES([yes])])

AC_CONFIG_HEADERS([config.h])

AC_CONFIG_MACRO_DIR([m4])

dnl make sure we keep ACLOCAL_FLAGS around for maintainer builds to work
AC_SUBST(ACLOCAL_AMFLAGS, "\${ACLOCAL_FLAGS}")

# Before making a release, the LT_VERSION string should be modified.
# The string is of the form C:R:A.
# - If interfaces have been changed or added, but binary compatibility has
#   been preserved, change to C+1:0:A+1
# - If binary compatibility has been broken (eg removed or changed interfaces)
#   change to C+1:0:0
# - If the interface is the same as the previous version, change to C:R+1:A

LT_VERSION=18:4:1
AC_SUBST(LT_VERSION)

AM_MAINTAINER_MODE

AC_PROG_CC
AC_STDC_HEADERS
AC_PROG_LIBTOOL
PKG_PROG_PKG_CONFIG

AC_ARG_ENABLE(deprecation_flags,
              [AS_HELP_STRING([--enable-deprecation-flags],
                              [use *_DISABLE_DEPRECATED flags @<:@default=no@:>@])],,
              [enable_deprecation_flags=no])

if test "x$enable_deprecation_flags" = "xyes"; then
   DISABLE_DEPRECATED_CFLAGS=$DISABLE_DEPRECATED
   AC_SUBST(DISABLE_DEPRECATED_CFLAGS)
fi

GLIB_REQUIRED=2.37.0
GIO_REQUIRED=2.26.0
GTK3_REQUIRED_VERSION=3.6

GOBJECT_INTROSPECTION_CHECK([0.9.7])

dnl pkg-config dependency checks

PKG_CHECK_MODULES(LIBRDA, glib-2.0 >= $GLIB_REQUIRED gio-2.0 >= $GIO_REQUIRED)

dnl enable/disable awarenesses

AC_ARG_ENABLE([x2go],
              [AS_HELP_STRING([--enable-x2go],
                              [enable awareness of X2Go sessions])],
              [enable_x2go=yes])
if test "x$enable_x2go" != "x"; then
    AC_DEFINE([WITH_X2GO_AWARENESS],,[Build with X2Go awareness])
fi

AC_ARG_ENABLE([ogon],
              [AS_HELP_STRING([--enable-ogon],
                              [enable awareness of Ogon sessions])],
              [enable_ogon=yes])
if test "x$enable_ogon" != "x"; then
    AC_DEFINE([WITH_OGON_AWARENESS],,[Build with Ogon awareness])
fi

dnl Language Support

IT_PROG_INTLTOOL([0.50.1])
GETTEXT_PACKAGE=librda
AC_DEFINE_UNQUOTED(GETTEXT_PACKAGE, "$GETTEXT_PACKAGE",
		   [The gettext translation domain])
AC_SUBST(GETTEXT_PACKAGE)
AM_GLIB_GNU_GETTEXT

AC_CONFIG_FILES([
Makefile
po/Makefile.in
src/Makefile
src/rda.pc
tests/Makefile
])

#########################
# Check if build tests
#########################
AC_ARG_ENABLE([tests],
        AC_HELP_STRING([--disable-tests], [disable tests]),,
        [enable_tests=yes])
AM_CONDITIONAL([WANT_TESTS], [test "x$enable_tests" != "xno"])

if test "x$enable_tests" != "xno"; then
    PKG_CHECK_MODULES(LIBRDA_TESTS, gtk+-3.0 >= $GTK3_REQUIRED_VERSION)
fi

AC_OUTPUT

dnl ---------------------------------------------------------------------------
dnl - Show summary
dnl ---------------------------------------------------------------------------

echo "
librda $VERSION
`echo librda $VERSION | sed "s/./=/g"`

    prefix:                       ${prefix}
    exec_prefix:                  ${exec_prefix}
    libdir:                       ${libdir}
    bindir:                       ${bindir}
    sbindir:                      ${sbindir}
    sysconfdir:                   ${sysconfdir}
    localstatedir:                ${localstatedir}
    datadir:                      ${datadir}
    source code location:         ${srcdir}
    compiler:                     ${CC}
    cflags:                       ${CFLAGS}
    Use *_DISABLE_DEPRECATED:     ${enable_deprecation_flags}

    Build introspection support:  ${found_introspection}

    Enable X2Go awareness         ${enable_x2go}
    Enable Ogon awareness         ${enable_ogon}
"
