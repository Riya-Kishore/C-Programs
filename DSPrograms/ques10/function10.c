#include"myheader10.h"

int row_sum=0, dia_sum=0, column_sum=0;
int i, j, flag=0;

int get_input(int arr[][COLUMNS], int row_max)
{
	printf("Enter Elements of a matrix: \n");
	for(i=0; i<row_max; i++)
	{
		for(j=0; j<COLUMNS; j++)
		{
			scanf("%d",&arr[i][j]);
		}
	}
}

int display(int arr[][COLUMNS], int row_max)
{	
	printf("ENTERED MATRIX- \n");	
	for(i=0; i<row_max; i++)
	{
		for(j=0; j<COLUMNS; j++)
		{
			printf("%d\t",arr[i][j]);
		}
		printf("\n");
	}
}

int check_magic_square(int arr[][COLUMNS], int row_max)
{
	for(i=0; i<row_max; i++)
	{
		for(j=0; j<COLUMNS; j++)
		{
			if(i==j)
			{
				dia_sum = dia_sum + arr[i][j];
			}
		}
		
	}
	
	for(i=0; i<row_max; i++)
	{
		for(j=0; j<COLUMNS; j++)
		{
			row_sum= row_sum + arr[i][j];
			column_sum= column_sum + arr[j][i];
			if(row_sum == dia_sum && column_sum == dia_sum)
			{			
				flag++;
			}
		}
	}
	if(1==flag)
	{
		printf("\nGIVEN MATRIX IS A MAGIC SQUARE\n\n");
	}
	else
	{
		printf("\nGIVEN MATRIX IS NOT MAGIC SQUARE\n\n");
	}
}	


