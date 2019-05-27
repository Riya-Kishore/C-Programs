#include"myheader8.h"


void ptr_size()
{
	
}

void operate()
{
	printf("Value of iptr = Address of a = %p || Value of a = %d\n",iptr,*iptr);
	printf("Value of fptr = Address of b = %p || Value of b = %f\n",fptr,*fptr);
	printf("Value of cptr = Address of c = %p || Value of c = %c\n\n",cptr,*cptr);
	printf("---Pointers Arithmetic-----\n");
	printf("-----INCREMENT OPERATION-----\n");
	iptr++;
	fptr++;
	cptr++;
	printf("Value of iptr++ = %p\n",iptr);
	printf("Value of fptr++ = %p\n",fptr);
	printf("Value of cptr++ = %p\n\n",cptr);
	printf("------DECREMENT OPERATION-----\n");
	iptr--;
	fptr--;
	cptr--;
	printf("Value of iptr-- = Address of a = %p\n",iptr);
	printf("Value of fptr-- = Address of b = %p\n",fptr);
	printf("Value of cptr-- = Address of c = %p\n\n",cptr);
	
	printf("Value of iptrr = Address of x = %p || Value of x = %d\n",iptrr,*iptrr);
	printf("Value of fptrr = Address of y = %p || Value of y = %f\n",fptrr,*fptrr);
	printf("Value of cptrr = Address of z = %p || Value of z = %c\n\n",cptrr,*cptrr);
	
	printf("---Subtraction of one pointer from another---\n");
	n1=iptr-iptrr;
	n2=fptr-fptrr;
	n3=cptr-cptrr;

	printf("Value of n1 = %d\n",n1);
	printf("Value of n2 = %d\n",n2);
	printf("Value of n3 = %d\n\n",n3);
}

void v_ptr()
{
	printf("----Void Pointer----\n");	
	printf("Address of vp = Value of vptr= %p\n",(int *)vptr);
	printf("Value of vp = %d\n\n",*(int *)vptr);
}

void d_ptr()
{
	printf("-----Double Pointer-----\n");
	printf("Value of dptr = Address of ptr = %p\n",dptr);
	printf("Value of **dptr = Value of n1 = %d\n\n",**dptr);
}


int swap(int p, int q)
{
	int temp;
	temp = p;
	p = q;
	q = temp;
}

int swapp(float *c, float *d)
{
	float temp;
	temp = *c;
	*c = *d;
	*d = temp;
}
