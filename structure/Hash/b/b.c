#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct Cell
{
	int Num;
	int Info;
}Cell;


typedef struct HashTab
{
	Cell **Array;
	int Size;
}HashTab;

int main(int argc, char **args)
{
	int N, M, *array, num;
	HashTab *tab;
	tab = (HashTab *)malloc(sizeof(HashTab));
	scanf("%d %d", &M, &N);
	if(M == 1) M = 2;
	tab->Size = NextPrime(M);
	tab->Array = (Cell **)malloc(sizeof(Cell *) * tab->Size);
	memset(tab->Array, 0, sizeof(Cell *) * tab->Size);

	for(int n = 0; n < N; ++n)
	{
		scanf("%d", &num);
		num = Hash_Add(tab, num);
		if(n) printf(" ");
		if(num != -1)
		{
			printf("%d", num);
		}
		else
		{
			printf("-");
		}
	}

	return 0;
}

int Hash_Add(HashTab *Tab, int Num)
{
	int index = Hash(Num, Tab->Size), offset = 0;
	Cell *cell = malloc(sizeof(Cell));
	cell->Num = Num;
	for(offset = 0; offset <= Tab->Size && Tab->Array[(index + offset * offset) % Tab->Size] != NULL; ++offset) ;
	
	index = (index + offset * offset) % Tab->Size;
	if(Tab->Array[index])
	{
		index = -1;
	}
	else
	{
		Tab->Array[index] = cell;
	}
	return index;
}

int Hash(int Num, int K)
{
	return Num % K;
}

int NextPrime(int N)
{
	int n = N, m = 2;
	for(n = N; ; ++n)
	{
		for(m = 2; m <= sqrt(n) && n % m != 0; ++m) ;
		if(m > sqrt(n))
			break;
			//printf("%d ", n);
	}
	return n;
}



