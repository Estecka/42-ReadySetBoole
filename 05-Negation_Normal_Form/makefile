HDRS = \
	negation_normal_form.hpp \

SRCS = \
	negation_normal_form.o \

TEST_SRCS = main.o \

LIBS = \
	../04-Truth_Table/truth_table.a \
	../03-Boolean_Evaluation/eval_formula.a \
	../logutil/logutil.a \
	../polishtree/polishtree.a \

NAME =  negation_normal_form.a
TEST =  negation_normal_form.out
CXX = clang++
CPPFLAGS = -Wall -Wextra


all: headers_test ${NAME} ${TEST}

${TEST}: ${TEST_SRCS} ${HDRS} ${NAME} ${LIBS}
	${CXX} ${TEST_SRCS} ${NAME} ${LIBS} -o ${TEST} ${CPPFLAGS}

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
