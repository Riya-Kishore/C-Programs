#include<stdio.h>
#include<string.h>

int main(int argc, char *argv[])
{
	int i, j, k, found =1, beg, mid, end;
	char str1[20], str2[20];
	printf("TOTAL NUMBER OF NAMES ENTERED- %d\n",argc-1);

	for(i=0; i<argc-1; i++)
	{
		for(j=i+1; j<argc-i-1; j++)
		{
			if(strcmp(argv[j],argv[j+1])>0)
			{
				strcpy(str1,argv[j]);
				strcpy(argv[j],argv[j+1]);
				strcpy(argv[j+1],str1);
			}
		}
	}
	/*for(i=1; i<argc; i++)
	{
		for(j=1; j<argc; j++)
		{
			if(strcmp(argv[j-1],argv[j])>0)
			{
				strcpy(str1,argv[j-1]);
				strcpy(argv[j-1],argv[j]);
				strcpy(argv[j],str1);
			}
		}
	}*/
	printf("\n\n");
	printf("Names entered in the given order- \n");
	for(i=1; i<argc; i++)
	{
		printf("%s\n",argv[i]);
	}
	printf("\n\n");

	printf("Enter the name to be searched: ");
	scanf("%s",&str2[i]);
	beg=0, end= argc-1;
	for(k=1; k<argc-1; k++)
	{
		mid = (beg+end)/2;
		if(0 == strcmp(&str2[i],argv[mid]))
		{
			found = 0;
			break;
		}
		else if(strcmp(&str2[i],argv[mid]) > 0)
		{
			end = mid+1;
			beg = 0;
		}
		else
		{
			beg = mid+1;
			end = argc;
		}
	}
	if(0 == found)
	{
		printf("%s is found at position %d\n",&str2[i],mid+1);
	}
	else
	{
		printf("%s is not found\n",&str2[i]);	
	}
}
