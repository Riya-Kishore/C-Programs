#include<stdio.h>
#define PI 3.14
#define SIDE 5.5
#define HEIGHT 10.2
#define BASE 5.5
#define RADIUS 3.5

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
