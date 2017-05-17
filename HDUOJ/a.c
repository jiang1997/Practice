#include <stdio.h>
#include <string.h>

int main(void)
{
	char str[8000];
	int record[8000];
	while(scanf("%s", str) != EOF)
	{

		for(char *str1 = strstr(str, "Apple"); str1 != NULL; str1 = strstr(str1, "Apple"))
		{
			record[str1 - str] = 1;
			++str1;
		}
		
		for(char *str1 = strstr(str, "IPod"); str1 != NULL; str1 = strstr(str1, "IPod"))
		{
			record[str1 - str] = 1;
			++str1;
		}

		for(char *str1 = strstr(str, "IPad"); str1 != NULL; str1 = strstr(str1, "IPad"))
		{
			record[str1-str] = 1;
			++str1;
		}


		for(char *str1 = strstr(str, "IPhone"); str1 != NULL; str1 = strstr(str1, "IPhone"))
		{
			record[str1 - str] = 1;
			++str1;
		}

		for(char *str1 = strstr(str, "Sony"); str1 != NULL; str1 = strstr(str1, "Sony"))
		{
			record[str1 - str] = 2;
			++str1;
		}


		for(int index = 0; index < strlen(str); ++index)
		{
			if(record[index] == 1)
				printf("MAI MAI MAI!\n");
			else if(record[index] == 2)
				printf("SONY DAFA IS GOOD\n");
		}
		memset(record, 0, sizeof(int) * 8000);

	}
	return 0;
}
