CC     = suncc
CFLAGS = -xc99=all -errwarn=%all -xO5 \
	 -xipo=2 -xipo_archive=writeback \
	 -xalias_level=strong \
         -xprefetch=auto -xprefetch_auto_type=indirect_array_access -xprefetch_level=3 \
         -xarch=sse2
OUTDIR = bin

all : ${OUTDIR}/mem ${OUTDIR}/filebackedmem ${OUTDIR}/brk ${OUTDIR}/event ${OUTDIR}/nontemp ${OUTDIR}/filemem \
	${OUTDIR}/barrierperf

${OUTDIR}/mem : mem.c
	${CC} ${CFLAGS} mem.c -o ${OUTDIR}/mem

${OUTDIR}/filebackedmem : filebackedmem.c
	${CC} ${CFLAGS} filebackedmem.c -o ${OUTDIR}/filebackedmem

${OUTDIR}/brk : brk.c
	${CC} ${CFLAGS} brk.c -o ${OUTDIR}/brk

${OUTDIR}/event : event.c
	${CC} ${CFLAGS} event.c -o ${OUTDIR}/event

${OUTDIR}/nontemp : nontemp.c
	${CC} ${CFLAGS} nontemp.c -o ${OUTDIR}/nontemp

${OUTDIR}/filemem : filemem.c
	${CC} ${CFLAGS} filemem.c -o ${OUTDIR}/filemem

${OUTDIR}/barrierperf : barrierperf.c
	${CC} ${CFLAGS} barrierperf.c -o ${OUTDIR}/barrierperf

clean :
	@rm ${OUTDIR}/mem ${OUTDIR}/brk ${OUTDIR}/event ${OUTDIR}/nontemp ${OUTDIR}/filemem ${OUTDIR}/filebackedmem \
	${OUTDIR}/barrierperf

