#include"myheader23.h"

int main()
{
	int choice, n, i, j;
	int arr[MAXSIZE];
	n = MAXSIZE;
	printf("Enter the elements of an array:- \n");
	for(i=0; i<n; i++)
	{
		scanf("%d",&arr[i]);
	}
	printf("\nYou can sort an array using following techniques:- \n");
again:
	printf("1.- BUBBLE SORT\n 2.- INSERTION SORT \n 3.- SELECTION SORT \n 4.- SHELL SORT \n 5.- QUICK SORT \n 6.- MERGE SORT\n 7.- EXIT\n");	
	printf("\nSelect one option- ");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:
			BubbleSort(arr,n);
			display(arr,n);
			break;

		case 2:
			InsertionSort(arr,n);
			display(arr,n);
			break;
		
		case 3:
			SelectionSort(arr,n);
			display(arr,n);
			break;

		case 4:
			ShellSort(arr,n);
			display(arr,n);
			break;
	
		case 5:
			QuickSort(arr,0,n-1);
			display(arr,n);
			break;

		case 6:
			MergeSort(arr,0,n);
			display(arr,n);
			break;
		
		case 7:
			exit(1);
			break;

		default:
			printf("Wrong Choice\n");

	}
	printf("\nWant to opt more options?\nIf yes press 1 ortherwise press 0\n");
	scanf("%d",&j);
	while(1 == j)
	{
		goto again;
	}
}
	
