#include <stdio.h>
#include <stdlib.h>
typedef int ElementType;
typedef struct Node *PtrToNode;
struct Node {
    ElementType Data;
    PtrToNode   Next;
};
typedef PtrToNode List;
List Merge(List L1, List L2)
{
	List temp = NULL, last, head;
	head = (PtrToNode)malloc(sizeof(struct Node));
	last = head;
	while(L1 != NULL)
	{
		if(L2 != NULL && L1->Data > L2->Data)
		{
			temp = L2->Next;
			last->Next = L2;
			L2->Next = L1;
			last = L1;

			L2 = temp;
			L1 = L1->Next;
		}
		else
		{
			temp = L1->Next;
			last->Next = L1;
			L1->Next = L2;

			last = L2 != NULL? L2: L1;
			L2 = L2 != NULL? L2->Next: NULL;
			L1 = temp;
		}

	}
	last->Next = L2;
	return head->Next;
}

int main(int argc, char **args)
{
	List l1 = NULL, l2 = NULL, temp;
	l1 = malloc(sizeof(struct Node));
	l2 = malloc(sizeof(struct Node));
	l1->Data = 7;
	l2->Data = 2;
	l1->Next = l2->Next = NULL;
	temp = malloc(sizeof(
	temp = Merge(l1, l2);
	for(; temp != NULL; temp = temp->Next)
		printf("%d ", temp->Data);
	return 0;
}


