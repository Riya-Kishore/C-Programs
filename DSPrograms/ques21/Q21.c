#include<stdio.h>
#include<stdlib.h> //this header file is used here for memset
#include<string.h>
#define SUCCESS 1
#define FAILURE 0
typedef struct pqnode //defining priority queue having two members
{
	char data;		//one is data (ex - A, B, C, ... so on) and
	int s_priority;	//another one is its priority
	struct pqnode *next;
}pqnode; 		/* priority is defined in decreasing order from 1>2>3>4>5... so on*/
int enqueue(pqnode **front, pqnode **rear, char item, int priority); //this is the function for inserting an element in the queue.
void display(pqnode **front, pqnode **rear);
int main(void)
{
	/*defining front and rear as struct pqnode type, status gives the status of enqueue function whether insertion of node is successful or not*/
	pqnode *front = NULL; pqnode *rear = NULL; char item; int priority; int status;
	char ch; //ch is used as a condition for the while loop given below
	do {
	printf("Enter the element (or node) name (e.g. - A, B, C, etc) - ");
	getchar();
	scanf("%c", &item);
	printf("Set its priority (e.g. 1(highest priority, 2, 3 etc.) - ");
	scanf("%d", &priority);
	printf("%c", item);
	status = enqueue(&front, &rear, item, priority); //calling of enqueue function
	display(&front, &rear);
	printf("Do you want enter further(y/n) - ");
	getchar();
	scanf("%c", &ch);
	}while('y' == ch);
	return 0;
}

int enqueue(pqnode **front, pqnode **rear, char item, int priority)
{
	pqnode *new = NULL; pqnode *p = NULL; pqnode *q = NULL;
	new = (pqnode *)malloc(sizeof(pqnode));
	if(NULL == new) { printf("Memory allocation failure"); return FAILURE; }
	new->data = item; new->s_priority = priority;
	if(NULL == *front)
	{
		*front = new; *rear = new;
		new->next = NULL;
	}
	else
	{
		if((*front)->s_priority  >  new->s_priority)
		{
			new->next = *front;
			*front = new;
		}
		else if((*rear)->s_priority  <=  new->s_priority)
		{
			(*rear)->next = new;
			*rear = new;
			new->next = NULL;
		}
		else
		{
			p = *front;
			while(p->s_priority < new->s_priority)
			{
				q = p;
				p = p->next;
			}
			q->next = new;
			new->next = p;
		}
	}
	return SUCCESS;
}

void display(pqnode **front, pqnode **rear)
{
	pqnode *p = NULL; // pointer p is to traversing the whole list
	if(NULL == *front)
	{
		printf("Linked list is empty\n");
	}
	else
	{
		p = *front;
		while(p->next != NULL)
		{
			//printf("1");
			printf("%c -> ", p->data); // print all nodes data with this sign (->) except last node
			p = p->next;
		}
		//printf("2");
		printf("%c\n", p->data); // print last node without this (->) sign
	}
}
