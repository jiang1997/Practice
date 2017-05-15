#include <stdio.h>

int main(void)
{
	int N = 0, Maximum = 0, sum = 0;
	scanf("%d", &N);
	for(int n = 0; n < N; ++n)
	{
		int temp = 0;	
		scanf("%d", &temp);
		sum += temp;	
		Maximum = Maximum < sum? sum: Maximum;
		sum = sum < 0? 0: sum;

	}
	printf("%d",Maximum); 
	return 0;
}
