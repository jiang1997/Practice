#include <stdio.h>

int main(void)
{
	int T = 0;
	char data[100000] = {0};
	scanf("%d", &T);
	for(int t = 0; t < T; ++t)
	{
		int num = 0, record[10000] = {-1}, count = 0, minimum = 100001;
		char target = 'B';
		scanf("%s", data);
		num = strlen(data);
		for(int n1 = 0; n1 < num; ++n1)
		{
			if(data[n1] == target)
			{
				record[count] = n1;
				++count;
			}
		}

		for(int n1 = 0; n1 < count; ++n1)
		{
			for(int n2 = n1; n2 < count; ++n2)
			{
				if(record[n2] - record[n1] + 1 <= count)
				{
					int cost = count - (n2 - n1 + 1);
					minimum = minimum < cost? minimum: cost;
				}
				else
					break;
			}

			for(int n2 = count - 1; n2 > n1; --n2)
			{
				if(num - (record[n2] - record[n1] + 1) + 2 <= count)
				{
					int cost = count - (count - (n2 - n1 + 1) + 2);
					minimum = minimum < cost? minimum: cost;
				}
				else
					break;
			}
		}
		printf("Case %d: %d\n", t + 1, minimum);
	
	}
	return 0;
}
