/*
 * TestExpTree.c
 *
 *  Created on: 2018. 2. 1.
 *      Author: user
 */

#include "ExpTree.h"

int main(void) {

	EtNode* root = NULL;

	char postfixExpression[20] = "71*52-/";
	ET_buildExpressionTree(postfixExpression, &root);

	printf("pre order...\n");
	ET_preOrderPrintTree(root);
	printf("\n\n");

	printf("in order...\n");
	ET_inOrderPrintTree(root);
	printf("\n\n");

	printf("post order...\n");
	ET_postOrderPrintTree(root);
	printf("\n");

	printf("eval : %f\n", ET_evaluate(root));

	ET_destroyTree(root);

	return 0;
}
