#include <stdio.h>
#include <stdlib.h>

int compare(void *a, void *b);

int main(void)
{
	int N = 0, *array = NULL, n;
	scanf("%d", &N);
	array = (int *)malloc(sizeof(int) * 100000);

	for(n = 0; n < N; ++n)
		scanf("%d", &array[n]);

	qsort(array, N, sizeof(int), compare);

	for(n = 0; n < N; ++n)
	{
		if(n) printf(" ");
		printf("%d", array[n]);
	}
	return 0;
}


int compare(void *a, void *b)
{
	return *(int *)a - *(int *)b;
}


