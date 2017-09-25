#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int lengthOfLongestSubstring(char *s);
int main(int argc, char **args)
{
	char str[256];
	scanf("%s", str);
	int result = lengthOfLongestSubstring(str);
	printf("%d", result);
	return 0;
}

int lengthOfLongestSubstring(char *s) {
	int length = 0;
	int *recorder = (int *)malloc(sizeof(int) * 100000);
	for(int n = 0; n < strlen(s); ++n) {
		int m = 0;
		for(m = n + 1;m < strlen(s) && s[n] != s[m]; ++m) ;
		recorder[n] = m - n;
		for(m = n - 1; m >= 0 && n + recorder[n] < m + recorder[m]; --m) {
			//if(n + recorder[n] < m + recorder[m]) {
				recorder[m] = n + recorder[n] - m;
			//}
		}
	}

	for(int n = 0; n < strlen(s); ++n)
		length = recorder[n] > length? recorder[n]: length;

	return length;
}
