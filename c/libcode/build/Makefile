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
