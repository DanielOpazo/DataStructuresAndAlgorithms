#include <stdio.h>
#include "test.h"
#include "BinaryTree.h"

//Note: None of these tests free any memory

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
			result = FAIL;
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
	return result;
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
	return result;
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

tTestResult testMaxDepthOneElement(void) {
	printf("\ttest: testMaxDepthOneElement: ");
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
	return result;
}

tTestResult testHasPathSumEmptyTree(void) {
	printf("\ttest: testHasPathSumEmptyTree: ");
	tTestResult result = FAIL;
	struct node* root = NULL;
	if (hasPathSum(root, 5) == FALSE) {
		result = SUCCESS;
	}
	printf("%s\n", (result == SUCCESS) ? success_str : fail_str);
	return result;
}

tTestResult testHasPathSumOneElement(void) {
	printf("\ttest: testHasPathSumOneElement: ");
	tTestResult result = FAIL;
	struct node* root = newNode(6);
	if (hasPathSum(root, 6) == TRUE) {
		result = SUCCESS;
	}
	printf("%s\n", (result == SUCCESS) ? success_str : fail_str);
	return result;
}

tTestResult testHasPathSumManyElements(void) {
	printf("\ttest: testHasPathSumManyElements: ");
	tTestResult result = SUCCESS;
	struct node* root = generateBST();
	if (hasPathSum(root, 11) == FALSE) {
		result = FAIL;
	}
	if (hasPathSum(root, 12) == FALSE) {
		result = FAIL;
	}
	if (hasPathSum(root, 27) == FALSE) {
		result = FAIL;
	}
	if (hasPathSum(root, 10) == TRUE) {
		result = FAIL;
	}
	if (hasPathSum(root, 0) == TRUE) {
		result = FAIL;
	}
	printf("%s\n", (result == SUCCESS) ? success_str : fail_str);
	return result;
}


tTestResult testHasPathSum(void) {
	printf("\nRunning test: testHasPathSum\n");
	tTestResult result = SUCCESS;
	result |= testHasPathSumEmptyTree();
	result |= testHasPathSumOneElement();
	result |= testHasPathSumManyElements();
	printf("testHasPathSum %s\n", (result == SUCCESS) ? success_str : fail_str);
	return result;
}

void testPrintTreeInOrder(void) {
	printf("\nRunning test: testPrintTreeInOrder\n");
	struct node* root = NULL;
	printf("print empty tree\n");
	printTreeInOrder(root);
	root = newNode(1);
	printf("print one element tree\n");
	printTreeInOrder(root);
	root = generateBST();
	printf("print many element tree\n");
	printTreeInOrder(root);
}

void testPrintTreePostOrder(void) {
	printf("\nRunning test: testPrintTreePostOrder\n");
	struct node* root = NULL;
	printf("print empty tree\n");
	printTreePostOrder(root);
	root = newNode(1);
	printf("print one element tree\n");
	printTreePostOrder(root);
	root = generateBST();
	printf("print many element tree\n");
	printTreePostOrder(root);
}
