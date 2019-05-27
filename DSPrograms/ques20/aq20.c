#include"myheader20.h"

int main()
{
	int choice, choice1, n;
	char name[30];
	char queue[MAX];
	printf("----CIRCULAR QUEUE OF NAMES USING ARRAY----\n");
	//printf("To Create a circular queue PRESS 1\n");
again:
	printf("To INSERT THE NAMES PRESS 1\n");
	printf("TO DELETE THE NAMES PRESS 2\n");
	printf("TO DISPLAY THE NAMES PRESS 3\n");
	printf("TO EXIT PRESS 5\n");
	do
	{
		printf("\nEnter your choice- \n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:	
				//char name[30];
				//int len;	
				printf("\nEnter the name to insert- \n");
				while('\n' != getchar())
				{
					;
				}
				memset(name,0,30*sizeof(char));
				fgets(name,29,stdin);	
				enqueue(queue,name);
				break;

			case 2 :				
				dequeue(queue);
				break;
				
			case 3 :
				display(queue);
				break;
			
			case 4:
				exit(1);
				break;
		}
		printf("\n\nWant to enter more option?\nIf yes PRESS 1 otherwise PRESS 0\n");
		scanf("%d",&choice1);
		if(1 == choice1)
		{
			goto again;
		}
	}while(1 == choice1);
}
