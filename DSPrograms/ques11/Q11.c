#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(int argc, char *argv[])
{
	int i; char **p = NULL; int j = 0; int len;
	//printf("argc = %d\n",argc);
	int n = atoi(argv[1]);
	printf("value of total no of arguments - %s (in int n = %d)\n", argv[1], n);
	printf("total command line arguments are - %d\n", argc);
	p = (char**)malloc((n)*sizeof(char));
	if(NULL == p)
	{
		printf("Memory allocation failure");
		exit(0);
	}
	memset(p,0,(n)*sizeof(char));
	for(i=0;i<n;i++)
	{
		//printf("argv[%d] = %s\n",i,argv[i]);
		p[j] = (char *) malloc(30*sizeof(char));
		//printf("%d %d", j, i);
		
		if(NULL == p)
		{
			printf("Memory allocation failure");
			exit(0);
		}
		memset(p[j],0,30*sizeof(char));
		//printf("7 string - %s and %s", (p+j), &p[j]);
		/*while('\n' != getchar()) ////////////////////////Check this one
		{
			;
		}*/
		printf("Print your string p[%d]-\t", j);
		fgets(p[j],29,stdin);
		len = strlen(p[j]);
		if('\n' == p[j][len-1]) { p[j][len-1] ='\0'; }			
		if(NULL == strstr(p[j],argv[2]))
		{
			free(p[j]);
			p[j] = NULL;
			printf("Your string no p[%d] has been freed\n", j);
			j--;
		}
		else
		{
			printf("string p[%d] is %s\n", j,p[j]);
		}
		j++;
	}
	for(i=j-1;i>=0;i--)
	{
		printf("%s->",p[i]);
	}
	return 0;
}
