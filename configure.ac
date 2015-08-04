# Copyright 2015 Charles Southerland.
#
# This file is part of json-nom.
#
# json-nom is free software: you can redistribute it and/or modify it under the
# terms of the GNU General Public License as published by the Free Software
# Foundation, either version 3 of the License, or (at your option) any later
# version.
#
# json-nom is distributed in the hope that it will be useful, but WITHOUT ANY
# WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR
# A PARTICULAR PURPOSE.  See the GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License along with
# json-nom.  If not, see <http://www.gnu.org/licenses/>.
#
# More information about json-nom can be found at
# <https://github.com/proidiot/json-nom/>.
#

#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_INIT([json-nom], [0.0.2], [charlie@stuphlabs.com])
AC_CONFIG_SRCDIR([src/main.c])
AC_CONFIG_HEADERS([config.h])
AM_INIT_AUTOMAKE([ -Wall ])

# Checks for programs.
AC_PROG_CC

# Checks for libraries.
AC_SEARCH_LIBS([yajl_tree_parse], [yajl yajl_s], , AC_MSG_ERROR([Either a dynamic or a static version of YAJL is required]))

# Checks for header files.
AC_CHECK_HEADER([argp.h], , AC_MSG_ERROR([Unable to find argp.h]))
AC_CHECK_HEADER([stdbool.h], , AC_MSG_ERROR([Unable to find stdbool.h]))
AC_CHECK_HEADER([stdlib.h], , AC_MSG_ERROR([Unable to find stdlib.h]))
AC_CHECK_HEADER([string.h], , AC_MSG_ERROR([Unable to find string.h]))

# Checks for typedefs, structures, and compiler characteristics.
#AC_CHECK_HEADER_STDBOOL
AC_TYPE_SIZE_T

# Checks for library functions.
AC_FUNC_MALLOC
AC_SEARCH_LIBS([argp_parse], , , AC_MSG_ERROR([Unable to find argp_parse function]))

AC_CONFIG_FILES([Makefile
                 src/Makefile
                 test/Makefile
                 test/behavior.tests/Makefile
                 test/behavior.tests/version.exp])
AC_OUTPUT


