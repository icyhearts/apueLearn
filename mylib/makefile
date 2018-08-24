.PHONY:clean
CC=gcc
DEBUG=1
ifeq ($(DEBUG),1)
C_FLAGS=-g -fPIC -c
else
C_FLAGS=-fPIC -c
endif
LIB_OBJS=../obj/error.o 

../obj/libapue.so:${LIB_OBJS}
	${CC} -shared -fPIC $^ -o $@
../obj/error.o:error.c
	${CC} ${C_FLAGS} $< -o $@
all:../obj/libapue.so
	@echo "makeing all"
clean:
	rm -rf ../obj/*.o ../obj/*.so
