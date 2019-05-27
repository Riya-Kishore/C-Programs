#include"myheader14.h"


int main()
{
	int choice, choice1, n, item;
	node *head = NULL;
	printf("To Create a List PRESS 1\n");
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
				create(&head, n);
				printf("\nList is- \n");
				display(&head);
				break;
		
			case 2:
				printf("Enter element to insert at the beginning- ");
				scanf("%d",&item);
				Insert_Beg(&head, item);
				printf("Element at the beginning has been inserted successfully.\n");
				printf("\nNew list is- \n");
				display(&head);				
				break;

			case 3:
				printf("Enter element to insert at the end- ");
				scanf("%d",&item);
				Insert_End(&head, item);
				printf("Element at the end has been inserted successfully.\n");
				printf("\nNew list is- \n");
				display(&head);				
				break;

			case 4:
				printf("Enter element to insert in the middle- ");
				scanf("%d",&item);
				Insert_Mid(&head, item);
				printf("Element at the middle has been inserted successfully.\n");
				printf("\nNew list is- \n");
				display(&head);
				break;
		
			case 5 :
				delete_beg(&head);
				printf("Element from the beginning has been deleted successfully.\n");
				printf("\nNew list is- \n");
				display(&head);
				break;

			case 6:
				delete_end(&head);
				printf("Element from the end has been deleted successfully.\n");
				printf("\nNew list is- \n");
				display(&head);
				break;

			case 7:
				printf("Enter the position to delete that specific element\n");
				scanf("%d",&n);
				delete_mid(&head, n);
				printf("Element from the given position (i.e %d) has been deleted successfully.\n",n);
				printf("\nNew list is- \n");
				display(&head);
				break;
			
			case 8 :
				free_list(&head);
				printf("list freed\n");
				break;

			case 9 :
				exit(1);
				break;
			
			default :
				printf("Wrong Choice\n");
		}
		printf("\n\nWant to enter more options?\nIf yes PRESS 1 otherwise PRESS 0\n");
		scanf("%d",&choice1);
	}while(1 == choice1);
}


