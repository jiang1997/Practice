#include <stdio.h>

#define INF 1000000000

int graph[101][101] = {0};

int main(void)
{
	int N, M, minimum = INF, index = 0;
	scanf("%d %d", &N, &M);

	for(int n1 = 1; n1 <= N; ++n1)
	{
		for(int n2 = 1; n2 <= N; ++n2)
		{
			graph[n1][n2] = INF;
			if(n1 ==n2)
				graph[n1][n2] = 0;
		}
	}

	while(M--)
	{
		int src, dst, length;
		scanf("%d %d %d", &src, &dst, &length);

		graph[src][dst] = length;
		graph[dst][src] = length;
	}

	//for(int i = 1; i <= N; ++i)
	{
	for(int n1 = 1; n1 <= N; ++n1)
	{
		for(int n2 = 1; n2 <= N; ++n2)
		{
			for(int n3 = 1; n3 <= N; ++n3)
			{
				if(n1 != n3 && graph[n1][n2] + graph[n2][n3] < graph[n1][n3])
				{
					graph[n1][n3] = graph[n1][n2] + graph[n2][n3];
					graph[n3][n1] = graph[n1][n3];
				}
			}
		}
	}
	}

	for(int n1 = 1; n1 <= N; ++n1)
	{
		int maximum = 0;
		for(int n2 = 1; n2 <= N; ++n2)
		{

			maximum = graph[n1][n2] > maximum? graph[n1][n2]: maximum;
		
			if(graph[n1][n2] == INF)
			{
				printf("0");
				return 0;
			}

		}

		if(minimum > maximum)
		{
			minimum = maximum;
			index = n1;
		}

	}

	printf("%d %d", index, minimum);

	return 0;
}

