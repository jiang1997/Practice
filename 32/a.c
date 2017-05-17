#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
	int Co;
	int Index;
	struct Node *Next;
}Node;

Node *Copy(Node *Lst);
Node *Plus(Node *Lst1, Node *Lst2);
Node *Multiply(Node *Lst1, Node *Lst2);
int main(int argc, char **args)
{
	int N;
	Node *lst1 = NULL, *lst2 = NULL;

	scanf("%d", &N);
	while(N--)
	{
		int co, index;
		Node **last = NULL;
		scanf("%d %d", &index, &co);
		
		for(last = &lst1; *last != NULL; last = &((*last)->Next)) ;

		*last = (Node *)malloc(sizeof(Node));
		(*last)->Co = co;
		(*last)->Index = index;
		(*last)->Next = NULL;
	}
	
	scanf("%d", &N);
	while(N--)
	{
		int co, index;
		Node **last = NULL;
		scanf("%d %d", &index, &co);

		for(last = &lst2; *last != NULL; last = &((*last)->Next)) ;

		*last = (Node *)malloc(sizeof(Node));
		(*last)->Co = co;
		(*last)->Index = index;
		(*last)->Next = NULL;
	}
	Node *temp = NULL;
	//temp = Copy(lst1);
	//temp = Plus(temp, lst2);
	temp = Multiply(lst1, lst2);
	int flag = 0;
	for(Node *last = temp; last != NULL; last = last->Next)
	{
		if(last->Index == 0)
			continue;
		if(flag == 1) printf(" ");
		flag = 1;
		printf("%d %d", last->Index, last->Co);
	}
	if(flag == 0)
		printf("0 0");
	printf("\n");
	temp = Plus(lst1, lst2);
	//return 0;
	flag = 0;
	for(Node *last = temp; last != NULL; last = last->Next)
	{
		if(last->Index == 0)
			continue;
		if(flag == 1) printf(" ");
		flag = 1;
		printf("%d %d", last->Index, last->Co);
	}
	if(flag == 0)
		printf("0 0");
	return 0;
}

Node *Multiply(Node *Lst1, Node *Lst2)
{
	Node *temp = NULL, *result = NULL;
	for(; Lst2 != NULL; Lst2 = Lst2->Next)
	{
		temp = Copy(Lst1);
		for(Node *last = temp; last != NULL; last = last->Next)
		{
			last->Co += Lst2->Co;
			last->Index *= Lst2->Index;
		}

		if(result == NULL)
		{
			result = Copy(temp);
		}
		else
		{
			result = Plus(result, temp);
		}
	}
	return result;
}

Node *Copy(Node *Lst)
{
	Node *head = NULL, **last = &head;
	for(; Lst != NULL; Lst = Lst->Next)
	{
		*last = (Node *)malloc(sizeof(Node));
		(*last)->Co = Lst->Co;
		(*last)->Index = Lst->Index;
		last = &((*last)->Next);
	}

	return head;
}

Node *Plus(Node *Lst1, Node *Lst2)
{
	if(Lst1 == NULL)
	{
	Lst1 = (Node *)malloc(sizeof(Node));
	Lst1->Next = NULL;
	Lst1->Index = Lst1->Co = 0;
	}
	for(; Lst2 != NULL; Lst2 = Lst2->Next)
	{
		Node *node = NULL, *temp = NULL;
		for(node = Lst1; node != NULL && node->Co > Lst2->Co; node = node->Next) temp = node;
		if(node == NULL && temp != NULL || node->Co < Lst2->Co && temp != NULL)
		{
			temp->Next = (Node *)malloc(sizeof(Node));
			temp->Next->Co = Lst2->Co;
			temp->Next->Index = Lst2->Index;
			temp->Next->Next = node;
		}
		else if(node != NULL && node->Co == Lst2->Co)
		{
			node->Index += Lst2->Index;
		}
		else
		{
			temp = (Node *)malloc(sizeof(Node));
			temp->Co = Lst2->Co;
			temp->Index = Lst2->Index;
			temp->Next = Lst1;
			Lst1 = temp;
		}
	}
	return Lst1;
}
