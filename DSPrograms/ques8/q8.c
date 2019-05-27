#include"myheader8.h"

int main()
{
	
	const int i=1;
	const int *pi;
	pi= &i; //pointer to constant
	/* *pi = *pi+5; (not possible)*/
	int j=1;
	int *const pj = &j; //constant pointer	
	int n1, n2, n3, vp=99;
	void *vptr;
	int *ptr=&n1;	
	int **dptr=&ptr;
	vptr=&vp;
	char c='a', *cptr=&c;
	char z='b', *cptrr=&z;
	int a=10, *iptr=&a;
	int x=15, *iptrr=&x;
	float b=10.55, *fptr=&b;
	float y=8.55, *fptrr=&y;
	int choice, choice1;

	printf("----------DIFFERENT OPTIONS-------\n");
	printf("1.---Types of Pointers and their sizes\n");
	printf("2.---Operations on Pointers\n");
	printf("3.---Void Pointer\n");
	printf("4.---Double Pointer\n");
	printf("5.---Call by Value and Call by Reference\n");
	printf("6.---Exit\n");	
	do
	{
		printf("Enter your choice- ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				printf("Pointer To Constant\n");
				printf("Address of i = Value of pi = %p || Value of i = %d\n",pi,*pi);
				printf("Constant Pointer\n");				
	printf("Address of j = Value of pj = %p || Value of j = %d\n\n",pj,*pj);

	printf("--Different Pointers and their sizes----\n\n");
	printf("---Integer Pointer----\nSize of Integer Pointer = %d\n",sizeof(iptr));
	printf("---Float Pointer----\nSize of Float Pointer = %d\n",sizeof(fptr));
	printf("---Character Pointer----\nSize of Char Pointer = %d\n",sizeof(cptr));
	printf("---Double Pointer----\nSize of Double Pointer = %d\n",sizeof(dptr));
	printf("---Void Pointer----\nSize of Void Pointer = %d\n\n",sizeof(vptr));
				break;

			case 2:
				operate;
				break;

			case 3:
				v_ptr();
				break;

			case 4:
				d_ptr();
				break;
			
			case 5:
				printf("----Call by Value----\n");
				printf("Before calling function swap\n");
				printf("a= %d || x= %d\n",a,x);
				swap(a,x);
				printf("After calling function swap\n");
				printf("a= %d || x= %d\n\n",a,x);
			
				printf("---Call by Reference---\n");
				printf("Before calling function swapp\n");
				printf("b= %f || y=%f\n",b,y);
				swapp(&b,&y);
				printf("After Calling function swapp\n");
				printf("b= %f || y= %f\n\n",b,y);
				break;

			case 6:
				exit(1);
				break;
		
			default :
				printf("Wrong Choice\n");
		}
		printf("\nDo you want to enter more options?\nIf yes PRESS 1 otherwise PRESS 0\n");
		scanf("%d",&choice1);
	}while(1 == choice1);
}

