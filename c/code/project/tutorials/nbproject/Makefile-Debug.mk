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
CND_PLATFORM=OracleSolarisStudio_12.2-Linux-x86
CND_CONF=Debug
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
	${OBJECTDIR}/main.o \
	${OBJECTDIR}/_ext/43898991/filebackedmem.o


# C Compiler Flags
CFLAGS=-xc99=all -errwarn=%all -g -xalias_level=strong -m32 -xvector=simd -xprefetch=auto -xprefetch_auto_type=indirect_array_access -xprefetch_level=3 -xarch=sse2

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
	"${MAKE}"  -f nbproject/Makefile-Debug.mk dist/Debug/OracleSolarisStudio_12.2-Linux-x86/tutorials

dist/Debug/OracleSolarisStudio_12.2-Linux-x86/tutorials: ${OBJECTFILES}
	${MKDIR} -p dist/Debug/OracleSolarisStudio_12.2-Linux-x86
	${LINK.c} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/tutorials ${OBJECTFILES} ${LDLIBSOPTIONS} 

${OBJECTDIR}/_ext/43898991/mem.o: ../../mem.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/43898991
	$(COMPILE.c) -g -o ${OBJECTDIR}/_ext/43898991/mem.o ../../mem.c

${OBJECTDIR}/_ext/43898991/brk.o: ../../brk.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/43898991
	$(COMPILE.c) -g -o ${OBJECTDIR}/_ext/43898991/brk.o ../../brk.c

${OBJECTDIR}/_ext/43898991/barrierperf.o: ../../barrierperf.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/43898991
	$(COMPILE.c) -g -o ${OBJECTDIR}/_ext/43898991/barrierperf.o ../../barrierperf.c

${OBJECTDIR}/_ext/43898991/nontemp.o: ../../nontemp.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/43898991
	$(COMPILE.c) -g -o ${OBJECTDIR}/_ext/43898991/nontemp.o ../../nontemp.c

${OBJECTDIR}/main.o: main.c 
	${MKDIR} -p ${OBJECTDIR}
	$(COMPILE.c) -g -o ${OBJECTDIR}/main.o main.c

${OBJECTDIR}/_ext/43898991/filebackedmem.o: ../../filebackedmem.c 
	${MKDIR} -p ${OBJECTDIR}/_ext/43898991
	$(COMPILE.c) -g -o ${OBJECTDIR}/_ext/43898991/filebackedmem.o ../../filebackedmem.c

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r build/Debug
	${RM} dist/Debug/OracleSolarisStudio_12.2-Linux-x86/tutorials

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
