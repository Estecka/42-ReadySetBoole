
all: multiplier.out

multiplier.out: multiplier.cpp main.cpp ../logutil.a
	clang++ main.cpp multiplier.cpp ../logutil/logutil.a -o multiplier.out -Wall -Wextra

../logutil.a: lib
	make logutil.a -C ../logutil

clean:
	rm -f multiplier

re: clean all

.PHONY: all clean re lib
