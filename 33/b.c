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
        temp = L1;
		L1 = L1->Next;
		temp->Next = NULL;
		temp = L2;
		L2 = L2->Next;
		temp->Next = NULL;
        head = (PtrToNode)malloc(sizeof(struct Node));
        last = head;
        while(L1 != NULL)
        {
                if(L2 != NULL && L1->Data > L2->Data)
                {
                        temp = L2->Next;
                        last->Next = L2;
                        // printf("1 %d\n", L2->Data);
                        // L2->Next = L1;
                        // last = L1;
						last = L2;
                        L2 = temp;
                        // L1 = L1->Next;
                }
                else
                {
                        temp = L1->Next;
                        last->Next = L1;
                        // printf("%d\n", L1->Data);
                        // L1->Next = L2;
						last = L1;
                        // last = L2 != NULL? L2: L1;
                        // L2 = L2 != NULL? L2->Next: NULL;
                        L1 = temp;
                }

        }
        last->Next = L2;
        return head;
}

int main(int argc, char **args)
{
        List l1 = NULL, l2 = NULL, temp;
        l1 = malloc(sizeof(struct Node));
        l2 = malloc(sizeof(struct Node));
        l1->Data = 7;
        l2->Data = 5;
        l1->Next = l2->Next = NULL;
        
        temp = malloc(sizeof(struct Node));
        temp->Data = 8;
        temp->Next = NULL;
        l1->Next = temp;
        temp = Merge(l1, l2);
        temp = temp->Next;
        for(; temp != NULL; temp = temp->Next)
                printf("%d ", temp->Data);
        return 0;
}