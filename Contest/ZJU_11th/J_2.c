#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int *multiply(int *num1, int length1, int *num2, int length2);
int *divided(int *num1, int length1, int num2);
int mod(int *num1, int length1, int num2);

int *num1 = NULL, *num2 = NULL;

int main(void)
{
	int T = 0;
	int length1 = 0, length2;
	int sum[100] = {0};
	sum[1] = 1;
	for(int n = 2; n < 100; ++n)
	{


		int temp = n;
		num1 = malloc(sizeof(int) * 256);
		num2 = malloc(sizeof(int) * 256);
		memset(num1, 0, sizeof(int) * 256);
		memset(num2, 0, sizeof(int) * 256);
		
		printf("n:%d\n", n);
		for(length1 = 0; temp > 0; ++length1)
		{
			num1[length1] = temp % 10;
			num2[length1] = num1[length1];
			temp /= 10;
		}
		length2 = length1;
		for(int n1 = 1; n1 < n; ++n1)
		{
			
			int *temp = multiply(num1, length1, num2, length2);	
			free(num1);
			num1 = temp;
			length1 += length2;
		}
	//	for(int n1 = 0; n1 < length1; ++n1)
	//		printf("%3d", num1[n1]);
	//	printf("\n");
		sum[n] = (mod(num1, length1, 7) + sum[n - 1]) % 7;
		printf("%d\n", sum[n]);
		free(num1);
		free(num2);
	}

	
	return 0;
}

int *multiply(int *num1, int length1, int *num2, int length2)
{

	int *product = malloc(sizeof(int) * 256);
	memset(product, 0, sizeof(int) * 256);
	for(int n1 = 0; n1 < length1; ++n1)
	{
		for(int n2 = 0; n2 < length2; ++n2)
		{
			product[n1 + n2] += num1[n1] * num2[n2];
			product[n1 + n2 + 1] += product[n1 + n2] / 10;
			product[n1 + n2] %= 10;
		}
	}
	return product;
}



int *divided(int *num1, int length1, int num2)
{
	int *result = malloc(sizeof(int) * 256);
	memset(result, 0, sizeof(int) * 256);

	for(int n1 = length1 - 1; n1 >= 0; --n1)
	{
		num1[n1] += num1[n1 + 1] * 10;
		num1[n1 + 1] = 0;
		result[n1] = num1[n1] / num2;
		num1[n1] %= num2;
	}
	return result;
}

int mod(int *num1, int length1, int num2)
{
	int *result = malloc(sizeof(int) * 256);
	memset(result, 0, sizeof(int) * 256);

	for(int n1 = length1 - 1; n1 >= 0; --n1)
	{
		num1[n1] += num1[n1 + 1] * 10;
		num1[n1 + 1] = 0;
		result[n1] = num1[n1] % num2;
		num1[n1] %= num2;
	}
	return result[0];
}

