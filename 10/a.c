#include <stdio.h>

int minimum(int *population, int num);

int main(void)
{
	int T = 0, n = 0, num[10] = {0};
	scanf("%d", &T);
	for(int t = 0; t < T; ++t)
	{
		scanf("%d", &n);
		for(int n1 = 0; n1 < n; ++n1)
		{
			scanf("%d", num + n1);
		}
	minimum(num, n);
	printf("%d\n", minimum(num, n));

	}
	return 0;
}

int minimum(int *population, int num)
{
	int mini_index = 0, mini = 0;
	for(int n1 = 0; n1 < num; ++n1)
	{
		mini_index = population[n1] < population[mini_index]? n1: mini_index;
	}
	mini = population[mini_index];
	population[mini_index] = 256;
	return mini;
}


