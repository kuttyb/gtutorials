# compiler
WORDSIZE = -m64
CC       = gcc
CFLAGS   = -O3 -Wall -msse2 -march=native -std=gnu99 -flto ${WORDSIZE}
# defines
OUTDIR = bin

all : ${OUTDIR}/mem ${OUTDIR}/filebackedmem ${OUTDIR}/brk ${OUTDIR}/nontemp ${OUTDIR}/filemem \
	${OUTDIR}/barrierperf ${OUTDIR}/alignment

${OUTDIR}/mem : mem.c
	${CC} ${CFLAGS} mem.c -o ${OUTDIR}/mem

${OUTDIR}/filebackedmem : filebackedmem.c
	${CC} ${CFLAGS} filebackedmem.c -o ${OUTDIR}/filebackedmem

${OUTDIR}/brk : brk.c
	${CC} ${CFLAGS} brk.c -o ${OUTDIR}/brk

${OUTDIR}/nontemp : nontemp.c
	${CC} ${CFLAGS} nontemp.c -o ${OUTDIR}/nontemp

${OUTDIR}/filemem : filemem.c
	${CC} ${CFLAGS} filemem.c -o ${OUTDIR}/filemem

${OUTDIR}/barrierperf : barrierperf.c
	${CC} ${CFLAGS} barrierperf.c -o ${OUTDIR}/barrierperf

${OUTDIR}/alignment : alignment.c
	${CC} ${CFLAGS} alignment.c -o ${OUTDIR}/alignment

clean :
	@rm ${OUTDIR}/mem ${OUTDIR}/brk ${OUTDIR}/nontemp ${OUTDIR}/filemem ${OUTDIR}/filebackedmem \
	${OUTDIR}/barrierperf ${OUTDIR}/alignment

