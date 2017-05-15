#include <stdio.h>
#include <stdlib.h>

int comp(void *a,void *b);

int main(void)
{
	int T = 0;
	scanf("%d", &T);
	int t = 0;
	for(t = 0; t < T; ++t)
	{
		int n = 0, sum = 0, data[20000];
		scanf("%d", &n);
		int n1 = 0;
		for(n1 = 0; n1 < n; ++n1)
		{
			scanf("%d", data + n1);
		}
		qsort(data, n, sizeof(int), comp);
		for(n1 = 2; n1 < n; n1 += 3)
		{
			sum += data[n - n1];
		}
		printf("%d\n", sum);
	}
	return 0;
}

int comp(void *a, void *b)
{
	return *(int *)a - *(int *)b;
}

