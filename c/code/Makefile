CFLAGS = -std=gnu99 -O3 -Wall -msse -msse2 -mtune=native

all : mem filebackedmem brk event nontemp filemem

mem : mem.c
	gcc ${CFLAGS} mem.c -o mem

filebackedmem : filebackedmem.c
	gcc ${CFLAGS} filebackedmem.c -o filebackedmem

brk : brk.c
	gcc ${CFLAGS} brk.c -o brk

event : event.c
	gcc ${CFLAGS} event.c -o event

nontemp : nontemp.c
	gcc ${CFLAGS} nontemp.c -o nontemp

filemem : filemem.c
	gcc ${CFLAGS} filemem.c -o filemem

clean :
	@rm mem brk event nontemp filemem filebackedmem
