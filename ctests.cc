#include "calc.h"
#include <limits.h>

#include "CUnit/CUnit.h"
#include "CUnit/Basic.h"

void test_fac(void) {
  CU_ASSERT(fac(1) == 1);
  CU_ASSERT(fac(2) == 2);
}

void test_add(void) {
  CU_ASSERT(sum(3,2) == 5);
  CU_ASSERT(sum(-1,-1) == -2);


  // sum operates on ints, let's check boundary conditions
  CU_ASSERT(sum(INT_MAX - 1, 1) == INT_MAX);
  CU_ASSERT(sum(INT_MIN + 1, -1) == INT_MIN);

  CU_ASSERT(sum(INT_MAX, INT_MAX) == 2 * INT_MAX);

  CU_ASSERT(sum(2147483647, 1) == 2147483648);

  CU_ASSERT(sum(INT_MAX, 1) == INT_MAX + 1);
}

int main(int argc, const char* argv[]) {
  CU_ErrorCode result = CU_initialize_registry();
  if (result != CUE_SUCCESS) {
    printf("Failed to initalized registry\n");
    return -1;
  }

  CU_pSuite suite = CU_add_suite("math-suite", NULL, NULL);
  if (!suite) {
    printf("Failed to create a suite\n");
    return -2;
  }

  CU_pTest t = CU_add_test(suite, "fac", test_fac);
  t = CU_add_test(suite, "adding", test_add);
  if (!t) {
    printf("Failed to add a test to test suite\n");
    return -3;
  }

  CU_basic_run_tests();

  CU_cleanup_registry();

  
  printf("Run complete\n");
  return CU_get_error();
}
