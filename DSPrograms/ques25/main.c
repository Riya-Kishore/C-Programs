#include<stdio.h>
#include<stdlib.h>
#include"myheader.h"
typedef struct tnode{
	int data;
	struct tnode *left;
	struct tnode *right;
}tnode;
typedef struct stack{
	int data;
	struct stack *next;
}stack;
stack *top=NULL;
typedef struct queue{
	tnode *ptr;
	struct queue *next;
}queue;
queue *front=NULL;
queue *rear=NULL;
queue *pt=NULL;
int find(tnode *,tnode **,tnode **,int);
int insert(tnode **,int);
void print2D(tnode *);
void print2DUtil(tnode *, int );
void printinfix(tnode *);
void printprefix(tnode *);
void printpostfix(tnode *);
void topview(tnode*,int,int *,int);
void leftview(tnode *,int,int *);
void rightview(tnode *,int,int *);
void delete01child(tnode **,tnode *,tnode *);
void delete2child(tnode **,tnode *,tnode *);

queue *peep(queue **pt)
{
	return (*pt)->next;
}
void enqueue(tnode *root,queue **front,queue **rear)
{
	queue *new;
	new=(queue*)malloc(sizeof(queue));
	if(NULL==new)
		exit(0);
	new->ptr=root;
	new->next=NULL;
	if(NULL==*front)
	{
		*front=new;
		*rear=new;
	}
	else
	{
		(*rear)->next=new;
		*rear=new;
	}
}
void disp(queue *front)
{
	while(NULL!=front)
	{
		printf( "%d ", ( (front->ptr)->data) );
		front=front->next;
	}
}
void push(stack **top,int item)
{
	stack *new;
	new=(stack *)malloc(sizeof(stack));
	if(NULL==new)
		exit(0);
	new->data=item;
	new->next=*top;
	*top=new;
}
void dispstack(stack *top)
{
	while(top)
	{
		printf("%d ",top->data);
		top=top->next;
	}
}
void delete(tnode **root,int key)
{
	tnode *loc=NULL,*par=NULL;
	int r=find(*root,&par,&loc,key);
	if(NULL==loc)
	{
		printf("not found");
		return;
	}
	if(NULL!=loc->left && NULL!=loc->right)
		delete2child(root,loc,par);
	else
		delete01child(root,loc,par);
	free(loc);
	loc=NULL;
}
void delete01child(tnode **root,tnode *loc,tnode *par)
{
	tnode *child=NULL;
	if(NULL!=loc->left)
		child=loc->left;
	if(NULL!=loc->right)
		child=loc->right;
	if(NULL==par)
		*root=child;
	else
	{
		if(loc->data<par->data)
			par->left=child;
		else
			par->right=child;
	}
}
void delete2child(tnode **root,tnode *loc,tnode *par)
{
	tnode *succ=loc->right,*parsucc=loc;
	while(NULL!=succ->left)
	{
		parsucc=succ;
		succ=succ->left;
	}
	delete01child(root,succ,parsucc);
	if(NULL==par)
		(*root)=succ;
	else if(loc==par->left)
		par->left=succ;
	else
		par->right=succ;
	succ->left=loc->left;
	succ->right=loc->right;
}
void levelview(tnode *root,queue *pt)
{
	if(NULL==root)
		return;
	if(NULL!=root->left)
		enqueue(root->left,&front,&rear);
	if(NULL!=root->right)
		enqueue(root->right,&front,&rear);
	pt=peep(&pt);
	if(NULL!=pt)
		levelview(pt->ptr,pt);    	
}
void leftview(tnode *root,int lvl,int *maxlvl)
{
	if(NULL==root)
		return;
	if(*maxlvl<lvl)
	{
		printf("%d ",root->data);
		*maxlvl=lvl;
	}
	leftview(root->left,lvl+1,maxlvl);
	leftview(root->right,lvl+1,maxlvl);
}
void rightview(tnode *root,int lvl,int *maxlvl)
{
	if(NULL==root)
		return;
	if(*maxlvl<lvl)
	{
		printf("%d ",root->data);
		*maxlvl=lvl;

	}
	rightview(root->right,lvl+1,maxlvl);
	rightview(root->left,lvl+1,maxlvl);
}
void topview(tnode *root,int lvl,int *v,int n)
{
	if(NULL==root)
		return;
	int r,lrl,f=0;
	for(int i=0;i<n;i++)
	{
		if(lvl==v[i])
		{
			f=1;
			break;
		}
	}
	if(1!=f)
	{
		push(&top,root->data);
		v[n++]=lvl;
	}
	if(NULL!=root->left && NULL!=root->right)
	{
		topview(root->left,lvl-1,v,n);
		topview(root->right,lvl+1,v,n);
	}
	else if(NULL!=root->left)
		topview(root->left,lvl-1,v,n);
	else if(NULL!=root->right)
		topview(root->right,lvl+1,v,n);
}
int find(tnode *root,tnode **par,tnode **loc,int item)
{
	tnode *ptr;
	if(NULL==root)
	{
		*loc=NULL;
		*par=NULL;
		return 1;
	}
	if(item==root->data)
	{
		*par=NULL;
		*loc=root;
		return 1;
	}
	*par=root;
	if(item<root->data)
	{
		ptr=root->left;
	}
	else
		ptr=root->right;
	ptr=root;
	while(NULL!=ptr)
	{
		if(item==ptr->data)
		{
			*loc=ptr;
			return 1;
		}
		*par=ptr;
		if(item<ptr->data)
		{
			ptr=ptr->left;
		}
		else
			ptr=ptr->right;
	}

	*loc=NULL;
	return 1;
}
int insert(tnode **root,int item)
{
	tnode *loc=NULL;
	tnode *par=NULL;
	int r;
	r=find(*root,&par,&loc,item);
	if(NULL!=loc)
	{
		printf("Duplicate entry!!");
		return 1;
	}
	tnode *new;
	new=(tnode*)malloc(sizeof(tnode));
	if(NULL==new)
		return 0;
	new->data=item;
	new->left=NULL;
	new->right=NULL;
	if(NULL==par)
		*root=new;
	else
	{
		if(item<par->data)
		{
			par->left=new;
		}
		else
			par->right=new;
	}
	return 1;
}
void print2DUtil(tnode *root, int space)  
{  
	if (root == NULL)  
		return;  
	space += 5;  

	print2DUtil(root->right, space);  

	printf("\n");  
	for (int i = 5; i < space; i++)  
		printf(" ");  
	printf("%d",root->data);  

	print2DUtil(root->left, space);  
}
void printinfix(tnode *root)
{
	if(NULL==root)
		return;
	printinfix(root->left);
	printf("%d ",root->data);
	printinfix(root->right);
}
void printprefix(tnode *root)
{
	if(NULL==root)
		return;
	printf("%d ",root->data);
	printprefix(root->left);
	printprefix(root->right);
}
void printpostfix(tnode *root)
{
	if(NULL==root)
		return;
	printpostfix(root->left);
	printpostfix(root->right);
	printf("%d ",root->data);
}
int main()
{
	tnode *root=NULL;
	tnode *loc=NULL;
	tnode *par=NULL;
	int item,r,ch,v[20],maxlvl=0;
	do
	{
		printf("\nEnter the data: ");
		item=get_int();
		r=insert(&root,item);
		if(0==r)
		{
			printf("fail");exit(0);

		}
		printf("Want to enter more! ");
		scanf("%d",&ch);
	}while(1==ch);
	do
	{
		if(NULL!=root)
		{
			print2DUtil(root,5);
			printf("\n");
			printf("\n inoder: ");
			printinfix(root);
			printf("\n preoder: ");
			printprefix(root);
			printf("\n postoder: ");
			printpostfix(root);
			maxlvl=0;
			printf("\nTop view :");
			topview(root,0,v,0);
			dispstack(top);
			printf("\nLeft view :");
			leftview(root,1,&maxlvl);
			maxlvl=0;
			printf("\nRight view :");
			rightview(root,1,&maxlvl);
			printf("\nLevelView: ");
			front=rear=NULL;
			enqueue(root,&front,&rear);
			levelview(root,front);
			disp(front);
			printf("\nWant to delete: ");
			scanf("%d",&ch);
			if(1==ch)
			{
				printf("Enter the item to delete: ");
				scanf("%d",&item);
				delete(&root,item);
			}
		}
		else
		{
			printf("Empty Tree!!!");
			break;
		}
	}while(1==ch);
}
