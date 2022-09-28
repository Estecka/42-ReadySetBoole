HDRS = \
	eval_expr.hpp \
	InvalidExprException.hpp \
	InvalidTreeException.hpp \
	IPolishItem.hpp \
	PolishBool.hpp \
	PolishNode.hpp \

SRCS = \
	eval_expr.o \
	InvalidExprException.o \
	InvalidTreeException.o \
	PolishBool.o \
	PolishNode.o \

LIBS = \
	../logutil/logutil.a \

NAME = eval_formula.a
TEST = eval_formula.out
CXX = clang++
CPPFLAGS = -Wall -Wextra


all: headers_test ${NAME} ${TEST}

${NAME}: ${SRCS}
	ar rcs ${NAME} ${SRCS}

${TEST}: ${NAME} ${LIB} main.o
	${CXX} main.o ${NAME} -o ${TEST} ${CPPFLAGS}

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
