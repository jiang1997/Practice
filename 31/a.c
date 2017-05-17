#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
	int Num;
	int Next;
}Node;

int main(int argc, char **args)
{
	int Root, N, K, index, flag, n, pre, head, foot, *stack, top = 0;
	Node *list;
	list = (Node *)malloc(sizeof(Node) * 100000);
	stack = (int *)malloc(sizeof(int) * 100000);
	scanf("%d %d %d", &Root, &N, &K);
	
	for(n = 0; n < N; ++n)
	{
		int index, num, next;
		scanf("%d %d %d", &index, &num, &next);
		list[index].Num = num;
		list[index].Next = next;
	}
	index = Root;

	for(n = 1;index != -1 && n <= N; ++n)
	{
		index = list[index].Next;
	}
	N = n - 1;

	index = Root;
	head = Root;
	for(n = 1; n <= N - N % K; ++n)
	{
		stack[top++] = index;
		//printf("push %05d %d\n", list[index], list[index].Num);
		index = list[index].Next;
	}
	
	foot = index;
	for(n = 1;K != 1 && n <= top; ++n)
	{
		int index = stack[top - n];
		if(n % K == 1)
		{
			pre = index;
			head = pre;
		}
		else
		{
			if(n % K == 0)
			{
				list[index].Next = foot;
				foot = head;
			}
			list[pre].Next = index;
			pre = index;
		}
	}
	index = head;
	while(index > -1)
	{
		printf("%05d %d ", index, list[index].Num);
		if(list[index].Next < 0)
			printf("%d\n", list[index].Next);
		else
			printf("%05d\n", list[index].Next);

		index = list[index].Next;
	}


	return 0;
}
