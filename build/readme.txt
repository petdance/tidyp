Tidyp Build Files

Each subdirectory contains input files to a selected build system for
TidyLib and the command line driver.  For details on any given build
system, see the readme file for that system.

Directory  System                Comments
---------  --------------------  --------------------------
gmake      GNU Make              Used for "official" builds

gnuauto    GNU AutoConf          Supports shared lib builds


Common Build Options

There are some basic build options for TidypLib, independent
of platform and build system.  Typically, these options can
be enabled or disabled by setting a macro value within the
Makefile or its equivalent.  An option may be disabled by
setting its value to "0".  Enable by setting to "1".  Again,
consult the directions for each build system for details
on how to enable/disable each option.

Option                        Default   Description
----------------------------  --------  ---------------------------------
DMALLOC                       Disabled  Use dmalloc for memory debugging
SUPPORT_UTF16_ENCODINGS       Enabled   Support Unicode documents
SUPPORT_ASIAN_ENCODINGS       Enabled   Support Big5 and ShiftJIS docs
