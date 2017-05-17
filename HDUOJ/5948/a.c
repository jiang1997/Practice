#include <stdio.h>

int main(void)
{
	int T = 0;
	scanf("%d", &T);
	for(int t = 0; t < T; ++t)
	{
		int a = 0, b = 0, c = 0;
		scanf("%d %d", &a, &b);
		c = a + b + (a > b? a: b);
		printf("%d\n", c);
	}
}
