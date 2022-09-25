DEP = main.o  \
	adder.o \
	../logutil/logutil.a \

NAME = adder.out
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
