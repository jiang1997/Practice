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

int N, K, M;

int main(int argc, char **args)
{
        int recorder[8] = {0}, rank = 1;
        Info **list, *result;
        list = (Info **)malloc(sizeof(Info *) * 20000);
        memset(list, 0, sizeof(Info *) * 20000);

        scanf("%d %d %d", &N, &K, &M);
        for(int k = 1; k <= K; ++k)
        {
                scanf("%d", &recorder[k]);
                recorder[0] += recorder[k];
        }
        result = (Info *)malloc(sizeof(Info) * (recorder[0] + 1));
        memset(result, 0, sizeof(Info) * (recorder[0] + 1));

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
                                usr->Scores[k] = -2;
                        usr->Scores[0] = 0;
                }

                if(list[uid]->Scores[pid] < score)
                {
                        list[uid]->Scores[pid] = score;
                        list[uid]->Solved += score == recorder[pid];
                }
                // if(score == -1)
                // {
                // 	list[uid]->Scores[pid] = 0;
                // }
        }
        /*
        for(int n = 1; n < 5; ++n)
        {
                printf("%05d %d\n", list[n]->ID, list[n]->Solved);
        }
        */

        for(int n = 1; n <= N; ++n)
        {
        	int flag = 0;
                if(list[n] != NULL)
                {
                        for(int k = 1; k <= K; ++k)
                        {	
                        		flag = list[n]->Scores[k] >= 0 || flag == 1;
                                list[n]->Scores[0] += list[n]->Scores[k] > -1? list[n]->Scores[k]: 0;
                                //printf("%d k:%d score:%d\n", n,k, list[n]->Scores[k]);
                        }
                        list[n]->Scores[0] = flag == 0? -1: list[n]->Scores[0];
                }
        }

        sort(list, result);
        for(int n = recorder[0]; n >= 0; --n)
        {
        	int count = 0;
            Info *info;
            // if(result[n].Next != NULL)
            // 	++rank;
            for(info = result[n].Next; info != NULL; info = info->Next)
            {
            	++count;
                printf("%d %05d %d", rank, info->ID, info->Scores[0]);
                for(int k = 1; k <= K; ++k)
                {
                	if(info->Scores[k] > -1)
                		printf(" %d", info->Scores[k]);
                	else if(info->Scores[k] == -1)
                		printf(" 0");
                	else
                		printf(" -");
                }
                printf("\n");
            }
            rank += count;
            
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


int sort(Info **List, Info *Result)
{
    int score;
    Info *info;
	for(int n = 1; n <= N; ++n)
    {
    	
    	if(List[n] && List[n]->Scores[0] != -1)
    	{
    		score = List[n]->Scores[0];
	        for(info = &Result[score]; info->Next != NULL && (info->Next->Scores[0] > score || info->Next->Scores[0] == score && info->Next->Solved >= List[n]->Solved); info = info->Next) ;
	
	        List[n]->Next = info->Next;
	        info->Next = List[n];
    	}
    }
	
}

