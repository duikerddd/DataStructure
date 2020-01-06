void Preorder(BNode *root)
{
	//终止条件
	if (root == NULL)
	{
		return;
	}

	//根
	printf("%d ", root->data);
	//左子树,子问题用递归处理
	Preorder(root->left);
	//右子树,子问题用递归处理
	Preorder(root->right);
}

void Inorder(BNode *root)
{
	//终止条件
	if (root == NULL)
	{
		return;
	}

	//左子树,子问题用递归处理
	Inorder(root->left);
	//根
	printf("%d ", root->data);
	//右子树,子问题用递归处理
	Inorder(root->right);
}

void Postorder(BNode *root)
{
	//终止条件
	if (root == NULL)
	{
		return;
	}

	//左子树,子问题用递归处理
	Postorder(root->left);
	//右子树,子问题用递归处理
	Postorder(root->right);
	//根
	printf("%d ", root->data);
}
