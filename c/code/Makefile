CC     = suncc
CFLAGS = -xc99=all -errwarn=%all -xO5 \
	 -xipo=2 -xipo_archive=writeback \
	 -xalias_level=strong \
	 -xvector=simd \
         -xprefetch=auto -xprefetch_auto_type=indirect_array_access -xprefetch_level=3 \
         -xarch=sse2
LINTFLAGS = -m64
OUTDIR = bin

all : ${OUTDIR}/mem ${OUTDIR}/filebackedmem ${OUTDIR}/brk ${OUTDIR}/event ${OUTDIR}/nontemp ${OUTDIR}/filemem \
	${OUTDIR}/barrierperf ${OUTDIR}/loop

${OUTDIR}/mem : mem.c
	${CC} ${CFLAGS} mem.c -o ${OUTDIR}/mem
	${LINT} ${LINTFLAGS} $<

${OUTDIR}/filebackedmem : filebackedmem.c
	${CC} ${CFLAGS} filebackedmem.c -o ${OUTDIR}/filebackedmem
	${LINT} ${LINTFLAGS} $<

${OUTDIR}/brk : brk.c
	${CC} ${CFLAGS} brk.c -o ${OUTDIR}/brk
	${LINT} ${LINTFLAGS} $<

${OUTDIR}/event : event.c
	${CC} ${CFLAGS} event.c -o ${OUTDIR}/event
	${LINT} ${LINTFLAGS} $<

${OUTDIR}/nontemp : nontemp.c
	${CC} ${CFLAGS} nontemp.c -o ${OUTDIR}/nontemp
	${LINT} ${LINTFLAGS} $<

${OUTDIR}/filemem : filemem.c
	${CC} ${CFLAGS} filemem.c -o ${OUTDIR}/filemem
	${LINT} ${LINTFLAGS} $<

${OUTDIR}/barrierperf : barrierperf.c
	${CC} ${CFLAGS} barrierperf.c -o ${OUTDIR}/barrierperf
	${LINT} ${LINTFLAGS} $<

${OUTDIR}/loop : loop.c
	${CC} ${CFLAGS} loop.c -o ${OUTDIR}/loop

clean :
	@rm ${OUTDIR}/mem ${OUTDIR}/brk ${OUTDIR}/event ${OUTDIR}/nontemp ${OUTDIR}/filemem ${OUTDIR}/filebackedmem \
	${OUTDIR}/barrierperf ${OUTDIR}/loop

