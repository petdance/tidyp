AUTOMAKE_OPTIONS = foreign

.PHONY: test

AM_CFLAGS = @CFLAGS@ @WARNING_CFLAGS@

INCLUDES = -I$(top_srcdir)/include

bin_PROGRAMS = tidyp
tidyp_SOURCES = ../src/tidyp.c

tidyp_LDADD = $(top_builddir)/src/libtidyp.la
