#include"myheader.h"
void display(char arr[][30],int n)
{
	for(int i=0;i<n;i++)
		printf(" %s",arr[i]);
}
void bubble(char arr[][30],int n)
{
	char temp[30];int i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if(strcmp(arr[j],arr[j+1])>0)
			{
				strcpy(temp,arr[j]);
				strcpy(arr[j],arr[j+1]);
			strcpy(arr[j+1],temp);
			}
		}
	}
}
void bnrysearch(char *name,char arr[][30],int n)
{
	int i,f,l,m;
	f=0;
	l=n-1;
	m=(f+l)/2;
	while (f <= l) 
	{
		if(0>(strcmp(arr[m],name)))
			f = m + 1;    
		else if (0==strcmp(arr[m],name)) 
		{
			printf("%s found at location %d.\n",name, m+1);
			break;
		}
		else
			l = m - 1;

		m = (f + l)/2;
	}
	if (f > l)
		printf("Not found! %s isn't present in the list.\n", name);

}
