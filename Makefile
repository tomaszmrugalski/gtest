all: fac tests

CUNIT_PATH=/home/student/lab3/cunit
GTEST_PATH=/home/student/lab4/gtest

facutil.o: facutil.c facutil.h
	$(CC) -c facutil.c -o facutil.o

fac:	fac.c facutil.o
	$(CC) fac.c facutil.o -o fac

clean:
	rm -f fac facutil

tests: tests.c facutil.c facutil.h
	$(CC) facutil.c tests.c -o tests \
            -I$(CUNIT_PATH)/include \
            -lcunit -L$(CUNIT_PATH)/lib

check: tests
	LD_LIBRARY_PATH=$(CUNIT_PATH)/lib ./tests

