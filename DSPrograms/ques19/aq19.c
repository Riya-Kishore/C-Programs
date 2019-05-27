#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define SUCCESS 1
#define FAILURE 0
typedef struct snode
{
	char str1;
	int flag1;
	struct snode *next;
}snode;
int operator(char str);
int push(snode **top, char str, int flag);
int pop(snode **top, char str);
int main(void)
{
	int i; int len;
	snode *top = NULL;
	char *str; int flag; int count; int status;
	printf("Enter the equation in infix form : ");
	str = (char *)malloc(30*sizeof(char));
	//snode *test = NULL;
	//test = (snode *) malloc(sizeof(snode));
	printf("\nAllocated\n");
	if(NULL == str)
	{
		printf("Memory allocation failure");
	}
	/*while('\n' != getchar()) ////////////////////////Check this one
	{
		;
	}*/
	memset(str,0,30*sizeof(char));
	fgets(str,29,stdin);
	len = strlen(str);
	if('\n' == str[len-1]) { str[len-1] ='\0'; }
	count = -len;
	printf("The postfix form of the given equation is : ");
	for(i = 0; i<len; i++)
	{
		flag = -1;
		//printf("%c\n",str[i]);
		//putchar(str[i]);
		if('+' == str[i] || '-' == str[i] || '*' == str[i] || '/' == str[i] || '^' == str[i])
		{
			//printf("\n1\n");
			flag = operator(str[i]);
			status = push(&top,str[i],flag);
		}
		else if('(' == str[i])
		{
			//printf("\n2\n");
			count++;
			flag +=count;
			status = push(&top,str[i],flag);
		}
		else if(')' == str[i])
		{
			//printf("\n3\n");
			status = pop(&top, str[i]);
			//printf("%s", item);
		}
		else
		{
			printf("%c", str[i]);
			//putchar(str[i]);
		}
	}
	free(str);
	str = NULL; 
	//printf("\n4\n");
	return 0;
}

int operator(char str)
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
	//printf("p1");
	//printf("/n character - %c\n", str);
	//printf("/n its flag value - %d\n", flag);
	snode *new;
	new = (snode *)malloc(sizeof(snode));
	if(NULL == new)
	{
		printf("Memory allocation faliure\n");
		return FAILURE;
		exit(0);
	}
	//printf("2");
	memset(new,0,sizeof(snode));
	new->flag1 = flag;
	new->str1 = str;
	//printf("%c", str);
	new->next = NULL;
	//printf("P2");
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
				pop(top, str); //pop(&*(top));
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
	if(NULL == (*top)->next)	//ONLY ITEM
	{
		free(*top);
		*top = NULL;
		//it(0);
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
