#include <stdio.h>

int main(void)
{
	int N = 0;
	while(scanf("%d", &N), N != 0)
	{
		int population[101] = {0}, sum = 0;
		for(int n1 = 0; n1 < N; ++n1)
		{
			scanf("%d", population + n1);
		}

		for(int n1 = 0; n1 < N / 2 + 1; ++n1)
		{
			sum += minimum(population, N) / 2 + 1;
		}

		printf("%d\n", sum);
		sum = 0;
		
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

