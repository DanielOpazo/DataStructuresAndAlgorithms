#include <stdio.h>
#define SUCCESS 0
#define success_str "SUCCESS"
#define FAIL 1
#define fail_str "FAIL"

typedef unsigned char tTestResult;
struct node* generateBST();

tTestResult testLookupBST(void);	
tTestResult testSize(void);
tTestResult testMaxDepth(void);
