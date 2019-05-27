#include<stdio.h>
#include<stdlib.h>  
#include<string.h>  
#define SUCCESS 1
#define FAILURE 0
typedef struct cnode
{
	int cons;
	int expo; 
	struct cnode *next;
}cnode;
int create_poly(cnode **head, int *n);
void poly_deri(cnode **head, char var, int *n);

