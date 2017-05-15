#include <stdio.h>
#include <stdlib.h>

typedef struct Heap
{
	int *array;
	int size;
}Heap;

Heap* init_heap(int *array, int size);
void sort(Heap *heap);


int N = 0;
int *array = NULL;
int main(void)
{
	Heap *heap = NULL;
	array = (int *)malloc(sizeof(int) * 100001);
	scanf("%d", &N);

	for(int n = 1; n <= N; ++n)
		scanf("%d", &array[n]);

	heap = init_heap(array, N);

	sort(heap);

	for(int n = 1; n <= N; ++n)
	{
		if(n != 1) printf(" ");
		printf("%d", array[n]);
	}

	return 0;
}

Heap* init_heap(int *array, int size)
{
	Heap *heap = NULL;
	heap = (Heap *)malloc(sizeof(Heap));

	for(int n = 1; n <= size; n *= 2)
	{
	for(int index = size; index > n; --index)
	{
		if(array[index] > array[index / 2])
		{
			int temp = array[index];
			array[index] = array[index / 2];
			array[index / 2] = temp;
		}
	}
	}

	heap->array = array;
	heap->size = size;
	return heap;
}

void sort(Heap *heap)
{
	int index = 0, temp = 0;	
	while(heap->size > 1)
	{
	temp = heap->array[heap->size];	
	heap->array[heap->size] = heap->array[1];
	--heap->size;

	for(index = 1; index * 2 <= heap->size && (temp < heap->array[index * 2] || index * 2 + 1 <= heap->size && temp < heap->array[index * 2 + 1]);)
	{
		if(index * 2 + 1 <= heap->size && heap->array[index * 2 + 1] > heap->array[index * 2])
		{
			heap->array[index] = heap->array[index * 2 + 1];
			index = index * 2 + 1;
		}
		else
		{
			heap->array[index] = heap->array[index * 2];
			index = index * 2;
		}
	}

	heap->array[index] = temp;
	}

}

