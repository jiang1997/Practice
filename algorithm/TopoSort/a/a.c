#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Node
{
	int num;
	int cost;
	int least;
	struct Node * edge;
}Node;

int sort();
int func();

int N = 0, M = 0;
int in[200] = {0}, out[200] = {0};
Node *graph = NULL, **Last = NULL;

int main(void)
{
	graph = (Node *)malloc(sizeof(Node) * 200);
	Last = (Node **)malloc(sizeof(Node *) * 200);
	memset(graph, 0, sizeof(Node) * 200);
	
	scanf("%d %d", &N, &M);

	for(int n = 1; n <= N; ++n)
	{
		Last[n] = &graph[n];
		graph[n].least = 900000000;
	}

	for(int m = 1; m <= M; ++m)
	{
		int src, dst, cost;
		Node *toSrc = (Node *)malloc(sizeof(Node));
		Node *toDst = (Node *)malloc(sizeof(Node));	
		toSrc->edge = toDst->edge = NULL;

		scanf("%d %d %d", &src, &dst, &cost);
		toSrc->num = src;
		toDst->num = dst;
		toDst->cost = cost;
		toSrc->cost = cost * -1 - 1; //indicate direction  always be minus

		toDst->edge = graph[src].edge;
		graph[src].edge = toDst;

		toSrc->edge = graph[dst].edge;
		graph[dst].edge = toSrc;
/*
		Last[src]->edge = toDst;
		Last[src] = toDst;
		Last[dst]->edge = toSrc;
		Last[dst] = toSrc;
*/
		++in[dst];
		++out[src];


	}

	int result = sort();
	printf("%d\n", result);
	if(result)
		func();
/*
	for(int n = 1; n <= N; ++n)
	{
		printf("%d:in:%d out:%d\n", n, in[n], out[n]);
		for(Node *last = graph[n].edge; last != NULL; last = last->edge)
		{
			printf("%d %d\n", last->num, last->cost);
		}
	}
*/
	return 0;
}


int sort()
{
	int cost = 0, count = 0;
	while(count < N)
	{
		int index = 0;
		for(index = N; index > 0 && in[index] != 0; --index) ;
		in[index] = -1;
		cost = cost < graph[index].cost? graph[index].cost: cost;

		for(Node *last = graph[index].edge; last != NULL; last = last->edge)
		{
			if(last->cost >= 0)
			{
				if(graph[index].cost + last->cost > graph[last->num].cost)
				{
					graph[last->num].cost = graph[index].cost + last->cost;
				}
				--in[last->num];
			}
		}

		++count;
		
	}
	for(int n = 1; n <= N; ++n)
	{
		if(in[n] != -1)
			return 0;
	}

	return cost;
}

int func()
{
	int count = 0;

	while(count < N)
	{
		int index = 0;
		for(index = N; index > 0 && out[index] != 0; --index) ;
		if(graph[index].least == 900000000)
			graph[index].least = graph[index].cost;
		out[index] = -1;
		for(Node *last = graph[index].edge; last != NULL; last = last->edge)
		{
			if(last->cost < 0)
			{
				if(graph[index].least + last->cost + 1 < graph[last->num].least)
					graph[last->num].least = graph[index].least + last->cost + 1;
				--out[last->num];
			}
		}
		++count;
	}

	for(int n = 1; n <= N; ++n)
	{
		for(Node *last = graph[n].edge; last != NULL; last = last->edge)
		{
			if(last->cost >= 0)
			{
				if(graph[n].cost + last->cost == graph[last->num].least)
				{
					printf("%d->%d\n", n, last->num);
				}
			}
		}
	}
	return 0;
}
