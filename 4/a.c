#include <stdio.h>

int main(void)
{
	int m = 0, n = 0, x = 0, y = 0;
	int k = 0;
	
	scanf("%d", &k);
	for(int n1 = 1; n1 * 9 <= 100; ++n1)
	{
		m = k - n1 * 9;
		n = k - n1 * 2;
		x = n - 2 * m;
		if(x % 2 != 0)
			continue;
		x /= 2;
		y = m - x;
		if(9 * n1 + x + y == k && 2 * n1 + 2 * y + 4 * x == k)
		{
			if(x > 0 && y > 0)
				printf("%d %d %d\n", n1, y, x);
		}
	}
}
