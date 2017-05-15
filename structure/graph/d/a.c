#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Node
{
	int num;// num or index
	int cost;
	struct Node *next;
}Node;

int func();

int N = 0, M = 0;
Node *graph = NULL;
int main(void)
{
	Node **Last = NULL;
	graph = (Node *)malloc(sizeof(Node) * 200);
	Last = (Node **)malloc(sizeof(Node *) * 200);
	memset(graph, 0, sizeof(Node) * 200);

	scanf("%d %d", &N, &M);
	
	for(int n = 0; n < N; ++n)
	{
		Last[n] = &graph[n];	
	}


	for(int m = 1; m <= M; ++m)
	{
		int S = 0, E = 0, L = 0;
		Node *next = NULL;
		next = (Node *)malloc(sizeof(Node));
		next->next = NULL;
		
		scanf("%d %d %d", &S, &E, &L);
		++graph[E].num;
		next->num = E;
		next->cost = L;	
		Last[S]->next = next;
		Last[S] = next;
	}

	for(int n = 0; n < N; ++n)
	{
		printf("%d:%d\n", n, graph[n].num);
		for(Node *last = graph[n].next; last != NULL; last = last->next)
		{
			printf("dst:%d cost:%d\n", last->num, last->cost);
		}
	}
	int length = func();
	printf("%d", length);
	return 0;
}

int func()
{
	int index = 0, count = 0, length = 0;

	graph[0].cost = 0;
	while(count != N)
	{
		//
		for(index = N - 1; index >= 0 && graph[index].num != 0; --index) ;
		
		length = graph[index].cost;
		for(Node *last = graph[index].next; last != NULL; last = last->next)
		{
			--graph[last->num].num;
			graph[last->num].cost = graph[last->num].cost < last->cost + graph[index].cost? last->cost + graph[index].cost: graph[last->num].cost;
		}
		graph[index].num = -1;
		printf("%d\n", index);
		++count;	

		//
	}

	for(index = 0; index < N && graph[index].num == -1; ++index) ;
	if(index != N)
		length = -1;
	return length;
}
