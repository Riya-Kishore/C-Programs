#include"myheader.h"
int main()
{
	int item,i,ch,n,c,arr[max];
	printf("\nEnter the no of elements for th array: ");
	scanf("%d",&n);
	printf("\nEnter the elemnts: ");
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);
	for(i=0;i<n;i++)
		printf("%d ",arr[i]);
	printf("\n1.Selection Sort\n2.Bubble Sort\n3.Insertion Sort\n4.Quick Sort\n5.Merge Sort\n6.Redix Sort\n7.Exit\n>");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:{
			       printf("\nArray after Selection Sorting: ");
			       selection(arr,n);
			       display(arr,n);
			       break;
		       }
		case 2:{
			       printf("\nArray after Bubble Sorting: ");
			       bubble(arr,n);
			       display(arr,n);
			       break;
		       }
		case 3:{
			       printf("\nArray after Insertion Sorting: ");
			       insertion(arr,n);
			       display(arr,n);
			       break;
		       }
		case 4:{
			       printf("\nArray after Quick Sorting: ");
			       quick(arr,0,n);
			       display(arr,n);
			       break;
		       }
		case 5:{
			       printf("\nArray after Merge Sorting: ");
			       merge(arr,0,n-1);
			       display(arr,n);
			       break;
		       }
		case 6:{
			       printf("\nArray after Redix Sorting: ");
			       redix(arr,n);
			       display(arr,n);
			       break;
		       }
		case 7:{
			       display(arr,n);
			       exit(0);
		       }
		default:break;
	}
}
