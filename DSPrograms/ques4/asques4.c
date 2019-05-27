#include<stdio.h>

int main()
{
	int no, pos = 0, neg = 0, zero = 0, option;
	do 
	{
		printf("Enter the  number : ");
		if(scanf("%d", &no) == 1)
		{
			if(no > 0) 
			{
				printf("%d is a positive number\n", no); 
				pos++; 
			}
			else if(no < 0) 
			{
				printf("%d is a negative number\n", no); 
				neg++; 
			}
			else 
			{
				printf("You have entered a zero\n");
				zero++; 
			}
		}
		else
		{
			printf("\nWrong Input! Please Enter the integer value\n");
		}
		while( '\n' != getchar())
		{
			;
		}
		printf("\nDo you want to enter more numbers?\nIf 'yes' PRESS 1 otherwise PRESS 0.\n");
		scanf("%d", &option);
		while( '\n' != getchar())
		{
			;
		}
	}while(1 == option);
	printf("The number of positive number(s) : %d , negative number(s) : %d and zeros : %d\n", pos, neg, zero);
	return 0;
}
