#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* dup_Rm(char *S);
int strangePrinter(char* s); 
int dfs(int src, int dst); 
int main() {
        char str[] = "ababa";
        strangePrinter(str);

}


char *S;
int M[1000][1000] = {0};
int strangePrinter(char* s) {
        int tmp[1000][1000]  = {0};
        int num;
        for(int n1 = 0; n1 < 1000; ++n1) {
        	for(int n2 = 0; n2 < 1000; ++n2) {
        		M[n1][n2] = 1000;
        	}
        	M[n1][n1] = 1;
        }
        //return 0;
        S = dup_Rm(s);
        //M = &tmp[0];
        num = dfs(0, strlen(S) - 1);
        printf("%d\n", num);
}

//delete duplicate
char* dup_Rm(char *S) {
        int length = strlen(S), top = 0, last = -1;
        char *r = malloc(sizeof(char) * 256);
        for(int index = 0; index < length; ++index) {
                if(last != S[index]) {
                        r[top++] = S[index];
                        last = S[index];
                }
        }
        r[top] = 0;
        return r;
}

int dfs(int src, int dst) {
        int t1 = 0, t2 = 0, min = 1000;
        int s2 = src, term = 1;
        //if(src == dst) return 1;
        if(M[src][dst] < 1000) return M[src][dst];
        printf("-%d -%d\n", src, dst);
        
        return min;
}

