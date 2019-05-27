#include"myheaderr.h"

float FTOC(float temp)
{
	float C;
	C=((temp-32)*5)/9;
	return C;
}

int PRIME_NO(unsigned int numb)
{
	int flag=0;
	if(numb%2==0)
	{
		flag=1;
	}
	if(1==flag)
	{
		printf("%d is not a prime number\n",numb);
	}
	else
	{
		printf("%d is a prime number\n",numb);
	}
}


int REVERSE(unsigned int no)
{
	int rem=0, quo=0;
	if(0==no)
	{
		return;
	}

	rem = no % 10;
	printf("%d",rem);
	quo = no / 10;
	no = REVERSE(quo);
	
}

		
