HDRS = \
	PolishLookup.hpp \

SRCS = \
	PolishLookup.o \
	CreateLookup.o \

TEST_SRCS = \
	main.o
	

NAME = polishlookup.a
TEST = polishlookup.out
CXX = clang++
CPPFLAGS = -Wall -Wextra


all: headers_test ${NAME} ${TEST}

${TEST}: ${TEST_SRCS} ${HDRS} ${NAME} ${LIBS}
	${CXX} ${TEST_SRCS} ${NAME} ${LIBS} -o ${TEST} ${CPPFLAGS}

${NAME}: ${SRCS}
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
