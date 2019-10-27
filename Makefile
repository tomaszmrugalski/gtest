all: fac tests

CUNIT_PATH=/home/student/lab3/cunit
GTEST_PATH=/home/student/lab4/gtest

facutil.o: facutil.c facutil.h
	$(CC) -c facutil.c -o facutil.o

fac:	fac.c facutil.o
	$(CC) fac.c facutil.o -o fac

clean:
	rm -f fac facutil

ctests: tests.c facutil.c facutil.h
	$(CC) facutil.c tests.c -o ctests \
            -I$(CUNIT_DIR)/include \
            -lcunit -L$(CUNIT_DIR)/lib

gtests:	facutil.c facutil.h libgtest.a gtests.c
	$(CXX) facutil.c gtests.c libgtest.a -o gtests -I$(GTEST_DIR) -pthread

libgtest.a: $(GTEST_DIR)/src/gtest-all.cc ${GTEST_DIR}/src/gtest_main.cc
	g++ -isystem ${GTEST_DIR}/include -I${GTEST_DIR} \
	        -pthread -c ${GTEST_DIR}/src/gtest-all.cc ${GTEST_DIR}/src/gtest_main.cc
	ar -rv libgtest.a gtest-all.o gtest_main.o


check: ctests gtests
	LD_LIBRARY_PATH=$(CUNIT_PATH)/lib ./tests
