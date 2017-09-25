#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **args)
{
	int T = 0, *coaches = NULL, *recorder = NULL, *recorder2 = NULL;
	coaches = (int *)malloc(sizeof(int) * 100000);
	recorder = (int *)malloc(sizeof(int) * 100000);
	recorder2 = (int *)malloc(sizeof(int) * 100000);
	scanf("%d", &T);
	while(T--)
	{
		int N = 0, L = 0, maximum = 0;
		scanf("%d", &N);
		for(int n = 0; n < N; ++n)
			scanf("%d", &coaches[n]);
		scanf("%d", &L);
		for(int n = 0; n + L - 1 < N; ++n)
		{
			for(int l = 1; l < L; ++l)
				coaches[n] += coaches[n + l];
			recorder[n] = coaches[n];
			recorder2[n] = coaches[n];
		}
		for(int n = 1; n < 3; ++n)
		{
			for(int m = n * L; m + L - 1 < N; ++m)
			{
				int maximum = 0;
				for(int u = (n - 1) * L; u < m - L + 1; ++u)
				{
				//	printf("n*L-1 %d,u %d  ", n * L - 1, u);
					maximum = maximum < recorder2[u]? recorder2[u]: maximum;
				}
//				printf("max %d\n", maximum);
				recorder[m] = maximum + coaches[m];
			}

			for(int m = n * L; m + L - 1 < N; ++m)
			{
				recorder2[m] = recorder[m];
			}
		}



		for(int n = 0; n + L - 1 < N; ++n)
		{
			maximum = maximum < recorder[n]? recorder[n]: maximum;
		}

		printf("%d\n", maximum);
	}
	return 0;
}




