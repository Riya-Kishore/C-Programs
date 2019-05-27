#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 10

void BubbleSort(int arr[], int MAX);
void InsertionSort(int arr[], int MAX);
void SelectionSort(int arr[], int MAX);
void ShellSort(int arr[], int MAX);
void QuickSort(int arr[], int beg, int end);
int Partition(int arr[], int beg, int end);
void MergeSort(int arr[], int beg, int end);
void Merge(int arr[], int beg, int mid, int end);
void display(int arr[], int MAX);
