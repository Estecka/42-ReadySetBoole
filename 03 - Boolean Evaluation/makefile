DEP = main.o  \
	../logutil/logutil.a \

HDRS = \
	eval_expr.hpp \
	InvalidExprException.hpp \
	InvalidTreeException.hpp \
	IPolishItem.hpp \
	PolishBool.hpp \
	PolishNode.hpp \

NAME = eval_formula.out
CXX = clang++
CPPFLAGS = -Wall -Wextra


all: headers_test ${NAME}

${NAME}: ${DEP}
	${CXX} ${DEP} -o ${NAME} ${CPPFLAGS}


%.a: lib
	make $(@F) -C $(@D)

headers_test: ${HDRS:.hpp=.hpp.o}
%.hpp.o: ${HDRS}
	${CXX} ${CPPFLAGS} ${@:.o=} -c -o $@
%.hpp:

clean:
	rm -f *.o
	rm -f *.out

re: clean all

.PHONY: all clean re lib headers_test
