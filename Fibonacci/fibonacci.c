#include <stdio.h>
#include <string.h>

#define UNKNOWN 0

int fibonacci(int n) {
    if (n == 0)
        return 0;
    else if (n == 1)
        return 1;
    else
        return fibonacci(n-2) + fibonacci(n-1);
}

//I could just put 0 and 1 in memo to start,
//and have -1 or something for UNKNOWN
long long unsigned int fib_memo(int n, long long unsigned int * memo) {
	if (n == 0)
		return 0;
	else if (n == 1)
		return 1;
	else {
		if (*(memo+n) != UNKNOWN)
			return *(memo+n);
		else {
			long long unsigned int fib_num = fib_memo(n-2, memo) + fib_memo(n-1, memo);
			*(memo+n) = fib_num;
			return fib_num;
		}
	}
}

long long unsigned int fibonacci_memo(int n) {
	long long unsigned int memo[n+1];
	memset(memo, UNKNOWN, sizeof(memo));
	return fib_memo(n, memo);
}
