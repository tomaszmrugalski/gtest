all: fac gtests ctests

CUNIT_DIR=/home/student/lab3/cunit
GTEST_DIR=/home/student/lab4/googletest-release-1.8.1/googletest

fac:	fac.c calc.cc
	$(CXX) fac.c calc.cc -o fac

clean:
	rm -f fac gtests ctests *.o *.a

ctests: ctests.cc calc.cc calc.h
	$(CXX) calc.cc ctests.cc -o ctests \
	    -I$(CUNIT_DIR)/include \
	    -lcunit -L$(CUNIT_DIR)/lib

gtests:	calc.cc calc.h libgtest.a gtests.cc
	$(CXX) calc.cc gtests.cc libgtest.a -o gtests -I$(GTEST_DIR)/include -pthread

libgtest.a: $(GTEST_DIR)/src/gtest-all.cc ${GTEST_DIR}/src/gtest_main.cc
	g++ -isystem -I${GTEST_DIR}/include -I${GTEST_DIR} \
		-pthread -c ${GTEST_DIR}/src/gtest-all.cc ${GTEST_DIR}/src/gtest_main.cc
	ar -rv libgtest.a gtest-all.o gtest_main.o


check: ctests gtests
	LD_LIBRARY_PATH=$(CUNIT_PATH)/lib ./tests
