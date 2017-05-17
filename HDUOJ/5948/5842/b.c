#include <stdio.h>

int main(void)
{
	int T = 0;
	char *sequence = NULL;
	sequence = (char *)malloc(100000);
	scanf("%d", &T);
	for(int t = 0; t < T; ++t)
	{
		int record[26] = {0}, length = 0, maximum = 0;
		memset(sequence, 0, 100000);
		scanf("%s", sequence);
		length = strlen(sequence);
		for(int n1 = 0; n1 < length; ++n1)
		{
			++record[sequence[n1] - 'a'];
		}
		for(int n1 = 0; n1 < 26; ++n1)
		{
			maximum += (record[n1] != 0);	
		}
		printf("%d\n", maximum);
		

	}
	return 0;
}
