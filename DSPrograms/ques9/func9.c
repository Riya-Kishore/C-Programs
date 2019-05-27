#include"myheader9.h"

int max(int arr[], int n)
{
	int max1, max2, i;
	max1=arr[0];
	for(i=0; i<n; i++)
	{
		if(arr[i]>max1)
		{
			max1=arr[i];
		}
	}
	printf("MAX1 = %d\n",max1);
	max2=arr[0];
	for(i=0; i<n; i++)
	{
		if(arr[i]>max2 && arr[i]<max1)
		{
			max2=arr[i];
		}
	}
	printf("MAX2 = %d\n",max2);
}

int check_sorting(int a[], int max)
{
	int i;
	for(i=0; i<max-1; i++)
	{
		if(a[i]>a[i+1])
		{
			return 0;
			break;
		}
	}
}

int rotate(int arr[], int max, int n)
{
	int i, j, temp;
	for(i=0; i<n; i++)
	{
		temp=arr[0];		
		for(j=0; j<max-1; j++)
		{
			arr[j]=arr[j+1];
		}
		arr[j]=temp;	
	}
	for(i=0; i<max; i++)
	{
		printf("%d ",arr[i]);
	}
	printf("\n");
}

int combine(int A[], int B[], int maxA, int maxB)
{
	int C[maxA], i, j, k;	
	for(i=0; i<maxA; i++)
	{
		for(j=0; j<maxB; j++)
		{
			if(A[i] == B[j])
			{
				C[k]=A[i];
				k++;
			}
		}
	}
	printf("NEW ARRAY IS- \n");
	for(i=0; i<k; i++)
	{
		printf("%d ",C[i]);
	}
	printf("\n");
}
