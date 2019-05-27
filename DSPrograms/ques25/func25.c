#include"myheader25.h"
struct node *root=NULL;

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

void display(struct node *ptr, int level)
{
	int i;
	if ( ptr!=NULL )
	{
		display(ptr->rchild, level+1);
		printf("\n");
		for (i = 0; i < level; i++)
			printf(" ");
		printf("%d", ptr->info);
		display(ptr->lchild, level+1);
	}
}
