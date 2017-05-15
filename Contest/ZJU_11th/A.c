#include <stdio.h>

int main(void)
{
	int T;
	scanf("%d", &T);
	for(int t = 0; t < T; ++t)
	{
		int N, M, sum_N = 0, sum_M = 0;
		scanf("%d %d", &N, &M);
		for(int n = 0; n < N; ++n)
		{
			int temp = 0;
			scanf("%d", &temp); 
			sum_N += temp;
		}
		for(int m = 0; m < M; ++m)
		{
			int temp = 0;
			scanf("%d", &temp); 
			sum_M += temp;
		}
		if(sum_N == sum_M)
		{
			printf("Draw\n");
			continue;
		}
		printf("%s\n", sum_N > sum_M? "Calem": "Serena");


	}
	return 0;
}

