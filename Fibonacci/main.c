#include <stdio.h>
#include "fibonacci.h"

int main(void) {
    //signed 32-bit overflows at fibonacci(47)
    int idx = 0;
	printf("Pure recursion way\n");
    for (idx = 0; idx < 47; idx++) {
        printf("fibonacci at %d is %d\n", idx, fibonacci(idx));
    }

	//unsigned 64-bit overflows at fibonacci(94)
	printf("Dynamic Programming way\n");
	for (idx = 0; idx < 94; idx++) {
		printf("fibonacci at %d is %llu\n", idx, fibonacci_memo(idx));
	}
}
