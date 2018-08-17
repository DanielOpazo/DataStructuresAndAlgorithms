#include <stdio.h>
#include "test.h"
#include "BinaryTree.h"

/*
 * Generates this tree
 *				5
 *			3		9
 *		 1     4  6
 *		  2        7
*/
struct node* generateBST() {
	struct node* root = insertBST(NULL, 5);
	insertBST(root, 3);
	insertBST(root, 9);
	insertBST(root, 1);
	insertBST(root, 4);
	insertBST(root, 2);
	insertBST(root, 6);
	insertBST(root, 7);
	return root;
}

tTestResult testLookupBSTEmptyTree(void) {
		printf("\ttest: testLookupBSTEmptyTree: ");
		tTestResult result = FAIL;
		struct node* root = NULL;
		if (lookupBST(root, 0) == FALSE) {
			result = SUCCESS;
		}
		printf("%s\n", (result == SUCCESS) ? success_str : fail_str);
		return result;
}

tTestResult testLookupBSTPopulatedTree(void) {
	printf("\ttest: testLookupBSTPopulatedTree: ");
	tTestResult result = SUCCESS;
	struct node* root = generateBST();
	for (int target = 1; target < 8; target++) {
		if (lookupBST(root, target) == FALSE) {
			result == FAIL;
		}
	}
	printf("%s\n", (result == SUCCESS) ? success_str : fail_str);
	return result;
}

tTestResult testLookupBST(void) {
	printf("\nRunning test: testLookupBST\n");
	tTestResult result = SUCCESS;
	result |= testLookupBSTEmptyTree();
	result |= testLookupBSTPopulatedTree();
	printf("testLookupBST %s\n", (result == SUCCESS) ? success_str : fail_str);
}

tTestResult testSizeEmptyTree(void) {
	printf("\ttest: testSizeEmptyTree: ");
	tTestResult result = FAIL;
	struct node* root = NULL;
	if (size(root) == 0) {
		result = SUCCESS;
	}
	printf("%s\n", (result == SUCCESS) ? success_str : fail_str);
	return result;
}

tTestResult testSizeOneElement(void) {
	printf("\ttest: testSizeOneElement: ");
	tTestResult result = FAIL;
	struct node* root = newNode(1);
	if (size(root) == 1) {
		result = SUCCESS;
	}
	printf("%s\n", (result == SUCCESS) ? success_str : fail_str);
	return result;
}

tTestResult testSizeManyElements(void) {
	printf("\ttest: testSizeManyElements: ");
	tTestResult result = FAIL;
	struct node* root = generateBST();
	if (size(root) == 8) {
		result = SUCCESS;
	}
	printf("%s\n", (result == SUCCESS) ? success_str : fail_str);
	return result;
}

tTestResult testSize(void) {
	printf("\nRunning test: testSize\n");
	tTestResult result = SUCCESS;
	result |= testSizeEmptyTree();
	result |= testSizeOneElement();
	result |= testSizeManyElements();
	printf("testSize %s\n", (result == SUCCESS) ? success_str : fail_str);
}

tTestResult testMaxDepthEmptyTree(void) {
	printf("\ttest: testMaxDepthEmptyTree: ");
	tTestResult result = FAIL;
	struct node* root = NULL;
	if (maxDepth(root) == 0) {
		result = SUCCESS;
	}
	printf("%s\n", (result == SUCCESS) ? success_str : fail_str);
	return result;
}

tTestResult  testMaxDepthOneElement(void) {
	printf("\ttest:  testMaxDepthOneElement: ");
	tTestResult result = FAIL;
	struct node* root = newNode(1);
	if (maxDepth(root) == 1) {
		result = SUCCESS;
	}
	printf("%s\n", (result == SUCCESS) ? success_str : fail_str);
	return result;
}

tTestResult testMaxDepthManyElements(void) {
	printf("\ttest: testMaxDepthManyElements: ");
	tTestResult result = FAIL;
	struct node* root = generateBST();
	if (maxDepth(root) == 4) {
		result = SUCCESS;
	}
	printf("%s\n", (result == SUCCESS) ? success_str : fail_str);
	return result;
}

tTestResult testMaxDepth(void) {
	printf("\nRunning test: testMaxDepth\n");
	tTestResult result = SUCCESS;
	result |= testMaxDepthEmptyTree();
	result |= testMaxDepthOneElement();
	result |= testMaxDepthManyElements();
	printf("testMaxDepth %s\n", (result == SUCCESS) ? success_str : fail_str);
}
