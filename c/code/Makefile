# compiler
Q        = @
WORDSIZE = -m64
CC       = gcc
CFLAGS   = -O3 -Wall -msse2 -march=native -std=gnu99 -flto ${WORDSIZE} 
# defines
OUTDIR = bin

all : $(patsubst %.c,${OUTDIR}/%, $(sort $(shell ls *.c)))

${OUTDIR}/% :: %.c
	@echo $<
	${Q} ${CC} ${CFLAGS} $< -o $@

clean :
	${Q} echo "cleaning..." 
	$(shell rm ${OUTDIR}/*)

