DEP = main.o  \
	gray_code.o \
	../logutil/logutil.a \

NAME = gray_code.out
CXX = clang++
CPPFLAGS = -Wall -Wextra


all: ${NAME}

${NAME}: ${DEP}
	${CXX} ${DEP} -o ${NAME} ${CPPFLAGS}


%.a: lib
	make $(@F) -C $(@D)


clean:
	rm -f *.o
	rm -f *.out

re: clean all

.PHONY: all clean re lib
