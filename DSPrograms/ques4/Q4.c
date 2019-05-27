#include<stdio.h>
int main(void)
{
	int no; int pos = 0, neg = 0, zero = 0; int option;
	do {
		printf("Enter the  number : ");
		if(scanf("%d", &no) == 1)
		{
			printf("\nEntered number is %d\n", no);
			if(no > 0) { pos++; }
			else if(no < 0) { neg++; }
			else { zero++; }
		}
		else
		{
			printf("Enter the integer value\n");
		}
		while( '\n' != getchar())
		{
			;
		}
		printf("Do you want to enter more numbers (yes = 1 and no = 0) :");
		scanf("%d", &option);
		while( '\n' != getchar())
		{
			;
		}
	}while(1 == option);
	printf("The no of positive number(s) - %d , negative number(s) - %d and zeros - %d\n", pos, neg, zero);
	return 0;
}