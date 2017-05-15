#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void PreOrderTraversal(struct Node *node);
void invert(struct Node *node);
struct Node
{
	int num;
	struct Node *left;
	struct Node *right;
};


int main(void)
{
	int T = 0;
	struct Node *nodes = NULL, *root = NULL;
	nodes = (struct Node *)malloc(sizeof(struct Node) * 8192);
	
	scanf("%d", &T);
	for(int t = 0; t < T; ++t)
	{
		int N = 0, D = 0;
		scanf("%d %d", &N, &D);
		scanf("%d", &(nodes[1]).num);
		for(int d = 1; d < D; ++d)
		{
			for(int offset = 0; offset < pow(2, d - 1); ++offset) 
			{
				struct Node *node_F = &nodes[(int)pow(2, d - 1) + offset];
				struct Node *node_L = &nodes[(int)pow(2, d) + offset * 2];	
				struct Node *node_R = &nodes[(int)pow(2, d) + offset * 2 + 1];	
				(*node_F).left = node_L;
				(*node_F).right = node_R;
				scanf("%d %d", &(*node_L).num, &(*node_R).num);

			}
		}
	}
	
	invert(&nodes[1]);
	PreOrderTraversal(&nodes[1]);
	return 0;
}


void PreOrderTraversal(struct Node *node)
{
	printf("%d\n", (*node).num);
	if(node->left != NULL)
		PreOrderTraversal(node->left);
	if(node->right != NULL)
		PreOrderTraversal(node->right);

}

void invert(struct Node *node)
{
	struct Node *temp = node->left;
	node->left = node->right;
	node->right = temp;
	if(node->left != NULL)
		invert(node->left);
	if(node->right != NULL)
		invert(node->right);
}

