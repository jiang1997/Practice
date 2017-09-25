#include <stdio.h>
#include <stdlib.h>

int isOK(int Num);
void init_recorder();
int *recorder;
int main(int argc, char **args)
{
	int N, M;
	init_recorder();
	//printf("%d %d\n", isOK(100), isOK(54));
	//printf("%d\n", recorder[100]);
	
	while(scanf("%d%d", &N, &M), N != 0 && N != M)
	{
		printf("%d\n", recorder[M] - recorder[N] + isOK(N));
	}
	
	return 0;
}

void init_recorder()
{
	recorder = (int *)malloc(sizeof(int) * 2000000);
	recorder[0] = 0;
	for(int n = 1; n < 1000000; ++n)
	{
		recorder[n] = recorder[n - 1] + isOK(n);
	}
}

int isOK(int Num)
{
	int flag = 1;
	while(Num > 0)
	{
		if(Num % 10 == 4 || Num % 10 == 2 && Num / 10 % 10 == 6)
		{
			flag = 0;
			break;
		}
		Num /= 10;
	}
	return flag;
}

