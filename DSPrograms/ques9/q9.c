#include"myheader9.h"

int main()
{
	int i, arr[SIZE], flag=0, n, temp, choice, choice1;
	int A[SIZE_A], B[SIZE_B];

	printf("Pre-defined sizes are SIZE = %d || SIZE_A = %d || SIZE_B = %d \n",SIZE,SIZE_A,SIZE_B);
again:
	printf("\n---DIFFERENT OPERATIONS ON ARRAYS---\n");
	printf("1 : Find Maximum and second maximum value of an array of integers.\n");
	printf("2 : Rotates an array of integers a given number of positions.\n");
	printf("3 : Determines whether a given array is sorted.\n");
	printf("4 : Array C that contains elements that are common to A and B.\n");
	printf("5 : Exit\n");
	printf("Enter your choice : ");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1 :
			printf("Enter elements(%d) of an array: \n",SIZE);
			for(i=0; i<SIZE; i++)
			{
				scanf("%d",&arr[i]);
			}			
			max(arr,SIZE); 
			break;			
	
		case 2 :
			printf("Enter elements(%d) of an array: \n",SIZE);
			for(i=0; i<SIZE; i++)
			{
				scanf("%d",&arr[i]);
			}
			printf("enter number to rotate the array\n");
			scanf("%d",&n);
			rotate(arr,SIZE,n);
			break;

		case 3 :
			printf("Enter elements(%d) of an array: \n",SIZE);
			for(i=0; i<SIZE; i++)
			{
				scanf("%d",&arr[i]);
			}
			flag=check_sorting(arr,SIZE);
			if(0 == flag)
			{
				printf("Array is not sorted\n");
			}
			else
			{
				printf("Array is sorted\n");
			}
			break;
		
		case 4 :
			printf("Enter elements(%d) of an array arr1: \n",SIZE_A);
			for(i=0; i<SIZE_A; i++)
			{
				scanf("%d",&A[i]);
			}

			printf("Enter elements(%d) of an array arr2: \n",SIZE_B);
			for(i=0; i<SIZE_B; i++)
			{
				scanf("%d",&B[i]);
			}
			combine(A,B,SIZE_A,SIZE_B);
			break;

		case 5 :
			exit(1);
			break;

		default :
			printf("Wrong Choice\n");
	}
	printf("\nWant to perform more operations?\nIf yes PRESS 1 otherwise PRESS 0\n");
	scanf("%d",&choice1);
	if(1 == choice1)
	{
		goto again;
	}
}
