#include <stdio.h>

int main(void)
{
	int T = 0, *record = NULL;
	record = (int *)malloc(20000 * sizeof(int));
	scanf("%d", &T);
	for(int t = 0; t < T; ++t)
	{
		int n = 0, a = 0, b = 0, temp = 0, num = 0;
		scanf("%d %d %d", &n, &a, &b);
		temp = a;
		if(a > b)
		{
			a = b;
			b = temp;
		}
		for(int n1 = 1; n1 < a && n1 <= n / b; ++n1)
		{
			temp = temp < n1 * b % a? temp: n1 * b % a;	
		}
		num = n / temp;
		num -= (a % temp == 0);
		num -= (b % temp == 0);
		printf("%d\n", num % 2);
	}
	return 0;
}
