#include"myheader15.h"

int create(dnode **head, dnode **tail, int n)
{
	int i, item;
	printf("Enter numbers- \n");
	for(i=0; i<n; i++)
	{
		dnode *temp, *p;
		temp = (dnode*)malloc(sizeof(dnode));
		scanf("%d",&item);
		temp->data = item;
		temp->next = NULL;
		temp->prev = NULL;
		if(NULL == *head)
		{
			*head = temp;
			*tail = temp;
		}
		else
		{
			p = *head;
			while(NULL != p->next)
			{
				p = p->next;
			}
			p->next = temp;
			*tail = p; 
		}
	}
}

int display(dnode **head, dnode **tail)
{
	dnode *p;
	p = *head;
	if(NULL == *head)
	{
		printf("Linked List is Empty\n");
	}
	else
	{
		while(NULL != p->next)
		{
			printf("%d\t",p->data);
			p = p->next;
		}
		if(NULL == p->next)
		{
			printf("%d\n",p->data);
		}
	}
}

int Insert_Beg(dnode **head, dnode **tail, int item)
{
	dnode *new;
	new = (dnode *)malloc(sizeof(dnode));
	if(NULL == new)
	{
		printf("Memory Allocation Failure\n");
		return FAILURE;
	}
	new->data = item;
	new->prev = NULL;
	if(NULL == *head)
	{
		new->next = NULL;
		*head = new;
		*tail = new;
	}
	else
	{
		new->next = *head;
		(*head)->prev = new;
		*head = new;
	}
	return SUCCESS;
}
int Insert_End(dnode **head, dnode **tail, int item)
{
	dnode *new, *p;
	new = (dnode *)malloc(sizeof(dnode));
	if(NULL == new)
	{
		printf("Memory Allocation Failure\n");
		return FAILURE;
	}
	new->data = item;
	new->next = NULL;
	if(NULL == *head)
	{
		new->next = NULL;
		*head = new;
		*tail = new;
	}
	else
	{
		p = *head;
		while(NULL != p->next)
		{
			p = p->next;
		}
		p->next = new;
		new->prev = *tail;
		*tail = new;
	}
	return SUCCESS;
}	
int Insert_Mid(dnode **head, dnode **tail, int item)
{
	dnode *new, *p, *q;
	new = (dnode *)malloc(sizeof(dnode));
	if(NULL == new)
	{ 
		printf("Memory allocation faliure\n"); 
		return FAILURE; 
	}
	new->data = item;
	if(NULL == *head)
	{
		new->next = NULL;
		new->prev = NULL;
		*head = new;
		*tail = new;
		return SUCCESS;
	}
	if(item <= (*head)->data)
	{
		new->prev = NULL;
		new->next = *head;
		(*head)->prev = new;
		*head = new;
		return SUCCESS;
	}
	if(item >= (*tail)->data)
	{
		new->next = NULL;
		new->prev = *tail;
		(*tail)->next = new;
		*tail = new;
		return SUCCESS;
	}
	p = (*head)->next; 
	q = *head;
	while((item > p->data) && (NULL != p))
	{
		q = p;
		p = p->next;
	}
	new->next = p;
	p->prev = new;
	q->next = new;
	new->prev = q;
	return SUCCESS;
}
int delete_beg(dnode **head, dnode **tail)
{
	dnode *p;
	int item;
	if(NULL == (*head))
	{
		printf("list is empty\n");
		return FAILURE;
	}
	p = *head;
	item = p->data;
	if((*head) == (*tail))
	{
		(*head) = NULL;
		(*tail) = NULL;
		free(p);
		p = NULL;
		return item;
	}
	(*head) = p->next;
	(*head)->prev = NULL;
	free(p);
	p = NULL;
	return item;
} 
int delete_end(dnode **head, dnode **tail)
{
	dnode *p, *q; 
	int item;
	if(NULL == *head)
	{
		printf("The linked list is empty\n");
		return FAILURE;
	}
	p = *head;
	if(NULL == p->next)
	{
		*head = NULL;
	}
	else
	{
		q = p;
		while(NULL != p->next)
		{
			q = p;
			p = p->next;
		}
		q->next = NULL;
	}
	(*tail) = q;
	item = p->data;
	free(p);
	p = NULL;
	
}
int delete_mid(dnode **head, dnode **tail, int pos)
{
	int i; dnode *p; dnode *q; 
	int item;
	if(NULL == *head)
	{
		printf("The linked list is empty\n");
		return -1;
	}
	if(1 == pos)
	{
		p = *head;
		if(*head == *tail)
		{
			*head = NULL;
			*tail = NULL;
		}
		else
		{
			*head = p->next; 
			(*head)->prev = NULL;
		}
	}
	else
	{
		p = *head;
		for(i = 0; i<pos-1; i++)
		{
			q = p;
			p = p->next;
		}
		q->next = p->next;
		(p->next)->prev = q;
	}
	item = p->data;
	free(p);
	p = NULL;
	return item;
}

int free_list(dnode **head, dnode **tail)
{
	dnode *p = *head;
	if(NULL==(*head))
	{
		printf("List already empty\n");
		return FAILURE;
	}
	if((*head)==(*tail))
	{
		free(*head);
		*head=NULL;
		*tail=NULL;
		printf("List freed\n");
		return SUCCESS;
	}
	
	while(p!=NULL)
	{
		(*head)=(*head)->next;
		free(p);
		p=NULL;
		p=(*head);
	}
	*tail=NULL;
	printf("List freed\n");
}
