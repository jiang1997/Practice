#include <stdio.h>

int main(void)
{
	int T = 0;
	scanf("%d", &T);
	for(int t = 0; t < T; ++t)
	{
		int a = 0, b = 0, c = 0, count = 0;
		scanf("%d %d %d", &a, &b, &c);
		for(int n = 1; n * a <= c; ++n)
		{
			if((c - n * a) % b == 0 && (c - n * a) != 0)
				count += 1;
		}
		printf("%d\n", count);
	}
	return 0;
}
