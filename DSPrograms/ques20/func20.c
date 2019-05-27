#include"myheader20.h"

void create(char queue[])
{
	char name[20];
	if(MAX-1 == rear)
	{
		printf("Queue Overflow\n");
	}
	else
	{
		if(-1 == front)
		{
			front = 0;
		}
		printf("Insert the names : \n");
		while('\n' != getchar())
		{
			;
		}
		memset(name,0,20*sizeof(char));
		fgets(name,19,stdin);
		rear = rear+1;
		strcpy(queue[rear],name);
	}
}

void display(char queue[])
{
	int i;
	if(-1 == front)
	{
		printf("Queue is empty\n");
		return;
	}
	printf("\nNames in a queue are -\n");
	for(i= front; i<= rear; i++)
	{
		printf("%s\t",queue[i]);
	}
	printf("\n");
}


void enqueue(char queue[])
{
	char name[30];
	//int len;	
	printf("\nEnter the name to insert- \n");
	while('\n' != getchar())
	{
		;
	}
	fgets(name,29,stdin);
	/*memset(name,0,30*sizeof(char));
	
	fgets(name,29,stdin);
	len = strlen(name);
	if('\n' == name[len-1])
	{
		name[len-1]='\0';
	}*/			
	/*if(((MAX-1 == rear) && (0 == front)) || (front = rear+1))
	{
		printf("Queue Overflow\n");
		return;
	}
	if(-1 == front)
	{
		front = 0;
		rear = 0;
	}
	else
	{
		if(MAX-1 == rear)
		{
			rear = 0;
		}
		else
		{
			rear = rear+1;
		}
	}
	int enqueue(char q[], int *front, int *rear, char *name)
{*/
	if((*rear+1)%MAX == *front)
	{
		printf("Queue Overflow\n"); return SUCCESS;
	}
	if(EMPTY == *front)
	{
		*front = 0; *rear = 0;
	}
	else
	{
		*rear = (*rear+1)%MAX;
	}
	q[*rear] = *name;
	return SUCCESS;
}
	strcpy(queue[rear],name);
}

void dequeue(char queue[])
{
	char name[30];
	if(-1 == front);
	{
		printf("Queue Underflow\n");
		return;
	}	
	strcpy(name,queue[front]);
	if(front == rear)
	{
		front = -1;
		rear = -1;
	}
	else
	{
		front = (front + 1) % MAX;
	}
	printf("Name Deleted : %s\n",name);
}
