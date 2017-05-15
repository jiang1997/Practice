#include <stdio.h>


int n = 0, m = 0, map[64][64] = {0};
int record[64][64] = {0};
int main(void)
{
	memset(record, 1,64 * 64 * sizeof(in));
	scanf("%d %d", &n, &m);
	for(int n1 = 0; n1 < n; ++n1)
	{
		for(int m1 = 0; m1 < m; ++m1)
		{
			scanf("%d", &(map[n1][m1]));
		}
	}

	return 0;
}


int dfs(int pn, int pm, int cn, int cm)
{
	int shape = map[cn][cm];
	if(cn + 1 < n && record[cn + 1][cm] == 0)
	{
		if(shape > 4)
		{
			if(cn - pn == 1)
			{
				map[cn][cm] = 6;	
				record[cn][cm] = 1;
				dfs(cn, cm, cn + 1, cm);	
				record[cn][cm] = 0;
			}
		}
		else
		{
			if(cm - pm != 0)	
			{
				map[cn][cm] = cm - pm == 1? 4: 1;
				recoed[cn][cm] = 1;
				dfs(cn, cm, cn + 1, cm);
				record[cn][cm] = 0;
			}
			map[cn][cm] = shape;

		}
		
	}
	if(cn > 1 && record[cn - 1][cm] == 0)
	{
		if(shape > 4)
		{
			if(cn - pn == -1)
			{
				map[cn][cm] = 6;	
				record[cn][cm] = 1;
				dfs(cn, cm, cn - 1, cm);	
				record[cn][cm] = 0;
			}
		}
		else
		{
			if(cm - pm != 0)	
			{
				map[cn][cm] = cm - pm == 1? 3: 2;
				recoed[cn][cm] = 1;
				dfs(cn, cm, cn - 1, cm);
				record[cn][cm] = 0;
			}
			map[cn][cm] = shape;

		}
	}
	if(cm + 1 < m && record[cn][cm + 1] == 0)
	{
		if(shape > 4)
		{
			if(cm - pm == 1)
			{
				map[cn][cm] = 5;	
				record[cn][cm] = 1;
				dfs(cn, cm + 1, cn, cm);	
				record[cn][cm] = 0;
			}
		}
		else
		{
			if(cn - pn != 0)	
			{
				map[cn][cm] = cn - pn == 1? 1: 2;
				recoed[cn][cm] = 1;
				dfs(cn, cm + 1, cn, cm);
				record[cn][cm] = 0;
			}
			map[cn][cm] = shape;

		}
		
	}	
	if(cm > 0 && record[cn][cm - 1] == 0)
	{
		if(shape > 4)
		{
			if(cm - pm == -1)
			{
				map[cn][cm] = 5;	
				record[cn][cm] = 1;
				dfs(cn, cm - 1, cn, cm);	
				record[cn][cm] = 0;
			}
		}
		else
		{
			if(cn - pn != 0)	
			{
				map[cn][cm] = cn - pn == 1? 4: 3;
				recoed[cn][cm] = 1;
				dfs(cn, cm - 1, cn, cm);
				record[cn][cm] = 0;
			}
			map[cn][cm] = shape;
		}

		
	}	
}

