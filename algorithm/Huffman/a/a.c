#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Node
{
	int num;
	int letter;
	struct Node *left;
	struct Node *right;
}Node;

int traversal(Node *node);

int main(void)
{
	int N = 0, M = 0, count = 0, c[256] = {0}, f[256] = {0};
	char str[256][256] = {0};
	Node **list = NULL;
	scanf("%d\n", &N);
	list = (Node **)malloc(sizeof(Node *) * 256);
	memset(list, 0, sizeof(Node *) * 256);

	list[0] = (Node *)malloc(sizeof(Node));
	list[0]->num = 256;


	for(int n = 1; n <= N; ++n)
	{
		int letter = 0, num = 0;
		Node *node = NULL;
		node = (Node *)malloc(sizeof(Node));
		node->left = node->right = NULL;
		scanf("%c %d ", &letter, &num);
		node->letter = c[n] = letter;
		node->num = f[letter] = num;
		list[n] = node;

	}
/*
	for(int n = 1; n <= N; ++n)
	{
		printf("%c %d\n", list[n]->letter, list[n]->num);
	}
*/
	int index1 = 0, index2 = 0;
	while(count < N - 1)
	{
		index1 = index2 = 0;
		for(int n = 1; n <= N; ++n)
		{
			if(list[n] != NULL && list[n]->num < list[index1]->num)
			{
				index1 = n;
				if(list[index1]->num < list[index2]->num)
				{
					int temp = index1;
					index1 = index2;
					index2 = temp;
				}
			}
		}

		Node *node = NULL;
		node = (Node *)malloc(sizeof(Node));
		node->num = list[index1]->num + list[index2]->num;
		node->left = list[index1];
		node->right = list[index2];
		list[index1] = node;
		list[index2] = NULL;
		printf("%d %d\n", index1, index2);
		++count;
	}

	int length = traversal(list[index1]);
	printf("%d\n", length);
	count = 0;
	scanf("%d", &M);
	//printf("%dsdfsdf",M);
	for(int m = 0; m < M; ++m)
	{
		for(int n = 1; n <= N; ++n)
		{
			int letter = 0;
			scanf("%d %s", &letter, str[n]);
			printf("%c\n", letter);
			count += f[letter] * strlen(str[m]);
		}
	}

	printf("%d\n", count);
	return 0;
}

int traversal(Node *node)
{
	static int count = 0;
	int length = 0;
	if(node == NULL)
		return 0;
	if(node->left == NULL && node->right == NULL)
	{
		printf("%c  %d\n", node->letter, count);
		length = count * node->num;
	}
	++count;
	length += traversal(node->left);
	length += traversal(node->right);
	--count;
	return length;
}
