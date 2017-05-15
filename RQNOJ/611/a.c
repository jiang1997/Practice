#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Node
{
	char value;
	struct Node *left;
	struct Node *right;
}Node;


Node *analyse(char *Poststr, char *Instr, int length);

int main(void)
{
	char Instr[64] = {0}, Poststr[64] = {0};
	Node *root = NULL;
	scanf("%s\n%s", Instr, Poststr);
	root = analyse(Instr, Poststr, strlen(Instr));	
	return 0;
}


Node *analyse(char *Instr, char *Poststr, int length)
{
	Node *node = (Node *)malloc(sizeof(Node));
	node->value = Poststr[length -1];
	node->left = NULL;
	node->right = NULL;
	printf("%c", node->value);
	if(length == 1)
		return node;
	
	char *Pnrself = strchr(Instr, node->value);
	char child = Poststr[length - 1 - 1];
	char *Pnrchild = strchr(Instr, child);
	//printf("%c", *Pnrchild);
	if(Pnrself != Instr)
		node->left = analyse(Instr, Poststr, Pnrself - Instr);
	if(Pnrself < Pnrchild) 
		node->right = analyse(Pnrself + 1, Poststr + (Pnrself - Instr), length - (Pnrself - Instr) - 1);
	
	return node;
	
}






