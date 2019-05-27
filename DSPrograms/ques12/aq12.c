#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(int argc, char *argv[])
{
	FILE *file1, *file2, *file3;
	char  ch, ch1;
	if(NULL==(file1=fopen(argv[1],"r")))
	{
		printf("Error in opening file\n");
		exit(1);
	}
		
	if(NULL==(file2=fopen(argv[2],"r")))
	{
		printf("Error in opening file\n");
		exit(1);
	}
	if(NULL==(file3=fopen(argv[3],"w")))
	{
		printf("Error in opening file\n");
		exit(1);
	}

	while((ch = fgetc(file1)) != EOF && (ch1 = fgetc(file2)) != EOF)
	{
		fputc(ch,file3);
		fputc(ch1,file3);
	}

	printf("Content of both the files has been copied successfully to file 3\n");
	fclose(file1);
	fclose(file2);
	fclose(file3);

	if(NULL==(file3=fopen(argv[3],"r")))
	{
		printf("Error in opening file\n");
		exit(1);
	}
	
	printf("Content of third file is- \n");
	while((ch = fgetc(file3)) != EOF)
	{
		printf("%c",ch);
	}

	fclose(file3);
	return 0;
}
