HDRS = \
	eval_formula.hpp \

SRCS = \
	eval_formula.o \

TEST_SRCS = main.o \

LIBS = \
	./eval_formula.a \
	../logutil/logutil.a \
	../polishtree/polishtree.a \

NAME =  eval_formula.a
TEST =  eval_formula.out
CXX = clang++
CPPFLAGS = -Wall -Wextra


all: headers_test ${NAME} ${TEST}

${TEST}: ${LIBS} ${TEST_SRCS}
	${CXX} ${TEST_SRCS} ${LIBS} -o ${TEST} ${CPPFLAGS}

${NAME}: ${HDRS} ${SRCS}
	ar rcs ${NAME} ${SRCS}

%.a: lib
	make $(@F) -C $(@D)

headers_test: ${HDRS:.hpp=.hpp.o}
%.hpp.o: ${HDRS}
	${CXX} ${CPPFLAGS} ${@:.o=} -c -o $@
%.hpp:

clean:
	rm -f *.o
	rm -f *.a
	rm -f *.out

re: clean all

.PHONY: all clean re lib headers_test
