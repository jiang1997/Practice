#include <stdio.h>

int main(void)
{
	int T = 0, *record = NULL;
	char *sequence = NULL;
	sequence = malloc(100000);
	record = malloc(sizeof(int) * 100000);
	scanf("%d", &T);
	for(int t = 0; t < T; ++t)
	{
		int length = 0, maximum = 0, local_max = 0;
		memset(record, 0, sizeof(int) * 100000);
		scanf("%s", sequence);	
		length = strlen(sequence);
		for(int n1 = 0; n1 < length; ++n1)
		{
			for(int n2 = n1; n2 >= 0; --n2)
			{
				if(sequence[n2] < sequence[n1])	
				{
					if(record[n1] < record[n2] + 1)
						record[n1] = record[n2] + 1;
					maximum = record[n1] > maximum? record[n1]: maximum;
				}
			}
		}
		printf("%d\n", maximum + 1);


	}
	return 0;
}
