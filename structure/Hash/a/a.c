#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define K 160807
typedef struct Node
{
	long long int num;
	int count;
	struct Node *next;
}Node;
void Hash_Add(Node *array, long long int num);
int Hash(long long int num);

int main(int argc, char *args[])
{
	int N, index, count = 0, maximum = 0;
	long long tmp1, tmp2, num;
	Node *array = NULL;
	array = (Node *)malloc(sizeof(Node) * 1000000);
	memset(array, 0, sizeof(Node) * 1000000);
	scanf("%d", &N);
	for(int n = 0; n < N; ++n)
	{
		scanf("%lld %lld", &tmp1, &tmp2);
		Hash_Add(array, tmp1);
		Hash_Add(array, tmp2);
	}

	for(int n = 0; n < K; ++n)
	{
		for(Node *last = array[n].next; last != NULL; last = last->next)
		{
			if(last->count > maximum)
			{	
				maximum = last->count;
				num = last->num;
				count = 1;
			}
			else if(last->count == maximum)
			{
				if(last->num < num)
					num = last->num;
				++count;
			}
			
		}
	}
	printf("%lld %d", num, maximum);
	if(count != 1)
		printf(" %d", count);

	return 0;
}


int Hash(long long int num)
{
	return num % K;
}

void Hash_Add(Node *array, long long int num)
{
	Node *last;
	int index = Hash(num);
	for(last = &array[index]; last->next != NULL && last->num != num; last = last->next) ;
	
	if(last->num == num)
	{
		++last->count;
	}
	else
	{
		Node *node = (Node *)malloc(sizeof(Node));
		node->num = num;
		node->count = 1;
		last->next = node;
	}
}


