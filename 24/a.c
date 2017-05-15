#include <stdio.h>

int main(void)
{
	int T = 0;
	scanf("%d", &T);
	for(int t = 0; t < T; ++t)
	{
		char str1[8], str2[8];
		scanf("%s %s", str1, str2);
		if(str1[0] < str2[0])
		{
			printf("< ");
		}
		else if(str1[0] == str2[0])
		{
			printf("= ");
		}
		else
		{
			printf("> ");
		}

		int temp = 3, n = 0;
		temp += (str1[0] == str2[0] && str1[1] == str2[1]);
		for(n = 0; n < temp; ++n)
		{
			if(str1[2 + n] < str2[2 + n])
			{
				printf("<");
				break;
			}
			else if(str1[2 + n] > str2[2 + n])
			{
				printf(">");
				break;
			}
		}
		if(n == temp)
			printf("=");
	}
	return 0;
}
