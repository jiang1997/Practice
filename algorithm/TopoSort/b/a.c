#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct Node
{
	int num;
	int cost;
	int earliest;
	int latest;
	struct Node *edge;
}Node;

int sort();

int N, M;
Node *graph = NULL;
int inDegree[200] = {0}, outDegree[200] = {0};

int main(void)
{
	graph = (Node *)malloc(sizeof(Node) * 200);
	memset(graph, 0, sizeof(Node) * 200);

	scanf("%d %d", &N, &M);

	for(int n = 1; n <= N; ++n)
		graph[n].latest = 1900000000;

	for(int m = 0; m < M; ++m)
	{
		int src = 0, dst = 0, cost = 0;
		Node *toDst = (Node *)malloc(sizeof(Node));
		Node *toSrc = (Node *)malloc(sizeof(Node));

		scanf("%d %d %d", &src, &dst, &cost);
		toDst->num = dst;
		toSrc->num = src;
		toDst->cost = cost;
		toSrc->cost = cost * -1 -1;

		toDst->edge = graph[src].edge;
		graph[src].edge = toDst;

		toSrc->edge = graph[dst].edge;
		graph[dst].edge = toSrc;

		++inDegree[dst];
		++outDegree[src];
	}

	for(int n = 1; n <= N; ++n)
	{
		printf("%d   in:%d  out:%d:\n", n, inDegree[n], outDegree[n]);
		for(Node *last = graph[n].edge; last != NULL; last = last->edge)
		{
			printf("num:%d cost:%d\n", last->num, last->cost);
		}
	}

	sort();
	return 0;
}

int sort()
{
	int earliest = 0;

	for(int n = 0; n < N; ++n)
	{
		int index = 0;
		for(index = N; index > 0 && inDegree[index] != 0; --index) ;

		inDegree[index] = -1;
		earliest = earliest < graph[index].earliest? graph[index].earliest: earliest;
		for(Node *last = graph[index].edge; last != NULL; last = last->edge)
		{
			if(last->cost >= 0)
			{
				if(graph[index].earliest + last->cost > graph[last->num].earliest)
					graph[last->num].earliest = graph[index].earliest + last->cost;
				--inDegree[last->num];
			}
		}
	}
	if(inDegree[0] == -1)
	{
		printf("0");
		return 0;
	}

	printf("%d\n", earliest);

	for(int n = 1; n <= N; ++n)
	{
		if(outDegree[n] == 0)
			graph[n].latest = graph[n].earliest;
	}

	for(int n = 0; n < N; ++n)
	{
		int index = 0;
		for(index = N; index > 0 && outDegree[index] != 0; --index) ; 
		
		outDegree[index] = -1;
		for(Node *last = graph[index].edge; last != NULL; last = last->edge)
		{
			if(last->cost < 0)
			{
				if(graph[index].latest + last->cost + 1 < graph[last->num].latest)
					graph[last->num].latest = graph[index].latest + last->cost + 1;
				--outDegree[last->num];
			}
		}
	}

	for(int n = 1; n <= N; ++n)
	{
		for(Node *last = graph[n].edge; last != NULL; last = last->edge)
		{
			if(last->cost >= 0)
			{
				if(graph[n].earliest + last->cost == graph[last->num].latest)
					printf("%d->%d\n", n, last->num);
			}
		}
	}
	return	earliest; 
}


