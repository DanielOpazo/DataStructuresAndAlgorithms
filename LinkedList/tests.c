#include <stdio.h>
#include "tests.h"
#include "LinkedList.h"

/* all these tests rely on push so they aren't really true unit tests,
 * but push is a utility function for linked lists, and is
 * necessary to construct lists
 */

tUnitTestResult test_count_emptyList() {
	struct node* head = NULL;
	int result = count(head);
	destroyList(&head);
	CHECK_RESULT(result == 0);
}

tUnitTestResult test_count_oneItem() {
	struct node* head = NULL;
	push(&head, 1);
	int result = count(head);
	destroyList(&head);
	CHECK_RESULT(result == 1);
}

tUnitTestResult test_count_manyItems() {
	struct node* head = NULL;
	const int numElems = 1000;
	for (int i = 0; i < numElems; i++) {
		push(&head, i);
	}
	int result = count(head);
	destroyList(&head);
	CHECK_RESULT(result == numElems);
}

void test_count(void) {
	printf("\nRUNNING test_count\n");
	tUnitTestResult result = PASS;
	tUnitTestResult lastTest;

	RUN_TEST(test_count_emptyList);
	RUN_TEST(test_count_oneItem);
	RUN_TEST(test_count_manyItems);

	printf("TEST test_count %s\n", result == PASS ? PASS_STR : FAIL_STR);	
}

tUnitTestResult test_pop_oneItem(void) {
	struct node* head = NULL;
	push(&head, 5);
	int val = pop(&head);
	destroyList(&head);
	CHECK_RESULT(val == 5);
}

tUnitTestResult test_pop_fiveItems(void) {
	struct node* head = NULL;
	for (int idx = 1; idx < 6; idx++) {
		push(&head, idx);
	}
	tUnitTestResult result = PASS;
	for (int idx = 5; idx > 0; idx--) {
		result |= (pop(&head) == idx) ? PASS : FAIL;
	}
	destroyList(&head);
	CHECK_RESULT(result == PASS);
}

void test_pop(void) {
	printf("\nRUNNING test_pop\n");
	tUnitTestResult result = PASS;
	tUnitTestResult lastTest;

	//can't unit test empty list because I put an assert in there
	RUN_TEST(test_pop_oneItem);
	RUN_TEST(test_pop_fiveItems);

	printf("TEST test_pop %s\n", result == PASS ? PASS_STR : FAIL_STR);
}

void test_reverse(void) {
	struct node* head = NULL;
	for (int idx = 0; idx < 5; idx++) {
		push(&head, idx);
	}
	printf("\nList before reversing\n");
	printList(head);
	reverseList(&head);
	printf("List after reversing\n");
	printList(head);
	destroyList(&head);
}
