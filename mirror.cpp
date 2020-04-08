void Mirror(BNode *root)
{
	if (root == NULL)
	{
		return;
	}
	BNode *t = root->left;
	root->left = root->right;
	root->right=t;

	Mirror(root->left);
	Mirror(root->right);
}
