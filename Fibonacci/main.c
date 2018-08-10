#include <stdio.h>
#include "fibonacci.h"

int main(void) {
    //signed 32-bit overflows at fibonacci(47)
    int idx = 0;
    for (idx = 0; idx < 50; idx++) {
        printf("fibonacci at %d is %d\n", idx, fibonacci(idx));
    }
}
