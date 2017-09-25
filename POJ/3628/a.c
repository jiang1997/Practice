#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **args)
{
	int N = 0, H[100], B = 0, *recorder = NULL, sum = 0, temp = 0;
	scanf("%d %d", &N, &B);
	for(int n = 0; n < N; ++n)
	{
		scanf("%d", &H[n]);
		sum += H[n];
	}
	recorder = (int *)malloc(sizeof(int) * (sum + 1));
	memset(recorder, 0, sizeof(int) * (sum + 1));
	for(int n = 0; n < N; ++n)
	{
		for(int b = sum; b >= H[n]; --b)
		{
			if(recorder[b] < recorder[b - H[n]] + H[n])
				recorder[b] = recorder[b - H[n]] + H[n];
		}
	}
	
	for(temp = B; recorder[temp] < B; ++temp) ;
	printf("%d", recorder[temp] - B);
	return 0;
}
