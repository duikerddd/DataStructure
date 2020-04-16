void InorderLoop(BNode *root)
{
	Stack stack;
	StackInit(&stack);
	BNode *node = root;
	BNode*top;

	while (node != NULL || !StackEmpty(&stack)){
		while (node != NULL)
		{	
			StackPush(&stack, node); //压栈,压的是结点地址
			node = node->left;
		}

		top = StackTop(&stack); StackPop(&stack);
		printf("%d ", top->data);
		node = top->right;
	}
}




