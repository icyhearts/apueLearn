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
${BIN}/self2_sighup.elf:self2_sighup.c ${MYLIB_INC_DIR}/apue.h
	${CC} $<  ${C_FLAGS} ${LINK_FLAGS} -o $@
${BIN}/self3_reread.elf:self3_reread.c ${MYLIB_INC_DIR}/apue.h
	${CC} $<  ${C_FLAGS} ${LINK_FLAGS} -o $@
${BIN}/self4_testDaemon.elf:self4_testDaemon.c ${MYLIB_INC_DIR}/apue.h
	${CC} $<  ${C_FLAGS} ${LINK_FLAGS} -o $@
${BIN}/c13n1_daemonize.elf:c13n1_daemonize.c ${MYLIB_INC_DIR}/apue.h
	${CC} $<  ${C_FLAGS} ${LINK_FLAGS} -o $@
${BIN}/c13n2_fig13.7_rereade.elf:c13n2_fig13.7_rereade.c ${MYLIB_INC_DIR}/apue.h
	${CC} $<  ${C_FLAGS} ${LINK_FLAGS} -o $@
${BIN}/c13n3_myreread.elf:c13n3_myreread.c ${MYLIB_INC_DIR}/apue.h
	${CC} $<  ${C_FLAGS} ${LINK_FLAGS} -o $@

${BIN}/c13n4_fig13.8_reread2.elf:c13n4_fig13.8_reread2.c ${MYLIB_INC_DIR}/apue.h
	${CC} $<  ${C_FLAGS} ${LINK_FLAGS} -o $@
clean:
	rm -rf *.elf *.o bin/*.elf
