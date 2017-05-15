#include <stdio.h>

int *array, N = 6, count = 0;
int *indexes;
int compare(void *a, void *b);
void sort();

int main(int argc, char **args)
{
	scanf("%d", &N);
	array = (int *)malloc(sizeof(int) * 100000);
	indexes = (int *)malloc(sizeof(int) * 100000);
	for(int n = 0; n < N; ++n)
	{
		scanf("%d", &array[n]);
		indexes[n] = n;
	}


	qsort(indexes, N, sizeof(int), compare);
	sort();
	printf("%d\n", count);
	
	return 0;
}

int compare(void *a, void *b)
{
	return array[*(int *)a] - array[*(int *)b];
}

void sort()
{
	int temp, num, n, m;
	/*
	for(int n = 0; n < N; ++n)
		printf("%d ", indexes[n]);
	printf("\n");
	*/
	for(n = 0; n < N; ++n)
	{
		int lcount = 0;
		if(n == indexes[n]) continue;
		num = array[n];
		m = n;
		while(indexes[m] != m)
		{
			array[m] = array[indexes[m]];
			temp = indexes[m];
			indexes[m] = m;
			++lcount;
			m = temp;

			if(indexes[temp] == indexes[indexes[temp]]) 
				break;

		}
		lcount += (lcount > 1);
		count += lcount;
		array[m] = num;
		indexes[m] = m;
	}
}

