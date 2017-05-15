#include <stdio.h>

int main(void)
{
	int N, array[51] = {0}, temp;
	scanf("%d", &N);

	for(int n = 0; n < N; ++n)
	{
		scanf("%d", &temp);
		++array[temp];
	}

	for(int n = 0; n <= 50; ++n)
	{
		if(array[n] != 0)
		{
			printf("%d:%d\n", n, array[n]);
		}
	}
	return 0;
}
