#include <stdio.h>


//	1928 5-1 Tuesday 2
int main(void)
{
	int T = 0, result[] = {6, 9, 6, 5, 5, 5, 5};
	scanf("%d", &T);
	for(int t = 0; t < T; ++t)
	{
		int ty = 0, d = 2;
		scanf("%d", &ty);
		for(int y = 1929; y <= ty; ++y)
		{
			int temp = (y % 400 == 0 || y % 4 == 0 && y % 100 != 0); 
			temp += 365;
			d += temp;
			d %= 7;
		}
		printf("%d\n", result[d]);
	}
	return 0;
}
