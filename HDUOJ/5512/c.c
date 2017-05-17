#include <stdio.h>

int main(void)
{
	int T = 0;
	scanf("%d", &T);
	for(int t = 0; t < T; ++t)
	{
		int n = 0, a = 0, b = 0;
		int x = 0, y = 0, temp = 0;
		scanf("%d %d %d",&n, &a, &b);
		temp = a;
		if(a > b)
		{
			a = b;
			b = temp;
		}
		x = a;
		y = b;

		do
		{
			temp = y % x;
			y = x;
			x = temp;

		}while(x != 0);

		printf("%d\n", a / y + (n - a) / y - 1);
	}
}
