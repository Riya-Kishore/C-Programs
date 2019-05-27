#include "myheader19.h"

int main()
{
	int i, len, flag, count, status;
	snode *top = NULL;
	char *str; 
	printf("\nEnter the equation in infix form : \n");
	str = (char *)malloc(30*sizeof(char));
	if(NULL == str)
	{
		printf("Memory allocation failure");
	}
	memset(str,0,30*sizeof(char));
	fgets(str,29,stdin);
	len = strlen(str);
	if('\n' == str[len-1]) 
	{ 
		str[len-1] ='\0'; 
	}
	count = -len;
	printf("\nThe postfix form of the given equation is : ");
	for(i = 0; i<len; i++)
	{
		flag = -1;
		if('+' == str[i] || '-' == str[i] || '*' == str[i] || '/' == str[i] || '^' == str[i])
		{
			flag = operate(str[i]);
			status = push(&top,str[i],flag);
		}
		else if('(' == str[i])
		{
			count++;
			flag +=count;
			status = push(&top,str[i],flag);
		}
		else if(')' == str[i])
		{
			status = pop(&top, str[i]);
		}
		else
		{
			printf("%c", str[i]);
		}
	}
	free(str);
	str = NULL; 
	printf("\n");
	return 0;
}


