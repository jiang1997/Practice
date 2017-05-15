#include <stdio.h>
#include <queue>
using namespace std;

int main(void)
{
	int N, tree[10][2], recorder[10] = {0}, root;
	queue<int> que;
	for(int n = 0; n < 10; ++n)
	{
		tree[n][0] = tree[n][1] = -1;
	}
	scanf("%d\n", &N);

	for(int n = 0; n < N; ++n)
	{
		char l = 0, r = 0, s;
		scanf("%c %c\n", &l, &r);
		printf("\n```%c %c\n", l, r);
		if(l != '-') recorder[l - '0'] = 1;
		if(r != '-') recorder[r - '0'] = 1;

		tree[n][0] = l - '0';
		tree[n][1] = r - '0';

	}

	for(root = 0; root < N && recorder[root] != 0; ++root) ;

	que.push(root);
	while(!que.empty()) 
	{
		int index = que.front();
		que.pop();
		if(index < 0) continue;

		que.push(tree[index][0]);
		que.push(tree[index][1]);
		
		if(tree[index][0] < 0 && tree[index][1] < 0)
			printf("%d\n", index);
	}


	return 0;
}
