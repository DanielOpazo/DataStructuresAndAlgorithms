#include <assert.h>
#include <stdio.h>
#include "tests.h"
#include "LinkedList.h"


tUnitTestResult test_count_emptyList() {
	struct node* head = NULL;
	//return (count(head) == 0) ? PASS : FAIL
	CHECK_RESULT(count(head) == 0);
	destroyList(&head);
}

tUnitTestResult test_count_oneItem() {
	struct node* head = NULL;
	push(&head, 1);
	CHECK_RESULT(count(head) == 1);
	destroyList(&head);
}

tUnitTestResult test_count_manyItems() {
	struct node* head = NULL;
	int numElems = 1000;
	for (int i = 0; i < numElems; i++) {
		push(&head, i);
	}
	CHECK_RESULT(count(head) == numElems);
	destroyList(&head);
}

/* test_count relies on push so not a true unit test,
 * but push is a utility function for linked lists, and is
 * necessary to construct lists
 */
void test_count(void) {
	printf("RUNNING test_count\n");
	tUnitTestResult result = PASS;
	tUnitTestResult lastTest;

	RUN_TEST(test_count_emptyList);
	RUN_TEST(test_count_oneItem);
	RUN_TEST(test_count_manyItems);

	//result |= test_count_oneItem();
	//result |= test_count_manyItems();
	if (result != PASS) {
		printf("TEST test_count FAILED\n\n");
	}
	else {
		printf("TEST test_count PASSED\n\n");
	}
}
