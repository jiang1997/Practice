#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int sort(int span);

int N = 0, *array = NULL, Sedge[20] = {1,5,19,41,109,209,505,929,2161,3905,8929,16001,36289,64769,146305,260609,587521,1045505};
int main(void)
{
	array = (int *)malloc(sizeof(int) * 100000);

	scanf("%d", &N);
	for(int n = 0; n < N; ++n)
		scanf("%d", &array[n]);

	for(int n = 17; n >= 0; --n)
	{
		sort(Sedge[n]);
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
