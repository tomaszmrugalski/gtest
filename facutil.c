#include <exception>

// Nice way of handling bad situations in C++ is exceptions.
// See https://en.cppreference.com/w/cpp/error/exception
// for a list of standard exceptions. It's also very easy to define
// your own exceptions.
#include <stdexcept>

int fac(int n) {
    if (n < 0)
        throw std::out_of_range("Negative value");
    if (n > 999)
        throw std::overflow_error("Man! that's too large");
    if (n<2)
        return 2;
    return n*fac(n-1);
}

int sum(int a, int b) {
    return a + b;
}
