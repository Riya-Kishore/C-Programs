#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define SUCCESS 1
#define FAILURE 0

typedef struct cnode
{
	char name[30];
	struct cnode *next;
}cnode;

void add_name(cnode **head);
char *del(cnode **temp);
