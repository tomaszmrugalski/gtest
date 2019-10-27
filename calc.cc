// Nice way of handling bad situations in C++ is exceptions.
// See https://en.cppreference.com/w/cpp/error/exception
// for a list of standard exceptions. It's also very easy to define
// your own exceptions.
#include <exception>
#include <stdexcept>

/// @brief Calculates factorial (pl. silnia).
/// @param n
/// @return n!
int fac(int n) {
    if (n < 0)
        throw std::out_of_range("Negative value");
    if (n > 999)
        throw std::overflow_error("Man! that's too large");
    if (n<2)
        return 2;
    return n*fac(n-1);
}

/// @brief Adds two integers
/// @param a
/// @param b
/// @return sum of a + b
int sum(int a, int b) {
    return a + b;
}

// Task 1: Implement a function that will take two integers and will
// return the distance between them. The function is supposed to work
// for the whole integer range. If the distance is too large to be
// stored on int, maximum int value should be returned.
// Don't forget to update calc.cc and calc.h.

// Task 2: Implement unit-tests for that method.

// Task 3: Run all unit-tests.

// Task 4: Generate test report in XML or JSON.

// Task 5: Disable one test in the source code.

// Task 6: Run all unit-tests from Math test suite
