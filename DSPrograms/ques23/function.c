#include"myheader.h"
void display(int *arr,int n)
{
	printf("\n");
	for(int i=0;i<n;i++)
		printf(" %d",arr[i]);
}
void quick(int *arr,int beg,int end)
{
	int p;
	if(beg<end)
	{
		p=part(arr,beg,end);
		quick(arr,beg,p-1);
		quick(arr,p+1,end);
	}
}
void clearbuk(int n,int arr[][n])
{
	int i,j;
	for(i=0;i<10;i++)
		for(j=0;j<n;j++)
			arr[i][j]=-1;
}
void redix(int *arr,int n)
{
	int ma,i,j,k,l,a,temp,it1,it2,pass=0;
	int buk[10][n];
	ma=arr[0];
	for(i=0;i<n;i++)
	{
		if(ma<arr[i])
			ma=arr[i];
	}
	while(0!=ma)
	{
		pass++;
		ma/=10;
	}
	it1=1;
	it2=1;
	for(i=0;i<pass;i++)
	{
		if(i>0)
			it1*=10;
		it2*=10;
		k=0;
		clearbuk(n,buk);
		for(j=0;j<n;j++)
		{
			temp=arr[j];
			a=temp%it2;
			a/=it1;
			buk[a][k]=temp;
			k++;
		}
		getfrombuk(arr,n,buk);
	}

}
void getfrombuk(int *arr,int n,int buk[][n])
{
	int i,j,k=0;
	for(i=0;i<10;i++)
		for(j=0;j<n;j++)
			if(-1!=buk[i][j])
			{
				arr[k]=buk[i][j];
				k++;
			}
}
int part(int *arr,int beg,int end)
{
	int l,r,loc,temp;
	l=beg;r=end;loc=beg;
	while(l<r)
	{
		while((arr[loc]<arr[r]) && loc!=r)
		r=r-1;
		if(loc==r)
			return loc;
		temp=arr[loc];
		arr[loc]=arr[r];
		arr[r]=temp;
		loc=r;
		while(arr[loc]>arr[l]&&loc!=l)
		l=l+1;
		if(loc==l)
			return loc;
		temp=arr[loc];
		arr[loc]=arr[l];
		arr[l]=temp;
		loc=l;
	}
}
void merge(int *arr,int beg,int end)
{
	printf("-1");
	int mid;
	if(beg<end)
	{
		mid=(beg+end)/2;
		printf("0");
		merge(arr,beg,mid);
		printf("1");
		merge(arr,mid+1,end);
		printf("2");
		mergesort(arr,beg,mid,mid+1,end);
	}
}
void mergesort(int *arr,int lb1,int ub1,int lb2,int ub2)
{
	int c[max];
	int i=lb1,j=lb2,k=0;
	while((i<=ub1)&&(j<=ub2))
	{
		if(arr[i]<arr[j])
		{
			c[k]=arr[i];
			k++;i++;
		}
		else
		{
			c[k]=arr[j];
			k++;j++;
		}
	}
		while(i<=ub1)
		{
			c[k]=arr[i];
			k++;i++;
		}
		while(j<=ub2)
		{
			c[k]=arr[j];
			k++;i++;
		}
		i=lb1;k=0;
		while(i<=ub2)
		{
			arr[i]=c[k];
			i++;k++;
		}
	
}
void selection(int *arr,int n)
{
	int i,j,temp;
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(arr[i]>arr[j])
			{
				temp=arr[i];
				arr[i]=arr[j];
				arr[j]=temp;
			}
		}
	}
}
void bubble(int arr[],int n)
{
	int i,j,temp,swap=0;
	for(i=0;i<=n-2;i++)
	{
		swap=0;
		for(j=0;j<=n-i-2;j++)
		{
			if(arr[j]>arr[j+1])
			{
				temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
				swap=1;
			}
		}
		if(0==swap)
			return;
	}
}
void insertion(int *arr,int n)
{
	int temp,i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<=i;j++)
		{
			if(arr[i]<arr[j])
			{
				temp=arr[i];
				arr[i]=arr[j];
				arr[j]=temp;
			}
		}
	}
}
