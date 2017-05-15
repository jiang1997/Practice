#include <stdio.h>
#include <stdlib.h>

#define Cutoff 1000000 

void QuickSort(int Array[], int Left, int Right);
void InsSort(int Array[], int Length);

int main(void)
{
	int N = 0, *array = NULL;
	array = (int *)malloc(sizeof(int) * 100000);

	scanf("%d", &N);
	for(int n = 0; n < N; ++n)
	{
		scanf("%d", &array[n]);
	}

	QuickSort(array, 0, N - 1);
	//InsSort(array, N);

	for(int n = 0; n < N; ++n)
	{
		if(n) printf(" ");
		printf("%d", array[n]);
	}

	return 0;
}


int Median3(int Array[], int Left, int Right)
{
	int Center = (Left + Right) / 2, temp = 0;

	if(Array[Center] < Array[Left])
	{
		temp = Array[Center];
		Array[Center] = Array[Left];
		Array[Left] = temp;
	}

	if(Array[Center] > Array[Right])
	{
		temp = Array[Center];
		Array[Center] = Array[Right];
		Array[Right] = temp;
	}

	if(Array[Center] < Array[Left])
	{
		temp = Array[Center];
		Array[Center] = Array[Left];
		Array[Left] = temp;
	}

	temp = Array[Center];
	Array[Center] = Array[Right - 1];
	Array[Right - 1] = temp;

	return Array[Right - 1]; 

}


void QuickSort(int Array[], int Left, int Right)
{
	int l = Left, r = Right - 1, temp;
	if(Right - Left + 1 < Cutoff)
	{
		InsSort(&Array[Left], Right - Left + 1);
	}
	else
	{
	int pivot = Median3(Array, Left, Right);

	while(l < r)
	{
	//	for(;l < Right && Array[l] < pivot; ++l) ;
		while(Array[++l] < pivot) ;
	//	for(;r > Left && Array[r] > pivot; --r) ;
		while(Array[--r] > pivot) ;

		if(l < r)
		{
			temp = Array[l];
			Array[l] = Array[r];
			Array[r] = temp;
		}

	}

	temp = Array[l];
	Array[l] = Array[Right - 1];
	Array[Right - 1] = temp;

	QuickSort(Array, Left, l - 1);
	QuickSort(Array, l + 1, Right);
	}
}


void InsSort(int Array[], int Length)
{
	for(int n = 0; n < Length; ++n)
	{
		int num = Array[n], index = 0;
		for(index = n; index > 0 && Array[index - 1] > num; --index) Array[index] = Array[index - 1];
		Array[index] = num;
	}
}


