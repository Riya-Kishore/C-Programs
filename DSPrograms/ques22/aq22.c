#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define max 20
void display(char **arr,int num);
void bubblesort(char **arr,int num);
int binarysearch(char **arr,int num,char item[]);
void main(void)
{
	printf("Enter how many names you want to enter : ");
	int num;
	scanf("%d",&num);
	if(num<1)
	{
		printf("invalid no. !! ");
		exit(0);
	}
	char **arr;
	arr=(char **)malloc(num*sizeof(char *));
	if(arr==NULL) { printf("memory allocation failure "); }
	for(int i=0;i<num;i++)
	{
		arr[i]=(char *)malloc(max);
		if(arr[i]==NULL) { printf("memory allocation failure"); }
	}
	for (int i=0;i<num;i++)
	{
		printf("please enter the name %d : ",i+1);
		scanf("%s",&arr[i][0]);
	}
	printf("\nThe sorted list of names is \n");
	bubblesort(arr,num);
	display(arr,num);
	printf("\nEnter the name you want to search:-  ");
	char item[max];
	scanf("%s",item);
	int result=binarysearch(arr,num,item);
	if (result!=-1) 
	{
		printf("The item \"%s\" is found at location %d in sorted array\n",item,result+1); 
	}
	else 
	{
		printf("the entered name is not found\n"); 
	}
}

void bubblesort(char **arr,int num)
{
	for(int i=0;i<num-1;i++)
	{
		int swap=0;
		for(int j=0;j<(num-1-i);j++)
		{
			if(strcmp(arr[j],arr[j+1]) > 0)
			{
				char temp[max];
				strcpy(temp,arr[j]);
				strcpy(arr[j],arr[j+1]);
				strcpy(arr[j+1],temp);
				swap=1;
			}
		}
		if(swap==0) { break; } //if it has been already sorted
	}
}
void display(char **arr,int num)
{
	for(int i=0;i<num;i++)
	{
		printf("%s\n",arr[i]);
	}
}
int binarysearch(char**arr,int num, char item[])
{
	int start=0;
	int end=num;
	int mid;
	int r;
	while(end>start)
	{ mid=((start+end)/2);
		r=strcmp(item,arr[mid]);
		if(r==0) { return mid; }
		else if(r<0) { end=mid; }
		else { start=mid; }
	}
	return -1;
}
