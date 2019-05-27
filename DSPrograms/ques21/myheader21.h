#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define SUCCESS 1
#define FAILURE 0

typedef struct pqnode
{
	char data;
	int priority;
	struct pqnode *next;
}pqnode;

int enqueue(pqnode **front, pqnode **rear, char item, int prior);
void display(pqnode **front, pqnode **rear, int i);
