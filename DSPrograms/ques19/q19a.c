#include<stdio.h>
#include<stdlib.h>
#define MAX 50
char s[MAX];
int top=-1;
void push(char elem)
{
        s[++top]=elem;
}
char pop()
{
        return (s[top--]);
}
int pr(char elem)
{
        switch(elem)
        {
                case '#': return 0;
                case '(': return 1;
                case '+':
                case '-': return 2;
                case '*':
                case '/': return 3;
        }
}

int main()
{
	char infx[MAX],posfx[MAX],ch,elem;
	int i=0,k=0;
	printf("\nEnter the infix expression   : ");
	scanf("%s",infx);
	push('#');
	while((ch=infx[i++])!='\0')
	{
		if(ch=='(')
			push(ch);
		else
			if(isalnum(ch))
			posfx[k++]=ch;
		else if(ch==')')
		{
			while(s[top]!='(')
				posfx[k++]=pop();
			elem=pop();
		}
		else
		{
			while(pr(s[top])>=pr(ch))
				posfx[k++]=pop();
			push(ch);
		}
	}
	while(s[top]!='#')
		posfx[k++]=pop();
	posfx[k]='\0';
	printf("\nGiven Infix Expression  :  %s\nPostfix expression  :  %s\n",infx,posfx);
}
