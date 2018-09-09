.PHONY:clean
## variable
CC=gcc
MYLIB_INC_DIR=../mylib
DEBUG=1
ifeq ($(DEBUG),1)
C_FLAGS=-Wall -g -I ${MYLIB_INC_DIR}
else
C_FLAGS=-Wall -I ${MYLIB_INC_DIR}
endif
MYLIB_LINK_DIR=../obj
LINK_FLAGS=-L ${MYLIB_LINK_DIR} -lapue -lpthread
BIN=bin
## recipe
${BIN}/c14n1_fig14.1_nonblockw.elf:c14n1_fig14.1_nonblockw.c ${MYLIB_INC_DIR}/apue.h
	${CC} $<  ${C_FLAGS} ${LINK_FLAGS} -o $@
${BIN}/c14n2_fig14.7_deadlock.elf:c14n2_fig14.7_deadlock.c ${MYLIB_INC_DIR}/apue.h
	${CC} $<  ${C_FLAGS} ${LINK_FLAGS} -o $@
${BIN}/c14n3_fig14.12_mandatory.elf:c14n3_fig14.12_mandatory.c ${MYLIB_INC_DIR}/apue.h
	${CC} $<  ${C_FLAGS} ${LINK_FLAGS} -o $@

${BIN}/self1_nonblock_r.elf:self1_nonblock_r.c ${MYLIB_INC_DIR}/apue.h
	${CC} $<  ${C_FLAGS} ${LINK_FLAGS} -o $@
clean:
	rm -rf *.elf *.o bin/*.elf
