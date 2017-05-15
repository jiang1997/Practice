#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int N, *array = NULL;
	array = (int *)malloc(sizeof(int) * 100000);
	scanf("%d", &N);

	scanf("%d", &array[0]);
	for(int n = 1; n < N; ++n)
	{
		int num, index;
		scanf("%d", &num);

		for(index = n; index > 0 && num < array[index - 1]; --index)
			array[index] = array[index - 1];

		array[index] = num;

	}

	for(int n = 0; n < N; ++n)
	{
		if(n) printf(" ");
		printf("%d", array[n]);
	}
	return 0;
}
