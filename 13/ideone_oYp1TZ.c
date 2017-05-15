#include <stdio.h>
#include <string.h>

int circumgyrate(int degree, char *str);
int main(void)
{
	char str[100];
	int n = 0;
	while(scanf("%s %d", str, &n) != EOF)
	{
		if(n < 0)
			n = 8 - (n * -1 % 8);
		circumgyrate(n % 8 * 45, str);
	}
	
	return 0;
}

int circumgyrate(int degree, char *str)
{
	char mirror_str[100];
	for(int n1 = strlen(str) - 1; n1 >= 0; --n1)
		mirror_str[strlen(str) - 1 - n1] = str[n1];
	mirror_str[strlen(str)] = 0;

	switch(degree)
	{
		case 45 * 4:
			str = mirror_str;
		case 45 * 0:
			printf("%s\n", str);
			break;

		case 45 * 3:
			str = mirror_str;
		case 45 * 7:
			for(int n1 = 0; n1 < strlen(str); ++n1)
			{
				for(int n2 = 0; n2 < n1; ++n2)
				{
					printf(" ");
				}
				printf("%c\n", str[n1]);
			}
			break;
		case 45 * 2:
			str = mirror_str;
		case 45 * 6:
			for(int n1 = 0; n1 < strlen(str); ++ n1)
			{
				for(int n2 = 0; n2 < strlen(str) / 2; ++n2)
					printf(" ");
				printf("%c\n", str[n1]);
			}
			break;

		case 45 * 1:
			str = mirror_str;
		case 45 * 5:
			for(int n1 = 0;n1 < strlen(str); ++n1)
			{
				for(int n2 = strlen(str) - 1 - n1 - 1; n2 >= 0; --n2)
				{
					printf(" ");
				}
				printf("%c\n",str[n1]);
			}
			break;
	}
	return 0;
}

