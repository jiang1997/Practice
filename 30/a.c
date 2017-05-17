#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Info
{
	int ID;
	int Scores[8];
	int Solved;
	struct Info *Next;
}Info;

int main(int argc, char **args)
{
	int N, K, M, recorder[8] = {0};
	Info **list;
	list = (Info **)malloc(sizeof(Info *) * 20000);
	memset(list, 0, sizeof(Info *) * 20000);

	scanf("%d %d %d", &N, &K, &M);
	for(int k = 1; k <= K; ++k)
	{
		scanf("%d", &recorder[k]);
		recorder[0] += recorder[k];
	}

	for(int m = 0; m < M; ++m)
	{
		int uid, pid, score;
		scanf("%d %d %d", &uid, &pid, &score);
		if(list[uid] == NULL)
		{
			Info *usr = (Info *)malloc(sizeof(Info));
			usr->ID = uid;
			usr->Next = NULL;
			usr->Solved = 0;
			list[uid] = usr;

			for(int k = 1; k <= K; ++k)
				usr->Scores[k] = -1;
			usr->Scores[0] = 0;
		}

		if(list[uid]->Scores[pid] < score)
		{
			list[uid]->Scores[pid] = score;
			list[uid]->Solved += score == recorder[pid];
		}
	}
	/*
	for(int n = 1; n < 5; ++n)
	{
		printf("%05d %d\n", list[n]->ID, list[n]->Solved);
	}
	*/
	for(int n = 1; n < 20000; ++n)
	{
		if(list[n] != NULL)
		{
			for(int k = 1; k <= K; ++k)
			{
				list[n]->Scores[0] += list[n]->Scores[k] != -1? list[n]->Scores[k]: 0;
				//printf("%d k:%d score:%d\n", n,k, list[n]->Scores[k]);
			}
		}
	}
/*	
	for(int n = 1; n < 5; ++n)
	{
		printf("%05d %d  %d\n", list[n]->ID, list[n]->Solved, list[n]->Scores[0]);
	}
*/

	//printf("%05d", a);
	return 0;
}


int sort(Info **List, Info **Result)
{
}
