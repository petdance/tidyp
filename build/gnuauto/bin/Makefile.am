AUTOMAKE_OPTIONS = foreign

.PHONY: test

AM_CFLAGS = @CFLAGS@ @WARNING_CFLAGS@

INCLUDES = -I$(top_srcdir)/include

bin_PROGRAMS = tidy
tidyp_SOURCES = ../src/tidyp.c

tidy_LDADD = $(top_builddir)/src/libtidy.la
