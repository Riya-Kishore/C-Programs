#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define number 10
#define max 40
int hashfunction(char[]);
int main()
{
	char** hashtable;
	int collison=0;
	hashtable=(char **)calloc(number,sizeof(char*));
	if(hashtable==NULL)
	{
		printf("memory allocation failure \n");
		exit(0);
	}
	for (int i=0;i<number;i++)
	{
		hashtable[i]=(char *)calloc(max,sizeof(char));
		if(hashtable==NULL)
		{
			printf("memory allocation failure \n");
			exit(0);
		}
	}
	printf("HASH TABLE OF SIZE 10 F0R 10 STRINGS \n");
	for (int i=0;i<number;i++)
	{
		printf("enter the string :%d \n",i+1);
		char temp[max];
		fgets(temp,max,stdin);
		int n=0;
		while(temp[n]!='\n') { n++; }
		temp[n]='\0';
		int key=hashfunction(temp);
		printf(" the key generated is %d\n",key);
		if(hashtable[key][0]==0) { strcpy(hashtable[key],temp); }
		else
		{
			collison++;
			while(hashtable[key][0]!=0)
			{
				key=(key+1)%number;
			}
			strcpy(hashtable[key],temp);
		}
	}	
	printf("\nthe number of collison is %d \n",collison);
	printf("\nthe hashing table is \n");
	printf("------------------------------------------\n");
	printf("key\tdata\n");
	for(int i=0;i<number;i++)
	printf("%d\t%s\n",i,hashtable[i]);
	free(hashtable);
}

int hashfunction(char temp[])
{
	int a=0,sum=0;
	while(temp[a]!='\n')
	{
		sum=sum+temp[a];
		a++;
	}
	int key=sum%number;
	return key;
}
