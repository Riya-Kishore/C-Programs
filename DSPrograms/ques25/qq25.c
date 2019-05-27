#include<stdio.h>
#include<stdlib.h>

struct node
{
	int info;
	struct node *lchild;
	struct node *rchild;
};
struct node *root=NULL;

void Search(int item, struct node **par, struct node **loc);
void insert(int item);
void case_a(struct node *par, struct node *loc);
void case_b(struct node *par, struct node *loc);
void case_c(struct node *par, struct node *loc);
int del(int item);
int preorder(struct node *ptr);
void inorder(struct node *ptr);
void postorder(struct node *ptr);

int main()
{
	int choice,num, n;
	struct node *par,*loc,*new;
	printf("\n");
	printf("SELECT ANY ONE OPTION: \n");
	printf("1.Insert\n");
	printf("2.Delete\n");
	printf("3.Inorder Traversal\n");
	printf("4.Preorder Traversal\n");
	printf("5.Postorder Traversal\n");
	printf("6.Search\n");
	printf("7.Quit\n");
again:
	printf("\nEnter your choice : ");
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
			printf("\nINORDER TRAVERSAL:- \n");
			inorder(root);
			break;
		
		case 4:
			printf("\nPREORDER TRAVERSAL:- \n");
			preorder(root);
			break;
		
		case 5:
			printf("\nPOSTORDER TRAVERSAL:- \n");
			postorder(root);
			break;

		case 6: 
			printf("Item to be searched is: ");
			scanf("%d",&num);
			Search(num,&par,&loc);
			if(loc==NULL)
			{
				printf("item not found");
			}
			else
			{
				printf("item found");
			}
			break;

		case 7: 
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


void Search(int item, struct node **par, struct node **loc)
{
	struct node *ptr,*ptrsave;//save parent of ptr
	*loc=NULL;
	if(NULL==root) /*tree empty*/
	{
		*loc=NULL;
		*par=NULL;
		return ;
	}
	if(item==(root)->info) /*item is at root*/
	{
		*loc=root;
		*par=NULL;
		return ;
	}
	/*Initialize ptr and ptrsave*/
	if(item<(root->info))
	{
		ptr=root->lchild;
	}
	else
	{
		ptr=root->rchild;
	}
	ptrsave=root;
	while(NULL!=ptr)
	{
		if(item==(ptr->info))
		{
			*loc=ptr;
			*par=ptrsave;
			return ;
		}
		ptrsave=ptr;
		if(item<ptr->info)
		{
			ptr=ptr->lchild;
		}
		else
		{
			ptr=ptr->rchild;
		}
	}
	*loc=NULL; /*item not found*/
	*par=ptrsave;
}

void insert(int item)
{
	struct node *new, *parent, *location;
	Search(item,&parent,&location);
	if(NULL != location)
	{
		printf("Item already present");
		return;
	}
	new = (struct node *)malloc(sizeof(struct node));
	if(NULL==new)
	{
		printf("memory allocation failure!!");
		return;
	}
	new->info = item;
	new->lchild = NULL;
	new->rchild = NULL;
	if(NULL == parent)
	{
		root=new;
	}
	else 
	{
		if(item<parent->info)
		{
			parent->lchild=new;
		}
		else
		{
			parent->rchild=new;
		}
	}
}
//Deleting a node that has no children...
void case_a(struct node *par, struct node *loc)
{
	if(par==NULL) /*item to be deleted is root node*/
	{
		root=NULL;
	}
	else if(loc==par->lchild)
	{
		par->lchild=NULL;
	}
	else
	{
		par->rchild=NULL;
	}
}
//Deleting a node with one child...
void case_b(struct node *par, struct node *loc)
{
	struct node *child=NULL;
	/*Initialize child*/
	if(NULL!=(loc->lchild)) /*item to be deleted has lchild */
	{
		child=loc->lchild;
	}
	else /*item to be deleted has rchild */
	{
		child=loc->rchild;
	}
	if(NULL==par) /*Item to be deleted is root node*/
	{
		root=child;
	}
	else 
	{
		if(par->lchild==loc) /*item is lchild of its parent*/
		{
			par->lchild=child;
		}
		else/*item is rchild of its parent*/
		{
			par->rchild=child;
		}
	}
}
//Deleting a node with two child...
void case_c(struct node *par, struct node *loc)
{
	struct node *ptr,*suc,*parsuc,*ptrsave;
	/*Find inorder successor and its parent*/
	ptrsave=loc;
	ptr=loc->rchild;
	while(NULL!=ptr->lchild)
	{
		ptrsave=ptr;
		ptr=ptr->lchild;
	}
	suc=ptr;
	parsuc=ptrsave;
	if(suc->lchild==NULL && suc->rchild==NULL)
	{
		case_a(parsuc,suc);
	}
	else
	{
		case_b(parsuc,suc);
	}
	if(NULL==par) /*if item to be deleted is root node */
	{
		root=suc;
	}
	else if(loc==(par->lchild))
	{
		par->lchild=suc;
	}
	else
	{
		par->rchild=suc;
	}
	suc->lchild=loc->lchild;
	suc->rchild=loc->rchild;
}
int del(int item)
{
	struct node *parent,*location;
	if(root==NULL)
	{
		printf("Tree empty");
		return 0;
	}

	Search(item,&parent,&location);
	if(NULL==location)
	{
		printf("Item not present in tree");
		return 0;
	}
	if(NULL==(location->lchild) && NULL==(location->rchild))
	{
		case_a(parent,location);
	}
	if(NULL!=(location->lchild) && NULL==(location->rchild))
	{
		case_b(parent,location);
	}
	if(NULL==(location->lchild) && NULL!=(location->rchild))
	{
		case_b(parent,location);
	}
	if(NULL!=(location->lchild) && NULL!=(location->rchild))
	{
		case_c(parent,location);
	}
	free(location);
}

int preorder(struct node *ptr)
{
	if(root==NULL)
	{
		printf("Tree is empty");
		return 0;
	}
	if(ptr!=NULL)
	{
		printf("%d ",ptr->info);
		preorder(ptr->lchild);
		preorder(ptr->rchild);
	}
}
void inorder(struct node *ptr)
{
	if(root==NULL)
	{
		printf("Tree is empty");
		return;
	}
	if(ptr!=NULL)
	{
		inorder(ptr->lchild);
		printf("%d ",ptr->info);
		inorder(ptr->rchild);
	}
}

void postorder(struct node *ptr)
{
	if(root==NULL)
	{
		printf("Tree is empty");
		return;
	}
	if(ptr!=NULL)
	{
		postorder(ptr->lchild);
		postorder(ptr->rchild);
		printf("%d ",ptr->info);
	}
}

