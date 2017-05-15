#include <stdio.h>

void dfs(int num);

int count = 1; 
int main(void)
{
	int num = 0;
	scanf("%d", &num);
	dfs(num);
	printf("%d", count);
}

void dfs(int num)
{
	for(int n1 = num / 2; n1 > 0; --n1)
	{
		++count;
		if(n1 > 1)
			dfs(n1);
	}
}

