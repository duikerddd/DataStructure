//前序: 前序遍历,每次拿根
//中序: 根据前序确定左右子树
//递归处理
BNode * ReCreatTree(TDataType preorder[], TDataType inorder[], int size)
{
	if (size <= 0)
	{
		return NULL;
	}

	TDataType rootValue = preorder[0];
	int i,r;
	for (i=0; i < size; i++)
	{
		if (inorder[i] == rootValue)
		{
			r = i;
			break;
		}
	}
	assert(i < size);

	BNode *root = CreatNode(rootValue);
	root->left = ReCreatTree(preorder + 1, inorder, r);
	root->right = ReCreatTree(preorder + 1 + r, inorder + r + 1, size - 1 - r);

	return root;
}
