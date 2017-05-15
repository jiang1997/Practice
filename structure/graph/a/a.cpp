#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <queue>

using namespace std;

int SDS(int index);

typedef struct Node
{
	int index;
	struct Node *next;
}Node;

Node *graph = NULL;

int main(void)
{
	int *record = NULL;
	int N = 0, M = 0;
	scanf("%d %d", &N, &M);
	graph = (Node *)malloc(sizeof(Node) * (N + 1));
	memset(graph, 0, sizeof(Node) * (N + 1));
	record = (int *)malloc(sizeof(int) * (N + 1));
	memset(record, 0, sizeof(int) * (N + 1));

	for(int m = 0; m < M; ++m)
	{
		int a = 0, b = 0;
		Node *node_a = NULL, *node_b = NULL, *lastNode = NULL;
		node_a = (Node *)malloc(sizeof(Node));
		node_b = (Node *)malloc(sizeof(Node));
		node_a->next = node_b->next = NULL;
		scanf("%d %d", &a, &b);

		node_a->index = b;
		for(lastNode = &graph[a]; lastNode->next != NULL; lastNode = lastNode->next) ;
		lastNode->next = node_a;

		node_b->index = a;
		for(lastNode = &graph[b]; lastNode->next != NULL; lastNode = lastNode->next) ;
		lastNode->next = node_b;

	}

	for(int n = 1; n <= N; ++n)
	{
		printf("%d:", n);
		for(Node *node = graph[n].next; node != NULL; node = node->next)	
		{
			printf("%d ", node->index);
		}
		printf("\n");
	}
	for(int n = 1; n <= N; ++n)
	{
		printf("%0.2f\%\n",(float)SDS(1) / N * 100);	
	}
	return 0;
}


int SDS(int index)
{
	queue<int> queNode;
	int record[10000] = {0}, level = 0, lastIndex = 0, count = 0; 

	queNode.push(index);

	record[index] = 1;
	while(!queNode.empty() && level < 6)
	{
		int index = queNode.front();

		level += (lastIndex == index);

		printf("%d ", index);
		count++;
		Node *node = graph[index].next;
		queNode.pop();

		for(; node != NULL; node = node->next)
		{
			if(record[node->index] == 0)
			{
				queNode.push(node->index);
				lastIndex = node->index;
				record[node->index] = 1;
			}
			
		}

	}

	return count;
}




