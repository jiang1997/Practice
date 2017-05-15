#include <stdio.h>

int main(void)
{
	int n = 0, data[100] = {0};
	while(scanf("%d", &n), n != 0)
	{
		int sum = 0;	
		for(int n1 = 0; n1 < n; ++n1)
		{
			scanf("%d", data + n1);
			sum += data[n1];
		}
		sort(data, n);
		sum -= data[0];
		sum -= data[n - 1];
		printf("%d\n", sum / (n - 2));
	}
	return 0;
}


int sort(int *data, int num)
{
	for(int n1 = 0; n1 < num - 1; ++n1)
	{
		for(int n2 = 0; n2 < num - 1 - n1; ++n2)
		{
			int temp = data[n2];
			if(data[n2] > data[n2 + 1])
			{
				data[n2] = data[n2 + 1];
				data[n2 + 1] = temp;
			}
		}
	}
}


