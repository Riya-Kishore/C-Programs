#include<stdio.h>
#define SIZE_A 5
#define SIZE_B 10
int main()
{
	int i, A[SIZE_A], B[SIZE_B], C[SIZE_A], j, k=0;
	printf("Enter elements of an array arr1: \n");
	for(i=0; i<SIZE_A; i++)
	{
		scanf("%d",&A[i]);
	}

	printf("Enter elements of an array arr2: \n");
	for(i=0; i<SIZE_B; i++)
	{
		scanf("%d",&B[i]);
	}
	for(i=0; i<SIZE_A; i++)
	{
		for(j=0; j<SIZE_B; j++)
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
