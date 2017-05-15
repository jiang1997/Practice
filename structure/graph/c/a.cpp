#include <stdio.h>
#include <queue>

using namespace std;

void bfs(int src);
void dfs(int src);

int graph[10][10] = {0};
int N = 0, E = 0;
int record[10] = {0};

int main(void)
{
	scanf("%d %d", &N, &E);
	for(int e = 0; e < E; ++e)
	{
		int a = 0, b = 0;
		scanf("%d %d", &a, &b);
		graph[a][b] = 1;
		graph[b][a] = 1;
	}
	
	for(int n = 0; n < N; ++n)
	{
		if(!record[n])
		{
			printf("{ ");
			dfs(n);
			printf("}\n");
		}
	
	}

	for(int n = 0; n < N; ++n)
		record[n] = 0;

	for(int n = 0; n < N; ++n)
	{
		
		if(!record[n])
		{
			printf("{ ");
			bfs(n);
			printf("}\n");
		}
	}
	return 0;
}



void dfs(int src)
{
	printf("%d ", src);
	record[src] = 1;
	for(int n = 0; n < N; ++n)
	{
		if(graph[src][n] == 1 && !record[n])
			dfs(n);
	}

}

void bfs(int src)
{
	queue<int> IndexQueue;	

	IndexQueue.push(src);
	record[src] = 1;
	while(!IndexQueue.empty())
	{
		int index = IndexQueue.front();
		IndexQueue.pop();
		printf("%d ", index);

		for(int n = 0; n < N; ++n)
		{
			if(graph[index][n] == 1 && record[n] == 0)
			{
				IndexQueue.push(n);
				record[n] = 1;
			}
		}
	}
}
