#include"myheader15.h"

int main()
{
	int choice, choice1, n, item, i;
	dnode *head = NULL, *tail = NULL;
	printf("To Create a List PRESS 1\n");
again:
	printf("To Insert Element at the beginning PRESS 2\n");
	printf("To Insert Element at the end PRESS 3\n");
	printf("To Insert Element in the middle PRESS 4\n");
	printf("To Delete Element from the beginning PRESS 5\n");
	printf("To Delete Element from the end PRESS 6\n");
	printf("To Delete Element from a specified position PRESS 7\n");
	printf("To free the list PRESS 8\n");
	printf("To Exit PRESS 9\n\n");
	do
	{
		printf("Enter your choice- ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				printf("Enter Number of nodes- ");
				scanf("%d",&n);
				create(&head, &tail, n);
				printf("\nList is- \n");
				display(&head, &tail);
				break;
		
			case 2:
				printf("Enter element to insert at the beginning- ");
				scanf("%d",&item);
				Insert_Beg(&head, &tail, item);
				printf("Element at the beginning has been inserted successfully.\n");
				printf("\nNew List is - \n");
				display(&head, &tail);
				break;

			case 3:
				printf("Enter element to insert at the end- ");
				scanf("%d",&item);
				Insert_End(&head, &tail, item);
				printf("Element at the end has been inserted successfully.\n");
				printf("\nNew List is - \n");
				display(&head, &tail);
				break;

			case 4:
				printf("Enter element to insert in the middle- ");
				scanf("%d",&item);
				Insert_Mid(&head, &tail, item);
				printf("Element at the middle has been inserted successfully.\n");
				printf("\nNew List is - \n");
				display(&head, &tail);
				break;
		
			case 5 :
				delete_beg(&head, &tail);
				printf("Element from the beginning has been deleted successfully.\n");
				printf("\nNew List is - \n");
				display(&head, &tail);
				break;

			case 6:
				delete_end(&head, &tail);
				printf("Element from the end has been deleted successfully.\n");
				printf("\nNew List is - \n");
				display(&head, &tail);
				break;

			case 7:
				printf("Enter the position to delete that specific element\n");
				scanf("%d",&n);
				i=delete_mid(&head, &tail, n);
				printf("Element (%d) from the given position (i.e. %d) has been deleted successfully.\n",i,n);
				printf("\nNew List is - \n");
				display(&head, &tail);
				break;
			
			case 8 :
				free_list(&head, &tail);
				break;

			case 9 :
				exit(1);
				break;
			
			default :
				printf("Wrong Choice\n");
		}
		printf("\n\nWant to enter more options?\nIf yes PRESS 1 otherwise PRESS 0\n");
		scanf("%d",&choice1);
		if(1 == choice1)
		{
			goto again;
		}
	}while(1 == choice1);
}


