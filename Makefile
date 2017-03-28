CC:=cc
CFLAGS:=-Wall -Wextra -g -O3

.PHONY: all clean
all: test

clean:
	rm -f munit.o test

munit.o: munit/munit.c munit/munit.h
	$(CC) -c -o $@ $<

test: munit.o test.c
	$(CC) -o $@ $^
