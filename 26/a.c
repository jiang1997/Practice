#include <stdio.h>

void insert_sort(int *array, int index);
void merge_sort(int *array, int length, int *temp, int span);
void MergeSort(int *left, int *right, int r_length, int *temp);

int main(void)
{
	int N = 0, org[200], sample[200], src1[200], src2[200], temp[200];
	scanf("%d", &N);

	for(int n = 0; n < N; ++n)
	{
		scanf("%d", &org[n]);
		src1[n] = org[n];
		src2[n] = org[n];
	}

	for(int n = 0; n < N; ++n)
		scanf("%d", &sample[n]);
	
	for(int n = 1; n < N; ++n)
	{
		int index = 0;
		insert_sort(src1, n);

		for(index = 0; index < N && src1[index] == sample[index]; ++index) ;

		if(index == N)
		{
			insert_sort(src1,n + 1);

			printf("Insertion Sort\n");
			for(int n1 = 0; n1 < N; ++n1)
			{
				if(n1) printf(" ");
				printf("%d", src1[n1]);
			}
			return 0;
		}

	}
	//printf("\n");
	for(int span = 1; span < N; span *= 2)
	{
		int index = 0;
		merge_sort(src2, N, temp, span);

		for(index = 0; index < N && src2[index] == sample[index]; ++index) ;

		if(index == N)
		{
			merge_sort(src2, N, temp, span * 2);
			printf("Merge Sort\n");
			for(int n1 = 0; n1 < N; ++n1)
			{
				if(n1) printf(" ");
				printf("%d", src2[n1]);
			}
			return 0;
		}
	}
	
	return 0;
}


void insert_sort(int *array, int index)
{
	int num = array[index];

	for(;index > 0 && array[index - 1] > num; --index) array[index] = array[index - 1];
	array[index] = num;

}

void merge_sort(int *array, int length, int *temp, int span) //span = 1,2,4,8,16......
{
	int offset = 0;
	for(offset = 0; offset < length - span * 2; offset += span * 2)
	{
		MergeSort(array + offset, array + offset + span, span, temp);
	}

	if(offset < length - span)
	{
		MergeSort(array + offset, array + offset + span, length - offset - span, temp);
	}

}

void MergeSort(int *left, int *right, int r_length, int *temp)
{
	int l_length = right - left;
	int l_index = 0, r_index = 0, t_index = 0;

	while(l_index < l_length)
	{
		if(r_index < r_length && right[r_index] < left[l_index])
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
		left[n] = temp[n];
}

