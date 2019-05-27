#include"myheader.h"

float calci(float x, float y)
{
	int choice;
	char op;
	float res;
	do{
		printf("\nEnter Your Choice To perform operation: ");
		getchar();
		scanf("%c",&op);
		switch(op)
		{
			case '+':
				res=addition(x,y);
				printf("Result= %f\n",res);
				break;
			case '-':
				res=subtraction(x,y);
				printf("Result= %f\n",res);
				break;
			case '*':
				res=multiplication(x,y);
				printf("Result= %f\n",res);
				break;
			case '/':
				res=division(x,y);
				printf("Result= %f\n",res);
				break;
			case '!':
				exit(1);
				break;
			default :
				printf("Wrong Choice");
		}
		x=res;
		printf("Want to perform more operations? \n If yes then press 1 otherwise press 0\n ");
		scanf("%d",&choice);
		if(0==choice)
		{
			exit(0);
		}
		printf("Enter b-");
		scanf("%f",&y);
		printf("a = %f | b= %f\n",x,y);

	}while(1==choice);

}
float addition(float a, float b)
{
	return(a+b);
}
float subtraction(float a, float b)
{
	return(a-b);
}
float multiplication(float a, float b)
{
	return(a*b);
}
float division(float a, float b)
{	
	return(a/b);
}
