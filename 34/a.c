#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
	int Num;
	struct Node *Left;
	struct Node *Right;
}Node;

Node *Parse(int *InOrder, int *PostOrder, int Length);
void PreOrderTraversal(Node *Root);
int Result[36] = {0}, top = 0;
int main(int argc, char **args)
{
	int N, InOrder[36], PostOrder[36];
	Node *Root = NULL;
	scanf("%d", &N);
	for(int n = 0; n < N; ++n)
		scanf("%d", &PostOrder[n]);
	for(int n = 0; n < N; ++n)
		scanf("%d", &InOrder[n]);

	Root = Parse(InOrder, PostOrder, N);	
	printf("Preorder:");
	PreOrderTraversal(Root);
	return 0; 
}

Node *Parse(int *InOrder, int *PostOrder, int Length)
{
	int index = 0;
	if(Length == 0) return NULL;

	for(index = 0; InOrder[index] != PostOrder[Length - 1]; ++index) ;

	Node *node = (Node *)malloc(sizeof(Node));
	node->Num = PostOrder[Length - 1];

	node->Left = Parse(InOrder, PostOrder, index);
	node->Right = Parse(&InOrder[index + 1], &PostOrder[index], Length - index - 1);

	return node;
}

void PreOrderTraversal(Node *Root)
{
	if(Root != NULL)
	{
		printf(" %d", Root->Num);
		PreOrderTraversal(Root->Left);
		PreOrderTraversal(Root->Right);
	}
}
