#include"myheader21.h"

int enqueue(pqnode **front, pqnode **rear, char item, int prior)
{
	pqnode *new = NULL; 
	pqnode *p = NULL, *q = NULL;
	new = (pqnode *)malloc(sizeof(pqnode));
	if(NULL == new) 
	{ 
		printf("Memory allocation failure"); 
		return FAILURE; 
	}
	new->data = item; 
	new->priority = prior;
	if(NULL == *front)
	{
		*front = new; 
		*rear = new;
		new->next = NULL;
	}
	else
	{
		if((*front)->priority  >  new->priority)
		{
			new->next = *front;
			*front = new;
		}
		else if((*rear)->priority  <=  new->priority)
		{
			(*rear)->next = new;
			*rear = new;
			new->next = NULL;
		}
		else
		{
			p = *front;
			while(p->priority < new->priority)
			{
				q = p;
				p = p->next;
			}
			q->next = new;
			new->next = p;
		}
	}
	return SUCCESS;
}

void display(pqnode **front, pqnode **rear, int i)
{
	pqnode *p = NULL;
	if(NULL == *front)
	{
		printf("Linked list is empty\n");
	}
	else
	{
		p = *front;
		while(p->next != NULL)
		{
			printf("%c(%d)-> ", p->data,i);
			p = p->next;
			i++;
		}
		printf("%c(%d)\n", p->data,i);
	}
}
