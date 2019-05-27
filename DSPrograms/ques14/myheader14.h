#include<stdio.h>
#include<stdlib.h>
#define SUCCESS 1
#define FAILURE 0

typedef struct node
{
	int data;
	struct node *next;
}node;

int Insert_Beg(node **head, int item);
int Insert_End(node **head, int item);
int Insert_Mid(node **head, int item);
int delete_beg(node **head);
int delete_end(node **head);
int delete_mid(node **head, int pos);
int display(node **head);
int create(node **head, int n);
int free_list(node **head);
