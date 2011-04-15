# compiler
Q        = @
WORDSIZE = -m64
CC       = gcc
CFLAGS   = -O3 -Wall -msse2 -march=native -std=gnu99 -flto ${WORDSIZE} 
# defines
OUTDIR = bin

all : ${OUTDIR}/mem ${OUTDIR}/filebackedmem ${OUTDIR}/brk ${OUTDIR}/nontemp ${OUTDIR}/filemem \
	${OUTDIR}/barrierperf ${OUTDIR}/alignment

${OUTDIR}/mem : mem.c
	@echo $<
	${Q} ${CC} ${CFLAGS} $< -o $@


${OUTDIR}/filebackedmem : filebackedmem.c
	@echo $<
	${Q} ${CC} ${CFLAGS} $< -o $@


${OUTDIR}/brk : brk.c
	@echo $<
	${Q} ${CC} ${CFLAGS} $< -o $@


${OUTDIR}/nontemp : nontemp.c
	@echo $<
	${Q} ${CC} ${CFLAGS} $< -o $@


${OUTDIR}/filemem : filemem.c
	@echo $<
	${Q} ${CC} ${CFLAGS} $< -o $@


${OUTDIR}/barrierperf : barrierperf.c
	@echo $<
	${Q} ${CC} ${CFLAGS} $< -o $@


${OUTDIR}/alignment : alignment.c
	@echo $<
	${Q} ${CC} ${CFLAGS} $< -o $@


clean :
	@rm ${OUTDIR}/mem ${OUTDIR}/brk ${OUTDIR}/nontemp ${OUTDIR}/filemem ${OUTDIR}/filebackedmem \
	${OUTDIR}/barrierperf ${OUTDIR}/alignment

