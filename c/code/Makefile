CFLAGS = -std=gnu99 -O3 -Wall -msse -msse2 -mtune=native 
OUTDIR = bin

all : ${OUTDIR}/mem ${OUTDIR}/filebackedmem ${OUTDIR}/brk ${OUTDIR}/event ${OUTDIR}/nontemp ${OUTDIR}/filemem \
	${OUTDIR}/barrierperf

${OUTDIR}/mem : mem.c
	gcc ${CFLAGS} mem.c -o ${OUTDIR}/mem

${OUTDIR}/filebackedmem : filebackedmem.c
	gcc ${CFLAGS} filebackedmem.c -o ${OUTDIR}/filebackedmem

${OUTDIR}/brk : brk.c
	gcc ${CFLAGS} brk.c -o ${OUTDIR}/brk

${OUTDIR}/event : event.c
	gcc ${CFLAGS} event.c -o ${OUTDIR}/event

${OUTDIR}/nontemp : nontemp.c
	gcc ${CFLAGS} nontemp.c -o ${OUTDIR}/nontemp

${OUTDIR}/filemem : filemem.c
	gcc ${CFLAGS} filemem.c -o ${OUTDIR}/filemem

${OUTDIR}/barrierperf : barrierperf.c
	gcc ${CFLAGS} barrierperf.c -o ${OUTDIR}/barrierperf

clean :
	@rm ${OUTDIR}/mem ${OUTDIR}/brk ${OUTDIR}/event ${OUTDIR}/nontemp ${OUTDIR}/filemem ${OUTDIR}/filebackedmem \
	${OUTDIR}/barrierperf

