#include <stdio.h>
#define OFFSET 400

int main(int argc, char **args) {
	int N, M;
	while(scanf("%d %d", &N, &M), N != 0 && M != 0) {
		int scores[201][4], recorder[40][800][2] = {0};

		for(int n1 = 0; n1 < 40; ++n1)
			for(int n2= 0; n2 < 800; ++n2)
				recorder[n1][n2][0] = 0;
			
		for(int n1 = 1; n1 <= N; ++n1) {
			scanf("%d %d", &scores[n1][0], &scores[n1][1]);
			scores[n1][2] = scores[n1][0] + scores[n1][1];
			scores[n1][3] = scores[n1][0] - scores[n1][1];
		}

		for(int n = 1; n <= N; ++n) {
			printf("%d %d\n",scores[n][0], scores[n][1]);
		}

		recorder[1][scores[1][3] + OFFSET][0] = scores[1][2];
		//return 0;
		for(int n = 2; n <= N; ++n) {
			for(int m = n < M? n: M; m > 1; --m) {
				int max = 799, min = 0;
				max += scores[n][3] < 0? scores[n][3]: 0;
				min += scores[n][3] > 0? scores[n][3]: 0;
				for(int s = max; s >= min; --s) {
					if(recorder[m - 1][s][0] != 0 && recorder[m][s][0] < recorder[m - 1][s - scores[n][3]][0] + scores[n][2]) {
						recorder[m][s][0] = recorder[m - 1][s - scores[n][3]][0] + scores[n][2];
						recorder[m][s][1] = n;
						//printf("1");
					}
				}
			}
			if(recorder[1][scores[n][3] + OFFSET][0] < scores[n][2]) {
				recorder[1][scores[n][3]][0] = scores[1][2];
				recorder[1][scores[n][3]][1] = n;
				//printf("1");

			}

		}

		for(int n = 0; n < 800; ++n) {
			if(recorder[M][n][0] != 0)
				printf("%d: %d %d\n", n, recorder[M][n][0], recorder[M][n][1]);
		}
		
	}
	return 0;
}
