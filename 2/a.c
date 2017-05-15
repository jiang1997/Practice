#include <stdio.h>
#include <math.h>

int main(void)
{
	int num1, num2;
	scanf("%d %d", &num1, &num2);
	int n1 = 0;
	for(n1 = num1 < 4?4: num1; n1 <= num2; ++n1)
	{
		int sum = 0, n2 = 0;
		for(n2 = 2; n2 < sqrt(n1); ++n2)
		{
			if(n1 % n2 == 0)
			{
				sum += n2;
				sum += n1 / n2;
			}
		}
		if(sum + 1 == n1)
		{
			printf("%d\n",n1);
		}
	}
	return 0;
}


