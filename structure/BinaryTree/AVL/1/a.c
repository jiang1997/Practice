#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
	int value;
	struct Node *left;
	struct Node *right;
}Node;

int BF(Node *node);

int main(void)
{
	return 0;
}

int InsertNode()
{
}

int DeleteNode()
{
}

//level order traversal
//use 2 stacks
int LevelOrderTraversal(Node *node)
{
	Node **src = NULL, **dst = NULL, *temp = NULL;
	int TopSrc = 0, TopDst = 0, TopTmp = 0, LvlNum = 0;
	src = malloc(sizeof(Node *) * 1024);
	dst = malloc(sizeof(Node *) * 1024);
	src[TopSrc++] = node;
	while(TopSrc > 0)
	{
		++LvlNum;
		while(TopSrc > 0)
		{
			Node *node == src[--TopSrc];
			if(node = NULL)
				continue;
			dst[TopDst++] = node->left;
			dst[TopDst++] = node->right;
		}
		TopTmp = TopSrc;
		TopSrc = TopDst;
		TopDst = TopTmp;
		temp = src;
		src = dst;
		dst = temp;
	}
	return LvlNum - 1;
}

int BF(Node *node)
{
	return LevelOrderTraversal(node->left) - LevelOrderTraversal(node->right);
}

