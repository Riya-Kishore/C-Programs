#include"myheader20.h"

int front = -1;
int rear = -1;

int enqueue(char q[], char name[30])
{
	//char name[30];
	//int len;	
	/*printf("\nEnter the name to insert- \n");
	while('\n' != getchar())
	{
		;
	}
	memset(name,0,30*sizeof(char));
	fgets(name,29,stdin);*/
	if((rear+1)%MAX == front)
	{
		printf("Queue Overflow\n"); return SUCCESS;
	}
	if(EMPTY == front)
	{
		front = 0; rear = 0;
	}
	else
	{
		rear = (rear+1)%MAX;
	}
	strcpy(q[rear],name);
	return SUCCESS;
}

int dequeue(char q[])
{
	char item;
	if(EMPTY == front)
	{
		printf("Queue Underflow\n");
		return FAILURE;
	}
	strcpy(item,q[front]);
	if(front == rear)
	{
		front = EMPTY;
		rear = EMPTY;
	}
	else
	{
		front = (front + 1)%MAX;
	}
	return SUCCESS;
}

/*void display(char q[])
{
	int *p; // pointer p is to traversing the whole list
	if(EMPTY == front)
	{
		printf("Linked list is empty\n");
	}
	else
	{
		*p = front;
		while(*p != rear)
		{
			printf("%s -> ", q[*p]); // print all nodes data with this sign (->) except last node
			*p = *p+1;
		}
		printf("%s\n", q[*p]); // print last node without this (->) sign
	}
}*/

void display(char q[])
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
		printf("%s\t",q[i]);
	}
	printf("\n");
}

