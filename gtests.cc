#include <stdexcept>

#include "gtest/gtest.h"

#include "calc.h"


TEST(math, add) {
    EXPECT_EQ(5, sum(2,3));
}

TEST(factorial, simple) {
    EXPECT_EQ(120, fac(5));
}

TEST(factorial, negative) {
    EXPECT_NO_THROW(fac(5));

    EXPECT_THROW(fac(-5), std::out_of_range);
    EXPECT_THROW(fac(1000), std::out_of_range);
}
