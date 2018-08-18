#include <stdio.h>
#include "BinaryTree.h"
#include "test.h"

int main(void) {
	testPrintTreeInOrder();
	testPrintTreePostOrder();
	testLookupBST();
	testSize();
	testMaxDepth();
	testHasPathSum();
}
