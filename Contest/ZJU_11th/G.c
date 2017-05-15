#include <stdio.h>


int calc(int a, int b, char symbol);
int priority(char symbol);


int main(void)
{
	int T = 0, a = 0, b = 0, c = 0;
	char operator1, operator2;
	scanf("%d", &T);
	for(int t = 0; t < T; ++t)
	{
		scanf("%d %c %d %c %d", &a, &operator1, &b, &operator2, &c);
		if(priority(operator1) < priority(operator2))
		{
			b = calc(b, c, operator2);
		}
		else
		{
			a = calc(a, b, operator1);
			operator1 = operator2;
			b = c;
		}

		a = calc(a, b, operator1);
		printf("%d\n", a);

	}
	return 0;
}

int calc(int a, int b, char symbol)
{
	switch(symbol)
	{
		case '+':
			return a + b;
		case '-':
			return a - b;
		case '*':
			return a * b;
		case '/':
			return a / b;
		case '%':
			return a % b;
	}
}

int priority(char symbol)
{
	switch(symbol)
	{
		case '+':
		case '-':
			return 1;
		case '*':
		case '/':
		case '%':
			return 2;
	}

}

