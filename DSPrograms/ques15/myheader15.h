#include<stdio.h>
#include<stdlib.h>
#define SUCCESS 1
#define FAILURE 0

typedef struct dnode
{
	int data;
	struct dnode *next;
	struct dnode *prev;
}dnode;

int Insert_Beg(dnode **head, dnode **tail, int item);
int Insert_End(dnode **head, dnode **tail, int item);
int Insert_Mid(dnode **head, dnode **tail, int item);
int delete_beg(dnode **head, dnode **tail);
int delete_end(dnode **head, dnode **tail);
int delete_mid(dnode **head, dnode **tail, int pos);
int display(dnode **head, dnode **tail);
int create(dnode **head, dnode **tail, int n);
int free_list(dnode **head, dnode **tail);
