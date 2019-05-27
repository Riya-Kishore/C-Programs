#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct snode
{
	char name;
	struct snode *next;
}snode;

void push(snode **top, char item);
char pop(snode **top);
void free_stack(snode **top);
