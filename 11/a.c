#include <stdio.h>

{
	int T = 0;
	scanf("%d", &T);
	for(int t = 0; t < T; ++t)
	{
		int num = 0, total = 0, sum = 0;
		scanf("%d %d", &num, &total);
		for(int n1 = 0; n1 <= num; ++n1)
		{
			for(int n2 = 0; n2 <= num - n1; ++n2)
			{
				if(n1 * 5 + n2 * 2 + num - n1 -n2 == total)
					++sum;
			}
		}
		printf("%d\n", sum);
		return 0;
	}
	return 0;
}
