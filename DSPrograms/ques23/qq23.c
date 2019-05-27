#include<stdio.h>
#define SIZE 10
#define BEG 0
#define END SIZE-1
void bubble_sort(int arr[], int n);
void insertion_sort(int arr[], int n);
void selection_sort(int arr[], int n);
void merge_sort(int arr[], int beg, int end);
void merge(int arr[], int lb1, int ub1, int lb2, int ub2);
void quick_sort(int arr[], int beg, int end);
int partition(int arr[], int beg, int end);
void shell_sort(int arr[], int n);
void heap_sort(int arr[], int n);

int main(void)
{
	int arr[SIZE]; int i; int x;
	printf("Enter the elements of the array -\n");
	for(i = 0; i<SIZE; i++)
	{
		scanf("%d", &arr[i]);
	}
	/*Unsorted Array*/
	printf("Array elements before sorting -\n");
	for(i = 0; i<SIZE; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\nMethods for sorting -\n1. Bubble Sort\n2. Insertion Sort\n3. Selection Sort\n4. Merge Sort\n5. Quick Sort\n6. Shell Sort\n7. Heap Sort\n");
	scanf("%d", &x);
	switch(x)
	{
		case 1 : bubble_sort(arr,SIZE);
				 break;
		case 2 : insertion_sort(arr,SIZE);
				 break;
		case 3 : selection_sort(arr, SIZE);
				 break;
		case 4 : merge_sort(arr, BEG, END);
				 break;
		case 5 : quick_sort(arr, BEG, END);
				 break;
		case 6 : shell_sort(arr, SIZE);
				 break;
		case 7 : heap_sort(arr, SIZE);
				 break;
	}
	/*Sorted Array*/
	printf("\nArray elements after sorting -\n");
	for(i = 0; i<SIZE; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	return 0;
}
void bubble_sort(int arr[], int n)
{
	int i; int j; int swap; int temp;
	for(i = 0; i<n-1; i++)
	{
		swap = 0; //to check whether there is any swapping of elements
		for(j = 0; j<n-1-i; j++)
		{
			if(arr[j] > arr[j+1])
			{
				temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
				swap = 1;
			}
		}
		if(0 == swap) //if no swapping happened, it means that the array is sorted
		{ break; }
	}
}
void insertion_sort(int arr[], int n)
{
	int i; int j; int temp;
	for(i = 0; i<n; i++)
	{
		temp = arr[i]; j = i-1;
		while((temp < arr[j] && (j>=0)))
		{
			arr[j+1] = arr[j];
			j = j-1;
		}
		arr[j+1] = temp;
	}
}
void selection_sort(int arr[], int n)
{
	int i; int j; int min; int temp; int loc;
	for(i = 0; i<n-1; i++)
	{
		min = arr[i]; loc = i;
		for(j = i+1; j<n; j++)
		{
			if(arr[j] < min)
			{
				min = arr[j]; loc = j;
			}
		}
		if(loc != i)
		{
			temp = arr[i];
			arr[i] = arr[loc];
			arr[loc] = temp;
		}
	}
}
void merge_sort(int arr[], int beg, int end)
{
	int mid;
	if(beg<end)
	{
		mid = (beg+end)/2;
		merge_sort(arr,beg,mid);
		merge_sort(arr,mid+1,end);
		merge(arr,beg,mid,mid+1,end);
	}
}
void merge(int arr[], int lb1, int ub1, int lb2, int ub2)
{
	int c[SIZE];
	int i = lb1; int j = lb2; int k = 0;
	while((i<=ub1) && (j<=ub2))
	{
		if(arr[i] < arr[j])
		{
			c[k] = arr[i]; i++; k++;
		}
		else
		{
			c[k] = arr[j]; j++; k++;
		}
	}
	while(i<=ub1)
	{
		c[k] = arr[i]; i++; k++;
	}
	while(k<=ub2)
	{
		c[k] = arr[j]; j++; k++;
	}
	i = lb1, k = 0;
	while(i<=ub2)
	{
		arr[i] = c[k]; i++; k++;
	}
}
void quick_sort(int arr[], int beg, int end)
{
	printf("end = %d\n",end);
	if(beg < end)
	{
		int p;
		p = partition(arr, beg, end);
		quick_sort(arr, beg, p-1);
		quick_sort(arr, p+1, end);
	}
}
int partition(int arr[], int beg, int end)
{
	int left; int right; int loc; int temp;
	left = beg+1;
	right = end;
	loc = arr[beg];
	while(left<=beg)
	{
		while((arr[left] < loc) && (right < end))
		{
			left++;
		}
		while(arr[right] > loc)
		{
			right--;
		}
		if(left < right)
		{
			temp = arr[left];
			arr[left] = arr[right];
			arr[right] = temp;
			left++;
			right--;
		}
		else
		{
			left++;
		}
	}
	arr[beg] = arr[right];
	arr[right] = loc;
	return right;
		
}


void shell_sort(int arr[], int n)
{
	for (int gap = n/2; gap > 0; gap /= 2)
	{
		for (int i = gap; i < n; i += 1)
		{
			int temp = arr[i];
			int j;
			for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) { arr[j] = arr[j - gap]; }
			arr[j] = temp;
		}
	}
}

void heapify(int arr[], int n, int i)
{
	int largest = i;
	int l = 2*i + 1;
	int r = 2*i + 2;
	if (l < n && arr[l] > arr[largest]) { largest = l; }
	if (r < n && arr[r] > arr[largest]) { largest = r; }
	if (largest != i)
	{
		int tmp=arr[i];
		arr[i]=arr[largest];
		arr[largest]=tmp;
		heapify(arr, n, largest);
	}
}
void heap_sort(int arr[], int n)
{
	for (int i = n / 2 - 1; i >= 0; i--) { heapify(arr, n, i); }
	for (int i=n-1; i>=0; i--)
	{
		int tmp=arr[0];
		arr[0]=arr[i];
		arr[i]=tmp;
		heapify(arr, i, 0);
	}
}
