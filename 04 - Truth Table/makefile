HDRS = \
	truth_table.hpp \

SRCS = main.o \
	truth_table.o \

LIBS = \
	../logutil/logutil.a \
	../polishtree/polishtree.a \

NAME =  truth_table.out
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
