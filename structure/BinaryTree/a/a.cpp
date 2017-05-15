#include <stdio.h>
#include <stdlib.h>



typedef struct Node
{
	int value;
	int left;
	int right;
}Node;

void traversal(int index);


Node *tree = NULL;
int main(void)
{
	int N = 0;
	tree1 = (Node *)malloc(sizeof(Node) * 10);

	scanf("%d\n", &N);
	for(int n = 0; n < N; ++n)
	{
		int value = 0, left = 0, right = 0;
		scanf("%c %d %d\n", &value, &left, &right);

		tree1[n].value = value;
		tree1[n].left = (left == '-'? -1: left);
		tree1[n].right = (right == '-'? -2: right);
	}

	for(int n = 0; n < N; ++n)
	{
		printf("%c %d %d\n", tree[n].value, tree[n].left, tree[n].right);
	}
	traversal(0);

	return 0;
}


void traversal(int index)
{
	if(index == -1)
		return;
	printf("%c\n", tree[index].value);	
	traversal(tree[index].left);
	traversal(tree[index].right);
}

