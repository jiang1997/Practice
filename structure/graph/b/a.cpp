#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <queue>

using namespace std;

typedef struct Node
{
	int index;
	int weights;
	struct Node *next;
}Node;


int bfs(int srcIndex);

int N = 0, M = 0;
Node *graph = NULL;  

int main(void)
{
	scanf("%d %d", &N, &M);
	graph = (Node *)malloc(sizeof(Node) * 1000);
	memset(graph, 0, sizeof(Node) * 1000);
	for(int m = 0; m < M; ++m)
	{
		Node *ToSrcNode = NULL, *ToDstNode = NULL, *lastNode = NULL;
		int srcIndex = 0, dstIndex = 0, weights = 0;
		scanf("%d %d %d", &srcIndex, &dstIndex, &weights);

		ToSrcNode = (Node *)malloc(sizeof(Node));
		ToDstNode = (Node *)malloc(sizeof(Node));

		ToSrcNode->next = ToDstNode->next = NULL;	
		ToDstNode->weights = ToSrcNode->weights = weights;
		ToDstNode->index = dstIndex;
		ToSrcNode->index = srcIndex;

		
		for(lastNode = &graph[srcIndex]; lastNode->next != NULL; lastNode = lastNode->next) ;
		lastNode->next = ToDstNode;
		
		for(lastNode = &graph[dstIndex]; lastNode->next != NULL; lastNode = lastNode->next) ;
		lastNode->next = ToSrcNode;
	}


	for(int n = 1; n <= N; ++n)
	{
		printf("%d:", n);
		for(Node *lastNode = graph[n].next; lastNode != NULL; lastNode = lastNode->next)
		{
			printf("%d weight:%d", lastNode->index, lastNode->weights);
		}
		printf("\n");
	}

	bfs(1);
	return 0;
}


int bfs(int srcIndex)
{
	int list[1000] = {0}, record[1000] = {0};

	memset(list, 1, sizeof(int) * 1000);
	list[1] = 0;

	queue<int> IndexQueue;

	IndexQueue.push(srcIndex);
	while(!IndexQueue.empty())
	{
		int TopIndex = IndexQueue.front();
		Node *node = graph[TopIndex].next;
		IndexQueue.pop();
		//transerval all edges
		for(; node != NULL; node = node->next)
		{
			//save the shortest edge's weights	
			if(list[node->index] > list[TopIndex] + node->weights)
			{
				list[node->index] = list[TopIndex] + node->weights;
				IndexQueue.push(node->index);
			}
			//transerval node
			if(record[node->index] == 0)
			{
				IndexQueue.push(node->index);
				record[node->index] = 1;
			}
		}

	}

	for(int n = 1; n <= N; ++n)
	{
		printf("%d to %d: %d\n", srcIndex, n, list[n]);
	}
	return 0;
}

