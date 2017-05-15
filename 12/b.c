#include <stdio.h>

void sort(int *data, int num);

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
		sort(data, n);
		for(int n1 = 0; n1 < n; n1 += 3)
		{
			sum += data[n - n1];
		}
		printf("%d\n", sum);
	}
	return 0;
}

void sort(int *data, int num)
{
	for(int n1 = 0; n1 < num - 1; ++n1)
	{
		for(int n2 = num - 1; n2 > n1; --n2)
		{
			int temp = data[n2];
			if(data[n2 - 1] > data[n2])
			{
				data[n2] = data[n2 - 1];
				data[n2 - 1] = temp;
			}
		}
	}
}


