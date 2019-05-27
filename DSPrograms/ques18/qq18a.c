#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#define sum ((side1+side2+side3)/2)
#define side1 a
#define side2 b
#define side3 c
#define side4 d
#define pi 3.14
#define radius r
int area(int);
int main()
{
	int e; float output;
	printf("Choices you have :\n");
	printf("1. Area of triangle\n2. Area of rectangle\n3. Area of circle\n4. Exit\n");
	printf("Choose your Choice :\n");
	scanf("%d",&e);
	output = area(int a);
	printf("%f", output);
	return 0;
}

int area(int a)
{
	switch(a)
	{
		case 1: //float a,b,c;
				printf("The sides are :");
				scanf("%f %f %f", &side1,&side2,&side3);
				if(side1 == side2+side3 || side2 == side1+side3 || side3 == side1+side2)
				{
					return pow((sum*(sum - side1)*(sum - side2)*(sum - side3)),(1/2));
				}
				else
				{
					printf("Triangle is not possible");
				}
				break;
		case 2: //float a,b,c,d;
				printf("The sides are :");
				scanf("%f %f %f %f", &side1,&side2,&side3, &side4);
				if(side1 == side2 == side3 == side4)
				{
					return pow(side1,2);
				}
				else
				{
					printf("Square is not possible");
				}
				break;
		case 3: //float r;
				printf("The radius of circle is :");
				scanf("%f", &radius);
				return pi*pow(radius,2);
				break;
		default:exit(0);
	}
}