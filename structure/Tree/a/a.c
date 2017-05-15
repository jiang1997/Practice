#include <stdio.h>
#include <stdlib.h>
#include <string.h>



void dfs(int index);

typedef struct Edge 
{
	int num;//index   weight
	struct Edge *next;
}Edge;

/*
typedef struct Node
{
	int weight;
	struct Edge *next;
}Node;
*/
Edge *list = NULL; 
int l = 0, r = 0, record[20000] = {0};
int main(void)
{
	int T = 0;

	scanf("%d", &T);
	
	for(int t = 0; t < T; ++t)
	{
		int N = 0, M = 0;
		list = (Edge *)malloc(sizeof(Edge) * 20000);
		memset(list, 0, sizeof(Edge) * 20000);

		scanf("%d", &N);		
		for(int n = 1; n <= N; ++n)
			scanf("%d", &list[n].num); // scan  weight
		
		//scan edge
		for(int n = 1; n < N; ++n)
		{
			int src = 0, dst = 0;
			Edge *toDst = (Edge *)malloc(sizeof(Edge));	
			Edge *toSrc = (Edge *)malloc(sizeof(Edge));
			toSrc->next = toDst->next = NULL;

			scanf("%d %d", &src, &dst);
			toSrc->num = src;
			toDst->num = dst;

			Edge *last = NULL;
			for(last = &list[src]; last->next != NULL; last = last->next) ;
			last->next = toDst;

			for(last = &list[dst]; last->next != NULL; last = last->next) ;
			last->next = toSrc;

		}

		for(int n = 1; n <= N; ++n)
		{
			printf("%d:%d\t", n, list[n].num);
			for(Edge *last = list[n].next; last != NULL; last = last->next)
			{
				printf("%d ", last->num);	
			}
			printf("\n");
		}
		scanf("%d", &M);
		for(int m = 0; m < M; ++m)
		{
			int count = 0;
			scanf("%d %d", &l, &r);
			for(int n = 1; n <= N; ++n)
			{
				if(record[n] == 0 && list[n].num >= l && list[n].num <= r)	
				{
					++count;
					dfs(n);	
				}
			}
			memset(record, 0, sizeof(int) * 20000);
			printf("%d\n", count);

		}
	}

	return 0;
}

void dfs(int index)
{
	record[index] = 1;
	for(Edge *last = list[index].next; last != NULL; last = last->next)	
	{
		Edge *edge = &list[last->num];
		if(record[last->num] == 0 && edge->num >= l && edge->num <= r)	
			dfs(last->num);
	}
}


