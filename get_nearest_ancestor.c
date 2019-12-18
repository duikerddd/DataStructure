//最近祖先
//递归回溯
//1.判断两个结点是否在两侧,两侧最近为当前root,同一侧肯定还是最远公共节点
//2.在同一侧,就继续深度递归遍历,直到两个结点在某个root的两侧
BNode *GetNearestAncestor(BNode *root, BNode *n1, BNode *n2)
{
	BNode *n1InLeft= Search(root->left, n1->data);
	BNode *n2InLeft = Search(root->left, n2->data);

  //一个左子树,一个右子树,最近公共祖先为当前root
	if (n1InLeft && !n2InLeft)
	{
		return root;
	}
	if (!n1InLeft && n2InLeft)
	{
		return root;
	}

  //深度优先遍历
	if (n1InLeft)
	{
		return GetNearestAncestor(root->left, n1, n2);
	}
	else
	{
		return GetNearestAncestor(root->right, n1, n2);
	}

}
