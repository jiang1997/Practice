#include <stdio.h>

int main(int argc, char **args)
{
	int N, M, W[20000], D[20000], Num = 0, n = 0, m = 0, recorder[20000] = {0};
	scanf("%d %d", &N, &M);
	for(n = 0; n < N; ++n)
		scanf("%d %d", &W[n], &D[n]);
	for(n = 0; n < N; ++n)
	{
		for(m = M; m >= W[n]; --m)
		{
			if(recorder[m - W[n]] + D[n] > recorder[m])
				recorder[m] = recorder[m - W[n]] + D[n];
		}
	}
	printf("%d",recorder[M]);
	return 0;
}
