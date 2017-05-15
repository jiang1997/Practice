#include <stdio.h>

int main(void)
{
	int T = 0, N = 0;
	scanf("%d", &T);
	for(int t = 0; t < T; ++t)
	{
		int sum = 0, maximum = 0;
		scanf("%d", &N);
		for(int n1 = 0; n1 < N; ++n1)
		{
			int temp = 0;
			scanf("%d", &temp);
			sum += temp;
			maximum = maximum < temp? temp: maximum;
		}
		if(sum - maximum >= maximum - 1)
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}
