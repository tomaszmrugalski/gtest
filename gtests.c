#include "gtest/gtest.h"

#include "facutil.h"

extern int sum(int, int);

TEST(MathTest, add) {
  EXPECT_EQ(5, sum(2,3));

}
