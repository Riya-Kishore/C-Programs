#include"myheader17.h"

void add_name(cnode **head)
{
	cnode *new;	
	char namee[30];
	int i=0, len;
	new = (cnode *)malloc(sizeof(cnode));
	if(NULL == new)
	{
		printf("Memory Allocation Failure\n");
		exit(1);
	}
	printf("Enter name : ");
	memset(namee,0,30*sizeof(char));
	fgets(namee,29,stdin);
	while(namee[i] != '\n')
	{
		i++;
	}
	namee[i] = '\0';
	strcpy(new->name,namee);
	if(NULL == *head)
	{
		new->next = new;
		*head = new;
	}
	else if((*head) == (*head)->next)
	{
		new->next = *head;
		(*head)->next = new;
	}
	else
	{
		cnode *p = *head;
		while(*head != p->next)
		{
			p = p->next;
		}
		p->next = new;
		new->next = *head;
		
	}
}

char *del(cnode **temp)
{
	cnode *q;	
	char *namee;
	namee = (*temp)->name;
	q = *temp;
	while(q->next != *temp)
	{
		q = q->next;
	}
	if(q == ((*temp)->next))
	{
		q->next = q;
		*temp = q;
	}
	else
	{
		q->next = (*temp)->next;
		*temp = q->next;
	}
	return namee;
}
