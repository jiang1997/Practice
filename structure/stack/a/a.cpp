#include <stdio.h>
#include <iostream>

using namespace std;

int main(void)
{
	int M = 0, N = 0, K = 0;
	scanf("%d %d %d", &M, &N, &K);

	for(int k = 0; k < K; ++k)
	{
		int stack[2000] = {0}, top = 0, sequence[2000] = {0};
		int maximum = 0, n = 0;
		for(n = 0; n < N; ++n)
			scanf("%d", &sequence[n]);	
		for(n = 0; n < N; ++n)
		{
			if(sequence[n] > maximum)
			{
				for(int num = maximum + 1; num < sequence[n]; ++num)
				{
					stack[top++] = num;
				}
				if(top + 1 > M)
					break;
				maximum = sequence[n];
			}
			else if(sequence[n] != stack[--top])
			{
				break;
			}
		}
		
		cout << ((n != N)? "NO": "YES") << '\n';


	}
	return 0;
}








