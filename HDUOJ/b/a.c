#include <stdio.h>


void rotate90(int src[][30], int dest[][30]);

int n = 0;

int main(void)
{
	int src[30][30] = {0}, r0[30][30] = {0}, r90[30][30] = {0}, r180[30][30] = {0}, r270[30][30] = {0};
	scanf("%d", &n);
	for(int x = 0; x < n; ++x)
	{
		for(int y = 0; y < n; ++y)
		{
			scanf("%d", &src[x][y]);
		}
	}
	for(int x = 0; x < n; ++x)
	{
		for(int y = 0; y < n; ++y)
		{
			scanf("%d", &r0[x][y]);
		}
	}

	int c0 = 0,c90 = 0, c180 = 0, c270 = 0, maximum = 0;
	rotate90(r0, r90);
	rotate90(r90, r180);
	rotate90(r180, r270);
	for(int x = 0; x < n; ++x)
	{
		for(int y = 0; y < n; ++y)
		{
			c0 += (r0[x][y] == src[x][y]);
			c90 += (r90[x][y] == src[x][y]);
			c180 += (r180[x][y] == src[x][y]);
			c270 += (r270[x][y] == src[x][y]);
		}
	}
	maximum = c90 > c180? c90: c180;
	maximum = maximum < c270? c270: maximum;
	maximum = maximum < c0? c0: maximum;
	printf("%d\n", maximum);


	return 0;
}

void rotate90(int src[][30], int dest[][30])
{
	for(int x = 0; x < n; ++x)
	{
		for(int y = 0; y < n; ++y)
		{
			dest[y][n - x - 1] = src[x][y];
		}
	}

}


