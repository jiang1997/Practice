#include <stdio.h>

int main(void)
{
	int M = 0, k = 0;
	while(scanf("%d %d", &M, &k), M + k != 0)
	{
		int temp = M / k;
		for(; (M + temp) / k != temp;)
		{
			temp = (M +temp) / k;	
		}
		printf("%d\n", M + temp);
	}
	return 0;
}
