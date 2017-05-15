#include <stdio.h>
#include <math.h>

int main(void)
{
	int n = 0;
	scanf("%d", &n);
	for(int n1 = 2; n1 <= n / 2; ++n1)
	{
		if(isPrime(n1) && isPrime(n - n1))
		{
			printf("%d=%d+%d", n, n1, n - n1);
			break;
		}
	}
	return 0;
}


int isPrime(int num)
{
	for(int n1 = 2; n1 <= sqrt(num); ++n1)
	{
		if(num % n1 == 0)
			return 0;
	}
	return 1;
}

