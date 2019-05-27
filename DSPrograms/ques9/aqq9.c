#include<stdio.h>
#define SIZE 5

//int check_sorting(int a[SIZE]);
int main()
{
	int i, j, arr[SIZE], n, temp;
	printf("Enter elements of an array: \n");
	for(i=0; i<SIZE; i++)
	{
		scanf("%d",&arr[i]);
	}
	printf("enter number to rotate the array\n");
	scanf("%d",&n);
	for(i=0; i<n; i++)
	{
		temp=arr[0];		
		for(j=0; j<SIZE-1; j++)
		{
			arr[j]=arr[j+1];
		}
		arr[j]=temp;	
	}
	for(i=0; i<SIZE; i++)
	{
		printf("%d ",arr[i]);
	}
	printf("\n");
}
