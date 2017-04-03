CC:=cc
CFLAGS:=-g -O3

HEADERS=../mmx.h ../sse.h ../sse2.h

.PHONY: all clean
all: test-emul test-native

clean:
	rm -f munit.o test test-native-mmx.o test-native-sse.o test-native-sse2.o test-emul-mmx.o test-emul-sse.o test-emul-sse2.o

munit.o: munit/munit.c munit/munit.h
	$(CC) $(CFLAGS) -c -o $@ $<

test-emul-mmx.o: test-mmx.c test.h ../mmx.h
	$(CC) $(CFLAGS) -c -o $@ $<

test-native-mmx.o: test-mmx.c test.h ../mmx.h
	$(CC) $(CFLAGS) -DTEST_NATIVE -c -o $@ $<

test-emul-sse.o: test-sse.c test.h ../sse.h
	$(CC) $(CFLAGS) -c -o $@ $<

test-native-sse.o: test-sse.c test.h ../sse.h
	$(CC) $(CFLAGS) -DTEST_NATIVE -c -o $@ $<

test-emul-sse2.o: test-sse2.c test.h ../sse2.h
	$(CC) $(CFLAGS) -c -o $@ $<

test-native-sse2.o: test-sse2.c test.h ../sse2.h
	$(CC) $(CFLAGS) -DTEST_NATIVE -c -o $@ $<

test: test-native test-emul
	./test-native && ./test-emul

test-native: munit.o test.c test-native-mmx.o test-native-sse.o test-native-sse2.o
	$(CC) $(CFLAGS) -DTEST_NATIVE -o $@ $^

test-emul: munit.o test.c test-emul-mmx.o test-emul-sse.o test-emul-sse2.o
	$(CC) $(CFLAGS) -o $@ $^
