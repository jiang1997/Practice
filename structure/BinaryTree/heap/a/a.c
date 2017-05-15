#include <stdio.h>

#define MIN -1024

int heap[1024] = {0}, size = 0;

int main(void)
{
	
	int l = 0, j = 0;
	heap[0] = MIN;
	scanf("%d %d", &l, &j);	
	for(int n = 0; n < l; ++n)
	{
		int temp;
		scanf("%d", &temp);
		Insert(temp);
	}

	for(int n = 0; n < j; ++n)
	{
		int index = 1;
		scanf("%d", &index);
		for(; index > 0; index /= 2)
			printf("%d ", heap[index]);
		printf("\n");
	}
	return 0;
}


int Insert(int num)
{
	int n = 0;
	for(n = ++size; num < heap[n / 2]; n /= 2) 
		heap[n] = heap[n / 2];
	heap[n] = num;
	return 0;
}




