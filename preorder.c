
#include"Stack.h"

void PreorderLoop(BNode *root)
{
	Stack stack;
	StackInit(&stack);
	BNode *node = root;
	BNode*top;

	while (node!=NULL || !StackEmpty(&stack)){
		while (node != NULL)
		{
			printf("%d ", node->data);
			StackPush(&stack, node); //压栈,压的是结点地址
			node = node->left;
		}

		top = StackTop(&stack); StackPop(&stack);
		node = top->right;
	}
}

