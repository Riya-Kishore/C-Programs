#include"myheader.h"
int main()
{
        int item,i,ch,n,c,len;
	char arr[30][30];
	char name[30],chq;
        printf("\nEnter the no of names for th array: ");
        scanf("%d",&n);
        printf("\nEnter the names: ");
	getchar();
        for(i=0;i<n;i++)
        {
		memset(name,0,30);
		fgets(name,29,stdin);
		len=strlen(name);
		name[len-1]='\0';
		memset(arr[i],0,30);
		strncpy(arr[i],name,len-1);
	}
        for(i=0;i<n;i++)
                printf(" %s |",arr[i]);
        printf("\nArray after Bubble Sorting: ");
        bubble(arr,n);
        display(arr,n);
	getchar();
	printf("Enter the name to search: ");
	fgets(name,29,stdin);
	len=strlen(name);
        name[len-1]='\0';
	bnrysearch(name,arr,n);
	printf("\n");
}
