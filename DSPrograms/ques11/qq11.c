#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(int argc, char *argv[])
{
	int i, j=0, count = 0, len; 
	char **arr = NULL; 
	char str[30];
	int n = atoi(argv[1]);
	printf("You can enter %d number of strings only and 'end' will stop taking the input \n",n);
	arr = (char **)malloc((n)*sizeof(char *));
	if(NULL == arr)
	{
		printf("Memory allocation failure\n");
		exit(1);
	}
	memset(arr,0,(n)*sizeof(char));
	for(i=0;i<n;i++)
	{
		arr[j] = (char *)malloc(30*sizeof(char));
		if(NULL == arr)
		{
			printf("Memory allocation failure");
			exit(1);
		}
		memset(str,0,30*sizeof(char));
		printf("Enter string %d : ", i+1);
		fgets(str,29,stdin);
		len = strlen(str);
		if('\n' == str[len-1]) 
		{ 
			str[len-1] ='\0'; 
		}
		if(0 == strcmp(str,"end"))
		{
			break;
		}
		if(NULL != strstr(str,argv[2]))
		{	
			strcpy(arr[j],str);
			j++;
			count = j;
		}		
		else
		{
			free(arr[j]);
			arr[j] = NULL;
			j--;
		}
	}
	printf("Number of strings with pattern (%s) are %d\n",argv[2],count);
	printf("Concatenated String is : \n");
	for(i=j;i>=0;i--)
	{
		printf("%s ",arr[i]);
	}
	printf("\n");
	return 0;
}
