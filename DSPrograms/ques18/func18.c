#include"myheader18.h"

void push(snode **top, char item)
{
	snode *new;
	new = (snode *)malloc(sizeof(snode));
	if(NULL == new)
	{
		printf("Memory Allocation Failure\n");
		return;
	}
	new->name = item;
	if(NULL == (*top))
	{
		new->next = NULL;
	}
	else
	{
		new->next = (*top);
	}
	(*top) = new;
}

char pop(snode **top)
{
	snode *p;
	char ch;
	if(NULL == (*top))
	{
		printf("Stack Underflow\n");
		exit(1);
	}
	ch = (*top)->name;
	if(NULL == (*top)->next)
	{
		free(*top);
		(*top)=NULL;
	}
	else
	{
		p = *top;
		(*top)=(*top)->next;
		free(p);
		p=NULL;
	}
	return ch;
}

void free_stack(snode **top)
{
	snode *p;
	if(NULL == *top)
	{
		return;
	}
	p = *top;
	while(NULL != p)
	{
		(*top)=(*top)->next;
		free(p);
		p=NULL;
		p = (*top);
	}
}
