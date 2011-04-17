 #   Copyright 2011 Kutty Banerjee <kutty.banerjee@gmail.com> 
 #
 #   This program is free software: you can redistribute it and/or modify
 #   it under the terms of the GNU General Public License as published by
 #   the Free Software Foundation, either version 3 of the License, or
 #   (at your option) any later version.
 #
 #   This program is distributed in the hope that it will be useful,
 #   but WITHOUT ANY WARRANTY; without even the implied warranty of
 #   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 #   GNU General Public License for more details.
 #
 #   You should have received a copy of the GNU General Public License
 #   along with this program.  If not, see <http://www.gnu.org/licenses/>.
 #
include ./../sources
include make.defs
# Compiler specific
ifdef STUDIO
include make.studio
endif 
ifdef GCC
include make.gcc
endif

# TARGETs
TARGETS = 
ifdef TARGET_BINARY
TARGETS += ${BINNAME}
endif
ifdef TARGET_LIBRARY
TARGETS += ${LIBNAME}
endif



all : ${TARGETS}

include make.rules
