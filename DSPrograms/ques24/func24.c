#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(int args , char *argv[])
{
	if(args!=3)
	{
	printf("WRONG NUMBER OF COMMAND LINE ARGUMENTS!!!\n");
	exit(1);
	}
	FILE *f1 ,*f2;
	if((f1=fopen(argv[1],"r")) == NULL)
	{
		printf("ERROR IN OPENING THE FILE1!!!\n");
		exit(1);
	}
	if((f2=fopen(argv[2],"w+")) == NULL)
	{
		printf("ERROR IN OPENING THE FILE2!!!\n");
		exit(1);
	}
	int input;
	printf("CONTENTS IN THE FILE '%s':\n",argv[1]);
	while((input=fgetc(f1)) != EOF)
	{	
		printf("%c",input);
	}
	fseek(f1,0L,0); //position indicator points to the beginning of the file1
	char string[200], stringarr[200][200];
	int x = 0, i , j , k;
	while(fscanf(f1,"%s",string)>0)
	{
		strcpy(stringarr[x],string);
		x++;
	}
	for(i=0; i<x; i++)
	{
		for(j=i+1; j<x; j++ )
		{
			if(strcmp(stringarr[i],stringarr[j]) == 0)
			{
				for(k=j; k<x; k++)
				{
					strcpy(stringarr[k],stringarr[k+1]);
				}
				x--;
				j--;
			}
		}
	}
	printf("DUPLICATES ARE REMOVED!!!\n");
	for(i=0;i<x;i++)
	{
		fprintf(f2,"%s\n",stringarr[i]);
	}
	fseek(f2,0L,0);
	printf("EDITED CONTENTS IN THE FILE '%s':\n",argv[2]);
	while((input=fgetc(f2)) != EOF)
	{
		printf("%c",input);
	}
	fclose(f1);
	fclose(f2);
	return 0;
}

