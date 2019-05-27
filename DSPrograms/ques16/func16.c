#include"myheader16.h"

int create_poly(cnode **head, int *n)
{
	int choice1;
	cnode *new = NULL, *p = NULL; 
	printf("Enter the constant and exponent:- \n"); 
again:
	new = (cnode*)malloc(sizeof(cnode));
	if(NULL == new)
	{
		printf("Memory allocation faliure\n");
		exit(0);
	}
	memset(new,0,sizeof(cnode));
	printf("Constant %d\t", *n+1);
	scanf("%d", &new->cons);
	printf("Exponent %d\t", *n+1);
	scanf("%d", &new->expo);
	new->next = NULL;
	if(NULL == *head) 
	{
		*head = new;
	}
	else
	{
		p->next = new; 
	}
	p = new;
	(*n)++;
	printf("Wants to print more terms? (1/0) : ");
	scanf("%d",&choice1);	
	if(1 == choice1)
	{
		goto again;
	}
	p->next = *head; 
	return SUCCESS;
}

void poly_deri(cnode **head, char var, int *n)
{
	int i; 
	cnode *p = NULL; 
	if(NULL == *head)
	{
		printf("Linked list is empty\n");
	}
	else
	{
		printf("\nThe polynomial equation is - \n");
		p = *head;
		for(i = 0; i<(*n)-1; i++)
		{
			printf("%d(%c^%d) + ", p->cons, var,p->expo); 
			p = p->next;
		}
		printf("%d(%c^%d)\n", p->cons, var, p->expo); 
		
		printf("\nThe derivative of this polynomial equation is - \n");
		p = *head;
		for(i = 0; i<(*n)-1; i++)
		{
			printf("(%d)*(%c^%d) + ", ((p->expo)*(p->cons)), var, ((p->expo)-1));
			p = p->next;
		}
		printf("(%d)*(%c^%d)\n", ((p->expo)*(p->cons)), var, ((p->expo)-1)); 
	}
}
