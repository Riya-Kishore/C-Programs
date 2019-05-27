#include<stdio.h>
#include<stdlib.h>
#define PI 3.14
#define SAREA(FNAME,DTYPE)	\
	DTYPE FNAME(DTYPE SIDE)	\
	{			\
		return SIDE * SIDE;	\
	}

#define TAREA(FNAME,DTYPE)	\
	DTYPE FNAME(DTYPE X, DTYPE Y)	\
	{				\
		return (X*Y)/2;		\
	}

#define CAREA(FNAME,DTYPE)	\
	DTYPE FNAME(DTYPE R)	\
	{			\
		return PI*R*R;	\
	}

SAREA(squ_ar,float)
TAREA(tri_ar,float)
CAREA(cir_ar,float)
