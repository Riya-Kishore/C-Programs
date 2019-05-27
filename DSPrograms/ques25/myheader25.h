#include<stdio.h>
#include<stdlib.h>

struct node
{
	int info;
	struct node *lchild;
	struct node *rchild;
};
struct node *root=NULL;

void Search(int item, struct node **par, struct node **loc);
void insert(int item);
void case_a(struct node *par, struct node *loc);
void case_b(struct node *par, struct node *loc);
void case_c(struct node *par, struct node *loc);
int del(int item);
int preorder(struct node *ptr);
void inorder(struct node *ptr);
void postorder(struct node *ptr);
void display(struct node *ptr, int level);

