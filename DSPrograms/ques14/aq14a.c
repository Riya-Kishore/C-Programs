#include"myheader14.h"

int create(node **head, int n)
{
	int i, item;
	printf("Enter numbers- \n");
	for(i=0; i<n; i++)
	{
		node *temp, *p;
		temp = (node*)malloc(sizeof(node));
		if(NULL == temp)
		{
			printf("Memory Allocation Failure\n");
			exit(1);
		}
		scanf("%d",&item);
		temp->data = item;
		temp->next = NULL;
		if(NULL == *head)
		{
			*head = temp;
		}
		else
		{
			p = *head;
			while(NULL != p->next)
			{
				p = p->next;
			}
			p->next = temp; 
		}
	}
}

int display(node **head)
{
	node *p;
	int i;
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

int Insert_Beg(node **head, int item)
{
	node *new;
	new = (node *)malloc(sizeof(node));
	if(NULL == new)
	{
		printf("Memory Allocation Failure\n");
		return FAILURE;
	}
	new->data =item;
	if(NULL == *head)
	{
		new->next = NULL;
	}
	else
	{
		new->next = *head;
		*head = new;
	}
	return SUCCESS;
}

int Insert_End(node **head, int item)
{
	node *new, *p;
	new = (node *)malloc(sizeof(node));
	if(NULL == new)
	{
		printf("Memory Allocation Failure\n");
		return FAILURE;
	}
	new->data =item;
	new->next = NULL;
	if(NULL == *head)
	{
		*head = new;
	
	}
	else
	{
		p = *head;
		while(NULL != p->next)
		{
			p = p->next;
		}
		p->next = new;
	}
	return SUCCESS;
}

int Insert_Mid(node **head, int item)
{
	node *new, *p, *q;
	new = (node *)malloc(sizeof(node));
	if(NULL == new)
	{
		printf("Memory Allocation Failure\n");
		return FAILURE;
	}
	new->data =item;
	if(NULL == *head)
	{
		new->next = NULL;
		*head = new;
		return SUCCESS;
	}
	if(item < (*head)->data)
	{
		new->next = *head;
		*head = new;
		return SUCCESS;
	}
	p = (*head)->next;
	q = *head;
	while(item > (p->data) && p != NULL)
	{
		q=p;
		p = p->next;
	}
	new->next =p;
	q->next = new;
	return SUCCESS;
}

int delete_beg(node **head)
{
	node *p;
	int item;
	if(NULL == *head)
	{
		printf("List is empty\n");
		return FAILURE;
	}
	p = *head;
	item = p->data;
	if(NULL == p->next)
	{
		*head = NULL;
	}
	else
	{
		*head = p->next;
	}
	free(p);
	p = NULL;
	return item;
}

int delete_end(node **head)
{
	node *p, *q;
	int item;
	if(NULL == *head)
	{
		printf("List is empty\n");
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
	item = p->data;
	free(p);
	p = NULL;
}

int delete_mid(node **head, int pos)
{
	node *p, *q;
	int count, item;
	if(NULL == *head)
	{
		printf("The linked list is empty\n");
		return FAILURE;
	}
	
	p = *head;
	if(NULL == p->next)
	{
		head = NULL;
		item = p->data;
		free(p);
	}
	else
	{
		for(count=1; count<pos; count++)
		{
			q = p;
			p = p->next;
		}
		q->next = p->next;
		item = q->data;
		free(p);
		p = NULL;
	}
	return item;
}

int free_list(node **head)
{
	node *p;	
	if(NULL == *head)
	{
		printf("\n LIst is empty");
		return FAILURE;
	}
	if(NULL==(*head)->next)
	{
		free(*head);
		*head = NULL;
		printf("List freed");
		return SUCCESS;
	}
	p = (*head);
	while(NULL != p)
	{
		*head = (*head)->next;
		free(p);
		p = NULL;
		p = *head;
	}
	return SUCCESS;
}
