#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
	int T = 0, *recorder = NULL, *result = NULL;
	char *S = NULL;
	S = (char *)malloc(sizeof(char) * 200000);
	recorder = (int *)malloc(sizeof(int) * 200000);
	result = (int *)malloc(sizeof(int) * 200000);
	
	scanf("%d", &T);
	for(int t = 0; t < T; t++)
	{
		int num_A = 0, length = 0, maximum = 0;
		scanf("%s", S);	
		length = strlen(S);

		for(int n = 0; n < length; ++n)
		{
			num_A += S[n] == 'A';
			recorder[n] = num_A;
		}
/*
		for(int n = 0; n < length; ++n)
		{
			printf("%d ", recorder[n]);
		}
		printf("\n");

		if(num_A == 0 || length == 1)
		{
			printf("Case %d: %d\n", t + 1, 0);
			continue;
		}
*/
		for(int n = 0; n < length; ++n)
		{
			int dst = (n + num_A - 1 + length) % length;
			int num = recorder[dst] - recorder[n];
			num += dst < n? recorder[length - 1]: 0;
			num += S[n] == 'A';

			maximum = num > maximum? num: maximum;

		}

		printf("Case %d: %d\n", t + 1, num_A - maximum);

	}
	return 0;
}
