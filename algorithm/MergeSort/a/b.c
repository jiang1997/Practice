#include <stdio.h>
#include <stdlib.h>

void MergeSort(int *left, int *right, int r_length, int *temp);
void sort(int *array, int lenght, int *temp);

int main(void)
{
	int N = 0, *array = NULL;
	int *temp = NULL;
	temp = (int *)malloc(sizeof(int) * 100000);
	array = (int *)malloc(sizeof(int) * 100000);

	scanf("%d", &N);

	for(int n = 0; n < N; ++n)
		scanf("%d", &array[n]);

	sort(array, N, temp);

	for(int n = 0; n < N; ++n)
	{
		if(n) printf(" ");
		printf("%d", array[n]);
	}

	return 0;
}

void sort(int *array, int length, int *temp)
{
	for(int span = 1; span < length;span *= 2)
	{
		int left = 0;
		for(left = 0; left < length - 2 * span; left += 2 * span)
		{
			MergeSort(array + left, array + left + span, span, temp);
		}

		if(left + span < length)
		{
			MergeSort(array + left, array + left + span, length - left - span, temp);
		}
	}
}

void MergeSort(int *left, int *right, int r_length, int *temp)
{
	int l_length = right - left;
	int l_index = 0, r_index = 0, t_index = 0;

	while(l_index < l_length)
	{
		if(r_index < r_length && left[l_index] > right[r_index])
		{
			temp[t_index++] = right[r_index++];
		}
		else
		{
			temp[t_index++] = left[l_index++];
		}
	}

	while(r_index < r_length)
	{
		temp[t_index++] = right[r_index++];
	}

	for(int n = 0; n < t_index; ++n)
	{
		left[n] = temp[n];
	}

}


