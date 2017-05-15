#include <stdio.h>

int main(void)
{
	int T = 0;
	scanf("%d", &T);
	for(int t = 0; t < T; ++t)
	{
		int N = 0, M = 0, length = 0;
		scanf("%d %d", &N, &M);
		int flag = 2 * (N % 2 == 0 || M % 2 == 0);
		length = (N + M) * 2 - 4;
		int result = (length / 2 - flag) * 8 + flag * 4 + (M * N - length) / 2 * 16;
		printf("%d\n", result);
	}
	return 0;
}
