CC:=cc
CFLAGS:=-Wall -Wextra -g -O3

HEADERS=sse.h mmx.h

.PHONY: all clean
all: test-emul test-native

clean:
	rm -f munit.o test

munit.o: munit/munit.c munit/munit.h
	$(CC) -c -o $@ $<

test: test-native test-emul
	./test-native
	./test-emul

test-native: munit.o test.c $(HEADERS)
	$(CC) -DTEST_NATIVE -o $@ munit.o test.c

test-emul: munit.o test.c $(HEADERS)
	$(CC) -o $@ munit.o test.c
