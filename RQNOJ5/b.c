#include <stdio.h>


int num = 4;
int data[100] = {2, 3, 5, 10}, back_up[100], status[100][100] = {0};

int main(void)
{
	for(int n1 = 0; n1 < num; ++n1)
		back_up[n1] = data[n1];

	printf("%d\n", dfs(num));

	return 0;
}

//数据标记（0 与 非0）情况连续 则  保存状态
int dfs(int rest)
{
	int maximum = 0, *range = isSequencr();
	if(range != null && status[range[0]][range[1]] != 0)
		return status + range[0] * 100 + range[1];
	for(int n1 = 0;n1 < num; ++n1)
	{
		if(data[n1] != 0)
		{
			int sum = fursion(n1);
			if(rest > 2)
				sum += dfs(rest - 1);
			maximum = sum > maximum? sum: maximum;
			data[n1] = back_up[n1];
		}
		if(range != null)
		{
			int * temp = status + range[0] * 100 + range[1];
			*temp = *temp < maximum? maximum: *temp;
			maximum = *temp;
		}
	}
	return maximum;
}

int fursion(int index)
{
	int product = front(index) * data[index] * posterior(index);
	data[index] = 0;
	return product;
}

int front(int index)
{
	for(int n1 = 1; n1 < num; ++n1)
	{
		int cur_index = (index - n1 + num) % num;
		if(data[cur_index] != 0)
			return data[cur_index];
	}
	return 0;
}

int posterior(int index)
{
	for(int n1 = 1; n1 < num; ++n1)
	{
		int cur_index = (index + n1) % num;
		if(data[cur_index] != 0)
			return data[cur_index];
	}
}

int * isSequence()
{
	int num_zero = 0, range[2];
	for(int n1 = 0; n1 < num; ++n1)
	{
		if(data[n1] == 0)
			++num_zero;	
	}

	for(int n1 = 0; n1 < num; ++n1)
	{
		int offset = 0;
		for(offset = 0; offset < num_zero; ++offset)
		{
			if(data[(n1 + offset) % num] != 0)
				break;
		}
		if(offset == num_zero)
		{
			range[0] = (n1 + offset) % num;
			range[1] = (n1 - 1 + num) % num;
			return range;
		}
	}
	return null;
}

