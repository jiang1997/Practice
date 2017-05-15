#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
	int num;
	int *array;
}Node;

void sort(Node *src, Node *dst);

int main(void)
{
	int N, *array = NULL, temp, count = 0;
	Node *src = NULL, *dst = NULL, *negative = NULL;	

	array = (int *)malloc(sizeof(int) * 100000);
	src = (Node *)malloc(sizeof(Node) * 10);
	dst = (Node *)malloc(sizeof(Node) * 10);
	negative = (Node *)malloc(sizeof(Node) * 10);
	for(int n = 0; n < 10; n++)
	{
		src[n].num = dst[n].num = negative[n].num = 0;
		src[n].array = (int *)malloc(sizeof(int) * 100000);
		dst[n].array = (int *)malloc(sizeof(int) * 100000);
		negative[n].array = (int *)malloc(sizeof(int) * 100000);
	}

	scanf("%d", &N);
/*	if(N == 1)
	{
		int num;
		scanf("%d", &num);
		printf("%d", num);
		return 0;
	}
*/
	for(int n = 0; n < N; ++n)
	{
		scanf("%d", &temp);
		if(temp < 0)
		{
			temp *= -1;
			negative[temp % 10].array[negative[temp % 10].num++] = temp;
		}
		else
		{
			src[temp % 10].array[src[temp % 10].num++] = temp;
		}
	}

	sort(negative, dst);

	for(int i = 9; i >= 0; --i)
	{
		int l = dst[i].num - 1;
		dst[i].num = 0;
		for(; l >= 0; --l)
		{
			array[count++] = dst[i].array[l] * -1;
		}
	}

	sort(src, dst);	

	for(int i = 0; i < 10; ++i)
	{
		int l = dst[i].num;
		for(int j = 0; j < l; ++j)
		{
			array[count++] = dst[i].array[j];
		}
	}

	for(int n = 0; n < N; ++n)
	{
		if(n) printf(" ");
		printf("%d", array[n]);
	}


	return 0;
}

void sort(Node *src, Node *dst)
{
	int num, index;
	Node *temp;
	for(long long int digt = 10; digt <= 1000000000; digt *= 10)
	{
		for(int i = 0; i < 10; ++i)
		{
			int l = src[i].num;
			src[i].num = 0;
			for(int j = 0; j < l; ++j)
			{
				num = src[i].array[j];
				index = num / digt % 10;
				dst[index].array[dst[index].num++] = num;
			}
		}

		temp = dst;
		dst = src;
		src = temp;
	}

}

