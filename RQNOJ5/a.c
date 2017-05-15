#include <stdio.h>

struct linked_node
{
	int value;
	node *next;
}

int main(void)
{
	int data[100] = {0};

	return 0;
}


void* newNode()
{
	struct linked_node *node = null;
	node = malloc(sizeof(struct node));
	node->next = null;
	return node;
}


int fusion(int *data, int num, int index)
{
	int result = data[index] * data	
}

