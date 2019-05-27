#include<stdio.h>
#include<string.h>

int main(int argc, char *argv[])
{
	int i, j, k, found =1, beg, mid, end;
	char str1[20], str2[20];	
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
	printf("Names entered in the given order- \n");
	for(i=1; i<argc; i++)
	{
		printf("%s\n",argv[i]);
	}
}
