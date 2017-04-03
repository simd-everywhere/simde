CC:=cc
CFLAGS:=-g -O3

HEADERS=mmx.h sse.h sse2.h

.PHONY: all clean
all: test-emul test-native

clean:
	rm -f munit.o test/test

munit.o: test/munit/munit.c test/munit/munit.h
	$(CC) -c -o $@ $<

test: test-native test-emul
	./test-native && ./test-emul

test-native: munit.o test/test.c $(HEADERS)
	$(CC) $(CFLAGS) -DTEST_NATIVE -o $@ munit.o test/test.c test/test-mmx.c test/test-sse.c test/test-sse2.c

test-emul: munit.o test/test.c $(HEADERS)
	$(CC) $(CFLAGS) -o $@ munit.o test/test.c test/test-mmx.c test/test-sse.c test/test-sse2.c
