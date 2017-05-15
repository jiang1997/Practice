#include <stdio.h>

int Hash(int Num, int K);
int main(int argc, char **args)
{
	int array[1000], recorder[1000] = {0}, result[1000], N, count = 0;
	scanf("%d", &N);
	for(int n = 0; n < N; ++n)
		scanf("%d", &array[n]);


	for(int n = 0; n < N; ++n)
	{
		int pssbl_Index = -1, minimum = 100000000;
		for(int m = 0; m < N; ++m)
		{
			int index = Hash(array[m], N);	
			if(array[index] < 0 || recorder[m] == 1) continue;

			for(;index % N != m && recorder[index % N] == 1; ++index) ;

			index %= N;
			if(index == m && array[index] < minimum)
			{
				minimum = array[index];
				pssbl_Index = index;
			}
		}
		if(pssbl_Index != -1)
		{
			recorder[pssbl_Index] = 1;
			result[count++] = minimum;
		}
	}
	for(int n = 0; n < count; ++n)
	{
		if(n) printf(" ");
		printf("%d", result[n]);
	}
	return 0;
}

int Hash(int Num, int K)
{
	return Num % K;
}


