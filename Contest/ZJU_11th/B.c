#include <stdio.h>

int main(void)
{
	int T = 0;
	int data[12][12] = {0};
	scanf("%d", &T);
	for(int t = 0; t < T; ++t)
	{
		int n = 0, m = 0, list[12] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
		scanf("%d %d", &n, &m);
		for(int n1 = 0; n1 < n; ++n1)
		{
			for(int n2 = 0; n2 < n; ++n2)
			{
				scanf("%d", &data[n1][n2]);
			}
		}
		int flag = 1;
		for(int n1 = 0; ; ++n1)
		{
			if(n1 % n == 0)
			{
				if(flag == 0)
					break;
				flag = 0;
			}
			n1 %= n;
			for(int n2 = 1; n2 < n; ++n2)
			{
				int sum1 = 0, sum2 = 0, index_cmp = (n1 + n2) % n;
				sum1 = data[n1][list[n1]] + data[index_cmp][list[index_cmp]];
				sum2 = data[n1][list[index_cmp]] + data[index_cmp][list[n1]];
				if(sum2 > sum1)
				{
					int temp = list[n1];
					list[n1] = list[n2];
					list[n2] = temp;
					++flag;
				}
				
			}
		}
		for(int n1 = 0; n1 < n; ++n1)
			printf("%d", list[n1]);
		printf("\n");

	}
	
	return 0;
}
