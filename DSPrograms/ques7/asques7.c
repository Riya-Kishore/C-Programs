#include"myheaderr.h"

int main()
{
	int choice, choice1;
	unsigned int numb, no;
	float temp, C;
	printf("-----MENU------\n");
	printf("To Convert Fahrenheit Temperature into Celcius PRESS 1\n");
	printf("To Determine whether a given Positive Number is Prime Or Not PRESS 2\n");
	printf("To Reverse the digits of given Positive Number PRESS 3\n");
	printf("To Exit Press 4\n");
	do{
		printf("Enter your choice-");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				printf("Enter The Value of Temperature in Fahrenheit- \n");
				scanf("%f",&temp);
				C= FTOC(temp);
				printf("Temperature in Celcius = %f\n",C);
				break;

			case 2:
				printf("Enter number to check whether it is prime or not- \n");
				scanf("%d",&no);
				PRIME_NO(no);
				break;
		
			case 3:
				printf("Enter a number to reverse- \n");
				scanf("%d",&numb);
				REVERSE(numb);
				break;
			
			case 4:
				exit(1);
				break;
		
			default:
				printf("Wrong Choice\n");
		}
		printf("\nDo you want to enter more options?\nIf yes PRESS 1 otherwise PRESS 0\n");
		scanf("%d",&choice1);
		
	}while(1 == choice1);
	printf("\n");
}

