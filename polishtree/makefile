HDRS = \
	InvalidExprException.hpp \
	InvalidTreeException.hpp \
	IPolishItem.hpp \
	PolishBool.hpp \
	PolishNode.hpp \
	TreeBuilder.hpp \

SRCS = \
	InvalidExprException.o \
	InvalidTreeException.o \
	PolishBool.o \
	PolishNode.o \
	PolishNot.o \
	TreeBuilder.o \

NAME = polishtree.a
CXX = clang++
CPPFLAGS = -Wall -Wextra


all: headers_test ${NAME} ${TEST}

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
