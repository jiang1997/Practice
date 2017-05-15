#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
	int value;
	struct Node *left;
	struct Node *right;
}Node;

Node* InsertNode(Node *node, int num);
int LevelOrderTraversal(Node *node);

int main(void) {
	
	int N = 0;
	scanf("%d", &N);
	Node *root = malloc(sizeof(Node));
	scanf("%d", &root->value);
	while(--N)
	{
		int temp;
		scanf("%d", &temp);
		root = InsertNode(root, temp);
	}

	printf("%d", root->value);
	return 0;
}


//插入节点
Node* InsertNode(Node *node, int num)
{
	if(node == NULL)
	{
		Node *insNode = malloc(sizeof(Node));
		insNode->left = NULL;
		insNode->right = NULL;
		insNode->value = num;
		return insNode;
	}
	
	if(node->value > num)
	{
		node->left = InsertNode(node->left, num);
		Node *tmpNode = node->left;
		//detecte banance
		if(DepthOfTree(node->left) - DepthOfTree(node->right) > 1)
		{
			Node *badNode = NULL;
			if(num > node->left->value)	//LR Rotate
			{
				badNode = node->left->right;
				tmpNode->right = badNode->left;
				node->left = badNode->right;
				badNode->right = node;
				badNode->left = tmpNode;
				node = badNode;
			}
			else				//LL Rotate
			{
				node->left = tmpNode->right;
				tmpNode->right = node;
				node = tmpNode;
			}
		}
		return node;
	}
	if(node->value < num)
	{
		node->right = InsertNode(node->right, num);
		Node *tmpNode = node->right;
		//RL
		//detecte banance
		if(DepthOfTree(node->right) - DepthOfTree(node->left) > 1)
		{
			Node *badNode = NULL;
			if(num < node->right->value)	//RL Rotate
			{
				badNode = node->right->left;
				tmpNode->left = badNode->right;
				node->right = badNode->left;
				badNode->left = node;
				badNode->right = tmpNode;
				node = badNode;
			}
			else				//RR Rotate
			{
				node->right = tmpNode->left;
				tmpNode->left = node;
				node = tmpNode;
			}
		}
		//RR
		return node;
	}
}
//删除节点
int DelNode(Node *root, int value)
{
	
}

//层序遍历 堆栈实现
int LevelOrderTraversal(Node *node)
{
	struct Node **src = NULL, **dst = NULL, *temp = NULL;
	int TopSrc = 0, TopDst = 0, TopTmp = 0, LvlNum = 0;
	src = malloc(sizeof(struct Node *) * 1024);
	dst = malloc(sizeof(struct Node *) * 1024);
	src[TopSrc++] = node;

	while(TopSrc > 0)
	{
		++LvlNum;
		while(TopSrc > 0)
		{
			
			struct Node *node = src[--TopSrc];
			if(node == NULL)
				continue;
			dst[TopDst++] = node;
		}
		while(TopDst > 0)
		{
			
			struct Node *node = dst[--TopDst];
			if(node == NULL)
				continue;
			printf("%d ", node->value);
			src[TopSrc++] = node->left;
			src[TopSrc++] = node->right;
		}
		printf("\n");

	}
	return LvlNum - 1;
}

int DepthOfTree(Node *node)
{
	struct Node **src = NULL, **dst = NULL, *temp = NULL;
	int TopSrc = 0, TopDst = 0, TopTmp = 0, LvlNum = 0;
	src = malloc(sizeof(struct Node *) * 1024);
	dst = malloc(sizeof(struct Node *) * 1024);
	src[TopSrc++] = node;

	while(TopSrc > 0)
	{
		++LvlNum;
		while(TopSrc > 0)
		{
			
			struct Node *node = src[--TopSrc];
			if(node == NULL)
				continue;
			dst[TopDst++] = node;
		}
		while(TopDst > 0)
		{
			
			struct Node *node = dst[--TopDst];
			if(node == NULL)
				continue;
			src[TopSrc++] = node->left;
			src[TopSrc++] = node->right;
		}

	}
	return LvlNum - 1;
}

