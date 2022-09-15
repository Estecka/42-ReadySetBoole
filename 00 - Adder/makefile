
all: adder.out

adder.out: adder.cpp main.cpp ../logutil.a
	clang++ main.cpp adder.cpp ../logutil/logutil.a -o adder.out -Wall -Wextra

../logutil.a: lib
	make logutil.a -C ../logutil

clean:
	rm -f adder

re: clean all

.PHONY: all clean re lib
