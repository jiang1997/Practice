#include <stdio.h>
#include <stdlib.h>

void func(int *a, int *b);

int N = 0, M = 0;
int main(void)
{
	int w[60] = {0}, p[60] = {0}, f[60] = {0};//w weights, p price, f father;
	int *dp[60] = {0};

	for(int i = 0; i < 60; ++i)
	{
		dp[i] = (int *)malloc(sizeof(int) * 60000);
	}
	scanf("%d %d", &M, &N);

	for(int n = 1; n <= N; ++n)
	{
		int weight = 0, price = 0, father = 0;
		scanf("%d %d %d", &price, &weight, &father);
		w[n] = price * weight;
		p[n] = price / 10;
		f[n] = father;

	}

	for(int n = 1; n <= N; ++n)
	{
		for(int m = M; m >= p[n]; --m)
		{
			if(f[n] == 0)
				dp[n][m] = w[n];
		}
	}

	for(int n = 1; n <= N; ++n)
	{
		for(int m = M / 10; m >= p[n] + p[f[n]]; --m)
		{
			if(dp[f[n]][m] < dp[f[n]][m - p[n]] + w[n])	
				dp[f[n]][m] = dp[f[n]][m - p[n]] + w[n];
		}
	}
/*
	for(int i = 0; i < 5; ++i)
	{
		for(int m = 0; m <= M / 10; ++m)
		{
			printf("m:%d %d\n", m, dp[i][m]);
		}
		printf("-------------------------%d\n", i);	
	}
*/
	for(int i = 2; i < 60; ++i)
	{
		func(dp[1], dp[i]);
	}

	int max = dp[0][M / 10];
	for(int m = M / 10; m >= 0; --m)
		max = dp[1][m] > max? dp[1][m]: max;	
	printf("%d", max);

	return 0;
}


void func(int *a, int *b)
{
	int temp[3200] = {0}; 
	
	for(int m1 = M / 10; m1 >= 0; --m1)
	{
		for(int m2 = 0; m1 + m2 <= M / 10; ++m2)
		{
			if(a[m1] + b[m2] > temp[m1 + m2])
				temp[m1 + m2] = a[m1] + b[m2];
		}
	}

	for(int m = M / 10; m >= 0; --m)
	{
		a[m] = temp[m];
	}
}
