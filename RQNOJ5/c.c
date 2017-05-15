#include <stdio.h>

int dfs(int rest);
int fursion(int index);
int isSequence(int* range);
int front(int index);
int posterior(int index);


int num = 4;
int data[100] = {2, 3, 5, 10}, back_up[100], status[100][100] = {0};
int count = 0;
int main(void)
{
	scanf("%d", &num);
	for(int n1 = 0; n1 < num; ++n1)
	{
		scanf("%d", data + n1);
		back_up[n1] = data[n1];
	}	
	printf("%d\n", dfs(num));
	printf("%d\n", count);
	return 0;
}

//数据标记（0 与 非0）情况连续 则  保存状态
int dfs(int rest)
{
	int maximum = 0, range[2], flag = isSequence(range);
	++count;
	if(flag && status[range[0]][range[1]] != 0)
	{
		printf("isSequence %d -- %d :%d\n", range[0], range[1], status[range[0]][range[1]]);
		return status[range[0]][range[1]];
	}
	for(int n1 = 0;n1 < num; ++n1)
	{
		
		if(data[n1] != 0)
		{
			printf("%d--%d\n", rest, n1);
			int sum = fursion(n1);
			if(rest > 2)
				sum += dfs(rest - 1);
			maximum = sum > maximum? sum: maximum;
			data[n1] = back_up[n1];
		}
		if(flag)
		{
			int* temp = &status[range[0]][range[1]];
			*temp = *temp < maximum? maximum: *temp;
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

int isSequence(int* range)
{
	int num_zero = 0;
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
			return 1;
		}
	}
	return 0;
}

