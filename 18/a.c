#include <stdio.h>

//1928 5-1   Tuesday  2
int main(void)
{
	int T = 0, result[] = {}, num = 5;
	for(int y = 2015; y > 1928; --y)
	{
		int d = (y % 400 == 0 || y % 4 == 0 && y % 100 != 0);	
		d += 365;
		num = (num - d + 7 * 70) % 7;
		printf("%d\n", num);

	}
	return 0;
}
