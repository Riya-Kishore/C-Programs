#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct employee
{
	int id;
	char *name;
	char *dept;
	int ph_num;
}e1;

int record_name(e1 **arr, int n);
//int display_record(int n);
int update_record(e1 **arr, int n);
