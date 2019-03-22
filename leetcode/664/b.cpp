#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
using namespace std;

#define MAX 2147483647

char orig[] =  "dcabca";
char opStr[] = "000000";
//char orig[] = "abcbaca";
//char opStr[] = "0000000";
int rec[105][105] = {0};

int init_R() {
	for(int n1 = 0; n1 < 105; ++n1) {
		for(int n2 = 0; n2 < 105; ++n2) {
			rec[n1][n2] = MAX;
		}
	}
	return 1;
}

int f_diff(int lf, int rt, char *op) {
	for(; lf <= rt && orig[lf] == op[lf]; ++lf) {
	}
	return lf;
}

int b_diff(int lf, int rt, char *op) {
	for(; rt >= lf && orig[rt] == op[rt]; --rt) {
	}
	return rt;
}

int count = 0;
int dfs(int lf, int rt, char str[]) {
	//
	if(lf > rt) return 0;
	if(lf == rt) return 1;
	//if(rec[lf][rt] != MAX) return rec[lf][rt];
	//printf("%s\n", str);
	char bk[105];
	strcpy(bk, str);
	int up = f_diff(lf, rt, bk);
	int low = b_diff(lf, rt, bk);

	for(int offset = up - lf; lf + offset <= low; ++offset) {
		int r1 = 1;
		int forward, backward;
		//print 
		//memeset(&str[lf],  orig[lf], offset + 1);
		bk[lf + offset] = orig[lf];
		//forward
		forward = f_diff(lf, rt, bk);
		//backward
		backward = b_diff(lf, rt, bk);

		r1 += dfs(forward, backward, bk);
		r1 < rec[lf][rt]? rec[lf][rt] = r1: 0;
		++count;
	}
	cout << lf << " " << count << endl;
	//memcpy(&str[lf], bk, rt - lf + 1);
	//memset(&str[lf], '0', rt - lf + 1);
	return rec[lf][rt];
	//
}

int main() {
	init_R();
	//cout << diff(0, 4);	
	dfs(0, strlen(opStr) - 1, opStr);
	cout << rec[0][strlen(opStr) - 1];
	return 0;
}


