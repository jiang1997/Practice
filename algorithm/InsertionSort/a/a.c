#include <stdio.h>
#include <stdlib.h>


int main(void)
{
	int N = 0, *array = NULL;
	scanf("%d", &N);
	array = (int *)malloc(sizeof(int) * 100000);

	scanf("%d", &array[0]);

	for(int n = 1; n < N; ++n)
	{
		int num = 0;
		scanf("%d", &num);
		
		for(int index = 0; index <= n; ++index)
		{
			if(array[index] > num)
			{
				int temp = array[index];
				array[index] = num;
				num = temp;
			}
		}

		array[n] = num;
	}
	

	for(int n = 0; n < N; ++n)
	{
		if(n) printf(" ");
		printf("%d", array[n]);
	}

	return 0;
}


