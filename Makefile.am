# Makefile [Makefile.am] - for tidy - HTML parser and pretty printer
#
#  CVS Info :
#
#     $Author: creitzel $ 
#     $Date: 2003/03/19 18:37:37 $ 
#     $Revision: 1.3 $ 
#
#  Copyright (c) 1998-2003 World Wide Web Consortium
#  (Massachusetts Institute of Technology, European Research 
#  Consortium for Informatics and Mathematics, Keio University).
#  All Rights Reserved.
#
#  Contributing Author(s):
#
#     Dave Raggett <dsr@w3.org>
#     Terry Teague <terry_teague@users.sourceforge.net>
#     Pradeep Padala<ppadala@users.sourceforge.net>
#
#  The contributing author(s) would like to thank all those who
#  helped with testing, bug fixes, and patience.  This wouldn't
#  have been possible without all of you.
#
#  COPYRIGHT NOTICE:
#
#  This software and documentation is provided "as is," and
#  the copyright holders and contributing author(s) make no
#  representations or warranties, express or implied, including
#  but not limited to, warranties of merchantability or fitness
#  for any particular purpose or that the use of the software or
#  documentation will not infringe any third party patents,
#  copyrights, trademarks or other rights. 
#
#  The copyright holders and contributing author(s) will not be
#  liable for any direct, indirect, special or consequential damages
#  arising out of any use of the software or documentation, even if
#  advised of the possibility of such damage.
#
#  Permission is hereby granted to use, copy, modify, and distribute
#  this source code, or portions hereof, documentation and executables,
#  for any purpose, without fee, subject to the following restrictions:
#
#  1. The origin of this source code must not be misrepresented.
#  2. Altered versions must be plainly marked as such and must
#     not be misrepresented as being the original source.
#  3. This Copyright notice may not be removed or altered from any
#     source or altered source distribution.
# 
#  The copyright holders and contributing author(s) specifically
#  permit, without fee, and encourage the use of this source code
#  as a component for supporting the Hypertext Markup Language in
#  commercial products. If you use this source code in a product,
#  acknowledgment is not required but would be appreciated.
#

SUBDIRS = src include bin tests

TESTS = test-thing.sh

EXTRA_DIST = test-thing.sh


# For checking with splint see also http://www.perlfoundation.org/parrot/index.cgi?splint
# Splint: http://splint.org
SPLINT = splint

# Temp directory for splint.  Add +keep to splintflags if you want work files
# kept in there after completion.
SPLINT_TMP = $(TMP)/splint

# Splint flags: http://splint.org/manual/html/appB.html
# The dashes in the names don't make any difference to Splint, but I've
# made them match how they are in the manual.  Otherwise, you might be
# looking for "declundef", except that it's "decl-undef" in the docs.

SPLINT_FLAGS_TIDYP_SPECIFIC = \
	-booltype Bool

SPLINTFLAGS = \
	-Dlinux \
	-I. \
	-I./src \
	-I./include \
	-I/usr/include \
	\
	+standard \
	-hints \
	\
	+indentspaces 4 \
	+locindentspaces 4 \
	+linelen 1200 \
	-message-stream-stdout \
	+showdeephistory \
	-showfunc \
	-tmpdir $(SPLINT_TMP) \
	\
	+posix-lib \
	-skip-posix-headers \
	\
	+ansi89-limits \
	+num-struct-fields 255 \
	\
	-show-summary \
	+show-scan \
	+time-dist \
	\
	+ansi-reserved \
	+ansi-reserved-internal \
	-iso-reserved \
	-iso-reserved-internal \
	-include-nest 10 \
	+bufferoverflow \
	+bufferoverflowhigh \
	+read-only-strings \
	+read-only-trans \
	+strict-destroy \
	+strict-use-released \
	+use-released \
	+macro-assign \
	+macro-empty \
	+macro-parens \
	+macro-redef \
	+macro-stmt \
	+macro-unrecog \
	+bool-compare \
	+ptr-compare \
	+real-compare \
	+unsigned-compare \
	-pred-bool-int \
	-pred-bool-ptr \
	-pred-bool-others \
	-boolops \
	+relax-quals \
	-must-free \
	-mustfreefresh \
	-mustfreeonly \
	+null \
	+nullptrarith \
	+nullret \
	-ptr-arith \
	+ptr-negate \
	-zero-ptr \
	-mem-trans \
	+decl-undef \
	+incon-defs \
	+incon-defs-lib \
	+cpp-names \
	+format-code \
	+format-type \
	+controlnestdepth 15 \
	+duplicate-case \
	+eval-order \
	+eval-order-uncon \
	+char-index \
	+char-int \
	+enum-members \
	+ignore-signs \
	+long-integral \
	+match-any-integral \
	\
	$(SPLINT_FLAGS_TIDYP_SPECIFIC)

# Other options we'd like to add back
# +initallelements : Right now, the *.ops files don't initialize all
#  values of the arrays
# +casebreak: Auto-generated ops have way too case fallthrus right now
# +fcnuse: We have many functions that are defined but not used, but they
#  should get hidden or ifdeffed
# +redef, +redecl: Ops currently have tons of redefinitions

# added to splint target to simplify experimentation,
# example: make SPLINTFLAGS_TEST='-posixstrictlib +posixlib' splint

SPLINT_SOURCE = `echo src/*.c`

splint :
	mkdir -p $(SPLINT_TMP)
	$(SPLINT) $(SPLINTFLAGS) $(SPLINTFLAGS_TEST) $(SPLINT_SOURCE)

tags :
	rm -f tags
	ctags \
		--links=no --totals \
		-R --exclude=.svn --exclude=.git \
		--languages=c \
		-I NOTNULL,NULLOK,ARGIN,ARGMOD,ARGOUT,ARGINOUT,ARGIN_NULLOK,ARGOUT_NULLOK,ARGMOD_NULLOK \
		$(CUR_DIR)

