.PHONY:clean
CC=gcc
DEBUG=1
ifeq ($(DEBUG),1)
C_FLAGS=-g -fPIC -c
else
C_FLAGS=-fPIC -c
endif
LIB_OBJS=../obj/error.o  ../obj/lockfile.o ../obj/init.o ../obj/single.o ../obj/setfl.o ../obj/clrfl.elf ../obj/tellwait.o ../obj/prmask.o ../obj/lockreg.o ../obj/setfd.o

../obj/libapue.so:${LIB_OBJS}
	${CC} -shared $^ -o $@
../obj/error.o:error.c
	${CC} ${C_FLAGS} $< -o $@
../obj/lockfile.o:lockfile.c
	${CC} ${C_FLAGS} $< -o $@
../obj/init.o:init.c
	${CC} ${C_FLAGS} $< -o $@
../obj/single.o:single.c
	${CC} ${C_FLAGS} $< -o $@
../obj/setfl.o:setfl.c
	${CC} ${C_FLAGS} $< -o $@
../obj/clrfl.elf:clrfl.c
	${CC} ${C_FLAGS} $< -o $@
../obj/tellwait.o:tellwait.c
	${CC} ${C_FLAGS} $< -o $@
../obj/prmask.o:prmask.c
	${CC} ${C_FLAGS} $< -o $@
../obj/lockreg.o:lockreg.c
	${CC} ${C_FLAGS} $< -o $@
../obj/setfd.o:setfd.c
	${CC} ${C_FLAGS} $< -o $@
all:../obj/libapue.so
	@echo "makeing all"
clean:
	rm -rf ../obj/*.o ../obj/*.so
