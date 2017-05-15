#include <stdio.h>

int maximum(int *data, int num);

int main(void)
{
	int T = 0;
	scanf("%d", &T);
	for(int t = 0; t < T; ++t)
	{
		int n = 0, sum = 0, data[20000];
		scanf("%d", &n);
		for(int n1 = 0; n1 < n; ++n1)
		{
			scanf("%d", data + n1);
		}
		for(int n1 = 0; n1 < n / 3; ++n1)
		{
			maximum(data, n);
			maximum(data, n);
			sum += maximum(data, n);
		}
		printf("%d\n", sum);
	}
	return 0;
}

int maximum(int *data, int num)
{
	int max = 0, max_index = 0;
	for(int n1 = 0; n1 < num; ++n1)
	{
		max_index = data[n1] > data[max_index]? n1: max_index;
	}
	max = data[max_index];
	data[max_index] = -1;
	return max;
}


