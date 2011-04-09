#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=suncc
CCC=CC
CXX=CC
FC=f95
AS=as

# Macros
CND_PLATFORM=OracleSolarisStudio_12.2-Solaris-Sparc
CND_CONF=Release
CND_DISTDIR=dist

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=build/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/_ext/43898991/mem.o \
	${OBJECTDIR}/_ext/43898991/brk.o \
	${OBJECTDIR}/_ext/43898991/barrierperf.o \
	${OBJECTDIR}/_ext/43898991/nontemp.o \
	${OBJECTDIR}/_ext/43898991/filebackedmem.o \
	${OBJECTDIR}/main.o


# C Compiler Flags
CFLAGS=-xc99=all -errwarn=%all -xO5 -xipo=2 -xipo_archive=writeback -xalias_level=strong -m64 -xvector=simd -xprefetch=auto -xprefetch_auto_type=indirect_array_access -xprefetch_level=3 -xarch=sse2

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-Release.mk dist/Release/OracleSolarisStudio_12.2-Solaris-Sparc/tutorials

dist/Release/OracleSolarisStudio_12.2-Solaris-Sparc/tutorials: ${OBJECTFILES}
	${MKDIR} -p dist/Release/OracleSolarisStudio_12.2-Solaris-Sparc
	${LINK.c} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/tutorials ${OBJECTFILES} ${LDLIBSOPTIONS} 

${OBJECTDIR}/_ext/43898991/mem.o: ../../mem.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/43898991
	$(COMPILE.c) -fast -g -o ${OBJECTDIR}/_ext/43898991/mem.o ../../mem.c

${OBJECTDIR}/_ext/43898991/brk.o: ../../brk.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/43898991
	$(COMPILE.c) -fast -g -o ${OBJECTDIR}/_ext/43898991/brk.o ../../brk.c

${OBJECTDIR}/_ext/43898991/barrierperf.o: ../../barrierperf.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/43898991
	$(COMPILE.c) -fast -g -o ${OBJECTDIR}/_ext/43898991/barrierperf.o ../../barrierperf.c

${OBJECTDIR}/_ext/43898991/nontemp.o: ../../nontemp.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/43898991
	$(COMPILE.c) -fast -g -o ${OBJECTDIR}/_ext/43898991/nontemp.o ../../nontemp.c

${OBJECTDIR}/_ext/43898991/filebackedmem.o: ../../filebackedmem.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/43898991
	$(COMPILE.c) -fast -g -o ${OBJECTDIR}/_ext/43898991/filebackedmem.o ../../filebackedmem.c

${OBJECTDIR}/main.o: main.c 
	${MKDIR} -p ${OBJECTDIR}
	$(COMPILE.c) -fast -g -o ${OBJECTDIR}/main.o main.c

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r build/Release
	${RM} dist/Release/OracleSolarisStudio_12.2-Solaris-Sparc/tutorials

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
