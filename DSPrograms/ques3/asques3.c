#include<stdio.h>

int main()
{
	unsigned int numb, i;
	printf("Enter a number- \n");
	scanf("%d",&numb);
	if(numb && !(numb&(numb-1)))
	{
		printf("%d is a power of 2\n",numb);
	}
	else
	{
		printf("%d is not a power of 2\n",numb);
	}
}

