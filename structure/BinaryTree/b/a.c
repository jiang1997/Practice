#include <stdio.h>

typedef struct Node
{
	int num;
	struct Node *left;
	struct Node *right;
}Node;

void Insertion_Sort(int Array[], int Length);

int main(void)
{
	int N, array[2000], count = 1;
	scanf("%d", &N);
	for(int n = 1; n <= N; ++n) scanf("%d", &array[n]);
	Insertion_Sort(array, N);



	return 0;
}


Node* parse(int *array, int Length)
{
	int list[14] = {0, 1, 3, 7, 15, 31, 63, 127, 255, 1023, 2047, 4095, 8191, 16383};
	int count = 0, pivot = 0; 
	for(count = 1; list[count] < Length; ++count) ;

	--count;

	if(Length - list[count] < list[count])
	{
		pivot = (list[count] + 1) / 2 + Length - list[count];
	}
	else
	{
		
	}
}


void Insertion_Sort(int Array[], int Length)
{
	int temp, index;
	for(int l = 0; l < Length; ++l)
	{
		temp = Array[l];
		for(index = l; index > 0 && Array[index - 1] > temp; ++index) Array[index] = Array[index - 1];

		Array[index] = temp;
	}
}


