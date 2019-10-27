#include <stdio.h>

#include "calc.h"

int main(int argc, const char* argv[]) {

    for (int i = 1; i < 10; i++) {
        printf("%d! = %d\n", i, fac(i));
    }

    return 0;
}
