#include <stdexcept>

#include "gtest/gtest.h"

#include "facutil.h"

extern int sum(int, int);

TEST(MathTest, add) {
    EXPECT_EQ(5, sum(2,3));
}

TEST(Factorial, basic) {
    EXPECT_NO_THROW(fac(5));

    EXPECT_THROW(fac(-5), std::out_of_range);
    EXPECT_THROW(fac(1000), std::out_of_range);
}

