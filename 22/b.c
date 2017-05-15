#include <stdio.h>

int main(void)
{
	int N = 0, Maximum = 0, sum = 0, Max_left = 0, Max_right = 0;
	scanf("%d", &N);
	Max_right = N;
	for(int n = 0; n < N; ++n)
	{
		int temp = 0;	
		scanf("%d", &temp);
		sum += temp;	
		if(Maximum < sum)
		{
			Max_right = n;
			Maximum = sum;
		}
		if(sum < 0)
		{
			sum = 0;
			Max_left = n + 1;
		}

	}
	printf("%d %d %d", Maximum, Max_left, Max_right); 
	return 0;
}
