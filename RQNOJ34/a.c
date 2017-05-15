#include <stdio.h>



int n = 0, map[1000][1000] = {0};

int main(void)
{
	int origin[2] = {0}, dest[2] = {0};
	scanf("%d", &n);

	for(int n1 = 0; n1 < n; ++n1)
	{
		for(int n2 = 0; n2 < n; ++n2)
		{
			scanf("%d", &map[n1][n2]);
		}
	}
	scanf("%d %d", origin + 0, origin + 1);
	scanf("%d %d", dest + 0, dest + 1);
	--(origin[0]);
	--(origin[1]);
	--(dest[0]);
	--(dest[1]);
	printf("origin %d %d\ndest %d %d\n", origin[0], origin[1], dest[0], dest[1]);
	map[origin[0]][origin[1]] = 'a';
	printf("%d\n",bfs(origin, dest, 'a') - 'a');
	return 0;
}


int bfs(int *origin, int *dest, int flag)
{
	for(int n1 = 0; n1 < n; ++n1)
	{
		for(int n2 = 0; n2 < n; ++n2)
		{
			if(map[n1][n2] == flag)
			{
				if(n1 > 0 && map[n1 - 1][n2] == 0)
					map[n1 - 1][n2] = flag + 1;

				if(n1 < n - 1 && map[n1 + 1][n2] == 0)
					map[n1 + 1][n2] = flag + 1;

				if(n2 > 0 && map[n1][n2 - 1] == 0)
					map[n1][n2 - 1] = flag + 1;

				if(n2 < n - 1 && map[n1][n2 + 1] == 0)
					map[n1][n2 + 1] = flag + 1;

			}
		}
	}
	++flag;
	if(map[dest[0]][dest[1]] != 0)
		return flag;
	bfs(origin, dest, flag);
}

