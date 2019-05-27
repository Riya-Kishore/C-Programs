#include<stdio.h>

int main()
{
	unsigned int numb, mask;
	int i, zero=0, one=0;
	printf("Enter a number- \n");
	scanf("%d",&numb);
	for(i=0; i<32; i++)
	{
		mask = 1<<i;
		if(0==(numb&mask))
		{
			zero++;
		}
		else
		{
			one++;
		}
	}
	printf("Number of zeros = %d and ones = %d\n",zero,one);
}	
