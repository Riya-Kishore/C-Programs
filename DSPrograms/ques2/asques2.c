#include<stdio.h>
int main()
{
	int a, temp, quo, rem=0, count=0, zero=0, one=0;
	printf("Enter number in binary- \n");
	scanf("%d",&a);
	temp=a;
	while(a>0)
	{
		quo=a/10;
		rem=a%10;
		
		if(rem==0)
		{
			zero++;
		}
		else 
		{
			one++;
		}
		a=quo;
		count++;
	}
	printf("Number of zeros = %d and number of ones = %d\n",zero,one);
}

