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
${BIN}/self1_umask.elf:self1_umask.c ${MYLIB_INC_DIR}/apue.h
	${CC} $<  ${C_FLAGS} ${LINK_FLAGS} -o $@
${BIN}/c13n1_daemonize.elf:c13n1_daemonize.c ${MYLIB_INC_DIR}/apue.h
	${CC} $<  ${C_FLAGS} ${LINK_FLAGS} -o $@
clean:
	rm -rf *.elf *.o
