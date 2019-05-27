#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define SUCCESS 1
#define FAILURE 0
typedef struct snode
{
	char str1;
	int flag1;
	struct snode *next;
}snode;


int operate(char str);
int push(snode **top, char str, int flag);
int pop(snode **top, char str);
