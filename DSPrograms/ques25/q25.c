#include"myheader25.h"
//struct node *root=NULL;
int main()
{
	int choice,num, n;
	struct node *par,*loc,*new, *root=NULL;
again:
	printf("\n");
	printf("1.Insert\n");
	printf("2.Delete\n");
	printf("3.Inorder Traversal\n");
	printf("4.Preorder Traversal\n");
	printf("5.Postorder Traversal\n");
	printf("6.Display\n");
	printf("7.Search\n");
	printf("8.Quit\n");
	printf("Enter your choice : ");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1 :
			printf("Enter the number to be inserted : ");
			scanf("%d",&num);
			insert(num);
			break;
		
		case 2:
			printf("Enter the number to be deleted : ");
			scanf("%d",&num);
			del(num);
			break;
		
		case 3:
			inorder(root);
			break;
		
		case 4:
			preorder(root);
			break;
		
		case 5:
			postorder(root);
			break;
	
		case 6:
			display(root,1);
			break;
		
		case 7: 
			printf("Item to be searched is: ");
			scanf("%d",&num);
			Search(num,&par,&loc,&root);
			if(loc==NULL)
			{
				printf("item not found");
			}
			else
			{
				printf("item found");
			}
			break;

		case 8: 
			exit(0);
			break;
		
		default:
			printf("Wrong choice\n");
	}
	printf("\nWant to opt more options?\nIf yes press 1 otherwise press 0\n");
	scanf("%d",&n);
	if(1 == n)
	{
		goto again;
	}
}

