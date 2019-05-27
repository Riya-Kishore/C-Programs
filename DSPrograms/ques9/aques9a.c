#include<stdio.h>
#define SIZE 5
int main()
{
	int i, arr[SIZE], max1, max2;
	printf("Enter elements of an array: \n");
	for(i=0; i<SIZE; i++)
	{
		scanf("%d",&arr[i]);
	}
	max1=arr[0];
	for(i=0; i<SIZE; i++)
	{
		if(arr[i]>max1)
		{
			max1=arr[i];
		}
	}
	printf("MAX1 = %d\n",max1);
	max2=arr[0];
	for(i=0; i<SIZE; i++)
	{
		if(arr[i]>max2 && arr[i]<max1)
		{
			max2=arr[i];
		}
	}
	printf("MAX2 = %d\n",max2);
}
	
