#include <stdio.h>
#include <string.h>

int isMatch(const char *s, const char *p);

int main(int argc, char **args)
{
	char s[24], p[24];
	scanf("%s%s", s, p);
	printf("%d", isMatch(s, p));
	return 0;
}


int isMatch(const char *s, const char *p)
{
	char last = 0, N = strlen(p), n = 0, M = strlen(s), m = 0;
	for(n = 0; n < N && m < M && n + M - 1 < N; ++n)
	{
		int temp = n;
		for(m = 0; m < M && (p[temp] == '.' || p[temp] == '*' && s[m] == last || p[temp] == s[m]); last = s[m++], ++temp);
	}

	return m == M;
}
