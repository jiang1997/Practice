#include <stdio.h>
#include <math.h>


int N = 0, M = 0;
int f();

int main(void)
{
	int T = 0;
	scanf("%d", &T);
	for(int t = 0; t < T; ++t)
	{
		scanf("%d %d", &N, &M);	
		int result = f();
		printf("%d\n", result);
	}
	return 0;
}


int f()
{
	int direction[4][2] = {0};
	direction[0][0] = 0;
	direction[0][1] = 1;
	direction[1][0] = 0;
	direction[1][1] = -1;
	direction[2][0] = 1;
	direction[2][1] = 0;
	direction[3][0] = -1;
	direction[3][1] = 0;
	
	int map[100][100] = {0};

	int result = 0;
	for(int n1 = 0; n1 < N; ++n1)
	{
		for(int n2 = (n1 % 2 != 0); n2 < M; n2 += 2)
		{
			int count = 0;
			for(int n3 = 0; n3 < 4; ++n3)
			{
				int x = direction[n3][0] + n1;
				int y = direction[n3][1] + n2;
				count += (x < N && x >= 0 && y < M && y >= 0);
			}
			result += pow(2, count);
			
		}
	}
	return result;
}

