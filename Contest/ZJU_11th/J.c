#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int *multiply(int *num1, int length1, int *num2, int length2);
int *divided(int *num1, int length1, int num2);
int *mod(int *num1, int length1, int num2);

int num1[128] = {0}, num2[128] = {0};

int main(void)
{
	int T = 0;
	scanf("%d", &T);
	for(int t = 0; t < T; ++t)
	{
		char str1[128] = {0};
		int two[1] = {2};
		scanf("%s", str1);
		for(int n1 = strlen(str1) - 1; n1 >= 0; --n1)
		{
			num1[strlen(str1) - 1 - n1] = str1[n1] - '0';
			num2[strlen(str1) - 1 - n1] = str1[n1] - '0';

		}
		++num2[0];
		for(int n1 = 0; n1 < strlen(str1); ++n1)
			printf("%d", num2[n1]);
		int *temp = multiply(num1, strlen(str1), num2, strlen(str1));
		int *double_num1 = multiply(num1, strlen(str1), two, 1);
		++double_num1[0];
		printf("\n");
		for(int n1 = 0; n1 < strlen(str1) - 1 + strlen(str1); ++n1)
			printf("%3d", temp[n1]);
		printf("\n");
		temp = multiply(temp, strlen(str1) - 1 + strlen(str1), double_num1, strlen(str1));
		for(int n1 = 0; n1 < strlen(str1) - 1 + strlen(str1) + strlen(str1) - 1; ++n1)
			printf("%5d", temp[n1]);
		printf("\n");
		temp = divided(temp, strlen(str1) * 3 - 2, 6);
		for(int n1 = 0; n1 < strlen(str1) * 3 - 2; ++n1)
			printf("%5d", temp[n1]);
		printf("\n");
		temp = mod(temp, strlen(str1) * 3 - 2, 7);
		printf("%5d", temp[0]);


	}
	return 0;
}

int *multiply(int *num1, int length1, int *num2, int length2)
{

	int *product = malloc(sizeof(int) * 128);
	memset(product, 0, sizeof(int) * 128);
	for(int n1 = 0; n1 < length1; ++n1)
	{
		for(int n2 = 0; n2 < length2; ++n2)
		{
			product[n1 + n2] += num1[n1] * num2[n2];
		}
	}
	return product;
}



int *divided(int *num1, int length1, int num2)
{
	int *result = malloc(sizeof(int) * 128);
	memset(result, 0, sizeof(int) * 128);

	for(int n1 = length1 - 1; n1 >= 0; --n1)
	{
		num1[n1] += num1[n1 + 1] * 10;
		num1[n1 + 1] = 0;
		result[n1] = num1[n1] / num2;
		num1[n1] %= num2;
	}
	return result;
}

int *mod(int *num1, int length1, int num2)
{
	int *result = malloc(sizeof(int) * 128);
	memset(result, 0, sizeof(int) * 128);

	for(int n1 = length1 - 1; n1 >= 0; --n1)
	{
		num1[n1] += num1[n1 + 1] * 10;
		num1[n1 + 1] = 0;
		result[n1] = num1[n1] % num2;
		num1[n1] %= num2;
	}
	return result;
}

