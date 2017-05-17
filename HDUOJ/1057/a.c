#include <stdio.h>

void pass();


int dir[5][2] = {0, 1, 0, -1, 1, 0, -1, 0, 0, 0};
char c[4] = {'.', '!', 'X', '#'};
int DNA[16] = {0}, dish[20][20] = {0};
int main(void)
{
	int T = 0,D = 0;

	scanf("%d", &T);
	for(int t = 0; t < T; ++t)
	{
	scanf("%d", &D);

	for(int n = 0; n < 16; ++n)
	{
		scanf("%d", &DNA[n]);
	}

	for(int row = 0; row < 20; ++row)
	{
		for(int column = 0; column < 20; ++column)
		{
			scanf("%d", &dish[row][column]);
		}
	}

	while(D--)
	{
		pass();
	}
	
	if(t) printf("\n");
	for(int row = 0; row < 20; ++row)
	{
		for(int column = 0; column < 20; ++column)
		{
			printf("%c", c[dish[row][column]]);
		}
		printf("\n");
	}
	}
	return 0;
}

void pass()
{
	int temp[20][20] = {0};
	for(int row = 0; row < 20; ++row)
	{
		for(int column = 0; column < 20; ++column)
		{
			int K = 0;
			for(int n = 0; n < 5; ++n)
			{
				if(row + dir[n][0] < 20 && row + dir[n][0] >= 0 && column + dir[n][1] < 20 && column + dir[n][1] >= 0)
					K += dish[row + dir[n][0]][column + dir[n][1]];
			}

			temp[row][column] = dish[row][column] + DNA[K];

			if(temp[row][column] < 0)
			{
				temp[row][column] = 0;
			}
			else if(temp[row][column] > 3)
			{
				temp[row][column] = 3;
			}
		}
	}
	
	for(int row = 0; row < 20; ++row)
	{
		for(int column = 0; column < 20; ++column)
		{
			dish[row][column] = temp[row][column];
		}
	}
}


