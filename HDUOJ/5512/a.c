#include <stdio.h>

int main(void)
{
	int T = 0, *record = NULL;
	record = malloc(40000 * sizeof(int));
	scanf("%d", &T);
	for(int t = 0; t < T; ++t)
	{
		int n = 0, a = 0, b = 0, count = 0;
		memset(record, 0, 40000 * sizeof(int));
		scanf("%d %d %d", &n, &a, &b);
		
		for(int x = 0; x <= n / a; ++x)
		{
			for(int y = 0; y <= n / b; ++y)
			{
				record[x * a + y * b] = 1;
			}
		}

		for(int n1 = 1; n1 <= n; ++n1)
		{
			count += record[n1];
		}
		printf("%d\n", count);

	}
	return 0;
}
