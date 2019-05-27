#include"myheader19.h"

int operate(char str)
{
	switch(str)
	{
		case '+' : return 1; break;
		case '-' : return 1; break;
		case '*' : return 2; break;
		case '/' : return 2; break;
		case '^' : return 3; break;
	}
}

int push(snode **top, char str, int flag)
{
	snode *new;
	new = (snode *)malloc(sizeof(snode));
	if(NULL == new)
	{
		printf("Memory allocation faliure\n");
		return FAILURE;
		exit(0);
	}
	memset(new,0,sizeof(snode));
	new->flag1 = flag;
	new->str1 = str;
	new->next = NULL;
	if(NULL == *top)
	{
		new->next = NULL;
	}
	else
	{
		if('(' != new->str1)
		{
			if((*top)->flag1 >= new->flag1)
			{
				pop(top, str); 
			}
		}
	new->next = *top;
	}
	*top = new;
	return SUCCESS;
}

int pop(snode **top, char str)
{
	snode *p = NULL; char item;
	if(')' == str)
	{
		while('(' != (*top)->str1)
		{
			if(NULL == *top)
			{
				printf("Stack overflow");
				return FAILURE;
			}
			p = *top;
			char item = p->str1;
			if(NULL != p->next)
			{
				*top = p->next;
			}
			printf("%c",item);
			free(p);
			p = NULL;
		}
	}
	if(NULL == (*top)->next)	
	{
		free(*top);
		*top = NULL;
	}
	else
	{
		p = *top;
		*top = p->next;
		free(p);
		p = NULL;
	}
	return SUCCESS;
}
