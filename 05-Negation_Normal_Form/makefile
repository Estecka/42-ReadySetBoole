HDRS = \
	negation_normal_form.hpp \

SRCS = main.o \
	negation_normal_form.o \

LIBS = \
	../04-Truth_Table/truth_table.a \
	../03-Boolean_Evaluation/eval_formula.a \
	../logutil/logutil.a \
	../polishtree/polishtree.a \

NAME =  negation_normal_form.out
CXX = clang++
CPPFLAGS = -Wall -Wextra


all: headers_test ${NAME} ${TEST}

${NAME}: ${LIBS} ${SRCS}
	${CXX} ${SRCS} ${LIBS} -o ${NAME} ${CPPFLAGS}

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
