#include"myheader10.h"

int main()
{
	int choice, ROWS = COLUMNS, arr[ROWS][COLUMNS], choice1;
	printf("NUMBER OF ROWS = NUMBER OF COLUMNS = %d \n",COLUMNS);
	printf("TO ENTER THE ELEMENTS OF MATRIX PRESS 1\n");
	printf("TO DISPLAY THE ELEMENTS OF MATRIX PRESS 2\n");
	printf("TO CHECK WHETHER THE ENTERED MATRIX IS A MAGIC SQUARE OR NOT PRESS 3\n");
	printf("TO EXIT PRESS 4\n");
	do
	{
		printf("\nENTER YOUR CHOICE\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: 
				get_input(arr,ROWS);
				break;
			
			case 2:
				display(arr,ROWS);
				break;
		
			case 3:
				check_magic_square(arr,ROWS);
				break;

			case 4:
				exit(1);
				break;

			default :
				printf("wrong choice\n");
				break;
		}
		printf("\nWANT TO ENTER MORE OPTIONS?\nIF YES PRESS 1 OTHERWISE PRESS 0\n");
		scanf("%d",&choice1);
	}while(1==choice1);
}	
	
