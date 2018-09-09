.PHONY:clean
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
##
${BIN}/fig8.12RaceCondition.elf:fig8.12RaceCondition.c ${MYLIB_INC_DIR}/apue.h
	${CC} $<  ${C_FLAGS} ${LINK_FLAGS} -o $@
${BIN}/fig8.13_tellwait2.elf:fig8.13_tellwait2.c ${MYLIB_INC_DIR}/apue.h
	${CC} $<  ${C_FLAGS} ${LINK_FLAGS} -o $@
clean:
	rm -rf *.elf *.o bin/*.elf
