#include"myheader18.h"

int main()
{
	FILE *fptr1, *fptr2;
	char filename[30], str[100];
	int len, i, j=0, flag =0, len1, in; //in--to read the words of file 
	snode *top = NULL;	
	printf("Enter file name : ");
	memset(filename,0,30*sizeof(char));
	fgets(filename,29,stdin);
	len = strlen(filename);
	if('\n' == filename[len-1])
	{
		filename[len-1] = '\0';
	}
	if(NULL == (fptr1 = fopen(filename,"r")))
	{
		printf("Error in opening file\n");
		exit(1);
	}
	if(NULL == (fptr2 = fopen("palindrome","w")))
	{
		printf("Error in opening file\n");
		exit(1);
	}
	printf("Content of file : %s\n",filename);
	while(EOF != (in = fgetc(fptr1)))
	{
		printf("%c",in);
	}
	fseek(fptr1,01,0);
	while(fscanf(fptr1,"%s",str) > 0)
	{
		flag = 0;
		len1 = strlen(str);
		for(i=0; i<len1; i++)
		{
			push(&top, str[i]);
		}
		for(i=0; i<len1; i++)
		{
			if(str[i] != pop(&top))
			{
				flag = 1;
				break;
			}
		}
		if(0 == flag)
		{
			fprintf(fptr2,"%s\n",str);
			j++;
		}
		free_stack(&top);
	}
	
	fclose(fptr1);
	fclose(fptr2);

	if(NULL == (fptr2 = fopen("palindrome","r")))
	{
		printf("Error in opening file\n");
		exit(1);
	}
	if(0 == j)
	{
		printf("There are no palindrome words in the file \n");
		exit(1);
	}
	printf("There are %d palindrome words in the file\n",j);
	fseek(fptr2,00,0);
	printf("Content of file(%s) which stores the palindrome words is: \n","palindrome");
	while(EOF != (in = fgetc(fptr2)))
	{
		printf("%c",in);
	}
	fclose(fptr2);
	return 0;
}
		
