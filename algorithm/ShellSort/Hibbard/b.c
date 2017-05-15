#include <stdio.h>
#include <stdlib.h>

int sort(int span);

int N = 0, *array = NULL, Hibb[20] = {1, 3, 7, 15, 31, 63, 127, 255, 511, 1023, 2047, 4095, 8191, 16383, 32767, 65535, 131071, 262143, 524287, 1048575};
int main(void)
{
	array = (int *)malloc(sizeof(int) * 100000);

	scanf("%d", &N);
	for(int n = 0; n < N; ++n)
		scanf("%d", &array[n]);

	for(int n = 19; n >= 0; --n)
	{
		sort(Hibb[n]);
	}


	for(int n = 0; n < N; ++n)
	{
		if(n) printf(" ");
		printf("%d", array[n]);
	}

	return 0;
}

int sort(int span)
{
	int *temp = NULL;
	temp = (int *)malloc(sizeof(int) * 100000);

	for(int n1 = span - 1; n1 < N; n1 += span)
	{
		int num = array[n1], n2;
		for(n2 = n1; n2 > span - 1 && num < temp[n2 - span]; n2 -= span)
			temp[n2] = temp[n2 - span];

		temp[n2] = num;
	}

	for(int n = span - 1; n < N; n += span)
		array[n] = temp[n];

	free(temp);
}
