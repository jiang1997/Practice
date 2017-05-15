#include <stdio.h>

int main(void)
{
	int T = 0;
	scanf("%d", &T);
	for(int t = 0; t < T; ++t)
	{
		int n = 0, level = 0;
		scanf("%d", &n);
		for(int n1 = 0; n1 < n; ++n1)
		{
			int temp = 0;
			scanf("%d", &temp);
			level += temp > 6000;
		}
		printf("%d\n", level);
	}
	return 0;
}
