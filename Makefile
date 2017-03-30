CC:=cc
CFLAGS:=-Wall -Wextra -Wno-strict-aliasing -g -O3

HEADERS=mmx.h sse.h sse2.h sse3.h

.PHONY: all clean
all: test-emul test-native

clean:
	rm -f munit.o test

munit.o: munit/munit.c munit/munit.h
	$(CC) -c -o $@ $<

test: test-native test-emul
	./test-native && ./test-emul

test-native: munit.o test.c $(HEADERS)
	$(CC) $(CFLAGS) -DTEST_NATIVE -o $@ munit.o test.c

test-emul: munit.o test.c $(HEADERS)
	$(CC) $(CFLAGS) -o $@ munit.o test.c
