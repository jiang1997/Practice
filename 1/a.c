#include <stdio.h>

int main(void)
{
	int n = 9, num[25];
	scanf("%d", &n);
	n = n / 2 + 1;
	int n1 = 0;
	for(n1 = 1; n1 <= n; ++n1)
	{
		num[n1 - 1] = n1;
	}

	for(n1 = 0; n1 < n; ++n1)
	{
		print_line(num, n, n1 + 1);
	}
	for(n1 = n - 1; n1 > 0; --n1)
	{
		print_line(num, n, n1);
	}


	printf("\n");
	return 0;
}

int print_line(int *num, int length, int flag)
{
	int index = 0;
	for(index = 0; index < length; ++index)
	{
		if(num[index] < flag)
			printf("%d", flag);
		else
			printf("%d", num[index]);
	}

	for(index = length - 2; index >= 0; --index)
	{
		if(num[index] < flag)
			printf("%d" ,flag);
		else
			printf("%d", num[index]);
	}
	printf("\n");
}



