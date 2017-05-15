#include <stdio.h>

int main(void)
{
	int n = 0;
	scanf("%d", &n);
	for(int n1 = 1; n1 <= n; n1 += 2)
	{
		for(int n2 = (n - n1) / 2; n2 > 0; --n2)
		{
			printf(" ");
		}
		for(int n2 = n1; n2 > 0; --n2)
		{
			printf("*");
		}
		printf("\n");
	}
	for(int n1 = n - 2; n1 >= 1; n1 -= 2)
	{
		for(int n2 = (n - n1) / 2; n2 > 0; --n2)
		{
			printf(" ");
		}
		for(int n2 = n1; n2 > 0; --n2)
		{
			printf("*");
		}
		printf("\n");
	}
	return 0;
}
