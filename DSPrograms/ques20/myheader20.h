#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 10
#define SUCCESS 1
#define FAILURE 0
#define EMPTY -1

/*int front = -1;
int rear = -1;*/

//int create_queue(char q[], int *front, int *rear, int total);
/*void display(char queue[]);
void enqueue(char queue[]);
void dequeue(char queue[]);
void create(char queue[]);*/

void display(char q[]);
int dequeue(char q[]);
int enqueue(char q[], char name[30]);
