#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
using namespace std;

#define MAX 2147483647

//char orig[] =  "dcabca";
//char opStr[] = "000000";
//char orig[] = "abcbaca";
//char opStr[] = "0000000";
char orig[] =  "bacdadbacdadacbdbcabdabdbcdcbacbdcabca";
char opStr[] = "00000000000000000000000000000000000000";
int rec[105][105] = {0};
int tri[255][105][105] = {0};

//delete duplicate
char* dup_Rm(char *S) {
	int length = strlen(S), top = 0, last = -1;
	char *r = new char[105];
	for(int index = 0; index < length; ++index) {
		if(last != S[index]) {
			r[top++] = S[index];
			last = S[index];
		}
	}
	r[top] = 0;
	return r;
}


int init_R() {
	for(int n1 = 0; n1 < 105; ++n1) {
		for(int n2 = 0; n2 < 105; ++n2) {
			rec[n1][n2] = MAX;
		}
	}
	for(int n1 = 0; n1 < 255; ++n1) {
		for(int n2 = 0; n2 < 105; ++n2) {
			for(int n3 = 0; n3 < 105; ++n3) {
				tri[n1][n2][n3] = MAX;
			}
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
	if(lf > rt) return 0;
	if(lf == rt) return 1;
	//if(rec[lf][rt] != MAX) return rec[lf][rt];
	if(tri[lf][lf][rt] != MAX) return tri[lf][lf][rt];
	char bk[105] = {0};
	strcpy(bk, str);
	
	//rec[lf][rt] = MAX;

	for(int offset = 0; lf + offset <= rt; ++offset) {
		if(orig[lf + offset] != orig[lf]) continue;
		int r1 = 1;
		int forward, backward;
		memset(bk + lf, orig[lf], offset + 1);

		//forward
		forward = f_diff(lf, lf + offset, bk);
		//backward
		/////////////////////
		backward = b_diff(lf, lf + offset, bk);

		r1 += dfs(forward, backward, bk);

		int f2 = f_diff(lf + offset + 1, rt, bk);
		int b2 = b_diff(lf + offset + 1, rt, bk);
		r1 += dfs(f2, b2, bk);

		//r1 < rec[lf][rt]? rec[lf][rt] = r1: 0;
		r1 < tri[lf][lf][rt]? tri[lf][lf][rt] = r1: 0;
		++count;
	}
	//cout << lf << " " << count << endl;
	return tri[lf][lf][rt];
	//return rec[lf][rt];
}

int main() {
	init_R();
	//cout << diff(0, 4);	
	cout << dfs(0, strlen(opStr) - 1, opStr);
	return 0;
}


