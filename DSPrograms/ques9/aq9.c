#include<stdio.h>
#define SIZE 5

int check_sorting(int a[SIZE]);
int main()
{
	int i, arr[SIZE], flag;
	printf("Enter elements of an array: \n");
	for(i=0; i<SIZE; i++)
	{
		scanf("%d",&arr[i]);
	}
	flag=check_sorting(arr);
	if(1==flag)
	{
		printf("Array is sorted\n");
	}
	else
	{
		printf("Array is not sorted\n");
	}
}
int check_sorting(int a[SIZE])
{
	int i;
	for(i=0; i<SIZE; i++)
	{
		if(a[i]<a[i+1])
		{
			return 1;
			break;
		}
		return 0;
	}
}
