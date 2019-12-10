


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//                                 二叉树问题思考方式 :                 1.递推公式:       2.终止条件:
//求结点个数
//终止条件: 
//1)空树 return 0
//2)叶子结点 return 1
//3)一个孩子为空
int GetSize(BNode *root)
{
	//终止条件
	if (root == NULL)
	{
		//空树
		return 0;
	}
	//递推
	return GetSize(root->left) +
		GetSize(root->right) + 1;
}

//求叶子结点个数
//空树 return 0
//只有一个结点的树 return 1
int GetLeafSize(BNode *root)
{
	if (root == NULL)
	{
		return 0;
	}
	else if (root->left == NULL && root->right == NULL)
	{
		return 1;
	}
	else
	{
		return GetLeafSize(root->left) +
			GetLeafSize(root->right) ;
	}
}

//求第k层结点个数
//1.递推
//    左+右
//    子问题在递推的过程需要
//    k-1
//2.终止条件
//    1)空树 return 0
//    2)k==1 return 1
int GetKLevelSize(BNode*root, int k)
{
	assert(k > 0);

	//位置不能交换 自己想为什么
	if (root == NULL)
	{
		return 0;
	}
	if (k == 1)
	{
		return 1;
	}

	return GetKLevelSize(root->left, k - 1) + 
		GetKLevelSize(root->right, k - 1);
}

//求二叉树的高度
//递推公式:
//         MAX(左,右)+1
//终止条件:
//         空树 return 0
#define MAX(a,b) ((a)>(b)?(a):(b))

int GetHeight(BNode *root)
{
	if (root == NULL)
	{
		return 0;
	}

	int leftHeight = GetHeight(root->left);
	int rightHeight = GetHeight(root->right);

	//注意下,不要多次调用
	return MAX(leftHeight, rightHeight) + 1;
}

//查找结点:
//      如果找到,返回结点地址
//      如果没有找到,返回NULL
//查找策略: 优先左
//       如果是空树,返回null
//       如果根命中,直接返回根的地址
//       先去左子树中找,如果找到了,返回结果
//       如果左子树也没有找到,再去右子树中找
BNode *Search(BNode *root, TDataType key)
{
	if (root == NULL)
	{
		return 0;
	}
	else if (root->data==key)
	{
		//如果根命中了
		return root;
	}

	BNode *node = Search(root->left, key);
	if (node!=NULL)
	{
		//左子树中找到了
		return node;
	}

	node = Search(root->right, key);
	if (node != NULL)
	{
		return node;
	}

	else
	{
		return NULL;
	}
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

