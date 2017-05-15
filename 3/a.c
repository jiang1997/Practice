#include <stdio.h>

int main()
{
	double x, y, h;
	scanf("%lf %lf %lf", &x, &y, &h);
	printf("%0.2f", (x + y) * h / 2);
	return 0;
}
