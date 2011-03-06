CFLAGS = -std=gnu99 -O3 -Wall -msse -msse2 -mtune=native
OUTDIR = bin

all : mem filebackedmem brk event nontemp filemem

mem : mem.c
	gcc ${CFLAGS} mem.c -o ${OUTDIR}/mem

filebackedmem : filebackedmem.c
	gcc ${CFLAGS} filebackedmem.c -o ${OUTDIR}/filebackedmem

brk : brk.c
	gcc ${CFLAGS} brk.c -o ${OUTDIR}/brk

event : event.c
	gcc ${CFLAGS} event.c -o ${OUTDIR}/event

nontemp : nontemp.c
	gcc ${CFLAGS} nontemp.c -o ${OUTDIR}/nontemp

filemem : filemem.c
	gcc ${CFLAGS} filemem.c -o ${OUTDIR}/filemem

clean :
	@rm ${OUTDIR}/mem ${OUTDIR}/brk ${OUTDIR}/event ${OUTDIR}/nontemp ${OUTDIR}/filemem ${OUTDIR}/filebackedmem
