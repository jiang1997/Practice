#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
using namespace std;

#define MAX 2147483647


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



//char orig[] =  "123";
//char opStr[] = "000";
//char orig[] = "abcbaca";
//char opStr[] = "0000000";

//char orig[] =  "bacdadacbdbcabdabdbcdcbacbdcabca";
char input[] =  "baacdddaaddaaaaccbddbcabdaabdbbcdcbbbacbddcabcaaa";
char *orig;
char opStr[105] = "00000000000000000000000000000000";

int rec[105][105] = {0};
int tri[255][105][105] = {0};

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
	//
	if(lf > rt) return 0;
	if(lf == rt) return 1;
	if(tri[orig[lf]][lf][rt] != MAX) return tri[orig[lf]][lf][rt];
	//if(rec[lf][rt] != MAX) return rec[lf][rt];

	char bk[105];
	strcpy(bk, str);
	int up = f_diff(lf, rt, bk);
	int low = b_diff(lf, rt, bk);

	int r1 = 1;
	int offset = 0;
	offset = strchr(orig + offset + lf, orig[lf]) - orig - lf;


//	rec[lf][rt] = MAX;
	while(offset <= rt && offset >= 0 ) {
	r1 = 1;
		int forward, backward;

		memset(&bk[lf],  orig[lf], offset + 1);

		forward = f_diff(lf, rt, bk);
		backward = b_diff(lf, rt, bk);

		r1 += dfs(forward, backward, bk);
		//r1 < rec[lf][rt]? rec[lf][rt] = r1: 0;
		r1 < tri[orig[lf]][lf][rt]? tri[orig[lf]][lf][rt] = r1: 0;

		offset = strchr(orig + lf + offset + 1, orig[lf]) - orig - lf;
		
		++count;
	}
	cout << count << endl;
	return tri[orig[lf]][lf][rt];
	//return rec[lf][rt];
	//
}

int main() {
	init_R();
	//cout << diff(0, 4);	
	orig = dup_Rm(input);
	cout << orig << endl;
	memset(opStr, '0', strlen(orig));
	opStr[strlen(orig)] = 0;

	cout << dfs(0, strlen(opStr) - 1, opStr);
	return 0;
}

