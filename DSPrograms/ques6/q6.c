#include"myheaderr6.h"

int main()
{
	float a, b, c;
	a= squ_ar(SIDE);
	b= tri_ar(HEIGHT,BASE);
	c= cir_ar(RADIUS);
	/*printf("Area of Triange ");
	printf("Area of Square with sides = %f\n",a);
	printf("Area of Circle with radius = %f\n",c);*/
	printf("Area of Triange with base and height = %f\n",b);
	printf("Area of Square with sides = %f\n",a);
	printf("Area of Circle with radius = %f\n",c);
}

