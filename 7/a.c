#include <stdio.h>

int main(void)
{
	int weight[25][30000] = {0};
	int commondity[25][2] = {0};
	int N, m, value, weights, product;
	scanf("%d %d", &N, &m);

	for(int n1 = 0; n1 < m; ++n1)
	{
		scanf("%d %d", &value, &weights);
		commondity[n1][0] = value;
		commondity[n1][1] = weights;
	}
	
	weight[0][commondity[0][0]] = commondity[0][1] * commondity[0][0];
	for(int n1= 1;n1 < m; ++n1)
	{
		for(int n2 = n1; n2 >= 0; --n2)
		{
			value = commondity[n1][0];
			weights = commondity[n1][1];
			product = value * weights;
			for(int n3 = 0; n3 <= N; ++n3)
			{
				int pre_weights = 0;
				if(n2 != 0)
					pre_weights = weight[n2 - 1][n3];
				if(pre_weights != 0 || n2 == 0)
				{
					
					if(pre_weights + product > weight[n2][n3 + value])
						weight[n2][n3 + value] = pre_weights  + product;
				}
				if(n2 == 0)
					break;
			}
		}
	}
	int maximum = 0;
	for(int n1 = N; n1 > 0; --n1)
	{
		for(int n2 = m - 1; n2 > 0; --n2)
		{
			if(weight[n2][n1] != 0)
				maximum = maximum < weight[n2][n1]? weight[n2][n1]: maximum;
		}
	}
	printf("%d", maximum);
	return 0;
}

