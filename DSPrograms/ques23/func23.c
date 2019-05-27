#include"myheader23.h"

void BubbleSort(int arr[], int MAX)
{
	int i, j, swap=0;
	for(i=0; i<MAX-1; i++)
	{
		for(j=0; j<MAX-1; j++)
		{
			if(arr[j]>arr[j+1])
			{
				int temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
				swap =1;
			}
		}
		if(0 == swap)
		{
			break;
		}
	}
}

void InsertionSort(int arr[], int MAX)
{
	int i, j, temp;
	for(i=1; i<MAX; i++)
	{
		temp = arr[i];
		for(j=i-1; j>=0 && temp<arr[j]; j--)
		{
			arr[j+1] = arr[j];
		}
		arr[j+1] =temp;
	}
}

void SelectionSort(int arr[], int MAX)
{
	int min, i, j, temp;
	for(i=0; i<MAX-1; i++)
	{
		min = i;
		for(j=i+1; j<MAX-1; j++)
		{
			if(arr[min] > arr[j])
			{
				min = j;
			}
		}
		if(min != i)
		{
			temp = arr[i];
			arr[i] = arr[min];
			arr[min] = temp;
		}
	}
}

void ShellSort(int arr[], int MAX)
{
	int i, flag=1, gap = MAX;
	while(1 == flag || gap>1)
	{
		flag = 0;
		gap = (gap+1)/2;
		for(i=0; i<MAX-gap; i++)
		{
			if(arr[i+gap]<arr[i])
			{
				int temp = arr[i+gap];
				arr[i+gap] = arr[i];
				arr[i] = temp;
			}
			flag = 0;
		}
	}
}

void QuickSort(int arr[], int beg, int end)
{
	if(beg < end)
	{
		int part = Partition(arr, beg, end);
		QuickSort(arr, beg, part-1);
		QuickSort(arr, part+1, end);
	}
}

int Partition(int arr[], int beg, int end)
{
	int temp, leftptr, rightptr, piv;
	leftptr = beg+1;
	rightptr = end;
	piv = arr[beg];
	while(leftptr<=rightptr)
	{
		while((arr[leftptr] < piv) && (rightptr < end))
		{
			leftptr++;
		}
		while(arr[rightptr] > piv)
		{
			rightptr--;
		}
		if(leftptr < rightptr)
		{
			temp = arr[leftptr];
			arr[leftptr] = arr[rightptr];
			arr[rightptr] = temp;
			leftptr++;
			rightptr--;
		}
		else
		{
			leftptr++;
		}
	}
	arr[beg] = arr[rightptr];
	arr[rightptr] = piv;
	return rightptr;
}

void MergeSort(int arr[], int beg, int end)
{
	int mid;
	if(beg < end)
	{
		mid = (beg + end)/2;
		MergeSort(arr, beg, mid);
		Merge(arr, beg, mid, end);
	}
}

void Merge(int arr[], int beg, int mid, int end)
{
	int i = beg, j = mid+1, index = beg, temp[10], k;
	while((i <= mid) && (j <= end))
	{
		if(arr[i] <= arr[j])
		{
			temp[index] = arr[i++];
		}
		else
		{
			temp[index] = arr[j++];
		}
		index++;
	}
	if(i > mid)
	{
		while(j <= end)
		{
			temp[index] = arr[j++];
			index++;
		}
	}
	else
	{
		while(i<=mid)
		{
			temp[index] = arr[i++];
			index++;
		}
	}
	for(int m= beg; m< index; m++)
	{
		arr[m] = temp[m];
	}
}

void display(int arr[], int MAX)
{
	printf("Array after sorting:- \n");
	for(int i=0; i<MAX; i++)
	{
		printf("%d\t",arr[i]);
	}
}
