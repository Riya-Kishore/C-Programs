#include"myheader13.h"

int record_name(e1 **arr, int n)
{	
	FILE *fptr;
	int i, len;
	char name[30];
	
	printf("\nEnter the name of employee : ");
	memset(name, 0, 30*sizeof(char));
	while('\n' != getchar())
	{
		;
	}
	fgets(name, 29, stdin);
	len = strlen(name);
	if('\n' == name[len-1])
	{
		name[len-1]='\0';
	}
	if(NULL == (fptr=fopen("records", "rb")))
	{
		printf("Error in opening file\n");
		exit(1);
	}

	for(i=1; i<=n; i++)
	{
		while(1 == fread(&arr[i], sizeof(arr[i]), 1, fptr))
		{	
			if(0 == strcmp(arr[i]->name, name))
			{
				printf("Employee ID : %d\n",arr[i]->id);
				printf("Name : %s\n",arr[i]->name);
				printf("Department : %s\n",arr[i]->dept);
				printf("Phone Number : %d\n",arr[i]->ph_num);
				break;
			}
			break;
		}
	}
	fclose(fptr);
}

int update_record(e1 **arr, int n)
{
	FILE *fptr;
	int id, i;	
	if(NULL == (fptr=fopen("records", "rb+")))
	{
		printf("Error in opening file\n");
		exit(1);
	}
	printf("\n\nEnter the Employee ID to update the phone number: ");
	scanf("%d",&id);
	for(i=1; i<=n; i++)
	{
		while(1 == fread(&arr[i], sizeof(arr[i]), 1, fptr))
		{
			if(id == arr[i]->id)
			{
				printf("\nEnter new phone number: ");
				scanf("%d",&arr[i]->ph_num);
				fwrite(&arr[i], sizeof(arr[i]), 1, fptr);
				break;
			}
		}	
	}
	fclose(fptr);
}
