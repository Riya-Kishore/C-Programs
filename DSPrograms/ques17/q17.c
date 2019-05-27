#include"myheader17.h"

int main()
{
	cnode *head = NULL, *temp; 
	int i, m, n, choice, choice1;
again:
	printf("\nTO ENTER THE NAMES PRESS 1 \n");
	printf("TO ELIMINATE THE NAMES PRESS 2 \n");
	printf("TO EXIT PRESS 3\n");
	printf("\nEnter your choice : ");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1 :
			printf("Enter the number of names you want to enter :   ");
			scanf("%d", &n);
			while('\n' != getchar())
			{	
				;
			}
			for(i=0; i<n; i++)
			{
				add_name(&head);
			}
			break;

		case 2 :
			temp = head;
			printf("\nEnter the lucky number : ");
			scanf("%d",&m);
			while(temp->next != temp)
			{
				char *arr;
				for(i=1; i<m; i++)
				{
					temp = temp->next;
				}
				arr = del(&temp);
				printf("Eliminated Name : %s\n",arr);
			}
			printf("\nThe Winner is : %s\n",temp->name);
			break;
		
		case 3 :
			exit(1);
			break;

		default :
			printf("Wrong Choice\n");
	}
	printf("\n\nWant to perform more options?\nIf yes PRESS 1 otherwise PRESS 0\t");
	scanf("%d",&choice1);
	if(1 == choice1)
	{
		goto again;
	}
}


