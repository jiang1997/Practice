#include <stdio.h>

int main(void)
{
	int T = 0;
	scanf("%d", &T);
	for(int t = 0; t < T; ++t)
	{
		int a = 0, b = 0, c = 0, d = 0;
		scanf("%d %d %d %d", &a, &b, &c, &d);
		printf("%d %d\n", c, b + d);
		printf("%d %d\n", a, b + d);

	}
	return 0;
}
