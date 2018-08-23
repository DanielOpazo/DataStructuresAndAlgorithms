#include <stdio.h>
#include <string.h>
#include "strings.h"
#include "test.h"

tTestResult testReverseEmptyString(void) {
	tTestResult result;
	char str[] = "";
	reverseStringNoSpecialChars(str);
	result = (strcmp(str, "") == 0) ? PASS : FAIL;
	printf("testReverseEmptyString: %s\n", (result == PASS) ? PASS_STR : FAIL_STR);
	return result;
}

tTestResult testReverseOneCharString(void) {
	tTestResult result;
	char str[] = "a";
	reverseStringNoSpecialChars(str);
	result = (strcmp(str, "a") == 0) ? PASS : FAIL;
	printf("testReverseOneCharString: %s\n", (result == PASS) ? PASS_STR : FAIL_STR);
	return result;
}

tTestResult testReverseNoSpecialChars(void) {
	tTestResult result;
	char str[] = "abcde";
	reverseStringNoSpecialChars(str);
	result = (strcmp(str, "edcba") == 0) ? PASS : FAIL;
	printf("testReverseNoSpecialChars: %s\n", (result == PASS) ? PASS_STR : FAIL_STR);
	return result;
}

tTestResult testReverseAllSpecialChars(void) {
	tTestResult result;
	char str[] = "*?()^^%";
	reverseStringNoSpecialChars(str);
	result = (strcmp(str, "*?()^^%") == 0) ? PASS : FAIL;
	printf("testReverseAllSpecialChars: %s\n", (result == PASS) ? PASS_STR : FAIL_STR);
	return result;
}

tTestResult testReverseMixedCharsEven(void) {
	tTestResult result;
	char str[] = "ab*d?(f)^ghi^%";
	reverseStringNoSpecialChars(str);
	result = (strcmp(str, "ih*g?(f)^dba^%") == 0) ? PASS : FAIL;
	printf("testReverseMixedCharsEven: %s\n", (result == PASS) ? PASS_STR : FAIL_STR);
	return result;
}

tTestResult testReverseMixedCharsOdd(void) {
	tTestResult result;
	char str[] = "ab*d?()^ghi^%";
	reverseStringNoSpecialChars(str);
	result = (strcmp(str, "ih*g?()^dba^%") == 0) ? PASS : FAIL;
	printf("testReverseMixedCharsOdd: %s\n", (result == PASS) ? PASS_STR : FAIL_STR);
	return result;
}

void testReverseStringNoSpecialChars(void) {
	tTestResult result = PASS;
	result |= testReverseEmptyString();
	result |= testReverseOneCharString();
	result |= 	testReverseNoSpecialChars();
	result |= 	testReverseAllSpecialChars();
	result |= 	testReverseMixedCharsEven();
	result |= 	testReverseMixedCharsOdd();
	printf("testReverseStringNoSpecialChars Result: %s\n", (result == PASS) ? PASS_STR : FAIL_STR);
}
