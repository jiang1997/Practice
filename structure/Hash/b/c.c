#include <stdio.h>

int main()
{
	for(int n = 1;n < 1000 ; ++n) printf("%d*%d=%d \n", n,n,n * n % 13);;
	return 0;
}
	
