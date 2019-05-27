#include"myheader16.h"

int main(void)
{
	int n =0;	
	cnode *head = NULL; 
	int choice, choice1;
	char ch;
again:
	printf("TO ENTER THE POLYNOMIAL TERMS PRESS 1\n");
	printf("TO FIND THE DERIVATIVE OF THE POLYNOMIAL PRESS 2 \n");
	printf("TO EXIT PRESS 3\n");
	printf("\n\nEnter your choice :- ");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1 :
			create_poly(&head,&n);
			break;
		
		case 2 :
			printf("\nEnter the variable to use - ");
			getchar();
			scanf("%c",&ch);
			poly_deri(&head,ch,&n);
			break;
	
		case 3 :
			exit(1);
			break;
		
		default :
			printf("WRONG CHOICE \n");
	
	}
	printf("\n\nWant to perform operations?\nIf yes PRESS 1 otherwise PRESS 0\n\n");
	scanf("%d",&choice1);
	if(1 == choice1)
	{
		goto again;
	}
}
