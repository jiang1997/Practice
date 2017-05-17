#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int Arrange(int *Array, int Length);
int Multiply(int *Array, int Length, int Num);
int main(int argc, char **args)
{
	int N, *array = NULL;
	int temp[] = {12, 45, 2};
	array = (int *)malloc(sizeof(int) * 100000);

	while(scanf("%d", &N) != EOF)
	{
		int length = 1;
		memset(array, 0, sizeof(int) * 100000);
		array[0] = 1;
		for(int num = 1; num <= N; ++num)
		{
			length = Multiply(array, length, num);
		}

		for(int index = length - 1; index >= 0; --index)
		{
			printf("%d", array[index]);
		}
		printf("\n");
	}

	return 0;
}

int Multiply(int *Array, int Length, int Num)
{
	for(int index = 0; index < Length; ++index)
	{
		Array[index] *= Num;
	}
	Length = Arrange(Array, Length);
	return Length;
}

int Arrange(int *Array, int Length)
{
	int index = 0;
	for(index = 0; index < Length || Array[index] >= 10; ++index)
	{
	
		Array[index + 1] += Array[index] / 10;
		Array[index] %= 10;
	}

	return index + (Array[index] != 0);
}

