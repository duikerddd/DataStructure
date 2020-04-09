int IsBlance(BNode *root)
{
	if (root == NULL)
	{
		return 1;
	}

	int isBlance = IsBlance(root->left);
	if (isBlance == 0)
	{
		return 0;
	}

	isBlance = IsBlance(root->right);
	if (isBlance == 0)
	{
		return 0;
	}

	int leftHeight = GetHeight(root->left);
	int rightHeight = GetHeight(root->right);
	int diff = leftHeight - rightHeight;
	if (diff<-1 || diff>1)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}

int IsBalance2(BNode *root, int *pHeight)
{
	if (root == NULL)
	{
		//return 高度值
		*pHeight = 0;
		return 1;
	}

	int leftHeight;
	int rightHeight;
	int leftBalance = IsBalance2(root->left, &leftHeight);
	int rightBalance = IsBalance2(root->right, &rightHeight);
	//return 高度值
	*pHeight = MAX(leftHeight, rightHeight) + 1;

	if (leftBalance == 0 || rightBalance == 0)
	{
		return 0;
	}

	int diff = leftHeight - rightHeight;
	if (diff<-1 || diff>1)
	{
		return 0;
	}
	else
	{
		return 1;
	}

}

