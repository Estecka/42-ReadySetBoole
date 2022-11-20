HDRS = \
	eval_set.hpp \
	bitstring.hpp \

SRCS = \
	eval_set.o \
	bitstring.o \

TEST_SRCS = main.o \

LIBS = \
	./eval_set.a \
	../logutil/logutil.a \
	../polishtree/polishtree.a \

NAME =  eval_set.a
TEST =  eval_set.out
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
