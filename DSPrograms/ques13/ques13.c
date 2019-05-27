#include"myheader13.h"

int main()
{
	int choice, choice1, n;
	FILE *fptr;
	int len, num, id, i;
	char name[30];
	e1 *emp;
	e1 **arr;
	printf("Enter number of records\n");
	scanf("%d",&n);	
	emp =(e1 *)malloc(n*sizeof(e1));
	if(NULL == emp)
	{
		printf("Memory Allocation Failed\n");
		exit(1);
	}
	
	arr = (e1 **)malloc(n*sizeof(e1 *));
	if(NULL == arr)
	{
		printf("Memory allocation failure\n");
		exit(1);
	}

	for(i = 1; i<=n; i++) 
	{
		arr[i] = (e1 *)malloc(sizeof(e1 *));
		if(NULL == arr[i])
		{
			printf("Memory allocation failure\n");
			break;
		}
		memset(arr[i],0,sizeof(e1 *));
	}
	for(i = 1; i<=n; i++)
	{
		arr[i]->name = (char *)malloc(30*sizeof(char));
		if(NULL == arr[i]->name)
		{
			printf("Memory allocation failure\n");
			break;
		}
		memset(arr[i]->name,0,30*sizeof(char));
		arr[i]->dept = (char *)malloc(30*sizeof(char));
		if(NULL == arr[i]->dept)
		{
			printf("Memory allocation failure\n");
			break;
		}
		memset(arr[i]->dept,0,30*sizeof(char));
	}

	if(NULL == (fptr=fopen("records","wb")))
	{
		printf("Error in opening file\n");
		exit(1);
	}

	printf("ENTER RECORDS\n");
	for(i=1; i<=n; i++)
	{
		printf("\nEnter ID : ");
		scanf("%d",&arr[i]->id);
		printf("Enter Name: ");
		while('\n' != getchar())
		{
			;
		}
		fgets(arr[i]->name, 29, stdin);
		len = strlen(arr[i]->name);
		if('\n' == arr[i]->name[len-1])
		{
			arr[i]->name[len-1]='\0';
		}
		printf("Enter Department: ");
		fgets(arr[i]->dept, 29, stdin);
		len = strlen(arr[i]->dept);
		if('\n' == arr[i]->dept[len-1])
		{
			arr[i]->dept[len-1]='\0';
		}
		printf("Enter Phone Number: ");
		scanf("%d",&arr[i]->ph_num);
		fwrite(&arr[i], sizeof(arr[i]), 1, fptr);
		printf("\n");

	}
	fclose(fptr);
again :
	printf("\n\n");
	printf("TO DISPLAY THE RECORD BY NAME PRESS 1\n");
	printf("TO UPDATE THE PHONE NUMBER BY EMPLOYEE ID PRESS 2\n");
	printf("TO EXIT PRESS 3\n");
	do
	{
		printf("Enter your choice\n");
		scanf("%d",&choice);		
		switch(choice)
		{
			case 1:
				record_name(arr,n);
				break;

			case 2:
				update_record(arr,n);
				break;

			case 3:
				exit(1);
			
			default :
				printf("WRONG CHOICE\n");
		}
		printf("\n\nWant to enter more option ?\nIf YES press 1 otherwise press 0\n");
		scanf("%d",&choice1);
		if(1 == choice1)
		{
			goto again;
		}
	}while(1 == choice1);
	for(i=1; i<=n; i++)
	{
		free(arr[i]->name); 
		arr[i]->name = NULL;
		free(arr[i]->dept); 
		arr[i]->dept = NULL;
		free(arr[i]); 
		arr[i] = NULL;
	}
	free(arr);
	arr = NULL;	
}
