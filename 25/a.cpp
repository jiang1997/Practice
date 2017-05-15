#include <stdio.h>
#include <string.h>

int lcs(int x, int y, int weight);

int record[100][100] = {0};
char str1[] = "1223456", str2[] = "1234";

int main(void)
{
	//char *str1 = NULL, *str2 = NULL;	
	//str1 = (char *)malloc(sizeof(20000));
	//str2 = (char *)malloc(sizeof(20000));

	for(int n1 = 0; n1 < strlen(str1); ++n1)
	{
		for(int n2 = 0; n2 < strlen(str2); ++n2)
		{
			record[n1][n2] = (str1[n1] == str2[n2]);
		}
	}

	for(int n1 = 0; n1 < strlen(str1); ++n1)
	{
		for(int n2 = 0; n2 < strlen(str2); ++n2)
		{
			printf("%d ", record[n1][n2]);
		}
		printf("\n");
	}



	
	return 0;
}

int lcs(int x, int y)
{
	if(record[x][y] == 1)
	{
		lcs(x + 1, y + 1);
	}
	else
	{
		for(int n = x; n < )
		{
		}

		for()
		{
		}
	}
}

