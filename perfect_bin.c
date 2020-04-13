//判断二叉树是否是完全二叉树

//带空结点的层序遍历判断是否是完全二叉树
int IsComplete(BNode *root)
{
	Queue queue;
	QueueInit(&queue);
	if (root == NULL)
	{
		return 1;
	}

	QueuePush(&queue, root);
	while (!QueueEmpty(&queue))
	{
		BNode *front = QueueFront(&queue);
		QueuePop(&queue);

		if (front == NULL)
		{
			break;
		}
			QueuePush(&queue, front->left);
			QueuePush(&queue, front->right);
		
	}
	//发现空结点了
	//查看队列中是否完全是NULL
	while (!QueueEmpty(&queue))
	{
		BNode* node = QueueFront(&queue);
		QueuePop(&queue);
		if (node != NULL){
			return 0;
		}
	}

	QueueDestroy(&queue);
	return 1;
	
}
