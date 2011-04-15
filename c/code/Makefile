# compiler
Q        = @
WORDSIZE = -m64
CC       = gcc
CFLAGS   = -O3 -Wall -msse2 -march=native -std=gnu99 -flto ${WORDSIZE} 
# defines
OUTDIR = bin

all : ${OUTDIR}/mem ${OUTDIR}/filebackedmem ${OUTDIR}/brk ${OUTDIR}/nontemp ${OUTDIR}/filemem \
	${OUTDIR}/barrierperf ${OUTDIR}/alignment

${OUTDIR}/% :: %.c
	@echo $<
	${Q} ${CC} ${CFLAGS} $< -o $@

${OUTDIR}/mem           : mem.c
${OUTDIR}/filebackedmem : filebackedmem.c
${OUTDIR}/brk           : brk.c
${OUTDIR}/nontemp       : nontemp.c
${OUTDIR}/filemem       : filemem.c
${OUTDIR}/barrierperf   : barrierperf.c
${OUTDIR}/alignment     : alignment.c


clean :
	${Q} echo "cleaning..." 
	$(shell rm ${OUTDIR}/*)

