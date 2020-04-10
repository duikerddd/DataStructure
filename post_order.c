void PostorderLoop(BNode *root)
{
	Stack stack;
	StackInit(&stack);
	BNode *node = root;
	BNode *top;
	BNode *last = NULL;

	while (node != NULL || !StackEmpty(&stack)){
		while (node != NULL)
		{
			StackPush(&stack, node); //压栈,压的是结点地址
			node = node->left;
		}

		top = StackTop(&stack);
		if (top->right == NULL || top->right == last)
		{
			printf("%d ", top->data);
			last = top;
			StackPop(&stack);
		}
		else{
			node = top->right;
		}
	}
}
