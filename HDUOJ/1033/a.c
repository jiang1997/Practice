#include <stdio.h>
#include <string.h>

int main(void)
{
	int direction[4][2] = {10, 0, 0, -10, -10, 0, 0, 10}; //left down right up
	char cmd[256];

	while(scanf("%s", cmd) != EOF)
	{
		int l = 0, dir = 300, x = 310, y = 420;
		printf("300 420 moveto\n310 420 lineto\n");

		for(;cmd[l] != '\0'; ++l)
		{
			if(cmd[l] == 'A')	
			{
				++dir;
			}
			else
			{
				--dir;
			}

			x += direction[dir % 4][0];
			y += direction[dir % 4][1];
			printf("%d %d lineto\n", x, y);
		}
		printf("stroke\n");
		printf("showpage\n");
	}
	return 0;
}
