#include <stdio.h>
#include <string.h>

int main(int argc, char **args)
{
	int N = 0;
	char str[200];
	scanf("%d", &N);
	while(N--)
	{
		int num[10000] = {0}, l = 0, length = 1, n = 0;
		while(scanf("%s", str), str[0] != '0')
		{
			int index = 0;
			length = strlen(str) > length? strlen(str): length;
			for(l = strlen(str) - 1; l >= 0; --l)
				num[index++] += str[l] - '0';
		}
		for(n = 0; n < length || num[n] != 0; ++n)
		{
			num[n + 1] += num[n] / 10;
			num[n] %= 10;
		}
		for(--n; n >= 0; --n)
		{
			printf("%d", num[n]);
		}
		printf("\n");
		if(N) printf("\n");
	}
	return 0;
}


