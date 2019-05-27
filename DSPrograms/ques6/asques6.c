#include"myheader6.h"

int main()
{
	float b,h,s,r;
	float ta,ca,sa;
	int choice, choice1;
	do
	{
		printf("\n---Choose One---\n");
		printf("1. Area of Triangle \n");
		printf("2. Area of Square \n");
		printf("3. Area of Circle \n");
		printf("4. Exit\n");
		printf("Enter Your Choice : ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1 :
				printf("Enter the value of base and height : \n");
				printf("Base : ");
				scanf("%f",&b);
				printf("Height : ");
				scanf("%f",&h);
				ta= tri_ar(b,h);
				printf("Area of Triange with base(%f) and height(%f) = %f\n",b,h,ta);
				break;
	
			case 2 :
				printf("Enter the value of side : ");
				scanf("%f",&s);
				sa= squ_ar(s);
				printf("Area of Square with sides(%f) = %f\n",s,sa);
				break;
	
			case 3:
				printf("Enter the value of radius : ");
				scanf("%f",&r);
				ca= cir_ar(r);
				printf("Area of Circle with radius(%f) = %f\n",r,ca);
				break;
	
			case 4:
				exit(1);
				break;

			default :
				printf("Wrong Choice\n");
		}
		printf("\nWant to choose more options?\nIf yes PRESS 1 otherwise PRESS 0\n");
		scanf("%d",&choice1);
	}while(1==choice1);
}

