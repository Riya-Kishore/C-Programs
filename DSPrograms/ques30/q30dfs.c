#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	struct node *next;
	int vertex;
}node;
node *G[20];
int visited[20];
int n;
void read_graph();
void insert(int,int);
void DFS(int);

void main()
{
	int i;
	read_graph();
	for(i=0; i<n; i++)
	{
		visited[i] = 0;
	}
	printf("\nDFS TRAVERSAL:- ");
	DFS(0);
	printf("\n");
}

void DFS(int i)
{
	node *p;
	printf("%d->",i);
	p = G[i];
	visited[i] = 1;
	while(NULL != p)
	{
		i = p->vertex;
		if(!visited[i])
		{
			DFS(i);
		}
		p=p->next;
	}
}

void read_graph()
{
	int i, vi, vj, ne;
	printf("Enter number of vertices:- ");
	scanf("%d",&n);
	for(i=0; i<n; i++)
	{
		G[i] = NULL;
		printf("Enter number of edges:- ");
		scanf("%d",&ne);
		for(i=0; i<ne; i++)
		{
			printf("Enter an edge(u,v):- ");
			scanf("%d%d",&vi,&vj);
			insert(vi,vj);
		}
	}
}

void insert(int vi, int vj)
{
	node *p, *q;
	q = (node *)malloc(sizeof(node));
	q->vertex = vj;
	q->next = NULL;
	if(NULL == G[vi])
	{
		G[vi] = q;
	}
	else
	{
		p = G[vi];
		while(NULL != p->next)
		{
			p = p->next;
		}
		p->next = q;
	}
}

