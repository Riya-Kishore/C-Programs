#include"myheader21.h"

int main()
{
	pqnode *front = NULL; 
	pqnode *rear = NULL; 
	char item; 
	int priority; 
	char ch; 
	do 
	{
		int i = 1;
		printf("\nEnter the element(char type) - ");
		scanf("%c", &item);
		printf("Set its priority(int type) - ");
		scanf("%d", &priority);
		enqueue(&front, &rear, item, priority); 
		printf("\nQueue is: ");
		display(&front, &rear,i);
		printf("\nDo you want enter further(y/n) - ");
		getchar();
		scanf("%c", &ch);
		while('\n' != getchar())
		{
			;
		}
	}while('y' == ch);
	return 0;
}
