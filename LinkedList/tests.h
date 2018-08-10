/* my own really basic unit test framework.
 * This isn't the place to use a proper production level framework
 */

#define PASS 0
#define FAIL 1
#define PASS_STR "PASSED"
#define FAIL_STR "FAILED"
#define CHECK_RESULT(_condition) \
	return (_condition) ? PASS : FAIL; \

/* not a good macro for real code base because it relies on variable named lastTest, and result. I just have a lot of tests to write and want to save some typing
 */
#define RUN_TEST(_testName) \
	printf("TEST %s: ", #_testName);	\
	lastTest = (_testName)();	\
	printf("%s\n", (lastTest == PASS) ? "PASS" : "FAIL");	\
	result |= lastTest;	\

typedef int tUnitTestResult;
void test_count(void);
void test_pop(void);
void test_reverse(void);
